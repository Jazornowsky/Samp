/***
*
* File: wp_fuel.inc
* Auth: Damian Wojdat
* Date: 15.09.2011
* Desc: Declarations, macros and variables.
*
*************************************************************************************************************/

public RefuelingCanister(playerid, Float:refillvalue, slot, gasStationID, Float:xpos, Float:ypos, Float:zpos)
{
	if(!PlayerToPoint(2.0,playerid,xpos, ypos, zpos))
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Odsun¹³eœ siê zbyt daleko od stacji ! Tankowania przerwane. ");
		return 1;
	}
	new string[128];
	if( SlotParam1(playerid, slot) >= 25 )
	{
		format(string, sizeof(string), "Zatankowano kanister na %.1fltr za $%d.\n\nAby op³aciæ paliwo przejdŸ do kasy znajduj¹cej siê w budynku stacji.", refillvalue, floatround(refillvalue * GasStations[gasStationID][PetrolPrice]) );
		ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Stacja benzynowa", string, "Zamknij", "" );
		return 1;
	}	
	switch( SlotParam2(playerid, slot) )
	{
		case 0: // benzyna
		{
			if( GasStations[gasStationID][PetrolResourceValue] <= 0 )
			{
				format(string, sizeof(string), "Tankowanie przerwane - zabrak³o paliwa na stacji.\nDo kanistra zatankowano %.1fltr za $%d.",
				refillvalue, GasStations[gasStationID][PetrolPrice]);
				ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Stacja benzynowa", string, "Zamknij", "" );
				return 1;
			}
			GasStations[gasStationID][PetrolResourceValue] -= FUEL_REFUEL_STEP_CNSTR; 
			gPlayerData[playerid][pGasStationRefPetrol][ GasStations[gasStationID][BusinessID] ] += FUEL_REFUEL_STEP_CNSTR;
			refillvalue += FUEL_REFUEL_STEP_CNSTR;
			format( string, sizeof( string ), "Zatankowano %.1fltr, koszt: $%d", 
			refillvalue, floatround(refillvalue * GasStations[gasStationID][PetrolPrice]));
			GameTextForPlayer( playerid, string, 2000, GAME_TEXT_STYLE_4 );
			SavePlayerData( playerid, "GasStationRefPetrol", GasStations[gasStationID][BusinessID] );
		}
		case 1: // ropa
		{
			if( GasStations[gasStationID][OilResourceValue] <= 0 )
			{
				format(string, sizeof(string), "Tankowanie przerwane - zabrak³o paliwa na stacji.\nDo kanistra zatankowano %.1fltr za $%d.",
				refillvalue, GasStations[gasStationID][OilPrice]);
				ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Stacja benzynowa", string, "Zamknij", "" );
				return 1;
			}
			GasStations[gasStationID][OilResourceValue] -= FUEL_REFUEL_STEP_CNSTR; 
			gPlayerData[playerid][pGasStationRefOil][ GasStations[gasStationID][BusinessID] ] += FUEL_REFUEL_STEP_CNSTR;
			refillvalue += FUEL_REFUEL_STEP_CNSTR;
			format( string, sizeof( string ), "Zatankowano %.1fltr, koszt: $%d", 
			refillvalue, floatround(refillvalue * GasStations[gasStationID][OilPrice]));
			GameTextForPlayer( playerid, string, 2000, GAME_TEXT_STYLE_4 );
			SavePlayerData( playerid, "GasStationRefOil", GasStations[gasStationID][BusinessID] );
		}
	}
	SetTimerEx("RefuelingCanister", 2000, false, "idddfff", playerid, refillvalue, slot, gasStationID, xpos, ypos, zpos);
	SetPSlotParam1(playerid, slot, SlotParam1(playerid, slot) + floatround(FUEL_REFUEL_STEP_CNSTR) );
	SaveGasStations();
	SaveFuleStationData(gasStationID, "PetrolResourceValue");
	return 1;
}

public RefuelingVehicleCanister(playerid, vehicleid,Float:xpos,Float:ypos,Float:zpos)
{
	if(!PlayerToPoint(2.0,playerid,xpos,ypos,zpos))
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Odsun¹³eœ siê zbyt daleko od baku ! Tankowania przerwane. ");
		return 1;
	}
	if(gVehData[vehicleid][EngineOn])
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Silnik pojazdu jest uruchomiony ! Tankowanie przerwane !");
		return 1;
	}
	if(SlotParam1(playerid, gSelectedSlot[playerid]) == floatround(float(VehFTank(vehicleid)) - gVehData[vehicleid-1][CarFuel], floatround_round))
	{
		gVehData[vehicleid-1][CarFuel] = float(VehFTank(vehicleid));
		SetPSlotParam1(playerid, gSelectedSlot[playerid], 0);
		SaveVehData(vehicleid-1, "CarFuel");
	}
	else if(SlotParam1(playerid, gSelectedSlot[playerid]) > floatround(float(VehFTank(vehicleid)) - gVehData[vehicleid-1][CarFuel], floatround_round))
	{
		SetPSlotParam1(playerid, gSelectedSlot[playerid], SlotParam1(playerid, gSelectedSlot[playerid]) - floatround(float(VehFTank(vehicleid)) - gVehData[vehicleid-1][CarFuel], floatround_round));
		gVehData[vehicleid-1][CarFuel] = float(VehFTank(vehicleid));
		SaveVehData(vehicleid-1, "CarFuel");
	}
	else if(SlotParam1(playerid, gSelectedSlot[playerid]) < floatround(float(VehFTank(vehicleid)) - gVehData[vehicleid-1][CarFuel], floatround_round))
	{
		gVehData[vehicleid-1][CarFuel] += float(SlotParam1(playerid, gSelectedSlot[playerid]));
		SetPSlotParam1(playerid, gSelectedSlot[playerid], 0);
		SaveVehData(vehicleid-1, "CarFuel");
	}
	SendClientMessage(playerid, COLOR_LIGHTYELLOW, "[INFO:] Pojazd zosta³ zatankowany");
	return 1;
}

