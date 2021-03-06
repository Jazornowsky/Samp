/*
*       SA:MP Surface To Air Missiles (SAMsites)
*		Version: 0.4
*		(c) Copyright 2010 - 2011 by Awaran
*		@date Jan 18 2010
*
* Do not re-distribute. File is given 'AS IS' (no warranties)
*
* Always pay credits to authors
*
*
*/

/* SYSTEM CONFIG */
#define MAX_SAMS 32
#define INVALID_SAM_ID 255
#define DEFAULT_MISSILE_SPEED 70
#define DEFAULT_SAM_RANGE 300
#define MISSILE_DRAG_TIME 8000 //milliseconds
#define SAM_RADAR_LIMIT 1.000
#define RESTART_INTERVAL 1800000

new sOBJECT[MAX_SAMS];
new resttime;
new samset;

enum SamS
{
	samida,
	Float:SX,
	Float:SY,
	Float:SZ,
	Float:speed,
	Float:rangeSam,
	Float:radar,
	chaseid,
	Fired,
	Ex,
	cancel,                    
};

new Sam[MAX_SAMS][SamS];
new Missile[MAX_SAMS];
new FireMissileKill[MAX_SAMS];
new FireMissileKill2[MAX_SAMS];
new DragKill[MAX_SAMS];
new Text3D:SamLabel[MAX_SAMS];
forward OnSamSiteUpdate(samid, playerid);
forward OnSamSiteRestarted();
/* natives
native AddStaticSAM(Float:XSam, Float:YSam, Float:ZSam);
native AddStaticSAMEx(Float:XSam, Float:YSam, Float:ZSam, srange, sspeed);
native CreateSAM(Float:XSam, Float:YSam, Float:ZSam, Float:rX, Float:rY, Float:rZ);
native CreateSAMEx(Float:XSam, Float:YSam, Float:ZSam, Float:rX, Float:rY, Float:rZ, srange, sspeed);
native CreateSamLabel(samid, label[], color, Float:DrawDistance, LOS);
native SAM_start();
native SAM_cancel(samid);
*/

stock AddStaticSAM(Float:XSam, Float:YSam, Float:ZSam)
{
	new samid = samset;
	if(samset > MAX_SAMS-1)
	{
		print("[SAM] Error - Script exceeds max limit");
		samid = INVALID_SAM_ID;
		return samid;
	}
	samset++;
	Sam[samid][samida] = samid;
	Sam[samid][SX] = XSam;
	Sam[samid][SY] = YSam;
	Sam[samid][SZ] = ZSam;
    Sam[samid][speed] = DEFAULT_MISSILE_SPEED;
    Sam[samid][rangeSam] = DEFAULT_SAM_RANGE;
    Sam[samid][radar] = SAM_RADAR_LIMIT;
    Sam[samid][chaseid] = -1;
	Sam[samid][Fired] = 0;
	Sam[samid][Ex] = 0;
	// printf("[SAM] SAM %d Created - %f,%f,%f -",samid,X,Y,Z);
	return samid;
}

stock AddStaticSAMEx(Float:XSam, Float:YSam, Float:ZSam, Float:srange, Float:sspeed)
{
	new samid = samset;
	if(samset > MAX_SAMS-1)
	{
		print("[SAM] Error - Script exceeds max limit");
		samid = INVALID_SAM_ID;
		return samid;
	}
	samset++;
	Sam[samid][samida] = samid;
	Sam[samid][SX] = XSam;
	Sam[samid][SY] = YSam;
	Sam[samid][SZ] = ZSam;
    Sam[samid][speed] = sspeed;
    Sam[samid][rangeSam] = srange;
    Sam[samid][radar] = SAM_RADAR_LIMIT;
    Sam[samid][chaseid] = -1;
    Sam[samid][Fired] = 0;
    Sam[samid][Ex] = 1;
    // printf("[SAM] SAM %d Created - %f,%f,%f -",samid,XSam,YSam,ZSam);
    return samid;
}

stock CreateSAM(Float:XSam, Float:YSam, Float:ZSam, Float:rX, Float:rY, Float:rZ)
{
    new samid = samset;
    if(samset > MAX_SAMS-1)
	{
		print("[SAM] Error - Script exceeds max limit");
		samid = INVALID_SAM_ID;
		return samid;
	}
	samset++;
	Sam[samid][samida] = samid;
	Sam[samid][SX] = XSam;
	Sam[samid][SY] = YSam;
	Sam[samid][SZ] = ZSam;
    Sam[samid][speed] = DEFAULT_MISSILE_SPEED;
    Sam[samid][rangeSam] = DEFAULT_SAM_RANGE;
    Sam[samid][radar] = SAM_RADAR_LIMIT;
    Sam[samid][chaseid] = -1;
    Sam[samid][Fired] = 0;
    sOBJECT[samid] = CreateDynamicObject(3884,XSam,YSam,XSam,rX,rY,rZ);
    Sam[samid][Ex] = 0;
    // printf("[SAM] SAM %d Created - %f,%f,%f -",samid,XSam,YSam,ZSam);
    return samid;
}

