/***
*
* File: wp_areas.inc
* Auth: Damian Wojdat
* Date: 15.09.2011
* Desc: Internal script functions.
*
*************************************************************************************************************/

#if defined _WP_UTILITY
    #endinput
#endif
#define _WP_UTILITY

#include <wp\utils\wp_utils_veh>
#include <wp\utils\wp_utils_log>
#include <wp\utils\wp_utils_chat>
#include <wp\utils\wp_utils_player>
#include <wp\utils\wp_utils_gates>
#include <wp\utils\wp_utils_phone>
#include <wp\utils\wp_utils_shop_view>
#include <wp\utils\wp_utils_radio>
#include <wp\utils\wp_utils_pickup_event>
#include <wp\utils\wp_utils_anticheat>
#include <wp\utils\wp_utils_race>
#include <wp\utils\wp_utils_gangzones>
#include <wp\utils\wp_utils_factions>
#include <wp\utils\wp_utils_biz>
#include <wp\utils\wp_utils_horsebetting>
#include <wp\utils\wp_utils_sn>

stock Float:GetXYInFrontOfPlayer(playerid, &Float:x, &Float:y, Float:distance)
{
    new Float:a;
    GetPlayerPos(playerid, x, y, a);
    if (IsPlayerInAnyVehicle(playerid))
        GetVehicleZAngle(GetPlayerVehicleID(playerid), a);
    else
        GetPlayerFacingAngle(playerid, a);
    x += (distance * floatsin(-a, degrees));
    y += (distance * floatcos(-a, degrees));
    return a;
}

Float:DistanceCameraTargetToLocation(Float:CamX, Float:CamY, Float:CamZ,  Float:ObjX, Float:ObjY, Float:ObjZ,  Float:FrX, Float:FrY, Float:FrZ)
{
    new Float:TGTDistance;
 
    // get distance from camera to target
    TGTDistance = floatsqroot((CamX - ObjX) * (CamX - ObjX) + (CamY - ObjY) * (CamY - ObjY) + (CamZ - ObjZ) * (CamZ - ObjZ));
 
    new Float:tmpX, Float:tmpY, Float:tmpZ;
 
    tmpX = FrX * TGTDistance + CamX;
    tmpY = FrY * TGTDistance + CamY;
    tmpZ = FrZ * TGTDistance + CamZ;
 
    return floatsqroot((tmpX - ObjX) * (tmpX - ObjX) + (tmpY - ObjY) * (tmpY - ObjY) + (tmpZ - ObjZ) * (tmpZ - ObjZ));
}

stock IsPlayerAimingAt(playerid, Float:x, Float:y, Float:z, Float:radius)
{
    new Float:cx,Float:cy,Float:cz,Float:fx,Float:fy,Float:fz;
    GetPlayerCameraPos(playerid, cx, cy, cz);
    GetPlayerCameraFrontVector(playerid, fx, fy, fz);
    return (radius >= DistanceCameraTargetToLocation(cx, cy, cz, x, y, z, fx, fy, fz));
}

stock ChangePickupModel(pickupid, model, Float:x, Float:y, Float:z)
{
	DestroyDynamicPickup(pickupid);
	new newpickup = CreateDynamicPickup(model,1,x,y,z);
	return newpickup;
}

stock RandomChance(percent)
{
	new converted = floatround((percent*10)/2, floatround_round);
	new randomTMP = random(1000);
	new randomTMP2 = random(1000);
	if(randomTMP > randomTMP2-converted && randomTMP < randomTMP2+converted)
	{
		return 1;
	}
	return 0;
}

timer GetPlayerSpeed[1000](playerid) //MPH
{
	new Float:x, Float:y, Float:z, string[128];
	new Float:final_speed, final_speed_int;
	new key, up, dwn;
	if(GetPlayerWeapon(playerid) == Speedgun)
	{
		for( new i = 0; i < sizeof(gVehData); i++ )
		{
			GetVehiclePos( i+1, x, y, z);
			new keys, ud, lr;
			GetPlayerKeys(playerid, keys, ud, lr);
			if(IsPlayerAimingAt(playerid, x, y, z, 10.0) && (keys & KEY_HANDBRAKE))
			{
				final_speed = ASpeed(i+1);
				final_speed_int = floatround(final_speed,floatround_round);
				format(string,sizeof(string),"%d KM/H", final_speed_int);
				GameTextForPlayer(playerid, string, 1000, GAME_TEXT_STYLE_4 );						
			}
		}
	}
	GetPlayerKeys(playerid, key, up, dwn);
	if( GetPlayerWeapon( playerid ) == Speedgun && key == KEY_HANDBRAKE )
		gPlayerData[playerid][pSpeedGunOn] = 1;
	else
		gPlayerData[playerid][pSpeedGunOn]++;
	gPlayerData[playerid][pSpeedGunOn]++;
	if( gPlayerData[playerid][pSpeedGunOn] > 60 )
	{
		gPlayerData[playerid][pSpeedGunOn] = 0;
		return 1;
	}
	else
		defer GetPlayerSpeed(playerid);		
    return 1;
}

stock BinaryToDecimal(value[])
{
	new decimal;
	for(new i = 7; i >= 0; i--)
	{
		if(strval(value[i]) > 1)
		{
			decimal += 0 * floatround(floatpower(2.0, float(7-i)), floatround_round);
		}
		else
		{
			decimal += 1 * floatround(floatpower(2.0, float(7-i)), floatround_round);
		}
	}
	printf("6 %d 5 %d 4 %d", strval(value[6]), strval(value[5]), strval(value[4]));
	return decimal;
}

// AddExpPoint(playerid)
// {
	// new string[128];
	// gPlayerData[playerid][pExp]++;
	// SavePlayerData(playerid, "Exp");
	// if(gPlayerData[playerid][pExp] >= (gPlayerData[playerid][pLevel]+1)*levelexp)
	// {
		// gPlayerData[playerid][pLevel]++;
		// gPlayerData[playerid][pExp] = 0;
		// SavePlayerData(playerid, "Level");

		// format(string, sizeof(string), "[INFO:] Zdoby³eœ nowy poziom postaci ! - %d", gPlayerData[playerid][pLevel]);
		// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	// }
	// else
	// {
		// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Otrzymujesz 1pkt doœwiadczenia !");
	// }
	// return 1;
// }

stock ProxDetectorS(Float:radi, playerid, targetid)
{
    if(IsPlayerConnected(playerid)&&IsPlayerConnected(targetid))
	{
		new Float:posx, Float:posy, Float:posz;
		new Float:oldposx, Float:oldposy, Float:oldposz;
		new Float:tempposx, Float:tempposy, Float:tempposz;
		GetPlayerPos(playerid, oldposx, oldposy, oldposz);
		//radi = 2.0; //Trigger Radius
		GetPlayerPos(targetid, posx, posy, posz);
		tempposx = (oldposx -posx);
		tempposy = (oldposy -posy);
		tempposz = (oldposz -posz);
		//printf("DEBUG: X:%f Y:%f Z:%f",posx,posy,posz);
		if (((tempposx < radi) && (tempposx > -radi)) && ((tempposy < radi) && (tempposy > -radi)) && ((tempposz < radi) && (tempposz > -radi)))
		{
		    if(GetPlayerVirtualWorld(playerid) == GetPlayerVirtualWorld(targetid))
		    {
				return 1;
			}
		}
	}
	return 0;
}

stock ProxDetector(Float:radi, playerid, string[],col1,col2,col3,col4,col5)
{
	if(IsPlayerConnected(playerid))
	{
		new Float:posx, Float:posy, Float:posz;
		new Float:oldposx, Float:oldposy, Float:oldposz;
		new Float:tempposx, Float:tempposy, Float:tempposz;

		GetPlayerPos(playerid, oldposx, oldposy, oldposz);
		//radi = 2.0; //Trigger Radius
		foreach(Player, i)
		{
			if(gPlayerLogged[i])
			{
				GetPlayerPos(i, posx, posy, posz);
				tempposx = (oldposx -posx);
				tempposy = (oldposy -posy);
				tempposz = (oldposz -posz);
				//printf("DEBUG: X:%f Y:%f Z:%f",posx,posy,posz);
				if (((tempposx < radi/16) && (tempposx > -radi/16)) && ((tempposy < radi/16) && (tempposy > -radi/16)) && ((tempposz < radi/16) && (tempposz > -radi/16)))
				{
					if(GetPlayerVirtualWorld(i) == GetPlayerVirtualWorld(playerid))
					{
						SendClientMessage(i, col1, string);
					}
				}
				else if (((tempposx < radi/8) && (tempposx > -radi/8)) && ((tempposy < radi/8) && (tempposy > -radi/8)) && ((tempposz < radi/8) && (tempposz > -radi/8)))
				{
					if(GetPlayerVirtualWorld(i) == GetPlayerVirtualWorld(playerid))
					{
						SendClientMessage(i, col2, string);
					}
				}
				else if (((tempposx < radi/4) && (tempposx > -radi/4)) && ((tempposy < radi/4) && (tempposy > -radi/4)) && ((tempposz < radi/4) && (tempposz > -radi/4)))
				{
					if(GetPlayerVirtualWorld(i) == GetPlayerVirtualWorld(playerid))
					{
						SendClientMessage(i, col3, string);
					}
				}
				else if (((tempposx < radi/2) && (tempposx > -radi/2)) && ((tempposy < radi/2) && (tempposy > -radi/2)) && ((tempposz < radi/2) && (tempposz > -radi/2)))
				{
					if(GetPlayerVirtualWorld(i) == GetPlayerVirtualWorld(playerid))
					{
						SendClientMessage(i, col4, string);
					}
				}
				else if (((tempposx < radi) && (tempposx > -radi)) && ((tempposy < radi) && (tempposy > -radi)) && ((tempposz < radi) && (tempposz > -radi)))
				{
					if(GetPlayerVirtualWorld(i) == GetPlayerVirtualWorld(playerid))
					{
						SendClientMessage(i, col5, string);
					}
				}
			}
		}
	}//not connected
	return 1;
}

strtok(string[],&idx,seperator = ' ')
{
	new ret[128], i = 0, len = strlen(string);
	while(string[idx] == seperator && idx < len) idx++;
	while(string[idx] != seperator && idx < len)
	{
	    ret[i] = string[idx];
	    i++;
		idx++;
	}
	while(string[idx] == seperator && idx < len) idx++;
	return ret;
}

stock GivePlayerCash(playerid, money)
{
	gPlayerData[playerid][pCash] += money;

	ResetMoneyBar(playerid);//Resets the money in the original moneybar, Do not remove!
	UpdateMoneyBar(playerid,gPlayerData[playerid][pCash]);//Sets the money in the moneybar to the serverside cash, Do not remove!
	return gPlayerData[playerid][pCash];
}

stock SetPlayerCash(playerid, money)
{
	gPlayerData[playerid][pCash] = money;

	ResetMoneyBar(playerid);//Resets the money in the original moneybar, Do not remove!
	UpdateMoneyBar(playerid,gPlayerData[playerid][pCash]);//Sets the money in the moneybar to the serverside cash, Do not remove
	return gPlayerData[playerid][pCash];
}

stock ResetPlayerCash(playerid)
{
	gPlayerData[playerid][pCash] = 0;
	
	ResetMoneyBar(playerid);//Resets the money in the original moneybar, Do not remove!
	UpdateMoneyBar(playerid,gPlayerData[playerid][pCash]);//Sets the money in the moneybar to the serverside cash, Do not remove!
	return gPlayerData[playerid][pCash];
}

stock GetPlayerCash(playerid)
{
	return gPlayerData[playerid][pCash];
}

ShowStats(playerid,targetid)
{
    if(IsPlayerConnected(playerid)&&IsPlayerConnected(targetid))
	{
		if(gPlayerLogged[targetid])
		{
			SendClientMessage(playerid,COLOR_YELLOW,"____________________________________________________");

			//==========================[VARIABLES]============================
			new joblvl;
			new jobpoints;
			new jobpointsmax;
			new wstring[128];
			new jobtext[128];
			new ranktext[256];
			new donatortext[128];
			new Float:hp;
			GetPlayerHealth(targetid,hp);
			new drugs = gPlayerData[targetid][pDrugs];
		    new playinghours = gPlayerData[targetid][pPlayingHours];
		    new warnings = gPlayerData[targetid][pWarnings];
		    new age = gPlayerData[targetid][pAge];

			//==============================[VIP]==============================
			new viptext[32], vipitemtext[32];
			if( gPlayerData[targetid][pVipExp] == 0 )
			{
				if( gPlayerData[targetid][pVipExpT] > 0 )
					format(viptext, sizeof(viptext), "%d dni", gPlayerData[targetid][pVipExpT]);
				else
					format(viptext, sizeof(viptext), "niekatywny");
			}
			else
				format(viptext, sizeof(viptext), "aktywny");
			if( gPlayerData[targetid][pVipItem] > 0 )
				format(vipitemtext, sizeof(vipitemtext), "%d dni", gPlayerData[targetid][pVipItem]);
			else
				format(vipitemtext, sizeof(vipitemtext), "nieaktywny");
			//=============================[JOBS]==============================
			switch(gPlayerData[targetid][pJob])
			{
			    case 0: jobtext = "Brak";
			    case 1: jobtext = "Diler broni";
			    case 2: jobtext = "Diler narkotyków";
			    case 3: jobtext = "Detektyw";
			    case 4: jobtext = "Prawnik";
			    case 5: jobtext = "Sprzedawca produktów";
				case 6: jobtext = "Prostytutka";
				case 7: jobtext = "Boxer";
				case 8: jobtext = "Gwa³ciciel";
				case 9: jobtext = "Ochroniarz";
				case 10: {jobtext = "Z³odziej samochodów"; jobpoints = gPlayerData[targetid][pCarJackerJobPoints]; jobpointsmax = 20 + (gPlayerData[targetid][pCarJackerJobLvl]*10); joblvl = gPlayerData[targetid][pCarJackerJobLvl]; }
				case 11: jobtext = "Kaskader";
				case 12: jobtext = "Scenarzysta";
				case 13: {jobtext = "Kierowca autobusu"; jobpoints = gPlayerData[targetid][pBusJobPoints]; jobpointsmax = playerNextLvlBusPoints(targetid); joblvl = gPlayerData[targetid][pJobLvl]; }
				case 14: {jobtext = "Kierowca œmieciarki"; jobpoints = gPlayerData[targetid][pMzgkJobPoints]; jobpointsmax = playerNextLvlTrashPoints(targetid); joblvl = gPlayerData[targetid][pMzgkJobLvl]; }
				case 15: {jobtext = "Kierowca myjki drogowej"; jobpoints = gPlayerData[targetid][pSweeperJobPoints]; jobpointsmax = playerNextLvlSweeperPoints(targetid); joblvl = gPlayerData[targetid][pSweeperJobLvl]; }
				case 16: jobtext = "Taksówkarz";
				case 17: {jobtext = "Mechanik"; jobpoints = gPlayerData[targetid][pMechanicJobPoints]; jobpointsmax = 90 + (gPlayerData[targetid][pMechanicJobLvl]*10); joblvl = gPlayerData[targetid][pMechanicJobLvl];}
				case 18: {jobtext = "Farmer"; jobpoints = gPlayerData[targetid][pFarmerJobPoints]; jobpointsmax = playerNextLvlFarmerPoints(targetid); joblvl = gPlayerData[targetid][pFarmerJobLvl]; }
				case 19: {jobtext = "Sprzedawca"; }
				case 20: {jobtext = "Ksiêgowy"; }
				case 21: {jobtext = "Roznosiciel gazet"; }
				case 22: {jobtext = "Pracownik fabryki bron"; }
			}

			//=============================[OTHER]=============================
			switch(gPlayerData[targetid][pDonator])
			{
			    case 0: donatortext = "Nie";
			    case 1: donatortext = "Tak";
			}

			//============================[DISPLAY]============================
   			format(wstring, sizeof(wstring), "[G£ÓWNE:] Gracz: %s - Pkt pracy: %d/%d - Lvl pracy: %d", GetPlayerNameEx(targetid), jobpoints, jobpointsmax, joblvl);
		    SendClientMessage(playerid,COLOR_WHITE, wstring);
			format(wstring, sizeof(wstring), "[G£ÓWNE:] Ostrze¿enia: %d - Narkotyki: %d - Praca: %s", warnings, drugs, jobtext);
		    SendClientMessage(playerid,COLOR_WHITE, wstring);
   			format(wstring, sizeof(wstring), "[G£ÓWNE:] Liczba przegranych godzin: %d - Wiek: %d - VIP: %s - VIP Item: %s", playinghours, age, viptext, vipitemtext);
		    SendClientMessage(playerid,COLOR_WHITE, wstring);
			//===========================[FACTIONS]============================
		    if(gPlayerData[targetid][pFaction] != 255)
			{
	      		switch(gPlayerData[targetid][pRank])
			    {
			        case 1: format(ranktext, sizeof(ranktext), "%s", DynamicFactions[gPlayerData[targetid][pFaction]][fRank1]);
			        case 2: format(ranktext, sizeof(ranktext), "%s", DynamicFactions[gPlayerData[targetid][pFaction]][fRank2]);
			        case 3: format(ranktext, sizeof(ranktext), "%s", DynamicFactions[gPlayerData[targetid][pFaction]][fRank3]);
			        case 4: format(ranktext, sizeof(ranktext), "%s", DynamicFactions[gPlayerData[targetid][pFaction]][fRank4]);
			        case 5: format(ranktext, sizeof(ranktext), "%s", DynamicFactions[gPlayerData[targetid][pFaction]][fRank5]);
			        case 6: format(ranktext, sizeof(ranktext), "%s", DynamicFactions[gPlayerData[targetid][pFaction]][fRank6]);
			        case 7: format(ranktext, sizeof(ranktext), "%s", DynamicFactions[gPlayerData[targetid][pFaction]][fRank7]);
			        case 8: format(ranktext, sizeof(ranktext), "%s", DynamicFactions[gPlayerData[targetid][pFaction]][fRank8]);
			        case 9: format(ranktext, sizeof(ranktext), "%s", DynamicFactions[gPlayerData[targetid][pFaction]][fRank9]);
			        case 10: format(ranktext, sizeof(ranktext), "%s", DynamicFactions[gPlayerData[targetid][pFaction]][fRank10]);
			    }
		 		format(wstring, sizeof(wstring), "[FRAKCJA:] Frakcja: %s - Ranga: %s",DynamicFactions[gPlayerData[targetid][pFaction]][Name],ranktext);
  				SendClientMessage(playerid,COLOR_WHITE, wstring);
			}
			else
			{
				SendClientMessage(playerid,COLOR_WHITE, "[FRAKCJA:] Frakcja: Brak - Ranga: Brak");
			}

			//============================[DISPLAY]============================

			SendClientMessage(playerid,COLOR_YELLOW,"____________________________________________________");
		}
	}
}

