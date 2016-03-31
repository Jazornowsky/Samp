public OnUnoccupiedVehicleUpdate(vehicleid, playerid, passenger_seat)
{
	if( gVehPosCheckCooldown[playerid] == 0 )
	{
		new string[MAX_PLAYER_NAME];
		GetPlayerName(playerid, string, sizeof(string));
		printf("[WARNING:] Player %s [id %d] pushed vehicle %d", string, playerid, vehicleid);
		gVehPosCheckCooldown[playerid] = 3;
	}
	return 1;
}

public OnVehicleSpawn(vehicleid)
{
	new enginedyn,lights,alarm,doors,bonnet,boot,objective,lightsd;
	/* Return vehicle HP and visual status */
	if(gVehData[vehicleid-1][CarLights] == 4)
		lightsd = 100;
	if(gVehData[vehicleid-1][CarLights] == 5)
		lightsd = 101;
	if(gVehData[vehicleid-1][CarLights] == 1)
		lightsd = 1;
	if(gVehData[vehicleid-1][CarLights] == 0)
		lightsd = 0;
	UpdateVehicleDamageStatus(vehicleid, gVehData[vehicleid-1][CarPanels], gVehData[vehicleid-1][CarDoors], lightsd, gVehData[vehicleid-1][CarTires]);
	GetVehicleParamsEx(vehicleid,enginedyn,lights,alarm,doors,bonnet,boot,objective);
	SetVehicleParamsEx(vehicleid,gVehData[vehicleid-1][EngineOn],gVehData[vehicleid-1][LightsOn],0,gVehData[vehicleid-1][Closed],gVehData[vehicleid-1][BonnetUp],gVehData[vehicleid-1][BootUp],objective);
	SetVehicleHealth(vehicleid, gVehData[vehicleid-1][CarHealth]);
	
	new vehid = vehicleid - 1;
	new string[10];
	format(string, sizeof(string), "SF-%d", gVehData[vehid][CarSerial]);
	if(IsAMotorBike(vehicleid) && gVehData[vehid][CarModel] != 522 && gVehData[vehid][CarModel] != 471 && gVehData[vehid][CarModel] != 468)
	{
		SetVehicleNumberPlate(vehicleid, string);
		// UpdateDynamic3DTextLabelText(veh3dserial[vehid], COLOR_WHITE, string);
	}
	if(gVehData[vehid][CarModel] == 522 || gVehData[vehid][CarModel] == 471 || gVehData[vehid][CarModel] == 468)
	{
		UpdateDynamic3DTextLabelText( gVehData[vehid][Veh3DSerial], COLOR_WHITE, string);
	}
	if(IsABoat(vehicleid))
	{
		UpdateDynamic3DTextLabelText( gVehData[vehid][Veh3DSerial], COLOR_WHITE, string);
	}
	if(IsAPlane(vehicleid))
	{
		UpdateDynamic3DTextLabelText( gVehData[vehid][Veh3DSerial], COLOR_WHITE, string);
	}
	if(IsAHelicopter(vehicleid))
	{
		UpdateDynamic3DTextLabelText( gVehData[vehid][Veh3DSerial], COLOR_WHITE, string);
	}
	if(IsABoat(vehicleid) == 0 && IsABike(vehicleid) == 0 && IsAPlane(vehicleid) == 0 && IsAHelicopter(vehicleid) == 0 && IsAMotorBike(vehicleid) == 0)
	{
		SetVehicleNumberPlate(vehicleid, string);
		// UpdateDynamic3DTextLabelText(veh3dserial[vehid], COLOR_WHITE, string);
	}
	if(gVehData[vehicleid-1][CarModel] == 431)
	{
		BusRoute[vehicleid-1] = CreateDynamic3DTextLabel(" ", COLOR_LIGHTYELLOW, 0.8, 5.8, 1, 10.0, INVALID_PLAYER_ID, vehicleid, 1);
	}
	return 1;
}

