/***
*
* File: wp_savedata.inc
* Auth: Damian Wojdat
* Date: 15.09.2011
* Desc: Functions saving data to files/databases.
*
*************************************************************************************************************/

SaveGSData(id, column[])
{
	new string[256];
	if(strlen(column) != 0)
	{
		if(strcmp(column, "PetrolResourceValue", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_gas_stations` SET `PetrolResourceValue` = '%f' WHERE `ID` = '%d'", GasStations[id][PetrolResourceValue], id);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "OilResourceValue", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_gas_stations` SET `OilResourceValue` = '%f' WHERE `ID` = '%d'", GasStations[id][OilResourceValue], id);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "GasResourceValue", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_gas_stations` SET `GasResourceValue` = '%f' WHERE `ID` = '%d'", GasStations[id][GasResourceValue], id);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		format(string, sizeof(string), "[WARNING:] Unknown column: %s", column);
		ErrorLog(string);
	}
	return 1;
}

SaveLotteryData(slot=-1)
{
	if( slot != -1 )
	{
		new string[256];
		format( string, sizeof(string), "UPDATE `samp_lucky_lottery` SET `LotteryID` = '%d' , `PlayerName` = '%s' , `RewardTaken` = '%d' , `number1` = '%d' , `number2` = '%d' , `number3` = '%d' , `number4` = '%d' WHERE `ID` = '%d'",
			gLuckyLottery[slot][LuckyID], gLuckyLottery[slot][LuckyPlayerName], gLuckyLottery[slot][LuckyRewardTaken], gLuckyLottery[slot][LuckyNumbers][0], gLuckyLottery[slot][LuckyNumbers][1], gLuckyLottery[slot][LuckyNumbers][2], gLuckyLottery[slot][LuckyNumbers][3], slot+1 );
		mysql_query( string, SAVE, INVALID_PLAYER_ID, db_con2 );
	}
	new File:file2;
	new arrCoords[64];
	format( arrCoords, sizeof(arrCoords), "%d|%d|%d|%d|%d|%d|%d|%d",
	gLuckyLotteryID,
	gLuckyLotteryCash,
	gLuckyLotteryLastLottery,
	gLuckyLotteryWinnersCount,
	gLuckyLotteryNumbers[0],
	gLuckyLotteryNumbers[1],
	gLuckyLotteryNumbers[2],
	gLuckyLotteryNumbers[3] );
	file2 = fopen("other/luckylottery.cfg", io_write);
	if(file2)
	{
		fwrite(file2, arrCoords);
		fclose(file2);
	}
	else
		ErrorLog("[ERROR:] Can't save luckylottery.log");
	return 1;
}

UpdatePlayerDataByName(name[], column[], newvalue = 0)
{
	static string[256];
	if(strlen(column) != 0)
	{
		if(strcmp(column, "Bank", true) == 0)
		{
			format(string, sizeof(string), "SELECT `Bank`, `PlayerName` FROM `samp_users` WHERE `PlayerName` = '%s'", name);
			mysql_query(string, UPDATE_DATA, newvalue, db_con3);
			return 1;
		}
		format(string, sizeof(string), "[WARNING:] Unknown column: %s", column);
		ErrorLog(string);
	}
	return 1;
}
	
SavePlayerData(playerid, column[], otherid = -1)
{
	if( playerid < CUSTOM_MAX_PLAYERS )
	{
		if(gSavePlayerReady[playerid] == 0)
		{
			return 1;
		}
	}
	static string[1024];
	if(strlen(column) != 0 && strcmp(gPlayerData[playerid][pName], "None", true) != 0)
	{
		if(strcmp(column, "Note1", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_notes` SET `Note1` = '%s' , `Note1s` = '%d' WHERE `PlayerName` = '%s' ", gPlayerData[playerid][pNote1], gPlayerData[playerid][pNote1s], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Note2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_notes` SET `Note2` = '%s' , `Note2s` = '%d' WHERE `PlayerName` = '%s' ", gPlayerData[playerid][pNote2], gPlayerData[playerid][pNote2s], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Note3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_notes` SET `Note3` = '%s' , `Note3s` = '%d' WHERE `PlayerName` = '%s' ", gPlayerData[playerid][pNote3], gPlayerData[playerid][pNote3s], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Note4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_notes` SET `Note4` = '%s' , `Note4s` = '%d' WHERE `PlayerName` = '%s' ", gPlayerData[playerid][pNote4], gPlayerData[playerid][pNote4s], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Note5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_notes` SET `Note5` = '%s' , `Note5s` = '%d' WHERE `PlayerName` = '%s' ", gPlayerData[playerid][pNote5], gPlayerData[playerid][pNote5s], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Faction2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `Faction2` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pFaction2], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Rank2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `Rank2` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pRank2], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "OOCChanell", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `OOCChanell` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pOOCChanell], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Quiz", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `Quiz` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pQuiz], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "SetToDelete", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `SetToDelete` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pSetToDelete], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "IsOnVacation", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `IsOnVacation` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pIsOnVacation], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "StomachDrops", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `StomachDrops` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pStomachDrops], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Slimming", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `Slimming` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pSlimming], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "PainKiller", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `PainKiller` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pPainKiller], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "NewVersion", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `NewVersion` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pNewVersion], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "SubMealEaten", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `SubMealEaten` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pSubMealEaten], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "CharDescriptionColor", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users` SET `CharDescriptionColor` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pCharDescriptionColor], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "CharDescription", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users` SET `CharDescription` = '%s' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pCharDescription], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "HealthStatus", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `Hunger` = '%f', `Thirst` = '%f', `Poison` = '%f', `Fat` = '%f', `Stomach` = '%f', `Vitamins` = '%f', `Energy` = '%f', `Drunk` = '%f', `Narcotic` = '%f'", 
			gPlayerData[playerid][pHunger], gPlayerData[playerid][pThirst], gPlayerData[playerid][pPoison], gPlayerData[playerid][pFat], gPlayerData[playerid][pStomach], gPlayerData[playerid][pVitamins], 
			gPlayerData[playerid][pEnergy], gPlayerData[playerid][pDrunk], gPlayerData[playerid][pNarcotic]);
			format(string, sizeof(string), "%s, `PainKiller` = '%d' , `Slimming` = '%d' , `StomachDrops` = '%d' WHERE `PlayerName` = '%s' ",
			string, gPlayerData[playerid][pPainKiller], gPlayerData[playerid][pSlimming], gPlayerData[playerid][pStomachDrops], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}		
		if(strcmp(column, "Hunger", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `Hunger` = '%f' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pHunger], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "PickupEventPickupStatus1", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `PickupEventPickupStatus1` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][mPickupEventPickupStatus][0], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "PickupEventPickupStatus2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `PickupEventPickupStatus2` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][mPickupEventPickupStatus][1], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "PickupEventPickupStatus3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `PickupEventPickupStatus3` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][mPickupEventPickupStatus][2], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "PickupEventPickupStatus4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `PickupEventPickupStatus4` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][mPickupEventPickupStatus][3], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "PickupEventPickupStatus5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `PickupEventPickupStatus5` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][mPickupEventPickupStatus][4], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "PickupEventPickupStatus6", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `PickupEventPickupStatus6` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][mPickupEventPickupStatus][5], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "PickupEventPickupStatus7", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `PickupEventPickupStatus7` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][mPickupEventPickupStatus][6], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "PickupEventPickupStatus8", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `PickupEventPickupStatus8` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][mPickupEventPickupStatus][7], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "PickupEventPickupStatus9", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `PickupEventPickupStatus9` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][mPickupEventPickupStatus][8], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "PickupEventPickupStatus10", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `PickupEventPickupStatus10` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][mPickupEventPickupStatus][9], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "PickupEventPickupStatus11", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `PickupEventPickupStatus11` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][mPickupEventPickupStatus][10], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "PickupEventPickupStatus12", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `PickupEventPickupStatus12` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][mPickupEventPickupStatus][11], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "PickupEventPickupStatus13", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `PickupEventPickupStatus13` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][mPickupEventPickupStatus][12], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "PickupEventPickupStatus14", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `PickupEventPickupStatus14` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][mPickupEventPickupStatus][13], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "PickupEventPickupStatus15", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `PickupEventPickupStatus15` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][mPickupEventPickupStatus][14], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "PickupEventPickupStatus16", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `PickupEventPickupStatus16` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][mPickupEventPickupStatus][15], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "PickupEventPickupStatus17", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `PickupEventPickupStatus17` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][mPickupEventPickupStatus][16], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "PickupEventPickupStatus18", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `PickupEventPickupStatus18` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][mPickupEventPickupStatus][17], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "PickupEventPickupStatus19", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `PickupEventPickupStatus19` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][mPickupEventPickupStatus][18], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "PickupEventPickupStatus20", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `PickupEventPickupStatus20` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][mPickupEventPickupStatus][19], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "PickupEventID", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `PickupEventID` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][mPickupEventID], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "PickupEventRewardReceived", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `PickupEventRewardReceived` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][mPickupEventRewardReceived], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Thirst", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `Thirst` = '%f' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pThirst], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Poison", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `Poison` = '%f' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pPoison], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Fat", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `Fat` = '%f' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pFat], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Stomach", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `Stomach` = '%f' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pStomach], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Vitamins", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `Vitamins` = '%f' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pVitamins], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Energy", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `Energy` = '%f' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pEnergy], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Drunk", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `Drunk` = '%f' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pDrunk], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Narcotic", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `Narcotic` = '%f' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pNarcotic], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "ShowHealthBars", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `ShowHealthBars` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pShowHealthBars], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "AdminDuty", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users` SET `AdminDuty` = '%d' WHERE `PlayerName` = '%s'", AdminDuty[playerid], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "SpeedLimiter", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users` SET `SpeedLimiter` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pSpeedLimiter], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "CreditValue", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other2` SET `CreditValue` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][mCreditValue], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "CreditRepayment", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other2` SET `CreditRepayment` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][mCreditRepayment], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "CreditPayed", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other2` SET `CreditPayed` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][mCreditPayed], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "OOCStatus", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other2` SET `OOCStatus` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pOOCStatus], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "PWStatus", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other2` SET `PWStatus` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pPWStatus], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "JoinInfoStatus", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other2` SET `JoinInfoStatus` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pJoinInfoStatus], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "LeaveInfoStatus", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other2` SET `LeaveInfoStatus` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pLeaveInfoStatus], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "TipsStatus", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other2` SET `TipsStatus` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pTipsStatus], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "BackgroundSoundStatus", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other2` SET `BackgroundSoundStatus` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pBackgroundSoundStatus], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "VipWhiteNeon", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_vip` SET `VipWhiteNeon` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pVipWhiteNeon], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "VipPinkNeon", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_vip` SET `VipPinkNeon` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pVipPinkNeon], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "VipYellowNeon", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_vip` SET `VipYellowNeon` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pVipYellowNeon], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "VipGreenNeon", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_vip` SET `VipGreenNeon` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pVipGreenNeon], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "VipBlueNeon", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_vip` SET `VipBlueNeon` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pVipBlueNeon], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "VipRedNeon", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_vip` SET `VipRedNeon` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pVipRedNeon], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "VipHalogenLight", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_vip` SET `VipHalogenLight` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pVipHalogenLight], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "VipWhitePointLight", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_vip` SET `VipWhitePointLight` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pVipWhitePointLight], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "VipRedPointLight", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_vip` SET `VipRedPointLight` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pVipRedPointLight], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "VipGreenPointLight", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_vip` SET `VipGreenPointLight` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pVipGreenPointLight], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "VipBluePointLight", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_vip` SET `VipBluePointLight` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pVipBluePointLight], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "VipGarage", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_vip` SET `VipGarage` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pVipGarage], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "VipGarageBig", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_vip` SET `VipGarageBig` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pVipGarageBig], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Registered", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users` SET `Registered` = '%d' WHERE `PlayerName` = '%s' ", gPlayerData[playerid][pRegistered], gPlayerData[playerid][pName] );
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "GasStationRefPetrol", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_fueled` SET `BizPetrol` = '%f' WHERE `PlayerName` = '%s' AND `BizID` = '%d'", gPlayerData[playerid][pGasStationRefPetrol][otherid], gPlayerData[playerid][pName], otherid);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "GasStationRefOil", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_fueled` SET `BizOil` = '%f' WHERE `PlayerName` = '%s' AND `BizID` = '%d'", gPlayerData[playerid][pGasStationRefOil][otherid], gPlayerData[playerid][pName], otherid);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "GasStationRefGas", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_fueled` SET `BizGas` = '%f' WHERE `PlayerName` = '%s' AND `BizID` = '%d'", gPlayerData[playerid][pGasStationRefGas][otherid], gPlayerData[playerid][pName], otherid);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Level", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users` SET `Level` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pLevel], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "VipCar", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_vip` SET `VipCar` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pVipCar], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "VipAFK", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_vip` SET `VipAFK` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pVipAFK], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "VipAFKT", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_vip` SET `VipAFKT` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pVipAFKT], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "VipExp", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_vip` SET `VipExp` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pVipExp], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "VipExpT", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_vip` SET `VipExpT` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pVipExpT], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "CharacterDeath", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_vip` SET `CharacterDeath` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pCharacterDeath], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "CharacterDying", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_vip` SET `CharacterDying` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pCharacterDying], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "VipItem", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_vip` SET `VipItem` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pVipItem], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Parts", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other2` SET `Parts` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pParts], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "JobTimeChange", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other2` SET `JobTimeChange` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pJobTimeChange], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "SkillLevPis", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other2` SET `SkillLevPis` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pSkillLevPis], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "SkillLevSil", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other2` SET `SkillLevSil` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pSkillLevSil], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "SkillLevDes", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other2` SET `SkillLevDes` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pSkillLevDes], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "SkillLevSho", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other2` SET `SkillLevSho` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pSkillLevSho], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "SkillLevSha", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other2` SET `SkillLevSha` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pSkillLevSha], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "SkillLevSpa", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other2` SET `SkillLevSpa` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pSkillLevSpa], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "SkillLevMic", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other2` SET `SkillLevMic` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pSkillLevMic], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "SkillLevMp5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other2` SET `SkillLevMp5` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pSkillLevMp5], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "SkillLevAk", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other2` SET `SkillLevAk` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pSkillLevAk], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "SkillLevM4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other2` SET `SkillLevM4` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pSkillLevM4], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "SkillLevSni", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other2` SET `SkillLevSni` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pSkillLevSni], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "SkillPointsPis", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other2` SET `SkillPointsPis` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pSkillPointsPis], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "SkillPointsSil", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other2` SET `SkillPointsSil` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pSkillPointsSil], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "SkillPointsDes", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other2` SET `SkillPointsDes` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pSkillPointsDes], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "SkillPointsSho", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other2` SET `SkillPointsSho` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pSkillPointsSho], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "SkillPointsSha", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other2` SET `SkillPointsSha` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pSkillPointsSha], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "SkillPointsSpa", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other2` SET `SkillPointsSpa` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pSkillPointsSpa], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "SkillPointsMic", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other2` SET `SkillPointsMic` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pSkillPointsMic], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "SkillPointsMp5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other2` SET `SkillPointsMp5` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pSkillPointsMp5], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "SkillPointsAk", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other2` SET `SkillPointsAk` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pSkillPointsAk], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "SkillPointsM4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other2` SET `SkillPointsM4` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pSkillPointsM4], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "SkillPointsSni", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other2` SET `SkillPointsSni` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pSkillPointsSni], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Pozwolenie", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other2` SET `Pozwolenie` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pPozwolenie], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Exp", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users` SET `Experience` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pExp], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Cash", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users` SET `Money` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pCash], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Bank", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users` SET `Bank` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pBank], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Skin", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users` SET `Skin` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pSkin], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "PlayingHours", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users` SET `PlayingHours` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pPlayingHours], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "AllowedPayday", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users` SET `AllowedPayday` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pAllowedPayday], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "PayCheck", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users` SET `PayCheck` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pPayCheck], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Faction", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users` SET `Faction` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pFaction], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Rank", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users` SET `Rank` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pRank], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Banned", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users` SET `Banned` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pBanned], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Warnings", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users` SET `Warnings` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pWarnings], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Jailed", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users` SET `Jailed` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pJailed], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "JailTime", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users` SET `JailTime` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pJailTime], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Crash", true, 5) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users` SET `CrashX` = '%f' , `CrashY` = '%f' , `CrashZ` = '%f' , `CrashInt` = '%d' , `CrashW` = '%d' , `CrashAngle` = '%f' , `Jailed` = '%d' , `JailTime` = '%d' , `Money` = '%d', ",
			gPlayerData[playerid][pCrashX], gPlayerData[playerid][pCrashY], gPlayerData[playerid][pCrashZ], gPlayerData[playerid][pCrashInt], gPlayerData[playerid][pCrashW], gPlayerData[playerid][pCrashAngle], 
			gPlayerData[playerid][pJailed], gPlayerData[playerid][pJailTime], gPlayerData[playerid][pCash]);
			format(string, sizeof(string), "%s`Bank` = '%d' WHERE `PlayerName` = '%s' ", string, gPlayerData[playerid][pBank], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `Cost` = '%d' , `HP` = '%f' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pCost], gPlayerData[playerid][pHP], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "CrashX", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users` SET `CrashX` = '%f' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pCrashX], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "CrashY", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users` SET `CrashY` = '%f' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pCrashY], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "CrashZ", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users` SET `CrashZ` = '%f' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pCrashZ], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "CrashInt", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users` SET `CrashInt` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pCrashInt], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "CrashW", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users` SET `CrashW` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pCrashW], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Crashed", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users` SET `Crashed` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pCrashed], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "InvWeapon", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users` SET `InvWeapon` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pInvWeapon], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "InvAmmo", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users` SET `InvAmmo` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pInvAmmo], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Moderator", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users` SET `Moderator` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pModerator], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "WantedLvl", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users` SET `WantedLvl` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pWantedLvl], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "FirstCar", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users` SET `FirstCar` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pFirstCar], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "FirstReanimation", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users` SET `FirstReanimation` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pFirstReanimation], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "FirstPhone", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users` SET `FirstPhone` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pFirstPhone], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "FirstLeader", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users` SET `FirstLeader` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pFirstLeader], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "FirstJob", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users` SET `FirstJob` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pFirstJob], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "FirstID", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users` SET `FirstID` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pFirstID], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "FirstBuy", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users` SET `FirstBuy` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pFirstBuy], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "FirstHouse", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users` SET `FirstHouse` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pFirstHouse], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "FirstDescription", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users` SET `FirstDescription` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pFirstDescription], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "FirstAction", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users` SET `FirstAction` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pFirstAction], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "FirstBankUse", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users` SET `FirstBankUse` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pFirstBankUse], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "FirstStats", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users` SET `FirstStats` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pFirstStats], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "FirstJail", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users` SET `FirstJail` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pFirstJail], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "FirstStudy", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users` SET `FirstStudy` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pFirstStudy], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "AchieveTickets", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `AchieveTickets` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pAchieveTickets], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "AchieveArrests", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `AchieveTickets` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pAchieveArrests], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "AchieveDistance", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `AchieveDistance` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pAchieveDistance], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "BankOld", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `BankOld` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pBankOld], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "BankIncome", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `BankIncome` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pBankIncome], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "BankLoose", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `BankLoose` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pBankLoose], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "BankNew", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `BankNew` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pBankNew], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "PayDayMessage", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `PayDayMessage` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pPayDayMessage], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "CrashAngle", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users` SET `CrashAngle` = '%f' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pCrashAngle], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "WarnCooldown", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users` SET `WarnCooldown` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pWarnCooldown], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "HourAssist", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users` SET `HourAssist` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pHourAssist], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "JoinedFaction", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users` SET `JoinedFaction` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pJoinedFaction], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "HoursOnDuty", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users` SET `HoursOnDuty` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pHoursOnDuty], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "HoursOnDutyHelper", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users` SET `HoursOnDutyHelper` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pHoursOnDutyHelper], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item1a", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items` SET `Item1` = '%d' , `Item1type` = '%d' , `Item1param` = '%d' , `Item1param2` = '%d' , `Item1param3` = '%d' , `Item1param4` = '%d' , `Item1param5` = '%s' , `Item1param6` = '%d' WHERE `PlayerName` = '%s' ",
				gPlayerData[playerid][pItem1], gPlayerData[playerid][pItem1type], gPlayerData[playerid][pItem1param], gPlayerData[playerid][pItem1param2], gPlayerData[playerid][pItem1param3], gPlayerData[playerid][pItem1param4], gPlayerData[playerid][pItem1param5],
				gPlayerData[playerid][pItem1param6], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item2a", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items` SET `Item2` = '%d' , `Item2type` = '%d' , `Item2param` = '%d' , `Item2param2` = '%d' , `Item2param3` = '%d' , `Item2param4` = '%d' , `Item2param5` = '%s' , `Item2param6` = '%d' WHERE `PlayerName` = '%s' ",
				gPlayerData[playerid][pItem2], gPlayerData[playerid][pItem2type], gPlayerData[playerid][pItem2param], gPlayerData[playerid][pItem2param2], gPlayerData[playerid][pItem2param3], gPlayerData[playerid][pItem2param4], gPlayerData[playerid][pItem2param5],
				gPlayerData[playerid][pItem2param6], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item3a", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items` SET `Item3` = '%d' , `Item3type` = '%d' , `Item3param` = '%d' , `Item3param2` = '%d' , `Item3param3` = '%d' , `Item3param4` = '%d' , `Item3param5` = '%s' , `Item3param6` = '%d' WHERE `PlayerName` = '%s' ",
				gPlayerData[playerid][pItem3], gPlayerData[playerid][pItem3type], gPlayerData[playerid][pItem3param], gPlayerData[playerid][pItem3param2], gPlayerData[playerid][pItem3param3], gPlayerData[playerid][pItem3param4], gPlayerData[playerid][pItem3param5],
				gPlayerData[playerid][pItem3param6], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item4a", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items` SET `Item4` = '%d' , `Item4type` = '%d' , `Item4param` = '%d' , `Item4param2` = '%d' , `Item4param3` = '%d' , `Item4param4` = '%d' , `Item4param5` = '%s' , `Item4param6` = '%d' WHERE `PlayerName` = '%s' ",
				gPlayerData[playerid][pItem4], gPlayerData[playerid][pItem4type], gPlayerData[playerid][pItem4param], gPlayerData[playerid][pItem4param2], gPlayerData[playerid][pItem4param3], gPlayerData[playerid][pItem4param4], gPlayerData[playerid][pItem4param5],
				gPlayerData[playerid][pItem4param6], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item5a", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items` SET `Item5` = '%d' , `Item5type` = '%d' , `Item5param` = '%d' , `Item5param2` = '%d' , `Item5param3` = '%d' , `Item5param4` = '%d' , `Item5param5` = '%s' , `Item5param6` = '%d' WHERE `PlayerName` = '%s' ",
				gPlayerData[playerid][pItem5], gPlayerData[playerid][pItem5type], gPlayerData[playerid][pItem5param], gPlayerData[playerid][pItem5param2], gPlayerData[playerid][pItem5param3], gPlayerData[playerid][pItem5param4], gPlayerData[playerid][pItem5param5],
				gPlayerData[playerid][pItem5param6], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item1", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items` SET `Item1` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem1], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items` SET `Item2` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem2], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items` SET `Item3` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem3], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items` SET `Item4` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem4], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items` SET `Item5` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem5], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item1type", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items` SET `Item1type` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem1type], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item2type", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items` SET `Item2type` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem2type], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item3type", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items` SET `Item3type` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem3type], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item4type", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items` SET `Item4type` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem4type], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item5type", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items` SET `Item5type` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem5type], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item1param", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items` SET `Item1param` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem1param], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item2param", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items` SET `Item2param` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem2param], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item3param", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items` SET `Item3param` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem3param], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item4param", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items` SET `Item4param` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem4param], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item5param", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items` SET `Item5param` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem5param], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item1param2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items` SET `Item1param2` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem1param2], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item2param2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items` SET `Item2param2` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem2param2], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item3param2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items` SET `Item3param2` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem3param2], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item4param2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items` SET `Item4param2` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem4param2], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item5param2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items` SET `Item5param2` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem5param2], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item1param3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items` SET `Item1param3` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem1param3], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item2param3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items` SET `Item2param3` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem2param3], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item3param3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items` SET `Item3param3` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem3param3], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item4param3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items` SET `Item4param3` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem4param3], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item5param3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items` SET `Item5param3` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem5param3], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item1param4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items` SET `Item1param4` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem1param4], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item2param4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items` SET `Item2param4` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem2param4], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item3param4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items` SET `Item3param4` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem3param4], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item4param4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items` SET `Item4param4` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem4param4], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item5param4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items` SET `Item5param4` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem5param4], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item1param5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items` SET `Item1param5` = '%s' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem1param5], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item2param5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items` SET `Item2param5` = '%s' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem2param5], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item3param5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items` SET `Item3param5` = '%s' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem3param5], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item4param5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items` SET `Item4param5` = '%s' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem4param5], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item5param5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items` SET `Item5param5` = '%s' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem5param5], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item1param6", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items` SET `Item1param6` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem1param6], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item2param6", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items` SET `Item2param6` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem2param6], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item3param6", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items` SET `Item3param6` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem3param6], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item4param6", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items` SET `Item4param6` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem4param6], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item5param6", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items` SET `Item5param6` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem5param6], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item6a", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items2` SET `Item6` = '%d' , `Item6type` = '%d' , `Item6param` = '%d' , `Item6param2` = '%d' , `Item6param3` = '%d' , `Item6param4` = '%d' , `Item6param5` = '%s' , `Item6param6` = '%d' WHERE `PlayerName` = '%s' ",
				gPlayerData[playerid][pItem6], gPlayerData[playerid][pItem6type], gPlayerData[playerid][pItem6param], gPlayerData[playerid][pItem6param2], gPlayerData[playerid][pItem6param3], gPlayerData[playerid][pItem6param4], gPlayerData[playerid][pItem6param5],
				gPlayerData[playerid][pItem6param6], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item7a", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items2` SET `Item7` = '%d' , `Item7type` = '%d' , `Item7param` = '%d' , `Item7param2` = '%d' , `Item7param3` = '%d' , `Item7param4` = '%d' , `Item7param5` = '%s' , `Item7param6` = '%d' WHERE `PlayerName` = '%s' ",
				gPlayerData[playerid][pItem7], gPlayerData[playerid][pItem7type], gPlayerData[playerid][pItem7param], gPlayerData[playerid][pItem7param2], gPlayerData[playerid][pItem7param3], gPlayerData[playerid][pItem7param4], gPlayerData[playerid][pItem7param5],
				gPlayerData[playerid][pItem7param6], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item8a", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items2` SET `Item8` = '%d' , `Item8type` = '%d' , `Item8param` = '%d' , `Item8param2` = '%d' , `Item8param3` = '%d' , `Item8param4` = '%d' , `Item8param5` = '%s' , `Item8param6` = '%d' WHERE `PlayerName` = '%s' ",
				gPlayerData[playerid][pItem8], gPlayerData[playerid][pItem8type], gPlayerData[playerid][pItem8param], gPlayerData[playerid][pItem8param2], gPlayerData[playerid][pItem8param3], gPlayerData[playerid][pItem8param4], gPlayerData[playerid][pItem8param5],
				gPlayerData[playerid][pItem8param6], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item9a", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items2` SET `Item9` = '%d' , `Item9type` = '%d' , `Item9param` = '%d' , `Item9param2` = '%d' , `Item9param3` = '%d' , `Item9param4` = '%d' , `Item9param5` = '%s' , `Item9param6` = '%d' WHERE `PlayerName` = '%s' ",
				gPlayerData[playerid][pItem9], gPlayerData[playerid][pItem9type], gPlayerData[playerid][pItem9param], gPlayerData[playerid][pItem9param2], gPlayerData[playerid][pItem9param3], gPlayerData[playerid][pItem9param4], gPlayerData[playerid][pItem9param5],
				gPlayerData[playerid][pItem9param6], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item10a", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items2` SET `Item10` = '%d' , `Item10type` = '%d' , `Item10param` = '%d' , `Item10param2` = '%d' , `Item10param3` = '%d' , `Item10param4` = '%d' , `Item10param5` = '%s' , `Item10param6` = '%d' WHERE `PlayerName` = '%s' ",
				gPlayerData[playerid][pItem10], gPlayerData[playerid][pItem10type], gPlayerData[playerid][pItem10param], gPlayerData[playerid][pItem10param2], gPlayerData[playerid][pItem10param3], gPlayerData[playerid][pItem10param4], gPlayerData[playerid][pItem10param5],
				gPlayerData[playerid][pItem10param6], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item6", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items2` SET `Item6` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem6], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item7", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items2` SET `Item7` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem7], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item8", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items2` SET `Item8` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem8], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item9", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items2` SET `Item9` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem9], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item10", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items2` SET `Item10` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem10], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item6type", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items2` SET `Item6type` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem6type], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item7type", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items2` SET `Item7type` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem7type], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item8type", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items2` SET `Item8type` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem8type], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item9type", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items2` SET `Item9type` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem9type], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item10type", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items2` SET `Item10type` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem10type], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item6param", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items2` SET `Item6param` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem6param], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item7param", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items2` SET `Item7param` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem7param], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item8param", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items2` SET `Item8param` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem8param], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item9param", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items2` SET `Item9param` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem9param], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item10param", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items2` SET `Item10param` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem10param], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item6param2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items2` SET `Item6param2` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem6param2], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item7param2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items2` SET `Item7param2` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem7param2], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item8param2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items2` SET `Item8param2` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem8param2], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item9param2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items2` SET `Item9param2` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem9param2], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item10param2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items2` SET `Item10param2` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem10param2], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item6param3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items2` SET `Item6param3` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem6param3], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item7param3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items2` SET `Item7param3` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem7param3], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item8param3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items2` SET `Item8param3` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem8param3], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item9param3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items2` SET `Item9param3` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem9param3], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item10param3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items2` SET `Item10param3` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem10param3], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item6param4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items2` SET `Item6param4` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem6param4], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item7param4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items2` SET `Item7param4` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem7param4], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item8param4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items2` SET `Item8param4` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem8param4], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item9param4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items2` SET `Item9param4` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem9param4], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item10param4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items2` SET `Item10param4` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem10param4], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item6param5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items2` SET `Item6param5` = '%s' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem6param5], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item7param5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items2` SET `Item7param5` = '%s' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem7param5], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item8param5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items2` SET `Item8param5` = '%s' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem8param5], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item9param5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items2` SET `Item9param5` = '%s' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem9param5], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item10param5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items2` SET `Item10param5` = '%s' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem10param5], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item6param6", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items2` SET `Item6param6` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem6param6], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item7param6", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items2` SET `Item7param6` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem7param6], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item8param6", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items2` SET `Item8param6` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem8param6], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item9param6", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items2` SET `Item9param6` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem9param6], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item10param6", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items2` SET `Item10param6` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem10param6], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item11a", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item11` = '%d' , `Item11type` = '%d' , `Item11param` = '%d' , `Item11param2` = '%d' , `Item11param3` = '%d' , `Item11param4` = '%d' , `Item11param5` = '%s' , `Item11param6` = '%d' WHERE `PlayerName` = '%s' ",
				gPlayerData[playerid][pItem11], gPlayerData[playerid][pItem11type], gPlayerData[playerid][pItem11param], gPlayerData[playerid][pItem11param2], gPlayerData[playerid][pItem11param3], gPlayerData[playerid][pItem11param4], gPlayerData[playerid][pItem11param5],
				gPlayerData[playerid][pItem11param6], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item12a", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item12` = '%d' , `Item12type` = '%d' , `Item12param` = '%d' , `Item12param2` = '%d' , `Item12param3` = '%d' , `Item12param4` = '%d' , `Item12param5` = '%s' , `Item12param6` = '%d' WHERE `PlayerName` = '%s' ",
				gPlayerData[playerid][pItem12], gPlayerData[playerid][pItem12type], gPlayerData[playerid][pItem12param], gPlayerData[playerid][pItem12param2], gPlayerData[playerid][pItem12param3], gPlayerData[playerid][pItem12param4], gPlayerData[playerid][pItem12param5],
				gPlayerData[playerid][pItem12param6], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item13a", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item13` = '%d' , `Item13type` = '%d' , `Item13param` = '%d' , `Item13param2` = '%d' , `Item13param3` = '%d' , `Item13param4` = '%d' , `Item13param5` = '%s' , `Item13param6` = '%d' WHERE `PlayerName` = '%s' ",
				gPlayerData[playerid][pItem13], gPlayerData[playerid][pItem13type], gPlayerData[playerid][pItem13param], gPlayerData[playerid][pItem13param2], gPlayerData[playerid][pItem13param3], gPlayerData[playerid][pItem13param4], gPlayerData[playerid][pItem13param5],
				gPlayerData[playerid][pItem13param6], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item14a", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item14` = '%d' , `Item14type` = '%d' , `Item14param` = '%d' , `Item14param2` = '%d' , `Item14param3` = '%d' , `Item14param4` = '%d' , `Item14param5` = '%s' , `Item14param6` = '%d' WHERE `PlayerName` = '%s' ",
				gPlayerData[playerid][pItem14], gPlayerData[playerid][pItem14type], gPlayerData[playerid][pItem14param], gPlayerData[playerid][pItem14param2], gPlayerData[playerid][pItem14param3], gPlayerData[playerid][pItem14param4], gPlayerData[playerid][pItem14param5],
				gPlayerData[playerid][pItem14param6], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item15a", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item15` = '%d' , `Item15type` = '%d' , `Item15param` = '%d' , `Item15param2` = '%d' , `Item15param3` = '%d' , `Item15param4` = '%d' , `Item15param5` = '%s' , `Item15param6` = '%d' WHERE `PlayerName` = '%s' ",
				gPlayerData[playerid][pItem15], gPlayerData[playerid][pItem15type], gPlayerData[playerid][pItem15param], gPlayerData[playerid][pItem15param2], gPlayerData[playerid][pItem15param3], gPlayerData[playerid][pItem15param4], gPlayerData[playerid][pItem15param5],
				gPlayerData[playerid][pItem15param6], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item16a", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item16` = '%d' , `Item16type` = '%d' , `Item16param` = '%d' , `Item16param2` = '%d' , `Item16param3` = '%d' , `Item16param4` = '%d' , `Item16param5` = '%s' , `Item16param6` = '%d' WHERE `PlayerName` = '%s' ",
				gPlayerData[playerid][pItem16], gPlayerData[playerid][pItem16type], gPlayerData[playerid][pItem16param], gPlayerData[playerid][pItem16param2], gPlayerData[playerid][pItem16param3], gPlayerData[playerid][pItem16param4], gPlayerData[playerid][pItem16param5],
				gPlayerData[playerid][pItem16param6], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item17a", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item17` = '%d' , `Item17type` = '%d' , `Item17param` = '%d' , `Item17param2` = '%d' , `Item17param3` = '%d' , `Item17param4` = '%d' , `Item17param5` = '%s' , `Item17param6` = '%d' WHERE `PlayerName` = '%s' ",
				gPlayerData[playerid][pItem17], gPlayerData[playerid][pItem17type], gPlayerData[playerid][pItem17param], gPlayerData[playerid][pItem17param2], gPlayerData[playerid][pItem17param3], gPlayerData[playerid][pItem17param4], gPlayerData[playerid][pItem17param5],
				gPlayerData[playerid][pItem17param6], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item18a", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item18` = '%d' , `Item18type` = '%d' , `Item18param` = '%d' , `Item18param2` = '%d' , `Item18param3` = '%d' , `Item18param4` = '%d' , `Item18param5` = '%s' , `Item18param6` = '%d' WHERE `PlayerName` = '%s' ",
				gPlayerData[playerid][pItem18], gPlayerData[playerid][pItem18type], gPlayerData[playerid][pItem18param], gPlayerData[playerid][pItem18param2], gPlayerData[playerid][pItem18param3], gPlayerData[playerid][pItem18param4], gPlayerData[playerid][pItem18param5],
				gPlayerData[playerid][pItem18param6], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item19a", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item19` = '%d' , `Item19type` = '%d' , `Item19param` = '%d' , `Item19param2` = '%d' , `Item19param3` = '%d' , `Item19param4` = '%d' , `Item19param5` = '%s' , `Item19param6` = '%d' WHERE `PlayerName` = '%s' ",
				gPlayerData[playerid][pItem19], gPlayerData[playerid][pItem19type], gPlayerData[playerid][pItem19param], gPlayerData[playerid][pItem19param2], gPlayerData[playerid][pItem19param3], gPlayerData[playerid][pItem19param4], gPlayerData[playerid][pItem19param5],
				gPlayerData[playerid][pItem19param6], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item20a", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item20` = '%d' , `Item20type` = '%d' , `Item20param` = '%d' , `Item20param2` = '%d' , `Item20param3` = '%d' , `Item20param4` = '%d' , `Item20param5` = '%s' , `Item20param6` = '%d' WHERE `PlayerName` = '%s' ",
				gPlayerData[playerid][pItem20], gPlayerData[playerid][pItem20type], gPlayerData[playerid][pItem20param], gPlayerData[playerid][pItem20param2], gPlayerData[playerid][pItem20param3], gPlayerData[playerid][pItem20param4], gPlayerData[playerid][pItem20param5],
				gPlayerData[playerid][pItem20param6], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item21a", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item21` = '%d' , `Item21type` = '%d' , `Item21param` = '%d' , `Item21param2` = '%d' , `Item21param3` = '%d' , `Item21param4` = '%d' , `Item21param5` = '%s' , `Item21param6` = '%d' WHERE `PlayerName` = '%s' ",
				gPlayerData[playerid][pItem21], gPlayerData[playerid][pItem21type], gPlayerData[playerid][pItem21param], gPlayerData[playerid][pItem21param2], gPlayerData[playerid][pItem21param3], gPlayerData[playerid][pItem21param4], gPlayerData[playerid][pItem21param5],
				gPlayerData[playerid][pItem21param6], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item22a", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item22` = '%d' , `Item22type` = '%d' , `Item22param` = '%d' , `Item22param2` = '%d' , `Item22param3` = '%d' , `Item22param4` = '%d' , `Item22param5` = '%s' , `Item22param6` = '%d' WHERE `PlayerName` = '%s' ",
				gPlayerData[playerid][pItem22], gPlayerData[playerid][pItem22type], gPlayerData[playerid][pItem22param], gPlayerData[playerid][pItem22param2], gPlayerData[playerid][pItem22param3], gPlayerData[playerid][pItem22param4], gPlayerData[playerid][pItem22param5],
				gPlayerData[playerid][pItem22param6], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item23a", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item23` = '%d' , `Item23type` = '%d' , `Item23param` = '%d' , `Item23param2` = '%d' , `Item23param3` = '%d' , `Item23param4` = '%d' , `Item23param5` = '%s' , `Item23param6` = '%d' WHERE `PlayerName` = '%s' ",
				gPlayerData[playerid][pItem23], gPlayerData[playerid][pItem23type], gPlayerData[playerid][pItem23param], gPlayerData[playerid][pItem23param2], gPlayerData[playerid][pItem23param3], gPlayerData[playerid][pItem23param4], gPlayerData[playerid][pItem23param5],
				gPlayerData[playerid][pItem23param6], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item24a", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item24` = '%d' , `Item24type` = '%d' , `Item24param` = '%d' , `Item24param2` = '%d' , `Item24param3` = '%d' , `Item24param4` = '%d' , `Item24param5` = '%s' , `Item24param6` = '%d' WHERE `PlayerName` = '%s' ",
				gPlayerData[playerid][pItem24], gPlayerData[playerid][pItem24type], gPlayerData[playerid][pItem24param], gPlayerData[playerid][pItem24param2], gPlayerData[playerid][pItem24param3], gPlayerData[playerid][pItem24param4], gPlayerData[playerid][pItem24param5],
				gPlayerData[playerid][pItem24param6], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item25a", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item25` = '%d' , `Item25type` = '%d' , `Item25param` = '%d' , `Item25param2` = '%d' , `Item25param3` = '%d' , `Item25param4` = '%d' , `Item25param5` = '%s' , `Item25param6` = '%d' WHERE `PlayerName` = '%s' ",
				gPlayerData[playerid][pItem25], gPlayerData[playerid][pItem25type], gPlayerData[playerid][pItem25param], gPlayerData[playerid][pItem25param2], gPlayerData[playerid][pItem25param3], gPlayerData[playerid][pItem25param4], gPlayerData[playerid][pItem25param5],
				gPlayerData[playerid][pItem25param6], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item11", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item11` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem11], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item12", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item12` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem12], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item13", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item13` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem13], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item14", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item14` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem14], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item15", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item15` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem15], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item16", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item16` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem16], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item17", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item17` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem17], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item18", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item18` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem18], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item19", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item19` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem19], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item20", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item20` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem20], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item21", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item21` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem21], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item22", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item22` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem22], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item23", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item23` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem23], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item24", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item24` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem24], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item25", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item25` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem25], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item11type", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item11type` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem11type], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item12type", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item12type` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem12type], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item13type", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item13type` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem13type], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item14type", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item14type` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem14type], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item15type", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item15type` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem15type], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item16type", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item16type` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem16type], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item17type", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item17type` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem17type], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item18type", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item18type` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem18type], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item19type", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item19type` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem19type], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item20type", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item20type` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem20type], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item21type", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item21type` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem21type], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item22type", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item22type` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem22type], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item23type", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item23type` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem23type], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item24type", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item24type` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem24type], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item25type", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item25type` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem25type], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item11param", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item11param` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem11param], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item12param", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item12param` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem12param], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item13param", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item13param` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem13param], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item14param", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item14param` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem14param], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item15param", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item15param` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem15param], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item16param", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item16param` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem16param], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item17param", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item17param` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem17param], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item18param", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item18param` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem18param], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item19param", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item19param` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem19param], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item20param", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item20param` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem20param], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item21param", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item21param` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem21param], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item22param", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item22param` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem22param], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item23param", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item23param` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem23param], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item24param", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item24param` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem24param], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item25param", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item25param` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem25param], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item11param2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item11param2` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem11param2], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item12param2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item12param2` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem12param2], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item13param2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item13param2` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem13param2], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item14param2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item14param2` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem14param2], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item15param2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item15param2` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem15param2], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item16param2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item16param2` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem16param2], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item17param2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item17param2` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem17param2], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item18param2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item18param2` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem18param2], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item19param2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item19param2` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem19param2], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item20param2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item20param2` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem20param2], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item21param2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item21param2` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem21param2], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item22param2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item22param2` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem22param2], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item23param2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item23param2` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem23param2], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item24param2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item24param2` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem24param2], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item25param2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item25param2` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem25param2], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item11param3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item11param3` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem11param3], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item12param3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item12param3` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem12param3], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item13param3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item13param3` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem13param3], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item14param3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item14param3` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem14param3], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item15param3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item15param3` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem15param3], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item16param3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item16param3` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem16param3], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item17param3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item17param3` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem17param3], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item18param3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item18param3` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem18param3], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item19param3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item19param3` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem19param3], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item20param3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item20param3` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem20param3], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item21param3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item21param3` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem21param3], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item22param3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item22param3` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem22param3], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item23param3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item23param3` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem23param3], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item24param3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item24param3` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem24param3], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item25param3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item25param3` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem25param3], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item11param4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item11param4` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem11param4], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item12param4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item12param4` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem12param4], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item13param4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item13param4` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem13param4], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item14param4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item14param4` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem14param4], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item15param4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item15param4` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem15param4], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item16param4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item16param4` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem16param4], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item17param4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item17param4` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem17param4], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item18param4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item18param4` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem18param4], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item19param4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item19param4` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem19param4], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item20param4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item20param4` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem20param4], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item21param4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item21param4` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem21param4], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item22param4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item22param4` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem22param4], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item23param4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item23param4` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem23param4], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item24param4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item24param4` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem24param4], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item25param4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item25param4` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem25param4], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item11param5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item11param5` = '%s' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem11param5], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item12param5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item12param5` = '%s' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem12param5], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item13param5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item13param5` = '%s' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem13param5], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item14param5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item14param5` = '%s' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem14param5], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item15param5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item15param5` = '%s' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem15param5], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item16param5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item16param5` = '%s' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem16param5], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item17param5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item17param5` = '%s' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem17param5], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item18param5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item18param5` = '%s' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem18param5], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item19param5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item19param5` = '%s' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem19param5], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item20param5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item20param5` = '%s' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem20param5], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item21param5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item21param5` = '%s' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem21param5], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item22param5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item22param5` = '%s' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem22param5], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item23param5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item23param5` = '%s' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem23param5], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item24param5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item24param5` = '%s' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem24param5], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item25param5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item25param5` = '%s' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem25param5], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item11param6", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item11param6` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem11param6], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item12param6", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item12param6` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem12param6], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item13param6", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item13param6` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem13param6], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item14param6", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item14param6` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem14param6], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item15param6", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item15param6` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem15param6], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item16param6", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item16param6` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem16param6], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item17param6", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item17param6` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem17param6], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item18param6", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item18param6` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem18param6], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item19param6", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item19param6` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem19param6], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item20param6", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item20param6` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem20param6], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item21param6", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item21param6` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem21param6], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item22param6", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item22param6` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem22param6], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item23param6", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item23param6` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem23param6], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item24param6", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item24param6` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem24param6], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Item25param6", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_items3` SET `Item25param6` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pItem25param6], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Job", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_jobs` SET `Job` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pJob], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "JobLvl", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_jobs` SET `JobLvl` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pJobLvl], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "MzgkJobLvl", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_jobs` SET `MzgkJobLvl` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pMzgkJobLvl], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "SweeperJobLvl", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_jobs` SET `SweeperJobLvl` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pSweeperJobLvl], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "CarJackerJobLvl", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_jobs` SET `CarJackerJobLvl` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pCarJackerJobLvl], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "MechanicJobLvl", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_jobs` SET `MechanicJobLvl` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pMechanicJobLvl], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "FarmerJobLvl", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_jobs` SET `FarmerJobLvl` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pFarmerJobLvl], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "BusJobPoints", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_jobs` SET `BusJobPoints` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pBusJobPoints], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "MzgkJobPoints", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_jobs` SET `MzgkJobPoints` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pMzgkJobPoints], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "SweeperJobPoints", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_jobs` SET `SweeperJobPoints` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pSweeperJobPoints], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "CarJackerJobPoints", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_jobs` SET `CarJackerJobPoints` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pCarJackerJobPoints], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "MechanicJobPoints", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_jobs` SET `MechanicJobPoints` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pMechanicJobPoints], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "FarmerJobPoints", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_jobs` SET `FarmerJobPoints` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pFarmerJobPoints], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "BizKey", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_keys` SET `BizKey` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pBizKey], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "BoatLic", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_lic` SET `BoatLic` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pBoatLic], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "PlaneLic", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_lic` SET `PlaneLic` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pPlaneLic], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "HeliLic", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_lic` SET `HeliLic` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pHeliLic], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "WepLic", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_lic` SET `WepLic` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pWepLic], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "PenaltyPointsA", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_lic` SET `PenaltyPointsA` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pPenaltyPointsA], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "PenaltyPointsB", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_lic` SET `PenaltyPointsB` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pPenaltyPointsB], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "PenaltyPointsCE", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_lic` SET `PenaltyPointsCE` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pPenaltyPointsCE], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "TestAreaTimeLeft", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `TestAreaTimeLeft` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pTestAreaTimeLeft], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "PhoneC", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `PhoneC` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pPhoneC], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "PhoneBook", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `PhoneBook` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pPhoneBook], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "ListNumber", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `ListNumber` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pListNumber], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Donator", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `Donator` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pDonator], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Drugs", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `Drugs` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pDrugs], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "DrugsEffect", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `DrugsEffect` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pDrugsEffect], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "DrugsTaken", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `DrugsTaken` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pDrugsTaken], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "DrugsAddicted", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `DrugsAddicted` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pDrugsAddicted], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Materials", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `Materials` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pMaterials], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Goggles", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `Goggles` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pGoggles], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Cost", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `Cost` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pCost], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Ticket", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `Ticket` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pTicket], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "HP", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `HP` = '%f' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pHP], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Armour", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `Armour` = '%f' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pArmour], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Head", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `Head` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pHead], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Torso", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `Torso` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pTorso], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Detoks", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `Detoks` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pDetoks], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "WSlot", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `WSlot0` = '%d', `WSlot0Ammo` = '%d', `WSlot1` = '%d', `WSlot1Ammo` = '%d'",
				gPlayerData[playerid][pWSlot0], gPlayerData[playerid][pWSlot0Ammo], gPlayerData[playerid][pWSlot1], gPlayerData[playerid][pWSlot1Ammo]);
			format(string, sizeof(string), "%s, `WSlot2` = '%d', `WSlot2Ammo` = '%d', `WSlot3` = '%d', `WSlot3Ammo` = '%d', `WSlot4` = '%d', `WSlot4Ammo` = '%d', `WSlot5` = '%d', `WSlot5Ammo` = '%d'",
				string, gPlayerData[playerid][pWSlot2], gPlayerData[playerid][pWSlot2Ammo], gPlayerData[playerid][pWSlot3], gPlayerData[playerid][pWSlot3Ammo],
				gPlayerData[playerid][pWSlot4], gPlayerData[playerid][pWSlot4Ammo], gPlayerData[playerid][pWSlot5], gPlayerData[playerid][pWSlot5Ammo]
			);
			format(string, sizeof(string), "%s, `WSlot6` = '%d', `WSlot6Ammo` = '%d' WHERE `PlayerName` = '%s'",
				string, gPlayerData[playerid][pWSlot6], gPlayerData[playerid][pWSlot6Ammo], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "WSlot0", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `WSlot0` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pWSlot0], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "WSlot0Ammo", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `WSlot0Ammo` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pWSlot0Ammo], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "WSlot1", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `WSlot1` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pWSlot1], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "WSlot1Ammo", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `WSlot1Ammo` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pWSlot1Ammo], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "WSlot2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `WSlot2` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pWSlot2], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "WSlot2Ammo", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `WSlot2Ammo` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pWSlot2Ammo], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "WSlot3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `WSlot3` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pWSlot3], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "WSlot3Ammo", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `WSlot3Ammo` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pWSlot3Ammo], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "WSlot4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `WSlot4` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pWSlot4], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "WSlot4Ammo", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `WSlot4Ammo` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pWSlot4Ammo], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "WSlot5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `WSlot5` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pWSlot5], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "WSlot5Ammo", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `WSlot5Ammo` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pWSlot5Ammo], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "WSlot6", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `WSlot6` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pWSlot6], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "WSlot6Ammo", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `WSlot6Ammo` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pWSlot6Ammo], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "RPCount", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `RPCount` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pRPCount], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "DeathCount", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `DeathCount` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pDeathCount], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Score", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `Score` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pScore], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "MechanicCoolDown", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `MechanicCoolDown` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pMechanicCoolDown], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "FirstATest", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `FirstATest` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pFirstATest], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "FirstBTest", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `FirstBTest` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pFirstBTest], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "FirstCETest", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other` SET `FirstCETest` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pFirstCETest], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "PktBio", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other2` SET `PktBio` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pPktBio], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "PktFiz", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other2` SET `PktFiz` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pPktFiz], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "PktHis", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other2` SET `PktHis` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pPktHis], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "PktPol", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other2` SET `PktPol` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pPktPol], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "PktMat", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other2` SET `PktMat` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pPktMat], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "PktWf", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other2` SET `PktWf` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pPktWf], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "PktAng", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other2` SET `PktAng` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pPktAng], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Dowod", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other2` SET `Dowod` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pDowod], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Inz", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other2` SET `Inz` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pInz], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Magister", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other2` SET `Magister` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pMagister], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Doktor", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other2` SET `Doktor` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pDoktor], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Bio", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other2` SET `Bio` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pBio], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Fiz", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other2` SET `Fiz` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pFiz], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "His", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other2` SET `His` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pHis], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Pol", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other2` SET `Pol` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pPol], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Mat", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other2` SET `Mat` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pMat], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Wf", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other2` SET `Wf` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pWf], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Ang", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other2` SET `Ang` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pAng], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "Duty", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other2` SET `Duty` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pDuty], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "PartType", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other2` SET `PartType` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pPartType], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "PartItem", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other2` SET `PartItem` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pPartItem], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "MountsLeft", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other2` SET `MountsLeft` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pMountsLeft], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "WFOrderedCount", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other2` SET `WFOrderedCount` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pWFOrderedCount], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "SpeedGunOn", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other2` SET `SpeedGunOn` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pSpeedGunOn], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "IsDeptor", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other2` SET `IsDeptor` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pIsDeptor], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "LastLogged", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other2` SET `LastLogged` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[playerid][pLastLogged], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		if(strcmp(column, "QuizWrongAnsweres", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_users_other2` SET `QuizWrongAnsweres` = '%d' WHERE `PlayerName` = '%s'", gPlayerVars[playerid][mQuizWrongAnsweres], gPlayerData[playerid][pName]);
			mysql_query(string, SAVE2, playerid, db_con3);
			return 1;
		}
		format(string, sizeof(string), "[WARNING:] Unknown column: %s", column);
		ErrorLog(string);
	}
	return 1;
}

