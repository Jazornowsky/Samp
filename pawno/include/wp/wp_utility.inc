#include <wp\utils\wp_vehutils>
#include <wp\utils\wp_logutils>
#include <wp\utils\wp_chatutils>

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

Delay:GetPlayerSpeed[1000, i](playerid) //MPH
{
	new Float:x, Float:y, Float:z, string[128];
	new Float:speed_x, Float:speed_y, Float:speed_z, Float:final_speed, final_speed_int;
	new key, up, dwn;
	if( GetPlayerWeapon(playerid) == Speedgun )
	{
		for( new i = 0; i < sizeof(gVehData); i++ )
		{
			GetVehiclePos( i+1, x, y, z);
			if(	IsPlayerAimingAt(playerid, x, y, z, 3.0) )
			{
				GetVehicleVelocity( i+1, speed_x, speed_y, speed_z);
				final_speed = floatsqroot(((speed_x*speed_x)+(speed_y*speed_y))+(speed_z*speed_z))*136.666667; // 136.666667 = kmph  // 85.4166672= mph
				final_speed_int = floatround(final_speed,floatround_round);
				format(string,sizeof(string),"%i KM/H", final_speed_int);
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
		GetPlayerSpeed(playerid);		
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

AddExpPoint(playerid)
{
	new string[128];
	gPlayerData[playerid][pExp]++;
	SavePlayerData(playerid, "Exp");
	if(gPlayerData[playerid][pExp] >= (gPlayerData[playerid][pLevel]+1)*levelexp)
	{
		gPlayerData[playerid][pLevel]++;
		gPlayerData[playerid][pExp] = 0;
		SavePlayerData(playerid, "Level");

		format(string, sizeof(string), "[INFO:] Zdoby³eœ nowy poziom postaci ! - %d", gPlayerData[playerid][pLevel]);
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	}
	else
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Otrzymujesz 1pkt doœwiadczenia !");
	}
	return 1;
}

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
		for(new i = 0; i < CUSTOM_MAX_PLAYERS; i++)
		{
			if(IsPlayerConnected(i))
			{
				if(!BigEar[i])
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
				else
				{
					SendClientMessage(i, col1, string);
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
	SavePlayerData(playerid, "Cash");

	ResetMoneyBar(playerid);//Resets the money in the original moneybar, Do not remove!
	UpdateMoneyBar(playerid,gPlayerData[playerid][pCash]);//Sets the money in the moneybar to the serverside cash, Do not remove!
	return gPlayerData[playerid][pCash];
}

stock SetPlayerCash(playerid, money)
{
	gPlayerData[playerid][pCash] = money;
	SavePlayerData(playerid, "Cash");

	ResetMoneyBar(playerid);//Resets the money in the original moneybar, Do not remove!
	UpdateMoneyBar(playerid,gPlayerData[playerid][pCash]);//Sets the money in the moneybar to the serverside cash, Do not remove
	return gPlayerData[playerid][pCash];
}

stock ResetPlayerCash(playerid)
{
	gPlayerData[playerid][pCash] = 0;
	SavePlayerData(playerid, "Cash");
	
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
			new phonenetwork[128];
			new donatortext[128];
			new Float:hp;
			GetPlayerHealth(targetid,hp);
			new drugs = gPlayerData[targetid][pDrugs];
			new bizkey = gPlayerData[targetid][pBizKey];
		    new playinghours = gPlayerData[targetid][pPlayingHours];
		    new warnings = gPlayerData[targetid][pWarnings];
		    new age = gPlayerData[targetid][pAge];
			new level = gPlayerData[targetid][pLevel];
			new exp = gPlayerData[targetid][pExp];
			new nxtlevel = gPlayerData[targetid][pLevel]+1;
			new expamount = nxtlevel*levelexp;

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
				case 13: {jobtext = "Kierowca autobusu"; jobpoints = gPlayerData[targetid][pBusJobPoints]; jobpointsmax = 30*gPlayerData[targetid][pJobLvl] + gPlayerData[targetid][pJobLvl]*10; joblvl = gPlayerData[targetid][pJobLvl]; }
				case 14: {jobtext = "Kierowca œmieciarki"; jobpoints = gPlayerData[targetid][pMzgkJobPoints]; jobpointsmax = 30*gPlayerData[targetid][pMzgkJobLvl] + gPlayerData[targetid][pMzgkJobLvl]*10; joblvl = gPlayerData[targetid][pMzgkJobLvl]; }
				case 15: {jobtext = "Kierowca myjki drogowej"; jobpoints = gPlayerData[targetid][pSweeperJobPoints]; jobpointsmax = 30*gPlayerData[targetid][pSweeperJobLvl] + gPlayerData[targetid][pSweeperJobLvl]*10; joblvl = gPlayerData[targetid][pSweeperJobLvl]; }
				case 16: jobtext = "Taksówkarz";
				case 17: {jobtext = "Mechanik"; jobpoints = gPlayerData[targetid][pMechanicJobPoints]; jobpointsmax = 90 + (gPlayerData[targetid][pMechanicJobLvl]*10); joblvl = gPlayerData[targetid][pMechanicJobLvl];}
				case 18: {jobtext = "Farmer"; jobpoints = gPlayerData[targetid][pFarmerJobPoints]; jobpointsmax = 30*gPlayerData[targetid][pFarmerJobLvl] + gPlayerData[targetid][pFarmerJobLvl]*20; joblvl = gPlayerData[targetid][pFarmerJobLvl]; }
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
			if(gPlayerData[targetid][pPhoneC] == 255) { phonenetwork = "Brak"; } else { format(phonenetwork, sizeof(phonenetwork), "%s",Businesses[gPlayerData[targetid][pPhoneC]][BusinessName]); }

			//============================[DISPLAY]============================
   			format(wstring, sizeof(wstring), "[G£ÓWNE:] Gracz: %s - Poziom: %d - Doœwiadczenie: %d/%d - Pkt pracy: %d/%d - Lvl pracy: %d", GetPlayerNameEx(targetid), level, exp, expamount, jobpoints, jobpointsmax, joblvl);
		    SendClientMessage(playerid,COLOR_WHITE, wstring);
			format(wstring, sizeof(wstring), "[G£ÓWNE:] ID biznesu: %d - Ostrze¿enia: %d - Narkotyki: %d - Praca: %s", bizkey, warnings, drugs, jobtext);
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
    new string[24];
	format(string, sizeof(string), "%s", gPlayerData[playerid][pName]);
    new str[24];
    strmid(str,string,0,strlen(string),24);
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

Delay:HangupTimer[1000, i](playerid)
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
public ResetVehicleData(vehicleid, reason)
{
	//print("[TIMERCHECK:] ResetVehicleData(vehicleid, reason)");
	new Float:vHealth;
	GetVehicleHealth(vehicleid, vHealth);
	if( vHealth < 25 || reason == 1)
	{
		new vehiclemodel = GetVehicleModel(vehicleid);

		new string[256];
		format(string, sizeof(string), "VehicleID: %d, Model: %d, by ResetVehicleData() ", vehicleid, vehiclemodel);
		ResetVehicleLog(string);

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
					print("Vehicle not prepaired for sale !");
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
					print("Vehicle not prepaired for sale !");
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
					print("Vehicle not prepaired for sale !");
					break;
				}
			}
		}

		/* Decrease vehicle cout from business if the vehicle wasn't bough */
		if(gVehData[vehicleid-1][BusinessID] != 255 && gVehData[vehicleid-1][FactionCar] == 255 && gVehData[vehicleid-1][CarType] == 0 && gVehData[vehicleid-1][Owned] == 0)
		{
			Businesses[gVehData[vehicleid-1][BusinessID]][VehicleCount]--;
		}

		/* Decrease vehicle cout from faction */
		if(gVehData[vehicleid-1][FactionCar] != 255)
		{
			if(!(DynamicFactions[gVehData[vehicleid-1][FactionCar]][fCarsCount] <= 0))
			{
				DynamicFactions[gVehData[vehicleid-1][FactionCar]][fCarsCount]--;
			}
		}

		if(gVehData[vehicleid-1][ReadyToSell] == 1)
		{
			DestroyDynamic3DTextLabel( gVehData[vehicleid-1][Veh3DSell]);
		}
		if(gVehData[vehicleid-1][FactionCar] != 255)
		{
			if( DynamicFactions[ gVehData[vehicleid-1][FactionCar] ][fType] == 6 )
			{
				// DestroyDynamic3DTextLabel( gVehData[vehicleid-1][Veh3DTaxiNfo] );
				// DestroyDynamic3DTextLabel( gVehData[vehicleid-1][Veh3DTaxiNfo2] );
			}
		}
		
		GetVehiclePos(vehicleid, gVehData[vehicleid-1][CarX], gVehData[vehicleid-1][CarY], gVehData[vehicleid-1][CarZ] );
		SaveVehData(vehicleid-1, "CarPos");
		if( vehicleid != 255 && vehicleid != 256)
		{
			DestroyObject( gVehData[vehicleid-1][CustomObj1ID] );
			DestroyObject( gVehData[vehicleid-1][CustomObj2ID] );
			DestroyObject( gVehData[vehicleid-1][CustomObj3ID] );			
			gVehData[vehicleid-1][CarModel] = 594;
			gVehData[vehicleid-1][CarX] = 4500.0;
			gVehData[vehicleid-1][CarY] = 300.0;
			gVehData[vehicleid-1][CarZ] = 3.0;
			gVehData[vehicleid-1][CarAngle] = 0.0;
			gVehData[vehicleid-1][CarColor1] = -1;
			gVehData[vehicleid-1][CarColor2] = -1;
			gVehData[vehicleid-1][FactionCar] = 255;
			gVehData[vehicleid-1][CarType] = 0;
			gVehData[vehicleid-1][Owned] = 0;
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

			SaveVehData(vehicleid-1, "CarModel");
			SaveVehData(vehicleid-1, "CarPos");
			SaveVehData(vehicleid-1, "CarColor1");
			SaveVehData(vehicleid-1, "CarColor2");
			SaveVehData(vehicleid-1, "FactionCar");
			SaveVehData(vehicleid-1, "CarType");
			SaveVehData(vehicleid-1, "Owned");
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
			SaveVehData(vehicleid-1, "CustomObj1Model");
			SaveVehData(vehicleid-1, "CustomObj2Model");
			SaveVehData(vehicleid-1, "CustomObj3Model");
			SaveVehData(vehicleid-1, "BatteryCapacity");
			SaveVehData(vehicleid-1, "VConfiscated");
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
		}

		/* Removes vehicle serial number */
		DestroyDynamic3DTextLabel( gVehData[vehicleid-1][Veh3DSerial] );

		DestroyVehicle(vehicleid);
		CreateVehicle(gVehData[vehicleid-1][CarModel], gVehData[vehicleid-1][CarX], gVehData[vehicleid-1][CarY], gVehData[vehicleid-1][CarZ], 0.0, -1, -1, -1);
		//printf("[%d-%d-%d] [VEHICLE:] Vehicle id: %d data has been reset", Year, Month, Day, vehicleid);
	}
	else
	{
		DestroyVehicle(vehicleid);
		CreateVehicle(gVehData[vehicleid-1][CarModel], gVehData[vehicleid-1][CarX], gVehData[vehicleid-1][CarY], gVehData[vehicleid-1][CarZ], 0.0, gVehData[vehicleid-1][CarColor1], gVehData[vehicleid-1][CarColor2], -1);
	}
}

PhoneAnimation(playerid)
{
	if(!IsPlayerInAnyVehicle(playerid))
	{
		SetPlayerSpecialAction(playerid,SPECIAL_ACTION_USECELLPHONE);
		SetPlayerAttachedObject(playerid, 4, 330, 6);
		HangupTimer(playerid);
		return 1;
	}
	return 0;
}

Delay:DrugEffect[2500, i](playerid)
{
	SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] Jesteœ na haju !");
 	SetPlayerWeather(playerid, 500);
	delay:UndrugEffect[50000](playerid);
	return 1;
}

Delay:DrugEffectHard[1000, i](playerid)
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
    delay:UndrugEffect[90000](playerid);
	return 1;
}

Delay:UndrugEffect[10000, i](playerid)
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
		SetPlayerArmour(playerid, pDrugsUsedStartArmour[playerid]);
		pDrugsUsedStartArmour[playerid] = 0.0;
	}
	else
	{
		if(armour > 100.0)
		{
			SetPlayerArmour(playerid, 100.0);
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

GetPlayerWantedLevelEx(playerid)
{
	return gPlayerData[playerid][pWantedLvl];
}

Delay:UntazePlayer[10000, i](playerid)
{
	if(PlayerTazed[playerid] == 1)
	{
	    SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] Otrz¹sn¹³eœ siê z parali¿u.");
	    TogglePlayerControllable(playerid,1);
	    PlayerTazed[playerid] = 0;
	    PlayerActionMessage(playerid,15.0,"nie jest ju¿ sparali¿owany.");
	}
	return 1;
}

public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	//new key, ud, lr;
	//GetPlayerKeys(playerid, key, ud, lr);
	//format(tmpstring, sizeof(tmpstring), "keyId: %d", key);
	//SendClientMessage(playerid, 0xFFFFFFFF, tmpstring);

	if(PRESSED(LIGHT_KEY))
	{
		if(IsPlayerInAnyVehicle(playerid) && GetPlayerVehicleSeat(playerid) == 0)
		{
			new carid = GetPlayerVehicleID(playerid);
			new enginedyn,lights,alarm,bonnet,boot,objective;
		 	new doors;
			GetVehicleParamsEx(carid, enginedyn, lights, alarm, doors, bonnet, boot, objective);
			switch(gVehData[carid-1][LightsOn])
			{
				case -1:{
					SetVehicleParamsEx(carid,enginedyn,0,alarm,doors,bonnet,boot,objective);
					gVehData[carid-1][LightsOn] = 0;
					SaveVehData(carid-1, "LightsOn");
				}
				case 0:{
					SetVehicleParamsEx(carid,enginedyn,1,alarm,doors,bonnet,boot,objective);
					gVehData[carid-1][LightsOn] = 1;
					SaveVehData(carid-1, "LightsOn");
				}
				case 1:{
					SetVehicleParamsEx(carid,enginedyn,0,alarm,doors,bonnet,boot,objective);
					gVehData[carid-1][LightsOn] = 0;
					SaveVehData(carid-1, "LightsOn");
				}
			}
		}
	}
	if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
	{
		if (newkeys & KEY_SECONDARY_ATTACK)
		{
			if(!IsPlayerInRangeOfPoint(playerid, 100.0, 617.5380, -1.9900, 1000.6829))
			{
				if(!PlayerCuffed[playerid])
				{
					if(gVehData[GetPlayerVehicleID(playerid)-1][EngineOn] == 0 && EngineTurningOn[playerid] == 0)
					{
						RemoveDriverFromVehicle(playerid);
					}
					// if(OutOfFuel[playerid])
					// {
						// RemoveDriverFromVehicle(playerid);
						// OutOfFuel[playerid] = 0;
					// }
				}
			}
		}
	}
	if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
	{
		if(newkeys & KEY_HANDBRAKE)
		{
			if(GetPlayerWeapon(playerid) == Speedgun && gPlayerData[playerid][pFaction] != 255)
			{
				if(DynamicFactions[gPlayerData[playerid][pFaction]][fType] == 1)
					delay:GetPlayerSpeed[1](playerid);
			}
			if(gIsOnAShip[playerid] != -1)
			{
				new Float:pX, Float:pY, Float:pZ, Float:pA;
				new Float:rOX, Float:rOY, Float:rOZ;
				new pointCorrect;
				GetPlayerCameraFrontVector(playerid, pX, pY, pZ);
				GetPosFromView(playerid, gShipSight[playerid], pX, pY, pZ);
				for(new i = 0; i < sizeof(gAreasWater); i++)
				{
					if(!IsPointInArea(gAreasWater[i][minX], gAreasWater[i][minY], gAreasWater[i][maxX], gAreasWater[i][maxY], pX, pY))
						continue;
					else
					{
						pointCorrect = 1;
						TurnPlayerFaceToPos(playerid, pX, pY);
						GetPlayerFacingAngle(playerid, pA);
						GetObjectRot(gIsOnAShip[playerid], rOX, rOY, rOZ);
						pA = floatabs(pA-rOZ);
						MoveObject(gShips[gIsOnAShip[playerid]][shipObjID], pX, pY, gShips[gIsOnAShip[playerid]][shipZ], 5.8, 0.0, 0.0, pA);
						gShips[gIsOnAShip[playerid]][shipX] = pX;
						gShips[gIsOnAShip[playerid]][shipY] = pY;
					}
				}
				if(!pointCorrect)
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz tam p³yn¹æ !");					
			}
		}
		if(newkeys & KEY_JUMP)
			gJumped[playerid] += 2;
		if(newkeys & KEY_SPRINT)
		{
			if(gPlayerData[playerid][pAdmin] == 0)
			{
				if(gSprinting[playerid] == 0)
				{
					new string[128];
					format(string, sizeof(string), "[INFO:] Gracz: %s [%d] sprintuje", gPlayerData[playerid][pName], playerid);
					ABroadCast(COLOR_YELLOW, string, 1);
				}
				gSprinting[playerid] = 3;
			}
		}
		if(newkeys & KEY_YES)
		{
			if(gIsOnAShip[playerid] != -1)
			{
				new string[128];
				if(gShipSight[playerid] > 10.0)
					gShipSight[playerid] += 5.0;
				else if(gShipSight[playerid] <= 10.0)
					gShipSight[playerid] += 1.0;
				format(string, sizeof(string), "[INFO:] Zasiêg przemieszczenia zwiêkszony do %fm", gShipSight[playerid]);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			}
		}
		if(newkeys & KEY_NO)
		{
			if(gIsOnAShip[playerid] != -1)
			{
				new string[128];
				if(gShipSight[playerid] > 10.0)
					gShipSight[playerid] -= 5.0;
				else if(gShipSight[playerid] <= 10.0 && gShipSight[playerid] > 0.0)
					gShipSight[playerid] -= 1.0;
				format(string, sizeof(string), "[INFO:] Zasiêg przemieszczenia zmniejszony do %fm", gShipSight[playerid]);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			}
		}				
	}
	return 1;
} // end of OnPlayerKeyStateChange

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

