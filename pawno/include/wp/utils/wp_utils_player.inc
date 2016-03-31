/***
*
* File: wp_utils_player.inc
* Auth: Damian Wojdat
* Date: 11.03.2012
* Desc: Internal script function related to player.
*
*************************************************************************************************************/

#include <wp\utils\wp_utils_player_weapons>

timer PlayerWomit[2000](playerid)
{
	if(gPlayerData[playerid][pPainKiller] == 0 && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
	{
		ApplyAnimation(playerid, "FOOD", "EAT_Vomit_P", 4.1, 0, 1, 1, 0, 0);
	}
}

stock SetPlayerDrunkLevelEx(playerid, lvl)
{
	if(gPlayerData[playerid][pPainKiller] == 0)
		SetPlayerDrunkLevel(playerid, lvl);
}

stock SetPlayerArmourEx(playerid, Float:armour)
{
	if(armour > 0.0)
	{
		if(IsPlayerAttachedObjectSlotUsed(playerid, MAX_PLAYER_ATTACHED_OBJECTS-5))
		{
			RemovePlayerAttachedObject(playerid, MAX_PLAYER_ATTACHED_OBJECTS-5);
		}
		new model, skin;
		
		if(gPlayerData[playerid][pFaction] == 255)
		{
			model = 373;
			
			SetPlayerAttachedObject(playerid, MAX_PLAYER_ATTACHED_OBJECTS-5, model, 1,
				ArmourOffSet[GetPlayerSkin(playerid)][0],
				ArmourOffSet[GetPlayerSkin(playerid)][1],
				ArmourOffSet[GetPlayerSkin(playerid)][2],
				ArmourOffSet[GetPlayerSkin(playerid)][3],
				ArmourOffSet[GetPlayerSkin(playerid)][4],
				ArmourOffSet[GetPlayerSkin(playerid)][5],
				ArmourOffSet[GetPlayerSkin(playerid)][6],
				ArmourOffSet[GetPlayerSkin(playerid)][7],
				ArmourOffSet[GetPlayerSkin(playerid)][8]
			);
		}
		else
		{
			skin = GetPlayerSkin(playerid);
			
			if(DynamicFactions[gPlayerData[playerid][pFaction]][fType] == FACTIONT_POLICE &&
				(skin == 265 || skin == 266 || skin == 267 || skin == 280 || skin == 281 || skin == 282 ||
				skin == 283 || skin == 284 || skin == 285 || skin == 286 || skin == 287))
			{
				model = 19142;
				
				switch(skin)
				{
					case 265:
					{
						skin = 0;
					}
					case 266:
					{
						skin = 0;
					}
					case 267:
					{
						skin = 0;
					}
					case 280:
					{
						skin = 0;
					}
					case 281:
					{
						skin = 0;
					}
					case 282:
					{
						skin = 0;
					}
					case 283:
					{
						skin = 0;
					}
					case 284:
					{
						skin = 0;
					}
					case 285:
					{
						skin = 0;
					}
					case 286:
					{
						skin = 0;
					}
					case 287:
					{
						skin = 0;
					}
				}
				
				SetPlayerAttachedObject(playerid, MAX_PLAYER_ATTACHED_OBJECTS-5, model, 1,
					HArmourOffSet[skin][0],
					HArmourOffSet[skin][1],
					HArmourOffSet[skin][2],
					HArmourOffSet[skin][3],
					HArmourOffSet[skin][4],
					HArmourOffSet[skin][5],
					HArmourOffSet[skin][6],
					HArmourOffSet[skin][7],
					HArmourOffSet[skin][8]
				);
			}
			else
			{
				model = 373;
				
				SetPlayerAttachedObject(playerid, MAX_PLAYER_ATTACHED_OBJECTS-5, model, 1,
					ArmourOffSet[GetPlayerSkin(playerid)][0],
					ArmourOffSet[GetPlayerSkin(playerid)][1],
					ArmourOffSet[GetPlayerSkin(playerid)][2],
					ArmourOffSet[GetPlayerSkin(playerid)][3],
					ArmourOffSet[GetPlayerSkin(playerid)][4],
					ArmourOffSet[GetPlayerSkin(playerid)][5],
					ArmourOffSet[GetPlayerSkin(playerid)][6],
					ArmourOffSet[GetPlayerSkin(playerid)][7],
					ArmourOffSet[GetPlayerSkin(playerid)][8]
				);
			}
		}
	}
	else
		RemovePlayerAttachedObject(playerid, MAX_PLAYER_ATTACHED_OBJECTS-5);
	
	SetPlayerArmour(playerid, armour);
	
	gPlayerData[playerid][pArmour] = armour;
	SavePlayerData(playerid, "Armour");
}

stock IsPlayerVip(playerid)
{
	if(gPlayerData[playerid][pVipExp] > 0 || gPlayerData[playerid][pVipExpT] > 0 || gPlayerData[playerid][pVipAFK] > 0 || gPlayerData[playerid][pVipAFKT] > 0)
		return 1;
	else
		return 0;
}

stock ShowPlayerMapIcons(playerid, type = 0)
{
	#pragma unused type
	for(new i = 0; i < MAX_BUILDINGS; i++)
	{
		if(Building[i][ShowIcon] && !gPlayerData[playerid][pMapIcons][MAX_BUSINESSES+i])
			gPlayerData[playerid][pMapIcons][MAX_BUSINESSES+i] = CreateDynamicMapIcon(Building[i][EnterX], Building[i][EnterY], Building[i][EnterZ], Building[i][IconType], 0, 0, 0, playerid, 500.0);
	}
	if(type == 1)
	{
		for(new i = 0; i < MAX_BUSINESSES; i++)
		{
			// if(Businesses[i][BShowIcon] && !gPlayerData[playerid][pMapIcons][i])
			if(!gPlayerData[playerid][pMapIcons][i] && Businesses[i][Owned])
			{
				switch(Businesses[i][BizType])
				{
					case 1:
						gPlayerData[playerid][pMapIcons][i] = CreateDynamicMapIcon(Businesses[i][EnterX], Businesses[i][EnterY], Businesses[i][EnterZ], 50, 0, 0, 0, playerid, 300.0);
					case 2:
						gPlayerData[playerid][pMapIcons][i] = CreateDynamicMapIcon(Businesses[i][EnterX], Businesses[i][EnterY], Businesses[i][EnterZ], 40, 0, 0, 0, playerid, 300.0);
					case 3:
						gPlayerData[playerid][pMapIcons][i] = CreateDynamicMapIcon(Businesses[i][EnterX], Businesses[i][EnterY], Businesses[i][EnterZ], 36, 0, 0, 0, playerid, 300.0);
					case 4:
						gPlayerData[playerid][pMapIcons][i] = CreateDynamicMapIcon(Businesses[i][EnterX], Businesses[i][EnterY], Businesses[i][EnterZ], 6, 0, 0, 0, playerid, 300.0);
					case 5:
						gPlayerData[playerid][pMapIcons][i] = CreateDynamicMapIcon(Businesses[i][EnterX], Businesses[i][EnterY], Businesses[i][EnterZ], 36, 0, 0, 0, playerid, 300.0);
					case 6:
						gPlayerData[playerid][pMapIcons][i] = CreateDynamicMapIcon(Businesses[i][EnterX], Businesses[i][EnterY], Businesses[i][EnterZ], 45, 0, 0, 0, playerid, 300.0);
					case 7:
						gPlayerData[playerid][pMapIcons][i] = CreateDynamicMapIcon(Businesses[i][EnterX], Businesses[i][EnterY], Businesses[i][EnterZ], 49, 0, 0, 0, playerid, 300.0);
					case 8:
						gPlayerData[playerid][pMapIcons][i] = CreateDynamicMapIcon(Businesses[i][EnterX], Businesses[i][EnterY], Businesses[i][EnterZ], 36, 0, 0, 0, playerid, 300.0);
					case 9:
						gPlayerData[playerid][pMapIcons][i] = CreateDynamicMapIcon(Businesses[i][EnterX], Businesses[i][EnterY], Businesses[i][EnterZ], 36, 0, 0, 0, playerid, 300.0);
					case 10:
						gPlayerData[playerid][pMapIcons][i] = CreateDynamicMapIcon(Businesses[i][EnterX], Businesses[i][EnterY], Businesses[i][EnterZ], 55, 0, 0, 0, playerid, 300.0);
					case 11:
						gPlayerData[playerid][pMapIcons][i] = CreateDynamicMapIcon(Businesses[i][EnterX], Businesses[i][EnterY], Businesses[i][EnterZ], 36, 0, 0, 0, playerid, 300.0);
				}
			}
		}
	}
	return 1;
}

public TogglePlayerUnControllable( playerid, Float:x, Float:y, Float:z )
{
	new Float:px, Float:py, Float:pz;
	GetPlayerPos( playerid, px, py, pz );
	TogglePlayerControllable(playerid, 0);
	return 1;
}

stock RemovePlayerMapIcons(playerid, type = 0)
{
	#pragma unused type
	if(type == 0)
	{
		for(new i = 0; i < MAX_BUILDINGS; i++)
		{
			if(gPlayerData[playerid][pMapIcons][MAX_BUSINESSES+i])
			{
				DestroyDynamicMapIcon(gPlayerData[playerid][pMapIcons][MAX_BUSINESSES+i]);
				gPlayerData[playerid][pMapIcons][MAX_BUSINESSES+i] = 0;
			}
		}
	}
	if(type == 1)
	{
		for(new i = 0; i < MAX_BUSINESSES; i++)
		{
			if(gPlayerData[playerid][pMapIcons][i])
			{
				DestroyDynamicMapIcon(gPlayerData[playerid][pMapIcons][i]);
				gPlayerData[playerid][pMapIcons][i] = 0;
			}
		}
	}
	return 1;
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

timer SetPlayerSpawn2[100](playerid)
{
	#if defined DEBUG
		printf("[DEBUG:] SetPlayerSpawn2 by player id %d", playerid);
	#endif
	static string[128];
	
	// Fill first logged player with default data
	if(!gPlayerData[playerid][pRegistered])
	{
		gPlayerData[playerid][pCrashX] = gStartSpawnX;
		gPlayerData[playerid][pCrashY] = gStartSpawnY;
		gPlayerData[playerid][pCrashZ] = gStartSpawnZ;
		gPlayerData[playerid][pCash] = gStartMoney;
		gPlayerData[playerid][pBank] = gStartBank;
		gPlayerData[playerid][pRegistered] = 1;

		gSavePlayerReady[playerid] = 1; // umo¿liwia zapis w wp_saveplayerdata.inc

		SavePlayerData(playerid, "Registered");
		SetPlayerCash(playerid, gPlayerData[playerid][pCash]);
		
		DynamicFactions[FACTIONID_GOVERNMENT][fBank] -= gStartBank;
		DynamicFactions[FACTIONID_GOVERNMENT][fBank] -= gStartMoney;		
		SaveFData(FACTIONID_GOVERNMENT, "Bank");
		
		SetPlayerToPos(playerid, gPlayerData[playerid][pCrashX], gPlayerData[playerid][pCrashY], gPlayerData[playerid][pCrashZ]);
		
		gFirstTime[playerid] = 1;
	}
	
	SetPlayerVirtualWorld(playerid, gPlayerData[playerid][pCrashW]);
	SetPlayerInterior(playerid, gPlayerData[playerid][pCrashInt]);
	SetPlayerFacingAngle(playerid, gPlayerData[playerid][pCrashAngle]);
	SetPlayerWantedLevelEx(playerid, gPlayerData[playerid][pWantedLvl]);
	
	TogglePlayerDynamicCP(playerid, gVehExport[mCpId1], 0);
	TogglePlayerDynamicCP(playerid, gVehExport[mCpId2], 0);
	TogglePlayerDynamicCP(playerid, gVehExport[mCpId3], 0);
	TogglePlayerDynamicCP(playerid, gVehExport[mCpId4], 0);
	TogglePlayerDynamicCP(playerid, gVehExport[mCpId5], 0);
	TogglePlayerDynamicCP(playerid, gVehExport[mCpId6], 0);
	TogglePlayerDynamicCP(playerid, gVehExport[mCpId7], 0);
	
	TextDrawShowForPlayer(playerid, gTextTime);
	
	// Load pickup event data
	CreatePickupEventPickups(playerid);
	
	if(gPlayerData[playerid][pFaction] != 255)
	{
		if(DynamicFactions[gPlayerData[playerid][pFaction]][fType] == 3)
		{
			for(new idx = 0; idx < sizeof(DynamicZones); idx++)
			{
				if(DynamicZones[idx][mFaction] == gPlayerData[playerid][pFaction])
					GangZoneShowForPlayer(playerid, DynamicZones[idx][mZoneId], 0x00FF0090);
				else
					GangZoneShowForPlayer(playerid, DynamicZones[idx][mZoneId], 0xFF000090);				
			}
			if(gGangWar[Enabled])
				GangZoneFlashForPlayer(playerid, gGangWar[AreaID], DynamicFactions[DynamicZones[gGangWar[AreaID]][mFaction]][fColor]);
		}
	}	
		
	if(gPlayerData[playerid][pHP] <= 0.0)
	{
		format(string, sizeof(string), "[WARNING:] Player HP below 0 !");
		ErrorLog(string);
		SetPlayerHealth(playerid, 30.0);
	}
	else
		SetPlayerHealth(playerid,gPlayerData[playerid][pHP]);
	
	if(PHaveExpandItem(playerid))
	{
		SetPlayerAttachedObject(playerid, MAX_PLAYER_ATTACHED_OBJECTS-3, 371, 1,
			BackPackOffSet[gPlayerData[playerid][pSkin]][0],
			BackPackOffSet[gPlayerData[playerid][pSkin]][1],
			BackPackOffSet[gPlayerData[playerid][pSkin]][2],
			BackPackOffSet[gPlayerData[playerid][pSkin]][3],
			BackPackOffSet[gPlayerData[playerid][pSkin]][4],
			BackPackOffSet[gPlayerData[playerid][pSkin]][5],
			BackPackOffSet[gPlayerData[playerid][pSkin]][6],
			BackPackOffSet[gPlayerData[playerid][pSkin]][7],
			BackPackOffSet[gPlayerData[playerid][pSkin]][8]
		);
	}
	
	// Return saved player guns
	GivePlayerGun(playerid, gPlayerData[playerid][pWSlot0], gPlayerData[playerid][pWSlot0Ammo]);
	GivePlayerGun(playerid, gPlayerData[playerid][pWSlot1], gPlayerData[playerid][pWSlot1Ammo]);
	GivePlayerGun(playerid, gPlayerData[playerid][pWSlot2], gPlayerData[playerid][pWSlot2Ammo]);
	GivePlayerGun(playerid, gPlayerData[playerid][pWSlot3], gPlayerData[playerid][pWSlot3Ammo]);
	GivePlayerGun(playerid, gPlayerData[playerid][pWSlot4], gPlayerData[playerid][pWSlot4Ammo]);
	GivePlayerGun(playerid, gPlayerData[playerid][pWSlot5], gPlayerData[playerid][pWSlot5Ammo]);
	GivePlayerGun(playerid, gPlayerData[playerid][pWSlot6], gPlayerData[playerid][pWSlot6Ammo]);
	GivePlayerGun(playerid, gPlayerData[playerid][pWSlot7], gPlayerData[playerid][pWSlot7Ammo]);
	GivePlayerGun(playerid, gPlayerData[playerid][pWSlot8], gPlayerData[playerid][pWSlot8Ammo]);
	GivePlayerGun(playerid, gPlayerData[playerid][pWSlot9], gPlayerData[playerid][pWSlot9Ammo]);
	GivePlayerGun(playerid, gPlayerData[playerid][pWSlot10], gPlayerData[playerid][pWSlot10Ammo]);
	GivePlayerGun(playerid, gPlayerData[playerid][pWSlot11], gPlayerData[playerid][pWSlot11Ammo]);
	GivePlayerGun(playerid, gPlayerData[playerid][pWSlot12], gPlayerData[playerid][pWSlot12Ammo]);
	
	SetPlayerSkinEx(playerid, gPlayerData[playerid][pSkin]);
	
	if(AdminDuty[playerid])
	{
		SetPlayerColor(playerid, COLOR_ADMINDUTY);
		SetPlayerHealth(playerid, 99999);
		SetPlayerArmourEx(playerid, 99999);
	}	
	if(JustDied[playerid])
	{
		JustDied[playerid] = 0;
		if(!AdminDuty[playerid])
		{
			if(gPlayerData[playerid][pCharacterDying] > 1)
			{
				SetPlayerCameraPos(playerid, gPlayerData[playerid][pCrashX], gPlayerData[playerid][pCrashY], gPlayerData[playerid][pCrashZ]+5.0);
				SetPlayerCameraLookAt( playerid, gPlayerData[playerid][pCrashX], gPlayerData[playerid][pCrashY], gPlayerData[playerid][pCrashZ]+10.0 );	
				SetPlayerHealth(playerid, 99999);
				ApplyAnimation(playerid,"PED","FLOOR_hit",4.1,0,1,1,1,0);
				ApplyAnimation(playerid,"PED","FLOOR_hit",4.1,0,1,1,1,0);
				TextDrawHideForPlayer(playerid, Status[playerid]);
				SendClientMessage(playerid, COLOR_RED, "[INFO:] Teraz oczekujesz na pomoc");
			}
			else
			{
				SetPlayerDrunkLevelEx(playerid, 50000);
			}
		}
	}
	else
	{
		//PlayerPlaySound(playerid, 1186, 0.0, 0.0, 0.0); // blank sound
		
		StopAudioStreamForPlayer(playerid);
		
		if(gPlayerData[playerid][pJailed] == 1)
		{			
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ jeszcze wolny !");
		}
		else
		{		
			if(gPlayerData[playerid][pCharacterDying] > 1)
			{
				SetPlayerCameraPos( playerid, gPlayerData[playerid][pCrashX], gPlayerData[playerid][pCrashY], gPlayerData[playerid][pCrashZ]+5.0 );
				SetPlayerCameraLookAt( playerid, gPlayerData[playerid][pCrashX], gPlayerData[playerid][pCrashY], gPlayerData[playerid][pCrashZ]+10.0 );	
				SetPlayerHealth(playerid,99999);
				ApplyAnimation(playerid,"PED","FLOOR_hit",4.1,0,1,1,1,0);
				ApplyAnimation(playerid,"PED","FLOOR_hit",4.1,0,1,1,1,0);
				TextDrawHideForPlayer(playerid, Status[playerid]);
				SendClientMessage(playerid, COLOR_RED, "[INFO:] Twoja postaæ wci¹¿ oczekuje na pomoc. Jeœli chcesz przerwaæ jej mêki wpisz /smierc");
			}
		}
	}
	
	
	
}

stock SetPlayerSpawn(playerid)
{
	#if defined DEBUG
		printf("[DEBUG:] SetPlayerSpawn by player id %d", playerid);
	#endif
	new string[128];

	if(JustDied[playerid])
	{		
		if(gPlayerData[playerid][pCrashX] == 0.0 || gPlayerData[playerid][pCrashY] == 0.0 || gPlayerData[playerid][pCrashY] == 0.0)
		{
			SetSpawnInfo(playerid, 0, gPlayerData[playerid][pSkin], CivilianSpawn[X], CivilianSpawn[Y], CivilianSpawn[Z], 0, 0, 0, 0, 0, 0, 0);
		}
		else
		{
			SetSpawnInfo(playerid, 0, gPlayerData[playerid][pSkin], gPlayerData[playerid][pCrashX], gPlayerData[playerid][pCrashY], gPlayerData[playerid][pCrashZ], gPlayerData[playerid][pCrashAngle],0,0,0,0,0,0);			
		}
		
		return 1;
	}
	else
	{	
		if(AdminDuty[playerid])
		{
			if(gPlayerData[playerid][pCrashX] == 0.0 || gPlayerData[playerid][pCrashY] == 0.0 || gPlayerData[playerid][pCrashY] == 0.0)
			{
				SetSpawnInfo(playerid, 0, gPlayerData[playerid][pSkin], CivilianSpawn[Y], CivilianSpawn[Y], CivilianSpawn[Z], 0, 0, 0, 0, 0, 0, 0);
			}
			else
			{
				SetSpawnInfo(playerid, 0, gPlayerData[playerid][pSkin], gPlayerData[playerid][pCrashX], gPlayerData[playerid][pCrashY], gPlayerData[playerid][pCrashZ], gPlayerData[playerid][pCrashAngle],0,0,0,0,0,0);
			}
		}
		else
		{
			if(gPlayerData[playerid][pCrashX] == 0.0 || gPlayerData[playerid][pCrashY] == 0.0 || gPlayerData[playerid][pCrashY] == 0.0)
			{
				format(string, sizeof(string), "[WARNING:] Player %s pos is null", gPlayerData[playerid][pName]);
				ErrorLog(string);
				
				SetSpawnInfo(playerid, 0, gPlayerData[playerid][pSkin], gStartSpawnX, gStartSpawnY, gStartSpawnZ,0,0,0,0,0,0,0);
			}
			else
			{
				SetSpawnInfo(playerid, 0, gPlayerData[playerid][pSkin], gPlayerData[playerid][pCrashX], gPlayerData[playerid][pCrashY], gPlayerData[playerid][pCrashZ], gPlayerData[playerid][pCrashAngle],0,0,0,0,0,0);
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

/*stock SetPlayerToFactionColor(playerid)
{
	if(gPlayerData[playerid][pFaction] != 255)
	{
		if(DynamicFactions[gPlayerData[playerid][pFaction]][fUseColor])
		{
		    if(DynamicFactions[gPlayerData[playerid][pFaction]][fType] == 1)
		    {
      			if(gPlayerData[playerid][pDuty])
	        	{
	        	    SetPlayerColor(playerid,HexToInt(DynamicFactions[gPlayerData[playerid][pFaction]][fColor]));
   		        }
   		        else
   		        {
	            	SetPlayerColor(playerid,COLOR_CIVILIAN);
   		        }
			}
			else
			{
				SetPlayerColor(playerid,HexToInt(DynamicFactions[gPlayerData[playerid][pFaction]][fColor]));
			}
		}
	}
	return 0;
}*/ 
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

stock ShowPlayerQuiz(playerid)
{
	new string[128];
	switch(gPlayerVars[playerid][mQuizQuestionNo])
	{
		case 0:
		{
			format(string, sizeof(string), "{DF013A}[WParty SERVER:]{FFFFFF} Zalogowa³eœ siê na Twojej nowej postaci !", gPlayerData[playerid][pOOCName]);
			SendClientMessage(playerid, COLOR_GREEN, string );
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "{DF013A}[WParty SERVER:]{FFFFFF} Zanim jednak rozpoczniesz gre musisz odpowiedzieæ na 25 krótkich pytañ.");
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "{DF013A}[WParty SERVER:]{FFFFFF} Pytania s¹ krótkie i nie powinny sprawiæ Tobie problemu ! Mo¿esz pope³niæ 2 b³êdy. Powodzenia !");
			gPlayerVars[playerid][mQuizQuestionNo] = 1;
			ShowPlayerQuiz(playerid);
		}
		case 1:
		{
			format(string, sizeof(string), gQuizQuestions[q1]);
			SendClientMessage(playerid, COLOR_YELLOW2, string);
			format(string, sizeof(string), gQuizQuestions[a1a]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a1b]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a1c]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a1d]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a1e]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
		}
		case 2:
		{
			format(string, sizeof(string), gQuizQuestions[q2]);
			SendClientMessage(playerid, COLOR_YELLOW2, string);
			format(string, sizeof(string), gQuizQuestions[a2a]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a2b]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a2c]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a2d]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a2e]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
		}
		case 3:
		{
			format(string, sizeof(string), gQuizQuestions[q3]);
			SendClientMessage(playerid, COLOR_YELLOW2, string);
			format(string, sizeof(string), gQuizQuestions[a3a]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a3b]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a3c]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a3d]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a3e]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
		}
		case 4:
		{
			format(string, sizeof(string), gQuizQuestions[q4]);
			SendClientMessage(playerid, COLOR_YELLOW2, string);
			format(string, sizeof(string), gQuizQuestions[a4a]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a4b]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a4c]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a4d]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a4e]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
		}
		case 5:
		{
			format(string, sizeof(string), gQuizQuestions[q5]);
			SendClientMessage(playerid, COLOR_YELLOW2, string);
			format(string, sizeof(string), gQuizQuestions[a5a]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a5b]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a5c]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a5d]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a5e]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
		}
		case 6:
		{
			format(string, sizeof(string), gQuizQuestions[q6]);
			SendClientMessage(playerid, COLOR_YELLOW2, string);
			format(string, sizeof(string), gQuizQuestions[a6a]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a6b]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a6c]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a6d]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a6e]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
		}
		case 7:
		{
			format(string, sizeof(string), gQuizQuestions[q7]);
			SendClientMessage(playerid, COLOR_YELLOW2, string);
			format(string, sizeof(string), gQuizQuestions[a7a]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a7b]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a7c]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a7d]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a7e]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
		}
		case 8:
		{
			format(string, sizeof(string), gQuizQuestions[q8]);
			SendClientMessage(playerid, COLOR_YELLOW2, string);
			format(string, sizeof(string), gQuizQuestions[a8a]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a8b]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a8c]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a8d]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a8e]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
		}
		case 9:
		{
			format(string, sizeof(string), gQuizQuestions[q9]);
			SendClientMessage(playerid, COLOR_YELLOW2, string);
			format(string, sizeof(string), gQuizQuestions[a9a]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a9b]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a9c]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a9d]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a9e]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
		}
		case 10:
		{
			format(string, sizeof(string), gQuizQuestions[q10]);
			SendClientMessage(playerid, COLOR_YELLOW2, string);
			format(string, sizeof(string), gQuizQuestions[a10a]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a10b]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a10c]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a10d]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a10e]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
		}
		case 11:
		{
			format(string, sizeof(string), gQuizQuestions[q11]);
			SendClientMessage(playerid, COLOR_YELLOW2, string);
			format(string, sizeof(string), gQuizQuestions[a11a]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a11b]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a11c]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a11d]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a11e]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
		}
		case 12:
		{
			format(string, sizeof(string), gQuizQuestions[q12]);
			SendClientMessage(playerid, COLOR_YELLOW2, string);
			format(string, sizeof(string), gQuizQuestions[a12a]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a12b]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a12c]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a12d]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a12e]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
		}
		case 13:
		{
			format(string, sizeof(string), gQuizQuestions[q13]);
			SendClientMessage(playerid, COLOR_YELLOW2, string);
			format(string, sizeof(string), gQuizQuestions[a13a]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a13b]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a13c]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a13d]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a13e]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
		}
		case 14:
		{
			format(string, sizeof(string), gQuizQuestions[q14]);
			SendClientMessage(playerid, COLOR_YELLOW2, string);
			format(string, sizeof(string), gQuizQuestions[a14a]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a14b]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a14c]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a14d]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a14e]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
		}
		case 15:
		{
			format(string, sizeof(string), gQuizQuestions[q15]);
			SendClientMessage(playerid, COLOR_YELLOW2, string);
			format(string, sizeof(string), gQuizQuestions[a15a]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a15b]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a15c]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a15d]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a15e]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
		}
		case 16:
		{
			format(string, sizeof(string), gQuizQuestions[q16]);
			SendClientMessage(playerid, COLOR_YELLOW2, string);
			format(string, sizeof(string), gQuizQuestions[a16a]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a16b]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a16c]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a16d]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a16e]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
		}
		case 17:
		{
			format(string, sizeof(string), gQuizQuestions[q17]);
			SendClientMessage(playerid, COLOR_YELLOW2, string);
			format(string, sizeof(string), gQuizQuestions[a17a]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a17b]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a17c]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a17d]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a17e]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
		}
		case 18:
		{
			format(string, sizeof(string), gQuizQuestions[q18]);
			SendClientMessage(playerid, COLOR_YELLOW2, string);
			format(string, sizeof(string), gQuizQuestions[a18a]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a18b]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a18c]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a18d]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a18e]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
		}
		case 19:
		{
			format(string, sizeof(string), gQuizQuestions[q19]);
			SendClientMessage(playerid, COLOR_YELLOW2, string);
			format(string, sizeof(string), gQuizQuestions[a19a]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a19b]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a19c]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a19d]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a19e]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
		}
		case 20:
		{
			format(string, sizeof(string), gQuizQuestions[q20]);
			SendClientMessage(playerid, COLOR_YELLOW2, string);
			format(string, sizeof(string), gQuizQuestions[a20a]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a20b]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a20c]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a20d]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a20e]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
		}
		case 21:
		{
			format(string, sizeof(string), gQuizQuestions[q21]);
			SendClientMessage(playerid, COLOR_YELLOW2, string);
			format(string, sizeof(string), gQuizQuestions[a21a]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a21b]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a21c]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a21d]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a21e]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
		}
		case 22:
		{
			format(string, sizeof(string), gQuizQuestions[q22]);
			SendClientMessage(playerid, COLOR_YELLOW2, string);
			format(string, sizeof(string), gQuizQuestions[a22a]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a22b]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a22c]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a22d]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a22e]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
		}
		case 23:
		{
			format(string, sizeof(string), gQuizQuestions[q23]);
			SendClientMessage(playerid, COLOR_YELLOW2, string);
			format(string, sizeof(string), gQuizQuestions[a23a]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a23b]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a23c]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a23d]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a23e]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
		}
		case 24:
		{
			format(string, sizeof(string), gQuizQuestions[q24]);
			SendClientMessage(playerid, COLOR_YELLOW2, string);
			format(string, sizeof(string), gQuizQuestions[a24a]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a24b]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a24c]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a24d]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a24e]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
		}
		case 25:
		{
			format(string, sizeof(string), gQuizQuestions[q25]);
			SendClientMessage(playerid, COLOR_YELLOW2, string);
			format(string, sizeof(string), gQuizQuestions[a25a]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a25b]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a25c]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a25d]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
			format(string, sizeof(string), gQuizQuestions[a25e]);
			SendClientMessage(playerid, COLOR_YELLOW, string);
		}
	}
}