SaveHouseData(houseid, column[])
{
	new string[128];
	if(strlen(column) != 0)
	{
		if(strcmp(column, "Description", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses` SET `Description` = '%s' WHERE `ID` = '%d'", Houses[houseid][Description], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Owner", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses` SET `Owner` = '%s' WHERE `ID` = '%d'", Houses[houseid][Owner], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "UID", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses` SET `UID` = '%d' WHERE `ID` = '%d'", Houses[houseid][HUID], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}		
		if(strcmp(column, "Renter", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses` SET `Renter` = '%s' WHERE `ID` = '%d'", Houses[houseid][HRenter], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "EnterX", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses` SET `EnterX` = '%f' WHERE `ID` = '%d'", Houses[houseid][EnterX], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "EnterY", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses` SET `EnterY` = '%f' WHERE `ID` = '%d'", Houses[houseid][EnterY], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "EnterZ", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses` SET `EnterZ` = '%f' WHERE `ID` = '%d'", Houses[houseid][EnterZ], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "EnterWorld", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses` SET `EnterWorld` = '%d' WHERE `ID` = '%d'", Houses[houseid][EnterWorld], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "EnterInterior", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses` SET `EnterInterior` = '%d' WHERE `ID` = '%d'", Houses[houseid][EnterInterior], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "EnterAngle", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses` SET `EnterAngle` = '%f' WHERE `ID` = '%d'", Houses[houseid][EnterAngle], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "ExitX", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses` SET `ExitX` = '%f' WHERE `ID` = '%d'", Houses[houseid][ExitX], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "ExitY", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses` SET `ExitY` = '%f' WHERE `ID` = '%d'", Houses[houseid][ExitY], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "ExitZ", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses` SET `ExitZ` = '%f' WHERE `ID` = '%d'", Houses[houseid][ExitZ], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "ExitAngle", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses` SET `ExitAngle` = '%f' WHERE `ID` = '%d'", Houses[houseid][ExitAngle], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "ExitInterior", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses` SET `ExitInterior` = '%d' WHERE `ID` = '%d'", Houses[houseid][ExitInterior], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Owned", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses` SET `Owned` = '%d' WHERE `ID` = '%d'", Houses[houseid][Owned], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rentable", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses` SET `Rentable` = '%d' WHERE `ID` = '%d'", Houses[houseid][Rentable], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "RentCost", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses` SET `RentCost` = '%d' WHERE `ID` = '%d'", Houses[houseid][RentCost], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "HousePrice", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses` SET `HousePrice` = '%d' WHERE `ID` = '%d'", Houses[houseid][HousePrice], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Money", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses` SET `Money` = '%d' WHERE `ID` = '%d'", Houses[houseid][Money], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Locked", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses` SET `Locked` = '%d' WHERE `ID` = '%d'", Houses[houseid][Locked], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "HRadio1Bought", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses` SET `HRadio1Bought` = '%d' WHERE `ID` = '%d'", Houses[houseid][HRadio1Bought], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "HRadio1On", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses` SET `HRadio1On` = '%d' WHERE `ID` = '%d'", Houses[houseid][HRadio1On], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "HRadio1Ch", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses` SET `HRadio1Ch` = '%d' WHERE `ID` = '%d'", Houses[houseid][HRadio1Ch], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "HRadio1Vol", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses` SET `HRadio1Vol` = '%d' WHERE `ID` = '%d'", Houses[houseid][HRadio1Vol], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "HRadio1X", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses` SET `HRadio1X` = '%f' WHERE `ID` = '%d'", Houses[houseid][HRadio1X], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "HRadio1Y", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses` SET `HRadio1Y` = '%f' WHERE `ID` = '%d'", Houses[houseid][HRadio1Y], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "HRadio1Z", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses` SET `HRadio1Z` = '%f' WHERE `ID` = '%d'", Houses[houseid][HRadio1Z], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "HRadio1Angle", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses` SET `HRadio1Angle` = '%f' WHERE `ID` = '%d'", Houses[houseid][HRadio1Angle], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "HouseType", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses` SET `HouseType` = '%d' WHERE `ID` = '%d'", Houses[houseid][HouseType], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "HItem1", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses_items` SET `HItem1` = '%d' WHERE `ID` = '%d'", Houses[houseid][HItem1], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "HItem2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses_items` SET `HItem2` = '%d' WHERE `ID` = '%d'", Houses[houseid][HItem2], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "HItem3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses_items` SET `HItem3` = '%d' WHERE `ID` = '%d'", Houses[houseid][HItem3], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "HItem4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses_items` SET `HItem4` = '%d' WHERE `ID` = '%d'", Houses[houseid][HItem4], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "HItem5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses_items` SET `HItem5` = '%d' WHERE `ID` = '%d'", Houses[houseid][HItem5], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "HItem1type", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses_items` SET `HItem1type` = '%d' WHERE `ID` = '%d'", Houses[houseid][HItem1type], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "HItem2type", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses_items` SET `HItem2type` = '%d' WHERE `ID` = '%d'", Houses[houseid][HItem2type], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "HItem3type", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses_items` SET `HItem3type` = '%d' WHERE `ID` = '%d'", Houses[houseid][HItem3type], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "HItem4type", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses_items` SET `HItem4type` = '%d' WHERE `ID` = '%d'", Houses[houseid][HItem4type], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "HItem5type", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses_items` SET `HItem5type` = '%d' WHERE `ID` = '%d'", Houses[houseid][HItem5type], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "HItem1param", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses_items` SET `HItem1param` = '%d' WHERE `ID` = '%d'", Houses[houseid][HItem1param], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "HItem2param", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses_items` SET `HItem2param` = '%d' WHERE `ID` = '%d'", Houses[houseid][HItem2param], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "HItem3param", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses_items` SET `HItem3param` = '%d' WHERE `ID` = '%d'", Houses[houseid][HItem3param], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "HItem4param", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses_items` SET `HItem4param` = '%d' WHERE `ID` = '%d'", Houses[houseid][HItem4param], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "HItem5param", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses_items` SET `HItem5param` = '%d' WHERE `ID` = '%d'", Houses[houseid][HItem5param], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "HItem1param2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses_items` SET `HItem1param2` = '%d' WHERE `ID` = '%d'", Houses[houseid][HItem1param2], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "HItem2param2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses_items` SET `HItem2param2` = '%d' WHERE `ID` = '%d'", Houses[houseid][HItem2param2], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "HItem3param2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses_items` SET `HItem3param2` = '%d' WHERE `ID` = '%d'", Houses[houseid][HItem3param2], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "HItem4param2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses_items` SET `HItem4param2` = '%d' WHERE `ID` = '%d'", Houses[houseid][HItem4param2], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "HItem5param2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses_items` SET `HItem5param2` = '%d' WHERE `ID` = '%d'", Houses[houseid][HItem5param2], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "HItem1param3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses_items` SET `HItem1param3` = '%d' WHERE `ID` = '%d'", Houses[houseid][HItem1param3], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "HItem2param3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses_items` SET `HItem2param3` = '%d' WHERE `ID` = '%d'", Houses[houseid][HItem2param3], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "HItem3param3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses_items` SET `HItem3param3` = '%d' WHERE `ID` = '%d'", Houses[houseid][HItem3param3], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "HItem4param3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses_items` SET `HItem4param3` = '%d' WHERE `ID` = '%d'", Houses[houseid][HItem4param3], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "HItem5param3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses_items` SET `HItem5param3` = '%d' WHERE `ID` = '%d'", Houses[houseid][HItem5param3], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "HItem1param4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses_items` SET `HItem1param4` = '%d' WHERE `ID` = '%d'", Houses[houseid][HItem1param4], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "HItem2param4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses_items` SET `HItem2param4` = '%d' WHERE `ID` = '%d'", Houses[houseid][HItem2param4], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "HItem3param4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses_items` SET `HItem3param4` = '%d' WHERE `ID` = '%d'", Houses[houseid][HItem3param4], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "HItem4param4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses_items` SET `HItem4param4` = '%d' WHERE `ID` = '%d'", Houses[houseid][HItem4param4], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "HItem5param4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses_items` SET `HItem5param4` = '%d' WHERE `ID` = '%d'", Houses[houseid][HItem5param4], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "HItem1param5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses_items` SET `HItem1param5` = '%s' WHERE `ID` = '%d'", Houses[houseid][HItem1param5], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "HItem2param5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses_items` SET `HItem2param5` = '%s' WHERE `ID` = '%d'", Houses[houseid][HItem2param5], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "HItem3param5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses_items` SET `HItem3param5` = '%s' WHERE `ID` = '%d' ", Houses[houseid][HItem3param5], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "HItem4param5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses_items` SET `HItem4param5` = '%s' WHERE `ID` = '%d'", Houses[houseid][HItem4param5], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "HItem5param5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses_items` SET `HItem5param5` = '%s' WHERE `ID` = '%d'", Houses[houseid][HItem5param5], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "HItem1param6", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses_items` SET `HItem1param6` = '%d' WHERE `ID` = '%d'", Houses[houseid][HItem1param6], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "HItem2param6", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses_items` SET `HItem2param6` = '%d' WHERE `ID` = '%d'", Houses[houseid][HItem2param6], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "HItem3param6", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses_items` SET `HItem3param6` = '%d' WHERE `ID` = '%d'", Houses[houseid][HItem3param6], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "HItem4param6", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses_items` SET `HItem4param6` = '%d' WHERE `ID` = '%d'", Houses[houseid][HItem4param6], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "HItem5param6", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses_items` SET `HItem5param6` = '%d' WHERE `ID` = '%d'", Houses[houseid][HItem5param6], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Confiscated", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses` SET `Confiscated` = '%d' WHERE `ID` = '%d'", Houses[houseid][HConfiscated], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Placed", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses` SET `Placed` = '%d' WHERE `ID` = '%d'", Houses[houseid][HPlaced], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "IntSet", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses` SET `IntSet` = '%d' WHERE `ID` = '%d'", Houses[houseid][HIntSet], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Interior", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses` SET `Interior` = '%d' WHERE `ID` = '%d'", Houses[houseid][HInterior], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "HouseType", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses` SET `HouseType` = '%d' WHERE `ID` = '%d'", Houses[houseid][HouseType], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Alarm", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses` SET `Alarm` = '%d' WHERE `ID` = '%d'", Houses[houseid][HAlarm], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Robbed", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_houses` SET `Robbed` = '%d' WHERE `ID` = '%d'", Houses[houseid][HRobbed], houseid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		format(string, sizeof(string), "[WARNING:] Unknown column: %s", column);
		ErrorLog(string);
	}
	return 1;
}

SaveFData(fid, column[])
{
	new string[128];
	if(strlen(column) != 0)
	{	
		if(strcmp(column, "Rank2TillCheck", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank2TillCheck` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank2TillCheck], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank2FactionStatus", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank2FactionStatus` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank2FactionStatus], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank2VehBuy", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank2VehBuy` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank2VehBuy], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank2VehSell", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank2VehSell` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank2VehSell], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank2VehSalvage", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank2VehSalvage` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank2VehSalvage], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank2VehDrive", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank2VehDrive` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank2VehDrive], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank2TerritoryWar", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank2TerritoryWar` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank2TerritoryWar], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank2BurnFactory", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank2BurnFactory` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank2BurnFactory], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank3TillCheck", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank3TillCheck` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank3TillCheck], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank3FactionStatus", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank3FactionStatus` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank3FactionStatus], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank3VehBuy", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank3VehBuy` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank3VehBuy], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank3VehSell", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank3VehSell` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank3VehSell], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank3VehSalvage", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank3VehSalvage` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank3VehSalvage], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank3VehDrive", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank3VehDrive` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank3VehDrive], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank3TerritoryWar", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank3TerritoryWar` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank3TerritoryWar], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}	
		if(strcmp(column, "Rank3BurnFactory", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank3BurnFactory` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank3BurnFactory], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank4TillCheck", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank4TillCheck` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank4TillCheck], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank4FactionStatus", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank4FactionStatus` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank4FactionStatus], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank4VehBuy", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank4VehBuy` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank4VehBuy], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank4VehSell", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank4VehSell` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank4VehSell], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank4VehSalvage", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank4VehSalvage` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank4VehSalvage], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank4VehDrive", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank4VehDrive` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank4VehDrive], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank4TerritoryWar", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank4TerritoryWar` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank4TerritoryWar], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}	
		if(strcmp(column, "Rank4BurnFactory", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank4BurnFactory` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank4BurnFactory], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank5TillCheck", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank5TillCheck` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank5TillCheck], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank5FactionStatus", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank5FactionStatus` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank5FactionStatus], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank5VehBuy", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank5VehBuy` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank5VehBuy], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank5VehSell", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank5VehSell` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank5VehSell], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank5VehSalvage", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank5VehSalvage` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank5VehSalvage], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank5VehDrive", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank5VehDrive` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank5VehDrive], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank5TerritoryWar", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank5TerritoryWar` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank5TerritoryWar], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}	
		if(strcmp(column, "Rank5BurnFactory", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank5BurnFactory` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank5BurnFactory], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank6TillCheck", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank6TillCheck` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank6TillCheck], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank6FactionStatus", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank6FactionStatus` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank6FactionStatus], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank6VehBuy", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank6VehBuy` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank6VehBuy], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank6VehSell", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank6VehSell` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank6VehSell], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank6VehSalvage", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank6VehSalvage` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank6VehSalvage], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank6VehDrive", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank6VehDrive` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank6VehDrive], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank6TerritoryWar", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank6TerritoryWar` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank6TerritoryWar], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}	
		if(strcmp(column, "Rank6BurnFactory", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank6BurnFactory` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank6BurnFactory], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank7TillCheck", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank7TillCheck` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank7TillCheck], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank7FactionStatus", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank7FactionStatus` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank7FactionStatus], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank7VehBuy", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank7VehBuy` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank7VehBuy], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank7VehSell", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank7VehSell` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank7VehSell], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank7VehSalvage", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank7VehSalvage` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank7VehSalvage], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank7VehDrive", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank7VehDrive` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank7VehDrive], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank7TerritoryWar", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank7TerritoryWar` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank7TerritoryWar], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}	
		if(strcmp(column, "Rank7BurnFactory", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank7BurnFactory` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank7BurnFactory], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank8TillCheck", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank8TillCheck` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank8TillCheck], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank8FactionStatus", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank8FactionStatus` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank8FactionStatus], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank8VehBuy", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank8VehBuy` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank8VehBuy], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank8VehSell", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank8VehSell` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank8VehSell], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank8VehSalvage", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank8VehSalvage` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank8VehSalvage], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank8VehDrive", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank8VehDrive` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank8VehDrive], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank8TerritoryWar", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank8TerritoryWar` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank8TerritoryWar], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}	
		if(strcmp(column, "Rank8BurnFactory", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank8BurnFactory` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank8BurnFactory], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank9TillCheck", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank9TillCheck` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank9TillCheck], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank9FactionStatus", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank9FactionStatus` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank9FactionStatus], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank9VehBuy", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank9VehBuy` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank9VehBuy], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank9VehSell", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank9VehSell` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank9VehSell], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank9VehSalvage", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank9VehSalvage` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank9VehSalvage], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank9VehDrive", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank9VehDrive` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank9VehDrive], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank9TerritoryWar", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank9TerritoryWar` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank9TerritoryWar], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}	
		if(strcmp(column, "Rank9BurnFactory", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank9BurnFactory` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank9BurnFactory], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank10TillCheck", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank10TillCheck` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank10TillCheck], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank10FactionStatus", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank10FactionStatus` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank10FactionStatus], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank10VehBuy", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank10VehBuy` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank10VehBuy], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank10VehSell", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank10VehSell` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank10VehSell], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank10VehSalvage", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank10VehSalvage` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank10VehSalvage], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank10VehDrive", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank10VehDrive` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank10VehDrive], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank10TerritoryWar", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank10TerritoryWar` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank10TerritoryWar], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank10BurnFactory", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank10BurnFactory` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRank10BurnFactory], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "IsEnabled", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `IsEnabled` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][IsEnabled], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "TaxiKMCost", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `TaxiKMCost` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fTaxiKMCost], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "TaxiEnterCost", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `TaxiEnterCost` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fTaxiEnterCost], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "HealCost", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `HealCost` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fHealCost], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "HealPrice", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `HealPrice` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fHealPrice], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "ExamineCost", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `ExamineCost` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fExamineCost], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "ExaminePrice", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `ExaminePrice` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fExaminePrice], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "TerritoryWarWins", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `TerritoryWarWins` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fTerritoryWarWins], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "TerritoryWarLooses", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `TerritoryWarLooses` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fTerritoryWarLooses], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "SimActivationCost", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `SimActivationCost` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][mSimActivationCost], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "SimDailyFee", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `SimDailyFee` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][mSimDailyFee], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "SimFreeMins", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `SimFreeMins` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][mSimFreeMins], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "SimFreeSms", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `SimFreeSms` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][mSimFreeSms], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "SmsCostFee", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `SmsCostFee` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][mSmsCostFee], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CallCostFee", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `CallCostFee` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][mCallCostFee], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "SmsCostCard", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `SmsCostCard` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][mSmsCostCard], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CallCostCard", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `CallCostCard` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][mCallCostCard], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CardValidity", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `CardValidity` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][mCardValidity], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CardRenewCost1", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `CardRenewCost1` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][mCardRenewCost1], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CardRenewTime1", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `CardRenewTime1` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][mCardRenewTime1], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CardRenewCost2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `CardRenewCost2` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][mCardRenewCost2], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CardRenewTime2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `CardRenewTime2` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][mCardRenewTime2], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CardRenewCost3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `CardRenewCost3` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][mCardRenewCost3], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CardRenewTime3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `CardRenewTime3` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][mCardRenewTime3], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CardRenewCost4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `CardRenewCost4` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][mCardRenewCost4], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CardRenewTime4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `CardRenewTime4` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][mCardRenewTime4], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "VehicleStealExportTimeLeft", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `VehicleStealExportTimeLeft` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][mVehicleStealExportTimeLeft], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "VehicleStealExportCpId", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `VehicleStealExportCpId` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][mVehicleStealExportCpId], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "BizConIncome", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `BizConIncome` = '%f' WHERE `ID` = '%d'", DynamicFactions[fid][mBizConIncome], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "BizOfferIncome", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `BizOfferIncome` = '%f' WHERE `ID` = '%d'", DynamicFactions[fid][mBizOfferIncome], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "BizJoinCash", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `BizJoinCash` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][mBizJoinCash], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "BizJoinTime", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `BizJoinTime` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][mBizJoinTime], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "BizPenaltyValue", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `BizPenaltyValue` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][mBizPenaltyValue], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Name", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Name` = '%s' WHERE `ID` = '%d'", DynamicFactions[fid][Name], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CompanyName", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `CompanyName` = '%s' WHERE `ID` = '%d'", DynamicFactions[fid][mCompanyName], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "X", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `X` = '%f' WHERE `ID` = '%d'", DynamicFactions[fid][m_fX], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Y", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Y` = '%f' WHERE `ID` = '%d'", DynamicFactions[fid][m_fY], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Z", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Z` = '%f' WHERE `ID` = '%d'", DynamicFactions[fid][m_fZ], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Materials", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Materials` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fMaterials], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Drugs", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Drugs` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fDrugs], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Bank", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Bank` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fBank], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank1", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank1` = '%s' WHERE `ID` = '%d'", DynamicFactions[fid][fRank1], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank2` = '%s' WHERE `ID` = '%d'", DynamicFactions[fid][fRank2], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank3` = '%s' WHERE `ID` = '%d'", DynamicFactions[fid][fRank3], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank4` = '%s' WHERE `ID` = '%d'", DynamicFactions[fid][fRank4], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank5` = '%s' WHERE `ID` = '%d'", DynamicFactions[fid][fRank5], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank6", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank6` = '%s' WHERE `ID` = '%d'", DynamicFactions[fid][fRank6], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank7", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank7` = '%s' WHERE `ID` = '%d'", DynamicFactions[fid][fRank7], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank8", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank8` = '%s' WHERE `ID` = '%d'", DynamicFactions[fid][fRank8], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank9", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank9` = '%s' WHERE `ID` = '%d'", DynamicFactions[fid][fRank9], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Rank10", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Rank10` = '%s' WHERE `ID` = '%d'", DynamicFactions[fid][fRank10], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Skin1", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Skin1` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fSkin1], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Skin2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Skin2` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fSkin2], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Skin3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Skin3` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fSkin3], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Skin4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Skin4` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fSkin4], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Skin5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Skin5` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fSkin5], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Skin6", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Skin6` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fSkin6], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Skin7", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Skin7` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fSkin7], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Skin8", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Skin8` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fSkin8], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Skin9", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Skin9` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fSkin9], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Skin10", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Skin10` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fSkin10], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "JoinRank", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `JoinRank` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fJoinRank], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "UseSkins", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `UseSkins` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fUseSkins], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Type", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Type` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fType], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "RankAmount", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `RankAmount` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fRankAmount], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Color", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `Color` = '%s' WHERE `ID` = '%d'", DynamicFactions[fid][fColor], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "MaxCars", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `MaxCars` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fMaxCars], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CarsCount", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `CarsCount` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fCarsCount], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "XDuty", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `XDuty` = '%f' WHERE `ID` = '%d'", DynamicFactions[fid][fXDuty], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "YDuty", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `YDuty` = '%f' WHERE `ID` = '%d'", DynamicFactions[fid][fYDuty], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "ZDuty", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `ZDuty` = '%f' WHERE `ID` = '%d'", DynamicFactions[fid][fZDuty], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WorldDuty", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WorldDuty` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fWorldDuty], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "InteriorDuty", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `InteriorDuty` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fInteriorDuty], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "XDuty2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `XDuty2` = '%f' WHERE `ID` = '%d'", DynamicFactions[fid][fXDuty2], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "YDuty2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `YDuty2` = '%f' WHERE `ID` = '%d'", DynamicFactions[fid][fYDuty2], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "ZDuty2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `ZDuty2` = '%f' WHERE `ID` = '%d'", DynamicFactions[fid][fZDuty2], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WorldDuty2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WorldDuty2` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fWorldDuty2], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "InteriorDuty2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `InteriorDuty2` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fInteriorDuty2], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CarsRank", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `CarsRank` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fCarsRank], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Gun1Rank1", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions_weapons` SET `Gun1Rank1` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fGun1Rank1], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Gun1Rank2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions_weapons` SET `Gun1Rank2` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fGun1Rank2], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Gun1Rank3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions_weapons` SET `Gun1Rank3` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fGun1Rank3], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Gun1Rank4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions_weapons` SET `Gun1Rank4` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fGun1Rank4], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Gun1Rank5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions_weapons` SET `Gun1Rank5` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fGun1Rank5], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Gun1Rank6", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions_weapons` SET `Gun1Rank6` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fGun1Rank6], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Gun1Rank7", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions_weapons` SET `Gun1Rank7` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fGun1Rank7], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Gun1Rank8", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions_weapons` SET `Gun1Rank8` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fGun1Rank8], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Gun1Rank9", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions_weapons` SET `Gun1Rank9` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fGun1Rank9], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Gun1Rank10", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions_weapons` SET `Gun1Rank10` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fGun1Rank10], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Gun2Rank1", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions_weapons` SET `Gun2Rank1` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fGun2Rank1], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Gun2Rank2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions_weapons` SET `Gun2Rank2` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fGun2Rank2], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Gun2Rank3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions_weapons` SET `Gun2Rank3` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fGun2Rank3], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Gun2Rank4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions_weapons` SET `Gun2Rank4` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fGun2Rank4], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Gun2Rank5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions_weapons` SET `Gun2Rank5` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fGun2Rank5], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Gun2Rank6", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions_weapons` SET `Gun2Rank6` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fGun2Rank6], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Gun2Rank7", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions_weapons` SET `Gun2Rank7` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fGun2Rank7], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Gun2Rank8", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions_weapons` SET `Gun2Rank8` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fGun2Rank8], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Gun2Rank9", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions_weapons` SET `Gun2Rank9` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fGun2Rank9], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Gun2Rank10", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions_weapons` SET `Gun2Rank10` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fGun2Rank10], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Gun3Rank1", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions_weapons` SET `Gun3Rank1` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fGun3Rank1], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Gun3Rank2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions_weapons` SET `Gun3Rank2` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fGun3Rank2], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Gun3Rank3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions_weapons` SET `Gun3Rank3` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fGun3Rank3], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Gun3Rank4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions_weapons` SET `Gun3Rank4` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fGun3Rank4], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Gun3Rank5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions_weapons` SET `Gun3Rank5` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fGun3Rank5], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Gun3Rank6", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions_weapons` SET `Gun3Rank6` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fGun3Rank6], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Gun3Rank7", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions_weapons` SET `Gun3Rank7` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fGun3Rank7], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Gun3Rank8", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions_weapons` SET `Gun3Rank8` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fGun3Rank8], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Gun3Rank9", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions_weapons` SET `Gun3Rank9` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fGun3Rank9], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Gun3Rank10", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions_weapons` SET `Gun3Rank10` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fGun3Rank10], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Ammo1Rank1", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions_weapons2` SET `Ammo1Rank1` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fAmmo1Rank1], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Ammo1Rank2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions_weapons2` SET `Ammo1Rank2` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fAmmo1Rank2], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Ammo1Rank3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions_weapons2` SET `Ammo1Rank3` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fAmmo1Rank3], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Ammo1Rank4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions_weapons2` SET `Ammo1Rank4` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fAmmo1Rank4], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Ammo1Rank5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions_weapons2` SET `Ammo1Rank5` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fAmmo1Rank5], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Ammo1Rank6", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions_weapons2` SET `Ammo1Rank6` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fAmmo1Rank6], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Ammo1Rank7", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions_weapons2` SET `Ammo1Rank7` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fAmmo1Rank7], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Ammo1Rank8", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions_weapons2` SET `Ammo1Rank8` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fAmmo1Rank8], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Ammo1Rank9", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions_weapons2` SET `Ammo1Rank9` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fAmmo1Rank9], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Ammo1Rank10", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions_weapons2` SET `Ammo1Rank10` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fAmmo1Rank10], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Ammo2Rank1", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions_weapons2` SET `Ammo2Rank1` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fAmmo2Rank1], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Ammo2Rank2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions_weapons2` SET `Ammo2Rank2` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fAmmo2Rank2], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Ammo2Rank3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions_weapons2` SET `Ammo2Rank3` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fAmmo2Rank3], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Ammo2Rank4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions_weapons2` SET `Ammo2Rank4` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fAmmo2Rank4], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Ammo2Rank5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions_weapons2` SET `Ammo2Rank5` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fAmmo2Rank5], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Ammo2Rank6", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions_weapons2` SET `Ammo2Rank6` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fAmmo2Rank6], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Ammo2Rank7", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions_weapons2` SET `Ammo2Rank7` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fAmmo2Rank7], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Ammo2Rank8", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions_weapons2` SET `Ammo2Rank8` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fAmmo2Rank8], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Ammo2Rank9", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions_weapons2` SET `Ammo2Rank9` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fAmmo2Rank9], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Ammo2Rank10", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions_weapons2` SET `Ammo2Rank10` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fAmmo2Rank10], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Ammo3Rank1", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions_weapons2` SET `Ammo3Rank1` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fAmmo3Rank1], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Ammo3Rank2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions_weapons2` SET `Ammo3Rank2` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fAmmo3Rank2], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Ammo3Rank3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions_weapons2` SET `Ammo3Rank3` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fAmmo3Rank3], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Ammo3Rank4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions_weapons2` SET `Ammo3Rank4` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fAmmo3Rank4], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Ammo3Rank5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions_weapons2` SET `Ammo3Rank5` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fAmmo3Rank5], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Ammo3Rank6", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions_weapons2` SET `Ammo3Rank6` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fAmmo3Rank6], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Ammo3Rank7", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions_weapons2` SET `Ammo3Rank7` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fAmmo3Rank7], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Ammo3Rank8", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions_weapons2` SET `Ammo3Rank8` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fAmmo3Rank8], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Ammo3Rank9", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions_weapons2` SET `Ammo3Rank9` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fAmmo3Rank9], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Ammo3Rank10", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions_weapons2` SET `Ammo3Rank10` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][fAmmo3Rank10], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryBuildingID", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryBuildingID` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryBuildingID], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryEnabled", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryEnabled` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryEnabled], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryBurning", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryBurning` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryBurning], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryJustBought", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryJustBought` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryJustBought], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryCentrePosX", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryCentrePosX` = '%f' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryCentrePosX], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryCentrePosY", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryCentrePosY` = '%f' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryCentrePosY], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryCentrePosZ", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryCentrePosZ` = '%f' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryCentrePosZ], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		// if(strcmp(column, "WFactoryCPPartTakeX", true) == 0)
		// {
			// format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryCPPartTakeX` = '%f' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryCPPartTakeX], fid+1);
			// mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			// return 1;
		// }
		// if(strcmp(column, "WFactoryCPPartTakeY", true) == 0)
		// {
			// format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryCPPartTakeY` = '%f' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryCPPartTakeY], fid+1);
			// mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			// return 1;
		// }
		// if(strcmp(column, "WFactoryCPPartTakeZ", true) == 0)
		// {
			// format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryCPPartTakeZ` = '%f' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryCPPartTakeZ], fid+1);
			// mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			// return 1;
		// }
		// if(strcmp(column, "WFactoryCPPartSetup1X", true) == 0)
		// {
			// format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryCPPartSetup1X` = '%f' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryCPPartSetup1X], fid+1);
			// mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			// return 1;
		// }
		// if(strcmp(column, "WFactoryCPPartSetup1Y", true) == 0)
		// {
			// format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryCPPartSetup1Y` = '%f' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryCPPartSetup1Y], fid+1);
			// mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			// return 1;
		// }
		// if(strcmp(column, "WFactoryCPPartSetup1Z", true) == 0)
		// {
			// format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryCPPartSetup1Z` = '%f' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryCPPartSetup1Z], fid+1);
			// mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			// return 1;
		// }
		// if(strcmp(column, "WFactoryCPPartSetup2X", true) == 0)
		// {
			// format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryCPPartSetup2X` = '%f' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryCPPartSetup2X], fid+1);
			// mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			// return 1;
		// }
		// if(strcmp(column, "WFactoryCPPartSetup2Y", true) == 0)
		// {
			// format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryCPPartSetup2Y` = '%f' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryCPPartSetup2Y], fid+1);
			// mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			// return 1;
		// }
		// if(strcmp(column, "WFactoryCPPartSetup2Z", true) == 0)
		// {
			// format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryCPPartSetup2Z` = '%f' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryCPPartSetup2Z], fid+1);
			// mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			// return 1;
		// }
		// if(strcmp(column, "WFactoryCPPartSetup4X", true) == 0)
		// {
			// format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryCPPartSetup4X` = '%f' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryCPPartSetup4X], fid+1);
			// mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			// return 1;
		// }
		// if(strcmp(column, "WFactoryCPPartSetup4Y", true) == 0)
		// {
			// format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryCPPartSetup4Y` = '%f' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryCPPartSetup4Y], fid+1);
			// mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			// return 1;
		// }
		// if(strcmp(column, "WFactoryCPPartSetup4Z", true) == 0)
		// {
			// format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryCPPartSetup4Z` = '%f' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryCPPartSetup4Z], fid+1);
			// mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			// return 1;
		// }
		// if(strcmp(column, "WFactoryCPPartSetup4X", true) == 0)
		// {
			// format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryCPPartSetup4X` = '%f' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryCPPartSetup4X], fid+1);
			// mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			// return 1;
		// }
		// if(strcmp(column, "WFactoryCPPartSetup4Y", true) == 0)
		// {
			// format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryCPPartSetup4Y` = '%f' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryCPPartSetup4Y], fid+1);
			// mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			// return 1;
		// }
		// if(strcmp(column, "WFactoryCPPartSetup4Z", true) == 0)
		// {
			// format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryCPPartSetup4Z` = '%f' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryCPPartSetup4Z], fid+1);
			// mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			// return 1;
		// }
		// if(strcmp(column, "WFactoryCPPartSetup5X", true) == 0)
		// {
			// format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryCPPartSetup5X` = '%f' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryCPPartSetup5X], fid+1);
			// mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			// return 1;
		// }
		// if(strcmp(column, "WFactoryCPPartSetup5Y", true) == 0)
		// {
			// format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryCPPartSetup5Y` = '%f' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryCPPartSetup5Y], fid+1);
			// mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			// return 1;
		// }
		// if(strcmp(column, "WFactoryCPPartSetup5Z", true) == 0)
		// {
			// format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryCPPartSetup5Z` = '%f' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryCPPartSetup5Z], fid+1);
			// mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			// return 1;
		// }
		// if(strcmp(column, "WFactoryCPPartSetup6X", true) == 0)
		// {
			// format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryCPPartSetup6X` = '%f' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryCPPartSetup6X], fid+1);
			// mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			// return 1;
		// }
		// if(strcmp(column, "WFactoryCPPartSetup6Y", true) == 0)
		// {
			// format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryCPPartSetup6Y` = '%f' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryCPPartSetup6Y], fid+1);
			// mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			// return 1;
		// }
		// if(strcmp(column, "WFactoryCPPartSetup6Z", true) == 0)
		// {
			// format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryCPPartSetup6Z` = '%f' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryCPPartSetup6Z], fid+1);
			// mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			// return 1;
		// }
		// if(strcmp(column, "WFactoryCPPartSetup7X", true) == 0)
		// {
			// format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryCPPartSetup7X` = '%f' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryCPPartSetup7X], fid+1);
			// mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			// return 1;
		// }
		// if(strcmp(column, "WFactoryCPPartSetup7Y", true) == 0)
		// {
			// format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryCPPartSetup7Y` = '%f' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryCPPartSetup7Y], fid+1);
			// mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			// return 1;
		// }
		// if(strcmp(column, "WFactoryCPPartSetup7Z", true) == 0)
		// {
			// format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryCPPartSetup7Z` = '%f' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryCPPartSetup7Z], fid+1);
			// mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			// return 1;
		// }
		// if(strcmp(column, "WFactoryCPPartSetup8X", true) == 0)
		// {
			// format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryCPPartSetup8X` = '%f' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryCPPartSetup8X], fid+1);
			// mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			// return 1;
		// }
		// if(strcmp(column, "WFactoryCPPartSetup8Y", true) == 0)
		// {
			// format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryCPPartSetup8Y` = '%f' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryCPPartSetup8Y], fid+1);
			// mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			// return 1;
		// }
		// if(strcmp(column, "WFactoryCPPartSetup8Z", true) == 0)
		// {
			// format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryCPPartSetup8Z` = '%f' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryCPPartSetup8Z], fid+1);
			// mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			// return 1;
		// }
		// if(strcmp(column, "WFactoryCPSubPartSetup1X", true) == 0)
		// {
			// format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryCPSubPartSetup1X` = '%f' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryCPSubPartSetup1X], fid+1);
			// mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			// return 1;
		// }
		// if(strcmp(column, "WFactoryCPSubPartSetup1Y", true) == 0)
		// {
			// format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryCPSubPartSetup1Y` = '%f' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryCPSubPartSetup1Y], fid+1);
			// mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			// return 1;
		// }
		// if(strcmp(column, "WFactoryCPSubPartSetup1Z", true) == 0)
		// {
			// format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryCPSubPartSetup1Z` = '%f' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryCPSubPartSetup1Z], fid+1);
			// mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			// return 1;
		// }
		// if(strcmp(column, "WFactoryCPSubPartSetup2X", true) == 0)
		// {
			// format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryCPSubPartSetup2X` = '%f' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryCPSubPartSetup2X], fid+1);
			// mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			// return 1;
		// }
		// if(strcmp(column, "WFactoryCPSubPartSetup2Y", true) == 0)
		// {
			// format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryCPSubPartSetup2Y` = '%f' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryCPSubPartSetup2Y], fid+1);
			// mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			// return 1;
		// }
		// if(strcmp(column, "WFactoryCPSubPartSetup2Z", true) == 0)
		// {
			// format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryCPSubPartSetup2Z` = '%f' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryCPSubPartSetup2Z], fid+1);
			// mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			// return 1;
		// }
		// if(strcmp(column, "WFactoryCPSubPartSetup4X", true) == 0)
		// {
			// format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryCPSubPartSetup4X` = '%f' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryCPSubPartSetup4X], fid+1);
			// mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			// return 1;
		// }
		// if(strcmp(column, "WFactoryCPSubPartSetup4Y", true) == 0)
		// {
			// format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryCPSubPartSetup4Y` = '%f' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryCPSubPartSetup4Y], fid+1);
			// mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			// return 1;
		// }
		// if(strcmp(column, "WFactoryCPSubPartSetup4Z", true) == 0)
		// {
			// format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryCPSubPartSetup4Z` = '%f' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryCPSubPartSetup4Z], fid+1);
			// mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			// return 1;
		// }
		// if(strcmp(column, "WFactoryCPSubPartSetup4X", true) == 0)
		// {
			// format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryCPSubPartSetup4X` = '%f' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryCPSubPartSetup4X], fid+1);
			// mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			// return 1;
		// }
		// if(strcmp(column, "WFactoryCPSubPartSetup4Y", true) == 0)
		// {
			// format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryCPSubPartSetup4Y` = '%f' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryCPSubPartSetup4Y], fid+1);
			// mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			// return 1;
		// }
		// if(strcmp(column, "WFactoryCPSubPartSetup4Z", true) == 0)
		// {
			// format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryCPSubPartSetup4Z` = '%f' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryCPSubPartSetup4Z], fid+1);
			// mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			// return 1;
		// }
		// if(strcmp(column, "WFactoryCPSubPartSetup5X", true) == 0)
		// {
			// format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryCPSubPartSetup5X` = '%f' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryCPSubPartSetup5X], fid+1);
			// mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			// return 1;
		// }
		// if(strcmp(column, "WFactoryCPSubPartSetup5Y", true) == 0)
		// {
			// format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryCPSubPartSetup5Y` = '%f' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryCPSubPartSetup5Y], fid+1);
			// mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			// return 1;
		// }
		// if(strcmp(column, "WFactoryCPSubPartSetup5Z", true) == 0)
		// {
			// format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryCPSubPartSetup5Z` = '%f' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryCPSubPartSetup5Z], fid+1);
			// mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			// return 1;
		// }
		// if(strcmp(column, "WFactoryCPSubPartSetup6X", true) == 0)
		// {
			// format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryCPSubPartSetup6X` = '%f' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryCPSubPartSetup6X], fid+1);
			// mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			// return 1;
		// }
		// if(strcmp(column, "WFactoryCPSubPartSetup6Y", true) == 0)
		// {
			// format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryCPSubPartSetup6Y` = '%f' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryCPSubPartSetup6Y], fid+1);
			// mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			// return 1;
		// }
		// if(strcmp(column, "WFactoryCPSubPartSetup6Z", true) == 0)
		// {
			// format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryCPSubPartSetup6Z` = '%f' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryCPSubPartSetup6Z], fid+1);
			// mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			// return 1;
		// }
		// if(strcmp(column, "WFactoryCPSendX", true) == 0)
		// {
			// format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryCPSendX` = '%f' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryCPInsertX], fid+1);
			// mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			// return 1;
		// }
		// if(strcmp(column, "WFactoryCPSendY", true) == 0)
		// {
			// format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryCPSendY` = '%f' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryCPInsertY], fid+1);
			// mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			// return 1;
		// }
		// if(strcmp(column, "WFactoryCPSendZ", true) == 0)
		// {
			// format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryCPSendZ` = '%f' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryCPInsertZ], fid+1);
			// mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			// return 1;
		// }
		if(strcmp(column, "WFactory9MM", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactory9MM` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactory9MM], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactory9MMSil", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactory9MMSil` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactory9MMSil], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryDesEagle", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryDesEagle` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryDesEagle], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryMicroSMG", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryMicroSMG` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryMicroSMG], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryMP5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryMP5` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryMP5], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryTec9", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryTec9` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryTec9], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryShotgun", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryShotgun` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryShotgun], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryAK47", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryAK47` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryAK47], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryM4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryM4` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryM4], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryRifle", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryRifle` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryRifle], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactorySRifle", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactorySRifle` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactorySRifle], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactorySCharge", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactorySCharge` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactorySCharge], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactory9MMAmmo", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactory9MMAmmo` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactory9MMAmmo], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactory50AEAmmo", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactory50AEAmmo` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactory50AEAmmo], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryBuckshot", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryBuckshot` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryBuckshot], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactory762MMAmmo", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactory762MMAmmo` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactory762MMAmmo], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactory127MMAmmo", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactory127MMAmmo` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactory127MMAmmo], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryKGP66MMAmmo", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryKGP66MMAmmo` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryKGP66MMAmmo], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryNapalm", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryNapalm` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryNapalm], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryPistolPart1", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryPistolPart1` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryPistolPart1], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryPistolS1Part1", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryPistolS1Part1` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryPistolS1Part1], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryPistolS1Part2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryPistolS1Part2` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryPistolS1Part2], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryPistolS1Part3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryPistolS1Part3` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryPistolS1Part3], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryPistolPart2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryPistolPart2` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryPistolPart2], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryPistolS2Part1", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryPistolS2Part1` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryPistolS2Part1], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryPistolS2Part2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryPistolS2Part2` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryPistolS2Part2], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryPistolS2Part3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryPistolS2Part3` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryPistolS2Part3], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryPistolPart3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryPistolPart3` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryPistolPart3], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryPistolS3Part1", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryPistolS3Part1` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryPistolS3Part1], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryPistolS3Part2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryPistolS3Part2` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryPistolS3Part2], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryPistolS3Part3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryPistolS3Part3` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryPistolS3Part3], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryPistolS3Part4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryPistolS3Part4` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryPistolS3Part4], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryPistolPart4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryPistolPart4` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryPistolPart4], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryPistolPart5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryPistolPart5` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryPistolPart5], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryPistolPart6", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryPistolPart6` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryPistolPart6], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryRiflePart1", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryRiflePart1` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryRiflePart1], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryRifleS1Part1", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryRifleS1Part1` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryRifleS1Part1], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryRifleS1Part2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryRifleS1Part2` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryRifleS1Part2], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryRiflePart2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryRiflePart2` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryRiflePart2], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryRifleS2Part1", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryRifleS2Part1` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryRifleS2Part1], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryRifleS2Part2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryRifleS2Part2` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryRifleS2Part2], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryRifleS2Part3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryRifleS2Part3` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryRifleS2Part3], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryRiflePart3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryRiflePart3` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryRiflePart3], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryRifleS3Part1", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryRifleS3Part1` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryRifleS3Part1], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryRifleS3Part2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryRifleS3Part2` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryRifleS3Part2], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryRifleS3Part3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryRifleS3Part3` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryRifleS3Part3], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryRifleS3Part4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryRifleS3Part4` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryRifleS3Part4], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryRiflePart4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryRiflePart4` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryRiflePart4], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryRiflePart5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryRiflePart5` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryRiflePart5], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryRiflePart6", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryRiflePart6` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryRiflePart6], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryRiflePart7", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryRiflePart7` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryRiflePart7], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryRifleS6Part1", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryRifleS6Part1` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryRifleS6Part1], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryRifleS6Part2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryRifleS6Part2` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryRifleS6Part2], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryAmmoPart1a", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryAmmoPart1a` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryAmmoPart1a], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryAmmoPart2a", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryAmmoPart2a` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryAmmoPart2a], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryAmmoPart3a", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryAmmoPart3a` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryAmmoPart3a], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryAmmoPart4a", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryAmmoPart4a` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryAmmoPart4a], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryAmmoPart1b", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryAmmoPart1b` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryAmmoPart1b], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryAmmoPart2b", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryAmmoPart2b` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryAmmoPart2b], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryAmmoPart3b", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryAmmoPart3b` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryAmmoPart3b], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryAmmoPart4b", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryAmmoPart4b` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryAmmoPart4b], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryAmmoPart1c", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryAmmoPart1c` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryAmmoPart1c], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryAmmoPart2c", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryAmmoPart2c` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryAmmoPart2c], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryAmmoPart3c", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryAmmoPart3c` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryAmmoPart3c], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryAmmoPart4c", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryAmmoPart4c` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryAmmoPart4c], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryAmmoPart1d", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryAmmoPart1d` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryAmmoPart1d], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryAmmoPart2d", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryAmmoPart2d` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryAmmoPart2d], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryAmmoPart3d", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryAmmoPart3d` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryAmmoPart3d], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryAmmoPart4d", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryAmmoPart4d` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryAmmoPart4d], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryAmmoPart1e", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryAmmoPart1e` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryAmmoPart1e], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryAmmoPart2e", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryAmmoPart2e` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryAmmoPart2e], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryAmmoPart3e", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryAmmoPart3e` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryAmmoPart3e], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryAmmoPart4e", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryAmmoPart4e` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryAmmoPart4e], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryAK47Part", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryAK47Part` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryAK47Part], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryM4Part", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryM4Part` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryM4Part], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryRiflePart", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryRiflePart` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryRiflePart], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactorySniperPart", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactorySniperPart` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactorySniperPart], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryMP5Part", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryMP5Part` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryMP5Part], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryShotPart", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryShotPart` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryShotPart], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryDesEaglePart", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_factions` SET `WFactoryDesEaglePart` = '%d' WHERE `ID` = '%d'", DynamicFactions[fid][WFactoryDesEaglePart], fid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		format(string, sizeof(string), "[WARNING:] Unknown column: %s", column);
		ErrorLog(string);
	}
	return 1;
}

stock SaveBizData(bizid, column[])
{
	new string[128];
	if(strlen(column) != 0)
	{
		if(strcmp(column, "Faction", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Faction` = '%d' WHERE `id` = '%d' ", Businesses[bizid][mFaction], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "FactionTimeLeft", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `FactionTimeLeft` = '%d' WHERE `id` = '%d' ", Businesses[bizid][mFactionTimeLeft], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "IncomeFuelGasTotal", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `IncomeFuelGasTotal` = '%d' WHERE `ID` = '%d'", Businesses[bizid][mIncomeFuelGasTotal], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "IncomeFuelGasTotal", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `IncomeFuelGasTotal` = '%d' WHERE `ID` = '%d'", Businesses[bizid][mIncomeFuelGasTotal], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "IncomeFuelGasToday", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `IncomeFuelGasToday` = '%d' WHERE `ID` = '%d'", Businesses[bizid][mIncomeFuelGasToday], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "IncomeFuelOilTotal", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `IncomeFuelOilTotal` = '%d' WHERE `ID` = '%d'", Businesses[bizid][mIncomeFuelOilTotal], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "IncomeFuelOilToday", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `IncomeFuelOilToday` = '%d' WHERE `ID` = '%d'", Businesses[bizid][mIncomeFuelOilToday], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "IncomeFuelPetrolTotal", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `IncomeFuelPetrolTotal` = '%d' WHERE `ID` = '%d'", Businesses[bizid][mIncomeFuelPetrolTotal], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "IncomeFuelPetrolToday", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `IncomeFuelPetrolToday` = '%d' WHERE `ID` = '%d'", Businesses[bizid][mIncomeFuelPetrolToday], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "IncomePhoneTotal", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `IncomePhoneTotal` = '%d' WHERE `ID` = '%d'", Businesses[bizid][mIncomePhoneTotal], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "IncomePhoneToday", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `IncomePhoneToday` = '%d' WHERE `ID` = '%d'", Businesses[bizid][mIncomePhoneToday], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "IncomeVehicleTotal", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `IncomeVehicleTotal` = '%d' WHERE `ID` = '%d'", Businesses[bizid][mIncomeVehicleTotal], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "IncomeVehicleToday", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `IncomeVehicleToday` = '%d' WHERE `ID` = '%d'", Businesses[bizid][mIncomeVehicleToday], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "IncomeEntranceToday", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `IncomeEntranceToday` = '%d' WHERE `ID` = '%d'", Businesses[bizid][mIncomeEntranceToday], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "IncomeEntranceTotal", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `IncomeEntranceTotal` = '%d' WHERE `ID` = '%d'", Businesses[bizid][mIncomeEntranceTotal], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "IncomeTotal", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `IncomeTotal` = '%d' WHERE `ID` = '%d'", Businesses[bizid][mIncomeTotal], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "UID", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `UID` = '%d' WHERE `ID` = '%d'", Businesses[bizid][BUID], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product1incomeTotal", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product1incomeTotal` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product1incomeTotal], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product1incomeToday", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product1incomeToday` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product1incomeToday], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product2incomeTotal", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product2incomeTotal` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product2incomeTotal], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product2incomeToday", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product2incomeToday` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product2incomeToday], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product3incomeTotal", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product3incomeTotal` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product3incomeTotal], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product3incomeToday", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product3incomeToday` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product3incomeToday], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product4incomeTotal", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product4incomeTotal` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product4incomeTotal], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product4incomeToday", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product4incomeToday` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product4incomeToday], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product5incomeTotal", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product5incomeTotal` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product5incomeTotal], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product5incomeToday", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product5incomeToday` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product5incomeToday], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product6incomeTotal", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product6incomeTotal` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product6incomeTotal], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product6incomeToday", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product6incomeToday` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product6incomeToday], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product7incomeTotal", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product7incomeTotal` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product7incomeTotal], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product7incomeToday", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product7incomeToday` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product7incomeToday], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product8incomeTotal", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product8incomeTotal` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product8incomeTotal], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product8incomeToday", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product8incomeToday` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product8incomeToday], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product9incomeTotal", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product9incomeTotal` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product9incomeTotal], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product9incomeToday", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product9incomeToday` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product9incomeToday], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product10incomeTotal", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product10incomeTotal` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product10incomeTotal], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product10incomeToday", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product10incomeToday` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product10incomeToday], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product1", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product1` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product1], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product1type", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product1type` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product1type], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product1price", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product1price` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product1price], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product1count", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product1count` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product1count], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product1buy", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product1buy` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product1buy], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product2` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product2], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product2type", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product2type` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product2type], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product2price", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product2price` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product2price], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product2count", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product2count` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product2count], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product2buy", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product2buy` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product2buy], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product3` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product3], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product3type", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product3type` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product3type], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product3price", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product3price` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product3price], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product3count", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product3count` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product3count], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product3buy", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product3buy` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product3buy], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product4` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product4], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product4type", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product4type` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product4type], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product4price", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product4price` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product4price], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product4count", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product4count` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product4count], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product4buy", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product4buy` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product4buy], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product5` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product5], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product5type", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product5type` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product5type], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product5price", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product5price` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product5price], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product5count", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product5count` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product5count], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product5buy", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product5buy` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product5buy], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product6", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product6` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product6], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product6type", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product6type` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product6type], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product6price", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product6price` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product6price], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product6count", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product6count` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product6count], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product6buy", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product6buy` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product6buy], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product7", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product7` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product7], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product7type", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product7type` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product7type], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product7price", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product7price` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product7price], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product7count", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product7count` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product7count], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product7buy", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product7buy` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product7buy], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product8", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product8` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product8], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product8type", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product8type` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product8type], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product8price", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product8price` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product8price], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product8count", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product8count` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product8count], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product8buy", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product8buy` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product8buy], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product9", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product9` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product9], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product9type", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product9type` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product9type], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product9price", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product9price` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product9price], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product9count", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product9count` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product9count], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product9buy", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product9buy` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product9buy], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product10", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product10` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product10], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product10type", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product10type` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product10type], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product10price", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product10price` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product10price], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product10count", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product10count` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product10count], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}	
		if(strcmp(column, "Product10buy", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product10buy` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product10buy], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}		
		if(strcmp(column, "Product11Price", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product11Price` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product11Price], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product12Price", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product12Price` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product12Price], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product13Price", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product13Price` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product13Price], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product14Price", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product14Price` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product14Price], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product15Price", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product15Price` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product15Price], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product16Price", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product16Price` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product16Price], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product17Price", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product17Price` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product17Price], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product18Price", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product18Price` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product18Price], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product19Price", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product19Price` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product19Price], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product20Price", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product20Price` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product20Price], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product21Price", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product21Price` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product21Price], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product22Price", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product22Price` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product22Price], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product23Price", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product23Price` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product23Price], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product24Price", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product24Price` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product24Price], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product25Price", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product25Price` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product25Price], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product26Price", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product26Price` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product26Price], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product27Price", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product27Price` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product27Price], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product28Price", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product28Price` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product28Price], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product29Price", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product29Price` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product29Price], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Product30Price", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Product30Price` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Product30Price], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "BRadio1X", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `BRadio1X` = '%f' WHERE `ID` = '%d'", Businesses[bizid][BRadio1X], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "BRadio1Y", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `BRadio1Y` = '%f' WHERE `ID` = '%d'", Businesses[bizid][BRadio1Y], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "BRadio1Z", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `BRadio1Z` = '%f' WHERE `ID` = '%d'", Businesses[bizid][BRadio1Z], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "BRadio1Angle", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `BRadio1Angle` = '%f' WHERE `ID` = '%d'", Businesses[bizid][BRadio1Angle], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "BRadio1Vol", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `BRadio1Vol` = '%d' WHERE `ID` = '%d'", Businesses[bizid][BRadio1Vol], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "BRadio1Ch", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `BRadio1Ch` = '%d' WHERE `ID` = '%d'", Businesses[bizid][BRadio1Ch], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "BRadio1On", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `BRadio1On` = '%d' WHERE `ID` = '%d'", Businesses[bizid][BRadio1On], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "BRadio1Bought", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `BRadio1Bought` = '%d' WHERE `ID` = '%d'", Businesses[bizid][BRadio1Bought], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "BusinessName", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `BusinessName` = '%s' WHERE `ID` = '%d'", Businesses[bizid][BusinessName], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Owner", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Owner` = '%s' WHERE `ID` = '%d'", Businesses[bizid][Owner], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "EnterX", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `EnterX` = '%f' WHERE `ID` = '%d'", Businesses[bizid][EnterX], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "EnterY", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `EnterY` = '%f' WHERE `ID` = '%d'", Businesses[bizid][EnterY], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "EnterZ", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `EnterZ` = '%f' WHERE `ID` = '%d'", Businesses[bizid][EnterZ], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "EnterWorld", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `EnterWorld` = '%d' WHERE `ID` = '%d'", Businesses[bizid][EnterWorld], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "EnterInterior", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `EnterInterior` = '%d' WHERE `ID` = '%d'", Businesses[bizid][EnterInterior], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "EnterAngle", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `EnterAngle` = '%f' WHERE `ID` = '%d'", Businesses[bizid][EnterAngle], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "ExitX", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `ExitX` = '%f' WHERE `ID` = '%d'", Businesses[bizid][ExitX], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "ExitY", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `ExitY` = '%f' WHERE `ID` = '%d'", Businesses[bizid][ExitY], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "ExitZ", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `ExitZ` = '%f' WHERE `ID` = '%d'", Businesses[bizid][ExitZ], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "ExitInterior", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `ExitInterior` = '%d' WHERE `ID` = '%d'", Businesses[bizid][ExitInterior], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "ExitAngle", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `ExitAngle` = '%f' WHERE `ID` = '%d'", Businesses[bizid][ExitAngle], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Owned", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Owned` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Owned], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Enterable", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Enterable` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Enterable], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "BizPrice", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `BizPrice` = '%d' WHERE `ID` = '%d'", Businesses[bizid][BizPrice], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "EntranceCost", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `EntranceCost` = '%d' WHERE `ID` = '%d'", Businesses[bizid][EntranceCost], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Till", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Till` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Till], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Locked", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Locked` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Locked], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "BizType", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `BizType` = '%d' WHERE `ID` = '%d'", Businesses[bizid][BizType], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Products", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Products` = '%d' WHERE `ID` = '%d'", Businesses[bizid][Products], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "VehicleSpawned", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `VehicleSpawned` = '%d' WHERE `ID` = '%d'", Businesses[bizid][VehicleSpawned], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "VehicleCount", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `VehicleCount` = '%d' WHERE `ID` = '%d'", Businesses[bizid][VehicleCount], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "MaxVehicles", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `MaxVehicles` = '%d' WHERE `ID` = '%d'", Businesses[bizid][MaxVehicles], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "VehicleOrderCount", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `VehicleOrderCount` = '%d' WHERE `ID` = '%d'", Businesses[bizid][VehicleOrderCount], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "SalesJob", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `SalesJob` = '%d' WHERE `ID` = '%d'", Businesses[bizid][SalesJob], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "W9MM", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `W9MM` = '%d' WHERE `ID` = '%d'", Businesses[bizid][W9MM], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "W9MMIncomeTotal", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `W9MMIncomeTotal` = '%d' WHERE `ID` = '%d'", Businesses[bizid][mW9MMIncomeTotal], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "W9MMIncomeToday", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `W9MMIncomeToday` = '%d' WHERE `ID` = '%d'", Businesses[bizid][mW9MMIncomeToday], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "W9MMSil", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `W9MMSil` = '%d' WHERE `ID` = '%d'", Businesses[bizid][W9MMSil], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "W9MMSilIncomeTotal", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `W9MMSilIncomeTotal` = '%d' WHERE `ID` = '%d'", Businesses[bizid][mW9MMSilIncomeTotal], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "W9MMSilIncomeToday", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `W9MMSilIncomeToday` = '%d' WHERE `ID` = '%d'", Businesses[bizid][mW9MMSilIncomeToday], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WDesEagle", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `WDesEagle` = '%d' WHERE `ID` = '%d'", Businesses[bizid][WDesEagle], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WDesEagleIncomeTotal", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `WDesEagleIncomeTotal` = '%d' WHERE `ID` = '%d'", Businesses[bizid][mWDesEagleIncomeTotal], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WDesEagleIncomeToday", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `WDesEagleIncomeToday` = '%d' WHERE `ID` = '%d'", Businesses[bizid][mWDesEagleIncomeToday], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WMicroSMG", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `WMicroSMG` = '%d' WHERE `ID` = '%d'", Businesses[bizid][WMicroSMG], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WMicroSMGIncomeTotal", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `WMicroSMGIncomeTotal` = '%d' WHERE `ID` = '%d'", Businesses[bizid][mWMicroSMGIncomeTotal], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WMicroSMGIncomeToday", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `WMicroSMGIncomeToday` = '%d' WHERE `ID` = '%d'", Businesses[bizid][mWMicroSMGIncomeToday], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WMP5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `WMP5` = '%d' WHERE `ID` = '%d'", Businesses[bizid][WMP5], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WMP5IncomeTotal", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `WMP5IncomeTotal` = '%d' WHERE `ID` = '%d'", Businesses[bizid][mWMP5IncomeTotal], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WMP5IncomeToday", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `WMP5IncomeToday` = '%d' WHERE `ID` = '%d'", Businesses[bizid][mWMP5IncomeToday], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WTec9", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `WTec9` = '%d' WHERE `ID` = '%d'", Businesses[bizid][WTec9], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WTec9IncomeTotal", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `WTec9IncomeTotal` = '%d' WHERE `ID` = '%d'", Businesses[bizid][mWTec9IncomeTotal], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WTec9IncomeToday", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `WTec9IncomeToday` = '%d' WHERE `ID` = '%d'", Businesses[bizid][mWTec9IncomeToday], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WShotgun", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `WShotgun` = '%d' WHERE `ID` = '%d'", Businesses[bizid][WShotgun], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WShotgunIncomeTotal", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `WShotgunIncomeTotal` = '%d' WHERE `ID` = '%d'", Businesses[bizid][mWShotgunIncomeTotal], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WShotgunIncomeToday", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `WShotgunIncomeToday` = '%d' WHERE `ID` = '%d'", Businesses[bizid][mWShotgunIncomeToday], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WAK47", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `WAK47` = '%d' WHERE `ID` = '%d'", Businesses[bizid][WAK47], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WAK47IncomeTotal", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `WAK47IncomeTotal` = '%d' WHERE `ID` = '%d'", Businesses[bizid][mWAK47IncomeTotal], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WAK47IncomeToday", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `WAK47IncomeToday` = '%d' WHERE `ID` = '%d'", Businesses[bizid][mWAK47IncomeToday], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WM4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `WM4` = '%d' WHERE `ID` = '%d'", Businesses[bizid][WM4], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WM4IncomeTotal", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `WM4IncomeTotal` = '%d' WHERE `ID` = '%d'", Businesses[bizid][mWM4IncomeTotal], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WM4IncomeToday", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `WM4IncomeToday` = '%d' WHERE `ID` = '%d'", Businesses[bizid][mWM4IncomeToday], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WRifle", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `WRifle` = '%d' WHERE `ID` = '%d'", Businesses[bizid][WRifle], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WRifleIncomeTotal", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `WRifleIncomeTotal` = '%d' WHERE `ID` = '%d'", Businesses[bizid][mWRifleIncomeTotal], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WRifleIncomeToday", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `WRifleIncomeToday` = '%d' WHERE `ID` = '%d'", Businesses[bizid][mWRifleIncomeToday], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WSRifle", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `WSRifle` = '%d' WHERE `ID` = '%d'", Businesses[bizid][WSRifle], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WSRifleIncomeTotal", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `WSRifleIncomeTotal` = '%d' WHERE `ID` = '%d'", Businesses[bizid][mWSRifleIncomeTotal], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WSRifleIncomeToday", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `WSRifleIncomeToday` = '%d' WHERE `ID` = '%d'", Businesses[bizid][mWSRifleIncomeToday], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "W9MMAmmo", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `W9MMAmmo` = '%d' WHERE `ID` = '%d'", Businesses[bizid][W9MMAmmo], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "W9MMAmmoIncomeTotal", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `W9MMAmmoIncomeTotal` = '%d' WHERE `ID` = '%d'", Businesses[bizid][mW9MMAmmoIncomeTotal], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "W9MMAmmoIncomeToday", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `W9MMAmmoIncomeToday` = '%d' WHERE `ID` = '%d'", Businesses[bizid][mW9MMAmmoIncomeToday], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "W50AEAmmo", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `W50AEAmmo` = '%d' WHERE `ID` = '%d'", Businesses[bizid][W50AEAmmo], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "W50AEAmmoIncomeTotal", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `W50AEAmmoIncomeTotal` = '%d' WHERE `ID` = '%d'", Businesses[bizid][mW50AEAmmoIncomeTotal], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "W50AEAmmoIncomeToday", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `W50AEAmmoIncomeToday` = '%d' WHERE `ID` = '%d'", Businesses[bizid][mW50AEAmmoIncomeToday], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WBuckshot", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `WBuckshot` = '%d' WHERE `ID` = '%d'", Businesses[bizid][WBuckshot], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WBuckshotIncomeTotal", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `WBuckshotIncomeTotal` = '%d' WHERE `ID` = '%d'", Businesses[bizid][mWBuckshotIncomeTotal], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WBuckshotIncomeToday", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `WBuckshotIncomeToday` = '%d' WHERE `ID` = '%d'", Businesses[bizid][mWBuckshotIncomeToday], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "W762MMAmmo", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `W762MMAmmo` = '%d' WHERE `ID` = '%d'", Businesses[bizid][W762MMAmmo], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "W762MMAmmoIncomeTotal", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `W762MMAmmoIncomeTotal` = '%d' WHERE `ID` = '%d'", Businesses[bizid][mW762MMAmmoIncomeTotal], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "W762MMAmmoIncomeToday", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `W762MMAmmoIncomeToday` = '%d' WHERE `ID` = '%d'", Businesses[bizid][mW762MMAmmoIncomeToday], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "W127MMAmmo", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `W127MMAmmo` = '%d' WHERE `ID` = '%d'", Businesses[bizid][W127MMAmmo], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "W127MMAmmoIncomeTotal", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `W127MMAmmoIncomeTotal` = '%d' WHERE `ID` = '%d'", Businesses[bizid][mW127MMAmmoIncomeTotal], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "W127MMAmmoIncomeToday", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `W127MMAmmoIncomeToday` = '%d' WHERE `ID` = '%d'", Businesses[bizid][mW127MMAmmoIncomeToday], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Confiscated", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Confiscated` = '%d' WHERE `ID` = '%d'", Businesses[bizid][BConfiscated], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Placed", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Placed` = '%d' WHERE `ID` = '%d'", Businesses[bizid][BPlaced], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "IntSet", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `IntSet` = '%d' WHERE `ID` = '%d'", Businesses[bizid][BIntSet], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Interior", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Interior` = '%d' WHERE `ID` = '%d'", Businesses[bizid][BInterior], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Gov", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Gov` = '%d' WHERE `ID` = '%d'", Businesses[bizid][BGov], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Alarm", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_businesses` SET `Alarm` = '%d' WHERE `ID` = '%d'", Businesses[bizid][mAlarm], bizid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		format(string, sizeof(string), "[WARNING:] Unknown column: %s", column);
		ErrorLog(string);
	}
	return 1;
}