Delay:ClearCheckpointsForPlayer[60000, i](playerid)
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

Timer:IdleKick[300000]()
{
	new plname[64];
	new string[128];
	for(new i = 0; i < CUSTOM_MAX_PLAYERS; i++)
	{
		if(IsPlayerConnected(i))
		{
		    if(gPlayerData[i][pAdmin] < 1)
		    {
				if(gPlayerData[i][pTutorial] == 1)
				{
					if(gPlayerData[i][pVipAFK] == 0 && gPlayerData[i][pVipAFKT] == 0)
					{
						GetPlayerPos(i, PlayerPos[i][0], PlayerPos[i][1], PlayerPos[i][2]);
						if(PlayerPos[i][0] == PlayerPos[i][3] && PlayerPos[i][1] == PlayerPos[i][4] && PlayerPos[i][2] == PlayerPos[i][5] && PlayerWrittingAnything[i] == 0)
						{
							GetPlayerName(i, plname, sizeof(plname));
							format(string, sizeof(string), "[SERVER:] %s zosta³ wyrzucony z serwera, powód: AFK", plname);
							ABroadCast(COLOR_YELLOW,string,1);
							Kick(i);
						}
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

SafeGivePlayerMoney(plyid, amounttogive)
{
	new curHour, curMinute, curSecond;
	gettime(curHour, curMinute, curSecond);
	ScriptMoneyUpdated[plyid] = curSecond;
	if (amounttogive < 0)
	{
		GivePlayerMoney(plyid, amounttogive);
		ScriptMoney[plyid] = (ScriptMoney[plyid] + amounttogive);
	}
	else
	{
		ScriptMoney[plyid] = (ScriptMoney[plyid] + amounttogive);
		GivePlayerMoney(plyid, amounttogive);
	}
	return 1;
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

Delay:NewbieTimer[50000, i](playerid)
{
	if(IsPlayerConnected(playerid))
	{
	    if(NewbieTime[playerid] == 1)
	    {
			NewbieTime[playerid] = 0;
	    }
	}
}

NewbieOff(color,const string[])
{
	for(new i = 0; i < CUSTOM_MAX_PLAYERS; i++)
	{
		if(IsPlayerConnected(i) && gPlayerData[i][pTutorial] == 1)
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

stock GivePlayerGun(playerid, weaponid, ammo) // Thx to Seif
{
	Gun[playerid][Weapon][WeaponSlot(weaponid)] = weaponid;
	Ammo[playerid][weaponid] = ammo;
	GivePlayerWeapon(playerid, weaponid, ammo);
}

stock WeaponSlot(weaponid) // Thx to Seif
{
	switch (weaponid)
	{
	    case 0,1: return 0;
	    case 2..9: return 1;
	    case 10..15: return 10;
	    case 16..18,39: return 8;
	    case 22..24: return 2;
	    case 25..27: return 3;
	    case 28,29,32: return 4;
	    case 33,34: return 6;
	    case 35..38: return 7;
	    case 41..43: return 9;
	    case 44..46: return 11;
	    default: return 12;
	}
	return true;
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

/*
stock GetConfigFile()
{
	new cf[256];
	format(cf,sizeof(cf), "%s", CONFIG_FILE);
	return cf;
}

stock ForbiddenWordsLoad()
{
    new File:file;
	new xstring[100];

	ForbiddenWordCount = 0;

	if((file = fopen(FWORDS,io_read)))
	{
		while(fread(file,xstring))
		{
		for(new i = 0, j = strlen(xstring); i < j; i++) if(xstring[i] == '\n' || xstring[i] == '\r') xstring[i] = '\0';
		ForbiddenWords[ForbiddenWordCount] = xstring;
		ForbiddenWordCount++;
		}
		fclose(file);	printf("[ANTI-CHEAT: %d forbidden Words loaded", ForbiddenWordCount);
	}
}

stock ForbiddenNamesLoad()
{
    new File:file;
	new string[100];

 	BadNameCount = 0;

	if((file = fopen(BNAMES,io_read)))
	{
	while(fread(file,string))
	{
 	for(new i = 0, j = strlen(string); i < j; i++) if(string[i] == '\n' || string[i] == '\r') string[i] = '\0';
 	BadNames[BadNameCount] = string;
 	BadNameCount++;
	}
	fclose(file);	printf("== ANTI-CHEAT: %d forbidden Names loaded", BadNameCount);
	}
}
*/
stock SetPlayerToPos(playerid,Float:x,Float:y,Float:z)
{
	if(IsPlayerConnected(playerid))
	{
		SetPlayerPos(playerid,x,y,z);
  		NewPos[playerid][0] = x;
    	NewPos[playerid][1] = y;
     	NewPos[playerid][2] = z;
      	PosHackCheckTime[playerid] = 5;
       	return 1;
	}
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

stock PutPlayerIntoVehicle(playerid,vehicleid,seatid)
{
	if(IsPlayerConnected(playerid))
	{
		for(new i = 0; i < CUSTOM_MAX_PLAYERS; i++)
		{
			if(GetPlayerVehicleID(i) == vehicleid)
			{
				if(GetPlayerVehicleSeat(i) == seatid)
				{
					return 0;
				}
			}
		}
		PutPlayerInVehicle(playerid,vehicleid,seatid);
  		IngVehData[playerid] = 1;
  		return 1;
	}
	return 0;
}

SetPlayerSpawn(playerid)
{
	if(gPlayerData[playerid][pCrashed] == 1)
	{
		gPlayerData[playerid][pCrashed] = 0;
		SavePlayerData(playerid, "Crashed");
		GameTextForPlayer(playerid, "~r~Crashed...~n~~g~Respawn na ostatniej znanej pozycji.", 7000, 6);

		if(gPlayerData[playerid][pSex] == 1)
			PlayerLocalMessage(playerid,15.0,"zosta³ przeniesiony na ostatni¹ znan¹ pozycje.");
		else
			PlayerLocalMessage(playerid,15.0,"zosta³a przeniesiona na ostatni¹ znan¹ pozycje.");
	}
	if(JustDied[playerid])
	{
		if( gPlayerData[playerid][pDuty] && gPlayerData[playerid][pFaction] != 255 )
			SetPlayerToFactionSkin(playerid);
		else if( gPlayerData[playerid][pJailed] > 0 )
			SetPlayerSkin(playerid,96);
		else
			SetPlayerSkin(playerid,gPlayerData[playerid][pSkin]);
		
		
		if( gPlayerData[playerid][pHP] <= 0.0 )
		{
			print("[WARNING:] Player HP below 0 !");
			SetPlayerHealth(playerid,30.0);
		}
		else
			SetPlayerHealth(playerid,gPlayerData[playerid][pHP]);
		
		SetPlayerDrunkLevel(playerid, 50000);
		JustDied[playerid] = 0;
		if(gPlayerData[playerid][pCrashX] == 0.0 || gPlayerData[playerid][pCrashY] == 0.0 || gPlayerData[playerid][pCrashY] == 0.0)
			SetPlayerToPos(playerid,-1951.84,137.79,26.2812);
		else
			SetPlayerToPos(playerid,gPlayerData[playerid][pCrashX],gPlayerData[playerid][pCrashY],gPlayerData[playerid][pCrashZ]);
		SetPlayerFacingAngle(playerid, gPlayerData[playerid][pCrashAngle]);
		SetPlayerVirtualWorld(playerid, gPlayerData[playerid][pCrashW]);
		SetPlayerInterior(playerid,gPlayerData[playerid][pCrashInt]);
		if(AdminDuty[playerid] == 1)
		{
			SetPlayerColor(playerid,COLOR_ADMINDUTY);
			SetPlayerHealth(playerid,99999);
			SetPlayerArmour(playerid,99999);
			TogglePlayerControllable(playerid, 0);
			unfreezeTPPlayer(playerid);
			
			// Return saved player guns
			GivePlayerGun(playerid, gPlayerData[playerid][pWSlot0], gPlayerData[playerid][pWSlot0Ammo]);
			GivePlayerGun(playerid, gPlayerData[playerid][pWSlot1], gPlayerData[playerid][pWSlot1Ammo]);
			GivePlayerGun(playerid, gPlayerData[playerid][pWSlot2], gPlayerData[playerid][pWSlot2Ammo]);
			GivePlayerGun(playerid, gPlayerData[playerid][pWSlot3], gPlayerData[playerid][pWSlot3Ammo]);
			GivePlayerGun(playerid, gPlayerData[playerid][pWSlot4], gPlayerData[playerid][pWSlot4Ammo]);
			GivePlayerGun(playerid, gPlayerData[playerid][pWSlot5], gPlayerData[playerid][pWSlot5Ammo]);
			GivePlayerGun(playerid, gPlayerData[playerid][pWSlot6], gPlayerData[playerid][pWSlot6Ammo]);
		}
		else
		{
			if(gPlayerData[playerid][pCharacterDying] > 1 && gPlayerData[playerid][pAdmin] == 0)
			{
				SetPlayerCameraPos( playerid, gPlayerData[playerid][pCrashX], gPlayerData[playerid][pCrashY], gPlayerData[playerid][pCrashZ]+5.0 );
				SetPlayerCameraLookAt( playerid, gPlayerData[playerid][pCrashX], gPlayerData[playerid][pCrashY], gPlayerData[playerid][pCrashZ]+10.0 );	
				SetPlayerHealth(playerid,99999);
				ApplyAnimation(playerid,"ped","FLOOR_hit",4.1,0,1,1,1,0);
				ApplyAnimation(playerid,"ped","FLOOR_hit",4.1,0,1,1,1,0);
				TextDrawHideForPlayer(playerid, Status[playerid]);
				// SetTimerEx("TogglePlayerUnControllable", 100, false, "dfff", playerid, gPlayerData[playerid][pCrashX], gPlayerData[playerid][pCrashY], gPlayerData[playerid][pCrashZ] );
				SendClientMessage(playerid, COLOR_RED, "[INFO:] Teraz oczekujesz na pomoc. Mo¿esz wpisaæ /smierc aby");
				SendClientMessage(playerid, COLOR_RED, "zrezygnowac z czekania jednakze wtedy Twoja postac umrze i nie bedziesz mogl nia juz grac.");
			}
			else
			{
				TogglePlayerControllable(playerid, 0);
				unfreezeTPPlayer(playerid);
			}
		}
		return 1;
	}
	else
	{
		if( gPlayerData[playerid][pDuty] && gPlayerData[playerid][pFaction] != 255 )
			SetPlayerToFactionSkin(playerid);
		else if( gPlayerData[playerid][pJailed] > 0 )
			SetPlayerSkin(playerid,96);
		else
			SetPlayerSkin(playerid,gPlayerData[playerid][pSkin]);			
		
		if( gPlayerData[playerid][pHP] <= 0.0 )
		{
			print("[WARNING:] Player HP below 0 !");
			SetPlayerHealth(playerid,30.0);
		}
		else
			SetPlayerHealth(playerid,gPlayerData[playerid][pHP]);
		
		// Return saved player guns
		GivePlayerGun(playerid, gPlayerData[playerid][pWSlot0], gPlayerData[playerid][pWSlot0Ammo]);
		GivePlayerGun(playerid, gPlayerData[playerid][pWSlot1], gPlayerData[playerid][pWSlot1Ammo]);
		GivePlayerGun(playerid, gPlayerData[playerid][pWSlot2], gPlayerData[playerid][pWSlot2Ammo]);
		GivePlayerGun(playerid, gPlayerData[playerid][pWSlot3], gPlayerData[playerid][pWSlot3Ammo]);
		GivePlayerGun(playerid, gPlayerData[playerid][pWSlot4], gPlayerData[playerid][pWSlot4Ammo]);
		GivePlayerGun(playerid, gPlayerData[playerid][pWSlot5], gPlayerData[playerid][pWSlot5Ammo]);
		
		if( AdminDuty[playerid] )
		{
			if(gPlayerData[playerid][pCrashX] == 0.0 || gPlayerData[playerid][pCrashY] == 0.0 || gPlayerData[playerid][pCrashY] == 0.0)
				SetPlayerToPos(playerid,-1951.84,137.79,26.2812);
			else
				SetPlayerToPos(playerid,gPlayerData[playerid][pCrashX],gPlayerData[playerid][pCrashY],gPlayerData[playerid][pCrashZ]);
			SetPlayerInterior(playerid,gPlayerData[playerid][pCrashInt]);
			SetPlayerVirtualWorld(playerid,gPlayerData[playerid][pCrashW]);
			SetPlayerFacingAngle(playerid,gPlayerData[playerid][pCrashAngle]);
			SetPlayerColor(playerid,COLOR_ADMINDUTY);
			SetPlayerHealth(playerid,99999);
			SetPlayerArmour(playerid,99999);
			TogglePlayerControllable(playerid, 0);
			unfreezeTPPlayer(playerid);
		}
		else
		{
			if(gPlayerData[playerid][pJailed] == 1)
			{
				if(gPlayerData[playerid][pFaction] != 255)
				{
					//SetPlayerToFactionColor(playerid);
					SetPlayerToFactionSkin(playerid);
				}
				SetPlayerVirtualWorld(playerid,21);
				SetPlayerInterior(playerid, 0);

				DBVariables[2][varDValue]++;
				switch(DBVariables[2][varDValue])
				{
					case 0: SetPlayerToPos(playerid, 1778.6060791016,-1581.3503417969,1738.7172851563);
					case 1: SetPlayerToPos(playerid, 1778.60546875,-1581.349609375,1734.9417724609);
					case 2: SetPlayerToPos(playerid, 1774.3107910156,-1580.8834228516,1734.9429931641);
					case 3: SetPlayerToPos(playerid, 1770.0396728516,-1580.9715576172,1734.9429931641);
					case 4: SetPlayerToPos(playerid, 1765.6442871094,-1581.0885009766,1734.9429931641);
					case 5: SetPlayerToPos(playerid, 1761.5192871094,-1580.9661865234,1734.9429931641);
					case 6: SetPlayerToPos(playerid, 1757.1713867188,-1581.1558837891,1734.9429931641);
					case 7: SetPlayerToPos(playerid, 1757.3331298828,-1565.4664306641,1734.9429931641);
					case 8: SetPlayerToPos(playerid, 1761.7298583984,-1565.6207275391,1734.9429931641);
					case 9: SetPlayerToPos(playerid, 1765.9074707031,-1565.1364746094,1734.9429931641);
					case 10: SetPlayerToPos(playerid, 1770.2448730469,-1565.3743896484,1734.9429931641);
					case 11: SetPlayerToPos(playerid, 1774.5153808594,-1565.1875,1734.9429931641);
					case 12: SetPlayerToPos(playerid, 1778.6448974609,-1565.0377197266,1734.9429931641);
					case 13: SetPlayerToPos(playerid, 1774.236328125,-1580.9116210938,1738.7172851563);
					case 14: SetPlayerToPos(playerid, 1770.1110839844,-1580.9205322266,1738.7172851563);
					case 15: SetPlayerToPos(playerid, 1765.7939453125,-1581.2406005859,1738.7172851563);
					case 16: SetPlayerToPos(playerid, 1761.4822998047,-1581.0185546875,1738.7172851563);
					case 17: SetPlayerToPos(playerid, 1757.3651123047,-1581.0830078125,1738.7172851563);
					case 18: SetPlayerToPos(playerid, 1757.3023681641,-1565.8057861328,1738.6934814453);
					case 19: SetPlayerToPos(playerid, 1761.7540283203,-1565.4591064453,1738.6934814453);
					case 20: SetPlayerToPos(playerid, 1765.8216552734,-1565.5594482422,1738.6934814453);
					case 21: SetPlayerToPos(playerid, 1770.0919189453,-1565.4733886719,1738.6934814453);
					case 22: SetPlayerToPos(playerid, 1774.4881591797,-1565.1726074219,1738.6934814453);
					case 23: SetPlayerToPos(playerid, 1778.5562744141,-1565.2510986328,1738.6937255859);
				}
				if(DBVariables[2][varDValue] == 23)
				{
					DBVariables[2][varDValue] = 0;
				}
				TogglePlayerControllable(playerid, 0);
				unfreezeTPPlayer(playerid);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie jesteœ jeszcze wolny !");
			}
			else
			{
				if(gPlayerData[playerid][pCrashX] == 0.0 || gPlayerData[playerid][pCrashY] == 0.0 || gPlayerData[playerid][pCrashY] == 0.0)
				{
					printf("[WARNING:] Player %s pos is null", GetPlayerNameEx(playerid));
					SetPlayerToPos(playerid,1262.0, 362.0, 20.0);
				}
				else
					SetPlayerToPos(playerid,gPlayerData[playerid][pCrashX],gPlayerData[playerid][pCrashY],gPlayerData[playerid][pCrashZ]);
				SetPlayerInterior(playerid,gPlayerData[playerid][pCrashInt]);
				SetPlayerVirtualWorld(playerid,gPlayerData[playerid][pCrashW]);
				SetPlayerFacingAngle(playerid,gPlayerData[playerid][pCrashAngle]);
				if(gPlayerData[playerid][pCharacterDying] > 1 && gPlayerData[playerid][pAdmin] == 0)
				{
					SetPlayerCameraPos( playerid, gPlayerData[playerid][pCrashX], gPlayerData[playerid][pCrashY], gPlayerData[playerid][pCrashZ]+5.0 );
					SetPlayerCameraLookAt( playerid, gPlayerData[playerid][pCrashX], gPlayerData[playerid][pCrashY], gPlayerData[playerid][pCrashZ]+10.0 );	
					SetPlayerHealth(playerid,99999);
					ApplyAnimation(playerid,"ped","FLOOR_hit",4.1,0,1,1,1,0);
					ApplyAnimation(playerid,"ped","FLOOR_hit",4.1,0,1,1,1,0);
					TextDrawHideForPlayer(playerid, Status[playerid]);
					// SetTimerEx("TogglePlayerUnControllable", 50, false, "dfff", playerid, gPlayerData[playerid][pCrashX], gPlayerData[playerid][pCrashY], gPlayerData[playerid][pCrashZ] );
					// ApplyAnimation(playerid,"ped","FLOOR_hit",4.1,0,1,1,1,1);
					SendClientMessage(playerid, COLOR_RED, "[INFO:] Twoja postaæ wci¹¿ oczekuje na pomoc. Jeœli chcesz przerwaæ jej mêki wpisz /smierc");
				}
				else
				{
					TogglePlayerControllable(playerid, 0);
					unfreezeTPPlayer(playerid);
				}
			}
		}
	}
	return 1;
} // end of SetPlayerSpawn

SetPlayerToFactionSkin(playerid)
{
  		new faction = gPlayerData[playerid][pFaction];
		new rank = gPlayerData[playerid][pRank];
		new rankamount = DynamicFactions[faction][fRankAmount];
		if(faction != 255)
		{
			if(DynamicFactions[faction][fUseSkins])
			{
				if(rank == 1 && rankamount >= 1)
				{
	   				if(DynamicFactions[faction][fType] == 1)
	    		    {
	    		        if(gPlayerData[playerid][pDuty])
	    		        {
	    		            SetPlayerSkin(playerid,DynamicFactions[faction][fSkin1]);
	    		        }
					}
					else
					{
						SetPlayerSkin(playerid,DynamicFactions[faction][fSkin1]);
					}
				}
				else if(rank == 2 && rankamount >= 2)
				{
	    			if(DynamicFactions[faction][fType] == 1)
	    		    {
	    		        if(gPlayerData[playerid][pDuty])
	    		        {
	    		            SetPlayerSkin(playerid,DynamicFactions[faction][fSkin2]);
	    		        }
					}
					else
					{
						SetPlayerSkin(playerid,DynamicFactions[faction][fSkin2]);
					}
				}
				else if(rank == 3 && rankamount >= 3)
				{
	    			if(DynamicFactions[faction][fType] == 1)
	    		    {
	    		        if(gPlayerData[playerid][pDuty])
	    		        {
	    		            SetPlayerSkin(playerid,DynamicFactions[faction][fSkin3]);
	    		        }
					}
					else
					{
						SetPlayerSkin(playerid,DynamicFactions[faction][fSkin3]);
					}
				}
				else if(rank == 4 && rankamount >= 4)
				{
					if(DynamicFactions[faction][fType] == 1)
	    		    {
	    		        if(gPlayerData[playerid][pDuty])
	    		        {
	    		            SetPlayerSkin(playerid,DynamicFactions[faction][fSkin4]);
	    		        }
					}
					else
					{
						SetPlayerSkin(playerid,DynamicFactions[faction][fSkin4]);
					}
				}
				else if(rank == 5 && rankamount >= 5)
				{
					if(DynamicFactions[faction][fType] == 1)
	    		    {
	    		        if(gPlayerData[playerid][pDuty])
	    		        {
	    		            SetPlayerSkin(playerid,DynamicFactions[faction][fSkin5]);
	    		        }
					}
					else
					{
						SetPlayerSkin(playerid,DynamicFactions[faction][fSkin5]);
					}
				}
				else if(rank == 6 && rankamount >= 6)
				{
					if(DynamicFactions[faction][fType] == 1)
	    		    {
	    		        if(gPlayerData[playerid][pDuty])
	    		        {
	    		            SetPlayerSkin(playerid,DynamicFactions[faction][fSkin6]);
	    		        }
					}
					else
					{
						SetPlayerSkin(playerid,DynamicFactions[faction][fSkin6]);
					}
				}
				else if(rank == 7 && rankamount >= 7)
				{
					if(DynamicFactions[faction][fType] == 1)
	    		    {
	    		        if(gPlayerData[playerid][pDuty])
	    		        {
	    		            SetPlayerSkin(playerid,DynamicFactions[faction][fSkin7]);
	    		        }
					}
					else
					{
						SetPlayerSkin(playerid,DynamicFactions[faction][fSkin7]);
					}
				}
				else if(rank == 8 && rankamount >= 8)
				{
					if(DynamicFactions[faction][fType] == 1)
	    		    {
	    		        if(gPlayerData[playerid][pDuty])
	    		        {
	    		            SetPlayerSkin(playerid,DynamicFactions[faction][fSkin8]);
	    		        }
					}
					else
					{
						SetPlayerSkin(playerid,DynamicFactions[faction][fSkin8]);
					}
				}
				else if(rank == 9 && rankamount >= 9)
				{
					if(DynamicFactions[faction][fType] == 1)
	    		    {
	    		        if(gPlayerData[playerid][pDuty])
	    		        {
	    		            SetPlayerSkin(playerid,DynamicFactions[faction][fSkin9]);
	    		        }
					}
					else
					{
						SetPlayerSkin(playerid,DynamicFactions[faction][fSkin9]);
					}
				}
				else if(rank == 10 && rankamount >= 10)
				{
					if(DynamicFactions[faction][fType] == 1)
	    		    {
	    		        if(gPlayerData[playerid][pDuty])
	    		        {
	    		            SetPlayerSkin(playerid,DynamicFactions[faction][fSkin10]);
	    		        }
					}
					else
					{
						SetPlayerSkin(playerid,DynamicFactions[faction][fSkin10]);
					}
				}
			}
		}
		return 1;
}

// SetPlayerToFactionColor(playerid)
// {
	// if(gPlayerData[playerid][pFaction] != 255)
	// {
		// if(DynamicFactions[gPlayerData[playerid][pFaction]][fUseColor])
		// {
		    // if(DynamicFactions[gPlayerData[playerid][pFaction]][fType] == 1)
		    // {
      			// if(gPlayerData[playerid][pDuty])
	        	// {
	        	    // SetPlayerColor(playerid,HexToInt(DynamicFactions[gPlayerData[playerid][pFaction]][fColor]));
   		        // }
   		        // else
   		        // {
	            	// SetPlayerColor(playerid,COLOR_CIVILIAN);
   		        // }
			// }
			// else
			// {
				// SetPlayerColor(playerid,HexToInt(DynamicFactions[gPlayerData[playerid][pFaction]][fColor]));
			// }
		// }
	// }
	// return 0;
// }

Delay:unfreezeTPPlayer[2000, i](playerid)
{
	TogglePlayerControllable(playerid, 1);
	return 1;
}

Delay:GateClose2[2000,]()
{
	MoveDynamicObject(HQ,-1990.5186767578, 543.30401611328, 36.789016723633, 3.5);
    return 0;
}

Delay:GateClose3[2000,]()
{
	MoveDynamicObject(HQ2,-2061.861328125, 434.58581542969, 25.348533630371, 3.5);
    return 0;
}

Delay:ArmyGate1Close[5000,]()
{
	SetDynamicObjectRot(bramawojsko1,0.000000, 270.49006347656, 359.99487304688);
    return 0;
}

Delay:PoliceGate1Close[5000,]()
{
	SetDynamicObjectRot(zomo1,0.000000, 89.090026855469, 90.055816650391);
    return 0;
}

Delay:PoliceGate2Close[5000,]()
{
	SetDynamicObjectRot(zomo2,0.000000, 270.92498779297, 89.785400390625);
    return 0;
}

public MoveCamera(playerid) // need fix, unauthorized use of gPlayerData[playerid][SpawnAngle]
{
	//this is called trigonometry. It makes the camera spin
	//you can experiment with this line. Just change the values 2, 10 and 3 to make different effects
	SetPlayerCameraPos(playerid, player_x - 13 * floatsin(-gPlayerData[playerid][SpawnAngle], degrees), player_y - 16 * floatcos(-gPlayerData[playerid][SpawnAngle], degrees), player_z + 3);
    SetPlayerCameraLookAt(playerid, player_x, player_y, player_z + 2);
	//changing the angle a little
	MoveCameraAngle[playerid] += 0.5;
    if (MoveCameraAngle[playerid] >= 360.0)
		MoveCameraAngle[playerid] = 0.0;
}

stock PlayerHaveWeapon(playerid, gunID)
{
	new tGunID, tGunAmmo, slot;
	if( GetPlayerWeapon(playerid) == gunID )
		return GetPlayerAmmo(playerid);
	slot = WeaponSlot(gunID);
	GetPlayerWeaponData(playerid, slot, tGunID, tGunAmmo);
	if( tGunID == gunID )
		return tGunAmmo;
	return 0;
}	

stock AddPlayerAmmo(playerid, gunID, gunAmmo)
{
	new tGunID, tGunAmmo, slot;
	if( GetPlayerWeapon(playerid) == gunID ) // sprawdzenie czy aktualnie wybrana bron gracza to bron == gunID
	{
		tGunAmmo = GetPlayerAmmo(playerid);
		GivePlayerGun(playerid, gunID, tGunAmmo + gunAmmo);
		return 1;
	}
	slot = WeaponSlot(gunID);
	GetPlayerWeaponData(playerid, slot, tGunID, tGunAmmo);
	if(tGunID == 0 || tGunID != gunID) // sprawdzenie czy gracz posiada bron na pozostalych slotach ( domyslnie 13 slotow w grze )
	{
		switch(gunID)
		{
			case 22: 
			{
				InsertPlayerItemEx(playerid, 1, 16, 0, 0, 0, 0, "Puste", 1);
				InsertPlayerItemEx(playerid, 1, 36, 0, 0, 0, 0, "Puste", gunAmmo);
			}
			case 23: 
			{
				InsertPlayerItemEx(playerid, 1, 17, 0, 0, 0, 0, "Puste", 1);
				InsertPlayerItemEx(playerid, 1, 36, 0, 0, 0, 0, "Puste", gunAmmo);
			}
			case 24:
			{
				InsertPlayerItemEx(playerid, 1, 18, 0, 0, 0, 0, "Puste", 1);
				InsertPlayerItemEx(playerid, 1, 37, 0, 0, 0, 0, "Puste", gunAmmo);
			}
			case 25:
			{
				InsertPlayerItemEx(playerid, 1, 19, 0, 0, 0, 0, "Puste", 1);
				InsertPlayerItemEx(playerid, 1, 39, 0, 0, 0, 0, "Puste", gunAmmo);
			}
			case 26:
			{
				InsertPlayerItemEx(playerid, 1, 20, 0, 0, 0, 0, "Puste", 1);
				InsertPlayerItemEx(playerid, 1, 38, 0, 0, 0, 0, "Puste", gunAmmo);
			}
			case 27:
			{
				InsertPlayerItemEx(playerid, 1, 21, 0, 0, 0, 0, "Puste", 1);
				InsertPlayerItemEx(playerid, 1, 38, 0, 0, 0, 0, "Puste", gunAmmo);
			}
			case 28:
			{
				InsertPlayerItemEx(playerid, 1, 22, 0, 0, 0, 0, "Puste", 1);
				InsertPlayerItemEx(playerid, 1, 36, 0, 0, 0, 0, "Puste", gunAmmo);
			}
			case 29:
			{
				InsertPlayerItemEx(playerid, 1, 23, 0, 0, 0, 0, "Puste", 1);
				InsertPlayerItemEx(playerid, 1, 36, 0, 0, 0, 0, "Puste", gunAmmo);
			}
			case 30:
			{
				InsertPlayerItemEx(playerid, 1, 24, 0, 0, 0, 0, "Puste", 1);
				InsertPlayerItemEx(playerid, 1, 39, 0, 0, 0, 0, "Puste", gunAmmo);
			}
			case 31:
			{
				InsertPlayerItemEx(playerid, 1, 25, 0, 0, 0, 0, "Puste", 1);
				InsertPlayerItemEx(playerid, 1, 39, 0, 0, 0, 0, "Puste", gunAmmo);
			}
			case 32:
			{
				InsertPlayerItemEx(playerid, 1, 26, 0, 0, 0, 0, "Puste", 1);
				InsertPlayerItemEx(playerid, 1, 36, 0, 0, 0, 0, "Puste", gunAmmo);
			}
			case 33:
			{
				InsertPlayerItemEx(playerid, 1, 27, 0, 0, 0, 0, "Puste", 1);
				InsertPlayerItemEx(playerid, 1, 40, 0, 0, 0, 0, "Puste", gunAmmo);
			}
			case 34:
			{
				InsertPlayerItemEx(playerid, 1, 28, 0, 0, 0, 0, "Puste", 1);
				InsertPlayerItemEx(playerid, 1, 40, 0, 0, 0, 0, "Puste", gunAmmo);
			}
			case 35:
			{
				InsertPlayerItemEx(playerid, 1, 29, 0, 0, 0, 0, "Puste", gunAmmo);
				InsertPlayerItemEx(playerid, 1, 41, 0, 0, 0, 0, "Puste", gunAmmo);
			}
			case 36:
			{
				InsertPlayerItemEx(playerid, 1, 30, 0, 0, 0, 0, "Puste", 1);
				InsertPlayerItemEx(playerid, 1, 41, 0, 0, 0, 0, "Puste", gunAmmo);
			}
			case 37:
			{
				InsertPlayerItemEx(playerid, 1, 31, 0, 0, 0, 0, "Puste", 1);
				InsertPlayerItemEx(playerid, 1, 42, 0, 0, 0, 0, "Puste", gunAmmo);
			}
			case 38:
			{
				InsertPlayerItemEx(playerid, 1, 32, 0, 0, 0, 0, "Puste", 1);
				InsertPlayerItemEx(playerid, 1, 39, 0, 0, 0, 0, "Puste", gunAmmo);
			}
			case 39: InsertPlayerItemEx(playerid, 1, 33, 0, 0, 0, 0, "Puste", gunAmmo);
			case 41: InsertPlayerItemEx(playerid, 1, 34, 0, 0, 0, 0, "Puste", gunAmmo);
			case 42: InsertPlayerItemEx(playerid, 1, 35, 0, 0, 0, 0, "Puste", gunAmmo);
		}
		return 1;
	}
	GivePlayerGun(playerid, gunID, gunAmmo); // przekazanie graczowi nowej broni
	return 0;
}

/*
* Checks if player carry weapon in normal slot, if not, add weapon to player items.
* Also checks if player factions have enough ammo or weapons for player.
* Removes apropriate amount of weapon/ammo from faction
*/
stock AddPlayerAmmoF(playerid, gunID, gunAmmo)
{
	new string[256];
	new fID = gPlayerData[playerid][pFaction];
	if( GetPlayerWeapon(playerid) != gunID )
	{
		switch( gunID )
		{
			case 22: // 9mm
			{
				if( DynamicFactions[fID][WFactory9MM] <= 0 )
					return 0;
				else if( !PHaveItem( playerid, 1, 16 ) )
				{
					InsertPlayerItemEx(playerid, 1, 16, 0, 0, 0, 0, "Puste", 1);
					DynamicFactions[fID][WFactory9MM]--;
					SaveFData( fID, "WFactory9MM" );
					format(string, sizeof(string), "[DUTY:] Taken WFactory9MM from factionid %d by %s", fID, GetPlayerNameEx(playerid));
					DutyLog(string);
				}
			}
			case 23: // 9mm sil
			{
				if( DynamicFactions[fID][WFactory9MMSil] <= 0 )
					return 0;
				else if( !PHaveItem( playerid, 1, 17 ) )
				{
					InsertPlayerItemEx(playerid, 1, 17, 0, 0, 0, 0, "Puste", 1);
					DynamicFactions[fID][WFactory9MMSil]--;
					SaveFData( fID, "WFactory9MMSil" );
					format(string, sizeof(string), "[DUTY:] Taken WFactory9MMSil from factionid %d by %s", fID, GetPlayerNameEx(playerid));
					DutyLog(string);
				}
			}
			case 24: // des eagle
			{
				if( DynamicFactions[fID][WFactoryDesEagle] <= 0 )
					return 0;
				else if( !PHaveItem( playerid, 1, 18 ) )
				{
					InsertPlayerItemEx(playerid, 1, 18, 0, 0, 0, 0, "Puste", 1);
					DynamicFactions[fID][WFactoryDesEagle]--;
					SaveFData( fID, "WFactoryDesEagle" );
					format(string, sizeof(string), "[DUTY:] Taken WFactoryDesEagle from factionid %d by %s", fID, GetPlayerNameEx(playerid));
					DutyLog(string);
				}
			}
			case 25: // shotgun
			{
				if( DynamicFactions[fID][WFactoryShotgun] <= 0 )
					return 0;
				else if( !PHaveItem( playerid, 1, 19 ) )
				{
					InsertPlayerItemEx(playerid, 1, 19, 0, 0, 0, 0, "Puste", 1);
					DynamicFactions[fID][WFactoryShotgun]--;
					SaveFData( fID, "WFactoryShotgun" );
					format(string, sizeof(string), "[DUTY:] Taken WFactoryShotgun from factionid %d by %s", fID, GetPlayerNameEx(playerid));
					DutyLog(string);
				}
			}
			case 28: // msmg
			{
				if( DynamicFactions[fID][WFactoryMicroSMG] <= 0 )
					return 0;
				else if( !PHaveItem( playerid, 1, 22 ) )
				{
					InsertPlayerItemEx(playerid, 1, 22, 0, 0, 0, 0, "Puste", 1);
					DynamicFactions[fID][WFactoryMicroSMG]--;
					SaveFData( fID, "WFactoryMicroSMG" );
					format(string, sizeof(string), "[DUTY:] Taken WFactoryMicroSMG from factionid %d by %s", fID, GetPlayerNameEx(playerid));
					DutyLog(string);
				}
			}
			case 29: // mp5
			{
				if( DynamicFactions[fID][WFactoryMP5] <= 0 )
					return 0;
				else if( !PHaveItem( playerid, 1, 23 ) )
				{
					InsertPlayerItemEx(playerid, 1, 23, 0, 0, 0, 0, "Puste", 1);
					DynamicFactions[fID][WFactoryMP5]--;
					SaveFData( fID, "WFactoryMP5" );
					format(string, sizeof(string), "[DUTY:] Taken WFactoryMP5 from factionid %d by %s", fID, GetPlayerNameEx(playerid));
					DutyLog(string);
				}
			}
			case 30: // AK47
			{
				if( DynamicFactions[fID][WFactoryAK47] <= 0 )
					return 0;
				else if( !PHaveItem( playerid, 1, 24 ) )
				{
					InsertPlayerItemEx(playerid, 1, 24, 0, 0, 0, 0, "Puste", 1);
					DynamicFactions[fID][WFactoryAK47]--;
					SaveFData( fID, "WFactoryAK47" );
					format(string, sizeof(string), "[DUTY:] Taken WFactoryAK47 from factionid %d by %s", fID, GetPlayerNameEx(playerid));
					DutyLog(string);
				}
			}
			case 31: // m4
			{
				if( DynamicFactions[fID][WFactoryM4] <= 0 )
					return 0;
				else if( !PHaveItem( playerid, 1, 25 ) )
				{
					InsertPlayerItemEx(playerid, 1, 25, 0, 0, 0, 0, "Puste", 1);
					DynamicFactions[fID][WFactoryM4]--;
					SaveFData( fID, "WFactoryM4" );
					format(string, sizeof(string), "[DUTY:] Taken WFactoryM4 from factionid %d by %s", fID, GetPlayerNameEx(playerid));
					DutyLog(string);
				}
			}
			case 32: // tec9
			{
				if( DynamicFactions[fID][WFactoryTec9] <= 0 )
					return 0;
				else if( !PHaveItem( playerid, 1, 26 ) )
				{
					InsertPlayerItemEx(playerid, 1, 26, 0, 0, 0, 0, "Puste", 1);
					DynamicFactions[fID][WFactoryTec9]--;
					SaveFData( fID, "WFactoryTec9" );
					format(string, sizeof(string), "[DUTY:] Taken WFactoryTec9 from factionid %d by %s", fID, GetPlayerNameEx(playerid));
					DutyLog(string);
				}
			}
			case 33: // rifle
			{
				if( DynamicFactions[fID][WFactoryRifle] <= 0 )
					return 0;
				else if( !PHaveItem( playerid, 1, 27 ) )
				{
					InsertPlayerItemEx(playerid, 1, 27, 0, 0, 0, 0, "Puste", 1);
					DynamicFactions[fID][WFactoryRifle]--;
					SaveFData( fID, "WFactoryRifle" );
					format(string, sizeof(string), "[DUTY:] Taken WFactoryRifle from factionid %d by %s", fID, GetPlayerNameEx(playerid));
					DutyLog(string);
				}
			}
			case 34: // srifle
			{
				if( DynamicFactions[fID][WFactorySRifle] <= 0 )
					return 0;
				else if( !PHaveItem( playerid, 1, 28 ) )
				{
					InsertPlayerItemEx(playerid, 1, 28, 0, 0, 0, 0, "Puste", 1);
					DynamicFactions[fID][WFactorySRifle]--;
					SaveFData( fID, "WFactorySRifle" );
					format(string, sizeof(string), "[DUTY:] Taken WFactorySRifle from factionid %d by %s", fID, GetPlayerNameEx(playerid));
					DutyLog(string);
				}
			}
		}
	}
	switch( gunID )
	{
		case 22, 23, 28, 29, 32: // 9mm ammo
		{
			if( DynamicFactions[fID][WFactory9MMAmmo] < gunAmmo )
				return 0;
			else
			{
				InsertPlayerItemEx(playerid, 1, 36, 0, 0, 0, 0, "Puste", gunAmmo);
				DynamicFactions[fID][WFactory9MMAmmo] -= gunAmmo;
				SaveFData( fID, "WFactory9MMAmmo" );
				format(string, sizeof(string), "[DUTY:] Taken %d WFactory9MMAmmo from factionid %d by %s", gunAmmo, fID, GetPlayerNameEx(playerid));
				DutyLog(string);
			}
		}
		case 24: // des eagle
		{
			if( DynamicFactions[fID][WFactory50AEAmmo] <= 0 )
				return 0;
			else
			{
				InsertPlayerItemEx(playerid, 1, 37, 0, 0, 0, 0, "Puste", gunAmmo);
				DynamicFactions[fID][WFactory50AEAmmo] -= gunAmmo;
				SaveFData( fID, "WFactory50AEAmmo" );
				format(string, sizeof(string), "[DUTY:] Taken %d WFactory50AEAmmo from factionid %d by %s", gunAmmo, fID, GetPlayerNameEx(playerid));
				DutyLog(string);
			}
		}
		case 25: // shotgun
		{
			if( DynamicFactions[fID][WFactoryBuckshot] <= 0 )
				return 0;
			else
			{
				InsertPlayerItemEx(playerid, 1, 38, 0, 0, 0, 0, "Puste", gunAmmo);
				DynamicFactions[fID][WFactoryBuckshot] -= gunAmmo;
				SaveFData( fID, "WFactoryBuckshot" );
				format(string, sizeof(string), "[DUTY:] Taken %d WFactoryBuckshot from factionid %d by %s", gunAmmo, fID, GetPlayerNameEx(playerid));
				DutyLog(string);
			}
		}
		case 30, 31, 33: // AK47
		{
			if( DynamicFactions[fID][WFactory762MMAmmo] <= 0 )
				return 0;
			else
			{
				InsertPlayerItemEx(playerid, 1, 39, 0, 0, 0, 0, "Puste", gunAmmo);
				DynamicFactions[fID][WFactory762MMAmmo] -= gunAmmo;
				SaveFData( fID, "WFactory762MMAmmo" );
				format(string, sizeof(string), "[DUTY:] Taken %d WFactory762MMAmmo from factionid %d by %s", gunAmmo, fID, GetPlayerNameEx(playerid));
				DutyLog(string);
			}
		}
		case 34: // srifle
		{
			if( DynamicFactions[fID][WFactory127MMAmmo] <= 0 )
				return 0;
			else
			{
				InsertPlayerItemEx(playerid, 1, 40, 0, 0, 0, 0, "Puste", gunAmmo);
				DynamicFactions[fID][WFactory127MMAmmo] -= gunAmmo;
				SaveFData( fID, "WFactory127MMAmmo" );
				format(string, sizeof(string), "[DUTY:] Taken %d WFactory127MMAmmo from factionid %d by %s", gunAmmo, fID, GetPlayerNameEx(playerid));
				DutyLog(string);
			}
		}
	}
	return 0;
}

/*
* Return weapons and ammo gained in duty
*/
stock ReturnPlayerAmmoF(playerid, gunID, gunAmmo)
{
	new fID = gPlayerData[playerid][pFaction];
	switch( gunID )
	{
		case 22: // 9mm
		{
			if( PHaveItem( playerid, 1, 16 ) )
			{
				RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 16 ) );
				DynamicFactions[fID][WFactory9MM]++;
				SaveFData( fID, "WFactory9MM" );
			}
		}
		case 23: // 9mm sil
		{
			if( PHaveItem( playerid, 1, 17 ) )
			{
				RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 17 ) );
				DynamicFactions[fID][WFactory9MMSil]++;
				SaveFData( fID, "WFactory9MMSil" );
			}
		}
		case 24: // des eagle
		{
			if( PHaveItem( playerid, 1, 18 ) )
			{
				RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 18 ) );
				DynamicFactions[fID][WFactoryDesEagle]++;
				SaveFData( fID, "WFactoryDesEagle" );
			}
		}
		case 25: // shotgun
		{
			if( PHaveItem( playerid, 1, 19 ) )
			{
				RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 19 ) );
				DynamicFactions[fID][WFactoryShotgun]++;
				SaveFData( fID, "WFactoryShotgun" );
			}
		}
		case 28: // msmg
		{
			if( PHaveItem( playerid, 1, 22 ) )
			{
				RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 22 ) );
				DynamicFactions[fID][WFactoryMicroSMG]++;
				SaveFData( fID, "WFactoryMicroSMG" );
			}
		}
		case 29: // mp5
		{
			if( PHaveItem( playerid, 1, 23 ) )
			{
				RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 23 ) );
				DynamicFactions[fID][WFactoryMP5]++;
				SaveFData( fID, "WFactoryMP5" );
			}
		}
		case 30: // AK47
		{
			if( PHaveItem( playerid, 1, 24 ) )
			{
				RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 24 ) );
				DynamicFactions[fID][WFactoryAK47]++;
				SaveFData( fID, "WFactoryAK47" );
			}
		}
		case 31: // m4
		{
			if( PHaveItem( playerid, 1, 25 ) )
			{
				RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 25 ) );
				DynamicFactions[fID][WFactoryM4]++;
				SaveFData( fID, "WFactoryM4" );
			}
		}
		case 32: // tec9
		{
			if( PHaveItem( playerid, 1, 26 ) )
			{
				RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 26 ) );
				DynamicFactions[fID][WFactoryTec9]++;
				SaveFData( fID, "WFactoryTec9" );
			}
		}
		case 33: // rifle
		{
			if( PHaveItem( playerid, 1, 27 ) )
			{
				RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 27 ) );
				DynamicFactions[fID][WFactoryRifle]++;
				SaveFData( fID, "WFactoryRifle" );
			}
		}
		case 34: // srifle
		{
			if( PHaveItem( playerid, 1, 28 ) )
			{
				RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 28 ) );
				DynamicFactions[fID][WFactorySRifle]++;
				SaveFData( fID, "WFactorySRifle" );
			}
		}
	}
	new rValue;
	switch( gunID )
	{
		case 22, 23, 28, 29, 32: // 9mm ammo
		{
			rValue = SlotParam6( playerid, PHaveItem( playerid, 1, 36 ) ) - gunAmmo;
			if( rValue >= 0 )
			{
				RemovePlayerItemExUsed(playerid, PHaveItem( playerid, 1, 36 ), gunAmmo);
				DynamicFactions[fID][WFactory9MMAmmo] += gunAmmo;
			}
			else if( rValue < 0 )
			{
				RemovePlayerItemExUsed(playerid, PHaveItem( playerid, 1, 36 ), SlotParam6( playerid, PHaveItem( playerid, 1, 36 ) ) );
				DynamicFactions[fID][WFactory9MMAmmo] += gunAmmo;
			}
			SaveFData( fID, "WFactory9MMAmmo" );
		}
		case 24: // des eagle
		{
			rValue = SlotParam6( playerid, PHaveItem( playerid, 1, 37 ) ) - gunAmmo;
			if( rValue >= 0 )
			{
				RemovePlayerItemExUsed(playerid, PHaveItem( playerid, 1, 37 ), gunAmmo);
				DynamicFactions[fID][WFactory50AEAmmo] += gunAmmo;
			}
			else if( rValue < 0 )
			{
				RemovePlayerItemExUsed(playerid, PHaveItem( playerid, 1, 37 ), SlotParam6( playerid, PHaveItem( playerid, 1, 36 ) ) );
				DynamicFactions[fID][WFactory50AEAmmo] += gunAmmo;
			}
			SaveFData( fID, "WFactory50AEAmmo" );
		}
		case 25: // shotgun
		{
			rValue = SlotParam6( playerid, PHaveItem( playerid, 1, 38 ) ) - gunAmmo;
			if( rValue >= 0 )
			{
				RemovePlayerItemExUsed(playerid, PHaveItem( playerid, 1, 38 ), gunAmmo);
				DynamicFactions[fID][WFactoryBuckshot] += gunAmmo;
			}
			else if( rValue < 0 )
			{
				RemovePlayerItemExUsed(playerid, PHaveItem( playerid, 1, 38 ), SlotParam6( playerid, PHaveItem( playerid, 1, 36 ) ) );
				DynamicFactions[fID][WFactoryBuckshot] += gunAmmo;
			}
			SaveFData( fID, "WFactoryBuckshot" );
		}
		case 30, 31, 33: // AK47
		{
			rValue = SlotParam6( playerid, PHaveItem( playerid, 1, 39 ) ) - gunAmmo;
			if( rValue >= 0 )
			{
				RemovePlayerItemExUsed(playerid, PHaveItem( playerid, 1, 39 ), gunAmmo);
				DynamicFactions[fID][WFactory762MMAmmo] += gunAmmo;
			}
			else if( rValue < 0 )
			{
				RemovePlayerItemExUsed(playerid, PHaveItem( playerid, 1, 39 ), SlotParam6( playerid, PHaveItem( playerid, 1, 36 ) ) );
				DynamicFactions[fID][WFactory762MMAmmo] += gunAmmo;
			}
			SaveFData( fID, "WFactory762MMAmmo" );
		}
		case 34: // srifle
		{
			rValue = SlotParam6( playerid, PHaveItem( playerid, 1, 40 ) ) - gunAmmo;
			if( rValue >= 0 )
			{
				RemovePlayerItemExUsed(playerid, PHaveItem( playerid, 1, 40 ), gunAmmo);
				DynamicFactions[fID][WFactory127MMAmmo] += gunAmmo;
			}
			else if( rValue < 0 )
			{
				RemovePlayerItemExUsed(playerid, PHaveItem( playerid, 1, 40 ), SlotParam6( playerid, PHaveItem( playerid, 1, 36 ) ) );
				DynamicFactions[fID][WFactory127MMAmmo] += gunAmmo;
			}
			SaveFData( fID, "WFactory127MMAmmo" );
		}
	}
	return 0;
}

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

