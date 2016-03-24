// LoadConfig()
// {
	// new arrCoords[4][128];
	// new strFromFile2[256];
	// new File: file = fopen("other/config.cfg", io_read);
	// if (file)
	// {
		// fread(file, strFromFile2);
		// split2(strFromFile2, arrCoords, '|');
		
		// strmid( db_host, arrCoords[0], 0, 128 );
		// strmid( db_user, arrCoords[1], 0, 128 );
		// strmid( db_database, arrCoords[2], 0, 128 );
		// strmid( db_pass, arrCoords[3], 0, 128 );
		// printf("db_host = %s,\ndb_user = %s,\ndb_database = %s,\ndb_pass = %s", db_host, db_user, db_database, db_pass);
		
		// fclose(file);
	// }
	// return 1;
// }

LoadDynamicCars()
{
	new string[128];

	format(string, sizeof(string), "SELECT * FROM samp_vehicles ORDER BY `ID` ASC");
	mysql_query(string, LOAD_DYNAMIC_CARS, INVALID_PLAYER_ID, db_con2);

	format(string, sizeof(string), "SELECT * FROM `samp_carsdata`");
	mysql_query(string, LOAD_CARSDATA, INVALID_PLAYER_ID, db_con2);
	
	format(string, sizeof(string), "SELECT * FROM `samp_cars_cparts`");
	mysql_query(string, LOAD_CARS_CPARTS, INVALID_PLAYER_ID, db_con2);

	return 1;
}

SaveDynamicCars()
{
	new string[256];

	for(new i = 0; i < sizeof(gVehData); i++)
	{
		format(string, sizeof(string), "UPDATE `samp_vehicles` SET `CarModel` = '%d' , `CarX` = '%f' , `CarY` = '%f' WHERE `ID` = '%d' ", gVehData[i][CarModel], gVehData[i][CarX], gVehData[i][CarY], i+1);
		mysql_query(string, SAVE2, INVALID_PLAYER_ID, db_con3);

		format(string, sizeof(string), "UPDATE `samp_vehicles` SET `CarZ` = '%f' , `CarAngle` = '%f' , `CarColor1` = '%d' WHERE `ID` = '%d' ", gVehData[i][CarZ], gVehData[i][CarAngle], gVehData[i][CarColor1], i+1);
		mysql_query(string, SAVE2, INVALID_PLAYER_ID, db_con3);

		format(string, sizeof(string), "UPDATE `samp_vehicles` SET `CarColor2` = '%d' , `FactionCar` = '%d' , `CarType` = '%d' WHERE `ID` = '%d' ", gVehData[i][CarColor2], gVehData[i][FactionCar], gVehData[i][CarType], i+1);
		mysql_query(string, SAVE2, INVALID_PLAYER_ID, db_con3);

		format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Owned` = '%d' , `Owner` = '%s' , `Price` = '%d' WHERE `ID` = '%d' ", gVehData[i][Owned], gVehData[i][Owner], gVehData[i][Price], i+1);
		mysql_query(string, SAVE2, INVALID_PLAYER_ID, db_con3);

		format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Closed` = '%d' , `CarResetT` = '%d' , `CarDamaged` = '%d' WHERE `ID` = '%d' ", gVehData[i][Closed], gVehData[i][CarResetT], gVehData[i][CarDamaged], i+1);
		mysql_query(string, SAVE2, INVALID_PLAYER_ID, db_con3);

		format(string, sizeof(string), "UPDATE `samp_vehicles` SET `CarRepairTimeLeft` = '%d' , `BusinessID` = '%d' , `CarFuel` = '%f' WHERE `ID` = '%d' ", gVehData[i][CarRepairTimeLeft], gVehData[i][BusinessID], gVehData[i][CarFuel], i+1);
		mysql_query(string, SAVE2, INVALID_PLAYER_ID, db_con3);

		format(string, sizeof(string), "UPDATE `samp_vehicles` SET `CarHealth` = '%f' , `ReadyToSell` = '%d' , `CarCounter` = '%d', `Fuel` = '%d' WHERE `ID` = '%d' ", gVehData[i][CarHealth], gVehData[i][ReadyToSell], gVehData[i][CarCounter], gVehData[i][Fuel], i+1);
		mysql_query(string, SAVE2, INVALID_PLAYER_ID, db_con3);
	}
	return 1;
}

LoadDynamicZones()
{
	new arrCoords[5][64];
	new strFromFile6[800];
	new File: file = fopen("zones/zone.cfg", io_read);
	if(file)
	{
		new idx;
		while (idx < sizeof(DynamicZones))
		{
			fread(file, strFromFile6);
			split2(strFromFile6, arrCoords, '|');
			DynamicZones[idx][zMin_X] = floatstr(arrCoords[0]);
			DynamicZones[idx][zMin_Y] = floatstr(arrCoords[1]);
			DynamicZones[idx][zMax_X] = floatstr(arrCoords[2]);
			DynamicZones[idx][zMax_Y] = floatstr(arrCoords[3]);
			DynamicZones[idx][zFaction] = strval(arrCoords[4]);
			idx++;
		}
		fclose(file);
	}
	return 1;
}

SaveDynamicZones()
{
	new idx;
	new File: file2;
	while (idx < sizeof(DynamicZones))
	{
		new coordstring[512];
		format(coordstring, sizeof(coordstring), "%f|%f|%f|%f|%d\n",
		DynamicZones[idx][zMin_X],
		DynamicZones[idx][zMin_Y],
		DynamicZones[idx][zMax_X],
		DynamicZones[idx][zMax_Y],
		DynamicZones[idx][zFaction]);

		if(idx == 0)
		{
			file2 = fopen("zones/zone.cfg", io_write);
		}
		else
		{
			file2 = fopen("zones/zone.cfg", io_append);
		}
		fwrite(file2, coordstring);
		idx++;
		fclose(file2);
	}
	return 1;
}

LoadDynamicRaces()
{
	new arrCoords[19][64];
	new strFromFile2[256];
	new File: file = fopen("races/races.cfg", io_read);
	if (file)
	{
		new idx;
		while (idx < sizeof(DynamicRaces))
		{
			fread(file, strFromFile2);
			split2(strFromFile2, arrCoords, '|');
			DynamicRaces[idx][TakeRaceX] = floatstr(arrCoords[0]);
			DynamicRaces[idx][TakeRaceY] = floatstr(arrCoords[1]);
			DynamicRaces[idx][TakeRaceZ] = floatstr(arrCoords[2]);
			DynamicRaces[idx][StartPointX] = floatstr(arrCoords[3]);
			DynamicRaces[idx][StartPointY] = floatstr(arrCoords[4]);
			DynamicRaces[idx][StartPointZ] = floatstr(arrCoords[5]);
			DynamicRaces[idx][FinishPointX] = floatstr(arrCoords[6]);
			DynamicRaces[idx][FinishPointY] = floatstr(arrCoords[7]);
			DynamicRaces[idx][FinishPointZ] = floatstr(arrCoords[8]);
			DynamicRaces[idx][TopTimeM] = strval(arrCoords[9]);
			DynamicRaces[idx][TopTimeS] = strval(arrCoords[10]);
			DynamicRaces[idx][EnterPrice] = strval(arrCoords[11]);
			DynamicRaces[idx][StartPrice] = strval(arrCoords[12]);
			strmid(DynamicRaces[idx][LastWinner], arrCoords[13], 0, strlen(arrCoords[13]), 255);
			strmid(DynamicRaces[idx][KingOfSprint], arrCoords[14], 0, strlen(arrCoords[14]), 255);
			DynamicRaces[idx][Started] = strval(arrCoords[15]);
			strmid(DynamicRaces[idx][Location], arrCoords[16], 0, strlen(arrCoords[16]), 255);
			DynamicRaces[idx][MaxDrivers] = strval(arrCoords[17]);
			DynamicRaces[idx][PickupID] = strval(arrCoords[18]);

			DynamicRaces[idx][PickupID] = CreateDynamicPickup(1239, 1, DynamicRaces[idx][TakeRaceX], DynamicRaces[idx][TakeRaceY], DynamicRaces[idx][TakeRaceZ]);

			idx++;
		}
		fclose(file);
	}
	return 1;
}

SaveDynamicRaces()
{
	new idx;
	new File: file2;
	while (idx < sizeof(DynamicRaces))
	{
		new coordstring[512];
		format(coordstring, sizeof(coordstring), "%f|%f|%f|%f|%f|%f|%f|%f|%f|%d|%d|%d|%d|%s|%s|%d|%s|%d|%d\n",
		DynamicRaces[idx][TakeRaceX],
		DynamicRaces[idx][TakeRaceY],
		DynamicRaces[idx][TakeRaceZ],
		DynamicRaces[idx][StartPointX],
		DynamicRaces[idx][StartPointY],
		DynamicRaces[idx][StartPointZ],
		DynamicRaces[idx][FinishPointX],
		DynamicRaces[idx][FinishPointY],
		DynamicRaces[idx][FinishPointZ],
		DynamicRaces[idx][TopTimeM],
		DynamicRaces[idx][TopTimeS],
		DynamicRaces[idx][EnterPrice],
		DynamicRaces[idx][StartPrice],
		DynamicRaces[idx][LastWinner],
		DynamicRaces[idx][KingOfSprint],
		DynamicRaces[idx][Started],
		DynamicRaces[idx][Location],
		DynamicRaces[idx][MaxDrivers],
		DynamicRaces[idx][PickupID]);

		if(idx == 0)
		{
			file2 = fopen("races/races.cfg", io_write);
		}
		else
		{
			file2 = fopen("races/races.cfg", io_append);
		}
		fwrite(file2, coordstring);
		idx++;
		fclose(file2);
	}
	return 1;
}