SaveVehData(carid, column[], otherid = -1)
{
	static string[512];
	
	strdel(string, 0, sizeof(string));
	
	if(strlen(column) != 0)
	{
		if(strcmp(column, "VehSaveTune", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles_customize` SET `Spoiler` = '%d' , `Hood` = '%d' , `Roof` = '%d' , `Sideskirt` = '%d' , `Lamps` = '%d' , `Nitro` = '%d' , `Exhaust` = '%d' , `Wheels` = '%d' , `Stereo` = '%d' ",
				gVehData[carid][mVehSpoiler], gVehData[carid][mVehHood], gVehData[carid][mVehRoof], gVehData[carid][mVehSideskirt], gVehData[carid][mVehLamps], gVehData[carid][mVehNitro], gVehData[carid][mVehExhaust],
				gVehData[carid][mVehWheels], gVehData[carid][mVehStereo]);
			format(string, sizeof(string),"%s, `Hydraulics` = '%d'  , `FrontBumper` = '%d'  , `RearBumper` = '%d'  , `VentLeft` = '%d'  , `VentRight` = '%d' WHERE `ID` = '%d' ",
				string, gVehData[carid][mVehHydraulics], gVehData[carid][mVehFrontBumper], gVehData[carid][mVehRearBumper], gVehData[carid][mVehVentLeft], gVehData[carid][mVehVentRight], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "VehSave3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `CarHealth` = '%f', `CarFuel` = '%f' WHERE `ID` = '%d'",
				gVehData[carid][CarHealth], gVehData[carid][CarFuel], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "VehSave2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `CarPanels` = '%d', `CarDoors` = '%d', `CarLights` = '%d', `CarTires` = '%d', `CarDamaged` = '%d' WHERE `ID` = '%d'",
				gVehData[carid][CarPanels], gVehData[carid][CarDoors], gVehData[carid][CarLights], gVehData[carid][CarTires], gVehData[carid][CarDamaged], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "VehSave1", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `BatteryCapacity` = '%f' , `BatteryMaxCapacity` = '%f' , `CarCounter` = '%d' , `EngineOn` = '%d' , `CarDamaged` = '%d' WHERE `ID` = '%d' ",
				gVehData[carid][BatteryCapacity], gVehData[carid][BatteryMaxCapacity], gVehData[carid][CarCounter], gVehData[carid][EngineOn], gVehData[carid][CarDamaged], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "VehSirenObjModel", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `VehSirenObjModel` = '%f' WHERE `ID` = '%d'", gVehData[carid][mVehSirenObjModel], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "VehIgnitionHacked", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `VehIgnitionHacked` = '%f' WHERE `ID` = '%d'", gVehData[carid][mVehIgnitionHacked], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "VehIgnitionDamaged", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `VehIgnitionDamaged` = '%f' WHERE `ID` = '%d'", gVehData[carid][mVehIgnitionDamaged], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "VehTransportSlot1", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `VehTransportSlot1` = '%f' WHERE `ID` = '%d'", gVehData[carid][mVehTransportSlot1], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "VehTransportSlot2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `VehTransportSlot2` = '%f' WHERE `ID` = '%d'", gVehData[carid][mVehTransportSlot2], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "VehTransportSlot3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `VehTransportSlot3` = '%f' WHERE `ID` = '%d'", gVehData[carid][mVehTransportSlot3], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "VehTransportSlot4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `VehTransportSlot4` = '%f' WHERE `ID` = '%d'", gVehData[carid][mVehTransportSlot4], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "BatteryCapacity", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `BatteryCapacity` = '%f' WHERE `ID` = '%d'", gVehData[carid][BatteryCapacity], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "BatteryMaxCapacity", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `BatteryMaxCapacity` = '%f' WHERE `ID` = '%d'", gVehData[carid][BatteryMaxCapacity], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "BatteryID", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `BatteryID` = '%d' WHERE `ID` = '%d'", gVehData[carid][BatteryID], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CustomObj7On", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_cars_cparts` SET `CustomObj7On` = '%d' WHERE `ID` = '%d'", gVehData[carid][CustomObj7On], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CustomObj6On", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_cars_cparts` SET `CustomObj6On` = '%d' WHERE `ID` = '%d'", gVehData[carid][CustomObj6On], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CustomObj5On", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_cars_cparts` SET `CustomObj5On` = '%d' WHERE `ID` = '%d'", gVehData[carid][CustomObj5On], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CustomObj4On", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_cars_cparts` SET `CustomObj4On` = '%d' WHERE `ID` = '%d'", gVehData[carid][CustomObj4On], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CustomObj3On", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_cars_cparts` SET `CustomObj3On` = '%d' WHERE `ID` = '%d'", gVehData[carid][CustomObj3On], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CustomObj2On", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_cars_cparts` SET `CustomObj2On` = '%d' WHERE `ID` = '%d'", gVehData[carid][CustomObj2On], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CustomObj1On", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_cars_cparts` SET `CustomObj1On` = '%d' WHERE `ID` = '%d'", gVehData[carid][CustomObj1On], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CustomObj1Model", true) == 0 )
		{
			format(string, sizeof(string), "UPDATE `samp_cars_cparts` SET `CustomObj1Model` = '%d' WHERE `ID` = '%d'", gVehData[carid][CustomObj1Model], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}		
		if(strcmp(column, "CustomObj1", true) == 0 && otherid == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_cars_cparts` SET `CustomObj1X` = '%f' WHERE `ID` = '%d'", gVehData[carid][CustomObj1][0], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CustomObj1", true) == 0 && otherid == 1)
		{
			format(string, sizeof(string), "UPDATE `samp_cars_cparts` SET `CustomObj1Y` = '%f' WHERE `ID` = '%d'", gVehData[carid][CustomObj1][1], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CustomObj1", true) == 0 && otherid == 2)
		{
			format(string, sizeof(string), "UPDATE `samp_cars_cparts` SET `CustomObj1Z` = '%f' WHERE `ID` = '%d'", gVehData[carid][CustomObj1][2], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CustomObj1", true) == 0 && otherid == 3)
		{
			format(string, sizeof(string), "UPDATE `samp_cars_cparts` SET `CustomObj1Xr` = '%f' WHERE `ID` = '%d'", gVehData[carid][CustomObj1][3], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CustomObj1", true) == 0 && otherid == 4)
		{
			format(string, sizeof(string), "UPDATE `samp_cars_cparts` SET `CustomObj1Yr` = '%f' WHERE `ID` = '%d'", gVehData[carid][CustomObj1][4], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CustomObj1", true) == 0 && otherid == 5)
		{
			format(string, sizeof(string), "UPDATE `samp_cars_cparts` SET `CustomObj1Zr` = '%f' WHERE `ID` = '%d'", gVehData[carid][CustomObj1][5], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CustomObj2Model", true) == 0 )
		{
			format(string, sizeof(string), "UPDATE `samp_cars_cparts` SET `CustomObj2Model` = '%d' WHERE `ID` = '%d'", gVehData[carid][CustomObj2Model], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}		
		if(strcmp(column, "CustomObj2", true) == 0 && otherid == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_cars_cparts` SET `CustomObj2X` = '%f' WHERE `ID` = '%d'", gVehData[carid][CustomObj2][0], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CustomObj2", true) == 0 && otherid == 1)
		{
			format(string, sizeof(string), "UPDATE `samp_cars_cparts` SET `CustomObj2Y` = '%f' WHERE `ID` = '%d'", gVehData[carid][CustomObj2][1], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CustomObj2", true) == 0 && otherid == 2)
		{
			format(string, sizeof(string), "UPDATE `samp_cars_cparts` SET `CustomObj2Z` = '%f' WHERE `ID` = '%d'", gVehData[carid][CustomObj2][2], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CustomObj2", true) == 0 && otherid == 3)
		{
			format(string, sizeof(string), "UPDATE `samp_cars_cparts` SET `CustomObj2Xr` = '%f' WHERE `ID` = '%d'", gVehData[carid][CustomObj2][3], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CustomObj2", true) == 0 && otherid == 4)
		{
			format(string, sizeof(string), "UPDATE `samp_cars_cparts` SET `CustomObj2Yr` = '%f' WHERE `ID` = '%d'", gVehData[carid][CustomObj2][4], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CustomObj2", true) == 0 && otherid == 5)
		{
			format(string, sizeof(string), "UPDATE `samp_cars_cparts` SET `CustomObj2Zr` = '%f' WHERE `ID` = '%d'", gVehData[carid][CustomObj2][5], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CustomObj3Model", true) == 0 )
		{
			format(string, sizeof(string), "UPDATE `samp_cars_cparts` SET `CustomObj3Model` = '%d' WHERE `ID` = '%d'", gVehData[carid][CustomObj3Model], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}		
		if(strcmp(column, "CustomObj3", true) == 0 && otherid == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_cars_cparts` SET `CustomObj3X` = '%f' WHERE `ID` = '%d'", gVehData[carid][CustomObj3][0], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CustomObj3", true) == 0 && otherid == 1)
		{
			format(string, sizeof(string), "UPDATE `samp_cars_cparts` SET `CustomObj3Y` = '%f' WHERE `ID` = '%d'", gVehData[carid][CustomObj3][1], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CustomObj3", true) == 0 && otherid == 2)
		{
			format(string, sizeof(string), "UPDATE `samp_cars_cparts` SET `CustomObj3Z` = '%f' WHERE `ID` = '%d'", gVehData[carid][CustomObj3][2], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CustomObj3", true) == 0 && otherid == 3)
		{
			format(string, sizeof(string), "UPDATE `samp_cars_cparts` SET `CustomObj3Xr` = '%f' WHERE `ID` = '%d'", gVehData[carid][CustomObj3][3], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CustomObj3", true) == 0 && otherid == 4)
		{
			format(string, sizeof(string), "UPDATE `samp_cars_cparts` SET `CustomObj3Yr` = '%f' WHERE `ID` = '%d'", gVehData[carid][CustomObj3][4], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CustomObj3", true) == 0 && otherid == 5)
		{
			format(string, sizeof(string), "UPDATE `samp_cars_cparts` SET `CustomObj3Zr` = '%f' WHERE `ID` = '%d'", gVehData[carid][CustomObj3][5], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CustomObj4Model", true) == 0 )
		{
			format(string, sizeof(string), "UPDATE `samp_cars_cparts` SET `CustomObj4Model` = '%d' WHERE `ID` = '%d'", gVehData[carid][CustomObj4Model], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}		
		if(strcmp(column, "CustomObj4", true) == 0 && otherid == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_cars_cparts` SET `CustomObj4X` = '%f' WHERE `ID` = '%d'", gVehData[carid][CustomObj4][0], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CustomObj4", true) == 0 && otherid == 1)
		{
			format(string, sizeof(string), "UPDATE `samp_cars_cparts` SET `CustomObj4Y` = '%f' WHERE `ID` = '%d'", gVehData[carid][CustomObj4][1], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CustomObj4", true) == 0 && otherid == 2)
		{
			format(string, sizeof(string), "UPDATE `samp_cars_cparts` SET `CustomObj4Z` = '%f' WHERE `ID` = '%d'", gVehData[carid][CustomObj4][2], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CustomObj4", true) == 0 && otherid == 3)
		{
			format(string, sizeof(string), "UPDATE `samp_cars_cparts` SET `CustomObj4Xr` = '%f' WHERE `ID` = '%d'", gVehData[carid][CustomObj4][3], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CustomObj4", true) == 0 && otherid == 4)
		{
			format(string, sizeof(string), "UPDATE `samp_cars_cparts` SET `CustomObj4Yr` = '%f' WHERE `ID` = '%d'", gVehData[carid][CustomObj4][4], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CustomObj4", true) == 0 && otherid == 5)
		{
			format(string, sizeof(string), "UPDATE `samp_cars_cparts` SET `CustomObj4Zr` = '%f' WHERE `ID` = '%d'", gVehData[carid][CustomObj4][5], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CustomObj7Model", true) == 0 )
		{
			format(string, sizeof(string), "UPDATE `samp_cars_cparts` SET `CustomObj7Model` = '%d' WHERE `ID` = '%d'", gVehData[carid][CustomObj7Model], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}		
		if(strcmp(column, "CustomObj6Model", true) == 0 )
		{
			format(string, sizeof(string), "UPDATE `samp_cars_cparts` SET `CustomObj6Model` = '%d' WHERE `ID` = '%d'", gVehData[carid][CustomObj6Model], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}		
		if(strcmp(column, "CustomObj5Model", true) == 0 )
		{
			format(string, sizeof(string), "UPDATE `samp_cars_cparts` SET `CustomObj5Model` = '%d' WHERE `ID` = '%d'", gVehData[carid][CustomObj5Model], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}		
		if(strcmp(column, "CustomObj7", true) == 0 && otherid == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_cars_cparts` SET `CustomObj7X` = '%f' WHERE `ID` = '%d'", gVehData[carid][CustomObj7][0], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CustomObj7", true) == 0 && otherid == 1)
		{
			format(string, sizeof(string), "UPDATE `samp_cars_cparts` SET `CustomObj7Y` = '%f' WHERE `ID` = '%d'", gVehData[carid][CustomObj7][1], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CustomObj7", true) == 0 && otherid == 2)
		{
			format(string, sizeof(string), "UPDATE `samp_cars_cparts` SET `CustomObj7Z` = '%f' WHERE `ID` = '%d'", gVehData[carid][CustomObj7][2], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CustomObj6", true) == 0 && otherid == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_cars_cparts` SET `CustomObj6X` = '%f' WHERE `ID` = '%d'", gVehData[carid][CustomObj6][0], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CustomObj6", true) == 0 && otherid == 1)
		{
			format(string, sizeof(string), "UPDATE `samp_cars_cparts` SET `CustomObj6Y` = '%f' WHERE `ID` = '%d'", gVehData[carid][CustomObj6][1], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CustomObj6", true) == 0 && otherid == 2)
		{
			format(string, sizeof(string), "UPDATE `samp_cars_cparts` SET `CustomObj6Z` = '%f' WHERE `ID` = '%d'", gVehData[carid][CustomObj6][2], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CustomObj5", true) == 0 && otherid == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_cars_cparts` SET `CustomObj5X` = '%f' WHERE `ID` = '%d'", gVehData[carid][CustomObj5][0], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CustomObj5", true) == 0 && otherid == 1)
		{
			format(string, sizeof(string), "UPDATE `samp_cars_cparts` SET `CustomObj5Y` = '%f' WHERE `ID` = '%d'", gVehData[carid][CustomObj5][1], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CustomObj5", true) == 0 && otherid == 2)
		{
			format(string, sizeof(string), "UPDATE `samp_cars_cparts` SET `CustomObj5Z` = '%f' WHERE `ID` = '%d'", gVehData[carid][CustomObj5][2], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CustomObj6", true) == 0 && otherid == 3)
		{
			format(string, sizeof(string), "UPDATE `samp_cars_cparts` SET `CustomObj6Xr` = '%f' WHERE `ID` = '%d'", gVehData[carid][CustomObj6][3], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CustomObj6", true) == 0 && otherid == 4)
		{
			format(string, sizeof(string), "UPDATE `samp_cars_cparts` SET `CustomObj6Yr` = '%f' WHERE `ID` = '%d'", gVehData[carid][CustomObj6][4], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CustomObj6", true) == 0 && otherid == 5)
		{
			format(string, sizeof(string), "UPDATE `samp_cars_cparts` SET `CustomObj6Zr` = '%f' WHERE `ID` = '%d'", gVehData[carid][CustomObj6][5], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CustomObj5", true) == 0 && otherid == 3)
		{
			format(string, sizeof(string), "UPDATE `samp_cars_cparts` SET `CustomObj5Xr` = '%f' WHERE `ID` = '%d'", gVehData[carid][CustomObj5][3], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CustomObj5", true) == 0 && otherid == 4)
		{
			format(string, sizeof(string), "UPDATE `samp_cars_cparts` SET `CustomObj5Yr` = '%f' WHERE `ID` = '%d'", gVehData[carid][CustomObj5][4], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CustomObj5", true) == 0 && otherid == 5)
		{
			format(string, sizeof(string), "UPDATE `samp_cars_cparts` SET `CustomObj5Zr` = '%f' WHERE `ID` = '%d'", gVehData[carid][CustomObj5][5], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "VehModel", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `VehModel` = '%d' WHERE `ID` = '%d'", gVehData[carid][mVehModel], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "VehPos", true, 6) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `VehX` = '%f', `VehY` = '%f' , `VehZ` = '%f' , `VehA` = '%f' WHERE `ID` = '%d'",
			gVehData[carid][mVehX], gVehData[carid][mVehY], gVehData[carid][mVehZ], gVehData[carid][mVehA], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "VehX", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `VehX` = '%f' WHERE `ID` = '%d'", gVehData[carid][mVehX], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "VehY", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `VehY` = '%f' WHERE `ID` = '%d'", gVehData[carid][mVehY], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "VehZ", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `VehZ` = '%f' WHERE `ID` = '%d'", gVehData[carid][mVehZ], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "VehA", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `VehA` = '%f' WHERE `ID` = '%d'", gVehData[carid][mVehA], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "VehColor1", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `VehColor1` = '%d' WHERE `ID` = '%d'", gVehData[carid][mVehColor1], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "VehColor2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `VehColor2` = '%d' WHERE `ID` = '%d'", gVehData[carid][mVehColor2], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "VehFaction", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `VehFaction` = '%d' WHERE `ID` = '%d'", gVehData[carid][mVehFaction], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "VehVinNo", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `VehVinNo` = '%d' WHERE `ID` = '%d'", gVehData[carid][mVehVinNo], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "VehType", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `VehType` = '%d' WHERE `ID` = '%d'", gVehData[carid][mVehType], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "VehOwned", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `VehOwned` = '%d' WHERE `ID` = '%d'", gVehData[carid][mVehOwned], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Owner", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Owner` = '%s' WHERE `ID` = '%d'", gVehData[carid][Owner], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Price", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Price` = '%d' WHERE `ID` = '%d'", gVehData[carid][Price], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Closed", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Closed` = '%d' WHERE `ID` = '%d'", gVehData[carid][Closed], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CarResetT", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `CarResetT` = '%d' WHERE `ID` = '%d'", gVehData[carid][CarResetT], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CarDamaged", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `CarDamaged` = '%d' WHERE `ID` = '%d'", gVehData[carid][CarDamaged], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CarRepairTimeLeft", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `CarRepairTimeLeft` = '%d' WHERE `ID` = '%d'", gVehData[carid][CarRepairTimeLeft], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "BusinessID", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `BusinessID` = '%d' WHERE `ID` = '%d'", gVehData[carid][BusinessID], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CarFuel", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `CarFuel` = '%f' WHERE `ID` = '%d'", gVehData[carid][CarFuel], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CarHealth", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `CarHealth` = '%f' WHERE `ID` = '%d'", gVehData[carid][CarHealth], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "ReadyToSell", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `ReadyToSell` = '%d' WHERE `ID` = '%d'", gVehData[carid][ReadyToSell], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CarCounter", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `CarCounter` = '%d' WHERE `ID` = '%d'", gVehData[carid][CarCounter], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Fuel", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Fuel` = '%d' WHERE `ID` = '%d'", gVehData[carid][Fuel], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CarPanels", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `CarPanels` = '%d' WHERE `ID` = '%d'", gVehData[carid][CarPanels], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CarDoors", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `CarDoors` = '%d' WHERE `ID` = '%d'", gVehData[carid][CarDoors], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CarLights", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `CarLights` = '%d' WHERE `ID` = '%d'", gVehData[carid][CarLights], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CarTires", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `CarTires` = '%d' WHERE `ID` = '%d'", gVehData[carid][CarTires], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "LastDriverWKey", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `LastDriverWKey` = '%d' WHERE `ID` = '%d'", gVehData[carid][LastDriverWKey], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CarSerial", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `CarSerial` = '%d' WHERE `ID` = '%d'", gVehData[carid][CarSerial], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "PaintStep", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `PaintStep` = '%d' WHERE `ID` = '%d'", gVehData[carid][PaintStep], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WheelStep", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `WheelStep` = '%d' WHERE `ID` = '%d'", gVehData[carid][WheelStep], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "EngineOn", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `EngineOn` = '%d' WHERE `ID` = '%d'", gVehData[carid][EngineOn], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "LightsOn", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `LightsOn` = '%d' WHERE `ID` = '%d'", gVehData[carid][LightsOn], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "BonnetUp", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `BonnetUp` = '%d' WHERE `ID` = '%d'", gVehData[carid][BonnetUp], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "BootUp", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `BootUp` = '%d' WHERE `ID` = '%d'", gVehData[carid][BootUp], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "RadioOn", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `RadioOn` = '%d' WHERE `ID` = '%d'", gVehData[carid][RadioOn], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Hook", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Hook` = '%d' WHERE `ID` = '%d'", gVehData[carid][Hook], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Alarm", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Alarm` = '%d' WHERE `ID` = '%d'", gVehData[carid][Alarm], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "GasStep", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `GasStep` = '%d' WHERE `ID` = '%d'", gVehData[carid][GasStep], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "TankerResourceType", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `TankerResourceType` = '%d' WHERE `ID` = '%d'", gVehData[carid][TankerResourceType], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "TankerResourceValue", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `TankerResourceValue` = '%d' WHERE `ID` = '%d'", gVehData[carid][TankerResourceValue], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "VehInt", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `VehInt` = '%d' WHERE `ID` = '%d'", gVehData[carid][mVehInt], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "VehVW", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `VehVW` = '%d' WHERE `ID` = '%d'", gVehData[carid][mVehVW], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Confiscated", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Confiscated` = '%d' WHERE `ID` = '%d'", gVehData[carid][VConfiscated], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "PoliceComputer", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `PoliceComputer` = '%d' WHERE `ID` = '%d'", gVehData[carid][VPoliceComputer], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CBRadio", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `CBRadio` = '%d' WHERE `ID` = '%d'", gVehData[carid][VCBRadio], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CBRadioChanel", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `CBRadioChanel` = '%d' WHERE `ID` = '%d'", gVehData[carid][VCBRadioChanel], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "CBRadioStatus", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `CBRadioStatus` = '%d' WHERE `ID` = '%d'", gVehData[carid][VCBRadioStatus], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item1a", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item1` = '%d' , `Item1type` = '%d' , `Item1param` = '%d' , `Item1param2` = '%d' , `Item1param3` = '%d' , `Item1param4` = '%d' , `Item1param5` = '%s' , `Item1param6` = '%d' WHERE `ID` = '%d' ",
				gVehData[carid][VItem1], gVehData[carid][VItem1type], gVehData[carid][VItem1param], gVehData[carid][VItem1param2], gVehData[carid][VItem1param3], gVehData[carid][VItem1param4], gVehData[carid][VItem1param5], gVehData[carid][VItem1param6], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item2a", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item2` = '%d' , `Item2type` = '%d' , `Item2param` = '%d' , `Item2param2` = '%d' , `Item2param3` = '%d' , `Item2param4` = '%d' , `Item2param5` = '%s' , `Item2param6` = '%d' WHERE `ID` = '%d' ",
				gVehData[carid][VItem2], gVehData[carid][VItem2type], gVehData[carid][VItem2param], gVehData[carid][VItem2param2], gVehData[carid][VItem2param3], gVehData[carid][VItem2param4], gVehData[carid][VItem2param5], gVehData[carid][VItem2param6], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item3a", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item3` = '%d' , `Item3type` = '%d' , `Item3param` = '%d' , `Item3param2` = '%d' , `Item3param3` = '%d' , `Item3param4` = '%d' , `Item3param5` = '%s' , `Item3param6` = '%d' WHERE `ID` = '%d' ",
				gVehData[carid][VItem3], gVehData[carid][VItem3type], gVehData[carid][VItem3param], gVehData[carid][VItem3param2], gVehData[carid][VItem3param3], gVehData[carid][VItem3param4], gVehData[carid][VItem3param5], gVehData[carid][VItem3param6], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item4a", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item4` = '%d' , `Item4type` = '%d' , `Item4param` = '%d' , `Item4param2` = '%d' , `Item4param3` = '%d' , `Item4param4` = '%d' , `Item4param5` = '%s' , `Item4param6` = '%d' WHERE `ID` = '%d' ",
				gVehData[carid][VItem4], gVehData[carid][VItem4type], gVehData[carid][VItem4param], gVehData[carid][VItem4param2], gVehData[carid][VItem4param3], gVehData[carid][VItem4param4], gVehData[carid][VItem4param5], gVehData[carid][VItem4param6], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item5a", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item5` = '%d' , `Item5type` = '%d' , `Item5param` = '%d' , `Item5param2` = '%d' , `Item5param3` = '%d' , `Item5param4` = '%d' , `Item5param5` = '%s' , `Item5param6` = '%d' WHERE `ID` = '%d' ",
				gVehData[carid][VItem5], gVehData[carid][VItem5type], gVehData[carid][VItem5param], gVehData[carid][VItem5param2], gVehData[carid][VItem5param3], gVehData[carid][VItem5param4], gVehData[carid][VItem5param5], gVehData[carid][VItem5param6], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item6a", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item6` = '%d' , `Item6type` = '%d' , `Item6param` = '%d' , `Item6param2` = '%d' , `Item6param3` = '%d' , `Item6param4` = '%d' , `Item6param5` = '%s' , `Item6param6` = '%d' WHERE `ID` = '%d' ",
				gVehData[carid][VItem6], gVehData[carid][VItem6type], gVehData[carid][VItem6param], gVehData[carid][VItem6param2], gVehData[carid][VItem6param3], gVehData[carid][VItem6param4], gVehData[carid][VItem6param5], gVehData[carid][VItem6param6], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item7a", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item7` = '%d' , `Item7type` = '%d' , `Item7param` = '%d' , `Item7param2` = '%d' , `Item7param3` = '%d' , `Item7param4` = '%d' , `Item7param5` = '%s' , `Item7param6` = '%d' WHERE `ID` = '%d' ",
				gVehData[carid][VItem7], gVehData[carid][VItem7type], gVehData[carid][VItem7param], gVehData[carid][VItem7param2], gVehData[carid][VItem7param3], gVehData[carid][VItem7param4], gVehData[carid][VItem7param5], gVehData[carid][VItem7param6], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item8a", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item8` = '%d' , `Item8type` = '%d' , `Item8param` = '%d' , `Item8param2` = '%d' , `Item8param3` = '%d' , `Item8param4` = '%d' , `Item8param5` = '%s' , `Item8param6` = '%d' WHERE `ID` = '%d' ",
				gVehData[carid][VItem8], gVehData[carid][VItem8type], gVehData[carid][VItem8param], gVehData[carid][VItem8param2], gVehData[carid][VItem8param3], gVehData[carid][VItem8param4], gVehData[carid][VItem8param5], gVehData[carid][VItem8param6], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item9a", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item9` = '%d' , `Item9type` = '%d' , `Item9param` = '%d' , `Item9param2` = '%d' , `Item9param3` = '%d' , `Item9param4` = '%d' , `Item9param5` = '%s' , `Item9param6` = '%d' WHERE `ID` = '%d' ",
				gVehData[carid][VItem9], gVehData[carid][VItem9type], gVehData[carid][VItem9param], gVehData[carid][VItem9param2], gVehData[carid][VItem9param3], gVehData[carid][VItem9param4], gVehData[carid][VItem9param5], gVehData[carid][VItem9param6], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item10a", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item10` = '%d' , `Item10type` = '%d' , `Item10param` = '%d' , `Item10param2` = '%d' , `Item10param3` = '%d' , `Item10param4` = '%d' , `Item10param5` = '%s' , `Item10param6` = '%d' WHERE `ID` = '%d' ",
				gVehData[carid][VItem10], gVehData[carid][VItem10type], gVehData[carid][VItem10param], gVehData[carid][VItem10param2], gVehData[carid][VItem10param3], gVehData[carid][VItem10param4], gVehData[carid][VItem10param5], gVehData[carid][VItem10param6], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item11a", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item11` = '%d' , `Item11type` = '%d' , `Item11param` = '%d' , `Item11param2` = '%d' , `Item11param3` = '%d' , `Item11param4` = '%d' , `Item11param5` = '%s' , `Item11param6` = '%d' WHERE `ID` = '%d' ",
				gVehData[carid][VItem11], gVehData[carid][VItem11type], gVehData[carid][VItem11param], gVehData[carid][VItem11param2], gVehData[carid][VItem11param3], gVehData[carid][VItem11param4], gVehData[carid][VItem11param5], gVehData[carid][VItem11param6], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item12a", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item12` = '%d' , `Item12type` = '%d' , `Item12param` = '%d' , `Item12param2` = '%d' , `Item12param3` = '%d' , `Item12param4` = '%d' , `Item12param5` = '%s' , `Item12param6` = '%d' WHERE `ID` = '%d' ",
				gVehData[carid][VItem12], gVehData[carid][VItem12type], gVehData[carid][VItem12param], gVehData[carid][VItem12param2], gVehData[carid][VItem12param3], gVehData[carid][VItem12param4], gVehData[carid][VItem12param5], gVehData[carid][VItem12param6], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item13a", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item13` = '%d' , `Item13type` = '%d' , `Item13param` = '%d' , `Item13param2` = '%d' , `Item13param3` = '%d' , `Item13param4` = '%d' , `Item13param5` = '%s' , `Item13param6` = '%d' WHERE `ID` = '%d' ",
				gVehData[carid][VItem13], gVehData[carid][VItem13type], gVehData[carid][VItem13param], gVehData[carid][VItem13param2], gVehData[carid][VItem13param3], gVehData[carid][VItem13param4], gVehData[carid][VItem13param5], gVehData[carid][VItem13param6], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item14a", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item14` = '%d' , `Item14type` = '%d' , `Item14param` = '%d' , `Item14param2` = '%d' , `Item14param3` = '%d' , `Item14param4` = '%d' , `Item14param5` = '%s' , `Item14param6` = '%d' WHERE `ID` = '%d' ",
				gVehData[carid][VItem14], gVehData[carid][VItem14type], gVehData[carid][VItem14param], gVehData[carid][VItem14param2], gVehData[carid][VItem14param3], gVehData[carid][VItem14param4], gVehData[carid][VItem14param5], gVehData[carid][VItem14param6], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item15a", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item15` = '%d' , `Item15type` = '%d' , `Item15param` = '%d' , `Item15param2` = '%d' , `Item15param3` = '%d' , `Item15param4` = '%d' , `Item15param5` = '%s' , `Item15param6` = '%d' WHERE `ID` = '%d' ",
				gVehData[carid][VItem15], gVehData[carid][VItem15type], gVehData[carid][VItem15param], gVehData[carid][VItem15param2], gVehData[carid][VItem15param3], gVehData[carid][VItem15param4], gVehData[carid][VItem15param5], gVehData[carid][VItem15param6], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item1", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item1` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem1], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item2` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem2], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item3` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem3], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item4` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem4], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item5` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem5], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item6", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item6` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem6], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item7", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item7` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem7], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item8", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item8` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem8], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item9", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item9` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem9], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item10", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item10` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem10], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item11", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item11` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem11], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item12", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item12` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem12], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item13", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item13` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem13], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item14", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item14` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem14], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item15", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item15` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem15], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item1type", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item1type` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem1type], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item2type", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item2type` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem2type], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item3type", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item3type` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem3type], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item4type", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item4type` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem4type], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item5type", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item5type` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem5type], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item6type", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item6type` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem6type], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item7type", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item7type` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem7type], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item8type", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item8type` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem8type], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item9type", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item9type` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem9type], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item10type", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item10type` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem10type], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item11type", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item11type` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem11type], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item12type", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item12type` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem12type], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item13type", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item13type` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem13type], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item14type", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item14type` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem14type], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item15type", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item15type` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem15type], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item1param", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item1param` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem1param], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item2param", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item2param` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem2param], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item3param", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item3param` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem3param], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item4param", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item4param` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem4param], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item5param", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item5param` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem5param], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item6param", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item6param` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem6param], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item7param", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item7param` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem7param], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item8param", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item8param` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem8param], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item9param", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item9param` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem9param], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item10param", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item10param` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem10param], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item11param", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item11param` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem11param], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item12param", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item12param` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem12param], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item13param", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item13param` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem13param], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item14param", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item14param` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem14param], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item15param", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item15param` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem15param], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item1param2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item1param2` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem1param2], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item2param2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item2param2` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem2param2], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item3param2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item3param2` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem3param2], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item4param2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item4param2` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem4param2], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item5param2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item5param2` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem5param2], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item6param2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item6param2` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem6param2], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item7param2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item7param2` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem7param2], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item8param2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item8param2` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem8param2], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item9param2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item9param2` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem9param2], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item10param2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item10param2` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem10param2], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item11param2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item11param2` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem11param2], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item12param2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item12param2` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem12param2], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item13param2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item13param2` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem13param2], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item14param2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item14param2` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem14param2], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item15param2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item15param2` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem15param2], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item1param3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item1param3` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem1param3], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item2param3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item2param3` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem2param3], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item3param3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item3param3` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem3param3], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item4param3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item4param3` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem4param3], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item5param3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item5param3` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem5param3], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item6param3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item6param3` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem6param3], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item7param3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item7param3` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem7param3], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item8param3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item8param3` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem8param3], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item9param3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item9param3` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem9param3], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item10param3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item10param3` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem10param3], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item11param3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item11param3` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem11param3], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item12param3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item12param3` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem12param3], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item13param3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item13param3` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem13param3], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item14param3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item14param3` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem14param3], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item15param3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item15param3` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem15param3], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item1param4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item1param4` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem1param4], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item2param4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item2param4` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem2param4], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item3param4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item3param4` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem3param4], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item4param4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item4param4` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem4param4], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item5param4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item5param4` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem5param4], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item6param4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item6param4` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem6param4], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item7param4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item7param4` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem7param4], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item8param4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item8param4` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem8param4], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item9param4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item9param4` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem9param4], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item10param4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item10param4` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem10param4], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item11param4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item11param4` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem11param4], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item12param4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item12param4` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem12param4], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item13param4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item13param4` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem13param4], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item14param4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item14param4` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem14param4], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item15param4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item15param4` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem15param4], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item1param5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item1param5` = '%s' WHERE `ID` = '%d'", gVehData[carid][VItem1param5], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item2param5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item2param5` = '%s' WHERE `ID` = '%d'", gVehData[carid][VItem2param5], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item3param5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item3param5` = '%s' WHERE `ID` = '%d'", gVehData[carid][VItem3param5], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item4param5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item4param5` = '%s' WHERE `ID` = '%d'", gVehData[carid][VItem4param5], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item5param5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item5param5` = '%s' WHERE `ID` = '%d'", gVehData[carid][VItem5param5], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item6param5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item6param5` = '%s' WHERE `ID` = '%d'", gVehData[carid][VItem6param5], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item7param5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item7param5` = '%s' WHERE `ID` = '%d'", gVehData[carid][VItem7param5], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item8param5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item8param5` = '%s' WHERE `ID` = '%d'", gVehData[carid][VItem8param5], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item9param5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item9param5` = '%s' WHERE `ID` = '%d'", gVehData[carid][VItem9param5], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item10param5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item10param5` = '%s' WHERE `ID` = '%d'", gVehData[carid][VItem10param5], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item11param5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item11param5` = '%s' WHERE `ID` = '%d'", gVehData[carid][VItem11param5], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item12param5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item12param5` = '%s' WHERE `ID` = '%d'", gVehData[carid][VItem12param5], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item13param5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item13param5` = '%s' WHERE `ID` = '%d'", gVehData[carid][VItem13param5], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item14param5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item14param5` = '%s' WHERE `ID` = '%d'", gVehData[carid][VItem14param5], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item15param5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item15param5` = '%s' WHERE `ID` = '%d'", gVehData[carid][VItem15param5], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item1param6", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item1param6` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem1param6], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item2param6", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item2param6` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem2param6], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item3param6", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item3param6` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem3param6], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item4param6", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item4param6` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem4param6], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item5param6", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item5param6` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem5param6], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item6param6", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item6param6` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem6param6], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item7param6", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item7param6` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem7param6], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item8param6", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item8param6` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem8param6], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item9param6", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item9param6` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem9param6], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item10param6", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item10param6` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem10param6], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item11param6", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item11param6` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem11param6], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item12param6", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item12param6` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem12param6], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item13param6", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item13param6` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem13param6], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item14param6", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item14param6` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem14param6], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Item15param6", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_vehicles` SET `Item15param6` = '%d' WHERE `ID` = '%d'", gVehData[carid][VItem15param6], carid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		format(string, sizeof(string), "[WARNING:] Unknown column: %s", column);
		ErrorLog(string);
	}
	return 1;
}

SaveFuleStationData(gasid, column[])
{
	new string[128];
	if(strlen(column) != 0)
	{
		if(strcmp(column, "BusinessID", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_gas_stations` SET `BusinessID` = '%d' WHERE `ID` = '%d'", GasStations[gasid][BusinessID], gasid);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "PetrolResourceValue", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_gas_stations` SET `PetrolResourceValue` = '%f' WHERE `ID` = '%d'", GasStations[gasid][PetrolResourceValue], gasid);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "OilResourceValue", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_gas_stations` SET `OilResourceValue` = '%f' WHERE `ID` = '%d'", GasStations[gasid][OilResourceValue], gasid);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "GasResourceValue", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_gas_stations` SET `GasResourceValue` = '%f' WHERE `ID` = '%d'", GasStations[gasid][GasResourceValue], gasid);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "MaxPetrolResourceValue", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_gas_stations` SET `MaxPetrolResourceValue` = '%f' WHERE `ID` = '%d'", GasStations[gasid][MaxPetrolResourceValue], gasid);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "MaxOilResourceValue", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_gas_stations` SET `MaxOilResourceValue` = '%f' WHERE `ID` = '%d'", GasStations[gasid][MaxOilResourceValue], gasid);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "MaxGasResourceValue", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_gas_stations` SET `MaxGasResourceValue` = '%f' WHERE `ID` = '%d'", GasStations[gasid][MaxGasResourceValue], gasid);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "RefuelPetrolResources", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_gas_stations` SET `RefuelPetrolResources` = '%d' WHERE `ID` = '%d'", GasStations[gasid][RefuelPetrolResources], gasid);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "RefuelOilResources", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_gas_stations` SET `RefuelOilResources` = '%d' WHERE `ID` = '%d'", GasStations[gasid][RefuelOilResources], gasid);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "RefuelGasResources", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_gas_stations` SET `RefuelGasResources` = '%d' WHERE `ID` = '%d'", GasStations[gasid][RefuelGasResources], gasid);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "PetrolPrice", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_gas_stations` SET `PetrolPrice` = '%d' WHERE `ID` = '%d'", GasStations[gasid][PetrolPrice], gasid);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "OilPrice", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_gas_stations` SET `OilPrice` = '%d' WHERE `ID` = '%d'", GasStations[gasid][OilPrice], gasid);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "GasPrice", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_gas_stations` SET `GasPrice` = '%d' WHERE `ID` = '%d'", GasStations[gasid][GasPrice], gasid);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "GSPosX", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_gas_stations` SET `GSPosX` = '%f' WHERE `ID` = '%d'", GasStations[gasid][GSposX], gasid);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "GSPosY", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_gas_stations` SET `GSPosY` = '%f' WHERE `ID` = '%d'", GasStations[gasid][GSposY], gasid);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "GSPosZ", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_gas_stations` SET `GSPosZ` = '%f' WHERE `ID` = '%d'", GasStations[gasid][GSposZ], gasid);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Pos3dTextX", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_gas_stations` SET `Pos3dTextX` = '%f' WHERE `ID` = '%d'", GasStations[gasid][Pos3dTextX], gasid);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Pos3dTextY", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_gas_stations` SET `Pos3dTextY` = '%f' WHERE `ID` = '%d'", GasStations[gasid][Pos3dTextY], gasid);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Pos3dTextZ", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_gas_stations` SET `Pos3dTextZ` = '%f' WHERE `ID` = '%d'", GasStations[gasid][Pos3dTextZ], gasid);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Pos3dTextX2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_gas_stations` SET `Pos3dTextX2` = '%f' WHERE `ID` = '%d'", GasStations[gasid][Pos3dTextX2], gasid);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Pos3dTextY2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_gas_stations` SET `Pos3dTextY2` = '%f' WHERE `ID` = '%d'", GasStations[gasid][Pos3dTextY2], gasid);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Pos3dTextZ2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_gas_stations` SET `Pos3dTextZ2` = '%f' WHERE `ID` = '%d'", GasStations[gasid][Pos3dTextZ2], gasid);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Pos3dTextX3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_gas_stations` SET `Pos3dTextX3` = '%f' WHERE `ID` = '%d'", GasStations[gasid][Pos3dTextX3], gasid);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Pos3dTextY3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_gas_stations` SET `Pos3dTextY3` = '%f' WHERE `ID` = '%d'", GasStations[gasid][Pos3dTextY3], gasid);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Pos3dTextZ3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_gas_stations` SET `Pos3dTextZ3` = '%f' WHERE `ID` = '%d'", GasStations[gasid][Pos3dTextZ3], gasid);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Pos3dTextX4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_gas_stations` SET `Pos3dTextX4` = '%f' WHERE `ID` = '%d'", GasStations[gasid][Pos3dTextX4], gasid);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Pos3dTextY4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_gas_stations` SET `Pos3dTextY4` = '%f' WHERE `ID` = '%d'", GasStations[gasid][Pos3dTextY4], gasid);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Pos3dTextZ4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_gas_stations` SET `Pos3dTextZ4` = '%f' WHERE `ID` = '%d'", GasStations[gasid][Pos3dTextZ4], gasid);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
	}
	format(string, sizeof(string), "[WARNING:] Unknown column: %s", column);
	ErrorLog(string);
	return 1;
}