public RefuelVehicleFly(playerid, Float:refillvalue, Float:pPosX, Float:pPosY, Float:pPosZ, truckId, tlId, planeId)
{
	new string[512];
	
	if(!PlayerToPoint(1.0, playerid, pPosX, pPosY, pPosZ) || gVehData[truckId-1][EngineOn])
	{
		format(string, sizeof(string), "Przerwa³eœ tankowanie !\nPojazd zosta³ zatankowany na %dltr. Koszt paliwa: $%d.",
			floatround(refillvalue, floatround_round), floatround(refillvalue * gRafinery[RafFlyLtrCost], floatround_round));
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", string, "Zamknij", "");
		
		gVehData[tlId-1][TankerIsRefueling] = 0;
		
		return 1;
	}
	
	if(gVehData[planeId][CarFuel] >= float(VehFTank(planeId+1)))
	{
		format(string, sizeof(string), "Pojazd zosta³ zatankowany na %dltr. Koszt paliwa: $%d.",
			floatround(refillvalue, floatround_round), floatround(refillvalue * gRafinery[RafFlyLtrCost], floatround_round));
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Stacja benzynowa", string, "Zamknij", "");
		
		gVehData[tlId-1][TankerIsRefueling] = 0;
		
		return 1;
	}
	
	if(gVehData[tlId-1][TankerResourceValue] <= 0)
	{
		format(string, sizeof(string), "Tankowanie przerwane - cysterna jest pusta.\nPojazd zosta³ zatankowany na %dltr. Koszt paliwa: $%d.",
			floatround(refillvalue, floatround_round), floatround(refillvalue * gRafinery[RafFlyLtrCost], floatround_round));
		ShowPlayerDialog(playerid, DIALOG_REFUEL_VEH, DIALOG_STYLE_MSGBOX, "Stacja benzynowa", string, "Zamknij", "");
		return 1;
	}
	
	gVehData[tlId-1][TankerResourceValue] -= floatround(FUEL_REFUEL_STEP_CNSTR); 
	SaveVehData(tlId-1, "TankerResourceValue");
	
	refillvalue += FUEL_REFUEL_STEP_CNSTR;
	
	format(string, sizeof(string), "Zatankowano %dltr, koszt: $%d", floatround(refillvalue, floatround_round), floatround(refillvalue * gRafinery[RafFlyLtrCost], floatround_round));
	GameTextForPlayer(playerid, string, 1500, GAME_TEXT_STYLE_4);

	gVehData[tlId-1][TankerIsRefueling] = 0;
	
	gVehData[planeId][CarFuel] += FUEL_REFUEL_STEP_CNSTR;
	SaveVehData(planeId, "CarFuel");
	
	SetTimerEx("RefuelVehicleFly", 1000, false, "iffffddd", playerid, refillvalue, pPosX, pPosY, pPosZ, truckId, tlId, planeId);
	
	return 1;
}