stock split2(const strsrc[], strdest[][], delimiter)
{
	new i, li;
	new aNum;
	new len;
	while(i <= strlen(strsrc)){
	    if(strsrc[i]==delimiter || i==strlen(strsrc)){
	        len = strmid(strdest[aNum], strsrc, li, i, 128);
	        strdest[aNum][len] = 0;
	        li = i+1;
	        aNum++;
		}
		i++;
	}
	return 1;
}

stock IsSkinValid(SkinID) return ((SkinID >= 0 && SkinID <= 2)||(SkinID == 7)||(SkinID >= 9 && SkinID <= 41)||(SkinID >= 43 && SkinID <= 85)||(SkinID >=87 && SkinID <= 118)||(SkinID >= 120 && SkinID <= 148)||(SkinID >= 150 && SkinID <= 207)||(SkinID >= 209 && SkinID <= 272)||(SkinID >= 274 && SkinID <= 288)||(SkinID >= 290 && SkinID <= 299)) ? true:false;

stock ClearScreen(playerid)
{
	for(new i = 0; i < 50; i++)
	{
	    SendClientMessage(playerid, COLOR_WHITE, " ");
	}
	return 0;
}

stock GetPlayerFirstName(playerid)
{
	new namestring[2][MAX_PLAYER_NAME];
	new name[MAX_PLAYER_NAME];
	GetPlayerName(playerid,name,MAX_PLAYER_NAME);
	split2(name, namestring, '_');
	return namestring[0];
}

stock GetPlayerLastName(playerid)
{
	new namestring[2][MAX_PLAYER_NAME];
	new name[MAX_PLAYER_NAME];
	GetPlayerName(playerid,name,MAX_PLAYER_NAME);
	split2(name, namestring, '_');
	return namestring[1];
}

stock GetPlayerIpAddress(playerid)
{
	new IP[16];
	GetPlayerIp(playerid, IP, sizeof(IP));
	return IP;
}

stock GetPlayerNameEx(playerid)
{
    new str[24];
    strmid(str,gPlayerData[playerid][pName],0,strlen(gPlayerData[playerid][pName]),24);
    for(new i = 0; i < MAX_PLAYER_NAME; i++)
    {
        if (str[i] == '_') str[i] = ' ';
    }
    return str;
}

stock GetRealName(name[])
{
	new str[24];
    strmid(str, name, 0, strlen(name), 24);
    for(new i = 0; i < MAX_PLAYER_NAME; i++)
    {
        if (str[i] == '_') str[i] = ' ';
    }
    return str;
}
	

stock GetObjectCount()
{
	new count;
	for(new o; o < MAX_OBJECTS; o++)
	{
		if (IsValidObject(o)) count++;
	}
	return count;
}

ReturnUser(text[], playerid = INVALID_PLAYER_ID)
{
	new pos = 0;
	while (text[pos] < 0x21) // Strip out leading spaces
	{
		if (text[pos] == 0) return INVALID_PLAYER_ID; // No passed text
		pos++;
	}
	new userid = INVALID_PLAYER_ID;
	if (IsNumeric(text[pos])) // Check whole passed string
	{
		// If they have a numeric name you have a problem (although names are checked on id failure)
		userid = strval(text[pos]);
		if (userid >=0 && userid < CUSTOM_MAX_PLAYERS)
		{
			if(!IsPlayerConnected(userid))
			{
				/*if (playerid != INVALID_PLAYER_ID)
				{
					SendClientMessage(playerid, 0xFF0000AA, "User not connected");
				}*/
				userid = INVALID_PLAYER_ID;
			}
			else
			{
				return userid; // A player was found
			}
		}
		/*else
		{
			if (playerid != INVALID_PLAYER_ID)
			{
				SendClientMessage(playerid, 0xFF0000AA, "Invalid user ID");
			}
			userid = INVALID_PLAYER_ID;
		}
		return userid;*/
		// Removed for fallthrough code
	}
	// They entered [part of] a name or the id search failed (check names just incase)
	new len = strlen(text[pos]);
	new count = 0;
	new name[MAX_PLAYER_NAME];
	for (new i = 0; i < CUSTOM_MAX_PLAYERS; i++)
	{
		if (IsPlayerConnected(i))
		{
			GetPlayerName(i, name, sizeof (name));
			if (strcmp(name, text[pos], true, len) == 0) // Check segment of name
			{
				if (len == strlen(name)) // Exact match
				{
					return i; // Return the exact player on an exact match
					// Otherwise if there are two players:
					// Me and MeYou any time you entered Me it would find both
					// And never be able to return just Me's id
				}
				else // Partial match
				{
					count++;
					userid = i;
				}
			}
		}
	}
	if (count != 1)
	{
		if (playerid != INVALID_PLAYER_ID)
		{
			if (count)
			{
				SendClientMessage(playerid, 0xFF0000AA, "Multiple users found, please narrow earch");
			}
			else
			{
				SendClientMessage(playerid, 0xFF0000AA, "No matching user found");
			}
		}
		userid = INVALID_PLAYER_ID;
	}
	return userid; // INVALID_USER_ID for bad return
}

IsNumeric(const string[])
{
	for (new i = 0, j = strlen(string); i < j; i++)
	{
		if (string[i] > '9' || string[i] < '0') return 0;
	}
	return 1;
}

KickPlayer(playerid,kickedby[MAX_PLAYER_NAME],reason[])
{
	new string[128];
	format(string,sizeof(string),"%s zosta³ wyrzucony z serwera przez %s, Powód: %s ",GetPlayerNameEx(playerid),kickedby,reason);
	ABroadCast(COLOR_YELLOW,string,1);
	SendModMessage(COLOR_GREEN,string);
	format(string,sizeof(string),"[INFO:] Zosta³eœ wyrzucony z serwera przez %s, Powód: %s ",kickedby,reason);
	SendClientMessage(playerid,COLOR_RED,string);
	KickLog(string);
	return Kick(playerid);
}

BanPlayerAccount(playerid,bannedby[MAX_PLAYER_NAME],reason[])
{
	new string[128];
	format(string,sizeof(string),"%s zosta³ zbanowany przez %s, Powód: %s ",GetPlayerNameEx(playerid),bannedby,reason);
	ABroadCast(COLOR_YELLOW,string,1);
	format(string,sizeof(string),"[INFO:] Zosta³eœ zbanowany przez %s, Powód: %s ",bannedby,reason);
	SendClientMessage(playerid,COLOR_RED,string);
	AccountBanLog(string);
	gPlayerData[playerid][pBanned] = 1;
	SavePlayerData(playerid, "Banned");
	return Kick(playerid);
}

BanPlayer(playerid,bannedby[MAX_PLAYER_NAME],reason[])
{
	new string[128];
	format(string,sizeof(string),"%s zosta³ zbanowany przez %s, Powód: %s ",GetPlayerNameEx(playerid),bannedby,reason);
	ABroadCast(COLOR_YELLOW,string,1);
	format(string,sizeof(string),"[INFO:] Zosta³eœ zbanowany przez %s, Powód: %s ",bannedby,reason);
	SendClientMessage(playerid,COLOR_RED,string);
	BanLog(string);
	return Ban(playerid);
}

stock PlayerToPoint(Float:radi, playerid, Float:x, Float:y, Float:z)
{
    if(IsPlayerConnected(playerid))
	{
		new Float:oldposx, Float:oldposy, Float:oldposz;
		new Float:tempposx, Float:tempposy, Float:tempposz;
		GetPlayerPos(playerid, oldposx, oldposy, oldposz);
		tempposx = (oldposx -x);
		tempposy = (oldposy -y);
		tempposz = (oldposz -z);
		//printf("DEBUG: X:%f Y:%f Z:%f",posx,posy,posz);
		if (((tempposx < radi) && (tempposx > -radi)) && ((tempposy < radi) && (tempposy > -radi)) && ((tempposz < radi) && (tempposz > -radi)))
		{
			return 1;
		}
	}
	return 0;
}

stock ShowServerPassword()
{
	new pass[128];
	if (strlen(PASSWORD) != 0)
	{
		format(pass, sizeof pass, "%s", PASSWORD);
	}
	else
	{
	    pass = "None";
	}
	return pass;
}

stock GetCoords2DZone(Float:x, Float:y, zone[], len)
{
 	for(new i = 0; i != sizeof(gSAZones); i++ )
 	{
		if(x >= gSAZones[i][SAZONE_AREA][0] && x <= gSAZones[i][SAZONE_AREA][3] && y >= gSAZones[i][SAZONE_AREA][1] && y <= gSAZones[i][SAZONE_AREA][4])
		{
		    return format(zone, len, gSAZones[i][SAZONE_NAME], 0);
		}
	}
	return 0;
}

stock GetPlayer2DZone(playerid, zone[], len)
{
	new Float:x, Float:y, Float:z;
	GetPlayerPos(playerid, x, y, z);
	format(zone, len, "Nieznana");
 	for(new i = 0; i != sizeof(gSAZones); i++ )
 	{
		if(x >= gSAZones[i][SAZONE_AREA][0] && x <= gSAZones[i][SAZONE_AREA][3] && y >= gSAZones[i][SAZONE_AREA][1] && y <= gSAZones[i][SAZONE_AREA][4])
		{
		    return format(zone, len, gSAZones[i][SAZONE_NAME], 0);
		}
	}
	return 0;
}

stock GetPlayer3DZone(playerid, zone[], len)
{
	new Float:x, Float:y, Float:z;
	GetPlayerPos(playerid, x, y, z);
 	for(new i = 0; i != sizeof(gSAZones); i++ )
 	{
		if(x >= gSAZones[i][SAZONE_AREA][0] && x <= gSAZones[i][SAZONE_AREA][3] && y >= gSAZones[i][SAZONE_AREA][1] && y <= gSAZones[i][SAZONE_AREA][4] && z >= gSAZones[i][SAZONE_AREA][2] && z <= gSAZones[i][SAZONE_AREA][5])
		{
		    return format(zone, len, gSAZones[i][SAZONE_NAME], 0);
		}
	}
	return 0;
}

stock IsPlayerInZone(playerid, zone[])
{
	new TmpZone[MAX_ZONE_NAME];
	GetPlayer3DZone(playerid, TmpZone, sizeof(TmpZone));
	for(new i = 0; i != sizeof(gSAZones); i++)
	{
		if(strfind(TmpZone, zone, true) != -1)
			return 1;
	}
	return 0;
}

stock IsAtGasStation(playerid)
{
    if(IsPlayerConnected(playerid))
	{
		if(PlayerToPoint(6.0,playerid,1004.0070,-939.3102,42.1797) || PlayerToPoint(6.0,playerid,1944.3260,-1772.9254,13.3906))
		{//LS
		    return 1;
		}
		else if(PlayerToPoint(6.0,playerid,-90.5515,-1169.4578,2.4079) || PlayerToPoint(6.0,playerid,-1609.7958,-2718.2048,48.5391))
		{//LS
		    return 1;
		}
		else if(PlayerToPoint(6.0,playerid,-2029.4968,156.4366,28.9498) || PlayerToPoint(8.0,playerid,-2408.7590,976.0934,45.4175))
		{//SF
		    return 1;
		}
		else if(PlayerToPoint(5.0,playerid,-2243.9629,-2560.6477,31.8841) || PlayerToPoint(8.0,playerid,-1676.6323,414.0262,6.9484))
		{//Between LS and SF
		    return 1;
		}
		else if(PlayerToPoint(6.0,playerid,2202.2349,2474.3494,10.5258) || PlayerToPoint(10.0,playerid,614.9333,1689.7418,6.6968))
		{//LV
		    return 1;
		}
		else if(PlayerToPoint(8.0,playerid,-1328.8250,2677.2173,49.7665) || PlayerToPoint(6.0,playerid,70.3882,1218.6783,18.5165))
		{//LV
		    return 1;
		}
		else if(PlayerToPoint(8.0,playerid,2113.7390,920.1079,10.5255) || PlayerToPoint(6.0,playerid,-1327.7218,2678.8723,50.0625))
		{//LV
		    return 1;
		}
	}
	return 0;
}

stock RemoveDriverFromVehicle(playerid) //This function will be used to avoid issue when removing players from vehicle and them being froze.
{
	if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
	{
		RemovePlayerFromVehicle(playerid);
		//TogglePlayerControllable(playerid,1);
		return 1;
	}
	return 0;
}

stock HexToInt(string[]) {
  if (string[0]==0) return 0;
  new i;
  new cur=1;
  new res=0;
  for (i=strlen(string);i>0;i--) {
    if (string[i-1]<58) res=res+cur*(string[i-1]-48); else res=res+cur*(string[i-1]-65+10);
    cur=cur*16;
  }
  return res;
}

timer HangupTimer[1000](playerid)
{
	if(!IsPlayerInAnyVehicle(playerid))
	{
		if(GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_USECELLPHONE)
		{
			SetPlayerSpecialAction(playerid,SPECIAL_ACTION_STOPUSECELLPHONE);
			RemovePlayerAttachedObject(playerid, 4);
			return 1;
		}
	}
	return 0;
}

stock PlayerName(playerid) 
{
  new name[255];
  GetPlayerName(playerid, name, 255);
  return name;
}

stock IsACopSkin(skinid)
{
	if(skinid == 280 || skinid == 281 || skinid == 282 || skinid == 283 || skinid == 288 || skinid == 284 || skinid == 285 || skinid == 286 || skinid == 287)
	{
		return 1;
	}
	return 0;
}