public TogglePlayerUnControllable( playerid, Float:x, Float:y, Float:z )
{
	new Float:px, Float:py, Float:pz;
	GetPlayerPos( playerid, px, py, pz );
	if( pz < z )
		SetTimerEx("TogglePlayerUnControllable", 50, false, "dfff", playerid, px, py, pz );
	else
		TogglePlayerControllable(playerid, 0);
	return 1;
}

RemovePlayerMapIcons( playerid, type )
{
	RemovePlayerMapIcon( playerid, 0 );
	RemovePlayerMapIcon( playerid, 1 );
	RemovePlayerMapIcon( playerid, 2 );
	RemovePlayerMapIcon( playerid, 3 );
	RemovePlayerMapIcon( playerid, 4 );
	RemovePlayerMapIcon( playerid, 5 );
	RemovePlayerMapIcon( playerid, 6 );
	RemovePlayerMapIcon( playerid, 7 );
	RemovePlayerMapIcon( playerid, 8 );
	RemovePlayerMapIcon( playerid, 9 );
	RemovePlayerMapIcon( playerid, 10 );
	RemovePlayerMapIcon( playerid, 11 );
	RemovePlayerMapIcon( playerid, 12 );
	RemovePlayerMapIcon( playerid, 13 );
	RemovePlayerMapIcon( playerid, 14 );
	RemovePlayerMapIcon( playerid, 15 );
	RemovePlayerMapIcon( playerid, 16 );
	RemovePlayerMapIcon( playerid, 17 );
	return 1;
}

