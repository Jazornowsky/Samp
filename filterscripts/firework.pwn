//!:.:!:.:!:.:!:.:!:.:!:.:!:.:!:.:![Made by Notime]!:.:!:.:!:.:!:.:!:.:!:.:!:.:!:.:!
#include <a_samp>
#include <djson>
#include <audio>
// This is a comment
// uncomment the line below if you want to write a filterscript
//#define FILTERSCRIPT
#define dcmd(%1,%2,%3) if ((strcmp((%3)[1], #%1, true, (%2)) == 0) && ((((%3)[(%2) + 1] == 0) && (dcmd_%1(playerid, "")))||(((%3)[(%2) + 1] == 32) && (dcmd_%1(playerid, (%3)[(%2) + 2]))))) return 1
#define COLOR_TAN 0xBDB76BAA
#define RED 		0xE60000FF
#define WHITE 		0xFFFFFFFF
#define MAX_LIGHTS 100
#define MAX_PARTS 13
#define Sprinkleid 52
#define RBSprinkleid 50

//dialog id's

#define FWCPM 500
#define FWCPDD 501
#define FWCPFC 502
#define FWCPFR1 503
#define FWCPFR2 504
#define FWCPCR 505
#define FWCPFT1 506
#define FWCPFT2 507
#define FWCPFT3 508
#define FWCPRB 509

new Float:FRX[MAX_PLAYERS], Float:FRY[MAX_PLAYERS], Float:FRZ[MAX_PLAYERS];
new Float:FTX[MAX_PLAYERS], Float:FTY[MAX_PLAYERS], Float:FTZ[MAX_PLAYERS];
new Float:RBX[MAX_PLAYERS], Float:RBY[MAX_PLAYERS], Float:RBZ[MAX_PLAYERS];
new firecrackertime[MAX_PLAYERS];
new firerockettime[MAX_PLAYERS];
new explosionrocket[MAX_PLAYERS];
new Firecracker[MAX_PLAYERS];
new Firerocket[MAX_PLAYERS];
new rocketsmoke[MAX_PLAYERS];
new FireCrackerRoll[MAX_PLAYERS];
new firecrackerroll[MAX_PLAYERS];
new CrackerRollSmoke[MAX_PLAYERS];
new Float:RollStartX[MAX_PLAYERS], Float:RollStartY[MAX_PLAYERS], Float:RollStartZ[MAX_PLAYERS];
new backgroundnoise[MAX_PLAYERS];

new RocketBoxTime[MAX_PLAYERS];
new RocketBox[MAX_PLAYERS];
new RocketBoxSmoke[MAX_PLAYERS];

new FountainSmoke[MAX_PLAYERS];
new Fountain[MAX_PLAYERS];

new Light[MAX_LIGHTS][MAX_PLAYERS];
new RollParts[MAX_PLAYERS][MAX_PARTS];
new FountainSprinkle[Sprinkleid][MAX_PLAYERS];

new RocketBoxSprinkle[RBSprinkleid][MAX_PLAYERS];
new RocketBoxSprinkle2[RBSprinkleid][MAX_PLAYERS];
new RocketBoxSprinkle3[RBSprinkleid][MAX_PLAYERS];
new RBLight[MAX_LIGHTS][MAX_PLAYERS];

new Fountain1Time[MAX_PLAYERS];
new Fountain2Time[MAX_PLAYERS];
new Fountain3Time[MAX_PLAYERS];
new DestroySprinkleID[MAX_PLAYERS];

new DrawDistanceWord[][32] =
{
	{"Low"},
	{"Medium"},
	{"High"}
};

new UsageFW[][32] =
{
	{"All"},
	{"Rcon Only"}
};

enum FWN
{
    FireCracker,
    Firerocket1,
    Firerocket2,
    Crackerroll,
    Fountain1,
    Fountain2,
    Fountain3,
    RocketB,
    DrawDistance,
};
new AllowedFirework[FWN];

forward LoadFireWorkInfo();
forward SaveFireWorkInfo();
forward FirecrackerTime(playerid);
forward CrackerRollTime(playerid);
forward FirerocketTime(playerid);
forward splittime(playerid);
forward splittime2(playerid);
forward splittime3(playerid);
forward lighttimer(playerid);
forward lighttimer2(playerid);
forward CreateRoll(Rollid, Float:X, Float:Y, Float:Z);
forward DestroyRoll(Rollid);
forward FountainTimer(playerid);
forward Destroy1Sprinkle(playerid);
forward Destroy3Sprinkle(playerid);
forward LastSprinkles(playerid);
forward RocketBoxTimer(playerid);
forward SplitRBSprinkle(lightobject, playerid);
forward DestroyRBLight(playerid);

stock ProxDetector(Float:radi, playerid, string[],col1,col2,col3,col4,col5)
{
	if(IsPlayerConnected(playerid))
	{
		new Float:posx, Float:posy, Float:posz;
		new Float:oldposx, Float:oldposy, Float:oldposz;
		new Float:tempposx, Float:tempposy, Float:tempposz;
		GetPlayerPos(playerid, oldposx, oldposy, oldposz);
		//radi = 2.0; //Trigger Radius
		for(new i = 0; i < MAX_PLAYERS; i++)
		{
			if(IsPlayerConnected(i))
			{
				if(IsPlayerConnected(i))
				{
					GetPlayerPos(i, posx, posy, posz);
					tempposx = (oldposx -posx);
					tempposy = (oldposy -posy);
					tempposz = (oldposz -posz);
					//printf("DEBUG: X:%f Y:%f Z:%f",posx,posy,posz);
					if (((tempposx < radi/16) && (tempposx > -radi/16)) && ((tempposy < radi/16) && (tempposy > -radi/16)) && ((tempposz < radi/16) && (tempposz > -radi/16)))
					{
						SendClientMessage(i, col1, string);
					}
					else if (((tempposx < radi/8) && (tempposx > -radi/8)) && ((tempposy < radi/8) && (tempposy > -radi/8)) && ((tempposz < radi/8) && (tempposz > -radi/8)))
					{
						SendClientMessage(i, col2, string);
					}
					else if (((tempposx < radi/4) && (tempposx > -radi/4)) && ((tempposy < radi/4) && (tempposy > -radi/4)) && ((tempposz < radi/4) && (tempposz > -radi/4)))
					{
						SendClientMessage(i, col3, string);
					}
					else if (((tempposx < radi/2) && (tempposx > -radi/2)) && ((tempposy < radi/2) && (tempposy > -radi/2)) && ((tempposz < radi/2) && (tempposz > -radi/2)))
					{
						SendClientMessage(i, col4, string);
					}
					else if (((tempposx < radi) && (tempposx > -radi)) && ((tempposy < radi) && (tempposy > -radi)) && ((tempposz < radi) && (tempposz > -radi)))
					{
						SendClientMessage(i, col5, string);
					}
				}
				else
				{
					SendClientMessage(i, col1, string);
				}
			}
		}
	}//not connected
	return 1;
}

stock Float:GetXYInFrontOfPlayer(playerid, &Float:x, &Float:y, Float:distance)
{
    new Float:a;
    GetPlayerPos(playerid, x, y, a);
    if (IsPlayerInAnyVehicle(playerid))
        GetVehicleZAngle(GetPlayerVehicleID(playerid), a);
    else
        GetPlayerFacingAngle(playerid, a);
    x += (distance * floatsin(-a, degrees));
    y += (distance * floatcos(-a, degrees));
    return a;
}

public LoadFireWorkInfo()
{
	new file[128];
	format(file, sizeof(file), "FireWorkInfo");
	if(fexist(file))
	{
	    AllowedFirework[FireCracker] = djInt(file,"FireCrackerAL");
	    AllowedFirework[Firerocket1] = djInt(file,"FireRocket1AL");
	    AllowedFirework[Firerocket2] = djInt(file,"FireRocket2AL");
	    AllowedFirework[Crackerroll] = djInt(file,"CrackerrollAL");
	    AllowedFirework[Fountain1] = djInt(file,"Fountain1AL");
	    AllowedFirework[Fountain2] = djInt(file,"Fountain2AL");
	    AllowedFirework[Fountain3] = djInt(file,"Fountain3AL");
	    AllowedFirework[RocketB] = djInt(file,"RocketBAL");
	    AllowedFirework[DrawDistance] = djInt(file,"DrawDistance");
	    print("[NotimeBot]: FireWorkInfo has succesfully loaded");
	    return 1;
	}
	else return print("[NotimeBot]: An error has occupied while loading the FireWorkInfo, no such file found");
}

public SaveFireWorkInfo()
{
	new file[128];
	format(file, sizeof(file), "FireWorkInfo");
	if(fexist(file))
	{
	    djSetInt(file,"FireCrackerAL", AllowedFirework[FireCracker]);
	    djSetInt(file,"FireRocket1AL", AllowedFirework[Firerocket1]);
	    djSetInt(file,"FireRocket2AL", AllowedFirework[Firerocket2]);
	    djSetInt(file,"CrackerrollAL", AllowedFirework[Crackerroll]);
	    djSetInt(file,"Fountain1AL", AllowedFirework[Fountain1]);
	    djSetInt(file,"Fountain2AL", AllowedFirework[Fountain2]);
	    djSetInt(file,"Fountain3AL", AllowedFirework[Fountain3]);
	    djSetInt(file,"RocketBAL", AllowedFirework[RocketB]);
	    djSetInt(file,"DrawDistance", AllowedFirework[DrawDistance]);
	    print("[NotimeBot]: FireWorkInfo has succesfully saved");
	    return 1;
	}
	else return print("[NotimeBot]: An error has occupied while loading the FireWorkInfo, no such file found");
}

public SplitRBSprinkle(lightobject, playerid)
{
	new Float:X, Float:Y, Float:Z, rand, id;
	GetObjectPos(RocketBoxSprinkle[RocketBoxTime[playerid]][playerid], X, Y, Z);
	CreateExplosion(X, Y, Z, 4, 0);
	for(new i = 0; i < 50; i++)
	{
		if(!IsPlayerConnected(i))
			continue;
		rand = random(4);
		if(rand == 0)
		{
			id = Audio_PlayStreamed(i, "http://wpartyrp.pl/firework_explosion1.mp3", false, false, false);
		}	
		else if(rand == 1)
		{
			id = Audio_PlayStreamed(i, "http://wpartyrp.pl/firework_explosion2.mp3", false, false, false);
		}	
		else if(rand == 2)
		{
			Audio_PlayStreamed(i, "http://wpartyrp.pl/firework_explosion3.mp3", false, false, false);
		}
		else if(rand == 3)
		{
			Audio_PlayStreamed(i, "http://wpartyrp.pl/firework_explosion4_mono.mp3", false, false, false);
		}	
	}
	DestroyObject(RocketBoxSprinkle[RocketBoxTime[playerid]][playerid]);
	RBLight[1][playerid] = CreateObject(lightobject, X, Y, Z, 0, 0, 0);
	MoveObject(RBLight[1][playerid], (X-(-10+(random(20)))), (Y-(0+(random(20)))), (Z+40+random(40)), (1+(random(5))));
	RBLight[2][playerid] = CreateObject(lightobject, X, Y, Z, 0, 0, 0);
	MoveObject(RBLight[2][playerid], (X+(20-(random(40)))), (Y+(0+(random(20)))), (Z+35+random(40)), (1+(random(5))));
	RBLight[3][playerid] = CreateObject(lightobject, X, Y, Z, 0, 0, 0);
	MoveObject(RBLight[3][playerid], (X-(0+(random(20)))), (Y+(0+(random(20)))), (Z+30+random(40)), (1+(random(5))));
	RBLight[4][playerid] = CreateObject(lightobject, X, Y, Z, 0, 0, 0);
	MoveObject(RBLight[4][playerid], (X+(20-(random(40)))), (Y-(0+(random(20)))), (Z+25+random(40)), (1+(random(5))));
	RBLight[5][playerid] = CreateObject(lightobject, X, Y, Z, 0, 0, 0);
	MoveObject(RBLight[5][playerid], (X+(20-(random(40)))), (Y-(0+(random(20)))), (Z+20+random(40)), (1+(random(5))));
	RBLight[6][playerid] = CreateObject(lightobject, X, Y, Z, 0, 0, 0);
	MoveObject(RBLight[6][playerid], (X+(20-(random(40)))), (Y-(0+(random(20)))), (Z+15+random(40)), (1+(random(5))));
	RBLight[7][playerid] = CreateObject(lightobject, X, Y, Z, 0, 0, 0);
	MoveObject(RBLight[7][playerid], (X+(20-(random(40)))), (Y-(0+(random(20)))), (Z+10+random(40)), (1+(random(5))));
	RBLight[8][playerid] = CreateObject(lightobject, X, Y, Z, 0, 0, 0);
	MoveObject(RBLight[8][playerid], (X+(20-(random(40)))), (Y-(0+(random(20)))), (Z+5+random(40)), (1+(random(5))));
	RBLight[9][playerid] = CreateObject(lightobject, X, Y, Z, 0, 0, 0);
	MoveObject(RBLight[9][playerid], (X+(20-(random(40)))), (Y-(0+(random(20)))), (Z+random(40)), (1+(random(5))));
	RBLight[10][playerid] = CreateObject(lightobject, X, Y, Z, 0, 0, 0);
	MoveObject(RBLight[10][playerid], (X+(20-(random(40)))), (Y-(0+(random(20)))), (Z-5+random(40)), (1+(random(5))));
	RBLight[11][playerid] = CreateObject(lightobject, X, Y, Z, 0, 0, 0);
	MoveObject(RBLight[11][playerid], (X+(20-(random(40)))), (Y-(0+(random(20)))), (Z-10+random(40)), (1+(random(5))));
	RBLight[12][playerid] = CreateObject(lightobject, X, Y, Z, 0, 0, 0);
	MoveObject(RBLight[12][playerid], (X+(20-(random(40)))), (Y-(0+(random(20)))), (Z-15+random(40)), (1+(random(5))));
	RBLight[13][playerid] = CreateObject(lightobject, X, Y, Z, 0, 0, 0);
	MoveObject(RBLight[13][playerid], (X+(20-(random(40)))), (Y-(0+(random(20)))), (Z-20+random(40)), (10+(random(5))));
	RBLight[14][playerid] = CreateObject(lightobject, X, Y, Z, 0, 0, 0);
	MoveObject(RBLight[14][playerid], (X+(20-(random(40)))), (Y-(0+(random(20)))), (Z-25+random(40)), (10+(random(5))));
	RBLight[15][playerid] = CreateObject(lightobject, X, Y, Z, 0, 0, 0);
	MoveObject(RBLight[15][playerid], (X+(20-(random(40)))), (Y-(0+(random(20)))), (Z-30+random(40)), (10+(random(5))));
	RBLight[16][playerid] = CreateObject(lightobject, X, Y, Z, 0, 0, 0);
	MoveObject(RBLight[16][playerid], (X+(20-(random(40)))), (Y-(0+(random(20)))), (Z-35+random(40)), (1+(random(5))));
	RBLight[17][playerid] = CreateObject(lightobject, X, Y, Z, 0, 0, 0);
	MoveObject(RBLight[17][playerid], (X+(20-(random(40)))), (Y-(0+(random(20)))), (Z-40+random(40)), (1+(random(5))));
	RBLight[18][playerid] = CreateObject(lightobject, X, Y, Z, 0, 0, 0);
	MoveObject(RBLight[18][playerid], (X+(20-(random(40)))), (Y-(0+(random(20)))), (Z-45+random(40)), (1+(random(5))));
	RBLight[19][playerid] = CreateObject(lightobject, X, Y, Z, 0, 0, 0);
	MoveObject(RBLight[19][playerid], (X+(20-(random(40)))), (Y-(0+(random(20)))), (Z-50+random(40)), (1+(random(5))));
	RBLight[20][playerid] = CreateObject(lightobject, X, Y, Z, 0, 0, 0);
	MoveObject(RBLight[20][playerid], (X+(20-(random(40)))), (Y-(0+(random(20)))), (Z-55+random(40)), (1+(random(5))));
	RBLight[21][playerid] = CreateObject(lightobject, X, Y, Z, 0, 0, 0);
	MoveObject(RBLight[21][playerid], (X+(20-(random(40)))), (Y-(0+(random(20)))), (Z-60+random(40)), (1+(random(5))));
	RBLight[22][playerid] = CreateObject(lightobject, X, Y, Z, 0, 0, 0);
	MoveObject(RBLight[22][playerid], (X+(20-(random(40)))), (Y-(0+(random(20)))), (Z-65+random(40)), (1+(random(5))));
	RBLight[23][playerid] = CreateObject(lightobject, X, Y, Z, 0, 0, 0);
	MoveObject(RBLight[23][playerid], (X+(20-(random(40)))), (Y-(0+(random(20)))), (Z-70+random(40)), (1+(random(5))));
	RBLight[24][playerid] = CreateObject(lightobject, X, Y, Z, 0, 0, 0);
	MoveObject(RBLight[24][playerid], (X+(20-(random(40)))), (Y-(0+(random(20)))), (Z-75+random(40)), (1+(random(5))));
	RBLight[25][playerid] = CreateObject(lightobject, X, Y, Z, 0, 0, 0);
	MoveObject(RBLight[25][playerid], (X+(20-(random(40)))), (Y-(0+(random(20)))), (Z-80+random(40)), (1+(random(5))));
	SetTimerEx("DestroyRBLight", 4000, 0, "i", playerid);
	return 1;
}

