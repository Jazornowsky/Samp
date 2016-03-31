/***
*
* File: wp_reset.inc
* Auth: Damian Wojdat
* Date: 15.09.2011
* Desc: Variables value reset fnc.
* TODO: Cleanup. Some variables not in use ? Not need to reset ? Etc...
*
*************************************************************************************************************/

ResetStats(playerid)
{
	gCallDataReceived[playerid] = 1;
	gHorseWatching[playerid] = 0;
	gHorseMoneyBet[playerid] = 0;
	gHorseBetOnHorse[playerid] = 0;
	gPlayerData[playerid][mBroadCastMessages] = 1;
	gPlayerVars[playerid][mPhoneDataReceived] = 1;
	gPlayerVars[playerid][mBugInfoCoolDown] = 0;
	gPlayerVars[playerid][mPhoneDataTimeout] = -1;
	gPlayerVars[playerid][mAntiCheatTimer] = 0;
	gPlayerVars[playerid][mAtHouseID] = -1;
	gPlayerVars[playerid][mAtBuildingId] = -1;
	gPlayerVars[playerid][mAtBizID] = -1;
	gPlayerVars[playerid][mAtCamperId] = -1;
	gPlayerVars[playerid][mVehicleStatusShow] = 0;
	gPlayerVars[playerid][mSanNewsStatus] = 1;
	gPlayerVars[playerid][mSanNewsTextDrawCreated] = 0;
	gPlayerVars[playerid][mVehicleStatusShowChanged] = 0;
	gPlayerVars[playerid][mIsPlayerHouseJacking] = 0;
	gPlayerVars[playerid][mIsPlayerBizJacking] = 0;
	gPlayerVars[playerid][mPassTries] = 0;
	gPlayerVars[playerid][mNewbieCoolDown] = 0;
	gPlayerVars[playerid][mRobbingHouseStage] = 0;
	gPlayerVars[playerid][mRepairProgress] = 0;
	gPlayerVars[playerid][mBulbToChange] = 0;
	gPlayerVars[playerid][mWheelToChange] = 0;
	gPlayerVars[playerid][mIsReanimate] = 0;
	gPlayerVars[playerid][tempVehId] = 0;
	gPlayerVars[playerid][mIsInTaxiTeleportId] = 0;
	gPlayerVars[playerid][mTaxiTeleportTimeLeft] = 0;
	gPlayerVars[playerid][mAtClotheStore] = false;
	gPlayerVars[playerid][mIsIdleAnimationTimerActive] = false;
	gPlayerData[playerid][pIsNPC] = 0;
	gPlayerData[playerid][pLoading] = 0;
	gPlayerData[playerid][pFaction] = 255;
	gPlayerData[playerid][pRank] = 0;
	gPlayerData[playerid][pBanned] = 0;
	gPlayerData[playerid][pWarnings] = 0;
	gPlayerData[playerid][pLevel] = 0;
	gPlayerData[playerid][pAdmin] = 0;
	gPlayerData[playerid][pVipCar] = 0;
	gPlayerData[playerid][pVipAFK] = 0;
	gPlayerData[playerid][pVipAFKT] = 0;
	gPlayerData[playerid][pVipExp] = 0;
	gPlayerData[playerid][pVipExpT] = 0;
	gPlayerData[playerid][pDonateRank] = 0;
	gPlayerData[playerid][pRegistered] = 0;
	gPlayerData[playerid][pCharacterDeath] = 0;
	gPlayerData[playerid][pCharacterDying] = 0;
	gPlayerData[playerid][pSex] = 0;
	gPlayerData[playerid][pAge] = 0;
	gPlayerData[playerid][pExp] = 0;
	gPlayerData[playerid][pCash] = 0; //Resetting the cash variable to 0.
	gPlayerData[playerid][pBank] = 0;
	gPlayerData[playerid][pSkin] = 0;
	gPlayerData[playerid][pDrugs] = 0;
	gPlayerData[playerid][pDrugsEffect] = 0;
	gPlayerData[playerid][pDrugsTaken] = 0;
	gPlayerData[playerid][pDrugsAddicted] = 0;
	gPlayerData[playerid][pJob] = 0;
	gPlayerData[playerid][pJobTimeChange] = 0;
	gPlayerData[playerid][pJobLvl] = 0; // Bus
	gPlayerData[playerid][pMzgkJobLvl] = 0; // MZGK
	gPlayerData[playerid][pSweeperJobLvl] = 0; // Sweeper
	gPlayerData[playerid][pBusJobPoints] = 0; 
	gPlayerData[playerid][pMzgkJobPoints] = 0;
	gPlayerData[playerid][pSweeperJobPoints] = 0;
	gPlayerData[playerid][pPlayingHours] = 0;
	gPlayerData[playerid][pAllowedPayday] = 0;
	gPlayerData[playerid][pPayCheck] = 0;
	gPlayerData[playerid][pListNumber] = 1;
	gPlayerData[playerid][pDonator] = 0;
	gPlayerData[playerid][pJailed] = 0;
	gPlayerData[playerid][pJailTime] = 0;
	gPlayerData[playerid][pCrashX] = 0.0000;
	gPlayerData[playerid][pCrashY] = 0.0000;
	gPlayerData[playerid][pCrashZ] = 0.0000;
	gPlayerData[playerid][pCrashInt] = 0;
	gPlayerData[playerid][pCrashW] = 0;
	gPlayerData[playerid][pCrashed] = 0;
	gPlayerData[playerid][pCost] = 0;
	gPlayerData[playerid][pTicket] = 0;
	gPlayerData[playerid][pWantedLvl] = 0;
	gPlayerData[playerid][pItem1] = 0;
	gPlayerData[playerid][pItem2] = 0;
	gPlayerData[playerid][pItem3] = 0;
	gPlayerData[playerid][pItem4] = 0;
	gPlayerData[playerid][pItem5] = 0;
	gPlayerData[playerid][pModerator] = 0;
	strdel(gPlayerData[playerid][pOOCName], 0, 254);
	gPlayerData[playerid][pAccountOwnerID] = 99999;
	gPlayerData[playerid][pFirstCar] = 0;
	gPlayerData[playerid][pFirstReanimation] = 0;
	gPlayerData[playerid][pFirstPhone] = 0;
	gPlayerData[playerid][pFirstLeader] = 0;
	gPlayerData[playerid][pMuted] = 0;
	strdel(gPlayerData[playerid][pName], 0, 63);
	strins(gPlayerData[playerid][pName], "None", 0, 63);
	gPlayerData[playerid][pSeatBelt] = 0;
	strmid(gPlayerData[playerid][pNote1], "None", 0, strlen("None"), 254);
	gPlayerData[playerid][pNote1s] = 0;
	strmid(gPlayerData[playerid][pNote2], "None", 0, strlen("None"), 254);
	gPlayerData[playerid][pNote2s] = 0;
	strmid(gPlayerData[playerid][pNote3], "None", 0, strlen("None"), 254);
	gPlayerData[playerid][pNote3s] = 0;
	strmid(gPlayerData[playerid][pNote4], "None", 0, strlen("None"), 254);
	gPlayerData[playerid][pNote4s] = 0;
	strmid(gPlayerData[playerid][pNote5], "None", 0, strlen("None"), 254);
	gPlayerData[playerid][pNote5s] = 0;
	gPlayerData[playerid][pInvWeapon] = 0;
	gPlayerData[playerid][pInvAmmo] = 0;
	gPlayerData[playerid][pDowod] = 0;
	gPlayerData[playerid][pSkillLevPis] = 0;
	gPlayerData[playerid][pSkillLevSil] = 0;
	gPlayerData[playerid][pSkillLevDes] = 0;
	gPlayerData[playerid][pSkillLevSho] = 0;
	gPlayerData[playerid][pSkillLevSha] = 0;
	gPlayerData[playerid][pSkillLevSpa] = 0;
	gPlayerData[playerid][pSkillLevMic] = 0;
	gPlayerData[playerid][pSkillLevMp5] = 0;
	gPlayerData[playerid][pSkillLevAk] = 0;
	gPlayerData[playerid][pSkillLevM4] = 0;
	gPlayerData[playerid][pSkillLevSni] = 0;
	gPlayerData[playerid][pSkillPointsPis] = 0;
	gPlayerData[playerid][pSkillPointsSil] = 0;
	gPlayerData[playerid][pSkillPointsDes] = 0;
	gPlayerData[playerid][pSkillPointsSho] = 0;
	gPlayerData[playerid][pSkillPointsSha] = 0;
	gPlayerData[playerid][pSkillPointsSpa] = 0;
	gPlayerData[playerid][pSkillPointsMic] = 0;
	gPlayerData[playerid][pSkillPointsMp5] = 0;
	gPlayerData[playerid][pSkillPointsAk] = 0;
	gPlayerData[playerid][pSkillPointsM4] = 0;
	gPlayerData[playerid][pSkillPointsSni] = 0;
	gPlayerData[playerid][pPozwolenie] = 0;
	gPlayerData[playerid][pTech] = 0;
	gPlayerData[playerid][pLaw] = 0;
	gPlayerData[playerid][pMat] = 0;
	gPlayerData[playerid][pPol] = 0;
	gPlayerData[playerid][pHis] = 0;
	gPlayerData[playerid][pFiz] = 0;
	gPlayerData[playerid][pBio] = 0;
	gPlayerData[playerid][pDoktor] = 0;
	gPlayerData[playerid][pMagister] = 0;
	gPlayerData[playerid][pInz] = 0;
	gPlayerData[playerid][pPktTech] = 0;
	gPlayerData[playerid][pPktLaw] = 0;
	gPlayerData[playerid][pPktMat] = 0;
	gPlayerData[playerid][pPktPol] = 0;
	gPlayerData[playerid][pPktHis] = 0;
	gPlayerData[playerid][pPktFiz] = 0;
	gPlayerData[playerid][pPktBio] = 0;
	gPlayerData[playerid][pRPCount] = 0;
	gPlayerData[playerid][pDeathCount] = 0;
	gPlayerData[playerid][pDuty] = 0;
	gPlayerData[playerid][pScore] = 0;
	gPlayerData[playerid][pHoursOnDutyHelper] = 0;
	gPlayerData[playerid][pHoursOnDuty] = 0;
	gPlayerData[playerid][pMechanicCoolDown] = 0;
	gPlayerData[playerid][pWSlot1] = 0;
	gPlayerData[playerid][pWSlot1Ammo] = 0;
	gPlayerData[playerid][pWSlot2] = 0;
	gPlayerData[playerid][pWSlot2Ammo] = 0;
	gPlayerData[playerid][pWSlot3] = 0;
	gPlayerData[playerid][pWSlot3Ammo] = 0;
	gPlayerData[playerid][pWSlot4] = 0;
	gPlayerData[playerid][pWSlot4Ammo] = 0;
	gPlayerData[playerid][pWSlot5] = 0;
	gPlayerData[playerid][pWSlot5Ammo] = 0;
	gPlayerData[playerid][pWSlot6] = 0;
	gPlayerData[playerid][pWSlot6Ammo] = 0;
	gPlayerData[playerid][pWSlot7] = 0;
	gPlayerData[playerid][pWSlot7Ammo] = 0;
	gPlayerData[playerid][pWSlot8] = 0;
	gPlayerData[playerid][pWSlot8Ammo] = 0;
	gPlayerData[playerid][pWSlot9] = 0;
	gPlayerData[playerid][pWSlot9Ammo] = 0;
	gPlayerData[playerid][pWSlot10] = 0;
	gPlayerData[playerid][pWSlot10Ammo] = 0;
	gPlayerData[playerid][pWSlot11] = 0;
	gPlayerData[playerid][pWSlot11Ammo] = 0;
	gPlayerData[playerid][pWSlot12] = 0;
	gPlayerData[playerid][pWSlot12Ammo] = 0;
	gPlayerData[playerid][pMaxWeight] = 0;
	gPlayerData[playerid][pPartType] = 0;
	gPlayerData[playerid][pPartItem] = 0;
	gPlayerData[playerid][pMountsLeft] = 0;
	gPlayerData[playerid][pMountsPasses] = 0;
	gPlayerData[playerid][pWFOrderedCount] = 0;
	gPlayerData[playerid][pSpeedGunOn] = 0;
	gPlayerData[playerid][pSellerJobOn] = 0;
	gPlayerData[playerid][pMountingW] = 0;
	
	for(new i = 0; i < MAX_BUSINESSES; i++)
	{
		gPlayerData[playerid][pGasStationRefGas][i] = 0;
		gPlayerData[playerid][pGasStationRefOil][i] = 0;
		gPlayerData[playerid][pGasStationRefPetrol][i] = 0;
	}
	for(new i = 0; i < sizeof(gPickupEventData); i++)
	{
		gPlayerVars[playerid][mPickupEventPickups][i] = -1;
	}

	ClearDescObj(playerid);
	
	PlayerPos[playerid][3] = 0.0;
	PlayerPos[playerid][4] = 0.0;
	PlayerPos[playerid][5] = 0.0;
	
	TextDrawSetString(GangWar[playerid], " ");
	TextDrawSetString(GangWarTime[playerid], " ");
	
	gIsPlayerFrozen[playerid] = 0;
	gBusDriverIsPassenger[playerid] = 0;
	gBusDriverPaymentCount[playerid] = 0;
	gBusDriverPenaltyInformed[playerid] = 0;
	gBusDriverJustStarted[playerid] = 0;
	gBusDriverOnDuty[playerid] = 0;
	gBusDriverCheckpointTime[playerid] = 0;
	gTrashDriverPenaltyInformed[playerid] = 0;
	gTrashDriverJustStarted[playerid] = 0;
	gTrashDriverOnDuty[playerid] = 0;
	gSweeperDriverPenaltyInformed[playerid] = 0;
	gSweeperDriverJustStarted[playerid] = 0;
	gSweeperDriverOnDuty[playerid] = 0;
	gFarmerDriverPenaltyInformed[playerid] = 0;
	gFarmerDriverJustStarted[playerid] = 0;
	gFarmerDriverOnDuty[playerid] = 0;
	gSelectedSlot[playerid] = 0;
	gSavePlayerReady[playerid] = 0;
	DyingPlayerKillTime[playerid] = 0;
	NewbieTime[playerid] = 0;
	KilledWithWeapon[playerid] = 0;
	BigEar[playerid] = 0;
	IncommingCall[playerid] = 0;
	gangZoneLoaded[playerid] = 0;
	IsCarJackerOpening[playerid] = 0;
	ZonesCreated[playerid] = 0;
	AudioReady[playerid] = 0;
	CarRadioOn[playerid] = 0;
	CarRadioLeftOn[playerid] = 0;
	CarRadioID[playerid] = 255;
	JustDied[playerid] = 0;
	TakingBoatTest[playerid] = 0;
	TrackingCar[playerid] = 0; // Detective
	LastDrug[playerid] = 0;
	VipAFKActive[playerid] = 0;
	Spawned[playerid] = 0; // UAC
	PosHackCheckTime[playerid] = 5; // UAC
	IngVehData[playerid] = 0; // UAC
	ReduceTime[playerid] = 0; // schowek i czas 3 sekund na odczekanie, gdyby cos zawiodlo...
	IsPlayerTaxiPassenger[playerid] = 0;
	gTaxiPassengerDistance[playerid] = 0;
	CheckDelay[playerid] = 0;
	EngineTurningOn[playerid] = 0;
	ProductsOffer[playerid] = 999;
	ProductsCost[playerid] = 0;
	ProductsAmount[playerid] = 0;
	TrackingPlayer[playerid] = 0;
	DrugsIntake[playerid] = 0;
	DrugsHolding[playerid] = 0;
	ResetPlayerWantedLevelEx(playerid);
	PlayerTazed[playerid] = 0;
	PlayerCuffed[playerid] = 0;
	WantedLevel[playerid] = 0;
	AdminDuty[playerid] = 0;
	SpeakerPhone[playerid] = 0;
	StartedCall[playerid] = 0;
	Mobile[playerid] = 0;
	Muted[playerid] = 0; //Player is not muted.
	ShowFuel[playerid] = 1;//Will show fuel.
	TakingDrivingTestA[playerid] = 0; //Player is not taking the driving test.
	TakingDrivingTestB[playerid] = 0; //Player is not taking the driving test.
	TakingDrivingTestCE[playerid] = 0; //Player is not taking the driving test.
	DrivingTestStep[playerid] = 0; //Player has not started the driving test.
	BoatTestStep[playerid] = 0;
	SetPlayerColor(playerid, COLOR_NOTLOGGED);//Set colour to not logged in.
	SpawnAttempts[playerid] = 0; //Player hasn't attempted to spawn yet.
	gPlayerLogged[playerid] = 0;//Player is not logged in.
	RegistrationStep[playerid] = 0;
	FactionRequest[playerid] = 255; //Player hasn't been asked to join a faction.
	CompanyRequest[playerid] = 255; //Player hasn't been asked to join a faction.
	Mobile[playerid] = 255;
	MusicHandle[playerid][0] = 0;
	MusicHandle[playerid][1] = 0;
	IsMusicPlaying[playerid] = 0;
	MoloSequence[playerid] = 255;
	PoolSequence[playerid] = 255;
	pDrugsUsedStartHP[playerid] = 0.0;
	pDrugsUsedStartArmour[playerid] = 0.0;
	PlayerStatusShowed[playerid] = 1;
	PlayerStatusCreated[playerid] = 0;
	gKickVoteStartCooldown[playerid] = 0;
	gKickVotePlayerVote[playerid] = 0;	
	gPingHitLimit[playerid] = 0;
	PlayerWrittingAnything[playerid] = 0;
	gTaxiPassengerDistance[playerid] = 0;
	Alive[playerid] = 0;
	CheckDelay[playerid] = 0;
	gJobProfit[playerid] = 0;
	gVehHealthOnPlayerEnter[playerid] = 1000.0;
	gIsInCityAreaSpeedLimit[playerid] = 0;
	AccountantCost[playerid] = 0;
	AccountantOffer[playerid] = 999;
	gRandNumber[playerid] = 0;
	gSendingSMS[playerid] = 0;
	EnsuranceOC[playerid][vehicleNr] = 0;
	EnsuranceOC[playerid][Level] = 0;
	EnsuranceAC[playerid][vehicleNr] = 0;
	EnsuranceAC[playerid][Level] = 0;
	gPhoneC[playerid] = 999;
	gGlassesWearingModel[playerid] = 0;
	gAdminGodMode[playerid] = 0;
	gOOC[playerid] = 0;
	gPapers[playerid] = 0; // praca roznosiciela gazet - ilosc przenoszonych gazet
	gTryCoolDown[playerid] = 0; // cooldown komendy /proba
	gOverSpeed[playerid] = 0;
	gTransferCoolDown[playerid] = 0;
	gCallCost[playerid] = 0;
	gCalledCompany[playerid] = 255;
	gWFactoryGunCreating[playerid] = 0;
	gBuyBusinessID[playerid] = 0;
	gFirstTime[playerid] = 0; // firt char connect
	gPreviousDialogList[playerid] = -1;
	gBizBoughtApproved[playerid] = -1;
	gBizBoughtApprovalID[playerid] = -1;
	gAddCooldown[playerid] = 0;
	gIsOnAShip[playerid] = -1;
	gTestQuestionsA[playerid][0] = 0;
	gTestQuestionsA[playerid][1] = 0;
	gTestQuestionsA[playerid][2] = 0;
	gTestQuestionsA[playerid][3] = 0;
	gTestQuestionsA[playerid][4] = 0;
	gTestResult[playerid] = 0;
	gBackgroundAudio1[playerid] = -1;
	gBackgroundAudio2[playerid] = -1;
	gPhoneCallShowed[playerid] = 0;
	
	for(new slot = 0; slot < 13; slot++)
	{
		if(slot == 0)
		{
			Ammo[playerid][0] = -1;
		}
		else
		{
			for(new weapon = 0; weapon < 46; weapon++)
			{
				Ammo[playerid][weapon] = 0;
			}
		}
		Gun[playerid][Weapon][slot] = 0;
	}

	return 0;
}