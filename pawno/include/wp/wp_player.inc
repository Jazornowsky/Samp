/***
*
* File: wp_player.inc
* Auth: Damian Wojdat
* Date: 15.09.2011
* Desc: Player related functions.
* Note: Seems incomplete ? Not transfered parts of script ?
*
*************************************************************************************************************/

OnPlayerLogin(playerid, password[])
{
	static string[256];
	new PlayerNameTMP[128];	
	
	strdel(gPasswd[playerid], 0, strlen(gPasswd[playerid]));
	strins(gPasswd[playerid], password, 0);
	
	GetPlayerName(playerid, PlayerNameTMP, sizeof(PlayerNameTMP));
	
	strdel(gPlayerData[playerid][pSName], 0, strlen(gPlayerData[playerid][pSName]));
	strins(gPlayerData[playerid][pSName], PlayerNameTMP, 0);
	
	gPlayerData[playerid][pLoading] = 1;
	
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Czekaj, trwa ³adowanie danych...");
	
	format(string, sizeof(string), "SELECT `Key`, `PlayerName` FROM `samp_users` WHERE `PlayerName` = '%s'", PlayerNameTMP);
	mysql_query(string, PLAYER_DATA_LOAD_FIRST_MYSQL, playerid, db_con4);

	return 1;
} // end of OnPlayerLogin