LoadDynamicTaxes()
{
	new arrCoords[13][64];
	new strFromFile2[256];
	new File: file = fopen("other/taxes.cfg", io_read);
	if (file)
	{
		fread(file, strFromFile2);
		split2(strFromFile2, arrCoords, '|');
		DynamicTaxes[CarTax] = floatstr(arrCoords[0]);
		DynamicTaxes[HeliTax] = floatstr(arrCoords[1]);
		DynamicTaxes[PlaneTax] = floatstr(arrCoords[2]);
		DynamicTaxes[BoatTax] = floatstr(arrCoords[3]);
		DynamicTaxes[HouseTax] = floatstr(arrCoords[4]);
		DynamicTaxes[BusinessTax] = floatstr(arrCoords[5]);
		DynamicTaxes[RadioTax] = strval(arrCoords[6]);
		DynamicTaxes[TelTax] = strval(arrCoords[7]);
		DynamicTaxes[RichTax] = floatstr(arrCoords[8]);
		DynamicTaxes[EkoTax] = floatstr(arrCoords[9]);
		DynamicTaxes[VatTaxMax] = floatstr(arrCoords[10]);
		DynamicTaxes[VatTaxMin] = floatstr(arrCoords[11]);
		DynamicTaxes[TheRich] = strval(arrCoords[12]);
	}
	fclose(file);
	return 1;
}

SaveDynamicTaxes()
{
	new File: file2;
	new coordstring[512];
	format(coordstring, sizeof(coordstring), "%f|%f|%f|%f|%f|%f|%d|%d|%f|%f|%f|%f|%d\n",
	DynamicTaxes[CarTax],
	DynamicTaxes[HeliTax],
	DynamicTaxes[PlaneTax],
	DynamicTaxes[BoatTax],
	DynamicTaxes[HouseTax],
	DynamicTaxes[BusinessTax],
	DynamicTaxes[RadioTax],
	DynamicTaxes[TelTax],
	DynamicTaxes[RichTax],
	DynamicTaxes[EkoTax],
	DynamicTaxes[VatTaxMax],
	DynamicTaxes[VatTaxMin],
	DynamicTaxes[TheRich]);
	file2 = fopen("other/taxes.cfg", io_write);
	fwrite(file2, coordstring);
	fclose(file2);
	return 1;
}

LoadDynamicCarSpawns()
{
	new arrCoords[6][64];
	new strFromFile2[256];
	new File: file = fopen("spawnplaces/carsspawnplaces.cfg", io_read);
	if (file)
	{
		new idx;
		while (idx < sizeof(SpawnPlaceCars))
		{
			fread(file, strFromFile2);
			split2(strFromFile2, arrCoords, '|');
			SpawnPlaceCars[idx][X] = floatstr(arrCoords[0]);
			SpawnPlaceCars[idx][Y] = floatstr(arrCoords[1]);
			SpawnPlaceCars[idx][Z] = floatstr(arrCoords[2]);
			SpawnPlaceCars[idx][Angle] = floatstr(arrCoords[3]);
			SpawnPlaceCars[idx][SlotUsed] = strval(arrCoords[4]);
			SpawnPlaceCars[idx][VehicleID] = strval(arrCoords[5]);

			idx++;
		}
		fclose(file);
	}
	return 1;
}

SaveDynamicCarSpawns()
{
	new idx;
	new File: file2;
	while (idx < sizeof(SpawnPlaceCars))
	{
		new coordstring[256];
		format(coordstring, sizeof(coordstring), "%f|%f|%f|%f|%d|%d\n",
		SpawnPlaceCars[idx][X],
		SpawnPlaceCars[idx][Y],
		SpawnPlaceCars[idx][Z],
		SpawnPlaceCars[idx][Angle],
		SpawnPlaceCars[idx][SlotUsed],
		SpawnPlaceCars[idx][VehicleID]);

		if(idx == 0)
		{
			file2 = fopen("spawnplaces/carsspawnplaces.cfg", io_write);
		}
		else
		{
			file2 = fopen("spawnplaces/carsspawnplaces.cfg", io_append);
		}
		fwrite(file2, coordstring);
		idx++;
		fclose(file2);
	}
	return 1;
}

LoadDynamicPlanesSpawns()
{
	new arrCoords[6][64];
	new strFromFile2[256];
	new File: file = fopen("spawnplaces/planesspawnplaces.cfg", io_read);
	if (file)
	{
		new idx;
		while (idx < sizeof(SpawnPlacePlanes))
		{
			fread(file, strFromFile2);
			split2(strFromFile2, arrCoords, '|');
			SpawnPlacePlanes[idx][X] = floatstr(arrCoords[0]);
			SpawnPlacePlanes[idx][Y] = floatstr(arrCoords[1]);
			SpawnPlacePlanes[idx][Z] = floatstr(arrCoords[2]);
			SpawnPlacePlanes[idx][Angle] = floatstr(arrCoords[3]);
			SpawnPlacePlanes[idx][SlotUsed] = strval(arrCoords[4]);
			SpawnPlacePlanes[idx][VehicleID] = strval(arrCoords[5]);

			idx++;
		}
		fclose(file);
	}
	return 1;
}

SaveDynamicPlanesSpawns()
{
	new idx;
	new File: file2;
	while (idx < sizeof(SpawnPlacePlanes))
	{
		new coordstring[512];
		format(coordstring, sizeof(coordstring), "%f|%f|%f|%f|%d|%d\n",
		SpawnPlacePlanes[idx][X],
		SpawnPlacePlanes[idx][Y],
		SpawnPlacePlanes[idx][Z],
		SpawnPlacePlanes[idx][Angle],
		SpawnPlacePlanes[idx][SlotUsed],
		SpawnPlacePlanes[idx][VehicleID]);

		if(idx == 0)
		{
			file2 = fopen("spawnplaces/planesspawnplaces.cfg", io_write);
		}
		else
		{
			file2 = fopen("spawnplaces/planesspawnplaces.cfg", io_append);
		}
		fwrite(file2, coordstring);
		idx++;
		fclose(file2);
	}
	return 1;
}

LoadDynamicBoatsSpawns()
{
	new arrCoords[6][64];
	new strFromFile2[256];
	new File: file = fopen("spawnplaces/boatsspawnplaces.cfg", io_read);
	if (file)
	{
		new idx;
		while (idx < sizeof(SpawnPlaceBoats))
		{
			fread(file, strFromFile2);
			split2(strFromFile2, arrCoords, '|');
			SpawnPlaceBoats[idx][X] = floatstr(arrCoords[0]);
			SpawnPlaceBoats[idx][Y] = floatstr(arrCoords[1]);
			SpawnPlaceBoats[idx][Z] = floatstr(arrCoords[2]);
			SpawnPlaceBoats[idx][Angle] = floatstr(arrCoords[3]);
			SpawnPlaceBoats[idx][SlotUsed] = strval(arrCoords[4]);
			SpawnPlaceBoats[idx][VehicleID] = strval(arrCoords[5]);

			idx++;
		}
		fclose(file);
	}
	return 1;
}

SaveDynamicBoatsSpawns()
{
	new idx;
	new File: file2;
	while (idx < sizeof(SpawnPlacePlanes))
	{
		new coordstring[512];
		format(coordstring, sizeof(coordstring), "%f|%f|%f|%f|%d|%d\n",
		SpawnPlaceBoats[idx][X],
		SpawnPlaceBoats[idx][Y],
		SpawnPlaceBoats[idx][Z],
		SpawnPlaceBoats[idx][Angle],
		SpawnPlaceBoats[idx][SlotUsed],
		SpawnPlaceBoats[idx][VehicleID]);

		if(idx == 0)
		{
			file2 = fopen("spawnplaces/boatsspawnplaces.cfg", io_write);
		}
		else
		{
			file2 = fopen("spawnplaces/boatsspawnplaces.cfg", io_append);
		}
		fwrite(file2, coordstring);
		idx++;
		fclose(file2);
	}
	return 1;
}

LoadRafinery()
{
	new string[64];

	format(string, sizeof(string), "SELECT * FROM `samp_rafinery`");
	mysql_query(string, LOAD_RAFINERY, INVALID_PLAYER_ID, db_con2);

	return 1;
}

SaveRafinery()
{
	new string[256];

	format(string, sizeof(string), "UPDATE `samp_rafinery` SET `ResourcePetrol` = '%d' , `PetrolLtrCost` = '%d' , `EmployerReward` = '%d' , `MaxResources` = '%d' ", gRafinery[RafResourcePetrol], gRafinery[RafPetrolLtrCost], gRafinery[RafRefuelReward], gRafinery[RafMaxResources]);
	mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
	format(string, sizeof(string), "UPDATE `samp_rafinery` SET `ResourceOil` = '%d' , `ResourceGas` = '%d' , `OilLtrCost` = '%d' , `GasLtrCost` = '%d' ", gRafinery[RafResourceOil], gRafinery[RafResourceGas], gRafinery[RafOilLtrCost], gRafinery[RafGasLtrCost]);
	mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);

	return 1;
}

LoadWFactoryLegal() // fabryka broni
{
	new string[64];
	
	format(string, sizeof(string), "SELECT * FROM `samp_wfactorylegal`");
	mysql_query(string, LOAD_WFACTORYLEGAL, INVALID_PLAYER_ID, db_con2);
	
	return 1;
}

LoadGasStations()
{
	new string[128];

	format(string, sizeof(string), "SELECT * FROM `samp_gas_stations`");
	mysql_query(string, LOAD_GAS_STATIONS, INVALID_PLAYER_ID, db_con2);

	return 1;
}

SaveGasStations()
{
	new string[128];

	for(new i = 0; i < sizeof(GasStations); i++)
	{
		format(string, sizeof(string), "UPDATE `samp_gas_stations` SET `BusinessID` = '%d' , `PetrolResourceValue` = '%f' WHERE `ID` = '%d' ", GasStations[i][BusinessID], GasStations[i][PetrolResourceValue], i);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);

		format(string, sizeof(string), "UPDATE `samp_gas_stations` SET `MaxPetrolResourceValue` = '%f' , `RefuelPetrolResources` = '%d' WHERE `ID` = '%d' ", GasStations[i][MaxPetrolResourceValue], GasStations[i][RefuelPetrolResources], i);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);

		format(string, sizeof(string), "UPDATE `samp_gas_stations` SET `PetrolPrice` = '%d' , `posX` = '%f' WHERE `ID` = '%d' ", GasStations[i][PetrolPrice], GasStations[i][GSposX], i);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);

		format(string, sizeof(string), "UPDATE `samp_gas_stations` SET `posY` = '%f' , `posZ` = '%f' WHERE `ID` = '%d' ", GasStations[i][GSposY], GasStations[i][GSposZ], i);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
		
		format(string, sizeof(string), "UPDATE `samp_gas_stations` SET `OilResourceValue` = '%f' , `GasResourceValue` = '%f' WHERE `ID` = '%d' ", GasStations[i][OilResourceValue], GasStations[i][GasResourceValue], i);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
		
		format(string, sizeof(string), "UPDATE `samp_gas_stations` SET `MaxOilResourceValue` = '%f' , `MaxGasResourceValue` = '%f' WHERE `ID` = '%d' ", GasStations[i][MaxOilResourceValue], GasStations[i][MaxGasResourceValue], i);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
		
		format(string, sizeof(string), "UPDATE `samp_gas_stations` SET `OilPrice` = '%d' , `GasPrice` = '%d' WHERE `ID` = '%d' ", GasStations[i][OilPrice], GasStations[i][GasPrice], i);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
	}
	return 1;
}

