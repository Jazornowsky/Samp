/***
*
* File: wp_utils_pickup_event.inc
* Auth: Damian Wojdat
* Date: 17.04.2012
* Desc: Internal script function related to pickup event.
*
*************************************************************************************************************/

stock LoadRandomPickupEvent()
{
	new string[256];
	format(string, sizeof(string), "SELECT `ID` FROM `samp_pickup_events`");
	wp_mysql_query(string, LOAD_RANDOM_PICKUP_EVENT_1, db_con4);
}

stock CreatePickupEventPickups(playerid = -1)
{
	if(playerid == -1)
	{
		if(gPickupEventMapIconID != -1)
			DestroyDynamicMapIcon(gPickupEventMapIconID);
		gPickupEventMapIconID = CreateDynamicMapIcon(gPickupEventCenterPosX, gPickupEventCenterPosY, gPickupEventCenterPosZ, gPickupEventMapIcon, 0, 0, 0, -1, 500.0);
		foreach(Player, i)
		{
			if(!gPlayerLogged[playerid])
				continue;
			if(gPlayerData[i][mPickupEventID] != gPickupEventID)
				ClearPickupEventPickups(i);
			for(new j = 0; j < sizeof(gPickupEventData); j++)
			{
				if(gPlayerVars[i][mPickupEventPickups][j] != -1)
					DestroyDynamicPickup(gPlayerVars[i][mPickupEventPickups][j]);
				if(j < gPickupEventCount && !gPlayerData[i][mPickupEventPickupStatus][j])
					gPlayerVars[i][mPickupEventPickups][j] = CreateDynamicPickup(gPickupEventData[j][mPickupModel], 1, gPickupEventData[j][mPosX], gPickupEventData[j][mPosY], gPickupEventData[j][mPosZ], 0, 0, i);
				else
					gPlayerVars[i][mPickupEventPickups][j] = -1;
			}
		}
	}
	else
	{
		if(gPlayerData[playerid][mPickupEventID] != gPickupEventID)
			ClearPickupEventPickups(playerid);
		for(new j = 0; j < sizeof(gPickupEventData); j++)
		{
			if(gPlayerVars[playerid][mPickupEventPickups][j] != -1)
				DestroyDynamicPickup(gPlayerVars[playerid][mPickupEventPickups][j]);
			if(j < gPickupEventCount && !gPlayerData[playerid][mPickupEventPickupStatus][j])
				gPlayerVars[playerid][mPickupEventPickups][j] = CreateDynamicPickup(gPickupEventData[j][mPickupModel], 1, gPickupEventData[j][mPosX], gPickupEventData[j][mPosY], gPickupEventData[j][mPosZ], 0, 0, playerid);
			else
				gPlayerVars[playerid][mPickupEventPickups][j] = -1;
		}
	}
}

