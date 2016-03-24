#include <a_samp>
/*
	This FS was created by Quincy_Gatlin, I was just bored and I
 	wanted to show how the NPC's worked, and just to show them off.
 	Edit this in any way you wish, basically they just either walk,
 	drive or fly around, if you can catch them sitting still you
 	can press "G" to get into the vehicle and ride around with them.
	You can't kill them I don't believe, but I heard you could with
	a spray can, who knows, give it a try.
	
	Credits:
	Quincy_Gatlin for creating and coding this FS.
	Kye and the SA:MP crew for developing SA:MP 0.3X and making it possible to have NPCs.
 	And anyone else who has contributed to SA:MP and the developing of NPCs.
*/

#define FILTERSCRIPT

#if defined FILTERSCRIPT

new PhoenixCar;
new DodoPlane;

public OnFilterScriptInit()
{
	print("\n--------------------------------------");
	print(" NPC Filterscript by Quincy Gatlin");
	print("Have fun editing and playing around with NPCs\n");
	print("--------------------------------------\n");

	ConnectNPC("Beach_Fella","Pier(Walking)");
	ConnectNPC("Phoenix_Driver","LS(Driving1)");
	ConnectNPC("LS_Flyer","Flyer");
	ConnectNPC("OG_LOC","Grove(Walking)");
	
	DodoPlane = CreateVehicle(593, 0, 0, 0, 0, -1, -1, 60000);
	PhoenixCar = CreateVehicle(603, 0,0,0,0, 0, 0, 60000);
	return 1;
}

public OnFilterScriptExit()
{
	return 1;
}

#else

#endif

public OnPlayerSpawn(playerid)
{
    if(IsPlayerNPC(playerid)) //Checks if the player that just spawned is an NPC.
    {
        new npcname[MAX_PLAYER_NAME];
        GetPlayerName(playerid, npcname, sizeof(npcname)); //Getting the NPC's name.
        if(!strcmp(npcname, "Beach_Fella", true)) //Checking if the NPC's name is Correct
        {
            SetPlayerSkin(playerid, 45);
        }
        if(!strcmp(npcname, "Phoenix_Driver", true)) //Checking if the NPC's name is Correct
        {
            PutPlayerInVehicle(playerid, PhoenixCar, 0); //Putting the NPC into the vehicle we created for it.
            AddVehicleComponent(GetPlayerVehicleID(playerid), 1010);
            AddVehicleComponent(GetPlayerVehicleID(playerid), 1087);
            AddVehicleComponent(GetPlayerVehicleID(playerid), 1079);
            SetPlayerSkin(playerid, 73);
        }
        if(!strcmp(npcname, "LS_Flyer", true)) //Checking if the NPC's name is Correct
        {
            PutPlayerInVehicle(playerid, DodoPlane, 0); //Putting the NPC into the vehicle we created for it.
            SetPlayerSkin(playerid, 53);
        }
        if(!strcmp(npcname, "OG_LOC", true)) //Checking if the NPC's name is Correct
        {
            SetPlayerSkin(playerid, 293);
            GivePlayerWeapon(playerid, 22, 9999);
        }
        return 1;
    }
	return 1;
}
