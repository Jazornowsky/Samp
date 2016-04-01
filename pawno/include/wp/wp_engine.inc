/***
*
* File: wp_engine.inc
* Auth: Damian Wojdat
* Date: 15.09.2011
* Desc: Vehicle engine on/off functions.
*
*************************************************************************************************************/

timer Engine[ENGINE_STARTUP_TIME](playerid)
{
	// if(gVehData[GetPlayerVehicleID(playerid)-1][EngineOn] == 0)
	// {
	new carid = GetPlayerVehicleID(playerid);
	EngineTurningOn[playerid] = 0;
	if(carid != INVALID_VEHICLE_ID)
	{
		if(gVehData[carid-1][CarFuel] > 0.5)
		{
			if( gVehData[carid-1][mVehType] == 0 )
			{
				gVehData[carid-1][BatteryCapacity]-= 1.0;
				SaveVehData(carid-1, "BatteryCapacity");
			}
			new enginedyn,lights,alarm,bonnet,boot,objective,doors;
			GetVehicleParamsEx(carid, enginedyn, lights, alarm, doors, bonnet, boot, objective);
			SetVehicleParamsEx(carid,1,lights,alarm,doors,bonnet,boot,objective);
			gVehData[carid-1][EngineOn] = 1;
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Silnik uruchomiony");
			SaveVehData(carid-1, "EngineOn");
			return 1;
		}
	}
	SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie uda³o siê odpaliæ silnika");
	// }
	return 1;
}

timer EngineNoKey[ENGINE_NO_KEY_TIME](playerid)
{
	if(gVehData[GetPlayerVehicleID(playerid)-1][EngineOn] == 0)
	{
		new tmprandom;
		new carid = GetPlayerVehicleID(playerid);
		if(!carid)
			return 1;
		tmprandom = random(100);
		EngineTurningOn[playerid] = 0;
		
		if(tmprandom >= 0 && tmprandom <= 30)
		{
			gVehData[carid-1][mVehIgnitionDamaged] = 1;
			SaveVehData(carid-1, "VehIgnitionDamaged");
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Uszkodzi³eœ stacyjke");
		}
		if(tmprandom >= 65 && tmprandom <= 100)
		{
			if( gVehData[carid-1][mVehType] == 0 )
			{
				gVehData[carid-1][BatteryCapacity] -= 1.0;
				SaveVehData(carid-1, "BatteryCapacity");
			}
			new enginedyn,lights,alarm,bonnet,boot,objective,doors;
			GetVehicleParamsEx(carid,enginedyn,lights,alarm,doors,bonnet,boot,objective);
			SetVehicleParamsEx(carid,1,lights,alarm,doors,bonnet,boot,objective);
			
			gVehData[carid-1][EngineOn] = 1;
			
			gPlayerData[playerid][pCarJackerJobPoints]++;
			
			gVehData[carid-1][mVehIgnitionHacked] = 1;
			SaveVehData(carid-1, "VehIgnitionHacked");
			
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Silnik uruchomiony");
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Kradziony pojazd mo¿esz wyeksportowaæ zyskuj¹æ 10%% jego wartoœci");
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Aby dowiedzieæ sie wiêcej wpisz /pomoc eksport");
			
			DynamicFactions[gPlayerData[playerid][pFaction]][mVehicleStealExportTimeLeft] = gVehExport[mTimeBeforeExport];						
			SaveFData(gPlayerData[playerid][pFaction], "VehicleStealExportTimeLeft");
			
			VehInZoneStealTimeLeftSave(carid);
			
			new randomCpId = random(7);
			if(randomCpId == 0)
				DynamicFactions[gPlayerData[playerid][pFaction]][mVehicleStealExportCpId] = gVehExport[mCpId1];
			if(randomCpId == 1)
				DynamicFactions[gPlayerData[playerid][pFaction]][mVehicleStealExportCpId] = gVehExport[mCpId2];
			if(randomCpId == 2)
				DynamicFactions[gPlayerData[playerid][pFaction]][mVehicleStealExportCpId] = gVehExport[mCpId3];
			if(randomCpId == 3)
				DynamicFactions[gPlayerData[playerid][pFaction]][mVehicleStealExportCpId] = gVehExport[mCpId4];
			if(randomCpId == 4)
				DynamicFactions[gPlayerData[playerid][pFaction]][mVehicleStealExportCpId] = gVehExport[mCpId5];
			if(randomCpId == 5)
				DynamicFactions[gPlayerData[playerid][pFaction]][mVehicleStealExportCpId] = gVehExport[mCpId6];
			if(randomCpId == 6)
				DynamicFactions[gPlayerData[playerid][pFaction]][mVehicleStealExportCpId] = gVehExport[mCpId7];
			SaveFData(gPlayerData[playerid][pFaction], "VehicleStealExportCpId");
			if(gPlayerData[playerid][pCarJackerJobPoints] == 20 + (gPlayerData[playerid][pCarJackerJobLvl]*10))
			{
				gPlayerData[playerid][pCarJackerJobLvl]++;
				gPlayerData[playerid][pCarJackerJobPoints] = 0;

				SavePlayerData(playerid, "CarJackerJobLvl");
				SavePlayerData(playerid, "CarJakcerJobPoints");
			}
		}
		else
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie uda³o Ci siê odpaliæ silnika");
	}
	return 1;
}

timer EngineInfo[ENGINE_INFO_TIME](playerid)
{
	EngineTurningOn[playerid] = 0;
	return 1;
}
