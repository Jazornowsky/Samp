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
	mysql_query(string, LOAD_DYNAMIC_CARS, INVALID_PLAYER_ID, db_con2);

	format(string, sizeof(string), "SELECT * FROM `samp_carsdata`");
	mysql_query(string, LOAD_CARSDATA, INVALID_PLAYER_ID, db_con2);
	
	format(string, sizeof(string), "SELECT * FROM `samp_cars_cparts`");
	mysql_query(string, LOAD_CARS_CPARTS, INVALID_PLAYER_ID, db_con2);
	
	format(string, sizeof(string), "SELECT * FROM `samp_vehicles_customize` ORDER BY `ID` ASC");
	mysql_query(string, LOAD_CARS_CUSTOMIZE, INVALID_PLAYER_ID, db_con2);

	return 1;
}

LoadDynamicZones()
{
	new string[128];
	
	format(string, sizeof(string), "SELECT * FROM samp_gang_zones ORDER BY `ID` ASC");
	mysql_query(string, LOAD_GANG_ZONES, INVALID_PLAYER_ID, db_con2);
	
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

// SaveVariables()
// {
	// new string[128];

	// for(new i = 0; i < sizeof(DBVariables); i++)
	// {
		// format(string, sizeof(string), "UPDATE `samp_variables` SET `varName` = '%s', `varType` = '%s' WHERE `ID` = '%d'", DBVariables[i][varName], DBVariables[i][varType], i+1);
		// mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);

		// format(string, sizeof(string), "UPDATE `samp_variables` SET `varDValue` = '%d', `varFValue` = '%f' WHERE `ID` = '%d'", DBVariables[i][varDValue], DBVariables[i][varFValue], i+1);
		// mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);

		// format(string, sizeof(string), "UPDATE `samp_variables` SET `varSValue` = '%s' WHERE `ID` = '%d'", DBVariables[i][varSValue], i+1);
		// mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
	// }
	// return 1;
// }

LoadDynamicFactions()
{
	new string[128];

	format(string, sizeof(string), "SELECT * FROM samp_factions ORDER BY `ID` ASC");
	mysql_query(string, LOAD_DYNAMIC_FACTIONS, INVALID_PLAYER_ID, db_con2);

	format(string, sizeof(string), "SELECT * FROM samp_factions_weapons ORDER BY `FactionID` ASC");
	mysql_query(string, LOAD_DYNAMIC_FACTIONS_WEAPONS, INVALID_PLAYER_ID, db_con2);

	format(string, sizeof(string), "SELECT * FROM samp_factions_weapons2 ORDER BY `FactionID` ASC");
	mysql_query(string, LOAD_DYNAMIC_FACTIONS_WEAPONS2, INVALID_PLAYER_ID, db_con2);

	return 1;
}

SaveDynamicFactions()
{	
	new string[256];

	for(new i = 0; i < sizeof(DynamicFactions); i++)
	{
		format(string, sizeof(string), "UPDATE `samp_factions` SET `Name` = '%s' , `X` = '%f' , `Y` = '%f' , `Z` = '%f' WHERE `ID` = '%d'", DynamicFactions[i][Name], DynamicFactions[i][m_fX], DynamicFactions[i][m_fY], DynamicFactions[i][m_fZ], i+1);
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

	format(string, sizeof(string), "SELECT * FROM samp_buildings LIMIT %d", MAX_BUILDINGS);
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
		
		format(string, sizeof(string), "UPDATE `samp_buildings` SET `ObjectID` = %d , `BuildingType` = %d , `ShowIcon` = %d , `IconType` = %d WHERE `ID` = '%d'", Building[i][ObjectID], Building[i][BuildingType], i+1 );
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
	}		
	return 1;
}

LoadHouses(hsource)
{
	if(hsource)
	{
		new string[128];

		format(string, sizeof(string), "SELECT * FROM samp_houses ORDER BY `ID` LIMIT 500");
		mysql_query(string, LOAD_HOUSES, INVALID_PLAYER_ID, db_con2);
		
		format(string, sizeof(string), "SELECT * FROM samp_houses_items ORDER BY `ID` LIMIT 500");
		mysql_query(string, LOAD_HOUSES_ITEMS, INVALID_PLAYER_ID, db_con2);
		
		format(string, sizeof(string), "SELECT * FROM samp_houses_data ORDER BY `id`");
		mysql_query(string, LOAD_HOUSES_DATA, INVALID_PLAYER_ID, db_con2);
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
		fclose(file);
		#if defined DEBUG
			print("[INFO:] Bank location loaded");
		#endif
	}
	else
		ErrorLog("[ERROR:] Can't load banklocation.cfg");
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
	if(file2)
	{
		fwrite(file2, coordsstring);
		fclose(file2);
	}
	else
		ErrorLog("[ERROR:] Can't save banklocation.cfg");
	return 1;
}

LoadBankPosition2()
{
	new arrCoords[30][64];
	new strFromFile2[256];
	new File: file = fopen("locations/banklocation2.cfg", io_read);
	if (file)
	{
		fread(file, strFromFile2);
		split2(strFromFile2, arrCoords, '|');
		BankPosition2[X] = floatstr(arrCoords[0]);
		BankPosition2[Y] = floatstr(arrCoords[1]);
		BankPosition2[Z] = floatstr(arrCoords[2]);
		BankPosition3[X] = floatstr(arrCoords[3]);
		BankPosition3[Y] = floatstr(arrCoords[4]);
		BankPosition3[Z] = floatstr(arrCoords[5]);
		BankPosition4[X] = floatstr(arrCoords[6]);
		BankPosition4[Y] = floatstr(arrCoords[7]);
		BankPosition4[Z] = floatstr(arrCoords[8]);
		BankPosition5[X] = floatstr(arrCoords[9]);
		BankPosition5[Y] = floatstr(arrCoords[10]);
		BankPosition5[Z] = floatstr(arrCoords[11]);
		BankPosition6[X] = floatstr(arrCoords[12]);
		BankPosition6[Y] = floatstr(arrCoords[13]);
		BankPosition6[Z] = floatstr(arrCoords[14]);
		BankPosition7[X] = floatstr(arrCoords[15]);
		BankPosition7[Y] = floatstr(arrCoords[16]);
		BankPosition7[Z] = floatstr(arrCoords[17]);
		BankPosition8[X] = floatstr(arrCoords[18]);
		BankPosition8[Y] = floatstr(arrCoords[19]);
		BankPosition8[Z] = floatstr(arrCoords[20]);
		BankPosition9[X] = floatstr(arrCoords[21]);
		BankPosition9[Y] = floatstr(arrCoords[22]);
		BankPosition9[Z] = floatstr(arrCoords[23]);
		BankPosition10[X] = floatstr(arrCoords[24]);
		BankPosition10[Y] = floatstr(arrCoords[25]);
		BankPosition10[Z] = floatstr(arrCoords[26]);
		BankPosition11[X] = floatstr(arrCoords[27]);
		BankPosition11[Y] = floatstr(arrCoords[28]);
		BankPosition11[Z] = floatstr(arrCoords[29]);
		
		//Creating Pickup
        BankPosition[PickupID] = CreateDynamicPickup(1239,1,BankPosition[X],BankPosition[Y],BankPosition[Z]);
        BankPosition2[PickupID] = CreateDynamicPickup(1239,1,BankPosition2[X],BankPosition2[Y],BankPosition2[Z]);
        BankPosition2[PickupID] = CreateDynamicPickup(1239,1,BankPosition3[X],BankPosition3[Y],BankPosition3[Z]);
        BankPosition3[PickupID] = CreateDynamicPickup(1239,1,BankPosition4[X],BankPosition4[Y],BankPosition4[Z]);
        BankPosition4[PickupID] = CreateDynamicPickup(1239,1,BankPosition5[X],BankPosition5[Y],BankPosition5[Z]);
        BankPosition5[PickupID] = CreateDynamicPickup(1239,1,BankPosition6[X],BankPosition6[Y],BankPosition6[Z]);
        BankPosition6[PickupID] = CreateDynamicPickup(1239,1,BankPosition7[X],BankPosition7[Y],BankPosition7[Z]);
        BankPosition7[PickupID] = CreateDynamicPickup(1239,1,BankPosition8[X],BankPosition8[Y],BankPosition8[Z]);
        BankPosition8[PickupID] = CreateDynamicPickup(1239,1,BankPosition9[X],BankPosition9[Y],BankPosition9[Z]);
        BankPosition9[PickupID] = CreateDynamicPickup(1239,1,BankPosition10[X],BankPosition10[Y],BankPosition10[Z]);
        BankPosition10[PickupID] = CreateDynamicPickup(1239,1,BankPosition11[X],BankPosition11[Y],BankPosition11[Z]);
		
		fclose(file);
		
		#if defined DEBUG
			print("[INFO:] Bank location loaded");
		#endif
	}
	else
		ErrorLog("[ERROR:] Can't load banklocation2.cfg");
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
	if(file2)
	{
		fwrite(file2, coordsstring);
		fclose(file2);
	}
	else
		ErrorLog("[ERROR:] Can't save banklocation2.cfg");
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
		SkillPosition[PickupIDHis] = CreateDynamicPickup(1239,1,SkillPosition[XHis],SkillPosition[YHis],SkillPosition[ZHis]);
		SkillPosition[PickupIDFiz] = CreateDynamicPickup(1239,1,SkillPosition[XFiz],SkillPosition[YFiz],SkillPosition[ZFiz]);
		SkillPosition[PickupIDBio] = CreateDynamicPickup(1239,1,SkillPosition[XBio],SkillPosition[YBio],SkillPosition[ZBio]);
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

LoadWheelChangePosition()
{
	new arrCoords[24][64];
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
		gWheelChangePos[pos5X] = floatstr(arrCoords[12]);
		gWheelChangePos[pos5Y] = floatstr(arrCoords[13]);
		gWheelChangePos[pos5Z] = floatstr(arrCoords[14]);
		gWheelChangePos[pos6X] = floatstr(arrCoords[15]);
		gWheelChangePos[pos6Y] = floatstr(arrCoords[16]);
		gWheelChangePos[pos6Z] = floatstr(arrCoords[17]);
		gWheelChangePos[pos7X] = floatstr(arrCoords[18]);
		gWheelChangePos[pos7Y] = floatstr(arrCoords[19]);
		gWheelChangePos[pos7Z] = floatstr(arrCoords[20]);
		gWheelChangePos[pos8X] = floatstr(arrCoords[21]);
		gWheelChangePos[pos8Y] = floatstr(arrCoords[22]);
		gWheelChangePos[pos8Z] = floatstr(arrCoords[23]);
		gWheelChangePos[pickup1] = CreateDynamicPickup(1239, 1, gWheelChangePos[pos1X], gWheelChangePos[pos1Y], gWheelChangePos[pos1Z]);
		gWheelChangePos[pickup2] = CreateDynamicPickup(1239, 1, gWheelChangePos[pos2X], gWheelChangePos[pos2Y], gWheelChangePos[pos2Z]);
		gWheelChangePos[pickup3] = CreateDynamicPickup(1239, 1, gWheelChangePos[pos3X], gWheelChangePos[pos3Y], gWheelChangePos[pos3Z]);
		gWheelChangePos[pickup4] = CreateDynamicPickup(1239, 1, gWheelChangePos[pos4X], gWheelChangePos[pos4Y], gWheelChangePos[pos4Z]);
		gWheelChangePos[pickup5] = CreateDynamicPickup(1239, 1, gWheelChangePos[pos5X], gWheelChangePos[pos5Y], gWheelChangePos[pos5Z]);
		gWheelChangePos[pickup6] = CreateDynamicPickup(1239, 1, gWheelChangePos[pos6X], gWheelChangePos[pos6Y], gWheelChangePos[pos6Z]);
		gWheelChangePos[pickup7] = CreateDynamicPickup(1239, 1, gWheelChangePos[pos7X], gWheelChangePos[pos7Y], gWheelChangePos[pos7Z]);
		gWheelChangePos[pickup8] = CreateDynamicPickup(1239, 1, gWheelChangePos[pos8X], gWheelChangePos[pos8Y], gWheelChangePos[pos8Z]);
		fclose(file);
		#if defined DEBUG
			print("[INFO:] Wheel change locations loaded");
		#endif
	}
	else
		ErrorLog("[ERROR:] Can't load wheelchangeposition.cfg ");
	return 1;
}

SaveWheelChangePosition()
{
	new File: file;
	new coordstring[512];
	format(coordstring, sizeof(coordstring), "%f|%f|%f|%f|%f|%f|%f|%f|%f|%f|%f|%f|%f|%f|%f|%f|%f|%f|%f|%f|%f|%f|%f|%f\n",
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
	gWheelChangePos[pos4Z],
	gWheelChangePos[pos5X],
	gWheelChangePos[pos5Y],
	gWheelChangePos[pos5Z],
	gWheelChangePos[pos6X],
	gWheelChangePos[pos6Y],
	gWheelChangePos[pos6Z],
	gWheelChangePos[pos7X],
	gWheelChangePos[pos7Y],
	gWheelChangePos[pos7Z],
	gWheelChangePos[pos8X],
	gWheelChangePos[pos8Y],
	gWheelChangePos[pos8Z]);
	file = fopen("locations/wheelchangeposition.cfg", io_write);
	if(file)
	{
		fwrite(file, coordstring);
		fclose(file);
	}
	else
		ErrorLog("[ERROR:] Can't save wheelchangeposition.cfg ");
	return 1;
}

// LoadWantedList()
// {
	// new string[128];
	// format(string, sizeof(string), "SELECT * FROM samp_wanted LIMIT 1000");
	// mysql_query(string, LOAD_WANTED_LIST, INVALID_PLAYER_ID, db_con1);
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
	mysql_query( string, LOAD_BUS_TRACKS, INVALID_PLAYER_ID, db_con2 );
	
	format( string, sizeof(string), "SELECT * FROM `samp_bus_tracks_data`" );
	mysql_query( string, LOAD_BUS_TRACKS_DATA, INVALID_PLAYER_ID, db_con2 );
	
	return 1;
}

