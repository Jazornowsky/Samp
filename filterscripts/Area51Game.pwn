// Area 51 Game FS [Version 1.0], By sK gaL  14/05/2013  Last Update.
//==============================================================================
#include <a_samp>
#include <keypad>
#include <streamer>
#pragma tabsize 0

//==============================================================================
#define SetPlayerPosEx(%0,%1,%2,%3,%4,%5,%6) SetPlayerPos(%0 , %1 , %2 ,%3),SetPlayerFacingAngle(%0,%4),SetPlayerInterior(%0,%5),SetPlayerVirtualWorld(%0,%6)
#define SCMToActPlayers(%0,%1) for(new ii=0;ii<GetOnlinePlayers();ii++) if(IsPlayerConnected(ii) && InGame[ii]) SCM(ii,%0,%1)
#define SCM SendClientMessage 			 // Because im lazy as fuck
#define SCMToAll SendClientMessageToAll  // That too.
#define VirtualWorld 1199                // You can redefine it
#define PlayerTeam   1199  				 // This too.
#define WinnerMoney 20000                // Winner price
#define MinPlayers  1                    // Minimum player who need to /join
#define KEYPAD_DOOR_1 1
#define KEYPAD_DOOR_2 2
#define KEYPAD_DOOR_3 3

//==============================================================================
new bool:InGame[MAX_PLAYERS], bool:GameRunning, WinningPickup, winnerid=-1;
new Obj[4], Door[3], CP[3], Pickups[3], Count[2], Timer[3], Code[3];
new Text:TextDraw1, txd[100];

//==============================================================================
public OnFilterScriptInit()
{
    print("\n--------------------------------------------------------------");
    print("                   Area 51 Game FS Loaded By-");
    print("                             sK gaL ");
    print("                       14/05/2013 [Version: 1.0] ");
    print("--------------------------------------------------------------\n");

	Obj[0]=CreateDynamicObject(971,96.70, 1920.10, 20.80,0.00, 0.00,269.00,VirtualWorld);
	Obj[1]=CreateDynamicObject(8210,269.60,1882.30,16.10,270.00, 179.92, 269.67,VirtualWorld);
	Obj[2]=CreateDynamicObject(3055,213.90,1875.60,13.10,0.00,0.00,0.00,VirtualWorld);
	Obj[3]=CreateDynamicObject(1557, 233.73, 1821.37, 6.41,   0.00, 0.00, 90.00,VirtualWorld);

	Door[0]=CreateDynamicObject(3036,226.50, 1870.90,14.50,0.00,0.00,90.00,VirtualWorld);
	Door[1]=CreateDynamicObject(18769, 238.06, 1795.42, 13.23,   0.00, 90.00, 0.00,VirtualWorld);
	Door[2]=CreateDynamicObject(1557, 233.75, 1824.34, 6.41,   0.00, 0.00, -90.72,VirtualWorld);

	CP[0] = CreateDynamicCP(225.1409,1870.8571,13.7421, 1.0,VirtualWorld);
	CP[1] = CreateDynamicCP(239.8673,1801.5189,7.4141 , 1.0,VirtualWorld);
	CP[2] = CreateDynamicCP(234.1828,1820.9523,7.4141 , 1.0,VirtualWorld);

	WinningPickup = CreateDynamicPickup(19343, 2, 212.4128,1822.8239,6.4141, VirtualWorld);
	
	new var0[128];format(var0, 128, "  ");
 	TextDraw1 = TextDrawCreate(1.0, 433.0, var0);
 	format(txd,sizeof(txd),"%s Won Area51 Game!",GetName(winnerid));
	return 1;
}

