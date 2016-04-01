/***
*
* File: wp_sweepercheckpoints.inc
* Auth: Damian Wojdat
* Date: 16.05.2012
* Desc: Handle rewards, experience gain, etc. for driving through sweeper checkpoints.
*
*************************************************************************************************************/

GenerateTrashObjectsForSweeper()
{
	new trashCount = random(2);
	new i = 0;
	new trackId, cpId, tries;
	while(i < trashCount && tries < 300)
	{
		tries++;
		trackId = random(sizeof(gSweeperTrackEnabled));
		if(!gSweeperTrackEnabled[trackId])
			continue;
		cpId = random(sizeof(gSweeperTrackEnabled));
		if(gSweeperTrackCpType[trackId][cpId] == 0 || gSweeperTrackCpType[trackId][cpId] == 2 || (gSweeperTrackCpX[trackId][cpId] == 0.0 || gSweeperTrackCpY[trackId][cpId] == 0.0))
			continue;
		if(gSweeperTrackCpTrashEnabled[trackId][cpId] == 1)
			continue;
		gSweeperTrackCpTrashEnabled[trackId][cpId] = 1;
		switch(random(10))
		{
			case 0:
				gSweeperTrackCpTrashId[trackId][cpId] = CreateDynamicObject(852, gSweeperTrackCpX[trackId][cpId]+float(random(5))/10.0, gSweeperTrackCpY[trackId][cpId]+float(random(5))/10.0, gSweeperTrackCpZ[trackId][cpId]-0.7, 0.0, 0.0, 0.0, 0, 0);
			case 1:
				gSweeperTrackCpTrashId[trackId][cpId] = CreateDynamicObject(851, gSweeperTrackCpX[trackId][cpId]+float(random(5))/10.0, gSweeperTrackCpY[trackId][cpId]+float(random(5))/10.0, gSweeperTrackCpZ[trackId][cpId]-0.4, 0.0, 0.0, 0.0, 0, 0);
			case 2:
				gSweeperTrackCpTrashId[trackId][cpId] = CreateDynamicObject(849, gSweeperTrackCpX[trackId][cpId]+float(random(5))/10.0, gSweeperTrackCpY[trackId][cpId]+float(random(5))/10.0, gSweeperTrackCpZ[trackId][cpId]-0.4, 0.0, 0.0, 0.0, 0, 0);
			case 3:
				gSweeperTrackCpTrashId[trackId][cpId] = CreateDynamicObject(2676, gSweeperTrackCpX[trackId][cpId]+float(random(5))/10.0, gSweeperTrackCpY[trackId][cpId]+float(random(5))/10.0, gSweeperTrackCpZ[trackId][cpId]-0.5, 0.0, 0.0, 0.0, 0, 0);
			case 4:
				gSweeperTrackCpTrashId[trackId][cpId] = CreateDynamicObject(2672, gSweeperTrackCpX[trackId][cpId]+float(random(5))/10.0, gSweeperTrackCpY[trackId][cpId]+float(random(5))/10.0, gSweeperTrackCpZ[trackId][cpId]-0.4, 0.0, 0.0, 0.0, 0, 0);
			case 5:
				gSweeperTrackCpTrashId[trackId][cpId] = CreateDynamicObject(2673, gSweeperTrackCpX[trackId][cpId]+float(random(5))/10.0, gSweeperTrackCpY[trackId][cpId]+float(random(5))/10.0, gSweeperTrackCpZ[trackId][cpId]-0.5, 0.0, 0.0, 0.0, 0, 0);
			case 6:
				gSweeperTrackCpTrashId[trackId][cpId] = CreateDynamicObject(2674, gSweeperTrackCpX[trackId][cpId]+float(random(5))/10.0, gSweeperTrackCpY[trackId][cpId]+float(random(5))/10.0, gSweeperTrackCpZ[trackId][cpId]-0.5, 0.0, 0.0, 0.0, 0, 0);
			case 7:
				gSweeperTrackCpTrashId[trackId][cpId] = CreateDynamicObject(2675, gSweeperTrackCpX[trackId][cpId]+float(random(5))/10.0, gSweeperTrackCpY[trackId][cpId]+float(random(5))/10.0, gSweeperTrackCpZ[trackId][cpId]-0.6, 0.0, 0.0, 0.0, 0, 0);
			case 8:
				gSweeperTrackCpTrashId[trackId][cpId] = CreateDynamicObject(2677, gSweeperTrackCpX[trackId][cpId]+float(random(5))/10.0, gSweeperTrackCpY[trackId][cpId]+float(random(5))/10.0, gSweeperTrackCpZ[trackId][cpId]-0.4, 0.0, 0.0, 0.0, 0, 0);
			case 9:
				gSweeperTrackCpTrashId[trackId][cpId] = CreateDynamicObject(18862, gSweeperTrackCpX[trackId][cpId]+float(random(5))/10.0, gSweeperTrackCpY[trackId][cpId]+float(random(5))/10.0, gSweeperTrackCpZ[trackId][cpId]-0.5, 0.0, 0.0, 0.0, 0, 0);
		}
	}
}
	
