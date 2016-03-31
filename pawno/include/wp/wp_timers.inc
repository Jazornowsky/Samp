/***
*
* File: wp_timers.inc
* Auth: Damian Wojdat
* Date: 15.09.2011
* Desc: Timered functions.
*
*************************************************************************************************************/

#include <wp\timers\wp_timers_default>

stock RafineryResourcesIncrease()
{
	//print("[TIMERCHECK:] RafineryResourceIncrease()");
	if(gRafinery[RafResourcePetrol] < gRafinery[RafMaxResources])
	{
		if(gRafinery[RafMaxResources] - gRafinery[RafResourcePetrol] > 300)
			gRafinery[RafResourcePetrol] += 300;
	}
	if(gRafinery[RafResourceOil] < gRafinery[RafMaxResources])
	{
		if(gRafinery[RafMaxResources] - gRafinery[RafResourceOil] > 240)
			gRafinery[RafResourceOil] += 240;
	}
	if(gRafinery[RafResourceGas] < gRafinery[RafMaxResources])
	{
		if(gRafinery[RafMaxResources] - gRafinery[RafResourceGas] > 180)
			gRafinery[RafResourceGas] += 180;
	}
	SaveRafinery();
	return 1;
}

task FuelTimer[5000]()
{
	//print("[TIMERCHECK:] FuelTimer()");
	//=============================================[TAKING FUEL FROM CARS WITH PLAYERS IN THEM]=================================
	new vehicle;
	new enginedyn,lights,alarm,bonnet,boot,objective, doors;
	if(gSaveReady == 1)
	{
		foreach(Player, i )
		{
			if( !gPlayerLogged[i] )
				continue;
				
			if(GetPlayerState(i) != PLAYER_STATE_DRIVER)
				continue;

			vehicle = GetPlayerVehicleID(i);

			if(IsABike(vehicle))
				continue;

			if(gVehData[vehicle-1][CarFuel] < 0.02)
			{
				gVehData[vehicle-1][EngineOn] = 0;
				SaveVehData(vehicle-1, "EngineOn");
				
				GetVehicleParamsEx(vehicle, enginedyn, lights, alarm, doors, bonnet, boot, objective);
				SetVehicleParamsEx(vehicle, 0, lights, alarm, doors, bonnet, boot, objective);
			}
			else
			{
				if(!gVehData[vehicle-1][EngineOn])
					continue;

				for(new n = 0; n < sizeof(CarsData); n++)
				{
					if(gVehData[vehicle-1][mVehModel] != CarsData[n][Model])
						continue;

					if(gVehData[vehicle-1][Fuel] != CarsData[n][Paliwo])
						continue;

					if(gVehData[vehicle-1][CarCounterPrev] == 0)
					{
						gVehData[vehicle-1][CarCounterPrev] = gVehData[vehicle-1][CarCounter];
					}
					else
					{
						if(gVehData[vehicle-1][CarHealth] < 500.0)
							gVehData[vehicle-1][CarFuel] -= ((( float(gVehData[vehicle-1][CarCounter] - gVehData[vehicle-1][CarCounterPrev]))/100000.0) * float(CarsData[n][Spalanie]))*4.0; // dlaczego przez 100000.0 ? bo spalanie jest podawane w l/100km
						else
							gVehData[vehicle-1][CarFuel] -= ((( float(gVehData[vehicle-1][CarCounter] - gVehData[vehicle-1][CarCounterPrev]))/100000.0) * float(CarsData[n][Spalanie])); // dlaczego przez 100000.0 ? bo spalanie jest podawane w l/100km

						gVehData[vehicle-1][CarFuel] -= 0.02;

						if(gVehData[vehicle-1][CarFuel] < 0.0)
							gVehData[vehicle-1][CarFuel] = 0.0;

						SaveVehData(vehicle-1, "CarFuel");

						gVehData[vehicle-1][CarCounterPrev] = gVehData[vehicle-1][CarCounter];
					}
					break;
				}
			}
		}
		for(new c = 0; c < sizeof(gVehData); c++)
		{
			if(!gVehData[c][EngineOn] || IsABike(c+1))
				continue;

			if(IsVehicleOccupied(c+1)) //Will only take fuel if the car is unoccupied.
				continue;

			if(gVehData[c][CarFuel] < 0.02)
			{
				gVehData[c][EngineOn] = 0;
				GetVehicleParamsEx(c+1, enginedyn, lights, alarm, doors, bonnet, boot, objective);
				SetVehicleParamsEx(c+1,0,0,alarm,doors,bonnet,boot,objective);
				continue;
			}

			gVehData[c][CarFuel] -= 0.02;

			SaveVehData(c, "CarFuel");
		}
	}
	else
	{
		gSaveReady = 1;
	}
	return 1;
}

GetXYVelocity(vehicleid, &Float:x, &Float:y, Float:speed)
{
	new Float:a;
	x = 0.0;
	y = 0.0;
	GetVehicleZAngle(vehicleid, a);
	x += (speed * floatsin(-a, degrees));
	y += (speed * floatcos(-a, degrees));
}

