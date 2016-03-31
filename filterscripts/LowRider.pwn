/*
	@title Low-Rider Mini-Game.
	@author Carlton
	@copyright 2010
	@description Perform a lowriding mini-game similar to singleplayer's one.

*/

#include <a_samp>

#define _WHITE 0xFFFFFFFF
#define CameraAngles // Comment this if you would like to disable the camera when you've finished a note.

#if !defined PRESSED
#define PRESSED(%0) \
	(((newkeys & (%0)) == (%0)) && ((oldkeys & (%0)) != (%0)))
#endif

new
	bool:ContestToggled = true,
	bool:InContest[MAX_PLAYERS],
	CurrentNote[MAX_PLAYERS],
	Text:ContestText,
	MoneyEarned[MAX_PLAYERS],
	bool:JustJoined[MAX_PLAYERS],
	Float:Pos[4];
	
public OnPlayerDisconnect(playerid) {
	InContest[playerid] = false;
	CurrentNote[playerid] = -1;
	MoneyEarned[playerid] = 0;
	JustJoined[playerid] = false;
	return 1;
}

public OnFilterScriptInit() {
    ContestText = TextDrawCreate(230.000000,309.000000,"_");
	TextDrawAlignment(ContestText,0);
	TextDrawBackgroundColor(ContestText,0x000000ff);
	TextDrawFont(ContestText,2);
	TextDrawLetterSize(ContestText,0.899999,2.599999);
	TextDrawColor(ContestText,0xffff00ff);
	TextDrawSetOutline(ContestText,1);
	TextDrawSetProportional(ContestText,1);
	TextDrawSetShadow(ContestText,1);
	return 1;
}

public OnFilterScriptExit() {
	TextDrawDestroy(ContestText);
	return 1;
}

public OnPlayerCommandText(playerid, cmdtext[]) {
	if (strcmp("/togglecontest", cmdtext, true, 10) == 0) {
		if(IsPlayerAdmin(playerid)) {
		    if(ContestToggled == true) {
		        ContestToggled = false;
		    }
		    else {
		        ContestToggled = true;
		    }
		}
	    return 1;
	}
	if (strcmp("/joincontest", cmdtext, true, 10) == 0) {
	    if(ContestToggled == false) return SendClientMessage(playerid, _WHITE, "The contest is not toggled, ask a admin to toggle it.");
	    if(InContest[playerid] == false) {
	        SetPlayerCheckpoint(playerid, 1792.2076,-1909.4030,13.2685, 9.0);
	        InContest[playerid] = true;
	        JustJoined[playerid] = true;
	    }
	    else {
	        InContest[playerid] = false;
	        JustJoined[playerid] = false;
	        TextDrawHideForPlayer(playerid, ContestText);
	        GivePlayerMoney(playerid, MoneyEarned[playerid]);
	        DisablePlayerCheckpoint(playerid);
	        SetCameraBehindPlayer(playerid);
	        CurrentNote[playerid] = -1;
	        ClearAnimations(playerid);
	    }
	    return 1;
	}
	return 0;
}

public OnPlayerEnterCheckpoint(playerid) {
	if(InContest[playerid] == true) {
	    if(!IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid, _WHITE, "You're not in a vehicle.");
		if(GetVehicleComponentInSlot(GetPlayerVehicleID(playerid),GetVehicleComponentType(1087)) == 1087) {
			BeginContestForPlayer(playerid);
		}
		else return SendClientMessage(playerid, _WHITE, "Your vehicle does not have hydraulics.");
	}
	return 1;
}

stock BeginContestForPlayer(playerid) {
	GetPlayerPos(playerid, Pos[0],Pos[1],Pos[2]);
	SetPlayerCameraPos(playerid, Pos[0]+5,Pos[1],Pos[2]+1);
	SetPlayerCameraLookAt(playerid, Pos[0],Pos[1],Pos[2]);
	DisablePlayerCheckpoint(playerid);
    SendClientMessage(playerid, _WHITE, "The contest is starting, make sure you're in the camera, so you can see!");
    SetTimerEx("SendNoteForPlayer", 5000, 0, "d", playerid);
    GameTextForPlayer(playerid, "~r~Information~n~~n~~>~ Right~n~~<~ Left~n~~up~ Up~n~~down~Down", 4000, 5);
    return 1;
}

