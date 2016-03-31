/***
*
* File: wp_trashcheckpoints.inc
* Auth: Damian Wojdat
* Date: 14.05.2012
* Desc: Handle rewards, experience gain, etc. for driving through trash checkpoints.
*
*************************************************************************************************************/

GenerateTrashObjectsForTrash()
{
	new trashCount = random(5);
	new i = 0;
	new trackId, cpId, tries;
	while(i < trashCount && tries < 200)
	{
		tries++;
		trackId = random(sizeof(gTrashTrackEnabled));
		if(!gTrashTrackEnabled[trackId])
			continue;
		cpId = random(sizeof(gTrashTrackEnabled));
		if(gTrashTrackCpType[trackId][cpId] == 0 && gTrashTrackCpType[trackId][cpId] == 2 && (gTrashTrackCpX[trackId][cpId] != 0.0 || gTrashTrackCpY[trackId][cpId] != 0.0))
			continue;
		if(gTrashTrackCpTime[trackId][cpId] == 0)
			continue;
		if(gTrashTrackCpTrashEnabled[trackId][cpId] == 1)
			continue;
		gTrashTrackCpTrashEnabled[trackId][cpId] = 1;
		gTrashTrackCpTrashId[trackId][cpId] = CreateDynamicObject(1343, gTrashTrackCpX[trackId][cpId], gTrashTrackCpY[trackId][cpId], gTrashTrackCpZ[trackId][cpId]-0.75, 0.0, 0.0, 0.0, 0, 0);
		i++;
	}
}
	
/*
* Purpose:
*				Return number of points required to gain next level in bus job.
*/
playerNextLvlTrashPoints(playerid)
{
	return 24*10*floatround(floatpower(3, gPlayerData[playerid][pMzgkJobLvl])); // 50 to jest œrednia liczba cp na danej trasie a 10 to liczba z ksiezyca naszej ziemi, dalej to zagadka dla ciebie
}

Float:TrashCashForCheckpoint(playerid)
{
	switch(gPlayerData[playerid][pMzgkJobLvl])
	{
		case 1: return 9.0;
		case 2: return 14.0;
		case 3: return 19.0;
		case 4: return 24.0;
		case 5: return 29.0;
		default: return 9.0;
	}
	return 0.0;
}

