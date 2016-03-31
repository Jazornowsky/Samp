Timer:OneSecTimer[1000]()
{
	if( gReportCooldown > 0 )
		gReportCooldown--;
	if( gKickVoteTimeLeft > 0 )
	{
		if( !IsPlayerConnected( gKickVotePlayerToKick ) )
		{
			gKickVoteTimeLeft = 0;
			gKickVotePlayerToKick = INVALID_PLAYER_ID;
			foreach(Player, i)
				gKickVotePlayerVote[i] = 0;
			SendClientMessageToAll( COLOR_ORANGE, "{DF013A}[WParty SERVER:]{FFFFFF} Gracz opuœci³ serwer, g³osowanie przerwane" );
			return 1;
		}
		gKickVoteTimeLeft--;
		if( gKickVoteTimeLeft == 0 )
		{
			new pCount = 0, positive = 0;
			
			foreach(Player, i )
			{
				pCount++;
				if( gKickVotePlayerVote[i] == 1 )
				{
					gKickVotePlayerVote[i] = 0;
					positive++;
				}
			}
			if( positive > floatround( pCount/2, floatround_round ) )
				Kick(gKickVotePlayerToKick);
			else
				SendClientMessageToAll( COLOR_DARKRED, "{DF013A}[WParty Server:]{FFFFFF} Nie osi¹gniêto ponad 50% g³osów za, gracz zostaje !" );
			gKickVotePlayerToKick = INVALID_PLAYER_ID;			
		}
	}
	
	/*
	* Races players and stats
	*/
	if(IsAnyRaceStarted)
	{
		new string[64];
		if(RaceID != 255 && StartRaceCountDown == 1)
		{
			if(RaceCountDownTime <= 300 && RaceCountDownTime > 240)
			{
				RaceCountDownTime--;
			}
			if(RaceCountDownTime == 240)
			{
				for(new i = 0; i < sizeof(RaceDriversID); i++)
				{
					SendClientMessage(RaceDriversID[i], COLOR_LIGHTYELLOW2, "Pozosta³a 4 minuty do rozpoczêcia wyœcigu");
				}
				RaceCountDownTime--;
			}
			if(RaceCountDownTime < 240 && RaceCountDownTime > 180)
			{
				RaceCountDownTime--;
			}
			if(RaceCountDownTime == 180)
			{
				for(new i = 0; i < sizeof(RaceDriversID); i++)
				{
					SendClientMessage(RaceDriversID[i], COLOR_LIGHTYELLOW2, "Pozosta³a 3 minuty do rozpoczêcia wyœcigu");
				}
				RaceCountDownTime--;
			}
			if(RaceCountDownTime < 180 && RaceCountDownTime > 120)
			{
				RaceCountDownTime--;
			}
			if(RaceCountDownTime == 120)
			{
				for(new i = 0; i < sizeof(RaceDriversID); i++)
				{
					SendClientMessage(RaceDriversID[i], COLOR_LIGHTYELLOW2, "Pozosta³y 2 minuty do rozpoczêcia wyœcigu");
				}
				RaceCountDownTime--;
			}
			if(RaceCountDownTime < 120 && RaceCountDownTime > 60)
			{
				RaceCountDownTime--;
			}
			if(RaceCountDownTime == 60)
			{
				for(new i = 0; i < sizeof(RaceDriversID); i++)
				{
					SendClientMessage(RaceDriversID[i], COLOR_LIGHTYELLOW2, "Pozosta³a 1 minuta do rozpoczêcia wyœcigu");
				}
				RaceCountDownTime--;
			}
			if(RaceCountDownTime < 60 && RaceCountDownTime > 15)
			{
				RaceCountDownTime--;
			}
			if(RaceCountDownTime == 15)
			{
				format(string, sizeof(string), "Pozosta³o %d sekund do rozpoczêcia wyœcigu.", RaceCountDownTime);
				for(new i = 0; i < sizeof(RaceDriversID); i++)
				{
					SendClientMessage(RaceDriversID[i], COLOR_LIGHTYELLOW2, string);
					SendClientMessage(RaceDriversID[i], COLOR_LIGHTYELLOW2, "Zawodnicy proszeni s¹ o zajmowanie miejsc startowych.");
				}
				for(new n = 0; n <= DynamicRaces[RaceID][MaxDrivers]; n++)
				{
					if(strlen(RaceDrivers[n]) != 0)
					{
						SetPlayerRaceCheckpoint(RaceDriversID[n], 0,DynamicRaces[RaceID][StartPointX],DynamicRaces[RaceID][StartPointY],DynamicRaces[RaceID][StartPointZ],DynamicRaces[RaceID][FinishPointX],DynamicRaces[RaceID][FinishPointY],DynamicRaces[RaceID][FinishPointZ], 15.0);
					}
				}
				RaceCountDownTime--;
			}
			if(RaceCountDownTime < 15 && RaceCountDownTime > 10)
			{
				RaceCountDownTime--;
			}
			if(RaceCountDownTime <= 10 && RaceCountDownTime > 5)
			{
				format(string, sizeof(string), "Pozosta³o %d sekund do rozpoczêcia wyœcigu", RaceCountDownTime);
				for(new i = 0; i < sizeof(RaceDriversID); i++)
				{
					SendClientMessage(RaceDriversID[i], COLOR_LIGHTYELLOW2, string);
				}
				RaceCountDownTime--;
			}
			if(RaceCountDownTime == 0)
			{
				format(string, sizeof(string), "START !", RaceCountDownTime);
				for(new i = 0; i < sizeof(RaceDriversID); i++)
				{
					SendClientMessage(RaceDriversID[i], COLOR_LIGHTYELLOW2, string);
				}
				RaceCountDownTime--;
				RaceStarted = 1;
			}
			if(RaceCountDownTime <= 5 && RaceCountDownTime >= 0)
			{
				format(string, sizeof(string), "%d", RaceCountDownTime);
				for(new i = 0; i < sizeof(RaceDriversID); i++)
				{
					SendClientMessage(RaceDriversID[i], COLOR_LIGHTYELLOW2, string);
				}
				RaceCountDownTime--;
			}
		}
	}
	
	/*
	* Check vehicle damage status
	*/
	new Float:vehiclehp;
	new enginedyn,lights,alarm,bonnet,boot,objective, doors;
	for(new i = 0; i < sizeof(gVehData); i++)
	{
		if (gVehData[i][CarModel] == 594)
			continue;
		GetVehicleHealth(i+1,vehiclehp);
		if (vehiclehp > 100.0 && vehiclehp <= 250.0)
		{
			if (random(100) <= 50)
				continue;
			if (gVehData[i][CarDamaged] == 1)
				continue;
			SetVehicleHealth(i+1, 260.0);
			gVehData[i][CarDamaged] = 1;
			SaveVehData(i, "CarDamaged");
			
			GetVehicleParamsEx(i+1, enginedyn, lights, alarm, doors, bonnet, boot, objective);
			foreach(Player, n )
			{
				if(GetPlayerVehicleID(n) != i+1 || GetPlayerState(n) != PLAYER_STATE_DRIVER)
					continue;

				if(gVehData[i][EngineOn])
				{
					SendClientMessage(n, COLOR_RED, "[INFO:] Pojazd uleg³ uszkodzeniu ! Nie mo¿esz jechaæ dalej.");
					SetVehicleParamsEx(i+1,0,lights,alarm,doors,bonnet,boot,objective);
					gVehData[i][EngineOn] = 0;
					SaveVehData(i, "EngineOn");
				}
			}
		}
		else if (vehiclehp > 250.0 && vehiclehp <= 300.0)
		{
			SetVehicleHealth(i+1, 310.0);
			gVehData[i][CarDamaged] = 1;
			SaveVehData(i, "CarDamaged");
			GetVehicleParamsEx(i+1, enginedyn, lights, alarm, doors, bonnet, boot, objective);
			for( new n = 0; n < CUSTOM_MAX_PLAYERS; n++ )
			{
				if(GetPlayerVehicleID(n) != i+1 || GetPlayerState(n) != PLAYER_STATE_DRIVER)
					continue;

				if(gVehData[i][EngineOn] == 1)
				{
					SendClientMessage(n, COLOR_RED, "[INFO:] Pojazd uleg³ uszkodzeniu ! Nie mo¿esz jechaæ dalej.");
					SetVehicleParamsEx(i+1,0,lights,alarm,doors,bonnet,boot,objective);
					gVehData[i][EngineOn] = 0;
					SaveVehData(i, "EngineOn");
				}
			}
		}
	}

	/*
	* Check if player is in burning factory
	* Take player HP if TRUE
	*/
	for( new j = 0; j < sizeof(DynamicFactions); j++ )
	{
		if( DynamicFactions[j][fType] == 3 && DynamicFactions[j][WFactoryBurning] )
		{
			foreach(Player, i )
			{
				if( PlayerToPoint( 10.0, i, DynamicFactions[j][WFactoryCentrePosX], DynamicFactions[j][WFactoryCentrePosY], DynamicFactions[j][WFactoryCentrePosZ] ) )
				{
					gPlayerData[i][pHP] -= 2.0;
					SetPlayerHealth( i, gPlayerData[i][pHP] );
					SavePlayerData(i, "HP");
				}
			}
		}
	}

	/*
	* Other related to player stuff
	*/
	new string[256];
	new hack;
	new location[MAX_ZONE_NAME];
	new Float: posX, Float: posY, Float: posZ, Float: posA, Float: dist;
	new weapon, ammo;
	new ping;
	new vehicleID;
	new Float:vehicleHealth;
	new tmpRand;
	foreach(Player, i )
	{
		if( !gPlayerLogged[i] )
			continue;
		if( gKickVoteStartCooldown[i] > 0 )
			gKickVoteStartCooldown[i]--;
		if( gVehPosCheckCooldown[i] > 0 )
			gVehPosCheckCooldown[i]--;
		if( gAddCooldown[i] > 0 )
			gAddCooldown[i]--;
		if (gTGunIDLastCD[i] > 0)
			gTGunIDLastCD[i]--;
		else
			gTGunIDLast[i] = 0;
		if (gJustDropped[i] > 0)
			gJustDropped[i]--;
		if (gTryCoolDown[i] > 0)
			gTryCoolDown[i]--;
		if (gTransferCoolDown[i] > 0)
			gTransferCoolDown[i]--;
		if (gSprinting[i] > 0)
			gSprinting[i]--;
		if (gJumped[i] > 0)
		{
			if(gJumped[i] > 2 && gPlayerData[i][pAdmin] == 0)
			{
				SendClientMessage(i, COLOR_RED, "[INFO:] BH jest zabronione !");
				format(string, sizeof(string), "[INFO:] Gracz %s [%d] u¿ywa BH", gPlayerData[i][pName], i);
				ABroadCast(COLOR_YELLOW, string, 1);
				ApplyAnimation(i,"PED","FLOOR_hit_f",4.0,0,1,1,1,0);
				gJumped[i] = 2;
			}
			else
				gJumped[i]--;
		}
		if (gPlayerData[i][pMechanicCoolDown] > 0)
		{
			gPlayerData[i][pMechanicCoolDown]--;
			SavePlayerData(i, "MechanicCoolDown");
		}		
		if (gPlayerData[i][pCharacterDying] >= 2)
		{
			gPlayerData[i][pCharacterDying]--;
			SavePlayerData(i, "CharacterDying");
		}
		// Return player to life instead of killing...
		else if (gPlayerData[i][pCharacterDying] == 1)
		{
			SetPlayerHealth( i, 30.0 );
			gPlayerData[i][pHP] = 30.0;
			SavePlayerData( i, "HP" );
			gPlayerData[i][pCharacterDying] = 0;			
			SavePlayerData(i, "CharacterDying");			
			TogglePlayerControllable( i,1 );
			SetCameraBehindPlayer( i );
			ApplyAnimation(i,"PED","getup",4.0,0,0,0,0,0);
			if(PlayerCuffed[i])
				TogglePlayerControllable(i,0);
			TextDrawShowForPlayer(i, Status[i]);
			SendClientMessage(i, COLOR_GREEN, "[INFO:] Odzyska³eœ przytomnoœæ lecz nie pamiêtasz nic z obecnego dnia !");
		}
		for(new k = 0; k < sizeof(Houses); k++)
		{
			if(gLastHVisit[i][k] > 0)
				gLastHVisit[i][k]--;
		}
		for(new k = 0; k < sizeof(Businesses); k++)
		{
			if(gLastBVisit[i][k] > 0)
				gLastBVisit[i][k]--;
		}
		if( gPlayerData[i][pFaction] != 255 )
		{
			if( DynamicFactions[gPlayerData[i][pFaction]][fType] == 3 && gGangWar[Enabled] && ( gGangWar[FactionStarted] == gPlayerData[i][pFaction] || gGangWar[FactionAttacked] == gPlayerData[i][pFaction] ) )
			{
				if( gPlayerData[i][pFaction] == gGangWar[FactionStarted] )
					format( string, sizeof(string), "TWOJ GANG %d:%d WROGI GANG", gGangWar[FactionStartedKills], gGangWar[FactionAttackedKills] );
				else
					format( string, sizeof(string), "TWOJ GANG %d:%d WROGI GANG", gGangWar[FactionAttackedKills], gGangWar[FactionStartedKills] );
				TextDrawSetString( GangWar[i], string );
			}
		}	
		if(gBusDriverOnDuty[i] == 1)
			busCheckpoints(i);
		// Update money
		if (GetPlayerCash(i) != GetPlayerMoney(i))
		{
			hack = GetPlayerMoney(i) - GetPlayerCash(i);
			if(hack >= 500)
			{
				format(string, sizeof(string), "[WARNING:] %s (ID:%d) tried to spawn $%d - This could be a money cheat.",gPlayerData[i][pName],i, hack);
				HackLog(string);
				ABroadCast(COLOR_YELLOW,string,1);
			}
			ResetMoneyBar(i);//Resets the money in the original moneybar, Do not remove!
			UpdateMoneyBar(i,gPlayerData[i][pCash]);//Sets the money in the moneybar to the serverside cash, Do not remove!
		}
		// player status bar
		if(PlayerStatusShowed[i])
		{
			GetPlayer2DZone(i, location, MAX_ZONE_NAME);
			new string2[128];
			if(gPlayerData[i][pGPS] == 0)
				format(string2, sizeof(string), "~y~Lokacja: ~w~brak modulu GPS");
			else if(gPlayerData[i][pGPS] == 1)
			{
				if(gpsOn[i] == 0) { format(string2, sizeof(string), "~y~Lokacja: ~w~modul GPS wylaczony", location); }
				if(gpsOn[i] == 1) { format(string2, sizeof(string), "~y~Lokacja: ~w~%s", location); }
			}
			if( gSpectateID[i] != INVALID_PLAYER_ID && GetPlayerState(i) == PLAYER_STATE_SPECTATING )
			{
				GetPlayer2DZone( gSpectateID[i], location, MAX_ZONE_NAME );
				if(gPlayerData[ gSpectateID[i] ][pFaction] != 255)
					format(string, sizeof(string), "~y~Poziom postaci: ~w~%d ~y~Doswiadczenie: ~w~%d/%d ~y~Frakcja: ~w~%s ~y~Lokacja: ~w~%s", gPlayerData[gSpectateID[i]][pLevel], gPlayerData[gSpectateID[i]][pExp], (gPlayerData[gSpectateID[i]][pLevel]+1)*levelexp, DynamicFactions[gPlayerData[gSpectateID[i]][pFaction]][Name], location);
				else
					format(string, sizeof(string), "~y~Poziom postaci: ~w~%d ~y~Doswiadczenie: ~w~%d/%d ~y~Frakcja: ~w~Brak ~y~Lokacja: ~w~%s", gPlayerData[gSpectateID[i]][pLevel], gPlayerData[gSpectateID[i]][pExp], (gPlayerData[gSpectateID[i]][pLevel]+1)*levelexp, location);
			}
			else
			{
				if(gPlayerData[i][pFaction] != 255)
					format(string, sizeof(string), "~y~Poziom postaci: ~w~%d ~y~Doswiadczenie: ~w~%d/%d ~y~Frakcja: ~w~%s ~y~Lokacja: ~w~%s", gPlayerData[i][pLevel], gPlayerData[i][pExp], (gPlayerData[i][pLevel]+1)*levelexp, DynamicFactions[gPlayerData[i][pFaction]][Name], location);
				else
					format(string, sizeof(string), "~y~Poziom postaci: ~w~%d ~y~Doswiadczenie: ~w~%d/%d ~y~Frakcja: ~w~Brak ~y~Lokacja: ~w~%s", gPlayerData[i][pLevel], gPlayerData[i][pExp], (gPlayerData[i][pLevel]+1)*levelexp, location);
			}
			TextDrawSetString(PlayerStatus[i], string);
		}
		// GPS status bar
		if(gPlayerData[i][pGPS] == 1 && gpsOn[i] == 1)
		{
			GetPlayerPos(i, posX, posY, posZ);
			GetPlayerFacingAngle(i, posA);
			format(string, sizeof(string), "X: %f; Y: %f; Z: %f; A: %f", posX, posY, posZ, posA);
			TextDrawSetString(GPSText[i], string);
			// TextDrawUseBox(GPSText[i], 1);
			// TextDrawBoxColor(GPSText[i], COLOR_BLACK);
			TextDrawLetterSize(GPSText[i], 0.15, 0.9);
			TextDrawTextSize(GPSText[i], 190.0, 100.0);
			TextDrawShowForPlayer(i, GPSText[i]);
		}
		// UAC system
		if(Spawned[i] == 1 && IsPlayerNPC(i) == 0 && gPlayerData[i][pAdmin] == 0)
		{
			// AntiAmmoHack
			for(new slot = 1; slot < 13; slot++)
			{
				GetPlayerWeaponData(i, slot, weapon, ammo);
				//printf("Ammo: %d, slot: %d, weapon: %d, Gun[i][Weapon][slot]: %d", ammo, slot, weapon, Gun[i][Weapon][slot]);
				if (Gun[i][Weapon][slot] != weapon)
				{
					if (ammo > Ammo[i][weapon])
					{
						if ((ammo - Ammo[i][weapon]) >= UAC_MAX_AMMO)
						{
							printf("ammo: %d, Ammo[%d][%d]: %d", ammo, i, weapon, Ammo[i][weapon]);
							SendClientMessage(i, COLOR_RED, "[ANTI-CHEAT:] Zosta³eœ wyrzucony za u¿ywanie cheatów ! (AmmoHack) !");
							format(string, sizeof(string), "[ANTI-CHEAT:] %s (id:%d) zosta³ wyrzucony za u¿ywanie cheatów ! (AmmoHack)", GetName(i), i);
							SendClientMessageToAll(COLOR_LIGHTGREEN, string);
							Kick(i);
							break;
						}
					}
				}
			}
			// AntiPositionHack
			if(!gPlayerData[i][pModerator])
			{
				if(!PosHackCheckTime[i])
				{
					if(GetDistanceToPoint(i,NewPos[i][0],NewPos[i][1],NewPos[i][2]) > 500 && GetPlayerState(i) != PLAYER_STATE_PASSENGER)
					{
						format(string,sizeof(string), "[ANTI-CHEAT:] Zosta³eœ wyrzucony za u¿ywanie cheatów !");
						SendClientMessage(i, COLOR_RED, string);
						format(string,sizeof(string), "[ANTI-CHEAT:] %s (id:%d) zosta³ wyrzucony za u¿ywanie cheatów !", GetName(i), i);
						SendClientMessageToAll(COLOR_LIGHTGREEN, string);
						printf("[ANTI-CHEAT:] %s has been kicked for using Teleport", GetName(i));
						Kick(i);
					}
					else if(GetDistanceToPoint(i,NewPos[i][0],NewPos[i][1],NewPos[i][2]) > 120 && GetPlayerState(i) == PLAYER_STATE_ONFOOT)
					{
						printf("GetDistanceToPoint = %d", GetDistanceToPoint(i,NewPos[i][0],NewPos[i][1],NewPos[i][2]));
						format(string,sizeof(string), "[ANTI-CHEAT:] Zosta³eœ wyrzucony za u¿ywanie cheatów !");
						SendClientMessage(i, COLOR_RED, string);
						format(string,sizeof(string), "[ANTI-CHEAT:] %s (id:%d) zosta³ wyrzucony za u¿ywanie cheatów !", GetName(i), i, MAX_PING);
						SendClientMessageToAll(COLOR_LIGHTGREEN, string);
						printf("[ANTI-CHEAT:] %s has been kicked for using Teleport", GetName(i));
						Kick(i);
					}
				}
				else
				{
					PosHackCheckTime[i]--;
				}
				GetPlayerPos(i,NewPos[i][0],NewPos[i][1],NewPos[i][2]);
			}
			// AntiJetPack
			if(GetPlayerSpecialAction(i) == 2) //Jetpack
			{
				SendClientMessage(i, COLOR_RED, "[ANTI-CHEAT:] Zosta³eœ wyrzucony za u¿ywanie cheatów !");
				format(string,sizeof(string), "[ANTI-CHEAT:] %s (id:%d) zosta³ wyrzucony za u¿ywanie cheatów !", GetName(i), i);
				SendClientMessageToAll(COLOR_LIGHTGREEN, string);
				printf("[ANTI-CHEAT:] %s has been kicked for using Jetpack Hack", GetName(i));
				Kick(i);
			}
			// AntiArmourHack
			GetPlayerArmour(i, gArmourUAC);
			if(gArmourUAC > 105)
			{
				SendClientMessage(i, COLOR_RED, "[ANTI-CHEAT:] Zosta³eœ wyrzucony za u¿ywanie cheatów !");
				format(string,sizeof(string), "[ANTI-CHEAT:] %s (id:%d) zosta³ wyrzucony za u¿ywanie cheatów !", GetName(i), i);
				SendClientMessageToAll(COLOR_LIGHTGREEN, string);
				printf("[ANTI-CHEAT:] %s has been kicked for using Armour Hack", GetName(i));
				Kick(i);
			}
			// AntiHealthHack
			GetPlayerHealth(i, gHealthUAC);
			if(gHealthUAC > 135 && gPlayerData[i][pCharacterDying] == 0)
			{
				SendClientMessage(i, COLOR_RED, "[ANTI-CHEAT:] Zosta³eœ wyrzucony za u¿ywanie cheatów !");
				format(string,sizeof(string), "[ANTI-CHEAT:] %s (id:%d) zosta³ wyrzucony za u¿ywanie cheatów !", GetName(i), i);
				SendClientMessageToAll(COLOR_LIGHTGREEN, string);
				printf("[ANTI-CHEAT:] %s has been kicked for using Health Hack", GetName(i));
				Kick(i);
			}
			// HighPingKick
			ping = GetPlayerPing(i);
			if(ping > MAX_PING)
			{
				gPingHitLimit[i]++;
				if( gPingHitLimit[i] == MAX_PING_HIT_LIMIT )
				{
					format(string,sizeof(string), "[ANTI-CHEAT:] Zosta³eœ wyrzucony za wysoki ping ! (HighPing [Max Ping: %d])", MAX_PING);
					SendClientMessage(i, COLOR_RED, string);
					format(string,sizeof(string), "[ANTI-CHEAT:] %s (id:%d) zosta³ wyrzucony za wysoki ping ! (HighPing [Max Ping: %d])", GetName(i), i, MAX_PING);
					SendClientMessageToAll(COLOR_LIGHTGREEN, string);
					printf("[ANTI-CHEAT:] %s has been kicked for High Ping", GetName(i));
					Kick(i);
				}
			}
			else
			{
				if(gPingHitLimit[i] > 0)
				{
					gPingHitLimit[i]--;
				}
			}

		}
		// jail timer
		if(gPlayerData[i][pJailed] == 1)
		{
			if(gPlayerData[i][pJailTime] > 0)
			{
				gPlayerData[i][pJailTime]--;
				SavePlayerData(i, "JailTime");

				format(string, sizeof(string), "~n~~n~~n~~n~~n~~n~~n~~w~Pozostalo czasu: ~g~%d sekund.",gPlayerData[i][pJailTime]);
				GameTextForPlayer(i, string, 999, 3);
			}
			else if(gPlayerData[i][pJailTime] == 0)
			{
				gPlayerData[i][pJailed] = 0;
				SavePlayerData(i, "Jailed");

				if(!PlayerToPoint(8.0, i, 268.0, 77.0, 1001.0))
				{
					SetPlayerToPos(i,-302.0,1504.0, 76.5);
					SetPlayerInterior(i, 0);
					SetPlayerVirtualWorld(i,0);

					gPlayerData[i][pCrashInt] = 0;
					gPlayerData[i][pCrashW] = 0;
				}
				else
					SetPlayerToPos(i,268.0,77.0, 1001.0);

				if( gPlayerData[i][pDuty] && DynamicFactions[gPlayerData[i][pFaction]][fUseSkins] )
					SetPlayerToFactionSkin(i);
				else
					SetPlayerSkin(i,gPlayerData[i][pSkin]);
				
				GetPlayerPos(i,posX,posY,posZ);
				gPlayerData[i][pCrashX] = posX;
				gPlayerData[i][pCrashY] = posY;
				gPlayerData[i][pCrashZ] = posZ;
				SavePlayerData(i, "Crash");

				if(posX == 0.0 || posY == 0.0)
					printf("[WARNING:] Jailed x = %d, y = %d", posX, posY);

				TogglePlayerControllable(i, 0);
				unfreezeTPPlayer(i);

				SendClientMessage(i, COLOR_LIGHTYELLOW2,"[INFO:] Zosta³eœ rozgrzeszony i wypuszczony.");
			}
		}
		// Vehicle speedometer and counter
		if(IsPlayerConnected(i) && Alive[i] == 1 && IsPlayerInAnyVehicle(i))
		{
			vehicleID = GetPlayerVehicleID(i);
			
			GetVehicleVelocity(vehicleID, posX, posY, posZ);
			// dist = floatsqroot(floatpower(posX, 2) + floatpower(posY, 2) + floatpower(posZ, 2)) * 136.666667;
			dist = floatsqroot(floatpower(posX, 2) + floatpower(posY, 2) + floatpower(posZ, 2)) * 200.0;

			if(CheckDelay[i] >= 1)
				CheckDelay[i]--;
			else
			{
                if(floatround(dist) < 1000)
				{
					if(IsPlayerTaxiPassenger[i])
						Distance[i] += floatround(dist);
					gVehData[vehicleID-1][CarCounter] += floatround(dist, floatround_round);
					SaveVehData(vehicleID-1, "CarCounter");
				}
			}
		}
		if(gMzgkDriverOnDuty[i] == 1)
		{
			vehicleID = GetPlayerVehicleID(i);
			if(gPlayerData[i][pMzgkJobPoints] == 30*gPlayerData[i][pMzgkJobLvl] + gPlayerData[i][pMzgkJobLvl]*10)
			{
				if(gPlayerData[i][pMzgkJobLvl] >= 23)
				{
					gPlayerData[i][pMzgkJobLvl] = 23;
					gPlayerData[i][pMzgkJobPoints] = 30*gPlayerData[i][pMzgkJobLvl] + gPlayerData[i][pMzgkJobLvl]*10;

					SavePlayerData(i, "MzgkJobPoints");
					SavePlayerData(i, "MzgkJobLvl");

					SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pMzgkJobPoints]));
					UpdateProgressBar(JobProgress[i], i);
				}
				else
				{
					gPlayerData[i][pMzgkJobLvl]++;
					gPlayerData[i][pExp]++;
					gPlayerData[i][pMzgkJobPoints] = 0;

					SavePlayerData(i, "MzgkJobPoints");
					SavePlayerData(i, "MzgkJobLvl");
					SavePlayerData(i, "Exp");

					SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pMzgkJobPoints]));
					UpdateProgressBar(JobProgress[i], i);
					format(string, sizeof(string), "[INFO:] Osi¹gn¹³eœ %d poziom jako kierowca œmieciarki w MZGK !", gPlayerData[i][pMzgkJobLvl]);
					SendClientMessage(i, COLOR_LIGHTYELLOW2, string);
					if(gPlayerData[i][pExp] >= (gPlayerData[i][pLevel]+1)*levelexp)
					{
						gPlayerData[i][pLevel]++;
						gPlayerData[i][pExp] = 0;

						SavePlayerData(i, "Level");
						SavePlayerData(i, "Exp");

						format(string, sizeof(string), "[INFO:] Zdoby³eœ tak¿e nowy poziom postaci ! - %d", gPlayerData[i][pLevel]);
						SendClientMessage(i, COLOR_LIGHTYELLOW2, string);
					}
					else
					{
						SendClientMessage(i, COLOR_LIGHTYELLOW2, "[INFO:] Otrzymujesz tak¿e 1pkt do doœwiadczenia !");
					}
				}
			}
			GetVehicleHealth(vehicleID, vehicleHealth);
			if(vehicleHealth <= 600.0 && gVehHealthOnPlayerEnter[i] > 600.0 && gMzgkDriverPenaltyInformed[i] == 0 && IsPlayerInAnyVehicle(i) && gVehData[vehicleID-1][CarType] == 2)
			{
				gPlayerData[i][pCost] += 15000;
				gMzgkDriverPenaltyInformed[i] = 1;
				gPlayerData[i][pMzgkJobPoints] -= 2;

				SavePlayerData(i, "MzgkJobPoints");
				SavePlayerData(i, "Cost");

				SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pMzgkJobPoints]));
				UpdateProgressBar(JobProgress[i], i);
				SendClientMessage(i, COLOR_LIGHTYELLOW2, "[INFO:] Zosta³eœ ukarany grzywn¹ w wysokoœci 15 000$ za nieostro¿n¹ jazde");
				SendClientMessage(i, COLOR_LIGHTYELLOW2, "[INFO:] Kara zostanie automatycznie pobrana przy nastêpnej wyp³acie.");
				SendClientMessage(i, COLOR_LIGHTYELLOW2, "[INFO:] Tracisz tak¿e 2pkt pracy.");
			}
			if(gMzgkDriverSelectedLine[i] == 0)
			{
				if(gMzgkDriverCheckpointCount[i] == 10)
				{
					gMzgkDriverCurrentCheckPoint[i] = 0;
					SetPlayerCheckpoint(i, MzgkJob[CheckPoint0ax], MzgkJob[CheckPoint0ay], MzgkJob[CheckPoint0az], 5.0);
				}
				if(gMzgkDriverCheckpointCount[i] < 10 && gMzgkDriverInRoute[i] == 0 && gMzgkDriverJustStarted[i] == 1)
				{
					tmpRand = random(9) + 1;
					while(gMzgkDriverCurrentCheckPoint[i] == tmpRand)
					{
						tmpRand = random(9) + 1;
					}
					gMzgkDriverCurrentCheckPoint[i] = tmpRand;
					if(gMzgkDriverCurrentCheckPoint[i] == 1)
					{
						SetPlayerCheckpoint(i, MzgkJob[CheckPoint1ax], MzgkJob[CheckPoint1ay], MzgkJob[CheckPoint1az], 5.0);
						gMzgkDriverInRoute[i] = 1;
					}
					if(gMzgkDriverCurrentCheckPoint[i] == 2)
					{
						SetPlayerCheckpoint(i, MzgkJob[CheckPoint2ax], MzgkJob[CheckPoint2ay], MzgkJob[CheckPoint2az], 5.0);
						gMzgkDriverInRoute[i] = 1;
					}
					if(gMzgkDriverCurrentCheckPoint[i] == 3)
					{
						SetPlayerCheckpoint(i, MzgkJob[CheckPoint3ax], MzgkJob[CheckPoint3ay], MzgkJob[CheckPoint3az], 5.0);
						gMzgkDriverInRoute[i] = 1;
					}
					if(gMzgkDriverCurrentCheckPoint[i] == 4)
					{
						SetPlayerCheckpoint(i, MzgkJob[CheckPoint4ax], MzgkJob[CheckPoint4ay], MzgkJob[CheckPoint4az], 5.0);
						gMzgkDriverInRoute[i] = 1;
					}
					if(gMzgkDriverCurrentCheckPoint[i] == 5)
					{
						SetPlayerCheckpoint(i, MzgkJob[CheckPoint5ax], MzgkJob[CheckPoint5ay], MzgkJob[CheckPoint5az], 5.0);
						gMzgkDriverInRoute[i] = 1;
					}
					if(gMzgkDriverCurrentCheckPoint[i] == 6)
					{
						SetPlayerCheckpoint(i, MzgkJob[CheckPoint6ax], MzgkJob[CheckPoint6ay], MzgkJob[CheckPoint6az], 5.0);
						gMzgkDriverInRoute[i] = 1;
					}
					if(gMzgkDriverCurrentCheckPoint[i] == 7)
					{
						SetPlayerCheckpoint(i, MzgkJob[CheckPoint7ax], MzgkJob[CheckPoint7ay], MzgkJob[CheckPoint7az], 5.0);
						gMzgkDriverInRoute[i] = 1;
					}
					if(gMzgkDriverCurrentCheckPoint[i] == 8)
					{
						SetPlayerCheckpoint(i, MzgkJob[CheckPoint8ax], MzgkJob[CheckPoint8ay], MzgkJob[CheckPoint8az], 5.0);
						gMzgkDriverInRoute[i] = 1;
					}
					if(gMzgkDriverCurrentCheckPoint[i] == 9)
					{
						SetPlayerCheckpoint(i, MzgkJob[CheckPoint9ax], MzgkJob[CheckPoint9ay], MzgkJob[CheckPoint9az], 5.0);
						gMzgkDriverInRoute[i] = 1;
					}
					if(gMzgkDriverCurrentCheckPoint[i] == 10)
					{
						SetPlayerCheckpoint(i, MzgkJob[CheckPoint10ax], MzgkJob[CheckPoint10ay], MzgkJob[CheckPoint10az], 5.0);
						gMzgkDriverInRoute[i] = 1;
					}
				}
				if(gMzgkDriverJustStarted[i] == 0)
				{
					gMzgkDriverPaymentCount[i] = 0;
					gMzgkDriverCheckpointTime[i] = 10;
					gMzgkDriverJustStarted[i] = 1;
					gMzgkDriverCurrentCheckPoint[i] = 1;
					gMzgkDriverCheckpointCount[i]++;
					gMzgkDriverInRoute[i] = 1;
					gJobProfit[i]  = 0;
					SetPlayerCheckpoint(i, MzgkJob[CheckPoint1ax], MzgkJob[CheckPoint1ay], MzgkJob[CheckPoint1az], 5.0);
				}
				else if(gMzgkDriverCurrentCheckPoint[i] == 1 && gMzgkDriverCheckpointTime[i] <= 10 && IsPlayerInRangeOfPoint(i, 10.0, MzgkJob[CheckPoint1ax], MzgkJob[CheckPoint1ay], MzgkJob[CheckPoint1az]))
				{
					gMzgkDriverCheckpointTime[i]--;
					if(gMzgkDriverCheckpointTime[i] == 9)
					{
						SendClientMessage(i, COLOR_LIGHTYELLOW2, "[INFO:] Czekaj 10 sek.");
					}
					else if(gMzgkDriverCheckpointTime[i] <= 3)
					{
						format(string, sizeof(string), "[INFO:] Odjazd za: %d sek.", gMzgkDriverCheckpointTime[i]);
						SendClientMessage(i, COLOR_LIGHTYELLOW2, string);
					}
					if(gMzgkDriverCheckpointTime[i] == 0)
					{
						gMzgkDriverCheckpointCount[i]++;
						gPlayerData[i][pMzgkJobPoints]++;
						SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pMzgkJobPoints]));
						UpdateProgressBar(JobProgress[i], i);
						gJobProfit[i] += floatpower(gPlayerData[i][pMzgkJobLvl],gMzgkDriverPaymentMultiplier);

						gMzgkDriverCheckpointTime[i] = 10;
						gMzgkDriverInRoute[i] = 0;
					}
				}
				else if(gMzgkDriverCurrentCheckPoint[i] == 2 && gMzgkDriverCheckpointTime[i] <= 10 && IsPlayerInRangeOfPoint(i, 10.0, MzgkJob[CheckPoint2ax], MzgkJob[CheckPoint2ay], MzgkJob[CheckPoint2az]))
				{
					gMzgkDriverCheckpointTime[i]--;
					if(gMzgkDriverCheckpointTime[i] == 9)
					{
						SendClientMessage(i, COLOR_LIGHTYELLOW2, "[INFO:] Czekaj 10 sek.");
					}
					else if(gMzgkDriverCheckpointTime[i] <= 3)
					{
						format(string, sizeof(string), "[INFO:] Odjazd za: %d sek.", gMzgkDriverCheckpointTime[i]);
						SendClientMessage(i, COLOR_LIGHTYELLOW2, string);
					}
					if(gMzgkDriverCheckpointTime[i] == 0)
					{
						gMzgkDriverCheckpointCount[i]++;
						gPlayerData[i][pMzgkJobPoints]++;
						SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pMzgkJobPoints]));
						UpdateProgressBar(JobProgress[i], i);
						gJobProfit[i] += floatpower(gPlayerData[i][pMzgkJobLvl],gMzgkDriverPaymentMultiplier);

						gMzgkDriverCheckpointTime[i] = 10;
						gMzgkDriverInRoute[i] = 0;
					}
				}
				else if(gMzgkDriverCurrentCheckPoint[i] == 3 && gMzgkDriverCheckpointTime[i] <= 10 && IsPlayerInRangeOfPoint(i, 10.0, MzgkJob[CheckPoint3ax], MzgkJob[CheckPoint3ay], MzgkJob[CheckPoint3az]))
				{
					gMzgkDriverCheckpointTime[i]--;
					if(gMzgkDriverCheckpointTime[i] == 9)
					{
						SendClientMessage(i, COLOR_LIGHTYELLOW2, "[INFO:] Czekaj 10 sek.");
					}
					else if(gMzgkDriverCheckpointTime[i] <= 3)
					{
						format(string, sizeof(string), "[INFO:] Odjazd za: %d sek.", gMzgkDriverCheckpointTime[i]);
						SendClientMessage(i, COLOR_LIGHTYELLOW2, string);
					}
					if(gMzgkDriverCheckpointTime[i] == 0)
					{
						gMzgkDriverCheckpointCount[i]++;
						gPlayerData[i][pMzgkJobPoints]++;
						SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pMzgkJobPoints]));
						UpdateProgressBar(JobProgress[i], i);
						gJobProfit[i] += floatpower(gPlayerData[i][pMzgkJobLvl],gMzgkDriverPaymentMultiplier);

						gMzgkDriverCheckpointTime[i] = 10;
						gMzgkDriverInRoute[i] = 0;
					}
				}
				else if(gMzgkDriverCurrentCheckPoint[i] == 4 && gMzgkDriverCheckpointTime[i] <= 10 && IsPlayerInRangeOfPoint(i, 10.0, MzgkJob[CheckPoint4ax], MzgkJob[CheckPoint4ay], MzgkJob[CheckPoint4az]))
				{
					gMzgkDriverCheckpointTime[i]--;
					if(gMzgkDriverCheckpointTime[i] == 9)
					{
						SendClientMessage(i, COLOR_LIGHTYELLOW2, "[INFO:] Czekaj 10 sek.");
					}
					else if(gMzgkDriverCheckpointTime[i] <= 3)
					{
						format(string, sizeof(string), "[INFO:] Odjazd za: %d sek.", gMzgkDriverCheckpointTime[i]);
						SendClientMessage(i, COLOR_LIGHTYELLOW2, string);
					}
					if(gMzgkDriverCheckpointTime[i] == 0)
					{
						gMzgkDriverCheckpointCount[i]++;
						gPlayerData[i][pMzgkJobPoints]++;
						SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pMzgkJobPoints]));
						UpdateProgressBar(JobProgress[i], i);
						gJobProfit[i] += floatpower(gPlayerData[i][pMzgkJobLvl],gMzgkDriverPaymentMultiplier);

						gMzgkDriverCheckpointTime[i] = 10;
						gMzgkDriverInRoute[i] = 0;
					}
				}
				else if(gMzgkDriverCurrentCheckPoint[i] == 5 && gMzgkDriverCheckpointTime[i] <= 10 && IsPlayerInRangeOfPoint(i, 10.0, MzgkJob[CheckPoint5ax], MzgkJob[CheckPoint5ay], MzgkJob[CheckPoint5az]))
				{
					gMzgkDriverCheckpointTime[i]--;
					if(gMzgkDriverCheckpointTime[i] == 9)
					{
						SendClientMessage(i, COLOR_LIGHTYELLOW2, "[INFO:] Czekaj 10 sek.");
					}
					else if(gMzgkDriverCheckpointTime[i] <= 3)
					{
						format(string, sizeof(string), "[INFO:] Odjazd za: %d sek.", gMzgkDriverCheckpointTime[i]);
						SendClientMessage(i, COLOR_LIGHTYELLOW2, string);
					}
					if(gMzgkDriverCheckpointTime[i] == 0)
					{
						gMzgkDriverCheckpointCount[i]++;
						gPlayerData[i][pMzgkJobPoints]++;
						SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pMzgkJobPoints]));
						UpdateProgressBar(JobProgress[i], i);
						gJobProfit[i] += floatpower(gPlayerData[i][pMzgkJobLvl],gMzgkDriverPaymentMultiplier);

						gMzgkDriverCheckpointTime[i] = 10;
						gMzgkDriverInRoute[i] = 0;
					}
				}
				else if(gMzgkDriverCurrentCheckPoint[i] == 6 && gMzgkDriverCheckpointTime[i] <= 10 && IsPlayerInRangeOfPoint(i, 10.0, MzgkJob[CheckPoint6ax], MzgkJob[CheckPoint6ay], MzgkJob[CheckPoint6az]))
				{
					gMzgkDriverCheckpointTime[i]--;
					if(gMzgkDriverCheckpointTime[i] == 9)
					{
						SendClientMessage(i, COLOR_LIGHTYELLOW2, "[INFO:] Czekaj 10 sek.");
					}
					else if(gMzgkDriverCheckpointTime[i] <= 3)
					{
						format(string, sizeof(string), "[INFO:] Odjazd za: %d sek.", gMzgkDriverCheckpointTime[i]);
						SendClientMessage(i, COLOR_LIGHTYELLOW2, string);
					}
					if(gMzgkDriverCheckpointTime[i] == 0)
					{
						gMzgkDriverCheckpointCount[i]++;
						gPlayerData[i][pMzgkJobPoints]++;
						SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pMzgkJobPoints]));
						UpdateProgressBar(JobProgress[i], i);
						gJobProfit[i] += floatpower(gPlayerData[i][pMzgkJobLvl],gMzgkDriverPaymentMultiplier);

						gMzgkDriverCheckpointTime[i] = 10;
						gMzgkDriverInRoute[i] = 0;
					}
				}
				else if(gMzgkDriverCurrentCheckPoint[i] == 7 && gMzgkDriverCheckpointTime[i] <= 10 && IsPlayerInRangeOfPoint(i, 10.0, MzgkJob[CheckPoint7ax], MzgkJob[CheckPoint7ay], MzgkJob[CheckPoint7az]))
				{
					gMzgkDriverCheckpointTime[i]--;
					if(gMzgkDriverCheckpointTime[i] == 9)
					{
						SendClientMessage(i, COLOR_LIGHTYELLOW2, "[INFO:] Czekaj 10 sek.");
					}
					else if(gMzgkDriverCheckpointTime[i] <= 3)
					{
						format(string, sizeof(string), "[INFO:] Odjazd za: %d sek.", gMzgkDriverCheckpointTime[i]);
						SendClientMessage(i, COLOR_LIGHTYELLOW2, string);
					}
					if(gMzgkDriverCheckpointTime[i] == 0)
					{
						gMzgkDriverCheckpointCount[i]++;
						gPlayerData[i][pMzgkJobPoints]++;
						SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pMzgkJobPoints]));
						UpdateProgressBar(JobProgress[i], i);
						gJobProfit[i] += floatpower(gPlayerData[i][pMzgkJobLvl],gMzgkDriverPaymentMultiplier);

						gMzgkDriverCheckpointTime[i] = 10;
						gMzgkDriverInRoute[i] = 0;
					}
				}
				else if(gMzgkDriverCurrentCheckPoint[i] == 8 && gMzgkDriverCheckpointTime[i] <= 10 && IsPlayerInRangeOfPoint(i, 10.0, MzgkJob[CheckPoint8ax], MzgkJob[CheckPoint8ay], MzgkJob[CheckPoint8az]))
				{
					gMzgkDriverCheckpointTime[i]--;
					if(gMzgkDriverCheckpointTime[i] == 9)
					{
						SendClientMessage(i, COLOR_LIGHTYELLOW2, "[INFO:] Czekaj 10 sek.");
					}
					else if(gMzgkDriverCheckpointTime[i] <= 3)
					{
						format(string, sizeof(string), "[INFO:] Odjazd za: %d sek.", gMzgkDriverCheckpointTime[i]);
						SendClientMessage(i, COLOR_LIGHTYELLOW2, string);
					}
					if(gMzgkDriverCheckpointTime[i] == 0)
					{
						gMzgkDriverCheckpointCount[i]++;
						gPlayerData[i][pMzgkJobPoints]++;
						SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pMzgkJobPoints]));
						UpdateProgressBar(JobProgress[i], i);
						gJobProfit[i] += floatpower(gPlayerData[i][pMzgkJobLvl],gMzgkDriverPaymentMultiplier);

						gMzgkDriverCheckpointTime[i] = 10;
						gMzgkDriverInRoute[i] = 0;
					}
				}
				else if(gMzgkDriverCurrentCheckPoint[i] == 9 && gMzgkDriverCheckpointTime[i] <= 10 && IsPlayerInRangeOfPoint(i, 10.0, MzgkJob[CheckPoint9ax], MzgkJob[CheckPoint9ay], MzgkJob[CheckPoint9az]))
				{
					gMzgkDriverCheckpointTime[i]--;
					if(gMzgkDriverCheckpointTime[i] == 9)
					{
						SendClientMessage(i, COLOR_LIGHTYELLOW2, "[INFO:] Czekaj 10 sek.");
					}
					else if(gMzgkDriverCheckpointTime[i] <= 3)
					{
						format(string, sizeof(string), "[INFO:] Odjazd za: %d sek.", gMzgkDriverCheckpointTime[i]);
						SendClientMessage(i, COLOR_LIGHTYELLOW2, string);
					}
					if(gMzgkDriverCheckpointTime[i] == 0)
					{
						gMzgkDriverCheckpointCount[i]++;
						gPlayerData[i][pMzgkJobPoints]++;
						SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pMzgkJobPoints]));
						UpdateProgressBar(JobProgress[i], i);
						gJobProfit[i] += floatpower(gPlayerData[i][pMzgkJobLvl],gMzgkDriverPaymentMultiplier);

						gMzgkDriverCheckpointTime[i] = 10;
						gMzgkDriverInRoute[i] = 0;
					}
				}
				else if(gMzgkDriverCurrentCheckPoint[i] == 10 && gMzgkDriverCheckpointTime[i] <= 10 && IsPlayerInRangeOfPoint(i, 10.0, MzgkJob[CheckPoint10ax], MzgkJob[CheckPoint10ay], MzgkJob[CheckPoint10az]))
				{
					gMzgkDriverCheckpointTime[i]--;
					if(gMzgkDriverCheckpointTime[i] == 9)
					{
						SendClientMessage(i, COLOR_LIGHTYELLOW2, "[INFO:] Czekaj 10 sek.");
					}
					else if(gMzgkDriverCheckpointTime[i] <= 3)
					{
						format(string, sizeof(string), "[INFO:] Odjazd za: %d sek.", gMzgkDriverCheckpointTime[i]);
						SendClientMessage(i, COLOR_LIGHTYELLOW2, string);
					}
					if(gMzgkDriverCheckpointTime[i] == 0)
					{
						gMzgkDriverCheckpointCount[i]++;
						gPlayerData[i][pMzgkJobPoints]++;
						SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pMzgkJobPoints]));
						UpdateProgressBar(JobProgress[i], i);
						gJobProfit[i] += floatpower(gPlayerData[i][pMzgkJobLvl],gMzgkDriverPaymentMultiplier);

						gMzgkDriverCheckpointTime[i] = 10;
						gMzgkDriverInRoute[i] = 0;
					}
				}
				else if(gMzgkDriverCurrentCheckPoint[i] == 11 && gMzgkDriverCheckpointTime[i] <= 10 && IsPlayerInRangeOfPoint(i, 10.0, MzgkJob[CheckPoint11ax], MzgkJob[CheckPoint11ay], MzgkJob[CheckPoint11az]))
				{
					gMzgkDriverCheckpointTime[i]--;
					if(gMzgkDriverCheckpointTime[i] == 9)
					{
						SendClientMessage(i, COLOR_LIGHTYELLOW2, "[INFO:] Czekaj 10 sek.");
					}
					else if(gMzgkDriverCheckpointTime[i] <= 3)
					{
						format(string, sizeof(string), "[INFO:] Odjazd za: %d sek.", gMzgkDriverCheckpointTime[i]);
						SendClientMessage(i, COLOR_LIGHTYELLOW2, string);
					}
					if(gMzgkDriverCheckpointTime[i] == 0)
					{
						gMzgkDriverCheckpointCount[i]++;
						gPlayerData[i][pMzgkJobPoints]++;
						SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pMzgkJobPoints]));
						UpdateProgressBar(JobProgress[i], i);
						gJobProfit[i] += floatpower(gPlayerData[i][pMzgkJobLvl],gMzgkDriverPaymentMultiplier);

						gMzgkDriverCheckpointTime[i] = 10;
						gMzgkDriverInRoute[i] = 0;
					}
				}
				else if(gMzgkDriverCurrentCheckPoint[i] == 0 && gMzgkDriverCheckpointTime[i] <= 10 && IsPlayerInRangeOfPoint(i, 10.0, MzgkJob[CheckPoint0ax], MzgkJob[CheckPoint0ay], MzgkJob[CheckPoint0az]))
				{
					gMzgkDriverCheckpointTime[i]--;
					format(string, sizeof(string), "[INFO:] Zarobi³eœ %d$ za jazde Œmieciark¹ MZGK.", floatround(gJobProfit[i], floatround_round));
					GivePlayerCash(i, floatround(gJobProfit[i], floatround_round));
					DynamicFactions[FACTIONID_GOVERNMENT][fBank] -= gJobProfit[i];
					SaveFData(FACTIONID_GOVERNMENT, "Bank");
					SendClientMessage(i, COLOR_LIGHTYELLOW2, string);
					RemovePlayerFromVehicle(i);
					HideProgressBarForPlayer(i, JobProgress[i]);
					SetVehicleToRespawn(vehicleID);
					GetVehicleParamsEx(vehicleID, enginedyn, lights, alarm, doors, bonnet, boot, objective);
					SetVehicleParamsEx(vehicleID,0,lights,alarm,doors,bonnet,boot,objective);
					gVehData[vehicleID-1][EngineOn] = 0;
					SaveVehData( vehicleID-1, "EngineOn" );
					gVehData[vehicleID-1][CarFuel] = float(VehFTank(vehicleID));
					SaveVehData( vehicleID-1, "CarFuel" );
					DisablePlayerCheckpoint(i);
					gMzgkDriverJustStarted[i] = 0;
					gMzgkDriverOnDuty[i] = 0;
				}
				SavePlayerData(i, "MzgkJobPoints");
				SavePlayerData(i, "Cash");
			}
			else if(gMzgkDriverSelectedLine[i] == 1)
			{
				if(gMzgkDriverCheckpointCount[i] == 10)
				{
					gMzgkDriverCurrentCheckPoint[i] = 0;
					SetPlayerCheckpoint(i, MzgkJob[CheckPoint0bx], MzgkJob[CheckPoint0by], MzgkJob[CheckPoint0bz], 5.0);
				}
				if(gMzgkDriverCheckpointCount[i] < 10 && gMzgkDriverInRoute[i] == 0 && gMzgkDriverJustStarted[i] == 1)
				{
					tmpRand = random(9) + 1;
					while(gMzgkDriverCurrentCheckPoint[i] == tmpRand)
					{
						tmpRand = random(9) + 1;
					}
					gMzgkDriverCurrentCheckPoint[i] = tmpRand;
					if(gMzgkDriverCurrentCheckPoint[i] == 1)
					{
						SetPlayerCheckpoint(i, MzgkJob[CheckPoint1bx], MzgkJob[CheckPoint1by], MzgkJob[CheckPoint1bz], 5.0);
						gMzgkDriverInRoute[i] = 1;
					}
					if(gMzgkDriverCurrentCheckPoint[i] == 2)
					{
						SetPlayerCheckpoint(i, MzgkJob[CheckPoint2bx], MzgkJob[CheckPoint2by], MzgkJob[CheckPoint2bz], 5.0);
						gMzgkDriverInRoute[i] = 1;
					}
					if(gMzgkDriverCurrentCheckPoint[i] == 3)
					{
						SetPlayerCheckpoint(i, MzgkJob[CheckPoint3bx], MzgkJob[CheckPoint3by], MzgkJob[CheckPoint3bz], 5.0);
						gMzgkDriverInRoute[i] = 1;
					}
					if(gMzgkDriverCurrentCheckPoint[i] == 4)
					{
						SetPlayerCheckpoint(i, MzgkJob[CheckPoint4bx], MzgkJob[CheckPoint4by], MzgkJob[CheckPoint4bz], 5.0);
						gMzgkDriverInRoute[i] = 1;
					}
					if(gMzgkDriverCurrentCheckPoint[i] == 5)
					{
						SetPlayerCheckpoint(i, MzgkJob[CheckPoint5bx], MzgkJob[CheckPoint5by], MzgkJob[CheckPoint5bz], 5.0);
						gMzgkDriverInRoute[i] = 1;
					}
					if(gMzgkDriverCurrentCheckPoint[i] == 6)
					{
						SetPlayerCheckpoint(i, MzgkJob[CheckPoint6bx], MzgkJob[CheckPoint6by], MzgkJob[CheckPoint6bz], 5.0);
						gMzgkDriverInRoute[i] = 1;
					}
					if(gMzgkDriverCurrentCheckPoint[i] == 7)
					{
						SetPlayerCheckpoint(i, MzgkJob[CheckPoint7bx], MzgkJob[CheckPoint7by], MzgkJob[CheckPoint7bz], 5.0);
						gMzgkDriverInRoute[i] = 1;
					}
					if(gMzgkDriverCurrentCheckPoint[i] == 8)
					{
						SetPlayerCheckpoint(i, MzgkJob[CheckPoint8bx], MzgkJob[CheckPoint8by], MzgkJob[CheckPoint8bz], 5.0);
						gMzgkDriverInRoute[i] = 1;
					}
					if(gMzgkDriverCurrentCheckPoint[i] == 9)
					{
						SetPlayerCheckpoint(i, MzgkJob[CheckPoint9bx], MzgkJob[CheckPoint9by], MzgkJob[CheckPoint9bz], 5.0);
						gMzgkDriverInRoute[i] = 1;
					}
					if(gMzgkDriverCurrentCheckPoint[i] == 10)
					{
						SetPlayerCheckpoint(i, MzgkJob[CheckPoint10bx], MzgkJob[CheckPoint10by], MzgkJob[CheckPoint10bz], 5.0);
						gMzgkDriverInRoute[i] = 1;
					}
				}
				if(gMzgkDriverJustStarted[i] == 0)
				{
					gMzgkDriverPaymentCount[i] = 0;
					gMzgkDriverCheckpointTime[i] = 10;
					gMzgkDriverJustStarted[i] = 1;
					gMzgkDriverCurrentCheckPoint[i] = 1;
					gMzgkDriverInRoute[i] = 1;
					gJobProfit[i]  = 0;
					SetPlayerCheckpoint(i, MzgkJob[CheckPoint1bx], MzgkJob[CheckPoint1by], MzgkJob[CheckPoint1bz], 5.0);
				}
				else if(gMzgkDriverCurrentCheckPoint[i] == 1 && gMzgkDriverCheckpointTime[i] <= 10 && IsPlayerInRangeOfPoint(i, 10.0, MzgkJob[CheckPoint1bx], MzgkJob[CheckPoint1by], MzgkJob[CheckPoint1bz]))
				{
					gMzgkDriverCheckpointTime[i]--;
					if(gMzgkDriverCheckpointTime[i] == 9)
					{
						SendClientMessage(i, COLOR_LIGHTYELLOW2, "[INFO:] Czekaj 10 sek.");
					}
					else if(gMzgkDriverCheckpointTime[i] <= 3)
					{
						format(string, sizeof(string), "[INFO:] Odjazd za: %d sek.", gMzgkDriverCheckpointTime[i]);
						SendClientMessage(i, COLOR_LIGHTYELLOW2, string);
					}
					if(gMzgkDriverCheckpointTime[i] == 0)
					{
						gMzgkDriverCheckpointCount[i]++;
						gPlayerData[i][pMzgkJobPoints]++;
						SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pMzgkJobPoints]));
						UpdateProgressBar(JobProgress[i], i);
						gJobProfit[i] += floatpower(gPlayerData[i][pMzgkJobLvl],gMzgkDriverPaymentMultiplier);

						gMzgkDriverCheckpointTime[i] = 10;
						gMzgkDriverInRoute[i] = 0;
					}
				}
				else if(gMzgkDriverCurrentCheckPoint[i] == 2 && gMzgkDriverCheckpointTime[i] <= 10 && IsPlayerInRangeOfPoint(i, 10.0, MzgkJob[CheckPoint2bx], MzgkJob[CheckPoint2by], MzgkJob[CheckPoint2bz]))
				{
					gMzgkDriverCheckpointTime[i]--;
					if(gMzgkDriverCheckpointTime[i] == 9)
					{
						SendClientMessage(i, COLOR_LIGHTYELLOW2, "[INFO:] Czekaj 10 sek.");
					}
					else if(gMzgkDriverCheckpointTime[i] <= 3)
					{
						format(string, sizeof(string), "[INFO:] Odjazd za: %d sek.", gMzgkDriverCheckpointTime[i]);
						SendClientMessage(i, COLOR_LIGHTYELLOW2, string);
					}
					if(gMzgkDriverCheckpointTime[i] == 0)
					{
						gMzgkDriverCheckpointCount[i]++;
						gPlayerData[i][pMzgkJobPoints]++;
						SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pMzgkJobPoints]));
						UpdateProgressBar(JobProgress[i], i);
						gJobProfit[i] += floatpower(gPlayerData[i][pMzgkJobLvl],gMzgkDriverPaymentMultiplier);

						gMzgkDriverCheckpointTime[i] = 10;
						gMzgkDriverInRoute[i] = 0;
					}
				}
				else if(gMzgkDriverCurrentCheckPoint[i] == 3 && gMzgkDriverCheckpointTime[i] <= 10 && IsPlayerInRangeOfPoint(i, 10.0, MzgkJob[CheckPoint3bx], MzgkJob[CheckPoint3by], MzgkJob[CheckPoint3bz]))
				{
					gMzgkDriverCheckpointTime[i]--;
					if(gMzgkDriverCheckpointTime[i] == 9)
					{
						SendClientMessage(i, COLOR_LIGHTYELLOW2, "[INFO:] Czekaj 10 sek.");
					}
					else if(gMzgkDriverCheckpointTime[i] <= 3)
					{
						format(string, sizeof(string), "[INFO:] Odjazd za: %d sek.", gMzgkDriverCheckpointTime[i]);
						SendClientMessage(i, COLOR_LIGHTYELLOW2, string);
					}
					if(gMzgkDriverCheckpointTime[i] == 0)
					{
						gMzgkDriverCheckpointCount[i]++;
						gPlayerData[i][pMzgkJobPoints]++;
						SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pMzgkJobPoints]));
						UpdateProgressBar(JobProgress[i], i);
						gJobProfit[i] += floatpower(gPlayerData[i][pMzgkJobLvl],gMzgkDriverPaymentMultiplier);

						gMzgkDriverCheckpointTime[i] = 10;
						gMzgkDriverInRoute[i] = 0;
					}
				}
				else if(gMzgkDriverCurrentCheckPoint[i] == 4 && gMzgkDriverCheckpointTime[i] <= 10 && IsPlayerInRangeOfPoint(i, 10.0, MzgkJob[CheckPoint4bx], MzgkJob[CheckPoint4by], MzgkJob[CheckPoint4bz]))
				{
					gMzgkDriverCheckpointTime[i]--;
					if(gMzgkDriverCheckpointTime[i] == 9)
					{
						SendClientMessage(i, COLOR_LIGHTYELLOW2, "[INFO:] Czekaj 10 sek.");
					}
					else if(gMzgkDriverCheckpointTime[i] <= 3)
					{
						format(string, sizeof(string), "[INFO:] Odjazd za: %d sek.", gMzgkDriverCheckpointTime[i]);
						SendClientMessage(i, COLOR_LIGHTYELLOW2, string);
					}
					if(gMzgkDriverCheckpointTime[i] == 0)
					{
						gMzgkDriverCheckpointCount[i]++;
						gPlayerData[i][pMzgkJobPoints]++;
						SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pMzgkJobPoints]));
						UpdateProgressBar(JobProgress[i], i);
						gJobProfit[i] += floatpower(gPlayerData[i][pMzgkJobLvl],gMzgkDriverPaymentMultiplier);

						gMzgkDriverCheckpointTime[i] = 10;
						gMzgkDriverInRoute[i] = 0;
					}
				}
				else if(gMzgkDriverCurrentCheckPoint[i] == 5 && gMzgkDriverCheckpointTime[i] <= 10 && IsPlayerInRangeOfPoint(i, 10.0, MzgkJob[CheckPoint5bx], MzgkJob[CheckPoint5by], MzgkJob[CheckPoint5bz]))
				{
					gMzgkDriverCheckpointTime[i]--;
					if(gMzgkDriverCheckpointTime[i] == 9)
					{
						SendClientMessage(i, COLOR_LIGHTYELLOW2, "[INFO:] Czekaj 10 sek.");
					}
					else if(gMzgkDriverCheckpointTime[i] <= 3)
					{
						format(string, sizeof(string), "[INFO:] Odjazd za: %d sek.", gMzgkDriverCheckpointTime[i]);
						SendClientMessage(i, COLOR_LIGHTYELLOW2, string);
					}
					if(gMzgkDriverCheckpointTime[i] == 0)
					{
						gMzgkDriverCheckpointCount[i]++;
						gPlayerData[i][pMzgkJobPoints]++;
						SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pMzgkJobPoints]));
						UpdateProgressBar(JobProgress[i], i);
						gJobProfit[i] += floatpower(gPlayerData[i][pMzgkJobLvl],gMzgkDriverPaymentMultiplier);

						gMzgkDriverCheckpointTime[i] = 10;
						gMzgkDriverInRoute[i] = 0;
					}
				}
				else if(gMzgkDriverCurrentCheckPoint[i] == 6 && gMzgkDriverCheckpointTime[i] <= 10 && IsPlayerInRangeOfPoint(i, 10.0, MzgkJob[CheckPoint6bx], MzgkJob[CheckPoint6by], MzgkJob[CheckPoint6bz]))
				{
					gMzgkDriverCheckpointTime[i]--;
					if(gMzgkDriverCheckpointTime[i] == 9)
					{
						SendClientMessage(i, COLOR_LIGHTYELLOW2, "[INFO:] Czekaj 10 sek.");
					}
					else if(gMzgkDriverCheckpointTime[i] <= 3)
					{
						format(string, sizeof(string), "[INFO:] Odjazd za: %d sek.", gMzgkDriverCheckpointTime[i]);
						SendClientMessage(i, COLOR_LIGHTYELLOW2, string);
					}
					if(gMzgkDriverCheckpointTime[i] == 0)
					{
						gMzgkDriverCheckpointCount[i]++;
						gPlayerData[i][pMzgkJobPoints]++;
						SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pMzgkJobPoints]));
						UpdateProgressBar(JobProgress[i], i);
						gJobProfit[i] += floatpower(gPlayerData[i][pMzgkJobLvl],gMzgkDriverPaymentMultiplier);

						gMzgkDriverCheckpointTime[i] = 10;
						gMzgkDriverInRoute[i] = 0;
					}
				}
				else if(gMzgkDriverCurrentCheckPoint[i] == 7 && gMzgkDriverCheckpointTime[i] <= 10 && IsPlayerInRangeOfPoint(i, 10.0, MzgkJob[CheckPoint7bx], MzgkJob[CheckPoint7by], MzgkJob[CheckPoint7bz]))
				{
					gMzgkDriverCheckpointTime[i]--;
					if(gMzgkDriverCheckpointTime[i] == 9)
					{
						SendClientMessage(i, COLOR_LIGHTYELLOW2, "[INFO:] Czekaj 10 sek.");
					}
					else if(gMzgkDriverCheckpointTime[i] <= 3)
					{
						format(string, sizeof(string), "[INFO:] Odjazd za: %d sek.", gMzgkDriverCheckpointTime[i]);
						SendClientMessage(i, COLOR_LIGHTYELLOW2, string);
					}
					if(gMzgkDriverCheckpointTime[i] == 0)
					{
						gMzgkDriverCheckpointCount[i]++;
						gPlayerData[i][pMzgkJobPoints]++;
						SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pMzgkJobPoints]));
						UpdateProgressBar(JobProgress[i], i);
						gJobProfit[i] += floatpower(gPlayerData[i][pMzgkJobLvl],gMzgkDriverPaymentMultiplier);

						gMzgkDriverCheckpointTime[i] = 10;
						gMzgkDriverInRoute[i] = 0;
					}
				}
				else if(gMzgkDriverCurrentCheckPoint[i] == 8 && gMzgkDriverCheckpointTime[i] <= 10 && IsPlayerInRangeOfPoint(i, 10.0, MzgkJob[CheckPoint8bx], MzgkJob[CheckPoint8by], MzgkJob[CheckPoint8bz]))
				{
					gMzgkDriverCheckpointTime[i]--;
					if(gMzgkDriverCheckpointTime[i] == 9)
					{
						SendClientMessage(i, COLOR_LIGHTYELLOW2, "[INFO:] Czekaj 10 sek.");
					}
					else if(gMzgkDriverCheckpointTime[i] <= 3)
					{
						format(string, sizeof(string), "[INFO:] Odjazd za: %d sek.", gMzgkDriverCheckpointTime[i]);
						SendClientMessage(i, COLOR_LIGHTYELLOW2, string);
					}
					if(gMzgkDriverCheckpointTime[i] == 0)
					{
						gMzgkDriverCheckpointCount[i]++;
						gPlayerData[i][pMzgkJobPoints]++;
						SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pMzgkJobPoints]));
						UpdateProgressBar(JobProgress[i], i);
						gJobProfit[i] += floatpower(gPlayerData[i][pMzgkJobLvl],gMzgkDriverPaymentMultiplier);

						gMzgkDriverCheckpointTime[i] = 10;
						gMzgkDriverInRoute[i] = 0;
					}
				}
				else if(gMzgkDriverCurrentCheckPoint[i] == 9 && gMzgkDriverCheckpointTime[i] <= 10 && IsPlayerInRangeOfPoint(i, 10.0, MzgkJob[CheckPoint9bx], MzgkJob[CheckPoint9by], MzgkJob[CheckPoint9bz]))
				{
					gMzgkDriverCheckpointTime[i]--;
					if(gMzgkDriverCheckpointTime[i] == 9)
					{
						SendClientMessage(i, COLOR_LIGHTYELLOW2, "[INFO:] Czekaj 10 sek.");
					}
					else if(gMzgkDriverCheckpointTime[i] <= 3)
					{
						format(string, sizeof(string), "[INFO:] Odjazd za: %d sek.", gMzgkDriverCheckpointTime[i]);
						SendClientMessage(i, COLOR_LIGHTYELLOW2, string);
					}
					if(gMzgkDriverCheckpointTime[i] == 0)
					{
						gMzgkDriverCheckpointCount[i]++;
						gPlayerData[i][pMzgkJobPoints]++;
						SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pMzgkJobPoints]));
						UpdateProgressBar(JobProgress[i], i);
						gJobProfit[i] += floatpower(gPlayerData[i][pMzgkJobLvl],gMzgkDriverPaymentMultiplier);

						gMzgkDriverCheckpointTime[i] = 10;
						gMzgkDriverInRoute[i] = 0;
					}
				}
				else if(gMzgkDriverCurrentCheckPoint[i] == 10 && gMzgkDriverCheckpointTime[i] <= 10 && IsPlayerInRangeOfPoint(i, 10.0, MzgkJob[CheckPoint10bx], MzgkJob[CheckPoint10by], MzgkJob[CheckPoint10bz]))
				{
					gMzgkDriverCheckpointTime[i]--;
					if(gMzgkDriverCheckpointTime[i] == 9)
					{
						SendClientMessage(i, COLOR_LIGHTYELLOW2, "[INFO:] Czekaj 10 sek.");
					}
					else if(gMzgkDriverCheckpointTime[i] <= 3)
					{
						format(string, sizeof(string), "[INFO:] Odjazd za: %d sek.", gMzgkDriverCheckpointTime[i]);
						SendClientMessage(i, COLOR_LIGHTYELLOW2, string);
					}
					if(gMzgkDriverCheckpointTime[i] == 0)
					{
						gMzgkDriverCheckpointCount[i]++;
						gPlayerData[i][pMzgkJobPoints]++;
						SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pMzgkJobPoints]));
						UpdateProgressBar(JobProgress[i], i);
						gJobProfit[i] += floatpower(gPlayerData[i][pMzgkJobLvl],gMzgkDriverPaymentMultiplier);

						gMzgkDriverCheckpointTime[i] = 10;
						gMzgkDriverInRoute[i] = 0;
					}
				}
				else if(gMzgkDriverCurrentCheckPoint[i] == 11 && gMzgkDriverCheckpointTime[i] <= 10 && IsPlayerInRangeOfPoint(i, 10.0, MzgkJob[CheckPoint11bx], MzgkJob[CheckPoint11by], MzgkJob[CheckPoint11bz]))
				{
					gMzgkDriverCheckpointTime[i]--;
					if(gMzgkDriverCheckpointTime[i] == 9)
					{
						SendClientMessage(i, COLOR_LIGHTYELLOW2, "[INFO:] Czekaj 10 sek.");
					}
					else if(gMzgkDriverCheckpointTime[i] <= 3)
					{
						format(string, sizeof(string), "[INFO:] Odjazd za: %d sek.", gMzgkDriverCheckpointTime[i]);
						SendClientMessage(i, COLOR_LIGHTYELLOW2, string);
					}
					if(gMzgkDriverCheckpointTime[i] == 0)
					{
						gMzgkDriverCheckpointCount[i]++;
						gPlayerData[i][pMzgkJobPoints]++;
						SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pMzgkJobPoints]));
						UpdateProgressBar(JobProgress[i], i);
						gJobProfit[i] += floatpower(gPlayerData[i][pMzgkJobLvl],gMzgkDriverPaymentMultiplier);

						gMzgkDriverCheckpointTime[i] = 10;
						gMzgkDriverInRoute[i] = 0;
					}
				}
				else if(gMzgkDriverCurrentCheckPoint[i] == 0 && gMzgkDriverCheckpointTime[i] <= 10 && IsPlayerInRangeOfPoint(i, 10.0, MzgkJob[CheckPoint0bx], MzgkJob[CheckPoint0by], MzgkJob[CheckPoint0bz]))
				{
					gMzgkDriverCheckpointTime[i]--;
					format(string, sizeof(string), "[INFO:] Zarobi³eœ %d$ za jazde Œmieciark¹ MZGK.", floatround(gJobProfit[i], floatround_round));
					GivePlayerCash(i, floatround(gJobProfit[i], floatround_round));
					DynamicFactions[FACTIONID_GOVERNMENT][fBank] -= gJobProfit[i];
					SaveFData(FACTIONID_GOVERNMENT, "Bank");
					SendClientMessage(i, COLOR_LIGHTYELLOW2, string);
					RemovePlayerFromVehicle(i);
					HideProgressBarForPlayer(i, JobProgress[i]);
					SetVehicleToRespawn(vehicleID);
					GetVehicleParamsEx(vehicleID, enginedyn, lights, alarm, doors, bonnet, boot, objective);
					SetVehicleParamsEx(vehicleID,0,lights,alarm,doors,bonnet,boot,objective);
					gVehData[vehicleID-1][EngineOn] = 0;
					SaveVehData( vehicleID-1, "EngineOn" );
					gVehData[vehicleID-1][CarFuel] = float(VehFTank(vehicleID));
					SaveVehData( vehicleID-1, "CarFuel" );
					DisablePlayerCheckpoint(i);
					gMzgkDriverJustStarted[i] = 0;
					gMzgkDriverOnDuty[i] = 0;
				}
				SavePlayerData(i, "MzgkJobPoints");
				SavePlayerData(i, "Cash");
			}
		}
		if(gSweeperDriverOnDuty[i] == 1)
		{
			vehicleID = GetPlayerVehicleID(i);
			if(gPlayerData[i][pSweeperJobPoints] == 30*gPlayerData[i][pSweeperJobLvl] + gPlayerData[i][pSweeperJobLvl]*10)
			{
				if(gPlayerData[i][pSweeperJobLvl] >= 25)
				{
					gPlayerData[i][pSweeperJobLvl] = 25;
					gPlayerData[i][pSweeperJobPoints] = 30*gPlayerData[i][pSweeperJobLvl] + gPlayerData[i][pSweeperJobLvl]*10;

					SavePlayerData(i, "SweeperJobLvl");
					SavePlayerData(i, "SweeperJobPoints");

					SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pSweeperJobPoints]));
					UpdateProgressBar(JobProgress[i], i);
				}
				else
				{
					gPlayerData[i][pSweeperJobLvl]++;
					gPlayerData[i][pExp]++;
					gPlayerData[i][pSweeperJobPoints] = 0;

					SavePlayerData(i, "SweeperJobLvl");
					SavePlayerData(i, "SweeperJobPoints");
					SavePlayerData(i, "Exp");

					SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pSweeperJobPoints]));
					UpdateProgressBar(JobProgress[i], i);
					format(string, sizeof(string), "[INFO:] Osi¹gn¹³eœ %d poziom jako kierowca Myjki Drogowej !", gPlayerData[i][pSweeperJobLvl]);
					SendClientMessage(i, COLOR_LIGHTYELLOW2, string);
					if(gPlayerData[i][pExp] >= (gPlayerData[i][pLevel]+1)*levelexp)
					{
						gPlayerData[i][pLevel]++;
						gPlayerData[i][pExp] = 0;

						SavePlayerData(i, "Level");
						SavePlayerData(i, "Exp");

						format(string, sizeof(string), "[INFO:] Zdoby³eœ tak¿e nowy poziom postaci ! - %d", gPlayerData[i][pLevel]);
						SendClientMessage(i, COLOR_LIGHTYELLOW2, string);
					}
					else
					{
						SendClientMessage(i, COLOR_LIGHTYELLOW2, "[INFO:] Otrzymujesz tak¿e 1pkt do doœwiadczenia !");
					}
				}
			}
			GetVehicleHealth(vehicleID, vehicleHealth);
			if(vehicleHealth <= 800.0 && gVehHealthOnPlayerEnter[i] > 800.0 && gSweeperDriverPenaltyInformed[i] == 0 && IsPlayerInAnyVehicle(i) && gVehData[vehicleID-1][CarType] == 2)
			{
				gPlayerData[i][pCost] += 15000;
				gSweeperDriverPenaltyInformed[i] = 1;
				gPlayerData[i][pSweeperJobPoints] -= 2;

				SavePlayerData(i, "SweeperJobPoints");
				SavePlayerData(i, "Cost");

				SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pSweeperJobPoints]));
				UpdateProgressBar(JobProgress[i], i);
				SendClientMessage(i, COLOR_LIGHTYELLOW2, "[INFO:] Zosta³eœ ukarany grzywn¹ w wysokoœci 15 000$ za nieostro¿n¹ jazde");
				SendClientMessage(i, COLOR_LIGHTYELLOW2, "[INFO:] Kara zostanie automatycznie pobrana przy nastêpnej wyp³acie.");
				SendClientMessage(i, COLOR_LIGHTYELLOW2, "[INFO:] Tracisz tak¿e 2pkt pracy.");
			}
			if(gSweeperDriverSelectedLine[i] == 0)
			{
				if(gSweeperDriverCheckpointCount[i] == 10)
				{
					gSweeperDriverCurrentCheckPoint[i] = 0;
					SetPlayerCheckpoint(i, SweeperJob[CheckPoint0ax], SweeperJob[CheckPoint0ay], SweeperJob[CheckPoint0az], 5.0);
				}
				if(gSweeperDriverCheckpointCount[i] < 10 && gSweeperDriverInRoute[i] == 0 && gSweeperDriverJustStarted[i] == 1)
				{
					tmpRand = random(9) + 1;
					while(gSweeperDriverCurrentCheckPoint[i] == tmpRand)
					{
						tmpRand = random(9) + 1;
					}
					gSweeperDriverCurrentCheckPoint[i] = tmpRand;
					if(gSweeperDriverCurrentCheckPoint[i] == 1)
					{
						SetPlayerCheckpoint(i, SweeperJob[CheckPoint1ax], SweeperJob[CheckPoint1ay], SweeperJob[CheckPoint1az], 5.0);
						gSweeperDriverInRoute[i] = 1;
					}
					if(gSweeperDriverCurrentCheckPoint[i] == 2)
					{
						SetPlayerCheckpoint(i, SweeperJob[CheckPoint2ax], SweeperJob[CheckPoint2ay], SweeperJob[CheckPoint2az], 5.0);
						gSweeperDriverInRoute[i] = 1;
					}
					if(gSweeperDriverCurrentCheckPoint[i] == 3)
					{
						SetPlayerCheckpoint(i, SweeperJob[CheckPoint3ax], SweeperJob[CheckPoint3ay], SweeperJob[CheckPoint3az], 5.0);
						gSweeperDriverInRoute[i] = 1;
					}
					if(gSweeperDriverCurrentCheckPoint[i] == 4)
					{
						SetPlayerCheckpoint(i, SweeperJob[CheckPoint4ax], SweeperJob[CheckPoint4ay], SweeperJob[CheckPoint4az], 5.0);
						gSweeperDriverInRoute[i] = 1;
					}
					if(gSweeperDriverCurrentCheckPoint[i] == 5)
					{
						SetPlayerCheckpoint(i, SweeperJob[CheckPoint5ax], SweeperJob[CheckPoint5ay], SweeperJob[CheckPoint5az], 5.0);
						gSweeperDriverInRoute[i] = 1;
					}
					if(gSweeperDriverCurrentCheckPoint[i] == 6)
					{
						SetPlayerCheckpoint(i, SweeperJob[CheckPoint6ax], SweeperJob[CheckPoint6ay], SweeperJob[CheckPoint6az], 5.0);
						gSweeperDriverInRoute[i] = 1;
					}
					if(gSweeperDriverCurrentCheckPoint[i] == 7)
					{
						SetPlayerCheckpoint(i, SweeperJob[CheckPoint7ax], SweeperJob[CheckPoint7ay], SweeperJob[CheckPoint7az], 5.0);
						gSweeperDriverInRoute[i] = 1;
					}
					if(gSweeperDriverCurrentCheckPoint[i] == 8)
					{
						SetPlayerCheckpoint(i, SweeperJob[CheckPoint8ax], SweeperJob[CheckPoint8ay], SweeperJob[CheckPoint8az], 5.0);
						gSweeperDriverInRoute[i] = 1;
					}
					if(gSweeperDriverCurrentCheckPoint[i] == 9)
					{
						SetPlayerCheckpoint(i, SweeperJob[CheckPoint9ax], SweeperJob[CheckPoint9ay], SweeperJob[CheckPoint9az], 5.0);
						gSweeperDriverInRoute[i] = 1;
					}
					if(gSweeperDriverCurrentCheckPoint[i] == 10)
					{
						SetPlayerCheckpoint(i, SweeperJob[CheckPoint10ax], SweeperJob[CheckPoint10ay], SweeperJob[CheckPoint10az], 5.0);
						gSweeperDriverInRoute[i] = 1;
					}
				}
				if(gSweeperDriverJustStarted[i] == 0)
				{
					gSweeperDriverPaymentCount[i] = 0;
					gSweeperDriverJustStarted[i] = 1;
					gSweeperDriverCurrentCheckPoint[i] = 1;
					gSweeperDriverInRoute[i] = 1;
					gJobProfit[i]  = 0;
					SetPlayerCheckpoint(i, SweeperJob[CheckPoint1ax], SweeperJob[CheckPoint1ay], SweeperJob[CheckPoint1az], 5.0);
				}
				else if(gSweeperDriverCurrentCheckPoint[i] == 1 && IsPlayerInRangeOfPoint(i, 10.0, SweeperJob[CheckPoint1ax], SweeperJob[CheckPoint1ay], SweeperJob[CheckPoint1az]))
				{
					gSweeperDriverInRoute[i] = 0;
					gSweeperDriverCheckpointCount[i]++;
					gPlayerData[i][pSweeperJobPoints]++;
					SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pSweeperJobPoints]));
					UpdateProgressBar(JobProgress[i], i);
					gJobProfit[i] += floatpower(gPlayerData[i][pSweeperJobLvl],gSweeperDriverPaymentMultiplier);

				}
				else if(gSweeperDriverCurrentCheckPoint[i] == 2 && IsPlayerInRangeOfPoint(i, 10.0, SweeperJob[CheckPoint2ax], SweeperJob[CheckPoint2ay], SweeperJob[CheckPoint2az]))
				{
					gSweeperDriverInRoute[i] = 0;
					gSweeperDriverCheckpointCount[i]++;
					gPlayerData[i][pSweeperJobPoints]++;
					SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pSweeperJobPoints]));
					UpdateProgressBar(JobProgress[i], i);
					gJobProfit[i] += floatpower(gPlayerData[i][pSweeperJobLvl],gSweeperDriverPaymentMultiplier);

				}
				else if(gSweeperDriverCurrentCheckPoint[i] == 3 && IsPlayerInRangeOfPoint(i, 10.0, SweeperJob[CheckPoint3ax], SweeperJob[CheckPoint3ay], SweeperJob[CheckPoint3az]))
				{
					gSweeperDriverInRoute[i] = 0;
					gSweeperDriverCheckpointCount[i]++;
					gPlayerData[i][pSweeperJobPoints]++;
					SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pSweeperJobPoints]));
					UpdateProgressBar(JobProgress[i], i);
					gJobProfit[i] += floatpower(gPlayerData[i][pSweeperJobLvl],gSweeperDriverPaymentMultiplier);

				}
				else if(gSweeperDriverCurrentCheckPoint[i] == 4 && IsPlayerInRangeOfPoint(i, 10.0, SweeperJob[CheckPoint4ax], SweeperJob[CheckPoint4ay], SweeperJob[CheckPoint4az]))
				{
					gSweeperDriverInRoute[i] = 0;
					gSweeperDriverCheckpointCount[i]++;
					gPlayerData[i][pSweeperJobPoints]++;
					SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pSweeperJobPoints]));
					UpdateProgressBar(JobProgress[i], i);
					gJobProfit[i] += floatpower(gPlayerData[i][pSweeperJobLvl],gSweeperDriverPaymentMultiplier);

				}
				else if(gSweeperDriverCurrentCheckPoint[i] == 5 && IsPlayerInRangeOfPoint(i, 10.0, SweeperJob[CheckPoint5ax], SweeperJob[CheckPoint5ay], SweeperJob[CheckPoint5az]))
				{
					gSweeperDriverInRoute[i] = 0;
					gSweeperDriverCheckpointCount[i]++;
					gPlayerData[i][pSweeperJobPoints]++;
					SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pSweeperJobPoints]));
					UpdateProgressBar(JobProgress[i], i);
					gJobProfit[i] += floatpower(gPlayerData[i][pSweeperJobLvl],gSweeperDriverPaymentMultiplier);

				}
				else if(gSweeperDriverCurrentCheckPoint[i] == 6 && IsPlayerInRangeOfPoint(i, 10.0, SweeperJob[CheckPoint6ax], SweeperJob[CheckPoint6ay], SweeperJob[CheckPoint6az]))
				{
					gSweeperDriverInRoute[i] = 0;
					gSweeperDriverCheckpointCount[i]++;
					gPlayerData[i][pSweeperJobPoints]++;
					SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pSweeperJobPoints]));
					UpdateProgressBar(JobProgress[i], i);
					gJobProfit[i] += floatpower(gPlayerData[i][pSweeperJobLvl],gSweeperDriverPaymentMultiplier);

				}
				else if(gSweeperDriverCurrentCheckPoint[i] == 7 && IsPlayerInRangeOfPoint(i, 10.0, SweeperJob[CheckPoint7ax], SweeperJob[CheckPoint7ay], SweeperJob[CheckPoint7az]))
				{
					gSweeperDriverInRoute[i] = 0;
					gSweeperDriverCheckpointCount[i]++;
					gPlayerData[i][pSweeperJobPoints]++;
					SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pSweeperJobPoints]));
					UpdateProgressBar(JobProgress[i], i);
					gJobProfit[i] += floatpower(gPlayerData[i][pSweeperJobLvl],gSweeperDriverPaymentMultiplier);

				}
				else if(gSweeperDriverCurrentCheckPoint[i] == 8 && IsPlayerInRangeOfPoint(i, 10.0, SweeperJob[CheckPoint8ax], SweeperJob[CheckPoint8ay], SweeperJob[CheckPoint8az]))
				{
					gSweeperDriverInRoute[i] = 0;
					gSweeperDriverCheckpointCount[i]++;
					gPlayerData[i][pSweeperJobPoints]++;
					SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pSweeperJobPoints]));
					UpdateProgressBar(JobProgress[i], i);
					gJobProfit[i] += floatpower(gPlayerData[i][pSweeperJobLvl],gSweeperDriverPaymentMultiplier);

				}
				else if(gSweeperDriverCurrentCheckPoint[i] == 9 && IsPlayerInRangeOfPoint(i, 10.0, SweeperJob[CheckPoint9ax], SweeperJob[CheckPoint9ay], SweeperJob[CheckPoint9az]))
				{
					gSweeperDriverInRoute[i] = 0;
					gSweeperDriverCheckpointCount[i]++;
					gPlayerData[i][pSweeperJobPoints]++;
					SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pSweeperJobPoints]));
					UpdateProgressBar(JobProgress[i], i);
					gJobProfit[i] += floatpower(gPlayerData[i][pSweeperJobLvl],gSweeperDriverPaymentMultiplier);

				}
				else if(gSweeperDriverCurrentCheckPoint[i] == 10 && IsPlayerInRangeOfPoint(i, 10.0, SweeperJob[CheckPoint10ax], SweeperJob[CheckPoint10ay], SweeperJob[CheckPoint10az]))
				{
					gSweeperDriverInRoute[i] = 0;
					gSweeperDriverCheckpointCount[i]++;
					gPlayerData[i][pSweeperJobPoints]++;
					SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pSweeperJobPoints]));
					UpdateProgressBar(JobProgress[i], i);
					gJobProfit[i] += floatpower(gPlayerData[i][pSweeperJobLvl],gSweeperDriverPaymentMultiplier);

				}
				else if(gSweeperDriverCurrentCheckPoint[i] == 11 && IsPlayerInRangeOfPoint(i, 10.0, SweeperJob[CheckPoint11ax], SweeperJob[CheckPoint11ay], SweeperJob[CheckPoint11az]))
				{
					gSweeperDriverInRoute[i] = 0;
					gSweeperDriverCheckpointCount[i]++;
					gPlayerData[i][pSweeperJobPoints]++;
					SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pSweeperJobPoints]));
					UpdateProgressBar(JobProgress[i], i);
					gJobProfit[i] += floatpower(gPlayerData[i][pSweeperJobLvl],gSweeperDriverPaymentMultiplier);

				}
				else if(gSweeperDriverCurrentCheckPoint[i] == 0 && IsPlayerInRangeOfPoint(i, 10.0, SweeperJob[CheckPoint0ax], SweeperJob[CheckPoint0ay], SweeperJob[CheckPoint0az]))
				{
					format(string, sizeof(string), "[INFO:] Zarobi³eœ %d$ za jazde Myjk¹ drogow¹.", floatround(gJobProfit[i],floatround_round));
					GivePlayerCash(i, floatround(gJobProfit[i], floatround_round));
					DynamicFactions[FACTIONID_GOVERNMENT][fBank] -= gJobProfit[i];
					SaveFData(FACTIONID_GOVERNMENT, "Bank");
					SendClientMessage(i, COLOR_LIGHTYELLOW2, string);
					RemovePlayerFromVehicle(i);
					HideProgressBarForPlayer(i, JobProgress[i]);
					SetVehicleToRespawn(vehicleID);
					GetVehicleParamsEx(vehicleID, enginedyn, lights, alarm, doors, bonnet, boot, objective);
					SetVehicleParamsEx(vehicleID,0,lights,alarm,doors,bonnet,boot,objective);
					gVehData[vehicleID-1][EngineOn] = 0;
					SaveVehData( vehicleID-1, "EngineOn" );
					gVehData[vehicleID-1][CarFuel] = float(VehFTank(vehicleID));
					SaveVehData( vehicleID-1, "CarFuel" );
					DisablePlayerCheckpoint(i);
					gSweeperDriverJustStarted[i] = 0;
					gSweeperDriverOnDuty[i] = 0;
				}
				SavePlayerData(i, "SweeperJobPoints");
			}
			else if(gSweeperDriverSelectedLine[i] == 1)
			{
				if(gSweeperDriverCheckpointCount[i] == 10)
				{
					gSweeperDriverCurrentCheckPoint[i] = 0;
					SetPlayerCheckpoint(i, SweeperJob[CheckPoint0bx], SweeperJob[CheckPoint0by], SweeperJob[CheckPoint0bz], 5.0);
				}
				if(gSweeperDriverCheckpointCount[i] < 10 && gSweeperDriverInRoute[i] == 0 && gSweeperDriverJustStarted[i] == 1)
				{
					tmpRand = random(9) + 1;
					while(gSweeperDriverCurrentCheckPoint[i] == tmpRand)
					{
						tmpRand = random(9) + 1;
					}
					gSweeperDriverCurrentCheckPoint[i] = tmpRand;
					if(gSweeperDriverCurrentCheckPoint[i] == 1)
					{
						SetPlayerCheckpoint(i, SweeperJob[CheckPoint1bx], SweeperJob[CheckPoint1by], SweeperJob[CheckPoint1bz], 5.0);
						gSweeperDriverInRoute[i] = 1;
					}
					if(gSweeperDriverCurrentCheckPoint[i] == 2)
					{
						SetPlayerCheckpoint(i, SweeperJob[CheckPoint2bx], SweeperJob[CheckPoint2by], SweeperJob[CheckPoint2bz], 5.0);
						gSweeperDriverInRoute[i] = 1;
					}
					if(gSweeperDriverCurrentCheckPoint[i] == 3)
					{
						SetPlayerCheckpoint(i, SweeperJob[CheckPoint3bx], SweeperJob[CheckPoint3by], SweeperJob[CheckPoint3bz], 5.0);
						gSweeperDriverInRoute[i] = 1;
					}
					if(gSweeperDriverCurrentCheckPoint[i] == 4)
					{
						SetPlayerCheckpoint(i, SweeperJob[CheckPoint4bx], SweeperJob[CheckPoint4by], SweeperJob[CheckPoint4bz], 5.0);
						gSweeperDriverInRoute[i] = 1;
					}
					if(gSweeperDriverCurrentCheckPoint[i] == 5)
					{
						SetPlayerCheckpoint(i, SweeperJob[CheckPoint5bx], SweeperJob[CheckPoint5by], SweeperJob[CheckPoint5bz], 5.0);
						gSweeperDriverInRoute[i] = 1;
					}
					if(gSweeperDriverCurrentCheckPoint[i] == 6)
					{
						SetPlayerCheckpoint(i, SweeperJob[CheckPoint6bx], SweeperJob[CheckPoint6by], SweeperJob[CheckPoint6bz], 5.0);
						gSweeperDriverInRoute[i] = 1;
					}
					if(gSweeperDriverCurrentCheckPoint[i] == 7)
					{
						SetPlayerCheckpoint(i, SweeperJob[CheckPoint7bx], SweeperJob[CheckPoint7by], SweeperJob[CheckPoint7bz], 5.0);
						gSweeperDriverInRoute[i] = 1;
					}
					if(gSweeperDriverCurrentCheckPoint[i] == 8)
					{
						SetPlayerCheckpoint(i, SweeperJob[CheckPoint8bx], SweeperJob[CheckPoint8by], SweeperJob[CheckPoint8bz], 5.0);
						gSweeperDriverInRoute[i] = 1;
					}
					if(gSweeperDriverCurrentCheckPoint[i] == 9)
					{
						SetPlayerCheckpoint(i, SweeperJob[CheckPoint9bx], SweeperJob[CheckPoint9by], SweeperJob[CheckPoint9bz], 5.0);
						gSweeperDriverInRoute[i] = 1;
					}
					if(gSweeperDriverCurrentCheckPoint[i] == 10)
					{
						SetPlayerCheckpoint(i, SweeperJob[CheckPoint10bx], SweeperJob[CheckPoint10by], SweeperJob[CheckPoint10bz], 5.0);
						gSweeperDriverInRoute[i] = 1;
					}
				}
				if(gSweeperDriverJustStarted[i] == 0)
				{
					gSweeperDriverPaymentCount[i] = 0;
					gSweeperDriverJustStarted[i] = 1;
					gSweeperDriverCurrentCheckPoint[i] = 1;
					gSweeperDriverInRoute[i] = 1;
					SetPlayerCheckpoint(i, SweeperJob[CheckPoint1bx], SweeperJob[CheckPoint1by], SweeperJob[CheckPoint1bz], 5.0);
				}
				else if(gSweeperDriverCurrentCheckPoint[i] == 1 && IsPlayerInRangeOfPoint(i, 10.0, SweeperJob[CheckPoint1bx], SweeperJob[CheckPoint1by], SweeperJob[CheckPoint1bz]))
				{
					gSweeperDriverInRoute[i] = 0;
					gSweeperDriverCheckpointCount[i]++;
					gPlayerData[i][pSweeperJobPoints]++;
					SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pSweeperJobPoints]));
					UpdateProgressBar(JobProgress[i], i);
					gJobProfit[i] += floatpower(gPlayerData[i][pSweeperJobLvl],gSweeperDriverPaymentMultiplier);

				}
				else if(gSweeperDriverCurrentCheckPoint[i] == 2 && IsPlayerInRangeOfPoint(i, 10.0, SweeperJob[CheckPoint2bx], SweeperJob[CheckPoint2by], SweeperJob[CheckPoint2bz]))
				{
					gSweeperDriverInRoute[i] = 0;
					gSweeperDriverCheckpointCount[i]++;
					gPlayerData[i][pSweeperJobPoints]++;
					SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pSweeperJobPoints]));
					UpdateProgressBar(JobProgress[i], i);
					gJobProfit[i] += floatpower(gPlayerData[i][pSweeperJobLvl],gSweeperDriverPaymentMultiplier);

				}
				else if(gSweeperDriverCurrentCheckPoint[i] == 3 && IsPlayerInRangeOfPoint(i, 10.0, SweeperJob[CheckPoint3bx], SweeperJob[CheckPoint3by], SweeperJob[CheckPoint3bz]))
				{
					gSweeperDriverInRoute[i] = 0;
					gSweeperDriverCheckpointCount[i]++;
					gPlayerData[i][pSweeperJobPoints]++;
					SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pSweeperJobPoints]));
					UpdateProgressBar(JobProgress[i], i);
					gJobProfit[i] += floatpower(gPlayerData[i][pSweeperJobLvl],gSweeperDriverPaymentMultiplier);

				}
				else if(gSweeperDriverCurrentCheckPoint[i] == 4 && IsPlayerInRangeOfPoint(i, 10.0, SweeperJob[CheckPoint4bx], SweeperJob[CheckPoint4by], SweeperJob[CheckPoint4bz]))
				{
					gSweeperDriverInRoute[i] = 0;
					gSweeperDriverCheckpointCount[i]++;
					gPlayerData[i][pSweeperJobPoints]++;
					SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pSweeperJobPoints]));
					UpdateProgressBar(JobProgress[i], i);
					gJobProfit[i] += floatpower(gPlayerData[i][pSweeperJobLvl],gSweeperDriverPaymentMultiplier);

				}
				else if(gSweeperDriverCurrentCheckPoint[i] == 5 && IsPlayerInRangeOfPoint(i, 10.0, SweeperJob[CheckPoint5bx], SweeperJob[CheckPoint5by], SweeperJob[CheckPoint5bz]))
				{
					gSweeperDriverInRoute[i] = 0;
					gSweeperDriverCheckpointCount[i]++;
					gPlayerData[i][pSweeperJobPoints]++;
					SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pSweeperJobPoints]));
					UpdateProgressBar(JobProgress[i], i);
					gJobProfit[i] += floatpower(gPlayerData[i][pSweeperJobLvl],gSweeperDriverPaymentMultiplier);

				}
				else if(gSweeperDriverCurrentCheckPoint[i] == 6 && IsPlayerInRangeOfPoint(i, 10.0, SweeperJob[CheckPoint6bx], SweeperJob[CheckPoint6by], SweeperJob[CheckPoint6bz]))
				{
					gSweeperDriverInRoute[i] = 0;
					gSweeperDriverCheckpointCount[i]++;
					gPlayerData[i][pSweeperJobPoints]++;
					SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pSweeperJobPoints]));
					UpdateProgressBar(JobProgress[i], i);
					gJobProfit[i] += floatpower(gPlayerData[i][pSweeperJobLvl],gSweeperDriverPaymentMultiplier);

				}
				else if(gSweeperDriverCurrentCheckPoint[i] == 7 && IsPlayerInRangeOfPoint(i, 10.0, SweeperJob[CheckPoint7bx], SweeperJob[CheckPoint7by], SweeperJob[CheckPoint7bz]))
				{
					gSweeperDriverInRoute[i] = 0;
					gSweeperDriverCheckpointCount[i]++;
					gPlayerData[i][pSweeperJobPoints]++;
					SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pSweeperJobPoints]));
					UpdateProgressBar(JobProgress[i], i);
					gJobProfit[i] += floatpower(gPlayerData[i][pSweeperJobLvl],gSweeperDriverPaymentMultiplier);

				}
				else if(gSweeperDriverCurrentCheckPoint[i] == 8 && IsPlayerInRangeOfPoint(i, 10.0, SweeperJob[CheckPoint8bx], SweeperJob[CheckPoint8by], SweeperJob[CheckPoint8bz]))
				{
					gSweeperDriverInRoute[i] = 0;
					gSweeperDriverCheckpointCount[i]++;
					gPlayerData[i][pSweeperJobPoints]++;
					SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pSweeperJobPoints]));
					UpdateProgressBar(JobProgress[i], i);
					gJobProfit[i] += floatpower(gPlayerData[i][pSweeperJobLvl],gSweeperDriverPaymentMultiplier);

				}
				else if(gSweeperDriverCurrentCheckPoint[i] == 9 && IsPlayerInRangeOfPoint(i, 10.0, SweeperJob[CheckPoint9bx], SweeperJob[CheckPoint9by], SweeperJob[CheckPoint9bz]))
				{
					gSweeperDriverInRoute[i] = 0;
					gSweeperDriverCheckpointCount[i]++;
					gPlayerData[i][pSweeperJobPoints]++;
					SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pSweeperJobPoints]));
					UpdateProgressBar(JobProgress[i], i);
					gJobProfit[i] += floatpower(gPlayerData[i][pSweeperJobLvl],gSweeperDriverPaymentMultiplier);

				}
				else if(gSweeperDriverCurrentCheckPoint[i] == 10 && IsPlayerInRangeOfPoint(i, 10.0, SweeperJob[CheckPoint10bx], SweeperJob[CheckPoint10by], SweeperJob[CheckPoint10bz]))
				{
					gSweeperDriverInRoute[i] = 0;
					gSweeperDriverCheckpointCount[i]++;
					gPlayerData[i][pSweeperJobPoints]++;
					SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pSweeperJobPoints]));
					UpdateProgressBar(JobProgress[i], i);
					gJobProfit[i] += floatpower(gPlayerData[i][pSweeperJobLvl],gSweeperDriverPaymentMultiplier);

				}
				else if(gSweeperDriverCurrentCheckPoint[i] == 11 && IsPlayerInRangeOfPoint(i, 10.0, SweeperJob[CheckPoint11bx], SweeperJob[CheckPoint11by], SweeperJob[CheckPoint11bz]))
				{
					gSweeperDriverInRoute[i] = 0;
					gSweeperDriverCheckpointCount[i]++;
					gPlayerData[i][pSweeperJobPoints]++;
					SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pSweeperJobPoints]));
					UpdateProgressBar(JobProgress[i], i);
					gJobProfit[i] += floatpower(gPlayerData[i][pSweeperJobLvl],gSweeperDriverPaymentMultiplier);

				}
				else if(gSweeperDriverCurrentCheckPoint[i] == 0 && IsPlayerInRangeOfPoint(i, 10.0, SweeperJob[CheckPoint0bx], SweeperJob[CheckPoint0by], SweeperJob[CheckPoint0bz]))
				{
					format(string, sizeof(string), "[INFO:] Zarobi³eœ %d$ za jazde Myjk¹ drogow¹.", floatround(gJobProfit[i],floatround_round));
					GivePlayerCash(i, floatround(gJobProfit[i], floatround_round));
					DynamicFactions[FACTIONID_GOVERNMENT][fBank] -= gJobProfit[i];
					SaveFData(FACTIONID_GOVERNMENT, "Bank");
					SendClientMessage(i, COLOR_LIGHTYELLOW2, string);
					RemovePlayerFromVehicle(i);
					HideProgressBarForPlayer(i, JobProgress[i]);
					SetVehicleToRespawn(vehicleID);
					GetVehicleParamsEx(vehicleID, enginedyn, lights, alarm, doors, bonnet, boot, objective);
					SetVehicleParamsEx(vehicleID,0,lights,alarm,doors,bonnet,boot,objective);
					gVehData[vehicleID-1][EngineOn] = 0;
					SaveVehData( vehicleID-1, "EngineOn" );
					gVehData[vehicleID-1][CarFuel] = float(VehFTank(vehicleID));
					SaveVehData( vehicleID-1, "CarFuel" );
					DisablePlayerCheckpoint(i);
					gSweeperDriverJustStarted[i] = 0;
					gSweeperDriverOnDuty[i] = 0;
				}
				SavePlayerData(i, "SweeperJobPoints");
				SavePlayerData(i, "Cash");
			}
		}
		if(gFarmerDriverOnDuty[i] == 1)
		{
			vehicleID = GetPlayerVehicleID(i);
			if(gPlayerData[i][pFarmerJobPoints] == FARMER_LVL)
			{
				if(gPlayerData[i][pFarmerJobLvl] >= MAX_FARMER_LVL)
				{
					gPlayerData[i][pFarmerJobLvl] = MAX_FARMER_LVL;
					gPlayerData[i][pFarmerJobPoints] = FARMER_LVL;

					SavePlayerData(i, "FarmerJobLvl");
					SavePlayerData(i, "FarmerJobPoints");

					SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pFarmerJobPoints]));
					UpdateProgressBar(JobProgress[i], i);
				}
				else
				{
					gPlayerData[i][pFarmerJobLvl]++;
					gPlayerData[i][pExp]++;
					gPlayerData[i][pFarmerJobPoints] = 0;

					SavePlayerData(i, "FarmerJobLvl");
					SavePlayerData(i, "FarmerJobPoints");
					SavePlayerData(i, "Exp");

					SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pFarmerJobPoints]));
					UpdateProgressBar(JobProgress[i], i);
					format(string, sizeof(string), "[INFO:] Osi¹gn¹³eœ %d poziom jako Farmer !", gPlayerData[i][pFarmerJobLvl]);
					SendClientMessage(i, COLOR_LIGHTYELLOW2, string);
					if(gPlayerData[i][pExp] >= (gPlayerData[i][pLevel]+1)*levelexp)
					{
						gPlayerData[i][pLevel]++;
						gPlayerData[i][pExp] = 0;

						SavePlayerData(i, "Level");
						SavePlayerData(i, "Exp");

						format(string, sizeof(string), "[INFO:] Zdoby³eœ tak¿e nowy poziom postaci ! - %d", gPlayerData[i][pLevel]);
						SendClientMessage(i, COLOR_LIGHTYELLOW2, string);
					}
					else
					{
						SendClientMessage(i, COLOR_LIGHTYELLOW2, "[INFO:] Otrzymujesz tak¿e 1pkt do doœwiadczenia !");
					}
				}
			}
			GetVehicleHealth(vehicleID, vehicleHealth);
			if(vehicleHealth <= 900.0 && gVehHealthOnPlayerEnter[i] > 900.0 && gFarmerDriverPenaltyInformed[i] == 0 && IsPlayerInAnyVehicle(i) && gVehData[vehicleID-1][CarType] == 11)
			{
				gPlayerData[i][pCost] += 5000;
				gFarmerDriverPenaltyInformed[i] = 1;
				gPlayerData[i][pFarmerJobPoints] -= 2;

				SavePlayerData(i, "Cost");
				SavePlayerData(i, "FarmerJobPoints");

				SendClientMessage(i, COLOR_LIGHTYELLOW2, "[INFO:] Zosta³eœ ukarany grzywn¹ w wysokoœci 5 000$ za nieostro¿n¹ jazde");
				SendClientMessage(i, COLOR_LIGHTYELLOW2, "[INFO:] Kara zostanie automatycznie pobrana przy nastêpnej wyp³acie.");
				SendClientMessage(i, COLOR_LIGHTYELLOW2, "[INFO:] Tracisz tak¿e 2pkt pracy.");
			}
			if(gFarmerDriverSelectedLine[i] == 0)
			{
				if(gFarmerDriverJustStarted[i] == 0)
				{
					gFarmerDriverPaymentCount[i] = 0;
					gFarmerDriverJustStarted[i] = 1;
					gFarmerDriverCurrentCheckPoint[i] = 1;
					SetPlayerCheckpoint(i, FarmerJob[CheckPoint1ax], FarmerJob[CheckPoint1ay], FarmerJob[CheckPoint1az], 5.0);
				}
				else if(gFarmerDriverCurrentCheckPoint[i] == 1 && IsPlayerInRangeOfPoint(i, 10.0, FarmerJob[CheckPoint1ax], FarmerJob[CheckPoint1ay], FarmerJob[CheckPoint1az]))
				{
					gPlayerData[i][pFarmerJobPoints]++;
					SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pFarmerJobPoints]));
					UpdateProgressBar(JobProgress[i], i);
					gJobProfit[i] += floatpower(gPlayerData[i][pFarmerJobLvl],gFarmerDriverPaymentMultiplier);

					gFarmerDriverCurrentCheckPoint[i] = 2;
					SetPlayerCheckpoint(i, FarmerJob[CheckPoint2ax], FarmerJob[CheckPoint2ay], FarmerJob[CheckPoint2az], 5.0);
				}
				else if(gFarmerDriverCurrentCheckPoint[i] == 2 && IsPlayerInRangeOfPoint(i, 10.0, FarmerJob[CheckPoint2ax], FarmerJob[CheckPoint2ay], FarmerJob[CheckPoint2az]))
				{
						gPlayerData[i][pFarmerJobPoints]++;
						gJobProfit[i] += floatpower(gPlayerData[i][pFarmerJobLvl],gFarmerDriverPaymentMultiplier);

						gFarmerDriverCurrentCheckPoint[i] = 3;
						SetPlayerCheckpoint(i, FarmerJob[CheckPoint3ax], FarmerJob[CheckPoint3ay], FarmerJob[CheckPoint3az], 5.0);
				}
				else if(gFarmerDriverCurrentCheckPoint[i] == 3 && IsPlayerInRangeOfPoint(i, 10.0, FarmerJob[CheckPoint3ax], FarmerJob[CheckPoint3ay], FarmerJob[CheckPoint3az]))
				{
					gPlayerData[i][pFarmerJobPoints]++;
					SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pFarmerJobPoints]));
					UpdateProgressBar(JobProgress[i], i);
					gJobProfit[i] += floatpower(gPlayerData[i][pFarmerJobLvl],gFarmerDriverPaymentMultiplier);

					gFarmerDriverCurrentCheckPoint[i] = 4;
					SetPlayerCheckpoint(i, FarmerJob[CheckPoint4ax], FarmerJob[CheckPoint4ay], FarmerJob[CheckPoint4az], 5.0);
				}
				else if(gFarmerDriverCurrentCheckPoint[i] == 4 && IsPlayerInRangeOfPoint(i, 10.0, FarmerJob[CheckPoint4ax], FarmerJob[CheckPoint4ay], FarmerJob[CheckPoint4az]))
				{
					gPlayerData[i][pFarmerJobPoints]++;
					SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pFarmerJobPoints]));
					UpdateProgressBar(JobProgress[i], i);
					gJobProfit[i] += floatpower(gPlayerData[i][pFarmerJobLvl],gFarmerDriverPaymentMultiplier);

					gFarmerDriverCheckpointTime[i] = 30;
					gFarmerDriverCurrentCheckPoint[i] = 5;
					SetPlayerCheckpoint(i, FarmerJob[CheckPoint0bx], FarmerJob[CheckPoint0by], FarmerJob[CheckPoint0bz], 5.0);
				}
				else if(gFarmerDriverCurrentCheckPoint[i] == 5 && gFarmerDriverCheckpointTime[i] <= 30 && IsPlayerInRangeOfPoint(i, 10.0, FarmerJob[CheckPoint0bx], FarmerJob[CheckPoint0by], FarmerJob[CheckPoint0bz]))
				{
					gFarmerDriverCheckpointTime[i]--;
					if(gFarmerDriverCheckpointTime[i] == 29)
					{
						SendClientMessage(i, COLOR_LIGHTYELLOW2, "[INFO:] Czekaj 30 sek. Trwa rozladowywanie zboza");
					}
					else if(gFarmerDriverCheckpointTime[i] <= 3)
					{
						format(string, sizeof(string), "[INFO:] Odjazd za: %d sek.", gFarmerDriverCheckpointTime[i]);
						SendClientMessage(i, COLOR_LIGHTYELLOW2, string);
					}
					if(gFarmerDriverCheckpointTime[i] == 0)
					{
						gPlayerData[i][pFarmerJobPoints]++;
						SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pFarmerJobPoints]));
						UpdateProgressBar(JobProgress[i], i);
						gJobProfit[i] += floatpower(gPlayerData[i][pFarmerJobLvl],gFarmerDriverPaymentMultiplier);

						gFarmerDriverCurrentCheckPoint[i] = 6;
						SetPlayerCheckpoint(i, FarmerJob[CheckPoint1bx], FarmerJob[CheckPoint1by], FarmerJob[CheckPoint1bz], 5.0);
					}
				}
				else if(gFarmerDriverCurrentCheckPoint[i] == 6 && IsPlayerInRangeOfPoint(i, 10.0, FarmerJob[CheckPoint1bx], FarmerJob[CheckPoint1by], FarmerJob[CheckPoint1bz]))
				{
					gPlayerData[i][pFarmerJobPoints]++;
					SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pFarmerJobPoints]));
					UpdateProgressBar(JobProgress[i], i);
					gJobProfit[i] += floatpower(gPlayerData[i][pFarmerJobLvl],gFarmerDriverPaymentMultiplier);

					gFarmerDriverCurrentCheckPoint[i] = 7;
					SetPlayerCheckpoint(i, FarmerJob[CheckPoint2bx], FarmerJob[CheckPoint2by], FarmerJob[CheckPoint2bz], 5.0);
				}
				else if(gFarmerDriverCurrentCheckPoint[i] == 7 && IsPlayerInRangeOfPoint(i, 10.0, FarmerJob[CheckPoint2bx], FarmerJob[CheckPoint2by], FarmerJob[CheckPoint2bz]))
				{
					gPlayerData[i][pFarmerJobPoints]++;
					SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pFarmerJobPoints]));
					UpdateProgressBar(JobProgress[i], i);
					gJobProfit[i] += floatpower(gPlayerData[i][pFarmerJobLvl],gFarmerDriverPaymentMultiplier);

					gFarmerDriverCurrentCheckPoint[i] = 8;
					SetPlayerCheckpoint(i, FarmerJob[CheckPoint3bx], FarmerJob[CheckPoint3by], FarmerJob[CheckPoint3bz], 5.0);
				}
				else if(gFarmerDriverCurrentCheckPoint[i] == 8 && IsPlayerInRangeOfPoint(i, 10.0, FarmerJob[CheckPoint3bx], FarmerJob[CheckPoint3by], FarmerJob[CheckPoint3bz]))
				{
					gPlayerData[i][pFarmerJobPoints]++;
					SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pFarmerJobPoints]));
					UpdateProgressBar(JobProgress[i], i);
					gJobProfit[i] += floatpower(gPlayerData[i][pFarmerJobLvl],gFarmerDriverPaymentMultiplier);

					gFarmerDriverCurrentCheckPoint[i] = 9;
					SetPlayerCheckpoint(i, FarmerJob[CheckPoint4bx], FarmerJob[CheckPoint4by], FarmerJob[CheckPoint4bz], 5.0);
				}
				else if(gFarmerDriverCurrentCheckPoint[i] == 9 && IsPlayerInRangeOfPoint(i, 10.0, FarmerJob[CheckPoint4bx], FarmerJob[CheckPoint4by], FarmerJob[CheckPoint4bz]))
				{
					gPlayerData[i][pFarmerJobPoints]++;
					SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pFarmerJobPoints]));
					UpdateProgressBar(JobProgress[i], i);
					gJobProfit[i] += floatpower(gPlayerData[i][pFarmerJobLvl],gFarmerDriverPaymentMultiplier);

					gFarmerDriverCheckpointTime[i] = 30;
					gFarmerDriverCurrentCheckPoint[i] = 10;
					SetPlayerCheckpoint(i, FarmerJob[CheckPoint0bx], FarmerJob[CheckPoint0by], FarmerJob[CheckPoint0bz], 5.0);
				}
				else if(gFarmerDriverCurrentCheckPoint[i] == 10 && gFarmerDriverCheckpointTime[i] <= 30 && IsPlayerInRangeOfPoint(i, 10.0, FarmerJob[CheckPoint0bx], FarmerJob[CheckPoint0by], FarmerJob[CheckPoint0bz]))
				{
					gFarmerDriverCheckpointTime[i]--;
					if(gFarmerDriverCheckpointTime[i] == 29)
					{
						SendClientMessage(i, COLOR_LIGHTYELLOW2, "[INFO:] Czekaj 30 sek. Trwa rozladowywanie zboza");
					}
					else if(gFarmerDriverCheckpointTime[i] <= 3)
					{
						format(string, sizeof(string), "[INFO:] Odjazd za: %d sek.", gFarmerDriverCheckpointTime[i]);
						SendClientMessage(i, COLOR_LIGHTYELLOW2, string);
					}
					if(gFarmerDriverCheckpointTime[i] == 0)
					{
						gPlayerData[i][pFarmerJobPoints]++;
						SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pFarmerJobPoints]));
						UpdateProgressBar(JobProgress[i], i);
						gJobProfit[i] += floatpower(gPlayerData[i][pFarmerJobLvl],gFarmerDriverPaymentMultiplier);

						gFarmerDriverCurrentCheckPoint[i] = 11;
						SetPlayerCheckpoint(i, FarmerJob[CheckPoint5bx], FarmerJob[CheckPoint5by], FarmerJob[CheckPoint5bz], 5.0);
					}
				}
				else if(gFarmerDriverCurrentCheckPoint[i] ==11 && IsPlayerInRangeOfPoint(i, 10.0, FarmerJob[CheckPoint5bx], FarmerJob[CheckPoint5by], FarmerJob[CheckPoint5bz]))
				{
					gPlayerData[i][pFarmerJobPoints]++;
					SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pFarmerJobPoints]));
					UpdateProgressBar(JobProgress[i], i);
					gJobProfit[i] += floatpower(gPlayerData[i][pFarmerJobLvl],gFarmerDriverPaymentMultiplier);

					gFarmerDriverCurrentCheckPoint[i] = 12;
					SetPlayerCheckpoint(i, FarmerJob[CheckPoint6bx], FarmerJob[CheckPoint6by], FarmerJob[CheckPoint6bz], 5.0);

				}
				else if(gFarmerDriverCurrentCheckPoint[i] == 12 && IsPlayerInRangeOfPoint(i, 10.0, FarmerJob[CheckPoint6bx], FarmerJob[CheckPoint6by], FarmerJob[CheckPoint6bz]))
				{
					gPlayerData[i][pFarmerJobPoints]++;
					SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pFarmerJobPoints]));
					UpdateProgressBar(JobProgress[i], i);
					gJobProfit[i] += floatpower(gPlayerData[i][pFarmerJobLvl],gFarmerDriverPaymentMultiplier);

					gFarmerDriverCurrentCheckPoint[i] = 13;
					SetPlayerCheckpoint(i, FarmerJob[CheckPoint7bx], FarmerJob[CheckPoint7by], FarmerJob[CheckPoint7bz], 5.0);
				}
				else if(gFarmerDriverCurrentCheckPoint[i] == 13 && IsPlayerInRangeOfPoint(i, 10.0, FarmerJob[CheckPoint7bx], FarmerJob[CheckPoint7by], FarmerJob[CheckPoint7bz]))
				{
					gPlayerData[i][pFarmerJobPoints]++;
					SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pFarmerJobPoints]));
					UpdateProgressBar(JobProgress[i], i);
					gJobProfit[i] += floatpower(gPlayerData[i][pFarmerJobLvl],gFarmerDriverPaymentMultiplier);

					gFarmerDriverCurrentCheckPoint[i] = 14;
					SetPlayerCheckpoint(i, FarmerJob[CheckPoint8bx], FarmerJob[CheckPoint8by], FarmerJob[CheckPoint8bz], 5.0);
				}
				else if(gFarmerDriverCurrentCheckPoint[i] == 14 && IsPlayerInRangeOfPoint(i, 10.0, FarmerJob[CheckPoint9bx], FarmerJob[CheckPoint8by], FarmerJob[CheckPoint8bz]))
				{
					gPlayerData[i][pFarmerJobPoints]++;
					SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pFarmerJobPoints]));
					UpdateProgressBar(JobProgress[i], i);
					gJobProfit[i] += floatpower(gPlayerData[i][pFarmerJobLvl],gFarmerDriverPaymentMultiplier);

					gFarmerDriverCheckpointTime[i] = 30;
					gFarmerDriverCurrentCheckPoint[i] = 15;
					SetPlayerCheckpoint(i, FarmerJob[CheckPoint0bx], FarmerJob[CheckPoint0by], FarmerJob[CheckPoint0bz], 5.0);
				}
				else if(gFarmerDriverCurrentCheckPoint[i] == 15 && IsPlayerInRangeOfPoint(i, 10.0, FarmerJob[CheckPoint0bx], FarmerJob[CheckPoint0by], FarmerJob[CheckPoint0bz]))
				{
					gFarmerDriverCheckpointTime[i]--;
					if(gFarmerDriverCheckpointTime[i] == 29)
					{
						SendClientMessage(i, COLOR_LIGHTYELLOW2, "[INFO:] Czekaj 30 sek. Trwa rozladowywanie zboza");
					}
					else if(gFarmerDriverCheckpointTime[i] <= 3)
					{
						format(string, sizeof(string), "[INFO:] Odjazd za: %d sek.", gFarmerDriverCheckpointTime[i]);
						SendClientMessage(i, COLOR_LIGHTYELLOW2, string);
					}
					if(gFarmerDriverCheckpointTime[i] == 0)
					{
						gPlayerData[i][pFarmerJobPoints]++;
						SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pFarmerJobPoints]));
						UpdateProgressBar(JobProgress[i], i);
						gJobProfit[i] += floatpower(gPlayerData[i][pFarmerJobLvl],gFarmerDriverPaymentMultiplier);

						gFarmerDriverCurrentCheckPoint[i] = 16;
						SetPlayerCheckpoint(i, FarmerJob[CheckPoint9bx], FarmerJob[CheckPoint9by], FarmerJob[CheckPoint9bz], 5.0);
					}
				}
				else if(gFarmerDriverCurrentCheckPoint[i] == 16 && IsPlayerInRangeOfPoint(i, 10.0, FarmerJob[CheckPoint9bx], FarmerJob[CheckPoint9by], FarmerJob[CheckPoint9bz]))
				{
						gPlayerData[i][pFarmerJobPoints]++;
						SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pFarmerJobPoints]));
						UpdateProgressBar(JobProgress[i], i);
						gJobProfit[i] += floatpower(gPlayerData[i][pFarmerJobLvl],gFarmerDriverPaymentMultiplier);

						gFarmerDriverCurrentCheckPoint[i] = 17;
						SetPlayerCheckpoint(i, FarmerJob[CheckPoint10bx], FarmerJob[CheckPoint10by], FarmerJob[CheckPoint10bz], 5.0);
				}
				else if(gFarmerDriverCurrentCheckPoint[i] == 17 && IsPlayerInRangeOfPoint(i, 10.0, FarmerJob[CheckPoint10bx], FarmerJob[CheckPoint10by], FarmerJob[CheckPoint10bz]))
				{
						gPlayerData[i][pFarmerJobPoints]++;
						SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pFarmerJobPoints]));
						UpdateProgressBar(JobProgress[i], i);
						gJobProfit[i] += floatpower(gPlayerData[i][pFarmerJobLvl],gFarmerDriverPaymentMultiplier);

						gFarmerDriverCurrentCheckPoint[i] = 18;
						SetPlayerCheckpoint(i, FarmerJob[CheckPoint11bx], FarmerJob[CheckPoint11by], FarmerJob[CheckPoint11bz], 5.0);
				}
				else if(gFarmerDriverCurrentCheckPoint[i] == 18 && IsPlayerInRangeOfPoint(i, 10.0, FarmerJob[CheckPoint11bx], FarmerJob[CheckPoint11by], FarmerJob[CheckPoint11bz]))
				{
						gPlayerData[i][pFarmerJobPoints]++;
						SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pFarmerJobPoints]));
						UpdateProgressBar(JobProgress[i], i);
						gJobProfit[i] += floatpower(gPlayerData[i][pFarmerJobLvl],gFarmerDriverPaymentMultiplier);

						gFarmerDriverCurrentCheckPoint[i] = 19;
						SetPlayerCheckpoint(i, FarmerJob[CheckPoint12bx], FarmerJob[CheckPoint12by], FarmerJob[CheckPoint12bz], 5.0);
				}
				else if(gFarmerDriverCurrentCheckPoint[i] == 19 && IsPlayerInRangeOfPoint(i, 10.0, FarmerJob[CheckPoint12bx], FarmerJob[CheckPoint12by], FarmerJob[CheckPoint12bz]))
				{
						gFarmerDriverCheckpointTime[i] = 30;
						gPlayerData[i][pFarmerJobPoints]++;
						SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pFarmerJobPoints]));
						UpdateProgressBar(JobProgress[i], i);
						gJobProfit[i] += floatpower(gPlayerData[i][pFarmerJobLvl],gFarmerDriverPaymentMultiplier);

						gFarmerDriverCheckpointTime[i] = 30;
						gFarmerDriverCurrentCheckPoint[i] = 20;
						SetPlayerCheckpoint(i, FarmerJob[CheckPoint0bx], FarmerJob[CheckPoint0by], FarmerJob[CheckPoint0bz], 5.0);
				}
				else if(gFarmerDriverCurrentCheckPoint[i] == 20 && gFarmerDriverCheckpointTime[i] <= 30 && IsPlayerInRangeOfPoint(i, 10.0, FarmerJob[CheckPoint0bx], FarmerJob[CheckPoint0by], FarmerJob[CheckPoint0bz]))
				{
					gFarmerDriverCheckpointTime[i]--;
					if(gFarmerDriverCheckpointTime[i] == 29)
					{
						SendClientMessage(i, COLOR_LIGHTYELLOW2, "[INFO:] Czekaj 30 sek. Trwa rozladowywanie zboza");
					}
					else if(gFarmerDriverCheckpointTime[i] <= 3)
					{
						format(string, sizeof(string), "[INFO:] Odjazd za: %d sek.", gFarmerDriverCheckpointTime[i]);
						SendClientMessage(i, COLOR_LIGHTYELLOW2, string);
					}
					if(gFarmerDriverCheckpointTime[i] == 0)
					{
						gPlayerData[i][pFarmerJobPoints]++;
						SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pFarmerJobPoints]));
						UpdateProgressBar(JobProgress[i], i);
						gJobProfit[i] += floatpower(gPlayerData[i][pFarmerJobLvl],gFarmerDriverPaymentMultiplier);

						gFarmerDriverCurrentCheckPoint[i] = 21;
						SetPlayerCheckpoint(i, FarmerJob[CheckPoint13cx], FarmerJob[CheckPoint13cy], FarmerJob[CheckPoint13cz], 5.0);
					}
				}
				else if(gFarmerDriverCurrentCheckPoint[i] == 21 && IsPlayerInRangeOfPoint(i, 10.0, FarmerJob[CheckPoint13cx], FarmerJob[CheckPoint13cy], FarmerJob[CheckPoint13cz]))
				{
						gPlayerData[i][pFarmerJobPoints]++;
						SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pFarmerJobPoints]));
						UpdateProgressBar(JobProgress[i], i);
						gJobProfit[i] += floatpower(gPlayerData[i][pFarmerJobLvl],gFarmerDriverPaymentMultiplier);

						gFarmerDriverCurrentCheckPoint[i] = 22;
						SetPlayerCheckpoint(i, FarmerJob[CheckPoint14cx], FarmerJob[CheckPoint14cy], FarmerJob[CheckPoint14cz], 5.0);
				}
				else if(gFarmerDriverCurrentCheckPoint[i] == 22 && IsPlayerInRangeOfPoint(i, 10.0, FarmerJob[CheckPoint14cx], FarmerJob[CheckPoint14cy], FarmerJob[CheckPoint14cz]))
				{
						gPlayerData[i][pFarmerJobPoints]++;
						SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pFarmerJobPoints]));
						UpdateProgressBar(JobProgress[i], i);
						gJobProfit[i] += floatpower(gPlayerData[i][pFarmerJobLvl],gFarmerDriverPaymentMultiplier);

						gFarmerDriverCurrentCheckPoint[i] = 23;
						SetPlayerCheckpoint(i, FarmerJob[CheckPoint15cx], FarmerJob[CheckPoint15cy], FarmerJob[CheckPoint15cz], 5.0);
				}
				else if(gFarmerDriverCurrentCheckPoint[i] == 23 && IsPlayerInRangeOfPoint(i, 10.0, FarmerJob[CheckPoint15cx], FarmerJob[CheckPoint15cy], FarmerJob[CheckPoint15cz]))
				{
						gPlayerData[i][pFarmerJobPoints]++;
						SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pFarmerJobPoints]));
						UpdateProgressBar(JobProgress[i], i);
						gJobProfit[i] += floatpower(gPlayerData[i][pFarmerJobLvl],gFarmerDriverPaymentMultiplier);

						gFarmerDriverCurrentCheckPoint[i] = 24;
						SetPlayerCheckpoint(i, FarmerJob[CheckPoint16cx], FarmerJob[CheckPoint16cy], FarmerJob[CheckPoint16cz], 5.0);
				}
				else if(gFarmerDriverCurrentCheckPoint[i] == 24 && IsPlayerInRangeOfPoint(i, 10.0, FarmerJob[CheckPoint16cx], FarmerJob[CheckPoint16cy], FarmerJob[CheckPoint16cz]))
				{
						gPlayerData[i][pFarmerJobPoints]++;
						SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pFarmerJobPoints]));
						UpdateProgressBar(JobProgress[i], i);
						gJobProfit[i] += floatpower(gPlayerData[i][pFarmerJobLvl],gFarmerDriverPaymentMultiplier);

						gFarmerDriverCurrentCheckPoint[i] = 25;
						SetPlayerCheckpoint(i, FarmerJob[CheckPoint17cx], FarmerJob[CheckPoint17cy], FarmerJob[CheckPoint17cz], 5.0);
				}
				else if(gFarmerDriverCurrentCheckPoint[i] == 25 && IsPlayerInRangeOfPoint(i, 10.0, FarmerJob[CheckPoint17cx], FarmerJob[CheckPoint17cy], FarmerJob[CheckPoint17cz]))
				{
						gPlayerData[i][pFarmerJobPoints]++;
						SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pFarmerJobPoints]));
						UpdateProgressBar(JobProgress[i], i);
						gJobProfit[i] += floatpower(gPlayerData[i][pFarmerJobLvl],gFarmerDriverPaymentMultiplier);

						gFarmerDriverCheckpointTime[i] = 30;
						gFarmerDriverCurrentCheckPoint[i] = 0;
						SetPlayerCheckpoint(i, FarmerJob[CheckPoint0ax], FarmerJob[CheckPoint0ay], FarmerJob[CheckPoint0az], 5.0);

				}
				else if(gFarmerDriverCurrentCheckPoint[i] == 0 && gFarmerDriverCheckpointTime[i] <= 30 && IsPlayerInRangeOfPoint(i, 10.0, FarmerJob[CheckPoint0ax], FarmerJob[CheckPoint0ay], FarmerJob[CheckPoint0az]))
				{
					gFarmerDriverCheckpointTime[i]--;
					if(gFarmerDriverCheckpointTime[i] == 29)
					{
						SendClientMessage(i, COLOR_LIGHTYELLOW2, "[INFO:] Czekaj 30 sekund. Trwa roz³adowywanie zbo¿a");
					}
					else if(gFarmerDriverCheckpointTime[i] <= 3)
					{
						format(string, sizeof(string), "[INFO:] Odjazd za: %d sek.", gFarmerDriverCheckpointTime[i]);
						SendClientMessage(i, COLOR_LIGHTYELLOW2, string);
					}
					if(gFarmerDriverCheckpointTime[i] == 0)
					{
						gFarmerDriverCheckpointTime[i]--;
						format(string, sizeof(string), "[INFO:] Zarobi³eœ za zebrania zboza %d$", floatround(gJobProfit[i], floatround_round));
						GivePlayerCash(i, floatround(gJobProfit[i], floatround_round));
						DynamicFactions[FACTIONID_GOVERNMENT][fBank] -= gJobProfit[i];
						SaveFData(FACTIONID_GOVERNMENT, "Bank");
						SendClientMessage(i, COLOR_LIGHTYELLOW2, string);
						RemovePlayerFromVehicle(i);
						HideProgressBarForPlayer(i, JobProgress[i]);
						SetVehicleToRespawn(vehicleID);
						GetVehicleParamsEx(vehicleID, enginedyn, lights, alarm, doors, bonnet, boot, objective);
						SetVehicleParamsEx(vehicleID,0,lights,alarm,doors,bonnet,boot,objective);
						gVehData[vehicleID-1][EngineOn] = 0;
						SaveVehData( vehicleID-1, "EngineOn" );
						gVehData[vehicleID-1][CarFuel] = float(VehFTank(vehicleID));
						SaveVehData( vehicleID-1, "CarFuel" );
						DisablePlayerCheckpoint(i);
						gFarmerDriverJustStarted[i] = 0;
						gFarmerDriverOnDuty[i] = 0;
					}
				}
				SavePlayerData(i, "Cost");
				SavePlayerData(i, "FarmerJobPoints");
				SavePlayerData(i, "Exp");
			}
			else if(gFarmerDriverSelectedLine[i] == 1)
			{
				if(gFarmerDriverJustStarted[i] == 0)
				{
					gFarmerDriverPaymentCount[i] = 0;
					gFarmerDriverJustStarted[i] = 1;
					gFarmerDriverCurrentCheckPoint[i] = 1;
					SetPlayerCheckpoint(i, FarmerJob[CheckPoint1bx], FarmerJob[CheckPoint1by], FarmerJob[CheckPoint1bz], 5.0);
				}
				else if(gFarmerDriverCurrentCheckPoint[i] == 1 && gFarmerDriverCheckpointTime[i] <= 10 && IsPlayerInRangeOfPoint(i, 10.0, FarmerJob[CheckPoint1bx], FarmerJob[CheckPoint1by], FarmerJob[CheckPoint1bz]))
				{
						gPlayerData[i][pFarmerJobPoints]++;
						SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pFarmerJobPoints]));
						UpdateProgressBar(JobProgress[i], i);
						gJobProfit[i] += floatpower(gPlayerData[i][pFarmerJobLvl],gFarmerDriverPaymentMultiplier);

						gFarmerDriverCurrentCheckPoint[i] = 2;
						SetPlayerCheckpoint(i, FarmerJob[CheckPoint2bx], FarmerJob[CheckPoint2by], FarmerJob[CheckPoint2bz], 5.0);
				}
				else if(gFarmerDriverCurrentCheckPoint[i] == 2 && gFarmerDriverCheckpointTime[i] <= 10 && IsPlayerInRangeOfPoint(i, 10.0, FarmerJob[CheckPoint2bx], FarmerJob[CheckPoint2by], FarmerJob[CheckPoint2bz]))
				{
						gPlayerData[i][pFarmerJobPoints]++;
						SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pFarmerJobPoints]));
						UpdateProgressBar(JobProgress[i], i);
						gJobProfit[i] += floatpower(gPlayerData[i][pFarmerJobLvl],gFarmerDriverPaymentMultiplier);

						gFarmerDriverCurrentCheckPoint[i] = 3;
						SetPlayerCheckpoint(i, FarmerJob[CheckPoint3bx], FarmerJob[CheckPoint3by], FarmerJob[CheckPoint3bz], 5.0);
				}
				else if(gFarmerDriverCurrentCheckPoint[i] == 3 && gFarmerDriverCheckpointTime[i] <= 10 && IsPlayerInRangeOfPoint(i, 10.0, FarmerJob[CheckPoint3bx], FarmerJob[CheckPoint3by], FarmerJob[CheckPoint3bz]))
				{
						gPlayerData[i][pFarmerJobPoints]++;
						SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pFarmerJobPoints]));
						UpdateProgressBar(JobProgress[i], i);
						gJobProfit[i] += floatpower(gPlayerData[i][pFarmerJobLvl],gFarmerDriverPaymentMultiplier);

						gFarmerDriverCurrentCheckPoint[i] = 4;
						SetPlayerCheckpoint(i, FarmerJob[CheckPoint4bx], FarmerJob[CheckPoint4by], FarmerJob[CheckPoint4bz], 5.0);
				}
				else if(gFarmerDriverCurrentCheckPoint[i] == 4 && IsPlayerInRangeOfPoint(i, 10.0, FarmerJob[CheckPoint4bx], FarmerJob[CheckPoint4by], FarmerJob[CheckPoint4bz]))
				{
						gPlayerData[i][pFarmerJobPoints]++;
						SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pFarmerJobPoints]));
						UpdateProgressBar(JobProgress[i], i);
						gJobProfit[i] += floatpower(gPlayerData[i][pFarmerJobLvl],gFarmerDriverPaymentMultiplier);

						gFarmerDriverCheckpointTime[i] = 30;
						gFarmerDriverCurrentCheckPoint[i] = 5;
						SetPlayerCheckpoint(i, FarmerJob[CheckPoint0bx], FarmerJob[CheckPoint0by], FarmerJob[CheckPoint0bz], 5.0);

				}
				else if(gFarmerDriverCurrentCheckPoint[i] == 5 && gFarmerDriverCheckpointTime[i] <= 30 && IsPlayerInRangeOfPoint(i, 10.0, FarmerJob[CheckPoint0bx], FarmerJob[CheckPoint0by], FarmerJob[CheckPoint0bz]))
				{
					gFarmerDriverCheckpointTime[i]--;
					if(gFarmerDriverCheckpointTime[i] == 29)
					{
						SendClientMessage(i, COLOR_LIGHTYELLOW2, "[INFO:] Czekaj 30 sek. Trwa rozladowywanie zboza");
					}
					else if(gFarmerDriverCheckpointTime[i] <= 3)
					{
						format(string, sizeof(string), "[INFO:] Odjazd za: %d sek.", gFarmerDriverCheckpointTime[i]);
						SendClientMessage(i, COLOR_LIGHTYELLOW2, string);
					}
					if(gFarmerDriverCheckpointTime[i] == 0)
					{
						gPlayerData[i][pFarmerJobPoints]++;
						SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pFarmerJobPoints]));
						UpdateProgressBar(JobProgress[i], i);
						gJobProfit[i] += floatpower(gPlayerData[i][pFarmerJobLvl],gFarmerDriverPaymentMultiplier);

						gFarmerDriverCurrentCheckPoint[i] = 6;
						SetPlayerCheckpoint(i, FarmerJob[CheckPoint5bx], FarmerJob[CheckPoint5by], FarmerJob[CheckPoint5bz], 5.0);
					}
				}
				else if(gFarmerDriverCurrentCheckPoint[i] == 6 && IsPlayerInRangeOfPoint(i, 10.0, FarmerJob[CheckPoint5bx], FarmerJob[CheckPoint5by], FarmerJob[CheckPoint5bz]))
				{
						gPlayerData[i][pFarmerJobPoints]++;
						SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pFarmerJobPoints]));
						UpdateProgressBar(JobProgress[i], i);
						gJobProfit[i] += floatpower(gPlayerData[i][pFarmerJobLvl],gFarmerDriverPaymentMultiplier);

						gFarmerDriverCurrentCheckPoint[i] = 7;
						SetPlayerCheckpoint(i, FarmerJob[CheckPoint6bx], FarmerJob[CheckPoint6by], FarmerJob[CheckPoint6bz], 5.0);

				}
				else if(gFarmerDriverCurrentCheckPoint[i] == 7 && IsPlayerInRangeOfPoint(i, 10.0, FarmerJob[CheckPoint6bx], FarmerJob[CheckPoint6by], FarmerJob[CheckPoint6bz]))
				{

						gPlayerData[i][pFarmerJobPoints]++;
						SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pFarmerJobPoints]));
						UpdateProgressBar(JobProgress[i], i);
						gJobProfit[i] += floatpower(gPlayerData[i][pFarmerJobLvl],gFarmerDriverPaymentMultiplier);

						gFarmerDriverCurrentCheckPoint[i] = 8;
						SetPlayerCheckpoint(i, FarmerJob[CheckPoint7bx], FarmerJob[CheckPoint7by], FarmerJob[CheckPoint7bz], 5.0);

				}
				else if(gFarmerDriverCurrentCheckPoint[i] == 8 && IsPlayerInRangeOfPoint(i, 10.0, FarmerJob[CheckPoint7bx], FarmerJob[CheckPoint7by], FarmerJob[CheckPoint7bz]))
				{
						gPlayerData[i][pFarmerJobPoints]++;
						SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pFarmerJobPoints]));
						UpdateProgressBar(JobProgress[i], i);
						gJobProfit[i] += floatpower(gPlayerData[i][pFarmerJobLvl],gFarmerDriverPaymentMultiplier);

						gFarmerDriverCurrentCheckPoint[i] = 9;
						SetPlayerCheckpoint(i, FarmerJob[CheckPoint8bx], FarmerJob[CheckPoint8by], FarmerJob[CheckPoint8bz], 5.0);
				}
				else if(gFarmerDriverCurrentCheckPoint[i] == 9 && IsPlayerInRangeOfPoint(i, 10.0, FarmerJob[CheckPoint9bx], FarmerJob[CheckPoint8by], FarmerJob[CheckPoint8bz]))
				{
						gPlayerData[i][pFarmerJobPoints]++;
						SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pFarmerJobPoints]));
						UpdateProgressBar(JobProgress[i], i);
						gJobProfit[i] += floatpower(gPlayerData[i][pFarmerJobLvl],gFarmerDriverPaymentMultiplier);

						gFarmerDriverCheckpointTime[i] = 30;
						gFarmerDriverCurrentCheckPoint[i] = 10;
						SetPlayerCheckpoint(i, FarmerJob[CheckPoint0bx], FarmerJob[CheckPoint0by], FarmerJob[CheckPoint0bz], 5.0);
				}
				else if(gFarmerDriverCurrentCheckPoint[i] == 10 && IsPlayerInRangeOfPoint(i, 10.0, FarmerJob[CheckPoint0bx], FarmerJob[CheckPoint0by], FarmerJob[CheckPoint0bz]))
				{
					gFarmerDriverCheckpointTime[i]--;
					if(gFarmerDriverCheckpointTime[i] == 29)
					{
						SendClientMessage(i, COLOR_LIGHTYELLOW2, "[INFO:] Czekaj 30 sek. Trwa rozladowywanie zboza");
					}
					else if(gFarmerDriverCheckpointTime[i] <= 3)
					{
						format(string, sizeof(string), "[INFO:] Odjazd za: %d sek.", gFarmerDriverCheckpointTime[i]);
						SendClientMessage(i, COLOR_LIGHTYELLOW2, string);
					}
					if(gFarmerDriverCheckpointTime[i] == 0)
					{
						gPlayerData[i][pFarmerJobPoints]++;
						SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pFarmerJobPoints]));
						UpdateProgressBar(JobProgress[i], i);
						gJobProfit[i] += floatpower(gPlayerData[i][pFarmerJobLvl],gFarmerDriverPaymentMultiplier);

						gFarmerDriverCurrentCheckPoint[i] = 11;
						SetPlayerCheckpoint(i, FarmerJob[CheckPoint9bx], FarmerJob[CheckPoint9by], FarmerJob[CheckPoint9bz], 5.0);
					}
				}
				else if(gFarmerDriverCurrentCheckPoint[i] == 11 && IsPlayerInRangeOfPoint(i, 10.0, FarmerJob[CheckPoint9bx], FarmerJob[CheckPoint9by], FarmerJob[CheckPoint9bz]))
				{
						gPlayerData[i][pFarmerJobPoints]++;
						SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pFarmerJobPoints]));
						UpdateProgressBar(JobProgress[i], i);
						gJobProfit[i] += floatpower(gPlayerData[i][pFarmerJobLvl],gFarmerDriverPaymentMultiplier);

						gFarmerDriverCurrentCheckPoint[i] = 12;
						SetPlayerCheckpoint(i, FarmerJob[CheckPoint10bx], FarmerJob[CheckPoint10by], FarmerJob[CheckPoint10bz], 5.0);
				}
				else if(gFarmerDriverCurrentCheckPoint[i] == 12 && IsPlayerInRangeOfPoint(i, 10.0, FarmerJob[CheckPoint10bx], FarmerJob[CheckPoint10by], FarmerJob[CheckPoint10bz]))
				{
						gPlayerData[i][pFarmerJobPoints]++;
						SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pFarmerJobPoints]));
						UpdateProgressBar(JobProgress[i], i);
						gJobProfit[i] += floatpower(gPlayerData[i][pFarmerJobLvl],gFarmerDriverPaymentMultiplier);

						gFarmerDriverCurrentCheckPoint[i] = 13;
						SetPlayerCheckpoint(i, FarmerJob[CheckPoint11bx], FarmerJob[CheckPoint11by], FarmerJob[CheckPoint11bz], 5.0);
				}
				else if(gFarmerDriverCurrentCheckPoint[i] == 13 && IsPlayerInRangeOfPoint(i, 10.0, FarmerJob[CheckPoint11bx], FarmerJob[CheckPoint11by], FarmerJob[CheckPoint11bz]))
				{
						gPlayerData[i][pFarmerJobPoints]++;
						SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pFarmerJobPoints]));
						UpdateProgressBar(JobProgress[i], i);
						gJobProfit[i] += floatpower(gPlayerData[i][pFarmerJobLvl],gFarmerDriverPaymentMultiplier);

						gFarmerDriverCurrentCheckPoint[i] = 14;
						SetPlayerCheckpoint(i, FarmerJob[CheckPoint12bx], FarmerJob[CheckPoint12by], FarmerJob[CheckPoint12bz], 5.0);
				}
				else if(gFarmerDriverCurrentCheckPoint[i] == 14 && IsPlayerInRangeOfPoint(i, 10.0, FarmerJob[CheckPoint12bx], FarmerJob[CheckPoint12by], FarmerJob[CheckPoint12bz]))
				{
						gFarmerDriverCheckpointTime[i] = 30;
						gPlayerData[i][pFarmerJobPoints]++;
						SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pFarmerJobPoints]));
						UpdateProgressBar(JobProgress[i], i);
						gJobProfit[i] += floatpower(gPlayerData[i][pFarmerJobLvl],gFarmerDriverPaymentMultiplier);

						gFarmerDriverCheckpointTime[i] = 30;
						gFarmerDriverCurrentCheckPoint[i] = 15;
						SetPlayerCheckpoint(i, FarmerJob[CheckPoint0bx], FarmerJob[CheckPoint0by], FarmerJob[CheckPoint0bz], 5.0);

				}
				else if(gFarmerDriverCurrentCheckPoint[i] == 15 && gFarmerDriverCheckpointTime[i] <= 30 && IsPlayerInRangeOfPoint(i, 10.0, FarmerJob[CheckPoint0bx], FarmerJob[CheckPoint0by], FarmerJob[CheckPoint0bz]))
				{
					gFarmerDriverCheckpointTime[i]--;
					if(gFarmerDriverCheckpointTime[i] == 29)
					{
						SendClientMessage(i, COLOR_LIGHTYELLOW2, "[INFO:] Czekaj 30 sek. Trwa rozladowywanie zboza");
					}
					else if(gFarmerDriverCheckpointTime[i] <= 3)
					{
						format(string, sizeof(string), "[INFO:] Odjazd za: %d sek.", gFarmerDriverCheckpointTime[i]);
						SendClientMessage(i, COLOR_LIGHTYELLOW2, string);
					}
					if(gFarmerDriverCheckpointTime[i] == 0)
					{
						gPlayerData[i][pFarmerJobPoints]++;
						SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pFarmerJobPoints]));
						UpdateProgressBar(JobProgress[i], i);
						gJobProfit[i] += floatpower(gPlayerData[i][pFarmerJobLvl],gFarmerDriverPaymentMultiplier);

						gFarmerDriverCurrentCheckPoint[i] = 16;
						SetPlayerCheckpoint(i, FarmerJob[CheckPoint13cx], FarmerJob[CheckPoint13cy], FarmerJob[CheckPoint13cz], 5.0);
					}
				}
				else if(gFarmerDriverCurrentCheckPoint[i] == 16 && IsPlayerInRangeOfPoint(i, 10.0, FarmerJob[CheckPoint13cx], FarmerJob[CheckPoint13cy], FarmerJob[CheckPoint13cz]))
				{
						gPlayerData[i][pFarmerJobPoints]++;
						SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pFarmerJobPoints]));
						UpdateProgressBar(JobProgress[i], i);
						gJobProfit[i] += floatpower(gPlayerData[i][pFarmerJobLvl],gFarmerDriverPaymentMultiplier);

						gFarmerDriverCurrentCheckPoint[i] = 17;
						SetPlayerCheckpoint(i, FarmerJob[CheckPoint14cx], FarmerJob[CheckPoint14cy], FarmerJob[CheckPoint14cz], 5.0);
				}
				else if(gFarmerDriverCurrentCheckPoint[i] == 17 && IsPlayerInRangeOfPoint(i, 10.0, FarmerJob[CheckPoint14cx], FarmerJob[CheckPoint14cy], FarmerJob[CheckPoint14cz]))
				{
						gPlayerData[i][pFarmerJobPoints]++;
						SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pFarmerJobPoints]));
						UpdateProgressBar(JobProgress[i], i);
						gJobProfit[i] += floatpower(gPlayerData[i][pFarmerJobLvl],gFarmerDriverPaymentMultiplier);

						gFarmerDriverCurrentCheckPoint[i] = 18;
						SetPlayerCheckpoint(i, FarmerJob[CheckPoint15cx], FarmerJob[CheckPoint15cy], FarmerJob[CheckPoint15cz], 5.0);
				}
				else if(gFarmerDriverCurrentCheckPoint[i] == 18 && IsPlayerInRangeOfPoint(i, 10.0, FarmerJob[CheckPoint15cx], FarmerJob[CheckPoint15cy], FarmerJob[CheckPoint15cz]))
				{
						gPlayerData[i][pFarmerJobPoints]++;
						SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pFarmerJobPoints]));
						UpdateProgressBar(JobProgress[i], i);
						gJobProfit[i] += floatpower(gPlayerData[i][pFarmerJobLvl],gFarmerDriverPaymentMultiplier);

						gFarmerDriverCurrentCheckPoint[i] = 19;
						SetPlayerCheckpoint(i, FarmerJob[CheckPoint16cx], FarmerJob[CheckPoint16cy], FarmerJob[CheckPoint16cz], 5.0);
				}
				else if(gFarmerDriverCurrentCheckPoint[i] == 19 && IsPlayerInRangeOfPoint(i, 10.0, FarmerJob[CheckPoint16cx], FarmerJob[CheckPoint16cy], FarmerJob[CheckPoint16cz]))
				{
						gPlayerData[i][pFarmerJobPoints]++;
						SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pFarmerJobPoints]));
						UpdateProgressBar(JobProgress[i], i);
						gJobProfit[i] += floatpower(gPlayerData[i][pFarmerJobLvl],gFarmerDriverPaymentMultiplier);

						gFarmerDriverCurrentCheckPoint[i] = 20;
						SetPlayerCheckpoint(i, FarmerJob[CheckPoint17cx], FarmerJob[CheckPoint17cy], FarmerJob[CheckPoint17cz], 5.0);
				}
				else if(gFarmerDriverCurrentCheckPoint[i] == 20 && IsPlayerInRangeOfPoint(i, 10.0, FarmerJob[CheckPoint17cx], FarmerJob[CheckPoint17cy], FarmerJob[CheckPoint17cz]))
				{
						gPlayerData[i][pFarmerJobPoints]++;
						SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pFarmerJobPoints]));
						UpdateProgressBar(JobProgress[i], i);
						gJobProfit[i] += floatpower(gPlayerData[i][pFarmerJobLvl],gFarmerDriverPaymentMultiplier);

						gFarmerDriverCheckpointTime[i] = 30;
						gFarmerDriverCurrentCheckPoint[i] = 0;
						SetPlayerCheckpoint(i, FarmerJob[CheckPoint0bx], FarmerJob[CheckPoint0by], FarmerJob[CheckPoint0bz], 5.0);

				}
				else if(gFarmerDriverCurrentCheckPoint[i] == 0 && gFarmerDriverCheckpointTime[i] <= 30 && IsPlayerInRangeOfPoint(i, 10.0, FarmerJob[CheckPoint0bx], FarmerJob[CheckPoint0by], FarmerJob[CheckPoint0bz]))
				{
					gFarmerDriverCheckpointTime[i]--;
					if(gFarmerDriverCheckpointTime[i] == 29)
					{
						SendClientMessage(i, COLOR_LIGHTYELLOW2, "[INFO:] Czekaj 30 sekund. Trwa roz³adowywanie zbo¿a");
					}
					else if(gFarmerDriverCheckpointTime[i] <= 3)
					{
						format(string, sizeof(string), "[INFO:] Odjazd za: %d sek.", gFarmerDriverCheckpointTime[i]);
						SendClientMessage(i, COLOR_LIGHTYELLOW2, string);
					}
					if(gFarmerDriverCheckpointTime[i] == 0)
					{
						format(string, sizeof(string), "[INFO:] Zarobi³eœ za zebrania zbo¿a %d$", floatround(gJobProfit[i], floatround_round));
						GivePlayerCash(i, floatround(gJobProfit[i], floatround_round));
						DynamicFactions[FACTIONID_GOVERNMENT][fBank] -= gJobProfit[i];
						SaveFData(FACTIONID_GOVERNMENT, "Bank");
						SendClientMessage(i, COLOR_LIGHTYELLOW2, string);
						RemovePlayerFromVehicle(i);
						HideProgressBarForPlayer(i, JobProgress[i]);
						SetVehicleToRespawn(vehicleID);
						GetVehicleParamsEx(vehicleID, enginedyn, lights, alarm, doors, bonnet, boot, objective);
						SetVehicleParamsEx(vehicleID,0,lights,alarm,doors,bonnet,boot,objective);
						gVehData[vehicleID-1][EngineOn] = 0;
						SaveVehData( vehicleID-1, "EngineOn" );
						gVehData[vehicleID-1][CarFuel] = float(VehFTank(vehicleID));
						SaveVehData( vehicleID-1, "CarFuel" );
						DisablePlayerCheckpoint(i);
						gFarmerDriverJustStarted[i] = 0;
						gFarmerDriverOnDuty[i] = 0;
					}
				}
				SavePlayerData(i, "Cost");
				SavePlayerData(i, "FarmerJobPoints");
			}
		}
	}
	
	//printf("MS na koncu timera: %d", tickcount(ticks));
	return 1;
}