task CheckPointTimer[200]()
{
	static Float: posX , Float: posY , Float: posZ, Float: dist ;
	static vid;
	static Keys,ud,lr;
	foreach(Player, i )
	{
		if(!gPlayerLogged[i])
			continue;
		if(GetPlayerState(i) == PLAYER_STATE_DRIVER)
		{
		    vid = GetPlayerVehicleID(i);
			GetVehicleVelocity(vid, posX, posY, posZ);
			dist = floatsqroot(floatpower(posX, 2) + floatpower(posY, 2) + floatpower(posZ, 2)) * 197.5;
			if(IsABike(vid))
			{
				if(dist > 35.0)
				{
					dist = 35.0;
					GetXYVelocity(vid, posX, posY, (dist/197.5));
					SetVehicleVelocity(vid, posX, posY, posZ);
				}
			}
			if(gVehData[vid-1][mVehModel] == 532)
			{
				if(dist > 30.0)
				{
					dist = 30.0;
					GetXYVelocity(vid, posX, posY, (dist/197.5));
					SetVehicleVelocity(vid, posX, posY, posZ);
				}
			}
			else if(gVehData[vid-1][mVehModel] == 431 || gVehData[vid-1][mVehModel] == 437)
			{
				if(gIsInCityAreaSpeedLimit[i])
				{
					if(dist > 55.0)
					{
						dist = 55.0;
						GetXYVelocity(vid, posX, posY, (dist/197.5));
						SetVehicleVelocity(vid, posX, posY, posZ);
					}
				}
				else
				{
					if(dist > 70.0)
					{
						dist = 70.0;
						GetXYVelocity(vid, posX, posY, (dist/197.5));
						SetVehicleVelocity(vid, posX, posY, posZ);
					}
				}
			}
			if(gPlayerData[i][pSpeedLimiter] && (!TakingDrivingTestA[i] && !TakingDrivingTestB[i] && !TakingDrivingTestCE[i]) &&
				!IsAPlane(vid) && !IsAHelicopter(vid) && !IsABoat(vid) && !IsAMotorBike(vid))
			{
				if(gIsInCityAreaSpeedLimit[i])
				{
					if(dist > 68.0)
					{
						dist = 68.0;
						GetXYVelocity(vid, posX, posY, (dist/197.5));
						SetVehicleVelocity(vid, posX, posY, posZ);
					}
				}
				else
				{
					if(dist > 120.0)
					{
						dist = 120.0;
						GetXYVelocity(vid, posX, posY, (dist/197.5));
						SetVehicleVelocity(vid, posX, posY, posZ);
					}
				}
			}
			if(TakingDrivingTestA[i] || TakingDrivingTestB[i] || TakingDrivingTestCE[i])
			{
				if(dist > 55.0)
					gOverSpeed[i]++;
			}
		}
		else if(GetPlayerState(i) == PLAYER_STATE_ONFOOT)
		{
			GetPlayerKeys(i, Keys, ud, lr);
			if(ud != 0 || lr != 0)
			{
				if(gPlayerData[i][pDrunk] > 40.0 && !gWalkingDrunk[i])
				{
					gWalkingDrunk[i] = 1;
					ApplyAnimation(i,"PED","WALK_DRUNK",4.1,1,1,1,1,1);
					if(gPlayerData[i][pDrunk] > 85.0 && random(10) == 5)
						ApplyAnimation(i,"WUZI","CS_Dead_Guy",4.1,1,1,1,1,0);
				}
			}
			if(ud == 0 && lr == 0 && gWalkingDrunk[i])
			{
				gWalkingDrunk[i] = 0;
				if(random(2) == 0)
					ApplyAnimation(i,"PAULNMAC","PnM_Loop_A",4.1,1,1,1,1,1);
				else
					ApplyAnimation(i,"PAULNMAC","PnM_Loop_B",4.1,1,1,1,1,1);
			}
		}
	}
	return 1;
}

stock WarTimer()
{
	//print("[TIMERCHECK:] WarTimer()");
	if(WarTime == 0)
	{
		gAllPlayersCount = 0;
		gSuspectPlayersCount = 0;
		foreach(Player, i )
		{
			if(!gPlayerLogged[i])
				continue;
			if(gPlayerData[i][pFaction] != 0 && gPlayerData[i][pFaction] != 6)
			{
				gAllPlayersCount++;
			}
			if(gPlayerData[i][pWantedLvl] > 0 && gPlayerData[i][pFaction] != 0 && gPlayerData[i][pFaction] != 6)
			{
				gSuspectPlayersCount++;
			}
		}
		if(gSuspectPlayersCount == gAllPlayersCount && gAllPlayersCount != 0 && gSuspectPlayersCount >= 4)
		{
			WarTime = 1;
			WarTimeCountdown = 300;
			SendClientMessageToAll(COLOR_LIGHTYELLOW2, "[INFO:] Ze wzglêdu na panuj¹cy chaos w mieœcie zostaje wprowadzony Stan Wojenny !");
			SendClientMessageToAll(COLOR_LIGHTYELLOW2, "[INFO:] Wszystkim mieszkañcom radzimy pozostaæ w domach.");
		}
	}
	if(WarTime == 1)
	{
		WarTimeCountdown--;
	}
	if(WarTimeCountdown == 0)
	{
		WarTime = 0;

		SendClientMessageToAll(COLOR_LIGHTYELLOW2, "[INFO:] Stan wojenny zniesiony.");
		WarTimeCountdown--;
	}
	return 1;
}

timer VehicleIgnitionFix[10000](playerid, vehicleid)
{
	gVehData[vehicleid][mVehIgnitionHacked] = 0;
	SaveVehData(vehicleid, "VehIgnitionHacked");
	gVehData[vehicleid][mVehIgnitionDamaged] = 0;
	SaveVehData(vehicleid, "VehIgnitionDamaged");
	SendClientMessage(playerid, COLOR_GREEN, "[INFO:] Naprawi³eœ stacyjke");
	return 1;
}

