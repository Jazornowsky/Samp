/***
*
* File: wp_samsites.inc
* Auth: Damian Wojdat
* Date: 15.09.2011
* Desc: Sam sites positions and activation.
*
*************************************************************************************************************/

public OnSamSiteRestarted()
{
	AddStaticSAMEx(-1395.0, 493.0, 20.0, 1000.0, 80.0);
	AddStaticSAMEx(-1324.0, 493.0, 22.0, 1000.0, 80.0);
	SAM_start();
	return 1;
}

public OnSamSiteUpdate(samid, playerid)
{
	for(new n = 0; n <= 32; n++)
	{
		if(samid == n)
		{
			if(gVehData[GetPlayerVehicleID(playerid)-1][mVehFaction] == gPlayerData[playerid][pFaction] || gVehData[GetPlayerVehicleID(playerid)-1][mVehFaction] == 255 || GetPlayerState(playerid) == PLAYER_STATE_PASSENGER)
			{
				SAM_cancel(n);
			}
			if(AdminDuty[playerid] == 1)
			{
				SAM_cancel(n);
			}
		}
	}
	return 1;
}

#include <SAMsites0.4>