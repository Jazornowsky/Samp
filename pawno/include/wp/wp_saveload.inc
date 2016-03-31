/***
*
* File: wp_saveload.inc
* Auth: Damian Wojdat
* Date: 15.09.2011
* Desc: Loading data functions.
*
*************************************************************************************************************/

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
	wp_mysql_query(string, LOAD_DYNAMIC_CARS, INVALID_PLAYER_ID, db_con2);

	format(string, sizeof(string), "SELECT * FROM `samp_carsdata`");
	wp_mysql_query(string, LOAD_CARSDATA, INVALID_PLAYER_ID, db_con2);
	
	format(string, sizeof(string), "SELECT * FROM `samp_cars_cparts`");
	wp_mysql_query(string, LOAD_CARS_CPARTS, INVALID_PLAYER_ID, db_con2);
	
	format(string, sizeof(string), "SELECT * FROM `samp_vehicles_customize` ORDER BY `ID` ASC");
	wp_mysql_query(string, LOAD_CARS_CUSTOMIZE, INVALID_PLAYER_ID, db_con2);

	return 1;
}

LoadDynamicZones()
{
	new string[128];
	
	format(string, sizeof(string), "SELECT * FROM samp_gang_zones ORDER BY `ID` ASC");
	wp_mysql_query(string, LOAD_GANG_ZONES, INVALID_PLAYER_ID, db_con2);
	
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
		fclose(file);
	}
	else
		ErrorLog("[ERROR:] Can't load taxes.cfg");
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
	if(file2)
	{
		fwrite(file2, coordstring);
		fclose(file2);
	}
	else
		ErrorLog("[ERROR:] Can't save taxes.cfg");
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
	else
		ErrorLog("[ERROR:] Can't load carsspawnplaces.cfg");
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
		if(file2)
		{
			fwrite(file2, coordstring);
			fclose(file2);
		}
		else
			ErrorLog("[ERROR:] Can't save carsspawnplaces.cfg");
		idx++;
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
	else
		ErrorLog("[ERROR:] Can't load planespawnplaces.cfg");
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
		if(file2)
		{
			fwrite(file2, coordstring);
			fclose(file2);
		}
		else
			ErrorLog("[ERROR:] Can't load planesspawnplaces.cfg");		
		idx++;
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
	else
		ErrorLog("[ERROR:] Can't load boatsspawnplaces.cfg");
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
		if(file2)
		{
			fwrite(file2, coordstring);
			fclose(file2);
		}
		else
			ErrorLog("[ERROR:] Can't save boatsspawnplaces");
		idx++;
	}
	return 1;
}

LoadRafinery()
{
	new string[64];

	format(string, sizeof(string), "SELECT * FROM `samp_rafinery`");
	wp_mysql_query(string, LOAD_RAFINERY, INVALID_PLAYER_ID, db_con2);

	return 1;
}

SaveRafinery()
{
	new string[256];

	format(string, sizeof(string), "UPDATE `samp_rafinery` SET `ResourcePetrol` = '%d' , `PetrolLtrCost` = '%d' , `EmployerReward` = '%d' , `MaxResources` = '%d' ", gRafinery[RafResourcePetrol], gRafinery[RafPetrolLtrCost], gRafinery[RafRefuelReward], gRafinery[RafMaxResources]);
	wp_mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
	format(string, sizeof(string), "UPDATE `samp_rafinery` SET `ResourceOil` = '%d' , `ResourceGas` = '%d' , `OilLtrCost` = '%d' , `GasLtrCost` = '%d' , `FlyLtrCost` = '%d' ", gRafinery[RafResourceOil], gRafinery[RafResourceGas], gRafinery[RafOilLtrCost], gRafinery[RafGasLtrCost], gRafinery[RafFlyLtrCost]);
	wp_mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
	format(string, sizeof(string), "UPDATE `samp_rafinery` SET `ResourceFly` = '%d'", gRafinery[RafResourceFly]);
	wp_mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);

	return 1;
}

LoadWFactoryLegal() // fabryka broni
{
	new string[64];
	
	format(string, sizeof(string), "SELECT * FROM `samp_wfactorylegal`");
	wp_mysql_query(string, LOAD_WFACTORYLEGAL, INVALID_PLAYER_ID, db_con2);
	
	return 1;
}

LoadGasStations()
{
	new string[128];

	format(string, sizeof(string), "SELECT * FROM `samp_gas_stations`");
	wp_mysql_query(string, LOAD_GAS_STATIONS, INVALID_PLAYER_ID, db_con2);

	return 1;
}

SaveGasStations()
{
	new string[256];

	for(new i = 0; i < sizeof(GasStations); i++)
	{
		format(string, sizeof(string), "UPDATE `samp_gas_stations` SET `BusinessID` = '%d' , `PetrolResourceValue` = '%f' WHERE `ID` = '%d' ", GasStations[i][BusinessID], GasStations[i][PetrolResourceValue], i);
		wp_mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);

		format(string, sizeof(string), "UPDATE `samp_gas_stations` SET `MaxPetrolResourceValue` = '%f' , `RefuelPetrolResources` = '%d' WHERE `ID` = '%d' ", GasStations[i][MaxPetrolResourceValue], GasStations[i][RefuelPetrolResources], i);
		wp_mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);

		format(string, sizeof(string), "UPDATE `samp_gas_stations` SET `PetrolPrice` = '%d' , `posX` = '%f' WHERE `ID` = '%d' ", GasStations[i][PetrolPrice], GasStations[i][GSposX], i);
		wp_mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);

		format(string, sizeof(string), "UPDATE `samp_gas_stations` SET `posY` = '%f' , `posZ` = '%f' WHERE `ID` = '%d' ", GasStations[i][GSposY], GasStations[i][GSposZ], i);
		wp_mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
		
		format(string, sizeof(string), "UPDATE `samp_gas_stations` SET `OilResourceValue` = '%f' , `GasResourceValue` = '%f' WHERE `ID` = '%d' ", GasStations[i][OilResourceValue], GasStations[i][GasResourceValue], i);
		wp_mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
		
		format(string, sizeof(string), "UPDATE `samp_gas_stations` SET `MaxOilResourceValue` = '%f' , `MaxGasResourceValue` = '%f' WHERE `ID` = '%d' ", GasStations[i][MaxOilResourceValue], GasStations[i][MaxGasResourceValue], i);
		wp_mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
		
		format(string, sizeof(string), "UPDATE `samp_gas_stations` SET `OilPrice` = '%d' , `GasPrice` = '%d' WHERE `ID` = '%d' ", GasStations[i][OilPrice], GasStations[i][GasPrice], i);
		wp_mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
	}
	return 1;
}