/*
* Clears vehicle data ( and destroy it by vehicle ID )
*
* Parameter 'reason' was made to force destroy vehicle
* if its HP doesn't below 25.0 points.
*/
timer ResetVehicleData[5000](vehicleid, reason)
{
	//print("[TIMERCHECK:] ResetVehicleData(vehicleid, reason)");
	new Float:vHealth;
	GetVehicleHealth(vehicleid, vHealth);
	VehJustRespawned[vehicleid-1] = 20;
	if((vHealth < 25 || reason == 1) && gVehData[vehicleid-1][mVehType] == 0)
	{
		new vehiclemodel = GetVehicleModel(vehicleid);

		new string[256];
		format(string, sizeof(string), "[VEHICLE:] ID: %d, Model: %d, by ResetVehicleData(), reason %d ", vehicleid, vehiclemodel, reason);
		VehicleLog(string);
		/* Remove vehicle from import slot if it is found */
		if(IsAPlane(vehicleid) || IsAHelicopter(vehicleid))
		{
			for(new i = 0; i < 20; i++)
			{
				if(SpawnPlacePlanes[i][VehicleID] == vehicleid)
				{
					Businesses[gVehData[vehicleid-1][BusinessID]][VehicleOrderCount]--;
					SpawnPlacePlanes[i][VehicleID] = 255;
					SpawnPlacePlanes[i][SlotUsed] = 0;
					SaveDynamicPlanesSpawns();
					VehicleLog("[VEHICLE:] not prepaired for sale !");
					break;
				}
			}
		}
		if(IsABoat(vehicleid))
		{
			for(new i = 0; i < 20; i++)
			{
				if(SpawnPlaceBoats[i][VehicleID] == vehicleid)
				{
					Businesses[gVehData[vehicleid-1][BusinessID]][VehicleOrderCount]--;
					SpawnPlaceBoats[i][VehicleID] = 255;
					SpawnPlaceBoats[i][SlotUsed] = 0;
					SaveDynamicBoatsSpawns();
					VehicleLog("[VEHICLE:] not prepaired for sale !");
					break;
				}
			}
		}
		if(!IsABoat(vehicleid) && !IsAPlane(vehicleid) && !IsAHelicopter(vehicleid))
		{
			for(new i = 0; i < 20; i++)
			{
				if(SpawnPlaceCars[i][VehicleID] == vehicleid)
				{
					Businesses[gVehData[vehicleid-1][BusinessID]][VehicleOrderCount]--;
					SpawnPlaceCars[i][VehicleID] = 255;
					SpawnPlaceCars[i][SlotUsed] = 0;
					SaveDynamicCarSpawns();
					VehicleLog("[VEHICLE:] not prepaired for sale !");
					break;
				}
			}
		}
		/* Decrease vehicle cout from business if the vehicle wasn't bough */
		if(gVehData[vehicleid-1][BusinessID] != 255 && gVehData[vehicleid-1][mVehFaction] == 255 && gVehData[vehicleid-1][mVehType] == 0 && gVehData[vehicleid-1][mVehOwned] == 0)
		{
			Businesses[gVehData[vehicleid-1][BusinessID]][VehicleCount]--;
		}
		/* Decrease vehicle cout from faction */
		if(gVehData[vehicleid-1][mVehFaction] != 255)
		{
			if(!(DynamicFactions[gVehData[vehicleid-1][mVehFaction]][fCarsCount] <= 0))
			{
				DynamicFactions[gVehData[vehicleid-1][mVehFaction]][fCarsCount]--;
				SaveFData(gVehData[vehicleid-1][mVehFaction], "CarsCount");
			}
		}
		if(gVehData[vehicleid-1][ReadyToSell] == 1)
		{
			DestroyDynamic3DTextLabel(gVehData[vehicleid-1][Veh3DSell]);
		}
		if(gVehData[vehicleid-1][Veh3DTaxiNfo])
			DestroyDynamic3DTextLabel(gVehData[vehicleid-1][Veh3DTaxiNfo]);
		if(gVehData[vehicleid-1][Veh3DTaxiNfo2])
			DestroyDynamic3DTextLabel(gVehData[vehicleid-1][Veh3DTaxiNfo2]);
		if(gVehData[vehicleid-1][mVehFaction] != 255)
		{
			if( DynamicFactions[ gVehData[vehicleid-1][mVehFaction] ][fType] == 6 )
			{
				// DestroyDynamic3DTextLabel( gVehData[vehicleid-1][Veh3DTaxiNfo] );
				// DestroyDynamic3DTextLabel( gVehData[vehicleid-1][Veh3DTaxiNfo2] );
			}
		}
		GetVehiclePos(vehicleid, gVehData[vehicleid-1][mVehX], gVehData[vehicleid-1][mVehY], gVehData[vehicleid-1][mVehZ] );
		SaveVehData(vehicleid-1, "VehPos");
		if(vehicleid != 255 && vehicleid != 256)
		{
			if(gVehData[vehicleid-1][CustomObj1ID] != 0)
			{
				DestroyDynamicObject( gVehData[vehicleid-1][CustomObj1ID] );
				gVehData[vehicleid-1][CustomObj1ID] = 0;
			}
			if(gVehData[vehicleid-1][CustomObj2ID] != 0)
			{
				DestroyDynamicObject( gVehData[vehicleid-1][CustomObj2ID] );
				gVehData[vehicleid-1][CustomObj2ID] = 0;
			}
			if(gVehData[vehicleid-1][CustomObj3ID] != 0)
			{
				DestroyDynamicObject( gVehData[vehicleid-1][CustomObj3ID] );
				gVehData[vehicleid-1][CustomObj3ID] = 0;
			}	
			if(gVehData[vehicleid-1][CustomObj4ID] != 0)
			{
				DestroyDynamicObject( gVehData[vehicleid-1][CustomObj4ID] );
				gVehData[vehicleid-1][CustomObj4ID] = 0;
			}	
			if(gVehData[vehicleid-1][CustomObj5ID] != 0)
			{
				DestroyDynamicObject( gVehData[vehicleid-1][CustomObj5ID] );
				gVehData[vehicleid-1][CustomObj5ID] = 0;
			}	
			if(gVehData[vehicleid-1][CustomObj6ID] != 0)
			{
				DestroyDynamicObject( gVehData[vehicleid-1][CustomObj6ID] );
				gVehData[vehicleid-1][CustomObj6ID] = 0;
			}	
			if(gVehData[vehicleid-1][CustomObj7ID] != 0)
			{
				DestroyDynamicObject( gVehData[vehicleid-1][CustomObj7ID] );
				gVehData[vehicleid-1][CustomObj7ID] = 0;
			}	
			gVehData[vehicleid-1][mVehModel] = 594;
			gVehData[vehicleid-1][mVehX] = 4500.0;
			gVehData[vehicleid-1][mVehY] = 300.0;
			gVehData[vehicleid-1][mVehZ] = 3.0;
			gVehData[vehicleid-1][mVehA] = 0.0;
			gVehData[vehicleid-1][mVehColor1] = -1;
			gVehData[vehicleid-1][mVehColor2] = -1;
			gVehData[vehicleid-1][mVehFaction] = 255;
			gVehData[vehicleid-1][mVehVinNo] = 0;
			gVehData[vehicleid-1][mVehType] = 0;
			gVehData[vehicleid-1][mVehOwned] = 0;
			strmid(gVehData[vehicleid-1][Owner], "None", 0, 4, 128);
			gVehData[vehicleid-1][Price] = 0;
			gVehData[vehicleid-1][Closed] = 0;
			gVehData[vehicleid-1][CarResetT] = 0;
			gVehData[vehicleid-1][CarDamaged] = 0;
			gVehData[vehicleid-1][CarRepairTimeLeft] = 0;
			gVehData[vehicleid-1][BusinessID] = 255;
			gVehData[vehicleid-1][CarFuel] = float(VehFTank(vehicleid));
			gVehData[vehicleid-1][CarHealth] = 1000.0;
			gVehData[vehicleid-1][ReadyToSell] = 0;
			gVehData[vehicleid-1][CarCounter] = 0;
			gVehData[vehicleid-1][Fuel] = 0;
			gVehData[vehicleid-1][CarPanels] = 0;
			gVehData[vehicleid-1][CarDoors] = 0;
			gVehData[vehicleid-1][CarLights] = 0;
			gVehData[vehicleid-1][CarTires] = 0;
			strmid(gVehData[vehicleid-1][LastDriverWKey], "None", 0, 4, 128);
			gVehData[vehicleid-1][CarSerial] = 0;
			gVehData[vehicleid-1][PaintStep] = 0;
			gVehData[vehicleid-1][WheelStep] = 0;
			gVehData[vehicleid-1][EngineOn] = 0;
			gVehData[vehicleid-1][LightsOn] = 0;
			gVehData[vehicleid-1][BonnetUp] = 0;
			gVehData[vehicleid-1][BootUp] = 0;
			gVehData[vehicleid-1][RadioOn] = 0;
			gVehData[vehicleid-1][Hook] = 0;
			gVehData[vehicleid-1][Alarm] = 0;
			gVehData[vehicleid-1][CustomObj1Model] = 0;
			gVehData[vehicleid-1][CustomObj2Model] = 0;
			gVehData[vehicleid-1][CustomObj3Model] = 0;
			gVehData[vehicleid-1][BatteryCapacity] = 25.0;
			gVehData[vehicleid-1][BatteryMaxCapacity] = 25.0;
			gVehData[vehicleid-1][VConfiscated] = 0;
			gVehData[vehicleid-1][VItem1] = 0;
			gVehData[vehicleid-1][VItem2] = 0;
			gVehData[vehicleid-1][VItem3] = 0;
			gVehData[vehicleid-1][VItem4] = 0;
			gVehData[vehicleid-1][VItem5] = 0;
			gVehData[vehicleid-1][VItem6] = 0;
			gVehData[vehicleid-1][VItem7] = 0;
			gVehData[vehicleid-1][VItem8] = 0;
			gVehData[vehicleid-1][VItem9] = 0;
			gVehData[vehicleid-1][VItem10] = 0;
			gVehData[vehicleid-1][VItem11] = 0;
			gVehData[vehicleid-1][VItem12] = 0;
			gVehData[vehicleid-1][VItem13] = 0;
			gVehData[vehicleid-1][VItem14] = 0;
			gVehData[vehicleid-1][VItem15] = 0;
			gVehData[vehicleid-1][VItem1type] = 0;
			gVehData[vehicleid-1][VItem2type] = 0;
			gVehData[vehicleid-1][VItem3type] = 0;
			gVehData[vehicleid-1][VItem4type] = 0;
			gVehData[vehicleid-1][VItem5type] = 0;
			gVehData[vehicleid-1][VItem6type] = 0;
			gVehData[vehicleid-1][VItem7type] = 0;
			gVehData[vehicleid-1][VItem8type] = 0;
			gVehData[vehicleid-1][VItem9type] = 0;
			gVehData[vehicleid-1][VItem10type] = 0;
			gVehData[vehicleid-1][VItem11type] = 0;
			gVehData[vehicleid-1][VItem12type] = 0;
			gVehData[vehicleid-1][VItem13type] = 0;
			gVehData[vehicleid-1][VItem14type] = 0;
			gVehData[vehicleid-1][VItem15type] = 0;			
			gVehData[vehicleid-1][mVehSpoiler] = 0;
			gVehData[vehicleid-1][mVehHood] = 0;
			gVehData[vehicleid-1][mVehRoof] = 0;
			gVehData[vehicleid-1][mVehSideskirt] = 0;
			gVehData[vehicleid-1][mVehLamps] = 0;
			gVehData[vehicleid-1][mVehNitro] = 0;
			gVehData[vehicleid-1][mVehExhaust] = 0;
			gVehData[vehicleid-1][mVehWheels] = 0;
			gVehData[vehicleid-1][mVehStereo] = 0;
			gVehData[vehicleid-1][mVehHydraulics] = 0;
			gVehData[vehicleid-1][mVehFrontBumper] = 0;
			gVehData[vehicleid-1][mVehRearBumper] = 0;
			gVehData[vehicleid-1][mVehVentLeft] = 0;
			gVehData[vehicleid-1][mVehVentRight] = 0;			
			gVehData[vehicleid-1][VCBRadio] = 0;
			gVehData[vehicleid-1][VPoliceComputer] = 0;
			gVehData[vehicleid-1][VConfiscated] = 0;
			gVehData[vehicleid-1][mVehSirenObjModel] = 0;
			
			SaveVehData(vehicleid-1, "VehModel");
			SaveVehData(vehicleid-1, "VehPos");
			SaveVehData(vehicleid-1, "VehColor1");
			SaveVehData(vehicleid-1, "VehColor2");
			SaveVehData(vehicleid-1, "VehFaction");
			SaveVehData(vehicleid-1, "VehVinNo");
			SaveVehData(vehicleid-1, "VehType");
			SaveVehData(vehicleid-1, "VehOwned");
			SaveVehData(vehicleid-1, "Owner");
			SaveVehData(vehicleid-1, "Price");
			SaveVehData(vehicleid-1, "Closed");
			SaveVehData(vehicleid-1, "CarResetT");
			SaveVehData(vehicleid-1, "CarDamaged");
			SaveVehData(vehicleid-1, "CarRepairTimeLeft");
			SaveVehData(vehicleid-1, "BusinessID");
			SaveVehData(vehicleid-1, "CarFuel");
			SaveVehData(vehicleid-1, "CarHealth");
			SaveVehData(vehicleid-1, "ReadyToSell");
			SaveVehData(vehicleid-1, "CarCounter");
			SaveVehData(vehicleid-1, "Fuel");
			SaveVehData(vehicleid-1, "CarPanels");
			SaveVehData(vehicleid-1, "CarDoors");
			SaveVehData(vehicleid-1, "CarLights");
			SaveVehData(vehicleid-1, "CarTires");
			SaveVehData(vehicleid-1, "LastDriverWKey");
			SaveVehData(vehicleid-1, "CarSerial");
			SaveVehData(vehicleid-1, "PaintStep");
			SaveVehData(vehicleid-1, "WheelStep");
			SaveVehData(vehicleid-1, "EngineOn");
			SaveVehData(vehicleid-1, "LightsOn");
			SaveVehData(vehicleid-1, "BonnetUp");
			SaveVehData(vehicleid-1, "BootUp");
			SaveVehData(vehicleid-1, "RadioOn");
			SaveVehData(vehicleid-1, "Hook");
			SaveVehData(vehicleid-1, "Alarm");
			SaveVehData(vehicleid-1, "CustomObj1Model");
			SaveVehData(vehicleid-1, "CustomObj2Model");
			SaveVehData(vehicleid-1, "CustomObj3Model");
			SaveVehData(vehicleid-1, "BatteryCapacity");
			SaveVehData(vehicleid-1, "Confiscated");
			SaveVehData(vehicleid-1, "Item1");
			SaveVehData(vehicleid-1, "Item2");
			SaveVehData(vehicleid-1, "Item3");
			SaveVehData(vehicleid-1, "Item4");
			SaveVehData(vehicleid-1, "Item5");
			SaveVehData(vehicleid-1, "Item6");
			SaveVehData(vehicleid-1, "Item7");
			SaveVehData(vehicleid-1, "Item8");
			SaveVehData(vehicleid-1, "Item9");
			SaveVehData(vehicleid-1, "Item10");
			SaveVehData(vehicleid-1, "Item11");
			SaveVehData(vehicleid-1, "Item12");
			SaveVehData(vehicleid-1, "Item13");
			SaveVehData(vehicleid-1, "Item14");
			SaveVehData(vehicleid-1, "Item15");
			SaveVehData(vehicleid-1, "Item1type");
			SaveVehData(vehicleid-1, "Item2type");
			SaveVehData(vehicleid-1, "Item3type");
			SaveVehData(vehicleid-1, "Item4type");
			SaveVehData(vehicleid-1, "Item5type");
			SaveVehData(vehicleid-1, "Item6type");
			SaveVehData(vehicleid-1, "Item7type");
			SaveVehData(vehicleid-1, "Item8type");
			SaveVehData(vehicleid-1, "Item9type");
			SaveVehData(vehicleid-1, "Item10type");
			SaveVehData(vehicleid-1, "Item11type");
			SaveVehData(vehicleid-1, "Item12type");
			SaveVehData(vehicleid-1, "Item13type");
			SaveVehData(vehicleid-1, "Item14type");
			SaveVehData(vehicleid-1, "Item15type");
			SaveVehData(vehicleid-1, "VehSaveTune");
			SaveVehData(vehicleid-1, "CBRadio");
			SaveVehData(vehicleid-1, "Confiscated");
			SaveVehData(vehicleid-1, "PoliceComputer");
			SaveVehData(vehicleid-1, "VehSirenObjModel");
		}
		/* Removes vehicle serial number */
		DestroyDynamic3DTextLabel( gVehData[vehicleid-1][Veh3DSerial] );
		DestroyVehicle(vehicleid);
		CreateVehicle(gVehData[vehicleid-1][mVehModel], gVehData[vehicleid-1][mVehX], gVehData[vehicleid-1][mVehY], gVehData[vehicleid-1][mVehZ], 0.0, -1, -1, -1);
		SetVehicleParamsEx(vehicleid, 0, 0, 0, 0, 0, 0, 0);
		//printf("[%d-%d-%d] [VEHICLE:] Vehicle id: %d data has been reset", Year, Month, Day, vehicleid);
	}
	else
	{
		DestroyVehicle(vehicleid);
		CreateVehicle(gVehData[vehicleid-1][mVehModel], gVehData[vehicleid-1][mVehX], gVehData[vehicleid-1][mVehY], gVehData[vehicleid-1][mVehZ], 0.0, gVehData[vehicleid-1][mVehColor1], gVehData[vehicleid-1][mVehColor2], -1);
		SetVehicleParamsEx(vehicleid, gVehData[vehicleid-1][EngineOn], gVehData[vehicleid-1][LightsOn], gVehData[vehicleid-1][Alarm], gVehData[vehicleid-1][Closed], gVehData[vehicleid-1][BonnetUp], gVehData[vehicleid-1][BootUp], 0);
	}
}

