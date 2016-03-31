//
// A Driver NPC that goes around a path continuously
// Kye 2009
//

#include <a_npc>

// #define NUM_PLAYBACK_FILES 3
// new gPlaybackFileCycle=0;

//------------------------------------------
forward CheckColission();
forward StartCheckColission();
forward Float:GetXYInFrontOfNPC(&Float:x, &Float:y, Float:distance);


main(){}
// new paused = 0;
// new timerId = -1;

//------------------------------------------

NextPlayback()
{
	// Reset the cycle count if we reach the max
	// if(gPlaybackFileCycle==NUM_PLAYBACK_FILES) gPlaybackFileCycle = 0;

	// if(gPlaybackFileCycle==0) {
	StartRecordingPlayback(PLAYER_RECORDING_TYPE_DRIVER,"bus_mg_pc");
	// }
	// else if(gPlaybackFileCycle==1) {
		// StartRecordingPlayback(PLAYER_RECORDING_TYPE_DRIVER,"at400_ls_to_lv_x1");
	// }
	// else if(gPlaybackFileCycle==2) {
	    // StartRecordingPlayback(PLAYER_RECORDING_TYPE_DRIVER,"at400_lv_to_sf_x1");
	// }
	// SetTimer("StartCheckColission", 10000, 0);

	// printf("DEBUG1");
	
	// gPlaybackFileCycle++;
}

// public Float:GetXYInFrontOfNPC(&Float:x, &Float:y, Float:distance)
// {
    // new Float:a, Float:z;
	// GetMyPos(x, y, z);
	// GetMyFacingAngle(a);
    // x += (distance * floatsin(-a, degrees));
    // y += (distance * floatcos(-a, degrees));
    // return a;
// }

// public StartCheckColission()
// {
	// if(timerId != -1)
		// KillTimer(timerId);
	// timerId = SetTimer("CheckColission", 100, 1);
// }

// public CheckColission()
// {
	// static Float:bX, Float:bY, Float:bZ;
	// static Float:vehX, Float:vehY, Float:vehZ;
	// static Float:nX, Float:nY, Float:nZ;
	// GetMyPos(bX, bY, bZ);
	// if(bX > -2.0 && bX < -2.0 && bY > -2.0 && bY < 2.0)
		// return;
	// GetXYInFrontOfNPC(nX, nY, 3.0);	
	// printf("DEBUG2");
	// for(new i = 0; i < 100; i++)
	// {
		// if(!IsPlayerConnected(i))
			// continue;
		// GetPlayerPos(i, vehX, vehY, vehZ);
		// if(vehX == bX && vehY == bY)
			// continue;
		// if(floatabs(vehX-nX) < 2.0 && floatabs(vehY-nY) < 2.0 && !paused)
		// {
			// PauseRecordingPlayback();
			// paused = 1;
			// break;
		// }
		// else
		// {
			// if(paused)
			// {
				// ResumeRecordingPlayback();
				// paused = 0;
			// }
		// }
	// }	
	// printf("DEBUG3");
	// return;
// }
	
//------------------------------------------

public OnRecordingPlaybackEnd()
{
    NextPlayback();
}

//------------------------------------------

public OnNPCEnterVehicle(vehicleid, seatid)
{
    NextPlayback();
}

//------------------------------------------

public OnNPCExitVehicle()
{
    StopRecordingPlayback();
    // gPlaybackFileCycle = 0;
}

//------------------------------------------
