#include <a_npc>
/*
	RNPC NPC script
	Modified version of Joe Staffs code (http://forum.sa-mp.com/showthread.php?t=344747)
	Version 0.2.1
	Mauzen, 3.7.2012
	
	Communication codes:
		Server -> NPC:
			101:<slot> 	Start playing back ID recording
			102			Stop current playback
			109			Start playing back the following recording file
			110			Disable autorepeat
			111			Enable autorepeat
			
		NPC -> Server:
			001			Notification about join
			002			Notification about finished playback
		
			201 		Started vehicle playback
			202 		Started on-foot playback
			208			Started custom file playback on-foot
			209			Started custom file playback in vehicle

*/

new npcid;
new vehicle;
new repeat;
new curplayback[12];

main(){}

public OnNPCEnterVehicle(vehicleid, seatid)
{
	vehicle = true;
	printf("now entering");
}

public OnNPCExitVehicle()
{
	vehicle = false;
	printf("now leaving");
}

public OnNPCConnect(myplayerid)
{	
    npcid = myplayerid;
	// Register at server
	new txt[13];
	format(txt, 13, "RNPC:001", npcid);
	SendCommand(txt);
}
public OnRecordingPlaybackEnd() 
{	
	SendCommand("RNPC:002");
	if (repeat) {
		new rec[9];
		if (vehicle) {
			StartRecordingPlayback(PLAYER_RECORDING_TYPE_DRIVER, curplayback);
			format(rec, 9, "RNPC:201");
		} else {
			StartRecordingPlayback(PLAYER_RECORDING_TYPE_ONFOOT, curplayback);
			format(rec, 9, "RNPC:202");
		}
		SendCommand(rec);
	}
}


public OnNPCSpawn() {
	SendCommand("RNPC:003");
}

public OnClientMessage(color, text[])
{
    if (!strcmp(text,"RNPC:101", false, 8))
    {
		new slot = strval(text[9]);
		new rec[12];
        format(curplayback, 12, "rnpc%03d-%02d", npcid, slot);
		
		
		StopRecordingPlayback();
        if (vehicle) {
			StartRecordingPlayback(PLAYER_RECORDING_TYPE_DRIVER, curplayback);
			format(rec, 12, "RNPC:201");
		} else {
			StartRecordingPlayback(PLAYER_RECORDING_TYPE_ONFOOT, curplayback);
			format(rec, 12, "RNPC:202");
		}
		
        SendCommand(rec);
		return;
    }
	
	if (!strcmp(text,"RNPC:102:",false, 9))
	{
		StopRecordingPlayback();
		return;
	}
	
	if (!strcmp(text,"RNPC:109:",false, 9))
    {
		new rec[9];
		format(curplayback, 32, "%s", text[9]);
		StopRecordingPlayback();
        if (vehicle) {
			StartRecordingPlayback(PLAYER_RECORDING_TYPE_DRIVER, curplayback);
			format(rec, 9, "RNPC:208");
		} else {
			StartRecordingPlayback(PLAYER_RECORDING_TYPE_ONFOOT, curplayback);
			format(rec, 9, "RNPC:209");
		}
		
        SendCommand(rec);
		return;
    }
	
	if (!strcmp(text,"RNPC:110",false))
    {
		repeat = 0;
		return;
    }
	
	if (!strcmp(text,"RNPC:111",false))
    {
		repeat = 1;
		return;
    }
}