PhoneAnimation(playerid)
{
	if(!IsPlayerInAnyVehicle(playerid))
	{
		SetPlayerSpecialAction(playerid,SPECIAL_ACTION_USECELLPHONE);
		SetPlayerAttachedObject(playerid, 1, 330, 6);
		HangupTimer(playerid);
		return 1;
	}
	return 0;
}

timer DrugEffect[2500](playerid)
{
	SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] Jesteœ na haju !");
 	SetPlayerWeather(playerid, 500);
	defer UndrugEffect[50000](playerid);
	return 1;
}

timer DrugEffectHard[1000](playerid)
{
	if(gPlayerData[playerid][pDrugsTaken] >= 10)
	{
		if(gPlayerData[playerid][pDrugsAddicted] == 0)
		{
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] Uzale¿ni³eœ siê od narkotyków !");
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Zg³oœ sie do najblizszego lekarza");
			gPlayerData[playerid][pDrugsAddicted] = 1;
			SavePlayerData(playerid, "DrugsAddicted");
		}
	}
	SetPlayerWeather(playerid, 500);
    ApplyAnimation(playerid,"PED","WALK_DRUNK",4.1,1,1,1,1,1);
    defer UndrugEffect[90000](playerid);
	return 1;
}

timer UndrugEffect[10000](playerid)
{
	new Float:armour;
	new Float:hp;
	GetPlayerArmour(playerid, armour);
	GetPlayerHealth(playerid, hp);
	if(pDrugsUsedStartHP[playerid] != 0.0)
	{
		SetPlayerHealth(playerid, pDrugsUsedStartHP[playerid]);
		pDrugsUsedStartHP[playerid] = 0.0;
	}
	else
	{
		if(hp > 100.0)
		{
			SetPlayerHealth(playerid, 100.0);
		}
	}
	if(pDrugsUsedStartArmour[playerid] != 0.0)
	{
		SetPlayerArmourEx(playerid, pDrugsUsedStartArmour[playerid]);
		pDrugsUsedStartArmour[playerid] = 0.0;
	}
	else
	{
		if(armour > 100.0)
		{
			SetPlayerArmourEx(playerid, 100.0);
		}
	}
	gPlayerData[playerid][pDrugsEffect] = 0;
	SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] Nie jesteœ ju¿ na haju !");
 	SetPlayerWeather(playerid, 0);
	gPlayerData[playerid][pDrugsTaken] = 0;
	return 1;
}

stock IsValidSkin(skinid)
{
    #define	MAX_BAD_SKINS 22
    new badSkins[MAX_BAD_SKINS] =
    {
        3, 4, 5, 6, 8, 42, 65, 74, 86,
        119, 149, 208, 265, 266, 267,
        268, 269, 270, 271, 272, 273, 289
    };
    if (skinid < 0 || skinid > 299) return false;
    for (new i = 0; i < MAX_BAD_SKINS; i++)
    {
        if (skinid == badSkins[i]) return false;
    }
    #undef MAX_BAD_SKINS
    return 1;
}

stock Float:GetDistanceBetweenPlayers(p1,p2)
{
	new Float:x1,Float:y1,Float:z1,Float:x2,Float:y2,Float:z2;
	if(!IsPlayerConnected(p1) || !IsPlayerConnected(p2))
	{
		return -1.00;
	}
	GetPlayerPos(p1,x1,y1,z1);
	GetPlayerPos(p2,x2,y2,z2);
	return floatsqroot(floatpower(floatabs(floatsub(x2,x1)),2)+floatpower(floatabs(floatsub(y2,y1)),2)+floatpower(floatabs(floatsub(z2,z1)),2));
}

stock GetClosestPlayer(p1)
{
	new x,Float:dis,Float:dis2,player;
	player = -1;
	dis = 99999.99;
	for (x=0;x<CUSTOM_MAX_PLAYERS;x++)
	{
		if(IsPlayerConnected(x))
		{
			if(x != p1)
			{
				dis2 = GetDistanceBetweenPlayers(x,p1);
				if(dis2 < dis && dis2 != -1.00)
				{
					dis = dis2;
					player = x;
				}
			}
		}
	}
	return player;
}

ResetPlayerWantedLevelEx(playerid)
{
  	SetPlayerWantedLevel(playerid, 0);
	WantedLevel[playerid] = 0;
	return 1;
}

SetPlayerWantedLevelEx(playerid,level)
{
  	SetPlayerWantedLevel(playerid, level);
	WantedLevel[playerid] = level;
	return 1;
}

timer UntazePlayer[10000](playerid)
{
	if(PlayerTazed[playerid] == 1)
	{
	    SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] Otrz¹sn¹³eœ siê z parali¿u.");
		TogglePlayerControllable(playerid, 1);
	    PlayerTazed[playerid] = 0;
	    PlayerActionMessage(playerid,15.0,"nie jest ju¿ sparali¿owany.");
	}
	return 1;
}

stock IsAtBar(playerid)
{
    if(IsPlayerConnected(playerid))
	{
		if(PlayerToPoint(4.0,playerid,495.7801,-76.0305,998.7578) || PlayerToPoint(4.0,playerid,499.9654,-20.2515,1000.6797))
		{//In grove street bar (with girlfriend), and in Havanna
		    return 1;
		}
		else if(PlayerToPoint(4.0,playerid,1215.9480,-13.3519,1000.9219) || PlayerToPoint(10.0,playerid,-2658.9749,1407.4136,906.2734))
		{//PIG Pen
		    return 1;
		}
	}
	return 0;
} // end of IsAtBar

stock TurnPlayerFaceToPos(playerid, Float:x, Float:y)
{
    new Float:angle;
    new Float:misc = 5.0;
    new Float:ix, Float:iy, Float:iz;
    GetPlayerPos(playerid, ix, iy, iz);
    angle = 180.0-atan2(ix-x,iy-y);
    angle += misc;
    misc *= -1;
    SetPlayerFacingAngle(playerid, angle+misc);
}

timer ClearCheckpointsForPlayer[60000](playerid)
{
	DisablePlayerCheckpoint(playerid);
	if(gPlayerData[playerid][pJob] == 3)
	{
		if(TrackingPlayer[playerid])
		{
		    SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] Nie œledzisz ju¿ danej osoby.");
			TrackingPlayer[playerid] = 0;
		}
		if(TrackingCar[playerid])
		{
		    SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] Nie œledzisz ju¿ danej osoby.");
			TrackingCar[playerid] = 0;
		}
	}
	return 1;
}// end of ClerCheckpointsForPlayer

stock IsValidName(playerid)
{
    if (IsPlayerConnected(playerid))
    {
        new player[24];
        GetPlayerName(playerid,player,24);
        for(new n = 0; n < strlen(player); n++)
        {
        	if (player[n] == '_') return 1;
        	if (player[n] == ']' || player[n] == '[') return 0;
        }
    }
    return 0;
}

task IdleKick[300000]()
{
	new plname[64];
	new string[128];
	for(new i = 0; i < CUSTOM_MAX_PLAYERS; i++)
	{
		if(IsPlayerConnected(i))
		{
		    if(gPlayerData[i][pAdmin] < 1)
		    {
				if(gPlayerData[i][pVipAFK] == 0 && gPlayerData[i][pVipAFKT] == 0 && gPlayerData[i][pQuiz])
				{
					GetPlayerPos(i, PlayerPos[i][0], PlayerPos[i][1], PlayerPos[i][2]);
					// NOTE: Anti AFK is OFF !
					// if(PlayerPos[i][0] == PlayerPos[i][3] && PlayerPos[i][1] == PlayerPos[i][4] && PlayerPos[i][2] == PlayerPos[i][5] && PlayerWrittingAnything[i] == 0)
					// {
						// GetPlayerName(i, plname, sizeof(plname));
						// format(string, sizeof(string), "[SERVER:] %s zosta³ wyrzucony z serwera, powód: AFK", plname);
						// ABroadCast(COLOR_YELLOW,string,1);
						// Kick(i);
					// }
					PlayerWrittingAnything[i] = 0;
					PlayerPos[i][3] = PlayerPos[i][0];
					PlayerPos[i][4] = PlayerPos[i][1];
					PlayerPos[i][5] = PlayerPos[i][2];
				}
				if(gPlayerData[i][pVipAFK] == 1 || gPlayerData[i][pVipAFKT] != 0)
				{
					GetPlayerPos(i, PlayerPos[i][0], PlayerPos[i][1], PlayerPos[i][2]);
					if(PlayerPos[i][0] == PlayerPos[i][3] && PlayerPos[i][1] == PlayerPos[i][4] && PlayerPos[i][2] == PlayerPos[i][5])
					{
						VipAFKActive[i] = 1;
						// UpdateDynamic3DTextLabelText(playerAFK[i], COLOR_LIGHTBLUE, "AFK");
					}
					else
					{
						VipAFKActive[i] = 0;
						// UpdateDynamic3DTextLabelText(playerAFK[i], COLOR_LIGHTBLUE, " ");
					}
					PlayerPos[i][3] = PlayerPos[i][0];
					PlayerPos[i][4] = PlayerPos[i][1];
					PlayerPos[i][5] = PlayerPos[i][2];
				}
			}
		}
	}
}

// ReduceTimer(playerid)
// {
	// if(IsPlayerConnected(playerid))
	// {
	    // if(ReduceTime[playerid] == 1)
	    // {
			// ReduceTime[playerid] = 0;
	    // }
	// }
// }

RemovePlayerWeapon(playerid, weaponid)
{
	new plyWeapons[12] = 0;
	new plyAmmo[12] = 0;
	for(new slot = 0; slot != 12; slot++)
	{
		new wep, ammo;
		GetPlayerWeaponData(playerid, slot, wep, ammo);

		if(wep != weaponid && ammo != 0)
		{
			GetPlayerWeaponData(playerid, slot, plyWeapons[slot], plyAmmo[slot]);
		}
	}
	SafeResetPlayerWeapons(playerid);
	for(new slot = 0; slot != 12; slot++)
	{
	    if(plyAmmo[slot] != 0)
	    {
			SafeGivePlayerGun(playerid, plyWeapons[slot], plyAmmo[slot]);
		}
	}
	return 1;
}

SafeGivePlayerGun(plyid, weaponid, ammo)
{
/*	new curHour, curMinute, curSecond;
	gettime(curHour, curMinute, curSecond);
	ScriptWeaponsUpdated[plyid] = curSecond;*/
	GivePlayerGun(plyid, weaponid, ammo);
	//UpdateWeaponSlots(plyid);
	return 1;
}

SafeResetPlayerWeapons(plyid)
{
/*	new curHour, curMinute, curSecond;
	gettime(curHour, curMinute, curSecond);
	ScriptWeaponsUpdated[plyid] = curSecond;*/
	ResetPlayerWeapons(plyid);
	//UpdateWeaponSlots(plyid);
	return 1;
}

stock strvalEx( const string[] ) // fix for strval-bug with > 50 letters.
{
	// written by mabako in less than a minute :X
	if( strlen( string ) >= 50 ) return 0; // It will just return 0 if the string is too long
	return strval(string);
}

stock Encrypt(string[])
{
	for(new x=0; x < strlen(string); x++)
	  {
		  string[x] += (3^x) * (x % 15);
		  if(string[x] > (0xff))
		  {
			  string[x] -= 256;
		  }
	  }
	return 1;
}

NewbieOff(color,const string[])
{
	for(new i = 0; i < CUSTOM_MAX_PLAYERS; i++)
	{
		if(IsPlayerConnected(i))
		{
			SendClientMessage(i, color, string);
		}
	}
}

stock ini_GetKey( line[] )
{
	new keyRes[256];
	keyRes[0] = 0;
    if ( strfind( line , "=" , true ) == -1 ) return keyRes;
    strmid( keyRes , line , 0 , strfind( line , "=" , true ) , sizeof( keyRes) );
    return keyRes;
}

stock ini_GetValue( line[] )
{
	new valRes[256];
	valRes[0]=0;
	if ( strfind( line , "=" , true ) == -1 ) return valRes;
	strmid( valRes , line , strfind( line , "=" , true )+1 , strlen( line ) , sizeof( valRes ) );
	return valRes;
}

stock GetPosFromView(playerid, Float:distance, &Float:x, &Float:y, &Float:z)
{
  new Float:cx,Float:cy,Float:cz,Float:fx,Float:fy,Float:fz;
  GetPlayerCameraPos(playerid, cx, cy, cz);
  GetPlayerCameraFrontVector(playerid, fx, fy, fz);
  x = fx * distance + cx;
  y = fy * distance + cy;
  z = fz * distance + cz;
}

stock IsPointInArea(Float:aMinX, Float:aMinY, Float:aMaxX, Float:aMaxY, Float:pX, Float:pY)
{
	if(pX <= aMaxX && pX >= aMinX && pY <= aMaxY && pY >= aMinY)
		return 1;
	else
		return 0;
}

stock IsPlayerInArea(playerid, Float:max_x, Float:min_x, Float:max_y, Float:min_y)
{
        new Float:Xa, Float:Ya, Float:Za;
        GetPlayerPos(playerid, Xa, Ya, Za);
        if(Xa <= max_x && Xa >= min_x && Ya <= max_y && Ya >= min_y)
			return 1;
		else
			return 0;
}

stock GetName(playerid)
{
	new name[MAX_PLAYER_NAME];
	GetPlayerName(playerid,name,sizeof(name));

	return name;
}

stock GetDistanceToPoint(playerid,Float:x,Float:y,Float:z)
{
	new Float:dis;
	new Float:x1,Float:y1,Float:z1;
	if (!IsPlayerConnected(playerid)) return -1;
	GetPlayerPos(playerid,x1,y1,z1);
	dis = floatsqroot(floatpower(floatabs(floatsub(x,x1)),2)+floatpower(floatabs(floatsub(y,y1)),2)+floatpower(floatabs(floatsub(z,z1)),2));
	return floatround(dis);
}

timer UnfreezePlayer[2800](playerid)
{
	TogglePlayerControllable(playerid, 1);
	return 1;
}

/*stock MoveCamera(playerid) // need fix, unauthorized use of gPlayerData[playerid][SpawnAngle]
{
	this is called trigonometry. It makes the camera spin
	you can experiment with this line. Just change the values 2, 10 and 3 to make different effects
	SetPlayerCameraPos(playerid, player_x - 13 * floatsin(-gPlayerData[playerid][SpawnAngle], degrees), player_y - 16 * floatcos(-gPlayerData[playerid][SpawnAngle], degrees), player_z + 3);
    SetPlayerCameraLookAt(playerid, player_x, player_y, player_z + 2);
	changing the angle a little
	MoveCameraAngle[playerid] += 0.5;
    if (MoveCameraAngle[playerid] >= 360.0)
		MoveCameraAngle[playerid] = 0.0;
}*/