stock ClearPickupEventPickups(playerid = -1)
{
	if(playerid == -1)
	{
		if(gPickupEventMapIconID != -1)
			DestroyDynamicMapIcon(gPickupEventMapIconID);
		for(new i = 0; i < CUSTOM_MAX_PLAYERS; i++)
		{
			gPlayerData[i][mPickupEventID] = gPickupEventID;
			SavePlayerData(i, "PickupEventID");
			gPlayerData[i][mPickupEventRewardReceived] = 0;
			SavePlayerData(i, "PickupEventRewardReceived");
			for(new j = 0; j < sizeof(gPickupEventData); j++)
			{
				if(gPlayerVars[i][mPickupEventPickups][j] != -1)
				{
					DestroyDynamicPickup(gPlayerVars[i][mPickupEventPickups][j]);
					gPlayerVars[i][mPickupEventPickups][j] = -1;
				}
			}
			if(gPlayerData[i][mPickupEventPickupStatus][0])
			{
				gPlayerData[i][mPickupEventPickupStatus][0] = 0;
				SavePlayerData(i, "PickupEventPickupStatus1");
			}
			if(gPlayerData[i][mPickupEventPickupStatus][1])
			{
				gPlayerData[i][mPickupEventPickupStatus][1] = 0;
				SavePlayerData(i, "PickupEventPickupStatus2");
			}
			if(gPlayerData[i][mPickupEventPickupStatus][2])
			{
				gPlayerData[i][mPickupEventPickupStatus][2] = 0;
				SavePlayerData(i, "PickupEventPickupStatus3");
			}
			if(gPlayerData[i][mPickupEventPickupStatus][3])
			{
				gPlayerData[i][mPickupEventPickupStatus][3] = 0;
				SavePlayerData(i, "PickupEventPickupStatus4");
			}
			if(gPlayerData[i][mPickupEventPickupStatus][4])
			{
				gPlayerData[i][mPickupEventPickupStatus][4] = 0;
				SavePlayerData(i, "PickupEventPickupStatus5");
			}
			if(gPlayerData[i][mPickupEventPickupStatus][5])
			{
				gPlayerData[i][mPickupEventPickupStatus][5] = 0;
				SavePlayerData(i, "PickupEventPickupStatus6");
			}
			if(gPlayerData[i][mPickupEventPickupStatus][6])
			{
				gPlayerData[i][mPickupEventPickupStatus][6] = 0;
				SavePlayerData(i, "PickupEventPickupStatus7");
			}
			if(gPlayerData[i][mPickupEventPickupStatus][7])
			{
				gPlayerData[i][mPickupEventPickupStatus][7] = 0;
				SavePlayerData(i, "PickupEventPickupStatus8");
			}
			if(gPlayerData[i][mPickupEventPickupStatus][8])
			{
				gPlayerData[i][mPickupEventPickupStatus][8] = 0;
				SavePlayerData(i, "PickupEventPickupStatus9");
			}
			if(gPlayerData[i][mPickupEventPickupStatus][9])
			{
				gPlayerData[i][mPickupEventPickupStatus][9] = 0;
				SavePlayerData(i, "PickupEventPickupStatus10");
			}
			if(gPlayerData[i][mPickupEventPickupStatus][10])
			{
				gPlayerData[i][mPickupEventPickupStatus][10] = 0;
				SavePlayerData(i, "PickupEventPickupStatus11");
			}
			if(gPlayerData[i][mPickupEventPickupStatus][11])
			{
				gPlayerData[i][mPickupEventPickupStatus][11] = 0;
				SavePlayerData(i, "PickupEventPickupStatus12");
			}
			if(gPlayerData[i][mPickupEventPickupStatus][12])
			{
				gPlayerData[i][mPickupEventPickupStatus][12] = 0;
				SavePlayerData(i, "PickupEventPickupStatus13");
			}
			if(gPlayerData[i][mPickupEventPickupStatus][13])
			{
				gPlayerData[i][mPickupEventPickupStatus][13] = 0;
				SavePlayerData(i, "PickupEventPickupStatus14");
			}
			if(gPlayerData[i][mPickupEventPickupStatus][14])
			{
				gPlayerData[i][mPickupEventPickupStatus][14] = 0;
				SavePlayerData(i, "PickupEventPickupStatus15");
			}
			if(gPlayerData[i][mPickupEventPickupStatus][15])
			{
				gPlayerData[i][mPickupEventPickupStatus][15] = 0;
				SavePlayerData(i, "PickupEventPickupStatus16");
			}
			if(gPlayerData[i][mPickupEventPickupStatus][16])
			{
				gPlayerData[i][mPickupEventPickupStatus][16] = 0;
				SavePlayerData(i, "PickupEventPickupStatus17");
			}
			if(gPlayerData[i][mPickupEventPickupStatus][17])
			{
				gPlayerData[i][mPickupEventPickupStatus][17] = 0;
				SavePlayerData(i, "PickupEventPickupStatus18");
			}
			if(gPlayerData[i][mPickupEventPickupStatus][18])
			{
				gPlayerData[i][mPickupEventPickupStatus][18] = 0;
				SavePlayerData(i, "PickupEventPickupStatus19");
			}
			if(gPlayerData[i][mPickupEventPickupStatus][19])
			{
				gPlayerData[i][mPickupEventPickupStatus][19] = 0;
				SavePlayerData(i, "PickupEventPickupStatus20");
			}
		}
	}
	else
	{
		gPlayerData[playerid][mPickupEventID] = gPickupEventID;
		SavePlayerData(playerid, "PickupEventID");
		gPlayerData[playerid][mPickupEventRewardReceived] = 0;
		SavePlayerData(playerid, "PickupEventRewardReceived");
		for(new j = 0; j < sizeof(gPickupEventData); j++)
		{
			if(gPlayerVars[playerid][mPickupEventPickups][j] != -1)
			{
				DestroyDynamicPickup(gPlayerVars[playerid][mPickupEventPickups][j]);
				gPlayerVars[playerid][mPickupEventPickups][j] = -1;
			}
		}
		if(gPlayerData[playerid][mPickupEventPickupStatus][0])
		{
			gPlayerData[playerid][mPickupEventPickupStatus][0] = 0;
			SavePlayerData(playerid, "PickupEventPickupStatus1");
		}
		if(gPlayerData[playerid][mPickupEventPickupStatus][1])
		{
			gPlayerData[playerid][mPickupEventPickupStatus][1] = 0;
			SavePlayerData(playerid, "PickupEventPickupStatus2");
		}
		if(gPlayerData[playerid][mPickupEventPickupStatus][2])
		{
			gPlayerData[playerid][mPickupEventPickupStatus][2] = 0;
			SavePlayerData(playerid, "PickupEventPickupStatus3");
		}
		if(gPlayerData[playerid][mPickupEventPickupStatus][3])
		{
			gPlayerData[playerid][mPickupEventPickupStatus][3] = 0;
			SavePlayerData(playerid, "PickupEventPickupStatus4");
		}
		if(gPlayerData[playerid][mPickupEventPickupStatus][4])
		{
			gPlayerData[playerid][mPickupEventPickupStatus][4] = 0;
			SavePlayerData(playerid, "PickupEventPickupStatus5");
		}
		if(gPlayerData[playerid][mPickupEventPickupStatus][5])
		{
			gPlayerData[playerid][mPickupEventPickupStatus][5] = 0;
			SavePlayerData(playerid, "PickupEventPickupStatus6");
		}
		if(gPlayerData[playerid][mPickupEventPickupStatus][6])
		{
			gPlayerData[playerid][mPickupEventPickupStatus][6] = 0;
			SavePlayerData(playerid, "PickupEventPickupStatus7");
		}
		if(gPlayerData[playerid][mPickupEventPickupStatus][7])
		{
			gPlayerData[playerid][mPickupEventPickupStatus][7] = 0;
			SavePlayerData(playerid, "PickupEventPickupStatus8");
		}
		if(gPlayerData[playerid][mPickupEventPickupStatus][8])
		{
			gPlayerData[playerid][mPickupEventPickupStatus][8] = 0;
			SavePlayerData(playerid, "PickupEventPickupStatus9");
		}
		if(gPlayerData[playerid][mPickupEventPickupStatus][9])
		{
			gPlayerData[playerid][mPickupEventPickupStatus][9] = 0;
			SavePlayerData(playerid, "PickupEventPickupStatus10");
		}
		if(gPlayerData[playerid][mPickupEventPickupStatus][10])
		{
			gPlayerData[playerid][mPickupEventPickupStatus][10] = 0;
			SavePlayerData(playerid, "PickupEventPickupStatus11");
		}
		if(gPlayerData[playerid][mPickupEventPickupStatus][11])
		{
			gPlayerData[playerid][mPickupEventPickupStatus][11] = 0;
			SavePlayerData(playerid, "PickupEventPickupStatus12");
		}
		if(gPlayerData[playerid][mPickupEventPickupStatus][12])
		{
			gPlayerData[playerid][mPickupEventPickupStatus][12] = 0;
			SavePlayerData(playerid, "PickupEventPickupStatus13");
		}
		if(gPlayerData[playerid][mPickupEventPickupStatus][13])
		{
			gPlayerData[playerid][mPickupEventPickupStatus][13] = 0;
			SavePlayerData(playerid, "PickupEventPickupStatus14");
		}
		if(gPlayerData[playerid][mPickupEventPickupStatus][14])
		{
			gPlayerData[playerid][mPickupEventPickupStatus][14] = 0;
			SavePlayerData(playerid, "PickupEventPickupStatus15");
		}
		if(gPlayerData[playerid][mPickupEventPickupStatus][15])
		{
			gPlayerData[playerid][mPickupEventPickupStatus][15] = 0;
			SavePlayerData(playerid, "PickupEventPickupStatus16");
		}
		if(gPlayerData[playerid][mPickupEventPickupStatus][16])
		{
			gPlayerData[playerid][mPickupEventPickupStatus][16] = 0;
			SavePlayerData(playerid, "PickupEventPickupStatus17");
		}
		if(gPlayerData[playerid][mPickupEventPickupStatus][17])
		{
			gPlayerData[playerid][mPickupEventPickupStatus][17] = 0;
			SavePlayerData(playerid, "PickupEventPickupStatus18");
		}
		if(gPlayerData[playerid][mPickupEventPickupStatus][18])
		{
			gPlayerData[playerid][mPickupEventPickupStatus][18] = 0;
			SavePlayerData(playerid, "PickupEventPickupStatus19");
		}
		if(gPlayerData[playerid][mPickupEventPickupStatus][19])
		{
			gPlayerData[playerid][mPickupEventPickupStatus][19] = 0;
			SavePlayerData(playerid, "PickupEventPickupStatus20");
		}
	}
}

stock PlayerPickupEventPickups(playerid)
{
	new string[128], count;
	Audio_Play(playerid, AUDIO_ITEM_PICKUP, false, false, false);
	for(new i = 0; i < gPickupEventCount; i++)
	{
		if(!gPlayerData[playerid][mPickupEventPickupStatus][i])
			count++;
	}
	if(count == 0)
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Znalaz³eœ ju¿ wszystkie przedmioty !\nUdaj siê do najbli¿szego urzêdu aby otrzymaæ nagrode", "Zamknij", "");
	else
	{
		format(string, sizeof(string), "Znalaz³eœ przedmiot ! Pozosta³o ci jeszcze %d przedmiotów do znalezienia", count);
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", string, "Zamknij", "");
	}
}