stock PostSpawn(playerid)
{
	#if defined DEBUG
		printf("[DEBUG:] PostSpawn(playerid)");
	#endif
	
	new string[128];
	
	TogglePlayerControllable(playerid, 0);
	defer UnfreezePlayer[5000](playerid);
	
	Alive[playerid] = 1;
	CheckDelay[playerid] = 2;
	
	format(string, sizeof(string), "{DF013A}[WParty SERVER:]{FFFFFF} Witaj ponownie %s", gPlayerData[playerid][pOOCName]);
	SendClientMessage( playerid, COLOR_GREEN, string);
	
	// Show gang war status
	TextDrawShowForPlayer(playerid, GangWar[playerid]);
	TextDrawShowForPlayer(playerid, GangWarTime[playerid]);

	// Set player nick color depends on nick
	if(IsPlayerVip(playerid))
	{
		SetPlayerColor(playerid, COLOR_PURPLE);
	}
	else
	{
		SetPlayerColor(playerid, COLOR_CIVILIAN);
	}
	
	// Show player map icons if have map
	if(PHaveItem(playerid, 1, 105))
	{
		ShowPlayerMapIcons( playerid, 0);
	}

	// Show player GPS data
	new slot[MAX_PLAYER_ITEM_SLOT];
	PHaveItemEx(playerid, 3, 12, slot);
	for(new i = 0; i < MAX_PLAYER_ITEM_SLOT; i++)
	{
		if(slot[i] && SlotParam1(playerid, i+1))
		{
			ShowPlayerMapIcons(playerid, 1);
			break;
		}
	}
	
	// Set player gui cash
	SetPlayerCash(playerid,gPlayerData[playerid][pCash]);

	// Set player score
	SetPlayerScore(playerid, gPlayerData[playerid][pPlayingHours]);

	// Set player weapon skills
	SetPlayerSkillLevel(playerid, 0, gPlayerData[playerid][pSkillLevPis] * 100);
	SetPlayerSkillLevel(playerid, 1, gPlayerData[playerid][pSkillLevSil] * 100);
	SetPlayerSkillLevel(playerid, 2, gPlayerData[playerid][pSkillLevDes] * 100);
	SetPlayerSkillLevel(playerid, 3, gPlayerData[playerid][pSkillLevSha] * 100);
	SetPlayerSkillLevel(playerid, 4, gPlayerData[playerid][pSkillLevSho] * 100);
	SetPlayerSkillLevel(playerid, 5, gPlayerData[playerid][pSkillLevSpa] * 100);
	SetPlayerSkillLevel(playerid, 6, gPlayerData[playerid][pSkillLevMic] * 100);
	SetPlayerSkillLevel(playerid, 7, gPlayerData[playerid][pSkillLevMp5] * 100);
	SetPlayerSkillLevel(playerid, 8, gPlayerData[playerid][pSkillLevAk] * 100);
	SetPlayerSkillLevel(playerid, 9, gPlayerData[playerid][pSkillLevM4] * 100);
	SetPlayerSkillLevel(playerid, 10, gPlayerData[playerid][pSkillLevSni] * 100);

	// Set PayDay Message
	if(gPlayerData[playerid][pPayDayMessage])
		TextDrawShowForPlayer(playerid, gPayDayText);
	
	// Set Hunger Bar
	if(IsPlayerVip(playerid))
	{
		gPlayerData[playerid][pEnergyProgressBarID] = CreateProgressBar(545.0, 110.5, 60.0, 4.0, COLOR_YELLOW, MAX_ENERGY_VIP);
		gPlayerData[playerid][pHungerProgressBarID] = CreateProgressBar(545.0, 115.5, 60.0, 4.0, COLOR_LIGHTRED, MAX_HUNGER_VIP);
		gPlayerData[playerid][pThirstProgressBarID] = CreateProgressBar(545.0, 120.5, 60.0, 4.0, COLOR_LIGHTBLUE, MAX_THIRST_VIP);
		/*gPlayerData[playerid][pPoisonProgressBarID] = CreateProgressBar(545.0, 125.5, 60.0, 4.0, COLOR_GREEN, MAX_POISON_VIP);
		gPlayerData[playerid][pFatProgressBarID] = CreateProgressBar(545.0, 130.5, 60.0, 4.0, COLOR_LIGHTYELLOW2, MAX_FAT_VIP);
		gPlayerData[playerid][pStomachProgressBarID] = CreateProgressBar(545.0, 135.5, 60.0, 4.0, COLOR_PURPLE, MAX_STOMACH_VIP);
		gPlayerData[playerid][pVitaminsProgressBarID] = CreateProgressBar(545.0, 140.5, 60.0, 4.0, COLOR_ORANGE, MAX_VITAMINS_VIP);
		gPlayerData[playerid][pDrunkProgressBarID] = CreateProgressBar(545.0, 145.5, 60.0, 4.0, COLOR_LIGHTORANGE, MAX_DRUNK);
		gPlayerData[playerid][pNarcoticProgressBarID] = CreateProgressBar(545.0, 150.5, 60.0, 4.0, COLOR_WHITE, MAX_NARCOTIC);*/
	}
	else
	{
		gPlayerData[playerid][pEnergyProgressBarID] = CreateProgressBar(550.0, 110.5, 55.5, 4.0, COLOR_YELLOW, MAX_ENERGY);
		gPlayerData[playerid][pHungerProgressBarID] = CreateProgressBar(550.0, 115.5, 55.5, 4.0, COLOR_LIGHTRED, MAX_HUNGER);
		gPlayerData[playerid][pThirstProgressBarID] = CreateProgressBar(550.0, 120.5, 55.5, 4.0, COLOR_LIGHTBLUE, MAX_THIRST);
		/*gPlayerData[playerid][pPoisonProgressBarID] = CreateProgressBar(550.0, 125.5, 55.5, 4.0, COLOR_GREEN, MAX_POISON);
		gPlayerData[playerid][pFatProgressBarID] = CreateProgressBar(550.0, 130.5, 55.5, 4.0, COLOR_LIGHTYELLOW2, MAX_FAT);
		gPlayerData[playerid][pStomachProgressBarID] = CreateProgressBar(550.0, 135.5, 55.5, 4.0, COLOR_PURPLE, MAX_STOMACH);
		gPlayerData[playerid][pVitaminsProgressBarID] = CreateProgressBar(550.0, 140.5, 55.5, 4.0, COLOR_ORANGE, MAX_VITAMINS);
		gPlayerData[playerid][pDrunkProgressBarID] = CreateProgressBar(550.0, 145.5, 55.5, 4.0, COLOR_LIGHTORANGE, MAX_DRUNK);
		gPlayerData[playerid][pNarcoticProgressBarID] = CreateProgressBar(550.0, 150.5, 55.5, 4.0, COLOR_WHITE, MAX_NARCOTIC);*/
	}
	SetProgressBarValue(gPlayerData[playerid][pEnergyProgressBarID], gPlayerData[playerid][pEnergy]);
	UpdateProgressBar(gPlayerData[playerid][pEnergyProgressBarID], playerid);
	SetProgressBarValue(gPlayerData[playerid][pHungerProgressBarID], gPlayerData[playerid][pHunger]);
	UpdateProgressBar(gPlayerData[playerid][pHungerProgressBarID], playerid);
	SetProgressBarValue(gPlayerData[playerid][pThirstProgressBarID], gPlayerData[playerid][pThirst]);
	UpdateProgressBar(gPlayerData[playerid][pThirstProgressBarID], playerid);
	// SetProgressBarValue(gPlayerData[playerid][pPoisonProgressBarID], gPlayerData[playerid][pPoison]);
	// UpdateProgressBar(gPlayerData[playerid][pPoisonProgressBarID], playerid);
	// SetProgressBarValue(gPlayerData[playerid][pFatProgressBarID], gPlayerData[playerid][pFat]);
	// UpdateProgressBar(gPlayerData[playerid][pFatProgressBarID], playerid);
	// SetProgressBarValue(gPlayerData[playerid][pStomachProgressBarID], gPlayerData[playerid][pStomach]);
	// UpdateProgressBar(gPlayerData[playerid][pStomachProgressBarID], playerid);
	// SetProgressBarValue(gPlayerData[playerid][pVitaminsProgressBarID], gPlayerData[playerid][pVitamins]);
	// UpdateProgressBar(gPlayerData[playerid][pVitaminsProgressBarID], playerid);
	// SetProgressBarValue(gPlayerData[playerid][pDrunkProgressBarID], gPlayerData[playerid][pDrunk]);
	// UpdateProgressBar(gPlayerData[playerid][pDrunkProgressBarID], playerid);
	// SetProgressBarValue(gPlayerData[playerid][pNarcoticProgressBarID], gPlayerData[playerid][pNarcotic]);
	// UpdateProgressBar(gPlayerData[playerid][pNarcoticProgressBarID], playerid);
	
	if(!gPlayerData[playerid][pShowHealthBars])
	{
		HideProgressBarForPlayer(playerid, gPlayerData[playerid][pEnergyProgressBarID]);
		HideProgressBarForPlayer(playerid, gPlayerData[playerid][pHungerProgressBarID]);
		HideProgressBarForPlayer(playerid, gPlayerData[playerid][pThirstProgressBarID]);
		/*HideProgressBarForPlayer(playerid, gPlayerData[playerid][pPoisonProgressBarID]);
		HideProgressBarForPlayer(playerid, gPlayerData[playerid][pFatProgressBarID]);
		HideProgressBarForPlayer(playerid, gPlayerData[playerid][pStomachProgressBarID]);
		HideProgressBarForPlayer(playerid, gPlayerData[playerid][pVitaminsProgressBarID]);
		HideProgressBarForPlayer(playerid, gPlayerData[playerid][pDrunkProgressBarID]);
		HideProgressBarForPlayer(playerid, gPlayerData[playerid][pNarcoticProgressBarID]);*/
	}
	else
	{
		TextDrawShowForPlayer(playerid, gHealthTextEnergy);
	}
	
	// Show infos
	// ClearScreen(playerid);
	format(string, sizeof(string), "{DF013A}[WParty SERVER:]{FFFFFF}[ID: %d][IC: %s] %s do³¹czy³ do gry !", playerid, GetPlayerNameEx(playerid), gPlayerData[playerid][pOOCName]);
	foreach(Player, i)
	{
		if(gPlayerLogged[i] && i != playerid && gPlayerData[i][pJoinInfoStatus])
		{
			SendClientMessage(i, 0xFFFFFFAA, string);
		}
	}

	// Show character AFK status
	Attach3DTextLabelToPlayer(playerAFK[playerid], playerid, 0.0, 0.0, 0.8);
	Update3DTextLabelText(playerAFK[playerid], COLOR_BLACK, " ");
	
	// Show character description
	Attach3DTextLabelToPlayer(gPlayerData[playerid][pCharDescriptionID], playerid, 0.0, 0.0, 0.5);
	UpdateCharDescription(playerid);

	// Show character name
	Attach3DTextLabelToPlayer(gPlayerData[playerid][pCharNameID], playerid, 0.0, 0.0, 0.2);
	
	if(IsPlayerVip(playerid))
	{
		format(string, sizeof(string), "{C2A2DA}%s [%d]", GetPlayerNameEx(playerid), playerid);
	}
	else
	{
		format(string, sizeof(string), "{FFFFFF}%s [%d]", GetPlayerNameEx(playerid), playerid);
	}
	
	Update3DTextLabelText(gPlayerData[playerid][pCharNameID], COLOR_BLACK, string);
	
	// Check if player have active bandana
	PHaveItemEx(playerid, 3, 14, slot);
	for(new i = 0; i < MAX_PLAYER_ITEM_SLOT; i++)
	{
		if(slot[i] && SlotParam1(playerid, i+1))
		{
			if(IsPlayerVip(playerid))
			{
				format(string, sizeof(string), "{C2A2DA}Twarz za chust¹ [%d]", playerid);
			}
			else
			{
				format(string, sizeof(string), "{FFFFFF}Twarz za chust¹ [%d]", playerid);
			}
			
			Update3DTextLabelText(gPlayerData[playerid][pCharNameID], COLOR_BLACK, string);
			
			break;
		}
	}
	
	// Set player dynamic weather
	if(IsPlayerInDynamicArea(playerid, gArea_MW_SanFierro))
	{
		SetPlayerRealWeatherEx(playerid, gMW_sanfrancisco);
	}
	else if(IsPlayerInDynamicArea(playerid, gArea_MW_LasVenturas))
	{
		SetPlayerRealWeatherEx(playerid, gMW_lasvegas);
	}
	else if(IsPlayerInDynamicArea(playerid, gArea_MW_LosSantos))
	{
		SetPlayerRealWeatherEx(playerid, gMW_losangeles);
	}
	else
	{
		SetPlayerRealWeatherEx(playerid, gMW_warszawa);
	}

	// Set player status box
	format(string, sizeof(string), " ");
	PlayerTextDrawSetString(playerid, PlayerStatus[playerid], string);
	PlayerTextDrawShow(playerid, PlayerStatus[playerid]);
	//TextDrawShowForPlayer(playerid, gPlayerVars[playerid][mSanNewsTextDrawId]);

	// Set login status and enable save
	gPlayerData[playerid][pLoading] = 0;
	gSavePlayerReady[playerid] = 1;

	// New version changes
	// if(!gPlayerData[playerid][pNewVersion])
	// {
		// strcat(string, "Otrzymujesz t¹ wiadomoœæ poniewa¿ od Twojego ostatniego logowania na serwer zosta³a wgrana nowa wersja skryptu.\n");
		// strcat(string, "\nZmiany w wersji - 1.15.0 - 1.15.1\n");
		// strcat(string, "- Stawianie/edycja biznesów/domów zosta³o zablokowane dla urzêdu. (1.15.1)\n");
		// strcat(string, "- Wezwania na policje/pogotwie wewn¹trz interiorów tworz¹ punkcie wejœcia do interioru. (1.15.1)\n");
		// strcat(string, "- Gracz mo¿e przejrzeæ ostatnie 5 wezwañ (dot. pogotowia oraz policji) poprzez komende /wezwania. Umo¿liwia to ponowne wyœwietlenie punktu w którym znajduje siê gracz który wykona³ po³¹czenie. (1.15.1)\n");
		// strcat(string, "- Rozwi¹zano problemy z zapisem w pomniejszych elementach gamemodu. (1.15.1)\n");
		// strcat(string, "- Ujednolicono zapis pozycji postaci (rozwi¹zuje problem ze spawnem w interiorach). (1.15.1)\n");
		// strcat(string, "- Wprowadzono mo¿liwoœæ posiadania wielu biznesów. (1.15.0)\n");
		// strcat(string, "- Dodano statystyki biznesu. (1.15.0)\n");
		// strcat(string, "- Ulepszono wynajmowanie domów. (1.15.0)\n");
		// strcat(string, "- Dodano item umo¿liwiaj¹cy zrobienie kopii klucza. (1.15.0)\n");
		// strcat(string, "- Wprowadzono mo¿liwoœæ zmiany zamka w domach oraz biznesach. (1.15.0)\n");
		// strcat(string, "- Dodano puste interiory do zaaran¿owania przez gracza. (1.15.0)\n");
		// strcat(string, "- Poprawiono problemy z BW. (1.15.0)\n");
		// ShowPlayerDialog(playerid, DIALOG_NEW_VERSION, DIALOG_STYLE_MSGBOX, "Nowa aktualizacja !", string, "Zamknij", "");
	// }
	
	if(gPlayerData[playerid][pVipItem] > 0 && gPlayerData[playerid][pVipItem] <= 5)
	{
		if(gPlayerData[playerid][pVipItem] == 1)
			format(string, sizeof(string), "Do koñca us³ugi premium VIP Item pozosta³ ju¿ tylko 1 dzieñ !");
		else
			format(string, sizeof(string), "Do koñca us³ugi premium VIP Item pozosta³o ju¿ tylko %d dni !", gPlayerData[playerid][pVipItem]);
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", string, "Zamknij", "");
	}
	else if(gPlayerData[playerid][pVipExpT] > 0 && gPlayerData[playerid][pVipExpT] <= 5)
	{
		if(gPlayerData[playerid][pVipExpT] == 1)
			format(string, sizeof(string), "Do koñca us³ugi premium VIP pozosta³o ju¿ tylko 1 dzieñ !");
		else
			format(string, sizeof(string), "Do koñca us³ugi premium VIP pozosta³o ju¿ tylko %d dni !", gPlayerData[playerid][pVipExpT]);
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", string, "Zamknij", "");
	}

	gPlayerData[playerid][pLastLogged] = 0;
	SavePlayerData(playerid, "LastLogged");
}

