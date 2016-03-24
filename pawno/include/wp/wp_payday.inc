PayDay()
{
	new wstring[256];
	format(wstring, sizeof(wstring), "[TIMERCHECK:] PayDay()");
	printf("%s", wstring);
	PayDayLog(wstring);
	new Float:px, Float:py, Float:pz;
	new Float:emmision; // vehicle co2 emmision
	RafineryResourcesIncrease();
	
	WFactoryLegalLight[WFactory9MM] += 2;
	WFactoryLegalLight[WFactory9MMAmmo] += 34;
	SaveWFactoryData( "WFactory9MM" );
	SaveWFactoryData( "WFactory9MMAmmo" );
	
	/*
	* Taxes from vehicles
	*/
	for( new i = 0; i < sizeof(gVehData); i++ )
	{
		if( ( strcmp(gVehData[i][Owner], "None", true) == 0 || strlen(gVehData[i][Owner]) < 0 ||
			strfind(gVehData[i][Owner], "_", true) == -1 ) && gVehData[i][FactionCar] == 255 )
		{
			continue;
		}
		if( gVehData[i][FactionCar] == 255 )
		{
			/*
			* Tax from engine capacity
			*/
			if( IsAMotorBike(i+1) )
				UpdatePlayerDataByName(gVehData[i][Owner], "Bank", -1);
			else if( IsAOffroadCar(i+1) )
				UpdatePlayerDataByName(gVehData[i][Owner], "Bank", -4);
			else if( IsASportsCar(i+1) )
				UpdatePlayerDataByName(gVehData[i][Owner], "Bank", -6);
			else if( IsAHardTruck(i+1) )
				UpdatePlayerDataByName(gVehData[i][Owner], "Bank", -8);
			else 
				UpdatePlayerDataByName(gVehData[i][Owner], "Bank", -2);
			
			/*
			* Tax from CO2 emmision
			*/
			VehCo2Emmision(i+1, emmision);
			if( emmision >= 0.01 && emmision <= 0.207 )
				UpdatePlayerDataByName(gVehData[i][Owner], "Bank", -2);
			else if( emmision > 0.207 && emmision <= 0.437 )
				UpdatePlayerDataByName(gVehData[i][Owner], "Bank", -3);
			else if( emmision > 0.437 && emmision <= 0.667 )
				UpdatePlayerDataByName(gVehData[i][Owner], "Bank", -5);
			else if( emmision > 0.667 && emmision <= 0.897 )
				UpdatePlayerDataByName(gVehData[i][Owner], "Bank", -7);
			else if( emmision > 0.897 )
				UpdatePlayerDataByName(gVehData[i][Owner], "Bank", -9);
		}
		else
		{
			/*
			* Tax from engine capacity
			*/
			if( IsAMotorBike(i+1) )
			{
				DynamicFactions[gVehData[i][FactionCar]][fBank] -= 1;
				SaveFData(gVehData[i][FactionCar], "Bank");
			}
			else if( IsAOffroadCar(i+1) )
			{
				DynamicFactions[gVehData[i][FactionCar]][fBank] -= 4;
				SaveFData(gVehData[i][FactionCar], "Bank");
			}
			else if( IsASportsCar(i+1) )
			{
				DynamicFactions[gVehData[i][FactionCar]][fBank] -= 6;
				SaveFData(gVehData[i][FactionCar], "Bank");
			}
			else if( IsAHardTruck(i+1) )
			{
				DynamicFactions[gVehData[i][FactionCar]][fBank] -= 8;
				SaveFData(gVehData[i][FactionCar], "Bank");
			}
			else
			{
				DynamicFactions[gVehData[i][FactionCar]][fBank] -= 2;
				SaveFData(gVehData[i][FactionCar], "Bank");
			}
			
			/*
			* Tax from CO2 emmision
			*/
			VehCo2Emmision(i+1, emmision);
			if( emmision >= 0.01 && emmision <= 0.207 )
			{
				DynamicFactions[gVehData[i][FactionCar]][fBank] -= 2;
				SaveFData(gVehData[i][FactionCar], "Bank");
			}
			else if( emmision > 0.207 && emmision <= 0.437 )
			{
				DynamicFactions[gVehData[i][FactionCar]][fBank] -= 3;
				SaveFData(gVehData[i][FactionCar], "Bank");
			}
			else if( emmision > 0.437 && emmision <= 0.667 )
			{
				DynamicFactions[gVehData[i][FactionCar]][fBank] -= 5;
				SaveFData(gVehData[i][FactionCar], "Bank");
			}
			else if( emmision > 0.667 && emmision <= 0.897 )
			{
				DynamicFactions[gVehData[i][FactionCar]][fBank] -= 7;
				SaveFData(gVehData[i][FactionCar], "Bank");
			}
			else if( emmision > 0.897 )
			{
				DynamicFactions[gVehData[i][FactionCar]][fBank] -= 9;
				SaveFData(gVehData[i][FactionCar], "Bank");
			}
		}	
	}
	
	/*
	* Builds illegal factory
	*/
	for( new i = 0; i < sizeof(DynamicFactions); i++ ) 
	{
		if( DynamicFactions[i][WFactoryJustBought] )
		{
			px = DynamicFactions[i][WFactoryCentrePosX];
			py = DynamicFactions[i][WFactoryCentrePosY];
			pz = DynamicFactions[i][WFactoryCentrePosZ];
			DynamicFactions[i][WFactoryObjects][0] = CreateDynamicObject( 18267, px, py, pz, 0.0, 0.0, 0.0 );
			DynamicFactions[i][WFactoryObjects][1] = CreateDynamicObject( 2061, px+WFObj[0][0], py+WFObj[0][1], pz+WFObj[0][2], WFObj[0][3], WFObj[0][4], WFObj[0][5] );	
			DynamicFactions[i][WFactoryObjects][2] = CreateDynamicObject( 1212 , px+WFObj[1][0], py+WFObj[1][1], pz+WFObj[1][2], WFObj[1][3], WFObj[1][4], WFObj[1][5] );	
			DynamicFactions[i][WFactoryObjects][3] = CreateDynamicObject( 1550, px+WFObj[2][0], py+WFObj[2][1], pz+WFObj[2][2], WFObj[2][3], WFObj[2][4], WFObj[2][5] );	
			DynamicFactions[i][WFactoryObjects][4] = CreateDynamicObject( 1550, px+WFObj[3][0], py+WFObj[3][1], pz+WFObj[3][2], WFObj[3][3], WFObj[3][4], WFObj[3][5] );	
			DynamicFactions[i][WFactoryObjects][5] = CreateDynamicObject( 1650, px+WFObj[4][0], py+WFObj[4][1], pz+WFObj[4][2], WFObj[4][3], WFObj[4][4], WFObj[4][5] );	
			DynamicFactions[i][WFactoryObjects][6] = CreateDynamicObject( 2035, px+WFObj[5][0], py+WFObj[5][1], pz+WFObj[5][2], WFObj[5][3], WFObj[5][4], WFObj[5][5] );	
			DynamicFactions[i][WFactoryObjects][7] = CreateDynamicObject( 2036, px+WFObj[6][0], py+WFObj[6][1], pz+WFObj[6][2], WFObj[6][3],WFObj[6][4], WFObj[6][5] );	
			DynamicFactions[i][WFactoryObjects][8] = CreateDynamicObject( 2037, px+WFObj[7][0], py+WFObj[7][1], pz+WFObj[7][2], WFObj[7][3], WFObj[7][4], WFObj[7][5] );	
			DynamicFactions[i][WFactoryObjects][9] = CreateDynamicObject( 2044, px+WFObj[8][0], py+WFObj[8][1], pz+WFObj[8][2], WFObj[8][3], WFObj[8][4], WFObj[8][5] );	
			DynamicFactions[i][WFactoryObjects][10] = CreateDynamicObject( 2057, px+WFObj[9][0], py+WFObj[9][1], pz+WFObj[9][2], WFObj[9][3], WFObj[9][4], WFObj[9][5] );	
			DynamicFactions[i][WFactoryObjects][11] = CreateDynamicObject( 2059, px+WFObj[10][0], py+WFObj[10][1], pz+WFObj[10][2], WFObj[10][3], WFObj[10][4], WFObj[10][5] );	
			DynamicFactions[i][WFactoryObjects][12] = CreateDynamicObject( 3387, px+WFObj[11][0], py+WFObj[11][1], pz+WFObj[11][2], WFObj[11][3], WFObj[11][4], WFObj[11][5] );	
			DynamicFactions[i][WFactoryObjects][13] = CreateDynamicObject( 3389, px+WFObj[12][0], py+WFObj[12][1], pz+WFObj[12][2], WFObj[12][3], WFObj[12][4], WFObj[12][5] );	
			DynamicFactions[i][WFactoryObjects][14] = CreateDynamicObject( 3391 , px+WFObj[13][0], py+WFObj[13][1], pz+WFObj[13][2], WFObj[13][3], WFObj[13][4], WFObj[13][5] );	
			DynamicFactions[i][WFactoryObjects][15] = CreateDynamicObject( 3396 , px+WFObj[14][0], py+WFObj[14][1], pz+WFObj[14][2], WFObj[14][3], WFObj[14][4], WFObj[14][5] );	
			DynamicFactions[i][WFactoryObjects][16] = CreateDynamicObject( 3787 , px+WFObj[15][0], py+WFObj[15][1], pz+WFObj[15][2], WFObj[15][3], WFObj[15][4], WFObj[15][5] );	
			DynamicFactions[i][WFactoryObjects][17] = CreateDynamicObject( 1222 , px+WFObj[16][0], py+WFObj[16][1], pz+WFObj[16][2], WFObj[16][3], WFObj[16][4], WFObj[16][5] );	
			DynamicFactions[i][WFactoryObjects][18] = CreateDynamicObject( 939 , px+WFObj[17][0], py+WFObj[17][1], pz+WFObj[17][2], WFObj[17][3], WFObj[17][4], WFObj[17][5] );	
			DynamicFactions[i][WFactoryObjects][19] = CreateDynamicObject( 2333 , px+WFObj[18][0], py+WFObj[18][1], pz+WFObj[18][2], WFObj[18][3], WFObj[18][4], WFObj[18][5] );	
			DynamicFactions[i][WFactoryObjects][20] = CreateDynamicObject( 1212 , px+WFObj[19][0], py+WFObj[19][1], pz+WFObj[19][2], WFObj[19][3], WFObj[19][4], WFObj[19][5] );	
			DynamicFactions[i][WFactoryObjects][21] = CreateDynamicObject( 1212 , px+WFObj[20][0], py+WFObj[20][1], pz+WFObj[20][2], WFObj[20][3], WFObj[20][4], WFObj[20][5] );	
			DynamicFactions[i][WFactoryObjects][22] = CreateDynamicObject( 1212 , px+WFObj[21][0], py+WFObj[21][1], pz+WFObj[21][2], WFObj[21][3], WFObj[21][4], WFObj[21][5] );	
			DynamicFactions[i][WFactoryObjects][23] = CreateDynamicObject( 2186 , px+WFObj[22][0], py+WFObj[22][1], pz+WFObj[22][2], WFObj[22][3], WFObj[22][4], WFObj[22][5] );	
			DynamicFactions[i][WFactoryObjects][24] = CreateDynamicObject( 1829 , px+WFObj[23][0], py+WFObj[23][1], pz+WFObj[23][2], WFObj[23][3], WFObj[23][4], WFObj[23][5] );	
			DynamicFactions[i][WFactoryObjects][25] = CreateDynamicObject( 1728 , px+WFObj[24][0], py+WFObj[24][1], pz+WFObj[24][2], WFObj[24][3], WFObj[24][4], WFObj[24][5] );	
			DynamicFactions[i][WFactoryObjects][26] = CreateDynamicObject( 2037 , px+WFObj[25][0], py+WFObj[25][1], pz+WFObj[25][2], WFObj[25][3], WFObj[25][4], WFObj[25][5] );	
			DynamicFactions[i][WFactoryObjects][27] = CreateDynamicObject( 2037 , px+WFObj[26][0], py+WFObj[26][1], pz+WFObj[26][2], WFObj[26][3], WFObj[26][4], WFObj[26][5] );	
			DynamicFactions[i][WFactoryObjects][28] = CreateDynamicObject( 2037 , px+WFObj[27][0], py+WFObj[27][1], pz+WFObj[27][2], WFObj[27][3], WFObj[27][4], WFObj[27][5] );	
			DynamicFactions[i][WFactoryObjects][29] = CreateDynamicObject( 2044 , px+WFObj[28][0], py+WFObj[28][1], pz+WFObj[28][2], WFObj[28][3], WFObj[28][4], WFObj[28][5] );	
			DynamicFactions[i][WFactoryObjects][30] = CreateDynamicObject( 18725 , px+WFObj[29][0], py+WFObj[29][1], pz+WFObj[29][2], WFObj[29][3], WFObj[29][4], WFObj[29][5] ); // DYM	
			// DynamicFactions[i][WFactoryObjects][31] = CreateDynamicObject( 18693 , px+WFObj[30][0], py+WFObj[30][1], pz+WFObj[30][2], WFObj[30][3], WFObj[30][4], WFObj[30][5] );
			DynamicFactions[i][WFactoryCPPartSetup1ID] = CreateDynamicCP( px+WFCP[0][0], py+WFCP[0][1], pz+WFCP[0][2], 2.0 ); // Make weapon parts
			DynamicFactions[i][WFactoryCPPartSetup2ID] = CreateDynamicCP( px+WFCP[1][0], py+WFCP[1][1], pz+WFCP[1][2], 2.0 ); // Make weapon parts
			DynamicFactions[i][WFactoryCPAmmoPartSetup1ID] = CreateDynamicCP( px+WFCP[2][0], py+WFCP[2][1], pz+WFCP[2][2], 2.0 ); // Make weapon subparts
			DynamicFactions[i][WFactoryCPPartTakeID] = CreateDynamicCP( px+WFCP[3][0], py+WFCP[3][1], pz+WFCP[3][2], 2.0 ); // Take/buy ammo/weapon (sub) parts
			DynamicFactions[i][WFactoryCPAmmoPartSetup2ID] = CreateDynamicCP( px+WFCP[4][0], py+WFCP[4][1], pz+WFCP[4][2], 2.0 ); // Make weapon subparts
			DynamicFactions[i][WFactoryEnabled] = 1;
			DynamicFactions[i][WFactoryJustBought] = 0;
			SaveFData( i, "WFactoryJustBought" );
			SaveFData( i, "WFactoryEnabled" );
		}
	}
	
	for( new i = 0; i < CUSTOM_MAX_PLAYERS; i++)
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
				if( PayRank[n][FactionID] == gPlayerData[i][pFaction] )
				{
					switch( gPlayerData[i][pRank] )
					{
						case 1: { gPlayerData[i][pBank] += PayRank[n][Rank1]; DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank1]; }
						case 2: { gPlayerData[i][pBank] += PayRank[n][Rank2]; DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank2]; }
						case 3: { gPlayerData[i][pBank] += PayRank[n][Rank3]; DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank3]; }
						case 4: { gPlayerData[i][pBank] += PayRank[n][Rank4]; DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank4]; }
						case 5: { gPlayerData[i][pBank] += PayRank[n][Rank5]; DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank5]; }
						case 6: { gPlayerData[i][pBank] += PayRank[n][Rank6]; DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank6]; }
						case 7: { gPlayerData[i][pBank] += PayRank[n][Rank7]; DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank7]; }
						case 8: { gPlayerData[i][pBank] += PayRank[n][Rank8]; DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank8]; }
						case 9: { gPlayerData[i][pBank] += PayRank[n][Rank9]; DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank9]; }
						case 10: { gPlayerData[i][pBank] += PayRank[n][Rank10]; DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank10]; }
					}
					SaveFData( gPlayerData[i][pFaction], "Bank" );
					break;
				}
			}
		}
		if( gPlayerData[i][pJob] == 0 && gPlayerData[i][pFaction] == 255 )
		{
			gPlayerData[i][pBank] += Zasilek;
			printf("[PAYDAY:] Player name = %s, Bank = %d + %d", gPlayerData[i][pName], gPlayerData[i][pBank], Zasilek); 
			DynamicFactions[FACTIONID_GOVERNMENT][fBank] -= Zasilek;
			SaveFData( FACTIONID_GOVERNMENT, "Bank" );
		}	
		
		/*
		* Pay taxes, costs, tickets, etc.
		*/
		gPlayerData[i][pBank] -= DynamicTaxes[RadioTax];
		DynamicFactions[FACTIONID_GOVERNMENT][fBank] += DynamicTaxes[RadioTax];
		if( ( gPlayerData[i][pCash] + gPlayerData[i][pBank] ) >= DynamicTaxes[TheRich] )
		{
			gPlayerData[i][pBank] -= floatround( DynamicTaxes[RichTax] * (gPlayerData[i][pBank]+gPlayerData[i][pCash]), floatround_round);
			printf("[PAYDAY:] PlayerName = %s, Bank = %d - %d, SOURCE = taxes (the rich)", gPlayerData[i][pName], gPlayerData[i][pBank], DynamicTaxes[TheRich]); 
			DynamicFactions[FACTIONID_GOVERNMENT][fBank] += DynamicTaxes[TheRich];
		}
		if( gPlayerData[i][pCost] > 0 )
		{
			gPlayerData[i][pBank] -= gPlayerData[i][pCost];
			printf("[PAYDAY:] PlayerName = %s, Bank = %d - %d, SOURCE = costs", gPlayerData[i][pName], gPlayerData[i][pBank], gPlayerData[i][pCost]); 
			gPlayerData[i][pCost] = 0;
			SavePlayerData( i, "Cost" );
		}
		if( gPlayerData[i][pTicket] > 0 )
		{
			gPlayerData[i][pBank] -= gPlayerData[i][pTicket];
			printf("[PAYDAY:] PlayerName = %s, Bank = %d - %d, SOURCE = ticket", gPlayerData[i][pName], gPlayerData[i][pBank], gPlayerData[i][pTicket]); 
			DynamicFactions[FACTIONID_POLICE][fBank] += gPlayerData[i][pTicket];
			SaveFData( FACTIONID_POLICE, "Bank" );
			gPlayerData[i][pTicket] = 0;
			SavePlayerData( i, "Ticket" );
		}
		if( gPlayerData[i][pBizKey] != 255 )
		{
			gPlayerData[i][pBank] -= floatround( Businesses[ gPlayerData[i][pBizKey] ][BizPrice] * DynamicTaxes[BusinessTax], floatround_round );
			printf("[PAYDAY:] PlayerName = %s, Bank = %d - %d, SOURCE = taxes (business)", gPlayerData[i][pName], gPlayerData[i][pBank], floatround( Businesses[ gPlayerData[i][pBizKey] ][BizPrice] * DynamicTaxes[BusinessTax], floatround_round ) ); 
			DynamicFactions[FACTIONID_GOVERNMENT][fBank] += floatround( Businesses[ gPlayerData[i][pBizKey] ][BizPrice] * DynamicTaxes[BusinessTax], floatround_round );
		}
		
		/*
		* Ensurance for vehicles
		*/
		if( gPlayerData[i][pItem1type] == 2 && gPlayerData[i][pItem1] != 0 )
		{
			switch( gPlayerData[i][pItem1param] )
			{
				case 1: gPlayerData[i][pBank] -= 200;
				case 2: gPlayerData[i][pBank] -= 400;
				case 3: gPlayerData[i][pBank] -= 1000;
			}
		}
		if( gPlayerData[i][pItem2type] == 2 && gPlayerData[i][pItem2] != 0 )
		{
			switch( gPlayerData[i][pItem2param] )
			{
				case 1: gPlayerData[i][pBank] -= 200;
				case 2: gPlayerData[i][pBank] -= 400;
				case 3: gPlayerData[i][pBank] -= 1000;
			}
		}
		if( gPlayerData[i][pItem3type] == 2 && gPlayerData[i][pItem3] != 0 )
		{
			switch( gPlayerData[i][pItem3param] )
			{
				case 1: gPlayerData[i][pBank] -= 200;
				case 2: gPlayerData[i][pBank] -= 400;
				case 3: gPlayerData[i][pBank] -= 1000;
			}
		}
		if( gPlayerData[i][pItem4type] == 2 && gPlayerData[i][pItem4] != 0 )
		{
			switch( gPlayerData[i][pItem4param] )
			{
				case 1: gPlayerData[i][pBank] -= 200;
				case 2: gPlayerData[i][pBank] -= 400;
				case 3: gPlayerData[i][pBank] -= 1000;
			}
		}
		if( gPlayerData[i][pItem5type] == 2 && gPlayerData[i][pItem5] != 0 )
		{
			switch( gPlayerData[i][pItem5param] )
			{
				case 1: gPlayerData[i][pBank] -= 200;
				case 2: gPlayerData[i][pBank] -= 400;
				case 3: gPlayerData[i][pBank] -= 1000;
			}
		}
		if( PHaveExpandItem(i) || gPlayerData[i][pVipItem] > 0 )
		{
			if( gPlayerData[i][pItem6type] == 2 && gPlayerData[i][pItem6] != 0 )
			{
				switch( gPlayerData[i][pItem6param] )
				{
					case 1: gPlayerData[i][pBank] -= 200;
					case 2: gPlayerData[i][pBank] -= 400;
					case 3: gPlayerData[i][pBank] -= 1000;
				}
			}
			if( gPlayerData[i][pItem7type] == 2 && gPlayerData[i][pItem7] != 0 )
			{
				switch( gPlayerData[i][pItem7param] )
				{
					case 1: gPlayerData[i][pBank] -= 200;
					case 2: gPlayerData[i][pBank] -= 400;
					case 3: gPlayerData[i][pBank] -= 1000;
				}
			}
			if( gPlayerData[i][pItem8type] == 2 && gPlayerData[i][pItem8] != 0 )
			{
				switch( gPlayerData[i][pItem8param] )
				{
					case 1: gPlayerData[i][pBank] -= 200;
					case 2: gPlayerData[i][pBank] -= 400;
					case 3: gPlayerData[i][pBank] -= 1000;
				}
			}
			if( gPlayerData[i][pItem9type] == 2 && gPlayerData[i][pItem9] != 0 )
			{
				switch( gPlayerData[i][pItem9param] )
				{
					case 1: gPlayerData[i][pBank] -= 200;
					case 2: gPlayerData[i][pBank] -= 400;
					case 3: gPlayerData[i][pBank] -= 1000;
				}
			}
			if( gPlayerData[i][pItem10type] == 2 && gPlayerData[i][pItem10] != 0 )
			{
				switch( gPlayerData[i][pItem10param] )
				{
					case 1: gPlayerData[i][pBank] -= 200;
					case 2: gPlayerData[i][pBank] -= 400;
					case 3: gPlayerData[i][pBank] -= 1000;
				}
			}
			if( gPlayerData[i][pVipItem] > 0 )
			{
				if( gPlayerData[i][pItem11type] == 2 && gPlayerData[i][pItem11] != 0 )
				{
					switch( gPlayerData[i][pItem11param] )
					{
						case 1: gPlayerData[i][pBank] -= 200;
						case 2: gPlayerData[i][pBank] -= 400;
						case 3: gPlayerData[i][pBank] -= 1000;
					}
				}
				if( gPlayerData[i][pItem12type] == 2 && gPlayerData[i][pItem12] != 0 )
				{
					switch( gPlayerData[i][pItem12param] )
					{
						case 1: gPlayerData[i][pBank] -= 200;
						case 2: gPlayerData[i][pBank] -= 400;
						case 3: gPlayerData[i][pBank] -= 1000;
					}
				}
				if( gPlayerData[i][pItem13type] == 2 && gPlayerData[i][pItem13] != 0 )
				{
					switch( gPlayerData[i][pItem13param] )
					{
						case 1: gPlayerData[i][pBank] -= 200;
						case 2: gPlayerData[i][pBank] -= 400;
						case 3: gPlayerData[i][pBank] -= 1000;
					}
				}
				if( gPlayerData[i][pItem14type] == 2 && gPlayerData[i][pItem14] != 0 )
				{
					switch( gPlayerData[i][pItem14param] )
					{
						case 1: gPlayerData[i][pBank] -= 200;
						case 2: gPlayerData[i][pBank] -= 400;
						case 3: gPlayerData[i][pBank] -= 1000;
					}
				}
				if( gPlayerData[i][pItem15type] == 2 && gPlayerData[i][pItem15] != 0 )
				{
					switch( gPlayerData[i][pItem15param] )
					{
						case 1: gPlayerData[i][pBank] -= 200;
						case 2: gPlayerData[i][pBank] -= 400;
						case 3: gPlayerData[i][pBank] -= 1000;
					}
				}
			}
		}
		
		if( gPlayerData[i][pItem1type] == 2 && gPlayerData[i][pItem1] != 0 )
		{
			switch( gPlayerData[i][pItem1param2] )
			{
				case 1: gPlayerData[i][pBank] -= 200;
				case 2: gPlayerData[i][pBank] -= 400;
				case 3: gPlayerData[i][pBank] -= 1000;
			}
		}
		if( gPlayerData[i][pItem2type] == 2 && gPlayerData[i][pItem2] != 0 )
		{
			switch( gPlayerData[i][pItem2param2] )
			{
				case 1: gPlayerData[i][pBank] -= 200;
				case 2: gPlayerData[i][pBank] -= 400;
				case 3: gPlayerData[i][pBank] -= 1000;
			}
		}
		if( gPlayerData[i][pItem3type] == 2 && gPlayerData[i][pItem3] != 0 )
		{
			switch( gPlayerData[i][pItem3param2] )
			{
				case 1: gPlayerData[i][pBank] -= 200;
				case 2: gPlayerData[i][pBank] -= 400;
				case 3: gPlayerData[i][pBank] -= 1000;
			}
		}
		if( gPlayerData[i][pItem4type] == 2 && gPlayerData[i][pItem4] != 0 )
		{
			switch( gPlayerData[i][pItem4param2] )
			{
				case 1: gPlayerData[i][pBank] -= 200;
				case 2: gPlayerData[i][pBank] -= 400;
				case 3: gPlayerData[i][pBank] -= 1000;
			}
		}
		if( gPlayerData[i][pItem5type] == 2 && gPlayerData[i][pItem5] != 0 )
		{
			switch( gPlayerData[i][pItem5param2] )
			{
				case 1: gPlayerData[i][pBank] -= 200;
				case 2: gPlayerData[i][pBank] -= 400;
				case 3: gPlayerData[i][pBank] -= 1000;
			}
		}
		if( PHaveExpandItem(i) || gPlayerData[i][pVipItem] > 0 )
		{
			if( gPlayerData[i][pItem6type] == 2 && gPlayerData[i][pItem6] != 0 )
			{
				switch( gPlayerData[i][pItem6param2] )
				{
					case 1: gPlayerData[i][pBank] -= 200;
					case 2: gPlayerData[i][pBank] -= 400;
					case 3: gPlayerData[i][pBank] -= 1000;
				}
			}
			if( gPlayerData[i][pItem7type] == 2 && gPlayerData[i][pItem7] != 0 )
			{
				switch( gPlayerData[i][pItem7param2] )
				{
					case 1: gPlayerData[i][pBank] -= 200;
					case 2: gPlayerData[i][pBank] -= 400;
					case 3: gPlayerData[i][pBank] -= 1000;
				}
			}
			if( gPlayerData[i][pItem8type] == 2 && gPlayerData[i][pItem8] != 0 )
			{
				switch( gPlayerData[i][pItem8param2] )
				{
					case 1: gPlayerData[i][pBank] -= 200;
					case 2: gPlayerData[i][pBank] -= 400;
					case 3: gPlayerData[i][pBank] -= 1000;
				}
			}
			if( gPlayerData[i][pItem9type] == 2 && gPlayerData[i][pItem9] != 0 )
			{
				switch( gPlayerData[i][pItem9param2] )
				{
					case 1: gPlayerData[i][pBank] -= 200;
					case 2: gPlayerData[i][pBank] -= 400;
					case 3: gPlayerData[i][pBank] -= 1000;
				}
			}
			if( gPlayerData[i][pItem10type] == 2 && gPlayerData[i][pItem10] != 0 )
			{
				switch( gPlayerData[i][pItem10param2] )
				{
					case 1: gPlayerData[i][pBank] -= 200;
					case 2: gPlayerData[i][pBank] -= 400;
					case 3: gPlayerData[i][pBank] -= 1000;
				}
			}
			if( gPlayerData[i][pVipItem] > 0 )
			{
				if( gPlayerData[i][pItem11type] == 2 && gPlayerData[i][pItem11] != 0 )
				{
					switch( gPlayerData[i][pItem11param2] )
					{
						case 1: gPlayerData[i][pBank] -= 200;
						case 2: gPlayerData[i][pBank] -= 400;
						case 3: gPlayerData[i][pBank] -= 1000;
					}
				}
				if( gPlayerData[i][pItem12type] == 2 && gPlayerData[i][pItem12] != 0 )
				{
					switch( gPlayerData[i][pItem12param2] )
					{
						case 1: gPlayerData[i][pBank] -= 200;
						case 2: gPlayerData[i][pBank] -= 400;
						case 3: gPlayerData[i][pBank] -= 1000;
					}
				}
				if( gPlayerData[i][pItem13type] == 2 && gPlayerData[i][pItem13] != 0 )
				{
					switch( gPlayerData[i][pItem13param2] )
					{
						case 1: gPlayerData[i][pBank] -= 200;
						case 2: gPlayerData[i][pBank] -= 400;
						case 3: gPlayerData[i][pBank] -= 1000;
					}
				}
				if( gPlayerData[i][pItem14type] == 2 && gPlayerData[i][pItem14] != 0 )
				{
					switch( gPlayerData[i][pItem14param2] )
					{
						case 1: gPlayerData[i][pBank] -= 200;
						case 2: gPlayerData[i][pBank] -= 400;
						case 3: gPlayerData[i][pBank] -= 1000;
					}
				}
				if( gPlayerData[i][pItem15type] == 2 && gPlayerData[i][pItem15] != 0 )
				{
					switch( gPlayerData[i][pItem15param2] )
					{
						case 1: gPlayerData[i][pBank] -= 200;
						case 2: gPlayerData[i][pBank] -= 400;
						case 3: gPlayerData[i][pBank] -= 1000;
					}
				}
			}
		}
		
		/*
		* Calculate and update player RP score
		*/
		gPlayerData[i][pScore] = ( gPlayerData[i][pRPCount] * 2 ) - ( gPlayerData[i][pDeathCount] * 100 ) + floatround( (gPlayerData[i][pHoursOnDuty]/5), floatround_round );
		SavePlayerData( i, "Score" );
		
		/*
		* VIP reduce
		*/
		if( gVipReduceOn )
		{
			if( gPlayerData[i][pVipAFKT] > 0 )
			{
				gPlayerData[i][pVipAFKT]--;
				SavePlayerData( i, "VipAFKT" );
			}
			if( gPlayerData[i][pVipExpT] > 0 )
			{
				gPlayerData[i][pVipExpT]--;
				SavePlayerData( i, "VipExpT" );
			}
			if( gPlayerData[i][pVipItem] > 0 )
			{
				gPlayerData[i][pVipItem]--;
				SavePlayerData( i, "VipItem" );
			}
		}
		
		/*
		* Other stuff
		*/
		if( gPlayerData[i][pJobTimeChange] > 0 )
		{
			gPlayerData[i][pJobTimeChange]--;
			SavePlayerData( i, "JobTimeChange" );
		}
		SaveFData( FACTIONID_GOVERNMENT, "Bank" );
		SavePlayerData( i, "Bank" );
		printf( "[PAYDAY:] Logged player [%d] passed", i );
		//=====================================================================

		// SendClientMessage(i,COLOR_YELLOW,"____________________________________________________");
		// SendClientMessage(i,COLOR_LIGHTYELLOW2,"                                    Dzieñ Wyp³at:                       ");
		// format(wstring, sizeof(wstring), "~y~Dzien Wyplat~n~~w~Wyplata: ~g~%d",randcheck + bonus);
		// GameTextForPlayer(i, wstring, 5000, 1);
		// format(wstring, sizeof(wstring), "Dzieñ Wyp³at: $%d, Bonus: $%d.", randcheck, bonus);
		// SendClientMessage(i,COLOR_LIGHTYELLOW2, wstring);
		// format(wstring, sizeof(wstring), "Stan konta: $%d, Zdobyte odsetki: $%d, Zakupy: $-%d, Nowy stan konta: $%d, Stopa procentowa: %f procent.", gPlayerData[i][pBank], interest, costs, newbank, intrate);
		// format(wstring, sizeof(wstring), "Stan konta: $%d, Zdobyte odsetki: $%d, Zakupy: $-%d, Nowy stan konta: $%d", gPlayerData[i][pBank], interest, costs, newbank);
		// SendClientMessage(i,COLOR_LIGHTYELLOW2, wstring);
		// format(wstring, sizeof(wstring), "Podatki: $%d, Mandaty: $%d", taxes, ticket);
		// SendClientMessage(i,COLOR_LIGHTYELLOW2, wstring);
		
		// gPlayerData[i][pBank] += interest;
		// gPlayerData[i][pBank] -= taxes;
		// gPlayerData[i][pBank] += randcheck + bonus;
		// gPlayerData[i][pPayCheck] = 0;
		// gPlayerData[i][pAllowedPayday] = 0;
		// gPlayerData[i][pTicket] = 0;
		// gPlayerData[i][pCost] = 0;
		
		// SavePlayerData(i, "Bank");
		// SavePlayerData(i, "PayCheck");
		// SavePlayerData(i, "AllowedPayday");
		// SavePlayerData(i, "Ticket");
		// SavePlayerData(i, "Cost");
		
		// SendClientMessage(i,COLOR_LIGHTYELLOW2, "[INFO:] Twoje pieni¹dze s¹ do odebrania w banku.");
		// SendClientMessage(i,COLOR_YELLOW,"____________________________________________________");
	}
	
	printf( "[PAYDAY:] Loading first player from DB" );
	// DATABASE SAVE =================================================================================================
	new string[128];
	format(string, sizeof(string), "SELECT COUNT(ID) AS founder_count FROM `samp_users` WHERE `Banned` = '0' ");
	mysql_query(string);
	
	if(mysql_store_result()!= 0)
	{
		format(string, sizeof(string), "MYSQL STORE RESULT failed in PayDay");
		PayDayLog(string);
	}
		
	if(!mysql_fetch_field("founder_count", fieldCount))
	{
		format(string, sizeof(string), "MYSQL FETCH FIELD failed in PayDay");
		PayDayLog(string); 
	}	
	mysql_free_result();	
	gPayDayLoop = 0;
	gPayDayCount = strval(fieldCount);

	new stringtmp1[2048];
	
	format(stringtmp1, sizeof(stringtmp1), "SELECT `Key`,`ID`,`PlayerName`,`Level`,`AdminLevel`,`DonateRank`,`Registered`,`Sex`,`Age`,`Experience`,`Money`,`Bank`,`Skin`,`PlayingHours`,`AllowedPayday`,`PayCheck`,`Faction`,`Rank`,`Banned`");
	strcat( stringtmp1, ",`Warnings`,`Jailed`,`JailTime`,`CrashX`,`CrashY`,`CrashZ`,`CrashInt`,`CrashW`,`Crashed`,`Wins`,`Loses`,`InvWeapon`,`InvAmmo`,`Tutorial`,`Moderator`,`WantedLvl`,`FirstCar`,`FirstReanimation`,`FirstPhone`,`FirstLeader`" );
	strcat( stringtmp1, ",`CrashAngle`,`HourAssist`,`JoinedFaction`,`HoursOnDuty`,`HoursOnDutyHelper`,`WarnCooldown`,`SpeedLimiter`,`AdminDuty`,`CharDescription`,`CharDescriptionColor`, `FirstJob`, `FirstID`, `FirstBuy`, `FirstHouse`, `FirstDescription`" );
	strcat( stringtmp1, ", `FirstAction`, `FirstBankUse`, `FirstStats`, `FirstJail`, `FirstStudy`" );
	format( stringtmp1, sizeof(stringtmp1), "%s FROM `samp_users` WHERE `Banned` = '0' LIMIT %d , 1", stringtmp1, gPayDayLoop);
	if(mysql_query(stringtmp1, PLAYER_DATA_LOAD_NAME_MYSQL, CUSTOM_MAX_PLAYERS, db_con2) != 0)
	{
		format(string, sizeof(string), "MYSQL QUERY failed in PayDay");
		PayDayLog(string);
	}	
	//SetTimer("PayDay",86400000,0); // sprawdza czy jest dana godzina, wyplaca pieniadze wszystkim graczom
	return 1;
}