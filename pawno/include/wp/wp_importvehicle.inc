ImportVeh(BizKey, modelID, PlayerName[MAX_PLAYER_NAME], fueltype)
{
	new carID;
	new color2;
	new color1;
	new string[256];
	new message[128];
	if(Businesses[BizKey][Till] >= cenyPojazdow[modelID-400])
	{
		for(new n = 0; n < sizeof(gVehData); n++)
		{
			if(gVehData[n][CarModel] == 594)
			{
				DestroyVehicle(n+1);
				color1 = random(126);
				color2 = random(126);
			
				if(IsABoatModel(modelID))
				{
					for(new i = 0; i < 10; i++)
					{
						if(SpawnPlaceBoats[i][SlotUsed] == 0)
						{
							SpawnPlaceBoats[i][SlotUsed] = 1;
							
							carID = CreateVehicle(modelID, SpawnPlaceBoats[i][X], SpawnPlaceBoats[i][Y], SpawnPlaceBoats[i][Z], SpawnPlaceBoats[i][Angle], color1, color2, -1);
							
							gVehData[carID-1][CarModel] = modelID;
							gVehData[carID-1][CarX] = SpawnPlaceBoats[i][X];
							gVehData[carID-1][CarY] = SpawnPlaceBoats[i][Y];
							gVehData[carID-1][CarZ] = SpawnPlaceBoats[i][Z];
							gVehData[carID-1][CarAngle] = SpawnPlaceBoats[i][Angle];
							gVehData[carID-1][CarColor1] = color1;
							gVehData[carID-1][CarColor2] = color2;
							gVehData[carID-1][FactionCar] = 255;
							gVehData[carID-1][CarType] = 0;
							gVehData[carID-1][Owned] = 0;
							strmid(gVehData[carID-1][Owner], "None", 0, 4, 128);
							gVehData[carID-1][Price] = cenyPojazdow[modelID-400];
							gVehData[carID-1][Closed] = 0;
							gVehData[carID-1][CarResetT] = 0;
							gVehData[carID-1][CarDamaged] = 0;
							gVehData[carID-1][CarRepairTimeLeft] = 0;
							gVehData[carID-1][BusinessID] = BizKey;
							gVehData[carID-1][CarFuel] = float(VehFTank(carID));
							gVehData[carID-1][CarHealth] = 1000.0;
							gVehData[carID-1][ReadyToSell] = 0;
							gVehData[carID-1][CarCounter] = 0;
							gVehData[carID-1][Fuel] = fueltype;
							gVehData[carID-1][CarPanels] = 0;
							gVehData[carID-1][CarDoors] = 0;
							gVehData[carID-1][CarLights] = 0;
							gVehData[carID-1][CarTires] = 0;
							gVehData[carID-1][CarSerial] = 0;
							gVehData[carID-1][PaintStep] = 0;
							gVehData[carID-1][WheelStep] = 0;
							gVehData[carID-1][EngineOn] = 0;
							gVehData[carID-1][LightsOn] = 0;
							gVehData[carID-1][BonnetUp] = 0;
							gVehData[carID-1][BootUp] = 0;
							gVehData[carID-1][RadioOn] = 0;
							gVehData[carID-1][Hook] = 0;
							gVehData[carID-1][Alarm] = 0;
							gVehData[carID-1][GasStep] = 0;
							
							SaveVehData(carID-1, "CarModel");
							SaveVehData(carID-1, "CarPos");
							SaveVehData(carID-1, "CarColor1");
							SaveVehData(carID-1, "CarColor2");
							SaveVehData(carID-1, "FactionCar");
							SaveVehData(carID-1, "CarType");
							SaveVehData(carID-1, "Owned");
							SaveVehData(carID-1, "Owner");
							SaveVehData(carID-1, "Price");
							SaveVehData(carID-1, "Closed");
							SaveVehData(carID-1, "CarResetT");
							SaveVehData(carID-1, "CarDamaged");
							SaveVehData(carID-1, "CarRepairTimeLeft");
							SaveVehData(carID-1, "BusinessID");
							SaveVehData(carID-1, "CarFuel");
							SaveVehData(carID-1, "CarHealth");
							SaveVehData(carID-1, "ReadyToSell");
							SaveVehData(carID-1, "CarCounter");
							SaveVehData(carID-1, "Fuel");
							SaveVehData(carID-1, "CarPanels");
							SaveVehData(carID-1, "CarDoors");
							SaveVehData(carID-1, "CarLights");
							SaveVehData(carID-1, "CarTires");
							SaveVehData(carID-1, "CarSerial");
							SaveVehData(carID-1, "PaintStep");
							SaveVehData(carID-1, "WheelStep");
							SaveVehData(carID-1, "EngineOn");
							SaveVehData(carID-1, "LightsOn");
							SaveVehData(carID-1, "BonnetUp");
							SaveVehData(carID-1, "BootUp");
							SaveVehData(carID-1, "RadioOn");
							SaveVehData(carID-1, "Hook");
							SaveVehData(carID-1, "Alarm");
							SaveVehData(carID-1, "GasStep");
							
							SpawnPlaceBoats[i][VehicleID] = carID;
							
							Businesses[BizKey][VehicleSpawned] = 1;
							Businesses[BizKey][VehicleOrderCount]--;
							Businesses[BizKey][VehicleCount]++;
							Businesses[BizKey][Till] -= cenyPojazdow[modelID-400];
							
							SaveDynamicBoatsSpawns();
							SaveBizData(BizKey, "VehicleSpawned");
							SaveBizData(BizKey, "VehicleOrderCount");
							SaveBizData(BizKey, "VehicleCount");
							SaveBizData(BizKey, "Till");
							
							return 1;
						}
					}
					format(message, sizeof(message), "Twoj pojazd nie mogl zostac sprowadzony (model %d). Powod: limit slotow fabryki.", modelID);
					format(string, sizeof(string), "INSERT INTO `samp_messages` ( `PlayerName` , `Content` , `Date` ) VALUES ( '%s' , '%s' , CURDATE() )", PlayerName, message);
					mysql_query(string, SAVE3, INVALID_PLAYER_ID, db_con4);
					return 1;
				}
				if(IsAPlaneModel(modelID) || IsAHelicopterModel(modelID))
				{
					for(new i = 0; i < 10; i++)
					{
						if(SpawnPlacePlanes[i][SlotUsed] == 0)
						{
							SpawnPlacePlanes[i][SlotUsed] = 1;
							
							carID = CreateVehicle(modelID, SpawnPlacePlanes[i][X], SpawnPlacePlanes[i][Y], SpawnPlacePlanes[i][Z], SpawnPlacePlanes[i][Angle], color1, color2, -1);
							
							gVehData[carID-1][CarModel] = modelID;
							gVehData[carID-1][CarX] = SpawnPlacePlanes[i][X];
							gVehData[carID-1][CarY] = SpawnPlacePlanes[i][Y];
							gVehData[carID-1][CarZ] = SpawnPlacePlanes[i][Z];
							gVehData[carID-1][CarAngle] = SpawnPlacePlanes[i][Angle];
							gVehData[carID-1][CarColor1] = color1;
							gVehData[carID-1][CarColor2] = color2;
							gVehData[carID-1][FactionCar] = 255;
							gVehData[carID-1][CarType] = 0;
							gVehData[carID-1][Owned] = 0;
							strmid(gVehData[carID-1][Owner], "None", 0, 4, 128);
							gVehData[carID-1][Price] = cenyPojazdow[modelID-400];
							gVehData[carID-1][Closed] = 0;
							gVehData[carID-1][CarResetT] = 0;
							gVehData[carID-1][CarDamaged] = 0;
							gVehData[carID-1][CarRepairTimeLeft] = 0;
							gVehData[carID-1][BusinessID] = BizKey;
							gVehData[carID-1][CarFuel] = float(VehFTank(carID));
							gVehData[carID-1][CarHealth] = 1000.0;
							gVehData[carID-1][ReadyToSell] = 0;
							gVehData[carID-1][CarCounter] = 0;
							gVehData[carID-1][Fuel] = fueltype;
							gVehData[carID-1][CarPanels] = 0;
							gVehData[carID-1][CarDoors] = 0;
							gVehData[carID-1][CarLights] = 0;
							gVehData[carID-1][CarTires] = 0;
							gVehData[carID-1][CarSerial] = 0;
							gVehData[carID-1][PaintStep] = 0;
							gVehData[carID-1][WheelStep] = 0;
							gVehData[carID-1][EngineOn] = 0;
							gVehData[carID-1][LightsOn] = 0;
							gVehData[carID-1][BonnetUp] = 0;
							gVehData[carID-1][BootUp] = 0;
							gVehData[carID-1][RadioOn] = 0;
							gVehData[carID-1][Hook] = 0;
							gVehData[carID-1][Alarm] = 0;
							gVehData[carID-1][GasStep] = 0;
							
							SaveVehData(carID-1, "CarModel");
							SaveVehData(carID-1, "CarPos");
							SaveVehData(carID-1, "CarColor1");
							SaveVehData(carID-1, "CarColor2");
							SaveVehData(carID-1, "FactionCar");
							SaveVehData(carID-1, "CarType");
							SaveVehData(carID-1, "Owned");
							SaveVehData(carID-1, "Owner");
							SaveVehData(carID-1, "Price");
							SaveVehData(carID-1, "Closed");
							SaveVehData(carID-1, "CarResetT");
							SaveVehData(carID-1, "CarDamaged");
							SaveVehData(carID-1, "CarRepairTimeLeft");
							SaveVehData(carID-1, "BusinessID");
							SaveVehData(carID-1, "CarFuel");
							SaveVehData(carID-1, "CarHealth");
							SaveVehData(carID-1, "ReadyToSell");
							SaveVehData(carID-1, "CarCounter");
							SaveVehData(carID-1, "Fuel");
							SaveVehData(carID-1, "CarPanels");
							SaveVehData(carID-1, "CarDoors");
							SaveVehData(carID-1, "CarLights");
							SaveVehData(carID-1, "CarTires");
							SaveVehData(carID-1, "CarSerial");
							SaveVehData(carID-1, "PaintStep");
							SaveVehData(carID-1, "WheelStep");
							SaveVehData(carID-1, "EngineOn");
							SaveVehData(carID-1, "LightsOn");
							SaveVehData(carID-1, "BonnetUp");
							SaveVehData(carID-1, "BootUp");
							SaveVehData(carID-1, "RadioOn");
							SaveVehData(carID-1, "Hook");
							SaveVehData(carID-1, "Alarm");
							SaveVehData(carID-1, "GasStep");
							
							SpawnPlacePlanes[i][VehicleID] = carID;
							
							Businesses[BizKey][VehicleSpawned] = 1;
							Businesses[BizKey][VehicleOrderCount]--;
							Businesses[BizKey][VehicleCount]++;
							Businesses[BizKey][Till] -= cenyPojazdow[modelID-400];
							
							SaveDynamicPlanesSpawns();
							SaveBizData(BizKey, "VehicleSpawned");
							SaveBizData(BizKey, "VehicleOrderCount");
							SaveBizData(BizKey, "VehicleCount");
							SaveBizData(BizKey, "Till");
							
							return 1;
						}
					}
					format(message, sizeof(message), "Twoj pojazd nie mogl zostac sprowadzony (model %d). Powod: limit slotow fabryki.", modelID);
					format(string, sizeof(string), "INSERT INTO `samp_messages` ( `PlayerName` , `Content` , `Date` ) VALUES ( '%s' , '%s' , CURDATE() )", PlayerName, message);
					mysql_query(string, SAVE3, INVALID_PLAYER_ID, db_con4);
					return 1;
				}
				else
				{
					for(new i = 0; i < 20; i++)
					{
						if(SpawnPlaceCars[i][SlotUsed] == 0)
						{
							SpawnPlaceCars[i][SlotUsed] = 1;
							
							carID = CreateVehicle(modelID, SpawnPlaceCars[i][X], SpawnPlaceCars[i][Y], SpawnPlaceCars[i][Z], SpawnPlaceCars[i][Angle], color1, color2, -1);
							
							gVehData[carID-1][CarModel] = modelID;
							gVehData[carID-1][CarX] = SpawnPlaceCars[i][X];
							gVehData[carID-1][CarY] = SpawnPlaceCars[i][Y];
							gVehData[carID-1][CarZ] = SpawnPlaceCars[i][Z];
							gVehData[carID-1][CarAngle] = SpawnPlaceCars[i][Angle];
							gVehData[carID-1][CarColor1] = color1;
							gVehData[carID-1][CarColor2] = color2;
							gVehData[carID-1][FactionCar] = 255;
							gVehData[carID-1][CarType] = 0;
							gVehData[carID-1][Owned] = 0;
							strmid(gVehData[carID-1][Owner], "None", 0, 4, 128);
							gVehData[carID-1][Price] = cenyPojazdow[modelID-400];
							gVehData[carID-1][Closed] = 0;
							gVehData[carID-1][CarResetT] = 0;
							gVehData[carID-1][CarDamaged] = 0;
							gVehData[carID-1][CarRepairTimeLeft] = 0;
							gVehData[carID-1][BusinessID] = BizKey;
							gVehData[carID-1][CarFuel] = float(VehFTank(carID));
							gVehData[carID-1][CarHealth] = 1000.0;
							gVehData[carID-1][ReadyToSell] = 0;
							gVehData[carID-1][CarCounter] = 0;
							gVehData[carID-1][Fuel] = fueltype;
							gVehData[carID-1][CarPanels] = 0;
							gVehData[carID-1][CarDoors] = 0;
							gVehData[carID-1][CarLights] = 0;
							gVehData[carID-1][CarTires] = 0;
							gVehData[carID-1][CarSerial] = 0;
							gVehData[carID-1][PaintStep] = 0;
							gVehData[carID-1][WheelStep] = 0;
							gVehData[carID-1][EngineOn] = 0;
							gVehData[carID-1][LightsOn] = 0;
							gVehData[carID-1][BonnetUp] = 0;
							gVehData[carID-1][BootUp] = 0;
							gVehData[carID-1][RadioOn] = 0;
							gVehData[carID-1][Hook] = 0;
							gVehData[carID-1][Alarm] = 0;
							gVehData[carID-1][GasStep] = 0;
							
							SaveVehData(carID-1, "CarModel");
							SaveVehData(carID-1, "CarPos");
							SaveVehData(carID-1, "CarColor1");
							SaveVehData(carID-1, "CarColor2");
							SaveVehData(carID-1, "FactionCar");
							SaveVehData(carID-1, "CarType");
							SaveVehData(carID-1, "Owned");
							SaveVehData(carID-1, "Owner");
							SaveVehData(carID-1, "Price");
							SaveVehData(carID-1, "Closed");
							SaveVehData(carID-1, "CarResetT");
							SaveVehData(carID-1, "CarDamaged");
							SaveVehData(carID-1, "CarRepairTimeLeft");
							SaveVehData(carID-1, "BusinessID");
							SaveVehData(carID-1, "CarFuel");
							SaveVehData(carID-1, "CarHealth");
							SaveVehData(carID-1, "ReadyToSell");
							SaveVehData(carID-1, "CarCounter");
							SaveVehData(carID-1, "Fuel");
							SaveVehData(carID-1, "CarPanels");
							SaveVehData(carID-1, "CarDoors");
							SaveVehData(carID-1, "CarLights");
							SaveVehData(carID-1, "CarTires");
							SaveVehData(carID-1, "CarSerial");
							SaveVehData(carID-1, "PaintStep");
							SaveVehData(carID-1, "WheelStep");
							SaveVehData(carID-1, "EngineOn");
							SaveVehData(carID-1, "LightsOn");
							SaveVehData(carID-1, "BonnetUp");
							SaveVehData(carID-1, "BootUp");
							SaveVehData(carID-1, "RadioOn");
							SaveVehData(carID-1, "Hook");
							SaveVehData(carID-1, "Alarm");
							SaveVehData(carID-1, "GasStep");
							
							SpawnPlaceCars[i][VehicleID] = carID;
							
							Businesses[BizKey][VehicleSpawned] = 1;
							Businesses[BizKey][VehicleOrderCount]--;
							Businesses[BizKey][VehicleCount]++;
							Businesses[BizKey][Till] -= cenyPojazdow[modelID-400];
							
							SaveDynamicPlanesSpawns();
							SaveBizData(BizKey, "VehicleSpawned");
							SaveBizData(BizKey, "VehicleOrderCount");
							SaveBizData(BizKey, "VehicleCount");
							SaveBizData(BizKey, "Till");
							
							return 1;
						}
					}
					format(message, sizeof(message), "Twoj pojazd nie mogl zostac sprowadzony (model %d). Powod: limit slotow fabryki.", modelID);
					format(string, sizeof(string), "INSERT INTO `samp_messages` ( `PlayerName` , `Content` , `Date` ) VALUES ( '%s' , '%s' , CURDATE() )", PlayerName, message);
					mysql_query(string, SAVE3, INVALID_PLAYER_ID, db_con4);
					return 1;
				}
			}
		}
		format(message, sizeof(message), "Twoj pojazd nie mogl zostac sprowadzony (model %d). Powod: limit pojazdow gry.", modelID);
		format(string, sizeof(string), "INSERT INTO `samp_messages` ( `PlayerName` , `Content` , `Date` ) VALUES ( '%s' , '%s' , CURDATE() )", PlayerName, message);
		mysql_query(string, SAVE3, INVALID_PLAYER_ID, db_con4);
		return 1;
	}
	else
	{
		Businesses[BizKey][VehicleOrderCount]--;
		SaveBizData( BizKey, "VehicleOrderCount" );
	}
	return 1;
}