LoadPayRank()
{
	new string[128];

	format(string, sizeof(string), " SELECT * FROM `samp_factions_payrank` ");
	mysql_query(string, LOAD_FACTIONS_PAYRANK, INVALID_PLAYER_ID, db_con2);

	return 1;
}

SavePayRank()
{
	new string[128];

	for(new i = 0; i < sizeof(DynamicFactions); i++)
	{
		format(string, sizeof(string), "UPDATE `samp_factions_payrank` SET `FactionID` = '%d' , `Rank1` = '%d' WHERE `FactionID` = '%d' ", PayRank[i][FactionID], PayRank[i][Rank1], i);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);

		format(string, sizeof(string), "UPDATE `samp_factions_payrank` SET `Rank2` = '%d' , `Rank3` = '%d' WHERE `FactionID` = '%d' ", PayRank[i][Rank2], PayRank[i][Rank3], i);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);

		format(string, sizeof(string), "UPDATE `samp_factions_payrank` SET `Rank4` = '%d' , `Rank5` = '%d' WHERE `FactionID` = '%d' ", PayRank[i][Rank4], PayRank[i][Rank5], i);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);

		format(string, sizeof(string), "UPDATE `samp_factions_payrank` SET `Rank6` = '%d' , `Rank7` = '%d' WHERE `FactionID` = '%d' ", PayRank[i][Rank6], PayRank[i][Rank7], i);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);

		format(string, sizeof(string), "UPDATE `samp_factions_payrank` SET `Rank8` = '%d' , `Rank9` = '%d' WHERE `FactionID` = '%d' ", PayRank[i][Rank8], PayRank[i][Rank9], i);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);

		format(string, sizeof(string), "UPDATE `samp_factions_payrank` SET `Rank10` = '%d' WHERE `FactionID` = '%d' ", PayRank[i][Rank10], i);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
	}
	return 1;
}

LoadVariables()
{
	new string[128];

	format(string, sizeof(string), "SELECT * FROM `samp_variables`");
	mysql_query(string, LOAD_VARIABLES, INVALID_PLAYER_ID, db_con2);

	return 1;
}

SaveVariables()
{
	new string[128];

	for(new i = 0; i < sizeof(DBVariables); i++)
	{
		format(string, sizeof(string), "UPDATE `samp_variables` SET `varName` = '%s', `varType` = '%s' WHERE `ID` = '%d'", DBVariables[i][varName], DBVariables[i][varType], i+1);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);

		format(string, sizeof(string), "UPDATE `samp_variables` SET `varDValue` = '%d', `varFValue` = '%f' WHERE `ID` = '%d'", DBVariables[i][varDValue], DBVariables[i][varFValue], i+1);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);

		format(string, sizeof(string), "UPDATE `samp_variables` SET `varSValue` = '%s' WHERE `ID` = '%d'", DBVariables[i][varSValue], i+1);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
	}
	return 1;
}

LoadDynamicFactions()
{
	new string[128];

	format(string, sizeof(string), "SELECT * FROM samp_factions");
	mysql_query(string, LOAD_DYNAMIC_FACTIONS, INVALID_PLAYER_ID, db_con2);

	format(string, sizeof(string), "SELECT * FROM samp_factions_weapons");
	mysql_query(string, LOAD_DYNAMIC_FACTIONS_WEAPONS, INVALID_PLAYER_ID, db_con2);

	format(string, sizeof(string), "SELECT * FROM samp_factions_weapons2");
	mysql_query(string, LOAD_DYNAMIC_FACTIONS_WEAPONS2, INVALID_PLAYER_ID, db_con2);

	return 1;
}

SaveDynamicFactions()
{	
	new string[256];

	for(new i = 0; i < sizeof(DynamicFactions); i++)
	{
		format(string, sizeof(string), "UPDATE `samp_factions` SET `Name` = '%s' , `X` = '%f' , `Y` = '%f' , `Z` = '%f' WHERE `ID` = '%d'", DynamicFactions[i][Name], DynamicFactions[i][fX], DynamicFactions[i][fY], DynamicFactions[i][fZ], i+1);
		mysql_query(string, SAVE2, INVALID_PLAYER_ID, db_con3);

		format(string, sizeof(string), "UPDATE `samp_factions` SET `Materials` = '%d' , `Drugs` = '%d' , `Bank` = '%d' WHERE `ID` = '%d'", DynamicFactions[i][fMaterials], DynamicFactions[i][fDrugs], DynamicFactions[i][fBank], i+1);
		mysql_query(string, SAVE2, INVALID_PLAYER_ID, db_con3);

		format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank1` = '%s' , `Rank2` = '%s' , `Rank3` = '%s' WHERE `ID` = '%d'", DynamicFactions[i][fRank1], DynamicFactions[i][fRank2], DynamicFactions[i][fRank3], i+1);
		mysql_query(string, SAVE2, INVALID_PLAYER_ID, db_con3);

		format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank4` = '%s' , `Rank5` = '%s' , `Rank6` = '%s' WHERE `ID` = '%d'", DynamicFactions[i][fRank4], DynamicFactions[i][fRank5], DynamicFactions[i][fRank6], i+1);
		mysql_query(string, SAVE2, INVALID_PLAYER_ID, db_con3);

		format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank7` = '%s' , `Rank8` = '%s' , `Rank9` = '%s' WHERE `ID` = '%d'", DynamicFactions[i][fRank7], DynamicFactions[i][fRank8], DynamicFactions[i][fRank10], i+1);
		mysql_query(string, SAVE2, INVALID_PLAYER_ID, db_con3);

		format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank10` = '%s' , `Skin1` = '%d' , `Skin2` = '%d' , `Skin3` = '%d' WHERE `ID` = '%d'", DynamicFactions[i][fRank10], DynamicFactions[i][fSkin1], DynamicFactions[i][fSkin2], DynamicFactions[i][fSkin3], i+1);
		mysql_query(string, SAVE2, INVALID_PLAYER_ID, db_con3);

		format(string, sizeof(string), "UPDATE `samp_factions` SET `Skin4` = '%d' , `Skin5` = '%d' , `Skin6` = '%d' , `Skin7` = '%d' WHERE `ID` = '%d'", DynamicFactions[i][fSkin4], DynamicFactions[i][fSkin5], DynamicFactions[i][fSkin6], DynamicFactions[i][fSkin7], i+1);
		mysql_query(string, SAVE2, INVALID_PLAYER_ID, db_con3);

		format(string, sizeof(string), "UPDATE `samp_factions` SET `Skin8` = '%d' , `Skin9` = '%d' , `Skin10` = '%d' , `JoinRank` = '%d' WHERE `ID` = '%d'", DynamicFactions[i][fSkin8], DynamicFactions[i][fSkin9], DynamicFactions[i][fSkin10], DynamicFactions[i][fJoinRank], i+1);
		mysql_query(string, SAVE2, INVALID_PLAYER_ID, db_con3);

		format(string, sizeof(string), "UPDATE `samp_factions` SET `UseSkins` = '%d' , `Type` = '%d' , `RankAmount` = '%d' , `Color` = '%d' WHERE `ID` = '%d'", DynamicFactions[i][fUseSkins], DynamicFactions[i][fType], DynamicFactions[i][fRankAmount], DynamicFactions[i][fColor], i+1);
		mysql_query(string, SAVE2, INVALID_PLAYER_ID, db_con3);

		format(string, sizeof(string), "UPDATE `samp_factions` SET `MaxCars` = '%d' , `CarsCount` = '%d' , `XDuty` = '%f' , `YDuty` = '%f' WHERE `ID` = '%d'", DynamicFactions[i][fMaxCars], DynamicFactions[i][fCarsCount], DynamicFactions[i][fXDuty], DynamicFactions[i][fYDuty], i+1);
		mysql_query(string, SAVE2, INVALID_PLAYER_ID, db_con3);

		format(string, sizeof(string), "UPDATE `samp_factions` SET `ZDuty` = '%f' , `WorldDuty` = '%d' WHERE `ID` = '%d'", DynamicFactions[i][fZDuty], DynamicFactions[i][fWorldDuty], i+1);
		mysql_query(string, SAVE2, INVALID_PLAYER_ID, db_con3);
	}
	return 1;
}

LoadBuildings()
{
	new string[128];

	format(string, sizeof(string), "SELECT * FROM samp_buildings");
	mysql_query(string, LOAD_BUILDINGS, INVALID_PLAYER_ID, db_con2);
	return 1;
}