public RefuelingVehicle(playerid, vehicleid, Float:refillvalue, gasStationID, Float:pPosX, Float:pPosY, Float:pPosZ)
{
	new form[512];
	
	if(!PlayerToPoint(1.0, playerid, pPosX, pPosY, pPosZ) || gVehData[vehicleid-1][EngineOn])
	{
		format(form, sizeof(form), "Przerwa³eœ tankowanie !\n\nTwój pojazd zosta³ zatankowany na %dltr za $%d.\n\nAby op³aciæ paliwo przejdŸ do kasy znajduj¹cej siê w budynku stacji.", floatround(refillvalue, floatround_round), floatround(refillvalue * GasStations[gasStationID][PetrolPrice], floatround_round));
		ShowPlayerDialog(playerid, DIALOG_REFUEL_VEH, DIALOG_STYLE_MSGBOX, "Stacja benzynowa", form, "Zamknij", "");
		
		gVehData[vehicleid-1][IsRefueling] = 0;
		
		SaveGasStations();
		
		SavePlayerData(playerid, "GasStationRefPetrol", GasStations[gasStationID][BusinessID]);
		SavePlayerData(playerid, "GasStationRefOil", GasStations[gasStationID][BusinessID]);
		SavePlayerData(playerid, "GasStationRefGas", GasStations[gasStationID][BusinessID]);
		
		return 1;
	}
	
	if(gVehData[vehicleid-1][CarFuel] >= float(VehFTank(vehicleid)))
	{
		format(form, sizeof(form), "vehicle id: %d, fuel type: %d", vehicleid, gVehData[vehicleid-1][Fuel]);
		SaveStatsData(form, gPlayerData[playerid][pName], floatround(refillvalue * GasStations[gasStationID][PetrolPrice], floatround_round), GasStations[gasStationID][BusinessID], Businesses[GasStations[gasStationID][BusinessID]][BizType]);
				
		format(form, sizeof(form), "Twój pojazd zosta³ zatankowany na %dltr za $%d.\n\nAby op³aciæ paliwo przejdŸ do kasy znajduj¹cej siê w budynku stacji.", floatround(refillvalue, floatround_round), floatround(refillvalue * GasStations[gasStationID][PetrolPrice], floatround_round));
		ShowPlayerDialog(playerid, DIALOG_REFUEL_VEH, DIALOG_STYLE_MSGBOX, "Stacja benzynowa", form, "Zamknij", "");
		
		gVehData[vehicleid-1][IsRefueling] = 0;
		
		SaveGasStations();
		
		SavePlayerData(playerid, "GasStationRefPetrol", GasStations[gasStationID][BusinessID]);
		SavePlayerData(playerid, "GasStationRefOil", GasStations[gasStationID][BusinessID]);
		SavePlayerData(playerid, "GasStationRefGas", GasStations[gasStationID][BusinessID]);
		
		return 1;
	}		
	
	switch(gVehData[vehicleid-1][Fuel])
	{
		case 0: 
		{	
			if(GasStations[gasStationID][PetrolResourceValue] <= 0)
			{
				format(form, sizeof(form), "Tankowanie przerwane - zabrak³o paliwa na stacji.\nTwój pojazd zosta³ zatankowany na %dltr za $%d.",floatround(refillvalue, floatround_round), floatround(refillvalue * GasStations[gasStationID][PetrolPrice], floatround_round));
				ShowPlayerDialog(playerid, DIALOG_REFUEL_VEH, DIALOG_STYLE_MSGBOX, "Stacja benzynowa", form, "Zamknij", "");
				
				SaveGasStations();
				
				SavePlayerData(playerid, "GasStationRefPetrol", GasStations[gasStationID][BusinessID]);
				SavePlayerData(playerid, "GasStationRefOil", GasStations[gasStationID][BusinessID]);
				SavePlayerData(playerid, "GasStationRefGas", GasStations[gasStationID][BusinessID]);
				
				return 1;
			}
			
			GasStations[gasStationID][PetrolResourceValue] -= FUEL_REFUEL_STEP; 
			
			gPlayerData[playerid][pGasStationRefPetrol][GasStations[gasStationID][BusinessID]] += FUEL_REFUEL_STEP;
			
			refillvalue += FUEL_REFUEL_STEP;
			
			format(form, sizeof(form), "Zatankowano %dltr, koszt: $%d", floatround(refillvalue, floatround_round),  floatround(refillvalue * GasStations[gasStationID][PetrolPrice], floatround_round));
			GameTextForPlayer(playerid, form, 1500, GAME_TEXT_STYLE_4);

			gVehData[vehicleid-1][IsRefueling] = 0;
		}
		case 1: 
		{
			if(GasStations[gasStationID][OilResourceValue] <= 0)
			{
				format(form, sizeof(form), "Tankowanie przerwane - zabrak³o paliwa na stacji.\nTwój pojazd zosta³ zatankowany na %ltr za $%d.",floatround(refillvalue, floatround_round), floatround(refillvalue * GasStations[gasStationID][OilPrice], floatround_round));
				ShowPlayerDialog(playerid, DIALOG_REFUEL_VEH, DIALOG_STYLE_MSGBOX, "Stacja benzynowa", form, "Zamknij", "");
				
				SaveGasStations();
				
				SavePlayerData(playerid, "GasStationRefPetrol", GasStations[gasStationID][BusinessID]);
				SavePlayerData(playerid, "GasStationRefOil", GasStations[gasStationID][BusinessID]);
				SavePlayerData(playerid, "GasStationRefGas", GasStations[gasStationID][BusinessID]);
				
				return 1;
			}
			
			GasStations[gasStationID][OilResourceValue] -= FUEL_REFUEL_STEP; 
			
			gPlayerData[playerid][pGasStationRefOil][GasStations[gasStationID][BusinessID]] += FUEL_REFUEL_STEP;
			
			refillvalue += FUEL_REFUEL_STEP;
			
			format(form, sizeof(form), "Zatankowano %dltr, koszt: $%d", floatround(refillvalue, floatround_round),  floatround(refillvalue * GasStations[gasStationID][OilPrice], floatround_round));
			GameTextForPlayer(playerid, form, 1500, GAME_TEXT_STYLE_4);
			
			SavePlayerData(playerid, "GasStationRefOil", GasStations[gasStationID][BusinessID]);
			
			gVehData[vehicleid-1][IsRefueling] = 0;
		}
		case 2: 
		{ 
			if(GasStations[gasStationID][GasResourceValue] <= 0)
			{
				format(form, sizeof(form), "Tankowanie przerwane - zabrak³o paliwa na stacji.\nTwój pojazd zosta³ zatankowany na %ltr za $%d.",floatround(refillvalue, floatround_round), floatround(refillvalue * GasStations[gasStationID][GasPrice], floatround_round));
				ShowPlayerDialog(playerid, DIALOG_REFUEL_VEH, DIALOG_STYLE_MSGBOX, "Stacja benzynowa", form, "Zamknij", "");
				
				SaveGasStations();
				
				SavePlayerData(playerid, "GasStationRefPetrol", GasStations[gasStationID][BusinessID]);
				SavePlayerData(playerid, "GasStationRefOil", GasStations[gasStationID][BusinessID]);
				SavePlayerData(playerid, "GasStationRefGas", GasStations[gasStationID][BusinessID]);
				
				return 1;
			}
			
			GasStations[gasStationID][GasResourceValue] -= FUEL_REFUEL_STEP; 
			
			gPlayerData[playerid][pGasStationRefGas][GasStations[gasStationID][BusinessID]] += FUEL_REFUEL_STEP;
			
			refillvalue += FUEL_REFUEL_STEP;
			
			format(form, sizeof(form), "Zatankowano %dltr, koszt: $%d", floatround(refillvalue, floatround_round),  floatround(refillvalue * GasStations[gasStationID][GasPrice], floatround_round));
			GameTextForPlayer(playerid, form, 1500, GAME_TEXT_STYLE_4);
			
			SavePlayerData(playerid, "GasStationRefGas", GasStations[gasStationID][BusinessID]);
			
			gVehData[vehicleid-1][IsRefueling] = 0;
		}
	}
	
	gVehData[vehicleid-1][CarFuel] += FUEL_REFUEL_STEP;
	SaveVehData(vehicleid-1, "CarFuel");
	
	SaveFuleStationData(gasStationID, "PetrolResourceValue");
	
	SetTimerEx("RefuelingVehicle", 1000, false, "idfdfff", playerid, vehicleid, refillvalue, gasStationID, pPosX, pPosY, pPosZ);
	
	return 1;
}

