/***
*
* File: wp_utils_anticheat.inc
* Auth: Damian Wojdat
* Date: 18.04.2012
* Desc: Internal script function related to anticheat.
*
*************************************************************************************************************/

stock SetPlayerToPos(playerid,Float:x,Float:y,Float:z)
{
	if(IsPlayerConnected(playerid))
	{
		SetPlayerPos(playerid,x,y,z);
  		NewPos[playerid][0] = x;
    	NewPos[playerid][1] = y;
     	NewPos[playerid][2] = z;
      	PosHackCheckTime[playerid] = 5;
       	return 1;
	}
	return 0;
}

stock antiHealthHack(playerid)
{
	if(!AdminDuty[playerid])
	{
		new Float:antiCheatHP, Float:antiCheatArmor;
		new string[128];
		
		GetPlayerHealth(playerid, antiCheatHP);
		GetPlayerArmour(playerid, antiCheatArmor);
		
		if(floatround(gPlayerData[playerid][pHP], floatround_floor) != antiCheatHP && gPlayerData[playerid][pHP] != 0.0)
		{
			SendClientMessage(playerid, COLOR_RED, "[ANTI-CHEAT:] Zosta³eœ wyrzucony za u¿ywanie cheatów !");
			format(string, sizeof(string), "[ANTI-CHEAT:] %s has been kicked for using Health Hack", gPlayerData[playerid][pName]);
			ABroadCast(COLOR_YELLOW, string, 1);
			Kick(playerid);
		}
		if(floatround(gPlayerData[playerid][pArmour], floatround_floor) != antiCheatArmor && gPlayerData[playerid][pArmour] != 0.0)
		{
			SendClientMessage(playerid, COLOR_RED, "[ANTI-CHEAT:] Zosta³eœ wyrzucony za u¿ywanie cheatów !");
			format(string, sizeof(string), "[ANTI-CHEAT:] %s has been kicked for using Armour Hack", gPlayerData[playerid][pName]);
			ABroadCast(COLOR_YELLOW, string, 1);
			Kick(playerid);
		}
	}	
	gPlayerVars[playerid][mAntiCheatTimer] = -1;
}

// stock TogglePlayerControllable(playerid, toggle)
// {
	// gPlayerVars[playerid][mPlayerControllable] = toggle;
	// TogglePlayerControllable(playerid, toggle);
// }