timer VehicleCrack[20000](playerid, vehicleid)
{
	//print("[TIMERCHECK:] VehicleCrack(playerid, vehicleid)");

	if(random(50) >= random(100))
	{
		gVehData[vehicleid][Closed] = 0;

		SaveVehData(vehicleid, "Closed");

		new enginedyn,lights,alarm,doors,bonnet,boot,objective;
		GetVehicleParamsEx(vehicleid+1,enginedyn,lights,alarm,doors,bonnet,boot,objective);
		SetVehicleParamsEx(vehicleid+1,enginedyn,lights,alarm,0,bonnet,boot,objective);

		gPlayerData[playerid][pCarJackerJobPoints]++;

		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Uda³o Ci siê otworzyæ pojazd");

		if(gPlayerData[playerid][pCarJackerJobPoints] == 20 + (gPlayerData[playerid][pCarJackerJobLvl]*10))
		{
			gPlayerData[playerid][pCarJackerJobLvl]++;
			gPlayerData[playerid][pCarJackerJobPoints] = 0;

			SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] Osi¹gn¹³eœ %d poziom jako z³odziej pojazdów !");
		}

		SavePlayerData(playerid, "CarJackerJobLvl");
		SavePlayerData(playerid, "CarJackerJobPoints");

		return 1;
	}
	else
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie uda³o Ci siê otworzyæ pojazdu");
		return 1;
	}
}

timer HouseCrack[15000](playerid, hId)
{
	gPlayerVars[playerid][mIsPlayerHouseJacking] = 0;
	
	if(random(100) >= random(100))
	{
		Houses[hId][Locked] = 0;
		SaveHouseData(hId, "Locked");
		
		HouseInZoneBreakTimeLeftSave(hId);
		
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Uda³o ci siê otworzyæ drzwi", "Zamknij", "");
	}
	else
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Nie uda³o ci siê otworzyæ drzwi", "Zamknij", "");
}

timer BizCrack[15000](playerid, bId)
{
	gPlayerVars[playerid][mIsPlayerBizJacking] = 0;
	
	if(random(100) >= random(100))
	{
		Businesses[bId][Locked] = 0;
		SaveBizData(bId, "Locked");
		
		BizInZoneBreakTimeLeftSave(bId);
		
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Uda³o ci siê otworzyæ drzwi", "Zamknij", "");
	}
	else
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Nie uda³o ci siê otworzyæ drzwi", "Zamknij", "");
}

timer VehicleCrack2[20000](playerid, vehicleid)
{
	//print("[TIMERCHECK:] VehicleCrack2(playerid, vehicleid)");

	IsCarJackerOpening[playerid] = 0;

	if(random(100) >= random(100))
	{
		gVehData[vehicleid][Closed] = 0;
		SaveVehData(vehicleid, "Closed");

		new enginedyn,lights,alarm,doors,bonnet,boot,objective;
		GetVehicleParamsEx(vehicleid+1,enginedyn,lights,alarm,doors,bonnet,boot,objective);
		SetVehicleParamsEx(vehicleid+1,enginedyn,lights,alarm,0,bonnet,boot,objective);

		gPlayerData[playerid][pCarJackerJobPoints]++;

		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Uda³o Ci siê otworzyæ pojazd");
		
		VehInZoneBreakTimeLeftSave(vehicleid+1);
		
		if(gPlayerData[playerid][pCarJackerJobPoints] == 20 + (gPlayerData[playerid][pCarJackerJobLvl]*10))
		{
			gPlayerData[playerid][pCarJackerJobLvl]++;
			gPlayerData[playerid][pCarJackerJobPoints] = 0;

			SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] Osi¹gn¹³eœ %d poziom jako z³odziej pojazdów !");
		}

		SavePlayerData(playerid, "CarJackerJobLvl");
		SavePlayerData(playerid, "CarJackerJobPoints");

		return 1;
	}
	else
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie uda³o Ci siê otworzyæ pojazdu");
		return 1;
	}
}

stock Camera1()
{
	new string[128];
	new Float: posX, Float: posY, Float: posZ;
	foreach(Player, i )
	{
		if(!gPlayerLogged[i])
			continue;
		if(Camera1On[i] == 1)
		{
			GetPlayerCameraPos(i, posX, posY, posZ);
			format(string, sizeof(string), "X: %f; Y: %f; Z: %f", posX, posY, posZ);
			TextDrawSetString(CameraPos[i], string);
			TextDrawUseBox(CameraPos[i], 1);
			TextDrawLetterSize(CameraPos[i], 0.3, 0.8);
			TextDrawTextSize(CameraPos[i], 300.0, 100.0);
			TextDrawShowForPlayer(i, CameraPos[i]);
		}
		if(AngleOn[i] == 1)
		{
			GetPlayerFacingAngle(i, posX);
			GetPlayerFacingAngle(i, posY);
			format(string, sizeof(string), "X: %f; Y: %f; Z: %f", posX, posY, posZ);
			TextDrawSetString(Angle2[i], string);
			TextDrawUseBox(Angle2[i], 1);
			TextDrawLetterSize(Angle2[i], 0.3, 0.8);
			TextDrawTextSize(Angle2[i], 250.0, 100.0);
			TextDrawShowForPlayer(i, Angle2[i]);
		}
		if(Camera2On[i] == 1)
		{
			GetPlayerCameraFrontVector(i, posX, posY, posZ);
			format(string, sizeof(string), "X: %f; Y: %f; Z: %f", posX, posY, posZ);
			TextDrawSetString(CameraFront[i], string);
			TextDrawUseBox(CameraFront[i], 1);
			TextDrawLetterSize(CameraFront[i], 0.3, 0.8);
			TextDrawTextSize(CameraFront[i], 300.0, 100.0);
			TextDrawShowForPlayer(i, CameraFront[i]);
		}
		else
		{
			TextDrawHideForPlayer(i, CameraPos[i]);
		}
	}
	return 1;
}

