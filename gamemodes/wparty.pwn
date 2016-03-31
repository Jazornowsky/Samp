/***
* wparty.pwn - Entry point for gamemode.
*
*							WParty RolePlay based on South-West RP 0.3
*							Originaly modified by Damian (Xtreme) Wojdat
*							Developing with Robert (Xamxe) B¹bel since 2009-12
*							Created: 2.12.2010
*
*************************************************************************************************************/

// #pragma dynamic 145000

#include <a_samp>
#include <core>
#include <float>
#include <time>
#include <file>
#include <sscanf2>
#include <streamer>
#include <audio>
// #include <mysql>
#include <a_mysql>
// #include <crashdetect>
// #include <Dini>
// #include <djson>
// #include <looking>
#include <mweather>
// #include <paused>
#include <foreach>
#include <keypad>
// #include <YSI/y_iterate>
#include <YSI\y_timers>
#include <spikestrip>
#include <wp\wp_variables>
#include <wp\callbacks\wp_onmysqlquery>
#include <wp\wp_areas>
#include <wp\wp_reset>
#include <wp\wp_saveload>
#include <wp\wp_saveloadjobdata>
#include <wp\wp_saveloadmzgkjobs>
#include <wp\wp_buscheckpoints>
#include <wp\wp_trashcheckpoints>
#include <wp\wp_sweepercheckpoints>
#include <wp\wp_farmercheckpoints>
#include <wp\wp_timers>
#include <wp\wp_bw>
#include <wp\wp_importvehicle>
#include <wp\wp_progressbar>
#include <wp\wp_savedata>
#include <wp\wp_itemfncs>
// #include <wp\wp_fireworks>
#include <wp\wp_payday>
#include <wp\wp_loadscript>
#include <wp\wp_audio>
#include <wp\wp_fuel>
#include <wp\wp_utility>
#include <wp\wp_engine>
#include <wp\wp_player>
#include <wp\wp_tips>
#include <wp\callbacks\wp_ongamemodestock>
#include <wp\callbacks\wp_onplayerstock>
#include <wp\callbacks\wp_onvehiclestock>
#include <wp\callbacks\wp_onplayerselectedmenurow>
#include <wp\callbacks\wp_ondialogresponse>
#include <wp\callbacks\wp_onplayercommandtext>
#include <wp\callbacks\wp_onplayerkeystatechange>
#include <wp\callbacks\wp_onplayereditobject>
#include <wp\callbacks\wp_onplayerkeypadinput>
#include <wp\callbacks\wp_ondynamicobjectmoved>
#include <wp\wp_dcmds>
#include <wp\wp_samsites>
#include <wp\wfactory\wp_wfactory>
#include <wp\wp_sounds>
#include <gbug>

public main()
{
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

// public OnRealWeatherUpdate(observerid, oldstate, newstate)
// {
	// return 1;
// }

timer SpawnedInWorld[4000](playerid)
{
	Spawned[playerid] = 1;
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