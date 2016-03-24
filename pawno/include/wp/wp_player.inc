OnPlayerLogin(playerid, password[])
{
	new string[128];
	new PlayerNameTMP[128];	
	strdel( gPasswd[playerid], 0, strlen(gPasswd[playerid]) );
	strins( gPasswd[playerid], password, 0 );
	GetPlayerName(playerid, PlayerNameTMP, sizeof(PlayerNameTMP));
	strdel( gPlayerData[playerid][pSName], 0, strlen( gPlayerData[playerid][pSName] ) );
	strins( gPlayerData[playerid][pSName], PlayerNameTMP, 0 );
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Czekaj, trwa ³adowanie danych...");
	format(string, sizeof(string), "SELECT `Key`, `PlayerName` FROM `samp_users` WHERE `PlayerName` = '%s'", PlayerNameTMP);
	mysql_query(string, PLAYER_DATA_LOAD_FIRST_MYSQL, playerid, db_con2);

	return 1;
} // end of OnPlayerLogin
