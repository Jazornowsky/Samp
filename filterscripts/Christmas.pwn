#include <a_samp>
#include <zcmd>
#include <dini>
#include <foreach>
#include <streamer>

#define MAX_SNOW_OBJECTS    20
#define UPDATE_INTERVAL     750
#define MAX_SONGS           4

#undef MAX_PLAYERS
#define MAX_PLAYERS 50

//COLORS
#define COLOR_GREEN 	0x00FF00FF
#define COLOR_WHITE 	0xFFFFFFFF
#define COLOR_RED       0xFF0000FF
#define COLOR_YELLOW    0xFFFF00FF

#define V03c

#pragma unused          ret_memcpy

#define DIALOG_SONG 1487

#define ploop(%0)			for(new %0 = 0; %0 < MAX_PLAYERS; %0++) if(IsPlayerConnected(%0))
#define CB:%0(%1)           forward %0(%1); public %0(%1)

new bool:snowOn[MAX_PLAYERS char],
	snowObject[MAX_PLAYERS][MAX_SNOW_OBJECTS],
	updateTimer[MAX_PLAYERS char]
;

forward MsgTimer(playerid);
forward  LoadTextdraws();
forward  AddMouthOptions();
forward  AddEyesOptions();
forward  Animate();
forward  DestroyTextdraws();
forward  HideLogo(playerid);
forward  ShowLogo(playerid);
forward CounterTimer();

new

	Text:Textdraw0,	  Text:Textdraw1,   Text:Textdraw2,
    Text:Textdraw3,	  Text:Textdraw4,   Text:Textdraw5,
    Text:Textdraw6,	  Text:Textdraw7,   Text:Textdraw8,
    Text:Textdraw9,	  Text:Textdraw10,  Text:Textdraw11,
    Text:Textdraw12,  Text:Textdraw13,  Text:Textdraw14,
    Text:Textdraw15,  Text:Textdraw16,  Text:Textdraw17,
    Text:Textdraw19,  Text:Textdraw20,
    Float:TheX = 508.000000,
	Float:BoxY = 0.499999,
	gDirection,
	gCount,
	bool:pLogo[MAX_PLAYERS];


new Objects[10];

new cTime;
new Text:NYCounter;
new Text:HappyNewYearText;

new File[50] = "Christmas.txt";
new MessageStatus[MAX_PLAYERS],Count[MAX_PLAYERS],TDShow[MAX_PLAYERS],Text:TdMsg[MAX_PLAYERS];

public OnFilterScriptInit()
{
	print("\n Christmas Filterscript Loaded! by Dimi\n");
	if(!dini_Exists(File))
	{
		dini_Create(File);
		dini_IntSet(File,"UseSong",1);
		dini_IntSet(File,"UseMessage",1);
		dini_IntSet(File,"UseHat",1);
		dini_IntSet(File,"UseSnow",1);
		dini_IntSet(File,"Use_Snowman",1);
		dini_IntSet(File,"UseCountdown",1);
		dini_IntSet(File,"Placed",0);
		dini_FloatSet(File,"PosX",0.0);
		dini_FloatSet(File,"PosY",0.0);
		dini_FloatSet(File,"PosZ",0.0);
		print("\n[XMAS] CONFIG FILE CREATED!\n");
	}
	if(dini_Int(File,"Placed") == 1)
	{
	    new Float:x,Float:y,Float:z;
		x = dini_Float(File,"PosX");
		y = dini_Float(File,"PosY");
		z = dini_Float(File,"PosZ");
		Objects[0] = CreateObject(19076, x, y, z-1.0,0.0,0.0,300);//xmas tree
   		Objects[1] = CreateObject(19054, x, y+1.0, z-0.4,0,0,0.0,300);//XmasBox1
    	Objects[2] = CreateObject(19058, x+1.0, y, z-0.4,0,0,0.0,300);//XmasBox5
    	Objects[3] = CreateObject(19056, x, y-1.0, z-0.4,0,0,0.0,300);//XmasBox3
    	Objects[4] = CreateObject(19057, x-1.0, y, z-0.4,0,0,0.0,300);//XmasBox4
    	Objects[5] = CreateObject(19058, x-1.5, y+1.5, z-1.0,0,0,0.0,300);//XmasBox5
    	Objects[6] = CreateObject(19055, x+1.5, y-1.5, z-1.0,0,0,0.0,300);//XmasBox2
    	Objects[7] = CreateObject(19057, x+1.5, y+1.5, z-1.0,0,0,0.0,300);//XmasBox4
    	Objects[8] = CreateObject(19054, x-1.5, y-1.5, z-1.0,0,0,0.0,300);//XmasBox1
    	Objects[9] = CreateObject(3526, x, y, z-1.0,0,0,300);//Airportlight - for flashing affect
    	print("\n[XMAS] TREE LOADED!\n");
	}
	if(dini_Int(File,"Use_Snowman") == 1)
	{
		SetTimer("Animate",300,true);
		LoadTextdraws();
	}
 	NYCounter = TextDrawCreate(320.000000, 399.000000, "_");
	TextDrawAlignment(NYCounter, 2);
	TextDrawBackgroundColor(NYCounter, 255);
	TextDrawFont(NYCounter, 2);
	TextDrawLetterSize(NYCounter, 0.40000, 2);
	TextDrawColor(NYCounter, -16776961);
	TextDrawSetOutline(NYCounter, 1);
	TextDrawSetProportional(NYCounter, 1);

	new year, month, day;
	getdate(year, month, day);
	if(month != 1) { year--; }
	new message[40];
	format(message, sizeof(message), "~>~ HAPPY NEW YEAR ~<~~n~~y~%d!", year);
	HappyNewYearText = TextDrawCreate(340.000000, 350.000000, message);
	TextDrawAlignment(HappyNewYearText, 2);
	TextDrawBackgroundColor(HappyNewYearText, 255);
	TextDrawFont(HappyNewYearText, 1);
	TextDrawLetterSize(HappyNewYearText, 1.000000, 4.000000);
	TextDrawColor(HappyNewYearText, 16777215);
	TextDrawSetOutline(HappyNewYearText, 1);
	TextDrawSetProportional(HappyNewYearText, 1);
    CounterTimer();
	cTime = SetTimer("CounterTimer", 400, 1);
	ploop(i)
	{
	    if(snowOn{i})
	    {
	        for(new j = 0; j < MAX_SNOW_OBJECTS; j++) DestroyDynamicObject(snowObject[i][j]);
			KillTimer(updateTimer{i});
		}
	}
	return 1;
}