stock PreSpawn(playerid)
{
	#if defined DEBUG
		printf("[DEBUG:] PreSpawn(playerid)");
	#endif
	
	// Set login status and enable save
	gPlayerLogged[playerid] = 1;
	
	if(!gPlayerData[playerid][pQuiz])
	{
		gPlayerVars[playerid][mQuizQuestionNo] = 0;
		gPlayerVars[playerid][mQuizWrongAnsweres] = 0;
		ShowPlayerQuiz(playerid);
	}
	else
	{
		SpawnPlayerEx(playerid);
	}
}

stock SpawnPlayerEx(playerid)
{
	#if defined DEBUG
		printf("[DEBUG:] SpawnPlayerEx(playerid)");
	#endif
	SetPlayerSpawn(playerid);							
	SpawnPlayer(playerid);
	PostSpawn(playerid);
}

stock GetPlayerInVehicleSeat(vehId, seatId)
{
	foreach(Player, i)
	{
		if(IsPlayerInVehicle(i, vehId))
		{
			if(GetPlayerVehicleSeat(i) == seatId)
			{
				return i;
			}
		}
	}
	return -1;
}

// TODO: Cleanup all unused TEXT: OnPlayerDisconnect

stock UpdateClotheStoreDescription(playerid)
{
	/*
	new string[128];
	new totalSkins;
	new slot = BizHaveItem(gBuyBusinessID[playerid], 3, 24);
	new itemPrice = BizItemSlotPrice(gBuyBusinessID[playerid], slot);
	if(gPlayerData[playerid][pSex] == 1)
	{
		totalSkins = sizeof(MaleSkins);
		SetPlayerSkinEx(playerid, MaleSkins[0]);
	}
	else
	{
		totalSkins = sizeof(FemaleSkins);
		SetPlayerSkinEx(playerid, FemaleSkins[0]);
	}
	format(string, sizeof(string), "~y~Wciœnij ~r~~k~~SPACJE~ ~y~aby kupiæ ubranie~n~Cena: ~r~$%d~n~~n~~y~(%d/%d)", itemPrice, gPlayerVars[playerid][mClotheShopSkinId]+1, totalSkins);
	*/
}

