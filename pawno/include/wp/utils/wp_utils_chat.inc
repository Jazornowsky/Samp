/***
*
* File: wp_utils_chat.inc
* Auth: Damian Wojdat
* Date: 22.11.2011
* Desc: Internal script function related to chat.
*
*************************************************************************************************************/

BroadCast(color,const string[])
{
	SendClientMessageToAll(color, string);
	return 1;
}

ABroadCast(color,const string[],level)
{
	for(new i = 0; i < CUSTOM_MAX_PLAYERS; i++)
	{
		if(IsPlayerConnected(i))
		{
			if (gPlayerData[i][pAdmin] >= level)
			{
				SendClientMessage(i, color, string);
				printf("%s", string);
			}
		}
	}
	return 1;
}

SendAdminMessage(color, string[])
{
	for(new i = 0; i < CUSTOM_MAX_PLAYERS; i++)
	{
		if(IsPlayerConnected(i))
		{
		    if(gPlayerData[i][pAdmin] >= 1)
		    {
				SendClientMessage(i, color, string);
			}
		}
	}
}

SendModMessage(color, string[])
{
	for(new i = 0; i < CUSTOM_MAX_PLAYERS; i++)
	{
		if(IsPlayerConnected(i))
		{
		    if(gPlayerData[i][pModerator] >= 1)
		    {
				SendClientMessage(i, color, string);
			}
		}
	}
}

SendJobMessage(job, color, string[])
{
	for(new i = 0; i < CUSTOM_MAX_PLAYERS; i++)
	{
		if(IsPlayerConnected(i))
		{
		    if(gPlayerData[i][pJob] == job)
		    {
				SendClientMessage(i, color, string);
			}
		}
	}
}

SendCBMessage(chanel, string[])
{
	new form[128], slot[MAX_PLAYER_ITEM_SLOT], vehid;
	format(form, sizeof(form), "[RADIO]: %s", string);
	foreach(Player, i)
	{
		if(!gPlayerLogged[i])
			continue;
		PHaveItemEx(i, 3, 2, slot);
		for(new j = 0; j < MAX_PLAYER_ITEM_SLOT; j++)
		{
			if(slot[j])
			{
				if(SlotParam1(i, j+1) && SlotParam2(i, j+1) == chanel)
					ProxDetector(20.0, i, form, COLOR_FADE1, COLOR_FADE2, COLOR_FADE3, COLOR_FADE4, COLOR_FADE5);
			}
		}
		PHaveItemEx(i, 3, 13, slot);
		for(new j = 0; j < MAX_PLAYER_ITEM_SLOT; j++)
		{
			if(slot[j])
			{
				if(SlotParam1(i, j+1) && SlotParam2(i, j+1) == chanel)
					ProxDetector(20.0, i, form, COLOR_FADE1, COLOR_FADE2, COLOR_FADE3, COLOR_FADE4, COLOR_FADE5);
			}
		}
		vehid = GetPlayerVehicleID(i);
		if(vehid != 0)
		{
			if(gVehData[vehid-1][VCBRadio] && gVehData[vehid-1][VCBRadioStatus] && gVehData[vehid-1][VCBRadioChanel] == chanel)
				ProxDetector(20.0, i, form, COLOR_FADE1, COLOR_FADE2, COLOR_FADE3, COLOR_FADE4, COLOR_FADE5);
		}
	}
}

SendFactionMessage(faction, color, string[])
{
	new vehicleID;
	for(new i = 0; i < CUSTOM_MAX_PLAYERS; i++)
	{
		if(IsPlayerConnected(i))
		{
			if(!BigEar[i])
			{
				if(gPlayerData[i][pFaction] != 255)
				{
					if(IsPlayerInAnyVehicle(i))
					{
						vehicleID = GetPlayerVehicleID(i);
						if(gPlayerData[i][pFaction] == faction)
						{
							if(gVehData[vehicleID-1][mVehFaction] == faction || PHaveItem(i, 3, 2) > 0)
							{
								SendClientMessage(i, color, string);
							}
						}
					}
					else if(PHaveItem(i, 3, 2) > 0 && gPlayerData[i][pFaction] == faction)
					{
						SendClientMessage(i, color, string);
					}
				}
			}
			else
				SendClientMessage(i, color, string);				
		}
	}
}

SendFactionTypeMessage(factiontype, color, string[])
{
	new vehicleID;
	for(new i = 0; i < CUSTOM_MAX_PLAYERS; i++)
	{
		if(IsPlayerConnected(i))
		{
			if(!BigEar[i])
			{
				if(gPlayerData[i][pFaction] != 255)
				{
					if(IsPlayerInAnyVehicle(i))
					{
						vehicleID = GetPlayerVehicleID(i);
						if(DynamicFactions[gPlayerData[i][pFaction]][fType] == factiontype)
						{
							if(gVehData[vehicleID-1][mVehFaction] == gPlayerData[i][pFaction] || PHaveItem(i, 3, 2) > 0)
							{
								SendClientMessage(i, color, string);
							}
						}
					}
					else if(PHaveItem(i, 3, 2) > 0 && DynamicFactions[gPlayerData[i][pFaction]][fType] == factiontype)
					{
						SendClientMessage(i, color, string);
					}
				}
			}
			else
				SendClientMessage(i, color, string);
		}
	}
}

PlayerActionMessage(playerid,Float:radius,message[])
{
	//This is for messages like "Blah has opened the door".
	static string[256], part1[86], part2[86];
	strdel(string, 0, sizeof(string));
	strdel(part1, 0, sizeof(part1));
	strdel(part2, 0, sizeof(part2));
	new Year, Month, Day, Hour, Minute, Second;
	getdate(Year, Month, Day);
	gettime(Hour, Minute, Second);
	if( strlen(message) > 86 )
	{
		strmid( part1, message, 0, 85 );
		strmid( part2, message, 85, 171 );
		format( string, sizeof(string), "[AKCJA:] %s %s", GetPlayerNameEx(playerid), part1);
		ProxDetector(radius, playerid, string, COLOR_LIGHTBLUE,COLOR_LIGHTBLUE,COLOR_LIGHTBLUE,COLOR_LIGHTBLUE,COLOR_LIGHTBLUE);
		PlayerActionLog(string);
		format( string, sizeof(string), "* %s (( %s ))", GetPlayerNameEx(playerid), part2);
		ProxDetector(radius, playerid, string, COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE);
		PlayerActionLog(string);
	}
	else
	{
		format(string, sizeof(string), "[AKCJA:] %s %s", GetPlayerNameEx(playerid), message);
		ProxDetector(radius, playerid, string, COLOR_LIGHTBLUE,COLOR_LIGHTBLUE,COLOR_LIGHTBLUE,COLOR_LIGHTBLUE,COLOR_LIGHTBLUE);
		PlayerActionLog(string);
	}
	return 1;
}

PlayerPlayerActionMessage(playerid,targetid,Float:radius,message[])
{
	//This is for messages like "Blah has opened the door for Steve".
	new string[128];
	format(string, sizeof(string), "[AKCJA:] %s %s %s.", GetPlayerNameEx(playerid), message,GetPlayerNameEx(targetid));
	ProxDetector(radius, playerid, string, COLOR_LIGHTBLUE,COLOR_LIGHTBLUE,COLOR_LIGHTBLUE,COLOR_LIGHTBLUE,COLOR_LIGHTBLUE);
	PlayerActionLog(string);
	return 1;
}