public OnFilterScriptExit()
{
	DestroyTextdraws();
	TextDrawDestroy(NYCounter);
	TextDrawDestroy(HappyNewYearText);
	KillTimer(cTime);
	return 1;
}

public OnPlayerDisconnect(playerid,reason)
{
    TextDrawHideForPlayer(playerid,TdMsg[playerid]);
    if(snowOn{playerid})
	{
	    for(new i = 0; i < MAX_SNOW_OBJECTS; i++) DestroyDynamicObject(snowObject[playerid][i]);
		snowOn{playerid} = false;
		KillTimer(updateTimer{playerid});
	}
    return 1;
}

public OnPlayerConnect(playerid)
{
    TdMsg[playerid] = TextDrawCreate(337.000000, 7.000000, "~r~M~g~e~w~r~r~r~g~y ~w~C~r~h~g~r~w~i~r~s~g~t~w~m~r~a~g~s~w~!");
	TextDrawAlignment(TdMsg[playerid], 2);
	TextDrawBackgroundColor(TdMsg[playerid], 255);
	TextDrawFont(TdMsg[playerid], 0);
	TextDrawLetterSize(TdMsg[playerid], 0.539999, 2.200000);
	TextDrawColor(TdMsg[playerid], -65281);
	TextDrawSetOutline(TdMsg[playerid], 1);
	TextDrawSetProportional(TdMsg[playerid], 1);
	SendClientMessage(playerid,COLOR_GREEN,"Ha{FFFFFF}ppy {FF0000}Hol{00FF00}ida{FFFFFF}ys! {FF0000}[ /xhelp ]");
	
	if(dini_Int(File,"UseSong") == 1) PlaySong(playerid,random(MAX_SONGS));
	if(dini_Int(File,"UseMessage") == 1)
	{
	    TDShow[playerid] = SetTimerEx("MsgTimer",3000,true,"d",playerid);
	    TextDrawShowForPlayer(playerid,TdMsg[playerid]);
	    Count[playerid] = 0;
	    MessageStatus[playerid] = 1;
	}
	if(dini_Int(File,"Use_Snowman") == 1)
	{
		pLogo[playerid] = true;
		ShowLogo(playerid);
	}
	if(dini_Int(File,"UseCountdown") == 1)
	{
		new year, month, day, hour, minute, second;
		getdate(year, month, day);
		gettime(hour, minute, second);
		if(day == 1 && month == 1 && (second > 0 || hour > 0))
		{
		    TextDrawShowForPlayer(playerid, HappyNewYearText);
		}
	}
	if(dini_Int(File,"UseSnow") == 1) CreateSnow(playerid);
	return 1;
}

public MsgTimer(playerid)
{
	if(Count[playerid] >= 4) Count[playerid] = 0;
	new msg[128];
	switch(Count[playerid])
	{
	    case 0: msg = "~r~H~g~a~w~p~r~p~g~y ~w~N~r~e~g~w ~w~Y~r~e~g~a~w~r~r~!";
	    case 1: msg = "~g~M~w~e~r~r~g~r~w~y ~r~C~g~h~w~r~r~i~g~s~w~t~r~m~g~a~w~s~r~!";
	    case 2: msg = "~w~H~r~a~g~p~w~p~r~y ~g~N~w~e~r~w ~g~Y~w~e~r~a~g~r~w~!";
	    case 3: msg = "~r~M~g~e~w~r~r~r~g~y ~w~C~r~h~g~r~w~i~r~s~g~t~w~m~r~a~g~s~w~!";
	}
	Count[playerid]++;
	TextDrawHideForPlayer(playerid,TdMsg[playerid]);
	TextDrawSetString(TdMsg[playerid],msg);
	if(MessageStatus[playerid] == 1 && dini_Int(File,"UseMessage") == 1) TextDrawShowForPlayer(playerid,TdMsg[playerid]);
	return 1;
}



public OnPlayerSpawn(playerid)
{
	if(dini_Int(File,"UseHat") == 1) SetPlayerAttachedObject(playerid,9,19065,2,0.138139,0.011843,0.008412,96.002761,124.982215,5.049138,1.000000,1.000000,1.000000);
    return 1;
}

public OnPlayerDeath(playerid)
{
    RemovePlayerAttachedObject(playerid,9);
    return 1;
}

CB:UpdateSnow(playerid)
{
	if(!snowOn{playerid}) return 0;
	new Float:pPos[3];
	GetPlayerPos(playerid, pPos[0], pPos[1], pPos[2]);
	for(new i = 0; i < MAX_SNOW_OBJECTS; i++) SetDynamicObjectPos(snowObject[playerid][i], pPos[0] + random(25), pPos[1] + random(25), pPos[2] - 5);
	return 1;
}

CMD:xsnow(playerid, params[])
{
	if(snowOn{playerid})
	{
	    DeleteSnow(playerid);
	    SendClientMessage(playerid, 0x00FF00AA, "* It's not snowing anymore now.");
	}
	else
	{
	    CreateSnow(playerid);
	    SendClientMessage(playerid, 0x00FF00AA, "* Let it snow, let it snow, let it snow!");
	}
	return 1;
}

CMD:xsnowforall(playerid, params[])
{
    if(!IsPlayerAdmin(playerid)) return 0;
    ploop(i) //This is included in my FS! It's the '#define ploop(%0)' thing.
    {
        if(snowOn{i}) continue;
        CreateSnow(i);
    }
    return 1;
}

CMD:xnosnow(playerid, params[])
{
    if(!IsPlayerAdmin(playerid)) return 0;
    ploop(i)
    {
        if(!snowOn{i}) continue;
        DeleteSnow(i);
    }
    return 1;
}


CMD:xsnowman(playerid,params[])
{
	if(dini_Int(File,"Use_Snowman") == 0) return SendClientMessage(playerid,COLOR_RED,"Snowman is disabled!");
	if(pLogo[playerid] == true)
 	{
  		pLogo[playerid] = false;
		SendClientMessage( playerid, -1, "The logo has been hidden! [DISABLED]");
		HideLogo(playerid);
  	}
   	else
    {
    	SendClientMessage( playerid, -1, "The logo is displayed on the screen! [ENABLED]");
     	ShowLogo(  playerid  );
   	}
    return 1;
}