SaveBuildings()
{
	new string[256];
	
	for(new i = 0; i < sizeof(Building); i++)
	{	
		format(string, sizeof(string), "UPDATE `samp_buildings` SET `BuildingName` = '%s' , `EnterX` = '%f' , `EnterY` = '%f' WHERE `ID` = '%d'", Building[i][BuildingName], Building[i][EnterX], Building[i][EnterY], i+1 );
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
		
		format(string, sizeof(string), "UPDATE `samp_buildings` SET `EnterZ` = '%f' , `EntranceFee` = %d , `EnterWorld` = %d WHERE `ID` = '%d'", Building[i][EnterZ], Building[i][EntranceFee], Building[i][EnterWorld], i+1 );
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
		
		format(string, sizeof(string), "UPDATE `samp_buildings` SET `EnterInterior` = %d , `EnterAngle` = %f , `ExitX` = %f WHERE `ID` = '%d'", Building[i][EnterInterior], Building[i][EnterAngle], Building[i][ExitX], i+1 );
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
		
		format(string, sizeof(string), "UPDATE `samp_buildings` SET `ExitY` = %f , `ExitInterior` = %d , `ExitAngle` = '%f' WHERE `ID` = '%d'", Building[i][ExitY], Building[i][ExitInterior], Building[i][ExitAngle], i+1 );
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
		
		format(string, sizeof(string), "UPDATE `samp_buildings` SET `Locked` = %d , `Opened` = %d , `Closed` = %d WHERE `ID` = '%d'", Building[i][Locked], Building[i][Opened], Building[i][Closed], i+1 );
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
		
		format(string, sizeof(string), "UPDATE `samp_buildings` SET `ObjectID` = %d , `BuildingType` = %d WHERE `ID` = '%d'", Building[i][ObjectID], Building[i][BuildingType], i+1 );
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
	}		
	return 1;
}

LoadHouses(hsource)
{
	if(hsource == 0)
	{
		new arrCoords[22][64];
		new strFromFile2[256];
		new File: file = fopen("houses/houses.cfg", io_read);
		if (file)
		{
			new idx;
			while (idx < sizeof(Houses))
			{
				fread(file, strFromFile2);
				split2(strFromFile2, arrCoords, '|');
				strmid(Houses[idx][Description], arrCoords[0], 0, strlen(arrCoords[0]), 255);
				strmid(Houses[idx][Owner], arrCoords[1], 0, strlen(arrCoords[1]), 255);
				Houses[idx][EnterX] = floatstr(arrCoords[2]);
				Houses[idx][EnterY] = floatstr(arrCoords[3]);
				Houses[idx][EnterZ] = floatstr(arrCoords[4]);
				Houses[idx][EnterWorld] = strval(arrCoords[5]);
				Houses[idx][EnterInterior] = strval(arrCoords[6]);
				Houses[idx][EnterAngle] = floatstr(arrCoords[7]);
				Houses[idx][ExitX] = floatstr(arrCoords[8]);
				Houses[idx][ExitY] = floatstr(arrCoords[9]);
				Houses[idx][ExitZ] = floatstr(arrCoords[10]);
				Houses[idx][ExitInterior] = strval(arrCoords[11]);
				Houses[idx][ExitAngle] = floatstr(arrCoords[12]);
				Houses[idx][Owned] = strval(arrCoords[13]);
				Houses[idx][Rentable] = strval(arrCoords[14]);
				Houses[idx][RentCost] = strval(arrCoords[15]);
				Houses[idx][HousePrice] = strval(arrCoords[16]);
				Houses[idx][Materials] = strval(arrCoords[17]);
				Houses[idx][Drugs] = strval(arrCoords[18]);
				Houses[idx][Money] = strval(arrCoords[19]);
				Houses[idx][Locked] = strval(arrCoords[20]);
				Houses[idx][PickupID] = strval(arrCoords[21]);

				if(Houses[idx][HousePrice] != 0) // Don't create the house icon if the cost is 0.
				{
					if(Houses[idx][Owned] == 0)
					{
						Houses[idx][PickupID] = CreateDynamicPickup(1273, 1, Houses[idx][EnterX], Houses[idx][EnterY], Houses[idx][EnterZ]);
					}
					else if(Houses[idx][Owned] == 1)
					{
						Houses[idx][PickupID] = CreateDynamicPickup(1239, 1, Houses[idx][EnterX], Houses[idx][EnterY], Houses[idx][EnterZ]);
					}
				}
				idx++;
			}
			fclose(file);
		}
	}
	else
	{
		new string[128];

		format(string, sizeof(string), "SELECT * FROM samp_houses LIMIT 300");
		mysql_query(string, LOAD_HOUSES, INVALID_PLAYER_ID, db_con2);
		
		format(string, sizeof(string), "SELECT * FROM samp_houses_items LIMIT 300");
		mysql_query(string, LOAD_HOUSES_ITEMS, INVALID_PLAYER_ID, db_con2);
	}
	return 1;
}