Timer:OneMinTimer[60000]()
{
	/*
	* Vehicle data update - actually only battery and some engine stuff
	*/
	new enginedyn, lights, alarm, doors, bonnet, boot, objective, Float:vehiclehp;
	for( new i = 0; i < sizeof(gVehData); i++ )
	{
		GetVehicleParamsEx(i+1,enginedyn,lights,alarm,doors,bonnet,boot,objective);
		if( gVehData[i][EngineOn] )
		{
			if( gVehData[i][BatteryCapacity] < gVehData[i][BatteryMaxCapacity] )
			{
				gVehData[i][BatteryCapacity] += 1.0;
				SaveVehData(i, "BatteryCapacity");
			}
			if( gVehData[i][EngineTemp] < 5 )
				gVehData[i][EngineTemp]++;
			GetVehicleHealth(i+1,vehiclehp);
			if( vehiclehp < 600.0 && gVehData[i][EngineTemp] == 5 )
			{
				SetVehicleParamsEx(i+1,0,lights,alarm,doors,bonnet,boot,objective);
				gVehData[i][EngineOn] = 0;
				SaveVehData(i, "EngineOn");
			}
		}
		else
		{
			if( gVehData[i][EngineTemp] > 0 )
				gVehData[i][EngineTemp]--;
			if( gVehData[i][CarType] == 0 )
			{
				if( gVehData[i][LightsOn] )
					gVehData[i][BatteryCapacity] -= 0.6;
				if( gVehData[i][RadioOn] )
					gVehData[i][BatteryCapacity] -= 0.15;
				if( gVehData[i][BatteryCapacity] <= 0.0 )
				{
					gVehData[i][BatteryCapacity] = 0.0;
					if( gVehData[i][LightsOn] )
					{
						gVehData[i][LightsOn] = 0;
						SetVehicleParamsEx(i+1,gVehData[i][EngineOn],gVehData[i][LightsOn],0,gVehData[i][Closed],gVehData[i][BonnetUp],gVehData[i][BootUp],objective);
						SaveVehData(i, "LightsOn");
					}
				}
			}
			SaveVehData(i, "BatteryCapacity");
		}
	}
	
	/*
	* Gang war status
	*/
	if(gGangWar[Enabled] == 1)
	{
		if( gGangWar[TimeLeft] == 0 )
		{
			foreach(Player, i )
			{
				if( gPlayerData[i][pFaction] != 255 )
				{
					if( DynamicFactions[ gPlayerData[i][pFaction] ][fType] == 3 )
					{
						TextDrawSetString( GangWar[i], " " );
						GangZoneStopFlashForPlayer( i, gGangWar[AreaID] );
					}
				}
			}
			gGangWar[Enabled] = 0;
			new string[128];
			if( gGangWar[FactionStartedKills] > gGangWar[FactionAttackedKills] )
			{
				DynamicZones[ gGangWar[AreaID] ][zFaction] = gGangWar[FactionStarted];
				GangZoneDestroy( gGangWar[AreaID] );
				gangZoneIDtmp = GangZoneCreate( DynamicZones[ gGangWar[AreaID] ][zMin_X]*1.0 , DynamicZones[ gGangWar[AreaID] ][zMin_Y]*1.0, DynamicZones[ gGangWar[AreaID] ][zMax_X]*1.0, DynamicZones[ gGangWar[AreaID] ][zMax_Y]*1.0);
				foreach(Player, i )
				{
					if( gPlayerData[i][pFaction] < sizeof(DynamicFactions) )
					{
						if( DynamicFactions[ gPlayerData[i][pFaction] ][fType] == 3 )
							GangZoneShowForPlayer(i, gangZoneIDtmp, HexToInt( DynamicFactions[ gGangWar[FactionStarted] ][fColor]));
					}
				}
				SendFactionTypeMessage(3, COLOR_LIGHTYELLOW2, "TERYTORIUM ZOSTA£O PRZEJÊTE");
				SaveDynamicZones();
			}
			else if( gGangWar[FactionStartedKills] <= gGangWar[FactionAttackedKills] )
			{
				foreach(Player, i )
				{
					if( gPlayerData[i][pFaction] < sizeof(DynamicFactions) )
					{
						if( DynamicFactions[ gPlayerData[i][pFaction] ][fType] == 3 )
							GangZoneShowForPlayer(i, gangZoneIDtmp, HexToInt( DynamicFactions[ gGangWar[FactionAttacked] ][fColor]));
					}
				}
				format(string, sizeof(string), "[INFO:] Terytorium zostaje pod kontrol¹ %s", DynamicFactions[ DynamicZones[ gGangWar[AreaID] ][zFaction] ][Name]);
				SendFactionTypeMessage(3, COLOR_LIGHTYELLOW2, string);
			}
		}
		else if( gGangWar[TimeLeft] > 0 )
			gGangWar[TimeLeft]--;
		new isAnyDefenderInArea;
		new isPlayerInAreab;
		foreach(Player, i)
		{
			/*
			* CHECK IF DEFENDER IS ON ATTACKED TERRITORY
			*/
			if( gPlayerData[i][pFaction] < sizeof(DynamicFactions) )
			{
				if( DynamicFactions[ gPlayerData[i][pFaction] ][fType] == 3 )
				{
					if( IsPlayerInArea( i, DynamicZones[ gGangWar[AreaID] ][zMax_X]*1.0, DynamicZones[ gGangWar[AreaID] ][zMin_X]*1.0, DynamicZones[ gGangWar[AreaID] ][zMax_Y]*1.0, DynamicZones[ gGangWar[AreaID] ][zMin_Y]*1.0 ) )
					{
						if( gGangWar[FactionAttacked] == gPlayerData[i][pFaction] && gPlayerData[i][pCharacterDying] == 0 )
							isAnyDefenderInArea = 1;
						else if( gGangWar[FactionStarted] == gPlayerData[i][pFaction] && gPlayerData[i][pCharacterDying] == 0 )
							isPlayerInAreab = 1;
					}
				}
			}
		}
		if( isAnyDefenderInArea == 0 && isPlayerInAreab == 1)
			gGangWar[TimeAlone]++;
		else
			gGangWar[TimeAlone] = 0;
		/*
		* TERRITORY TAKEN - PLAYER ALONE IN FIELD
		*/
		if( gGangWar[TimeAlone] >= 10 )
		{
			gGangWar[Enabled] = 0;
			DynamicZones[ gGangWar[AreaID] ][zFaction] = gGangWar[FactionStarted];
			GangZoneDestroy( gGangWar[AreaID] );
			gangZoneIDtmp = GangZoneCreate( DynamicZones[ gGangWar[AreaID] ][zMin_X]*1.0 , DynamicZones[ gGangWar[AreaID] ][zMin_Y]*1.0, DynamicZones[ gGangWar[AreaID] ][zMax_X]*1.0, DynamicZones[ gGangWar[AreaID] ][zMax_Y]*1.0);
			foreach(Player, i )
			{
				if( gPlayerData[i][pFaction] < sizeof(DynamicFactions) )
				{
					if( DynamicFactions[ gPlayerData[i][pFaction] ][fType] == 3 )
					{
						TextDrawSetString( GangWar[i], " " );
						GangZoneStopFlashForPlayer( i, gGangWar[AreaID] );
						GangZoneShowForPlayer(i, gangZoneIDtmp, HexToInt( DynamicFactions[ gGangWar[FactionStarted] ][fColor]));
					}
				}
			}
			SendFactionTypeMessage(3, COLOR_LIGHTYELLOW2, "TERYTORIUM ZOSTA£O PRZEJÊTE");
			SaveDynamicZones();
		}
	}
	
	/*
	* Player stuff
	*/
	foreach(Player, i )
	{
		if( !gPlayerLogged[i] )
			continue;
		SetPlayerScore(i, gPlayerData[i][pLevel]);
		if(Mobile[i] != 255)
		{
			if(Mobile[Mobile[i]] != 255)
				gCallCost[i] += PHONE_COST;
		}
		if(VipAFKActive[i] == 0 && AdminDuty[i] == 0 && GetPlayerState(i) != PLAYER_STATE_SPECTATING && gPlayerData[i][pTutorial] && Spawned[i])
		{		
			/*
			* This part checks eating needs
			*/	
			if( gPlayerData[i][pJailed] == 0 && gPlayerData[i][pCharacterDying] == 0)
			{
				if( gPlayerData[i][pHunger] > 0 )
				gPlayerData[i][pHunger] -= 3.2;
				if( gPlayerData[i][pHunger] < 0 )
					gPlayerData[i][pHunger] = 0;
				SavePlayerData( i, "Hunger" );
				SetProgressBarValue( gPlayerData[i][pHungerProgressBarID], gPlayerData[i][pHunger] );
				UpdateProgressBar( gPlayerData[i][pHungerProgressBarID], i );
				if( gPlayerData[i][pHunger] == 0.0 )
				{
					SendClientMessage(i, COLOR_LIGHTYELLOW2, "[INFO:] Robisz siê bardzo g³odny !");
					GetPlayerHealth(i, gPlayerData[i][pHP]);
					gPlayerData[i][pHP] -= 4.0;
					if( gPlayerData[i][pHP] < 0.0 )
						gPlayerData[i][pHP] = 0.0;
					SetPlayerHealth(i, gPlayerData[i][pHP] );
					SavePlayerData(i, "HP");
					if(LifeDecreaserTmpHP <= 30.0)
						SetPlayerDrunkLevel(i, 50000);
				}
			}

			/*
			* This part checks drug addict
			*/
			if(LastDrug[i] == 0 && gPlayerData[i][pJailed] == 0 && gPlayerData[i][pDrugsAddicted] == 1)
			{
				GetPlayerHealth(i,LifeDecreaserTmpHP);
				if(LifeDecreaserTmpHP <= 35.0)
				{
					SetPlayerDrunkLevel(i, 50000);
					SendClientMessage(i, COLOR_LIGHTYELLOW2, "[INFO:] Jesteœ na g³odzie narkotykowym. Strzel sobie strza³a !");
				}
				else
				{
					LifeDecreaserTmpHP -= 5.0;
					SendClientMessage(i, COLOR_LIGHTYELLOW2, "[INFO:] Czujesz g³ód narkotykowy. Strzel sobie strza³a !");
					SetPlayerHealth(i,LifeDecreaserTmpHP);
					gPlayerData[i][pHP] = LifeDecreaserTmpHP;
					SavePlayerData(i, "HP");
				}
			}
			if(LastDrug[i] > 0)
				LastDrug[i]--;
		}
	}
	return 1;
}

