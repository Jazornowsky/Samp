/***
*
* File: wp_timers_default.inc
* Auth: Damian Wojdat
* Date: 26.11.2011
* Desc: Default timers.
* TODO: Transfer other default timers here.
*
*************************************************************************************************************/

task TimeTime[250]()
{
	static string[256];
	gSec++;
	if(gSec == 60)
	{
		gSec = 0;
		gMin++;
		foreach(Player, i)
		{
			/*
			* Sync player time with game time
			*/
			SetPlayerTime(i, gHour, gMin);
			
			if(gPlayerData[i][pJobTimeChange] > 0)
				gPlayerData[i][pJobTimeChange]--;
		}
		for(new i = 0; i < sizeof(gVehData); i++)
		{
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

					GetVehiclePos(i+1, gVehData[i][mVehX], gVehData[i][mVehY], gVehData[i][mVehZ]);
					GetVehicleZAngle(i+1, gVehData[i][mVehA]);

					SaveVehData(i, "VehSave2");
				}
			}
		}
		
		if(gMin == 60)
		{
			for(new i = 0; i < sizeof(Businesses); i++)
			{
				if(Businesses[i][mFactionTimeLeft] > 0)
				{
					Businesses[i][mFactionTimeLeft]--;
					SaveBizData(i, "FactionTimeLeft");
				}
			}
			gMin = 0;
			gHour++;
			if(gHour == 24)			
				gHour = 0;			
			if(gHour == 21)
			{
				if( gLuckyLotteryLastLottery <= 2 )
				{
					gLuckyLotteryLastLottery++;
					SaveLotteryData(-1);
					if(gLuckyLotteryLastLottery == 3)
					{
						/*
						* Global SMSes
						*/
						if(gLuckyLotteryLastLottery == 3)
						{
							format(string, sizeof(string), "Ju¿ dziœ odbêdzie siê losowanie w Szczêœliwej Loterii !\n Kumulacja wynosi ju¿ a¿ %d$ !\n\nTy te¿ mo¿esz zostaæ milionerem !",
								gLuckyLotteryCash);
							SendSmsToAll(CUSTOM_MAX_PLAYERS, 7200, string);
						}
					}
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
					gLuckyLotteryLastLottery = 0;
					SaveLotteryData(-1);
				}
			}
			
			HorseRacePrepare(2);
			
			for(new i; i < sizeof(gWeed); i++)
			{
				GrowthWeed(i);
			}
			
			for(new i; i < sizeof(DynamicFactions); i++)
			{
				if(DynamicFactions[i][mVehicleStealExportTimeLeft])
				{
					DynamicFactions[i][mVehicleStealExportTimeLeft]--;
					SaveFData(i, "VehicleStealExportTimeLeft");
				}
			}
			
			for(new i = 0; i < sizeof(DynamicZones); i++)
			{
				if(DynamicZones[i][mCharStealTimeLeft])
				{
					DynamicZones[i][mCharStealTimeLeft]--;
					SaveGangZone(i, "CharStealTimeLeft");
				}
				if(DynamicZones[i][mVehStealTimeLeft])
				{
					DynamicZones[i][mVehStealTimeLeft]--;
					SaveGangZone(i, "VehStealTimeLeft");
				}
				if(DynamicZones[i][mVehBreakTimeLeft])
				{
					DynamicZones[i][mVehBreakTimeLeft]--;
					SaveGangZone(i, "VehBreakTimeLeft");
				}
				if(DynamicZones[i][mHouseBreakTimeLeft])
				{
					DynamicZones[i][mHouseBreakTimeLeft]--;
					SaveGangZone(i, "HouseBreakTimeLeft");
				}
				if(DynamicZones[i][mHouseStealTimeLeft])
				{
					DynamicZones[i][mHouseStealTimeLeft]--;
					SaveGangZone(i, "HouseStealTimeLeft");
				}
				if(DynamicZones[i][mBizBreakTimeLeft])
				{
					DynamicZones[i][mBizBreakTimeLeft]--;
					SaveGangZone(i, "BizBreakTimeLeft");
				}
				if(DynamicZones[i][mBizStealTimeLeft])
				{
					DynamicZones[i][mBizStealTimeLeft]--;
					SaveGangZone(i, "BizStealTimeLeft");
				}
			}
		}
		else if(gMin == 30)
		{
			foreach(Player, i)
			{
				if(gPlayerVars[i][mAtBuildingID] == 121)
					SendClientMessage(i, COLOR_LIGHTYELLOW2, "[INFO:] Wyœcig rozpocznie siê za 30 minut !");
			}
		}
		else if(gMin == 10)
		{
			foreach(Player, i)
			{
				if(gPlayerVars[i][mAtBuildingID] == 121)
					SendClientMessage(i, COLOR_LIGHTYELLOW2, "[INFO:] Zak³ady do kolejnego wyœcigu rozpoczête !");
			}
			HorseRacePrepare(1);
		}
	}
	// format(string, sizeof string, "%d/%s%d/%s%d", day, ((month < 10) ? ("0") : ("")), month, (year < 10) ? ("0") : (""), year);
	// TextDrawSetString(Date, string);
	format(string, sizeof(string), "%s%d:%s%d:%s%d", (gHour < 10) ? ("0") : (""), gHour, (gMin < 10) ? ("0") : (""), gMin, (gSec < 10) ? ("0") : (""), gSec);
	TextDrawSetString(gTextTime, string);
}

