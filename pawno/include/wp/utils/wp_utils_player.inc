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
		if(!IsPlayerAttachedObjectSlotUsed(playerid, MAX_PLAYER_ATTACHED_OBJECTS-5))
		{
			new model;
			if((gPlayerData[playerid][pSkin] >= 265 && gPlayerData[playerid][pSkin] <= 267) ||
				(gPlayerData[playerid][pSkin] >= 280 && gPlayerData[playerid][pSkin] <= 288))
			{
				model = 19142;
			}
			else
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
		if(gPlayerData[playerid][pDuty])
		{
			if(DynamicFactions[gPlayerData[playerid][pFaction]][fUseSkins])
				SetPlayerToFactionSkin(playerid);
			else
				SetPlayerSkin(playerid,gPlayerData[playerid][pSkin]);
		}
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
	else if(gPlayerData[playerid][pJailed] > 0)
		SetPlayerSkin(playerid,96);
	else
		SetPlayerSkin(playerid,gPlayerData[playerid][pSkin]);		
		
	if(gPlayerData[playerid][pHP] <= 0.0)
	{
		format(string, sizeof(string), "[WARNING:] Player HP below 0 !");
		ErrorLog(string);
		SetPlayerHealth(playerid,30.0);
	}
	else
		SetPlayerHealth(playerid,gPlayerData[playerid][pHP]);
	
	SetPlayerArmourEx(playerid, gPlayerData[playerid][pArmour]);
	
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
		PlayerPlaySound(playerid, 1186, 0.0, 0.0, 0.0); // blank sound
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
			SetSpawnInfo(playerid, 0, gPlayerData[playerid][pSkin], CivilianSpawn[X],CivilianSpawn[Y],CivilianSpawn[Z],0,0,0,0,0,0,0);
		else
			SetSpawnInfo(playerid, 0, gPlayerData[playerid][pSkin], gPlayerData[playerid][pCrashX], gPlayerData[playerid][pCrashY], gPlayerData[playerid][pCrashZ], gPlayerData[playerid][pCrashAngle],0,0,0,0,0,0);			
		return 1;
	}
	else
	{	
		if(AdminDuty[playerid])
		{
			if(gPlayerData[playerid][pCrashX] == 0.0 || gPlayerData[playerid][pCrashY] == 0.0 || gPlayerData[playerid][pCrashY] == 0.0)
				SetSpawnInfo(playerid, 0, gPlayerData[playerid][pSkin], CivilianSpawn[Y],CivilianSpawn[Y],CivilianSpawn[Z],0,0,0,0,0,0,0);
			else
				SetSpawnInfo(playerid, 0, gPlayerData[playerid][pSkin], gPlayerData[playerid][pCrashX], gPlayerData[playerid][pCrashY], gPlayerData[playerid][pCrashZ], gPlayerData[playerid][pCrashAngle],0,0,0,0,0,0);
		}
		else
		{
			// if(gPlayerData[playerid][pJailed] == 1 &&
				// (floatabs(gPlayerData[playerid][pCrashX] - 268.0) > 10.0 || floatabs(gPlayerData[playerid][pCrashY]) > 10.0 || floatabs(gPlayerData[playerid][pCrashZ]) > 10.0))
			// {
				// DBVariables[2][varDValue]++;
				// switch(DBVariables[2][varDValue])
				// {
					// case 0: SetSpawnInfo(playerid, 0, gPlayerData[playerid][pSkin], 1778.6060791016,-1581.3503417969,1738.7172851563,0,0,0,0,0,0,0);
					// case 1: SetSpawnInfo(playerid, 0, gPlayerData[playerid][pSkin], 1778.60546875,-1581.349609375,1734.9417724609,0,0,0,0,0,0,0);
					// case 2: SetSpawnInfo(playerid, 0, gPlayerData[playerid][pSkin], 1774.3107910156,-1580.8834228516,1734.9429931641,0,0,0,0,0,0,0);
					// case 3: SetSpawnInfo(playerid, 0, gPlayerData[playerid][pSkin], 1770.0396728516,-1580.9715576172,1734.9429931641,0,0,0,0,0,0,0);
					// case 4: SetSpawnInfo(playerid, 0, gPlayerData[playerid][pSkin], 1765.6442871094,-1581.0885009766,1734.9429931641,0,0,0,0,0,0,0);
					// case 5: SetSpawnInfo(playerid, 0, gPlayerData[playerid][pSkin], 1761.5192871094,-1580.9661865234,1734.9429931641,0,0,0,0,0,0,0);
					// case 6: SetSpawnInfo(playerid, 0, gPlayerData[playerid][pSkin], 1757.1713867188,-1581.1558837891,1734.9429931641,0,0,0,0,0,0,0);
					// case 7: SetSpawnInfo(playerid, 0, gPlayerData[playerid][pSkin], 1757.3331298828,-1565.4664306641,1734.9429931641,0,0,0,0,0,0,0);
					// case 8: SetSpawnInfo(playerid, 0, gPlayerData[playerid][pSkin], 1761.7298583984,-1565.6207275391,1734.9429931641,0,0,0,0,0,0,0);
					// case 9: SetSpawnInfo(playerid, 0, gPlayerData[playerid][pSkin], 1765.9074707031,-1565.1364746094,1734.9429931641,0,0,0,0,0,0,0);
					// case 10: SetSpawnInfo(playerid, 0, gPlayerData[playerid][pSkin], 1770.2448730469,-1565.3743896484,1734.9429931641,0,0,0,0,0,0,0);
					// case 11: SetSpawnInfo(playerid, 0, gPlayerData[playerid][pSkin], 1774.5153808594,-1565.1875,1734.9429931641,0,0,0,0,0,0,0);
					// case 12: SetSpawnInfo(playerid, 0, gPlayerData[playerid][pSkin], 1778.6448974609,-1565.0377197266,1734.9429931641,0,0,0,0,0,0,0);
					// case 13: SetSpawnInfo(playerid, 0, gPlayerData[playerid][pSkin], 1774.236328125,-1580.9116210938,1738.7172851563,0,0,0,0,0,0,0);
					// case 14: SetSpawnInfo(playerid, 0, gPlayerData[playerid][pSkin], 1770.1110839844,-1580.9205322266,1738.7172851563,0,0,0,0,0,0,0);
					// case 15: SetSpawnInfo(playerid, 0, gPlayerData[playerid][pSkin], 1765.7939453125,-1581.2406005859,1738.7172851563,0,0,0,0,0,0,0);
					// case 16: SetSpawnInfo(playerid, 0, gPlayerData[playerid][pSkin], 1761.4822998047,-1581.0185546875,1738.7172851563,0,0,0,0,0,0,0);
					// case 17: SetSpawnInfo(playerid, 0, gPlayerData[playerid][pSkin], 1757.3651123047,-1581.0830078125,1738.7172851563,0,0,0,0,0,0,0);
					// case 18: SetSpawnInfo(playerid, 0, gPlayerData[playerid][pSkin], 1757.3023681641,-1565.8057861328,1738.6934814453,0,0,0,0,0,0,0);
					// case 19: SetSpawnInfo(playerid, 0, gPlayerData[playerid][pSkin], 1761.7540283203,-1565.4591064453,1738.6934814453,0,0,0,0,0,0,0);
					// case 20: SetSpawnInfo(playerid, 0, gPlayerData[playerid][pSkin], 1765.8216552734,-1565.5594482422,1738.6934814453,0,0,0,0,0,0,0);
					// case 21: SetSpawnInfo(playerid, 0, gPlayerData[playerid][pSkin], 1770.0919189453,-1565.4733886719,1738.6934814453,0,0,0,0,0,0,0);
					// case 22: SetSpawnInfo(playerid, 0, gPlayerData[playerid][pSkin], 1774.4881591797,-1565.1726074219,1738.6934814453,0,0,0,0,0,0,0);
					// case 23: SetSpawnInfo(playerid, 0, gPlayerData[playerid][pSkin], 1778.5562744141,-1565.2510986328,1738.6937255859,0,0,0,0,0,0,0);
				// }
				// if(DBVariables[2][varDValue] == 23)
					// DBVariables[2][varDValue] = 0;
			// }
			// else
			// {
				if(gPlayerData[playerid][pCrashX] == 0.0 || gPlayerData[playerid][pCrashY] == 0.0 || gPlayerData[playerid][pCrashY] == 0.0)
				{
					format(string, sizeof(string), "[WARNING:] Player %s pos is null", gPlayerData[playerid][pName]);
					ErrorLog(string);
					SetSpawnInfo(playerid, 0, gPlayerData[playerid][pSkin], gStartSpawnX, gStartSpawnY, gStartSpawnZ,0,0,0,0,0,0,0);
				}
				else
					SetSpawnInfo(playerid, 0, gPlayerData[playerid][pSkin], gPlayerData[playerid][pCrashX], gPlayerData[playerid][pCrashY], gPlayerData[playerid][pCrashZ], gPlayerData[playerid][pCrashAngle],0,0,0,0,0,0);
			// }
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