LoadPayRank()
{
	new string[128];

	format(string, sizeof(string), " SELECT * FROM `samp_factions_payrank` ");
	wp_mysql_query(string, LOAD_FACTIONS_PAYRANK, INVALID_PLAYER_ID, db_con2);

	return 1;
}

SavePayRank()
{
	new string[128];

	for(new i = 0; i < sizeof(DynamicFactions); i++)
	{
		format(string, sizeof(string), "UPDATE `samp_factions_payrank` SET `FactionID` = '%d' , `Rank1` = '%d' WHERE `FactionID` = '%d' ", PayRank[i][FactionID], PayRank[i][Rank1], i);
		wp_mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);

		format(string, sizeof(string), "UPDATE `samp_factions_payrank` SET `Rank2` = '%d' , `Rank3` = '%d' WHERE `FactionID` = '%d' ", PayRank[i][Rank2], PayRank[i][Rank3], i);
		wp_mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);

		format(string, sizeof(string), "UPDATE `samp_factions_payrank` SET `Rank4` = '%d' , `Rank5` = '%d' WHERE `FactionID` = '%d' ", PayRank[i][Rank4], PayRank[i][Rank5], i);
		wp_mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);

		format(string, sizeof(string), "UPDATE `samp_factions_payrank` SET `Rank6` = '%d' , `Rank7` = '%d' WHERE `FactionID` = '%d' ", PayRank[i][Rank6], PayRank[i][Rank7], i);
		wp_mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);

		format(string, sizeof(string), "UPDATE `samp_factions_payrank` SET `Rank8` = '%d' , `Rank9` = '%d' WHERE `FactionID` = '%d' ", PayRank[i][Rank8], PayRank[i][Rank9], i);
		wp_mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);

		format(string, sizeof(string), "UPDATE `samp_factions_payrank` SET `Rank10` = '%d' WHERE `FactionID` = '%d' ", PayRank[i][Rank10], i);
		wp_mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
	}
	return 1;
}

LoadVariables()
{
	new string[128];

	format(string, sizeof(string), "SELECT * FROM `samp_variables`");
	wp_mysql_query(string, LOAD_VARIABLES, INVALID_PLAYER_ID, db_con2);

	return 1;
}

// SaveVariables()
// {
	// new string[128];

	// for(new i = 0; i < sizeof(DBVariables); i++)
	// {
		// format(string, sizeof(string), "UPDATE `samp_variables` SET `varName` = '%s', `varType` = '%s' WHERE `ID` = '%d'", DBVariables[i][varName], DBVariables[i][varType], i+1);
		// wp_mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);

		// format(string, sizeof(string), "UPDATE `samp_variables` SET `varDValue` = '%d', `varFValue` = '%f' WHERE `ID` = '%d'", DBVariables[i][varDValue], DBVariables[i][varFValue], i+1);
		// wp_mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);

		// format(string, sizeof(string), "UPDATE `samp_variables` SET `varSValue` = '%s' WHERE `ID` = '%d'", DBVariables[i][varSValue], i+1);
		// wp_mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
	// }
	// return 1;
// }

LoadDynamicFactions()
{	
	new string[128];
	
	format(string, sizeof(string), "SELECT * FROM samp_factions ORDER BY `ID` ASC");
	wp_mysql_query(string, LOAD_DYNAMIC_FACTIONS, INVALID_PLAYER_ID, db_con2);
	
	format(string, sizeof(string), "SELECT * FROM samp_factions_weapons ORDER BY `FactionID` ASC");
	wp_mysql_query(string, LOAD_DYNAMIC_FACTIONS_WEAPONS, INVALID_PLAYER_ID, db_con2);
	
	format(string, sizeof(string), "SELECT * FROM samp_factions_weapons2 ORDER BY `FactionID` ASC");
	wp_mysql_query(string, LOAD_DYNAMIC_FACTIONS_WEAPONS2, INVALID_PLAYER_ID, db_con2);

	return 1;
}