timer PaintTimer[10000](vehicleid)
{
	isPainting[vehicleid] = 0;
	return 1;
}

timer WheelChangingTimer[20000](vehicleid)
{
	isWheelChanging[vehicleid] = 0;
	return 1;
}

timer GasChangingTimer[20000](vehicleid)
{
	isGasMounting[vehicleid] = 0;
	return 1;
}

timer CarAlarmOff[1000](vehicleid)
{
	new enginedyn,lights,alarm,doors,bonnet,boot,objective;
	GetVehicleParamsEx(vehicleid,enginedyn,lights,alarm,doors,bonnet,boot,objective);
	SetVehicleParamsEx(vehicleid,enginedyn,0,0,doors,bonnet,boot,objective);
	return 1;
}

timer DestroyFactory[10000]( fID, fDID )
{
	new Float:px, Float:py, Float:pz;
	px = DynamicFactions[fID][WFactoryCentrePosX];
	py = DynamicFactions[fID][WFactoryCentrePosY];
	pz = DynamicFactions[fID][WFactoryCentrePosZ];
	if( DynamicFactions[fID][WFactoryBurning] == 0 )
	{
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][1] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][2] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][3] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][4] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][5] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][6] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][7] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][8] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][9] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][10] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][11] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][12] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][13] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][14] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][15] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][16] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][17] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][18] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][19] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][20] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][21] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][22] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][23] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][24] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][25] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][26] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][27] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][28] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][29] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][30] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][31] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][32] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][33] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][34] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][35] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][36] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][37] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][38] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][39] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][40] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][41] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][55] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][42] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][43] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][44] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][45] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][46] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][47] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][48] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][49] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][50] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][51] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][52] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][53] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][54] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][55] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][56] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][57] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][58] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][59] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][60] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][61] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][62] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][63] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][64] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][65] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][66] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][67] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][68] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][69] );
	}
	if( DynamicFactions[fID][WFactoryBurning] == 1 )
	{
		DynamicFactions[fID][WFactoryBurning] = 2;
		DynamicFactions[fID][WFactoryDObjects][1] = CreateDynamicObject(18688,px+3.51809835,py+-6.28747177,pz+-1.08281255,0.00000000,0.00000000,0.00000000,0,0,-1,250);
		DynamicFactions[fID][WFactoryDObjects][2] = CreateDynamicObject(18688,px+2.15382385,py+-5.91271210,pz+-1.08281255,0.00000000,0.00000000,0.00000000,0,0,-1,250);
		DynamicFactions[fID][WFactoryDObjects][3] = CreateDynamicObject(18688,px+-2.08829880,py+-5.81902885,pz+-1.08281255,0.00000000,0.00000000,0.00000000,0,0,-1,250);
		DynamicFactions[fID][WFactoryDObjects][4] = CreateDynamicObject(18688,px+-3.32890749,py+-5.96794510,pz+-1.08281255,0.00000000,0.00000000,0.00000000,0,0,-1,250);
		DynamicFactions[fID][WFactoryDObjects][5] = CreateDynamicObject(18688,px+-3.34380007,py+-0.94286251,pz+-1.08281255,0.00000000,0.00000000,0.00000000,0,0,-1,250);
		DynamicFactions[fID][WFactoryDObjects][6] = CreateDynamicObject(18727,px+5.63071442,py+5.99838924,pz+1.06058848,0.00000000,0.00000000,0.00000000,0,0,-1,250);
		DynamicFactions[fID][WFactoryDObjects][7] = CreateDynamicObject(18727,px+-5.03250837,py+10.41282463,pz+1.01058853,0.00000000,0.00000000,0.00000000,0,0,-1,250);
	}
	if( DynamicFactions[fID][WFactoryBurning] == 2 )
	{
		DynamicFactions[fID][WFactoryBurning] = 3;
		DynamicFactions[fID][WFactoryDObjects][8] = CreateDynamicObject(18688,px+-3.87802267,py+3.12296534,pz+-1.08281255,0.00000000,0.00000000,0.00000000);
		DynamicFactions[fID][WFactoryDObjects][9] = CreateDynamicObject(18688,px+-1.90487027,py+7.50037003,pz+-1.08281255,0.00000000,0.00000000,0.00000000);
		DynamicFactions[fID][WFactoryDObjects][10] = CreateDynamicObject(18688,px+0.88364732,py+7.69967270,pz+-1.08281255,0.00000000,0.00000000,0.00000000);
		DynamicFactions[fID][WFactoryDObjects][11] = CreateDynamicObject(18688,px+3.60534906,py+3.74317360,pz+-1.08281255,0.00000000,0.00000000,0.00000000);
		DynamicFactions[fID][WFactoryDObjects][12] = CreateDynamicObject(18688,px+3.58199930,py+4.53341341,pz+-1.08281255,0.00000000,0.00000000,0.00000000);
		DynamicFactions[fID][WFactoryDObjects][13] = CreateDynamicObject(18727,px+-2.27175093,py+-7.85546255,pz+1.01058853,0.00000000,0.00000000,0.00000000);
		DynamicFactions[fID][WFactoryDObjects][14] = CreateDynamicObject(18727,px+2.10430861,py+-7.61335039,pz+1.01058853,0.00000000,0.00000000,0.00000000);
		DynamicFactions[fID][WFactoryDObjects][15] = CreateDynamicObject(18727,px+-5.71557283,py+5.78334713,pz+1.01058853,0.00000000,0.00000000,0.00000000);
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][0] );

		defer DestroyFactory( fID, fDID );
	}
	else if( DynamicFactions[fID][WFactoryBurning] == 3 )
	{
		DynamicFactions[fID][WFactoryBurning] = 4;
		DynamicFactions[fID][WFactoryDObjects][16] = CreateDynamicObject(18688,px+3.79568839,py+-2.53902864,pz+-1.08281255,0.00000000,0.00000000,0.00000000);
		DynamicFactions[fID][WFactoryDObjects][17] = CreateDynamicObject(18688,px+4.92002869,py+0.26532960,pz+-1.08281255,0.00000000,0.00000000,0.00000000);
		DynamicFactions[fID][WFactoryDObjects][18] = CreateDynamicObject(18688,px+-4.60537052,py+5.25028896,pz+-1.08281255,0.00000000,0.00000000,0.00000000);
		DynamicFactions[fID][WFactoryDObjects][19] =CreateDynamicObject(18727,px+5.09636688,py+10.72340584,pz+1.01058853,0.00000000,0.00000000,0.00000000);
		DynamicFactions[fID][WFactoryDObjects][20] = CreateDynamicObject(18727,px+-5.97128963,py+-4.03578281,pz+1.01058853,0.00000000,0.00000000,0.00000000);
		DynamicFactions[fID][WFactoryDObjects][21] = CreateDynamicObject(18727,px+5.97105122,py+-7.07275867,pz+1.01058853,0.00000000,0.00000000,0.00000000);
		
		defer DestroyFactory( fID, fDID );
	}
	else if( DynamicFactions[fID][WFactoryBurning] == 4 )
	{
		DynamicFactions[fID][WFactoryBurning] = 5;
		DynamicFactions[fID][WFactoryDObjects][22] = CreateDynamicObject(18685,px+3.06152511,py+-6.05036736,pz+0.12812500,0.00000000,0.00000000,0.00000000);
		DynamicFactions[fID][WFactoryDObjects][23] =CreateDynamicObject(18685,px+4.38275623,py+-2.45808172,pz+0.12812500,0.00000000,0.00000000,0.00000000);
		DynamicFactions[fID][WFactoryDObjects][24] = CreateDynamicObject(18685,px+-2.33152175,py+-5.62697363,pz+0.12812500,0.00000000,0.00000000,0.00000000);
		DynamicFactions[fID][WFactoryDObjects][25] = CreateDynamicObject(18685,px+0.93585062,py+8.30728245,pz+0.12812500,0.00000000,0.00000000,356.00000000);
		DynamicFactions[fID][WFactoryDObjects][26] = CreateDynamicObject(18688,px+4.02942276,py+0.13488016,pz+-1.08281255,0.00000000,0.00000000,0.00000000);
		DynamicFactions[fID][WFactoryDObjects][27] = CreateDynamicObject(18688,px+4.46142387,py+-4.58122444,pz+-1.08281255,0.00000000,0.00000000,0.00000000);
		DynamicFactions[fID][WFactoryDObjects][28] = CreateDynamicObject(18688,px+2.07426405,py+-6.03579903,pz+-1.08281255,0.00000000,0.00000000,0.00000000);

		defer DestroyFactory( fID, fDID );
	}
	else if( DynamicFactions[fID][WFactoryBurning] == 5 )
	{
		DynamicFactions[fID][WFactoryBurning] = 6;
		DynamicFactions[fID][WFactoryDObjects][29] = CreateDynamicObject(18688,px+-1.96972919,py+-6.11529064,pz+-1.08281255,0.00000000,0.00000000,0.00000000);
		DynamicFactions[fID][WFactoryDObjects][30] = CreateDynamicObject(18688,px+-3.65178037,py+-4.29829454,pz+-1.08281255,0.00000000,0.00000000,0.00000000); // DYM
		DynamicFactions[fID][WFactoryDObjects][31] = CreateDynamicObject(18688,px+-4.04132223,py+5.34731293,pz+-1.08281255,0.00000000,0.00000000,0.00000000);

		defer DestroyFactory( fID, fDID );
	}
	else if( DynamicFactions[fID][WFactoryBurning] == 6 )
	{
		DynamicFactions[fID][WFactoryBurning] = 7;
		DynamicFactions[fID][WFactoryDObjects][32] = CreateDynamicObject(18688,px+-2.20555925,py+7.93822575,pz+-1.08281255,0.00000000,0.00000000,0.00000000); //Object number 0
		DynamicFactions[fID][WFactoryDObjects][33] = CreateDynamicObject(18688,px+2.09640694,py+7.23771858,pz+-1.08281255,0.00000000,0.00000000,0.00000000); //Object number 1
		DynamicFactions[fID][WFactoryDObjects][34] = CreateDynamicObject(18688,px+4.07061195,py+5.35370541,pz+-1.08281255,0.00000000,0.00000000,0.00000000); //Object number 2

		defer DestroyFactory( fID, fDID ); // poprawione
	}
	else if( DynamicFactions[fID][WFactoryBurning] == 7 )
	{
		DynamicFactions[fID][WFactoryBurning] = 8;
		DynamicFactions[fID][WFactoryDObjects][35] = CreateDynamicObject(18688,px+7.26077890,py+-5.29881668,pz+-1.08281255,0.00000000,0.00000000,0.00000000); //Object number 3
		DynamicFactions[fID][WFactoryDObjects][36] = CreateDynamicObject(18688,px+7.38368750,py+-2.01982164,pz+-1.08281255,0.00000000,0.00000000,0.00000000); //Object number 4
		DynamicFactions[fID][WFactoryDObjects][37] = CreateDynamicObject(18688,px+7.52604151,py+2.71459961,pz+-1.08281255,0.00000000,0.00000000,0.00000000); //Object number 5
		DynamicFactions[fID][WFactoryDObjects][38]  = CreateDynamicObject(18688,px+7.60581112,py+7.50650978,pz+-1.08281255,0.00000000,0.00000000,0.00000000);

		defer DestroyFactory( fID, fDID ); // poprawione
	}
	else if( DynamicFactions[fID][WFactoryBurning] == 8 )
	{
		DynamicFactions[fID][WFactoryBurning] = 9;
		DynamicFactions[fID][WFactoryDObjects][39] = CreateDynamicObject(18727,px+0.13985056,py+5.88873529,pz+1.01058853,0.00000000,0.00000000,0.00000000); // dym
		DynamicFactions[fID][WFactoryDObjects][40] = CreateDynamicObject(18727,px+0.22189075,py+-4.72055721,pz+1.01058853,0.00000000,0.00000000,0.00000000); //dym
		DynamicFactions[fID][WFactoryDObjects][41] = CreateDynamicObject(18688,px+4.26882935,py+7.92933512,pz+2.91718769,0.00000000,0.00000000,0.00000000);
		DynamicFactions[fID][WFactoryDObjects][42] = CreateDynamicObject(18688,px+4.50096512,py+0.92676902,pz+2.91718769,0.00000000,0.00000000,0.00000000);
		DynamicFactions[fID][WFactoryDObjects][43] = CreateDynamicObject(18688,px+3.55468059,py+-5.95523930,pz+2.91718769,0.00000000,0.00000000,0.00000000);
		DynamicFactions[fID][WFactoryDObjects][44] = CreateDynamicObject(18688,px+-4.45439005,py+-6.22060680,pz+2.91718769,0.00000000,0.00000000,0.00000000);
		DynamicFactions[fID][WFactoryDObjects][45] = CreateDynamicObject(18688,px+-4.02879047,py+0.98733354,pz+2.91718769,0.00000000,0.00000000,0.00000000);
		DynamicFactions[fID][WFactoryDObjects][46] = CreateDynamicObject(18688,px+-4.13882923,py+7.84502697,pz+2.91718769,0.00000000,0.00000000,0.00000000);

		defer DestroyFactory( fID, fDID );  //poprawione
	}
	else if( DynamicFactions[fID][WFactoryBurning] == 9 )
	{
		DynamicFactions[fID][WFactoryBurning] = 10;
		DynamicFactions[fID][WFactoryDObjects][47] = CreateDynamicObject(18688,px+-3.14181685,py+11.53678513,pz+2.19218493,0.00000000,0.00000000,0.00000000);
		DynamicFactions[fID][WFactoryDObjects][48] = CreateDynamicObject(18688,px+-0.14819607,py+11.33732605,pz+2.09218454,0.00000000,0.00000000,0.00000000);
		DynamicFactions[fID][WFactoryDObjects][49] = CreateDynamicObject(18688,px+3.51605368,py+11.41932201,pz+2.59218454,0.00000000,0.00000000,0.00000000);
		DynamicFactions[fID][WFactoryDObjects][50] = CreateDynamicObject(18688,px+0.12142569,py+-3.06669521,pz+5.16718769,0.00000000,0.00000000,0.00000000);
		DynamicFactions[fID][WFactoryDObjects][51] = CreateDynamicObject(18688,px+-0.40233070,py+4.41530561,pz+5.16718769,0.00000000,0.00000000,0.00000000);
		
		defer DestroyFactory( fID, fDID ); //poprawione
	}
	else if( DynamicFactions[fID][WFactoryBurning] == 10 )
	{
		DynamicFactions[fID][WFactoryBurning] = 11;
		// Audio_Play(playerid, 1159, false, false, false);
		DynamicFactions[fID][WFactoryDObjects][52] = CreateDynamicObject(18682,px+0.12921290,py+1.85947990,pz+0.12812500,0.00000000,0.00000000,0.00000000,0,0,-1,250);
		DynamicFactions[fID][WFactoryDObjects][53] = CreateDynamicObject(18682,px+-0.49170995,py+1.22855473,pz+0.12812500,0.00000000,0.00000000,0.00000000,0,0,-1,250);
		DynamicFactions[fID][WFactoryDObjects][54] = CreateDynamicObject(18682,px+2.64665532,py+-3.13171053,pz+0.12812500,0.00000000,0.00000000,0.00000000,0,0,-1,250);
		DynamicFactions[fID][WFactoryDObjects][55] = CreateDynamicObject(18682,px+-1.85613203,py+-3.32820010,pz+0.12812500,0.00000000,0.00000000,0.00000000,0,0,-1,250);
		DynamicFactions[fID][WFactoryDObjects][56] = CreateDynamicObject(18682,px+-3.28180742,py+5.48041821,pz+0.12812500,0.00000000,0.00000000,0.00000000,0,0,-1,250);
		DynamicFactions[fID][WFactoryDObjects][57] = CreateDynamicObject(18682,px+-2.00083661,py+7.80823326,pz+0.12812500,0.00000000,0.00000000,0.00000000,0,0,-1,250);
		DynamicFactions[fID][WFactoryDObjects][58] = CreateDynamicObject(18682,px+2.06595969,py+8.57765675,pz+0.12812500,0.00000000,0.00000000,0.00000000,0,0,-1,250);
		DynamicFactions[fID][WFactoryDObjects][59] = CreateDynamicObject(18682,px+4.50518847,py+0.36046758,pz+0.12812500,0.00000000,0.00000000,0.00000000,0,0,-1,250);
		
		defer DestroyFactory( fID, fDID ); //poprawione
	}
	else if( DynamicFactions[fID][WFactoryBurning] == 11 )
	{
		DynamicFactions[fID][WFactoryBurning] = 12;
		// Audio_Play(playerid, 1159, false, false, false);
		DynamicFactions[fID][WFactoryDObjects][60] = CreateDynamicObject(18682,px+-2.05068183,py+-4.99210167,pz+4.37812519,0.00000000,0.00000000,0.00000000,0,0,-1,250);
		DynamicFactions[fID][WFactoryDObjects][61] = CreateDynamicObject(18682,px+-1.76031137,py+1.04337204,pz+4.37812519,0.00000000,0.00000000,0.00000000,0,0,-1,250);
		DynamicFactions[fID][WFactoryDObjects][62] = CreateDynamicObject(18682,px+-1.69767320,py+9.67770481,pz+4.37812519,0.00000000,0.00000000,0.00000000,0,0,-1,250);
		DynamicFactions[fID][WFactoryDObjects][63] = CreateDynamicObject(18682,px+2.66152525,py+7.88192940,pz+4.37812519,0.00000000,0.00000000,0.00000000,0,0,-1,250);
		DynamicFactions[fID][WFactoryDObjects][64] = CreateDynamicObject(18682,px+3.53181529,py+0.54668343,pz+4.37812519,0.00000000,0.00000000,0.00000000,0,0,-1,250);
		DynamicFactions[fID][WFactoryDObjects][65] = CreateDynamicObject(18682,px+2.21829152,py+-6.05153704,pz+4.37812519,0.00000000,0.00000000,0.00000000,0,0,-1,250);
		
		defer DestroyFactory( fID, fDID ); //poprawione
	}
	else if( DynamicFactions[fID][WFactoryBurning] == 12 )
	{
		DynamicFactions[fID][WFactoryBurning] = 13;
		// Audio_Play(playerid, 1159, false, false, false);
		DynamicFactions[fID][WFactoryDObjects][66] = CreateDynamicObject(18682,px+6.67809105,py+-5.72583961,pz+2.37812519,0.00000000,0.00000000,0.00000000,0,0,-1,250);
		DynamicFactions[fID][WFactoryDObjects][67] = CreateDynamicObject(18682,px+7.04398727,py+0.01818210,pz+2.37812519,0.00000000,0.00000000,0.00000000,0,0,-1,250);
		DynamicFactions[fID][WFactoryDObjects][68] = CreateDynamicObject(18682,px+-1.44621408,py+10.38482857,pz+1.37812519,0.00000000,0.00000000,0.00000000,0,0,-1,250);
		DynamicFactions[fID][WFactoryDObjects][69] = CreateDynamicObject(18682,px+-1.70082259,py+10.81455040,pz+1.37812519,0.00000000,0.00000000,0.00000000,0,0,-1,250);
		
		defer DestroyFactory( fID, fDID );  // poprawione
	}
	else if( DynamicFactions[fID][WFactoryBurning] == 13 )
	{
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][1] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][2] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][3] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][4] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][5] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][6] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][7] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][8] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][9] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][10] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][11] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][12] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][13] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][14] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][15] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][16] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][17] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][18] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][19] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][20] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][21] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][22] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][23] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][24] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][25] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][26] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][27] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][28] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][29] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][30] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][31] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][32] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][33] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][34] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][35] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][36] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][37] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][38] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][39] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][40] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][41] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][55] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][42] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][43] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][44] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][45] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][46] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][47] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][48] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][49] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][50] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][51] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][52] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][53] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][54] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][55] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][56] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][57] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][58] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][59] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][60] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][61] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][62] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][63] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][64] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][65] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][66] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][67] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][68] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][69] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryObjects][0] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryObjects][1] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryObjects][2] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryObjects][3] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryObjects][4] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryObjects][5] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryObjects][6] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryObjects][7] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryObjects][8] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryObjects][9] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryObjects][10] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryObjects][11] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryObjects][12] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryObjects][13] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryObjects][14] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryObjects][15] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryObjects][16] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryObjects][17] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryObjects][18] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryObjects][19] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryObjects][20] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryObjects][21] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryObjects][22] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryObjects][23] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryObjects][24] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryObjects][25] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryObjects][26] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryObjects][27] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryObjects][28] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryObjects][29] );
		DestroyDynamicObject( DynamicFactions[fID][WFactoryObjects][30] );
		DestroyDynamicCP( DynamicFactions[fID][WFactoryCPPartSetup1ID] );
		DestroyDynamicCP( DynamicFactions[fID][WFactoryCPPartSetup2ID] );
		DestroyDynamicCP( DynamicFactions[fID][WFactoryCPAmmoPartSetup1ID] );
		DestroyDynamicCP( DynamicFactions[fID][WFactoryCPPartTakeID]  );
		DestroyDynamicCP( DynamicFactions[fID][WFactoryCPSafeID]  );
		DestroyDynamicCP( DynamicFactions[fID][WFactoryCPAmmoPartSetup2ID] );
		DynamicFactions[fID][WFactoryObjects][0] = 0;
		DynamicFactions[fID][WFactoryObjects][1] = 0;
		DynamicFactions[fID][WFactoryObjects][2] = 0;
		DynamicFactions[fID][WFactoryObjects][3] = 0;
		DynamicFactions[fID][WFactoryObjects][4] = 0;
		DynamicFactions[fID][WFactoryObjects][5] = 0;
		DynamicFactions[fID][WFactoryObjects][6] = 0;
		DynamicFactions[fID][WFactoryObjects][7] = 0;
		DynamicFactions[fID][WFactoryObjects][8] = 0;
		DynamicFactions[fID][WFactoryObjects][9] = 0;
		DynamicFactions[fID][WFactoryObjects][10] = 0;
		DynamicFactions[fID][WFactoryObjects][11] = 0;
		DynamicFactions[fID][WFactoryObjects][12] = 0;
		DynamicFactions[fID][WFactoryObjects][13] = 0;
		DynamicFactions[fID][WFactoryObjects][14] = 0;
		DynamicFactions[fID][WFactoryObjects][15] = 0;
		DynamicFactions[fID][WFactoryObjects][16] = 0;
		DynamicFactions[fID][WFactoryObjects][17] = 0;
		DynamicFactions[fID][WFactoryObjects][18] = 0;
		DynamicFactions[fID][WFactoryObjects][19] = 0;
		DynamicFactions[fID][WFactoryObjects][20] = 0;
		DynamicFactions[fID][WFactoryObjects][21] = 0;
		DynamicFactions[fID][WFactoryObjects][22] = 0;
		DynamicFactions[fID][WFactoryObjects][23] = 0;
		DynamicFactions[fID][WFactoryObjects][24] = 0;
		DynamicFactions[fID][WFactoryObjects][25] = 0;
		DynamicFactions[fID][WFactoryObjects][26] = 0;
		DynamicFactions[fID][WFactoryObjects][27] = 0;
		DynamicFactions[fID][WFactoryObjects][28] = 0;
		DynamicFactions[fID][WFactoryObjects][29] = 0;
		DynamicFactions[fID][WFactoryObjects][30] = 0;
		DynamicFactions[fID][WFactoryBurning] = 0;
		DynamicFactions[fID][WFactoryCentrePosX] = 0;
		DynamicFactions[fID][WFactoryCentrePosY] = 0;
		DynamicFactions[fID][WFactoryCentrePosZ] = 0;
		if( DynamicFactions[fDID][fType] == 1 )
		{
			DynamicFactions[fDID][fBank] += WFACTORY_DES_REW_FACTION;
			DynamicFactions[FACTIONID_GOVERNMENT][fBank] -= WFACTORY_DES_REW_FACTION;
		}
		SaveFData( fDID, "Bank" );
		SaveFData( FACTIONID_GOVERNMENT, "Bank" );
		SaveFData( fID, "WFactoryBurning" );
		// SaveFData( fID, "WFactoryObjects" );
		SaveFData( fID, "WFactoryCentrePosX" );
		SaveFData( fID, "WFactoryCentrePosY" );
		SaveFData( fID, "WFactoryCentrePosZ" );
	}
	return 1;
}