public DestroyRBLight(playerid)
{
	DestroyObject(RBLight[1][playerid]);
	DestroyObject(RBLight[2][playerid]);
	DestroyObject(RBLight[3][playerid]);
	DestroyObject(RBLight[4][playerid]);
	DestroyObject(RBLight[5][playerid]);
	DestroyObject(RBLight[6][playerid]);
	DestroyObject(RBLight[7][playerid]);
	DestroyObject(RBLight[8][playerid]);
	DestroyObject(RBLight[9][playerid]);
	DestroyObject(RBLight[10][playerid]);
	DestroyObject(RBLight[11][playerid]);
	DestroyObject(RBLight[12][playerid]);
	DestroyObject(RBLight[13][playerid]);
	DestroyObject(RBLight[14][playerid]);
	DestroyObject(RBLight[15][playerid]);
	DestroyObject(RBLight[16][playerid]);
	DestroyObject(RBLight[17][playerid]);
	DestroyObject(RBLight[18][playerid]);
	DestroyObject(RBLight[19][playerid]);
	DestroyObject(RBLight[20][playerid]);
	DestroyObject(RBLight[21][playerid]);
	DestroyObject(RBLight[22][playerid]);
	DestroyObject(RBLight[23][playerid]);
	DestroyObject(RBLight[24][playerid]);
	DestroyObject(RBLight[25][playerid]);	
	RocketBoxTime[playerid] = RocketBoxTime[playerid]+1;
	RocketBoxTimer(playerid);
	return 1;
}

public RocketBoxTimer(playerid)
{
	if(RocketBoxTime[playerid] == 50)
	{
	    RocketBoxTime[playerid] = 0;
	    DestroyObject(RocketBox[playerid]);
	    DestroyObject(RocketBoxSmoke[playerid]);
	    return 1;
	}
	if(RocketBoxTime[playerid] >= 1)
	{
	    new LightObject;
		if(RocketBoxTime[playerid] < 10 || (RocketBoxTime[playerid] > 20 && RocketBoxTime[playerid] <= 30) || (RocketBoxTime[playerid] > 40 && RocketBoxTime[playerid] <= 50))
		{
			switch(random(9))
			{
				case 0:
				{
					LightObject = 19288;
				}
				case 1:
				{
					LightObject = 1213;
				}
				case 2:
				{
					LightObject = 18728;
				}
				case 3:
				{
					LightObject = 19281;
				}
				case 4:
				{
					LightObject = 19282;
				}
				case 5:
				{
					LightObject = 19283;
				}
				case 6:
				{
					LightObject = 19284;
				}
				case 7:
				{
					LightObject = 19286;
				}
				case 8:
				{
					LightObject = 19287;
				}
			}
		}
		else
		{
			LightObject = 354;
		}
		new rand, id, Float:randX, Float:randY;
		randX = float(random(20));
		randY = float(random(20));
		for(new i = 0; i < 50; i++)
		{
			if(!IsPlayerConnected(i))
				continue;
			rand = random(3);
			if(rand == 0)
			{
				id = Audio_PlayStreamed(i, "http://wpartyrp.pl/firework_lauch1.mp3", false, false, false);
			}
			else if(rand == 1)
			{
				id = Audio_PlayStreamed(i, "http://wpartyrp.pl/firework_lauch2.mp3", false, false, false);
			}
			else if(rand == 2)
			{
				id = Audio_PlayStreamed(i, "http://wpartyrp.pl/firework_lauch3.mp3", false, false, false);
			}				
		}
	    RocketBoxSprinkle[RocketBoxTime[playerid]][playerid] = CreateObject(354, RBX[playerid], RBY[playerid], RBZ[playerid], 0, 0, 0);
		MoveObject(RocketBoxSprinkle[RocketBoxTime[playerid]][playerid], RBX[playerid]+randX, RBY[playerid]+randY, (RBZ[playerid]+50), 40);
		SetTimerEx("SplitRBSprinkle", 1500, 0, "ii",LightObject, playerid);
		return 1;
	}
	return 1;
}

public Destroy1Sprinkle(playerid)
{
	if(DestroySprinkleID[playerid] >= 50)
	{
	    new x;
	    for (x=0;x<Sprinkleid;x++)
		{
			DestroyObject(FountainSprinkle[x][playerid]);
		}
	    return 1;
	}
	if(DestroySprinkleID[playerid] >= 0)
	{
		DestroyObject(FountainSprinkle[DestroySprinkleID[playerid]][playerid]);
		DestroySprinkleID[playerid] = DestroySprinkleID[playerid]+1;
		return 1;
	}
	return 1;
}

public Destroy3Sprinkle(playerid)
{
	if(DestroySprinkleID[playerid] >= 50)
	{
	    new x;
	    for (x=0;x<Sprinkleid;x++)
		{
			DestroyObject(FountainSprinkle[x][playerid]);
		}
	    return 1;
	}
	if(DestroySprinkleID[playerid] >= 0)
	{
	    new Float:X, Float:Y, Float:Z;
	    GetObjectPos(FountainSprinkle[DestroySprinkleID[playerid]][playerid] ,X, Y, Z);
	    CreateExplosion(X, Y, Z, 12, 0);
		DestroyObject(FountainSprinkle[DestroySprinkleID[playerid]][playerid]);
		DestroySprinkleID[playerid] = DestroySprinkleID[playerid]+1;
		return 1;
	}
	return 1;
}

public LastSprinkles(playerid)
{
    Fountain1Time[playerid] = 0;
    Fountain2Time[playerid] = 0;
    Fountain3Time[playerid] = 0;
    DestroySprinkleID[playerid] = 0;
    return 1;
}

public FountainTimer(playerid)
{
	if(Fountain1Time[playerid] >= 50)
	{
	    DestroyObject(Fountain[playerid]);
	    DestroyObject(FountainSmoke[playerid]);
	    SetTimerEx("Destroy1Sprinkle", 300, 0, "i",playerid);
	    SetTimerEx("LastSprinkles", 600, 0, "i", playerid);
	    return 1;
	}
	if(Fountain1Time[playerid] >= 1)
	{
	    new Float:RandomXPos;
	    new Float:RandomYPos;
	    switch(random(2))
		{
			case 0:
			{
				RandomXPos = -(random(4));
			}
			case 1:
			{
				RandomXPos = (random(4));
			}
		}
	    switch(random(2))
		{
			case 0:
			{
				RandomYPos = -(random(4));
			}
			case 1:
			{
				RandomYPos = (random(4));
			}
		}
		FountainSprinkle[Fountain1Time[playerid]][playerid] = CreateObject(354, FTX[playerid], FTY[playerid], FTZ[playerid], 0, 0, 0);
		MoveObject(FountainSprinkle[Fountain1Time[playerid]][playerid], (FTX[playerid]+RandomXPos), (FTY[playerid]+RandomYPos), (FTZ[playerid]+80), 30);
		Fountain1Time[playerid] = Fountain1Time[playerid]+1;
		SetTimerEx("Destroy1Sprinkle", 300, 0, "i",playerid);
		SetTimerEx("FountainTimer", (100+(random(200))), 0, "i",playerid);
		return 1;
	}
	if(Fountain2Time[playerid] >= 50)
	{
	    DestroyObject(Fountain[playerid]);
	    DestroyObject(FountainSmoke[playerid]);
	    SetTimerEx("Destroy1Sprinkle", 300, 0, "i",playerid);
	    SetTimerEx("LastSprinkles", 600, 0, "i", playerid);
	    return 1;
	}
	if(Fountain2Time[playerid] >= 1)
	{
	    new Float:RandomXPos;
	    new Float:RandomYPos;
	    switch(random(2))
		{
			case 0:
			{
				RandomXPos = -(random(4));
			}
			case 1:
			{
				RandomXPos = (random(4));
			}
		}
	    switch(random(2))
		{
			case 0:
			{
				RandomYPos = -(random(4));
			}
			case 1:
			{
				RandomYPos = (random(4));
			}
		}
		FountainSprinkle[Fountain2Time[playerid]][playerid] = CreateObject(1213, FTX[playerid], FTY[playerid], FTZ[playerid], 0, 0, 0);
		MoveObject(FountainSprinkle[Fountain2Time[playerid]][playerid], (FTX[playerid]+RandomXPos), (FTY[playerid]+RandomYPos), (FTZ[playerid]+80), 30);
		Fountain2Time[playerid] = Fountain2Time[playerid]+1;
		SetTimerEx("Destroy1Sprinkle", 300, 0, "i",playerid);
		SetTimerEx("FountainTimer", (100+(random(200))), 0, "i",playerid);
		return 1;
	}
	if(Fountain3Time[playerid] >= 50)
	{
	    DestroyObject(Fountain[playerid]);
	    DestroyObject(FountainSmoke[playerid]);
	    SetTimerEx("Destroy3Sprinkle", 300, 0, "i",playerid);
	    SetTimerEx("LastSprinkles", 600, 0, "i", playerid);
	    return 1;
	}
	if(Fountain3Time[playerid] >= 1)
	{
	    new Float:RandomXPos;
	    new Float:RandomYPos;
	    new RandomLight;
	    switch(random(2))
		{
			case 0:
			{
				RandomXPos = -(random(50));
			}
			case 1:
			{
				RandomXPos = (random(50));
			}
		}
	    switch(random(2))
		{
			case 0:
			{
				RandomYPos = -(random(50));
			}
			case 1:
			{
				RandomYPos = (random(50));
			}
		}
		switch(random(2))
		{
			case 0:
			{
				RandomLight = 354;
			}
			case 1:
			{
				RandomLight = 1213;
			}
		}
		FountainSprinkle[Fountain3Time[playerid]][playerid] = CreateObject(RandomLight, FTX[playerid], FTY[playerid], FTZ[playerid], 0, 0, 0);
		MoveObject(FountainSprinkle[Fountain3Time[playerid]][playerid], (FTX[playerid]+RandomXPos), (FTY[playerid]+RandomYPos), (FTZ[playerid]+120), 30);
		Fountain3Time[playerid] = Fountain3Time[playerid]+1;
		SetTimerEx("Destroy3Sprinkle", 300, 0, "i",playerid);
		SetTimerEx("FountainTimer", (100+(random(200))), 0, "i",playerid);
		return 1;
	}
	return 1;
}

public CreateRoll(Rollid, Float:X, Float:Y, Float:Z)
{
	RollParts[Rollid][1] = CreateObject(1654,X,Y,Z, 90, 90, 0);
	RollParts[Rollid][2] = CreateObject(1654,(X+0.25),Y,Z, 90, 90, 0);
	RollParts[Rollid][3] = CreateObject(1654,(X+0.50),Y,Z, 90, 90, 0);
	RollParts[Rollid][4] = CreateObject(1654,(X+0.75),Y,Z, 90, 90, 0);
	RollParts[Rollid][5] = CreateObject(1654,(X+1.00),Y,Z, 90, 90, 0);
	RollParts[Rollid][6] = CreateObject(1654,(X+1.25),Y,Z, 90, 90, 0);
	RollParts[Rollid][7] = CreateObject(1654,X,(Y+0.1),Z, 90, 90, 0);
	RollParts[Rollid][8] = CreateObject(1654,(X+0.25),(Y+0.1),Z, 90, 90, 0);
	RollParts[Rollid][9] = CreateObject(1654,(X+0.50),(Y+0.1),Z, 90, 90, 0);
	RollParts[Rollid][10] = CreateObject(1654,(X+0.75),(Y+0.1),Z, 90, 90, 0);
	RollParts[Rollid][11] = CreateObject(1654,(X+1.00),(Y+0.1),Z, 90, 90, 0);
	RollParts[Rollid][12] = CreateObject(1654,(X+1.25),(Y+0.1),Z, 90, 90, 0);
	return 1;
}