SaveDynamicFactions()
{	
	new string[256];

	for(new i = 0; i < sizeof(DynamicFactions); i++)
	{
		format(string, sizeof(string), "UPDATE `samp_factions` SET `Name` = '%s' , `X` = '%f' , `Y` = '%f' , `Z` = '%f' WHERE `ID` = '%d'", DynamicFactions[i][Name], DynamicFactions[i][m_fX], DynamicFactions[i][m_fY], DynamicFactions[i][m_fZ], i+1);
		wp_mysql_query(string, SAVE2, INVALID_PLAYER_ID, db_con3);

		format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank1` = '%s' , `Rank2` = '%s' , `Rank3` = '%s' WHERE `ID` = '%d'", DynamicFactions[i][fRank1], DynamicFactions[i][fRank2], DynamicFactions[i][fRank3], i+1);
		wp_mysql_query(string, SAVE2, INVALID_PLAYER_ID, db_con3);

		format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank4` = '%s' , `Rank5` = '%s' , `Rank6` = '%s' WHERE `ID` = '%d'", DynamicFactions[i][fRank4], DynamicFactions[i][fRank5], DynamicFactions[i][fRank6], i+1);
		wp_mysql_query(string, SAVE2, INVALID_PLAYER_ID, db_con3);

		format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank7` = '%s' , `Rank8` = '%s' , `Rank9` = '%s' WHERE `ID` = '%d'", DynamicFactions[i][fRank7], DynamicFactions[i][fRank8], DynamicFactions[i][fRank10], i+1);
		wp_mysql_query(string, SAVE2, INVALID_PLAYER_ID, db_con3);

		format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank10` = '%s' , `Skin1` = '%d' , `Skin2` = '%d' , `Skin3` = '%d' WHERE `ID` = '%d'", DynamicFactions[i][fRank10], DynamicFactions[i][fSkin1], DynamicFactions[i][fSkin2], DynamicFactions[i][fSkin3], i+1);
		wp_mysql_query(string, SAVE2, INVALID_PLAYER_ID, db_con3);

		format(string, sizeof(string), "UPDATE `samp_factions` SET `Skin4` = '%d' , `Skin5` = '%d' , `Skin6` = '%d' , `Skin7` = '%d' WHERE `ID` = '%d'", DynamicFactions[i][fSkin4], DynamicFactions[i][fSkin5], DynamicFactions[i][fSkin6], DynamicFactions[i][fSkin7], i+1);
		wp_mysql_query(string, SAVE2, INVALID_PLAYER_ID, db_con3);

		format(string, sizeof(string), "UPDATE `samp_factions` SET `Skin8` = '%d' , `Skin9` = '%d' , `Skin10` = '%d' , `JoinRank` = '%d' WHERE `ID` = '%d'", DynamicFactions[i][fSkin8], DynamicFactions[i][fSkin9], DynamicFactions[i][fSkin10], DynamicFactions[i][fJoinRank], i+1);
		wp_mysql_query(string, SAVE2, INVALID_PLAYER_ID, db_con3);

		format(string, sizeof(string), "UPDATE `samp_factions` SET `UseSkins` = '%d' , `Type` = '%d' , `RankAmount` = '%d' , `Color` = '%d' WHERE `ID` = '%d'", DynamicFactions[i][fUseSkins], DynamicFactions[i][fType], DynamicFactions[i][fRankAmount], DynamicFactions[i][fColor], i+1);
		wp_mysql_query(string, SAVE2, INVALID_PLAYER_ID, db_con3);

		format(string, sizeof(string), "UPDATE `samp_factions` SET `MaxCars` = '%d' , `CarsCount` = '%d' , `XDuty` = '%f' , `YDuty` = '%f' WHERE `ID` = '%d'", DynamicFactions[i][fMaxCars], DynamicFactions[i][fCarsCount], DynamicFactions[i][fXDuty], DynamicFactions[i][fYDuty], i+1);
		wp_mysql_query(string, SAVE2, INVALID_PLAYER_ID, db_con3);

		format(string, sizeof(string), "UPDATE `samp_factions` SET `ZDuty` = '%f' , `WorldDuty` = '%d' WHERE `ID` = '%d'", DynamicFactions[i][fZDuty], DynamicFactions[i][fWorldDuty], i+1);
		wp_mysql_query(string, SAVE2, INVALID_PLAYER_ID, db_con3);
	}
	return 1;
}

LoadBuildings()
{
	new string[128];

	format(string, sizeof(string), "SELECT * FROM samp_buildings LIMIT %d", MAX_BUILDINGS);
	wp_mysql_query(string, LOAD_BUILDINGS, INVALID_PLAYER_ID, db_con2);
	return 1;
}

LoadHouses(hsource)
{
	if(hsource)
	{
		new string[128];

		format(string, sizeof(string), "SELECT * FROM samp_houses ORDER BY `ID` ASC LIMIT 1500");
		wp_mysql_query(string, LOAD_HOUSES, INVALID_PLAYER_ID, db_con2);
		
		format(string, sizeof(string), "SELECT * FROM samp_houses_items ORDER BY `ID` ASC LIMIT 1500");
		wp_mysql_query(string, LOAD_HOUSES_ITEMS, INVALID_PLAYER_ID, db_con2);
		
		format(string, sizeof(string), "SELECT * FROM samp_houses_data ORDER BY `ID` ASC");
		wp_mysql_query(string, LOAD_HOUSES_DATA, INVALID_PLAYER_ID, db_con2);
	}
	return 1;
}

LoadBusinesses()
{
	new string[128];

	format(string, sizeof(string), "SELECT * FROM samp_businesses ORDER BY `ID` LIMIT 1000");
	wp_mysql_query(string, LOAD_BUSINESSES, INVALID_PLAYER_ID, db_con2);
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
		fclose(file);
	}
	else
		ErrorLog("[ERROR:] Can't load civilianspawn.cfg");
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
	if(file2)
	{
		fwrite(file2, coordsstring);
		fclose(file2);
	}
	else
		ErrorLog("[ERROR:] Can't save civilianspawn.cfg");
	return 1;
}

LoadPoliceComputerPassword()
{
	new strFromFile2[64];
	new File: file = fopen("policecomputerpassword.cfg", io_read);
	if (file)
	{
		fread(file, strFromFile2);
		strmid(gPoliceComputerPassword, strFromFile2, 0, 64, 255);
		fclose(file);
		
		#if defined DEBUG
			print("[INFO:] Police computer password loaded");
		#endif
	}
	else
		ErrorLog("[ERROR:] Can't load policecomputerpassword.cfg");
	return 1;
}

SavePoliceComputerPassword()
{
	new File: file2;
	new coordsstring[64];
	format(coordsstring, sizeof(coordsstring), "%s",
		gPoliceComputerPassword
	);
	file2 = fopen("policecomputerpassword.cfg", io_write);
	if(file2)
	{
		fwrite(file2, coordsstring);
		fclose(file2);
	}
	else
		ErrorLog("[ERROR:] Can't save policecomputerpassword.cfg");
	return 1;
}