task OneSecTimer[1000]()
{
	#if defined DEBUG2
		printf("[DEBUG:] OneSecTimer");
	#endif
	
	static string[256], string2[128];
	
	strdel(string, 0, sizeof(string));
	strdel(string, 0, sizeof(string2));
	
	/**
	* Kicking vote cooldown
	*/
	if(gReportCooldown > 0)
		gReportCooldown--;
	if(gKickVoteTimeLeft > 0)
	{
		if(!IsPlayerConnected(gKickVotePlayerToKick))
		{
			gKickVoteTimeLeft = 0;
			gKickVotePlayerToKick = INVALID_PLAYER_ID;
			foreach(Player, i)
				gKickVotePlayerVote[i] = 0;
			SendClientMessageToAll( COLOR_ORANGE, "{DF013A}[WParty SERVER:]{FFFFFF} Gracz opuœci³ serwer, g³osowanie przerwane" );
		}
		gKickVoteTimeLeft--;
		if(gKickVoteTimeLeft == 0)
		{
			new pCount = 0, positive = 0;
			
			foreach(Player, i )
			{
				if(!gPlayerLogged[i])
					continue;
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
				SendClientMessageToAll( COLOR_DARKRED, "{DF013A}[WParty SERVER:]{FFFFFF} Nie osi¹gniêto ponad 50%% g³osów za, gracz zostaje !" );
			gKickVotePlayerToKick = INVALID_PLAYER_ID;			
		}
	}
	if(gSanNewsMsgCountdown > 0)
		gSanNewsMsgCountdown--;
	else if(gSanNewsMsgCountdown == 0)
	{
		gSanNewsMsgCountdown = 10;
		gSanNewsMsgId++;
		if(gSanNewsMsgId > 9)
			gSanNewsMsgId = 0;
		while(gSanNewsMsgId > 0 && strlen(gSanNewsMsg[gSanNewsMsgId]) == 0)
		{
			gSanNewsMsgId++;
			if(gSanNewsMsgId > 9)
				gSanNewsMsgId = 0;
		}
		foreach(Player, i)
		{
			if(gPlayerLogged[i])
				RedrawSanNewsBox(i);
		}
	}
	/**
	* Horse race mechanism
	*/
	if(gHorseRaceStarted)
	{
		if(gHorseCD > 0)
		{
			format(string, sizeof(string), "%d", gHorseCD);
			TextDrawColor(gHorseCDTextDraw,0xff0000ff);
			TextDrawSetString(gHorseCDTextDraw, string);
			gHorseCD -= 1;
			foreach(Player, i)
			{
				if(!gPlayerLogged[i])
					continue;
				if(gPlayerVars[i][mAtBuildingID] == 121)
				{
					PlayerPlaySound(i, 3200, 0, 0, 0);
					TextDrawShowForPlayer(i, gHorseCDTextDraw);
				}
			}
		}
		else if(gHorseCD == 0)
		{
			gHorseCD = -1;
			TextDrawColor(gHorseCDTextDraw,0x00ff00ff);
			TextDrawSetString(gHorseCDTextDraw, "Start !");
			foreach(Player, i)
			{
				if(!gPlayerLogged[i])
					continue;
				if(gPlayerVars[i][mAtBuildingID] == 121)
				{
					PlayerPlaySound(i, 3201, 0, 0, 0);
					TextDrawShowForPlayer(i, gHorseCDTextDraw);
				}
			}
		}
		else if(gHorseCD == -1)
		{
			gHorseCD = -2;
			HorseAnim();
			foreach(Player, i)
			{
				TextDrawHideForAll(gHorseCDTextDraw);
			}
		}
	}
	
	/**
	* Races mechanism
	*/
	for(new i = 0; i < MAX_RACES; i++)
	{
		if(gRaceStatus[i][mRaceState] == RACE_STATE_JOINING)
		{
			if(gRaceStatus[i][mRaceTimeToStart])
				gRaceStatus[i][mRaceTimeToStart]--;
			if(!gRaceStatus[i][mRaceTimeToStart])
			{
				gettime(gRaceStatus[i][mRaceStartHour], gRaceStatus[i][mRaceStartMin], gRaceStatus[i][mRaceStartSec]);
				CheckRacersStartPos(i);
				PlayerRaceStartSound(i, 0);
				gRaceStatus[i][mRaceState] = RACE_STATE_RACE;
				format(string, sizeof(string), "START !", gRaceStatus[i][mRaceTimeToStart]);
				GameTextForRacers(i, "START !", 1000, 3);
				UnfreezeRacers(i);
				ResetRaceStandings(i);
				ShowFirstRaceCheckpoint(i);
			}
			else
			{
				if(gRaceStatus[i][mRaceTimeToStart] == 5)
				{
					CheckRacersStartPos(i);
					FreezeRacers(i);
					SetCameraAtStart(i, 1);
					PlayerRaceStartSound(i, 5);
					GameTextForRacers(i, "START WYSCIGU ZA: 5 SEKUND", 1000, 3);
				}
				if(gRaceStatus[i][mRaceTimeToStart] == 4)
				{
					SetCameraAtStart(i, 2);
					PlayerRaceStartSound(i, 4);
					GameTextForRacers(i, "START WYSCIGU ZA: 4 SEKUNDY", 1000, 3);
				}
				if(gRaceStatus[i][mRaceTimeToStart] == 3)
				{
					SetCameraAtStart(i, 3);
					PlayerRaceStartSound(i, 3);
					GameTextForRacers(i, "START WYSCIGU ZA: 3 SEKUNDY", 1000, 3);
				}
				if(gRaceStatus[i][mRaceTimeToStart] == 2)
				{
					SetCameraAtStart(i, 4);
					PlayerRaceStartSound(i, 2);
					GameTextForRacers(i, "START WYSCIGU ZA: 2 SEKUNDY", 1000, 3);
				}
				if(gRaceStatus[i][mRaceTimeToStart] == 1)
				{
					PlayerRaceStartSound(i, 1);
					SetCameraBehindRacers(i);
					GameTextForRacers(i, "START WYSCIGU ZA: 1 SEKUNDE", 1000, 3);
				}
				format(string, sizeof(string), "START WYSCIGU ZA: %d SEKUND", gRaceStatus[i][mRaceTimeToStart]);
			}
			TextDrawSetString(gRaceStatus[i][mRaceInfo], string);
		}
		else if(gRaceStatus[i][mRaceState] == RACE_STATE_RACE || gRaceStatus[i][mRaceState] == RACE_STATE_COUNTDOWN)
		{
			if(!gRaceStatus[i][mRaceTimeToStart])
			{
				gRaceStatus[i][mRaceTimeToStart] = -1;
				if(gRaceStatus[i][mRaceLaps] > 1)
					format(string, sizeof(string), "Okrazenie 1/%d", gRaceStatus[i][mRaceLaps]);
				else
					format(string, sizeof(string), " ");
				TextDrawSetString(gRaceStatus[i][mRaceInfo], string);
			}
			if(!IsAnyPlayerInRace(i))
			{
				ResetRaceData(i);
				continue;
			}
			CheckRacersVehicles(i);
			CheckPlayerStandings(i);
			RefreshRaceStandings(i);
		}
	}
	
	
	/**
	* Check vehicle damage status
	*/
	static Float:vehiclehp, enginedyn, lights, alarm, bonnet, boot, objective, doors, componentId;
	for(new i = 0; i < sizeof(gVehData); i++)
	{
		GetVehiclePos(i+1, gVehData[i][mVehX], gVehData[i][mVehY], gVehData[i][mVehZ]);
		if((floatabs(VehNewPos[i][0] - gVehData[i][mVehX]) > 100.0 ||
			floatabs(VehNewPos[i][1] - gVehData[i][mVehY]) > 100.0 ||
			floatabs(VehNewPos[i][2] - gVehData[i][mVehZ]) > 100.0) && !VehJustRespawned[i] && gVehData[i][mVehType] != 3)
		{
			format(string, sizeof(string), "[ANTI-CHEAT:] Vehicle ID: %d traveled distance bigger than 100 (x: %.1f, y: %.1f, z: %.1f), could be non function Vehicle TP", i+1, floatabs(VehNewPos[i][0] - gVehData[i][mVehX]), floatabs(VehNewPos[i][1] - gVehData[i][mVehY]), floatabs(VehNewPos[i][2] - gVehData[i][mVehZ]));
			ABroadCast(COLOR_YELLOW, string, 1);
			SetVehicleToPos(i+1, VehNewPos[i][0], VehNewPos[i][1], VehNewPos[i][2]);
			gVehData[i][mVehX] = VehNewPos[i][0];
			gVehData[i][mVehY] = VehNewPos[i][1];
			gVehData[i][mVehZ] = VehNewPos[i][2];
			foreach(Player, j)
			{
				if(gPlayerLogged[j] && !gPlayerData[j][pAdmin])
				{
					if(PlayerToPoint(20.0, j, gVehData[i][mVehX], gVehData[i][mVehY], gVehData[i][mVehZ]))
					{
						SendClientMessage(j, COLOR_RED, "[ANTI-CHEAT:] Zosta³eœ wyrzucony za u¿ywanie cheatów !");
						format(string, sizeof(string), "[ANTI-CHEAT:] %s has been kicked for using Vehicle Teleport", gPlayerData[j][pName]);
						ABroadCast(COLOR_YELLOW, string, 1);
						Kick(j);
					}
				}
			}
		}
		if(VehJustRespawned[i] > 0)
			VehJustRespawned[i]--;
		VehNewPos[i][0] = gVehData[i][mVehX];
		VehNewPos[i][1] = gVehData[i][mVehY];
		VehNewPos[i][2] = gVehData[i][mVehZ];
	
		if(gVehData[i][mVehModel] == 594)
			continue;
		
		GetVehicleHealth(i+1,vehiclehp);
		GetVehicleParamsEx(i+1, enginedyn, lights, alarm, doors, bonnet, boot, objective);
		
		if(enginedyn != gVehData[i][EngineOn])
		{
			SetVehicleParamsEx(i+1, gVehData[i][EngineOn], lights, alarm, doors, bonnet, boot, objective);
			printf("[WARNING:] Vehicle [%d] engine status differs from variable", i+1);
			format(string, sizeof(string), "Vehicle [%d] engine status differs from variable", i+1);
			ABroadCast(COLOR_YELLOW, string, 5);
			VehicleLog(string);
			ErrorLog(string);
		}
		
		if(vehiclehp > 100.0 && vehiclehp <= 250.0)
		{
			if(random(100) <= 50)
				continue;
			if(gVehData[i][CarDamaged] == 1)
				continue;
			SetVehicleHealth(i+1, 260.0);
			gVehData[i][CarDamaged] = 1;
			
			foreach(Player, n)
			{
				if(!gPlayerLogged[n])
					continue;
				if(GetPlayerVehicleID(n) != i+1 || GetPlayerState(n) != PLAYER_STATE_DRIVER)
					continue;

				if(gVehData[i][EngineOn])
				{
					SendClientMessage(n, COLOR_RED, "[INFO:] Pojazd uleg³ uszkodzeniu ! Nie mo¿esz jechaæ dalej.");
					SetVehicleParamsEx(i+1, 0, lights, alarm, doors, bonnet, boot, objective);
					gVehData[i][EngineOn] = 0;
					format(string, sizeof(string), "Vehicle [%d] has been damaged (undrivable) by %s", i+1, gPlayerData[n][pName]);
					VehicleLog(string);
					// Save in OneMinTimer();
				}
			}
		}
		else if (vehiclehp > 250.0 && vehiclehp <= 300.0)
		{
			SetVehicleHealth(i+1, 310.0);
			gVehData[i][CarDamaged] = 1;
			// Save in OneMinTimer();
			foreach(Player, n)
			{
				if(!gPlayerLogged[n])
					continue;
				if(GetPlayerVehicleID(n) != i+1 || GetPlayerState(n) != PLAYER_STATE_DRIVER)
					continue;

				if(gVehData[i][EngineOn] == 1)
				{
					SendClientMessage(n, COLOR_RED, "[INFO:] Pojazd uleg³ uszkodzeniu ! Nie mo¿esz jechaæ dalej.");
					SetVehicleParamsEx(i+1,0,lights,alarm,doors,bonnet,boot,objective);
					gVehData[i][EngineOn] = 0;
					format(string, sizeof(string), "Vehicle [%d] has been damaged (undrivable) by %s", i+1, gPlayerData[n][pName]);
					VehicleLog(string);
					// Save in OneMinTimer();
				}
			}
		}
		
		/*
		* AntiTune
		*/
		componentId = GetVehicleComponentInSlot(i+1, CARMODTYPE_SPOILER);
		if(componentId != gVehData[i][mVehSpoiler])
		{
			foreach(Player, j)
			{
				if(!gPlayerLogged[j] || gPlayerData[j][pAdmin] == 5)
					continue;
				if(IsPlayerInVehicle(j, i+1))
					BanPlayerAccount(j, "AntiTune Guard", "Generowanie czêœci tuningowych");
			}
			UnmodVehicle(i+1);
			continue;
		}
		componentId = GetVehicleComponentInSlot(i+1, CARMODTYPE_HOOD);
		if(componentId != gVehData[i][mVehHood])
		{
			foreach(Player, j)
			{
				if(!gPlayerLogged[j] || gPlayerData[j][pAdmin] == 5)
					continue;
				if(IsPlayerInVehicle(j, i+1))
					BanPlayerAccount(j, "AntiTune Guard", "Generowanie czêœci tuningowych");
			}
			UnmodVehicle(i+1);
			continue;
		}
		componentId = GetVehicleComponentInSlot(i+1, CARMODTYPE_ROOF);
		if(componentId != gVehData[i][mVehRoof])
		{
			foreach(Player, j)
			{
				if(!gPlayerLogged[j] || gPlayerData[j][pAdmin] == 5)
					continue;
				if(IsPlayerInVehicle(j, i+1))
					BanPlayerAccount(j, "AntiTune Guard", "Generowanie czêœci tuningowych");
			}
			UnmodVehicle(i+1);
			continue;
		}
		componentId = GetVehicleComponentInSlot(i+1, CARMODTYPE_SIDESKIRT);
		if(componentId != gVehData[i][mVehSideskirt])
		{
			foreach(Player, j)
			{
				if(!gPlayerLogged[j] || gPlayerData[j][pAdmin] == 5)
					continue;
				if(IsPlayerInVehicle(j, i+1))
					BanPlayerAccount(j, "AntiTune Guard", "Generowanie czêœci tuningowych");
			}
			UnmodVehicle(i+1);
			continue;
		}
		componentId = GetVehicleComponentInSlot(i+1, CARMODTYPE_LAMPS);
		if(componentId != gVehData[i][mVehLamps])
		{
			foreach(Player, j)
			{
				if(!gPlayerLogged[j] || gPlayerData[j][pAdmin] == 5)
					continue;
				if(IsPlayerInVehicle(j, i+1))
					BanPlayerAccount(j, "AntiTune Guard", "Generowanie czêœci tuningowych");
			}
			UnmodVehicle(i+1);
			continue;
		}
		componentId = GetVehicleComponentInSlot(i+1, CARMODTYPE_NITRO);
		if(componentId != gVehData[i][mVehNitro])
		{
			foreach(Player, j)
			{
				if(!gPlayerLogged[j] || gPlayerData[j][pAdmin] == 5)
					continue;
				if(IsPlayerInVehicle(j, i+1))
					BanPlayerAccount(j, "AntiTune Guard", "Generowanie czêœci tuningowych");
			}
			UnmodVehicle(i+1);
			continue;
		}
		componentId = GetVehicleComponentInSlot(i+1, CARMODTYPE_EXHAUST);
		if(componentId != gVehData[i][mVehExhaust])
		{
			foreach(Player, j)
			{
				if(!gPlayerLogged[j] || gPlayerData[j][pAdmin] == 5)
					continue;
				if(IsPlayerInVehicle(j, i+1))
					BanPlayerAccount(j, "AntiTune Guard", "Generowanie czêœci tuningowych");
			}
			UnmodVehicle(i+1);
			continue;
		}
		componentId = GetVehicleComponentInSlot(i+1, CARMODTYPE_WHEELS);
		if(componentId != gVehData[i][mVehWheels])
		{
			foreach(Player, j)
			{
				if(!gPlayerLogged[j] || gPlayerData[j][pAdmin] == 5)
					continue;
				if(IsPlayerInVehicle(j, i+1))
					BanPlayerAccount(j, "AntiTune Guard", "Generowanie czêœci tuningowych");
			}
			UnmodVehicle(i+1);
			continue;
		}
		componentId = GetVehicleComponentInSlot(i+1, CARMODTYPE_STEREO);
		if(componentId != gVehData[i][mVehStereo])
		{
			foreach(Player, j)
			{
				if(!gPlayerLogged[j] || gPlayerData[j][pAdmin] == 5)
					continue;
				if(IsPlayerInVehicle(j, i+1))
					BanPlayerAccount(j, "AntiTune Guard", "Generowanie czêœci tuningowych");
			}
			UnmodVehicle(i+1);
			continue;
		}
		componentId = GetVehicleComponentInSlot(i+1, CARMODTYPE_HYDRAULICS);
		if(componentId != gVehData[i][mVehHydraulics])
		{
			foreach(Player, j)
			{
				if(!gPlayerLogged[j] || gPlayerData[j][pAdmin] == 5)
					continue;
				if(IsPlayerInVehicle(j, i+1))
					BanPlayerAccount(j, "AntiTune Guard", "Generowanie czêœci tuningowych");
			}
			UnmodVehicle(i+1);
			continue;
		}
		componentId = GetVehicleComponentInSlot(i+1, CARMODTYPE_FRONT_BUMPER);
		if(componentId != gVehData[i][mVehFrontBumper])
		{
			foreach(Player, j)
			{
				if(!gPlayerLogged[j] || gPlayerData[j][pAdmin] == 5)
					continue;
				if(IsPlayerInVehicle(j, i+1))
					BanPlayerAccount(j, "AntiTune Guard", "Generowanie czêœci tuningowych");
			}
			UnmodVehicle(i+1);
			continue;
		}
		componentId = GetVehicleComponentInSlot(i+1, CARMODTYPE_REAR_BUMPER);
		if(componentId != gVehData[i][mVehRearBumper])
		{
			foreach(Player, j)
			{
				if(!gPlayerLogged[j] || gPlayerData[j][pAdmin] == 5)
					continue;
				if(IsPlayerInVehicle(j, i+1))
					BanPlayerAccount(j, "AntiTune Guard", "Generowanie czêœci tuningowych");
			}
			UnmodVehicle(i+1);
			continue;
		}
		componentId = GetVehicleComponentInSlot(i+1, CARMODTYPE_VENT_RIGHT);
		if(componentId != gVehData[i][mVehVentRight])
		{
			foreach(Player, j)
			{
				if(!gPlayerLogged[j] || gPlayerData[j][pAdmin] == 5)
					continue;
				if(IsPlayerInVehicle(j, i+1))
					BanPlayerAccount(j, "AntiTune Guard", "Generowanie czêœci tuningowych");
			}
			UnmodVehicle(i+1);
			continue;
		}
		componentId = GetVehicleComponentInSlot(i+1, CARMODTYPE_VENT_LEFT);
		if(componentId != gVehData[i][mVehVentLeft])
		{
			foreach(Player, j)
			{
				if(!gPlayerLogged[j] || gPlayerData[j][pAdmin] == 5)
					continue;
				if(IsPlayerInVehicle(j, i+1))
					BanPlayerAccount(j, "AntiTune Guard", "Generowanie czêœci tuningowych");
			}
			UnmodVehicle(i+1);
			continue;
		}
	}

	
	/*
	* Check if player is in burning factory
	* Take player HP if TRUE
	*/
	for( new n = 0; n < sizeof(DynamicFactions); n++ )
	{
		if( DynamicFactions[n][fType] == 3 && DynamicFactions[n][WFactoryBurning] )
		{
			foreach(Player, i )
			{
				if( PlayerToPoint( 10.0, i, DynamicFactions[n][WFactoryCentrePosX], DynamicFactions[n][WFactoryCentrePosY], DynamicFactions[n][WFactoryCentrePosZ] ) )
				{
					gPlayerData[i][pHP] -= 2.0;
					SetPlayerHealth( i, gPlayerData[i][pHP] );
					// save on exit
				}
			}
		}
	}

	
	/*
	* Other related to player stuff
	*/
	static location[MAX_ZONE_NAME];
	static Float: posX, Float: posY, Float: posZ, Float: posA, Float: dist, weapon, ammo, ping, vehicleID, hack;
	static tmpslot[MAX_PLAYER_ITEM_SLOT], haveGPS, isGPSOn, j;
	foreach(Player, i )
	{
		if(!gPlayerLogged[i] || !Alive[i])
			continue;
		if(gPlayerVars[i][mNewbieCoolDown])
			gPlayerVars[i][mNewbieCoolDown]--;
		if(gPlayerVars[i][mBugInfoCoolDown])
			gPlayerVars[i][mBugInfoCoolDown]--;
		if(gKickVoteStartCooldown[i] > 0)
			gKickVoteStartCooldown[i]--;
		if(gVehPosCheckCooldown[i] > 0)
			gVehPosCheckCooldown[i]--;
		if(gAddCooldown[i] > 0)
			gAddCooldown[i]--;
		if(gTGunIDLastCD[i] > 0)
			gTGunIDLastCD[i]--;
		else
			gTGunIDLast[i] = 0;
		if(gJustDropped[i] > 0)
			gJustDropped[i]--;
		if(gTryCoolDown[i] > 0)
			gTryCoolDown[i]--;
		if(gTransferCoolDown[i] > 0)
			gTransferCoolDown[i]--;
		if(gPlayerVars[i][mSprinting] > 0)
			gPlayerVars[i][mSprinting]--;
		if(gPlayerVars[i][mJumped] > 0)
		{
			if(gPlayerVars[i][mJumped] > 2 && gPlayerData[i][pAdmin] == 0)
			{
				SendClientMessage(i, COLOR_RED, "[INFO:] BH jest zabronione !");
				SendClientMessage(i, COLOR_RED, "[INFO:] Aby wstaæ wpisz /wstan1");
				format(string, sizeof(string), "[INFO:] Gracz %s [%d] u¿ywa BH", gPlayerData[i][pName], i);
				ABroadCast(COLOR_YELLOW, string, 1);
				ApplyAnimation(i,"PED","FLOOR_hit_f",4.0,0,1,1,1,0);
				gPlayerVars[i][mJumped] = 2;
			}
			else
				gPlayerVars[i][mJumped]--;
		}
		if(gPlayerVars[i][mPhoneDataTimeout] > 0)
		{
			gPlayerVars[i][mPhoneDataTimeout]--;
			if(gPlayerVars[i][mPhoneDataTimeout] == 0)
			{
				gPlayerVars[i][mPhoneDataTimeout] = -1;
				gPlayerVars[i][mPhoneDataReceived] = 1;
			}
		}
		if(gPlayerData[i][pMechanicCoolDown] > 0)
		{
			gPlayerData[i][pMechanicCoolDown]--;
			SavePlayerData(i, "MechanicCoolDown");
		}
		if(gPlayerData[i][pCharacterDying] >= 2)
		{
			format(string, sizeof(string), "~r~Jestes nieprzytomny !~n~Przebudzisz sie za %d sekund", gPlayerData[i][pCharacterDying]);
			GameTextForPlayer(i, string, 1000, 3);
			gPlayerData[i][pCharacterDying]--;
			SavePlayerData(i, "CharacterDying");
		}
		
		// Return player to life instead of killing...
		else if (gPlayerData[i][pCharacterDying] == 1)
		{
			SetPlayerHealth( i, 30.0 );
			gPlayerData[i][pHP] = 30.0;
			// save on exit
			gPlayerData[i][pCharacterDying] = 0;			
			SavePlayerData(i, "CharacterDying");			
			TogglePlayerControllable( i,1 );
			SetCameraBehindPlayer( i );
			ApplyAnimation(i,"PED","getup",4.0,0,0,0,0,0);
			if(PlayerCuffed[i])
				SetPlayerSpecialAction(i, SPECIAL_ACTION_CUFFED);
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
		if(gPlayerData[i][pFaction] != 255)
		{
			if(DynamicFactions[gPlayerData[i][pFaction]][fType] == 3 && gGangWar[Enabled] && (gGangWar[FactionStarted] == gPlayerData[i][pFaction] || gGangWar[FactionAttacked] == gPlayerData[i][pFaction]))
			{
				if(gPlayerData[i][pFaction] == gGangWar[FactionStarted])
					format(string, sizeof(string), "TWOJ GANG %d:%d WROGI GANG", gGangWar[FactionStartedKills], gGangWar[FactionAttackedKills]);
				else
					format(string, sizeof(string), "TWOJ GANG %d:%d WROGI GANG", gGangWar[FactionAttackedKills], gGangWar[FactionStartedKills]);
				TextDrawSetString(GangWar[i], string );
				format(string, sizeof(string), "POZOSTALO CZASU: %d MINUT", gGangWar[TimeLeft]);
				TextDrawSetString(GangWarTime[i], string);
			}
		}	
		
		// Custom Money Text
		// format(string, sizeof(string), "%08d$", GetPlayerMoney(i));
		// TextDrawSetString(PlayerMoney[i], string);
		// TextDrawShowForPlayer(i, PlayerMoney[i]);
		// TextDrawShowForPlayer(i, PlayerMoneyBox[i]);
		
		// Update money
		if (GetPlayerCash(i) != GetPlayerMoney(i))
		{
			hack = GetPlayerMoney(i) - GetPlayerCash(i);
			if(hack >= 500)
			{
				format(string, sizeof(string), "[WARNING:] %s (ID:%d) tried to spawn %d$ - This could be a money cheat.",gPlayerData[i][pName],i, hack);
				HackLog(string);
				ABroadCast(COLOR_YELLOW,string,1);
			}
			ResetMoneyBar(i); //Resets the money in the original moneybar, Do not remove!
			UpdateMoneyBar(i,gPlayerData[i][pCash]); //Sets the money in the moneybar to the serverside cash, Do not remove!
		}
		// player status bar
		haveGPS = 0;
		isGPSOn = 0;
		PHaveItemEx(i, 3, 12, tmpslot);
		for(j = 0; j < MAX_PLAYER_ITEM_SLOT; j++)
		{
			if(tmpslot[j])
			{
				haveGPS = 1;
				if(SlotParam1(i, j+1))
					isGPSOn = 1;
			}
		}
		if(PlayerStatusShowed[i])
		{
			GetPlayer2DZone(i, location, MAX_ZONE_NAME);
			
			if(!haveGPS)
				format(string2, sizeof(string2), "~y~Lokacja: ~w~brak modulu GPS");
			else if(haveGPS)
			{
				if(!isGPSOn) { format(string2, sizeof(string2), "~y~Lokacja: ~w~modul GPS wylaczony"); }
				if(isGPSOn) { format(string2, sizeof(string2), "~y~Lokacja: ~w~%s", location); }
			}
			if(gSpectateID[i] != INVALID_PLAYER_ID && GetPlayerState(i) == PLAYER_STATE_SPECTATING)
			{
				GetPlayer2DZone(gSpectateID[i], location, MAX_ZONE_NAME);
				if(gPlayerData[gSpectateID[i]][pFaction] != 255)
					format(string, sizeof(string), "~y~Przegranych godzin: ~w~%d ~y~Frakcja: ~w~%s %s", gPlayerData[gSpectateID[i]][pPlayingHours], DynamicFactions[gPlayerData[gSpectateID[i]][pFaction2]][Name], string2);
				else
					format(string, sizeof(string), "~y~Przegranych godzin: ~w~%d ~y~Doswiadczenie: ~w~%d/%d ~y~Frakcja: ~w~Brak %s", gPlayerData[gSpectateID[i]][pPlayingHours], string2);
				if(gPlayerData[gSpectateID[i]][pFaction2] != 255)
					format(string, sizeof(string), "%s~y~Firma: ~w~%s", string, DynamicFactions[gPlayerData[gSpectateID[i]][pFaction2]][Name]);
				else
					format(string, sizeof(string), "%s~y~Firma: ~w~Brak");
				format(string, sizeof(string), "%s%s", string, string2);
				if(haveGPS && isGPSOn)
				{
					GetPlayerPos(gSpectateID[i], posX, posY, posZ);
					GetPlayerFacingAngle(gSpectateID[i], posA);
					format(string, sizeof(string), "%s ~y~X: ~w~%.2f ~y~Y: ~w~%.2f ~y~Z: ~w~%.2f ~y~A: ~w~%.2f", string, posX, posY, posZ, posA);
				}
			}
			else
			{
				if(gPlayerData[i][pFaction] != 255)
					format(string, sizeof(string), "~y~Przegranych godzin: ~w~%d ~y~Frakcja: ~w~%s %s", gPlayerData[i][pPlayingHours], DynamicFactions[gPlayerData[i][pFaction]][Name]);
				else
					format(string, sizeof(string), "~y~Przegranych godzin: ~w~%d ~y~Frakcja: ~w~Brak %s", gPlayerData[i][pPlayingHours]);
				if(gPlayerData[i][pFaction2] != 255)
					format(string, sizeof(string), "%s~y~Firma: ~w~%s %s", string, DynamicFactions[gPlayerData[i][pFaction2]][Name]);
				else
					format(string, sizeof(string), "%s~y~Firma: ~w~Brak %s", string);				
				format(string, sizeof(string), "%s%s", string, string2);
				if(haveGPS && isGPSOn)
				{
					GetPlayerPos(i, posX, posY, posZ);
					GetPlayerFacingAngle(i, posA);
					format(string, sizeof(string), "%s ~y~X: ~w~%.2f ~y~Y: ~w~%.2f ~y~Z: ~w~%.2f ~y~A: ~w~%.2f", string, posX, posY, posZ, posA);
				}
			}
			TextDrawSetString(PlayerStatus[i], string);
		}
		// UAC system
		if(Spawned[i] && !IsPlayerNPC(i) && gPlayerData[i][pAdmin] == 0)
		{
			// AntiAmmoHack
			for(new slot = 0; slot <= 12; slot++)
			{
				GetPlayerWeaponData(i, slot, weapon, ammo);
				if(Gun[i][Weapon][slot] != weapon)
				{
					if(ammo > Ammo[i][weapon])
					{
						if((ammo - Ammo[i][weapon]) >= UAC_MAX_AMMO)
						{
							printf("ammo: %d, Ammo[%d][%d]: %d", ammo, i, weapon, Ammo[i][weapon]);
							SendClientMessage(i, COLOR_RED, "[ANTI-CHEAT:] Zosta³eœ wyrzucony za u¿ywanie cheatów ! (AmmoHack) !");
							format(string, sizeof(string), "[ANTI-CHEAT:] %s has been kicked for using AmmoHack", gPlayerData[i][pName]);
							ABroadCast(COLOR_YELLOW, string, 1);
							ResetPlayerWeapons(i);
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
					GetPlayerPos(i, posX, posY, posZ);
					if(GetDistanceToPoint(i,NewPos[i][0],NewPos[i][1],NewPos[i][2]) > 500.0 && posX != 0.0 && posY != 0.0)
					{
						printf("[WARNING:] %s [%d] used TP", GetPlayerNameEx(i), i);
						format(string,sizeof(string), "[ANTI-CHEAT:] Zosta³eœ wyrzucony za u¿ywanie cheatów !");
						SendClientMessage(i, COLOR_RED, string);
						format(string, sizeof(string), "[ANTI-CHEAT:] %s has been kicked for using Teleport", gPlayerData[i][pName]);
						ABroadCast(COLOR_YELLOW, string, 1);
						Kick(i);
					}
					else if(GetDistanceToPoint(i,NewPos[i][0],NewPos[i][1],NewPos[i][2]) > 120 && GetPlayerState(i) == PLAYER_STATE_ONFOOT && posX != 0.0 && posY != 0.0)
					{
						printf("[WARNING:] %s [%d] used TP", GetPlayerNameEx(i), i);
						format(string,sizeof(string), "[ANTI-CHEAT:] Zosta³eœ wyrzucony za u¿ywanie cheatów !");
						SendClientMessage(i, COLOR_RED, string);
						format(string, sizeof(string), "[ANTI-CHEAT:] %s has been kicked for using Teleport", gPlayerData[i][pName]);
						ABroadCast(COLOR_YELLOW, string, 1);
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
				format(string, sizeof(string), "[ANTI-CHEAT:] %s has been kicked for using Jetpack Hack", gPlayerData[i][pName]);
				ABroadCast(COLOR_YELLOW, string, 1);
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
					format(string, sizeof(string), "[ANTI-CHEAT:] %s has been kicked for HighPing [Max Ping: %d]", gPlayerData[i][pName], MAX_PING);
					ABroadCast(COLOR_YELLOW, string, 1);
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
				// save on exit

				format(string, sizeof(string), "~n~~n~~n~~n~~n~~n~~n~~w~Pozostalo czasu: ~g~%d sekund.",gPlayerData[i][pJailTime]);
				GameTextForPlayer(i, string, 999, 3);
			}
			else if(gPlayerData[i][pJailTime] == 0)
			{
				gPlayerData[i][pJailed] = 0;
				// save on exit

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

				if(posX == 0.0 || posY == 0.0)
					printf("[WARNING:] Jailed x = %d, y = %d", posX, posY);

				TogglePlayerControllable(i, 0);
				defer UnfreezePlayer(i);

				SendClientMessage(i, COLOR_LIGHTYELLOW2,"[INFO:] Zosta³eœ rozgrzeszony i wypuszczony.");
			}
		}
		// Vehicle speedometer and counter
		if(Alive[i] == 1 && IsPlayerInAnyVehicle(i))
		{
			vehicleID = GetPlayerVehicleID(i);
			dist = ASpeed(vehicleID);

			if(CheckDelay[i] >= 1)
				CheckDelay[i]--;
			else
			{
                if(floatround(dist) < 1000)
				{
					if(IsPlayerTaxiPassenger[i])
						gTaxiPassengerDistance[i] += floatround(dist);
					
					if(GetPlayerState(i) == PLAYER_STATE_DRIVER)
					{
						gVehData[vehicleID-1][CarCounter] += floatround(dist, floatround_round);
						if(dist > 28.0)
							gVehData[vehicleID-1][CarHealth] -= dist/900;
						else
							gVehData[vehicleID-1][CarHealth] -= dist/450;
						SetVehicleHealth(vehicleID, gVehData[vehicleID-1][CarHealth]);						
					}						

					gPlayerData[i][pAchieveDistance] += floatround(dist, floatround_round);
					// Save CarCounter moved to OneMinTimer
				}
			}
		}
		if(gBusDriverOnDuty[i] == 1)
			busCheckpoints(i);
		if(gTrashDriverOnDuty[i] == 1)
			trashCheckpoints(i);
		if(gSweeperDriverOnDuty[i] == 1)
			sweeperCheckpoints(i);
		if(gFarmerDriverOnDuty[i] == 1)
			farmerCheckpoints(i);
	}
	
	//printf("MS na koncu timera: %d", tickcount(ticks));
	return 1;
}

task OneMinTimer[60000]()
{
	#if defined DEBUG
		printf("[DEBUG:] OneMinTimer");
	#endif
	
	static string[256], vehid, enginedyn, lights, alarm, doors, bonnet, boot, objective, Float:vehiclehp;
	
	strdel(string, 0, sizeof(string));	
	
	/*
	* Check what phones have new messages
	*/
	format(string, sizeof(string), "SELECT `ReceiverNumber` FROM `samp_sms` WHERE `New` = '1' ORDER BY `ID` DESC LIMIT 0,500");
	mysql_query(string, CHECK_PHONE_NEW_SMS, INVALID_PLAYER_ID, db_con4);
	
	
	GenerateTrashObjectsForTrash();
	
	/*
	* Vehicle data update - actually only battery and some engine stuff
	*/
	for( new i = 0; i < sizeof(gVehData); i++ )
	{
		GetVehicleParamsEx(i+1,enginedyn,lights,alarm,doors,bonnet,boot,objective);
		if(gVehData[i][EngineOn])
		{
			if(gVehData[i][BatteryMaxCapacity] > 0.0)
				gVehData[i][BatteryMaxCapacity] -= VehBatDegradation(gVehData[i][BatteryID]);
			if(gVehData[i][BatteryMaxCapacity] < 0.0)
				gVehData[i][BatteryMaxCapacity] = 0.0;
			if(gVehData[i][BatteryCapacity] < gVehData[i][BatteryMaxCapacity])
			{
				gVehData[i][BatteryCapacity] += 1.0;
			}
			if(gVehData[i][EngineTemp] < 5 )
				gVehData[i][EngineTemp]++;
			GetVehicleHealth(i+1,vehiclehp);
			if( vehiclehp < 600.0 && gVehData[i][EngineTemp] == 5 )
			{
				SetVehicleParamsEx(i+1,0,lights,alarm,doors,bonnet,boot,objective);
				gVehData[i][EngineOn] = 0;
			}
		}
		else
		{
			if( gVehData[i][EngineTemp] > 0 )
				gVehData[i][EngineTemp]--;
			if( gVehData[i][mVehType] == 0 )
			{
				if( gVehData[i][LightsOn] )
					gVehData[i][BatteryCapacity] -= 0.8;
				if( gVehData[i][RadioOn] )
					gVehData[i][BatteryCapacity] -= 0.2;
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
		}
	}
	
	/*
	* Faction data update
	*/
	for(new i = 0; i < sizeof(DynamicFactions); i++)
	{
		if(DynamicFactions[i][fNotification1] > 0)
		{
			DynamicFactions[i][fNotification1]--;
			if(DynamicFactions[i][fNotification1] == 0)
				DynamicFactions[i][fNotification1ID] = -1;
		}
		if(DynamicFactions[i][fNotification2] > 0)
		{
			DynamicFactions[i][fNotification2]--;
			if(DynamicFactions[i][fNotification2] == 0)
				DynamicFactions[i][fNotification2ID] = -1;
		}
		if(DynamicFactions[i][fNotification3] > 0)
		{
			DynamicFactions[i][fNotification3]--;
			if(DynamicFactions[i][fNotification3] == 0)
				DynamicFactions[i][fNotification3ID] = -1;
		}
		if(DynamicFactions[i][fNotification4] > 0)
		{
			DynamicFactions[i][fNotification4]--;
			if(DynamicFactions[i][fNotification4] == 0)
				DynamicFactions[i][fNotification4ID] = -1;
		}
		if(DynamicFactions[i][fNotification5] > 0)
		{
			DynamicFactions[i][fNotification5]--;
			if(DynamicFactions[i][fNotification5] == 0)
				DynamicFactions[i][fNotification5ID] = -1;
		}
	}
	
	/*
	* Gang war status
	*/
	if(gGangWar[Enabled] == 1)
	{
		if(gGangWar[TimeLeft] == 0)
		{
			foreach(Player, i )
			{
				if(!gPlayerLogged[i])
					continue;
				if( gPlayerData[i][pFaction] != 255 )
				{
					if( DynamicFactions[ gPlayerData[i][pFaction] ][fType] == 3 )
					{
						TextDrawSetString(GangWar[i], " ");
						TextDrawSetString(GangWarTime[i], " ");
						GangZoneStopFlashForPlayer(i, gGangWar[AreaID]);
					}
				}
			}
			gGangWar[Enabled] = 0;
			if(gGangWar[FactionStartedKills] > gGangWar[FactionAttackedKills])
			{
				DynamicFactions[gGangWar[FactionStarted]][fTerritoryWarWins]++;
				SaveFData(gGangWar[FactionStarted], "TerritoryWarWins");
				DynamicFactions[gGangWar[FactionAttacked]][fTerritoryWarLooses]++;
				SaveFData(gGangWar[FactionAttacked], "TerritoryWarLooses");
				DynamicZones[gGangWar[AreaID]][mFaction] = gGangWar[FactionStarted];
				foreach(Player, j)
				{
					if(!gPlayerLogged[j])
						continue;
					if(gPlayerData[j][pFaction] != 255)
					{
						if(DynamicFactions[gPlayerData[j][pFaction]][fType] == 3)
						{						
							GangZoneHideForPlayer(j, gGangWar[AreaID]);
							if(gPlayerData[j][pFaction] == DynamicZones[gGangWar[AreaID]][mFaction])
								GangZoneShowForPlayer(j, gGangWar[AreaID], 0x00FF0090);
							else
								GangZoneShowForPlayer(j, gGangWar[AreaID], 0xFF000090);
						}
					}
				}
				SendFactionTypeMessage(3, COLOR_LIGHTYELLOW2, "TERYTORIUM ZOSTA£O PRZEJÊTE");
				SaveGangZone(gGangWar[AreaID], "Faction");
			}
			else if(gGangWar[FactionStartedKills] <= gGangWar[FactionAttackedKills])
			{
				DynamicFactions[gGangWar[FactionAttacked]][fTerritoryWarWins]++;
				SavePlayerData(gGangWar[FactionAttacked], "TerritoryWarWins");
				DynamicFactions[gGangWar[FactionStarted]][fTerritoryWarLooses]++;
				SavePlayerData(gGangWar[FactionStarted], "TerritoryWarLooses");
				foreach(Player, j)
				{
					if(!gPlayerLogged[j])
						continue;
					if(gPlayerData[j][pFaction] != 255)
					{
						if(DynamicFactions[gPlayerData[j][pFaction]][fType] == 3)
						{						
							GangZoneHideForPlayer(j, gGangWar[AreaID]);
							if(gPlayerData[j][pFaction] == DynamicZones[gGangWar[AreaID]][mFaction])
								GangZoneShowForPlayer(j, gGangWar[AreaID], 0x00FF0090);
							else
								GangZoneShowForPlayer(j, gGangWar[AreaID], 0xFF000090);
						}
					}
				}
				format(string, sizeof(string), "[INFO:] Terytorium zostaje pod kontrol¹ %s", DynamicFactions[ DynamicZones[ gGangWar[AreaID] ][mFaction] ][Name]);
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
					if( IsPlayerInArea( i, DynamicZones[ gGangWar[AreaID] ][mPosMaxX]*1.0, DynamicZones[ gGangWar[AreaID] ][mPosMinX]*1.0, DynamicZones[ gGangWar[AreaID] ][mPosMaxY]*1.0, DynamicZones[ gGangWar[AreaID] ][mPosMinY]*1.0 ) )
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
		if(gGangWar[TimeAlone] >= 10)
		{
			gGangWar[Enabled] = 0;
			DynamicZones[gGangWar[AreaID]][mFaction] = gGangWar[FactionStarted];
			
			foreach(Player, i)
			{
				if(!gPlayerLogged[i])
					continue;
				if(gPlayerData[i][pFaction] != 255)
				{
					if(DynamicFactions[gPlayerData[i][pFaction]][fType] == 3)
					{
						TextDrawSetString(GangWar[i], " ");
						TextDrawSetString(GangWarTime[i], " ");
						GangZoneStopFlashForPlayer( i, gGangWar[AreaID]);
						GangZoneHideForPlayer(i, gGangWar[AreaID]);
						if(gPlayerData[i][pFaction] == DynamicZones[gGangWar[AreaID]][mFaction])
							GangZoneShowForPlayer(i, gGangWar[AreaID], 0x00FF0090);
						else
							GangZoneShowForPlayer(i, gGangWar[AreaID], 0xFF000090);
					}
				}
			}
			SendFactionTypeMessage(3, COLOR_LIGHTYELLOW2, "TERYTORIUM ZOSTA£O PRZEJÊTE");
			SaveGangZone(gGangWar[AreaID], "Faction");
		}
	}
	
	/*
	* Player stuff
	*/
	foreach(Player, i )
	{
		if(!gPlayerLogged[i])
			continue;
			
		if(gPlayerVars[i][mBulletProof] > 0)
			gPlayerVars[i][mBulletProof]--;
		
		SavePlayerData(i, "AchieveDistance");
		if(Mobile[i] != 255)
		{
			if(Mobile[Mobile[i]] != 255 && StartedCall[i])
			{
				if(gPlayerVars[i][mPhoneType] == PHONET_FEE)
				{
					if(gCallFreeMins[i] <= 0)
						gCallCost[i] += DynamicFactions[Businesses[gCalledCompany[i]][mFaction]][mCallCostFee];
					else
					{
						gCallFreeMins[i]--;
						gCallCost[i] = 0;
					}
				}
				else if(gPlayerVars[i][mPhoneType] == PHONET_CARD)
					gPlayerVars[i][mPhoneCash] -= DynamicFactions[Businesses[gCalledCompany[i]][mFaction]][mCallCostCard];
			}
		}
		if(IsPlayerInDynamicArea(i, gArea_CarTest))
		{
			if(gPlayerData[i][pTestAreaTimeLeft] > 0 && PHaveItemParam5Ex(i, 3, 18, gPlayerData[i][pName]) == -1 && !TakingDrivingTestA[i] && !TakingDrivingTestB[i] && !TakingDrivingTestCE[i])
			{
				gPlayerData[i][pTestAreaTimeLeft]--;
				SavePlayerData(i, "TestAreaTimeLeft");
			}
			if(gPlayerData[i][pTestAreaTimeLeft] <= 0 && !AdminDuty[i] && PHaveItemParam5Ex(i, 3, 18, gPlayerData[i][pName]) == -1 && !TakingDrivingTestA[i] && !TakingDrivingTestB[i] && !TakingDrivingTestCE[i])
			{
				if(IsPlayerInAnyVehicle(i))
				{
					vehid = GetPlayerVehicleID(i);
					SetVehicleToRespawnEx(vehid);
				}
				SetPlayerToPos(i, gDrivingTestArea[posEntranceX], gDrivingTestArea[posEntranceY], gDrivingTestArea[posEntranceZ]);
				SetPlayerFacingAngle(i, gDrivingTestArea[posEntranceAngle]);
				SetPlayerInterior(i, gDrivingTestArea[posEntranceInterior]);
				SetPlayerVirtualWorld(i, gDrivingTestArea[posEntranceWorld]);
				SendClientMessage(i, COLOR_ORANGE, "[INFO:] Skoñczy³ siê twój wykupiony czas na placu manewrowym !");
			}
		}
		if(!VipAFKActive[i] && !AdminDuty[i] && GetPlayerState(i) != PLAYER_STATE_SPECTATING && Spawned[i] && !PosHackCheckTime[i])
		{
			/*
			* Decrease used medicaments effects
			*/
			if(gPlayerData[i][pPainKiller] > 0)
				gPlayerData[i][pPainKiller]--;
			if(gPlayerData[i][pSlimming] > 0)
				gPlayerData[i][pSlimming]--;
			if(gPlayerData[i][pStomachDrops] > 0)
				gPlayerData[i][pStomachDrops]--;
			/*
			* This part checks eating needs
			*/	
			if(gPlayerData[i][pJailed] == 0 && gPlayerData[i][pCharacterDying] == 0)
			{
				// Health problems
				if((IsPlayerVip(i) && gPlayerData[i][pStomach] >= MAX_STOMACH_VIP) || (!IsPlayerVip(i) && gPlayerData[i][pStomach] >= MAX_STOMACH))
				{
					defer PlayerWomit(i);
					gPlayerData[i][pVitamins] -= 10.0;
					gPlayerData[i][pPoison] += 15.0;
					gPlayerData[i][pEnergy] -= 20.0;
					gPlayerData[i][pStomach] -= 50.0;
					SetPlayerDrunkLevelEx(i, 4000);	
					SendClientMessage(i, COLOR_ORANGE, "[INFO:] Zjad³eœ za du¿o ! Czujesz siê Ÿle");
				}
				// Energy
				if(gPlayerData[i][pEnergy] > 0.0)
				{
					format(string, sizeof(string), "EO: %f; HO: %f; TO: %f; PO: %f; FO: %f; SO: %f; VO: %f",
						gPlayerData[i][pEnergy], gPlayerData[i][pHunger], gPlayerData[i][pThirst], gPlayerData[i][pPoison],
						gPlayerData[i][pFat], gPlayerData[i][pStomach], gPlayerData[i][pVitamins]); 
					if(IsPlayerVip(i))
					{
						if(gPlayerVars[i][mAtHouseID] != -1)
						{
							if(strcmp(Houses[gPlayerVars[i][mAtHouseID]][Owner], gPlayerData[i][pName], false) == 0 || strcmp(gPlayerData[i][pName], Houses[gPlayerVars[i][mAtHouseID]][HRenter], false) == 0)
							{
								gPlayerData[i][pEnergy] += 0.5;
								if(gPlayerData[i][pEnergy] > MAX_ENERGY_VIP)
									gPlayerData[i][pEnergy] = MAX_ENERGY_VIP;
							}
						}
						else
						{
							// hunger and thirst
							if(gPlayerData[i][pThirst] == MAX_THIRST_VIP && gPlayerData[i][pHunger] < MAX_HUNGER_VIP)
								gPlayerData[i][pEnergy] -= ENERGY*0.375;
							else if(gPlayerData[i][pThirst] == MAX_THIRST_VIP && gPlayerData[i][pHunger] == MAX_HUNGER_VIP)
								gPlayerData[i][pEnergy] -= ENERGY*0.625;
							// poison
							if(gPlayerData[i][pPoison] >= 30.0 && gPlayerData[i][pPoison] < 60.0)
								gPlayerData[i][pEnergy] -= ENERGY*0.05;
							else if(gPlayerData[i][pPoison] >= 60.0 && gPlayerData[i][pPoison] < 90.0)
								gPlayerData[i][pEnergy] -= ENERGY*0.05;
							else if(gPlayerData[i][pPoison] >= 90.0 && gPlayerData[i][pPoison] < 120.0)
								gPlayerData[i][pEnergy] -= ENERGY*0.1;
							else if(gPlayerData[i][pPoison] >= 120.0 && gPlayerData[i][pPoison] <= 150.0)
								gPlayerData[i][pEnergy] -= ENERGY*0.15;
							gPlayerData[i][pEnergy] -= ENERGY;
						}
					}
					else
					{
						if(gPlayerVars[i][mAtHouseID] != -1)
						{							
							if(strcmp(Houses[gPlayerVars[i][mAtHouseID]][Owner], gPlayerData[i][pName], false) == 0 || strcmp(gPlayerData[i][pName], Houses[gPlayerVars[i][mAtHouseID]][HRenter], false) == 0)
							{
								gPlayerData[i][pEnergy] += 0.5;
								if(gPlayerData[i][pEnergy] > MAX_ENERGY)
									gPlayerData[i][pEnergy] = MAX_ENERGY;
							}
						}
						else
						{
							// hunger and thirst
							if(gPlayerData[i][pThirst] == MAX_THIRST && gPlayerData[i][pHunger] < MAX_HUNGER)
								gPlayerData[i][pEnergy] -= ENERGY*0.375;
							else if(gPlayerData[i][pThirst] == MAX_THIRST && gPlayerData[i][pHunger] == MAX_HUNGER)
								gPlayerData[i][pEnergy] -= ENERGY*0.625;
							// poison
							if(gPlayerData[i][pPoison] >= 20.0 && gPlayerData[i][pPoison] < 40.0)
								gPlayerData[i][pEnergy] -= ENERGY*0.05;
							else if(gPlayerData[i][pPoison] >= 40.0 && gPlayerData[i][pPoison] < 60.0)
								gPlayerData[i][pEnergy] -= ENERGY*0.05;
							else if(gPlayerData[i][pPoison] >= 60.0 && gPlayerData[i][pPoison] < 80.0)
								gPlayerData[i][pEnergy] -= ENERGY*0.1;
							else if(gPlayerData[i][pPoison] >= 80.0 && gPlayerData[i][pPoison] <= 100.0)
								gPlayerData[i][pEnergy] -= ENERGY*0.15;
							// fat
							if(gPlayerData[i][pFat] >= 0.0 && gPlayerData[i][pFat] < 30.0)
								gPlayerData[i][pEnergy] -= ENERGY*0.1;
							else if(gPlayerData[i][pFat] >= 60.0 && gPlayerData[i][pFat] <= 100.0)
								gPlayerData[i][pEnergy] -= ENERGY*0.1;
							// default
							gPlayerData[i][pEnergy] -= ENERGY;
						}
					}
					if(gPlayerData[i][pEnergy] <= 20 && gPlayerData[i][pEnergy] >= 10)
						SendClientMessage(i, COLOR_ORANGE, "[INFO:] Czujesz siê os³abiony");
					if(gPlayerData[i][pEnergy] < 10)
						SendClientMessage(i, COLOR_ORANGE, "[INFO:] Czujesz siê bardzo os³abiony");
				}
				if(gPlayerData[i][pEnergy] < 0.0)
					gPlayerData[i][pEnergy] = 0.0;
				// Hunger
				if(IsPlayerVip(i))
				{
					if(gPlayerData[i][pHunger] < MAX_HUNGER_VIP)
					{
						// thirst
						if(gPlayerData[i][pThirst] == MAX_THIRST_VIP)
							gPlayerData[i][pHunger] += HUNGER*0.5;
						// poison
						if(gPlayerData[i][pPoison] >= 30 && gPlayerData[i][pPoison] < 60)
							gPlayerData[i][pHunger] += HUNGER*0.05;
						else if(gPlayerData[i][pPoison] >= 60 && gPlayerData[i][pPoison] < 90)
							gPlayerData[i][pHunger] += HUNGER*0.05;
						else if(gPlayerData[i][pPoison] >= 90 && gPlayerData[i][pPoison] < 120)
							gPlayerData[i][pHunger] += HUNGER*0.1;
						else if(gPlayerData[i][pPoison] >= 120 && gPlayerData[i][pPoison] <= 150)
							gPlayerData[i][pHunger] += HUNGER*0.15;
						// vitamins
						if(gPlayerData[i][pVitamins] >= 0.0 && gPlayerData[i][pVitamins] < 50.0)
							gPlayerData[i][pHunger] += HUNGER*0.05;
						else if(gPlayerData[i][pVitamins] >= 120.0 && gPlayerData[i][pVitamins] <= 150.0)
							gPlayerData[i][pHunger] += HUNGER*0.05;
						// fat
						if(gPlayerData[i][pFat] >= 0.0 && gPlayerData[i][pFat] < 45.0)
							gPlayerData[i][pHunger] += HUNGER*0.1;
						else if(gPlayerData[i][pFat] >= 90.0 && gPlayerData[i][pFat] <= 150.0)
							gPlayerData[i][pHunger] += HUNGER*0.1;
						// default
						gPlayerData[i][pHunger] += HUNGER;
					}
					if(gPlayerData[i][pHunger] > MAX_HUNGER_VIP)
					{
						gPlayerData[i][pHunger] = MAX_HUNGER_VIP;
						SendClientMessage(i, COLOR_ORANGE, "[INFO:] Jesteœ bardzo g³odny !");
					}
					if(MAX_HUNGER_VIP-gPlayerData[i][pHunger] <= 20 && gPlayerData[i][pHunger] < MAX_HUNGER_VIP)
						SendClientMessage(i, COLOR_ORANGE, "[INFO:] Czujesz lekki g³ód");
				}
				else
				{
					if(gPlayerData[i][pHunger] < MAX_HUNGER)
					{
						// thirst
						if(gPlayerData[i][pThirst] == MAX_THIRST)
							gPlayerData[i][pHunger] += HUNGER*0.5;
						// poison
						if(gPlayerData[i][pPoison] >= 20 && gPlayerData[i][pPoison] < 40)
							gPlayerData[i][pHunger] += HUNGER*0.05;
						else if(gPlayerData[i][pPoison] >= 40 && gPlayerData[i][pPoison] < 60)
							gPlayerData[i][pHunger] += HUNGER*0.05;
						else if(gPlayerData[i][pPoison] >= 60 && gPlayerData[i][pPoison] < 80)
							gPlayerData[i][pHunger] += HUNGER*0.1;
						else if(gPlayerData[i][pPoison] >= 80 && gPlayerData[i][pPoison] <= 100)
							gPlayerData[i][pHunger] += HUNGER*0.15;
						// vitamins
						if(gPlayerData[i][pVitamins] >= 0.0 && gPlayerData[i][pVitamins] < 20.0)
							gPlayerData[i][pHunger] += HUNGER*0.05;
						else if(gPlayerData[i][pVitamins] >= 80.0 && gPlayerData[i][pVitamins] <= 100.0)
							gPlayerData[i][pHunger] += HUNGER*0.05;
						// fat
						if(gPlayerData[i][pFat] >= 0.0 && gPlayerData[i][pFat] < 30.0)
							gPlayerData[i][pHunger] += HUNGER*0.1;
						else if(gPlayerData[i][pFat] >= 60.0 && gPlayerData[i][pFat] <= 100.0)
							gPlayerData[i][pHunger] += HUNGER*0.1;
						// default
						gPlayerData[i][pHunger] += HUNGER;
					}
					if(gPlayerData[i][pHunger] > MAX_HUNGER)
					{
						gPlayerData[i][pHunger] = MAX_HUNGER;
						SendClientMessage(i, COLOR_ORANGE, "[INFO:] Jesteœ bardzo g³odny !");
					}
					if(MAX_HUNGER-gPlayerData[i][pHunger] <= 20 && gPlayerData[i][pHunger] < MAX_HUNGER)
						SendClientMessage(i, COLOR_ORANGE, "[INFO:] Czujesz lekki g³ód");
				}
				// Thirst
				if(IsPlayerVip(i))
				{
					if(gPlayerData[i][pThirst] < MAX_THIRST_VIP)
					{
						// hunger
						if(gPlayerData[i][pHunger] == MAX_HUNGER_VIP)
							gPlayerData[i][pThirst] += THIRST*0.5;
						// poison
						if(gPlayerData[i][pPoison] >= 30 && gPlayerData[i][pPoison] < 60)
							gPlayerData[i][pThirst] -= THIRST*0.05;
						else if(gPlayerData[i][pPoison] >= 60 && gPlayerData[i][pPoison] < 90)
							gPlayerData[i][pThirst] -= THIRST*0.05;
						else if(gPlayerData[i][pPoison] >= 90 && gPlayerData[i][pPoison] < 120)
							gPlayerData[i][pThirst] -= THIRST*0.1;
						else if(gPlayerData[i][pPoison] >= 120 && gPlayerData[i][pPoison] <= 150)
							gPlayerData[i][pThirst] -= THIRST*0.15;
						// vitamins
						if(gPlayerData[i][pVitamins] >= 0.0 && gPlayerData[i][pVitamins] < 30.0)
							gPlayerData[i][pThirst] -= THIRST*0.05;
						else if(gPlayerData[i][pVitamins] >= 120.0 && gPlayerData[i][pVitamins] <= 150.0)
							gPlayerData[i][pThirst] -= THIRST*0.05;
						// fat
						if(gPlayerData[i][pFat] >= 0.0 && gPlayerData[i][pFat] < 45.0)
							gPlayerData[i][pThirst] -= THIRST*0.1;
						else if(gPlayerData[i][pFat] >= 90.0 && gPlayerData[i][pFat] <= 150.0)
							gPlayerData[i][pThirst] -= THIRST*0.1;
						// default
						gPlayerData[i][pThirst] += THIRST;
					}
					if(gPlayerData[i][pThirst] > MAX_THIRST_VIP)
					{
						gPlayerData[i][pThirst] = MAX_THIRST_VIP;
						SendClientMessage(i, COLOR_ORANGE, "[INFO:] Jesteœ odwodniony !");
					}
					if(MAX_THIRST_VIP - gPlayerData[i][pThirst] <= 10 && gPlayerData[i][pThirst] < MAX_THIRST_VIP)
						SendClientMessage(i, COLOR_ORANGE, "[INFO:] Czujesz pragnienie");
					if(MAX_THIRST_VIP - gPlayerData[i][pThirst] <= 30 && MAX_THIRST_VIP - gPlayerData[i][pThirst] > 10)
						SendClientMessage(i, COLOR_ORANGE, "[INFO:] Czujesz lekkie pragnienie");
				}
				else
				{
					if(gPlayerData[i][pThirst] < MAX_THIRST)
					{
						// hunger
						if(gPlayerData[i][pHunger] == MAX_HUNGER)
							gPlayerData[i][pThirst] += THIRST*0.5;
						// poison
						if(gPlayerData[i][pPoison] >= 20 && gPlayerData[i][pPoison] < 40)
							gPlayerData[i][pThirst] -= THIRST*0.05;
						else if(gPlayerData[i][pPoison] >= 40 && gPlayerData[i][pPoison] < 60)
							gPlayerData[i][pThirst] -= THIRST*0.05;
						else if(gPlayerData[i][pPoison] >= 60 && gPlayerData[i][pPoison] < 80)
							gPlayerData[i][pThirst] -= THIRST*0.1;
						else if(gPlayerData[i][pPoison] >= 80 && gPlayerData[i][pPoison] <= 100)
							gPlayerData[i][pThirst] -= THIRST*0.15;
						// vitamins
						if(gPlayerData[i][pVitamins] >= 0.0 && gPlayerData[i][pVitamins] < 20.0)
							gPlayerData[i][pThirst] -= THIRST*0.05;
						else if(gPlayerData[i][pVitamins] >= 80.0 && gPlayerData[i][pVitamins] <= 100.0)
							gPlayerData[i][pThirst] -= THIRST*0.05;
						// fat
						if(gPlayerData[i][pFat] >= 0.0 && gPlayerData[i][pFat] < 30.0)
							gPlayerData[i][pThirst] -= THIRST*0.1;
						else if(gPlayerData[i][pFat] >= 60.0 && gPlayerData[i][pFat] <= 100.0)
							gPlayerData[i][pThirst] -= THIRST*0.1;
						// default
						gPlayerData[i][pThirst] += THIRST;
					}
					if(gPlayerData[i][pThirst] > MAX_THIRST)
					{
						gPlayerData[i][pThirst] = MAX_THIRST;
						SendClientMessage(i, COLOR_ORANGE, "[INFO:] Jesteœ odwodniony !");
					}
					if(MAX_THIRST - gPlayerData[i][pThirst] <= 10 && gPlayerData[i][pThirst] < MAX_THIRST)
						SendClientMessage(i, COLOR_ORANGE, "[INFO:] Czujesz pragnienie");
					if(MAX_THIRST - gPlayerData[i][pThirst] <= 30 && MAX_THIRST - gPlayerData[i][pThirst] > 10)
						SendClientMessage(i, COLOR_ORANGE, "[INFO:] Czujesz lekkie pragnienie");				
				}
				// Poison
				if(gPlayerVars[i][mAtHouseID] != -1)
				{
					if(strcmp(Houses[gPlayerVars[i][mAtHouseID]][Owner], gPlayerData[i][pName], false) == 0)
					{
						gPlayerData[i][pPoison] -= POISON;
						if(gPlayerData[i][pPoison] < 0)
							gPlayerData[i][pPoison] = 0;
					}
				}
				if(IsPlayerVip(i))
				{
					if(gPlayerData[i][pPoison] > 0.0 && gPlayerData[i][pPoison] < 60.0)
					{
						gPlayerData[i][pPoison] -= POISON;
						// TextDrawHideForPlayer(i, gTdPoison);
					}
					if(gPlayerData[i][pPoison] >= 60.0 && gPlayerData[i][pPoison] < 90.0)
					{
						if(random(15) == 3)
							SetPlayerDrunkLevelEx(i, 3980);	
						// TextDrawShowForPlayer(i, gTdPoison);
					}
					if(gPlayerData[i][pPoison] >= 90.0 && gPlayerData[i][pPoison] < 120.0)
					{
						if(random(10) == 3)
						{
							SetPlayerDrunkLevelEx(i, 5960);	
							defer PlayerWomit(i);
						}
						// TextDrawShowForPlayer(i, gTdPoison);
					}	
					if(gPlayerData[i][pPoison] >= 120.0)
					{
						if(random(5) == 3)
						{
							SetPlayerDrunkLevelEx(i, 12880);	
							defer PlayerWomit(i);
						}
						// TextDrawShowForPlayer(i, gTdPoison);
					}
				}
				else
				{
					if(gPlayerData[i][pPoison] > 0.0 && gPlayerData[i][pPoison] < 40.0)
					{
						gPlayerData[i][pPoison] -= POISON;
						// TextDrawHideForPlayer(i, gTdPoison);
					}
					if(gPlayerData[i][pPoison] >= 40.0 && gPlayerData[i][pPoison] < 60.0)
					{
						if(random(15) == 3)
							SetPlayerDrunkLevelEx(i, 3980);	
						// TextDrawShowForPlayer(i, gTdPoison);
					}
					if(gPlayerData[i][pPoison] >= 60.0 && gPlayerData[i][pPoison] < 80.0)
					{
						if(random(10) == 3)
						{
							SetPlayerDrunkLevelEx(i, 5960);	
							defer PlayerWomit(i);
						}
						// TextDrawShowForPlayer(i, gTdPoison);
					}	
					if(gPlayerData[i][pPoison] >= 80.0)
					{
						if(random(5) == 3)
						{
							SetPlayerDrunkLevelEx(i, 12880);	
							defer PlayerWomit(i);
						}
						// TextDrawShowForPlayer(i, gTdPoison);
					}
				}
				if(gPlayerData[i][pPoison] < 0.0)
				{
					gPlayerData[i][pPoison] = 0.0;
					// TextDrawHideForPlayer(i, gTdPoison);
				}
				// Fat
				if(gPlayerData[i][pFat] > 0.0)
					gPlayerData[i][pFat] -= FAT;
				if(gPlayerData[i][pFat] < 0.0)
					gPlayerData[i][pFat] = 0.0;				
				// Stomach
				if(gPlayerData[i][pStomach] > 0.0)
				{
					if(gPlayerData[i][pSlimming] > 0)
						gPlayerData[i][pStomach] -= STOMACH*1.0;
					gPlayerData[i][pStomach] -= STOMACH;
				}
				if(gPlayerData[i][pStomach] < 0.0)
					gPlayerData[i][pStomach] = 0.0;				
				// Vitamins
				if(gPlayerData[i][pVitamins] > 0.0)
				{
					if((IsPlayerVip(i) && gPlayerData[i][pPoison] >= MAX_POISON_VIP) || (!IsPlayerVip(i) && gPlayerData[i][pPoison] >= MAX_POISON))
						gPlayerData[i][pVitamins] -= 5.0;
					gPlayerData[i][pVitamins] -= VITAMINS;
				}
				if(gPlayerData[i][pVitamins] < 0.0)
					gPlayerData[i][pVitamins] = 0.0;				
				// Drunk
				if(IsPlayerVip(i))
				{
					if(gPlayerData[i][pDrunk] > 0.0)
					{
						if(gPlayerData[i][pDrunk] > 30.0 && gPlayerData[i][pDrunk] <= 60.0)
							SetPlayerDrunkLevelEx(i, 3980);	
						else if(gPlayerData[i][pDrunk] > 60.0 && gPlayerData[i][pDrunk] <= 90.0)
							SetPlayerDrunkLevelEx(i, 5960);	
						else if(gPlayerData[i][pDrunk] > 90.0 && gPlayerData[i][pDrunk] <= 150.0)
							SetPlayerDrunkLevelEx(i, 12880);
						gPlayerData[i][pDrunk] -= DRUNK;
					}
				}
				else
				{
					if(gPlayerData[i][pDrunk] > 0.0)
					{
						if(gPlayerData[i][pDrunk] > 20.0 && gPlayerData[i][pDrunk] <= 40.0)
							SetPlayerDrunkLevelEx(i, 3980);	
						else if(gPlayerData[i][pDrunk] > 40.0 && gPlayerData[i][pDrunk] <= 60.0)
							SetPlayerDrunkLevelEx(i, 5960);	
						else if(gPlayerData[i][pDrunk] > 60.0 && gPlayerData[i][pDrunk] <= 100.0)
							SetPlayerDrunkLevelEx(i, 12880);
						gPlayerData[i][pDrunk] -= DRUNK;
					}
				}
				if(gPlayerData[i][pDrunk] < 0.0)
					gPlayerData[i][pDrunk] = 0.0;				
				// Narcotic
				if(gPlayerData[i][pNarcotic] > 0.0)
				{
					if((gPlayerData[i][pNarcotic] >= 100.0 && !IsPlayerVip(i)) || (gPlayerData[i][pNarcotic] >= 150.0 && IsPlayerVip(i)))
						BW(i, 2500);
					gPlayerData[i][pNarcotic] -= NARCOTIC;
				}
				if(gPlayerData[i][pNarcotic] < 0.0)
					gPlayerData[i][pNarcotic] = 0.0;					
				
				SavePlayerData(i, "HealthStatus");
				format(string, sizeof(string), "%s\nEN: %f; HN: %f; TN: %f; PN: %f; FN: %f; SN: %f; VN: %f", string,
					gPlayerData[i][pEnergy], gPlayerData[i][pHunger], gPlayerData[i][pThirst], gPlayerData[i][pPoison],
					gPlayerData[i][pFat], gPlayerData[i][pStomach], gPlayerData[i][pVitamins]); 
				TextDrawSetString(EatText[i], string);
				if(gPlayerData[i][pShowHealthBars])
				{
					// SetProgressBarValue(gPlayerData[i][pEnergyProgressBarID], gPlayerData[i][pEnergy]);
					// UpdateProgressBar(gPlayerData[i][pEnergyProgressBarID], i);
					SetProgressBarValue(gPlayerData[i][pHungerProgressBarID], gPlayerData[i][pHunger]);
					UpdateProgressBar(gPlayerData[i][pHungerProgressBarID], i);
					SetProgressBarValue(gPlayerData[i][pThirstProgressBarID], gPlayerData[i][pThirst]);
					UpdateProgressBar(gPlayerData[i][pThirstProgressBarID], i);
					// SetProgressBarValue(gPlayerData[i][pPoisonProgressBarID], gPlayerData[i][pPoison]);
					// UpdateProgressBar(gPlayerData[i][pPoisonProgressBarID], i);
					// SetProgressBarValue(gPlayerData[i][pFatProgressBarID], gPlayerData[i][pFat]);
					// UpdateProgressBar(gPlayerData[i][pFatProgressBarID], i);
					SetProgressBarValue(gPlayerData[i][pStomachProgressBarID], gPlayerData[i][pStomach]);
					UpdateProgressBar(gPlayerData[i][pStomachProgressBarID], i);
					// SetProgressBarValue(gPlayerData[i][pVitaminsProgressBarID], gPlayerData[i][pVitamins]);
					// UpdateProgressBar(gPlayerData[i][pVitaminsProgressBarID], i);
					SetProgressBarValue(gPlayerData[i][pDrunkProgressBarID], gPlayerData[i][pDrunk]);
					UpdateProgressBar(gPlayerData[i][pDrunkProgressBarID], i);
					SetProgressBarValue(gPlayerData[i][pNarcoticProgressBarID], gPlayerData[i][pNarcotic]);
					UpdateProgressBar(gPlayerData[i][pNarcoticProgressBarID], i);
				}
				if(gPlayerData[i][pEnergy] == 0.0)
				{
					SendClientMessage(i, COLOR_LIGHTYELLOW2, "[INFO:] Jesteœ zmêczony, robi ci siê s³abo !");
					GetPlayerHealth(i, gPlayerData[i][pHP]);
					gPlayerData[i][pHP] -= 4.0;
					if(gPlayerData[i][pHP] < 0.0)
						gPlayerData[i][pHP] = 0.0;
					SetPlayerHealth(i, gPlayerData[i][pHP]);
					// save on exit
					if(LifeDecreaserTmpHP <= 30.0)
						SetPlayerDrunkLevelEx(i, 50000);
				}
				if(gPlayerData[i][pHP] < 30.0)
				{
					// TextDrawShowForPlayer(i, gTdLHealth);
					if(gAHeartBeat == -1)
						gAHeartBeat = Audio_Play(i, AUDIO_HEART_BEAT, false, true, false);
					if(gABreath == -1)
						gABreath = Audio_Play(i, AUDIO_BREATH, false, true, false);
					Audio_SetVolume(i, gAHeartBeat, 50);
					Audio_SetVolume(i, gABreath, 20);
				}
				else
				{
					// TextDrawHideForPlayer(i, gTdLHealth);
					Audio_Stop(i, gAHeartBeat);
					Audio_Stop(i, gABreath);
					gAHeartBeat = -1;
					gABreath = -1;
				}
			}

			/*
			* This part checks drug addict
			*/
			if(LastDrug[i] == 0 && gPlayerData[i][pJailed] == 0 && gPlayerData[i][pDrugsAddicted] == 1)
			{
				GetPlayerHealth(i, LifeDecreaserTmpHP);
				if(LifeDecreaserTmpHP <= 35.0)
				{
					SetPlayerDrunkLevelEx(i, 50000);
					SendClientMessage(i, COLOR_LIGHTYELLOW2, "[INFO:] Jesteœ na g³odzie narkotykowym. Strzel sobie strza³a !");
				}
				else
				{
					LifeDecreaserTmpHP -= 5.0;
					SendClientMessage(i, COLOR_LIGHTYELLOW2, "[INFO:] Czujesz g³ód narkotykowy. Strzel sobie strza³a !");
					SetPlayerHealth(i,LifeDecreaserTmpHP);
					gPlayerData[i][pHP] = LifeDecreaserTmpHP;
					// save on exit
				}
			}
			if(LastDrug[i] > 0)
				LastDrug[i]--;
		}
	}
	return 1;
}

task FiveMinTimer[300000]()
{
	#if defined DEBUG
		printf("[DEBUG:] FiveMinTimer");
	#endif
	
	GenerateTrashObjectsForSweeper();
	
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

task TenMinTimer[600000]()
{
	#if defined DEBUG
		printf("[DEBUG:] TenMinTimer");
	#endif
	
	static string[128], string2[128];
	
	strdel(string, 0, sizeof(string));
	strdel(string2, 0, sizeof(string2));
	
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
	
	// RepairVehicles and SaveCarsLocations
	for(new i = 0; i < sizeof(gVehData); i++)
	{
		if(!ReadyToSave)
		{
			ReadyToSave = 1;
			break;
		}
		GetVehiclePos(i+1, gVehData[i][mVehX], gVehData[i][mVehY], gVehData[i][mVehZ]);
		GetVehicleZAngle(i+1, gVehData[i][mVehA]);
		GetVehicleHealth(i+1, gVehData[i][CarHealth]);
		
		if(gVehData[i][CarRepairTimeLeft] > 0)
		{
			SaveVehData(i, "CarRepairTimeLeft");
		}
		
		SaveVehData(i, "VehPos");
		SaveVehData(i, "VehSave3");
	}
	
	CurrentInformationTmp = random(15);
	while(CurrentInformation  == CurrentInformationTmp)
	{
		CurrentInformationTmp = random(15);
	}
	CurrentInformation = CurrentInformationTmp;
	switch(CurrentInformation)
	{
		case 0:
		{
			format(string, sizeof(string), "[TIPS:] Numery publiczne: 999 - Pogotowie, 997 - Policja, 411 - HALO Taxi, 555 - Warsztat Samochodowy");
		}
		case 1:
		{
			format(string, sizeof(string), "[TIPS:] Nie wiesz o co chodzi ? Masz propozycje zmian ? WejdŸ na forum - WParty.pl");
		}
		case 2:
		{
			format(string, sizeof(string), "[TIPS:] Potrzebujesz pieniêdzy ? Zatrudnij sie do pracy wybieraj¹c z poœród wielu ofert !");
			format(string2, sizeof(string2), "[TIPS:] Czêœæ prac znajduje siê pod urzêdem, reszta rozmieszczona jest po ca³ym mieœcie.");
		}
		case 3:
		{
			format(string, sizeof(string), "[TIPS:] Widzisz cheatera lub gracza ³ami¹cego zasady gry ? Skorzystaj z komendy /donos");
			format(string2, sizeof(string2), "[TIPS:] lub napisz na GG");
		}
		case 4:
		{
			format(string, sizeof(string), "[TIPS:] Chcesz wyró¿niaæ siê poœród inny ? Udaj siê na do sklepu z ubraniami");
			format(string2, sizeof(string2), "[TIPS:] i wybierz jeden z modeli czapek czy te¿ okularów");
		}
		case 5:
		{
			format(string, sizeof(string), "[TIPS:] Do³¹cz do grupy WParty SA:MP na facebooku ju¿ dziœ !");
			format(string2, sizeof(string2), "[TIPS:] B¹dŸ na bie¿¹co z wydarzeniami na serwerze i komentuj je");
		}
		case 6:
		{
			format(string, sizeof(string), "[TIPS:] Zosta³o Ci ma³o ¿ycia ? Udaj siê do jednej z kilkudzisiêciu knajp/restauracji");
			format(string2, sizeof(string2), "[TIPS:] i u¿yj komendy /jedz ew. idŸ do baru i napij sie - /kupdrink");
		}
		case 7:
		{
			format(string, sizeof(string), "[TIPS:] Zadaj nam pytanie na GG !");
			format(string2, sizeof(string2), "[TIPS:] GG: 20677329");
		}
		case 8:
		{
			format(string, sizeof(string), "[TIPS:] Gdy jesteœ w pojeŸdzie skorzystaj z komendy /radios !");
			format(string2, sizeof(string2), "[TIPS:] Do wyboru masz kilka ró¿nych stacji (np. Radio ZET). ");
		}
		case 9:
		{
			format(string, sizeof(string), "[TIPS:] Czeste uzywanie /ja /do dodaje do gry urozmaicenie rozgrywki na WParty !");
			format(string2, sizeof(string2), "[TIPS:] Gra z dnia na dzien moze nas zadziwic uzywiajac akcji RP");
		}
		case 10:
		{
			format(string, sizeof(string), "[TIPS:] Stosujac mottto serwera : Zatrzymaj sie !!! : pomysl przed nastepna akcja czy jest ona Non RP czy RP");
			format(string2, sizeof(string2), "[TIPS:] W ten sposob uzyskasz 100 procent z frajdy z gry oraz zaufanie obecnych graczy");
		}
		case 11:
		{
			format(string, sizeof(string), "[TIPS:] Jeœli jesteœ pracownikiem s³u¿b publicznych zalecane jest posiadanie GPSu.");
			format(string2, sizeof(string2), "[TIPS:] Dziêki niemu du¿o ³atwiej odnajdziesz ludzi w potrzebie.");
		}
		case 12:
		{
			format(string, sizeof(string), "[TIPS:] Posiadanie GPSu oraz telefonu ulatwi Ci gre oraz sluzbom publicznym.");
			format(string2, sizeof(string2), "[TIPS:] GPS kupisz w kazdym 24/7 a Telefon w dowolnej sieci komorkowej.");
		}
		case 13:
		{
			format(string, sizeof(string), "[TIPS:] Jeœli posiadasz ju¿ pojazd mo¿esz go ubezpieczyæ.");
			format(string2, sizeof(string2), "[TIPS:] Umowe o ubezpieczenie OC/AC mo¿esz otrzymaæ od urzêdnika.");
		}
		case 14:
		{
			format(string, sizeof(string), "[TIPS:] Chcesz siê pozbyæ pojazdu ? Udaj siê na z³omowisko i wpisz /zezlomuj pojazd.");
			format(string2, sizeof(string), "[TIPS:] Pobrana zostanie odgórnie ustalona stawka za z³omowanie. Wiêcej informacji na forum.");
		}
	}
	
	foreach(Player, i )
	{
		if(gPlayerLogged[i])
		{
			/* Show tip info */
			if(gPlayerData[i][pTipsStatus])
			{
				SendClientMessage(i, COLOR_LIGHTORANGE, string);
				SendClientMessage(i, COLOR_LIGHTORANGE, string2);
			}
			
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
				GetPlayerPos(i, gPlayerData[i][pCrashX], gPlayerData[i][pCrashY], gPlayerData[i][pCrashZ]);
				if(gPlayerData[i][pCrashX] != 0.0 && gPlayerData[i][pCrashY] != 0.0)
				{
					gPlayerData[i][pCrashInt] = GetPlayerInterior(i);
					gPlayerData[i][pCrashW] = GetPlayerVirtualWorld(i);
					SavePlayerData(i, "Crash");
				}		
			}
			// EXP
			if(gPlayerData[i][pJailed] == 0)
			{
				if(gPlayerData[i][pDuty])
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
					// nxtlevel = gPlayerData[i][pLevel]+1;
					// expamount = nxtlevel * levelexp;
					gPlayerData[i][pPlayingHours]++;
					SetPlayerScore(i, gPlayerData[i][pPlayingHours]);
					// if(gPlayerData[i][pVipExp] == 1 || gPlayerData[i][pVipExpT] > 0)
						// gPlayerData[i][pExp] += 2;
					// if(gPlayerData[i][pVipExp] == 0 && gPlayerData[i][pVipExpT] == 0)
						// gPlayerData[i][pExp]++;
					// if(gPlayerData[i][pPlayingHours] == 50)
					// {
						// gPlayerData[i][pExp]++;
						// SendClientMessage(i,COLOR_LIGHTYELLOW2, "[INFO:] Otrzymujesz dodatkowy punkt doœwiadczenia za sta¿ w grze !");
					// }
					// if(gPlayerData[i][pPlayingHours] == 100)
					// {
						// gPlayerData[i][pExp]++;
						// SendClientMessage(i,COLOR_LIGHTYELLOW2, "[INFO:] Otrzymujesz dodatkowy punkt doœwiadczenia za sta¿ w grze !");
					// }
					// if(gPlayerData[i][pPlayingHours] == 500)
					// {
						// gPlayerData[i][pExp]++;
						// SendClientMessage(i,COLOR_LIGHTYELLOW2, "[INFO:] Otrzymujesz dodatkowy punkt doœwiadczenia za sta¿ w grze !");
					// }
					// if(gPlayerData[i][pPlayingHours] == 1000)
					// {
						// gPlayerData[i][pExp]++;
						// SendClientMessage(i,COLOR_LIGHTYELLOW2, "[INFO:] Otrzymujesz dodatkowy punkt doœwiadczenia za sta¿ w grze !");
					// }
					// if(gPlayerData[i][pExp] < expamount)
					// {
						// format(wstring, sizeof(wstring), "Twój poziom doœwiadczenia: %d/%d.", gPlayerData[i][pExp], expamount);
						// SendClientMessage(i,COLOR_LIGHTYELLOW2, wstring);
					// }
					// else
					// {
						// format(wstring, sizeof(wstring), "Nowy poziom! - %d.", nxtlevel);
						// SendClientMessage(i,COLOR_LIGHTYELLOW2, wstring);
						// gPlayerData[i][pLevel]++;
						// nxtlevel = gPlayerData[i][pLevel]+1;
						// gPlayerData[i][pExp] = 0;
						// expamount = nxtlevel * levelexp;
						// format(wstring, sizeof(wstring), "Do kolejnego potrzebujesz %d doœwiadczenia.", expamount);
						// SendClientMessage(i,COLOR_LIGHTYELLOW2, wstring);
					// }
					// SavePlayerData(i, "Exp");
					SavePlayerData(i, "JobTimeChange");
					// SavePlayerData(i, "Level");
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
	
	format(string, sizeof(string), "SELECT * FROM samp_factions ORDER BY `ID` ASC");
	mysql_query(string, RELOAD_DYNAMIC_FACTIONS, INVALID_PLAYER_ID, db_con2);

	format(string, sizeof(string), "SELECT * FROM samp_factions_weapons ORDER BY `FactionID` ASC");
	mysql_query(string, LOAD_DYNAMIC_FACTIONS_WEAPONS, INVALID_PLAYER_ID, db_con2);

	format(string, sizeof(string), "SELECT * FROM samp_factions_weapons2 ORDER BY `FactionID` ASC");
	mysql_query(string, LOAD_DYNAMIC_FACTIONS_WEAPONS2, INVALID_PLAYER_ID, db_con2);

	format(string, sizeof(string), "SELECT * FROM `samp_factions_payrank` ORDER BY `FactionID` ASC");
	mysql_query(string, LOAD_FACTIONS_PAYRANK, INVALID_PLAYER_ID, db_con2);
	
	return 1;
} // end of TenMinTimer

task OneHourTimer[3600000]()
{
	#if defined DEBUG
		printf("[DEBUG:] OneHourTimer");
	#endif
	// Gang territory earn
	for(new i = 0; i < sizeof(DynamicZones); i++)
	{
		if(DynamicZones[i][mFaction] != 255)
			DynamicFactions[DynamicZones[i][mFaction]][fBank] += 2;
	}
	
	for(new i = 0; i < sizeof(gVehData); i++)
	{
		if(!IsVehicleOccupied(i+1))
		{
			SetVehicleToPos(i+1, gVehData[i][mVehX], gVehData[i][mVehY], gVehData[i][mVehZ]);
			SetVehicleZAngle(i+1, gVehData[i][mVehA]);
		}
		SaveVehData(i, "VehSave1");
		SaveVehData(i, "VehSaveTune");
	}
	
	static Hour, Minute, Second;
	gettime(Hour, Minute, Second);

	if(Hour == 7)
		PayDay();
	
	return 1;
}