public DestroyRoll(Rollid)
{
	DestroyObject(RollParts[Rollid][1]);
	DestroyObject(RollParts[Rollid][2]);
	DestroyObject(RollParts[Rollid][3]);
	DestroyObject(RollParts[Rollid][4]);
	DestroyObject(RollParts[Rollid][5]);
	DestroyObject(RollParts[Rollid][6]);
	DestroyObject(RollParts[Rollid][7]);
	DestroyObject(RollParts[Rollid][8]);
	DestroyObject(RollParts[Rollid][9]);
	DestroyObject(RollParts[Rollid][10]);
	DestroyObject(RollParts[Rollid][11]);
	DestroyObject(RollParts[Rollid][12]);
	return 1;
}

public CrackerRollTime(playerid)
{
	if(firecrackerroll[playerid] == 1)
	{
	    DestroyObject(CrackerRollSmoke[playerid]);
	}
	if(firecrackerroll[playerid] == 49)
	{
	    firecrackerroll[playerid] = 0;
	    DestroyRoll(playerid);
	    return 1;
	}
	if(firecrackerroll[playerid] >= 1)
	{
	    new Float:X, Float:Y, Float:Z;
	    if(firecrackerroll[playerid] >= 1 && firecrackerroll[playerid] <= 4)
	    {
	        GetObjectPos(RollParts[playerid][1], X, Y, Z);
            DestroyRoll(playerid);
	        CreateExplosion(X, Y, Z, 12, 0);
	        CreateRoll(playerid, RollStartX[playerid], RollStartY[playerid], RollStartZ[playerid]);
	        firecrackerroll[playerid] = firecrackerroll[playerid]+1;
	        SetTimerEx("CrackerRollTime", (100+(random(200))), 0, "i", playerid);
	        return 1;
	    }
	    if(firecrackerroll[playerid] >= 5 && firecrackerroll[playerid] <= 8)
	    {
	        GetObjectPos(RollParts[playerid][2], X, Y, Z);
	        DestroyRoll(playerid);
	        CreateExplosion(X, Y, Z, 12, 0);
	        CreateRoll(playerid, RollStartX[playerid], RollStartY[playerid], RollStartZ[playerid]);
	        firecrackerroll[playerid] = firecrackerroll[playerid]+1;
	        SetTimerEx("CrackerRollTime", (100+(random(200))), 0, "i", playerid);
	        return 1;
	    }
	    if(firecrackerroll[playerid] >= 9 && firecrackerroll[playerid] <= 12)
	    {
	        GetObjectPos(RollParts[playerid][3], X, Y, Z);
	        DestroyRoll(playerid);
	        CreateExplosion(X, Y, Z, 12, 0);
	        CreateRoll(playerid, RollStartX[playerid], RollStartY[playerid], RollStartZ[playerid]);
	        firecrackerroll[playerid] = firecrackerroll[playerid]+1;
	        SetTimerEx("CrackerRollTime", (100+(random(200))), 0, "i", playerid);
	        return 1;
	    }
	    if(firecrackerroll[playerid] >= 13 && firecrackerroll[playerid] <= 16)
	    {
	        GetObjectPos(RollParts[playerid][4], X, Y, Z);
	        DestroyRoll(playerid);
	        CreateExplosion(X, Y, Z, 12, 0);
	        CreateRoll(playerid, RollStartX[playerid], RollStartY[playerid], RollStartZ[playerid]);
	        firecrackerroll[playerid] = firecrackerroll[playerid]+1;
	        SetTimerEx("CrackerRollTime", (100+(random(200))), 0, "i", playerid);
	        return 1;
	    }
	    if(firecrackerroll[playerid] >= 17 && firecrackerroll[playerid] <= 20)
	    {
	        GetObjectPos(RollParts[playerid][5], X, Y, Z);
	        DestroyRoll(playerid);
	        CreateExplosion(X, Y, Z, 12, 0);
	        CreateRoll(playerid, RollStartX[playerid], RollStartY[playerid], RollStartZ[playerid]);
	        firecrackerroll[playerid] = firecrackerroll[playerid]+1;
	        SetTimerEx("CrackerRollTime", (100+(random(200))), 0, "i", playerid);
	        return 1;
	    }
	    if(firecrackerroll[playerid] >= 21 && firecrackerroll[playerid] <= 24)
	    {
	        GetObjectPos(RollParts[playerid][6], X, Y, Z);
	        DestroyRoll(playerid);
	        CreateExplosion(X, Y, Z, 12, 0);
	        CreateRoll(playerid, RollStartX[playerid], RollStartY[playerid], RollStartZ[playerid]);
	        firecrackerroll[playerid] = firecrackerroll[playerid]+1;
	        SetTimerEx("CrackerRollTime", (100+(random(200))), 0, "i", playerid);
	        return 1;
	    }
	    if(firecrackerroll[playerid] >= 25 && firecrackerroll[playerid] <= 28)
	    {
	        GetObjectPos(RollParts[playerid][12], X, Y, Z);
	        DestroyRoll(playerid);
	        CreateExplosion(X, Y, Z, 12, 0);
	        CreateRoll(playerid, RollStartX[playerid], RollStartY[playerid], RollStartZ[playerid]);
	        firecrackerroll[playerid] = firecrackerroll[playerid]+1;
	        SetTimerEx("CrackerRollTime", (100+(random(200))), 0, "i", playerid);
	        return 1;
	    }
	    if(firecrackerroll[playerid] >= 29 && firecrackerroll[playerid] <= 32)
	    {
	        GetObjectPos(RollParts[playerid][11], X, Y, Z);
	        DestroyRoll(playerid);
	        CreateExplosion(X, Y, Z, 12, 0);
	        CreateRoll(playerid, RollStartX[playerid], RollStartY[playerid], RollStartZ[playerid]);
	        firecrackerroll[playerid] = firecrackerroll[playerid]+1;
	        SetTimerEx("CrackerRollTime", (100+(random(200))), 0, "i", playerid);
	        return 1;
	    }
	    if(firecrackerroll[playerid] >= 33 && firecrackerroll[playerid] <= 36)
	    {
	        GetObjectPos(RollParts[playerid][10], X, Y, Z);
	        DestroyRoll(playerid);
	        CreateExplosion(X, Y, Z, 12, 0);
	        CreateRoll(playerid, RollStartX[playerid], RollStartY[playerid], RollStartZ[playerid]);
	        firecrackerroll[playerid] = firecrackerroll[playerid]+1;
	        SetTimerEx("CrackerRollTime", (100+(random(200))), 0, "i", playerid);
	        return 1;
	    }
	    if(firecrackerroll[playerid] >= 37 && firecrackerroll[playerid] <= 40)
	    {
	        GetObjectPos(RollParts[playerid][9], X, Y, Z);
			DestroyRoll(playerid);
	        CreateExplosion(X, Y, Z, 12, 0);
	        CreateRoll(playerid, RollStartX[playerid], RollStartY[playerid], RollStartZ[playerid]);
	        firecrackerroll[playerid] = firecrackerroll[playerid]+1;
	        SetTimerEx("CrackerRollTime", (100+(random(200))), 0, "i", playerid);
	        return 1;
	    }
	    if(firecrackerroll[playerid] >= 41 && firecrackerroll[playerid] <= 44)
	    {
	        GetObjectPos(RollParts[playerid][8], X, Y, Z);
	        DestroyRoll(playerid);
	        CreateExplosion(X, Y, Z, 12, 0);
	        CreateRoll(playerid, RollStartX[playerid], RollStartY[playerid], RollStartZ[playerid]);
	        firecrackerroll[playerid] = firecrackerroll[playerid]+1;
	        SetTimerEx("CrackerRollTime", (100+(random(200))), 0, "i", playerid);
	        return 1;
	    }
	    if(firecrackerroll[playerid] >= 45 && firecrackerroll[playerid] <= 48)
	    {
	        GetObjectPos(RollParts[playerid][7], X, Y, Z);
	        DestroyRoll(playerid);
	        CreateExplosion(X, Y, Z, 12, 0);
	        CreateRoll(playerid, RollStartX[playerid], RollStartY[playerid], RollStartZ[playerid]);
	        firecrackerroll[playerid] = firecrackerroll[playerid]+1;
	        SetTimerEx("CrackerRollTime", (100+(random(200))), 0, "i", playerid);
	        return 1;
	    }
	    return 1;
	}
	return 1;
}

public FirecrackerTime(playerid)
{
	if(firecrackertime[playerid] == 1)
	{
	    new Float:X, Float:Y,Float:Z;
		GetObjectPos(Firecracker[playerid], X, Y, Z);
		CreateExplosion(X,Y,Z, 12, 0);
		DestroyObject(Firecracker[playerid]);
		firecrackertime[playerid] = 0;
		return 1;
	}
	return 1;
}

public FirerocketTime(playerid)
{
	if(firerockettime[playerid] == 1)
	{
		GetObjectPos(Firerocket[playerid], FRX[playerid], FRY[playerid], FRZ[playerid]);
		explosionrocket[playerid] = CreateExplosion(FRX[playerid], FRY[playerid], FRZ[playerid], 6, 0);
		SetTimerEx("splittime", 500, 0, "i", playerid);
		return 1;
	}
	if(firerockettime[playerid] == 2)
	{
		GetObjectPos(Firerocket[playerid], FRX[playerid], FRY[playerid], FRZ[playerid]);
		explosionrocket[playerid] = CreateExplosion(FRX[playerid], FRY[playerid], FRZ[playerid], 6, 0);
		SetTimerEx("splittime2", 100, 0, "i", playerid);
		return 1;
	}
	return 1;
}

public splittime(playerid)
{
	if(firerockettime[playerid] == 1)
	{
		CreateExplosion(FRX[playerid]-(0+(random(3))),FRY[playerid]-(0+(random(3))),FRZ[playerid]-(0+(random(3))), 4, 0);
		CreateExplosion(FRX[playerid]-(0+(random(3))),FRY[playerid]+(0+(random(3))),FRZ[playerid]-(0+(random(3))), 4, 0);
		CreateExplosion(FRX[playerid]-(0+(random(3))),FRY[playerid],FRZ[playerid]-(0+(random(3))), 4, 0);
		CreateExplosion(FRX[playerid]+(0+(random(3))),FRY[playerid]-(0+(random(3))),FRZ[playerid]-(0+(random(3))), 4, 0);
		CreateExplosion(FRX[playerid]+(0+(random(3))),FRY[playerid]+(0+(random(3))),FRZ[playerid]-(0+(random(3))), 4, 0);
		CreateExplosion(FRX[playerid]+(0+(random(3))),FRY[playerid],FRZ[playerid]-(0+(random(3))), 4, 0);
		CreateExplosion(FRX[playerid],FRY[playerid]-(0+(random(3))),FRZ[playerid]-(0+(random(3))), 4, 0);
		CreateExplosion(FRX[playerid],FRY[playerid]+(0+(random(3))),FRZ[playerid]-(0+(random(3))), 4, 0);
		Light[1][playerid] = CreateObject(354,FRX[playerid]-(0+(random(6))),FRY[playerid]-(0+(random(6))),FRZ[playerid]+(0+(random(6))), 0, 0,0);
		Light[2][playerid] = CreateObject(354,FRX[playerid]-(0+(random(6))),FRY[playerid],FRZ[playerid]+(0+(random(6))), 0, 0,0);
		Light[3][playerid] = CreateObject(354,FRX[playerid]-(0+(random(6))),FRY[playerid],FRZ[playerid]-(0+(random(6))), 0, 0,0);
		Light[4][playerid] = CreateObject(354,FRX[playerid]-(0+(random(6))),FRY[playerid]-(0+(random(6))),FRZ[playerid]+(0+(random(6))), 0, 0,0);
		Light[5][playerid] = CreateObject(354,FRX[playerid]-(0+(random(6))),FRY[playerid]+(0+(random(6))),FRZ[playerid]+(0+(random(6))), 0, 0,0);
		Light[6][playerid] = CreateObject(354,FRX[playerid]-(0+(random(6))),FRY[playerid],FRZ[playerid]-(0+(random(6))), 0, 0,0);
		Light[7][playerid] = CreateObject(354,FRX[playerid]-(0+(random(6))),FRY[playerid]-(0+(random(6))),FRZ[playerid]-(0+(random(6))), 0, 0,0);
		Light[8][playerid] = CreateObject(354,FRX[playerid],FRY[playerid]-(0+(random(6))),FRZ[playerid]+(0+(random(6))), 0, 0,0);
		new Float:X,Float:Y,Float:Z;
		GetObjectPos(Light[1][playerid], X, Y, Z);
		MoveObject(Light[1][playerid], X-(0+(random(6))), Y-(0+(random(6))), Z-20, 6);
		GetObjectPos(Light[2][playerid], X, Y, Z);
		MoveObject(Light[2][playerid], X-(0+(random(6))), Y+(0+(random(6))), Z-20, 5);
		GetObjectPos(Light[3][playerid], X, Y, Z);
		MoveObject(Light[3][playerid], X-(0+(random(6))), Y, Z-20, 4);
		GetObjectPos(Light[4][playerid], X, Y, Z);
		MoveObject(Light[4][playerid], X+(0+(random(6))), Y-(0+(random(6))), Z-20, 5);
		GetObjectPos(Light[5][playerid], X, Y, Z);
		MoveObject(Light[5][playerid], X+(0+(random(6))), Y+(0+(random(6))), Z-20, 5);
		GetObjectPos(Light[6][playerid], X, Y, Z);
		MoveObject(Light[6][playerid], X+(0+(random(6))), Y, Z-20, 4);
		GetObjectPos(Light[7][playerid], X, Y, Z);
		MoveObject(Light[7][playerid], X, Y-(0+(random(6))), Z-20, 6);
		GetObjectPos(Light[8][playerid], X, Y, Z);
		MoveObject(Light[8][playerid], X, Y+(0+(random(6))), Z-20, 5);
		SetTimerEx("lighttimer", 3900, 0, "i", playerid);
		DestroyObject(Firerocket[playerid]);
		DestroyObject(rocketsmoke[playerid]);
		return 1;
	}
	return 1;
}

