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
			{
				gPlayerData[i][pJobTimeChange]--;
			}
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
			{
				gHour = 0;	
			}
			else if(gHour == 21)
			{
				if(gLuckyLotteryLastLottery <= 2)
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
							format(string, sizeof(string), "Ju¿ dziœ odbêdzie siê losowanie w Szczêœliwej Loterii !\n Kumulacja wynosi ju¿ a¿ $%d !\n\nTy te¿ mo¿esz zostaæ milionerem !",
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
			else if(gHour == 20)
			{
				HorseRacePrepare(2);
			}
			
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
			if(gHour == 20)
			{
				foreach(Player, i)
				{
					if(gPlayerLogged[i])
					{
						continue;
					}
					
					if(gPlayerVars[i][mAtBuildingId] == 121)
					{
						SendClientMessage(i, COLOR_LIGHTYELLOW2, "[INFO:] Wyœcig rozpocznie siê za 30 minut !");
					}
				}
			}
		}
		else if(gMin == 10)
		{
			if(gHour == 20)
			{
				foreach(Player, i)
				{
					if(gPlayerVars[i][mAtBuildingId] == 121)
					{
						SendClientMessage(i, COLOR_LIGHTYELLOW2, "[INFO:] Zak³ady do kolejnego wyœcigu rozpoczête !");
					}
				}
			
				HorseRacePrepare(1);
			}
		}
	}
	
	format(string, sizeof(string), "%s%d:%s%d:%s%d", (gHour < 10) ? ("0") : (""), gHour, (gMin < 10) ? ("0") : (""), gMin, (gSec < 10) ? ("0") : (""), gSec);
	TextDrawSetString(gTextTime, string);
}

task halfSecTimer[500]()
{
	#if defined DEBUG2
		printf("[DEBUG:] HalfSecTimer");
	#endif

	static string[256], tfueltype[32], fuel[32], engineStatus[32], batteryStatus[32];
	static Float:hitDamage, Float:vehiclehp;
	static vehicle, tlID, lightsprm, alarm, doorsprm, bonnet, boot, objective;
	
	for(new i = 0; i < sizeof(gVehData); i++)
	{
		if(gVehData[i][mVehModel] == 594)
		{
			continue;
		}
		
		GetVehicleHealth(i+1, vehiclehp);
		hitDamage = gVehData[i][CarHealth] - vehiclehp;
		if((hitDamage) > 80.0 && gVehData[i][mVehType] == 0)
		{
			foreach(Player, j)
			{
				if(!IsPlayerInVehicle(j, i+1) || AdminDuty[j] || gPlayerVars[j][mJustEnteredVehicle])
				{
					continue;
				}
				
				GetPlayerHealth(j, gPlayerData[j][pHP]);
				
				if(gPlayerData[j][pSeatBelt])
				{
					gPlayerData[j][pHP] -= hitDamage/9;
					SetPlayerHealth(j, gPlayerData[j][pHP]);
				}
				else
				{
					gPlayerData[j][pHP] -= hitDamage/4;
					SetPlayerHealth(j, gPlayerData[j][pHP]);
				}
			}
		}
		
		if((hitDamage) > 130.0 && gVehData[i][EngineOn])
		{
			gVehData[i][EngineOn] = 0;
			if(RandomChance(30))
				gVehData[i][CarDamaged] = 1;
			SetVehicleParamsEx(i+1, 0, lightsprm, alarm, doorsprm, bonnet, boot, objective);
		}
		
		if(floatround(vehiclehp, floatround_round) <= 200 && floatround(vehiclehp, floatround_round) >= 100)
		{
			if(RandomChance(60)) // 60 procent szansy
			{
				SetVehicleHealth(i+1, 260.0);
				gVehData[i][EngineOn] = 0;
				gVehData[i][CarDamaged] = 1;
				SetVehicleParamsEx(i+1, 0, lightsprm, alarm, doorsprm, bonnet, boot, objective);
			}
		
		}
		if(gVehData[i][CarHealth] != vehiclehp)
		{
			gVehData[i][CarHealth] = vehiclehp;
		}
	}
	
	foreach(Player, i )
	{
		if(!gPlayerLogged[i])
		{
			continue;
		}
		
		gPlayerVars[i][mVehicleStatusShowChanged] = 0;
		
		if(ShowFuel[i] && (GetPlayerState(i) == PLAYER_STATE_DRIVER || (GetPlayerState(i) == PLAYER_STATE_PASSENGER && PHaveItemParam5Ex(i, 3, 18, gPlayerData[i][pName]) >= 0)))
		{
			format(string, sizeof(string), "_");
			if(gPlayerVars[i][mVehicleStatusShow] == 0)
			{
				TextDrawShowForPlayer(i, gPlayerVars[i][mVehicleStatus]);
				gPlayerVars[i][mVehicleStatusShow] = 1;
				gPlayerVars[i][mVehicleStatusShowChanged] = 1;
			}
			
			vehicle = GetPlayerVehicleID(i);
			tlID = GetVehicleTrailer(vehicle);
			
			if(gVehData[vehicle-1][mVehModel] != 509 && gVehData[vehicle-1][mVehModel] != 481 &&
				gVehData[vehicle-1][mVehModel] != 509 && gVehData[vehicle-1][mVehModel] != 510)
			{
				if(!IsABike(vehicle))
				{
					if( gVehData[vehicle-1][CarFuel] <= float(VehFTank(vehicle)) * 0.20 )
					{
						format(fuel, sizeof(fuel), "~r~! %dltr", floatround(gVehData[vehicle-1][CarFuel], floatround_round));
					}
					else
					{
						format(fuel, sizeof(fuel), "%dltr", floatround(gVehData[vehicle-1][CarFuel], floatround_round));
					}
					
					if(gVehData[vehicle-1][EngineOn] == 1)
					{
						format(engineStatus, sizeof(engineStatus), "uruchomiony");
					}
					else
					{
						format(engineStatus, sizeof(engineStatus), "wylaczony");
					}
					
					if(gVehData[vehicle-1][BatteryCapacity] >= floatround( gVehData[vehicle-1][BatteryMaxCapacity]/2, floatround_round ))
					{
						format(batteryStatus, sizeof(batteryStatus), "~g~bardzo dobry");
					}
					else if(gVehData[vehicle-1][BatteryCapacity] < floatround(gVehData[vehicle-1][BatteryMaxCapacity]/2, floatround_round) && 
						gVehData[vehicle-1][BatteryCapacity] > floatround(gVehData[vehicle-1][BatteryMaxCapacity]/4, floatround_round))
					{	
						format(batteryStatus, sizeof(batteryStatus), "~y~dobry");
					}
					else
					{
						format(batteryStatus, sizeof(batteryStatus), "~r~slaby");
					}
					
					if(!gVehData[vehicle-1][EngineOn])
					{
						format(string, sizeof(string), "~w~~r~Silnik: ~w~%s ~r~Paliwo:~w~ - ~r~Kilometry: ~w~%5.5d ~r~Predkosc: ~w~%d km/h ~r~Akumulator:~w~ -", 
							engineStatus, floatround(gVehData[vehicle-1][CarCounter]/1000, floatround_round), ASpeed(vehicle));
					}
					else
					{
						format(string, sizeof(string), "~w~~r~Silnik: ~w~%s ~r~Paliwo:~w~ %s ~r~Kilometry: ~w~%5.5d ~r~Predkosc: ~w~%d km/h ~r~Akumulator: %s", 
							engineStatus, fuel, floatround(gVehData[vehicle-1][CarCounter]/1000, floatround_round), ASpeed(vehicle), batteryStatus);
					}
					
					if(gVehData[vehicle-1][VCBRadio])
					{
						if(gVehData[vehicle-1][VCBRadioStatus])
						{
							format(string, sizeof(string), "%s ~r~CB:~w~ kanal %d", string, gVehData[vehicle-1][VCBRadioChanel]);
						}
						else
						{
							format(string, sizeof(string), "%s ~r~CB:~w~ wylaczone", string);
						}
					}
					
					if(IsATankerTrailer(tlID))
					{
						switch(gVehData[tlID-1][TankerResourceType])
						{
							case TANKER_TYPE_NONE: { format(tfueltype, sizeof(tfueltype), "brak"); }
							case TANKER_TYPE_PETROL: { format(tfueltype, sizeof(tfueltype), "benzyna"); }
							case TANKER_TYPE_OIL: { format(tfueltype, sizeof(tfueltype), "ropa"); }
							case TANKER_TYPE_GAS: { format(tfueltype, sizeof(tfueltype), "gas"); }
							case TANKER_TYPE_FLY: { format(tfueltype, sizeof(tfueltype), "lotnicze"); }
						}
						format(string, sizeof(string), "%s ~r~Typ paliwa w cysternie: ~w~%s ~r~Ilosc paliwa: ~w~%dltr", string, tfueltype, gVehData[tlID-1][TankerResourceValue]);
					}
				}
				TextDrawSetString(gPlayerVars[i][mVehicleStatus], string);
			}
		}
		else
		{
			if(gPlayerVars[i][mVehicleStatusShow])
			{
				TextDrawHideForPlayer(i, gPlayerVars[i][mVehicleStatus]);
				gPlayerVars[i][mVehicleStatusShow] = 0;
				gPlayerVars[i][mVehicleStatusShowChanged] = 1;
			}
		}
		
		RedrawSanNewsBox(i);
	}
	
	#if defined DEBUG2
		printf("[DEBUG:] HalfSecTimer - end");
	#endif
	
	return 1;
}

