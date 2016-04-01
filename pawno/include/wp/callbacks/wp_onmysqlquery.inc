/***
*
* File: wp_onmysqlquery.inc
* Auth: Damian Wojdat
* Date: 15.09.2011
* Desc: Mysql functions.
* TODO: Fix loading player gas station debts.
*
*************************************************************************************************************/

/*public OnMysqlQueryArray(resultid, extravars[], MySQL:handle)
{
	static
		arrCoords[50][512],
		PlayerNameTMP[128],
		arrayData[2][256],
		string[256],
		playerid
	;
	strdel(PlayerNameTMP, 0, sizeof(PlayerNameTMP));
	strdel(string, 0, sizeof(string));
	format(string, sizeof(string), "%s", extravars);
	split2(string, arrayData, '|');
	playerid = strval(arrayData[0]);
	GetPlayerName(playerid,PlayerNameTMP, sizeof(PlayerNameTMP));
	switch(resultid)
	{
		case PLAYER_LOAD_FUEL:
		{
			// printf("[DEBUG:][PLAYER_LOAD_FUEL] pid = %d, pname = %s LIMIT 1", playerid, gPlayerData[playerid][pName]);
			new bizID = strval(arrayData[1]);
			if( bizID == 1 )
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Czekaj, trwa ³adowanie danych [dane tankowañ - mo¿e chwile potrwaæ]...");
			// printf("[INTO:] dataar[1] = %d", strval(arrayData[1]) );
			if(!mysql_store_result(db_con2))
			{
				ErrorLog("[ERROR:] Can't store result on PLAYER_LOAD_FUEL");
				if(playerid < CUSTOM_MAX_PLAYERS)
				{
					SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Wyst¹pi³ b³¹d przy ³adowaniu danych twojego konta. Jeœli problem bêdzie siê powtarza³ skontaktuj siê z administratorem" );
					return 1;
				}
			}
			if(mysql_num_rows(db_con2) == 0 && playerid < CUSTOM_MAX_PLAYERS)
			{
				format(string, sizeof(string), "INSERT INTO `samp_users_fueled` (`PlayerName`, `BizID`) VALUES ('%s', '%d')", PlayerNameTMP, bizID );
				mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			}
			else
			{
				mysql_fetch_row_format(db_result, "|", db_con2);
				split2(db_result, arrCoords, '|');
				// printf("BizID = %d, Petrol = %f", bizID, floatstr(arrCoords[3]) );
				gPlayerData[playerid][pGasStationRefPetrol][bizID] = floatstr(arrCoords[3]);
				gPlayerData[playerid][pGasStationRefOil][bizID] = floatstr(arrCoords[4]);
				gPlayerData[playerid][pGasStationRefGas][bizID] = floatstr(arrCoords[5]);
			}
			mysql_free_result(db_con2);
		}
	}
	return 1;
}*/

public OnQueryError(errorid, error[], resultid, extraid, callback[], query[], connectionHandle)
{
	printf("[ERROR:] MySQL: %s, connection id: %d", error, resultid);
	printf("[ERROR:] Query: %s", query);
	return 1;
}

// public OnMysqlQuery(query[], resultid, spareid, MySQL:handle)
public OnQueryFinish(query[], resultid, extraid, connectionHandle)
{
	static
		arrCoords[153][64],
		PlayerNameTMP[128],
		string[1324],
		string2[128],
		playerid
	;
	playerid = extraid;
	strdel(string, 0, sizeof(string));
	strdel(string2, 0, sizeof(string2));
	strdel(PlayerNameTMP, 0, sizeof(PlayerNameTMP));

	GetPlayerName(playerid, PlayerNameTMP, sizeof(PlayerNameTMP));
	switch(resultid)
	{
		case PLAYER_DATA_LOAD_NAME_MYSQL:
		{
			#if defined DEBUG
				printf("[DEBUG:][PLAYER_LOAD_NAME_MYSQL] pid = %d, pname = %s", playerid, PlayerNameTMP);
			#endif
			if(!mysql_store_result(db_con4))
			{
				ErrorLog("[ERROR:] Can't store result on PLAYER_DATA_LOAD_NAME_MYSQL");
				return 1;
			}
			mysql_fetch_row_format(db_result, "|", db_con4);

			if(mysql_num_rows(db_con4) == 0 )
			{
				mysql_free_result(db_con4);
				format(string, sizeof(string), "[PAYDAY:] Player ID %d not exist, increasing ID, loop ID: %d", gPayDayID, gPayDayLoop);
				PayDayLog(string);
				gPayDayLoop++;
				if(gPayDayLoop <= gPayDayCount)
				{
					format(string, sizeof(string), "SELECT `Key`,`ID`,`PlayerName`,`Level`,`AdminLevel`,`DonateRank`,`Registered`,`Sex`,`Age`,`Experience`,`Money`,`Bank`,`Skin`,`PlayingHours`,`AllowedPayday`,`PayCheck`,`Faction`,`Rank`,`Banned`");
					strcat( string, ",`Warnings`,`Jailed`,`JailTime`,`CrashX`,`CrashY`,`CrashZ`,`CrashInt`,`CrashW`,`Crashed`,`Wins`,`Loses`,`InvWeapon`,`InvAmmo`,`Tutorial`,`Moderator`,`WantedLvl`,`FirstCar`,`FirstReanimation`,`FirstPhone`,`FirstLeader`" );
					strcat( string, ",`CrashAngle`,`HourAssist`,`JoinedFaction`,`HoursOnDuty`,`HoursOnDutyHelper`,`WarnCooldown`,`SpeedLimiter`,`AdminDuty`,`CharDescription`,`CharDescriptionColor`, `FirstJob`, `FirstID`, `FirstBuy`, `FirstHouse`, `FirstDescription`" );
					strcat( string, ", `FirstAction`, `FirstBankUse`, `FirstStats`, `FirstJail`, `FirstStudy`" );
					format( string, sizeof(string), "%s FROM `samp_users` WHERE `Banned` = '0' LIMIT %d , 1", string, gPayDayLoop);
					mysql_query(string, PLAYER_DATA_LOAD_NAME_MYSQL, CUSTOM_MAX_PLAYERS, db_con4);
				}
				return 1;
			}

			mysql_fetch_field_row(gPlayerData[CUSTOM_MAX_PLAYERS][pName], "PlayerName", db_con4);
			mysql_fetch_field_row(string, "Level", db_con4);
			gPlayerData[CUSTOM_MAX_PLAYERS][pLevel] = strval(string);
			mysql_fetch_field_row(string, "AdminLevel", db_con4);
			gPlayerData[CUSTOM_MAX_PLAYERS][pAdmin] = strval(string);
			mysql_fetch_field_row(string, "DonateRank", db_con4);
			gPlayerData[CUSTOM_MAX_PLAYERS][pDonateRank] = strval(string);
			mysql_fetch_field_row(string, "Registered", db_con4);
			gPlayerData[CUSTOM_MAX_PLAYERS][pRegistered] = strval(string);
			mysql_fetch_field_row(string, "Sex", db_con4);
			gPlayerData[CUSTOM_MAX_PLAYERS][pSex] = strval(string);
			mysql_fetch_field_row(string, "Age", db_con4);
			gPlayerData[CUSTOM_MAX_PLAYERS][pAge] = strval(string);
			mysql_fetch_field_row(string, "Experience", db_con4);
			gPlayerData[CUSTOM_MAX_PLAYERS][pExp] = strval(string);
			mysql_fetch_field_row(string, "Money", db_con4);
			gPlayerData[CUSTOM_MAX_PLAYERS][pCash] = strval(string);
			mysql_fetch_field_row(string, "Bank", db_con4);
			gPlayerData[CUSTOM_MAX_PLAYERS][pBank] = strval(string);
			mysql_fetch_field_row(string, "Skin", db_con4);
			gPlayerData[CUSTOM_MAX_PLAYERS][pSkin] = strval(string);
			mysql_fetch_field_row(string, "PlayingHours", db_con4);
			gPlayerData[CUSTOM_MAX_PLAYERS][pPlayingHours] = strval(string);
			mysql_fetch_field_row(string, "AllowedPayday", db_con4);
			gPlayerData[CUSTOM_MAX_PLAYERS][pAllowedPayday] = strval(string);
			mysql_fetch_field_row(string, "PayCheck", db_con4);
			gPlayerData[CUSTOM_MAX_PLAYERS][pPayCheck] = strval(string);
			mysql_fetch_field_row(string, "Faction", db_con4);
			gPlayerData[CUSTOM_MAX_PLAYERS][pFaction] = strval(string);
			mysql_fetch_field_row(string, "Rank", db_con4);
			gPlayerData[CUSTOM_MAX_PLAYERS][pRank] = strval(string);
			mysql_fetch_field_row(string, "Banned", db_con4);
			gPlayerData[CUSTOM_MAX_PLAYERS][pBanned] = strval(string);
			mysql_fetch_field_row(string, "Warnings", db_con4);
			gPlayerData[CUSTOM_MAX_PLAYERS][pWarnings] = strval(string);
			mysql_fetch_field_row(string, "Jailed", db_con4);
			gPlayerData[CUSTOM_MAX_PLAYERS][pJailed] = strval(string);
			mysql_fetch_field_row(string, "JailTime", db_con4);
			gPlayerData[CUSTOM_MAX_PLAYERS][pJailTime] = strval(string);
			mysql_fetch_field_row(string, "CrashX", db_con4);
			gPlayerData[CUSTOM_MAX_PLAYERS][pCrashX] = floatstr(string);
			mysql_fetch_field_row(string, "CrashY", db_con4);
			gPlayerData[CUSTOM_MAX_PLAYERS][pCrashY] = floatstr(string);
			mysql_fetch_field_row(string, "CrashZ", db_con4);
			gPlayerData[CUSTOM_MAX_PLAYERS][pCrashZ] = floatstr(string);
			mysql_fetch_field_row(string, "CrashInt", db_con4);
			gPlayerData[CUSTOM_MAX_PLAYERS][pCrashInt] = strval(string);
			mysql_fetch_field_row(string, "CrashW", db_con4);
			gPlayerData[CUSTOM_MAX_PLAYERS][pCrashW] = strval(string);
			mysql_fetch_field_row(string, "Crashed", db_con4);
			gPlayerData[CUSTOM_MAX_PLAYERS][pCrashed] = strval(string);
			mysql_fetch_field_row(string, "Wins", db_con4);
			gPlayerData[CUSTOM_MAX_PLAYERS][pWins] = strval(string);
			mysql_fetch_field_row(string, "Loses", db_con4);
			gPlayerData[CUSTOM_MAX_PLAYERS][pLoses] = strval(string);
			mysql_fetch_field_row(string, "InvWeapon", db_con4);
			gPlayerData[CUSTOM_MAX_PLAYERS][pInvWeapon] = strval(string);
			mysql_fetch_field_row(string, "InvAmmo", db_con4);
			gPlayerData[CUSTOM_MAX_PLAYERS][pInvAmmo] = strval(string);
			mysql_fetch_field_row(string, "Moderator", db_con4);
			gPlayerData[CUSTOM_MAX_PLAYERS][pModerator] = strval(string);
			mysql_fetch_field_row(string, "WantedLvl", db_con4);
			gPlayerData[CUSTOM_MAX_PLAYERS][pWantedLvl] = strval(string);
			mysql_fetch_field_row(string, "FirstCar", db_con4);
			gPlayerData[CUSTOM_MAX_PLAYERS][pFirstCar] = strval(string);
			mysql_fetch_field_row(string, "FirstReanimation", db_con4);
			gPlayerData[CUSTOM_MAX_PLAYERS][pFirstReanimation] = strval(string);
			mysql_fetch_field_row(string, "FirstPhone", db_con4);
			gPlayerData[CUSTOM_MAX_PLAYERS][pFirstPhone] = strval(string);
			mysql_fetch_field_row(string, "FirstLeader", db_con4);
			gPlayerData[CUSTOM_MAX_PLAYERS][pFirstLeader] = strval(string);
			mysql_fetch_field_row(string, "FirstJob", db_con4);
			gPlayerData[CUSTOM_MAX_PLAYERS][pFirstJob] = strval(string);
			mysql_fetch_field_row(string, "FirstID", db_con4);
			gPlayerData[CUSTOM_MAX_PLAYERS][pFirstID] = strval(string);
			mysql_fetch_field_row(string, "FirstBuy", db_con4);
			gPlayerData[CUSTOM_MAX_PLAYERS][pFirstBuy] = strval(string);
			mysql_fetch_field_row(string, "FirstHouse", db_con4);
			gPlayerData[CUSTOM_MAX_PLAYERS][pFirstHouse] = strval(string);
			mysql_fetch_field_row(string, "FirstDescription", db_con4);
			gPlayerData[CUSTOM_MAX_PLAYERS][pFirstDescription] = strval(string);
			mysql_fetch_field_row(string, "FirstAction", db_con4);
			gPlayerData[CUSTOM_MAX_PLAYERS][pFirstAction] = strval(string);
			mysql_fetch_field_row(string, "FirstBankUse", db_con4);
			gPlayerData[CUSTOM_MAX_PLAYERS][pFirstBankUse] = strval(string);
			mysql_fetch_field_row(string, "FirstStats", db_con4);
			gPlayerData[CUSTOM_MAX_PLAYERS][pFirstStats] = strval(string);
			mysql_fetch_field_row(string, "FirstJail", db_con4);
			gPlayerData[CUSTOM_MAX_PLAYERS][pFirstJail] = strval(string);
			mysql_fetch_field_row(string, "FirstStudy", db_con4);
			gPlayerData[CUSTOM_MAX_PLAYERS][pFirstStudy] = strval(string);
			mysql_fetch_field_row(string, "CrashAngle", db_con4);
			gPlayerData[CUSTOM_MAX_PLAYERS][pCrashAngle] = floatstr(string);
			mysql_fetch_field_row(string, "HourAssist", db_con4);
			gPlayerData[CUSTOM_MAX_PLAYERS][pHourAssist] = strval(string);
			mysql_fetch_field_row(string, "JoinedFaction", db_con4);
			gPlayerData[CUSTOM_MAX_PLAYERS][pJoinedFaction] = strval(string);
			mysql_fetch_field_row(string, "HoursOnDuty", db_con4);
			gPlayerData[CUSTOM_MAX_PLAYERS][pHoursOnDuty] = strval(string);
			mysql_fetch_field_row(string, "HoursOnDutyHelper", db_con4);
			gPlayerData[CUSTOM_MAX_PLAYERS][pHoursOnDutyHelper] = strval(string);
			mysql_fetch_field_row(string, "WarnCooldown", db_con4);
			gPlayerData[CUSTOM_MAX_PLAYERS][pWarnCooldown] = strval(string);

			mysql_free_result(db_con4);

			format(string, sizeof(string), "[PAYDAY:] gPayDayLoop = %d, Player name: %s",  gPayDayLoop, gPlayerData[CUSTOM_MAX_PLAYERS][pName] );
			PayDayLog(string);

			format( string, sizeof(string), "SELECT * FROM `samp_users_keys` WHERE `PlayerName` = '%s' LIMIT 1", gPlayerData[CUSTOM_MAX_PLAYERS][pName] );
			mysql_query(string, PLAYER_DATA_LOAD_KEYS_MYSQL, CUSTOM_MAX_PLAYERS, db_con4);

			// format( string, sizeof(string), "SELECT * FROM `samp_users_other` WHERE `PlayerName` = '%s' ", gPlayerData[CUSTOM_MAX_PLAYERS][pName] );
			// mysql_query(string, PLAYER_DATA_LOAD_OTHER_MYSQL, CUSTOM_MAX_PLAYERS, db_con4);

			// format( string, sizeof(string), "SELECT * FROM `samp_users_items` WHERE `PlayerName` = '%s' ", gPlayerData[CUSTOM_MAX_PLAYERS][pName] );
			// mysql_query(string, PLAYER_DATA_LOAD_ITEMS_MYSQL, CUSTOM_MAX_PLAYERS, db_con4);

			// format( string, sizeof(string), "SELECT * FROM `samp_users_items2` WHERE `PlayerName` = '%s' ", gPlayerData[CUSTOM_MAX_PLAYERS][pName] );
			// mysql_query(string, PLAYER_DATA_LOAD_ITEMS2_MYSQL, CUSTOM_MAX_PLAYERS, db_con4);

			// format( string, sizeof(string), "SELECT * FROM `samp_users_items3` WHERE `PlayerName` = '%s' ", gPlayerData[CUSTOM_MAX_PLAYERS][pName]) ;
			// mysql_query(string, PLAYER_DATA_LOAD_ITEMS3_MYSQL, CUSTOM_MAX_PLAYERS, db_con4);

			// format( string, sizeof(string), "SELECT * FROM `samp_users_jobs` WHERE `PlayerName` = '%s' ", gPlayerData[CUSTOM_MAX_PLAYERS][pName] );
			// mysql_query(string, PLAYER_DATA_LOAD_JOB_MYSQL, CUSTOM_MAX_PLAYERS, db_con4);

			// format( string, sizeof(string), "SELECT * FROM `samp_users_lic` WHERE `PlayerName` = '%s' ", gPlayerData[CUSTOM_MAX_PLAYERS][pName] );
			// mysql_query(string, PLAYER_DATA_LOAD_LIC_MYSQL, CUSTOM_MAX_PLAYERS, db_con4);

			// format( string, sizeof(string), "SELECT * FROM `samp_users_notes` WHERE `PlayerName` = '%s' ", gPlayerData[CUSTOM_MAX_PLAYERS][pName] );
			// mysql_query(string, PLAYER_DATA_LOAD_NOTES_MYSQL, CUSTOM_MAX_PLAYERS, db_con4);

			// format( string, sizeof(string), "SELECT * FROM `samp_users_vip` WHERE `PlayerName` = '%s'", gPlayerData[CUSTOM_MAX_PLAYERS][pName] );
			// mysql_query(string, PLAYER_DATA_LOAD_VIP_MYSQL, CUSTOM_MAX_PLAYERS, db_con4);

			// format( string, sizeof(string), "SELECT * FROM `samp_users_other2` WHERE `PlayerName` = '%s'", gPlayerData[CUSTOM_MAX_PLAYERS][pName] );
			// mysql_query(string, PLAYER_DATA_LOAD_OTHER2_MYSQL, CUSTOM_MAX_PLAYERS, db_con4);
		}
		case PLAYER_DATA_LOAD_FIRST_MYSQL:
		{
			#if defined DEBUG
				printf("[DEBUG:][PLAYER_LOAD_FIRST_MYSQL] pid = %d, pname = %s", playerid, PlayerNameTMP);
			#endif
			ClearScreen(playerid);
			if(!mysql_store_result(db_con4))
			{
				ErrorLog("[ERROR:] Can't store result on PLAYER_DATA_LOAD_FIRST_MYSQL");
				return 1;
			}

			/* Check if row exist */
			if(mysql_num_rows(db_con4) == 0)
			{
				format( string, sizeof(string), "{FFFFFF}Witaj na serwerze WParty !\n\n" );
				strcat( string, "Aby siê zalogowaæ wpisz swoje has³o do postaci.\n\n\n" );
				strcat( string, "{F52222}Ta nazwa postaci nie jest zarejestrowana !\nJeœli nie posiadasz jeszcze postaci musisz wpierw zarejestrowaæ swoje konto\nna forum WParty.pl a nastêpnei utworzyæ postaæ\npostêpuj¹æ wed³ug podanych tam wskazówek.\n\n" );
				strcat( string, "{FAEC25}Jeœli zapomnia³eœ has³a do postaci mo¿esz je zmieniæ loguj¹c siê na forum\na nastêpnie przechodz¹c do panelu zarz¹dzania postaciami.\n\n\n" );
				strcat( string, "{FFFFFF}Wpisz has³o:" );
				gPlayerData[playerid][pLoading] = 0;
				ShowPlayerDialog(playerid, DIALOG_LOGIN, DIALOG_STYLE_PASSWORD, "Logowanie", string, "Zaloguj", "");
				mysql_free_result(db_con4);
				return 1;
			}
			mysql_fetch_row_format(db_result, "|", db_con4);
			split2(db_result, arrCoords, '|');
			mysql_fetch_field_row(string, "Key", db_con2);
			format(arrCoords[0], 512, string);
			mysql_free_result(db_con4);
			if(strlen(arrCoords[1]) < 5)
			{
				format( string, sizeof(string), "{FFFFFF}Witaj na serwerze WParty !\n\n" );
				strcat( string, "Aby siê zalogowaæ wpisz swoje has³o do postaci.\n\n\n" );
				strcat( string, "{F52222}Ta nazwa postaci jest za krótka !\nAby utworzyæ inn¹ postaæ o d³u¿ej nazwie przejdŸ na strone WParty.pl a nastêpnie w panelu zarz¹dzania postaciami utwórz\nnow¹ postaæ o odpowiednio d³ugiej nazwie.\n\n" );
				strcat( string, "{FAEC25}Jeœli zapomnia³eœ has³a do postaci mo¿esz je zmieniæ loguj¹c siê na forum\na nastêpnie przechodz¹c do panelu zarz¹dzania postaciami.\n\n\n" );
				strcat( string, "{FFFFFF}Wpisz has³o:" );
				gPlayerData[playerid][pLoading] = 0;
				ShowPlayerDialog(playerid, DIALOG_LOGIN, DIALOG_STYLE_PASSWORD, "Logowanie", string, "Zaloguj", "");
				return 1;
			}
			WP_Hash(gPasswd[playerid], 145, gPasswd[playerid]);
			if(strcmp(arrCoords[0], gPasswd[playerid], true) != 0 || strlen(gPasswd[playerid]) <= 0)
			{
				format( string, sizeof(string), "{FFFFFF}Witaj na serwerze WParty !\n\n" );
				strcat( string, "Aby siê zalogowaæ wpisz swoje has³o do postaci.\n\n\n" );
				strcat( string, "{FAEC25}Jeœli zapomnia³eœ has³a do postaci mo¿esz je zmieniæ loguj¹c siê na forum\na nastêpnie przechodz¹c do panelu zarz¹dzania postaciami.\n\n\n" );
				strcat( string, "{F52222}B£ÊDNE HAS£O !\n" );
				strcat( string, "{FFFFFF}Wpisz ponownie has³o:" );
				gPlayerVars[playerid][mPassTries]++;
				if(gPlayerVars[playerid][mPassTries] == 3)
				{
					KickPlayer(playerid, "System", "Wykorzysta³eœ 3 próby logowania");
					return 1;
				}
				gPlayerData[playerid][pLoading] = 0;
				ShowPlayerDialog(playerid, DIALOG_LOGIN, DIALOG_STYLE_PASSWORD, "Logowanie", string, "Zaloguj", "");
				return 1;
			}
			if( strcmp( gPlayerData[playerid][pSName], PlayerNameTMP, false, 32 ) != 0 )
			{
				format( string, sizeof(string), "{FFFFFF}Witaj na serwerze WParty !\n\n" );
				strcat( string, "Aby siê zalogowaæ wpisz swoje has³o do postaci.\n\n\n" );
				strcat( string, "{FAEC25}Jeœli zapomnia³eœ has³a do postaci mo¿esz je zmieniæ loguj¹c siê na forum\na nastêpnie przechodz¹c do panelu zarz¹dzania postaciami.\n\n\n" );
				strcat( string, "{F52222}NIEZGODNA NAZWA U¯YTKOWNIKA !\n" );
				strcat( string, "{FFFFFF}Wpisz ponownie has³o:" );
				gPlayerData[playerid][pLoading] = 0;
				ShowPlayerDialog(playerid, DIALOG_LOGIN, DIALOG_STYLE_PASSWORD, "Logowanie", string, "Zaloguj", "");
				return 1;
			}

			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Czekaj, trwa ³adowanie danych...");

			format(string, sizeof(string), "SELECT `Key`,`ID`,`PlayerName`,`Level`,`AdminLevel`,`DonateRank`,`Registered`,`Sex`,`Age`,`Experience`,`Money`,`Bank`,`Skin`,`PlayingHours`,`AllowedPayday`,`PayCheck`,`Faction`,`Rank`,`Banned`");
			strcat( string, ",`Warnings`,`Jailed`,`JailTime`,`CrashX`,`CrashY`,`CrashZ`,`CrashInt`,`CrashW`,`Crashed`,`Wins`,`Loses`,`InvWeapon`,`InvAmmo`,`Tutorial`,`Moderator`,`WantedLvl`,`FirstCar`,`FirstReanimation`,`FirstPhone`,`FirstLeader`" );
			strcat( string, ",`CrashAngle`,`HourAssist`,`JoinedFaction`,`HoursOnDuty`,`HoursOnDutyHelper`,`WarnCooldown`,`SpeedLimiter`,`AdminDuty`,`CharDescription`,`CharDescriptionColor`, `FirstJob`, `FirstID`, `FirstBuy`, `FirstHouse`, `FirstDescription`" );
			strcat( string, ", `FirstAction`, `FirstBankUse`, `FirstStats`, `FirstJail`, `FirstStudy`" );
			format( string, sizeof(string), "%s FROM `samp_users` WHERE `PlayerName` = '%s' LIMIT 1", string, PlayerNameTMP);
			mysql_query(string, PLAYER_DATA_LOAD_USER_MYSQL, playerid, db_con4);

			// format(string, sizeof(string), "SELECT * FROM `samp_users_keys` WHERE `PlayerName` = '%s' ", PlayerNameTMP);
			// mysql_query(string, PLAYER_DATA_LOAD_KEYS_MYSQL, playerid, db_con4);

			// format(string, sizeof(string), "SELECT * FROM `samp_users_other` WHERE `PlayerName` = '%s' ", PlayerNameTMP);
			// mysql_query(string, PLAYER_DATA_LOAD_OTHER_MYSQL, playerid, db_con4);

			// format(string, sizeof(string), "SELECT * FROM `samp_users_items` WHERE `PlayerName` = '%s' ", PlayerNameTMP);
			// mysql_query(string, PLAYER_DATA_LOAD_ITEMS_MYSQL, playerid, db_con4);

			// format(string, sizeof(string), "SELECT * FROM `samp_users_items2` WHERE `PlayerName` = '%s' ", PlayerNameTMP);
			// mysql_query(string, PLAYER_DATA_LOAD_ITEMS2_MYSQL, playerid, db_con4);

			// format(string, sizeof(string), "SELECT * FROM `samp_users_items3` WHERE `PlayerName` = '%s' ", PlayerNameTMP);
			// mysql_query(string, PLAYER_DATA_LOAD_ITEMS3_MYSQL, playerid, db_con4);

			// format(string, sizeof(string), "SELECT * FROM `samp_users_jobs` WHERE `PlayerName` = '%s' ", PlayerNameTMP);
			// mysql_query(string, PLAYER_DATA_LOAD_JOB_MYSQL, playerid, db_con4);

			// format(string, sizeof(string), "SELECT * FROM `samp_users_lic` WHERE `PlayerName` = '%s' ", PlayerNameTMP);
			// mysql_query(string, PLAYER_DATA_LOAD_LIC_MYSQL, playerid, db_con4);

			// format(string, sizeof(string), "SELECT * FROM `samp_users_notes` WHERE `PlayerName` = '%s' ", PlayerNameTMP);
			// mysql_query(string, PLAYER_DATA_LOAD_NOTES_MYSQL, playerid, db_con4);

			// format(string, sizeof(string), "SELECT * FROM `samp_users_vip` WHERE `PlayerName` = '%s'", PlayerNameTMP);
			// mysql_query(string, PLAYER_DATA_LOAD_VIP_MYSQL, playerid, db_con4);

			// format(string, sizeof(string), "SELECT * FROM `samp_users_other2` WHERE `PlayerName` = '%s'", PlayerNameTMP);
			// mysql_query(string, PLAYER_DATA_LOAD_OTHER2_MYSQL, playerid, db_con4);

			return 1;
		}
		case PLAYER_DATA_LOAD_USER_MYSQL:
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Czekaj, trwa ³adowanie danych [dane podstawowe]...");

			if( !mysql_store_result(db_con4) )
			{
				ErrorLog("[ERROR:] Can't store result on PLAYER_DATA_LOAD_USER_MYSQL");
				if(playerid < CUSTOM_MAX_PLAYERS)
				{
					SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Wyst¹pi³ b³¹d przy ³adowaniu danych twojego konta. Jeœli problem bêdzie siê powtarza³ skontaktuj siê z administratorem" );
					return 1;
				}
			}
			mysql_fetch_row_format(db_result, "|", db_con4);
			mysql_fetch_field_row(gPlayerData[playerid][pName], "PlayerName", db_con4);
			mysql_fetch_field_row(string, "Level", db_con4);
			gPlayerData[playerid][pLevel] = strval(string);
			mysql_fetch_field_row(string, "AdminLevel", db_con4);
			gPlayerData[playerid][pAdmin] = strval(string);
			mysql_fetch_field_row(string, "DonateRank", db_con4);
			gPlayerData[playerid][pDonateRank] = strval(string);
			mysql_fetch_field_row(string, "Registered", db_con4);
			gPlayerData[playerid][pRegistered] = strval(string);
			mysql_fetch_field_row(string, "Sex", db_con4);
			gPlayerData[playerid][pSex] = strval(string);
			mysql_fetch_field_row(string, "Age", db_con4);
			gPlayerData[playerid][pAge] = strval(string);
			mysql_fetch_field_row(string, "Experience", db_con4);
			gPlayerData[playerid][pExp] = strval(string);
			mysql_fetch_field_row(string, "Money", db_con4);
			gPlayerData[playerid][pCash] = strval(string);
			mysql_fetch_field_row(string, "Bank", db_con4);
			gPlayerData[playerid][pBank] = strval(string);
			mysql_fetch_field_row(string, "Skin", db_con4);
			gPlayerData[playerid][pSkin] = strval(string);
			mysql_fetch_field_row(string, "PlayingHours", db_con4);
			gPlayerData[playerid][pPlayingHours] = strval(string);
			mysql_fetch_field_row(string, "AllowedPayday", db_con4);
			gPlayerData[playerid][pAllowedPayday] = strval(string);
			mysql_fetch_field_row(string, "PayCheck", db_con4);
			gPlayerData[playerid][pPayCheck] = strval(string);
			mysql_fetch_field_row(string, "Faction", db_con4);
			gPlayerData[playerid][pFaction] = strval(string);
			mysql_fetch_field_row(string, "Rank", db_con4);
			gPlayerData[playerid][pRank] = strval(string);
			mysql_fetch_field_row(string, "Banned", db_con4);
			gPlayerData[playerid][pBanned] = strval(string);
			mysql_fetch_field_row(string, "Warnings", db_con4);
			gPlayerData[playerid][pWarnings] = strval(string);
			mysql_fetch_field_row(string, "Jailed", db_con4);
			gPlayerData[playerid][pJailed] = strval(string);
			mysql_fetch_field_row(string, "JailTime", db_con4);
			gPlayerData[playerid][pJailTime] = strval(string);
			mysql_fetch_field_row(string, "CrashX", db_con4);
			gPlayerData[playerid][pCrashX] = floatstr(string);
			mysql_fetch_field_row(string, "CrashY", db_con4);
			gPlayerData[playerid][pCrashY] = floatstr(string);
			mysql_fetch_field_row(string, "CrashZ", db_con4);
			gPlayerData[playerid][pCrashZ] = floatstr(string);
			mysql_fetch_field_row(string, "CrashInt", db_con4);
			gPlayerData[playerid][pCrashInt] = strval(string);
			mysql_fetch_field_row(string, "CrashW", db_con4);
			gPlayerData[playerid][pCrashW] = strval(string);
			mysql_fetch_field_row(string, "Crashed", db_con4);
			gPlayerData[playerid][pCrashed] = strval(string);
			mysql_fetch_field_row(string, "Wins", db_con4);
			gPlayerData[playerid][pWins] = strval(string);
			mysql_fetch_field_row(string, "Loses", db_con4);
			gPlayerData[playerid][pLoses] = strval(string);
			mysql_fetch_field_row(string, "InvWeapon", db_con4);
			gPlayerData[playerid][pInvWeapon] = strval(string);
			mysql_fetch_field_row(string, "InvAmmo", db_con4);
			gPlayerData[playerid][pInvAmmo] = strval(string);
			mysql_fetch_field_row(string, "Moderator", db_con4);
			gPlayerData[playerid][pModerator] = strval(string);
			mysql_fetch_field_row(string, "WantedLvl", db_con4);
			gPlayerData[playerid][pWantedLvl] = strval(string);
			mysql_fetch_field_row(string, "FirstCar", db_con4);
			gPlayerData[playerid][pFirstCar] = strval(string);
			mysql_fetch_field_row(string, "FirstReanimation", db_con4);
			gPlayerData[playerid][pFirstReanimation] = strval(string);
			mysql_fetch_field_row(string, "FirstPhone", db_con4);
			gPlayerData[playerid][pFirstPhone] = strval(string);
			mysql_fetch_field_row(string, "FirstLeader", db_con4);
			gPlayerData[playerid][pFirstLeader] = strval(string);
			mysql_fetch_field_row(string, "FirstJob", db_con4);
			gPlayerData[playerid][pFirstJob] = strval(string);
			mysql_fetch_field_row(string, "FirstID", db_con4);
			gPlayerData[playerid][pFirstID] = strval(string);
			mysql_fetch_field_row(string, "FirstBuy", db_con4);
			gPlayerData[playerid][pFirstBuy] = strval(string);
			mysql_fetch_field_row(string, "FirstHouse", db_con4);
			gPlayerData[playerid][pFirstHouse] = strval(string);
			mysql_fetch_field_row(string, "FirstDescription", db_con4);
			gPlayerData[playerid][pFirstDescription] = strval(string);
			mysql_fetch_field_row(string, "FirstAction", db_con4);
			gPlayerData[playerid][pFirstAction] = strval(string);
			mysql_fetch_field_row(string, "FirstBankUse", db_con4);
			gPlayerData[playerid][pFirstBankUse] = strval(string);
			mysql_fetch_field_row(string, "FirstStats", db_con4);
			gPlayerData[playerid][pFirstStats] = strval(string);
			mysql_fetch_field_row(string, "FirstJail", db_con4);
			gPlayerData[playerid][pFirstJail] = strval(string);
			mysql_fetch_field_row(string, "FirstStudy", db_con4);
			gPlayerData[playerid][pFirstStudy] = strval(string);
			mysql_fetch_field_row(string, "CrashAngle", db_con4);
			gPlayerData[playerid][pCrashAngle] = floatstr(string);
			mysql_fetch_field_row(string, "HourAssist", db_con4);
			gPlayerData[playerid][pHourAssist] = strval(string);
			mysql_fetch_field_row(string, "JoinedFaction", db_con4);
			gPlayerData[playerid][pJoinedFaction] = strval(string);
			mysql_fetch_field_row(string, "HoursOnDuty", db_con4);
			gPlayerData[playerid][pHoursOnDuty] = strval(string);
			mysql_fetch_field_row(string, "HoursOnDutyHelper", db_con4);
			gPlayerData[playerid][pHoursOnDutyHelper] = strval(string);
			mysql_fetch_field_row(string, "WarnCooldown", db_con4);
			gPlayerData[playerid][pWarnCooldown] = strval(string);
			mysql_fetch_field_row(string, "AdminDuty", db_con4);
			AdminDuty[playerid] = strval(string);
			mysql_fetch_field_row(gPlayerData[playerid][pCharDescription], "CharDescription", db_con4);
			mysql_fetch_field_row(string, "CharDescriptionColor", db_con4);
			gPlayerData[playerid][pCharDescriptionColor] = strval(string);

			mysql_free_result(db_con4);

			format( string, sizeof(string), "SELECT * FROM `samp_users_keys` WHERE `PlayerName` = '%s' ", gPlayerData[playerid][pName] );
			mysql_query(string, PLAYER_DATA_LOAD_KEYS_MYSQL, playerid, db_con4);
		}
		case PLAYER_DATA_LOAD_KEYS_MYSQL:
		{
			// printf("[DEBUG:][PLAYER_LOAD_KEYS_MYSQL] pid = %d, pname = %s", playerid, gPlayerData[playerid][pName]);
			if(playerid != CUSTOM_MAX_PLAYERS)
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Czekaj, trwa ³adowanie danych [klucze]...");
			if(!mysql_store_result(db_con4))
			{
				ErrorLog("[ERROR:] Can't store result on PLAYER_DATA_LOAD_KEYS_MYSQL");
				if(playerid < CUSTOM_MAX_PLAYERS)
				{
					SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Wyst¹pi³ b³¹d przy ³adowaniu danych twojego konta. Jeœli problem bêdzie siê powtarza³ skontaktuj siê z administratorem" );
					return 1;
				}
			}
			if(mysql_num_rows(db_con4) == 0)
			{
				ErrorLog("[ERROR:] No record on PLAYER_DATA_LOAD_KEYS_MYSQL");
				mysql_free_result(db_con4);
				if(playerid < CUSTOM_MAX_PLAYERS)
				{
					format(string, sizeof(string), "INSERT INTO `samp_users_keys` (`PlayerName`) VALUES ('%s')", PlayerNameTMP);
					mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
				}
			}
			else
			{
				mysql_fetch_row_format(db_result, "|", db_con4);

				mysql_free_result(db_con4);
			}
			format( string, sizeof(string), "SELECT * FROM `samp_users_other` WHERE `PlayerName` = '%s' LIMIT 1", gPlayerData[playerid][pName] );
			mysql_query(string, PLAYER_DATA_LOAD_OTHER_MYSQL, playerid, db_con4);
		}
		case PLAYER_DATA_LOAD_OTHER_MYSQL:
		{
			// printf("[DEBUG:][PLAYER_LOAD_OTHER_MYSQL] pid = %d, pname = %s", playerid, gPlayerData[playerid][pName]);
			if(playerid != CUSTOM_MAX_PLAYERS)
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Czekaj, trwa ³adowanie danych [dane podstawowe]...");
			if(!mysql_store_result(db_con4))
			{
				ErrorLog("[ERROR:] Can't store result on PLAYER_DATA_LOAD_OTHER_MYSQL");
				if(playerid < CUSTOM_MAX_PLAYERS)
				{
					SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Wyst¹pi³ b³¹d przy ³adowaniu danych twojego konta. Jeœli problem bêdzie siê powtarza³ skontaktuj siê z administratorem" );
					return 1;
				}
			}
			if(mysql_num_rows(db_con4) == 0)
			{
				mysql_free_result(db_con4);
				if(playerid < CUSTOM_MAX_PLAYERS)
				{
					format(string, sizeof(string), "INSERT INTO `samp_users_other` (`PlayerName`) VALUES ('%s')", PlayerNameTMP);
					mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
				}
			}
			else
			{
				mysql_fetch_row_format(db_result, "|", db_con4);

				mysql_fetch_field_row(string, "ListNumber", db_con4);
				gPlayerData[playerid][pListNumber] = strval(string);
				mysql_fetch_field_row(string, "Donator", db_con4);
				gPlayerData[playerid][pDonator] = strval(string);
				mysql_fetch_field_row(string, "Drugs", db_con4);
				gPlayerData[playerid][pDrugs] = strval(string);
				mysql_fetch_field_row(string, "DrugsEffect", db_con4);
				gPlayerData[playerid][pDrugsEffect] = strval(string);
				mysql_fetch_field_row(string, "DrugsTaken", db_con4);
				gPlayerData[playerid][pDrugsTaken] = strval(string);
				mysql_fetch_field_row(string, "DrugsAddicted", db_con4);
				gPlayerData[playerid][pDrugsAddicted] = strval(string);
				mysql_fetch_field_row(string, "Materials", db_con4);
				gPlayerData[playerid][pMaterials] = strval(string);
				mysql_fetch_field_row(string, "Goggles", db_con4);
				gPlayerData[playerid][pGoggles] = strval(string);
				mysql_fetch_field_row(string, "Cost", db_con4);
				gPlayerData[playerid][pCost] = strval(string);
				mysql_fetch_field_row(string, "Ticket", db_con4);
				gPlayerData[playerid][pTicket] = strval(string);
				mysql_fetch_field_row(string, "HP", db_con4);
				gPlayerData[playerid][pHP] = strval(string);
				mysql_fetch_field_row(string, "Armour", db_con4);
				gPlayerData[playerid][pArmour] = strval(string);
				mysql_fetch_field_row(string, "Head", db_con4);
				gPlayerData[playerid][pHead] = strval(string);
				mysql_fetch_field_row(string, "Torso", db_con4);
				gPlayerData[playerid][pTorso] = strval(string);
				mysql_fetch_field_row(string, "Legs", db_con4);
				gPlayerData[playerid][pLegs] = strval(string);
				mysql_fetch_field_row(string, "Detoks", db_con4);
				gPlayerData[playerid][pDetoks] = strval(string);
				mysql_fetch_field_row(string, "WSlot0", db_con4);
				gPlayerData[playerid][pWSlot0] = strval(string);
				mysql_fetch_field_row(string, "WSlot0Ammo", db_con4);
				gPlayerData[playerid][pWSlot0Ammo] = strval(string);
				mysql_fetch_field_row(string, "WSlot1", db_con4);
				gPlayerData[playerid][pWSlot1] = strval(string);
				mysql_fetch_field_row(string, "WSlot1Ammo", db_con4);
				gPlayerData[playerid][pWSlot1Ammo] = strval(string);
				mysql_fetch_field_row(string, "WSlot2", db_con4);
				gPlayerData[playerid][pWSlot2] = strval(string);
				mysql_fetch_field_row(string, "WSlot2Ammo", db_con4);
				gPlayerData[playerid][pWSlot2Ammo] = strval(string);
				mysql_fetch_field_row(string, "WSlot3", db_con4);
				gPlayerData[playerid][pWSlot3] = strval(string);
				mysql_fetch_field_row(string, "WSlot3Ammo", db_con4);
				gPlayerData[playerid][pWSlot3Ammo] = strval(string);
				mysql_fetch_field_row(string, "WSlot4", db_con4);
				gPlayerData[playerid][pWSlot4] = strval(string);
				mysql_fetch_field_row(string, "WSlot4Ammo", db_con4);
				gPlayerData[playerid][pWSlot4Ammo] = strval(string);
				mysql_fetch_field_row(string, "WSlot5", db_con4);
				gPlayerData[playerid][pWSlot5] = strval(string);
				mysql_fetch_field_row(string, "WSlot5Ammo", db_con4);
				gPlayerData[playerid][pWSlot5Ammo] = strval(string);
				mysql_fetch_field_row(string, "WSlot6", db_con4);
				gPlayerData[playerid][pWSlot6] = strval(string);
				mysql_fetch_field_row(string, "WSlot6Ammo", db_con4);
				gPlayerData[playerid][pWSlot6Ammo] = strval(string);
				mysql_fetch_field_row(string, "PickupEventPickupStatus1", db_con4);
				gPlayerData[playerid][mPickupEventPickupStatus][0] = strval(string);
				mysql_fetch_field_row(string, "PickupEventPickupStatus2", db_con4);
				gPlayerData[playerid][mPickupEventPickupStatus][1] = strval(string);
				mysql_fetch_field_row(string, "PickupEventPickupStatus3", db_con4);
				gPlayerData[playerid][mPickupEventPickupStatus][2] = strval(string);
				mysql_fetch_field_row(string, "PickupEventPickupStatus4", db_con4);
				gPlayerData[playerid][mPickupEventPickupStatus][3] = strval(string);
				mysql_fetch_field_row(string, "PickupEventPickupStatus5", db_con4);
				gPlayerData[playerid][mPickupEventPickupStatus][4] = strval(string);
				mysql_fetch_field_row(string, "PickupEventPickupStatus6", db_con4);
				gPlayerData[playerid][mPickupEventPickupStatus][5] = strval(string);
				mysql_fetch_field_row(string, "PickupEventPickupStatus7", db_con4);
				gPlayerData[playerid][mPickupEventPickupStatus][6] = strval(string);
				mysql_fetch_field_row(string, "PickupEventPickupStatus8", db_con4);
				gPlayerData[playerid][mPickupEventPickupStatus][7] = strval(string);
				mysql_fetch_field_row(string, "PickupEventPickupStatus9", db_con4);
				gPlayerData[playerid][mPickupEventPickupStatus][8] = strval(string);
				mysql_fetch_field_row(string, "PickupEventPickupStatus10", db_con4);
				gPlayerData[playerid][mPickupEventPickupStatus][9] = strval(string);
				mysql_fetch_field_row(string, "PickupEventPickupStatus11", db_con4);
				gPlayerData[playerid][mPickupEventPickupStatus][10] = strval(string);
				mysql_fetch_field_row(string, "PickupEventPickupStatus12", db_con4);
				gPlayerData[playerid][mPickupEventPickupStatus][11] = strval(string);
				mysql_fetch_field_row(string, "PickupEventPickupStatus13", db_con4);
				gPlayerData[playerid][mPickupEventPickupStatus][12] = strval(string);
				mysql_fetch_field_row(string, "PickupEventPickupStatus14", db_con4);
				gPlayerData[playerid][mPickupEventPickupStatus][13] = strval(string);
				mysql_fetch_field_row(string, "PickupEventPickupStatus15", db_con4);
				gPlayerData[playerid][mPickupEventPickupStatus][14] = strval(string);
				mysql_fetch_field_row(string, "PickupEventPickupStatus16", db_con4);
				gPlayerData[playerid][mPickupEventPickupStatus][15] = strval(string);
				mysql_fetch_field_row(string, "PickupEventPickupStatus17", db_con4);
				gPlayerData[playerid][mPickupEventPickupStatus][16] = strval(string);
				mysql_fetch_field_row(string, "PickupEventPickupStatus18", db_con4);
				gPlayerData[playerid][mPickupEventPickupStatus][17] = strval(string);
				mysql_fetch_field_row(string, "PickupEventPickupStatus19", db_con4);
				gPlayerData[playerid][mPickupEventPickupStatus][18] = strval(string);
				mysql_fetch_field_row(string, "PickupEventPickupStatus20", db_con4);
				gPlayerData[playerid][mPickupEventPickupStatus][19] = strval(string);
				mysql_fetch_field_row(string, "PickupEventRewardReceived", db_con4);
				gPlayerData[playerid][mPickupEventRewardReceived] = strval(string);
				mysql_fetch_field_row(string, "PickupEventID", db_con4);
				gPlayerData[playerid][mPickupEventID] = strval(string);
				mysql_fetch_field_row(string, "RPCount", db_con4);
				gPlayerData[playerid][pRPCount] = strval(string);
				mysql_fetch_field_row(string, "DeathCount", db_con4);
				gPlayerData[playerid][pDeathCount] = strval(string);
				mysql_fetch_field_row(string, "Score", db_con4);
				gPlayerData[playerid][pScore] = strval(string);
				mysql_fetch_field_row(string, "MechanicCoolDown", db_con4);
				gPlayerData[playerid][pMechanicCoolDown] = strval(string);
				mysql_fetch_field_row(string, "FirstATest", db_con4);
				gPlayerData[playerid][pFirstATest] = strval(string);
				mysql_fetch_field_row(string, "FirstBTest", db_con4);
				gPlayerData[playerid][pFirstBTest] = strval(string);
				mysql_fetch_field_row(string, "FirstCETest", db_con4);
				gPlayerData[playerid][pFirstCETest] = strval(string);
				mysql_fetch_field_row(string, "MaxWeight", db_con4);
				gPlayerData[playerid][pMaxWeight] = strval(string);
				mysql_fetch_field_row(string, "Hunger", db_con4);
				gPlayerData[playerid][pHunger] = strval(string);
				mysql_fetch_field_row(string, "Thirst", db_con4);
				gPlayerData[playerid][pThirst] = strval(string);
				mysql_fetch_field_row(string, "Poison", db_con4);
				gPlayerData[playerid][pPoison] = strval(string);
				mysql_fetch_field_row(string, "Fat", db_con4);
				gPlayerData[playerid][pFat] = strval(string);
				mysql_fetch_field_row(string, "Stomach", db_con4);
				gPlayerData[playerid][pStomach] = strval(string);
				mysql_fetch_field_row(string, "Vitamins", db_con4);
				gPlayerData[playerid][pVitamins] = strval(string);
				mysql_fetch_field_row(string, "Energy", db_con4);
				gPlayerData[playerid][pEnergy] = strval(string);
				mysql_fetch_field_row(string, "Drunk", db_con4);
				gPlayerData[playerid][pDrunk] = strval(string);
				mysql_fetch_field_row(string, "Narcotic", db_con4);
				gPlayerData[playerid][pNarcotic] = strval(string);
				mysql_fetch_field_row(string, "ShowHealthBars", db_con4);
				gPlayerData[playerid][pShowHealthBars] = strval(string);
				mysql_fetch_field_row(string, "SubMealEaten", db_con4);
				gPlayerData[playerid][pSubMealEaten] = strval(string);
				mysql_fetch_field_row(string, "OOCChanell", db_con4);
				gPlayerData[playerid][pOOCChanell] = strval(string);
				mysql_fetch_field_row(string, "TestAreaTimeLeft", db_con4);
				gPlayerData[playerid][pTestAreaTimeLeft] = strval(string);
				mysql_fetch_field_row(string, "NewVersion", db_con4);
				gPlayerData[playerid][pNewVersion] = strval(string);
				mysql_fetch_field_row(string, "PainKiller", db_con4);
				gPlayerData[playerid][pPainKiller] = strval(string);
				mysql_fetch_field_row(string, "Slimming", db_con4);
				gPlayerData[playerid][pSlimming] = strval(string);
				mysql_fetch_field_row(string, "StomachDrops", db_con4);
				gPlayerData[playerid][pStomachDrops] = strval(string);
				mysql_fetch_field_row(string, "AchieveTickets", db_con4);
				gPlayerData[playerid][pAchieveTickets] = strval(string);
				mysql_fetch_field_row(string, "AchieveArrests", db_con4);
				gPlayerData[playerid][pAchieveArrests] = strval(string);
				mysql_fetch_field_row(string, "AchieveDistance", db_con4);
				gPlayerData[playerid][pAchieveDistance] = strval(string);
				mysql_fetch_field_row(string, "BankOld", db_con4);
				gPlayerData[playerid][pBankOld] = strval(string);
				mysql_fetch_field_row(string, "BankIncome", db_con4);
				gPlayerData[playerid][pBankIncome] = strval(string);
				mysql_fetch_field_row(string, "BankLoose", db_con4);
				gPlayerData[playerid][pBankLoose] = strval(string);
				mysql_fetch_field_row(string, "BankNew", db_con4);
				gPlayerData[playerid][pBankNew] = strval(string);
				mysql_fetch_field_row(string, "PayDayMessage", db_con4);
				gPlayerData[playerid][pPayDayMessage] = strval(string);
				mysql_fetch_field_row(string, "Faction2", db_con4);
				gPlayerData[playerid][pFaction2] = strval(string);
				mysql_fetch_field_row(string, "Rank2", db_con4);
				gPlayerData[playerid][pRank2] = strval(string);
				mysql_fetch_field_row(string, "Quiz", db_con4);
				gPlayerData[playerid][pQuiz] = strval(string);
				mysql_fetch_field_row(string, "SetToDelete", db_con4);
				gPlayerData[playerid][pSetToDelete] = strval(string);
				mysql_fetch_field_row(string, "IsOnVacation", db_con4);
				gPlayerData[playerid][pIsOnVacation] = strval(string);

				mysql_free_result(db_con4);
			}
			format( string, sizeof(string), "SELECT * FROM `samp_users_items` WHERE `PlayerName` = '%s' LIMIT 1", gPlayerData[playerid][pName] );
			mysql_query(string, PLAYER_DATA_LOAD_ITEMS_MYSQL, playerid, db_con4);
		}
		case PLAYER_DATA_LOAD_JOB_MYSQL:
		{
			// printf("[DEBUG:][PLAYER_LOAD_JOB_MYSQL] pid = %d, pname = %s", playerid, gPlayerData[playerid][pName]);
			if(playerid != CUSTOM_MAX_PLAYERS)
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Czekaj, trwa ³adowanie danych [prace]...");
			if( !mysql_store_result(db_con4) )
			{
				ErrorLog("[ERROR:] Can't store result on PLAYER_DATA_LOAD_JOB_MYSQL");
				if(playerid < CUSTOM_MAX_PLAYERS)
				{
					SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Wyst¹pi³ b³¹d przy ³adowaniu danych twojego konta. Jeœli problem bêdzie siê powtarza³ skontaktuj siê z administratorem" );
					return 1;
				}
			}
			if(mysql_num_rows(db_con4) == 0)
			{
				mysql_free_result(db_con4);
				if(playerid < CUSTOM_MAX_PLAYERS)
				{
					format(string, sizeof(string), "INSERT INTO `samp_users_jobs` (`PlayerName`) VALUES ('%s')", PlayerNameTMP);
					mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
				}
			}
			else
			{
				mysql_fetch_row_format(db_result, "|", db_con4);

				split2(db_result, arrCoords, '|');

				gPlayerData[playerid][pJob] = strval(arrCoords[0]);
				gPlayerData[playerid][pJobLvl] = strval(arrCoords[1]);
				gPlayerData[playerid][pMzgkJobLvl] = strval(arrCoords[2]);
				gPlayerData[playerid][pSweeperJobLvl] = strval(arrCoords[3]);
				gPlayerData[playerid][pCarJackerJobLvl] = strval(arrCoords[4]);
				gPlayerData[playerid][pMechanicJobLvl] = strval(arrCoords[5]);
				gPlayerData[playerid][pFarmerJobLvl] = strval(arrCoords[6]);
				gPlayerData[playerid][pBusJobPoints] = strval(arrCoords[7]);
				gPlayerData[playerid][pMzgkJobPoints] = strval(arrCoords[8]);
				gPlayerData[playerid][pSweeperJobPoints] = strval(arrCoords[9]);
				gPlayerData[playerid][pCarJackerJobPoints] = strval(arrCoords[10]);
				gPlayerData[playerid][pMechanicJobPoints] = strval(arrCoords[11]);
				gPlayerData[playerid][pFarmerJobPoints] = strval(arrCoords[12]);

				mysql_free_result(db_con4);
			}
			format( string, sizeof(string), "SELECT * FROM `samp_users_lic` WHERE `PlayerName` = '%s' LIMIT 1", gPlayerData[playerid][pName] );
			mysql_query(string, PLAYER_DATA_LOAD_LIC_MYSQL, playerid, db_con4);
			if(playerid < CUSTOM_MAX_PLAYERS)
			{
				switch( gPlayerData[playerid][pJob] )
				{
					case 13: JobProgress[playerid] = CreateProgressBar(550.0, 130.0, 55.5, 5.0, COLOR_LIGHTBLUE, float(11 + (gPlayerData[playerid][pJobLvl]*5)));
					case 14: JobProgress[playerid] = CreateProgressBar(550.0, 130.0, 55.5, 5.0, COLOR_LIGHTBLUE, float(11 + (gPlayerData[playerid][pMzgkJobLvl]*5)));
					case 15: JobProgress[playerid] = CreateProgressBar(550.0, 130.0, 55.5, 5.0, COLOR_LIGHTBLUE, float(11 + (gPlayerData[playerid][pSweeperJobLvl]*5)));
					case 18: JobProgress[playerid] = CreateProgressBar(550.0, 130.0, 55.5, 5.0, COLOR_LIGHTBLUE, float(15 + (gPlayerData[playerid][pFarmerJobLvl]*5)));
					default: JobProgress[playerid] = CreateProgressBar(550.0, 130.0, 55.5, 5.0, COLOR_LIGHTBLUE, float(11 + (gPlayerData[playerid][pJobLvl]*5)));
				}
			}
		}
		case PLAYER_DATA_LOAD_LIC_MYSQL:
		{
			// printf("[DEBUG:][PLAYER_LOAD_LIC_MYSQL] pid = %d, pname = %s", playerid, gPlayerData[playerid][pName]);
			if(playerid != CUSTOM_MAX_PLAYERS)
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Czekaj, trwa ³adowanie danych [licencje]...");
			if(!mysql_store_result(db_con4))
			{
				ErrorLog("[ERROR:] Can't store result on PLAYER_DATA_LOAD_LIC_MYSQL");
				if(playerid < CUSTOM_MAX_PLAYERS)
				{
					SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Wyst¹pi³ b³¹d przy ³adowaniu danych twojego konta. Jeœli problem bêdzie siê powtarza³ skontaktuj siê z administratorem" );
					return 1;
				}
			}
			if(mysql_num_rows(db_con4) == 0)
			{
				mysql_free_result(db_con4);
				if(playerid < CUSTOM_MAX_PLAYERS)
				{
					format(string, sizeof(string), "INSERT INTO `samp_users_lic` (`PlayerName`) VALUES ('%s')", PlayerNameTMP);
					mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
				}
			}
			else
			{
				mysql_fetch_row_format(db_result, "|", db_con4);

				split2(db_result, arrCoords, '|');

				gPlayerData[playerid][pBoatLic] = strval(arrCoords[2]);
				gPlayerData[playerid][pPlaneLic] = strval(arrCoords[3]);
				gPlayerData[playerid][pHeliLic] = strval(arrCoords[4]);
				gPlayerData[playerid][pWepLic] = strval(arrCoords[5]);
				gPlayerData[playerid][pPenaltyPointsA] = strval(arrCoords[6]);
				gPlayerData[playerid][pPenaltyPointsB] = strval(arrCoords[7]);
				gPlayerData[playerid][pPenaltyPointsCE] = strval(arrCoords[8]);

				mysql_free_result(db_con4);
			}
			format( string, sizeof(string), "SELECT * FROM `samp_users_notes` WHERE `PlayerName` = '%s' LIMIT 1", gPlayerData[playerid][pName] );
			mysql_query(string, PLAYER_DATA_LOAD_NOTES_MYSQL, playerid, db_con4);
		}
		case PLAYER_DATA_LOAD_NOTES_MYSQL:
		{
			// printf("[DEBUG:][PLAYER_LOAD_NOTES_MYSQL] pid = %d, pname = %s", playerid, gPlayerData[playerid][pName]);
			if(playerid != CUSTOM_MAX_PLAYERS)
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Czekaj, trwa ³adowanie danych [notatki]...");
			if(!mysql_store_result(db_con4))
			{
				ErrorLog("[ERROR:] Can't store result on PLAYER_DATA_LOAD_NOTES_MYSQL");
				if(playerid < CUSTOM_MAX_PLAYERS)
				{
					SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Wyst¹pi³ b³¹d przy ³adowaniu danych twojego konta. Jeœli problem bêdzie siê powtarza³ skontaktuj siê z administratorem" );
					return 1;
				}
			}
			if(mysql_num_rows(db_con4) == 0)
			{
				mysql_free_result(db_con4);
				if(playerid < CUSTOM_MAX_PLAYERS)
				{
					format(string, sizeof(string), "INSERT INTO `samp_users_notes` (`PlayerName`) VALUES ('%s')", PlayerNameTMP);
					mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
				}
			}
			else
			{
				mysql_fetch_row_format(db_result, "|", db_con4);

				split2(db_result, arrCoords, '|');

				strmid(gPlayerData[playerid][pNote1], arrCoords[0], 0, strlen(arrCoords[0])-1, 255);
				gPlayerData[playerid][pNote1s] = strval(arrCoords[1]);
				strmid(gPlayerData[playerid][pNote1], arrCoords[2], 0, strlen(arrCoords[2])-1, 255);
				gPlayerData[playerid][pNote1s] = strval(arrCoords[3]);
				strmid(gPlayerData[playerid][pNote1], arrCoords[4], 0, strlen(arrCoords[4])-1, 255);
				gPlayerData[playerid][pNote1s] = strval(arrCoords[5]);
				strmid(gPlayerData[playerid][pNote1], arrCoords[6], 0, strlen(arrCoords[6])-1, 255);
				gPlayerData[playerid][pNote1s] = strval(arrCoords[7]);
				strmid(gPlayerData[playerid][pNote1], arrCoords[8], 0, strlen(arrCoords[8])-1, 255);
				gPlayerData[playerid][pNote1s] = strval(arrCoords[9]);

				mysql_free_result(db_con4);
			}
			format( string, sizeof(string), "SELECT * FROM `samp_users_vip` WHERE `PlayerName` = '%s' LIMIT 1", gPlayerData[playerid][pName] );
			mysql_query(string, PLAYER_DATA_LOAD_VIP_MYSQL, playerid, db_con4);
		}
		case PLAYER_DATA_LOAD_VIP_MYSQL:
		{
			// printf("[DEBUG:][PLAYER_LOAD_VIP_MYSQL] pid = %d, pname = %s", playerid, gPlayerData[playerid][pName]);
			if(playerid != CUSTOM_MAX_PLAYERS)
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Czekaj, trwa ³adowanie danych [dane VIP'a]...");
			if(!mysql_store_result(db_con4))
			{
				ErrorLog("[ERROR:] Can't store result on PLAYER_DATA_LOAD_VIP_MYSQL");
				if(playerid < CUSTOM_MAX_PLAYERS)
				{
					SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Wyst¹pi³ b³¹d przy ³adowaniu danych twojego konta. Jeœli problem bêdzie siê powtarza³ skontaktuj siê z administratorem" );
					return 1;
				}
			}
			if(mysql_num_rows(db_con4) == 0)
			{
				mysql_free_result(db_con4);
				if(playerid < CUSTOM_MAX_PLAYERS)
				{
					format(string, sizeof(string), "INSERT INTO `samp_users_vip` (`PlayerName`) VALUES ('%s')", PlayerNameTMP);
					mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
				}

				gPlayerData[playerid][pVipCar] = 0;
				gPlayerData[playerid][pVipAFK] = 0;
				gPlayerData[playerid][pVipAFKT] = 0;
				gPlayerData[playerid][pVipExp] = 0;
				gPlayerData[playerid][pVipExpT] = 0;
				gPlayerData[playerid][pCharacterDeath] = 0;
				gPlayerData[playerid][pCharacterDying] = 0;
				gPlayerData[playerid][pVipItem] = 0;
				gPlayerData[playerid][pAccountOwnerID] = 0;
				gPlayerData[playerid][pVipGarage] = 0;
				gPlayerData[playerid][pVipGarageBig] = 0;
				gPlayerData[playerid][pVipRedNeon] = 0;
				gPlayerData[playerid][pVipBlueNeon] = 0;
				gPlayerData[playerid][pVipGreenNeon] = 0;
				gPlayerData[playerid][pVipYellowNeon] = 0;
				gPlayerData[playerid][pVipPinkNeon] = 0;
				gPlayerData[playerid][pVipWhiteNeon] = 0;
				gPlayerData[playerid][pVipCustomObjects] = 0;
				gPlayerData[playerid][pVipHalogenLight] = 0;
				gPlayerData[playerid][pVipWhitePointLight] = 0;
				gPlayerData[playerid][pVipRedPointLight] = 0;
				gPlayerData[playerid][pVipGreenPointLight] = 0;
				gPlayerData[playerid][pVipBluePointLight] = 0;
			}
			else
			{
				mysql_fetch_row_format(db_result, "|", db_con4);

				split2(db_result, arrCoords, '|');

				mysql_free_result(db_con4);

				gPlayerData[playerid][pVipCar] = strval(arrCoords[0]);
				gPlayerData[playerid][pVipAFK] = strval(arrCoords[1]);
				gPlayerData[playerid][pVipAFKT] = strval(arrCoords[2]);
				gPlayerData[playerid][pVipExp] = strval(arrCoords[3]);
				gPlayerData[playerid][pVipExpT] = strval(arrCoords[4]);
				gPlayerData[playerid][pCharacterDeath] = strval(arrCoords[5]);
				gPlayerData[playerid][pCharacterDying] = strval(arrCoords[6]);
				gPlayerData[playerid][pVipItem] = strval(arrCoords[7]);
				gPlayerData[playerid][pAccountOwnerID] = strval(arrCoords[10]);
				gPlayerData[playerid][pVipGarage] = strval(arrCoords[11]);
				gPlayerData[playerid][pVipGarageBig] = strval(arrCoords[12]);
				gPlayerData[playerid][pVipRedNeon] = strval(arrCoords[13]);
				gPlayerData[playerid][pVipBlueNeon] = strval(arrCoords[14]);
				gPlayerData[playerid][pVipGreenNeon] = strval(arrCoords[15]);
				gPlayerData[playerid][pVipYellowNeon] = strval(arrCoords[16]);
				gPlayerData[playerid][pVipPinkNeon] = strval(arrCoords[17]);
				gPlayerData[playerid][pVipWhiteNeon] = strval(arrCoords[18]);
				gPlayerData[playerid][pVipCustomObjects] = strval(arrCoords[19]);
				gPlayerData[playerid][pVipHalogenLight] = strval(arrCoords[20]);
				gPlayerData[playerid][pVipWhitePointLight] = strval(arrCoords[21]);
				gPlayerData[playerid][pVipRedPointLight] = strval(arrCoords[22]);
				gPlayerData[playerid][pVipGreenPointLight] = strval(arrCoords[23]);
				gPlayerData[playerid][pVipBluePointLight] = strval(arrCoords[24]);

				if( playerid < CUSTOM_MAX_PLAYERS )
				{
					format(string, sizeof(string), "SELECT `username` FROM `phpbb_users` WHERE `user_id` = '%d' LIMIT 1", gPlayerData[playerid][pAccountOwnerID]);
					mysql_query(string, PLAYER_DATA_LOAD_OOCNAME_MYSQL, playerid, db_con4);
				}
			}
			// if( playerid < CUSTOM_MAX_PLAYERS )
			// {
				// new dataar[256];
				// for( new id = 0; id <= BIZ_CPN_ID; id++ )
				// {
					// format(dataar, sizeof(dataar), "%d|%d", playerid, id);
					// format(string, sizeof(string), "SELECT * FROM `samp_users_fueled` WHERE `PlayerName` = '%s' AND `BizID` = '%d'", PlayerNameTMP, id);
					// mysql_query_array(string, PLAYER_LOAD_FUEL, dataar, db_con2);
				// }
			// }
			format( string, sizeof(string), "SELECT * FROM `samp_users_other2` WHERE `PlayerName` = '%s'", gPlayerData[playerid][pName] );
			mysql_query(string, PLAYER_DATA_LOAD_OTHER2_MYSQL, playerid, db_con4);
		}
		case PLAYER_DATA_LOAD_ITEMS_MYSQL:
		{
			// printf("[DEBUG:][PLAYER_LOAD_ITEMS_MYSQL] pid = %d, pname = %s", playerid, gPlayerData[playerid][pName]);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Czekaj, trwa ³adowanie danych [itemy 1-5]...");
			if( !mysql_store_result(db_con4) )
			{
				ErrorLog("[ERROR:] Can't store result on PLAYER_DATA_LOAD_ITEMS_MYSQL");
				if(playerid < CUSTOM_MAX_PLAYERS)
				{
					SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Wyst¹pi³ b³¹d przy ³adowaniu danych twojego konta. Jeœli problem bêdzie siê powtarza³ skontaktuj siê z administratorem" );
					return 1;
				}
			}
			if(mysql_num_rows(db_con4) == 0)
			{
				mysql_free_result(db_con4);
				if(playerid < CUSTOM_MAX_PLAYERS)
				{
					format(string, sizeof(string), "INSERT INTO `samp_users_items` (`PlayerName`) VALUES ('%s')", PlayerNameTMP);
					mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
				}
			}
			else
			{
				mysql_fetch_row_format(db_result, "|", db_con4);

				mysql_fetch_field_row(string, "Item1", db_con4);
				gPlayerData[playerid][pItem1] = strval(string);
				mysql_fetch_field_row(string, "Item2", db_con4);
				gPlayerData[playerid][pItem2] = strval(string);
				mysql_fetch_field_row(string, "Item3", db_con4);
				gPlayerData[playerid][pItem3] = strval(string);
				mysql_fetch_field_row(string, "Item4", db_con4);
				gPlayerData[playerid][pItem4] = strval(string);
				mysql_fetch_field_row(string, "Item5", db_con4);
				gPlayerData[playerid][pItem5] = strval(string);
				mysql_fetch_field_row(string, "Item1type", db_con4);
				gPlayerData[playerid][pItem1type] = strval(string);
				mysql_fetch_field_row(string, "Item2type", db_con4);
				gPlayerData[playerid][pItem2type] = strval(string);
				mysql_fetch_field_row(string, "Item3type", db_con4);
				gPlayerData[playerid][pItem3type] = strval(string);
				mysql_fetch_field_row(string, "Item4type", db_con4);
				gPlayerData[playerid][pItem4type] = strval(string);
				mysql_fetch_field_row(string, "Item5type", db_con4);
				gPlayerData[playerid][pItem5type] = strval(string);
				mysql_fetch_field_row(string, "Item1param", db_con4);
				gPlayerData[playerid][pItem1param] = strval(string);
				mysql_fetch_field_row(string, "Item2param", db_con4);
				gPlayerData[playerid][pItem2param] = strval(string);
				mysql_fetch_field_row(string, "Item3param", db_con4);
				gPlayerData[playerid][pItem3param] = strval(string);
				mysql_fetch_field_row(string, "Item4param", db_con4);
				gPlayerData[playerid][pItem4param] = strval(string);
				mysql_fetch_field_row(string, "Item5param", db_con4);
				gPlayerData[playerid][pItem5param] = strval(string);
				mysql_fetch_field_row(string, "Item1param2", db_con4);
				gPlayerData[playerid][pItem1param2] = strval(string);
				mysql_fetch_field_row(string, "Item2param2", db_con4);
				gPlayerData[playerid][pItem2param2] = strval(string);
				mysql_fetch_field_row(string, "Item3param2", db_con4);
				gPlayerData[playerid][pItem3param2] = strval(string);
				mysql_fetch_field_row(string, "Item4param2", db_con4);
				gPlayerData[playerid][pItem4param2] = strval(string);
				mysql_fetch_field_row(string, "Item5param2", db_con4);
				gPlayerData[playerid][pItem5param2] = strval(string);
				mysql_fetch_field_row(string, "Item1param3", db_con4);
				gPlayerData[playerid][pItem1param3] = strval(string);
				mysql_fetch_field_row(string, "Item2param3", db_con4);
				gPlayerData[playerid][pItem2param3] = strval(string);
				mysql_fetch_field_row(string, "Item3param3", db_con4);
				gPlayerData[playerid][pItem3param3] = strval(string);
				mysql_fetch_field_row(string, "Item4param3", db_con4);
				gPlayerData[playerid][pItem4param3] = strval(string);
				mysql_fetch_field_row(string, "Item5param3", db_con4);
				gPlayerData[playerid][pItem5param3] = strval(string);
				mysql_fetch_field_row(string, "Item1param4", db_con4);
				gPlayerData[playerid][pItem1param4] = strval(string);
				mysql_fetch_field_row(string, "Item2param4", db_con4);
				gPlayerData[playerid][pItem2param4] = strval(string);
				mysql_fetch_field_row(string, "Item3param4", db_con4);
				gPlayerData[playerid][pItem3param4] = strval(string);
				mysql_fetch_field_row(string, "Item4param4", db_con4);
				gPlayerData[playerid][pItem4param4] = strval(string);
				mysql_fetch_field_row(string, "Item5param4", db_con4);
				gPlayerData[playerid][pItem5param4] = strval(string);
				mysql_fetch_field_row(gPlayerData[playerid][pItem1param5], "Item1param5", db_con4);
				mysql_fetch_field_row(gPlayerData[playerid][pItem2param5], "Item2param5", db_con4);
				mysql_fetch_field_row(gPlayerData[playerid][pItem3param5], "Item3param5", db_con4);
				mysql_fetch_field_row(gPlayerData[playerid][pItem4param5], "Item4param5", db_con4);
				mysql_fetch_field_row(gPlayerData[playerid][pItem5param5], "Item5param5", db_con4);
				mysql_fetch_field_row(string, "Item1param6", db_con4);
				gPlayerData[playerid][pItem1param6] = strval(string);
				mysql_fetch_field_row(string, "Item2param6", db_con4);
				gPlayerData[playerid][pItem2param6] = strval(string);
				mysql_fetch_field_row(string, "Item3param6", db_con4);
				gPlayerData[playerid][pItem3param6] = strval(string);
				mysql_fetch_field_row(string, "Item4param6", db_con4);
				gPlayerData[playerid][pItem4param6] = strval(string);
				mysql_fetch_field_row(string, "Item5param6", db_con4);
				gPlayerData[playerid][pItem5param6] = strval(string);

				mysql_free_result(db_con4);
			}
			format( string, sizeof(string), "SELECT * FROM `samp_users_items2` WHERE `PlayerName` = '%s' LIMIT 1", gPlayerData[playerid][pName] );
			mysql_query(string, PLAYER_DATA_LOAD_ITEMS2_MYSQL, playerid, db_con4);
		}
		case PLAYER_DATA_LOAD_ITEMS2_MYSQL:
		{
			// printf("[DEBUG:][PLAYER_LOAD_ITEMS2_MYSQL] pid = %d, pname = %s", playerid, gPlayerData[playerid][pName]);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Czekaj, trwa ³adowanie danych [itemy 6-10]...");
			if( !mysql_store_result(db_con4) )
			{
				ErrorLog("[ERROR:] Can't store result on PLAYER_DATA_LOAD_ITEMS2_MYSQL");
				if( playerid != CUSTOM_MAX_PLAYERS )
					SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Wyst¹pi³ b³¹d przy ³adowaniu danych twojego konta. Jeœli problem bêdzie siê powtarza³ skontaktuj siê z administratorem" );
				return 1;
			}
			if(mysql_num_rows(db_con4) == 0)
			{
				mysql_free_result(db_con4);
				if(playerid < CUSTOM_MAX_PLAYERS)
				{
					format(string, sizeof(string), "INSERT INTO `samp_users_items2` (`PlayerName`) VALUES ('%s')", gPlayerData[playerid][pName]);
					mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
				}
			}
			else
			{
				mysql_fetch_row_format(db_result, "|", db_con4);

				mysql_fetch_field_row(string, "Item6", db_con4);
				gPlayerData[playerid][pItem6] = strval(string);
				mysql_fetch_field_row(string, "Item7", db_con4);
				gPlayerData[playerid][pItem7] = strval(string);
				mysql_fetch_field_row(string, "Item8", db_con4);
				gPlayerData[playerid][pItem8] = strval(string);
				mysql_fetch_field_row(string, "Item9", db_con4);
				gPlayerData[playerid][pItem9] = strval(string);
				mysql_fetch_field_row(string, "Item10", db_con4);
				gPlayerData[playerid][pItem10] = strval(string);
				mysql_fetch_field_row(string, "Item6type", db_con4);
				gPlayerData[playerid][pItem6type] = strval(string);
				mysql_fetch_field_row(string, "Item7type", db_con4);
				gPlayerData[playerid][pItem7type] = strval(string);
				mysql_fetch_field_row(string, "Item8type", db_con4);
				gPlayerData[playerid][pItem8type] = strval(string);
				mysql_fetch_field_row(string, "Item9type", db_con4);
				gPlayerData[playerid][pItem9type] = strval(string);
				mysql_fetch_field_row(string, "Item10type", db_con4);
				gPlayerData[playerid][pItem10type] = strval(string);
				mysql_fetch_field_row(string, "Item6param", db_con4);
				gPlayerData[playerid][pItem6param] = strval(string);
				mysql_fetch_field_row(string, "Item7param", db_con4);
				gPlayerData[playerid][pItem7param] = strval(string);
				mysql_fetch_field_row(string, "Item8param", db_con4);
				gPlayerData[playerid][pItem8param] = strval(string);
				mysql_fetch_field_row(string, "Item9param", db_con4);
				gPlayerData[playerid][pItem9param] = strval(string);
				mysql_fetch_field_row(string, "Item10param", db_con4);
				gPlayerData[playerid][pItem10param] = strval(string);
				mysql_fetch_field_row(string, "Item6param2", db_con4);
				gPlayerData[playerid][pItem6param2] = strval(string);
				mysql_fetch_field_row(string, "Item7param2", db_con4);
				gPlayerData[playerid][pItem7param2] = strval(string);
				mysql_fetch_field_row(string, "Item8param2", db_con4);
				gPlayerData[playerid][pItem8param2] = strval(string);
				mysql_fetch_field_row(string, "Item9param2", db_con4);
				gPlayerData[playerid][pItem9param2] = strval(string);
				mysql_fetch_field_row(string, "Item10param2", db_con4);
				gPlayerData[playerid][pItem10param2] = strval(string);
				mysql_fetch_field_row(string, "Item6param3", db_con4);
				gPlayerData[playerid][pItem6param3] = strval(string);
				mysql_fetch_field_row(string, "Item7param3", db_con4);
				gPlayerData[playerid][pItem7param3] = strval(string);
				mysql_fetch_field_row(string, "Item8param3", db_con4);
				gPlayerData[playerid][pItem8param3] = strval(string);
				mysql_fetch_field_row(string, "Item9param3", db_con4);
				gPlayerData[playerid][pItem9param3] = strval(string);
				mysql_fetch_field_row(string, "Item10param3", db_con4);
				gPlayerData[playerid][pItem10param3] = strval(string);
				mysql_fetch_field_row(string, "Item6param4", db_con4);
				gPlayerData[playerid][pItem6param4] = strval(string);
				mysql_fetch_field_row(string, "Item7param4", db_con4);
				gPlayerData[playerid][pItem7param4] = strval(string);
				mysql_fetch_field_row(string, "Item8param4", db_con4);
				gPlayerData[playerid][pItem8param4] = strval(string);
				mysql_fetch_field_row(string, "Item9param4", db_con4);
				gPlayerData[playerid][pItem9param4] = strval(string);
				mysql_fetch_field_row(string, "Item10param4", db_con4);
				gPlayerData[playerid][pItem10param4] = strval(string);
				mysql_fetch_field_row(gPlayerData[playerid][pItem6param5], "Item6param5", db_con4);
				mysql_fetch_field_row(gPlayerData[playerid][pItem7param5], "Item7param5", db_con4);
				mysql_fetch_field_row(gPlayerData[playerid][pItem8param5], "Item8param5", db_con4);
				mysql_fetch_field_row(gPlayerData[playerid][pItem9param5], "Item9param5", db_con4);
				mysql_fetch_field_row(gPlayerData[playerid][pItem10param5], "Item10param5", db_con4);
				mysql_fetch_field_row(string, "Item6param6", db_con4);
				gPlayerData[playerid][pItem6param6] = strval(string);
				mysql_fetch_field_row(string, "Item7param6", db_con4);
				gPlayerData[playerid][pItem7param6] = strval(string);
				mysql_fetch_field_row(string, "Item8param6", db_con4);
				gPlayerData[playerid][pItem8param6] = strval(string);
				mysql_fetch_field_row(string, "Item9param6", db_con4);
				gPlayerData[playerid][pItem9param6] = strval(string);
				mysql_fetch_field_row(string, "Item10param6", db_con4);
				gPlayerData[playerid][pItem10param6] = strval(string);

				mysql_free_result(db_con4);
			}
			format( string, sizeof(string), "SELECT * FROM `samp_users_items3` WHERE `PlayerName` = '%s' LIMIT 1", gPlayerData[playerid][pName]) ;
			mysql_query(string, PLAYER_DATA_LOAD_ITEMS3_MYSQL, playerid, db_con4);
		}
		case PLAYER_DATA_LOAD_ITEMS3_MYSQL:
		{
			// printf("[DEBUG:][PLAYER_LOAD_ITEMS3_MYSQL] pid = %d, pname = %s", playerid, gPlayerData[playerid][pName]);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Czekaj, trwa ³adowanie danych [itemy 11-25]...");
			if( !mysql_store_result(db_con4) )
			{
				ErrorLog("[ERROR:] Can't store result on PLAYER_DATA_LOAD_ITEMS3_MYSQL");
				if(playerid < CUSTOM_MAX_PLAYERS)
				{
					SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Wyst¹pi³ b³¹d przy ³adowaniu danych twojego konta. Jeœli problem bêdzie siê powtarza³ skontaktuj siê z administratorem" );
					return 1;
				}
			}
			if(mysql_num_rows(db_con4) == 0)
			{
				mysql_free_result(db_con4);
				if(playerid < CUSTOM_MAX_PLAYERS)
				{
					format(string, sizeof(string), "INSERT INTO `samp_users_items3` (`PlayerName`) VALUES('%s')", gPlayerData[playerid][pName]);
					mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
				}
			}
			else
			{
				mysql_fetch_row_format(db_result, "|", db_con4);

				mysql_fetch_field_row(string, "Item11", db_con4);
				gPlayerData[playerid][pItem11] = strval(string);
				mysql_fetch_field_row(string, "Item12", db_con4);
				gPlayerData[playerid][pItem12] = strval(string);
				mysql_fetch_field_row(string, "Item13", db_con4);
				gPlayerData[playerid][pItem13] = strval(string);
				mysql_fetch_field_row(string, "Item14", db_con4);
				gPlayerData[playerid][pItem14] = strval(string);
				mysql_fetch_field_row(string, "Item15", db_con4);
				gPlayerData[playerid][pItem15] = strval(string);
				mysql_fetch_field_row(string, "Item16", db_con4);
				gPlayerData[playerid][pItem16] = strval(string);
				mysql_fetch_field_row(string, "Item17", db_con4);
				gPlayerData[playerid][pItem17] = strval(string);
				mysql_fetch_field_row(string, "Item18", db_con4);
				gPlayerData[playerid][pItem18] = strval(string);
				mysql_fetch_field_row(string, "Item19", db_con4);
				gPlayerData[playerid][pItem19] = strval(string);
				mysql_fetch_field_row(string, "Item20", db_con4);
				gPlayerData[playerid][pItem20] = strval(string);
				mysql_fetch_field_row(string, "Item21", db_con4);
				gPlayerData[playerid][pItem21] = strval(string);
				mysql_fetch_field_row(string, "Item22", db_con4);
				gPlayerData[playerid][pItem22] = strval(string);
				mysql_fetch_field_row(string, "Item23", db_con4);
				gPlayerData[playerid][pItem23] = strval(string);
				mysql_fetch_field_row(string, "Item24", db_con4);
				gPlayerData[playerid][pItem24] = strval(string);
				mysql_fetch_field_row(string, "Item25", db_con4);
				gPlayerData[playerid][pItem25] = strval(string);
				mysql_fetch_field_row(string, "Item11type", db_con4);
				gPlayerData[playerid][pItem11type] = strval(string);
				mysql_fetch_field_row(string, "Item12type", db_con4);
				gPlayerData[playerid][pItem12type] = strval(string);
				mysql_fetch_field_row(string, "Item13type", db_con4);
				gPlayerData[playerid][pItem13type] = strval(string);
				mysql_fetch_field_row(string, "Item14type", db_con4);
				gPlayerData[playerid][pItem14type] = strval(string);
				mysql_fetch_field_row(string, "Item15type", db_con4);
				gPlayerData[playerid][pItem15type] = strval(string);
				mysql_fetch_field_row(string, "Item16type", db_con4);
				gPlayerData[playerid][pItem16type] = strval(string);
				mysql_fetch_field_row(string, "Item17type", db_con4);
				gPlayerData[playerid][pItem17type] = strval(string);
				mysql_fetch_field_row(string, "Item18type", db_con4);
				gPlayerData[playerid][pItem18type] = strval(string);
				mysql_fetch_field_row(string, "Item19type", db_con4);
				gPlayerData[playerid][pItem19type] = strval(string);
				mysql_fetch_field_row(string, "Item20type", db_con4);
				gPlayerData[playerid][pItem20type] = strval(string);
				mysql_fetch_field_row(string, "Item21type", db_con4);
				gPlayerData[playerid][pItem21type] = strval(string);
				mysql_fetch_field_row(string, "Item22type", db_con4);
				gPlayerData[playerid][pItem22type] = strval(string);
				mysql_fetch_field_row(string, "Item23type", db_con4);
				gPlayerData[playerid][pItem23type] = strval(string);
				mysql_fetch_field_row(string, "Item24type", db_con4);
				gPlayerData[playerid][pItem24type] = strval(string);
				mysql_fetch_field_row(string, "Item25type", db_con4);
				gPlayerData[playerid][pItem25type] = strval(string);
				mysql_fetch_field_row(string, "Item11param", db_con4);
				gPlayerData[playerid][pItem11param] = strval(string);
				mysql_fetch_field_row(string, "Item12param", db_con4);
				gPlayerData[playerid][pItem12param] = strval(string);
				mysql_fetch_field_row(string, "Item13param", db_con4);
				gPlayerData[playerid][pItem13param] = strval(string);
				mysql_fetch_field_row(string, "Item14param", db_con4);
				gPlayerData[playerid][pItem14param] = strval(string);
				mysql_fetch_field_row(string, "Item15param", db_con4);
				gPlayerData[playerid][pItem15param] = strval(string);
				mysql_fetch_field_row(string, "Item16param", db_con4);
				gPlayerData[playerid][pItem16param] = strval(string);
				mysql_fetch_field_row(string, "Item17param", db_con4);
				gPlayerData[playerid][pItem17param] = strval(string);
				mysql_fetch_field_row(string, "Item18param", db_con4);
				gPlayerData[playerid][pItem18param] = strval(string);
				mysql_fetch_field_row(string, "Item19param", db_con4);
				gPlayerData[playerid][pItem19param] = strval(string);
				mysql_fetch_field_row(string, "Item20param", db_con4);
				gPlayerData[playerid][pItem20param] = strval(string);
				mysql_fetch_field_row(string, "Item21param", db_con4);
				gPlayerData[playerid][pItem21param] = strval(string);
				mysql_fetch_field_row(string, "Item22param", db_con4);
				gPlayerData[playerid][pItem22param] = strval(string);
				mysql_fetch_field_row(string, "Item23param", db_con4);
				gPlayerData[playerid][pItem23param] = strval(string);
				mysql_fetch_field_row(string, "Item24param", db_con4);
				gPlayerData[playerid][pItem24param] = strval(string);
				mysql_fetch_field_row(string, "Item25param", db_con4);
				gPlayerData[playerid][pItem25param] = strval(string);
				mysql_fetch_field_row(string, "Item11param2", db_con4);
				gPlayerData[playerid][pItem11param2] = strval(string);
				mysql_fetch_field_row(string, "Item12param2", db_con4);
				gPlayerData[playerid][pItem12param2] = strval(string);
				mysql_fetch_field_row(string, "Item13param2", db_con4);
				gPlayerData[playerid][pItem13param2] = strval(string);
				mysql_fetch_field_row(string, "Item14param2", db_con4);
				gPlayerData[playerid][pItem14param2] = strval(string);
				mysql_fetch_field_row(string, "Item15param2", db_con4);
				gPlayerData[playerid][pItem15param2] = strval(string);
				mysql_fetch_field_row(string, "Item16param2", db_con4);
				gPlayerData[playerid][pItem16param2] = strval(string);
				mysql_fetch_field_row(string, "Item17param2", db_con4);
				gPlayerData[playerid][pItem17param2] = strval(string);
				mysql_fetch_field_row(string, "Item18param2", db_con4);
				gPlayerData[playerid][pItem18param2] = strval(string);
				mysql_fetch_field_row(string, "Item19param2", db_con4);
				gPlayerData[playerid][pItem19param2] = strval(string);
				mysql_fetch_field_row(string, "Item20param2", db_con4);
				gPlayerData[playerid][pItem20param2] = strval(string);
				mysql_fetch_field_row(string, "Item21param2", db_con4);
				gPlayerData[playerid][pItem21param2] = strval(string);
				mysql_fetch_field_row(string, "Item22param2", db_con4);
				gPlayerData[playerid][pItem22param2] = strval(string);
				mysql_fetch_field_row(string, "Item23param2", db_con4);
				gPlayerData[playerid][pItem23param2] = strval(string);
				mysql_fetch_field_row(string, "Item24param2", db_con4);
				gPlayerData[playerid][pItem24param2] = strval(string);
				mysql_fetch_field_row(string, "Item25param2", db_con4);
				gPlayerData[playerid][pItem25param2] = strval(string);
				mysql_fetch_field_row(string, "Item11param3", db_con4);
				gPlayerData[playerid][pItem11param3] = strval(string);
				mysql_fetch_field_row(string, "Item12param3", db_con4);
				gPlayerData[playerid][pItem12param3] = strval(string);
				mysql_fetch_field_row(string, "Item13param3", db_con4);
				gPlayerData[playerid][pItem13param3] = strval(string);
				mysql_fetch_field_row(string, "Item14param3", db_con4);
				gPlayerData[playerid][pItem14param3] = strval(string);
				mysql_fetch_field_row(string, "Item15param3", db_con4);
				gPlayerData[playerid][pItem15param3] = strval(string);
				mysql_fetch_field_row(string, "Item16param3", db_con4);
				gPlayerData[playerid][pItem16param3] = strval(string);
				mysql_fetch_field_row(string, "Item17param3", db_con4);
				gPlayerData[playerid][pItem17param3] = strval(string);
				mysql_fetch_field_row(string, "Item18param3", db_con4);
				gPlayerData[playerid][pItem18param3] = strval(string);
				mysql_fetch_field_row(string, "Item19param3", db_con4);
				gPlayerData[playerid][pItem19param3] = strval(string);
				mysql_fetch_field_row(string, "Item20param3", db_con4);
				gPlayerData[playerid][pItem20param3] = strval(string);
				mysql_fetch_field_row(string, "Item21param3", db_con4);
				gPlayerData[playerid][pItem21param3] = strval(string);
				mysql_fetch_field_row(string, "Item22param3", db_con4);
				gPlayerData[playerid][pItem22param3] = strval(string);
				mysql_fetch_field_row(string, "Item23param3", db_con4);
				gPlayerData[playerid][pItem23param3] = strval(string);
				mysql_fetch_field_row(string, "Item24param3", db_con4);
				gPlayerData[playerid][pItem24param3] = strval(string);
				mysql_fetch_field_row(string, "Item25param3", db_con4);
				gPlayerData[playerid][pItem25param3] = strval(string);
				mysql_fetch_field_row(string, "Item11param4", db_con4);
				gPlayerData[playerid][pItem11param4] = strval(string);
				mysql_fetch_field_row(string, "Item12param4", db_con4);
				gPlayerData[playerid][pItem12param4] = strval(string);
				mysql_fetch_field_row(string, "Item13param4", db_con4);
				gPlayerData[playerid][pItem13param4] = strval(string);
				mysql_fetch_field_row(string, "Item14param4", db_con4);
				gPlayerData[playerid][pItem14param4] = strval(string);
				mysql_fetch_field_row(string, "Item15param4", db_con4);
				gPlayerData[playerid][pItem15param4] = strval(string);
				mysql_fetch_field_row(string, "Item16param4", db_con4);
				gPlayerData[playerid][pItem16param4] = strval(string);
				mysql_fetch_field_row(string, "Item17param4", db_con4);
				gPlayerData[playerid][pItem17param4] = strval(string);
				mysql_fetch_field_row(string, "Item18param4", db_con4);
				gPlayerData[playerid][pItem18param4] = strval(string);
				mysql_fetch_field_row(string, "Item19param4", db_con4);
				gPlayerData[playerid][pItem19param4] = strval(string);
				mysql_fetch_field_row(string, "Item20param4", db_con4);
				gPlayerData[playerid][pItem20param4] = strval(string);
				mysql_fetch_field_row(string, "Item21param4", db_con4);
				gPlayerData[playerid][pItem21param4] = strval(string);
				mysql_fetch_field_row(string, "Item22param4", db_con4);
				gPlayerData[playerid][pItem22param4] = strval(string);
				mysql_fetch_field_row(string, "Item23param4", db_con4);
				gPlayerData[playerid][pItem23param4] = strval(string);
				mysql_fetch_field_row(string, "Item24param4", db_con4);
				gPlayerData[playerid][pItem24param4] = strval(string);
				mysql_fetch_field_row(string, "Item25param4", db_con4);
				gPlayerData[playerid][pItem25param4] = strval(string);
				mysql_fetch_field_row(gPlayerData[playerid][pItem11param5], "Item11param5", db_con4);
				mysql_fetch_field_row(gPlayerData[playerid][pItem12param5], "Item12param5", db_con4);
				mysql_fetch_field_row(gPlayerData[playerid][pItem13param5], "Item13param5", db_con4);
				mysql_fetch_field_row(gPlayerData[playerid][pItem14param5], "Item14param5", db_con4);
				mysql_fetch_field_row(gPlayerData[playerid][pItem15param5], "Item15param5", db_con4);
				mysql_fetch_field_row(gPlayerData[playerid][pItem16param5], "Item16param5", db_con4);
				mysql_fetch_field_row(gPlayerData[playerid][pItem17param5], "Item17param5", db_con4);
				mysql_fetch_field_row(gPlayerData[playerid][pItem18param5], "Item18param5", db_con4);
				mysql_fetch_field_row(gPlayerData[playerid][pItem19param5], "Item19param5", db_con4);
				mysql_fetch_field_row(gPlayerData[playerid][pItem20param5], "Item20param5", db_con4);
				mysql_fetch_field_row(gPlayerData[playerid][pItem21param5], "Item21param5", db_con4);
				mysql_fetch_field_row(gPlayerData[playerid][pItem22param5], "Item22param5", db_con4);
				mysql_fetch_field_row(gPlayerData[playerid][pItem23param5], "Item23param5", db_con4);
				mysql_fetch_field_row(gPlayerData[playerid][pItem24param5], "Item24param5", db_con4);
				mysql_fetch_field_row(gPlayerData[playerid][pItem25param5], "Item25param5", db_con4);
				mysql_fetch_field_row(string, "Item11param6", db_con4);
				gPlayerData[playerid][pItem11param6] = strval(string);
				mysql_fetch_field_row(string, "Item12param6", db_con4);
				gPlayerData[playerid][pItem12param6] = strval(string);
				mysql_fetch_field_row(string, "Item13param6", db_con4);
				gPlayerData[playerid][pItem13param6] = strval(string);
				mysql_fetch_field_row(string, "Item14param6", db_con4);
				gPlayerData[playerid][pItem14param6] = strval(string);
				mysql_fetch_field_row(string, "Item15param6", db_con4);
				gPlayerData[playerid][pItem15param6] = strval(string);
				mysql_fetch_field_row(string, "Item16param6", db_con4);
				gPlayerData[playerid][pItem16param6] = strval(string);
				mysql_fetch_field_row(string, "Item17param6", db_con4);
				gPlayerData[playerid][pItem17param6] = strval(string);
				mysql_fetch_field_row(string, "Item18param6", db_con4);
				gPlayerData[playerid][pItem18param6] = strval(string);
				mysql_fetch_field_row(string, "Item19param6", db_con4);
				gPlayerData[playerid][pItem19param6] = strval(string);
				mysql_fetch_field_row(string, "Item20param6", db_con4);
				gPlayerData[playerid][pItem20param6] = strval(string);
				mysql_fetch_field_row(string, "Item21param6", db_con4);
				gPlayerData[playerid][pItem21param6] = strval(string);
				mysql_fetch_field_row(string, "Item22param6", db_con4);
				gPlayerData[playerid][pItem22param6] = strval(string);
				mysql_fetch_field_row(string, "Item23param6", db_con4);
				gPlayerData[playerid][pItem23param6] = strval(string);
				mysql_fetch_field_row(string, "Item24param6", db_con4);
				gPlayerData[playerid][pItem24param6] = strval(string);
				mysql_fetch_field_row(string, "Item25param6", db_con4);
				gPlayerData[playerid][pItem25param6] = strval(string);

				mysql_free_result(db_con4);
			}
			format( string, sizeof(string), "SELECT * FROM `samp_users_jobs` WHERE `PlayerName` = '%s' LIMIT 1", gPlayerData[playerid][pName] );
			mysql_query(string, PLAYER_DATA_LOAD_JOB_MYSQL, playerid, db_con4);
		}
		case PLAYER_DATA_LOAD_OOCNAME_MYSQL:
		{
			if(!mysql_store_result(db_con4))
			{
				ErrorLog("[ERROR:] Can't store result on PLAYER_DATA_LOAD_OOCNAME_MYSQL");
				if( playerid != CUSTOM_MAX_PLAYERS )
					SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Wyst¹pi³ b³¹d przy ³adowaniu danych twojego konta. Jeœli problem bêdzie siê powtarza³ skontaktuj siê z administratorem" );
				return 1;
			}
			mysql_fetch_row_format(db_result, "|", db_con4);

			split2(db_result, arrCoords, '|');

			strdel(gPlayerData[playerid][pOOCName], 0, 64);
			strins(gPlayerData[playerid][pOOCName], arrCoords[0], 0, 64);

			mysql_free_result(db_con4);
		}
		case PLAYER_DATA_LOAD_OTHER2_MYSQL:
		{
			// printf("[DEBUG:][PLAYER_LOAD_OTHER2_MYSQL] pid = %d, pname = %s", playerid, gPlayerData[playerid][pName]);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Czekaj, trwa ³adowanie danych [finalizacja]...");
			if(!mysql_store_result(db_con4))
			{
				ErrorLog("[ERROR:] Can't store result on PLAYER_DATA_LOAD_OTHER2_MYSQL");
				if(playerid < CUSTOM_MAX_PLAYERS)
				{
					SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Wyst¹pi³ b³¹d przy ³adowaniu danych twojego konta. Jeœli problem bêdzie siê powtarza³ skontaktuj siê z administratorem" );
					return 1;
				}
			}
			if(mysql_num_rows(db_con4) == 0 && playerid < CUSTOM_MAX_PLAYERS)
			{
				format(string, sizeof(string), "[ERROR:] Player %s don't have record on PLAYER_DATA_LOAD_OTHER2_MYSQL", gPlayerData[playerid][pName]);
				ErrorLog(string);

				mysql_free_result(db_con2);

				format(string, sizeof(string), "INSERT INTO `samp_users_other2` (`PlayerName`) VALUES ('%s')", gPlayerData[playerid][pName]);
				mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);

				format(string, sizeof(string), "SELECT * FROM `samp_users_other2` WHERE `PlayerName` = '%s' LIMIT 1", gPlayerData[playerid][pName]);
				mysql_query(string, PLAYER_DATA_LOAD_OTHER2_MYSQL, playerid, db_con4);
			}
			else
			{
				mysql_fetch_row_format(db_result, "|", db_con4);

				mysql_fetch_field_row(string, "Parts", db_con4);
				gPlayerData[playerid][pParts] = strval(string);
				mysql_fetch_field_row(string, "JobTimeChange", db_con4);
				gPlayerData[playerid][pJobTimeChange] = strval(string);
				mysql_fetch_field_row(string, "SkillLevPis", db_con4);
				gPlayerData[playerid][pSkillLevPis] = strval(string);
				mysql_fetch_field_row(string, "SkillLevSil", db_con4);
				gPlayerData[playerid][pSkillLevSil] = strval(string);
				mysql_fetch_field_row(string, "SkillLevDes", db_con4);
				gPlayerData[playerid][pSkillLevDes] = strval(string);
				mysql_fetch_field_row(string, "SkillLevSho", db_con4);
				gPlayerData[playerid][pSkillLevSho] = strval(string);
				mysql_fetch_field_row(string, "SkillLevSha", db_con4);
				gPlayerData[playerid][pSkillLevSha] = strval(string);
				mysql_fetch_field_row(string, "SkillLevSpa", db_con4);
				gPlayerData[playerid][pSkillLevSpa] = strval(string);
				mysql_fetch_field_row(string, "SkillLevMic", db_con4);
				gPlayerData[playerid][pSkillLevMic] = strval(string);
				mysql_fetch_field_row(string, "SkillLevMp5", db_con4);
				gPlayerData[playerid][pSkillLevMp5] = strval(string);
				mysql_fetch_field_row(string, "SkillLevAk", db_con4);
				gPlayerData[playerid][pSkillLevAk] = strval(string);
				mysql_fetch_field_row(string, "SkillLevM4", db_con4);
				gPlayerData[playerid][pSkillLevM4] = strval(string);
				mysql_fetch_field_row(string, "SkillLevSni", db_con4);
				gPlayerData[playerid][pSkillLevSni] = strval(string);
				mysql_fetch_field_row(string, "SkillPointsPis", db_con4);
				gPlayerData[playerid][pSkillPointsPis] = strval(string);
				mysql_fetch_field_row(string, "SkillPointsSil", db_con4);
				gPlayerData[playerid][pSkillPointsSil] = strval(string);
				mysql_fetch_field_row(string, "SkillPointsDes", db_con4);
				gPlayerData[playerid][pSkillPointsDes] = strval(string);
				mysql_fetch_field_row(string, "SkillPointsSho", db_con4);
				gPlayerData[playerid][pSkillPointsSho] = strval(string);
				mysql_fetch_field_row(string, "SkillPointsSha", db_con4);
				gPlayerData[playerid][pSkillPointsSha] = strval(string);
				mysql_fetch_field_row(string, "SkillPointsSpa", db_con4);
				gPlayerData[playerid][pSkillPointsSpa] = strval(string);
				mysql_fetch_field_row(string, "SkillPointsMic", db_con4);
				gPlayerData[playerid][pSkillPointsMic] = strval(string);
				mysql_fetch_field_row(string, "SkillPointsMp5", db_con4);
				gPlayerData[playerid][pSkillPointsMp5] = strval(string);
				mysql_fetch_field_row(string, "SkillPointsAk", db_con4);
				gPlayerData[playerid][pSkillPointsAk] = strval(string);
				mysql_fetch_field_row(string, "SkillPointsM4", db_con4);
				gPlayerData[playerid][pSkillPointsM4] = strval(string);
				mysql_fetch_field_row(string, "SkillPointsSni", db_con4);
				gPlayerData[playerid][pSkillPointsSni] = strval(string);
				mysql_fetch_field_row(string, "Pozwolenie", db_con4);
				gPlayerData[playerid][pPozwolenie] = strval(string);
				mysql_fetch_field_row(string, "Ang", db_con4);
				gPlayerData[playerid][pAng] = strval(string);
				mysql_fetch_field_row(string, "Wf", db_con4);
				gPlayerData[playerid][pWf] = strval(string);
				mysql_fetch_field_row(string, "Mat", db_con4);
				gPlayerData[playerid][pMat] = strval(string);
				mysql_fetch_field_row(string, "Pol", db_con4);
				gPlayerData[playerid][pPol] = strval(string);
				mysql_fetch_field_row(string, "His", db_con4);
				gPlayerData[playerid][pHis] = strval(string);
				mysql_fetch_field_row(string, "Fiz", db_con4);
				gPlayerData[playerid][pFiz] = strval(string);
				mysql_fetch_field_row(string, "Bio", db_con4);
				gPlayerData[playerid][pBio] = strval(string);
				mysql_fetch_field_row(string, "Doktor", db_con4);
				gPlayerData[playerid][pDoktor] = strval(string);
				mysql_fetch_field_row(string, "Magister", db_con4);
				gPlayerData[playerid][pMagister] = strval(string);
				mysql_fetch_field_row(string, "Inz", db_con4);
				gPlayerData[playerid][pInz] = strval(string);
				mysql_fetch_field_row(string, "Dowod", db_con4);
				gPlayerData[playerid][pDowod] = strval(string);
				mysql_fetch_field_row(string, "PktAng", db_con4);
				gPlayerData[playerid][pPktAng] = strval(string);
				mysql_fetch_field_row(string, "PktWf", db_con4);
				gPlayerData[playerid][pPktWf] = strval(string);
				mysql_fetch_field_row(string, "PktMat", db_con4);
				gPlayerData[playerid][pPktMat] = strval(string);
				mysql_fetch_field_row(string, "PktPol", db_con4);
				gPlayerData[playerid][pPktPol] = strval(string);
				mysql_fetch_field_row(string, "PktHis", db_con4);
				gPlayerData[playerid][pPktHis] = strval(string);
				mysql_fetch_field_row(string, "PktFiz", db_con4);
				gPlayerData[playerid][pPktFiz] = strval(string);
				mysql_fetch_field_row(string, "PktBio", db_con4);
				gPlayerData[playerid][pPktBio] = strval(string);
				mysql_fetch_field_row(string, "Duty", db_con4);
				gPlayerData[playerid][pDuty] = strval(string);
				mysql_fetch_field_row(string, "PartType", db_con4);
				gPlayerData[playerid][pPartType] = strval(string);
				mysql_fetch_field_row(string, "PartItem", db_con4);
				gPlayerData[playerid][pPartItem] = strval(string);
				mysql_fetch_field_row(string, "MountsLeft", db_con4);
				gPlayerData[playerid][pMountsLeft] = strval(string);
				mysql_fetch_field_row(string, "WFOrderedCount", db_con4);
				gPlayerData[playerid][pWFOrderedCount] = strval(string);
				mysql_fetch_field_row(string, "SpeedGunOn", db_con4);
				gPlayerData[playerid][pSpeedGunOn] = strval(string);
				mysql_fetch_field_row(string, "PWStatus", db_con4);
				gPlayerData[playerid][pPWStatus] = strval(string);
				mysql_fetch_field_row(string, "OOCStatus", db_con4);
				gPlayerData[playerid][pOOCStatus] = strval(string);
				mysql_fetch_field_row(string, "JoinInfoStatus", db_con4);
				gPlayerData[playerid][pJoinInfoStatus] = strval(string);
				mysql_fetch_field_row(string, "LeaveInfoStatus", db_con4);
				gPlayerData[playerid][pLeaveInfoStatus] = strval(string);
				mysql_fetch_field_row(string, "TipsStatus", db_con4);
				gPlayerData[playerid][pTipsStatus] = strval(string);
				mysql_fetch_field_row(string, "BackgroundSoundStatus", db_con4);
				gPlayerData[playerid][pBackgroundSoundStatus] = strval(string);
				mysql_fetch_field_row(string, "IsDeptor", db_con4);
				gPlayerData[playerid][pIsDeptor] = strval(string);
				mysql_fetch_field_row(string, "LastLogged", db_con4);
				gPlayerData[playerid][pLastLogged] = strval(string);
				mysql_fetch_field_row(string, "QuizWrongAnsweres", db_con4);
				gPlayerVars[playerid][mQuizWrongAnsweres] = strval(string);
				mysql_fetch_field_row(string, "CreditValue", db_con4);
				gPlayerData[playerid][mCreditValue] = strval(string);
				mysql_fetch_field_row(string, "CreditRepayment", db_con4);
				gPlayerData[playerid][mCreditRepayment] = strval(string);
				mysql_fetch_field_row(string, "CreditPayed", db_con4);
				gPlayerData[playerid][mCreditPayed] = strval(string);

				mysql_free_result(db_con4);

				if(playerid < CUSTOM_MAX_PLAYERS)
				{
					GetPlayerIp(playerid, string, sizeof(string));
					format(string, sizeof(string), "%s sign in with %d$ in character cash and %d$ in bank cash, IP is %s", gPlayerData[playerid][pName], gPlayerData[playerid][pCash], gPlayerData[playerid][pBank], string);
					LogginDataLog(string);

					// Is character set to delete
					if(gPlayerData[playerid][pSetToDelete])
						KickPlayer(playerid,"System","Konto zosta³o przeznaczone do usuniêcia i nie mo¿na siê na nie zalogowaæ");
					
					// Vacation status
					if(gPlayerData[playerid][pIsOnVacation])
						KickPlayer(playerid,"System","Konto posiada aktywny urlop - deaktywuj urlop przed zalogowaniem siê do gry");
					
					// Kick banned player
					if(gPlayerData[playerid][pBanned])
						KickPlayer(playerid,"System","Konto zbanowane");

					// Kick dead player
					if(gPlayerData[playerid][pCharacterDeath] == 1)
						KickPlayer(playerid,"System","Postaæ martwa");

					// Fill first logged player with default data
					if( gPlayerData[playerid][pRegistered] == 0 )
					{
						gPlayerData[playerid][pCrashX] = gStartSpawnX;
						gPlayerData[playerid][pCrashY] = gStartSpawnY;
						gPlayerData[playerid][pCrashZ] = gStartSpawnZ;
						gPlayerData[playerid][pCash] = gStartMoney;
						gPlayerData[playerid][pBank] = gStartBank;
						gPlayerData[playerid][pSkin] = gStartSkin;
						gPlayerData[playerid][pRegistered] = 1;

						gSavePlayerReady[playerid] = 1; // umo¿liwia zapis w wp_saveplayerdata.inc

						SavePlayerData(playerid, "Skin");
						SavePlayerData(playerid, "Registered");
						SetPlayerCash(playerid,gPlayerData[playerid][pCash]);
						gFirstTime[playerid] = 1;
					}
					
					PosHackCheckTime[playerid] = 5;
					TogglePlayerControllable(playerid, 0);
					
					if(!gPlayerData[playerid][pQuiz])
					{
						gPlayerVars[playerid][mQuizQuestionNo] = 0;
						gPlayerVars[playerid][mQuizWrongAnsweres] = 0;
						ShowPlayerQuiz(playerid);
					}
					else
					{
						SetPlayerSpawn(playerid);							
						SpawnPlayer(playerid);						
						defer UnfreezePlayer[5000](playerid);
						Alive[playerid] = 1;
						CheckDelay[playerid] = 2;
						format(string, sizeof(string), "{DF013A}[WParty SERVER:]{FFFFFF} Witaj ponownie %s", gPlayerData[playerid][pOOCName]);
						SendClientMessage( playerid, COLOR_GREEN, string);
					}
					
					// Show gang war status
					TextDrawShowForPlayer(playerid, GangWar[playerid]);
					TextDrawShowForPlayer(playerid, GangWarTime[playerid]);

					// Set player nick color depends on nick
					if(IsPlayerVip(playerid))
						SetPlayerColor(playerid, COLOR_PURPLE);
					else
						SetPlayerColor(playerid, COLOR_CIVILIAN);
					
					// Show player map icons if have map
					if(PHaveItem(playerid, 1, 105))
						ShowPlayerMapIcons( playerid, 0);

					// Show player GPS data
					new slot[MAX_PLAYER_ITEM_SLOT];
					PHaveItemEx(playerid, 3, 12, slot);
					for(new i = 0; i < MAX_PLAYER_ITEM_SLOT; i++)
					{
						if(slot[i] && SlotParam1(playerid, i+1))
						{
							ShowPlayerMapIcons(playerid, 1);
							break;
						}
					}
					
					// Show debug data
					// Eating
					#if defined DEBUG
						EatText[playerid] = TextDrawCreate(10.0, 285.0, " ");
						TextDrawLetterSize(EatText[playerid], 0.15, 0.9);
						TextDrawTextSize(EatText[playerid], 190.0, 100.0);
						TextDrawShowForPlayer(playerid, EatText[playerid]);
					#endif

					// Set player gui cash
					SetPlayerCash(playerid,gPlayerData[playerid][pCash]);

					// Set player score
					SetPlayerScore(playerid, gPlayerData[playerid][pPlayingHours]);

					// Set player weapon skills
					SetPlayerSkillLevel(playerid, 0, gPlayerData[playerid][pSkillLevPis] * 100);
					SetPlayerSkillLevel(playerid, 1, gPlayerData[playerid][pSkillLevSil] * 100);
					SetPlayerSkillLevel(playerid, 2, gPlayerData[playerid][pSkillLevDes] * 100);
					SetPlayerSkillLevel(playerid, 3, gPlayerData[playerid][pSkillLevSha] * 100);
					SetPlayerSkillLevel(playerid, 4, gPlayerData[playerid][pSkillLevSho] * 100);
					SetPlayerSkillLevel(playerid, 5, gPlayerData[playerid][pSkillLevSpa] * 100);
					SetPlayerSkillLevel(playerid, 6, gPlayerData[playerid][pSkillLevMic] * 100);
					SetPlayerSkillLevel(playerid, 7, gPlayerData[playerid][pSkillLevMp5] * 100);
					SetPlayerSkillLevel(playerid, 8, gPlayerData[playerid][pSkillLevAk] * 100);
					SetPlayerSkillLevel(playerid, 9, gPlayerData[playerid][pSkillLevM4] * 100);
					SetPlayerSkillLevel(playerid, 10, gPlayerData[playerid][pSkillLevSni] * 100);

					// Set PayDay Message
					if(gPlayerData[playerid][pPayDayMessage])
						TextDrawShowForPlayer(playerid, gPayDayText);
					
					// Set Hunger Bar
					if(IsPlayerVip(playerid))
					{
						gPlayerData[playerid][pEnergyProgressBarID] = CreateProgressBar(535.0, 130.5, 70.0, 5.5, COLOR_YELLOW, MAX_ENERGY_VIP);
						gPlayerData[playerid][pHungerProgressBarID] = CreateProgressBar(535.0, 141.5, 70.0, 5.5, COLOR_LIGHTRED, MAX_HUNGER_VIP);
						gPlayerData[playerid][pThirstProgressBarID] = CreateProgressBar(535.0, 152.5, 70.0, 5.5, COLOR_LIGHTBLUE, MAX_THIRST_VIP);
						gPlayerData[playerid][pPoisonProgressBarID] = CreateProgressBar(535.0, 163.5, 70.0, 5.5, COLOR_GREEN, MAX_POISON_VIP);
						gPlayerData[playerid][pFatProgressBarID] = CreateProgressBar(535.0, 174.0, 70.0, 5.5, COLOR_LIGHTYELLOW2, MAX_FAT_VIP);
						gPlayerData[playerid][pStomachProgressBarID] = CreateProgressBar(535.0, 185.0, 70.0, 5.5, COLOR_PURPLE, MAX_STOMACH_VIP);
						gPlayerData[playerid][pVitaminsProgressBarID] = CreateProgressBar(535.0, 195.5, 70.0, 5.5, COLOR_ORANGE, MAX_VITAMINS_VIP);
						gPlayerData[playerid][pDrunkProgressBarID] = CreateProgressBar(535.0, 206.5, 70.0, 5.5, COLOR_LIGHTORANGE, MAX_DRUNK);
						gPlayerData[playerid][pNarcoticProgressBarID] = CreateProgressBar(535.0, 217.5, 70.0, 5.5, COLOR_WHITE, MAX_NARCOTIC);
					}
					else
					{
						gPlayerData[playerid][pEnergyProgressBarID] = CreateProgressBar(550.0, 130.5, 55.5, 5.5, COLOR_YELLOW, MAX_ENERGY);
						gPlayerData[playerid][pHungerProgressBarID] = CreateProgressBar(550.0, 141.5, 55.5, 5.5, COLOR_LIGHTRED, MAX_HUNGER);
						gPlayerData[playerid][pThirstProgressBarID] = CreateProgressBar(550.0, 152.5, 55.5, 5.5, COLOR_LIGHTBLUE, MAX_THIRST);
						gPlayerData[playerid][pPoisonProgressBarID] = CreateProgressBar(550.0, 163.5, 55.5, 5.5, COLOR_GREEN, MAX_POISON);
						gPlayerData[playerid][pFatProgressBarID] = CreateProgressBar(550.0, 174.0, 55.5, 5.5, COLOR_LIGHTYELLOW2, MAX_FAT);
						gPlayerData[playerid][pStomachProgressBarID] = CreateProgressBar(550.0, 185.0, 55.5, 5.5, COLOR_PURPLE, MAX_STOMACH);
						gPlayerData[playerid][pVitaminsProgressBarID] = CreateProgressBar(550.0, 195.5, 55.5, 5.5, COLOR_ORANGE, MAX_VITAMINS);
						gPlayerData[playerid][pDrunkProgressBarID] = CreateProgressBar(550.0, 206.5, 55.5, 5.5, COLOR_LIGHTORANGE, MAX_DRUNK);
						gPlayerData[playerid][pNarcoticProgressBarID] = CreateProgressBar(550.0, 217.5, 55.5, 5.5, COLOR_WHITE, MAX_NARCOTIC);
					}
					SetProgressBarValue(gPlayerData[playerid][pEnergyProgressBarID], gPlayerData[playerid][pEnergy]);
					UpdateProgressBar(gPlayerData[playerid][pEnergyProgressBarID], playerid);
					SetProgressBarValue(gPlayerData[playerid][pHungerProgressBarID], gPlayerData[playerid][pHunger]);
					UpdateProgressBar(gPlayerData[playerid][pHungerProgressBarID], playerid);
					SetProgressBarValue(gPlayerData[playerid][pThirstProgressBarID], gPlayerData[playerid][pThirst]);
					UpdateProgressBar(gPlayerData[playerid][pThirstProgressBarID], playerid);
					SetProgressBarValue(gPlayerData[playerid][pPoisonProgressBarID], gPlayerData[playerid][pPoison]);
					UpdateProgressBar(gPlayerData[playerid][pPoisonProgressBarID], playerid);
					SetProgressBarValue(gPlayerData[playerid][pFatProgressBarID], gPlayerData[playerid][pFat]);
					UpdateProgressBar(gPlayerData[playerid][pFatProgressBarID], playerid);
					SetProgressBarValue(gPlayerData[playerid][pStomachProgressBarID], gPlayerData[playerid][pStomach]);
					UpdateProgressBar(gPlayerData[playerid][pStomachProgressBarID], playerid);
					SetProgressBarValue(gPlayerData[playerid][pVitaminsProgressBarID], gPlayerData[playerid][pVitamins]);
					UpdateProgressBar(gPlayerData[playerid][pVitaminsProgressBarID], playerid);
					SetProgressBarValue(gPlayerData[playerid][pDrunkProgressBarID], gPlayerData[playerid][pDrunk]);
					UpdateProgressBar(gPlayerData[playerid][pDrunkProgressBarID], playerid);
					SetProgressBarValue(gPlayerData[playerid][pNarcoticProgressBarID], gPlayerData[playerid][pNarcotic]);
					UpdateProgressBar(gPlayerData[playerid][pNarcoticProgressBarID], playerid);
					
					TextDrawHideForPlayer(playerid, gHealthTextEnergy);
					TextDrawHideForPlayer(playerid, gHealthTextHunger);
					TextDrawHideForPlayer(playerid, gHealthTextThirst);
					TextDrawHideForPlayer(playerid, gHealthTextPoison);
					TextDrawHideForPlayer(playerid, gHealthTextFat);
					TextDrawHideForPlayer(playerid, gHealthTextStomach);
					TextDrawHideForPlayer(playerid, gHealthTextVitamins);
					TextDrawHideForPlayer(playerid, gHealthTextDrunk);
					TextDrawHideForPlayer(playerid, gHealthTextNarcotics);
					
					if(!gPlayerData[playerid][pShowHealthBars])
					{
						HideProgressBarForPlayer(playerid, gPlayerData[playerid][pEnergyProgressBarID]);
						HideProgressBarForPlayer(playerid, gPlayerData[playerid][pHungerProgressBarID]);
						HideProgressBarForPlayer(playerid, gPlayerData[playerid][pThirstProgressBarID]);
						HideProgressBarForPlayer(playerid, gPlayerData[playerid][pPoisonProgressBarID]);
						HideProgressBarForPlayer(playerid, gPlayerData[playerid][pFatProgressBarID]);
						HideProgressBarForPlayer(playerid, gPlayerData[playerid][pStomachProgressBarID]);
						HideProgressBarForPlayer(playerid, gPlayerData[playerid][pVitaminsProgressBarID]);
						HideProgressBarForPlayer(playerid, gPlayerData[playerid][pDrunkProgressBarID]);
						HideProgressBarForPlayer(playerid, gPlayerData[playerid][pNarcoticProgressBarID]);
					}
					else
					{
						TextDrawShowForPlayer(playerid, gHealthTextEnergy);
						TextDrawShowForPlayer(playerid, gHealthTextHunger);
						TextDrawShowForPlayer(playerid, gHealthTextThirst);
						TextDrawShowForPlayer(playerid, gHealthTextPoison);
						TextDrawShowForPlayer(playerid, gHealthTextFat);
						TextDrawShowForPlayer(playerid, gHealthTextStomach);
						TextDrawShowForPlayer(playerid, gHealthTextVitamins);
						TextDrawShowForPlayer(playerid, gHealthTextDrunk);
						TextDrawShowForPlayer(playerid, gHealthTextNarcotics);
					}
					
					// Show infos
					// ClearScreen(playerid);
					format(string, sizeof(string), "{DF013A}[WParty SERVER:]{FFFFFF}[ID: %d][IC: %s] %s do³¹czy³ do gry !", playerid, GetPlayerNameEx(playerid), gPlayerData[playerid][pOOCName]);
					foreach(Player, i)
					{
						if(gPlayerLogged[i] && i != playerid && gPlayerData[i][pJoinInfoStatus])
							SendClientMessage(i, 0xFFFFFFAA, string);
					}

					// Show character description
					Attach3DTextLabelToPlayer(gPlayerData[playerid][pCharDescriptionID], playerid, 0.0, 0.0, 0.5);
					Update3DTextLabelText(gPlayerData[playerid][pCharDescriptionID], gPlayerData[playerid][pCharDescriptionColor], gPlayerData[playerid][pCharDescription]);

					// Show character name
					Attach3DTextLabelToPlayer(gPlayerData[playerid][pCharNameID], playerid, 0.0, 0.0, 0.2);
					format(string, sizeof(string), "%s [%d]", GetPlayerNameEx(playerid), playerid);
					if(IsPlayerVip(playerid))
						Update3DTextLabelText(gPlayerData[playerid][pCharNameID], COLOR_PURPLE, string);
					else
						Update3DTextLabelText(gPlayerData[playerid][pCharNameID], COLOR_WHITE, string);

					// Check if player have active bandana
					PHaveItemEx(playerid, 3, 14, slot);
					for(new i = 0; i < MAX_PLAYER_ITEM_SLOT; i++)
					{
						if(slot[i] && SlotParam1(playerid, i+1))
						{
							format(string, sizeof(string), "Twarz za chust¹ [%d]", playerid);
							if(IsPlayerVip(playerid))
								Update3DTextLabelText(gPlayerData[playerid][pCharNameID], COLOR_PURPLE, string);
							else
								Update3DTextLabelText(gPlayerData[playerid][pCharNameID], COLOR_WHITE, string);
							break;
						}
					}
					// Set player dynamic weather
					if(IsPlayerInDynamicArea(playerid, gArea_MW_SanFierro))
						SetPlayerRealWeatherEx(playerid, gMW_sanfrancisco);
					else if(IsPlayerInDynamicArea(playerid, gArea_MW_LasVenturas))
						SetPlayerRealWeatherEx(playerid, gMW_lasvegas);
					else if(IsPlayerInDynamicArea(playerid, gArea_MW_LosSantos))
						SetPlayerRealWeatherEx(playerid, gMW_losangeles);
					else
						SetPlayerRealWeatherEx(playerid, gMW_warszawa);

					// Set player status box
					format(string, sizeof(string), " ");
					TextDrawSetString(PlayerStatus[playerid], string);
					TextDrawShowForPlayer(playerid, PlayerStatus[playerid]);
					TextDrawShowForPlayer(playerid, gPlayerVars[playerid][mSanNewsStatus]);

					// Set login status and enable save
					gPlayerLogged[playerid] = 1;
					gPlayerData[playerid][pLoading] = 0;
					gSavePlayerReady[playerid] = 1;

					// New version changes
					// if(!gPlayerData[playerid][pNewVersion])
					// {
						// strcat(string, "Otrzymujesz t¹ wiadomoœæ poniewa¿ od Twojego ostatniego logowania na serwer zosta³a wgrana nowa wersja skryptu.\n");
						// strcat(string, "\nZmiany w wersji - 1.15.0 - 1.15.1\n");
						// strcat(string, "- Stawianie/edycja biznesów/domów zosta³o zablokowane dla urzêdu. (1.15.1)\n");
						// strcat(string, "- Wezwania na policje/pogotwie wewn¹trz interiorów tworz¹ punkcie wejœcia do interioru. (1.15.1)\n");
						// strcat(string, "- Gracz mo¿e przejrzeæ ostatnie 5 wezwañ (dot. pogotowia oraz policji) poprzez komende /wezwania. Umo¿liwia to ponowne wyœwietlenie punktu w którym znajduje siê gracz który wykona³ po³¹czenie. (1.15.1)\n");
						// strcat(string, "- Rozwi¹zano problemy z zapisem w pomniejszych elementach gamemodu. (1.15.1)\n");
						// strcat(string, "- Ujednolicono zapis pozycji postaci (rozwi¹zuje problem ze spawnem w interiorach). (1.15.1)\n");
						// strcat(string, "- Wprowadzono mo¿liwoœæ posiadania wielu biznesów. (1.15.0)\n");
						// strcat(string, "- Dodano statystyki biznesu. (1.15.0)\n");
						// strcat(string, "- Ulepszono wynajmowanie domów. (1.15.0)\n");
						// strcat(string, "- Dodano item umo¿liwiaj¹cy zrobienie kopii klucza. (1.15.0)\n");
						// strcat(string, "- Wprowadzono mo¿liwoœæ zmiany zamka w domach oraz biznesach. (1.15.0)\n");
						// strcat(string, "- Dodano puste interiory do zaaran¿owania przez gracza. (1.15.0)\n");
						// strcat(string, "- Poprawiono problemy z BW. (1.15.0)\n");
						// ShowPlayerDialog(playerid, DIALOG_NEW_VERSION, DIALOG_STYLE_MSGBOX, "Nowa aktualizacja !", string, "Zamknij", "");
					// }
					if(gPlayerData[playerid][pVipItem] > 0 && gPlayerData[playerid][pVipItem] <= 5)
					{
						if(gPlayerData[playerid][pVipItem] == 1)
							format(string, sizeof(string), "Do koñca us³ugi premium VIP Item pozosta³ ju¿ tylko 1 dzieñ !");
						else
							format(string, sizeof(string), "Do koñca us³ugi premium VIP Item pozosta³o ju¿ tylko %d dni !", gPlayerData[playerid][pVipItem]);
						ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", string, "Zamknij", "");
					}
					else if(gPlayerData[playerid][pVipExpT] > 0 && gPlayerData[playerid][pVipExpT] <= 5)
					{
						if(gPlayerData[playerid][pVipExpT] == 1)
							format(string, sizeof(string), "Do koñca us³ugi premium VIP pozosta³o ju¿ tylko 1 dzieñ !");
						else
							format(string, sizeof(string), "Do koñca us³ugi premium VIP pozosta³o ju¿ tylko %d dni !", gPlayerData[playerid][pVipExpT]);
						ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", string, "Zamknij", "");
					}

					gPlayerData[playerid][pLastLogged] = 0;
					SavePlayerData(playerid, "LastLogged");

					return 1;
				}
				else
				{
					format(string, sizeof(string), "[PAYDAY:] Player %s start in character cash: %d$, in bank cash: %d$", gPlayerData[playerid][pName], gPlayerData[playerid][pCash], gPlayerData[playerid][pBank]);
					PayDayLog(string);
					if(gPlayerData[playerid][pIsOnVacation] > 0)
					{
						gPlayerData[playerid][pIsOnVacation]++;
						SavePlayerData(playerid, "IsOnVacation");
					}
					if((gPlayerData[playerid][pPlayingHours] <= 50 && gPlayerData[playerid][pLastLogged] >= 10) ||
						(gPlayerData[playerid][pPlayingHours] > 50 && gPlayerData[playerid][pLastLogged] >= 20) ||
						strlen(gPlayerData[playerid][pName]) <= 3 || gPlayerData[playerid][pAdmin] > 0 || gPlayerData[playerid][pSetToDelete] || gPlayerData[playerid][pIsOnVacation] > 0)
					{
						gPlayerData[playerid][pLastLogged]++;
						SavePlayerData(playerid, "LastLogged");
						format(string, sizeof(string), "[PAYDAY:] Player name = %s - payday is off (not logged for %d day(s)), is administrator or is set to delete", gPlayerData[playerid][pName], gPlayerData[playerid][pLastLogged] );
						PayDayLog(string);

						/*
						* Remove unproper/unused account
						*/
						if(!gPlayerData[playerid][pBanned] && !gPlayerData[playerid][pAdmin] && !IsPlayerVip(playerid) && (gPlayerData[playerid][pLastLogged] >= 60 || strlen(gPlayerData[playerid][pName]) <= 3 || 
							strfind(gPlayerData[playerid][pName], "_", true) == -1 || strfind(gPlayerData[playerid][pName], "[", true) > 0 || strfind(gPlayerData[playerid][pName], "]", true) > 0) || gPlayerData[playerid][pSetToDelete] || gPlayerData[playerid][pIsOnVacation] > 90)
						{
							format(string, sizeof(string), "DELETE FROM `samp_users` WHERE `PlayerName` = '%s' ", gPlayerData[playerid][pName]);
							mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
							format(string, sizeof(string), "DELETE FROM `samp_users_items` WHERE `PlayerName` = '%s' ", gPlayerData[playerid][pName]);
							mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
							format(string, sizeof(string), "DELETE FROM `samp_users_items2` WHERE `PlayerName` = '%s' ", gPlayerData[playerid][pName]);
							mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
							format(string, sizeof(string), "DELETE FROM `samp_users_items3` WHERE `PlayerName` = '%s' ", gPlayerData[playerid][pName]);
							mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
							format(string, sizeof(string), "DELETE FROM `samp_users_jobs` WHERE `PlayerName` = '%s' ", gPlayerData[playerid][pName]);
							mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
							format(string, sizeof(string), "DELETE FROM `samp_users_keys` WHERE `PlayerName` = '%s' ", gPlayerData[playerid][pName]);
							mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
							format(string, sizeof(string), "DELETE FROM `samp_users_lic` WHERE `PlayerName` = '%s' ", gPlayerData[playerid][pName]);
							mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
							format(string, sizeof(string), "DELETE FROM `samp_users_notes` WHERE `PlayerName` = '%s' ", gPlayerData[playerid][pName]);
							mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
							format(string, sizeof(string), "DELETE FROM `samp_users_vip` WHERE `PlayerName` = '%s' ", gPlayerData[playerid][pName]);
							mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
							format(string, sizeof(string), "DELETE FROM `samp_users_other` WHERE `PlayerName` = '%s' ", gPlayerData[playerid][pName]);
							mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
							format(string, sizeof(string), "DELETE FROM `samp_users_other2` WHERE `PlayerName` = '%s' ", gPlayerData[playerid][pName]);
							mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
							format(string, sizeof(string), "DELETE FROM `samp_users_fueled` WHERE `PlayerName` = '%s' ", gPlayerData[playerid][pName]);
							mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
							for(new i = 0; i < sizeof(gVehData); i++)
							{
								if(strcmp(gVehData[i][Owner], gPlayerData[playerid][pName], true, strlen(gPlayerData[playerid][pName])) == 0)
									defer ResetVehicleData(i+1, 1);
							}
							for(new i = 0; i < sizeof(Houses); i++)
							{
								if(strcmp(Houses[i][Owner], gPlayerData[playerid][pName], true, strlen(gPlayerData[playerid][pName])) == 0)
									ResetHouseData(i, 1);
							}
							for(new i = 0; i < sizeof(Businesses); i++)
							{
								if(strcmp(Businesses[i][Owner], gPlayerData[playerid][pName], true, strlen(gPlayerData[playerid][pName])) == 0)
									ResetBizData(i, 1);
							}
							format(string, sizeof(string), "[PAYDAY:] Player name = %s - account removed", gPlayerData[playerid][pName], gPlayerData[playerid][pLastLogged]);
							PayDayLog(string);
						}

						/*
						* Select next player in DB
						*/
						gPayDayLoop++;
						gPayDayID++;
						format(string, sizeof(string), "[PAYDAY:] gPayDayLoop = %d, gPayDayCount = %d", gPayDayLoop, gPayDayCount );
						PayDayLog(string);
						if(gPayDayLoop <= gPayDayCount)
						{
							format(string, sizeof(string), "SELECT `Key`,`ID`,`PlayerName`,`Level`,`AdminLevel`,`DonateRank`,`Registered`,`Sex`,`Age`,`Experience`,`Money`,`Bank`,`Skin`,`PlayingHours`,`AllowedPayday`,`PayCheck`,`Faction`,`Rank`,`Banned`");
							strcat( string, ",`Warnings`,`Jailed`,`JailTime`,`CrashX`,`CrashY`,`CrashZ`,`CrashInt`,`CrashW`,`Crashed`,`Wins`,`Loses`,`InvWeapon`,`InvAmmo`,`Tutorial`,`Moderator`,`WantedLvl`,`FirstCar`,`FirstReanimation`,`FirstPhone`,`FirstLeader`" );
							strcat( string, ",`CrashAngle`,`HourAssist`,`JoinedFaction`,`HoursOnDuty`,`HoursOnDutyHelper`,`WarnCooldown`,`SpeedLimiter`,`AdminDuty`,`CharDescription`,`CharDescriptionColor`, `FirstJob`, `FirstID`, `FirstBuy`, `FirstHouse`, `FirstDescription`" );
							strcat( string, ", `FirstAction`, `FirstBankUse`, `FirstStats`, `FirstJail`, `FirstStudy`" );
							format( string, sizeof(string), "%s FROM `samp_users` WHERE `Banned` = '0' LIMIT %d , 1", string, gPayDayLoop);
							mysql_query(string, PLAYER_DATA_LOAD_NAME_MYSQL, CUSTOM_MAX_PLAYERS, db_con4);
						}
						return 1;
					}

					/*
					* Set bank status befor PayDay for PayDay Message
					*/
					gPlayerData[CUSTOM_MAX_PLAYERS][pPayDayMessage] = 1;
					gPlayerData[CUSTOM_MAX_PLAYERS][pBankOld] = gPlayerData[CUSTOM_MAX_PLAYERS][pBank];
					gPlayerData[CUSTOM_MAX_PLAYERS][pBankIncome] = 0;
					gPlayerData[CUSTOM_MAX_PLAYERS][pBankLoose] = 0;
					SavePlayerData(playerid, "PayDayMessage");
					SavePlayerData(playerid, "BankOld");

					/*
					* Reduce drive licence days
					*/
					new slot[MAX_PLAYER_ITEM_SLOT];
					PHaveItemEx(playerid, 3, 4, slot);
					for(new i = 0; i < MAX_PLAYER_ITEM_SLOT; i++)
					{
						if(slot[i])
						{
							if(SlotParam1(playerid, i+1) > 0)
								SetPSlotParam1(playerid, i+1, SlotParam1(playerid, i+1)-1);
							if(SlotParam2(playerid, i+1) > 0)
								SetPSlotParam1(playerid, i+1, SlotParam2(playerid, i+1)-1);
							if(SlotParam3(playerid, i+1) > 0)
								SetPSlotParam1(playerid, i+1, SlotParam3(playerid, i+1)-1);
						}
					}
					
					/*
					* Credit repayment
					*/
					if(gPlayerData[playerid][mCreditValue] > 0)
					{
						gPlayerData[playerid][pBank] -= gPlayerData[playerid][mCreditRepayment];
						gPlayerData[playerid][mCreditPayed] += gPlayerData[playerid][mCreditRepayment];						
						gPlayerData[playerid][pBankLoose] += gPlayerData[playerid][mCreditRepayment];
						DynamicFactions[FACTIONID_GOVERNMENT][fBank] += gPlayerData[playerid][mCreditRepayment];
						SaveFData(FACTIONID_GOVERNMENT, "Bank");
						if(gPlayerData[playerid][mCreditPayed] >= gPlayerData[playerid][mCreditValue])
						{
							gPlayerData[playerid][mCreditRepayment] = 0;
							gPlayerData[playerid][mCreditPayed] = 0;
							gPlayerData[playerid][mCreditValue] = 0;
							SavePlayerData(playerid, "CreditRepayment");
							SavePlayerData(playerid, "CreditValue");
						}
						SavePlayerData(playerid, "CreditPayed");
					}
					
					/*
					* Pay for OC/AC
					*/
					PHaveItemEx(playerid, 3, 19, slot);
					for(new i = 1; i <= MAX_PLAYER_ITEM_SLOT; i++)
					{
						if(slot[i-1])
						{
							if(SlotParam3(playerid, i) > 0)
							{
								gPlayerData[playerid][pBank] -= 4;
								gPlayerData[CUSTOM_MAX_PLAYERS][pBankLoose] += 4;
								DynamicFactions[FACTIONID_GOVERNMENT][fBank] += 4;
							}
							if(SlotParam4(playerid, i) > 0)
							{
								gPlayerData[playerid][pBank] -= 6;
								gPlayerData[CUSTOM_MAX_PLAYERS][pBankLoose] += 6;
								DynamicFactions[FACTIONID_GOVERNMENT][fBank] += 6;
							}
						}
					}							
					
					/*
					* Give player faction payment and other payment
					*/
					if(gPlayerData[CUSTOM_MAX_PLAYERS][pFaction] != 255 && gPlayerData[playerid][pLastLogged] == 0)
					{
						for(new n = 0; n < sizeof(DynamicFactions); n++)
						{
							if(PayRank[n][FactionID] == gPlayerData[CUSTOM_MAX_PLAYERS][pFaction])
							{
								switch( gPlayerData[playerid][pRank] )
								{
									case 1:
									{
										format(string, sizeof(string), "[PAYDAY:] Player name = %s, rank 1, Bank = %d + %d, Faction id = %d, Bank = %d - %d",
											gPlayerData[playerid][pName], gPlayerData[playerid][pBank], PayRank[n][Rank2], gPlayerData[playerid][pFaction], DynamicFactions[gPlayerData[playerid][pFaction]][fBank], PayRank[n][Rank2]);
										gPlayerData[playerid][pBank] += PayRank[n][Rank1];
										gPlayerData[playerid][pBankIncome] += PayRank[n][Rank1];
										DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank1];
									}
									case 2:
									{
										format(string, sizeof(string), "[PAYDAY:] Player name = %s, rank 2, Bank = %d + %d, Faction id = %d, Bank = %d - %d",
											gPlayerData[playerid][pName], gPlayerData[playerid][pBank], PayRank[n][Rank2], gPlayerData[playerid][pFaction], DynamicFactions[gPlayerData[playerid][pFaction]][fBank], PayRank[n][Rank2]);
										gPlayerData[playerid][pBank] += PayRank[n][Rank2];
										gPlayerData[playerid][pBankIncome] += PayRank[n][Rank2];
										DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank2];
									}
									case 3:
									{
										format(string, sizeof(string), "[PAYDAY:] Player name = %s, rank 3, Bank = %d + %d, Faction id = %d, Bank = %d - %d",
											gPlayerData[playerid][pName], gPlayerData[playerid][pBank], PayRank[n][Rank2], gPlayerData[playerid][pFaction], DynamicFactions[gPlayerData[playerid][pFaction]][fBank], PayRank[n][Rank2]);
										gPlayerData[playerid][pBank] += PayRank[n][Rank3];
										gPlayerData[playerid][pBankIncome] += PayRank[n][Rank3];
										DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank3];
									}
									case 4:
									{
										format(string, sizeof(string), "[PAYDAY:] Player name = %s, rank 4, Bank = %d + %d, Faction id = %d, Bank = %d - %d",
											gPlayerData[playerid][pName], gPlayerData[playerid][pBank], PayRank[n][Rank2], gPlayerData[playerid][pFaction], DynamicFactions[gPlayerData[playerid][pFaction]][fBank], PayRank[n][Rank2]);
										gPlayerData[playerid][pBank] += PayRank[n][Rank4];
										gPlayerData[playerid][pBankIncome] += PayRank[n][Rank4];
										DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank4];
									}
									case 5:
									{
										format(string, sizeof(string), "[PAYDAY:] Player name = %s, rank 5, Bank = %d + %d, Faction id = %d, Bank = %d - %d",
											gPlayerData[playerid][pName], gPlayerData[playerid][pBank], PayRank[n][Rank2], gPlayerData[playerid][pFaction], DynamicFactions[gPlayerData[playerid][pFaction]][fBank], PayRank[n][Rank2]);
										gPlayerData[playerid][pBank] += PayRank[n][Rank5];
										gPlayerData[playerid][pBankIncome] += PayRank[n][Rank5];
										DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank5];
									}
									case 6:
									{
										format(string, sizeof(string), "[PAYDAY:] Player name = %s, rank 6, Bank = %d + %d, Faction id = %d, Bank = %d - %d",
											gPlayerData[playerid][pName], gPlayerData[playerid][pBank], PayRank[n][Rank2], gPlayerData[playerid][pFaction], DynamicFactions[gPlayerData[playerid][pFaction]][fBank], PayRank[n][Rank2]);
										gPlayerData[playerid][pBank] += PayRank[n][Rank6];
										gPlayerData[playerid][pBankIncome] += PayRank[n][Rank6];
										DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank6];
									}
									case 7:
									{
										format(string, sizeof(string), "[PAYDAY:] Player name = %s, rank 7, Bank = %d + %d, Faction id = %d, Bank = %d - %d",
											gPlayerData[playerid][pName], gPlayerData[playerid][pBank], PayRank[n][Rank2], gPlayerData[playerid][pFaction], DynamicFactions[gPlayerData[playerid][pFaction]][fBank], PayRank[n][Rank2]);
										gPlayerData[playerid][pBank] += PayRank[n][Rank7];
										gPlayerData[playerid][pBankIncome] += PayRank[n][Rank7];
										DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank7];
									}
									case 8:
									{
										format(string, sizeof(string), "[PAYDAY:] Player name = %s, rank 8, Bank = %d + %d, Faction id = %d, Bank = %d - %d",
											gPlayerData[playerid][pName], gPlayerData[playerid][pBank], PayRank[n][Rank2], gPlayerData[playerid][pFaction], DynamicFactions[gPlayerData[playerid][pFaction]][fBank], PayRank[n][Rank2]);
										gPlayerData[playerid][pBank] += PayRank[n][Rank8];
										gPlayerData[playerid][pBankIncome] += PayRank[n][Rank8];
										DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank8];
									}
									case 9:
									{
										format(string, sizeof(string), "[PAYDAY:] Player name = %s, rank 9, Bank = %d + %d, Faction id = %d, Bank = %d - %d",
											gPlayerData[playerid][pName], gPlayerData[playerid][pBank], PayRank[n][Rank2], gPlayerData[playerid][pFaction], DynamicFactions[gPlayerData[playerid][pFaction]][fBank], PayRank[n][Rank2]);
										gPlayerData[playerid][pBank] += PayRank[n][Rank9];
										gPlayerData[playerid][pBankIncome] += PayRank[n][Rank9];
										DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank9];
									}
									case 10:
									{
										format(string, sizeof(string), "[PAYDAY:] Player name = %s, rank 10, Bank = %d + %d, Faction id = %d, Bank = %d - %d",
											gPlayerData[playerid][pName], gPlayerData[playerid][pBank], PayRank[n][Rank2], gPlayerData[playerid][pFaction], DynamicFactions[gPlayerData[playerid][pFaction]][fBank], PayRank[n][Rank2]);
										gPlayerData[playerid][pBank] += PayRank[n][Rank10];
										gPlayerData[playerid][pBankIncome] += PayRank[n][Rank10];
										DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank10];
									}
								}
								PayDayLog(string);
								SaveFData( gPlayerData[playerid][pFaction], "Bank" );
								break;
							}
						}
					}
					if( gPlayerData[playerid][pJob] == 0 && gPlayerData[playerid][pFaction] == 255 )
					{
						format(string, sizeof(string), "[PAYDAY:] Player name = %s, Bank = %d + %d", gPlayerData[playerid][pName], gPlayerData[playerid][pBank], Zasilek);
						PayDayLog(string);
						gPlayerData[playerid][pBank] += Zasilek;
						gPlayerData[playerid][pBankIncome] += Zasilek;
						DynamicFactions[FACTIONID_GOVERNMENT][fBank] -= Zasilek;
						SaveFData( FACTIONID_GOVERNMENT, "Bank" );
					}

					/*
					* Pay taxes, costs, tickets, etc.
					*/
					format(string, sizeof(string), "[PAYDAY:] PlayerName = %s, Bank = %d - %d, SOURCE = Radio tax", gPlayerData[playerid][pName], gPlayerData[playerid][pBank], DynamicTaxes[RadioTax]);
					PayDayLog(string);
					gPlayerData[playerid][pBank] -= DynamicTaxes[RadioTax];
					gPlayerData[playerid][pBankLoose] += DynamicTaxes[RadioTax];
					DynamicFactions[FACTIONID_GOVERNMENT][fBank] += DynamicTaxes[RadioTax];
					if( ( gPlayerData[playerid][pCash] + gPlayerData[playerid][pBank] ) >= DynamicTaxes[TheRich] )
					{
						format(string, sizeof(string), "[PAYDAY:] PlayerName = %s, Bank = %d - %d, SOURCE = taxes (the rich)", gPlayerData[playerid][pName], gPlayerData[playerid][pBank], floatround( DynamicTaxes[RichTax] * (gPlayerData[playerid][pBank]+gPlayerData[playerid][pCash]), floatround_round));
						PayDayLog(string);
						gPlayerData[playerid][pBank] -= floatround( DynamicTaxes[RichTax] * (gPlayerData[playerid][pBank]+gPlayerData[playerid][pCash]), floatround_round);
						gPlayerData[playerid][pBankLoose] += floatround( DynamicTaxes[RichTax] * (gPlayerData[playerid][pBank]+gPlayerData[playerid][pCash]), floatround_round);
						DynamicFactions[FACTIONID_GOVERNMENT][fBank] += floatround( DynamicTaxes[RichTax] * (gPlayerData[playerid][pBank]+gPlayerData[playerid][pCash]), floatround_round);
					}
					if( gPlayerData[playerid][pCost] > 0 )
					{
						format(string, sizeof(string), "[PAYDAY:] PlayerName = %s, Bank = %d - %d, SOURCE = costs", gPlayerData[playerid][pName], gPlayerData[playerid][pBank], gPlayerData[playerid][pCost]);
						PayDayLog(string);
						gPlayerData[playerid][pBank] -= gPlayerData[playerid][pCost];
						gPlayerData[playerid][pBankLoose] += gPlayerData[playerid][pCost];						
						gPlayerData[playerid][pCost] = 0;
						SavePlayerData( playerid, "Cost" );
					}
					if( gPlayerData[playerid][pTicket] > 0 )
					{
						format(string, sizeof(string), "[PAYDAY:] PlayerName = %s, Bank = %d - %d, SOURCE = ticket", gPlayerData[playerid][pName], gPlayerData[playerid][pBank], gPlayerData[playerid][pTicket]);
						PayDayLog(string);
						gPlayerData[playerid][pBank] -= gPlayerData[playerid][pTicket];
						gPlayerData[playerid][pBankLoose] += gPlayerData[playerid][pTicket];
						DynamicFactions[FACTIONID_POLICE][fBank] += gPlayerData[playerid][pTicket];
						SaveFData( FACTIONID_POLICE, "Bank" );
						gPlayerData[playerid][pTicket] = 0;
						SavePlayerData( playerid, "Ticket" );
					}
					
					for(new i = 0; i < sizeof(Houses); i++)
					{
						if(strcmp(gPlayerData[playerid][pName], Houses[i][HRenter], false) == 0 && strlen(Houses[i][HRenter]) > 0)
						{
							if(gPlayerData[playerid][pBank] < 0)
							{
								strmid(Houses[i][HRenter], "Brak", 0, MAX_PLAYER_NAME, 255);
								SaveHouseData(i, "Renter");
								format(string, sizeof(string), "[PAYDAY:] PlayerName = %s, House rent deleted, House ID: %d", gPlayerData[playerid][pName], i);
								PayDayLog(string);
							}
							else
							{
								gPlayerData[playerid][pBank] -= Houses[i][RentCost];
								gPlayerData[playerid][pBankLoose] += Houses[i][RentCost];
								UpdatePlayerDataByName(Houses[i][Owner], "Bank", Houses[i][RentCost]);
								format(string, sizeof(string), "[PAYDAY:] PlayerName = %s, Bank = %d - %d, SOURCE = house rent, House ID: %d", gPlayerData[playerid][pName], gPlayerData[playerid][pBank], Houses[i][RentCost], i);
								PayDayLog(string);
							}
						}
					}

					/*
					* Is player on debt ?
					*/
					if( gPlayerData[playerid][pBank] < -5000 )
					{
						gPlayerData[playerid][pIsDeptor] = 1;
						SavePlayerData(playerid,"IsDeptor");
						for(new i = 0; i < sizeof(Houses); i++)
						{
							if( strcmp(Houses[i][Owner], gPlayerData[playerid][pName], true) == 0 && strlen(Houses[i][Owner]) > 0 )
							{
								format(string, sizeof(string), "[PAYDAY:] PlayerName = %s, House ID: %d, confiscated", gPlayerData[playerid][pName], i);
								PayDayLog(string);
								Houses[i][HConfiscated] = 1;
								SaveHouseData(i, "Confiscated");
							}
						}
						for(new i = 0; i < sizeof(Businesses); i++)
						{
							if( strcmp(Businesses[i][Owner], gPlayerData[playerid][pName], true) == 0 && strlen(Businesses[i][Owner]) > 0 )
							{
								format(string, sizeof(string), "[PAYDAY:] PlayerName = %s, Biz ID: %d, confiscated", gPlayerData[playerid][pName], i);
								PayDayLog(string);
								Businesses[i][BConfiscated] = 1;
								SaveBizData(i, "Confiscated");
							}
						}
						for(new i = 0; i < sizeof(gVehData); i++)
						{
							if( strcmp(gVehData[i][Owner], gPlayerData[playerid][pName], true) == 0 && strlen(gVehData[i][Owner]) > 0 )
							{
								format(string, sizeof(string), "[PAYDAY:] PlayerName = %s, Veh ID: %d, confiscated", gPlayerData[playerid][pName], i);
								PayDayLog(string);

								new enginedyn,lights,alarm,doors,bonnet,boot,objective;
								GetVehicleParamsEx(i+1,enginedyn,lights,alarm,doors,bonnet,boot,objective);
								SetVehicleParamsEx(i+1,enginedyn,lights,alarm,1,bonnet,boot,objective);

								gVehData[i][Closed] = 1;
								SaveVehData(i, "Closed");
								gVehData[i][VConfiscated] = 1;
								SaveVehData(i, "Confiscated");
							}
						}
					}
					else if( gPlayerData[playerid][pIsDeptor] && gPlayerData[playerid][pBank] >= -5000 )
					{
						gPlayerData[playerid][pIsDeptor] = 0;
						SavePlayerData(playerid,"IsDeptor");
						for(new i = 0; i < sizeof(Houses); i++)
						{
							if( strcmp(Houses[i][Owner], gPlayerData[playerid][pName], true) == 0 && strlen(Houses[i][Owner]) > 0 )
							{
								format(string, sizeof(string), "[PAYDAY:] PlayerName = %s, House ID: %d, deconfiscated", gPlayerData[playerid][pName], i);
								PayDayLog(string);

								Houses[i][HConfiscated] = 0;
								SaveHouseData(i, "Confiscated");
							}
						}
						for(new i = 0; i < sizeof(Businesses); i++)
						{
							if( strcmp(Businesses[i][Owner], gPlayerData[playerid][pName], true) == 0 && strlen(Businesses[i][Owner]) > 0 )
							{
								format(string, sizeof(string), "[PAYDAY:] PlayerName = %s, Biz ID: %d, deconfiscated", gPlayerData[playerid][pName], i);
								PayDayLog(string);

								Businesses[i][BConfiscated] = 0;
								SaveBizData(i, "Confiscated");
							}
						}
						for(new i = 0; i < sizeof(gVehData); i++)
						{
							if( strcmp(gVehData[i][Owner], gPlayerData[playerid][pName], true) == 0 && strlen(gVehData[i][Owner]) > 0 )
							{
								format(string, sizeof(string), "[PAYDAY:] PlayerName = %s, Veh ID: %d, deconfiscated", gPlayerData[playerid][pName], i);
								PayDayLog(string);

								new enginedyn,lights,alarm,doors,bonnet,boot,objective;
								GetVehicleParamsEx(i+1,enginedyn,lights,alarm,doors,bonnet,boot,objective);
								SetVehicleParamsEx(i+1,enginedyn,lights,alarm,0,bonnet,boot,objective);

								gVehData[i][Closed] = 0;
								SaveVehData(i, "Closed");
								gVehData[i][VConfiscated] = 0;
								SaveVehData(i, "Confiscated");
							}
						}
					}

					/*
					* Calculate and update player RP score
					*/
					gPlayerData[playerid][pScore] = ( gPlayerData[playerid][pRPCount] * 2 ) - ( gPlayerData[playerid][pDeathCount] * 100 ) /*+ floatround( (gPlayerData[playerid][pHoursOnDuty]/5), floatround_round )*/;
					SavePlayerData(playerid, "Score");

					/*
					* VIP reduce
					*/
					if( gVipReduceOn )
					{
						if(gPlayerData[playerid][pVipAFKT] > 0)
						{
							gPlayerData[playerid][pVipAFKT]--;
							SavePlayerData(playerid, "VipAFKT");
						}
						if(gPlayerData[playerid][pVipExpT] > 0)
						{
							gPlayerData[playerid][pVipExpT]--;
							SavePlayerData(playerid, "VipExpT");
						}
						if(gPlayerData[playerid][pVipItem] > 0)
						{
							gPlayerData[playerid][pVipItem]--;
							SavePlayerData(playerid, "VipItem");
						}
					}

					/*
					* Other stuff
					*/
					if(gPlayerData[playerid][pWarnings] > 0)
					{
						if(gPlayerData[playerid][pWarnCooldown] <= 0)
						{
							gPlayerData[playerid][pWarnings]--;
							SavePlayerData(playerid, "Warnings");
							gPlayerData[playerid][pWarnCooldown] = WARN_COOLDOWN;
						}
						else
						{
							gPlayerData[playerid][pWarnCooldown]--;
							SavePlayerData(playerid, "WarnCooldown");
						}
					}
					gPlayerData[playerid][pLastLogged]++;
					gPlayerData[playerid][pBankNew] = gPlayerData[playerid][pBank];
					SavePlayerData(playerid, "LastLogged");
					SavePlayerData(playerid, "Bank");
					SavePlayerData(playerid, "BankIncome");
					SavePlayerData(playerid, "BankLoose");
					SavePlayerData(playerid, "BankNew");

					// if( gPlayerData[playerid][pJobTimeChange] > 0 )
					// {
						// gPlayerData[playerid][pJobTimeChange]--;
						// SavePlayerData( playerid, "JobTimeChange" );
					// }

					format(string, sizeof(string), "[PAYDAY:] Player %s end in character cash: %d$, in bank cash: %d$", gPlayerData[playerid][pName], gPlayerData[playerid][pCash], gPlayerData[playerid][pBank]);
					PayDayLog(string);

					SaveFData( FACTIONID_GOVERNMENT, "Bank" );

					/*
					* Select next player in DB
					*/
					gPayDayLoop++;
					gPayDayID++;
					format(string, sizeof(string), "[PAYDAY:] gPayDayLoop = %d, gPayDayCount = %d", gPayDayLoop, gPayDayCount );
					PayDayLog(string);
					if( gPayDayLoop <= gPayDayCount )
					{
						format(string, sizeof(string), "SELECT `Key`,`ID`,`PlayerName`,`Level`,`AdminLevel`,`DonateRank`,`Registered`,`Sex`,`Age`,`Experience`,`Money`,`Bank`,`Skin`,`PlayingHours`,`AllowedPayday`,`PayCheck`,`Faction`,`Rank`,`Banned`");
						strcat( string, ",`Warnings`,`Jailed`,`JailTime`,`CrashX`,`CrashY`,`CrashZ`,`CrashInt`,`CrashW`,`Crashed`,`Wins`,`Loses`,`InvWeapon`,`InvAmmo`,`Tutorial`,`Moderator`,`WantedLvl`,`FirstCar`,`FirstReanimation`,`FirstPhone`,`FirstLeader`" );
						strcat( string, ",`CrashAngle`,`HourAssist`,`JoinedFaction`,`HoursOnDuty`,`HoursOnDutyHelper`,`WarnCooldown`,`SpeedLimiter`,`AdminDuty`,`CharDescription`,`CharDescriptionColor`, `FirstJob`, `FirstID`, `FirstBuy`, `FirstHouse`, `FirstDescription`" );
						strcat( string, ", `FirstAction`, `FirstBankUse`, `FirstStats`, `FirstJail`, `FirstStudy`" );
						format( string, sizeof(string), "%s FROM `samp_users` WHERE `Banned` = '0' LIMIT %d , 1", string, gPayDayLoop);
						mysql_query(string, PLAYER_DATA_LOAD_NAME_MYSQL, CUSTOM_MAX_PLAYERS, db_con4);
					}
				}
			}
		}
		case LOAD_RAFINERY:
		{
			if( !mysql_store_result(db_con2) )
			{
				ErrorLog("[ERROR:] Can't store result on LOAD_RAFINERY");
				GameModeExit();
				return 1;
			}
			mysql_fetch_row_format(db_result, "|", db_con2);

			split2(db_result, arrCoords, '|');
			mysql_free_result(db_con2);
			gRafinery[RafResourcePetrol] = strval(arrCoords[1]);
			gRafinery[RafPetrolLtrCost] = strval(arrCoords[2]);
			gRafinery[RafRefuelReward] = strval(arrCoords[3]);
			gRafinery[RafMaxResources] = strval(arrCoords[4]);
			gRafinery[RafResourceOil] = strval(arrCoords[5]);
			gRafinery[RafResourceGas] = strval(arrCoords[6]);
			gRafinery[RafOilLtrCost] = strval(arrCoords[7]);
			gRafinery[RafGasLtrCost] = strval(arrCoords[8]);

			#if defined DEBUG
				print("[INFO:] Rafinery loaded [MySQL]");
			#endif


		}
		case LOAD_WFACTORYLEGAL:
		{
			if( !mysql_store_result(db_con2) )
			{
				ErrorLog("[ERROR:] Can't store result on LOAD_WFACTORYLEGAL");
				GameModeExit();
				return 1;
			}
			mysql_fetch_row_format(db_result, "|", db_con2);
			split2(db_result, arrCoords, '|');

			//WFactoryLegalInfo[WFactoryID] = strval(arrCoords[0]); // narazie nie potrzebne

			mysql_fetch_field_row(string, "WFactoryBuildingID", db_con2);
			WFactoryLegal[WFactoryBuildingID] = strval(string);

			mysql_fetch_field_row(string, "WFactoryReward", db_con2);
			WFactoryLegal[WFactoryReward] = strval(string);
			mysql_fetch_field_row(string, "WFactoryCPPartTakeWV", db_con2);
			WFactoryLegal[WFactoryCPPartTakeWV] = strval(string);
			mysql_fetch_field_row(string, "WFactoryCPPartTakeInt", db_con2);
			WFactoryLegal[WFactoryCPPartTakeInt] = strval(string);
			mysql_fetch_field_row(string, "WFactoryCPPartTakeX", db_con2);
			WFactoryLegal[WFactoryCPPartTakeX] = strval(string);
			mysql_fetch_field_row(string, "WFactoryCPPartTakeY", db_con2);
			WFactoryLegal[WFactoryCPPartTakeY] = strval(string);
			mysql_fetch_field_row(string, "WFactoryCPPartTakeZ", db_con2);
			WFactoryLegal[WFactoryCPPartTakeZ] = strval(string);
			mysql_fetch_field_row(string, "WFactoryCPPartSetup1X", db_con2);
			WFactoryLegal[WFactoryCPPartSetup1X] = strval(string);
			mysql_fetch_field_row(string, "WFactoryCPPartSetup1Y", db_con2);
			WFactoryLegal[WFactoryCPPartSetup1Y] = strval(string);
			mysql_fetch_field_row(string, "WFactoryCPPartSetup1Z", db_con2);
			WFactoryLegal[WFactoryCPPartSetup1Z] = strval(string);
			mysql_fetch_field_row(string, "WFactoryCPPartSetup2X", db_con2);
			WFactoryLegal[WFactoryCPPartSetup2X] = strval(string);
			mysql_fetch_field_row(string, "WFactoryCPPartSetup2Y", db_con2);
			WFactoryLegal[WFactoryCPPartSetup2Y] = strval(string);
			mysql_fetch_field_row(string, "WFactoryCPPartSetup2Z", db_con2);
			WFactoryLegal[WFactoryCPPartSetup2Z] = strval(string);
			mysql_fetch_field_row(string, "WFactoryCPPartSetup3X", db_con2);
			WFactoryLegal[WFactoryCPPartSetup3X] = strval(string);
			mysql_fetch_field_row(string, "WFactoryCPPartSetup3Y", db_con2);
			WFactoryLegal[WFactoryCPPartSetup3Y] = strval(string);
			mysql_fetch_field_row(string, "WFactoryCPPartSetup3Z", db_con2);
			WFactoryLegal[WFactoryCPPartSetup3Z] = strval(string);
			mysql_fetch_field_row(string, "WFactoryCPPartSetup4X", db_con2);
			WFactoryLegal[WFactoryCPPartSetup4X] = strval(string);
			mysql_fetch_field_row(string, "WFactoryCPPartSetup4Y", db_con2);
			WFactoryLegal[WFactoryCPPartSetup4Y] = strval(string);
			mysql_fetch_field_row(string, "WFactoryCPPartSetup4Z", db_con2);
			WFactoryLegal[WFactoryCPPartSetup4Z] = strval(string);
			mysql_fetch_field_row(string, "WFactoryCPPartSetup5X", db_con2);
			WFactoryLegal[WFactoryCPPartSetup5X] = strval(string);
			mysql_fetch_field_row(string, "WFactoryCPPartSetup5Y", db_con2);
			WFactoryLegal[WFactoryCPPartSetup5Y] = strval(string);
			mysql_fetch_field_row(string, "WFactoryCPPartSetup5Z", db_con2);
			WFactoryLegal[WFactoryCPPartSetup5Z] = strval(string);
			mysql_fetch_field_row(string, "WFactoryCPPartSetup6X", db_con2);
			WFactoryLegal[WFactoryCPPartSetup6X] = strval(string);
			mysql_fetch_field_row(string, "WFactoryCPPartSetup6Y", db_con2);
			WFactoryLegal[WFactoryCPPartSetup6Y] = strval(string);
			mysql_fetch_field_row(string, "WFactoryCPPartSetup6Z", db_con2);
			WFactoryLegal[WFactoryCPPartSetup6Z] = strval(string);
			mysql_fetch_field_row(string, "WFactoryCPAmmoSetup1X", db_con2);
			WFactoryLegal[WFactoryCPAmmoSetup1X] = strval(string);
			mysql_fetch_field_row(string, "WFactoryCPAmmoSetup1Y", db_con2);
			WFactoryLegal[WFactoryCPAmmoSetup1Y] = strval(string);
			mysql_fetch_field_row(string, "WFactoryCPAmmoSetup1Z", db_con2);
			WFactoryLegal[WFactoryCPAmmoSetup1Z] = strval(string);
			mysql_fetch_field_row(string, "WFactoryCPAmmoSetup2X", db_con2);
			WFactoryLegal[WFactoryCPAmmoSetup2X] = strval(string);
			mysql_fetch_field_row(string, "WFactoryCPAmmoSetup2Y", db_con2);
			WFactoryLegal[WFactoryCPAmmoSetup2Y] = strval(string);
			mysql_fetch_field_row(string, "WFactoryCPAmmoSetup2Z", db_con2);
			WFactoryLegal[WFactoryCPAmmoSetup2Z] = strval(string);
			mysql_fetch_field_row(string, "WFactoryCPAmmoSetup3X", db_con2);
			WFactoryLegal[WFactoryCPAmmoSetup3X] = strval(string);
			mysql_fetch_field_row(string, "WFactoryCPAmmoSetup3Y", db_con2);
			WFactoryLegal[WFactoryCPAmmoSetup3Y] = strval(string);
			mysql_fetch_field_row(string, "WFactoryCPAmmoSetup3Z", db_con2);
			WFactoryLegal[WFactoryCPAmmoSetup3Z] = strval(string);
			mysql_fetch_field_row(string, "WFactoryCPAmmoSetup4X", db_con2);
			WFactoryLegal[WFactoryCPAmmoSetup4X] = strval(string);
			mysql_fetch_field_row(string, "WFactoryCPAmmoSetup4Y", db_con2);
			WFactoryLegal[WFactoryCPAmmoSetup4Y] = strval(string);
			mysql_fetch_field_row(string, "WFactoryCPAmmoSetup4Z", db_con2);
			WFactoryLegal[WFactoryCPAmmoSetup4Z] = strval(string);
			mysql_fetch_field_row(string, "WFactoryCPAmmoSetup5X", db_con2);
			WFactoryLegal[WFactoryCPAmmoSetup5X] = strval(string);
			mysql_fetch_field_row(string, "WFactoryCPAmmoSetup5Y", db_con2);
			WFactoryLegal[WFactoryCPAmmoSetup5Y] = strval(string);
			mysql_fetch_field_row(string, "WFactoryCPAmmoSetup5Z", db_con2);
			WFactoryLegal[WFactoryCPAmmoSetup5Z] = strval(string);
			mysql_fetch_field_row(string, "WFactoryCPAmmoSetup6X", db_con2);
			WFactoryLegal[WFactoryCPAmmoSetup6X] = strval(string);
			mysql_fetch_field_row(string, "WFactoryCPAmmoSetup6Y", db_con2);
			WFactoryLegal[WFactoryCPAmmoSetup6Y] = strval(string);
			mysql_fetch_field_row(string, "WFactoryCPAmmoSetup6Z", db_con2);
			WFactoryLegal[WFactoryCPAmmoSetup6Z] = strval(string);
			mysql_fetch_field_row(string, "WFactoryCPDocsX", db_con2);
			WFactoryLegal[WFactoryCPDocsX] = strval(string);
			mysql_fetch_field_row(string, "WFactoryCPDocsY", db_con2);
			WFactoryLegal[WFactoryCPDocsY] = strval(string);
			mysql_fetch_field_row(string, "WFactoryCPDocsZ", db_con2);
			WFactoryLegal[WFactoryCPDocsZ] = strval(string);
			mysql_fetch_field_row(string, "WFactory9MM", db_con2);
			WFactoryLegalLight[WFactory9MM] = strval(string);
			mysql_fetch_field_row(string, "WFactory9MMO", db_con2);
			WFactoryLegalLight[WFactory9MMO] = strval(string);
			mysql_fetch_field_row(string, "WFactory9MMSil", db_con2);
			WFactoryLegalLight[WFactory9MMSil] = strval(string);
			mysql_fetch_field_row(string, "WFactory9MMSilO", db_con2);
			WFactoryLegalLight[WFactory9MMSilO] = strval(string);
			mysql_fetch_field_row(string, "WFactoryDesEagle", db_con2);
			WFactoryLegalLight[WFactoryDesEagle] = strval(string);
			mysql_fetch_field_row(string, "WFactoryDesEagleO", db_con2);
			WFactoryLegalLight[WFactoryDesEagleO] = strval(string);
			mysql_fetch_field_row(string, "WFactoryMicroSMG", db_con2);
			WFactoryLegalLight[WFactoryMicroSMG] = strval(string);
			mysql_fetch_field_row(string, "WFactoryMicroSMGO", db_con2);
			WFactoryLegalLight[WFactoryMicroSMGO] = strval(string);
			mysql_fetch_field_row(string, "WFactoryMP5", db_con2);
			WFactoryLegalLight[WFactoryMP5] = strval(string);
			mysql_fetch_field_row(string, "WFactoryMP5O", db_con2);
			WFactoryLegalLight[WFactoryMP5O] = strval(string);
			mysql_fetch_field_row(string, "WFactoryTec9", db_con2);
			WFactoryLegalLight[WFactoryTec9] = strval(string);
			mysql_fetch_field_row(string, "WFactoryTec9O", db_con2);
			WFactoryLegalLight[WFactoryTec9O] = strval(string);
			mysql_fetch_field_row(string, "WFactoryShotgun", db_con2);
			WFactoryLegalHeavy[WFactoryShotgun] = strval(string);
			mysql_fetch_field_row(string, "WFactoryShotgunO", db_con2);
			WFactoryLegalHeavy[WFactoryShotgunO] = strval(string);
			mysql_fetch_field_row(string, "WFactoryAK47", db_con2);
			WFactoryLegalHeavy[WFactoryAK47] = strval(string);
			mysql_fetch_field_row(string, "WFactoryAK47O", db_con2);
			WFactoryLegalHeavy[WFactoryAK47O] = strval(string);
			mysql_fetch_field_row(string, "WFactoryM4", db_con2);
			WFactoryLegalHeavy[WFactoryM4] = strval(string);
			mysql_fetch_field_row(string, "WFactoryM4O", db_con2);
			WFactoryLegalHeavy[WFactoryM4O] = strval(string);
			mysql_fetch_field_row(string, "WFactoryRifle", db_con2);
			WFactoryLegalHeavy[WFactoryRifle] = strval(string);
			mysql_fetch_field_row(string, "WFactoryRifleO", db_con2);
			WFactoryLegalHeavy[WFactoryRifleO] = strval(string);
			mysql_fetch_field_row(string, "WFactorySRifle", db_con2);
			WFactoryLegalHeavy[WFactorySRifle] = strval(string);
			mysql_fetch_field_row(string, "WFactorySRifleO", db_con2);
			WFactoryLegalHeavy[WFactorySRifleO] = strval(string);
			mysql_fetch_field_row(string, "WFactorySCharge", db_con2);
			WFactoryLegalHeavy[WFactorySCharge] = strval(string);
			mysql_fetch_field_row(string, "WFactory9MMAmmo", db_con2);
			WFactoryLegalLight[WFactory9MMAmmo] = strval(string);
			mysql_fetch_field_row(string, "WFactory50AEAmmo", db_con2);
			WFactoryLegalLight[WFactory50AEAmmo] = strval(string);
			mysql_fetch_field_row(string, "WFactoryBuckshot", db_con2);
			WFactoryLegalHeavy[WFactoryBuckshot] = strval(string);
			mysql_fetch_field_row(string, "WFactory762MMAmmo", db_con2);
			WFactoryLegalHeavy[WFactory762MMAmmo] = strval(string);
			mysql_fetch_field_row(string, "WFactory127MMAmmo", db_con2);
			WFactoryLegalHeavy[WFactory127MMAmmo] = strval(string);
			mysql_fetch_field_row(string, "WFactoryKGP66MMAmmo", db_con2);
			WFactoryLegalHeavy[WFactoryKGP66MMAmmo] = strval(string);
			mysql_fetch_field_row(string, "WFactoryNapalm", db_con2);
			WFactoryLegalHeavy[WFactoryNapalm] = strval(string);
			mysql_fetch_field_row(string, "WFactoryPistolPart1", db_con2);
			WFactoryLegalLight[WFactoryPistolPart1] = strval(string);
			mysql_fetch_field_row(string, "WFactoryPistolS1Part1", db_con2);
			WFactoryLegalLight[WFactoryPistolS1Part1] = strval(string);
			mysql_fetch_field_row(string, "WFactoryPistolS1Part2", db_con2);
			WFactoryLegalLight[WFactoryPistolS1Part2] = strval(string);
			mysql_fetch_field_row(string, "WFactoryPistolS1Part3", db_con2);
			WFactoryLegalLight[WFactoryPistolS1Part3] = strval(string);
			mysql_fetch_field_row(string, "WFactoryPistolPart2", db_con2);
			WFactoryLegalLight[WFactoryPistolPart2] = strval(string);
			mysql_fetch_field_row(string, "WFactoryPistolS2Part1", db_con2);
			WFactoryLegalLight[WFactoryPistolS2Part1] = strval(string);
			mysql_fetch_field_row(string, "WFactoryPistolS2Part2", db_con2);
			WFactoryLegalLight[WFactoryPistolS2Part2] = strval(string);
			mysql_fetch_field_row(string, "WFactoryPistolS2Part3", db_con2);
			WFactoryLegalLight[WFactoryPistolS2Part3] = strval(string);
			mysql_fetch_field_row(string, "WFactoryPistolPart3", db_con2);
			WFactoryLegalLight[WFactoryPistolPart3] = strval(string);
			mysql_fetch_field_row(string, "WFactoryPistolS3Part1", db_con2);
			WFactoryLegalLight[WFactoryPistolS3Part1] = strval(string);
			mysql_fetch_field_row(string, "WFactoryPistolS3Part2", db_con2);
			WFactoryLegalLight[WFactoryPistolS3Part2] = strval(string);
			mysql_fetch_field_row(string, "WFactoryPistolS3Part3", db_con2);
			WFactoryLegalLight[WFactoryPistolS3Part3] = strval(string);
			mysql_fetch_field_row(string, "WFactoryPistolS3Part4", db_con2);
			WFactoryLegalLight[WFactoryPistolS3Part4] = strval(string);
			mysql_fetch_field_row(string, "WFactoryPistolPart4", db_con2);
			WFactoryLegalLight[WFactoryPistolPart4] = strval(string);
			mysql_fetch_field_row(string, "WFactoryPistolPart5", db_con2);
			WFactoryLegalLight[WFactoryPistolPart5] = strval(string);
			mysql_fetch_field_row(string, "WFactoryPistolPart6", db_con2);
			WFactoryLegalLight[WFactoryPistolPart6] = strval(string);
			mysql_fetch_field_row(string, "WFactoryRiflePart1", db_con2);
			WFactoryLegalHeavy[WFactoryRiflePart1] = strval(string);
			mysql_fetch_field_row(string, "WFactoryRifleS1Part1", db_con2);
			WFactoryLegalHeavy[WFactoryRifleS1Part1] = strval(string);
			mysql_fetch_field_row(string, "WFactoryRifleS1Part2", db_con2);
			WFactoryLegalHeavy[WFactoryRifleS1Part2] = strval(string);
			// mysql_fetch_field_row(string, "WFactoryRifleS1Part3", db_con2);
			// WFactoryLegalHeavy[WFactoryRifleS1Part3] = strval(string);
			mysql_fetch_field_row(string, "WFactoryRiflePart2", db_con2);
			WFactoryLegalHeavy[WFactoryRiflePart2] = strval(string);
			mysql_fetch_field_row(string, "WFactoryRifleS2Part1", db_con2);
			WFactoryLegalHeavy[WFactoryRifleS2Part1] = strval(string);
			mysql_fetch_field_row(string, "WFactoryRifleS2Part2", db_con2);
			WFactoryLegalHeavy[WFactoryRifleS2Part2] = strval(string);
			mysql_fetch_field_row(string, "WFactoryRifleS2Part3", db_con2);
			WFactoryLegalHeavy[WFactoryRifleS2Part3] = strval(string);
			mysql_fetch_field_row(string, "WFactoryRiflePart3", db_con2);
			WFactoryLegalHeavy[WFactoryRiflePart3] = strval(string);
			mysql_fetch_field_row(string, "WFactoryRifleS3Part4", db_con2);
			WFactoryLegalHeavy[WFactoryRifleS3Part4] = strval(string);
			mysql_fetch_field_row(string, "WFactoryRifleS3Part4", db_con2);
			WFactoryLegalHeavy[WFactoryRifleS3Part4] = strval(string);
			mysql_fetch_field_row(string, "WFactoryRifleS3Part4", db_con2);
			WFactoryLegalHeavy[WFactoryRifleS3Part4] = strval(string);
			mysql_fetch_field_row(string, "WFactoryRifleS3Part4", db_con2);
			WFactoryLegalHeavy[WFactoryRifleS3Part4] = strval(string);
			mysql_fetch_field_row(string, "WFactoryRiflePart4", db_con2);
			WFactoryLegalHeavy[WFactoryRiflePart4] = strval(string);
			mysql_fetch_field_row(string, "WFactoryRiflePart5", db_con2);
			WFactoryLegalHeavy[WFactoryRiflePart5] = strval(string);
			mysql_fetch_field_row(string, "WFactoryRiflePart6", db_con2);
			WFactoryLegalHeavy[WFactoryRiflePart6] = strval(string);
			mysql_fetch_field_row(string, "WFactoryRiflePart7", db_con2);
			WFactoryLegalHeavy[WFactoryRiflePart7] = strval(string);
			mysql_fetch_field_row(string, "WFactoryAmmoPart1a", db_con2);
			WFactoryLegalLight[WFactoryAmmoPart1a] = strval(string);
			mysql_fetch_field_row(string, "WFactoryAmmoPart2a", db_con2);
			WFactoryLegalLight[WFactoryAmmoPart2a] = strval(string);
			mysql_fetch_field_row(string, "WFactoryAmmoPart3a", db_con2);
			WFactoryLegalLight[WFactoryAmmoPart3a] = strval(string);
			mysql_fetch_field_row(string, "WFactoryAmmoPart4a", db_con2);
			WFactoryLegalLight[WFactoryAmmoPart4a] = strval(string);
			mysql_fetch_field_row(string, "WFactoryAmmoPart1b", db_con2);
			WFactoryLegalLight[WFactoryAmmoPart1b] = strval(string);
			mysql_fetch_field_row(string, "WFactoryAmmoPart2b", db_con2);
			WFactoryLegalLight[WFactoryAmmoPart2b] = strval(string);
			mysql_fetch_field_row(string, "WFactoryAmmoPart3b", db_con2);
			WFactoryLegalLight[WFactoryAmmoPart3b] = strval(string);
			mysql_fetch_field_row(string, "WFactoryAmmoPart4b", db_con2);
			WFactoryLegalLight[WFactoryAmmoPart4b] = strval(string);
			mysql_fetch_field_row(string, "WFactoryAmmoPart1c", db_con2);
			WFactoryLegalLight[WFactoryAmmoPart1c] = strval(string);
			mysql_fetch_field_row(string, "WFactoryAmmoPart2c", db_con2);
			WFactoryLegalLight[WFactoryAmmoPart2c] = strval(string);
			mysql_fetch_field_row(string, "WFactoryAmmoPart3c", db_con2);
			WFactoryLegalLight[WFactoryAmmoPart3c] = strval(string);
			mysql_fetch_field_row(string, "WFactoryAmmoPart4c", db_con2);
			WFactoryLegalLight[WFactoryAmmoPart4c] = strval(string);
			mysql_fetch_field_row(string, "WFactoryAmmoPart1d", db_con2);
			WFactoryLegalLight[WFactoryAmmoPart1d] = strval(string);
			mysql_fetch_field_row(string, "WFactoryAmmoPart2d", db_con2);
			WFactoryLegalLight[WFactoryAmmoPart2d] = strval(string);
			mysql_fetch_field_row(string, "WFactoryAmmoPart3d", db_con2);
			WFactoryLegalLight[WFactoryAmmoPart3d] = strval(string);
			mysql_fetch_field_row(string, "WFactoryAmmoPart4d", db_con2);
			WFactoryLegalLight[WFactoryAmmoPart4d] = strval(string);
			mysql_fetch_field_row(string, "WFactoryAmmoPart1e", db_con2);
			WFactoryLegalLight[WFactoryAmmoPart1e] = strval(string);
			mysql_fetch_field_row(string, "WFactoryAmmoPart2e", db_con2);
			WFactoryLegalLight[WFactoryAmmoPart2e] = strval(string);
			mysql_fetch_field_row(string, "WFactoryAmmoPart3e", db_con2);
			WFactoryLegalLight[WFactoryAmmoPart3e] = strval(string);
			mysql_fetch_field_row(string, "WFactoryAmmoPart4e", db_con2);
			WFactoryLegalLight[WFactoryAmmoPart4e] = strval(string);
			mysql_fetch_field_row(string, "WFactoryTec9Part", db_con2);
			WFactoryLegalLight[WFactoryTec9Part] = strval(string);
			mysql_fetch_field_row(string, "WFactoryMP5Part", db_con2);
			WFactoryLegalHeavy[WFactoryMP5Part] = strval(string);
			mysql_fetch_field_row(string, "WFactoryAK47Part", db_con2);
			WFactoryLegalHeavy[WFactoryAK47Part] = strval(string);
			mysql_fetch_field_row(string, "WFactoryM4Part", db_con2);
			WFactoryLegalHeavy[WFactoryM4Part] = strval(string);
			mysql_fetch_field_row(string, "WFactoryShotPart", db_con2);
			WFactoryLegalHeavy[WFactoryShotPart] = strval(string);
			mysql_fetch_field_row(string, "WFactoryDesEaglePart", db_con2);
			WFactoryLegalLight[WFactoryDesEaglePart] = strval(string);
			mysql_fetch_field_row(string, "WFactoryRiflePart", db_con2);
			WFactoryLegalHeavy[WFactoryRiflePart] = strval(string);
			mysql_fetch_field_row(string, "WFactorySniperPart", db_con2);
			WFactoryLegalHeavy[WFactorySniperPart] = strval(string);

			mysql_free_result(db_con2);

			WFactoryLegal[WFactoryCPDocsID] = CreateDynamicCP( WFactoryLegal[WFactoryCPDocsX], WFactoryLegal[WFactoryCPDocsY], WFactoryLegal[WFactoryCPDocsZ], 1.0, -1, -1, -1, 5.0 );
			WFactoryLegal[WFactoryCPDocsID2] = CreateDynamicCP(211.24,-64.05,1.57, 1.0, -1, -1, -1, 5.0 );
			WFactoryLegal[WFactoryCPDocsID3] = CreateDynamicCP(-2068.2,8.56,35.32, 1.0, -1, -1, -1, 5.0 );
			WFactoryLegal[WFactoryCPDocsID4] = CreateDynamicCP(2456.92,-2119.48,13.55, 1.0, -1, -1, -1, 5.0 );
			WFactoryLegal[WFactoryCPDocsID5] = CreateDynamicCP(2812.24,972.54,10.75, 1.0, -1, -1, -1, 5.0 );
			WFactoryLegal[WFactoryCPDocsID6] = CreateDynamicCP(-2113.79,-2287.28,30.63, 1.0, -1, -1, -1, 5.0 );
			WFactoryLegal[WFactoryCPDocsID7] = CreateDynamicCP(-1532.95,2609.53,55.83, 1.0, -1, -1, -1, 5.0 );

			WFactoryLegal[WFactoryCPPartTakeID] = CreateDynamicCP( WFactoryLegal[WFactoryCPPartTakeX], WFactoryLegal[WFactoryCPPartTakeY], WFactoryLegal[WFactoryCPPartTakeZ], 2.0, WFactoryLegal[WFactoryCPPartTakeWV], WFactoryLegal[WFactoryCPPartTakeInt], -1, 10.0 );
			WFactoryLegal[WFactoryCPPartSetup1ID] = CreateDynamicCP( WFactoryLegal[WFactoryCPPartSetup1X], WFactoryLegal[WFactoryCPPartSetup1Y], WFactoryLegal[WFactoryCPPartSetup1Z], 2.0, WFactoryLegal[WFactoryCPPartTakeWV], WFactoryLegal[WFactoryCPPartTakeInt], -1, 10.0 );
			WFactoryLegal[WFactoryCPPartSetup2ID] = CreateDynamicCP( WFactoryLegal[WFactoryCPPartSetup2X], WFactoryLegal[WFactoryCPPartSetup2Y], WFactoryLegal[WFactoryCPPartSetup2Z], 2.0, WFactoryLegal[WFactoryCPPartTakeWV], WFactoryLegal[WFactoryCPPartTakeInt], -1, 10.0 );
			WFactoryLegal[WFactoryCPPartSetup3ID] = CreateDynamicCP( WFactoryLegal[WFactoryCPPartSetup3X], WFactoryLegal[WFactoryCPPartSetup3Y], WFactoryLegal[WFactoryCPPartSetup3Z], 2.0, WFactoryLegal[WFactoryCPPartTakeWV], WFactoryLegal[WFactoryCPPartTakeInt], -1, 10.0 );
			WFactoryLegal[WFactoryCPPartSetup4ID] = CreateDynamicCP( WFactoryLegal[WFactoryCPPartSetup4X], WFactoryLegal[WFactoryCPPartSetup4Y], WFactoryLegal[WFactoryCPPartSetup4Z], 2.0, WFactoryLegal[WFactoryCPPartTakeWV], WFactoryLegal[WFactoryCPPartTakeInt], -1, 10.0 );
			WFactoryLegal[WFactoryCPPartSetup5ID] = CreateDynamicCP( WFactoryLegal[WFactoryCPPartSetup5X], WFactoryLegal[WFactoryCPPartSetup5Y], WFactoryLegal[WFactoryCPPartSetup5Z], 2.0, WFactoryLegal[WFactoryCPPartTakeWV], WFactoryLegal[WFactoryCPPartTakeInt], -1, 10.0 );
			WFactoryLegal[WFactoryCPPartSetup6ID] = CreateDynamicCP( WFactoryLegal[WFactoryCPPartSetup6X], WFactoryLegal[WFactoryCPPartSetup6Y], WFactoryLegal[WFactoryCPPartSetup6Z], 2.0, WFactoryLegal[WFactoryCPPartTakeWV], WFactoryLegal[WFactoryCPPartTakeInt], -1, 10.0 );
			WFactoryLegal[WFactoryCPAmmoSetup1ID] = CreateDynamicCP( WFactoryLegal[WFactoryCPAmmoSetup1X], WFactoryLegal[WFactoryCPAmmoSetup1Y], WFactoryLegal[WFactoryCPAmmoSetup1Z], 2.0, WFactoryLegal[WFactoryCPPartTakeWV], WFactoryLegal[WFactoryCPPartTakeInt], -1, 10.0 );
			WFactoryLegal[WFactoryCPAmmoSetup2ID] = CreateDynamicCP( WFactoryLegal[WFactoryCPAmmoSetup2X], WFactoryLegal[WFactoryCPAmmoSetup2Y], WFactoryLegal[WFactoryCPAmmoSetup2Z], 2.0, WFactoryLegal[WFactoryCPPartTakeWV], WFactoryLegal[WFactoryCPPartTakeInt], -1, 10.0 );
			WFactoryLegal[WFactoryCPAmmoSetup3ID] = CreateDynamicCP( WFactoryLegal[WFactoryCPAmmoSetup3X], WFactoryLegal[WFactoryCPAmmoSetup3Y], WFactoryLegal[WFactoryCPAmmoSetup3Z], 2.0, WFactoryLegal[WFactoryCPPartTakeWV], WFactoryLegal[WFactoryCPPartTakeInt], -1, 10.0 );
			WFactoryLegal[WFactoryCPAmmoSetup4ID] = CreateDynamicCP( WFactoryLegal[WFactoryCPAmmoSetup4X], WFactoryLegal[WFactoryCPAmmoSetup4Y], WFactoryLegal[WFactoryCPAmmoSetup4Z], 2.0, WFactoryLegal[WFactoryCPPartTakeWV], WFactoryLegal[WFactoryCPPartTakeInt], -1, 10.0 );
			WFactoryLegal[WFactoryCPAmmoSetup5ID] = CreateDynamicCP( WFactoryLegal[WFactoryCPAmmoSetup5X], WFactoryLegal[WFactoryCPAmmoSetup5Y], WFactoryLegal[WFactoryCPAmmoSetup5Z], 2.0, WFactoryLegal[WFactoryCPPartTakeWV], WFactoryLegal[WFactoryCPPartTakeInt], -1, 10.0 );
			WFactoryLegal[WFactoryCPAmmoSetup6ID] = CreateDynamicCP( WFactoryLegal[WFactoryCPAmmoSetup6X], WFactoryLegal[WFactoryCPAmmoSetup6Y], WFactoryLegal[WFactoryCPAmmoSetup6Z], 2.0, WFactoryLegal[WFactoryCPPartTakeWV], WFactoryLegal[WFactoryCPPartTakeInt], -1, 10.0 );

			#if defined DEBUG
				print("[INFO:] Legal weapon factory loaded [MySQL]");
			#endif
		}
		case LOAD_GAS_STATIONS:
		{
			if( !mysql_store_result(db_con2) )
			{
				ErrorLog("[ERROR:] Can't store result on LOAD_GAS_STATIONS");
				GameModeExit();
				return 1;
			}
			new i = 0;

			while(mysql_fetch_row_format(db_result, "|", db_con2))
			{
				split2(db_result, arrCoords, '|');

				GasStations[i][BusinessID] = strval(arrCoords[1]);
				GasStations[i][PetrolResourceValue] = floatstr(arrCoords[2]);
				GasStations[i][OilResourceValue] = floatstr(arrCoords[3]);
				GasStations[i][GasResourceValue] = floatstr(arrCoords[4]);
				GasStations[i][MaxPetrolResourceValue] = floatstr(arrCoords[5]);
				GasStations[i][MaxOilResourceValue] = floatstr(arrCoords[6]);
				GasStations[i][MaxGasResourceValue] = floatstr(arrCoords[7]);
				GasStations[i][RefuelPetrolResources] = strval(arrCoords[8]);
				GasStations[i][RefuelOilResources] = strval(arrCoords[9]);
				GasStations[i][RefuelGasResources] = strval(arrCoords[10]);
				GasStations[i][PetrolPrice] = strval(arrCoords[11]);
				GasStations[i][OilPrice] = strval(arrCoords[12]);
				GasStations[i][GasPrice] = strval(arrCoords[13]);
				GasStations[i][GSposX] = floatstr(arrCoords[14]);
				GasStations[i][GSposY] = floatstr(arrCoords[15]);
				GasStations[i][GSposZ] = floatstr(arrCoords[16]);
				GasStations[i][Pos3dTextX] = floatstr(arrCoords[17]);
				GasStations[i][Pos3dTextY] = floatstr(arrCoords[18]);
				GasStations[i][Pos3dTextZ] = floatstr(arrCoords[19]);
				GasStations[i][Pos3dTextX2] = floatstr(arrCoords[20]);
				GasStations[i][Pos3dTextY2] = floatstr(arrCoords[21]);
				GasStations[i][Pos3dTextZ2] = floatstr(arrCoords[22]);
				GasStations[i][Pos3dTextX3] = floatstr(arrCoords[23]);
				GasStations[i][Pos3dTextY3] = floatstr(arrCoords[24]);
				GasStations[i][Pos3dTextZ3] = floatstr(arrCoords[25]);
				GasStations[i][Pos3dTextX4] = floatstr(arrCoords[26]);
				GasStations[i][Pos3dTextY4] = floatstr(arrCoords[27]);
				GasStations[i][Pos3dTextZ4] = floatstr(arrCoords[28]);

				format(string, sizeof(string), "Benzyna: %d$", GasStations[i][PetrolPrice]);
				GasStations[i][GS3dTextLabel] = CreateDynamic3DTextLabel(string, COLOR_GREEN, GasStations[i][Pos3dTextX], GasStations[i][Pos3dTextY], GasStations[i][Pos3dTextZ], 50.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID);
				format(string, sizeof(string), "Diesel: %d$", GasStations[i][OilPrice]);
				GasStations[i][GS3dTextLabel2] = CreateDynamic3DTextLabel(string, COLOR_GREEN, GasStations[i][Pos3dTextX2], GasStations[i][Pos3dTextY2], GasStations[i][Pos3dTextZ2], 50.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID);
				format(string, sizeof(string), "Gaz: %d$", GasStations[i][GasPrice]);
				GasStations[i][GS3dTextLabel3] = CreateDynamic3DTextLabel(string, COLOR_GREEN, GasStations[i][Pos3dTextX3], GasStations[i][Pos3dTextY3], GasStations[i][Pos3dTextZ3], 50.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID);
				format(string, sizeof(string), "Nr stacji: %d", i+1);
				GasStations[i][GS3dTextLabel4] = CreateDynamic3DTextLabel(string, COLOR_GREEN, GasStations[i][Pos3dTextX4], GasStations[i][Pos3dTextY4], GasStations[i][Pos3dTextZ4], 50.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID);

				// printf("GasStation ID: %d,  GSposX = %f, GSposY = %f, GSposZ = %f", i, GasStations[i][GSposX], GasStations[i][GSposY], GasStations[i][GSposZ] );

				i++;
			}
			#if defined DEBUG
				print("[INFO:] Gas stations data loaded [MySQL]");
			#endif

			mysql_free_result(db_con2);
		}
		case COUNT_PAYDAY:
		{
			if(mysql_store_result(db_con2) != 0)
			{
				format(string, sizeof(string), "MYSQL STORE RESULT failed in COUNT_PAYDAY");
				ErrorLog(string);
			}
			if(!mysql_fetch_field_row(fieldCount, "founder_count", db_con2))
			{
				format(string, sizeof(string), "MYSQL FETCH FIELD failed in COUNT_PAYDAY");
				ErrorLog(string);
			}

			gPayDayLoop = 0;
			gPayDayID = 0;
			gPayDayCount = mysql_fetch_int(db_con2);
			
			mysql_free_result(db_con2);
			
			format(string, sizeof(string), "[PAYDAY:] PayDayCount = %d", gPayDayCount);
			PayDayLog(string);
			PayDayLog("[PAYDAY:] Loading first player from DB");

			format(string, sizeof(string), "SELECT `Key`,`ID`,`PlayerName`,`Level`,`AdminLevel`,`DonateRank`,`Registered`,`Sex`,`Age`,`Experience`,`Money`,`Bank`,`Skin`,`PlayingHours`,`AllowedPayday`,`PayCheck`,`Faction`,`Rank`,`Banned`");
			strcat( string, ",`Warnings`,`Jailed`,`JailTime`,`CrashX`,`CrashY`,`CrashZ`,`CrashInt`,`CrashW`,`Crashed`,`Wins`,`Loses`,`InvWeapon`,`InvAmmo`,`Tutorial`,`Moderator`,`WantedLvl`,`FirstCar`,`FirstReanimation`,`FirstPhone`,`FirstLeader`" );
			strcat( string, ",`CrashAngle`,`HourAssist`,`JoinedFaction`,`HoursOnDuty`,`HoursOnDutyHelper`,`WarnCooldown`,`SpeedLimiter`,`AdminDuty`,`CharDescription`,`CharDescriptionColor`, `FirstJob`, `FirstID`, `FirstBuy`, `FirstHouse`, `FirstDescription`" );
			strcat( string, ", `FirstAction`, `FirstBankUse`, `FirstStats`, `FirstJail`, `FirstStudy`" );
			format( string, sizeof(string), "%s FROM `samp_users` WHERE `Banned` = '0' LIMIT %d , 1", string, gPayDayLoop);
			mysql_query(string, PLAYER_DATA_LOAD_NAME_MYSQL, CUSTOM_MAX_PLAYERS, db_con4);
		}
		case UPDATE_DATA:
		{
			if(!mysql_store_result(db_con3))
			{
				ErrorLog("[ERROR:] Can't store result on UPDATE");
				return 1;
			}
			mysql_fetch_field_row(string, "Bank", db_con3);
			gPlayerData[CUSTOM_MAX_PLAYERS][pBank] = strval(string);
			mysql_fetch_field_row(gPlayerData[CUSTOM_MAX_PLAYERS][pName], "PlayerName", db_con3);
			mysql_free_result(db_con3);
			// printf("[DEBUG:] case UPDATE, debug bank value to add: %d", spareid);
			format(string, sizeof(string), "UPDATE `samp_users` SET `Bank` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[CUSTOM_MAX_PLAYERS][pBank]+extraid, gPlayerData[CUSTOM_MAX_PLAYERS][pName]);
			mysql_query(string, SAVE, playerid, db_con3);
			return 1;
		}
		case SAVE:
		{
			// mysql_free_result(db_con2);
		}
		case SAVE2:
		{
			// mysql_free_result(db_con3);
		}
		case SAVE3:
		{
			// mysql_free_result(db_con4);
		}
		case LOAD_FACTIONS_PAYRANK:
		{
			if( !mysql_store_result(db_con2) )
			{
				ErrorLog("[ERROR:] Can't store result on LOAD_FACTIONS_PAYRANK");
				GameModeExit();
				return 1;
			}
			new i = 0;

			while(mysql_fetch_row_format(db_result, "|", db_con2))
			{
				split2(db_result, arrCoords, '|');

				PayRank[i][FactionID] = strval(arrCoords[1]);
				PayRank[i][Rank1] = strval(arrCoords[2]);
				PayRank[i][Rank2] = strval(arrCoords[3]);
				PayRank[i][Rank3] = strval(arrCoords[4]);
				PayRank[i][Rank4] = strval(arrCoords[5]);
				PayRank[i][Rank5] = strval(arrCoords[6]);
				PayRank[i][Rank6] = strval(arrCoords[7]);
				PayRank[i][Rank7] = strval(arrCoords[8]);
				PayRank[i][Rank8] = strval(arrCoords[9]);
				PayRank[i][Rank9] = strval(arrCoords[10]);
				PayRank[i][Rank10] = strval(arrCoords[11]);
				i++;
			}
			#if defined DEBUG
				print("[INFO:] Factions payments loaded [MySQL]");
			#endif

			mysql_free_result(db_con2);
		}
		case LOAD_DYNAMIC_FACTIONS_WEAPONS2:
		{
			if(mysql_store_result(db_con2))
			{
				new fid;

				while(mysql_fetch_row_format(db_result, "|", db_con2))
				{
					split2(db_result, arrCoords, '|');

					fid = strval(arrCoords[30]);

					DynamicFactions[fid][fAmmo1Rank1] = strval(arrCoords[0]);
					DynamicFactions[fid][fAmmo1Rank2] = strval(arrCoords[1]);
					DynamicFactions[fid][fAmmo1Rank3] = strval(arrCoords[2]);
					DynamicFactions[fid][fAmmo1Rank4] = strval(arrCoords[3]);
					DynamicFactions[fid][fAmmo1Rank5] = strval(arrCoords[4]);
					DynamicFactions[fid][fAmmo1Rank6] = strval(arrCoords[5]);
					DynamicFactions[fid][fAmmo1Rank7] = strval(arrCoords[6]);
					DynamicFactions[fid][fAmmo1Rank8] = strval(arrCoords[7]);
					DynamicFactions[fid][fAmmo1Rank9] = strval(arrCoords[8]);
					DynamicFactions[fid][fAmmo1Rank10] = strval(arrCoords[9]);
					DynamicFactions[fid][fAmmo2Rank1] = strval(arrCoords[10]);
					DynamicFactions[fid][fAmmo2Rank2] = strval(arrCoords[11]);
					DynamicFactions[fid][fAmmo2Rank3] = strval(arrCoords[12]);
					DynamicFactions[fid][fAmmo2Rank4] = strval(arrCoords[13]);
					DynamicFactions[fid][fAmmo2Rank5] = strval(arrCoords[14]);
					DynamicFactions[fid][fAmmo2Rank6] = strval(arrCoords[15]);
					DynamicFactions[fid][fAmmo2Rank7] = strval(arrCoords[16]);
					DynamicFactions[fid][fAmmo2Rank8] = strval(arrCoords[17]);
					DynamicFactions[fid][fAmmo2Rank9] = strval(arrCoords[18]);
					DynamicFactions[fid][fAmmo2Rank10] = strval(arrCoords[19]);
					DynamicFactions[fid][fAmmo3Rank1] = strval(arrCoords[20]);
					DynamicFactions[fid][fAmmo3Rank2] = strval(arrCoords[21]);
					DynamicFactions[fid][fAmmo3Rank3] = strval(arrCoords[22]);
					DynamicFactions[fid][fAmmo3Rank4] = strval(arrCoords[23]);
					DynamicFactions[fid][fAmmo3Rank5] = strval(arrCoords[24]);
					DynamicFactions[fid][fAmmo3Rank6] = strval(arrCoords[25]);
					DynamicFactions[fid][fAmmo3Rank7] = strval(arrCoords[26]);
					DynamicFactions[fid][fAmmo3Rank8] = strval(arrCoords[27]);
					DynamicFactions[fid][fAmmo3Rank9] = strval(arrCoords[28]);
					DynamicFactions[fid][fAmmo3Rank10] = strval(arrCoords[29]);
				}
				#if defined DEBUG
					print("[INFO:] Faction weapons data part 2/2 loaded [MySQL]");
				#endif
			}
			else
			{
				print("[INFO:] Wystapil blad przy pobieraniu danych broni frakcji 2");
				GameModeExit();
			}
			mysql_free_result(db_con2);


		}
		case LOAD_DYNAMIC_FACTIONS_WEAPONS:
		{
			if(mysql_store_result(db_con2))
			{
				new fid;

				while(mysql_fetch_row_format(db_result, "|", db_con2))
				{
					split2(db_result, arrCoords, '|');

					fid = strval(arrCoords[30]);

					DynamicFactions[fid][fGun1Rank1] = strval(arrCoords[0]);
					DynamicFactions[fid][fGun1Rank2] = strval(arrCoords[1]);
					DynamicFactions[fid][fGun1Rank3] = strval(arrCoords[2]);
					DynamicFactions[fid][fGun1Rank4] = strval(arrCoords[3]);
					DynamicFactions[fid][fGun1Rank5] = strval(arrCoords[4]);
					DynamicFactions[fid][fGun1Rank6] = strval(arrCoords[5]);
					DynamicFactions[fid][fGun1Rank7] = strval(arrCoords[6]);
					DynamicFactions[fid][fGun1Rank8] = strval(arrCoords[7]);
					DynamicFactions[fid][fGun1Rank9] = strval(arrCoords[8]);
					DynamicFactions[fid][fGun1Rank10] = strval(arrCoords[9]);
					DynamicFactions[fid][fGun2Rank1] = strval(arrCoords[10]);
					DynamicFactions[fid][fGun2Rank2] = strval(arrCoords[11]);
					DynamicFactions[fid][fGun2Rank3] = strval(arrCoords[12]);
					DynamicFactions[fid][fGun2Rank4] = strval(arrCoords[13]);
					DynamicFactions[fid][fGun2Rank5] = strval(arrCoords[14]);
					DynamicFactions[fid][fGun2Rank6] = strval(arrCoords[15]);
					DynamicFactions[fid][fGun2Rank7] = strval(arrCoords[16]);
					DynamicFactions[fid][fGun2Rank8] = strval(arrCoords[17]);
					DynamicFactions[fid][fGun2Rank9] = strval(arrCoords[18]);
					DynamicFactions[fid][fGun2Rank10] = strval(arrCoords[19]);
					DynamicFactions[fid][fGun3Rank1] = strval(arrCoords[20]);
					DynamicFactions[fid][fGun3Rank2] = strval(arrCoords[21]);
					DynamicFactions[fid][fGun3Rank3] = strval(arrCoords[22]);
					DynamicFactions[fid][fGun3Rank4] = strval(arrCoords[23]);
					DynamicFactions[fid][fGun3Rank5] = strval(arrCoords[24]);
					DynamicFactions[fid][fGun3Rank6] = strval(arrCoords[25]);
					DynamicFactions[fid][fGun3Rank7] = strval(arrCoords[26]);
					DynamicFactions[fid][fGun3Rank8] = strval(arrCoords[27]);
					DynamicFactions[fid][fGun3Rank9] = strval(arrCoords[28]);
					DynamicFactions[fid][fGun3Rank10] = strval(arrCoords[29]);
				}
				#if defined DEBUG
					print("[INFO:] Faction weapons data part 1/2 loaded [MySQL]");
				#endif
			}
			else
			{
				print("[INFO:] Wystapil problem przy pobieraniu danych broni frakcji 1");
				GameModeExit();
			}
			mysql_free_result(db_con2);
		}
		case RELOAD_DYNAMIC_FACTIONS:
		{
			if(mysql_store_result(db_con2))
			{
				new i;
				i = 0;

				while(mysql_fetch_row_format(db_result, "|", db_con2))
				{
					mysql_fetch_field_row(DynamicFactions[i][Name], "Name", db_con2);
					mysql_fetch_field_row(DynamicFactions[i][fRank1], "Rank1", db_con2);
					mysql_fetch_field_row(DynamicFactions[i][fRank2], "Rank2", db_con2);
					mysql_fetch_field_row(DynamicFactions[i][fRank3], "Rank3", db_con2);
					mysql_fetch_field_row(DynamicFactions[i][fRank4], "Rank4", db_con2);
					mysql_fetch_field_row(DynamicFactions[i][fRank5], "Rank5", db_con2);
					mysql_fetch_field_row(DynamicFactions[i][fRank6], "Rank6", db_con2);
					mysql_fetch_field_row(DynamicFactions[i][fRank7], "Rank7", db_con2);
					mysql_fetch_field_row(DynamicFactions[i][fRank8], "Rank8", db_con2);
					mysql_fetch_field_row(DynamicFactions[i][fRank9], "Rank9", db_con2);
					mysql_fetch_field_row(DynamicFactions[i][fRank10], "Rank10", db_con2);
					mysql_fetch_field_row(string, "Skin1", db_con2);
					DynamicFactions[i][fSkin1] = strval(string);
					mysql_fetch_field_row(string, "Skin2", db_con2);
					DynamicFactions[i][fSkin2] = strval(string);
					mysql_fetch_field_row(string, "Skin3", db_con2);
					DynamicFactions[i][fSkin3] = strval(string);
					mysql_fetch_field_row(string, "Skin4", db_con2);
					DynamicFactions[i][fSkin4] = strval(string);
					mysql_fetch_field_row(string, "Skin5", db_con2);
					DynamicFactions[i][fSkin5] = strval(string);
					mysql_fetch_field_row(string, "Skin6", db_con2);
					DynamicFactions[i][fSkin6] = strval(string);
					mysql_fetch_field_row(string, "Skin7", db_con2);
					DynamicFactions[i][fSkin7] = strval(string);
					mysql_fetch_field_row(string, "Skin8", db_con2);
					DynamicFactions[i][fSkin8] = strval(string);
					mysql_fetch_field_row(string, "Skin9", db_con2);
					DynamicFactions[i][fSkin9] = strval(string);
					mysql_fetch_field_row(string, "Skin10", db_con2);
					DynamicFactions[i][fSkin10] = strval(string);
					mysql_fetch_field_row(string, "JoinRank", db_con2);
					DynamicFactions[i][fJoinRank] = strval(string);
					mysql_fetch_field_row(string, "UseSkins", db_con2);
					DynamicFactions[i][fUseSkins] = strval(string);
					mysql_fetch_field_row(string, "RankAmount", db_con2);
					DynamicFactions[i][fRankAmount] = strval(string);

					i++;
				}
				#if defined DEBUG
					print("[INFO:] Faction data reloaded [MySQL]");
				#endif
			}
			else
			{
				print("[INFO:] Wystapil problem przy przeladowywaniu danych frakcji");
			}
			mysql_free_result(db_con2);
		}
		case LOAD_DYNAMIC_FACTIONS:
		{
			#if defined DEBUG
				print("[INFO:] Factions loading started...");
			#endif
			if(!mysql_store_result(db_con2))
			{
				print("[INFO:] Wystapil problem przy pobieraniu danych frakcji");
				GameModeExit();
				return 1;
			}
			if(mysql_num_rows(db_con2) == 0)
			{
				print("[INFO:] Brak wpisów we frakcjach !");
			}
			new i, Float:px, Float:py, Float:pz;
			i = 0;
			while(mysql_fetch_row_format(db_result, "|", db_con2))
			{
				mysql_fetch_field_row(DynamicFactions[i][Name], "Name", db_con2);
				mysql_fetch_field_row(string, "IsEnabled", db_con2);
				DynamicFactions[i][IsEnabled] = strval(string);
				mysql_fetch_field_row(string, "X", db_con2);
				DynamicFactions[i][m_fX] = floatstr(string);
				mysql_fetch_field_row(string, "Y", db_con2);
				DynamicFactions[i][m_fY] = floatstr(string);
				mysql_fetch_field_row(string, "Z", db_con2);
				DynamicFactions[i][m_fZ] = floatstr(string);
				mysql_fetch_field_row(string, "Materials", db_con2);
				DynamicFactions[i][fMaterials] = strval(string);
				mysql_fetch_field_row(string, "Drugs", db_con2);
				DynamicFactions[i][fDrugs] = strval(string);
				mysql_fetch_field_row(string, "Bank", db_con2);
				DynamicFactions[i][fBank] = strval(string);
				mysql_fetch_field_row(DynamicFactions[i][fRank1], "Rank1", db_con2);
				mysql_fetch_field_row(DynamicFactions[i][fRank2], "Rank2", db_con2);
				mysql_fetch_field_row(DynamicFactions[i][fRank3], "Rank3", db_con2);
				mysql_fetch_field_row(DynamicFactions[i][fRank4], "Rank4", db_con2);
				mysql_fetch_field_row(DynamicFactions[i][fRank5], "Rank5", db_con2);
				mysql_fetch_field_row(DynamicFactions[i][fRank6], "Rank6", db_con2);
				mysql_fetch_field_row(DynamicFactions[i][fRank7], "Rank7", db_con2);
				mysql_fetch_field_row(DynamicFactions[i][fRank8], "Rank8", db_con2);
				mysql_fetch_field_row(DynamicFactions[i][fRank9], "Rank9", db_con2);
				mysql_fetch_field_row(DynamicFactions[i][fRank10], "Rank10", db_con2);
				mysql_fetch_field_row(string, "Skin1", db_con2);
				DynamicFactions[i][fSkin1] = strval(string);
				mysql_fetch_field_row(string, "Skin2", db_con2);
				DynamicFactions[i][fSkin2] = strval(string);
				mysql_fetch_field_row(string, "Skin3", db_con2);
				DynamicFactions[i][fSkin3] = strval(string);
				mysql_fetch_field_row(string, "Skin4", db_con2);
				DynamicFactions[i][fSkin4] = strval(string);
				mysql_fetch_field_row(string, "Skin5", db_con2);
				DynamicFactions[i][fSkin5] = strval(string);
				mysql_fetch_field_row(string, "Skin6", db_con2);
				DynamicFactions[i][fSkin6] = strval(string);
				mysql_fetch_field_row(string, "Skin7", db_con2);
				DynamicFactions[i][fSkin7] = strval(string);
				mysql_fetch_field_row(string, "Skin8", db_con2);
				DynamicFactions[i][fSkin8] = strval(string);
				mysql_fetch_field_row(string, "Skin9", db_con2);
				DynamicFactions[i][fSkin9] = strval(string);
				mysql_fetch_field_row(string, "Skin10", db_con2);
				DynamicFactions[i][fSkin10] = strval(string);
				
				mysql_fetch_field_row(string, "Rank2TillCheck", db_con2);
				DynamicFactions[i][fRank2TillCheck] = strval(string);
				mysql_fetch_field_row(string, "Rank2FactionStatus", db_con2);
				DynamicFactions[i][fRank2FactionStatus] = strval(string);
				mysql_fetch_field_row(string, "Rank2VehBuy", db_con2);
				DynamicFactions[i][fRank2VehBuy] = strval(string);
				mysql_fetch_field_row(string, "Rank2VehSell", db_con2);
				DynamicFactions[i][fRank2VehSell] = strval(string);
				mysql_fetch_field_row(string, "Rank2VehSalvage", db_con2);
				DynamicFactions[i][fRank2VehSalvage] = strval(string);
				mysql_fetch_field_row(string, "Rank2VehDrive", db_con2);
				DynamicFactions[i][fRank2VehDrive] = strval(string);
				mysql_fetch_field_row(string, "Rank2TerritoryWar", db_con2);
				DynamicFactions[i][fRank2TerritoryWar] = strval(string);		
				mysql_fetch_field_row(string, "Rank2BurnFactory", db_con2);
				DynamicFactions[i][fRank2BurnFactory] = strval(string);				
				mysql_fetch_field_row(string, "Rank3TillCheck", db_con2);
				DynamicFactions[i][fRank3TillCheck] = strval(string);
				mysql_fetch_field_row(string, "Rank3FactionStatus", db_con2);
				DynamicFactions[i][fRank3FactionStatus] = strval(string);
				mysql_fetch_field_row(string, "Rank3VehBuy", db_con2);
				DynamicFactions[i][fRank3VehBuy] = strval(string);
				mysql_fetch_field_row(string, "Rank3VehSell", db_con2);
				DynamicFactions[i][fRank3VehSell] = strval(string);
				mysql_fetch_field_row(string, "Rank3VehSalvage", db_con2);
				DynamicFactions[i][fRank3VehSalvage] = strval(string);
				mysql_fetch_field_row(string, "Rank3VehDrive", db_con2);
				DynamicFactions[i][fRank3VehDrive] = strval(string);
				mysql_fetch_field_row(string, "Rank3TerritoryWar", db_con2);
				DynamicFactions[i][fRank3TerritoryWar] = strval(string);			
				mysql_fetch_field_row(string, "Rank3BurnFactory", db_con2);
				DynamicFactions[i][fRank3BurnFactory] = strval(string);			
				mysql_fetch_field_row(string, "Rank4TillCheck", db_con2);
				DynamicFactions[i][fRank4TillCheck] = strval(string);
				mysql_fetch_field_row(string, "Rank4FactionStatus", db_con2);
				DynamicFactions[i][fRank4FactionStatus] = strval(string);
				mysql_fetch_field_row(string, "Rank4VehBuy", db_con2);
				DynamicFactions[i][fRank4VehBuy] = strval(string);
				mysql_fetch_field_row(string, "Rank4VehSell", db_con2);
				DynamicFactions[i][fRank4VehSell] = strval(string);
				mysql_fetch_field_row(string, "Rank4VehSalvage", db_con2);
				DynamicFactions[i][fRank4VehSalvage] = strval(string);
				mysql_fetch_field_row(string, "Rank4VehDrive", db_con2);
				DynamicFactions[i][fRank4VehDrive] = strval(string);
				mysql_fetch_field_row(string, "Rank4TerritoryWar", db_con2);
				DynamicFactions[i][fRank4TerritoryWar] = strval(string);				
				mysql_fetch_field_row(string, "Rank4BurnFactory", db_con2);
				DynamicFactions[i][fRank4BurnFactory] = strval(string);		
				mysql_fetch_field_row(string, "Rank5TillCheck", db_con2);
				DynamicFactions[i][fRank5TillCheck] = strval(string);
				mysql_fetch_field_row(string, "Rank5FactionStatus", db_con2);
				DynamicFactions[i][fRank5FactionStatus] = strval(string);
				mysql_fetch_field_row(string, "Rank5VehBuy", db_con2);
				DynamicFactions[i][fRank5VehBuy] = strval(string);
				mysql_fetch_field_row(string, "Rank5VehSell", db_con2);
				DynamicFactions[i][fRank5VehSell] = strval(string);
				mysql_fetch_field_row(string, "Rank5VehSalvage", db_con2);
				DynamicFactions[i][fRank5VehSalvage] = strval(string);
				mysql_fetch_field_row(string, "Rank5VehDrive", db_con2);
				DynamicFactions[i][fRank5VehDrive] = strval(string);
				mysql_fetch_field_row(string, "Rank5TerritoryWar", db_con2);
				DynamicFactions[i][fRank5TerritoryWar] = strval(string);	
				mysql_fetch_field_row(string, "Rank5BurnFactory", db_con2);
				DynamicFactions[i][fRank5BurnFactory] = strval(string);	
				mysql_fetch_field_row(string, "Rank6TillCheck", db_con2);
				DynamicFactions[i][fRank6TillCheck] = strval(string);
				mysql_fetch_field_row(string, "Rank6FactionStatus", db_con2);
				DynamicFactions[i][fRank6FactionStatus] = strval(string);
				mysql_fetch_field_row(string, "Rank6VehBuy", db_con2);
				DynamicFactions[i][fRank6VehBuy] = strval(string);
				mysql_fetch_field_row(string, "Rank6VehSell", db_con2);
				DynamicFactions[i][fRank6VehSell] = strval(string);
				mysql_fetch_field_row(string, "Rank6VehSalvage", db_con2);
				DynamicFactions[i][fRank6VehSalvage] = strval(string);
				mysql_fetch_field_row(string, "Rank6VehDrive", db_con2);
				DynamicFactions[i][fRank6VehDrive] = strval(string);
				mysql_fetch_field_row(string, "Rank6TerritoryWar", db_con2);
				DynamicFactions[i][fRank6TerritoryWar] = strval(string);					
				mysql_fetch_field_row(string, "Rank6BurnFactory", db_con2);
				DynamicFactions[i][fRank6BurnFactory] = strval(string);	
				mysql_fetch_field_row(string, "Rank7TillCheck", db_con2);
				DynamicFactions[i][fRank7TillCheck] = strval(string);
				mysql_fetch_field_row(string, "Rank7FactionStatus", db_con2);
				DynamicFactions[i][fRank7FactionStatus] = strval(string);
				mysql_fetch_field_row(string, "Rank7VehBuy", db_con2);
				DynamicFactions[i][fRank7VehBuy] = strval(string);
				mysql_fetch_field_row(string, "Rank7VehSell", db_con2);
				DynamicFactions[i][fRank7VehSell] = strval(string);
				mysql_fetch_field_row(string, "Rank7VehSalvage", db_con2);
				DynamicFactions[i][fRank7VehSalvage] = strval(string);
				mysql_fetch_field_row(string, "Rank7VehDrive", db_con2);
				DynamicFactions[i][fRank7VehDrive] = strval(string);
				mysql_fetch_field_row(string, "Rank7TerritoryWar", db_con2);
				DynamicFactions[i][fRank7TerritoryWar] = strval(string);		
				mysql_fetch_field_row(string, "Rank7BurnFactory", db_con2);
				DynamicFactions[i][fRank7BurnFactory] = strval(string);				
				mysql_fetch_field_row(string, "Rank8TillCheck", db_con2);
				DynamicFactions[i][fRank8TillCheck] = strval(string);
				mysql_fetch_field_row(string, "Rank8FactionStatus", db_con2);
				DynamicFactions[i][fRank8FactionStatus] = strval(string);
				mysql_fetch_field_row(string, "Rank8VehBuy", db_con2);
				DynamicFactions[i][fRank8VehBuy] = strval(string);
				mysql_fetch_field_row(string, "Rank8VehSell", db_con2);
				DynamicFactions[i][fRank8VehSell] = strval(string);
				mysql_fetch_field_row(string, "Rank8VehSalvage", db_con2);
				DynamicFactions[i][fRank8VehSalvage] = strval(string);
				mysql_fetch_field_row(string, "Rank8VehDrive", db_con2);
				DynamicFactions[i][fRank8VehDrive] = strval(string);
				mysql_fetch_field_row(string, "Rank8TerritoryWar", db_con2);
				DynamicFactions[i][fRank8TerritoryWar] = strval(string);					
				mysql_fetch_field_row(string, "Rank8BurnFactory", db_con2);
				DynamicFactions[i][fRank8BurnFactory] = strval(string);	
				mysql_fetch_field_row(string, "Rank9TillCheck", db_con2);
				DynamicFactions[i][fRank9TillCheck] = strval(string);
				mysql_fetch_field_row(string, "Rank9FactionStatus", db_con2);
				DynamicFactions[i][fRank9FactionStatus] = strval(string);
				mysql_fetch_field_row(string, "Rank9VehBuy", db_con2);
				DynamicFactions[i][fRank9VehBuy] = strval(string);
				mysql_fetch_field_row(string, "Rank9VehSell", db_con2);
				DynamicFactions[i][fRank9VehSell] = strval(string);
				mysql_fetch_field_row(string, "Rank9VehSalvage", db_con2);
				DynamicFactions[i][fRank9VehSalvage] = strval(string);
				mysql_fetch_field_row(string, "Rank9VehDrive", db_con2);
				DynamicFactions[i][fRank9VehDrive] = strval(string);
				mysql_fetch_field_row(string, "Rank9TerritoryWar", db_con2);
				DynamicFactions[i][fRank9TerritoryWar] = strval(string);		
				mysql_fetch_field_row(string, "Rank9BurnFactory", db_con2);
				DynamicFactions[i][fRank9BurnFactory] = strval(string);				
				mysql_fetch_field_row(string, "Rank10TillCheck", db_con2);
				DynamicFactions[i][fRank10TillCheck] = strval(string);
				mysql_fetch_field_row(string, "Rank10FactionStatus", db_con2);
				DynamicFactions[i][fRank10FactionStatus] = strval(string);
				mysql_fetch_field_row(string, "Rank10VehBuy", db_con2);
				DynamicFactions[i][fRank10VehBuy] = strval(string);
				mysql_fetch_field_row(string, "Rank10VehSell", db_con2);
				DynamicFactions[i][fRank10VehSell] = strval(string);
				mysql_fetch_field_row(string, "Rank10VehSalvage", db_con2);
				DynamicFactions[i][fRank10VehSalvage] = strval(string);
				mysql_fetch_field_row(string, "Rank10VehDrive", db_con2);
				DynamicFactions[i][fRank10VehDrive] = strval(string);
				mysql_fetch_field_row(string, "Rank10TerritoryWar", db_con2);
				DynamicFactions[i][fRank10TerritoryWar] = strval(string);	
				mysql_fetch_field_row(string, "Rank10BurnFactory", db_con2);
				DynamicFactions[i][fRank10BurnFactory] = strval(string);	
				
				mysql_fetch_field_row(string, "JoinRank", db_con2);
				DynamicFactions[i][fJoinRank] = strval(string);
				mysql_fetch_field_row(string, "UseSkins", db_con2);
				DynamicFactions[i][fUseSkins] = strval(string);
				mysql_fetch_field_row(string, "Type", db_con2);
				DynamicFactions[i][fType] = strval(string);
				mysql_fetch_field_row(string, "RankAmount", db_con2);
				DynamicFactions[i][fRankAmount] = strval(string);
				mysql_fetch_field_row(DynamicFactions[i][fColor], "Color", db_con2);
				mysql_fetch_field_row(string, "MaxCars", db_con2);
				DynamicFactions[i][fMaxCars] = strval(string);
				mysql_fetch_field_row(string, "CarsCount", db_con2);
				DynamicFactions[i][fCarsCount] = strval(string);
				mysql_fetch_field_row(string, "XDuty", db_con2);
				DynamicFactions[i][fXDuty] = floatstr(string);
				mysql_fetch_field_row(string, "YDuty", db_con2);
				DynamicFactions[i][fYDuty] = floatstr(string);
				mysql_fetch_field_row(string, "ZDuty", db_con2);
				DynamicFactions[i][fZDuty] = floatstr(string);
				mysql_fetch_field_row(string, "WorldDuty", db_con2);
				DynamicFactions[i][fWorldDuty] = strval(string);
				mysql_fetch_field_row(string, "InteriorDuty", db_con2);
				DynamicFactions[i][fInteriorDuty] = strval(string);
				mysql_fetch_field_row(string, "XDuty2", db_con2);
				DynamicFactions[i][fXDuty2] = floatstr(string);
				mysql_fetch_field_row(string, "YDuty2", db_con2);
				DynamicFactions[i][fYDuty2] = floatstr(string);
				mysql_fetch_field_row(string, "ZDuty2", db_con2);
				DynamicFactions[i][fZDuty2] = floatstr(string);
				mysql_fetch_field_row(string, "WorldDuty2", db_con2);
				DynamicFactions[i][fWorldDuty] = strval(string);
				mysql_fetch_field_row(string, "InteriorDuty2", db_con2);
				DynamicFactions[i][fInteriorDuty] = strval(string);
				mysql_fetch_field_row(string, "TaxiKMCost", db_con2);
				DynamicFactions[i][fTaxiKMCost] = strval(string);
				mysql_fetch_field_row(string, "TaxiEnterCost", db_con2);
				DynamicFactions[i][fTaxiEnterCost] = strval(string);
				mysql_fetch_field_row(string, "HealCost", db_con2);
				DynamicFactions[i][fHealCost] = strval(string);
				mysql_fetch_field_row(string, "HealPrice", db_con2);
				DynamicFactions[i][fHealPrice] = strval(string);
				mysql_fetch_field_row(string, "ExamineCost", db_con2);
				DynamicFactions[i][fExamineCost] = strval(string);
				mysql_fetch_field_row(string, "ExaminePrice", db_con2);
				DynamicFactions[i][fExaminePrice] = strval(string);
				mysql_fetch_field_row(string, "SimActivationCost", db_con2);
				DynamicFactions[i][mSimActivationCost] = strval(string);
				mysql_fetch_field_row(string, "SimDailyFee", db_con2);
				DynamicFactions[i][mSimDailyFee] = strval(string);
				mysql_fetch_field_row(string, "SimFreeMins", db_con2);
				DynamicFactions[i][mSimFreeMins] = strval(string);
				mysql_fetch_field_row(string, "SimFreeSms", db_con2);
				DynamicFactions[i][mSimFreeSms] = strval(string);
				mysql_fetch_field_row(string, "SmsCostFee", db_con2);
				DynamicFactions[i][mSmsCostFee] = strval(string);
				mysql_fetch_field_row(string, "CallCostFee", db_con2);
				DynamicFactions[i][mCallCostFee] = strval(string);
				mysql_fetch_field_row(string, "SmsCostCard", db_con2);
				DynamicFactions[i][mSmsCostCard] = strval(string);
				mysql_fetch_field_row(string, "CallCostCard", db_con2);
				DynamicFactions[i][mCallCostCard] = strval(string);
				mysql_fetch_field_row(string, "CardValidity", db_con2);
				DynamicFactions[i][mCardValidity] = strval(string);
				mysql_fetch_field_row(string, "CardRenewCost1", db_con2);
				DynamicFactions[i][mCardRenewCost1] = strval(string);
				mysql_fetch_field_row(string, "CardRenewTime1", db_con2);
				DynamicFactions[i][mCardRenewTime1] = strval(string);
				mysql_fetch_field_row(string, "CardRenewCost2", db_con2);
				DynamicFactions[i][mCardRenewCost2] = strval(string);
				mysql_fetch_field_row(string, "CardRenewTime2", db_con2);
				DynamicFactions[i][mCardRenewTime2] = strval(string);
				mysql_fetch_field_row(string, "CardRenewCost3", db_con2);
				DynamicFactions[i][mCardRenewCost3] = strval(string);
				mysql_fetch_field_row(string, "CardRenewTime3", db_con2);
				DynamicFactions[i][mCardRenewTime3] = strval(string);
				mysql_fetch_field_row(string, "CardRenewCost4", db_con2);
				DynamicFactions[i][mCardRenewCost4] = strval(string);
				mysql_fetch_field_row(string, "CardRenewTime4", db_con2);
				DynamicFactions[i][mCardRenewTime4] = strval(string);
				mysql_fetch_field_row(string, "VehicleStealExportTimeLeft", db_con2);
				DynamicFactions[i][mVehicleStealExportTimeLeft] = strval(string);		
				mysql_fetch_field_row(string, "VehicleStealExportCpId", db_con2);
				DynamicFactions[i][mVehicleStealExportCpId] = strval(string);		
				mysql_fetch_field_row(string, "BizConIncome", db_con2);
				DynamicFactions[i][mBizConIncome] = floatstr(string);		
				mysql_fetch_field_row(string, "BizOfferIncome", db_con2);
				DynamicFactions[i][mBizOfferIncome] = floatstr(string);
				mysql_fetch_field_row(string, "BizJoinCash", db_con2);
				DynamicFactions[i][mBizJoinCash] = strval(string);
				mysql_fetch_field_row(string, "BizJoinTime", db_con2);
				DynamicFactions[i][mBizJoinTime] = strval(string);
				mysql_fetch_field_row(string, "BizPenaltyValue", db_con2);
				DynamicFactions[i][mBizPenaltyValue] = strval(string);
				mysql_fetch_field_row(string, "WFactoryBuildingID", db_con2);
				DynamicFactions[i][WFactoryBuildingID] = strval(string);
				mysql_fetch_field_row(string, "WFactoryEnabled", db_con2);
				DynamicFactions[i][WFactoryEnabled] = strval(string);
				mysql_fetch_field_row(string, "WFactoryBurning", db_con2);
				DynamicFactions[i][WFactoryBurning] = strval(string);
				mysql_fetch_field_row(string, "WFactoryJustBought", db_con2);
				DynamicFactions[i][WFactoryJustBought] = strval(string);
				mysql_fetch_field_row(string, "WFactoryCentrePosX", db_con2);
				DynamicFactions[i][WFactoryCentrePosX] = floatstr(string);
				mysql_fetch_field_row(string, "WFactoryCentrePosY", db_con2);
				DynamicFactions[i][WFactoryCentrePosY] = floatstr(string);
				mysql_fetch_field_row(string, "WFactoryCentrePosZ", db_con2);
				DynamicFactions[i][WFactoryCentrePosZ] = floatstr(string);
				mysql_fetch_field_row(string, "WFactory9MM", db_con2);
				DynamicFactions[i][WFactory9MM] = strval(string);
				mysql_fetch_field_row(string, "WFactory9MMSil", db_con2);
				DynamicFactions[i][WFactory9MMSil] = strval(string);
				mysql_fetch_field_row(string, "WFactoryDesEagle", db_con2);
				DynamicFactions[i][WFactoryDesEagle] = strval(string);
				mysql_fetch_field_row(string, "WFactoryMicroSMG", db_con2);
				DynamicFactions[i][WFactoryMicroSMG] = strval(string);
				mysql_fetch_field_row(string, "WFactoryMP5", db_con2);
				DynamicFactions[i][WFactoryMP5] = strval(string);
				mysql_fetch_field_row(string, "WFactoryTec9", db_con2);
				DynamicFactions[i][WFactoryTec9] = strval(string);
				mysql_fetch_field_row(string, "WFactoryShotgun", db_con2);
				DynamicFactions[i][WFactoryShotgun] = strval(string);
				mysql_fetch_field_row(string, "WFactoryAK47", db_con2);
				DynamicFactions[i][WFactoryAK47] = strval(string);
				mysql_fetch_field_row(string, "WFactoryM4", db_con2);
				DynamicFactions[i][WFactoryM4] = strval(string);
				mysql_fetch_field_row(string, "WFactoryRifle", db_con2);
				DynamicFactions[i][WFactoryRifle] = strval(string);
				mysql_fetch_field_row(string, "WFactorySRifle", db_con2);
				DynamicFactions[i][WFactorySRifle] = strval(string);
				mysql_fetch_field_row(string, "WFactorySCharge", db_con2);
				DynamicFactions[i][WFactorySCharge] = strval(string);
				mysql_fetch_field_row(string, "WFactory9MMAmmo", db_con2);
				DynamicFactions[i][WFactory9MMAmmo] = strval(string);
				mysql_fetch_field_row(string, "WFactory50AEAmmo", db_con2);
				DynamicFactions[i][WFactory50AEAmmo] = strval(string);
				mysql_fetch_field_row(string, "WFactoryBuckshot", db_con2);
				DynamicFactions[i][WFactoryBuckshot] = strval(string);
				mysql_fetch_field_row(string, "WFactory762MMAmmo", db_con2);
				DynamicFactions[i][WFactory762MMAmmo] = strval(string);
				mysql_fetch_field_row(string, "WFactory127MMAmmo", db_con2);
				DynamicFactions[i][WFactory127MMAmmo] = strval(string);
				mysql_fetch_field_row(string, "WFactoryKGP66MMAmmo", db_con2);
				DynamicFactions[i][WFactoryKGP66MMAmmo] = strval(string);
				mysql_fetch_field_row(string, "WFactoryNapalm", db_con2);
				DynamicFactions[i][WFactoryNapalm] = strval(string);
				mysql_fetch_field_row(string, "WFactoryPistolPart1", db_con2);
				DynamicFactions[i][WFactoryPistolPart1] = strval(string);
				mysql_fetch_field_row(string, "WFactoryPistolS1Part1", db_con2);
				DynamicFactions[i][WFactoryPistolS1Part1] = strval(string);
				mysql_fetch_field_row(string, "WFactoryPistolS1Part2", db_con2);
				DynamicFactions[i][WFactoryPistolS1Part2] = strval(string);
				mysql_fetch_field_row(string, "WFactoryPistolS1Part3", db_con2);
				DynamicFactions[i][WFactoryPistolS1Part3] = strval(string);
				mysql_fetch_field_row(string, "WFactoryPistolPart2", db_con2);
				DynamicFactions[i][WFactoryPistolPart2] = strval(string);
				mysql_fetch_field_row(string, "WFactoryPistolS2Part1", db_con2);
				DynamicFactions[i][WFactoryPistolS2Part1] = strval(string);
				mysql_fetch_field_row(string, "WFactoryPistolS2Part2", db_con2);
				DynamicFactions[i][WFactoryPistolS2Part2] = strval(string);
				mysql_fetch_field_row(string, "WFactoryPistolS2Part3", db_con2);
				DynamicFactions[i][WFactoryPistolS2Part3] = strval(string);
				mysql_fetch_field_row(string, "WFactoryPistolPart3", db_con2);
				DynamicFactions[i][WFactoryPistolPart3] = strval(string);
				mysql_fetch_field_row(string, "WFactoryPistolS3Part1", db_con2);
				DynamicFactions[i][WFactoryPistolS3Part1] = strval(string);
				mysql_fetch_field_row(string, "WFactoryPistolS3Part2", db_con2);
				DynamicFactions[i][WFactoryPistolS3Part2] = strval(string);
				mysql_fetch_field_row(string, "WFactoryPistolS3Part3", db_con2);
				DynamicFactions[i][WFactoryPistolS3Part3] = strval(string);
				mysql_fetch_field_row(string, "WFactoryPistolS3Part4", db_con2);
				DynamicFactions[i][WFactoryPistolS3Part4] = strval(string);
				mysql_fetch_field_row(string, "WFactoryPistolPart4", db_con2);
				DynamicFactions[i][WFactoryPistolPart4] = strval(string);
				mysql_fetch_field_row(string, "WFactoryPistolPart5", db_con2);
				DynamicFactions[i][WFactoryPistolPart5] = strval(string);
				mysql_fetch_field_row(string, "WFactoryPistolPart6", db_con2);
				DynamicFactions[i][WFactoryPistolPart6] = strval(string);
				mysql_fetch_field_row(string, "WFactoryRiflePart1", db_con2);
				DynamicFactions[i][WFactoryRiflePart1] = strval(string);
				mysql_fetch_field_row(string, "WFactoryRifleS1Part1", db_con2);
				DynamicFactions[i][WFactoryRifleS1Part1] = strval(string);
				mysql_fetch_field_row(string, "WFactoryRifleS1Part2", db_con2);
				DynamicFactions[i][WFactoryRifleS1Part2] = strval(string);
				mysql_fetch_field_row(string, "WFactoryRiflePart2", db_con2);
				DynamicFactions[i][WFactoryRiflePart2] = strval(string);
				mysql_fetch_field_row(string, "WFactoryRifleS2Part1", db_con2);
				DynamicFactions[i][WFactoryRifleS2Part1] = strval(string);
				mysql_fetch_field_row(string, "WFactoryRifleS2Part2", db_con2);
				DynamicFactions[i][WFactoryRifleS2Part2] = strval(string);
				mysql_fetch_field_row(string, "WFactoryRifleS2Part3", db_con2);
				DynamicFactions[i][WFactoryRifleS2Part3] = strval(string);
				mysql_fetch_field_row(string, "WFactoryRiflePart3", db_con2);
				DynamicFactions[i][WFactoryRiflePart3] = strval(string);
				mysql_fetch_field_row(string, "WFactoryRifleS3Part1", db_con2);
				DynamicFactions[i][WFactoryRifleS3Part1] = strval(string);
				mysql_fetch_field_row(string, "WFactoryRifleS3Part2", db_con2);
				DynamicFactions[i][WFactoryRifleS3Part2] = strval(string);
				mysql_fetch_field_row(string, "WFactoryRifleS3Part3", db_con2);
				DynamicFactions[i][WFactoryRifleS3Part3] = strval(string);
				mysql_fetch_field_row(string, "WFactoryRifleS3Part4", db_con2);
				DynamicFactions[i][WFactoryRifleS3Part4] = strval(string);
				mysql_fetch_field_row(string, "WFactoryRiflePart4", db_con2);
				DynamicFactions[i][WFactoryRiflePart4] = strval(string);
				mysql_fetch_field_row(string, "WFactoryRiflePart5", db_con2);
				DynamicFactions[i][WFactoryRiflePart5] = strval(string);
				mysql_fetch_field_row(string, "WFactoryRiflePart6", db_con2);
				DynamicFactions[i][WFactoryRiflePart6] = strval(string);
				mysql_fetch_field_row(string, "WFactoryRiflePart7", db_con2);
				DynamicFactions[i][WFactoryRiflePart7] = strval(string);
				mysql_fetch_field_row(string, "WFactoryRifleS6Part1", db_con2);
				DynamicFactions[i][WFactoryRifleS6Part1] = strval(string);
				mysql_fetch_field_row(string, "WFactoryRifleS6Part2", db_con2);
				DynamicFactions[i][WFactoryRifleS6Part2] = strval(string);
				mysql_fetch_field_row(string, "WFactoryAmmoPart1a", db_con2);
				DynamicFactions[i][WFactoryAmmoPart1a] = strval(string);
				mysql_fetch_field_row(string, "WFactoryAmmoPart2a", db_con2);
				DynamicFactions[i][WFactoryAmmoPart2a] = strval(string);
				mysql_fetch_field_row(string, "WFactoryAmmoPart3a", db_con2);
				DynamicFactions[i][WFactoryAmmoPart3a] = strval(string);
				mysql_fetch_field_row(string, "WFactoryAmmoPart4a", db_con2);
				DynamicFactions[i][WFactoryAmmoPart4a] = strval(string);
				mysql_fetch_field_row(string, "WFactoryAmmoPart1b", db_con2);
				DynamicFactions[i][WFactoryAmmoPart1b] = strval(string);
				mysql_fetch_field_row(string, "WFactoryAmmoPart2b", db_con2);
				DynamicFactions[i][WFactoryAmmoPart2b] = strval(string);
				mysql_fetch_field_row(string, "WFactoryAmmoPart3b", db_con2);
				DynamicFactions[i][WFactoryAmmoPart3b] = strval(string);
				mysql_fetch_field_row(string, "WFactoryAmmoPart4b", db_con2);
				DynamicFactions[i][WFactoryAmmoPart4b] = strval(string);
				mysql_fetch_field_row(string, "WFactoryAmmoPart1c", db_con2);
				DynamicFactions[i][WFactoryAmmoPart1c] = strval(string);
				mysql_fetch_field_row(string, "WFactoryAmmoPart2c", db_con2);
				DynamicFactions[i][WFactoryAmmoPart2c] = strval(string);
				mysql_fetch_field_row(string, "WFactoryAmmoPart3c", db_con2);
				DynamicFactions[i][WFactoryAmmoPart3c] = strval(string);
				mysql_fetch_field_row(string, "WFactoryAmmoPart4c", db_con2);
				DynamicFactions[i][WFactoryAmmoPart4c] = strval(string);
				mysql_fetch_field_row(string, "WFactoryAmmoPart1d", db_con2);
				DynamicFactions[i][WFactoryAmmoPart1d] = strval(string);
				mysql_fetch_field_row(string, "WFactoryAmmoPart2d", db_con2);
				DynamicFactions[i][WFactoryAmmoPart2d] = strval(string);
				mysql_fetch_field_row(string, "WFactoryAmmoPart3d", db_con2);
				DynamicFactions[i][WFactoryAmmoPart3d] = strval(string);
				mysql_fetch_field_row(string, "WFactoryAmmoPart4d", db_con2);
				DynamicFactions[i][WFactoryAmmoPart4d] = strval(string);
				mysql_fetch_field_row(string, "WFactoryAmmoPart1e", db_con2);
				DynamicFactions[i][WFactoryAmmoPart1e] = strval(string);
				mysql_fetch_field_row(string, "WFactoryAmmoPart2e", db_con2);
				DynamicFactions[i][WFactoryAmmoPart2e] = strval(string);
				mysql_fetch_field_row(string, "WFactoryAmmoPart3e", db_con2);
				DynamicFactions[i][WFactoryAmmoPart3e] = strval(string);
				mysql_fetch_field_row(string, "WFactoryAmmoPart4e", db_con2);
				DynamicFactions[i][WFactoryAmmoPart4e] = strval(string);
				mysql_fetch_field_row(string, "WFactoryTec9Part", db_con2);
				DynamicFactions[i][WFactoryTec9Part] = strval(string);
				mysql_fetch_field_row(string, "WFactoryMP5Part", db_con2);
				DynamicFactions[i][WFactoryMP5Part] = strval(string);
				mysql_fetch_field_row(string, "WFactoryAK47Part", db_con2);
				DynamicFactions[i][WFactoryAK47Part] = strval(string);
				mysql_fetch_field_row(string, "WFactoryM4Part", db_con2);
				DynamicFactions[i][WFactoryM4Part] = strval(string);
				mysql_fetch_field_row(string, "WFactoryShotPart", db_con2);
				DynamicFactions[i][WFactoryShotPart] = strval(string);
				mysql_fetch_field_row(string, "WFactoryDesEaglePart", db_con2);
				DynamicFactions[i][WFactoryDesEaglePart] = strval(string);
				mysql_fetch_field_row(string, "WFactoryRiflePart", db_con2);
				DynamicFactions[i][WFactoryRiflePart] = strval(string);
				mysql_fetch_field_row(string, "WFactorySniperPart", db_con2);
				DynamicFactions[i][WFactorySniperPart] = strval(string);
				
				if(DynamicFactions[i][fXDuty] != 0.0 || DynamicFactions[i][fYDuty] != 0.0)
					DynamicFactions[i][fCP] = CreateDynamicPickup(1239, 1, DynamicFactions[i][fXDuty], DynamicFactions[i][fYDuty], DynamicFactions[i][fZDuty], DynamicFactions[i][fWorldDuty], DynamicFactions[i][fInteriorDuty], -1, 20.0);
				if(DynamicFactions[i][fXDuty2] != 0.0 || DynamicFactions[i][fYDuty2] != 0.0)
					DynamicFactions[i][fCP2] = CreateDynamicPickup(1239, 1, DynamicFactions[i][fXDuty2], DynamicFactions[i][fYDuty2], DynamicFactions[i][fZDuty2], DynamicFactions[i][fWorldDuty2], DynamicFactions[i][fInteriorDuty2], -1, 20.0);
				
				px = DynamicFactions[i][WFactoryCentrePosX];
				py = DynamicFactions[i][WFactoryCentrePosY];
				pz = DynamicFactions[i][WFactoryCentrePosZ];
				if( DynamicFactions[i][WFactoryEnabled] )
				{
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
					DynamicFactions[i][WFactoryObjects][31] = CreateDynamicObject( 18693 , px+WFObj[30][0], py+WFObj[30][1], pz+WFObj[30][2], WFObj[30][3], WFObj[30][4], WFObj[30][5] );
					DynamicFactions[i][WFactoryCPPartSetup1ID] = CreateDynamicCP( px+WFCP[0][0], py+WFCP[0][1], pz+WFCP[0][2], 2.0, 0, 0, -1, 5.0 ); // Make weapon parts
					DynamicFactions[i][WFactoryCPPartSetup2ID] = CreateDynamicCP( px+WFCP[1][0], py+WFCP[1][1], pz+WFCP[1][2], 2.0, 0, 0, -1, 5.0); // Make weapon parts
					DynamicFactions[i][WFactoryCPAmmoPartSetup1ID] = CreateDynamicCP( px+WFCP[2][0], py+WFCP[2][1], pz+WFCP[2][2], 2.0, 0, 0, -1, 5.0 ); // Make weapon subparts
					DynamicFactions[i][WFactoryCPAmmoPartSetup2ID] = CreateDynamicCP( px+WFCP[4][0], py+WFCP[4][1], pz+WFCP[4][2], 2.0, 0, 0, -1, 5.0 ); // Make weapon subparts
					DynamicFactions[i][WFactoryCPPartTakeID] = CreateDynamicCP( px+WFCP[3][0], py+WFCP[3][1], pz+WFCP[3][2], 2.0, 0, 0, -1, 5.0 ); // Take/buy ammo/weapon (sub) parts
				}
				// printf("fCP ID: %d, X %f, Y %f, Z %f", DynamicFactions[i][fCP],DynamicFactions[i][fXDuty],DynamicFactions[i][fYDuty],DynamicFactions[i][fZDuty]);
				// printf("[FRAKCJE DYNAMICZNE:] Nazwa frakcji: %s, Typ: %d, ID: %d",DynamicFactions[i][Name],DynamicFactions[i][fType],i);

				i++;
			}
			#if defined DEBUG
				print("[INFO:] Factions loaded [MySQL]");
			#endif
			mysql_free_result(db_con2);
		}
		case LOAD_CARS_CPARTS:
		{
			if( !mysql_store_result(db_con2) )
			{
				ErrorLog("[ERROR:] Can't store result on LOAD_CARS_CPARTS");
				GameModeExit();
				return 1;
			}
			new i = 0;
			while(mysql_fetch_row_format(db_result, "|", db_con2))
			{
				split2(db_result, arrCoords, '|');
				if(i+1 == strval(arrCoords[0]))
				{
					gVehData[i][CustomObj1Model] = strval(arrCoords[1]);
					gVehData[i][CustomObj1On] = strval(arrCoords[2]);
					gVehData[i][CustomObj1][0] = floatstr(arrCoords[3]);
					gVehData[i][CustomObj1][1] = floatstr(arrCoords[4]);
					gVehData[i][CustomObj1][2] = floatstr(arrCoords[5]);
					gVehData[i][CustomObj1][3] = floatstr(arrCoords[6]);
					gVehData[i][CustomObj1][4] = floatstr(arrCoords[7]);
					gVehData[i][CustomObj1][5] = floatstr(arrCoords[8]);
					gVehData[i][CustomObj2Model] = strval(arrCoords[9]);
					gVehData[i][CustomObj2On] = strval(arrCoords[10]);
					gVehData[i][CustomObj2][0] = floatstr(arrCoords[11]);
					gVehData[i][CustomObj2][1] = floatstr(arrCoords[12]);
					gVehData[i][CustomObj2][2] = floatstr(arrCoords[13]);
					gVehData[i][CustomObj2][3] = floatstr(arrCoords[14]);
					gVehData[i][CustomObj2][4] = floatstr(arrCoords[15]);
					gVehData[i][CustomObj2][5] = floatstr(arrCoords[16]);
					gVehData[i][CustomObj3Model] = strval(arrCoords[17]);
					gVehData[i][CustomObj3On] = strval(arrCoords[18]);
					gVehData[i][CustomObj3][0] = floatstr(arrCoords[19]);
					gVehData[i][CustomObj3][1] = floatstr(arrCoords[20]);
					gVehData[i][CustomObj3][2] = floatstr(arrCoords[21]);
					gVehData[i][CustomObj3][3] = floatstr(arrCoords[22]);
					gVehData[i][CustomObj3][4] = floatstr(arrCoords[23]);
					gVehData[i][CustomObj3][5] = floatstr(arrCoords[24]);
					gVehData[i][CustomObj4Model] = strval(arrCoords[25]);
					gVehData[i][CustomObj4On] = strval(arrCoords[26]);
					gVehData[i][CustomObj4][0] = floatstr(arrCoords[27]);
					gVehData[i][CustomObj4][1] = floatstr(arrCoords[28]);
					gVehData[i][CustomObj4][2] = floatstr(arrCoords[29]);
					gVehData[i][CustomObj4][3] = floatstr(arrCoords[30]);
					gVehData[i][CustomObj4][4] = floatstr(arrCoords[31]);
					gVehData[i][CustomObj4][5] = floatstr(arrCoords[32]);
					gVehData[i][CustomObj5Model] = strval(arrCoords[33]);
					gVehData[i][CustomObj5On] = strval(arrCoords[34]);
					gVehData[i][CustomObj5][0] = floatstr(arrCoords[35]);
					gVehData[i][CustomObj5][1] = floatstr(arrCoords[36]);
					gVehData[i][CustomObj5][2] = floatstr(arrCoords[37]);
					gVehData[i][CustomObj5][3] = floatstr(arrCoords[38]);
					gVehData[i][CustomObj5][4] = floatstr(arrCoords[39]);
					gVehData[i][CustomObj5][5] = floatstr(arrCoords[40]);
					gVehData[i][CustomObj6Model] = strval(arrCoords[41]);
					gVehData[i][CustomObj6On] = strval(arrCoords[42]);
					gVehData[i][CustomObj6][0] = floatstr(arrCoords[43]);
					gVehData[i][CustomObj6][1] = floatstr(arrCoords[44]);
					gVehData[i][CustomObj6][2] = floatstr(arrCoords[45]);
					gVehData[i][CustomObj6][3] = floatstr(arrCoords[46]);
					gVehData[i][CustomObj6][4] = floatstr(arrCoords[47]);
					gVehData[i][CustomObj6][5] = floatstr(arrCoords[48]);
					gVehData[i][CustomObj7Model] = strval(arrCoords[49]);
					gVehData[i][CustomObj7On] = strval(arrCoords[50]);
					gVehData[i][CustomObj7][0] = floatstr(arrCoords[51]);
					gVehData[i][CustomObj7][1] = floatstr(arrCoords[52]);
					gVehData[i][CustomObj7][2] = floatstr(arrCoords[53]);
					gVehData[i][CustomObj7][3] = floatstr(arrCoords[54]);
					gVehData[i][CustomObj7][4] = floatstr(arrCoords[55]);
					gVehData[i][CustomObj7][5] = floatstr(arrCoords[56]);

					if( gVehData[i][CustomObj1Model] != 0 && gVehData[i][CustomObj1On] == 1 )
					{
						gVehData[i][CustomObj1ID] = CreateDynamicObject(
																					gVehData[i][CustomObj1Model],
																					0.0,
																					0.0,
																					-1000.0,
																					0.0,
																					0.0,
																					0.0);
						AttachDynamicObjectToVehicle(gVehData[i][CustomObj1ID], i+1, gVehData[i][CustomObj1][0], gVehData[i][CustomObj1][1], gVehData[i][CustomObj1][2], gVehData[i][CustomObj1][3], gVehData[i][CustomObj1][4], gVehData[i][CustomObj1][5]);
					}
					if( gVehData[i][CustomObj2Model] != 0  && gVehData[i][CustomObj2On] == 1 )
					{
						gVehData[i][CustomObj2ID] = CreateDynamicObject(
																					gVehData[i][CustomObj2Model],
																					0.0,
																					0.0,
																					-1000.0,
																					0.0,
																					0.0,
																					0.0);
						AttachDynamicObjectToVehicle(gVehData[i][CustomObj2ID], i+1, gVehData[i][CustomObj2][0], gVehData[i][CustomObj2][1], gVehData[i][CustomObj2][2], gVehData[i][CustomObj2][3], gVehData[i][CustomObj2][4], gVehData[i][CustomObj2][5]);
					}
					if( gVehData[i][CustomObj3Model] != 0 && gVehData[i][CustomObj3On] == 1  )
					{
						gVehData[i][CustomObj3ID] = CreateDynamicObject(
																					gVehData[i][CustomObj3Model],
																					0.0,
																					0.0,
																					-1000.0,
																					0.0,
																					0.0,
																					0.0);
						AttachDynamicObjectToVehicle(gVehData[i][CustomObj3ID], i+1, gVehData[i][CustomObj3][0], gVehData[i][CustomObj3][1], gVehData[i][CustomObj3][2], gVehData[i][CustomObj3][3], gVehData[i][CustomObj3][4], gVehData[i][CustomObj3][5]);
					}
					if( gVehData[i][CustomObj4Model] != 0 && gVehData[i][CustomObj4On] == 1  )
					{
						gVehData[i][CustomObj4ID] = CreateDynamicObject(
																					gVehData[i][CustomObj4Model],
																					0.0,
																					0.0,
																					-1000.0,
																					0.0,
																					0.0,
																					0.0);
						AttachDynamicObjectToVehicle(gVehData[i][CustomObj4ID], i+1, gVehData[i][CustomObj4][0], gVehData[i][CustomObj4][1], gVehData[i][CustomObj4][2], gVehData[i][CustomObj4][3], gVehData[i][CustomObj4][4], gVehData[i][CustomObj4][5]);
					}
					if( gVehData[i][CustomObj5Model] != 0 && gVehData[i][CustomObj5On] == 1  )
					{
						gVehData[i][CustomObj5ID] = CreateDynamicObject(
																					gVehData[i][CustomObj5Model],
																					0.0,
																					0.0,
																					-1000.0,
																					0.0,
																					0.0,
																					0.0);
						AttachDynamicObjectToVehicle(gVehData[i][CustomObj5ID], i+1, gVehData[i][CustomObj5][0], gVehData[i][CustomObj5][1], gVehData[i][CustomObj5][2], gVehData[i][CustomObj5][3], gVehData[i][CustomObj5][4], gVehData[i][CustomObj5][5]);
					}
					if( gVehData[i][CustomObj6Model] != 0 && gVehData[i][CustomObj6On] == 1  )
					{
						gVehData[i][CustomObj6ID] = CreateDynamicObject(
																					gVehData[i][CustomObj6Model],
																					0.0,
																					0.0,
																					-1000.0,
																					0.0,
																					0.0,
																					0.0);
						AttachDynamicObjectToVehicle(gVehData[i][CustomObj6ID], i+1, gVehData[i][CustomObj6][0], gVehData[i][CustomObj6][1], gVehData[i][CustomObj6][2], gVehData[i][CustomObj6][3], gVehData[i][CustomObj6][4], gVehData[i][CustomObj6][5]);
					}
					if( gVehData[i][CustomObj7Model] != 0 && gVehData[i][CustomObj7On] == 1  )
					{
						gVehData[i][CustomObj7ID] = CreateDynamicObject(
																					gVehData[i][CustomObj7Model],
																					0.0,
																					0.0,
																					-1000.0,
																					0.0,
																					0.0,
																					0.0);
						AttachDynamicObjectToVehicle(gVehData[i][CustomObj7ID], i+1, gVehData[i][CustomObj7][0], gVehData[i][CustomObj7][1], gVehData[i][CustomObj7][2], gVehData[i][CustomObj7][3], gVehData[i][CustomObj7][4], gVehData[i][CustomObj7][5]);
					}
					i++;
				}
			}
			#if defined DEBUG
				print("[INFO:] Vehicle custom objects loaded [MySQL]");
			#endif

			mysql_free_result(db_con2);
		}
		case LOAD_CARS_CUSTOMIZE:
		{
			if(!mysql_store_result(db_con2))
			{
				ErrorLog("[ERROR:] Can't store result on LOAD_CARS_CUSTOMIZE");
				GameModeExit();
				return 1;
			}

			new i = 0;

			while(mysql_fetch_row_format(db_result, "|", db_con2))
			{
				mysql_fetch_field_row(string, "Spoiler", db_con2);
				gVehData[i][mVehSpoiler] = strval(string);
				mysql_fetch_field_row(string, "Hood", db_con2);
				gVehData[i][mVehHood] = strval(string);
				mysql_fetch_field_row(string, "Roof", db_con2);
				gVehData[i][mVehRoof] = strval(string);
				mysql_fetch_field_row(string, "Sideskirt", db_con2);
				gVehData[i][mVehSideskirt] = strval(string);
				mysql_fetch_field_row(string, "Lamps", db_con2);
				gVehData[i][mVehLamps] = strval(string);
				mysql_fetch_field_row(string, "Nitro", db_con2);
				gVehData[i][mVehNitro] = strval(string);
				mysql_fetch_field_row(string, "Exhaust", db_con2);
				gVehData[i][mVehExhaust] = strval(string);
				mysql_fetch_field_row(string, "Wheels", db_con2);
				gVehData[i][mVehWheels] = strval(string);
				mysql_fetch_field_row(string, "Stereo", db_con2);
				gVehData[i][mVehStereo] = strval(string);
				mysql_fetch_field_row(string, "Hydraulics", db_con2);
				gVehData[i][mVehHydraulics] = strval(string);
				mysql_fetch_field_row(string, "FrontBumper", db_con2);
				gVehData[i][mVehFrontBumper] = strval(string);
				mysql_fetch_field_row(string, "RearBumper", db_con2);
				gVehData[i][mVehRearBumper] = strval(string);
				mysql_fetch_field_row(string, "VentLeft", db_con2);
				gVehData[i][mVehVentLeft] = strval(string);
				mysql_fetch_field_row(string, "VentRight", db_con2);
				gVehData[i][mVehVentRight] = strval(string);

				SetVehicleToRespawnEx(i+1);

				i++;
			}
			#if defined DEBUG
				print("[INFO:] Dynamic vehicles customize loaded [MySQL]");
			#endif

			mysql_free_result(db_con2);
		}
		case LOAD_GANG_ZONES:
		{
			if(!mysql_store_result(db_con2))
			{
				ErrorLog("[ERROR:] Can't store result on LOAD_GANG_ZONES");
				GameModeExit();
				return 1;
			}
			
			new i = 0;
			
			while(mysql_fetch_row_format(db_result, "|", db_con2))
			{
				mysql_fetch_field_row(string, "PosMinX", db_con2);
				DynamicZones[i][mPosMinX] = floatstr(string);
				mysql_fetch_field_row(string, "PosMinY", db_con2);
				DynamicZones[i][mPosMinY] = floatstr(string);
				mysql_fetch_field_row(string, "PosMaxX", db_con2);
				DynamicZones[i][mPosMaxX] = floatstr(string);
				mysql_fetch_field_row(string, "PosMaxY", db_con2);
				DynamicZones[i][mPosMaxY] = floatstr(string);
				mysql_fetch_field_row(string, "Faction", db_con2);
				DynamicZones[i][mFaction] = strval(string);
				mysql_fetch_field_row(string, "CharStealTimeLeft", db_con2);
				DynamicZones[i][mCharStealTimeLeft] = strval(string);
				mysql_fetch_field_row(string, "CharMoneyStealTimeLeft", db_con2);
				DynamicZones[i][mCharMoneyStealTimeLeft] = strval(string);
				mysql_fetch_field_row(string, "VehStealTimeLeft", db_con2);
				DynamicZones[i][mVehStealTimeLeft] = strval(string);
				mysql_fetch_field_row(string, "VehBreakTimeLeft", db_con2);
				DynamicZones[i][mVehBreakTimeLeft] = strval(string);
				mysql_fetch_field_row(string, "BizStealTimeLeft", db_con2);
				DynamicZones[i][mBizStealTimeLeft] = strval(string);
				mysql_fetch_field_row(string, "BizBreakTimeLeft", db_con2);
				DynamicZones[i][mBizBreakTimeLeft] = strval(string);
				mysql_fetch_field_row(string, "HouseStealTimeLeft", db_con2);
				DynamicZones[i][mHouseStealTimeLeft] = strval(string);
				mysql_fetch_field_row(string, "HouseBreakTimeLeft", db_con2);
				DynamicZones[i][mHouseBreakTimeLeft] = strval(string);
				
				DynamicZones[i][mZoneId] = GangZoneCreate(DynamicZones[i][mPosMinX], DynamicZones[i][mPosMinY], DynamicZones[i][mPosMaxX], DynamicZones[i][mPosMaxY]);
				
				i++;
			}
			#if defined DEBUG
				print("[INFO:] Dynamic vehicles loaded [MySQL]");
			#endif

			mysql_free_result(db_con2);
		}
		case LOAD_DYNAMIC_CARS:
		{
			if(!mysql_store_result(db_con2))
			{
				ErrorLog("[ERROR:] Can't store result on LOAD_DYNAMIC_CARS");
				GameModeExit();
				return 1;
			}

			new i, id, lightsd;
			i = 0;

			new enginedyn,lights,alarm,doors,bonnet,boot,objective;

			while(mysql_fetch_row_format(db_result, "|", db_con2))
			{
				mysql_fetch_field_row(string, "VehModel", db_con2);
				gVehData[i][mVehModel] = strval(string);
				mysql_fetch_field_row(string, "VehX", db_con2);
				gVehData[i][mVehX] = floatstr(string);
				VehNewPos[i][0] = floatstr(string);
				mysql_fetch_field_row(string, "VehY", db_con2);
				gVehData[i][mVehY] = floatstr(string);
				VehNewPos[i][1] = floatstr(string);
				mysql_fetch_field_row(string, "VehZ", db_con2);
				gVehData[i][mVehZ] = floatstr(string);
				VehNewPos[i][2] = floatstr(string);
				mysql_fetch_field_row(string, "VehA", db_con2);
				gVehData[i][mVehA] = floatstr(string);
				mysql_fetch_field_row(string, "VehInt", db_con2);
				gVehData[i][mVehInt] = strval(string);
				mysql_fetch_field_row(string, "VehVW", db_con2);
				gVehData[i][mVehVW] = strval(string);
				mysql_fetch_field_row(string, "VehColor1", db_con2);
				gVehData[i][mVehColor1] = strval(string);
				mysql_fetch_field_row(string, "VehColor2", db_con2);
				gVehData[i][mVehColor2] = strval(string);
				mysql_fetch_field_row(string, "VehFaction", db_con2);
				gVehData[i][mVehFaction] = strval(string);
				mysql_fetch_field_row(string, "VehVinNo", db_con2);
				gVehData[i][mVehVinNo] = strval(string);
				mysql_fetch_field_row(string, "VehType", db_con2);
				gVehData[i][mVehType] = strval(string);
				mysql_fetch_field_row(string, "VehOwned", db_con2);
				gVehData[i][mVehOwned] = strval(string);
				mysql_fetch_field_row(gVehData[i][Owner], "Owner", db_con2);
				mysql_fetch_field_row(string, "Price", db_con2);
				gVehData[i][Price] = strval(string);
				mysql_fetch_field_row(string, "Closed", db_con2);
				gVehData[i][Closed] = strval(string);
				mysql_fetch_field_row(string, "CarResetT", db_con2);
				gVehData[i][CarResetT] = strval(string);
				mysql_fetch_field_row(string, "CarDamaged", db_con2);
				gVehData[i][CarDamaged] = strval(string);
				mysql_fetch_field_row(string, "CarRepairTimeLeft", db_con2);
				gVehData[i][CarRepairTimeLeft] = strval(string);
				mysql_fetch_field_row(string, "BusinessID", db_con2);
				gVehData[i][BusinessID] = strval(string);
				mysql_fetch_field_row(string, "CarFuel", db_con2);
				gVehData[i][CarFuel] = strval(string);
				mysql_fetch_field_row(string, "CarHealth", db_con2);
				gVehData[i][CarHealth] = floatstr(string);
				mysql_fetch_field_row(string, "ReadyToSell", db_con2);
				gVehData[i][ReadyToSell] = strval(string);
				mysql_fetch_field_row(string, "CarCounter", db_con2);
				gVehData[i][CarCounter] = strval(string);
				mysql_fetch_field_row(string, "Fuel", db_con2);
				gVehData[i][Fuel] = strval(string);
				mysql_fetch_field_row(string, "CarPanels", db_con2);
				gVehData[i][CarPanels] = strval(string);
				mysql_fetch_field_row(string, "CarDoors", db_con2);
				gVehData[i][CarDoors] = strval(string);
				mysql_fetch_field_row(string, "CarLights", db_con2);
				gVehData[i][CarLights] = strval(string);
				mysql_fetch_field_row(string, "CarTires", db_con2);
				gVehData[i][CarTires] = strval(string);
				mysql_fetch_field_row(string, "LastDriverWKey", db_con2);
				gVehData[i][LastDriverWKey] = strlen(string);
				mysql_fetch_field_row(string, "CarSerial", db_con2);
				gVehData[i][CarSerial] = strval(string);
				mysql_fetch_field_row(string, "PaintStep", db_con2);
				gVehData[i][PaintStep] = strval(string);
				mysql_fetch_field_row(string, "WheelStep", db_con2);
				gVehData[i][WheelStep] = strval(string);
				mysql_fetch_field_row(string, "EngineOn", db_con2);
				gVehData[i][EngineOn] = strval(string);
				mysql_fetch_field_row(string, "LightsOn", db_con2);
				gVehData[i][LightsOn] = strval(string);
				mysql_fetch_field_row(string, "BonnetUp", db_con2);
				gVehData[i][BonnetUp] = strval(string);
				mysql_fetch_field_row(string, "BootUp", db_con2);
				gVehData[i][BootUp] = strval(string);
				mysql_fetch_field_row(string, "RadioOn", db_con2);
				gVehData[i][RadioOn] = strval(string);
				mysql_fetch_field_row(string, "Hook", db_con2);
				gVehData[i][Hook] = strval(string);
				mysql_fetch_field_row(string, "Alarm", db_con2);
				gVehData[i][Alarm] = strval(string);
				mysql_fetch_field_row(string, "GasStep", db_con2);
				gVehData[i][GasStep] = strval(string);
				mysql_fetch_field_row(string, "TankerResourceType", db_con2);
				gVehData[i][TankerResourceType] = strval(string);
				mysql_fetch_field_row(string, "TankerResourceValue", db_con2);
				gVehData[i][TankerResourceValue] = strval(string);
				mysql_fetch_field_row(string, "EngineTemp", db_con2);
				gVehData[i][EngineTemp] = strval(string);
				mysql_fetch_field_row(string, "RadioVol", db_con2);
				gVehData[i][RadioVol] = strval(string);
				mysql_fetch_field_row(string, "BatteryCapacity", db_con2);
				gVehData[i][BatteryCapacity] = floatstr(string);
				mysql_fetch_field_row(string, "BatteryMaxCapacity", db_con2);
				gVehData[i][BatteryMaxCapacity] = floatstr(string);
				mysql_fetch_field_row(string, "BatteryID", db_con2);
				gVehData[i][BatteryID] = strval(string);
				mysql_fetch_field_row(string, "Confiscated", db_con2);
				gVehData[i][VConfiscated] = strval(string);
				mysql_fetch_field_row(string, "PoliceComputer", db_con2);
				gVehData[i][VPoliceComputer] = strval(string);
				mysql_fetch_field_row(string, "CBRadio", db_con2);
				gVehData[i][VCBRadio] = strval(string);
				mysql_fetch_field_row(string, "CBRadioChanel", db_con2);
				gVehData[i][VCBRadioChanel] = strval(string);
				mysql_fetch_field_row(string, "CBRadioStatus", db_con2);
				gVehData[i][VCBRadioStatus] = strval(string);
				mysql_fetch_field_row(string, "VehIgnitionHacked", db_con2);
				gVehData[i][mVehIgnitionHacked] = strval(string);
				mysql_fetch_field_row(string, "VehIgnitionDamaged", db_con2);
				gVehData[i][mVehIgnitionDamaged] = strval(string);
				mysql_fetch_field_row(string, "VehSirenObjModel", db_con2);
				gVehData[i][mVehSirenObjModel] = strval(string);
				mysql_fetch_field_row(string, "Item1", db_con2);
				gVehData[i][VItem1] = strval(string);
				mysql_fetch_field_row(string, "Item2", db_con2);
				gVehData[i][VItem2] = strval(string);
				mysql_fetch_field_row(string, "Item3", db_con2);
				gVehData[i][VItem3] = strval(string);
				mysql_fetch_field_row(string, "Item4", db_con2);
				gVehData[i][VItem4] = strval(string);
				mysql_fetch_field_row(string, "Item5", db_con2);
				gVehData[i][VItem5] = strval(string);
				mysql_fetch_field_row(string, "Item6", db_con2);
				gVehData[i][VItem6] = strval(string);
				mysql_fetch_field_row(string, "Item7", db_con2);
				gVehData[i][VItem7] = strval(string);
				mysql_fetch_field_row(string, "Item8", db_con2);
				gVehData[i][VItem8] = strval(string);
				mysql_fetch_field_row(string, "Item9", db_con2);
				gVehData[i][VItem9] = strval(string);
				mysql_fetch_field_row(string, "Item10", db_con2);
				gVehData[i][VItem10] = strval(string);
				mysql_fetch_field_row(string, "Item11", db_con2);
				gVehData[i][VItem11] = strval(string);
				mysql_fetch_field_row(string, "Item12", db_con2);
				gVehData[i][VItem12] = strval(string);
				mysql_fetch_field_row(string, "Item13", db_con2);
				gVehData[i][VItem13] = strval(string);
				mysql_fetch_field_row(string, "Item14", db_con2);
				gVehData[i][VItem14] = strval(string);
				mysql_fetch_field_row(string, "Item15", db_con2);
				gVehData[i][VItem15] = strval(string);
				mysql_fetch_field_row(string, "Item1type", db_con2);
				gVehData[i][VItem1type] = strval(string);
				mysql_fetch_field_row(string, "Item2type", db_con2);
				gVehData[i][VItem2type] = strval(string);
				mysql_fetch_field_row(string, "Item3type", db_con2);
				gVehData[i][VItem3type] = strval(string);
				mysql_fetch_field_row(string, "Item4type", db_con2);
				gVehData[i][VItem4type] = strval(string);
				mysql_fetch_field_row(string, "Item5type", db_con2);
				gVehData[i][VItem5type] = strval(string);
				mysql_fetch_field_row(string, "Item6type", db_con2);
				gVehData[i][VItem6type] = strval(string);
				mysql_fetch_field_row(string, "Item7type", db_con2);
				gVehData[i][VItem7type] = strval(string);
				mysql_fetch_field_row(string, "Item8type", db_con2);
				gVehData[i][VItem8type] = strval(string);
				mysql_fetch_field_row(string, "Item9type", db_con2);
				gVehData[i][VItem9type] = strval(string);
				mysql_fetch_field_row(string, "Item10type", db_con2);
				gVehData[i][VItem10type] = strval(string);
				mysql_fetch_field_row(string, "Item11type", db_con2);
				gVehData[i][VItem11type] = strval(string);
				mysql_fetch_field_row(string, "Item12type", db_con2);
				gVehData[i][VItem12type] = strval(string);
				mysql_fetch_field_row(string, "Item13type", db_con2);
				gVehData[i][VItem13type] = strval(string);
				mysql_fetch_field_row(string, "Item14type", db_con2);
				gVehData[i][VItem14type] = strval(string);
				mysql_fetch_field_row(string, "Item15type", db_con2);
				gVehData[i][VItem15type] = strval(string);
				mysql_fetch_field_row(string, "Item1param", db_con2);
				gVehData[i][VItem1param] = strval(string);
				mysql_fetch_field_row(string, "Item2param", db_con2);
				gVehData[i][VItem2param] = strval(string);
				mysql_fetch_field_row(string, "Item3param", db_con2);
				gVehData[i][VItem3param] = strval(string);
				mysql_fetch_field_row(string, "Item4param", db_con2);
				gVehData[i][VItem4param] = strval(string);
				mysql_fetch_field_row(string, "Item5param", db_con2);
				gVehData[i][VItem5param] = strval(string);
				mysql_fetch_field_row(string, "Item6param", db_con2);
				gVehData[i][VItem6param] = strval(string);
				mysql_fetch_field_row(string, "Item7param", db_con2);
				gVehData[i][VItem7param] = strval(string);
				mysql_fetch_field_row(string, "Item8param", db_con2);
				gVehData[i][VItem8param] = strval(string);
				mysql_fetch_field_row(string, "Item9param", db_con2);
				gVehData[i][VItem9param] = strval(string);
				mysql_fetch_field_row(string, "Item10param", db_con2);
				gVehData[i][VItem10param] = strval(string);
				mysql_fetch_field_row(string, "Item11param", db_con2);
				gVehData[i][VItem11param] = strval(string);
				mysql_fetch_field_row(string, "Item12param", db_con2);
				gVehData[i][VItem12param] = strval(string);
				mysql_fetch_field_row(string, "Item13param", db_con2);
				gVehData[i][VItem13param] = strval(string);
				mysql_fetch_field_row(string, "Item14param", db_con2);
				gVehData[i][VItem14param] = strval(string);
				mysql_fetch_field_row(string, "Item15param", db_con2);
				gVehData[i][VItem15param] = strval(string);
				mysql_fetch_field_row(string, "Item1param2", db_con2);
				gVehData[i][VItem1param2] = strval(string);
				mysql_fetch_field_row(string, "Item2param2", db_con2);
				gVehData[i][VItem2param2] = strval(string);
				mysql_fetch_field_row(string, "Item3param2", db_con2);
				gVehData[i][VItem3param2] = strval(string);
				mysql_fetch_field_row(string, "Item4param2", db_con2);
				gVehData[i][VItem4param2] = strval(string);
				mysql_fetch_field_row(string, "Item5param2", db_con2);
				gVehData[i][VItem5param2] = strval(string);
				mysql_fetch_field_row(string, "Item6param2", db_con2);
				gVehData[i][VItem6param2] = strval(string);
				mysql_fetch_field_row(string, "Item7param2", db_con2);
				gVehData[i][VItem7param2] = strval(string);
				mysql_fetch_field_row(string, "Item8param2", db_con2);
				gVehData[i][VItem8param2] = strval(string);
				mysql_fetch_field_row(string, "Item9param2", db_con2);
				gVehData[i][VItem9param2] = strval(string);
				mysql_fetch_field_row(string, "Item10param2", db_con2);
				gVehData[i][VItem10param2] = strval(string);
				mysql_fetch_field_row(string, "Item11param2", db_con2);
				gVehData[i][VItem11param2] = strval(string);
				mysql_fetch_field_row(string, "Item12param2", db_con2);
				gVehData[i][VItem12param2] = strval(string);
				mysql_fetch_field_row(string, "Item13param2", db_con2);
				gVehData[i][VItem13param2] = strval(string);
				mysql_fetch_field_row(string, "Item14param2", db_con2);
				gVehData[i][VItem14param2] = strval(string);
				mysql_fetch_field_row(string, "Item15param2", db_con2);
				gVehData[i][VItem15param2] = strval(string);
				mysql_fetch_field_row(string, "Item1param3", db_con2);
				gVehData[i][VItem1param3] = strval(string);
				mysql_fetch_field_row(string, "Item2param3", db_con2);
				gVehData[i][VItem2param3] = strval(string);
				mysql_fetch_field_row(string, "Item3param3", db_con2);
				gVehData[i][VItem3param3] = strval(string);
				mysql_fetch_field_row(string, "Item4param3", db_con2);
				gVehData[i][VItem4param3] = strval(string);
				mysql_fetch_field_row(string, "Item5param3", db_con2);
				gVehData[i][VItem5param3] = strval(string);
				mysql_fetch_field_row(string, "Item6param3", db_con2);
				gVehData[i][VItem6param3] = strval(string);
				mysql_fetch_field_row(string, "Item7param3", db_con2);
				gVehData[i][VItem7param3] = strval(string);
				mysql_fetch_field_row(string, "Item8param3", db_con2);
				gVehData[i][VItem8param3] = strval(string);
				mysql_fetch_field_row(string, "Item9param3", db_con2);
				gVehData[i][VItem9param3] = strval(string);
				mysql_fetch_field_row(string, "Item10param3", db_con2);
				gVehData[i][VItem10param3] = strval(string);
				mysql_fetch_field_row(string, "Item11param3", db_con2);
				gVehData[i][VItem11param3] = strval(string);
				mysql_fetch_field_row(string, "Item12param3", db_con2);
				gVehData[i][VItem12param3] = strval(string);
				mysql_fetch_field_row(string, "Item13param3", db_con2);
				gVehData[i][VItem13param3] = strval(string);
				mysql_fetch_field_row(string, "Item14param3", db_con2);
				gVehData[i][VItem14param3] = strval(string);
				mysql_fetch_field_row(string, "Item15param3", db_con2);
				gVehData[i][VItem15param3] = strval(string);
				mysql_fetch_field_row(string, "Item1param4", db_con2);
				gVehData[i][VItem1param4] = strval(string);
				mysql_fetch_field_row(string, "Item2param4", db_con2);
				gVehData[i][VItem2param4] = strval(string);
				mysql_fetch_field_row(string, "Item3param4", db_con2);
				gVehData[i][VItem3param4] = strval(string);
				mysql_fetch_field_row(string, "Item4param4", db_con2);
				gVehData[i][VItem4param4] = strval(string);
				mysql_fetch_field_row(string, "Item5param4", db_con2);
				gVehData[i][VItem5param4] = strval(string);
				mysql_fetch_field_row(string, "Item6param4", db_con2);
				gVehData[i][VItem6param4] = strval(string);
				mysql_fetch_field_row(string, "Item7param4", db_con2);
				gVehData[i][VItem7param4] = strval(string);
				mysql_fetch_field_row(string, "Item8param4", db_con2);
				gVehData[i][VItem8param4] = strval(string);
				mysql_fetch_field_row(string, "Item9param4", db_con2);
				gVehData[i][VItem9param4] = strval(string);
				mysql_fetch_field_row(string, "Item10param4", db_con2);
				gVehData[i][VItem10param4] = strval(string);
				mysql_fetch_field_row(string, "Item11param4", db_con2);
				gVehData[i][VItem11param4] = strval(string);
				mysql_fetch_field_row(string, "Item12param4", db_con2);
				gVehData[i][VItem12param4] = strval(string);
				mysql_fetch_field_row(string, "Item13param4", db_con2);
				gVehData[i][VItem13param4] = strval(string);
				mysql_fetch_field_row(string, "Item14param4", db_con2);
				gVehData[i][VItem14param4] = strval(string);
				mysql_fetch_field_row(string, "Item15param4", db_con2);
				gVehData[i][VItem15param4] = strval(string);
				mysql_fetch_field_row(gVehData[i][VItem1param5], "Item1param5", db_con2);
				mysql_fetch_field_row(gVehData[i][VItem2param5], "Item2param5", db_con2);
				mysql_fetch_field_row(gVehData[i][VItem3param5], "Item3param5", db_con2);
				mysql_fetch_field_row(gVehData[i][VItem4param5], "Item4param5", db_con2);
				mysql_fetch_field_row(gVehData[i][VItem5param5], "Item5param5", db_con2);
				mysql_fetch_field_row(gVehData[i][VItem6param5], "Item6param5", db_con2);
				mysql_fetch_field_row(gVehData[i][VItem7param5], "Item7param5", db_con2);
				mysql_fetch_field_row(gVehData[i][VItem8param5], "Item8param5", db_con2);
				mysql_fetch_field_row(gVehData[i][VItem9param5], "Item9param5", db_con2);
				mysql_fetch_field_row(gVehData[i][VItem10param5], "Item10param5", db_con2);
				mysql_fetch_field_row(gVehData[i][VItem11param5], "Item11param5", db_con2);
				mysql_fetch_field_row(gVehData[i][VItem12param5], "Item12param5", db_con2);
				mysql_fetch_field_row(gVehData[i][VItem13param5], "Item13param5", db_con2);
				mysql_fetch_field_row(gVehData[i][VItem14param5], "Item14param5", db_con2);
				mysql_fetch_field_row(gVehData[i][VItem15param5], "Item15param5", db_con2);
				mysql_fetch_field_row(string, "Item1param6", db_con2);
				gVehData[i][VItem1param6] = strval(string);
				mysql_fetch_field_row(string, "Item2param6", db_con2);
				gVehData[i][VItem2param6] = strval(string);
				mysql_fetch_field_row(string, "Item3param6", db_con2);
				gVehData[i][VItem3param6] = strval(string);
				mysql_fetch_field_row(string, "Item4param6", db_con2);
				gVehData[i][VItem4param6] = strval(string);
				mysql_fetch_field_row(string, "Item5param6", db_con2);
				gVehData[i][VItem5param6] = strval(string);
				mysql_fetch_field_row(string, "Item6param6", db_con2);
				gVehData[i][VItem6param6] = strval(string);
				mysql_fetch_field_row(string, "Item7param6", db_con2);
				gVehData[i][VItem7param6] = strval(string);
				mysql_fetch_field_row(string, "Item8param6", db_con2);
				gVehData[i][VItem8param6] = strval(string);
				mysql_fetch_field_row(string, "Item9param6", db_con2);
				gVehData[i][VItem9param6] = strval(string);
				mysql_fetch_field_row(string, "Item10param6", db_con2);
				gVehData[i][VItem10param6] = strval(string);
				mysql_fetch_field_row(string, "Item11param6", db_con2);
				gVehData[i][VItem11param6] = strval(string);
				mysql_fetch_field_row(string, "Item12param6", db_con2);
				gVehData[i][VItem12param6] = strval(string);
				mysql_fetch_field_row(string, "Item13param6", db_con2);
				gVehData[i][VItem13param6] = strval(string);
				mysql_fetch_field_row(string, "Item14param6", db_con2);
				gVehData[i][VItem14param6] = strval(string);
				mysql_fetch_field_row(string, "Item15param6", db_con2);
				gVehData[i][VItem15param6] = strval(string);


				id = CreateVehicle(gVehData[i][mVehModel],gVehData[i][mVehX],gVehData[i][mVehY],gVehData[i][mVehZ],gVehData[i][mVehA],gVehData[i][mVehColor1],gVehData[i][mVehColor2], -1);
				if(gVehData[i][CarLights] == 4)
				{
					lightsd = 100;
				}
				if(gVehData[i][CarLights] == 5)
				{
					lightsd = 101;
				}
				if(gVehData[i][CarLights] == 1)
				{
					lightsd = 1;
				}
				if(gVehData[i][CarLights] == 0)
				{
					lightsd = 0;
				}
				UpdateVehicleDamageStatus(id, gVehData[i][CarPanels], gVehData[i][CarDoors], lightsd, gVehData[i][CarTires]);
				LinkVehicleToInterior(id, gVehData[i][mVehInt]);
				SetVehicleVirtualWorld(id, gVehData[i][mVehVW]);
				GetVehicleParamsEx(id,enginedyn,lights,alarm,doors,bonnet,boot,objective);
				SetVehicleParamsEx(id,gVehData[i][EngineOn],gVehData[i][LightsOn],0,gVehData[i][Closed],gVehData[i][BonnetUp],gVehData[i][BootUp],objective);
				SetVehicleHealth(id, gVehData[i][CarHealth]);
				DismountSirenFromVehicle(i);
				
				if(gVehData[i][CarSerial] < 10 && gVehData[i][CarSerial] > 0)
					format(string, sizeof(string), "SA-000%d", gVehData[i][CarSerial]);
				if(gVehData[i][CarSerial] > 10 && gVehData[i][CarSerial] < 100)
					format(string, sizeof(string), "SA-00%d", gVehData[i][CarSerial]);
				if(gVehData[i][CarSerial] > 100 && gVehData[i][CarSerial] < 1000)
					format(string, sizeof(string), "SA-0%d", gVehData[i][CarSerial]);
				if(gVehData[i][CarSerial] > 1000)
					format(string, sizeof(string), "SA-%d", gVehData[i][CarSerial]);

				if(gVehData[i][mVehModel] == 431)
				{
					BusRoute[i] = CreateDynamic3DTextLabel(" ", COLOR_LIGHTYELLOW, 0.8, 5.8, 1, 10.0, INVALID_PLAYER_ID, i+1, 1);
				}

				gVehData[i][RadioVol] = 100;

				if(gVehData[i][CarSerial] > 0)
				{
					if(IsAMotorBike(id) && gVehData[i][mVehModel] != 522 && gVehData[i][mVehModel] != 471 && gVehData[i][mVehModel] != 468)
					{
						SetVehicleNumberPlate(id, string);
						// veh3dserial[i] = CreateDynamic3DTextLabel(string, COLOR_WHITE, 0.0, -1.0, 0.3, 20.0, INVALID_PLAYER_ID, id, 0);
					}
					else if(gVehData[i][mVehModel] == 522 || gVehData[i][mVehModel] == 471 || gVehData[i][mVehModel] == 468)
					{
						gVehData[i][Veh3DSerial] = CreateDynamic3DTextLabel(string, COLOR_WHITE, 0.0, -1.0, 0.3, 20.0, INVALID_PLAYER_ID, id, 0);
					}
					if(IsABoat(id))
					{
						gVehData[i][Veh3DSerial] = CreateDynamic3DTextLabel(string, COLOR_WHITE, 0.0, 1.0, 0.2, 25.0, INVALID_PLAYER_ID, id, 0);
					}
					if(IsAPlane(id))
					{
						gVehData[i][Veh3DSerial] = CreateDynamic3DTextLabel(string, COLOR_WHITE, 0.0, 1.0, 0.2, 25.0, INVALID_PLAYER_ID, id, 0);
					}
					if(IsAHelicopter(id))
					{
						gVehData[i][Veh3DSerial] = CreateDynamic3DTextLabel(string, COLOR_WHITE, 0.0, -2.5, 0.9, 25.0, INVALID_PLAYER_ID, id, 0);
					}
					if(IsABoat(id) == 0 && IsABike(id) == 0 && IsAPlane(id) == 0 && IsAHelicopter(id) == 0 && IsAMotorBike(id) == 0)
					{
						SetVehicleNumberPlate(id, string);
						// veh3dserial[i] = CreateDynamic3DTextLabel(string, COLOR_WHITE, 0.0, -2.5, -0.5, 20.0, INVALID_PLAYER_ID, id, 0);
					}
				}

				if(gVehData[i][ReadyToSell] == 1)
					gVehData[i][Veh3DSell] = CreateDynamic3DTextLabel("Sprzedam !", COLOR_LIGHTBLUE, 0.0, 0.0, 0.6, 5.0, INVALID_PLAYER_ID, id, 1);
				if(gVehData[i][mVehFaction] != 255)
				{
					if(DynamicFactions[ gVehData[i][mVehFaction] ][fType] == 6)
					{
						gVehData[i][Veh3DTaxiNfo] = CreateDynamic3DTextLabel("TAXI", COLOR_YELLOW, 0.0, 0.0, 1.0, 20.0, INVALID_PLAYER_ID, id, 1);
						if( DynamicFactions[ gVehData[i][mVehFaction] ][fTaxiEnterCost] > 0 )
							format( string, sizeof(string), "cena za KM: %d$ + %d$", DynamicFactions[ gVehData[i][mVehFaction] ][fTaxiKMCost], DynamicFactions[ gVehData[i][mVehFaction] ][fTaxiEnterCost] );
						else
							format( string, sizeof(string), "cena za KM: %d$", DynamicFactions[ gVehData[i][mVehFaction] ][fTaxiKMCost] );
						gVehData[i][Veh3DTaxiNfo2] = CreateDynamic3DTextLabel(string, COLOR_YELLOW, 0.0, 0.0, 0.8, 20.0, INVALID_PLAYER_ID, id, 1);
					}
				}
				i++;
				// }
				// else
				// {
					// format(string, sizeof(string), "INSERT INTO `samp_vehicles` (`ID`) VALUES ('%d')", i+1);
					// mysql_query(string);

					// gVehData[i][mVehModel] = 594;
					// gVehData[i][mVehX] = 0.0;
					// gVehData[i][mVehY] = 0.0;
					// gVehData[i][mVehZ] = 0.0;
					// gVehData[i][mVehA] = 0.0;
					// gVehData[i][mVehColor1] = -1;
					// gVehData[i][mVehColor2] = -1;
					// gVehData[i][mVehFaction] = 255;
					// gVehData[i][mVehType] = 0;
					// gVehData[i][Owned] = 0;
					// strmid(gVehData[i][Owner], "None", 0, 4, 255);
					// gVehData[i][Price] = 0;
					// gVehData[i][Closed] = 0;
					// gVehData[i][CarResetT] = 0;
					// gVehData[i][CarDamaged] = 0;
					// gVehData[i][CarRepairTimeLeft] = 0;
					// gVehData[i][BusinessID] = 0;
					// gVehData[i][CarFuel] = 0;
					// gVehData[i][CarHealth] = 1000.0;
					// gVehData[i][ReadyToSell] = 0;
					// gVehData[i][CarCounter] = 0;
					// gVehData[i][Fuel] = 0;
					// gVehData[i][CarPanels] = 0;
					// gVehData[i][CarDoors] = 0;
					// gVehData[i][CarLights] = 0;
					// gVehData[i][CarTires] = 0;
					// strmid(gVehData[i][LastDriverWKey], "None", 0, 4, 255);
					// gVehData[i][CarSerial] = 0;
					// gVehData[i][PaintStep] = 0;

					// CreateVehicle(gVehData[i][mVehModel],gVehData[i][mVehX],gVehData[i][mVehY],gVehData[i][mVehZ],gVehData[i][mVehA],gVehData[i][mVehColor1],gVehData[i][mVehColor2], -1);

					// i++;
				// }
			}
			#if defined DEBUG
				print("[INFO:] Dynamic vehicles loaded [MySQL]");
			#endif

			mysql_free_result(db_con2);
		}
		case LOAD_ITEM_FACTORIES:
		{
			if(!mysql_store_result(db_con2))
			{
				ErrorLog("[ERROR:] Can't store result on LOAD_ITEM_FACTORIES");
				GameModeExit();
				return 1;
			}
			new i = 0;
			while(mysql_fetch_row_format(db_result, "|", db_con2))
			{
				mysql_fetch_field_row(gItemFactories[i][fName], "name", db_con2);
				mysql_fetch_field_row(string, "posX", db_con2);
				gItemFactories[i][fPosX] = floatstr(string);
				mysql_fetch_field_row(string, "posY", db_con2);
				gItemFactories[i][fPosY] = floatstr(string);
				mysql_fetch_field_row(string, "posZ", db_con2);
				gItemFactories[i][fPosZ] = floatstr(string);
				mysql_fetch_field_row(string, "item1", db_con2);
				gItemFactories[i][item1] = strval(string);
				mysql_fetch_field_row(string, "item1type", db_con2);
				gItemFactories[i][item1type] = strval(string);
				mysql_fetch_field_row(string, "item1count", db_con2);
				gItemFactories[i][item1count] = strval(string);
				mysql_fetch_field_row(string, "item1minBuy", db_con2);
				gItemFactories[i][item1minBuy] = strval(string);
				mysql_fetch_field_row(string, "item1reproduceCount", db_con2);
				gItemFactories[i][item1reproduceCount] = strval(string);
				mysql_fetch_field_row(string, "item1price", db_con2);
				gItemFactories[i][item1price] = strval(string);
				mysql_fetch_field_row(string, "item2", db_con2);
				gItemFactories[i][item2] = strval(string);
				mysql_fetch_field_row(string, "item2type", db_con2);
				gItemFactories[i][item2type] = strval(string);
				mysql_fetch_field_row(string, "item2count", db_con2);
				gItemFactories[i][item2count] = strval(string);
				mysql_fetch_field_row(string, "item2minBuy", db_con2);
				gItemFactories[i][item2minBuy] = strval(string);
				mysql_fetch_field_row(string, "item2reproduceCount", db_con2);
				gItemFactories[i][item2reproduceCount] = strval(string);
				mysql_fetch_field_row(string, "item2price", db_con2);
				gItemFactories[i][item2price] = strval(string);
				mysql_fetch_field_row(string, "item3", db_con2);
				gItemFactories[i][item3] = strval(string);
				mysql_fetch_field_row(string, "item3type", db_con2);
				gItemFactories[i][item3type] = strval(string);
				mysql_fetch_field_row(string, "item3count", db_con2);
				gItemFactories[i][item3count] = strval(string);
				mysql_fetch_field_row(string, "item3minBuy", db_con2);
				gItemFactories[i][item3minBuy] = strval(string);
				mysql_fetch_field_row(string, "item3reproduceCount", db_con2);
				gItemFactories[i][item3reproduceCount] = strval(string);
				mysql_fetch_field_row(string, "item3price", db_con2);
				gItemFactories[i][item3price] = strval(string);
				mysql_fetch_field_row(string, "item4", db_con2);
				gItemFactories[i][item4] = strval(string);
				mysql_fetch_field_row(string, "item4type", db_con2);
				gItemFactories[i][item4type] = strval(string);
				mysql_fetch_field_row(string, "item4count", db_con2);
				gItemFactories[i][item4count] = strval(string);
				mysql_fetch_field_row(string, "item4minBuy", db_con2);
				gItemFactories[i][item4minBuy] = strval(string);
				mysql_fetch_field_row(string, "item4reproduceCount", db_con2);
				gItemFactories[i][item4reproduceCount] = strval(string);
				mysql_fetch_field_row(string, "item4price", db_con2);
				gItemFactories[i][item4price] = strval(string);
				mysql_fetch_field_row(string, "item5", db_con2);
				gItemFactories[i][item5] = strval(string);
				mysql_fetch_field_row(string, "item5type", db_con2);
				gItemFactories[i][item5type] = strval(string);
				mysql_fetch_field_row(string, "item5count", db_con2);
				gItemFactories[i][item5count] = strval(string);
				mysql_fetch_field_row(string, "item5minBuy", db_con2);
				gItemFactories[i][item5minBuy] = strval(string);
				mysql_fetch_field_row(string, "item5reproduceCount", db_con2);
				gItemFactories[i][item5reproduceCount] = strval(string);
				mysql_fetch_field_row(string, "item5price", db_con2);
				gItemFactories[i][item5price] = strval(string);
				mysql_fetch_field_row(string, "item6", db_con2);
				gItemFactories[i][item6] = strval(string);
				mysql_fetch_field_row(string, "item6type", db_con2);
				gItemFactories[i][item6type] = strval(string);
				mysql_fetch_field_row(string, "item6count", db_con2);
				gItemFactories[i][item6count] = strval(string);
				mysql_fetch_field_row(string, "item6minBuy", db_con2);
				gItemFactories[i][item6minBuy] = strval(string);
				mysql_fetch_field_row(string, "item6reproduceCount", db_con2);
				gItemFactories[i][item6reproduceCount] = strval(string);
				mysql_fetch_field_row(string, "item6price", db_con2);
				gItemFactories[i][item6price] = strval(string);
				mysql_fetch_field_row(string, "item7", db_con2);
				gItemFactories[i][item7] = strval(string);
				mysql_fetch_field_row(string, "item7type", db_con2);
				gItemFactories[i][item7type] = strval(string);
				mysql_fetch_field_row(string, "item7count", db_con2);
				gItemFactories[i][item7count] = strval(string);
				mysql_fetch_field_row(string, "item7minBuy", db_con2);
				gItemFactories[i][item7minBuy] = strval(string);
				mysql_fetch_field_row(string, "item7reproduceCount", db_con2);
				gItemFactories[i][item7reproduceCount] = strval(string);
				mysql_fetch_field_row(string, "item7price", db_con2);
				gItemFactories[i][item7price] = strval(string);
				mysql_fetch_field_row(string, "item8", db_con2);
				gItemFactories[i][item8] = strval(string);
				mysql_fetch_field_row(string, "item8type", db_con2);
				gItemFactories[i][item8type] = strval(string);
				mysql_fetch_field_row(string, "item8count", db_con2);
				gItemFactories[i][item8count] = strval(string);
				mysql_fetch_field_row(string, "item8minBuy", db_con2);
				gItemFactories[i][item8minBuy] = strval(string);
				mysql_fetch_field_row(string, "item8reproduceCount", db_con2);
				gItemFactories[i][item8reproduceCount] = strval(string);
				mysql_fetch_field_row(string, "item8price", db_con2);
				gItemFactories[i][item8price] = strval(string);
				mysql_fetch_field_row(string, "item9", db_con2);
				gItemFactories[i][item9] = strval(string);
				mysql_fetch_field_row(string, "item9type", db_con2);
				gItemFactories[i][item9type] = strval(string);
				mysql_fetch_field_row(string, "item9count", db_con2);
				gItemFactories[i][item9count] = strval(string);
				mysql_fetch_field_row(string, "item9minBuy", db_con2);
				gItemFactories[i][item9minBuy] = strval(string);
				mysql_fetch_field_row(string, "item9reproduceCount", db_con2);
				gItemFactories[i][item9reproduceCount] = strval(string);
				mysql_fetch_field_row(string, "item9price", db_con2);
				gItemFactories[i][item9price] = strval(string);
				mysql_fetch_field_row(string, "item10", db_con2);
				gItemFactories[i][item10] = strval(string);
				mysql_fetch_field_row(string, "item10type", db_con2);
				gItemFactories[i][item10type] = strval(string);
				mysql_fetch_field_row(string, "item10count", db_con2);
				gItemFactories[i][item10count] = strval(string);
				mysql_fetch_field_row(string, "item10minBuy", db_con2);
				gItemFactories[i][item10minBuy] = strval(string);
				mysql_fetch_field_row(string, "item10reproduceCount", db_con2);
				gItemFactories[i][item10reproduceCount] = strval(string);
				mysql_fetch_field_row(string, "item10price", db_con2);
				gItemFactories[i][item10price] = strval(string);

				gItemFactories[i][fCPID] = CreateDynamicCP(gItemFactories[i][fPosX], gItemFactories[i][fPosY], gItemFactories[i][fPosZ], 3.0, 0, 0, -1, 10.0);

				i++;
			}
			mysql_free_result(db_con2);
			#if defined DEBUG
				print("[INFO:] Loaded item factories [MySQL]");
			#endif
			return 1;
		}
		case LOAD_CUSTOM_OBJECTS:
		{
			if(!mysql_store_result(db_con2))
			{
				ErrorLog("[ERROR:] Can't store result on LOAD_CUSTOM_OBJECTS");
				GameModeExit();
				return 1;
			}

			new i = 0;

			while(mysql_fetch_row_format(db_result, "|", db_con2))
			{
				split2(db_result, arrCoords, '|');
				i = strval(arrCoords[0])-1;
				if(strval(arrCoords[1]))
					gCustomObj[i][cstSlotUsed] = true;
				else
					gCustomObj[i][cstSlotUsed] = false;
				gCustomObj[i][cstObjModel] = strval(arrCoords[2]);
				gCustomObj[i][cstObjVW] = strval(arrCoords[3]);
				gCustomObj[i][cstObjInt] = strval(arrCoords[4]);
				format(gCustomObj[i][cstObjOwner], MAX_PLAYER_NAME, "%s", arrCoords[5]);
				if(gCustomObj[i][cstSlotUsed] && gCustomObj[i][cstObjModel] != 0)
				{
					gCustomObj[i][cstObjID] = CreateDynamicObject(gCustomObj[i][cstObjModel], floatstr(arrCoords[6]), floatstr(arrCoords[7]), floatstr(arrCoords[8]), floatstr(arrCoords[9]), floatstr(arrCoords[10]), floatstr(arrCoords[11]), gCustomObj[i][cstObjVW], gCustomObj[i][cstObjInt], -1, 400.0);
					// foreach(Player, j)
					// {
						// gCustomObjTextID1[j][i] = CreateDynamic3DTextLabel(" ", COLOR_LIGHTBLUE, floatstr(arrCoords[6]), floatstr(arrCoords[7]), floatstr(arrCoords[8])    , 100.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, gCustomObj[i][cstObjVW], -1, j, 100.0 );
						// gCustomObjTextID2[j][i] = CreateDynamic3DTextLabel(" ", COLOR_LIGHTBLUE, floatstr(arrCoords[6]), floatstr(arrCoords[7]), floatstr(arrCoords[8])-0.2, 100.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, gCustomObj[i][cstObjVW], -1, j, 100.0 );
						// gCustomObjTextID3[j][i] = CreateDynamic3DTextLabel(" ", COLOR_LIGHTBLUE, floatstr(arrCoords[6]), floatstr(arrCoords[7]), floatstr(arrCoords[8])-0.4, 100.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, gCustomObj[i][cstObjVW], -1, j, 100.0 );
						// gCustomObjTextID4[j][i] = CreateDynamic3DTextLabel(" ", COLOR_LIGHTBLUE, floatstr(arrCoords[6]), floatstr(arrCoords[7]), floatstr(arrCoords[8])+0.2, 100.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, gCustomObj[i][cstObjVW], -1, j, 100.0 );
					// }
					// gCustomObj[i][cstText3dID] = CreateDynamic3DTextLabel(" ", COLOR_LIGHTBLUE, floatstr(arrCoords[6]), floatstr(arrCoords[7]), floatstr(arrCoords[8]), 100.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, gCustomObj[i][cstObjVW], -1, -1, 100.0 );
					// gCustomObj[i][cstText3dID2] = CreateDynamic3DTextLabel(" ", COLOR_LIGHTBLUE, floatstr(arrCoords[6]), floatstr(arrCoords[7]), floatstr(arrCoords[8])-0.2,100.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, gCustomObj[i][cstObjVW], -1, -1, 100.0 );
					// gCustomObj[i][cstText3dID3] = CreateDynamic3DTextLabel(" ", COLOR_LIGHTBLUE, floatstr(arrCoords[6]), floatstr(arrCoords[7]), floatstr(arrCoords[8])-0.4,100.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, gCustomObj[i][cstObjVW], -1, -1, 100.0 );
					// gCustomObj[i][cstText3dID4] = CreateDynamic3DTextLabel(" ", COLOR_LIGHTBLUE, floatstr(arrCoords[6]), floatstr(arrCoords[7]), floatstr(arrCoords[8])+0.2, 100.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, gCustomObj[i][cstObjVW], -1, -1, 100.0 );
				}
			}
			mysql_free_result(db_con2);
			#if defined DEBUG
				print("[INFO:] Custom objects loaded [MySQL]");
			#endif
		}
		case LOAD_HOUSES_DATA:
		{
			if(!mysql_store_result(db_con2))
			{
				ErrorLog("[ERROR:] Can't store result on LOAD_HOUSES_DATA");
				GameModeExit();
				return 1;
			}
			
			new i;
			i = 0;

			while(mysql_fetch_row_format(db_result, "|", db_con2))
			{				
				mysql_fetch_field_row(HousesData[i][mDescription], "Description", db_con2);
				mysql_fetch_field_row(string, "Size", db_con2);
				HousesData[i][mSize] = strval(string);
				mysql_fetch_field_row(string, "ExitX", db_con2);
				HousesData[i][mExitX] = floatstr(string);
				mysql_fetch_field_row(string, "ExitY", db_con2);
				HousesData[i][mExitY] = floatstr(string);
				mysql_fetch_field_row(string, "ExitZ", db_con2);
				HousesData[i][mExitZ] = floatstr(string);
				mysql_fetch_field_row(string, "ExitA", db_con2);
				HousesData[i][mExitA] = floatstr(string);
				mysql_fetch_field_row(string, "ExitInt", db_con2);
				HousesData[i][mExitInt] = strval(string);
				
				i++;
			}
			#if defined DEBUG
				print("[INFO:] Houses data reloaded [MySQL]");
			#endif
			mysql_free_result(db_con2);
		}
		case LOAD_HOUSES_ITEMS:
		{
			if( !mysql_store_result(db_con2) )
			{
				ErrorLog("[ERROR:] Can't store result on LOAD_HOUSES_ITEMS");
				GameModeExit();
				return 1;
			}

			new i;
			i = 0;

			while(mysql_fetch_row_format(db_result, "|", db_con2))
			{
				split2(db_result, arrCoords, '|');

				Houses[i][HItem1] = strval(arrCoords[1]);
				Houses[i][HItem2] = strval(arrCoords[2]);
				Houses[i][HItem3] = strval(arrCoords[3]);
				Houses[i][HItem4] = strval(arrCoords[4]);
				Houses[i][HItem5] = strval(arrCoords[5]);
				Houses[i][HItem1type] = strval(arrCoords[6]);
				Houses[i][HItem2type] = strval(arrCoords[7]);
				Houses[i][HItem3type] = strval(arrCoords[8]);
				Houses[i][HItem4type] = strval(arrCoords[9]);
				Houses[i][HItem5type] = strval(arrCoords[10]);
				Houses[i][HItem1param] = strval(arrCoords[11]);
				Houses[i][HItem2param] = strval(arrCoords[12]);
				Houses[i][HItem3param] = strval(arrCoords[13]);
				Houses[i][HItem4param] = strval(arrCoords[14]);
				Houses[i][HItem5param] = strval(arrCoords[15]);
				Houses[i][HItem1param2] = strval(arrCoords[16]);
				Houses[i][HItem2param2] = strval(arrCoords[17]);
				Houses[i][HItem3param2] = strval(arrCoords[18]);
				Houses[i][HItem4param2] = strval(arrCoords[19]);
				Houses[i][HItem5param2] = strval(arrCoords[20]);
				Houses[i][HItem1param3] = strval(arrCoords[21]);
				Houses[i][HItem2param3] = strval(arrCoords[22]);
				Houses[i][HItem3param3] = strval(arrCoords[23]);
				Houses[i][HItem4param3] = strval(arrCoords[24]);
				Houses[i][HItem5param3] = strval(arrCoords[25]);
				Houses[i][HItem1param4] = strval(arrCoords[26]);
				Houses[i][HItem2param4] = strval(arrCoords[27]);
				Houses[i][HItem3param4] = strval(arrCoords[28]);
				Houses[i][HItem4param4] = strval(arrCoords[29]);
				Houses[i][HItem5param4] = strval(arrCoords[30]);
				strdel(Houses[i][HItem1param5], 0, 64);
				strins(Houses[i][HItem1param5], arrCoords[31], 0, 64);
				strdel(Houses[i][HItem2param5], 0, 64);
				strins(Houses[i][HItem2param5], arrCoords[32], 0, 64);
				strdel(Houses[i][HItem3param5], 0, 64);
				strins(Houses[i][HItem3param5], arrCoords[33], 0, 64);
				strdel(Houses[i][HItem4param5], 0, 64);
				strins(Houses[i][HItem4param5], arrCoords[34], 0, 64);
				strdel(Houses[i][HItem5param5], 0, 64);
				strins(Houses[i][HItem5param5], arrCoords[35], 0, 64);
				Houses[i][HItem1param6] = strval(arrCoords[36]);
				Houses[i][HItem2param6] = strval(arrCoords[37]);
				Houses[i][HItem3param6] = strval(arrCoords[38]);
				Houses[i][HItem4param6] = strval(arrCoords[39]);
				Houses[i][HItem5param6] = strval(arrCoords[40]);
				i++;
			}
			mysql_free_result(db_con2);
			#if defined DEBUG
				print("[INFO:] Houses items loaded [MySQL]");
			#endif
		}
		case LOAD_BUILDINGS:
		{
			if( !mysql_store_result(db_con2) )
			{
				ErrorLog("[ERROR:] Can't store result on LOAD_BUILDINGS");
				GameModeExit();
				return 1;
			}

			new i = 0;

			while(mysql_fetch_row_format(db_result, "|", db_con2))
			{
				split2(db_result, arrCoords, '|');

				strmid(Building[i][BuildingName], arrCoords[1], 0, strlen(arrCoords[1]), 255);
				Building[i][EnterX] = floatstr(arrCoords[2]);
				Building[i][EnterY] = floatstr(arrCoords[3]);
				Building[i][EnterZ] = floatstr(arrCoords[4]);
				Building[i][EntranceFee] = strval(arrCoords[5]);
				Building[i][EnterWorld] = strval(arrCoords[6]);
				Building[i][EnterInterior] = strval(arrCoords[7]);
				Building[i][EnterAngle] = floatstr(arrCoords[8]);
				Building[i][ExitX] = floatstr(arrCoords[9]);
				Building[i][ExitY] = floatstr(arrCoords[10]);
				Building[i][ExitZ] = floatstr(arrCoords[11]);
				Building[i][ExitInterior] = strval(arrCoords[12]);
				Building[i][ExitAngle] = floatstr(arrCoords[13]);
				Building[i][Locked] = strval(arrCoords[14]);
				Building[i][Opened] = strval(arrCoords[15]);
				Building[i][Closed] = strval(arrCoords[16]);
				Building[i][ObjectID] = strval(arrCoords[17]);
				Building[i][BuildingType] = strval(arrCoords[18]);
				Building[i][ShowIcon] = strval(arrCoords[19]);
				Building[i][IconType] = strval(arrCoords[20]);

				if( Building[i][EnterX] != 0.0 || Building[i][EnterY] != 0.0 )
					Building[i][PickupID] = CreateDynamicPickup(1239, 1, Building[i][EnterX], Building[i][EnterY], Building[i][EnterZ]);

				i++;
			}
			mysql_free_result(db_con2);
			#if defined DEBUG
				print("[INFO:] Buildings loaded [MySQL]");
			#endif
		}
		case LOAD_HOUSES:
		{
			if( !mysql_store_result(db_con2) )
			{
				ErrorLog("[ERROR:] Can't store result on LOAD_HOUSES");
				GameModeExit();
				return 1;
			}

			new i;
			new houselocation[MAX_ZONE_NAME];
			i = 0;

			while(mysql_fetch_row_format(db_result, "|", db_con2))
			{
				mysql_fetch_field_row(Houses[i][Description], "Description", db_con2);
				mysql_fetch_field_row(Houses[i][Owner], "Owner", db_con2);
				mysql_fetch_field_row(string, "UID", db_con2);
				Houses[i][HUID] = strval(string);
				mysql_fetch_field_row(Houses[i][HRenter], "Renter", db_con2);
				mysql_fetch_field_row(string, "EnterX", db_con2);
				Houses[i][EnterX] = floatstr(string);
				mysql_fetch_field_row(string, "EnterY", db_con2);
				Houses[i][EnterY] = floatstr(string);
				mysql_fetch_field_row(string, "EnterZ", db_con2);
				Houses[i][EnterZ] = floatstr(string);
				mysql_fetch_field_row(string, "EnterWorld", db_con2);
				Houses[i][EnterWorld] = strval(string);
				mysql_fetch_field_row(string, "EnterInterior", db_con2);
				Houses[i][EnterInterior] = strval(string);
				mysql_fetch_field_row(string, "EnterAngle", db_con2);
				Houses[i][EnterAngle] = floatstr(string);
				mysql_fetch_field_row(string, "ExitX", db_con2);
				Houses[i][ExitX] = floatstr(string);
				mysql_fetch_field_row(string, "ExitY", db_con2);
				Houses[i][ExitY] = floatstr(string);
				mysql_fetch_field_row(string, "ExitZ", db_con2);
				Houses[i][ExitZ] = floatstr(string);
				mysql_fetch_field_row(string, "ExitInterior", db_con2);
				Houses[i][ExitInterior] = strval(string);
				mysql_fetch_field_row(string, "ExitAngle", db_con2);
				Houses[i][ExitAngle] = floatstr(string);
				mysql_fetch_field_row(string, "Owned", db_con2);
				Houses[i][Owned] = strval(string);
				mysql_fetch_field_row(string, "Rentable", db_con2);
				Houses[i][Rentable] = strval(string);
				mysql_fetch_field_row(string, "RentCost", db_con2);
				Houses[i][RentCost] = strval(string);
				mysql_fetch_field_row(string, "HousePrice", db_con2);
				Houses[i][HousePrice] = strval(string);
				mysql_fetch_field_row(string, "Money", db_con2);
				Houses[i][Money] = strval(string);
				mysql_fetch_field_row(string, "Locked", db_con2);
				Houses[i][Locked] = strval(string);
				mysql_fetch_field_row(string, "HRadio1Bought", db_con2);
				Houses[i][HRadio1Bought] = strval(string);
				mysql_fetch_field_row(string, "HRadio1On", db_con2);
				Houses[i][HRadio1On] = strval(string);
				mysql_fetch_field_row(string, "HRadio1Ch", db_con2);
				Houses[i][HRadio1Ch] = strval(string);
				mysql_fetch_field_row(string, "HRadio1Vol", db_con2);
				Houses[i][HRadio1Vol] = strval(string);
				mysql_fetch_field_row(string, "HRadio1X", db_con2);
				Houses[i][HRadio1X] = floatstr(string);
				mysql_fetch_field_row(string, "HRadio1Y", db_con2);
				Houses[i][HRadio1Y] = floatstr(string);
				mysql_fetch_field_row(string, "HRadio1Z", db_con2);
				Houses[i][HRadio1Z] = floatstr(string);
				mysql_fetch_field_row(string, "HRadio1Angle", db_con2);
				Houses[i][HRadio1Angle] = floatstr(string);
				mysql_fetch_field_row(string, "HouseType", db_con2);
				Houses[i][HouseType] = strval(string);
				mysql_fetch_field_row(string, "Confiscated", db_con2);
				Houses[i][HConfiscated] = strval(string);
				mysql_fetch_field_row(string, "Placed", db_con2);
				Houses[i][HPlaced] = strval(string);
				mysql_fetch_field_row(string, "IntSet", db_con2);
				Houses[i][HIntSet] = strval(string);
				mysql_fetch_field_row(string, "Interior", db_con2);
				Houses[i][HInterior] = strval(string);
				mysql_fetch_field_row(string, "Alarm", db_con2);
				Houses[i][HAlarm] = strval(string);
				mysql_fetch_field_row(string, "Robbed", db_con2);
				Houses[i][HRobbed] = strval(string);

				if( Houses[i][HRadio1Bought] )
					Houses[i][HRadio1Obj] = CreateDynamicObject(O_RADIO_T_1, Houses[i][HRadio1X], Houses[i][HRadio1Y], Houses[i][HRadio1Z]-1.0, 0, 0, Houses[i][HRadio1Angle], i, Houses[i][ExitInterior]);
				if(Houses[i][Owned] == 0)
				{
					if( Houses[i][EnterX] != 0.0 || Houses[i][EnterY] != 0.0 )
						Houses[i][PickupID] = CreateDynamicPickup(1273, 1, Houses[i][EnterX], Houses[i][EnterY], Houses[i][EnterZ]);

					GetCoords2DZone(Houses[i][EnterX],Houses[i][EnterY], houselocation, MAX_ZONE_NAME);

					format(string, sizeof(string), "Ten dom jest na sprzedaz!");
					Houses3DTextLabelA[i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTYELLOW2, Houses[i][EnterX], Houses[i][EnterY], Houses[i][EnterZ]+1.0, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

					format(string, sizeof(string), "Adres: %d %s",i,houselocation);
					Houses3DTextLabelB[i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTYELLOW2, Houses[i][EnterX], Houses[i][EnterY], Houses[i][EnterZ]+0.5, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

					format(string, sizeof(string), "Opis: %s, Cena: %d$",Houses[i][Description],Houses[i][HousePrice]);
					Houses3DTextLabelC[i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTYELLOW2, Houses[i][EnterX], Houses[i][EnterY], Houses[i][EnterZ], 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
				}
				else if(Houses[i][Owned] == 1)
				{
					if( Houses[i][EnterX] != 0.0 || Houses[i][EnterY] != 0.0 )
						Houses[i][PickupID] = CreateDynamicPickup(1239, 1, Houses[i][EnterX], Houses[i][EnterY], Houses[i][EnterZ]);

					if(Houses[i][Rentable] == 1)
					{
						GetCoords2DZone(Houses[i][EnterX],Houses[i][EnterY], houselocation, MAX_ZONE_NAME);

						format(string, sizeof(string), "Adres: %d %s",i,houselocation);
						Houses3DTextLabelA[i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTYELLOW2, Houses[i][EnterX], Houses[i][EnterY], Houses[i][EnterZ]+1.0, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

						// format(string, sizeof(string), "Wlasciciel: %s",Houses[i][Owner]);
						format(string, sizeof(string), " ",Houses[i][Owner]);
						Houses3DTextLabelB[i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTYELLOW2, Houses[i][EnterX], Houses[i][EnterY], Houses[i][EnterZ]+0.5, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

						format(string, sizeof(string), "Opis: %s Czynsz: %d$ (/wynajmijdom)",Houses[i][Description],Houses[i][RentCost]);
						Houses3DTextLabelC[i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTYELLOW2, Houses[i][EnterX], Houses[i][EnterY], Houses[i][EnterZ], 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
					}
					else
					{
						GetCoords2DZone(Houses[i][EnterX],Houses[i][EnterY], houselocation, MAX_ZONE_NAME);

						format(string, sizeof(string), "Adres: %d %s",i,houselocation);
						Houses3DTextLabelA[i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTYELLOW2, Houses[i][EnterX], Houses[i][EnterY], Houses[i][EnterZ]+1.0, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

						// format(string, sizeof(string), "Wlasciciel: %s",Houses[i][Owner]);
						format(string, sizeof(string), " ",Houses[i][Owner]);
						Houses3DTextLabelB[i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTYELLOW2, Houses[i][EnterX], Houses[i][EnterY], Houses[i][EnterZ]+0.5, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

						format(string, sizeof(string), "Opis: %s",Houses[i][Description]);
						Houses3DTextLabelC[i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTYELLOW2, Houses[i][EnterX], Houses[i][EnterY], Houses[i][EnterZ], 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
					}
				}
				i++;
			}
			mysql_free_result(db_con2);
			#if defined DEBUG
				print("[INFO:] Houses loaded [MySQL]");
			#endif
		}
		case LOAD_BUSINESSES:
		{
			if( !mysql_store_result(db_con2) )
			{
				ErrorLog("[ERROR:] Can't store result on LOAD_BUSINESSES");
				GameModeExit();
				return 1;
			}

			new i;
			i = 0;
			new businesstype[64];

			while(mysql_fetch_row_format(db_result, "|", db_con2))
			{
				mysql_fetch_field_row(Businesses[i][BusinessName], "BusinessName", db_con2);
				mysql_fetch_field_row(Businesses[i][Owner], "Owner", db_con2);
				mysql_fetch_field_row(string, "Faction", db_con2);
				Businesses[i][mFaction] = strval(string);
				mysql_fetch_field_row(string, "FactionTimeLeft", db_con2);
				Businesses[i][mFactionTimeLeft] = strval(string);
				mysql_fetch_field_row(string, "UID", db_con2);
				Businesses[i][BUID] = strval(string);
				mysql_fetch_field_row(string, "EnterX", db_con2);
				Businesses[i][EnterX] = floatstr(string);
				mysql_fetch_field_row(string, "EnterY", db_con2);
				Businesses[i][EnterY] = floatstr(string);
				mysql_fetch_field_row(string, "EnterZ", db_con2);
				Businesses[i][EnterZ] = floatstr(string);
				mysql_fetch_field_row(string, "EnterWorld", db_con2);
				Businesses[i][EnterWorld] = strval(string);
				mysql_fetch_field_row(string, "EnterInterior", db_con2);
				Businesses[i][EnterInterior] = strval(string);
				mysql_fetch_field_row(string, "EnterAngle", db_con2);
				Businesses[i][EnterAngle] = floatstr(string);
				mysql_fetch_field_row(string, "ExitX", db_con2);
				Businesses[i][ExitX] = floatstr(string);
				mysql_fetch_field_row(string, "ExitX", db_con2);
				Businesses[i][ExitX] = floatstr(string);
				mysql_fetch_field_row(string, "ExitY", db_con2);
				Businesses[i][ExitY] = floatstr(string);
				mysql_fetch_field_row(string, "ExitZ", db_con2);
				Businesses[i][ExitZ] = floatstr(string);
				mysql_fetch_field_row(string, "ExitInterior", db_con2);
				Businesses[i][ExitInterior] = strval(string);
				mysql_fetch_field_row(string, "ExitAngle", db_con2);
				Businesses[i][ExitAngle] = floatstr(string);
				mysql_fetch_field_row(string, "Owned", db_con2);
				Businesses[i][Owned] = strval(string);
				mysql_fetch_field_row(string, "Enterable", db_con2);
				Businesses[i][Enterable] = strval(string);
				mysql_fetch_field_row(string, "BizPrice", db_con2);
				Businesses[i][BizPrice] = strval(string);
				mysql_fetch_field_row(string, "EntranceCost", db_con2);
				Businesses[i][EntranceCost] = strval(string);
				mysql_fetch_field_row(string, "Till", db_con2);
				Businesses[i][Till] = strval(string);
				mysql_fetch_field_row(string, "Locked", db_con2);
				Businesses[i][Locked] = strval(string);
				mysql_fetch_field_row(string, "BizType", db_con2);
				Businesses[i][BizType] = strval(string);
				mysql_fetch_field_row(string, "Products", db_con2);
				Businesses[i][Products] = strval(string);
				mysql_fetch_field_row(string, "VehicleSpawned", db_con2);
				Businesses[i][VehicleSpawned] = strval(string);
				mysql_fetch_field_row(string, "VehicleCount", db_con2);
				Businesses[i][VehicleCount] = strval(string);
				mysql_fetch_field_row(string, "MaxVehicles", db_con2);
				Businesses[i][MaxVehicles] = strval(string);
				mysql_fetch_field_row(string, "VehicleOrderCount", db_con2);
				Businesses[i][VehicleOrderCount] = strval(string);
				mysql_fetch_field_row(string, "SalesJob", db_con2);
				Businesses[i][SalesJob] = strval(string);
				mysql_fetch_field_row(string, "W9MM", db_con2);
				Businesses[i][W9MM] = strval(string);
				mysql_fetch_field_row(string, "W9MMSil", db_con2);
				Businesses[i][W9MMSil] = strval(string);
				mysql_fetch_field_row(string, "WDesEagle", db_con2);
				Businesses[i][WDesEagle] = strval(string);
				mysql_fetch_field_row(string, "WMicroSMG", db_con2);
				Businesses[i][WMicroSMG] = strval(string);
				mysql_fetch_field_row(string, "WMP5", db_con2);
				Businesses[i][WMP5] = strval(string);
				mysql_fetch_field_row(string, "WTec9", db_con2);
				Businesses[i][WTec9] = strval(string);
				mysql_fetch_field_row(string, "WShotgun", db_con2);
				Businesses[i][WShotgun] = strval(string);
				mysql_fetch_field_row(string, "WAK47", db_con2);
				Businesses[i][WAK47] = strval(string);
				mysql_fetch_field_row(string, "WM4", db_con2);
				Businesses[i][WM4] = strval(string);
				mysql_fetch_field_row(string, "WRifle", db_con2);
				Businesses[i][WRifle] = strval(string);
				mysql_fetch_field_row(string, "WSRifle", db_con2);
				Businesses[i][WSRifle] = strval(string);
				mysql_fetch_field_row(string, "W9MMAmmo", db_con2);
				Businesses[i][W9MMAmmo] = strval(string);
				mysql_fetch_field_row(string, "W50AEAmmo", db_con2);
				Businesses[i][W50AEAmmo] = strval(string);
				mysql_fetch_field_row(string, "WBuckshot", db_con2);
				Businesses[i][WBuckshot] = strval(string);
				mysql_fetch_field_row(string, "W762MMAmmo", db_con2);
				Businesses[i][W762MMAmmo] = strval(string);
				mysql_fetch_field_row(string, "W127MMAmmo", db_con2);
				Businesses[i][W127MMAmmo] = strval(string);
				mysql_fetch_field_row(string, "BRadio1Bought", db_con2);
				Businesses[i][BRadio1Bought] = strval(string);
				mysql_fetch_field_row(string, "BRadio1On", db_con2);
				Businesses[i][BRadio1On] = strval(string);
				mysql_fetch_field_row(string, "BRadio1Ch", db_con2);
				Businesses[i][BRadio1Ch] = strval(string);
				mysql_fetch_field_row(string, "BRadio1Vol", db_con2);
				Businesses[i][BRadio1Vol] = strval(string);
				mysql_fetch_field_row(string, "BRadio1X", db_con2);
				Businesses[i][BRadio1X] = floatstr(string);
				mysql_fetch_field_row(string, "BRadio1Y", db_con2);
				Businesses[i][BRadio1Y] = floatstr(string);
				mysql_fetch_field_row(string, "BRadio1Z", db_con2);
				Businesses[i][BRadio1Z] = floatstr(string);
				mysql_fetch_field_row(string, "BRadio1Angle", db_con2);
				Businesses[i][BRadio1Angle] = floatstr(string);
				mysql_fetch_field_row(string, "Confiscated", db_con2);
				Businesses[i][BConfiscated] = strval(string);
				mysql_fetch_field_row(string, "Placed", db_con2);
				Businesses[i][BPlaced] = strval(string);
				mysql_fetch_field_row(string, "IntSet", db_con2);
				Businesses[i][BIntSet] = strval(string);
				mysql_fetch_field_row(string, "Interior", db_con2);
				Businesses[i][BInterior] = strval(string);
				mysql_fetch_field_row(string, "Gov", db_con2);
				Businesses[i][BGov] = strval(string);
				mysql_fetch_field_row(string, "Alarm", db_con2);
				Businesses[i][mAlarm] = strval(string);
				mysql_fetch_field_row(string, "Product1", db_con2);
				Businesses[i][Product1] = strval(string);
				mysql_fetch_field_row(string, "Product1type", db_con2);
				Businesses[i][Product1type] = strval(string);
				mysql_fetch_field_row(string, "Product1price", db_con2);
				Businesses[i][Product1price] = strval(string);
				mysql_fetch_field_row(string, "Product1count", db_con2);
				Businesses[i][Product1count] = strval(string);
				mysql_fetch_field_row(string, "Product1buy", db_con2);
				Businesses[i][Product1buy] = strval(string);
				mysql_fetch_field_row(string, "Product2", db_con2);
				Businesses[i][Product2] = strval(string);
				mysql_fetch_field_row(string, "Product2type", db_con2);
				Businesses[i][Product2type] = strval(string);
				mysql_fetch_field_row(string, "Product2price", db_con2);
				Businesses[i][Product2price] = strval(string);
				mysql_fetch_field_row(string, "Product2count", db_con2);
				Businesses[i][Product2count] = strval(string);
				mysql_fetch_field_row(string, "Product2buy", db_con2);
				Businesses[i][Product2buy] = strval(string);
				mysql_fetch_field_row(string, "Product3", db_con2);
				Businesses[i][Product3] = strval(string);
				mysql_fetch_field_row(string, "Product3type", db_con2);
				Businesses[i][Product3type] = strval(string);
				mysql_fetch_field_row(string, "Product3price", db_con2);
				Businesses[i][Product3price] = strval(string);
				mysql_fetch_field_row(string, "Product3count", db_con2);
				Businesses[i][Product3count] = strval(string);
				mysql_fetch_field_row(string, "Product3buy", db_con2);
				Businesses[i][Product3buy] = strval(string);
				mysql_fetch_field_row(string, "Product4", db_con2);
				Businesses[i][Product4] = strval(string);
				mysql_fetch_field_row(string, "Product4type", db_con2);
				Businesses[i][Product4type] = strval(string);
				mysql_fetch_field_row(string, "Product4price", db_con2);
				Businesses[i][Product4price] = strval(string);
				mysql_fetch_field_row(string, "Product4count", db_con2);
				Businesses[i][Product4count] = strval(string);
				mysql_fetch_field_row(string, "Product4buy", db_con2);
				Businesses[i][Product4buy] = strval(string);
				mysql_fetch_field_row(string, "Product5", db_con2);
				Businesses[i][Product5] = strval(string);
				mysql_fetch_field_row(string, "Product5type", db_con2);
				Businesses[i][Product5type] = strval(string);
				mysql_fetch_field_row(string, "Product5price", db_con2);
				Businesses[i][Product5price] = strval(string);
				mysql_fetch_field_row(string, "Product5count", db_con2);
				Businesses[i][Product5count] = strval(string);
				mysql_fetch_field_row(string, "Product5buy", db_con2);
				Businesses[i][Product5buy] = strval(string);
				mysql_fetch_field_row(string, "Product6", db_con2);
				Businesses[i][Product6] = strval(string);
				mysql_fetch_field_row(string, "Product6type", db_con2);
				Businesses[i][Product6type] = strval(string);
				mysql_fetch_field_row(string, "Product6price", db_con2);
				Businesses[i][Product6price] = strval(string);
				mysql_fetch_field_row(string, "Product6count", db_con2);
				Businesses[i][Product6count] = strval(string);
				mysql_fetch_field_row(string, "Product6buy", db_con2);
				Businesses[i][Product6buy] = strval(string);
				mysql_fetch_field_row(string, "Product7", db_con2);
				Businesses[i][Product7] = strval(string);
				mysql_fetch_field_row(string, "Product7type", db_con2);
				Businesses[i][Product7type] = strval(string);
				mysql_fetch_field_row(string, "Product7price", db_con2);
				Businesses[i][Product7price] = strval(string);
				mysql_fetch_field_row(string, "Product7count", db_con2);
				Businesses[i][Product7count] = strval(string);
				mysql_fetch_field_row(string, "Product7buy", db_con2);
				Businesses[i][Product7buy] = strval(string);
				mysql_fetch_field_row(string, "Product8", db_con2);
				Businesses[i][Product8] = strval(string);
				mysql_fetch_field_row(string, "Product8type", db_con2);
				Businesses[i][Product8type] = strval(string);
				mysql_fetch_field_row(string, "Product8price", db_con2);
				Businesses[i][Product8price] = strval(string);
				mysql_fetch_field_row(string, "Product8count", db_con2);
				Businesses[i][Product8count] = strval(string);
				mysql_fetch_field_row(string, "Product8buy", db_con2);
				Businesses[i][Product8buy] = strval(string);
				mysql_fetch_field_row(string, "Product9", db_con2);
				Businesses[i][Product9] = strval(string);
				mysql_fetch_field_row(string, "Product9type", db_con2);
				Businesses[i][Product9type] = strval(string);
				mysql_fetch_field_row(string, "Product9price", db_con2);
				Businesses[i][Product9price] = strval(string);
				mysql_fetch_field_row(string, "Product9count", db_con2);
				Businesses[i][Product9count] = strval(string);
				mysql_fetch_field_row(string, "Product9buy", db_con2);
				Businesses[i][Product9buy] = strval(string);
				mysql_fetch_field_row(string, "Product10", db_con2);
				Businesses[i][Product10] = strval(string);
				mysql_fetch_field_row(string, "Product10type", db_con2);
				Businesses[i][Product10type] = strval(string);
				mysql_fetch_field_row(string, "Product10price", db_con2);
				Businesses[i][Product10price] = strval(string);
				mysql_fetch_field_row(string, "Product10count", db_con2);
				Businesses[i][Product10count] = strval(string);
				mysql_fetch_field_row(string, "Product10buy", db_con2);
				Businesses[i][Product10buy] = strval(string);
				mysql_fetch_field_row(string, "Product11Price", db_con2);
				Businesses[i][Product11Price] = strval(string);
				mysql_fetch_field_row(string, "Product12Price", db_con2);
				Businesses[i][Product12Price] = strval(string);
				mysql_fetch_field_row(string, "Product13Price", db_con2);
				Businesses[i][Product13Price] = strval(string);
				mysql_fetch_field_row(string, "Product14Price", db_con2);
				Businesses[i][Product14Price] = strval(string);
				mysql_fetch_field_row(string, "Product15Price", db_con2);
				Businesses[i][Product15Price] = strval(string);
				mysql_fetch_field_row(string, "Product16Price", db_con2);
				Businesses[i][Product16Price] = strval(string);
				mysql_fetch_field_row(string, "Product17Price", db_con2);
				Businesses[i][Product17Price] = strval(string);
				mysql_fetch_field_row(string, "Product18Price", db_con2);
				Businesses[i][Product18Price] = strval(string);
				mysql_fetch_field_row(string, "Product19Price", db_con2);
				Businesses[i][Product19Price] = strval(string);
				mysql_fetch_field_row(string, "Product20Price", db_con2);
				Businesses[i][Product20Price] = strval(string);
				mysql_fetch_field_row(string, "Product21Price", db_con2);
				Businesses[i][Product21Price] = strval(string);
				mysql_fetch_field_row(string, "Product22Price", db_con2);
				Businesses[i][Product22Price] = strval(string);
				mysql_fetch_field_row(string, "Product23Price", db_con2);
				Businesses[i][Product23Price] = strval(string);
				mysql_fetch_field_row(string, "Product24Price", db_con2);
				Businesses[i][Product24Price] = strval(string);
				mysql_fetch_field_row(string, "Product25Price", db_con2);
				Businesses[i][Product25Price] = strval(string);
				mysql_fetch_field_row(string, "Product26Price", db_con2);
				Businesses[i][Product26Price] = strval(string);
				mysql_fetch_field_row(string, "Product27Price", db_con2);
				Businesses[i][Product27Price] = strval(string);
				mysql_fetch_field_row(string, "Product28Price", db_con2);
				Businesses[i][Product28Price] = strval(string);
				mysql_fetch_field_row(string, "Product29Price", db_con2);
				Businesses[i][Product29Price] = strval(string);
				mysql_fetch_field_row(string, "Product30Price", db_con2);
				Businesses[i][Product30Price] = strval(string);

				if(Businesses[i][BRadio1Bought])
					Businesses[i][BRadio1Obj] = CreateDynamicObject(O_RADIO_T_1, Businesses[i][BRadio1X], Businesses[i][BRadio1Y], Businesses[i][BRadio1Z]-1.0, 0, 0, Businesses[i][BRadio1Angle], i, Businesses[i][ExitInterior]);
				if(Businesses[i][BizType] != 0)
				{
					if(Businesses[i][BizType] == 1) { businesstype = "Restauracja"; }
					else if(Businesses[i][BizType] == 2) { businesstype = "Siec komorkowa"; }
					else if(Businesses[i][BizType] == 3) { businesstype = "Sklep 24/7"; }
					else if(Businesses[i][BizType] == 4) { businesstype = "Sklep z bronia"; }
					else if(Businesses[i][BizType] == 5) { businesstype = "Studio reklamowe"; }
					else if(Businesses[i][BizType] == 6) { businesstype = "Sklep z ubraniami"; }
					else if(Businesses[i][BizType] == 7) { businesstype = "Bar/Club"; }
					else if(Businesses[i][BizType] == 8) { businesstype = "Studio nagraniowe"; }
					else if(Businesses[i][BizType] == 9) { businesstype = "Studio"; }
					else if(Businesses[i][BizType] == 10) { businesstype = "Salon samochodowy"; }
					else if(Businesses[i][BizType] == 11) { businesstype = "Stacja paliw"; }
				}
				else { businesstype = "Nie ustawione"; }

				RefreshBizDescription(i);
				
				i++;
			}
			mysql_free_result(db_con2);
			#if defined DEBUG
				print("[INFO:] Businesses loaded [MySQL]");
			#endif
		}
		case LOAD_BUS_TRACKS:
		{
			if( !mysql_store_result(db_con2) )
			{
				ErrorLog("[ERROR:] Can't store result on LOAD_BUS_TRACKS");
				GameModeExit();
				return 1;
			}

			new i;
			i = 0;

			while(mysql_fetch_row_format(db_result, "|", db_con2))
			{
				split2(db_result, arrCoords, '|');

				gBusTrackEnabled[i] = strval(arrCoords[1]);
				gBusTrackStartArea[i] = strval(arrCoords[2]);

				i++;
			}
			#if defined DEBUG
				printf("[INFO:] Bus tracks data part 1/2 loaded [MySQL]");
			#endif
			mysql_free_result(db_con2);
		}
		case LOAD_BUS_TRACKS_DATA:
		{
			if( !mysql_store_result(db_con2) )
			{
				ErrorLog("[ERROR:] Can't store result on LOAD_BUS_TRACKS_DATA");
				GameModeExit();
				return 1;
			}

			new trkid, cpid;

			while(mysql_fetch_row_format(db_result, "|", db_con2))
			{
				split2(db_result, arrCoords, '|');

				trkid = strval(arrCoords[1]);
				cpid = strval(arrCoords[2]);
				gBusTrackCpX[trkid][cpid] = floatstr(arrCoords[3]);
				gBusTrackCpY[trkid][cpid] = floatstr(arrCoords[4]);
				gBusTrackCpZ[trkid][cpid] = floatstr(arrCoords[5]);
				gBusTrackCpReward[trkid][cpid] = strval(arrCoords[6]);
				gBusTrackCpType[trkid][cpid] = strval(arrCoords[7]);
				gBusTrackCpTime[trkid][cpid] = strval(arrCoords[8]);
			}
			#if defined DEBUG
				printf("[INFO:] Bus tracks data part 2/2 loaded [MySQL]");
			#endif
			mysql_free_result(db_con2);
		}
		case LOAD_TRASH_TRACKS:
		{
			if( !mysql_store_result(db_con2) )
			{
				ErrorLog("[ERROR:] Can't store result on LOAD_TRASH_TRACKS");
				GameModeExit();
				return 1;
			}

			new i;
			i = 0;

			while(mysql_fetch_row_format(db_result, "|", db_con2))
			{
				split2(db_result, arrCoords, '|');

				gTrashTrackEnabled[i] = strval(arrCoords[1]);
				gTrashTrackStartArea[i] = strval(arrCoords[2]);

				i++;
			}
			#if defined DEBUG
				printf("[INFO:] Trash tracks data part 1/2 loaded [MySQL]");
			#endif
			mysql_free_result(db_con2);
		}
		case LOAD_TRASH_TRACKS_DATA:
		{
			if( !mysql_store_result(db_con2) )
			{
				ErrorLog("[ERROR:] Can't store result on LOAD_TRASH_TRACKS_DATA");
				GameModeExit();
				return 1;
			}

			new trkid, cpid;

			while(mysql_fetch_row_format(db_result, "|", db_con2))
			{
				split2(db_result, arrCoords, '|');

				trkid = strval(arrCoords[1]);
				cpid = strval(arrCoords[2]);
				gTrashTrackCpX[trkid][cpid] = floatstr(arrCoords[3]);
				gTrashTrackCpY[trkid][cpid] = floatstr(arrCoords[4]);
				gTrashTrackCpZ[trkid][cpid] = floatstr(arrCoords[5]);
				gTrashTrackCpReward[trkid][cpid] = strval(arrCoords[6]);
				gTrashTrackCpType[trkid][cpid] = strval(arrCoords[7]);
				gTrashTrackCpTime[trkid][cpid] = strval(arrCoords[8]);
			}
			#if defined DEBUG
				printf("[INFO:] Trash tracks data part 2/2 loaded [MySQL]");
			#endif
			mysql_free_result(db_con2);
		}
		case LOAD_SWEEPER_TRACKS:
		{
			if( !mysql_store_result(db_con2) )
			{
				ErrorLog("[ERROR:] Can't store result on LOAD_SWEEPER_TRACKS");
				GameModeExit();
				return 1;
			}

			new i;
			i = 0;

			while(mysql_fetch_row_format(db_result, "|", db_con2))
			{
				split2(db_result, arrCoords, '|');

				gSweeperTrackEnabled[i] = strval(arrCoords[1]);
				gSweeperTrackStartArea[i] = strval(arrCoords[2]);

				i++;
			}
			#if defined DEBUG
				printf("[INFO:] Sweeper tracks data part 1/2 loaded [MySQL]");
			#endif
			mysql_free_result(db_con2);
		}
		case LOAD_FARMER_TRACKS:
		{
			if( !mysql_store_result(db_con2) )
			{
				ErrorLog("[ERROR:] Can't store result on LOAD_FARMER_TRACKS");
				GameModeExit();
				return 1;
			}

			new i;
			i = 0;

			while(mysql_fetch_row_format(db_result, "|", db_con2))
			{
				split2(db_result, arrCoords, '|');

				gFarmerTrackEnabled[i] = strval(arrCoords[1]);
				gFarmerTrackStartArea[i] = strval(arrCoords[2]);

				i++;
			}
			#if defined DEBUG
				printf("[INFO:] Farmer tracks data part 1/2 loaded [MySQL]");
			#endif
			mysql_free_result(db_con2);
		}
		case LOAD_SWEEPER_TRACKS_DATA:
		{
			if( !mysql_store_result(db_con2) )
			{
				ErrorLog("[ERROR:] Can't store result on LOAD_SWEEPER_TRACKS_DATA");
				GameModeExit();
				return 1;
			}

			new trkid, cpid;

			while(mysql_fetch_row_format(db_result, "|", db_con2))
			{
				split2(db_result, arrCoords, '|');

				trkid = strval(arrCoords[1]);
				cpid = strval(arrCoords[2]);
				gSweeperTrackCpX[trkid][cpid] = floatstr(arrCoords[3]);
				gSweeperTrackCpY[trkid][cpid] = floatstr(arrCoords[4]);
				gSweeperTrackCpZ[trkid][cpid] = floatstr(arrCoords[5]);
				gSweeperTrackCpReward[trkid][cpid] = strval(arrCoords[6]);
				gSweeperTrackCpType[trkid][cpid] = strval(arrCoords[7]);
				gSweeperTrackCpTime[trkid][cpid] = strval(arrCoords[8]);
			}
			#if defined DEBUG
				printf("[INFO:] Sweeper tracks data part 2/2 loaded [MySQL]");
			#endif
			mysql_free_result(db_con2);
		}
		case LOAD_FARMER_TRACKS_DATA:
		{
			if( !mysql_store_result(db_con2) )
			{
				ErrorLog("[ERROR:] Can't store result on LOAD_FARMER_TRACKS_DATA");
				GameModeExit();
				return 1;
			}

			new trkid, cpid;

			while(mysql_fetch_row_format(db_result, "|", db_con2))
			{
				split2(db_result, arrCoords, '|');

				trkid = strval(arrCoords[1]);
				cpid = strval(arrCoords[2]);
				gFarmerTrackCpX[trkid][cpid] = floatstr(arrCoords[3]);
				gFarmerTrackCpY[trkid][cpid] = floatstr(arrCoords[4]);
				gFarmerTrackCpZ[trkid][cpid] = floatstr(arrCoords[5]);
				gFarmerTrackCpReward[trkid][cpid] = strval(arrCoords[6]);
				gFarmerTrackCpType[trkid][cpid] = strval(arrCoords[7]);
				gFarmerTrackCpTime[trkid][cpid] = strval(arrCoords[8]);
			}
			#if defined DEBUG
				printf("[INFO:] Farmer tracks data part 2/2 loaded [MySQL]");
			#endif
			mysql_free_result(db_con2);
		}
		case LOAD_VARIABLES:
		{
			if( !mysql_store_result(db_con2) )
			{
				ErrorLog("[ERROR:] Can't store result on LOAD_VARIABLES");
				return 1;
			}
			new i = 0;

			while(mysql_fetch_row_format(db_result, "|", db_con2))
			{
				split2(db_result, arrCoords, '|');

				strins(DBVariables[i][varName], arrCoords[1], 0, 128);
				strins(DBVariables[i][varType], arrCoords[2], 0, 1);
				DBVariables[i][varDValue] = strval(arrCoords[3]);
				DBVariables[i][varFValue] = floatstr(arrCoords[4]);
				strins(DBVariables[i][varSValue], arrCoords[5], 0, 128);

				i++;
			}
			#if defined DEBUG
				print("[INFO:] Loaded misc data [MySQL]");
			#endif
			mysql_free_result(db_con2);
		}
		case SEND_SMS_TO_ALL:
		{
			if(!mysql_store_result(db_con4))
				return 1;
			if(!mysql_num_rows(db_con4))
			{
				mysql_free_result(db_con4);
				return 1;
			}
			while(mysql_fetch_row_format(db_result, "|", db_con4))
			{
				mysql_fetch_field_row(string, "Nr", db_con4);
				format(string, sizeof(string), "INSERT INTO `samp_sms` (`Sender` , `Receiver` , `SenderNumber` , `ReceiverNumber` , `Content`) VALUES ('%s' , '%s' , '%d' , '%d' , '%s')",
					" ", " ", gPlayerVars[playerid][mGlobalSmsSenderNumber], strval(string), gPlayerVars[playerid][mGlobalSms]);
				mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con4);
			}
			mysql_free_result(db_con1);
		}
		case SEND_SMS:
		{
			if(!mysql_store_result(db_con1))
			{
				ShowPlayerDialog(playerid, DIALOG_ITEM_3, DIALOG_STYLE_MSGBOX, "Informacja", "Sieæ jest przeci¹¿ona, spróbuj ponownie za chwile", "Ok", "");
				return 1;
			}
			if(gPlayerVars[playerid][mPhoneDataReceived])
			{
				mysql_free_result(db_con1);
				return 1;
			}
			gPlayerVars[playerid][mPhoneDataReceived] = 1;
			gPlayerVars[playerid][mPhoneDataTimeout] = -1;
			if(!mysql_num_rows(db_con1))
			{
				ShowPlayerDialog(playerid, DIALOG_ITEM_3, DIALOG_STYLE_MSGBOX, "Informacja", "Twoja karta SIM zosta³a zablokowana", "Ok", "");
				mysql_free_result(db_con1);
				return 1;
			}
			mysql_fetch_row_format(db_result, "|", db_con1);
			
			new freeSms, faction;
			mysql_fetch_field_row(string, "Type", db_con1);
			gPlayerVars[playerid][mPhoneType] = strval(string);
			mysql_fetch_field_row(string, "Faction", db_con1);
			faction = strval(string);
			if(gPlayerVars[playerid][mPhoneType] == PHONET_FEE)
			{
				mysql_fetch_field_row(string, "FreeSms", db_con1);
				freeSms = strval(string);
				if(freeSms == 0)
				{
					gPlayerData[playerid][pCost] += DynamicFactions[faction][mSmsCostFee];
					SavePlayerData(playerid, "Cost");
				}
				else
				{
					freeSms--;
					format(string, sizeof(string), "UPDATE `samp_phones` SET `Cash` = '%d' WHERE `Nr` = '%d' AND `SimID` = ' %d'",
						freeSms, gSmsList[0][mSmsSenderNumber], gSmsList[0][mSmsSenderSimId]);
				}
			}
			else if(gPlayerVars[playerid][mPhoneType] == PHONET_CARD)
			{
				mysql_fetch_field_row(string, "Cash", db_con1);
				gPlayerVars[playerid][mPhoneCash] = strval(string);
				mysql_fetch_field_row(string, "RenewalTime", db_con1);
				gPlayerVars[playerid][mPhoneRenewalTime] = strval(string);
				if(!gPlayerVars[playerid][mPhoneRenewalTime])
				{
					ShowPlayerDialog(playerid, DIALOG_ITEM_3, DIALOG_STYLE_MSGBOX, "Informacja", "Twoje konto wygas³o", "Wróæ", "");
					return 1;
				}
				if(gPlayerVars[playerid][mPhoneCash] <= 0)
				{
					ShowPlayerDialog(playerid, DIALOG_ITEM_3, DIALOG_STYLE_MSGBOX, "Informacja", "Nie posiadasz œrodków na koncie", "Wróc", "");
					return 1;
				}
				gPlayerVars[playerid][mPhoneCash] -= DynamicFactions[faction][mSmsCostCard];
				format(string, sizeof(string), "UPDATE `samp_phones` SET `Cash` = '%d' WHERE `Nr` = '%d' AND `SimID` = ' %d'",
					gPlayerVars[playerid][mPhoneCash], gSmsList[0][mSmsSenderNumber], gSmsList[0][mSmsSenderSimId]);
				mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con1);				
			}
			format(string, sizeof(string), "INSERT INTO `samp_sms` (`Sender` , `Receiver` , `SenderNumber` , `ReceiverNumber` , `Content`) VALUES ('%s' , '%s' , '%d' , '%d', '%s')",
				gPlayerData[playerid][pName], " ", gSmsList[0][mSmsSenderNumber], gSmsList[0][mSmsReceiverNumber], gSmsList[0][mSmsContent]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			
			SMSLog(gSmsList[0][mSmsContent]);
			
			ShowPlayerDialog(playerid, DIALOG_ITEM_3, DIALOG_STYLE_MSGBOX, "Informacja", "Wiadomoœæ zosta³a wys³ana", "Wróæ", "");
			mysql_free_result(db_con1);
		}
		case CHECK_PHONE_STATUS:
		{
			if(!mysql_store_result(db_con2))
			{
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Sieæ jest przeci¹¿ona, spróbuj ponownie za chwile", "Ok", "");
				return 1;
			}
			if(gPlayerVars[playerid][mPhoneDataReceived])
			{
				mysql_free_result(db_con2);
				return 1;
			}
			gPlayerVars[playerid][mPhoneDataReceived] = 1;
			gPlayerVars[playerid][mPhoneDataTimeout] = -1;
			if(!mysql_num_rows(db_con2))
			{
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Twoja karta SIM zosta³a zablokowana", "Ok", "");
				mysql_free_result(db_con2);
				return 1;
			}
			mysql_fetch_row_format(db_result, "|", db_con2);
			
			mysql_fetch_field_row(string, "Faction", db_con2);
			gPlayerVars[playerid][mPhoneFaction] = strval(string);
			if(DynamicFactions[gPlayerVars[playerid][mPhoneFaction]][fType] != FACTIONT_COMPANY_PHONE)
			{
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Brak sieci...", "Ok", "");
				mysql_free_result(db_con2);
				return 1;
			}
			
			new freeMins, freeSms;
			mysql_fetch_field_row(string, "Type", db_con2);
			gPlayerVars[playerid][mPhoneType] = strval(string);
			if(gPlayerVars[playerid][mPhoneType] == PHONET_FEE)
			{
				mysql_fetch_field_row(string, "FreeMins", db_con2);
				freeMins = strval(string);
				mysql_fetch_field_row(string, "FreeSms", db_con2);
				freeSms = strval(string);
			
				format(string, sizeof(string), "Sieæ: %s\nCena za min. po³¹czenia: %d$\nCena za sms: %d$\nDarmowe minuty: %d\nDarmowe SMSy: %d",
					DynamicFactions[Businesses[SlotParam3(playerid, gSelectedSlot[playerid])][mFaction]][mCompanyName],
					DynamicFactions[Businesses[SlotParam3(playerid, gSelectedSlot[playerid])][mFaction]][mCallCostFee],
					DynamicFactions[Businesses[SlotParam3(playerid, gSelectedSlot[playerid])][mFaction]][mSmsCostFee],
					freeMins, freeSms);
			}
			else if(gPlayerVars[playerid][mPhoneType] == PHONET_CARD)
			{
				mysql_fetch_field_row(string, "Cash", db_con2);
				gPlayerVars[playerid][mPhoneCash] = strval(string);
				mysql_fetch_field_row(string, "RenewalTime", db_con2);
				gPlayerVars[playerid][mPhoneRenewalTime] = strval(string);
				
				format(string, sizeof(string), "Sieæ: %s\nCena za min. po³¹czenia: %d$\nCena za sms: %d$\nPieni¹dze na koncie: %d$\nWa¿noœæ: %d dni",
					DynamicFactions[Businesses[SlotParam3(playerid, gSelectedSlot[playerid])][mFaction]][mCompanyName],
					DynamicFactions[Businesses[SlotParam3(playerid, gSelectedSlot[playerid])][mFaction]][mCallCostCard],
					DynamicFactions[Businesses[SlotParam3(playerid, gSelectedSlot[playerid])][mFaction]][mSmsCostCard],
					gPlayerVars[playerid][mPhoneCash], gPlayerVars[playerid][mPhoneRenewalTime]);
			}
			ShowPlayerDialog(playerid, DIALOG_ITEM_3, DIALOG_STYLE_MSGBOX, "Informacja", string, "Wróæ", "");
			mysql_free_result(db_con2);
		}			
		case CHECK_PHONE_FEE:
		{
			if(!mysql_store_result(db_con3))
			{
				ErrorLog("[ERROR:] Can't store result on CHECK_PHONE_FEE");
				return 1;
			}
			if(mysql_num_rows(db_con3) == 0)
			{
				if(InsertPlayerItemEx(playerid, 3, 16, gRandNumber[playerid], gPhoneC[playerid], gRandSimNumber[playerid], 0, "Puste") == 0)
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie masz miejsca na karte SIM");
					return 1;
				}
				if(gPlayerData[playerid][pFirstPhone] == 0)
				{
					SendClientMessage(playerid,COLOR_GREEN,"[INFO:] Kupi³eœ swoj¹ pierwsz¹ karte SIM !");
					gPlayerData[playerid][pFirstPhone] = 1;

					SavePlayerData(playerid, "FirstPhone");
				}
				else
				{
					SendClientMessage(playerid,COLOR_WHITE,"[INFO:] Kupi³eœ karte SIM");
					SendClientMessage(playerid,COLOR_WHITE,"[INFO:] Aby z niej skorzystaæ przejdŸ do /mi , wybierz karte a nastêpnie zamontuj j¹ w swoim telefonie");
				}
				GivePlayerCash(playerid, -DynamicFactions[Businesses[gPhoneC[playerid]][mFaction]][mSimActivationCost]);
				Businesses[gPhoneC[playerid]][Till] += DynamicFactions[Businesses[gPhoneC[playerid]][mFaction]][mSimActivationCost];
				SaveBizData(gPhoneC[playerid], "Till");
				format(string, sizeof(string), "INSERT INTO `samp_phones` (`PlayerName` , `Nr` , `Faction` , `FreeMins` , `FreeSms` , `RenewalTime` , `Cash` , `SimID` , `Type`) VALUES ('%s' , '%d' , '%d' , '%d' , '%d', '%d', '%d', '%d', '%d')",
					gPlayerData[playerid][pName], gRandNumber[playerid], Businesses[gBuyBusinessID[playerid]][mFaction], DynamicFactions[Businesses[gPhoneC[playerid]][mFaction]][mSimFreeMins], 
					DynamicFactions[Businesses[gPhoneC[playerid]][mFaction]][mSimFreeSms], 0, 0, gRandSimNumber[playerid], PHONET_FEE);
				mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con3);
			}
			else
			{
				gRandNumber[playerid] = 600000000 + random(999999);
				format(string, sizeof(string), "SELECT `Nr` FROM `samp_phones` WHERE `Nr` = '%d'",gRandNumber[playerid]);
				mysql_query(string, CHECK_PHONE_FEE, playerid, db_con3);
			}
			mysql_free_result(db_con3);
		}
		case CHECK_PHONE_CARD:
		{
			if(!mysql_store_result(db_con3))
			{
				ErrorLog("[ERROR:] Can't store result on CHECK_PHONE_CARD");
				return 1;
			}
			if(mysql_num_rows(db_con3) == 0)
			{
				if(InsertPlayerItemEx(playerid, 3, 16, gRandNumber[playerid], gPhoneC[playerid], gRandSimNumber[playerid], 0, "Puste") == 0)
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie masz miejsca na karte SIM");
					return 1;
				}
				if(gPlayerData[playerid][pFirstPhone] == 0)
				{
					SendClientMessage(playerid,COLOR_GREEN,"[INFO:] Kupi³eœ swoj¹ pierwsz¹ karte SIM !");
					gPlayerData[playerid][pFirstPhone] = 1;

					SavePlayerData(playerid, "FirstPhone");
				}
				else
				{
					SendClientMessage(playerid,COLOR_WHITE,"[INFO:] Kupi³eœ karte SIM");
					SendClientMessage(playerid,COLOR_WHITE,"[INFO:] Aby z niej skorzystaæ przejdŸ do /mi , wybierz karte a nastêpnie zamontuj j¹ w swoim telefonie");
				}				
				format(string, sizeof(string), "INSERT INTO `samp_phones` (`PlayerName` , `Nr` , `Faction` , `FreeMins` , `FreeSms` , `RenewalTime` , `Cash` , `SimID` , `Type`) VALUES ('%s' , '%d' , '%d' , '%d' , '%d', '%d', '%d', '%d', '%d')",
					gPlayerData[playerid][pName], gRandNumber[playerid], Businesses[gBuyBusinessID[playerid]][mFaction], 0, 0, DynamicFactions[Businesses[gPhoneC[playerid]][mFaction]][mCardRenewTime1],
					DynamicFactions[Businesses[gPhoneC[playerid]][mFaction]][mCardRenewCost1], gRandSimNumber[playerid], PHONET_CARD);
				mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con3);
			}
			else
			{
				gRandNumber[playerid] = 600000000 + random(999999);
				format(string, sizeof(string), "SELECT `Nr` FROM `samp_phones` WHERE `Nr` = '%d'",gRandNumber[playerid]);
				mysql_query(string, CHECK_PHONE_FEE, playerid, db_con3);
			}
			mysql_free_result(db_con3);
		}
		case CHECK_PHONE_TYPE_CALL:
		{
			if(Mobile[playerid] == 255)
			{
				gCallDataReceived[playerid] = 1;
				mysql_free_result(db_con3);
			}
			if(!mysql_store_result(db_con3))
			{
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Sieæ jest przeci¹¿ona, spróbuj ponownie za chwile", "Ok", "");
				return 1;
			}
			if(gCallDataReceived[playerid])
			{
				mysql_free_result(db_con3);
				return 1;
			}
			gCallDataReceived[playerid] = 1;
			if(!mysql_num_rows(db_con3))
			{
				mysql_free_result(db_con3);
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Twoja karta SIM zosta³a zablokowana", "Ok", "");
				return 1;
			}
			mysql_fetch_row_format(db_result, "|", db_con3);
			
			mysql_fetch_field_row(string, "SimID", db_con3);
			gPlayerVars[playerid][mPhoneSimID] = strval(string);
			mysql_fetch_field_row(string, "Type", db_con3);
			gPlayerVars[playerid][mPhoneType] = strval(string);
			if(gPlayerVars[playerid][mPhoneType] == PHONET_FEE)
			{
				mysql_fetch_field_row(string, "FreeMins", db_con3);
				gCallFreeMins[playerid] = strval(string);
				if(gCallFreeMins[playerid] <= 0)
					gCallCost[playerid] = DynamicFactions[Businesses[gCalledCompany[playerid]][mFaction]][mCallCostFee];
				else
				{
					gCallFreeMins[playerid]--;
					gCallCost[playerid] = 0;
				}
			}
			else if(gPlayerVars[playerid][mPhoneType] == PHONET_CARD)
			{
				mysql_fetch_field_row(string, "Cash", db_con3);
				gPlayerVars[playerid][mPhoneCash] = strval(string);
				if(gPlayerVars[playerid][mPhoneCash] <= DynamicFactions[Businesses[gCalledCompany[playerid]][mFaction]][mCallCostCard])
				{
					mysql_free_result(db_con3);
					ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Nie masz wystarczaj¹cej iloœci œrodków na koncie aby wykonaæ po³¹czenie", "Zamknij", "");
					return 1;
				}
				gCallCost[playerid] = DynamicFactions[Businesses[gCalledCompany[playerid]][mFaction]][mCallCostCard];
			}
			
			defer BlinkPhoneCall(gSelectedNumberID[playerid]);
			
			if(!IsPlayerInAnyVehicle(playerid))
			{
				SetPlayerSpecialAction(playerid,SPECIAL_ACTION_USECELLPHONE);
				SetPlayerAttachedObject(playerid, 1, 330, 6);
			}
			mysql_free_result(db_con3);
		}
		case CHECK_PHONE_TYPE_EXTENSION:
		{
			if(!mysql_store_result(db_con1))
			{
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Sieæ jest przeci¹¿ona, spróbuj ponownie za chwile", "Ok", "");
				return 1;
			}
			if(!mysql_num_rows(db_con1))
			{
				mysql_free_result(db_con1);
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Twoja karta SIM zosta³a zablokowana", "Ok", "");
				return 1;
			}
			// mysql_fetch_row_format(db_result, "|", db_con3);
			mysql_fetch_field_row(string, "Type", db_con1);
			gPlayerVars[playerid][mPhoneType] = strval(string);
			if(gPlayerVars[playerid][mPhoneType] == PHONET_FEE)
			{
				mysql_free_result(db_con1);
				ShowPlayerDialog(playerid, DIALOG_ITEM_3, DIALOG_STYLE_MSGBOX, "Informacja", "Nie mo¿esz do³adowaæ karty w abonamencie", "Wróæ", "");
				return 1;
			}
			else if(gPlayerVars[playerid][mPhoneType] == PHONET_CARD)
			{
				mysql_fetch_row_format(db_result, "|", db_con2);
				
				mysql_fetch_field_row(string, "Cash", db_con2);
				gPlayerVars[playerid][mPhoneCash] = strval(string);
				mysql_fetch_field_row(string, "RenewalTime", db_con2);
				gPlayerVars[playerid][mPhoneRenewalTime] = strval(string);
				mysql_fetch_field_row(string, "SimID", db_con2);
				gPlayerVars[playerid][mPhoneSimID] = strval(string);
				mysql_fetch_field_row(string, "Nr", db_con2);
				gPlayerVars[playerid][mPhoneNr] = strval(string);
				format(string, sizeof(string), "UPDATE `samp_phones` SET `RenewalTime` = '%d' , `Cash` = '%d' WHERE `SimID` = '%d' AND `Nr` = '%d'",
					gPlayerVars[playerid][mPhoneRenewalTime]+SlotParam2(playerid, gSelectedSlot[playerid]),
					gPlayerVars[playerid][mPhoneCash]+SlotParam1(playerid, gSelectedSlot[playerid]),
					gPlayerVars[playerid][mPhoneSimID], gPlayerVars[playerid][mPhoneNr]);
				mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
				ShowPlayerDialog(playerid, DIALOG_ITEM_3, DIALOG_STYLE_MSGBOX, "Informacja", "Kod z karty zosta³ u¿yty", "Wróc", "");
				RemovePlayerItemExUsed(playerid, gSelectedSlot[playerid]);
				InsertPlayerItemEx(playerid, 1, 144, 0, 0, 0, 0, "Puste", 1);
			}
			mysql_free_result(db_con1);
		} 
		case CHECK_PHONE_NEW_SMS:
		{
			if(!mysql_store_result(db_con4))
			{
				return 1;
			}
			new slot[MAX_PLAYER_ITEM_SLOT];
			while(mysql_fetch_row_format(db_result, "|", db_con4))
			{
				split2(db_result, arrCoords, '|');
				foreach(Player, i)
				{
					if(!gPlayerLogged[i] || gPhoneTextBlinking[i])
						continue;
					PHaveItemEx(i, 3, 3, slot);
					for(new j = 0; j < MAX_PLAYER_ITEM_SLOT; j++)
					{
						if(slot[j] && SlotParam2(i, j+1) == strval(arrCoords[0]))
						{
							gPhoneTextReceived[i] = strval(arrCoords[0]);
							defer BlinkPhoneText(i);
							gPhoneTextBlinking[i] = 1;
							break;
						}
					}	
					PHaveItemEx(i, 3, 4, slot);
					for(new j = 0; j < MAX_PLAYER_ITEM_SLOT; j++)
					{
						if(slot[j] && SlotParam2(i, j+1) == strval(arrCoords[0]))
						{
							gPhoneTextReceived[i] = strval(arrCoords[0]);
							defer BlinkPhoneText(i);
							gPhoneTextBlinking[i] = 1;
							break;
						}
					}
				}				
			}
			mysql_free_result(db_con4);
		}
		case PHONE_LIST_SIM_REPLACE:
		{
			if(!mysql_store_result(db_con1))
			{
				ErrorLog("[ERROR:] Can't store result on PHONE_LIST_SIM_REPLACE");
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Sieæ jest przeci¹¿ona, spróbuj ponownie za chwile");
				return 1;
			}
			new i = 0;
			new k = mysql_num_rows(db_con1);
			if(k == 0)
			{
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Nie posiadasz w tej sieci ¿adnej aktywnej karty", "Wróæ", "");
				mysql_free_result(db_con1);
				return 1;
			}
			while(mysql_fetch_row_format(db_result, "|", db_con1))
			{
				split2(db_result, arrCoords, '|');
				
				gPhoneList[i][mPhoneID] = strval(arrCoords[0]);
				gPhoneList[i][mPhoneNr] = strval(arrCoords[1]);
				gPhoneList[i][mPhoneSimID] = strval(arrCoords[2]);
				
				i++;
			}
			i = 0;
			while(i < k)
			{
				format(string, sizeof(string), "%s%d. Nr telefonu: %d, ID karty: %d\n", string, i+1, gPhoneList[i][mPhoneNr], gPhoneList[i][mPhoneSimID]);
				i++;
			}
			mysql_free_result(db_con1);
			ShowPlayerDialog(playerid, DIALOG_BUY_SIM_2_RENEW, DIALOG_STYLE_LIST, "Wybierz karte któr¹ chcesz wyrobiæ", string, "Wybierz", "Wróc");
		}
		case PHONE_LIST_FEE_RESIGN:
		{
			if(!mysql_store_result(db_con1))
			{
				ErrorLog("[ERROR:] Can't store result on PHONE_LIST_FEE_RESIGN");
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Sieæ jest przeci¹¿ona, spróbuj ponownie za chwile");
				return 1;
			}
			new i = 0;
			new k = mysql_num_rows(db_con1);
			if(k == 0)
			{
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Nie posiadasz w tej sieci ¿adnej aktywnej karty", "Wróæ", "");
				mysql_free_result(db_con1);
				return 1;
			}
			while(mysql_fetch_row_format(db_result, "|", db_con1))
			{
				split2(db_result, arrCoords, '|');
				
				gPhoneList[i][mPhoneID] = strval(arrCoords[0]);
				gPhoneList[i][mPhoneNr] = strval(arrCoords[1]);
				gPhoneList[i][mPhoneSimID] = strval(arrCoords[2]);
				
				i++;
			}
			i = 0;
			while(i < k)
			{
				format(string, sizeof(string), "%s%d. Nr telefonu: %d, ID karty: %d\n", string, i+1, gPhoneList[i][mPhoneNr], gPhoneList[i][mPhoneSimID]);
				i++;
			}
			mysql_free_result(db_con1);
			ShowPlayerDialog(playerid, DIALOG_BUY_SIM_2_RESIGN, DIALOG_STYLE_LIST, "Wybierz umowe, któr¹ chcesz rozwi¹zaæ", string, "Wybierz", "Wróc");
		}
		case PHONE_SMS_LIST:
		{
			if(!mysql_store_result(db_con1))
			{
				ErrorLog("[ERROR:] Can't store result on PHONE_SMS_LIST");
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Wyst¹pi³ problem z za³adowaniem zawartoœci skrzynki");
				return 1;
			}
			new i = 0;
			new k = mysql_num_rows(db_con1);
			if(k == 0)
			{
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Lista wiadomoœci jest pusta", "Wróæ", "");
				mysql_free_result(db_con1);
				return 1;
			}
			while(mysql_fetch_row_format(db_result, "|", db_con1))
			{
				split2(db_result, arrCoords, '|');
				
				gSmsList[i][mSmsId] = strval(arrCoords[0]);
				gSmsList[i][mSmsSenderName] = strval(arrCoords[1]);
				gSmsList[i][mSmsReceiverName] = strval(arrCoords[2]);
				gSmsList[i][mSmsSenderSimId] = strval(arrCoords[3]);
				gSmsList[i][mSmsReceiverSimId] = strval(arrCoords[4]);
				gSmsList[i][mSmsSenderNumber] = strval(arrCoords[5]);
				gSmsList[i][mSmsReceiverNumber] = strval(arrCoords[6]);
				format(gSmsList[i][mSmsContent], 256, "%s", arrCoords[7]);
				
				i++;
			}
			i = 0;
			while(i < k)
			{
				if(gSmsList[i][mSmsReceiverNumber] == SlotParam2(playerid, gSelectedSlot[playerid]))
					format(string, sizeof(string), "%s%d. Otrzymana od %d\n", string, i+1, gSmsList[i][mSmsSenderNumber]);
				else if(gSmsList[i][mSmsSenderNumber] == SlotParam2(playerid, gSelectedSlot[playerid]))
					format(string, sizeof(string), "%s%d. Wys³ana do %d\n", string, i+1, gSmsList[i][mSmsReceiverNumber]);
				i++;
			}
			mysql_free_result(db_con1);
			format(string2, sizeof(string2), "SMSy %d/50", k);
			ShowPlayerDialog(playerid, DIALOG_SMS_2_VIEW, DIALOG_STYLE_LIST, string2, string, "Wybierz", "Wróc");
		}
		case LOAD_CARSDATA:
		{
			if( !mysql_store_result(db_con2) )
			{
				ErrorLog("[ERROR:] Can't store result on LOAD_CARSDATA");
				GameModeExit();
				return 1;
			}
			new i = 0;

			while(mysql_fetch_row_format(db_result, "|", db_con2))
			{
				split2(db_result, arrCoords, '|');

				CarsData[i][Model] = strval(arrCoords[1]);
				CarsData[i][Bak] = strval(arrCoords[2]);
				CarsData[i][Paliwo] = strval(arrCoords[3]);
				CarsData[i][Spalanie] = strval(arrCoords[4]);
				CarsData[i][ToGas] = strval(arrCoords[5]);
				CarsData[i][MaxHealth] = strval(arrCoords[6]);

				switch( CarsData[i][Paliwo] )
				{
					case 0:
					{
						CarsData[i][Co2Emmision] = 2.3*(float(CarsData[i][Spalanie])/100.0);
						// printf("[DEBUG:] Co2Emmision, model: %d, fuel type: %d, combustion: %d, emmision: %f", CarsData[i][Model], CarsData[i][Paliwo], CarsData[i][Spalanie], CarsData[i][Co2Emmision]);
					}
					case 1:
					{
						CarsData[i][Co2Emmision] = 2.6*(float(CarsData[i][Spalanie])/100.0);
						// printf("[DEBUG:] Co2Emmision, model: %d, fuel type: %d, combustion: %d, emmision: %f", CarsData[i][Model], CarsData[i][Paliwo], CarsData[i][Spalanie], CarsData[i][Co2Emmision]);
					}
					case 2:
					{
						CarsData[i][Co2Emmision] = 1.4*(float(CarsData[i][Spalanie])/100.0);
						// printf("[DEBUG:] Co2Emmision, model: %d, fuel type: %d, combustion: %d, emmision: %f", CarsData[i][Model], CarsData[i][Paliwo], CarsData[i][Spalanie], CarsData[i][Co2Emmision]);
					}
					case 3:
					{
						CarsData[i][Co2Emmision] = 4.0*(float(CarsData[i][Spalanie])/100.0);
						// printf("[DEBUG:] Co2Emmision, model: %d, fuel type: %d, combustion: %d, emmision: %f", CarsData[i][Model], CarsData[i][Paliwo], CarsData[i][Spalanie], CarsData[i][Co2Emmision]);
					}
				}

				i++;
			}
			mysql_free_result(db_con2);
			#if defined DEBUG
				printf("[INFO:] Vehicles additional data loaded [MySQL]");
			#endif
		}
		case LOAD_WANTED_LIST:
		{
			// printf("[DEBUG:][LOAD_WANTED_LIST]");
			if( !mysql_store_result(db_con1) )
			{
				ErrorLog("[ERROR:] Can't store result on LOAD_WANTED_LIST");
				return 1;
			}
			new i = 0;
			while(mysql_fetch_row_format(db_result, "|", db_con1))
			{
				split2(db_result, arrCoords, '|');

				strmid(WantedList[i][WantedName], arrCoords[1], 0, strlen(arrCoords[1]), 255);
				strmid(WantedList[i][WantedDescription], arrCoords[2], 0, strlen(arrCoords[2]), 255);
				WantedList[i][WantedCommitedDay] = strval(arrCoords[3]);
				WantedList[i][WantedCommitedMonth] = strval(arrCoords[4]);
				WantedList[i][WantedCommitedYear] = strval(arrCoords[4]);

				printf("[INFO:] Wanted: %s, Description: %s, Commited day: %d, month: %d, year: %d", WantedList[i][WantedName], WantedList[i][WantedDescription], WantedList[i][WantedCommitedDay], WantedList[i][WantedCommitedMonth], WantedList[i][WantedCommitedYear]);

				i++;
			}
			mysql_free_result(db_con1);
		}
		case SHOW_SWANTED_LIST:
		{
			if(!mysql_store_result(db_con1))
			{
				ErrorLog("[ERROR:] Can't store result on SHOW_SWANTED_LIST");
				return 1;
			}
			new i = 0;
			new k = mysql_num_rows(db_con1);
			if(k == 0)
			{
				ShowPlayerDialog(playerid, DIALOG_POLICE_COMPUTER_4D, DIALOG_STYLE_MSGBOX, "Komputer policyjny", "Brak wpisów do kartoteki na wybrane nazwisko", "Wróæ", "");
				mysql_free_result(db_con1);
				return 1;
			}
			while(mysql_fetch_row_format(db_result, "|", db_con1))
			{
				split2(db_result, arrCoords, '|');

				strdel(WantedList[i][WantedName], 0, strlen(WantedList[i][WantedName]));
				strmid(WantedList[i][WantedName], arrCoords[1], 0, strlen(arrCoords[1]), 64);

				strdel(WantedList[i][WantedDescription], 0, strlen(WantedList[i][WantedDescription]));
				strmid(WantedList[i][WantedDescription], arrCoords[2], 0, strlen(arrCoords[2]), 64);

				WantedList[i][WantedCommitedDay] = strval(arrCoords[3]);
				WantedList[i][WantedCommitedMonth] = strval(arrCoords[4]);
				WantedList[i][WantedCommitedYear] = strval(arrCoords[5]);
				WantedList[i][WantedPunished] = strval(arrCoords[6]);

				i++;
			}
			i = 0;
			if(WantedList[gPlayerVars[playerid][lPoliceComputerPID]][WantedPunished])
			{
				format(string, sizeof(string), "Wpis z dnia %d/%d/%d\nUkarany: tak\nTreœæ:\n\n%s", WantedList[gPlayerVars[playerid][lPoliceComputerPID]][WantedCommitedDay], WantedList[gPlayerVars[playerid][lPoliceComputerPID]][WantedCommitedMonth],WantedList[gPlayerVars[playerid][lPoliceComputerPID]][WantedCommitedYear], WantedList[gPlayerVars[playerid][lPoliceComputerPID]][WantedDescription]);
			}
			else
			{
				format(string, sizeof(string), "Wpis z dnia %d/%d/%d\nUkarany: nie\nTreœæ:\n\n%s", WantedList[gPlayerVars[playerid][lPoliceComputerPID]][WantedCommitedDay], WantedList[gPlayerVars[playerid][lPoliceComputerPID]][WantedCommitedMonth],WantedList[gPlayerVars[playerid][lPoliceComputerPID]][WantedCommitedYear], WantedList[gPlayerVars[playerid][lPoliceComputerPID]][WantedDescription]);
			}
			mysql_free_result(db_con1);
			ShowPlayerDialog(playerid, DIALOG_POLICE_COMPUTER_3D, DIALOG_STYLE_MSGBOX, "Komputer policyjny", string, "Wróæ", "WyjdŸ");
		}
		case SHOW_DWANTED_LIST:
		{
			if(!mysql_store_result(db_con1))
			{
				ErrorLog("[ERROR:] Can't store result on SHOW_DWANTED_LIST");
				return 1;
			}
			new i = 0;
			new k = mysql_num_rows(db_con1);
			if(k == 0)
			{
				ShowPlayerDialog(playerid, DIALOG_POLICE_COMPUTER_4D, DIALOG_STYLE_MSGBOX, "Komputer policyjny", "Brak wpisów do kartoteki na wybrane nazwisko", "Wróæ", "");
				mysql_free_result(db_con1);
				return 1;
			}
			while(mysql_fetch_row_format(db_result, "|", db_con1))
			{
				split2(db_result, arrCoords, '|');

				WantedList[i][WantedID] = strval(arrCoords[0]);

				strdel(WantedList[i][WantedName], 0, strlen(WantedList[i][WantedName]));
				strmid(WantedList[i][WantedName], arrCoords[1], 0, strlen(arrCoords[1]), 64);

				strdel(WantedList[i][WantedDescription], 0, strlen(WantedList[i][WantedDescription]));
				strmid(WantedList[i][WantedDescription], arrCoords[2], 0, strlen(arrCoords[2]), 64);

				WantedList[i][WantedCommitedDay] = strval(arrCoords[3]);
				WantedList[i][WantedCommitedMonth] = strval(arrCoords[4]);
				WantedList[i][WantedCommitedYear] = strval(arrCoords[5]);
				WantedList[i][WantedPunished] = strval(arrCoords[6]);

				i++;
			}
			mysql_free_result(db_con1);
			format(string, sizeof(string), "DELETE FROM `samp_wanted` WHERE `ID` = '%d' ", WantedList[gPlayerVars[playerid][lPoliceComputerPID]][WantedID]);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);

			ShowPlayerDialog(playerid, DIALOG_POLICE_COMPUTER_3D, DIALOG_STYLE_MSGBOX, "Komputer policyjny", "Wpis zost¹³ usuniêty", "Wróæ", "Zamknij");
			return 1;
		}
		case SHOW_WANTED_LIST:
		{
			if(!mysql_store_result(db_con1))
			{
				ErrorLog("[ERROR:] Can't store result on SHOW_WANTED_LIST");
				return 1;
			}
			new i = 0;
			new k = mysql_num_rows(db_con1);
			if(k == 0)
			{
				ShowPlayerDialog(playerid, DIALOG_POLICE_COMPUTER_4D, DIALOG_STYLE_MSGBOX, "Komputer policyjny", "Brak wpisów do kartoteki na wybrane nazwisko", "Wróæ", "");
				mysql_free_result(db_con1);
				return 1;
			}
			while(mysql_fetch_row_format(db_result, "|", db_con1))
			{
				split2(db_result, arrCoords, '|');

				strdel(WantedList[i][WantedName], 0, strlen(WantedList[i][WantedName]));
				strmid(WantedList[i][WantedName], arrCoords[1], 0, strlen(arrCoords[1]), 64);

				strdel(WantedList[i][WantedDescription], 0, strlen(WantedList[i][WantedDescription]));
				strmid(WantedList[i][WantedDescription], arrCoords[2], 0, strlen(arrCoords[2]), 64);

				WantedList[i][WantedCommitedDay] = strval(arrCoords[3]);
				WantedList[i][WantedCommitedMonth] = strval(arrCoords[4]);
				WantedList[i][WantedCommitedYear] = strval(arrCoords[5]);
				WantedList[i][WantedPunished] = strval(arrCoords[6]);

				i++;
			}
			i = 0;
			while(i < k)
			{
				if(WantedList[i][WantedPunished])
				{
					format(string, sizeof(string), "%s[%d/%d/%d][T] %s\n", string, WantedList[i][WantedCommitedDay], WantedList[i][WantedCommitedMonth],WantedList[i][WantedCommitedYear], WantedList[i][WantedDescription]);
				}
				else
				{
					format(string, sizeof(string), "%s[%d/%d/%d][N] %s\n", string, WantedList[i][WantedCommitedDay], WantedList[i][WantedCommitedMonth],WantedList[i][WantedCommitedYear], WantedList[i][WantedDescription]);
				}

				i++;
			}
			mysql_free_result(db_con1);
			ShowPlayerDialog(playerid, DIALOG_POLICE_COMPUTER_3B, DIALOG_STYLE_LIST, "Komputer policyjny", string, "Wybierz", "Wróæ");
		}
		case LOAD_LUCKY_LOTTERY:
		{
			if( !mysql_store_result(db_con2) )
			{
				ErrorLog("[ERROR:] Can't store result on LOAD_LUCKY_LOTTERY");
				GameModeExit();
				return 1;
			}
			new i = 0;
			while(mysql_fetch_row_format(db_result, "|", db_con2))
			{
				mysql_fetch_field_row(string, "LotteryID", db_con2);
				gLuckyLottery[i][LuckyID] = strval(string);
				mysql_fetch_field_row(gLuckyLottery[i][LuckyPlayerName], "PlayerName", db_con2);
				mysql_fetch_field_row(string, "RewardTaken", db_con2);
				gLuckyLottery[i][LuckyRewardTaken] = strval(string);
				mysql_fetch_field_row(string, "number1", db_con2);
				gLuckyLottery[i][LuckyNumbers][0] = strval(string);
				mysql_fetch_field_row(string, "number2", db_con2);
				gLuckyLottery[i][LuckyNumbers][1] = strval(string);
				mysql_fetch_field_row(string, "number3", db_con2);
				gLuckyLottery[i][LuckyNumbers][2] = strval(string);
				mysql_fetch_field_row(string, "number4", db_con2);
				gLuckyLottery[i][LuckyNumbers][3] = strval(string);

				#if defined DEBUG
					printf("Lucky lottery ID: %d, reward taken: %d, number 1: %d, number 2: %d, number 3: %d, number 4: %d",
						gLuckyLottery[i][LuckyID],
						gLuckyLottery[i][LuckyRewardTaken],
						gLuckyLottery[i][LuckyNumbers][0],
						gLuckyLottery[i][LuckyNumbers][1],
						gLuckyLottery[i][LuckyNumbers][2],
						gLuckyLottery[i][LuckyNumbers][3]
					);
				#endif					
				
				i++;
			}
			mysql_free_result(db_con2);
			#if defined DEBUG
				printf("[INFO:] Loaded Lucky Lottery Data [MySQL]");
			#endif
		}
		case LOAD_RANDOM_PICKUP_EVENT_1:
		{
			if(!mysql_store_result(db_con4))
			{
				ErrorLog("[ERROR:] Can't store result on LOAD_RANDOM_PICKUP_EVENT_1");
				return 1;
			}
			new randomID = random(mysql_num_rows(db_con4))+1;
			gPickupEventID = randomID;
			format(string, sizeof(string), "SELECT * FROM `samp_pickup_events` WHERE `ID` = '%d'", randomID);
			mysql_query(string, LOAD_RANDOM_PICKUP_EVENT_2, db_con4);
			mysql_free_result(db_con4);
		}
		case LOAD_RANDOM_PICKUP_EVENT_2:
		{
			if(!mysql_store_result(db_con4))
			{
				ErrorLog("[ERROR:] Can't store result on LOAD_RANDOM_PICKUP_EVENT_2");
				return 1;
			}
			mysql_fetch_row_format(db_result, "|", db_con4);
			
			mysql_fetch_field_row(string, "Count", db_con4);
			gPickupEventCount = strval(string);
			mysql_fetch_field_row(string, "Time", db_con4);
			gPickupEventTime = strval(string);
			mysql_fetch_field_row(string, "PrizeType", db_con4);
			gPickupEventPrizeType = strval(string);
			mysql_fetch_field_row(string, "CashPrize", db_con4);
			gPickupEventCashPrize = strval(string);
			mysql_fetch_field_row(string, "ItemType", db_con4);
			gPickupEventItemType = strval(string);
			mysql_fetch_field_row(string, "Item", db_con4);
			gPickupEventItem = strval(string);
			mysql_fetch_field_row(string, "ItemCount", db_con4);
			gPickupEventItemCount = strval(string);
			mysql_fetch_field_row(gPickupEventMessage, "Message", db_con4);
			mysql_fetch_field_row(string, "Number", db_con4);
			gPickupEventNumber = strval(string);
			mysql_fetch_field_row(string, "CenterPosX", db_con4);
			gPickupEventCenterPosX = floatstr(string);
			mysql_fetch_field_row(string, "CenterPosY", db_con4);
			gPickupEventCenterPosY = floatstr(string);
			mysql_fetch_field_row(string, "CenterPosZ", db_con4);
			gPickupEventCenterPosZ = floatstr(string);
			mysql_fetch_field_row(string, "MapIcon", db_con4);
			gPickupEventMapIcon = strval(string);
			
			format(string, sizeof(string), "SELECT * FROM `samp_pickup_events_locations` WHERE `EventID` = '%d'", gPickupEventID);
			mysql_query(string, LOAD_RANDOM_PICKUP_EVENT_3, db_con4);
			
			mysql_free_result(db_con4);
		}
		case LOAD_RANDOM_PICKUP_EVENT_3:
		{
			if(!mysql_store_result(db_con4))
			{
				ErrorLog("[ERROR:] Can't store result on LOAD_RANDOM_PICKUP_EVENT_3");
				return 1;
			}
			new i = 0;
			while(mysql_fetch_row_format(db_result, "|", db_con4))
			{
				mysql_fetch_field_row(string, "ID", db_con4);
				gPickupEventData[i][mPickupID] = strval(string);
				mysql_fetch_field_row(string, "PosX", db_con4);
				gPickupEventData[i][mPosX] = floatstr(string);
				mysql_fetch_field_row(string, "PosY", db_con4);
				gPickupEventData[i][mPosY] = floatstr(string);
				mysql_fetch_field_row(string, "PosZ", db_con4);
				gPickupEventData[i][mPosZ] = floatstr(string);
				mysql_fetch_field_row(string, "PickupModel", db_con4);
				gPickupEventData[i][mPickupModel] = strval(string);
				
				i++;
			}
			if(gPickupEventTime == 0)
			{
				SendSmsToAll(CUSTOM_MAX_PLAYERS, gPickupEventNumber, gPickupEventMessage);
				CreatePickupEventPickups();
			}
			mysql_free_result(db_con4);
		}
		case CHECK_VEHICLE_AVAILABLE:
		{
			new modelID;
			if(!mysql_store_result(db_con4))
			{
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Chwilowo nie ma mo¿liwoœci z³o¿enia zamówienia na ten pojazd", "Zamknij", "");
				ErrorLog("[ERROR:] Can't store result on CHECK_VEHICLE_AVAILABLE");
				return 1;
			}
			mysql_fetch_row_format(db_result, "|", db_con4);
			mysql_fetch_field_row(string, "modelID", db_con4);
			modelID = strval(string);
			mysql_fetch_field_row(string, "Available", db_con4);
			if(strval(string) == 0)
			{
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "W tej chwili nie ma dostêpnego tego modelu", "Zamknij", "");
				return 1;
			}
			else if(strval(string) > 0 || strval(string) == -1)
			{
				if(strval(string) > 0)
				{
					format(string, sizeof(string), "UPDATE `samp_vehicles_limits` SET `Available` = '%d' WHERE `modelID` = '%d'", strval(string)-1, modelID);
					mysql_query(string, SAVE, playerid, db_con2);
				}				
				ImportVeh(gBuyBusinessID[playerid], modelID, gPlayerData[playerid][pName], gPlayerVars[playerid][mFuelType], gPlayerVars[playerid][mVehMaxHealth]);

				format(string, sizeof(string), "Twój pojazd jest gotowy do odebrania. Koszt: %d$\nPamiêtaj ¿e kwota pieniêdzy wyznaczona za pojazd pobierana jest dopiero w momencie sprowadzenia pojazdu !", cenyPojazdow[modelID-400]);
				format(string, sizeof(string), "%s\nJeœli w kasie biznesu nie bêdzie wystarczaj¹cej iloœci pieniêdzy samochód zostanie odes³any !", string);
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", string, "Zamknij", "");
				
				Businesses[gBuyBusinessID[playerid]][VehicleOrderCount]++;
				SaveBizData(gBuyBusinessID[playerid], "VehicleOrderCount");
			}
		}
		case LOAD_RACES_TRACKS_DATA:
		{
			if(!mysql_store_result(db_con2))
			{
				ErrorLog("[ERROR:] Can't store result on LOAD_RACES_TRACKS_DATA");
				GameModeExit();
				return 1;
			}

			new trkid, cpid;

			while(mysql_fetch_row_format(db_result, "|", db_con2))
			{
				split2(db_result, arrCoords, '|');

				trkid = strval(arrCoords[1]);
				cpid = strval(arrCoords[2]);
				gRaceTrackCpX[trkid][cpid] = floatstr(arrCoords[3]);
				gRaceTrackCpY[trkid][cpid] = floatstr(arrCoords[4]);
				gRaceTrackCpZ[trkid][cpid] = floatstr(arrCoords[5]);
				gRaceTrackCpType[trkid][cpid] = strval(arrCoords[6]);
			}
			#if defined DEBUG
				printf("[INFO:] Race tracks data part 2/2 loaded [MySQL]");
			#endif
			mysql_free_result(db_con2);
		}
		case LOAD_RACES_TRACKS:
		{
			if(!mysql_store_result(db_con2))
			{
				ErrorLog("[ERROR:] Can't store result on LOAD_RACES_TRACKS_DATA");
				GameModeExit();
				return 1;
			}

			new trkid;

			while(mysql_fetch_row_format(db_result, "|", db_con2))
			{
				split2(db_result, arrCoords, '|');

				mysql_fetch_field_row(string, "ID", db_con2);
				trkid = strval(string)-1;
				mysql_fetch_field_row(string, "Enabled", db_con2);
				gRaceTrackEnabled[trkid] = strval(string);
				mysql_fetch_field_row(string, "InfoCpX", db_con2);
				gRaceTrackInfoCpX[trkid] = floatstr(string);
				mysql_fetch_field_row(string, "InfoCpY", db_con2);
				gRaceTrackInfoCpY[trkid] = floatstr(string);
				mysql_fetch_field_row(string, "InfoCpZ", db_con2);
				gRaceTrackInfoCpZ[trkid] = floatstr(string);
				mysql_fetch_field_row(string, "StartPosCount", db_con2);
				gRaceTrackStartPosCount[trkid] = strval(string);
				mysql_fetch_field_row(string, "Start1CpX", db_con2);
				gRaceTrackStart1CpX[trkid] = strval(string);
				mysql_fetch_field_row(string, "Start1CpY", db_con2);
				gRaceTrackStart1CpY[trkid] = strval(string);
				mysql_fetch_field_row(string, "Start1CpZ", db_con2);
				gRaceTrackStart1CpZ[trkid] = strval(string);
				gRaceTrackStart2CpX[trkid] = strval(arrCoords[9]);
				gRaceTrackStart2CpY[trkid] = strval(arrCoords[10]);
				gRaceTrackStart2CpZ[trkid] = strval(arrCoords[11]);
				gRaceTrackStart3CpX[trkid] = strval(arrCoords[12]);
				gRaceTrackStart3CpY[trkid] = strval(arrCoords[13]);
				gRaceTrackStart3CpZ[trkid] = strval(arrCoords[14]);
				gRaceTrackStart4CpX[trkid] = strval(arrCoords[15]);
				gRaceTrackStart4CpY[trkid] = strval(arrCoords[16]);
				gRaceTrackStart4CpZ[trkid] = strval(arrCoords[17]);
				gRaceTrackStart5CpX[trkid] = strval(arrCoords[18]);
				gRaceTrackStart5CpY[trkid] = strval(arrCoords[19]);
				gRaceTrackStart5CpZ[trkid] = strval(arrCoords[20]);
				gRaceTrackStart6CpX[trkid] = strval(arrCoords[21]);
				gRaceTrackStart6CpY[trkid] = strval(arrCoords[22]);
				gRaceTrackStart6CpZ[trkid] = strval(arrCoords[23]);
				gRaceTrackStart7CpX[trkid] = strval(arrCoords[24]);
				gRaceTrackStart7CpY[trkid] = strval(arrCoords[25]);
				gRaceTrackStart7CpZ[trkid] = strval(arrCoords[26]);
				gRaceTrackStart8CpX[trkid] = strval(arrCoords[27]);
				gRaceTrackStart8CpY[trkid] = strval(arrCoords[28]);
				gRaceTrackStart8CpZ[trkid] = strval(arrCoords[29]);
				gRaceTrackStart9CpX[trkid] = strval(arrCoords[30]);
				gRaceTrackStart9CpY[trkid] = strval(arrCoords[31]);
				gRaceTrackStart9CpZ[trkid] = strval(arrCoords[32]);
				gRaceTrackStart10CpX[trkid] = strval(arrCoords[33]);
				gRaceTrackStart10CpY[trkid] = strval(arrCoords[34]);
				gRaceTrackStart10CpZ[trkid] = strval(arrCoords[35]);
				
				if(gRaceTrackInfoCpX[trkid] != 0.0 && gRaceTrackInfoCpY[trkid] != 0.0)
					gRaceTrackInfoPickupId[trkid] = CreateDynamicPickup(1008, 23, gRaceTrackInfoCpX[trkid], gRaceTrackInfoCpY[trkid], gRaceTrackInfoCpZ[trkid]);
			}
			#if defined DEBUG
				printf("[INFO:] Race tracks data part 2/2 loaded [MySQL]");
			#endif
			mysql_free_result(db_con2);
		}
		case LOAD_RACER_STATS:
		{
			if(!mysql_store_result(db_con2))
			{
				ErrorLog("[ERROR:] Can't store result on LOAD_RACER_STATS");
				return 1;
			}
			if(!mysql_num_rows(db_con2))
			{
				ShowPlayerDialog(playerid, DIALOG_RACE_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Nie posiadasz jeszcze statystyk na tej trasie", "Wróæ", "");
				return 1;
			}
			mysql_fetch_row_format(db_result, "|", db_con2);
			format(string, sizeof(string), "Twój nalepszy czas: %s\nIloœæ wygranych: %d\nIloœæ przegranych: %d", arrCoords[2], strval(arrCoords[4]), strval(arrCoords[5]));
			ShowPlayerDialog(playerid, DIALOG_RACE_INFO, DIALOG_STYLE_MSGBOX, "Twoje statystyki wyœcigu", string, "Wróæ", "");
			return 1;
		}
		case LOAD_WEED:
		{
			if(!mysql_store_result(db_con2))
			{
				ErrorLog("[ERROR:] Can't store result on LOAD_WEED");
				return 1;
			}
			if(!mysql_num_rows(db_con2))
			{
				ErrorLog("[ERROR:] There is no rows on LOAD_WEED");
				return 1;
			}
			new i = 0;
			while(mysql_fetch_row_format(db_result, "|", db_con2))
			{
				mysql_fetch_field_row(string, "PosX", db_con2);
				gWeed[i][mPosX] = floatstr(string);
				mysql_fetch_field_row(string, "PosY", db_con2);
				gWeed[i][mPosY] = floatstr(string);
				mysql_fetch_field_row(string, "PosZ", db_con2);
				gWeed[i][mPosZ] = floatstr(string);
				mysql_fetch_field_row(string, "Type", db_con2);
				gWeed[i][mType] = strval(string);
				mysql_fetch_field_row(string, "Phase", db_con2);
				gWeed[i][mPhase] = strval(string);
				
				#if defined DEBUG
					printf("[DEBUG:][WEED:] X: %f, Y: %f, Z: %f, type: %d, phase: %d",
						gWeed[i][mPosX],
						gWeed[i][mPosY],
						gWeed[i][mPosZ],
						gWeed[i][mType],
						gWeed[i][mPhase]);
				#endif
				
				// No need to implement each phase separatly. When weed growth function saves new Z position of the plant.
				if(gWeed[i][mPhase] != 0)
					gWeed[i][mObjId] = CreateDynamicObject(19473, gWeed[i][mPosX], gWeed[i][mPosY], gWeed[i][mPosZ], 0.0, 0.0, 0.0); 
				
				i++;
			}
			mysql_free_result(db_con2);
		}
		case LOAD_DRIVER_BOOK_QUESTION:
		{
			if(!mysql_store_result(db_con2))
			{
				ErrorLog("[ERROR:] Can't store result on LOAD_DRIVER_BOOK_QUESTION");
				ShowPlayerDialog(playerid, DIALOG_ITEM_3, DIALOG_STYLE_MSGBOX, "Informacja", "Wyst¹pi³ b³¹d. Spróbuj jeszcze raz.", "Wróæ", "");
				return 1;
			}
			if(!mysql_num_rows(db_con2))
			{
				ErrorLog("[ERROR:] There is no rows on LOAD_DRIVER_BOOK_QUESTION");
				ShowPlayerDialog(playerid, DIALOG_ITEM_3, DIALOG_STYLE_MSGBOX, "Informacja", "Wyst¹pi³ b³¹d. Spróbuj jeszcze raz.", "Wróæ", "");
				return 1;
			}
			mysql_fetch_row_format(db_result, "|", db_con2);
			
			new questionary[512];
			mysql_fetch_field_row(string, "id", db_con2);
			format(questionary, sizeof(questionary), "Pytanie nr %d:\n", strval(string));
			mysql_fetch_field_row(string, "Question", db_con2);
			format(questionary, sizeof(questionary), "%s%s", questionary, string);
			mysql_fetch_field_row(string, "Answer", db_con2);
			format(questionary, sizeof(questionary), "%s\n\nOdpowiedŸ:\n%s", questionary, string);

			ShowPlayerDialog(playerid, DIALOG_DRIVER_BOOK_2, DIALOG_STYLE_MSGBOX, "Pytanie", questionary, "Wróæ", "Zamknij");
			
			mysql_free_result(db_con2);
		}
	}
		
	return 1;
}