BW(playerid)
{
	if(gPlayerData[playerid][pAdmin] == 0)
	{
		SetPlayerCameraPos( playerid, gPlayerData[playerid][pCrashX], gPlayerData[playerid][pCrashY], gPlayerData[playerid][pCrashZ]+5.0 );
		SetPlayerCameraLookAt( playerid,gPlayerData[playerid][pCrashX], gPlayerData[playerid][pCrashY], gPlayerData[playerid][pCrashZ]+10.0 );	
		new distance = GetDistanceToPoint(playerid, -2263.0, 570.0, 35.0);
		gPlayerData[playerid][pCharacterDying] = distance;
		if(gPlayerData[playerid][pCharacterDying] < 1800)
			gPlayerData[playerid][pCharacterDying] = 1800;
		if(gPlayerData[playerid][pCharacterDying] > 3600)
			gPlayerData[playerid][pCharacterDying] = 3600;
		printf("time to die: %d", gPlayerData[playerid][pCharacterDying]);		
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Stan twojej postaci jest krytyczny ! Pozosta³o Ci liczyæ na szczêœcie a¿ ktoœ Cie zauwa¿y i wezwie pogotowie");
		SendClientMessage(playerid, COLOR_RED, "[INFO:] lub umrzeæ wpisuj¹c komende /samobojstwo");
		SetPlayerHealth(playerid,99999);
		SavePlayerData(playerid, "CharacterDying");
	}
}

// KillPlayer(playerid)
// {
	// if(gPlayerData[playerid][pCharacterDying] == 1)
	// {
		// gPlayerData[playerid][pCharacterDeath] = 1;		
		// SavePlayerData(playerid, "CharacterDeath");
		
		// SetPlayerHealth(playerid, 0.0);
		// SendClientMessage(playerid, COLOR_RED, "[INFO:] Twoja postaæ umar³a ! Mo¿esz teraz wyjœæ z gry i zarejestrowaæ now¹ lub wys³aæ smsa wskrzesaj¹cego Twoj¹ postaæ.");
		// gPlayerLogged[playerid] = 0;
		// Kick(playerid);
	// }
// }