CMD:xsettree(playerid,params[])
{
	if(!IsPlayerAdmin(playerid)) return 0;
	if(dini_Int(File,"Placed"))
	{
	    for(new i=0;i<sizeof(Objects);i++)
		{
			DestroyObject(Objects[i]);
		}
		SendClientMessage(playerid,COLOR_RED,"Previous Tree Destroyed!");
	}
	new Float:x,Float:y,Float:z;
	GetPlayerPos(playerid,x,y,z);
	Objects[0] = CreateObject(19076, x, y, z-1.0,0.0,0.0,300);//xmas tree
   	Objects[1] = CreateObject(19054, x, y+1.0, z-0.4,0,0,0.0,300);//XmasBox1
    Objects[2] = CreateObject(19058, x+1.0, y, z-0.4,0,0,0.0,300);//XmasBox5
    Objects[3] = CreateObject(19056, x, y-1.0, z-0.4,0,0,0.0,300);//XmasBox3
    Objects[4] = CreateObject(19057, x-1.0, y, z-0.4,0,0,0.0,300);//XmasBox4
    Objects[5] = CreateObject(19058, x-1.5, y+1.5, z-1.0,0,0,0.0,300);//XmasBox5
    Objects[6] = CreateObject(19055, x+1.5, y-1.5, z-1.0,0,0,0.0,300);//XmasBox2
    Objects[7] = CreateObject(19057, x+1.5, y+1.5, z-1.0,0,0,0.0,300);//XmasBox4
    Objects[8] = CreateObject(19054, x-1.5, y-1.5, z-1.0,0,0,0.0,300);//XmasBox1
    Objects[9] = CreateObject(3526, x, y, z-1.0,0,0,300);//Airportlight - for flashing affect
	SendClientMessage(playerid,COLOR_GREEN,"** Christmas Tree Created! **");
	SetPlayerPos(playerid,x+2.0,y+1.5,z);
	dini_FloatSet(File,"PosX",x);
	dini_FloatSet(File,"PosY",y);
	dini_FloatSet(File,"PosZ",z);
	dini_IntSet(File,"Placed",1);
	return 1;
}

CMD:xdestroytree(playerid,params[])
{
    if(!IsPlayerAdmin(playerid)) return 0;
    if(dini_Int(File,"Placed") == 0) return SendClientMessage(playerid,COLOR_RED,"Tree isn't created!");
    for(new i=0;i<sizeof(Objects);i++)
	{
		DestroyObject(Objects[i]);
	}
	SendClientMessage(playerid,COLOR_RED,"Tree Destroyed!");
	dini_FloatSet(File,"PosX",0.0);
	dini_FloatSet(File,"PosY",0.0);
	dini_FloatSet(File,"PosZ",0.0);
	dini_IntSet(File,"Placed",0);
	return 1;
}

CMD:xplaysong(playerid,params[])
{
	ShowPlayerDialog(playerid,DIALOG_SONG,DIALOG_STYLE_LIST,"{00FF00}Choose {FFFFFF}Song{FF0000}:","{FF0000}We Wish You a Merry Christmas\n{00FF00}Holidays Are Coming\n{FFFFFF}Jingle Bells\n{FF0000}Let it Snow","Play","Cancel");
	return 1;
}

CMD:xstopsong(playerid,params[])
{
    StopAudioStreamForPlayer(playerid);
    return 1;
}

CMD:xmessage(playerid,params[])
{
	if(MessageStatus[playerid] == 0)
	{
		MessageStatus[playerid] = 1;
		SendClientMessage(playerid,COLOR_GREEN,"Christmas Messages Turned ON!");
		TextDrawShowForPlayer(playerid,TdMsg[playerid]);
	}
	else
	{
		MessageStatus[playerid] = 0;
		SendClientMessage(playerid,COLOR_RED,"Christmas Messages Turned OFF!");
		TextDrawHideForPlayer(playerid,TdMsg[playerid]);
	}
	return 1;
}

CMD:xplayforall(playerid,params[])
{

    if(!IsPlayerAdmin(playerid)) return 0;
    if(isnull(params))
	{
		SendClientMessage(playerid,COLOR_WHITE,"Usage: /xplayforall [Song ID] | Song IDs: 0 - We wish you a merry christmas |");
		SendClientMessage(playerid,COLOR_WHITE,"| 1 - Holidays are coming | 2 - Jingle Bells | 3 - Let it Snow |");
		return 1;
	}
	new msg[128];
 	format(msg,128,"Admin %s(%d) has played Christmas song for everyone",Name(playerid),playerid);
	if(!strcmp(params,"0",false))
	{
		for(new i=0;i<MAX_PLAYERS;i++)
		if(IsPlayerConnected(i))
		{
		    PlaySong(i,0);
		    SendClientMessage(playerid,COLOR_GREEN,msg);
		}
	}
	else if(!strcmp(params,"1",false))
	{
		for(new i=0;i<MAX_PLAYERS;i++)
		if(IsPlayerConnected(i))
		{
		    PlaySong(i,1);
		    SendClientMessage(playerid,COLOR_GREEN,msg);
		}
	}
	else if(!strcmp(params,"2",false))
	{
		for(new i=0;i<MAX_PLAYERS;i++)
		if(IsPlayerConnected(i))
		{
		    PlaySong(i,2);
		    SendClientMessage(playerid,COLOR_GREEN,msg);
		}
	}
	else if(!strcmp(params,"3",false))
	{
		for(new i=0;i<MAX_PLAYERS;i++)
		if(IsPlayerConnected(i))
		{
		    PlaySong(i,3);
		    SendClientMessage(playerid,COLOR_GREEN,msg);
		}
	}
	else
	{
		SendClientMessage(playerid,COLOR_WHITE,"Usage: /xplayforall [Song ID] | Song IDs: 0 - We wish you a merry christmas |");
		SendClientMessage(playerid,COLOR_WHITE,"| 1 - Holidays are coming | 2 - Jingle Bells | 3 - Let it Snow |");
		return 1;
	}
	return 1;
}

CMD:xstopforall(playerid,params[])
{
    if(!IsPlayerAdmin(playerid)) return 0;
    for(new i=0;i<MAX_PLAYERS;i++)
    if(IsPlayerConnected(i))
	{
	    StopAudioStreamForPlayer(i);
	    new msg[128];
	    format(msg,128,"Admin %s(%d) has stopped song for everyone",Name(playerid),playerid);
	    SendClientMessage(i,COLOR_RED,msg);
	}
	return 1;
}