ShowPlayerMapIcons( playerid, type )
{
	SetPlayerMapIcon(playerid, 0, 1374.0, 405.0, 20.0, 56, 0, MAPICON_GLOBAL ); // urzad MG
	SetPlayerMapIcon(playerid, 1, 1241.0, 326.0, 20.0, 22, 0, MAPICON_LOCAL ); // szpital MG
	SetPlayerMapIcon(playerid, 2, 1393.0, 423.0, 20.0, 36, 0, MAPICON_LOCAL ); // szkola zawodowa MG
	SetPlayerMapIcon(playerid, 3, 1228.0, 182.0, 20.0, 27, 0, MAPICON_LOCAL ); // warsztat MG
	SetPlayerMapIcon(playerid, 4, 1881.0, 348.0, 21.0, 30, 0, MAPICON_LOCAL ); // policja MG/PC
	SetPlayerMapIcon(playerid, 5, 2304.0, -16.0, 26.0, 52, 0, MAPICON_GLOBAL ); // bank PC
	SetPlayerMapIcon(playerid, 6, 1368.0, 248.0, 20.0, 29, 0, MAPICON_LOCAL ); // pizzeria MG
	SetPlayerMapIcon(playerid, 7, 1324.0, 286.0, 20.0, 36, 0, MAPICON_LOCAL ); // prawko MG
	SetPlayerMapIcon(playerid, 8, 627.0, -572.0, 18.0, 30, 0, MAPICON_LOCAL ); // policja DM
	SetPlayerMapIcon(playerid, 9, 204.0, -63.0, 2.0, 18, 0, MAPICON_LOCAL ); // fabryka broni DM
	SetPlayerMapIcon(playerid, 10, -1036.0, -666.0, 32.0, 34, 0, MAPICON_LOCAL ); // rafineria SF
	SetPlayerMapIcon(playerid, 11, -1061.0, -1196.0, 130.0, 46, 0, MAPICON_LOCAL ); // farmer
	SetPlayerMapIcon(playerid, 12, 1362.0, 348.0, 21.0, 56, 0, MAPICON_LOCAL ); // basen
	SetPlayerMapIcon(playerid, 13, 1341.0, 389.0, 20.0, 34, 0, MAPICON_LOCAL ); // siedziba rafinerii
	SetPlayerMapIcon(playerid, 14, 1338.0, 381.0, 20.0, 6, 0, MAPICON_LOCAL ); // strzelnica
	SetPlayerMapIcon(playerid, 15, 1405.0, 239.0, 20.0, 55, 0, MAPICON_LOCAL ); // salon samochodowy MG
	SetPlayerMapIcon(playerid, 16, 1288.0, 168.0, 20.0, 31, 0, MAPICON_LOCAL ); // tania strefa mieszkalna
	SetPlayerMapIcon(playerid, 17, 2352.0, 46.0, 26.0, 32, 0, MAPICON_LOCAL ); // droga strefa mieszkalna
	
	// if( type == ICONS_ADVANCED )
	// {
		// SetPlayerMapIcon(playerid, 0, Float:x, Float:y, Float:z, 56, 0, MAPICON_GLOBAL )
	// }
	return 1;
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

// CreateCustomObject( playerid, model, Float:objX, Float:objY, Float:objZ, Float:rX = 0.0, Float:rY = 0.0, Float:rZ = 0.0 )
// {
	// new vw, interior, playername[MAX_PLAYER_NAME], string[128];
	// vw = GetPlayerVirtualWorld(playerid);
	// interior = GetPlayerInterior(playerid);
	// GetPlayerName( playerid, playername, MAX_PLAYER_NAME );
	// for( new i = 0; i < sizeof(gCustomObj); i++ )
	// {
		// if( !gCustomObj[i][cstSlotUsed] )
		// {
			// gCustomObj[i][cstObjID] = CreateDynamicObject( model, objX, objY, objZ, rX, rY, rZ, vw, interior );
			// gCustomObj[i][cstObjModel] = model;
			// gCustomObj[i][cstObjVW] = vw;
			// gCustomObj[i][cstObjInt] = interior;
			// gCustomObj[i][cstSlotUsed] = true;
			// format( gCustomObj[i][cstObjOwner], MAX_PLAYER_NAME, "%s", playername );
			// if(	!gCustomObjShow )
			// {
				// gCustomObj[i][cstText3dID] = Create3DTextLabel(" ", COLOR_LIGHTBLUE, objX, objY, objZ, 100.0, vw, 0);
				// gCustomObj[i][cstText3dID2] = Create3DTextLabel(" ", COLOR_LIGHTBLUE, objX, objY, objZ-0.2, 100.0, vw, 0);
				// gCustomObj[i][cstText3dID3] = Create3DTextLabel(" ", COLOR_LIGHTBLUE, objX, objY, objZ-0.4, 100.0, vw, 0);
				// gCustomObj[i][cstText3dID4] = Create3DTextLabel(" ", COLOR_LIGHTBLUE, objX, objY, objZ+0.2, 100.0, vw, 0);
				// gCustomObj[i][cstDscShow] = 0;
			// }
			// else
			// {
				// format(string, sizeof(string), "objID = %d | objModel = %d | objSlot = %d", gCustomObj[i][cstObjID], gCustomObj[i][cstObjModel], i );
				// gCustomObj[i][cstText3dID] = Create3DTextLabel(string, COLOR_LIGHTBLUE, objX, objY, objZ, 100.0, vw, 0);
				// format(string, sizeof(string), "objIX = %f | objY = %f | objZ = %f", objX, objY, objZ );
				// gCustomObj[i][cstText3dID2] = Create3DTextLabel(string, COLOR_LIGHTBLUE, objX, objY, objZ-0.2, 100.0, vw, 0);
				// format(string, sizeof(string), "objIRX = %f | objRY = %f | objRZ = %f", rX, rY, rZ );
				// gCustomObj[i][cstText3dID3] = Create3DTextLabel(string, COLOR_LIGHTBLUE, objX, objY, objZ-0.4, 100.0, vw, 0);
				// format(string, sizeof(string), "made by: %s", gCustomObj[i][cstObjOwner] );
				// gCustomObj[i][cstText3dID4] = Create3DTextLabel(string, COLOR_LIGHTBLUE, objX, objY, objZ+0.2, 100.0, vw, 0);
				// gCustomObj[i][cstDscShow] = 1;
			// }
			// SaveObjData(i);
			// return 1;
		// }
	// }
	// return 0;
// }

// RemoveCustomObject( objectID )
// {
	// for( new i = 0; i < sizeof(gCustomObj); i++ )
	// {
		// if( gCustomObj[i][cstSlotUsed] && gCustomObj[i][cstObjID] == objectID )
		// {
			// Delete3DTextLabel( gCustomObj[i][cstText3dID] );
			// Delete3DTextLabel( gCustomObj[i][cstText3dID2] );
			// Delete3DTextLabel( gCustomObj[i][cstText3dID3] );
			// Delete3DTextLabel( gCustomObj[i][cstText3dID4] );
			// DestroyDynamicObject( gCustomObj[i][cstObjID] );			
			// gCustomObj[i][cstObjID] = 0;	
			// gCustomObj[i][cstSlotUsed] = false;
			// gCustomObj[i][cstObjModel] = 0;
			// gCustomObj[i][cstObjVW] = 0;
			// gCustomObj[i][cstObjInt] = 0;			
			// gCustomObj[i][cstDscShow] = 0;
			// strdel( gCustomObj[i][cstObjOwner], 0, MAX_PLAYER_NAME );
			// SaveObjData(i);
			// return 1;
		// }
	// }
	// return 0;
// }

// MoveCustomObject( objectID, Float:mx, Float:my, Float:mz )
// {
	// for( new i = 0; i < sizeof(gCustomObj); i++ )
	// {
		// if( gCustomObj[i][cstSlotUsed] && gCustomObj[i][cstObjID] == objID )
		// {
			// vw = GetPlayerVirtualWorld(playerid);
			// GetDynamicObjectPos( objID, ox, oy, oz );
			// SetDynamicObjectPos( objID, ox+mx, oy+my, oz+mz );
			// GetDynamicObjectRot( objID, rx, ry, rz );
			// Delete3DTextLabel( gCustomObj[i][cstText3dID] );
			// Delete3DTextLabel( gCustomObj[i][cstText3dID2] );
			// Delete3DTextLabel( gCustomObj[i][cstText3dID3] );
			// Delete3DTextLabel( gCustomObj[i][cstText3dID4] );
			// if( gCustomObjShow )
			// {
				// format(string, sizeof(string), "objID = %d | objModel = %d | objSlot = %d", gCustomObj[i][cstObjID], gCustomObj[i][cstObjModel], i );
				// gCustomObj[i][cstText3dID] = Create3DTextLabel(string, COLOR_LIGHTBLUE, ox+mx, oy+my, oz+mz, 100.0, vw, 0);
				// format(string, sizeof(string), "objIX = %f | objY = %f | objZ = %f", ox+mx, oy+my, oz+mz );
				// gCustomObj[i][cstText3dID2] = Create3DTextLabel(string, COLOR_LIGHTBLUE, ox+mx, oy+my, oz+mz-0.2, 100.0, vw, 0);
				// format(string, sizeof(string), "objIRX = %f | objRY = %f | objRZ = %f", rx, ry, rz );
				// gCustomObj[i][cstText3dID3] = Create3DTextLabel(string, COLOR_LIGHTBLUE, ox+mx, oy+my, oz+mz-0.4, 100.0, vw, 0);
				// format(string, sizeof(string), "made by: %s", gCustomObj[i][cstObjOwner] );
				// gCustomObj[i][cstText3dID4] = Create3DTextLabel(string, COLOR_LIGHTBLUE, ox+mx, oy+my, oz+mz+0.2, 100.0, vw, 0);
				// gCustomObj[i][cstDscShow] = 1;
			// }
			// else
			// {
				// gCustomObj[i][cstText3dID] = Create3DTextLabel(" ", COLOR_LIGHTBLUE, ox+mx, oy+my, oz+mz, 100.0, vw, 0);
				// gCustomObj[i][cstText3dID2] = Create3DTextLabel(" ", COLOR_LIGHTBLUE, ox+mx, oy+my, oz+mz-0.2, 100.0, vw, 0);
				// gCustomObj[i][cstText3dID3] = Create3DTextLabel(" ", COLOR_LIGHTBLUE, ox+mx, oy+my, oz+mz-0.4, 100.0, vw, 0);
				// gCustomObj[i][cstText3dID4] = Create3DTextLabel(" ", COLOR_LIGHTBLUE, ox+mx, oy+my, oz+mz+0.2, 100.0, vw, 0);
				// gCustomObj[i][cstDscShow] = 0;
			// }
			// SaveObjData(i);
			// GetPlayerName(playerid, string, sizeof(string));
			// printf("[WARNING:] %s used /movobj for obj %d, slot %d", string, gCustomObj[i][cstObjID], i);
			// return 1;
		// }
	// }
// }

ResetBizData(bID, type)
{
	// type 0 - reset all data
	// type 1 - removes owner, etc, just prepare for next buyer
	
	DestroyDynamicPickup(Businesses[bID][PickupID]);
	
	strdel(Businesses[bID][Owner], 0, 128);
	format(Businesses[bID][Owner], 128, "None");
	Businesses[bID][Owned] = 0;
	Businesses[bID][BizPrice] = 0;
	Businesses[bID][EntranceCost] = 0;
	Businesses[bID][Till] = 0;
	Businesses[bID][Locked] = 0;
	Businesses[bID][BizType] = 0;
	Businesses[bID][Products] = 0;
	Businesses[bID][VehicleSpawned] = 0;
	Businesses[bID][VehicleCount] = 0;
	Businesses[bID][MaxVehicles] = 5;
	Businesses[bID][VehicleOrderCount] = 0;
	Businesses[bID][SalesJob] = 0;
	Businesses[bID][W9MM] = 0;
	Businesses[bID][W9MMSil] = 0;
	Businesses[bID][WDesEagle] = 0;
	Businesses[bID][WMicroSMG] = 0;
	Businesses[bID][WMP5] = 0;
	Businesses[bID][WTec9] = 0;
	Businesses[bID][WShotgun] = 0;
	Businesses[bID][WAK47] = 0;
	Businesses[bID][WM4] = 0;
	Businesses[bID][WRifle] = 0;
	Businesses[bID][WSRifle] = 0;
	Businesses[bID][W9MMAmmo] = 0;
	Businesses[bID][W50AEAmmo] = 0;
	Businesses[bID][WBuckshot] = 0;
	Businesses[bID][W762MMAmmo] = 0;
	Businesses[bID][W127MMAmmo] = 0;
	Businesses[bID][BRadio1Bought] = 0;
	Businesses[bID][BRadio1On] = 0;
	Businesses[bID][BRadio1Ch] = 0;
	Businesses[bID][BRadio1Obj] = 0;
	Businesses[bID][BRadio1Vol] = 100;
	Businesses[bID][Product1Price] = 0;
	Businesses[bID][Product2Price] = 0;
	Businesses[bID][Product3Price] = 0;
	Businesses[bID][Product4Price] = 0;
	Businesses[bID][Product5Price] = 0;
	Businesses[bID][Product6Price] = 0;
	Businesses[bID][Product7Price] = 0;
	Businesses[bID][Product8Price] = 0;
	Businesses[bID][Product9Price] = 0;
	Businesses[bID][Product10Price] = 0;
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
	
	SaveBizData(bID, "Owner");
	SaveBizData(bID, "Owned");
	SaveBizData(bID, "BizPrice");
	SaveBizData(bID, "EntranceCost");
	SaveBizData(bID, "Till");
	SaveBizData(bID, "Locked");
	SaveBizData(bID, "BizType");
	SaveBizData(bID, "Products");
	SaveBizData(bID, "VehicleSpawned");
	SaveBizData(bID, "VehicleCount");
	SaveBizData(bID, "MaxVehicles");
	SaveBizData(bID, "VehicleOrderCount");
	SaveBizData(bID, "SalesJob");
	SaveBizData(bID, "W9MM");
	SaveBizData(bID, "W9MMSil");
	SaveBizData(bID, "WDesEagle");
	SaveBizData(bID, "WMicroSMG");
	SaveBizData(bID, "WMP5");
	SaveBizData(bID, "WTec9");
	SaveBizData(bID, "WShotgun");
	SaveBizData(bID, "WAK47");
	SaveBizData(bID, "WM4");
	SaveBizData(bID, "WRifle");
	SaveBizData(bID, "WSRifle");
	SaveBizData(bID, "W9MMAmmo");
	SaveBizData(bID, "W50AEAmmo");
	SaveBizData(bID, "WBuckshot");
	SaveBizData(bID, "W762MMAmmo");
	SaveBizData(bID, "W127MMAmmo");
	SaveBizData(bID, "BRadio1Bought");
	SaveBizData(bID, "BRadio1On");
	SaveBizData(bID, "BRadio1Ch");
	SaveBizData(bID, "BRadio1Obj");
	SaveBizData(bID, "BRadio1Vol");
	SaveBizData(bID, "Product1Price");
	SaveBizData(bID, "Product2Price");
	SaveBizData(bID, "Product3Price");
	SaveBizData(bID, "Product4Price");
	SaveBizData(bID, "Product5Price");
	SaveBizData(bID, "Product6Price");
	SaveBizData(bID, "Product7Price");
	SaveBizData(bID, "Product8Price");
	SaveBizData(bID, "Product9Price");
	SaveBizData(bID, "Product10Price");
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
	SaveBizData(bID, "BConfiscated");
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
}

ResetHouseData(hID, type)
{
	// type 0 - reset all data
	// type 1 - removes owner, etc, just prepare for next buyer
	
	DestroyDynamicPickup(Houses[hID][PickupID]);
	
	strdel(Houses[hID][Description], 0, 128);
	format(Houses[hID][Owner], 128, "Brak");
	Houses[hID][Owned] = 0;
	Houses[hID][Rentable] = 0;
	Houses[hID][RentCost] = 0;
	Houses[hID][Locked] = 0;
	Houses[hID][HConfiscated] = 0;
	Houses[hID][HouseType] = 0;
	
	SaveHouseData(hID, "Description");
	SaveHouseData(hID, "Owner");
	SaveHouseData(hID, "Owned");
	SaveHouseData(hID, "Rentable");
	SaveHouseData(hID, "RentCost");
	SaveHouseData(hID, "Locked");
	SaveHouseData(hID, "HConfiscated");
	SaveHouseData(hID, "Type");
	
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
		Houses[hID][Materials] = 0;
		Houses[hID][Drugs] = 0;
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
		PlayerToPoint(2.0, playerid, gWheelChangePos[pos4X], gWheelChangePos[pos4Y], gWheelChangePos[pos4Z]))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

stock ResumeCarRadioStation(playerid, stationid)
{
	new adres[256];
	if(CarRadioID[playerid] != 255)
		Audio_Stop(playerid, CarRadioID[playerid]);

	switch(stationid)
	{
		case 1: adres = "http://radioparty.pl/play/glowny_48.m3u";
		case 2: adres = "http://radioparty.pl/play/djmixes_64aac.m3u";
		case 3: adres = "http://radioparty.pl/play/house_64aac.m3u";
		case 4: adres = "http://radioparty.pl/play/trance_64aac.m3u";
		case 5: adres = "http://radioparty.pl/play/vtrance_64aac.m3u";
		case 6: adres = "http://radioparty.pl/play/dnb_64aac.m3u";
		case 7: adres = "http://radioparty.pl/play/hard_64aac.m3u";
		case 8: adres = "http://radioparty.pl/play/chillout_64aac.m3u";
		case 9: adres = "http://www.radiozet.pl/externals/radiozet-streams/radiozet_stream.pls";
		case 10: adres = "http://www.miastomuzyki.pl/odbior/rmfcl_aacp.pls";
		case 11: adres = "http://www.miastomuzyki.pl/odbior/rmf_aacp.pls";
		case 12: adres = "http://wroclaw.radio.pionier.net.pl:8000/pl/eskarock.mp3.m3u";
		default: return 0;
	}
	CarRadioID[playerid] = Audio_PlayStreamed(playerid, adres, false, true, false);
	Audio_SetVolume(playerid, CarRadioID[playerid], gVehData[GetPlayerVehicleID(playerid)-1][RadioVol] );
	return 1;
}

stock ResumeHouseRadioStation(playerid, hid, stationid)
{
	new adres[256];
	if( Houses[hid][HRadio1On] )
		Audio_Stop(playerid, CarRadioID[playerid]);

	switch(stationid)
	{
		case 1: adres = "http://radioparty.pl/play/glowny_48.m3u";
		case 2: adres = "http://radioparty.pl/play/djmixes_64aac.m3u";
		case 3: adres = "http://radioparty.pl/play/house_64aac.m3u";
		case 4: adres = "http://radioparty.pl/play/trance_64aac.m3u";
		case 5: adres = "http://radioparty.pl/play/vtrance_64aac.m3u";
		case 6: adres = "http://radioparty.pl/play/dnb_64aac.m3u";
		case 7: adres = "http://radioparty.pl/play/hard_64aac.m3u";
		case 8: adres = "http://radioparty.pl/play/chillout_64aac.m3u";
		case 9: adres = "http://www.radiozet.pl/externals/radiozet-streams/radiozet_stream.pls";
		case 10: adres = "http://www.miastomuzyki.pl/odbior/rmfcl_aacp.pls";
		case 11: adres = "http://www.miastomuzyki.pl/odbior/rmf_aacp.pls";
		case 12: adres = "http://wroclaw.radio.pionier.net.pl:8000/pl/eskarock.mp3.m3u";
		default: return 0;
	}
	Houses[hid][HRadio1ID][playerid] = Audio_PlayStreamed(playerid, adres, false, true, false);
	Audio_Set3DPosition(playerid,  Houses[hid][HRadio1ID][playerid],  Houses[hid][HRadio1X], Houses[hid][HRadio1Y], Houses[hid][HRadio1Z], 30.0);
	return 1;
}

stock ResumeBizRadioStation(playerid, hid)
{
	new adres[256];
	switch( Businesses[hid][BRadio1Ch] )
	{
		case 1: adres = "http://radioparty.pl/play/glowny_48.m3u";
		case 2: adres = "http://radioparty.pl/play/djmixes_64aac.m3u";
		case 3: adres = "http://radioparty.pl/play/house_64aac.m3u";
		case 4: adres = "http://radioparty.pl/play/trance_64aac.m3u";
		case 5: adres = "http://radioparty.pl/play/vtrance_64aac.m3u";
		case 6: adres = "http://radioparty.pl/play/dnb_64aac.m3u";
		case 7: adres = "http://radioparty.pl/play/hard_64aac.m3u";
		case 8: adres = "http://radioparty.pl/play/chillout_64aac.m3u";
		case 9: adres = "http://www.radiozet.pl/externals/radiozet-streams/radiozet_stream.pls";
		case 10: adres = "http://www.miastomuzyki.pl/odbior/rmfcl_aacp.pls";
		case 11: adres = "http://www.miastomuzyki.pl/odbior/rmf_aacp.pls";
		case 12: adres = "http://wroclaw.radio.pionier.net.pl:8000/pl/eskarock.mp3.m3u";
		default: return 0;
	}
	if( GetPlayerVirtualWorld(playerid) == hid )
	{
		if(Businesses[hid][BRadio1ID][playerid] != 255)
			Audio_Stop(playerid, Businesses[hid][BRadio1ID][playerid] );
		Businesses[hid][BRadio1ID][playerid] = Audio_PlayStreamed(playerid, adres, false, true, true);
		Audio_SetVolume(playerid, Businesses[hid][BRadio1ID][playerid], Businesses[hid][BRadio1Vol]);
		// Audio_Set3DPosition(playerid, Businesses[hid][BRadio1ID][playerid], Businesses[hid][BRadio1X], Businesses[hid][BRadio1Y], Businesses[hid][BRadio1Z], 100.0);
	}
	return 1;
}

stock ChangeCarRadioVolume( vehicleid, volume )
{
	gVehData[vehicleid-1][RadioVol] = volume;
	foreach(Player, i )
	{
		if(IsPlayerInVehicle(i, vehicleid))
			Audio_SetVolume(i, CarRadioID[i], volume);
	}
	return 1;
}

stock ChangeHouseRadioVolume( hid, volume )
{
	foreach(Player, i )
	{
		Audio_SetVolume(i, Houses[hid][HRadio1ID][i], volume);
		Houses[hid][HRadio1Vol] = volume;
		SaveHouseData( hid, "HRadio1Vol" );
	}
	return 1;
}

stock ChangeBizRadioVolume( hid, volume )
{
	foreach(Player, i )
	{
		Audio_SetVolume(i, Businesses[hid][BRadio1ID][i], volume);
		Businesses[hid][BRadio1Vol] = volume;
		SaveHouseData( hid, "BRadio1Vol" );
	}
	return 1;
}

stock PlayerPHouseRadio( playerid, hid )
{
	new adres[256];
	switch( Houses[hid][HRadio1Ch] )
	{
		case 1: adres = "http://radioparty.pl/play/glowny_48.m3u";
		case 2: adres = "http://radioparty.pl/play/djmixes_64aac.m3u";
		case 3: adres = "http://radioparty.pl/play/house_64aac.m3u";
		case 4: adres = "http://radioparty.pl/play/trance_64aac.m3u";
		case 5: adres = "http://radioparty.pl/play/vtrance_64aac.m3u";
		case 6: adres = "http://radioparty.pl/play/dnb_64aac.m3u";
		case 7: adres = "http://radioparty.pl/play/hard_64aac.m3u";
		case 8: adres = "http://radioparty.pl/play/chillout_64aac.m3u";
		case 9: adres = "http://www.radiozet.pl/externals/radiozet-streams/radiozet_stream.pls";
		case 10: adres = "http://www.miastomuzyki.pl/odbior/rmfcl_aacp.pls";
		case 11: adres = "http://www.miastomuzyki.pl/odbior/rmf_aacp.pls";
		case 12: adres = "http://wroclaw.radio.pionier.net.pl:8000/pl/eskarock.mp3.m3u";
		default: return 0;
	}
	if( GetPlayerVirtualWorld(playerid) == hid )
	{
		if(Houses[hid][HRadio1ID][playerid] != 255)
			Audio_Stop(playerid, Houses[hid][HRadio1ID][playerid] );
		Houses[hid][HRadio1ID][playerid] = Audio_PlayStreamed(playerid, adres, false, true, true);
		Audio_SetVolume(playerid, Houses[hid][HRadio1ID][playerid], Houses[hid][HRadio1Vol]);
		Audio_Set3DPosition(playerid, Houses[hid][HRadio1ID][playerid], Houses[hid][HRadio1X], Houses[hid][HRadio1Y], Houses[hid][HRadio1Z], 30.0);
	}
	return 1;
}

stock PlayBizRadio( hid, stationid, vw )
{
	new adres[256];
	switch(stationid)
	{
		case 1: adres = "http://radioparty.pl/play/glowny_48.m3u";
		case 2: adres = "http://radioparty.pl/play/djmixes_64aac.m3u";
		case 3: adres = "http://radioparty.pl/play/house_64aac.m3u";
		case 4: adres = "http://radioparty.pl/play/trance_64aac.m3u";
		case 5: adres = "http://radioparty.pl/play/vtrance_64aac.m3u";
		case 6: adres = "http://radioparty.pl/play/dnb_64aac.m3u";
		case 7: adres = "http://radioparty.pl/play/hard_64aac.m3u";
		case 8: adres = "http://radioparty.pl/play/chillout_64aac.m3u";
		case 9: adres = "http://www.radiozet.pl/externals/radiozet-streams/radiozet_stream.pls";
		case 10: adres = "http://www.miastomuzyki.pl/odbior/rmfcl_aacp.pls";
		case 11: adres = "http://www.miastomuzyki.pl/odbior/rmf_aacp.pls";
		case 12: adres = "http://wroclaw.radio.pionier.net.pl:8000/pl/eskarock.mp3.m3u";
		default: return 0;
	}
	foreach(Player, i )
	{
		if( GetPlayerVirtualWorld(i) == vw )
		{
			if(Businesses[hid][BRadio1ID][i] != 255)
				Audio_Stop(i, Businesses[hid][BRadio1ID][i] );
			Businesses[hid][BRadio1ID][i] = Audio_PlayStreamed(i, adres, false, true, true);
			Audio_SetVolume(i, Businesses[hid][BRadio1ID][i], Businesses[hid][BRadio1Vol]);
			// Audio_Set3DPosition(i,  Businesses[hid][BRadio1ID][i],  Businesses[hid][BRadio1X], Businesses[hid][BRadio1Y], Businesses[hid][BRadio1Z], 100.0);
		}
	}
	return 1;
}

stock PlayHouseRadio( hid, stationid, vw )
{
	new adres[256];
	switch(stationid)
	{
		case 1: adres = "http://radioparty.pl/play/glowny_48.m3u";
		case 2: adres = "http://radioparty.pl/play/djmixes_64aac.m3u";
		case 3: adres = "http://radioparty.pl/play/house_64aac.m3u";
		case 4: adres = "http://radioparty.pl/play/trance_64aac.m3u";
		case 5: adres = "http://radioparty.pl/play/vtrance_64aac.m3u";
		case 6: adres = "http://radioparty.pl/play/dnb_64aac.m3u";
		case 7: adres = "http://radioparty.pl/play/hard_64aac.m3u";
		case 8: adres = "http://radioparty.pl/play/chillout_64aac.m3u";
		case 9: adres = "http://www.radiozet.pl/externals/radiozet-streams/radiozet_stream.pls";
		case 10: adres = "http://www.miastomuzyki.pl/odbior/rmfcl_aacp.pls";
		case 11: adres = "http://www.miastomuzyki.pl/odbior/rmf_aacp.pls";
		case 12: adres = "http://wroclaw.radio.pionier.net.pl:8000/pl/eskarock.mp3.m3u";
		default: return 0;
	}
	foreach(Player, i )
	{
		if( GetPlayerVirtualWorld(i) == vw )
		{
			if(Houses[hid][HRadio1ID][i] != 255)
				Audio_Stop(i, Houses[hid][HRadio1ID][i] );
			Houses[hid][HRadio1ID][i] = Audio_PlayStreamed(i, adres, false, true, true);
			Audio_SetVolume(i, Houses[hid][HRadio1ID][i], Houses[hid][HRadio1Vol]);
			Audio_Set3DPosition(i,  Houses[hid][HRadio1ID][i],  Houses[hid][HRadio1X], Houses[hid][HRadio1Y], Houses[hid][HRadio1Z], 30.0);
		}
	}
	return 1;
}

stock StopBizRadioStation(hid)
{
	Businesses[hid][BRadio1On] = 0;
	SaveBizData( hid, "BRadio1On" );
	foreach(Player, i )
	{
		if( Businesses[hid][BRadio1ID][i] != 255 )
			Audio_Stop( i, Businesses[hid][BRadio1ID][i] );
		Businesses[hid][BRadio1ID][i] = 255;
	}
	return 1;
}

stock StopHouseRadioStation(hid)
{
	Houses[hid][HRadio1On] = 0;
	SaveHouseData( hid, "HRadio1On" );
	foreach(Player, i )
	{
		if( Houses[hid][HRadio1ID][i] != 255 )
			Audio_Stop( i, Houses[hid][HRadio1ID][i] );
		Houses[hid][HRadio1ID][i] = 255;
	}
	return 1;
}

stock PlayCarRadioStation(playerid, stationid, vehicleid)
{
	new adres[256];
	if(CarRadioID[playerid] != 255)
		Audio_Stop(playerid, CarRadioID[playerid]);

	switch(stationid)
	{
		case 1: adres = "http://radioparty.pl/play/glowny_48.m3u";
		case 2: adres = "http://radioparty.pl/play/djmixes_64aac.m3u";
		case 3: adres = "http://radioparty.pl/play/house_64aac.m3u";
		case 4: adres = "http://radioparty.pl/play/trance_64aac.m3u";
		case 5: adres = "http://radioparty.pl/play/vtrance_64aac.m3u";
		case 6: adres = "http://radioparty.pl/play/dnb_64aac.m3u";
		case 7: adres = "http://radioparty.pl/play/hard_64aac.m3u";
		case 8: adres = "http://radioparty.pl/play/chillout_64aac.m3u";
		case 9: adres = "http://www.radiozet.pl/externals/radiozet-streams/radiozet_stream.pls";
		case 10: adres = "http://www.miastomuzyki.pl/odbior/rmfcl_aacp.pls";
		case 11: adres = "http://www.miastomuzyki.pl/odbior/rmf_aacp.pls";
		case 12: adres = "http://wroclaw.radio.pionier.net.pl:8000/pl/eskarock.mp3.m3u";
		default: return 0;
	}
	CarRadioID[playerid] = Audio_PlayStreamed(playerid, adres, false, true, false);
	Audio_SetVolume(playerid, CarRadioID[playerid], gVehData[vehicleid-1][RadioVol] );
	gVehData[vehicleid-1][RadioOn] = stationid;
	SaveVehData(vehicleid-1, "RadioOn");
	foreach(Player, i )
	{
		if(i == playerid)
			continue;

		if(IsPlayerInVehicle(i, vehicleid))
		{
			Audio_Stop(i, CarRadioID[i]);
			CarRadioID[i] = Audio_PlayStreamed(i, adres, false, true, false);
		}
	}
	return 1;
}

stock StopCarRadioStation(vehicleid)
{
	if(gVehData[vehicleid-1][RadioOn] != 0)
	{
		gVehData[vehicleid-1][RadioOn] = 0;
		SaveVehData(vehicleid-1, "RadioOn");
	}
	foreach(Player, i )
	{
		if(!IsPlayerInVehicle(i, vehicleid))
			continue;

		Audio_Stop(i, CarRadioID[i]);
		CarRadioID[i] = 255;
	}
	return 1;
}
