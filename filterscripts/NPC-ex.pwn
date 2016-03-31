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

public OnFilterScriptInit()
{
	//ConnectNPC("Czarek", "bus_mg_pc");
	//ConnectNPC("Jurek", "bus_mg_bb_dm");
	ConnectNPC("Monika", "idle");
	ConnectNPC("Anna", "idle");
	ConnectNPC("UrzednikFC1", "idle");
	ConnectNPC("UrzednikFC2", "idle");
	ConnectNPC("UrzednikBS1", "idle");
	ConnectNPC("UrzednikBS2", "idle");
	ConnectNPC("UrzednikLV1", "idle");
	ConnectNPC("UrzednikLV2", "idle");
	ConnectNPC("UrzednikLS1", "idle");
	ConnectNPC("UrzednikLS2", "idle");
	ConnectNPC("UrzednikSF1", "idle");
	ConnectNPC("UrzednikSF2", "idle");
	ConnectNPC("UrzednikAP1", "idle");
	ConnectNPC("UrzednikAP2", "idle");
	ConnectNPC("MedykSF", "idle");
	ConnectNPC("MedykLV", "idle");
	ConnectNPC("MedykLS", "idle");
	ConnectNPC("MedykLS2", "idle");
	ConnectNPC("MedykMG", "idle");
	ConnectNPC("MedykFC", "idle");
	ConnectNPC("MedykAP", "idle");
	ConnectNPC("MedykEQ", "idle");
	return 1;
}

