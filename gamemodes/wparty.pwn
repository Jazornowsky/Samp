/***
* wparty.pwn - Entry point for gamemode.
*
*							WParty RolePlay based on South-West RP 0.3
*							Originaly modified by Damian (Xtreme) Wojdat
*							Developing with Robert (Xamxe) B¹bel since 2009-12
*
*************************************************************************************************************/

//============[SYSTEM RELATED MESSAGE DEFINES]========
#define BUSINESS_TYPES "1: Restaurant - 2: Phone - 3: 24-7 - 4: Ammunation - 5: Advertising - 6: Clothes Store - 7. Bar/Club"
#define BUSINESS_TYPES2 "8: Record Company - 9: Studio - 10: Salon"
//====================================================

#include <a_samp>
#include <core>
#include <float>
#include <time>
#include <file>
#include <Dini>
#include <sscanf2>
#include <streamer>
#include <mysql>
#include <audio>
#include <looking>
#include <mweather>
#include <YSI/y_timers>
// #include <paused>
#include <spikestrip>
#include <foreach>
#include <wp\wp_variables>
#include <wp\wp_speedlimitsrc>
#include <wp\wp_reset>
#include <wp\wp_onmysqlquery>
#include <wp\wp_saveload>
#include <wp\wp_saveloadjobdata>
#include <wp\wp_saveloadmzgkjobs>
#include <wp\wp_buscheckpoints>
#include <wp\wp_timers>
#include <wp\wp_bw>
#include <wp\wp_importvehicle>
#include <wp\wp_progressbar>
#include <wp\wp_savedata>
#include <wp\wp_itemfncs>
#include <wp\wp_fireworks>
#include <wp\wp_payday>
#include <wp\wp_loadscript>
#include <wp\wp_audio>
#include <wp\wp_fuel>
#include <wp\wp_utility>
#include <wp\wp_engine>
#include <wp\wp_player>
#include <wp\wp_ongamemodestock>
#include <wp\wp_onplayerstock>
#include <wp\wp_onvehiclestock>
#include <wp\wp_onplayerselectedmenurow>
#include <wp\wp_ondialogresponse>
#include <wp\wp_onplayercommandtext>
#include <wp\wp_dcmds>
#include <wp\wp_samsites>
#include <wp\wfactory\wp_wfactory>
#include <wp\wp_vehutils>

public main()
{
	print("Inizialling GameMode");
	// print("_________________________________________________________________________");
		// printf("> %s - %s by %s loaded.", GAMEMODE,MAP_NAME,DEVELOPER);
		// printf("> Nazwa serwera: %s", SERVER_NAME);
		// if (!strcmp("Yes", GAMEMODE_USE_VERSION, true)) { printf("> Gamemode: %s - %s", GAMEMODE,VERSION); } else { printf("> Gamemode: %s", GAMEMODE); } // Checking the "GAMEMODE_USE_VERSION" define, if "Yes" then set the gamemode text to the gamemode name & version, else set it to just the gamemode name.
		// printf("> Version: %s", VERSION);
		// printf("> Map: %s", MAP_NAME);
		// printf("> Website: %s", WEBSITE);
		// printf("> Developer: %s", DEVELOPER);
		// printf("> Last Update: %s", LAST_UPDATE);
		// printf("> Current Script Lines: %d", SCRIPT_LINES);
		// printf("> Password: %s", ShowServerPassword());
	// print("_________________________________________________________________________");
	return 1;
}

// public OnPlayerPause(playerid)
// {
    // UpdateDynamic3DTextLabelText(playerAFK[playerid], COLOR_LIGHTBLUE, "AFK");
    // return 1;
// }

// public OnPlayerUnPause(playerid)
// {
	// UpdateDynamic3DTextLabelText(playerAFK[playerid], COLOR_LIGHTBLUE, " ");
    // return 1;
// }

public OnRealWeatherUpdate(observerid, oldstate, newstate)
{
	return 1;
}

Delay:SpawnedInWorld[4000, i](playerid)
{
	Spawned[playerid] = 1;
	return 1;
}

public OnDynamicObjectMoved(objectid)
{
	return 1;
}

public OnRconCommand(cmd[])
{
	return 1;
}

public OnObjectMoved(objectid)
{
	return 1;
}