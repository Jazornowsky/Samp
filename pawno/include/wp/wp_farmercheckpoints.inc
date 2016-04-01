/***
*
* File: wp_farmercheckpoints.inc
* Auth: Damian Wojdat
* Date: 5.06.2012
* Desc: Handle rewards, experience gain, etc. for driving through farmer checkpoints.
*
*************************************************************************************************************/

// GenerateTrashObjectsForFarmer()
// {
	// new trashCount = random(2);
	// new i = 0;
	// new trackId, cpId, tries;
	// while(i < trashCount && tries < 300)
	// {
		// tries++;
		// trackId = random(sizeof(gFarmerTrackEnabled));
		// if(!gFarmerTrackEnabled[trackId])
			// continue;
		// cpId = random(sizeof(gFarmerTrackEnabled));
		// if(gFarmerTrackCpType[trackId][cpId] == 0 && gFarmerTrackCpType[trackId][cpId] == 2)
			// continue;
		// if(gFarmerTrackCpTrashEnabled[trackId][cpId] == 1)
			// continue;
		// gFarmerTrackCpTrashEnabled[trackId][cpId] = 1;
		// switch(random(10))
		// {
			// case 0:
				// gFarmerTrackCpTrashId[trackId][cpId] = CreateDynamicObject(852, gFarmerTrackCpX[trackId][cpId]+float(random(5))/10.0, gFarmerTrackCpY[trackId][cpId]+float(random(5))/10.0, gFarmerTrackCpZ[trackId][cpId]-0.7, 0.0, 0.0, 0.0, 0, 0);
			// case 1:
				// gFarmerTrackCpTrashId[trackId][cpId] = CreateDynamicObject(851, gFarmerTrackCpX[trackId][cpId]+float(random(5))/10.0, gFarmerTrackCpY[trackId][cpId]+float(random(5))/10.0, gFarmerTrackCpZ[trackId][cpId]-0.4, 0.0, 0.0, 0.0, 0, 0);
			// case 2:
				// gFarmerTrackCpTrashId[trackId][cpId] = CreateDynamicObject(849, gFarmerTrackCpX[trackId][cpId]+float(random(5))/10.0, gFarmerTrackCpY[trackId][cpId]+float(random(5))/10.0, gFarmerTrackCpZ[trackId][cpId]-0.4, 0.0, 0.0, 0.0, 0, 0);
			// case 3:
				// gFarmerTrackCpTrashId[trackId][cpId] = CreateDynamicObject(2676, gFarmerTrackCpX[trackId][cpId]+float(random(5))/10.0, gFarmerTrackCpY[trackId][cpId]+float(random(5))/10.0, gFarmerTrackCpZ[trackId][cpId]-0.5, 0.0, 0.0, 0.0, 0, 0);
			// case 4:
				// gFarmerTrackCpTrashId[trackId][cpId] = CreateDynamicObject(2672, gFarmerTrackCpX[trackId][cpId]+float(random(5))/10.0, gFarmerTrackCpY[trackId][cpId]+float(random(5))/10.0, gFarmerTrackCpZ[trackId][cpId]-0.4, 0.0, 0.0, 0.0, 0, 0);
			// case 5:
				// gFarmerTrackCpTrashId[trackId][cpId] = CreateDynamicObject(2673, gFarmerTrackCpX[trackId][cpId]+float(random(5))/10.0, gFarmerTrackCpY[trackId][cpId]+float(random(5))/10.0, gFarmerTrackCpZ[trackId][cpId]-0.5, 0.0, 0.0, 0.0, 0, 0);
			// case 6:
				// gFarmerTrackCpTrashId[trackId][cpId] = CreateDynamicObject(2674, gFarmerTrackCpX[trackId][cpId]+float(random(5))/10.0, gFarmerTrackCpY[trackId][cpId]+float(random(5))/10.0, gFarmerTrackCpZ[trackId][cpId]-0.5, 0.0, 0.0, 0.0, 0, 0);
			// case 7:
				// gFarmerTrackCpTrashId[trackId][cpId] = CreateDynamicObject(2675, gFarmerTrackCpX[trackId][cpId]+float(random(5))/10.0, gFarmerTrackCpY[trackId][cpId]+float(random(5))/10.0, gFarmerTrackCpZ[trackId][cpId]-0.6, 0.0, 0.0, 0.0, 0, 0);
			// case 8:
				// gFarmerTrackCpTrashId[trackId][cpId] = CreateDynamicObject(2677, gFarmerTrackCpX[trackId][cpId]+float(random(5))/10.0, gFarmerTrackCpY[trackId][cpId]+float(random(5))/10.0, gFarmerTrackCpZ[trackId][cpId]-0.4, 0.0, 0.0, 0.0, 0, 0);
			// case 9:
				// gFarmerTrackCpTrashId[trackId][cpId] = CreateDynamicObject(18862, gFarmerTrackCpX[trackId][cpId]+float(random(5))/10.0, gFarmerTrackCpY[trackId][cpId]+float(random(5))/10.0, gFarmerTrackCpZ[trackId][cpId]-0.5, 0.0, 0.0, 0.0, 0, 0);
		// }
	// }