public OnPlayerSpawn(playerid)
{
	if(!IsPlayerNPC(playerid))
	{
		return 1;
	}
	
	new playername[MAX_PLAYER_NAME];
	GetPlayerName(playerid, playername, sizeof(playername));
	
	
	// Urzednicy
	
	// SF
	if(!strcmp(playername, "UrzednikSF1", true))
	{
		SetPlayerColor(playerid, 0xFFFFFFFF);
		SetPlayerVirtualWorld(playerid, 11);
		SetPlayerPos(playerid, 356.25, 169.21, 1008.37);
		SetPlayerFacingAngle(playerid, 272.82);
	}	
	if(!strcmp(playername, "UrzednikSF2", true))
	{
		SetPlayerColor(playerid, 0xFFFFFFFF);
		SetPlayerVirtualWorld(playerid, 11);
		SetPlayerPos(playerid, 356.29, 178.66, 1008.37);
		SetPlayerFacingAngle(playerid, 271.53);
	}
	
	// LS
	if(!strcmp(playername, "UrzednikLS1", true))
	{
		SetPlayerColor(playerid, 0xFFFFFFFF);
		SetPlayerVirtualWorld(playerid, 12);
		SetPlayerPos(playerid, 356.25, 169.21, 1008.37);
		SetPlayerFacingAngle(playerid, 272.82);
	}	
	if(!strcmp(playername, "UrzednikLS2", true))
	{
		SetPlayerColor(playerid, 0xFFFFFFFF);
		SetPlayerVirtualWorld(playerid, 12);
		SetPlayerPos(playerid, 356.29, 178.66, 1008.37);
		SetPlayerFacingAngle(playerid, 271.53);
	}
	
	// LV
	if(!strcmp(playername, "UrzednikLV1", true))
	{
		SetPlayerColor(playerid, 0xFFFFFFFF);
		SetPlayerVirtualWorld(playerid, 13);
		SetPlayerPos(playerid, 356.25, 169.21, 1008.37);
		SetPlayerFacingAngle(playerid, 272.82);
	}	
	if(!strcmp(playername, "UrzednikLV2", true))
	{
		SetPlayerColor(playerid, 0xFFFFFFFF);
		SetPlayerVirtualWorld(playerid, 13);
		SetPlayerPos(playerid, 356.29, 178.66, 1008.37);
		SetPlayerFacingAngle(playerid, 271.53);
	}
	
	// FC
	if(!strcmp(playername, "UrzednikFC1", true))
	{
		SetPlayerColor(playerid, 0xFFFFFFFF);
		SetPlayerVirtualWorld(playerid, 14);
		SetPlayerPos(playerid, 356.25, 169.21, 1008.37);
		SetPlayerFacingAngle(playerid, 272.82);
	}	
	if(!strcmp(playername, "UrzednikFC2", true))
	{
		SetPlayerColor(playerid, 0xFFFFFFFF);
		SetPlayerVirtualWorld(playerid, 14);
		SetPlayerPos(playerid, 356.29, 178.66, 1008.37);
		SetPlayerFacingAngle(playerid, 271.53);
	}
	
	// MG
	if(!strcmp(playername, "Monika", true))
	{
		SetPlayerColor(playerid, 0xFFFFFFFF);
		SetPlayerVirtualWorld(playerid, 15);
		SetPlayerPos(playerid, 356.25, 169.21, 1008.37);
		SetPlayerFacingAngle(playerid, 272.82);
	}	
	if(!strcmp(playername, "Anna", true))
	{
		SetPlayerColor(playerid, 0xFFFFFFFF);
		SetPlayerVirtualWorld(playerid, 15);
		SetPlayerPos(playerid, 356.29, 178.66, 1008.37);
		SetPlayerFacingAngle(playerid, 271.53);
	}
	
	// BS
	if(!strcmp(playername, "UrzednikBS1", true))
	{
		SetPlayerColor(playerid, 0xFFFFFFFF);
		SetPlayerVirtualWorld(playerid, 16);
		SetPlayerPos(playerid, 356.25, 169.21, 1008.37);
		SetPlayerFacingAngle(playerid, 272.82);
	}	
	if(!strcmp(playername, "UrzednikBS2", true))
	{
		SetPlayerColor(playerid, 0xFFFFFFFF);
		SetPlayerVirtualWorld(playerid, 16);
		SetPlayerPos(playerid, 356.29, 178.66, 1008.37);
		SetPlayerFacingAngle(playerid, 271.53);
	}
	
	// AP
	if(!strcmp(playername, "UrzednikAP1", true))
	{
		SetPlayerColor(playerid, 0xFFFFFFFF);
		SetPlayerVirtualWorld(playerid, 17);
		SetPlayerPos(playerid, 356.25, 169.21, 1008.37);
		SetPlayerFacingAngle(playerid, 272.82);
	}	
	if(!strcmp(playername, "UrzednikAP2", true))
	{
		SetPlayerColor(playerid, 0xFFFFFFFF);
		SetPlayerVirtualWorld(playerid, 17);
		SetPlayerPos(playerid, 356.29, 178.66, 1008.37);
		SetPlayerFacingAngle(playerid, 271.53);
	}
	
	
	//Medycy
	
	//SF	
	if(!strcmp(playername, "MedykSF", true))
	{
		SetPlayerColor(playerid, 0xFFFFFFFF);
		SetPlayerVirtualWorld(playerid, 21);
		SetPlayerPos(playerid, -2675.40, 649.16, 10.29);
		SetPlayerFacingAngle(playerid, 357.99);
	}
	//LV	
	if(!strcmp(playername, "MedykLV", true))
	{
		SetPlayerColor(playerid, 0xFFFFFFFF);
		SetPlayerVirtualWorld(playerid, 22);
		SetPlayerPos(playerid, -2675.40, 649.16, 10.29);
		SetPlayerFacingAngle(playerid, 357.99);
	}
	//LS	
	if(!strcmp(playername, "MedykLS", true))
	{
		SetPlayerColor(playerid, 0xFFFFFFFF);
		SetPlayerVirtualWorld(playerid, 23);
		SetPlayerPos(playerid, -2675.40, 649.16, 10.29);
		SetPlayerFacingAngle(playerid, 357.99);
	}
	//LS2	
	if(!strcmp(playername, "MedykLS2", true))
	{
		SetPlayerColor(playerid, 0xFFFFFFFF);
		SetPlayerVirtualWorld(playerid, 24);
		SetPlayerPos(playerid, -2675.40, 649.16, 10.29);
		SetPlayerFacingAngle(playerid, 357.99);
	}
	//MG	
	if(!strcmp(playername, "MedykMG", true))
	{
		SetPlayerColor(playerid, 0xFFFFFFFF);
		SetPlayerVirtualWorld(playerid, 25);
		SetPlayerPos(playerid, 1123.64, -2520.28, 113.81);
		SetPlayerFacingAngle(playerid, 269.26);
	}
	//FC	
	if(!strcmp(playername, "MedykFC", true))
	{
		SetPlayerColor(playerid, 0xFFFFFFFF);
		SetPlayerVirtualWorld(playerid, 26);
		SetPlayerPos(playerid, 1123.64, -2520.28, 113.81);
		SetPlayerFacingAngle(playerid, 269.26);
	}
	//AP	
	if(!strcmp(playername, "MedykAP", true))
	{
		SetPlayerColor(playerid, 0xFFFFFFFF);
		SetPlayerVirtualWorld(playerid, 27);
		SetPlayerPos(playerid, 1123.64, -2520.28, 113.81);
		SetPlayerFacingAngle(playerid, 269.26);
	}
	//EQ
	if(!strcmp(playername, "MedykAP", true))
	{
		SetPlayerColor(playerid, 0xFFFFFFFF);
		SetPlayerVirtualWorld(playerid, 28);
		SetPlayerPos(playerid, 1123.64, -2520.28, 113.81);
		SetPlayerFacingAngle(playerid, 269.26);
	}
	
	if(!strcmp(playername, "Czarek", true))
	{
		SetPlayerColor(playerid,0xFFFFFFFF); // Chose any color you want, this is currently white
        PutPlayerInVehicle(playerid, 1999, 0);
    }
	if(!strcmp(playername, "Jurek", true))
	{
		SetPlayerColor(playerid,0xFFFFFFFF); // Chose any color you want, this is currently white
        PutPlayerInVehicle(playerid, 1998, 0);
    }
	
	return 1;
}