timer RPC2[3500](playerid)
{
	gPlayerData[playerid][pCharacterDying] = 0;
	SavePlayerData( playerid, "CharacterDying" );
}

timer RPC[8500](playerid)
{
	gPlayerData[playerid][pHP] = 30.0;
	SetPlayerHealth(playerid, gPlayerData[playerid][pHP]);	
	
	TogglePlayerControllable(playerid, 1);	
	SetCameraBehindPlayer(playerid);	
	ApplyAnimation(playerid, "PED", "getup", 4.1, 0, 0, 0, 0, 0);
	
	SendClientMessage(playerid, COLOR_GREEN, "[INFO:] Reanimacja powiod³a siê, stan stabilny !");
	
	TextDrawShowForPlayer(playerid, Status[playerid]);
	
	if(gPlayerData[playerid][pFirstReanimation])
	{
		SendClientMessage(playerid, COLOR_GREEN, "[INFO:] Reanimacja powiod³a siê, wróci³eœ do ¿ywych !");
	}
	else
	{
		SendClientMessage(playerid, COLOR_GREEN, "[INFO:] Bêdziesz ¿y³ ! Reanimacja powiod³a siê !");
		gPlayerData[playerid][pFirstReanimation] = 1;
		SavePlayerData(playerid, "FirstReanimation");
	}
	
	defer RPC2(playerid);
	return 1;
}