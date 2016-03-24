#include <djson>
/*
LoadFireWorkInfo();
SaveFireWorkInfo();
public FirecrackerTime(playerid);
public CrackerRollTime(playerid);
public FirerocketTime(playerid);
splittime(playerid);
splittime2(playerid);
splittime3(playerid);
lighttimer(playerid);
lighttimer2(playerid);
CreateRoll(Rollid, Float:Xv, Float:Yv, Float:Zv);
DestroyRoll(Rollid);
//FountainTimer(playerid);
Destroy1Sprinkle(playerid);
Destroy3Sprinkle(playerid);
LastSprinkles(playerid);
public RocketBoxTimer(playerid);
SplitRBSprinkle(lightobject, playerid);
DestroyRBLight(playerid);


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
					//printf("DEBUG: Xv:%f Yv:%f Zv:%f",posx,posy,posz);
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

Load()
{
    LoadFireWorkInfo();
	return 1;
}

LoadFireWorkInfo()
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
	    AllowedFirework[FWNDrawDistance] = djInt(file,"DrawDistance");
	    print("[NotimeBot]: FireWorkInfo has succesfully loaded");
	    return 1;
	}
	else return print("[NotimeBot]: An error has occupied while loading the FireWorkInfo, no such file found");
}

SaveFireWorkInfo()
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
	    djSetInt(file,"DrawDistance", AllowedFirework[FWNDrawDistance]);
	    print("[NotimeBot]: FireWorkInfo has succesfully saved");
	    return 1;
	}
	else return print("[NotimeBot]: An error has occupied while loading the FireWorkInfo, no such file found");
}

SplitRBSprinkle(lightobject, playerid)
{
	new Float:Xv, Float:Yv, Float:Zv;
	GetObjectPos(RocketBoxSprinkle[RocketBoxTime[playerid]][playerid], Xv, Yv, Zv);
	CreateExplosion(Xv, Yv, Zv, 2, 0);
	DestroyObject(RocketBoxSprinkle[RocketBoxTime[playerid]][playerid]);
	RBLight[1][playerid] = CreateObject(lightobject, Xv, Yv, Zv, 0, 0, 0);
	MoveObject(RBLight[1][playerid], (Xv-(0+(random(8)))), (Yv-(0+(random(8)))), (Zv-25), (2+(random(4))));
	RBLight[2][playerid] = CreateObject(lightobject, Xv, Yv, Zv, 0, 0, 0);
	MoveObject(RBLight[2][playerid], (Xv+(0+(random(8)))), (Yv+(0+(random(8)))), (Zv-25), (2+(random(4))));
	RBLight[3][playerid] = CreateObject(lightobject, Xv, Yv, Zv, 0, 0, 0);
	MoveObject(RBLight[3][playerid], (Xv-(0+(random(8)))), (Yv+(0+(random(8)))), (Zv-25), (2+(random(4))));
	RBLight[4][playerid] = CreateObject(lightobject, Xv, Yv, Zv, 0, 0, 0);
	MoveObject(RBLight[4][playerid], (Xv+(0+(random(8)))), (Yv-(0+(random(8)))), (Zv-25), (2+(random(4))));
	SetTimerEx("DestroyRBLight", 2600, 0, "i", playerid);
	return 1;
}

DestroyRBLight(playerid)
{
	DestroyObject(RBLight[1][playerid]);
	DestroyObject(RBLight[2][playerid]);
	DestroyObject(RBLight[3][playerid]);
	DestroyObject(RBLight[4][playerid]);
	RocketBoxTime[playerid] = RocketBoxTime[playerid]+1;
	RocketBoxTimer(playerid);
	return 1;
}

RocketBoxTimer(playerid)
{
	if(RocketBoxTime[playerid] == 11)
	{
	    RocketBoxTime[playerid] = 0;
	    DestroyObject(RocketBox[playerid]);
	    DestroyObject(RocketBoxSmoke[playerid]);
	    return 1;
	}
	if(RocketBoxTime[playerid] >= 1)
	{
	    new LightObject;
	    switch(random(2))
		{
			case 0:
			{
				LightObject = 354;
			}
			case 1:
			{
				LightObject = 1213;
			}
		}
	    RocketBoxSprinkle[RocketBoxTime[playerid]][playerid] = CreateObject(LightObject, RBX[playerid], RBY[playerid], RBZ[playerid], 0, 0, 0);
		MoveObject(RocketBoxSprinkle[RocketBoxTime[playerid]][playerid], RBX[playerid], RBY[playerid], (RBZ[playerid]+35), 20);
		SetTimerEx("SplitRBSprinkle", 1500, 0, "i",LightObject, playerid);
		return 1;
	}
	return 1;
}

Destroy1Sprinkle(playerid)
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

Destroy3Sprinkle(playerid)
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
	    new Float:Xv, Float:Yv, Float:Zv;
	    GetObjectPos(FountainSprinkle[DestroySprinkleID[playerid]][playerid] ,Xv, Yv, Zv);
	    CreateExplosion(Xv, Yv, Zv, 12, 0.0);
		DestroyObject(FountainSprinkle[DestroySprinkleID[playerid]][playerid]);
		DestroySprinkleID[playerid] = DestroySprinkleID[playerid]+1;
		return 1;
	}
	return 1;
}

LastSprinkles(playerid)
{
    Fountain1Time[playerid] = 0;
    Fountain2Time[playerid] = 0;
    Fountain3Time[playerid] = 0;
    DestroySprinkleID[playerid] = 0;
    return 1;
}

FountainTimer(playerid)
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
		MoveObject(FountainSprinkle[Fountain1Time[playerid]][playerid], (FTX[playerid]+RandomXPos), (FTY[playerid]+RandomYPos), (FTZ[playerid]+8), 30);
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
		MoveObject(FountainSprinkle[Fountain2Time[playerid]][playerid], (FTX[playerid]+RandomXPos), (FTY[playerid]+RandomYPos), (FTZ[playerid]+8), 30);
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
		MoveObject(FountainSprinkle[Fountain3Time[playerid]][playerid], (FTX[playerid]+RandomXPos), (FTY[playerid]+RandomYPos), (FTZ[playerid]+8), 30);
		Fountain3Time[playerid] = Fountain3Time[playerid]+1;
		SetTimerEx("Destroy3Sprinkle", 300, 0, "i",playerid);
		SetTimerEx("FountainTimer", (100+(random(200))), 0, "i",playerid);
		return 1;
	}
	return 1;
}

CreateRoll(Rollid, Float:Xv, Float:Yv, Float:Zv)
{
	RollParts[Rollid][1] = CreateObject(1654,Xv,Yv,Zv, 90, 90, 0);
	RollParts[Rollid][2] = CreateObject(1654,(Xv+0.25),Yv,Zv, 90, 90, 0);
	RollParts[Rollid][3] = CreateObject(1654,(Xv+0.50),Yv,Zv, 90, 90, 0);
	RollParts[Rollid][4] = CreateObject(1654,(Xv+0.75),Yv,Zv, 90, 90, 0);
	RollParts[Rollid][5] = CreateObject(1654,(Xv+1.00),Yv,Zv, 90, 90, 0);
	RollParts[Rollid][6] = CreateObject(1654,(Xv+1.25),Yv,Zv, 90, 90, 0);
	RollParts[Rollid][7] = CreateObject(1654,Xv,(Yv+0.1),Zv, 90, 90, 0);
	RollParts[Rollid][8] = CreateObject(1654,(Xv+0.25),(Yv+0.1),Zv, 90, 90, 0);
	RollParts[Rollid][9] = CreateObject(1654,(Xv+0.50),(Yv+0.1),Zv, 90, 90, 0);
	RollParts[Rollid][10] = CreateObject(1654,(Xv+0.75),(Yv+0.1),Zv, 90, 90, 0);
	RollParts[Rollid][11] = CreateObject(1654,(Xv+1.00),(Yv+0.1),Zv, 90, 90, 0);
	RollParts[Rollid][12] = CreateObject(1654,(Xv+1.25),(Yv+0.1),Zv, 90, 90, 0);
	return 1;
}

DestroyRoll(Rollid)
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

CrackerRollTime(playerid)
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
	    new Float:Xv, Float:Yv, Float:Zv;
	    if(firecrackerroll[playerid] >= 1 && firecrackerroll[playerid] <= 4)
	    {
	        GetObjectPos(RollParts[playerid][1], Xv, Yv, Zv);
            DestroyRoll(playerid);
	        CreateExplosion(Xv, Yv, Zv, 12, 0.0);
	        CreateRoll(playerid, RollStartX[playerid], RollStartY[playerid], RollStartZ[playerid]);
	        firecrackerroll[playerid] = firecrackerroll[playerid]+1;
	        SetTimerEx("CrackerRollTime", (100+(random(200))), 0, "i", playerid);
	        return 1;
	    }
	    if(firecrackerroll[playerid] >= 5 && firecrackerroll[playerid] <= 8)
	    {
	        GetObjectPos(RollParts[playerid][2], Xv, Yv, Zv);
	        DestroyRoll(playerid);
	        CreateExplosion(Xv, Yv, Zv, 12, 0.0);
	        CreateRoll(playerid, RollStartX[playerid], RollStartY[playerid], RollStartZ[playerid]);
	        firecrackerroll[playerid] = firecrackerroll[playerid]+1;
	        SetTimerEx("CrackerRollTime", (100+(random(200))), 0, "i", playerid);
	        return 1;
	    }
	    if(firecrackerroll[playerid] >= 9 && firecrackerroll[playerid] <= 12)
	    {
	        GetObjectPos(RollParts[playerid][3], Xv, Yv, Zv);
	        DestroyRoll(playerid);
	        CreateExplosion(Xv, Yv, Zv, 12, 0.0);
	        CreateRoll(playerid, RollStartX[playerid], RollStartY[playerid], RollStartZ[playerid]);
	        firecrackerroll[playerid] = firecrackerroll[playerid]+1;
	        SetTimerEx("CrackerRollTime", (100+(random(200))), 0, "i", playerid);
	        return 1;
	    }
	    if(firecrackerroll[playerid] >= 13 && firecrackerroll[playerid] <= 16)
	    {
	        GetObjectPos(RollParts[playerid][4], Xv, Yv, Zv);
	        DestroyRoll(playerid);
	        CreateExplosion(Xv, Yv, Zv, 12, 0.0);
	        CreateRoll(playerid, RollStartX[playerid], RollStartY[playerid], RollStartZ[playerid]);
	        firecrackerroll[playerid] = firecrackerroll[playerid]+1;
	        SetTimerEx("CrackerRollTime", (100+(random(200))), 0, "i", playerid);
	        return 1;
	    }
	    if(firecrackerroll[playerid] >= 17 && firecrackerroll[playerid] <= 20)
	    {
	        GetObjectPos(RollParts[playerid][5], Xv, Yv, Zv);
	        DestroyRoll(playerid);
	        CreateExplosion(Xv, Yv, Zv, 12, 0.0);
	        CreateRoll(playerid, RollStartX[playerid], RollStartY[playerid], RollStartZ[playerid]);
	        firecrackerroll[playerid] = firecrackerroll[playerid]+1;
	        SetTimerEx("CrackerRollTime", (100+(random(200))), 0, "i", playerid);
	        return 1;
	    }
	    if(firecrackerroll[playerid] >= 21 && firecrackerroll[playerid] <= 24)
	    {
	        GetObjectPos(RollParts[playerid][6], Xv, Yv, Zv);
	        DestroyRoll(playerid);
	        CreateExplosion(Xv, Yv, Zv, 12, 0.0);
	        CreateRoll(playerid, RollStartX[playerid], RollStartY[playerid], RollStartZ[playerid]);
	        firecrackerroll[playerid] = firecrackerroll[playerid]+1;
	        SetTimerEx("CrackerRollTime", (100+(random(200))), 0, "i", playerid);
	        return 1;
	    }
	    if(firecrackerroll[playerid] >= 25 && firecrackerroll[playerid] <= 28)
	    {
	        GetObjectPos(RollParts[playerid][12], Xv, Yv, Zv);
	        DestroyRoll(playerid);
	        CreateExplosion(Xv, Yv, Zv, 12, 0.0);
	        CreateRoll(playerid, RollStartX[playerid], RollStartY[playerid], RollStartZ[playerid]);
	        firecrackerroll[playerid] = firecrackerroll[playerid]+1;
	        SetTimerEx("CrackerRollTime", (100+(random(200))), 0, "i", playerid);
	        return 1;
	    }
	    if(firecrackerroll[playerid] >= 29 && firecrackerroll[playerid] <= 32)
	    {
	        GetObjectPos(RollParts[playerid][11], Xv, Yv, Zv);
	        DestroyRoll(playerid);
	        CreateExplosion(Xv, Yv, Zv, 12, 0.0);
	        CreateRoll(playerid, RollStartX[playerid], RollStartY[playerid], RollStartZ[playerid]);
	        firecrackerroll[playerid] = firecrackerroll[playerid]+1;
	        SetTimerEx("CrackerRollTime", (100+(random(200))), 0, "i", playerid);
	        return 1;
	    }
	    if(firecrackerroll[playerid] >= 33 && firecrackerroll[playerid] <= 36)
	    {
	        GetObjectPos(RollParts[playerid][10], Xv, Yv, Zv);
	        DestroyRoll(playerid);
	        CreateExplosion(Xv, Yv, Zv, 12, 0.0);
	        CreateRoll(playerid, RollStartX[playerid], RollStartY[playerid], RollStartZ[playerid]);
	        firecrackerroll[playerid] = firecrackerroll[playerid]+1;
	        SetTimerEx("CrackerRollTime", (100+(random(200))), 0, "i", playerid);
	        return 1;
	    }
	    if(firecrackerroll[playerid] >= 37 && firecrackerroll[playerid] <= 40)
	    {
	        GetObjectPos(RollParts[playerid][9], Xv, Yv, Zv);
			DestroyRoll(playerid);
	        CreateExplosion(Xv, Yv, Zv, 12, 0.0);
	        CreateRoll(playerid, RollStartX[playerid], RollStartY[playerid], RollStartZ[playerid]);
	        firecrackerroll[playerid] = firecrackerroll[playerid]+1;
	        SetTimerEx("CrackerRollTime", (100+(random(200))), 0, "i", playerid);
	        return 1;
	    }
	    if(firecrackerroll[playerid] >= 41 && firecrackerroll[playerid] <= 44)
	    {
	        GetObjectPos(RollParts[playerid][8], Xv, Yv, Zv);
	        DestroyRoll(playerid);
	        CreateExplosion(Xv, Yv, Zv, 12, 0.0);
	        CreateRoll(playerid, RollStartX[playerid], RollStartY[playerid], RollStartZ[playerid]);
	        firecrackerroll[playerid] = firecrackerroll[playerid]+1;
	        SetTimerEx("CrackerRollTime", (100+(random(200))), 0, "i", playerid);
	        return 1;
	    }
	    if(firecrackerroll[playerid] >= 45 && firecrackerroll[playerid] <= 48)
	    {
	        GetObjectPos(RollParts[playerid][7], Xv, Yv, Zv);
	        DestroyRoll(playerid);
	        CreateExplosion(Xv, Yv, Zv, 12, 0.0);
	        CreateRoll(playerid, RollStartX[playerid], RollStartY[playerid], RollStartZ[playerid]);
	        firecrackerroll[playerid] = firecrackerroll[playerid]+1;
	        SetTimerEx("CrackerRollTime", (100+(random(200))), 0, "i", playerid);
	        return 1;
	    }
	    return 1;
	}
	return 1;
}

FirecrackerTime(playerid)
{
	if(firecrackertime[playerid] == 1)
	{
	    new Float:Xv, Float:Yv,Float:Zv;
		GetObjectPos(Firecracker[playerid], Xv, Yv, Zv);
		CreateExplosion(Xv,Yv,Zv, 12, 0.0);
		DestroyObject(Firecracker[playerid]);
		firecrackertime[playerid] = 0;
		return 1;
	}
	return 1;
}

FirerocketTime(playerid)
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

splittime(playerid)
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
		new Float:Xv,Float:Yv,Float:Zv;
		GetObjectPos(Light[1][playerid], Xv, Yv, Zv);
		MoveObject(Light[1][playerid], Xv-(0+(random(6))), Yv-(0+(random(6))), Zv-20, 6);
		GetObjectPos(Light[2][playerid], Xv, Yv, Zv);
		MoveObject(Light[2][playerid], Xv-(0+(random(6))), Yv+(0+(random(6))), Zv-20, 5);
		GetObjectPos(Light[3][playerid], Xv, Yv, Zv);
		MoveObject(Light[3][playerid], Xv-(0+(random(6))), Yv, Zv-20, 4);
		GetObjectPos(Light[4][playerid], Xv, Yv, Zv);
		MoveObject(Light[4][playerid], Xv+(0+(random(6))), Yv-(0+(random(6))), Zv-20, 5);
		GetObjectPos(Light[5][playerid], Xv, Yv, Zv);
		MoveObject(Light[5][playerid], Xv+(0+(random(6))), Yv+(0+(random(6))), Zv-20, 5);
		GetObjectPos(Light[6][playerid], Xv, Yv, Zv);
		MoveObject(Light[6][playerid], Xv+(0+(random(6))), Yv, Zv-20, 4);
		GetObjectPos(Light[7][playerid], Xv, Yv, Zv);
		MoveObject(Light[7][playerid], Xv, Yv-(0+(random(6))), Zv-20, 6);
		GetObjectPos(Light[8][playerid], Xv, Yv, Zv);
		MoveObject(Light[8][playerid], Xv, Yv+(0+(random(6))), Zv-20, 5);
		SetTimerEx("lighttimer", 3900, 0, "i", playerid);
		DestroyObject(Firerocket[playerid]);
		DestroyObject(rocketsmoke[playerid]);
		return 1;
	}
	return 1;
}

splittime2(playerid)
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
		new Float:Xv,Float:Yv,Float:Zv;
		GetObjectPos(Light[1][playerid], Xv, Yv, Zv);
		MoveObject(Light[1][playerid], Xv-6, Yv-6, Zv-20, 4);
		GetObjectPos(Light[2][playerid], Xv, Yv, Zv);
		MoveObject(Light[2][playerid], Xv-6, Yv+6, Zv-20, 4);
		GetObjectPos(Light[3][playerid], Xv, Yv, Zv);
		MoveObject(Light[3][playerid], Xv-6, Yv, Zv-20, 4);
		GetObjectPos(Light[4][playerid], Xv, Yv, Zv);
		MoveObject(Light[4][playerid], Xv+6, Yv-6, Zv-20, 4);
		GetObjectPos(Light[5][playerid], Xv, Yv, Zv);
		MoveObject(Light[5][playerid], Xv+6, Yv+6, Zv-20, 4);
		GetObjectPos(Light[6][playerid], Xv, Yv, Zv);
		MoveObject(Light[6][playerid], Xv+6, Yv, Zv-20, 4);
		GetObjectPos(Light[7][playerid], Xv, Yv, Zv);
		MoveObject(Light[7][playerid], Xv, Yv-6, Zv-20, 4);
		GetObjectPos(Light[8][playerid], Xv, Yv, Zv);
		MoveObject(Light[8][playerid], Xv, Yv+6, Zv-20, 4);
		SetTimerEx("splittime3", 3000, 0, "i", playerid);
		DestroyObject(Firerocket[playerid]);
		DestroyObject(rocketsmoke[playerid]);
		return 1;
	}
	return 1;
}

splittime3(playerid)
{
	if(firerockettime[playerid] == 2)
	{
		new Float:Xv,Float:Yv,Float:Zv;
		GetObjectPos(Light[1][playerid], Xv, Yv, Zv);
		CreateExplosion(Xv, Yv, Zv, 6, 0);
		GetObjectPos(Light[2][playerid], Xv, Yv, Zv);
		CreateExplosion(Xv, Yv, Zv, 6, 0);
		GetObjectPos(Light[3][playerid], Xv, Yv, Zv);
		CreateExplosion(Xv, Yv, Zv, 6, 0);
		GetObjectPos(Light[4][playerid], Xv, Yv, Zv);
		CreateExplosion(Xv, Yv, Zv, 6, 0);
		GetObjectPos(Light[5][playerid], Xv, Yv, Zv);
		CreateExplosion(Xv, Yv, Zv, 6, 0);
		GetObjectPos(Light[6][playerid], Xv, Yv, Zv);
		CreateExplosion(Xv, Yv, Zv, 6, 0);
		GetObjectPos(Light[7][playerid], Xv, Yv, Zv);
		CreateExplosion(Xv, Yv, Zv, 6, 0);
		GetObjectPos(Light[8][playerid], Xv, Yv, Zv);
		CreateExplosion(Xv, Yv, Zv, 6, 0);
		GetObjectPos(Light[9][playerid], Xv, Yv, Zv);
		Light[11][playerid] = CreateObject(1213,Xv-7,Yv+7,Zv+8, 0, 0,0);
		Light[12][playerid] = CreateObject(1213,Xv-7,Yv,Zv+5, 0, 0,0);
		Light[13][playerid] = CreateObject(1213,Xv,Yv+7,Zv-5, 0, 0,0);
		Light[14][playerid] = CreateObject(1213,Xv,Yv-7,Zv-5, 0, 0,0);
		GetObjectPos(Light[2][playerid], Xv, Yv, Zv);
		Light[15][playerid] = CreateObject(1213,Xv,Yv-7,Zv+5, 0, 0,0);
		Light[16][playerid] = CreateObject(1213,Xv-7,Yv,Zv-5, 0, 0,0);
		Light[17][playerid] = CreateObject(1213,Xv,Yv+7,Zv-8, 0, 0,0);
		Light[18][playerid] = CreateObject(1213,Xv,Yv+7,Zv-5, 0, 0,0);
		GetObjectPos(Light[3][playerid], Xv, Yv, Zv);
		Light[19][playerid] = CreateObject(1213,Xv+7,Yv,Zv-1, 0, 0,0);
		Light[20][playerid] = CreateObject(1213,Xv-7,Yv,Zv-8, 0, 0,0);
		Light[21][playerid] = CreateObject(1213,Xv+7,Yv+7,Zv-5, 0, 0,0);
		Light[22][playerid] = CreateObject(1213,Xv,Yv,Zv+5, 0, 0,0);
		GetObjectPos(Light[4][playerid], Xv, Yv, Zv);
		Light[23][playerid] = CreateObject(1213,Xv+7,Yv-7,Zv-5, 0, 0,0);
		Light[24][playerid] = CreateObject(1213,Xv-7,Yv,Zv-7, 0, 0,0);
		Light[25][playerid] = CreateObject(1213,Xv+7,Yv+7,Zv+5, 0, 0,0);
		Light[26][playerid] = CreateObject(1213,Xv,Yv-7,Zv, 0, 0,0);
		GetObjectPos(Light[5][playerid], Xv, Yv, Zv);
		Light[27][playerid] = CreateObject(1213,Xv,Yv-7,Zv-5, 0, 0,0);
		Light[28][playerid] = CreateObject(1213,Xv-7,Yv,Zv+8, 0, 0,0);
		Light[29][playerid] = CreateObject(1213,Xv+7,Yv,Zv-8, 0, 0,0);
		Light[30][playerid] = CreateObject(1213,Xv,Yv+7,Zv+5, 0, 0,0);
		GetObjectPos(Light[6][playerid], Xv, Yv, Zv);
		Light[31][playerid] = CreateObject(1213,Xv-7,Yv-7,Zv-7, 0, 0,0);
		Light[32][playerid] = CreateObject(1213,Xv,Yv,Zv-5, 0, 0,0);
		Light[33][playerid] = CreateObject(1213,Xv+7,Yv+7,Zv+5, 0, 0,0);
		Light[34][playerid] = CreateObject(1213,Xv+4,Yv-7,Zv-5, 0, 0,0);
		GetObjectPos(Light[7][playerid], Xv, Yv, Zv);
		Light[35][playerid] = CreateObject(1213,Xv-7,Yv-7,Zv-8, 0, 0,0);
		Light[36][playerid] = CreateObject(1213,Xv-7,Yv,Zv+5, 0, 0,0);
		Light[37][playerid] = CreateObject(1213,Xv,Yv,Zv-5, 0, 0,0);
		Light[38][playerid] = CreateObject(1213,Xv,Yv-7,Zv+8, 0, 0,0);
		GetObjectPos(Light[8][playerid], Xv, Yv, Zv);
		Light[39][playerid] = CreateObject(1213,Xv-4,Yv-7,Zv-8, 0, 0,0);
		Light[40][playerid] = CreateObject(1213,Xv+7,Yv,Zv+8, 0, 0,0);
		Light[41][playerid] = CreateObject(1213,Xv+4,Yv,Zv+5, 0, 0,0);
		Light[42][playerid] = CreateObject(1213,Xv,Yv-7,Zv-5, 0, 0,0);
		GetObjectPos(Light[1][playerid], Xv, Yv, Zv);
		MoveObject(Light[1][playerid], Xv-6, Yv-6, Zv-20, 4);
		GetObjectPos(Light[2][playerid], Xv, Yv, Zv);
		MoveObject(Light[2][playerid], Xv-6, Yv+6, Zv-20, 4);
		GetObjectPos(Light[3][playerid], Xv, Yv, Zv);
		MoveObject(Light[3][playerid], Xv-6, Yv, Zv-20, 4);
		GetObjectPos(Light[4][playerid], Xv, Yv, Zv);
		MoveObject(Light[4][playerid], Xv+6, Yv-6, Zv-20, 4);
		GetObjectPos(Light[5][playerid], Xv, Yv, Zv);
		MoveObject(Light[5][playerid], Xv+6, Yv+6, Zv-20, 4);
		GetObjectPos(Light[6][playerid], Xv, Yv, Zv);
		MoveObject(Light[6][playerid], Xv+6, Yv, Zv-20, 4);
		GetObjectPos(Light[7][playerid], Xv, Yv, Zv);
		MoveObject(Light[1][playerid], Xv, Yv-6, Zv-20, 4);
		GetObjectPos(Light[8][playerid], Xv, Yv, Zv);
		MoveObject(Light[8][playerid], Xv, Yv+6, Zv-20, 4);
		GetObjectPos(Light[11][playerid], Xv, Yv, Zv);
		MoveObject(Light[11][playerid], Xv-6, Yv-6, Zv-20, 4);
		GetObjectPos(Light[12][playerid], Xv, Yv, Zv);
		MoveObject(Light[12][playerid], Xv-6, Yv-6, Zv-20, 4);
		GetObjectPos(Light[13][playerid], Xv, Yv, Zv);
		MoveObject(Light[13][playerid], Xv-6, Yv-6, Zv-20, 4);
		GetObjectPos(Light[14][playerid], Xv, Yv, Zv);
		MoveObject(Light[14][playerid], Xv-6, Yv-6, Zv-20, 4);
		GetObjectPos(Light[15][playerid], Xv, Yv, Zv);
		MoveObject(Light[15][playerid], Xv-6, Yv-6, Zv-20, 4);
		GetObjectPos(Light[16][playerid], Xv, Yv, Zv);
		MoveObject(Light[16][playerid], Xv-6, Yv-6, Zv-20, 4);
		GetObjectPos(Light[17][playerid], Xv, Yv, Zv);
		MoveObject(Light[17][playerid], Xv-6, Yv-6, Zv-20, 4);
		GetObjectPos(Light[18][playerid], Xv, Yv, Zv);
		MoveObject(Light[18][playerid], Xv-6, Yv-6, Zv-20, 4);
		GetObjectPos(Light[19][playerid], Xv, Yv, Zv);
		MoveObject(Light[19][playerid], Xv-6, Yv-6, Zv-20, 4);
		GetObjectPos(Light[20][playerid], Xv, Yv, Zv);
		MoveObject(Light[20][playerid], Xv-6, Yv-6, Zv-20, 4);
		GetObjectPos(Light[21][playerid], Xv, Yv, Zv);
		MoveObject(Light[21][playerid], Xv-6, Yv-6, Zv-20, 4);
		GetObjectPos(Light[22][playerid], Xv, Yv, Zv);
		MoveObject(Light[22][playerid], Xv-6, Yv-6, Zv-20, 4);
		GetObjectPos(Light[23][playerid], Xv, Yv, Zv);
		MoveObject(Light[23][playerid], Xv-6, Yv-6, Zv-20, 4);
		GetObjectPos(Light[24][playerid], Xv, Yv, Zv);
		MoveObject(Light[24][playerid], Xv-6, Yv-6, Zv-20, 4);
		GetObjectPos(Light[25][playerid], Xv, Yv, Zv);
		MoveObject(Light[25][playerid], Xv-6, Yv-6, Zv-20, 4);
		GetObjectPos(Light[26][playerid], Xv, Yv, Zv);
		MoveObject(Light[26][playerid], Xv-6, Yv-6, Zv-20, 4);
		GetObjectPos(Light[27][playerid], Xv, Yv, Zv);
		MoveObject(Light[27][playerid], Xv-6, Yv-6, Zv-20, 4);
		GetObjectPos(Light[28][playerid], Xv, Yv, Zv);
		MoveObject(Light[28][playerid], Xv-6, Yv-6, Zv-20, 4);
		GetObjectPos(Light[29][playerid], Xv, Yv, Zv);
		MoveObject(Light[29][playerid], Xv-6, Yv-6, Zv-20, 4);
		GetObjectPos(Light[30][playerid], Xv, Yv, Zv);
		MoveObject(Light[30][playerid], Xv-6, Yv-6, Zv-20, 4);
		GetObjectPos(Light[31][playerid], Xv, Yv, Zv);
		MoveObject(Light[31][playerid], Xv-6, Yv-6, Zv-20, 4);
		GetObjectPos(Light[32][playerid], Xv, Yv, Zv);
		MoveObject(Light[32][playerid], Xv-6, Yv-6, Zv-20, 4);
		GetObjectPos(Light[33][playerid], Xv, Yv, Zv);
		MoveObject(Light[33][playerid], Xv-6, Yv-6, Zv-20, 4);
		GetObjectPos(Light[34][playerid], Xv, Yv, Zv);
		MoveObject(Light[34][playerid], Xv-6, Yv-6, Zv-20, 4);
		GetObjectPos(Light[35][playerid], Xv, Yv, Zv);
		MoveObject(Light[35][playerid], Xv-6, Yv-6, Zv-20, 4);
		GetObjectPos(Light[36][playerid], Xv, Yv, Zv);
		MoveObject(Light[36][playerid], Xv-6, Yv-6, Zv-20, 4);
		GetObjectPos(Light[37][playerid], Xv, Yv, Zv);
		MoveObject(Light[37][playerid], Xv-6, Yv-6, Zv-20, 4);
		GetObjectPos(Light[38][playerid], Xv, Yv, Zv);
		MoveObject(Light[38][playerid], Xv-6, Yv-6, Zv-20, 4);
		GetObjectPos(Light[39][playerid], Xv, Yv, Zv);
		MoveObject(Light[39][playerid], Xv-6, Yv-6, Zv-20, 4);
		GetObjectPos(Light[40][playerid], Xv, Yv, Zv);
		MoveObject(Light[40][playerid], Xv-6, Yv-6, Zv-20, 4);
		GetObjectPos(Light[41][playerid], Xv, Yv, Zv);
		MoveObject(Light[41][playerid], Xv-6, Yv-6, Zv-20, 4);
		GetObjectPos(Light[42][playerid], Xv, Yv, Zv);
		MoveObject(Light[42][playerid], Xv-6, Yv-6, Zv-20, 4);
		SetTimerEx("lighttimer2", 4000, 0, "i", playerid);
		DestroyObject(Firerocket[playerid]);
		DestroyObject(rocketsmoke[playerid]);
		return 1;
	}
	return 1;
}

lighttimer(playerid)
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

lighttimer2(playerid)
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
}*/