public DrainTankerFuel(playerid, Float:tankerX, Float:tankerY, Float:tankerZ)
{
	new vehID = GetPlayerVehicleID(playerid);
	new tlID = GetVehicleTrailer(vehID);
	/* Player left truck or moved truck */
	if(!(PlayerToPoint(4.0, playerid, tankerX, tankerY, tankerZ)))
	{
		gVehData[tlID-1][TankerIsRefueling] = 0;
		ShowPlayerDialog(playerid,
										DIALOG_RAF_RSC_CP_INFO_A,
										DIALOG_STYLE_MSGBOX,
										RAF_RSC_CP_MENU_HEADER,
										RAF_RSC_CP_MENU_DRAINED_B,
										RAF_RSC_CP_MENU_EXIT,
										"" );
		return 1;
	}
	/* Proper process of drain of tanker */
	new string[128];
	gVehData[tlID-1][TankerResourceValue]--;
	format(string, sizeof(string), "Odpompowywanie cysterny - %dl", gVehData[tlID-1][TankerResourceValue] );
	GameTextForPlayer( playerid, string, FUEL_TANKER_STEP, GAME_TEXT_STYLE_6 );
	SaveVehData(tlID-1, "TankerResourceValue" );
	switch( gVehData[tlID-1][TankerResourceType] )
	{
		case TANKER_TYPE_PETROL: { gRafinery[RafResourcePetrol]++; }
		case TANKER_TYPE_OIL: { gRafinery[RafResourceOil]++; }
		case TANKER_TYPE_GAS: { gRafinery[RafResourceGas]++; }
		case TANKER_TYPE_FLY: { gRafinery[RafResourceFly]++; }
	}
	SaveRafinery();
	if( gVehData[tlID-1][TankerResourceValue] == 0 )
	{
		gVehData[tlID-1][TankerIsRefueling] = 0;
		gVehData[tlID-1][TankerResourceType] = TANKER_TYPE_NONE;
		SaveVehData(tlID-1, "TankerResourceType");
		ShowPlayerDialog(playerid,
										DIALOG_RAF_RSC_CP_INFO_A,
										DIALOG_STYLE_MSGBOX,
										RAF_RSC_CP_MENU_HEADER,
										RAF_RSC_CP_MENU_DRAINED_A,
										RAF_RSC_CP_MENU_EXIT,
										"" );
		return 1;
	}
	else
		SetTimerEx("DrainTankerFuel", FUEL_TANKER_STEP, false, "ifff", playerid, tankerX, tankerY, tankerZ);
	return 1;
}