LoadDrivingTestAreaBuy()
{
	new arrCoords[7][64];
	new strFromFile[256];
	new File:file = fopen("locations/drivingtestareabuylocation.cfg", io_read);
	if(file)
	{
		fread(file, strFromFile);
		split2(strFromFile, arrCoords, '|');
		gDrivingTestAreaBuy[mPosX] = floatstr(arrCoords[0]);
		gDrivingTestAreaBuy[mPosY] = floatstr(arrCoords[1]);
		gDrivingTestAreaBuy[mPosZ] = floatstr(arrCoords[2]);		
		gDrivingTestAreaBuy[mPosWorld] = strval(arrCoords[3]);
		gDrivingTestAreaBuy[mPosInterior] = strval(arrCoords[4]);
		gDrivingTestAreaBuy[mPrice] = strval(arrCoords[5]);
		gDrivingTestAreaBuy[mTime] = strval(arrCoords[6]);
		gDrivingTestAreaBuy[pickupID] = CreateDynamicPickup(1239, 1, gDrivingTestAreaBuy[mPosX], gDrivingTestAreaBuy[mPosY], gDrivingTestAreaBuy[mPosZ], gDrivingTestAreaBuy[mPosWorld], gDrivingTestAreaBuy[mPosInterior]);
		fclose(file);
		#if defined DEBUG
			print("[INFO:] Driving test buy pos loaded");
		#endif
	}
	else
		ErrorLog("[ERROR:] Can't load drivingtestareabuylocation.cfg");
	return 1;
}

SaveDrivingTestAreaBuy()
{
	new File:file;
	new coordsstring[512];
	format(coordsstring, sizeof(coordsstring), "%f|%f|%f|%d|%d|%d|%d",
	gDrivingTestAreaBuy[mPosX],
	gDrivingTestAreaBuy[mPosY],
	gDrivingTestAreaBuy[mPosZ],
	gDrivingTestAreaBuy[mPosWorld],
	gDrivingTestAreaBuy[mPosInterior],
	gDrivingTestAreaBuy[mPrice],
	gDrivingTestAreaBuy[mTime]);
	file = fopen("locations/drivingtestareabuylocation.cfg", io_write);
	if(file)
	{
		fwrite(file, coordsstring);
		fclose(file);
	}
	else
		ErrorLog("[ERROR:] Can't save drivingtestareabuylocation.cfg");
	return 1;
}

LoadDrivingTestArea()
{
	new arrCoords[12][64];
	new strFromFile[256];
	new File:file = fopen("locations/drivingtestarealocation.cfg", io_read);
	if(file)
	{
		fread(file, strFromFile);
		split2(strFromFile, arrCoords, '|');
		gDrivingTestArea[posEntranceX] = floatstr(arrCoords[0]);
		gDrivingTestArea[posEntranceY] = floatstr(arrCoords[1]);
		gDrivingTestArea[posEntranceZ] = floatstr(arrCoords[2]);
		gDrivingTestArea[posEntranceWorld] = strval(arrCoords[3]);
		gDrivingTestArea[posEntranceInterior] = strval(arrCoords[4]);
		gDrivingTestArea[posEntranceAngle]  = floatstr(arrCoords[5]);
		gDrivingTestArea[posExitX] = floatstr(arrCoords[6]);
		gDrivingTestArea[posExitY] = floatstr(arrCoords[7]);
		gDrivingTestArea[posExitZ] = floatstr(arrCoords[8]);
		gDrivingTestArea[posExitWorld] = strval(arrCoords[9]);
		gDrivingTestArea[posExitInterior] = strval(arrCoords[10]);
		gDrivingTestArea[posExitAngle]  = floatstr(arrCoords[11]);		
		gDrivingTestArea[pickupID1] = CreateDynamicPickup(1239, 1, gDrivingTestArea[posEntranceX], gDrivingTestArea[posEntranceY], gDrivingTestArea[posEntranceZ], gDrivingTestArea[posEntranceWorld], gDrivingTestArea[posEntranceInterior]);
		gDrivingTestArea[pickupID2] = CreateDynamicPickup(1239, 1, gDrivingTestArea[posExitX], gDrivingTestArea[posExitY], gDrivingTestArea[posExitZ], gDrivingTestArea[posExitWorld], gDrivingTestArea[posExitInterior]);
		fclose(file);
		#if defined DEBUG
			printf("[INFO:] Driving test area loaded");
		#endif
	}
	else
		ErrorLog("[ERROR:] Can't load drivingtestarealocation.cfg");
	return 1;
}

SaveDrivingTestArea()
{
	new File:file;
	new coordsstring[512];
	format(coordsstring, sizeof(coordsstring), "%f|%f|%f|%d|%d|%f|%f|%f|%f|%d|%d|%f",
	gDrivingTestArea[posEntranceX],
	gDrivingTestArea[posEntranceY],
	gDrivingTestArea[posEntranceZ],
	gDrivingTestArea[posEntranceWorld],
	gDrivingTestArea[posEntranceInterior],
	gDrivingTestArea[posEntranceAngle],
	gDrivingTestArea[posExitX],
	gDrivingTestArea[posExitY],
	gDrivingTestArea[posExitZ],
	gDrivingTestArea[posExitWorld],
	gDrivingTestArea[posExitInterior],
	gDrivingTestArea[posExitAngle]);
	file = fopen("locations/drivingtestarealocation.cfg", io_write);
	if(file)
	{
		fwrite(file, coordsstring);
		fclose(file);
	}
	else
		ErrorLog("[ERROR:] Can't save drivingtestarealocation.cfg");
	return 1;
}