stock ReturnWFactoryParts( playerid, slot, slotitem )
{
	switch( slotitem )
	{
		case 43:
		{
			DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart1a]  += SlotParam6( playerid, slot );
			SaveFData( gPlayerData[playerid][pFaction], "WFactoryAmmoPart1a" );
		}
		case 44:
		{
			DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart1b]  += SlotParam6( playerid, slot );
			SaveFData( gPlayerData[playerid][pFaction], "WFactoryAmmoPart1b" );
		}
		case 45:
		{
			DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart1c]  += SlotParam6( playerid, slot );
			SaveFData( gPlayerData[playerid][pFaction], "WFactoryAmmoPart1c" );
		}
		case 46:
		{
			DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart1d]  += SlotParam6( playerid, slot );
			SaveFData( gPlayerData[playerid][pFaction], "WFactoryAmmoPart1d" );
		}
		case 47:
		{
			DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart2a]  += SlotParam6( playerid, slot );
			SaveFData( gPlayerData[playerid][pFaction], "WFactoryAmmoPart2a" );
		}
		case 48:
		{
			DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart1]  += SlotParam6( playerid, slot );
			SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolPart1" );
		}
		case 49:
		{
			DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart2]  += SlotParam6( playerid, slot );
			SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolPart2" );
		}
		case 50:
		{
			DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart3]  += SlotParam6( playerid, slot );
			SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolPart3" );
		}
		case 51:
		{
			DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart4]  += SlotParam6( playerid, slot );
			SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolPart4" );
		}
		case 52:
		{
			DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart5]  += SlotParam6( playerid, slot );
			SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolPart5" );
		}
		case 53:
		{
			DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart1]  += SlotParam6( playerid, slot );
			SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflePart1" );
		}
		case 54:
		{
			DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart2]  += SlotParam6( playerid, slot );
			SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflePart2" );
		}
		case 55:
		{
			DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart3]  += SlotParam6( playerid, slot );
			SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflePart3" );
		}
		case 56:
		{
			DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart4]  += SlotParam6( playerid, slot );
			SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflePart4" );
		}
		case 57:
		{
			DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart5]  += SlotParam6( playerid, slot );
			SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflePart5" );
		}
		case 58:
		{
			DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart6]  += SlotParam6( playerid, slot );
			SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflePart6" );
		}
		case 59:
		{
			DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart6]  += SlotParam6( playerid, slot );
			SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolPart6" );
		}
	}
	RemovePlayerItemExUsed( playerid, slot );
}

CountPlayerObjects( playerid )
{
	new counter = 0, playername[MAX_PLAYER_NAME];
	GetPlayerName( playerid, playername, MAX_PLAYER_NAME );
	for( new i = 0; i < sizeof(gCustomObj); i++ )
	{
		if( gCustomObj[i][cstSlotUsed] && strcmp( gCustomObj[i][cstObjOwner], playername, false ) == 0 )
			counter++;
	}
	return counter;
}

/*CreateCustomObject( playerid, model, Float:objX, Float:objY, Float:objZ, Float:rX = 0.0, Float:rY = 0.0, Float:rZ = 0.0 )
{
	new vw, interior, playername[MAX_PLAYER_NAME], string[128];
	vw = GetPlayerVirtualWorld(playerid);
	interior = GetPlayerInterior(playerid);
	GetPlayerName( playerid, playername, MAX_PLAYER_NAME );
	for( new i = 0; i < sizeof(gCustomObj); i++ )
	{
		if( !gCustomObj[i][cstSlotUsed] )
		{
			gCustomObj[i][cstObjID] = CreateDynamicObject( model, objX, objY, objZ, rX, rY, rZ, vw, interior );
			gCustomObj[i][cstObjModel] = model;
			gCustomObj[i][cstObjVW] = vw;
			gCustomObj[i][cstObjInt] = interior;
			gCustomObj[i][cstSlotUsed] = true;
			format( gCustomObj[i][cstObjOwner], MAX_PLAYER_NAME, "%s", playername );
			if(	!gCustomObjShow )
			{
				gCustomObj[i][cstText3dID] = Create3DTextLabel(" ", COLOR_LIGHTBLUE, objX, objY, objZ, 100.0, vw, 0);
				gCustomObj[i][cstText3dID2] = Create3DTextLabel(" ", COLOR_LIGHTBLUE, objX, objY, objZ-0.2, 100.0, vw, 0);
				gCustomObj[i][cstText3dID3] = Create3DTextLabel(" ", COLOR_LIGHTBLUE, objX, objY, objZ-0.4, 100.0, vw, 0);
				gCustomObj[i][cstText3dID4] = Create3DTextLabel(" ", COLOR_LIGHTBLUE, objX, objY, objZ+0.2, 100.0, vw, 0);
				gCustomObj[i][cstDscShow] = 0;
			}
			else
			{
				format(string, sizeof(string), "objID = %d | objModel = %d | objSlot = %d", gCustomObj[i][cstObjID], gCustomObj[i][cstObjModel], i );
				gCustomObj[i][cstText3dID] = Create3DTextLabel(string, COLOR_LIGHTBLUE, objX, objY, objZ, 100.0, vw, 0);
				format(string, sizeof(string), "objIX = %f | objY = %f | objZ = %f", objX, objY, objZ );
				gCustomObj[i][cstText3dID2] = Create3DTextLabel(string, COLOR_LIGHTBLUE, objX, objY, objZ-0.2, 100.0, vw, 0);
				format(string, sizeof(string), "objIRX = %f | objRY = %f | objRZ = %f", rX, rY, rZ );
				gCustomObj[i][cstText3dID3] = Create3DTextLabel(string, COLOR_LIGHTBLUE, objX, objY, objZ-0.4, 100.0, vw, 0);
				format(string, sizeof(string), "made by: %s", gCustomObj[i][cstObjOwner] );
				gCustomObj[i][cstText3dID4] = Create3DTextLabel(string, COLOR_LIGHTBLUE, objX, objY, objZ+0.2, 100.0, vw, 0);
				gCustomObj[i][cstDscShow] = 1;
			}
			SaveObjData(i);
			return 1;
		}
	}
	return 0;
}

RemoveCustomObject( objectID )
{
	for( new i = 0; i < sizeof(gCustomObj); i++ )
	{
		if( gCustomObj[i][cstSlotUsed] && gCustomObj[i][cstObjID] == objectID )
		{
			Delete3DTextLabel( gCustomObj[i][cstText3dID] );
			Delete3DTextLabel( gCustomObj[i][cstText3dID2] );
			Delete3DTextLabel( gCustomObj[i][cstText3dID3] );
			Delete3DTextLabel( gCustomObj[i][cstText3dID4] );
			DestroyDynamicObject( gCustomObj[i][cstObjID] );			
			gCustomObj[i][cstObjID] = 0;	
			gCustomObj[i][cstSlotUsed] = false;
			gCustomObj[i][cstObjModel] = 0;
			gCustomObj[i][cstObjVW] = 0;
			gCustomObj[i][cstObjInt] = 0;			
			gCustomObj[i][cstDscShow] = 0;
			strdel( gCustomObj[i][cstObjOwner], 0, MAX_PLAYER_NAME );
			SaveObjData(i);
			return 1;
		}
	}
	return 0;
}

MoveCustomObject( objectID, Float:mx, Float:my, Float:mz )
{
	for( new i = 0; i < sizeof(gCustomObj); i++ )
	{
		if( gCustomObj[i][cstSlotUsed] && gCustomObj[i][cstObjID] == objID )
		{
			vw = GetPlayerVirtualWorld(playerid);
			GetDynamicObjectPos( objID, ox, oy, oz );
			SetDynamicObjectPos( objID, ox+mx, oy+my, oz+mz );
			GetDynamicObjectRot( objID, rx, ry, rz );
			Delete3DTextLabel( gCustomObj[i][cstText3dID] );
			Delete3DTextLabel( gCustomObj[i][cstText3dID2] );
			Delete3DTextLabel( gCustomObj[i][cstText3dID3] );
			Delete3DTextLabel( gCustomObj[i][cstText3dID4] );
			if( gCustomObjShow )
			{
				format(string, sizeof(string), "objID = %d | objModel = %d | objSlot = %d", gCustomObj[i][cstObjID], gCustomObj[i][cstObjModel], i );
				gCustomObj[i][cstText3dID] = Create3DTextLabel(string, COLOR_LIGHTBLUE, ox+mx, oy+my, oz+mz, 100.0, vw, 0);
				format(string, sizeof(string), "objIX = %f | objY = %f | objZ = %f", ox+mx, oy+my, oz+mz );
				gCustomObj[i][cstText3dID2] = Create3DTextLabel(string, COLOR_LIGHTBLUE, ox+mx, oy+my, oz+mz-0.2, 100.0, vw, 0);
				format(string, sizeof(string), "objIRX = %f | objRY = %f | objRZ = %f", rx, ry, rz );
				gCustomObj[i][cstText3dID3] = Create3DTextLabel(string, COLOR_LIGHTBLUE, ox+mx, oy+my, oz+mz-0.4, 100.0, vw, 0);
				format(string, sizeof(string), "made by: %s", gCustomObj[i][cstObjOwner] );
				gCustomObj[i][cstText3dID4] = Create3DTextLabel(string, COLOR_LIGHTBLUE, ox+mx, oy+my, oz+mz+0.2, 100.0, vw, 0);
				gCustomObj[i][cstDscShow] = 1;
			}
			else
			{
				gCustomObj[i][cstText3dID] = Create3DTextLabel(" ", COLOR_LIGHTBLUE, ox+mx, oy+my, oz+mz, 100.0, vw, 0);
				gCustomObj[i][cstText3dID2] = Create3DTextLabel(" ", COLOR_LIGHTBLUE, ox+mx, oy+my, oz+mz-0.2, 100.0, vw, 0);
				gCustomObj[i][cstText3dID3] = Create3DTextLabel(" ", COLOR_LIGHTBLUE, ox+mx, oy+my, oz+mz-0.4, 100.0, vw, 0);
				gCustomObj[i][cstText3dID4] = Create3DTextLabel(" ", COLOR_LIGHTBLUE, ox+mx, oy+my, oz+mz+0.2, 100.0, vw, 0);
				gCustomObj[i][cstDscShow] = 0;
			}
			SaveObjData(i);
			GetPlayerName(playerid, string, sizeof(string));
			printf("[WARNING:] %s used /movobj for obj %d, slot %d", string, gCustomObj[i][cstObjID], i);
			return 1;
		}
	}
}*/

