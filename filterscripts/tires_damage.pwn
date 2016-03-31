////////////////////////////////////////////////////////////////////////////////
//						Script name: Tires Damage                             //
//                      Author: Snoowker                                      //
//                      Date of creation: 31-03-2012 01:54                    //
//                      Skype: snoowker                                       //
////////////////////////////////////////////////////////////////////////////////

#include <a_samp>

#define PRESSED(%0) \
	(((newkeys & (%0)) == (%0)) && ((oldkeys & (%0)) != (%0)))
	
//------------------------------------------------------------------------------
// Congiguration (RECOMMENDED!)
#define MIN_SLOW_TIME 		20
#define MAX_SLOW_TIME       40
#define MAX_SLOW_SPEED 		7
#define SLOW_KEY_ID 		40
#define NEED_TIRES_STATE 	5
#define TIMER_DURATION      1
//------------------------------------------------------------------------------

new
	td_BustTime[MAX_PLAYERS],
	td_TimerID;

public OnFilterScriptInit() {
	for(new td_i = 0, td_m = GetMaxPlayers(); td_i < td_m; td_i ++) {
		td_BustTime[td_i] = 0;
		DeletePVar(td_i, "td_vehicleid");
	}
	td_TimerID = SetTimer("td_CheckTires", TIMER_DURATION * 1000, true);
	print("Tires Damage script by Snoowker successfully loaded!");
	return 1;
}

public OnFilterScriptExit() {
	for(new td_i = 0, td_m = GetMaxPlayers(); td_i < td_m; td_i ++) {
		td_BustTime[td_i] = 0;
		DeletePVar(td_i, "td_vehicleid");
	}
	KillTimer(td_TimerID);
	print("Tires Damage script by Snoowker successfully unloaded!");
	return 1;
}

forward td_CheckTires();
public td_CheckTires() {
 	new
		td_Keys,
		td_ud,
		td_lr,
		td_vehicleid,
		td_panels,
		td_doors,
		td_lights,
		td_tires,
		td_NeedTimeToDamage;
	for(new td_i = 0, td_m = GetMaxPlayers(); td_i < td_m; td_i ++) {
		if(!IsPlayerConnected(td_i) || GetPlayerState(td_i) != PLAYER_STATE_DRIVER || td_BustTime[td_i] == 0) continue;
		td_vehicleid = GetPlayerVehicleID(td_i);
		if(td_vehicleid != GetPVarInt(td_i, "td_vehicleid")) {
			td_BustTime[td_i] = 0;
			DeletePVar(td_i, "td_vehicleid");
			continue;
		}
		GetPlayerKeys(td_i, td_Keys, td_ud, td_lr);
		if(!(td_Keys & SLOW_KEY_ID || td_Keys == SLOW_KEY_ID)) {
			td_BustTime[td_i] = 0;
			DeletePVar(td_i, "td_vehicleid");
			continue;
		}
		td_BustTime[td_i] += TIMER_DURATION;
		if(td_GetVehicleSpeed(td_vehicleid) >= MAX_SLOW_SPEED) continue;
		td_NeedTimeToDamage = MIN_SLOW_TIME + random(MAX_SLOW_TIME - MIN_SLOW_TIME + 1);
		if(td_BustTime[td_i] >= td_NeedTimeToDamage) {
            GetVehicleDamageStatus(td_vehicleid, td_panels, td_doors, td_lights, td_tires);
			UpdateVehicleDamageStatus(td_vehicleid, td_panels, td_doors, td_lights, NEED_TIRES_STATE);
			td_BustTime[td_i] = 0;
			DeletePVar(td_i, "td_vehicleid");
			continue;
		}
	}
	return 1;
}

public OnPlayerConnect(playerid) {
	td_BustTime[playerid] = 0;
	return 1;
}

public OnPlayerDisconnect(playerid, reason) {
    td_BustTime[playerid] = 0;
	return 1;
}

public OnPlayerStateChange(playerid, newstate, oldstate) {
	if(oldstate == PLAYER_STATE_DRIVER) {
		td_BustTime[playerid] = 0;
		DeletePVar(playerid, "td_vehicleid");
	}
	return 1;
}

public OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
	if(PRESSED(SLOW_KEY_ID) && GetPlayerState(playerid) == PLAYER_STATE_DRIVER && !td_BustTime[playerid] && IsVehicleRD(GetPlayerVehicleID(playerid))) {
	    new
			td_vehicleid = GetPlayerVehicleID(playerid),
			td_panels,
			td_doors,
			td_lights,
			td_tires;
		GetVehicleDamageStatus(td_vehicleid, td_panels, td_doors, td_lights, td_tires);
		if(td_tires != NEED_TIRES_STATE) {
			td_BustTime[playerid] = 1;
			SetPVarInt(playerid, "td_vehicleid", td_vehicleid);
		}
	}
	return 1;
}

td_GetVehicleSpeed(td_carid) {
    new
		Float: td_Velocity[3];
    GetVehicleVelocity(td_carid, td_Velocity[0], td_Velocity[1], td_Velocity[2]);
    return floatround(floatsqroot(td_Velocity[0] * td_Velocity[0] + td_Velocity[1] * td_Velocity[1] + td_Velocity[2] * td_Velocity[2]) * 100);
}

IsVehicleRD(td_vehicleid) {
	new
		td_model = GetVehicleModel(td_vehicleid);
	switch(td_model) {
		case
			400, 402, 403, 405, 406, 407, 408, 409, 411, 412, 413, 414, 415, 416,
			418, 419, 421, 422, 423, 424, 426, 427, 428, 429, 431, 433, 434, 437,
			438, 439, 442, 443, 444, 448, 451, 455, 456, 457, 458, 459, 461, 462,
			463, 466, 467, 468, 470, 471, 475, 477, 478, 480, 482, 483, 485, 486,
			489, 490, 491, 492, 494, 495, 498, 499, 500, 502, 503, 504, 505, 506,
			507, 508, 514, 515, 517, 518, 521..529, 531, 533..536, 541..547, 549,
			551, 552, 554..558, 560..562, 566..568, 571..576, 578..583, 585..588,
			596..605, 609: return 1;
		default:
			return 0;
	}
	return 0;
}

////////////////////////////////////////////////////////////////////////////////
//						Script name: Tires Damage                             //
//                      Author: Snoowker                                      //
//                      Date of creation: 31-03-2012                          //
//                      Skype: snoowker                                       //
////////////////////////////////////////////////////////////////////////////////