LoadDrivingTestPosition()
{
	new arrCoords[21][64];
	new strFromFile2[256];
	new File: file = fopen("locations/drivingtestlocation.cfg", io_read);
	if (file)
	{
		fread(file, strFromFile2);
		split2(strFromFile2, arrCoords, '|');
		gDrivingTestPosition[mPosXA] = floatstr(arrCoords[0]);
		gDrivingTestPosition[mPosYA] = floatstr(arrCoords[1]);
		gDrivingTestPosition[mPosZA] = floatstr(arrCoords[2]);
		gDrivingTestPosition[mPosWorldA] = strval(arrCoords[3]);
		gDrivingTestPosition[mPosInteriorA] = strval(arrCoords[4]);
		gDrivingTestPosition[mPosXB] = floatstr(arrCoords[5]);
		gDrivingTestPosition[mPosYB] = floatstr(arrCoords[6]);
		gDrivingTestPosition[mPosZB] = floatstr(arrCoords[7]);
		gDrivingTestPosition[mPosWorldB] = strval(arrCoords[8]);
		gDrivingTestPosition[mPosInteriorB] = strval(arrCoords[9]);
		gDrivingTestPosition[mPosXCE] = floatstr(arrCoords[10]);
		gDrivingTestPosition[mPosYCE] = floatstr(arrCoords[11]);
		gDrivingTestPosition[mPosZCE] = floatstr(arrCoords[12]);
		gDrivingTestPosition[mPosWorldCE] = strval(arrCoords[13]);
		gDrivingTestPosition[mPosInteriorCE] = strval(arrCoords[14]);
		gDrivingTestPosition[mPriceA] = strval(arrCoords[15]);
		gDrivingTestPosition[mPriceB] = strval(arrCoords[16]);
		gDrivingTestPosition[mPriceCE] = strval(arrCoords[17]);
		gDrivingTestPosition[mPriceLowA] = strval(arrCoords[18]);
		gDrivingTestPosition[mPriceLowB] = strval(arrCoords[19]);
		gDrivingTestPosition[mPriceLowCE] = strval(arrCoords[20]);
        gDrivingTestPosition[PickupIDA] = CreateDynamicPickup(1239, 1, gDrivingTestPosition[mPosXA], gDrivingTestPosition[mPosYA], gDrivingTestPosition[mPosZA], gDrivingTestPosition[mPosWorldA], gDrivingTestPosition[mPosInteriorA]);
        gDrivingTestPosition[PickupIDB] = CreateDynamicPickup(1239, 1, gDrivingTestPosition[mPosXB], gDrivingTestPosition[mPosYB], gDrivingTestPosition[mPosZB], gDrivingTestPosition[mPosWorldB], gDrivingTestPosition[mPosInteriorB]);
        gDrivingTestPosition[PickupIDCE] = CreateDynamicPickup(1239, 1, gDrivingTestPosition[mPosXCE], gDrivingTestPosition[mPosYCE], gDrivingTestPosition[mPosZCE], gDrivingTestPosition[mPosWorldCE], gDrivingTestPosition[mPosInteriorCE]);
		fclose(file);
        #if defined DEBUG
			print("[INFO:] Driving test location loaded");
		#endif
	}
	else
		ErrorLog("[ERROR:] Can't load drivingtestlocation.cfg");
	return 1;
}

SaveDrivingTestPosition()
{
	new File: file2;
	new coordsstring[512];
	format(coordsstring, sizeof(coordsstring), "%f|%f|%f|%d|%d|%f|%f|%f|%d|%d|%f|%f|%f|%d|%d|%d|%d|%d|%d|%d|%d\n",
	gDrivingTestPosition[mPosXA],
	gDrivingTestPosition[mPosYA],
	gDrivingTestPosition[mPosZA],
	gDrivingTestPosition[mPosWorldA],
	gDrivingTestPosition[mPosInteriorA],
	gDrivingTestPosition[mPosXB],
	gDrivingTestPosition[mPosYB],
	gDrivingTestPosition[mPosZB],
	gDrivingTestPosition[mPosWorldB],
	gDrivingTestPosition[mPosInteriorB],
	gDrivingTestPosition[mPosXCE],
	gDrivingTestPosition[mPosYCE],
	gDrivingTestPosition[mPosZCE],
	gDrivingTestPosition[mPosWorldCE],
	gDrivingTestPosition[mPosInteriorCE],
	gDrivingTestPosition[mPriceA],
	gDrivingTestPosition[mPriceB],
	gDrivingTestPosition[mPriceCE],
	gDrivingTestPosition[mPriceLowA],
	gDrivingTestPosition[mPriceLowB],
	gDrivingTestPosition[mPriceLowCE]);
	file2 = fopen("locations/drivingtestlocation.cfg", io_write);
	if(file2)
	{
		fwrite(file2, coordsstring);
		fclose(file2);
	}
	else
		ErrorLog("[ERROR:] Can't save drivingtestlocation.cfg");
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
		fclose(file);
		#if defined DEBUG
			print("[INFO:] Skill location loaded");
		#endif
	}
	else
		ErrorLog("[ERROR:] Can't load skilllocation.cfg");
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
	if(file2)
	{
		fwrite(file2, coordsstring);
		fclose(file2);
	}
	else
		ErrorLog("[ERROR:] Can't save skilllocation.cfg");
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
		fclose(file);
		#if defined DEBUG
			print("[INFO:] Skill 2 location loaded");
		#endif
	}
	else
		ErrorLog("[ERROR:] Can't load skillpositionb.cfg");
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
	if(file2)
	{
		fwrite(file2, coordsstring);
		fclose(file2);
	}
	else
		ErrorLog("[ERROR:] Can't save skilllocationb.cfg");
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
		fclose(file);
		#if defined DEBUG
			print("[INFO:] Skill 3 location loaded");
		#endif
	}
	else
		ErrorLog("[ERROR:] Can't load skilllocationc.cfg");
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
	if(file2)
	{
		fwrite(file2, coordsstring);
		fclose(file2);
	}
	else
		ErrorLog("[ERROR:] Can't save skillpositionc.cfg");
	return 1;
}