stock PlayerToClotheStore(playerid)
{
	gPlayerVars[playerid][mAtClotheStore] = true;
	gPlayerVars[playerid][mClotheShopSkinId] = 0;
	
	SetPlayerVirtualWorld(playerid, playerid+1);
	SetPlayerInterior(playerid, 18);
	SetPlayerToPos(playerid, 181.7410,-87.4888,1002.0234);
	SetPlayerFacingAngle(playerid, 128.0);
	SetPlayerCameraPos(playerid, 178.2804,-89.5319,1003.0234);
	SetPlayerCameraLookAt(playerid, 181.7410,-87.4888,1002.0234);
	TogglePlayerControllable(playerid, 0);
	
	PlayerTextDrawShow(playerid, gPlayerVars[playerid][mWardrobeExitText]);
	
	defer ClotheStoreKeyTimer(playerid);
	
	ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "U¿yj strza³ek aby przegl¹daæ dostêpne ubrania.\nWpisz /opuscprzymierzalnie aby wyjœæ.\nWciœnij spacje aby kupiæ ubranie.", "Zamknij", "");
}

stock SetPlayerClotheStoreSkin(playerid)
{
	if(gPlayerData[playerid][pSex] == 1)
	{
		SetPlayerSkinEx(playerid, MaleSkins[gPlayerVars[playerid][mClotheShopSkinId]]);
	}
	else
	{
		SetPlayerSkinEx(playerid, FemaleSkins[gPlayerVars[playerid][mClotheShopSkinId]]);
	}
}

