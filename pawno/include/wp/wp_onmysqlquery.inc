#include <a_samp>
#include <wp_variables>
#include <streamer>
#include <mysql>

public OnMysqlQueryArray(resultid, extravars[], MySQL:handle)
{
	new arrCoords[50][64];
	new PlayerNameTMP[128];
	new arrayData[2][256];
	new tmpData[256];
	new string[128];
	format(tmpData, sizeof(tmpData), "%s", extravars);
	split2(tmpData, arrayData, '|');
	new playerid = strval(arrayData[0]);
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
			if( !mysql_store_result(db_con2) )
			{
				printf("[ERROR:] Can't store result on PLAYER_LOAD_FUEL");
				return 1;
			}
			if(mysql_num_rows(db_con2) == 0)
			{
				format(string, sizeof(string), "INSERT INTO `samp_users_fueled` (`PlayerName`, `BizID`) VALUES ('%s', '%d')", PlayerNameTMP, bizID );
				mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			}
			else
			{
				mysql_fetch_row(db_result, "|", db_con2);
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
}

public OnMysqlQuery(resultid, spareid, MySQL:handle)
{
	new arrCoords[153][64];
	new PlayerNameTMP[128];
	new playerid = spareid;
	new string[128];
	if( playerid < CUSTOM_MAX_PLAYERS )
		GetPlayerName(playerid,PlayerNameTMP, sizeof(PlayerNameTMP));

	switch(resultid)
	{
		case PLAYER_DATA_LOAD_NAME_MYSQL:
		{
			GetPlayerName(playerid, string, sizeof(string));
			// printf("[DEBUG:][PLAYER_LOAD_NAME_MYSQL] pid = %d, pname = %s", playerid, string);
			if( !mysql_store_result(db_con2) )
			{
				printf("[ERROR:] Can't store result on PLAYER_DATA_LOAD_NAME_MYSQL");
				return 1;
			}
			mysql_fetch_row(db_result, "|", db_con2);
			
			if(mysql_num_rows(db_con2) <= 0 )
			{
				mysql_free_result(db_con2);
				gPayDayLoop++;
				if( gPayDayLoop <= gPayDayCount )
				{
					new stringtmp1[2048];
					if( gPayDayLoop <= gPayDayCount )
					{
						format(stringtmp1, sizeof(stringtmp1), "SELECT `Key`,`ID`,`PlayerName`,`Level`,`AdminLevel`,`DonateRank`,`Registered`,`Sex`,`Age`,`Experience`,`Money`,`Bank`,`Skin`,`PlayingHours`,`AllowedPayday`,`PayCheck`,`Faction`,`Rank`,`Banned`");
						strcat( stringtmp1, ",`Warnings`,`Jailed`,`JailTime`,`CrashX`,`CrashY`,`CrashZ`,`CrashInt`,`CrashW`,`Crashed`,`Wins`,`Loses`,`InvWeapon`,`InvAmmo`,`Tutorial`,`Moderator`,`WantedLvl`,`FirstCar`,`FirstReanimation`,`FirstPhone`,`FirstLeader`" );
						strcat( stringtmp1, ",`CrashAngle`,`HourAssist`,`JoinedFaction`,`HoursOnDuty`,`HoursOnDutyHelper`,`WarnCooldown`,`SpeedLimiter`,`AdminDuty`,`CharDescription`,`CharDescriptionColor`, `FirstJob`, `FirstID`, `FirstBuy`, `FirstHouse`, `FirstDescription`" );
						strcat( stringtmp1, ", `FirstAction`, `FirstBankUse`, `FirstStats`, `FirstJail`, `FirstStudy`" );
						format( stringtmp1, sizeof(stringtmp1), "%s FROM `samp_users` WHERE `Banned` = '0' LIMIT %d , 1", stringtmp1, gPayDayLoop);
						mysql_query(stringtmp1, PLAYER_DATA_LOAD_NAME_MYSQL, CUSTOM_MAX_PLAYERS, db_con2);
					}
				}
				return 1;
			}			
			new TmpData[256];
			
			mysql_fetch_field("PlayerName", gPlayerData[CUSTOM_MAX_PLAYERS][pName], db_con2);
			mysql_fetch_field("Level", TmpData, db_con2);
			gPlayerData[CUSTOM_MAX_PLAYERS][pLevel] = strval(TmpData);
			mysql_fetch_field("AdminLevel", TmpData, db_con2);
			gPlayerData[CUSTOM_MAX_PLAYERS][pAdmin] = strval(TmpData);
			mysql_fetch_field("DonateRank", TmpData, db_con2);
			gPlayerData[CUSTOM_MAX_PLAYERS][pDonateRank] = strval(TmpData);
			mysql_fetch_field("Registered", TmpData, db_con2);
			gPlayerData[CUSTOM_MAX_PLAYERS][pRegistered] = strval(TmpData);
			mysql_fetch_field("Sex", TmpData, db_con2);
			gPlayerData[CUSTOM_MAX_PLAYERS][pSex] = strval(TmpData);
			mysql_fetch_field("Age", TmpData, db_con2);
			gPlayerData[CUSTOM_MAX_PLAYERS][pAge] = strval(TmpData);
			mysql_fetch_field("Experience", TmpData, db_con2);
			gPlayerData[CUSTOM_MAX_PLAYERS][pExp] = strval(TmpData);
			mysql_fetch_field("Money", TmpData, db_con2);
			gPlayerData[CUSTOM_MAX_PLAYERS][pCash] = strval(TmpData);
			mysql_fetch_field("Bank", TmpData, db_con2);
			gPlayerData[CUSTOM_MAX_PLAYERS][pBank] = strval(TmpData);
			mysql_fetch_field("Skin", TmpData, db_con2);
			gPlayerData[CUSTOM_MAX_PLAYERS][pSkin] = strval(TmpData);
			mysql_fetch_field("PlayingHours", TmpData, db_con2);
			gPlayerData[CUSTOM_MAX_PLAYERS][pPlayingHours] = strval(TmpData);
			mysql_fetch_field("AllowedPayday", TmpData, db_con2);
			gPlayerData[CUSTOM_MAX_PLAYERS][pAllowedPayday] = strval(TmpData);
			mysql_fetch_field("PayCheck", TmpData, db_con2);
			gPlayerData[CUSTOM_MAX_PLAYERS][pPayCheck] = strval(TmpData);
			mysql_fetch_field("Faction", TmpData, db_con2);
			gPlayerData[CUSTOM_MAX_PLAYERS][pFaction] = strval(TmpData);
			mysql_fetch_field("Rank", TmpData, db_con2);
			gPlayerData[CUSTOM_MAX_PLAYERS][pRank] = strval(TmpData);
			mysql_fetch_field("Banned", TmpData, db_con2);
			gPlayerData[CUSTOM_MAX_PLAYERS][pBanned] = strval(TmpData);
			mysql_fetch_field("Warnings", TmpData, db_con2);
			gPlayerData[CUSTOM_MAX_PLAYERS][pWarnings] = strval(TmpData);
			mysql_fetch_field("Jailed", TmpData, db_con2);
			gPlayerData[CUSTOM_MAX_PLAYERS][pJailed] = strval(TmpData);
			mysql_fetch_field("JailTime", TmpData, db_con2);
			gPlayerData[CUSTOM_MAX_PLAYERS][pJailTime] = strval(TmpData);
			mysql_fetch_field("CrashX", TmpData, db_con2);
			gPlayerData[CUSTOM_MAX_PLAYERS][pCrashX] = floatstr(TmpData);
			mysql_fetch_field("CrashY", TmpData, db_con2);
			gPlayerData[CUSTOM_MAX_PLAYERS][pCrashY] = floatstr(TmpData);
			mysql_fetch_field("CrashZ", TmpData, db_con2);
			gPlayerData[CUSTOM_MAX_PLAYERS][pCrashZ] = floatstr(TmpData);
			mysql_fetch_field("CrashInt", TmpData, db_con2);
			gPlayerData[CUSTOM_MAX_PLAYERS][pCrashInt] = strval(TmpData);
			mysql_fetch_field("CrashW", TmpData, db_con2);
			gPlayerData[CUSTOM_MAX_PLAYERS][pCrashW] = strval(TmpData);
			mysql_fetch_field("Crashed", TmpData, db_con2);
			gPlayerData[CUSTOM_MAX_PLAYERS][pCrashed] = strval(TmpData);
			mysql_fetch_field("Wins", TmpData, db_con2);
			gPlayerData[CUSTOM_MAX_PLAYERS][pWins] = strval(TmpData);
			mysql_fetch_field("Loses", TmpData, db_con2);
			gPlayerData[CUSTOM_MAX_PLAYERS][pLoses] = strval(TmpData);
			mysql_fetch_field("InvWeapon", TmpData, db_con2);
			gPlayerData[CUSTOM_MAX_PLAYERS][pInvWeapon] = strval(TmpData);
			mysql_fetch_field("InvAmmo", TmpData, db_con2);
			gPlayerData[CUSTOM_MAX_PLAYERS][pInvAmmo] = strval(TmpData);
			mysql_fetch_field("Tutorial", TmpData, db_con2);
			gPlayerData[CUSTOM_MAX_PLAYERS][pTutorial] = strval(TmpData);
			mysql_fetch_field("Moderator", TmpData, db_con2);
			gPlayerData[CUSTOM_MAX_PLAYERS][pModerator] = strval(TmpData);
			mysql_fetch_field("WantedLvl", TmpData, db_con2);
			gPlayerData[CUSTOM_MAX_PLAYERS][pWantedLvl] = strval(TmpData);
			mysql_fetch_field("FirstCar", TmpData, db_con2);
			gPlayerData[CUSTOM_MAX_PLAYERS][pFirstCar] = strval(TmpData);
			mysql_fetch_field("FirstReanimation", TmpData, db_con2);
			gPlayerData[CUSTOM_MAX_PLAYERS][pFirstReanimation] = strval(TmpData);
			mysql_fetch_field("FirstPhone", TmpData, db_con2);
			gPlayerData[CUSTOM_MAX_PLAYERS][pFirstPhone] = strval(TmpData);
			mysql_fetch_field("FirstLeader", TmpData, db_con2);
			gPlayerData[CUSTOM_MAX_PLAYERS][pFirstLeader] = strval(TmpData);
			mysql_fetch_field("FirstJob", TmpData, db_con2);
			gPlayerData[CUSTOM_MAX_PLAYERS][pFirstJob] = strval(TmpData);
			mysql_fetch_field("FirstID", TmpData, db_con2);
			gPlayerData[CUSTOM_MAX_PLAYERS][pFirstID] = strval(TmpData);
			mysql_fetch_field("FirstBuy", TmpData, db_con2);
			gPlayerData[CUSTOM_MAX_PLAYERS][pFirstBuy] = strval(TmpData);
			mysql_fetch_field("FirstHouse", TmpData, db_con2);
			gPlayerData[CUSTOM_MAX_PLAYERS][pFirstHouse] = strval(TmpData);
			mysql_fetch_field("FirstDescription", TmpData, db_con2);
			gPlayerData[CUSTOM_MAX_PLAYERS][pFirstDescription] = strval(TmpData);
			mysql_fetch_field("FirstAction", TmpData, db_con2);
			gPlayerData[CUSTOM_MAX_PLAYERS][pFirstAction] = strval(TmpData);
			mysql_fetch_field("FirstBankUse", TmpData, db_con2);
			gPlayerData[CUSTOM_MAX_PLAYERS][pFirstBankUse] = strval(TmpData);
			mysql_fetch_field("FirstStats", TmpData, db_con2);
			gPlayerData[CUSTOM_MAX_PLAYERS][pFirstStats] = strval(TmpData);
			mysql_fetch_field("FirstJail", TmpData, db_con2);
			gPlayerData[CUSTOM_MAX_PLAYERS][pFirstJail] = strval(TmpData);
			mysql_fetch_field("FirstStudy", TmpData, db_con2);
			gPlayerData[CUSTOM_MAX_PLAYERS][pFirstStudy] = strval(TmpData);
			mysql_fetch_field("CrashAngle", TmpData, db_con2);
			gPlayerData[CUSTOM_MAX_PLAYERS][pCrashAngle] = floatstr(TmpData);
			mysql_fetch_field("HourAssist", TmpData, db_con2);
			gPlayerData[CUSTOM_MAX_PLAYERS][pHourAssist] = strval(TmpData);
			mysql_fetch_field("JoinedFaction", TmpData, db_con2);
			gPlayerData[CUSTOM_MAX_PLAYERS][pJoinedFaction] = strval(TmpData);
			mysql_fetch_field("HoursOnDuty", TmpData, db_con2);
			gPlayerData[CUSTOM_MAX_PLAYERS][pHoursOnDuty] = strval(TmpData);
			mysql_fetch_field("HoursOnDutyHelper", TmpData, db_con2);
			gPlayerData[CUSTOM_MAX_PLAYERS][pHoursOnDutyHelper] = strval(TmpData);
			mysql_fetch_field("WarnCooldown", TmpData, db_con2);
			gPlayerData[CUSTOM_MAX_PLAYERS][pWarnCooldown] = strval(TmpData);
			
			mysql_free_result(db_con2);
			
			printf("[PAYDAY:] gPayDayLoop = %d, Player name: %s",  gPayDayLoop, gPlayerData[CUSTOM_MAX_PLAYERS][pName] );
			
			format( string, sizeof(string), "SELECT * FROM `samp_users_keys` WHERE `PlayerName` = '%s' LIMIT 1", gPlayerData[CUSTOM_MAX_PLAYERS][pName] );
			mysql_query(string, PLAYER_DATA_LOAD_KEYS_MYSQL, CUSTOM_MAX_PLAYERS, db_con2);

			// format( string, sizeof(string), "SELECT * FROM `samp_users_other` WHERE `PlayerName` = '%s' ", gPlayerData[CUSTOM_MAX_PLAYERS][pName] );
			// mysql_query(string, PLAYER_DATA_LOAD_OTHER_MYSQL, CUSTOM_MAX_PLAYERS, db_con2);

			// format( string, sizeof(string), "SELECT * FROM `samp_users_items` WHERE `PlayerName` = '%s' ", gPlayerData[CUSTOM_MAX_PLAYERS][pName] );
			// mysql_query(string, PLAYER_DATA_LOAD_ITEMS_MYSQL, CUSTOM_MAX_PLAYERS, db_con2);
			
			// format( string, sizeof(string), "SELECT * FROM `samp_users_items2` WHERE `PlayerName` = '%s' ", gPlayerData[CUSTOM_MAX_PLAYERS][pName] );
			// mysql_query(string, PLAYER_DATA_LOAD_ITEMS2_MYSQL, CUSTOM_MAX_PLAYERS, db_con2);
			
			// format( string, sizeof(string), "SELECT * FROM `samp_users_items3` WHERE `PlayerName` = '%s' ", gPlayerData[CUSTOM_MAX_PLAYERS][pName]) ;
			// mysql_query(string, PLAYER_DATA_LOAD_ITEMS3_MYSQL, CUSTOM_MAX_PLAYERS, db_con2);

			// format( string, sizeof(string), "SELECT * FROM `samp_users_jobs` WHERE `PlayerName` = '%s' ", gPlayerData[CUSTOM_MAX_PLAYERS][pName] );
			// mysql_query(string, PLAYER_DATA_LOAD_JOB_MYSQL, CUSTOM_MAX_PLAYERS, db_con2);

			// format( string, sizeof(string), "SELECT * FROM `samp_users_lic` WHERE `PlayerName` = '%s' ", gPlayerData[CUSTOM_MAX_PLAYERS][pName] );
			// mysql_query(string, PLAYER_DATA_LOAD_LIC_MYSQL, CUSTOM_MAX_PLAYERS, db_con2);

			// format( string, sizeof(string), "SELECT * FROM `samp_users_notes` WHERE `PlayerName` = '%s' ", gPlayerData[CUSTOM_MAX_PLAYERS][pName] );
			// mysql_query(string, PLAYER_DATA_LOAD_NOTES_MYSQL, CUSTOM_MAX_PLAYERS, db_con2);
			
			// format( string, sizeof(string), "SELECT * FROM `samp_users_vip` WHERE `PlayerName` = '%s'", gPlayerData[CUSTOM_MAX_PLAYERS][pName] );
			// mysql_query(string, PLAYER_DATA_LOAD_VIP_MYSQL, CUSTOM_MAX_PLAYERS, db_con2);
			
			// format( string, sizeof(string), "SELECT * FROM `samp_users_other2` WHERE `PlayerName` = '%s'", gPlayerData[CUSTOM_MAX_PLAYERS][pName] );
			// mysql_query(string, PLAYER_DATA_LOAD_OTHER2_MYSQL, CUSTOM_MAX_PLAYERS, db_con2);
		}
		case PLAYER_DATA_LOAD_FIRST_MYSQL:
		{
			new tmpName[32];
			GetPlayerName( playerid, tmpName, sizeof(tmpName) );
			// printf("[DEBUG:][PLAYER_LOAD_FIRST_MYSQL] pid = %d, pname = %s", playerid, tmpName);
			ClearScreen(playerid);
			if( !mysql_store_result(db_con2) )
			{
				printf("[ERROR:] Can't store result on PLAYER_DATA_LOAD_FIRST_MYSQL");
				return 1;
			}
		
			new loginstr[1024];
			/* Check if row exist */
			if(mysql_num_rows(db_con2) <= 0)
			{
				strcat( loginstr, "{FFFFFF}Witaj na serwerze WParty !\n\n" );
				strcat( loginstr, "Aby siê zalogowaæ wpisz swoje has³o do postaci.\n\n\n" );
				strcat( loginstr, "{F52222}Ta nazwa postaci nie jest zarejestrowana !\nJeœli nie posiadasz jeszcze postaci musisz wpierw zarejestrowaæ swoje konto\nna forum wpartyrp.pl a nastêpnei utworzyæ postaæ\npostêpuj¹æ wed³ug podanych tam wskazówek.\n\n" );
				strcat( loginstr, "{FAEC25}Jeœli zapomnia³eœ has³a do postaci mo¿esz je zmieniæ loguj¹c siê na forum\na nastêpnie przechodz¹c do panelu zarz¹dzania postaciami.\n\n\n" );
				strcat( loginstr, "{FFFFFF}Wpisz has³o:" );
				ShowPlayerDialog(playerid, DIALOG_LOGIN, DIALOG_STYLE_PASSWORD, "Logowanie", loginstr, "Zaloguj", "");
				mysql_free_result(db_con2);
				return 1;
			}
			mysql_fetch_row(db_result, "|", db_con2);
			split2(db_result, arrCoords, '|');
			mysql_free_result(db_con2);
			if(strlen(arrCoords[1]) < 5)
			{
				strcat( loginstr, "{FFFFFF}Witaj na serwerze WParty !\n\n" );
				strcat( loginstr, "Aby siê zalogowaæ wpisz swoje has³o do postaci.\n\n\n" );
				strcat( loginstr, "{F52222}Ta nazwa postaci jest za krótka !\nAby utworzyæ inn¹ postaæ o d³u¿ej nazwie przejdŸ na strone wpartyrp.pl a nastêpnie w panelu zarz¹dzania postaciami utwórz\nnow¹ postaæ o odpowiednio d³ugiej nazwie.\n\n" );
				strcat( loginstr, "{FAEC25}Jeœli zapomnia³eœ has³a do postaci mo¿esz je zmieniæ loguj¹c siê na forum\na nastêpnie przechodz¹c do panelu zarz¹dzania postaciami.\n\n\n" );
				strcat( loginstr, "{FFFFFF}Wpisz has³o:" );
				ShowPlayerDialog(playerid, DIALOG_LOGIN, DIALOG_STYLE_PASSWORD, "Logowanie", loginstr, "Zaloguj", "");
				return 1;
			}
			if(strcmp(arrCoords[0], gPasswd[playerid], false ) != 0 || strlen(gPasswd[playerid]) <= 0)
			{
				strcat( loginstr, "{FFFFFF}Witaj na serwerze WParty !\n\n" );
				strcat( loginstr, "Aby siê zalogowaæ wpisz swoje has³o do postaci.\n\n\n" );
				strcat( loginstr, "{FAEC25}Jeœli zapomnia³eœ has³a do postaci mo¿esz je zmieniæ loguj¹c siê na forum\na nastêpnie przechodz¹c do panelu zarz¹dzania postaciami.\n\n\n" );
				strcat( loginstr, "{F52222}B£ÊDNE HAS£O !\n" );
				strcat( loginstr, "{FFFFFF}Wpisz ponownie has³o:" );
				ShowPlayerDialog(playerid, DIALOG_LOGIN, DIALOG_STYLE_PASSWORD, "Logowanie", loginstr, "Zaloguj", "");
				return 1;
			}
			if( strcmp( gPlayerData[playerid][pSName], tmpName, false, 32 ) != 0 )
			{
				strcat( loginstr, "{FFFFFF}Witaj na serwerze WParty !\n\n" );
				strcat( loginstr, "Aby siê zalogowaæ wpisz swoje has³o do postaci.\n\n\n" );
				strcat( loginstr, "{FAEC25}Jeœli zapomnia³eœ has³a do postaci mo¿esz je zmieniæ loguj¹c siê na forum\na nastêpnie przechodz¹c do panelu zarz¹dzania postaciami.\n\n\n" );
				strcat( loginstr, "{F52222}NIEZGODNA NAZWA U¯YTKOWNIKA !\n" );
				strcat( loginstr, "{FFFFFF}Wpisz ponownie has³o:" );
				ShowPlayerDialog(playerid, DIALOG_LOGIN, DIALOG_STYLE_PASSWORD, "Logowanie", loginstr, "Zaloguj", "");
				return 1;
			}
			
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Czekaj, trwa ³adowanie danych...");
			
			new stringtmp1[2048];
			format(stringtmp1, sizeof(stringtmp1), "SELECT `Key`,`ID`,`PlayerName`,`Level`,`AdminLevel`,`DonateRank`,`Registered`,`Sex`,`Age`,`Experience`,`Money`,`Bank`,`Skin`,`PlayingHours`,`AllowedPayday`,`PayCheck`,`Faction`,`Rank`,`Banned`");
			strcat( stringtmp1, ",`Warnings`,`Jailed`,`JailTime`,`CrashX`,`CrashY`,`CrashZ`,`CrashInt`,`CrashW`,`Crashed`,`Wins`,`Loses`,`InvWeapon`,`InvAmmo`,`Tutorial`,`Moderator`,`WantedLvl`,`FirstCar`,`FirstReanimation`,`FirstPhone`,`FirstLeader`" );
			strcat( stringtmp1, ",`CrashAngle`,`HourAssist`,`JoinedFaction`,`HoursOnDuty`,`HoursOnDutyHelper`,`WarnCooldown`,`SpeedLimiter`,`AdminDuty`,`CharDescription`,`CharDescriptionColor`, `FirstJob`, `FirstID`, `FirstBuy`, `FirstHouse`, `FirstDescription`" );
			strcat( stringtmp1, ", `FirstAction`, `FirstBankUse`, `FirstStats`, `FirstJail`, `FirstStudy`" );
			format( stringtmp1, sizeof(stringtmp1), "%s FROM `samp_users` WHERE `PlayerName` = '%s' LIMIT 1", stringtmp1, PlayerNameTMP);			
			mysql_query(stringtmp1, PLAYER_DATA_LOAD_USER_MYSQL, playerid, db_con2);

			// format(string, sizeof(string), "SELECT * FROM `samp_users_keys` WHERE `PlayerName` = '%s' ", PlayerNameTMP);
			// mysql_query(string, PLAYER_DATA_LOAD_KEYS_MYSQL, playerid, db_con2);

			// format(string, sizeof(string), "SELECT * FROM `samp_users_other` WHERE `PlayerName` = '%s' ", PlayerNameTMP);
			// mysql_query(string, PLAYER_DATA_LOAD_OTHER_MYSQL, playerid, db_con2);

			// format(string, sizeof(string), "SELECT * FROM `samp_users_items` WHERE `PlayerName` = '%s' ", PlayerNameTMP);
			// mysql_query(string, PLAYER_DATA_LOAD_ITEMS_MYSQL, playerid, db_con2);
			
			// format(string, sizeof(string), "SELECT * FROM `samp_users_items2` WHERE `PlayerName` = '%s' ", PlayerNameTMP);
			// mysql_query(string, PLAYER_DATA_LOAD_ITEMS2_MYSQL, playerid, db_con2);
			
			// format(string, sizeof(string), "SELECT * FROM `samp_users_items3` WHERE `PlayerName` = '%s' ", PlayerNameTMP);
			// mysql_query(string, PLAYER_DATA_LOAD_ITEMS3_MYSQL, playerid, db_con2);

			// format(string, sizeof(string), "SELECT * FROM `samp_users_jobs` WHERE `PlayerName` = '%s' ", PlayerNameTMP);
			// mysql_query(string, PLAYER_DATA_LOAD_JOB_MYSQL, playerid, db_con2);

			// format(string, sizeof(string), "SELECT * FROM `samp_users_lic` WHERE `PlayerName` = '%s' ", PlayerNameTMP);
			// mysql_query(string, PLAYER_DATA_LOAD_LIC_MYSQL, playerid, db_con2);

			// format(string, sizeof(string), "SELECT * FROM `samp_users_notes` WHERE `PlayerName` = '%s' ", PlayerNameTMP);
			// mysql_query(string, PLAYER_DATA_LOAD_NOTES_MYSQL, playerid, db_con2);

			// format(string, sizeof(string), "SELECT * FROM `samp_users_vip` WHERE `PlayerName` = '%s'", PlayerNameTMP);
			// mysql_query(string, PLAYER_DATA_LOAD_VIP_MYSQL, playerid, db_con2);
			
			// format(string, sizeof(string), "SELECT * FROM `samp_users_other2` WHERE `PlayerName` = '%s'", PlayerNameTMP);
			// mysql_query(string, PLAYER_DATA_LOAD_OTHER2_MYSQL, playerid, db_con2);

			return 1;
		}
		case PLAYER_DATA_LOAD_USER_MYSQL:
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Czekaj, trwa ³adowanie danych [dane podstawowe]...");
			new TmpData[256];
			
			if( !mysql_store_result(db_con2) )
			{
				printf("[ERROR:] Can't store result on PLAYER_DATA_LOAD_USER_MYSQL");
				if( playerid != CUSTOM_MAX_PLAYERS )
					SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Wyst¹pi³ b³¹d przy ³adowaniu danych twojego konta. Jeœli problem bêdzie siê powtarza³ skontaktuj siê z administratorem" );
				return 1;
			}
			mysql_fetch_row(db_result, "|", db_con2);
			mysql_fetch_field("PlayerName", gPlayerData[playerid][pName], db_con2);
			mysql_fetch_field("Level", TmpData, db_con2);
			gPlayerData[playerid][pLevel] = strval(TmpData);
			mysql_fetch_field("AdminLevel", TmpData, db_con2);
			gPlayerData[playerid][pAdmin] = strval(TmpData);
			mysql_fetch_field("DonateRank", TmpData, db_con2);
			gPlayerData[playerid][pDonateRank] = strval(TmpData);
			mysql_fetch_field("Registered", TmpData, db_con2);
			gPlayerData[playerid][pRegistered] = strval(TmpData);
			mysql_fetch_field("Sex", TmpData, db_con2);
			gPlayerData[playerid][pSex] = strval(TmpData);
			mysql_fetch_field("Age", TmpData, db_con2);
			gPlayerData[playerid][pAge] = strval(TmpData);
			mysql_fetch_field("Experience", TmpData, db_con2);
			gPlayerData[playerid][pExp] = strval(TmpData);
			mysql_fetch_field("Money", TmpData, db_con2);
			gPlayerData[playerid][pCash] = strval(TmpData);
			mysql_fetch_field("Bank", TmpData, db_con2);
			gPlayerData[playerid][pBank] = strval(TmpData);
			mysql_fetch_field("Skin", TmpData, db_con2);
			gPlayerData[playerid][pSkin] = strval(TmpData);
			mysql_fetch_field("PlayingHours", TmpData, db_con2);
			gPlayerData[playerid][pPlayingHours] = strval(TmpData);
			mysql_fetch_field("AllowedPayday", TmpData, db_con2);
			gPlayerData[playerid][pAllowedPayday] = strval(TmpData);
			mysql_fetch_field("PayCheck", TmpData, db_con2);
			gPlayerData[playerid][pPayCheck] = strval(TmpData);
			mysql_fetch_field("Faction", TmpData, db_con2);
			gPlayerData[playerid][pFaction] = strval(TmpData);
			mysql_fetch_field("Rank", TmpData, db_con2);
			gPlayerData[playerid][pRank] = strval(TmpData);
			mysql_fetch_field("Banned", TmpData, db_con2);
			gPlayerData[playerid][pBanned] = strval(TmpData);
			mysql_fetch_field("Warnings", TmpData, db_con2);
			gPlayerData[playerid][pWarnings] = strval(TmpData);
			mysql_fetch_field("Jailed", TmpData, db_con2);
			gPlayerData[playerid][pJailed] = strval(TmpData);
			mysql_fetch_field("JailTime", TmpData, db_con2);
			gPlayerData[playerid][pJailTime] = strval(TmpData);
			mysql_fetch_field("CrashX", TmpData, db_con2);
			gPlayerData[playerid][pCrashX] = floatstr(TmpData);
			mysql_fetch_field("CrashY", TmpData, db_con2);
			gPlayerData[playerid][pCrashY] = floatstr(TmpData);
			mysql_fetch_field("CrashZ", TmpData, db_con2);
			gPlayerData[playerid][pCrashZ] = floatstr(TmpData);
			mysql_fetch_field("CrashInt", TmpData, db_con2);
			gPlayerData[playerid][pCrashInt] = strval(TmpData);
			mysql_fetch_field("CrashW", TmpData, db_con2);
			gPlayerData[playerid][pCrashW] = strval(TmpData);
			mysql_fetch_field("Crashed", TmpData, db_con2);
			gPlayerData[playerid][pCrashed] = strval(TmpData);
			mysql_fetch_field("Wins", TmpData, db_con2);
			gPlayerData[playerid][pWins] = strval(TmpData);
			mysql_fetch_field("Loses", TmpData, db_con2);
			gPlayerData[playerid][pLoses] = strval(TmpData);
			mysql_fetch_field("InvWeapon", TmpData, db_con2);
			gPlayerData[playerid][pInvWeapon] = strval(TmpData);
			mysql_fetch_field("InvAmmo", TmpData, db_con2);
			gPlayerData[playerid][pInvAmmo] = strval(TmpData);
			mysql_fetch_field("Tutorial", TmpData, db_con2);
			gPlayerData[playerid][pTutorial] = strval(TmpData);
			mysql_fetch_field("Moderator", TmpData, db_con2);
			gPlayerData[playerid][pModerator] = strval(TmpData);
			mysql_fetch_field("WantedLvl", TmpData, db_con2);
			gPlayerData[playerid][pWantedLvl] = strval(TmpData);
			mysql_fetch_field("FirstCar", TmpData, db_con2);
			gPlayerData[playerid][pFirstCar] = strval(TmpData);
			mysql_fetch_field("FirstReanimation", TmpData, db_con2);
			gPlayerData[playerid][pFirstReanimation] = strval(TmpData);
			mysql_fetch_field("FirstPhone", TmpData, db_con2);
			gPlayerData[playerid][pFirstPhone] = strval(TmpData);
			mysql_fetch_field("FirstLeader", TmpData, db_con2);
			gPlayerData[playerid][pFirstLeader] = strval(TmpData);
			mysql_fetch_field("FirstJob", TmpData, db_con2);
			gPlayerData[playerid][pFirstJob] = strval(TmpData);
			mysql_fetch_field("FirstID", TmpData, db_con2);
			gPlayerData[playerid][pFirstID] = strval(TmpData);
			mysql_fetch_field("FirstBuy", TmpData, db_con2);
			gPlayerData[playerid][pFirstBuy] = strval(TmpData);
			mysql_fetch_field("FirstHouse", TmpData, db_con2);
			gPlayerData[playerid][pFirstHouse] = strval(TmpData);
			mysql_fetch_field("FirstDescription", TmpData, db_con2);
			gPlayerData[playerid][pFirstDescription] = strval(TmpData);
			mysql_fetch_field("FirstAction", TmpData, db_con2);
			gPlayerData[playerid][pFirstAction] = strval(TmpData);
			mysql_fetch_field("FirstBankUse", TmpData, db_con2);
			gPlayerData[playerid][pFirstBankUse] = strval(TmpData);
			mysql_fetch_field("FirstStats", TmpData, db_con2);
			gPlayerData[playerid][pFirstStats] = strval(TmpData);
			mysql_fetch_field("FirstJail", TmpData, db_con2);
			gPlayerData[playerid][pFirstJail] = strval(TmpData);
			mysql_fetch_field("FirstStudy", TmpData, db_con2);
			gPlayerData[playerid][pFirstStudy] = strval(TmpData);
			mysql_fetch_field("CrashAngle", TmpData, db_con2);
			gPlayerData[playerid][pCrashAngle] = floatstr(TmpData);
			mysql_fetch_field("HourAssist", TmpData, db_con2);
			gPlayerData[playerid][pHourAssist] = strval(TmpData);
			mysql_fetch_field("JoinedFaction", TmpData, db_con2);
			gPlayerData[playerid][pJoinedFaction] = strval(TmpData);
			mysql_fetch_field("HoursOnDuty", TmpData, db_con2);
			gPlayerData[playerid][pHoursOnDuty] = strval(TmpData);
			mysql_fetch_field("HoursOnDutyHelper", TmpData, db_con2);
			gPlayerData[playerid][pHoursOnDutyHelper] = strval(TmpData);
			mysql_fetch_field("WarnCooldown", TmpData, db_con2);
			gPlayerData[playerid][pWarnCooldown] = strval(TmpData);
			mysql_fetch_field("AdminDuty", TmpData, db_con2);
			AdminDuty[playerid] = strval(TmpData);
			mysql_fetch_field("CharDescription", gPlayerData[playerid][pCharDescription], db_con2);
			mysql_fetch_field("CharDescriptionColor", TmpData, db_con2);
			gPlayerData[playerid][pCharDescriptionColor] = strval(TmpData);
			
			mysql_free_result(db_con2);
			
			format( string, sizeof(string), "SELECT * FROM `samp_users_keys` WHERE `PlayerName` = '%s' ", gPlayerData[playerid][pName] );
			mysql_query(string, PLAYER_DATA_LOAD_KEYS_MYSQL, playerid, db_con2);
		}
		case PLAYER_DATA_LOAD_KEYS_MYSQL:
		{
			// printf("[DEBUG:][PLAYER_LOAD_KEYS_MYSQL] pid = %d, pname = %s", playerid, gPlayerData[playerid][pName]);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Czekaj, trwa ³adowanie danych [klucze]...");
			if( !mysql_store_result(db_con2) )
			{
				printf("[ERROR:] Can't store result on PLAYER_DATA_LOAD_KEYS_MYSQL");
				if( playerid != CUSTOM_MAX_PLAYERS )
					SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Wyst¹pi³ b³¹d przy ³adowaniu danych twojego konta. Jeœli problem bêdzie siê powtarza³ skontaktuj siê z administratorem" );
				return 1;
			}
			if(mysql_num_rows(db_con2) == 0)
			{
				mysql_free_result(db_con2);
				new sendername[64];
				GetPlayerName(playerid, sendername, sizeof(sendername));
				format(string, sizeof(string), "INSERT INTO `samp_users_keys` (`PlayerName`) VALUES ('%s')", sendername);
				mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
				
				gPlayerData[playerid][pHouseKey] = 255;
				gPlayerData[playerid][pBizKey] = 255;
			}
			else
			{
				mysql_fetch_row(db_result, "|", db_con2);
				split2(db_result, arrCoords, '|');

				gPlayerData[playerid][pHouseKey] = strval(arrCoords[0]);
				gPlayerData[playerid][pBizKey] = strval(arrCoords[1]);

				if(gPlayerData[playerid][pHouseKey] != 255)
				{
					InsertPlayerItem(playerid, 4, gPlayerData[playerid][pHouseKey], 0, 0);
					gPlayerData[playerid][pHouseKey] = 255;
					SavePlayerData(playerid, "HouseKey");
				}

				mysql_free_result(db_con2);
			}
			format( string, sizeof(string), "SELECT * FROM `samp_users_other` WHERE `PlayerName` = '%s' LIMIT 1", gPlayerData[playerid][pName] );
			mysql_query(string, PLAYER_DATA_LOAD_OTHER_MYSQL, playerid, db_con2);
		}
		case PLAYER_DATA_LOAD_OTHER_MYSQL:
		{
			// printf("[DEBUG:][PLAYER_LOAD_OTHER_MYSQL] pid = %d, pname = %s", playerid, gPlayerData[playerid][pName]);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Czekaj, trwa ³adowanie danych [dane podstawowe]...");
			if( !mysql_store_result(db_con2) )
			{
				printf("[ERROR:] Can't store result on PLAYER_DATA_LOAD_OTHER_MYSQL");
				if( playerid != CUSTOM_MAX_PLAYERS )
					SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Wyst¹pi³ b³¹d przy ³adowaniu danych twojego konta. Jeœli problem bêdzie siê powtarza³ skontaktuj siê z administratorem" );
				return 1;
			}
			if(mysql_num_rows(db_con2) == 0)
			{
				mysql_free_result(db_con2);
				new sendername[64];
				GetPlayerName(playerid, sendername, sizeof(sendername));
				format(string, sizeof(string), "INSERT INTO `samp_users_other` (`PlayerName`) VALUES ('%s')", sendername);
				mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			}
			else
			{	
				mysql_fetch_row(db_result, "|", db_con2);

				split2(db_result, arrCoords, '|');

				// TODO: Replace loading by id to by column name
				// Remove unused columns when loading is changed
				
				// gPlayerData[playerid][pSpawnPoint] = strval(arrCoords[0]);
				// gPlayerData[playerid][pPhoneNumber] = strval(arrCoords[1]);
				gPlayerData[playerid][pPhoneC] = strval(arrCoords[2]);
				gPlayerData[playerid][pPhoneBook] = strval(arrCoords[3]);
				gPlayerData[playerid][pListNumber] = strval(arrCoords[4]);
				gPlayerData[playerid][pDonator] = strval(arrCoords[5]);
				// gPlayerData[playerid][pProducts] = strval(arrCoords[6]);
				gPlayerData[playerid][pDrugs] = strval(arrCoords[7]);
				gPlayerData[playerid][pDrugsEffect] = strval(arrCoords[8]);
				gPlayerData[playerid][pDrugsTaken] = strval(arrCoords[9]);
				gPlayerData[playerid][pDrugsAddicted] = strval(arrCoords[10]);
				gPlayerData[playerid][pMaterials] = strval(arrCoords[11]);
				gPlayerData[playerid][pGoggles] = strval(arrCoords[12]);
				gPlayerData[playerid][pCost] = strval(arrCoords[13]);
				gPlayerData[playerid][pTicket] = strval(arrCoords[14]);
				gPlayerData[playerid][pGPS] = strval(arrCoords[15]);
				gPlayerData[playerid][pHP] = floatstr(arrCoords[16]);
				gPlayerData[playerid][pHead] = strval(arrCoords[17]);
				gPlayerData[playerid][pTorso] = strval(arrCoords[18]);
				gPlayerData[playerid][pLegs] = strval(arrCoords[19]);
				gPlayerData[playerid][pDetoks] = strval(arrCoords[20]);
				gPlayerData[playerid][pWSlot0] = strval(arrCoords[23]);
				gPlayerData[playerid][pWSlot0Ammo] = strval(arrCoords[24]);
				gPlayerData[playerid][pWSlot1] = strval(arrCoords[25]);
				gPlayerData[playerid][pWSlot1Ammo] = strval(arrCoords[26]);
				gPlayerData[playerid][pWSlot2] = strval(arrCoords[27]);
				gPlayerData[playerid][pWSlot2Ammo] = strval(arrCoords[28]);
				gPlayerData[playerid][pWSlot3] = strval(arrCoords[29]);
				gPlayerData[playerid][pWSlot3Ammo] = strval(arrCoords[30]);
				gPlayerData[playerid][pWSlot4] = strval(arrCoords[31]);
				gPlayerData[playerid][pWSlot4Ammo] = strval(arrCoords[32]);
				gPlayerData[playerid][pWSlot5] = strval(arrCoords[33]);
				gPlayerData[playerid][pWSlot5Ammo] = strval(arrCoords[34]);
				gPlayerData[playerid][pWSlot6] = strval(arrCoords[35]);
				gPlayerData[playerid][pWSlot6Ammo] = strval(arrCoords[36]);
				gPlayerData[playerid][pRPCount] = strval(arrCoords[37]);
				gPlayerData[playerid][pDeathCount] = strval(arrCoords[38]);
				gPlayerData[playerid][pScore] = strval(arrCoords[39]);
				gPlayerData[playerid][pMechanicCoolDown] = strval(arrCoords[40]);
				gPlayerData[playerid][pFirstCarTest] = strval(arrCoords[41]);
				gPlayerData[playerid][pMaxWeight] = strval(arrCoords[42]);
				gPlayerData[playerid][pHunger] = strval(arrCoords[43]);
				gPlayerData[playerid][JemmyUses] = strval(arrCoords[44]);
				gPlayerData[playerid][pSubMealEaten] = strval(arrCoords[45]);
				
				mysql_free_result(db_con2);
			}
			format( string, sizeof(string), "SELECT * FROM `samp_users_items` WHERE `PlayerName` = '%s' LIMIT 1", gPlayerData[playerid][pName] );
			mysql_query(string, PLAYER_DATA_LOAD_ITEMS_MYSQL, playerid, db_con2);
		}
		case PLAYER_DATA_LOAD_JOB_MYSQL:
		{
			// printf("[DEBUG:][PLAYER_LOAD_JOB_MYSQL] pid = %d, pname = %s", playerid, gPlayerData[playerid][pName]);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Czekaj, trwa ³adowanie danych [prace]...");
			if( !mysql_store_result(db_con2) )
			{
				printf("[ERROR:] Can't store result on PLAYER_DATA_LOAD_JOB_MYSQL");
				if( playerid != CUSTOM_MAX_PLAYERS )
					SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Wyst¹pi³ b³¹d przy ³adowaniu danych twojego konta. Jeœli problem bêdzie siê powtarza³ skontaktuj siê z administratorem" );
				return 1;
			}
			if(mysql_num_rows(db_con2) == 0)
			{
				mysql_free_result(db_con2);
				new sendername[64];
				GetPlayerName(playerid, sendername, sizeof(sendername));
				format(string, sizeof(string), "INSERT INTO `samp_users_jobs` (`PlayerName`) VALUES ('%s')", sendername);
				mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			}
			else
			{
				mysql_fetch_row(db_result, "|", db_con2);

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

				mysql_free_result(db_con2);
			}
			format( string, sizeof(string), "SELECT * FROM `samp_users_lic` WHERE `PlayerName` = '%s' LIMIT 1", gPlayerData[playerid][pName] );
			mysql_query(string, PLAYER_DATA_LOAD_LIC_MYSQL, playerid, db_con2);
			if( playerid < CUSTOM_MAX_PLAYERS )
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
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Czekaj, trwa ³adowanie danych [licencje]...");
			if( !mysql_store_result(db_con2) )
			{
				printf("[ERROR:] Can't store result on PLAYER_DATA_LOAD_LIC_MYSQL");
				if( playerid != CUSTOM_MAX_PLAYERS )
					SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Wyst¹pi³ b³¹d przy ³adowaniu danych twojego konta. Jeœli problem bêdzie siê powtarza³ skontaktuj siê z administratorem" );
				return 1;
			}
			if(mysql_num_rows(db_con2) == 0)
			{
				mysql_free_result(db_con2);
				new sendername[64];
				GetPlayerName(playerid, sendername, sizeof(sendername));
				format(string, sizeof(string), "INSERT INTO `samp_users_lic` (`PlayerName`) VALUES ('%s')", sendername);
				mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			}
			else
			{
				mysql_fetch_row(db_result, "|", db_con2);

				split2(db_result, arrCoords, '|');

				gPlayerData[playerid][pCarLic] = strval(arrCoords[0]);
				gPlayerData[playerid][pBoatLic] = strval(arrCoords[1]);
				gPlayerData[playerid][pFlyLic] = strval(arrCoords[2]);
				gPlayerData[playerid][pWepLic] = strval(arrCoords[3]);

				mysql_free_result(db_con2);
			}
			format( string, sizeof(string), "SELECT * FROM `samp_users_notes` WHERE `PlayerName` = '%s' LIMIT 1", gPlayerData[playerid][pName] );
			mysql_query(string, PLAYER_DATA_LOAD_NOTES_MYSQL, playerid, db_con2);
		}
		case PLAYER_DATA_LOAD_NOTES_MYSQL:
		{
			// printf("[DEBUG:][PLAYER_LOAD_NOTES_MYSQL] pid = %d, pname = %s", playerid, gPlayerData[playerid][pName]);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Czekaj, trwa ³adowanie danych [notatki]...");
			if( !mysql_store_result(db_con2) )
			{
				printf("[ERROR:] Can't store result on PLAYER_DATA_LOAD_NOTES_MYSQL");
				if( playerid != CUSTOM_MAX_PLAYERS )
					SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Wyst¹pi³ b³¹d przy ³adowaniu danych twojego konta. Jeœli problem bêdzie siê powtarza³ skontaktuj siê z administratorem" );
				return 1;
			}
			if(mysql_num_rows(db_con2) == 0)
			{
				mysql_free_result(db_con2);
				new sendername[64];
				GetPlayerName(playerid, sendername, sizeof(sendername));
				format(string, sizeof(string), "INSERT INTO `samp_users_notes` (`PlayerName`) VALUES ('%s')", sendername);
				mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			}
			else
			{
				mysql_fetch_row(db_result, "|", db_con2);

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

				mysql_free_result(db_con2);
			}
			format( string, sizeof(string), "SELECT * FROM `samp_users_vip` WHERE `PlayerName` = '%s' LIMIT 1", gPlayerData[playerid][pName] );
			mysql_query(string, PLAYER_DATA_LOAD_VIP_MYSQL, playerid, db_con2);
		}
		case PLAYER_DATA_LOAD_VIP_MYSQL:
		{
			// printf("[DEBUG:][PLAYER_LOAD_VIP_MYSQL] pid = %d, pname = %s", playerid, gPlayerData[playerid][pName]);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Czekaj, trwa ³adowanie danych [dane VIP'a]...");
			if( !mysql_store_result(db_con2) )
			{
				printf("[ERROR:] Can't store result on PLAYER_DATA_LOAD_VIP_MYSQL");
				if( playerid != CUSTOM_MAX_PLAYERS )
					SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Wyst¹pi³ b³¹d przy ³adowaniu danych twojego konta. Jeœli problem bêdzie siê powtarza³ skontaktuj siê z administratorem" );
				return 1;
			}
			new sendername[64];
			GetPlayerName(playerid, sendername, sizeof(sendername));
			if(mysql_num_rows(db_con2) == 0)
			{
				mysql_free_result(db_con2);
				format(string, sizeof(string), "INSERT INTO `samp_users_vip` (`PlayerName`) VALUES ('%s')", sendername);
				mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
				
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
			}
			else
			{
				mysql_fetch_row(db_result, "|", db_con2);

				split2(db_result, arrCoords, '|');

				mysql_free_result(db_con2);
				
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
				
				if( playerid < CUSTOM_MAX_PLAYERS )
				{
					format(string, sizeof(string), "SELECT `username` FROM `phpbb_users` WHERE `user_id` = '%d' LIMIT 1", gPlayerData[playerid][pAccountOwnerID]);
					mysql_query(string, PLAYER_DATA_LOAD_OOCNAME_MYSQL, playerid, db_con2);
				}
			}
			if( playerid < CUSTOM_MAX_PLAYERS )
			{
				new dataar[256];
				for( new id = 0; id <= BIZ_CPN_ID; id++ )
				{
					format(dataar, sizeof(dataar), "%d|%d", playerid, id);
					format(string, sizeof(string), "SELECT * FROM `samp_users_fueled` WHERE `PlayerName` = '%s' AND `BizID` = '%d'", PlayerNameTMP, id);
					mysql_query_array(string, PLAYER_LOAD_FUEL, dataar, db_con2);
				}
			}
			format( string, sizeof(string), "SELECT * FROM `samp_users_other2` WHERE `PlayerName` = '%s'", gPlayerData[playerid][pName] );
			mysql_query(string, PLAYER_DATA_LOAD_OTHER2_MYSQL, playerid, db_con2);
		}
		case PLAYER_DATA_LOAD_ITEMS_MYSQL:
		{
			// printf("[DEBUG:][PLAYER_LOAD_ITEMS_MYSQL] pid = %d, pname = %s", playerid, gPlayerData[playerid][pName]);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Czekaj, trwa ³adowanie danych [itemy 1-5]...");
			if( !mysql_store_result(db_con2) )
			{
				printf("[ERROR:] Can't store result on PLAYER_DATA_LOAD_ITEMS_MYSQL");
				if( playerid != CUSTOM_MAX_PLAYERS )
					SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Wyst¹pi³ b³¹d przy ³adowaniu danych twojego konta. Jeœli problem bêdzie siê powtarza³ skontaktuj siê z administratorem" );
				return 1;
			}
			if(mysql_num_rows(db_con2) == 0)
			{
				mysql_free_result(db_con2);
				new sendername[64];
				GetPlayerName(playerid, sendername, sizeof(sendername));
				format(string, sizeof(string), "INSERT INTO `samp_users_items` (`PlayerName`) VALUES ('%s')", sendername);
				mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			}
			else
			{
				new TmpData[256];
				mysql_fetch_row(db_result, "|", db_con2);

				mysql_fetch_field("Item1", TmpData, db_con2);
				gPlayerData[playerid][pItem1] = strval(TmpData);
				mysql_fetch_field("Item2", TmpData, db_con2);
				gPlayerData[playerid][pItem2] = strval(TmpData);
				mysql_fetch_field("Item3", TmpData, db_con2);
				gPlayerData[playerid][pItem3] = strval(TmpData);
				mysql_fetch_field("Item4", TmpData, db_con2);
				gPlayerData[playerid][pItem4] = strval(TmpData);
				mysql_fetch_field("Item5", TmpData, db_con2);
				gPlayerData[playerid][pItem5] = strval(TmpData);
				mysql_fetch_field("Item1type", TmpData, db_con2);
				gPlayerData[playerid][pItem1type] = strval(TmpData);
				mysql_fetch_field("Item2type", TmpData, db_con2);
				gPlayerData[playerid][pItem2type] = strval(TmpData);
				mysql_fetch_field("Item3type", TmpData, db_con2);
				gPlayerData[playerid][pItem3type] = strval(TmpData);
				mysql_fetch_field("Item4type", TmpData, db_con2);
				gPlayerData[playerid][pItem4type] = strval(TmpData);
				mysql_fetch_field("Item5type", TmpData, db_con2);
				gPlayerData[playerid][pItem5type] = strval(TmpData);
				mysql_fetch_field("Item1param", TmpData, db_con2);
				gPlayerData[playerid][pItem1param] = strval(TmpData);
				mysql_fetch_field("Item2param", TmpData, db_con2);
				gPlayerData[playerid][pItem2param] = strval(TmpData);
				mysql_fetch_field("Item3param", TmpData, db_con2);
				gPlayerData[playerid][pItem3param] = strval(TmpData);
				mysql_fetch_field("Item4param", TmpData, db_con2);
				gPlayerData[playerid][pItem4param] = strval(TmpData);
				mysql_fetch_field("Item5param", TmpData, db_con2);
				gPlayerData[playerid][pItem5param] = strval(TmpData);
				mysql_fetch_field("Item1param2", TmpData, db_con2);
				gPlayerData[playerid][pItem1param2] = strval(TmpData);
				mysql_fetch_field("Item2param2", TmpData, db_con2);
				gPlayerData[playerid][pItem2param2] = strval(TmpData);
				mysql_fetch_field("Item3param2", TmpData, db_con2);
				gPlayerData[playerid][pItem3param2] = strval(TmpData);
				mysql_fetch_field("Item4param2", TmpData, db_con2);
				gPlayerData[playerid][pItem4param2] = strval(TmpData);
				mysql_fetch_field("Item5param2", TmpData, db_con2);
				gPlayerData[playerid][pItem5param2] = strval(TmpData);
				mysql_fetch_field("Item1param3", TmpData, db_con2);
				gPlayerData[playerid][pItem1param3] = strval(TmpData);
				mysql_fetch_field("Item2param3", TmpData, db_con2);
				gPlayerData[playerid][pItem2param3] = strval(TmpData);
				mysql_fetch_field("Item3param3", TmpData, db_con2);
				gPlayerData[playerid][pItem3param3] = strval(TmpData);
				mysql_fetch_field("Item4param3", TmpData, db_con2);
				gPlayerData[playerid][pItem4param3] = strval(TmpData);
				mysql_fetch_field("Item5param3", TmpData, db_con2);
				gPlayerData[playerid][pItem5param3] = strval(TmpData);
				mysql_fetch_field("Item1param4", TmpData, db_con2);
				gPlayerData[playerid][pItem1param4] = strval(TmpData);
				mysql_fetch_field("Item2param4", TmpData, db_con2);
				gPlayerData[playerid][pItem2param4] = strval(TmpData);
				mysql_fetch_field("Item3param4", TmpData, db_con2);
				gPlayerData[playerid][pItem3param4] = strval(TmpData);
				mysql_fetch_field("Item4param4", TmpData, db_con2);
				gPlayerData[playerid][pItem4param4] = strval(TmpData);
				mysql_fetch_field("Item5param4", TmpData, db_con2);
				gPlayerData[playerid][pItem5param4] = strval(TmpData);
				mysql_fetch_field("Item1param5", gPlayerData[playerid][pItem1param5], db_con2);
				mysql_fetch_field("Item2param5", gPlayerData[playerid][pItem2param5], db_con2);
				mysql_fetch_field("Item3param5", gPlayerData[playerid][pItem3param5], db_con2);
				mysql_fetch_field("Item4param5", gPlayerData[playerid][pItem4param5], db_con2);
				mysql_fetch_field("Item5param5", gPlayerData[playerid][pItem5param5], db_con2);
				mysql_fetch_field("Item1param6", TmpData, db_con2);
				gPlayerData[playerid][pItem1param6] = strval(TmpData);
				mysql_fetch_field("Item2param6", TmpData, db_con2);
				gPlayerData[playerid][pItem2param6] = strval(TmpData);
				mysql_fetch_field("Item3param6", TmpData, db_con2);
				gPlayerData[playerid][pItem3param6] = strval(TmpData);
				mysql_fetch_field("Item4param6", TmpData, db_con2);
				gPlayerData[playerid][pItem4param6] = strval(TmpData);
				mysql_fetch_field("Item5param6", TmpData, db_con2);
				gPlayerData[playerid][pItem5param6] = strval(TmpData);
				
				mysql_free_result(db_con2);
			}
			format( string, sizeof(string), "SELECT * FROM `samp_users_items2` WHERE `PlayerName` = '%s' LIMIT 1", gPlayerData[playerid][pName] );
			mysql_query(string, PLAYER_DATA_LOAD_ITEMS2_MYSQL, playerid, db_con2);
		}
		case PLAYER_DATA_LOAD_ITEMS2_MYSQL:
		{
			// printf("[DEBUG:][PLAYER_LOAD_ITEMS2_MYSQL] pid = %d, pname = %s", playerid, gPlayerData[playerid][pName]);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Czekaj, trwa ³adowanie danych [itemy 6-10]...");
			if( !mysql_store_result(db_con2) )
			{
				printf("[ERROR:] Can't store result on PLAYER_DATA_LOAD_ITEMS2_MYSQL");
				if( playerid != CUSTOM_MAX_PLAYERS )
					SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Wyst¹pi³ b³¹d przy ³adowaniu danych twojego konta. Jeœli problem bêdzie siê powtarza³ skontaktuj siê z administratorem" );
				return 1;
			}
			if(mysql_num_rows(db_con2) == 0)
			{
				mysql_free_result(db_con2);				
				format(string, sizeof(string), "INSERT INTO `samp_users_items2` (`PlayerName`) VALUES ('%s')", gPlayerData[playerid][pName]);
				mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			}
			else
			{
				new TmpData[256];
				mysql_fetch_row(db_result, "|", db_con2);
				
				mysql_fetch_field("Item6", TmpData, db_con2);
				gPlayerData[playerid][pItem6] = strval(TmpData);
				mysql_fetch_field("Item7", TmpData, db_con2);
				gPlayerData[playerid][pItem7] = strval(TmpData);
				mysql_fetch_field("Item8", TmpData, db_con2);
				gPlayerData[playerid][pItem8] = strval(TmpData);
				mysql_fetch_field("Item9", TmpData, db_con2);
				gPlayerData[playerid][pItem9] = strval(TmpData);
				mysql_fetch_field("Item10", TmpData, db_con2);
				gPlayerData[playerid][pItem10] = strval(TmpData);
				mysql_fetch_field("Item6type", TmpData, db_con2);
				gPlayerData[playerid][pItem6type] = strval(TmpData);
				mysql_fetch_field("Item7type", TmpData, db_con2);
				gPlayerData[playerid][pItem7type] = strval(TmpData);
				mysql_fetch_field("Item8type", TmpData, db_con2);
				gPlayerData[playerid][pItem8type] = strval(TmpData);
				mysql_fetch_field("Item9type", TmpData, db_con2);
				gPlayerData[playerid][pItem9type] = strval(TmpData);
				mysql_fetch_field("Item10type", TmpData, db_con2);
				gPlayerData[playerid][pItem10type] = strval(TmpData);
				mysql_fetch_field("Item6param", TmpData, db_con2);
				gPlayerData[playerid][pItem6param] = strval(TmpData);
				mysql_fetch_field("Item7param", TmpData, db_con2);
				gPlayerData[playerid][pItem7param] = strval(TmpData);
				mysql_fetch_field("Item8param", TmpData, db_con2);
				gPlayerData[playerid][pItem8param] = strval(TmpData);
				mysql_fetch_field("Item9param", TmpData, db_con2);
				gPlayerData[playerid][pItem9param] = strval(TmpData);
				mysql_fetch_field("Item10param", TmpData, db_con2);
				gPlayerData[playerid][pItem10param] = strval(TmpData);
				mysql_fetch_field("Item6param2", TmpData, db_con2);
				gPlayerData[playerid][pItem6param2] = strval(TmpData);
				mysql_fetch_field("Item7param2", TmpData, db_con2);
				gPlayerData[playerid][pItem7param2] = strval(TmpData);
				mysql_fetch_field("Item8param2", TmpData, db_con2);
				gPlayerData[playerid][pItem8param2] = strval(TmpData);
				mysql_fetch_field("Item9param2", TmpData, db_con2);
				gPlayerData[playerid][pItem9param2] = strval(TmpData);
				mysql_fetch_field("Item10param2", TmpData, db_con2);
				gPlayerData[playerid][pItem10param2] = strval(TmpData);
				mysql_fetch_field("Item6param3", TmpData, db_con2);
				gPlayerData[playerid][pItem6param3] = strval(TmpData);
				mysql_fetch_field("Item7param3", TmpData, db_con2);
				gPlayerData[playerid][pItem7param3] = strval(TmpData);
				mysql_fetch_field("Item8param3", TmpData, db_con2);
				gPlayerData[playerid][pItem8param3] = strval(TmpData);
				mysql_fetch_field("Item9param3", TmpData, db_con2);
				gPlayerData[playerid][pItem9param3] = strval(TmpData);
				mysql_fetch_field("Item10param3", TmpData, db_con2);
				gPlayerData[playerid][pItem10param3] = strval(TmpData);
				mysql_fetch_field("Item6param4", TmpData, db_con2);
				gPlayerData[playerid][pItem6param4] = strval(TmpData);
				mysql_fetch_field("Item7param4", TmpData, db_con2);
				gPlayerData[playerid][pItem7param4] = strval(TmpData);
				mysql_fetch_field("Item8param4", TmpData, db_con2);
				gPlayerData[playerid][pItem8param4] = strval(TmpData);
				mysql_fetch_field("Item9param4", TmpData, db_con2);
				gPlayerData[playerid][pItem9param4] = strval(TmpData);
				mysql_fetch_field("Item10param4", TmpData, db_con2);
				gPlayerData[playerid][pItem10param4] = strval(TmpData);
				mysql_fetch_field("Item6param5", gPlayerData[playerid][pItem6param5], db_con2);
				mysql_fetch_field("Item7param5", gPlayerData[playerid][pItem6param5], db_con2);
				mysql_fetch_field("Item8param5", gPlayerData[playerid][pItem6param5], db_con2);
				mysql_fetch_field("Item9param5", gPlayerData[playerid][pItem6param5], db_con2);
				mysql_fetch_field("Item10param5", gPlayerData[playerid][pItem6param5], db_con2);
				mysql_fetch_field("Item6param6", TmpData, db_con2);
				gPlayerData[playerid][pItem6param6] = strval(TmpData);
				mysql_fetch_field("Item7param6", TmpData, db_con2);
				gPlayerData[playerid][pItem7param6] = strval(TmpData);
				mysql_fetch_field("Item8param6", TmpData, db_con2);
				gPlayerData[playerid][pItem8param6] = strval(TmpData);
				mysql_fetch_field("Item9param6", TmpData, db_con2);
				gPlayerData[playerid][pItem9param6] = strval(TmpData);
				mysql_fetch_field("Item10param6", TmpData, db_con2);
				gPlayerData[playerid][pItem10param6] = strval(TmpData);
				
				mysql_free_result(db_con2);
			}
			format( string, sizeof(string), "SELECT * FROM `samp_users_items3` WHERE `PlayerName` = '%s' LIMIT 1", gPlayerData[playerid][pName]) ;
			mysql_query(string, PLAYER_DATA_LOAD_ITEMS3_MYSQL, playerid, db_con2);
		}
		case PLAYER_DATA_LOAD_ITEMS3_MYSQL:
		{
			// printf("[DEBUG:][PLAYER_LOAD_ITEMS3_MYSQL] pid = %d, pname = %s", playerid, gPlayerData[playerid][pName]);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Czekaj, trwa ³adowanie danych [itemy 11-25]...");
			if( !mysql_store_result(db_con2) )
			{
				printf("[ERROR:] Can't store result on PLAYER_DATA_LOAD_ITEMS3_MYSQL");
				if( playerid != CUSTOM_MAX_PLAYERS )
					SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Wyst¹pi³ b³¹d przy ³adowaniu danych twojego konta. Jeœli problem bêdzie siê powtarza³ skontaktuj siê z administratorem" );
				mysql_free_result(db_con2);
				format( string, sizeof(string), "SELECT * FROM `samp_users_jobs` WHERE `PlayerName` = '%s' ", gPlayerData[playerid][pName] );
				mysql_query(string, PLAYER_DATA_LOAD_JOB_MYSQL, playerid, db_con2);
				return 1;
			}
			if(mysql_num_rows(db_con2) == 0)
			{
				mysql_free_result(db_con2);
				format(string, sizeof(string), "INSERT INTO `samp_users_items3` (`PlayerName`) VALUES('%s')", gPlayerData[playerid][pName]);
				mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			}
			else
			{
				new TmpData[256];
				mysql_fetch_row(db_result, "|", db_con2);
				
				mysql_fetch_field("Item11", TmpData, db_con2);
				gPlayerData[playerid][pItem11] = strval(TmpData);
				mysql_fetch_field("Item12", TmpData, db_con2);
				gPlayerData[playerid][pItem12] = strval(TmpData);
				mysql_fetch_field("Item13", TmpData, db_con2);
				gPlayerData[playerid][pItem13] = strval(TmpData);
				mysql_fetch_field("Item14", TmpData, db_con2);
				gPlayerData[playerid][pItem14] = strval(TmpData);
				mysql_fetch_field("Item15", TmpData, db_con2);
				gPlayerData[playerid][pItem15] = strval(TmpData);
				mysql_fetch_field("Item16", TmpData, db_con2);
				gPlayerData[playerid][pItem16] = strval(TmpData);
				mysql_fetch_field("Item17", TmpData, db_con2);
				gPlayerData[playerid][pItem17] = strval(TmpData);
				mysql_fetch_field("Item18", TmpData, db_con2);
				gPlayerData[playerid][pItem18] = strval(TmpData);
				mysql_fetch_field("Item19", TmpData, db_con2);
				gPlayerData[playerid][pItem19] = strval(TmpData);
				mysql_fetch_field("Item20", TmpData, db_con2);
				gPlayerData[playerid][pItem20] = strval(TmpData);
				mysql_fetch_field("Item21", TmpData, db_con2);
				gPlayerData[playerid][pItem21] = strval(TmpData);
				mysql_fetch_field("Item22", TmpData, db_con2);
				gPlayerData[playerid][pItem22] = strval(TmpData);
				mysql_fetch_field("Item23", TmpData, db_con2);
				gPlayerData[playerid][pItem23] = strval(TmpData);
				mysql_fetch_field("Item24", TmpData, db_con2);
				gPlayerData[playerid][pItem24] = strval(TmpData);
				mysql_fetch_field("Item25", TmpData, db_con2);
				gPlayerData[playerid][pItem25] = strval(TmpData);
				mysql_fetch_field("Item11type", TmpData, db_con2);
				gPlayerData[playerid][pItem11type] = strval(TmpData);
				mysql_fetch_field("Item12type", TmpData, db_con2);
				gPlayerData[playerid][pItem12type] = strval(TmpData);
				mysql_fetch_field("Item13type", TmpData, db_con2);
				gPlayerData[playerid][pItem13type] = strval(TmpData);
				mysql_fetch_field("Item14type", TmpData, db_con2);
				gPlayerData[playerid][pItem14type] = strval(TmpData);
				mysql_fetch_field("Item15type", TmpData, db_con2);
				gPlayerData[playerid][pItem15type] = strval(TmpData);
				mysql_fetch_field("Item16type", TmpData, db_con2);
				gPlayerData[playerid][pItem16type] = strval(TmpData);
				mysql_fetch_field("Item17type", TmpData, db_con2);
				gPlayerData[playerid][pItem17type] = strval(TmpData);
				mysql_fetch_field("Item18type", TmpData, db_con2);
				gPlayerData[playerid][pItem18type] = strval(TmpData);
				mysql_fetch_field("Item19type", TmpData, db_con2);
				gPlayerData[playerid][pItem19type] = strval(TmpData);
				mysql_fetch_field("Item20type", TmpData, db_con2);
				gPlayerData[playerid][pItem20type] = strval(TmpData);
				mysql_fetch_field("Item21type", TmpData, db_con2);
				gPlayerData[playerid][pItem21type] = strval(TmpData);
				mysql_fetch_field("Item22type", TmpData, db_con2);
				gPlayerData[playerid][pItem22type] = strval(TmpData);
				mysql_fetch_field("Item23type", TmpData, db_con2);
				gPlayerData[playerid][pItem23type] = strval(TmpData);
				mysql_fetch_field("Item24type", TmpData, db_con2);
				gPlayerData[playerid][pItem24type] = strval(TmpData);
				mysql_fetch_field("Item25type", TmpData, db_con2);
				gPlayerData[playerid][pItem25type] = strval(TmpData);
				mysql_fetch_field("Item11param", TmpData, db_con2);
				gPlayerData[playerid][pItem11param] = strval(TmpData);
				mysql_fetch_field("Item12param", TmpData, db_con2);
				gPlayerData[playerid][pItem12param] = strval(TmpData);
				mysql_fetch_field("Item13param", TmpData, db_con2);
				gPlayerData[playerid][pItem13param] = strval(TmpData);
				mysql_fetch_field("Item14param", TmpData, db_con2);
				gPlayerData[playerid][pItem14param] = strval(TmpData);
				mysql_fetch_field("Item15param", TmpData, db_con2);
				gPlayerData[playerid][pItem15param] = strval(TmpData);
				mysql_fetch_field("Item16param", TmpData, db_con2);
				gPlayerData[playerid][pItem16param] = strval(TmpData);
				mysql_fetch_field("Item17param", TmpData, db_con2);
				gPlayerData[playerid][pItem17param] = strval(TmpData);
				mysql_fetch_field("Item18param", TmpData, db_con2);
				gPlayerData[playerid][pItem18param] = strval(TmpData);
				mysql_fetch_field("Item19param", TmpData, db_con2);
				gPlayerData[playerid][pItem19param] = strval(TmpData);
				mysql_fetch_field("Item20param", TmpData, db_con2);
				gPlayerData[playerid][pItem20param] = strval(TmpData);
				mysql_fetch_field("Item21param", TmpData, db_con2);
				gPlayerData[playerid][pItem21param] = strval(TmpData);
				mysql_fetch_field("Item22param", TmpData, db_con2);
				gPlayerData[playerid][pItem22param] = strval(TmpData);
				mysql_fetch_field("Item23param", TmpData, db_con2);
				gPlayerData[playerid][pItem23param] = strval(TmpData);
				mysql_fetch_field("Item24param", TmpData, db_con2);
				gPlayerData[playerid][pItem24param] = strval(TmpData);
				mysql_fetch_field("Item25param", TmpData, db_con2);
				gPlayerData[playerid][pItem25param] = strval(TmpData);
				mysql_fetch_field("Item11param2", TmpData, db_con2);
				gPlayerData[playerid][pItem11param2] = strval(TmpData);
				mysql_fetch_field("Item12param2", TmpData, db_con2);
				gPlayerData[playerid][pItem12param2] = strval(TmpData);
				mysql_fetch_field("Item13param2", TmpData, db_con2);
				gPlayerData[playerid][pItem13param2] = strval(TmpData);
				mysql_fetch_field("Item14param2", TmpData, db_con2);
				gPlayerData[playerid][pItem14param2] = strval(TmpData);
				mysql_fetch_field("Item15param2", TmpData, db_con2);
				gPlayerData[playerid][pItem15param2] = strval(TmpData);
				mysql_fetch_field("Item16param2", TmpData, db_con2);
				gPlayerData[playerid][pItem16param2] = strval(TmpData);
				mysql_fetch_field("Item17param2", TmpData, db_con2);
				gPlayerData[playerid][pItem17param2] = strval(TmpData);
				mysql_fetch_field("Item18param2", TmpData, db_con2);
				gPlayerData[playerid][pItem18param2] = strval(TmpData);
				mysql_fetch_field("Item19param2", TmpData, db_con2);
				gPlayerData[playerid][pItem19param2] = strval(TmpData);
				mysql_fetch_field("Item20param2", TmpData, db_con2);
				gPlayerData[playerid][pItem20param2] = strval(TmpData);
				mysql_fetch_field("Item21param2", TmpData, db_con2);
				gPlayerData[playerid][pItem21param2] = strval(TmpData);
				mysql_fetch_field("Item22param2", TmpData, db_con2);
				gPlayerData[playerid][pItem22param2] = strval(TmpData);
				mysql_fetch_field("Item23param2", TmpData, db_con2);
				gPlayerData[playerid][pItem23param2] = strval(TmpData);
				mysql_fetch_field("Item24param2", TmpData, db_con2);
				gPlayerData[playerid][pItem24param2] = strval(TmpData);
				mysql_fetch_field("Item25param2", TmpData, db_con2);
				gPlayerData[playerid][pItem25param2] = strval(TmpData);
				mysql_fetch_field("Item11param3", TmpData, db_con2);
				gPlayerData[playerid][pItem11param3] = strval(TmpData);
				mysql_fetch_field("Item12param3", TmpData, db_con2);
				gPlayerData[playerid][pItem12param3] = strval(TmpData);
				mysql_fetch_field("Item13param3", TmpData, db_con2);
				gPlayerData[playerid][pItem13param3] = strval(TmpData);
				mysql_fetch_field("Item14param3", TmpData, db_con2);
				gPlayerData[playerid][pItem14param3] = strval(TmpData);
				mysql_fetch_field("Item15param3", TmpData, db_con2);
				gPlayerData[playerid][pItem15param3] = strval(TmpData);
				mysql_fetch_field("Item16param3", TmpData, db_con2);
				gPlayerData[playerid][pItem16param3] = strval(TmpData);
				mysql_fetch_field("Item17param3", TmpData, db_con2);
				gPlayerData[playerid][pItem17param3] = strval(TmpData);
				mysql_fetch_field("Item18param3", TmpData, db_con2);
				gPlayerData[playerid][pItem18param3] = strval(TmpData);
				mysql_fetch_field("Item19param3", TmpData, db_con2);
				gPlayerData[playerid][pItem19param3] = strval(TmpData);
				mysql_fetch_field("Item20param3", TmpData, db_con2);
				gPlayerData[playerid][pItem20param3] = strval(TmpData);
				mysql_fetch_field("Item21param3", TmpData, db_con2);
				gPlayerData[playerid][pItem21param3] = strval(TmpData);
				mysql_fetch_field("Item22param3", TmpData, db_con2);
				gPlayerData[playerid][pItem22param3] = strval(TmpData);
				mysql_fetch_field("Item23param3", TmpData, db_con2);
				gPlayerData[playerid][pItem23param3] = strval(TmpData);
				mysql_fetch_field("Item24param3", TmpData, db_con2);
				gPlayerData[playerid][pItem24param3] = strval(TmpData);
				mysql_fetch_field("Item25param3", TmpData, db_con2);
				gPlayerData[playerid][pItem25param3] = strval(TmpData);
				mysql_fetch_field("Item11param4", TmpData, db_con2);
				gPlayerData[playerid][pItem11param4] = strval(TmpData);
				mysql_fetch_field("Item12param4", TmpData, db_con2);
				gPlayerData[playerid][pItem12param4] = strval(TmpData);
				mysql_fetch_field("Item13param4", TmpData, db_con2);
				gPlayerData[playerid][pItem13param4] = strval(TmpData);
				mysql_fetch_field("Item14param4", TmpData, db_con2);
				gPlayerData[playerid][pItem14param4] = strval(TmpData);
				mysql_fetch_field("Item15param4", TmpData, db_con2);
				gPlayerData[playerid][pItem15param4] = strval(TmpData);
				mysql_fetch_field("Item16param4", TmpData, db_con2);
				gPlayerData[playerid][pItem16param4] = strval(TmpData);
				mysql_fetch_field("Item17param4", TmpData, db_con2);
				gPlayerData[playerid][pItem17param4] = strval(TmpData);
				mysql_fetch_field("Item18param4", TmpData, db_con2);
				gPlayerData[playerid][pItem18param4] = strval(TmpData);
				mysql_fetch_field("Item19param4", TmpData, db_con2);
				gPlayerData[playerid][pItem19param4] = strval(TmpData);
				mysql_fetch_field("Item20param4", TmpData, db_con2);
				gPlayerData[playerid][pItem20param4] = strval(TmpData);
				mysql_fetch_field("Item21param4", TmpData, db_con2);
				gPlayerData[playerid][pItem21param4] = strval(TmpData);
				mysql_fetch_field("Item22param4", TmpData, db_con2);
				gPlayerData[playerid][pItem22param4] = strval(TmpData);
				mysql_fetch_field("Item23param4", TmpData, db_con2);
				gPlayerData[playerid][pItem23param4] = strval(TmpData);
				mysql_fetch_field("Item24param4", TmpData, db_con2);
				gPlayerData[playerid][pItem24param4] = strval(TmpData);
				mysql_fetch_field("Item25param4", TmpData, db_con2);
				gPlayerData[playerid][pItem25param4] = strval(TmpData);
				mysql_fetch_field("Item11param5", gPlayerData[playerid][pItem11param5], db_con2);
				mysql_fetch_field("Item12param5", gPlayerData[playerid][pItem12param5], db_con2);
				mysql_fetch_field("Item13param5", gPlayerData[playerid][pItem13param5], db_con2);
				mysql_fetch_field("Item14param5", gPlayerData[playerid][pItem14param5], db_con2);
				mysql_fetch_field("Item15param5", gPlayerData[playerid][pItem15param5], db_con2);
				mysql_fetch_field("Item16param5", gPlayerData[playerid][pItem16param5], db_con2);
				mysql_fetch_field("Item17param5", gPlayerData[playerid][pItem17param5], db_con2);
				mysql_fetch_field("Item18param5", gPlayerData[playerid][pItem18param5], db_con2);
				mysql_fetch_field("Item19param5", gPlayerData[playerid][pItem19param5], db_con2);
				mysql_fetch_field("Item20param5", gPlayerData[playerid][pItem20param5], db_con2);
				mysql_fetch_field("Item21param5", gPlayerData[playerid][pItem21param5], db_con2);
				mysql_fetch_field("Item22param5", gPlayerData[playerid][pItem22param5], db_con2);
				mysql_fetch_field("Item23param5", gPlayerData[playerid][pItem23param5], db_con2);
				mysql_fetch_field("Item24param5", gPlayerData[playerid][pItem24param5], db_con2);
				mysql_fetch_field("Item25param5", gPlayerData[playerid][pItem25param5], db_con2);
				mysql_fetch_field("Item11param6", TmpData, db_con2);
				gPlayerData[playerid][pItem11param6] = strval(TmpData);
				mysql_fetch_field("Item12param6", TmpData, db_con2);
				gPlayerData[playerid][pItem12param6] = strval(TmpData);
				mysql_fetch_field("Item13param6", TmpData, db_con2);
				gPlayerData[playerid][pItem13param6] = strval(TmpData);
				mysql_fetch_field("Item14param6", TmpData, db_con2);
				gPlayerData[playerid][pItem14param6] = strval(TmpData);
				mysql_fetch_field("Item15param6", TmpData, db_con2);
				gPlayerData[playerid][pItem15param6] = strval(TmpData);
				mysql_fetch_field("Item16param6", TmpData, db_con2);
				gPlayerData[playerid][pItem16param6] = strval(TmpData);
				mysql_fetch_field("Item17param6", TmpData, db_con2);
				gPlayerData[playerid][pItem17param6] = strval(TmpData);
				mysql_fetch_field("Item18param6", TmpData, db_con2);
				gPlayerData[playerid][pItem18param6] = strval(TmpData);
				mysql_fetch_field("Item19param6", TmpData, db_con2);
				gPlayerData[playerid][pItem19param6] = strval(TmpData);
				mysql_fetch_field("Item20param6", TmpData, db_con2);
				gPlayerData[playerid][pItem20param6] = strval(TmpData);
				mysql_fetch_field("Item21param6", TmpData, db_con2);
				gPlayerData[playerid][pItem21param6] = strval(TmpData);
				mysql_fetch_field("Item22param6", TmpData, db_con2);
				gPlayerData[playerid][pItem22param6] = strval(TmpData);
				mysql_fetch_field("Item23param6", TmpData, db_con2);
				gPlayerData[playerid][pItem23param6] = strval(TmpData);
				mysql_fetch_field("Item24param6", TmpData, db_con2);
				gPlayerData[playerid][pItem24param6] = strval(TmpData);
				mysql_fetch_field("Item25param6", TmpData, db_con2);
				gPlayerData[playerid][pItem25param6] = strval(TmpData);
				
				mysql_free_result(db_con2);
			}
			format( string, sizeof(string), "SELECT * FROM `samp_users_jobs` WHERE `PlayerName` = '%s' LIMIT 1", gPlayerData[playerid][pName] );
			mysql_query(string, PLAYER_DATA_LOAD_JOB_MYSQL, playerid, db_con2);
		}
		case PLAYER_DATA_LOAD_OOCNAME_MYSQL:
		{
			if( !mysql_store_result(db_con2) )
			{
				printf("[ERROR:] Can't store result on PLAYER_DATA_LOAD_OOCNAME_MYSQL");
				if( playerid != CUSTOM_MAX_PLAYERS )
					SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Wyst¹pi³ b³¹d przy ³adowaniu danych twojego konta. Jeœli problem bêdzie siê powtarza³ skontaktuj siê z administratorem" );
				return 1;
			}
			mysql_fetch_row(db_result, "|", db_con2);

			split2(db_result, arrCoords, '|');

			strdel(gPlayerData[playerid][pOOCName], 0, 64);
			strins(gPlayerData[playerid][pOOCName], arrCoords[0], 0, 64);

			format(string, sizeof(string), "{DF013A}[WParty SERVER:]{FFFFFF}[ID: %d][IC: %s] %s do³¹czy³ do gry !", playerid, GetPlayerNameEx(playerid), gPlayerData[playerid][pOOCName]);
		
			foreach(Player, i)
			{
				if( gPlayerData[i][pOOCStatus] && gPlayerLogged[i] && i != playerid)
					SendClientMessage(i, 0xFFFFFFAA, string);
			}
			if( gFirstTime[playerid] )
			{
				format(string, sizeof(string), "{DF013A}[WParty SERVER:]{FFFFFF} Zalogowa³eœ siê na Twojej nowej postaci !", gPlayerData[playerid][pOOCName]);
				SendClientMessage( playerid, COLOR_GREEN, string );
				SendClientMessage( playerid, COLOR_GREEN, "{DF013A}[WParty SERVER:]{FFFFFF} Aby dowiedzieæ siê wiêcej na temat gry u¿yj komendy /pomoc" );
				SendClientMessage( playerid, COLOR_GREEN, "{DF013A}[WParty SERVER:]{FFFFFF} W razie jakichkolwiek pytañ pisz na /n. ¯yczymy mi³ej gry ! - Zespó³ WParty" );
			}
			else
			{
				format(string, sizeof(string), "{DF013A}[WParty SERVER:]{FFFFFF} Witaj ponownie %s", gPlayerData[playerid][pOOCName]);
				SendClientMessage( playerid, COLOR_GREEN, string);
			}	
			
			mysql_free_result(db_con2);
		}
		case PLAYER_DATA_LOAD_OTHER2_MYSQL:
		{
			// printf("[DEBUG:][PLAYER_LOAD_OTHER2_MYSQL] pid = %d, pname = %s", playerid, gPlayerData[playerid][pName]);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Czekaj, trwa ³adowanie danych [finalizacja]...");
			if( !mysql_store_result(db_con2) )
			{
				printf("[ERROR:] Can't store result on PLAYER_DATA_LOAD_OTHER2_MYSQL");
				if( playerid != CUSTOM_MAX_PLAYERS )
					SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Wyst¹pi³ b³¹d przy ³adowaniu danych twojego konta. Jeœli problem bêdzie siê powtarza³ skontaktuj siê z administratorem" );
				return 1;
			}
			if(mysql_num_rows(db_con2) == 0)
			{
				mysql_free_result(db_con2);
				
				format(string, sizeof(string), "INSERT INTO `samp_users_other2` (`PlayerName`) VALUES ('%s')", gPlayerData[playerid][pName]);
				mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
				
				format(string, sizeof(string), "SELECT * FROM `samp_users_other2` WHERE `PlayerName` = '%s' LIMIT 1", gPlayerData[playerid][pName]);
				mysql_query(string, PLAYER_DATA_LOAD_OTHER2_MYSQL, playerid, db_con2);
			}
			else
			{
				mysql_fetch_row(db_result, "|", db_con2);

				split2(db_result, arrCoords, '|');
				gPlayerData[playerid][pParts] = strval(arrCoords[2]);
				gPlayerData[playerid][pJobTimeChange] = strval(arrCoords[3]);
				gPlayerData[playerid][pSeatBelt] = strval(arrCoords[4]);
				gPlayerData[playerid][pSkillLevPis] = strval(arrCoords[5]);
				gPlayerData[playerid][pSkillLevSil] = strval(arrCoords[6]);
				gPlayerData[playerid][pSkillLevDes] = strval(arrCoords[7]);
				gPlayerData[playerid][pSkillLevSho] = strval(arrCoords[8]);
				gPlayerData[playerid][pSkillLevSha] = strval(arrCoords[9]);
				gPlayerData[playerid][pSkillLevSpa] = strval(arrCoords[10]);
				gPlayerData[playerid][pSkillLevMic] = strval(arrCoords[11]);
				gPlayerData[playerid][pSkillLevMp5] = strval(arrCoords[12]);
				gPlayerData[playerid][pSkillLevAk] = strval(arrCoords[13]);
				gPlayerData[playerid][pSkillLevM4] = strval(arrCoords[14]);
				gPlayerData[playerid][pSkillLevSni] = strval(arrCoords[15]);
				gPlayerData[playerid][pSkillPointsPis] = strval(arrCoords[16]);
				gPlayerData[playerid][pSkillPointsSil] = strval(arrCoords[17]);
				gPlayerData[playerid][pSkillPointsDes] = strval(arrCoords[18]);
				gPlayerData[playerid][pSkillPointsSho] = strval(arrCoords[19]);
				gPlayerData[playerid][pSkillPointsSha] = strval(arrCoords[20]);
				gPlayerData[playerid][pSkillPointsSpa] = strval(arrCoords[21]);
				gPlayerData[playerid][pSkillPointsMic] = strval(arrCoords[22]);
				gPlayerData[playerid][pSkillPointsMp5] = strval(arrCoords[23]);
				gPlayerData[playerid][pSkillPointsAk] = strval(arrCoords[24]);
				gPlayerData[playerid][pSkillPointsM4] = strval(arrCoords[25]);
				gPlayerData[playerid][pSkillPointsSni] = strval(arrCoords[26]);
				gPlayerData[playerid][pPozwolenie] = strval(arrCoords[27]);
				gPlayerData[playerid][pAng] = strval(arrCoords[28]);
				gPlayerData[playerid][pWf] = strval(arrCoords[29]);
				gPlayerData[playerid][pMat] = strval(arrCoords[30]);
				gPlayerData[playerid][pPol] = strval(arrCoords[31]);
				gPlayerData[playerid][pHis] = strval(arrCoords[32]);
				gPlayerData[playerid][pFiz] = strval(arrCoords[33]);
				gPlayerData[playerid][pBio] = strval(arrCoords[34]);
				gPlayerData[playerid][pDoktor] = strval(arrCoords[35]);
				gPlayerData[playerid][pMagister] = strval(arrCoords[36]);
				gPlayerData[playerid][pInz] = strval(arrCoords[37]);
				gPlayerData[playerid][pDowod] = strval(arrCoords[38]);
				gPlayerData[playerid][pPktAng] = strval(arrCoords[39]);
				gPlayerData[playerid][pPktWf] = strval(arrCoords[40]);
				gPlayerData[playerid][pPktMat] = strval(arrCoords[41]);
				gPlayerData[playerid][pPktPol] = strval(arrCoords[42]);
				gPlayerData[playerid][pPktHis] = strval(arrCoords[43]);
				gPlayerData[playerid][pPktFiz] = strval(arrCoords[44]);
				gPlayerData[playerid][pPktBio] = strval(arrCoords[45]);
				gPlayerData[playerid][pDuty] = strval(arrCoords[46]);
				gPlayerData[playerid][pPartType] = strval(arrCoords[47]);
				gPlayerData[playerid][pPartItem] = strval(arrCoords[48]);
				gPlayerData[playerid][pMountsLeft] = strval(arrCoords[49]);
				gPlayerData[playerid][pWFOrderedCount] = strval(arrCoords[50]);
				gPlayerData[playerid][pSpeedGunOn] = strval(arrCoords[51]);
				gPlayerData[playerid][pPWStatus] = strval(arrCoords[52]);
				gPlayerData[playerid][pOOCStatus] = strval(arrCoords[53]);
				gPlayerData[playerid][pIsDeptor] = strval(arrCoords[54]);
				gPlayerData[playerid][pLastLogged] = strval(arrCoords[55]);
				// gPlayerData[playerid][pPenaltyRP] = strval(arrCoords[55]);

				mysql_free_result(db_con2);
				
				if( playerid < CUSTOM_MAX_PLAYERS )
				{				
					if(gPlayerData[playerid][pFaction] < sizeof(DynamicFactions))
					{
						if(DynamicFactions[gPlayerData[playerid][pFaction]][fType] == 3)
						{
							for(new idx = 0; idx < sizeof(DynamicZones); idx++)
							{
								GangZoneShowForPlayer(playerid, gangZoneID[idx], HexToInt(DynamicFactions[DynamicZones[idx][zFaction]][fColor]));
								if( gGangWar[Enabled] )
									GangZoneFlashForPlayer(playerid, gGangWar[AreaID], DynamicFactions[ DynamicZones[ gGangWar[AreaID] ][zFaction] ][fColor] );
							}
						}
					}
					
					// Show gang war status
					TextDrawShowForPlayer( playerid, GangWar[playerid] );

					// Set player nick color depends on nick
					if( (gPlayerData[playerid][pVipAFK] != 0 || gPlayerData[playerid][pVipAFKT] != 0) && (gPlayerData[playerid][pVipExp] != 0 || gPlayerData[playerid][pVipExpT] != 0) )
						SetPlayerColor(playerid, COLOR_PURPLE);
					else
						SetPlayerColor(playerid,COLOR_CIVILIAN);

					// Kick banned player
					if(gPlayerData[playerid][pBanned])
						KickPlayer(playerid,"System","Konto zbanowane");
						
					// Kick dead player
					if(gPlayerData[playerid][pCharacterDeath] == 1)
						KickPlayer(playerid,"System","Postaæ martwa");
						
					// Fill first logged player with default data
					if( gPlayerData[playerid][pRegistered] == 0 )
					{
						// gPlayerData[playerid][pLevel] = 1;
						gPlayerData[playerid][pCrashX] = gStartSpawnX;
						gPlayerData[playerid][pCrashY] = gStartSpawnY;
						gPlayerData[playerid][pCrashZ] = gStartSpawnZ;
						gPlayerData[playerid][pCash] = gStartMoney;
						gPlayerData[playerid][pBank] = gStartBank;
						gPlayerData[playerid][pSkin] = gStartSkin;
						gPlayerData[playerid][pRegistered] = 1;
						
						gSavePlayerReady[playerid] = 1; // umo¿liwia zapis w wp_saveplayerdata.inc
						
						SavePlayerData( playerid, "Crash" );
						SavePlayerData( playerid, "Bank" );
						SavePlayerData( playerid, "Skin" );
						SavePlayerData( playerid, "Registered" );
						SetPlayerCash(playerid,gPlayerData[playerid][pCash]);
						gFirstTime[playerid] = 1;
						// ZAPIS NA KONCU !
					}
					
					// Show player map icons if have map
					if( PHaveItem( playerid, 1, 105 ) )
						ShowPlayerMapIcons( playerid, 1 );
					
					// Set player gui cash
					SetPlayerCash(playerid,gPlayerData[playerid][pCash]);
					
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
					
					// Set Hunger Bar
					if( gPlayerData[playerid][pVipAFK] == 1 || gPlayerData[playerid][pVipAFKT] > 0 )
						gPlayerData[playerid][pHungerProgressBarID] = CreateProgressBar( 535.0, 110.5, 70.0, 5.5, COLOR_LIGHTRED, MAX_HUNGER_VIP );
					else
						gPlayerData[playerid][pHungerProgressBarID] = CreateProgressBar( 535.0, 110.5, 55.5, 5.5, COLOR_LIGHTRED, MAX_HUNGER );
					SetProgressBarValue( gPlayerData[playerid][pHungerProgressBarID], gPlayerData[playerid][pHunger] );
					UpdateProgressBar( gPlayerData[playerid][pHungerProgressBarID], playerid );
					
					printf("%s has logged in", gPlayerData[playerid][pName]);
					ClearScreen(playerid);
					SendClientMessage(playerid, COLOR_YELLOW2, "[INFO:] Zalogowany.");

					TogglePlayerControllable(playerid, 1);
					
					SetSpawnInfo(playerid, 0, gPlayerData[playerid][pSkin],CivilianSpawn[X],CivilianSpawn[Y],CivilianSpawn[Z],0,0,0,0,0,0,0);
					PosHackCheckTime[playerid] = 5;
					SetPlayerHealth( playerid, gPlayerData[playerid][pHP] );
					SpawnPlayer(playerid);					
					SpawnedInWorld(playerid); // UAC
					Alive[playerid] = 1;
					CheckDelay[playerid] = 2;
					
					// Show character description
					Attach3DTextLabelToPlayer( gPlayerData[playerid][pCharDescriptionID], playerid, 0.0, 0.0, 0.35 );
					Update3DTextLabelText( gPlayerData[playerid][pCharDescriptionID], gPlayerData[playerid][pCharDescriptionColor], gPlayerData[playerid][pCharDescription] );
					
					// Set player dynamic weather
					if( IsPlayerInDynamicArea(playerid, gArea_MW_SanFierro) )
						SetPlayerRealWeatherEx(playerid, gMW_sanfrancisco);
					else if( IsPlayerInDynamicArea(playerid, gArea_MW_LasVenturas) )
						SetPlayerRealWeatherEx(playerid, gMW_lasvegas);
					else if( IsPlayerInDynamicArea(playerid, gArea_MW_LosSantos) )
						SetPlayerRealWeatherEx(playerid, gMW_losangeles);
					else
						SetPlayerRealWeatherEx(playerid, gMW_warszawa);

					// Set player status box
					new location[MAX_ZONE_NAME];
					GetPlayer2DZone(playerid, location, MAX_ZONE_NAME);
					
					// if(gPlayerData[playerid][pFaction] != 255)
						// format(string, sizeof(string), "~y~Poziom postaci: ~w~%d ~y~Doswiadczenie: ~w~%d/%d ~y~Frakcja: ~w~%s ~y~Lokacja: ~w~%s", gPlayerData[playerid][pLevel], gPlayerData[playerid][pExp], gPlayerData[playerid][pLevel]+1*levelexp, DynamicFactions[gPlayerData[playerid][pFaction]][Name], location);
					// else
						// format(string, sizeof(string), "~y~Poziom postaci: ~w~%d ~y~Doswiadczenie: ~w~%d/%d ~y~Frakcja: ~w~Brak ~y~Lokacja: ~w~%s", gPlayerData[playerid][pLevel], gPlayerData[playerid][pExp], gPlayerData[playerid][pLevel]+1*levelexp, location);
					format(string, sizeof(string), " ");
					TextDrawSetString(PlayerStatus[playerid], string);
					TextDrawShowForPlayer(playerid,PlayerStatus[playerid]);
					
					// Set login status and enable save
					gPlayerLogged[playerid] = 1;				
					gSavePlayerReady[playerid] = 1;
					
					gPlayerData[playerid][pLastLogged] = 0;
					SavePlayerData(playerid, "LastLogged");
					
					return 1;
				}
				else
				{
					if( (gPlayerData[playerid][pPlayingHours] <= 50 && gPlayerData[playerid][pLastLogged] >= 10) || 
						(gPlayerData[playerid][pPlayingHours] > 50 && gPlayerData[playerid][pLastLogged] >= 20) ||
						strlen(gPlayerData[playerid][pName]) <= 3 || gPlayerData[playerid][pAdmin] > 0 )
					{
						gPlayerData[playerid][pLastLogged]++;
						SavePlayerData(playerid, "LastLogged");
						printf("[PAYDAY:] Player name = %s - payday is off (not logged for %d day(s)) or is administrator", gPlayerData[playerid][pName], gPlayerData[playerid][pLastLogged] );
						/* 
						* Select next player in DB
						*/
						gPayDayLoop++;
						new stringtmp1[2048];
						printf("[PAYDAY:] gPayDayLoop = %d, gPayDayCount = %d", gPayDayLoop, gPayDayCount );
						if( gPayDayLoop <= gPayDayCount )
						{
							format(stringtmp1, sizeof(stringtmp1), "SELECT `Key`,`ID`,`PlayerName`,`Level`,`AdminLevel`,`DonateRank`,`Registered`,`Sex`,`Age`,`Experience`,`Money`,`Bank`,`Skin`,`PlayingHours`,`AllowedPayday`,`PayCheck`,`Faction`,`Rank`,`Banned`");
							strcat( stringtmp1, ",`Warnings`,`Jailed`,`JailTime`,`CrashX`,`CrashY`,`CrashZ`,`CrashInt`,`CrashW`,`Crashed`,`Wins`,`Loses`,`InvWeapon`,`InvAmmo`,`Tutorial`,`Moderator`,`WantedLvl`,`FirstCar`,`FirstReanimation`,`FirstPhone`,`FirstLeader`" );
							strcat( stringtmp1, ",`CrashAngle`,`HourAssist`,`JoinedFaction`,`HoursOnDuty`,`HoursOnDutyHelper`,`WarnCooldown`,`SpeedLimiter`,`AdminDuty`,`CharDescription`,`CharDescriptionColor`, `FirstJob`, `FirstID`, `FirstBuy`, `FirstHouse`, `FirstDescription`" );
							strcat( stringtmp1, ", `FirstAction`, `FirstBankUse`, `FirstStats`, `FirstJail`, `FirstStudy`" );
							format( stringtmp1, sizeof(stringtmp1), "%s FROM `samp_users` WHERE `Banned` = '0' LIMIT %d , 1", stringtmp1, gPayDayLoop);
							if(mysql_query(stringtmp1, PLAYER_DATA_LOAD_NAME_MYSQL, CUSTOM_MAX_PLAYERS, db_con2) != 0)
							{
								format(string, sizeof(string), "MYSQL QUERY failed in PayDay");
								PayDayLog(string);
							}	
						}
						return 1;
					}
					
					/*
					* Give player faction payment and other payment
					*/
					if(gPlayerData[CUSTOM_MAX_PLAYERS][pFaction] != 255 && gPlayerData[playerid][pLastLogged] == 0)
					{
						for(new n = 0; n < sizeof(DynamicFactions); n++)
						{
							if( PayRank[n][FactionID] == gPlayerData[CUSTOM_MAX_PLAYERS][pFaction] )
							{
								switch( gPlayerData[playerid][pRank] )
								{
									case 1: { gPlayerData[playerid][pBank] += PayRank[n][Rank1]; DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank1]; }
									case 2: { gPlayerData[playerid][pBank] += PayRank[n][Rank2]; DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank2]; }
									case 3: { gPlayerData[playerid][pBank] += PayRank[n][Rank3]; DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank3]; }
									case 4: { gPlayerData[playerid][pBank] += PayRank[n][Rank4]; DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank4]; }
									case 5: { gPlayerData[playerid][pBank] += PayRank[n][Rank5]; DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank5]; }
									case 6: { gPlayerData[playerid][pBank] += PayRank[n][Rank6]; DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank6]; }
									case 7: { gPlayerData[playerid][pBank] += PayRank[n][Rank7]; DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank7]; }
									case 8: { gPlayerData[playerid][pBank] += PayRank[n][Rank8]; DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank8]; }
									case 9: { gPlayerData[playerid][pBank] += PayRank[n][Rank9]; DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank9]; }
									case 10: { gPlayerData[playerid][pBank] += PayRank[n][Rank10]; DynamicFactions[PayRank[n][FactionID]][fBank] -= PayRank[n][Rank10]; }
								}
								SaveFData( gPlayerData[playerid][pFaction], "Bank" );
								break;
							}
						}
					}
					if( gPlayerData[playerid][pJob] == 0 && gPlayerData[playerid][pFaction] == 255 )
					{
						printf("[PAYDAY:] Player name = %s, Bank = %d + %d", gPlayerData[playerid][pName], gPlayerData[playerid][pBank], Zasilek); 
						gPlayerData[playerid][pBank] += Zasilek;
						DynamicFactions[FACTIONID_GOVERNMENT][fBank] -= Zasilek;						
						SaveFData( FACTIONID_GOVERNMENT, "Bank" );
					}		
					
					/*
					* Pay taxes, costs, tickets, etc.
					*/			
					printf("[PAYDAY:] PlayerName = %s, Bank = %d - %d, SOURCE = Radio tax", gPlayerData[playerid][pName], gPlayerData[playerid][pBank], DynamicTaxes[RadioTax]);					
					gPlayerData[playerid][pBank] -= DynamicTaxes[RadioTax]; 						
					DynamicFactions[FACTIONID_GOVERNMENT][fBank] += DynamicTaxes[RadioTax];
					if( ( gPlayerData[playerid][pCash] + gPlayerData[playerid][pBank] ) >= DynamicTaxes[TheRich] )
					{
						printf("[PAYDAY:] PlayerName = %s, Bank = %d - %d, SOURCE = taxes (the rich)", gPlayerData[playerid][pName], gPlayerData[playerid][pBank], floatround( DynamicTaxes[RichTax] * (gPlayerData[playerid][pBank]+gPlayerData[playerid][pCash]), floatround_round)); 
						gPlayerData[playerid][pBank] -= floatround( DynamicTaxes[RichTax] * (gPlayerData[playerid][pBank]+gPlayerData[playerid][pCash]), floatround_round);						
						DynamicFactions[FACTIONID_GOVERNMENT][fBank] += DynamicTaxes[TheRich];
					}
					if( gPlayerData[playerid][pCost] > 0 )
					{
						printf("[PAYDAY:] PlayerName = %s, Bank = %d - %d, SOURCE = costs", gPlayerData[playerid][pName], gPlayerData[playerid][pBank], gPlayerData[playerid][pCost]);
						gPlayerData[playerid][pBank] -= gPlayerData[playerid][pCost];						 
						gPlayerData[playerid][pCost] = 0;
						SavePlayerData( playerid, "Cost" );
					}
					if( gPlayerData[playerid][pTicket] > 0 )
					{
						printf("[PAYDAY:] PlayerName = %s, Bank = %d - %d, SOURCE = ticket", gPlayerData[playerid][pName], gPlayerData[playerid][pBank], gPlayerData[playerid][pTicket]); 
						gPlayerData[playerid][pBank] -= gPlayerData[playerid][pTicket];						
						DynamicFactions[FACTIONID_POLICE][fBank] += gPlayerData[playerid][pTicket];
						SaveFData( FACTIONID_POLICE, "Bank" );
						gPlayerData[playerid][pTicket] = 0;
						SavePlayerData( playerid, "Ticket" );
					}
					if( gPlayerData[playerid][pBizKey] != 255 )
					{
						printf("[PAYDAY:] PlayerName = %s, Bank = %d - %d, SOURCE = taxes (business)", gPlayerData[playerid][pName], gPlayerData[playerid][pBank], floatround( Businesses[ gPlayerData[playerid][pBizKey] ][BizPrice] * DynamicTaxes[BusinessTax], floatround_round ) ); 
						gPlayerData[playerid][pBank] -= floatround( Businesses[ gPlayerData[playerid][pBizKey] ][BizPrice] * DynamicTaxes[BusinessTax], floatround_round );
						DynamicFactions[FACTIONID_GOVERNMENT][fBank] += floatround( Businesses[ gPlayerData[playerid][pBizKey] ][BizPrice] * DynamicTaxes[BusinessTax], floatround_round );
					}
					
					/*
					* Ensurance for vehicles
					*/
					if( gPlayerData[playerid][pItem1type] == 2 && gPlayerData[playerid][pItem1] != 0 )
					{
						switch( gPlayerData[playerid][pItem1param] )
						{
							case 1: gPlayerData[playerid][pBank] -= 200;
							case 2: gPlayerData[playerid][pBank] -= 400;
							case 3: gPlayerData[playerid][pBank] -= 1000;
						}
					}
					if( gPlayerData[playerid][pItem2type] == 2 && gPlayerData[playerid][pItem2] != 0 )
					{
						switch( gPlayerData[playerid][pItem2param] )
						{
							case 1: gPlayerData[playerid][pBank] -= 200;
							case 2: gPlayerData[playerid][pBank] -= 400;
							case 3: gPlayerData[playerid][pBank] -= 1000;
						}
					}
					if( gPlayerData[playerid][pItem3type] == 2 && gPlayerData[playerid][pItem3] != 0 )
					{
						switch( gPlayerData[playerid][pItem3param] )
						{
							case 1: gPlayerData[playerid][pBank] -= 200;
							case 2: gPlayerData[playerid][pBank] -= 400;
							case 3: gPlayerData[playerid][pBank] -= 1000;
						}
					}
					if( gPlayerData[playerid][pItem4type] == 2 && gPlayerData[playerid][pItem4] != 0 )
					{
						switch( gPlayerData[playerid][pItem4param] )
						{
							case 1: gPlayerData[playerid][pBank] -= 200;
							case 2: gPlayerData[playerid][pBank] -= 400;
							case 3: gPlayerData[playerid][pBank] -= 1000;
						}
					}
					if( gPlayerData[playerid][pItem5type] == 2 && gPlayerData[playerid][pItem5] != 0 )
					{
						switch( gPlayerData[playerid][pItem5param] )
						{
							case 1: gPlayerData[playerid][pBank] -= 200;
							case 2: gPlayerData[playerid][pBank] -= 400;
							case 3: gPlayerData[playerid][pBank] -= 1000;
						}
					}
					if( PHaveExpandItem(playerid) || gPlayerData[playerid][pVipItem] > 0 )
					{
						if( gPlayerData[playerid][pItem6type] == 2 && gPlayerData[playerid][pItem6] != 0 )
						{
							switch( gPlayerData[playerid][pItem6param] )
							{
								case 1: gPlayerData[playerid][pBank] -= 200;
								case 2: gPlayerData[playerid][pBank] -= 400;
								case 3: gPlayerData[playerid][pBank] -= 1000;
							}
						}
						if( gPlayerData[playerid][pItem7type] == 2 && gPlayerData[playerid][pItem7] != 0 )
						{
							switch( gPlayerData[playerid][pItem7param] )
							{
								case 1: gPlayerData[playerid][pBank] -= 200;
								case 2: gPlayerData[playerid][pBank] -= 400;
								case 3: gPlayerData[playerid][pBank] -= 1000;
							}
						}
						if( gPlayerData[playerid][pItem8type] == 2 && gPlayerData[playerid][pItem8] != 0 )
						{
							switch( gPlayerData[playerid][pItem8param] )
							{
								case 1: gPlayerData[playerid][pBank] -= 200;
								case 2: gPlayerData[playerid][pBank] -= 400;
								case 3: gPlayerData[playerid][pBank] -= 1000;
							}
						}
						if( gPlayerData[playerid][pItem9type] == 2 && gPlayerData[playerid][pItem9] != 0 )
						{
							switch( gPlayerData[playerid][pItem9param] )
							{
								case 1: gPlayerData[playerid][pBank] -= 200;
								case 2: gPlayerData[playerid][pBank] -= 400;
								case 3: gPlayerData[playerid][pBank] -= 1000;
							}
						}
						if( gPlayerData[playerid][pItem10type] == 2 && gPlayerData[playerid][pItem10] != 0 )
						{
							switch( gPlayerData[playerid][pItem10param] )
							{
								case 1: gPlayerData[playerid][pBank] -= 200;
								case 2: gPlayerData[playerid][pBank] -= 400;
								case 3: gPlayerData[playerid][pBank] -= 1000;
							}
						}
						if( gPlayerData[playerid][pVipItem] > 0 )
						{
							if( gPlayerData[playerid][pItem11type] == 2 && gPlayerData[playerid][pItem11] != 0 )
							{
								switch( gPlayerData[playerid][pItem11param] )
								{
									case 1: gPlayerData[playerid][pBank] -= 200;
									case 2: gPlayerData[playerid][pBank] -= 400;
									case 3: gPlayerData[playerid][pBank] -= 1000;
								}
							}
							if( gPlayerData[playerid][pItem12type] == 2 && gPlayerData[playerid][pItem12] != 0 )
							{
								switch( gPlayerData[playerid][pItem12param] )
								{
									case 1: gPlayerData[playerid][pBank] -= 200;
									case 2: gPlayerData[playerid][pBank] -= 400;
									case 3: gPlayerData[playerid][pBank] -= 1000;
								}
							}
							if( gPlayerData[playerid][pItem13type] == 2 && gPlayerData[playerid][pItem13] != 0 )
							{
								switch( gPlayerData[playerid][pItem13param] )
								{
									case 1: gPlayerData[playerid][pBank] -= 200;
									case 2: gPlayerData[playerid][pBank] -= 400;
									case 3: gPlayerData[playerid][pBank] -= 1000;
								}
							}
							if( gPlayerData[playerid][pItem14type] == 2 && gPlayerData[playerid][pItem14] != 0 )
							{
								switch( gPlayerData[playerid][pItem14param] )
								{
									case 1: gPlayerData[playerid][pBank] -= 200;
									case 2: gPlayerData[playerid][pBank] -= 400;
									case 3: gPlayerData[playerid][pBank] -= 1000;
								}
							}
							if( gPlayerData[playerid][pItem15type] == 2 && gPlayerData[playerid][pItem15] != 0 )
							{
								switch( gPlayerData[playerid][pItem15param] )
								{
									case 1: gPlayerData[playerid][pBank] -= 200;
									case 2: gPlayerData[playerid][pBank] -= 400;
									case 3: gPlayerData[playerid][pBank] -= 1000;
								}
							}
						}
					}
					
					if( gPlayerData[playerid][pItem1type] == 2 && gPlayerData[playerid][pItem1] != 0 )
					{
						switch( gPlayerData[playerid][pItem1param2] )
						{
							case 1: gPlayerData[playerid][pBank] -= 200;
							case 2: gPlayerData[playerid][pBank] -= 400;
							case 3: gPlayerData[playerid][pBank] -= 1000;
						}
					}
					if( gPlayerData[playerid][pItem2type] == 2 && gPlayerData[playerid][pItem2] != 0 )
					{
						switch( gPlayerData[playerid][pItem2param2] )
						{
							case 1: gPlayerData[playerid][pBank] -= 200;
							case 2: gPlayerData[playerid][pBank] -= 400;
							case 3: gPlayerData[playerid][pBank] -= 1000;
						}
					}
					if( gPlayerData[playerid][pItem3type] == 2 && gPlayerData[playerid][pItem3] != 0 )
					{
						switch( gPlayerData[playerid][pItem3param2] )
						{
							case 1: gPlayerData[playerid][pBank] -= 200;
							case 2: gPlayerData[playerid][pBank] -= 400;
							case 3: gPlayerData[playerid][pBank] -= 1000;
						}
					}
					if( gPlayerData[playerid][pItem4type] == 2 && gPlayerData[playerid][pItem4] != 0 )
					{
						switch( gPlayerData[playerid][pItem4param2] )
						{
							case 1: gPlayerData[playerid][pBank] -= 200;
							case 2: gPlayerData[playerid][pBank] -= 400;
							case 3: gPlayerData[playerid][pBank] -= 1000;
						}
					}
					if( gPlayerData[playerid][pItem5type] == 2 && gPlayerData[playerid][pItem5] != 0 )
					{
						switch( gPlayerData[playerid][pItem5param2] )
						{
							case 1: gPlayerData[playerid][pBank] -= 200;
							case 2: gPlayerData[playerid][pBank] -= 400;
							case 3: gPlayerData[playerid][pBank] -= 1000;
						}
					}
					if( PHaveExpandItem(playerid) || gPlayerData[playerid][pVipItem] > 0 )
					{
						if( gPlayerData[playerid][pItem6type] == 2 && gPlayerData[playerid][pItem6] != 0 )
						{
							switch( gPlayerData[playerid][pItem6param2] )
							{
								case 1: gPlayerData[playerid][pBank] -= 200;
								case 2: gPlayerData[playerid][pBank] -= 400;
								case 3: gPlayerData[playerid][pBank] -= 1000;
							}
						}
						if( gPlayerData[playerid][pItem7type] == 2 && gPlayerData[playerid][pItem7] != 0 )
						{
							switch( gPlayerData[playerid][pItem7param2] )
							{
								case 1: gPlayerData[playerid][pBank] -= 200;
								case 2: gPlayerData[playerid][pBank] -= 400;
								case 3: gPlayerData[playerid][pBank] -= 1000;
							}
						}
						if( gPlayerData[playerid][pItem8type] == 2 && gPlayerData[playerid][pItem8] != 0 )
						{
							switch( gPlayerData[playerid][pItem8param2] )
							{
								case 1: gPlayerData[playerid][pBank] -= 200;
								case 2: gPlayerData[playerid][pBank] -= 400;
								case 3: gPlayerData[playerid][pBank] -= 1000;
							}
						}
						if( gPlayerData[playerid][pItem9type] == 2 && gPlayerData[playerid][pItem9] != 0 )
						{
							switch( gPlayerData[playerid][pItem9param2] )
							{
								case 1: gPlayerData[playerid][pBank] -= 200;
								case 2: gPlayerData[playerid][pBank] -= 400;
								case 3: gPlayerData[playerid][pBank] -= 1000;
							}
						}
						if( gPlayerData[playerid][pItem10type] == 2 && gPlayerData[playerid][pItem10] != 0 )
						{
							switch( gPlayerData[playerid][pItem10param2] )
							{
								case 1: gPlayerData[playerid][pBank] -= 200;
								case 2: gPlayerData[playerid][pBank] -= 400;
								case 3: gPlayerData[playerid][pBank] -= 1000;
							}
						}
						if( gPlayerData[playerid][pVipItem] > 0 )
						{
							if( gPlayerData[playerid][pItem11type] == 2 && gPlayerData[playerid][pItem11] != 0 )
							{
								switch( gPlayerData[playerid][pItem11param2] )
								{
									case 1: gPlayerData[playerid][pBank] -= 200;
									case 2: gPlayerData[playerid][pBank] -= 400;
									case 3: gPlayerData[playerid][pBank] -= 1000;
								}
							}
							if( gPlayerData[playerid][pItem12type] == 2 && gPlayerData[playerid][pItem12] != 0 )
							{
								switch( gPlayerData[playerid][pItem12param2] )
								{
									case 1: gPlayerData[playerid][pBank] -= 200;
									case 2: gPlayerData[playerid][pBank] -= 400;
									case 3: gPlayerData[playerid][pBank] -= 1000;
								}
							}
							if( gPlayerData[playerid][pItem13type] == 2 && gPlayerData[playerid][pItem13] != 0 )
							{
								switch( gPlayerData[playerid][pItem13param2] )
								{
									case 1: gPlayerData[playerid][pBank] -= 200;
									case 2: gPlayerData[playerid][pBank] -= 400;
									case 3: gPlayerData[playerid][pBank] -= 1000;
								}
							}
							if( gPlayerData[playerid][pItem14type] == 2 && gPlayerData[playerid][pItem14] != 0 )
							{
								switch( gPlayerData[playerid][pItem14param2] )
								{
									case 1: gPlayerData[playerid][pBank] -= 200;
									case 2: gPlayerData[playerid][pBank] -= 400;
									case 3: gPlayerData[playerid][pBank] -= 1000;
								}
							}
							if( gPlayerData[playerid][pItem15type] == 2 && gPlayerData[playerid][pItem15] != 0 )
							{
								switch( gPlayerData[playerid][pItem15param2] )
								{
									case 1: gPlayerData[playerid][pBank] -= 200;
									case 2: gPlayerData[playerid][pBank] -= 400;
									case 3: gPlayerData[playerid][pBank] -= 1000;
								}
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
								printf("[PAYDAY:] PlayerName = %s, House ID: %d, confiscated", gPlayerData[playerid][pName], i);
								Houses[i][HConfiscated] = 1;
								SaveHouseData(i, "Confiscated");
							}
						}
						for(new i = 0; i < sizeof(Businesses); i++)
						{
							if( strcmp(Businesses[i][Owner], gPlayerData[playerid][pName], true) == 0 && strlen(Businesses[i][Owner]) > 0 )
							{
								printf("[PAYDAY:] PlayerName = %s, Biz ID: %d, confiscated", gPlayerData[playerid][pName], i);
								Businesses[i][BConfiscated] = 1;
								SaveBizData(i, "Confiscated");
							}
						}
						for(new i = 0; i < sizeof(gVehData); i++)
						{
							if( strcmp(gVehData[i][Owner], gPlayerData[playerid][pName], true) == 0 && strlen(gVehData[i][Owner]) > 0 )
							{
								printf("[PAYDAY:] PlayerName = %s, Veh ID: %d, confiscated", gPlayerData[playerid][pName], i);
								
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
								printf("[PAYDAY:] PlayerName = %s, House ID: %d, deconfiscated", gPlayerData[playerid][pName], i);
								Houses[i][HConfiscated] = 0;
								SaveHouseData(i, "Confiscated");
							}
						}
						for(new i = 0; i < sizeof(Businesses); i++)
						{
							if( strcmp(Businesses[i][Owner], gPlayerData[playerid][pName], true) == 0 && strlen(Businesses[i][Owner]) > 0 )
							{
								printf("[PAYDAY:] PlayerName = %s, Biz ID: %d, deconfiscated", gPlayerData[playerid][pName], i);
								Businesses[i][BConfiscated] = 0;
								SaveBizData(i, "Confiscated");
							}
						}
						for(new i = 0; i < sizeof(gVehData); i++)
						{
							if( strcmp(gVehData[i][Owner], gPlayerData[playerid][pName], true) == 0 && strlen(gVehData[i][Owner]) > 0 )
							{
								printf("[PAYDAY:] PlayerName = %s, Veh ID: %d, deconfiscated", gPlayerData[playerid][pName], i);
								
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
						if( gPlayerData[playerid][pVipAFKT] > 0 )
						{
							gPlayerData[playerid][pVipAFKT]--;
							SavePlayerData( playerid, "VipAFKT" );
						}
						if( gPlayerData[playerid][pVipExpT] > 0 )
						{
							gPlayerData[playerid][pVipExpT]--;
							SavePlayerData( playerid, "VipExpT" );
						}
						if( gPlayerData[playerid][pVipItem] > 0 )
						{
							gPlayerData[playerid][pVipItem]--;
							SavePlayerData( playerid, "VipItem" );
						}
					}
					
					/*
					* Other stuff
					*/					
					if( gPlayerData[playerid][pWarnings] > 0 )
					{
						if( gPlayerData[playerid][pWarnCooldown] <= 0 )
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
					SavePlayerData(playerid, "LastLogged");
					
					// if( gPlayerData[playerid][pJobTimeChange] > 0 )
					// {
						// gPlayerData[playerid][pJobTimeChange]--;
						// SavePlayerData( playerid, "JobTimeChange" );
					// }
					SaveFData( FACTIONID_GOVERNMENT, "Bank" );
					SavePlayerData( playerid, "Bank" );
					SavePlayerData( playerid, "Cash" );
					
					/* 
					* Select next player in DB
					*/
					gPayDayLoop++;
					new stringtmp1[2048];
					printf("[PAYDAY:] gPayDayLoop = %d, gPayDayCount = %d", gPayDayLoop, gPayDayCount );
					if( gPayDayLoop <= gPayDayCount )
					{
						format(stringtmp1, sizeof(stringtmp1), "SELECT `Key`,`ID`,`PlayerName`,`Level`,`AdminLevel`,`DonateRank`,`Registered`,`Sex`,`Age`,`Experience`,`Money`,`Bank`,`Skin`,`PlayingHours`,`AllowedPayday`,`PayCheck`,`Faction`,`Rank`,`Banned`");
						strcat( stringtmp1, ",`Warnings`,`Jailed`,`JailTime`,`CrashX`,`CrashY`,`CrashZ`,`CrashInt`,`CrashW`,`Crashed`,`Wins`,`Loses`,`InvWeapon`,`InvAmmo`,`Tutorial`,`Moderator`,`WantedLvl`,`FirstCar`,`FirstReanimation`,`FirstPhone`,`FirstLeader`" );
						strcat( stringtmp1, ",`CrashAngle`,`HourAssist`,`JoinedFaction`,`HoursOnDuty`,`HoursOnDutyHelper`,`WarnCooldown`,`SpeedLimiter`,`AdminDuty`,`CharDescription`,`CharDescriptionColor`, `FirstJob`, `FirstID`, `FirstBuy`, `FirstHouse`, `FirstDescription`" );
						strcat( stringtmp1, ", `FirstAction`, `FirstBankUse`, `FirstStats`, `FirstJail`, `FirstStudy`" );
						format( stringtmp1, sizeof(stringtmp1), "%s FROM `samp_users` WHERE `Banned` = '0' LIMIT %d , 1", stringtmp1, gPayDayLoop);
						if(mysql_query(stringtmp1, PLAYER_DATA_LOAD_NAME_MYSQL, CUSTOM_MAX_PLAYERS, db_con2) != 0)
						{
							format(string, sizeof(string), "MYSQL QUERY failed in PayDay");
							PayDayLog(string);
						}	
					}
				}
			}
		}
		case LOAD_RAFINERY:
		{
			if( !mysql_store_result(db_con2) )
			{
				printf("[ERROR:] Can't store result on LOAD_RAFINERY");
				GameModeExit();
				return 1;
			}
			mysql_fetch_row(db_result, "|", db_con2);

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

			print("[SKRYPT:] Zaladowano rafinerie");
			
			
		}
		case LOAD_WFACTORYLEGAL:
		{
			if( !mysql_store_result(db_con2) )
			{
				printf("[ERROR:] Can't store result on LOAD_WFACTORYLEGAL");
				GameModeExit();
				return 1;
			}
			mysql_fetch_row(db_result, "|", db_con2);
			split2(db_result, arrCoords, '|');
			
			new TmpData[256];
			
			//WFactoryLegalInfo[WFactoryID] = strval(arrCoords[0]); // narazie nie potrzebne
			
			mysql_fetch_field("WFactoryBuildingID", TmpData, db_con2);
			WFactoryLegal[WFactoryBuildingID] = strval(TmpData);
			
			mysql_fetch_field("WFactoryReward", TmpData, db_con2);
			WFactoryLegal[WFactoryReward] = strval(TmpData);
			mysql_fetch_field("WFactoryCPPartTakeWV", TmpData, db_con2);
			WFactoryLegal[WFactoryCPPartTakeWV] = strval(TmpData);
			mysql_fetch_field("WFactoryCPPartTakeInt", TmpData, db_con2);
			WFactoryLegal[WFactoryCPPartTakeInt] = strval(TmpData);
			mysql_fetch_field("WFactoryCPPartTakeX", TmpData, db_con2);
			WFactoryLegal[WFactoryCPPartTakeX] = strval(TmpData);
			mysql_fetch_field("WFactoryCPPartTakeY", TmpData, db_con2);
			WFactoryLegal[WFactoryCPPartTakeY] = strval(TmpData);
			mysql_fetch_field("WFactoryCPPartTakeZ", TmpData, db_con2);
			WFactoryLegal[WFactoryCPPartTakeZ] = strval(TmpData);
			mysql_fetch_field("WFactoryCPPartSetup1X", TmpData, db_con2);
			WFactoryLegal[WFactoryCPPartSetup1X] = strval(TmpData);
			mysql_fetch_field("WFactoryCPPartSetup1Y", TmpData, db_con2);
			WFactoryLegal[WFactoryCPPartSetup1Y] = strval(TmpData);
			mysql_fetch_field("WFactoryCPPartSetup1Z", TmpData, db_con2);
			WFactoryLegal[WFactoryCPPartSetup1Z] = strval(TmpData);
			mysql_fetch_field("WFactoryCPPartSetup2X", TmpData, db_con2);
			WFactoryLegal[WFactoryCPPartSetup2X] = strval(TmpData);
			mysql_fetch_field("WFactoryCPPartSetup2Y", TmpData, db_con2);
			WFactoryLegal[WFactoryCPPartSetup2Y] = strval(TmpData);
			mysql_fetch_field("WFactoryCPPartSetup2Z", TmpData, db_con2);
			WFactoryLegal[WFactoryCPPartSetup2Z] = strval(TmpData);
			mysql_fetch_field("WFactoryCPPartSetup3X", TmpData, db_con2);
			WFactoryLegal[WFactoryCPPartSetup3X] = strval(TmpData);
			mysql_fetch_field("WFactoryCPPartSetup3Y", TmpData, db_con2);
			WFactoryLegal[WFactoryCPPartSetup3Y] = strval(TmpData);
			mysql_fetch_field("WFactoryCPPartSetup3Z", TmpData, db_con2);
			WFactoryLegal[WFactoryCPPartSetup3Z] = strval(TmpData);
			mysql_fetch_field("WFactoryCPPartSetup4X", TmpData, db_con2);
			WFactoryLegal[WFactoryCPPartSetup4X] = strval(TmpData);
			mysql_fetch_field("WFactoryCPPartSetup4Y", TmpData, db_con2);
			WFactoryLegal[WFactoryCPPartSetup4Y] = strval(TmpData);
			mysql_fetch_field("WFactoryCPPartSetup4Z", TmpData, db_con2);
			WFactoryLegal[WFactoryCPPartSetup4Z] = strval(TmpData);
			mysql_fetch_field("WFactoryCPPartSetup5X", TmpData, db_con2);
			WFactoryLegal[WFactoryCPPartSetup5X] = strval(TmpData);
			mysql_fetch_field("WFactoryCPPartSetup5Y", TmpData, db_con2);
			WFactoryLegal[WFactoryCPPartSetup5Y] = strval(TmpData);
			mysql_fetch_field("WFactoryCPPartSetup5Z", TmpData, db_con2);
			WFactoryLegal[WFactoryCPPartSetup5Z] = strval(TmpData);
			mysql_fetch_field("WFactoryCPPartSetup6X", TmpData, db_con2);
			WFactoryLegal[WFactoryCPPartSetup6X] = strval(TmpData);
			mysql_fetch_field("WFactoryCPPartSetup6Y", TmpData, db_con2);
			WFactoryLegal[WFactoryCPPartSetup6Y] = strval(TmpData);
			mysql_fetch_field("WFactoryCPPartSetup6Z", TmpData, db_con2);
			WFactoryLegal[WFactoryCPPartSetup6Z] = strval(TmpData);
			mysql_fetch_field("WFactoryCPAmmoSetup1X", TmpData, db_con2);
			WFactoryLegal[WFactoryCPAmmoSetup1X] = strval(TmpData);
			mysql_fetch_field("WFactoryCPAmmoSetup1Y", TmpData, db_con2);
			WFactoryLegal[WFactoryCPAmmoSetup1Y] = strval(TmpData);
			mysql_fetch_field("WFactoryCPAmmoSetup1Z", TmpData, db_con2);
			WFactoryLegal[WFactoryCPAmmoSetup1Z] = strval(TmpData);
			mysql_fetch_field("WFactoryCPAmmoSetup2X", TmpData, db_con2);
			WFactoryLegal[WFactoryCPAmmoSetup2X] = strval(TmpData);
			mysql_fetch_field("WFactoryCPAmmoSetup2Y", TmpData, db_con2);
			WFactoryLegal[WFactoryCPAmmoSetup2Y] = strval(TmpData);
			mysql_fetch_field("WFactoryCPAmmoSetup2Z", TmpData, db_con2);
			WFactoryLegal[WFactoryCPAmmoSetup2Z] = strval(TmpData);
			mysql_fetch_field("WFactoryCPAmmoSetup3X", TmpData, db_con2);
			WFactoryLegal[WFactoryCPAmmoSetup3X] = strval(TmpData);
			mysql_fetch_field("WFactoryCPAmmoSetup3Y", TmpData, db_con2);
			WFactoryLegal[WFactoryCPAmmoSetup3Y] = strval(TmpData);
			mysql_fetch_field("WFactoryCPAmmoSetup3Z", TmpData, db_con2);
			WFactoryLegal[WFactoryCPAmmoSetup3Z] = strval(TmpData);
			mysql_fetch_field("WFactoryCPAmmoSetup4X", TmpData, db_con2);
			WFactoryLegal[WFactoryCPAmmoSetup4X] = strval(TmpData);
			mysql_fetch_field("WFactoryCPAmmoSetup4Y", TmpData, db_con2);
			WFactoryLegal[WFactoryCPAmmoSetup4Y] = strval(TmpData);
			mysql_fetch_field("WFactoryCPAmmoSetup4Z", TmpData, db_con2);
			WFactoryLegal[WFactoryCPAmmoSetup4Z] = strval(TmpData);
			mysql_fetch_field("WFactoryCPAmmoSetup5X", TmpData, db_con2);
			WFactoryLegal[WFactoryCPAmmoSetup5X] = strval(TmpData);
			mysql_fetch_field("WFactoryCPAmmoSetup5Y", TmpData, db_con2);
			WFactoryLegal[WFactoryCPAmmoSetup5Y] = strval(TmpData);
			mysql_fetch_field("WFactoryCPAmmoSetup5Z", TmpData, db_con2);
			WFactoryLegal[WFactoryCPAmmoSetup5Z] = strval(TmpData);
			mysql_fetch_field("WFactoryCPAmmoSetup6X", TmpData, db_con2);
			WFactoryLegal[WFactoryCPAmmoSetup6X] = strval(TmpData);
			mysql_fetch_field("WFactoryCPAmmoSetup6Y", TmpData, db_con2);
			WFactoryLegal[WFactoryCPAmmoSetup6Y] = strval(TmpData);
			mysql_fetch_field("WFactoryCPAmmoSetup6Z", TmpData, db_con2);
			WFactoryLegal[WFactoryCPAmmoSetup6Z] = strval(TmpData);
			mysql_fetch_field("WFactoryCPDocsX", TmpData, db_con2);
			WFactoryLegal[WFactoryCPDocsX] = strval(TmpData);
			mysql_fetch_field("WFactoryCPDocsY", TmpData, db_con2);
			WFactoryLegal[WFactoryCPDocsY] = strval(TmpData);
			mysql_fetch_field("WFactoryCPDocsZ", TmpData, db_con2);
			WFactoryLegal[WFactoryCPDocsZ] = strval(TmpData);
			mysql_fetch_field("WFactory9MM", TmpData, db_con2);
			WFactoryLegalLight[WFactory9MM] = strval(TmpData);
			mysql_fetch_field("WFactory9MMO", TmpData, db_con2);
			WFactoryLegalLight[WFactory9MMO] = strval(TmpData);
			mysql_fetch_field("WFactory9MMSil", TmpData, db_con2);
			WFactoryLegalLight[WFactory9MMSil] = strval(TmpData);
			mysql_fetch_field("WFactory9MMSilO", TmpData, db_con2);
			WFactoryLegalLight[WFactory9MMSilO] = strval(TmpData);
			mysql_fetch_field("WFactoryDesEagle", TmpData, db_con2);
			WFactoryLegalLight[WFactoryDesEagle] = strval(TmpData);
			mysql_fetch_field("WFactoryDesEagleO", TmpData, db_con2);
			WFactoryLegalLight[WFactoryDesEagleO] = strval(TmpData);
			mysql_fetch_field("WFactoryMicroSMG", TmpData, db_con2);
			WFactoryLegalLight[WFactoryMicroSMG] = strval(TmpData);
			mysql_fetch_field("WFactoryMicroSMGO", TmpData, db_con2);
			WFactoryLegalLight[WFactoryMicroSMGO] = strval(TmpData);
			mysql_fetch_field("WFactoryMP5", TmpData, db_con2);
			WFactoryLegalLight[WFactoryMP5] = strval(TmpData);
			mysql_fetch_field("WFactoryMP5O", TmpData, db_con2);
			WFactoryLegalLight[WFactoryMP5O] = strval(TmpData);
			mysql_fetch_field("WFactoryTec9", TmpData, db_con2);
			WFactoryLegalLight[WFactoryTec9] = strval(TmpData);
			mysql_fetch_field("WFactoryTec9O", TmpData, db_con2);
			WFactoryLegalLight[WFactoryTec9O] = strval(TmpData);
			mysql_fetch_field("WFactoryShotgun", TmpData, db_con2);
			WFactoryLegalHeavy[WFactoryShotgun] = strval(TmpData);
			mysql_fetch_field("WFactoryShotgunO", TmpData, db_con2);
			WFactoryLegalHeavy[WFactoryShotgunO] = strval(TmpData);
			mysql_fetch_field("WFactoryAK47", TmpData, db_con2);
			WFactoryLegalHeavy[WFactoryAK47] = strval(TmpData);
			mysql_fetch_field("WFactoryAK47O", TmpData, db_con2);
			WFactoryLegalHeavy[WFactoryAK47O] = strval(TmpData);
			mysql_fetch_field("WFactoryM4", TmpData, db_con2);
			WFactoryLegalHeavy[WFactoryM4] = strval(TmpData);
			mysql_fetch_field("WFactoryM4O", TmpData, db_con2);
			WFactoryLegalHeavy[WFactoryM4O] = strval(TmpData);
			mysql_fetch_field("WFactoryRifle", TmpData, db_con2);
			WFactoryLegalHeavy[WFactoryRifle] = strval(TmpData);
			mysql_fetch_field("WFactoryRifleO", TmpData, db_con2);
			WFactoryLegalHeavy[WFactoryRifleO] = strval(TmpData);
			mysql_fetch_field("WFactorySRifle", TmpData, db_con2);
			WFactoryLegalHeavy[WFactorySRifle] = strval(TmpData);
			mysql_fetch_field("WFactorySRifleO", TmpData, db_con2);
			WFactoryLegalHeavy[WFactorySRifleO] = strval(TmpData);
			mysql_fetch_field("WFactorySCharge", TmpData, db_con2);
			WFactoryLegalHeavy[WFactorySCharge] = strval(TmpData);
			mysql_fetch_field("WFactory9MMAmmo", TmpData, db_con2);
			WFactoryLegalLight[WFactory9MMAmmo] = strval(TmpData);
			mysql_fetch_field("WFactory50AEAmmo", TmpData, db_con2);
			WFactoryLegalLight[WFactory50AEAmmo] = strval(TmpData);
			mysql_fetch_field("WFactoryBuckshot", TmpData, db_con2);
			WFactoryLegalHeavy[WFactoryBuckshot] = strval(TmpData);
			mysql_fetch_field("WFactory762MMAmmo", TmpData, db_con2);
			WFactoryLegalHeavy[WFactory762MMAmmo] = strval(TmpData);
			mysql_fetch_field("WFactory127MMAmmo", TmpData, db_con2);
			WFactoryLegalHeavy[WFactory127MMAmmo] = strval(TmpData);
			mysql_fetch_field("WFactoryKGP66MMAmmo", TmpData, db_con2);
			WFactoryLegalHeavy[WFactoryKGP66MMAmmo] = strval(TmpData);
			mysql_fetch_field("WFactoryNapalm", TmpData, db_con2);
			WFactoryLegalHeavy[WFactoryNapalm] = strval(TmpData);
			mysql_fetch_field("WFactoryPistolPart1", TmpData, db_con2);
			WFactoryLegalLight[WFactoryPistolPart1] = strval(TmpData);
			mysql_fetch_field("WFactoryPistolS1Part1", TmpData, db_con2);
			WFactoryLegalLight[WFactoryPistolS1Part1] = strval(TmpData);
			mysql_fetch_field("WFactoryPistolS1Part2", TmpData, db_con2);
			WFactoryLegalLight[WFactoryPistolS1Part2] = strval(TmpData);
			mysql_fetch_field("WFactoryPistolS1Part3", TmpData, db_con2);
			WFactoryLegalLight[WFactoryPistolS1Part3] = strval(TmpData);
			mysql_fetch_field("WFactoryPistolPart2", TmpData, db_con2);
			WFactoryLegalLight[WFactoryPistolPart2] = strval(TmpData);
			mysql_fetch_field("WFactoryPistolS2Part1", TmpData, db_con2);
			WFactoryLegalLight[WFactoryPistolS2Part1] = strval(TmpData);
			mysql_fetch_field("WFactoryPistolS2Part2", TmpData, db_con2);
			WFactoryLegalLight[WFactoryPistolS2Part2] = strval(TmpData);
			mysql_fetch_field("WFactoryPistolS2Part3", TmpData, db_con2);
			WFactoryLegalLight[WFactoryPistolS2Part3] = strval(TmpData);
			mysql_fetch_field("WFactoryPistolPart3", TmpData, db_con2);
			WFactoryLegalLight[WFactoryPistolPart3] = strval(TmpData);
			mysql_fetch_field("WFactoryPistolS3Part1", TmpData, db_con2);
			WFactoryLegalLight[WFactoryPistolS3Part1] = strval(TmpData);
			mysql_fetch_field("WFactoryPistolS3Part2", TmpData, db_con2);
			WFactoryLegalLight[WFactoryPistolS3Part2] = strval(TmpData);
			mysql_fetch_field("WFactoryPistolS3Part3", TmpData, db_con2);
			WFactoryLegalLight[WFactoryPistolS3Part3] = strval(TmpData);
			mysql_fetch_field("WFactoryPistolS3Part4", TmpData, db_con2);
			WFactoryLegalLight[WFactoryPistolS3Part4] = strval(TmpData);
			mysql_fetch_field("WFactoryPistolPart4", TmpData, db_con2);
			WFactoryLegalLight[WFactoryPistolPart4] = strval(TmpData);
			mysql_fetch_field("WFactoryPistolPart5", TmpData, db_con2);
			WFactoryLegalLight[WFactoryPistolPart5] = strval(TmpData);
			mysql_fetch_field("WFactoryPistolPart6", TmpData, db_con2);
			WFactoryLegalLight[WFactoryPistolPart6] = strval(TmpData);
			mysql_fetch_field("WFactoryRiflePart1", TmpData, db_con2);
			WFactoryLegalHeavy[WFactoryRiflePart1] = strval(TmpData);
			mysql_fetch_field("WFactoryRifleS1Part1", TmpData, db_con2);
			WFactoryLegalHeavy[WFactoryRifleS1Part1] = strval(TmpData);
			mysql_fetch_field("WFactoryRifleS1Part2", TmpData, db_con2);
			WFactoryLegalHeavy[WFactoryRifleS1Part2] = strval(TmpData);
			// mysql_fetch_field("WFactoryRifleS1Part3", TmpData, db_con2);
			// WFactoryLegalHeavy[WFactoryRifleS1Part3] = strval(TmpData);
			mysql_fetch_field("WFactoryRiflePart2", TmpData, db_con2);
			WFactoryLegalHeavy[WFactoryRiflePart2] = strval(TmpData);
			mysql_fetch_field("WFactoryRifleS2Part1", TmpData, db_con2);
			WFactoryLegalHeavy[WFactoryRifleS2Part1] = strval(TmpData);
			mysql_fetch_field("WFactoryRifleS2Part2", TmpData, db_con2);
			WFactoryLegalHeavy[WFactoryRifleS2Part2] = strval(TmpData);
			mysql_fetch_field("WFactoryRifleS2Part3", TmpData, db_con2);
			WFactoryLegalHeavy[WFactoryRifleS2Part3] = strval(TmpData);
			mysql_fetch_field("WFactoryRiflePart3", TmpData, db_con2);
			WFactoryLegalHeavy[WFactoryRiflePart3] = strval(TmpData);
			mysql_fetch_field("WFactoryRifleS3Part4", TmpData, db_con2);
			WFactoryLegalHeavy[WFactoryRifleS3Part4] = strval(TmpData);
			mysql_fetch_field("WFactoryRifleS3Part4", TmpData, db_con2);
			WFactoryLegalHeavy[WFactoryRifleS3Part4] = strval(TmpData);
			mysql_fetch_field("WFactoryRifleS3Part4", TmpData, db_con2);
			WFactoryLegalHeavy[WFactoryRifleS3Part4] = strval(TmpData);
			mysql_fetch_field("WFactoryRifleS3Part4", TmpData, db_con2);
			WFactoryLegalHeavy[WFactoryRifleS3Part4] = strval(TmpData);
			mysql_fetch_field("WFactoryRiflePart4", TmpData, db_con2);
			WFactoryLegalHeavy[WFactoryRiflePart4] = strval(TmpData);
			mysql_fetch_field("WFactoryRiflePart5", TmpData, db_con2);
			WFactoryLegalHeavy[WFactoryRiflePart5] = strval(TmpData);
			mysql_fetch_field("WFactoryRiflePart6", TmpData, db_con2);
			WFactoryLegalHeavy[WFactoryRiflePart6] = strval(TmpData);
			mysql_fetch_field("WFactoryRiflePart7", TmpData, db_con2);
			WFactoryLegalHeavy[WFactoryRiflePart7] = strval(TmpData);
			mysql_fetch_field("WFactoryAmmoPart1a", TmpData, db_con2);
			WFactoryLegalLight[WFactoryAmmoPart1a] = strval(TmpData);
			mysql_fetch_field("WFactoryAmmoPart2a", TmpData, db_con2);
			WFactoryLegalLight[WFactoryAmmoPart2a] = strval(TmpData);
			mysql_fetch_field("WFactoryAmmoPart3a", TmpData, db_con2);
			WFactoryLegalLight[WFactoryAmmoPart3a] = strval(TmpData);
			mysql_fetch_field("WFactoryAmmoPart4a", TmpData, db_con2);
			WFactoryLegalLight[WFactoryAmmoPart4a] = strval(TmpData);
			mysql_fetch_field("WFactoryAmmoPart1b", TmpData, db_con2);
			WFactoryLegalLight[WFactoryAmmoPart1b] = strval(TmpData);
			mysql_fetch_field("WFactoryAmmoPart2b", TmpData, db_con2);
			WFactoryLegalLight[WFactoryAmmoPart2b] = strval(TmpData);
			mysql_fetch_field("WFactoryAmmoPart3b", TmpData, db_con2);
			WFactoryLegalLight[WFactoryAmmoPart3b] = strval(TmpData);
			mysql_fetch_field("WFactoryAmmoPart4b", TmpData, db_con2);
			WFactoryLegalLight[WFactoryAmmoPart4b] = strval(TmpData);
			mysql_fetch_field("WFactoryAmmoPart1c", TmpData, db_con2);
			WFactoryLegalLight[WFactoryAmmoPart1c] = strval(TmpData);
			mysql_fetch_field("WFactoryAmmoPart2c", TmpData, db_con2);
			WFactoryLegalLight[WFactoryAmmoPart2c] = strval(TmpData);
			mysql_fetch_field("WFactoryAmmoPart3c", TmpData, db_con2);
			WFactoryLegalLight[WFactoryAmmoPart3c] = strval(TmpData);
			mysql_fetch_field("WFactoryAmmoPart4c", TmpData, db_con2);
			WFactoryLegalLight[WFactoryAmmoPart4c] = strval(TmpData);
			mysql_fetch_field("WFactoryAmmoPart1d", TmpData, db_con2);
			WFactoryLegalLight[WFactoryAmmoPart1d] = strval(TmpData);
			mysql_fetch_field("WFactoryAmmoPart2d", TmpData, db_con2);
			WFactoryLegalLight[WFactoryAmmoPart2d] = strval(TmpData);
			mysql_fetch_field("WFactoryAmmoPart3d", TmpData, db_con2);
			WFactoryLegalLight[WFactoryAmmoPart3d] = strval(TmpData);
			mysql_fetch_field("WFactoryAmmoPart4d", TmpData, db_con2);
			WFactoryLegalLight[WFactoryAmmoPart4d] = strval(TmpData);
			mysql_fetch_field("WFactoryAmmoPart1e", TmpData, db_con2);
			WFactoryLegalLight[WFactoryAmmoPart1e] = strval(TmpData);
			mysql_fetch_field("WFactoryAmmoPart2e", TmpData, db_con2);
			WFactoryLegalLight[WFactoryAmmoPart2e] = strval(TmpData);
			mysql_fetch_field("WFactoryAmmoPart3e", TmpData, db_con2);
			WFactoryLegalLight[WFactoryAmmoPart3e] = strval(TmpData);
			mysql_fetch_field("WFactoryAmmoPart4e", TmpData, db_con2);
			WFactoryLegalLight[WFactoryAmmoPart4e] = strval(TmpData);
			mysql_fetch_field("WFactoryTec9Part", TmpData, db_con2);
			WFactoryLegalLight[WFactoryTec9Part] = strval(TmpData);
			mysql_fetch_field("WFactoryMP5Part", TmpData, db_con2);
			WFactoryLegalHeavy[WFactoryMP5Part] = strval(TmpData);
			mysql_fetch_field("WFactoryAK47Part", TmpData, db_con2);
			WFactoryLegalHeavy[WFactoryAK47Part] = strval(TmpData);
			mysql_fetch_field("WFactoryM4Part", TmpData, db_con2);
			WFactoryLegalHeavy[WFactoryM4Part] = strval(TmpData);
			mysql_fetch_field("WFactoryShotPart", TmpData, db_con2);
			WFactoryLegalHeavy[WFactoryShotPart] = strval(TmpData);
			mysql_fetch_field("WFactoryDesEaglePart", TmpData, db_con2);
			WFactoryLegalLight[WFactoryDesEaglePart] = strval(TmpData);
			mysql_fetch_field("WFactoryRiflePart", TmpData, db_con2);
			WFactoryLegalHeavy[WFactoryRiflePart] = strval(TmpData);
			mysql_fetch_field("WFactorySniperPart", TmpData, db_con2);
			WFactoryLegalHeavy[WFactorySniperPart] = strval(TmpData);
			
			mysql_free_result(db_con2);
			
			WFactoryLegal[WFactoryCPDocsID] = CreateDynamicCP( WFactoryLegal[WFactoryCPDocsX], WFactoryLegal[WFactoryCPDocsY], WFactoryLegal[WFactoryCPDocsZ], 1.0, -1, -1, -1, 5.0 );
			
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
			
			print("[SKRYPT:] Zaladowano legalna fabryke broni");
		}			
		case LOAD_GAS_STATIONS:
		{
			if( !mysql_store_result(db_con2) )
			{
				printf("[ERROR:] Can't store result on LOAD_GAS_STATIONS");
				GameModeExit();
				return 1;
			}
			new i = 0;

			while(mysql_fetch_row(db_result, "|", db_con2))
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
			print("[SKRYPT:] Zaladowano dane stacji paliwowych");
			
			mysql_free_result(db_con2);
		}
		case LOAD_FACTIONS_PAYRANK:
		{
			if( !mysql_store_result(db_con2) )
			{
				printf("[ERROR:] Can't store result on LOAD_FACTIONS_PAYRANK");
				GameModeExit();
				return 1;
			}
			new i = 0;

			while(mysql_fetch_row(db_result, "|", db_con2))
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
			print("[SKRYPT:] Zaladowano wysokosci wyplat");
			
			mysql_free_result(db_con2);
		}
		case COUNT_PAYDAY:
		{
			//print("COUNT_PAYDAY");
			if( !mysql_store_result(db_con2) )
			{
				printf("[ERROR:] Can't store result on COUNT_PAYDAY");
				return 1;
			}
			mysql_fetch_field("founder_count", fieldCount, db_con2);
			//printf("fieldCount: %d", strval(fieldCount));

			mysql_free_result(db_con2);
		}
		case UPDATE:
		{
			if( !mysql_store_result(db_con2) )
			{
				printf("[ERROR:] Can't store result on UPDATE");
				return 1;
			}
			new TmpData[256];
			mysql_fetch_field("Bank", TmpData, db_con2);
			gPlayerData[CUSTOM_MAX_PLAYERS][pBank] = strval(TmpData);
			mysql_fetch_field("PlayerName", gPlayerData[CUSTOM_MAX_PLAYERS][pName],db_con2);
			mysql_free_result(db_con2);
			// printf("[DEBUG:] case UPDATE, debug bank value to add: %d", spareid);
			format(TmpData, sizeof(TmpData), "UPDATE `samp_users` SET `Bank` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[CUSTOM_MAX_PLAYERS][pBank]+spareid, gPlayerData[CUSTOM_MAX_PLAYERS][pName]);
			mysql_query(TmpData, SAVE, playerid, db_con2);
			return 1;
		}
		case SAVE:
		{
			mysql_free_result(db_con2);
		}
		case SAVE2:
		{
			mysql_free_result(db_con3);
		}
		case SAVE3:
		{
			mysql_free_result(db_con4);
		}
		case LOAD_DYNAMIC_FACTIONS_WEAPONS2:
		{
			if(mysql_store_result(db_con2))
			{
				new fid;

				while(mysql_fetch_row(db_result, "|", db_con2))
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
				print("[SKRYPT:] Zaladowano bronie frakcji 2");
			}
			else
			{
				print("[SKRYPT:] Wystapil blad przy pobieraniu danych broni frakcji 2");
				GameModeExit();
			}
			mysql_free_result(db_con2);
			
			
		}
		case LOAD_DYNAMIC_FACTIONS_WEAPONS:
		{
			if(mysql_store_result(db_con2))
			{
				new fid;

				while(mysql_fetch_row(db_result, "|", db_con2))
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
				print("[SKRYPT:] Zaladowano bronie frakcji 1");
			}
			else
			{
				print("[SKRYPT:] Wystapil problem przy pobieraniu danych broni frakcji 1");
				GameModeExit();
			}
			mysql_free_result(db_con2);
		}
		case RELOAD_DYNAMIC_FACTIONS:
		{
			if(mysql_store_result(db_con2))
			{
				new i, TmpData[256];
				i = 0;

				while(mysql_fetch_row(db_result, "|", db_con2))
				{
					mysql_fetch_field("Name", DynamicFactions[i][Name], db_con2);
					mysql_fetch_field("Rank1", DynamicFactions[i][fRank1], db_con2);
					mysql_fetch_field("Rank2", DynamicFactions[i][fRank2], db_con2);
					mysql_fetch_field("Rank3", DynamicFactions[i][fRank3], db_con2);
					mysql_fetch_field("Rank4", DynamicFactions[i][fRank4], db_con2);
					mysql_fetch_field("Rank5", DynamicFactions[i][fRank5], db_con2);
					mysql_fetch_field("Rank6", DynamicFactions[i][fRank6], db_con2);
					mysql_fetch_field("Rank7", DynamicFactions[i][fRank7], db_con2);
					mysql_fetch_field("Rank8", DynamicFactions[i][fRank8], db_con2);
					mysql_fetch_field("Rank9", DynamicFactions[i][fRank9], db_con2);
					mysql_fetch_field("Rank10", DynamicFactions[i][fRank10], db_con2);
					mysql_fetch_field("Skin1", TmpData, db_con2);
					DynamicFactions[i][fSkin1] = strval(TmpData);
					mysql_fetch_field("Skin2", TmpData, db_con2);
					DynamicFactions[i][fSkin2] = strval(TmpData);
					mysql_fetch_field("Skin3", TmpData, db_con2);
					DynamicFactions[i][fSkin3] = strval(TmpData);
					mysql_fetch_field("Skin4", TmpData, db_con2);
					DynamicFactions[i][fSkin4] = strval(TmpData);
					mysql_fetch_field("Skin5", TmpData, db_con2);
					DynamicFactions[i][fSkin5] = strval(TmpData);
					mysql_fetch_field("Skin6", TmpData, db_con2);
					DynamicFactions[i][fSkin6] = strval(TmpData);
					mysql_fetch_field("Skin7", TmpData, db_con2);
					DynamicFactions[i][fSkin7] = strval(TmpData);
					mysql_fetch_field("Skin8", TmpData, db_con2);
					DynamicFactions[i][fSkin8] = strval(TmpData);
					mysql_fetch_field("Skin9", TmpData, db_con2);
					DynamicFactions[i][fSkin9] = strval(TmpData);
					mysql_fetch_field("Skin10", TmpData, db_con2);
					DynamicFactions[i][fSkin10] = strval(TmpData);
					mysql_fetch_field("JoinRank", TmpData, db_con2);
					DynamicFactions[i][fJoinRank] = strval(TmpData);
					mysql_fetch_field("UseSkins", TmpData, db_con2);
					DynamicFactions[i][fUseSkins] = strval(TmpData);
					mysql_fetch_field("RankAmount", TmpData, db_con2);
					DynamicFactions[i][fRankAmount] = strval(TmpData);				

					i++;
				}
				print("[SKRYPT:] Przeladowano frakcje");
			}
			else
			{
				print("[SKRYPT:] Wystapil problem przy przeladowywaniu danych frakcji");
			}			
			mysql_free_result(db_con2);
		}
		case LOAD_DYNAMIC_FACTIONS:
		{
			if(mysql_store_result(db_con2))
			{
				new i, Float:px, Float:py, Float:pz, TmpData[256];
				i = 0;
				while(mysql_fetch_row(db_result, "|", db_con2))
				{
					// split2(db_result, arrCoords, '|');
					// strmid(DynamicFactions[i][Name], arrCoords[1], 0, strlen(arrCoords[1]), 255);
					mysql_fetch_field("Name", DynamicFactions[i][Name], db_con2);
					mysql_fetch_field("IsEnabled", TmpData, db_con2);
					DynamicFactions[i][IsEnabled] = strval(TmpData);
					mysql_fetch_field("X", TmpData, db_con2);
					DynamicFactions[i][fX] = floatstr(TmpData);
					mysql_fetch_field("Y", TmpData, db_con2);
					DynamicFactions[i][fY] = floatstr(TmpData);
					mysql_fetch_field("Z", TmpData, db_con2);
					DynamicFactions[i][fZ] = floatstr(TmpData);
					mysql_fetch_field("Materials", TmpData, db_con2);
					DynamicFactions[i][fMaterials] = strval(TmpData);
					mysql_fetch_field("Drugs", TmpData, db_con2);
					DynamicFactions[i][fDrugs] = strval(TmpData);
					mysql_fetch_field("Bank", TmpData, db_con2);
					DynamicFactions[i][fBank] = strval(TmpData);
					mysql_fetch_field("Rank1", DynamicFactions[i][fRank1], db_con2);
					mysql_fetch_field("Rank2", DynamicFactions[i][fRank2], db_con2);
					mysql_fetch_field("Rank3", DynamicFactions[i][fRank3], db_con2);
					mysql_fetch_field("Rank4", DynamicFactions[i][fRank4], db_con2);
					mysql_fetch_field("Rank5", DynamicFactions[i][fRank5], db_con2);
					mysql_fetch_field("Rank6", DynamicFactions[i][fRank6], db_con2);
					mysql_fetch_field("Rank7", DynamicFactions[i][fRank7], db_con2);
					mysql_fetch_field("Rank8", DynamicFactions[i][fRank8], db_con2);
					mysql_fetch_field("Rank9", DynamicFactions[i][fRank9], db_con2);
					mysql_fetch_field("Rank10", DynamicFactions[i][fRank10], db_con2);
					mysql_fetch_field("Skin1", TmpData, db_con2);
					DynamicFactions[i][fSkin1] = strval(TmpData);
					mysql_fetch_field("Skin2", TmpData, db_con2);
					DynamicFactions[i][fSkin2] = strval(TmpData);
					mysql_fetch_field("Skin3", TmpData, db_con2);
					DynamicFactions[i][fSkin3] = strval(TmpData);
					mysql_fetch_field("Skin4", TmpData, db_con2);
					DynamicFactions[i][fSkin4] = strval(TmpData);
					mysql_fetch_field("Skin5", TmpData, db_con2);
					DynamicFactions[i][fSkin5] = strval(TmpData);
					mysql_fetch_field("Skin6", TmpData, db_con2);
					DynamicFactions[i][fSkin6] = strval(TmpData);
					mysql_fetch_field("Skin7", TmpData, db_con2);
					DynamicFactions[i][fSkin7] = strval(TmpData);
					mysql_fetch_field("Skin8", TmpData, db_con2);
					DynamicFactions[i][fSkin8] = strval(TmpData);
					mysql_fetch_field("Skin9", TmpData, db_con2);
					DynamicFactions[i][fSkin9] = strval(TmpData);
					mysql_fetch_field("Skin10", TmpData, db_con2);
					DynamicFactions[i][fSkin10] = strval(TmpData);
					mysql_fetch_field("JoinRank", TmpData, db_con2);
					DynamicFactions[i][fJoinRank] = strval(TmpData);
					mysql_fetch_field("UseSkins", TmpData, db_con2);
					DynamicFactions[i][fUseSkins] = strval(TmpData);
					mysql_fetch_field("Type", TmpData, db_con2);
					DynamicFactions[i][fType] = strval(TmpData);
					mysql_fetch_field("RankAmount", TmpData, db_con2);
					DynamicFactions[i][fRankAmount] = strval(TmpData);
					mysql_fetch_field("Color", DynamicFactions[i][fColor], db_con2);
					mysql_fetch_field("MaxCars", TmpData, db_con2);
					DynamicFactions[i][fMaxCars] = strval(TmpData);
					mysql_fetch_field("CarsCount", TmpData, db_con2);
					DynamicFactions[i][fCarsCount] = strval(TmpData);
					mysql_fetch_field("XDuty", TmpData, db_con2);
					DynamicFactions[i][fXDuty] = floatstr(TmpData);
					mysql_fetch_field("YDuty", TmpData, db_con2);
					DynamicFactions[i][fYDuty] = floatstr(TmpData);
					mysql_fetch_field("ZDuty", TmpData, db_con2);
					DynamicFactions[i][fZDuty] = floatstr(TmpData);
					mysql_fetch_field("WorldDuty", TmpData, db_con2);
					DynamicFactions[i][fWorldDuty] = strval(TmpData);
					mysql_fetch_field("InteriorDuty", TmpData, db_con2);
					DynamicFactions[i][fInteriorDuty] = strval(TmpData);
					mysql_fetch_field("XDuty2", TmpData, db_con2);
					DynamicFactions[i][fXDuty2] = floatstr(TmpData);
					mysql_fetch_field("YDuty2", TmpData, db_con2);
					DynamicFactions[i][fYDuty2] = floatstr(TmpData);
					mysql_fetch_field("ZDuty2", TmpData, db_con2);
					DynamicFactions[i][fZDuty2] = floatstr(TmpData);
					mysql_fetch_field("WorldDuty2", TmpData, db_con2);
					DynamicFactions[i][fWorldDuty] = strval(TmpData);
					mysql_fetch_field("InteriorDuty2", TmpData, db_con2);
					DynamicFactions[i][fInteriorDuty] = strval(TmpData);
					mysql_fetch_field("TaxiKMCost", TmpData, db_con2);
					DynamicFactions[i][fTaxiKMCost] = strval(TmpData);
					mysql_fetch_field("TaxiEnterCost", TmpData, db_con2);
					DynamicFactions[i][fTaxiEnterCost] = strval(TmpData);
					mysql_fetch_field("WFactoryBuildingID", TmpData, db_con2);
					DynamicFactions[i][WFactoryBuildingID] = strval(TmpData);
					mysql_fetch_field("WFactoryEnabled", TmpData, db_con2);
					DynamicFactions[i][WFactoryEnabled] = strval(TmpData);
					mysql_fetch_field("WFactoryBurning", TmpData, db_con2);
					DynamicFactions[i][WFactoryBurning] = strval(TmpData);
					mysql_fetch_field("WFactoryJustBought", TmpData, db_con2);
					DynamicFactions[i][WFactoryJustBought] = strval(TmpData);
					mysql_fetch_field("WFactoryCentrePosX", TmpData, db_con2);
					DynamicFactions[i][WFactoryCentrePosX] = floatstr(TmpData);
					mysql_fetch_field("WFactoryCentrePosY", TmpData, db_con2);
					DynamicFactions[i][WFactoryCentrePosY] = floatstr(TmpData);
					mysql_fetch_field("WFactoryCentrePosZ", TmpData, db_con2);
					DynamicFactions[i][WFactoryCentrePosZ] = floatstr(TmpData);
					mysql_fetch_field("WFactory9MM", TmpData, db_con2);
					DynamicFactions[i][WFactory9MM] = strval(TmpData);
					mysql_fetch_field("WFactory9MMSil", TmpData, db_con2);
					DynamicFactions[i][WFactory9MMSil] = strval(TmpData);
					mysql_fetch_field("WFactoryDesEagle", TmpData, db_con2);
					DynamicFactions[i][WFactoryDesEagle] = strval(TmpData);
					mysql_fetch_field("WFactoryMicroSMG", TmpData, db_con2);
					DynamicFactions[i][WFactoryMicroSMG] = strval(TmpData);
					mysql_fetch_field("WFactoryMP5", TmpData, db_con2);
					DynamicFactions[i][WFactoryMP5] = strval(TmpData);
					mysql_fetch_field("WFactoryTec9", TmpData, db_con2);
					DynamicFactions[i][WFactoryTec9] = strval(TmpData);
					mysql_fetch_field("WFactoryShotgun", TmpData, db_con2);
					DynamicFactions[i][WFactoryShotgun] = strval(TmpData);
					mysql_fetch_field("WFactoryAK47", TmpData, db_con2);
					DynamicFactions[i][WFactoryAK47] = strval(TmpData);
					mysql_fetch_field("WFactoryM4", TmpData, db_con2);
					DynamicFactions[i][WFactoryM4] = strval(TmpData);
					mysql_fetch_field("WFactoryRifle", TmpData, db_con2);
					DynamicFactions[i][WFactoryRifle] = strval(TmpData);
					mysql_fetch_field("WFactorySRifle", TmpData, db_con2);
					DynamicFactions[i][WFactorySRifle] = strval(TmpData);
					mysql_fetch_field("WFactorySCharge", TmpData, db_con2);
					DynamicFactions[i][WFactorySCharge] = strval(TmpData);
					mysql_fetch_field("WFactory9MMAmmo", TmpData, db_con2);
					DynamicFactions[i][WFactory9MMAmmo] = strval(TmpData);
					mysql_fetch_field("WFactory50AEAmmo", TmpData, db_con2);
					DynamicFactions[i][WFactory50AEAmmo] = strval(TmpData);
					mysql_fetch_field("WFactoryBuckshot", TmpData, db_con2);
					DynamicFactions[i][WFactoryBuckshot] = strval(TmpData);
					mysql_fetch_field("WFactory762MMAmmo", TmpData, db_con2);
					DynamicFactions[i][WFactory762MMAmmo] = strval(TmpData);
					mysql_fetch_field("WFactory127MMAmmo", TmpData, db_con2);
					DynamicFactions[i][WFactory127MMAmmo] = strval(TmpData);
					mysql_fetch_field("WFactoryKGP66MMAmmo", TmpData, db_con2);
					DynamicFactions[i][WFactoryKGP66MMAmmo] = strval(TmpData);
					mysql_fetch_field("WFactoryNapalm", TmpData, db_con2);
					DynamicFactions[i][WFactoryNapalm] = strval(TmpData);
					mysql_fetch_field("WFactoryPistolPart1", TmpData, db_con2);
					DynamicFactions[i][WFactoryPistolPart1] = strval(TmpData);
					mysql_fetch_field("WFactoryPistolS1Part1", TmpData, db_con2);
					DynamicFactions[i][WFactoryPistolS1Part1] = strval(TmpData);
					mysql_fetch_field("WFactoryPistolS1Part2", TmpData, db_con2);
					DynamicFactions[i][WFactoryPistolS1Part2] = strval(TmpData);
					mysql_fetch_field("WFactoryPistolS1Part3", TmpData, db_con2);
					DynamicFactions[i][WFactoryPistolS1Part3] = strval(TmpData);
					mysql_fetch_field("WFactoryPistolPart2", TmpData, db_con2);
					DynamicFactions[i][WFactoryPistolPart2] = strval(TmpData);
					mysql_fetch_field("WFactoryPistolS2Part1", TmpData, db_con2);
					DynamicFactions[i][WFactoryPistolS2Part1] = strval(TmpData);
					mysql_fetch_field("WFactoryPistolS2Part2", TmpData, db_con2);
					DynamicFactions[i][WFactoryPistolS2Part2] = strval(TmpData);
					mysql_fetch_field("WFactoryPistolS2Part3", TmpData, db_con2);
					DynamicFactions[i][WFactoryPistolS2Part3] = strval(TmpData);
					mysql_fetch_field("WFactoryPistolPart3", TmpData, db_con2);
					DynamicFactions[i][WFactoryPistolPart3] = strval(TmpData);
					mysql_fetch_field("WFactoryPistolS3Part1", TmpData, db_con2);
					DynamicFactions[i][WFactoryPistolS3Part1] = strval(TmpData);
					mysql_fetch_field("WFactoryPistolS3Part2", TmpData, db_con2);
					DynamicFactions[i][WFactoryPistolS3Part2] = strval(TmpData);
					mysql_fetch_field("WFactoryPistolS3Part3", TmpData, db_con2);
					DynamicFactions[i][WFactoryPistolS3Part3] = strval(TmpData);
					mysql_fetch_field("WFactoryPistolS3Part4", TmpData, db_con2);
					DynamicFactions[i][WFactoryPistolS3Part4] = strval(TmpData);
					mysql_fetch_field("WFactoryPistolPart4", TmpData, db_con2);
					DynamicFactions[i][WFactoryPistolPart4] = strval(TmpData);
					mysql_fetch_field("WFactoryPistolPart5", TmpData, db_con2);
					DynamicFactions[i][WFactoryPistolPart5] = strval(TmpData);
					mysql_fetch_field("WFactoryPistolPart6", TmpData, db_con2);
					DynamicFactions[i][WFactoryPistolPart6] = strval(TmpData);
					mysql_fetch_field("WFactoryRiflePart1", TmpData, db_con2);
					DynamicFactions[i][WFactoryRiflePart1] = strval(TmpData);
					mysql_fetch_field("WFactoryRifleS1Part1", TmpData, db_con2);
					DynamicFactions[i][WFactoryRifleS1Part1] = strval(TmpData);
					mysql_fetch_field("WFactoryRifleS1Part2", TmpData, db_con2);
					DynamicFactions[i][WFactoryRifleS1Part2] = strval(TmpData);
					mysql_fetch_field("WFactoryRiflePart2", TmpData, db_con2);
					DynamicFactions[i][WFactoryRiflePart2] = strval(TmpData);
					mysql_fetch_field("WFactoryRifleS2Part1", TmpData, db_con2);
					DynamicFactions[i][WFactoryRifleS2Part1] = strval(TmpData);
					mysql_fetch_field("WFactoryRifleS2Part2", TmpData, db_con2);
					DynamicFactions[i][WFactoryRifleS2Part2] = strval(TmpData);
					mysql_fetch_field("WFactoryRifleS2Part3", TmpData, db_con2);
					DynamicFactions[i][WFactoryRifleS2Part3] = strval(TmpData);
					mysql_fetch_field("WFactoryRiflePart3", TmpData, db_con2);
					DynamicFactions[i][WFactoryRiflePart3] = strval(TmpData);
					mysql_fetch_field("WFactoryRifleS3Part1", TmpData, db_con2);
					DynamicFactions[i][WFactoryRifleS3Part1] = strval(TmpData);
					mysql_fetch_field("WFactoryRifleS3Part2", TmpData, db_con2);
					DynamicFactions[i][WFactoryRifleS3Part2] = strval(TmpData);
					mysql_fetch_field("WFactoryRifleS3Part3", TmpData, db_con2);
					DynamicFactions[i][WFactoryRifleS3Part3] = strval(TmpData);
					mysql_fetch_field("WFactoryRifleS3Part4", TmpData, db_con2);
					DynamicFactions[i][WFactoryRifleS3Part4] = strval(TmpData);
					mysql_fetch_field("WFactoryRiflePart4", TmpData, db_con2);
					DynamicFactions[i][WFactoryRiflePart4] = strval(TmpData);
					mysql_fetch_field("WFactoryRiflePart5", TmpData, db_con2);
					DynamicFactions[i][WFactoryRiflePart5] = strval(TmpData);
					mysql_fetch_field("WFactoryRiflePart6", TmpData, db_con2);
					DynamicFactions[i][WFactoryRiflePart6] = strval(TmpData);
					mysql_fetch_field("WFactoryRiflePart7", TmpData, db_con2);
					DynamicFactions[i][WFactoryRiflePart7] = strval(TmpData);
					mysql_fetch_field("WFactoryRifleS6Part1", TmpData, db_con2);
					DynamicFactions[i][WFactoryRifleS6Part1] = strval(TmpData);
					mysql_fetch_field("WFactoryRifleS6Part2", TmpData, db_con2);
					DynamicFactions[i][WFactoryRifleS6Part2] = strval(TmpData);
					mysql_fetch_field("WFactoryAmmoPart1a", TmpData, db_con2);
					DynamicFactions[i][WFactoryAmmoPart1a] = strval(TmpData);
					mysql_fetch_field("WFactoryAmmoPart2a", TmpData, db_con2);
					DynamicFactions[i][WFactoryAmmoPart2a] = strval(TmpData);
					mysql_fetch_field("WFactoryAmmoPart3a", TmpData, db_con2);
					DynamicFactions[i][WFactoryAmmoPart3a] = strval(TmpData);
					mysql_fetch_field("WFactoryAmmoPart4a", TmpData, db_con2);
					DynamicFactions[i][WFactoryAmmoPart4a] = strval(TmpData);
					mysql_fetch_field("WFactoryAmmoPart1b", TmpData, db_con2);
					DynamicFactions[i][WFactoryAmmoPart1b] = strval(TmpData);
					mysql_fetch_field("WFactoryAmmoPart2b", TmpData, db_con2);
					DynamicFactions[i][WFactoryAmmoPart2b] = strval(TmpData);
					mysql_fetch_field("WFactoryAmmoPart3b", TmpData, db_con2);
					DynamicFactions[i][WFactoryAmmoPart3b] = strval(TmpData);
					mysql_fetch_field("WFactoryAmmoPart4b", TmpData, db_con2);
					DynamicFactions[i][WFactoryAmmoPart4b] = strval(TmpData);
					mysql_fetch_field("WFactoryAmmoPart1c", TmpData, db_con2);
					DynamicFactions[i][WFactoryAmmoPart1c] = strval(TmpData);
					mysql_fetch_field("WFactoryAmmoPart2c", TmpData, db_con2);
					DynamicFactions[i][WFactoryAmmoPart2c] = strval(TmpData);
					mysql_fetch_field("WFactoryAmmoPart3c", TmpData, db_con2);
					DynamicFactions[i][WFactoryAmmoPart3c] = strval(TmpData);
					mysql_fetch_field("WFactoryAmmoPart4c", TmpData, db_con2);
					DynamicFactions[i][WFactoryAmmoPart4c] = strval(TmpData);
					mysql_fetch_field("WFactoryAmmoPart1d", TmpData, db_con2);
					DynamicFactions[i][WFactoryAmmoPart1d] = strval(TmpData);
					mysql_fetch_field("WFactoryAmmoPart2d", TmpData, db_con2);
					DynamicFactions[i][WFactoryAmmoPart2d] = strval(TmpData);
					mysql_fetch_field("WFactoryAmmoPart3d", TmpData, db_con2);
					DynamicFactions[i][WFactoryAmmoPart3d] = strval(TmpData);
					mysql_fetch_field("WFactoryAmmoPart4d", TmpData, db_con2);
					DynamicFactions[i][WFactoryAmmoPart4d] = strval(TmpData);
					mysql_fetch_field("WFactoryAmmoPart1e", TmpData, db_con2);
					DynamicFactions[i][WFactoryAmmoPart1e] = strval(TmpData);
					mysql_fetch_field("WFactoryAmmoPart2e", TmpData, db_con2);
					DynamicFactions[i][WFactoryAmmoPart2e] = strval(TmpData);
					mysql_fetch_field("WFactoryAmmoPart3e", TmpData, db_con2);
					DynamicFactions[i][WFactoryAmmoPart3e] = strval(TmpData);
					mysql_fetch_field("WFactoryAmmoPart4e", TmpData, db_con2);
					DynamicFactions[i][WFactoryAmmoPart4e] = strval(TmpData);
					mysql_fetch_field("WFactoryTec9Part", TmpData, db_con2);
					DynamicFactions[i][WFactoryTec9Part] = strval(TmpData);
					mysql_fetch_field("WFactoryMP5Part", TmpData, db_con2);
					DynamicFactions[i][WFactoryMP5Part] = strval(TmpData);
					mysql_fetch_field("WFactoryAK47Part", TmpData, db_con2);
					DynamicFactions[i][WFactoryAK47Part] = strval(TmpData);
					mysql_fetch_field("WFactoryM4Part", TmpData, db_con2);
					DynamicFactions[i][WFactoryM4Part] = strval(TmpData);
					mysql_fetch_field("WFactoryShotPart", TmpData, db_con2);
					DynamicFactions[i][WFactoryShotPart] = strval(TmpData);
					mysql_fetch_field("WFactoryDesEaglePart", TmpData, db_con2);
					DynamicFactions[i][WFactoryDesEaglePart] = strval(TmpData);
					mysql_fetch_field("WFactoryRiflePart", TmpData, db_con2);
					DynamicFactions[i][WFactoryRiflePart] = strval(TmpData);
					mysql_fetch_field("WFactorySniperPart", TmpData, db_con2);
					DynamicFactions[i][WFactorySniperPart] = strval(TmpData);
					
					px = DynamicFactions[i][WFactoryCentrePosX];
					py = DynamicFactions[i][WFactoryCentrePosY];
					pz = DynamicFactions[i][WFactoryCentrePosZ];
					if( DynamicFactions[i][fXDuty] != 0.0 || DynamicFactions[i][fYDuty] != 0.0 )
						DynamicFactions[i][fCP] = CreateDynamicPickup(1239,0,DynamicFactions[i][fXDuty],DynamicFactions[i][fYDuty],DynamicFactions[i][fZDuty],DynamicFactions[i][fWorldDuty], DynamicFactions[i][fInteriorDuty], -1, 20.0);
					if( DynamicFactions[i][fXDuty2] != 0.0 || DynamicFactions[i][fYDuty2] != 0.0 )
						DynamicFactions[i][fCP2] = CreateDynamicPickup(1239,0,DynamicFactions[i][fXDuty2],DynamicFactions[i][fYDuty2],DynamicFactions[i][fZDuty2],DynamicFactions[i][fWorldDuty2], DynamicFactions[i][fInteriorDuty2], -1, 20.0);
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
						DynamicFactions[i][WFactoryCPPartSetup1ID] = CreateDynamicCP( px+WFCP[0][0], py+WFCP[0][1], pz+WFCP[0][2], 2.0 ); // Make weapon parts
						DynamicFactions[i][WFactoryCPPartSetup2ID] = CreateDynamicCP( px+WFCP[1][0], py+WFCP[1][1], pz+WFCP[1][2], 2.0 ); // Make weapon parts
						DynamicFactions[i][WFactoryCPAmmoPartSetup1ID] = CreateDynamicCP( px+WFCP[2][0], py+WFCP[2][1], pz+WFCP[2][2], 2.0 ); // Make weapon subparts
						DynamicFactions[i][WFactoryCPAmmoPartSetup2ID] = CreateDynamicCP( px+WFCP[4][0], py+WFCP[4][1], pz+WFCP[4][2], 2.0 ); // Make weapon subparts
						DynamicFactions[i][WFactoryCPPartTakeID] = CreateDynamicCP( px+WFCP[3][0], py+WFCP[3][1], pz+WFCP[3][2], 2.0 ); // Take/buy ammo/weapon (sub) parts
					}
					// printf("fCP ID: %d, X %f, Y %f, Z %f", DynamicFactions[i][fCP],DynamicFactions[i][fXDuty],DynamicFactions[i][fYDuty],DynamicFactions[i][fZDuty]);
					// printf("[FRAKCJE DYNAMICZNE:] Nazwa frakcji: %s, Typ: %d, ID: %d",DynamicFactions[i][Name],DynamicFactions[i][fType],i);

					i++;
				}
				print("[SKRYPT:] Zaladowano frakcje");
			}
			else
			{
				print("[SKRYPT:] Wystapil problem przy pobieraniu danych frakcji");
				GameModeExit();
			}
			mysql_free_result(db_con2);	
		}
		case LOAD_CARS_CPARTS:
		{
			if( !mysql_store_result(db_con2) )
			{
				printf("[ERROR:] Can't store result on LOAD_CARS_CPARTS");
				GameModeExit();
				return 1;
			}
			new i = 0;
			while(mysql_fetch_row(db_result, "|", db_con2))
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
					
					if( gVehData[i][CustomObj1Model] != 0 && gVehData[i][CustomObj1On] == 1 )
					{
						gVehData[i][CustomObj1ID] = CreateObject(
																					gVehData[i][CustomObj1Model],
																					0.0,
																					0.0,
																					-1000.0,
																					0.0,
																					0.0,
																					0.0);
						AttachObjectToVehicle(gVehData[i][CustomObj1ID], i+1, gVehData[i][CustomObj1][0], gVehData[i][CustomObj1][1], gVehData[i][CustomObj1][2], gVehData[i][CustomObj1][3], gVehData[i][CustomObj1][4], gVehData[i][CustomObj1][5]);															
					}
					if( gVehData[i][CustomObj2Model] != 0  && gVehData[i][CustomObj2On] == 1 )
					{
						gVehData[i][CustomObj2ID] = CreateObject(
																					gVehData[i][CustomObj2Model],
																					0.0,
																					0.0,
																					-1000.0,
																					0.0,
																					0.0,
																					0.0);
						AttachObjectToVehicle(gVehData[i][CustomObj2ID], i+1, gVehData[i][CustomObj2][0], gVehData[i][CustomObj2][1], gVehData[i][CustomObj2][2], gVehData[i][CustomObj2][3], gVehData[i][CustomObj2][4], gVehData[i][CustomObj2][5]);																		
					}
					if( gVehData[i][CustomObj3Model] != 0 && gVehData[i][CustomObj3On] == 1  )
					{
						gVehData[i][CustomObj3ID] = CreateObject(
																					gVehData[i][CustomObj3Model],
																					0.0,
																					0.0,
																					-1000.0,
																					0.0,
																					0.0,
																					0.0);			
						AttachObjectToVehicle(gVehData[i][CustomObj3ID], i+1, gVehData[i][CustomObj3][0], gVehData[i][CustomObj3][1], gVehData[i][CustomObj3][2], gVehData[i][CustomObj3][3], gVehData[i][CustomObj3][4], gVehData[i][CustomObj3][5]);			
					}
					i++;
				}
			}
			print("[SKRYPT:] Zaladowano niestandartowe czesci pojazdow dynamicznych");
			
			mysql_free_result(db_con2);
		}
		case LOAD_DYNAMIC_CARS:
		{
			if( !mysql_store_result(db_con2) )
			{
				printf("[ERROR:] Can't store result on LOAD_DYNAMIC_CARS");
				GameModeExit();
				return 1;
			}

			new i, id, lightsd;
			i = 0;
			
			new enginedyn,lights,alarm,doors,bonnet,boot,objective;

			while(mysql_fetch_row(db_result, "|", db_con2))
			{
				new TmpData[256];
				
				mysql_fetch_field("CarModel", TmpData, db_con2);
				gVehData[i][CarModel] = strval(TmpData);				
				mysql_fetch_field("CarX", TmpData, db_con2);
				gVehData[i][CarX] = floatstr(TmpData);				
				mysql_fetch_field("CarY", TmpData, db_con2);
				gVehData[i][CarY] = floatstr(TmpData);
				mysql_fetch_field("CarZ", TmpData, db_con2);
				gVehData[i][CarZ] = floatstr(TmpData);
				mysql_fetch_field("CarAngle", TmpData, db_con2);
				gVehData[i][CarAngle] = floatstr(TmpData);
				mysql_fetch_field("CarInterior", TmpData, db_con2);
				gVehData[i][CarInterior] = strval(TmpData);
				mysql_fetch_field("CarVW", TmpData, db_con2);
				gVehData[i][CarVW] = strval(TmpData);
				mysql_fetch_field("CarColor1", TmpData, db_con2);
				gVehData[i][CarColor1] = strval(TmpData);
				mysql_fetch_field("CarColor2", TmpData, db_con2);
				gVehData[i][CarColor2] = strval(TmpData);
				mysql_fetch_field("FactionCar", TmpData, db_con2);
				gVehData[i][FactionCar] = strval(TmpData);
				mysql_fetch_field("CarType", TmpData, db_con2);
				gVehData[i][CarType] = strval(TmpData);
				mysql_fetch_field("Owned", TmpData, db_con2);
				gVehData[i][Owned] = strval(TmpData);
				mysql_fetch_field("Owner", gVehData[i][Owner], db_con2);
				mysql_fetch_field("Price", TmpData, db_con2);
				gVehData[i][Price] = strval(TmpData);
				mysql_fetch_field("Closed", TmpData, db_con2);
				gVehData[i][Closed] = strval(TmpData);
				mysql_fetch_field("CarResetT", TmpData, db_con2);
				gVehData[i][CarResetT] = strval(TmpData);
				mysql_fetch_field("CarDamaged", TmpData, db_con2);
				gVehData[i][CarDamaged] = strval(TmpData);
				mysql_fetch_field("CarRepairTimeLeft", TmpData, db_con2);
				gVehData[i][CarRepairTimeLeft] = strval(TmpData);
				mysql_fetch_field("BusinessID", TmpData, db_con2);
				gVehData[i][BusinessID] = strval(TmpData);
				mysql_fetch_field("CarFuel", TmpData, db_con2);
				gVehData[i][CarFuel] = strval(TmpData);
				mysql_fetch_field("CarHealth", TmpData, db_con2);
				gVehData[i][CarHealth] = floatstr(TmpData);
				mysql_fetch_field("ReadyToSell", TmpData, db_con2);
				gVehData[i][ReadyToSell] = strval(TmpData);
				mysql_fetch_field("CarCounter", TmpData, db_con2);
				gVehData[i][CarCounter] = strval(TmpData);
				mysql_fetch_field("Fuel", TmpData, db_con2);
				gVehData[i][Fuel] = strval(TmpData);
				mysql_fetch_field("CarPanels", TmpData, db_con2);
				gVehData[i][CarPanels] = strval(TmpData);
				mysql_fetch_field("CarDoors", TmpData, db_con2);
				gVehData[i][CarDoors] = strval(TmpData);
				mysql_fetch_field("CarLights", TmpData, db_con2);
				gVehData[i][CarLights] = strval(TmpData);
				mysql_fetch_field("CarTires", TmpData, db_con2);
				gVehData[i][CarTires] = strval(TmpData);
				mysql_fetch_field("LastDriverWKey", TmpData, db_con2);
				gVehData[i][LastDriverWKey] = strlen(TmpData);
				mysql_fetch_field("CarSerial", TmpData, db_con2);
				gVehData[i][CarSerial] = strval(TmpData);
				mysql_fetch_field("PaintStep", TmpData, db_con2);
				gVehData[i][PaintStep] = strval(TmpData);
				mysql_fetch_field("WheelStep", TmpData, db_con2);
				gVehData[i][WheelStep] = strval(TmpData);
				mysql_fetch_field("EngineOn", TmpData, db_con2);
				gVehData[i][EngineOn] = strval(TmpData);
				mysql_fetch_field("LightsOn", TmpData, db_con2);
				gVehData[i][LightsOn] = strval(TmpData);
				mysql_fetch_field("BonnetUp", TmpData, db_con2);
				gVehData[i][BonnetUp] = strval(TmpData);
				mysql_fetch_field("BootUp", TmpData, db_con2);
				gVehData[i][BootUp] = strval(TmpData); 
				mysql_fetch_field("RadioOn", TmpData, db_con2);
				gVehData[i][RadioOn] = strval(TmpData);
				mysql_fetch_field("Hook", TmpData, db_con2);
				gVehData[i][Hook] = strval(TmpData);
				mysql_fetch_field("Alarm", TmpData, db_con2);
				gVehData[i][Alarm] = strval(TmpData);
				mysql_fetch_field("GasStep", TmpData, db_con2);
				gVehData[i][GasStep] = strval(TmpData);
				mysql_fetch_field("TankerResourceType", TmpData, db_con2);
				gVehData[i][TankerResourceType] = strval(TmpData);
				mysql_fetch_field("TankerResourceValue", TmpData, db_con2);
				gVehData[i][TankerResourceValue] = strval(TmpData);
				mysql_fetch_field("EngineTemp", TmpData, db_con2);
				gVehData[i][EngineTemp] = strval(TmpData);
				mysql_fetch_field("RadioVol", TmpData, db_con2);
				gVehData[i][RadioVol] = strval(TmpData);
				mysql_fetch_field("BatteryCapacity", TmpData, db_con2);	
				gVehData[i][BatteryCapacity] = floatstr(TmpData);
				mysql_fetch_field("BatteryMaxCapacity", TmpData, db_con2);
				gVehData[i][BatteryMaxCapacity] = floatstr(TmpData);
				mysql_fetch_field("Confiscated", TmpData, db_con2);
				gVehData[i][VConfiscated] = strval(TmpData);
				mysql_fetch_field("Item1", TmpData, db_con2);
				gVehData[i][VItem1] = strval(TmpData);
				mysql_fetch_field("Item2", TmpData, db_con2);
				gVehData[i][VItem2] = strval(TmpData);
				mysql_fetch_field("Item3", TmpData, db_con2);
				gVehData[i][VItem3] = strval(TmpData);
				mysql_fetch_field("Item4", TmpData, db_con2);
				gVehData[i][VItem4] = strval(TmpData);
				mysql_fetch_field("Item5", TmpData, db_con2);
				gVehData[i][VItem5] = strval(TmpData);
				mysql_fetch_field("Item6", TmpData, db_con2);
				gVehData[i][VItem6] = strval(TmpData);
				mysql_fetch_field("Item7", TmpData, db_con2);
				gVehData[i][VItem7] = strval(TmpData);
				mysql_fetch_field("Item8", TmpData, db_con2);
				gVehData[i][VItem8] = strval(TmpData);
				mysql_fetch_field("Item9", TmpData, db_con2);
				gVehData[i][VItem9] = strval(TmpData);
				mysql_fetch_field("Item10", TmpData, db_con2);
				gVehData[i][VItem10] = strval(TmpData);
				mysql_fetch_field("Item11", TmpData, db_con2);
				gVehData[i][VItem11] = strval(TmpData);
				mysql_fetch_field("Item12", TmpData, db_con2);
				gVehData[i][VItem12] = strval(TmpData);
				mysql_fetch_field("Item13", TmpData, db_con2);
				gVehData[i][VItem13] = strval(TmpData);
				mysql_fetch_field("Item14", TmpData, db_con2);
				gVehData[i][VItem14] = strval(TmpData);
				mysql_fetch_field("Item15", TmpData, db_con2);
				gVehData[i][VItem15] = strval(TmpData);
				mysql_fetch_field("Item1type", TmpData, db_con2);
				gVehData[i][VItem1type] = strval(TmpData);
				mysql_fetch_field("Item2type", TmpData, db_con2);
				gVehData[i][VItem2type] = strval(TmpData);
				mysql_fetch_field("Item3type", TmpData, db_con2);
				gVehData[i][VItem3type] = strval(TmpData);
				mysql_fetch_field("Item4type", TmpData, db_con2);
				gVehData[i][VItem4type] = strval(TmpData);
				mysql_fetch_field("Item5type", TmpData, db_con2);
				gVehData[i][VItem5type] = strval(TmpData);
				mysql_fetch_field("Item6type", TmpData, db_con2);
				gVehData[i][VItem6type] = strval(TmpData);
				mysql_fetch_field("Item7type", TmpData, db_con2);
				gVehData[i][VItem7type] = strval(TmpData);
				mysql_fetch_field("Item8type", TmpData, db_con2);
				gVehData[i][VItem8type] = strval(TmpData);
				mysql_fetch_field("Item9type", TmpData, db_con2);
				gVehData[i][VItem9type] = strval(TmpData);
				mysql_fetch_field("Item10type", TmpData, db_con2);
				gVehData[i][VItem10type] = strval(TmpData);
				mysql_fetch_field("Item11type", TmpData, db_con2);
				gVehData[i][VItem11type] = strval(TmpData);
				mysql_fetch_field("Item12type", TmpData, db_con2);
				gVehData[i][VItem12type] = strval(TmpData);
				mysql_fetch_field("Item13type", TmpData, db_con2);
				gVehData[i][VItem13type] = strval(TmpData);
				mysql_fetch_field("Item14type", TmpData, db_con2);
				gVehData[i][VItem14type] = strval(TmpData);
				mysql_fetch_field("Item15type", TmpData, db_con2);
				gVehData[i][VItem15type] = strval(TmpData);
				mysql_fetch_field("Item1param", TmpData, db_con2);
				gVehData[i][VItem1param] = strval(TmpData);
				mysql_fetch_field("Item2param", TmpData, db_con2);
				gVehData[i][VItem2param] = strval(TmpData);
				mysql_fetch_field("Item3param", TmpData, db_con2);
				gVehData[i][VItem3param] = strval(TmpData);
				mysql_fetch_field("Item4param", TmpData, db_con2);
				gVehData[i][VItem4param] = strval(TmpData);
				mysql_fetch_field("Item5param", TmpData, db_con2);
				gVehData[i][VItem5param] = strval(TmpData);
				mysql_fetch_field("Item6param", TmpData, db_con2);
				gVehData[i][VItem6param] = strval(TmpData);
				mysql_fetch_field("Item7param", TmpData, db_con2);
				gVehData[i][VItem7param] = strval(TmpData);
				mysql_fetch_field("Item8param", TmpData, db_con2);
				gVehData[i][VItem8param] = strval(TmpData);
				mysql_fetch_field("Item9param", TmpData, db_con2);
				gVehData[i][VItem9param] = strval(TmpData);
				mysql_fetch_field("Item10param", TmpData, db_con2);
				gVehData[i][VItem10param] = strval(TmpData);
				mysql_fetch_field("Item11param", TmpData, db_con2);
				gVehData[i][VItem11param] = strval(TmpData);
				mysql_fetch_field("Item12param", TmpData, db_con2);
				gVehData[i][VItem12param] = strval(TmpData);
				mysql_fetch_field("Item13param", TmpData, db_con2);
				gVehData[i][VItem13param] = strval(TmpData);
				mysql_fetch_field("Item14param", TmpData, db_con2);
				gVehData[i][VItem14param] = strval(TmpData);
				mysql_fetch_field("Item15param", TmpData, db_con2);
				gVehData[i][VItem15param] = strval(TmpData);
				mysql_fetch_field("Item1param2", TmpData, db_con2);
				gVehData[i][VItem1param2] = strval(TmpData);
				mysql_fetch_field("Item2param2", TmpData, db_con2);
				gVehData[i][VItem2param2] = strval(TmpData);
				mysql_fetch_field("Item3param2", TmpData, db_con2);
				gVehData[i][VItem3param2] = strval(TmpData);
				mysql_fetch_field("Item4param2", TmpData, db_con2);
				gVehData[i][VItem4param2] = strval(TmpData);
				mysql_fetch_field("Item5param2", TmpData, db_con2);
				gVehData[i][VItem5param2] = strval(TmpData);
				mysql_fetch_field("Item6param2", TmpData, db_con2);
				gVehData[i][VItem6param2] = strval(TmpData);
				mysql_fetch_field("Item7param2", TmpData, db_con2);
				gVehData[i][VItem7param2] = strval(TmpData);
				mysql_fetch_field("Item8param2", TmpData, db_con2);
				gVehData[i][VItem8param2] = strval(TmpData);
				mysql_fetch_field("Item9param2", TmpData, db_con2);
				gVehData[i][VItem9param2] = strval(TmpData);
				mysql_fetch_field("Item10param2", TmpData, db_con2);
				gVehData[i][VItem10param2] = strval(TmpData);
				mysql_fetch_field("Item11param2", TmpData, db_con2);
				gVehData[i][VItem11param2] = strval(TmpData);
				mysql_fetch_field("Item12param2", TmpData, db_con2);
				gVehData[i][VItem12param2] = strval(TmpData);
				mysql_fetch_field("Item13param2", TmpData, db_con2);
				gVehData[i][VItem13param2] = strval(TmpData);
				mysql_fetch_field("Item14param2", TmpData, db_con2);
				gVehData[i][VItem14param2] = strval(TmpData);
				mysql_fetch_field("Item15param2", TmpData, db_con2);
				gVehData[i][VItem15param2] = strval(TmpData);
				mysql_fetch_field("Item1param3", TmpData, db_con2);
				gVehData[i][VItem1param3] = strval(TmpData);
				mysql_fetch_field("Item2param3", TmpData, db_con2);
				gVehData[i][VItem2param3] = strval(TmpData);
				mysql_fetch_field("Item3param3", TmpData, db_con2);
				gVehData[i][VItem3param3] = strval(TmpData);
				mysql_fetch_field("Item4param3", TmpData, db_con2);
				gVehData[i][VItem4param3] = strval(TmpData);
				mysql_fetch_field("Item5param3", TmpData, db_con2);
				gVehData[i][VItem5param3] = strval(TmpData);
				mysql_fetch_field("Item6param3", TmpData, db_con2);
				gVehData[i][VItem6param3] = strval(TmpData);
				mysql_fetch_field("Item7param3", TmpData, db_con2);
				gVehData[i][VItem7param3] = strval(TmpData);
				mysql_fetch_field("Item8param3", TmpData, db_con2);
				gVehData[i][VItem8param3] = strval(TmpData);
				mysql_fetch_field("Item9param3", TmpData, db_con2);
				gVehData[i][VItem9param3] = strval(TmpData);
				mysql_fetch_field("Item10param3", TmpData, db_con2);
				gVehData[i][VItem10param3] = strval(TmpData);
				mysql_fetch_field("Item11param3", TmpData, db_con2);
				gVehData[i][VItem11param3] = strval(TmpData);
				mysql_fetch_field("Item12param3", TmpData, db_con2);
				gVehData[i][VItem12param3] = strval(TmpData);
				mysql_fetch_field("Item13param3", TmpData, db_con2);
				gVehData[i][VItem13param3] = strval(TmpData);
				mysql_fetch_field("Item14param3", TmpData, db_con2);
				gVehData[i][VItem14param3] = strval(TmpData);
				mysql_fetch_field("Item15param3", TmpData, db_con2);
				gVehData[i][VItem15param3] = strval(TmpData);
				mysql_fetch_field("Item1param4", TmpData, db_con2);
				gVehData[i][VItem1param4] = strval(TmpData);
				mysql_fetch_field("Item2param4", TmpData, db_con2);
				gVehData[i][VItem2param4] = strval(TmpData);
				mysql_fetch_field("Item3param4", TmpData, db_con2);
				gVehData[i][VItem3param4] = strval(TmpData);
				mysql_fetch_field("Item4param4", TmpData, db_con2);
				gVehData[i][VItem4param4] = strval(TmpData);
				mysql_fetch_field("Item5param4", TmpData, db_con2);
				gVehData[i][VItem5param4] = strval(TmpData);
				mysql_fetch_field("Item6param4", TmpData, db_con2);
				gVehData[i][VItem6param4] = strval(TmpData);
				mysql_fetch_field("Item7param4", TmpData, db_con2);
				gVehData[i][VItem7param4] = strval(TmpData);
				mysql_fetch_field("Item8param4", TmpData, db_con2);
				gVehData[i][VItem8param4] = strval(TmpData);
				mysql_fetch_field("Item9param4", TmpData, db_con2);
				gVehData[i][VItem9param4] = strval(TmpData);
				mysql_fetch_field("Item10param4", TmpData, db_con2);
				gVehData[i][VItem10param4] = strval(TmpData);
				mysql_fetch_field("Item11param4", TmpData, db_con2);
				gVehData[i][VItem11param4] = strval(TmpData);
				mysql_fetch_field("Item12param4", TmpData, db_con2);
				gVehData[i][VItem12param4] = strval(TmpData);
				mysql_fetch_field("Item13param4", TmpData, db_con2);
				gVehData[i][VItem13param4] = strval(TmpData);
				mysql_fetch_field("Item14param4", TmpData, db_con2);
				gVehData[i][VItem14param4] = strval(TmpData);
				mysql_fetch_field("Item15param4", TmpData, db_con2);
				gVehData[i][VItem15param4] = strval(TmpData);
				mysql_fetch_field("Item1param5", gVehData[i][VItem1param5], db_con2);
				mysql_fetch_field("Item2param5", gVehData[i][VItem2param5], db_con2);
				mysql_fetch_field("Item3param5", gVehData[i][VItem3param5], db_con2);
				mysql_fetch_field("Item4param5", gVehData[i][VItem4param5], db_con2);
				mysql_fetch_field("Item5param5", gVehData[i][VItem5param5], db_con2);
				mysql_fetch_field("Item6param5", gVehData[i][VItem6param5], db_con2);
				mysql_fetch_field("Item7param5", gVehData[i][VItem7param5], db_con2);
				mysql_fetch_field("Item8param5", gVehData[i][VItem8param5], db_con2);
				mysql_fetch_field("Item9param5", gVehData[i][VItem9param5], db_con2);
				mysql_fetch_field("Item10param5", gVehData[i][VItem10param5], db_con2);
				mysql_fetch_field("Item11param5", gVehData[i][VItem11param5], db_con2);
				mysql_fetch_field("Item12param5", gVehData[i][VItem12param5], db_con2);
				mysql_fetch_field("Item13param5", gVehData[i][VItem13param5], db_con2);
				mysql_fetch_field("Item14param5", gVehData[i][VItem14param5], db_con2);
				mysql_fetch_field("Item15param5", gVehData[i][VItem15param5], db_con2);
				mysql_fetch_field("Item1param6", TmpData, db_con2);
				gVehData[i][VItem1param6] = strval(TmpData);
				mysql_fetch_field("Item2param6", TmpData, db_con2);
				gVehData[i][VItem2param6] = strval(TmpData);
				mysql_fetch_field("Item3param6", TmpData, db_con2);
				gVehData[i][VItem3param6] = strval(TmpData);
				mysql_fetch_field("Item4param6", TmpData, db_con2);
				gVehData[i][VItem4param6] = strval(TmpData);
				mysql_fetch_field("Item5param6", TmpData, db_con2);
				gVehData[i][VItem5param6] = strval(TmpData);
				mysql_fetch_field("Item6param6", TmpData, db_con2);
				gVehData[i][VItem6param6] = strval(TmpData);
				mysql_fetch_field("Item7param6", TmpData, db_con2);
				gVehData[i][VItem7param6] = strval(TmpData);
				mysql_fetch_field("Item8param6", TmpData, db_con2);
				gVehData[i][VItem8param6] = strval(TmpData);
				mysql_fetch_field("Item9param6", TmpData, db_con2);
				gVehData[i][VItem9param6] = strval(TmpData);
				mysql_fetch_field("Item10param6", TmpData, db_con2);
				gVehData[i][VItem10param6] = strval(TmpData);
				mysql_fetch_field("Item11param6", TmpData, db_con2);
				gVehData[i][VItem11param6] = strval(TmpData);
				mysql_fetch_field("Item12param6", TmpData, db_con2);
				gVehData[i][VItem12param6] = strval(TmpData);
				mysql_fetch_field("Item13param6", TmpData, db_con2);
				gVehData[i][VItem13param6] = strval(TmpData);
				mysql_fetch_field("Item14param6", TmpData, db_con2);
				gVehData[i][VItem14param6] = strval(TmpData);
				mysql_fetch_field("Item15param6", TmpData, db_con2);
				gVehData[i][VItem15param6] = strval(TmpData);
				

				id = CreateVehicle(gVehData[i][CarModel],gVehData[i][CarX],gVehData[i][CarY],gVehData[i][CarZ],gVehData[i][CarAngle],gVehData[i][CarColor1],gVehData[i][CarColor2], -1);
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
				LinkVehicleToInterior(id, gVehData[i][CarInterior]);
				SetVehicleVirtualWorld(id, gVehData[i][CarVW]);				
				GetVehicleParamsEx(id,enginedyn,lights,alarm,doors,bonnet,boot,objective);
				SetVehicleParamsEx(id,gVehData[i][EngineOn],gVehData[i][LightsOn],0,gVehData[i][Closed],gVehData[i][BonnetUp],gVehData[i][BootUp],objective);
				SetVehicleHealth(id, gVehData[i][CarHealth]);
				
				if(gVehData[i][CarSerial] < 10 && gVehData[i][CarSerial] > 0)
					format(string, sizeof(string), "SF-000%d", gVehData[i][CarSerial]);
				if(gVehData[i][CarSerial] > 10 && gVehData[i][CarSerial] < 100)
					format(string, sizeof(string), "SF-00%d", gVehData[i][CarSerial]);
				if(gVehData[i][CarSerial] > 100 && gVehData[i][CarSerial] < 1000)
					format(string, sizeof(string), "SF-0%d", gVehData[i][CarSerial]);
				if(gVehData[i][CarSerial] > 1000)
					format(string, sizeof(string), "SF-%d", gVehData[i][CarSerial]);
				
				if(gVehData[i][CarModel] == 431)
				{
					BusRoute[i] = CreateDynamic3DTextLabel(" ", COLOR_LIGHTYELLOW, 0.8, 5.8, 1, 10.0, INVALID_PLAYER_ID, i+1, 1);
				}
				
				gVehData[i][RadioVol] = 100;
				
				if(gVehData[i][CarSerial] > 0)
				{
					if(IsAMotorBike(id) && gVehData[i][CarModel] != 522 && gVehData[i][CarModel] != 471 && gVehData[i][CarModel] != 468)
					{
						SetVehicleNumberPlate(id, string);
						// veh3dserial[i] = CreateDynamic3DTextLabel(string, COLOR_WHITE, 0.0, -1.0, 0.3, 20.0, INVALID_PLAYER_ID, id, 0);
					}
					else if(gVehData[i][CarModel] == 522 || gVehData[i][CarModel] == 471 || gVehData[i][CarModel] == 468)
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
					gVehData[i][Veh3DSell] = CreateDynamic3DTextLabel("Sprzedam !", COLOR_LIGHTBLUE, 0.0, 0.0, 0.6, 20.0, INVALID_PLAYER_ID, id, 1);
				if(gVehData[i][FactionCar] != 255)
				{
					if(DynamicFactions[ gVehData[i][FactionCar] ][fType] == 6)
					{
						gVehData[i][Veh3DTaxiNfo] = CreateDynamic3DTextLabel("TAXI", COLOR_YELLOW, 0.0, 0.0, 1.0, 20.0, INVALID_PLAYER_ID, id, 1);
						if( DynamicFactions[ gVehData[i][FactionCar] ][fTaxiEnterCost] > 0 )
							format( string, sizeof(string), "cena za KM: %d$ + %d$", DynamicFactions[ gVehData[i][FactionCar] ][fTaxiKMCost], DynamicFactions[ gVehData[i][FactionCar] ][fTaxiEnterCost] );
						else
							format( string, sizeof(string), "cena za KM: %d$", DynamicFactions[ gVehData[i][FactionCar] ][fTaxiKMCost] );
						gVehData[i][Veh3DTaxiNfo2] = CreateDynamic3DTextLabel(string, COLOR_YELLOW, 0.0, 0.0, 0.8, 20.0, INVALID_PLAYER_ID, id, 1);
					}
				}
				i++;
				// }
				// else
				// {
					// format(string, sizeof(string), "INSERT INTO `samp_vehicles` (`ID`) VALUES ('%d')", i+1);
					// mysql_query(string);

					// gVehData[i][CarModel] = 594;
					// gVehData[i][CarX] = 0.0;
					// gVehData[i][CarY] = 0.0;
					// gVehData[i][CarZ] = 0.0;
					// gVehData[i][CarAngle] = 0.0;
					// gVehData[i][CarColor1] = -1;
					// gVehData[i][CarColor2] = -1;
					// gVehData[i][FactionCar] = 255;
					// gVehData[i][CarType] = 0;
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

					// CreateVehicle(gVehData[i][CarModel],gVehData[i][CarX],gVehData[i][CarY],gVehData[i][CarZ],gVehData[i][CarAngle],gVehData[i][CarColor1],gVehData[i][CarColor2], -1);

					// i++;
				// }
			}

			print("[SKRYPT:] Zaladowano pojazdy dynamiczne");
			
			mysql_free_result(db_con2);
		}
		case LOAD_ITEM_FACTORIES:
		{
			if(!mysql_store_result(db_con2))
			{
				printf("[ERROR:] Can't store result on LOAD_ITEM_FACTORIES");
				GameModeExit();
				return 1;
			}
			new i = 0;
			new TmpData[256];
			while(mysql_fetch_row(db_result, "|", db_con2))
			{
				mysql_fetch_field("name", gItemFactories[i][fName], db_con2);
				mysql_fetch_field("posX", TmpData, db_con2);
				gItemFactories[i][fPosX] = floatstr(TmpData);
				mysql_fetch_field("posY", TmpData, db_con2);
				gItemFactories[i][fPosY] = floatstr(TmpData);
				mysql_fetch_field("posZ", TmpData, db_con2);
				gItemFactories[i][fPosZ] = floatstr(TmpData);
				mysql_fetch_field("item1", TmpData, db_con2);
				gItemFactories[i][item1] = strval(TmpData);
				mysql_fetch_field("item1type", TmpData, db_con2);
				gItemFactories[i][item1type] = strval(TmpData);
				mysql_fetch_field("item1count", TmpData, db_con2);
				gItemFactories[i][item1count] = strval(TmpData);
				mysql_fetch_field("item1minBuy", TmpData, db_con2);
				gItemFactories[i][item1minBuy] = strval(TmpData);
				mysql_fetch_field("item1reproduceCount", TmpData, db_con2);
				gItemFactories[i][item1reproduceCount] = strval(TmpData);
				mysql_fetch_field("item1price", TmpData, db_con2);
				gItemFactories[i][item1price] = strval(TmpData);
				mysql_fetch_field("item2", TmpData, db_con2);
				gItemFactories[i][item2] = strval(TmpData);
				mysql_fetch_field("item2type", TmpData, db_con2);
				gItemFactories[i][item2type] = strval(TmpData);
				mysql_fetch_field("item2count", TmpData, db_con2);
				gItemFactories[i][item2count] = strval(TmpData);
				mysql_fetch_field("item2minBuy", TmpData, db_con2);
				gItemFactories[i][item2minBuy] = strval(TmpData);
				mysql_fetch_field("item2reproduceCount", TmpData, db_con2);
				gItemFactories[i][item2reproduceCount] = strval(TmpData);
				mysql_fetch_field("item2price", TmpData, db_con2);
				gItemFactories[i][item2price] = strval(TmpData);
				mysql_fetch_field("item3", TmpData, db_con2);
				gItemFactories[i][item3] = strval(TmpData);
				mysql_fetch_field("item3type", TmpData, db_con2);
				gItemFactories[i][item3type] = strval(TmpData);
				mysql_fetch_field("item3count", TmpData, db_con2);
				gItemFactories[i][item3count] = strval(TmpData);
				mysql_fetch_field("item3minBuy", TmpData, db_con2);
				gItemFactories[i][item3minBuy] = strval(TmpData);
				mysql_fetch_field("item3reproduceCount", TmpData, db_con2);
				gItemFactories[i][item3reproduceCount] = strval(TmpData);
				mysql_fetch_field("item3price", TmpData, db_con2);
				gItemFactories[i][item3price] = strval(TmpData);
				mysql_fetch_field("item4", TmpData, db_con2);
				gItemFactories[i][item4] = strval(TmpData);
				mysql_fetch_field("item4type", TmpData, db_con2);
				gItemFactories[i][item4type] = strval(TmpData);
				mysql_fetch_field("item4count", TmpData, db_con2);
				gItemFactories[i][item4count] = strval(TmpData);
				mysql_fetch_field("item4minBuy", TmpData, db_con2);
				gItemFactories[i][item4minBuy] = strval(TmpData);
				mysql_fetch_field("item4reproduceCount", TmpData, db_con2);
				gItemFactories[i][item4reproduceCount] = strval(TmpData);
				mysql_fetch_field("item4price", TmpData, db_con2);
				gItemFactories[i][item4price] = strval(TmpData);
				mysql_fetch_field("item5", TmpData, db_con2);
				gItemFactories[i][item5] = strval(TmpData);
				mysql_fetch_field("item5type", TmpData, db_con2);
				gItemFactories[i][item5type] = strval(TmpData);
				mysql_fetch_field("item5count", TmpData, db_con2);
				gItemFactories[i][item5count] = strval(TmpData);
				mysql_fetch_field("item5minBuy", TmpData, db_con2);
				gItemFactories[i][item5minBuy] = strval(TmpData);
				mysql_fetch_field("item5reproduceCount", TmpData, db_con2);
				gItemFactories[i][item5reproduceCount] = strval(TmpData);
				mysql_fetch_field("item5price", TmpData, db_con2);
				gItemFactories[i][item5price] = strval(TmpData);
				mysql_fetch_field("item6", TmpData, db_con2);
				gItemFactories[i][item6] = strval(TmpData);
				mysql_fetch_field("item6type", TmpData, db_con2);
				gItemFactories[i][item6type] = strval(TmpData);
				mysql_fetch_field("item6count", TmpData, db_con2);
				gItemFactories[i][item6count] = strval(TmpData);
				mysql_fetch_field("item6minBuy", TmpData, db_con2);
				gItemFactories[i][item6minBuy] = strval(TmpData);
				mysql_fetch_field("item6reproduceCount", TmpData, db_con2);
				gItemFactories[i][item6reproduceCount] = strval(TmpData);
				mysql_fetch_field("item6price", TmpData, db_con2);
				gItemFactories[i][item6price] = strval(TmpData);
				mysql_fetch_field("item7", TmpData, db_con2);
				gItemFactories[i][item7] = strval(TmpData);
				mysql_fetch_field("item7type", TmpData, db_con2);
				gItemFactories[i][item7type] = strval(TmpData);
				mysql_fetch_field("item7count", TmpData, db_con2);
				gItemFactories[i][item7count] = strval(TmpData);
				mysql_fetch_field("item7minBuy", TmpData, db_con2);
				gItemFactories[i][item7minBuy] = strval(TmpData);
				mysql_fetch_field("item7reproduceCount", TmpData, db_con2);
				gItemFactories[i][item7reproduceCount] = strval(TmpData);
				mysql_fetch_field("item7price", TmpData, db_con2);
				gItemFactories[i][item7price] = strval(TmpData);
				mysql_fetch_field("item8", TmpData, db_con2);
				gItemFactories[i][item8] = strval(TmpData);
				mysql_fetch_field("item8type", TmpData, db_con2);
				gItemFactories[i][item8type] = strval(TmpData);
				mysql_fetch_field("item8count", TmpData, db_con2);
				gItemFactories[i][item8count] = strval(TmpData);
				mysql_fetch_field("item8minBuy", TmpData, db_con2);
				gItemFactories[i][item8minBuy] = strval(TmpData);
				mysql_fetch_field("item8reproduceCount", TmpData, db_con2);
				gItemFactories[i][item8reproduceCount] = strval(TmpData);
				mysql_fetch_field("item8price", TmpData, db_con2);
				gItemFactories[i][item8price] = strval(TmpData);
				mysql_fetch_field("item9", TmpData, db_con2);
				gItemFactories[i][item9] = strval(TmpData);
				mysql_fetch_field("item9type", TmpData, db_con2);
				gItemFactories[i][item9type] = strval(TmpData);
				mysql_fetch_field("item9count", TmpData, db_con2);
				gItemFactories[i][item9count] = strval(TmpData);
				mysql_fetch_field("item9minBuy", TmpData, db_con2);
				gItemFactories[i][item9minBuy] = strval(TmpData);
				mysql_fetch_field("item9reproduceCount", TmpData, db_con2);
				gItemFactories[i][item9reproduceCount] = strval(TmpData);
				mysql_fetch_field("item9price", TmpData, db_con2);
				gItemFactories[i][item9price] = strval(TmpData);
				mysql_fetch_field("item10", TmpData, db_con2);
				gItemFactories[i][item10] = strval(TmpData);
				mysql_fetch_field("item10type", TmpData, db_con2);
				gItemFactories[i][item10type] = strval(TmpData);
				mysql_fetch_field("item10count", TmpData, db_con2);
				gItemFactories[i][item10count] = strval(TmpData);
				mysql_fetch_field("item10minBuy", TmpData, db_con2);
				gItemFactories[i][item10minBuy] = strval(TmpData);
				mysql_fetch_field("item10reproduceCount", TmpData, db_con2);
				gItemFactories[i][item10reproduceCount] = strval(TmpData);
				mysql_fetch_field("item10price", TmpData, db_con2);
				gItemFactories[i][item10price] = strval(TmpData);
				
				gItemFactories[i][fPickupID] = CreateDynamicPickup(1239, 1, gItemFactories[i][fPosX], gItemFactories[i][fPosY], gItemFactories[i][fPosZ]);
				
				i++;
			}
			mysql_free_result(db_con2);
			print("[SKRYPT:] Loaded item factories");
			return 1;
		}
		case LOAD_CUSTOM_OBJECTS:
		{
			if( !mysql_store_result(db_con2) )
			{
				printf("[ERROR:] Can't store result on LOAD_CUSTOM_OBJECTS");
				GameModeExit();
				return 1;
			}
			
			new i = 0;
			
			while(mysql_fetch_row(db_result, "|", db_con2))
			{
				split2(db_result, arrCoords, '|');
				
				if( strval(arrCoords[1]) )
					gCustomObj[i][cstSlotUsed] = true;
				else
					gCustomObj[i][cstSlotUsed] = false;
				gCustomObj[i][cstObjModel] = strval(arrCoords[2]);
				gCustomObj[i][cstObjVW] = strval(arrCoords[3]);
				gCustomObj[i][cstObjInt] = strval(arrCoords[4]);
				format( gCustomObj[i][cstObjOwner], MAX_PLAYER_NAME, "%s", arrCoords[5] );
				if( gCustomObj[i][cstSlotUsed] )
				{
					gCustomObj[i][cstObjID] = CreateDynamicObject(gCustomObj[i][cstObjModel], floatstr(arrCoords[6]), floatstr(arrCoords[7]), floatstr(arrCoords[8]), floatstr(arrCoords[9]), floatstr(arrCoords[10]), floatstr(arrCoords[11]), gCustomObj[i][cstObjVW], gCustomObj[i][cstObjInt]);
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
				i++;
			}
			mysql_free_result(db_con2);
			
			print("[SKRYPT:] Zaladowano customo objects");
		}
		case LOAD_HOUSES_ITEMS:
		{
			if( !mysql_store_result(db_con2) )
			{
				printf("[ERROR:] Can't store result on LOAD_HOUSES_ITEMS");
				GameModeExit();
				return 1;
			}

			new i;
			i = 0;
			
			while(mysql_fetch_row(db_result, "|", db_con2))
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
			
			print("[SKRYPT:] Zaladowano itemy w domach");
		}
		case LOAD_BUILDINGS:
		{
			if( !mysql_store_result(db_con2) )
			{
				printf("[ERROR:] Can't store result on LOAD_BUILDINGS");
				GameModeExit();
				return 1;
			}
			
			new i = 0;
			
			while(mysql_fetch_row(db_result, "|", db_con2))
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
				// printf("[BUILDINGS:] Building name: %s", Building[i][BuildingName] );
				
				if( Building[i][EnterX] != 0.0 || Building[i][EnterY] != 0.0 )
					Building[i][PickupID] = CreateDynamicPickup(1239, 1, Building[i][EnterX], Building[i][EnterY], Building[i][EnterZ]);
				
				i++;
			}
			mysql_free_result(db_con2);
			
			print("[SKRYPT:] Zaladowano budynki");
		}
		case LOAD_HOUSES:
		{
			if( !mysql_store_result(db_con2) )
			{
				printf("[ERROR:] Can't store result on LOAD_HOUSES");
				GameModeExit();
				return 1;
			}

			new i;
			new houselocation[MAX_ZONE_NAME];
			i = 0;

			while(mysql_fetch_row(db_result, "|", db_con2))
			{
				split2(db_result, arrCoords, '|');

				strmid(Houses[i][Description], arrCoords[1], 0, strlen(arrCoords[1]), 255);
				strmid(Houses[i][Owner], arrCoords[2], 0, strlen(arrCoords[2]), 255);
				Houses[i][EnterX] = floatstr(arrCoords[3]);
				Houses[i][EnterY] = floatstr(arrCoords[4]);
				Houses[i][EnterZ] = floatstr(arrCoords[5]);
				Houses[i][EnterWorld] = strval(arrCoords[6]);
				Houses[i][EnterInterior] = strval(arrCoords[7]);
				Houses[i][EnterAngle] = floatstr(arrCoords[8]);
				Houses[i][ExitX] = floatstr(arrCoords[9]);
				Houses[i][ExitY] = floatstr(arrCoords[10]);
				Houses[i][ExitZ] = floatstr(arrCoords[11]);
				Houses[i][ExitInterior] = strval(arrCoords[12]);
				Houses[i][ExitAngle] = floatstr(arrCoords[13]);
				Houses[i][Owned] = strval(arrCoords[14]);
				Houses[i][Rentable] = strval(arrCoords[15]);
				Houses[i][RentCost] = strval(arrCoords[16]);
				Houses[i][HousePrice] = strval(arrCoords[17]);
				Houses[i][Materials] = strval(arrCoords[18]);
				Houses[i][Drugs] = strval(arrCoords[19]);
				Houses[i][Money] = strval(arrCoords[20]);
				Houses[i][Locked] = strval(arrCoords[21]);
				Houses[i][HRadio1Bought] = strval(arrCoords[22]);
				Houses[i][HRadio1On] = strval(arrCoords[23]);
				Houses[i][HRadio1Ch] = strval(arrCoords[24]);
				Houses[i][HRadio1Vol] = strval(arrCoords[25]);
				Houses[i][HRadio1X] = floatstr(arrCoords[26]);
				Houses[i][HRadio1Y] = floatstr(arrCoords[27]);
				Houses[i][HRadio1Z] = floatstr(arrCoords[28]);
				Houses[i][HRadio1Angle] = floatstr(arrCoords[29]);
				Houses[i][HouseType] = strval(arrCoords[30]);
				Houses[i][HConfiscated] = strval(arrCoords[31]);
				Houses[i][HPlaced] = strval(arrCoords[32]);
				Houses[i][HIntSet] = strval(arrCoords[33]);
				Houses[i][HInterior] = strval(arrCoords[34]);
				
				if( Houses[i][HRadio1Bought] )
					Houses[i][HRadio1Obj] = CreateDynamicObject(O_RADIO_T_1, Houses[i][HRadio1X], Houses[i][HRadio1Y], Houses[i][HRadio1Z]-1.0, 0, 0, Houses[i][HRadio1Angle], i, Houses[i][ExitInterior]);
				if(Houses[i][HousePrice] != 0) // Don't create the house icon if the cost is 0.
				{
					if(Houses[i][Owned] == 0)
					{
						if( Houses[i][EnterX] != 0.0 || Houses[i][EnterY] != 0.0 )
							Houses[i][PickupID] = CreateDynamicPickup(1273, 1, Houses[i][EnterX], Houses[i][EnterY], Houses[i][EnterZ]);

						GetCoords2DZone(Houses[i][EnterX],Houses[i][EnterY], houselocation, MAX_ZONE_NAME);

						format(string, sizeof(string), "Ten dom jest na sprzedaz!");
						Houses3DTextLabelA[i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTYELLOW2, Houses[i][EnterX], Houses[i][EnterY], Houses[i][EnterZ]+1.0, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

						format(string, sizeof(string), "Adres: %d %s",i,houselocation);
						Houses3DTextLabelB[i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTYELLOW2, Houses[i][EnterX], Houses[i][EnterY], Houses[i][EnterZ]+0.5, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

						format(string, sizeof(string), "Opis: %s, Cena: $%d",Houses[i][Description],Houses[i][HousePrice]);
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

							format(string, sizeof(string), "Wlasciciel: %s",Houses[i][Owner]);
							Houses3DTextLabelB[i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTYELLOW2, Houses[i][EnterX], Houses[i][EnterY], Houses[i][EnterZ]+0.5, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

							format(string, sizeof(string), "Opis: %s Czynsz: $%d",Houses[i][Description],Houses[i][RentCost]);
							Houses3DTextLabelC[i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTYELLOW2, Houses[i][EnterX], Houses[i][EnterY], Houses[i][EnterZ], 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
						}
						else
						{
							GetCoords2DZone(Houses[i][EnterX],Houses[i][EnterY], houselocation, MAX_ZONE_NAME);

							format(string, sizeof(string), "Adres: %d %s",i,houselocation);
							Houses3DTextLabelA[i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTYELLOW2, Houses[i][EnterX], Houses[i][EnterY], Houses[i][EnterZ]+1.0, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

							format(string, sizeof(string), "Wlasciciel: %s",Houses[i][Owner]);
							Houses3DTextLabelB[i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTYELLOW2, Houses[i][EnterX], Houses[i][EnterY], Houses[i][EnterZ]+0.5, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

							format(string, sizeof(string), "Opis: %s",Houses[i][Description]);
							Houses3DTextLabelC[i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTYELLOW2, Houses[i][EnterX], Houses[i][EnterY], Houses[i][EnterZ], 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
						}
					}
				}
				i++;
			}
			mysql_free_result(db_con2);
			
			print("[SKRYPT:] Zaladowano domy");
		}
		case LOAD_BUSINESSES:
		{
			if( !mysql_store_result(db_con2) )
			{
				printf("[ERROR:] Can't store result on LOAD_BUSINESSES");
				GameModeExit();
				return 1;
			}

			new i, TmpData[256];
			i = 0;
			new businesstype[64];

			while(mysql_fetch_row(db_result, "|", db_con2))
			{
				mysql_fetch_field("BusinessName", Businesses[i][BusinessName], db_con2);
				mysql_fetch_field("Owner", Businesses[i][Owner], db_con2);
				mysql_fetch_field("EnterX", TmpData, db_con2);
				Businesses[i][EnterX] = floatstr(TmpData);
				mysql_fetch_field("EnterY", TmpData, db_con2);
				Businesses[i][EnterY] = floatstr(TmpData);
				mysql_fetch_field("EnterZ", TmpData, db_con2);
				Businesses[i][EnterZ] = floatstr(TmpData);
				mysql_fetch_field("EnterWorld", TmpData, db_con2);				
				Businesses[i][EnterWorld] = strval(TmpData);
				mysql_fetch_field("EnterInterior", TmpData, db_con2);	
				Businesses[i][EnterInterior] = strval(TmpData);
				mysql_fetch_field("EnterAngle", TmpData, db_con2);	
				Businesses[i][EnterAngle] = floatstr(TmpData);
				mysql_fetch_field("ExitX", TmpData, db_con2);
				Businesses[i][ExitX] = floatstr(TmpData);				
				mysql_fetch_field("ExitX", TmpData, db_con2);
				Businesses[i][ExitX] = floatstr(TmpData);				
				mysql_fetch_field("ExitY", TmpData, db_con2);	
				Businesses[i][ExitY] = floatstr(TmpData);
				mysql_fetch_field("ExitZ", TmpData, db_con2);
				Businesses[i][ExitZ] = floatstr(TmpData);
				mysql_fetch_field("ExitInterior", TmpData, db_con2);	
				Businesses[i][ExitInterior] = strval(TmpData);
				mysql_fetch_field("ExitAngle", TmpData, db_con2);
				Businesses[i][ExitAngle] = floatstr(TmpData);
				mysql_fetch_field("Owned", TmpData, db_con2);
				Businesses[i][Owned] = strval(TmpData);
				mysql_fetch_field("Enterable", TmpData, db_con2);
				Businesses[i][Enterable] = strval(TmpData);
				mysql_fetch_field("BizPrice", TmpData, db_con2);
				Businesses[i][BizPrice] = strval(TmpData);
				mysql_fetch_field("EntranceCost", TmpData, db_con2);	
				Businesses[i][EntranceCost] = strval(TmpData);
				mysql_fetch_field("Till", TmpData, db_con2);
				Businesses[i][Till] = strval(TmpData);
				mysql_fetch_field("Locked", TmpData, db_con2);	
				Businesses[i][Locked] = strval(TmpData);
				mysql_fetch_field("BizType", TmpData, db_con2);	
				Businesses[i][BizType] = strval(TmpData);
				mysql_fetch_field("Products", TmpData, db_con2);	
				Businesses[i][Products] = strval(TmpData);
				mysql_fetch_field("VehicleSpawned", TmpData, db_con2);
				Businesses[i][VehicleSpawned] = strval(TmpData);
				mysql_fetch_field("VehicleCount", TmpData, db_con2);
				Businesses[i][VehicleCount] = strval(TmpData);				
				mysql_fetch_field("MaxVehicles", TmpData, db_con2);	
				Businesses[i][MaxVehicles] = strval(TmpData);
				mysql_fetch_field("VehicleOrderCount", TmpData, db_con2);	
				Businesses[i][VehicleOrderCount] = strval(TmpData);
				mysql_fetch_field("SalesJob", TmpData, db_con2);	
				Businesses[i][SalesJob] = strval(TmpData);
				mysql_fetch_field("W9MM", TmpData, db_con2);	
				Businesses[i][W9MM] = strval(TmpData);
				mysql_fetch_field("W9MMSil", TmpData, db_con2);
				Businesses[i][W9MMSil] = strval(TmpData);
				mysql_fetch_field("WDesEagle", TmpData, db_con2);	
				Businesses[i][WDesEagle] = strval(TmpData);
				mysql_fetch_field("WMicroSMG", TmpData, db_con2);
				Businesses[i][WMicroSMG] = strval(TmpData);
				mysql_fetch_field("WMP5", TmpData, db_con2);
				Businesses[i][WMP5] = strval(TmpData);
				mysql_fetch_field("WTec9", TmpData, db_con2);	
				Businesses[i][WTec9] = strval(TmpData);
				mysql_fetch_field("WShotgun", TmpData, db_con2);	
				Businesses[i][WShotgun] = strval(TmpData);
				mysql_fetch_field("WAK47", TmpData, db_con2);	
				Businesses[i][WAK47] = strval(TmpData);
				mysql_fetch_field("WM4", TmpData, db_con2);
				Businesses[i][WM4] = strval(TmpData);
				mysql_fetch_field("WRifle", TmpData, db_con2);	
				Businesses[i][WRifle] = strval(TmpData);
				mysql_fetch_field("WSRifle", TmpData, db_con2);	
				Businesses[i][WSRifle] = strval(TmpData);
				mysql_fetch_field("W9MMAmmo", TmpData, db_con2);	
				Businesses[i][W9MMAmmo] = strval(TmpData);
				mysql_fetch_field("W50AEAmmo", TmpData, db_con2);	
				Businesses[i][W50AEAmmo] = strval(TmpData);
				mysql_fetch_field("WBuckshot", TmpData, db_con2);
				Businesses[i][WBuckshot] = strval(TmpData);				
				mysql_fetch_field("W762MMAmmo", TmpData, db_con2);
				Businesses[i][W762MMAmmo] = strval(TmpData);
				mysql_fetch_field("W127MMAmmo", TmpData, db_con2);	
				Businesses[i][W127MMAmmo] = strval(TmpData);
				mysql_fetch_field("BRadio1Bought", TmpData, db_con2);	
				Businesses[i][BRadio1Bought] = strval(TmpData);
				mysql_fetch_field("BRadio1On", TmpData, db_con2);
				Businesses[i][BRadio1On] = strval(TmpData);
				mysql_fetch_field("BRadio1Ch", TmpData, db_con2);	
				Businesses[i][BRadio1Ch] = strval(TmpData);
				mysql_fetch_field("BRadio1Vol", TmpData, db_con2);	
				Businesses[i][BRadio1Vol] = strval(TmpData);
				mysql_fetch_field("BRadio1X", TmpData, db_con2);
				Businesses[i][BRadio1X] = floatstr(TmpData);
				mysql_fetch_field("BRadio1Y", TmpData, db_con2);
				Businesses[i][BRadio1Y] = floatstr(TmpData);
				mysql_fetch_field("BRadio1Z", TmpData, db_con2);
				Businesses[i][BRadio1Z] = floatstr(TmpData);
				mysql_fetch_field("BRadio1Angle", TmpData, db_con2);
				Businesses[i][BRadio1Angle] = floatstr(TmpData);
				mysql_fetch_field("Confiscated", TmpData, db_con2);
				Businesses[i][BConfiscated] = strval(TmpData);
				mysql_fetch_field("Placed", TmpData, db_con2);
				Businesses[i][BPlaced] = strval(TmpData);
				mysql_fetch_field("IntSet", TmpData, db_con2);
				Businesses[i][BIntSet] = strval(TmpData);
				mysql_fetch_field("Interior", TmpData, db_con2);
				Businesses[i][BInterior] = strval(TmpData);
				mysql_fetch_field("Product1Price", TmpData, db_con2);
				Businesses[i][Product1Price] = strval(TmpData);
				mysql_fetch_field("Product2Price", TmpData, db_con2);	
				Businesses[i][Product2Price] = strval(TmpData);
				mysql_fetch_field("Product3Price", TmpData, db_con2);	
				Businesses[i][Product3Price] = strval(TmpData);
				mysql_fetch_field("Product4Price", TmpData, db_con2);	
				Businesses[i][Product4Price] = strval(TmpData);
				mysql_fetch_field("Product5Price", TmpData, db_con2);	
				Businesses[i][Product5Price] = strval(TmpData);
				mysql_fetch_field("Product6Price", TmpData, db_con2);	
				Businesses[i][Product6Price] = strval(TmpData);
				mysql_fetch_field("Product7Price", TmpData, db_con2);	
				Businesses[i][Product7Price] = strval(TmpData);
				mysql_fetch_field("Product8Price", TmpData, db_con2);	
				Businesses[i][Product8Price] = strval(TmpData);
				mysql_fetch_field("Product9Price", TmpData, db_con2);	
				Businesses[i][Product9Price] = strval(TmpData);
				mysql_fetch_field("Product10Price", TmpData, db_con2);	
				Businesses[i][Product10Price] = strval(TmpData);
				mysql_fetch_field("Product11Price", TmpData, db_con2);	
				Businesses[i][Product11Price] = strval(TmpData);
				mysql_fetch_field("Product12Price", TmpData, db_con2);	
				Businesses[i][Product12Price] = strval(TmpData);
				mysql_fetch_field("Product13Price", TmpData, db_con2);	
				Businesses[i][Product13Price] = strval(TmpData);
				mysql_fetch_field("Product14Price", TmpData, db_con2);	
				Businesses[i][Product14Price] = strval(TmpData);
				mysql_fetch_field("Product15Price", TmpData, db_con2);	
				Businesses[i][Product15Price] = strval(TmpData);
				mysql_fetch_field("Product16Price", TmpData, db_con2);	
				Businesses[i][Product16Price] = strval(TmpData);
				mysql_fetch_field("Product17Price", TmpData, db_con2);	
				Businesses[i][Product17Price] = strval(TmpData);
				mysql_fetch_field("Product18Price", TmpData, db_con2);	
				Businesses[i][Product18Price] = strval(TmpData);
				mysql_fetch_field("Product19Price", TmpData, db_con2);	
				Businesses[i][Product19Price] = strval(TmpData);
				mysql_fetch_field("Product20Price", TmpData, db_con2);	
				Businesses[i][Product20Price] = strval(TmpData);
				mysql_fetch_field("Product21Price", TmpData, db_con2);	
				Businesses[i][Product21Price] = strval(TmpData);
				mysql_fetch_field("Product22Price", TmpData, db_con2);	
				Businesses[i][Product22Price] = strval(TmpData);
				mysql_fetch_field("Product23Price", TmpData, db_con2);	
				Businesses[i][Product23Price] = strval(TmpData);
				mysql_fetch_field("Product24Price", TmpData, db_con2);	
				Businesses[i][Product24Price] = strval(TmpData);
				mysql_fetch_field("Product25Price", TmpData, db_con2);	
				Businesses[i][Product25Price] = strval(TmpData);
				mysql_fetch_field("Product26Price", TmpData, db_con2);	
				Businesses[i][Product26Price] = strval(TmpData);
				mysql_fetch_field("Product27Price", TmpData, db_con2);	
				Businesses[i][Product27Price] = strval(TmpData);
				mysql_fetch_field("Product28Price", TmpData, db_con2);	
				Businesses[i][Product28Price] = strval(TmpData);
				mysql_fetch_field("Product29Price", TmpData, db_con2);	
				Businesses[i][Product29Price] = strval(TmpData);
				mysql_fetch_field("Product30Price", TmpData, db_con2);	
				Businesses[i][Product30Price] = strval(TmpData);

				if( Businesses[i][BRadio1Bought] )
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

				if(Businesses[i][Owned] == 0)
				{
					if( Businesses[i][EnterX] != 0.0 || Businesses[i][EnterY] != 0.0 )
						Businesses[i][PickupID] = CreateDynamicPickup(1272, 1, Businesses[i][EnterX], Businesses[i][EnterY], Businesses[i][EnterZ]);

					format(string, sizeof(string), "Ten biznes jest na sprzeda¿!");
					Business3DTextLabelA[i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE2, Businesses[i][EnterX], Businesses[i][EnterY], Businesses[i][EnterZ]+1.0, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

					format(string, sizeof(string), "Numer Budynku: %d, Nazwa biznesu: %s, Typ biznesu: %s",i,Businesses[i][BusinessName],businesstype);
					Business3DTextLabelB[i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE2, Businesses[i][EnterX], Businesses[i][EnterY], Businesses[i][EnterZ]+0.5, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

					format(string, sizeof(string), "Cena: $%d",Businesses[i][BizPrice]);
					Business3DTextLabelC[i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE2, Businesses[i][EnterX], Businesses[i][EnterY], Businesses[i][EnterZ], 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
				}
				else if(Businesses[i][Owned] == 1)
				{
					if( Businesses[i][EnterX] != 0.0 || Businesses[i][EnterY] != 0.0 )
						Businesses[i][PickupID] = CreateDynamicPickup(1239, 1, Businesses[i][EnterX], Businesses[i][EnterY], Businesses[i][EnterZ]);

					format(string, sizeof(string), "Nazwa biznesu: %s, Typ biznesu: %s",Businesses[i][BusinessName],businesstype);
					Business3DTextLabelA[i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE2, Businesses[i][EnterX], Businesses[i][EnterY], Businesses[i][EnterZ]+1.0, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

					format(string, sizeof(string), "Numer Budynku: %d, W³aœciciel: %s", i,Businesses[i][Owner]);
					Business3DTextLabelB[i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE2, Businesses[i][EnterX], Businesses[i][EnterY], Businesses[i][EnterZ]+0.5, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

					format(string, sizeof(string), "Wejœciówka: $%d",Businesses[i][EntranceCost]);
					Business3DTextLabelC[i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE2, Businesses[i][EnterX], Businesses[i][EnterY], Businesses[i][EnterZ], 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
				}

				i++;
			}
			mysql_free_result(db_con2);
		
			print("[SKRYPT:] Zaladowano biznesy");
		}
		case LOAD_BUS_TRACKS:
		{
			if( !mysql_store_result(db_con2) )
			{
				printf("[ERROR:] Can't store result on LOAD_BUS_TRACKS");
				GameModeExit();
				return 1;
			}
			
			new i;
			i = 0;
			
			while(mysql_fetch_row(db_result, "|", db_con2))
			{
				split2(db_result, arrCoords, '|');
				
				gBusTrackEnabled[i] = strval(arrCoords[1]);
				gBusTrackStartArea[i] = strval(arrCoords[2]);
				
				i++;
			}
			printf("[SKRYPT:] Zaladowano informacje o trasach autobusowych");
			mysql_free_result(db_con2);
		}
		case LOAD_BUS_TRACKS_DATA:
		{
			if( !mysql_store_result(db_con2) )
			{
				printf("[ERROR:] Can't store result on LOAD_BUS_TRACKS_DATA");
				GameModeExit();
				return 1;
			}
			
			new trkid, cpid;
			
			while(mysql_fetch_row(db_result, "|", db_con2))
			{
				split2(db_result, arrCoords, '|');
				
				trkid = strval(arrCoords[1]);
				cpid = strval(arrCoords[2]);
				gBusTrackCPX[trkid][cpid] = floatstr(arrCoords[3]);
				gBusTrackCPY[trkid][cpid] = floatstr(arrCoords[4]);
				gBusTrackCPZ[trkid][cpid] = floatstr(arrCoords[5]);
				gBusTrackCPReward[trkid][cpid] = strval(arrCoords[6]);
				gBusTrackCPType[trkid][cpid] = strval(arrCoords[7]);
				gBusTrackCPTime[trkid][cpid] = strval(arrCoords[8]);
			}
			printf("[SKRYPT:] Zaladowano informacje o trasach autobusowych");
			mysql_free_result(db_con2);
		}
		case LOAD_VARIABLES:
		{
			if( !mysql_store_result(db_con2) )
			{
				printf("[ERROR:] Can't store result on LOAD_VARIABLES");
				return 1;
			}
			new i = 0;

			while(mysql_fetch_row(db_result, "|", db_con2))
			{
				split2(db_result, arrCoords, '|');

				strins(DBVariables[i][varName], arrCoords[1], 0, 128);
				strins(DBVariables[i][varType], arrCoords[2], 0, 1);
				DBVariables[i][varDValue] = strval(arrCoords[3]);
				DBVariables[i][varFValue] = floatstr(arrCoords[4]);
				strins(DBVariables[i][varSValue], arrCoords[5], 0, 128);

				i++;
			}
			print("[SKRYPT:] Zaladowano pomniejsze dane");
			
			mysql_free_result(db_con2);
		}
		case CHECK_PHONE:
		{
			GetPlayerName(playerid, string, sizeof(string));
			// printf("[DEBUG:][CHECK_PHONE] pid = %d, pname = %s", playerid, string);
			if( !mysql_store_result(db_con2) )
			{
				printf("[ERROR:] Can't store result on CHECK_PHONE");
				return 1;
			}
			if(mysql_num_rows(db_con2) == 0)
			{
				if(InsertPlayerItemEx(playerid, 3, 3, 1, gRandNumber[playerid], gPhoneC[playerid], 0, "Puste") == 0)
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie masz miejsca na telefon");
					return 1;
				}
				if(gPlayerData[playerid][pFirstPhone] == 0)
				{
					SendClientMessage(playerid,COLOR_GREEN,"[INFO:] Kupi³eœ swój pierwszy telefon ! $-650");
					AddExpPoint(playerid);
					gPlayerData[playerid][pFirstPhone] = 1;

					SavePlayerData(playerid, "FirstPhone");
				}
				else
				{
					SendClientMessage(playerid,COLOR_WHITE,"[INFO:] Kupi³eœ telefon ! $-650");
				}
				
				GivePlayerCash(playerid, -650);
				Businesses[gPhoneC[playerid]][Till] += 650;
				SaveBizData(gPhoneC[playerid], "Till");
				format(string, sizeof(string), "INSERT INTO `samp_phones` (`PlayerName` , `Nr`) VALUES ('%s' , '%d')", gPlayerData[playerid][pName], gRandNumber[playerid]);
				mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			}
			else
			{
				gRandNumber[playerid] = 600000000 + random(999999);
				format(string, sizeof(string), "SELECT `Nr` FROM `samp_phones` WHERE `Nr` = '%d'",gRandNumber[playerid]);
				mysql_query(string, CHECK_PHONE, playerid, db_con2);
			}
			mysql_free_result(db_con2);
		}
		case LOAD_CARSDATA:
		{
			if( !mysql_store_result(db_con2) )
			{
				printf("[ERROR:] Can't store result on LOAD_CARSDATA");
				GameModeExit();
				return 1;
			}
			new i = 0;

			while(mysql_fetch_row(db_result, "|", db_con2))
			{
				split2(db_result, arrCoords, '|');

				CarsData[i][Model] = strval(arrCoords[1]);
				CarsData[i][Bak] = strval(arrCoords[2]);
				CarsData[i][Paliwo] = strval(arrCoords[3]);
				CarsData[i][Spalanie] = strval(arrCoords[4]);
				CarsData[i][ToGas] = strval(arrCoords[5]);
				
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
			
			printf("[SKRYPT:] Zaladowano dane pojazdow");
		}
		/* Reset player key item for vehicle to 999 so player cant use the car anymore */
		case RESET_VEH_KEY_ITEM_1:
		{
			if( !mysql_store_result(db_con2) )
			{
				printf("[ERROR:] Can't store result on RESET_VEH_KEY_ITEM_1");
				return 1;
			}
			mysql_fetch_row(db_result, "|", db_con2);
			split2(db_result, arrCoords, '|');

			new tmpVar[tmpDataItem];
			
			tmpVar[item1] = strval(arrCoords[0]);
			tmpVar[item2] = strval(arrCoords[1]);
			tmpVar[item3] = strval(arrCoords[2]);
			tmpVar[item4] = strval(arrCoords[3]);
			tmpVar[item5] = strval(arrCoords[4]);
			tmpVar[item1type] = strval(arrCoords[6]);
			tmpVar[item2type] = strval(arrCoords[7]);
			tmpVar[item3type] = strval(arrCoords[8]);
			tmpVar[item4type] = strval(arrCoords[9]);
			tmpVar[item5type] = strval(arrCoords[10]);
			strins(tmpVar[itemPlayerName], arrCoords[41], 0, sizeof(tmpVar[itemPlayerName]));

			if(spareid != 255)
			{
				new tmpString[256];
				if(tmpVar[item1type] == 2)
				{
					if(tmpVar[item1] == spareid)
					{
						tmpVar[item1] = 999;

						format(tmpString, sizeof(tmpString), "UPDATE `samp_users_items` SET `Item1` = '%d' WHERE `PlayerName` = '%s'", tmpVar[item1], tmpVar[itemPlayerName]);
						mysql_query(tmpString, SAVE, INVALID_PLAYER_ID, db_con2);
					}
				}
				if(tmpVar[item2type] == 2)
				{
					if(tmpVar[item2] == spareid)
					{
						tmpVar[item2] = 999;

						format(tmpString, sizeof(tmpString), "UPDATE `samp_users_items` SET `Item2` = '%d' WHERE `PlayerName` = '%s'", tmpVar[item2], tmpVar[itemPlayerName]);
						mysql_query(tmpString, SAVE, INVALID_PLAYER_ID, db_con2);
					}
				}
				if(tmpVar[item3type] == 2)
				{
					if(tmpVar[item3] == spareid)
					{
						tmpVar[item3] = 999;

						format(tmpString, sizeof(tmpString), "UPDATE `samp_users_items` SET `Item3` = '%d' WHERE `PlayerName` = '%s'", tmpVar[item3], tmpVar[itemPlayerName]);
						mysql_query(tmpString, SAVE, INVALID_PLAYER_ID, db_con2);
					}
				}
				if(tmpVar[item4type] == 2)
				{
					if(tmpVar[item4] == spareid)
					{
						tmpVar[item4] = 999;

						format(tmpString, sizeof(tmpString), "UPDATE `samp_users_items` SET `Item4` = '%d' WHERE `PlayerName` = '%s'", tmpVar[item4], tmpVar[itemPlayerName]);
						mysql_query(tmpString, SAVE, INVALID_PLAYER_ID, db_con2);
					}
				}
				if(tmpVar[item5type] == 2)
				{
					if(tmpVar[item5] == spareid)
					{
						tmpVar[item5] = 999;

						format(tmpString, sizeof(tmpString), "UPDATE `samp_users_items` SET `Item5` = '%d' WHERE `PlayerName` = '%s'", tmpVar[item5], tmpVar[itemPlayerName]);
						mysql_query(tmpString, SAVE, INVALID_PLAYER_ID, db_con2);
					}
				}
			}			
			mysql_free_result(db_con2);
		}
		/* Reset player key item for vehicle to 999 so player cant use the car anymore */
		case RESET_VEH_KEY_ITEM_2:
		{
			if( !mysql_store_result(db_con2) )
			{
				printf("[ERROR:] Can't store result on RESET_VEH_KEY_ITEM_2");
				return 1;
			}
			mysql_fetch_row(db_result, "|", db_con2);
			split2(db_result, arrCoords, '|');

			new tmpVar[tmpDataItem];
			
			tmpVar[item6] = strval(arrCoords[2]);
			tmpVar[item7] = strval(arrCoords[3]);
			tmpVar[item8] = strval(arrCoords[4]);
			tmpVar[item9] = strval(arrCoords[5]);
			tmpVar[item10] = strval(arrCoords[6]);
			tmpVar[item6type] = strval(arrCoords[7]);
			tmpVar[item7type] = strval(arrCoords[8]);
			tmpVar[item8type] = strval(arrCoords[9]);
			tmpVar[item9type] = strval(arrCoords[10]);
			tmpVar[item10type] = strval(arrCoords[11]);
			strins(tmpVar[itemPlayerName], arrCoords[1], 0, sizeof(tmpVar[itemPlayerName]));

			if(spareid != 255)
			{
				new tmpString[256];
				if(tmpVar[item6type] == 2)
				{
					if(tmpVar[item6] == spareid)
					{
						tmpVar[item6] = 999;

						format(tmpString, sizeof(tmpString), "UPDATE `samp_users_items` SET `Item6` = '%d' WHERE `PlayerName` = '%s'", tmpVar[item6], tmpVar[itemPlayerName]);
						mysql_query(tmpString, SAVE, INVALID_PLAYER_ID, db_con2);
					}
				}
				if(tmpVar[item7type] == 2)
				{
					if(tmpVar[item7] == spareid)
					{
						tmpVar[item7] = 999;

						format(tmpString, sizeof(tmpString), "UPDATE `samp_users_items` SET `Item7` = '%d' WHERE `PlayerName` = '%s'", tmpVar[item7], tmpVar[itemPlayerName]);
						mysql_query(tmpString, SAVE, INVALID_PLAYER_ID, db_con2);
					}
				}
				if(tmpVar[item8type] == 2)
				{
					if(tmpVar[item8] == spareid)
					{
						tmpVar[item8] = 999;

						format(tmpString, sizeof(tmpString), "UPDATE `samp_users_items` SET `Item8` = '%d' WHERE `PlayerName` = '%s'", tmpVar[item8], tmpVar[itemPlayerName]);
						mysql_query(tmpString, SAVE, INVALID_PLAYER_ID, db_con2);
					}
				}
				if(tmpVar[item9type] == 2)
				{
					if(tmpVar[item9] == spareid)
					{
						tmpVar[item9] = 999;

						format(tmpString, sizeof(tmpString), "UPDATE `samp_users_items` SET `Item9` = '%d' WHERE `PlayerName` = '%s'", tmpVar[item9], tmpVar[itemPlayerName]);
						mysql_query(tmpString, SAVE, INVALID_PLAYER_ID, db_con2);
					}
				}
				if(tmpVar[item10type] == 2)
				{
					if(tmpVar[item10] == spareid)
					{
						tmpVar[item10] = 999;

						format(tmpString, sizeof(tmpString), "UPDATE `samp_users_items` SET `Item10` = '%d' WHERE `PlayerName` = '%s'", tmpVar[item10], tmpVar[itemPlayerName]);
						mysql_query(tmpString, SAVE, INVALID_PLAYER_ID, db_con2);
					}
				}
			}			
			mysql_free_result(db_con2);
		}
		/* Reset player key item for vehicle to 999 so player cant use the car anymore */
		case RESET_VEH_KEY_ITEM_3:
		{
			if( !mysql_store_result(db_con2) )
			{
				printf("[ERROR:] Can't store result on RESET_VEH_KEY_ITEM_3");
				return 1;
			}
			mysql_fetch_row(db_result, "|", db_con2);
			split2(db_result, arrCoords, '|');

			new tmpVar[tmpDataItem];
			
			tmpVar[item11] = strval(arrCoords[2]);
			tmpVar[item12] = strval(arrCoords[3]);
			tmpVar[item13] = strval(arrCoords[4]);
			tmpVar[item14] = strval(arrCoords[5]);
			tmpVar[item15] = strval(arrCoords[6]);
			tmpVar[item11type] = strval(arrCoords[7]);
			tmpVar[item12type] = strval(arrCoords[8]);
			tmpVar[item13type] = strval(arrCoords[9]);
			tmpVar[item14type] = strval(arrCoords[10]);
			tmpVar[item15type] = strval(arrCoords[11]);
			strins(tmpVar[itemPlayerName], arrCoords[1], 0, sizeof(tmpVar[itemPlayerName]));

			if(spareid != 255)
			{
				new tmpString[256];
				if(tmpVar[item11type] == 2)
				{
					if(tmpVar[item11] == spareid)
					{
						tmpVar[item11] = 999;

						format(tmpString, sizeof(tmpString), "UPDATE `samp_users_items` SET `Item6` = '%d' WHERE `PlayerName` = '%s'", tmpVar[item11], tmpVar[itemPlayerName]);
						mysql_query(tmpString, SAVE, INVALID_PLAYER_ID, db_con2);
					}
				}
				if(tmpVar[item12type] == 2)
				{
					if(tmpVar[item12] == spareid)
					{
						tmpVar[item12] = 999;

						format(tmpString, sizeof(tmpString), "UPDATE `samp_users_items` SET `Item7` = '%d' WHERE `PlayerName` = '%s'", tmpVar[item12], tmpVar[itemPlayerName]);
						mysql_query(tmpString, SAVE, INVALID_PLAYER_ID, db_con2);
					}
				}
				if(tmpVar[item13type] == 2)
				{
					if(tmpVar[item13] == spareid)
					{
						tmpVar[item13] = 999;

						format(tmpString, sizeof(tmpString), "UPDATE `samp_users_items` SET `item13` = '%d' WHERE `PlayerName` = '%s'", tmpVar[item13], tmpVar[itemPlayerName]);
						mysql_query(tmpString, SAVE, INVALID_PLAYER_ID, db_con2);
					}
				}
				if(tmpVar[item14type] == 2)
				{
					if(tmpVar[item14] == spareid)
					{
						tmpVar[item14] = 999;

						format(tmpString, sizeof(tmpString), "UPDATE `samp_users_items` SET `item14` = '%d' WHERE `PlayerName` = '%s'", tmpVar[item14], tmpVar[itemPlayerName]);
						mysql_query(tmpString, SAVE, INVALID_PLAYER_ID, db_con2);
					}
				}
				if(tmpVar[item15type] == 2)
				{
					if(tmpVar[item15] == spareid)
					{
						tmpVar[item15] = 999;

						format(tmpString, sizeof(tmpString), "UPDATE `samp_users_items` SET `item15` = '%d' WHERE `PlayerName` = '%s'", tmpVar[item15], tmpVar[itemPlayerName]);
						mysql_query(tmpString, SAVE, INVALID_PLAYER_ID, db_con2);
					}
				}
			}			
			mysql_free_result(db_con2);
		}
		case LOAD_WANTED_LIST:
		{
			// printf("[DEBUG:][LOAD_WANTED_LIST]");
			if( !mysql_store_result(db_con1) )
			{
				printf("[ERROR:] Can't store result on LOAD_WANTED_LIST");
				return 1;
			}
			new i = 0;
			while(mysql_fetch_row(db_result, "|", db_con1))
			{
				split2(db_result, arrCoords, '|');
				
				strmid(WantedList[i][WantedName], arrCoords[1], 0, strlen(arrCoords[1]), 255);
				strmid(WantedList[i][WantedDescription], arrCoords[2], 0, strlen(arrCoords[2]), 255);
				WantedList[i][WantedCommitedDay] = strval(arrCoords[3]);
				WantedList[i][WantedCommitedMonth] = strval(arrCoords[4]);
				WantedList[i][WantedCommitedYear] = strval(arrCoords[4]);
				
				printf("[SKRYPT:] Wanted: %s, Description: %s, Commited day: %d, month: %d, year: %d", WantedList[i][WantedName], WantedList[i][WantedDescription], WantedList[i][WantedCommitedDay], WantedList[i][WantedCommitedMonth], WantedList[i][WantedCommitedYear]);
				
				i++;
			}
			mysql_free_result(db_con1);
		}
		case SHOW_WANTED_LIST:
		{
			if( !mysql_store_result(db_con2) )
			{
				printf("[ERROR:] Can't store result on SHOW_WANTED_LIST");
				return 1;
			}
			new i = 0;
			new k = mysql_num_rows(db_con2);
			printf("ile k %d", k);
			if(k == 0)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Brak wpisów do kartoteki na wybrane nazwisko");
				mysql_free_result(db_con2);
				return 1;
			}
			SendClientMessage(playerid, COLOR_GREEN, "[INFO:] Odnaleziono podejrzanego, wyœwietlanie danych...");
			while(mysql_fetch_row(db_result, "|", db_con2))
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
			new string2[1024];
			new string3[256];
			i = 0;
			while(k > i)
			{
				if(WantedList[i][WantedPunished])
				{
					format(string3, sizeof(string3), "[%d/%d/%d][T] %s\n", WantedList[i][WantedCommitedDay], WantedList[i][WantedCommitedMonth],WantedList[i][WantedCommitedYear], WantedList[i][WantedDescription]);
				}
				else
				{
					format(string3, sizeof(string3), "[%d/%d/%d][N] %s\n", WantedList[i][WantedCommitedDay], WantedList[i][WantedCommitedMonth],WantedList[i][WantedCommitedYear], WantedList[i][WantedDescription]);
				}
				
				format(string2, sizeof(string2), "%s%s", string3, string2);

				i++;
			}
			mysql_free_result(db_con2);
			ShowPlayerDialog(playerid, 100, DIALOG_STYLE_LIST, "Kartoteka", string2, "Zamknij", "");
		}		
		case LOAD_LUCKY_LOTTERY:
		{
			if( !mysql_store_result(db_con2) )
			{
				printf("[ERROR:] Can't store result on LOAD_LUCKY_LOTTERY");
				GameModeExit();
				return 1;
			}
			new i = 0, TmpData[256];
			while(mysql_fetch_row(db_result, "|", db_con2))
			{
				mysql_fetch_field("LotteryID", TmpData, db_con2);
				gLuckyLottery[i][LuckyID] = strval(TmpData);
				mysql_fetch_field("PlayerName", gLuckyLottery[i][LuckyPlayerName], db_con2);
				mysql_fetch_field("RewardTaken", TmpData, db_con2);
				gLuckyLottery[i][LuckyRewardTaken] = strval(TmpData);
				mysql_fetch_field("number1", TmpData, db_con2);
				gLuckyLottery[i][LuckyNumbers][0] = strval(TmpData);
				mysql_fetch_field("number2", TmpData, db_con2);
				gLuckyLottery[i][LuckyNumbers][1] = strval(TmpData);
				mysql_fetch_field("number3", TmpData, db_con2);
				gLuckyLottery[i][LuckyNumbers][2] = strval(TmpData);
				mysql_fetch_field("number4", TmpData, db_con2);
				gLuckyLottery[i][LuckyNumbers][3] = strval(TmpData);
				
				i++;
			}
			mysql_free_result(db_con2);
			printf("[SKRYPT:] Loaded Lucky Lottery Data");			
		}
	}
	if(mysql_result_stored(db_con2))
	{
		mysql_free_result(db_con2);
	}
	if(mysql_result_stored(db_con3))
	{
		mysql_free_result(db_con3);
	}
	// mysql_error(string, db_con1);
	// if(strcmp(string, " ", false) != 0)
		// printf("[WARNING:] %s", string);
	
	// mysql_error(string, db_con2);
	// if(strcmp(string, " ", false) != 0)
		// printf("[WARNING:] %s", string);
	
	// mysql_error(string, db_con3);
	// if(strcmp(string, " ", false) != 0)
		// printf("[WARNING:] %s", string);
		
	return 1;
}