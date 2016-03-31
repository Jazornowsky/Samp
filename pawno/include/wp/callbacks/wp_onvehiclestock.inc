/***
*
* File: wp_onvehiclestock.inc
* Auth: Damian Wojdat
* Date: 15.09.2011
* Desc: Vehicle callbacks.
*
*************************************************************************************************************/

public OnUnoccupiedVehicleUpdate(vehicleid, playerid, passenger_seat)
{
	if( gVehPosCheckCooldown[playerid] == 0 )
	{
		new string[256];
		format(string, sizeof(string), "Player %s [%d] pushed vehicle %d", gPlayerData[playerid][pName], playerid, vehicleid);
		VehicleLog(string);
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
	
	if(gVehData[vehicleid-1][mVehPaintJob])
	{
		ChangeVehiclePaintjob(vehicleid, gVehData[vehicleid-1][mVehPaintJob]);
	}
	
	/*if(gVehData[vehicleid-1][mVehModel] != 594)
	{
		if(gVehData[vehicleid-1][mVehSpoiler] != 0)
			AddVehicleComponent(vehicleid, gVehData[vehicleid-1][mVehSpoiler]);
		if(gVehData[vehicleid-1][mVehHood] != 0)
			AddVehicleComponent(vehicleid, gVehData[vehicleid-1][mVehHood]);
		if(gVehData[vehicleid-1][mVehRoof] != 0)
			AddVehicleComponent(vehicleid, gVehData[vehicleid-1][mVehRoof]);
		if(gVehData[vehicleid-1][mVehSideskirt] != 0)
			AddVehicleComponent(vehicleid, gVehData[vehicleid-1][mVehSideskirt]);
		if(gVehData[vehicleid-1][mVehLamps] != 0)
			AddVehicleComponent(vehicleid, gVehData[vehicleid-1][mVehLamps]);
		if(gVehData[vehicleid-1][mVehNitro] != 0)
			AddVehicleComponent(vehicleid, gVehData[vehicleid-1][mVehNitro]);
		if(gVehData[vehicleid-1][mVehExhaust] != 0)
			AddVehicleComponent(vehicleid, gVehData[vehicleid-1][mVehExhaust]);
		if(gVehData[vehicleid-1][mVehWheels] != 0)
			AddVehicleComponent(vehicleid, gVehData[vehicleid-1][mVehWheels]);
		if(gVehData[vehicleid-1][mVehStereo] != 0)
			AddVehicleComponent(vehicleid, gVehData[vehicleid-1][mVehStereo]);
		if(gVehData[vehicleid-1][mVehHydraulics] != 0)
			AddVehicleComponent(vehicleid, gVehData[vehicleid-1][mVehHydraulics]);
		if(gVehData[vehicleid-1][mVehFrontBumper] != 0)
			AddVehicleComponent(vehicleid, gVehData[vehicleid-1][mVehFrontBumper]);
		if(gVehData[vehicleid-1][mVehRearBumper] != 0)
			AddVehicleComponent(vehicleid, gVehData[vehicleid-1][mVehRearBumper]);
		if(gVehData[vehicleid-1][mVehVentLeft] != 0)
			AddVehicleComponent(vehicleid, gVehData[vehicleid-1][mVehVentLeft]);
		if(gVehData[vehicleid-1][mVehVentRight] != 0)
			AddVehicleComponent(vehicleid, gVehData[vehicleid-1][mVehVentRight]);
	}*/
	
	new vehid = vehicleid - 1;
	new string[10];
	format(string, sizeof(string), "SA-%d", gVehData[vehid][CarSerial]);
	if(IsAMotorBike(vehicleid) && gVehData[vehid][mVehModel] != 522 && gVehData[vehid][mVehModel] != 471 && gVehData[vehid][mVehModel] != 468)
	{
		SetVehicleNumberPlate(vehicleid, string);
		// UpdateDynamic3DTextLabelText(veh3dserial[vehid], COLOR_WHITE, string);
	}
	if(gVehData[vehid][mVehModel] == 522 || gVehData[vehid][mVehModel] == 471 || gVehData[vehid][mVehModel] == 468)
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
	if(gVehData[vehicleid-1][mVehModel] == 431)
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
	VehJustRespawned[vehicleid-1] = 20;
	
	if(strlen(gVehData[vehicleid-1][mRenter]))
	{
		UpdatePlayerDataByName(gVehData[vehicleid-1][mRenter], "Bank", -gVehData[vehicleid-1][mRentPenalty]);
	}
	
	// indicators
	if(Indicators_xqz[vehicleid][2]) DestroyObject(Indicators_xqz[vehicleid][2]), DestroyObject(Indicators_xqz[vehicleid][3]),DestroyObject(Indicators_xqz[vehicleid][5]),Indicators_xqz[vehicleid][2]=0;
	if(Indicators_xqz[vehicleid][0]) DestroyObject(Indicators_xqz[vehicleid][0]), DestroyObject(Indicators_xqz[vehicleid][1]),DestroyObject(Indicators_xqz[vehicleid][4]),Indicators_xqz[vehicleid][0]=0;
	
	defer ResetVehicleData(vehicleid, 1);
	
	new Year, Month, Day;
	new Float:x, Float:y, Float:z;
	getdate(Year, Month, Day);
	
	static string[512];
	
	if(killerid != INVALID_PLAYER_ID && killerid != 255)
	{
		format(string, sizeof(string), "[VEHICLE:] Vehicle ID: %d destroyed by %s, Faction: %d, Type: %d, Damaged: %d, CarRepairTimeLeft: %d", vehicleid, GetPlayerNameEx(killerid), gVehData[vehicleid-1][mVehFaction], gVehData[vehicleid-1][CarDamaged], gVehData[vehicleid-1][CarRepairTimeLeft]);
	}
	else
	{
		format(string, sizeof(string), "[VEHICLE:] Vehicle ID: %d destroyed by NOBODY, Faction: %d, Type: %d, Damaged: %d, CarRepairTimeLeft: %d", vehicleid, gVehData[vehicleid-1][mVehFaction], gVehData[vehicleid-1][CarDamaged], gVehData[vehicleid-1][CarRepairTimeLeft]);
	}
	
	VehicleLog(string);
	
	format(string, sizeof(string), "[VEHICLE:] mVehX: %f, mVehY: %f, mVehZ: %f, mVehOwned: %d, Owner: %s, CarResetT: %d, BusinessID: %d, CarSerial: %d", gVehData[vehicleid-1][mVehX], gVehData[vehicleid-1][mVehY], gVehData[vehicleid-1][mVehZ], gVehData[vehicleid-1][mVehOwned], gVehData[vehicleid-1][Owner], gVehData[vehicleid-1][CarResetT], gVehData[vehicleid-1][BusinessID], gVehData[vehicleid-1][CarSerial]);
	VehicleLog(string);
	
	format(string, sizeof(string), "[VEHICLE:] Model: %d", gVehData[vehicleid-1][mVehModel]);
	VehicleLog(string);
	
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
					VehicleLog(string);
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
	gVehData[vehicleid][mVehColor1] = color1;
	gVehData[vehicleid][mVehColor2] = color2;

	SaveVehData(vehicleid, "VehColor1");
	SaveVehData(vehicleid, "VehColor2");
	SavePlayerData(playerid, "Cost");
	return 1;
}

public OnVehicleStreamIn(vehicleid, forplayerid)
{
	if(gVehData[vehicleid-1][mVehSetToTp])
		return 1;
	gVehData[vehicleid-1][mVehSetToTp] = 1;
	defer SetVehicleLastPos(vehicleid);
	return 1;
}