public FuelTankerPetrol(playerid, Float:tankerX, Float:tankerY, Float:tankerZ)
{
	new vehID = GetPlayerVehicleID(playerid);
	new tlID = GetVehicleTrailer(vehID);
	/* Player left truck or moved truck */
	if(!(PlayerToPoint(4.0, playerid, tankerX, tankerY, tankerZ)))
	{
		gVehData[tlID-1][TankerIsRefueling] = 0;
		ShowPlayerDialog(playerid,
										DIALOG_RAF_RSC_CP_INFO_A,
										DIALOG_STYLE_MSGBOX,
										RAF_RSC_CP_MENU_HEADER,
										RAF_RSC_CP_MENU_REFUELED_C,
										RAF_RSC_CP_MENU_EXIT,
										"" );
		return 1;
	}
	new string[64];
	if( gRafinery[RafResourcePetrol] > 0 )
	{
		gVehData[tlID-1][TankerResourceValue]++;
		gRafinery[RafResourcePetrol]--;
		format(string, sizeof(string), "Tankowanie cysterny - %dl/%dl", gVehData[tlID-1][TankerResourceValue], MAX_TANKER_RESOURCE_VALUE );
		GameTextForPlayer( playerid, string, FUEL_TANKER_STEP, GAME_TEXT_STYLE_6 );
		SaveVehData(tlID-1, "TankerResourceValue");
		SaveRafinery();
	}
	else
	{
		gVehData[tlID-1][TankerIsRefueling] = 0;
		ShowPlayerDialog(playerid,
										DIALOG_RAF_RSC_CP_INFO_A,
										DIALOG_STYLE_MSGBOX,
										RAF_RSC_CP_MENU_HEADER,
										RAF_RSC_CP_MENU_REFUELED_B,
										RAF_RSC_CP_MENU_EXIT,
										"" );
		return 1;
	}
	if( gVehData[tlID-1][TankerResourceValue] == MAX_TANKER_RESOURCE_VALUE )
	{
		gVehData[tlID-1][TankerIsRefueling] = 0;
		ShowPlayerDialog(playerid,
										DIALOG_RAF_RSC_CP_INFO_A,
										DIALOG_STYLE_MSGBOX,
										RAF_RSC_CP_MENU_HEADER,
										RAF_RSC_CP_MENU_REFUELED_A,
										RAF_RSC_CP_MENU_EXIT,
										"" );
		return 1;
	}
	else
		SetTimerEx("FuelTankerPetrol", FUEL_TANKER_STEP, false, "ifff", playerid, tankerX, tankerY, tankerZ);
	return 1;
}

public FuelTankerOil(playerid, Float:tankerX, Float:tankerY, Float:tankerZ)
{
	new vehID = GetPlayerVehicleID(playerid);
	new tlID = GetVehicleTrailer(vehID);
	/* Player left truck or moved truck */
	if(!(PlayerToPoint(4.0, playerid, tankerX, tankerY, tankerZ)))
	{
		gVehData[tlID-1][TankerIsRefueling] = 0;
		ShowPlayerDialog(playerid,
										DIALOG_RAF_RSC_CP_INFO_A,
										DIALOG_STYLE_MSGBOX,
										RAF_RSC_CP_MENU_HEADER,
										RAF_RSC_CP_MENU_REFUELED_C,
										RAF_RSC_CP_MENU_EXIT,
										"" );
		return 1;
	}
	new string[64];
	if( gRafinery[RafResourceOil] > 0 )
	{
		gVehData[tlID-1][TankerResourceValue]++;
		gRafinery[RafResourceOil]--;
		format(string, sizeof(string), "Tankowanie cysterny - %dl/%dl", gVehData[tlID-1][TankerResourceValue], MAX_TANKER_RESOURCE_VALUE );
		GameTextForPlayer( playerid, string, FUEL_TANKER_STEP, GAME_TEXT_STYLE_6 );
		SaveVehData(tlID-1, "TankerResourceValue");
		SaveRafinery();
	}
	else
	{
		gVehData[tlID-1][TankerIsRefueling] = 0;
		ShowPlayerDialog(playerid,
										DIALOG_RAF_RSC_CP_INFO_A,
										DIALOG_STYLE_MSGBOX,
										RAF_RSC_CP_MENU_HEADER,
										RAF_RSC_CP_MENU_REFUELED_B,
										RAF_RSC_CP_MENU_EXIT,
										"" );
		return 1;
	}
	if( gVehData[tlID-1][TankerResourceValue] >= MAX_TANKER_RESOURCE_VALUE )
	{
		gVehData[tlID-1][TankerIsRefueling] = 0;
		ShowPlayerDialog(playerid,
										DIALOG_RAF_RSC_CP_INFO_A,
										DIALOG_STYLE_MSGBOX,
										RAF_RSC_CP_MENU_HEADER,
										RAF_RSC_CP_MENU_REFUELED_A,
										RAF_RSC_CP_MENU_EXIT,
										"" );
		return 1;
	}
	else
		SetTimerEx("FuelTankerOil", FUEL_TANKER_STEP, false, "ifff", playerid, tankerX, tankerY, tankerZ);
	return 1;
}