Timer:FiveMinTimer[300000]()
{
	foreach(Player, i )
	{
		if( !gPlayerLogged[i] )
			continue;
		// sprzedawca
		if(gPlayerData[i][pJob] == 19)
		{
			for(new k = 0; k < sizeof(Businesses); k++)
			{
				if(GetPlayerVirtualWorld(i) == k)
				{
					if(PlayerToPoint(20.0, i,Businesses[k][ExitX],Businesses[k][ExitY],Businesses[k][ExitZ]))
					{
						if(Businesses[k][Till] > 0 && Businesses[k][Products] > 0 && gPlayerData[i][pSellerJobOn])
						{
							GivePlayerCash(i,12);
							Businesses[k][Till] -= 12;
							SaveBizData(k, "Till");
						}
					}
				}
			}
		}
	}
}

Timer:TenMinTimer[600000]()
{
	new Float: vehHealth;
	new Float: x, Float: y, Float: z, Float: a;	
	new string[128];
	
	/*
	* Check pickup exist time, remove if its old
	*/
	for(new i = 0; i < sizeof(gPickupItem); i++)
	{
		if(gPickupItem[i][pickupLifeTime] > 0)
			gPickupItem[i][pickupLifeTime]--;
		if(gPickupItem[i][pickupLifeTime] == 0)
		{
			DestroyDynamicPickup(gPickupItem[i][pickupID]);
			gPickupItem[i][pickupID] = -1;
		}
	}
	
	CurrentInformationTmp = random(16);
	while(CurrentInformation  == CurrentInformationTmp)
	{
		CurrentInformationTmp = random(16);
	}
	CurrentInformation = CurrentInformationTmp;
	switch(CurrentInformation)
	{
		case 0:
		{
			SendClientMessageToAll(COLOR_LIGHTORANGE, "[TIPS:] Numery publiczne: 999 - Pogotowie, 997 - Policja, 411 - HALO Taxi, 555 - Warsztat Samochodowy");
		}
		case 1:
		{
			SendClientMessageToAll(COLOR_LIGHTORANGE, "[TIPS:] Nie wiesz o co chodzi ? Masz propozycje zmian ? WejdŸ na forum - www.wpartyrp.pl");
		}
		case 2:
		{
			SendClientMessageToAll(COLOR_LIGHTORANGE, "[TIPS:] Potrzebujesz pieniêdzy ? Zatrudnij sie do pracy wybieraj¹c z poœród wielu ofert !");
			SendClientMessageToAll(COLOR_LIGHTORANGE, "[TIPS:] Czêœæ prac znajduje siê pod urzêdem, reszta rozmieszczona jest po ca³ym mieœcie.");
			SendClientMessageToAll(COLOR_LIGHTORANGE, "[TIPS:] Wiêcej informacji - www.wpartyrp.pl");
		}
		case 3:
		{
			SendClientMessageToAll(COLOR_LIGHTORANGE, "[TIPS:] Widzisz cheatera lub gracza ³ami¹cego zasady gry ? Skorzystaj z komendy /donos");
			SendClientMessageToAll(COLOR_LIGHTORANGE, "[TIPS:] lub napisz na GG/AQQ");
		}
		case 4:
		{
		}
		case 5:
		{
		}
		case 6:
		{
			SendClientMessageToAll(COLOR_LIGHTORANGE, "[TIPS:] Zosta³o Ci ma³o ¿ycia ? Udaj siê do jednej z kilkudzisiêciu knajp/restauracji");
			SendClientMessageToAll(COLOR_LIGHTORANGE, "[TIPS:] i u¿yj komendy /jedz ew. idŸ do baru i napij sie - /kupdrink");
		}
		case 7:
		{
			SendClientMessageToAll(COLOR_LIGHTORANGE, "[TIPS:] Zadaj nam pytanie na GG lub AQQ !");
			SendClientMessageToAll(COLOR_LIGHTORANGE, "[TIPS:] GG: 20677329, AQQ: wparty@aqq.eu");
		}
		case 8:
		{
			SendClientMessageToAll(COLOR_LIGHTORANGE, "[TIPS:] Gdy jesteœ w pojeŸdzie skorzystaj z komendy /radios !");
			SendClientMessageToAll(COLOR_LIGHTORANGE, "[TIPS:] Do wyboru masz kilka ró¿nych stacji (np. Radio ZET). ");
		}
		case 9:
		{
			SendClientMessageToAll(COLOR_LIGHTORANGE, "[TIPS:] Czeste uzywanie /ja /do dodaje do gry urozmaicenie rozgrywki na Wparty !");
			SendClientMessageToAll(COLOR_LIGHTORANGE, "[TIPS:] Gra z dnia na dzien moze nas zadziwic uzywiajac akcji RP");
		}
		case 10:
		{
			SendClientMessageToAll( COLOR_LIGHTORANGE,"[TIPS:] Stosujac mottto serwera : Zatrzymaj sie !!! : pomysl przed nastepna akcja czy jest ona Non RP czy RP");
			SendClientMessageToAll( COLOR_LIGHTORANGE,"[TIPS:] W ten sposob uzyskasz 100 procent z frajdy z gry oraz zaufanie obecnych graczy");
		}
		case 11:
		{
			SendClientMessageToAll( COLOR_LIGHTORANGE,"[TIPS:] Jeœli jesteœ pracownikiem s³u¿b publicznych zalecane jest posiadanie GPSu.");
			SendClientMessageToAll( COLOR_LIGHTORANGE,"[TIPS:] Dziêki niemu du¿o ³atwiej odnajdziesz ludzi w potrzebie.");
		}
		case 12:
		{
			SendClientMessageToAll( COLOR_LIGHTORANGE,"[TIPS:] Posiadanie GPSu oraz telefonu ulatwi Ci gre oraz sluzbom publicznym.");
			SendClientMessageToAll( COLOR_LIGHTORANGE,"[TIPS:] GPS kupisz w kazdym 24/7 a Telefon w dowolnej sieci komorkowej.");
		}
		case 13:
		{
			SendClientMessageToAll( COLOR_LIGHTORANGE,"[TIPS:] Jeœli posiadasz ju¿ pojazd mo¿esz go ubezpieczyæ.");
			SendClientMessageToAll( COLOR_LIGHTORANGE,"[TIPS:] Umowe o ubezpieczenie OC/AC mo¿esz otrzymaæ od urzêdnika.");
		}
		case 14:
		{
			SendClientMessageToAll( COLOR_LIGHTORANGE,"[TIPS:] Chcesz siê pozbyæ pojazdu ? Udaj siê na z³omowisko i wpisz /zezlomuj pojazd.");
			SendClientMessageToAll( COLOR_LIGHTORANGE,"[TIPS:] Pobrana zostanie odgórnie ustalona stawka za z³omowanie. Wiêcej informacji na forum.");
		}
		case 15:
		{
			SendClientMessageToAll( COLOR_LIGHTORANGE,"[TIPS:] Chcesz wyró¿niaæ siê poœród inny ? Udaj siê na do sklepu z ubraniami");
			SendClientMessageToAll( COLOR_LIGHTORANGE,"[TIPS:] i wybierz jeden z modeli czapek czy te¿ okularów");
		}
		case 16:
		{
			SendClientMessageToAll( COLOR_LIGHTORANGE,"[TIPS:] Do³¹cz do grupy WParty SA:MP na facebooku ju¿ dziœ !");
			SendClientMessageToAll( COLOR_LIGHTORANGE,"[TIPS:] B¹dŸ na bie¿¹co z wydarzeniami na serwerze i komentuj je");
		}
	}
	
	// RepairVehicles and SaveCarsLocations
	for(new i = 0; i < sizeof(gVehData); i++)
	{
		if(!ReadyToSave)
		{
			ReadyToSave = 1;
			break;
		}
		GetVehiclePos(i+1, x, y, z);
		GetVehicleZAngle(i+1, a);
		GetVehicleHealth(i+1, vehHealth);

		gVehData[i][CarX] = x;
		gVehData[i][CarY] = y;
		gVehData[i][CarZ] = z;
		gVehData[i][CarAngle] = a;
		gVehData[i][CarHealth] = vehHealth;

		SaveVehData(i, "CarPos");
		SaveVehData(i, "CarHealth");
		SaveVehData(i, "CarFuel");
			
		if(gVehData[i][CarRepairTimeLeft] > 0)
		{
			gVehData[i][CarRepairTimeLeft]--;
			if(gVehData[i][CarRepairTimeLeft] == 1)
			{
				gVehData[i][CarRepairTimeLeft] = 0;
				gVehData[i][CarDamaged] = 0;
				RepairVehicle(i+1);

				gVehData[i][CarPanels] = 0;
				gVehData[i][CarDoors] = 0;
				gVehData[i][CarLights] = 0;
				gVehData[i][CarTires] = 0;
				gVehData[i][CarHealth] = 1000.0;

				GetVehiclePos(i+1, gVehData[i][CarX], gVehData[i][CarY], gVehData[i][CarZ]);
				GetVehicleZAngle(i+1, gVehData[i][CarAngle]);

				SaveVehData(i, "CarPos");

				// NOTE: do we realy need to do this ?
				// DestroyVehicle(i+1);
				// CreateVehicle(gVehData[i][CarModel],gVehData[i][CarX],gVehData[i][CarY],gVehData[i][CarZ],gVehData[i][CarAngle],gVehData[i][CarColor1],gVehData[i][CarColor2],-1);
				// SetVehicleToRespawn(i+1);

				// new enginedyn,lights,alarm,doors,bonnet,boot,objective;
				// GetVehicleParamsEx(i+1,enginedyn,lights,alarm,doors,bonnet,boot,objective);
				// SetVehicleParamsEx(i+1,gVehData[i][EngineOn],gVehData[i][LightsOn],alarm,0,gVehData[i][BonnetUp],gVehData[i][BootUp],objective);

				SaveVehData(i, "CarPanels");
				SaveVehData(i, "CarDoors");
				SaveVehData(i, "CarLights");
				SaveVehData(i, "CarTires");
				SaveVehData(i, "CarDamaged");
				SaveVehData(i, "CarHealth");
			}
			SaveVehData(i, "CarRepairTimeLeft");
		}
	}

	new wstring[128];
	new nxtlevel;
	new expamount;
	foreach(Player, i )
	{
		if(gPlayerLogged[i])
		{
			/*
			* Reduce last submeal
			*/
			if( gPlayerData[i][pSubMealEaten] > 0 )
			{
				gPlayerData[i][pSubMealEaten]--;
				SavePlayerData( i, "SubMealEaten" );
			}
			
			/*
			* Player position save
			*/
			if(GetPlayerState(i) != 9 && GetPlayerState(i) != 7 && GetPlayerState(i) != 0)
			{
				GetPlayerPos(i,x,y,z);
				gPlayerData[i][pCrashX] = x;
				gPlayerData[i][pCrashY] = y;
				gPlayerData[i][pCrashZ] = z;
				gPlayerData[i][pCrashInt] = GetPlayerInterior(i);
				gPlayerData[i][pCrashW] = GetPlayerVirtualWorld(i);

				SavePlayerData(i, "Crash");

				if(x == 0.0 || y == 0.0)
				{
					printf("[WARNING:] OneMinTimer() x = %d, y =  %d", x, y);
				}
			}
			// EXP
			if(gPlayerData[i][pJailed] == 0)
			{
				if( gPlayerData[i][pDuty] )
				{
					gPlayerData[i][pHoursOnDutyHelper]++;
					if(gPlayerData[i][pHoursOnDutyHelper] >= 6)
					{
						gPlayerData[i][pHoursOnDutyHelper] = 0;
						gPlayerData[i][pHoursOnDuty]++;
						SavePlayerData(i, "HoursOnDuty");
					}
					SavePlayerData(i, "HoursOnDutyHelper");
				}
				gPlayerData[i][pHourAssist]++;
				if(gPlayerData[i][pHourAssist] >= 6)
				{
					gPlayerData[i][pHourAssist] = 0;
					nxtlevel = gPlayerData[i][pLevel]+1;
					expamount = nxtlevel * levelexp;
					gPlayerData[i][pPlayingHours]++;
					if(gPlayerData[i][pVipExp] == 1 || gPlayerData[i][pVipExpT] > 0)
						gPlayerData[i][pExp] += 2;
					if(gPlayerData[i][pVipExp] == 0 && gPlayerData[i][pVipExpT] == 0)
						gPlayerData[i][pExp]++;
					if(gPlayerData[i][pJobTimeChange] > 0)
						gPlayerData[i][pJobTimeChange]--;
					if(gPlayerData[i][pPlayingHours] == 100)
					{
						gPlayerData[i][pExp]++;
						SendClientMessage(i,COLOR_LIGHTYELLOW2, "[INFO:] Otrzymujesz dodatkowy punkt doœwiadczenia za sta¿ w grze !");
					}
					if(gPlayerData[i][pPlayingHours] == 500)
					{
						gPlayerData[i][pExp]++;
						SendClientMessage(i,COLOR_LIGHTYELLOW2, "[INFO:] Otrzymujesz dodatkowy punkt doœwiadczenia za sta¿ w grze !");
					}
					if(gPlayerData[i][pPlayingHours] == 1000)
					{
						gPlayerData[i][pExp]++;
						SendClientMessage(i,COLOR_LIGHTYELLOW2, "[INFO:] Otrzymujesz dodatkowy punkt doœwiadczenia za sta¿ w grze !");
					}
					if(gPlayerData[i][pPlayingHours] == 2000)
					{
						gPlayerData[i][pExp]++;
						SendClientMessage(i,COLOR_LIGHTYELLOW2, "[INFO:] Otrzymujesz dodatkowy punkt doœwiadczenia za sta¿ w grze !");
					}
					if(gPlayerData[i][pExp] < expamount)
					{
						format(wstring, sizeof(wstring), "Twój poziom doœwiadczenia: %d/%d.", gPlayerData[i][pExp], expamount);
						SendClientMessage(i,COLOR_LIGHTYELLOW2, wstring);
					}
					else
					{
						format(wstring, sizeof(wstring), "Nowy poziom! - %d.", nxtlevel);
						SendClientMessage(i,COLOR_LIGHTYELLOW2, wstring);
						gPlayerData[i][pLevel]++;
						nxtlevel = gPlayerData[i][pLevel]+1;
						expamount = nxtlevel * levelexp;
						format(wstring, sizeof(wstring), "Do kolejnego potrzebujesz %d doœwiadczenia.", expamount);
						SendClientMessage(i,COLOR_LIGHTYELLOW2, wstring);
						gPlayerData[i][pExp] = 0;
					}
					SavePlayerData(i, "Exp");
					SavePlayerData(i, "JobTimeChange");
					SavePlayerData(i, "Level");
					SavePlayerData(i, "PlayingHours");
				}
				SavePlayerData(i, "HourAssist");
				SavePlayerData(i, "HoursOnDutyHelper");
			}
		}
	}

	SaveDynamicCarSpawns();
	SaveDynamicPlanesSpawns();
	SaveDynamicBoatsSpawns();
	SaveGasStations();
	SaveRafinery();
	
	format(string, sizeof(string), "SELECT * FROM samp_factions");
	mysql_query(string, RELOAD_DYNAMIC_FACTIONS, INVALID_PLAYER_ID, db_con2);

	format(string, sizeof(string), "SELECT * FROM samp_factions_weapons");
	mysql_query(string, LOAD_DYNAMIC_FACTIONS_WEAPONS, INVALID_PLAYER_ID, db_con2);

	format(string, sizeof(string), "SELECT * FROM samp_factions_weapons2");
	mysql_query(string, LOAD_DYNAMIC_FACTIONS_WEAPONS2, INVALID_PLAYER_ID, db_con2);

	format(string, sizeof(string), "SELECT * FROM `samp_factions_payrank` ");
	mysql_query(string, LOAD_FACTIONS_PAYRANK, INVALID_PLAYER_ID, db_con2);
	
	return 1;
} // end of TenMinTimer

