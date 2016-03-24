#include <wp\timers\wp_timersdefault>

Timer:PickupGametexts[500]()
{
	new Float:oldposx, Float:oldposy, Float:oldposz;
	new string[128];
	new Float:vehiclehp, Float:hitDamage;
	new Float:playerhp;
	new lightsprm, alarm, doorsprm, bonnet, boot, objective;
	for( new i = 0; i < sizeof(gVehData); i++ )
	{
		GetVehicleHealth(i+1,vehiclehp);
		hitDamage = gVehData[i][CarHealth] - vehiclehp;
		if( (hitDamage) > 80.0 && gVehData[i][EngineOn] )
		{
			for( new j = 0; j < CUSTOM_MAX_PLAYERS; j++ )
			{
				if( !IsPlayerConnected( j ) )
					continue;
				if( !IsPlayerInVehicle( j, i+1 ) )
					continue;
				GetPlayerHealth(j, playerhp);
				if( gPlayerData[j][pSeatBelt] )
				{
					gPlayerData[j][pHP] = playerhp - floatround(hitDamage/9,floatround_round );
					SavePlayerData( j, "HP" );
					SetPlayerHealth( j, gPlayerData[j][pHP] );
				}
				else
				{
					gPlayerData[j][pHP] = playerhp - floatround(hitDamage/4,floatround_round );
					SavePlayerData( j, "HP" );
					SetPlayerHealth( j, gPlayerData[j][pHP] );
				}
			}
		}
		if( (hitDamage) > 130 && gVehData[i][EngineOn] )
		{
			gVehData[i][EngineOn] = 0;
			SaveVehData(i, "EngineOn");
			SetVehicleParamsEx(i+1, 0, lightsprm, alarm, doorsprm, bonnet, boot, objective);
		}
		if(floatround(vehiclehp,floatround_round) <= 200 && floatround(vehiclehp,floatround_round) >= 100)
		{
			if(RandomChance(60)) // 60 procent szansy
			{
				SetVehicleHealth(i+1, 260.0);
				gVehData[i][EngineOn] = 0;
				gVehData[i][CarDamaged] = 1;
				SetVehicleParamsEx(i+1, 0, lightsprm, alarm, doorsprm, bonnet, boot, objective);

				SaveVehData(i, "EngineOn");
				SaveVehData(i, "CarDamaged");
			}
		}
		if( gVehData[i][CarHealth] != vehiclehp )
		{
			gVehData[i][CarHealth] = vehiclehp;
			SaveVehData( i, "CarHealth" );
		}
	}
	foreach(Player, i )
	{
		if( !gPlayerLogged[i] )
			continue;
		//=========================================[FUEL GAMETEXT]=============================================================
		if(ShowFuel[i] && GetPlayerState(i) == PLAYER_STATE_DRIVER)
		{
			VehicleStatusShow[i] = 1;
			new form[256];
			new tfueltype[32];
			new copyform[256];
			new fuel[32];
			new engineStatus[32];
			new batteryStatus[32];
			new vehicle = GetPlayerVehicleID(i);
			new tlID = GetVehicleTrailer(vehicle);
			if(gVehData[vehicle-1][CarModel] != 509
			&& gVehData[vehicle-1][CarModel] != 481
			&& gVehData[vehicle-1][CarModel] != 509
			&& gVehData[vehicle-1][CarModel] != 510 )
			{
				if(!IsABike(vehicle))
				{
					if( gVehData[vehicle-1][CarFuel] <= float(VehFTank(vehicle)) * 0.20 )
						format( fuel, sizeof(fuel), "~r~! %dltr", floatround(gVehData[vehicle-1][CarFuel], floatround_round ) );
					else
						format( fuel, sizeof(fuel), "%dltr", floatround(gVehData[vehicle-1][CarFuel], floatround_round ) );
					if(gVehData[vehicle-1][EngineOn] == 1)
						strcat( engineStatus, "uruchomiony" );						
					else
						strcat( engineStatus, "wylaczony" );
					if( gVehData[vehicle-1][BatteryCapacity] >= floatround( gVehData[vehicle-1][BatteryMaxCapacity]/2, floatround_round ) )
						strcat( batteryStatus, "~g~bardzo dobry" );
					else if( gVehData[vehicle-1][BatteryCapacity] < floatround( gVehData[vehicle-1][BatteryMaxCapacity]/2, floatround_round ) && gVehData[vehicle-1][BatteryCapacity] > floatround( gVehData[vehicle-1][BatteryMaxCapacity]/4, floatround_round ) )
						strcat( batteryStatus, "~y~dobry" );
					else
						strcat( batteryStatus, "~r~slaby" );
					format(form, sizeof(form), "~w~~y~Silnik: ~w~%s ~y~Paliwo:~w~ %s ~y~Kilometry: ~w~%d ~y~Predkosc: ~w~%d ~y~Akumulator: %s", engineStatus, fuel, floatround(gVehData[vehicle-1][CarCounter]/1000, floatround_round), ASpeed(vehicle), batteryStatus);
					if( IsATankerTrailer(tlID) )
					{
						switch( gVehData[tlID-1][TankerResourceType] )
						{
							case TANKER_TYPE_NONE: { format(tfueltype, sizeof(tfueltype), "brak" ); }
							case TANKER_TYPE_PETROL: { format(tfueltype, sizeof(tfueltype), "benzyna" ); }
							case TANKER_TYPE_OIL: { format(tfueltype, sizeof(tfueltype), "ropa" ); }
							case TANKER_TYPE_GAS: { format(tfueltype, sizeof(tfueltype), "gas" ); }
						}
						format(copyform, sizeof(copyform), "%s ~y~Typ paliwa w cysternie: ~w~%s ~y~Ilosc paliwa: ~w~%dltr", form, tfueltype, gVehData[tlID-1][TankerResourceValue] );
						format(form, sizeof(form), "%s", copyform );
					}
				}
				TextDrawSetString(VehicleStatus[i], form);
				TextDrawShowForPlayer(i, VehicleStatus[i]);
			}
		}
		else
		{
			if(VehicleStatusShow[i] == 1)
			{
				TextDrawHideForPlayer(i, Text:VehicleStatus[i]);
				VehicleStatusShow[i] = 0;
			}
		}
		// Position data
		GetPlayerPos(i, oldposx, oldposy, oldposz);
		if(oldposx!=0.0 && oldposy!=0.0 && oldposz!=0.0)
		{
			//=============================================[BUILDING GAMETEXTS]==========================================
			for(new h = 0; h < sizeof(Building); h++)
			{
				if (PlayerToPoint(1.0, i,Building[h][EnterX], Building[h][EnterY], Building[h][EnterZ]))
				{
					if(GetPlayerCash(i) >= Building[h][EntranceFee])
					{
						if(Building[h][EntranceFee] > 1)
						{
							format(string, sizeof(string), "%s~n~~w~Wejsciowka: ~g~$%d",Building[h][BuildingName],Building[h][EntranceFee]);
							GameTextForPlayer(i, string, 3500, 3);
						}
						else
						{
							format(string, sizeof(string), "%s",Building[h][BuildingName]);
							GameTextForPlayer(i, string, 3500, 3);
						}
					}
					else
					{
						if(Building[h][EntranceFee] > 1)
						{
							format(string, sizeof(string), "%s~n~~w~Wejsciowka: ~r~$%d",Building[h][BuildingName],Building[h][EntranceFee]);
							GameTextForPlayer(i, string, 3500, 3);
						}
						else
						{
							format(string, sizeof(string), "%s",Building[h][BuildingName]);
							GameTextForPlayer(i, string, 3500, 3);
						}
					}
				}
			}
			//=========================================================================================================
			//======================================[HOUSE GAMETEXTS]===================================================
			/*for(new n = 0; n < sizeof(Houses); n++)
			{
				if (PlayerToPoint(1.0, i,Houses[n][EnterX], Houses[n][EnterY], Houses[n][EnterZ]))
				{
					if(Houses[n][HousePrice] != 0) //Only show the house if Cena is set
					{
						if(Houses[n][Owned] == 0)
						{
							new houselocation[MAX_ZONE_NAME];
							GetCoords2DZone(Houses[n][EnterX],Houses[n][EnterY], houselocation, MAX_ZONE_NAME);
							format(string, sizeof(string), "~g~Ten dom jest na sprzedaz!~n~~w~Adres: ~y~ %d %s~n~~w~Opis: ~y~%s ~n~~w~Cena: ~y~$%d",n,houselocation,Houses[n][Description],Houses[n][HousePrice]);
							GameTextForPlayer(i, string, 3500, 3);
						}
						else
						{
							if(Houses[n][Rentable] == 1)
							{
								new houselocation[MAX_ZONE_NAME];
								GetCoords2DZone(Houses[n][EnterX],Houses[n][EnterY], houselocation, MAX_ZONE_NAME);
								format(string, sizeof(string), "~w~Adres: ~y~%d %s~n~~w~Wlasciciel: ~y~%s ~n~~w~Opis: ~y~%s~n~~w~Czynsz: ~y~$%d",n,houselocation,Houses[n][Owner],Houses[n][Description],Houses[n][RentCost]);
								GameTextForPlayer(i, string, 3500, 3);
							}
							else
							{
								new houselocation[MAX_ZONE_NAME];
								GetCoords2DZone(Houses[n][EnterX],Houses[n][EnterY], houselocation, MAX_ZONE_NAME);
								format(string, sizeof(string), "~w~Adres: ~y~%d %s~n~~w~Wlasciciel: ~y~%s ~n~~w~Opis: ~y~%s",n,houselocation,Houses[n][Owner],Houses[n][Description]);
								GameTextForPlayer(i, string, 3500, 3);
							}
						}
					}
				}
			}*/
			//=======================================[BUSINESS GAMETEXTS]=========================================================
			/*for(new n = 0; n < sizeof(Businesses); n++)
			{
				if (PlayerToPoint(1.0, i,Businesses[n][EnterX], Businesses[n][EnterY], Businesses[n][EnterZ]))
				{
					new businesstype[128];
					if(Businesses[n][BizType] != 0)
					{
						if(Businesses[n][BizType] == 1) { businesstype = "Restauracja"; }
						else if(Businesses[n][BizType] == 2) { businesstype = "Siec komorkowa"; }
						else if(Businesses[n][BizType] == 3) { businesstype = "Sklep 24/7"; }
						else if(Businesses[n][BizType] == 4) { businesstype = "Sklep z bronia"; }
						else if(Businesses[n][BizType] == 5) { businesstype = "Studio reklamowe"; }
						else if(Businesses[n][BizType] == 6) { businesstype = "Sklep z ubraniami"; }
						else if(Businesses[n][BizType] == 7) { businesstype = "Bar/Club"; }
						else if(Businesses[n][BizType] == 8) { businesstype = "Studio nagraniowe"; }
						else if(Businesses[n][BizType] == 9) { businesstype = "Studio"; }
					}
					else { businesstype = "Nie ustawione"; }

					if(Businesses[n][BizPrice] != 0) //Only show the business if Cena is set
					{
						if(Businesses[n][Owned] == 0)
						{
							format(string, sizeof(string), "~g~Ten biznes jest na sprzeda¿!~n~~w~Nazwa biznesu: ~y~%s ~n~~w~Typ biznesu: ~y~%s ~n~~w~Cena: ~y~$%d",Businesses[n][BusinessName],businesstype,Businesses[n][BizPrice]);
							GameTextForPlayer(i, string, 3500, 3);
						}
						else
						{
							format(string, sizeof(string), "~w~Business Name: ~y~%s ~n~~w~Nazwa biznesu: ~y~%s ~n~~w~Wlasciciel: ~y~%s~n~~w~Wejsciowka: ~y~$%d",Businesses[n][BusinessName],businesstype,Businesses[n][Owner],Businesses[n][EntranceCost]);
							GameTextForPlayer(i, string, 3500, 3);
						}
					}
				}
			}*/
			//=======================================[RACE GAMETEXTS]=========================================================
			for(new n = 0; n < sizeof(DynamicRaces); n++)
			{
				if (PlayerToPoint(1.0, i,DynamicRaces[n][TakeRaceX], DynamicRaces[n][TakeRaceY], DynamicRaces[n][TakeRaceZ]))
				{
					if(DynamicRaces[n][Started])
					{
						format(string, sizeof(string), "~r~WYSCIG~n~~w~STAN: ~g~ROZPOCZETY~n~~w~WEJSCIOWKA: ~g~%d~n~~w~L. KIEROWCOW: ~g~%d/%d~n~~r~/dolaczdowyscigu", DynamicRaces[n][EnterPrice], RaceDriversCount, DynamicRaces[n][MaxDrivers]);
						GameTextForPlayer(i, string, 3500, 3);
					}
					else
					{
						format(string, sizeof(string), "~r~WYSCIG~n~~w~STAN: ~g~ZAKONCZONY~n~~w~KOSZT ROZPOCZECIA: ~g~%d~n~~w~REKORD: ~g~%s~n~~w~CZAS: ~g~%d:%d~n~~r~/rozpocznijwyscig", DynamicRaces[n][StartPrice], DynamicRaces[n][KingOfSprint], DynamicRaces[n][TopTimeM], DynamicRaces[n][TopTimeS]);
						GameTextForPlayer(i, string, 3500, 3);
					}
				}
			}
			//========================================================================================================================
			if (PlayerToPoint(1.0, i,DrivingTestPosition[X],DrivingTestPosition[Y],DrivingTestPosition[Z]))
			{
				// if(GetPlayerVirtualWorld(i) == DrivingTestPosition[World])
				// {
				if(!gPlayerData[i][pFirstCarTest])
				{
					GameTextForPlayer(i, "~w~Test na prawko ~n~Cena: ~g~$1500~n~~w~Wpisz /kuptest !", 3500, 3);
				}
				else
				{
					GameTextForPlayer(i, "~w~Test na prawko ~n~Cena: ~g~$200~n~~w~Wpisz /kuptest !", 3500, 3);
				}
				// }
			}
			else if(PlayerToPoint(1.0, i,FlyingTestPosition[X],FlyingTestPosition[Y],FlyingTestPosition[Z]))
			{
				if(GetPlayerVirtualWorld(i) == FlyingTestPosition[World])
				{
					GameTextForPlayer(i, "~w~Licencja pilota~n~Cena: ~g~$20000~n~~w~Wpisz /kuplicencjepilota !", 3500, 3);
				}
			}
			else if(PlayerToPoint(1.0, i,BoatTestPosition[X],BoatTestPosition[Y],BoatTestPosition[Z]))
			{
				if(GetPlayerVirtualWorld(i) == BoatTestPosition[World])
				{
					GameTextForPlayer(i, "~w~Licencja na ³odzie~n~Cena: ~g~$20000~n~~w~Wpisz /kuptest !", 3500, 3);
				}
			}
			else if(PlayerToPoint(1.0, i,WeaponLicensePosition[X],WeaponLicensePosition[Y],WeaponLicensePosition[Z]))
			{
				if(GetPlayerVirtualWorld(i) == WeaponLicensePosition[World])
				{
					GameTextForPlayer(i, "~w~Licencja na bron ~n~Cena: ~g~$50000~n~~w~Wpisz /kuplicencjenabron !", 3500, 3);
				}
			}
			else if(PlayerToPoint(1.0, i,BankPosition[X],BankPosition[Y],BankPosition[Z]))
			{
				if(GetPlayerVirtualWorld(i) == BankPosition[World])
				{
					GameTextForPlayer(i, "~w~Bank", 3500, 3);
				}
			}
			else if(PlayerToPoint(1.0, i,FactionMaterialsStorage[X],FactionMaterialsStorage[Y],FactionMaterialsStorage[Z]))
			{
				if(gPlayerData[i][pFaction] != 255 && DynamicFactions[gPlayerData[i][pFaction]][fType] != 1)
				{
					GameTextForPlayer(i, "~w~Magazyn materialow", 3500, 3);
				}
				else
				{
					GameTextForPlayer(i, "~r~Nieznane", 3500, 3);
				}
			}
			else if(PlayerToPoint(1.0, i,FactionDrugsStorage[X],FactionDrugsStorage[Y],FactionDrugsStorage[Z]))
			{
				if(gPlayerData[i][pFaction] != 255 && DynamicFactions[gPlayerData[i][pFaction]][fType] != 1)
				{
					GameTextForPlayer(i, "~w~Magazyn narkotykow", 3500, 3);
				}
				else
				{
					GameTextForPlayer(i, "~r~Nieznane", 3500, 3);
				}
			}
			else if(PlayerToPoint(1.0, i,GunJob[TakeJobX],GunJob[TakeJobY],GunJob[TakeJobZ]))
			{
				// if(GetPlayerVirtualWorld(i) == GunJob[TakeJobWorld])
				// {
					GameTextForPlayer(i, "~n~~r~Diler broni ~n~~w~/wezprace", 3500, 3);
				// }
			}
			else if(PlayerToPoint(1.0, i,GunJob[BuyPackagesX],GunJob[BuyPackagesY],GunJob[BuyPackagesZ]))
			{
				// if(GetPlayerVirtualWorld(i) == GunJob[BuyPackagesWorld])
				// {
					GameTextForPlayer(i, "~n~~r~Diler broni ~n~~w~/materialy kup", 3500, 3);
				// }
			}
			else if(PlayerToPoint(1.0, i,GunJob[DeliverX],GunJob[DeliverY],GunJob[DeliverZ]))
			{
				// if(GetPlayerVirtualWorld(i) == GunJob[DeliverWorld])
				// {
					GameTextForPlayer(i, "~n~~r~Diler broni ~n~~w~/materialy zrzuc", 3500, 3);
				// }
			}
			else if(PlayerToPoint(1.0, i,DrugJob[TakeJobX],DrugJob[TakeJobY],DrugJob[TakeJobZ]))
			{
				if(GetPlayerVirtualWorld(i) == DrugJob[TakeJobWorld])
				{
					GameTextForPlayer(i, "~n~~r~Diler narkotykow ~n~~w~/wezprace", 3500, 3);
				}
			}
			else if(PlayerToPoint(1.0, i,DrugJob[BuyDrugsX],DrugJob[BuyDrugsY],DrugJob[BuyDrugsZ]))
			{
				if(GetPlayerVirtualWorld(i) == DrugJob[BuyDrugsWorld])
				{
					GameTextForPlayer(i, "~n~~r~Diler narkotykow ~n~~w~/narkotyki kup", 3500, 3);
				}
			}
			else if(PlayerToPoint(1.0, i,DrugJob[DeliverX],DrugJob[DeliverY],DrugJob[DeliverZ]))
			{
				// if(GetPlayerVirtualWorld(i) == DrugJob[DeliverWorld])
				// {
					GameTextForPlayer(i, "~n~~r~Diler narkotykow ~n~~w~/narkotyki zrzuc", 3500, 3);
				// }
			}
			else if(PlayerToPoint(1.0, i,DetectiveJobPosition[X],DetectiveJobPosition[Y],DetectiveJobPosition[Z]))
			{
				// if(GetPlayerVirtualWorld(i) == DetectiveJobPosition[World])
				// {
					GameTextForPlayer(i, "~n~~r~Detektyw ~n~~w~/wezprace", 3500, 3);
				// }
			}
			else if(PlayerToPoint(1.0, i,LawyerJobPosition[X],LawyerJobPosition[Y],LawyerJobPosition[Z]))
			{
				// if(GetPlayerVirtualWorld(i) == LawyerJobPosition[World])
				// {
					GameTextForPlayer(i, "~n~~r~Prawnik ~n~~w~/wezprace", 3500, 3);
				// }
			}
			else if(PlayerToPoint(1.0, i,ProductsSellerJob[TakeJobX],ProductsSellerJob[TakeJobY],ProductsSellerJob[TakeJobZ]))
			{
				// if(GetPlayerVirtualWorld(i) == ProductsSellerJob[TakeJobWorld])
				// {
					GameTextForPlayer(i, "~n~~r~Sprzedawca produktow ~n~~w~/wezprace", 3500, 3);
				// }
			}
			else if(PlayerToPoint(1.0, i,WhoreJob[TakeJobX],WhoreJob[TakeJobY],WhoreJob[TakeJobZ]))
			{
				// if(GetPlayerVirtualWorld(i) == WhoreJob[TakeJobWorld])
				// {
					GameTextForPlayer(i, "~n~~r~Praca dziwki ~n~~w~/wezprace", 3500, 3);
				// }
			}
			else if(PlayerToPoint(1.0, i,StuntJob[TakeJobX],StuntJob[TakeJobY],StuntJob[TakeJobZ]))
			{
				// if(GetPlayerVirtualWorld(i) == StuntJob[TakeJobWorld])
				// {
					GameTextForPlayer(i, "~n~~r~Praca kaskadera ~n~~w~/wezprace", 3500, 3);
				// }
			}
			else if(PlayerToPoint(1.0, i,CarjackJob[TakeJobX],CarjackJob[TakeJobY],CarjackJob[TakeJobZ]))
			{
				// if(GetPlayerVirtualWorld(i) == CarjackJob[TakeJobWorld])
				// {
					GameTextForPlayer(i, "~n~~r~Praca zlodzieja wozow ~n~~w~/wezprace", 3500, 3);
				// }
			}
			else if(PlayerToPoint(1.0, i,RapistJob[TakeJobX],RapistJob[TakeJobY],RapistJob[TakeJobZ]))
			{
				if(GetPlayerVirtualWorld(i) == RapistJob[TakeJobWorld])
				{
					GameTextForPlayer(i, "~n~~r~Gwalciciel ~n~~w~/wezprace", 3500, 3);
				}
			}
			else if(PlayerToPoint(1.0, i,BoxerJob[TakeJobX],BoxerJob[TakeJobY],BoxerJob[TakeJobZ]))
			{
				if(GetPlayerVirtualWorld(i) == BoxerJob[TakeJobWorld])
				{
					GameTextForPlayer(i, "~n~~r~Boxer ~n~~w~/wezprace", 3500, 3);
				}
			}
			else if(PlayerToPoint(1.0, i,BodyJob[TakeJobX],BodyJob[TakeJobY],BodyJob[TakeJobZ]))
			{
				// if(GetPlayerVirtualWorld(i) == BodyJob[TakeJobWorld])
				// {
					GameTextForPlayer(i, "~n~~r~Ochroniarz ~n~~w~/wezprace", 3500, 3);
				// }
			}
			else if(PlayerToPoint(1.0, i,DirJob[TakeJobX],DirJob[TakeJobY],DirJob[TakeJobZ]))
			{
				if(GetPlayerVirtualWorld(i) == DirJob[TakeJobWorld])
				{
					GameTextForPlayer(i, "~n~~r~Rezyser~n~~w~/wezprace", 3500, 3);
				}
			}
			else if(PlayerToPoint(1.0, i,ProductsSellerJob[BuyProductsX],ProductsSellerJob[BuyProductsY],ProductsSellerJob[BuyProductsZ]))
			{
				// if(GetPlayerVirtualWorld(i) == ProductsSellerJob[BuyProductsWorld])
				// {
					GameTextForPlayer(i, "~n~~r~Sprzedawca produktow ~n~~w~/produkty kup", 3500, 3);
				// }
			}
			else if(PlayerToPoint(1.0, i,BusJob[TakeJobX],BusJob[TakeJobY],BusJob[TakeJobZ]))
			{
				if(GetPlayerVirtualWorld(i) == BusJob[TakeJobWorld])
				{
					GameTextForPlayer(i, "~n~~r~Kierowca Autobusu~n~~w~/wezprace", 3500, 3);
				}
			}
			else if(PlayerToPoint(1.0, i,MzgkJob[TakeJobX],MzgkJob[TakeJobY],MzgkJob[TakeJobZ]))
			{
				if(GetPlayerVirtualWorld(i) == MzgkJob[TakeJobWorld])
				{
					GameTextForPlayer(i, "~n~~r~Kierowca Smieciarki~n~~w~/wezprace", 3500, 3);
				}
			}
			else if(PlayerToPoint(1.0, i,SweeperJob[TakeJobX],SweeperJob[TakeJobY],SweeperJob[TakeJobZ]))
			{
				if(GetPlayerVirtualWorld(i) == SweeperJob[TakeJobWorld])
				{
					GameTextForPlayer(i, "~n~~r~Kierowca Myjki drogowej~n~~w~/wezprace", 3500, 3);
				}
			}
			else if(PlayerToPoint(1.0, i,TaxiJob[TakeJobX],TaxiJob[TakeJobY],TaxiJob[TakeJobZ]))
			{
				if(GetPlayerVirtualWorld(i) == TaxiJob[TakeJobWorld])
				{
					GameTextForPlayer(i, "~n~~r~Taksowkarz~n~~w~/wezprace", 3500, 3);
				}
			}
			else if(PlayerToPoint(1.0, i,MechanicJob[TakeJobX],MechanicJob[TakeJobY],MechanicJob[TakeJobZ]))
			{
				// if(GetPlayerVirtualWorld(i) == MechanicJob[TakeJobWorld])
				// {
					GameTextForPlayer(i, "~n~~r~Mechanik~n~~w~/wezprace", 3500, 3);
				// }
			}
			else if(PlayerToPoint(1.0, i,MechanicJob2[BuyProductsX],MechanicJob2[BuyProductsY],MechanicJob2[BuyProductsZ]))
			{
				// if(GetPlayerVirtualWorld(i) == 	MechanicJob2[BuyProductsWorld])
				// {
					GameTextForPlayer(i, "~n~~r~Czesci samochodowe~n~~w~/kupczesci", 3500, 3);
				// }
			}
			else if(PlayerToPoint(1.0, i,FarmerJob[TakeJobX],FarmerJob[TakeJobY],FarmerJob[TakeJobZ]))
			{
				// if(GetPlayerVirtualWorld(i) == FarmerJob[TakeJobWorld])
				// {
					GameTextForPlayer(i, "~n~~r~Farmer~n~~w~/wezprace", 3500, 3);
				// }
			}
			else if(PlayerToPoint(1.0, i,SellerJob[TakeJobX],SellerJob[TakeJobY],SellerJob[TakeJobZ]))
			{
				// if(GetPlayerVirtualWorld(i) == SellerJob[TakeJobWorld])
				// {
					GameTextForPlayer(i, "~n~~r~Sprzedawca/kasjer~n~~w~/wezprace", 3500, 3);
				// }
			}
			else if(PlayerToPoint(1.0, i,AccountantJob[TakeJobX],AccountantJob[TakeJobY],AccountantJob[TakeJobZ]))
			{
				// if(GetPlayerVirtualWorld(i) == AccountantJob[TakeJobWorld])
				// {
					GameTextForPlayer(i, "~n~~r~Ksiegowy~n~~w~/wezprace", 3500, 3);
				// }
			}
			else if(PlayerToPoint(1.0, i,NewsBoyJob[TakeJobX],NewsBoyJob[TakeJobY],NewsBoyJob[TakeJobZ]))
			{
				// if(GetPlayerVirtualWorld(i) == NewsBoyJob[TakeJobWorld])
				// {
					GameTextForPlayer(i, "~n~~r~Roznosiciel gazet~n~~w~/wezprace", 3500, 3);
				// }
			}
			else if(PlayerToPoint(1.0, i,SkillPosition[XPis],SkillPosition[YPis],SkillPosition[ZPis]))
			{
					GameTextForPlayer(i, "~n~~r~Pistolet~n~Cena: ~g~$1000~n~~w~/podnieslev", 3500, 3);
			}
			else if(PlayerToPoint(1.0, i,SkillPosition[XSil],SkillPosition[YSil],SkillPosition[ZSil]))
			{
					GameTextForPlayer(i, "~n~~r~Pistolet z Tlumnikiem~n~Cena: ~g~$1000~n~~w~/podnieslev", 3500, 3);
			}
			else if(PlayerToPoint(1.0, i,SkillPosition[XDes],SkillPosition[YDes],SkillPosition[ZDes]))
			{
					GameTextForPlayer(i, "~n~~r~Desert Eagle~n~Cena: ~g~$2000~n~~w~/podnieslev", 3500, 3);
			}
			else if(PlayerToPoint(1.0, i,SkillPosition[XSho],SkillPosition[YSho],SkillPosition[ZSho]))
			{
					GameTextForPlayer(i, "~n~~r~Shotgun~n~Cena: ~g~$2000~n~~w~/podnieslev", 3500, 3);
			}
			else if(PlayerToPoint(1.0, i,SkillPosition[XSha],SkillPosition[YSha],SkillPosition[ZSha]))
			{
					GameTextForPlayer(i, "~n~~r~Ogryzek~n~Cena: ~g~$2000~n~~w~/podnieslev", 3500, 3);
			}
			else if(PlayerToPoint(1.0, i,SkillPosition[XSpa],SkillPosition[YSpa],SkillPosition[ZSpa]))
			{
					GameTextForPlayer(i, "~n~~r~Shotgun Bojowy~n~Cena: ~g~$3000~n~~w~/podnieslev", 3500, 3);
			}
			else if(PlayerToPoint(1.0, i,SkillPosition[XMic],SkillPosition[YMic],SkillPosition[ZMic]))
			{
					GameTextForPlayer(i, "~n~~r~Uzi~n~Cena: ~g~$2000~n~~w~/podnieslev", 3500, 3);
			}
			else if(PlayerToPoint(1.0, i,SkillPosition[XMp5],SkillPosition[YMp5],SkillPosition[ZMp5]))
			{
					GameTextForPlayer(i, "~n~~r~Mp5~n~Cena: ~g~$4000~n~~w~/podnieslev", 3500, 3);
			}
			else if(PlayerToPoint(1.0, i,SkillPosition[XAk],SkillPosition[YAk],SkillPosition[ZAk]))
			{
					GameTextForPlayer(i, "~n~~r~Kalasznikow~n~Cena: ~g~$5000~n~~w~/podnieslev", 3500, 3);
			}
			else if(PlayerToPoint(1.0, i,SkillPosition[XM4],SkillPosition[YM4],SkillPosition[ZM4]))
			{
					GameTextForPlayer(i, "~n~~r~M4~n~Cena: ~g~$5000~n~~w~/podnieslev", 3500, 3);
			}
			else if(PlayerToPoint(1.0, i,SkillPosition[XSni],SkillPosition[YSni],SkillPosition[ZSni]))
			{
					GameTextForPlayer(i, "~n~~r~Snajperka~n~Cena: ~g~$6000~n~~w~/podnieslev", 3500, 3);
			}
			else if(PlayerToPoint(1.0, i,SkillPosition[XAng],SkillPosition[YAng],SkillPosition[ZAng]))
			{
					GameTextForPlayer(i, "~n~~r~Angielski~n~Cena: ~g~$400~n~~w~/podnieslev", 3500, 3);
			}
			else if(PlayerToPoint(1.0, i,SkillPosition[XWf],SkillPosition[YWf],SkillPosition[ZWf]))
			{
					GameTextForPlayer(i, "~n~~r~WF~n~Cena: ~g~$500~n~~w~/podnieslev", 3500, 3);
			}
			else if(PlayerToPoint(1.0, i,SkillPosition[XMat],SkillPosition[YMat],SkillPosition[ZMat]))
			{
					GameTextForPlayer(i, "~n~~r~Matematyka~n~Cena: ~g~$500~n~~w~/podnieslev", 3500, 3);
			}
			else if(PlayerToPoint(1.0, i,SkillPosition[XPol],SkillPosition[YPol],SkillPosition[ZPol]))
			{
					GameTextForPlayer(i, "~n~~r~Polski~n~Cena: ~g~$500~n~~w~/podnieslev", 3500, 3);
			}
			else if(PlayerToPoint(1.0, i,SkillPosition[XHis],SkillPosition[YHis],SkillPosition[ZHis]))
			{
					GameTextForPlayer(i, "~n~~r~Historia~n~Cena: ~g~$500~n~~w~/podnieslev", 3500, 3);
			}
			else if(PlayerToPoint(1.0, i,SkillPosition[XFiz],SkillPosition[YFiz],SkillPosition[ZFiz]))
			{
					GameTextForPlayer(i, "~n~~r~Fizyka~n~Cena: ~g~$500~n~~w~/podnieslev", 3500, 3);
			}
			else if(PlayerToPoint(1.0, i,SkillPosition[XBio],SkillPosition[YBio],SkillPosition[ZBio]))
			{
					GameTextForPlayer(i, "~n~~r~Biologia~n~Cena: ~g~$500~n~~w~/podnieslev", 3500, 3);
			}
			else if(PlayerToPoint(1.0, i, WFWorkerJob[TakeJobX], WFWorkerJob[TakeJobY], WFWorkerJob[TakeJobZ] ) )
				GameTextForPlayer(i, "~n~~r~Pracownik fabryki broni~n~~w~/wezprace", 3500, 3);
			//=============================================================================================================
		}
	}
	return 1;
}