//==============================================================================
public OnFilterScriptExit()
{
	GameRunning=true, EndGame();
	for(new i=0;i<sizeof(Obj);i++) 	    DestroyDynamicObject(Obj[i]);
	for(new i=0;i<sizeof(Door);i++) 	DestroyDynamicObject(Door[i]);
	for(new i=0;i<sizeof(CP);i++)   	DestroyDynamicCP(CP[i]);
	for(new i=0;i<sizeof(Pickups);i++)	DestroyDynamicPickup(Pickups[i]);
	DestroyDynamicPickup(WinningPickup);
    return 1;
}

//==============================================================================
public OnPlayerCommandText(playerid, cmdtext[])
{
	if(!strcmp(cmdtext,"/StartGame",true))
	{
	    if(!IsPlayerAdmin(playerid))return SCM(playerid, -1, "You are not a rcon admin");
	    if(GameRunning)return SCM(playerid,-1,"{FF8000}[Area51 Game]:{C0C0C0} The game is already on.");
	    Count[0]=5,Timer[0]=SetTimer("CD", 1*1000, true), GameRunning=true;
		for(new i=0;i<sizeof(Code);i++)Code[i]=random(5999-2999)+2999,printf("Code[%d]=%d",i,Code[i]); // Random Codes.
		SCMToAll(0,"***************{FFFFFF}[Area51 Game]{000000}*****************");
		SCMToAll(0x00FFFFC8,"Please notice! Area51Game is about to start !");
		SCMToAll(0xFFFF00C8,"To take part of the game, use /Join");
		SCMToAll(0,"********************************************");
		return 1;
	}
	
	if(!strcmp(cmdtext,"/CloseGame",true))
	{
	    if(!IsPlayerAdmin(playerid))return SCM(playerid, -1, "You are not a rcon admin");
	    if(!GameRunning)return SCM(playerid,-1,"{FF8000}[Area51 Game]:{C0C0C0} The game isn't running");
		EndGame();
		SCMToAll(0x00FFFFC8,"The game Area51 Closed By the admin !");
		return 1;
	}

	if(!strcmp(cmdtext,"/Join",true) || !strcmp(cmdtext,"/JoinGame",true))
	{
	    if(!GameRunning)return SCM(playerid,-1,"{FF8000}[Area51 Game]:{C0C0C0} The game isn't running now. Contact the admins.");
	    if(InGame[playerid])return SCM(playerid,-1,"{FF8000}[Area51 Game]:{C0C0C0} Chill out.Your already in the game.");
	    new pCheck=0;
		for(new i=0;i<GetOnlinePlayers();i++)
		{
			if(IsPlayerConnected(i) && InGame[i] && GetPlayerVirtualWorld(i)==VirtualWorld)
			{
				pCheck++;
			}
		}
		if(pCheck>1)return SCM(playerid,-1,"{FF8000}[Area51 Game]:{C0C0C0} Joining time is over. Sorry.");
	    new str[25+MAX_PLAYER_NAME];format(str,sizeof(str),"<< {C0C0C0}%s Joined the Area51Game (/Join)",GetName(playerid));
		SCMToAll(0xFF8000C8,str);
		InGame[playerid]=true;
		return 1;
	}
	
	if(!strcmp(cmdtext,"/QuitGame",true))
	{
	    if(!InGame[playerid] || !GameRunning)return 1;
	    KickPlayerFromGame(playerid);
	    CheckPlayers();
		return 1;
	}
	return 0;
}

//==============================================================================
forward CD();
public CD()
{
	if(Count[0]==0)
	return Count[0]=25,KillTimer(Timer[0]),StartAct();
	new str[25];format(str,sizeof(str),"~r~Area 51 Game ~g~ %d",Count[0]);
    GameTextForAll(str, 1*1000, 3 );
    Count[0]--;
    return 1;
}