stock SaveStatsData(desc[], plname[], price, businessid, param1=0, param2=0, param3=0, param4=0)
{
	new string[256];
	format(string, sizeof(string), "INSERT INTO `samp_stats` (`description`, `playerName`, `price`, `businessid`, `param1`, `param2`, `param3`, `param4`) VALUES ('%s' , '%s' , '%d', '%d' , '%d' , '%d' , '%d' , '%d')", 
					desc, plname, price, businessid, param1, param2, param3, param4);
	mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
}

stock SaveWFactoryData(column[])
{
	new string[256];
	if(strlen(column) != 0)
	{
		if(strcmp(column, "WFactoryCPDocsX", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryCPDocsX` = '%f' ", WFactoryLegal[WFactoryCPDocsX]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryCPDocsY", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryCPDocsY` = '%f' ", WFactoryLegal[WFactoryCPDocsY]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryCPDocsZ", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryCPDocsZ` = '%f' ", WFactoryLegal[WFactoryCPDocsZ]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryBuildingID", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryBuildingID` = '%d'", WFactoryLegal[WFactoryBuildingID]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryReward", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryReward` = '%d'", WFactoryLegal[WFactoryReward]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryCPPartTakeWV", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryCPPartTakeWV` = '%d'", WFactoryLegal[WFactoryCPPartTakeWV]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryCPPartTakeInt", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryCPPartTakeInt` = '%d'", WFactoryLegal[WFactoryCPPartTakeInt]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryCPPartTakeX", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryCPPartTakeX` = '%f'", WFactoryLegal[WFactoryCPPartTakeX]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryCPPartTakeY", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryCPPartTakeY` = '%f'", WFactoryLegal[WFactoryCPPartTakeY]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryCPPartTakeZ", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryCPPartTakeZ` = '%f'", WFactoryLegal[WFactoryCPPartTakeZ]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryCPPartSetup1X", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryCPPartSetup1X` = '%f'", WFactoryLegal[WFactoryCPPartSetup1X]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryCPPartSetup1Y", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryCPPartSetup1Y` = '%f'", WFactoryLegal[WFactoryCPPartSetup1Y]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryCPPartSetup1Z", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryCPPartSetup1Z` = '%f'", WFactoryLegal[WFactoryCPPartSetup1Z]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryCPPartSetup2X", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryCPPartSetup2X` = '%f'", WFactoryLegal[WFactoryCPPartSetup2X]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryCPPartSetup2Y", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryCPPartSetup2Y` = '%f'", WFactoryLegal[WFactoryCPPartSetup2Y]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryCPPartSetup2Z", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryCPPartSetup2Z` = '%f'", WFactoryLegal[WFactoryCPPartSetup2Z]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryCPPartSetup3X", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryCPPartSetup3X` = '%f'", WFactoryLegal[WFactoryCPPartSetup3X]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryCPPartSetup3Y", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryCPPartSetup3Y` = '%f'", WFactoryLegal[WFactoryCPPartSetup3Y]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryCPPartSetup3Z", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryCPPartSetup3Z` = '%f'", WFactoryLegal[WFactoryCPPartSetup3Z]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryCPPartSetup4X", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryCPPartSetup4X` = '%f'", WFactoryLegal[WFactoryCPPartSetup4X]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryCPPartSetup4Y", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryCPPartSetup4Y` = '%f'", WFactoryLegal[WFactoryCPPartSetup4Y]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryCPPartSetup4Z", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryCPPartSetup4Z` = '%f'", WFactoryLegal[WFactoryCPPartSetup4Z]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryCPPartSetup5X", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryCPPartSetup5X` = '%f'", WFactoryLegal[WFactoryCPPartSetup5X]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryCPPartSetup5Y", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryCPPartSetup5Y` = '%f'", WFactoryLegal[WFactoryCPPartSetup5Y]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryCPPartSetup5Z", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryCPPartSetup5Z` = '%f'", WFactoryLegal[WFactoryCPPartSetup5Z]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryCPPartSetup6X", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryCPPartSetup6X` = '%f'", WFactoryLegal[WFactoryCPPartSetup6X]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryCPPartSetup6Y", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryCPPartSetup6Y` = '%f'", WFactoryLegal[WFactoryCPPartSetup6Y]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryCPPartSetup6Z", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryCPPartSetup6Z` = '%f'", WFactoryLegal[WFactoryCPPartSetup6Z]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryCPAmmoSetup1X", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryCPAmmoSetup1X` = '%f'", WFactoryLegal[WFactoryCPAmmoSetup1X]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryCPAmmoSetup1Y", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryCPAmmoSetup1Y` = '%f'", WFactoryLegal[WFactoryCPAmmoSetup1Y]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryCPAmmoSetup1Z", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryCPAmmoSetup1Z` = '%f'", WFactoryLegal[WFactoryCPAmmoSetup1Z]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryCPAmmoSetup2X", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryCPAmmoSetup2X` = '%f'", WFactoryLegal[WFactoryCPAmmoSetup2X]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryCPAmmoSetup2Y", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryCPAmmoSetup2Y` = '%f'", WFactoryLegal[WFactoryCPAmmoSetup2Y]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryCPAmmoSetup2Z", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryCPAmmoSetup2Z` = '%f'", WFactoryLegal[WFactoryCPAmmoSetup2Z]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryCPAmmoSetup3X", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryCPAmmoSetup3X` = '%f'", WFactoryLegal[WFactoryCPAmmoSetup3X]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryCPAmmoSetup3Y", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryCPAmmoSetup3Y` = '%f'", WFactoryLegal[WFactoryCPAmmoSetup3Y]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryCPAmmoSetup3Z", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryCPAmmoSetup3Z` = '%f'", WFactoryLegal[WFactoryCPAmmoSetup3Z]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryCPAmmoSetup4X", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryCPAmmoSetup4X` = '%f'", WFactoryLegal[WFactoryCPAmmoSetup4X]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryCPAmmoSetup4Y", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryCPAmmoSetup4Y` = '%f'", WFactoryLegal[WFactoryCPAmmoSetup4Y]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryCPAmmoSetup4Z", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryCPAmmoSetup4Z` = '%f'", WFactoryLegal[WFactoryCPAmmoSetup4Z]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryCPAmmoSetup5X", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryCPAmmoSetup5X` = '%f'", WFactoryLegal[WFactoryCPAmmoSetup5X]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryCPAmmoSetup5Y", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryCPAmmoSetup5Y` = '%f'", WFactoryLegal[WFactoryCPAmmoSetup5Y]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryCPAmmoSetup5Z", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryCPAmmoSetup5Z` = '%f'", WFactoryLegal[WFactoryCPAmmoSetup5Z]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryCPAmmoSetup6X", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryCPAmmoSetup6X` = '%f'", WFactoryLegal[WFactoryCPAmmoSetup6X]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryCPAmmoSetup6Y", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryCPAmmoSetup6Y` = '%f'", WFactoryLegal[WFactoryCPAmmoSetup6Y]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryCPAmmoSetup6Z", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryCPAmmoSetup6Z` = '%f'", WFactoryLegal[WFactoryCPAmmoSetup6Z]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryCPDocsX", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryCPDocsX` = '%f'", WFactoryLegal[WFactoryCPDocsX]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryCPDocsY", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryCPDocsY` = '%f'", WFactoryLegal[WFactoryCPDocsY]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryCPDocsZ", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryCPDocsZ` = '%f'", WFactoryLegal[WFactoryCPDocsZ]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactory9MM", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactory9MM` = '%d'", WFactoryLegalLight[WFactory9MM]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactory9MMO", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactory9MMO` = '%d'", WFactoryLegalLight[WFactory9MMO]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactory9MMSil", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactory9MMSil` = '%d'", WFactoryLegalLight[WFactory9MMSil]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactory9MMSilO", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactory9MMSilO` = '%d'", WFactoryLegalLight[WFactory9MMSilO]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryDesEagle", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryDesEagle` = '%d'", WFactoryLegalLight[WFactoryDesEagle]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryDesEagleO", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryDesEagleO` = '%d'", WFactoryLegalLight[WFactoryDesEagleO]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryMicroSMG", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryMicroSMG` = '%d'", WFactoryLegalLight[WFactoryMicroSMG]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryMicroSMGO", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryMicroSMGO` = '%d'", WFactoryLegalLight[WFactoryMicroSMGO]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryMP5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryMP5` = '%d'", WFactoryLegalLight[WFactoryMP5]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryMP5O", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryMP5O` = '%d'", WFactoryLegalLight[WFactoryMP5O]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryTec9", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryTec9` = '%d'", WFactoryLegalLight[WFactoryTec9]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryTec9O", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryTec9O` = '%d'", WFactoryLegalLight[WFactoryTec9O]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryShotgun", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryShotgun` = '%d'", WFactoryLegalHeavy[WFactoryShotgun]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryShotgunO", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryShotgunO` = '%d'", WFactoryLegalHeavy[WFactoryShotgunO]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryAK47", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryAK47` = '%d'", WFactoryLegalHeavy[WFactoryAK47]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryAK47O", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryAK47O` = '%d'", WFactoryLegalHeavy[WFactoryAK47O]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryM4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryM4` = '%d'", WFactoryLegalHeavy[WFactoryM4]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryM4O", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryM4O` = '%d'", WFactoryLegalHeavy[WFactoryM4O]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryRifle", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryRifle` = '%d'", WFactoryLegalHeavy[WFactoryRifle]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryRifleO", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryRifleO` = '%d'", WFactoryLegalHeavy[WFactoryRifleO]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactorySRifle", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactorySRifle` = '%d'", WFactoryLegalHeavy[WFactorySRifle]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactorySRifleO", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactorySRifleO` = '%d'", WFactoryLegalHeavy[WFactorySRifleO]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactorySCharge", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactorySCharge` = '%d'", WFactoryLegalHeavy[WFactorySCharge]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactory9MMAmmo", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactory9MMAmmo` = '%d'", WFactoryLegalLight[WFactory9MMAmmo]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactory50AEAmmo", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactory50AEAmmo` = '%d'", WFactoryLegalLight[WFactory50AEAmmo]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryBuckshot", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryBuckshot` = '%d'", WFactoryLegalHeavy[WFactoryBuckshot]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactory762MMAmmo", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactory762MMAmmo` = '%d'", WFactoryLegalHeavy[WFactory762MMAmmo]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactory127MMAmmo", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactory127MMAmmo` = '%d'", WFactoryLegalHeavy[WFactory127MMAmmo]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryKGP66MMAmmo", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryKGP66MMAmmo` = '%d'", WFactoryLegalHeavy[WFactoryKGP66MMAmmo]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryNapalm", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryNapalm` = '%d'", WFactoryLegalHeavy[WFactoryNapalm]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryPistolPart1", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryPistolPart1` = '%d'", WFactoryLegalLight[WFactoryPistolPart1]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryPistolS1Part1", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryPistolS1Part1` = '%d'", WFactoryLegalLight[WFactoryPistolS1Part1]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryPistolS1Part2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryPistolS1Part2` = '%d'", WFactoryLegalLight[WFactoryPistolS1Part2]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryPistolS1Part3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryPistolS1Part3` = '%d'", WFactoryLegalLight[WFactoryPistolS1Part3]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryPistolPart2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryPistolPart2` = '%d'", WFactoryLegalLight[WFactoryPistolPart2]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryPistolPart3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryPistolPart2` = '%d'", WFactoryLegalLight[WFactoryPistolPart2]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryPistolS2Part1", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryPistolS2Part1` = '%d'", WFactoryLegalLight[WFactoryPistolS2Part1]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryPistolS2Part2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryPistolS2Part2` = '%d'", WFactoryLegalLight[WFactoryPistolS2Part2]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryPistolS2Part3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryPistolS2Part3` = '%d'", WFactoryLegalLight[WFactoryPistolS2Part3]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryPistolS3Part1", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryPistolS3Part1` = '%d'", WFactoryLegalLight[WFactoryPistolS3Part1]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryPistolS3Part2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryPistolS3Part2` = '%d'", WFactoryLegalLight[WFactoryPistolS3Part2]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryPistolS3Part3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryPistolS3Part3` = '%d'", WFactoryLegalLight[WFactoryPistolS3Part3]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryPistolS3Part4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryPistolS3Part4` = '%d'", WFactoryLegalLight[WFactoryPistolS3Part4]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryPistolPart4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryPistolPart4` = '%d'", WFactoryLegalLight[WFactoryPistolPart4]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryPistolPart5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryPistolPart5` = '%d'", WFactoryLegalLight[WFactoryPistolPart5]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryPistolPart6", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryPistolPart6` = '%d'", WFactoryLegalLight[WFactoryPistolPart6]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryRiflePart1", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryRiflePart1` = '%d'", WFactoryLegalHeavy[WFactoryRiflePart1]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryRifleS1Part1", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryRifleS1Part1` = '%d'", WFactoryLegalHeavy[WFactoryRifleS1Part1]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryRifleS1Part2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryRifleS1Part2` = '%d'", WFactoryLegalHeavy[WFactoryRifleS1Part2]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryRiflePart2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryRiflePart2` = '%d'", WFactoryLegalHeavy[WFactoryRiflePart2]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryRifleS2Part1", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryRifleS2Part1` = '%d'", WFactoryLegalHeavy[WFactoryRifleS2Part1]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryRifleS2Part2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryRifleS2Part2` = '%d'", WFactoryLegalHeavy[WFactoryRifleS2Part2]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryRifleS2Part3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryRifleS2Part3` = '%d'", WFactoryLegalHeavy[WFactoryRifleS2Part3]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryRiflePart3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryRiflePart3` = '%d'", WFactoryLegalHeavy[WFactoryRiflePart3]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryRifleS3Part1", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryRifleS3Part1` = '%d'", WFactoryLegalHeavy[WFactoryRifleS3Part1]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryRifleS3Part2", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryRifleS3Part2` = '%d'", WFactoryLegalHeavy[WFactoryRifleS3Part2]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryRifleS3Part3", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryRifleS3Part3` = '%d'", WFactoryLegalHeavy[WFactoryRifleS3Part3]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryRifleS3Part4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryRifleS3Part4` = '%d'", WFactoryLegalHeavy[WFactoryRifleS3Part4]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryRiflePart4", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryRiflePart4` = '%d'", WFactoryLegalHeavy[WFactoryRiflePart4]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryRiflePart5", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryRiflePart5` = '%d'", WFactoryLegalHeavy[WFactoryRiflePart5]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryRiflePart6", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryRiflePart6` = '%d'", WFactoryLegalHeavy[WFactoryRiflePart6]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryRiflePart7", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryRiflePart7` = '%d'", WFactoryLegalHeavy[WFactoryRiflePart7]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryAmmoPart1a", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryAmmoPart1a` = '%d'", WFactoryLegalLight[WFactoryAmmoPart1a]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryAmmoPart2a", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryAmmoPart2a` = '%d'", WFactoryLegalLight[WFactoryAmmoPart2a]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryAmmoPart3a", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryAmmoPart3a` = '%d'", WFactoryLegalLight[WFactoryAmmoPart3a]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryAmmoPart4a", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryAmmoPart4a` = '%d'", WFactoryLegalLight[WFactoryAmmoPart4a]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryAmmoPart1b", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryAmmoPart1b` = '%d'", WFactoryLegalLight[WFactoryAmmoPart1b]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryAmmoPart2b", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryAmmoPart2b` = '%d'", WFactoryLegalLight[WFactoryAmmoPart2b]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryAmmoPart3b", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryAmmoPart3b` = '%d'", WFactoryLegalLight[WFactoryAmmoPart3b]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryAmmoPart4b", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryAmmoPart4b` = '%d'", WFactoryLegalLight[WFactoryAmmoPart4b]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryAmmoPart1c", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryAmmoPart1c` = '%d'", WFactoryLegalLight[WFactoryAmmoPart1c]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryAmmoPart2c", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryAmmoPart2c` = '%d'", WFactoryLegalLight[WFactoryAmmoPart2c]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryAmmoPart3c", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryAmmoPart3c` = '%d'", WFactoryLegalLight[WFactoryAmmoPart3c]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryAmmoPart4c", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryAmmoPart4c` = '%d'", WFactoryLegalLight[WFactoryAmmoPart4c]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryAmmoPart1d", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryAmmoPart1d` = '%d'", WFactoryLegalLight[WFactoryAmmoPart1d]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryAmmoPart2d", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryAmmoPart2d` = '%d'", WFactoryLegalLight[WFactoryAmmoPart2d]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryAmmoPart3d", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryAmmoPart3d` = '%d'", WFactoryLegalLight[WFactoryAmmoPart3d]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryAmmoPart4d", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryAmmoPart4d` = '%d'", WFactoryLegalLight[WFactoryAmmoPart4d]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryAmmoPart1e", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryAmmoPart1e` = '%d'", WFactoryLegalLight[WFactoryAmmoPart1e]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryAmmoPart2e", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryAmmoPart2e` = '%d'", WFactoryLegalLight[WFactoryAmmoPart2e]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryAmmoPart3e", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryAmmoPart3e` = '%d'", WFactoryLegalLight[WFactoryAmmoPart3e]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryAmmoPart4e", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryAmmoPart4e` = '%d'", WFactoryLegalLight[WFactoryAmmoPart4e]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryAK47Part", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryAK47Part` = '%d'", WFactoryLegalHeavy[WFactoryAK47Part]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryM4Part", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryM4Part` = '%d'", WFactoryLegalHeavy[WFactoryM4Part]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryRiflePart", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryRiflePart` = '%d'", WFactoryLegalHeavy[WFactoryRiflePart]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactorySniperPart", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactorySniperPart` = '%d'", WFactoryLegalHeavy[WFactorySniperPart]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryMP5Part", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryMP5Part` = '%d'", WFactoryLegalHeavy[WFactoryMP5Part]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryShotPart", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryShotPart` = '%d'", WFactoryLegalHeavy[WFactoryShotPart]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "WFactoryDesEaglePart", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_wfactorylegal` SET `WFactoryDesEaglePart` = '%d'", WFactoryLegalLight[WFactoryDesEaglePart]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		format(string, sizeof(string), "[WARNING:] Unknown column: %s", column);
		ErrorLog(string);
	}
	return 1;
}

stock SaveBData(bid, column[])
{
	new string[256];
	if(strlen(column) != 0)
	{
		if(strcmp(column, "BuildingName", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_buildings` SET `BuildingName` = '%s' WHERE `id` = '%d' ", Building[bid][BuildingName], bid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "EnterX", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_buildings` SET `EnterX` = '%f' WHERE `id` = '%d' ", Building[bid][EnterX], bid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "EnterY", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_buildings` SET `EnterY` = '%f' WHERE `id` = '%d' ", Building[bid][EnterY], bid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "EnterZ", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_buildings` SET `EnterZ` = '%f' WHERE `id` = '%d' ", Building[bid][EnterZ], bid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "EntranceFee", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_buildings` SET `EntranceFee` = '%d' WHERE `id` = '%d' ", Building[bid][EntranceFee], bid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "ShowIcon", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_buildings` SET `ShowIcon` = '%d' WHERE `id` = '%d' ", Building[bid][ShowIcon], bid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "IconType", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_buildings` SET `IconType` = '%d' WHERE `id` = '%d' ", Building[bid][IconType], bid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "EnterWorld", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_buildings` SET `EnterWorld` = '%d' WHERE `id` = '%d' ", Building[bid][EnterWorld], bid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "EnterInterior", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_buildings` SET `EnterInterior` = '%d' WHERE `id` = '%d' ", Building[bid][EnterInterior], bid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "EnterAngle", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_buildings` SET `EnterAngle` = '%f' WHERE `id` = '%d' ", Building[bid][EnterAngle], bid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "ExitX", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_buildings` SET `ExitX` = '%f' WHERE `id` = '%d' ", Building[bid][ExitX], bid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "ExitY", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_buildings` SET `ExitY` = '%f' WHERE `id` = '%d' ", Building[bid][ExitY], bid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "ExitZ", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_buildings` SET `ExitZ` = '%f' WHERE `id` = '%d' ", Building[bid][ExitZ], bid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "ExitInterior", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_buildings` SET `ExitInterior` = '%d' WHERE `id` = '%d' ", Building[bid][ExitInterior], bid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "ExitAngle", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_buildings` SET `ExitAngle` = '%f' WHERE `id` = '%d' ", Building[bid][ExitAngle], bid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Locked", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_buildings` SET `Locked` = '%d' WHERE `id` = '%d' ", Building[bid][Locked], bid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Opened", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_buildings` SET `Opened` = '%d' WHERE `id` = '%d' ", Building[bid][Opened], bid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "Closed", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_buildings` SET `Closed` = '%d' WHERE `id` = '%d' ", Building[bid][Closed], bid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "ObjectID", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_buildings` SET `ObjectID` = '%d' WHERE `id` = '%d' ", Building[bid][ObjectID], bid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		if(strcmp(column, "BuildingType", true) == 0)
		{
			format(string, sizeof(string), "UPDATE `samp_buildings` SET `BuildingType` = '%d' WHERE `id` = '%d' ", Building[bid][BuildingType], bid+1);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			return 1;
		}
		format(string, sizeof(string), "[WARNING:] Unknown column: %s", column);
		ErrorLog(string);
	}
	return 1;
}

stock SaveObjData(slot)
{	
	static slotUsed, Float:ox, Float:oy, Float:oz, Float:orx, Float:ory, Float:orz, string[1024];
	strdel(string, 0, sizeof(string));
	if(gCustomObj[slot][cstSlotUsed])
	{
		slotUsed = 1;
		GetDynamicObjectPos( gCustomObj[slot][cstObjID], ox, oy, oz );
		GetDynamicObjectRot( gCustomObj[slot][cstObjID], orx, ory, orz );
		format( string, sizeof(string),
		"UPDATE `samp_objects` SET `cstSlotUsed` = '%d', `cstObjModel` = '%d', `cstObjVW` = '%d', `cstObjInt` = '%d', `cstObjOwner` = '%s', `cstObjX` = '%f', `cstObjY` = '%f', `cstObjZ` = '%f', `cstObjRX` = '%f', `cstObjRY` = '%f', `cstObjRZ` = '%f' WHERE `id` = '%d'",
		slotUsed, gCustomObj[slot][cstObjModel], gCustomObj[slot][cstObjVW], gCustomObj[slot][cstObjInt], gCustomObj[slot][cstObjOwner], ox, oy, oz, orx, ory, orz, slot+1 );
	}
	else
	{
		slotUsed = 0;
		format( string, sizeof(string),
		"UPDATE `samp_objects` SET `cstSlotUsed` = '%d', `cstObjModel` = '%d', `cstObjVW` = '%d', `cstObjInt` = '%d', `cstObjOwner` = '%s' WHERE `id` = '%d'",
		slotUsed, gCustomObj[slot][cstObjModel], gCustomObj[slot][cstObjVW], gCustomObj[slot][cstObjInt], gCustomObj[slot][cstObjOwner], slot+1 );
	}
	mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
	return 1;
}

SaveBusTrack(slot, column[], cp=-1)
{
	new string[512];
	
	if(strcmp(column, "gBusTrackEnabled") == 0)
	{
		format(string, sizeof(string), "UPDATE `samp_bus_tracks` SET `Enabled` = '%d' WHERE `id` = '%d'", gBusTrackEnabled[slot], slot+1);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
		return 1;
	}
	else if(strcmp(column, "gBusTrackStartArea") == 0)
	{
		format(string, sizeof(string), "UPDATE `samp_bus_tracks` SET `StartArea` = '%d' WHERE `id` = '%d'", gBusTrackStartArea[slot], slot+1);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
		return 1;
	}
	else if(strcmp(column, "gBusTrackCP") == 0)
	{
		format(string, sizeof(string), "UPDATE `samp_bus_tracks_data` SET `CPX` = '%f' , `CPY` = '%f' , `CPZ` = '%f', `CPReward` = '%d' , `CPType` = '%d', `CPTime` = '%d' WHERE `TrackID` = '%d' AND `CPID` = '%d'",
			gBusTrackCpX[slot][cp], gBusTrackCpY[slot][cp], gBusTrackCpZ[slot][cp], gBusTrackCpReward[slot][cp], gBusTrackCpType[slot][cp], gBusTrackCpTime[slot][cp], slot, cp);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
		return 1;
	}
	format(string, sizeof(string), "[WARNING:] Unknown column: %s", column);
	ErrorLog(string);
	return 1;
}

SaveTrashTrack(slot, column[], cp=-1)
{
	new string[512];
	
	if(strcmp(column, "gTrashTrackEnabled") == 0)
	{
		format(string, sizeof(string), "UPDATE `samp_trash_tracks` SET `Enabled` = '%d' WHERE `id` = '%d'", gTrashTrackEnabled[slot], slot+1);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
		return 1;
	}
	else if(strcmp(column, "gTrashTrackStartArea") == 0)
	{
		format(string, sizeof(string), "UPDATE `samp_trash_tracks` SET `StartArea` = '%d' WHERE `id` = '%d'", gTrashTrackStartArea[slot], slot+1);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
		return 1;
	}
	else if(strcmp(column, "gTrashTrackCP") == 0)
	{
		format(string, sizeof(string), "UPDATE `samp_trash_tracks_data` SET `CPX` = '%f' , `CPY` = '%f' , `CPZ` = '%f', `CPReward` = '%d' , `CPType` = '%d', `CPTime` = '%d' WHERE `TrackID` = '%d' AND `CPID` = '%d'",
			gTrashTrackCpX[slot][cp], gTrashTrackCpY[slot][cp], gTrashTrackCpZ[slot][cp], gTrashTrackCpReward[slot][cp], gTrashTrackCpType[slot][cp], gTrashTrackCpTime[slot][cp], slot, cp);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
		return 1;
	}
	format(string, sizeof(string), "[WARNING:] Unknown column: %s", column);
	ErrorLog(string);
	return 1;
}

SaveSweeperTrack(slot, column[], cp=-1)
{
	new string[512];
	
	if(strcmp(column, "gSweeperTrackEnabled") == 0)
	{
		format(string, sizeof(string), "UPDATE `samp_sweeper_tracks` SET `Enabled` = '%d' WHERE `id` = '%d'", gSweeperTrackEnabled[slot], slot+1);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
		return 1;
	}
	else if(strcmp(column, "gSweeperTrackStartArea") == 0)
	{
		format(string, sizeof(string), "UPDATE `samp_sweeper_tracks` SET `StartArea` = '%d' WHERE `id` = '%d'", gSweeperTrackStartArea[slot], slot+1);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
		return 1;
	}
	else if(strcmp(column, "gSweeperTrackCP") == 0)
	{
		format(string, sizeof(string), "UPDATE `samp_sweeper_tracks_data` SET `CPX` = '%f' , `CPY` = '%f' , `CPZ` = '%f', `CPReward` = '%d' , `CPType` = '%d', `CPTime` = '%d' WHERE `TrackID` = '%d' AND `CPID` = '%d'",
			gSweeperTrackCpX[slot][cp], gSweeperTrackCpY[slot][cp], gSweeperTrackCpZ[slot][cp], gSweeperTrackCpReward[slot][cp], gSweeperTrackCpType[slot][cp], gSweeperTrackCpTime[slot][cp], slot, cp);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
		return 1;
	}
	format(string, sizeof(string), "[WARNING:] Unknown column: %s", column);
	ErrorLog(string);
	return 1;
}

SaveFarmerTrack(slot, column[], cp=-1)
{
	new string[512];
	
	if(strcmp(column, "gFarmerTrackEnabled") == 0)
	{
		format(string, sizeof(string), "UPDATE `samp_farmer_tracks` SET `Enabled` = '%d' WHERE `id` = '%d'", gFarmerTrackEnabled[slot], slot+1);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
		return 1;
	}
	else if(strcmp(column, "gFarmerTrackStartArea") == 0)
	{
		format(string, sizeof(string), "UPDATE `samp_farmer_tracks` SET `StartArea` = '%d' WHERE `id` = '%d'", gFarmerTrackStartArea[slot], slot+1);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
		return 1;
	}
	else if(strcmp(column, "gFarmerTrackCP") == 0)
	{
		format(string, sizeof(string), "UPDATE `samp_farmer_tracks_data` SET `CPX` = '%f' , `CPY` = '%f' , `CPZ` = '%f', `CPReward` = '%d' , `CPType` = '%d', `CPTime` = '%d' WHERE `TrackID` = '%d' AND `CPID` = '%d'",
			gFarmerTrackCpX[slot][cp], gFarmerTrackCpY[slot][cp], gFarmerTrackCpZ[slot][cp], gFarmerTrackCpReward[slot][cp], gFarmerTrackCpType[slot][cp], gFarmerTrackCpTime[slot][cp], slot, cp);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
		return 1;
	}
	format(string, sizeof(string), "[WARNING:] Unknown column: %s", column);
	ErrorLog(string);
	return 1;
}

SaveItemFactory(fID, column[])
{
	new string[512];
	
	if(strcmp(column, "Name") == 0)
	{
		format(string, sizeof(string), "UPDATE `samp_item_factories` SET `name` = '%s WHERE `id` = '%d''", gItemFactories[fID][fName], fID+1);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
		return 1;
	}
	else if(strcmp(column, "Pos") == 0)
	{
		format(string, sizeof(string), "UPDATE `samp_item_factories` SET `posX` = '%f' , `posY` = '%f' , `posZ` = '%f' WHERE `id` = '%d'", gItemFactories[fID][fPosX], gItemFactories[fID][fPosY], gItemFactories[fID][fPosZ], fID+1);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
		return 1;
	}
	else if(strcmp(column, "item1") == 0)
	{
		format(string, sizeof(string), "UPDATE `samp_item_factories` SET `item1` = '%d' , `item1type` = '%d' , `item1count` = '%d' , `item1minBuy` = '%d' , `item1reproduceCount` = '%d' , `item1price` = '%d' WHERE `id` = '%d' ",
			gItemFactories[fID][item1], gItemFactories[fID][item1type], gItemFactories[fID][item1count], gItemFactories[fID][item1minBuy], gItemFactories[fID][item1reproduceCount], gItemFactories[fID][item1price], fID+1);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
		return 1;
	}
	else if(strcmp(column, "item2") == 0)
	{
		format(string, sizeof(string), "UPDATE `samp_item_factories` SET `item2` = '%d' , `item2type` = '%d' , `item2count` = '%d' , `item2minBuy` = '%d' , `item2reproduceCount` = '%d' , `item2price` = '%d' WHERE `id` = '%d' ",
			gItemFactories[fID][item2], gItemFactories[fID][item2type], gItemFactories[fID][item2count], gItemFactories[fID][item2minBuy], gItemFactories[fID][item2reproduceCount], gItemFactories[fID][item2price], fID+1);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
		return 1;
	}
	else if(strcmp(column, "item3") == 0)
	{
		format(string, sizeof(string), "UPDATE `samp_item_factories` SET `item3` = '%d' , `item3type` = '%d' , `item3count` = '%d' , `item3minBuy` = '%d' , `item3reproduceCount` = '%d' , `item3price` = '%d' WHERE `id` = '%d' ",
			gItemFactories[fID][item3], gItemFactories[fID][item3type], gItemFactories[fID][item3count], gItemFactories[fID][item3minBuy], gItemFactories[fID][item3reproduceCount], gItemFactories[fID][item3price], fID+1);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
		return 1;
	}
	else if(strcmp(column, "item4") == 0)
	{
		format(string, sizeof(string), "UPDATE `samp_item_factories` SET `item4` = '%d' , `item4type` = '%d' , `item4count` = '%d' , `item4minBuy` = '%d' , `item4reproduceCount` = '%d' , `item4price` = '%d' WHERE `id` = '%d' ",
			gItemFactories[fID][item4], gItemFactories[fID][item4type], gItemFactories[fID][item4count], gItemFactories[fID][item4minBuy], gItemFactories[fID][item4reproduceCount], gItemFactories[fID][item4price], fID+1);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
		return 1;
	}
	else if(strcmp(column, "item5") == 0)
	{
		format(string, sizeof(string), "UPDATE `samp_item_factories` SET `item5` = '%d' , `item5type` = '%d' , `item5count` = '%d' , `item5minBuy` = '%d' , `item5reproduceCount` = '%d' , `item5price` = '%d' WHERE `id` = '%d' ",
			gItemFactories[fID][item5], gItemFactories[fID][item5type], gItemFactories[fID][item5count], gItemFactories[fID][item5minBuy], gItemFactories[fID][item5reproduceCount], gItemFactories[fID][item5price], fID+1);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
		return 1;
	}
	else if(strcmp(column, "item6") == 0)
	{
		format(string, sizeof(string), "UPDATE `samp_item_factories` SET `item6` = '%d' , `item6type` = '%d' , `item6count` = '%d' , `item6minBuy` = '%d' , `item6reproduceCount` = '%d' , `item6price` = '%d' WHERE `id` = '%d' ",
			gItemFactories[fID][item6], gItemFactories[fID][item6type], gItemFactories[fID][item6count], gItemFactories[fID][item6minBuy], gItemFactories[fID][item6reproduceCount], gItemFactories[fID][item6price], fID+1);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
		return 1;
	}
	else if(strcmp(column, "item7") == 0)
	{
		format(string, sizeof(string), "UPDATE `samp_item_factories` SET `item7` = '%d' , `item7type` = '%d' , `item7count` = '%d' , `item7minBuy` = '%d' , `item7reproduceCount` = '%d' , `item7price` = '%d' WHERE `id` = '%d' ",
			gItemFactories[fID][item7], gItemFactories[fID][item7type], gItemFactories[fID][item7count], gItemFactories[fID][item7minBuy], gItemFactories[fID][item7reproduceCount], gItemFactories[fID][item7price], fID+1);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
		return 1;
	}
	else if(strcmp(column, "item8") == 0)
	{
		format(string, sizeof(string), "UPDATE `samp_item_factories` SET `item8` = '%d' , `item8type` = '%d' , `item8count` = '%d' , `item8minBuy` = '%d' , `item8reproduceCount` = '%d' , `item8price` = '%d' WHERE `id` = '%d' ",
			gItemFactories[fID][item8], gItemFactories[fID][item8type], gItemFactories[fID][item8count], gItemFactories[fID][item8minBuy], gItemFactories[fID][item8reproduceCount], gItemFactories[fID][item8price], fID+1);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
		return 1;
	}
	else if(strcmp(column, "item9") == 0)
	{
		format(string, sizeof(string), "UPDATE `samp_item_factories` SET `item9` = '%d' , `item9type` = '%d' , `item9count` = '%d' , `item9minBuy` = '%d' , `item9reproduceCount` = '%d' , `item9price` = '%d' WHERE `id` = '%d' ",
			gItemFactories[fID][item9], gItemFactories[fID][item9type], gItemFactories[fID][item9count], gItemFactories[fID][item9minBuy], gItemFactories[fID][item9reproduceCount], gItemFactories[fID][item9price], fID+1);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
		return 1;
	}
	else if(strcmp(column, "item10") == 0)
	{
		format(string, sizeof(string), "UPDATE `samp_item_factories` SET `item10` = '%d' , `item10type` = '%d' , `item10count` = '%d' , `item10minBuy` = '%d' , `item10reproduceCount` = '%d' , `item10price` = '%d' WHERE `id` = '%d' ",
			gItemFactories[fID][item10], gItemFactories[fID][item10type], gItemFactories[fID][item10count], gItemFactories[fID][item10minBuy], gItemFactories[fID][item10reproduceCount], gItemFactories[fID][item10price], fID+1);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
		return 1;
	}
	format(string, sizeof(string), "[WARNING:] Unknown column: %s", column);
	ErrorLog(string);
	return 1;
}

stock SaveGangZone(zId, column[])
{
	new string[256];
	if(strcmp(column, "PosMin") == 0)
	{
		format(string, sizeof(string), "UPDATE `samp_gang_zones` SET `PosMinX` = '%f', `PosMinY` = '%f' WHERE `id` = '%d'",
			DynamicZones[zId][mPosMinX], DynamicZones[zId][mPosMinY], zId+1);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
		return 1;
	}
	else if(strcmp(column, "PosMax") == 0)
	{
		format(string, sizeof(string), "UPDATE `samp_gang_zones` SET `PosMaxX` = '%f', `PosMaxY` = '%f' WHERE `id` = '%d'",
			DynamicZones[zId][mPosMaxX], DynamicZones[zId][mPosMaxY], zId+1);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
		return 1;
	}
	else if(strcmp(column, "Faction") == 0)
	{
		format(string, sizeof(string), "UPDATE `samp_gang_zones` SET `Faction` = '%d' WHERE `id` = '%d'",
			DynamicZones[zId][mFaction], zId+1);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
		return 1;
	}
	else if(strcmp(column, "CharStealTimeLeft") == 0)
	{
		format(string, sizeof(string), "UPDATE `samp_gang_zones` SET `CharStealTimeLeft` = '%d' WHERE `id` = '%d'",
			DynamicZones[zId][mCharStealTimeLeft], zId+1);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
		return 1;
	}
	else if(strcmp(column, "VehStealTimeLeft") == 0)
	{
		format(string, sizeof(string), "UPDATE `samp_gang_zones` SET `VehStealTimeLeft` = '%d' WHERE `id` = '%d'",
			DynamicZones[zId][mVehStealTimeLeft], zId+1);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
		return 1;
	}
	else if(strcmp(column, "VehBreakTimeLeft") == 0)
	{
		format(string, sizeof(string), "UPDATE `samp_gang_zones` SET `VehBreakTimeLeft` = '%d' WHERE `id` = '%d'",
			DynamicZones[zId][mVehBreakTimeLeft], zId+1);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
		return 1;
	}
	else if(strcmp(column, "BizStealTimeLeft") == 0)
	{
		format(string, sizeof(string), "UPDATE `samp_gang_zones` SET `BizStealTimeLeft` = '%d' WHERE `id` = '%d'",
			DynamicZones[zId][mBizStealTimeLeft], zId+1);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
		return 1;
	}
	else if(strcmp(column, "BizBreakTimeLeft") == 0)
	{
		format(string, sizeof(string), "UPDATE `samp_gang_zones` SET `BizBreakTimeLeft` = '%d' WHERE `id` = '%d'",
			DynamicZones[zId][mBizBreakTimeLeft], zId+1);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
		return 1;
	}
	else if(strcmp(column, "HouseStealTimeLeft") == 0)
	{
		format(string, sizeof(string), "UPDATE `samp_gang_zones` SET `HouseStealTimeLeft` = '%d' WHERE `id` = '%d'",
			DynamicZones[zId][mHouseStealTimeLeft], zId+1);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
		return 1;
	}
	else if(strcmp(column, "HouseBreakTimeLeft") == 0)
	{
		format(string, sizeof(string), "UPDATE `samp_gang_zones` SET `HouseBreakTimeLeft` = '%d' WHERE `id` = '%d'",
			DynamicZones[zId][mHouseBreakTimeLeft], zId+1);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
		return 1;
	}
	format(string, sizeof(string), "[WARNING:] Unknown column: %s", column);
	ErrorLog(string);
	return 1;
}
	
stock SaveWeedData(wId, column[])
{
	new string[256];
	if(strcmp(column, "Pos") == 0)
	{
		format(string, sizeof(string), "UPDATE `samp_weed` SET `PosX` = '%f' , `PosY` = '%f' , `PosZ` = '%f' WHERE `id` = '%d'",
			gWeed[wId][mPosX], gWeed[wId][mPosY], gWeed[wId][mPosZ], wId+1);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
		return 1;
	}
	else if(strcmp(column, "Type") == 0)
	{
		format(string, sizeof(string), "UPDATE `samp_weed` SET `Type` = '%d' WHERE `id` = '%d'",
			gWeed[wId][mType], wId+1);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
		return 1;
	}
	else if(strcmp(column, "Phase") == 0)
	{
		format(string, sizeof(string), "UPDATE `samp_weed` SET `Phase` = '%d' WHERE `id` = '%d'",
			gWeed[wId][mPhase], wId+1);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
		return 1;
	}
	format(string, sizeof(string), "[WARNING:] Unknown column: %s", column);
	ErrorLog(string);
	return 1;
}

stock SaveRaceData(raceId, column[], cpId = -1)
{
	new string[256];
	if(strcmp(column, "RaceTrackEnabled") == 0)
	{
		format(string, sizeof(string), "UPDATE `samp_races_tracks` SET `Enabled` = '%d' WHERE `ID` = '%d'",
			gRaceTrackEnabled[raceId], raceId+1);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
		return 1;
	}
	else if(strcmp(column, "RaceTrackInfoCpX") == 0)
	{
		format(string, sizeof(string), "UPDATE `samp_races_tracks` SET `InfoCpX` = '%f' , `InfoCpY` = '%f' , `InfoCpZ` = '%f' WHERE `ID` = '%d'",
			gRaceTrackInfoCpX[raceId], gRaceTrackInfoCpY[raceId], gRaceTrackInfoCpZ[raceId], raceId+1);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
		return 1;
	}
	else if(strcmp(column, "RaceTrackStartPosCount") == 0)
	{
		format(string, sizeof(string), "UPDATE `samp_races_tracks` SET `StartPosCount` = '%d' WHERE `ID` = '%d'",
			gRaceTrackStartPosCount[raceId], raceId+1);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
		return 1;
	}
	else if(strcmp(column, "RaceTrackStart1Cp") == 0)
	{
		format(string, sizeof(string), "UPDATE `samp_races_tracks` SET `Start1CpX` = '%f' , `Start1CpY` = '%f' , `Start1CpZ` = '%f' WHERE `ID` = '%d'",
			gRaceTrackStart1CpX[raceId], gRaceTrackStart1CpY[raceId], gRaceTrackStart1CpZ[raceId], raceId+1);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
		return 1;
	}
	else if(strcmp(column, "RaceTrackStart2Cp") == 0)
	{
		format(string, sizeof(string), "UPDATE `samp_races_tracks` SET `Start2CpX` = '%f' , `Start2CpY` = '%f' , `Start2CpZ` = '%f' WHERE `ID` = '%d'",
			gRaceTrackStart2CpX[raceId], gRaceTrackStart2CpY[raceId], gRaceTrackStart2CpZ[raceId], raceId+1);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
		return 1;
	}
	else if(strcmp(column, "RaceTrackStart3Cp") == 0)
	{
		format(string, sizeof(string), "UPDATE `samp_races_tracks` SET `Start3CpX` = '%f' , `Start3CpY` = '%f' , `Start3CpZ` = '%f' WHERE `ID` = '%d'",
			gRaceTrackStart3CpX[raceId], gRaceTrackStart3CpY[raceId], gRaceTrackStart3CpZ[raceId], raceId+1);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
		return 1;
	}
	else if(strcmp(column, "RaceTrackStart4Cp") == 0)
	{
		format(string, sizeof(string), "UPDATE `samp_races_tracks` SET `Start4CpX` = '%f' , `Start4CpY` = '%f' , `Start4CpZ` = '%f' WHERE `ID` = '%d'",
			gRaceTrackStart4CpX[raceId], gRaceTrackStart4CpY[raceId], gRaceTrackStart4CpZ[raceId], raceId+1);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
		return 1;
	}
	else if(strcmp(column, "RaceTrackStart5Cp") == 0)
	{
		format(string, sizeof(string), "UPDATE `samp_races_tracks` SET `Start5CpX` = '%f' , `Start5CpY` = '%f' , `Start5CpZ` = '%f' WHERE `ID` = '%d'",
			gRaceTrackStart5CpX[raceId], gRaceTrackStart5CpY[raceId], gRaceTrackStart5CpZ[raceId], raceId+1);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
		return 1;
	}
	else if(strcmp(column, "RaceTrackStart6Cp") == 0)
	{
		format(string, sizeof(string), "UPDATE `samp_races_tracks` SET `Start6CpX` = '%f' , `Start6CpY` = '%f' , `Start6CpZ` = '%f' WHERE `ID` = '%d'",
			gRaceTrackStart6CpX[raceId], gRaceTrackStart6CpY[raceId], gRaceTrackStart6CpZ[raceId], raceId+1);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
		return 1;
	}
	else if(strcmp(column, "RaceTrackStart7Cp") == 0)
	{
		format(string, sizeof(string), "UPDATE `samp_races_tracks` SET `Start7CpX` = '%f' , `Start7CpY` = '%f' , `Start7CpZ` = '%f' WHERE `ID` = '%d'",
			gRaceTrackStart7CpX[raceId], gRaceTrackStart7CpY[raceId], gRaceTrackStart7CpZ[raceId], raceId+1);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
		return 1;
	}
	else if(strcmp(column, "RaceTrackStart8Cp") == 0)
	{
		format(string, sizeof(string), "UPDATE `samp_races_tracks` SET `Start8CpX` = '%f' , `Start8CpY` = '%f' , `Start8CpZ` = '%f' WHERE `ID` = '%d'",
			gRaceTrackStart8CpX[raceId], gRaceTrackStart8CpY[raceId], gRaceTrackStart8CpZ[raceId], raceId+1);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
		return 1;
	}
	else if(strcmp(column, "RaceTrackStart9Cp") == 0)
	{
		format(string, sizeof(string), "UPDATE `samp_races_tracks` SET `Start9CpX` = '%f' , `Start9CpY` = '%f' , `Start9CpZ` = '%f' WHERE `ID` = '%d'",
			gRaceTrackStart9CpX[raceId], gRaceTrackStart9CpY[raceId], gRaceTrackStart9CpZ[raceId], raceId+1);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
		return 1;
	}
	else if(strcmp(column, "RaceTrackStart10Cp") == 0)
	{
		format(string, sizeof(string), "UPDATE `samp_races_tracks` SET `Start10CpX` = '%f' , `Start10CpY` = '%f' , `Start10CpZ` = '%f' WHERE `ID` = '%d'",
			gRaceTrackStart10CpX[raceId], gRaceTrackStart10CpY[raceId], gRaceTrackStart10CpZ[raceId], raceId+1);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
		return 1;
	}
	else if(strcmp(column, "RaceTrackCp") == 0)
	{
		format(string, sizeof(string), "UPDATE `samp_races_tracks_data` SET `CpX` = '%f' , `CpY` = '%f' , `CpZ` = '%f' , `CpType` = '%d' WHERE `RaceId` = '%d' AND `CpId` = '%d'",
			gRaceTrackCpX[raceId][cpId], gRaceTrackCpY[raceId][cpId], gRaceTrackCpZ[raceId][cpId], gRaceTrackCpType[raceId][cpId], raceId, cpId);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
		return 1;
	}
	format(string, sizeof(string), "[WARNING:] Unknown column: %s", column);
	ErrorLog(string);
	return 1;
}