ResetBizData(bID, type)
{
	// type 0 - reset all data
	// type 1 - removes owner, etc, just prepare for next buyer
	
	DestroyDynamicPickup(Businesses[bID][PickupID]);
	
	strdel(Businesses[bID][Owner], 0, 128);
	format(Businesses[bID][Owner], 128, "None");
	strdel(Businesses[bID][BusinessName], 0, 128);
	format(Businesses[bID][BusinessName], 128, "Biznes");
	Businesses[bID][BUID] = random(99999);
	Businesses[bID][mFaction] = 0;
	Businesses[bID][mFactionTimeLeft] = 0; // how long to end of company contract
	// Businesses[bID][EnterX] = 0;
	// Businesses[bID][EnterY] = 0;
	// Businesses[bID][EnterZ] = 0;
	// Businesses[bID][EnterWorld] = 0;
	// Businesses[bID][EnterInterior] = 0;
	// Businesses[bID][EnterAngle] = 0;
	// Businesses[bID][ExitX] = 0;
	// Businesses[bID][ExitY] = 0;
	// Businesses[bID][ExitZ] = 0;
	// Businesses[bID][ExitInterior] = 0;
	// Businesses[bID][ExitAngle] = 0;
	Businesses[bID][Owned] = 0;
	Businesses[bID][Enterable] = 0;
	// Businesses[bID][BizPrice] = 0;
	Businesses[bID][EntranceCost] = 0;
	Businesses[bID][Till] = 0;
	Businesses[bID][Locked] = 0;
	// Businesses[bID][BizType] = 0;
	Businesses[bID][Products] = 0;
	Businesses[bID][VehicleSpawned] = 0;
	Businesses[bID][VehicleCount] = 0;
	Businesses[bID][MaxVehicles] = 6;
	Businesses[bID][VehicleOrderCount] = 0;
	Businesses[bID][SalesJob] = 0;
	Businesses[bID][W9MM] = 0;
	Businesses[bID][mW9MMIncomeTotal] = 0;
	Businesses[bID][mW9MMIncomeToday] = 0;
	Businesses[bID][W9MMSil] = 0;
	Businesses[bID][mW9MMSilIncomeTotal] = 0;
	Businesses[bID][mW9MMSilIncomeToday] = 0;
	Businesses[bID][WDesEagle] = 0;
	Businesses[bID][mWDesEagleIncomeTotal] = 0;
	Businesses[bID][mWDesEagleIncomeToday] = 0;
	Businesses[bID][WMicroSMG] = 0;
	Businesses[bID][mWMicroSMGIncomeTotal] = 0;
	Businesses[bID][mWMicroSMGIncomeToday] = 0;
	Businesses[bID][WMP5] = 0;
	Businesses[bID][mWMP5IncomeTotal] = 0;
	Businesses[bID][mWMP5IncomeToday] = 0;
	Businesses[bID][WTec9] = 0;
	Businesses[bID][mWTec9IncomeTotal] = 0;
	Businesses[bID][mWTec9IncomeToday] = 0;
	Businesses[bID][WShotgun] = 0;
	Businesses[bID][mWShotgunIncomeTotal] = 0;
	Businesses[bID][mWShotgunIncomeToday] = 0;
	Businesses[bID][WAK47] = 0;
	Businesses[bID][mWAK47IncomeTotal] = 0;
	Businesses[bID][mWAK47IncomeToday] = 0;
	Businesses[bID][WM4] = 0;
	Businesses[bID][mWM4IncomeTotal] = 0;
	Businesses[bID][mWM4IncomeToday] = 0;
	Businesses[bID][WRifle] = 0;
	Businesses[bID][mWRifleIncomeTotal] = 0;
	Businesses[bID][mWRifleIncomeToday] = 0;
	Businesses[bID][WSRifle] = 0;
	Businesses[bID][mWSRifleIncomeTotal] = 0;
	Businesses[bID][mWSRifleIncomeToday] = 0;
	Businesses[bID][W9MMAmmo] = 0;
	Businesses[bID][mW9MMAmmoIncomeTotal] = 0;
	Businesses[bID][mW9MMAmmoIncomeToday] = 0;
	Businesses[bID][W50AEAmmo] = 0;
	Businesses[bID][mW50AEAmmoIncomeTotal] = 0;
	Businesses[bID][mW50AEAmmoIncomeToday] = 0;
	Businesses[bID][WBuckshot] = 0;
	Businesses[bID][mWBuckshotIncomeTotal] = 0;
	Businesses[bID][mWBuckshotIncomeToday] = 0;
	Businesses[bID][W762MMAmmo] = 0;
	Businesses[bID][mW762MMAmmoIncomeTotal] = 0;
	Businesses[bID][mW762MMAmmoIncomeToday] = 0;
	Businesses[bID][W127MMAmmo] = 0;
	Businesses[bID][mW127MMAmmoIncomeTotal] = 0;
	Businesses[bID][mW127MMAmmoIncomeToday] = 0;
	Businesses[bID][BRadio1Bought] = 0; // Is radio bought
	Businesses[bID][BRadio1On] = 0; // Is radio ON
	Businesses[bID][BRadio1Ch] = 0; // Radio channell
	Businesses[bID][BRadio1Obj] = 0; // Radio object id
	Businesses[bID][BRadio1Vol] = 0; // Volume of radio
	Businesses[bID][BRadio1X] = 0; // radio x pos 
	Businesses[bID][BRadio1Y] = 0; // radio y pos
	Businesses[bID][BRadio1Z] = 0; // radio z pos
	Businesses[bID][BRadio1Angle] = 0;
	Businesses[bID][Product1] = 0;
	Businesses[bID][Product1type] = 0;
	Businesses[bID][Product1price] = 0;
	Businesses[bID][Product1count] = 0;
	Businesses[bID][Product1buy] = 0;
	Businesses[bID][Product1incomeTotal] = 0;
	Businesses[bID][Product1incomeToday] = 0;
	Businesses[bID][Product2] = 0;
	Businesses[bID][Product2type] = 0;
	Businesses[bID][Product2price] = 0;
	Businesses[bID][Product2count] = 0;
	Businesses[bID][Product2buy] = 0;
	Businesses[bID][Product2incomeTotal] = 0;
	Businesses[bID][Product2incomeToday] = 0;
	Businesses[bID][Product3] = 0;
	Businesses[bID][Product3type] = 0;
	Businesses[bID][Product3price] = 0;
	Businesses[bID][Product3count] = 0;
	Businesses[bID][Product3buy] = 0;
	Businesses[bID][Product3incomeTotal] = 0;
	Businesses[bID][Product3incomeToday] = 0;
	Businesses[bID][Product4] = 0;
	Businesses[bID][Product4type] = 0;
	Businesses[bID][Product4price] = 0;
	Businesses[bID][Product4count] = 0;
	Businesses[bID][Product4buy] = 0;
	Businesses[bID][Product4incomeTotal] = 0;
	Businesses[bID][Product4incomeToday] = 0;
	Businesses[bID][Product5] = 0;
	Businesses[bID][Product5type] = 0;
	Businesses[bID][Product5price] = 0;
	Businesses[bID][Product5count] = 0;
	Businesses[bID][Product5buy] = 0;
	Businesses[bID][Product5incomeTotal] = 0;
	Businesses[bID][Product5incomeToday] = 0;
	Businesses[bID][Product6] = 0;
	Businesses[bID][Product6type] = 0;
	Businesses[bID][Product6price] = 0;
	Businesses[bID][Product6count] = 0;
	Businesses[bID][Product6buy] = 0;
	Businesses[bID][Product6incomeTotal] = 0;
	Businesses[bID][Product6incomeToday] = 0;
	Businesses[bID][Product7] = 0;
	Businesses[bID][Product7type] = 0;
	Businesses[bID][Product7price] = 0;
	Businesses[bID][Product7count] = 0;
	Businesses[bID][Product7buy] = 0;
	Businesses[bID][Product7incomeTotal] = 0;
	Businesses[bID][Product7incomeToday] = 0;
	Businesses[bID][Product8] = 0;
	Businesses[bID][Product8type] = 0;
	Businesses[bID][Product8price] = 0;
	Businesses[bID][Product8count] = 0;
	Businesses[bID][Product8buy] = 0;
	Businesses[bID][Product8incomeTotal] = 0;
	Businesses[bID][Product8incomeToday] = 0;
	Businesses[bID][Product9] = 0;
	Businesses[bID][Product9type] = 0;
	Businesses[bID][Product9price] = 0;
	Businesses[bID][Product9count] = 0;
	Businesses[bID][Product9buy] = 0;
	Businesses[bID][Product9incomeTotal] = 0;
	Businesses[bID][Product9incomeToday] = 0;
	Businesses[bID][Product10] = 0;
	Businesses[bID][Product10type] = 0;
	Businesses[bID][Product10price] = 0;
	Businesses[bID][Product10count] = 0;
	Businesses[bID][Product10buy] = 0;
	Businesses[bID][Product10incomeTotal] = 0;
	Businesses[bID][Product10incomeToday] = 0;
	Businesses[bID][Product11Price] = 0;
	Businesses[bID][Product12Price] = 0;
	Businesses[bID][Product13Price] = 0;
	Businesses[bID][Product14Price] = 0;
	Businesses[bID][Product15Price] = 0;
	Businesses[bID][Product16Price] = 0;
	Businesses[bID][Product17Price] = 0;
	Businesses[bID][Product18Price] = 0;
	Businesses[bID][Product19Price] = 0;
	Businesses[bID][Product20Price] = 0;
	Businesses[bID][Product21Price] = 0;
	Businesses[bID][Product22Price] = 0;
	Businesses[bID][Product23Price] = 0;
	Businesses[bID][Product24Price] = 0;
	Businesses[bID][Product25Price] = 0;
	Businesses[bID][Product26Price] = 0;
	Businesses[bID][Product27Price] = 0;
	Businesses[bID][Product28Price] = 0;
	Businesses[bID][Product29Price] = 0;
	Businesses[bID][Product30Price] = 0;
	Businesses[bID][BConfiscated] = 0;
	// Businesses[bID][BPlaced] = 0;
	// Businesses[bID][BIntSet] = 0;
	// Businesses[bID][BInterior] = 0;
	Businesses[bID][BGov] = 0;
	// Businesses[bID][BShowIcon] = 0;
	Businesses[bID][mIncomeTotal] = 0;
	Businesses[bID][mIncomePhoneTotal] = 0;
	Businesses[bID][mIncomePhoneToday] = 0;
	Businesses[bID][mIncomeFuelPetrolToday] = 0;
	Businesses[bID][mIncomeFuelPetrolTotal] = 0;
	Businesses[bID][mIncomeFuelOilToday] = 0;
	Businesses[bID][mIncomeFuelOilTotal] = 0;
	Businesses[bID][mIncomeFuelGasToday] = 0;
	Businesses[bID][mIncomeFuelGasTotal] = 0;
	Businesses[bID][mIncomeVehicleTotal] = 0;
	Businesses[bID][mIncomeVehicleToday] = 0;
	Businesses[bID][mIncomeEntranceTotal] = 0;
	Businesses[bID][mIncomeEntranceToday] = 0;
	Businesses[bID][mAlarm] = 0;
	
	SaveBizData(bID, "Owner");
	SaveBizData(bID, "BusinessName");
	SaveBizData(bID, "UID");
	SaveBizData(bID, "Owner");
	SaveBizData(bID, "Faction");
	SaveBizData(bID, "FactionTimeLeft"); // how long to end of company contract
	// SaveBizData(bID, "EnterX");
	// SaveBizData(bID, "EnterY");
	// SaveBizData(bID, "EnterZ");
	// SaveBizData(bID, "EnterWorld");
	// SaveBizData(bID, "EnterInterior");
	// SaveBizData(bID, "EnterAngle");
	// SaveBizData(bID, "ExitX");
	// SaveBizData(bID, "ExitY");
	// SaveBizData(bID, "ExitZ");
	// SaveBizData(bID, "ExitInterior");
	// SaveBizData(bID, "ExitAngle");
	SaveBizData(bID, "Owned");
	SaveBizData(bID, "Enterable");
	// SaveBizData(bID, "BizPrice");
	SaveBizData(bID, "EntranceCost");
	SaveBizData(bID, "Till");
	SaveBizData(bID, "Locked");
	// SaveBizData(bID, "BizType");
	SaveBizData(bID, "Products");
	SaveBizData(bID, "VehicleSpawned");
	SaveBizData(bID, "VehicleCount");
	SaveBizData(bID, "MaxVehicles");
	SaveBizData(bID, "VehicleOrderCount");
	SaveBizData(bID, "SalesJob");
	SaveBizData(bID, "W9MM");
	SaveBizData(bID, "W9MMIncomeTotal");
	SaveBizData(bID, "W9MMIncomeToday");
	SaveBizData(bID, "W9MMSil");
	SaveBizData(bID, "W9MMSilIncomeTotal");
	SaveBizData(bID, "W9MMSilIncomeToday");
	SaveBizData(bID, "WDesEagle");
	SaveBizData(bID, "WDesEagleIncomeTotal");
	SaveBizData(bID, "WDesEagleIncomeToday");
	SaveBizData(bID, "WMicroSMG");
	SaveBizData(bID, "WMicroSMGIncomeTotal");
	SaveBizData(bID, "WMicroSMGIncomeToday");
	SaveBizData(bID, "WMP5");
	SaveBizData(bID, "WMP5IncomeTotal");
	SaveBizData(bID, "WMP5IncomeToday");
	SaveBizData(bID, "WTec9");
	SaveBizData(bID, "WTec9IncomeTotal");
	SaveBizData(bID, "WTec9IncomeToday");
	SaveBizData(bID, "WShotgun");
	SaveBizData(bID, "WShotgunIncomeTotal");
	SaveBizData(bID, "WShotgunIncomeToday");
	SaveBizData(bID, "WAK47");
	SaveBizData(bID, "WAK47IncomeTotal");
	SaveBizData(bID, "WAK47IncomeToday");
	SaveBizData(bID, "WM4");
	SaveBizData(bID, "WM4IncomeTotal");
	SaveBizData(bID, "WM4IncomeToday");
	SaveBizData(bID, "WRifle");
	SaveBizData(bID, "WRifleIncomeTotal");
	SaveBizData(bID, "WRifleIncomeToday");
	SaveBizData(bID, "WSRifle");
	SaveBizData(bID, "WSRifleIncomeTotal");
	SaveBizData(bID, "WSRifleIncomeToday");
	SaveBizData(bID, "W9MMAmmo");
	SaveBizData(bID, "W9MMAmmoIncomeTotal");
	SaveBizData(bID, "W9MMAmmoIncomeToday");
	SaveBizData(bID, "W50AEAmmo");
	SaveBizData(bID, "W50AEAmmoIncomeTotal");
	SaveBizData(bID, "W50AEAmmoIncomeToday");
	SaveBizData(bID, "WBuckshot");
	SaveBizData(bID, "WBuckshotIncomeTotal");
	SaveBizData(bID, "WBuckshotIncomeToday");
	SaveBizData(bID, "W762MMAmmo");
	SaveBizData(bID, "W762MMAmmoIncomeTotal");
	SaveBizData(bID, "W762MMAmmoIncomeToday");
	SaveBizData(bID, "W127MMAmmo");
	SaveBizData(bID, "W127MMAmmoIncomeTotal");
	SaveBizData(bID, "W127MMAmmoIncomeToday");
	SaveBizData(bID, "BRadio1Bought"); // Is radio bought
	SaveBizData(bID, "BRadio1On"); // Is radio ON
	SaveBizData(bID, "BRadio1Ch"); // Radio channell
	SaveBizData(bID, "BRadio1Vol"); // Volume of radio
	SaveBizData(bID, "BRadio1X"); // radio x pos 
	SaveBizData(bID, "BRadio1Y"); // radio y pos
	SaveBizData(bID, "BRadio1Z"); // radio z pos
	SaveBizData(bID, "BRadio1Angle");
	SaveBizData(bID, "Product1");
	SaveBizData(bID, "Product1type");
	SaveBizData(bID, "Product1price");
	SaveBizData(bID, "Product1count");
	SaveBizData(bID, "Product1buy");
	SaveBizData(bID, "Product1incomeTotal");
	SaveBizData(bID, "Product1incomeToday");
	SaveBizData(bID, "Product2");
	SaveBizData(bID, "Product2type");
	SaveBizData(bID, "Product2price");
	SaveBizData(bID, "Product2count");
	SaveBizData(bID, "Product2buy");
	SaveBizData(bID, "Product2incomeTotal");
	SaveBizData(bID, "Product2incomeToday");
	SaveBizData(bID, "Product3");
	SaveBizData(bID, "Product3type");
	SaveBizData(bID, "Product3price");
	SaveBizData(bID, "Product3count");
	SaveBizData(bID, "Product3buy");
	SaveBizData(bID, "Product3incomeTotal");
	SaveBizData(bID, "Product3incomeToday");
	SaveBizData(bID, "Product4");
	SaveBizData(bID, "Product4type");
	SaveBizData(bID, "Product4price");
	SaveBizData(bID, "Product4count");
	SaveBizData(bID, "Product4buy");
	SaveBizData(bID, "Product4incomeTotal");
	SaveBizData(bID, "Product4incomeToday");
	SaveBizData(bID, "Product5");
	SaveBizData(bID, "Product5type");
	SaveBizData(bID, "Product5price");
	SaveBizData(bID, "Product5count");
	SaveBizData(bID, "Product5buy");
	SaveBizData(bID, "Product5incomeTotal");
	SaveBizData(bID, "Product5incomeToday");
	SaveBizData(bID, "Product6");
	SaveBizData(bID, "Product6type");
	SaveBizData(bID, "Product6price");
	SaveBizData(bID, "Product6count");
	SaveBizData(bID, "Product6buy");
	SaveBizData(bID, "Product6incomeTotal");
	SaveBizData(bID, "Product6incomeToday");
	SaveBizData(bID, "Product7");
	SaveBizData(bID, "Product7type");
	SaveBizData(bID, "Product7price");
	SaveBizData(bID, "Product7count");
	SaveBizData(bID, "Product7buy");
	SaveBizData(bID, "Product7incomeTotal");
	SaveBizData(bID, "Product7incomeToday");
	SaveBizData(bID, "Product8");
	SaveBizData(bID, "Product8type");
	SaveBizData(bID, "Product8price");
	SaveBizData(bID, "Product8count");
	SaveBizData(bID, "Product8buy");
	SaveBizData(bID, "Product8incomeTotal");
	SaveBizData(bID, "Product8incomeToday");
	SaveBizData(bID, "Product9");
	SaveBizData(bID, "Product9type");
	SaveBizData(bID, "Product9price");
	SaveBizData(bID, "Product9count");
	SaveBizData(bID, "Product9buy");
	SaveBizData(bID, "Product9incomeTotal");
	SaveBizData(bID, "Product9incomeToday");
	SaveBizData(bID, "Product10");
	SaveBizData(bID, "Product10type");
	SaveBizData(bID, "Product10price");
	SaveBizData(bID, "Product10count");
	SaveBizData(bID, "Product10buy");
	SaveBizData(bID, "Product10incomeTotal");
	SaveBizData(bID, "Product10incomeToday");
	SaveBizData(bID, "Product11Price");
	SaveBizData(bID, "Product12Price");
	SaveBizData(bID, "Product13Price");
	SaveBizData(bID, "Product14Price");
	SaveBizData(bID, "Product15Price");
	SaveBizData(bID, "Product16Price");
	SaveBizData(bID, "Product17Price");
	SaveBizData(bID, "Product18Price");
	SaveBizData(bID, "Product19Price");
	SaveBizData(bID, "Product20Price");
	SaveBizData(bID, "Product21Price");
	SaveBizData(bID, "Product22Price");
	SaveBizData(bID, "Product23Price");
	SaveBizData(bID, "Product24Price");
	SaveBizData(bID, "Product25Price");
	SaveBizData(bID, "Product26Price");
	SaveBizData(bID, "Product27Price");
	SaveBizData(bID, "Product28Price");
	SaveBizData(bID, "Product29Price");
	SaveBizData(bID, "Product30Price");
	SaveBizData(bID, "Confiscated");
	// SaveBizData(bID, "BPlaced");
	// SaveBizData(bID, "BIntSet");
	// SaveBizData(bID, "BInterior");
	SaveBizData(bID, "Gov");
	// SaveBizData(bID, "BShowIcon");
	SaveBizData(bID, "IncomeTotal");
	SaveBizData(bID, "IncomePhoneTotal");
	SaveBizData(bID, "IncomePhoneToday");
	SaveBizData(bID, "IncomeFuelPetrolToday");
	SaveBizData(bID, "IncomeFuelPetrolTotal");
	SaveBizData(bID, "IncomeFuelOilToday");
	SaveBizData(bID, "IncomeFuelOilTotal");
	SaveBizData(bID, "IncomeFuelGasToday");
	SaveBizData(bID, "IncomeFuelGasTotal");
	SaveBizData(bID, "IncomeVehicleTotal");
	SaveBizData(bID, "IncomeVehicleToday");
	SaveBizData(bID, "IncomeEntranceTotal");
	SaveBizData(bID, "IncomeEntranceToday");
	SaveBizData(bID, "Alarm");
	
	if(type)
		Businesses[bID][PickupID] = CreateDynamicPickup(1272, 1, Businesses[bID][EnterX], Businesses[bID][EnterY], Businesses[bID][EnterZ]);
	else
	{
		Businesses[bID][EnterX] = 0.0;
		Businesses[bID][EnterY] = 0.0;
		Businesses[bID][EnterZ] = 0.0;
		Businesses[bID][EnterWorld] = 0;
		Businesses[bID][EnterInterior] = 0;
		Businesses[bID][EnterAngle] = 0.0;		
		Businesses[bID][Enterable] = 0;
		
		SaveBizData(bID, "EnterX");
		SaveBizData(bID, "EnterY");
		SaveBizData(bID, "EnterZ");
		SaveBizData(bID, "EnterWorld");
		SaveBizData(bID, "EnterInterior");
		SaveBizData(bID, "EnterAngle");
		SaveBizData(bID, "Enterable");
	}
	
	new businesstype[128], string[256];
	if(Businesses[bID][BizType] != 0)
	{
		if(Businesses[bID][BizType] == 1) { businesstype = "Restauracja"; }
		else if(Businesses[bID][BizType] == 2) { businesstype = "Siec komorkowa"; }
		else if(Businesses[bID][BizType] == 3) { businesstype = "Sklep 24/7"; }
		else if(Businesses[bID][BizType] == 4) { businesstype = "Sklep z bronia"; }
		else if(Businesses[bID][BizType] == 5) { businesstype = "Studio reklamowe"; }
		else if(Businesses[bID][BizType] == 6) { businesstype = "Sklep z ubraniami"; }
		else if(Businesses[bID][BizType] == 7) { businesstype = "Bar/Club"; }
		else if(Businesses[bID][BizType] == 8) { businesstype = "Studio nagraniowe"; }
		else if(Businesses[bID][BizType] == 9) { businesstype = "Studio"; }
		else if(Businesses[bID][BizType] == 10) { businesstype = "Salon samochodowy"; }
		else if(Businesses[bID][BizType] == 11) { businesstype = "Stacja paliw"; }
	}
	else { businesstype = "Nie ustawione"; }

	format(string, sizeof(string), "Ten biznes jest na sprzeda¿ !");
	UpdateDynamic3DTextLabelText(Business3DTextLabelA[bID], COLOR_LIGHTBLUE2, string);

	format(string, sizeof(string), "Numer Budynku: %d, Nazwa biznesu: %s, Typ biznesu: %s",bID,Businesses[bID][BusinessName],businesstype);
	UpdateDynamic3DTextLabelText(Business3DTextLabelB[bID], COLOR_LIGHTBLUE2, string);

	format(string, sizeof(string), "Cena: %d$",Businesses[bID][BizPrice]);
	UpdateDynamic3DTextLabelText(Business3DTextLabelC[bID], COLOR_LIGHTBLUE2, string);
}

