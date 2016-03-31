/***
*
* File: wp_bw.inc
* Auth: Damian Wojdat
* Date: 15.09.2011
* Desc: Handle part of player rp death state.
*
*************************************************************************************************************/

stock BW(playerid, time = 0)
{
	if(!AdminDuty[playerid])
	{
		// SetPlayerCameraPos( playerid, gPlayerData[playerid][pCrashX], gPlayerData[playerid][pCrashY], gPlayerData[playerid][pCrashZ]+5.0 );
		// SetPlayerCameraLookAt( playerid,gPlayerData[playerid][pCrashX], gPlayerData[playerid][pCrashY], gPlayerData[playerid][pCrashZ]+10.0 );
		if(time == 0)
		{
			new distance = GetDistanceToPoint(playerid, -1371.530, -248.258, 0.0);
			gPlayerData[playerid][pCharacterDying] = distance;
			new medCount = 0;
			foreach(Player, i)
			{
				if(!gPlayerLogged[playerid])
					continue;
				if(gPlayerData[i][pFaction] == FACTIONID_MEDICS)
				{
					medCount++;
					break;
				}
			}
			if(medCount)
			{
				if(gPlayerData[playerid][pCharacterDying] < 900)
					gPlayerData[playerid][pCharacterDying] = 900;
				if(gPlayerData[playerid][pCharacterDying] > 1800)
					gPlayerData[playerid][pCharacterDying] = 1800;
			}
			else
			{
				if(gPlayerData[playerid][pCharacterDying] < 350)
					gPlayerData[playerid][pCharacterDying] = 350;
				if(gPlayerData[playerid][pCharacterDying] > 900)
					gPlayerData[playerid][pCharacterDying] = 900;
			}
		}
		else
			gPlayerData[playerid][pCharacterDying] = time;
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Stan twojej postaci jest krytyczny !");
		// SetPlayerHealth(playerid, 99999);
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