CMD:xcredits(playerid,params[])
{
	SendClientMessage(playerid,COLOR_GREEN,".: * Christmas Filtercript by [MG]Dimi * :.");
	SendClientMessage(playerid,COLOR_YELLOW,">> Credits to Dimi for creating this FIlterscript.");
	SendClientMessage(playerid,COLOR_YELLOW,">> Credits to Killa[DGZ] for Christmas tree.");
	SendClientMessage(playerid,COLOR_YELLOW,">> Credits to Kwarde for Snow.");
	SendClientMessage(playerid,COLOR_YELLOW,">> Credits to Zh3r0 for Snowman.");
	SendClientMessage(playerid,COLOR_YELLOW,">> Credits to Meta for NY Countdown.");
    SendClientMessage(playerid,COLOR_YELLOW,"******************************************************");
    return 1;
}

CMD:xen_songs(playerid,params[])
{
	if(!IsPlayerAdmin(playerid)) return 0;
	if(dini_Int(File,"UseSong") == 1)
	{
	    SendClientMessage(playerid,COLOR_GREEN,"Entry Songs Disabled!");
	    dini_IntSet(File,"UseSong",0);
	    ploop(i)
		if(IsPlayerConnected(i)) StopAudioStreamForPlayer(i);
	}
	else
	{
	    SendClientMessage(playerid,COLOR_GREEN,"Entry Songs Enabled!");
	    dini_IntSet(File,"UseSong",1);
	}
	return 1;
}

CMD:xen_message(playerid,params[])
{
    if(!IsPlayerAdmin(playerid)) return 0;
	if(dini_Int(File,"UseMessage") == 1)
	{
	    SendClientMessage(playerid,COLOR_GREEN,"Christmas Messages Disabled!");
	    dini_IntSet(File,"UseMessage",0);
	    ploop(i)
	    if(IsPlayerConnected(i) && MessageStatus[i] == 1) MessageStatus[i] = 0;
	}
	else
	{
	    SendClientMessage(playerid,COLOR_GREEN,"Christmas Messages Enabled!");
	    dini_IntSet(File,"UseMessage",1);
	}
	return 1;
}

CMD:xen_snow(playerid,params[])
{
    if(!IsPlayerAdmin(playerid)) return 0;
	if(dini_Int(File,"UseSnow") == 1)
	{
	    SendClientMessage(playerid,COLOR_GREEN,"Snow Disabled!");
	    dini_IntSet(File,"UseSnow",0);
	    ploop(i)
	    if(IsPlayerConnected(i) && snowOn{i} == true)
	    {
	        DeleteSnow(i);
	        snowOn{i} = false;
		}
	}
	else
	{
	    SendClientMessage(playerid,COLOR_GREEN,"Snow Enabled!");
	    dini_IntSet(File,"UseSnow",1);
	}
	return 1;
}

CMD:xen_snowman(playerid,params[])
{
    if(!IsPlayerAdmin(playerid)) return 0;
	if(dini_Int(File,"Use_Snowman") == 1)
	{
	    SendClientMessage(playerid,COLOR_GREEN,"Snowman Disabled!");
	    dini_IntSet(File,"Use_Snowman",0);
	    ploop(i)
	    if(IsPlayerConnected(i))
	    {
	        HideLogo(i);
	        pLogo[i] = false;
		}
	}
	else
	{
	    SendClientMessage(playerid,COLOR_GREEN,"Snowman Enabled!");
	    dini_IntSet(File,"Use_Snowman",1);
	    ploop(i)
	    if(IsPlayerConnected(i))
		{
			ShowLogo(i);
			pLogo[i] = true;
		}
	}
	return 1;
}

CMD:xen_count(playerid,params[])
{
    if(!IsPlayerAdmin(playerid)) return 0;
	if(dini_Int(File,"UseCountdown") == 1)
	{
	    SendClientMessage(playerid,COLOR_GREEN,"Countdown Disabled!");
	    dini_IntSet(File,"UseCountdown",0);
	    ploop(i)
	    if(IsPlayerConnected(i))
	    {
	        TextDrawHideForAll(NYCounter);
		}
	}
	else
	{
	    SendClientMessage(playerid,COLOR_GREEN,"Countdown Enabled!");
	    dini_IntSet(File,"UseCountdown",1);
	    ploop(i)
	    if(IsPlayerConnected(i))
		{
		    TextDrawShowForAll(NYCounter);
		}
	}
	return 1;
}

CMD:xhelp(playerid,params[])
{
	SendClientMessage(playerid,COLOR_WHITE,"Christmas Filterscript by Dimi | HELP |");
	SendClientMessage(playerid,COLOR_GREEN,"/xplaysong /xstopsong /xmessage /xsnow /xsnowman /xcounton /xcountoff");
	if(IsPlayerAdmin(playerid))
	{
		SendClientMessage(playerid,COLOR_GREEN,"[RCON] /xsettree /xdestroytree /xplayforall /xstopforall /xsnowforall /xnosnow");
		SendClientMessage(playerid,COLOR_GREEN,"[RCON - ENABLING] /xen_songs /xen_message /xen_count /xen_snow /xen_hats /xen_snowman");
	}
	SendClientMessage(playerid,COLOR_RED,"Type /xcredits to see full Credits for this Filterscript.");
	return 1;
}

CMD:xen_hats(playerid,params[])
{
    if(!IsPlayerAdmin(playerid)) return 0;
    if(dini_Int(File,"UseHat") == 1)
    {
        dini_IntSet(File,"UseHat",0);
    	SendClientMessage(playerid,COLOR_GREEN,"Santa's hats disabled");
    	ploop(i)
    	if(IsPlayerConnected(i)) RemovePlayerAttachedObject(i,9);
	}
	else
	{
	    dini_IntSet(File,"UseHat",1);
	    SendClientMessage(playerid,COLOR_GREEN,"Santa's hats enabled!");
		ploop(i)
		if(IsPlayerConnected(i))
		{
			RemovePlayerAttachedObject(i,9);
		    SetPlayerAttachedObject(playerid,9,19065,2,0.138139,0.011843,0.008412,96.002761,124.982215,5.049138,1.000000,1.000000,1.000000);
	    }
	}
    return 1;
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	if(dialogid == DIALOG_SONG && response)
	{
		StopAudioStreamForPlayer(playerid);
		PlaySong(playerid,listitem);
		return 1;
	}
	return 1;
}

