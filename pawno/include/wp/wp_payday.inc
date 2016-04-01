/***
*
* File: wp_payday.inc
* Auth: Damian Wojdat
* Date: 15.09.2011
* Desc: Payday function.
*
*************************************************************************************************************/

stock PayDay()
{
	new string[256], Float:px, Float:py, Float:pz, Float:emmision, slot[MAX_VEHICLE_ITEM_SLOT];
	#if defined DEBUG
		print("[TIMERCHECK:] PayDay()");
	#endif
	
	RafineryResourcesIncrease();	
	WFactoryLegalLight[WFactory9MM] += 2;
	WFactoryLegalLight[WFactory9MMAmmo] += 34;
	SaveWFactoryData("WFactory9MM");
	SaveWFactoryData("WFactory9MMAmmo");
	
	/*
	*	Every payday load new event location
	*/
	LoadRandomPickupEvent();
	
	/*
	* Item factory items reproduce
	*/
	for(new i = 0; i < sizeof(gItemFactories); i++)
	{
		gItemFactories[i][item1count] += gItemFactories[i][item1reproduceCount];
		gItemFactories[i][item2count] += gItemFactories[i][item2reproduceCount];
		gItemFactories[i][item3count] += gItemFactories[i][item3reproduceCount];
		gItemFactories[i][item4count] += gItemFactories[i][item4reproduceCount];
		gItemFactories[i][item5count] += gItemFactories[i][item5reproduceCount];
		gItemFactories[i][item6count] += gItemFactories[i][item6reproduceCount];
		gItemFactories[i][item7count] += gItemFactories[i][item7reproduceCount];
		gItemFactories[i][item8count] += gItemFactories[i][item8reproduceCount];
		gItemFactories[i][item9count] += gItemFactories[i][item9reproduceCount];
		gItemFactories[i][item10count] += gItemFactories[i][item10reproduceCount];
		SaveItemFactory(i, "item1");
		SaveItemFactory(i, "item2");
		SaveItemFactory(i, "item3");
		SaveItemFactory(i, "item4");
		SaveItemFactory(i, "item5");
		SaveItemFactory(i, "item6");
		SaveItemFactory(i, "item7");
		SaveItemFactory(i, "item8");
		SaveItemFactory(i, "item9");
		SaveItemFactory(i, "item10");
	}
	
	/*
	* Vehicle related cost
	* Trunk check
	*/
	for(new i = 0; i < sizeof(gVehData); i++)
	{
		/*
		* Fix faction vehicles
		*/
		if(gVehData[i][mVehFaction] == 0 || gVehData[i][mVehFaction] == 2 || gVehData[i][mVehFaction] == 9)
		{
			if(gVehData[i][CarHealth] > 500.0 || gVehData[i][CarHealth] < 1000.0)
			{
				if(DynamicFactions[gVehData[i][mVehFaction]][fBank] > 0)
				{
					DynamicFactions[gVehData[i][mVehFaction]][fBank] -= 100;
					SaveFData(gVehData[i][mVehFaction], "Bank");
					RepairVehicle(i+1);
					gVehData[i][CarDamaged] = 0;
					gVehData[i][CarRepairTimeLeft] = 0;
					gVehData[i][CarHealth] = 1000.0;
					
					SaveVehData(i, "CarHealth");
					SaveVehData(i, "CarDamaged");
					SaveVehData(i, "CarRepairTimeLeft");
				}
			}
		}
		
		if((strcmp(gVehData[i][Owner], "None", true) == 0 || strlen(gVehData[i][Owner]) < 0 ||
			strfind(gVehData[i][Owner], "_", true) == -1) && gVehData[i][mVehFaction] == 255)
		{
			continue;
		}
		/*
		* Pay for OC/AC
		*/
		VHaveItemEx(i, 3, 19, slot);
		for(new j = 1; j <= MAX_VEHICLE_ITEM_SLOT; j++)
		{
			if(slot[j-1])
			{
				if(VSlotParam3(i+1, j) > 0)
				{
					UpdatePlayerDataByName(gVehData[i][Owner], "Bank", -4);
					DynamicFactions[FACTIONID_GOVERNMENT][fBank] += 4;
				}
				if(VSlotParam4(i+1, j) > 0)
				{
					UpdatePlayerDataByName(gVehData[i][Owner], "Bank", -6);
					DynamicFactions[FACTIONID_GOVERNMENT][fBank] += 6;
				}
			}
		}
		if(gVehData[i][mVehFaction] == 255)
		{
			/*
			* Tax from engine capacity
			*/
			if(IsAMotorBike(i+1))
			{
				UpdatePlayerDataByName(gVehData[i][Owner], "Bank", -1);
				format(string, sizeof(string), "[PAYDAY:] Player %s tax from engine capacity vehicle %d, value 1$", gVehData[i][Owner], i+1);
				PayDayLog(string);
			}
			else if(IsAOffroadCar(i+1))
			{
				UpdatePlayerDataByName(gVehData[i][Owner], "Bank", -4);
				format(string, sizeof(string), "[PAYDAY:] Player %s tax from engine capacity vehicle %d, value 4$", gVehData[i][Owner], i+1);
				PayDayLog(string);
			}
			else if(IsASportsCar(i+1))
			{
				UpdatePlayerDataByName(gVehData[i][Owner], "Bank", -6);
				format(string, sizeof(string), "[PAYDAY:] Player %s tax from engine capacity vehicle %d, value 6$", gVehData[i][Owner], i+1);
				PayDayLog(string);
			}
			else if(IsAHardTruck(i+1))
			{
				UpdatePlayerDataByName(gVehData[i][Owner], "Bank", -8);
				format(string, sizeof(string), "[PAYDAY:] Player %s tax from engine capacity vehicle %d, value 8$", gVehData[i][Owner], i+1);
				PayDayLog(string);
			}
			else 
			{
				UpdatePlayerDataByName(gVehData[i][Owner], "Bank", -2);
				format(string, sizeof(string), "[PAYDAY:] Player %s tax from engine capacity vehicle %d, value 2$", gVehData[i][Owner], i+1);
				PayDayLog(string);
			}
			
			/*
			* Tax from CO2 emmision
			*/
			VehCo2Emmision(i+1, emmision);
			if(emmision >= 0.01 && emmision <= 0.207)
			{
				UpdatePlayerDataByName(gVehData[i][Owner], "Bank", -2);
				format(string, sizeof(string), "[PAYDAY:] Player %s tax from co2 vehicle %d, value 2$", gVehData[i][Owner], i+1);
				PayDayLog(string);
			}
			else if(emmision > 0.207 && emmision <= 0.437)
			{
				UpdatePlayerDataByName(gVehData[i][Owner], "Bank", -3);
				format(string, sizeof(string), "[PAYDAY:] Player %s tax from co2 vehicle %d, value 3$", gVehData[i][Owner], i+1);
				PayDayLog(string);
			}
			else if(emmision > 0.437 && emmision <= 0.667)
			{
				UpdatePlayerDataByName(gVehData[i][Owner], "Bank", -5);
				format(string, sizeof(string), "[PAYDAY:] Player %s tax from co2 vehicle %d, value 5$", gVehData[i][Owner], i+1);
				PayDayLog(string);
			}
			else if(emmision > 0.667 && emmision <= 0.897)
			{
				UpdatePlayerDataByName(gVehData[i][Owner], "Bank", -7);
				format(string, sizeof(string), "[PAYDAY:] Player %s tax from co2 vehicle %d, value 7$", gVehData[i][Owner], i+1);
				PayDayLog(string);
			}
			else if(emmision > 0.897)
			{
				UpdatePlayerDataByName(gVehData[i][Owner], "Bank", -9);
				format(string, sizeof(string), "[PAYDAY:] Player %s tax from co2 vehicle %d, value 9$", gVehData[i][Owner], i+1);
				PayDayLog(string);
			}
		}
		else
		{
			/*
			* Tax from engine capacity
			*/
			if(IsAMotorBike(i+1))
			{
				DynamicFactions[gVehData[i][mVehFaction]][fBank] -= 1;
				SaveFData(gVehData[i][mVehFaction], "Bank");
				format(string, sizeof(string), "[PAYDAY:] Faction %d tax from engine capacity vehicle %d, value 5$", gVehData[i][mVehFaction], i+1);
				PayDayLog(string);
			}
			else if(IsAOffroadCar(i+1))
			{
				DynamicFactions[gVehData[i][mVehFaction]][fBank] -= 4;
				SaveFData(gVehData[i][mVehFaction], "Bank");
				format(string, sizeof(string), "[PAYDAY:] Faction %d tax from engine capacity vehicle %d, value 4$", gVehData[i][mVehFaction], i+1);
				PayDayLog(string);
			}
			else if(IsASportsCar(i+1))
			{
				DynamicFactions[gVehData[i][mVehFaction]][fBank] -= 6;
				SaveFData(gVehData[i][mVehFaction], "Bank");
				format(string, sizeof(string), "[PAYDAY:] Faction %d tax from engine capacity vehicle %d, value 6$", gVehData[i][mVehFaction], i+1);
				PayDayLog(string);
			}
			else if(IsAHardTruck(i+1))
			{
				DynamicFactions[gVehData[i][mVehFaction]][fBank] -= 8;
				SaveFData(gVehData[i][mVehFaction], "Bank");
				format(string, sizeof(string), "[PAYDAY:] Faction %d tax from engine capacity vehicle %d, value 8$", gVehData[i][mVehFaction], i+1);
				PayDayLog(string);
			}
			else
			{
				DynamicFactions[gVehData[i][mVehFaction]][fBank] -= 2;
				SaveFData(gVehData[i][mVehFaction], "Bank");
				format(string, sizeof(string), "[PAYDAY:] Faction %d tax from engine capacity vehicle %d, value 2$", gVehData[i][mVehFaction], i+1);
				PayDayLog(string);
			}
			
			/*
			* Tax from CO2 emmision
			*/
			VehCo2Emmision(i+1, emmision);
			if(emmision >= 0.01 && emmision <= 0.207)
			{
				DynamicFactions[gVehData[i][mVehFaction]][fBank] -= 2;
				SaveFData(gVehData[i][mVehFaction], "Bank");
				format(string, sizeof(string), "[PAYDAY:] Faction %d tax from co2 vehicle %d, value 2$", gVehData[i][mVehFaction], i+1);
				PayDayLog(string);
			}
			else if(emmision > 0.207 && emmision <= 0.437)
			{
				DynamicFactions[gVehData[i][mVehFaction]][fBank] -= 3;
				SaveFData(gVehData[i][mVehFaction], "Bank");
				format(string, sizeof(string), "[PAYDAY:] Faction %d tax from co2 vehicle %d, value 3$", gVehData[i][mVehFaction], i+1);
				PayDayLog(string);
			}
			else if(emmision > 0.437 && emmision <= 0.667)
			{
				DynamicFactions[gVehData[i][mVehFaction]][fBank] -= 5;
				SaveFData(gVehData[i][mVehFaction], "Bank");
				format(string, sizeof(string), "[PAYDAY:] Faction %d tax from co2 vehicle %d, value 5$", gVehData[i][mVehFaction], i+1);
				PayDayLog(string);
			}
			else if(emmision > 0.667 && emmision <= 0.897)
			{
				DynamicFactions[gVehData[i][mVehFaction]][fBank] -= 7;
				SaveFData(gVehData[i][mVehFaction], "Bank");
				format(string, sizeof(string), "[PAYDAY:] Faction %d tax from co2 vehicle %d, value 7$", gVehData[i][mVehFaction], i+1);
				PayDayLog(string);
			}
			else if(emmision > 0.897)
			{
				DynamicFactions[gVehData[i][mVehFaction]][fBank] -= 9;
				SaveFData(gVehData[i][mVehFaction], "Bank");
				format(string, sizeof(string), "[PAYDAY:] Faction %d tax from co2 vehicle %d, value 9$", gVehData[i][mVehFaction], i+1);
				PayDayLog(string);
			}
		}	
	}
	
	/*
	* TODO: Taxes from businesses
	* Resets daily cash income data
	* NOTE: Check if all is done properly, needs tests
	*/
	new todayincome, tax;
	for(new i = 0; i < sizeof(Businesses); i++)
	{
		switch(Businesses[i][BizType])
		{
			case 1,3:
			{
				todayincome = Businesses[i][Product1incomeToday]+Businesses[i][Product2incomeToday]+Businesses[i][Product3incomeToday]+Businesses[i][Product4incomeToday]+Businesses[i][Product5incomeToday];
				todayincome += Businesses[i][Product6incomeToday]+Businesses[i][Product7incomeToday]+Businesses[i][Product8incomeToday]+Businesses[i][Product9incomeToday]+Businesses[i][Product10incomeToday];
				todayincome += Businesses[i][mIncomeEntranceToday];
				if(todayincome > 0)
					tax = floatround(todayincome*DynamicTaxes[BusinessTax]);
				
			}
			case 2:
			{
				todayincome = Businesses[i][mIncomeEntranceToday] + Businesses[i][mIncomePhoneToday];
				if(todayincome > 0)
					tax = floatround(todayincome*DynamicTaxes[BusinessTax]);
			}
			case 4:
			{
				todayincome = Businesses[i][mIncomeEntranceToday] + Businesses[i][mIncomePhoneToday];
				if(todayincome > 0)
					tax = floatround(todayincome*DynamicTaxes[BusinessTax]);
			}
			case 5,6:
			{
				todayincome = Businesses[i][mIncomeEntranceToday];
				if(todayincome > 0)
					tax = floatround(todayincome*DynamicTaxes[BusinessTax]);
			}
			case 10:
			{
				todayincome = Businesses[i][mIncomeEntranceToday] + Businesses[i][mIncomeVehicleToday];
				if(todayincome > 0)
					tax = floatround(todayincome*DynamicTaxes[BusinessTax]);
			}
			case 11:
			{
				todayincome = Businesses[i][mIncomeEntranceToday] + Businesses[i][mIncomeFuelPetrolToday] + Businesses[i][mIncomeFuelOilToday] + Businesses[i][mIncomeFuelGasToday];
				if(todayincome > 0)
					tax = floatround(todayincome*DynamicTaxes[BusinessTax]);
			}
		}
		UpdatePlayerDataByName(gVehData[i][Owner], "Bank", -tax);
		Businesses[i][Product1incomeToday] = 0;
		Businesses[i][Product2incomeToday] = 0;
		Businesses[i][Product3incomeToday] = 0;
		Businesses[i][Product4incomeToday] = 0;
		Businesses[i][Product5incomeToday] = 0;
		Businesses[i][Product6incomeToday] = 0;
		Businesses[i][Product7incomeToday] = 0;
		Businesses[i][Product8incomeToday] = 0;
		Businesses[i][Product9incomeToday] = 0;
		Businesses[i][Product10incomeToday] = 0;
		Businesses[i][mIncomePhoneToday] = 0;
		Businesses[i][mIncomeFuelPetrolToday] = 0;
		Businesses[i][mIncomeFuelOilToday] = 0;
		Businesses[i][mIncomeFuelGasToday] = 0;
		Businesses[i][mIncomeEntranceToday] = 0;
		Businesses[i][mW9MMIncomeToday] = 0;
		Businesses[i][mW9MMSilIncomeToday] = 0;
		Businesses[i][mWDesEagleIncomeToday] = 0;
		Businesses[i][mWMicroSMGIncomeToday] = 0;
		Businesses[i][mWMP5IncomeToday] = 0;
		Businesses[i][mWTec9IncomeToday] = 0;
		Businesses[i][mWShotgunIncomeToday] = 0;
		Businesses[i][mWAK47IncomeToday] = 0;
		Businesses[i][mWM4IncomeToday] = 0;
		Businesses[i][mWRifleIncomeToday] = 0;
		Businesses[i][mWSRifleIncomeToday] = 0;
		Businesses[i][mW9MMAmmoIncomeToday] = 0;
		Businesses[i][mW50AEAmmoIncomeToday] = 0;
		Businesses[i][mWBuckshotIncomeToday] = 0;
		Businesses[i][mW762MMAmmoIncomeToday] = 0;
		Businesses[i][mW127MMAmmoIncomeToday] = 0;
		SaveBizData(i, "mW9MMIncomeToday");
		SaveBizData(i, "mW9MMSilIncomeToday");
		SaveBizData(i, "mWDesEagleIncomeToday");
		SaveBizData(i, "mWMicroSMGIncomeToday");
		SaveBizData(i, "mWMP5IncomeToday");
		SaveBizData(i, "mWTec9IncomeToday");
		SaveBizData(i, "mWShotgunIncomeToday");
		SaveBizData(i, "mWAK47IncomeToday");
		SaveBizData(i, "mWM4IncomeToday");
		SaveBizData(i, "mWRifleIncomeToday");
		SaveBizData(i, "mWSRifleIncomeToday");
		SaveBizData(i, "mW9MMAmmoIncomeToday");
		SaveBizData(i, "mW50AEAmmoIncomeToday");
		SaveBizData(i, "mWBuckshotIncomeToday");
		SaveBizData(i, "mW762MMAmmoIncomeToday");
		SaveBizData(i, "mW127MMAmmoIncomeToday");
		SaveBizData(i, "Product1incomeToday");
		SaveBizData(i, "Product2incomeToday");
		SaveBizData(i, "Product3incomeToday");
		SaveBizData(i, "Product4incomeToday");
		SaveBizData(i, "Product5incomeToday");
		SaveBizData(i, "Product6incomeToday");
		SaveBizData(i, "Product7incomeToday");
		SaveBizData(i, "Product8incomeToday");
		SaveBizData(i, "Product9incomeToday");
		SaveBizData(i, "Product10incomeToday");
		SaveBizData(i, "IncomePhoneToday");
		SaveBizData(i, "IncomeFuelPetrolToday");
		SaveBizData(i, "IncomeFuelOilToday");
		SaveBizData(i, "IncomeFuelGasToday");
		SaveBizData(i, "IncomeEntranceToday");
	}
	
	/*
	* House taxes
	* House trunk taxes
	*/
	new payer[MAX_PLAYER_NAME]; // check if owner or renter is responsible for taxes
	for(new i = 0; i < sizeof(Houses); i++)
	{
		if((strcmp(Houses[i][Owner], "None", true) == 0 || strlen(Houses[i][Owner]) < 0 || strfind(Houses[i][Owner], "_", true) == -1))
		{
			continue;
		}
		if(strcmp(Houses[i][HRenter], "Brak", true) == 0 || strlen(Houses[i][HRenter]) < 0 || strfind(Houses[i][HRenter], "_", true) == -1)
			format(payer, sizeof(payer), Houses[i][Owner]);
		else
			format(payer, sizeof(payer), Houses[i][HRenter]);
			
		/*
		* Pay for OC/AC
		*/
		HHaveItemEx(i, 3, 19, slot);
		for(new j = 1; j <= MAX_HOUSE_ITEM_SLOT; j++)
		{
			if(slot[j-1])
			{
				if(HSlotParam3(i+1, j) > 0)
				{
					UpdatePlayerDataByName(payer, "Bank", -4);
					DynamicFactions[FACTIONID_GOVERNMENT][fBank] += 4;
				}
				if(HSlotParam4(i+1, j) > 0)
				{
					UpdatePlayerDataByName(payer, "Bank", -6);
					DynamicFactions[FACTIONID_GOVERNMENT][fBank] += 6;
				}
			}
		}
	}
	
	/*
	* Builds illegal factory
	* Decreases steal time left
	*/
	for(new i = 0; i < sizeof(DynamicFactions); i++) 
	{
		if(DynamicFactions[i][WFactoryJustBought])
		{
			px = DynamicFactions[i][WFactoryCentrePosX];
			py = DynamicFactions[i][WFactoryCentrePosY];
			pz = DynamicFactions[i][WFactoryCentrePosZ];
			DynamicFactions[i][WFactoryObjects][0] = CreateDynamicObject(18267, px, py, pz, 0.0, 0.0, 0.0);
			DynamicFactions[i][WFactoryObjects][1] = CreateDynamicObject(2061, px+WFObj[0][0], py+WFObj[0][1], pz+WFObj[0][2], WFObj[0][3], WFObj[0][4], WFObj[0][5]);	
			DynamicFactions[i][WFactoryObjects][2] = CreateDynamicObject(1212 , px+WFObj[1][0], py+WFObj[1][1], pz+WFObj[1][2], WFObj[1][3], WFObj[1][4], WFObj[1][5]);	
			DynamicFactions[i][WFactoryObjects][3] = CreateDynamicObject(1550, px+WFObj[2][0], py+WFObj[2][1], pz+WFObj[2][2], WFObj[2][3], WFObj[2][4], WFObj[2][5]);	
			DynamicFactions[i][WFactoryObjects][4] = CreateDynamicObject(1550, px+WFObj[3][0], py+WFObj[3][1], pz+WFObj[3][2], WFObj[3][3], WFObj[3][4], WFObj[3][5]);	
			DynamicFactions[i][WFactoryObjects][5] = CreateDynamicObject(1650, px+WFObj[4][0], py+WFObj[4][1], pz+WFObj[4][2], WFObj[4][3], WFObj[4][4], WFObj[4][5]);	
			DynamicFactions[i][WFactoryObjects][6] = CreateDynamicObject(2035, px+WFObj[5][0], py+WFObj[5][1], pz+WFObj[5][2], WFObj[5][3], WFObj[5][4], WFObj[5][5]);	
			DynamicFactions[i][WFactoryObjects][7] = CreateDynamicObject(2036, px+WFObj[6][0], py+WFObj[6][1], pz+WFObj[6][2], WFObj[6][3],WFObj[6][4], WFObj[6][5]);	
			DynamicFactions[i][WFactoryObjects][8] = CreateDynamicObject(2037, px+WFObj[7][0], py+WFObj[7][1], pz+WFObj[7][2], WFObj[7][3], WFObj[7][4], WFObj[7][5]);	
			DynamicFactions[i][WFactoryObjects][9] = CreateDynamicObject(2044, px+WFObj[8][0], py+WFObj[8][1], pz+WFObj[8][2], WFObj[8][3], WFObj[8][4], WFObj[8][5]);	
			DynamicFactions[i][WFactoryObjects][10] = CreateDynamicObject(2057, px+WFObj[9][0], py+WFObj[9][1], pz+WFObj[9][2], WFObj[9][3], WFObj[9][4], WFObj[9][5]);	
			DynamicFactions[i][WFactoryObjects][11] = CreateDynamicObject(2059, px+WFObj[10][0], py+WFObj[10][1], pz+WFObj[10][2], WFObj[10][3], WFObj[10][4], WFObj[10][5]);	
			DynamicFactions[i][WFactoryObjects][12] = CreateDynamicObject(3387, px+WFObj[11][0], py+WFObj[11][1], pz+WFObj[11][2], WFObj[11][3], WFObj[11][4], WFObj[11][5]);	
			DynamicFactions[i][WFactoryObjects][13] = CreateDynamicObject(3389, px+WFObj[12][0], py+WFObj[12][1], pz+WFObj[12][2], WFObj[12][3], WFObj[12][4], WFObj[12][5]);	
			DynamicFactions[i][WFactoryObjects][14] = CreateDynamicObject(3391 , px+WFObj[13][0], py+WFObj[13][1], pz+WFObj[13][2], WFObj[13][3], WFObj[13][4], WFObj[13][5]);	
			DynamicFactions[i][WFactoryObjects][15] = CreateDynamicObject(3396 , px+WFObj[14][0], py+WFObj[14][1], pz+WFObj[14][2], WFObj[14][3], WFObj[14][4], WFObj[14][5]);	
			DynamicFactions[i][WFactoryObjects][16] = CreateDynamicObject(3787 , px+WFObj[15][0], py+WFObj[15][1], pz+WFObj[15][2], WFObj[15][3], WFObj[15][4], WFObj[15][5]);	
			DynamicFactions[i][WFactoryObjects][17] = CreateDynamicObject(1222 , px+WFObj[16][0], py+WFObj[16][1], pz+WFObj[16][2], WFObj[16][3], WFObj[16][4], WFObj[16][5]);	
			DynamicFactions[i][WFactoryObjects][18] = CreateDynamicObject(939 , px+WFObj[17][0], py+WFObj[17][1], pz+WFObj[17][2], WFObj[17][3], WFObj[17][4], WFObj[17][5]);	
			DynamicFactions[i][WFactoryObjects][19] = CreateDynamicObject(2333 , px+WFObj[18][0], py+WFObj[18][1], pz+WFObj[18][2], WFObj[18][3], WFObj[18][4], WFObj[18][5]);	
			DynamicFactions[i][WFactoryObjects][20] = CreateDynamicObject(1212 , px+WFObj[19][0], py+WFObj[19][1], pz+WFObj[19][2], WFObj[19][3], WFObj[19][4], WFObj[19][5]);	
			DynamicFactions[i][WFactoryObjects][21] = CreateDynamicObject(1212 , px+WFObj[20][0], py+WFObj[20][1], pz+WFObj[20][2], WFObj[20][3], WFObj[20][4], WFObj[20][5]);	
			DynamicFactions[i][WFactoryObjects][22] = CreateDynamicObject(1212 , px+WFObj[21][0], py+WFObj[21][1], pz+WFObj[21][2], WFObj[21][3], WFObj[21][4], WFObj[21][5]);	
			DynamicFactions[i][WFactoryObjects][23] = CreateDynamicObject(2186 , px+WFObj[22][0], py+WFObj[22][1], pz+WFObj[22][2], WFObj[22][3], WFObj[22][4], WFObj[22][5]);	
			DynamicFactions[i][WFactoryObjects][24] = CreateDynamicObject(1829 , px+WFObj[23][0], py+WFObj[23][1], pz+WFObj[23][2], WFObj[23][3], WFObj[23][4], WFObj[23][5]);	
			DynamicFactions[i][WFactoryObjects][25] = CreateDynamicObject(1728 , px+WFObj[24][0], py+WFObj[24][1], pz+WFObj[24][2], WFObj[24][3], WFObj[24][4], WFObj[24][5]);	
			DynamicFactions[i][WFactoryObjects][26] = CreateDynamicObject(2037 , px+WFObj[25][0], py+WFObj[25][1], pz+WFObj[25][2], WFObj[25][3], WFObj[25][4], WFObj[25][5]);	
			DynamicFactions[i][WFactoryObjects][27] = CreateDynamicObject(2037 , px+WFObj[26][0], py+WFObj[26][1], pz+WFObj[26][2], WFObj[26][3], WFObj[26][4], WFObj[26][5]);	
			DynamicFactions[i][WFactoryObjects][28] = CreateDynamicObject(2037 , px+WFObj[27][0], py+WFObj[27][1], pz+WFObj[27][2], WFObj[27][3], WFObj[27][4], WFObj[27][5]);	
			DynamicFactions[i][WFactoryObjects][29] = CreateDynamicObject(2044 , px+WFObj[28][0], py+WFObj[28][1], pz+WFObj[28][2], WFObj[28][3], WFObj[28][4], WFObj[28][5]);	
			DynamicFactions[i][WFactoryObjects][30] = CreateDynamicObject(18725 , px+WFObj[29][0], py+WFObj[29][1], pz+WFObj[29][2], WFObj[29][3], WFObj[29][4], WFObj[29][5]); // DYM	
			// DynamicFactions[i][WFactoryObjects][31] = CreateDynamicObject(18693 , px+WFObj[30][0], py+WFObj[30][1], pz+WFObj[30][2], WFObj[30][3], WFObj[30][4], WFObj[30][5]);
			DynamicFactions[i][WFactoryCPPartSetup1ID] = CreateDynamicCP(px+WFCP[0][0], py+WFCP[0][1], pz+WFCP[0][2], 2.0); // Make weapon parts
			DynamicFactions[i][WFactoryCPPartSetup2ID] = CreateDynamicCP(px+WFCP[1][0], py+WFCP[1][1], pz+WFCP[1][2], 2.0); // Make weapon parts
			DynamicFactions[i][WFactoryCPAmmoPartSetup1ID] = CreateDynamicCP(px+WFCP[2][0], py+WFCP[2][1], pz+WFCP[2][2], 2.0); // Make weapon subparts
			DynamicFactions[i][WFactoryCPPartTakeID] = CreateDynamicCP(px+WFCP[3][0], py+WFCP[3][1], pz+WFCP[3][2], 2.0); // Take/buy ammo/weapon (sub) parts
			DynamicFactions[i][WFactoryCPAmmoPartSetup2ID] = CreateDynamicCP(px+WFCP[4][0], py+WFCP[4][1], pz+WFCP[4][2], 2.0); // Make weapon subparts
			DynamicFactions[i][WFactoryEnabled] = 1;
			DynamicFactions[i][WFactoryJustBought] = 0;
			SaveFData(i, "WFactoryJustBought");
			SaveFData(i, "WFactoryEnabled");
		}
	}
	
	/*
	* Minimal payday for connected players
	* Some stuff still needs to be done in full payday
	*/
	for(new i = 0; i < CUSTOM_MAX_PLAYERS; i++)
	{
		if(!IsPlayerConnected(i) || !gPlayerLogged[i] || gPlayerData[i][pAdmin] > 0)
		{
			continue;
		}
		if(gPlayerData[i][pJailed] == 1)
		{
			SendClientMessage(i, COLOR_RED, "[INFO:] Nie mo¿esz otrzymaæ wyp³aty bêd¹c w wiêzieniu !");
			continue;
		}
		
		/*
		* Give player faction payment and other payment
		*/
		if(gPlayerData[i][pFaction] != 255)
		{
			for(new n = 0; n < sizeof(DynamicFactions); n++)
			{
				if(PayRank[n][FactionID] == gPlayerData[i][pFaction])
				{
					switch(gPlayerData[i][pRank])
					{
						case 1:
						{
							format(string, sizeof(string), "[PAYDAY:] Player name = %s, rank 1, Bank = %d + %d, Faction id = %d, Bank = %d - %d",
								gPlayerData[i][pName], gPlayerData[i][pBank], PayRank[n][Rank2], gPlayerData[i][pFaction], DynamicFactions[gPlayerData[i][pFaction]][fBank], PayRank[n][Rank2]);
							gPlayerData[i][pBank] += PayRank[n][Rank1];
							DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank1];
						}
						case 2:
						{
							format(string, sizeof(string), "[PAYDAY:] Player name = %s, rank 2, Bank = %d + %d, Faction id = %d, Bank = %d - %d",
								gPlayerData[i][pName], gPlayerData[i][pBank], PayRank[n][Rank2], gPlayerData[i][pFaction], DynamicFactions[gPlayerData[i][pFaction]][fBank], PayRank[n][Rank2]);
							gPlayerData[i][pBank] += PayRank[n][Rank2];
							DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank2];							
						}
						case 3:
						{
							format(string, sizeof(string), "[PAYDAY:] Player name = %s, rank 3, Bank = %d + %d, Faction id = %d, Bank = %d - %d",
								gPlayerData[i][pName], gPlayerData[i][pBank], PayRank[n][Rank2], gPlayerData[i][pFaction], DynamicFactions[gPlayerData[i][pFaction]][fBank], PayRank[n][Rank2]);
							gPlayerData[i][pBank] += PayRank[n][Rank3];
							DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank3];
						}
						case 4:
						{
							format(string, sizeof(string), "[PAYDAY:] Player name = %s, rank 4, Bank = %d + %d, Faction id = %d, Bank = %d - %d",
								gPlayerData[i][pName], gPlayerData[i][pBank], PayRank[n][Rank2], gPlayerData[i][pFaction], DynamicFactions[gPlayerData[i][pFaction]][fBank], PayRank[n][Rank2]);
							gPlayerData[i][pBank] += PayRank[n][Rank4];
							DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank4];
						}
						case 5:
						{
							format(string, sizeof(string), "[PAYDAY:] Player name = %s, rank 5, Bank = %d + %d, Faction id = %d, Bank = %d - %d",
								gPlayerData[i][pName], gPlayerData[i][pBank], PayRank[n][Rank2], gPlayerData[i][pFaction], DynamicFactions[gPlayerData[i][pFaction]][fBank], PayRank[n][Rank2]);
							gPlayerData[i][pBank] += PayRank[n][Rank5];
							DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank5];
						}
						case 6:
						{
							format(string, sizeof(string), "[PAYDAY:] Player name = %s, rank 6, Bank = %d + %d, Faction id = %d, Bank = %d - %d",
								gPlayerData[i][pName], gPlayerData[i][pBank], PayRank[n][Rank2], gPlayerData[i][pFaction], DynamicFactions[gPlayerData[i][pFaction]][fBank], PayRank[n][Rank2]);
							gPlayerData[i][pBank] += PayRank[n][Rank6];
							DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank6];
						}
						case 7:
						{
							format(string, sizeof(string), "[PAYDAY:] Player name = %s, rank 7, Bank = %d + %d, Faction id = %d, Bank = %d - %d",
								gPlayerData[i][pName], gPlayerData[i][pBank], PayRank[n][Rank2], gPlayerData[i][pFaction], DynamicFactions[gPlayerData[i][pFaction]][fBank], PayRank[n][Rank2]);
							gPlayerData[i][pBank] += PayRank[n][Rank7];
							DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank7];
						}
						case 8:
						{
							format(string, sizeof(string), "[PAYDAY:] Player name = %s, rank 8, Bank = %d + %d, Faction id = %d, Bank = %d - %d",
								gPlayerData[i][pName], gPlayerData[i][pBank], PayRank[n][Rank2], gPlayerData[i][pFaction], DynamicFactions[gPlayerData[i][pFaction]][fBank], PayRank[n][Rank2]);
							gPlayerData[i][pBank] += PayRank[n][Rank8];
							DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank8];
						}
						case 9:
						{
							format(string, sizeof(string), "[PAYDAY:] Player name = %s, rank 9, Bank = %d + %d, Faction id = %d, Bank = %d - %d",
								gPlayerData[i][pName], gPlayerData[i][pBank], PayRank[n][Rank2], gPlayerData[i][pFaction], DynamicFactions[gPlayerData[i][pFaction]][fBank], PayRank[n][Rank2]);
							gPlayerData[i][pBank] += PayRank[n][Rank9];
							DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank9];
						}
						case 10:
						{
							format(string, sizeof(string), "[PAYDAY:] Player name = %s, rank 10, Bank = %d + %d, Faction id = %d, Bank = %d - %d",
								gPlayerData[i][pName], gPlayerData[i][pBank], PayRank[n][Rank2], gPlayerData[i][pFaction], DynamicFactions[gPlayerData[i][pFaction]][fBank], PayRank[n][Rank2]);
							gPlayerData[i][pBank] += PayRank[n][Rank10];
							DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank10];
						}
					}
					PayDayLog(string);
					SaveFData(gPlayerData[i][pFaction], "Bank");
					break;
				}
			}
		}
		if(gPlayerData[i][pJob] == 0 && gPlayerData[i][pFaction] == 255)
		{
			gPlayerData[i][pBank] += Zasilek;
			format(string, sizeof(string), "[PAYDAY:] Player name = %s, Bank = %d + %d", gPlayerData[i][pName], gPlayerData[i][pBank], Zasilek); 
			PayDayLog(string);
			
			DynamicFactions[FACTIONID_GOVERNMENT][fBank] -= Zasilek;
			SaveFData(FACTIONID_GOVERNMENT, "Bank");
		}	
		
		/*
		* Credit repayment
		*/
		if(gPlayerData[i][mCreditValue] > 0)
		{
			gPlayerData[i][pBank] -= gPlayerData[i][mCreditRepayment];
			gPlayerData[i][mCreditPayed] += gPlayerData[i][mCreditRepayment];
			DynamicFactions[FACTIONID_GOVERNMENT][fBank] += gPlayerData[i][mCreditRepayment];
			SaveFData(FACTIONID_GOVERNMENT, "Bank");
			if(gPlayerData[i][mCreditPayed] >= gPlayerData[i][mCreditValue])
			{
				gPlayerData[i][mCreditRepayment] = 0;
				gPlayerData[i][mCreditPayed] = 0;
				gPlayerData[i][mCreditValue] = 0;
				SavePlayerData(i, "CreditRepayment");
				SavePlayerData(i, "CreditValue");
			}
			SavePlayerData(i, "CreditPayed");
		}
		
		/*
		* Pay taxes, costs, tickets, etc.
		*/
		gPlayerData[i][pBank] -= DynamicTaxes[RadioTax];
		DynamicFactions[FACTIONID_GOVERNMENT][fBank] += DynamicTaxes[RadioTax];
		if((gPlayerData[i][pCash] + gPlayerData[i][pBank]) >= DynamicTaxes[TheRich])
		{
			gPlayerData[i][pBank] -= floatround(DynamicTaxes[RichTax] * (gPlayerData[i][pBank]+gPlayerData[i][pCash]), floatround_round);
			format(string, sizeof(string), "[PAYDAY:] PlayerName = %s, Bank = %d - %d, SOURCE = taxes (the rich)", gPlayerData[i][pName], gPlayerData[i][pBank], DynamicTaxes[TheRich]); 
			PayDayLog(string);
			
			DynamicFactions[FACTIONID_GOVERNMENT][fBank] += DynamicTaxes[TheRich];
		}
		if(gPlayerData[i][pCost] > 0)
		{
			gPlayerData[i][pBank] -= gPlayerData[i][pCost];
			format(string, sizeof(string), "[PAYDAY:] PlayerName = %s, Bank = %d - %d, SOURCE = costs", gPlayerData[i][pName], gPlayerData[i][pBank], gPlayerData[i][pCost]); 
			PayDayLog(string);
			
			gPlayerData[i][pCost] = 0;
			SavePlayerData(i, "Cost");
		}
		if(gPlayerData[i][pTicket] > 0)
		{
			gPlayerData[i][pBank] -= gPlayerData[i][pTicket];
			format(string, sizeof(string), "[PAYDAY:] PlayerName = %s, Bank = %d - %d, SOURCE = ticket", gPlayerData[i][pName], gPlayerData[i][pBank], gPlayerData[i][pTicket]); 
			PayDayLog(string);
			
			DynamicFactions[FACTIONID_POLICE][fBank] += gPlayerData[i][pTicket];
			SaveFData(FACTIONID_POLICE, "Bank");
			gPlayerData[i][pTicket] = 0;
			SavePlayerData(i, "Ticket");
		}
		
		/*
		* Other stuff
		*/
		if(gPlayerData[i][pJobTimeChange] > 0)
		{
			gPlayerData[i][pJobTimeChange]--;
			SavePlayerData(i, "JobTimeChange");
		}
		SaveFData(FACTIONID_GOVERNMENT, "Bank");
		printf("[PAYDAY:] Logged player [%d] passed", i);
	}
	
	// DATABASE SAVE =================================================================================================
	PayDayLog("[PAYDAY:] Counting...");
	format(string, sizeof(string), "SELECT COUNT(*) FROM `samp_users` WHERE `Banned` = '0' ");
	mysql_query(string, COUNT_PAYDAY, INVALID_PLAYER_ID, db_con2);
	//SetTimer("PayDay",86400000,0); // sprawdza czy jest dana godzina, wyplaca pieniadze wszystkim graczom
	return 1;
}