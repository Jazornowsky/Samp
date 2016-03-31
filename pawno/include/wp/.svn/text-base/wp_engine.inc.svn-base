Delay:Engine[ENGINE_STARTUP_TIME, i](playerid)
{
	// if(gVehData[GetPlayerVehicleID(playerid)-1][EngineOn] == 0)
	// {
	new carid = GetPlayerVehicleID(playerid);
	EngineTurningOn[playerid] = 0;
	if( carid != INVALID_VEHICLE_ID )
	{
		if(gVehData[carid-1][CarFuel] > 0.5)
		{
			if( gVehData[carid-1][CarType] == 0 )
			{
				gVehData[carid-1][BatteryCapacity]-= 1.0;
				SaveVehData(carid-1, "BatteryCapacity");
			}
			new enginedyn,lights,alarm,bonnet,boot,objective,doors;
			GetVehicleParamsEx(carid, enginedyn, lights, alarm, doors, bonnet, boot, objective);
			SetVehicleParamsEx(carid,1,lights,alarm,doors,bonnet,boot,objective);
			gVehData[carid-1][EngineOn] = 1;
			SendClientMessage(playerid, COLOR_GREEN,"[STATUS:] Silnik uruchomiony");
			SaveVehData(carid-1, "EngineOn");
			return 1;
		}
	}
	SendClientMessage(playerid, COLOR_GREEN,"[STATUS:] Nie uda³o siê odpaliæ silnika");
	// }
	return 1;
}

Delay:EngineNoKey[ENGINE_NO_KEY_TIME, i](playerid)
{
	if(gVehData[GetPlayerVehicleID(playerid)-1][EngineOn] == 0)
	{
		new string[128], tmprandom;
		new carid = GetPlayerVehicleID(playerid);
		tmprandom = random(200);
		EngineTurningOn[playerid] = 0;
		if(tmprandom > 190 && tmprandom < 199)
		{
			if( gVehData[carid-1][CarType] == 0 )
			{
				gVehData[carid-1][BatteryCapacity]-= 1.0;
				SaveVehData(carid-1, "BatteryCapacity");
			}
			new enginedyn,lights,alarm,bonnet,boot,objective,doors;
			GetVehicleParamsEx(carid,enginedyn,lights,alarm,doors,bonnet,boot,objective);
			SetVehicleParamsEx(carid,1,lights,alarm,doors,bonnet,boot,objective);
			gVehData[carid-1][EngineOn] = 1;
			gPlayerData[playerid][pCarJackerJobPoints]++;
			SendClientMessage(playerid, COLOR_GREEN,"[STATUS:] Silnik uruchomiony");
			if(gPlayerData[playerid][pCarJackerJobPoints] == 20 + (gPlayerData[playerid][pCarJackerJobLvl]*10))
			{
				gPlayerData[playerid][pCarJackerJobLvl]++;
				gPlayerData[playerid][pExp]++;
				gPlayerData[playerid][pCarJackerJobPoints] = 0;

				SavePlayerData(playerid, "CarJackerJobLvl");
				SavePlayerData(playerid, "CarJakcerJobPoints");

				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] Osi¹gn¹³eœ %d poziom jako z³odziej pojazdów !");
				if(gPlayerData[playerid][pExp] >= (gPlayerData[playerid][pLevel]+1)*levelexp)
				{
					gPlayerData[playerid][pLevel]++;
					gPlayerData[playerid][pExp] = 0;

					SavePlayerData(playerid, "Level");

					format(string, sizeof(string), "[INFO:] Zdoby³eœ tak¿e nowy poziom postaci ! - %d", gPlayerData[playerid][pLevel]);
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Otrzymujesz tak¿e 1pkt do doœwiadczenia postaci");
				}
				SavePlayerData(playerid, "Exp");
			}
		}
		else
			SendClientMessage(playerid, COLOR_GREEN,"[STATUS:] Nie uda³o Ci siê odpaliæ silnika");
	}
	return 1;
}

Delay:EngineInfo[ENGINE_INFO_TIME, i](playerid)
{
	EngineTurningOn[playerid] = 0;
	return 1;
}