public splittime2(playerid)
{
	if(firerockettime[playerid] == 2)
	{
		CreateExplosion(FRX[playerid]-(0+(random(10))),FRY[playerid]-(0+(random(10))),FRZ[playerid]-5, 6, 0);
		CreateExplosion(FRX[playerid]-(0+(random(10))),FRY[playerid]+(0+(random(10))),FRZ[playerid]-5, 6, 0);
		CreateExplosion(FRX[playerid]-(0+(random(10))),FRY[playerid],FRZ[playerid]-5, 6, 0);
		CreateExplosion(FRX[playerid]+(0+(random(10))),FRY[playerid]-(0+(random(10))),FRZ[playerid]-5, 6, 0);
		CreateExplosion(FRX[playerid]+(0+(random(10))),FRY[playerid]+(0+(random(10))),FRZ[playerid]-5, 6, 0);
		CreateExplosion(FRX[playerid]+(0+(random(10))),FRY[playerid],FRZ[playerid]-5, 6, 0);
		CreateExplosion(FRX[playerid],FRY[playerid]-(0+(random(10))),FRZ[playerid]-5, 6, 0);
		CreateExplosion(FRX[playerid],FRY[playerid]+(0+(random(10))),FRZ[playerid]-5, 6, 0);
		Light[1][playerid] = CreateObject(354,FRX[playerid]-(0+(random(10))),FRY[playerid]-(0+(random(10))),FRZ[playerid]-5, 0, 0,0);
		Light[2][playerid] = CreateObject(354,FRX[playerid]-(0+(random(10))),FRY[playerid]+(0+(random(10))),FRZ[playerid]-5, 0, 0,0);
		Light[3][playerid] = CreateObject(354,FRX[playerid]-(0+(random(10))),FRY[playerid],FRZ[playerid]-5, 0, 0,0);
		Light[4][playerid] = CreateObject(354,FRX[playerid]+(0+(random(10))),FRY[playerid]-(0+(random(10))),FRZ[playerid]-5, 0, 0,0);
		Light[5][playerid] = CreateObject(354,FRX[playerid]+(0+(random(10))),FRY[playerid]+(0+(random(10))),FRZ[playerid]-5, 0, 0,0);
		Light[6][playerid] = CreateObject(354,FRX[playerid]+(0+(random(10))),FRY[playerid],FRZ[playerid]-5, 0, 0,0);
		Light[7][playerid] = CreateObject(354,FRX[playerid],FRY[playerid]-(0+(random(10))),FRZ[playerid]-5, 0, 0,0);
		Light[8][playerid] = CreateObject(354,FRX[playerid],FRY[playerid]+(0+(random(10))),FRZ[playerid]-5, 0, 0,0);
		new Float:X,Float:Y,Float:Z;
		GetObjectPos(Light[1][playerid], X, Y, Z);
		MoveObject(Light[1][playerid], X-6, Y-6, Z-20, 4);
		GetObjectPos(Light[2][playerid], X, Y, Z);
		MoveObject(Light[2][playerid], X-6, Y+6, Z-20, 4);
		GetObjectPos(Light[3][playerid], X, Y, Z);
		MoveObject(Light[3][playerid], X-6, Y, Z-20, 4);
		GetObjectPos(Light[4][playerid], X, Y, Z);
		MoveObject(Light[4][playerid], X+6, Y-6, Z-20, 4);
		GetObjectPos(Light[5][playerid], X, Y, Z);
		MoveObject(Light[5][playerid], X+6, Y+6, Z-20, 4);
		GetObjectPos(Light[6][playerid], X, Y, Z);
		MoveObject(Light[6][playerid], X+6, Y, Z-20, 4);
		GetObjectPos(Light[7][playerid], X, Y, Z);
		MoveObject(Light[7][playerid], X, Y-6, Z-20, 4);
		GetObjectPos(Light[8][playerid], X, Y, Z);
		MoveObject(Light[8][playerid], X, Y+6, Z-20, 4);
		SetTimerEx("splittime3", 3000, 0, "i", playerid);
		DestroyObject(Firerocket[playerid]);
		DestroyObject(rocketsmoke[playerid]);
		return 1;
	}
	return 1;
}

public splittime3(playerid)
{
	if(firerockettime[playerid] == 2)
	{
		new Float:X,Float:Y,Float:Z;
		GetObjectPos(Light[1][playerid], X, Y, Z);
		CreateExplosion(X, Y, Z, 6, 0);
		GetObjectPos(Light[2][playerid], X, Y, Z);
		CreateExplosion(X, Y, Z, 6, 0);
		GetObjectPos(Light[3][playerid], X, Y, Z);
		CreateExplosion(X, Y, Z, 6, 0);
		GetObjectPos(Light[4][playerid], X, Y, Z);
		CreateExplosion(X, Y, Z, 6, 0);
		GetObjectPos(Light[5][playerid], X, Y, Z);
		CreateExplosion(X, Y, Z, 6, 0);
		GetObjectPos(Light[6][playerid], X, Y, Z);
		CreateExplosion(X, Y, Z, 6, 0);
		GetObjectPos(Light[7][playerid], X, Y, Z);
		CreateExplosion(X, Y, Z, 6, 0);
		GetObjectPos(Light[8][playerid], X, Y, Z);
		CreateExplosion(X, Y, Z, 6, 0);
		GetObjectPos(Light[9][playerid], X, Y, Z);
		Light[11][playerid] = CreateObject(1213,X-7,Y+7,Z+8, 0, 0,0);
		Light[12][playerid] = CreateObject(1213,X-7,Y,Z+5, 0, 0,0);
		Light[13][playerid] = CreateObject(1213,X,Y+7,Z-5, 0, 0,0);
		Light[14][playerid] = CreateObject(1213,X,Y-7,Z-5, 0, 0,0);
		GetObjectPos(Light[2][playerid], X, Y, Z);
		Light[15][playerid] = CreateObject(1213,X,Y-7,Z+5, 0, 0,0);
		Light[16][playerid] = CreateObject(1213,X-7,Y,Z-5, 0, 0,0);
		Light[17][playerid] = CreateObject(1213,X,Y+7,Z-8, 0, 0,0);
		Light[18][playerid] = CreateObject(1213,X,Y+7,Z-5, 0, 0,0);
		GetObjectPos(Light[3][playerid], X, Y, Z);
		Light[19][playerid] = CreateObject(1213,X+7,Y,Z-1, 0, 0,0);
		Light[20][playerid] = CreateObject(1213,X-7,Y,Z-8, 0, 0,0);
		Light[21][playerid] = CreateObject(1213,X+7,Y+7,Z-5, 0, 0,0);
		Light[22][playerid] = CreateObject(1213,X,Y,Z+5, 0, 0,0);
		GetObjectPos(Light[4][playerid], X, Y, Z);
		Light[23][playerid] = CreateObject(1213,X+7,Y-7,Z-5, 0, 0,0);
		Light[24][playerid] = CreateObject(1213,X-7,Y,Z-7, 0, 0,0);
		Light[25][playerid] = CreateObject(1213,X+7,Y+7,Z+5, 0, 0,0);
		Light[26][playerid] = CreateObject(1213,X,Y-7,Z, 0, 0,0);
		GetObjectPos(Light[5][playerid], X, Y, Z);
		Light[27][playerid] = CreateObject(1213,X,Y-7,Z-5, 0, 0,0);
		Light[28][playerid] = CreateObject(1213,X-7,Y,Z+8, 0, 0,0);
		Light[29][playerid] = CreateObject(1213,X+7,Y,Z-8, 0, 0,0);
		Light[30][playerid] = CreateObject(1213,X,Y+7,Z+5, 0, 0,0);
		GetObjectPos(Light[6][playerid], X, Y, Z);
		Light[31][playerid] = CreateObject(1213,X-7,Y-7,Z-7, 0, 0,0);
		Light[32][playerid] = CreateObject(1213,X,Y,Z-5, 0, 0,0);
		Light[33][playerid] = CreateObject(1213,X+7,Y+7,Z+5, 0, 0,0);
		Light[34][playerid] = CreateObject(1213,X+4,Y-7,Z-5, 0, 0,0);
		GetObjectPos(Light[7][playerid], X, Y, Z);
		Light[35][playerid] = CreateObject(1213,X-7,Y-7,Z-8, 0, 0,0);
		Light[36][playerid] = CreateObject(1213,X-7,Y,Z+5, 0, 0,0);
		Light[37][playerid] = CreateObject(1213,X,Y,Z-5, 0, 0,0);
		Light[38][playerid] = CreateObject(1213,X,Y-7,Z+8, 0, 0,0);
		GetObjectPos(Light[8][playerid], X, Y, Z);
		Light[39][playerid] = CreateObject(1213,X-4,Y-7,Z-8, 0, 0,0);
		Light[40][playerid] = CreateObject(1213,X+7,Y,Z+8, 0, 0,0);
		Light[41][playerid] = CreateObject(1213,X+4,Y,Z+5, 0, 0,0);
		Light[42][playerid] = CreateObject(1213,X,Y-7,Z-5, 0, 0,0);
		GetObjectPos(Light[1][playerid], X, Y, Z);
		MoveObject(Light[1][playerid], X-6, Y-6, Z-20, 4);
		GetObjectPos(Light[2][playerid], X, Y, Z);
		MoveObject(Light[2][playerid], X-6, Y+6, Z-20, 4);
		GetObjectPos(Light[3][playerid], X, Y, Z);
		MoveObject(Light[3][playerid], X-6, Y, Z-20, 4);
		GetObjectPos(Light[4][playerid], X, Y, Z);
		MoveObject(Light[4][playerid], X+6, Y-6, Z-20, 4);
		GetObjectPos(Light[5][playerid], X, Y, Z);
		MoveObject(Light[5][playerid], X+6, Y+6, Z-20, 4);
		GetObjectPos(Light[6][playerid], X, Y, Z);
		MoveObject(Light[6][playerid], X+6, Y, Z-20, 4);
		GetObjectPos(Light[7][playerid], X, Y, Z);
		MoveObject(Light[1][playerid], X, Y-6, Z-20, 4);
		GetObjectPos(Light[8][playerid], X, Y, Z);
		MoveObject(Light[8][playerid], X, Y+6, Z-20, 4);
		GetObjectPos(Light[11][playerid], X, Y, Z);
		MoveObject(Light[11][playerid], X-6, Y-6, Z-20, 4);
		GetObjectPos(Light[12][playerid], X, Y, Z);
		MoveObject(Light[12][playerid], X-6, Y-6, Z-20, 4);
		GetObjectPos(Light[13][playerid], X, Y, Z);
		MoveObject(Light[13][playerid], X-6, Y-6, Z-20, 4);
		GetObjectPos(Light[14][playerid], X, Y, Z);
		MoveObject(Light[14][playerid], X-6, Y-6, Z-20, 4);
		GetObjectPos(Light[15][playerid], X, Y, Z);
		MoveObject(Light[15][playerid], X-6, Y-6, Z-20, 4);
		GetObjectPos(Light[16][playerid], X, Y, Z);
		MoveObject(Light[16][playerid], X-6, Y-6, Z-20, 4);
		GetObjectPos(Light[17][playerid], X, Y, Z);
		MoveObject(Light[17][playerid], X-6, Y-6, Z-20, 4);
		GetObjectPos(Light[18][playerid], X, Y, Z);
		MoveObject(Light[18][playerid], X-6, Y-6, Z-20, 4);
		GetObjectPos(Light[19][playerid], X, Y, Z);
		MoveObject(Light[19][playerid], X-6, Y-6, Z-20, 4);
		GetObjectPos(Light[20][playerid], X, Y, Z);
		MoveObject(Light[20][playerid], X-6, Y-6, Z-20, 4);
		GetObjectPos(Light[21][playerid], X, Y, Z);
		MoveObject(Light[21][playerid], X-6, Y-6, Z-20, 4);
		GetObjectPos(Light[22][playerid], X, Y, Z);
		MoveObject(Light[22][playerid], X-6, Y-6, Z-20, 4);
		GetObjectPos(Light[23][playerid], X, Y, Z);
		MoveObject(Light[23][playerid], X-6, Y-6, Z-20, 4);
		GetObjectPos(Light[24][playerid], X, Y, Z);
		MoveObject(Light[24][playerid], X-6, Y-6, Z-20, 4);
		GetObjectPos(Light[25][playerid], X, Y, Z);
		MoveObject(Light[25][playerid], X-6, Y-6, Z-20, 4);
		GetObjectPos(Light[26][playerid], X, Y, Z);
		MoveObject(Light[26][playerid], X-6, Y-6, Z-20, 4);
		GetObjectPos(Light[27][playerid], X, Y, Z);
		MoveObject(Light[27][playerid], X-6, Y-6, Z-20, 4);
		GetObjectPos(Light[28][playerid], X, Y, Z);
		MoveObject(Light[28][playerid], X-6, Y-6, Z-20, 4);
		GetObjectPos(Light[29][playerid], X, Y, Z);
		MoveObject(Light[29][playerid], X-6, Y-6, Z-20, 4);
		GetObjectPos(Light[30][playerid], X, Y, Z);
		MoveObject(Light[30][playerid], X-6, Y-6, Z-20, 4);
		GetObjectPos(Light[31][playerid], X, Y, Z);
		MoveObject(Light[31][playerid], X-6, Y-6, Z-20, 4);
		GetObjectPos(Light[32][playerid], X, Y, Z);
		MoveObject(Light[32][playerid], X-6, Y-6, Z-20, 4);
		GetObjectPos(Light[33][playerid], X, Y, Z);
		MoveObject(Light[33][playerid], X-6, Y-6, Z-20, 4);
		GetObjectPos(Light[34][playerid], X, Y, Z);
		MoveObject(Light[34][playerid], X-6, Y-6, Z-20, 4);
		GetObjectPos(Light[35][playerid], X, Y, Z);
		MoveObject(Light[35][playerid], X-6, Y-6, Z-20, 4);
		GetObjectPos(Light[36][playerid], X, Y, Z);
		MoveObject(Light[36][playerid], X-6, Y-6, Z-20, 4);
		GetObjectPos(Light[37][playerid], X, Y, Z);
		MoveObject(Light[37][playerid], X-6, Y-6, Z-20, 4);
		GetObjectPos(Light[38][playerid], X, Y, Z);
		MoveObject(Light[38][playerid], X-6, Y-6, Z-20, 4);
		GetObjectPos(Light[39][playerid], X, Y, Z);
		MoveObject(Light[39][playerid], X-6, Y-6, Z-20, 4);
		GetObjectPos(Light[40][playerid], X, Y, Z);
		MoveObject(Light[40][playerid], X-6, Y-6, Z-20, 4);
		GetObjectPos(Light[41][playerid], X, Y, Z);
		MoveObject(Light[41][playerid], X-6, Y-6, Z-20, 4);
		GetObjectPos(Light[42][playerid], X, Y, Z);
		MoveObject(Light[42][playerid], X-6, Y-6, Z-20, 4);
		SetTimerEx("lighttimer2", 4000, 0, "i", playerid);
		DestroyObject(Firerocket[playerid]);
		DestroyObject(rocketsmoke[playerid]);
		return 1;
	}
	return 1;
}