public Animate(   )
{
    if ( gDirection == 0 )
	{

	    gCount++;
		if ( gCount == 1 )
		{
			TheX += 0.500;
			TextDrawDestroy(Text:Textdraw11 );
		    Textdraw11 = TextDrawCreate(TheX, 405.000000, "..");
		    gDirection = 0;
		    AddEyesOptions();
	    }
	    if ( gCount == 2 )
		{
			TheX += 0.500;
			TextDrawDestroy(Text:Textdraw11 );
		    Textdraw11 = TextDrawCreate(TheX, 405.000000, "..");
		    gDirection = 0;
		    AddEyesOptions();
	    }
	    if ( gCount == 3 )
		{
			TheX += 0.500;
			TextDrawDestroy(Text:Textdraw11 );
		    Textdraw11 = TextDrawCreate(TheX, 405.000000, "..");
		    gDirection = 0;
		    AddEyesOptions();
	    }
	    if ( gCount == 4 )
		{
			TheX -= 0.500;
			TextDrawDestroy(Text:Textdraw11 );
		    Textdraw11 = TextDrawCreate(TheX, 405.000000, "..");
		    gDirection = 0;
		    AddEyesOptions();
	    }
	    if ( gCount == 5 )
		{
			TheX -= 0.500;
			TextDrawDestroy(Text:Textdraw11 );
		    Textdraw11 = TextDrawCreate(TheX, 405.000000, "..");
		    gDirection = 0;
		    AddEyesOptions();
	    }
	    if ( gCount == 6 )
		{
			TheX -= 0.500;
			TextDrawDestroy(Text:Textdraw11 );
		    Textdraw11 = TextDrawCreate(TheX, 405.000000, "..");
		    AddEyesOptions();
		    gDirection = 1;
		    gCount = 0;
	    }
	    foreach(Player, i )
	    {
	    	TextDrawShowForPlayer( i, Textdraw11);
	    }
	}
	else if ( gDirection == 1 )
	{

	    gCount++;
		if ( gCount == 1 )
		{
			TheX += 0.500;
			TextDrawDestroy(Text:Textdraw11 );
		    Textdraw11 = TextDrawCreate(TheX, 405.000000, "..");
		    gDirection = 1;
		    AddEyesOptions();
	    }
	    if ( gCount == 2 )
		{
			TheX += 0.500;
			TextDrawDestroy(Text:Textdraw11 );
		    Textdraw11 = TextDrawCreate(TheX, 405.000000, "..");
		    gDirection = 1;
		    AddEyesOptions();
	    }
	    if ( gCount == 3 )
		{
			TheX += 0.500;
			TextDrawDestroy(Text:Textdraw11 );
		    Textdraw11 = TextDrawCreate(TheX, 405.000000, "..");
		    gDirection = 1;
		    AddEyesOptions();
	    }
	    if ( gCount == 4 )
		{
			TheX -= 0.500;
			TextDrawDestroy(Text:Textdraw11 );
		    Textdraw11 = TextDrawCreate(TheX, 405.000000, "..");
		    gDirection = 1;
		    AddEyesOptions();
	    }
	    if ( gCount == 5 )
		{
			TheX -= 0.500;
			TextDrawDestroy(Text:Textdraw11 );
		    Textdraw11 = TextDrawCreate(TheX, 405.000000, "..");
		    gDirection = 1;
		    AddEyesOptions();
	    }
	    if ( gCount == 6 )
		{
			TheX -= 0.500;
			TextDrawDestroy(Text:Textdraw11 );
		    Textdraw11 = TextDrawCreate(TheX, 405.000000, "..");
		    AddEyesOptions();
		    gDirection = 2;
		    gCount = 0;
	    }
	    foreach(Player, i )
	    {
	    	TextDrawShowForPlayer( i, Textdraw11);
	    }
	}
	else if ( gDirection == 2 )
	{

	    gCount++;
		if ( gCount == 1 )
		{
			BoxY += 0.050;
		    TextDrawLetterSize(Textdraw1,  2.099999,BoxY);
		    gDirection = 2;
		    AddMouthOptions();
	    }
	    if ( gCount == 2 )
		{
			BoxY += 0.050;
		    TextDrawLetterSize(Textdraw1,  2.099999,BoxY);
		    gDirection = 2;
		    AddMouthOptions();
	    }
	    if ( gCount == 3 )
		{
			BoxY -= 0.050;
		    TextDrawLetterSize(Textdraw1,  2.099999,BoxY);
		    gDirection = 2;
		    AddMouthOptions();
	    }
	    if ( gCount == 4 )
		{
			BoxY -= 0.050;
		    TextDrawLetterSize(Textdraw1,  2.099999,BoxY);
		    gDirection = 2;
		    AddMouthOptions();
	    }
	    if ( gCount == 5 )
		{
			BoxY += 0.050;
		    TextDrawLetterSize(Textdraw1,  2.099999,BoxY);
		    gDirection = 2;
		    AddMouthOptions();
	    }
	    if ( gCount == 6 )
		{
			BoxY += 0.050;
		    TextDrawLetterSize(Textdraw1,  2.099999,BoxY);
		    gDirection = 2;
		    AddMouthOptions();
	    }
	    if ( gCount == 7 )
		{
			BoxY -= 0.050;
		    TextDrawLetterSize(Textdraw1,  2.099999,BoxY);
		    gDirection = 2;
		    AddMouthOptions();
	    }
	    if ( gCount == 8 )
		{
			BoxY-= 0.050;
		    TextDrawLetterSize(Textdraw1,  2.099999,BoxY);
		    AddMouthOptions();
		    gDirection = 0;
		    gCount = 0;
	    }
	    foreach(Player, i )
	    {
	    	TextDrawShowForPlayer( i, Textdraw1);
	    }
    }
}

