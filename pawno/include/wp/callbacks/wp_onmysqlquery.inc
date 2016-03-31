/***
*
* File: wp_onmysqlquery.inc
* Auth: Damian Wojdat
* Date: 15.09.2011
* Desc: Mysql functions.
*
*************************************************************************************************************/

wp_mysql_query(query[], resultid = -1, extraid = -1, connectionHandle = 1) {
	//mysql_query_callback(resultid, query, "OnQueryFinish", extraid, connectionHandle);
	mysql_function_query(connectionHandle, query, true, "OnQueryFinish", "iii", resultid, extraid, connectionHandle);
}

/*wp_mysql_free_result(connectionHandle) {
	if(!mysql_free_result(connectionHandle)) {
		printf("[ERROR:][MYSQL:] Couldn't free result ! connection handle = %d", connectionHandle);
	}
}*/

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
				wp_mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
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
			wp_mysql_free_result(db_con2);
		}
	}
	return 1;
}*/

public OnQueryError(errorid, error[], callback[], query[], connectionHandle)
{
	printf("[ERROR:] MySQL: %s, connection id: %d", error);
	printf("[ERROR:] Query: %s", query);
	return 1;
}

// public OnMysqlQuery(query[], resultid, spareid, MySQL:handle)
// public OnQueryFinish(query[], resultid, extraid, connectionHandle)
public OnQueryFinish(resultid, extraid, connectionHandle)
{
	static
		arrCoords[153][64],
		PlayerNameTMP[128],
		string[1324],
		string2[128],
		password[512],
		playerid
	;
	playerid = extraid;
	strdel(string, 0, sizeof(string));
	strdel(string2, 0, sizeof(string2));
	strdel(PlayerNameTMP, 0, sizeof(PlayerNameTMP));

	GetPlayerName(playerid, PlayerNameTMP, sizeof(PlayerNameTMP));
	switch(resultid)
	{
		case PLAYER_DATA_LOAD_FIRST_MYSQL:
		{
			#if defined DEBUG
				printf("[DEBUG:][PLAYER_DATA_LOAD_FIRST_MYSQL] pid = %d, pname = %s", playerid, PlayerNameTMP);
			#endif
			
			ClearScreen(playerid);
			
			mysql_store_result(db_con4);

			if(mysql_num_rows(db_con4) == 0)
			{
				gPlayerData[playerid][pLoading] = 0;
			
				format(string, sizeof(string), "{FFFFFF}Witaj na serwerze WParty !\n\n");
				strcat(string, "Aby siê zalogowaæ wpisz swoje has³o do postaci.\n\n\n");
				strcat(string, "{F52222}Ta nazwa postaci nie jest zarejestrowana !\nJeœli nie posiadasz jeszcze postaci musisz wpierw zarejestrowaæ swoje konto\nna forum WParty.eu a nastêpnie utworzyæ postaæ\npostêpuj¹æ wed³ug podanych tam wskazówek.\n\n");
				strcat(string, "{FAEC25}Jeœli zapomnia³eœ has³a do postaci mo¿esz je zmieniæ loguj¹c siê na forum\na nastêpnie przechodz¹c do panelu zarz¹dzania postaciami.\n\n\n");
				strcat(string, "{FFFFFF}Wpisz has³o:");
				
				ShowPlayerDialog(playerid, DIALOG_LOGIN, DIALOG_STYLE_PASSWORD, ""#COLOR_TITLE"Logowanie", string, "Zaloguj", "");
				
				return 1;
			}

			mysql_retrieve_row(db_con4);
			
			mysql_fetch_field_row(string, "Key", db_con4);
			format(password, 512, string);
			
			GetPlayerName(playerid, PlayerNameTMP, sizeof(PlayerNameTMP));
			if(strlen(PlayerNameTMP) < 5)
			{
				format( string, sizeof(string), "{FFFFFF}Witaj na serwerze WParty !\n\n" );
				strcat( string, "Aby siê zalogowaæ wpisz swoje has³o do postaci.\n\n\n" );
				strcat( string, "{F52222}Ta nazwa postaci jest za krótka !\nAby utworzyæ inn¹ postaæ o d³u¿ej nazwie przejdŸ na strone WParty.eu a nastêpnie w panelu zarz¹dzania postaciami utwórz\nnow¹ postaæ o odpowiednio d³ugiej nazwie.\n\n" );
				strcat( string, "{FAEC25}Jeœli zapomnia³eœ has³a do postaci mo¿esz je zmieniæ loguj¹c siê na forum\na nastêpnie przechodz¹c do panelu zarz¹dzania postaciami.\n\n\n" );
				strcat( string, "{FFFFFF}Wpisz has³o:" );
				gPlayerData[playerid][pLoading] = 0;
				ShowPlayerDialog(playerid, DIALOG_LOGIN, DIALOG_STYLE_PASSWORD, ""#COLOR_TITLE"Logowanie", string, "Zaloguj", "");
				return 1;
			}
			
			WP_Hash(gPasswd[playerid], 145, gPasswd[playerid]);
			if(strcmp(password, gPasswd[playerid], true) != 0 || strlen(gPasswd[playerid]) <= 0)
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
				ShowPlayerDialog(playerid, DIALOG_LOGIN, DIALOG_STYLE_PASSWORD, ""#COLOR_TITLE"Logowanie", string, "Zaloguj", "");
				return 1;
			}
			
			if(strcmp(gPlayerData[playerid][pSName], PlayerNameTMP, false, 32) != 0)
			{
				format( string, sizeof(string), "{FFFFFF}Witaj na serwerze WParty !\n\n" );
				strcat( string, "Aby siê zalogowaæ wpisz swoje has³o do postaci.\n\n\n" );
				strcat( string, "{FAEC25}Jeœli zapomnia³eœ has³a do postaci mo¿esz je zmieniæ loguj¹c siê na forum\na nastêpnie przechodz¹c do panelu zarz¹dzania postaciami.\n\n\n" );
				strcat( string, "{F52222}NIEZGODNA NAZWA U¯YTKOWNIKA !\n" );
				strcat( string, "{FFFFFF}Wpisz ponownie has³o:" );
				gPlayerData[playerid][pLoading] = 0;
				ShowPlayerDialog(playerid, DIALOG_LOGIN, DIALOG_STYLE_PASSWORD, ""#COLOR_TITLE"Logowanie", string, "Zaloguj", "");
				return 1;
			}

			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Czekaj, trwa ³adowanie danych...");

			format(string, sizeof(string), "SELECT");
			strcat(string, " `samp_users`.*");
			strcat(string, ", `samp_users_items`.*");
			strcat(string, ", `samp_users_items2`.*");
			strcat(string, ", `samp_users_items3`.*");
			strcat(string, ", `samp_users_jobs`.*");
			strcat(string, ", `samp_users_lic`.*");
			strcat(string, ", `samp_users_notes`.*");
			strcat(string, ", `samp_users_other`.*");
			strcat(string, ", `samp_users_other2`.*");
			strcat(string, ", `samp_users_vip`.*");
			strcat(string, " FROM `samp_users`");
			strcat(string, " JOIN `samp_users_items` ON `samp_users_items`.PlayerName = `samp_users`.PlayerName");
			strcat(string, " JOIN `samp_users_items2` ON `samp_users_items2`.PlayerName = `samp_users`.PlayerName");
			strcat(string, " JOIN `samp_users_items3` ON `samp_users_items3`.PlayerName = `samp_users`.PlayerName");
			strcat(string, " JOIN `samp_users_jobs` ON `samp_users_jobs`.PlayerName = `samp_users`.PlayerName");
			strcat(string, " JOIN `samp_users_lic` ON `samp_users_lic`.PlayerName = `samp_users`.PlayerName");
			strcat(string, " JOIN `samp_users_notes` ON `samp_users_notes`.PlayerName = `samp_users`.PlayerName");
			strcat(string, " JOIN `samp_users_other` ON `samp_users_other`.PlayerName = `samp_users`.PlayerName");
			strcat(string, " JOIN `samp_users_other2` ON `samp_users_other2`.PlayerName = `samp_users`.PlayerName");
			strcat(string, " JOIN `samp_users_vip` ON `samp_users_vip`.PlayerName = `samp_users`.PlayerName");
			format(string, sizeof(string), "%s WHERE `samp_users`.PlayerName = '%s'", string, PlayerNameTMP);
			
			wp_mysql_query(string, PLAYER_DATA_LOAD_ALL, playerid, db_con4);

			return 1;
		}
		case PLAYER_DATA_LOAD_OOCNAME_MYSQL:
		{
			#if defined DEBUG
				printf("[DEBUG:][PLAYER_DATA_LOAD_OOCNAME_MYSQL] pid = %d, pname = %s", playerid, gPlayerData[playerid][pName]);
			#endif
			
			mysql_store_result(db_con4);
			
			mysql_retrieve_row(db_con4);
			
			mysql_fetch_field_row(string, "username", db_con4);
			format(gPlayerData[playerid][pOOCName], 255, string);
		}
		case PLAYER_DATA_LOAD_ALL:
		{
			#if defined DEBUG
				printf("[DEBUG:][PLAYER_LOAD_OTHER2_MYSQL] pid = %d, pname = %s", playerid, gPlayerData[playerid][pName]);
			#endif
			
			if(playerid < CUSTOM_MAX_PLAYERS)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Czekaj, trwa ³adowanie danych [finalizacja]...");
			}
			
			mysql_store_result(db_con4);
			
			mysql_retrieve_row(db_con4);
			
			// samp_users
			{
				mysql_fetch_field_row(string, "PlayerName", db_con4);
				format(gPlayerData[playerid][pName], MAX_PLAYER_NAME, string);
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
				mysql_fetch_field_row(string, "CharDescription", db_con4);
				format(gPlayerData[playerid][pCharDescription], 128, string);
				mysql_fetch_field_row(string, "CharDescriptionColor", db_con4);
				format(gPlayerData[playerid][pCharDescriptionColor], 32, string);
			}
			
			// samp_users_items
			{
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
				mysql_fetch_field_row(string, "Item1param5", db_con4);
				format(gPlayerData[playerid][pItem1param5], 64, string);
				mysql_fetch_field_row(string, "Item2param5", db_con4);
				format(gPlayerData[playerid][pItem2param5], 64, string);
				mysql_fetch_field_row(string, "Item3param5", db_con4);
				format(gPlayerData[playerid][pItem3param5], 64, string);
				mysql_fetch_field_row(string, "Item4param5", db_con4);
				format(gPlayerData[playerid][pItem4param5], 64, string);
				mysql_fetch_field_row(string, "Item5param5", db_con4);
				format(gPlayerData[playerid][pItem5param5], 64, string);
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
			}
			
			// samp_users_items2
			{
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
				mysql_fetch_field_row(string, "Item6param5", db_con4);
				format(gPlayerData[playerid][pItem6param5], 64, string);
				mysql_fetch_field_row(string, "Item7param5", db_con4);
				format(gPlayerData[playerid][pItem7param5], 64, string);
				mysql_fetch_field_row(string, "Item8param5", db_con4);
				format(gPlayerData[playerid][pItem8param5], 64, string);
				mysql_fetch_field_row(string, "Item9param5", db_con4);
				format(gPlayerData[playerid][pItem9param5], 64, string);
				mysql_fetch_field_row(string, "Item10param5", db_con4);
				format(gPlayerData[playerid][pItem10param5], 64, string);
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
			}
			
			// samp_users_items3
			{
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
				mysql_fetch_field_row(string, "Item11param5", db_con4);
				format(gPlayerData[playerid][pItem11param5], 64, string);
				mysql_fetch_field_row(string, "Item12param5", db_con4);
				format(gPlayerData[playerid][pItem12param5], 64, string);
				mysql_fetch_field_row(string, "Item13param5", db_con4);
				format(gPlayerData[playerid][pItem13param5], 64, string);
				mysql_fetch_field_row(string, "Item14param5", db_con4);
				format(gPlayerData[playerid][pItem14param5], 64, string);
				mysql_fetch_field_row(string, "Item15param5", db_con4);
				format(gPlayerData[playerid][pItem15param5], 64, string);
				mysql_fetch_field_row(string, "Item16param5", db_con4);
				format(gPlayerData[playerid][pItem16param5], 64, string);
				mysql_fetch_field_row(string, "Item17param5", db_con4);
				format(gPlayerData[playerid][pItem17param5], 64, string);
				mysql_fetch_field_row(string, "Item18param5", db_con4);
				format(gPlayerData[playerid][pItem18param5], 64, string);
				mysql_fetch_field_row(string, "Item19param5", db_con4);
				format(gPlayerData[playerid][pItem19param5], 64, string);
				mysql_fetch_field_row(string, "Item20param5", db_con4);
				format(gPlayerData[playerid][pItem20param5], 64, string);
				mysql_fetch_field_row(string, "Item21param5", db_con4);
				format(gPlayerData[playerid][pItem21param5], 64, string);
				mysql_fetch_field_row(string, "Item22param5", db_con4);
				format(gPlayerData[playerid][pItem22param5], 64, string);
				mysql_fetch_field_row(string, "Item23param5", db_con4);
				format(gPlayerData[playerid][pItem23param5], 64, string);
				mysql_fetch_field_row(string, "Item24param5", db_con4);
				format(gPlayerData[playerid][pItem24param5], 64, string);
				mysql_fetch_field_row(string, "Item25param5", db_con4);
				format(gPlayerData[playerid][pItem25param5], 64, string);
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
			}
			
			// samp_users_jobs
			{
				mysql_fetch_field_row(string, "Job", db_con4);
				gPlayerData[playerid][pJob] = strval(string);
				mysql_fetch_field_row(string, "JobLvl", db_con4);
				gPlayerData[playerid][pJobLvl] = strval(string);
				mysql_fetch_field_row(string, "MzgkJobLvl", db_con4);
				gPlayerData[playerid][pMzgkJobLvl] = strval(string);
				mysql_fetch_field_row(string, "SweeperJobLvl", db_con4);
				gPlayerData[playerid][pSweeperJobLvl] = strval(string);
				mysql_fetch_field_row(string, "CarJackerJobLvl", db_con4);
				gPlayerData[playerid][pCarJackerJobLvl] = strval(string);
				mysql_fetch_field_row(string, "MechanicJobLvl", db_con4);
				gPlayerData[playerid][pMechanicJobLvl] = strval(string);
				mysql_fetch_field_row(string, "FarmerJobLvl", db_con4);
				gPlayerData[playerid][pFarmerJobLvl] = strval(string);
				mysql_fetch_field_row(string, "BusJobPoints", db_con4);
				gPlayerData[playerid][pBusJobPoints] = strval(string);
				mysql_fetch_field_row(string, "MzgkJobPoints", db_con4);
				gPlayerData[playerid][pMzgkJobPoints] = strval(string);
				mysql_fetch_field_row(string, "SweeperJobPoints", db_con4);
				gPlayerData[playerid][pSweeperJobPoints] = strval(string);
				mysql_fetch_field_row(string, "CarJackerJobPoints", db_con4);
				gPlayerData[playerid][pCarJackerJobPoints] = strval(string);
				mysql_fetch_field_row(string, "MechanicJobPoints", db_con4);
				gPlayerData[playerid][pMechanicJobPoints] = strval(string);
				mysql_fetch_field_row(string, "FarmerJobPoints", db_con4);
				gPlayerData[playerid][pFarmerJobPoints] = strval(string);
			}
			
			// samp_users_lic
			{
				mysql_fetch_field_row(string, "BoatLic", db_con4);
				gPlayerData[playerid][pBoatLic] = strval(string);
				mysql_fetch_field_row(string, "PlaneLic", db_con4);
				gPlayerData[playerid][pPlaneLic] = strval(string);
				mysql_fetch_field_row(string, "HeliLic", db_con4);
				gPlayerData[playerid][pHeliLic] = strval(string);
				mysql_fetch_field_row(string, "WepLic", db_con4);
				gPlayerData[playerid][pWepLic] = strval(string);
				mysql_fetch_field_row(string, "PenaltyPointsA", db_con4);
				gPlayerData[playerid][pPenaltyPointsA] = strval(string);
				mysql_fetch_field_row(string, "PenaltyPointsB", db_con4);
				gPlayerData[playerid][pPenaltyPointsB] = strval(string);
				mysql_fetch_field_row(string, "PenaltyPointsCE", db_con4);
				gPlayerData[playerid][pPenaltyPointsCE] = strval(string);
			}
			
			// samp_users_notes
			{
				mysql_fetch_field_row(string, "Note1", db_con4);
				format(gPlayerData[playerid][pNote1], 128, string);
				mysql_fetch_field_row(string, "Note1s", db_con4);
				gPlayerData[playerid][pNote1s] = strval(string);
				mysql_fetch_field_row(string, "Note2", db_con4);
				format(gPlayerData[playerid][pNote2], 128, string);
				mysql_fetch_field_row(string, "Note2s", db_con4);
				gPlayerData[playerid][pNote2s] = strval(string);
				mysql_fetch_field_row(string, "Note3", db_con4);
				format(gPlayerData[playerid][pNote3], 128, string);
				mysql_fetch_field_row(string, "Note3s", db_con4);
				gPlayerData[playerid][pNote3s] = strval(string);
				mysql_fetch_field_row(string, "Note4", db_con4);
				format(gPlayerData[playerid][pNote4], 128, string);
				mysql_fetch_field_row(string, "Note4s", db_con4);
				gPlayerData[playerid][pNote4s] = strval(string);
				mysql_fetch_field_row(string, "Note5", db_con4);
				format(gPlayerData[playerid][pNote5], 128, string);
				mysql_fetch_field_row(string, "Note5s", db_con4);
				gPlayerData[playerid][pNote5s] = strval(string);
			}
			
			// samp_users_vip
			{
				mysql_fetch_field_row(string, "VipCar", db_con4);
				gPlayerData[playerid][pVipCar] = strval(string);
				mysql_fetch_field_row(string, "VipAFK", db_con4);
				gPlayerData[playerid][pVipAFK] = strval(string);
				mysql_fetch_field_row(string, "VipAFKT", db_con4);
				gPlayerData[playerid][pVipAFKT] = strval(string);
				mysql_fetch_field_row(string, "VipExp", db_con4);
				gPlayerData[playerid][pVipExp] = strval(string);
				mysql_fetch_field_row(string, "VipExpT", db_con4);
				gPlayerData[playerid][pVipExpT] = strval(string);
				mysql_fetch_field_row(string, "CharacterDeath", db_con4);
				gPlayerData[playerid][pCharacterDeath] = strval(string);
				mysql_fetch_field_row(string, "CharacterDying", db_con4);
				gPlayerData[playerid][pCharacterDying] = strval(string);
				mysql_fetch_field_row(string, "VipItem", db_con4);
				gPlayerData[playerid][pVipItem] = strval(string);
				mysql_fetch_field_row(string, "AccountOwnerID", db_con4);
				gPlayerData[playerid][pAccountOwnerID] = strval(string);
				mysql_fetch_field_row(string, "VipGarage", db_con4);
				gPlayerData[playerid][pVipGarage] = strval(string);
				mysql_fetch_field_row(string, "VipGarageBig", db_con4);
				gPlayerData[playerid][pVipGarageBig] = strval(string);
				mysql_fetch_field_row(string, "VipRedNeon", db_con4);
				gPlayerData[playerid][pVipRedNeon] = strval(string);
				mysql_fetch_field_row(string, "VipBlueNeon", db_con4);
				gPlayerData[playerid][pVipBlueNeon] = strval(string);
				mysql_fetch_field_row(string, "VipGreenNeon", db_con4);
				gPlayerData[playerid][pVipGreenNeon] = strval(string);
				mysql_fetch_field_row(string, "VipYellowNeon", db_con4);
				gPlayerData[playerid][pVipYellowNeon] = strval(string);
				mysql_fetch_field_row(string, "VipPinkNeon", db_con4);
				gPlayerData[playerid][pVipPinkNeon] = strval(string);
				mysql_fetch_field_row(string, "VipWhiteNeon", db_con4);
				gPlayerData[playerid][pVipWhiteNeon] = strval(string);
				mysql_fetch_field_row(string, "VipCustomObjects", db_con4);
				gPlayerData[playerid][pVipCustomObjects] = strval(string);
				mysql_fetch_field_row(string, "VipHalogenLight", db_con4);
				gPlayerData[playerid][pVipHalogenLight] = strval(string);
				mysql_fetch_field_row(string, "VipWhitePointLight", db_con4);
				gPlayerData[playerid][pVipWhitePointLight] = strval(string);
				mysql_fetch_field_row(string, "VipRedPointLight", db_con4);
				gPlayerData[playerid][pVipRedPointLight] = strval(string);
				mysql_fetch_field_row(string, "VipGreenPointLight", db_con4);
				gPlayerData[playerid][pVipGreenPointLight] = strval(string);
				mysql_fetch_field_row(string, "VipBluePointLight", db_con4);
				gPlayerData[playerid][pVipBluePointLight] = strval(string);
			}
			
			// samp_users_other
			{
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
				mysql_fetch_field_row(string, "WSlot7", db_con4);
				gPlayerData[playerid][pWSlot7] = strval(string);
				mysql_fetch_field_row(string, "WSlot7Ammo", db_con4);
				gPlayerData[playerid][pWSlot7Ammo] = strval(string);
				mysql_fetch_field_row(string, "WSlot8", db_con4);
				gPlayerData[playerid][pWSlot8] = strval(string);
				mysql_fetch_field_row(string, "WSlot8Ammo", db_con4);
				gPlayerData[playerid][pWSlot8Ammo] = strval(string);
				mysql_fetch_field_row(string, "WSlot9", db_con4);
				gPlayerData[playerid][pWSlot9] = strval(string);
				mysql_fetch_field_row(string, "WSlot9Ammo", db_con4);
				gPlayerData[playerid][pWSlot9Ammo] = strval(string);
				mysql_fetch_field_row(string, "WSlot10", db_con4);
				gPlayerData[playerid][pWSlot10] = strval(string);
				mysql_fetch_field_row(string, "WSlot10Ammo", db_con4);
				gPlayerData[playerid][pWSlot10Ammo] = strval(string);
				mysql_fetch_field_row(string, "WSlot11", db_con4);
				gPlayerData[playerid][pWSlot11] = strval(string);
				mysql_fetch_field_row(string, "WSlot11Ammo", db_con4);
				gPlayerData[playerid][pWSlot11Ammo] = strval(string);
				mysql_fetch_field_row(string, "WSlot12", db_con4);
				gPlayerData[playerid][pWSlot12] = strval(string);
				mysql_fetch_field_row(string, "WSlot12Ammo", db_con4);
				gPlayerData[playerid][pWSlot12Ammo] = strval(string);
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
				mysql_fetch_field_row(string, "BroadCastMessages", db_con4);
				gPlayerData[playerid][mBroadCastMessages] = strval(string);
				// mysql_fetch_field_row(string, "IsLogged", db_con4);
				// gPlayerData[playerid][pIsLogged] = strval(string);
			}
			
			// samp_users_other2
			{
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
				mysql_fetch_field_row(string, "Tech", db_con4);
				gPlayerData[playerid][pTech] = strval(string);
				mysql_fetch_field_row(string, "Law", db_con4);
				gPlayerData[playerid][pLaw] = strval(string);
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
				mysql_fetch_field_row(string, "PktTech", db_con4);
				gPlayerData[playerid][pPktTech] = strval(string);
				mysql_fetch_field_row(string, "PktLaw", db_con4);
				gPlayerData[playerid][pPktLaw] = strval(string);
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
				mysql_fetch_field_row(string, "HighSchool", db_con4);
				gPlayerData[playerid][pHighSchool] = strval(string);
				mysql_fetch_field_row(string, "SchoolCooldown", db_con4);
				gPlayerData[playerid][pSchoolCooldown] = strval(string);
				mysql_fetch_field_row(string, "MountsPasses", db_con4);
				gPlayerData[playerid][pMountsPasses] = strval(string);
			}
			
			format(string, sizeof(string), "SELECT HIGH_PRIORITY * FROM `mybb_banned` WHERE `uid` = '%d'", gPlayerData[playerid][pAccountOwnerID]);
			wp_mysql_query(string, CHECK_ACCOUNT_STATUS, playerid, db_con2);
			
			
		}
		case PLAYER_DATA_LOAD_ALL_PAYDAY:
		{
			#if defined DEBUG
				printf("[DEBUG:][PLAYER_LOAD_OTHER2_MYSQL] pid = %d, pname = %s", playerid, gPlayerData[playerid][pName]);
			#endif
			
			if(playerid < CUSTOM_MAX_PLAYERS)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Czekaj, trwa ³adowanie danych [finalizacja]...");
			}
			
			mysql_store_result(db_con4);
			
			mysql_retrieve_row(db_con4);
			
			// samp_users
			{
				mysql_fetch_field_row(string, "PlayerName", db_con4);
				format(gPlayerData[playerid][pName], MAX_PLAYER_NAME, string);
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
				mysql_fetch_field_row(string, "CharDescription", db_con4);
				format(gPlayerData[playerid][pCharDescription], 128, string);
				mysql_fetch_field_row(string, "CharDescriptionColor", db_con4);
				format(gPlayerData[playerid][pCharDescriptionColor], 32, string);
			}
			
			// samp_users_items
			{
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
				mysql_fetch_field_row(string, "Item1param5", db_con4);
				format(gPlayerData[playerid][pItem1param5], 64, string);
				mysql_fetch_field_row(string, "Item2param5", db_con4);
				format(gPlayerData[playerid][pItem2param5], 64, string);
				mysql_fetch_field_row(string, "Item3param5", db_con4);
				format(gPlayerData[playerid][pItem3param5], 64, string);
				mysql_fetch_field_row(string, "Item4param5", db_con4);
				format(gPlayerData[playerid][pItem4param5], 64, string);
				mysql_fetch_field_row(string, "Item5param5", db_con4);
				format(gPlayerData[playerid][pItem5param5], 64, string);
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
			}
			
			// samp_users_items2
			{
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
				mysql_fetch_field_row(string, "Item6param5", db_con4);
				format(gPlayerData[playerid][pItem6param5], 64, string);
				mysql_fetch_field_row(string, "Item7param5", db_con4);
				format(gPlayerData[playerid][pItem7param5], 64, string);
				mysql_fetch_field_row(string, "Item8param5", db_con4);
				format(gPlayerData[playerid][pItem8param5], 64, string);
				mysql_fetch_field_row(string, "Item9param5", db_con4);
				format(gPlayerData[playerid][pItem9param5], 64, string);
				mysql_fetch_field_row(string, "Item10param5", db_con4);
				format(gPlayerData[playerid][pItem10param5], 64, string);
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
			}
			
			// samp_users_items3
			{
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
				mysql_fetch_field_row(string, "Item11param5", db_con4);
				format(gPlayerData[playerid][pItem11param5], 64, string);
				mysql_fetch_field_row(string, "Item12param5", db_con4);
				format(gPlayerData[playerid][pItem12param5], 64, string);
				mysql_fetch_field_row(string, "Item13param5", db_con4);
				format(gPlayerData[playerid][pItem13param5], 64, string);
				mysql_fetch_field_row(string, "Item14param5", db_con4);
				format(gPlayerData[playerid][pItem14param5], 64, string);
				mysql_fetch_field_row(string, "Item15param5", db_con4);
				format(gPlayerData[playerid][pItem15param5], 64, string);
				mysql_fetch_field_row(string, "Item16param5", db_con4);
				format(gPlayerData[playerid][pItem16param5], 64, string);
				mysql_fetch_field_row(string, "Item17param5", db_con4);
				format(gPlayerData[playerid][pItem17param5], 64, string);
				mysql_fetch_field_row(string, "Item18param5", db_con4);
				format(gPlayerData[playerid][pItem18param5], 64, string);
				mysql_fetch_field_row(string, "Item19param5", db_con4);
				format(gPlayerData[playerid][pItem19param5], 64, string);
				mysql_fetch_field_row(string, "Item20param5", db_con4);
				format(gPlayerData[playerid][pItem20param5], 64, string);
				mysql_fetch_field_row(string, "Item21param5", db_con4);
				format(gPlayerData[playerid][pItem21param5], 64, string);
				mysql_fetch_field_row(string, "Item22param5", db_con4);
				format(gPlayerData[playerid][pItem22param5], 64, string);
				mysql_fetch_field_row(string, "Item23param5", db_con4);
				format(gPlayerData[playerid][pItem23param5], 64, string);
				mysql_fetch_field_row(string, "Item24param5", db_con4);
				format(gPlayerData[playerid][pItem24param5], 64, string);
				mysql_fetch_field_row(string, "Item25param5", db_con4);
				format(gPlayerData[playerid][pItem25param5], 64, string);
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
			}
			
			// samp_users_jobs
			{
				mysql_fetch_field_row(string, "Job", db_con4);
				gPlayerData[playerid][pJob] = strval(string);
				mysql_fetch_field_row(string, "JobLvl", db_con4);
				gPlayerData[playerid][pJobLvl] = strval(string);
				mysql_fetch_field_row(string, "MzgkJobLvl", db_con4);
				gPlayerData[playerid][pMzgkJobLvl] = strval(string);
				mysql_fetch_field_row(string, "SweeperJobLvl", db_con4);
				gPlayerData[playerid][pSweeperJobLvl] = strval(string);
				mysql_fetch_field_row(string, "CarJackerJobLvl", db_con4);
				gPlayerData[playerid][pCarJackerJobLvl] = strval(string);
				mysql_fetch_field_row(string, "MechanicJobLvl", db_con4);
				gPlayerData[playerid][pMechanicJobLvl] = strval(string);
				mysql_fetch_field_row(string, "FarmerJobLvl", db_con4);
				gPlayerData[playerid][pFarmerJobLvl] = strval(string);
				mysql_fetch_field_row(string, "BusJobPoints", db_con4);
				gPlayerData[playerid][pBusJobPoints] = strval(string);
				mysql_fetch_field_row(string, "MzgkJobPoints", db_con4);
				gPlayerData[playerid][pMzgkJobPoints] = strval(string);
				mysql_fetch_field_row(string, "SweeperJobPoints", db_con4);
				gPlayerData[playerid][pSweeperJobPoints] = strval(string);
				mysql_fetch_field_row(string, "CarJackerJobPoints", db_con4);
				gPlayerData[playerid][pCarJackerJobPoints] = strval(string);
				mysql_fetch_field_row(string, "MechanicJobPoints", db_con4);
				gPlayerData[playerid][pMechanicJobPoints] = strval(string);
				mysql_fetch_field_row(string, "FarmerJobPoints", db_con4);
				gPlayerData[playerid][pFarmerJobPoints] = strval(string);
			}
			
			// samp_users_lic
			{
				mysql_fetch_field_row(string, "BoatLic", db_con4);
				gPlayerData[playerid][pBoatLic] = strval(string);
				mysql_fetch_field_row(string, "PlaneLic", db_con4);
				gPlayerData[playerid][pPlaneLic] = strval(string);
				mysql_fetch_field_row(string, "HeliLic", db_con4);
				gPlayerData[playerid][pHeliLic] = strval(string);
				mysql_fetch_field_row(string, "WepLic", db_con4);
				gPlayerData[playerid][pWepLic] = strval(string);
				mysql_fetch_field_row(string, "PenaltyPointsA", db_con4);
				gPlayerData[playerid][pPenaltyPointsA] = strval(string);
				mysql_fetch_field_row(string, "PenaltyPointsB", db_con4);
				gPlayerData[playerid][pPenaltyPointsB] = strval(string);
				mysql_fetch_field_row(string, "PenaltyPointsCE", db_con4);
				gPlayerData[playerid][pPenaltyPointsCE] = strval(string);
			}
			
			// samp_users_notes
			{
				mysql_fetch_field_row(string, "Note1", db_con4);
				format(gPlayerData[playerid][pNote1], 128, string);
				mysql_fetch_field_row(string, "Note1s", db_con4);
				gPlayerData[playerid][pNote1s] = strval(string);
				mysql_fetch_field_row(string, "Note2", db_con4);
				format(gPlayerData[playerid][pNote2], 128, string);
				mysql_fetch_field_row(string, "Note2s", db_con4);
				gPlayerData[playerid][pNote2s] = strval(string);
				mysql_fetch_field_row(string, "Note3", db_con4);
				format(gPlayerData[playerid][pNote3], 128, string);
				mysql_fetch_field_row(string, "Note3s", db_con4);
				gPlayerData[playerid][pNote3s] = strval(string);
				mysql_fetch_field_row(string, "Note4", db_con4);
				format(gPlayerData[playerid][pNote4], 128, string);
				mysql_fetch_field_row(string, "Note4s", db_con4);
				gPlayerData[playerid][pNote4s] = strval(string);
				mysql_fetch_field_row(string, "Note5", db_con4);
				format(gPlayerData[playerid][pNote5], 128, string);
				mysql_fetch_field_row(string, "Note5s", db_con4);
				gPlayerData[playerid][pNote5s] = strval(string);
			}
			
			// samp_users_vip
			{
				mysql_fetch_field_row(string, "VipCar", db_con4);
				gPlayerData[playerid][pVipCar] = strval(string);
				mysql_fetch_field_row(string, "VipAFK", db_con4);
				gPlayerData[playerid][pVipAFK] = strval(string);
				mysql_fetch_field_row(string, "VipAFKT", db_con4);
				gPlayerData[playerid][pVipAFKT] = strval(string);
				mysql_fetch_field_row(string, "VipExp", db_con4);
				gPlayerData[playerid][pVipExp] = strval(string);
				mysql_fetch_field_row(string, "VipExpT", db_con4);
				gPlayerData[playerid][pVipExpT] = strval(string);
				mysql_fetch_field_row(string, "CharacterDeath", db_con4);
				gPlayerData[playerid][pCharacterDeath] = strval(string);
				mysql_fetch_field_row(string, "CharacterDying", db_con4);
				gPlayerData[playerid][pCharacterDying] = strval(string);
				mysql_fetch_field_row(string, "VipItem", db_con4);
				gPlayerData[playerid][pVipItem] = strval(string);
				mysql_fetch_field_row(string, "AccountOwnerID", db_con4);
				gPlayerData[playerid][pAccountOwnerID] = strval(string);
				mysql_fetch_field_row(string, "VipGarage", db_con4);
				gPlayerData[playerid][pVipGarage] = strval(string);
				mysql_fetch_field_row(string, "VipGarageBig", db_con4);
				gPlayerData[playerid][pVipGarageBig] = strval(string);
				mysql_fetch_field_row(string, "VipRedNeon", db_con4);
				gPlayerData[playerid][pVipRedNeon] = strval(string);
				mysql_fetch_field_row(string, "VipBlueNeon", db_con4);
				gPlayerData[playerid][pVipBlueNeon] = strval(string);
				mysql_fetch_field_row(string, "VipGreenNeon", db_con4);
				gPlayerData[playerid][pVipGreenNeon] = strval(string);
				mysql_fetch_field_row(string, "VipYellowNeon", db_con4);
				gPlayerData[playerid][pVipYellowNeon] = strval(string);
				mysql_fetch_field_row(string, "VipPinkNeon", db_con4);
				gPlayerData[playerid][pVipPinkNeon] = strval(string);
				mysql_fetch_field_row(string, "VipWhiteNeon", db_con4);
				gPlayerData[playerid][pVipWhiteNeon] = strval(string);
				mysql_fetch_field_row(string, "VipCustomObjects", db_con4);
				gPlayerData[playerid][pVipCustomObjects] = strval(string);
				mysql_fetch_field_row(string, "VipHalogenLight", db_con4);
				gPlayerData[playerid][pVipHalogenLight] = strval(string);
				mysql_fetch_field_row(string, "VipWhitePointLight", db_con4);
				gPlayerData[playerid][pVipWhitePointLight] = strval(string);
				mysql_fetch_field_row(string, "VipRedPointLight", db_con4);
				gPlayerData[playerid][pVipRedPointLight] = strval(string);
				mysql_fetch_field_row(string, "VipGreenPointLight", db_con4);
				gPlayerData[playerid][pVipGreenPointLight] = strval(string);
				mysql_fetch_field_row(string, "VipBluePointLight", db_con4);
				gPlayerData[playerid][pVipBluePointLight] = strval(string);
			}
			
			// samp_users_other
			{
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
				mysql_fetch_field_row(string, "WSlot7", db_con4);
				gPlayerData[playerid][pWSlot7] = strval(string);
				mysql_fetch_field_row(string, "WSlot7Ammo", db_con4);
				gPlayerData[playerid][pWSlot7Ammo] = strval(string);
				mysql_fetch_field_row(string, "WSlot8", db_con4);
				gPlayerData[playerid][pWSlot8] = strval(string);
				mysql_fetch_field_row(string, "WSlot8Ammo", db_con4);
				gPlayerData[playerid][pWSlot8Ammo] = strval(string);
				mysql_fetch_field_row(string, "WSlot9", db_con4);
				gPlayerData[playerid][pWSlot9] = strval(string);
				mysql_fetch_field_row(string, "WSlot9Ammo", db_con4);
				gPlayerData[playerid][pWSlot9Ammo] = strval(string);
				mysql_fetch_field_row(string, "WSlot10", db_con4);
				gPlayerData[playerid][pWSlot10] = strval(string);
				mysql_fetch_field_row(string, "WSlot10Ammo", db_con4);
				gPlayerData[playerid][pWSlot10Ammo] = strval(string);
				mysql_fetch_field_row(string, "WSlot11", db_con4);
				gPlayerData[playerid][pWSlot11] = strval(string);
				mysql_fetch_field_row(string, "WSlot11Ammo", db_con4);
				gPlayerData[playerid][pWSlot11Ammo] = strval(string);
				mysql_fetch_field_row(string, "WSlot12", db_con4);
				gPlayerData[playerid][pWSlot12] = strval(string);
				mysql_fetch_field_row(string, "WSlot12Ammo", db_con4);
				gPlayerData[playerid][pWSlot12Ammo] = strval(string);
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
				mysql_fetch_field_row(string, "BroadCastMessages", db_con4);
				gPlayerData[playerid][mBroadCastMessages] = strval(string);
				// mysql_fetch_field_row(string, "IsLogged", db_con4);
				// gPlayerData[playerid][pIsLogged] = strval(string);
			}
			
			// samp_users_other2
			{
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
				mysql_fetch_field_row(string, "Tech", db_con4);
				gPlayerData[playerid][pTech] = strval(string);
				mysql_fetch_field_row(string, "Law", db_con4);
				gPlayerData[playerid][pLaw] = strval(string);
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
				mysql_fetch_field_row(string, "PktTech", db_con4);
				gPlayerData[playerid][pPktTech] = strval(string);
				mysql_fetch_field_row(string, "PktLaw", db_con4);
				gPlayerData[playerid][pPktLaw] = strval(string);
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
				mysql_fetch_field_row(string, "HighSchool", db_con4);
				gPlayerData[playerid][pHighSchool] = strval(string);
				mysql_fetch_field_row(string, "SchoolCooldown", db_con4);
				gPlayerData[playerid][pSchoolCooldown] = strval(string);
				mysql_fetch_field_row(string, "MountsPasses", db_con4);
				gPlayerData[playerid][pMountsPasses] = strval(string);
			}
			
			format(string, sizeof(string), "SELECT HIGH_PRIORITY * FROM `mybb_banned` WHERE `uid` = '%d'", gPlayerData[playerid][pAccountOwnerID]);
			wp_mysql_query(string, CHECK_ACCOUNT_STATUS_PAYDAY, playerid, db_con2);
			
			
		}
		case CHECK_ACCOUNT_STATUS:
		{
			mysql_store_result(db_con2);
			
			if(mysql_num_rows(db_con2) != 0)
			{
				KickPlayer(playerid, "System", "Twoje konto na forum zosta³o zbanowane");
				
				return 1;
			}
			else
			{
				if(playerid < CUSTOM_MAX_PLAYERS)
				{
					GetPlayerIp(playerid, string, sizeof(string));
					format(string, sizeof(string), "%s sign in with $%d in character cash and $%d in bank cash, IP is %s", gPlayerData[playerid][pName], gPlayerData[playerid][pCash], gPlayerData[playerid][pBank], string);
					LogginDataLog(string);

					if(gPlayerData[playerid][pSetToDelete])
					{
						KickPlayer(playerid,"System","Konto zosta³o przeznaczone do usuniêcia i nie mo¿na siê na nie zalogowaæ");
					}
					
					if(gPlayerData[playerid][pIsOnVacation])
					{
						KickPlayer(playerid,"System","Konto posiada aktywny urlop - deaktywuj urlop przed zalogowaniem siê do gry");
					}
					
					if(gPlayerData[playerid][pBanned])
					{
						KickPlayer(playerid,"System","Konto zbanowane");
					}

					if(gPlayerData[playerid][pCharacterDeath] == 1)
					{
						KickPlayer(playerid,"System","Postaæ martwa");
					}
					
					PosHackCheckTime[playerid] = 5;
					
					ClearScreen(playerid);
					
					PreSpawn(playerid);
					
					// Show debug data
					// Eating
					#if defined DEBUG2
						EatText[playerid] = TextDrawCreate(10.0, 285.0, " ");
						TextDrawLetterSize(EatText[playerid], 0.15, 0.9);
						TextDrawTextSize(EatText[playerid], 190.0, 100.0);
						TextDrawShowForPlayer(playerid, EatText[playerid]);
					#endif

					return 1;
				}
				else
				{
					format(string, sizeof(string), "[PAYDAY:] Player %s start in character cash: $%d, in bank cash: $%d", gPlayerData[playerid][pName], gPlayerData[playerid][pCash], gPlayerData[playerid][pBank]);
					PayDayLog(string);
					
					if(gPlayerData[playerid][pIsLogged])
					{
						format(string, sizeof(string), "[PAYDAY:] Player is already logged during payday");
						PayDayLog(string);
					}
					
					if(gPlayerData[playerid][pIsOnVacation] > 0)
					{
						gPlayerData[playerid][pIsOnVacation]++;
						SavePlayerData(playerid, "IsOnVacation");
					}
					
					if(gPlayerData[playerid][pSchoolCooldown] > 0)
					{
						gPlayerData[playerid][pSchoolCooldown] = 0;
						SavePlayerData(playerid, "SchoolCooldown");
					}
					
					if((gPlayerData[playerid][pPlayingHours] <= 50 && gPlayerData[playerid][pLastLogged] >= 10) ||
						(gPlayerData[playerid][pPlayingHours] > 50 && gPlayerData[playerid][pLastLogged] >= 20) ||
						//strlen(gPlayerData[playerid][pName]) <= 3 || gPlayerData[playerid][pAdmin] > 0 || gPlayerData[playerid][pSetToDelete] || gPlayerData[playerid][pIsOnVacation] > 0)
						strlen(gPlayerData[playerid][pName]) <= 3 || gPlayerData[playerid][pAdmin] > 4 || gPlayerData[playerid][pSetToDelete] || gPlayerData[playerid][pIsOnVacation] > 0)
					{
						gPlayerData[playerid][pLastLogged]++;
						SavePlayerData(playerid, "LastLogged");
						
						gPlayerData[playerid][pSchoolCooldown] = 0;
						SavePlayerData(playerid, "SchoolCooldown");
						
						format(string, sizeof(string), "[PAYDAY:] Player name = %s - payday is off (not logged for %d day(s)), is administrator or is set to delete", gPlayerData[playerid][pName], gPlayerData[playerid][pLastLogged] );
						PayDayLog(string);

						/*
						* Remove unproper/unused account
						*/
						if(!gPlayerData[playerid][pBanned] && !gPlayerData[playerid][pAdmin] && !IsPlayerVip(playerid) && (gPlayerData[playerid][pLastLogged] >= 60 || strlen(gPlayerData[playerid][pName]) <= 3 || 
							strfind(gPlayerData[playerid][pName], "_", true) == -1 || strfind(gPlayerData[playerid][pName], "[", true) > 0 || strfind(gPlayerData[playerid][pName], "]", true) > 0) || gPlayerData[playerid][pSetToDelete] || gPlayerData[playerid][pIsOnVacation] > 90)
						{
							format(string, sizeof(string), "DELETE FROM `samp_users` WHERE `PlayerName` = '%s' ", gPlayerData[playerid][pName]);
							wp_mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
							format(string, sizeof(string), "DELETE FROM `samp_users_items` WHERE `PlayerName` = '%s' ", gPlayerData[playerid][pName]);
							wp_mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
							format(string, sizeof(string), "DELETE FROM `samp_users_items2` WHERE `PlayerName` = '%s' ", gPlayerData[playerid][pName]);
							wp_mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
							format(string, sizeof(string), "DELETE FROM `samp_users_items3` WHERE `PlayerName` = '%s' ", gPlayerData[playerid][pName]);
							wp_mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
							format(string, sizeof(string), "DELETE FROM `samp_users_jobs` WHERE `PlayerName` = '%s' ", gPlayerData[playerid][pName]);
							wp_mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
							format(string, sizeof(string), "DELETE FROM `samp_users_keys` WHERE `PlayerName` = '%s' ", gPlayerData[playerid][pName]);
							wp_mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
							format(string, sizeof(string), "DELETE FROM `samp_users_lic` WHERE `PlayerName` = '%s' ", gPlayerData[playerid][pName]);
							wp_mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
							format(string, sizeof(string), "DELETE FROM `samp_users_notes` WHERE `PlayerName` = '%s' ", gPlayerData[playerid][pName]);
							wp_mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
							format(string, sizeof(string), "DELETE FROM `samp_users_vip` WHERE `PlayerName` = '%s' ", gPlayerData[playerid][pName]);
							wp_mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
							format(string, sizeof(string), "DELETE FROM `samp_users_other` WHERE `PlayerName` = '%s' ", gPlayerData[playerid][pName]);
							wp_mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
							format(string, sizeof(string), "DELETE FROM `samp_users_other2` WHERE `PlayerName` = '%s' ", gPlayerData[playerid][pName]);
							wp_mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
							format(string, sizeof(string), "DELETE FROM `samp_users_fueled` WHERE `PlayerName` = '%s' ", gPlayerData[playerid][pName]);
							wp_mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
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
									ResetBizData(i);
							}
							format(string, sizeof(string), "[PAYDAY:] Player name = %s - account removed", gPlayerData[playerid][pName], gPlayerData[playerid][pLastLogged]);
							PayDayLog(string);
						}

						/*
						* Select next player in DB
						*/
						gPayDayLoop++;
						
						format(string, sizeof(string), "[PAYDAY:] gPayDayLoop = %d, gPayDayCount = %d", gPayDayLoop, gPayDayCount );
						PayDayLog(string);
						
						if(gPayDayLoop <= gPayDayCount)
						{
							format(string, sizeof(string), "SELECT");
							strcat(string, " `samp_users`.*");
							strcat(string, ", `samp_users_items`.*");
							strcat(string, ", `samp_users_items2`.*");
							strcat(string, ", `samp_users_items3`.*");
							strcat(string, ", `samp_users_jobs`.*");
							strcat(string, ", `samp_users_lic`.*");
							strcat(string, ", `samp_users_notes`.*");
							strcat(string, ", `samp_users_other`.*");
							strcat(string, ", `samp_users_other2`.*");
							strcat(string, ", `samp_users_vip`.*");
							strcat(string, " FROM `samp_users`");
							strcat(string, " JOIN `samp_users_items` ON `samp_users_items`.PlayerName = `samp_users`.PlayerName");
							strcat(string, " JOIN `samp_users_items2` ON `samp_users_items2`.PlayerName = `samp_users`.PlayerName");
							strcat(string, " JOIN `samp_users_items3` ON `samp_users_items3`.PlayerName = `samp_users`.PlayerName");
							strcat(string, " JOIN `samp_users_jobs` ON `samp_users_jobs`.PlayerName = `samp_users`.PlayerName");
							strcat(string, " JOIN `samp_users_lic` ON `samp_users_lic`.PlayerName = `samp_users`.PlayerName");
							strcat(string, " JOIN `samp_users_notes` ON `samp_users_notes`.PlayerName = `samp_users`.PlayerName");
							strcat(string, " JOIN `samp_users_other` ON `samp_users_other`.PlayerName = `samp_users`.PlayerName");
							strcat(string, " JOIN `samp_users_other2` ON `samp_users_other2`.PlayerName = `samp_users`.PlayerName");
							strcat(string, " JOIN `samp_users_vip` ON `samp_users_vip`.PlayerName = `samp_users`.PlayerName");
							format(string, sizeof(string), "%s WHERE `samp_users`.Banned = '0' LIMIT %d , 1", string, gPayDayLoop);
						}
						
						return 1;
					}

					/*
					* Remove from public faction if not present for 5 days
					*/
					if(gPlayerData[playerid][pLastLogged] >= 5 && gPlayerData[playerid][pRank] == 1 && gPlayerData[playerid][pFaction] >= 0 && gPlayerData[playerid][pFaction] < 9 && gPlayerData[playerid][pFaction] != 6 && gPlayerData[playerid][pFaction] != 7 && gPlayerData[playerid][pFaction] != 8)
					{
						// TODO: dopisac tutaj czyszczenie frakcje
						gPlayerData[playerid][pFaction] = 255;
						gPlayerData[playerid][pRank] = 9;
						SavePlayerData(playerid, "Faction");
						SavePlayerData(playerid, "Rank");
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
					PHaveItemEx(playerid, 3, 6, slot);
					
					for(new i = 0; i < MAX_PLAYER_ITEM_SLOT; i++)
					{
						if(slot[i])
						{
							if(SlotParam1(playerid, i+1) > 0)
							{
								SetPSlotParam1(playerid, i+1, SlotParam1(playerid, i+1)-1);
							}
							
							if(SlotParam2(playerid, i+1) > 0)
							{
								SetPSlotParam2(playerid, i+1, SlotParam2(playerid, i+1)-1);
							}
							
							if(SlotParam3(playerid, i+1) > 0)
							{
								SetPSlotParam3(playerid, i+1, SlotParam3(playerid, i+1)-1);
							}
						}
					}
					
					/*
					* Credit repayment
					*/
					if(gPlayerData[playerid][mCreditValue] > 0 && gPlayerData[playerid][pAdmin] != 5)
					{
						format(string, sizeof(string), "[PAYDAY:] Player name = %s, credit repayment, Bank = $%d - $%d",
							gPlayerData[playerid][pName], gPlayerData[playerid][pBank], gPlayerData[playerid][mCreditRepayment]);
						PayDayLog(string);
						
						gPlayerData[playerid][pBank] -= gPlayerData[playerid][mCreditRepayment];
						gPlayerData[playerid][mCreditPayed] += gPlayerData[playerid][mCreditRepayment];						
						gPlayerData[playerid][pBankLoose] += gPlayerData[playerid][mCreditRepayment];
						
						DynamicFactions[FACTIONID_GOVERNMENT][fBank] += gPlayerData[playerid][mCreditRepayment];
						
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
					// TODO: WA¯NE ! UWZGLÊDNIÆ WSZYSTKIE SLOTY WSZEDZIE !
					PHaveItemEx(playerid, 3, 19, slot);
					for(new i = 1; i <= MAX_PLAYER_ITEM_SLOT; i++)
					{
						if(slot[i-1])
						{
							if(SlotParam3(playerid, i) > 0)
							{
								format(string, sizeof(string), "[PAYDAY:] Player name = %s, OC pay, Bank = $%d - $%d",
									gPlayerData[playerid][pName], gPlayerData[playerid][pBank], 4);
								PayDayLog(string);
								
								gPlayerData[playerid][pBank] -= 4;
								gPlayerData[CUSTOM_MAX_PLAYERS][pBankLoose] += 4;
								
								DynamicFactions[FACTIONID_GOVERNMENT][fBank] += 4;
							}
							if(SlotParam4(playerid, i) > 0)
							{
								format(string, sizeof(string), "[PAYDAY:] Player name = %s, AC pay, Bank = $%d - $%d",
									gPlayerData[playerid][pName], gPlayerData[playerid][pBank], 6);
								PayDayLog(string);
								
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
											gPlayerData[playerid][pName], gPlayerData[playerid][pBank], PayRank[n][Rank1], gPlayerData[playerid][pFaction], DynamicFactions[gPlayerData[playerid][pFaction]][fBank], PayRank[n][Rank1]);
										
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
											gPlayerData[playerid][pName], gPlayerData[playerid][pBank], PayRank[n][Rank3], gPlayerData[playerid][pFaction], DynamicFactions[gPlayerData[playerid][pFaction]][fBank], PayRank[n][Rank3]);
										
										gPlayerData[playerid][pBank] += PayRank[n][Rank3];
										gPlayerData[playerid][pBankIncome] += PayRank[n][Rank3];
										
										DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank3];
									}
									case 4:
									{
										format(string, sizeof(string), "[PAYDAY:] Player name = %s, rank 4, Bank = %d + %d, Faction id = %d, Bank = %d - %d",
											gPlayerData[playerid][pName], gPlayerData[playerid][pBank], PayRank[n][Rank4], gPlayerData[playerid][pFaction], DynamicFactions[gPlayerData[playerid][pFaction]][fBank], PayRank[n][Rank4]);
										
										gPlayerData[playerid][pBank] += PayRank[n][Rank4];
										gPlayerData[playerid][pBankIncome] += PayRank[n][Rank4];
										
										DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank4];
									}
									case 5:
									{
										format(string, sizeof(string), "[PAYDAY:] Player name = %s, rank 5, Bank = %d + %d, Faction id = %d, Bank = %d - %d",
											gPlayerData[playerid][pName], gPlayerData[playerid][pBank], PayRank[n][Rank5], gPlayerData[playerid][pFaction], DynamicFactions[gPlayerData[playerid][pFaction]][fBank], PayRank[n][Rank5]);
										
										gPlayerData[playerid][pBank] += PayRank[n][Rank5];
										gPlayerData[playerid][pBankIncome] += PayRank[n][Rank5];
										
										DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank5];
									}
									case 6:
									{
										format(string, sizeof(string), "[PAYDAY:] Player name = %s, rank 6, Bank = %d + %d, Faction id = %d, Bank = %d - %d",
											gPlayerData[playerid][pName], gPlayerData[playerid][pBank], PayRank[n][Rank6], gPlayerData[playerid][pFaction], DynamicFactions[gPlayerData[playerid][pFaction]][fBank], PayRank[n][Rank6]);
										
										gPlayerData[playerid][pBank] += PayRank[n][Rank6];
										gPlayerData[playerid][pBankIncome] += PayRank[n][Rank6];
										
										DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank6];
									}
									case 7:
									{
										format(string, sizeof(string), "[PAYDAY:] Player name = %s, rank 7, Bank = %d + %d, Faction id = %d, Bank = %d - %d",
											gPlayerData[playerid][pName], gPlayerData[playerid][pBank], PayRank[n][Rank7], gPlayerData[playerid][pFaction], DynamicFactions[gPlayerData[playerid][pFaction]][fBank], PayRank[n][Rank7]);
										
										gPlayerData[playerid][pBank] += PayRank[n][Rank7];
										gPlayerData[playerid][pBankIncome] += PayRank[n][Rank7];
										
										DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank7];
									}
									case 8:
									{
										format(string, sizeof(string), "[PAYDAY:] Player name = %s, rank 8, Bank = %d + %d, Faction id = %d, Bank = %d - %d",
											gPlayerData[playerid][pName], gPlayerData[playerid][pBank], PayRank[n][Rank8], gPlayerData[playerid][pFaction], DynamicFactions[gPlayerData[playerid][pFaction]][fBank], PayRank[n][Rank8]);
										
										gPlayerData[playerid][pBank] += PayRank[n][Rank8];
										gPlayerData[playerid][pBankIncome] += PayRank[n][Rank8];
										
										DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank8];
									}
									case 9:
									{
										format(string, sizeof(string), "[PAYDAY:] Player name = %s, rank 9, Bank = %d + %d, Faction id = %d, Bank = %d - %d",
											gPlayerData[playerid][pName], gPlayerData[playerid][pBank], PayRank[n][Rank9], gPlayerData[playerid][pFaction], DynamicFactions[gPlayerData[playerid][pFaction]][fBank], PayRank[n][Rank9]);
										
										gPlayerData[playerid][pBank] += PayRank[n][Rank9];
										gPlayerData[playerid][pBankIncome] += PayRank[n][Rank9];
										
										DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank9];
									}
									case 10:
									{
										format(string, sizeof(string), "[PAYDAY:] Player name = %s, rank 10, Bank = %d + %d, Faction id = %d, Bank = %d - %d",
											gPlayerData[playerid][pName], gPlayerData[playerid][pBank], PayRank[n][Rank10], gPlayerData[playerid][pFaction], DynamicFactions[gPlayerData[playerid][pFaction]][fBank], PayRank[n][Rank10]);
										
										gPlayerData[playerid][pBank] += PayRank[n][Rank10];
										gPlayerData[playerid][pBankIncome] += PayRank[n][Rank10];
										
										DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank10];
									}
								}
								
								PayDayLog(string);
								SaveFData(gPlayerData[playerid][pFaction], "Bank");
								
								break;
							}
						}
					}
					
					/*
					* Give player faction payment and other payment
					*/
					if(gPlayerData[CUSTOM_MAX_PLAYERS][pFaction2] != 255 && gPlayerData[playerid][pLastLogged] == 0)
					{
						for(new n = 0; n < sizeof(DynamicFactions); n++)
						{
							if(PayRank[n][FactionID] == gPlayerData[CUSTOM_MAX_PLAYERS][pFaction2])
							{
								switch(gPlayerData[playerid][pRank2])
								{
									case 1:
									{
										format(string, sizeof(string), "[PAYDAY:] Player name = %s, rank 1, Bank = %d + %d, Faction id = %d, Bank = %d - %d",
											gPlayerData[playerid][pName], gPlayerData[playerid][pBank], PayRank[n][Rank1], gPlayerData[playerid][pFaction2], DynamicFactions[gPlayerData[playerid][pFaction2]][fBank], PayRank[n][Rank1]);
									
										gPlayerData[playerid][pBank] += PayRank[n][Rank1];
										gPlayerData[playerid][pBankIncome] += PayRank[n][Rank1];
										
										DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank1];
									}
									case 2:
									{
										format(string, sizeof(string), "[PAYDAY:] Player name = %s, rank 2, Bank = %d + %d, Faction id = %d, Bank = %d - %d",
											gPlayerData[playerid][pName], gPlayerData[playerid][pBank], PayRank[n][Rank2], gPlayerData[playerid][pFaction2], DynamicFactions[gPlayerData[playerid][pFaction2]][fBank], PayRank[n][Rank2]);
										
										gPlayerData[playerid][pBank] += PayRank[n][Rank2];
										gPlayerData[playerid][pBankIncome] += PayRank[n][Rank2];
										
										DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank2];
									}
									case 3:
									{
										format(string, sizeof(string), "[PAYDAY:] Player name = %s, rank 3, Bank = %d + %d, Faction id = %d, Bank = %d - %d",
											gPlayerData[playerid][pName], gPlayerData[playerid][pBank], PayRank[n][Rank3], gPlayerData[playerid][pFaction2], DynamicFactions[gPlayerData[playerid][pFaction2]][fBank], PayRank[n][Rank3]);
										
										gPlayerData[playerid][pBank] += PayRank[n][Rank3];
										gPlayerData[playerid][pBankIncome] += PayRank[n][Rank3];
										
										DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank3];
									}
									case 4:
									{
										format(string, sizeof(string), "[PAYDAY:] Player name = %s, rank 4, Bank = %d + %d, Faction id = %d, Bank = %d - %d",
											gPlayerData[playerid][pName], gPlayerData[playerid][pBank], PayRank[n][Rank4], gPlayerData[playerid][pFaction2], DynamicFactions[gPlayerData[playerid][pFaction2]][fBank], PayRank[n][Rank4]);
										
										gPlayerData[playerid][pBank] += PayRank[n][Rank4];
										gPlayerData[playerid][pBankIncome] += PayRank[n][Rank4];
										
										DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank4];
									}
									case 5:
									{
										format(string, sizeof(string), "[PAYDAY:] Player name = %s, rank 5, Bank = %d + %d, Faction id = %d, Bank = %d - %d",
											gPlayerData[playerid][pName], gPlayerData[playerid][pBank], PayRank[n][Rank5], gPlayerData[playerid][pFaction2], DynamicFactions[gPlayerData[playerid][pFaction2]][fBank], PayRank[n][Rank5]);
										
										gPlayerData[playerid][pBank] += PayRank[n][Rank5];
										gPlayerData[playerid][pBankIncome] += PayRank[n][Rank5];
										
										DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank5];
									}
									case 6:
									{
										format(string, sizeof(string), "[PAYDAY:] Player name = %s, rank 6, Bank = %d + %d, Faction id = %d, Bank = %d - %d",
											gPlayerData[playerid][pName], gPlayerData[playerid][pBank], PayRank[n][Rank6], gPlayerData[playerid][pFaction2], DynamicFactions[gPlayerData[playerid][pFaction2]][fBank], PayRank[n][Rank6]);
										
										gPlayerData[playerid][pBank] += PayRank[n][Rank6];
										gPlayerData[playerid][pBankIncome] += PayRank[n][Rank6];
										
										DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank6];
									}
									case 7:
									{
										format(string, sizeof(string), "[PAYDAY:] Player name = %s, rank 7, Bank = %d + %d, Faction id = %d, Bank = %d - %d",
											gPlayerData[playerid][pName], gPlayerData[playerid][pBank], PayRank[n][Rank7], gPlayerData[playerid][pFaction2], DynamicFactions[gPlayerData[playerid][pFaction2]][fBank], PayRank[n][Rank7]);
										
										gPlayerData[playerid][pBank] += PayRank[n][Rank7];
										gPlayerData[playerid][pBankIncome] += PayRank[n][Rank7];
										
										DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank7];
									}
									case 8:
									{
										format(string, sizeof(string), "[PAYDAY:] Player name = %s, rank 8, Bank = %d + %d, Faction id = %d, Bank = %d - %d",
											gPlayerData[playerid][pName], gPlayerData[playerid][pBank], PayRank[n][Rank8], gPlayerData[playerid][pFaction2], DynamicFactions[gPlayerData[playerid][pFaction2]][fBank], PayRank[n][Rank8]);
										
										gPlayerData[playerid][pBank] += PayRank[n][Rank8];
										gPlayerData[playerid][pBankIncome] += PayRank[n][Rank8];
										
										DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank8];
									}
									case 9:
									{
										format(string, sizeof(string), "[PAYDAY:] Player name = %s, rank 9, Bank = %d + %d, Faction id = %d, Bank = %d - %d",
											gPlayerData[playerid][pName], gPlayerData[playerid][pBank], PayRank[n][Rank9], gPlayerData[playerid][pFaction2], DynamicFactions[gPlayerData[playerid][pFaction2]][fBank], PayRank[n][Rank9]);
										
										gPlayerData[playerid][pBank] += PayRank[n][Rank9];
										gPlayerData[playerid][pBankIncome] += PayRank[n][Rank9];
										
										DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank9];
									}
									case 10:
									{
										format(string, sizeof(string), "[PAYDAY:] Player name = %s, rank 10, Bank = %d + %d, Faction id = %d, Bank = %d - %d",
											gPlayerData[playerid][pName], gPlayerData[playerid][pBank], PayRank[n][Rank10], gPlayerData[playerid][pFaction2], DynamicFactions[gPlayerData[playerid][pFaction2]][fBank], PayRank[n][Rank10]);
										
										gPlayerData[playerid][pBank] += PayRank[n][Rank10];
										gPlayerData[playerid][pBankIncome] += PayRank[n][Rank10];
										
										DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank10];
									}
								}
								
								PayDayLog(string);
								SaveFData( gPlayerData[playerid][pFaction2], "Bank" );
								
								break;
							}
						}
					}
					
					if(gPlayerData[playerid][pJob] == 0 && gPlayerData[playerid][pFaction] == 255)
					{
						format(string, sizeof(string), "[PAYDAY:] Player name = %s, Bank = %d + %d", gPlayerData[playerid][pName], gPlayerData[playerid][pBank], Zasilek);
						PayDayLog(string);
						
						gPlayerData[playerid][pBank] += Zasilek;
						gPlayerData[playerid][pBankIncome] += Zasilek;
						
						DynamicFactions[FACTIONID_GOVERNMENT][fBank] -= Zasilek;
					}

					/*
					* Pay taxes, costs, tickets, etc.
					*/
					format(string, sizeof(string), "[PAYDAY:] PlayerName = %s, Bank = %d - %d, SOURCE = Radio tax", gPlayerData[playerid][pName], gPlayerData[playerid][pBank], DynamicTaxes[RadioTax]);
					PayDayLog(string);
					
					gPlayerData[playerid][pBank] -= DynamicTaxes[RadioTax];
					gPlayerData[playerid][pBankLoose] += DynamicTaxes[RadioTax];
					
					DynamicFactions[FACTIONID_GOVERNMENT][fBank] += DynamicTaxes[RadioTax];
					
					if((gPlayerData[playerid][pCash] + gPlayerData[playerid][pBank]) >= DynamicTaxes[TheRich])
					{
						format(string, sizeof(string), "[PAYDAY:] PlayerName = %s, Bank = %d - %d, SOURCE = taxes (the rich)", gPlayerData[playerid][pName], gPlayerData[playerid][pBank], floatround(DynamicTaxes[RichTax] * (gPlayerData[playerid][pBank]+gPlayerData[playerid][pCash]), floatround_round));
						PayDayLog(string);
						
						gPlayerData[playerid][pBank] -= floatround(DynamicTaxes[RichTax] * (gPlayerData[playerid][pBank]+gPlayerData[playerid][pCash]), floatround_round);
						gPlayerData[playerid][pBankLoose] += floatround(DynamicTaxes[RichTax] * (gPlayerData[playerid][pBank]+gPlayerData[playerid][pCash]), floatround_round);
						
						DynamicFactions[FACTIONID_GOVERNMENT][fBank] += floatround(DynamicTaxes[RichTax] * (gPlayerData[playerid][pBank]+gPlayerData[playerid][pCash]), floatround_round);
					}
					
					if(gPlayerData[playerid][pCost] > 0)
					{
						format(string, sizeof(string), "[PAYDAY:] PlayerName = %s, Bank = %d - %d, SOURCE = costs",
							gPlayerData[playerid][pName], gPlayerData[playerid][pBank], gPlayerData[playerid][pCost]);
						PayDayLog(string);
						
						gPlayerData[playerid][pBank] -= gPlayerData[playerid][pCost];
						gPlayerData[playerid][pBankLoose] += gPlayerData[playerid][pCost];						
						
						DynamicFactions[FACTIONID_GOVERNMENT][fBank] += gPlayerData[playerid][pCost];
						
						gPlayerData[playerid][pCost] = 0;
						SavePlayerData(playerid, "Cost");
					}
					
					if(gPlayerData[playerid][pTicket] > 0)
					{
						format(string, sizeof(string), "[PAYDAY:] PlayerName = %s, Bank = %d - %d, SOURCE = ticket",
							gPlayerData[playerid][pName], gPlayerData[playerid][pBank], gPlayerData[playerid][pTicket]);
						PayDayLog(string);
						
						gPlayerData[playerid][pBank] -= gPlayerData[playerid][pTicket];
						gPlayerData[playerid][pBankLoose] += gPlayerData[playerid][pTicket];
						
						DynamicFactions[FACTIONID_POLICE][fBank] += gPlayerData[playerid][pTicket];
						SaveFData(FACTIONID_POLICE, "Bank");
						
						gPlayerData[playerid][pTicket] = 0;
						SavePlayerData( playerid, "Ticket" );
					}
					
					for(new i = 0; i < sizeof(Houses); i++)
					{
						if(strcmp(gPlayerData[playerid][pName], Houses[i][HRenter], false) == 0 && strlen(Houses[i][HRenter]) > 0)
						{
							if(gPlayerData[playerid][pBank] < 0)
							{
								format(string, sizeof(string), "[PAYDAY:] PlayerName = %s, House rent deleted, House ID: %d",
									gPlayerData[playerid][pName], i);
								PayDayLog(string);
								
								strmid(Houses[i][HRenter], "Brak", 0, MAX_PLAYER_NAME, 255);
								SaveHouseData(i, "Renter");
							}
							else
							{
								format(string, sizeof(string), "[PAYDAY:] PlayerName = %s, Bank = %d - %d, SOURCE = house rent, House ID: %d", 
									gPlayerData[playerid][pName], gPlayerData[playerid][pBank], Houses[i][RentCost], i);
								PayDayLog(string);
								
								gPlayerData[playerid][pBank] -= Houses[i][RentCost];
								gPlayerData[playerid][pBankLoose] += Houses[i][RentCost];
								
								UpdatePlayerDataByName(Houses[i][Owner], "Bank", Houses[i][RentCost]);
							}
						}
					}

					/*
					* Is player on debt ?
					*/
					if(gPlayerData[playerid][pBank] < -5000)
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
								gVehData[i][VConfiscated] = 1;
								SaveVehData(i, "Closed");
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
							if(strcmp(gVehData[i][Owner], gPlayerData[playerid][pName], true) == 0 && strlen(gVehData[i][Owner]) > 0)
							{
								format(string, sizeof(string), "[PAYDAY:] PlayerName = %s, Veh ID: %d, deconfiscated", gPlayerData[playerid][pName], i);
								PayDayLog(string);

								new enginedyn,lights,alarm,doors,bonnet,boot,objective;
								GetVehicleParamsEx(i+1,enginedyn,lights,alarm,doors,bonnet,boot,objective);
								SetVehicleParamsEx(i+1,enginedyn,lights,alarm,0,bonnet,boot,objective);

								gVehData[i][Closed] = 0;
								gVehData[i][VConfiscated] = 0;
								SaveVehData(i, "Closed");
								SaveVehData(i, "Confiscated");
							}
						}
					}

					/*
					* Calculate and update player RP score
					*/
					gPlayerData[playerid][pScore] = (gPlayerData[playerid][pRPCount] * 2);
					SavePlayerData(playerid, "Score");

					/*
					* VIP reduce
					*/
					if(gVipReduceOn)
					{
						if(gPlayerData[playerid][pVipAFKT] > 0)
						{
							format(string, sizeof(string), "[PAYDAY:] PlayerName = %s, VipAFKT: %d -1", gPlayerData[playerid][pName], gPlayerData[playerid][pVipAFKT]);
							PayDayLog(string);
							
							gPlayerData[playerid][pVipAFKT]--;
							SavePlayerData(playerid, "VipAFKT");
						}
						if(gPlayerData[playerid][pVipExpT] > 0)
						{
							format(string, sizeof(string), "[PAYDAY:] PlayerName = %s, VipExpT: %d -1", gPlayerData[playerid][pName], gPlayerData[playerid][pVipExpT]);
							PayDayLog(string);
							
							gPlayerData[playerid][pVipExpT]--;
							SavePlayerData(playerid, "VipExpT");
						}
						if(gPlayerData[playerid][pVipItem] > 0)
						{
							format(string, sizeof(string), "[PAYDAY:] PlayerName = %s, VipItem: %d -1", gPlayerData[playerid][pName], gPlayerData[playerid][pVipItem]);
							PayDayLog(string);
								
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
							gPlayerData[playerid][pWarnCooldown] = WARN_COOLDOWN;
							SavePlayerData(playerid, "Warnings");
							SavePlayerData(playerid, "WarnCooldown");
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

					format(string, sizeof(string), "[PAYDAY:] Player %s end in character cash: $%d, in bank cash: $%d", gPlayerData[playerid][pName], gPlayerData[playerid][pCash], gPlayerData[playerid][pBank]);
					PayDayLog(string);

					SaveFData(FACTIONID_GOVERNMENT, "Bank");

					/*
					* Select next player in DB
					*/
					gPayDayLoop++;
					format(string, sizeof(string), "[PAYDAY:] gPayDayLoop = %d, gPayDayCount = %d", gPayDayLoop, gPayDayCount);
					PayDayLog(string);
					if(gPayDayLoop <= gPayDayCount)
					{
						format(string, sizeof(string), "SELECT");
						strcat(string, " `samp_users`.*");
						strcat(string, ", `samp_users_items`.*");
						strcat(string, ", `samp_users_items2`.*");
						strcat(string, ", `samp_users_items3`.*");
						strcat(string, ", `samp_users_jobs`.*");
						strcat(string, ", `samp_users_lic`.*");
						strcat(string, ", `samp_users_notes`.*");
						strcat(string, ", `samp_users_other`.*");
						strcat(string, ", `samp_users_other2`.*");
						strcat(string, ", `samp_users_vip`.*");
						strcat(string, " FROM `samp_users`");
						strcat(string, " JOIN `samp_users_items` ON `samp_users_items`.PlayerName = `samp_users`.PlayerName");
						strcat(string, " JOIN `samp_users_items2` ON `samp_users_items2`.PlayerName = `samp_users`.PlayerName");
						strcat(string, " JOIN `samp_users_items3` ON `samp_users_items3`.PlayerName = `samp_users`.PlayerName");
						strcat(string, " JOIN `samp_users_jobs` ON `samp_users_jobs`.PlayerName = `samp_users`.PlayerName");
						strcat(string, " JOIN `samp_users_lic` ON `samp_users_lic`.PlayerName = `samp_users`.PlayerName");
						strcat(string, " JOIN `samp_users_notes` ON `samp_users_notes`.PlayerName = `samp_users`.PlayerName");
						strcat(string, " JOIN `samp_users_other` ON `samp_users_other`.PlayerName = `samp_users`.PlayerName");
						strcat(string, " JOIN `samp_users_other2` ON `samp_users_other2`.PlayerName = `samp_users`.PlayerName");
						strcat(string, " JOIN `samp_users_vip` ON `samp_users_vip`.PlayerName = `samp_users`.PlayerName");
						format(string, sizeof(string), "%s WHERE `samp_users`.Banned = '0' LIMIT %d , 1", string, gPayDayLoop);
					}
				}
				
				return 1;
			}
		}
		case CHECK_ACCOUNT_STATUS_PAYDAY:
		{
			mysql_store_result(db_con2);
			
			if(mysql_num_rows(db_con2) != 0)
			{
				KickPlayer(playerid, "System", "Twoje konto na forum zosta³o zbanowane");
				
				return 1;
			}
			else
			{
				format(string, sizeof(string), "[PAYDAY:] Player %s start in character cash: $%d, in bank cash: $%d", gPlayerData[playerid][pName], gPlayerData[playerid][pCash], gPlayerData[playerid][pBank]);
				PayDayLog(string);
				
				if(gPlayerData[playerid][pIsLogged])
				{
					format(string, sizeof(string), "[PAYDAY:] Player is already logged during payday");
					PayDayLog(string);
				}
				
				if(gPlayerData[playerid][pIsOnVacation] > 0)
				{
					gPlayerData[playerid][pIsOnVacation]++;
					SavePlayerData(playerid, "IsOnVacation");
				}
				
				if(gPlayerData[playerid][pSchoolCooldown] > 0)
				{
					gPlayerData[playerid][pSchoolCooldown] = 0;
					SavePlayerData(playerid, "SchoolCooldown");
				}
				
				if((gPlayerData[playerid][pPlayingHours] <= 50 && gPlayerData[playerid][pLastLogged] >= 10) ||
					(gPlayerData[playerid][pPlayingHours] > 50 && gPlayerData[playerid][pLastLogged] >= 20) ||
					//strlen(gPlayerData[playerid][pName]) <= 3 || gPlayerData[playerid][pAdmin] > 0 || gPlayerData[playerid][pSetToDelete] || gPlayerData[playerid][pIsOnVacation] > 0)
					strlen(gPlayerData[playerid][pName]) <= 3 || gPlayerData[playerid][pAdmin] > 4 || gPlayerData[playerid][pSetToDelete] || gPlayerData[playerid][pIsOnVacation] > 0)
				{
					gPlayerData[playerid][pLastLogged]++;
					SavePlayerData(playerid, "LastLogged");
					
					gPlayerData[playerid][pSchoolCooldown] = 0;
					SavePlayerData(playerid, "SchoolCooldown");
					
					format(string, sizeof(string), "[PAYDAY:] Player name = %s - payday is off (not logged for %d day(s)), is administrator or is set to delete", gPlayerData[playerid][pName], gPlayerData[playerid][pLastLogged] );
					PayDayLog(string);

					/*
					* Remove unproper/unused account
					*/
					if(!gPlayerData[playerid][pBanned] && !gPlayerData[playerid][pAdmin] && !IsPlayerVip(playerid) && (gPlayerData[playerid][pLastLogged] >= 60 || strlen(gPlayerData[playerid][pName]) <= 3 || 
						strfind(gPlayerData[playerid][pName], "_", true) == -1 || strfind(gPlayerData[playerid][pName], "[", true) > 0 || strfind(gPlayerData[playerid][pName], "]", true) > 0) || gPlayerData[playerid][pSetToDelete] || gPlayerData[playerid][pIsOnVacation] > 90)
					{
						format(string, sizeof(string), "DELETE FROM `samp_users` WHERE `PlayerName` = '%s' ", gPlayerData[playerid][pName]);
						wp_mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
						format(string, sizeof(string), "DELETE FROM `samp_users_items` WHERE `PlayerName` = '%s' ", gPlayerData[playerid][pName]);
						wp_mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
						format(string, sizeof(string), "DELETE FROM `samp_users_items2` WHERE `PlayerName` = '%s' ", gPlayerData[playerid][pName]);
						wp_mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
						format(string, sizeof(string), "DELETE FROM `samp_users_items3` WHERE `PlayerName` = '%s' ", gPlayerData[playerid][pName]);
						wp_mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
						format(string, sizeof(string), "DELETE FROM `samp_users_jobs` WHERE `PlayerName` = '%s' ", gPlayerData[playerid][pName]);
						wp_mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
						format(string, sizeof(string), "DELETE FROM `samp_users_keys` WHERE `PlayerName` = '%s' ", gPlayerData[playerid][pName]);
						wp_mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
						format(string, sizeof(string), "DELETE FROM `samp_users_lic` WHERE `PlayerName` = '%s' ", gPlayerData[playerid][pName]);
						wp_mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
						format(string, sizeof(string), "DELETE FROM `samp_users_notes` WHERE `PlayerName` = '%s' ", gPlayerData[playerid][pName]);
						wp_mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
						format(string, sizeof(string), "DELETE FROM `samp_users_vip` WHERE `PlayerName` = '%s' ", gPlayerData[playerid][pName]);
						wp_mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
						format(string, sizeof(string), "DELETE FROM `samp_users_other` WHERE `PlayerName` = '%s' ", gPlayerData[playerid][pName]);
						wp_mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
						format(string, sizeof(string), "DELETE FROM `samp_users_other2` WHERE `PlayerName` = '%s' ", gPlayerData[playerid][pName]);
						wp_mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
						format(string, sizeof(string), "DELETE FROM `samp_users_fueled` WHERE `PlayerName` = '%s' ", gPlayerData[playerid][pName]);
						wp_mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
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
								ResetBizData(i);
						}
						format(string, sizeof(string), "[PAYDAY:] Player name = %s - account removed", gPlayerData[playerid][pName], gPlayerData[playerid][pLastLogged]);
						PayDayLog(string);
					}

					/*
					* Select next player in DB
					*/
					gPayDayLoop++;
					
					format(string, sizeof(string), "[PAYDAY:] gPayDayLoop = %d, gPayDayCount = %d", gPayDayLoop, gPayDayCount );
					PayDayLog(string);
					
					if(gPayDayLoop <= gPayDayCount)
					{
						format(string, sizeof(string), "SELECT");
						strcat(string, " `samp_users`.*");
						strcat(string, ", `samp_users_items`.*");
						strcat(string, ", `samp_users_items2`.*");
						strcat(string, ", `samp_users_items3`.*");
						strcat(string, ", `samp_users_jobs`.*");
						strcat(string, ", `samp_users_lic`.*");
						strcat(string, ", `samp_users_notes`.*");
						strcat(string, ", `samp_users_other`.*");
						strcat(string, ", `samp_users_other2`.*");
						strcat(string, ", `samp_users_vip`.*");
						strcat(string, " FROM `samp_users`");
						strcat(string, " JOIN `samp_users_items` ON `samp_users_items`.PlayerName = `samp_users`.PlayerName");
						strcat(string, " JOIN `samp_users_items2` ON `samp_users_items2`.PlayerName = `samp_users`.PlayerName");
						strcat(string, " JOIN `samp_users_items3` ON `samp_users_items3`.PlayerName = `samp_users`.PlayerName");
						strcat(string, " JOIN `samp_users_jobs` ON `samp_users_jobs`.PlayerName = `samp_users`.PlayerName");
						strcat(string, " JOIN `samp_users_lic` ON `samp_users_lic`.PlayerName = `samp_users`.PlayerName");
						strcat(string, " JOIN `samp_users_notes` ON `samp_users_notes`.PlayerName = `samp_users`.PlayerName");
						strcat(string, " JOIN `samp_users_other` ON `samp_users_other`.PlayerName = `samp_users`.PlayerName");
						strcat(string, " JOIN `samp_users_other2` ON `samp_users_other2`.PlayerName = `samp_users`.PlayerName");
						strcat(string, " JOIN `samp_users_vip` ON `samp_users_vip`.PlayerName = `samp_users`.PlayerName");
						format(string, sizeof(string), "%s WHERE `samp_users`.Banned = '0' LIMIT %d , 1", string, gPayDayLoop);
					}
					
					return 1;
				}

				/*
				* Remove from public faction if not present for 5 days
				*/
				if(gPlayerData[playerid][pLastLogged] >= 5 && gPlayerData[playerid][pRank] == 1 && gPlayerData[playerid][pFaction] >= 0 && gPlayerData[playerid][pFaction] < 9 && gPlayerData[playerid][pFaction] != 6 && gPlayerData[playerid][pFaction] != 7 && gPlayerData[playerid][pFaction] != 8)
				{
					// TODO: dopisac tutaj czyszczenie frakcje
					gPlayerData[playerid][pFaction] = 255;
					gPlayerData[playerid][pRank] = 9;
					SavePlayerData(playerid, "Faction");
					SavePlayerData(playerid, "Rank");
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
				PHaveItemEx(playerid, 3, 6, slot);
				
				for(new i = 0; i < MAX_PLAYER_ITEM_SLOT; i++)
				{
					if(slot[i])
					{
						if(SlotParam1(playerid, i+1) > 0)
						{
							SetPSlotParam1(playerid, i+1, SlotParam1(playerid, i+1)-1);
						}
						
						if(SlotParam2(playerid, i+1) > 0)
						{
							SetPSlotParam2(playerid, i+1, SlotParam2(playerid, i+1)-1);
						}
						
						if(SlotParam3(playerid, i+1) > 0)
						{
							SetPSlotParam3(playerid, i+1, SlotParam3(playerid, i+1)-1);
						}
					}
				}
				
				/*
				* Credit repayment
				*/
				if(gPlayerData[playerid][mCreditValue] > 0 && gPlayerData[playerid][pAdmin] != 5)
				{
					format(string, sizeof(string), "[PAYDAY:] Player name = %s, credit repayment, Bank = $%d - $%d",
						gPlayerData[playerid][pName], gPlayerData[playerid][pBank], gPlayerData[playerid][mCreditRepayment]);
					PayDayLog(string);
					
					gPlayerData[playerid][pBank] -= gPlayerData[playerid][mCreditRepayment];
					gPlayerData[playerid][mCreditPayed] += gPlayerData[playerid][mCreditRepayment];						
					gPlayerData[playerid][pBankLoose] += gPlayerData[playerid][mCreditRepayment];
					
					DynamicFactions[FACTIONID_GOVERNMENT][fBank] += gPlayerData[playerid][mCreditRepayment];
					
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
				// TODO: WA¯NE ! UWZGLÊDNIÆ WSZYSTKIE SLOTY WSZEDZIE !
				PHaveItemEx(playerid, 3, 19, slot);
				for(new i = 1; i <= MAX_PLAYER_ITEM_SLOT; i++)
				{
					if(slot[i-1])
					{
						if(SlotParam3(playerid, i) > 0)
						{
							format(string, sizeof(string), "[PAYDAY:] Player name = %s, OC pay, Bank = $%d - $%d",
								gPlayerData[playerid][pName], gPlayerData[playerid][pBank], 4);
							PayDayLog(string);
							
							gPlayerData[playerid][pBank] -= 4;
							gPlayerData[CUSTOM_MAX_PLAYERS][pBankLoose] += 4;
							
							DynamicFactions[FACTIONID_GOVERNMENT][fBank] += 4;
						}
						if(SlotParam4(playerid, i) > 0)
						{
							format(string, sizeof(string), "[PAYDAY:] Player name = %s, AC pay, Bank = $%d - $%d",
								gPlayerData[playerid][pName], gPlayerData[playerid][pBank], 6);
							PayDayLog(string);
							
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
										gPlayerData[playerid][pName], gPlayerData[playerid][pBank], PayRank[n][Rank1], gPlayerData[playerid][pFaction], DynamicFactions[gPlayerData[playerid][pFaction]][fBank], PayRank[n][Rank1]);
									
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
										gPlayerData[playerid][pName], gPlayerData[playerid][pBank], PayRank[n][Rank3], gPlayerData[playerid][pFaction], DynamicFactions[gPlayerData[playerid][pFaction]][fBank], PayRank[n][Rank3]);
									
									gPlayerData[playerid][pBank] += PayRank[n][Rank3];
									gPlayerData[playerid][pBankIncome] += PayRank[n][Rank3];
									
									DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank3];
								}
								case 4:
								{
									format(string, sizeof(string), "[PAYDAY:] Player name = %s, rank 4, Bank = %d + %d, Faction id = %d, Bank = %d - %d",
										gPlayerData[playerid][pName], gPlayerData[playerid][pBank], PayRank[n][Rank4], gPlayerData[playerid][pFaction], DynamicFactions[gPlayerData[playerid][pFaction]][fBank], PayRank[n][Rank4]);
									
									gPlayerData[playerid][pBank] += PayRank[n][Rank4];
									gPlayerData[playerid][pBankIncome] += PayRank[n][Rank4];
									
									DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank4];
								}
								case 5:
								{
									format(string, sizeof(string), "[PAYDAY:] Player name = %s, rank 5, Bank = %d + %d, Faction id = %d, Bank = %d - %d",
										gPlayerData[playerid][pName], gPlayerData[playerid][pBank], PayRank[n][Rank5], gPlayerData[playerid][pFaction], DynamicFactions[gPlayerData[playerid][pFaction]][fBank], PayRank[n][Rank5]);
									
									gPlayerData[playerid][pBank] += PayRank[n][Rank5];
									gPlayerData[playerid][pBankIncome] += PayRank[n][Rank5];
									
									DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank5];
								}
								case 6:
								{
									format(string, sizeof(string), "[PAYDAY:] Player name = %s, rank 6, Bank = %d + %d, Faction id = %d, Bank = %d - %d",
										gPlayerData[playerid][pName], gPlayerData[playerid][pBank], PayRank[n][Rank6], gPlayerData[playerid][pFaction], DynamicFactions[gPlayerData[playerid][pFaction]][fBank], PayRank[n][Rank6]);
									
									gPlayerData[playerid][pBank] += PayRank[n][Rank6];
									gPlayerData[playerid][pBankIncome] += PayRank[n][Rank6];
									
									DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank6];
								}
								case 7:
								{
									format(string, sizeof(string), "[PAYDAY:] Player name = %s, rank 7, Bank = %d + %d, Faction id = %d, Bank = %d - %d",
										gPlayerData[playerid][pName], gPlayerData[playerid][pBank], PayRank[n][Rank7], gPlayerData[playerid][pFaction], DynamicFactions[gPlayerData[playerid][pFaction]][fBank], PayRank[n][Rank7]);
									
									gPlayerData[playerid][pBank] += PayRank[n][Rank7];
									gPlayerData[playerid][pBankIncome] += PayRank[n][Rank7];
									
									DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank7];
								}
								case 8:
								{
									format(string, sizeof(string), "[PAYDAY:] Player name = %s, rank 8, Bank = %d + %d, Faction id = %d, Bank = %d - %d",
										gPlayerData[playerid][pName], gPlayerData[playerid][pBank], PayRank[n][Rank8], gPlayerData[playerid][pFaction], DynamicFactions[gPlayerData[playerid][pFaction]][fBank], PayRank[n][Rank8]);
									
									gPlayerData[playerid][pBank] += PayRank[n][Rank8];
									gPlayerData[playerid][pBankIncome] += PayRank[n][Rank8];
									
									DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank8];
								}
								case 9:
								{
									format(string, sizeof(string), "[PAYDAY:] Player name = %s, rank 9, Bank = %d + %d, Faction id = %d, Bank = %d - %d",
										gPlayerData[playerid][pName], gPlayerData[playerid][pBank], PayRank[n][Rank9], gPlayerData[playerid][pFaction], DynamicFactions[gPlayerData[playerid][pFaction]][fBank], PayRank[n][Rank9]);
									
									gPlayerData[playerid][pBank] += PayRank[n][Rank9];
									gPlayerData[playerid][pBankIncome] += PayRank[n][Rank9];
									
									DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank9];
								}
								case 10:
								{
									format(string, sizeof(string), "[PAYDAY:] Player name = %s, rank 10, Bank = %d + %d, Faction id = %d, Bank = %d - %d",
										gPlayerData[playerid][pName], gPlayerData[playerid][pBank], PayRank[n][Rank10], gPlayerData[playerid][pFaction], DynamicFactions[gPlayerData[playerid][pFaction]][fBank], PayRank[n][Rank10]);
									
									gPlayerData[playerid][pBank] += PayRank[n][Rank10];
									gPlayerData[playerid][pBankIncome] += PayRank[n][Rank10];
									
									DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank10];
								}
							}
							
							PayDayLog(string);
							SaveFData(gPlayerData[playerid][pFaction], "Bank");
							
							break;
						}
					}
				}
				
				/*
				* Give player faction payment and other payment
				*/
				if(gPlayerData[CUSTOM_MAX_PLAYERS][pFaction2] != 255 && gPlayerData[playerid][pLastLogged] == 0)
				{
					for(new n = 0; n < sizeof(DynamicFactions); n++)
					{
						if(PayRank[n][FactionID] == gPlayerData[CUSTOM_MAX_PLAYERS][pFaction2])
						{
							switch(gPlayerData[playerid][pRank2])
							{
								case 1:
								{
									format(string, sizeof(string), "[PAYDAY:] Player name = %s, rank 1, Bank = %d + %d, Faction id = %d, Bank = %d - %d",
										gPlayerData[playerid][pName], gPlayerData[playerid][pBank], PayRank[n][Rank1], gPlayerData[playerid][pFaction2], DynamicFactions[gPlayerData[playerid][pFaction2]][fBank], PayRank[n][Rank1]);
								
									gPlayerData[playerid][pBank] += PayRank[n][Rank1];
									gPlayerData[playerid][pBankIncome] += PayRank[n][Rank1];
									
									DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank1];
								}
								case 2:
								{
									format(string, sizeof(string), "[PAYDAY:] Player name = %s, rank 2, Bank = %d + %d, Faction id = %d, Bank = %d - %d",
										gPlayerData[playerid][pName], gPlayerData[playerid][pBank], PayRank[n][Rank2], gPlayerData[playerid][pFaction2], DynamicFactions[gPlayerData[playerid][pFaction2]][fBank], PayRank[n][Rank2]);
									
									gPlayerData[playerid][pBank] += PayRank[n][Rank2];
									gPlayerData[playerid][pBankIncome] += PayRank[n][Rank2];
									
									DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank2];
								}
								case 3:
								{
									format(string, sizeof(string), "[PAYDAY:] Player name = %s, rank 3, Bank = %d + %d, Faction id = %d, Bank = %d - %d",
										gPlayerData[playerid][pName], gPlayerData[playerid][pBank], PayRank[n][Rank3], gPlayerData[playerid][pFaction2], DynamicFactions[gPlayerData[playerid][pFaction2]][fBank], PayRank[n][Rank3]);
									
									gPlayerData[playerid][pBank] += PayRank[n][Rank3];
									gPlayerData[playerid][pBankIncome] += PayRank[n][Rank3];
									
									DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank3];
								}
								case 4:
								{
									format(string, sizeof(string), "[PAYDAY:] Player name = %s, rank 4, Bank = %d + %d, Faction id = %d, Bank = %d - %d",
										gPlayerData[playerid][pName], gPlayerData[playerid][pBank], PayRank[n][Rank4], gPlayerData[playerid][pFaction2], DynamicFactions[gPlayerData[playerid][pFaction2]][fBank], PayRank[n][Rank4]);
									
									gPlayerData[playerid][pBank] += PayRank[n][Rank4];
									gPlayerData[playerid][pBankIncome] += PayRank[n][Rank4];
									
									DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank4];
								}
								case 5:
								{
									format(string, sizeof(string), "[PAYDAY:] Player name = %s, rank 5, Bank = %d + %d, Faction id = %d, Bank = %d - %d",
										gPlayerData[playerid][pName], gPlayerData[playerid][pBank], PayRank[n][Rank5], gPlayerData[playerid][pFaction2], DynamicFactions[gPlayerData[playerid][pFaction2]][fBank], PayRank[n][Rank5]);
									
									gPlayerData[playerid][pBank] += PayRank[n][Rank5];
									gPlayerData[playerid][pBankIncome] += PayRank[n][Rank5];
									
									DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank5];
								}
								case 6:
								{
									format(string, sizeof(string), "[PAYDAY:] Player name = %s, rank 6, Bank = %d + %d, Faction id = %d, Bank = %d - %d",
										gPlayerData[playerid][pName], gPlayerData[playerid][pBank], PayRank[n][Rank6], gPlayerData[playerid][pFaction2], DynamicFactions[gPlayerData[playerid][pFaction2]][fBank], PayRank[n][Rank6]);
									
									gPlayerData[playerid][pBank] += PayRank[n][Rank6];
									gPlayerData[playerid][pBankIncome] += PayRank[n][Rank6];
									
									DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank6];
								}
								case 7:
								{
									format(string, sizeof(string), "[PAYDAY:] Player name = %s, rank 7, Bank = %d + %d, Faction id = %d, Bank = %d - %d",
										gPlayerData[playerid][pName], gPlayerData[playerid][pBank], PayRank[n][Rank7], gPlayerData[playerid][pFaction2], DynamicFactions[gPlayerData[playerid][pFaction2]][fBank], PayRank[n][Rank7]);
									
									gPlayerData[playerid][pBank] += PayRank[n][Rank7];
									gPlayerData[playerid][pBankIncome] += PayRank[n][Rank7];
									
									DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank7];
								}
								case 8:
								{
									format(string, sizeof(string), "[PAYDAY:] Player name = %s, rank 8, Bank = %d + %d, Faction id = %d, Bank = %d - %d",
										gPlayerData[playerid][pName], gPlayerData[playerid][pBank], PayRank[n][Rank8], gPlayerData[playerid][pFaction2], DynamicFactions[gPlayerData[playerid][pFaction2]][fBank], PayRank[n][Rank8]);
									
									gPlayerData[playerid][pBank] += PayRank[n][Rank8];
									gPlayerData[playerid][pBankIncome] += PayRank[n][Rank8];
									
									DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank8];
								}
								case 9:
								{
									format(string, sizeof(string), "[PAYDAY:] Player name = %s, rank 9, Bank = %d + %d, Faction id = %d, Bank = %d - %d",
										gPlayerData[playerid][pName], gPlayerData[playerid][pBank], PayRank[n][Rank9], gPlayerData[playerid][pFaction2], DynamicFactions[gPlayerData[playerid][pFaction2]][fBank], PayRank[n][Rank9]);
									
									gPlayerData[playerid][pBank] += PayRank[n][Rank9];
									gPlayerData[playerid][pBankIncome] += PayRank[n][Rank9];
									
									DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank9];
								}
								case 10:
								{
									format(string, sizeof(string), "[PAYDAY:] Player name = %s, rank 10, Bank = %d + %d, Faction id = %d, Bank = %d - %d",
										gPlayerData[playerid][pName], gPlayerData[playerid][pBank], PayRank[n][Rank10], gPlayerData[playerid][pFaction2], DynamicFactions[gPlayerData[playerid][pFaction2]][fBank], PayRank[n][Rank10]);
									
									gPlayerData[playerid][pBank] += PayRank[n][Rank10];
									gPlayerData[playerid][pBankIncome] += PayRank[n][Rank10];
									
									DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank10];
								}
							}
							
							PayDayLog(string);
							SaveFData( gPlayerData[playerid][pFaction2], "Bank" );
							
							break;
						}
					}
				}
				
				if(gPlayerData[playerid][pJob] == 0 && gPlayerData[playerid][pFaction] == 255)
				{
					format(string, sizeof(string), "[PAYDAY:] Player name = %s, Bank = %d + %d", gPlayerData[playerid][pName], gPlayerData[playerid][pBank], Zasilek);
					PayDayLog(string);
					
					gPlayerData[playerid][pBank] += Zasilek;
					gPlayerData[playerid][pBankIncome] += Zasilek;
					
					DynamicFactions[FACTIONID_GOVERNMENT][fBank] -= Zasilek;
				}

				/*
				* Pay taxes, costs, tickets, etc.
				*/
				format(string, sizeof(string), "[PAYDAY:] PlayerName = %s, Bank = %d - %d, SOURCE = Radio tax", gPlayerData[playerid][pName], gPlayerData[playerid][pBank], DynamicTaxes[RadioTax]);
				PayDayLog(string);
				
				gPlayerData[playerid][pBank] -= DynamicTaxes[RadioTax];
				gPlayerData[playerid][pBankLoose] += DynamicTaxes[RadioTax];
				
				DynamicFactions[FACTIONID_GOVERNMENT][fBank] += DynamicTaxes[RadioTax];
				
				if((gPlayerData[playerid][pCash] + gPlayerData[playerid][pBank]) >= DynamicTaxes[TheRich])
				{
					format(string, sizeof(string), "[PAYDAY:] PlayerName = %s, Bank = %d - %d, SOURCE = taxes (the rich)", gPlayerData[playerid][pName], gPlayerData[playerid][pBank], floatround(DynamicTaxes[RichTax] * (gPlayerData[playerid][pBank]+gPlayerData[playerid][pCash]), floatround_round));
					PayDayLog(string);
					
					gPlayerData[playerid][pBank] -= floatround(DynamicTaxes[RichTax] * (gPlayerData[playerid][pBank]+gPlayerData[playerid][pCash]), floatround_round);
					gPlayerData[playerid][pBankLoose] += floatround(DynamicTaxes[RichTax] * (gPlayerData[playerid][pBank]+gPlayerData[playerid][pCash]), floatround_round);
					
					DynamicFactions[FACTIONID_GOVERNMENT][fBank] += floatround(DynamicTaxes[RichTax] * (gPlayerData[playerid][pBank]+gPlayerData[playerid][pCash]), floatround_round);
				}
				
				if(gPlayerData[playerid][pCost] > 0)
				{
					format(string, sizeof(string), "[PAYDAY:] PlayerName = %s, Bank = %d - %d, SOURCE = costs",
						gPlayerData[playerid][pName], gPlayerData[playerid][pBank], gPlayerData[playerid][pCost]);
					PayDayLog(string);
					
					gPlayerData[playerid][pBank] -= gPlayerData[playerid][pCost];
					gPlayerData[playerid][pBankLoose] += gPlayerData[playerid][pCost];						
					
					DynamicFactions[FACTIONID_GOVERNMENT][fBank] += gPlayerData[playerid][pCost];
					
					gPlayerData[playerid][pCost] = 0;
					SavePlayerData(playerid, "Cost");
				}
				
				if(gPlayerData[playerid][pTicket] > 0)
				{
					format(string, sizeof(string), "[PAYDAY:] PlayerName = %s, Bank = %d - %d, SOURCE = ticket",
						gPlayerData[playerid][pName], gPlayerData[playerid][pBank], gPlayerData[playerid][pTicket]);
					PayDayLog(string);
					
					gPlayerData[playerid][pBank] -= gPlayerData[playerid][pTicket];
					gPlayerData[playerid][pBankLoose] += gPlayerData[playerid][pTicket];
					
					DynamicFactions[FACTIONID_POLICE][fBank] += gPlayerData[playerid][pTicket];
					SaveFData(FACTIONID_POLICE, "Bank");
					
					gPlayerData[playerid][pTicket] = 0;
					SavePlayerData( playerid, "Ticket" );
				}
				
				for(new i = 0; i < sizeof(Houses); i++)
				{
					if(strcmp(gPlayerData[playerid][pName], Houses[i][HRenter], false) == 0 && strlen(Houses[i][HRenter]) > 0)
					{
						if(gPlayerData[playerid][pBank] < 0)
						{
							format(string, sizeof(string), "[PAYDAY:] PlayerName = %s, House rent deleted, House ID: %d",
								gPlayerData[playerid][pName], i);
							PayDayLog(string);
							
							strmid(Houses[i][HRenter], "Brak", 0, MAX_PLAYER_NAME, 255);
							SaveHouseData(i, "Renter");
						}
						else
						{
							format(string, sizeof(string), "[PAYDAY:] PlayerName = %s, Bank = %d - %d, SOURCE = house rent, House ID: %d", 
								gPlayerData[playerid][pName], gPlayerData[playerid][pBank], Houses[i][RentCost], i);
							PayDayLog(string);
							
							gPlayerData[playerid][pBank] -= Houses[i][RentCost];
							gPlayerData[playerid][pBankLoose] += Houses[i][RentCost];
							
							UpdatePlayerDataByName(Houses[i][Owner], "Bank", Houses[i][RentCost]);
						}
					}
				}

				/*
				* Is player on debt ?
				*/
				if(gPlayerData[playerid][pBank] < -5000)
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
							gVehData[i][VConfiscated] = 1;
							SaveVehData(i, "Closed");
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
						if(strcmp(gVehData[i][Owner], gPlayerData[playerid][pName], true) == 0 && strlen(gVehData[i][Owner]) > 0)
						{
							format(string, sizeof(string), "[PAYDAY:] PlayerName = %s, Veh ID: %d, deconfiscated", gPlayerData[playerid][pName], i);
							PayDayLog(string);

							new enginedyn,lights,alarm,doors,bonnet,boot,objective;
							GetVehicleParamsEx(i+1,enginedyn,lights,alarm,doors,bonnet,boot,objective);
							SetVehicleParamsEx(i+1,enginedyn,lights,alarm,0,bonnet,boot,objective);

							gVehData[i][Closed] = 0;
							gVehData[i][VConfiscated] = 0;
							SaveVehData(i, "Closed");
							SaveVehData(i, "Confiscated");
						}
					}
				}

				/*
				* Calculate and update player RP score
				*/
				gPlayerData[playerid][pScore] = (gPlayerData[playerid][pRPCount] * 2);
				SavePlayerData(playerid, "Score");

				/*
				* VIP reduce
				*/
				if(gVipReduceOn)
				{
					if(gPlayerData[playerid][pVipAFKT] > 0)
					{
						format(string, sizeof(string), "[PAYDAY:] PlayerName = %s, VipAFKT: %d -1", gPlayerData[playerid][pName], gPlayerData[playerid][pVipAFKT]);
						PayDayLog(string);
						
						gPlayerData[playerid][pVipAFKT]--;
						SavePlayerData(playerid, "VipAFKT");
					}
					if(gPlayerData[playerid][pVipExpT] > 0)
					{
						format(string, sizeof(string), "[PAYDAY:] PlayerName = %s, VipExpT: %d -1", gPlayerData[playerid][pName], gPlayerData[playerid][pVipExpT]);
						PayDayLog(string);
						
						gPlayerData[playerid][pVipExpT]--;
						SavePlayerData(playerid, "VipExpT");
					}
					if(gPlayerData[playerid][pVipItem] > 0)
					{
						format(string, sizeof(string), "[PAYDAY:] PlayerName = %s, VipItem: %d -1", gPlayerData[playerid][pName], gPlayerData[playerid][pVipItem]);
						PayDayLog(string);
							
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
						gPlayerData[playerid][pWarnCooldown] = WARN_COOLDOWN;
						SavePlayerData(playerid, "Warnings");
						SavePlayerData(playerid, "WarnCooldown");
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

				format(string, sizeof(string), "[PAYDAY:] Player %s end in character cash: $%d, in bank cash: $%d", gPlayerData[playerid][pName], gPlayerData[playerid][pCash], gPlayerData[playerid][pBank]);
				PayDayLog(string);

				SaveFData(FACTIONID_GOVERNMENT, "Bank");

				/*
				* Select next player in DB
				*/
				gPayDayLoop++;
				format(string, sizeof(string), "[PAYDAY:] gPayDayLoop = %d, gPayDayCount = %d", gPayDayLoop, gPayDayCount);
				PayDayLog(string);
				if(gPayDayLoop <= gPayDayCount)
				{
					format(string, sizeof(string), "SELECT");
					strcat(string, " `samp_users`.*");
					strcat(string, ", `samp_users_items`.*");
					strcat(string, ", `samp_users_items2`.*");
					strcat(string, ", `samp_users_items3`.*");
					strcat(string, ", `samp_users_jobs`.*");
					strcat(string, ", `samp_users_lic`.*");
					strcat(string, ", `samp_users_notes`.*");
					strcat(string, ", `samp_users_other`.*");
					strcat(string, ", `samp_users_other2`.*");
					strcat(string, ", `samp_users_vip`.*");
					strcat(string, " FROM `samp_users`");
					strcat(string, " JOIN `samp_users_items` ON `samp_users_items`.PlayerName = `samp_users`.PlayerName");
					strcat(string, " JOIN `samp_users_items2` ON `samp_users_items2`.PlayerName = `samp_users`.PlayerName");
					strcat(string, " JOIN `samp_users_items3` ON `samp_users_items3`.PlayerName = `samp_users`.PlayerName");
					strcat(string, " JOIN `samp_users_jobs` ON `samp_users_jobs`.PlayerName = `samp_users`.PlayerName");
					strcat(string, " JOIN `samp_users_lic` ON `samp_users_lic`.PlayerName = `samp_users`.PlayerName");
					strcat(string, " JOIN `samp_users_notes` ON `samp_users_notes`.PlayerName = `samp_users`.PlayerName");
					strcat(string, " JOIN `samp_users_other` ON `samp_users_other`.PlayerName = `samp_users`.PlayerName");
					strcat(string, " JOIN `samp_users_other2` ON `samp_users_other2`.PlayerName = `samp_users`.PlayerName");
					strcat(string, " JOIN `samp_users_vip` ON `samp_users_vip`.PlayerName = `samp_users`.PlayerName");
					format(string, sizeof(string), "%s WHERE `samp_users`.Banned = '0' LIMIT %d , 1", string, gPayDayLoop);
				}
				
				return 1;
			}
		}
		case DEL_FROM_FORUM_FACTION:
		{
			mysql_store_result(db_con2);
			mysql_retrieve_row(db_con2);
			mysql_fetch_field_row(string, "additionalgroups", db_con2);
			
			new stringNumber[4];
			
			switch(FactionRequest[playerid])
			{
				case 0:
				{
					format(stringNumber, sizeof(stringNumber), "9");
				}
				case 9:
				{
					format(stringNumber, sizeof(stringNumber), "15");
				}
			}
			
			new index = strfind(string, stringNumber, true);			
			new numberSize = strlen(stringNumber);
			
			if(index != -1)
			{
				// liczba nie jest na pocz¹tku
				if(index > 0)
				{
					strdel(string, index-1, index+numberSize);
				}
				else
				{
					strdel(string, 0, index+numberSize);
				}
				format(string, sizeof(string), "UPDATE `mybb_users` SET `additionalgroups` = '%s' WHERE `uid` = '%d'", string, gPlayerData[playerid][pAccountOwnerID]);
				wp_mysql_query(string, SAVE, playerid, db_con3);
			}
			FactionRequest[playerid] = 255;
		}
		case SET_FORUM_FACTION:
		{
			// [NOTE:] Nie uwzglêdniono liczb 3 i wiêcej cyfrowych w wyszukiwaniu grupy !
			mysql_store_result(db_con2);
			mysql_retrieve_row(db_con2);
			mysql_fetch_field_row(string, "additionalgroups", db_con2);
			
			new stringNumber[4];
			
			switch(FactionRequest[playerid])
			{
				case 0:
				{
					format(stringNumber, sizeof(stringNumber), "9");
				}
			}
			
			new index = strfind(string, stringNumber, true);			
			new numberSize = strlen(stringNumber);
			
			// liczby nie ma w stringu
			if(index == -1)
			{
				notSearchedNumber:
				// string jest pusty
				if(strlen(string) == 0)
				{
					format(string, sizeof(string), "UPDATE `mybb_users` SET `additionalgroups` = '%s' WHERE `uid` = '%d'", stringNumber, gPlayerData[playerid][pAccountOwnerID]);
					wp_mysql_query(string, SAVE, playerid, db_con3);
				}
				// string nie jest pusty
				else
				{
					format(string, sizeof(string), "UPDATE `mybb_users` SET `additionalgroups` = '%s,%s' WHERE `uid` = '%d'", string, stringNumber, gPlayerData[playerid][pAccountOwnerID]);
					wp_mysql_query(string, SAVE, playerid, db_con3);
				}
			}
			// liczba jest w stringu
			else
			{
				// liczba nie jest na pocz¹tku
				if(index > 0)
				{
					new isLast = false;
					if(index+numberSize == strlen(string))
					{
						isLast = true;
					}
					if(string[index-1] == ',')
					{
						if(!isLast && string[index+numberSize] == ',')
						{
							// liczba jest ju¿ wpisana
							return 1;
						}
						else
						{
							goto notSearchedNumber;
						}
					}
				}
			}
			FactionRequest[playerid] = 255;
		}
		case LOAD_RAFINERY:
		{
			mysql_store_result(db_con2);
			mysql_retrieve_row(db_con2);
			
			mysql_fetch_field_row(string, "ResourcePetrol", db_con2);
			gRafinery[RafResourcePetrol] = strval(string);
			mysql_fetch_field_row(string, "PetrolLtrCost", db_con2);
			gRafinery[RafPetrolLtrCost] = strval(string);
			mysql_fetch_field_row(string, "EmployerReward", db_con2);
			gRafinery[RafRefuelReward] = strval(string);
			mysql_fetch_field_row(string, "MaxResources", db_con2);
			gRafinery[RafMaxResources] = strval(string);
			mysql_fetch_field_row(string, "ResourceOil", db_con2);
			gRafinery[RafResourceOil] = strval(string);
			mysql_fetch_field_row(string, "ResourceGas", db_con2);
			gRafinery[RafResourceGas] = strval(string);
			mysql_fetch_field_row(string, "ResourceFly", db_con2);
			gRafinery[RafResourceFly] = strval(string);
			mysql_fetch_field_row(string, "OilLtrCost", db_con2);
			gRafinery[RafOilLtrCost] = strval(string);
			mysql_fetch_field_row(string, "GasLtrCost", db_con2);
			gRafinery[RafGasLtrCost] = strval(string);
			mysql_fetch_field_row(string, "FlyLtrCost", db_con2);
			gRafinery[RafFlyLtrCost] = strval(string);

			#if defined DEBUG
				print("[INFO:] Rafinery loaded [MySQL]");
			#endif
		}
		case LOAD_WFACTORYLEGAL:
		{
			mysql_store_result(db_con2);
			mysql_retrieve_row(db_con2);

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

			//wp_mysql_free_result(db_con2);

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
			mysql_store_result(db_con2);
			
			new i = 0;

			while(mysql_retrieve_row(db_con2))
			{
				mysql_fetch_field_row(string, "BusinessID", db_con2);
				GasStations[i][BusinessID] = strval(string);
				mysql_fetch_field_row(string, "PetrolResourceValue", db_con2);
				GasStations[i][PetrolResourceValue] = floatstr(string);
				mysql_fetch_field_row(string, "OilResourceValue", db_con2);
				GasStations[i][OilResourceValue] = floatstr(string);
				mysql_fetch_field_row(string, "GasResourceValue", db_con2);
				GasStations[i][GasResourceValue] = floatstr(string);
				mysql_fetch_field_row(string, "MaxPetrolResourceValue", db_con2);
				GasStations[i][MaxPetrolResourceValue] = floatstr(string);
				mysql_fetch_field_row(string, "MaxOilResourceValue", db_con2);
				GasStations[i][MaxOilResourceValue] = floatstr(string);
				mysql_fetch_field_row(string, "MaxGasResourceValue", db_con2);
				GasStations[i][MaxGasResourceValue] = floatstr(string);
				mysql_fetch_field_row(string, "RefuelPetrolResources", db_con2);
				GasStations[i][RefuelPetrolResources] = strval(string);
				mysql_fetch_field_row(string, "RefuelOilResources", db_con2);
				GasStations[i][RefuelOilResources] = strval(string);
				mysql_fetch_field_row(string, "RefuelGasResources", db_con2);
				GasStations[i][RefuelGasResources] = strval(string);
				mysql_fetch_field_row(string, "PetrolPrice", db_con2);
				GasStations[i][PetrolPrice] = strval(string);
				mysql_fetch_field_row(string, "OilPrice", db_con2);
				GasStations[i][OilPrice] = strval(string);
				mysql_fetch_field_row(string, "GasPrice", db_con2);
				GasStations[i][GasPrice] = strval(string);
				mysql_fetch_field_row(string, "posX", db_con2);
				GasStations[i][GSposX] = floatstr(string);
				mysql_fetch_field_row(string, "posY", db_con2);
				GasStations[i][GSposY] = floatstr(string);
				mysql_fetch_field_row(string, "posZ", db_con2);
				GasStations[i][GSposZ] = floatstr(string);
				mysql_fetch_field_row(string, "Pos3dTextX", db_con2);
				GasStations[i][Pos3dTextX] = floatstr(string);
				mysql_fetch_field_row(string, "Pos3dTextY", db_con2);
				GasStations[i][Pos3dTextY] = floatstr(string);
				mysql_fetch_field_row(string, "Pos3dTextZ", db_con2);
				GasStations[i][Pos3dTextZ] = floatstr(string);
				mysql_fetch_field_row(string, "Pos3dTextX2", db_con2);
				GasStations[i][Pos3dTextX2] = floatstr(string);
				mysql_fetch_field_row(string, "Pos3dTextY2", db_con2);
				GasStations[i][Pos3dTextY2] = floatstr(string);
				mysql_fetch_field_row(string, "Pos3dTextZ2", db_con2);
				GasStations[i][Pos3dTextZ2] = floatstr(string);
				mysql_fetch_field_row(string, "Pos3dTextX3", db_con2);
				GasStations[i][Pos3dTextX3] = floatstr(string);
				mysql_fetch_field_row(string, "Pos3dTextY3", db_con2);
				GasStations[i][Pos3dTextY3] = floatstr(string);
				mysql_fetch_field_row(string, "Pos3dTextZ3", db_con2);
				GasStations[i][Pos3dTextZ3] = floatstr(string);
				mysql_fetch_field_row(string, "Pos3dTextX4", db_con2);
				GasStations[i][Pos3dTextX4] = floatstr(string);
				mysql_fetch_field_row(string, "Pos3dTextY4", db_con2);
				GasStations[i][Pos3dTextY4] = floatstr(string);
				mysql_fetch_field_row(string, "Pos3dTextZ4", db_con2);
				GasStations[i][Pos3dTextZ4] = floatstr(string);

				format(string, sizeof(string), "Benzyna: $%d", GasStations[i][PetrolPrice]);
				GasStations[i][GS3dTextLabel] = CreateDynamic3DTextLabel(string, COLOR_GREEN, GasStations[i][Pos3dTextX], GasStations[i][Pos3dTextY], GasStations[i][Pos3dTextZ], 50.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID);
				format(string, sizeof(string), "Diesel: $%d", GasStations[i][OilPrice]);
				GasStations[i][GS3dTextLabel2] = CreateDynamic3DTextLabel(string, COLOR_GREEN, GasStations[i][Pos3dTextX2], GasStations[i][Pos3dTextY2], GasStations[i][Pos3dTextZ2], 50.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID);
				format(string, sizeof(string), "Gaz: $%d", GasStations[i][GasPrice]);
				GasStations[i][GS3dTextLabel3] = CreateDynamic3DTextLabel(string, COLOR_GREEN, GasStations[i][Pos3dTextX3], GasStations[i][Pos3dTextY3], GasStations[i][Pos3dTextZ3], 50.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID);
				format(string, sizeof(string), "Nr stacji: %d", i+1);
				GasStations[i][GS3dTextLabel4] = CreateDynamic3DTextLabel(string, COLOR_GREEN, GasStations[i][Pos3dTextX4], GasStations[i][Pos3dTextY4], GasStations[i][Pos3dTextZ4], 50.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID);

				// printf("GasStation ID: %d,  GSposX = %f, GSposY = %f, GSposZ = %f", i, GasStations[i][GSposX], GasStations[i][GSposY], GasStations[i][GSposZ] );

				i++;
			}
			#if defined DEBUG
				print("[INFO:] Gas stations data loaded [MySQL]");
			#endif
		}
		case COUNT_PAYDAY:
		{
			mysql_store_result(db_con2);
			
			mysql_fetch_field_row(string, "founder_count", db_con2);
			gPayDayCount = strval(string);

			gPayDayLoop = 0;
			
			format(string, sizeof(string), "[PAYDAY:] PayDayCount = %d", gPayDayCount);
			PayDayLog(string);
			PayDayLog("[PAYDAY:] Loading first player from DB");
			
			format(string, sizeof(string), "SELECT");
			strcat(string, " `samp_users`.*");
			strcat(string, ", `samp_users_items`.*");
			strcat(string, ", `samp_users_items2`.*");
			strcat(string, ", `samp_users_items3`.*");
			strcat(string, ", `samp_users_jobs`.*");
			strcat(string, ", `samp_users_lic`.*");
			strcat(string, ", `samp_users_notes`.*");
			strcat(string, ", `samp_users_other`.*");
			strcat(string, ", `samp_users_other2`.*");
			strcat(string, ", `samp_users_vip`.*");
			strcat(string, " FROM `samp_users`");
			strcat(string, " JOIN `samp_users_items` ON `samp_users_items`.PlayerName = `samp_users`.PlayerName");
			strcat(string, " JOIN `samp_users_items2` ON `samp_users_items2`.PlayerName = `samp_users`.PlayerName");
			strcat(string, " JOIN `samp_users_items3` ON `samp_users_items3`.PlayerName = `samp_users`.PlayerName");
			strcat(string, " JOIN `samp_users_jobs` ON `samp_users_jobs`.PlayerName = `samp_users`.PlayerName");
			strcat(string, " JOIN `samp_users_lic` ON `samp_users_lic`.PlayerName = `samp_users`.PlayerName");
			strcat(string, " JOIN `samp_users_notes` ON `samp_users_notes`.PlayerName = `samp_users`.PlayerName");
			strcat(string, " JOIN `samp_users_other` ON `samp_users_other`.PlayerName = `samp_users`.PlayerName");
			strcat(string, " JOIN `samp_users_other2` ON `samp_users_other2`.PlayerName = `samp_users`.PlayerName");
			strcat(string, " JOIN `samp_users_vip` ON `samp_users_vip`.PlayerName = `samp_users`.PlayerName");
			format(string, sizeof(string), "%s WHERE `samp_users`.Banned = '0' ORDER BY `samp_users`.`ID` LIMIT %d , 1", string, gPayDayLoop);
			
			wp_mysql_query(string, PLAYER_DATA_LOAD_ALL_PAYDAY, CUSTOM_MAX_PLAYERS, db_con4);
		}
		case UPDATE_DATA:
		{
			mysql_fetch_field_row(string, "Bank", db_con3);
			gPlayerData[CUSTOM_MAX_PLAYERS][pBank] = strval(string);
			
			mysql_fetch_field_row(string, "PlayerName", db_con3);
			
			format(gPlayerData[CUSTOM_MAX_PLAYERS][pName], MAX_PLAYER_NAME, string);
			
			format(string, sizeof(string), "UPDATE `samp_users` SET `Bank` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[CUSTOM_MAX_PLAYERS][pBank]+extraid, gPlayerData[CUSTOM_MAX_PLAYERS][pName]);
			wp_mysql_query(string, SAVE, playerid, db_con3);
			return 1;
		}
		case SAVE:
		{
			// wp_mysql_free_result(db_con2);
		}
		case SAVE2:
		{
			// wp_mysql_free_result(db_con3);
		}
		case SAVE3:
		{
			// wp_mysql_free_result(db_con4);
		}
		case LOAD_FACTIONS_PAYRANK:
		{
			mysql_store_result(db_con2);
			
			new i = 0;

			while(mysql_retrieve_row(db_con2))
			{
				mysql_fetch_field_row(string, "FactionID", db_con3);
				PayRank[i][FactionID] = strval(string);
				mysql_fetch_field_row(string, "Rank1", db_con3);
				PayRank[i][Rank1] = strval(string);
				mysql_fetch_field_row(string, "Rank2", db_con3);
				PayRank[i][Rank2] = strval(string);
				mysql_fetch_field_row(string, "Rank3", db_con3);
				PayRank[i][Rank3] = strval(string);
				mysql_fetch_field_row(string, "Rank4", db_con3);
				PayRank[i][Rank4] = strval(string);
				mysql_fetch_field_row(string, "Rank5", db_con3);
				PayRank[i][Rank5] = strval(string);
				mysql_fetch_field_row(string, "Rank6", db_con3);
				PayRank[i][Rank6] = strval(string);
				mysql_fetch_field_row(string, "Rank7", db_con3);
				PayRank[i][Rank7] = strval(string);
				mysql_fetch_field_row(string, "Rank8", db_con3);
				PayRank[i][Rank8] = strval(string);
				mysql_fetch_field_row(string, "Rank9", db_con3);
				PayRank[i][Rank9] = strval(string);
				mysql_fetch_field_row(string, "Rank10", db_con3);
				PayRank[i][Rank10] = strval(string);
				i++;
			}
			#if defined DEBUG
				print("[INFO:] Factions payments loaded [MySQL]");
			#endif
		}
		case LOAD_DYNAMIC_FACTIONS_WEAPONS2:
		{
			mysql_store_result(db_con2);
		
			new fid;

			while(mysql_retrieve_row(db_con2))
			{
				mysql_fetch_field_row(string, "FactionID", db_con2);
				fid = strval(string);				
				mysql_fetch_field_row(string, "Ammo1Rank1", db_con2);
				DynamicFactions[fid][fAmmo1Rank1] = strval(string);
				mysql_fetch_field_row(string, "Ammo1Rank2", db_con2);
				DynamicFactions[fid][fAmmo1Rank2] = strval(string);
				mysql_fetch_field_row(string, "Ammo1Rank3", db_con2);
				DynamicFactions[fid][fAmmo1Rank3] = strval(string);
				mysql_fetch_field_row(string, "Ammo1Rank4", db_con2);
				DynamicFactions[fid][fAmmo1Rank4] = strval(string);
				mysql_fetch_field_row(string, "Ammo1Rank5", db_con2);
				DynamicFactions[fid][fAmmo1Rank5] = strval(string);
				mysql_fetch_field_row(string, "Ammo1Rank6", db_con2);
				DynamicFactions[fid][fAmmo1Rank6] = strval(string);
				mysql_fetch_field_row(string, "Ammo1Rank7", db_con2);
				DynamicFactions[fid][fAmmo1Rank7] = strval(string);
				mysql_fetch_field_row(string, "Ammo1Rank8", db_con2);
				DynamicFactions[fid][fAmmo1Rank8] = strval(string);
				mysql_fetch_field_row(string, "Ammo1Rank9", db_con2);
				DynamicFactions[fid][fAmmo1Rank9] = strval(string);
				mysql_fetch_field_row(string, "Ammo1Rank10", db_con2);
				DynamicFactions[fid][fAmmo1Rank10] = strval(string);
				
				mysql_fetch_field_row(string, "Ammo2Rank1", db_con2);
				DynamicFactions[fid][fAmmo2Rank1] = strval(string);
				mysql_fetch_field_row(string, "Ammo2Rank2", db_con2);
				DynamicFactions[fid][fAmmo2Rank2] = strval(string);
				mysql_fetch_field_row(string, "Ammo2Rank3", db_con2);
				DynamicFactions[fid][fAmmo2Rank3] = strval(string);
				mysql_fetch_field_row(string, "Ammo2Rank4", db_con2);
				DynamicFactions[fid][fAmmo2Rank4] = strval(string);
				mysql_fetch_field_row(string, "Ammo2Rank5", db_con2);
				DynamicFactions[fid][fAmmo2Rank5] = strval(string);
				mysql_fetch_field_row(string, "Ammo2Rank6", db_con2);
				DynamicFactions[fid][fAmmo2Rank6] = strval(string);
				mysql_fetch_field_row(string, "Ammo2Rank7", db_con2);
				DynamicFactions[fid][fAmmo2Rank7] = strval(string);
				mysql_fetch_field_row(string, "Ammo2Rank8", db_con2);
				DynamicFactions[fid][fAmmo2Rank8] = strval(string);
				mysql_fetch_field_row(string, "Ammo2Rank9", db_con2);
				DynamicFactions[fid][fAmmo2Rank9] = strval(string);
				mysql_fetch_field_row(string, "Ammo2Rank10", db_con2);
				DynamicFactions[fid][fAmmo2Rank10] = strval(string);
				mysql_fetch_field_row(string, "Ammo3Rank1", db_con2);
				DynamicFactions[fid][fAmmo3Rank1] = strval(string);
				mysql_fetch_field_row(string, "Ammo3Rank2", db_con2);
				DynamicFactions[fid][fAmmo3Rank2] = strval(string);
				mysql_fetch_field_row(string, "Ammo3Rank3", db_con2);
				DynamicFactions[fid][fAmmo3Rank3] = strval(string);
				mysql_fetch_field_row(string, "Ammo3Rank4", db_con2);
				DynamicFactions[fid][fAmmo3Rank4] = strval(string);
				mysql_fetch_field_row(string, "Ammo3Rank5", db_con2);
				DynamicFactions[fid][fAmmo3Rank5] = strval(string);
				mysql_fetch_field_row(string, "Ammo3Rank6", db_con2);
				DynamicFactions[fid][fAmmo3Rank6] = strval(string);
				mysql_fetch_field_row(string, "Ammo3Rank7", db_con2);
				DynamicFactions[fid][fAmmo3Rank7] = strval(string);
				mysql_fetch_field_row(string, "Ammo3Rank8", db_con2);
				DynamicFactions[fid][fAmmo3Rank8] = strval(string);
				mysql_fetch_field_row(string, "Ammo3Rank9", db_con2);
				DynamicFactions[fid][fAmmo3Rank9] = strval(string);
				mysql_fetch_field_row(string, "Ammo3Rank10", db_con2);
				DynamicFactions[fid][fAmmo3Rank10] = strval(string);
			}
			#if defined DEBUG
				print("[INFO:] Faction weapons data part 2/2 loaded [MySQL]");
			#endif
		}
		case LOAD_DYNAMIC_FACTIONS_WEAPONS:
		{
			new fid;

			mysql_store_result(db_con2);
			
			while(mysql_retrieve_row(db_con2))
			{
				mysql_fetch_field_row(string, "FactionID", db_con2);
				fid = strval(string);
				mysql_fetch_field_row(string, "Gun1Rank1", db_con2);
				DynamicFactions[fid][fGun1Rank1] = strval(string);
				mysql_fetch_field_row(string, "Gun1Rank2", db_con2);
				DynamicFactions[fid][fGun1Rank2] = strval(string);
				mysql_fetch_field_row(string, "Gun1Rank3", db_con2);
				DynamicFactions[fid][fGun1Rank3] = strval(string);
				mysql_fetch_field_row(string, "Gun1Rank4", db_con2);
				DynamicFactions[fid][fGun1Rank4] = strval(string);
				mysql_fetch_field_row(string, "Gun1Rank5", db_con2);
				DynamicFactions[fid][fGun1Rank5] = strval(string);
				mysql_fetch_field_row(string, "Gun1Rank6", db_con2);
				DynamicFactions[fid][fGun1Rank6] = strval(string);
				mysql_fetch_field_row(string, "Gun1Rank7", db_con2);
				DynamicFactions[fid][fGun1Rank7] = strval(string);
				mysql_fetch_field_row(string, "Gun1Rank8", db_con2);
				DynamicFactions[fid][fGun1Rank8] = strval(string);
				mysql_fetch_field_row(string, "Gun1Rank9", db_con2);
				DynamicFactions[fid][fGun1Rank9] = strval(string);
				mysql_fetch_field_row(string, "Gun1Rank10", db_con2);
				DynamicFactions[fid][fGun1Rank10] = strval(string);
				mysql_fetch_field_row(string, "Gun2Rank1", db_con2);
				DynamicFactions[fid][fGun2Rank1] = strval(string);
				mysql_fetch_field_row(string, "Gun2Rank2", db_con2);
				DynamicFactions[fid][fGun2Rank2] = strval(string);
				mysql_fetch_field_row(string, "Gun2Rank3", db_con2);
				DynamicFactions[fid][fGun2Rank3] = strval(string);
				mysql_fetch_field_row(string, "Gun2Rank4", db_con2);
				DynamicFactions[fid][fGun2Rank4] = strval(string);
				mysql_fetch_field_row(string, "Gun2Rank5", db_con2);
				DynamicFactions[fid][fGun2Rank5] = strval(string);
				mysql_fetch_field_row(string, "Gun2Rank6", db_con2);
				DynamicFactions[fid][fGun2Rank6] = strval(string);
				mysql_fetch_field_row(string, "Gun2Rank7", db_con2);
				DynamicFactions[fid][fGun2Rank7] = strval(string);
				mysql_fetch_field_row(string, "Gun2Rank8", db_con2);
				DynamicFactions[fid][fGun2Rank8] = strval(string);
				mysql_fetch_field_row(string, "Gun2Rank9", db_con2);
				DynamicFactions[fid][fGun2Rank9] = strval(string);
				mysql_fetch_field_row(string, "Gun2Rank10", db_con2);
				DynamicFactions[fid][fGun2Rank10] = strval(string);
				mysql_fetch_field_row(string, "Gun3Rank1", db_con2);
				DynamicFactions[fid][fGun3Rank1] = strval(string);
				mysql_fetch_field_row(string, "Gun3Rank2", db_con2);
				DynamicFactions[fid][fGun3Rank2] = strval(string);
				mysql_fetch_field_row(string, "Gun3Rank3", db_con2);
				DynamicFactions[fid][fGun3Rank3] = strval(string);
				mysql_fetch_field_row(string, "Gun3Rank4", db_con2);
				DynamicFactions[fid][fGun3Rank4] = strval(string);
				mysql_fetch_field_row(string, "Gun3Rank5", db_con2);
				DynamicFactions[fid][fGun3Rank5] = strval(string);
				mysql_fetch_field_row(string, "Gun3Rank6", db_con2);
				DynamicFactions[fid][fGun3Rank6] = strval(string);
				mysql_fetch_field_row(string, "Gun3Rank7", db_con2);
				DynamicFactions[fid][fGun3Rank7] = strval(string);
				mysql_fetch_field_row(string, "Gun3Rank8", db_con2);
				DynamicFactions[fid][fGun3Rank8] = strval(string);
				mysql_fetch_field_row(string, "Gun3Rank9", db_con2);
				DynamicFactions[fid][fGun3Rank9] = strval(string);
				mysql_fetch_field_row(string, "Gun3Rank10", db_con2);
				DynamicFactions[fid][fGun3Rank10] = strval(string);
			}
			#if defined DEBUG
				print("[INFO:] Faction weapons data part 1/2 loaded [MySQL]");
			#endif
		}
		case RELOAD_DYNAMIC_FACTIONS:
		{
			mysql_store_result(db_con2);
		
			new i = 0;

			while(mysql_retrieve_row(db_con2))
			{
				mysql_fetch_field_row(string, "Name", db_con2);
				format(DynamicFactions[i][Name], 50, string);
				mysql_fetch_field_row(string, "Rank1", db_con2);
				format(DynamicFactions[i][fRank1], 35, string);
				mysql_fetch_field_row(string, "Rank2", db_con2);
				format(DynamicFactions[i][fRank2], 35, string);
				mysql_fetch_field_row(string, "Rank3", db_con2);
				format(DynamicFactions[i][fRank3], 35, string);
				mysql_fetch_field_row(string, "Rank4", db_con2);
				format(DynamicFactions[i][fRank4], 35, string);
				mysql_fetch_field_row(string, "Rank5", db_con2);
				format(DynamicFactions[i][fRank5], 35, string);
				mysql_fetch_field_row(string, "Rank6", db_con2);
				format(DynamicFactions[i][fRank6], 35, string);
				mysql_fetch_field_row(string, "Rank7", db_con2);
				format(DynamicFactions[i][fRank7], 35, string);
				mysql_fetch_field_row(string, "Rank8", db_con2);
				format(DynamicFactions[i][fRank8], 35, string);
				mysql_fetch_field_row(string, "Rank9", db_con2);
				format(DynamicFactions[i][fRank9], 35, string);
				mysql_fetch_field_row(string, "Rank10", db_con2);
				format(DynamicFactions[i][fRank10], 35, string);
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
		case LOAD_DYNAMIC_FACTIONS:
		{
			#if defined DEBUG
				print("[INFO:] Factions loading started...");
			#endif
			
			mysql_store_result(db_con2);
			
			if(mysql_num_rows(db_con2) == 0)
			{
				print("[INFO:] Brak wpisów we frakcjach !");
			}
			
			new i, Float:px, Float:py, Float:pz;
			i = 0;
			
			while(mysql_retrieve_row(db_con2))
			{
				mysql_fetch_field_row(string, "Name", db_con2);
				format(DynamicFactions[i][Name], 50, string);
				mysql_fetch_field_row(string, "IsEnabled", db_con2);
				DynamicFactions[i][IsEnabled] = strval(string);
				mysql_fetch_field_row(string, "X", db_con2);
				DynamicFactions[i][m_fX] = floatstr(string);
				mysql_fetch_field_row(string, "Y", db_con2);
				DynamicFactions[i][m_fY] = floatstr(string);
				mysql_fetch_field_row(string, "Z", db_con2);
				DynamicFactions[i][m_fZ] = floatstr(string);
				mysql_fetch_field_row(string, "Bank", db_con2);
				DynamicFactions[i][fBank] = strval(string);
				mysql_fetch_field_row(string, "Rank1", db_con2);
				format(DynamicFactions[i][fRank1], 35, string);
				mysql_fetch_field_row(string, "Rank2", db_con2);
				format(DynamicFactions[i][fRank2], 35, string);
				mysql_fetch_field_row(string, "Rank3", db_con2);
				format(DynamicFactions[i][fRank3], 35, string);
				mysql_fetch_field_row(string, "Rank4", db_con2);
				format(DynamicFactions[i][fRank4], 35, string);
				mysql_fetch_field_row(string, "Rank5", db_con2);
				format(DynamicFactions[i][fRank5], 35, string);
				mysql_fetch_field_row(string, "Rank6", db_con2);
				format(DynamicFactions[i][fRank6], 35, string);
				mysql_fetch_field_row(string, "Rank7", db_con2);
				format(DynamicFactions[i][fRank7], 35, string);
				mysql_fetch_field_row(string, "Rank8", db_con2);
				format(DynamicFactions[i][fRank8], 35, string);
				mysql_fetch_field_row(string, "Rank9", db_con2);
				format(DynamicFactions[i][fRank9], 35, string);
				mysql_fetch_field_row(string, "Rank10", db_con2);
				format(DynamicFactions[i][fRank10], 35, string);
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
				mysql_fetch_field_row(string, "Color", db_con2);
				format(DynamicFactions[i][fColor], 128, string);
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
					DynamicFactions[i][WFactoryCPSafeID] = CreateDynamicCP( px+WFCP[5][0], py+WFCP[5][1], pz+WFCP[5][2], 2.0, 0, 0, -1, 5.0 ); // Safe
				}
				// printf("fCP ID: %d, X %f, Y %f, Z %f", DynamicFactions[i][fCP],DynamicFactions[i][fXDuty],DynamicFactions[i][fYDuty],DynamicFactions[i][fZDuty]);
				// printf("[FRAKCJE DYNAMICZNE:] Nazwa frakcji: %s, Typ: %d, ID: %d",DynamicFactions[i][Name],DynamicFactions[i][fType],i);

				i++;
			}
			#if defined DEBUG
				print("[INFO:] Factions loaded [MySQL]");
			#endif
		}
		case LOAD_CARS_CPARTS:
		{
			mysql_store_result(db_con2);
			
			new i = 0;
			
			while(mysql_retrieve_row(db_con2))
			{
				mysql_fetch_field_row(string, "ID", db_con2);
				if(i+1 == strval(string))
				{
					mysql_fetch_field_row(string, "CustomObj1Model", db_con2);
					gVehData[i][CustomObj1Model] = strval(string);
					mysql_fetch_field_row(string, "CustomObj1On", db_con2);
					gVehData[i][CustomObj1On] = strval(string);
					mysql_fetch_field_row(string, "CustomObj1X", db_con2);
					gVehData[i][CustomObj1][0] = floatstr(string);
					mysql_fetch_field_row(string, "CustomObj1Y", db_con2);
					gVehData[i][CustomObj1][1] = floatstr(string);
					mysql_fetch_field_row(string, "CustomObj1Z", db_con2);
					gVehData[i][CustomObj1][2] = floatstr(string);
					mysql_fetch_field_row(string, "CustomObj1Xr", db_con2);
					gVehData[i][CustomObj1][3] = floatstr(string);
					mysql_fetch_field_row(string, "CustomObj1Yr", db_con2);
					gVehData[i][CustomObj1][4] = floatstr(string);
					mysql_fetch_field_row(string, "CustomObj1Zr", db_con2);
					gVehData[i][CustomObj1][5] = floatstr(string);
					mysql_fetch_field_row(string, "CustomObj2Model", db_con2);
					gVehData[i][CustomObj2Model] = strval(string);
					mysql_fetch_field_row(string, "CustomObj2On", db_con2);
					gVehData[i][CustomObj2On] = strval(string);
					mysql_fetch_field_row(string, "CustomObj2X", db_con2);
					gVehData[i][CustomObj2][0] = floatstr(string);
					mysql_fetch_field_row(string, "CustomObj2Y", db_con2);
					gVehData[i][CustomObj2][1] = floatstr(string);
					mysql_fetch_field_row(string, "CustomObj2Z", db_con2);
					gVehData[i][CustomObj2][2] = floatstr(string);
					mysql_fetch_field_row(string, "CustomObj2Xr", db_con2);
					gVehData[i][CustomObj2][3] = floatstr(string);
					mysql_fetch_field_row(string, "CustomObj2Yr", db_con2);
					gVehData[i][CustomObj2][4] = floatstr(string);
					mysql_fetch_field_row(string, "CustomObj2Zr", db_con2);
					gVehData[i][CustomObj2][5] = floatstr(string);
					mysql_fetch_field_row(string, "CustomObj3Model", db_con2);
					gVehData[i][CustomObj3Model] = strval(string);
					mysql_fetch_field_row(string, "CustomObj3On", db_con2);
					gVehData[i][CustomObj3On] = strval(string);
					mysql_fetch_field_row(string, "CustomObj3X", db_con2);
					gVehData[i][CustomObj3][0] = floatstr(string);
					mysql_fetch_field_row(string, "CustomObj3Y", db_con2);
					gVehData[i][CustomObj3][1] = floatstr(string);
					mysql_fetch_field_row(string, "CustomObj3Z", db_con2);
					gVehData[i][CustomObj3][2] = floatstr(string);
					mysql_fetch_field_row(string, "CustomObj3Xr", db_con2);
					gVehData[i][CustomObj3][3] = floatstr(string);
					mysql_fetch_field_row(string, "CustomObj3Yr", db_con2);
					gVehData[i][CustomObj3][4] = floatstr(string);
					mysql_fetch_field_row(string, "CustomObj3Zr", db_con2);
					gVehData[i][CustomObj3][5] = floatstr(string);
					mysql_fetch_field_row(string, "CustomObj4Model", db_con2);
					gVehData[i][CustomObj4Model] = strval(string);
					mysql_fetch_field_row(string, "CustomObj4On", db_con2);
					gVehData[i][CustomObj4On] = strval(string);
					mysql_fetch_field_row(string, "CustomObj4X", db_con2);
					gVehData[i][CustomObj4][0] = floatstr(string);
					mysql_fetch_field_row(string, "CustomObj4Y", db_con2);
					gVehData[i][CustomObj4][1] = floatstr(string);
					mysql_fetch_field_row(string, "CustomObj4Z", db_con2);
					gVehData[i][CustomObj4][2] = floatstr(string);
					mysql_fetch_field_row(string, "CustomObj4Xr", db_con2);
					gVehData[i][CustomObj4][3] = floatstr(string);
					mysql_fetch_field_row(string, "CustomObj4Yr", db_con2);
					gVehData[i][CustomObj4][4] = floatstr(string);
					mysql_fetch_field_row(string, "CustomObj4Zr", db_con2);
					gVehData[i][CustomObj4][5] = floatstr(string);
					mysql_fetch_field_row(string, "CustomObj5Model", db_con2);
					gVehData[i][CustomObj5Model] = strval(string);
					mysql_fetch_field_row(string, "CustomObj5On", db_con2);
					gVehData[i][CustomObj5On] = strval(string);
					mysql_fetch_field_row(string, "CustomObj5X", db_con2);
					gVehData[i][CustomObj5][0] = floatstr(string);
					mysql_fetch_field_row(string, "CustomObj5Y", db_con2);
					gVehData[i][CustomObj5][1] = floatstr(string);
					mysql_fetch_field_row(string, "CustomObj5Z", db_con2);
					gVehData[i][CustomObj5][2] = floatstr(string);
					mysql_fetch_field_row(string, "CustomObj5Xr", db_con2);
					gVehData[i][CustomObj5][3] = floatstr(string);
					mysql_fetch_field_row(string, "CustomObj5Yr", db_con2);
					gVehData[i][CustomObj5][4] = floatstr(string);
					mysql_fetch_field_row(string, "CustomObj5Zr", db_con2);
					gVehData[i][CustomObj5][5] = floatstr(string);
					mysql_fetch_field_row(string, "CustomObj6Model", db_con2);
					gVehData[i][CustomObj6Model] = strval(string);
					mysql_fetch_field_row(string, "CustomObj6On", db_con2);
					gVehData[i][CustomObj6On] = strval(string);
					mysql_fetch_field_row(string, "CustomObj6X", db_con2);
					gVehData[i][CustomObj6][0] = floatstr(string);
					mysql_fetch_field_row(string, "CustomObj6Y", db_con2);
					gVehData[i][CustomObj6][1] = floatstr(string);
					mysql_fetch_field_row(string, "CustomObj6Z", db_con2);
					gVehData[i][CustomObj6][2] = floatstr(string);
					mysql_fetch_field_row(string, "CustomObj6Xr", db_con2);
					gVehData[i][CustomObj6][3] = floatstr(string);
					mysql_fetch_field_row(string, "CustomObj6Yr", db_con2);
					gVehData[i][CustomObj6][4] = floatstr(string);
					mysql_fetch_field_row(string, "CustomObj6Zr", db_con2);
					gVehData[i][CustomObj6][5] = floatstr(string);
					mysql_fetch_field_row(string, "CustomObj7Model", db_con2);
					gVehData[i][CustomObj7Model] = strval(string);
					mysql_fetch_field_row(string, "CustomObj7On", db_con2);
					gVehData[i][CustomObj7On] = strval(string);
					mysql_fetch_field_row(string, "CustomObj7X", db_con2);
					gVehData[i][CustomObj7][0] = floatstr(string);
					mysql_fetch_field_row(string, "CustomObj7Y", db_con2);
					gVehData[i][CustomObj7][1] = floatstr(string);
					mysql_fetch_field_row(string, "CustomObj7Z", db_con2);
					gVehData[i][CustomObj7][2] = floatstr(string);
					mysql_fetch_field_row(string, "CustomObj7Xr", db_con2);
					gVehData[i][CustomObj7][3] = floatstr(string);
					mysql_fetch_field_row(string, "CustomObj7Yr", db_con2);
					gVehData[i][CustomObj7][4] = floatstr(string);
					mysql_fetch_field_row(string, "CustomObj7Zr", db_con2);
					gVehData[i][CustomObj7][5] = floatstr(string);

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
		}
		case LOAD_CARS_CUSTOMIZE:
		{
			mysql_store_result(db_con2);

			new i = 0;

			while(mysql_retrieve_row(db_con2))
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

				/*AddVehicleComponent(i+1, gVehData[i][mVehSpoiler]);
				AddVehicleComponent(i+1, gVehData[i][mVehHood]);
				AddVehicleComponent(i+1, gVehData[i][mVehRoof]);
				AddVehicleComponent(i+1, gVehData[i][mVehSideskirt]);
				AddVehicleComponent(i+1, gVehData[i][mVehLamps]);
				AddVehicleComponent(i+1, gVehData[i][mVehNitro]);
				AddVehicleComponent(i+1, gVehData[i][mVehExhaust]);
				AddVehicleComponent(i+1, gVehData[i][mVehWheels]);
				AddVehicleComponent(i+1, gVehData[i][mVehStereo]);
				AddVehicleComponent(i+1, gVehData[i][mVehHydraulics]);
				AddVehicleComponent(i+1, gVehData[i][mVehFrontBumper]);
				AddVehicleComponent(i+1, gVehData[i][mVehRearBumper]);
				AddVehicleComponent(i+1, gVehData[i][mVehVentLeft]);
				AddVehicleComponent(i+1, gVehData[i][mVehVentRight]);*/
				if(gVehData[i][mVehModel] != 594)
				{
					if(gVehData[i][mVehSpoiler] != 0)
						AddVehicleComponent(i+1, gVehData[i][mVehSpoiler]);
					if(gVehData[i][mVehHood] != 0)
						AddVehicleComponent(i+1, gVehData[i][mVehHood]);
					if(gVehData[i][mVehRoof] != 0)
						AddVehicleComponent(i+1, gVehData[i][mVehRoof]);
					if(gVehData[i][mVehSideskirt] != 0)
						AddVehicleComponent(i+1, gVehData[i][mVehSideskirt]);
					if(gVehData[i][mVehLamps] != 0)
						AddVehicleComponent(i+1, gVehData[i][mVehLamps]);
					if(gVehData[i][mVehNitro] != 0)
						AddVehicleComponent(i+1, gVehData[i][mVehNitro]);
					if(gVehData[i][mVehExhaust] != 0)
						AddVehicleComponent(i+1, gVehData[i][mVehExhaust]);
					if(gVehData[i][mVehWheels] != 0)
						AddVehicleComponent(i+1, gVehData[i][mVehWheels]);
					if(gVehData[i][mVehStereo] != 0)
						AddVehicleComponent(i+1, gVehData[i][mVehStereo]);
					if(gVehData[i][mVehHydraulics] != 0)
						AddVehicleComponent(i+1, gVehData[i][mVehHydraulics]);
					if(gVehData[i][mVehFrontBumper] != 0)
						AddVehicleComponent(i+1, gVehData[i][mVehFrontBumper]);
					if(gVehData[i][mVehRearBumper] != 0)
						AddVehicleComponent(i+1, gVehData[i][mVehRearBumper]);
					if(gVehData[i][mVehVentLeft] != 0)
						AddVehicleComponent(i+1, gVehData[i][mVehVentLeft]);
					if(gVehData[i][mVehVentRight] != 0)
						AddVehicleComponent(i+1, gVehData[i][mVehVentRight]);
				}			

				i++;
			}
			#if defined DEBUG
				print("[INFO:] Dynamic vehicles customize loaded [MySQL]");
			#endif
		}
		case LOAD_GANG_ZONES:
		{
			mysql_store_result(db_con2);
			
			new i = 0;
			
			while(mysql_retrieve_row(db_con2))
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

			//wp_mysql_free_result(db_con2);
		}
		case LOAD_DYNAMIC_CARS:
		{

			new i, id, lightsd;
			i = 0;

			new enginedyn,lights,alarm,doors,bonnet,boot,objective;

			mysql_store_result(db_con2);
			
			while(mysql_retrieve_row(db_con2))
			{
				mysql_fetch_field_row(string, "ID", db_con2);
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
				mysql_fetch_field_row(string, "VehPaintJob", db_con2);
				gVehData[i][mVehPaintJob] = strval(string);
				mysql_fetch_field_row(string, "VehFaction", db_con2);
				gVehData[i][mVehFaction] = strval(string);
				mysql_fetch_field_row(string, "VehVinNo", db_con2);
				gVehData[i][mVehVinNo] = strval(string);
				mysql_fetch_field_row(string, "VehType", db_con2);
				gVehData[i][mVehType] = strval(string);
				mysql_fetch_field_row(string, "VehOwned", db_con2);
				gVehData[i][mVehOwned] = strval(string);
				mysql_fetch_field_row(string, "Owner", db_con2);
				format(gVehData[i][Owner], MAX_PLAYER_NAME, string);
				mysql_fetch_field_row(string, "Price", db_con2);
				gVehData[i][Price] = strval(string);
				mysql_fetch_field_row(string, "Renter", db_con2);
				format(gVehData[i][mRenter], MAX_PLAYER_NAME, string);
				mysql_fetch_field_row(string, "RentPrice", db_con2);
				gVehData[i][mRentPrice] = strval(string);
				mysql_fetch_field_row(string, "RentPenalty", db_con2);
				gVehData[i][mRentPenalty] = strval(string);
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
				mysql_fetch_field_row(string, "Item1param5", db_con2);
				format(gVehData[i][VItem1param5], 64, string);
				mysql_fetch_field_row(string, "Item2param5", db_con2);
				format(gVehData[i][VItem2param5], 64, string);
				mysql_fetch_field_row(string, "Item3param5", db_con2);
				format(gVehData[i][VItem3param5], 64, string);
				mysql_fetch_field_row(string, "Item4param5", db_con2);
				format(gVehData[i][VItem4param5], 64, string);
				mysql_fetch_field_row(string, "Item5param5", db_con2);
				format(gVehData[i][VItem5param5], 64, string);
				mysql_fetch_field_row(string, "Item6param5", db_con2);
				format(gVehData[i][VItem6param5], 64, string);
				mysql_fetch_field_row(string, "Item7param5", db_con2);
				format(gVehData[i][VItem7param5], 64, string);
				mysql_fetch_field_row(string, "Item8param5", db_con2);
				format(gVehData[i][VItem8param5], 64, string);
				mysql_fetch_field_row(string, "Item9param5", db_con2);
				format(gVehData[i][VItem9param5], 64, string);
				mysql_fetch_field_row(string, "Item10param5", db_con2);
				format(gVehData[i][VItem10param5], 64, string);
				mysql_fetch_field_row(string, "Item11param5", db_con2);
				format(gVehData[i][VItem11param5], 64, string);
				mysql_fetch_field_row(string, "Item12param5", db_con2);
				format(gVehData[i][VItem12param5], 64, string);
				mysql_fetch_field_row(string, "Item13param5", db_con2);
				format(gVehData[i][VItem13param5], 64, string);
				mysql_fetch_field_row(string, "Item14param5", db_con2);
				format(gVehData[i][VItem14param5], 64, string);
				mysql_fetch_field_row(string, "Item15param5", db_con2);
				format(gVehData[i][VItem15param5], 64, string);
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
				{
					format(string, sizeof(string), "SA-000%d", gVehData[i][CarSerial]);
				}
				if(gVehData[i][CarSerial] > 10 && gVehData[i][CarSerial] < 100)
				{
					format(string, sizeof(string), "SA-00%d", gVehData[i][CarSerial]);
				}
				if(gVehData[i][CarSerial] > 100 && gVehData[i][CarSerial] < 1000)
				{
					format(string, sizeof(string), "SA-0%d", gVehData[i][CarSerial]);
				}
				if(gVehData[i][CarSerial] > 1000)
				{
					format(string, sizeof(string), "SA-%d", gVehData[i][CarSerial]);
				}

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
					}
				}
				
				RefreshVehicleDescription(id);
				
				if(gVehData[i][mVehPaintJob])
				{
					ChangeVehiclePaintjob(id, gVehData[i][mVehPaintJob]);
				}
				
				if(gVehData[i][mVehFaction] != 255)
				{
					if(DynamicFactions[gVehData[i][mVehFaction]][fType] == 6)
					{
						gVehData[i][Veh3DTaxiNfo] = CreateDynamic3DTextLabel("TAXI", COLOR_YELLOW, 0.0, 0.0, 1.0, 20.0, INVALID_PLAYER_ID, id, 1);
						if( DynamicFactions[ gVehData[i][mVehFaction] ][fTaxiEnterCost] > 0 )
							format( string, sizeof(string), "cena za KM: $%d + $%d", DynamicFactions[ gVehData[i][mVehFaction] ][fTaxiKMCost], DynamicFactions[ gVehData[i][mVehFaction] ][fTaxiEnterCost] );
						else
							format( string, sizeof(string), "cena za KM: $%d", DynamicFactions[ gVehData[i][mVehFaction] ][fTaxiKMCost] );
						gVehData[i][Veh3DTaxiNfo2] = CreateDynamic3DTextLabel(string, COLOR_YELLOW, 0.0, 0.0, 0.8, 20.0, INVALID_PLAYER_ID, id, 1);
					}
				}
				
				// Predefiniowane opisy autobusów dla botów
				if(i+1 == 1999)
				{
					UpdateDynamic3DTextLabelText(BusRoute[i], COLOR_LIGHTYELLOW, gBusTrackDesc[0]);
				}
				else if(i+1 == 1998)
				{
					UpdateDynamic3DTextLabelText(BusRoute[i], COLOR_LIGHTYELLOW, "| MG->BB->DM->MG");
				}
				
				i++;
				// }
				// else
				// {
					// format(string, sizeof(string), "INSERT INTO `samp_vehicles` (`ID`) VALUES ('%d')", i+1);
					// wp_mysql_query(string);

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
		}
		case LOAD_ITEM_FACTORIES:
		{
			new i = 0;
			
			mysql_store_result(db_con2);
			
			while(mysql_retrieve_row(db_con2))
			{
				mysql_fetch_field_row(string, "name", db_con2);
				format(gItemFactories[i][fName], 128, string);
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
			//wp_mysql_free_result(db_con2);
			#if defined DEBUG
				print("[INFO:] Loaded item factories [MySQL]");
			#endif
			return 1;
		}
		case LOAD_CUSTOM_OBJECTS:
		{
			new i = 0;

			mysql_store_result(db_con2);
			
			while(mysql_retrieve_row(db_con2))
			{
				mysql_fetch_field_row(string, "ID", db_con2);
				i = strval(string)-1;
				mysql_fetch_field_row(string, "cstSlotUsed", db_con2);
				if(strval(string))
					gCustomObj[i][cstSlotUsed] = true;
				else
					gCustomObj[i][cstSlotUsed] = false;
				mysql_fetch_field_row(string, "cstObjModel", db_con2);
				gCustomObj[i][cstObjModel] = strval(string);
				mysql_fetch_field_row(string, "cstObjVW", db_con2);
				gCustomObj[i][cstObjVW] = strval(string);
				mysql_fetch_field_row(string, "cstObjInt", db_con2);
				gCustomObj[i][cstObjInt] = strval(string);		
				mysql_fetch_field_row(string, "cstObjOwner", db_con2);		
				format(gCustomObj[i][cstObjOwner], MAX_PLAYER_NAME, "%s", string);
				
				new Float:x, Float:y, Float:z, Float:xr, Float:yr, Float:zr;
				mysql_fetch_field_row(string, "cstObjX", db_con2);
				x = floatstr(string);
				mysql_fetch_field_row(string, "cstObjY", db_con2);
				y = floatstr(string);
				mysql_fetch_field_row(string, "cstObjZ", db_con2);
				z = floatstr(string);
				mysql_fetch_field_row(string, "cstObjRX", db_con2);
				xr = floatstr(string);
				mysql_fetch_field_row(string, "cstObjRY", db_con2);
				yr = floatstr(string);
				mysql_fetch_field_row(string, "cstObjRZ", db_con2);
				zr = floatstr(string);
				
				if(gCustomObj[i][cstSlotUsed] && gCustomObj[i][cstObjModel] != 0)
				{
					
					gCustomObj[i][cstObjID] = CreateDynamicObject(gCustomObj[i][cstObjModel], x, y, z, xr, yr, zr, gCustomObj[i][cstObjVW], gCustomObj[i][cstObjInt], -1, 600.0);
					SetDynamicObjectRot(gCustomObj[i][cstObjID], xr, yr, zr);
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
			#if defined DEBUG
				print("[INFO:] Custom objects loaded [MySQL]");
			#endif
		}
		case LOAD_HOUSES_DATA:
		{			
			new i = 0;

			mysql_store_result(db_con2);
			
			while(mysql_retrieve_row(db_con2))
			{				
				mysql_fetch_field_row(string, "Description", db_con2);
				format(HousesData[i][mDescription], 64, "%s", string);
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
			//wp_mysql_free_result(db_con2);
		}
		case LOAD_HOUSES_ITEMS:
		{
			new i = 0;
			
			mysql_store_result(db_con2);
			
			while(mysql_retrieve_row(db_con2))
			{
				mysql_fetch_field_row(string, "HItem1", db_con2);
				Houses[i][HItem1] = strval(string);
				mysql_fetch_field_row(string, "HItem2", db_con2);
				Houses[i][HItem2] = strval(string);
				mysql_fetch_field_row(string, "HItem3", db_con2);
				Houses[i][HItem3] = strval(string);
				mysql_fetch_field_row(string, "HItem4", db_con2);
				Houses[i][HItem4] = strval(string);
				mysql_fetch_field_row(string, "HItem5", db_con2);
				Houses[i][HItem5] = strval(string);
				mysql_fetch_field_row(string, "HItem1type", db_con2);
				Houses[i][HItem1type] = strval(string);
				mysql_fetch_field_row(string, "HItem2type", db_con2);
				Houses[i][HItem2type] = strval(string);
				mysql_fetch_field_row(string, "HItem3type", db_con2);
				Houses[i][HItem3type] = strval(string);
				mysql_fetch_field_row(string, "HItem4type", db_con2);
				Houses[i][HItem4type] = strval(string);
				mysql_fetch_field_row(string, "HItem5type", db_con2);
				Houses[i][HItem5type] = strval(string);
				mysql_fetch_field_row(string, "HItem1param", db_con2);
				Houses[i][HItem1param] = strval(string);
				mysql_fetch_field_row(string, "HItem2param", db_con2);
				Houses[i][HItem2param] = strval(string);
				mysql_fetch_field_row(string, "HItem3param", db_con2);
				Houses[i][HItem3param] = strval(string);
				mysql_fetch_field_row(string, "HItem4param", db_con2);
				Houses[i][HItem4param] = strval(string);
				mysql_fetch_field_row(string, "HItem5param", db_con2);
				Houses[i][HItem5param] = strval(string);
				mysql_fetch_field_row(string, "HItem1param2", db_con2);
				Houses[i][HItem1param2] = strval(string);
				mysql_fetch_field_row(string, "HItem2param2", db_con2);
				Houses[i][HItem2param2] = strval(string);
				mysql_fetch_field_row(string, "HItem3param2", db_con2);
				Houses[i][HItem3param2] = strval(string);
				mysql_fetch_field_row(string, "HItem4param2", db_con2);
				Houses[i][HItem4param2] = strval(string);
				mysql_fetch_field_row(string, "HItem5param2", db_con2);
				Houses[i][HItem5param2] = strval(string);
				mysql_fetch_field_row(string, "HItem1param3", db_con2);
				Houses[i][HItem1param3] = strval(string);
				mysql_fetch_field_row(string, "HItem2param3", db_con2);
				Houses[i][HItem2param3] = strval(string);
				mysql_fetch_field_row(string, "HItem3param3", db_con2);
				Houses[i][HItem3param3] = strval(string);
				mysql_fetch_field_row(string, "HItem4param3", db_con2);
				Houses[i][HItem4param3] = strval(string);
				mysql_fetch_field_row(string, "HItem5param3", db_con2);
				Houses[i][HItem5param3] = strval(string);
				mysql_fetch_field_row(string, "HItem1param4", db_con2);
				Houses[i][HItem1param4] = strval(string);
				mysql_fetch_field_row(string, "HItem2param4", db_con2);
				Houses[i][HItem2param4] = strval(string);
				mysql_fetch_field_row(string, "HItem3param4", db_con2);
				Houses[i][HItem3param4] = strval(string);
				mysql_fetch_field_row(string, "HItem4param4", db_con2);
				Houses[i][HItem4param4] = strval(string);
				mysql_fetch_field_row(string, "HItem5param4", db_con2);
				Houses[i][HItem5param4] = strval(string);
				mysql_fetch_field_row(string, "HItem1param5", db_con2);
				format(Houses[i][HItem1param5], 64, string);
				mysql_fetch_field_row(string, "HItem2param5", db_con2);
				format(Houses[i][HItem2param5], 64, string);
				mysql_fetch_field_row(string, "HItem3param5", db_con2);
				format(Houses[i][HItem3param5], 64, string);
				mysql_fetch_field_row(string, "HItem4param5", db_con2);
				format(Houses[i][HItem4param5], 64, string);
				mysql_fetch_field_row(string, "HItem5param5", db_con2);
				format(Houses[i][HItem5param5], 64, string);
				mysql_fetch_field_row(string, "HItem1param6", db_con2);
				Houses[i][HItem1param6] = strval(string);
				mysql_fetch_field_row(string, "HItem2param6", db_con2);
				Houses[i][HItem2param6] = strval(string);
				mysql_fetch_field_row(string, "HItem3param6", db_con2);
				Houses[i][HItem3param6] = strval(string);
				mysql_fetch_field_row(string, "HItem4param6", db_con2);
				Houses[i][HItem4param6] = strval(string);
				mysql_fetch_field_row(string, "HItem5param6", db_con2);
				Houses[i][HItem5param6] = strval(string);
				i++;
			}
			//wp_mysql_free_result(db_con2);
			#if defined DEBUG
				print("[INFO:] Houses items loaded [MySQL]");
			#endif
		}
		case LOAD_BUILDINGS:
		{
			new i = 0;
			
			mysql_store_result(db_con2);
			
			while(mysql_retrieve_row(db_con2))
			{
				mysql_fetch_field_row(string, "BuildingName", db_con2);
				format(Building[i][BuildingName], 128, string);
				mysql_fetch_field_row(string, "FactionOwnerId", db_con2);
				Building[i][FactionOwnerId] = strval(string);
				mysql_fetch_field_row(string, "Cash", db_con2);
				Building[i][Cash] = strval(string);
				mysql_fetch_field_row(string, "StreetNo", db_con2);
				Building[i][StreetNo] = strval(string);
				mysql_fetch_field_row(string, "Price", db_con2);
				Building[i][Price] = strval(string);
				mysql_fetch_field_row(string, "ForSale", db_con2);
				Building[i][ForSale] = strval(string);
				mysql_fetch_field_row(string, "EnterX", db_con2);
				Building[i][EnterX] = floatstr(string);
				mysql_fetch_field_row(string, "EnterY", db_con2);
				Building[i][EnterY] = floatstr(string);
				mysql_fetch_field_row(string, "EnterZ", db_con2);
				Building[i][EnterZ] = floatstr(string);
				mysql_fetch_field_row(string, "EntranceFee", db_con2);
				Building[i][EntranceFee] = strval(string);
				mysql_fetch_field_row(string, "EnterWorld", db_con2);
				Building[i][EnterWorld] = strval(string);
				mysql_fetch_field_row(string, "EnterInterior", db_con2);
				Building[i][EnterInterior] = strval(string);
				mysql_fetch_field_row(string, "EnterAngle", db_con2);
				Building[i][EnterAngle] = floatstr(string);
				mysql_fetch_field_row(string, "ExitX", db_con2);
				Building[i][ExitX] = floatstr(string);
				mysql_fetch_field_row(string, "ExitY", db_con2);
				Building[i][ExitY] = floatstr(string);
				mysql_fetch_field_row(string, "ExitZ", db_con2);
				Building[i][ExitZ] = floatstr(string);
				mysql_fetch_field_row(string, "ExitInterior", db_con2);
				Building[i][ExitInterior] = strval(string);
				mysql_fetch_field_row(string, "ExitAngle", db_con2);
				Building[i][ExitAngle] = floatstr(string);
				mysql_fetch_field_row(string, "Locked", db_con2);
				Building[i][Locked] = strval(string);
				mysql_fetch_field_row(string, "Opened", db_con2);
				Building[i][Opened] = strval(string);
				mysql_fetch_field_row(string, "Closed", db_con2);
				Building[i][Closed] = strval(string);
				mysql_fetch_field_row(string, "ObjectID", db_con2);
				Building[i][ObjectID] = strval(string);
				mysql_fetch_field_row(string, "BuildingType", db_con2);
				Building[i][BuildingType] = strval(string);
				mysql_fetch_field_row(string, "ShowIcon", db_con2);
				Building[i][ShowIcon] = strval(string);
				mysql_fetch_field_row(string, "IconType", db_con2);
				Building[i][IconType] = strval(string);
				mysql_fetch_field_row(string, "BuildingPlaced", db_con2);
				Building[i][mBuildingPlaced] = strval(string);
				
				RefreshBuildingDescription(i);				
				
				//format(string, sizeof(string), "ID: %d<br />Description: %s", i, Building[i][BuildingName]);
				//addDmapIcon(Building[i][EnterX], Building[i][EnterY], 32, "Building", string);
				
				i++;
			}
			#if defined DEBUG
				print("[INFO:] Buildings loaded [MySQL]");
			#endif
		}
		case LOAD_HOUSES:
		{
			new i = 0;

			mysql_store_result(db_con2);
			
			while(mysql_retrieve_row(db_con2))
			{
				mysql_fetch_field_row(string, "Description", db_con2);
				format(Houses[i][Description], 128, string);
				mysql_fetch_field_row(string, "Owner", db_con2);
				format(Houses[i][Owner], MAX_PLAYER_NAME, string);
				mysql_fetch_field_row(string, "UID", db_con2);
				Houses[i][HUID] = strval(string);
				mysql_fetch_field_row(string, "StreetNo", db_con2);
				Houses[i][StreetNo] = strval(string);
				mysql_fetch_field_row(string, "Renter", db_con2);
				format(Houses[i][HRenter], MAX_PLAYER_NAME, string);
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

				if( Houses[i][HRadio1Bought] )
					Houses[i][HRadio1Obj] = CreateDynamicObject(O_RADIO_T_1, Houses[i][HRadio1X], Houses[i][HRadio1Y], Houses[i][HRadio1Z]-1.0, 0, 0, Houses[i][HRadio1Angle], i, Houses[i][ExitInterior]);
				
				RefreshHouseDescription(i);
				
				//format(string, sizeof(string), "ID: %d<br />Owner: %s<br />Description: %s", i, Houses[i][Owner], Houses[i][Description]);
				//addDmapIcon(Houses[i][EnterX], Houses[i][EnterY], 31, "House", string);
				
				i++;
			}
			
			#if defined DEBUG
				print("[INFO:] Houses loaded [MySQL]");
			#endif
		}
		case LOAD_BUSINESSES:
		{
			new i = 0;

			mysql_store_result(db_con2);
			
			while(mysql_retrieve_row(db_con2))
			{
				mysql_fetch_field_row(string, "BusinessName", db_con2);
				format(Businesses[i][BusinessName], 128, string);
				mysql_fetch_field_row(string, "Owner", db_con2);
				format(Businesses[i][Owner], MAX_PLAYER_NAME, string);
				mysql_fetch_field_row(string, "Faction", db_con2);
				Businesses[i][mFaction] = strval(string);
				mysql_fetch_field_row(string, "StreetNo", db_con2);
				Businesses[i][StreetNo] = strval(string);
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

				RefreshBizDescription(i);
				
				//format(string, sizeof(string), "ID: %d<br />Owner: %s<br />Name: %s", i, Businesses[i][Owner], Businesses[i][BusinessName]);
				//addDmapIcon(Businesses[i][EnterX], Businesses[i][EnterY], 32, Businesses[i][BusinessName], string);
				
				i++;
			}
			#if defined DEBUG
				print("[INFO:] Businesses loaded [MySQL]");
			#endif
		}
		case LOAD_BUS_TRACKS:
		{
			new i = 0;
			
			mysql_store_result(db_con2);

			while(mysql_retrieve_row(db_con2))
			{
				mysql_fetch_field_row(string, "Enabled", db_con2);
				gBusTrackEnabled[i] = strval(string);
				mysql_fetch_field_row(string, "StartArea", db_con2);
				gBusTrackStartArea[i] = strval(string);
				mysql_fetch_field_row(string, "Description", db_con2);
				format(gBusTrackDesc[i], 64, "%d | %s", i, string);
				mysql_fetch_field_row(string, "Cost", db_con2);
				gBusTrackTicketCost[i] = strval(string);
				i++;
			}
			#if defined DEBUG
				printf("[INFO:] Bus tracks data part 1/2 loaded [MySQL]");
			#endif
		}
		case LOAD_BUS_TRACKS_DATA:
		{
			new trkid, cpid;

			mysql_store_result(db_con2);
			
			while(mysql_retrieve_row(db_con2))
			{				
				mysql_fetch_field_row(string, "TrackID", db_con2);
				trkid = strval(string);
				mysql_fetch_field_row(string, "CPID", db_con2);
				cpid = strval(string);
				mysql_fetch_field_row(string, "CPX", db_con2);
				gBusTrackCpX[trkid][cpid] = floatstr(string);
				mysql_fetch_field_row(string, "CPY", db_con2);
				gBusTrackCpY[trkid][cpid] = floatstr(string);
				mysql_fetch_field_row(string, "CPZ", db_con2);
				gBusTrackCpZ[trkid][cpid] = floatstr(string);
				mysql_fetch_field_row(string, "CPReward", db_con2);
				gBusTrackCpReward[trkid][cpid] = strval(string);
				mysql_fetch_field_row(string, "CPType", db_con2);
				gBusTrackCpType[trkid][cpid] = strval(string);
				mysql_fetch_field_row(string, "CPTime", db_con2);
				gBusTrackCpTime[trkid][cpid] = strval(string);
			}
			#if defined DEBUG
				printf("[INFO:] Bus tracks data part 2/2 loaded [MySQL]");
			#endif
			//wp_mysql_free_result(db_con2);
		}
		case LOAD_TRASH_TRACKS:
		{
			new i = 0;
			
			mysql_store_result(db_con2);

			while(mysql_retrieve_row(db_con2))
			{
				mysql_fetch_field_row(string, "Enabled", db_con2);
				gTrashTrackEnabled[i] = strval(string);
				mysql_fetch_field_row(string, "StartArea", db_con2);
				gTrashTrackStartArea[i] = strval(string);

				i++;
			}
			#if defined DEBUG
				printf("[INFO:] Trash tracks data part 1/2 loaded [MySQL]");
			#endif
			//wp_mysql_free_result(db_con2);
		}
		case LOAD_TRASH_TRACKS_DATA:
		{
			new trkid, cpid;

			mysql_store_result(db_con2);
			
			while(mysql_retrieve_row(db_con2))
			{
				mysql_fetch_field_row(string, "TrackID", db_con2);
				trkid = strval(string);
				mysql_fetch_field_row(string, "CPID", db_con2);
				cpid = strval(string);
				mysql_fetch_field_row(string, "CPX", db_con2);
				gTrashTrackCpX[trkid][cpid] = strval(string);
				mysql_fetch_field_row(string, "CPY", db_con2);
				gTrashTrackCpY[trkid][cpid] = floatstr(string);
				mysql_fetch_field_row(string, "CPZ", db_con2);
				gTrashTrackCpZ[trkid][cpid] = floatstr(string);
				mysql_fetch_field_row(string, "CPReward", db_con2);
				gTrashTrackCpReward[trkid][cpid] = strval(string);
				mysql_fetch_field_row(string, "CPType", db_con2);
				gTrashTrackCpType[trkid][cpid] = strval(string);
				mysql_fetch_field_row(string, "CPTime", db_con2);
				gTrashTrackCpTime[trkid][cpid] = strval(string);
			}
			#if defined DEBUG
				printf("[INFO:] Trash tracks data part 2/2 loaded [MySQL]");
			#endif
			//wp_mysql_free_result(db_con2);
		}
		case LOAD_SWEEPER_TRACKS:
		{
			new i = 0;

			mysql_store_result(db_con2);
			
			while(mysql_retrieve_row(db_con2))
			{
				mysql_fetch_field_row(string, "Enabled", db_con2);
				gSweeperTrackEnabled[i] = strval(string);
				mysql_fetch_field_row(string, "StartArea", db_con2);
				gSweeperTrackStartArea[i] = strval(string);

				i++;
			}
			#if defined DEBUG
				printf("[INFO:] Sweeper tracks data part 1/2 loaded [MySQL]");
			#endif
			//wp_mysql_free_result(db_con2);
		}
		case LOAD_FARMER_TRACKS:
		{
			new i = 0;

			mysql_store_result(db_con2);
			
			while(mysql_retrieve_row(db_con2))
			{
				mysql_fetch_field_row(string, "Enabled", db_con2);
				gFarmerTrackEnabled[i] = strval(string);
				mysql_fetch_field_row(string, "StartArea", db_con2);
				gFarmerTrackStartArea[i] = strval(string);

				i++;
			}
			#if defined DEBUG
				printf("[INFO:] Farmer tracks data part 1/2 loaded [MySQL]");
			#endif
			//wp_mysql_free_result(db_con2);
		}
		case LOAD_SWEEPER_TRACKS_DATA:
		{
			new trkid, cpid;

			mysql_store_result(db_con2);
			
			while(mysql_retrieve_row(db_con2))
			{
				mysql_fetch_field_row(string, "TrackID", db_con2);
				trkid = strval(string);
				mysql_fetch_field_row(string, "CPID", db_con2);
				cpid = strval(string);
				mysql_fetch_field_row(string, "CPX", db_con2);
				gSweeperTrackCpX[trkid][cpid] = floatstr(string);
				mysql_fetch_field_row(string, "CPY", db_con2);
				gSweeperTrackCpY[trkid][cpid] = floatstr(string);
				mysql_fetch_field_row(string, "CPZ", db_con2);
				gSweeperTrackCpZ[trkid][cpid] = floatstr(string);
				mysql_fetch_field_row(string, "CPReward", db_con2);
				gSweeperTrackCpReward[trkid][cpid] = strval(string);
				mysql_fetch_field_row(string, "CPType", db_con2);
				gSweeperTrackCpType[trkid][cpid] = strval(string);
				mysql_fetch_field_row(string, "CPTime", db_con2);
				gSweeperTrackCpTime[trkid][cpid] = strval(string);
			}
			#if defined DEBUG
				printf("[INFO:] Sweeper tracks data part 2/2 loaded [MySQL]");
			#endif
		}
		case LOAD_FARMER_TRACKS_DATA:
		{
			new trkid, cpid;

			mysql_store_result(db_con2);
			
			while(mysql_retrieve_row(db_con2))
			{
				mysql_fetch_field_row(string, "TrackID", db_con2);
				trkid = strval(string);
				mysql_fetch_field_row(string, "CPID", db_con2);
				cpid = strval(string);
				mysql_fetch_field_row(string, "CPX", db_con2);
				gFarmerTrackCpX[trkid][cpid] = floatstr(string);
				mysql_fetch_field_row(string, "CPY", db_con2);
				gFarmerTrackCpY[trkid][cpid] = floatstr(string);
				mysql_fetch_field_row(string, "CPZ", db_con2);
				gFarmerTrackCpZ[trkid][cpid] = floatstr(string);
				mysql_fetch_field_row(string, "CPReward", db_con2);
				gFarmerTrackCpReward[trkid][cpid] = strval(string);
				mysql_fetch_field_row(string, "CPType", db_con2);
				gFarmerTrackCpType[trkid][cpid] = strval(string);
				mysql_fetch_field_row(string, "CPTime", db_con2);
				gFarmerTrackCpTime[trkid][cpid] = strval(string);
			}
			#if defined DEBUG
				printf("[INFO:] Farmer tracks data part 2/2 loaded [MySQL]");
			#endif
		}
		case LOAD_VARIABLES:
		{
			new i = 0;

			mysql_store_result(db_con2);
			
			while(mysql_retrieve_row(db_con2))
			{
				mysql_fetch_field_row(string, "varName", db_con2);
				strins(DBVariables[i][varName], string, 0, 128);
				mysql_fetch_field_row(string, "varType", db_con2);
				strins(DBVariables[i][varType], string, 0, 1);
				mysql_fetch_field_row(string, "varDValue", db_con2);
				DBVariables[i][varDValue] = strval(string);
				mysql_fetch_field_row(string, "varFValue", db_con2);
				DBVariables[i][varFValue] = floatstr(string);
				mysql_fetch_field_row(string, "varSValue", db_con2);
				strins(DBVariables[i][varSValue], string, 0, 128);

				i++;
			}
			#if defined DEBUG
				print("[INFO:] Loaded misc data [MySQL]");
			#endif
		}
		case SEND_SMS_TO_ALL:
		{
			mysql_store_result(db_con4);
		
			if(!mysql_num_rows(db_con4))
			{
				return 1;
			}
			
			while(mysql_retrieve_row(db_con4))
			{
				mysql_fetch_field_row(string, "Nr", db_con4);
				format(string, sizeof(string), "INSERT INTO `samp_sms` (`Sender` , `Receiver` , `SenderNumber` , `ReceiverNumber` , `Content`) VALUES ('%s' , '%s' , '%d' , '%d' , '%s')",
					" ", " ", gPlayerVars[playerid][mGlobalSmsSenderNumber], strval(string), gPlayerVars[playerid][mGlobalSms]);
				wp_mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con4);
			}
		}
		case SEND_SMS:
		{
			if(gPlayerVars[playerid][mPhoneDataReceived])
			{
				return 1;
			}
			
			gPlayerVars[playerid][mPhoneDataReceived] = 1;
			gPlayerVars[playerid][mPhoneDataTimeout] = -1;
			
			mysql_store_result(db_con1);
			
			if(!mysql_num_rows(db_con1))
			{
				ShowPlayerDialog(playerid, DIALOG_ITEM_3, DIALOG_STYLE_MSGBOX, "Informacja", "Twoja karta SIM zosta³a zablokowana", "Ok", "");
				return 1;
			}
			
			mysql_retrieve_row(db_con1);
			
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
				wp_mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con1);				
			}
			format(string, sizeof(string), "INSERT INTO `samp_sms` (`Sender` , `Receiver` , `SenderNumber` , `ReceiverNumber` , `Content`) VALUES ('%s' , '%s' , '%d' , '%d', '%s')",
				gPlayerData[playerid][pName], " ", gSmsList[0][mSmsSenderNumber], gSmsList[0][mSmsReceiverNumber], gSmsList[0][mSmsContent]);
			wp_mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			
			SMSLog(gSmsList[0][mSmsContent]);
			
			ShowPlayerDialog(playerid, DIALOG_ITEM_3, DIALOG_STYLE_MSGBOX, "Informacja", "Wiadomoœæ zosta³a wys³ana", "Wróæ", "");
		}
		case CHECK_PHONE_STATUS:
		{
			if(gPlayerVars[playerid][mPhoneDataReceived])
			{
				return 1;
			}
			
			gPlayerVars[playerid][mPhoneDataReceived] = 1;
			gPlayerVars[playerid][mPhoneDataTimeout] = -1;
			
			mysql_store_result(db_con2);
			
			if(!mysql_num_rows(db_con2))
			{
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Twoja karta SIM zosta³a zablokowana", "Ok", "");
				return 1;
			}
			
			mysql_retrieve_row(db_con2);			
			mysql_fetch_field_row(string, "Faction", db_con2);
			gPlayerVars[playerid][mPhoneFaction] = strval(string);
			
			if(DynamicFactions[gPlayerVars[playerid][mPhoneFaction]][fType] != FACTIONT_COMPANY_PHONE)
			{
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Brak sieci...", "Ok", "");
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
			
				format(string, sizeof(string), "Sieæ: %s\nCena za min. po³¹czenia: $%d\nCena za sms: $%d\nDarmowe minuty: %d\nDarmowe SMSy: %d",
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
				
				format(string, sizeof(string), "Sieæ: %s\nCena za min. po³¹czenia: $%d\nCena za sms: $%d\nPieni¹dze na koncie: $%d\nWa¿noœæ: %d dni",
					DynamicFactions[Businesses[SlotParam3(playerid, gSelectedSlot[playerid])][mFaction]][mCompanyName],
					DynamicFactions[Businesses[SlotParam3(playerid, gSelectedSlot[playerid])][mFaction]][mCallCostCard],
					DynamicFactions[Businesses[SlotParam3(playerid, gSelectedSlot[playerid])][mFaction]][mSmsCostCard],
					gPlayerVars[playerid][mPhoneCash], gPlayerVars[playerid][mPhoneRenewalTime]);
			}
			ShowPlayerDialog(playerid, DIALOG_ITEM_3, DIALOG_STYLE_MSGBOX, "Informacja", string, "Wróæ", "");
		}			
		case CHECK_PHONE_FEE:
		{
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
				wp_mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con3);
			}
			else
			{
				gRandNumber[playerid] = 600000000 + random(999999);
				format(string, sizeof(string), "SELECT `Nr` FROM `samp_phones` WHERE `Nr` = '%d'",gRandNumber[playerid]);
				wp_mysql_query(string, CHECK_PHONE_FEE, playerid, db_con3);
			}
		}
		case CHECK_PHONE_CARD:
		{
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
				wp_mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con3);
			}
			else
			{
				gRandNumber[playerid] = 600000000 + random(999999);
				format(string, sizeof(string), "SELECT `Nr` FROM `samp_phones` WHERE `Nr` = '%d'",gRandNumber[playerid]);
				wp_mysql_query(string, CHECK_PHONE_FEE, playerid, db_con3);
			}
		}
		case CHECK_PHONE_TYPE_CALL:
		{
			if(Mobile[playerid] == 255)
			{
				gCallDataReceived[playerid] = 1;
			}
			
			if(gCallDataReceived[playerid])
			{
				return 1;
			}
			
			gCallDataReceived[playerid] = 1;			
			mysql_store_result(db_con3);
			
			if(!mysql_num_rows(db_con3))
			{
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Twoja karta SIM zosta³a zablokowana", "Ok", "");
				return 1;
			}
			
			mysql_retrieve_row(db_con3);
			
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
		}
		case CHECK_PHONE_TYPE_EXTENSION:
		{
			mysql_store_result(db_con1);
			
			if(!mysql_num_rows(db_con1))
			{
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Twoja karta SIM zosta³a zablokowana", "Ok", "");
				return 1;
			}
			
			mysql_retrieve_row(db_con1);			
			mysql_fetch_field_row(string, "Type", db_con1);			
			gPlayerVars[playerid][mPhoneType] = strval(string);
			
			if(gPlayerVars[playerid][mPhoneType] == PHONET_FEE)
			{
				ShowPlayerDialog(playerid, DIALOG_ITEM_3, DIALOG_STYLE_MSGBOX, "Informacja", "Nie mo¿esz do³adowaæ karty w abonamencie", "Wróæ", "");
				return 1;
			}
			else if(gPlayerVars[playerid][mPhoneType] == PHONET_CARD)
			{
				mysql_fetch_field_row(string, "Cash", db_con1);
				gPlayerVars[playerid][mPhoneCash] = strval(string);
				mysql_fetch_field_row(string, "RenewalTime", db_con1);
				gPlayerVars[playerid][mPhoneRenewalTime] = strval(string);
				mysql_fetch_field_row(string, "SimID", db_con1);
				gPlayerVars[playerid][mPhoneSimID] = strval(string);
				mysql_fetch_field_row(string, "Nr", db_con1);
				gPlayerVars[playerid][mPhoneNr] = strval(string);
				format(string, sizeof(string), "UPDATE `samp_phones` SET `RenewalTime` = '%d' , `Cash` = '%d' WHERE `SimID` = '%d' AND `Nr` = '%d'",
					gPlayerVars[playerid][mPhoneRenewalTime]+SlotParam2(playerid, gSelectedSlot[playerid]),
					gPlayerVars[playerid][mPhoneCash]+SlotParam1(playerid, gSelectedSlot[playerid]),
					gPlayerVars[playerid][mPhoneSimID], gPlayerVars[playerid][mPhoneNr]);
				wp_mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con1);
				ShowPlayerDialog(playerid, DIALOG_ITEM_3, DIALOG_STYLE_MSGBOX, "Informacja", "Kod z karty zosta³ u¿yty", "Wróc", "");
				RemovePlayerItemExUsed(playerid, gSelectedSlot[playerid]);
				InsertPlayerItemEx(playerid, 1, 144, 0, 0, 0, 0, "Puste", 1);
			}
		} 
		case CHECK_PHONE_NEW_SMS:
		{
			new slot[MAX_PLAYER_ITEM_SLOT];
			
			mysql_store_result(db_con4);
			
			new smsId;
			while(mysql_retrieve_row(db_con4))
			{
				mysql_fetch_field_row(string, "ID", db_con4);
				smsId = strval(string);				
				
				foreach(Player, i)
				{
					if(!gPlayerLogged[i] || gPhoneTextBlinking[i])
						continue;
					PHaveItemEx(i, 3, 3, slot);
					for(new j = 0; j < MAX_PLAYER_ITEM_SLOT; j++)
					{
						if(slot[j] && SlotParam2(i, j+1) == smsId)
						{
							gPhoneTextReceived[i] = smsId;
							defer BlinkPhoneText(i);
							gPhoneTextBlinking[i] = 1;
							break;
						}
					}	
					PHaveItemEx(i, 3, 4, slot);
					for(new j = 0; j < MAX_PLAYER_ITEM_SLOT; j++)
					{
						if(slot[j] && SlotParam2(i, j+1) == smsId)
						{
							gPhoneTextReceived[i] = smsId;
							defer BlinkPhoneText(i);
							gPhoneTextBlinking[i] = 1;
							break;
						}
					}
				}				
			}
		}
		case PHONE_LIST_SIM_REPLACE:
		{
			
			mysql_store_result(db_con1);
			
			new i = 0;
			new k = mysql_num_rows(db_con1);
			if(k == 0)
			{
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Nie posiadasz w tej sieci ¿adnej aktywnej karty", "Wróæ", "");
				return 1;
			}
			
			while(mysql_retrieve_row(db_con1))
			{
				mysql_fetch_field_row(string, "ID", db_con1);
				gPhoneList[i][mPhoneID] = strval(string);
				mysql_fetch_field_row(string, "Nr", db_con1);
				gPhoneList[i][mPhoneNr] = strval(string);
				mysql_fetch_field_row(string, "SimID", db_con1);
				gPhoneList[i][mPhoneSimID] = strval(string);
				
				i++;
			}
			i = 0;
			while(i < k)
			{
				format(string, sizeof(string), "%s%d. Nr telefonu: %d, ID karty: %d\n", string, i+1, gPhoneList[i][mPhoneNr], gPhoneList[i][mPhoneSimID]);
				i++;
			}
			ShowPlayerDialog(playerid, DIALOG_BUY_SIM_2_RENEW, DIALOG_STYLE_LIST, "Wybierz karte któr¹ chcesz wyrobiæ", string, "Wybierz", "Wróc");
		}
		case PHONE_LIST_FEE_RESIGN:
		{			
			mysql_store_result(db_con1);
			
			new i = 0;
			new k = mysql_num_rows(db_con1);
			if(k == 0)
			{
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Nie posiadasz w tej sieci ¿adnej aktywnej karty", "Wróæ", "");
				return 1;
			}

			while(mysql_retrieve_row(db_con1))
			{
				mysql_fetch_field_row(string, "ID", db_con1);
				gPhoneList[i][mPhoneID] = strval(string);
				mysql_fetch_field_row(string, "Nr", db_con1);
				gPhoneList[i][mPhoneNr] = strval(string);
				mysql_fetch_field_row(string, "SimID", db_con1);
				gPhoneList[i][mPhoneSimID] = strval(string);
				
				i++;
			}
			i = 0;
			while(i < k)
			{
				format(string, sizeof(string), "%s%d. Nr telefonu: %d, ID karty: %d\n", string, i+1, gPhoneList[i][mPhoneNr], gPhoneList[i][mPhoneSimID]);
				i++;
			}
			ShowPlayerDialog(playerid, DIALOG_BUY_SIM_2_RESIGN, DIALOG_STYLE_LIST, "Wybierz umowe, któr¹ chcesz rozwi¹zaæ", string, "Wybierz", "Wróc");
		}
		case PHONE_SMS_LIST:
		{
			mysql_store_result(db_con1);
			
			new i = 0;
			new k = mysql_num_rows(db_con1);
			if(k == 0)
			{
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Lista wiadomoœci jest pusta", "Wróæ", "");
				return 1;
			}
			
			while(mysql_retrieve_row(db_con1))
			{
				mysql_fetch_field_row(string, "ID", db_con1);
				gSmsList[i][mSmsId] = strval(string);
				mysql_fetch_field_row(string, "Sender", db_con1);
				gSmsList[i][mSmsSenderName] = strval(string);
				mysql_fetch_field_row(string, "Receiver", db_con1);
				gSmsList[i][mSmsReceiverName] = strval(string);
				mysql_fetch_field_row(string, "SenderSimId", db_con1);
				gSmsList[i][mSmsSenderSimId] = strval(string);
				mysql_fetch_field_row(string, "ReceiverSimId", db_con1);
				gSmsList[i][mSmsReceiverSimId] = strval(string);
				mysql_fetch_field_row(string, "SenderNumber", db_con1);
				gSmsList[i][mSmsSenderNumber] = strval(string);
				mysql_fetch_field_row(string, "ReceiverNumber", db_con1);
				gSmsList[i][mSmsReceiverNumber] = strval(string);
				mysql_fetch_field_row(string, "Content", db_con1);
				format(gSmsList[i][mSmsContent], 256, "%s", string);
				
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
			format(string2, sizeof(string2), "SMSy %d/50", k);
			ShowPlayerDialog(playerid, DIALOG_SMS_2_VIEW, DIALOG_STYLE_LIST, string2, string, "Wybierz", "Wróc");
		}
		case LOAD_CARSDATA:
		{
			new i = 0;

			mysql_store_result(db_con2);
			
			while(mysql_retrieve_row(db_con2))
			{
				mysql_fetch_field_row(string, "Model", db_con1);
				CarsData[i][Model] = strval(string);
				mysql_fetch_field_row(string, "Bak", db_con1);
				CarsData[i][Bak] = strval(string);
				mysql_fetch_field_row(string, "Paliwo", db_con1);
				CarsData[i][Paliwo] = strval(string);
				mysql_fetch_field_row(string, "Spalanie", db_con1);
				CarsData[i][Spalanie] = strval(string);
				mysql_fetch_field_row(string, "ToGas", db_con1);
				CarsData[i][ToGas] = strval(string);
				mysql_fetch_field_row(string, "MaxHealth", db_con1);
				CarsData[i][MaxHealth] = strval(string);

				switch( CarsData[i][Paliwo] )
				{
					case 0:
					{
						CarsData[i][Co2Emmision] = 2.3*(float(CarsData[i][Spalanie])/100.0);
						#if defined DEBUG
							printf("[DEBUG:] Co2Emmision, model: %d, fuel type: %d, combustion: %d, emmision: %f", CarsData[i][Model], CarsData[i][Paliwo], CarsData[i][Spalanie], CarsData[i][Co2Emmision]);
						#endif
					}
					case 1:
					{
						CarsData[i][Co2Emmision] = 2.6*(float(CarsData[i][Spalanie])/100.0);
						#if defined DEBUG
							printf("[DEBUG:] Co2Emmision, model: %d, fuel type: %d, combustion: %d, emmision: %f", CarsData[i][Model], CarsData[i][Paliwo], CarsData[i][Spalanie], CarsData[i][Co2Emmision]);
						#endif
					}
					case 2:
					{
						CarsData[i][Co2Emmision] = 1.4*(float(CarsData[i][Spalanie])/100.0);
						#if defined DEBUG
							printf("[DEBUG:] Co2Emmision, model: %d, fuel type: %d, combustion: %d, emmision: %f", CarsData[i][Model], CarsData[i][Paliwo], CarsData[i][Spalanie], CarsData[i][Co2Emmision]);
						#endif
					}
					case 3:
					{
						CarsData[i][Co2Emmision] = 4.0*(float(CarsData[i][Spalanie])/100.0);
						#if defined DEBUG
							printf("[DEBUG:] Co2Emmision, model: %d, fuel type: %d, combustion: %d, emmision: %f", CarsData[i][Model], CarsData[i][Paliwo], CarsData[i][Spalanie], CarsData[i][Co2Emmision]);
						#endif
					}
				}

				i++;
			}
			#if defined DEBUG
				printf("[INFO:] Vehicles additional data loaded [MySQL]");
			#endif
		}
		case LOAD_NEWS:
		{
			new i = 0;
			
			mysql_store_result(db_con2);
			
			while(mysql_retrieve_row(db_con2))
			{
				mysql_fetch_field_row(string, "TimeLeft", db_con2);
				gSanNewsMsgs[i][mTimeLeft] = strval(string);
				mysql_fetch_field_row(string, "Content", db_con2);
				format(gSanNewsMsgs[i][mContent], 255, string);
				mysql_fetch_field_row(string, "Used", db_con2);
				gSanNewsMsgs[i][mUsed] = strval(string);
				
				i++;
			}
			
			#if defined DEBUG
				printf("[INFO:] News loaded [MySQL]");
			#endif
		}
		case LOAD_WANTED_LIST: // TODO: FIX THIS LATER (not used for now)
		{
			new i = 0;
			
			mysql_store_result(db_con1);
			
			while(mysql_retrieve_row(db_con1))
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
		}
		case SHOW_SWANTED_LIST:
		{
			mysql_store_result(db_con1);
			
			new i = 0;
			new k = mysql_num_rows(db_con1);
			if(k == 0)
			{
				ShowPlayerDialog(playerid, DIALOG_POLICE_COMPUTER_4D, DIALOG_STYLE_MSGBOX, "Komputer policyjny", "Brak wpisów do kartoteki na wybrane nazwisko", "Wróæ", "");
				return 1;
			}

			while(mysql_retrieve_row(db_con1))
			{
				mysql_fetch_field_row(string, "PlayerName", db_con1);
				strdel(WantedList[i][WantedName], 0, strlen(WantedList[i][WantedName]));
				strmid(WantedList[i][WantedName], string, 0, strlen(string), 64);
				mysql_fetch_field_row(string, "Description", db_con1);
				strdel(WantedList[i][WantedDescription], 0, strlen(WantedList[i][WantedDescription]));
				strmid(WantedList[i][WantedDescription], string, 0, strlen(string), 64);
				mysql_fetch_field_row(string, "CommitedDay", db_con1);
				WantedList[i][WantedCommitedDay] = strval(string);
				mysql_fetch_field_row(string, "CommitedMonth", db_con1);
				WantedList[i][WantedCommitedMonth] = strval(string);
				mysql_fetch_field_row(string, "CommitedYear", db_con1);
				WantedList[i][WantedCommitedYear] = strval(string);
				mysql_fetch_field_row(string, "Punished", db_con1);
				WantedList[i][WantedPunished] = strval(string);

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
			//wp_mysql_free_result(db_con1);
			ShowPlayerDialog(playerid, DIALOG_POLICE_COMPUTER_3D, DIALOG_STYLE_MSGBOX, "Komputer policyjny", string, "Wróæ", "WyjdŸ");
		}
		case SHOW_DWANTED_LIST:
		{
			mysql_store_result(db_con1);
		
			new i = 0;
			new k = mysql_num_rows(db_con1);
			if(k == 0)
			{
				ShowPlayerDialog(playerid, DIALOG_POLICE_COMPUTER_4D, DIALOG_STYLE_MSGBOX, "Komputer policyjny", "Brak wpisów do kartoteki na wybrane nazwisko", "Wróæ", "");
				return 1;
			}

			while(mysql_retrieve_row(db_con1))
			{
				mysql_fetch_field_row(string, "ID", db_con2);
				WantedList[i][WantedID] = strval(string);
				mysql_fetch_field_row(string, "PlayerName", db_con1);
				strdel(WantedList[i][WantedName], 0, strlen(WantedList[i][WantedName]));
				strmid(WantedList[i][WantedName], string, 0, strlen(string), 64);
				mysql_fetch_field_row(string, "Description", db_con1);
				strdel(WantedList[i][WantedDescription], 0, strlen(WantedList[i][WantedDescription]));
				strmid(WantedList[i][WantedDescription], string, 0, strlen(string), 64);
				mysql_fetch_field_row(string, "CommitedDay", db_con1);
				WantedList[i][WantedCommitedDay] = strval(string);
				mysql_fetch_field_row(string, "CommitedMonth", db_con1);
				WantedList[i][WantedCommitedMonth] = strval(string);
				mysql_fetch_field_row(string, "CommitedYear", db_con1);
				WantedList[i][WantedCommitedYear] = strval(string);
				mysql_fetch_field_row(string, "Punished", db_con1);
				WantedList[i][WantedPunished] = strval(string);

				i++;
			}
			format(string, sizeof(string), "DELETE FROM `samp_wanted` WHERE `ID` = '%d' ", WantedList[gPlayerVars[playerid][lPoliceComputerPID]][WantedID]);
			wp_mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);

			ShowPlayerDialog(playerid, DIALOG_POLICE_COMPUTER_3D, DIALOG_STYLE_MSGBOX, "Komputer policyjny", "Wpis zosta³ usuniêty", "Wróæ", "Zamknij");
			return 1;
		}
		case SHOW_WANTED_LIST:
		{
			mysql_store_result(db_con1);
			
			new i = 0;
			new k = mysql_num_rows(db_con1);
			if(k == 0)
			{
				ShowPlayerDialog(playerid, DIALOG_POLICE_COMPUTER_4D, DIALOG_STYLE_MSGBOX, "Komputer policyjny", "Brak wpisów do kartoteki na wybrane nazwisko", "Wróæ", "");
				return 1;
			}
			
			while(mysql_retrieve_row(db_con1))
			{
				mysql_fetch_field_row(string, "PlayerName", db_con1);
				strdel(WantedList[i][WantedName], 0, strlen(WantedList[i][WantedName]));
				strmid(WantedList[i][WantedName], string, 0, strlen(string), 64);
				mysql_fetch_field_row(string, "Description", db_con1);
				strdel(WantedList[i][WantedDescription], 0, strlen(WantedList[i][WantedDescription]));
				strmid(WantedList[i][WantedDescription], string, 0, strlen(string), 64);
				mysql_fetch_field_row(string, "CommitedDay", db_con1);
				WantedList[i][WantedCommitedDay] = strval(string);
				mysql_fetch_field_row(string, "CommitedMonth", db_con1);
				WantedList[i][WantedCommitedMonth] = strval(string);
				mysql_fetch_field_row(string, "CommitedYear", db_con1);
				WantedList[i][WantedCommitedYear] = strval(string);
				mysql_fetch_field_row(string, "Punished", db_con1);
				WantedList[i][WantedPunished] = strval(string);

				i++;
			}
			i = 0;
			string = "";
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
			ShowPlayerDialog(playerid, DIALOG_POLICE_COMPUTER_3B, DIALOG_STYLE_LIST, "Komputer policyjny", string, "Wybierz", "Wróæ");
		}
		case LOAD_LUCKY_LOTTERY:
		{
			new i = 0;
			
			mysql_store_result(db_con2);
			
			while(mysql_retrieve_row(db_con2))
			{
				mysql_fetch_field_row(string, "LotteryID", db_con2);
				gLuckyLottery[i][LuckyID] = strval(string);
				mysql_fetch_field_row(string, "PlayerName", db_con2);
				format(gLuckyLottery[i][LuckyPlayerName], MAX_PLAYER_NAME, string);
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
			//wp_mysql_free_result(db_con2);
			#if defined DEBUG
				printf("[INFO:] Loaded Lucky Lottery Data [MySQL]");
			#endif
		}
		case LOAD_RANDOM_PICKUP_EVENT_1:
		{
			/*if(!mysql_store_result(db_con4))
			{
				ErrorLog("[ERROR:] Can't store result on LOAD_RANDOM_PICKUP_EVENT_1");
				return 1;
			}*/
			new randomID = random(mysql_num_rows(db_con4))+1;
			gPickupEventID = randomID;
			format(string, sizeof(string), "SELECT HIGH_PRIORITY * FROM `samp_pickup_events` WHERE `ID` = '%d'", randomID);
			wp_mysql_query(string, LOAD_RANDOM_PICKUP_EVENT_2, db_con4);
			//wp_mysql_free_result(db_con4);
		}
		case LOAD_RANDOM_PICKUP_EVENT_2:
		{
			mysql_store_result(db_con4);
			mysql_retrieve_row(db_con4);
			
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
			mysql_fetch_field_row(string, "Message", db_con4);
			format(gPickupEventMessage, 256, string);
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
			
			format(string, sizeof(string), "SELECT HIGH_PRIORITY * FROM `samp_pickup_events_locations` WHERE `EventID` = '%d'", gPickupEventID);
			wp_mysql_query(string, LOAD_RANDOM_PICKUP_EVENT_3, db_con4);
			
			//wp_mysql_free_result(db_con4);
		}
		case LOAD_RANDOM_PICKUP_EVENT_3:
		{
			new i = 0;

			mysql_store_result(db_con4);
			
			while(mysql_retrieve_row(db_con4))
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
			//wp_mysql_free_result(db_con4);
		}
		case CHECK_VEHICLE_AVAILABLE:
		{
			new modelID;
			
			mysql_store_result(db_con4);			
			mysql_retrieve_row(db_con4);
			
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
					wp_mysql_query(string, SAVE, playerid, db_con2);
				}				
				ImportVeh(gBuyBusinessID[playerid], modelID, gPlayerData[playerid][pName], gPlayerVars[playerid][mFuelType], gPlayerVars[playerid][mVehMaxHealth]);

				format(string, sizeof(string), "Twój pojazd jest gotowy do odebrania. Koszt: $%d\nPamiêtaj ¿e kwota pieniêdzy wyznaczona za pojazd pobierana jest dopiero w momencie sprowadzenia pojazdu !", cenyPojazdow[modelID-400]);
				format(string, sizeof(string), "%s\nJeœli w kasie biznesu nie bêdzie wystarczaj¹cej iloœci pieniêdzy samochód zostanie odes³any !", string);
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", string, "Zamknij", "");
				
				Businesses[gBuyBusinessID[playerid]][VehicleOrderCount]++;
				SaveBizData(gBuyBusinessID[playerid], "VehicleOrderCount");
			}
		}
		case LOAD_RACES_TRACKS_DATA:
		{
			new trkid, cpid;
			
			mysql_store_result(db_con2);

			while(mysql_retrieve_row(db_con2))
			{
				mysql_fetch_field_row(string, "RaceId", db_con2);
				trkid = strval(string);
				mysql_fetch_field_row(string, "CpId", db_con2);
				cpid = strval(string);
				mysql_fetch_field_row(string, "CpX", db_con2);
				gRaceTrackCpX[trkid][cpid] = floatstr(string);
				mysql_fetch_field_row(string, "CpY", db_con2);
				gRaceTrackCpY[trkid][cpid] = floatstr(string);
				mysql_fetch_field_row(string, "CpZ", db_con2);
				gRaceTrackCpZ[trkid][cpid] = floatstr(string);
				mysql_fetch_field_row(string, "CpType", db_con2);
				gRaceTrackCpType[trkid][cpid] = strval(string);
			}
			#if defined DEBUG
				printf("[INFO:] Race tracks data part 2/2 loaded [MySQL]");
			#endif
			//wp_mysql_free_result(db_con2);
		}
		case LOAD_RACES_TRACKS:
		{
			new trkid;

			mysql_store_result(db_con2);
			
			while(mysql_retrieve_row(db_con2))
			{
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
				mysql_fetch_field_row(string, "Start2CpX", db_con2);
				gRaceTrackStart2CpX[trkid] = strval(string);
				mysql_fetch_field_row(string, "Start2CpY", db_con2);
				gRaceTrackStart2CpY[trkid] = strval(string);
				mysql_fetch_field_row(string, "Start2CpZ", db_con2);
				gRaceTrackStart2CpZ[trkid] = strval(string);
				mysql_fetch_field_row(string, "Start3CpX", db_con2);
				gRaceTrackStart3CpX[trkid] = strval(string);
				mysql_fetch_field_row(string, "Start3CpY", db_con2);
				gRaceTrackStart3CpY[trkid] = strval(string);
				mysql_fetch_field_row(string, "Start3CpZ", db_con2);
				gRaceTrackStart3CpZ[trkid] = strval(string);
				mysql_fetch_field_row(string, "Start4CpX", db_con2);
				gRaceTrackStart4CpX[trkid] = strval(string);
				mysql_fetch_field_row(string, "Start4CpY", db_con2);
				gRaceTrackStart4CpY[trkid] = strval(string);
				mysql_fetch_field_row(string, "Start4CpZ", db_con2);
				gRaceTrackStart4CpZ[trkid] = strval(string);
				mysql_fetch_field_row(string, "Start5CpX", db_con2);
				gRaceTrackStart5CpX[trkid] = strval(string);
				mysql_fetch_field_row(string, "Start5CpY", db_con2);
				gRaceTrackStart5CpY[trkid] = strval(string);
				mysql_fetch_field_row(string, "Start5CpZ", db_con2);
				gRaceTrackStart5CpZ[trkid] = strval(string);
				mysql_fetch_field_row(string, "Start6CpX", db_con2);
				gRaceTrackStart6CpX[trkid] = strval(string);
				mysql_fetch_field_row(string, "Start6CpY", db_con2);
				gRaceTrackStart6CpY[trkid] = strval(string);
				mysql_fetch_field_row(string, "Start6CpZ", db_con2);
				gRaceTrackStart6CpZ[trkid] = strval(string);
				mysql_fetch_field_row(string, "Start7CpX", db_con2);
				gRaceTrackStart7CpX[trkid] = strval(string);
				mysql_fetch_field_row(string, "Start7CpY", db_con2);
				gRaceTrackStart7CpY[trkid] = strval(string);
				mysql_fetch_field_row(string, "Start7CpZ", db_con2);
				gRaceTrackStart7CpZ[trkid] = strval(string);
				mysql_fetch_field_row(string, "Start8CpX", db_con2);
				gRaceTrackStart8CpX[trkid] = strval(string);
				mysql_fetch_field_row(string, "Start8CpY", db_con2);
				gRaceTrackStart8CpY[trkid] = strval(string);
				mysql_fetch_field_row(string, "Start8CpZ", db_con2);
				gRaceTrackStart8CpZ[trkid] = strval(string);
				mysql_fetch_field_row(string, "Start9CpX", db_con2);
				gRaceTrackStart9CpX[trkid] = strval(string);
				mysql_fetch_field_row(string, "Start9CpY", db_con2);
				gRaceTrackStart9CpY[trkid] = strval(string);
				mysql_fetch_field_row(string, "Start9CpZ", db_con2);
				gRaceTrackStart9CpZ[trkid] = strval(string);
				mysql_fetch_field_row(string, "Start10CpX", db_con2);
				gRaceTrackStart10CpX[trkid] = strval(string);
				mysql_fetch_field_row(string, "Start10CpY", db_con2);
				gRaceTrackStart10CpY[trkid] = strval(string);
				mysql_fetch_field_row(string, "Start10CpZ", db_con2);
				gRaceTrackStart10CpZ[trkid] = strval(string);
				
				if(gRaceTrackInfoCpX[trkid] != 0.0 && gRaceTrackInfoCpY[trkid] != 0.0)
					gRaceTrackInfoPickupId[trkid] = CreateDynamicPickup(1008, 23, gRaceTrackInfoCpX[trkid], gRaceTrackInfoCpY[trkid], gRaceTrackInfoCpZ[trkid]);
			}
			#if defined DEBUG
				printf("[INFO:] Race tracks data part 1/2 loaded [MySQL]");
			#endif
			//wp_mysql_free_result(db_con2);
		}
		case LOAD_RACER_STATS:
		{
			mysql_store_result(db_con2);
			
			if(!mysql_num_rows(db_con2))
			{
				ShowPlayerDialog(playerid, DIALOG_RACE_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Nie posiadasz jeszcze statystyk na tej trasie.", "Wróæ", "");
				return 1;
			}
			
			mysql_retrieve_row(db_con2);
			new bestTime[128], winCount, looseCount;
			mysql_fetch_field_row(string, "Time", db_con2);
			format(bestTime, sizeof(bestTime), "%s", string);
			mysql_fetch_field_row(string, "Wins", db_con2);
			winCount = strval(string);
			mysql_fetch_field_row(string, "Looses", db_con2);
			looseCount = strval(string);
			format(string, sizeof(string), "Twój nalepszy czas: %s\nIloœæ wygranych: %d\nIloœæ przegranych: %d", bestTime, winCount, looseCount);
			ShowPlayerDialog(playerid, DIALOG_RACE_INFO, DIALOG_STYLE_MSGBOX, "Twoje statystyki wyœcigu", string, "Wróæ", "");
			return 1;
		}
		case LOAD_RACER_STATS_BEST:
		{
			mysql_store_result(db_con2);
			
			if(!mysql_num_rows(db_con2))
			{
				ShowPlayerDialog(playerid, DIALOG_RACE_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Brak najlepszego czasu na tej trasie.", "Wróæ", "");
				return 1;
			}
			
			mysql_retrieve_row(db_con2);
			
			new bestTime[128], setBy[MAX_PLAYER_NAME];
			
			mysql_fetch_field_row(string, "Time", db_con2);
			format(bestTime, sizeof(bestTime), "%s", string);
			mysql_fetch_field_row(string, "Name", db_con2);
			format(setBy, MAX_PLAYER_NAME, string);
			
			format(string, sizeof(string), "Nalepszy czas: %s\nPrzez: %s", bestTime, setBy);
			ShowPlayerDialog(playerid, DIALOG_RACE_INFO, DIALOG_STYLE_MSGBOX, "Statystyki", string, "Wróæ", "");
			
			return 1;
		}
		case LOAD_WEED:
		{
			mysql_store_result(db_con2);
			
			if(!mysql_num_rows(db_con2))
			{
				ErrorLog("[ERROR:] There is no rows on LOAD_WEED");
				return 1;
			}
			
			new i = 0;
			
			while(mysql_retrieve_row(db_con2))
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
			//wp_mysql_free_result(db_con2);
			
		}
		case DEF_FAC_LEADERS:
		{
			mysql_store_result(db_con1);
			
			if(!mysql_num_rows(db_con1))
			{
				// [NOTE:] Every faction leader is free
			}
			
			new factionHaveLeader[7];
			
			while(mysql_retrieve_row(db_con1))
			{
				mysql_fetch_field_row(string, "Faction", db_con1);
				switch(strval(string))
				{
					case 0: factionHaveLeader[0] = 1;
					case 1: factionHaveLeader[1] = 1;
					case 3: factionHaveLeader[2] = 1;
					case 4: factionHaveLeader[3] = 1;
					case 9: factionHaveLeader[4] = 1;
					case 11: factionHaveLeader[5] = 1;					
					case 2: factionHaveLeader[6] = 1;					
				}
			}
			format(string, sizeof(string), "");
			if(!factionHaveLeader[0])
			{
				format(string, sizeof(string), ""#COLOR_BEGIN2"%s\n\n", DynamicFactions[0][Name]);
			}
			if(!factionHaveLeader[1])
			{
				format(string, sizeof(string), "%s%s\n\n", string, DynamicFactions[2][Name]);
			}
			if(!factionHaveLeader[2])
			{
				format(string, sizeof(string), "%s%s\n\n", string, DynamicFactions[3][Name]);
			}
			if(!factionHaveLeader[3])
			{
				format(string, sizeof(string), "%s%s\n\n", string, DynamicFactions[4][Name]);
			}
			if(!factionHaveLeader[4])
			{
				format(string, sizeof(string), "%s%s\n\n", string, DynamicFactions[9][Name]);
			}
			if(!factionHaveLeader[5])
			{
				format(string, sizeof(string), "%s%s\n\n", string, DynamicFactions[11][Name]);
			}
			if(!factionHaveLeader[6])
			{
				format(string, sizeof(string), "%s%s\n\n", string, DynamicFactions[2][Name]);
			}
			if(strlen(string) == 0)
			{
				format(string, sizeof(string), "Wszystkie frakcje publiczne maj¹ obecnie swojego lidera");
			}
			ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, ""#COLOR_TITLE"Frakcje nieposiadaj¹ce lidera", string, "Zamknij", "");
			return 1;
		}			
		case LOAD_DRIVER_BOOK_QUESTION:
		{			
			mysql_store_result(db_con2);
			
			if(!mysql_num_rows(db_con2))
			{
				ErrorLog("[ERROR:] There is no rows on LOAD_DRIVER_BOOK_QUESTION");
				ShowPlayerDialog(playerid, DIALOG_ITEM_3, DIALOG_STYLE_MSGBOX, "Informacja", "Wyst¹pi³ b³¹d. Spróbuj jeszcze raz.", "Wróæ", "");
				return 1;
			}
			
			mysql_retrieve_row(db_con2);
			
			new questionary[512];
			mysql_fetch_field_row(string, "ID", db_con2);
			format(questionary, sizeof(questionary), "Pytanie nr %d:\n", strval(string));
			mysql_fetch_field_row(string, "Question", db_con2);
			format(questionary, sizeof(questionary), "%s%s", questionary, string);
			mysql_fetch_field_row(string, "Answer", db_con2);
			format(questionary, sizeof(questionary), "%s\n\nOdpowiedŸ:\n%s", questionary, string);

			ShowPlayerDialog(playerid, DIALOG_DRIVER_BOOK_2, DIALOG_STYLE_MSGBOX, "Pytanie", questionary, "Wróæ", "Zamknij");
			
			//wp_mysql_free_result(db_con2);
			return 1;
		}
		case LOAD_MAP_ICONS:
		{
			new i = 0;
			
			mysql_store_result(db_con2);
			
			while(mysql_retrieve_row(db_con2))
			{
				mysql_fetch_field_row(string, "PosX", db_con2);
				gMapIcon[i][mPosX] = floatstr(string);
				mysql_fetch_field_row(string, "PosY", db_con2);
				gMapIcon[i][mPosY] = floatstr(string);
				mysql_fetch_field_row(string, "PosZ", db_con2);
				gMapIcon[i][mPosZ] = floatstr(string);
				mysql_fetch_field_row(string, "Type", db_con2);
				gMapIcon[i][mType] = strval(string);
				mysql_fetch_field_row(string, "Color", db_con2);
				gMapIcon[i][mColor] = strval(string);
				mysql_fetch_field_row(string, "World", db_con2);
				gMapIcon[i][mWorld] = strval(string);
				mysql_fetch_field_row(string, "Interior", db_con2);
				gMapIcon[i][mInterior] = strval(string);
				mysql_fetch_field_row(string, "StreamDistance", db_con2);
				gMapIcon[i][mStreamDistance] = strval(string);
				
				if(gMapIcon[i][mPosX] != 0.0 || gMapIcon[i][mPosY] != 0.0)
				{
					gMapIcon[i][mIconId] = CreateDynamicMapIcon(gMapIcon[i][mPosX], gMapIcon[i][mPosY], gMapIcon[i][mPosZ], gMapIcon[i][mType], gMapIcon[i][mColor], gMapIcon[i][mWorld], gMapIcon[i][mInterior], -1, gMapIcon[i][mStreamDistance]);
				}
				
				i++;
			}
			
			#if defined DEBUG
				printf("[DEBUG:] LoadMapIcons finished");
			#endif
		}
		case COMPANY_MEMBERS_DISMISS:
		{
			mysql_store_result(db_con1);			
			
			gCompanyMembersCount[playerid] = 0;
			
			while(mysql_retrieve_row(db_con1))
			{			
				mysql_fetch_field_row(string2, "PlayerName", db_con1);
				format(gCompanyMembersToFire[playerid][gCompanyMembersCount[playerid]], MAX_PLAYER_NAME, string2);
				format(string, sizeof(string), "%s\n%s", string, string2);
				
				gCompanyMembersCount[playerid]++;
			}
			
			ShowPlayerDialog(playerid, DIALOG_COMPANY_DISMISS, DIALOG_STYLE_LIST, "Panel firmy - zwolnij", string, "Dalej", "Wróæ");
		}
		case FACTION_MEMBERS_DISMISS:
		{
			mysql_store_result(db_con1);			
			
			gFactionMembersCount[playerid] = 0;
			
			while(mysql_retrieve_row(db_con1))
			{			
				mysql_fetch_field_row(string2, "PlayerName", db_con1);
				format(gFactionMembersToFire[playerid][gFactionMembersCount[playerid]], MAX_PLAYER_NAME, string2);
				format(string, sizeof(string), "%s\n%s", string, string2);
				
				gFactionMembersCount[playerid]++;
			}
			
			ShowPlayerDialog(playerid, DIALOG_FACTION_DISMISS, DIALOG_STYLE_LIST, "Panel frakcji - wyproœ", string, "Dalej", "Wróæ");
		}
		case FACTION_MEMBERS_RANK:
		{
			mysql_store_result(db_con1);			
			
			gFactionMembersCount[playerid] = 0;
			new rank[32];
			
			while(mysql_retrieve_row(db_con1))
			{	
				mysql_fetch_field_row(string2, "Rank", db_con1);
				format(rank, sizeof(rank), string2);
				mysql_fetch_field_row(string2, "PlayerName", db_con1);
				format(gFactionMembersToFire[playerid][gFactionMembersCount[playerid]], MAX_PLAYER_NAME, string2);
				format(string, sizeof(string), "%s\n%s - %s", string, string2, rank);
				
				gFactionMembersCount[playerid]++;
			}
			
			ShowPlayerDialog(playerid, DIALOG_FACTION_RANK, DIALOG_STYLE_LIST, "Panel frakcji - rangi", string, "Dalej", "Wróæ");
		}
		case LOAD_PICKUP_INFOS:
		{
			mysql_store_result(db_con2);
			
			new i = 0;
			
			while(mysql_retrieve_row(db_con2))
			{
				mysql_fetch_field_row(string, "PosX", db_con2);
				gPickupInfos[i][mPosX] = floatstr(string);
				mysql_fetch_field_row(string, "PosY", db_con2);
				gPickupInfos[i][mPosY] = floatstr(string);
				mysql_fetch_field_row(string, "PosZ", db_con2);
				gPickupInfos[i][mPosZ] = floatstr(string);
				mysql_fetch_field_row(string, "World", db_con2);
				gPickupInfos[i][mWorld] = strval(string);
				mysql_fetch_field_row(string, "Interior", db_con2);
				gPickupInfos[i][mInterior] = strval(string);
				mysql_fetch_field_row(string, "PickupModel", db_con2);
				gPickupInfos[i][mPickupModel] = strval(string);
				mysql_fetch_field_row(string, "PickupType", db_con2);
				gPickupInfos[i][mPickupType] = strval(string);
				mysql_fetch_field_row(string, "InfoTextLine1", db_con2);
				format(gPickupInfos[i][mInfoTextLine1], 128, string);
				mysql_fetch_field_row(string, "InfoTextLine2", db_con2);
				format(gPickupInfos[i][mInfoTextLine2], 128, string);
				mysql_fetch_field_row(string, "InfoTextLine3", db_con2);
				format(gPickupInfos[i][mInfoTextLine3], 128, string);
				mysql_fetch_field_row(string, "InfoTextType", db_con2);
				gPickupInfos[i][mInfoTextType] = strval(string);
				
				if(gPickupInfos[i][mPosX] != 0.0 && gPickupInfos[i][mPosY] != 0.0)
				{
					gPickupInfos[i][mPickupId] = CreateDynamicPickup(gPickupInfos[i][mPickupModel], gPickupInfos[i][mPickupType], gPickupInfos[i][mPosX], gPickupInfos[i][mPosY], gPickupInfos[i][mPosZ], gPickupInfos[i][mWorld], gPickupInfos[i][mInterior]); 
					
					if(gPickupInfos[i][mInfoTextType] == 0)
					{
						gPickupInfos[i][m3dText1Id] = CreateDynamic3DTextLabel(gPickupInfos[i][mInfoTextLine1], COLOR_YELLOW, gPickupInfos[i][mPosX], gPickupInfos[i][mPosY], gPickupInfos[i][mPosZ]+0.9,  10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, gPickupInfos[i][mWorld], gPickupInfos[i][mInterior]);
						gPickupInfos[i][m3dText2Id] = CreateDynamic3DTextLabel(gPickupInfos[i][mInfoTextLine2], COLOR_YELLOW, gPickupInfos[i][mPosX], gPickupInfos[i][mPosY], gPickupInfos[i][mPosZ]+0.6,  10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, gPickupInfos[i][mWorld], gPickupInfos[i][mInterior]);
						gPickupInfos[i][m3dText3Id] = CreateDynamic3DTextLabel(gPickupInfos[i][mInfoTextLine3], COLOR_YELLOW, gPickupInfos[i][mPosX], gPickupInfos[i][mPosY], gPickupInfos[i][mPosZ]+0.3,  10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, gPickupInfos[i][mWorld], gPickupInfos[i][mInterior]);
					}
				}
				
				i++;
			}
			
			#if defined DEBUG
				printf("[DEBUG:] LoadPickupInfos finished");
			#endif
		}
		case LOAD_PUBLIC_ADS:
		{
			mysql_store_result(db_con2);
		
			new i = 0;
		
			while(mysql_retrieve_row(db_con2))
			{
				mysql_fetch_field_row(string, "Owner", db_con2);
				format(gPublicAds[i][mOwner], MAX_PLAYER_NAME, string);
				mysql_fetch_field_row(string, "ObjPosX", db_con2);
				gPublicAds[i][mObjPosX] = floatstr(string);
				mysql_fetch_field_row(string, "ObjPosY", db_con2);
				gPublicAds[i][mObjPosY] = floatstr(string);
				mysql_fetch_field_row(string, "ObjPosZ", db_con2);
				gPublicAds[i][mObjPosZ] = floatstr(string);
				mysql_fetch_field_row(string, "ObjRotX", db_con2);
				gPublicAds[i][mObjRotX] = floatstr(string);
				mysql_fetch_field_row(string, "ObjRotY", db_con2);
				gPublicAds[i][mObjRotY] = floatstr(string);
				mysql_fetch_field_row(string, "ObjRotZ", db_con2);
				gPublicAds[i][mObjRotZ] = floatstr(string);
				
				mysql_fetch_field_row(string, "ObjWorld", db_con2);
				gPublicAds[i][mObjWorld] = strval(string);
				
				mysql_fetch_field_row(string, "CpPosX", db_con2);
				gPublicAds[i][mCpPosX] = floatstr(string);
				mysql_fetch_field_row(string, "CpPosY", db_con2);
				gPublicAds[i][mCpPosY] = floatstr(string);
				mysql_fetch_field_row(string, "CpPosZ", db_con2);
				gPublicAds[i][mCpPosZ] = floatstr(string);
				
				mysql_fetch_field_row(string, "CpWorld", db_con2);
				gPublicAds[i][mCpWorld] = strval(string);				
				
				mysql_fetch_field_row(string, "AdLine1Content", db_con2);
				format(gPublicAds[i][mAdLine1Content], 65, string);
				mysql_fetch_field_row(string, "AdLine1TimeLeft", db_con2);
				gPublicAds[i][mAdLine1TimeLeft] = strval(string);
				mysql_fetch_field_row(string, "AdLine1Owner", db_con2);
				format(gPublicAds[i][mAdLine1Owner], MAX_PLAYER_NAME, string);
				
				mysql_fetch_field_row(string, "AdLine2Content", db_con2);
				format(gPublicAds[i][mAdLine2Content], 65, string);
				mysql_fetch_field_row(string, "AdLine2TimeLeft", db_con2);
				gPublicAds[i][mAdLine2TimeLeft] = strval(string);
				mysql_fetch_field_row(string, "AdLine2Owner", db_con2);
				format(gPublicAds[i][mAdLine2Owner], MAX_PLAYER_NAME, string);
				
				mysql_fetch_field_row(string, "AdLine3Content", db_con2);
				format(gPublicAds[i][mAdLine3Content], 65, string);
				mysql_fetch_field_row(string, "AdLine3TimeLeft", db_con2);
				gPublicAds[i][mAdLine3TimeLeft] = strval(string);
				mysql_fetch_field_row(string, "AdLine3Owner", db_con2);
				format(gPublicAds[i][mAdLine3Owner], MAX_PLAYER_NAME, string);
				
				mysql_fetch_field_row(string, "AdLine4Content", db_con2);
				format(gPublicAds[i][mAdLine4Content], 65, string);
				mysql_fetch_field_row(string, "AdLine4TimeLeft", db_con2);
				gPublicAds[i][mAdLine4TimeLeft] = strval(string);
				mysql_fetch_field_row(string, "AdLine4Owner", db_con2);
				format(gPublicAds[i][mAdLine4Owner], MAX_PLAYER_NAME, string);
				
				mysql_fetch_field_row(string, "AdLine5Content", db_con2);
				format(gPublicAds[i][mAdLine5Content], 65, string);
				mysql_fetch_field_row(string, "AdLine5TimeLeft", db_con2);
				gPublicAds[i][mAdLine5TimeLeft] = strval(string);
				mysql_fetch_field_row(string, "AdLine5Owner", db_con2);
				format(gPublicAds[i][mAdLine5Owner], MAX_PLAYER_NAME, string);
				
				mysql_fetch_field_row(string, "AdLine6Content", db_con2);
				format(gPublicAds[i][mAdLine6Content], 65, string);
				mysql_fetch_field_row(string, "AdLine6TimeLeft", db_con2);
				gPublicAds[i][mAdLine6TimeLeft] = strval(string);
				mysql_fetch_field_row(string, "AdLine6Owner", db_con2);
				format(gPublicAds[i][mAdLine6Owner], MAX_PLAYER_NAME, string);
				
				mysql_fetch_field_row(string, "AdLine7Content", db_con2);
				format(gPublicAds[i][mAdLine7Content], 65, string);
				mysql_fetch_field_row(string, "AdLine7TimeLeft", db_con2);
				gPublicAds[i][mAdLine7TimeLeft] = strval(string);
				mysql_fetch_field_row(string, "AdLine7Owner", db_con2);
				format(gPublicAds[i][mAdLine7Owner], MAX_PLAYER_NAME, string);
				
				mysql_fetch_field_row(string, "AdLine8Content", db_con2);
				format(gPublicAds[i][mAdLine8Content], 65, string);
				mysql_fetch_field_row(string, "AdLine8TimeLeft", db_con2);
				gPublicAds[i][mAdLine8TimeLeft] = strval(string);
				mysql_fetch_field_row(string, "AdLine8Owner", db_con2);
				format(gPublicAds[i][mAdLine8Owner], MAX_PLAYER_NAME, string);
				
				mysql_fetch_field_row(string, "AdLine9Content", db_con2);
				format(gPublicAds[i][mAdLine9Content], 65, string);
				mysql_fetch_field_row(string, "AdLine9TimeLeft", db_con2);
				gPublicAds[i][mAdLine9TimeLeft] = strval(string);
				mysql_fetch_field_row(string, "AdLine9Owner", db_con2);
				format(gPublicAds[i][mAdLine9Owner], MAX_PLAYER_NAME, string);
				
				mysql_fetch_field_row(string, "AdLine10Content", db_con2);
				format(gPublicAds[i][mAdLine10Content], 65, string);
				mysql_fetch_field_row(string, "AdLine10TimeLeft", db_con2);
				gPublicAds[i][mAdLine10TimeLeft] = strval(string);
				mysql_fetch_field_row(string, "AdLine10Owner", db_con2);
				format(gPublicAds[i][mAdLine10Owner], MAX_PLAYER_NAME, string);
				
				if(gPublicAds[i][mObjPosX] != 0.0 || gPublicAds[i][mObjPosY] != 0.0)
				{				
					gPublicAds[i][mObjId] = CreateDynamicObject(3335, gPublicAds[i][mObjPosX], gPublicAds[i][mObjPosY], gPublicAds[i][mObjPosZ], gPublicAds[i][mObjRotX], gPublicAds[i][mObjRotY], gPublicAds[i][mObjRotZ], gPublicAds[i][mObjWorld]);
					SetDynamicObjectRot(gPublicAds[i][mObjId], gPublicAds[i][mObjRotX], gPublicAds[i][mObjRotY], gPublicAds[i][mObjRotZ]);
					defer RefreshPublicAd(i);
				}
				
				if(gPublicAds[i][mCpPosX] != 0.0 || gPublicAds[i][mCpPosX] != 0.0)
				{
					//gPublicAds[i][mCpId] = CreateDynamicCP(gPublicAds[i][mCpPosX], gPublicAds[i][mCpPosY], gPublicAds[i][mCpPosZ], 0.5, gPublicAds[i][mCpWorld]);
				}
				
				i++;
			}
			
			#if defined DEBUG
				printf("[DEBUG:] LoadPublicAds finished");
			#endif
		}
		case PLAYER_LOAD_FUEL:
		{
			#if defined DEBUG
				printf("[DEBUG:][PLAYER_LOAD_FUEL] pid = %d, pname = %s", playerid, gPlayerData[playerid][pName]);
			#endif
			
			if(playerid != CUSTOM_MAX_PLAYERS)
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Czekaj, trwa ³adowanie danych [dane tankowañ]...");
			
			mysql_store_result(db_con2);
			
			if(mysql_num_rows(db_con2) == 0 && playerid < CUSTOM_MAX_PLAYERS)
			{
				for(new i = 0; i <= BIZ_CPN_ID; i++)
				{
					format(string, sizeof(string), "INSERT INTO `samp_users_fueled` (`PlayerName`, `BizID`) VALUES ('%s', '%d')", gPlayerData[playerid][pName], i);
					wp_mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
				}
			}
			else
			{
				new bizId;
				
				while(mysql_retrieve_row(db_con2))
				{
					mysql_fetch_field_row(string, "BizID", db_con2);
					bizId = strval(string);
					
					mysql_fetch_field_row(string, "BizPetrol", db_con2);
					gPlayerData[playerid][pGasStationRefPetrol][bizId] = floatstr(string);
					mysql_fetch_field_row(string, "BizOil", db_con2);
					gPlayerData[playerid][pGasStationRefOil][bizId] = floatstr(string);
					mysql_fetch_field_row(string, "BizGas", db_con2);
					gPlayerData[playerid][pGasStationRefGas][bizId] = floatstr(string);
				}
			}
		}
		case PLAYER_VEHICLE_CASH:
		{
			mysql_store_result(db_con2);
			
			if(mysql_num_rows(db_con2))
			{
				mysql_retrieve_row(db_con2);
				
				mysql_fetch_field_row(string, "PlayerName", db_con2);
				
				UpdatePlayerDataByName(string, "Bank", gVehData[playerid][Price]);
			}
		}
		case LOAD_ITEMS_FOR_DELETE:
		{
			new slot, slotId;
			
			mysql_store_result(db_con2);
			
			while(mysql_retrieve_row(db_con2))
			{
				mysql_fetch_field_row(string, "PlayerName", db_con2);
				format(gPlayerData[playerid][pName], MAX_PLAYER_NAME, string);
				mysql_fetch_field_row(string, "Item1", db_con2);
				gPlayerData[playerid][pItem1] = strval(string);
				mysql_fetch_field_row(string, "Item2", db_con2);
				gPlayerData[playerid][pItem2] = strval(string);
				mysql_fetch_field_row(string, "Item3", db_con2);
				gPlayerData[playerid][pItem3] = strval(string);
				mysql_fetch_field_row(string, "Item4", db_con2);
				gPlayerData[playerid][pItem4] = strval(string);
				mysql_fetch_field_row(string, "Item5", db_con2);
				gPlayerData[playerid][pItem5] = strval(string);
				mysql_fetch_field_row(string, "Item1type", db_con2);
				gPlayerData[playerid][pItem1type] = strval(string);
				mysql_fetch_field_row(string, "Item2type", db_con2);
				gPlayerData[playerid][pItem2type] = strval(string);
				mysql_fetch_field_row(string, "Item3type", db_con2);
				gPlayerData[playerid][pItem3type] = strval(string);
				mysql_fetch_field_row(string, "Item4type", db_con2);
				gPlayerData[playerid][pItem4type] = strval(string);
				mysql_fetch_field_row(string, "Item5type", db_con2);
				gPlayerData[playerid][pItem5type] = strval(string);
				mysql_fetch_field_row(string, "Item1param", db_con2);
				gPlayerData[playerid][pItem1param] = strval(string);
				mysql_fetch_field_row(string, "Item2param", db_con2);
				gPlayerData[playerid][pItem2param] = strval(string);
				mysql_fetch_field_row(string, "Item3param", db_con2);
				gPlayerData[playerid][pItem3param] = strval(string);
				mysql_fetch_field_row(string, "Item4param", db_con2);
				gPlayerData[playerid][pItem4param] = strval(string);
				mysql_fetch_field_row(string, "Item5param", db_con2);
				gPlayerData[playerid][pItem5param] = strval(string);
				mysql_fetch_field_row(string, "Item1param2", db_con2);
				gPlayerData[playerid][pItem1param2] = strval(string);
				mysql_fetch_field_row(string, "Item2param2", db_con2);
				gPlayerData[playerid][pItem2param2] = strval(string);
				mysql_fetch_field_row(string, "Item3param2", db_con2);
				gPlayerData[playerid][pItem3param2] = strval(string);
				mysql_fetch_field_row(string, "Item4param2", db_con2);
				gPlayerData[playerid][pItem4param2] = strval(string);
				mysql_fetch_field_row(string, "Item5param2", db_con2);
				gPlayerData[playerid][pItem5param2] = strval(string);
				mysql_fetch_field_row(string, "Item1param3", db_con2);
				gPlayerData[playerid][pItem1param3] = strval(string);
				mysql_fetch_field_row(string, "Item2param3", db_con2);
				gPlayerData[playerid][pItem2param3] = strval(string);
				mysql_fetch_field_row(string, "Item3param3", db_con2);
				gPlayerData[playerid][pItem3param3] = strval(string);
				mysql_fetch_field_row(string, "Item4param3", db_con2);
				gPlayerData[playerid][pItem4param3] = strval(string);
				mysql_fetch_field_row(string, "Item5param3", db_con2);
				gPlayerData[playerid][pItem5param3] = strval(string);
				mysql_fetch_field_row(string, "Item1param4", db_con2);
				gPlayerData[playerid][pItem1param4] = strval(string);
				mysql_fetch_field_row(string, "Item2param4", db_con2);
				gPlayerData[playerid][pItem2param4] = strval(string);
				mysql_fetch_field_row(string, "Item3param4", db_con2);
				gPlayerData[playerid][pItem3param4] = strval(string);
				mysql_fetch_field_row(string, "Item4param4", db_con2);
				gPlayerData[playerid][pItem4param4] = strval(string);
				mysql_fetch_field_row(string, "Item5param4", db_con2);
				gPlayerData[playerid][pItem5param4] = strval(string);
				mysql_fetch_field_row(string, "Item1param5", db_con2);
				format(gPlayerData[playerid][pItem1param5], 64, string);
				mysql_fetch_field_row(string, "Item2param5", db_con2);
				format(gPlayerData[playerid][pItem2param5], 64, string);
				mysql_fetch_field_row(string, "Item3param5", db_con2);
				format(gPlayerData[playerid][pItem3param5], 64, string);
				mysql_fetch_field_row(string, "Item4param5", db_con2);
				format(gPlayerData[playerid][pItem4param5], 64, string);
				mysql_fetch_field_row(string, "Item5param5", db_con2);
				format(gPlayerData[playerid][pItem5param5], 64, string);
				mysql_fetch_field_row(string, "Item1param6", db_con2);
				gPlayerData[playerid][pItem1param6] = strval(string);
				mysql_fetch_field_row(string, "Item2param6", db_con2);
				gPlayerData[playerid][pItem2param6] = strval(string);
				mysql_fetch_field_row(string, "Item3param6", db_con2);
				gPlayerData[playerid][pItem3param6] = strval(string);
				mysql_fetch_field_row(string, "Item4param6", db_con2);
				gPlayerData[playerid][pItem4param6] = strval(string);
				mysql_fetch_field_row(string, "Item5param6", db_con2);
				gPlayerData[playerid][pItem5param6] = strval(string);
				
				for(new pSlotId = 0; pSlotId < MAX_PLAYER_ITEM_SLOT; pSlotId++)
				{
					slot = PHaveItem(playerid, gSearchItemType, gSearchItemId, pSlotId);
					
					if(slot == 0)
					{
						continue;
					}
					
					if(gSearchItemParam1 != -999)
					{
						if(SlotParam1(playerid, slotId) != gSearchItemParam1)
						{
							continue;
						}
					}
						
					if(gSearchItemParam2 != -999)
					{
						if(SlotParam2(playerid, slotId) != gSearchItemParam2)
						{
							continue;
						}
					}
					
					if(gSearchItemParam3 != -999)
					{
						if(SlotParam3(playerid, slotId) != gSearchItemParam3)
						{
							continue;
						}
					}
					
					if(gSearchItemParam4 != -999)
					{	
						if(SlotParam4(playerid, slotId) != gSearchItemParam4)
						{
							continue;
						}
					}
					
					if(strlen(gSearchItemParam5) != 0)
					{
						SlotParam5(playerid, slotId);
						
						if(strcmp(gDSelectedItemP5[playerid], gSearchItemParam5, false) != 0)
						{
							continue;
						}
					}
					
					RemovePlayerItemUsed(playerid, slotId);
				}
			}
			
			format(string, sizeof(string), "SELECT HIGH_PRIORITY * FROM `samp_users_items2`");
			wp_mysql_query(string, LOAD_ITEMS2_FOR_DELETE, CUSTOM_MAX_PLAYERS, db_con2);
		}
		case LOAD_ITEMS2_FOR_DELETE:
		{
			new slot, slotId;
		
			mysql_store_result(db_con2);
			
			while(mysql_retrieve_row(db_con2))
			{
				mysql_fetch_field_row(string, "PlayerName", db_con2);
				format(gPlayerData[playerid][pName], MAX_PLAYER_NAME, string);
				mysql_fetch_field_row(string, "Item6", db_con2);
				gPlayerData[playerid][pItem6] = strval(string);
				mysql_fetch_field_row(string, "Item7", db_con2);
				gPlayerData[playerid][pItem7] = strval(string);
				mysql_fetch_field_row(string, "Item8", db_con2);
				gPlayerData[playerid][pItem8] = strval(string);
				mysql_fetch_field_row(string, "Item9", db_con2);
				gPlayerData[playerid][pItem9] = strval(string);
				mysql_fetch_field_row(string, "Item10", db_con2);
				gPlayerData[playerid][pItem10] = strval(string);
				mysql_fetch_field_row(string, "Item6type", db_con2);
				gPlayerData[playerid][pItem6type] = strval(string);
				mysql_fetch_field_row(string, "Item7type", db_con2);
				gPlayerData[playerid][pItem7type] = strval(string);
				mysql_fetch_field_row(string, "Item8type", db_con2);
				gPlayerData[playerid][pItem8type] = strval(string);
				mysql_fetch_field_row(string, "Item9type", db_con2);
				gPlayerData[playerid][pItem9type] = strval(string);
				mysql_fetch_field_row(string, "Item10type", db_con2);
				gPlayerData[playerid][pItem10type] = strval(string);
				mysql_fetch_field_row(string, "Item6param", db_con2);
				gPlayerData[playerid][pItem6param] = strval(string);
				mysql_fetch_field_row(string, "Item7param", db_con2);
				gPlayerData[playerid][pItem7param] = strval(string);
				mysql_fetch_field_row(string, "Item8param", db_con2);
				gPlayerData[playerid][pItem8param] = strval(string);
				mysql_fetch_field_row(string, "Item9param", db_con2);
				gPlayerData[playerid][pItem9param] = strval(string);
				mysql_fetch_field_row(string, "Item10param", db_con2);
				gPlayerData[playerid][pItem10param] = strval(string);
				mysql_fetch_field_row(string, "Item6param2", db_con2);
				gPlayerData[playerid][pItem6param2] = strval(string);
				mysql_fetch_field_row(string, "Item7param2", db_con2);
				gPlayerData[playerid][pItem7param2] = strval(string);
				mysql_fetch_field_row(string, "Item8param2", db_con2);
				gPlayerData[playerid][pItem8param2] = strval(string);
				mysql_fetch_field_row(string, "Item9param2", db_con2);
				gPlayerData[playerid][pItem9param2] = strval(string);
				mysql_fetch_field_row(string, "Item10param2", db_con2);
				gPlayerData[playerid][pItem10param2] = strval(string);
				mysql_fetch_field_row(string, "Item6param3", db_con2);
				gPlayerData[playerid][pItem6param3] = strval(string);
				mysql_fetch_field_row(string, "Item7param3", db_con2);
				gPlayerData[playerid][pItem7param3] = strval(string);
				mysql_fetch_field_row(string, "Item8param3", db_con2);
				gPlayerData[playerid][pItem8param3] = strval(string);
				mysql_fetch_field_row(string, "Item9param3", db_con2);
				gPlayerData[playerid][pItem9param3] = strval(string);
				mysql_fetch_field_row(string, "Item10param3", db_con2);
				gPlayerData[playerid][pItem10param3] = strval(string);
				mysql_fetch_field_row(string, "Item6param4", db_con2);
				gPlayerData[playerid][pItem6param4] = strval(string);
				mysql_fetch_field_row(string, "Item7param4", db_con2);
				gPlayerData[playerid][pItem7param4] = strval(string);
				mysql_fetch_field_row(string, "Item8param4", db_con2);
				gPlayerData[playerid][pItem8param4] = strval(string);
				mysql_fetch_field_row(string, "Item9param4", db_con2);
				gPlayerData[playerid][pItem9param4] = strval(string);
				mysql_fetch_field_row(string, "Item10param4", db_con2);
				gPlayerData[playerid][pItem10param4] = strval(string);
				mysql_fetch_field_row(string, "Item6param5", db_con2);
				format(gPlayerData[playerid][pItem6param5], 64, string);
				mysql_fetch_field_row(string, "Item7param5", db_con2);
				format(gPlayerData[playerid][pItem7param5], 64, string);
				mysql_fetch_field_row(string, "Item8param5", db_con2);
				format(gPlayerData[playerid][pItem8param5], 64, string);
				mysql_fetch_field_row(string, "Item9param5", db_con2);
				format(gPlayerData[playerid][pItem9param5], 64, string);
				mysql_fetch_field_row(string, "Item10param5", db_con2);
				format(gPlayerData[playerid][pItem10param5], 64, string);
				mysql_fetch_field_row(string, "Item6param6", db_con2);
				gPlayerData[playerid][pItem6param6] = strval(string);
				mysql_fetch_field_row(string, "Item7param6", db_con2);
				gPlayerData[playerid][pItem7param6] = strval(string);
				mysql_fetch_field_row(string, "Item8param6", db_con2);
				gPlayerData[playerid][pItem8param6] = strval(string);
				mysql_fetch_field_row(string, "Item9param6", db_con2);
				gPlayerData[playerid][pItem9param6] = strval(string);
				mysql_fetch_field_row(string, "Item10param6", db_con2);
				gPlayerData[playerid][pItem10param6] = strval(string);
				
				for(new pSlotId = 0; pSlotId < MAX_PLAYER_ITEM_SLOT; pSlotId++)
				{
					slot = PHaveItem(playerid, gSearchItemType, gSearchItemId, pSlotId);
					
					if(slot == 0)
					{
						continue;
					}
					
					if(gSearchItemParam1 != -999)
					{
						if(SlotParam1(playerid, slotId) != gSearchItemParam1)
						{
							continue;
						}
					}
						
					if(gSearchItemParam2 != -999)
					{
						if(SlotParam2(playerid, slotId) != gSearchItemParam2)
						{
							continue;
						}
					}
					
					if(gSearchItemParam3 != -999)
					{
						if(SlotParam3(playerid, slotId) != gSearchItemParam3)
						{
							continue;
						}
					}
					
					if(gSearchItemParam4 != -999)
					{	
						if(SlotParam4(playerid, slotId) != gSearchItemParam4)
						{
							continue;
						}
					}
					
					if(strlen(gSearchItemParam5) != 0)
					{
						SlotParam5(playerid, slotId);
						
						if(strcmp(gDSelectedItemP5[playerid], gSearchItemParam5, false) != 0)
						{
							continue;
						}
					}
					
					RemovePlayerItemUsed(playerid, slotId);
				}
			}
			
			format(string, sizeof(string), "SELECT HIGH_PRIORITY * FROM `samp_users_items3`");
			wp_mysql_query(string, LOAD_ITEMS3_FOR_DELETE, CUSTOM_MAX_PLAYERS, db_con2);
		}
		case LOAD_ITEMS3_FOR_DELETE:
		{
			new slot, slotId;
		
			mysql_store_result(db_con2);
			
			while(mysql_retrieve_row(db_con2))
			{
				mysql_fetch_field_row(string, "PlayerName", db_con2);
				format(gPlayerData[playerid][pName], MAX_PLAYER_NAME, string);
				mysql_fetch_field_row(string, "Item11", db_con2);
				gPlayerData[playerid][pItem11] = strval(string);
				mysql_fetch_field_row(string, "Item12", db_con2);
				gPlayerData[playerid][pItem12] = strval(string);
				mysql_fetch_field_row(string, "Item13", db_con2);
				gPlayerData[playerid][pItem13] = strval(string);
				mysql_fetch_field_row(string, "Item14", db_con2);
				gPlayerData[playerid][pItem14] = strval(string);
				mysql_fetch_field_row(string, "Item15", db_con2);
				gPlayerData[playerid][pItem15] = strval(string);
				mysql_fetch_field_row(string, "Item16", db_con2);
				gPlayerData[playerid][pItem16] = strval(string);
				mysql_fetch_field_row(string, "Item17", db_con2);
				gPlayerData[playerid][pItem17] = strval(string);
				mysql_fetch_field_row(string, "Item18", db_con2);
				gPlayerData[playerid][pItem18] = strval(string);
				mysql_fetch_field_row(string, "Item19", db_con2);
				gPlayerData[playerid][pItem19] = strval(string);
				mysql_fetch_field_row(string, "Item20", db_con2);
				gPlayerData[playerid][pItem20] = strval(string);
				mysql_fetch_field_row(string, "Item21", db_con2);
				gPlayerData[playerid][pItem21] = strval(string);
				mysql_fetch_field_row(string, "Item22", db_con2);
				gPlayerData[playerid][pItem22] = strval(string);
				mysql_fetch_field_row(string, "Item23", db_con2);
				gPlayerData[playerid][pItem23] = strval(string);
				mysql_fetch_field_row(string, "Item24", db_con2);
				gPlayerData[playerid][pItem24] = strval(string);
				mysql_fetch_field_row(string, "Item25", db_con2);
				gPlayerData[playerid][pItem25] = strval(string);
				mysql_fetch_field_row(string, "Item11type", db_con2);
				gPlayerData[playerid][pItem11type] = strval(string);
				mysql_fetch_field_row(string, "Item12type", db_con2);
				gPlayerData[playerid][pItem12type] = strval(string);
				mysql_fetch_field_row(string, "Item13type", db_con2);
				gPlayerData[playerid][pItem13type] = strval(string);
				mysql_fetch_field_row(string, "Item14type", db_con2);
				gPlayerData[playerid][pItem14type] = strval(string);
				mysql_fetch_field_row(string, "Item15type", db_con2);
				gPlayerData[playerid][pItem15type] = strval(string);
				mysql_fetch_field_row(string, "Item16type", db_con2);
				gPlayerData[playerid][pItem16type] = strval(string);
				mysql_fetch_field_row(string, "Item17type", db_con2);
				gPlayerData[playerid][pItem17type] = strval(string);
				mysql_fetch_field_row(string, "Item18type", db_con2);
				gPlayerData[playerid][pItem18type] = strval(string);
				mysql_fetch_field_row(string, "Item19type", db_con2);
				gPlayerData[playerid][pItem19type] = strval(string);
				mysql_fetch_field_row(string, "Item20type", db_con2);
				gPlayerData[playerid][pItem20type] = strval(string);
				mysql_fetch_field_row(string, "Item21type", db_con2);
				gPlayerData[playerid][pItem21type] = strval(string);
				mysql_fetch_field_row(string, "Item22type", db_con2);
				gPlayerData[playerid][pItem22type] = strval(string);
				mysql_fetch_field_row(string, "Item23type", db_con2);
				gPlayerData[playerid][pItem23type] = strval(string);
				mysql_fetch_field_row(string, "Item24type", db_con2);
				gPlayerData[playerid][pItem24type] = strval(string);
				mysql_fetch_field_row(string, "Item25type", db_con2);
				gPlayerData[playerid][pItem25type] = strval(string);
				mysql_fetch_field_row(string, "Item11param", db_con2);
				gPlayerData[playerid][pItem11param] = strval(string);
				mysql_fetch_field_row(string, "Item12param", db_con2);
				gPlayerData[playerid][pItem12param] = strval(string);
				mysql_fetch_field_row(string, "Item13param", db_con2);
				gPlayerData[playerid][pItem13param] = strval(string);
				mysql_fetch_field_row(string, "Item14param", db_con2);
				gPlayerData[playerid][pItem14param] = strval(string);
				mysql_fetch_field_row(string, "Item15param", db_con2);
				gPlayerData[playerid][pItem15param] = strval(string);
				mysql_fetch_field_row(string, "Item16param", db_con2);
				gPlayerData[playerid][pItem16param] = strval(string);
				mysql_fetch_field_row(string, "Item17param", db_con2);
				gPlayerData[playerid][pItem17param] = strval(string);
				mysql_fetch_field_row(string, "Item18param", db_con2);
				gPlayerData[playerid][pItem18param] = strval(string);
				mysql_fetch_field_row(string, "Item19param", db_con2);
				gPlayerData[playerid][pItem19param] = strval(string);
				mysql_fetch_field_row(string, "Item20param", db_con2);
				gPlayerData[playerid][pItem20param] = strval(string);
				mysql_fetch_field_row(string, "Item21param", db_con2);
				gPlayerData[playerid][pItem21param] = strval(string);
				mysql_fetch_field_row(string, "Item22param", db_con2);
				gPlayerData[playerid][pItem22param] = strval(string);
				mysql_fetch_field_row(string, "Item23param", db_con2);
				gPlayerData[playerid][pItem23param] = strval(string);
				mysql_fetch_field_row(string, "Item24param", db_con2);
				gPlayerData[playerid][pItem24param] = strval(string);
				mysql_fetch_field_row(string, "Item25param", db_con2);
				gPlayerData[playerid][pItem25param] = strval(string);
				mysql_fetch_field_row(string, "Item11param2", db_con2);
				gPlayerData[playerid][pItem11param2] = strval(string);
				mysql_fetch_field_row(string, "Item12param2", db_con2);
				gPlayerData[playerid][pItem12param2] = strval(string);
				mysql_fetch_field_row(string, "Item13param2", db_con2);
				gPlayerData[playerid][pItem13param2] = strval(string);
				mysql_fetch_field_row(string, "Item14param2", db_con2);
				gPlayerData[playerid][pItem14param2] = strval(string);
				mysql_fetch_field_row(string, "Item15param2", db_con2);
				gPlayerData[playerid][pItem15param2] = strval(string);
				mysql_fetch_field_row(string, "Item16param2", db_con2);
				gPlayerData[playerid][pItem16param2] = strval(string);
				mysql_fetch_field_row(string, "Item17param2", db_con2);
				gPlayerData[playerid][pItem17param2] = strval(string);
				mysql_fetch_field_row(string, "Item18param2", db_con2);
				gPlayerData[playerid][pItem18param2] = strval(string);
				mysql_fetch_field_row(string, "Item19param2", db_con2);
				gPlayerData[playerid][pItem19param2] = strval(string);
				mysql_fetch_field_row(string, "Item20param2", db_con2);
				gPlayerData[playerid][pItem20param2] = strval(string);
				mysql_fetch_field_row(string, "Item21param2", db_con2);
				gPlayerData[playerid][pItem21param2] = strval(string);
				mysql_fetch_field_row(string, "Item22param2", db_con2);
				gPlayerData[playerid][pItem22param2] = strval(string);
				mysql_fetch_field_row(string, "Item23param2", db_con2);
				gPlayerData[playerid][pItem23param2] = strval(string);
				mysql_fetch_field_row(string, "Item24param2", db_con2);
				gPlayerData[playerid][pItem24param2] = strval(string);
				mysql_fetch_field_row(string, "Item25param2", db_con2);
				gPlayerData[playerid][pItem25param2] = strval(string);
				mysql_fetch_field_row(string, "Item11param3", db_con2);
				gPlayerData[playerid][pItem11param3] = strval(string);
				mysql_fetch_field_row(string, "Item12param3", db_con2);
				gPlayerData[playerid][pItem12param3] = strval(string);
				mysql_fetch_field_row(string, "Item13param3", db_con2);
				gPlayerData[playerid][pItem13param3] = strval(string);
				mysql_fetch_field_row(string, "Item14param3", db_con2);
				gPlayerData[playerid][pItem14param3] = strval(string);
				mysql_fetch_field_row(string, "Item15param3", db_con2);
				gPlayerData[playerid][pItem15param3] = strval(string);
				mysql_fetch_field_row(string, "Item16param3", db_con2);
				gPlayerData[playerid][pItem16param3] = strval(string);
				mysql_fetch_field_row(string, "Item17param3", db_con2);
				gPlayerData[playerid][pItem17param3] = strval(string);
				mysql_fetch_field_row(string, "Item18param3", db_con2);
				gPlayerData[playerid][pItem18param3] = strval(string);
				mysql_fetch_field_row(string, "Item19param3", db_con2);
				gPlayerData[playerid][pItem19param3] = strval(string);
				mysql_fetch_field_row(string, "Item20param3", db_con2);
				gPlayerData[playerid][pItem20param3] = strval(string);
				mysql_fetch_field_row(string, "Item21param3", db_con2);
				gPlayerData[playerid][pItem21param3] = strval(string);
				mysql_fetch_field_row(string, "Item22param3", db_con2);
				gPlayerData[playerid][pItem22param3] = strval(string);
				mysql_fetch_field_row(string, "Item23param3", db_con2);
				gPlayerData[playerid][pItem23param3] = strval(string);
				mysql_fetch_field_row(string, "Item24param3", db_con2);
				gPlayerData[playerid][pItem24param3] = strval(string);
				mysql_fetch_field_row(string, "Item25param3", db_con2);
				gPlayerData[playerid][pItem25param3] = strval(string);
				mysql_fetch_field_row(string, "Item11param4", db_con2);
				gPlayerData[playerid][pItem11param4] = strval(string);
				mysql_fetch_field_row(string, "Item12param4", db_con2);
				gPlayerData[playerid][pItem12param4] = strval(string);
				mysql_fetch_field_row(string, "Item13param4", db_con2);
				gPlayerData[playerid][pItem13param4] = strval(string);
				mysql_fetch_field_row(string, "Item14param4", db_con2);
				gPlayerData[playerid][pItem14param4] = strval(string);
				mysql_fetch_field_row(string, "Item15param4", db_con2);
				gPlayerData[playerid][pItem15param4] = strval(string);
				mysql_fetch_field_row(string, "Item16param4", db_con2);
				gPlayerData[playerid][pItem16param4] = strval(string);
				mysql_fetch_field_row(string, "Item17param4", db_con2);
				gPlayerData[playerid][pItem17param4] = strval(string);
				mysql_fetch_field_row(string, "Item18param4", db_con2);
				gPlayerData[playerid][pItem18param4] = strval(string);
				mysql_fetch_field_row(string, "Item19param4", db_con2);
				gPlayerData[playerid][pItem19param4] = strval(string);
				mysql_fetch_field_row(string, "Item20param4", db_con2);
				gPlayerData[playerid][pItem20param4] = strval(string);
				mysql_fetch_field_row(string, "Item21param4", db_con2);
				gPlayerData[playerid][pItem21param4] = strval(string);
				mysql_fetch_field_row(string, "Item22param4", db_con2);
				gPlayerData[playerid][pItem22param4] = strval(string);
				mysql_fetch_field_row(string, "Item23param4", db_con2);
				gPlayerData[playerid][pItem23param4] = strval(string);
				mysql_fetch_field_row(string, "Item24param4", db_con2);
				gPlayerData[playerid][pItem24param4] = strval(string);
				mysql_fetch_field_row(string, "Item25param4", db_con2);
				gPlayerData[playerid][pItem25param4] = strval(string);
				mysql_fetch_field_row(string, "Item11param5", db_con2);
				format(gPlayerData[playerid][pItem11param5], 64, string);
				mysql_fetch_field_row(string, "Item12param5", db_con2);
				format(gPlayerData[playerid][pItem12param5], 64, string);
				mysql_fetch_field_row(string, "Item13param5", db_con2);
				format(gPlayerData[playerid][pItem13param5], 64, string);
				mysql_fetch_field_row(string, "Item14param5", db_con2);
				format(gPlayerData[playerid][pItem14param5], 64, string);
				mysql_fetch_field_row(string, "Item15param5", db_con2);
				format(gPlayerData[playerid][pItem15param5], 64, string);
				mysql_fetch_field_row(string, "Item16param5", db_con2);
				format(gPlayerData[playerid][pItem16param5], 64, string);
				mysql_fetch_field_row(string, "Item17param5", db_con2);
				format(gPlayerData[playerid][pItem17param5], 64, string);
				mysql_fetch_field_row(string, "Item18param5", db_con2);
				format(gPlayerData[playerid][pItem18param5], 64, string);
				mysql_fetch_field_row(string, "Item19param5", db_con2);
				format(gPlayerData[playerid][pItem19param5], 64, string);
				mysql_fetch_field_row(string, "Item20param5", db_con2);
				format(gPlayerData[playerid][pItem20param5], 64, string);
				mysql_fetch_field_row(string, "Item21param5", db_con2);
				format(gPlayerData[playerid][pItem21param5], 64, string);
				mysql_fetch_field_row(string, "Item22param5", db_con2);
				format(gPlayerData[playerid][pItem22param5], 64, string);
				mysql_fetch_field_row(string, "Item23param5", db_con2);
				format(gPlayerData[playerid][pItem23param5], 64, string);
				mysql_fetch_field_row(string, "Item24param5", db_con2);
				format(gPlayerData[playerid][pItem24param5], 64, string);
				mysql_fetch_field_row(string, "Item25param5", db_con2);
				format(gPlayerData[playerid][pItem25param5], 64, string);
				mysql_fetch_field_row(string, "Item11param6", db_con2);
				gPlayerData[playerid][pItem11param6] = strval(string);
				mysql_fetch_field_row(string, "Item12param6", db_con2);
				gPlayerData[playerid][pItem12param6] = strval(string);
				mysql_fetch_field_row(string, "Item13param6", db_con2);
				gPlayerData[playerid][pItem13param6] = strval(string);
				mysql_fetch_field_row(string, "Item14param6", db_con2);
				gPlayerData[playerid][pItem14param6] = strval(string);
				mysql_fetch_field_row(string, "Item15param6", db_con2);
				gPlayerData[playerid][pItem15param6] = strval(string);
				mysql_fetch_field_row(string, "Item16param6", db_con2);
				gPlayerData[playerid][pItem16param6] = strval(string);
				mysql_fetch_field_row(string, "Item17param6", db_con2);
				gPlayerData[playerid][pItem17param6] = strval(string);
				mysql_fetch_field_row(string, "Item18param6", db_con2);
				gPlayerData[playerid][pItem18param6] = strval(string);
				mysql_fetch_field_row(string, "Item19param6", db_con2);
				gPlayerData[playerid][pItem19param6] = strval(string);
				mysql_fetch_field_row(string, "Item20param6", db_con2);
				gPlayerData[playerid][pItem20param6] = strval(string);
				mysql_fetch_field_row(string, "Item21param6", db_con2);
				gPlayerData[playerid][pItem21param6] = strval(string);
				mysql_fetch_field_row(string, "Item22param6", db_con2);
				gPlayerData[playerid][pItem22param6] = strval(string);
				mysql_fetch_field_row(string, "Item23param6", db_con2);
				gPlayerData[playerid][pItem23param6] = strval(string);
				mysql_fetch_field_row(string, "Item24param6", db_con2);
				gPlayerData[playerid][pItem24param6] = strval(string);
				mysql_fetch_field_row(string, "Item25param6", db_con2);
				gPlayerData[playerid][pItem25param6] = strval(string);
				
				for(new pSlotId = 0; pSlotId < MAX_PLAYER_ITEM_SLOT; pSlotId++)
				{
					slot = PHaveItem(playerid, gSearchItemType, gSearchItemId, pSlotId);
					
					if(slot == 0)
					{
						continue;
					}
					
					if(gSearchItemParam1 != -999)
					{
						if(SlotParam1(playerid, slotId) != gSearchItemParam1)
						{
							continue;
						}
					}
						
					if(gSearchItemParam2 != -999)
					{
						if(SlotParam2(playerid, slotId) != gSearchItemParam2)
						{
							continue;
						}
					}
					
					if(gSearchItemParam3 != -999)
					{
						if(SlotParam3(playerid, slotId) != gSearchItemParam3)
						{
							continue;
						}
					}
					
					if(gSearchItemParam4 != -999)
					{	
						if(SlotParam4(playerid, slotId) != gSearchItemParam4)
						{
							continue;
						}
					}
					
					if(strlen(gSearchItemParam5) != 0)
					{
						SlotParam5(playerid, slotId);
						
						if(strcmp(gDSelectedItemP5[playerid], gSearchItemParam5, false) != 0)
						{
							continue;
						}
					}
					
					RemovePlayerItemUsed(playerid, slotId);
				}
			}
		}
		case CASH_FOR_EXPORT_VEH:
		{
			mysql_store_result(db_con2);
			
			if(mysql_num_rows(db_con2))
			{
				mysql_retrieve_row(db_con2);
				
				mysql_fetch_field_row(string, "PlayerName", db_con2);
				
				UpdatePlayerDataByName(string, "Bank", floatround(cenyPojazdow[gVehData[extraid-1][mVehModel]-400]*0.1));
			}
		}
		default:
		{
			//wp_mysql_free_result(db_con1);
			//wp_mysql_free_result(db_con2);
			//wp_mysql_free_result(db_con3);
			//wp_mysql_free_result(db_con4);
		}
	}
		
	return 1;
}