LoadSkillPositiond()
{
	new arrCoords[16][64];
	new strFromFile2[256];
	new File: file = fopen("locations/skilllocationd.cfg", io_read);
	if (file)
	{
		fread(file, strFromFile2);
		split2(strFromFile2, arrCoords, '|');
		SkillPosition[XTech] = floatstr(arrCoords[0]);
		SkillPosition[YTech] = floatstr(arrCoords[1]);
		SkillPosition[ZTech] = floatstr(arrCoords[2]);
		SkillPosition[XLaw] = floatstr(arrCoords[3]);
		SkillPosition[YLaw] = floatstr(arrCoords[4]);
		SkillPosition[ZLaw] = floatstr(arrCoords[5]);
		SkillPosition[XMat] = floatstr(arrCoords[6]);
		SkillPosition[YMat] = floatstr(arrCoords[7]);
		SkillPosition[ZMat] = floatstr(arrCoords[8]);
		SkillPosition[XPol] = floatstr(arrCoords[9]);
		SkillPosition[YPol] = floatstr(arrCoords[10]);
		SkillPosition[ZPol] = floatstr(arrCoords[11]);
		SkillPosition[PickupIDTech] = strval(arrCoords[12]);
		SkillPosition[PickupIDLaw] = strval(arrCoords[13]);
		SkillPosition[PickupIDMat] = strval(arrCoords[14]);
		SkillPosition[PickupIDPol] = strval(arrCoords[15]);
		//Creating Pickup
		SkillPosition[PickupIDTech] = CreateDynamicPickup(1239,1,SkillPosition[XTech],SkillPosition[YTech],SkillPosition[ZTech]);
		SkillPosition[PickupIDLaw] = CreateDynamicPickup(1239,1,SkillPosition[XLaw],SkillPosition[YLaw],SkillPosition[ZLaw]);
		SkillPosition[PickupIDMat] = CreateDynamicPickup(1239,1,SkillPosition[XMat],SkillPosition[YMat],SkillPosition[ZMat]);
		SkillPosition[PickupIDPol] = CreateDynamicPickup(1239,1,SkillPosition[XPol],SkillPosition[YPol],SkillPosition[ZPol]);
		fclose(file);
		#if defined DEBUG
			print("[INFO:] Skill 4 location loaded");
		#endif
	}
	else
		ErrorLog("[ERROR:] Can't load skillpositiond.cfg");
	return 1;
}

SaveSkillPositiond()
{
	new File: file2;
	new coordsstring[256];
	format(coordsstring, sizeof(coordsstring), "%f|%f|%f|%f|%f|%f|%f|%f|%f|%f|%f|%f|%d|%d|%d|%d\n",
	SkillPosition[XTech],
	SkillPosition[YTech],
	SkillPosition[ZTech],
	SkillPosition[XLaw],
	SkillPosition[YLaw],
	SkillPosition[ZLaw],
	SkillPosition[XMat],
	SkillPosition[YMat],
	SkillPosition[ZMat],
	SkillPosition[XPol],
	SkillPosition[YPol],
	SkillPosition[ZPol],
	SkillPosition[PickupIDTech],
	SkillPosition[PickupIDLaw],
	SkillPosition[PickupIDMat],
	SkillPosition[PickupIDPol]);
	file2 = fopen("locations/skilllocationd.cfg", io_write);
	if(file2)
	{
		fwrite(file2, coordsstring);
		fclose(file2);
	}
	else
		ErrorLog("[ERROR:] Can't save skillpositiond.cfg");
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
		//SkillPosition[PickupIDHis] = CreateDynamicPickup(1239, 1, SkillPosition[XHis], SkillPosition[YHis], SkillPosition[ZHis]);
		SkillPosition[PickupIDFiz] = CreateDynamicPickup(1239, 1, SkillPosition[XFiz], SkillPosition[YFiz], SkillPosition[ZFiz]);
		SkillPosition[PickupIDBio] = CreateDynamicPickup(1239, 1, SkillPosition[XBio], SkillPosition[YBio], SkillPosition[ZBio]);
		fclose(file);
		#if defined DEBUG
			print("[INFO:] Skill 5 location loaded");
		#endif
	}
	else
		ErrorLog("[ERROR:] Can't load skillpositione.cfg");
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
	if(file2)
	{
		fwrite(file2, coordsstring);
		fclose(file2);
	}
	else
		ErrorLog("[ERROR:] Can't save skillpositione.cfg");
	return 1;
}

LoadSkillPositionf()
{
	new arrCoords[3][64];
	new strFromFile2[128];
	new File: file = fopen("locations/skilllocationf.cfg", io_read);
	if (file)
	{
		fread(file, strFromFile2);
		split2(strFromFile2, arrCoords, '|');
		
		SkillPosition[XHighSchool] = floatstr(arrCoords[0]);
		SkillPosition[YHighSchool] = floatstr(arrCoords[1]);
		SkillPosition[ZHighSchool] = floatstr(arrCoords[2]);

		SkillPosition[PickupIDHighSchool] = CreateDynamicPickup(1239,1,SkillPosition[XHighSchool],SkillPosition[YHighSchool],SkillPosition[ZHighSchool]);
		fclose(file);
		#if defined DEBUG
			print("[INFO:] Skill 1 location loaded");
		#endif
	}
	else
		ErrorLog("[ERROR:] Can't load skillpositiond.cfg");
	return 1;
}