public DestroyTextdraws(  )
{
	TextDrawHideForAll(Textdraw0);
	TextDrawDestroy(Textdraw0);
	TextDrawHideForAll(Textdraw1);
	TextDrawDestroy(Textdraw1);
	TextDrawHideForAll(Textdraw2);
	TextDrawDestroy(Textdraw2);
	TextDrawHideForAll(Textdraw3);
	TextDrawDestroy(Textdraw3);
	TextDrawHideForAll(Textdraw4);
	TextDrawDestroy(Textdraw4);
	TextDrawHideForAll(Textdraw5);
	TextDrawDestroy(Textdraw5);
	TextDrawHideForAll(Textdraw6);
	TextDrawDestroy(Textdraw6);
	TextDrawHideForAll(Textdraw7);
	TextDrawDestroy(Textdraw7);
	TextDrawHideForAll(Textdraw8);
	TextDrawDestroy(Textdraw8);
	TextDrawHideForAll(Textdraw9);
	TextDrawDestroy(Textdraw9);
	TextDrawHideForAll(Textdraw10);
	TextDrawDestroy(Textdraw10);
	TextDrawHideForAll(Textdraw11);
	TextDrawDestroy(Textdraw11);
	TextDrawHideForAll(Textdraw12);
	TextDrawDestroy(Textdraw12);
	TextDrawHideForAll(Textdraw13);
	TextDrawDestroy(Textdraw13);
	TextDrawHideForAll(Textdraw14);
	TextDrawDestroy(Textdraw14);
	TextDrawHideForAll(Textdraw15);
	TextDrawDestroy(Textdraw15);
	TextDrawHideForAll(Textdraw16);
	TextDrawDestroy(Textdraw16);
	TextDrawHideForAll(Textdraw17);
	TextDrawDestroy(Textdraw17);
	TextDrawHideForAll(Textdraw19);
	TextDrawDestroy(Textdraw19);
	TextDrawHideForAll(Textdraw20);
	TextDrawDestroy(Textdraw20);
}
public AddEyesOptions(   )
{
		TextDrawBackgroundColor(Textdraw11, 255);
		TextDrawFont(Textdraw11, 1);
		TextDrawLetterSize(Textdraw11, 0.400000, 1.500000);
		TextDrawColor(Textdraw11, 255);
		TextDrawSetOutline(Textdraw11, 0);
		TextDrawSetProportional(Textdraw11, 0);
		TextDrawSetShadow(Textdraw11, 0);
}
public AddMouthOptions(    )
{
		TextDrawBackgroundColor(Textdraw1, 255);
		TextDrawFont(Textdraw1, 1);
		TextDrawColor(Textdraw1, -1);
		TextDrawSetOutline(Textdraw1, 0);
		TextDrawSetProportional(Textdraw1, 1);
		TextDrawSetShadow(Textdraw1, 1);
		TextDrawUseBox(Textdraw1, 1);
		TextDrawBoxColor(Textdraw1, -1);
		TextDrawTextSize(Textdraw1, 504.000000, 0.000000);
}
public LoadTextdraws(  )
{

	// Create the textdraws:
	Textdraw0 = TextDrawCreate(501.000000, 402.000000, "O");
	TextDrawBackgroundColor(Textdraw0, 255);
	TextDrawFont(Textdraw0, 1);
	TextDrawLetterSize(Textdraw0, 0.899999, 3.000000);
	TextDrawColor(Textdraw0, -1);
	TextDrawSetOutline(Textdraw0, 0);
	TextDrawSetProportional(Textdraw0, 1);
	TextDrawSetShadow(Textdraw0, 0);

	Textdraw1 = TextDrawCreate(521.000000, 412.000000, "~n~");
	TextDrawBackgroundColor(Textdraw1, 255);
	TextDrawFont(Textdraw1, 1);
	TextDrawLetterSize(Textdraw1, 2.099999, 0.499999);
	TextDrawColor(Textdraw1, -1);
	TextDrawSetOutline(Textdraw1, 0);
	TextDrawSetProportional(Textdraw1, 1);
	TextDrawSetShadow(Textdraw1, 1);
	TextDrawUseBox(Textdraw1, 1);
	TextDrawBoxColor(Textdraw1, -1);
	TextDrawTextSize(Textdraw1, 504.000000, 0.000000);

	Textdraw2 = TextDrawCreate(496.000000, 412.000000, "O");
	TextDrawBackgroundColor(Textdraw2, 255);
	TextDrawFont(Textdraw2, 1);
	TextDrawLetterSize(Textdraw2, 1.329998, 4.899999);
	TextDrawColor(Textdraw2, -1);
	TextDrawSetOutline(Textdraw2, 0);
	TextDrawSetProportional(Textdraw2, 1);
	TextDrawSetShadow(Textdraw2, 0);

	Textdraw3 = TextDrawCreate(527.000000, 429.000000, "~n~");
	TextDrawBackgroundColor(Textdraw3, 255);
	TextDrawFont(Textdraw3, 1);
	TextDrawLetterSize(Textdraw3, 2.099999, 1.400000);
	TextDrawColor(Textdraw3, -1);
	TextDrawSetOutline(Textdraw3, 0);
	TextDrawSetProportional(Textdraw3, 1);
	TextDrawSetShadow(Textdraw3, 1);
	TextDrawUseBox(Textdraw3, 1);
	TextDrawBoxColor(Textdraw3, -1);
	TextDrawTextSize(Textdraw3, 501.000000, -2.000000);

	Textdraw4 = TextDrawCreate(511.000000, 418.000000, ":");
	TextDrawBackgroundColor(Textdraw4, 255);
	TextDrawFont(Textdraw4, 1);
	TextDrawLetterSize(Textdraw4, 0.469999, 1.500000);
	TextDrawColor(Textdraw4, 255);
	TextDrawSetOutline(Textdraw4, 0);
	TextDrawSetProportional(Textdraw4, 1);
	TextDrawSetShadow(Textdraw4, 0);

	Textdraw5 = TextDrawCreate(550.000000, 427.000000, "O");
	TextDrawBackgroundColor(Textdraw5, 255);
	TextDrawFont(Textdraw5, 1);
	TextDrawLetterSize(Textdraw5, 2.029999, 4.899999);
	TextDrawColor(Textdraw5, -1);
	TextDrawSetOutline(Textdraw5, 0);
	TextDrawSetProportional(Textdraw5, 1);
	TextDrawSetShadow(Textdraw5, 0);

	Textdraw6 = TextDrawCreate(512.000000, 432.000000, "O");
	TextDrawBackgroundColor(Textdraw6, -1);
	TextDrawFont(Textdraw6, 1);
	TextDrawLetterSize(Textdraw6, 2.029999, 4.899999);
	TextDrawColor(Textdraw6, -1);
	TextDrawSetOutline(Textdraw6, 0);
	TextDrawSetProportional(Textdraw6, 1);
	TextDrawSetShadow(Textdraw6, -2);

	Textdraw7 = TextDrawCreate(553.000000, 433.000000, "O");
	TextDrawBackgroundColor(Textdraw7, 20);
	TextDrawFont(Textdraw7, 1);
	TextDrawLetterSize(Textdraw7, 2.029999, 4.899999);
	TextDrawColor(Textdraw7, -1);
	TextDrawSetOutline(Textdraw7, 0);
	TextDrawSetProportional(Textdraw7, 1);
	TextDrawSetShadow(Textdraw7, 0);

	Textdraw8 = TextDrawCreate(573.000000, 427.000000, "O");
	TextDrawBackgroundColor(Textdraw8, -1);
	TextDrawFont(Textdraw8, 1);
	TextDrawLetterSize(Textdraw8, 3.789998, 4.899999);
	TextDrawColor(Textdraw8, -1);
	TextDrawSetOutline(Textdraw8, 0);
	TextDrawSetProportional(Textdraw8, 1);
	TextDrawSetShadow(Textdraw8, 4);

	Textdraw9 = TextDrawCreate(500.000000, 405.000000, "O");
	TextDrawBackgroundColor(Textdraw9, 255);
	TextDrawFont(Textdraw9, 1);
	TextDrawLetterSize(Textdraw9, 0.949999, 0.799998);
	TextDrawColor(Textdraw9, 255);
	TextDrawSetOutline(Textdraw9, 1);
	TextDrawSetProportional(Textdraw9, 1);

	Textdraw10 = TextDrawCreate(527.000000, 406.000000, "~n~");
	TextDrawBackgroundColor(Textdraw10, 255);
	TextDrawFont(Textdraw10, 1);
	TextDrawLetterSize(Textdraw10, 0.500000, 0.099999);
	TextDrawColor(Textdraw10, -1);
	TextDrawSetOutline(Textdraw10, 0);
	TextDrawSetProportional(Textdraw10, 1);
	TextDrawSetShadow(Textdraw10, 1);
	TextDrawUseBox(Textdraw10, 1);
	TextDrawBoxColor(Textdraw10, 255);
	TextDrawTextSize(Textdraw10, 498.000000, 0.000000);



	Textdraw12 = TextDrawCreate(511.000000, 428.000000, ":");
	TextDrawBackgroundColor(Textdraw12, 255);
	TextDrawFont(Textdraw12, 1);
	TextDrawLetterSize(Textdraw12, 0.469999, 1.500000);
	TextDrawColor(Textdraw12, 255);
	TextDrawSetOutline(Textdraw12, 0);
	TextDrawSetProportional(Textdraw12, 1);
	TextDrawSetShadow(Textdraw12, 0);

	Textdraw13 = TextDrawCreate(512.000000, 420.000000, "/");
	TextDrawBackgroundColor(Textdraw13, 255);
	TextDrawFont(Textdraw13, 1);
	TextDrawLetterSize(Textdraw13, 0.449998, -0.399998);
	TextDrawColor(Textdraw13, -15466241);
	TextDrawSetOutline(Textdraw13, 0);
	TextDrawSetProportional(Textdraw13, 1);
	TextDrawSetShadow(Textdraw13, 0);

	Textdraw14 = TextDrawCreate(530.000000, 380.000000, ".     ~n~  .  .    .      . ~n~ .   .   .     . .  .~n~     .    . ~n~ .    .       .       . ~n~    .    .     .  . ~n~ .  .   ");
	TextDrawBackgroundColor(Textdraw14, -206);
	TextDrawFont(Textdraw14, 1);
	TextDrawLetterSize(Textdraw14, 0.330000, 0.999998);
	TextDrawColor(Textdraw14, -1);
	TextDrawSetOutline(Textdraw14, 0);
	TextDrawSetProportional(Textdraw14, 1);
	TextDrawSetShadow(Textdraw14, 10);

	Textdraw15 = TextDrawCreate(576.000000, 482.000000, ".     ~n~  .  .    .      . ~n~ .   .   .     . .  .~n~     .    . ~n~ .    .       .       . ~n~    .    .     .  . ~n~ .  .   ");
	TextDrawBackgroundColor(Textdraw15, -206);
	TextDrawFont(Textdraw15, 1);
	TextDrawLetterSize(Textdraw15, 0.330000, -1.000000);
	TextDrawColor(Textdraw15, -1);
	TextDrawSetOutline(Textdraw15, 0);
	TextDrawSetProportional(Textdraw15, 1);
	TextDrawSetShadow(Textdraw15, -60);

	Textdraw16 = TextDrawCreate(526.000000, 422.000000, "Merry Xmas!");
	TextDrawBackgroundColor(Textdraw16, -1);
	TextDrawFont(Textdraw16, 1);
	TextDrawLetterSize(Textdraw16, 0.430000, 2.000000);
	TextDrawColor(Textdraw16, -1);
	TextDrawSetOutline(Textdraw16, 0);
	TextDrawSetProportional(Textdraw16, 1);
	TextDrawSetShadow(Textdraw16, 0);

	Textdraw17 = TextDrawCreate(505.000000, 419.000000, "/");
	TextDrawBackgroundColor(Textdraw17, 255);
	TextDrawFont(Textdraw17, 1);
	TextDrawLetterSize(Textdraw17, -0.889999, 1.299998);
	TextDrawColor(Textdraw17, -1656160001);
	TextDrawSetOutline(Textdraw17, 0);
	TextDrawSetProportional(Textdraw17, 1);
	TextDrawSetShadow(Textdraw17, 0);

	Textdraw19 = TextDrawCreate(498.000000, 410.000000, "/");
	TextDrawBackgroundColor(Textdraw19, 255);
	TextDrawFont(Textdraw19, 1);
	TextDrawLetterSize(Textdraw19, -0.889999, 1.299998);
	TextDrawColor(Textdraw19, -1656160001);
	TextDrawSetOutline(Textdraw19, 0);
	TextDrawSetProportional(Textdraw19, 1);
	TextDrawSetShadow(Textdraw19, 0);

	Textdraw20 = TextDrawCreate(528.000000, 424.000000, "Merry Xmas!");
	TextDrawBackgroundColor(Textdraw20, -1);
	TextDrawFont(Textdraw20, 1);
	TextDrawLetterSize(Textdraw20, 0.409999, 1.700000);
	TextDrawColor(Textdraw20, 50);
	TextDrawSetOutline(Textdraw20, 0);
	TextDrawSetProportional(Textdraw20, 1);
	TextDrawSetShadow(Textdraw20, 0);

	Textdraw11 = TextDrawCreate(508.000000, 405.000000, "..");
	TextDrawBackgroundColor(Textdraw11, 255);
	TextDrawFont(Textdraw11, 1);
	TextDrawLetterSize(Textdraw11, 0.400000, 1.500000);
	TextDrawColor(Textdraw11, 255);
	TextDrawSetOutline(Textdraw11, 0);
	TextDrawSetProportional(Textdraw11, 0);
	TextDrawSetShadow(Textdraw11, 0);

	for(new i; i < MAX_PLAYERS; i ++)
	{
		if(IsPlayerConnected(i))
		{
			HideLogo( i );
		}
	}
}

