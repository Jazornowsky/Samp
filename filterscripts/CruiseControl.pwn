// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// Cruise Control FilterScript for SAMP 0.3
// 4th March 2010 (My birthday :)
// By Mick88
// Visit my server:
// Convoy Trucking (Cruise Control implemented)
// 91.204.163.105:7931
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------

#include <a_samp>

#define COLOR_MESSAGE_YELLOW 0xFFDD00AA
#define COLOR_GREY 0xAFAFAFAA


new Float:PlayerCruiseSpeed[MAX_PLAYERS];
new Float:PlayerHeadingAngle[MAX_PLAYERS];
new CCKey = KEY_ACTION; //Cruise Control Key - change this if you need
/*  keys that can be used:
	KEY_ACTION (LCTRL)
	KEY_FIRE (mouse click)
	KEY_SUBMISSION (2)
	KEY_LOOK_BEHIND
	or others you know
*/

forward CruiseControl(playerid);

public OnPlayerCommandText(playerid, cmdtext[])
{
    new cmd[256];
	new idx;
	
	cmd = strtok(cmdtext, idx);
	
	if (strcmp(cmd, "/tempomat", true) == 0)
	{
      	SendClientMessage(playerid, COLOR_MESSAGE_YELLOW, "[INFO:] Tempomat by mick88");
      	SendClientMessage(playerid, COLOR_MESSAGE_YELLOW, "Tempomat pozwala na utrzymanie sta�ej pr�dko�ci bez potrzeby ci�g�ego wciskania klawisza W");
      	SendClientMessage(playerid, COLOR_MESSAGE_YELLOW, "Aby u�y� tempomatu rozp�d� sw�j pojazd do odpowiedniej pr�dko�ci i przytrzymaj klawisz LCTRL");
      	return 1;
    }
	return 0;
}

public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	if ((newkeys & CCKey) && !(oldkeys & CCKey) && IsPlayerInAnyVehicle(playerid) && GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
	{
	    new vid = GetPlayerVehicleID(playerid);
		if (GetVehicleSpeed(vid) == 0) return false;
		new Float:x, Float:y, Float:z;
		GetVehicleVelocity(vid, x, y, z);
		GetVehicleZAngle(vid, PlayerHeadingAngle[playerid]);
		DistanceFlat(0, 0, x, y, PlayerCruiseSpeed[playerid]);
	    SetTimerEx("CruiseControl", 250, false, "d", playerid);
	    //SendClientMessage(playerid, COLOR_GREY, "* Cruise control engaged"); // === Remove this if not needed ===
	}
	else if (PlayerCruiseSpeed[playerid] != 0.00 && (newkeys & KEY_HANDBRAKE)) 
	{
	    PlayerCruiseSpeed[playerid] = 0.00;
	}
	return 1;
}

GetVehicleSpeed(vehicleid)
{
	new Float:Vx, Float:Vy, Float:Vz;
	GetVehicleVelocity(vehicleid, Vx, Vy, Vz);
    new Float:rtn;
    rtn = floatsqroot(floatpower(Vx*100,2) + floatpower(Vy*100,2));
    rtn = floatsqroot(floatpower(rtn,2) + floatpower(Vz*100,2));
    return floatround(rtn);
}

DistanceFlat(Float:ax, Float:ay, Float:bx,Float:by, &Float:distance)
{
	distance = floatsqroot(floatpower(bx-ax,2)+floatpower(by-ay,2));
	return floatround(distance);
}

public CruiseControl(playerid)
{
    new vid = GetPlayerVehicleID(playerid);
    new Float:x, Float:y, Float:z;
	GetVehicleVelocity(vid, x, y, z);

	new keys, ud, lr;
	GetPlayerKeys(playerid, keys, ud, lr);

	new Float:angle, Float:heading, Float:speed;
	GetVehicleZAngle(vid, angle);
	GetVehicleHeadingAngle(vid, heading);
	DistanceFlat(0, 0, x, y, speed);


	if (!(keys & CCKey) || PlayerCruiseSpeed[playerid] == 0.00 || //If player released LCTRL or CruiseSpeed got cancelled by other means (spacebar press)
	GetPlayerState(playerid) != PLAYER_STATE_DRIVER ||
	(speed < 0.7 * PlayerCruiseSpeed[playerid]) || //if player slowed down too much
	z > 1 || //if car is going upwards too fast
	(floatabs(angle - heading) > 50 && floatabs(angle - heading) < 310))//if vehicle goes sideways
	{                                   //Cruise control will turn off:
	    PlayerCruiseSpeed[playerid] = 0.00;
	    //SendClientMessage(playerid, COLOR_GREY, "*Cruse control disengaged"); // === Remove this if not needed ===
		return false;
	}
	GetVehicleZAngle(vid, PlayerHeadingAngle[playerid]);
	GetXYVelocity(vid, x, y, PlayerCruiseSpeed[playerid]);
	SetVehicleVelocity(vid, x, y, z);
	return SetTimerEx("CruiseControl", 250, false, "d", playerid);
}

GetXYVelocity(vehicleid, &Float:x, &Float:y, Float:speed)
{
	new Float:a;
	x = 0.0;
	y = 0.0;
	GetVehicleZAngle(vehicleid, a);
	x += (speed * floatsin(-a, degrees));
	y += (speed * floatcos(-a, degrees));
}

GetAngleToXY(Float:X, Float:Y, Float:CurrentX, Float:CurrentY, &Float:Angle)
{
    Angle = atan2(Y-CurrentY, X-CurrentX);
    Angle = floatsub(Angle, 90.0);
    if(Angle < 0.0) Angle = floatadd(Angle, 360.0);
}

GetVehicleHeadingAngle(vehicleid, &Float:a)
{
	new Float:x, Float:y, Float:z;
	GetVehicleVelocity(vehicleid, x, y, z);
	GetAngleToXY(x, y, 0, 0, a);
}

strtok(const string[], &index)
{
	new length = strlen(string);
	while ((index < length) && (string[index] <= ' '))
	{
		index++;
	}

	new offset = index;
	new result[20];
	while ((index < length) && (string[index] > ' ') && ((index - offset) < (sizeof(result) - 1)))
	{
		result[index - offset] = string[index];
		index++;
	}
	result[index - offset] = EOS;
	return result;
}

