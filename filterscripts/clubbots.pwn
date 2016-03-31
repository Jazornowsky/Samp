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
	ConnectNPC("Clubber1", "idle");
	ConnectNPC("Clubber2", "idle");
	ConnectNPC("Clubber3", "idle");
	ConnectNPC("Clubber4", "idle");
	ConnectNPC("Clubber5", "idle");
	ConnectNPC("Clubber6", "idle");
	ConnectNPC("Clubber7", "idle");
	ConnectNPC("Clubber8", "idle");
	ConnectNPC("Clubber9", "idle");
	ConnectNPC("Clubber10", "idle");
	ConnectNPC("Clubber11", "idle");
	ConnectNPC("Clubber12", "idle");
	ConnectNPC("Clubber13", "idle");
	ConnectNPC("Clubber14", "idle");
	ConnectNPC("Clubber15", "idle");
	ConnectNPC("Clubber16", "idle");
	ConnectNPC("Clubber17", "idle");
	ConnectNPC("Clubber18", "idle");
	ConnectNPC("Clubber19", "idle");
	ConnectNPC("Clubber20", "idle");
	ConnectNPC("Clubber21", "idle");
	ConnectNPC("Clubber22", "idle");
	ConnectNPC("Clubber23", "idle");
	ConnectNPC("Clubber24", "idle");
	ConnectNPC("Clubber25", "idle");
	ConnectNPC("Clubber26", "idle");
	ConnectNPC("Clubber27", "idle");
	ConnectNPC("Clubber28", "idle");
	ConnectNPC("Clubber29", "idle");
	ConnectNPC("Clubber30", "idle");
	ConnectNPC("Clubber31", "idle");
	ConnectNPC("Clubber32", "idle");
	ConnectNPC("Clubber33", "idle");
	ConnectNPC("Clubber34", "idle");
	ConnectNPC("Clubber35", "idle");
	ConnectNPC("Clubber36", "idle");
	ConnectNPC("Clubber37", "idle");
	ConnectNPC("Clubber38", "idle");
	ConnectNPC("Clubber39", "idle");
	ConnectNPC("Clubber40", "idle");
	ConnectNPC("Clubber41", "idle");
	ConnectNPC("Clubber42", "idle");
	ConnectNPC("Clubber43", "idle");
	ConnectNPC("Clubber44", "idle");
	ConnectNPC("Clubber45", "idle");
	ConnectNPC("Clubber46", "idle");
	ConnectNPC("Clubber47", "idle");
	ConnectNPC("Clubber48", "idle");
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
	
	if(!strcmp(playername, "Clubber1", true))
	{
		ApplyAnimation(playerid, "STRIP", "strip_A", 4.1, 0, 1, 1, 1, 1, 1);
		ApplyAnimation(playerid, "STRIP", "strip_A", 4.1, 0, 1, 1, 1, 1, 1);
	}
	else if(!strcmp(playername, "Clubber2", true))
	{
		ApplyAnimation(playerid, "STRIP", "strip_B", 4.1, 0, 1, 1, 1, 1, 1);
		ApplyAnimation(playerid, "STRIP", "strip_B", 4.1, 0, 1, 1, 1, 1, 1);
	}
	else if(!strcmp(playername, "Clubber3", true))
	{
		ApplyAnimation(playerid, "DANCING", "dnce_M_d", 4.1, 0, 1, 1, 1, 1, 1);
		ApplyAnimation(playerid, "DANCING", "dnce_M_d", 4.1, 0, 1, 1, 1, 1, 1);
	}
	else if(!strcmp(playername, "Clubber4", true))
	{
		ApplyAnimation(playerid, "DANCING", "dnce_M_e", 4.1, 0, 1, 1, 1, 1, 1);
		ApplyAnimation(playerid, "DANCING", "dnce_M_e", 4.1, 0, 1, 1, 1, 1, 1);
	}
	else if(!strcmp(playername, "Clubber5", true))
	{
		ApplyAnimation(playerid, "STRIP", "strip_G", 4.1, 0, 1, 1, 1, 1, 1);
		ApplyAnimation(playerid, "STRIP", "strip_G", 4.1, 0, 1, 1, 1, 1, 1);
	}
	else if(!strcmp(playername, "Clubber6", true))
	{
		ApplyAnimation(playerid, "STRIP", "STR_B2C", 4.1, 0, 1, 1, 1, 1, 1);
		ApplyAnimation(playerid, "STRIP", "STR_B2C", 4.1, 0, 1, 1, 1, 1, 1);
	}
	else if(!strcmp(playername, "Clubber7", true))
	{
		ApplyAnimation(playerid, "DANCING", "bd_clap", 4.1, 0, 1, 1, 1, 1, 1);
		ApplyAnimation(playerid, "DANCING", "bd_clap", 4.1, 0, 1, 1, 1, 1, 1);
	}
	else if(!strcmp(playername, "Clubber8", true))
	{
		ApplyAnimation(playerid, "DANCING", "bd_clap1", 4.1, 0, 1, 1, 1, 1, 1);
		ApplyAnimation(playerid, "DANCING", "bd_clap1", 4.1, 0, 1, 1, 1, 1, 1);
	}
	else if(!strcmp(playername, "Clubber9", true))
	{
		ApplyAnimation(playerid, "DANCING", "dance_loop", 4.1, 0, 1, 1, 1, 1, 1);
		ApplyAnimation(playerid, "DANCING", "dance_loop", 4.1, 0, 1, 1, 1, 1, 1);
	}
	else if(!strcmp(playername, "Clubber10", true))
	{
		ApplyAnimation(playerid, "DANCING", "DAN_Down_A", 4.1, 0, 1, 1, 1, 1, 1);
		ApplyAnimation(playerid, "DANCING", "DAN_Down_A", 4.1, 0, 1, 1, 1, 1, 1);
	}
	else if(!strcmp(playername, "Clubber11", true))
	{
		ApplyAnimation(playerid, "DANCING", "DAN_Left_A", 4.1, 0, 1, 1, 1, 1, 1);
		ApplyAnimation(playerid, "DANCING", "DAN_Left_A", 4.1, 0, 1, 1, 1, 1, 1);
	}
	else if(!strcmp(playername, "Clubber12", true))
	{
		ApplyAnimation(playerid, "DANCING", "DAN_Loop_A", 4.1, 0, 1, 1, 1, 1, 1);
		ApplyAnimation(playerid, "DANCING", "DAN_Loop_A", 4.1, 0, 1, 1, 1, 1, 1);
	}
	else if(!strcmp(playername, "Clubber13", true))
	{
		ApplyAnimation(playerid, "DANCING", "DAN_Right_A", 4.1, 0, 1, 1, 1, 1, 1);
		ApplyAnimation(playerid, "DANCING", "DAN_Right_A", 4.1, 0, 1, 1, 1, 1, 1);
	}
	else if(!strcmp(playername, "Clubber14", true))
	{
		ApplyAnimation(playerid, "DANCING", "DAN_Up_A", 4.1, 0, 1, 1, 1, 1, 1);
		ApplyAnimation(playerid, "DANCING", "DAN_Up_A", 4.1, 0, 1, 1, 1, 1, 1);
	}
	else if(!strcmp(playername, "Clubber15", true))
	{
		ApplyAnimation(playerid, "DANCING", "dnce_M_a", 4.1, 0, 1, 1, 1, 1, 1);
		ApplyAnimation(playerid, "DANCING", "dnce_M_a", 4.1, 0, 1, 1, 1, 1, 1);
	}
	else if(!strcmp(playername, "Clubber16", true))
	{
		ApplyAnimation(playerid, "DANCING", "dnce_M_b", 4.1, 0, 1, 1, 1, 1, 1);
		ApplyAnimation(playerid, "DANCING", "dnce_M_b", 4.1, 0, 1, 1, 1, 1, 1);
	}
	else if(!strcmp(playername, "Clubber17", true))
	{
		ApplyAnimation(playerid, "DANCING", "dnce_M_c", 4.1, 0, 1, 1, 1, 1, 1);
		ApplyAnimation(playerid, "DANCING", "dnce_M_c", 4.1, 0, 1, 1, 1, 1, 1);
	}
	else if(!strcmp(playername, "Clubber18", true))
	{
		ApplyAnimation(playerid, "DANCING", "dnce_M_d", 4.1, 0, 1, 1, 1, 1, 1);
		ApplyAnimation(playerid, "DANCING", "dnce_M_d", 4.1, 0, 1, 1, 1, 1, 1);
	}
	else if(!strcmp(playername, "Clubber19", true))
	{
		ApplyAnimation(playerid, "DANCING", "dnce_M_e", 4.1, 0, 1, 1, 1, 1, 1);
		ApplyAnimation(playerid, "DANCING", "dnce_M_e", 4.1, 0, 1, 1, 1, 1, 1);
	}
	else if(!strcmp(playername, "Clubber20", true))
	{
		ApplyAnimation(playerid, "DANCING", "dance_loop", 4.1, 0, 1, 1, 1, 1, 1);
		ApplyAnimation(playerid, "DANCING", "dance_loop", 4.1, 0, 1, 1, 1, 1, 1);
	}
	else if(!strcmp(playername, "Clubber21", true))
	{
		ApplyAnimation(playerid, "DANCING", "DAN_Down_A", 4.1, 0, 1, 1, 1, 1, 1);
		ApplyAnimation(playerid, "DANCING", "DAN_Down_A", 4.1, 0, 1, 1, 1, 1, 1);
	}
	else if(!strcmp(playername, "Clubber22", true))
	{
		ApplyAnimation(playerid, "STRIP", "strip_D", 4.1, 0, 1, 1, 1, 1, 1);
		ApplyAnimation(playerid, "STRIP", "strip_D", 4.1, 0, 1, 1, 1, 1, 1);
	}
	else if(!strcmp(playername, "Clubber23", true))
	{
		ApplyAnimation(playerid, "STRIP", "strip_F", 4.1, 0, 1, 1, 1, 1, 1);
		ApplyAnimation(playerid, "STRIP", "strip_F", 4.1, 0, 1, 1, 1, 1, 1);
	}
	else if(!strcmp(playername, "Clubber24", true))
	{
		ApplyAnimation(playerid, "DANCING", "DAN_Loop_A", 4.1, 0, 1, 1, 1, 1, 1);
		ApplyAnimation(playerid, "DANCING", "DAN_Loop_A", 4.1, 0, 1, 1, 1, 1, 1);
	}
	else if(!strcmp(playername, "Clubber25", true))
	{
		ApplyAnimation(playerid, "DANCING", "DAN_Right_A", 4.1, 0, 1, 1, 1, 1, 1);
		ApplyAnimation(playerid, "DANCING", "DAN_Right_A", 4.1, 0, 1, 1, 1, 1, 1);
	}
	else if(!strcmp(playername, "Clubber26", true))
	{
		ApplyAnimation(playerid, "DANCING", "DAN_Up_A", 4.1, 0, 1, 1, 1, 1, 1);
		ApplyAnimation(playerid, "DANCING", "DAN_Up_A", 4.1, 0, 1, 1, 1, 1, 1);
	}
	else if(!strcmp(playername, "Clubber27", true))
	{
		ApplyAnimation(playerid, "DANCING", "dnce_M_a", 4.1, 0, 1, 1, 1, 1, 1);
		ApplyAnimation(playerid, "DANCING", "dnce_M_a", 4.1, 0, 1, 1, 1, 1, 1);
	}
	else if(!strcmp(playername, "Clubber28", true))
	{
		ApplyAnimation(playerid, "DANCING", "dnce_M_b", 4.1, 0, 1, 1, 1, 1, 1);
		ApplyAnimation(playerid, "DANCING", "dnce_M_b", 4.1, 0, 1, 1, 1, 1, 1);
	}
	else if(!strcmp(playername, "Clubber29", true))
	{
		ApplyAnimation(playerid, "DANCING", "DAN_Down_A", 4.1, 0, 1, 1, 1, 1, 1);
		ApplyAnimation(playerid, "DANCING", "DAN_Down_A", 4.1, 0, 1, 1, 1, 1, 1);
	}
	else if(!strcmp(playername, "Clubber30", true))
	{
		ApplyAnimation(playerid, "PED", "XPRESSscratch", 4.1, 0, 1, 1, 1, 1, 1);
		ApplyAnimation(playerid, "PED", "XPRESSscratch", 4.1, 0, 1, 1, 1, 1, 1);
	}
	else if(!strcmp(playername, "Clubber31", true))
	{
		ApplyAnimation(playerid, "PED", "XPRESSscratch", 4.1, 0, 1, 1, 1, 1, 1);
		ApplyAnimation(playerid, "PED", "XPRESSscratch", 4.1, 0, 1, 1, 1, 1, 1);
	}
	else if(!strcmp(playername, "Clubber32", true))
	{
		ApplyAnimation(playerid, "PED", "WALK_start", 4.1, 0, 1, 1, 1, 1, 1);
		ApplyAnimation(playerid, "PED", "WALK_start", 4.1, 0, 1, 1, 1, 1, 1);
	}
	else if(!strcmp(playername, "Clubber33", true))
	{
		ApplyAnimation(playerid, "PED", "WALK_fat", 4.1, 0, 1, 1, 1, 1, 1);
		ApplyAnimation(playerid, "PED", "WALK_fat", 4.1, 0, 1, 1, 1, 1, 1);
	}
	else if(!strcmp(playername, "Clubber34", true))
	{
		ApplyAnimation(playerid, "PED", "WALK_start", 4.1, 0, 1, 1, 1, 1, 1);
		ApplyAnimation(playerid, "PED", "WALK_start", 4.1, 0, 1, 1, 1, 1, 1);
	}
	else if(!strcmp(playername, "Clubber35", true))
	{
		ApplyAnimation(playerid, "PED", "WALK_fat", 4.1, 0, 1, 1, 1, 1, 1);
		ApplyAnimation(playerid, "PED", "WALK_fat", 4.1, 0, 1, 1, 1, 1, 1);
	}
	else if(!strcmp(playername, "Clubber36", true))
	{
		ApplyAnimation(playerid, "PED", "WALK_start", 4.1, 0, 1, 1, 1, 1, 1);
		ApplyAnimation(playerid, "PED", "WALK_start", 4.1, 0, 1, 1, 1, 1, 1);
	}
	else if(!strcmp(playername, "Clubber37", true))
	{
		ApplyAnimation(playerid, "DANCING", "DAN_Up_A", 4.1, 0, 1, 1, 1, 1, 1);
		ApplyAnimation(playerid, "DANCING", "DAN_Up_A", 4.1, 0, 1, 1, 1, 1, 1);
	}
	else if(!strcmp(playername, "Clubber38", true))
	{
		ApplyAnimation(playerid, "DANCING", "dnce_M_a", 4.1, 0, 1, 1, 1, 1, 1);
		ApplyAnimation(playerid, "DANCING", "dnce_M_a", 4.1, 0, 1, 1, 1, 1, 1);
	}
	else if(!strcmp(playername, "Clubber39", true))
	{
		ApplyAnimation(playerid, "DANCING", "dnce_M_b", 4.1, 0, 1, 1, 1, 1, 1);
		ApplyAnimation(playerid, "DANCING", "dnce_M_b", 4.1, 0, 1, 1, 1, 1, 1);
	}
	else if(!strcmp(playername, "Clubber40", true))
	{
		ApplyAnimation(playerid, "DANCING", "dnce_M_c", 4.1, 0, 1, 1, 1, 1, 1);
		ApplyAnimation(playerid, "DANCING", "dnce_M_c", 4.1, 0, 1, 1, 1, 1, 1);
	}
	else if(!strcmp(playername, "Clubber41", true))
	{
		ApplyAnimation(playerid, "DANCING", "dnce_M_d", 4.1, 0, 1, 1, 1, 1, 1);
		ApplyAnimation(playerid, "DANCING", "dnce_M_d", 4.1, 0, 1, 1, 1, 1, 1);
	}
	else if(!strcmp(playername, "Clubber42", true))
	{
		ApplyAnimation(playerid, "PED", "WALK_fat", 4.1, 0, 1, 1, 1, 1, 1);
		ApplyAnimation(playerid, "PED", "WALK_fat", 4.1, 0, 1, 1, 1, 1, 1);
	}
	else if(!strcmp(playername, "Clubber43", true))
	{
		ApplyAnimation(playerid, "PED", "WALK_start", 4.1, 0, 1, 1, 1, 1, 1);
		ApplyAnimation(playerid, "PED", "WALK_start", 4.1, 0, 1, 1, 1, 1, 1);
	}
	else if(!strcmp(playername, "Clubber44", true))
	{
		ApplyAnimation(playerid, "PED", "WALK_fat", 4.1, 0, 1, 1, 1, 1, 1);
		ApplyAnimation(playerid, "PED", "WALK_fat", 4.1, 0, 1, 1, 1, 1, 1);
	}
	else if(!strcmp(playername, "Clubber45", true))
	{
		ApplyAnimation(playerid, "PED", "WALK_start", 4.1, 0, 1, 1, 1, 1, 1);
		ApplyAnimation(playerid, "PED", "WALK_start", 4.1, 0, 1, 1, 1, 1, 1);
	}
	else if(!strcmp(playername, "Clubber46", true))
	{
		ApplyAnimation(playerid, "PED", "abseil", 4.1, 0, 1, 1, 1, 1, 1);
		ApplyAnimation(playerid, "PED", "abseil", 4.1, 0, 1, 1, 1, 1, 1);
	}
	else if(!strcmp(playername, "Clubber47", true))
	{
		ApplyAnimation(playerid, "PED", "abseil", 4.1, 0, 1, 1, 1, 1, 1);
		ApplyAnimation(playerid, "PED", "abseil", 4.1, 0, 1, 1, 1, 1, 1);
	}
	else if(!strcmp(playername, "Clubber48", true))
	{
		ApplyAnimation(playerid, "PED", "woman_idlestance", 4.1, 0, 1, 1, 1, 1, 1);
		ApplyAnimation(playerid, "PED", "woman_idlestance", 4.1, 0, 1, 1, 1, 1, 1);
	}
	
	/*if(!strcmp(playername, "Clubber1", true))
	{
		SetPlayerColor(playerid, 0xFFFFFFFF);
		SetPlayerVirtualWorld(playerid, 0);
		SetPlayerPos(playerid, 2058.007, -1868.180, 14.743);
		SetPlayerFacingAngle(playerid, 0.82);
	}
	else if(!strcmp(playername, "Clubber2", true))
	{
		SetPlayerColor(playerid, 0xFFFFFFFF);
		SetPlayerVirtualWorld(playerid, 0);
		SetPlayerPos(playerid, 2057.033, -1870.014, 14.743);
		SetPlayerFacingAngle(playerid, 54.82);
	}
	else if(!strcmp(playername, "Clubber3", true))
	{
		SetPlayerColor(playerid, 0xFFFFFFFF);
		SetPlayerVirtualWorld(playerid, 0);
		SetPlayerPos(playerid, 2056.970, -1871.962, 14.743);
		SetPlayerFacingAngle(playerid, 31.82);
	}
	else if(!strcmp(playername, "Clubber4", true))
	{
		SetPlayerColor(playerid, 0xFFFFFFFF);
		SetPlayerVirtualWorld(playerid, 0);
		SetPlayerPos(playerid, 2055.038, -1871.827, 14.743);
		SetPlayerFacingAngle(playerid, 66.82);
	}
	else if(!strcmp(playername, "Clubber5", true))
	{
		SetPlayerColor(playerid, 0xFFFFFFFF);
		SetPlayerVirtualWorld(playerid, 0);
		SetPlayerPos(playerid, 2056.808, -1874.550, 14.743);
		SetPlayerFacingAngle(playerid, 45.82);
	}
	else if(!strcmp(playername, "Clubber6", true))
	{
		SetPlayerColor(playerid, 0xFFFFFFFF);
		SetPlayerVirtualWorld(playerid, 0);
		SetPlayerPos(playerid, 2057.062, -1877.366, 14.743);
		SetPlayerFacingAngle(playerid, 65.82);
	}
	else if(!strcmp(playername, "Clubber7", true))
	{
		SetPlayerColor(playerid, 0xFFFFFFFF);
		SetPlayerVirtualWorld(playerid, 0);
		SetPlayerPos(playerid, 2055.047, -1877.053, 14.743);
		SetPlayerFacingAngle(playerid, 99.82);
	}
	else if(!strcmp(playername, "Clubber8", true))
	{
		SetPlayerColor(playerid, 0xFFFFFFFF);
		SetPlayerVirtualWorld(playerid, 0);
		SetPlayerPos(playerid, 2054.780, -1879.363, 14.743);
		SetPlayerFacingAngle(playerid, 121.82);
	}
	else if(!strcmp(playername, "Clubber9", true))
	{
		SetPlayerColor(playerid, 0xFFFFFFFF);
		SetPlayerVirtualWorld(playerid, 0);
		SetPlayerPos(playerid, 2057.507, -1879.858, 14.743);
		SetPlayerFacingAngle(playerid, 58.82);
	}
	else if(!strcmp(playername, "Clubber10", true))
	{
		SetPlayerColor(playerid, 0xFFFFFFFF);
		SetPlayerVirtualWorld(playerid, 0);
		SetPlayerPos(playerid, 2057.896, -1882.090, 14.743);
		SetPlayerFacingAngle(playerid, 43.82);
	}
	else if(!strcmp(playername, "Clubber11", true))
	{
		SetPlayerColor(playerid, 0xFFFFFFFF);
		SetPlayerVirtualWorld(playerid, 0);
		SetPlayerPos(playerid, 2055.098, -1881.712, 14.743);
		SetPlayerFacingAngle(playerid, 290.82);
	}
	else if(!strcmp(playername, "Clubber12", true))
	{
		SetPlayerColor(playerid, 0xFFFFFFFF);
		SetPlayerVirtualWorld(playerid, 0);
		SetPlayerPos(playerid, 2054.416, -1877.394, 14.743);
		SetPlayerFacingAngle(playerid, 255.82);
	}
	else if(!strcmp(playername, "Clubber13", true))
	{
		SetPlayerColor(playerid, 0xFFFFFFFF);
		SetPlayerVirtualWorld(playerid, 0);
		SetPlayerPos(playerid, 2054.202, -1873.956, 14.743);
		SetPlayerFacingAngle(playerid, 41.82);
	}
	else if(!strcmp(playername, "Clubber14", true))
	{
		SetPlayerColor(playerid, 0xFFFFFFFF);
		SetPlayerVirtualWorld(playerid, 0);
		SetPlayerPos(playerid, 2056.218, -1870.349, 14.743);
		SetPlayerFacingAngle(playerid, 91.82);
	}
	else if(!strcmp(playername, "Clubber15", true))
	{
		SetPlayerColor(playerid, 0xFFFFFFFF);
		SetPlayerVirtualWorld(playerid, 0);
		SetPlayerPos(playerid, 2064.223, -1875.652, 13.564);
		SetPlayerFacingAngle(playerid, 61.82);
	}
	else if(!strcmp(playername, "Clubber16", true))
	{
		SetPlayerColor(playerid, 0xFFFFFFFF);
		SetPlayerVirtualWorld(playerid, 0);
		SetPlayerPos(playerid, 2066.350, -1875.691, 13.564);
		SetPlayerFacingAngle(playerid, 4.82);
	}
	else if(!strcmp(playername, "Clubber17", true))
	{
		SetPlayerColor(playerid, 0xFFFFFFFF);
		SetPlayerVirtualWorld(playerid, 0);
		SetPlayerPos(playerid, 2067.870, -1876.142, 13.564);
		SetPlayerFacingAngle(playerid, 351.82);
	}
	else if(!strcmp(playername, "Clubber18", true))
	{
		SetPlayerColor(playerid, 0xFFFFFFFF);
		SetPlayerVirtualWorld(playerid, 0);
		SetPlayerPos(playerid, 2069.831, -1875.879, 13.564);
		SetPlayerFacingAngle(playerid, 104.82);
	}
	else if(!strcmp(playername, "Clubber19", true))
	{
		SetPlayerColor(playerid, 0xFFFFFFFF);
		SetPlayerVirtualWorld(playerid, 0);
		SetPlayerPos(playerid, 2071.315, -1876.010, 13.564);
		SetPlayerFacingAngle(playerid, 91.82);
	}
	else if(!strcmp(playername, "Clubber20", true))
	{
		SetPlayerColor(playerid, 0xFFFFFFFF);
		SetPlayerVirtualWorld(playerid, 0);
		SetPlayerPos(playerid, 2070.039, -1874.004, 13.564);
		SetPlayerFacingAngle(playerid, 54.82);
	}
	else if(!strcmp(playername, "Clubber21", true))
	{
		SetPlayerColor(playerid, 0xFFFFFFFF);
		SetPlayerVirtualWorld(playerid, 0);
		SetPlayerPos(playerid, 2067.837, -1874.239, 13.564);
		SetPlayerFacingAngle(playerid, 5.82);
	}
	else if(!strcmp(playername, "Clubber22", true))
	{
		SetPlayerColor(playerid, 0xFFFFFFFF);
		SetPlayerVirtualWorld(playerid, 0);
		SetPlayerPos(playerid, 2065.495, -1874.174, 13.564);
		SetPlayerFacingAngle(playerid, 124.82);
	}*/
	
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
	
	if(!strcmp(playername, "Clubber1", true))
	{
		SetSpawnInfo(playerid, 0, 12, 2058.007, -1868.180, 14.743, 272.82, 0, 0, 0, 0, 0, 0);
	}
	else if(!strcmp(playername, "Clubber2", true))
	{
		SetSpawnInfo(playerid, 0, 13, 2057.39,-1869.07,14.74, 20.82, 0, 0, 0, 0, 0, 0);
	}
	else if(!strcmp(playername, "Clubber3", true))
	{
		SetSpawnInfo(playerid, 0, 63, 2053.74, -1868.99,14.74, 30.82, 0, 0, 0, 0, 0, 0);
	}
	else if(!strcmp(playername, "Clubber4", true))
	{
		SetSpawnInfo(playerid, 0, 64, 2057.54, -1872.72, 14.74, 30.82, 0, 0, 0, 0, 0, 0);
	}
	else if(!strcmp(playername, "Clubber5", true))
	{
		SetSpawnInfo(playerid, 0, 69, 2053.16, -1876.59, 14.74, 340.82, 0, 0, 0, 0, 0, 0);
	}
	else if(!strcmp(playername, "Clubber6", true))
	{
		SetSpawnInfo(playerid, 0, 82, 2056.36, -1868.14, 14.74, 170.82, 0, 0, 0, 0, 0, 0);
	}
	else if(!strcmp(playername, "Clubber7", true))
	{
		SetSpawnInfo(playerid, 0, 83, 2057.75, -1871.3670, 14.74, 70.82, 0, 0, 0, 0, 0, 0);
	}
	else if(!strcmp(playername, "Clubber8", true))
	{
		SetSpawnInfo(playerid, 0, 84, 2055.04, -1871.72, 14.74, 70.82, 0, 0, 0, 0, 0, 0);
	}
	else if(!strcmp(playername, "Clubber9", true))
	{
		SetSpawnInfo(playerid, 0, 90, 2056.70, -1870.99, 14.74, 270.82, 0, 0, 0, 0, 0, 0);
	}
	else if(!strcmp(playername, "Clubber10", true))
	{
		SetSpawnInfo(playerid, 0, 91, 2058.45, -1870.60, 14.74, 130.82, 0, 0, 0, 0, 0, 0);
	}
	else if(!strcmp(playername, "Clubber11", true))
	{
		SetSpawnInfo(playerid, 0, 93, 2055.87, -1869.45, 14.74, 310.82, 0, 0, 0, 0, 0, 0);
	}
	else if(!strcmp(playername, "Clubber12", true))
	{
		SetSpawnInfo(playerid, 0, 139, 2054.59, -1869.23, 14.74, 310.82, 0, 0, 0, 0, 0, 0);
	}
	else if(!strcmp(playername, "Clubber13", true))
	{
		SetSpawnInfo(playerid, 0, 138, 2055.04, -1867.91, 14.74, 210.82, 0, 0, 0, 0, 0, 0);
	}
	else if(!strcmp(playername, "Clubber14", true))
	{
		SetSpawnInfo(playerid, 0, 144, 2053.81, -1869.53, 14.74, 210.82, 0, 0, 0, 0, 0, 0);
	}
	else if(!strcmp(playername, "Clubber15", true))
	{
		SetSpawnInfo(playerid, 0, 146, 2055.85, -1872.26, 14.74, 290.82, 0, 0, 0, 0, 0, 0);
	}
	else if(!strcmp(playername, "Clubber16", true))
	{
		SetSpawnInfo(playerid, 0, 152, 2054.02, -1872.44, 14.74, 120.82, 0, 0, 0, 0, 0, 0);
	}
	else if(!strcmp(playername, "Clubber17", true))
	{
		SetSpawnInfo(playerid, 0, 154, 2054.70, -1869.18, 14.74, 70.82, 0, 0, 0, 0, 0, 0);
	}
	else if(!strcmp(playername, "Clubber18", true))
	{
		SetSpawnInfo(playerid, 0, 169, 2055.10, -1874.00, 14.74, 90.82, 0, 0, 0, 0, 0, 0);
	}
	else if(!strcmp(playername, "Clubber19", true))
	{
		SetSpawnInfo(playerid, 0, 185, 2053.87, -1874.37, 14.74, 0.82, 0, 0, 0, 0, 0, 0);
	}
	else if(!strcmp(playername, "Clubber20", true))
	{
		SetSpawnInfo(playerid, 0, 186, 2054.44, -1875.77, 14.74, 90.82, 0, 0, 0, 0, 0, 0);
	}
	else if(!strcmp(playername, "Clubber21", true))
	{
		SetSpawnInfo(playerid, 0, 193, 2053.39, -1873.03, 14.74, 340.82, 0, 0, 0, 0, 0, 0);
	}
	else if(!strcmp(playername, "Clubber22", true))
	{
		SetSpawnInfo(playerid, 0, 223, 2056.09, -1874.37, 14.74, 40.82, 0, 0, 0, 0, 0, 0);
	}
	else if(!strcmp(playername, "Clubber23", true))
	{
		SetSpawnInfo(playerid, 0, 237, 2059.323, -1879.664, 14.740, 120.82, 0, 0, 0, 0, 0, 0);
	}
	else if(!strcmp(playername, "Clubber24", true))
	{
		SetSpawnInfo(playerid, 0, 238, 2059.097, -1882.333, 14.740, 85.82, 0, 0, 0, 0, 0, 0);
	}
	else if(!strcmp(playername, "Clubber25", true))
	{
		SetSpawnInfo(playerid, 0, 241, 2056.997, -1883.621, 14.740, 335.82, 0, 0, 0, 0, 0, 0);
	}
	else if(!strcmp(playername, "Clubber26", true))
	{
		SetSpawnInfo(playerid, 0, 244, 2057.404, -1881.943, 14.740, 280.82, 0, 0, 0, 0, 0, 0);
	}
	else if(!strcmp(playername, "Clubber27", true))
	{
		SetSpawnInfo(playerid, 0, 246, 2056.670, -1879.645, 14.740, 45.82, 0, 0, 0, 0, 0, 0);
	}
	else if(!strcmp(playername, "Clubber28", true))
	{
		SetSpawnInfo(playerid, 0, 249, 2055.698, -1881.454, 14.740, 225.82, 0, 0, 0, 0, 0, 0);
	}
	else if(!strcmp(playername, "Clubber29", true))
	{
		SetSpawnInfo(playerid, 0, 219, 2054.726, -1882.286, 14.740, 60.82, 0, 0, 0, 0, 0, 0);
	}
	else if(!strcmp(playername, "Clubber30", true))
	{
		SetSpawnInfo(playerid, 0, 163, 2062.491, -1876.307, 13.825, 275.82, 0, 0, 0, 0, 0, 0);
	}
	else if(!strcmp(playername, "Clubber31", true))
	{
		SetSpawnInfo(playerid, 0, 164, 2062.406, -1873.486, 13.886, 264.82, 0, 0, 0, 0, 0, 0);
	}
	else if(!strcmp(playername, "Clubber32", true))
	{
		SetSpawnInfo(playerid, 0, 221, 2062.385, -1875.291, 13.901, 90.82, 0, 0, 0, 0, 0, 0);
	}
	else if(!strcmp(playername, "Clubber33", true))
	{
		SetSpawnInfo(playerid, 0, 226, 2063.558, -1874.208, 13.565, 95.82, 0, 0, 0, 0, 0, 0);
	}
	else if(!strcmp(playername, "Clubber34", true))
	{
		SetSpawnInfo(playerid, 0, 217, 2064.288, -1875.588, 13.565, 85.82, 0, 0, 0, 0, 0, 0);
	}
	else if(!strcmp(playername, "Clubber35", true))
	{
		SetSpawnInfo(playerid, 0, 236, 2064.868, -1874.168, 13.565, 90.82, 0, 0, 0, 0, 0, 0);
	}
	else if(!strcmp(playername, "Clubber36", true))
	{
		SetSpawnInfo(playerid, 0, 251, 2065.798, -1874.079, 13.565 , 95.82, 0, 0, 0, 0, 0, 0);
	}
	else if(!strcmp(playername, "Clubber37", true))
	{
		SetSpawnInfo(playerid, 0, 252, 2065.365, -1875.198, 13.565, 90.82, 0, 0, 0, 0, 0, 0);
	}
	else if(!strcmp(playername, "Clubber38", true))
	{
		SetSpawnInfo(playerid, 0, 254, 2066.640, -1875.815, 13.565, 90.82, 0, 0, 0, 0, 0, 0);
	}
	else if(!strcmp(playername, "Clubber39", true))
	{
		SetSpawnInfo(playerid, 0, 256, 2067.135, -1874.590, 13.565, 85.82, 0, 0, 0, 0, 0, 0);
	}
	else if(!strcmp(playername, "Clubber40", true))
	{
		SetSpawnInfo(playerid, 0, 257, 2068.892, -1873.711, 13.565, 80.82, 0, 0, 0, 0, 0, 0);
	}
	else if(!strcmp(playername, "Clubber41", true))
	{
		SetSpawnInfo(playerid, 0, 263, 2069.707, -1874.605, 13.565, 100.82, 0, 0, 0, 0, 0, 0);
	}
	else if(!strcmp(playername, "Clubber42", true))
	{
		SetSpawnInfo(playerid, 0, 292, 2069.306, -1876.258, 13.565, 90.82, 0, 0, 0, 0, 0, 0);
	}
	else if(!strcmp(playername, "Clubber43", true))
	{
		SetSpawnInfo(playerid, 0, 293, 2071.259, -1875.419, 13.565, 95.82, 0, 0, 0, 0, 0, 0);
	}
	else if(!strcmp(playername, "Clubber44", true))
	{
		SetSpawnInfo(playerid, 0, 296, 2071.397, -1873.475, 13.565, 90.82, 0, 0, 0, 0, 0, 0);
	}
	else if(!strcmp(playername, "Clubber45", true))
	{
		SetSpawnInfo(playerid, 0, 298, 2063.027, -1865.667, 13.591, 90.82, 0, 0, 0, 0, 0, 0);
	}
	else if(!strcmp(playername, "Clubber46", true))
	{
		SetSpawnInfo(playerid, 0, 107, 2062.449, -1867.504, 13.565, 90.82, 0, 0, 0, 0, 0, 0);
	}
	else if(!strcmp(playername, "Clubber47", true))
	{
		SetSpawnInfo(playerid, 0, 106, 2065.313, -1867.019, 13.565, 90.82, 0, 0, 0, 0, 0, 0);
	}
	else if(!strcmp(playername, "Clubber48", true))
	{
		SetSpawnInfo(playerid, 0, 105, 2064.192, -1867.695, 13.565, 90.82, 0, 0, 0, 0, 0, 0);
	}
	
	return 0;
}

public OnPlayerConnect(playerid)
{
	
	return 1;
}
	