SaveSkillPositionf()
{
	new File: file2;
	new coordsstring[128];
	format(coordsstring, sizeof(coordsstring), "%f|%f|%f\n",
	SkillPosition[XHighSchool],
	SkillPosition[YHighSchool],
	SkillPosition[ZHighSchool]);
	file2 = fopen("locations/skilllocationf.cfg", io_write);
	if(file2)
	{
		fwrite(file2, coordsstring);
		fclose(file2);
	}
	else
		ErrorLog("[ERROR:] Can't save skillpositiond.cfg");
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
		fclose(file);
		#if defined DEBUG
			print("[INFO:] Boat test location loaded");
		#endif
	}
	else
		ErrorLog("[ERROR:] Can't load boattestlocation.cfg");
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
	if(file2)
	{
		fwrite(file2, coordsstring);
		fclose(file2);
	}
	else
		ErrorLog("[ERROR:] Can't save boattestlocation.cfg ");
	return 1;
}

LoadPlaneTestPosition()
{
	new arrCoords[7][64];
	new strFromFile2[256];
	new File: file = fopen("locations/flyingtestlocation.cfg", io_read);
	if (file)
	{
		fread(file, strFromFile2);
		split2(strFromFile2, arrCoords, '|');
		gPlaneTestPosition[mPosX] = floatstr(arrCoords[0]);
		gPlaneTestPosition[mPosY] = floatstr(arrCoords[1]);
		gPlaneTestPosition[mPosZ] = floatstr(arrCoords[2]);
		gPlaneTestPosition[mPosW] = strval(arrCoords[3]);
		gPlaneTestPosition[mPosInt] = strval(arrCoords[4]);
		gPlaneTestPosition[mPosA] = floatstr(arrCoords[5]);
		gPlaneTestPosition[PickupID] = strval(arrCoords[6]);
        gPlaneTestPosition[PickupID] = CreateDynamicPickup(1239,1,gPlaneTestPosition[mPosX],gPlaneTestPosition[mPosY],gPlaneTestPosition[mPosZ]);
		fclose(file);
		#if defined DEBUG
			print("[INFO:] Flying test location loaded");
		#endif
	}
	else
		ErrorLog("[ERROR:] Can't load flyingtestlocation.cfg");
	return 1;
}

SavePlaneTestPosition()
{
	new File: file2;
	new coordsstring[512];
	format(coordsstring, sizeof(coordsstring), "%f|%f|%f|%d|%d|%f|%d\n",
	gPlaneTestPosition[mPosX],
	gPlaneTestPosition[mPosY],
	gPlaneTestPosition[mPosZ],
	gPlaneTestPosition[mPosW],
	gPlaneTestPosition[mPosInt],
	gPlaneTestPosition[mPosA],
	gPlaneTestPosition[PickupID]);
	file2 = fopen("locations/flyingtestlocation.cfg", io_write);
	if(file2)
	{
		fwrite(file2, coordsstring);
		fclose(file2);
	}
	else
		ErrorLog("[ERROR:] Can't save flyingtestlocation.cfg ");
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
		fclose(file);
		#if defined DEBUG
			print("[INFO:] Weapon License location loaded");
		#endif
	}
	else
		ErrorLog("[ERROR:] Can't load weaponlicenselocation.cfg");
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
	if(file2)
	{
		fwrite(file2, coordsstring);
		fclose(file2);
	}
	else
		ErrorLog("[ERROR:] Can't save weaponlicenselocation.cfg ");
	return 1;
}

// LoadWantedList()
// {
	// new string[128];
	// format(string, sizeof(string), "SELECT * FROM samp_wanted LIMIT 1000");
	// wp_mysql_query(string, LOAD_WANTED_LIST, INVALID_PLAYER_ID, db_con1);
	// return 1;
// }

stock LoadSpawnInfo()
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
		fclose(file);
	}
	else
		ErrorLog("[ERROR:] Can't load startplayerdata.cfg ");
	#if defined DEBUG
		printf("[INFO:] Default player data loaded");
	#endif
	return 1;
}

stock SaveSpawnInfo()
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
	if(file2)
	{
		fwrite(file2, coordsstring);
		fclose(file2);
	}
	else
		ErrorLog("[ERROR:] Can't save startplayerdata.cfg ");
	return 1;
}

LoadBusTracks()
{
	new string[128];
	
	format( string, sizeof(string), "SELECT * FROM `samp_bus_tracks`" );
	wp_mysql_query( string, LOAD_BUS_TRACKS, INVALID_PLAYER_ID, db_con2 );
	
	format( string, sizeof(string), "SELECT * FROM `samp_bus_tracks_data`" );
	wp_mysql_query( string, LOAD_BUS_TRACKS_DATA, INVALID_PLAYER_ID, db_con2 );
	
	return 1;
}

LoadTrashTracks()
{
	new string[128];
	
	format( string, sizeof(string), "SELECT * FROM `samp_trash_tracks`" );
	wp_mysql_query( string, LOAD_TRASH_TRACKS, INVALID_PLAYER_ID, db_con2 );
	
	format( string, sizeof(string), "SELECT * FROM `samp_trash_tracks_data`" );
	wp_mysql_query( string, LOAD_TRASH_TRACKS_DATA, INVALID_PLAYER_ID, db_con2 );
	
	return 1;
}

LoadSweeperTracks()
{
	new string[128];
	
	format( string, sizeof(string), "SELECT * FROM `samp_sweeper_tracks`" );
	wp_mysql_query( string, LOAD_SWEEPER_TRACKS, INVALID_PLAYER_ID, db_con2 );
	
	format( string, sizeof(string), "SELECT * FROM `samp_sweeper_tracks_data`" );
	wp_mysql_query( string, LOAD_SWEEPER_TRACKS_DATA, INVALID_PLAYER_ID, db_con2 );
	
	return 1;
}

LoadFarmerTracks()
{
	new string[128];
	
	format( string, sizeof(string), "SELECT * FROM `samp_farmer_tracks`" );
	wp_mysql_query( string, LOAD_FARMER_TRACKS, INVALID_PLAYER_ID, db_con2 );
	
	format( string, sizeof(string), "SELECT * FROM `samp_farmer_tracks_data`" );
	wp_mysql_query( string, LOAD_FARMER_TRACKS_DATA, INVALID_PLAYER_ID, db_con2 );
	
	return 1;
}

