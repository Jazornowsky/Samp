/***
*
* File: wp_importvehicle.inc
* Auth: Damian Wojdat
* Date: 15.09.2011
* Desc: Sets vehicle data when imported by player.
*
*************************************************************************************************************/

ImportVeh(BizKey, modelID, PlayerName[], fueltype, Float:maxHealth)
{
	new carID, j;
	new color2;
	new color1;
	new string[256];
	new message[128];
	if(Businesses[BizKey][Till] >= cenyPojazdow[modelID-400])
	{
		for(new n = 0; n < sizeof(gVehData); n++)
		{
			if(gVehData[n][mVehModel] == 594)
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
							
							for(j = 0; j < sizeof(CarsData); j++)
							{
								if(CarsData[j][Model] == modelID && CarsData[j][Paliwo] == fueltype)
								{
									SetVehicleHealth(carID, CarsData[j][MaxHealth]);
									break;
								}
							}
							
							gVehData[carID-1][mVehModel] = modelID;
							gVehData[carID-1][mVehX] = SpawnPlaceBoats[i][X];
							gVehData[carID-1][mVehY] = SpawnPlaceBoats[i][Y];
							gVehData[carID-1][mVehZ] = SpawnPlaceBoats[i][Z];
							VehNewPos[carID-1][0] = SpawnPlaceBoats[i][X];
							VehNewPos[carID-1][1] = SpawnPlaceBoats[i][Y];
							VehNewPos[carID-1][2] = SpawnPlaceBoats[i][Z];
							gVehData[carID-1][mVehA] = SpawnPlaceBoats[i][Angle];
							gVehData[carID-1][mVehColor1] = color1;
							gVehData[carID-1][mVehColor2] = color2;
							gVehData[carID-1][mVehFaction] = 255;
							gVehData[carID-1][mVehType] = 0;
							gVehData[carID-1][mVehVinNo] = random(999999);
							gVehData[carID-1][mVehOwned] = 0;
							strmid(gVehData[carID-1][Owner], "None", 0, 4, 128);
							gVehData[carID-1][Price] = cenyPojazdow[modelID-400];
							gVehData[carID-1][Closed] = 0;
							gVehData[carID-1][CarResetT] = 0;
							gVehData[carID-1][CarDamaged] = 0;
							gVehData[carID-1][CarRepairTimeLeft] = 0;
							gVehData[carID-1][BusinessID] = BizKey;
							gVehData[carID-1][CarFuel] = float(VehFTank(carID));
							gVehData[carID-1][CarHealth] = maxHealth;
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
							
							RefreshVehicleDescription(carID-1);
							
							SaveVehData(carID-1, "VehModel");
							SaveVehData(carID-1, "VehPos");
							SaveVehData(carID-1, "VehColor1");
							SaveVehData(carID-1, "VehColor2");
							SaveVehData(carID-1, "VehFaction");
							SaveVehData(carID-1, "VehType");
							SaveVehData(carID-1, "VehVinNo");
							SaveVehData(carID-1, "VehOwned");
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
					wp_mysql_query(string, SAVE3, INVALID_PLAYER_ID, db_con4);
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
							
							for(j = 0; j < sizeof(CarsData); j++)
							{
								if(CarsData[j][Model] == modelID && CarsData[j][Paliwo] == fueltype)
								{
									SetVehicleHealth(carID, CarsData[j][MaxHealth]);
									break;
								}
							}
							
							gVehData[carID-1][mVehModel] = modelID;
							gVehData[carID-1][mVehX] = SpawnPlacePlanes[i][X];
							gVehData[carID-1][mVehY] = SpawnPlacePlanes[i][Y];
							gVehData[carID-1][mVehZ] = SpawnPlacePlanes[i][Z];
							VehNewPos[carID-1][0] = SpawnPlacePlanes[i][X];
							VehNewPos[carID-1][1] = SpawnPlacePlanes[i][Y];
							VehNewPos[carID-1][2] = SpawnPlacePlanes[i][Z];
							gVehData[carID-1][mVehA] = SpawnPlacePlanes[i][Angle];
							gVehData[carID-1][mVehColor1] = color1;
							gVehData[carID-1][mVehColor2] = color2;
							gVehData[carID-1][mVehFaction] = 255;
							gVehData[carID-1][mVehType] = 0;
							gVehData[carID-1][mVehVinNo] = random(999999);
							gVehData[carID-1][mVehOwned] = 0;
							strmid(gVehData[carID-1][Owner], "None", 0, 4, 128);
							gVehData[carID-1][Price] = cenyPojazdow[modelID-400];
							gVehData[carID-1][Closed] = 0;
							gVehData[carID-1][CarResetT] = 0;
							gVehData[carID-1][CarDamaged] = 0;
							gVehData[carID-1][CarRepairTimeLeft] = 0;
							gVehData[carID-1][BusinessID] = BizKey;
							gVehData[carID-1][CarFuel] = float(VehFTank(carID));
							gVehData[carID-1][CarHealth] = maxHealth;
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
							
							RefreshVehicleDescription(carID-1);
							
							SaveVehData(carID-1, "VehModel");
							SaveVehData(carID-1, "VehPos");
							SaveVehData(carID-1, "VehColor1");
							SaveVehData(carID-1, "VehColor2");
							SaveVehData(carID-1, "VehFaction");							
							SaveVehData(carID-1, "VehVinNo");
							SaveVehData(carID-1, "VehType");
							SaveVehData(carID-1, "VehOwned");
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
					wp_mysql_query(string, SAVE3, INVALID_PLAYER_ID, db_con4);
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
							
							for(j = 0; j < sizeof(CarsData); j++)
							{
								if(CarsData[j][Model] == modelID && CarsData[j][Paliwo] == fueltype)
								{
									SetVehicleHealth(carID, CarsData[j][MaxHealth]);
									break;
								}
							}
							
							gVehData[carID-1][mVehModel] = modelID;
							gVehData[carID-1][mVehX] = SpawnPlaceCars[i][X];
							gVehData[carID-1][mVehY] = SpawnPlaceCars[i][Y];
							gVehData[carID-1][mVehZ] = SpawnPlaceCars[i][Z];
							VehNewPos[carID-1][0] = SpawnPlaceCars[i][X];
							VehNewPos[carID-1][1] = SpawnPlaceCars[i][Y];
							VehNewPos[carID-1][2] = SpawnPlaceCars[i][Z];
							gVehData[carID-1][mVehA] = SpawnPlaceCars[i][Angle];
							gVehData[carID-1][mVehColor1] = color1;
							gVehData[carID-1][mVehColor2] = color2;
							gVehData[carID-1][mVehFaction] = 255;
							gVehData[carID-1][mVehType] = 0;
							gVehData[carID-1][mVehVinNo] = random(999999);
							gVehData[carID-1][mVehOwned] = 0;
							strmid(gVehData[carID-1][Owner], "None", 0, 4, 128);
							gVehData[carID-1][Price] = cenyPojazdow[modelID-400];
							gVehData[carID-1][Closed] = 0;
							gVehData[carID-1][CarResetT] = 0;
							gVehData[carID-1][CarDamaged] = 0;
							gVehData[carID-1][CarRepairTimeLeft] = 0;
							gVehData[carID-1][BusinessID] = BizKey;
							gVehData[carID-1][CarFuel] = float(VehFTank(carID));
							gVehData[carID-1][CarHealth] = maxHealth;
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
							
							RefreshVehicleDescription(carID-1);
							
							SaveVehData(carID-1, "VehModel");
							SaveVehData(carID-1, "VehPos");
							SaveVehData(carID-1, "VehColor1");
							SaveVehData(carID-1, "VehColor2");
							SaveVehData(carID-1, "VehFaction");
							SaveVehData(carID-1, "VehVinNo");
							SaveVehData(carID-1, "VehType");
							SaveVehData(carID-1, "VehOwned");
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
					wp_mysql_query(string, SAVE3, INVALID_PLAYER_ID, db_con4);
					return 1;
				}
			}
		}
		format(message, sizeof(message), "Twoj pojazd nie mogl zostac sprowadzony (model %d). Powod: limit pojazdow gry.", modelID);
		
		format(string, sizeof(string), "INSERT INTO `samp_messages` ( `PlayerName` , `Content` , `Date` ) VALUES ( '%s' , '%s' , CURDATE() )", PlayerName, message);
		wp_mysql_query(string, SAVE3, INVALID_PLAYER_ID, db_con4);
		return 1;
	}
	else
	{
		Businesses[BizKey][VehicleOrderCount]--;
		SaveBizData( BizKey, "VehicleOrderCount" );
	}
	return 1;
}