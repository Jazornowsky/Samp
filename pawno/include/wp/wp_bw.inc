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
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Stan twojej postaci jest krytyczny ! Pozosta�o Ci liczy� na szcz�cie a� kto� Cie zauwa�y i wezwie pogotowie");
		SendClientMessage(playerid, COLOR_RED, "[INFO:] lub umrze� wpisuj�c komende /samobojstwo");
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
		// SendClientMessage(playerid, COLOR_RED, "[INFO:] Twoja posta� umar�a ! Mo�esz teraz wyj�� z gry i zarejestrowa� now� lub wys�a� smsa wskrzesaj�cego Twoj� posta�.");
		// gPlayerLogged[playerid] = 0;
		// Kick(playerid);
	// }
// }