ResetHouseData(hID, type = 1)
{
	// type 0 - reset all data
	// type 1 - removes owner, etc, just prepare for next buyer
	
	DestroyDynamicPickup(Houses[hID][PickupID]);
	
	strdel(Houses[hID][Description], 0, 128);
	format(Houses[hID][Owner], 128, "Brak");
	strdel(Houses[hID][HRenter], 0, MAX_PLAYER_NAME);
	format(Houses[hID][HRenter], MAX_PLAYER_NAME, "Brak");
	Houses[hID][HUID] = 0;
	Houses[hID][Owned] = 0;
	Houses[hID][Rentable] = 0;
	Houses[hID][RentCost] = 0;
	Houses[hID][Locked] = 0;
	Houses[hID][HConfiscated] = 0;
	Houses[hID][HouseType] = 0;
	
	SaveHouseData(hID, "Description");
	SaveHouseData(hID, "UID");
	SaveHouseData(hID, "Owner");
	SaveHouseData(hID, "Renter");
	SaveHouseData(hID, "Owned");
	SaveHouseData(hID, "Rentable");
	SaveHouseData(hID, "RentCost");
	SaveHouseData(hID, "Locked");
	SaveHouseData(hID, "Confiscated");
	SaveHouseData(hID, "HouseType");
	
	if(type)
		Houses[hID][PickupID] = CreateDynamicPickup(1273, 1, Houses[hID][EnterX], Houses[hID][EnterY], Houses[hID][EnterZ]);
	else
	{
		Houses[hID][EnterX] = 0.0;
		Houses[hID][EnterY] = 0.0;
		Houses[hID][EnterZ] = 0.0;
		Houses[hID][EnterWorld] = 0;
		Houses[hID][EnterInterior] = 0;
		Houses[hID][EnterAngle] = 0;	
		Houses[hID][HousePrice] = 0;
		Houses[hID][Money] = 0;	
		Houses[hID][HItem1] = 0;
		Houses[hID][HItem2] = 0;
		Houses[hID][HItem3] = 0;
		Houses[hID][HItem4] = 0;
		Houses[hID][HItem5] = 0;
		Houses[hID][HItem1type] = 0;
		Houses[hID][HItem2type] = 0;
		Houses[hID][HItem3type] = 0;
		Houses[hID][HItem4type] = 0;
		Houses[hID][HItem5type] = 0;
		if(Houses[hID][HRadio1Bought])
			DestroyDynamicObject(Businesses[hID][BRadio1Obj]);
		Houses[hID][HRadio1On] = 0;
		
		SaveHouseData(hID, "EnterX");
		SaveHouseData(hID, "EnterY");
		SaveHouseData(hID, "EnterZ");
		SaveHouseData(hID, "EnterWorld");
		SaveHouseData(hID, "EnterInterior");
		SaveHouseData(hID, "EnterAngle");
		SaveHouseData(hID, "HousePrice");
		SaveHouseData(hID, "Materials");
		SaveHouseData(hID, "Drugs");
		SaveHouseData(hID, "Money");
		SaveHouseData(hID, "HItem1");
		SaveHouseData(hID, "HItem2");
		SaveHouseData(hID, "HItem3");
		SaveHouseData(hID, "HItem4");
		SaveHouseData(hID, "HItem5");
		SaveHouseData(hID, "HItem1type");
		SaveHouseData(hID, "HItem2type");
		SaveHouseData(hID, "HItem3type");
		SaveHouseData(hID, "HItem4type");
		SaveHouseData(hID, "HItem5type");
	}
}

