/***
*
* File: wp_utils_biz.inc
* Auth: Damian Wojdat
* Date: 28.05.2012
* Desc: Internal script function related to businesses.
*
*************************************************************************************************************/

// TODO: Przebieranie siê tylko w domu
// TODO: Sieæ sklepów pod jedn¹ nazw¹ zmieniana z frakcji

stock ResetBizData(bID)
{
	// type 0 - reset all data
	// type 1 - removes owner, etc, just prepare for next buyer
	
	strdel(Businesses[bID][Owner], 0, 128);
	format(Businesses[bID][Owner], 128, "None");
	strdel(Businesses[bID][BusinessName], 0, 128);
	format(Businesses[bID][BusinessName], 128, "Biznes");
	Businesses[bID][BUID] = random(99999);
	Businesses[bID][mFaction] = -1;
	Businesses[bID][mFactionTimeLeft] = 0; // how long to end of company contract
	// Businesses[bID][EnterX] = 0;
	// Businesses[bID][EnterY] = 0;
	// Businesses[bID][EnterZ] = 0;
	// Businesses[bID][EnterWorld] = 0;
	// Businesses[bID][EnterInterior] = 0;
	// Businesses[bID][EnterAngle] = 0;
	// Businesses[bID][ExitX] = 0;
	// Businesses[bID][ExitY] = 0;
	// Businesses[bID][ExitZ] = 0;
	// Businesses[bID][ExitInterior] = 0;
	// Businesses[bID][ExitAngle] = 0;
	Businesses[bID][Owned] = 0;
	Businesses[bID][Enterable] = 0;
	// Businesses[bID][BizPrice] = 0;
	Businesses[bID][EntranceCost] = 0;
	Businesses[bID][Till] = 0;
	Businesses[bID][Locked] = 1;
	// Businesses[bID][BizType] = 0;
	Businesses[bID][Products] = 0;
	Businesses[bID][VehicleSpawned] = 0;
	Businesses[bID][VehicleCount] = 0;
	Businesses[bID][MaxVehicles] = 6;
	Businesses[bID][VehicleOrderCount] = 0;
	Businesses[bID][SalesJob] = 0;
	Businesses[bID][W9MM] = 0;
	Businesses[bID][mW9MMIncomeTotal] = 0;
	Businesses[bID][mW9MMIncomeToday] = 0;
	Businesses[bID][W9MMSil] = 0;
	Businesses[bID][mW9MMSilIncomeTotal] = 0;
	Businesses[bID][mW9MMSilIncomeToday] = 0;
	Businesses[bID][WDesEagle] = 0;
	Businesses[bID][mWDesEagleIncomeTotal] = 0;
	Businesses[bID][mWDesEagleIncomeToday] = 0;
	Businesses[bID][WMicroSMG] = 0;
	Businesses[bID][mWMicroSMGIncomeTotal] = 0;
	Businesses[bID][mWMicroSMGIncomeToday] = 0;
	Businesses[bID][WMP5] = 0;
	Businesses[bID][mWMP5IncomeTotal] = 0;
	Businesses[bID][mWMP5IncomeToday] = 0;
	Businesses[bID][WTec9] = 0;
	Businesses[bID][mWTec9IncomeTotal] = 0;
	Businesses[bID][mWTec9IncomeToday] = 0;
	Businesses[bID][WShotgun] = 0;
	Businesses[bID][mWShotgunIncomeTotal] = 0;
	Businesses[bID][mWShotgunIncomeToday] = 0;
	Businesses[bID][WAK47] = 0;
	Businesses[bID][mWAK47IncomeTotal] = 0;
	Businesses[bID][mWAK47IncomeToday] = 0;
	Businesses[bID][WM4] = 0;
	Businesses[bID][mWM4IncomeTotal] = 0;
	Businesses[bID][mWM4IncomeToday] = 0;
	Businesses[bID][WRifle] = 0;
	Businesses[bID][mWRifleIncomeTotal] = 0;
	Businesses[bID][mWRifleIncomeToday] = 0;
	Businesses[bID][WSRifle] = 0;
	Businesses[bID][mWSRifleIncomeTotal] = 0;
	Businesses[bID][mWSRifleIncomeToday] = 0;
	Businesses[bID][W9MMAmmo] = 0;
	Businesses[bID][mW9MMAmmoIncomeTotal] = 0;
	Businesses[bID][mW9MMAmmoIncomeToday] = 0;
	Businesses[bID][W50AEAmmo] = 0;
	Businesses[bID][mW50AEAmmoIncomeTotal] = 0;
	Businesses[bID][mW50AEAmmoIncomeToday] = 0;
	Businesses[bID][WBuckshot] = 0;
	Businesses[bID][mWBuckshotIncomeTotal] = 0;
	Businesses[bID][mWBuckshotIncomeToday] = 0;
	Businesses[bID][W762MMAmmo] = 0;
	Businesses[bID][mW762MMAmmoIncomeTotal] = 0;
	Businesses[bID][mW762MMAmmoIncomeToday] = 0;
	Businesses[bID][W127MMAmmo] = 0;
	Businesses[bID][mW127MMAmmoIncomeTotal] = 0;
	Businesses[bID][mW127MMAmmoIncomeToday] = 0;
	Businesses[bID][BRadio1Bought] = 0; // Is radio bought
	Businesses[bID][BRadio1On] = 0; // Is radio ON
	Businesses[bID][BRadio1Ch] = 0; // Radio channell
	Businesses[bID][BRadio1Obj] = 0; // Radio object id
	Businesses[bID][BRadio1Vol] = 0; // Volume of radio
	Businesses[bID][BRadio1X] = 0; // radio x pos 
	Businesses[bID][BRadio1Y] = 0; // radio y pos
	Businesses[bID][BRadio1Z] = 0; // radio z pos
	Businesses[bID][BRadio1Angle] = 0;
	Businesses[bID][Product1] = 0;
	Businesses[bID][Product1type] = 0;
	Businesses[bID][Product1price] = 0;
	Businesses[bID][Product1count] = 0;
	Businesses[bID][Product1buy] = 0;
	Businesses[bID][Product1incomeTotal] = 0;
	Businesses[bID][Product1incomeToday] = 0;
	Businesses[bID][Product2] = 0;
	Businesses[bID][Product2type] = 0;
	Businesses[bID][Product2price] = 0;
	Businesses[bID][Product2count] = 0;
	Businesses[bID][Product2buy] = 0;
	Businesses[bID][Product2incomeTotal] = 0;
	Businesses[bID][Product2incomeToday] = 0;
	Businesses[bID][Product3] = 0;
	Businesses[bID][Product3type] = 0;
	Businesses[bID][Product3price] = 0;
	Businesses[bID][Product3count] = 0;
	Businesses[bID][Product3buy] = 0;
	Businesses[bID][Product3incomeTotal] = 0;
	Businesses[bID][Product3incomeToday] = 0;
	Businesses[bID][Product4] = 0;
	Businesses[bID][Product4type] = 0;
	Businesses[bID][Product4price] = 0;
	Businesses[bID][Product4count] = 0;
	Businesses[bID][Product4buy] = 0;
	Businesses[bID][Product4incomeTotal] = 0;
	Businesses[bID][Product4incomeToday] = 0;
	Businesses[bID][Product5] = 0;
	Businesses[bID][Product5type] = 0;
	Businesses[bID][Product5price] = 0;
	Businesses[bID][Product5count] = 0;
	Businesses[bID][Product5buy] = 0;
	Businesses[bID][Product5incomeTotal] = 0;
	Businesses[bID][Product5incomeToday] = 0;
	Businesses[bID][Product6] = 0;
	Businesses[bID][Product6type] = 0;
	Businesses[bID][Product6price] = 0;
	Businesses[bID][Product6count] = 0;
	Businesses[bID][Product6buy] = 0;
	Businesses[bID][Product6incomeTotal] = 0;
	Businesses[bID][Product6incomeToday] = 0;
	Businesses[bID][Product7] = 0;
	Businesses[bID][Product7type] = 0;
	Businesses[bID][Product7price] = 0;
	Businesses[bID][Product7count] = 0;
	Businesses[bID][Product7buy] = 0;
	Businesses[bID][Product7incomeTotal] = 0;
	Businesses[bID][Product7incomeToday] = 0;
	Businesses[bID][Product8] = 0;
	Businesses[bID][Product8type] = 0;
	Businesses[bID][Product8price] = 0;
	Businesses[bID][Product8count] = 0;
	Businesses[bID][Product8buy] = 0;
	Businesses[bID][Product8incomeTotal] = 0;
	Businesses[bID][Product8incomeToday] = 0;
	Businesses[bID][Product9] = 0;
	Businesses[bID][Product9type] = 0;
	Businesses[bID][Product9price] = 0;
	Businesses[bID][Product9count] = 0;
	Businesses[bID][Product9buy] = 0;
	Businesses[bID][Product9incomeTotal] = 0;
	Businesses[bID][Product9incomeToday] = 0;
	Businesses[bID][Product10] = 0;
	Businesses[bID][Product10type] = 0;
	Businesses[bID][Product10price] = 0;
	Businesses[bID][Product10count] = 0;
	Businesses[bID][Product10buy] = 0;
	Businesses[bID][Product10incomeTotal] = 0;
	Businesses[bID][Product10incomeToday] = 0;
	Businesses[bID][Product11Price] = 0;
	Businesses[bID][Product12Price] = 0;
	Businesses[bID][Product13Price] = 0;
	Businesses[bID][Product14Price] = 0;
	Businesses[bID][Product15Price] = 0;
	Businesses[bID][Product16Price] = 0;
	Businesses[bID][Product17Price] = 0;
	Businesses[bID][Product18Price] = 0;
	Businesses[bID][Product19Price] = 0;
	Businesses[bID][Product20Price] = 0;
	Businesses[bID][Product21Price] = 0;
	Businesses[bID][Product22Price] = 0;
	Businesses[bID][Product23Price] = 0;
	Businesses[bID][Product24Price] = 0;
	Businesses[bID][Product25Price] = 0;
	Businesses[bID][Product26Price] = 0;
	Businesses[bID][Product27Price] = 0;
	Businesses[bID][Product28Price] = 0;
	Businesses[bID][Product29Price] = 0;
	Businesses[bID][Product30Price] = 0;
	Businesses[bID][BConfiscated] = 0;
	// Businesses[bID][BPlaced] = 0;
	// Businesses[bID][BIntSet] = 0;
	// Businesses[bID][BInterior] = 0;
	Businesses[bID][BGov] = 0;
	// Businesses[bID][BShowIcon] = 0;
	Businesses[bID][mIncomeTotal] = 0;
	Businesses[bID][mIncomePhoneTotal] = 0;
	Businesses[bID][mIncomePhoneToday] = 0;
	Businesses[bID][mIncomeFuelPetrolToday] = 0;
	Businesses[bID][mIncomeFuelPetrolTotal] = 0;
	Businesses[bID][mIncomeFuelOilToday] = 0;
	Businesses[bID][mIncomeFuelOilTotal] = 0;
	Businesses[bID][mIncomeFuelGasToday] = 0;
	Businesses[bID][mIncomeFuelGasTotal] = 0;
	Businesses[bID][mIncomeVehicleTotal] = 0;
	Businesses[bID][mIncomeVehicleToday] = 0;
	Businesses[bID][mIncomeEntranceTotal] = 0;
	Businesses[bID][mIncomeEntranceToday] = 0;
	Businesses[bID][mAlarm] = 0;
	
	SaveBizData(bID, "Owner");
	SaveBizData(bID, "BusinessName");
	SaveBizData(bID, "UID");
	SaveBizData(bID, "Owner");
	SaveBizData(bID, "Faction");
	SaveBizData(bID, "FactionTimeLeft"); // how long to end of company contract
	// SaveBizData(bID, "EnterX");
	// SaveBizData(bID, "EnterY");
	// SaveBizData(bID, "EnterZ");
	// SaveBizData(bID, "EnterWorld");
	// SaveBizData(bID, "EnterInterior");
	// SaveBizData(bID, "EnterAngle");
	// SaveBizData(bID, "ExitX");
	// SaveBizData(bID, "ExitY");
	// SaveBizData(bID, "ExitZ");
	// SaveBizData(bID, "ExitInterior");
	// SaveBizData(bID, "ExitAngle");
	SaveBizData(bID, "Owned");
	SaveBizData(bID, "Enterable");
	// SaveBizData(bID, "BizPrice");
	SaveBizData(bID, "EntranceCost");
	SaveBizData(bID, "Till");
	SaveBizData(bID, "Locked");
	// SaveBizData(bID, "BizType");
	SaveBizData(bID, "Products");
	SaveBizData(bID, "VehicleSpawned");
	SaveBizData(bID, "VehicleCount");
	SaveBizData(bID, "MaxVehicles");
	SaveBizData(bID, "VehicleOrderCount");
	SaveBizData(bID, "SalesJob");
	SaveBizData(bID, "W9MM");
	SaveBizData(bID, "W9MMIncomeTotal");
	SaveBizData(bID, "W9MMIncomeToday");
	SaveBizData(bID, "W9MMSil");
	SaveBizData(bID, "W9MMSilIncomeTotal");
	SaveBizData(bID, "W9MMSilIncomeToday");
	SaveBizData(bID, "WDesEagle");
	SaveBizData(bID, "WDesEagleIncomeTotal");
	SaveBizData(bID, "WDesEagleIncomeToday");
	SaveBizData(bID, "WMicroSMG");
	SaveBizData(bID, "WMicroSMGIncomeTotal");
	SaveBizData(bID, "WMicroSMGIncomeToday");
	SaveBizData(bID, "WMP5");
	SaveBizData(bID, "WMP5IncomeTotal");
	SaveBizData(bID, "WMP5IncomeToday");
	SaveBizData(bID, "WTec9");
	SaveBizData(bID, "WTec9IncomeTotal");
	SaveBizData(bID, "WTec9IncomeToday");
	SaveBizData(bID, "WShotgun");
	SaveBizData(bID, "WShotgunIncomeTotal");
	SaveBizData(bID, "WShotgunIncomeToday");
	SaveBizData(bID, "WAK47");
	SaveBizData(bID, "WAK47IncomeTotal");
	SaveBizData(bID, "WAK47IncomeToday");
	SaveBizData(bID, "WM4");
	SaveBizData(bID, "WM4IncomeTotal");
	SaveBizData(bID, "WM4IncomeToday");
	SaveBizData(bID, "WRifle");
	SaveBizData(bID, "WRifleIncomeTotal");
	SaveBizData(bID, "WRifleIncomeToday");
	SaveBizData(bID, "WSRifle");
	SaveBizData(bID, "WSRifleIncomeTotal");
	SaveBizData(bID, "WSRifleIncomeToday");
	SaveBizData(bID, "W9MMAmmo");
	SaveBizData(bID, "W9MMAmmoIncomeTotal");
	SaveBizData(bID, "W9MMAmmoIncomeToday");
	SaveBizData(bID, "W50AEAmmo");
	SaveBizData(bID, "W50AEAmmoIncomeTotal");
	SaveBizData(bID, "W50AEAmmoIncomeToday");
	SaveBizData(bID, "WBuckshot");
	SaveBizData(bID, "WBuckshotIncomeTotal");
	SaveBizData(bID, "WBuckshotIncomeToday");
	SaveBizData(bID, "W762MMAmmo");
	SaveBizData(bID, "W762MMAmmoIncomeTotal");
	SaveBizData(bID, "W762MMAmmoIncomeToday");
	SaveBizData(bID, "W127MMAmmo");
	SaveBizData(bID, "W127MMAmmoIncomeTotal");
	SaveBizData(bID, "W127MMAmmoIncomeToday");
	SaveBizData(bID, "BRadio1Bought"); // Is radio bought
	SaveBizData(bID, "BRadio1On"); // Is radio ON
	SaveBizData(bID, "BRadio1Ch"); // Radio channell
	SaveBizData(bID, "BRadio1Vol"); // Volume of radio
	SaveBizData(bID, "BRadio1X"); // radio x pos 
	SaveBizData(bID, "BRadio1Y"); // radio y pos
	SaveBizData(bID, "BRadio1Z"); // radio z pos
	SaveBizData(bID, "BRadio1Angle");
	SaveBizData(bID, "Product1");
	SaveBizData(bID, "Product1type");
	SaveBizData(bID, "Product1price");
	SaveBizData(bID, "Product1count");
	SaveBizData(bID, "Product1buy");
	SaveBizData(bID, "Product1incomeTotal");
	SaveBizData(bID, "Product1incomeToday");
	SaveBizData(bID, "Product2");
	SaveBizData(bID, "Product2type");
	SaveBizData(bID, "Product2price");
	SaveBizData(bID, "Product2count");
	SaveBizData(bID, "Product2buy");
	SaveBizData(bID, "Product2incomeTotal");
	SaveBizData(bID, "Product2incomeToday");
	SaveBizData(bID, "Product3");
	SaveBizData(bID, "Product3type");
	SaveBizData(bID, "Product3price");
	SaveBizData(bID, "Product3count");
	SaveBizData(bID, "Product3buy");
	SaveBizData(bID, "Product3incomeTotal");
	SaveBizData(bID, "Product3incomeToday");
	SaveBizData(bID, "Product4");
	SaveBizData(bID, "Product4type");
	SaveBizData(bID, "Product4price");
	SaveBizData(bID, "Product4count");
	SaveBizData(bID, "Product4buy");
	SaveBizData(bID, "Product4incomeTotal");
	SaveBizData(bID, "Product4incomeToday");
	SaveBizData(bID, "Product5");
	SaveBizData(bID, "Product5type");
	SaveBizData(bID, "Product5price");
	SaveBizData(bID, "Product5count");
	SaveBizData(bID, "Product5buy");
	SaveBizData(bID, "Product5incomeTotal");
	SaveBizData(bID, "Product5incomeToday");
	SaveBizData(bID, "Product6");
	SaveBizData(bID, "Product6type");
	SaveBizData(bID, "Product6price");
	SaveBizData(bID, "Product6count");
	SaveBizData(bID, "Product6buy");
	SaveBizData(bID, "Product6incomeTotal");
	SaveBizData(bID, "Product6incomeToday");
	SaveBizData(bID, "Product7");
	SaveBizData(bID, "Product7type");
	SaveBizData(bID, "Product7price");
	SaveBizData(bID, "Product7count");
	SaveBizData(bID, "Product7buy");
	SaveBizData(bID, "Product7incomeTotal");
	SaveBizData(bID, "Product7incomeToday");
	SaveBizData(bID, "Product8");
	SaveBizData(bID, "Product8type");
	SaveBizData(bID, "Product8price");
	SaveBizData(bID, "Product8count");
	SaveBizData(bID, "Product8buy");
	SaveBizData(bID, "Product8incomeTotal");
	SaveBizData(bID, "Product8incomeToday");
	SaveBizData(bID, "Product9");
	SaveBizData(bID, "Product9type");
	SaveBizData(bID, "Product9price");
	SaveBizData(bID, "Product9count");
	SaveBizData(bID, "Product9buy");
	SaveBizData(bID, "Product9incomeTotal");
	SaveBizData(bID, "Product9incomeToday");
	SaveBizData(bID, "Product10");
	SaveBizData(bID, "Product10type");
	SaveBizData(bID, "Product10price");
	SaveBizData(bID, "Product10count");
	SaveBizData(bID, "Product10buy");
	SaveBizData(bID, "Product10incomeTotal");
	SaveBizData(bID, "Product10incomeToday");
	SaveBizData(bID, "Product11Price");
	SaveBizData(bID, "Product12Price");
	SaveBizData(bID, "Product13Price");
	SaveBizData(bID, "Product14Price");
	SaveBizData(bID, "Product15Price");
	SaveBizData(bID, "Product16Price");
	SaveBizData(bID, "Product17Price");
	SaveBizData(bID, "Product18Price");
	SaveBizData(bID, "Product19Price");
	SaveBizData(bID, "Product20Price");
	SaveBizData(bID, "Product21Price");
	SaveBizData(bID, "Product22Price");
	SaveBizData(bID, "Product23Price");
	SaveBizData(bID, "Product24Price");
	SaveBizData(bID, "Product25Price");
	SaveBizData(bID, "Product26Price");
	SaveBizData(bID, "Product27Price");
	SaveBizData(bID, "Product28Price");
	SaveBizData(bID, "Product29Price");
	SaveBizData(bID, "Product30Price");
	SaveBizData(bID, "Confiscated");
	// SaveBizData(bID, "BPlaced");
	// SaveBizData(bID, "BIntSet");
	// SaveBizData(bID, "BInterior");
	SaveBizData(bID, "Gov");
	// SaveBizData(bID, "BShowIcon");
	SaveBizData(bID, "IncomeTotal");
	SaveBizData(bID, "IncomePhoneTotal");
	SaveBizData(bID, "IncomePhoneToday");
	SaveBizData(bID, "IncomeFuelPetrolToday");
	SaveBizData(bID, "IncomeFuelPetrolTotal");
	SaveBizData(bID, "IncomeFuelOilToday");
	SaveBizData(bID, "IncomeFuelOilTotal");
	SaveBizData(bID, "IncomeFuelGasToday");
	SaveBizData(bID, "IncomeFuelGasTotal");
	SaveBizData(bID, "IncomeVehicleTotal");
	SaveBizData(bID, "IncomeVehicleToday");
	SaveBizData(bID, "IncomeEntranceTotal");
	SaveBizData(bID, "IncomeEntranceToday");
	SaveBizData(bID, "Alarm");
	
	RefreshBizDescription(bID);
}