public OnVehicleDamageStatusUpdate(vehicleid, playerid)
{
	if(gAdminGodMode[playerid])
	{
		RepairVehicle(vehicleid);
		return 1;
	}
	new panels, doors, lights, tires;
	new enginedyn,alarm,bonnet,boot,objective,doorsprm,lightsprm;
	GetVehicleDamageStatus(vehicleid, panels, doors, lights, tires);
	GetVehicleParamsEx(vehicleid, enginedyn, lightsprm, alarm, doorsprm, bonnet, boot, objective);

	gVehData[vehicleid-1][CarPanels] = panels;
	gVehData[vehicleid-1][CarDoors] = doors;
	gVehData[vehicleid-1][CarLights] = lights;
	gVehData[vehicleid-1][CarTires] = tires;

	SaveVehData(vehicleid-1, "CarPanels");
	SaveVehData(vehicleid-1, "CarDoors");
	SaveVehData(vehicleid-1, "CarLights");
	SaveVehData(vehicleid-1, "CarTires");
	
	return 1;
}

public OnVehicleDeath(vehicleid, killerid)
{
	SetTimerEx("ResetVehicleData",5000,0,"dd",vehicleid,0);
	new Year, Month, Day;
	new Float:x, Float:y, Float:z;
	getdate(Year, Month, Day);
	new string[512];
	format(string, sizeof(string), "[%d-%d-%d] [VEHICLE:] Vehicle ID: %d destroyed by %s, Faction: %d, Type: %d, Damaged: %d, CarRepairTimeLeft: %d", Year, Month, Day, vehicleid, GetPlayerNameEx(killerid), gVehData[vehicleid-1][FactionCar], gVehData[vehicleid-1][CarDamaged], gVehData[vehicleid-1][CarRepairTimeLeft]);
	ResetVehicleLog(string);
	format(string, sizeof(string), "[VEHICLE:] CarX: %f, CarY: %f, CarZ: %f, Owned: %d, Owner: %s, CarResetT: %d, BusinessID: %d, CarSerial: %d", gVehData[vehicleid-1][CarX], gVehData[vehicleid-1][CarY], gVehData[vehicleid-1][CarZ], gVehData[vehicleid-1][Owned], gVehData[vehicleid-1][Owner], gVehData[vehicleid-1][CarResetT], gVehData[vehicleid-1][BusinessID], gVehData[vehicleid-1][CarSerial]);
	ResetVehicleLog(string);
	format(string, sizeof(string), "[VEHICLE:] Model: %d", gVehData[vehicleid-1][CarModel]);
	ResetVehicleLog(string);
	GetVehiclePos(vehicleid, x, y, z);
	for(new i = 0; i < CUSTOM_MAX_PLAYERS; i++)
	{
		if(IsPlayerConnected(i))
		{
			if(gPlayerLogged[i])
			{
				if(PlayerToPoint(200.0, i, x, y, z))
				{
					format(string, sizeof(string), "[VEHICLE:] Player name near (200.0) destroyed car: %s (OOC: %s)", gPlayerData[i][pName], gPlayerData[i][pOOCName]);
					ResetVehicleLog(string);
				}
			}
		}
	}
	return 1;
}

public OnVehicleRespray(playerid, vehicleid, color1, color2)
{
	UpdateVehicleDamageStatus(vehicleid, gVehData[vehicleid-1][CarPanels], gVehData[vehicleid-1][CarDoors], gVehData[vehicleid-1][CarLights], gVehData[vehicleid-1][CarTires]);

	vehicleid -= 1;
	gPlayerData[playerid][pCost] += 100;
	gVehData[vehicleid][CarColor1] = color1;
	gVehData[vehicleid][CarColor2] = color2;

	SaveVehData(vehicleid, "CarColor1");
	SaveVehData(vehicleid, "Carcolor2");
	SavePlayerData(playerid, "Cost");
	return 1;
}