stock SetNextPlayerClotheStoreSkin(playerid)
{
	if(gPlayerData[playerid][pSex] == 1)
	{
		if(gPlayerVars[playerid][mClotheShopSkinId]+1 >= sizeof(MaleSkins))
		{
			gPlayerVars[playerid][mClotheShopSkinId] = 0;
		}
		else
		{
			gPlayerVars[playerid][mClotheShopSkinId]++;
		}
		SetPlayerSkinEx(playerid, MaleSkins[gPlayerVars[playerid][mClotheShopSkinId]]);
	}
	else
	{
		if(gPlayerVars[playerid][mClotheShopSkinId]+1 >= sizeof(FemaleSkins))
		{
			gPlayerVars[playerid][mClotheShopSkinId] = 0;
		}
		else
		{
			gPlayerVars[playerid][mClotheShopSkinId]++;
		}
		SetPlayerSkinEx(playerid, FemaleSkins[gPlayerVars[playerid][mClotheShopSkinId]]);
	}
}

stock SetPrevPlayerClotheStoreSkin(playerid)
{
	if(gPlayerData[playerid][pSex] == 1)
	{
		if(gPlayerVars[playerid][mClotheShopSkinId]-1 <= 0)
		{
			gPlayerVars[playerid][mClotheShopSkinId] = sizeof(MaleSkins)-1;
		}
		else
		{
			gPlayerVars[playerid][mClotheShopSkinId]--;
		}
		SetPlayerSkinEx(playerid, MaleSkins[gPlayerVars[playerid][mClotheShopSkinId]]);
	}
	else
	{
		if(gPlayerVars[playerid][mClotheShopSkinId]-1 <= 0)
		{
			gPlayerVars[playerid][mClotheShopSkinId] = sizeof(FemaleSkins)-1;
		}
		else
		{
			gPlayerVars[playerid][mClotheShopSkinId]--;
		}
		SetPlayerSkinEx(playerid, FemaleSkins[gPlayerVars[playerid][mClotheShopSkinId]]);
	}
}

