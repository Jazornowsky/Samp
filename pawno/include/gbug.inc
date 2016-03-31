/*
This include prevents the bug where if you press G to enter a vehicle as a passenger and after 3 seconds entry isn't achieved you are teleported inside.
This is abusable as a player may start to enter an enemy player's vehicle, the enemy may drive off leaving the passenger still running after the car but
he will be teleported inside.
*/

#include <YSI\y_hooks>

enum E_GBUG
{
	Float:gbug_carjack_playerpos[3],
	gbug_playerenteringveh,
	gbug_pentervtick
	
}
new gBugPlayerData[MAX_PLAYERS][E_GBUG];

Hook:gbug_OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
	if(!ispassenger) return 1;
	gBugPlayerData[playerid][gbug_pentervtick] = GetTickCount();
	GetPlayerPos(playerid, gBugPlayerData[playerid][gbug_carjack_playerpos][0], gBugPlayerData[playerid][gbug_carjack_playerpos][1], gBugPlayerData[playerid][gbug_carjack_playerpos][2]);
	gBugPlayerData[playerid][gbug_playerenteringveh] = 1;
	//SendClientMessage(playerid, -1, "Starting to enter vehicle..");
	return 1;
}

Hook:gbug_OnPlayerStateChange(playerid, newstate, oldstate)
{
	if(newstate == 3) // Entered vehicle
	{
		if(gBugPlayerData[playerid][gbug_playerenteringveh] == 1 || gBugPlayerData[playerid][gbug_playerenteringveh] == 2)
		{
			SetPlayerPos(playerid, gBugPlayerData[playerid][gbug_carjack_playerpos][0], gBugPlayerData[playerid][gbug_carjack_playerpos][1], gBugPlayerData[playerid][gbug_carjack_playerpos][2]);
			gBugPlayerData[playerid][gbug_playerenteringveh] = 0;
			//SendClientMessage(playerid, -1, "Entry denied");
			GameTextForPlayer(playerid, "~R~entry denied", 3000, 3);
		}
		else
		{
			gBugPlayerData[playerid][gbug_playerenteringveh] = 0;
			//SendClientMessage(playerid, -1, "Entry accepted");
		}
	}
	return 1;
}

stock gbug_PutPlayerInVehicle(playerid, vehicleid, seatid)
{
	gBugPlayerData[playerid][gbug_playerenteringveh] = 0;
	PutPlayerInVehicle(playerid, vehicleid, seatid);
	return 1;
}

#if defined _ALS_PutPlayerInVehicle
	#undef PutPlayerInVehicle
#else
	#define _ALS_PutPlayerInVehicle
#endif
#define PutPlayerInVehicle  gbug_PutPlayerInVehicle

Hook:gbug_OnPlayerUpdate(playerid)
{
	if(gBugPlayerData[playerid][gbug_playerenteringveh] == 0) return 1; // Not handling

	new Float:x, Float:y, Float:z;
	GetPlayerVelocity(playerid, x, y, z);

	if(gBugPlayerData[playerid][gbug_playerenteringveh] == 3 && GetPlayerSpecialAction(playerid) != SPECIAL_ACTION_ENTER_VEHICLE)
	{
		gBugPlayerData[playerid][gbug_playerenteringveh] = 0;
		//SendClientMessage(playerid, -1, "Cancelled entry while stepping in");
		return 1;
	}
	
	if(x == 0 && y == 0 && z == 0) // Standing still, did they get in?
	{
		if(gBugPlayerData[playerid][gbug_playerenteringveh] != 3)
		{
			if(GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_ENTER_VEHICLE)
			{
				if(gBugPlayerData[playerid][gbug_playerenteringveh] == 2) // Stepping in
				{
					gBugPlayerData[playerid][gbug_playerenteringveh] = 3;
					//SendClientMessage(playerid, -1, "Stepping in");
				}
				else
				{
					gBugPlayerData[playerid][gbug_playerenteringveh] = 2; // Stepping in?
					//SendClientMessage(playerid, -1, "Stepping in?");
					gBugPlayerData[playerid][gbug_pentervtick] = GetTickCount();
				}
			}
			else // Cancelled entry
			{
				gBugPlayerData[playerid][gbug_playerenteringveh] = 0;
				//SendClientMessage(playerid, -1, "Cancelled entry while running to door");
			}
		}
	}
	return 1;
}