RafineryResourcesIncrease()
{
	//print("[TIMERCHECK:] RafineryResourceIncrease()");
	if( gRafinery[RafResourcePetrol] < gRafinery[RafMaxResources] )
	{
		if( gRafinery[RafMaxResources] - gRafinery[RafResourcePetrol] < 50 )
			gRafinery[RafResourcePetrol] += 50;
	}
	if( gRafinery[RafResourceOil] < gRafinery[RafMaxResources] )
	{
		if( gRafinery[RafMaxResources] - gRafinery[RafResourceOil] < 40 )
			gRafinery[RafResourceOil] += 40;
	}
	if( gRafinery[RafResourceGas] < gRafinery[RafMaxResources] )
	{
		if( gRafinery[RafMaxResources] - gRafinery[RafResourceGas] < 30 )
			gRafinery[RafResourceGas] += 30;
	}
	SaveRafinery();
	return 1;
}

Timer:FuelTimer[5000]()
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
				GameTextForPlayer(i,"~r~Brak paliwa!",1500,3);
				GetVehicleParamsEx(vehicle, enginedyn, lights, alarm, doors, bonnet, boot, objective);
				SetVehicleParamsEx(vehicle,0,lights,alarm,doors,bonnet,boot,objective);
			}
			else
			{
				if(!gVehData[vehicle-1][EngineOn])
					continue;

				for(new n = 0; n < sizeof(CarsData); n++)
				{
					if(gVehData[vehicle-1][CarModel] != CarsData[n][Model])
						continue;

					if(gVehData[vehicle-1][Fuel] != CarsData[n][Paliwo])
						continue;

					if(gCarFuelDistancer[vehicle-1] == 0)
					{
						gCarFuelDistancer[vehicle-1] = gVehData[vehicle-1][CarCounter];
					}
					else
					{
						gVehData[vehicle-1][CarFuel] -= ((( float(gVehData[vehicle-1][CarCounter] - gCarFuelDistancer[vehicle-1]))/100000.0) * float(CarsData[n][Spalanie])); // dlaczego przez 100000.0 ? bo spalanie jest podawane w l/100km

						gVehData[vehicle-1][CarFuel] -= 0.02;

						if(gVehData[vehicle-1][CarFuel] < 0.0)
							gVehData[vehicle-1][CarFuel] = 0.0;

						SaveVehData(vehicle-1, "CarFuel");

						gCarFuelDistancer[vehicle-1] = gVehData[vehicle-1][CarCounter];
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

Timer:CheckPointTimer[200]()
{
	new Float: posX , Float: posY , Float: posZ, Float: dist ;
	new vid;
	foreach(Player, i )
	{
		if(GetPlayerState(i) == PLAYER_STATE_DRIVER)
		{
		    vid = GetPlayerVehicleID(i);
			GetVehicleVelocity(vid, posX, posY, posZ);
			dist = floatsqroot(floatpower(posX, 2) + floatpower(posY, 2) + floatpower(posZ, 2)) * 200.0;
			if(gVehData[vid-1][CarModel] == 431 || gVehData[vid-1][CarModel] == 437)
			{
				if(gIsInCityAreaSpeedLimit[i])
				{
					if(dist > 45.0)
					{
						dist = 45.0;
						GetXYVelocity(vid, posX, posY, (dist/136.666667));
						SetVehicleVelocity(vid, posX, posY, posZ);
					}
				}
				else
				{
					if(dist > 68.4)
					{
						dist = 68.4;
						GetXYVelocity(vid, posX, posY, (dist/136.666667));
						SetVehicleVelocity(vid, posX, posY, posZ);
					}
				}
			}
			if(gPlayerData[i][pSpeedLimiter] && !TakingDrivingTest[i]
			&& !IsAPlane(vid) && !IsAHelicopter(vid) && !IsABoat(vid)
			&& !IsAMotorBike(vid))
			{
				if(gIsInCityAreaSpeedLimit[i])
				{
					if(dist > 53.2)
					{
						dist = 53.2;
						GetXYVelocity(vid, posX, posY, (dist/136.666667));
						SetVehicleVelocity(vid, posX, posY, posZ);
					}
				}
				else
				{
					if(dist > 91.2)
					{
						dist = 91.2;
						GetXYVelocity(vid, posX, posY, (dist/136.666667));
						SetVehicleVelocity(vid, posX, posY, posZ);
					}
				}
			}
			if(TakingDrivingTest[i])
			{
				if(dist > 55.0)
					gOverSpeed[i]++;
			}
		}
	}
	if(RaceStarted == 1)
	{
		new string[128];
		new tmpname[MAX_PLAYER_NAME];
		for(new i = 0; i <= DynamicRaces[RaceID][MaxDrivers]; i++)
		{
			if(strlen(RaceDrivers[i]) != 0 && RaceTimeM[i] < 10)
			{
				RaceTimeS[i]++;
				if(RaceTimeS[i] >= 60)
				{
					RaceTimeM[i]++;
					RaceTimeS[i] = 0;
				}
				if(IsPlayerInRangeOfPoint(RaceDriversID[i], 15.0, DynamicRaces[RaceID][StartPointX],DynamicRaces[RaceID][StartPointY],DynamicRaces[RaceID][StartPointZ]))
				{
					SetPlayerRaceCheckpoint(RaceDriversID[i], 1,DynamicRaces[RaceID][FinishPointX],DynamicRaces[RaceID][FinishPointY],DynamicRaces[RaceID][FinishPointZ], 0.0, 0.0, 0.0, 15.0);
				}
				if(IsPlayerInRangeOfPoint(RaceDriversID[i], 15.0,DynamicRaces[RaceID][FinishPointX],DynamicRaces[RaceID][FinishPointY],DynamicRaces[RaceID][FinishPointZ]))
				{
					RacePlace++;
					if(RacePlace == 1)
					{
						GivePlayerCash(RaceDriversID[i], RacePrize);
						strmid(DynamicRaces[RaceID][LastWinner], RaceDrivers[i], 0, strlen(RaceDrivers[i]), MAX_PLAYER_NAME);
						SendClientMessage(RaceDriversID[i], COLOR_LIGHTYELLOW2, "[INFO:] Wygra³eœ wyœcig ! Otrzymujesz nagrode !");
						format(string, sizeof(string), "[INFO:] Twój czas: %d:%d, pula: %d", RaceTimeM[i], RaceTimeS[i], RacePrize);
						SendClientMessage(RaceDriversID[i], COLOR_LIGHTYELLOW2, string);
						RaceDriversCount--;
						SavePlayerData(RaceDriversID[i], "Cash");

						if(DynamicRaces[RaceID][TopTimeM] == 0 && DynamicRaces[RaceID][TopTimeS] == 0)
						{
							DynamicRaces[RaceID][TopTimeS] = RaceTimeS[i];
							DynamicRaces[RaceID][TopTimeM] = RaceTimeM[i];
							strmid(DynamicRaces[RaceID][KingOfSprint], RaceDrivers[i], 0,strlen(RaceDrivers[i]), MAX_PLAYER_NAME);
						}
						else if(RaceTimeM[i] == DynamicRaces[RaceID][TopTimeM])
						{
							if(RaceTimeS[i] < DynamicRaces[RaceID][TopTimeS])
							{
								DynamicRaces[RaceID][TopTimeS] = RaceTimeS[i];
								DynamicRaces[RaceID][TopTimeM] = RaceTimeM[i];
								strmid(DynamicRaces[RaceID][KingOfSprint], RaceDrivers[i], 0, strlen(RaceDrivers[i]), MAX_PLAYER_NAME);
							}
						}
						else if(RaceTimeM[i] < DynamicRaces[RaceID][TopTimeM])
						{
							DynamicRaces[RaceID][TopTimeS] = RaceTimeS[i];
							DynamicRaces[RaceID][TopTimeM] = RaceTimeM[i];
							strmid(DynamicRaces[RaceID][KingOfSprint], RaceDrivers[i], 0,strlen(RaceDrivers[i]), MAX_PLAYER_NAME);
						}
						DisablePlayerRaceCheckpoint(RaceDriversID[i]);
						RaceDriversID[i] = 255;
						RaceTimeM[i] = 0;
						RaceTimeS[i] = 0;
						strdel(RaceDrivers[i], 0, MAX_PLAYER_NAME);
						RacePrize = 0;
					}
					else
					{
						RaceDriversCount--;
						format(string, sizeof(string), "[INFO:] Zaj¹³eœ %d miejsce", RacePlace);
						SendClientMessage(RaceDriversID[i], COLOR_LIGHTYELLOW2, string);
						DisablePlayerRaceCheckpoint(RaceDriversID[i]);
						RaceDriversID[i] = 255;
						RaceTimeM[i] = 0;
						RaceTimeS[i] = 0;
						strdel(RaceDrivers[i], 0, MAX_PLAYER_NAME);
					}
					PlayerRacePlace[i] = RacePlace;
				}
			}
			if(RaceDriversCount == 0)
			{
				DynamicRaces[RaceID][Started] = 0;
				IsAnyRaceStarted = 0;
				strdel(RaceOrganizator, 0, MAX_PLAYER_NAME);
				RacePlace = 0;
				RaceStarted = 0;
				RaceID = 255;
				SaveDynamicRaces();
			}
			if(RaceTimeM[i] >= 10)
			{
				for(new j = 0; j <= DynamicRaces[RaceID][MaxDrivers]; j++)
				{
					GetPlayerName(RaceDriversID[j], tmpname, sizeof(tmpname));
					printf("RaceDrivers[j]: %s, TMP name: %s", RaceDrivers[j], tmpname);
					DisablePlayerRaceCheckpoint(RaceDriversID[j]);
					if(strcmp(tmpname, RaceDrivers[j], true, strlen(tmpname)) == 0 && RacePrize == 0)
					{
						SendClientMessage(RaceDriversID[j], COLOR_LIGHTYELLOW2, "[INFO:] Nie ukoñczy³eœ wyœcigu w ci¹gu 10 minut, zostajesz zdyskwalifikowany.");
					}
					else if(strcmp(tmpname, RaceDrivers[j], true, strlen(tmpname)) == 0 && RacePrize > 0)
					{
						SendClientMessage(RaceDriversID[j], COLOR_LIGHTYELLOW2, "[INFO:] Wyœcig zosta³ przerwany z powodu z byt d³ugiego trwania. Pieni¹dze zosta³y zwrócone.");
						GivePlayerCash(RaceDriversID[j],  DynamicRaces[RaceID][EnterPrice]);
					}
					RaceDriversID[j] = 255;
					RaceTimeM[j] = 0;
					RaceTimeS[j] = 0;
					strdel(RaceDrivers[j], 0, MAX_PLAYER_NAME);
				}
				DynamicRaces[RaceID][Started] = 0;
				IsAnyRaceStarted = 0;
				strdel(RaceOrganizator, 0, MAX_PLAYER_NAME);
				RacePlace = 0;
				RaceStarted = 0;
				RaceDriversCount = 0;
				RaceID = 255;
				SaveDynamicRaces();
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

VehicleCrack(playerid, vehicleid)
{
	//print("[TIMERCHECK:] VehicleCrack(playerid, vehicleid)");
	new string[128];

	gPlayerData[playerid][JemmyUses]--;

	randomlock[playerid] = random(100);

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
			gPlayerData[playerid][pExp]++;
			gPlayerData[playerid][pCarJackerJobPoints] = 0;

			SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] Osi¹gn¹³eœ %d poziom jako z³odziej pojazdów !");

			if(gPlayerData[playerid][pExp] >= (gPlayerData[playerid][pLevel]+1)*levelexp)
			{
				gPlayerData[playerid][pLevel]++;
				gPlayerData[playerid][pExp] = 0;

				SavePlayerData(playerid, "Level");
				SavePlayerData(playerid, "Exp");

				format(string, sizeof(string), "[INFO:] Zdoby³eœ tak¿e nowy poziom postaci ! - %d", gPlayerData[playerid][pLevel]);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Otrzymujesz tak¿e 1pkt do doœwiadczenia !");
			}
		}

		SavePlayerData(playerid, "CarJackerJobLvl");
		SavePlayerData(playerid, "CarJackerJobPoints");
		SavePlayerData(playerid, "JemmyUses");

		return 1;
	}
	else
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie uda³o Ci siê otworzyæ pojazdu");
		return 1;
	}
}

VehicleCrack2(playerid, vehicleid)
{
	//print("[TIMERCHECK:] VehicleCrack2(playerid, vehicleid)");
	new string[128];

	gPlayerData[playerid][JemmyUses]--;

	randomlock[playerid] = random(100);

	if(random(100) >= random(100))
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
			gPlayerData[playerid][pExp]++;
			gPlayerData[playerid][pCarJackerJobPoints] = 0;

			SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] Osi¹gn¹³eœ %d poziom jako z³odziej pojazdów !");

			if(gPlayerData[playerid][pExp] >= (gPlayerData[playerid][pLevel]+1)*levelexp)
			{
				gPlayerData[playerid][pLevel]++;
				gPlayerData[playerid][pExp] = 0;

				SavePlayerData(playerid, "Level");
				SavePlayerData(playerid, "Exp");

				format(string, sizeof(string), "[INFO:] Zdoby³eœ tak¿e nowy poziom postaci ! - %d", gPlayerData[playerid][pLevel]);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Otrzymujesz tak¿e 1pkt do doœwiadczenia !");
			}
		}

		SavePlayerData(playerid, "CarJackerJobLvl");
		SavePlayerData(playerid, "CarJackerJobPoints");
		SavePlayerData(playerid, "JemmyUses");

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

Delay:GiveGunTimer[120000, i](playerid)
{
	gunGiven[playerid] = 0;
}

Delay:PaintTimer[10000, d](vehicleid)
{
	isPainting[vehicleid] = 0;
	return 1;
}

Delay:WheelChangingTimer[20000, d](vehicleid)
{
	isWheelChanging[vehicleid] = 0;
	return 1;
}

Delay:GasChangingTimer[20000, d](vehicleid)
{
	isGasMounting[vehicleid] = 0;
	return 1;
}

Delay:CarAlarmOff[1000, d](vehicleid)
{
	new enginedyn,lights,alarm,doors,bonnet,boot,objective;
	GetVehicleParamsEx(vehicleid,enginedyn,lights,alarm,doors,bonnet,boot,objective);
	SetVehicleParamsEx(vehicleid,enginedyn,0,0,doors,bonnet,boot,objective);
	return 1;
}

Delay:DestroyFactory[10000, dd]( fID, fDID )
{
	// new Float:px, Float:py, Float:pz;
	// px = DynamicFactions[fID][WFactoryCentrePosX];
	// py = DynamicFactions[fID][WFactoryCentrePosY];
	// pz = DynamicFactions[fID][WFactoryCentrePosZ];
	// if( DynamicFactions[fID][WFactoryBurning] == 0 )
	// {
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][1] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][2] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][3] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][4] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][5] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][6] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][7] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][8] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][9] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][10] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][11] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][12] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][13] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][14] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][15] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][16] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][17] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][18] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][19] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][20] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][21] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][22] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][23] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][24] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][25] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][26] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][27] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][28] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][29] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][30] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][31] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][32] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][33] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][34] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][35] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][36] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][37] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][38] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][39] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][40] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][41] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][55] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][42] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][43] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][44] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][45] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][46] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][47] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][48] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][49] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][50] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][51] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][52] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][53] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][54] );
	// }
	// if( DynamicFactions[fID][WFactoryBurning] == 1 )
	// {
		// DynamicFactions[fID][WFactoryBurning] = 2;
		// DynamicFactions[fID][WFactoryDObjects][1] = CreateDynamicObject(18688,px+3.51809835,py+-6.28747177,pz+-1.08281255,0.00000000,0.00000000,0.00000000,0,0,-1,250);
		// DynamicFactions[fID][WFactoryDObjects][2] = CreateDynamicObject(18688,px+2.15382385,py+-5.91271210,pz+-1.08281255,0.00000000,0.00000000,0.00000000,0,0,-1,250);
		// DynamicFactions[fID][WFactoryDObjects][3] = CreateDynamicObject(18688,px+-2.08829880,py+-5.81902885,pz+-1.08281255,0.00000000,0.00000000,0.00000000,0,0,-1,250);
		// DynamicFactions[fID][WFactoryDObjects][4] = CreateDynamicObject(18688,px+-3.32890749,py+-5.96794510,pz+-1.08281255,0.00000000,0.00000000,0.00000000,0,0,-1,250);
		// DynamicFactions[fID][WFactoryDObjects][5] = CreateDynamicObject(18688,px+-3.34380007,py+-0.94286251,pz+-1.08281255,0.00000000,0.00000000,0.00000000,0,0,-1,250);
		// DynamicFactions[fID][WFactoryDObjects][6] = CreateDynamicObject(18727,px+5.63071442,py+5.99838924,pz+1.06058848,0.00000000,0.00000000,0.00000000,0,0,-1,250);
		// DynamicFactions[fID][WFactoryDObjects][7] = CreateDynamicObject(18727,px+-5.03250837,py+10.41282463,pz+1.01058853,0.00000000,0.00000000,0.00000000,0,0,-1,250);
	// }
	// if( DynamicFactions[fID][WFactoryBurning] == 2 )
	// {
		// DynamicFactions[fID][WFactoryBurning] = 3;
		// DynamicFactions[fID][WFactoryDObjects][8] = CreateDynamicObject(18688,px+-3.87802267,py+3.12296534,pz+-1.08281255,0.00000000,0.00000000,0.00000000);
		// DynamicFactions[fID][WFactoryDObjects][9] = CreateDynamicObject(18688,px+-1.90487027,py+7.50037003,pz+-1.08281255,0.00000000,0.00000000,0.00000000);
		// DynamicFactions[fID][WFactoryDObjects][10] = CreateDynamicObject(18688,px+0.88364732,py+7.69967270,pz+-1.08281255,0.00000000,0.00000000,0.00000000);
		// DynamicFactions[fID][WFactoryDObjects][11] = CreateDynamicObject(18688,px+3.60534906,py+3.74317360,pz+-1.08281255,0.00000000,0.00000000,0.00000000);
		// DynamicFactions[fID][WFactoryDObjects][12] = CreateDynamicObject(18688,px+3.58199930,py+4.53341341,pz+-1.08281255,0.00000000,0.00000000,0.00000000);
		// DynamicFactions[fID][WFactoryDObjects][13] = CreateDynamicObject(18727,px+-2.27175093,py+-7.85546255,pz+1.01058853,0.00000000,0.00000000,0.00000000);
		// DynamicFactions[fID][WFactoryDObjects][14] = CreateDynamicObject(18727,px+2.10430861,py+-7.61335039,pz+1.01058853,0.00000000,0.00000000,0.00000000);
		// DynamicFactions[fID][WFactoryDObjects][15] = CreateDynamicObject(18727,px+-5.71557283,py+5.78334713,pz+1.01058853,0.00000000,0.00000000,0.00000000);

		// DestroyFactory( fID, fDID );
	// }
	// else if( DynamicFactions[fID][WFactoryBurning] == 3 )
	// {
		// DynamicFactions[fID][WFactoryBurning] = 4;
		// DynamicFactions[fID][WFactoryDObjects][16] = CreateDynamicObject(18688,px+3.79568839,py+-2.53902864,pz+-1.08281255,0.00000000,0.00000000,0.00000000);
		// DynamicFactions[fID][WFactoryDObjects][17] = CreateDynamicObject(18688,px+4.92002869,py+0.26532960,pz+-1.08281255,0.00000000,0.00000000,0.00000000);
		// DynamicFactions[fID][WFactoryDObjects][18] = CreateDynamicObject(18688,px+-4.60537052,py+5.25028896,pz+-1.08281255,0.00000000,0.00000000,0.00000000);
		// DynamicFactions[fID][WFactoryDObjects][19] =CreateDynamicObject(18727,px+5.09636688,py+10.72340584,pz+1.01058853,0.00000000,0.00000000,0.00000000);
		// DynamicFactions[fID][WFactoryDObjects][20] = CreateDynamicObject(18727,px+-5.97128963,py+-4.03578281,pz+1.01058853,0.00000000,0.00000000,0.00000000);
		// DynamicFactions[fID][WFactoryDObjects][21] = CreateDynamicObject(18727,px+5.97105122,py+-7.07275867,pz+1.01058853,0.00000000,0.00000000,0.00000000);
		// DestroyFactory( fID, fDID );
	// }
	// else if( DynamicFactions[fID][WFactoryBurning] == 4 )
	// {
		// DynamicFactions[fID][WFactoryBurning] = 5;
		// DynamicFactions[fID][WFactoryDObjects][22] = CreateDynamicObject(18685,px+3.06152511,py+-6.05036736,pz+0.12812500,0.00000000,0.00000000,0.00000000);
		// DynamicFactions[fID][WFactoryDObjects][23] =CreateDynamicObject(18685,px+4.38275623,py+-2.45808172,pz+0.12812500,0.00000000,0.00000000,0.00000000);
		// DynamicFactions[fID][WFactoryDObjects][24] = CreateDynamicObject(18685,px+-2.33152175,py+-5.62697363,pz+0.12812500,0.00000000,0.00000000,0.00000000);
		// DynamicFactions[fID][WFactoryDObjects][25] = CreateDynamicObject(18685,px+0.93585062,py+8.30728245,pz+0.12812500,0.00000000,0.00000000,356.00000000);
		// DynamicFactions[fID][WFactoryDObjects][26] = CreateDynamicObject(18688,px+4.02942276,py+0.13488016,pz+-1.08281255,0.00000000,0.00000000,0.00000000);
		// DynamicFactions[fID][WFactoryDObjects][27] = CreateDynamicObject(18688,px+4.46142387,py+-4.58122444,pz+-1.08281255,0.00000000,0.00000000,0.00000000);
		// DynamicFactions[fID][WFactoryDObjects][28] = CreateDynamicObject(18688,px+2.07426405,py+-6.03579903,pz+-1.08281255,0.00000000,0.00000000,0.00000000);

		// DestroyFactory( fID, fDID );
	// }
	// else if( DynamicFactions[fID][WFactoryBurning] == 5 )
	// {
		// DynamicFactions[fID][WFactoryBurning] = 6;
		// DynamicFactions[fID][WFactoryDObjects][29] = CreateDynamicObject(18688,px+-1.96972919,py+-6.11529064,pz+-1.08281255,0.00000000,0.00000000,0.00000000);
		// DynamicFactions[fID][WFactoryDObjects][30] = CreateDynamicObject(18688,px+-3.65178037,py+-4.29829454,pz+-1.08281255,0.00000000,0.00000000,0.00000000); // DYM
		// DynamicFactions[fID][WFactoryDObjects][31] = CreateDynamicObject(18688,px+-4.04132223,py+5.34731293,pz+-1.08281255,0.00000000,0.00000000,0.00000000);

		// DestroyFactory( fID, fDID );
	// }
	// else if( DynamicFactions[fID][WFactoryBurning] == 6 )
	// {
		// DynamicFactions[fID][WFactoryBurning] = 7;
		// DynamicFactions[fID][WFactoryDObjects][32] = CreateDynamicObject(18691,px-0.08842524,py-8.07476234,pz+4.81373739,0.00000000,0.00000000,0.00000000); //Object number 0
		// DynamicFactions[fID][WFactoryDObjects][33] = CreateDynamicObject(18690,px-3.83491707,py-11.80510044,pz+1.41718745,0.00000000,0.00000000,0.00000000); //Object number 1
		// DynamicFactions[fID][WFactoryDObjects][34] = CreateDynamicObject(18688,px-1.80454016,py-6.99040127,pz-1.08281207,0.00000000,0.00000000,0.00000000); //Object number 2

		// DestroyFactory( fID, fDID );
	// }
	// else if( DynamicFactions[fID][WFactoryBurning] == 7 )
	// {
		// DynamicFactions[fID][WFactoryBurning] = 8;
		// DynamicFactions[fID][WFactoryDObjects][35] = CreateDynamicObject(18688,px+-2.20555925,py+7.93822575,pz+-1.08281255,0.00000000,0.00000000,0.00000000); //Object number 3
		// DynamicFactions[fID][WFactoryDObjects][36] = CreateDynamicObject(18688,px+2.09640694,py+7.23771858,pz+-1.08281255,0.00000000,0.00000000,0.00000000); //Object number 4
		// DynamicFactions[fID][WFactoryDObjects][37] = CreateDynamicObject(18688,px+4.07061195,py+5.35370541,pz+-1.08281255,0.00000000,0.00000000,0.00000000); //Object number 5

		// DestroyFactory( fID, fDID );
	// }
	// else if( DynamicFactions[fID][WFactoryBurning] == 8 )
	// {
		// DynamicFactions[fID][WFactoryBurning] = 9;
		// DynamicFactions[fID][WFactoryDObjects][38] = CreateDynamicObject(18688,px+7.26077890,py+-5.29881668,pz+-1.08281255,0.00000000,0.00000000,0.00000000); //Object number 6
		// DynamicFactions[fID][WFactoryDObjects][39] = CreateDynamicObject(18688,px+7.38368750,py+-2.01982164,pz+-1.08281255,0.00000000,0.00000000,0.00000000); //Object number 7
		// DynamicFactions[fID][WFactoryDObjects][40] = CreateDynamicObject(18688,px+7.52604151,py+2.71459961,pz+-1.08281255,0.00000000,0.00000000,0.00000000); //Object number 8
		// DynamicFactions[fID][WFactoryDObjects][41] = CreateDynamicObject(18688,px+7.60581112,py+7.50650978,pz+-1.08281255,0.00000000,0.00000000,0.00000000); //Object number 3

		// DestroyFactory( fID, fDID );
	// }
	// else if( DynamicFactions[fID][WFactoryBurning] == 9 )
	// {
		// DynamicFactions[fID][WFactoryBurning] = 10;
		// DynamicFactions[fID][WFactoryDObjects][42] = CreateDynamicObject(18727,px+0.13985056,py+5.88873529,pz+1.01058853,0.00000000,0.00000000,0.00000000); //Object number 10
		// DynamicFactions[fID][WFactoryDObjects][43] = CreateDynamicObject(18727,px+0.22189075,py+-4.72055721,pz+1.01058853,0.00000000,0.00000000,0.00000000); //Object number 11
		// DynamicFactions[fID][WFactoryDObjects][44] = CreateDynamicObject(18688,px+4.26882935,py+7.92933512,pz+2.91718769,0.00000000,0.00000000,0.00000000); //Object number 12
		// DynamicFactions[fID][WFactoryDObjects][45] = CreateDynamicObject(18688,px+4.50096512,py+0.92676902,pz+2.91718769,0.00000000,0.00000000,0.00000000); //Object number 13
		// DynamicFactions[fID][WFactoryDObjects][46] = CreateDynamicObject(18688,px+3.55468059,py+-5.95523930,pz+2.91718769,0.00000000,0.00000000,0.00000000); //Object number 14
		// DynamicFactions[fID][WFactoryDObjects][47] = CreateDynamicObject(18688,px+-4.45439005,py+-6.22060680,pz+2.91718769,0.00000000,0.00000000,0.00000000); //Object number 15
		// DynamicFactions[fID][WFactoryDObjects][48] = CreateDynamicObject(18688,px+-4.02879047,py+0.98733354,pz+2.91718769,0.00000000,0.00000000,0.00000000); //Object number 16
		// DynamicFactions[fID][WFactoryDObjects][49] = CreateDynamicObject(18688,px+-4.13882923,py+7.84502697,pz+2.91718769,0.00000000,0.00000000,0.00000000); //Object number 17
		// DynamicFactions[fID][WFactoryDObjects][50] = CreateDynamicObject(18688,px+-3.14181685,py+11.53678513,pz+2.19218493,0.00000000,0.00000000,0.00000000); //Object number 18
		// DynamicFactions[fID][WFactoryDObjects][51] = CreateDynamicObject(18688,px+-0.14819607,py+11.33732605,pz+2.09218454,0.00000000,0.00000000,0.00000000); //Object number 19
		// DynamicFactions[fID][WFactoryDObjects][52] = CreateDynamicObject(18688,px+3.51605368,py+11.41932201,pz+2.59218454,0.00000000,0.00000000,0.00000000); //Object number 20
		// DynamicFactions[fID][WFactoryDObjects][53] = CreateDynamicObject(18688,px+0.12142569,py+-3.06669521,pz+5.16718769,0.00000000,0.00000000,0.00000000); //Object number 21
		// DynamicFactions[fID][WFactoryDObjects][54] = CreateDynamicObject(18688,px+-0.40233070,py+4.41530561,pz+5.16718769,0.00000000,0.00000000,0.00000000); //Object number 22

		// DestroyFactory( fID, fDID );
	// }
	// else if( DynamicFactions[fID][WFactoryBurning] == 10 )
	// {
		// DynamicFactions[fID][WFactoryBurning] = 11;
		// DynamicFactions[fID][WFactoryDObjects][55] = CreateDynamicObject(18682,px+0.12921290,py+1.85947990,pz+0.12812500,0.00000000,0.00000000,0.00000000); //Object number 23
		// DestroyFactory( fID, fDID );
	// }
	// else if( DynamicFactions[fID][WFactoryBurning] == 11 )
	// {
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][1] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][2] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][3] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][4] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][5] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][6] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][7] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][8] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][9] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][10] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][11] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][12] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][13] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][14] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][15] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][16] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][17] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][18] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][19] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][20] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][21] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][22] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][23] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][24] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][25] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][26] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][27] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][28] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][29] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][30] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][31] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][32] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][33] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][34] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][35] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][36] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][37] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][38] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][39] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][40] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][41] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][55] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][42] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][43] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][44] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][45] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][46] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][47] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][48] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][49] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][50] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][51] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][52] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][53] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryDObjects][54] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryObjects][0] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryObjects][1] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryObjects][2] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryObjects][3] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryObjects][4] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryObjects][5] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryObjects][6] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryObjects][7] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryObjects][8] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryObjects][9] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryObjects][10] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryObjects][11] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryObjects][12] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryObjects][13] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryObjects][14] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryObjects][15] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryObjects][16] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryObjects][17] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryObjects][18] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryObjects][19] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryObjects][20] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryObjects][21] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryObjects][22] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryObjects][23] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryObjects][24] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryObjects][25] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryObjects][26] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryObjects][27] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryObjects][28] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryObjects][29] );
		// DestroyDynamicObject( DynamicFactions[fID][WFactoryObjects][30] );
		// DestroyDynamicCP( DynamicFactions[fID][WFactoryCPPartSetup1ID] );
		// DestroyDynamicCP( DynamicFactions[fID][WFactoryCPPartSetup2ID] );
		// DestroyDynamicCP( DynamicFactions[fID][WFactoryCPAmmoPartSetup1ID] );
		// DestroyDynamicCP( DynamicFactions[fID][WFactoryCPPartTakeID]  );
		// DestroyDynamicCP( DynamicFactions[fID][WFactoryCPAmmoPartSetup2ID] );
		// DynamicFactions[fID][WFactoryObjects][0] = 0;
		// DynamicFactions[fID][WFactoryObjects][1] = 0;
		// DynamicFactions[fID][WFactoryObjects][2] = 0;
		// DynamicFactions[fID][WFactoryObjects][3] = 0;
		// DynamicFactions[fID][WFactoryObjects][4] = 0;
		// DynamicFactions[fID][WFactoryObjects][5] = 0;
		// DynamicFactions[fID][WFactoryObjects][6] = 0;
		// DynamicFactions[fID][WFactoryObjects][7] = 0;
		// DynamicFactions[fID][WFactoryObjects][8] = 0;
		// DynamicFactions[fID][WFactoryObjects][9] = 0;
		// DynamicFactions[fID][WFactoryObjects][10] = 0;
		// DynamicFactions[fID][WFactoryObjects][11] = 0;
		// DynamicFactions[fID][WFactoryObjects][12] = 0;
		// DynamicFactions[fID][WFactoryObjects][13] = 0;
		// DynamicFactions[fID][WFactoryObjects][14] = 0;
		// DynamicFactions[fID][WFactoryObjects][15] = 0;
		// DynamicFactions[fID][WFactoryObjects][16] = 0;
		// DynamicFactions[fID][WFactoryObjects][17] = 0;
		// DynamicFactions[fID][WFactoryObjects][18] = 0;
		// DynamicFactions[fID][WFactoryObjects][19] = 0;
		// DynamicFactions[fID][WFactoryObjects][20] = 0;
		// DynamicFactions[fID][WFactoryObjects][21] = 0;
		// DynamicFactions[fID][WFactoryObjects][22] = 0;
		// DynamicFactions[fID][WFactoryObjects][23] = 0;
		// DynamicFactions[fID][WFactoryObjects][24] = 0;
		// DynamicFactions[fID][WFactoryObjects][25] = 0;
		// DynamicFactions[fID][WFactoryObjects][26] = 0;
		// DynamicFactions[fID][WFactoryObjects][27] = 0;
		// DynamicFactions[fID][WFactoryObjects][28] = 0;
		// DynamicFactions[fID][WFactoryObjects][29] = 0;
		// DynamicFactions[fID][WFactoryObjects][30] = 0;
		// DynamicFactions[fID][WFactoryBurning] = 0;
		// DynamicFactions[fID][WFactoryCentrePosX] = 0;
		// DynamicFactions[fID][WFactoryCentrePosY] = 0;
		// DynamicFactions[fID][WFactoryCentrePosZ] = 0;
		// if( DynamicFactions[fDID][fType] == 1 )
		// {
			// DynamicFactions[fDID][fBank] += WFACTORY_DES_REW_FACTION;
			// DynamicFactions[FACTIONID_GOVERNMENT][fBank] -= WFACTORY_DES_REW_FACTION;
		// }
		// SaveFData( fDID, "Bank" );
		// SaveFData( FACTIONID_GOVERNMENT, "Bank" );
		// SaveFData( fID, "WFactoryBurning" );
		// SaveFData( fID, "WFactoryObjects" );
		// SaveFData( fID, "WFactoryCentrePosX" );
		// SaveFData( fID, "WFactoryCentrePosY" );
		// SaveFData( fID, "WFactoryCentrePosZ" );
	// }

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

		DestroyFactory( fID, fDID );
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
		DestroyFactory( fID, fDID );
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

		DestroyFactory( fID, fDID );
	}
	else if( DynamicFactions[fID][WFactoryBurning] == 5 )
	{
		DynamicFactions[fID][WFactoryBurning] = 6;
		DynamicFactions[fID][WFactoryDObjects][29] = CreateDynamicObject(18688,px+-1.96972919,py+-6.11529064,pz+-1.08281255,0.00000000,0.00000000,0.00000000);
		DynamicFactions[fID][WFactoryDObjects][30] = CreateDynamicObject(18688,px+-3.65178037,py+-4.29829454,pz+-1.08281255,0.00000000,0.00000000,0.00000000); // DYM
		DynamicFactions[fID][WFactoryDObjects][31] = CreateDynamicObject(18688,px+-4.04132223,py+5.34731293,pz+-1.08281255,0.00000000,0.00000000,0.00000000);

		DestroyFactory( fID, fDID );
	}
	else if( DynamicFactions[fID][WFactoryBurning] == 6 )
	{
		DynamicFactions[fID][WFactoryBurning] = 7;
		DynamicFactions[fID][WFactoryDObjects][32] = CreateDynamicObject(18688,px+-2.20555925,py+7.93822575,pz+-1.08281255,0.00000000,0.00000000,0.00000000); //Object number 0
		DynamicFactions[fID][WFactoryDObjects][33] = CreateDynamicObject(18688,px+2.09640694,py+7.23771858,pz+-1.08281255,0.00000000,0.00000000,0.00000000); //Object number 1
		DynamicFactions[fID][WFactoryDObjects][34] = CreateDynamicObject(18688,px+4.07061195,py+5.35370541,pz+-1.08281255,0.00000000,0.00000000,0.00000000); //Object number 2

		DestroyFactory( fID, fDID ); // poprawione
	}
	else if( DynamicFactions[fID][WFactoryBurning] == 7 )
	{
		DynamicFactions[fID][WFactoryBurning] = 8;
		DynamicFactions[fID][WFactoryDObjects][35] = CreateDynamicObject(18688,px+7.26077890,py+-5.29881668,pz+-1.08281255,0.00000000,0.00000000,0.00000000); //Object number 3
		DynamicFactions[fID][WFactoryDObjects][36] = CreateDynamicObject(18688,px+7.38368750,py+-2.01982164,pz+-1.08281255,0.00000000,0.00000000,0.00000000); //Object number 4
		DynamicFactions[fID][WFactoryDObjects][37] = CreateDynamicObject(18688,px+7.52604151,py+2.71459961,pz+-1.08281255,0.00000000,0.00000000,0.00000000); //Object number 5
		DynamicFactions[fID][WFactoryDObjects][38]  = CreateDynamicObject(18688,px+7.60581112,py+7.50650978,pz+-1.08281255,0.00000000,0.00000000,0.00000000);

		DestroyFactory( fID, fDID ); // poprawione
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

		DestroyFactory( fID, fDID );  //poprawione
	}
	else if( DynamicFactions[fID][WFactoryBurning] == 9 )
	{
		DynamicFactions[fID][WFactoryBurning] = 10;
		DynamicFactions[fID][WFactoryDObjects][47] = CreateDynamicObject(18688,px+-3.14181685,py+11.53678513,pz+2.19218493,0.00000000,0.00000000,0.00000000);
		DynamicFactions[fID][WFactoryDObjects][48] = CreateDynamicObject(18688,px+-0.14819607,py+11.33732605,pz+2.09218454,0.00000000,0.00000000,0.00000000);
		DynamicFactions[fID][WFactoryDObjects][49] = CreateDynamicObject(18688,px+3.51605368,py+11.41932201,pz+2.59218454,0.00000000,0.00000000,0.00000000);
		DynamicFactions[fID][WFactoryDObjects][50] = CreateDynamicObject(18688,px+0.12142569,py+-3.06669521,pz+5.16718769,0.00000000,0.00000000,0.00000000);
		DynamicFactions[fID][WFactoryDObjects][51] = CreateDynamicObject(18688,px+-0.40233070,py+4.41530561,pz+5.16718769,0.00000000,0.00000000,0.00000000);
		DestroyFactory( fID, fDID ); //poprawione
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
		DestroyFactory( fID, fDID ); //poprawione
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
		DestroyFactory( fID, fDID ); //poprawione
	}
	else if( DynamicFactions[fID][WFactoryBurning] == 12 )
	{
		DynamicFactions[fID][WFactoryBurning] = 13;
		// Audio_Play(playerid, 1159, false, false, false);
		DynamicFactions[fID][WFactoryDObjects][66] = CreateDynamicObject(18682,px+6.67809105,py+-5.72583961,pz+2.37812519,0.00000000,0.00000000,0.00000000,0,0,-1,250);
		DynamicFactions[fID][WFactoryDObjects][67] = CreateDynamicObject(18682,px+7.04398727,py+0.01818210,pz+2.37812519,0.00000000,0.00000000,0.00000000,0,0,-1,250);
		DynamicFactions[fID][WFactoryDObjects][68] = CreateDynamicObject(18682,px+-1.44621408,py+10.38482857,pz+1.37812519,0.00000000,0.00000000,0.00000000,0,0,-1,250);
		DynamicFactions[fID][WFactoryDObjects][69] = CreateDynamicObject(18682,px+-1.70082259,py+10.81455040,pz+1.37812519,0.00000000,0.00000000,0.00000000,0,0,-1,250);
		DestroyFactory( fID, fDID );  // poprawione
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

Delay:RPC[8500, i](playerid)
{
	SetPlayerHealth( playerid, 30.0 );
	gPlayerData[playerid][pHP] = 30.0;
	SavePlayerData( playerid, "HP" );
	TogglePlayerControllable( playerid,1 );
	SetCameraBehindPlayer( playerid );
	// ApplyAnimation(playerid,"PED","SEAT_up",4.0, 0, 1, 1, 0, 0);
	ApplyAnimation(playerid,"PED","getup",4.0,0,0,0,0,0);
	if(PlayerCuffed[playerid])
		TogglePlayerControllable(playerid,0);
	SendClientMessage(playerid, COLOR_GREEN, "[INFO:] Reanimacja powiod³a siê, stan stabilny !");
	TextDrawShowForPlayer(playerid, Status[playerid]);
	if(gPlayerData[playerid][pFirstReanimation])
		SendClientMessage(playerid, COLOR_GREEN, "[INFO:] Reanimacja powiod³a siê, wróci³eœ do ¿ywych !");
	else
	{
		SendClientMessage(playerid, COLOR_GREEN, "[INFO:] Bêdziesz ¿y³ ! Reanimacja powiod³a siê !");
		AddExpPoint(playerid);
		gPlayerData[playerid][pFirstReanimation] = 1;
		SavePlayerData(playerid, "FirstReanimation");
	}
	gPlayerData[playerid][pCharacterDying] = 0;
	SavePlayerData( playerid, "CharacterDying" );
	return 1;
}