public ShowLogo( playerid )
{
	TextDrawShowForPlayer(playerid, Textdraw0);
    TextDrawShowForPlayer(playerid, Textdraw1);
    TextDrawShowForPlayer(playerid, Textdraw2);
    TextDrawShowForPlayer(playerid, Textdraw3);
    TextDrawShowForPlayer(playerid, Textdraw4);
    TextDrawShowForPlayer(playerid, Textdraw5);
    TextDrawShowForPlayer(playerid, Textdraw6);
    TextDrawShowForPlayer(playerid, Textdraw7);
    TextDrawShowForPlayer(playerid, Textdraw8);
    TextDrawShowForPlayer(playerid, Textdraw9);
    TextDrawShowForPlayer(playerid, Textdraw10);
    TextDrawShowForPlayer(playerid, Textdraw11);
    TextDrawShowForPlayer(playerid, Textdraw12);
    TextDrawShowForPlayer(playerid, Textdraw13);
    TextDrawShowForPlayer(playerid, Textdraw14);
    TextDrawShowForPlayer(playerid, Textdraw15);
    TextDrawShowForPlayer(playerid, Textdraw16);
    TextDrawShowForPlayer(playerid, Textdraw17);
    TextDrawShowForPlayer(playerid, Textdraw19);
    TextDrawShowForPlayer(playerid, Textdraw20);
}
public HideLogo( playerid )
{
	TextDrawHideForPlayer(playerid, Textdraw0);
    TextDrawHideForPlayer(playerid, Textdraw1);
    TextDrawHideForPlayer(playerid, Textdraw2);
    TextDrawHideForPlayer(playerid, Textdraw3);
    TextDrawHideForPlayer(playerid, Textdraw4);
    TextDrawHideForPlayer(playerid, Textdraw5);
    TextDrawHideForPlayer(playerid, Textdraw6);
    TextDrawHideForPlayer(playerid, Textdraw7);
    TextDrawHideForPlayer(playerid, Textdraw8);
    TextDrawHideForPlayer(playerid, Textdraw9);
    TextDrawHideForPlayer(playerid, Textdraw10);
    TextDrawHideForPlayer(playerid, Textdraw11);
    TextDrawHideForPlayer(playerid, Textdraw12);
    TextDrawHideForPlayer(playerid, Textdraw13);
    TextDrawHideForPlayer(playerid, Textdraw14);
    TextDrawHideForPlayer(playerid, Textdraw15);
    TextDrawHideForPlayer(playerid, Textdraw16);
    TextDrawHideForPlayer(playerid, Textdraw17);
    TextDrawHideForPlayer(playerid, Textdraw19);
    TextDrawHideForPlayer(playerid, Textdraw20);
}