LoadTrashTracks()
{
	new string[128];
	
	format( string, sizeof(string), "SELECT * FROM `samp_trash_tracks`" );
	mysql_query( string, LOAD_TRASH_TRACKS, INVALID_PLAYER_ID, db_con2 );
	
	format( string, sizeof(string), "SELECT * FROM `samp_trash_tracks_data`" );
	mysql_query( string, LOAD_TRASH_TRACKS_DATA, INVALID_PLAYER_ID, db_con2 );
	
	return 1;
}

LoadSweeperTracks()
{
	new string[128];
	
	format( string, sizeof(string), "SELECT * FROM `samp_sweeper_tracks`" );
	mysql_query( string, LOAD_SWEEPER_TRACKS, INVALID_PLAYER_ID, db_con2 );
	
	format( string, sizeof(string), "SELECT * FROM `samp_sweeper_tracks_data`" );
	mysql_query( string, LOAD_SWEEPER_TRACKS_DATA, INVALID_PLAYER_ID, db_con2 );
	
	return 1;
}

LoadFarmerTracks()
{
	new string[128];
	
	format( string, sizeof(string), "SELECT * FROM `samp_farmer_tracks`" );
	mysql_query( string, LOAD_FARMER_TRACKS, INVALID_PLAYER_ID, db_con2 );
	
	format( string, sizeof(string), "SELECT * FROM `samp_farmer_tracks_data`" );
	mysql_query( string, LOAD_FARMER_TRACKS_DATA, INVALID_PLAYER_ID, db_con2 );
	
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
	
	format(string, sizeof(string), "SELECT * FROM `samp_objects` ORDER BY `id` ASC");
	mysql_query(string, LOAD_CUSTOM_OBJECTS, INVALID_PLAYER_ID, db_con2);
	
	return 1;
}

LoadItemFactories()
{
	new string[128];
	
	format(string, sizeof(string), "SELECT * FROM `samp_item_factories` ORDER BY `id`");
	mysql_query(string, LOAD_ITEM_FACTORIES, INVALID_PLAYER_ID, db_con2);
	
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
	
	format(string, sizeof(string), "SELECT * FROM `samp_races_tracks` ORDER BY `id` ASC");
	mysql_query(string, LOAD_RACES_TRACKS, INVALID_PLAYER_ID, db_con2 );
	
	format(string, sizeof(string), "SELECT * FROM `samp_races_tracks_data` ORDER BY `id` ASC");
	mysql_query(string, LOAD_RACES_TRACKS_DATA, INVALID_PLAYER_ID, db_con2 );
	
	return 1;
}

LoadWeed()
{
	new string[128];
	
	format(string, sizeof(string), "SELECT * FROM `samp_weed`");
	mysql_query(string, LOAD_WEED, INVALID_PLAYER_ID, db_con2 );
	
	return 1;
}