public lighttimer(playerid)
{
	DestroyObject(Light[1][playerid]);
	DestroyObject(Light[2][playerid]);
	DestroyObject(Light[3][playerid]);
	DestroyObject(Light[4][playerid]);
	DestroyObject(Light[5][playerid]);
    DestroyObject(Light[6][playerid]);
    DestroyObject(Light[7][playerid]);
    DestroyObject(Light[8][playerid]);
    firerockettime[playerid] = 0;
	return 1;
}

public lighttimer2(playerid)
{
	DestroyObject(Light[1][playerid]);
	DestroyObject(Light[2][playerid]);
	DestroyObject(Light[3][playerid]);
	DestroyObject(Light[4][playerid]);
	DestroyObject(Light[5][playerid]);
    DestroyObject(Light[6][playerid]);
    DestroyObject(Light[7][playerid]);
    DestroyObject(Light[8][playerid]);
    DestroyObject(Light[11][playerid]);
	DestroyObject(Light[12][playerid]);
	DestroyObject(Light[13][playerid]);
	DestroyObject(Light[14][playerid]);
	DestroyObject(Light[15][playerid]);
    DestroyObject(Light[16][playerid]);
    DestroyObject(Light[17][playerid]);
    DestroyObject(Light[18][playerid]);
    DestroyObject(Light[19][playerid]);
	DestroyObject(Light[20][playerid]);
	DestroyObject(Light[21][playerid]);
	DestroyObject(Light[22][playerid]);
	DestroyObject(Light[23][playerid]);
    DestroyObject(Light[24][playerid]);
    DestroyObject(Light[25][playerid]);
    DestroyObject(Light[26][playerid]);
    DestroyObject(Light[27][playerid]);
	DestroyObject(Light[28][playerid]);
	DestroyObject(Light[29][playerid]);
	DestroyObject(Light[30][playerid]);
	DestroyObject(Light[31][playerid]);
    DestroyObject(Light[32][playerid]);
    DestroyObject(Light[33][playerid]);
    DestroyObject(Light[34][playerid]);
    DestroyObject(Light[35][playerid]);
	DestroyObject(Light[36][playerid]);
	DestroyObject(Light[37][playerid]);
	DestroyObject(Light[38][playerid]);
	DestroyObject(Light[39][playerid]);
    DestroyObject(Light[40][playerid]);
    DestroyObject(Light[41][playerid]);
    DestroyObject(Light[42][playerid]);
    firerockettime[playerid] = 0;
	return 1;
}

public OnFilterScriptInit()
{
	print("\n--------------------------------------");
	print("Notime's Firework");
	print("--------------------------------------\n");
	if(!fexist("FireWorkInfo"))
	{
		djCreateFile("FireWorkInfo");
		djSetInt("FireWorkInfo","FireCrackerAL", 0);
	    djSetInt("FireWorkInfo","FireRocket1AL", 0);
	    djSetInt("FireWorkInfo","FireRocket2AL", 0);
	    djSetInt("FireWorkInfo","CrackerrollAL", 0);
	    djSetInt("FireWorkInfo","Fountain1AL", 0);
	    djSetInt("FireWorkInfo","Fountain2AL", 0);
	    djSetInt("FireWorkInfo","Fountain3AL", 0);
	    djSetInt("FireWorkInfo","RocketBAL", 0);
	    djSetInt("FireWorkInfo","DrawDistance", 1);
	    print("[FWCP]: FireWorkInfo file created");
	}
	SetTimer("Load", 3000, 0);
	djson_GameModeInit();
	return 1;
}

forward Load();
public Load()
{
    LoadFireWorkInfo();
	return 1;
}

public OnFilterScriptExit()
{
    djson_GameModeExit();
	return 1;
}

main()
{
	print("\n--------------------------------------");
	print("Notime's Firework");
	print("--------------------------------------\n");
}

forward play(playerid);

public play(playerid)
{
	backgroundnoise[playerid] = Audio_PlayStreamed(playerid, "http://wpartyrp.pl/firework_background.mp3", false, false, false);
	Audio_SetVolume(playerid, backgroundnoise[playerid], 7);
	Audio_SetPosition(playerid, backgroundnoise[playerid], random(700));
}

public Audio_OnClientConnect(playerid)
{
	SetTimerEx("play", 10000, 0, "i", playerid);
}

public Audio_OnStop(playerid, handleid)
{
	if(backgroundnoise[playerid])
	{
		backgroundnoise[playerid] = Audio_PlayStreamed(playerid, "http://wpartyrp.pl/firework_background.mp3", false, false, false);
		Audio_SetVolume(playerid, backgroundnoise[playerid], 7);
		Audio_SetPosition(playerid, backgroundnoise[playerid], random(700));
	}
}

public OnGameModeInit()
{
	// Don't use these lines if it's a filterscript
	AddPlayerClass(0, 1958.3783, 1343.1572, 15.3746, 269.1425, 0, 0, 0, 0, 0, 0);
	return 1;
}

public OnGameModeExit()
{
	return 1;
}

public OnPlayerConnect(playerid)
{
	return 1;
}

public OnPlayerRequestClass(playerid, classid)
{
	SetPlayerPos(playerid, 1958.3783, 1343.1572, 15.3746);
	SetPlayerCameraPos(playerid, 1958.3783, 1343.1572, 15.3746);
	SetPlayerCameraLookAt(playerid, 1958.3783, 1343.1572, 15.3746);
	return 1;
}

public OnPlayerCommandText(playerid, cmdtext[])
{
    dcmd(fajerwerki,10,cmdtext);
    dcmd(fwcp,4,cmdtext);
	if (strcmp("/mycommand", cmdtext, true, 10) == 0)
	{
		// Do something here
		return 1;
	}
	return 0;
}

dcmd_fajerwerki(playerid, params[])
{
	new distance;
    if(AllowedFirework[DrawDistance] == 0) distance = 15;
    if(AllowedFirework[DrawDistance] == 1) distance = 22;
    if(AllowedFirework[DrawDistance] == 2) distance = 30;
    if(!strlen(params))
	{
		SendClientMessage(playerid, COLOR_TAN, "[INFO:] /fajerwerki [typ]");
		SendClientMessage(playerid, COLOR_TAN, "Typy: Firecracker, crackerroll, firerocket1, firerocket2, fountain1, fountain2, fountain3, rocketbox");
		return 1;
	}
	if(strcmp("firecracker", params, true, 8) == 0)
	{
	    if(AllowedFirework[FireCracker] == 1 && IsPlayerAdmin(playerid) || AllowedFirework[FireCracker] == 0)
	    {
		    if(firecrackertime[playerid] == 0)
		    {
		        new Float:X, Float:Y,Float:Z;
		        firecrackertime[playerid] = 1;
			    new string[128];
				new sendername[MAX_PLAYER_NAME];
				GetPlayerName(playerid, sendername, sizeof(sendername));
				format(string, sizeof(string), "<> %s throws away a firecracker.", sendername);
				ProxDetector(15.0, playerid, string, WHITE,WHITE,WHITE,WHITE,WHITE);
				GetPlayerPos(playerid,X,Y,Z);
				GetXYInFrontOfPlayer(playerid, X,Y, 8);
				Firecracker[playerid] = CreateObject(1672, X,Y,(Z-0.9), 0, 0, 0);
				SetTimerEx("FirecrackerTime", (2000+(random(3000))), 0, "i", playerid);
				return 1;
			}
			else return SendClientMessage(playerid, RED, "ERROR: You already threw a firecracker.");
		}
		else return SendClientMessage(playerid, RED, "ERROR: The Firecracker is enabled for rcon admins only");
	}
	if(strcmp("crackerroll", params, true, 11) == 0)
	{
	    if(AllowedFirework[Crackerroll] == 1 && IsPlayerAdmin(playerid) || AllowedFirework[Crackerroll] == 0)
	    {
		    if(firecrackerroll[playerid] == 0)
		    {
		        new Float:X, Float:Y,Float:Z;
		        firecrackerroll[playerid] = 1;
			    new string[128];
				new sendername[MAX_PLAYER_NAME];
				GetPlayerName(playerid, sendername, sizeof(sendername));
				format(string, sizeof(string), "<> %s Places down a firecracker roll", sendername);
				ProxDetector(15.0, playerid, string, WHITE,WHITE,WHITE,WHITE,WHITE);
				GetPlayerPos(playerid,X,Y,Z);
				GetXYInFrontOfPlayer(playerid, X,Y, 8);
				FireCrackerRoll[playerid] = CreateRoll(playerid,X,Y,(Z-1.00));
				RollStartX[playerid] = X;
				RollStartY[playerid] = Y;
				RollStartZ[playerid] = (Z-1.00);
				CrackerRollSmoke[playerid] = CreateObject(2780, X, Y, (Z-5.00), 0, 0, 0);
				SetTimerEx("CrackerRollTime", (2000+(random(3000))), 0, "i", playerid);
				return 1;
			}
			else return SendClientMessage(playerid, RED, "ERROR: You already placed a firecracker roll.");
		}
		else return SendClientMessage(playerid, RED, "ERROR: The CrackerRoll is enabled for rcon admins only");
	}
	if(strcmp("firerocket1", params, true, 11) == 0)
	{
	    if(AllowedFirework[Firerocket1] == 1 && IsPlayerAdmin(playerid) || AllowedFirework[Firerocket1] == 0)
	    {
		    if(firerockettime[playerid] == 0)
		    {
		        new Float:X, Float:Y,Float:Z;
		        firerockettime[playerid] = 1;
			    new string[128];
				new sendername[MAX_PLAYER_NAME];
				GetPlayerName(playerid, sendername, sizeof(sendername));
				format(string, sizeof(string), "<> %s lights up a fire rocket.", sendername);
				ProxDetector(15.0, playerid, string, WHITE,WHITE,WHITE,WHITE,WHITE);
				GetPlayerPos(playerid,X,Y,Z);
				GetXYInFrontOfPlayer(playerid, X,Y, distance);
				Firerocket[playerid] = CreateObject(354, X,Y,(Z), 0, 0, 0);
				rocketsmoke[playerid] = CreateObject(2780, X,Y,(Z), 0, 0, 0);
				MoveObject(Firerocket[playerid], X, Y, Z+30, 10);
				MoveObject(rocketsmoke[playerid], X, Y, Z+30, 10);
				SetTimerEx("FirerocketTime", 3000, 0, "i", playerid);
				return 1;
			}
			else return SendClientMessage(playerid, RED, "ERROR: You already lightd a firerocket.");
        }
		else return SendClientMessage(playerid, RED, "ERROR: The FireRocket 1 is enabled for rcon admins only");
	}
	if(strcmp("firerocket2", params, true, 11) == 0)
	{
	    if(AllowedFirework[Firerocket2] == 1 && IsPlayerAdmin(playerid) || AllowedFirework[Firerocket2] == 0)
	    {
			if(firerockettime[playerid] == 0)
			{
			    new Float:X, Float:Y,Float:Z;
			    firerockettime[playerid] = 2;
			    new string[128];
				new sendername[MAX_PLAYER_NAME];
				GetPlayerName(playerid, sendername, sizeof(sendername));
				format(string, sizeof(string), "<> %s lights up a fire rocket.", sendername);
				ProxDetector(15.0, playerid, string, WHITE,WHITE,WHITE,WHITE,WHITE);
				GetPlayerPos(playerid,X,Y,Z);
				GetXYInFrontOfPlayer(playerid, X,Y, distance);
				Firerocket[playerid] = CreateObject(354, X,Y,(Z), 0, 0, 0);
				rocketsmoke[playerid] = CreateObject(2780, X,Y,(Z), 0, 0, 0);
				MoveObject(Firerocket[playerid], X, Y, Z+50, 15);
				MoveObject(rocketsmoke[playerid], X, Y, Z+50, 15);
				SetTimerEx("FirerocketTime", 3000, 0, "i", playerid);
				return 1;
			}
			else return SendClientMessage(playerid, RED, "ERROR: You already Light a firerocket.");
		}
		else return SendClientMessage(playerid, RED, "ERROR: The FireRocket 2 is enabled for rcon admins only");
	}
	if(strcmp("fountain1", params, true, 9) == 0)
	{
	    if(AllowedFirework[Fountain1] == 1 && IsPlayerAdmin(playerid) || AllowedFirework[Fountain1] == 0)
	    {
			if(Fountain1Time[playerid] == 0 && Fountain2Time[playerid] == 0 && Fountain3Time[playerid] == 0)
			{
			    new Float:X, Float:Y,Float:Z;
			    Fountain1Time[playerid] = 1;
			    new string[128];
				new sendername[MAX_PLAYER_NAME];
				GetPlayerName(playerid, sendername, sizeof(sendername));
				format(string, sizeof(string), "<> %s places a Firework Fountain on the ground.", sendername);
				ProxDetector(15.0, playerid, string, WHITE,WHITE,WHITE,WHITE,WHITE);
				GetPlayerPos(playerid,X,Y,Z);
				GetXYInFrontOfPlayer(playerid, X,Y, 15);
				FTX[playerid] = X;
				FTY[playerid] = Y;
				FTZ[playerid] = (Z-1.0);
				Fountain[playerid] = CreateObject(354, X,Y,(Z-1.0), 0, 0, 0);
				FountainSmoke[playerid] = CreateObject(2780, X,Y,(Z-1.0), 0, 0, 0);
				SetTimerEx("FountainTimer", 3000, 0, "i", playerid);
				return 1;
			}
			else return SendClientMessage(playerid, RED, "ERROR: You already Light a Firework Fountain.");
		}
		else return SendClientMessage(playerid, RED, "ERROR: The Fountain 1 is enabled for rcon admins only");
	}
	if(strcmp("fountain2", params, true, 9) == 0)
	{
	    if(AllowedFirework[Fountain2] == 1 && IsPlayerAdmin(playerid) || AllowedFirework[Fountain2] == 0)
	    {
			if(Fountain1Time[playerid] == 0 && Fountain2Time[playerid] == 0 && Fountain3Time[playerid] == 0)
			{
			    new Float:X, Float:Y,Float:Z;
			    Fountain2Time[playerid] = 1;
			    new string[128];
				new sendername[MAX_PLAYER_NAME];
				GetPlayerName(playerid, sendername, sizeof(sendername));
				format(string, sizeof(string), "<> %s places a Firework Fountain on the ground.", sendername);
				ProxDetector(15.0, playerid, string, WHITE,WHITE,WHITE,WHITE,WHITE);
				GetPlayerPos(playerid,X,Y,Z);
				GetXYInFrontOfPlayer(playerid, X,Y, 15);
				FTX[playerid] = X;
				FTY[playerid] = Y;
				FTZ[playerid] = (Z-1.0);
				Fountain[playerid] = CreateObject(354, X,Y,(Z-1.0), 0, 0, 0);
				FountainSmoke[playerid] = CreateObject(2780, X,Y,(Z-1.0), 0, 0, 0);
				SetTimerEx("FountainTimer", 3000, 0, "i", playerid);
				return 1;
			}
			else return SendClientMessage(playerid, RED, "ERROR: You already Light a Firework Fountain.");
		}
		else return SendClientMessage(playerid, RED, "ERROR: The Fountain 2 is enabled for rcon admins only");
	}
	if(strcmp("fountain3", params, true, 9) == 0)
	{
	    if(AllowedFirework[Fountain3] == 1 && IsPlayerAdmin(playerid) || AllowedFirework[Fountain3] == 0)
	    {
			if(Fountain1Time[playerid] == 0 && Fountain2Time[playerid] == 0 && Fountain3Time[playerid] == 0)
			{
			    new Float:X, Float:Y,Float:Z;
			    Fountain3Time[playerid] = 1;
			    new string[128];
				new sendername[MAX_PLAYER_NAME];
				GetPlayerName(playerid, sendername, sizeof(sendername));
				format(string, sizeof(string), "<> %s places a Firework Fountain on the ground.", sendername);
				ProxDetector(15.0, playerid, string, WHITE,WHITE,WHITE,WHITE,WHITE);
				GetPlayerPos(playerid,X,Y,Z);
				GetXYInFrontOfPlayer(playerid, X,Y, 15);
				FTX[playerid] = X;
				FTY[playerid] = Y;
				FTZ[playerid] = (Z-1.0);
				Fountain[playerid] = CreateObject(354, X,Y,(Z-1.0), 0, 0, 0);
				FountainSmoke[playerid] = CreateObject(2780, X,Y,(Z-1.0), 0, 0, 0);
				SetTimerEx("FountainTimer", 3000, 0, "i", playerid);
				return 1;
			}
			else return SendClientMessage(playerid, RED, "ERROR: You already Light a Firework Fountain.");
		}
		else return SendClientMessage(playerid, RED, "ERROR: The Fountain 3 is enabled for rcon admins only");
	}
	if(strcmp("rocketbox1", params, true, 10) == 0)
	{
	    if(AllowedFirework[RocketB] == 1 && IsPlayerAdmin(playerid) || AllowedFirework[RocketB] == 0)
	    {
			if(RocketBoxTime[playerid] == 0)
			{
			    new Float:X, Float:Y,Float:Z;
			    RocketBoxTime[playerid] = 1;
			    new string[128];
				new sendername[MAX_PLAYER_NAME];
				GetPlayerName(playerid, sendername, sizeof(sendername));
				format(string, sizeof(string), "<> %s places a Rocketbox on the ground.", sendername);
				ProxDetector(15.0, playerid, string, WHITE,WHITE,WHITE,WHITE,WHITE);
				GetPlayerPos(playerid,X,Y,Z);
				GetXYInFrontOfPlayer(playerid, X,Y, distance);
				RBX[playerid] = X;
				RBY[playerid] = Y;
				RBZ[playerid] = (Z-1.0);
				RocketBox[playerid] = CreateObject(354, X,Y,(Z-1.0), 0, 0, 0);
				RocketBoxSmoke[playerid] = CreateObject(2780, X,Y,(Z-1.0), 0, 0, 0);
				SetTimerEx("RocketBoxTimer", 4500, 0, "i", playerid);
				return 1;
			}
			else return SendClientMessage(playerid, RED, "ERROR: You already Light a Firework RocketBox.");
		}
		else return SendClientMessage(playerid, RED, "ERROR: The RocketBox is enabled for rcon admins only");
	}
	if(strcmp("rocketbox2", params, true, 10) == 0)
	{
	    if(AllowedFirework[RocketB] == 1 && IsPlayerAdmin(playerid) || AllowedFirework[RocketB] == 0)
	    {
			new Float:X, Float:Y,Float:Z;
			new string[128];
			new sendername[MAX_PLAYER_NAME];
			for(new i = 0; i < 5; i++)
			{
				if(RocketBoxTime[i] == 0)
				{					
					RocketBoxTime[i] = 1;					
					// GetPlayerName(i, sendername, sizeof(sendername));
					// format(string, sizeof(string), "<> %s places a Rocketbox on the ground.", sendername);
					// ProxDetector(15.0, i, string, WHITE,WHITE,WHITE,WHITE,WHITE);
					GetPlayerPos(playerid,X,Y,Z);
					RBX[i] = X+random(100);
					RBY[i] = Y+random(100);
					RBZ[i] = (Z-1.0);
					RocketBox[i] = CreateObject(354, RBX[i],RBY[i],(Z-1.0), 0, 0, 0);
					RocketBoxSmoke[i] = CreateObject(2780, RBX[i],RBY[i],(Z-1.0), 0, 0, 0);
					SetTimerEx("RocketBoxTimer", 1000+(random(10000)), 0, "i", i);
				}
			}
			return 1;
		}
		else return SendClientMessage(playerid, RED, "ERROR: The RocketBox is enabled for rcon admins only");
	}
	else return SendClientMessage(playerid, COLOR_TAN, "Right Usage: /lightfirework [type]");
}

