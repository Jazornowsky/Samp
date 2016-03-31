#include <a_samp>

public OnFilterScriptInit()
{
	ConnectNPC("Taxi1", "taxi1");
	ConnectNPC("Taxi2", "taxi2");
	ConnectNPC("Taxi3", "taxi3");
	ConnectNPC("Taxi4", "taxi4");
	ConnectNPC("Taxi5", "taxi5");
	ConnectNPC("Taxi6", "taxi6");
	ConnectNPC("Taxi7", "taxi7");
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
	
	
    SetPlayerVirtualWorld(playerid, 999);
	if(!strcmp(playername, "Taxi1", true))
	{
		SetPlayerColor(playerid,0xFFFFFFFF);
        PutPlayerInVehicle(playerid, 1991, 0);
    }
	if(!strcmp(playername, "Taxi2", true))
	{
		SetPlayerColor(playerid,0xFFFFFFFF);
        PutPlayerInVehicle(playerid, 1992, 0);
    }
	if(!strcmp(playername, "Taxi3", true))
	{
		SetPlayerColor(playerid,0xFFFFFFFF);
        PutPlayerInVehicle(playerid, 1993, 0);
    }
	if(!strcmp(playername, "Taxi4", true))
	{
		SetPlayerColor(playerid,0xFFFFFFFF);
        PutPlayerInVehicle(playerid, 1994, 0);
    }
	if(!strcmp(playername, "Taxi5", true))
	{
		SetPlayerColor(playerid,0xFFFFFFFF);
        PutPlayerInVehicle(playerid, 1995, 0);
    }
	if(!strcmp(playername, "Taxi6", true))
	{
		SetPlayerColor(playerid,0xFFFFFFFF);
        PutPlayerInVehicle(playerid, 1996, 0);
    }
	if(!strcmp(playername, "Taxi7", true))
	{
		SetPlayerColor(playerid,0xFFFFFFFF);
        PutPlayerInVehicle(playerid, 1997, 0);
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
	
	if(!strcmp(playername, "Taxi1", true))
	{
		SetSpawnInfo( playerid, 0, 255, 1958.33, 1343.12, 15.36, 269.15, 0, 0, 0, 0, 0, 0 );
    }
	if(!strcmp(playername, "Taxi2", true))
	{
		SetSpawnInfo( playerid, 0, 255, 1958.33, 1343.12, 15.36, 269.15, 0, 0, 0, 0, 0, 0 );
    }
	if(!strcmp(playername, "Taxi3", true))
	{
		SetSpawnInfo( playerid, 0, 255, 1958.33, 1343.12, 15.36, 269.15, 0, 0, 0, 0, 0, 0 );
    }
	if(!strcmp(playername, "Taxi4", true))
	{
		SetSpawnInfo( playerid, 0, 255, 1958.33, 1343.12, 15.36, 269.15, 0, 0, 0, 0, 0, 0 );
    }
	if(!strcmp(playername, "Taxi5", true))
	{
		SetSpawnInfo( playerid, 0, 255, 1958.33, 1343.12, 15.36, 269.15, 0, 0, 0, 0, 0, 0 );
    }
	if(!strcmp(playername, "Taxi6", true))
	{
		SetSpawnInfo( playerid, 0, 255, 1958.33, 1343.12, 15.36, 269.15, 0, 0, 0, 0, 0, 0 );
    }
	if(!strcmp(playername, "Taxi7", true))
	{
		SetSpawnInfo( playerid, 0, 255, 1958.33, 1343.12, 15.36, 269.15, 0, 0, 0, 0, 0, 0 );
    }
	
	return 0;
}

public OnPlayerConnect(playerid)
{
	
	return 1;
}
	