public FuelTankerGas(playerid, Float:tankerX, Float:tankerY, Float:tankerZ)
{
	new vehID = GetPlayerVehicleID(playerid);
	new tlID = GetVehicleTrailer(vehID);
	/* Player left truck or moved truck */
	if(!(PlayerToPoint(4.0, playerid, tankerX, tankerY, tankerZ)))
	{
		gVehData[tlID-1][TankerIsRefueling] = 0;
		ShowPlayerDialog(playerid,
										DIALOG_RAF_RSC_CP_INFO_A,
										DIALOG_STYLE_MSGBOX,
										RAF_RSC_CP_MENU_HEADER,
										RAF_RSC_CP_MENU_REFUELED_C,
										RAF_RSC_CP_MENU_EXIT,
										"" );
		return 1;
	}
	new string[64];
	if( gRafinery[RafResourceGas] > 0 )
	{
		gVehData[tlID-1][TankerResourceValue]++;
		gRafinery[RafResourceGas]--;
		format(string, sizeof(string), "Tankowanie cysterny - %dl/%dl", gVehData[tlID-1][TankerResourceValue], MAX_TANKER_RESOURCE_VALUE );
		GameTextForPlayer( playerid, string, FUEL_TANKER_STEP, GAME_TEXT_STYLE_6 );
		SaveVehData(tlID-1, "TankerResourceValue");
		SaveRafinery();
	}
	else
	{
		gVehData[tlID-1][TankerIsRefueling] = 0;
		ShowPlayerDialog(playerid,
										DIALOG_RAF_RSC_CP_INFO_A,
										DIALOG_STYLE_MSGBOX,
										RAF_RSC_CP_MENU_HEADER,
										RAF_RSC_CP_MENU_REFUELED_B,
										RAF_RSC_CP_MENU_EXIT,
										"" );
		return 1;
	}
	if( gVehData[tlID-1][TankerResourceValue] >= MAX_TANKER_RESOURCE_VALUE )
	{
		gVehData[tlID-1][TankerIsRefueling] = 0;
		ShowPlayerDialog(playerid,
										DIALOG_RAF_RSC_CP_INFO_A,
										DIALOG_STYLE_MSGBOX,
										RAF_RSC_CP_MENU_HEADER,
										RAF_RSC_CP_MENU_REFUELED_A,
										RAF_RSC_CP_MENU_EXIT,
										"" );
		return 1;
	}
	else
		SetTimerEx("FuelTankerGas", FUEL_TANKER_STEP, false, "ifff", playerid, tankerX, tankerY, tankerZ);
	return 1;
}
public FuelTankerFly(playerid, Float:tankerX, Float:tankerY, Float:tankerZ)
{
	new vehID = GetPlayerVehicleID(playerid);
	new tlID = GetVehicleTrailer(vehID);
	/* Player left truck or moved truck */
	if(!(PlayerToPoint(4.0, playerid, tankerX, tankerY, tankerZ)))
	{
		gVehData[tlID-1][TankerIsRefueling] = 0;
		ShowPlayerDialog(playerid,
										DIALOG_RAF_RSC_CP_INFO_A,
										DIALOG_STYLE_MSGBOX,
										RAF_RSC_CP_MENU_HEADER,
										RAF_RSC_CP_MENU_REFUELED_C,
										RAF_RSC_CP_MENU_EXIT,
										"" );
		return 1;
	}
	new string[64];
	if( gRafinery[RafResourceFly] > 0 )
	{
		gVehData[tlID-1][TankerResourceValue]++;
		gRafinery[RafResourceGas]--;
		format(string, sizeof(string), "Tankowanie cysterny - %dl/%dl", gVehData[tlID-1][TankerResourceValue], MAX_TANKER_RESOURCE_VALUE );
		GameTextForPlayer( playerid, string, FUEL_TANKER_STEP, GAME_TEXT_STYLE_6 );
		SaveVehData(tlID-1, "TankerResourceValue");
		SaveRafinery();
	}
	else
	{
		gVehData[tlID-1][TankerIsRefueling] = 0;
		ShowPlayerDialog(playerid,
										DIALOG_RAF_RSC_CP_INFO_A,
										DIALOG_STYLE_MSGBOX,
										RAF_RSC_CP_MENU_HEADER,
										RAF_RSC_CP_MENU_REFUELED_B,
										RAF_RSC_CP_MENU_EXIT,
										"" );
		return 1;
	}
	if( gVehData[tlID-1][TankerResourceValue] >= MAX_TANKER_RESOURCE_VALUE )
	{
		gVehData[tlID-1][TankerIsRefueling] = 0;
		ShowPlayerDialog(playerid,
										DIALOG_RAF_RSC_CP_INFO_A,
										DIALOG_STYLE_MSGBOX,
										RAF_RSC_CP_MENU_HEADER,
										RAF_RSC_CP_MENU_REFUELED_A,
										RAF_RSC_CP_MENU_EXIT,
										"" );
		return 1;
	}
	else
		SetTimerEx("FuelTankerFly", FUEL_TANKER_STEP, false, "ifff", playerid, tankerX, tankerY, tankerZ);
	return 1;
}