dcmd_fwcp(playerid, params[])
{
	#pragma unused params
	if(IsPlayerAdmin(playerid))
	{
	    new string[512];
	    format(string, sizeof(string), "DrawDistance: %s\nFire Cracker: %s\nFirerocket1: %s\nFirerocket2: %s\nCrackerRoll: %s\nFountain1: %s\nFountain2: %s\nFountain3: %s\nRocketBox: %s",
		DrawDistanceWord[AllowedFirework[DrawDistance]], UsageFW[AllowedFirework[FireCracker]], UsageFW[AllowedFirework[Firerocket1]], UsageFW[AllowedFirework[Firerocket2]], UsageFW[AllowedFirework[Crackerroll]], UsageFW[AllowedFirework[Fountain1]], UsageFW[AllowedFirework[Fountain2]], UsageFW[AllowedFirework[Fountain3]], UsageFW[AllowedFirework[RocketB]]);
        ShowPlayerDialog(playerid, FWCPM,2,"FireWork Control Panel", string,"Select", "Close");
        return 1;
	}
	else return SendClientMessage(playerid, RED, "[Notime Bot]: U are not allowed to use this command");
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	if(dialogid == FWCPM)
	{
 		if(response == 0) return SendClientMessage(playerid, WHITE, "[NotimeBot]: You closed the Fire Work Control Panel");
	    if(response == 1)
	    {
		    switch (listitem)
	     	{
	      		case 0: //DrawDistance
	      		{
	      		    ShowPlayerDialog(playerid, FWCPDD, DIALOG_STYLE_LIST, "FireWork Control Panel > -Draw Distance Setting-", "Low\nMedium\nHigh", "Select", "Back");
	      		    return 1;
	      		}
	      		case 1://Firecracker
				{
				    ShowPlayerDialog(playerid, FWCPFC, DIALOG_STYLE_LIST, "FireWork Control Panel > -FireCracker Usable for:-", "Usable for all players\nUsable for Rcon Admins only", "Select", "Back");
				    return 1;
				}
				case 2://Firerocket1
				{
    				ShowPlayerDialog(playerid, FWCPFR1, DIALOG_STYLE_LIST, "FireWork Control Panel > -FireRocket1 Usable for:-", "Usable for all players\nUsable for Rcon Admins only", "Select", "Back");
				    return 1;
				}
    			case 3://Firerocket2
				{
				    ShowPlayerDialog(playerid, FWCPFR2, DIALOG_STYLE_LIST, "FireWork Control Panel > -FireRocket2 Usable for:-", "Usable for all players\nUsable for Rcon Admins only", "Select", "Back");
				    return 1;
				}
				case 4://Crackerroll
				{
				    ShowPlayerDialog(playerid, FWCPCR, DIALOG_STYLE_LIST, "FireWork Control Panel > -CrackerRoll Usable for:-", "Usable for all players\nUsable for Rcon Admins only", "Select", "Back");
				    return 1;
				}
				case 5://Fountain1
				{
        			ShowPlayerDialog(playerid, FWCPFT1, DIALOG_STYLE_LIST, "FireWork Control Panel > -Fountain1 Usable for:-", "Usable for all players\nUsable for Rcon Admins only", "Select", "Back");
				    return 1;
				}
				case 6://Fountain2
				{
				    ShowPlayerDialog(playerid, FWCPFT2, DIALOG_STYLE_LIST, "FireWork Control Panel > -Fountain2 Usable for:-", "Usable for all players\nUsable for Rcon Admins only", "Select", "Back");
				    return 1;
				}
				case 7://Fountain3
				{
				    ShowPlayerDialog(playerid, FWCPFT3, DIALOG_STYLE_LIST, "FireWork Control Panel > -Fountain3 Usable for:-", "Usable for all players\nUsable for Rcon Admins only", "Select", "Back");
				    return 1;
				}
				case 8://RocketBox
				{
				    ShowPlayerDialog(playerid, FWCPRB, DIALOG_STYLE_LIST, "FireWork Control Panel > -RocketBox Usable for:-", "Usable for all players\nUsable for Rcon Admins only", "Select", "Back");
				    return 1;
				}
			}
			return 1;
		}
		return 1;
	}
	if(dialogid == FWCPDD)
	{
 		if(response == 0)
 		{
 		    new string[512];
		    format(string, sizeof(string), "DrawDistance: %s\nFire Cracker: %s\nFirerocket1: %s\nFirerocket2: %s\nCrackerRoll: %s\nFountain1: %s\nFountain2: %s\nFountain3: %s\nRocketBox: %s",
			DrawDistanceWord[AllowedFirework[DrawDistance]], UsageFW[AllowedFirework[FireCracker]], UsageFW[AllowedFirework[Firerocket1]], UsageFW[AllowedFirework[Firerocket2]], UsageFW[AllowedFirework[Crackerroll]], UsageFW[AllowedFirework[Fountain1]], UsageFW[AllowedFirework[Fountain2]], UsageFW[AllowedFirework[Fountain3]], UsageFW[AllowedFirework[RocketB]]);
	        ShowPlayerDialog(playerid, FWCPM,2,"FireWork Control Panel", string,"Select", "Close");
	        return 1;
 		}
	    if(response == 1)
	    {
		    switch (listitem)
	     	{
	      		case 0: //Low DrawDistance
	      		{
	      		    SendClientMessage(playerid, WHITE, "[FWCP]: Draw distance set to low.");
	      		    new string[512];
	      		    AllowedFirework[DrawDistance] = 0;
				    format(string, sizeof(string), "DrawDistance: %s\nFire Cracker: %s\nFirerocket1: %s\nFirerocket2: %s\nCrackerRoll: %s\nFountain1: %s\nFountain2: %s\nFountain3: %s\nRocketBox: %s",
					DrawDistanceWord[AllowedFirework[DrawDistance]], UsageFW[AllowedFirework[FireCracker]], UsageFW[AllowedFirework[Firerocket1]], UsageFW[AllowedFirework[Firerocket2]], UsageFW[AllowedFirework[Crackerroll]], UsageFW[AllowedFirework[Fountain1]], UsageFW[AllowedFirework[Fountain2]], UsageFW[AllowedFirework[Fountain3]], UsageFW[AllowedFirework[RocketB]]);
			        ShowPlayerDialog(playerid, FWCPM,2,"FireWork Control Panel", string,"Select", "Close");
                    SaveFireWorkInfo();
					return 1;
	      		}
	      		case 1://Medium DrawDistance
				{
				    SendClientMessage(playerid, WHITE, "[FWCP]: Draw distance set to medium.");
	      		    new string[512];
	      		    AllowedFirework[DrawDistance] = 1;
				    format(string, sizeof(string), "DrawDistance: %s\nFire Cracker: %s\nFirerocket1: %s\nFirerocket2: %s\nCrackerRoll: %s\nFountain1: %s\nFountain2: %s\nFountain3: %s\nRocketBox: %s",
					DrawDistanceWord[AllowedFirework[DrawDistance]], UsageFW[AllowedFirework[FireCracker]], UsageFW[AllowedFirework[Firerocket1]], UsageFW[AllowedFirework[Firerocket2]], UsageFW[AllowedFirework[Crackerroll]], UsageFW[AllowedFirework[Fountain1]], UsageFW[AllowedFirework[Fountain2]], UsageFW[AllowedFirework[Fountain3]], UsageFW[AllowedFirework[RocketB]]);
			        ShowPlayerDialog(playerid, FWCPM,2,"FireWork Control Panel", string,"Select", "Close");
                    SaveFireWorkInfo();
					return 1;
				}
				case 2://High DrawDistance
				{
    				SendClientMessage(playerid, WHITE, "[FWCP]: Draw distance set to High.");
	      		    new string[512];
	      		    AllowedFirework[DrawDistance] = 2;
				    format(string, sizeof(string), "DrawDistance: %s\nFire Cracker: %s\nFirerocket1: %s\nFirerocket2: %s\nCrackerRoll: %s\nFountain1: %s\nFountain2: %s\nFountain3: %s\nRocketBox: %s",
					DrawDistanceWord[AllowedFirework[DrawDistance]], UsageFW[AllowedFirework[FireCracker]], UsageFW[AllowedFirework[Firerocket1]], UsageFW[AllowedFirework[Firerocket2]], UsageFW[AllowedFirework[Crackerroll]], UsageFW[AllowedFirework[Fountain1]], UsageFW[AllowedFirework[Fountain2]], UsageFW[AllowedFirework[Fountain3]], UsageFW[AllowedFirework[RocketB]]);
			        ShowPlayerDialog(playerid, FWCPM,2,"FireWork Control Panel", string,"Select", "Close");
                    SaveFireWorkInfo();
					return 1;
				}
			}
			return 1;
		}
		return 1;
	}
	if(dialogid == FWCPFC)
	{
 		if(response == 0)
 		{
 		    new string[512];
		    format(string, sizeof(string), "DrawDistance: %s\nFire Cracker: %s\nFirerocket1: %s\nFirerocket2: %s\nCrackerRoll: %s\nFountain1: %s\nFountain2: %s\nFountain3: %s\nRocketBox: %s",
			DrawDistanceWord[AllowedFirework[DrawDistance]], UsageFW[AllowedFirework[FireCracker]], UsageFW[AllowedFirework[Firerocket1]], UsageFW[AllowedFirework[Firerocket2]], UsageFW[AllowedFirework[Crackerroll]], UsageFW[AllowedFirework[Fountain1]], UsageFW[AllowedFirework[Fountain2]], UsageFW[AllowedFirework[Fountain3]], UsageFW[AllowedFirework[RocketB]]);
	        ShowPlayerDialog(playerid, FWCPM,2,"FireWork Control Panel", string,"Select", "Close");
	        return 1;
 		}
	    if(response == 1)
	    {
		    switch (listitem)
	     	{
	      		case 0: //FireCracker usable for all
	      		{
	      		    SendClientMessage(playerid, WHITE, "[FWCP]: The Firecracker is now enabled for all players.");
	      		    new string[512];
	      		    AllowedFirework[FireCracker] = 0;
				    format(string, sizeof(string), "DrawDistance: %s\nFire Cracker: %s\nFirerocket1: %s\nFirerocket2: %s\nCrackerRoll: %s\nFountain1: %s\nFountain2: %s\nFountain3: %s\nRocketBox: %s",
					DrawDistanceWord[AllowedFirework[DrawDistance]], UsageFW[AllowedFirework[FireCracker]], UsageFW[AllowedFirework[Firerocket1]], UsageFW[AllowedFirework[Firerocket2]], UsageFW[AllowedFirework[Crackerroll]], UsageFW[AllowedFirework[Fountain1]], UsageFW[AllowedFirework[Fountain2]], UsageFW[AllowedFirework[Fountain3]], UsageFW[AllowedFirework[RocketB]]);
			        ShowPlayerDialog(playerid, FWCPM,2,"FireWork Control Panel", string,"Select", "Close");
                    SaveFireWorkInfo();
					return 1;
	      		}
	      		case 1://FireCracker usable for rcon only
				{
				    SendClientMessage(playerid, WHITE, "[FWCP]: The Firecracker is now enabled for Rcon Admins only.");
	      		    new string[512];
	      		    AllowedFirework[FireCracker] = 1;
				    format(string, sizeof(string), "DrawDistance: %s\nFire Cracker: %s\nFirerocket1: %s\nFirerocket2: %s\nCrackerRoll: %s\nFountain1: %s\nFountain2: %s\nFountain3: %s\nRocketBox: %s",
					DrawDistanceWord[AllowedFirework[DrawDistance]], UsageFW[AllowedFirework[FireCracker]], UsageFW[AllowedFirework[Firerocket1]], UsageFW[AllowedFirework[Firerocket2]], UsageFW[AllowedFirework[Crackerroll]], UsageFW[AllowedFirework[Fountain1]], UsageFW[AllowedFirework[Fountain2]], UsageFW[AllowedFirework[Fountain3]], UsageFW[AllowedFirework[RocketB]]);
			        ShowPlayerDialog(playerid, FWCPM,2,"FireWork Control Panel", string,"Select", "Close");
                    SaveFireWorkInfo();
					return 1;
				}
			}
			return 1;
		}
		return 1;
	}
	if(dialogid == FWCPFR1)
	{
 		if(response == 0)
 		{
 		    new string[512];
		    format(string, sizeof(string), "DrawDistance: %s\nFire Cracker: %s\nFirerocket1: %s\nFirerocket2: %s\nCrackerRoll: %s\nFountain1: %s\nFountain2: %s\nFountain3: %s\nRocketBox: %s",
			DrawDistanceWord[AllowedFirework[DrawDistance]], UsageFW[AllowedFirework[FireCracker]], UsageFW[AllowedFirework[Firerocket1]], UsageFW[AllowedFirework[Firerocket2]], UsageFW[AllowedFirework[Crackerroll]], UsageFW[AllowedFirework[Fountain1]], UsageFW[AllowedFirework[Fountain2]], UsageFW[AllowedFirework[Fountain3]], UsageFW[AllowedFirework[RocketB]]);
	        ShowPlayerDialog(playerid, FWCPM,2,"FireWork Control Panel", string,"Select", "Close");
	        return 1;
 		}
	    if(response == 1)
	    {
		    switch (listitem)
	     	{
	      		case 0: //FireRocket1 usable for all
	      		{
	      		    SendClientMessage(playerid, WHITE, "[FWCP]: The FireRocket 1 is now enabled for all players.");
	      		    new string[512];
	      		    AllowedFirework[Firerocket1] = 0;
				    format(string, sizeof(string), "DrawDistance: %s\nFire Cracker: %s\nFirerocket1: %s\nFirerocket2: %s\nCrackerRoll: %s\nFountain1: %s\nFountain2: %s\nFountain3: %s\nRocketBox: %s",
					DrawDistanceWord[AllowedFirework[DrawDistance]], UsageFW[AllowedFirework[FireCracker]], UsageFW[AllowedFirework[Firerocket1]], UsageFW[AllowedFirework[Firerocket2]], UsageFW[AllowedFirework[Crackerroll]], UsageFW[AllowedFirework[Fountain1]], UsageFW[AllowedFirework[Fountain2]], UsageFW[AllowedFirework[Fountain3]], UsageFW[AllowedFirework[RocketB]]);
			        ShowPlayerDialog(playerid, FWCPM,2,"FireWork Control Panel", string,"Select", "Close");
                    SaveFireWorkInfo();
					return 1;
	      		}
	      		case 1://FireRocket1 usable for rcon only
				{
				    SendClientMessage(playerid, WHITE, "[FWCP]: The FireRocket 1 is now enabled for Rcon Admins only.");
	      		    new string[512];
	      		    AllowedFirework[Firerocket1] = 1;
				    format(string, sizeof(string), "DrawDistance: %s\nFire Cracker: %s\nFirerocket1: %s\nFirerocket2: %s\nCrackerRoll: %s\nFountain1: %s\nFountain2: %s\nFountain3: %s\nRocketBox: %s",
					DrawDistanceWord[AllowedFirework[DrawDistance]], UsageFW[AllowedFirework[FireCracker]], UsageFW[AllowedFirework[Firerocket1]], UsageFW[AllowedFirework[Firerocket2]], UsageFW[AllowedFirework[Crackerroll]], UsageFW[AllowedFirework[Fountain1]], UsageFW[AllowedFirework[Fountain2]], UsageFW[AllowedFirework[Fountain3]], UsageFW[AllowedFirework[RocketB]]);
			        ShowPlayerDialog(playerid, FWCPM,2,"FireWork Control Panel", string,"Select", "Close");
                    SaveFireWorkInfo();
					return 1;
				}
			}
			return 1;
		}
		return 1;
	}
	if(dialogid == FWCPFR2)
	{
 		if(response == 0)
 		{
 		    new string[512];
		    format(string, sizeof(string), "DrawDistance: %s\nFire Cracker: %s\nFirerocket1: %s\nFirerocket2: %s\nCrackerRoll: %s\nFountain1: %s\nFountain2: %s\nFountain3: %s\nRocketBox: %s",
			DrawDistanceWord[AllowedFirework[DrawDistance]], UsageFW[AllowedFirework[FireCracker]], UsageFW[AllowedFirework[Firerocket1]], UsageFW[AllowedFirework[Firerocket2]], UsageFW[AllowedFirework[Crackerroll]], UsageFW[AllowedFirework[Fountain1]], UsageFW[AllowedFirework[Fountain2]], UsageFW[AllowedFirework[Fountain3]], UsageFW[AllowedFirework[RocketB]]);
	        ShowPlayerDialog(playerid, FWCPM,2,"FireWork Control Panel", string,"Select", "Close");
	        return 1;
 		}
	    if(response == 1)
	    {
		    switch (listitem)
	     	{
	      		case 0: //FireRocket2 usable for all
	      		{
	      		    SendClientMessage(playerid, WHITE, "[FWCP]: The FireRocket 2 is now enabled for all players.");
	      		    new string[512];
	      		    AllowedFirework[Firerocket2] = 0;
				    format(string, sizeof(string), "DrawDistance: %s\nFire Cracker: %s\nFirerocket1: %s\nFirerocket2: %s\nCrackerRoll: %s\nFountain1: %s\nFountain2: %s\nFountain3: %s\nRocketBox: %s",
					DrawDistanceWord[AllowedFirework[DrawDistance]], UsageFW[AllowedFirework[FireCracker]], UsageFW[AllowedFirework[Firerocket1]], UsageFW[AllowedFirework[Firerocket2]], UsageFW[AllowedFirework[Crackerroll]], UsageFW[AllowedFirework[Fountain1]], UsageFW[AllowedFirework[Fountain2]], UsageFW[AllowedFirework[Fountain3]], UsageFW[AllowedFirework[RocketB]]);
			        ShowPlayerDialog(playerid, FWCPM,2,"FireWork Control Panel", string,"Select", "Close");
                    SaveFireWorkInfo();
					return 1;
	      		}
	      		case 1://FireRocket2 usable for rcon only
				{
				    SendClientMessage(playerid, WHITE, "[FWCP]: The FireRocket 2 is now enabled for Rcon Admins only.");
	      		    new string[512];
	      		    AllowedFirework[Firerocket2] = 1;
				    format(string, sizeof(string), "DrawDistance: %s\nFire Cracker: %s\nFirerocket1: %s\nFirerocket2: %s\nCrackerRoll: %s\nFountain1: %s\nFountain2: %s\nFountain3: %s\nRocketBox: %s",
					DrawDistanceWord[AllowedFirework[DrawDistance]], UsageFW[AllowedFirework[FireCracker]], UsageFW[AllowedFirework[Firerocket1]], UsageFW[AllowedFirework[Firerocket2]], UsageFW[AllowedFirework[Crackerroll]], UsageFW[AllowedFirework[Fountain1]], UsageFW[AllowedFirework[Fountain2]], UsageFW[AllowedFirework[Fountain3]], UsageFW[AllowedFirework[RocketB]]);
			        ShowPlayerDialog(playerid, FWCPM,2,"FireWork Control Panel", string,"Select", "Close");
                    SaveFireWorkInfo();
					return 1;
				}
			}
			return 1;
		}
		return 1;
	}
	if(dialogid == FWCPCR)
	{
 		if(response == 0)
 		{
 		    new string[512];
		    format(string, sizeof(string), "DrawDistance: %s\nFire Cracker: %s\nFirerocket1: %s\nFirerocket2: %s\nCrackerRoll: %s\nFountain1: %s\nFountain2: %s\nFountain3: %s\nRocketBox: %s",
			DrawDistanceWord[AllowedFirework[DrawDistance]], UsageFW[AllowedFirework[FireCracker]], UsageFW[AllowedFirework[Firerocket1]], UsageFW[AllowedFirework[Firerocket2]], UsageFW[AllowedFirework[Crackerroll]], UsageFW[AllowedFirework[Fountain1]], UsageFW[AllowedFirework[Fountain2]], UsageFW[AllowedFirework[Fountain3]], UsageFW[AllowedFirework[RocketB]]);
	        ShowPlayerDialog(playerid, FWCPM,2,"FireWork Control Panel", string,"Select", "Close");
	        return 1;
 		}
	    if(response == 1)
	    {
		    switch (listitem)
	     	{
	      		case 0: //CrackerRoll usable for all
	      		{
	      		    SendClientMessage(playerid, WHITE, "[FWCP]: The CrackerRoll is now enabled for all players.");
	      		    new string[512];
	      		    AllowedFirework[Crackerroll] = 0;
				    format(string, sizeof(string), "DrawDistance: %s\nFire Cracker: %s\nFirerocket1: %s\nFirerocket2: %s\nCrackerRoll: %s\nFountain1: %s\nFountain2: %s\nFountain3: %s\nRocketBox: %s",
					DrawDistanceWord[AllowedFirework[DrawDistance]], UsageFW[AllowedFirework[FireCracker]], UsageFW[AllowedFirework[Firerocket1]], UsageFW[AllowedFirework[Firerocket2]], UsageFW[AllowedFirework[Crackerroll]], UsageFW[AllowedFirework[Fountain1]], UsageFW[AllowedFirework[Fountain2]], UsageFW[AllowedFirework[Fountain3]], UsageFW[AllowedFirework[RocketB]]);
			        ShowPlayerDialog(playerid, FWCPM,2,"FireWork Control Panel", string,"Select", "Close");
                    SaveFireWorkInfo();
					return 1;
	      		}
	      		case 1://CrackerRoll usable for rcon only
				{
				    SendClientMessage(playerid, WHITE, "[FWCP]: The CrackerRoll is now enabled for Rcon Admins only.");
	      		    new string[512];
	      		    AllowedFirework[Crackerroll] = 1;
				    format(string, sizeof(string), "DrawDistance: %s\nFire Cracker: %s\nFirerocket1: %s\nFirerocket2: %s\nCrackerRoll: %s\nFountain1: %s\nFountain2: %s\nFountain3: %s\nRocketBox: %s",
					DrawDistanceWord[AllowedFirework[DrawDistance]], UsageFW[AllowedFirework[FireCracker]], UsageFW[AllowedFirework[Firerocket1]], UsageFW[AllowedFirework[Firerocket2]], UsageFW[AllowedFirework[Crackerroll]], UsageFW[AllowedFirework[Fountain1]], UsageFW[AllowedFirework[Fountain2]], UsageFW[AllowedFirework[Fountain3]], UsageFW[AllowedFirework[RocketB]]);
			        ShowPlayerDialog(playerid, FWCPM,2,"FireWork Control Panel", string,"Select", "Close");
                    SaveFireWorkInfo();
					return 1;
				}
			}
			return 1;
		}
		return 1;
	}
	if(dialogid == FWCPFT1)
	{
 		if(response == 0)
 		{
 		    new string[512];
		    format(string, sizeof(string), "DrawDistance: %s\nFire Cracker: %s\nFirerocket1: %s\nFirerocket2: %s\nCrackerRoll: %s\nFountain1: %s\nFountain2: %s\nFountain3: %s\nRocketBox: %s",
			DrawDistanceWord[AllowedFirework[DrawDistance]], UsageFW[AllowedFirework[FireCracker]], UsageFW[AllowedFirework[Firerocket1]], UsageFW[AllowedFirework[Firerocket2]], UsageFW[AllowedFirework[Crackerroll]], UsageFW[AllowedFirework[Fountain1]], UsageFW[AllowedFirework[Fountain2]], UsageFW[AllowedFirework[Fountain3]], UsageFW[AllowedFirework[RocketB]]);
	        ShowPlayerDialog(playerid, FWCPM,2,"FireWork Control Panel", string,"Select", "Close");
	        return 1;
 		}
	    if(response == 1)
	    {
		    switch (listitem)
	     	{
	      		case 0: //Fountain1 usable for all
	      		{
	      		    SendClientMessage(playerid, WHITE, "[FWCP]: The Fountain 1 is now enabled for all players.");
	      		    new string[512];
	      		    AllowedFirework[Fountain1] = 0;
				    format(string, sizeof(string), "DrawDistance: %s\nFire Cracker: %s\nFirerocket1: %s\nFirerocket2: %s\nCrackerRoll: %s\nFountain1: %s\nFountain2: %s\nFountain3: %s\nRocketBox: %s",
					DrawDistanceWord[AllowedFirework[DrawDistance]], UsageFW[AllowedFirework[FireCracker]], UsageFW[AllowedFirework[Firerocket1]], UsageFW[AllowedFirework[Firerocket2]], UsageFW[AllowedFirework[Crackerroll]], UsageFW[AllowedFirework[Fountain1]], UsageFW[AllowedFirework[Fountain2]], UsageFW[AllowedFirework[Fountain3]], UsageFW[AllowedFirework[RocketB]]);
			        ShowPlayerDialog(playerid, FWCPM,2,"FireWork Control Panel", string,"Select", "Close");
                    SaveFireWorkInfo();
					return 1;
	      		}
	      		case 1://Fountain1 usable for rcon only
				{
				    SendClientMessage(playerid, WHITE, "[FWCP]: The Fountain 1 is now enabled for Rcon Admins only.");
	      		    new string[512];
	      		    AllowedFirework[Fountain1] = 1;
				    format(string, sizeof(string), "DrawDistance: %s\nFire Cracker: %s\nFirerocket1: %s\nFirerocket2: %s\nCrackerRoll: %s\nFountain1: %s\nFountain2: %s\nFountain3: %s\nRocketBox: %s",
					DrawDistanceWord[AllowedFirework[DrawDistance]], UsageFW[AllowedFirework[FireCracker]], UsageFW[AllowedFirework[Firerocket1]], UsageFW[AllowedFirework[Firerocket2]], UsageFW[AllowedFirework[Crackerroll]], UsageFW[AllowedFirework[Fountain1]], UsageFW[AllowedFirework[Fountain2]], UsageFW[AllowedFirework[Fountain3]], UsageFW[AllowedFirework[RocketB]]);
			        ShowPlayerDialog(playerid, FWCPM,2,"FireWork Control Panel", string,"Select", "Close");
                    SaveFireWorkInfo();
					return 1;
				}
			}
			return 1;
		}
		return 1;
	}
	if(dialogid == FWCPFT2)
	{
 		if(response == 0)
 		{
 		    new string[512];
		    format(string, sizeof(string), "DrawDistance: %s\nFire Cracker: %s\nFirerocket1: %s\nFirerocket2: %s\nCrackerRoll: %s\nFountain1: %s\nFountain2: %s\nFountain3: %s\nRocketBox: %s",
			DrawDistanceWord[AllowedFirework[DrawDistance]], UsageFW[AllowedFirework[FireCracker]], UsageFW[AllowedFirework[Firerocket1]], UsageFW[AllowedFirework[Firerocket2]], UsageFW[AllowedFirework[Crackerroll]], UsageFW[AllowedFirework[Fountain1]], UsageFW[AllowedFirework[Fountain2]], UsageFW[AllowedFirework[Fountain3]], UsageFW[AllowedFirework[RocketB]]);
	        ShowPlayerDialog(playerid, FWCPM,2,"FireWork Control Panel", string,"Select", "Close");
	        return 1;
 		}
	    if(response == 1)
	    {
		    switch (listitem)
	     	{
	      		case 0: //Fountain2 usable for all
	      		{
	      		    SendClientMessage(playerid, WHITE, "[FWCP]: The Fountain 2 is now enabled for all players.");
	      		    new string[512];
	      		    AllowedFirework[Fountain2] = 0;
				    format(string, sizeof(string), "DrawDistance: %s\nFire Cracker: %s\nFirerocket1: %s\nFirerocket2: %s\nCrackerRoll: %s\nFountain1: %s\nFountain2: %s\nFountain3: %s\nRocketBox: %s",
					DrawDistanceWord[AllowedFirework[DrawDistance]], UsageFW[AllowedFirework[FireCracker]], UsageFW[AllowedFirework[Firerocket1]], UsageFW[AllowedFirework[Firerocket2]], UsageFW[AllowedFirework[Crackerroll]], UsageFW[AllowedFirework[Fountain1]], UsageFW[AllowedFirework[Fountain2]], UsageFW[AllowedFirework[Fountain3]], UsageFW[AllowedFirework[RocketB]]);
			        ShowPlayerDialog(playerid, FWCPM,2,"FireWork Control Panel", string,"Select", "Close");
                    SaveFireWorkInfo();
					return 1;
	      		}
	      		case 1://Fountain2 usable for rcon only
				{
				    SendClientMessage(playerid, WHITE, "[FWCP]: The Fountain 2 is now enabled for Rcon Admins only.");
	      		    new string[512];
	      		    AllowedFirework[Fountain2] = 1;
				    format(string, sizeof(string), "DrawDistance: %s\nFire Cracker: %s\nFirerocket1: %s\nFirerocket2: %s\nCrackerRoll: %s\nFountain1: %s\nFountain2: %s\nFountain3: %s\nRocketBox: %s",
					DrawDistanceWord[AllowedFirework[DrawDistance]], UsageFW[AllowedFirework[FireCracker]], UsageFW[AllowedFirework[Firerocket1]], UsageFW[AllowedFirework[Firerocket2]], UsageFW[AllowedFirework[Crackerroll]], UsageFW[AllowedFirework[Fountain1]], UsageFW[AllowedFirework[Fountain2]], UsageFW[AllowedFirework[Fountain3]], UsageFW[AllowedFirework[RocketB]]);
			        ShowPlayerDialog(playerid, FWCPM,2,"FireWork Control Panel", string,"Select", "Close");
                    SaveFireWorkInfo();
					return 1;
				}
			}
			return 1;
		}
		return 1;
	}
	if(dialogid == FWCPFT3)
	{
 		if(response == 0)
 		{
 		    new string[512];
		    format(string, sizeof(string), "DrawDistance: %s\nFire Cracker: %s\nFirerocket1: %s\nFirerocket2: %s\nCrackerRoll: %s\nFountain1: %s\nFountain2: %s\nFountain3: %s\nRocketBox: %s",
			DrawDistanceWord[AllowedFirework[DrawDistance]], UsageFW[AllowedFirework[FireCracker]], UsageFW[AllowedFirework[Firerocket1]], UsageFW[AllowedFirework[Firerocket2]], UsageFW[AllowedFirework[Crackerroll]], UsageFW[AllowedFirework[Fountain1]], UsageFW[AllowedFirework[Fountain2]], UsageFW[AllowedFirework[Fountain3]], UsageFW[AllowedFirework[RocketB]]);
	        ShowPlayerDialog(playerid, FWCPM,2,"FireWork Control Panel", string,"Select", "Close");
	        return 1;
 		}
	    if(response == 1)
	    {
		    switch (listitem)
	     	{
	      		case 0: //Fountain3 usable for all
	      		{
	      		    SendClientMessage(playerid, WHITE, "[FWCP]: The Fountain 3 is now enabled for all players.");
	      		    new string[512];
	      		    AllowedFirework[Fountain3] = 0;
				    format(string, sizeof(string), "DrawDistance: %s\nFire Cracker: %s\nFirerocket1: %s\nFirerocket2: %s\nCrackerRoll: %s\nFountain1: %s\nFountain2: %s\nFountain3: %s\nRocketBox: %s",
					DrawDistanceWord[AllowedFirework[DrawDistance]], UsageFW[AllowedFirework[FireCracker]], UsageFW[AllowedFirework[Firerocket1]], UsageFW[AllowedFirework[Firerocket2]], UsageFW[AllowedFirework[Crackerroll]], UsageFW[AllowedFirework[Fountain1]], UsageFW[AllowedFirework[Fountain2]], UsageFW[AllowedFirework[Fountain3]], UsageFW[AllowedFirework[RocketB]]);
			        ShowPlayerDialog(playerid, FWCPM,2,"FireWork Control Panel", string,"Select", "Close");
                    SaveFireWorkInfo();
					return 1;
	      		}
	      		case 1://Fountain3 usable for rcon only
				{
				    SendClientMessage(playerid, WHITE, "[FWCP]: The Fountain 3 is now enabled for Rcon Admins only.");
	      		    new string[512];
	      		    AllowedFirework[Fountain3] = 1;
				    format(string, sizeof(string), "DrawDistance: %s\nFire Cracker: %s\nFirerocket1: %s\nFirerocket2: %s\nCrackerRoll: %s\nFountain1: %s\nFountain2: %s\nFountain3: %s\nRocketBox: %s",
					DrawDistanceWord[AllowedFirework[DrawDistance]], UsageFW[AllowedFirework[FireCracker]], UsageFW[AllowedFirework[Firerocket1]], UsageFW[AllowedFirework[Firerocket2]], UsageFW[AllowedFirework[Crackerroll]], UsageFW[AllowedFirework[Fountain1]], UsageFW[AllowedFirework[Fountain2]], UsageFW[AllowedFirework[Fountain3]], UsageFW[AllowedFirework[RocketB]]);
			        ShowPlayerDialog(playerid, FWCPM,2,"FireWork Control Panel", string,"Select", "Close");
                    SaveFireWorkInfo();
					return 1;
				}
			}
			return 1;
		}
		return 1;
	}
	if(dialogid == FWCPRB)
	{
 		if(response == 0)
 		{
 		    new string[512];
		    format(string, sizeof(string), "DrawDistance: %s\nFire Cracker: %s\nFirerocket1: %s\nFirerocket2: %s\nCrackerRoll: %s\nFountain1: %s\nFountain2: %s\nFountain3: %s\nRocketBox: %s",
			DrawDistanceWord[AllowedFirework[DrawDistance]], UsageFW[AllowedFirework[FireCracker]], UsageFW[AllowedFirework[Firerocket1]], UsageFW[AllowedFirework[Firerocket2]], UsageFW[AllowedFirework[Crackerroll]], UsageFW[AllowedFirework[Fountain1]], UsageFW[AllowedFirework[Fountain2]], UsageFW[AllowedFirework[Fountain3]], UsageFW[AllowedFirework[RocketB]]);
	        ShowPlayerDialog(playerid, FWCPM,2,"FireWork Control Panel", string,"Select", "Close");
	        return 1;
 		}
	    if(response == 1)
	    {
		    switch (listitem)
	     	{
	      		case 0: //RocketBox usable for all
	      		{
	      		    SendClientMessage(playerid, WHITE, "[FWCP]: The RocketBox is now enabled for all players.");
	      		    new string[512];
	      		    AllowedFirework[RocketB] = 0;
				    format(string, sizeof(string), "DrawDistance: %s\nFire Cracker: %s\nFirerocket1: %s\nFirerocket2: %s\nCrackerRoll: %s\nFountain1: %s\nFountain2: %s\nFountain3: %s\nRocketBox: %s",
					DrawDistanceWord[AllowedFirework[DrawDistance]], UsageFW[AllowedFirework[FireCracker]], UsageFW[AllowedFirework[Firerocket1]], UsageFW[AllowedFirework[Firerocket2]], UsageFW[AllowedFirework[Crackerroll]], UsageFW[AllowedFirework[Fountain1]], UsageFW[AllowedFirework[Fountain2]], UsageFW[AllowedFirework[Fountain3]], UsageFW[AllowedFirework[RocketB]]);
			        ShowPlayerDialog(playerid, FWCPM,2,"FireWork Control Panel", string,"Select", "Close");
                    SaveFireWorkInfo();
					return 1;
	      		}
	      		case 1://RocketBox usable for rcon only
				{
				    SendClientMessage(playerid, WHITE, "[FWCP]: The RocketBox is now enabled for Rcon Admins only.");
	      		    new string[512];
	      		    AllowedFirework[RocketB] = 1;
				    format(string, sizeof(string), "DrawDistance: %s\nFire Cracker: %s\nFirerocket1: %s\nFirerocket2: %s\nCrackerRoll: %s\nFountain1: %s\nFountain2: %s\nFountain3: %s\nRocketBox: %s",
					DrawDistanceWord[AllowedFirework[DrawDistance]], UsageFW[AllowedFirework[FireCracker]], UsageFW[AllowedFirework[Firerocket1]], UsageFW[AllowedFirework[Firerocket2]], UsageFW[AllowedFirework[Crackerroll]], UsageFW[AllowedFirework[Fountain1]], UsageFW[AllowedFirework[Fountain2]], UsageFW[AllowedFirework[Fountain3]], UsageFW[AllowedFirework[RocketB]]);
			        ShowPlayerDialog(playerid, FWCPM,2,"FireWork Control Panel", string,"Select", "Close");
                    SaveFireWorkInfo();
					return 1;
				}
			}
			return 1;
		}
		return 1;
	}
	return 1;
}
//!:.:!:.:!:.:!:.:!:.:!:.:!:.:!:.:![Made by Notime]!:.:!:.:!:.:!:.:!:.:!:.:!:.:!:.:!