//==============================================================================
forward StartAct();
public StartAct()
{
    CheckPlayers();
	new CC=0, Float:Spawns[9][4] =
	{
		{101.2032,1930.9553,18.3300,266.4993} ,{101.4914,1928.5717,18.3334,266.4993} ,{101.7253,1925.9855,18.3341,266.4993} ,
		{102.0164,1923.3114,18.3367,266.4993} ,{102.3168,1920.8043,18.3375,266.4993} ,{102.6351,1918.8785,18.3526,266.4993} ,
		{102.9418,1916.7843,18.3511,266.4993} ,{103.2301,1914.4163,18.3762,266.4993} ,{103.4854,1912.1718,18.4395,266.4993}
	};
	for(new i=0;i<GetOnlinePlayers();i++)
	{
		if(InGame[i])
		{
			if(CC==sizeof(Spawns))CC=0;
			CC++;
			SetPVarInt(i, "Skin", GetPlayerSkin(i)); // For returning old skin
			SetPlayerSkin(i,287), ResetPlayerWeapons(i);
			SetPlayerPosEx(i, Spawns[CC][0] ,Spawns[CC][1],Spawns[CC][2],Spawns[CC][3],0,VirtualWorld);
	        TogglePlayerControllable(i,0); // Freeze
	        SetPlayerTeam(i,PlayerTeam);
	        SetCameraBehindPlayer(i);
	        SetPlayerTime(i,0,0);
		}
	}
	for(new i=0;i<50;i++)SCMToActPlayers(-1,""); // Clear Chat
	SCMToActPlayers(-1,"{FF8000}[Area51 Game]:{C0C0C0} Dear players, you'll get a explenation of the game in a few seconds.");
	Count[1]=0, Timer[1]=SetTimer("Introduction", 6*1000, true);
    return 1;
}

//==============================================================================
forward Introduction();
public Introduction()
{
	if(Count[1]>=10)KillTimer(Timer[1]); // To make sure timer killed...
 CheckPlayers();
	switch(Count[1])
	{
	    case 0:SCMToActPlayers(-1,"{FF8000}[Area51 Game]:{C0C0C0} In this activity, there are locked doors and gates.");
	    case 1:SCMToActPlayers(-1,"{FF8000}[Area51 Game]:{C0C0C0} In the area there are hidding pickups which will give you the code for the locked doors");
	    case 2:SCMToActPlayers(-1,"{FF8000}[Area51 Game]:{C0C0C0} The winner will be the first one who will enter the last room.");
	    case 3:
	    {
	        new Float:PickupsLvl1[7][3] = // You can change the pickups spawns , but it must be 7 positions. Not more.
			{                             
				{211.5464,1812.2909,21.8594} ,{172.0143,1834.8248,17.6406} ,{117.8953,1871.2706,17.8359} ,
				{233.6766,1936.0747,33.8984} ,{282.4868,1829.9612,17.6481} ,{262.1819,1807.5195,25.4985} ,
				{192.4710,1940.0167,17.6406}
			};
			new Float:PickupsLvl2[7][3] =
			{
				{244.0067,1878.0615,8.7578} ,{238.9237,1862.4539,8.7578} ,{265.6482,1839.5363,6.4104} ,
				{332.0314,1837.6624,7.8281} ,{280.1072,1837.7607,11.5348} ,{276.0665,1870.2676,8.7578} ,
				{266.0165,1852.6895,8.7578}
			};
			new Float:PickupsLvl3[7][3] =
			{
				{328.2001,1846.7675,7.7266} ,{280.8895,1853.5070,8.7649} ,{262.1155,1886.6445,-30.3906} ,
				{262.1157,1886.6431,-30.3906} ,{268.2729,1891.6575,-12.8621} ,{265.8628,1840.6222,6.7261} ,
				{255.5310,1878.0601,8.7578}
			};
			new Rand=random(7);
			Pickups[0] = CreateDynamicPickup(1277, 19, PickupsLvl1[Rand][0], PickupsLvl1[Rand][1], PickupsLvl1[Rand][2], VirtualWorld);//Picks lvl 1
			Pickups[1] = CreateDynamicPickup(1277, 19, PickupsLvl2[Rand][0], PickupsLvl2[Rand][1], PickupsLvl2[Rand][2], VirtualWorld);//Picks lvl 2
			Pickups[2] = CreateDynamicPickup(1277, 19, PickupsLvl3[Rand][0], PickupsLvl3[Rand][1], PickupsLvl3[Rand][2], VirtualWorld);//Picks lvl 2
			SCMToActPlayers(-1,"{FF8000}[Area51 Game]:{C0C0C0} Good luck for everyone, GO GO GO !");
		    KillTimer(Timer[1]);
		    for(new i=0;i<GetOnlinePlayers();i++) if(InGame[i]) TogglePlayerControllable(i,1),GivePlayerWeapon(i,31,500);
	    }
	}
	Count[1]++;
	return 1;
}