timer RefuelingStation[FUEL_TANKER_STEP](playerid, gasStationID)
{
	if( !PlayerToPoint( 10.0, playerid, GasStations[gasStationID][GSposX], GasStations[gasStationID][GSposY], GasStations[gasStationID][GSposZ] ) )
	{
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_INFO_HEADER, RAF_GS_REFUELED_B, DIALOG_INFO_EXIT, "" );
		return 1;
	}
	new vehID = GetPlayerVehicleID(playerid);
	new tlID = GetVehicleTrailer(vehID);
	
	/* Not enough fuel */
	if( gVehData[tlID-1][TankerResourceValue] <= 0 )
	{
		gVehData[tlID-1][TankerIsRefueling] = 0;
		gVehData[tlID-1][TankerResourceType] = TANKER_TYPE_NONE;
		SaveVehData(tlID-1, "TankerResourceType");
		
		GivePlayerCash(playerid, floatround( gRafinery[RafRefuelReward]/2, floatround_round) );
		
		DynamicFactions[FACTIONID_RAFINERY][fBank] -= floatround( gRafinery[RafRefuelReward]/2, floatround_round);
		SaveFData(FACTIONID_RAFINERY, "Bank");
		
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_INFO_HEADER, RAF_GS_REFUELED_C, DIALOG_INFO_EXIT, "" );
		return 1;
	}
	
	new string[128];
	
	switch( gVehData[tlID-1][TankerResourceType] )
	{
		case TANKER_TYPE_PETROL:
		{
			GasStations[gasStationID][PetrolResourceValue] += 1.0;
			SaveGSData( gasStationID, "PetrolResourceValue" );
			
			gVehData[tlID-1][TankerResourceValue]--;
			SaveVehData(tlID-1, "TankerResourceValue");
			
			DynamicFactions[FACTIONID_RAFINERY][fBank] += gRafinery[RafPetrolLtrCost];
			SaveFData(FACTIONID_RAFINERY, "Bank");
			
			Businesses[GasStations[gasStationID][BusinessID]][Till] -= gRafinery[RafPetrolLtrCost];
			SaveBizData(GasStations[gasStationID][BusinessID], "Till");
			
			format(string, sizeof(string), "Nape³nianie zbiorników - %.1fl/%.1fl", GasStations[gasStationID][PetrolResourceValue], GasStations[gasStationID][MaxPetrolResourceValue] );
			GameTextForPlayer( playerid, string, FUEL_TANKER_STEP, GAME_TEXT_STYLE_6 );
			
			/* Tanks fueled */
			if( GasStations[gasStationID][PetrolResourceValue] >= GasStations[gasStationID][MaxPetrolResourceValue] )
			{
				gVehData[tlID-1][TankerIsRefueling] = 0;
				if( gVehData[tlID-1][TankerResourceValue] <= 0 )
				{
					gVehData[tlID-1][TankerResourceType] = TANKER_TYPE_NONE;
					SaveVehData(tlID-1, "TankerResourceType");
				}
				GivePlayerCash(playerid, gRafinery[RafRefuelReward]);
				DynamicFactions[FACTIONID_RAFINERY][fBank] -= gRafinery[RafRefuelReward];
				SaveFData(FACTIONID_RAFINERY, "Bank");
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_INFO_HEADER, RAF_GS_REFUELED_A, DIALOG_INFO_EXIT, "" );
				return 1;
			}
			/* No more till for refuel */
			if( Businesses[GasStations[gasStationID][BusinessID]][Till] < gRafinery[RafPetrolLtrCost] )
			{
				gVehData[tlID-1][TankerIsRefueling] = 0;
				GivePlayerCash(playerid, gRafinery[RafRefuelReward]);
				DynamicFactions[FACTIONID_RAFINERY][fBank] -= gRafinery[RafRefuelReward];
				SaveFData(FACTIONID_RAFINERY, "Bank");
				ShowPlayerDialog(playerid,
												DIALOG_INFO,
												DIALOG_STYLE_MSGBOX,
												DIALOG_INFO_HEADER,
												RAF_GS_REFUELED_D,
												DIALOG_INFO_EXIT,
												"" );
				return 1;
			}
		}
		case TANKER_TYPE_OIL:
		{
			GasStations[gasStationID][OilResourceValue] += 1.0;
			SaveGSData( gasStationID, "OilResourceValue" );
			gVehData[tlID-1][TankerResourceValue]--;
			SaveVehData(tlID-1, "TankerResourceValue");
			DynamicFactions[FACTIONID_RAFINERY][fBank] += gRafinery[RafOilLtrCost];
			SaveFData(FACTIONID_RAFINERY, "Bank");
			Businesses[GasStations[gasStationID][BusinessID]][Till] -= gRafinery[RafOilLtrCost];
			SaveBizData(GasStations[gasStationID][BusinessID], "Till");
			format(string, sizeof(string), "Nape³nianie zbiorników - %.1fl/%.1fl", GasStations[gasStationID][OilResourceValue], GasStations[gasStationID][MaxOilResourceValue] );
			GameTextForPlayer( playerid, string, FUEL_TANKER_STEP, GAME_TEXT_STYLE_6 );
			/* Tanks fueled */
			if( GasStations[gasStationID][OilResourceValue] >= GasStations[gasStationID][MaxOilResourceValue] )
			{
				gVehData[tlID-1][TankerIsRefueling] = 0;
				if( gVehData[tlID-1][TankerResourceValue] <= 0 )
				{
					gVehData[tlID-1][TankerResourceType] = TANKER_TYPE_NONE;
					SaveVehData(tlID-1, "TankerResourceType");
				}
				GivePlayerCash(playerid, gRafinery[RafRefuelReward]);
				ShowPlayerDialog(playerid,
												DIALOG_INFO,
												DIALOG_STYLE_MSGBOX,
												DIALOG_INFO_HEADER,
												RAF_GS_REFUELED_A,
												DIALOG_INFO_EXIT,
												"" );
				return 1;
			}
			/* No more till for refuel */
			if( Businesses[GasStations[gasStationID][BusinessID]][Till] < gRafinery[RafOilLtrCost] )
			{
				gVehData[tlID-1][TankerIsRefueling] = 0;
				GivePlayerCash(playerid, gRafinery[RafRefuelReward]);
				DynamicFactions[FACTIONID_RAFINERY][fBank] -= gRafinery[RafRefuelReward];
				SaveFData(FACTIONID_RAFINERY, "Bank");
				ShowPlayerDialog(playerid,
												DIALOG_INFO,
												DIALOG_STYLE_MSGBOX,
												DIALOG_INFO_HEADER,
												RAF_GS_REFUELED_D,
												DIALOG_INFO_EXIT,
												"" );
				return 1;
			}
		}
		case TANKER_TYPE_GAS:
		{
			GasStations[gasStationID][GasResourceValue] += 1.0;
			SaveGSData( gasStationID, "GasResourceValue" );
			gVehData[tlID-1][TankerResourceValue]--;
			SaveVehData(tlID-1, "TankerResourceValue");
			DynamicFactions[FACTIONID_RAFINERY][fBank] += gRafinery[RafGasLtrCost];
			SaveFData(FACTIONID_RAFINERY, "Bank");
			Businesses[GasStations[gasStationID][BusinessID]][Till] -= gRafinery[RafGasLtrCost];
			SaveBizData(GasStations[gasStationID][BusinessID], "Till");
			format(string, sizeof(string), "Nape³nianie zbiorników - %.1fl/%.1fl", GasStations[gasStationID][GasResourceValue], GasStations[gasStationID][MaxGasResourceValue] );
			GameTextForPlayer( playerid, string, FUEL_TANKER_STEP, GAME_TEXT_STYLE_6 );
			/* Tanks fueled */
			if( GasStations[gasStationID][GasResourceValue] >= GasStations[gasStationID][MaxGasResourceValue] )
			{
				gVehData[tlID-1][TankerIsRefueling] = 0;
				if( gVehData[tlID-1][TankerResourceValue] <= 0 )
				{
					gVehData[tlID-1][TankerResourceType] = TANKER_TYPE_NONE;
					SaveVehData(tlID-1, "TankerResourceType");
				}
				GivePlayerCash(playerid, gRafinery[RafRefuelReward]);
				DynamicFactions[FACTIONID_RAFINERY][fBank] -= gRafinery[RafRefuelReward];
				SaveFData(FACTIONID_RAFINERY, "Bank");
				ShowPlayerDialog(playerid,
												DIALOG_INFO,
												DIALOG_STYLE_MSGBOX,
												DIALOG_INFO_HEADER,
												RAF_GS_REFUELED_A,
												DIALOG_INFO_EXIT,
												"" );
				return 1;
			}
			/* No more till for refuel */
			if( Businesses[GasStations[gasStationID][BusinessID]][Till] < gRafinery[RafGasLtrCost] )
			{
				gVehData[tlID-1][TankerIsRefueling] = 0;
				GivePlayerCash(playerid, gRafinery[RafRefuelReward]);
				ShowPlayerDialog(playerid,
												DIALOG_INFO,
												DIALOG_STYLE_MSGBOX,
												DIALOG_INFO_HEADER,
												RAF_GS_REFUELED_D,
												DIALOG_INFO_EXIT,
												"" );
				return 1;
			}
		}
	}
	defer RefuelingStation(playerid, gasStationID);	
	return 1;
}

VehFTank(vehID)
{
	for(new i = 0; i < sizeof(CarsData); i++)
	{
		if(gVehData[vehID-1][mVehModel] == CarsData[i][Model] &&
			gVehData[vehID-1][Fuel] == CarsData[i][Paliwo])
		{
			return (CarsData[i][Bak]/1000);
		}
	}
	return 100;
}

VehCo2Emmision(vehID, &Float:co2emmision)
{
	new string[256];
	for(new i = 0; i < sizeof(CarsData); i++)
	{
		if(gVehData[vehID-1][mVehModel] == CarsData[i][Model] &&
			gVehData[vehID-1][Fuel] == CarsData[i][Paliwo])
		{
			co2emmision = CarsData[i][Co2Emmision];
			if( co2emmision == 0.0 )
			{
				format(string, sizeof(string), "[WARNING:] CO2 emmision not set (0.0) for model %d, fuel type %d", CarsData[i][Model], CarsData[i][Paliwo]);
				ErrorLog(string);
			}
			return 1;
		}
	}
	return 0;
}