public CounterTimer()
{
	new string[150];
	new year, month, day, hour, minute, second;
	getdate(year, month, day);
	gettime(hour, minute, second);
	if(month == 1 && day == 1)
	{
	    TextDrawHideForAll(NYCounter);
	    TextDrawShowForAll(HappyNewYearText);
	    KillTimer(cTime);
	}
	else
	{
		gettime(hour, minute, second);

		new day2;
		switch(month)
		{
		    case 1, 3, 5, 7, 8, 10, 12: day2 = 31;
		    case 2: { if(year%4 == 0) { day2 = 29; } else { day2 = 28; } }
		    case 4, 6, 9, 11: day2 = 30;
		}
		month = 12 - month;
		day = day2 - day;
		hour = 24 - hour;
		if(hour == 24) hour = 0;
		if(minute != 0) hour--;
		minute = 60 - minute;
		if(minute == 60) minute = 0;
		if(second != 0) minute--;
		second = 60 - second;
		if(second == 60) second = 0;
		format(string, sizeof(string), "~y~2012: ~g~%02d ~w~Mo, ~g~%02d ~w~D, ~g~%02d ~w~H, ~g~%02d ~w~M, ~g~%02d ~w~S", month, day, hour, minute, second);
		TextDrawHideForAll(NYCounter);
		TextDrawSetString(NYCounter, string);
		if(dini_Int(File,"UseCountdown") == 1) TextDrawShowForAll(NYCounter);
	}
	return 1;
}
	
stock Name(playerid)
{
	new name[24];
	GetPlayerName(playerid,name,24);
	return name;
}

stock PlaySong(playerid,songid)
{
	if(dini_Int(File,"UseSong") == 0) return SendClientMessage(playerid,COLOR_RED,"Songs have been disabled by an admin!");
	switch(songid)
	{
	    case 0:PlayAudioStreamForPlayer(playerid,"http://dimi-sa-mp.weebly.com/uploads/7/0/2/3/7023626/christmas_songs_-_we_wish_you_a_merry_chrismas.mp3",0.0,0.0,0.0,350.0,0);
	    case 1:PlayAudioStreamForPlayer(playerid,"http://dimi-sa-mp.weebly.com/uploads/7/0/2/3/7023626/christmas_coca_cola_song_melanie_thornton_holidays_are_coming.mp3",0.0,0.0,0.0,350.0,0);
	    case 2:PlayAudioStreamForPlayer(playerid,"http://dimi-sa-mp.weebly.com/uploads/7/0/2/3/7023626/jingle_bells_lyrics.mp3",0.0,0.0,0.0,350.0,0);
	    case 3:PlayAudioStreamForPlayer(playerid,"http://dimi-sa-mp.weebly.com/uploads/7/0/2/3/7023626/dean_martin_-_let_it_snow.mp3",0.0,0.0,0.0,350.0,0);
	    default: return 1;
	}
	return 1;
}

stock CreateSnow(playerid)
{
	if(snowOn{playerid}) return 0;
	new Float:pPos[3];
	GetPlayerPos(playerid, pPos[0], pPos[1], pPos[2]);
	for(new i = 0; i < MAX_SNOW_OBJECTS; i++) snowObject[playerid][i] = CreateDynamicObject(18864, pPos[0] + random(25), pPos[1] + random (25), pPos[2] - 5, random(100), random(100), random(100), -1, -1, playerid);
	snowOn{playerid} = true;
	updateTimer{playerid} = SetTimerEx("UpdateSnow", UPDATE_INTERVAL, true, "i", playerid);
	return 1;
}

stock DeleteSnow(playerid)
{
	if(!snowOn{playerid}) return 0;
	for(new i = 0; i < MAX_SNOW_OBJECTS; i++) DestroyDynamicObject(snowObject[playerid][i]);
	KillTimer(updateTimer{playerid});
	snowOn{playerid} = false;
	return 1;
}