stock RefreshBizDescription(bizId)
{
	new businesstype[64], string[128], bizLocation[MAX_ZONE_NAME];
	
	if(Business3DTextLabelA[bizId])
	{
		DestroyDynamic3DTextLabel(Business3DTextLabelA[bizId]);
	}
	if(Business3DTextLabelB[bizId])
	{
		DestroyDynamic3DTextLabel(Business3DTextLabelB[bizId]);
	}
	if(Business3DTextLabelC[bizId])
	{
		DestroyDynamic3DTextLabel(Business3DTextLabelC[bizId]);
	}
	
	if(Businesses[bizId][BizType] != 0)
	{
		if(Businesses[bizId][BizType] == 1) { businesstype = "restauracja"; }
		else if(Businesses[bizId][BizType] == 2) { businesstype = "sieæ komorkowa"; }
		else if(Businesses[bizId][BizType] == 3) { businesstype = "sklep"; }
		else if(Businesses[bizId][BizType] == 4) { businesstype = "sklep z bronia"; }
		else if(Businesses[bizId][BizType] == 5) { businesstype = "studio reklamowe"; }
		else if(Businesses[bizId][BizType] == 6) { businesstype = "sklep z ubraniami"; }
		else if(Businesses[bizId][BizType] == 7) { businesstype = "Bar/Club"; }
		else if(Businesses[bizId][BizType] == 8) { businesstype = "studio nagraniowe"; }
		else if(Businesses[bizId][BizType] == 9) { businesstype = "studio"; }
		else if(Businesses[bizId][BizType] == 10) { businesstype = "salon samochodowy"; }
		else if(Businesses[bizId][BizType] == 11) { businesstype = "stacja paliw"; }
	}
	else { businesstype = "Nie ustawione"; }
	
	if(Businesses[bizId][PickupID])
	{
		DestroyDynamicPickup(Businesses[bizId][PickupID]);
	}
	
	if(Businesses[bizId][ExitPickupId])
	{
		DestroyDynamicPickup(Businesses[bizId][ExitPickupId]);
	}
	
	if(Businesses[bizId][ExitX] != 0.0 || Businesses[bizId][ExitY] != 0.0)
	{
		Businesses[bizId][ExitPickupId] = CreateDynamicPickup(1318, 1, Businesses[bizId][ExitX], Businesses[bizId][ExitY], Businesses[bizId][ExitZ], bizId, Businesses[bizId][ExitInterior]);
	}
	
	if(Businesses[bizId][EnterX] != 0.0 || Businesses[bizId][EnterY] != 0.0)
	{
		Businesses[bizId][PickupID] = CreateDynamicPickup(1272, 1, Businesses[bizId][EnterX], Businesses[bizId][EnterY], Businesses[bizId][EnterZ]);
	
		GetCoords2DZone(Businesses[bizId][EnterX], Businesses[bizId][EnterY], bizLocation, MAX_ZONE_NAME);
	
		if(Businesses[bizId][Owned] == 0)
		{
			format(string, sizeof(string), "%s %d", bizLocation, Businesses[bizId][StreetNo]);
			Business3DTextLabelA[bizId] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE2, Businesses[bizId][EnterX], Businesses[bizId][EnterY], Businesses[bizId][EnterZ]+1.0, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

			format(string, sizeof(string), "Ten biznes jest na sprzeda¿! /kupbiznes");
			Business3DTextLabelB[bizId] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE2, Businesses[bizId][EnterX], Businesses[bizId][EnterY], Businesses[bizId][EnterZ]+0.5, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

			format(string, sizeof(string), "%s, cena $%d", businesstype, Businesses[bizId][BizPrice]);
			Business3DTextLabelC[bizId] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE2, Businesses[bizId][EnterX], Businesses[bizId][EnterY], Businesses[bizId][EnterZ], 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
		}
		else if(Businesses[bizId][Owned] == 1)
		{
			if(Businesses[bizId][mFaction] == -1)
			{
				format(string, sizeof(string), "%s %d", bizLocation, Businesses[bizId][StreetNo]);
				Business3DTextLabelA[bizId] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE2, Businesses[bizId][EnterX], Businesses[bizId][EnterY], Businesses[bizId][EnterZ]+1.0, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
			}
			else
			{
				format(string, sizeof(string), "%s %d, %s", bizLocation, Businesses[bizId][StreetNo], DynamicFactions[Businesses[bizId][mFaction]][Name]);
				Business3DTextLabelA[bizId] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE2, Businesses[bizId][EnterX], Businesses[bizId][EnterY], Businesses[bizId][EnterZ]+1.0, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
			}
			
			if(strlen(Businesses[bizId][BusinessName]) == 0)
			{
				format(string, sizeof(string), "%s", businesstype);
				Business3DTextLabelB[bizId] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE2, Businesses[bizId][EnterX], Businesses[bizId][EnterY], Businesses[bizId][EnterZ]+0.5, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
			}
			else
			{
				format(string, sizeof(string), "%s, %s", Businesses[bizId][BusinessName], businesstype);
				Business3DTextLabelB[bizId] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE2, Businesses[bizId][EnterX], Businesses[bizId][EnterY], Businesses[bizId][EnterZ]+0.5, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
			}
			
			format(string, sizeof(string), "Wejœciówka $%d",Businesses[bizId][EntranceCost]);
			Business3DTextLabelC[bizId] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE2, Businesses[bizId][EnterX], Businesses[bizId][EnterY], Businesses[bizId][EnterZ], 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
		}
	}
}

stock RefreshBizIcon(bizId)
{
	new model;
	switch(Businesses[bizId][Owned])
	{
		case 0: model = 1272;
		case 1: model = 1239;
	}
	Businesses[bizId][PickupID] = ChangePickupModel(Businesses[bizId][PickupID], model, Businesses[bizId][EnterX], Businesses[bizId][EnterY], Businesses[bizId][EnterZ]);
}