public OnPlayerRequestClass(playerid, classid)
{
	if(!IsPlayerNPC(playerid))
	{
		return 0;
	}
	
	new playername[MAX_PLAYER_NAME];
	GetPlayerName(playerid, playername, sizeof(playername));
	if(!strcmp(playername, "Monika", true))
	{
		SetSpawnInfo(playerid, 0, 150, 356.25, 169.21, 1008.37, 272.82, 0, 0, 0, 0, 0, 0);
	}
	if(!strcmp(playername, "Anna", true))
	{
		SetSpawnInfo(playerid, 0, 141, 356.25, 169.21, 1008.37, 272.82, 0, 0, 0, 0, 0, 0);
	}
	if(!strcmp(playername, "UrzednikFC1", true))
	{
		SetSpawnInfo(playerid, 0, 141, 356.25, 169.21, 1008.37, 272.82, 0, 0, 0, 0, 0, 0);
	}
	if(!strcmp(playername, "UrzednikFC2", true))
	{
		SetSpawnInfo(playerid, 0, 150, 356.25, 169.21, 1008.37, 272.82, 0, 0, 0, 0, 0, 0);
	}
	if(!strcmp(playername, "UrzednikBS1", true))
	{
		SetSpawnInfo(playerid, 0, 141, 356.25, 169.21, 1008.37, 272.82, 0, 0, 0, 0, 0, 0);
	}
	if(!strcmp(playername, "UrzednikBS2", true))
	{
		SetSpawnInfo(playerid, 0, 150, 356.25, 169.21, 1008.37, 272.82, 0, 0, 0, 0, 0, 0);
	}
	if(!strcmp(playername, "UrzednikLV1", true))
	{
		SetSpawnInfo(playerid, 0, 141, 356.25, 169.21, 1008.37, 272.82, 0, 0, 0, 0, 0, 0);
	}
	if(!strcmp(playername, "UrzednikLV2", true))
	{
		SetSpawnInfo(playerid, 0, 150, 356.25, 169.21, 1008.37, 272.82, 0, 0, 0, 0, 0, 0);
	}
	if(!strcmp(playername, "UrzednikLS1", true))
	{
		SetSpawnInfo(playerid, 0, 141, 356.25, 169.21, 1008.37, 272.82, 0, 0, 0, 0, 0, 0);
	}
	if(!strcmp(playername, "UrzednikLS2", true))
	{
		SetSpawnInfo(playerid, 0, 150, 356.25, 169.21, 1008.37, 272.82, 0, 0, 0, 0, 0, 0);
	}
	if(!strcmp(playername, "UrzednikSF1", true))
	{
		SetSpawnInfo(playerid, 0, 141, 356.25, 169.21, 1008.37, 272.82, 0, 0, 0, 0, 0, 0);
	}
	if(!strcmp(playername, "UrzednikSF2", true))
	{
		SetSpawnInfo(playerid, 0, 150, 356.25, 169.21, 1008.37, 272.82, 0, 0, 0, 0, 0, 0);
	}
	if(!strcmp(playername, "UrzednikAP1", true))
	{
		SetSpawnInfo(playerid, 0, 141, 356.25, 169.21, 1008.37, 272.82, 0, 0, 0, 0, 0, 0);
	}
	if(!strcmp(playername, "UrzednikAP2", true))
	{
		SetSpawnInfo(playerid, 0, 150, 356.25, 169.21, 1008.37, 272.82, 0, 0, 0, 0, 0, 0);
	}
	
	if(!strcmp(playername, "MedykSF", true))
	{
		SetSpawnInfo(playerid, 0, 276, 356.25, 169.21, 1008.37, 272.82, 0, 0, 0, 0, 0, 0);
	}
	if(!strcmp(playername, "MedykLV", true))
	{
		SetSpawnInfo(playerid, 0, 276, 356.25, 169.21, 1008.37, 272.82, 0, 0, 0, 0, 0, 0);
	}
	if(!strcmp(playername, "MedykLS", true))
	{
		SetSpawnInfo(playerid, 0, 276, 356.25, 169.21, 1008.37, 272.82, 0, 0, 0, 0, 0, 0);
	}
	if(!strcmp(playername, "MedykLS2", true))
	{
		SetSpawnInfo(playerid, 0, 276, 356.25, 169.21, 1008.37, 272.82, 0, 0, 0, 0, 0, 0);
	}
	if(!strcmp(playername, "MedykMG", true))
	{
		SetSpawnInfo(playerid, 0, 276, 356.25, 169.21, 1008.37, 272.82, 0, 0, 0, 0, 0, 0);
	}
	if(!strcmp(playername, "MedykFC", true))
	{
		SetSpawnInfo(playerid, 0, 276, 356.25, 169.21, 1008.37, 272.82, 0, 0, 0, 0, 0, 0);
	}
	if(!strcmp(playername, "MedykAP", true))
	{
		SetSpawnInfo(playerid, 0, 276, 356.25, 169.21, 1008.37, 272.82, 0, 0, 0, 0, 0, 0);
	}
	if(!strcmp(playername, "MedykEQ", true))
	{
		SetSpawnInfo(playerid, 0, 276, 356.25, 169.21, 1008.37, 272.82, 0, 0, 0, 0, 0, 0);
	}
	
	if(!strcmp(playername, "Czarek", true))
	{
		SetSpawnInfo( playerid, 0, 255, 1958.33, 1343.12, 15.36, 269.15, 0, 0, 0, 0, 0, 0 );
    }
	if(!strcmp(playername, "Jurek", true))
	{
		SetSpawnInfo( playerid, 0, 255, 1958.33, 1343.12, 15.36, 269.15, 0, 0, 0, 0, 0, 0 );
    }
	
	return 0;
}

public OnPlayerConnect(playerid)
{
	
	return 1;
}
	