/*
* Purpose:
*				Return number of points required to gain next level in bus job.
*/
playerNextLvlSweeperPoints(playerid)
{
	return 50*10*floatround(floatpower(2, gPlayerData[playerid][pSweeperJobLvl])); // 50 to jest œrednia liczba cp na danej trasie a 10 to liczba z ksiezyca naszej ziemi, dalej to zagadka dla ciebie
}

Float:SweeperCashForCheckpoint(playerid)
{
	switch(gPlayerData[playerid][pSweeperJobLvl])
	{
		case 1: return 8.0;
		case 2: return 13.0;
		case 3: return 17.0;
		case 4: return 21.0;
		case 5: return 25.0;
		default: return 4.0;
	}
	return 0.0;
}

sweeperCheckpoints(i)
{
	new enginedyn, lights, alarm, doors, bonnet, boot, objective;
	new string[128];
	new vehicleID = GetPlayerVehicleID(i);
	new Float:vehicleHealth; // used for storage of vehicle health
	if(gPlayerData[i][pSweeperJobPoints] == ( playerNextLvlSweeperPoints(i)))
	{
		if(gPlayerData[i][pSweeperJobLvl] >= 20)
		{
			gPlayerData[i][pSweeperJobLvl] = 20;
			gPlayerData[i][pSweeperJobPoints] = playerNextLvlSweeperPoints(i);
			SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pSweeperJobPoints]));
			UpdateProgressBar(JobProgress[i], i);
			SavePlayerData(i, "SweeperJobLvl");
			SavePlayerData(i, "SweeperJobPoints");
		}
		else
		{
			SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pSweeperJobPoints]));
			UpdateProgressBar(JobProgress[i], i);
			gPlayerData[i][pSweeperJobLvl]++;
			gPlayerData[i][pExp]++;
			gPlayerData[i][pSweeperJobPoints] = 0;
			
			SavePlayerData(i, "SweeperJobLvl");
			SavePlayerData(i, "Exp");
			SavePlayerData(i, "SweeperJobPoints");
			
			SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pSweeperJobPoints]));
			UpdateProgressBar(JobProgress[i], i);
			format(string, sizeof(string), "[INFO:] Osi¹gn¹³eœ %d poziom jako kierowca œmieciarki !", gPlayerData[i][pSweeperJobLvl]);
			SendClientMessage(i, COLOR_LIGHTYELLOW2, string);
		}
	}
	GetVehicleHealth(vehicleID, vehicleHealth);
	if(vehicleHealth <= 700.0 && gVehHealthOnPlayerEnter[i] > 700.0 && gSweeperDriverPenaltyInformed[i] == 0 && IsPlayerInAnyVehicle(i) && gVehData[vehicleID-1][mVehType] == 2)
	{
		gPlayerData[i][pCost] += BUS_PENALTY_COST;
		gSweeperDriverPenaltyInformed[i] = 1;
		gPlayerData[i][pSweeperJobPoints] -= 2;
		
		SavePlayerData(i, "Cost");
		SavePlayerData(i, "SweeperJobPoints");
		
		SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pSweeperJobPoints]));
		UpdateProgressBar(JobProgress[i], i);
		format( string, sizeof(string), "[INFO:] Zosta³eœ ukarany grzywn¹ w wysokoœci %s$ za nieostro¿n¹ jazde", BUS_PENALTY_COST);
		SendClientMessage(i, COLOR_LIGHTYELLOW2, string);
		SendClientMessage(i, COLOR_LIGHTYELLOW2, "[INFO:] Kara zostanie automatycznie pobrana przy nastêpnej wyp³acie");
		SendClientMessage(i, COLOR_LIGHTYELLOW2, "[INFO:] Tracisz tak¿e 2pkt pracy");
	}
	if(EnteredVehicleID[i] == GetPlayerVehicleID(i))
	{
		if( gSweeperTrackCpType[ gSweeperDriverSelectedLine[i] ][ gSweeperDriverCurrentCheckPoint[i] ] == 0 && gSweeperDriverJustStarted[i] )
		{
			gSweeperDriverPaymentCount[i] = 0;
			gSweeperDriverCurrentCheckPoint[i] = 0;
			gSweeperDriverCheckpointTime[i] = gSweeperTrackCpTime[ gSweeperDriverSelectedLine[i] ][ gSweeperDriverCurrentCheckPoint[i] ];
			gSweeperDriverJustStarted[i] = 0;			
			gJobProfit[i] = 0;
			SetPlayerCheckpoint(i, gSweeperTrackCpX[ gSweeperDriverSelectedLine[i] ][ gSweeperDriverCurrentCheckPoint[i] ], gSweeperTrackCpY[ gSweeperDriverSelectedLine[i] ][ gSweeperDriverCurrentCheckPoint[i] ], gSweeperTrackCpZ[ gSweeperDriverSelectedLine[i] ][ gSweeperDriverCurrentCheckPoint[i] ], 5.0);
		}
		if( ( gSweeperTrackCpType[ gSweeperDriverSelectedLine[i] ][ gSweeperDriverCurrentCheckPoint[i] ] == 1 || gSweeperTrackCpType[ gSweeperDriverSelectedLine[i] ][ gSweeperDriverCurrentCheckPoint[i] ] == 0 ) && IsPlayerInRangeOfPoint(i, 5.0, gSweeperTrackCpX[ gSweeperDriverSelectedLine[i] ][ gSweeperDriverCurrentCheckPoint[i] ], gSweeperTrackCpY[ gSweeperDriverSelectedLine[i] ][ gSweeperDriverCurrentCheckPoint[i] ], gSweeperTrackCpZ[ gSweeperDriverSelectedLine[i] ][ gSweeperDriverCurrentCheckPoint[i] ] ) )
		{
			gSweeperDriverCheckpointTime[i]--;
			if(gSweeperDriverCheckpointTime[i] > 0)
			{
				format(string, sizeof(string), JOB_BUS_DEP_TIME_LEFT, gSweeperDriverCheckpointTime[i]);
				GameTextForPlayer(i, string, JOB_BUS_TXT_SHOW_TIME, GAME_TEXT_STYLE_4);
			}
			else
			{
				if(gSweeperTrackCpTrashEnabled[gSweeperDriverSelectedLine[i]][gSweeperDriverCurrentCheckPoint[i]] == 1)
				{
					gSweeperTrackCpTrashEnabled[gSweeperDriverSelectedLine[i]][gSweeperDriverCurrentCheckPoint[i]] = 0;
					DestroyDynamicObject(gSweeperTrackCpTrashId[gSweeperDriverSelectedLine[i]][gSweeperDriverCurrentCheckPoint[i]]);
				}
				gPlayerData[i][pSweeperJobPoints]++;
				SavePlayerData(i, "SweeperJobPoints");
				SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pSweeperJobPoints]));
				UpdateProgressBar(JobProgress[i], i);
				gJobProfit[i] += SweeperCashForCheckpoint(i);
				
				gSweeperDriverCurrentCheckPoint[i]++;
				gSweeperDriverCheckpointTime[i] = gSweeperTrackCpTime[ gSweeperDriverSelectedLine[i] ][ gSweeperDriverCurrentCheckPoint[i] ];
				SetPlayerCheckpoint(i, gSweeperTrackCpX[ gSweeperDriverSelectedLine[i] ][ gSweeperDriverCurrentCheckPoint[i] ], gSweeperTrackCpY[ gSweeperDriverSelectedLine[i] ][ gSweeperDriverCurrentCheckPoint[i] ], gSweeperTrackCpZ[ gSweeperDriverSelectedLine[i] ][ gSweeperDriverCurrentCheckPoint[i] ], 5.0);				
			}
		}
		else if( gSweeperTrackCpType[ gSweeperDriverSelectedLine[i] ][ gSweeperDriverCurrentCheckPoint[i] ] == 2 && IsPlayerInRangeOfPoint(i, 5.0, gSweeperTrackCpX[ gSweeperDriverSelectedLine[i] ][ gSweeperDriverCurrentCheckPoint[i] ], gSweeperTrackCpY[ gSweeperDriverSelectedLine[i] ][ gSweeperDriverCurrentCheckPoint[i] ], gSweeperTrackCpZ[ gSweeperDriverSelectedLine[i] ][ gSweeperDriverCurrentCheckPoint[i] ] ) )
		{
			GivePlayerCash(i, floatround(gJobProfit[i], floatround_round));
			DynamicFactions[FACTIONID_GOVERNMENT][fBank] -= floatround(gJobProfit[i], floatround_round);
			SaveFData(FACTIONID_GOVERNMENT, "Bank");
		
			format(string, sizeof(string), "[INFO:] Zarobi³eœ za tê trase %d$", floatround(gJobProfit[i], floatround_round));
			SendClientMessage(i, COLOR_LIGHTYELLOW2, string);
			
			gSweeperDriverOnDuty[i] = 0;
			DisablePlayerCheckpoint(i);			
			RemovePlayerFromVehicle(i);		
			HideProgressBarForPlayer(i, JobProgress[i]);
			gSweeperDriverCurrentCheckPoint[i] = 0;
			
			UpdateDynamic3DTextLabelText(BusRoute[vehicleID-1], COLOR_LIGHTYELLOW, " ");
			SetVehicleToRespawnEx(vehicleID);
			GetVehicleParamsEx(vehicleID, enginedyn, lights, alarm, doors, bonnet, boot, objective);
			SetVehicleParamsEx(vehicleID,0,lights,alarm,doors,bonnet,boot,objective);
			gVehData[vehicleID-1][EngineOn] = 0;
			SaveVehData( vehicleID-1, "EngineOn" );
			gVehData[vehicleID-1][CarFuel] = float(VehFTank(vehicleID));
			SaveVehData( vehicleID-1, "CarFuel" );			
		}
	}
}