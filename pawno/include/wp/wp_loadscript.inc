/***
*
* File: wp_loadscript.inc
* Auth: Damian Wojdat
* Date: 15.09.2011
* Desc: Launch script setup functions.
*
*************************************************************************************************************/

LoadScript()
{
	print("[INFO:] LoadScript started");
	
	LoadDynamicFactions();
	LoadDynamicZones();
	LoadDynamicCarSpawns();
	LoadDynamicBoatsSpawns();
	LoadDynamicPlanesSpawns();
	LoadDynamicCars();
	LoadCivilianSpawn();
	LoadBuildings();
	LoadHouses(houseSource);
	LoadGasStations();
	LoadBusinesses();
	LoadDrivingTestPosition();
	LoadSkillPosition();
	LoadSkillPositionb();
	LoadSkillPositionc();
	LoadSkillPositiond();
	LoadSkillPositione();
	LoadSkillPositionf();
	LoadBoatTestPosition();
	LoadPlaneTestPosition();
	LoadPoliceComputerPassword();
	LoadDynamicTaxes();
	LoadWeaponLicensePosition();
	LoadTaxiJob();
	LoadBusJob();
	LoadMzgkJob();
	LoadSweeperJob();
	LoadMzgkJobCheckpointA();
	LoadMzgkJobCheckpointB();
	LoadSweeperJobCheckpointA();
	LoadSweeperJobCheckpointB();
	LoadFarmerJob();
	LoadFarmerJobCheckpointA();
	LoadFarmerJobCheckpointB();
	LoadFarmerJobCheckpointC();
	LoadSellerJob();
	LoadAccountantJob();
	LoadNewsBoyJob();
	LoadGunJob();
	LoadDrugJob();
	LoadDetectiveJob();
	LoadLawyerJob();
	LoadProductsSellerJob();
 	LoadWhoreJob();
 	LoadDirJob();
	LoadStuntJob();
	LoadCarjackJob();
	LoadBodyJob();
	LoadBoxerJob();
	LoadRapistJob();
	LoadMechanicJob1();
	LoadMechanicJob2();
	LoadMechanicJob();
	LoadWFWorkerJob();
	LoadRafinery();
	LoadWFactoryLegal();
	LoadPayRank();
	LoadVariables();
	LoadSpawnInfo();
	LoadCustomObjects();
	LoadBusTracks();
	LoadTrashTracks();
	LoadSweeperTracks();
	LoadFarmerTracks();
	LoadLuckyLottery();
	LoadItemFactories();
	LoadDrivingTestArea();
	LoadDrivingTestAreaBuy();
	LoadAdmissionChambers();
	LoadRandomPickupEvent();
	LoadRaces();
	LoadWeed();
	LoadMapIcons();
	LoadPublicAds();
	LoadPickupInfos();
	LoadNews();
	CreateLocationsCp();
	HorseRacePrepare(1);

	print("[INFO:] All loading functions initiated");

	return 1;
} // end of LoadScript