stock CreateSAMEx(Float:XSam, Float:YSam, Float:ZSam, Float:rX, Float:rY, Float:rZ, Float:srange, Float:sspeed)
{
	new samid = samset;
	if(samset > MAX_SAMS-1)
	{
		print("[SAM] Error - Script exceeds max limit");
		samid = INVALID_SAM_ID;
		return samid;
	}
	samset++;
	Sam[samid][samida] = samid;
	Sam[samid][SX] = XSam;
	Sam[samid][SY] = YSam;
	Sam[samid][SZ] = ZSam;
    Sam[samid][speed] = sspeed;
    Sam[samid][rangeSam] = srange;
    Sam[samid][radar] = SAM_RADAR_LIMIT;
    Sam[samid][chaseid] = -1;
    Sam[samid][Fired] = 0;
    sOBJECT[samid] = CreateDynamicObject(3884,XSam,YSam,XSam,rX,rY,rZ);
    Sam[samid][Ex] = 1;
    // printf("[SAM] SAM %d Created - %f,%f,%f -",samid,X,Y,Z);
    return samid;
}

stock SAM_cancel(samid)
{
	Sam[samid][cancel] = 1;
}

stock SAM_start()
{
	resttime = SetTimer("SamLive",500,true);
	SetTimer("Restart",RESTART_INTERVAL,false);
	// print("\n--------------------------------------");
	print("[INCLUDE:] Surface To Air Missiles System (Re)Loaded v0.4");
	// print("                 0.4");
	// print("--------------------------------------\n");
	return 1;
}

stock CreateSamLabel(samid, label[], color, Float:DrawDistance, LOS)
{
	if(samid == INVALID_SAM_ID) return false;
	new string[128];
	format(string,sizeof(string),"%s(%d)",label,samid);
	SamLabel[samid] = Create3DTextLabel(string,color,Sam[samid][SX],Sam[samid][SY],Sam[samid][SZ] + 2.00,DrawDistance,0,LOS);
	return true;
}

stock GetMaxSams()
{
	return samset;
}

forward SamLive();
public SamLive()
{
	for(new s = 0; s <GetMaxSams(); s++)
	{
	    if(s != INVALID_SAM_ID)
		{
	    	SamConfig(s);
		}
	}
}

forward SamConfig(samid);
public SamConfig(samid)
{
	new Float:POS[3];
	for(new i = 0; i <MAX_PLAYERS; i++)
	{
	    if(IsPlayerConnected(i))
	    {
	        if(Sam[samid][Fired] == 0)
	        {
	            if(IsPlayerInAnyVehicle(i))
	            {
	                new veh = GetPlayerVehicleID(i);
	                if(IsAirVehicle(veh))
					{
					    GetVehiclePos(veh,POS[0],POS[1],POS[2]);
	        			if(IsAboveRadar(samid,POS[2]))
						{
						    if(Sam[samid][Ex] == 1)
						    {
	     	   				if(IsVehicleInRangeOfPoint(veh,Sam[samid][rangeSam],Sam[samid][SX],Sam[samid][SY],Sam[samid][SZ]))
						        {
						            OnSamSiteUpdate(samid, i);
						            if(Sam[samid][cancel] == 1)
									{
										Sam[samid][cancel] = 0;
										return 1;
									}
						            Missile[samid] = CreateObject(354,Sam[samid][SX],Sam[samid][SY],Sam[samid][SZ],0,0,0);
						            Sam[samid][Fired] = 1;
						            Sam[samid][chaseid] = veh;
						            FireSam(samid,i,veh);
								}
							}
							else
							{
							    if(IsVehicleInRangeOfPoint(veh,DEFAULT_SAM_RANGE,Sam[samid][SX],Sam[samid][SY],Sam[samid][SZ]))
	        					{
									OnSamSiteUpdate(samid, i);
									if(Sam[samid][cancel] == 1)
									{
										Sam[samid][cancel] = 0;
										return 1;
									}
		           		 			Missile[samid] = CreateObject(354,Sam[samid][SX],Sam[samid][SY],Sam[samid][SZ],0,0,0);
		          	  				Sam[samid][Fired] = 1;
		          	  				Sam[samid][chaseid] = veh;
		            				FireSam(samid,i,veh);
								}
							}
						}
					}
				}
			}
		}
	}
	return 1;
}

forward FireSam(samid, playerid, vehicleid);
public FireSam(samid, playerid, vehicleid)
{
	if(Sam[samid][chaseid] != vehicleid) return 1;
	FireMissileKill[samid] = SetTimerEx("Fire",500,true,"iii",playerid, samid, vehicleid);
	FireMissileKill2[samid] = SetTimerEx("Destroy",300,true,"iii",playerid,samid,vehicleid);
	DragKill[samid] = SetTimerEx("Drag",MISSILE_DRAG_TIME,false,"i",samid);
	return 1;
}