LoadLuckyLottery()
{
	new string[128];
	
	format( string, sizeof(string), "SELECT * FROM `samp_lucky_lottery`" );
	wp_mysql_query( string, LOAD_LUCKY_LOTTERY, INVALID_PLAYER_ID, db_con2 );
	
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
		fclose(file);
	}
	else
		ErrorLog("[ERROR:] Can't load luckylottery.cfg");
	#if defined DEBUG
		printf("[INFO:] Loaded Lucky Lottery Data 2");	
	#endif
	return 1;
}

LoadCustomObjects()
{
	new string[128];
	
	format(string, sizeof(string), "SELECT * FROM `samp_objects` ORDER BY `ID` ASC");
	wp_mysql_query(string, LOAD_CUSTOM_OBJECTS, INVALID_PLAYER_ID, db_con2);
	
	return 1;
}

LoadItemFactories()
{
	new string[128];
	
	format(string, sizeof(string), "SELECT * FROM `samp_item_factories` ORDER BY `ID`");
	wp_mysql_query(string, LOAD_ITEM_FACTORIES, INVALID_PLAYER_ID, db_con2);
	
	return 1;
}

LoadAdmissionChambers()
{
	new arrCoords[5][64];
	new strFromFile[256];
	new File: file = fopen("locations/admissionchambers.cfg", io_read);
	if(file)
	{
		new i;
		while(i < sizeof(gAdmissionChambers))
		{
			fread(file, strFromFile);
			split2(strFromFile, arrCoords, '|');
			gAdmissionChambers[i][mPosX] = floatstr(arrCoords[0]);
			gAdmissionChambers[i][mPosY] = floatstr(arrCoords[1]);
			gAdmissionChambers[i][mPosZ] = floatstr(arrCoords[2]);
			gAdmissionChambers[i][mWorld] = strval(arrCoords[3]);
			gAdmissionChambers[i][mInt] = strval(arrCoords[4]);
			gAdmissionChambers[i][mPickupID] = CreateDynamicPickup(1239, 23, gAdmissionChambers[i][mPosX], gAdmissionChambers[i][mPosY], gAdmissionChambers[i][mPosZ], gAdmissionChambers[i][mWorld], gAdmissionChambers[i][mInt]);
			i++;
		}
		fclose(file);
	}
	else
		ErrorLog("[ERROR:] Can't load admissionchambers.cfg");
	#if defined DEBUG
		printf("[INFO:] Admission chambers loaded");
	#endif
	return 1;
}

SaveAdmissionChambers()
{
	new i;
	new File:file;
	new coordstring[512];
	while (i < sizeof(gAdmissionChambers))
	{		
		format(coordstring, sizeof(coordstring), "%f|%f|%f|%d|%d\n",
		gAdmissionChambers[i][mPosX],
		gAdmissionChambers[i][mPosY],
		gAdmissionChambers[i][mPosZ],
		gAdmissionChambers[i][mWorld],
		gAdmissionChambers[i][mInt]
		);

		if(i == 0)
			file = fopen("locations/admissionchambers.cfg", io_write);
		else
			file = fopen("locations/admissionchambers.cfg", io_append);
		if(file)
		{
			fwrite(file, coordstring);
			fclose(file);
		}
		else
			ErrorLog("[ERROR:] Can't save admissionchambers.cfg ");

		i++;
	}
	return 1;
}

LoadRaces()
{
	new string[128];
	
	format(string, sizeof(string), "SELECT * FROM `samp_races_tracks` ORDER BY `ID` ASC");
	wp_mysql_query(string, LOAD_RACES_TRACKS, INVALID_PLAYER_ID, db_con2 );
	
	format(string, sizeof(string), "SELECT * FROM `samp_races_tracks_data` ORDER BY `ID` ASC");
	wp_mysql_query(string, LOAD_RACES_TRACKS_DATA, INVALID_PLAYER_ID, db_con2 );
	
	return 1;
}

LoadWeed()
{
	new string[128];
	
	format(string, sizeof(string), "SELECT * FROM `samp_weed`");
	wp_mysql_query(string, LOAD_WEED, INVALID_PLAYER_ID, db_con2 );
	
	return 1;
}

LoadMapIcons()
{
	#if defined DEBUG
		printf("[DEBUG:] LoadMapIcons started");
	#endif
	
	new string[128];

	format(string, sizeof(string), "SELECT * FROM `samp_map_icons` LIMIT %d", MAX_MAP_ICONS);
	wp_mysql_query(string, LOAD_MAP_ICONS, INVALID_PLAYER_ID, db_con2);
	return 1;
}

LoadPublicAds()
{
	#if defined DEBUG
		printf("[DEBUG:] LoadPublicAds started");
	#endif

	new string[128];

	format(string, sizeof(string), "SELECT * FROM `samp_public_ads` LIMIT %d", MAX_MAP_ICONS);
	wp_mysql_query(string, LOAD_PUBLIC_ADS, INVALID_PLAYER_ID, db_con2);
	return 1;
}

stock LoadPickupInfos()
{
	#if defined DEBUG
		printf("[DEBUG:] LoadPickupInfos started");
	#endif

	new string[128];

	format(string, sizeof(string), "SELECT * FROM `samp_pickup_infos` LIMIT %d", MAX_PICKUP_INFOS);
	wp_mysql_query(string, LOAD_PICKUP_INFOS, INVALID_PLAYER_ID, db_con2);
	return 1;
}

stock LoadNews()
{
	new string[128];

	format(string, sizeof(string), "SELECT * FROM `samp_news` ORDER BY `ID` ASC");
	wp_mysql_query(string, LOAD_NEWS, INVALID_PLAYER_ID, db_con2);

	return 1;
}
