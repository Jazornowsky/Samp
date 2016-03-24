//!:.:!:.:!:.:!:.:!:.:!:.:!:.:!:.:![Made by Notime]!:.:!:.:!:.:!:.:!:.:!:.:!:.:!:.:!
#include <a_samp>
#include <djson>
// This is a comment
// uncomment the line below if you want to write a filterscript
//#define FILTERSCRIPT
#define dcmd(%1,%2,%3) if ((strcmp((%3)[1], #%1, true, (%2)) == 0) && ((((%3)[(%2) + 1] == 0) && (dcmd_%1(playerid, "")))||(((%3)[(%2) + 1] == 32) && (dcmd_%1(playerid, (%3)[(%2) + 2]))))) return 1








public OnFilterScriptInit()
{
	print("\n--------------------------------------");
	print("Notime's Firework");
	print("--------------------------------------\n");
	
	return 1;
}




public OnFilterScriptExit()
{
    djson_GameModeExit();
	return 1;
}


main()
{
	print("\n--------------------------------------");
	print("Notime's Firework");
	print("--------------------------------------\n");
}


public OnGameModeInit()
{
	// Don't use these lines if it's a filterscript
	AddPlayerClass(0, 1958.3783, 1343.1572, 15.3746, 269.1425, 0, 0, 0, 0, 0, 0);
	return 1;
}

public OnGameModeExit()
{
	return 1;
}

public OnPlayerConnect(playerid)
{
	SendClientMessage(playerid, WHITE, "FilterScript loaded: Notime's Firework");
	return 1;
}

public OnPlayerRequestClass(playerid, classid)
{
	SetPlayerPos(playerid, 1958.3783, 1343.1572, 15.3746);
	SetPlayerCameraPos(playerid, 1958.3783, 1343.1572, 15.3746);
	SetPlayerCameraLookAt(playerid, 1958.3783, 1343.1572, 15.3746);
	return 1;
}

public OnPlayerCommandText(playerid, cmdtext[])
{
    dcmd(lightfw,7,cmdtext);
    dcmd(fwcp,4,cmdtext);
	if (strcmp("/mycommand", cmdtext, true, 10) == 0)
	{
		// Do something here
		return 1;
	}
	return 0;
}



public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	
	return 1;
}
//!:.:!:.:!:.:!:.:!:.:!:.:!:.:!:.:![Made by Notime]!:.:!:.:!:.:!:.:!:.:!:.:!:.:!:.:!