forward Fire(playerid, samid, vehicleid);
public Fire(playerid, samid, vehicleid)
{
	if(!IsPlayerConnected(playerid))
	{
	    KillTimer(FireMissileKill[samid]);
	    KillTimer(FireMissileKill2[samid]);
	    KillTimer(DragKill[samid]);
	    Drag(samid);
	    return 1;
	}
	if(vehicleid == Sam[samid][chaseid])
	{
	    new Float:XSam,
	        Float:YSam,
	        Float:ZSam;
		GetVehiclePos(vehicleid,XSam,YSam,ZSam);
		if(Sam[samid][Ex] == 1)
		{
		    StopObject(Missile[samid]);
		    MoveObject(Missile[samid],XSam,YSam,ZSam,Sam[samid][speed]);
		}
		else
		{
		    StopObject(Missile[samid]);
		    MoveObject(Missile[samid],XSam,YSam,ZSam,DEFAULT_MISSILE_SPEED);
		}
	}
	return 1;
}

forward Destroy(playerid, samid, vehicleid);
public Destroy(playerid, samid, vehicleid)
{
	new Float:OX,
		Float:OY,
		Float:OZ;
	GetObjectPos(Missile[samid],OX,OY,OZ);
	if(IsVehicleInRangeOfPoint(vehicleid,3,OX,OY,OZ))
	{
	    CreateExplosion(OX,OY,OZ,2,10);
	    CreateExplosion(OX,OY,OZ,2,10);
	    CreateExplosion(OX,OY,OZ,2,10);
		KillTimer(FireMissileKill[samid]);
		KillTimer(FireMissileKill2[samid]);
		DecreaseVehicleHealth(vehicleid, 50.0);
		KillTimer(DragKill[samid]);
		SetTimerEx("FireSet",5000,false,"i",samid);
		DestroyObject(Missile[samid]);
	}
	return 1;
}

forward FireSet(samid);
public FireSet(samid)
{
	Sam[samid][Fired] = 0;
}

forward Drag(samid);
public Drag(samid)
{
	new Float:OX,
	    Float:OY,
	    Float:OZ;
	GetObjectPos(Missile[samid],OX,OY,OZ);
	CreateExplosion(OX,OY,OZ,2,2.00);
    CreateExplosion(OX,OY,OZ,2,2.00);
    CreateExplosion(OX,OY,OZ,2,2.00);
    Sam[samid][Fired] = 0;
    DestroyObject(Missile[samid]);
}

forward Restart();
public Restart()
{
	KillTimer(resttime);
	for(new samid = 0; samid < GetMaxSams(); samid++)
	{
		Sam[samid][samida] = INVALID_SAM_ID;
		Sam[samid][SX] = 0.0;
		Sam[samid][SY] = 0.0;
		Sam[samid][SZ] = 0.0;
	    Sam[samid][speed] = 0.0;
	    Sam[samid][rangeSam] = 0.0;
	    Sam[samid][radar] = 0.0;
	    Sam[samid][chaseid] = -1;
		Sam[samid][Fired] = 0;
		Sam[samid][Ex] = 0;
	}
	samset = 0;
	OnSamSiteRestarted();
}

stock IsAirVehicle(carid)
{
    new AirVeh[] = { 592, 577, 511, 512, 593, 520, 553, 476, 519, 460, 513, 548, 425, 417, 487, 488, 497, 563, 447, 469 };
    for(new i = 0; i < sizeof(AirVeh); i++)
    {
        if(GetVehicleModel(carid) == AirVeh[i]) return 1;
    }
    return 0;
}

stock DecreaseVehicleHealth(vehicleid, Float:decreaseby)
{
	new Float:voldhp;
	GetVehicleHealth(vehicleid, voldhp);
	return SetVehicleHealth(vehicleid,voldhp - decreaseby);
}

IsVehicleInRangeOfPoint(vehicleid, Float:vrange, Float:x, Float:y, Float:z)
{
	new Float:oldpos[3],
	    Float:temppos[3];
	GetVehiclePos(vehicleid, oldpos[0], oldpos[1], oldpos[2]);
	temppos[0] = (oldpos[0] -x);
	temppos[1] = (oldpos[1] -y);
	temppos[2] = (oldpos[2] -z);
	if(((temppos[0] < vrange) && (temppos[0] > -vrange)) && ((temppos[1] < vrange) && (temppos[1] > -vrange)) && ((temppos[2] < vrange) && (temppos[2] > -vrange)))
	{
	    return true;
	}
	return false;
}

forward IsAboveRadar(samid, Float:value);
public IsAboveRadar(samid, Float:value)
{
	if(value > Sam[samid][SZ] + SAM_RADAR_LIMIT) return true;
	else return false;
}