forward SendNoteForPlayer(playerid);
public SendNoteForPlayer(playerid) {
	new
		array[128],
		earned,
		note,
		randanim,
		randomcamera;
		
	PlayerPlaySound(playerid, 1130, 0.0, 0.0, 10.0);
	TextDrawHideForPlayer(playerid, ContestText);
	GetPlayerPos(playerid, Pos[0],Pos[1],Pos[2]);
	
	earned = random(20);
	note = random(4);
	randanim = random(3);
	
	#if !defined CameraAngles
	#pragma unused randomcamera
	#endif
	
	#if defined CameraAngles
	randomcamera = random(6);
	#endif
	
	if(JustJoined[playerid] == false) {
		MoneyEarned[playerid] += earned;
		format(array, 128, "Money Earned: ~g~$%d", MoneyEarned[playerid]);
		GameTextForPlayer(playerid, array, 8000, 4);
	}
	if(JustJoined[playerid] == true)  JustJoined[playerid] = false;
	
	switch(note) {
	    case 0:{
	        TextDrawSetString(ContestText, "New note~n~~n~      ~up~");
	        CurrentNote[playerid] = 0;
	    }
	    case 1:{
	        TextDrawSetString(ContestText, "New note~n~~n~      ~down~");
	        CurrentNote[playerid] = 1;
	    }
	    case 2:{
	       	TextDrawSetString(ContestText, "New note~n~~n~      ~>~");
	        CurrentNote[playerid] = 2;
	    }
	    case 3:{
	        TextDrawSetString(ContestText, "New note~n~~n~      ~<~");
	        CurrentNote[playerid] = 3;
	    }
	}
	switch(randanim) {
	    case 0: {
     	   ApplyAnimation(playerid, "LOWRIDER", "lrgirl_l3_loop", 4.0, 1, 0, 0, 0, 0);
	    }
	    case 1: {
	        ApplyAnimation(playerid, "LOWRIDER", "lrgirl_l4_loop", 4.0, 1, 0, 0, 0, 0);
	    }
	    case 2: {
	        ApplyAnimation(playerid, "LOWRIDER", "lrgirl_l5_loop", 4.0, 1, 0, 0, 0, 0);
	    }
	}
	#if defined CameraAngles
	switch(randomcamera) {
	    case 0: {
	        SetPlayerCameraPos(playerid, Pos[0]+5,Pos[1],Pos[2]+1);
		    SetPlayerCameraLookAt(playerid, Pos[0],Pos[1],Pos[2]);
	    }
	    case 1: {
	        SetPlayerCameraPos(playerid, Pos[0]+5,Pos[1]+4,Pos[2]+1);
		    SetPlayerCameraLookAt(playerid, Pos[0],Pos[1],Pos[2]);
	    }
	    case 2: {
	        SetPlayerCameraPos(playerid, Pos[0]+3,Pos[1],Pos[2]+1);
		    SetPlayerCameraLookAt(playerid, Pos[0],Pos[1],Pos[2]);
	    }
	    case 3: {
	        SetPlayerCameraPos(playerid, Pos[0]+3,Pos[1],Pos[2]+2);
		    SetPlayerCameraLookAt(playerid, Pos[0],Pos[1],Pos[2]);
	    }
	    case 4: {
	        SetPlayerCameraPos(playerid, Pos[0],Pos[1]+2,Pos[2]+9);
		    SetPlayerCameraLookAt(playerid, Pos[0],Pos[1],Pos[2]);
	    }
	    case 5: {
	        SetPlayerCameraPos(playerid, Pos[0],Pos[1]+2,Pos[2]+2);
		    SetPlayerCameraLookAt(playerid, Pos[0],Pos[1],Pos[2]);
	    }
	}
	#endif
	TextDrawShowForPlayer(playerid, ContestText);
	return 1;
}

public OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
	if (newkeys & KEY_ANALOG_UP && CurrentNote[playerid] == 0) {
	    SendNoteForPlayer(playerid);
	}
	if (newkeys & KEY_ANALOG_DOWN && CurrentNote[playerid] == 1) {
	    SendNoteForPlayer(playerid);
	}
	if (newkeys & KEY_ANALOG_RIGHT && CurrentNote[playerid] == 2) {
	    SendNoteForPlayer(playerid);
	}
	if (newkeys & KEY_ANALOG_LEFT && CurrentNote[playerid] == 3) {
	    SendNoteForPlayer(playerid);
	}
	return 1;
}