SaveHouses(hsource)
{
	if(hsource == 0)
	{
		new idx;
		new File: file2;
		while (idx < sizeof(Houses))
		{
			new coordsstring[256];
			format(coordsstring, sizeof(coordsstring), "%s|%s|%f|%f|%f|%d|%d|%f|%f|%f|%f|%d|%f|%d|%d|%d|%d|%d|%d|%d|%d|%d\n",
			Houses[idx][Description],
			Houses[idx][Owner],
			Houses[idx][EnterX],
			Houses[idx][EnterY],
			Houses[idx][EnterZ],
			Houses[idx][EnterWorld],
			Houses[idx][EnterInterior],
			Houses[idx][EnterAngle],
			Houses[idx][ExitX],
			Houses[idx][ExitY],
			Houses[idx][ExitZ],
			Houses[idx][ExitInterior],
			Houses[idx][ExitAngle],
			Houses[idx][Owned],
			Houses[idx][Rentable],
			Houses[idx][RentCost],
			Houses[idx][HousePrice],
			Houses[idx][Materials],
			Houses[idx][Drugs],
			Houses[idx][Money],
			Houses[idx][Locked],
			Houses[idx][PickupID]);

			if(idx == 0)
			{
				file2 = fopen("houses/houses.cfg", io_write);
			}
			else
			{
				file2 = fopen("houses/houses.cfg", io_append);
			}
			fwrite(file2, coordsstring);
			idx++;
			fclose(file2);
		}
	}
	else
	{
		new string[256];

		for(new i = 0; i < sizeof(Houses); i++)
		{
			format(string, sizeof(string), "UPDATE `samp_houses` SET `Description` = %s , `Owner` = '%s' , `EnterX` = '%f' WHERE `ID` = '%d'", Houses[i][Description], Houses[i][Owner], Houses[i][EnterX], i+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);

			format(string, sizeof(string), "UPDATE `samp_houses` SET `EnterY` = '%f' , `EnterZ` = '%f' , `EnterWorld` = '%d' WHERE `ID` = '%d'", Houses[i][EnterY], Houses[i][EnterZ], Houses[i][EnterWorld], i+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);

			format(string, sizeof(string), "UPDATE `samp_houses` SET `EnterInterior` = '%d' , `EnterAngle` = '%f' , `ExitX` = '%f' WHERE `ID` = '%d'", Houses[i][EnterInterior], Houses[i][EnterAngle], Houses[i][ExitX], i+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);

			format(string, sizeof(string), "UPDATE `samp_houses` SET `ExitY` = '%f' , `ExitZ` = '%f' , `ExitInterior` = '%f' WHERE `ID` = '%d'", Houses[i][ExitY], Houses[i][ExitZ], Houses[i][ExitInterior], i+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);

			format(string, sizeof(string), "UPDATE `samp_houses` SET `ExitAngle` = '%f' , `Owned` = '%d' , `Rentable` = '%d' WHERE `ID` = '%d'", Houses[i][ExitAngle], Houses[i][Owned], Houses[i][Rentable], i+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);

			format(string, sizeof(string), "UPDATE `samp_houses` SET `RentCost` = '%d' , `HousePrice` = '%d' , `Materials` = '%d' WHERE `ID` = '%d'", Houses[i][RentCost], Houses[i][HousePrice], Houses[i][Materials], i+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);

			format(string, sizeof(string), "UPDATE `samp_houses` SET `Drugs` = '%d' , `Money` = '%d' , `Locked` = '%d' WHERE `ID` = '%d'", Houses[i][Drugs], Houses[i][Money], Houses[i][Locked], i+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);

			// format(string, sizeof(string), "UPDATE `samp_houses` SET `PickupID` = '%d' WHERE `ID` = '%d'", Houses[i][PickupID], i+1);
			// mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			
			format(string, sizeof(string), "UPDATE `samp_houses_items` SET `HItem1` = '%d' , `HItem2` = '%d' , `HItem3` = '%d' , `HItem4` = '%d' WHERE `ID` = '%d'", Houses[i][HItem1], Houses[i][HItem2], Houses[i][HItem3], Houses[i][HItem4], i+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			
			format(string, sizeof(string), "UPDATE `samp_houses_items` SET `HItem5` = '%d' , `HItem1type` = '%d' , `HItem2type` = '%d' , `HItem3type` = '%d' WHERE `ID` = '%d'", Houses[i][HItem5], Houses[i][HItem1type], Houses[i][HItem2type], Houses[i][HItem3type], i+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			
			format(string, sizeof(string), "UPDATE `samp_houses_items` SET `HItem4type` = '%d' , `HItem5type` = '%d' , `HItem1param` = '%d' , `HItem2param` = '%d' WHERE `ID` = '%d'", Houses[i][HItem4type], Houses[i][HItem5type], Houses[i][HItem1param], Houses[i][HItem2param], i+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			
			format(string, sizeof(string), "UPDATE `samp_houses_items` SET `HItem3param` = '%d' , `HItem4param` = '%d' , `HItem5param` = '%d' , `HItem1param2` = '%d' WHERE `ID` = '%d'", Houses[i][HItem3param], Houses[i][HItem4param], Houses[i][HItem5param], Houses[i][HItem1param2], i+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			
			format(string, sizeof(string), "UPDATE `samp_houses_items` SET `HItem2param2` = '%d' , `HItem3param2` = '%d' , `HItem4param2` = '%d' , `HItem5param2` = '%d' WHERE `ID` = '%d'", Houses[i][HItem2param2], Houses[i][HItem3param2], Houses[i][HItem4param2], Houses[i][HItem5param2], i+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			
			format(string, sizeof(string), "UPDATE `samp_houses_items` SET `HItem1param3` = '%d' , `HItem2param3` = '%d' , `HItem3param3` = '%d' , `HItem4param3` = '%d' WHERE `ID` = '%d'", Houses[i][HItem1param3], Houses[i][HItem2param3], Houses[i][HItem3param3], Houses[i][HItem4param3], i+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			
			format(string, sizeof(string), "UPDATE `samp_houses_items` SET `HItem5param3` = '%d' , `HItem1param4` = '%d' , `HItem2param4` = '%d' , `HItem3param4` = '%d' WHERE `ID` = '%d'", Houses[i][HItem5param3], Houses[i][HItem1param4], Houses[i][HItem2param4], Houses[i][HItem3param4], i+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			
			format(string, sizeof(string), "UPDATE `samp_houses_items` SET `HItem4param4` = '%d' , `HItem5param4` = '%d' , `HItem1param5` = '%s' , `HItem2param5` = '%s' WHERE `ID` = '%d'", Houses[i][HItem4param4], Houses[i][HItem5param4], Houses[i][HItem1param5], Houses[i][HItem2param5], i+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			
			format(string, sizeof(string), "UPDATE `samp_houses_items` SET `HItem3param5` = '%d' , `HItem4param5` = '%d' , `HItem5param5` = '%s' WHERE `ID` = '%d'", Houses[i][HItem3param5], Houses[i][HItem4param5], Houses[i][HItem5param5], i+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
		}
	}
	return 1;
}

LoadBusinesses()
{
	new string[128];

	format(string, sizeof(string), "SELECT * FROM samp_businesses");
	mysql_query(string, LOAD_BUSINESSES, INVALID_PLAYER_ID, db_con2);
	return 1;
}

SaveBusinesses()
{
	new string[256];

	for(new i = 0; i < sizeof(Businesses); i++)
	{
		format(string, sizeof(string), "UPDATE `samp_businesses` SET `BusinessName` = '%s' , `Owner` = '%s' , `EnterX` = '%f' WHERE `ID` = '%d'", Businesses[i][BusinessName], Businesses[i][Owner], Businesses[i][EnterX], i+1);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);

		format(string, sizeof(string), "UPDATE `samp_businesses` SET `EnterY` = '%f' , `EnterZ` = '%f' , `EnterWorld` = '%d' WHERE `ID` = '%d'", Businesses[i][EnterY], Businesses[i][EnterZ], Businesses[i][EnterWorld], i+1);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);

		format(string, sizeof(string), "UPDATE `samp_businesses` SET `EnterInterior` = '%d' , `EnterAngle` = '%f' , `ExitX` = '%f' WHERE `ID` = '%d'", Businesses[i][EnterInterior], Businesses[i][EnterAngle], Businesses[i][ExitX], i+1);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);

		format(string, sizeof(string), "UPDATE `samp_businesses` SET `ExitY` = '%f' , `ExitZ` = '%f' , `ExitInterior` = '%d' WHERE `ID` = '%d'", Businesses[i][ExitY], Businesses[i][ExitZ], Businesses[i][ExitInterior], i+1);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);

		format(string, sizeof(string), "UPDATE `samp_businesses` SET `ExitAngle` = '%f' , `Owned` = '%d' , `Enterable` = '%d' WHERE `ID` = '%d'", Businesses[i][ExitAngle], Businesses[i][Owned], Businesses[i][Enterable], i+1);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);

		format(string, sizeof(string), "UPDATE `samp_businesses` SET `BizPrice` = '%d' , `EntranceCost` = '%d' , `Till` = '%d' WHERE `ID` = '%d'", Businesses[i][BizPrice], Businesses[i][EntranceCost], Businesses[i][Till], i+1);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);

		format(string, sizeof(string), "UPDATE `samp_businesses` SET `Locked` = '%d' , `BizType` = '%d' , `Products` = '%d' WHERE `ID` = '%d'", Businesses[i][Locked], Businesses[i][BizType], Businesses[i][Products], i+1);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);

		format(string, sizeof(string), "UPDATE `samp_businesses` SET `PickupID` = '%d' , `VehicleSpawned` = '%d' , `VehicleCount` = '%d' WHERE `ID` = '%d'", Businesses[i][PickupID], Businesses[i][VehicleSpawned], Businesses[i][VehicleCount], i+1);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);

		format(string, sizeof(string), "UPDATE `samp_businesses` SET `MaxVehicles` = '%d' , `VehicleOrderCount` = '%d' WHERE `ID` = '%d'", Businesses[i][MaxVehicles], Businesses[i][VehicleOrderCount], i+1);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
	}
	return 1;
}

LoadCivilianSpawn()
{
	new arrCoords[6][64];
	new strFromFile2[256];
	new File: file = fopen("locations/civilianspawn.cfg", io_read);
	if (file)
	{
		fread(file, strFromFile2);
		split2(strFromFile2, arrCoords, '|');
		CivilianSpawn[X] = floatstr(arrCoords[0]);
		CivilianSpawn[Y] = floatstr(arrCoords[1]);
		CivilianSpawn[Z] = floatstr(arrCoords[2]);
		CivilianSpawn[World] = strval(arrCoords[3]);
		CivilianSpawn[Interior] = strval(arrCoords[4]);
		CivilianSpawn[Angle] = floatstr(arrCoords[5]);
	}
	fclose(file);
	return 1;
}

SaveCivilianSpawn()
{
	new File: file2;
	new coordsstring[512];
	format(coordsstring, sizeof(coordsstring), "%f|%f|%f|%d|%d|%f\n",
	CivilianSpawn[X],
	CivilianSpawn[Y],
	CivilianSpawn[Z],
	CivilianSpawn[World],
	CivilianSpawn[Interior],
	CivilianSpawn[Angle]);
	file2 = fopen("locations/civilianspawn.cfg", io_write);
	fwrite(file2, coordsstring);
	fclose(file2);
	return 1;
}

LoadFactionMaterialsStorage()
{
	new arrCoords[7][64];
	new strFromFile2[256];
	new File: file = fopen("locations/factionmatsstorage.cfg", io_read);
	if (file)
	{
		fread(file, strFromFile2);
		split2(strFromFile2, arrCoords, '|');
		FactionMaterialsStorage[X] = floatstr(arrCoords[0]);
		FactionMaterialsStorage[Y] = floatstr(arrCoords[1]);
		FactionMaterialsStorage[Z] = floatstr(arrCoords[2]);
		FactionMaterialsStorage[World] = strval(arrCoords[3]);
		FactionMaterialsStorage[Interior] = strval(arrCoords[4]);
		FactionMaterialsStorage[Angle] = floatstr(arrCoords[5]);
		FactionMaterialsStorage[PickupID] = strval(arrCoords[6]);
		//Creating Pickup
        FactionMaterialsStorage[PickupID] = CreateDynamicPickup(1254,1,FactionMaterialsStorage[X],FactionMaterialsStorage[Y],FactionMaterialsStorage[Z]); // Faction Materials Storage Facility
        print("[INFO:] Faction materials storage location loaded");
	}
	fclose(file);
	return 1;
}

SaveFactionMaterialsStorage()
{
	new File: file2;
	new coordsstring[512];
	format(coordsstring, sizeof(coordsstring), "%f|%f|%f|%d|%d|%f|%d\n",
	FactionMaterialsStorage[X],
	FactionMaterialsStorage[Y],
	FactionMaterialsStorage[Z],
	FactionMaterialsStorage[World],
	FactionMaterialsStorage[Interior],
	FactionMaterialsStorage[Angle],
	FactionMaterialsStorage[PickupID]);
	file2 = fopen("locations/factionmatsstorage.cfg", io_write);
	fwrite(file2, coordsstring);
	fclose(file2);
	return 1;
}

LoadFactionDrugsStorage()
{
	new arrCoords[7][64];
	new strFromFile2[256];
	new File: file = fopen("locations/factiondrugsstorage.cfg", io_read);
	if (file)
	{
		fread(file, strFromFile2);
		split2(strFromFile2, arrCoords, '|');
		FactionDrugsStorage[X] = floatstr(arrCoords[0]);
		FactionDrugsStorage[Y] = floatstr(arrCoords[1]);
		FactionDrugsStorage[Z] = floatstr(arrCoords[2]);
		FactionDrugsStorage[World] = strval(arrCoords[3]);
		FactionDrugsStorage[Interior] = strval(arrCoords[4]);
		FactionDrugsStorage[Angle] = floatstr(arrCoords[5]);
		FactionDrugsStorage[PickupID] = strval(arrCoords[6]);
		//Creating Pickup
        FactionDrugsStorage[PickupID] = CreateDynamicPickup(1279,1,FactionDrugsStorage[X],FactionDrugsStorage[Y],FactionDrugsStorage[Z]); // Faction Materials Storage Facility
        print("[INFO:] Faction drugs storage location loaded");
	}
	fclose(file);
	return 1;
}

SaveFactionDrugsStorage()
{
	new File: file2;
	new coordsstring[512];
	format(coordsstring, sizeof(coordsstring), "%f|%f|%f|%d|%d|%f|%d\n",
	FactionDrugsStorage[X],
	FactionDrugsStorage[Y],
	FactionDrugsStorage[Z],
	FactionDrugsStorage[World],
	FactionDrugsStorage[Interior],
	FactionDrugsStorage[Angle],
	FactionDrugsStorage[PickupID]);
	file2 = fopen("locations/factiondrugsstorage.cfg", io_write);
	fwrite(file2, coordsstring);
	fclose(file2);
	return 1;
}

LoadBankPosition()
{
	new arrCoords[7][64];
	new strFromFile2[256];
	new File: file = fopen("locations/banklocation.cfg", io_read);
	if (file)
	{
		fread(file, strFromFile2);
		split2(strFromFile2, arrCoords, '|');
		BankPosition[X] = floatstr(arrCoords[0]);
		BankPosition[Y] = floatstr(arrCoords[1]);
		BankPosition[Z] = floatstr(arrCoords[2]);
		BankPosition[World] = strval(arrCoords[3]);
		BankPosition[Interior] = strval(arrCoords[4]);
		BankPosition[Angle] = floatstr(arrCoords[5]);
		BankPosition[PickupID] = strval(arrCoords[6]);
		//Creating Pickup
        BankPosition[PickupID] = CreateDynamicPickup(1239,1,BankPosition[X],BankPosition[Y],BankPosition[Z]);
        print("[INFO:] Bank location loaded");
	}
	fclose(file);
	return 1;
}

SaveBankPosition()
{
	new File: file2;
	new coordsstring[512];
	format(coordsstring, sizeof(coordsstring), "%f|%f|%f|%d|%d|%f|%d\n",
	BankPosition[X],
	BankPosition[Y],
	BankPosition[Z],
	BankPosition[World],
	BankPosition[Interior],
	BankPosition[Angle],
	BankPosition[PickupID]);
	file2 = fopen("locations/banklocation.cfg", io_write);
	fwrite(file2, coordsstring);
	fclose(file2);
	return 1;
}

LoadBankPosition2()
{
	new arrCoords[7][64];
	new strFromFile2[256];
	new File: file = fopen("locations/banklocation2.cfg", io_read);
	if (file)
	{
		fread(file, strFromFile2);
		split2(strFromFile2, arrCoords, '|');
		BankPosition2[X] = floatstr(arrCoords[0]);
		BankPosition2[Y] = floatstr(arrCoords[1]);
		BankPosition2[Z] = floatstr(arrCoords[2]);
		BankPosition2[World] = strval(arrCoords[3]);
		BankPosition2[Interior] = strval(arrCoords[4]);
		BankPosition2[Angle] = floatstr(arrCoords[5]);
		BankPosition2[PickupID] = strval(arrCoords[6]);
		//Creating Pickup
        BankPosition[PickupID] = CreateDynamicPickup(1239,1,BankPosition2[X],BankPosition2[Y],BankPosition2[Z]);
        print("[INFO:] Bank location loaded");
	}
	fclose(file);
	return 1;
}

SaveBankPosition2()
{
	new File: file2;
	new coordsstring[512];
	format(coordsstring, sizeof(coordsstring), "%f|%f|%f|%d|%d|%f|%d\n",
	BankPosition2[X],
	BankPosition2[Y],
	BankPosition2[Z],
	BankPosition2[World],
	BankPosition2[Interior],
	BankPosition2[Angle],
	BankPosition2[PickupID]);
	file2 = fopen("locations/banklocation2.cfg", io_write);
	fwrite(file2, coordsstring);
	fclose(file2);
	return 1;
}

LoadDrivingTestPosition()
{
	new arrCoords[7][64];
	new strFromFile2[256];
	new File: file = fopen("locations/drivingtestlocation.cfg", io_read);
	if (file)
	{
		fread(file, strFromFile2);
		split2(strFromFile2, arrCoords, '|');
		DrivingTestPosition[X] = floatstr(arrCoords[0]);
		DrivingTestPosition[Y] = floatstr(arrCoords[1]);
		DrivingTestPosition[Z] = floatstr(arrCoords[2]);
		DrivingTestPosition[World] = strval(arrCoords[3]);
		DrivingTestPosition[Interior] = strval(arrCoords[4]);
		DrivingTestPosition[Angle] = floatstr(arrCoords[5]);
		DrivingTestPosition[PickupID] = strval(arrCoords[6]);
		//Creating Pickup
        DrivingTestPosition[PickupID] = CreateDynamicPickup(1239,1,DrivingTestPosition[X],DrivingTestPosition[Y],DrivingTestPosition[Z]);
        print("[INFO:] Driving test location loaded");
	}
	fclose(file);
	return 1;
}

SaveDrivingTestPosition()
{
	new File: file2;
	new coordsstring[512];
	format(coordsstring, sizeof(coordsstring), "%f|%f|%f|%d|%d|%f|%d\n",
	DrivingTestPosition[X],
	DrivingTestPosition[Y],
	DrivingTestPosition[Z],
	DrivingTestPosition[World],
	DrivingTestPosition[Interior],
	DrivingTestPosition[Angle],
	DrivingTestPosition[PickupID]);
	file2 = fopen("locations/drivingtestlocation.cfg", io_write);
	fwrite(file2, coordsstring);
	fclose(file2);
	return 1;
}

LoadSkillPosition()
{
	new arrCoords[11][64];
	new strFromFile2[128];
	new File: file = fopen("locations/skilllocation.cfg", io_read);
	if (file)
	{
		fread(file, strFromFile2);
		split2(strFromFile2, arrCoords, '|');
		SkillPosition[XMic] = floatstr(arrCoords[0]);
		SkillPosition[YMic] = floatstr(arrCoords[1]);
		SkillPosition[ZMic] = floatstr(arrCoords[2]);
		SkillPosition[XMp5] = floatstr(arrCoords[2]);
		SkillPosition[YMp5] = floatstr(arrCoords[3]);
		SkillPosition[ZMp5] = floatstr(arrCoords[4]);
		SkillPosition[XAk] = floatstr(arrCoords[5]);
		SkillPosition[YAk] = floatstr(arrCoords[6]);
		SkillPosition[ZAk] = floatstr(arrCoords[7]);
		SkillPosition[PickupIDMic] = strval(arrCoords[8]);
		SkillPosition[PickupIDMp5] = strval(arrCoords[9]);
		SkillPosition[PickupIDAk] = strval(arrCoords[10]);
		//Creating Pickup
		SkillPosition[PickupIDMic] = CreateDynamicPickup(1239,1,SkillPosition[XMic],SkillPosition[YMic],SkillPosition[ZMic]);
		SkillPosition[PickupIDMp5] = CreateDynamicPickup(1239,1,SkillPosition[XMp5],SkillPosition[YMp5],SkillPosition[ZMp5]);
		SkillPosition[PickupIDAk] = CreateDynamicPickup(1239,1,SkillPosition[XAk],SkillPosition[YAk],SkillPosition[ZAk]);
		print("[INFO:] Skill location loaded");
	}
	fclose(file);
	return 1;
}

SaveSkillPosition()
{
	new File: file2;
	new coordsstring[128];
	format(coordsstring, sizeof(coordsstring), "%f|%f|%f|%f|%f|%f|%f|%f|%f|%d|%d|%d\n",
	SkillPosition[XMic],
	SkillPosition[YMic],
	SkillPosition[ZMic],
	SkillPosition[XMp5],
	SkillPosition[YMp5],
	SkillPosition[ZMp5],
	SkillPosition[XAk],
	SkillPosition[YAk],
	SkillPosition[ZAk],
	SkillPosition[PickupIDMic],
	SkillPosition[PickupIDMp5],
	SkillPosition[PickupIDAk]);
	file2 = fopen("locations/skilllocation.cfg", io_write);
	fwrite(file2, coordsstring);
	fclose(file2);
	return 1;
}

LoadSkillPositionb()
{
	new arrCoords[16][64];
	new strFromFile2[128];
	new File: file = fopen("locations/skilllocationb.cfg", io_read);
	if (file)
	{
		fread(file, strFromFile2);
		split2(strFromFile2, arrCoords, '|');
		SkillPosition[XPis] = floatstr(arrCoords[0]);
		SkillPosition[YPis] = floatstr(arrCoords[1]);
		SkillPosition[ZPis] = floatstr(arrCoords[2]);
		SkillPosition[XSil] = floatstr(arrCoords[3]);
		SkillPosition[YSil] = floatstr(arrCoords[4]);
		SkillPosition[ZSil] = floatstr(arrCoords[5]);
		SkillPosition[XDes] = floatstr(arrCoords[6]);
		SkillPosition[YDes] = floatstr(arrCoords[7]);
		SkillPosition[ZDes] = floatstr(arrCoords[8]);
		SkillPosition[XSho] = floatstr(arrCoords[9]);
		SkillPosition[YSho] = floatstr(arrCoords[10]);
		SkillPosition[ZSho] = floatstr(arrCoords[11]);
		SkillPosition[PickupIDPis] = strval(arrCoords[12]);
		SkillPosition[PickupIDSil] = strval(arrCoords[13]);
		SkillPosition[PickupIDDes] = strval(arrCoords[14]);
		SkillPosition[PickupIDSho] = strval(arrCoords[15]);
		//Creating Pickup
        SkillPosition[PickupIDPis] = CreateDynamicPickup(1239,1,SkillPosition[XPis],SkillPosition[YPis],SkillPosition[ZPis]);
        SkillPosition[PickupIDSil] = CreateDynamicPickup(1239,1,SkillPosition[XSil],SkillPosition[YSil],SkillPosition[ZSil]);
		SkillPosition[PickupIDDes] = CreateDynamicPickup(1239,1,SkillPosition[XDes],SkillPosition[YDes],SkillPosition[ZDes]);
		SkillPosition[PickupIDSho] = CreateDynamicPickup(1239,1,SkillPosition[XSho],SkillPosition[YSho],SkillPosition[ZSho]);

		print("[INFO:] Skill 2 location loaded");
	}
	fclose(file);
	return 1;
}

SaveSkillPositionb()
{
	new File: file2;
	new coordsstring[128];
	format(coordsstring, sizeof(coordsstring), "%f|%f|%f|%f|%f|%f|%f|%f|%f|%f|%f|%f|%d|%d|%d|%d\n",
	SkillPosition[XPis],
	SkillPosition[YPis],
	SkillPosition[ZPis],
	SkillPosition[XSil],
	SkillPosition[YSil],
	SkillPosition[ZSil],
	SkillPosition[XDes],
	SkillPosition[YDes],
	SkillPosition[ZDes],
	SkillPosition[XSho],
	SkillPosition[YSho],
	SkillPosition[ZSho],
	SkillPosition[PickupIDPis],
	SkillPosition[PickupIDSil],
	SkillPosition[PickupIDDes],
	SkillPosition[PickupIDSho]);
	file2 = fopen("locations/skilllocationb.cfg", io_write);
	fwrite(file2, coordsstring);
	fclose(file2);
	return 1;
}

LoadSkillPositionc()
{
	new arrCoords[16][64];
	new strFromFile2[128];
	new File: file = fopen("locations/skilllocationc.cfg", io_read);
	if (file)
	{
		fread(file, strFromFile2);
		split2(strFromFile2, arrCoords, '|');
		SkillPosition[XSha] = floatstr(arrCoords[0]);
		SkillPosition[YSha] = floatstr(arrCoords[1]);
		SkillPosition[ZSha] = floatstr(arrCoords[2]);
		SkillPosition[XSpa] = floatstr(arrCoords[3]);
		SkillPosition[YSpa] = floatstr(arrCoords[4]);
		SkillPosition[ZSpa] = floatstr(arrCoords[5]);
		SkillPosition[XM4] = floatstr(arrCoords[6]);
		SkillPosition[YM4] = floatstr(arrCoords[7]);
		SkillPosition[ZM4] = floatstr(arrCoords[8]);
		SkillPosition[XSni] = floatstr(arrCoords[9]);
		SkillPosition[YSni] = floatstr(arrCoords[10]);
		SkillPosition[ZSni] = floatstr(arrCoords[11]);
		SkillPosition[PickupIDSha] = strval(arrCoords[12]);
		SkillPosition[PickupIDSpa] = strval(arrCoords[13]);
		SkillPosition[PickupIDM4] = strval(arrCoords[14]);
		SkillPosition[PickupIDSni] = strval(arrCoords[15]);
		//Creating Pickup
		SkillPosition[PickupIDSha] = CreateDynamicPickup(1239,1,SkillPosition[XSha],SkillPosition[YSha],SkillPosition[ZSha]);
		SkillPosition[PickupIDSpa] = CreateDynamicPickup(1239,1,SkillPosition[XSpa],SkillPosition[YSpa],SkillPosition[ZSpa]);
		SkillPosition[PickupIDM4] = CreateDynamicPickup(1239,1,SkillPosition[XM4],SkillPosition[YM4],SkillPosition[ZM4]);
		SkillPosition[PickupIDSni] = CreateDynamicPickup(1239,1,SkillPosition[XSni],SkillPosition[YSni],SkillPosition[ZSni]);

		print("[INFO:] Skill 3 location loaded");
	}
	fclose(file);
	return 1;
}

SaveSkillPositionc()
{
	new File: file2;
	new coordsstring[128];
	format(coordsstring, sizeof(coordsstring), "%f|%f|%f|%f|%f|%f|%f|%f|%f|%f|%f|%f|%d|%d|%d|%d\n",
	SkillPosition[XSha],
	SkillPosition[YSha],
	SkillPosition[ZSha],
	SkillPosition[XSpa],
	SkillPosition[YSpa],
	SkillPosition[ZSpa],
	SkillPosition[XM4],
	SkillPosition[YM4],
	SkillPosition[ZM4],
	SkillPosition[XSni],
	SkillPosition[YSni],
	SkillPosition[ZSni],
	SkillPosition[PickupIDSha],
	SkillPosition[PickupIDSpa],
	SkillPosition[PickupIDM4],
	SkillPosition[PickupIDSni]);
	file2 = fopen("locations/skilllocationc.cfg", io_write);
	fwrite(file2, coordsstring);
	fclose(file2);
	return 1;
}

LoadSkillPositiond()
{
	new arrCoords[16][64];
	new strFromFile2[128];
	new File: file = fopen("locations/skilllocationd.cfg", io_read);
	if (file)
	{
		fread(file, strFromFile2);
		split2(strFromFile2, arrCoords, '|');
		SkillPosition[XAng] = floatstr(arrCoords[0]);
		SkillPosition[YAng] = floatstr(arrCoords[1]);
		SkillPosition[ZAng] = floatstr(arrCoords[2]);
		SkillPosition[XWf] = floatstr(arrCoords[3]);
		SkillPosition[YWf] = floatstr(arrCoords[4]);
		SkillPosition[ZWf] = floatstr(arrCoords[5]);
		SkillPosition[XMat] = floatstr(arrCoords[6]);
		SkillPosition[YMat] = floatstr(arrCoords[7]);
		SkillPosition[ZMat] = floatstr(arrCoords[8]);
		SkillPosition[XPol] = floatstr(arrCoords[9]);
		SkillPosition[YPol] = floatstr(arrCoords[10]);
		SkillPosition[ZPol] = floatstr(arrCoords[11]);
		SkillPosition[PickupIDAng] = strval(arrCoords[12]);
		SkillPosition[PickupIDWf] = strval(arrCoords[13]);
		SkillPosition[PickupIDMat] = strval(arrCoords[14]);
		SkillPosition[PickupIDPol] = strval(arrCoords[15]);
		//Creating Pickup
		SkillPosition[PickupIDAng] = CreateDynamicPickup(1239,1,SkillPosition[XAng],SkillPosition[YAng],SkillPosition[ZAng]);
		SkillPosition[PickupIDWf] = CreateDynamicPickup(1239,1,SkillPosition[XWf],SkillPosition[YWf],SkillPosition[ZWf]);
		SkillPosition[PickupIDMat] = CreateDynamicPickup(1239,1,SkillPosition[XMat],SkillPosition[YMat],SkillPosition[ZMat]);
		SkillPosition[PickupIDPol] = CreateDynamicPickup(1239,1,SkillPosition[XPol],SkillPosition[YPol],SkillPosition[ZPol]);

		print("[INFO:] Skill 4 location loaded");
	}
	fclose(file);
	return 1;
}

SaveSkillPositiond()
{
	new File: file2;
	new coordsstring[128];
	format(coordsstring, sizeof(coordsstring), "%f|%f|%f|%f|%f|%f|%f|%f|%f|%f|%f|%f|%d|%d|%d|%d\n",
	SkillPosition[XAng],
	SkillPosition[YAng],
	SkillPosition[ZAng],
	SkillPosition[XWf],
	SkillPosition[YWf],
	SkillPosition[ZWf],
	SkillPosition[XMat],
	SkillPosition[YMat],
	SkillPosition[ZMat],
	SkillPosition[XPol],
	SkillPosition[YPol],
	SkillPosition[ZPol],
	SkillPosition[PickupIDAng],
	SkillPosition[PickupIDWf],
	SkillPosition[PickupIDMat],
	SkillPosition[PickupIDPol]);
	file2 = fopen("locations/skilllocationd.cfg", io_write);
	fwrite(file2, coordsstring);
	fclose(file2);
	return 1;
}

LoadSkillPositione()
{
	new arrCoords[12][64];
	new strFromFile2[128];
	new File: file = fopen("locations/skilllocatione.cfg", io_read);
	if (file)
	{
		fread(file, strFromFile2);
		split2(strFromFile2, arrCoords, '|');
		SkillPosition[XHis] = floatstr(arrCoords[0]);
		SkillPosition[YHis] = floatstr(arrCoords[1]);
		SkillPosition[ZHis] = floatstr(arrCoords[2]);
		SkillPosition[XFiz] = floatstr(arrCoords[3]);
		SkillPosition[YFiz] = floatstr(arrCoords[4]);
		SkillPosition[ZFiz] = floatstr(arrCoords[5]);
		SkillPosition[XBio] = floatstr(arrCoords[6]);
		SkillPosition[YBio] = floatstr(arrCoords[7]);
		SkillPosition[ZBio] = floatstr(arrCoords[8]);
		SkillPosition[PickupIDHis] = strval(arrCoords[9]);
		SkillPosition[PickupIDFiz] = strval(arrCoords[10]);
		SkillPosition[PickupIDBio] = strval(arrCoords[11]);
		//Creating Pickup
		SkillPosition[PickupIDHis] = CreateDynamicPickup(1239,1,SkillPosition[XHis],SkillPosition[YHis],SkillPosition[ZHis]);
		SkillPosition[PickupIDFiz] = CreateDynamicPickup(1239,1,SkillPosition[XFiz],SkillPosition[YFiz],SkillPosition[ZFiz]);
		SkillPosition[PickupIDBio] = CreateDynamicPickup(1239,1,SkillPosition[XBio],SkillPosition[YBio],SkillPosition[ZBio]);
		print("[INFO:] Skill 5 location loaded");
	}
	fclose(file);
	return 1;
}

SaveSkillPositione()
{
	new File: file2;
	new coordsstring[128];
	format(coordsstring, sizeof(coordsstring), "%f|%f|%f|%f|%f|%f|%f|%f|%f|%d|%d|%d\n",
	SkillPosition[XHis],
	SkillPosition[YHis],
	SkillPosition[ZHis],
	SkillPosition[XFiz],
	SkillPosition[YFiz],
	SkillPosition[ZFiz],
	SkillPosition[XBio],
	SkillPosition[YBio],
	SkillPosition[ZBio],
	SkillPosition[PickupIDHis],
	SkillPosition[PickupIDFiz],
	SkillPosition[PickupIDBio]);
	file2 = fopen("locations/skilllocatione.cfg", io_write);
	fwrite(file2, coordsstring);
	fclose(file2);
	return 1;
}

LoadBoatTestPosition()
{
	new arrCoords[7][64];
	new strFromFile2[256];
	new File: file = fopen("locations/boattestlocation.cfg", io_read);
	if (file)
	{
		fread(file, strFromFile2);
		split2(strFromFile2, arrCoords, '|');
		BoatTestPosition[X] = floatstr(arrCoords[0]);
		BoatTestPosition[Y] = floatstr(arrCoords[1]);
		BoatTestPosition[Z] = floatstr(arrCoords[2]);
		BoatTestPosition[World] = strval(arrCoords[3]);
		BoatTestPosition[Interior] = strval(arrCoords[4]);
		BoatTestPosition[Angle] = floatstr(arrCoords[5]);
		BoatTestPosition[PickupID] = strval(arrCoords[6]);
		//Creating Pickup
        BoatTestPosition[PickupID] = CreateDynamicPickup(1239,1,BoatTestPosition[X],BoatTestPosition[Y],BoatTestPosition[Z]);
        print("[INFO:] Boat test location loaded");
	}
	fclose(file);
	return 1;
}

SaveBoatTestPosition()
{
	new File: file2;
	new coordsstring[512];
	format(coordsstring, sizeof(coordsstring), "%f|%f|%f|%d|%d|%f|%d\n",
	BoatTestPosition[X],
	BoatTestPosition[Y],
	BoatTestPosition[Z],
	BoatTestPosition[World],
	BoatTestPosition[Interior],
	BoatTestPosition[Angle],
	BoatTestPosition[PickupID]);
	file2 = fopen("locations/boattestlocation.cfg", io_write);
	fwrite(file2, coordsstring);
	fclose(file2);
	return 1;
}

LoadFlyingTestPosition()
{
	new arrCoords[7][64];
	new strFromFile2[256];
	new File: file = fopen("locations/flyingtestlocation.cfg", io_read);
	if (file)
	{
		fread(file, strFromFile2);
		split2(strFromFile2, arrCoords, '|');
		FlyingTestPosition[X] = floatstr(arrCoords[0]);
		FlyingTestPosition[Y] = floatstr(arrCoords[1]);
		FlyingTestPosition[Z] = floatstr(arrCoords[2]);
		FlyingTestPosition[World] = strval(arrCoords[3]);
		FlyingTestPosition[Interior] = strval(arrCoords[4]);
		FlyingTestPosition[Angle] = floatstr(arrCoords[5]);
		FlyingTestPosition[PickupID] = strval(arrCoords[6]);
		//Creating Pickup
        FlyingTestPosition[PickupID] = CreateDynamicPickup(1239,1,FlyingTestPosition[X],FlyingTestPosition[Y],FlyingTestPosition[Z]);
        print("[INFO:] Flying test location loaded");
	}
	fclose(file);
	return 1;
}

SaveFlyingTestPosition()
{
	new File: file2;
	new coordsstring[512];
	format(coordsstring, sizeof(coordsstring), "%f|%f|%f|%d|%d|%f|%d\n",
	FlyingTestPosition[X],
	FlyingTestPosition[Y],
	FlyingTestPosition[Z],
	FlyingTestPosition[World],
	FlyingTestPosition[Interior],
	FlyingTestPosition[Angle],
	FlyingTestPosition[PickupID]);
	file2 = fopen("locations/flyingtestlocation.cfg", io_write);
	fwrite(file2, coordsstring);
	fclose(file2);
	return 1;
}

LoadWeaponLicensePosition()
{
	new arrCoords[7][64];
	new strFromFile2[256];
	new File: file = fopen("locations/weaponlicenselocation.cfg", io_read);
	if (file)
	{
		fread(file, strFromFile2);
		split2(strFromFile2, arrCoords, '|');
		WeaponLicensePosition[X] = floatstr(arrCoords[0]);
		WeaponLicensePosition[Y] = floatstr(arrCoords[1]);
		WeaponLicensePosition[Z] = floatstr(arrCoords[2]);
		WeaponLicensePosition[World] = strval(arrCoords[3]);
		WeaponLicensePosition[Interior] = strval(arrCoords[4]);
		WeaponLicensePosition[Angle] = floatstr(arrCoords[5]);
		WeaponLicensePosition[PickupID] = strval(arrCoords[6]);
		//Creating Pickup
        WeaponLicensePosition[PickupID] = CreateDynamicPickup(1239,1,WeaponLicensePosition[X],WeaponLicensePosition[Y],WeaponLicensePosition[Z]);
        print("[INFO:] Weapon License location loaded");
	}
	fclose(file);
	return 1;
}

SaveWeaponLicensePosition()
{
	new File: file2;
	new coordsstring[512];
	format(coordsstring, sizeof(coordsstring), "%f|%f|%f|%d|%d|%f|%d\n",
	WeaponLicensePosition[X],
	WeaponLicensePosition[Y],
	WeaponLicensePosition[Z],
	WeaponLicensePosition[World],
	WeaponLicensePosition[Interior],
	WeaponLicensePosition[Angle],
	WeaponLicensePosition[PickupID]);
	file2 = fopen("locations/weaponlicenselocation.cfg", io_write);
	fwrite(file2, coordsstring);
	fclose(file2);
	return 1;
}

LoadWheelChangePosition()
{
	new arrCoords[12][64];
	new strFromFile[256];
	new File: file = fopen("locations/wheelchangeposition.cfg", io_read);
	if(file)
	{
		fread(file, strFromFile);
		split2(strFromFile, arrCoords, '|');
		gWheelChangePos[pos1X] = floatstr(arrCoords[0]);
		gWheelChangePos[pos1Y] = floatstr(arrCoords[1]);
		gWheelChangePos[pos1Z] = floatstr(arrCoords[2]);
		gWheelChangePos[pos2X] = floatstr(arrCoords[3]);
		gWheelChangePos[pos2Y] = floatstr(arrCoords[4]);
		gWheelChangePos[pos2Z] = floatstr(arrCoords[5]);
		gWheelChangePos[pos3X] = floatstr(arrCoords[6]);
		gWheelChangePos[pos3Y] = floatstr(arrCoords[7]);
		gWheelChangePos[pos3Z] = floatstr(arrCoords[8]);
		gWheelChangePos[pos4X] = floatstr(arrCoords[9]);
		gWheelChangePos[pos4Y] = floatstr(arrCoords[10]);
		gWheelChangePos[pos4Z] = floatstr(arrCoords[11]);
		gWheelChangePos[pickup1] = CreateDynamicPickup(1239, 1, gWheelChangePos[pos1X], gWheelChangePos[pos1Y], gWheelChangePos[pos1Z]);
		gWheelChangePos[pickup2] = CreateDynamicPickup(1239, 1, gWheelChangePos[pos2X], gWheelChangePos[pos2Y], gWheelChangePos[pos2Z]);
		gWheelChangePos[pickup3] = CreateDynamicPickup(1239, 1, gWheelChangePos[pos3X], gWheelChangePos[pos3Y], gWheelChangePos[pos3Z]);
		gWheelChangePos[pickup4] = CreateDynamicPickup(1239, 1, gWheelChangePos[pos4X], gWheelChangePos[pos4Y], gWheelChangePos[pos4Z]);
		print("[INFO:] Wheel change locations loaded");
	}
	fclose(file);
	return 1;
}

SaveWheelChangePosition()
{
	new File: file;
	new coordstring[512];
	format(coordstring, sizeof(coordstring), "%f|%f|%f|%f|%f|%f|%f|%f|%f|%f|%f|%f\n",
	gWheelChangePos[pos1X],
	gWheelChangePos[pos1Y],
	gWheelChangePos[pos1Z],
	gWheelChangePos[pos2X],
	gWheelChangePos[pos2Y],
	gWheelChangePos[pos2Z],
	gWheelChangePos[pos3X],
	gWheelChangePos[pos3Y],
	gWheelChangePos[pos3Z],
	gWheelChangePos[pos4X],
	gWheelChangePos[pos4Y],
	gWheelChangePos[pos4Z]);
	file = fopen("locations/wheelchangeposition.cfg", io_write);
	fwrite(file, coordstring);
	fclose(file);
	return 1;
}

// LoadWantedList()
// {
	// new string[128];
	// format(string, sizeof(string), "SELECT * FROM samp_wanted LIMIT 1000");
	// mysql_query(string, LOAD_WANTED_LIST, INVALID_PLAYER_ID, db_con1);
	// return 1;
// }

LoadSpawnInfo()
{
	new arrCoords[6][64];
	new strFromFile2[256];
	new File: file = fopen("other/startplayerdata.cfg", io_read);
	if (file)
	{
		fread(file, strFromFile2);
		split2(strFromFile2, arrCoords, '|');
		gStartSpawnX = floatstr(arrCoords[0]);
		gStartSpawnY = floatstr(arrCoords[1]);
		gStartSpawnZ = floatstr(arrCoords[2]);
		gStartMoney = strval(arrCoords[3]);
		gStartBank = strval(arrCoords[4]);
		gStartSkin = strval(arrCoords[5]);
        print("[INFO:] Mechanic job loaded");
	}
	fclose(file);	
	printf("[SKRYPT:] Zaladowane dane startowe graczy");
	return 1;
}

SaveSpawnInfo()
{
	new File: file2;
	new coordsstring[512];
	format(coordsstring, sizeof(coordsstring), "%f|%f|%f|%d|%d|%d\n",
	gStartSpawnX,
	gStartSpawnY,
	gStartSpawnZ,
	gStartMoney,
	gStartBank,
	gStartSkin);

	file2 = fopen("other/startplayerdata.cfg", io_write);
	fwrite(file2, coordsstring);
	fclose(file2);
	return 1;
}

LoadBusTracks()
{
	new string[128];
	
	format( string, sizeof(string), "SELECT * FROM `samp_bus_tracks`" );
	mysql_query( string, LOAD_BUS_TRACKS, INVALID_PLAYER_ID, db_con2 );
	
	format( string, sizeof(string), "SELECT * FROM `samp_bus_tracks_data`" );
	mysql_query( string, LOAD_BUS_TRACKS_DATA, INVALID_PLAYER_ID, db_con2 );
	
	return 1;
}

LoadLuckyLottery()
{
	new string[128];
	
	format( string, sizeof(string), "SELECT * FROM `samp_lucky_lottery`" );
	mysql_query( string, LOAD_LUCKY_LOTTERY, INVALID_PLAYER_ID, db_con2 );
	
	new arrCoords[8][32];
	new strFromFile[256];
	new File:file = fopen("other/luckylottery.cfg", io_read);
	if( file )
	{
		fread(file, strFromFile);
		split2(strFromFile, arrCoords, '|');
		gLuckyLotteryID = strval(arrCoords[0]);
		gLuckyLotteryCash = strval(arrCoords[1]);
		gLuckyLotteryLastLottery = strval(arrCoords[2]);
		gLuckyLotteryWinnersCount = strval(arrCoords[3]);
		gLuckyLotteryNumbers[0] = strval(arrCoords[4]);
		gLuckyLotteryNumbers[1] = strval(arrCoords[5]);
		gLuckyLotteryNumbers[2] = strval(arrCoords[6]);
		gLuckyLotteryNumbers[3] = strval(arrCoords[7]);
	}
	fclose(file);
	printf("[SKRYPT:] Loaded Lucky Lottery Data 2");	
	return 1;
}

LoadCustomObjects()
{
	new string[128];
	
	format(string, sizeof(string), "SELECT * FROM `samp_objects`");
	mysql_query(string, LOAD_CUSTOM_OBJECTS, INVALID_PLAYER_ID, db_con2);
	
	return 1;
}

LoadItemFactories()
{
	new string[128];
	
	format(string, sizeof(string), "SELECT * FROM `samp_item_factories`");
	mysql_query(string, LOAD_ITEM_FACTORIES, INVALID_PLAYER_ID, db_con2);
	
	return 1;
}