timer ClotheStoreKeyTimer[90](playerid)
{
	new keys, updown, leftright;
	GetPlayerKeys(playerid, keys, updown, leftright);
	if(leftright == KEY_RIGHT)
	{
		SetNextPlayerClotheStoreSkin(playerid);
	}
	if(leftright == KEY_LEFT)
	{
		SetPrevPlayerClotheStoreSkin(playerid);
	}
	if(gPlayerVars[playerid][mAtClotheStore])
	{
		defer ClotheStoreKeyTimer(playerid);
	}
}

stock SetPlayerToBiz(playerid, bizId)
{
	SetPlayerInterior(playerid, Businesses[bizId][ExitInterior]);
	SetPlayerToPos(playerid, Businesses[bizId][ExitX], Businesses[bizId][ExitY], Businesses[bizId][ExitZ]);
	SetPlayerVirtualWorld(playerid, bizId);
	SetPlayerFacingAngle(playerid, Businesses[bizId][ExitAngle]);
	TogglePlayerControllable(playerid, 0);
	defer UnfreezePlayer(playerid);
}

stock IsPlayerBizOwner(playerid, bizId)
{
	if(strcmp(gPlayerData[playerid][pName], Businesses[bizId][Owner], false) != 0 && (!Businesses[bizId][BGov] || gPlayerData[playerid][pFaction] != FACTIONID_GOVERNMENT))
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

stock ShowBizInfo(playerid)
{
	new string[128];
	if(gPlayerVars[playerid][mAtBizID] == -1)
	{
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Nie jesteœ w ¿adnym biznesie.", "Zamknij", "");
		return;
	}
	if(!IsPlayerBizOwner(playerid, gPlayerVars[playerid][mAtBizID]) && !IsPlayerAdmin(playerid))
	{
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Biznes", "Nie jesteœ w³aœcicielem tego biznesu.", "Zamknij", "");
		return;
	}
	format(string, sizeof(string), "Nazwa biznesu: %s\nPieni¹dze w kasie: $%d\nWejœciówka: $%d\nWycena biznesu: $%d\n", Businesses[gPlayerVars[playerid][mAtBizID]][BusinessName], Businesses[gPlayerVars[playerid][mAtBizID]][Till], Businesses[gPlayerVars[playerid][mAtBizID]][EntranceCost], Businesses[gPlayerVars[playerid][mAtBizID]][BizPrice]);
	if(Businesses[gPlayerVars[playerid][mAtBizID]][BizType] == BIZT_VEHICLES)
	{
		format(string, sizeof(string), "%sPosiadanych pojazdów: %d/%d\nLiczba zamówieñ: %d\nPojazdy oczekuj¹ce(0/1): %d\n", string, Businesses[gPlayerVars[playerid][mAtBizID]][VehicleCount], Businesses[gPlayerVars[playerid][mAtBizID]][MaxVehicles], Businesses[gPlayerVars[playerid][mAtBizID]][VehicleOrderCount], Businesses[gPlayerVars[playerid][mAtBizID]][VehicleSpawned]);
	}

	ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Biznes", string, "Zamknij", "");
	PlayerActionMessage(playerid, 15.0, "przegl¹da dokumentacje biznesu");
	return;
}

stock SetPlayerSkinEx(playerid, skinId)
{
	if(gPlayerVars[playerid][mAtClotheStore])
	{
		SetPlayerSkin(playerid, skinId);
		SetPlayerArmourEx(playerid, 0);
	}
	else if(gPlayerData[playerid][pJailed] > 0)
	{
		SetPlayerSkin(playerid, 96);
		SetPlayerArmourEx(playerid, 0);
	}
	else if(gPlayerData[playerid][pFaction] != 255)
	{
		if(gPlayerData[playerid][pDuty] && DynamicFactions[gPlayerData[playerid][pFaction]][fUseSkins])
		{
			SetPlayerToFactionSkin(playerid);
		}
		else
		{
			SetPlayerSkin(playerid, skinId);
		}
		SetPlayerArmourEx(playerid, gPlayerData[playerid][pArmour]);
	}
	else
	{
		SetPlayerSkin(playerid, skinId);
		SetPlayerArmourEx(playerid, gPlayerData[playerid][pArmour]);
	}
}

stock IsAtAtm(playerid)
{
	for(new i = 0; i < sizeof(gATM); i++)
	{
		if(!PlayerToPoint(1.0, playerid, gATM[i][0], gATM[i][1], gATM[i][2]))
		{
			continue;
		}
		
		return 1;
	}
	
	return 0;
}

stock ReturnGradeName(gradeId)
{
	new string[11];
	format(string, sizeof(string), "");
	switch(gradeId)
	{
		case 0:
		{
			format(string, sizeof(string), "podstawowe");
		}
		case 1:
		{
			format(string, sizeof(string), "œrednie");
		}
		case 2:
		{
			format(string, sizeof(string), "licencjat");
		}
		case 3:
		{
			format(string, sizeof(string), "magister");
		}
		case 4:
		{
			format(string, sizeof(string), "doktorat");
		}
	}
	return string;
}

stock RemoveWeaponFromSlot(playerid, slot)
{
	new weaponInSlot, ammoInSlot;
	GetPlayerWeaponData(playerid, slot, weaponInSlot, ammoInSlot);
	
	switch(weaponInSlot)
	{
		case 1:
		{
			GivePlayerWeapon(playerid, 0, 0);
		}
		case 2:
		{
			GivePlayerWeapon(playerid, 3, 0);
		}
		case 3:
		{
			GivePlayerWeapon(playerid, 2, 0);
		}
		case 4:
		{
			GivePlayerWeapon(playerid, 2, 0);
		}
		case 5:
		{
			GivePlayerWeapon(playerid, 2, 0);
		}
		case 6:
		{
			GivePlayerWeapon(playerid, 2, 0);
		}
		case 7:
		{
			GivePlayerWeapon(playerid, 2, 0);
		}
		case 8:
		{
			GivePlayerWeapon(playerid, 2, 0);
		}
		case 9:
		{
			GivePlayerWeapon(playerid, 2, 0);
		}
		case 10:
		{
			GivePlayerWeapon(playerid, 11, 0);
		}
		case 11:
		{
			GivePlayerWeapon(playerid, 10, 0);
		}
		case 12:
		{
			GivePlayerWeapon(playerid, 10, 0);
		}
		case 13:
		{
			GivePlayerWeapon(playerid, 10, 0);
		}
		case 14:
		{
			GivePlayerWeapon(playerid, 10, 0);
		}
		case 15:
		{
			GivePlayerWeapon(playerid, 10, 0);
		}
		case 16:
		{
			GivePlayerWeapon(playerid, 17, 0);
		}
		case 17:
		{
			GivePlayerWeapon(playerid, 16, 0);
		}
		case 18:
		{
			GivePlayerWeapon(playerid, 16, 0);
		}
		case 22:
		{
			GivePlayerWeapon(playerid, 23, 0);
		}
		case 23:
		{
			GivePlayerWeapon(playerid, 22, 0);
		}
		case 24:
		{
			GivePlayerWeapon(playerid, 22, 0);
		}
		case 25:
		{
			GivePlayerWeapon(playerid, 26, 0);
		}
		case 26:
		{
			GivePlayerWeapon(playerid, 25, 0);
		}
		case 27:
		{
			GivePlayerWeapon(playerid, 25, 0);
		}
		case 28:
		{
			GivePlayerWeapon(playerid, 29, 0);
		}
		case 29:
		{
			GivePlayerWeapon(playerid, 28, 0);
		}
		case 30:
		{
			GivePlayerWeapon(playerid, 31, 0);
		}
		case 31:
		{
			GivePlayerWeapon(playerid, 30, 0);
		}
		case 32:
		{
			GivePlayerWeapon(playerid, 28, 0);
		}
		case 33:
		{
			GivePlayerWeapon(playerid, 34, 0);
		}
		case 34:
		{
			GivePlayerWeapon(playerid, 33, 0);
		}
		case 35:
		{
			GivePlayerWeapon(playerid, 36, 0);
		}
		case 36:
		{
			GivePlayerWeapon(playerid, 35, 0);
		}
		case 37:
		{
			GivePlayerWeapon(playerid, 35, 0);
		}
		case 38:
		{
			GivePlayerWeapon(playerid, 35, 0);
		}		
	}
}

stock IsInFrontOfHood(playerid, vehId)
{
	if(IsABike(vehId) || IsAMotorBike(vehId) || IsABoat(vehId) || IsAHelicopter(vehId) || IsAPlaneModel(vehId))
	{
		return 1;
	}
	
	new Float:vehPosX, Float:vehPosY, Float:vehPosZ, Float:vehPosA, Float:inFrontOfPlayerPosX, Float:inFrontOfPlayerPosY, Float:playerPosA;
	
	GetVehiclePos(vehId, vehPosX, vehPosY, vehPosZ);
	GetVehicleZAngle(vehId, vehPosA);
	
	GetPlayerFacingAngle(playerid, playerPosA);
	
	for(new i = 0; i < sizeof(CarsLenghts); i++)
	{
		if(CarsLenghts[i][lenghtModel] != gVehData[vehId-1][mVehModel])
		{
			continue;
		}
		
		GetXYInFrontOfPlayer(playerid, inFrontOfPlayerPosX, inFrontOfPlayerPosY, CarsLenghts[i][hoodDistance]);
		
		if(CarsLenghts[i][hoodAngle] == 1)
		{
			if(playerPosA-180.0 < 0.0)
			{
				playerPosA += 180.0;
			}
			else
			{
				playerPosA -= 180.0;
			}
		}
		
		if((floatabs(inFrontOfPlayerPosX - vehPosX) > 0.9 || floatabs(inFrontOfPlayerPosY - vehPosY) > 0.9) || floatabs(vehPosA - playerPosA) > 28.0)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	return 0;
}

stock IsHoodOpened(playerid, vehId)
{
	if(IsABike(vehId) || IsAMotorBike(vehId) || IsABoat(vehId) || IsAHelicopter(vehId) || IsAPlaneModel(vehId))
	{
		return 1;
	}

	new Float:vehPosX, Float:vehPosY, Float:vehPosZ, Float:vehPosA, Float:inFrontOfPlayerPosX, Float:inFrontOfPlayerPosY, Float:playerPosA;
	
	GetVehiclePos(vehId, vehPosX, vehPosY, vehPosZ);
	GetVehicleZAngle(vehId, vehPosA);
	
	GetPlayerFacingAngle(playerid, playerPosA);
	
	new objective;
	
	for(new i = 0; i < sizeof(CarsLenghts); i++)
	{
		if(CarsLenghts[i][lenghtModel] != gVehData[vehId-1][mVehModel])
		{
			continue;
		}
		
		GetXYInFrontOfPlayer(playerid, inFrontOfPlayerPosX, inFrontOfPlayerPosY, CarsLenghts[i][hoodDistance]);
		
		if(CarsLenghts[i][hoodAngle] == 1)
		{
			if(playerPosA-180.0 < 0.0)
			{
				playerPosA += 180.0;
			}
			else
			{
				playerPosA -= 180.0;
			}
		}
		
		if((floatabs(inFrontOfPlayerPosX - vehPosX) > 0.9 || floatabs(inFrontOfPlayerPosY - vehPosY) > 0.9) || floatabs(vehPosA - playerPosA) > 28.0)
		{
			return 0;
		}
		else
		{
			GetVehicleParamsEx(vehId, gVehData[vehId-1][EngineOn], gVehData[vehId-1][LightsOn], gVehData[vehId-1][Alarm], gVehData[vehId-1][CarDoors], gVehData[vehId-1][BonnetUp], gVehData[vehId-1][BootUp], objective);
			if(CarsLenghts[i][trunkAngle] == 1)
			{
				if(!gVehData[vehId-1][BootUp])
				{
					return 0;
				}
				else
				{
					return 1;							
				}
			}
			else
			{
				if(!gVehData[vehId-1][BonnetUp])
				{
					return 0;
				}
				else
				{
					return 1;							
				}
			}
		}
	}
	return 0;
}

timer ClearAnimationsEx[2000](playerid)
{
	ClearAnimations(playerid);
}

timer InjuryEndAnimation[3000](playerid)
{
	ApplyAnimation(playerid, "PED", "getup_front", 4.1, 1, 0, 0, 1, 0, 1);
	defer ClearAnimationsEx[800](playerid);
}

stock ShowPlayerPhoneCompany(playerid)
{
	new string[2048], fID = gPlayerData[playerid][pFaction2];
	
	format(string, sizeof(string), "1. Koszt aktywacji - $%d\n2. Abonament dzienny - $%d\n3. Darmowe minuty w abonamencie - %d\n4. Darmowe SMSy w abonamencie - %d\n5. Koszt minuty w abonamencie - $%d\n6. Koszt SMSa w abonamencie - $%d\n",
		DynamicFactions[fID][mSimActivationCost], DynamicFactions[fID][mSimDailyFee], DynamicFactions[fID][mSimFreeMins], DynamicFactions[fID][mSimFreeSms], DynamicFactions[fID][mCallCostFee], DynamicFactions[fID][mSmsCostFee]);
	format(string, sizeof(string), "%s7. Koszt minuty w ofercie na karte - $%d\n8. Koszt SMSa w ofercie na karte - $%d\n9. Wa¿noœæ karty po aktywacji - %d dni\n10. Kwota do³adowania I - $%d\n11. Okres przed³u¿enia do³adowania I - %d dni\n", string,
		DynamicFactions[fID][mCallCostCard], DynamicFactions[fID][mSmsCostCard], DynamicFactions[fID][mCardValidity], DynamicFactions[fID][mCardRenewCost1], DynamicFactions[fID][mCardRenewTime1]);
	format(string, sizeof(string), "%s12. Kwota do³adowania II - $%d\n13. Okres przed³u¿enia do³adowania II - %d dni\n14. Kwota do³adowania III - $%d\n15. Okres przed³u¿enia do³adowania III - %d dni\n16. Kwota do³adowania IV - $%d\n", string,
		DynamicFactions[fID][mCardRenewCost2], DynamicFactions[fID][mCardRenewTime2], DynamicFactions[fID][mCardRenewCost3], DynamicFactions[fID][mCardRenewTime3], DynamicFactions[fID][mCardRenewCost4]);
	format(string, sizeof(string), "%s17. Okres przed³u¿enia do³adowania IV - %d dni\n18. Procentowy zysk biznesów z po³¹czeñ - %.2f%%\n19. Procentowy zysk biznesu ze sprzeda¿y ofert - %.2f%%\n20. Zysk biznesu za podpisanie umowy z firm¹ - $%d\n", string,
		DynamicFactions[fID][mCardRenewTime4], DynamicFactions[fID][mBizConIncome], DynamicFactions[fID][mBizOfferIncome], DynamicFactions[fID][mBizJoinCash]);
	format(string, sizeof(string), "%s21. Czas po jakim wygasa umowa z biznesem - %d dni\n22. Wartoœæ kary za przedwczesne zerwanie umowy - $%d\n23. Nazwa sieci - %s", string,
		DynamicFactions[fID][mBizJoinTime], DynamicFactions[fID][mBizPenaltyValue], DynamicFactions[fID][mCompanyName]);
	
	ShowPlayerDialog(playerid, DIALOG_NETWORK_COMP_1, DIALOG_STYLE_LIST, "Zarz¹dzanie firm¹", string, "Wybierz", "Zamknij");
}

stock StopJob(playerid)
{
	new enginedyn, lights, alarm, bonnet, boot, objective, doors;
	new Float:vehPosX, Float:vehPosY, Float:vehPosZ;
	
	switch(gPlayerData[playerid][pJob])
	{
		case JOB_BUSDRIVER:
		{
			if(!gBusDriverOnDuty[playerid])
			{
				return;
			}
			
			gBusDriverOnDuty[playerid] = 0;
			gBusDriverCurrentCheckPoint[playerid] = 0;
			gBusDriverResetTime[playerid] = 0;
			
			DisablePlayerCheckpoint(playerid);	
			
			HideProgressBarForPlayer(playerid, JobProgress[playerid]);
			
			if(EnteredVehicleID[playerid] != 0)
			{
				if(EnteredVehicleID[playerid] == GetPlayerVehicleID(playerid))
				{
					GetVehiclePos(EnteredVehicleID[playerid], vehPosX, vehPosY, vehPosZ);
					SetPlayerToPos(playerid, vehPosX+5.0, vehPosY, vehPosZ);
				}
				
				UpdateDynamic3DTextLabelText(BusRoute[EnteredVehicleID[playerid]-1], COLOR_LIGHTYELLOW, " ");
				
				SetVehicleToPos(EnteredVehicleID[playerid], gVehData[EnteredVehicleID[playerid]-1][mVehX], gVehData[EnteredVehicleID[playerid]-1][mVehY], gVehData[EnteredVehicleID[playerid]-1][mVehZ]);
				SetVehicleZAngle(EnteredVehicleID[playerid], gVehData[EnteredVehicleID[playerid]-1][mVehA]);
				GetVehicleParamsEx(EnteredVehicleID[playerid], enginedyn, lights, alarm, doors, bonnet, boot, objective);
				SetVehicleParamsEx(EnteredVehicleID[playerid], 0, 0, alarm, doors, bonnet, boot, objective);
				
				gVehData[EnteredVehicleID[playerid]-1][EngineOn] = 0;
				gVehData[EnteredVehicleID[playerid]-1][LightsOn] = 0;
				SaveVehData(EnteredVehicleID[playerid]-1, "EngineOn");
				SaveVehData(EnteredVehicleID[playerid]-1, "LightsOn");
				
				EnteredVehicleID[playerid] = 0;
			}
		}
		case JOB_TRASHDRIVER:
		{
			if(!gTrashDriverOnDuty[playerid])
			{
				return;
			}
			
			gTrashDriverOnDuty[playerid] = 0;
			gTrashDriverCurrentCheckPoint[playerid] = 0;
			gTrashDriverResetTime[playerid] = 0;
			
			DisablePlayerCheckpoint(playerid);	
			
			HideProgressBarForPlayer(playerid, JobProgress[playerid]);
			
			if(EnteredVehicleID[playerid] != 0)
			{
				if(EnteredVehicleID[playerid] == GetPlayerVehicleID(playerid))
				{
					GetVehiclePos(EnteredVehicleID[playerid], vehPosX, vehPosY, vehPosZ);
					SetPlayerToPos(playerid, vehPosX+5.0, vehPosY, vehPosZ);
				}
			
				SetVehicleToPos(EnteredVehicleID[playerid], gVehData[EnteredVehicleID[playerid]-1][mVehX], gVehData[EnteredVehicleID[playerid]-1][mVehY], gVehData[EnteredVehicleID[playerid]-1][mVehZ]);
				SetVehicleZAngle(EnteredVehicleID[playerid], gVehData[EnteredVehicleID[playerid]-1][mVehA]);
				GetVehicleParamsEx(EnteredVehicleID[playerid], enginedyn, lights, alarm, doors, bonnet, boot, objective);
				SetVehicleParamsEx(EnteredVehicleID[playerid], 0, 0, alarm, doors, bonnet, boot, objective);
				
				gVehData[EnteredVehicleID[playerid]-1][EngineOn] = 0;
				gVehData[EnteredVehicleID[playerid]-1][LightsOn] = 0;
				SaveVehData(EnteredVehicleID[playerid]-1, "EngineOn");
				SaveVehData(EnteredVehicleID[playerid]-1, "LightsOn");
				
				EnteredVehicleID[playerid] = 0;
			}
		}
		case JOB_SWEEPER:
		{
			if(!gSweeperDriverOnDuty[playerid])
			{
				return;
			}
			
			gSweeperDriverOnDuty[playerid] = 0;
			gSweeperDriverCurrentCheckPoint[playerid] = 0;
			gSweeperDriverResetTime[playerid] = 0;
			
			DisablePlayerCheckpoint(playerid);	
			
			HideProgressBarForPlayer(playerid, JobProgress[playerid]);
			
			if(EnteredVehicleID[playerid] != 0)
			{
				if(EnteredVehicleID[playerid] == GetPlayerVehicleID(playerid))
				{
					GetVehiclePos(EnteredVehicleID[playerid], vehPosX, vehPosY, vehPosZ);
					SetPlayerToPos(playerid, vehPosX, vehPosY, vehPosZ);
				}
			
				SetVehicleToPos(EnteredVehicleID[playerid], gVehData[EnteredVehicleID[playerid]-1][mVehX], gVehData[EnteredVehicleID[playerid]-1][mVehY], gVehData[EnteredVehicleID[playerid]-1][mVehZ]);
				SetVehicleZAngle(EnteredVehicleID[playerid], gVehData[EnteredVehicleID[playerid]-1][mVehA]);
				GetVehicleParamsEx(EnteredVehicleID[playerid], enginedyn, lights, alarm, doors, bonnet, boot, objective);
				SetVehicleParamsEx(EnteredVehicleID[playerid], 0, 0, alarm, doors, bonnet, boot, objective);
				
				gVehData[EnteredVehicleID[playerid]-1][EngineOn] = 0;
				gVehData[EnteredVehicleID[playerid]-1][LightsOn] = 0;
				SaveVehData(EnteredVehicleID[playerid]-1, "EngineOn");
				SaveVehData(EnteredVehicleID[playerid]-1, "LightsOn");
				
				EnteredVehicleID[playerid] = 0;
			}
		}
		case JOB_FARMER:
		{
			if(!gFarmerDriverOnDuty[playerid])
			{
				return;
			}
			
			gFarmerDriverOnDuty[playerid] = 0;
			gFarmerDriverCurrentCheckPoint[playerid] = 0;
			gFarmerDriverResetTime[playerid] = 0;
			
			DisablePlayerCheckpoint(playerid);
			
			HideProgressBarForPlayer(playerid, JobProgress[playerid]);
			
			if(EnteredVehicleID[playerid] != 0)
			{
				if(EnteredVehicleID[playerid] == GetPlayerVehicleID(playerid))
				{
					GetVehiclePos(EnteredVehicleID[playerid], vehPosX, vehPosY, vehPosZ);
					SetPlayerToPos(playerid, vehPosX, vehPosY, vehPosZ);
				}
			
				SetVehicleToPos(EnteredVehicleID[playerid], gVehData[EnteredVehicleID[playerid]-1][mVehX], gVehData[EnteredVehicleID[playerid]-1][mVehY], gVehData[EnteredVehicleID[playerid]-1][mVehZ]);
				SetVehicleZAngle(EnteredVehicleID[playerid], gVehData[EnteredVehicleID[playerid]-1][mVehA]);
				GetVehicleParamsEx(EnteredVehicleID[playerid], enginedyn, lights, alarm, doors, bonnet, boot, objective);
				SetVehicleParamsEx(EnteredVehicleID[playerid], 0, 0, alarm, doors, bonnet, boot, objective);
				
				gVehData[EnteredVehicleID[playerid]-1][EngineOn] = 0;
				gVehData[EnteredVehicleID[playerid]-1][LightsOn] = 0;
				SaveVehData(EnteredVehicleID[playerid]-1, "EngineOn");
				SaveVehData(EnteredVehicleID[playerid]-1, "LightsOn");
				
				EnteredVehicleID[playerid] = 0;
			}
		}
	}
}

stock UpdateCharDescription(playerid)
{
	new string[160];

	if(strcmp(gPlayerData[playerid][pCharDescriptionColor], "white", true) == 0)
	{
		format(string, sizeof(string), "{FFFFFF} %s", gPlayerData[playerid][pCharDescription]);		
	}
	else if(strcmp(gPlayerData[playerid][pCharDescriptionColor], "yellow", true) == 0)
	{
		format(string, sizeof(string), "{FFFF00} %s", gPlayerData[playerid][pCharDescription]);		
	}
	else if(strcmp(gPlayerData[playerid][pCharDescriptionColor], "green", true) == 0)
	{
		format(string, sizeof(string), "{9ACD32} %s", gPlayerData[playerid][pCharDescription]);		
	}
	else if(strcmp(gPlayerData[playerid][pCharDescriptionColor], "red", true) == 0)
	{
		format(string, sizeof(string), "{A10000} %s", gPlayerData[playerid][pCharDescription]);		
	}
	
	Update3DTextLabelText(gPlayerData[playerid][pCharDescriptionID], COLOR_BLACK, string);
}

timer SetCameraBehindPlayerEx[5000](playerid)
{
	SetCameraBehindPlayer(playerid);
}

timer TaxiTpPlayer[10000](playerid)
{
	SetCameraBehindPlayer(playerid);
	SetPlayerVirtualWorld(playerid, 0);
	SetPlayerToPos(playerid, gTaxiLocations[gPlayerVars[playerid][mIsInTaxiTeleportId]][mPosX], gTaxiLocations[gPlayerVars[playerid][mIsInTaxiTeleportId]][mPosY], gTaxiLocations[gPlayerVars[playerid][mIsInTaxiTeleportId]][mPosZ]);
}

timer SetPlayerIdleAnimation[6800](playerid)
{
	ApplyAnimation(playerid, "PED", "IDLE_stance", 4.1, 1, 1, 1, 1, 1);
	gPlayerVars[playerid][mIsIdleAnimationTimerActive] = false;
	//ClearAnimations(playerid);
}

// Thats all folks :-)