//
// Keeps the in game time synced to the server's time and
// draws the current time on the player's hud using a textdraw/
// (1 minute = 1 minute real world time)
//
//  Kye 2009

#include <a_samp>
#pragma tabsize 0

//--------------------------------------------------

new hour, minute;

forward UpdateTime();

//--------------------------------------------------


public UpdateTime()
{
    gettime(hour, minute);
   	// format(timestr,32,"%02d:%02d",hour,minute);
   	// TextDrawSetString(txtTimeDisp,timestr);
   	
   	SetWorldTime(hour);
   	
	new x=0;
	while(x!=MAX_PLAYERS) {
	    if(IsPlayerConnected(x) && GetPlayerState(x) != PLAYER_STATE_NONE) {
	        SetPlayerTime(x,hour,minute);
		 }
		 x++;
	}
}

//--------------------------------------------------

public OnGameModeInit()
{	
	UpdateTime();
	SetTimer("UpdateTime",1000*60,1);

	return 1;
}

//--------------------------------------------------

public OnPlayerSpawn(playerid)
{
	// gettime(hour, minute);
	// SetPlayerTime(playerid,hour,minute);
	
	return 1;
}

//--------------------------------------------------

public OnPlayerDeath(playerid, killerid, reason)
{
 	return 1;
}

//--------------------------------------------------

public OnPlayerConnect(playerid)
{
    gettime(hour, minute);
    SetPlayerTime(playerid,hour,minute);
    return 1;
}

//--------------------------------------------------
