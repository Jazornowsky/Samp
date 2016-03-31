/***
* wp_buscheckpoints.inc - Handle rewards, experience gain, etc. for driving
*											through bus checkpoints.
*
*							Made by Damian Wojdat
*
*Last modified:
*						17-06-2011
*
*************************************************************************************************************/

/*
* Purpose:
*				Return number of points required to gain next level in bus job.
*/
playerNextLvlBusPoints(playerid)
{
	return ( (gPlayerData[playerid][pJobLvl]*30) + (gPlayerData[playerid][pJobLvl]*10) );
}

busCheckpoints(i)
{
	new enginedyn, lights, alarm, doors, bonnet, boot, objective;
	new string[128];
	new vehicleID = GetPlayerVehicleID(i);
	new Float:vehicleHealth; // used for storage of vehicle health
	if(gPlayerData[i][pBusJobPoints] == ( playerNextLvlBusPoints(i)))
	{
		if(gPlayerData[i][pJobLvl] >= 20)
		{
			gPlayerData[i][pJobLvl] = 20;
			gPlayerData[i][pBusJobPoints] = playerNextLvlBusPoints(i);
			SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pBusJobPoints]));
			UpdateProgressBar(JobProgress[i], i);
			SavePlayerData(i, "JobLvl");
			SavePlayerData(i, "BusJobPoints");
		}
		else
		{
			SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pBusJobPoints]));
			UpdateProgressBar(JobProgress[i], i);
			gPlayerData[i][pJobLvl]++;
			gPlayerData[i][pExp]++;
			gPlayerData[i][pBusJobPoints] = 0;
			
			SavePlayerData(i, "JobLvl");
			SavePlayerData(i, "Exp");
			SavePlayerData(i, "BusJobPoints");
			
			SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pBusJobPoints]));
			UpdateProgressBar(JobProgress[i], i);
			format(string, sizeof(string), "[INFO:] Osi¹gn¹³eœ %d poziom jako kierowca autobusu !", gPlayerData[i][pJobLvl]);
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
	if(vehicleHealth <= 700.0 && gVehHealthOnPlayerEnter[i] > 700.0 && gBusDriverPenaltyInformed[i] == 0 && IsPlayerInAnyVehicle(i) && gVehData[vehicleID-1][CarType] == 2)
	{
		gPlayerData[i][pCost] += BUS_PENALTY_COST;
		gBusDriverPenaltyInformed[i] = 1;
		gPlayerData[i][pBusJobPoints] -= 2;
		
		SavePlayerData(i, "Cost");
		SavePlayerData(i, "BusJobPoints");
		
		SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pBusJobPoints]));
		UpdateProgressBar(JobProgress[i], i);
		format( string, sizeof(string), "[INFO:] Zosta³eœ ukarany grzywn¹ w wysokoœci %s$ za nieostro¿n¹ jazde", BUS_PENALTY_COST);
		SendClientMessage(i, COLOR_LIGHTYELLOW2, string);
		SendClientMessage(i, COLOR_LIGHTYELLOW2, "[INFO:] Kara zostanie automatycznie pobrana przy nastêpnej wyp³acie");
		SendClientMessage(i, COLOR_LIGHTYELLOW2, "[INFO:] Tracisz tak¿e 2pkt pracy");
	}
	if(EnteredVehicleID[i] == GetPlayerVehicleID(i))
	{
		if( gBusTrackCPType[ gBusDriverSelectedLine[i] ][ gBusDriverCurrentCheckPoint[i] ] == 0 && gBusDriverJustStarted[i] )
		{
			gBusDriverPaymentCount[i] = 0;
			gBusDriverCurrentCheckPoint[i] = 0;
			gBusDriverCheckpointTime[i] = gBusTrackCPTime[ gBusDriverSelectedLine[i] ][ gBusDriverCurrentCheckPoint[i] ];
			gBusDriverJustStarted[i] = 0;			
			gJobProfit[i] = 0;
			SetPlayerCheckpoint(i, gBusTrackCPX[ gBusDriverSelectedLine[i] ][ gBusDriverCurrentCheckPoint[i] ], gBusTrackCPY[ gBusDriverSelectedLine[i] ][ gBusDriverCurrentCheckPoint[i] ], gBusTrackCPZ[ gBusDriverSelectedLine[i] ][ gBusDriverCurrentCheckPoint[i] ], 5.0);
		}
		if( ( gBusTrackCPType[ gBusDriverSelectedLine[i] ][ gBusDriverCurrentCheckPoint[i] ] == 1 || gBusTrackCPType[ gBusDriverSelectedLine[i] ][ gBusDriverCurrentCheckPoint[i] ] == 0 ) && IsPlayerInRangeOfPoint(i, 5.0, gBusTrackCPX[ gBusDriverSelectedLine[i] ][ gBusDriverCurrentCheckPoint[i] ], gBusTrackCPY[ gBusDriverSelectedLine[i] ][ gBusDriverCurrentCheckPoint[i] ], gBusTrackCPZ[ gBusDriverSelectedLine[i] ][ gBusDriverCurrentCheckPoint[i] ] ) )
		{
			gBusDriverCheckpointTime[i]--;
			if(gBusDriverCheckpointTime[i] > 0)
			{
				format(string, sizeof(string), JOB_BUS_DEP_TIME_LEFT, gBusDriverCheckpointTime[i]);
				GameTextForPlayer(i, string, JOB_BUS_TXT_SHOW_TIME, GAME_TEXT_STYLE_4);
			}
			else
			{
				gPlayerData[i][pBusJobPoints]++;
				SavePlayerData(i, "BusJobPoints");
				SetProgressBarValue(JobProgress[i], float(gPlayerData[i][pBusJobPoints]));
				UpdateProgressBar(JobProgress[i], i);
				gJobProfit[i] += floatpower(gPlayerData[i][pJobLvl],gBusDriverPaymentMultiplier) + floatpower(gBusTrackCPReward[ gBusDriverSelectedLine[i] ][ gBusDriverCurrentCheckPoint[i] ], gBusDriverPaymentMultiplier);
				
				gBusDriverCurrentCheckPoint[i]++;
				gBusDriverCheckpointTime[i] = gBusTrackCPTime[ gBusDriverSelectedLine[i] ][ gBusDriverCurrentCheckPoint[i] ];
				SetPlayerCheckpoint(i, gBusTrackCPX[ gBusDriverSelectedLine[i] ][ gBusDriverCurrentCheckPoint[i] ], gBusTrackCPY[ gBusDriverSelectedLine[i] ][ gBusDriverCurrentCheckPoint[i] ], gBusTrackCPZ[ gBusDriverSelectedLine[i] ][ gBusDriverCurrentCheckPoint[i] ], 5.0);				
			}
		}
		else if( gBusTrackCPType[ gBusDriverSelectedLine[i] ][ gBusDriverCurrentCheckPoint[i] ] == 2 && IsPlayerInRangeOfPoint(i, 5.0, gBusTrackCPX[ gBusDriverSelectedLine[i] ][ gBusDriverCurrentCheckPoint[i] ], gBusTrackCPY[ gBusDriverSelectedLine[i] ][ gBusDriverCurrentCheckPoint[i] ], gBusTrackCPZ[ gBusDriverSelectedLine[i] ][ gBusDriverCurrentCheckPoint[i] ] ) )
		{
			GivePlayerCash(i, floatround(gJobProfit[i], floatround_round));
			DynamicFactions[FACTIONID_GOVERNMENT][fBank] -= floatround(gJobProfit[i], floatround_round);
			SaveFData(FACTIONID_GOVERNMENT, "Bank");
		
			format(string, sizeof(string), "[INFO:] Zarobi³eœ za tê trase %d$", floatround(gJobProfit[i],floatround_round));
			SendClientMessage(i, COLOR_LIGHTYELLOW2, string);
			
			gBusDriverOnDuty[i] = 0;
			DisablePlayerCheckpoint(i);			
			RemovePlayerFromVehicle(i);		
			HideProgressBarForPlayer(i, JobProgress[i]);
			gBusDriverCurrentCheckPoint[i] = 0;
			
			UpdateDynamic3DTextLabelText(BusRoute[vehicleID-1], COLOR_LIGHTYELLOW, " ");
			SetVehicleToRespawn(vehicleID);
			GetVehicleParamsEx(vehicleID, enginedyn, lights, alarm, doors, bonnet, boot, objective);
			SetVehicleParamsEx(vehicleID,0,lights,alarm,doors,bonnet,boot,objective);
			gVehData[vehicleID-1][EngineOn] = 0;
			SaveVehData( vehicleID-1, "EngineOn" );
			gVehData[vehicleID-1][CarFuel] = float(VehFTank(vehicleID));
			SaveVehData( vehicleID-1, "CarFuel" );			
		}
	}
}