task OneSecTimer[1000]()
{
	#if defined DEBUG2
		printf("[DEBUG:] OneSecTimer");
	#endif
	
	static string[256], string2[128], j;
	
	strdel(string, 0, sizeof(string));
	strdel(string, 0, sizeof(string2));
	
	/**
	* Kicking vote cooldown
	*/
	if(gReportCooldown > 0)
	{
		gReportCooldown--;
	}
	
	if(gKickVoteTimeLeft > 0)
	{
		if(!IsPlayerConnected(gKickVotePlayerToKick))
		{
			gKickVoteTimeLeft = 0;
			gKickVotePlayerToKick = INVALID_PLAYER_ID;
			
			foreach(Player, i)
			{
				gKickVotePlayerVote[i] = 0;
			}
				
			SendClientMessageToAll(COLOR_ORANGE, "{DF013A}[WParty SERVER:]{FFFFFF} Gracz opuœci³ serwer, g³osowanie przerwane");
		}
		gKickVoteTimeLeft--;
		if(gKickVoteTimeLeft == 0)
		{
			new pCount = 0, positive = 0;
			
			foreach(Player, i)
			{
				if(!gPlayerLogged[i])
				{
					continue;
				}
				
				pCount++;
				
				if(gKickVotePlayerVote[i] == 1)
				{
					gKickVotePlayerVote[i] = 0;
					positive++;
				}
			}
			if(positive > floatround(pCount/2, floatround_round))
			{
				Kick(gKickVotePlayerToKick);
			}
			else
			{
				SendClientMessageToAll( COLOR_DARKRED, "{DF013A}[WParty SERVER:]{FFFFFF} Nie osi¹gniêto ponad 50%% g³osów za, gracz zostaje !" );
			}
			
			gKickVotePlayerToKick = INVALID_PLAYER_ID;			
		}
	}
	
	if(gEvent2timeToEnd > 0)
	{
		gEvent2timeToEnd--;
		
		if(gEvent2timeToEnd == 0)
		{
			EndEvent(2);
		}
		else
		{
			UpdateEventNote();
		}
	}

	// Horse race mechanism
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
				{
					continue;
				}
				
				if(gPlayerVars[i][mAtBuildingId] == 121)
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
				if(gPlayerVars[i][mAtBuildingId] == 121)
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
	
	// Event timers
	if(gEvent1timeToJoin > 0)
	{
		gEvent1timeToJoin--;
		if(gEvent1timeToJoin == 0)
		{
			StartEvent(1);
		}
		else
		{
			if(gEvent1timeToJoin > 60)
			{
				format(string, sizeof(string), "Poszukiwania rozpoczna sie za ~n~%d minut", floatround(gEvent1timeToStart/60));
			}
			else
			{
				format(string, sizeof(string), "Poszukiwania rozpoczna sie za mniej niz minute", floatround(gEvent1timeToStart/60));
			}
			
			for(new i = 0; i < sizeof(gEvent1players); i++)
			{
				if(gEvent1players[i] != -1)
				{
					GameTextForPlayer(gEvent1players[i], string, 2000, 6);
				}
			}
		}
	}
	
	// Event timers
	if(gEvent2timeToJoin > 0)
	{
		gEvent2timeToJoin--;
		if(gEvent2timeToJoin == 0)
		{
			StartEvent(2);
		}
		else
		{
			if(gEvent2timeToJoin > 60)
			{
				format(string, sizeof(string), "Event rozpoczyna sie za ~n~%d minut", floatround(gEvent2timeToStart/60));
			}
			else
			{
				format(string, sizeof(string), "Event rozpoczyna sie za mniej niz minute", floatround(gEvent2timeToStart/60));
			}
			
			for(new i = 0; i < sizeof(gEvent2players); i++)
			{
				if(gEvent2players[i] != -1)
				{
					GameTextForPlayer(gEvent2players[i], string, 2000, 6);
				}
			}
		}
	}
	
	if(gEvent1timeToStart > 0)
	{
		gEvent1timeToStart--;
		
		if(gEvent1timeToStart == 0)
		{
			BeginEvent(1);
		}
		else
		{
			format(string, sizeof(string), "Poszukiwania rozpoczna sie za ~n~%d sekund", gEvent1timeToStart);
			
			for(new i = 0; i < sizeof(gEvent1players); i++)
			{
				if(gEvent1players[i] != -1)
				{
					GameTextForPlayer(gEvent1players[i], string, 2000, 6);
				}
			}
		}
	}
	
	if(gEvent2timeToStart > 0)
	{
		gEvent2timeToStart--;
		
		if(gEvent2timeToStart == 0)
		{
			BeginEvent(2);
		}
		else
		{
			format(string, sizeof(string), "Muzyka zacznie grac za za ~n~%d sekund", gEvent2timeToStart);
			
			for(new i = 0; i < sizeof(gEvent2players); i++)
			{
				if(gEvent2players[i] != -1)
				{
					GameTextForPlayer(gEvent2players[i], string, 2000, 6);
				}
			}
		}
	}
	
	/**
	* Races mechanism
	*/
	for(j = 0; j < MAX_RACES; j++)
	{
		if(gRaceStatus[j][mRaceState] == RACE_STATE_JOINING)
		{
			if(gRaceStatus[j][mRaceTimeToStart])
				gRaceStatus[j][mRaceTimeToStart]--;
			if(!gRaceStatus[j][mRaceTimeToStart])
			{
				gettime(gRaceStatus[j][mRaceStartHour], gRaceStatus[j][mRaceStartMin], gRaceStatus[j][mRaceStartSec]);
				CheckRacersStartPos(j);
				PlayerRaceStartSound(j, 0);
				gRaceStatus[j][mRaceState] = RACE_STATE_RACE;
				format(string, sizeof(string), "START !", gRaceStatus[j][mRaceTimeToStart]);
				GameTextForRacers(j, "START !", 2000, 3);
				UnfreezeRacers(j);
				ResetRaceStandings(j);
				ShowFirstRaceCheckpoint(j);
			}
			else
			{
				if(gRaceStatus[j][mRaceTimeToStart] == 5)
				{
					CheckRacersStartPos(j);
					FreezeRacers(j);
					SetCameraAtStart(j, 1);
					PlayerRaceStartSound(j, 5);
					GameTextForRacers(j, "START WYSCIGU ZA: 5 SEKUND", 1500, 3);
				}
				if(gRaceStatus[j][mRaceTimeToStart] == 4)
				{
					SetCameraAtStart(j, 2);
					PlayerRaceStartSound(j, 4);
					GameTextForRacers(j, "START WYSCIGU ZA: 4 SEKUNDY", 1500, 3);
				}
				if(gRaceStatus[j][mRaceTimeToStart] == 3)
				{
					SetCameraAtStart(j, 3);
					PlayerRaceStartSound(j, 3);
					GameTextForRacers(j, "START WYSCIGU ZA: 3 SEKUNDY", 1500, 3);
				}
				if(gRaceStatus[j][mRaceTimeToStart] == 2)
				{
					SetCameraAtStart(j, 4);
					PlayerRaceStartSound(j, 2);
					GameTextForRacers(j, "START WYSCIGU ZA: 2 SEKUNDY", 1500, 3);
				}
				if(gRaceStatus[j][mRaceTimeToStart] == 1)
				{
					PlayerRaceStartSound(j, 1);
					SetCameraBehindRacers(j);
					GameTextForRacers(j, "START WYSCIGU ZA: 1 SEKUNDE", 1500, 3);
				}
				format(string, sizeof(string), "START WYSCIGU ZA: %d SEKUND", gRaceStatus[j][mRaceTimeToStart]);
			}
			TextDrawSetString(gRaceStatus[j][mRaceInfo], string);
		}
		if(gRaceStatus[j][mRaceState] == RACE_STATE_RACE || gRaceStatus[j][mRaceState] == RACE_STATE_COUNTDOWN)
		{
			if(!gRaceStatus[j][mRaceTimeToStart])
			{
				gRaceStatus[j][mRaceTimeToStart] = -1;
				if(gRaceStatus[j][mRaceLaps] > 1)
					format(string, sizeof(string), "Okrazenie 1/%d", gRaceStatus[j][mRaceLaps]);
				else
					format(string, sizeof(string), " ");
				TextDrawSetString(gRaceStatus[j][mRaceInfo], string);
			}
			if(!IsAnyPlayerInRace(j))
			{
				ResetRaceData(j);
				continue;
			}
			CheckRacersVehicles(j);
			CheckPlayerStandings(j);
			RefreshRaceStandings(j);
		}
	}
	
	#if defined DEBUG2
		printf("[DEBUG:] OneSecTimer - check vehicle damage status");
	#endif
	
	/**
	* Check vehicle damage status
	*/
	static Float:vehiclehp, enginedyn, lights, alarm, bonnet, boot, objective, doors, componentId, panels, tires, randomV;
	for(j = 0; j < sizeof(gVehData); j++)
	{
		// TODO: Make workaround for non normal type vehicles
		// probably normal variable will do...
		if(gVehData[j][mVehType] != 0)
		{
			continue;
		}
		
		if(gVehData[j][mVehType] == 0 && j < 1990)
		{
			GetVehiclePos(j+1, gVehData[j][mVehX], gVehData[j][mVehY], gVehData[j][mVehZ]);
			if((floatabs(VehNewPos[j][0] - gVehData[j][mVehX]) > 100.0 ||
				floatabs(VehNewPos[j][1] - gVehData[j][mVehY]) > 100.0 ||
				floatabs(VehNewPos[j][2] - gVehData[j][mVehZ]) > 100.0) && !VehJustRespawned[j] && gVehData[j][mVehType] != 3)
			{
				format(string, sizeof(string), "[ANTI-CHEAT:] Vehicle ID: %d traveled distance bigger than 100 (x: %.1f, y: %.1f, z: %.1f), could be non function Vehicle TP", j+1, floatabs(VehNewPos[j][0] - gVehData[j][mVehX]), floatabs(VehNewPos[j][1] - gVehData[j][mVehY]), floatabs(VehNewPos[j][2] - gVehData[j][mVehZ]));
				ABroadCast(COLOR_YELLOW, string, 1);
				SetVehicleToPos(j+1, VehNewPos[j][0], VehNewPos[j][1], VehNewPos[j][2]);
				gVehData[j][mVehX] = VehNewPos[j][0];
				gVehData[j][mVehY] = VehNewPos[j][1];
				gVehData[j][mVehZ] = VehNewPos[j][2];
				foreach(Player, i)
				{
					if(gPlayerLogged[i] && !gPlayerData[i][pAdmin])
					{
						if(PlayerToPoint(20.0, i, gVehData[j][mVehX], gVehData[j][mVehY], gVehData[j][mVehZ]))
						{
							SendClientMessage(i, COLOR_RED, "[ANTI-CHEAT:] Zosta³eœ wyrzucony za u¿ywanie cheatów !");
							format(string, sizeof(string), "[ANTI-CHEAT:] %s has been kicked for using Vehicle Teleport", gPlayerData[i][pName]);
							ABroadCast(COLOR_YELLOW, string, 1);
							Kick(i);
						}
					}
				}
			}
		}
		
		if(VehJustRespawned[j] > 0)
		{
			VehJustRespawned[j]--;
		}
		
		VehNewPos[j][0] = gVehData[j][mVehX];
		VehNewPos[j][1] = gVehData[j][mVehY];
		VehNewPos[j][2] = gVehData[j][mVehZ];
	
		if(gVehData[j][mVehModel] == 594)
			continue;
		
		GetVehicleHealth(j+1,vehiclehp);
		GetVehicleParamsEx(j+1, enginedyn, lights, alarm, doors, bonnet, boot, objective);
		
		if(enginedyn != gVehData[j][EngineOn])
		{
			SetVehicleParamsEx(j+1, gVehData[j][EngineOn], lights, alarm, doors, bonnet, boot, objective);
			printf("[WARNING:] Vehicle [%d] engine status differs from variable", j+1);
			format(string, sizeof(string), "Vehicle [%d] engine status differs from variable", j+1);
			ABroadCast(COLOR_YELLOW, string, 5);
			VehicleLog(string);
			ErrorLog(string);
		}
		
		if(vehiclehp > 100.0 && vehiclehp <= 250.0)
		{
			if(random(100) <= 50)
				continue;
			if(gVehData[j][CarDamaged] == 1)
				continue;
			SetVehicleHealth(j+1, 260.0);
			gVehData[j][CarDamaged] = 1;
			
			foreach(Player, n)
			{
				if(!gPlayerLogged[n])
					continue;
				if(GetPlayerVehicleID(n) != j+1 || GetPlayerState(n) != PLAYER_STATE_DRIVER)
					continue;

				if(gVehData[j][EngineOn])
				{
					SendClientMessage(n, COLOR_RED, "[INFO:] Pojazd uleg³ uszkodzeniu ! Nie mo¿esz jechaæ dalej.");
					SetVehicleParamsEx(j+1, 0, lights, alarm, doors, bonnet, boot, objective);
					gVehData[j][EngineOn] = 0;
					format(string, sizeof(string), "Vehicle [%d] has been damaged (undrivable) by %s", j+1, gPlayerData[n][pName]);
					VehicleLog(string);
					// Save in OneMinTimer();
				}
			}
		}
		else if (vehiclehp > 250.0 && vehiclehp <= 300.0)
		{
			SetVehicleHealth(j+1, 310.0);
			gVehData[j][CarDamaged] = 1;
			// Save in OneMinTimer();
			foreach(Player, n)
			{
				if(!gPlayerLogged[n])
					continue;
				if(GetPlayerVehicleID(n) != j+1 || GetPlayerState(n) != PLAYER_STATE_DRIVER)
					continue;

				if(gVehData[j][EngineOn] == 1)
				{
					SendClientMessage(n, COLOR_RED, "[INFO:] Pojazd uleg³ uszkodzeniu ! Nie mo¿esz jechaæ dalej.");
					SetVehicleParamsEx(j+1,0,lights,alarm,doors,bonnet,boot,objective);
					gVehData[j][EngineOn] = 0;
					format(string, sizeof(string), "Vehicle [%d] has been damaged (undrivable) by %s", j+1, gPlayerData[n][pName]);
					VehicleLog(string);
					// Save in OneMinTimer();
				}
			}
		}
		
		/*
		* AntiTune
		*/
		componentId = GetVehicleComponentInSlot(j+1, CARMODTYPE_SPOILER);
		if(componentId != gVehData[j][mVehSpoiler])
		{
			foreach(Player, i)
			{
				if(!gPlayerLogged[i] || gPlayerData[i][pAdmin] == 5)
					continue;
				if(IsPlayerInVehicle(i, j+1))
					BanPlayerAccount(i, "AntiTune Guard", "Generowanie czêœci tuningowych - spojler");
			}
			UnmodVehicle(j+1);
			continue;
		}
		componentId = GetVehicleComponentInSlot(j+1, CARMODTYPE_HOOD);
		if(componentId != gVehData[j][mVehHood])
		{
			foreach(Player, i)
			{
				if(!gPlayerLogged[i] || gPlayerData[i][pAdmin] == 5)
					continue;
				if(IsPlayerInVehicle(i, j+1))
					BanPlayerAccount(i, "AntiTune Guard", "Generowanie czêœci tuningowych - hood");
			}
			UnmodVehicle(j+1);
			continue;
		}
		componentId = GetVehicleComponentInSlot(j+1, CARMODTYPE_ROOF);
		if(componentId != gVehData[j][mVehRoof])
		{
			foreach(Player, i)
			{
				if(!gPlayerLogged[i] || gPlayerData[i][pAdmin] == 5)
					continue;
				if(IsPlayerInVehicle(i, i+1))
					BanPlayerAccount(i, "AntiTune Guard", "Generowanie czêœci tuningowych - roof");
			}
			UnmodVehicle(j+1);
			continue;
		}
		componentId = GetVehicleComponentInSlot(j+1, CARMODTYPE_SIDESKIRT);
		if(componentId != gVehData[j][mVehSideskirt])
		{
			foreach(Player, i)
			{
				if(!gPlayerLogged[i] || gPlayerData[i][pAdmin] == 5)
					continue;
				if(IsPlayerInVehicle(i, j+1))
					BanPlayerAccount(i, "AntiTune Guard", "Generowanie czêœci tuningowych - side skirt");
			}
			UnmodVehicle(j+1);
			continue;
		}
		componentId = GetVehicleComponentInSlot(j+1, CARMODTYPE_LAMPS);
		if(componentId != gVehData[j][mVehLamps])
		{
			foreach(Player, i)
			{
				if(!gPlayerLogged[i] || gPlayerData[i][pAdmin] == 5)
					continue;
				if(IsPlayerInVehicle(i, j+1))
					BanPlayerAccount(i, "AntiTune Guard", "Generowanie czêœci tuningowych - lamps");
			}
			UnmodVehicle(j+1);
			continue;
		}
		componentId = GetVehicleComponentInSlot(j+1, CARMODTYPE_NITRO);
		if(componentId != gVehData[j][mVehNitro])
		{
			foreach(Player, i)
			{
				if(!gPlayerLogged[i] || gPlayerData[i][pAdmin] == 5)
					continue;
				if(IsPlayerInVehicle(i, j+1))
					BanPlayerAccount(i, "AntiTune Guard", "Generowanie czêœci tuningowych - nitro");
			}
			UnmodVehicle(j+1);
			continue;
		}
		componentId = GetVehicleComponentInSlot(j+1, CARMODTYPE_EXHAUST);
		if(componentId != gVehData[j][mVehExhaust])
		{
			foreach(Player, i)
			{
				if(!gPlayerLogged[i] || gPlayerData[i][pAdmin] == 5)
					continue;
				if(IsPlayerInVehicle(i, j+1))
					BanPlayerAccount(i, "AntiTune Guard", "Generowanie czêœci tuningowych - exhaust");
			}
			UnmodVehicle(j+1);
			continue;
		}
		componentId = GetVehicleComponentInSlot(j+1, CARMODTYPE_WHEELS);
		if(componentId != gVehData[j][mVehWheels])
		{
			foreach(Player, i)
			{
				if(!gPlayerLogged[i] || gPlayerData[i][pAdmin] == 5)
					continue;
				if(IsPlayerInVehicle(i, j+1))
					BanPlayerAccount(i, "AntiTune Guard", "Generowanie czêœci tuningowych - wheels");
			}
			UnmodVehicle(j+1);
			continue;
		}
		componentId = GetVehicleComponentInSlot(j+1, CARMODTYPE_STEREO);
		if(componentId != gVehData[j][mVehStereo])
		{
			foreach(Player, i)
			{
				if(!gPlayerLogged[i] || gPlayerData[i][pAdmin] == 5)
					continue;
				if(IsPlayerInVehicle(i, j+1))
					BanPlayerAccount(i, "AntiTune Guard", "Generowanie czêœci tuningowych - stereo");
			}
			UnmodVehicle(j+1);
			continue;
		}
		componentId = GetVehicleComponentInSlot(j+1, CARMODTYPE_HYDRAULICS);
		if(componentId != gVehData[j][mVehHydraulics])
		{
			foreach(Player, i)
			{
				if(!gPlayerLogged[i] || gPlayerData[i][pAdmin] == 5)
					continue;
				if(IsPlayerInVehicle(i, j+1))
					BanPlayerAccount(i, "AntiTune Guard", "Generowanie czêœci tuningowych - hydraulics");
			}
			UnmodVehicle(j+1);
			continue;
		}
		componentId = GetVehicleComponentInSlot(j+1, CARMODTYPE_FRONT_BUMPER);
		if(componentId != gVehData[j][mVehFrontBumper])
		{
			foreach(Player, i)
			{
				if(!gPlayerLogged[i] || gPlayerData[i][pAdmin] == 5)
					continue;
				if(IsPlayerInVehicle(i, j+1))
					BanPlayerAccount(i, "AntiTune Guard", "Generowanie czêœci tuningowych - front bumper");
			}
			UnmodVehicle(j+1);
			continue;
		}
		componentId = GetVehicleComponentInSlot(j+1, CARMODTYPE_REAR_BUMPER);
		if(componentId != gVehData[j][mVehRearBumper])
		{
			foreach(Player, i)
			{
				if(!gPlayerLogged[i] || gPlayerData[i][pAdmin] == 5)
					continue;
				if(IsPlayerInVehicle(i, j+1))
					BanPlayerAccount(i, "AntiTune Guard", "Generowanie czêœci tuningowych - rear bumper");
			}
			UnmodVehicle(j+1);
			continue;
		}
		/*componentId = GetVehicleComponentInSlot(j+1, CARMODTYPE_VENT_RIGHT);
		if(componentId != gVehData[j][mVehVentRight])
		{
			foreach(Player, i)
			{
				if(!gPlayerLogged[i] || gPlayerData[i][pAdmin] == 5)
					continue;
				if(IsPlayerInVehicle(i, j+1))
					BanPlayerAccount(i, "AntiTune Guard", "Generowanie czêœci tuningowych");
			}
			UnmodVehicle(j+1);
			continue;
		}*/
		/*componentId = GetVehicleComponentInSlot(j+1, CARMODTYPE_VENT_LEFT);
		if(componentId != gVehData[j][mVehVentLeft])
		{
			foreach(Player, i)
			{
				if(!gPlayerLogged[i] || gPlayerData[i][pAdmin] == 5)
					continue;
				if(IsPlayerInVehicle(i, j+1))
					BanPlayerAccount(i, "AntiTune Guard", "Generowanie czêœci tuningowych");
			}
			UnmodVehicle(j+1);
			continue;
		}*/
	}

	
	#if defined DEBUG2
		printf("[DEBUG:] OneSecTimer - check if player is in burning factory");
	#endif
	
	/*
	* Check if player is in burning factory
	* Take player HP if TRUE
	*/
	for(j = 5; j < sizeof(DynamicFactions); j++ )
	{
		if(DynamicFactions[j][fType] == 3 && DynamicFactions[j][WFactoryBurning])
		{
			foreach(Player, i )
			{
				if(!gPlayerLogged[i])
				{
					continue;
				}
				
				if(PlayerToPoint(10.0, i, DynamicFactions[j][WFactoryCentrePosX], DynamicFactions[j][WFactoryCentrePosY], DynamicFactions[j][WFactoryCentrePosZ]))
				{
					gPlayerData[i][pHP] -= 2.0;
					SetPlayerHealth(i, gPlayerData[i][pHP]);
				}
			}
		}
	}

	#if defined DEBUG2
		printf("[DEBUG:] OneSecTimer - other related to player stuff");
	#endif
	
	/*
	* Other related to player stuff
	*/
	static location[MAX_ZONE_NAME];
	static Float: posX, Float: posY, Float: posZ, Float: posA, Float: dist, weapon, ammo, ping, vehicleID, hack;
	static tmpslot[MAX_PLAYER_ITEM_SLOT], haveGPS, isGPSOn;
	foreach(Player, i)
	{
		if(!gPlayerLogged[i] || !Alive[i])
		{
			continue;
		}
		
		if(gPlayerVars[i][mTaxiTeleportTimeLeft] > 0)
		{
			format(string, sizeof(string), "~w~W TRASIE~n~dojedziesz za~n~%d sek.", gPlayerVars[i][mTaxiTeleportTimeLeft]);
			GameTextForPlayer(i, string, 1500, 3);
			
			gPlayerVars[i][mTaxiTeleportTimeLeft]--;
			if(gPlayerVars[i][mTaxiTeleportTimeLeft] == 0)
			{
				TaxiTpPlayer(i);
			}
		}
		
		if(gPlayerVars[i][mNewbieCoolDown])
		{
			gPlayerVars[i][mNewbieCoolDown]--;
		}
		
		if(gPlayerVars[i][mBugInfoCoolDown])
		{
			gPlayerVars[i][mBugInfoCoolDown]--;
		}
		
		if(gKickVoteStartCooldown[i] > 0)
		{
			gKickVoteStartCooldown[i]--;
		}
		
		if(gVehPosCheckCooldown[i] > 0)
		{
			gVehPosCheckCooldown[i]--;
		}
		
		if(gAddCooldown[i] > 0)
		{
			gAddCooldown[i]--;
		}
		
		if(gTGunIDLastCD[i] > 0)
		{
			gTGunIDLastCD[i]--;
		}
		else
		{
			gTGunIDLast[i] = 0;
		}
		
		if(gJustDropped[i] > 0)
		{
			gJustDropped[i]--;
		}
		
		if(gTryCoolDown[i] > 0)
		{
			gTryCoolDown[i]--;
		}
		
		if(gTransferCoolDown[i] > 0)
		{
			gTransferCoolDown[i]--;
		}
		
		if(gPlayerVars[i][mSprinting] > 0)
		{
			gPlayerVars[i][mSprinting]--;
		}
		
		if(gPlayerVars[i][mJustEnteredVehicle] > 0)
		{
			gPlayerVars[i][mJustEnteredVehicle]--;
		}
		
		if(gPlayerVars[i][mIsReanimate] > 0)	
		{
			gPlayerVars[i][mIsReanimate]--;
		}
		
		if(gPlayerVars[i][mRepairProgress])
		{
			gPlayerVars[i][mRepairProgress]--;

			if(gPlayerVars[i][mRepairProgress] > 0)
			{
				format(string, sizeof(string), "~y~W TRAKCIE PRAC~n~POZOSTALO %d SEK", gPlayerVars[i][mRepairProgress]);
			
				GameTextForPlayer(i, string, 1500, 3);
				if(gPlayerVars[i][mRepairProgress]%2 == 0 && random(2) == 0)
				{
					PlayerPlaySound(i, 1133, 0.0, 0.0, 0.0);
				}
			}
			
			if(gPlayerVars[i][mRepairProgress] == 0)
			{
				PlayerPlaySound(i, 1133, 0.0, 0.0, 0.0);
				if(gPlayerVars[i][mRepairingItemType] == 1)
				{
					switch(gPlayerVars[i][mRepairingItemId])
					{
						//¿arówka
						case 7:
						{
							vehicleID = GetClosestVehicle(i);
					
							if(vehicleID != INVALID_VEHICLE_ID)
							{
								GetVehicleDamageStatus(vehicleID, panels, doors, lights, tires);
								if(gPlayerVars[i][mBulbToChange] == 0)
								{
									UpdateVehicleDamageStatus(vehicleID, panels, doors, lights & 0b1011, tires);
								}
								else if(gPlayerVars[i][mBulbToChange] == 1)
								{
									UpdateVehicleDamageStatus(vehicleID, panels, doors, lights & 0b1110, tires);
								}
								else if(gPlayerVars[i][mBulbToChange] == 2)
								{						
									UpdateVehicleDamageStatus(vehicleID, panels, doors, lights & 0b0111, tires);
								}
								else if(gPlayerVars[i][mBulbToChange] == 3)
								{
									UpdateVehicleDamageStatus(vehicleID, panels, doors, lights & 0b1101, tires);
								}
								ClearAnimationsEx(i);					
								ShowPlayerDialog(i, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Wymiana zosta³a zakoñczona pomyœlnie", "Zamknij", "");
							}
						}
						// hak
						case 10:
						{
							vehicleID = GetClosestVehicle(i);
					
							if(vehicleID != INVALID_VEHICLE_ID)
							{
								gVehData[vehicleID-1][Hook] = 1;
								SaveVehData(vehicleID-1, "Hook");
								
								ClearAnimationsEx(i);					
								ShowPlayerDialog(i, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Hak zosta³ zamontowany.", "Zamknij", "");
							}
						}
						// œwiat³o policyjne (listwa)
						case 152:
						{
							vehicleID = GetClosestVehicle(i);
							
							if(vehicleID != INVALID_VEHICLE_ID)
							{
								MountSirenToVehicle(vehicleID-1);
								ShowPlayerDialog(i, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Monta¿ zosta³ zakoñczony pomyœlnie.", "Zamknij", "");
							}
						}
						// œwiat³o policyjne (pojedyncze)
						case 153:
						{
							vehicleID = GetClosestVehicle(i);
							
							if(vehicleID != INVALID_VEHICLE_ID)
							{
								MountSirenToVehicle(vehicleID-1);
								ShowPlayerDialog(i, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Monta¿ zosta³ zakoñczony pomyœlnie.", "Zamknij", "");
							}
						}
						// lista TAXI 1
						case 154:
						{
							vehicleID = GetClosestVehicle(i);
					
							if(vehicleID != INVALID_VEHICLE_ID)
							{
								AttachObjectToVehicleSlot(vehicleID, 19308);
								
								ClearAnimationsEx(i);
								
								ShowPlayerDialog(i, DIALOG_ITEM_3, DIALOG_STYLE_MSGBOX, "Informacja", "Zamontowa³eœ liste TAXI", "Wróæ", "");
							}
						}
						// lista TAXI 2
						case 155:
						{
							vehicleID = GetClosestVehicle(i);
					
							if(vehicleID != INVALID_VEHICLE_ID)
							{
								AttachObjectToVehicleSlot(vehicleID, 19309);
								
								ClearAnimationsEx(i);
								
								ShowPlayerDialog(i, DIALOG_ITEM_3, DIALOG_STYLE_MSGBOX, "Informacja", "Zamontowa³eœ liste TAXI", "Wróæ", "");
							}
						}
						// lista TAXI 3
						case 156:
						{
							vehicleID = GetClosestVehicle(i);
					
							if(vehicleID != INVALID_VEHICLE_ID)
							{
								AttachObjectToVehicleSlot(vehicleID, 19310);
								
								ClearAnimationsEx(i);
								
								ShowPlayerDialog(i, DIALOG_ITEM_3, DIALOG_STYLE_MSGBOX, "Informacja", "Zamontowa³eœ liste TAXI", "Wróæ", "");
							}
						}
						// lista TAXI 4
						case 157:
						{
							vehicleID = GetClosestVehicle(i);
					
							if(vehicleID != INVALID_VEHICLE_ID)
							{
								AttachObjectToVehicleSlot(vehicleID, 19311);
								
								ClearAnimationsEx(i);
								
								ShowPlayerDialog(i, DIALOG_ITEM_3, DIALOG_STYLE_MSGBOX, "Informacja", "Zamontowa³eœ liste TAXI", "Wróæ", "");
							}
						}
						// czêœci silnika
						case 175:
						{
							vehicleID = GetClosestVehicle(i);
							
							if(vehicleID != INVALID_VEHICLE_ID)
							{
								gVehData[vehicleID-1][CarDamaged] = 0;
								gVehData[vehicleID-1][CarHealth] = MaxVehicleHealth(vehicleID);
								
								SaveVehData(vehicleID-1, "CarDamaged");
								SaveVehData(vehicleID-1, "CarHealth");
								
								SetVehicleHealth(vehicleID, gVehData[vehicleID-1][CarHealth]);
								
								ApplyAnimation(i, "CAR", "Fixn_Car_Out", 4.1, 1, 0, 0, 1, 0, 1);
								
								defer ClearAnimationsEx(i);
								
								ShowPlayerDialog(i, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Napraw zosta³a zakoñczona pomyœlnie.", "Zamknij", "");
							}
						}
						// opona
						case 176:
						{
							vehicleID = GetClosestVehicle(i);
					
							if(vehicleID != INVALID_VEHICLE_ID)
							{
								GetVehicleDamageStatus(vehicleID, panels, doors, lights, tires);
								if(gPlayerVars[i][mWheelToChange] == 0)
								{
									UpdateVehicleDamageStatus(vehicleID, panels, doors, lights, tires & 0b0111);
								}
								else if(gPlayerVars[i][mWheelToChange] == 1)
								{
									UpdateVehicleDamageStatus(vehicleID, panels, doors, lights, tires & 0b1101);
								}
								else if(gPlayerVars[i][mWheelToChange] == 2)
								{
									UpdateVehicleDamageStatus(vehicleID, panels, doors, lights, tires & 0b1011);
								}
								else if(gPlayerVars[i][mWheelToChange] == 3)
								{
									UpdateVehicleDamageStatus(vehicleID, panels, doors, lights, tires & 0b1110);
								}
								
								ClearAnimationsEx(i);					
								ShowPlayerDialog(i, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Napraw zosta³a zakoñczona pomyœlnie.", "Zamknij", "");
							}
						}
						// instalacja gazowa
						case 177:
						{
							vehicleID = GetClosestVehicle(i);
					
							if(vehicleID != INVALID_VEHICLE_ID)
							{
								gVehData[vehicleID-1][Fuel] = 2;
								gVehData[vehicleID-1][CarFuel] = 10.0;
								SaveVehData(vehicleID-1, "Fuel");
								SaveVehData(vehicleID-1, "CarFuel");
								
								ClearAnimationsEx(i);					
								ShowPlayerDialog(i, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Instalacja gazowa zosta³a zamontowana.", "Zamknij", "");
							}
						}
					}
				}
				else if(gPlayerVars[i][mRepairingItemType] == 8)
				{
					vehicleID = GetClosestVehicle(i);
					
					if(!MountVehicleItem(ShowSlotItem(i, gSelectedSlot[i]), vehicleID-1))
					{
						ShowPlayerDialog(i, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Niestety nie uda³o siê dopasowaæ tej czêœci do tego pojazdu.", "Zamknij", "");
					}
					else
					{
						RemovePlayerItemExUsed(i, gSelectedSlot[i]);
						
						SaveVehData(vehicleID-1, "VehSaveTune");
						
						PlayerPlaySound(i, 1133, 0.0, 0.0, 0.0);
						
						ShowPlayerDialog(i, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Zamontowa³eœ element.", "Zamknij", "");
					}
				}
				else if(gPlayerVars[i][mRepairingItemType] == 9)
				{
					vehicleID = GetClosestVehicle(i);
					
					if(!MountVehicleStockItem(ShowSlotItem(i, gSelectedSlot[i]), vehicleID-1))
					{
						ShowPlayerDialog(i, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Niestety nie uda³o siê dopasowaæ tej czêœci do tego pojazdu.", "Zamknij", "");
					}
					else
					{
						RemovePlayerItemExUsed(i, gSelectedSlot[i]);
						
						PlayerPlaySound(i, 1133, 0.0, 0.0, 0.0);
						
						ShowPlayerDialog(i, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Zamontowa³eœ element.", "Zamknij", "");
					}
				}
				else if(gPlayerVars[i][mRepairingItemType] == 9)
				{
					vehicleID = GetClosestVehicle(i);
				}
				ClearAnimationsEx(i);
			}
		}
		
		if(gPlayerVars[i][mBusTicketBuyTime] > 0)
		{
			gPlayerVars[i][mBusTicketBuyTime]--;
			if(gPlayerVars[i][mBusTicketBuyTime] == 0)
			{
				ShowPlayerDialog(i, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Kupno biletu", "Nie kupi³eœ biletu.\nNie mo¿esz kontynuuowaæ jazdy.", "Zamknij", "");
				RemovePlayerFromVehicle(i);
				TogglePlayerControllable(i, 0);
				defer UnfreezePlayer[3000](i);
			}
		}
		
		if(gPlayerVars[i][mJumped] > 0 && !gIsAntiBH)
		{
			if(gPlayerVars[i][mJumped] > 3 && gPlayerData[i][pAdmin] == 0)
			{
				SendClientMessage(i, COLOR_RED, "[INFO:] BH jest zabronione !");
				SendClientMessage(i, COLOR_RED, "[INFO:] Aby wstaæ wpisz /wstan");
				format(string, sizeof(string), "[INFO:] Gracz %s [%d] u¿ywa BH", gPlayerData[i][pName], i);
				ABroadCast(COLOR_YELLOW, string, 1);
				ApplyAnimation(i,"PED","FLOOR_hit_f",4.0,0,1,1,1,0);
				gPlayerVars[i][mJumped] = 2;
			}
			else
			{
				gPlayerVars[i][mJumped]--;
			}
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
			GameTextForPlayer(i, string, 1500, 3);
			gPlayerData[i][pCharacterDying]--;
			SavePlayerData(i, "CharacterDying");
		}
		
		if(gPlayerVars[i][mRobbingHouseStage] > 0)
		{
			if(gPlayerVars[i][mAtHouseID] == -1)
			{
				gPlayerVars[i][mRobbingHouseStage] = 0;
				format(string, sizeof(string), "ucieka z miejsca kradzie¿y");
				PlayerActionMessage(i, AR_HOUSE_STEALING, string);
			}
			else
			{
				gPlayerVars[i][mRobbingHouseStage]++;
				if(gPlayerVars[i][mRobbingHouseStage]%5 == 0 && gPlayerVars[i][mRobbingHouseStage] != 60)
				{
					format(string, sizeof(string), "okrada dom (pozosta³o %d sek.)", 60-gPlayerVars[i][mRobbingHouseStage]);
					PlayerActionMessage(i, AR_HOUSE_STEALING, string);
				}
				else if(gPlayerVars[i][mRobbingHouseStage] == 60)
				{
					gPlayerVars[i][mRobbingHouseStage] = 0;
					HouseInZoneStealTimeLeftSave(i);
					
					format(string, sizeof(string), "Zabra³eœ $%d ze schowka", floatround(Houses[gPlayerVars[i][mAtHouseID]][Money]*0.3));
					
					GivePlayerCash(i, floatround(Houses[gPlayerVars[i][mAtHouseID]][Money]*0.3));
					
					Houses[gPlayerVars[i][mAtHouseID]][Money] -= floatround(Houses[gPlayerVars[i][mAtHouseID]][Money]*0.3);
					SaveHouseData(gPlayerVars[i][mAtHouseID], "Money");
					
					ShowPlayerDialog(i, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", string, "Zamknij", "");
				}
			}
		}
		
		if(gPlayerVars[i][mRobbingBusinessStage] > 0)
		{
			if(gPlayerVars[i][mAtBizID] == -1)
			{
				gPlayerVars[i][mRobbingBusinessStage] = 0;
				format(string, sizeof(string), "ucieka z miejsca kradzie¿y");
				PlayerActionMessage(i, AR_BUSINESS_STEALING, string);
			}
			else
			{
				gPlayerVars[i][mRobbingBusinessStage]++;
				if(gPlayerVars[i][mRobbingBusinessStage]%5 == 0 && gPlayerVars[i][mRobbingBusinessStage] != 60)
				{
					format(string, sizeof(string), "okrada biznes (pozosta³o %d sek.)", 60-gPlayerVars[i][mRobbingBusinessStage]);
					PlayerActionMessage(i, AR_BUSINESS_STEALING, string);
				}
				else if(gPlayerVars[i][mRobbingBusinessStage] == 60)
				{
					gPlayerVars[i][mRobbingBusinessStage] = 0;
					BizInZoneStealTimeLeftSave(i);
					
					format(string, sizeof(string), "Zabra³eœ $%d z kasy", floatround(Businesses[gPlayerVars[i][mAtBizID]][Till]*0.3));
					
					GivePlayerCash(i, floatround(Businesses[gPlayerVars[i][mAtBizID]][Till]*0.3));
					
					Businesses[gPlayerVars[i][mAtBizID]][Till] -= floatround(Businesses[gPlayerVars[i][mAtBizID]][Till]*0.3);
					SaveBizData(gPlayerVars[i][mAtBizID], "Till");
					
					ShowPlayerDialog(i, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", string, "Zamknij", "");
				}
			}
		}		
		
		// Return player to life instead of killing...
		else if(gPlayerData[i][pCharacterDying] == 1)
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
			SendClientMessage(i, COLOR_GREEN, "[INFO:] Odzyska³eœ przytomnoœæ lecz nie pamiêtasz nic z obecnego dnia !");
		}
		
		for(new k = 0; k < sizeof(Houses); k++)
		{
			if(gLastHVisit[i][k] > 0)
			{
				gLastHVisit[i][k]--;
			}
		}	
		
		for(new k = 0; k < sizeof(Businesses); k++)
		{
			if(gLastBVisit[i][k] > 0)
			{
				gLastBVisit[i][k]--;
			}
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
				format(string, sizeof(string), "[WARNING:] %s (ID:%d) tried to spawn $%d - This could be a money cheat.",gPlayerData[i][pName],i, hack);
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
				format(string2, sizeof(string2), "~r~Lokacja: ~w~brak modulu GPS");
			else if(haveGPS)
			{
				if(!isGPSOn) { format(string2, sizeof(string2), "~r~Lokacja: ~w~modul GPS wylaczony"); }
				if(isGPSOn) { format(string2, sizeof(string2), "~r~Lokacja: ~w~%s", location); }
			}
			if(gSpectateID[i] != INVALID_PLAYER_ID && GetPlayerState(i) == PLAYER_STATE_SPECTATING)
			{
				GetPlayer2DZone(gSpectateID[i], location, MAX_ZONE_NAME);
				if(gPlayerData[gSpectateID[i]][pFaction] != 255)
					format(string, sizeof(string), "~r~Przegranych godzin: ~w~%d ~r~Frakcja: ~w~%s %s", gPlayerData[gSpectateID[i]][pPlayingHours], DynamicFactions[gPlayerData[gSpectateID[i]][pFaction2]][Name], string2);
				else
					format(string, sizeof(string), "~r~Przegranych godzin: ~w~%d ~r~Doswiadczenie: ~w~%d/%d ~r~Frakcja: ~w~Brak %s", gPlayerData[gSpectateID[i]][pPlayingHours], string2);
				if(gPlayerData[gSpectateID[i]][pFaction2] != 255)
					format(string, sizeof(string), "%s~r~Firma: ~w~%s", string, DynamicFactions[gPlayerData[gSpectateID[i]][pFaction2]][Name]);
				else
					format(string, sizeof(string), "%s~r~Firma: ~w~Brak");
				format(string, sizeof(string), "%s%s", string, string2);
				if(haveGPS && isGPSOn)
				{
					GetPlayerPos(gSpectateID[i], posX, posY, posZ);
					GetPlayerFacingAngle(gSpectateID[i], posA);
					format(string, sizeof(string), "%s ~r~X: ~w~%.2f ~r~Y: ~w~%.2f ~r~Z: ~w~%.2f ~r~A: ~w~%.2f", string, posX, posY, posZ, posA);
				}
			}
			else
			{
				if(gPlayerData[i][pFaction] != 255)
					format(string, sizeof(string), "~r~Przegranych godzin: ~w~%d ~r~Frakcja: ~w~%s %s", gPlayerData[i][pPlayingHours], DynamicFactions[gPlayerData[i][pFaction]][Name]);
				else
					format(string, sizeof(string), "~r~Przegranych godzin: ~w~%d ~r~Frakcja: ~w~Brak %s", gPlayerData[i][pPlayingHours]);
				if(gPlayerData[i][pFaction2] != 255)
					format(string, sizeof(string), "%s~r~Firma: ~w~%s %s", string, DynamicFactions[gPlayerData[i][pFaction2]][Name]);
				else
					format(string, sizeof(string), "%s~r~Firma: ~w~Brak %s", string);				
				format(string, sizeof(string), "%s%s", string, string2);
				if(haveGPS && isGPSOn)
				{
					GetPlayerPos(i, posX, posY, posZ);
					GetPlayerFacingAngle(i, posA);
					format(string, sizeof(string), "%s ~r~X: ~w~%.2f ~r~Y: ~w~%.2f ~r~Z: ~w~%.2f ~r~A: ~w~%.2f", string, posX, posY, posZ, posA);
				}
			}
			PlayerTextDrawSetString(i, PlayerStatus[i], string);
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
		new exited = 0;
		if(gPlayerData[i][pJailed] == 1)
		{
			if(gPlayerData[i][pJailTime] > 0)
			{
				gPlayerData[i][pJailTime]--;

				format(string, sizeof(string), "~n~~n~~n~~n~~n~~n~~n~~w~Pozostalo czasu: ~g~%d sekund.",gPlayerData[i][pJailTime]);
				GameTextForPlayer(i, string, 1500, 3);
			}
			else if(gPlayerData[i][pJailTime] == 0)
			{
				gPlayerData[i][pJailed] = 0;

				for(new n = 0; n < sizeof(gPrisonCells); n++)
				{
					if(!PlayerToPoint(3.0, i, gPrisonCells[n][mPosXInCell], gPrisonCells[n][mPosYInCell], gPrisonCells[n][mPosZInCell]))
					{
						continue;
					}
					exited = 1;
					SetPlayerToPos(i, gPrisonCells[n][mPosXCellEntrance], gPrisonCells[n][mPosYCellEntrance], gPrisonCells[n][mPosZCellEntrance]);
				}
				
				if(!exited)
				{
					SetPlayerToPos(i, gMainPrisonPos[0], gMainPrisonPos[1], gMainPrisonPos[2]);
					SetPlayerInterior(i, 0);
					SetPlayerVirtualWorld(i, 0);
					SetPlayerFacingAngle(i, 280.0);
					
					gPlayerData[i][pCrashInt] = 0;
					gPlayerData[i][pCrashW] = 0;
				}

				if(gPlayerData[i][pDuty] && DynamicFactions[gPlayerData[i][pFaction]][fUseSkins])
				{
					SetPlayerToFactionSkin(i);
				}
				else
				{
					SetPlayerSkinEx(i, gPlayerData[i][pSkin]);
				}
				
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
		
		// Vehicle speedometer and counter and damage
		if(IsPlayerInAnyVehicle(i))
		{
			vehicleID = GetPlayerVehicleID(i);
			dist = ASpeed(vehicleID);

			randomV = random(1450000);
			if(randomV > 0 && randomV < 500 && gVehData[vehicleID-1][EngineOn] && gVehData[vehicleID-1][mVehType] == 0 && dist > 0)
			{
				GetVehicleDamageStatus(vehicleID, panels, doors, lights, tires);
				randomV = random(9);
				if(randomV == 0)
				{
					UpdateVehicleDamageStatus(vehicleID, panels, doors, lights, tires | 0b1000);
				}
				else if(randomV == 1)
				{
					UpdateVehicleDamageStatus(vehicleID, panels, doors, lights, tires | 0b0100);
				}
				else if(randomV == 2)
				{
					UpdateVehicleDamageStatus(vehicleID, panels, doors, lights, tires | 0b0010);
				}
				else if(randomV == 3)
				{
					UpdateVehicleDamageStatus(vehicleID, panels, doors, lights, tires | 0b0001);
				}
				else if(randomV == 4)
				{
					UpdateVehicleDamageStatus(vehicleID, panels, doors, lights | 0b0010, tires);
				}
				else if(randomV == 5)
				{
					UpdateVehicleDamageStatus(vehicleID, panels, doors, lights | 0b0001, tires);
				}
				else if(randomV == 6)
				{
					UpdateVehicleDamageStatus(vehicleID, panels, doors, lights | 0b0100, tires);
				}
				else if(randomV == 7)
				{
					UpdateVehicleDamageStatus(vehicleID, panels, doors, lights | 0b1000, tires);
				}
				else if(randomV == 8)
				{
					GetVehicleParamsEx(vehicleID, enginedyn, lights, alarm, doors, bonnet, boot, objective);
					SetVehicleParamsEx(vehicleID, 0, lights, alarm, doors, bonnet, boot, objective);
					gVehData[vehicleID-1][EngineOn] = 0;
					gVehData[vehicleID-1][CarDamaged] = 0;
				}
			}
			
			if(CheckDelay[i] >= 1)
			{
				CheckDelay[i]--;
			}
			else
			{
                if(floatround(dist) < 1000)
				{
					if(IsPlayerTaxiPassenger[i])
					{
						gTaxiPassengerDistance[i] += floatround(dist);
					}
					
					if(GetPlayerState(i) == PLAYER_STATE_DRIVER)
					{
						gVehData[vehicleID-1][CarCounter] += floatround(dist, floatround_round);
						
						if(dist > 28.0)
						{
							gVehData[vehicleID-1][CarHealth] -= dist/900;
						}
						else
						{
							gVehData[vehicleID-1][CarHealth] -= dist/450;
						}
						
						SetVehicleHealth(vehicleID, gVehData[vehicleID-1][CarHealth]);						
					}						

					gPlayerData[i][pAchieveDistance] += floatround(dist, floatround_round);
				}
			}
		}
		
		if(gBusDriverOnDuty[i] == 1)
		{
			if(gBusDriverResetTime[i] > 0)
			{
				gBusDriverResetTime[i]--;
				
				if(gBusDriverResetTime[i] == 0)
				{
					StopJob(i);
					ShowPlayerDialog(i, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Nie wróci³eœ do pracy na czas.\nW zwi¹zku z niedyspozycj¹ przepada twój przepracowany czas w tym zleceniu.", "Zamknij", "");
				}
				else if(gBusDriverResetTime[i] >= 120)
				{
					format(string, sizeof(string), "Masz %d minuty aby wrocic do pracy", floatround(gBusDriverResetTime[i]/60));
					GameTextForPlayer(i, string, 1500, 6);
				}
				else if(gBusDriverResetTime[i] >= 60 && gBusDriverResetTime[i] < 120)
				{
					format(string, sizeof(string), "Masz %d minute aby wrocic do pracy", floatround(gBusDriverResetTime[i]/60));
					GameTextForPlayer(i, string, 1500, 6);
				}
				else if(gBusDriverResetTime[i] < 60)
				{
					format(string, sizeof(string), "Masz %d sekund/y aby wrocic do pracy", gBusDriverResetTime[i]);
					GameTextForPlayer(i, string, 1500, 6);
				}
			}
			else
			{
				busCheckpoints(i);
			}
		}
		
		if(gTrashDriverOnDuty[i] == 1)
		{
			if(gTrashDriverResetTime[i] > 0)
			{
				gTrashDriverResetTime[i]--;
				
				if(gTrashDriverResetTime[i] == 0)
				{
					StopJob(i);
					ShowPlayerDialog(i, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Nie wróci³eœ do pracy na czas.\nW zwi¹zku z niedyspozycj¹ przepada twój przepracowany czas w tym zleceniu.", "Zamknij", "");
				}
				else if(gTrashDriverResetTime[i] >= 120)
				{
					format(string, sizeof(string), "Masz %d minuty aby wrocic do pracy", floatround(gTrashDriverResetTime[i]/60));
					GameTextForPlayer(i, string, 1500, 6);
				}
				else if(gTrashDriverResetTime[i] >= 60 && gTrashDriverResetTime[i] < 120)
				{
					format(string, sizeof(string), "Masz %d minute aby wrocic do pracy", floatround(gTrashDriverResetTime[i]/60));
					GameTextForPlayer(i, string, 1500, 6);
				}
				else if(gTrashDriverResetTime[i] < 60)
				{
					format(string, sizeof(string), "Masz %d sekund/y aby wrocic do pracy", gTrashDriverResetTime[i]);
					GameTextForPlayer(i, string, 1500, 6);
				}
			}
			else
			{
				trashCheckpoints(i);
			}
		}
		
		if(gSweeperDriverOnDuty[i] == 1)
		{
			if(gSweeperDriverResetTime[i] > 0)
			{
				gSweeperDriverResetTime[i]--;
				
				if(gSweeperDriverResetTime[i] == 0)
				{
					StopJob(i);
					ShowPlayerDialog(i, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Nie wróci³eœ do pracy na czas.\nW zwi¹zku z niedyspozycj¹ przepada twój przepracowany czas w tym zleceniu.", "Zamknij", "");
				}
				else if(gSweeperDriverResetTime[i] >= 120)
				{
					format(string, sizeof(string), "Masz %d minuty aby wrocic do pracy", floatround(gSweeperDriverResetTime[i]/60));
					GameTextForPlayer(i, string, 1500, 6);
				}
				else if(gSweeperDriverResetTime[i] >= 60 && gSweeperDriverResetTime[i] < 120)
				{
					format(string, sizeof(string), "Masz %d minute aby wrocic do pracy", floatround(gSweeperDriverResetTime[i]/60));
					GameTextForPlayer(i, string, 1500, 6);
				}
				else if(gSweeperDriverResetTime[i] < 60)
				{
					format(string, sizeof(string), "Masz %d sekund/y aby wrocic do pracy", gSweeperDriverResetTime[i]);
					GameTextForPlayer(i, string, 1500, 6);
				}
			}
			else
			{
				sweeperCheckpoints(i);
			}
		}
		
		if(gFarmerDriverOnDuty[i] == 1)
		{
			if(gFarmerDriverResetTime[i] > 0)
			{
				gFarmerDriverResetTime[i]--;
				
				if(gFarmerDriverResetTime[i] == 0)
				{
					StopJob(i);
					ShowPlayerDialog(i, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Nie wróci³eœ do pracy na czas.\nW zwi¹zku z niedyspozycj¹ przepada twój przepracowany czas w tym zleceniu.", "Zamknij", "");
				}
				else if(gFarmerDriverResetTime[i] >= 120)
				{
					format(string, sizeof(string), "Masz %d minuty aby wrocic do pracy", floatround(gFarmerDriverResetTime[i]/60));
					GameTextForPlayer(i, string, 1500, 6);
				}
				else if(gFarmerDriverResetTime[i] >= 60 && gFarmerDriverResetTime[i] < 120)
				{
					format(string, sizeof(string), "Masz %d minute aby wrocic do pracy", floatround(gFarmerDriverResetTime[i]/60));
					GameTextForPlayer(i, string, 1500, 6);
				}
				else if(gFarmerDriverResetTime[i] < 60)
				{
					format(string, sizeof(string), "Masz %d sekund/y aby wrocic do pracy", gFarmerDriverResetTime[i]);
					GameTextForPlayer(i, string, 1500, 6);
				}
			}
			else
			{
				farmerCheckpoints(i);
			}
		}
	}
	
	#if defined DEBUG2
		printf("[DEBUG:] OneSecTimer - end");
	#endif
	return;
}

task OneMinTimer[60000]()
{
	#if defined DEBUG
		printf("[DEBUG:] OneMinTimer");
	#endif
	
	static string[256], vehid, enginedyn, lights, alarm, doors, bonnet, boot, objective, Float:vehiclehp;
	
	strdel(string, 0, sizeof(string));	
	
	#if defined DEBUG2
		printf("[DEBUG:] OneMinTimer - check what phones have new messages");
	#endif
	/*
	* Check what phones have new messages
	*/
	format(string, sizeof(string), "SELECT `ReceiverNumber` FROM `samp_sms` WHERE `New` = '1' ORDER BY `ID` DESC LIMIT 0,500");
	wp_mysql_query(string, CHECK_PHONE_NEW_SMS, INVALID_PLAYER_ID, db_con4);
	
	
	GenerateTrashObjectsForTrash();
	
	#if defined DEBUG2
		printf("[DEBUG:] OneMinTimer - vehicle data update - battery, engine stuff, etc");
	#endif
	/*
	* Vehicle data update - actually only battery and some engine stuff
	*/
	for(new i = 0; i < sizeof(gVehData); i++)
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
			
			if(gVehData[i][EngineTemp] < 5)
				gVehData[i][EngineTemp]++;
			
			GetVehicleHealth(i+1,vehiclehp);
			if(vehiclehp < 600.0 && gVehData[i][EngineTemp] == 5)
			{
				SetVehicleParamsEx(i+1,0,lights,alarm,doors,bonnet,boot,objective);
				gVehData[i][EngineOn] = 0;
			}
		}
		else
		{
			if(gVehData[i][EngineTemp] > 0)
				gVehData[i][EngineTemp]--;
			
			if(gVehData[i][mVehType] == 0)
			{
				if(gVehData[i][LightsOn])
				{
					gVehData[i][BatteryCapacity] -= 0.8;
				}
				if(gVehData[i][RadioOn])
				{
					gVehData[i][BatteryCapacity] -= 0.2;
				}
				if(gVehData[i][BatteryCapacity] <= 0.0)
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
	
	#if defined DEBUG2
		printf("[DEBUG:] OneMinTimer - faction data update");
	#endif
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
	
	#if defined DEBUG2
		printf("[DEBUG:] OneMinTimer - gang war status");
	#endif
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
				{
					continue;
				}
				
				if(gPlayerData[i][pFaction] != 255)
				{
					if(DynamicFactions[gPlayerData[i][pFaction]][fType] == FACTIONT_GANG)
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
				SaveGangZone(gGangWar[AreaID], "Faction");
				
				RefreshZoneColorAfterWar();
				
				format(string, sizeof(string), "Terytorium zostalo przejete przez~n~%s", DynamicFactions[gGangWar[FactionStarted]]);
		
				foreach(Player, i)
				{
					if(!gPlayerLogged[i])
					{
						continue;
					}
					
					if(gPlayerData[i][pFaction] != gGangWar[FactionStarted] && gPlayerData[i][pFaction] != gGangWar[FactionAttacked])
					{
						continue;
					}
					
					GameTextForPlayer(i, string, 6000, 6);
				}
				
			}
			else if(gGangWar[FactionStartedKills] <= gGangWar[FactionAttackedKills])
			{
				DynamicFactions[gGangWar[FactionAttacked]][fTerritoryWarWins]++;
				SavePlayerData(gGangWar[FactionAttacked], "TerritoryWarWins");
				
				DynamicFactions[gGangWar[FactionStarted]][fTerritoryWarLooses]++;
				SavePlayerData(gGangWar[FactionStarted], "TerritoryWarLooses");
				
				RefreshZoneColorAfterWar();
		
				format(string, sizeof(string), "Terytorium zostaje pod kontrola~n~%s", DynamicFactions[DynamicZones[gGangWar[AreaID]][mFaction]][Name]);
				
				foreach(Player, i)
				{
					if(!gPlayerLogged[i])
					{
						continue;
					}
					
					if(gPlayerData[i][pFaction] != gGangWar[FactionStarted] && gPlayerData[i][pFaction] != gGangWar[FactionAttacked])
					{
						continue;
					}
					
					GameTextForPlayer(i, string, 6000, 6);
					
					return 1;
				}
			}
		}
		else if(gGangWar[TimeLeft] > 0)
		{
			gGangWar[TimeLeft]--;
		}
		
		new isAnyDefenderInArea;
		new isPlayerInAreab;
		
		foreach(Player, i)
		{
			/*
			* CHECK IF DEFENDER IS ON ATTACKED TERRITORY
			*/
			if(gPlayerData[i][pFaction] != 255)
			{
				if(DynamicFactions[gPlayerData[i][pFaction]][fType] == 3 )
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
		/*
		* TERRITORY TAKEN - PLAYER ALONE IN FIELD
		*/
		/*if(gGangWar[TimeAlone] >= 10)
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
		}*/
	}
	
	#if defined DEBUG2
		printf("[DEBUG:] OneMinTimer - player stuff, health, etc");
	#endif
	/*
	* Player stuff
	*/
	foreach(Player, i )
	{
		#if defined DEBUG2
			printf("[DEBUG:] OneMinTimer - check if logged");
		#endif
		if(!gPlayerLogged[i])
			continue;
		
		#if defined DEBUG2
			printf("[DEBUG:] OneMinTimer - bullet proof");
		#endif
		if(gPlayerVars[i][mBulletProof] > 0)
			gPlayerVars[i][mBulletProof]--;
		
		// NOTE: WTF IS THAT ?
		SavePlayerData(i, "AchieveDistance");
		
		#if defined DEBUG2
			printf("[DEBUG:] OneMinTimer - player phone check");
		#endif
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
		
		#if defined DEBUG2
			printf("[DEBUG:] OneMinTimer - word area player check");
		#endif
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
		
		if(!VipAFKActive[i] && !AdminDuty[i] && GetPlayerState(i) != PLAYER_STATE_SPECTATING && Spawned[i])
		{
			#if defined DEBUG2
				printf("[DEBUG:] OneMinTimer - decrease used medicaments effects");
			#endif
			
			/*
			* Decrease used medicaments effects
			*/
			if(gPlayerData[i][pPainKiller] > 0)
				gPlayerData[i][pPainKiller]--;
			if(gPlayerData[i][pSlimming] > 0)
				gPlayerData[i][pSlimming]--;
			if(gPlayerData[i][pStomachDrops] > 0)
				gPlayerData[i][pStomachDrops]--;
			
			#if defined DEBUG2
				printf("[DEBUG:] OneMinTimer - eating needs");
			#endif
			/*
			* This part checks eating needs
			*/	
			if(gPlayerData[i][pJailed] == 0 && gPlayerData[i][pCharacterDying] == 0)
			{
				#if defined DEBUG2
					printf("[DEBUG:] OneMinTimer - health problems");
				#endif
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
				
				#if defined DEBUG2
					printf("[DEBUG:] OneMinTimer - energy");
				#endif
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
					{
						SendClientMessage(i, COLOR_ORANGE, "[INFO:] Czujesz siê os³abiony, powinieneœ coœ zjeœæ");
					}
					
					if(gPlayerData[i][pEnergy] < 10)
					{
						SendClientMessage(i, COLOR_ORANGE, "[INFO:] Czujesz siê bardzo os³abiony, powinieneœ coœ zjeœæ");
					}
				}
				
				if(gPlayerData[i][pEnergy] < 0.0)
					gPlayerData[i][pEnergy] = 0.0;
			
			
				#if defined DEBUG2
					printf("[DEBUG:] OneMinTimer - hunger");
				#endif
				// Hunger
				if(IsPlayerVip(i))
				{
					#if defined DEBUG2
						printf("[DEBUG:] OneMinTimer - hunger for vip");
					#endif
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
					{
						SendClientMessage(i, COLOR_ORANGE, "[INFO:] Czujesz lekki g³ód");
					}
				}
				else
				{
					#if defined DEBUG2
						printf("[DEBUG:] OneMinTimer - hunger for non vip");
					#endif
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
						{
							gPlayerData[i][pHunger] += HUNGER*0.05;
						}
						else if(gPlayerData[i][pVitamins] >= 80.0 && gPlayerData[i][pVitamins] <= 100.0)
						{
							gPlayerData[i][pHunger] += HUNGER*0.05;
						}
						
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
					}
				}
				
				#if defined DEBUG2
					printf("[DEBUG:] OneMinTimer - thirst");
				#endif
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
						
					}
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
					}
				}
				
				#if defined DEBUG2
					printf("[DEBUG:] OneMinTimer - poison");
				#endif
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
					}
					if(gPlayerData[i][pPoison] >= 60.0 && gPlayerData[i][pPoison] < 90.0)
					{
						if(random(15) == 3)
							SetPlayerDrunkLevelEx(i, 3980);
					}
					if(gPlayerData[i][pPoison] >= 90.0 && gPlayerData[i][pPoison] < 120.0)
					{
						if(random(10) == 3)
						{
							SetPlayerDrunkLevelEx(i, 5960);	
							defer PlayerWomit(i);
						}
					}	
					if(gPlayerData[i][pPoison] >= 120.0)
					{
						if(random(5) == 3)
						{
							SetPlayerDrunkLevelEx(i, 12880);	
							defer PlayerWomit(i);
						}
					}
				}
				else
				{
					if(gPlayerData[i][pPoison] > 0.0 && gPlayerData[i][pPoison] < 40.0)
					{
						gPlayerData[i][pPoison] -= POISON;
					}
					if(gPlayerData[i][pPoison] >= 40.0 && gPlayerData[i][pPoison] < 60.0)
					{
						if(random(15) == 3)
							SetPlayerDrunkLevelEx(i, 3980);	
					}
					if(gPlayerData[i][pPoison] >= 60.0 && gPlayerData[i][pPoison] < 80.0)
					{
						if(random(10) == 3)
						{
							SetPlayerDrunkLevelEx(i, 5960);	
							defer PlayerWomit(i);
						}
					}	
					if(gPlayerData[i][pPoison] >= 80.0)
					{
						if(random(5) == 3)
						{
							SetPlayerDrunkLevelEx(i, 12880);	
							defer PlayerWomit(i);
						}
					}
				}
				
				if(gPlayerData[i][pPoison] < 0.0)
				{
					gPlayerData[i][pPoison] = 0.0;
				}
				
				#if defined DEBUG2
					printf("[DEBUG:] OneMinTimer - fat");
				#endif
				// Fat
				if(gPlayerData[i][pFat] > 0.0)
				{
					gPlayerData[i][pFat] -= FAT*2.0;
				}
				if(gPlayerData[i][pFat] < 0.0)
				{
					gPlayerData[i][pFat] = 0.0;
				}
				
				#if defined DEBUG2
					printf("[DEBUG:] OneMinTimer - stomach");
				#endif
				// Stomach
				if(gPlayerData[i][pStomach] > 0.0)
				{
					if(gPlayerData[i][pSlimming] > 0)
					{
						gPlayerData[i][pStomach] -= STOMACH*2.5;
					}
					gPlayerData[i][pStomach] -= STOMACH;
				}
				else if(gPlayerData[i][pStomach] < 0.0)
				{
					gPlayerData[i][pStomach] = 0.0;
				}
				
				// Vitamins
				if(gPlayerData[i][pVitamins] > 0.0)
				{
					if((IsPlayerVip(i) && gPlayerData[i][pPoison] >= MAX_POISON_VIP) || (!IsPlayerVip(i) && gPlayerData[i][pPoison] >= MAX_POISON))
					{
						gPlayerData[i][pVitamins] -= 5.0;
					}
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
					SetProgressBarValue(gPlayerData[i][pEnergyProgressBarID], gPlayerData[i][pEnergy]);
					UpdateProgressBar(gPlayerData[i][pEnergyProgressBarID], i);
					SetProgressBarValue(gPlayerData[i][pHungerProgressBarID], gPlayerData[i][pHunger]);
					UpdateProgressBar(gPlayerData[i][pHungerProgressBarID], i);
					SetProgressBarValue(gPlayerData[i][pThirstProgressBarID], gPlayerData[i][pThirst]);
					UpdateProgressBar(gPlayerData[i][pThirstProgressBarID], i);
					// SetProgressBarValue(gPlayerData[i][pPoisonProgressBarID], gPlayerData[i][pPoison]);
					// UpdateProgressBar(gPlayerData[i][pPoisonProgressBarID], i);
					// SetProgressBarValue(gPlayerData[i][pFatProgressBarID], gPlayerData[i][pFat]);
					// UpdateProgressBar(gPlayerData[i][pFatProgressBarID], i);
					// SetProgressBarValue(gPlayerData[i][pStomachProgressBarID], gPlayerData[i][pStomach]);
					// UpdateProgressBar(gPlayerData[i][pStomachProgressBarID], i);
					// SetProgressBarValue(gPlayerData[i][pVitaminsProgressBarID], gPlayerData[i][pVitamins]);
					// UpdateProgressBar(gPlayerData[i][pVitaminsProgressBarID], i);
					// SetProgressBarValue(gPlayerData[i][pDrunkProgressBarID], gPlayerData[i][pDrunk]);
					// UpdateProgressBar(gPlayerData[i][pDrunkProgressBarID], i);
					// SetProgressBarValue(gPlayerData[i][pNarcoticProgressBarID], gPlayerData[i][pNarcotic]);
					// UpdateProgressBar(gPlayerData[i][pNarcoticProgressBarID], i);
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
				}
			}
			if(LastDrug[i] > 0)
			{
				LastDrug[i]--;
			}
		}
	}
	
	#if defined DEBUG2
		printf("[DEBUG:] OneMinTimer - end");
	#endif
	
	return 1;
}

task FiveMinTimer[300000]()
{
	#if defined DEBUG
		printf("[DEBUG:] FiveMinTimer");
	#endif
	
	foreach(Player, i )
	{
		if(!gPlayerLogged[i])
		{
			continue;
		}
			
		// sprzedawca/ekspedient
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
							GivePlayerCash(i,3);
							Businesses[k][Till] -= 3;
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
	
	static string[128], string2[128], Hour, Minute, Second;

	gettime(Hour, Minute, Second);
	
	strdel(string, 0, sizeof(string));
	strdel(string2, 0, sizeof(string2));
	
	if(Hour == 4 && !gPaydayLaunched)
	{
		PayDay();
		gPaydayLaunched = 1;
	}
	else if(Hour == 5)
	{
		gPaydayLaunched = 0;
	}
	
	GenerateTrashObjectsForSweeper();
	
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
		
		if(gVehData[i][mVehType] == 0)
		{
			GetVehiclePos(i+1, gVehData[i][mVehX], gVehData[i][mVehY], gVehData[i][mVehZ]);
			GetVehicleZAngle(i+1, gVehData[i][mVehA]);
			GetVehicleHealth(i+1, gVehData[i][CarHealth]);
			
			SaveVehData(i, "VehPos");
		}
		
		SaveVehData(i, "CarCounter");
		
		if(gVehData[i][CarRepairTimeLeft] > 0)
		{
			SaveVehData(i, "CarRepairTimeLeft");
		}
		
		SaveVehData(i, "VehSave3");
	}
	
	// Shows tips about gameplay
	//ShowNewTip();
	
	for(new i = 0; i < sizeof(gPublicAds); i++)
	{
		if(gPublicAds[i][mAdLine1TimeLeft] > 0)
		{
			gPublicAds[i][mAdLine1TimeLeft]--;
			SavePublicAdsData(i, "AdLine1");
		}
		if(gPublicAds[i][mAdLine2TimeLeft] > 0)
		{
			gPublicAds[i][mAdLine2TimeLeft]--;
			SavePublicAdsData(i, "AdLine2");
		}
		if(gPublicAds[i][mAdLine3TimeLeft] > 0)
		{
			gPublicAds[i][mAdLine3TimeLeft]--;
			SavePublicAdsData(i, "AdLine3");
		}
		if(gPublicAds[i][mAdLine4TimeLeft] > 0)
		{
			gPublicAds[i][mAdLine4TimeLeft]--;
			SavePublicAdsData(i, "AdLine4");
		}
		if(gPublicAds[i][mAdLine5TimeLeft] > 0)
		{
			gPublicAds[i][mAdLine5TimeLeft]--;
			SavePublicAdsData(i, "AdLine5");
		}
		if(gPublicAds[i][mAdLine6TimeLeft] > 0)
		{
			gPublicAds[i][mAdLine6TimeLeft]--;
			SavePublicAdsData(i, "AdLine6");
		}
		if(gPublicAds[i][mAdLine7TimeLeft] > 0)
		{
			gPublicAds[i][mAdLine7TimeLeft]--;
			SavePublicAdsData(i, "AdLine7");
		}
		if(gPublicAds[i][mAdLine8TimeLeft] > 0)
		{
			gPublicAds[i][mAdLine8TimeLeft]--;
			SavePublicAdsData(i, "AdLine8");
		}
		if(gPublicAds[i][mAdLine9TimeLeft] > 0)
		{
			gPublicAds[i][mAdLine9TimeLeft]--;
			SavePublicAdsData(i, "AdLine9");
		}
		if(gPublicAds[i][mAdLine10TimeLeft] > 0)
		{
			gPublicAds[i][mAdLine10TimeLeft]--;
			SavePublicAdsData(i, "AdLine10");
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
			
			if(IsPlayerVip(i))
			{
				if(gPlayerData[i][pHunger] >= MAX_HUNGER_VIP)
				{
					SendClientMessage(i, COLOR_ORANGE, "[INFO:] Jesteœ bardzo g³odny !");
				}
				if(MAX_HUNGER_VIP-gPlayerData[i][pHunger] <= 20 && gPlayerData[i][pHunger] < MAX_HUNGER_VIP)
				{
					SendClientMessage(i, COLOR_ORANGE, "[INFO:] Czujesz lekki g³ód");
				}
			
				if(gPlayerData[i][pThirst] >= MAX_THIRST_VIP)
				{
					gPlayerData[i][pThirst] = MAX_THIRST_VIP;
					SendClientMessage(i, COLOR_ORANGE, "[INFO:] Jesteœ odwodniony !");
				}
				if(MAX_THIRST_VIP - gPlayerData[i][pThirst] <= 10 && gPlayerData[i][pThirst] < MAX_THIRST_VIP)
				{	
					SendClientMessage(i, COLOR_ORANGE, "[INFO:] Czujesz pragnienie");
				}
				if(MAX_THIRST_VIP - gPlayerData[i][pThirst] <= 30 && MAX_THIRST_VIP - gPlayerData[i][pThirst] > 10)
				{	
					SendClientMessage(i, COLOR_ORANGE, "[INFO:] Czujesz lekkie pragnienie");
				}	
			}
			else
			{		
				if(gPlayerData[i][pHunger] >= MAX_HUNGER)
				{
					SendClientMessage(i, COLOR_ORANGE, "[INFO:] Jesteœ bardzo g³odny !");
				}
				if(MAX_HUNGER-gPlayerData[i][pHunger] <= 20 && gPlayerData[i][pHunger] < MAX_HUNGER)
				{	
					SendClientMessage(i, COLOR_ORANGE, "[INFO:] Czujesz lekki g³ód");
				}

				if(gPlayerData[i][pThirst] >= MAX_THIRST)
				{
					SendClientMessage(i, COLOR_ORANGE, "[INFO:] Jesteœ odwodniony !");
				}
				if(MAX_THIRST - gPlayerData[i][pThirst] <= 10 && gPlayerData[i][pThirst] < MAX_THIRST)
				{
					SendClientMessage(i, COLOR_ORANGE, "[INFO:] Czujesz pragnienie");
				}
				if(MAX_THIRST - gPlayerData[i][pThirst] <= 30 && MAX_THIRST - gPlayerData[i][pThirst] > 10)
				{
					SendClientMessage(i, COLOR_ORANGE, "[INFO:] Czujesz lekkie pragnienie");
				}
			}
			
			if(gPlayerData[i][pEnergy] <= 20 && gPlayerData[i][pEnergy] >= 10)
			{
				SendClientMessage(i, COLOR_ORANGE, "[INFO:] Czujesz siê os³abiony, powinieneœ coœ zjeœæ");
			}
			
			if(gPlayerData[i][pEnergy] < 10)
			{
				SendClientMessage(i, COLOR_ORANGE, "[INFO:] Czujesz siê bardzo os³abiony, powinieneœ coœ zjeœæ");
			}
			
			if(gPlayerData[i][pPoison] >= 40.0)
			{
				SendClientMessage(i, COLOR_ORANGE, "[INFO:] Zatru³eœ siê, czuje siê Ÿle, udaj siê do lekarza po porade");
			}
			
			if(gPlayerData[i][pFat] <= 30.0)
			{
				SendClientMessage(i, COLOR_ORANGE, "[INFO:] Zbli¿asz siê ku dolnej granicy cholesterolu");
			}
			
			if(gPlayerData[i][pFat] >= 85.0)
			{
				SendClientMessage(i, COLOR_ORANGE, "[INFO:] Miewasz czêste zadyszki, zg³oœ siê do lekarza");
			}
			
			if(gPlayerData[i][pStomach] >= 80.0)
			{
				SendClientMessage(i, COLOR_ORANGE, "[INFO:] Czujesz siê w pe³ni najedzony - dalsze jedzenie spowoduje zatrucie");
			}
			
			if(gPlayerData[i][pVitamins] <= 30.0)
			{
				SendClientMessage(i, COLOR_ORANGE, "[INFO:] Masz niedobór minera³ów, zjedz coœ po¿ywnego");
			}
			
			if(gPlayerData[i][pVitamins] >= 70.0)
			{
				SendClientMessage(i, COLOR_ORANGE, "[INFO:] Jesteœ chory, zg³oœ siê do lekarza");
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
	wp_mysql_query(string, RELOAD_DYNAMIC_FACTIONS, INVALID_PLAYER_ID, db_con2);

	format(string, sizeof(string), "SELECT * FROM samp_factions_weapons ORDER BY `FactionID` ASC");
	wp_mysql_query(string, LOAD_DYNAMIC_FACTIONS_WEAPONS, INVALID_PLAYER_ID, db_con2);

	format(string, sizeof(string), "SELECT * FROM samp_factions_weapons2 ORDER BY `FactionID` ASC");
	wp_mysql_query(string, LOAD_DYNAMIC_FACTIONS_WEAPONS2, INVALID_PLAYER_ID, db_con2);

	format(string, sizeof(string), "SELECT * FROM `samp_factions_payrank` ORDER BY `FactionID` ASC");
	wp_mysql_query(string, LOAD_FACTIONS_PAYRANK, INVALID_PLAYER_ID, db_con2);
	
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
	
	return 1;
}