trashCheckpoints(i)
{
	new enginedyn, lights, alarm, doors, bonnet, boot, objective;
	new string[128];
	new vehicleID = GetPlayerVehicleID(i);
	new Float:vehicleHealth; // used for storage of vehicle health
	if(gPlayerData[i][pMzgkJobPoints] == ( playerNextLvlTrashPoints(i)))
	{
		if(gPlayerData[i][pMzgkJobLvl] >= 5)
		{
			gPlayerData[i][pMzgkJobLvl] = 5;
			gPlayerData[i][pMzgkJobPoints] = playerNextLvlTrashPoints(i);
			SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pMzgkJobPoints]));
			UpdateProgressBar(JobProgress[i], i);
			SavePlayerData(i, "MzgkJobLvl");
			SavePlayerData(i, "MzgkJobPoints");
		}
		else
		{
			SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pMzgkJobPoints]));
			UpdateProgressBar(JobProgress[i], i);
			gPlayerData[i][pMzgkJobLvl]++;
			gPlayerData[i][pExp]++;
			gPlayerData[i][pMzgkJobPoints] = 0;
			
			SavePlayerData(i, "MzgkJobLvl");
			SavePlayerData(i, "Exp");
			SavePlayerData(i, "MzgkJobPoints");
			
			SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pMzgkJobPoints]));
			UpdateProgressBar(JobProgress[i], i);
			format(string, sizeof(string), "[INFO:] Osi¹gn¹³eœ %d poziom jako kierowca œmieciarki !", gPlayerData[i][pMzgkJobLvl]);
			SendClientMessage(i, COLOR_LIGHTYELLOW2, string);
		}
	}
	GetVehicleHealth(vehicleID, vehicleHealth);
	if(vehicleHealth-gVehHealthOnPlayerEnter[i] < -300.0 && gVehHealthOnPlayerEnter[i] > 300.0 && gTrashDriverPenaltyInformed[i] == 0 && IsPlayerInAnyVehicle(i) && gVehData[vehicleID-1][mVehType] == 2)
	{
		gPlayerData[i][pCost] += BUS_PENALTY_COST;
		gTrashDriverPenaltyInformed[i] = 1;
		gPlayerData[i][pMzgkJobPoints] -= 2;
		
		SavePlayerData(i, "Cost");
		SavePlayerData(i, "MzgkJobPoints");
		
		SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pMzgkJobPoints]));
		UpdateProgressBar(JobProgress[i], i);
		format( string, sizeof(string), "[INFO:] Zosta³eœ ukarany grzywn¹ w wysokoœci $%d za nieostro¿n¹ jazde", BUS_PENALTY_COST);
		SendClientMessage(i, COLOR_LIGHTYELLOW2, string);
		SendClientMessage(i, COLOR_LIGHTYELLOW2, "[INFO:] Kara zostanie automatycznie pobrana przy nastêpnej wyp³acie");
		SendClientMessage(i, COLOR_LIGHTYELLOW2, "[INFO:] Tracisz tak¿e 2pkt pracy");
	}
	if(EnteredVehicleID[i] == GetPlayerVehicleID(i))
	{
		if( gTrashTrackCpType[ gTrashDriverSelectedLine[i] ][ gTrashDriverCurrentCheckPoint[i] ] == 0 && gTrashDriverJustStarted[i] )
		{
			gTrashDriverPaymentCount[i] = 0;
			gTrashDriverCurrentCheckPoint[i] = 0;
			gTrashDriverCheckpointTime[i] = gTrashTrackCpTime[ gTrashDriverSelectedLine[i] ][ gTrashDriverCurrentCheckPoint[i] ];
			gTrashDriverJustStarted[i] = 0;			
			gJobProfit[i] = 0;
			SetPlayerCheckpoint(i, gTrashTrackCpX[ gTrashDriverSelectedLine[i] ][ gTrashDriverCurrentCheckPoint[i] ], gTrashTrackCpY[ gTrashDriverSelectedLine[i] ][ gTrashDriverCurrentCheckPoint[i] ], gTrashTrackCpZ[ gTrashDriverSelectedLine[i] ][ gTrashDriverCurrentCheckPoint[i] ], 5.0);
		}
		if( ( gTrashTrackCpType[ gTrashDriverSelectedLine[i] ][ gTrashDriverCurrentCheckPoint[i] ] == 1 || gTrashTrackCpType[ gTrashDriverSelectedLine[i] ][ gTrashDriverCurrentCheckPoint[i] ] == 0 ) && IsPlayerInRangeOfPoint(i, 5.0, gTrashTrackCpX[ gTrashDriverSelectedLine[i] ][ gTrashDriverCurrentCheckPoint[i] ], gTrashTrackCpY[ gTrashDriverSelectedLine[i] ][ gTrashDriverCurrentCheckPoint[i] ], gTrashTrackCpZ[ gTrashDriverSelectedLine[i] ][ gTrashDriverCurrentCheckPoint[i] ] ) )
		{
			gTrashDriverCheckpointTime[i]--;
			if(gTrashDriverCheckpointTime[i] > 0)
			{
				format(string, sizeof(string), JOB_BUS_DEP_TIME_LEFT, gTrashDriverCheckpointTime[i]);
				GameTextForPlayer(i, string, JOB_BUS_TXT_SHOW_TIME, GAME_TEXT_STYLE_4);
			}
			else
			{
				if(gTrashTrackCpTrashEnabled[gTrashDriverSelectedLine[i]][gTrashDriverCurrentCheckPoint[i]] == 1)
				{
					gTrashTrackCpTrashEnabled[gTrashDriverSelectedLine[i]][gTrashDriverCurrentCheckPoint[i]] = 0;
					DestroyDynamicObject(gTrashTrackCpTrashId[gTrashDriverSelectedLine[i]][gTrashDriverCurrentCheckPoint[i]]);
				}
				gPlayerData[i][pMzgkJobPoints]++;
				SavePlayerData(i, "MzgkJobPoints");
				SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pMzgkJobPoints]));
				UpdateProgressBar(JobProgress[i], i);
				gJobProfit[i] += TrashCashForCheckpoint(i);
				
				gTrashDriverCurrentCheckPoint[i]++;
				gTrashDriverCheckpointTime[i] = gTrashTrackCpTime[ gTrashDriverSelectedLine[i] ][ gTrashDriverCurrentCheckPoint[i] ];
				SetPlayerCheckpoint(i, gTrashTrackCpX[ gTrashDriverSelectedLine[i] ][ gTrashDriverCurrentCheckPoint[i] ], gTrashTrackCpY[ gTrashDriverSelectedLine[i] ][ gTrashDriverCurrentCheckPoint[i] ], gTrashTrackCpZ[ gTrashDriverSelectedLine[i] ][ gTrashDriverCurrentCheckPoint[i] ], 5.0);				
			}
		}
		else if( gTrashTrackCpType[ gTrashDriverSelectedLine[i] ][ gTrashDriverCurrentCheckPoint[i] ] == 2 && IsPlayerInRangeOfPoint(i, 5.0, gTrashTrackCpX[ gTrashDriverSelectedLine[i] ][ gTrashDriverCurrentCheckPoint[i] ], gTrashTrackCpY[ gTrashDriverSelectedLine[i] ][ gTrashDriverCurrentCheckPoint[i] ], gTrashTrackCpZ[ gTrashDriverSelectedLine[i] ][ gTrashDriverCurrentCheckPoint[i] ] ) )
		{
			GivePlayerCash(i, floatround(gJobProfit[i], floatround_round));
			DynamicFactions[FACTIONID_GOVERNMENT][fBank] -= floatround(gJobProfit[i], floatround_round);
			SaveFData(FACTIONID_GOVERNMENT, "Bank");
		
			format(string, sizeof(string), "[INFO:] Zarobi³eœ za tê trase $%d", floatround(gJobProfit[i],floatround_round));
			SendClientMessage(i, COLOR_LIGHTYELLOW2, string);
			
			gTrashDriverOnDuty[i] = 0;
			DisablePlayerCheckpoint(i);			
			RemovePlayerFromVehicle(i);		
			HideProgressBarForPlayer(i, JobProgress[i]);
			gTrashDriverCurrentCheckPoint[i] = 0;
			
			SetVehicleToRespawnEx(vehicleID);
			GetVehicleParamsEx(vehicleID, enginedyn, lights, alarm, doors, bonnet, boot, objective);
			SetVehicleParamsEx(vehicleID, 0, 0, alarm, doors, bonnet, boot, objective);
			gVehData[vehicleID-1][LightsOn] = 0;
			gVehData[vehicleID-1][EngineOn] = 0;
			gVehData[vehicleID-1][CarFuel] = float(VehFTank(vehicleID));		
		}
	}
}