stock isInWheelChangePoint(playerid)
{
	if(PlayerToPoint(2.0, playerid, gWheelChangePos[pos1X], gWheelChangePos[pos1Y], gWheelChangePos[pos1Z]) ||
		PlayerToPoint(2.0, playerid, gWheelChangePos[pos2X], gWheelChangePos[pos2Y], gWheelChangePos[pos2Z]) ||
		PlayerToPoint(2.0, playerid, gWheelChangePos[pos3X], gWheelChangePos[pos3Y], gWheelChangePos[pos3Z]) ||
		PlayerToPoint(2.0, playerid, gWheelChangePos[pos4X], gWheelChangePos[pos4Y], gWheelChangePos[pos4Z]) ||
		PlayerToPoint(2.0, playerid, gWheelChangePos[pos5X], gWheelChangePos[pos5Y], gWheelChangePos[pos5Z]) ||
		PlayerToPoint(2.0, playerid, gWheelChangePos[pos6X], gWheelChangePos[pos6Y], gWheelChangePos[pos6Z]) ||
		PlayerToPoint(2.0, playerid, gWheelChangePos[pos7X], gWheelChangePos[pos7Y], gWheelChangePos[pos7Z]) ||
		PlayerToPoint(2.0, playerid, gWheelChangePos[pos8X], gWheelChangePos[pos8Y], gWheelChangePos[pos8Z]))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

stock ShowBizFProductList(playerid, bizid)
{
	new string[512];
	format(string, sizeof(string), FOOD_PRODUCT_LIST,
		ItemName(Businesses[bizid][Product1type], Businesses[bizid][Product1]),
		Businesses[bizid][Product1price],
		Businesses[bizid][Product1count],
		ItemName(Businesses[bizid][Product2type], Businesses[bizid][Product2]),
		Businesses[bizid][Product2price],
		Businesses[bizid][Product2count],
		ItemName(Businesses[bizid][Product3type], Businesses[bizid][Product3]),
		Businesses[bizid][Product3price],
		Businesses[bizid][Product3count],
		ItemName(Businesses[bizid][Product4type], Businesses[bizid][Product4]),
		Businesses[bizid][Product4price],
		Businesses[bizid][Product4count],
		ItemName(Businesses[bizid][Product5type], Businesses[bizid][Product5]),
		Businesses[bizid][Product5price],
		Businesses[bizid][Product5count]
	);
	if(strcmp(gPlayerData[playerid][pName], Businesses[bizid][Owner], false) == 0)
		ShowPlayerDialog(playerid, DIALOG_FBUY_1, DIALOG_STYLE_LIST, "Restauracja", string, "Wybierz", "Zamknij");
	else
		ShowPlayerDialog(playerid, DIALOG_FBUY_1, DIALOG_STYLE_LIST, "Restauracja", string, "Jedz/pij", "Zamknij");		
}

stock ReloadBizText(bizid)
{
	new string[128];
	DestroyDynamic3DTextLabel(Business3DTextLabelA[bizid]);
	DestroyDynamic3DTextLabel(Business3DTextLabelB[bizid]);
	DestroyDynamic3DTextLabel(Business3DTextLabelC[bizid]);
	
	new businesstype[128];
	if(Businesses[bizid][BizType] != 0)
	{
		if(Businesses[bizid][BizType] == 1) { businesstype = "Restauracja"; }
		else if(Businesses[bizid][BizType] == 2) { businesstype = "Siec komorkowa"; }
		else if(Businesses[bizid][BizType] == 3) { businesstype = "Sklep 24/7"; }
		else if(Businesses[bizid][BizType] == 4) { businesstype = "Sklep z bronia"; }
		else if(Businesses[bizid][BizType] == 5) { businesstype = "Studio reklamowe"; }
		else if(Businesses[bizid][BizType] == 6) { businesstype = "Sklep z ubraniami"; }
		else if(Businesses[bizid][BizType] == 7) { businesstype = "Bar/Club"; }
		else if(Businesses[bizid][BizType] == 8) { businesstype = "Studio nagraniowe"; }
		else if(Businesses[bizid][BizType] == 9) { businesstype = "Studio"; }
		else if(Businesses[bizid][BizType] == 10) { businesstype = "Salon samochodowy"; }
		else if(Businesses[bizid][BizType] == 11) { businesstype = "Stacja paliw"; }
	}
	else { businesstype = "Nie ustawione"; }
	if(Businesses[bizid][Owned] == 0)
	{
		format(string, sizeof(string), "Ten biznes jest na sprzeda¿!");
		Business3DTextLabelA[bizid] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE2, Businesses[bizid][EnterX], Businesses[bizid][EnterY], Businesses[bizid][EnterZ]+1.0, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

		format(string, sizeof(string), "Numer Budynku: %d, Nazwa biznesu: %s, Typ biznesu: %s", bizid, Businesses[bizid][BusinessName],businesstype);
		Business3DTextLabelB[bizid] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE2, Businesses[bizid][EnterX], Businesses[bizid][EnterY], Businesses[bizid][EnterZ]+0.5, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
		
		format(string, sizeof(string), "Cena: %d$",Businesses[bizid][BizPrice]);
		Business3DTextLabelC[bizid] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE2, Businesses[bizid][EnterX], Businesses[bizid][EnterY], Businesses[bizid][EnterZ], 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
	}
	else
	{
		format(string, sizeof(string), "Nazwa biznesu: %s, Typ biznesu: %s", Businesses[bizid][BusinessName], businesstype);
		Business3DTextLabelA[bizid] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE2, Businesses[bizid][EnterX], Businesses[bizid][EnterY], Businesses[bizid][EnterZ]+1.0, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

		format(string, sizeof(string), "Numer Budynku: %d, W³aœciciel: %s", bizid, GetRealName(Businesses[bizid][Owner]));
		Business3DTextLabelB[bizid] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE2, Businesses[bizid][EnterX], Businesses[bizid][EnterY], Businesses[bizid][EnterZ]+0.5, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

		format(string, sizeof(string), "Wejœciówka: %d$",Businesses[bizid][EntranceCost]);
		Business3DTextLabelC[bizid] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE2, Businesses[bizid][EnterX], Businesses[bizid][EnterY], Businesses[bizid][EnterZ], 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
	}
}

stock ShowPoliceComputer(playerid)
{
	new string[128];
	gListItem[playerid] = -1;
	format(string, sizeof(string), "SprawdŸ pojazd\nSprawdŸ podejrzanego\nNadaj punkty karne\nDodaj wpis do kartoteki gracza");
	ShowPlayerDialog(playerid, DIALOG_POLICE_COMPUTER_1, DIALOG_STYLE_LIST, "Komputer policyjny", string, "Wybierz", "Zamknij");
}

stock HideObjectsDescriptions(playerid)
{
	for(new i = 0; i < sizeof(gCustomObj); i++)
	{
		if(gCustomObj[i][cstSlotUsed] && strcmp(gCustomObj[i][cstObjOwner], gPlayerData[playerid][pName], false) == 0)
		{
			if(gCustomObjShowed[playerid][i])
			{
				DestroyDynamic3DTextLabel(gCustomObjTextID1[playerid][i]);
				DestroyDynamic3DTextLabel(gCustomObjTextID2[playerid][i]);
				DestroyDynamic3DTextLabel(gCustomObjTextID3[playerid][i]);
				DestroyDynamic3DTextLabel(gCustomObjTextID4[playerid][i]);
				gCustomObjShowed[playerid][i] = 0;
			}
		}
	}
}

stock FirstBuy(playerid)
{
	if(!gPlayerData[playerid][pFirstBuy])
	{
		new string[128];
		// AddExpPoint(playerid);
		format(string, sizeof(string), "[INFO:] Dokona³eœ swojego pierwszego zakupu w 24/7 ! Otrzymujesz dodatkowy punkt doœwiadczenia");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
		gPlayerData[playerid][pFirstBuy] = 1;
		SavePlayerData(playerid, "FirstBuy");
	}
}

stock ResetFactionData(fID)
{
	DynamicFactions[fID][IsEnabled] = 0;
	format(DynamicFactions[fID][Name], 50, "Brak");
	DynamicFactions[fID][m_fX] = 0.0;
	DynamicFactions[fID][m_fY] = 0.0;
	DynamicFactions[fID][m_fZ] = 0.0;
	DynamicFactions[fID][fBank] = 0;
	DynamicFactions[fID][fSkin1] = 1;
	DynamicFactions[fID][fSkin2] = 1;
	DynamicFactions[fID][fSkin3] = 1;
	DynamicFactions[fID][fSkin4] = 1;
	DynamicFactions[fID][fSkin5] = 1;
	DynamicFactions[fID][fSkin6] = 1;
	DynamicFactions[fID][fSkin7] = 1;
	DynamicFactions[fID][fSkin8] = 1;
	DynamicFactions[fID][fSkin9] = 1;
	DynamicFactions[fID][fSkin10] = 1;
	format(DynamicFactions[fID][fRank1], 35, "Ranga1");
	format(DynamicFactions[fID][fRank2], 35, "Ranga2");
	format(DynamicFactions[fID][fRank3], 35, "Ranga3");
	format(DynamicFactions[fID][fRank4], 35, "Ranga4");
	format(DynamicFactions[fID][fRank5], 35, "Ranga5");
	format(DynamicFactions[fID][fRank6], 35, "Ranga6");
	format(DynamicFactions[fID][fRank7], 35, "Ranga7");
	format(DynamicFactions[fID][fRank8], 35, "Ranga8");
	format(DynamicFactions[fID][fRank9], 35, "Ranga9");
	format(DynamicFactions[fID][fRank10], 35, "Ranga10");
	DynamicFactions[fID][fJoinRank] = 2;
	DynamicFactions[fID][fUseSkins] = 0;
	DynamicFactions[fID][fType] = 0;
	DynamicFactions[fID][fRankAmount] = 2;
	DynamicFactions[fID][fColor] = 0;
	DynamicFactions[fID][fMaxCars] = 2;
	DynamicFactions[fID][fCarsCount] = 0;
	DynamicFactions[fID][fXDuty] = 0.0;
	DynamicFactions[fID][fYDuty] = 0.0;
	DynamicFactions[fID][fZDuty] = 0.0;
	DynamicFactions[fID][fWorldDuty] = 0;
	DynamicFactions[fID][fInteriorDuty] = 0;
	DynamicFactions[fID][fXDuty2] = 0.0;
	DynamicFactions[fID][fYDuty2] = 0.0;
	DynamicFactions[fID][fZDuty2] = 0.0;
	DynamicFactions[fID][fWorldDuty2] = 0;
	DynamicFactions[fID][fInteriorDuty2] = 0;
	DynamicFactions[fID][fTaxiKMCost] = 0;
	DynamicFactions[fID][fTaxiEnterCost] = 0;
	DynamicFactions[fID][fGun1Rank1] = 0;
	DynamicFactions[fID][fGun1Rank2] = 0;
	DynamicFactions[fID][fGun1Rank3] = 0;
	DynamicFactions[fID][fGun1Rank4] = 0;
	DynamicFactions[fID][fGun1Rank5] = 0;
	DynamicFactions[fID][fGun1Rank6] = 0;
	DynamicFactions[fID][fGun1Rank7] = 0;
	DynamicFactions[fID][fGun1Rank8] = 0;
	DynamicFactions[fID][fGun1Rank9] = 0;
	DynamicFactions[fID][fGun1Rank10] = 0;
	DynamicFactions[fID][fGun2Rank1] = 0;
	DynamicFactions[fID][fGun2Rank2] = 0;
	DynamicFactions[fID][fGun2Rank3] = 0;
	DynamicFactions[fID][fGun2Rank4] = 0;
	DynamicFactions[fID][fGun2Rank5] = 0;
	DynamicFactions[fID][fGun2Rank6] = 0;
	DynamicFactions[fID][fGun2Rank7] = 0;
	DynamicFactions[fID][fGun2Rank8] = 0;
	DynamicFactions[fID][fGun2Rank9] = 0;
	DynamicFactions[fID][fGun2Rank10] = 0;
	DynamicFactions[fID][fGun3Rank1] = 0;
	DynamicFactions[fID][fGun3Rank2] = 0;
	DynamicFactions[fID][fGun3Rank3] = 0;
	DynamicFactions[fID][fGun3Rank4] = 0;
	DynamicFactions[fID][fGun3Rank5] = 0;
	DynamicFactions[fID][fGun3Rank6] = 0;
	DynamicFactions[fID][fGun3Rank7] = 0;
	DynamicFactions[fID][fGun3Rank8] = 0;
	DynamicFactions[fID][fGun3Rank9] = 0;
	DynamicFactions[fID][fGun3Rank10] = 0;
	DynamicFactions[fID][fAmmo1Rank1] = 0;
	DynamicFactions[fID][fAmmo1Rank2] = 0;
	DynamicFactions[fID][fAmmo1Rank3] = 0;
	DynamicFactions[fID][fAmmo1Rank4] = 0;
	DynamicFactions[fID][fAmmo1Rank5] = 0;
	DynamicFactions[fID][fAmmo1Rank6] = 0;
	DynamicFactions[fID][fAmmo1Rank7] = 0;
	DynamicFactions[fID][fAmmo1Rank8] = 0;
	DynamicFactions[fID][fAmmo1Rank9] = 0;
	DynamicFactions[fID][fAmmo1Rank10] = 0;
	DynamicFactions[fID][fAmmo2Rank1] = 0;
	DynamicFactions[fID][fAmmo2Rank2] = 0;
	DynamicFactions[fID][fAmmo2Rank3] = 0;
	DynamicFactions[fID][fAmmo2Rank4] = 0;
	DynamicFactions[fID][fAmmo2Rank5] = 0;
	DynamicFactions[fID][fAmmo2Rank6] = 0;
	DynamicFactions[fID][fAmmo2Rank7] = 0;
	DynamicFactions[fID][fAmmo2Rank8] = 0;
	DynamicFactions[fID][fAmmo2Rank9] = 0;
	DynamicFactions[fID][fAmmo2Rank10] = 0;
	DynamicFactions[fID][fAmmo3Rank1] = 0;
	DynamicFactions[fID][fAmmo3Rank2] = 0;
	DynamicFactions[fID][fAmmo3Rank3] = 0;
	DynamicFactions[fID][fAmmo3Rank4] = 0;
	DynamicFactions[fID][fAmmo3Rank5] = 0;
	DynamicFactions[fID][fAmmo3Rank6] = 0;
	DynamicFactions[fID][fAmmo3Rank7] = 0;
	DynamicFactions[fID][fAmmo3Rank8] = 0;
	DynamicFactions[fID][fAmmo3Rank9] = 0;
	DynamicFactions[fID][fAmmo3Rank10] = 0;
	DynamicFactions[fID][WFactoryEnabled] = 0;
	DynamicFactions[fID][WFactoryBurning] = 1;
	DestroyFactory(fID, fID);
	SaveFData(fID, "Name");
	SaveFData(fID, "IsEnabled");
	SaveFData(fID, "X");
	SaveFData(fID, "Y");
	SaveFData(fID, "Z");
	SaveFData(fID, "Bank");
	SaveFData(fID, "Rank1");
	SaveFData(fID, "Rank2");
	SaveFData(fID, "Rank3");
	SaveFData(fID, "Rank4");
	SaveFData(fID, "Rank5");
	SaveFData(fID, "Rank6");
	SaveFData(fID, "Rank7");
	SaveFData(fID, "Rank8");
	SaveFData(fID, "Rank9");
	SaveFData(fID, "Rank10");
	SaveFData(fID, "Skin1");
	SaveFData(fID, "Skin2");
	SaveFData(fID, "Skin3");
	SaveFData(fID, "Skin4");
	SaveFData(fID, "Skin5");
	SaveFData(fID, "Skin6");
	SaveFData(fID, "Skin7");
	SaveFData(fID, "Skin8");
	SaveFData(fID, "Skin9");
	SaveFData(fID, "Skin10");
	SaveFData(fID, "JoinRank");
	SaveFData(fID, "UseSkins");
	SaveFData(fID, "Type");
	SaveFData(fID, "RankAmount");
	SaveFData(fID, "Color");
	SaveFData(fID, "UseColor");
	SaveFData(fID, "MaxCars");
	SaveFData(fID, "CarsCount");
	SaveFData(fID, "XDuty");
	SaveFData(fID, "YDuty");
	SaveFData(fID, "ZDuty");
	SaveFData(fID, "WorldDuty");
	SaveFData(fID, "InteriorDuty");
	SaveFData(fID, "XDuty2");
	SaveFData(fID, "YDuty2");
	SaveFData(fID, "ZDuty2");
	SaveFData(fID, "WorldDuty2");
	SaveFData(fID, "InteriorDuty2");
	SaveFData(fID, "TaxiKMCost");
	SaveFData(fID, "TaxiEnterCost");
	SaveFData(fID, "Gun1Rank1");
	SaveFData(fID, "Gun1Rank2");
	SaveFData(fID, "Gun1Rank3");
	SaveFData(fID, "Gun1Rank4");
	SaveFData(fID, "Gun1Rank5");
	SaveFData(fID, "Gun1Rank6");
	SaveFData(fID, "Gun1Rank7");
	SaveFData(fID, "Gun1Rank8");
	SaveFData(fID, "Gun1Rank9");
	SaveFData(fID, "Gun1Rank10");
	SaveFData(fID, "Gun2Rank1");
	SaveFData(fID, "Gun2Rank2");
	SaveFData(fID, "Gun2Rank3");
	SaveFData(fID, "Gun2Rank4");
	SaveFData(fID, "Gun2Rank5");
	SaveFData(fID, "Gun2Rank6");
	SaveFData(fID, "Gun2Rank7");
	SaveFData(fID, "Gun2Rank8");
	SaveFData(fID, "Gun2Rank9");
	SaveFData(fID, "Gun2Rank10");
	SaveFData(fID, "Gun3Rank1");
	SaveFData(fID, "Gun3Rank2");
	SaveFData(fID, "Gun3Rank3");
	SaveFData(fID, "Gun3Rank4");
	SaveFData(fID, "Gun3Rank5");
	SaveFData(fID, "Gun3Rank6");
	SaveFData(fID, "Gun3Rank7");
	SaveFData(fID, "Gun3Rank8");
	SaveFData(fID, "Gun3Rank9");
	SaveFData(fID, "Gun3Rank10");
	SaveFData(fID, "Ammo1Rank1");
	SaveFData(fID, "Ammo1Rank2");
	SaveFData(fID, "Ammo1Rank3");
	SaveFData(fID, "Ammo1Rank4");
	SaveFData(fID, "Ammo1Rank5");
	SaveFData(fID, "Ammo1Rank6");
	SaveFData(fID, "Ammo1Rank7");
	SaveFData(fID, "Ammo1Rank8");
	SaveFData(fID, "Ammo1Rank9");
	SaveFData(fID, "Ammo1Rank10");
	SaveFData(fID, "Ammo2Rank1");
	SaveFData(fID, "Ammo2Rank2");
	SaveFData(fID, "Ammo2Rank3");
	SaveFData(fID, "Ammo2Rank4");
	SaveFData(fID, "Ammo2Rank5");
	SaveFData(fID, "Ammo2Rank6");
	SaveFData(fID, "Ammo2Rank7");
	SaveFData(fID, "Ammo2Rank8");
	SaveFData(fID, "Ammo2Rank9");
	SaveFData(fID, "Ammo2Rank10");
	SaveFData(fID, "Ammo3Rank1");
	SaveFData(fID, "Ammo3Rank2");
	SaveFData(fID, "Ammo3Rank3");
	SaveFData(fID, "Ammo3Rank4");
	SaveFData(fID, "Ammo3Rank5");
	SaveFData(fID, "Ammo3Rank6");
	SaveFData(fID, "Ammo3Rank7");
	SaveFData(fID, "Ammo3Rank8");
	SaveFData(fID, "Ammo3Rank9");
	SaveFData(fID, "Ammo3Rank10");
	SaveFData(fID, "WFactoryEnabled");
	SaveFData(fID, "WFactoryBurning");
}

stock ClearDescObj(playerid)
{
	for(new i = 0; i < sizeof(gCustomObj); i++)
	{
		if(gCustomObj[i][cstSlotUsed])
		{
			if(gCustomObjShowed[playerid][i])
			{
				DestroyDynamic3DTextLabel(gCustomObjTextID1[playerid][i]);
				DestroyDynamic3DTextLabel(gCustomObjTextID2[playerid][i]);
				DestroyDynamic3DTextLabel(gCustomObjTextID3[playerid][i]);
				DestroyDynamic3DTextLabel(gCustomObjTextID4[playerid][i]);
				gCustomObjShowed[playerid][i] = 0;
			}
		}
	}
}

stock SendPoliceCbMessage(playerid, type = 0)
{
	new location[MAX_ZONE_NAME];
	GetPlayer2DZone(playerid, location, MAX_ZONE_NAME);
	new string[128];
	if(type == 0)
		format(string, sizeof(string), "Otrzymano nowe zg³oszenie - zosta³ uaktywniony alarm samochodowy przy %s", location);
	else if(type == 1)
		format(string, sizeof(string), "Otrzymano nowe zg³oszenie - zosta³ uaktywniony alarm w domu przy %s", location);
	else if(type == 2)
		format(string, sizeof(string), "Otrzymano nowe zg³oszenie - zosta³ uaktywniony alarm w biznesie przy %s", location);
	SendCBMessage(41, string);
	
	if(!DynamicFactions[FACTIONID_POLICE][fNotification1])
	{
		DynamicFactions[FACTIONID_POLICE][fNotification1] = 5;
		DynamicFactions[FACTIONID_POLICE][fNotification1ID] = playerid;
	}
	else if(!DynamicFactions[FACTIONID_POLICE][fNotification2])
	{
		DynamicFactions[FACTIONID_POLICE][fNotification2] = 5;
		DynamicFactions[FACTIONID_POLICE][fNotification2ID] = playerid;
	}
	else if(!DynamicFactions[FACTIONID_POLICE][fNotification3])
	{
		DynamicFactions[FACTIONID_POLICE][fNotification3] = 5;
		DynamicFactions[FACTIONID_POLICE][fNotification3ID] = playerid;
	}
	else if(!DynamicFactions[FACTIONID_POLICE][fNotification4])
	{
		DynamicFactions[FACTIONID_POLICE][fNotification4] = 5;
		DynamicFactions[FACTIONID_POLICE][fNotification4ID] = playerid;
	}
	else if(!DynamicFactions[FACTIONID_POLICE][fNotification5])
	{
		DynamicFactions[FACTIONID_POLICE][fNotification5] = 5;
		DynamicFactions[FACTIONID_POLICE][fNotification5ID] = playerid;
	}
	
	GetPlayerPos(playerid, gPlayerData[playerid][pCrashX], gPlayerData[playerid][pCrashY], gPlayerData[playerid][pCrashZ]);
	
	new slot[MAX_PLAYER_ITEM_SLOT];
	foreach(Player, i)
	{
		if(gPlayerLogged[i])
		{
			if(gPlayerData[i][pFaction] == FACTIONID_POLICE)
			{								
				PHaveItemEx(i, 3, 12, slot);
				for(new j = 0; j < MAX_PLAYER_ITEM_SLOT; j++)
				{
					if(slot[j] && SlotParam1(i, j+1))
					{
						if(gPlayerVars[playerid][mAtHouseID] != -1)
							SetPlayerCheckpoint(i, Houses[gPlayerVars[playerid][mAtHouseID]][EnterX], Houses[gPlayerVars[playerid][mAtHouseID]][EnterY], Houses[gPlayerVars[playerid][mAtHouseID]][EnterZ], 10.0);
						else if(gPlayerVars[playerid][mAtBuildingID] != -1)
							SetPlayerCheckpoint(i, Building[gPlayerVars[playerid][mAtBuildingID]][EnterX], Building[gPlayerVars[playerid][mAtBuildingID]][EnterY], Building[gPlayerVars[playerid][mAtBuildingID]][EnterZ], 10.0);
						else if(gPlayerVars[playerid][mAtBizID] != -1)
							SetPlayerCheckpoint(i, Businesses[gPlayerVars[playerid][mAtBizID]][EnterX], Businesses[gPlayerVars[playerid][mAtBizID]][EnterY], Businesses[gPlayerVars[playerid][mAtBizID]][EnterZ], 10.0);
						else
							SetPlayerCheckpoint(i, gPlayerData[playerid][pCrashX], gPlayerData[playerid][pCrashY], gPlayerData[playerid][pCrashZ], 10.0);
						defer ClearCheckpointsForPlayer(i);
						break;
					}
				}
			}
		}
	}
}

GrowthWeed(id)
{
	switch(gWeed[id][mPhase])
	{
		case 1:
		{
			SaveWeedData(id, "Pos");
			MoveDynamicObject(gWeed[id][mObjId], gWeed[id][mPosX], gWeed[id][mPosY], gWeed[id][mPosZ]+0.7, 0.017);
			gWeed[id][mPosZ] += 0.7;
			gWeed[id][mPhase] = 2;
			SaveWeedData(id, "Phase");
		}
		case 2:
		{
			SaveWeedData(id, "Pos");
			MoveDynamicObject(gWeed[id][mObjId], gWeed[id][mPosX], gWeed[id][mPosY], gWeed[id][mPosZ]+0.7, 0.017);
			gWeed[id][mPosZ] += 0.7;
			gWeed[id][mPhase] = 3;
			SaveWeedData(id, "Phase");
		}
		case 3:
		{
			SaveWeedData(id, "Pos");
			MoveDynamicObject(gWeed[id][mObjId], gWeed[id][mPosX], gWeed[id][mPosY], gWeed[id][mPosZ]+0.7, 0.017);
			gWeed[id][mPosZ] += 0.7;
			gWeed[id][mPhase] = 4;
			SaveWeedData(id, "Phase");
		}
	}
}

SelectTestQuestion(playerid)
{
	new string[512];
	for(new i = 0; i < 40; i++)
	{
		format(string, sizeof(string), "%s\nPytanie %d", string, i+1);
	}
	ShowPlayerDialog(playerid, DIALOG_DRIVER_BOOK, DIALOG_STYLE_LIST, "Wybierz pytanie", string, "Wybierz", "WyjdŸ");
}

IsAtBank(playerid)
{
	if(PlayerToPoint(2.0, playerid, BankPosition[X], BankPosition[Y], BankPosition[Z])
		|| PlayerToPoint(2.0, playerid, BankPosition2[X], BankPosition2[Y], BankPosition2[Z])
		|| PlayerToPoint(2.0, playerid, BankPosition3[X], BankPosition3[Y], BankPosition3[Z])
		|| PlayerToPoint(2.0, playerid, BankPosition4[X], BankPosition4[Y], BankPosition4[Z])
		|| PlayerToPoint(2.0, playerid, BankPosition5[X], BankPosition5[Y], BankPosition5[Z])
		|| PlayerToPoint(2.0, playerid, BankPosition6[X], BankPosition6[Y], BankPosition6[Z])
		|| PlayerToPoint(2.0, playerid, BankPosition7[X], BankPosition7[Y], BankPosition7[Z])
		|| PlayerToPoint(2.0, playerid, BankPosition8[X], BankPosition8[Y], BankPosition8[Z])
		|| PlayerToPoint(2.0, playerid, BankPosition9[X], BankPosition9[Y], BankPosition9[Z])
		|| PlayerToPoint(2.0, playerid, BankPosition10[X], BankPosition10[Y], BankPosition10[Z])
		|| PlayerToPoint(2.0, playerid, BankPosition11[X], BankPosition11[Y], BankPosition11[Z])
	)
		return 1;
	else
		return 0;
}