//==============================================================================
public OnPlayerDeath(playerid, killerid, reason) // any case player dies O_O
{
    if(InGame[playerid])
    {
		SetPlayerTeam(playerid,NO_TEAM) , SetPlayerVirtualWorld(playerid,0);
	    InGame[playerid]=false;
	    CheckPlayers();
    }
    return 1;
}

//==============================================================================
public OnPlayerPickUpDynamicPickup(playerid, pickupid)
{
		 new st[100];
         if(pickupid == Pickups[0])format(st,sizeof(st),"[Area51 ~Secret~ Code]:{C0C0C0} %d",Code[0]),SCM(playerid,0xFFFF00C8,st);
    else if(pickupid == Pickups[1])format(st,sizeof(st),"[Area51 ~Secret~ Code]:{C0C0C0} %d",Code[1]),SCM(playerid,0xFFFF00C8,st);
    else if(pickupid == Pickups[2])format(st,sizeof(st),"[Area51 ~Secret~ Code]:{C0C0C0} %d",Code[2]),SCM(playerid,0xFFFF00C8,st);
    else if(pickupid == WinningPickup)
    	 {
			 SCMToAll(0,"***************{FFFFFF}[Area51 Game]{000000}*****************");
			 new str[MAX_PLAYER_NAME+25];format(str,sizeof(str),"The winner of the Area51Game is %s !!",GetName(playerid)), SCMToAll(0x00FFFFC8,str);
		 	 format(str,sizeof(str),"$%d :הוא זכה ב",WinnerMoney), SCMToAll(0x00FFFFC8,str);
			 SCMToAll(0,"********************************************");
			 GivePlayerMoney(playerid,WinnerMoney);
	    	 EndGame();
			 winnerid=playerid;
	 		 format(txd,sizeof(txd),"%s Won Area51 Game!",GetName(winnerid));
	    	 Timer[2]=SetTimer("TextDraw", 185, true);
	    	 SetTimer("RemoveTextDraw", 18*1000, false);
	    	 TextDrawColor(TextDraw1,0x00FFFFC8);
	    	 TextDrawShowForAll(TextDraw1);
    	 }
         if(GetPlayerVirtualWorld(playerid)==VirtualWorld && pickupid != WinningPickup)GameTextForPlayer(playerid, "~r~Top Secret ~g~Paper ~y~ Found", 3000, 1);
  	     return 1;
}

//==============================================================================
public OnPlayerEnterDynamicCP(playerid, checkpointid)
{
		 new Code0[30];valstr(Code0, Code[0]);
		 new Code1[30];valstr(Code1, Code[1]);
		 new Code2[30];valstr(Code2, Code[2]);
		 if(checkpointid==CP[0]) ShowPlayerKeypad(playerid, KEYPAD_DOOR_1, Code0);
	else if(checkpointid==CP[1]) ShowPlayerKeypad(playerid, KEYPAD_DOOR_2, Code1);
	else if(checkpointid==CP[2]) ShowPlayerKeypad(playerid, KEYPAD_DOOR_3, Code2);
	return 1;
}