Timer:OneHourTimer[3600000]()
{
	//print("[TIMERCHECK:] OneHourTimer()");
	// GangTerritoryEarn
	for(new i = 0; i < sizeof(DynamicZones); i++)
	{
		if(DynamicZones[i][zFaction] != 255)
			DynamicFactions[DynamicZones[i][zFaction]][fBank] += 2;
	}

	new Hour, Minute, Second;
	gettime(Hour, Minute, Second);

	if(Hour == 4)
		PayDay();
	if(Hour == 21)
	{
		if( gLuckyLotteryLastLottery <= 2 )
		{
			gLuckyLotteryLastLottery++;
			SaveLotteryData(-1);
		}
		else
		{
			gLuckyLotteryID++;
			new numbers[4];
			numbers[0] = random(50);
			numbers[1] = random(50);
			while( numbers[1] == numbers[0] )
				numbers[1] = random(50);
			numbers[2] = random(50);
			while( numbers[2] == numbers[0] || numbers[2] == numbers[1] )
				numbers[2] = random(50);
			numbers[3] = random(50);
			while( numbers[3] == numbers[0] || numbers[3] == numbers[1] || numbers[3] == numbers[2] )
				numbers[3] = random(50);
			gLuckyLotteryWinnersCount = 0;
			gLuckyLotteryNumbers[0] = numbers[0];
			gLuckyLotteryNumbers[1] = numbers[1];
			gLuckyLotteryNumbers[2] = numbers[2];
			gLuckyLotteryNumbers[3] = numbers[3];
			for( new i = 0; i < sizeof(gLuckyLottery); i++ )
			{
				if( gLuckyLotteryNumbers[0] == gLuckyLottery[i][LuckyNumbers][0] && gLuckyLotteryNumbers[1] == gLuckyLottery[i][LuckyNumbers][1] &&
					gLuckyLotteryNumbers[2] == gLuckyLottery[i][LuckyNumbers][2] && gLuckyLotteryNumbers[3] == gLuckyLottery[i][LuckyNumbers][3] && gLuckyLotteryID == gLuckyLottery[i][LuckyID] )
				{
					gLuckyLotteryWinnersCount++;
				}
			}
			SaveLotteryData(-1);
		}
	}

	return 1;
}
