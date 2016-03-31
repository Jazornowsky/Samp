/***
*
* File: wp_ongamemodestock.inc
* Auth: Damian Wojdat
* Date: 15.09.2011
* Desc: Declarations, macros and variables.
*
*************************************************************************************************************/

public OnGameModeInit()
{
	printf("[INIT:] OnGameModeInit started - WP-RP %s", VERSION);
    SetGameModeText("WP-RP v.1.32");
	
	// TODO: house cost should be transfered to somekind of house faction manager
	// For now cash from house goes nowhere...
	// Same with businesses
	
	// TODO: There should be some activities in house (except item taking, etc.) that requires player
	// 		to come back to house more often
	
	//dmap_GameModeInit();
	//printf("ABCD");
	//printf("strlen = %d", strlen("ABCD"));
	//printf("first letter pos = %d", strfind("ABCD", "A"));
	//printf("last letter pos = %d", strfind("ABCD", "D"));
	
	/*
	* Anti DeAMX
	*/
	new a[][] =
	{
		"Unarmed (Fist)",
		"Brass K"
	};
	#pragma unused a
	
	/*
	* SAMP internal settings set
	*/
	ShowPlayerMarkers(0);
	EnableStuntBonusForAll(0);
    DisableInteriorEnterExits();
    AllowInteriorWeapons(0);
	SetNameTagDrawDistance(15.0);
	ManualVehicleEngineAndLights();
	DisableNameTagLOS();
	ShowNameTags(0);

	/*
	* MySQL database connection
	*/
	print("[INFO:] Laczenie z baza danych...");

	// LoadConfig loads MySQL connection data from file
	// LoadConfig();
	
	printf("[INFO:] Using %s as database", db_database);
	
	if(!(db_con1 = mysql_connect(db_host,db_user,db_database,db_pass)))
	{
		GameModeExit();
		return 1;
	}
	if(!(db_con2 = mysql_connect(db_host,db_user,db_database,db_pass)))
	{
		GameModeExit();
		return 1;
	}
	if(!(db_con3 = mysql_connect(db_host,db_user,db_database,db_pass)))
	{
		GameModeExit();
		return 1;
	}
	if(!(db_con4 = mysql_connect(db_host,db_user,db_database,db_pass)))
	{
		GameModeExit();
		return 1;
	}
	// if(!(db_con5 = mysql_connect(db_host,db_user,db_database, db_pass)))
	// {
		// GameModeExit();
		// return 1;
	// }
	// if(!mysql_ping(db_con5))
	// {
		// GameModeExit();
		// return 1;
	// }
	// new string[20];
	// format(string, sizeof(string), "ascii");
	// mysql_set_charset(string, db_con1);
	// mysql_set_charset(string, db_con2);
	// mysql_set_charset(string, db_con3);
	// mysql_set_charset(string, db_con4);
	// mysql_get_charset(string, db_con1);
	
	/*
	* Begin loading data
	*/
	LoadScript();
	LoadCustomAreas();
	Audio_SetPack("default_pack", true, true);

	/*
	* MWeather locations
	*/
	//MWeather_OnGameModeInit();
	//gMW_warszawa = AddWeatherObserver("http://weather.yahoo.com/united-states/michigan/detroit-2391585/", 1200000);
	//gMW_lasvegas = AddWeatherObserver("http://weather.yahoo.com/united-states/michigan/detroit-2391585/", 1200000);
	//gMW_sanfrancisco = AddWeatherObserver("http://weather.yahoo.com/united-states/michigan/detroit-2391585/", 1200000);
	//gMW_losangeles = AddWeatherObserver("http://weather.yahoo.com/united-states/michigan/detroit-2391585/", 1200000);
	//SetRealWeatherEx(gMW_warszawa);

	// Event2 predef
	gEvent2noteText1 = TextDrawCreate(230.000000, 309.000000, "_");
	TextDrawAlignment(gEvent2noteText1, 0);
	TextDrawBackgroundColor(gEvent2noteText1, 0x000000ff);
	TextDrawFont(gEvent2noteText1, 2);
	TextDrawLetterSize(gEvent2noteText1, 0.899999, 2.599999);
	TextDrawColor(gEvent2noteText1, 0xffff00ff);
	TextDrawSetOutline(gEvent2noteText1, 1);
	TextDrawSetProportional(gEvent2noteText1, 1);
	TextDrawSetShadow(gEvent2noteText1, 1);
	
	ResetEventsVariables();
	
	/*
	* Fireworks script data load
	*/
	// djson plugin load
	// djson_GameModeInit();
	
	// if(!fexist("FireWorkInfo"))
	// {
		// djCreateFile("FireWorkInfo");
		// djSetInt("FireWorkInfo","FireCrackerAL", 0);
	    // djSetInt("FireWorkInfo","FireRocket1AL", 0);
	    // djSetInt("FireWorkInfo","FireRocket2AL", 0);
	    // djSetInt("FireWorkInfo","CrackerrollAL", 0);
	    // djSetInt("FireWorkInfo","Fountain1AL", 0);
	    // djSetInt("FireWorkInfo","Fountain2AL", 0);
	    // djSetInt("FireWorkInfo","Fountain3AL", 0);
	    // djSetInt("FireWorkInfo","RocketBAL", 0);
	    // djSetInt("FireWorkInfo","DrawDistance", 1);
	    // print("[FWCP]: FireWorkInfo file created");
	// }
	// SetTimer("Load", 3000, 0);
	
	/*
	* Default data set
	*/
	// Radio channels
	strmid(gRadio[0], "http://radioparty.pl/play/glowny_48.m3u", 0, 128, 255); // radioparty.pl
	strmid(gRadio[1], "http://radioparty.pl/play/djmixes_64aac.m3u", 0, 128, 255); // radio zet
	strmid(gRadio[2], "http://radioparty.pl/play/house_64aac.m3u", 0, 128, 255); // radio zet
	strmid(gRadio[3], "http://radioparty.pl/play/trance_64aac.m3u", 0, 128, 255); // radio zet
	strmid(gRadio[4], "http://radioparty.pl/play/vtrance_64aac.m3u", 0, 128, 255); // radio zet
	strmid(gRadio[5], "http://radioparty.pl/play/dnb_64aac.m3u", 0, 128, 255); // radio zet
	strmid(gRadio[6], "http://radioparty.pl/play/hard_64aac.m3u", 0, 128, 255); // radio zet
	strmid(gRadio[7], "http://radioparty.pl/play/chillout_64aac.m3u", 0, 128, 255); // radio zet
	strmid(gRadio[8], "http://www.radiozet.pl/externals/radiozet-streams/radiozet_stream.pls", 0, 128, 255); // radio zet
	strmid(gRadio[9], "http://www.miastomuzyki.pl/odbior/rmfcl_aacp.pls", 0, 128, 255); // radio zet
	strmid(gRadio[10], "http://www.miastomuzyki.pl/odbior/rmf_aacp.pls", 0, 128, 255); // radio zet
	strmid(gRadio[11], "http://wroclaw.radio.pionier.net.pl:8000/pl/eskarock.mp3.m3u", 0, 128, 255); // radio zet
	strmid(gRadio[12], "http://yp.shoutcast.com/sbin/tunein-station.pls?id=1277114", 0, 128, 255); // radio zet
	strmid(gRadio[13], "http://yp.shoutcast.com/sbin/tunein-station.pls?id=1270718", 0, 128, 255); // radio zet
	strmid(gRadio[14], "http://yp.shoutcast.com/sbin/tunein-station.pls?id=1377200", 0, 128, 255); // radio zet
	strmid(gRadio[15], "http://yp.shoutcast.com/sbin/tunein-station.pls?id=695657", 0, 128, 255); // radio zet
	strmid(gRadio[16], "http://87.98.222.178/HIPHOP?.wma", 0, 128, 255); // radio zet
	
	/*
	* Hardcoded default checkpoints
	*/
	for(new i = 0; i < sizeof(BankPosition); i++)
	{
		BankPosition[i][mPickupId] = CreateDynamicPickup(1239, 1, BankPosition[i][X], BankPosition[i][Y], BankPosition[i][Z]);
	}
	
	// ATMs
	for(new i = 0; i < sizeof(gAtmCp); i++)
	{
		gAtmCp[i] = CreateDynamicCP(gATM[i][0], gATM[i][1], gATM[i][2], 1.0, -1, -1, -1, 5.0);
	}
	
	// rafinery refuel and manage cp
	gRafinery[RafResourceCP] = CreateDynamicCP(-985.0, -708.0, 32.0, 10.0);
	
	// government cp for work and taxes purpose
	gGovCheckpoint = CreateDynamicCP(358.67, 169.11, 1008.38, 1.0);
	gGovCheckpoint2 = CreateDynamicCP(358.63, 178.70, 1008.38, 1.0);
	
	// medic checkpoints
	gMedicCheckpoints[0] = CreateDynamicCP(-2675.36, 650.29, 10.29, 1.0);
	gMedicCheckpoints[1] = CreateDynamicCP(1124.88, -2520.29, 113.81, 1.0);
	gMedicCheckpoints[2] = CreateDynamicCP(285.58, 1893.55, 499.28, 1.0);

	// businesses buy cp
	gShopCP[0] = CreateDynamicCP(-28.0,-185.0,1004.0,0.8);
	gShopCP[1] = CreateDynamicCP(3.0,-29.0,1004.0,0.8);
	gShopCP[2] = CreateDynamicCP(-27.0,-90.0,1004.0,0.8);
	gShopCP[3] = CreateDynamicCP(-21.0,-139.0,1004.0,0.8);
	gShopCP[4] = CreateDynamicCP(-30.0,-29.0,1004.0,0.8);
	gShopCP[5] = CreateDynamicCP(-22.0,-56.0,1004.0,0.8);
	gShopCP[6] = CreateDynamicCP(2243.0,1612.93,1018.812438,0.8, -1, -1, -1, 10.0);
	gShopCP[7] = CreateDynamicCP(-2237.26,130.17,1035.52,0.8, -1, -1, -1, 10.0);
	gShopCP[8] = CreateDynamicCP(204.0, -160.0, 1001.0, 0.8, -1, -1, -1, 10.0);
	gShopCP[9] = CreateDynamicCP(209.0, -101.0, 1005.0, 0.8, -1, -1, -1, 10.0);
	gShopCP[10] = CreateDynamicCP(207.0, -129.0, 1004.0, 0.8, -1, -1, -1, 10.0);
	gShopCP[11] = CreateDynamicCP(203.0, -44.0, 1002.0, 0.8, -1, -1, -1, 10.0);
	gShopCP[12] = CreateDynamicCP(207.0, -9.0, 1001.0, 0.8, -1, -1, -1, 10.0);
	gShopCP[13] = CreateDynamicCP(161.0, -84.0, 1002.0, 0.8, -1, -1, -1, 10.0);
	gShopCP[14] = CreateDynamicCP(297.0, -38.0, 1002.0, 0.8, -1, -1, -1, 10.0);
	gShopCP[15] = CreateDynamicCP(295.0, -81.0, 1002.0, 0.8, -1, -1, -1, 10.0);
	gShopCP[16] = CreateDynamicCP(288.0, -109.0, 1002.0, 0.8, -1, -1, -1, 10.0);
	gShopCP[17] = CreateDynamicCP(313.0, -166.0, 1000.0, 0.8, -1, -1, -1, 10.0);
	gShopCP[18] = CreateDynamicCP(-783.0, 500.0, 1372.0, 0.8, -1, -1, -1, 10.0 );
	gShopCP[19] = CreateDynamicCP(377.0, -68.0, 1002.0, 0.8, -1, -1, -1, 10.0 );
	gShopCP[20] = CreateDynamicCP(373.0, -66.0, 1002.0, 0.8, -1, -1, -1, 10.0 );
	gShopCP[21] = CreateDynamicCP(368.0, -6.0, 1002.0, 0.8, -1, -1, -1, 10.0);
	gShopCP[22] = CreateDynamicCP(371.0, -6.0, 1002.0, 0.8, -1, -1, -1, 10.0);
	gShopCP[23] = CreateDynamicCP(377.0, -119.0, 1001.0, 0.8, -1, -1, -1, 10.0);
	gShopCP[24] = CreateDynamicCP(375.0, -119.0, 1001.0, 0.8, -1, -1, -1, 10.0);
	gShopCP[25] = CreateDynamicCP(373.0, -119.0, 1001.0, 0.8, -1, -1, -1, 10.0);
	gShopCP[26] = CreateDynamicCP(381.0, -191.0, 1001.0, 0.8, -1, -1, -1, 10.0);
	gShopCP[27] = CreateDynamicCP(451.0, -84.0, 1000.0, 0.8, -1, -1, -1, 10.0);
	gShopCP[28] = CreateDynamicCP(449.0, -84.0, 1000.0, 0.8, -1, -1, -1, 10.0);
	gShopCP[29] = CreateDynamicCP(500.0, -75.72, 998.75, 0.8, -1, -1, -1, 10.0);
	gShopCP[30] = CreateDynamicCP(500.0, -75.72, 998.75, 0.8, -1, -1, -1, 10.0);
	gShopCP[31] = CreateDynamicCP(498.47, -76.04, 998.75, 0.8, -1, -1, -1, 10.0);
	gShopCP[32] = CreateDynamicCP(496.80, -75.98, 998.75, 0.8, -1, -1, -1, 10.0);
	gShopCP[33] = CreateDynamicCP(493.37, -76.03, 998.75, 0.8, -1, -1, -1, 10.0);
	gShopCP[34] = CreateDynamicCP(492.03, -77.30, 998.75, 0.8, -1, -1, -1, 10.0);
	gShopCP[35] = CreateDynamicCP(492.03, -79.97, 998.75, 0.8, -1, -1, -1, 10.0);
	gShopCP[36] = CreateDynamicCP(499.96, -22.51, 1000.67, 0.8, -1, -1, -1, 10.0);
	gShopCP[37] = CreateDynamicCP(499.96, -20.71, 1000.67, 0.8, -1, -1, -1, 10.0);
	gShopCP[38] = CreateDynamicCP(499.96, -18.74, 1000.67, 0.8, -1, -1, -1, 10.0);
	gShopCP[39] = CreateDynamicCP(499.96, -17.13, 1000.67, 0.8, -1, -1, -1, 10.0);
	gShopCP[40] = CreateDynamicCP(502.18, -15.28, 1000.67, 0.8, -1, -1, -1, 10.0);
	gShopCP[41] = CreateDynamicCP(-224.78, 1403.23, 27.77, 0.8, -1, -1, -1, 10.0);
	gShopCP[42] = CreateDynamicCP(-224.78, 1407.52, 27.77, 0.8, -1, -1, -1, 10.0);
	gShopCP[43] = CreateDynamicCP(-223.29, 1409.38, 27.77, 0.8, -1, -1, -1, 10.0);
	gShopCP[44] = CreateDynamicCP(-2654.01, 1407.22, 906.27, 0.8, -1, -1, -1, 10.0);
	gShopCP[45] = CreateDynamicCP(-2656.35, 1405.18, 906.27, 0.8, -1, -1, -1, 10.0);
	gShopCP[46] = CreateDynamicCP(-2662.00, 1405.18, 906.27, 0.8, -1, -1, -1, 10.0);
	gShopCP[47] = CreateDynamicCP(-2664.32, 1407.23, 906.27, 0.8, -1, -1, -1, 10.0);
	gShopCP[48] = CreateDynamicCP(-2664.33, 1413.32, 906.27, 0.8, -1, -1, -1, 10.0);
	gShopCP[49] = CreateDynamicCP(-2662.27, 1415.44, 906.27, 0.8, -1, -1, -1, 10.0);
	gShopCP[50] = CreateDynamicCP(-2656.27, 1415.44, 906.27, 0.8, -1, -1, -1, 10.0);
	gShopCP[51] = CreateDynamicCP(-2653.99, 1413.41, 906.27, 0.8, -1, -1, -1, 10.0);
	gShopCP[52] = CreateDynamicCP(-460.63, -2014.97, 24.78, 0.8, -1, -1, -1, 10.0);
	gShopCP[53] = CreateDynamicCP(1240.11, -1651.99, 11.80, 0.8, -1, -1, -1, 10.0);
	gShopCP[54] = CreateDynamicCP(1234.82, -1651.99, 11.80, 0.8, -1, -1, -1, 10.0);
	gShopCP[55] = CreateDynamicCP(1231.82, -1649.92, 11.80, 0.8, -1, -1, -1, 10.0);
	gShopCP[56] = CreateDynamicCP(1207.23, -30.98, 1000.95, 0.8, -1, -1, -1, 10.0);
	gShopCP[57] = CreateDynamicCP(681.35, -453.83, -25.61, 0.8, -1, -1, -1, 10.0);
	gShopCP[58] = CreateDynamicCP(1139.72, -6.75, 1000.67, 0.8, -1, -1, -1, 10.0);
	gShopCP[59] = CreateDynamicCP(0.0, 0.0, 1004.17, 0.8, -1, -1, -1, 10.0);
	gShopCP[60] = CreateDynamicCP(0.0, 0.0, 1004.17, 0.8, -1, -1, -1, 10.0);
	gShopCP[61] = CreateDynamicCP(0.0, 0.0, 1004.17, 0.8, -1, -1, -1, 10.0);
	gShopCP[62] = CreateDynamicCP(0.0, 0.0, 1004.17, 0.8, -1, -1, -1, 10.0);
	gShopCP[59] = CreateDynamicCP(-103.88, -22.67, 1000.74, 0.8, -1, -1, -1, 10.0);
	gShopCP[60] = CreateDynamicCP(-105.42, -10.61, 1000.74, 0.8, -1, -1, -1, 10.0);
	gShopCP[61] = CreateDynamicCP(1242.19, -1649.01, 11.80, 0.8, -1, -1, -1, 10.0);
	gShopCP[62] = CreateDynamicCP(370.14, -1693.02, 17.0, 0.8, -1, -1, -1, 10.0);
	gShopCP[63] = CreateDynamicCP(1484.97, 1292.31, 1010.82, 0.8, -1, -1, -1, 10.0);
	gShopCP[64] = CreateDynamicCP(1508.89, 1551.10, 1010.85, 0.8, -1, -1, -1, 10.0);
	gShopCP[65] = CreateDynamicCP(1247.06, -670.85, 1194.2, 0.8, -1, -1, -1, 10.0);
	gShopCP[66] = CreateDynamicCP(1687.13, -1454.92, 13.57, 0.8, -1, -1, -1, 10.0);
	gShopCP[67] = CreateDynamicCP(1668.4, -1461.93, 17.11, 0.8, -1, -1, -1, 10.0);
	gShopCP[68] = CreateDynamicCP(-394.7, 281.68, 489.96, 0.8, -1, -1, -1, 10.0);
	gShopCP[69] = CreateDynamicCP(1645.65, -1456.13, 13.67, 0.8, -1, -1, -1, 10.0);
	gShopCP[70] = CreateDynamicCP(310.23, 1830.11, 1597.99, 0.8, -1, -1, -1, 10.0);
	gShopCP[71] = CreateDynamicCP(2902.77, 2471.81, -43.83, 0.8, -1, -1, -1, 10.0);
	gShopCP[72] = CreateDynamicCP(2051.47, -1871.36, 14.70, 0.8, -1, -1, -1, 10.0);
	gShopCP[73] = CreateDynamicCP(2493.22, -1782.49, 1014.53, 0.8, -1, -1, -1, 10.0);
	gShopCP[74] = CreateDynamicCP(962.59, -1554.22, 21.51, 0.8, -1, -1, -1, 10.0);

	for(new i = 0; i < sizeof(gPrisonCells); i++)
	{
		gPrisonCellsCp[i] = CreateDynamicCP(gPrisonCells[i][mPosXCellEntrance], gPrisonCells[i][mPosYCellEntrance], gPrisonCells[i][mPosZCellEntrance], 1.0);
	}
	gMainPrisonCp = CreateDynamicCP(gMainPrisonPos[0], gMainPrisonPos[1], gMainPrisonPos[2], 3.0, -1, -1, -1, 5.0);
	
	// businesses buy clothes cp
	gClotheShopCP[0] = CreateDynamicCP(199.15, -128.51, 1003.51, 0.8, -1, -1, -1, 10.0);
	gClotheShopCP[1] = CreateDynamicCP(215.79, -159.42, 1000.53, 0.8, -1, -1, -1, 10.0);
	gClotheShopCP[2] = CreateDynamicCP(217.06, -98.62, 1005.25, 0.8, -1, -1, -1, 10.0);
	gClotheShopCP[3] = CreateDynamicCP(213.58, -41.62, 1002.02, 0.8, -1, -1, -1, 10.0);
	gClotheShopCP[4] = CreateDynamicCP(207.20, -4.85, 1001.21, 0.8, -1, -1, -1, 10.0);
	gClotheShopCP[5] = CreateDynamicCP(180.88, -87.94, 1002.03, 0.8, -1, -1, -1, 10.0);
	
	// horse betting point
	gHorsesCp[0] = CreateDynamicCP(833.60, 3.22, 1004.17, 0.8, -1, -1, -1, 10.0);
	gHorsesCp[1] = CreateDynamicCP(830.65, -0.13, 1004.17, 0.8, -1, -1, -1, 10.0);
	
	// stolen vehicle export points
	gVehExport[mCpId1] = CreateDynamicCP(gVehExport[mPosX1], gVehExport[mPosY1], gVehExport[mPosZ1], 10.0, 0, 0, -1, 5000.0);
	gVehExport[mCpId2] = CreateDynamicCP(gVehExport[mPosX2], gVehExport[mPosY2], gVehExport[mPosZ2], 10.0, 0, 0, -1, 5000.0);
	gVehExport[mCpId3] = CreateDynamicCP(gVehExport[mPosX3], gVehExport[mPosY3], gVehExport[mPosZ3], 10.0, 0, 0, -1, 5000.0);
	gVehExport[mCpId4] = CreateDynamicCP(gVehExport[mPosX4], gVehExport[mPosY4], gVehExport[mPosZ4], 10.0, 0, 0, -1, 5000.0);
	gVehExport[mCpId5] = CreateDynamicCP(gVehExport[mPosX5], gVehExport[mPosY5], gVehExport[mPosZ5], 10.0, 0, 0, -1, 5000.0);
	gVehExport[mCpId6] = CreateDynamicCP(gVehExport[mPosX6], gVehExport[mPosY6], gVehExport[mPosZ6], 10.0, 0, 0, -1, 5000.0);
	gVehExport[mCpId7] = CreateDynamicCP(gVehExport[mPosX7], gVehExport[mPosY7], gVehExport[mPosZ7], 10.0, 0, 0, -1, 5000.0);	
	
	#if defined DEBUG
		print("[INFO:] Hardcoded checkpoints loaded");
	#endif
	
	/*
	* Hardcoded default pickups
	*/
	// mechanicsPickup = CreateDynamicPickup(1239,2,-1855,127,15,0,-1,-1,50.0); // biuro mechaników
	// gOfficialPickup = CreateDynamicPickup(1239,2,361,171,1008,-1,-1,-1,50.0); // urz¹d
	// CreateDynamicPickup(1239,0,-1845.0,129.0,15.0,-1,-1,-1,50.0); // punkt wymiany opon
	// CreateDynamicPickup(1239,0,618.0,0.0,1001.0,-1,-1,-1,50.0); // punkt wymiany opon int transfender
	
	// exit point from prison yard
	gP_PrisonYard = CreateDynamicPickup(1239, 23, -333.0, 1533.0, 75.0, 0, 0, -1, 100.0);
	
	// swimming pool jump entrance
	gP_SwimingPool = CreateDynamicPickup(1239, 23, 579.0, -2198.0, 2.0);
	
	// lucky lottery pickup point
	gP_Lottery = CreateDynamicPickup(1239, 23, 359.0, 167.0, 1008.38);
	
	// pickup event reward receive point
	gPickupEventPrizeReceive = CreateDynamicPickup(1239, 1, 358.78, 186.86, 1008.38);
	
	#if defined DEBUG
		print("[INFO:] Hardcoded pickups loaded");
	#endif
	
	/*
	* Hardcoded 3d texts
	*/
	for(new i = 0; i < CUSTOM_MAX_PLAYERS; i++)
	{
	//	gPlayerData[i][pCharDescriptionID] = Create3DTextLabel(" ", COLOR_BLACK, 0.0, 0.0, 0.0, 7.0, -1, 1);
		gPlayerData[i][pCharDescriptionID] = CreateDynamic3DTextLabel(" ", COLOR_BLACK, 1720.81, 1443.44, 10.82, 7.0, -1, 1);
		gPlayerData[i][pCharNameID] = Create3DTextLabel(" ", COLOR_BLACK, 0.0, 0.0, 0.0, 7.0, -1, 1);
		playerAFK[i] = Create3DTextLabel(" ", COLOR_BLACK, 0.0, 0.0, 0.0, 7.0, -1, 1);
	}
	
	#if defined DEBUG
		print("[INFO:] Hardcoded 3D Texts loaded");
	#endif
	
	// SAM sites script
	// AddStaticSAMEx(-1395.0, 493.0, 20.0, 1000.0, 80.0);
	// AddStaticSAMEx(-1324.0, 493.0, 22.0, 1000.0, 80.0);
	// SAM_start();

	/*
	* Hardcoded textdraws
	*/
	for(new i = 0; i < CUSTOM_MAX_PLAYERS; i++)
	{
		// Player money box
		// PlayerMoneyBox[i] = TextDrawCreate(630.000000, 79.000000, "   ");
		// TextDrawBackgroundColor(PlayerMoneyBox[i], 255); 
		// TextDrawFont(PlayerMoneyBox[i], 1); 
		// TextDrawLetterSize(PlayerMoneyBox[i], 0.500000, 1.000000); 
		// TextDrawColor(PlayerMoneyBox[i], -1); 
		// TextDrawSetOutline(PlayerMoneyBox[i], 0); 
		// TextDrawSetProportional(PlayerMoneyBox[i], 1); 
		// TextDrawSetShadow(PlayerMoneyBox[i], 1); 
		// TextDrawUseBox(PlayerMoneyBox[i], 1); 
		// TextDrawBoxColor(PlayerMoneyBox[i], 0x000035FF); 
		// TextDrawTextSize(PlayerMoneyBox[i], 470.000000, 49.000000); 
		
		// Player money
		// PlayerMoney[i] = TextDrawCreate(500.000000, 77.000000, "00000000");
		// TextDrawBackgroundColor(PlayerMoney[i], 0xF5F51FFF); 
		// TextDrawFont(PlayerMoney[i], 1); 
		// TextDrawLetterSize(PlayerMoney[i], 0.539999, 2.299999); 
		// TextDrawColor(PlayerMoney[i], 0xCACA09FF); 
		// TextDrawSetOutline(PlayerMoney[i], 1); 
		// TextDrawSetProportional(PlayerMoney[i], 1); 
	
		// Player status
		Status[i] = TextDrawCreate(88.000000,312.000000," ");
		TextDrawAlignment(Status[i],2);
		TextDrawBackgroundColor(Status[i],0x000000ff);
		TextDrawFont(Status[i],1);
		TextDrawLetterSize(Status[i],0.299999,1.200000);
		TextDrawColor(Status[i],0xffffffff);
		TextDrawSetOutline(Status[i],1);
		TextDrawSetProportional(Status[i],1);
		TextDrawSetShadow(Status[i],1);
		
		// Vehicle status
		gPlayerVars[i][mVehicleStatus] = TextDrawCreate(0.0, 434.5, " ");
		TextDrawUseBox(gPlayerVars[i][mVehicleStatus], 1);
		TextDrawBoxColor(gPlayerVars[i][mVehicleStatus], 0x000000AA);
		TextDrawAlignment(gPlayerVars[i][mVehicleStatus], 0);
		TextDrawBackgroundColor(gPlayerVars[i][mVehicleStatus], 0x000000ff);
		TextDrawFont(gPlayerVars[i][mVehicleStatus], 1);
		TextDrawLetterSize(gPlayerVars[i][mVehicleStatus], 0.15, 0.525);
		TextDrawColor(gPlayerVars[i][mVehicleStatus], 0xffffffff);
		TextDrawSetOutline(gPlayerVars[i][mVehicleStatus], 1);
		TextDrawSetProportional(gPlayerVars[i][mVehicleStatus], 1);
		TextDrawSetShadow(gPlayerVars[i][mVehicleStatus], 1);
		
		// Gang War status
		GangWar[i] = TextDrawCreate(10.0, 275.0, " ");
		TextDrawLetterSize(GangWar[i], 0.15, 0.6);
		TextDrawTextSize(GangWar[i], 200.0, 100.0);
		
		// Gang War time status
		GangWarTime[i] = TextDrawCreate(10.0, 285.0, " ");
		TextDrawLetterSize(GangWarTime[i], 0.15, 0.6);
		TextDrawTextSize(GangWarTime[i], 200.0, 100.0);
	}
	
	for(new i = 0; i < MAX_RACES; i++)
	{
		// Race status
		gRaceStatus[i][mRaceInfo] = TextDrawCreate(10.0, 265.0, " ");
		TextDrawLetterSize(gRaceStatus[i][mRaceInfo], 0.15, 0.6);
		TextDrawTextSize(gRaceStatus[i][mRaceInfo], 100.0, 50.0);
		ResetRaceData(i);
	}
	
	// PayDay Message
	gPayDayText = TextDrawCreate(10.0, 315, "OTRZYMALES WYCIAG Z KONTA (/wyplata)");
	TextDrawLetterSize(gPayDayText, 0.15, 0.6);
	TextDrawTextSize(gPayDayText, 100.0, 50.0);
	
	// Phone Call
	gPhoneCall = TextDrawCreate(10.0, 305, "PRZYCHODZACE POLACZENIE (/odbierz)");
	TextDrawLetterSize(gPhoneCall, 0.15, 0.6);
	TextDrawTextSize(gPhoneCall, 100.0, 50.0);
	
	// Phone Message
	gPhoneText = TextDrawCreate(10.0, 295, "NOWA WIADOMOSC SMS");
	TextDrawLetterSize(gPhoneText, 0.15, 0.6);
	TextDrawTextSize(gPhoneText, 100.0, 50.0);
	
	// Health Description
	//gHealthTextEnergy = TextDrawCreate(610.0, 108.6, "energia~n~glod~n~pragnienie~n~zatrucie~n~cholesterol~n~zoladek~n~witaminy~n~alkohol~n~narkotyki");
	gHealthTextEnergy = TextDrawCreate(610.0, 108.6, "energia~n~glod~n~pragnienie");
	TextDrawLetterSize(gHealthTextEnergy, 0.12, 0.58);
	TextDrawTextSize(gHealthTextEnergy, 50.0, 100.0);
	TextDrawSetShadow(gHealthTextEnergy, 0);
	
	// gTextDate = TextDrawCreate(547.000000, 11.000000, "--");
	// TextDrawFont(Date, 3);
	// TextDrawLetterSize(Date, 0.399999, 1.600000);
    // TextDrawColor(Date, 0xffffffff);
	// TextDrawSetShadow(Time, 0);
	// TextDrawSetOutline(Time, 2);

	gTextTime = TextDrawCreate(547.000000, 28.000000, "--");
	TextDrawFont(gTextTime, 3);
	TextDrawLetterSize(gTextTime, 0.399999, 1.600000);
	TextDrawColor(gTextTime, 0xffffffff);
	TextDrawSetShadow(gTextTime, 0);
	TextDrawSetOutline(gTextTime, 2);
	
	// low health text draw
	// gTdLHealth = TextDrawCreate(-20.000000,2.000000,"|");
	// TextDrawUseBox(gTdLHealth,1);
	// TextDrawBoxColor(gTdLHealth,0xE30E0E1F);
	// TextDrawTextSize(gTdLHealth,660.000000,22.000000);
	// TextDrawAlignment(gTdLHealth,0);
	// TextDrawBackgroundColor(gTdLHealth,0x000000ff);
	// TextDrawFont(gTdLHealth,3);
	// TextDrawLetterSize(gTdLHealth,1.000000,52.200000);
	// TextDrawColor(gTdLHealth,0x54E9183F);
	// TextDrawSetOutline(gTdLHealth,1);
	// TextDrawSetProportional(gTdLHealth,1);
	// TextDrawSetShadow(gTdLHealth,1);
	
	// poison text draw
	// gTdPoison = TextDrawCreate(-20.000000,2.000000,"|");
	// TextDrawUseBox(gTdPoison,1);
	// TextDrawBoxColor(gTdPoison,0x54E9180F);
	// TextDrawTextSize(gTdPoison,660.000000,22.000000);
	// TextDrawAlignment(gTdPoison,0);
	// TextDrawBackgroundColor(gTdPoison,0x000000ff);
	// TextDrawFont(gTdPoison,3);
	// TextDrawLetterSize(gTdPoison,1.000000,52.200000);
	// TextDrawColor(gTdPoison,0x54E9183F);
	// TextDrawSetOutline(gTdPoison,1);
	// TextDrawSetProportional(gTdPoison,1);
	// TextDrawSetShadow(gTdPoison,1);
	
	// womit text draw
	// gTdWomit = TextDrawCreate(-20.000000,2.000000,"|");
	// TextDrawUseBox(gTdWomit,1);
	// TextDrawBoxColor(gTdWomit,0x8E6C483A);
	// TextDrawTextSize(gTdWomit,660.000000,22.000000);
	// TextDrawAlignment(gTdWomit,0);
	// TextDrawBackgroundColor(gTdWomit,0x000000ff);
	// TextDrawFont(gTdWomit,3);
	// TextDrawLetterSize(gTdWomit,1.000000,52.200000);
	// TextDrawColor(gTdWomit,0x54E9183F);
	// TextDrawSetOutline(gTdWomit,1);
	// TextDrawSetProportional(gTdWomit,1);
	// TextDrawSetShadow(gTdWomit,1);
	
	#if defined DEBUG
		print("[INFO:] Loaded hardcoded text draws");
	#endif
	
	/*
	* Hardcoded default objects
	*/
	gGateSfPd1a = CreateDynamicObject(971,-1635.600000,688.500000,7.468800,0.000000,0.000000,180.0000);
	gGateSfPd1b = CreateDynamicObject(971,-1627.790000,688.500000,7.468800,0.000000,0.000000,180.0000);
	gGateDmPd1a = CreateDynamicObject(5302, 618.110168, -601.536499, 18.532262, 0.0, 0.0, 180.0);
	gGateDmPd2a = CreateDynamicObject(5302, 618.110168, -597.027770, 18.532262, 0.0, 0.0, 180.0);
	gGatePrison1a = CreateDynamicObject(976,-293.45800781,1507.03222656,74.46191406,0.00000000,0.00000000,180.74707031); //object(phils_compnd_gate) (1)
	gGatePrison1b = CreateDynamicObject(976,-302.32324219,1506.92089844,74.46191406,0.00000000,0.00000000,180.74157715); //object(phils_compnd_gate) (2)
	gGatePrison1c = CreateDynamicObject(976,-293.45800781,1507.03222656,77.58695221,0.00000000,0.00000000,180.74707031); //object(phils_compnd_gate) (1)
	gGatePrison1d = CreateDynamicObject(976,-302.32324219,1506.92089844,77.58695221,0.00000000,0.00000000,180.74157715); //object(phils_compnd_gate) (2);
	MoveDynamicObject(gGateSfPd1a,-1635.600000,688.500000,7.468800, 1.5);
	MoveDynamicObject(gGateSfPd1b,-1627.790000,688.500000,7.468800, 1.5);
	gGateSfParking1a = CreateDynamicObject(980, -1990.5186767578, 543.30401611328, 36.789016723633, 0.0000, 0.0000, 90.000);
    gGateSfParking1b = CreateDynamicObject(985, -2061.861328125, 434.58581542969, 25.348533630371, 0.0000, 0.0000 , 0.0);
	gGateSfMilitary1a = CreateDynamicObject(968, -1526.3221435547, 481.37817382813, 7.5000000000000, 0.000000, 270.19006347656, 359.99487304688);
    gGateSfMilitary2a = CreateDynamicObject(968, -1548.1329345703, 512.18304443359, 6.7313146591187, 0.000000, 359.74731445313, 79.8076171875);
    gGateSfMilitary3a = CreateDynamicObject(968, -1547.5684814453, 518.17321777344, 6.7313146591187, 0.000000, 359.75, 82.370025634766);
    gGateSfGov1a = CreateDynamicObject(968, -1923.5104980469, 1159.3200683594, 45.32926940918, 0.000000, 0.000000, 0.000000);
	gGateSfPd2a = CreateDynamicObject(968, -1572.1822509766, 658.74877929688, 6.7435255050659, 0.000000, 89.090026855469, 90.055816650391);
	gGateSfPd3a = CreateDynamicObject(968, -1701.430664, 687.677, 24.65, 0.0, 270.0, 90.0, 0, 0, -1, 100.0);
	gGateSfGov2a = CreateDynamicObject(968, -2671.6064453125, 1280.2763671875, 55.559833526611, 0.000000, 0.000000, 0.000000);
	gGateSfGov3a = CreateDynamicObject(968, -2673.4760742188, 1280.4490966797, 55.559833526611, 0.000000, 0.000000, 0.000000);
	gGateSfGov4a = CreateDynamicObject(968, -2682.7377929688, 1268.826171875, 55.559833526611, 0.000000, 0.000000, 0.000000);
	gGateSfGov5a = CreateDynamicObject(968, -2691.3725585938, 1268.7795410156, 55.559833526611, 0.000000, 0.000000, 0.000000);
	gGateSfTaxi1a = CreateDynamicObject(968, -1739.2216796875, 985.66516113281, 17.714046478271, 0.000000, 90, 100.51501464844);
	gGateSfTaxi2a = CreateDynamicObject(968, -1739.2216796875, 985.6650390625, 17.714046478271, 0.000000, 90, 239.47900390625);
	gGateLsPd1 = CreateDynamicObject(975, 1589.03, -1638.09, 14.14, 0.0, 0.0, 0.0);
	
	#if defined DEBUG
		print("[INFO:] Loaded hardcoded objects");
	#endif
	
	return 1;
} // end of OnGameModeInit

public OnGameModeExit()
{
	print("[SCRIPT:] WRPG script closed");
	return 1;
}