// }
	
/*
* Purpose:
*				Return number of points required to gain next level in bus job.
*/
playerNextLvlFarmerPoints(playerid)
{
	return 50*10*floatround(floatpower(2, gPlayerData[playerid][pFarmerJobLvl])); // 50 to jest œrednia liczba cp na danej trasie a 10 to liczba z ksiezyca naszej ziemi, dalej to zagadka dla ciebie
}

Float:FarmerCashForCheckpoint(playerid)
{
	switch(gPlayerData[playerid][pFarmerJobLvl])
	{
		case 1: return 3.0;
		case 2: return 4.0;
		case 3: return 5.0;
		case 4: return 6.0;
		case 5: return 7.0;
		default: return 3.0;
	}
	return 0.0;
}

farmerCheckpoints(i)
{
	new enginedyn, lights, alarm, doors, bonnet, boot, objective;
	new string[128];
	new vehicleID = GetPlayerVehicleID(i);
	new Float:vehicleHealth; // used for storage of vehicle health
	if(gPlayerData[i][pFarmerJobPoints] == (playerNextLvlFarmerPoints(i)))
	{
		if(gPlayerData[i][pFarmerJobLvl] >= 20)
		{
			gPlayerData[i][pFarmerJobLvl] = 20;
			gPlayerData[i][pFarmerJobPoints] = playerNextLvlFarmerPoints(i);
			SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pFarmerJobPoints]));
			UpdateProgressBar(JobProgress[i], i);
			SavePlayerData(i, "FarmerJobLvl");
			SavePlayerData(i, "FarmerJobPoints");
		}
		else
		{
			SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pFarmerJobPoints]));
			UpdateProgressBar(JobProgress[i], i);
			gPlayerData[i][pFarmerJobLvl]++;
			gPlayerData[i][pExp]++;
			gPlayerData[i][pFarmerJobPoints] = 0;
			
			SavePlayerData(i, "FarmerJobLvl");
			SavePlayerData(i, "Exp");
			SavePlayerData(i, "FarmerJobPoints");
			
			SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pFarmerJobPoints]));
			UpdateProgressBar(JobProgress[i], i);
			format(string, sizeof(string), "[INFO:] Osi¹gn¹³eœ %d poziom jako kierowca œmieciarki !", gPlayerData[i][pFarmerJobLvl]);
			SendClientMessage(i, COLOR_LIGHTYELLOW2, string);
		}
	}
	GetVehicleHealth(vehicleID, vehicleHealth);
	if(vehicleHealth <= 700.0 && gVehHealthOnPlayerEnter[i] > 700.0 && gFarmerDriverPenaltyInformed[i] == 0 && IsPlayerInAnyVehicle(i) && gVehData[vehicleID-1][mVehType] == 2)
	{
		gPlayerData[i][pCost] += BUS_PENALTY_COST;
		gFarmerDriverPenaltyInformed[i] = 1;
		gPlayerData[i][pFarmerJobPoints] -= 2;
		
		SavePlayerData(i, "Cost");
		SavePlayerData(i, "FarmerJobPoints");
		
		SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pFarmerJobPoints]));
		UpdateProgressBar(JobProgress[i], i);
		format(string, sizeof(string), "[INFO:] Zosta³eœ ukarany grzywn¹ w wysokoœci %s$ za nieostro¿n¹ jazde", BUS_PENALTY_COST);
		SendClientMessage(i, COLOR_LIGHTYELLOW2, string);
		SendClientMessage(i, COLOR_LIGHTYELLOW2, "[INFO:] Kara zostanie automatycznie pobrana przy nastêpnej wyp³acie");
		SendClientMessage(i, COLOR_LIGHTYELLOW2, "[INFO:] Tracisz tak¿e 2pkt pracy");
	}
	if(EnteredVehicleID[i] == GetPlayerVehicleID(i))
	{
		if(gFarmerTrackCpType[gFarmerDriverSelectedLine[i]][gFarmerDriverCurrentCheckPoint[i]] == 0 && gFarmerDriverJustStarted[i])
		{
			gFarmerDriverPaymentCount[i] = 0;
			gFarmerDriverCurrentCheckPoint[i] = 0;
			gFarmerDriverCheckpointTime[i] = gFarmerTrackCpTime[gFarmerDriverSelectedLine[i]][gFarmerDriverCurrentCheckPoint[i]];
			gFarmerDriverJustStarted[i] = 0;			
			gJobProfit[i] = 0;
			SetPlayerCheckpoint(i, gFarmerTrackCpX[gFarmerDriverSelectedLine[i]][gFarmerDriverCurrentCheckPoint[i]], gFarmerTrackCpY[gFarmerDriverSelectedLine[i]][gFarmerDriverCurrentCheckPoint[i]], gFarmerTrackCpZ[gFarmerDriverSelectedLine[i]][gFarmerDriverCurrentCheckPoint[i]], 5.0);
		}
		if((gFarmerTrackCpType[gFarmerDriverSelectedLine[i]][gFarmerDriverCurrentCheckPoint[i]] == 1 || gFarmerTrackCpType[gFarmerDriverSelectedLine[i]][gFarmerDriverCurrentCheckPoint[i]] == 0) && IsPlayerInRangeOfPoint(i, 5.0, gFarmerTrackCpX[gFarmerDriverSelectedLine[i]][gFarmerDriverCurrentCheckPoint[i]], gFarmerTrackCpY[gFarmerDriverSelectedLine[i]][gFarmerDriverCurrentCheckPoint[i]], gFarmerTrackCpZ[gFarmerDriverSelectedLine[i]][gFarmerDriverCurrentCheckPoint[i]]))
		{
			gFarmerDriverCheckpointTime[i]--;
			if(gFarmerDriverCheckpointTime[i] > 0)
			{
				format(string, sizeof(string), JOB_BUS_DEP_TIME_LEFT, gFarmerDriverCheckpointTime[i]);
				GameTextForPlayer(i, string, JOB_BUS_TXT_SHOW_TIME, GAME_TEXT_STYLE_4);
			}
			else
			{
				if(gFarmerTrackCpTrashEnabled[gFarmerDriverSelectedLine[i]][gFarmerDriverCurrentCheckPoint[i]] == 1)
				{
					gFarmerTrackCpTrashEnabled[gFarmerDriverSelectedLine[i]][gFarmerDriverCurrentCheckPoint[i]] = 0;
					DestroyDynamicObject(gFarmerTrackCpTrashId[gFarmerDriverSelectedLine[i]][gFarmerDriverCurrentCheckPoint[i]]);
				}
				gPlayerData[i][pFarmerJobPoints]++;
				SavePlayerData(i, "FarmerJobPoints");
				SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pFarmerJobPoints]));
				UpdateProgressBar(JobProgress[i], i);
				gJobProfit[i] += FarmerCashForCheckpoint(i);
				
				gFarmerDriverCurrentCheckPoint[i]++;
				gFarmerDriverCheckpointTime[i] = gFarmerTrackCpTime[gFarmerDriverSelectedLine[i]][gFarmerDriverCurrentCheckPoint[i]];
				SetPlayerCheckpoint(i, gFarmerTrackCpX[gFarmerDriverSelectedLine[i]][gFarmerDriverCurrentCheckPoint[i]], gFarmerTrackCpY[gFarmerDriverSelectedLine[i]][gFarmerDriverCurrentCheckPoint[i]], gFarmerTrackCpZ[gFarmerDriverSelectedLine[i]][gFarmerDriverCurrentCheckPoint[i]], 5.0);				
			}
		}
		else if(gFarmerTrackCpType[gFarmerDriverSelectedLine[i]][gFarmerDriverCurrentCheckPoint[i]] == 2 && IsPlayerInRangeOfPoint(i, 5.0, gFarmerTrackCpX[gFarmerDriverSelectedLine[i]][gFarmerDriverCurrentCheckPoint[i]], gFarmerTrackCpY[gFarmerDriverSelectedLine[i]][gFarmerDriverCurrentCheckPoint[i]], gFarmerTrackCpZ[gFarmerDriverSelectedLine[i]][gFarmerDriverCurrentCheckPoint[i]]))
		{
			GivePlayerCash(i, floatround(gJobProfit[i], floatround_round));
			DynamicFactions[FACTIONID_GOVERNMENT][fBank] -= floatround(gJobProfit[i], floatround_round);
			SaveFData(FACTIONID_GOVERNMENT, "Bank");
		
			format(string, sizeof(string), "[INFO:] Zarobi³eœ za tê trase %d$", floatround(gJobProfit[i],floatround_round));
			SendClientMessage(i, COLOR_LIGHTYELLOW2, string);
			
			gFarmerDriverOnDuty[i] = 0;
			DisablePlayerCheckpoint(i);			
			RemovePlayerFromVehicle(i);		
			HideProgressBarForPlayer(i, JobProgress[i]);
			gFarmerDriverCurrentCheckPoint[i] = 0;
			
			UpdateDynamic3DTextLabelText(BusRoute[vehicleID-1], COLOR_LIGHTYELLOW, " ");
			SetVehicleToRespawnEx(vehicleID);
			GetVehicleParamsEx(vehicleID, enginedyn, lights, alarm, doors, bonnet, boot, objective);
			SetVehicleParamsEx(vehicleID,0,lights,alarm,doors,bonnet,boot,objective);
			gVehData[vehicleID-1][EngineOn] = 0;
			SaveVehData(vehicleID-1, "EngineOn");
			gVehData[vehicleID-1][CarFuel] = float(VehFTank(vehicleID));
			SaveVehData(vehicleID-1, "CarFuel");			
		}
	}
}