//==============================================================================
public OnPlayerKeypadInput(playerid, keypadID, type, key)
{
    CheckPlayers();
    for(new i=0;i<GetOnlinePlayers();i++) if(GetPlayerKeypad(i) == GetPlayerKeypad(playerid)) HideKeypad(i);
	if(type == KEYPAD_INPUT_BAD && InGame[playerid])GameTextForPlayer(playerid, "~R~access denied", 3000, 3);
	if(type == KEYPAD_INPUT_GOOD && InGame[playerid])
	{
		GameTextForPlayer(playerid, "~G~access granted",3000, 3);
		if(keypadID == KEYPAD_DOOR_1)MoveDynamicObject(Door[0], 226.40,1873.50,14.50, 3.0);
		if(keypadID == KEYPAD_DOOR_2)MoveDynamicObject(Door[1], 238.06, 1795.42, 18.78, 3.0);
		if(keypadID == KEYPAD_DOOR_3)MoveDynamicObject(Door[2], 233.74, 1825.54, 6.41, 1.0);
	}
	return 1;
}

//==============================================================================
public OnDynamicObjectMoved(objectid)
{
		 if(objectid==Door[0])MoveDynamicObject(Door[0], 226.50, 1870.90,14.50, 3.0);
	else if(objectid==Door[1])MoveDynamicObject(Door[1], 238.06, 1795.42, 13.23, 3.0);
	else if(objectid==Door[2])MoveDynamicObject(Door[2], 233.75, 1824.34, 6.41, 3.0);
	return 1;
}

//==============================================================================
forward TextDraw();
public TextDraw()
{
	strins(txd," ",0);
	TextDrawSetString(TextDraw1, txd);
	return 1;
}

forward RemoveTextDraw();
public RemoveTextDraw()
{
    TextDrawHideForAll(TextDraw1);
    KillTimer(Timer[2]);
    strdel(txd, 0, strlen(txd));
    strins(txd,"%s Won Area51 Game!",0);
	return 1;
}

//======= Stocks ========
stock GetName(playerid)
{
	new pName[MAX_PLAYER_NAME+1];
	GetPlayerName(playerid, pName, sizeof(pName));
	return pName;
}

stock GetOnlinePlayers()
{
	new HighestID;
    for(new i=0;i<GetMaxPlayers();i++) if(IsPlayerConnected(i))HighestID=i;
    HighestID++;
    return HighestID;
}

stock InGamePlayers()
{
    new count=0;
    for(new i=0;i<GetMaxPlayers();i++) if(IsPlayerConnected(i) && InGame[i])count++;
    return count;
}

stock KickPlayerFromGame(playerid)
{
    if(!InGame[playerid])return 0;
    InGame[playerid]=false;
    if(GetPlayerVirtualWorld(playerid)==VirtualWorld)
    {
		SpawnPlayer(playerid);
		SetPlayerTeam(playerid,NO_TEAM);
		SetPlayerVirtualWorld(playerid,0);
		SetPlayerSkin(playerid,GetPVarInt(playerid, "Skin"));
		DeletePVar(playerid,"Skin");
	}
	return 1;
}

CheckPlayers()
{
	if(!GameRunning)return 0;
	if(InGamePlayers()<=MinPlayers)
	EndGame(),
	RemoveTextDraw(),
	SCMToAll(0xC0C0C0C8,".בוטלה מהסיבה: חוסר שחקנים , Area51 Game :הפעילות");
	SCMToAll(0xC0C0C0C8,"The game: Area51 Game , Canceled for the reason: Not enough players!");
	return 1;
}

EndGame()
{
	if(!GameRunning)return 0;
	for(new i=0;i<GetOnlinePlayers();i++)if(IsPlayerConnected(i) && InGame[i])  KickPlayerFromGame(i);
	for(new i=0;i<sizeof(Timer);i++)KillTimer(Timer[i]);
	GameRunning=false;
	if(winnerid!=-1)winnerid=-1;
	return 1;
}
