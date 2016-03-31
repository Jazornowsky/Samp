public OnGameModeInit()
{
	printf("[INIT:] OnGameModeInit started - WP-RP v.1.13 R2");
    SetGameModeText("WP-RP v.1.13 R2");
	
	// TODO: house cost should be transfered to somekind of house faction manager
	// For now cash from house goes nowhere...
	// Same with businesses
	
	// TODO: There should be some activities in house (except item taking, etc.) that requires player
	// 		to come back to house more often
	
	//=======================================[ANTI DeAMX]======================================
	new a[][] =
	{
		"Unarmed (Fist)",
		"Brass K"
	};
	#pragma unused a

	//==========================[SETTING FUEL AND TURNING ENGINES OFF]========================
	for(new c = 0; c < sizeof(gVehData); c++)
	{
		CarWindowStatus[c] = 1; //1 = up, 0 = down.
	}

	//===================================[SET DEFAULT DATA]====================================
	strmid(gRadio[0], "http://radioparty.pl/play/glowny_48.m3u", 0, 128, 255); // radioparty.pl
	strmid(gRadio[1], "http://www.radiozet.pl/externals/radiozet-streams/radiozet_stream.pls", 0, 128, 255); // radio zet
	strmid(gRadio[2], "http://www.miastomuzyki.pl/rmfclassic.asx", 0, 128, 255); // radio zet
	strmid(gRadio[3], "http://www.miastomuzyki.pl/odbior/rmf_aacp.pls", 0, 128, 255); // radio zet
	strmid(gRadio[4], "http://www.miastomuzyki.pl/rmfhiphop.asx", 0, 128, 255); // radio zet
	strmid(gRadio[5], "http://www.miastomuzyki.pl/rmfdance.asx", 0, 128, 255); // radio zet
	strmid(gRadio[6], "http://www.polskastacja.pl/play/hot100.asx", 0, 128, 255); // radio zet
	strmid(gRadio[7], "http://www.radioblue.fm/blue.asx", 0, 128, 255); // radio zet
	strmid(gRadio[8], "http://www.miastomuzyki.pl/rmfmaxxx.asx", 0, 128, 255); // radio zet
	
	//===============================[DISABLING/ENABLING STUFF]================================
	ShowPlayerMarkers(0);
	EnableStuntBonusForAll(0); //Disable stunt bonus.
    DisableInteriorEnterExits(); //Disable Yellow Markers.
    AllowInteriorWeapons(0); //Allowing weapons inside.
	AllowAdminTeleport(1);
	SetNameTagDrawDistance(10.0);
	ManualVehicleEngineAndLights(); //server control engine and lights

	//=================================[DATABASE CONNECTION]===================================
	print("[SKRYPT:] Laczenie z baza danych...");
	db_con1 = mysql_init(LOG_ONLY_ERRORS, 1);
	db_con2 = mysql_init(LOG_ONLY_ERRORS, 1);
	db_con3 = mysql_init(LOG_ONLY_ERRORS, 1);	
	db_con4 = mysql_init(LOG_ONLY_ERRORS, 1);
	// db_con1 = mysql_init(LOG_ALL, 1);
	// db_con2 = mysql_init(LOG_ALL, 1);
	// db_con3 = mysql_init(LOG_ALL, 1);
	// db_con4 = mysql_init(LOG_ALL, 1);

	// LoadConfig();
	
	if( !mysql_connect(db_host,db_user,db_pass,db_database, db_con1, 1) )
	{
		GameModeExit();
		return 1;
	}
	if( !mysql_connect(db_host,db_user,db_pass,db_database, db_con2, 1) )
	{
		GameModeExit();
		return 1;
	}
	if( !mysql_connect(db_host,db_user,db_pass,db_database, db_con3, 1) )
	{
		GameModeExit();
		return 1;
	}
	if( !mysql_connect(db_host,db_user,db_pass,db_database, db_con4, 1) )
	{
		GameModeExit();
		return 1;
	}

	// mysql_set_character_set("utf8_unicode_ci", db_con1);
	// mysql_set_character_set("utf8_unicode_ci", db_con2);
	// mysql_set_character_set("utf8_unicode_ci", db_con3);
	// mysql_set_character_set("utf8_unicode_ci", db_con4);
	//=========================================[LOAD]==========================================
	LoadScript();
	LoadCustomAreas();
	Audio_SetPack("default_pack", true);

	//=======================================[MWEATHER]========================================
	MWeather_OnGameModeInit();
	gMW_warszawa = AddWeatherObserver("http://weather.yahoo.com/poland/masovian/warsaw-523920/", 1200000);
	gMW_lasvegas = AddWeatherObserver("http://weather.yahoo.com/united-states/nevada/las-vegas-2436704/", 1200000);
	gMW_sanfrancisco = AddWeatherObserver("http://weather.yahoo.com/united-states/nevada/las-vegas-2436704/", 1200000);
	gMW_losangeles = AddWeatherObserver("http://weather.yahoo.com/united-states/california/los-angeles-2442047/", 1200000);
	//SetRealWeatherEx(gMW_warszawa);

	//=====================================[DJSON PLUGIN]======================================
	djson_GameModeInit();
	
	//====================================[FIREWORKS LOAD]=====================================
	if(!fexist("FireWorkInfo"))
	{
		djCreateFile("FireWorkInfo");
		djSetInt("FireWorkInfo","FireCrackerAL", 0);
	    djSetInt("FireWorkInfo","FireRocket1AL", 0);
	    djSetInt("FireWorkInfo","FireRocket2AL", 0);
	    djSetInt("FireWorkInfo","CrackerrollAL", 0);
	    djSetInt("FireWorkInfo","Fountain1AL", 0);
	    djSetInt("FireWorkInfo","Fountain2AL", 0);
	    djSetInt("FireWorkInfo","Fountain3AL", 0);
	    djSetInt("FireWorkInfo","RocketBAL", 0);
	    djSetInt("FireWorkInfo","DrawDistance", 1);
	    print("[FWCP]: FireWorkInfo file created");
	}
	SetTimer("Load", 3000, 0);
	
	//======================================[GANG ZONES]=======================================
	for(new idx = 0; idx < sizeof(DynamicZones); idx++)
	{
		gangZoneID[idx] = GangZoneCreate(DynamicZones[idx][zMin_X]*1.0, DynamicZones[idx][zMin_Y]*1.0, DynamicZones[idx][zMax_X]*1.0, DynamicZones[idx][zMax_Y]*1.0);
	}

	for( new i = 0; i < CUSTOM_MAX_PLAYERS; i++ )
	{
		GangWar[i] = TextDrawCreate(32.0, 310.0, " ");
		TextDrawLetterSize( GangWar[i], 0.3, 0.8 );
		TextDrawTextSize( GangWar[i], 200.0, 100.0 );
	}
	//=====================================[CHECKPOINTS]=======================================
	CreateDynamicCP(DrivingTestPosition[X], DrivingTestPosition[Y], DrivingTestPosition[Z], 1.0);
	CreateDynamicCP(BankPosition[X], BankPosition[Y], BankPosition[Z], 1.0);
	CreateDynamicCP( gATM[0][0], gATM[0][1], gATM[0][2], 1.0, 0, 0, -1, 5.0 );
	CreateDynamicCP( gATM[1][0], gATM[1][1], gATM[1][2], 1.0, 0, 0, -1, 5.0 );
	CreateDynamicCP( gATM[2][0], gATM[2][1], gATM[2][2], 1.0, 0, 0, -1, 5.0 );
	CreateDynamicCP( gATM[3][0], gATM[3][1], gATM[3][2], 1.0, 0, 0, -1, 5.0 );
	// CreateDynamicCP(SkillPosition[XPis],SkillPosition[YPis],SkillPosition[ZPis], 1.0);
	// CreateDynamicCP(SkillPosition[XSil],SkillPosition[YSil],SkillPosition[ZSil], 1.0);
	// CreateDynamicCP(SkillPosition[XDes],SkillPosition[YDes],SkillPosition[ZDes], 1.0);
	// CreateDynamicCP(SkillPosition[XSho],SkillPosition[YSho],SkillPosition[ZSho], 1.0);
	// CreateDynamicCP(SkillPosition[XSha],SkillPosition[YSha],SkillPosition[ZSha], 1.0);
	// CreateDynamicCP(SkillPosition[XSpa],SkillPosition[YSpa],SkillPosition[ZSpa], 1.0);
	// CreateDynamicCP(SkillPosition[XMic],SkillPosition[YMic],SkillPosition[ZMic], 1.0);
	// CreateDynamicCP(SkillPosition[XMp5],SkillPosition[YMp5],SkillPosition[ZMp5], 1.0);
	// CreateDynamicCP(SkillPosition[XAk],SkillPosition[YAk],SkillPosition[ZAk], 1.0);
	// CreateDynamicCP(SkillPosition[XM4],SkillPosition[YM4],SkillPosition[ZM4],1.0);
	// CreateDynamicCP(SkillPosition[XSni],SkillPosition[YSni],SkillPosition[ZSni], 1.0);
	gRafinery[RafResourceCP] = CreateDynamicCP(-985.0, -708.0, 32.0, 10.0); // checkpoint tankowania cystern
	gGovCheckpoint = CreateDynamicCP(359.0, 169.0, 1008.0, 1.0); // checkpoint obslugi klienta w urzedzie);
	gShopCP1 = CreateDynamicCP(-28.0,-185.0,1004.0,1.0);
	gShopCP2 = CreateDynamicCP(3.0,-29.0,1004.0,1.0);
	gShopCP3 = CreateDynamicCP(-27.0,-90.0,1004.0,1.0);
	gShopCP4 = CreateDynamicCP(-21.0,-139.0,1004.0,1.0);
	gShopCP5 = CreateDynamicCP(-30.0,-29.0,1004.0,1.0);
	gShopCP6 = CreateDynamicCP(-22.0,-56.0,1004.0,1.0);
	gCShopCP1 = CreateDynamicCP(204.0, -160.0, 1001.0, 1.0);
	gCShopCP2 = CreateDynamicCP(209.0, -101.0, 1005.0, 1.0);
	gCShopCP3 = CreateDynamicCP(207.0, -129.0, 1004.0, 1.0);
	gCShopCP4 = CreateDynamicCP(203.0, -44.0, 1002.0, 1.0);
	gCShopCP5 = CreateDynamicCP(207.0, -9.0, 1001.0, 1.0);
	gCShopCP6 = CreateDynamicCP(161.0, -84.0, 1002.0, 1.0);
	gAmmoCP1 = CreateDynamicCP( 297.0, -38.0, 1002.0, 1.0 );
	gAmmoCP2 = CreateDynamicCP( 295.0, -81.0, 1002.0, 1.0 );
	gAmmoCP3 = CreateDynamicCP( 288.0, -109.0, 1002.0, 1.0 );
	gAmmoCP4 = CreateDynamicCP( 313.0, -166.0, 1000.0, 1.0 );
	gEatCP1 = CreateDynamicCP( -783.0, 500.0, 1372.0, 1.0, -1, -1, -1, 20.0 );
	gEatCP2 = CreateDynamicCP( 377.0, -68.0, 1002.0, 1.0, -1, -1, -1, 20.0 );
	gEatCP3 = CreateDynamicCP( 373.0, -66.0, 1002.0, 1.0, -1, -1, -1, 20.0 );
	gEatCP4 = CreateDynamicCP( 368.0, -6.0, 1002.0, 1.0, -1, -1, -1, 4.0 );
	gEatCP5 = CreateDynamicCP( 371.0, -6.0, 1002.0, 1.0, -1, -1, -1, 4.0 );
	gEatCP6 = CreateDynamicCP( 377.0, -119.0, 1001.0, 1.0, -1, -1, -1, 4.0 );
	gEatCP7 = CreateDynamicCP( 375.0, -119.0, 1001.0, 1.0, -1, -1, -1, 4.0 );
	gEatCP8 = CreateDynamicCP( 373.0, -119.0, 1001.0, 1.0, -1, -1, -1, 4.0 );
	gEatCP9 = CreateDynamicCP( 381.0, -191.0, 1001.0, 1.0, -1, -1, -1, 4.0 );
	gEatCP10 = CreateDynamicCP( 451.0, -84.0, 1000.0, 1.0, -1, -1, -1, 4.0 );
	gEatCP11 = CreateDynamicCP( 449.0, -84.0, 1000.0, 1.0, -1, -1, -1, 4.0 );
	//CreateDynamicCP(571.0,-2034.0,16.0,10.0); // punkt kupowania biletów na basen
	print("[SKRYPT:] Zaladowano stale checkpointy");

	
	//=======================================[PICKUPS]=========================================
	//mechanicsPickup = CreateDynamicPickup(1239,2,-1855,127,15,0,-1,-1,50.0); // biuro mechaników
	//gOfficialPickup = CreateDynamicPickup(1239,2,361,171,1008,-1,-1,-1,50.0); // urz¹d
	CreateDynamicPickup(1239,0,-1845.0,129.0,15.0,-1,-1,-1,50.0); // punkt wymiany opon
	CreateDynamicPickup(1239,0,618.0,0.0,1001.0,-1,-1,-1,50.0); // punkt wymiany opon int transfender
	gP_PrisonYard = CreateDynamicPickup(1239, 23, -333.0, 1533.0, 75.0, 0, 0, -1, 100.0 ); // punkt wejscia do wiezienia ZE SPACERNIAKA
	gP_SwimingPool = CreateDynamicPickup(1239, 23, 579.0, -2198.0, 2.0 ); // punkt wejscia na skocznie w basenie
	gP_Lottery = CreateDynamicPickup(1239, 23, 359.0, 167.0, 1008.0 ); // lottery pickup point
	//print("[SKRYPT:] Zaladowano nowe pickupy");
	//========================================[3DTEXT]=========================================
	for( new i = 0; i < CUSTOM_MAX_PLAYERS; i++ )
		gPlayerData[i][pCharDescriptionID] = Create3DTextLabel( " ", COLOR_WHITE, 0.0, 0.0, 0.0, 10.0, -1, 1 );
	
    //======================================[PRZEWODNIK]=======================================
	przewodnik = CreateMenu("Przewodnik po Wparty", 2, 150.0, 100.0, 150.0, 150.0);
	AddMenuItem(przewodnik, 0, "Zasady");
	AddMenuItem(przewodnik, 0, "Kontakt");
	//AddMenuItem(przewodnik, 0, "Licencje");
	//AddMenuItem(przewodnik, 0, "Prace");
	//AddMenuItem(przewodnik, 0, "Opcja 4");
	//AddMenuItem(przewodnik, 0, "Opcja 5");
	prace = CreateMenu("Prace w Wparty", 2, 150.0, 100.0, 150.0, 150.0);
	AddMenuItem(prace, 0, "Pracownik Œmieciarki w MZGK");
	AddMenuItem(prace, 0, "Pracownik Myjki drogowej w MZGK");
	AddMenuItem(prace, 0, "Kierowca Autobusu PKS");
	AddMenuItem(prace, 0, "Farmer");
	AddMenuItem(prace, 0, "Mechanik");
	AddMenuItem(prace, 0, "Detektyw");
	AddMenuItem(prace, 0, "Diler broni");
	AddMenuItem(prace, 0, "Diler narkotyków");
	AddMenuItem(prace, 0, "Sprzedawca produktów");
	AddMenuItem(prace, 0, "Praca dziwki");
	AddMenuItem(prace, 0, "Gwa³ciciel");
	AddMenuItem(prace, 0, "Kontynuakcja listy prac");

	prace2 = CreateMenu("Prace w Wparty", 2, 150.0, 100.0, 150.0, 150.0);
	AddMenuItem(prace2, 0, "Prawnik");
	AddMenuItem(prace2, 0, "Boxer");
	AddMenuItem(prace2, 0, "Z³odziej samochodów");
	AddMenuItem(prace2, 0, "Kaskader");
	AddMenuItem(prace2, 0, "Re¿yser");
	AddMenuItem(prace2, 0, "Ochroniarz");

	licencje = CreateMenu("Licencje w Wparty", 2, 150.0, 100.0, 150.0, 150.0);
	AddMenuItem(licencje, 0, "Prawo Jazdy");
	AddMenuItem(licencje, 0, "Licencja Pilota");
	AddMenuItem(licencje, 0, "Licencja na Bron");
	AddMenuItem(licencje, 0, "Licencja na Lodzie");
	//new samid;
	print("[SKRYPT:] Zaladowano przewodnik");
	
	//=======================================[SAM SITES]=======================================
	AddStaticSAMEx(-1395.0, 493.0, 20.0, 1000.0, 80.0);
	AddStaticSAMEx(-1324.0, 493.0, 22.0, 1000.0, 80.0);
	SAM_start();

	//========================================[TIMERS]=========================================
	SetTimer("Update",70000,1);//Update every less than 2 minutes
	//SetTimer("PickupGametexts",500,1); //Timer that shows gametexts if the player is on a pickup/location. - deprecated, using ysi timers
	//SetTimer("FuelTimer",5000,1); // Car Fuel System - deprecated, using ysi timers
	//SetTimer("CheckPointTimer",250,1);
	//SetTimer("OneSecTimer",1000,1); // VehicleStatusCheck, JailTimer, DistanceCheck, StreamPickups, UpdateMoney, RaceCountdownTimer, Targeting, GPS  - deprecated, using ysi timers
	//SetTimer("OneMinTimer",60000,1); // GangWarTimer - deprecated, using ysi timers
	//SetTimer("TenMinTimer",600000,1); // Informations, SaveCarsLocations, VIPTimeCheck, PlayerSavePos - deprecated, using ysi timers
	//SetTimer("OneHourTimer",3600000,1); // CarResetT, GangTerritoryEarn - deprecated, uzyto ysi
	// SetTimer("LifeDecreaser",180000,1); // zmniejsza zycie - skrypt jedzenia
	//SetTimer("Camera1",2000,1); // WTF do czego to ?

	//=================================[TIMERS IN FUNCTIONS]===================================
	/*
	SetTimerEx("DrugEffect", 2500, false, "i", playerid);
	SetTimerEx("DrugEffectHard", 1000, false, "i", playerid);
	*/
	//======================================[OFF TIMERS]=======================================
	/*
	SetTimer("UpdateMoney", 1000, 1);//AntiMoney hack timer
	SetTimer("JailTimer", 1000, 1);
	SetTimer("CheckGateTaxi", 2200, true);
	SetTimer("CheckGateVla1", 500, true);
	SetTimer("DistanceCheck",1000,1);
	SetTimer("LifeCheck",500,1);
	SetTimer("WarTimer",5000,1); // nie dzia³a
	SetTimer("BusCheckpointTimer",1000,1);
	SetTimer("MzgkCheckpointTimer",1000,1);
	SetTimer("SweeperCheckpointTimer",1000,1);
	SetTimer("FarmerCheckpointTimer",1000,1);
	SetTimer("VehicleStatusCheck",1000,1);
	SetTimer("VehicleStatusCheck2",1000,1);
	SetTimer("MapLocationTimer", 500, 1);
	*/
	//======================================[TEXT DRAWS]=======================================

	/* Fade out box for BW */
	gBlackBox = TextDrawCreate( 0.0, 0.0, "_" );
	TextDrawUseBox( gBlackBox, true );
	TextDrawColor( gBlackBox, 0 );
	TextDrawBoxColor( gBlackBox, 0x00000000 );
	
	// napis www
 	// title = TextDrawCreate(220.000000,405.000000,"wpartyrp.pl");
	// TextDrawAlignment(title,0);
	// TextDrawBackgroundColor(title,0x000000ff);
	// TextDrawFont(title,3);
	// TextDrawLetterSize(title,0.599999,1.900000);
	// TextDrawColor(title,0xff0000ff);
	// TextDrawSetOutline(title,1);
	// TextDrawSetProportional(title,1);
	// TextDrawSetShadow(title,1);

	// status gracza ??
	for(new i; i < CUSTOM_MAX_PLAYERS; i++)
	{
		Status[i] = TextDrawCreate(88.000000,312.000000," ");
		TextDrawAlignment(Status[i],2);
		TextDrawBackgroundColor(Status[i],0x000000ff);
		TextDrawFont(Status[i],1);
		TextDrawLetterSize(Status[i],0.299999,1.200000);
		TextDrawColor(Status[i],0xffffffff);
		TextDrawSetOutline(Status[i],1);
		TextDrawSetProportional(Status[i],1);
		TextDrawSetShadow(Status[i],1);
	}

	// status gracza
	for(new i; i < CUSTOM_MAX_PLAYERS; i++)
	{
		PlayerStatus[i] = TextDrawCreate(0.0, 440.0, " ");
		TextDrawUseBox(PlayerStatus[i],1);
		TextDrawBoxColor(PlayerStatus[i],0x000000AA);
		TextDrawAlignment(PlayerStatus[i],0);
		TextDrawBackgroundColor(PlayerStatus[i],0x000000ff);
		TextDrawFont(PlayerStatus[i],1);
		TextDrawLetterSize(PlayerStatus[i],0.199999,0.700000);
		TextDrawColor(PlayerStatus[i],0xffffffff);
		TextDrawSetOutline(PlayerStatus[i],1);
		TextDrawSetProportional(PlayerStatus[i],1);
		TextDrawSetShadow(PlayerStatus[i],1);
	}

	// status pojazdu gracza
	for(new i; i < CUSTOM_MAX_PLAYERS; i++)
	{
		VehicleStatus[i] = TextDrawCreate(0.000000,430.600000," ");
		TextDrawUseBox(VehicleStatus[i],1);
		TextDrawBoxColor(VehicleStatus[i],0x000000AA);
		TextDrawAlignment(VehicleStatus[i],0);
		TextDrawBackgroundColor(VehicleStatus[i],0x000000ff);
		TextDrawFont(VehicleStatus[i],1);
		TextDrawLetterSize(VehicleStatus[i],0.199999,0.700000);
		TextDrawColor(VehicleStatus[i],0xffffffff);
		TextDrawSetOutline(VehicleStatus[i],1);
		TextDrawSetProportional(VehicleStatus[i],1);
		TextDrawSetShadow(VehicleStatus[i],1);
	}
	//========================================[OBJECTS]========================================
	pdgate1a = CreateDynamicObject(971,-1635.600000,688.500000,7.468800,0.000000,0.000000,180.0000); // gate1a
	pdgate1b = CreateDynamicObject(971,-1627.790000,688.500000,7.468800,0.000000,0.000000,180.0000); // gate1b
	pdgate2a = CreateDynamicObject(976,-293.45800781,1507.03222656,74.46191406,0.00000000,0.00000000,180.74707031); //object(phils_compnd_gate) (1)
	pdgate2b = CreateDynamicObject(976,-302.32324219,1506.92089844,74.46191406,0.00000000,0.00000000,180.74157715); //object(phils_compnd_gate) (2)
	pdgate2c = CreateDynamicObject(976,-293.45800781,1507.03222656,77.58695221,0.00000000,0.00000000,180.74707031); //object(phils_compnd_gate) (1)
	pdgate2d = CreateDynamicObject(976,-302.32324219,1506.92089844,77.58695221,0.00000000,0.00000000,180.74157715); //object(phils_compnd_gate) (2);
	//yakuzagate1 = CreateStreamObject(988, -2126.8876953125, 20.220703125, 35.191345214844, 0.000000, 0.000000, 180.71411132813, 250.0);
	MoveDynamicObject(pdgate1a,-1635.600000,688.500000,7.468800, 1.5);
	MoveDynamicObject(pdgate1b,-1627.790000,688.500000,7.468800, 1.5);
	//mgate2a = CreateObject(968, -1526.31958, 481.32641, 7.17968, 0.000000,270.000000,0.0000);
	//MoveObject(mgate2a,-1526.31958,481.32641, 7.17968, 1.5);
	CreateDynamicObject(14877, -2693.0036621094, 1584.7528076172, 0.075000002980232, 0.000000, 0.000000, 90.325012207031); // schody dla mara
	HQ = CreateDynamicObject(980, -1990.5186767578, 543.30401611328, 36.789016723633, 0.0000, 0.0000, 90.000);
    HQ2 = CreateDynamicObject(985, -2061.861328125, 434.58581542969, 25.348533630371, 0.0000, 0.0000 , 0.0);
	bramawojsko1 = CreateDynamicObject(968, -1526.3221435547, 481.37817382813, 7.5000000000000, 0.000000, 270.19006347656, 359.99487304688);
    bramawojsko2 = CreateDynamicObject(968, -1548.1329345703, 512.18304443359, 6.7313146591187, 0.000000, 359.74731445313, 79.8076171875);
    bramawojsko3 = CreateDynamicObject(968, -1547.5684814453, 518.17321777344, 6.7313146591187, 0.000000, 359.75, 82.370025634766);
    slums = CreateDynamicObject(968, -1923.5104980469, 1159.3200683594, 45.32926940918, 0.000000, 0.000000, 0.000000);
	zomo1 = CreateDynamicObject(968, -1572.1822509766, 658.74877929688, 6.7435255050659, 0.000000, 89.090026855469, 90.055816650391);
	zomo2 = CreateDynamicObject(968, -1701.4306640625, 687.67700195313, 24.515615463257, 0.000000, 270.92498779297, 89.785400390625);
	mostpol1 = CreateDynamicObject(968, -2671.6064453125, 1280.2763671875, 55.559833526611, 0.000000, 0.000000, 0.000000);
	mostpol2 = CreateDynamicObject(968, -2673.4760742188, 1280.4490966797, 55.559833526611, 0.000000, 0.000000, 0.000000);
	mostpol3 = CreateDynamicObject(968, -2682.7377929688, 1268.826171875, 55.559833526611, 0.000000, 0.000000, 0.000000);
	mostpol4 = CreateDynamicObject(968, -2691.3725585938, 1268.7795410156, 55.559833526611, 0.000000, 0.000000, 0.000000);
	//parkgate1a = CreateDynamicObject(969, -3072.5986328125, 422.12594604492, 1.2798770666122, 0, 359.955078125, 276.65991210938, 250.0 ); //
	//parkgate1b = CreateDynamicObject(969, -3073.4038085938, 428.12539672852, 1.2798770666122, 0, 359.95056152344, 277.40795898438, 250.0 ); //
	//parkgate2 = CreateDynamicObject(969, -3074.2590332031, 400.93130493164, 11.477691650391, 0, 0, 186.87005615234, 250.0 ); //
	//parkgate2a = CreateDynamicObject(969, -3110.4201660156, 396.7969665527, 16.896947860718, 0, 0, 5.75, 250.0 ); //
	//parkgate3 = CreateDynamicObject(969, -3074.3471679688, 401.5930480957, 16.802698135376, 0, 0, 186.86645507813, 250.0 ); //
	//parkmost = CreateDynamicObject(9001, -2990.7666015625, 431.8955078125, 6.5404720306396, 359.99987792969, 359.75, 97.248291015625); // molo
	bramataxi1 = CreateDynamicObject(968, -1739.2216796875, 985.66516113281, 17.714046478271, 0.000000, 90, 100.51501464844); // brama taxi
	bramataxi2 = CreateDynamicObject(968, -1739.2216796875, 985.6650390625, 17.714046478271, 0.000000, 90, 239.47900390625); // brama taxi
	CreateDynamicObject(656, -2706.4375, 376.458618, 3.768813, 0.0, 0.0, 0.0); // choinka

	// CreateDynamicObjects();
	return 1;
} // end of OnGameModeInit

public OnGameModeExit()
{
	djson_GameModeExit();
	print("[SCRIPT:] WRPG script closed");
	return 1;
}