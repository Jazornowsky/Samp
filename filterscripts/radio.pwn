#include <a_samp>
#include <audio>
#include <mxINI>
#define MAX_RADIO 128

forward LoadRadioParams();
forward PlayVehicleRadioForPlayer(playerid,online,volume);
forward NonChangeRadio(playerid);
forward IsAVel(vehicleid);
forward HideStationTitle(playerid,numberid);
forward CalculateX(numberid);
forward SetVolume(playerid,volume);

new NumOfRadio;
new VehRadio[MAX_VEHICLES];
new VehVolume[MAX_VEHICLES];
new PassengerInCar[MAX_VEHICLES][8];

new HandleidForPlayer[MAX_PLAYERS];
new bool:WaitForBuf[MAX_PLAYERS];
new PassengerSeat[MAX_PLAYERS];
new OldCar[MAX_PLAYERS];

new RadioParams[MAX_RADIO][2][128];
new Text:StationText[MAX_RADIO];

public OnFilterScriptInit()
{
    print("----------------------------------");
	print("[FS] Online Radio In Vehicles. Author: SDraw");
	print("Loading radio params...");
	LoadRadioParams();
	if(NumOfRadio >= MAX_RADIO) print("[WARNING] Number of radio is above maximum! There may be problems in working of script.");
	if(NumOfRadio <= 0) print("[WARNING] Number of radio is negative or zero! There may be problems in working of script.");
	print("Setup settings for vehicles...");
	for(new i = 1; i < MAX_VEHICLES; i++)
	{
		VehRadio[i] = random(NumOfRadio);
		VehVolume[i] = 30;
		for(new s = 1; s < 8; s++) PassengerInCar[i][s] = INVALID_PLAYER_ID;
	}
	print("Creating of TextDraw's...");
	StationText[0] = TextDrawCreate(275.0,20.0,"Radio Off");
	TextDrawAlignment(StationText[0],0);
	TextDrawBackgroundColor(StationText[0],0x000000ff);
	TextDrawFont(StationText[0],2);
	TextDrawLetterSize(StationText[0],0.4,1.6);
	TextDrawColor(StationText[0],0x906010ff);
	TextDrawSetOutline(StationText[0],1);
	TextDrawSetProportional(StationText[0],2);
	TextDrawSetShadow(StationText[0],1);
	for(new t = 1; t < NumOfRadio; t++)
	{
		StationText[t] = TextDrawCreate(CalculateX(t),20.0,RadioParams[t][0]);
		TextDrawAlignment(StationText[t],0);
		TextDrawBackgroundColor(StationText[t],0x000000ff);
		TextDrawFont(StationText[t],2);
		TextDrawLetterSize(StationText[t],0.4,1.6);
		TextDrawColor(StationText[t],0x906010ff);
		TextDrawSetOutline(StationText[t],1);
		TextDrawSetProportional(StationText[t],2);
		TextDrawSetShadow(StationText[t],1);
	}
	print("Loaded.");
	print("----------------------------------");
	return 1;
}

public OnFilterScriptExit()
{
	print("----------------------------------");
 	print("Unloading of FS...");
	print("Destroying of TextDraw's...");
	for(new t = 0; t <= NumOfRadio; t++) TextDrawDestroy(StationText[t]);
	print("Unloaded.");
	print("----------------------------------");
	return 1;
}

public OnPlayerConnect(playerid)
{
    WaitForBuf[playerid] = false;
    HandleidForPlayer[playerid] = 0;
    OldCar[playerid] = INVALID_VEHICLE_ID;
    PassengerSeat[playerid] = 0;
    return 0;
}

public OnPlayerDisconnect(playerid)
{
    if(OldCar[playerid] != INVALID_VEHICLE_ID) PassengerInCar[OldCar[playerid]][PassengerSeat[playerid]] = INVALID_PLAYER_ID;
	return 0;
}

public OnPlayerStateChange(playerid,newstate,oldstate)
{
	if(newstate == PLAYER_STATE_DRIVER || newstate == PLAYER_STATE_PASSENGER)
	{
	    if(!Audio_IsClientConnected(playerid)) return 0;
		new veh = GetPlayerVehicleID(playerid);
		if(IsAVel(veh)) return 0;
  		new seat = GetPlayerVehicleSeat(playerid);
    	if(seat != 0)
		{
			PassengerInCar[veh][seat] = playerid;
			PassengerSeat[playerid] = seat;
			OldCar[playerid] = veh;
		}
  		PlayVehicleRadioForPlayer(playerid,VehRadio[veh],VehVolume[veh]);
 	}
 	if(oldstate == PLAYER_STATE_DRIVER || oldstate == PLAYER_STATE_PASSENGER)
 	{
 	    if(!Audio_IsClientConnected(playerid)) return 0;
  		new veh = GetPlayerVehicleID(playerid);
  		if(IsAVel(veh)) return 0;
  		if(HandleidForPlayer[playerid] != 0)
  		{
	 		Audio_Stop(playerid,HandleidForPlayer[playerid]);
	 		HandleidForPlayer[playerid] = 0;
		}
		if(OldCar[playerid] != INVALID_VEHICLE_ID)
		{
  			PassengerInCar[OldCar[playerid]][PassengerSeat[playerid]] = INVALID_PLAYER_ID;
   			OldCar[playerid] = INVALID_VEHICLE_ID;
		}
	}
 	return 0;
}

public OnPlayerKeyStateChange(playerid,newkeys,oldkeys)
{
	if(newkeys == KEY_ACTION)
	{
	    if(!IsPlayerInAnyVehicle(playerid)) return 0;
     	if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return 0;
     	if(!Audio_IsClientConnected(playerid)) return 0;
   		new veh = GetPlayerVehicleID(playerid);
		if(IsAVel(veh)) return 0;
		if(WaitForBuf[playerid])
		{
			SendClientMessage(playerid,0xFF0000FF,"* You can change radiostation after 5 seconds.");
			return 0;
		}
		VehRadio[veh]++;
		if(VehRadio[veh] == NumOfRadio+1) VehRadio[veh] = 0;
		PlayVehicleRadioForPlayer(playerid,VehRadio[veh],VehVolume[veh]);
		for(new s = 1; s < 8; s++)
		{
		    if(!Audio_IsClientConnected(s)) continue;
			if(PassengerInCar[veh][s] != INVALID_PLAYER_ID && !WaitForBuf[PassengerInCar[veh][s]]) PlayVehicleRadioForPlayer(PassengerInCar[veh][s],VehRadio[veh],VehVolume[veh]);
		}
	}
	if(newkeys == 132)
	{
	    if(!IsPlayerInAnyVehicle(playerid)) return 0;
     	if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return 0;
   		new veh = GetPlayerVehicleID(playerid);
		if(IsAVel(veh)) return 0;
		if(WaitForBuf[playerid])
		{
			SendClientMessage(playerid,0xFF0000FF,"* You can change radiostation after 5 seconds.");
			return 0;
		}
		VehRadio[veh]--;
		if(VehRadio[veh] == -1) VehRadio[veh] = NumOfRadio;
		PlayVehicleRadioForPlayer(playerid,VehRadio[veh],VehVolume[veh]);
		for(new s = 1; s < 8; s++)
		{
		    if(!Audio_IsClientConnected(s)) continue;
			if(PassengerInCar[veh][s] != INVALID_PLAYER_ID && !WaitForBuf[PassengerInCar[veh][s]]) PlayVehicleRadioForPlayer(PassengerInCar[veh][s],VehRadio[veh],VehVolume[veh]);
		}
	}
	if(newkeys == KEY_ANALOG_UP)
	{
	    if(!IsPlayerInAnyVehicle(playerid)) return 0;
     	if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return 0;
      	if(!Audio_IsClientConnected(playerid)) return 0;
		new veh = GetPlayerVehicleID(playerid);
		if(IsAVel(veh)) return 0;
		if(VehVolume[veh] >= 0 && VehVolume[veh] < 100 && VehRadio[veh] != 0)
		{
			VehVolume[veh] += 5;
   			SetVolume(playerid,VehVolume[veh]);
		    for(new s = 1; s < 8; s++)
			{
				if(PassengerInCar[veh][s] != INVALID_PLAYER_ID)
				{
					if(!Audio_IsClientConnected(s)) continue;
					if(HandleidForPlayer[s] != 0) SetVolume(PassengerInCar[veh][s],VehVolume[veh]);
				}
			}
		}
	}
	if(newkeys == KEY_ANALOG_DOWN)
	{
	    if(!IsPlayerInAnyVehicle(playerid)) return 0;
     	if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return 0;
      	if(!Audio_IsClientConnected(playerid)) return 0;
		new veh = GetPlayerVehicleID(playerid);
		if(IsAVel(veh)) return 0;
		if(VehVolume[veh] > 0 && VehVolume[veh] <= 100 && VehRadio[veh] != 0)
		{
			VehVolume[veh] -= 5;
   			SetVolume(playerid,VehVolume[veh]);
	  		for(new s = 1; s < 8; s++)
			{
   				if(PassengerInCar[veh][s] != INVALID_PLAYER_ID)
	   			{
	   			    if(!Audio_IsClientConnected(s)) continue;
	   			    if(HandleidForPlayer[s] != 0) SetVolume(PassengerInCar[veh][s],VehVolume[veh]);
				}
			}
		}
	}
	return 0;
}

public PlayVehicleRadioForPlayer(playerid,online,volume)
{
    TextDrawShowForPlayer(playerid,StationText[online]);
	if(online == 0)
	{
	    Audio_Stop(playerid,HandleidForPlayer[playerid]);
		HandleidForPlayer[playerid] = 0;
		WaitForBuf[playerid] = true;
		SetTimerEx("NonChangeRadio",5000,false,"i",playerid);
		SetTimerEx("HideStationTitle",3500,false,"id",playerid,0);
		Audio_SetRadioStation(playerid,1);
		return 1;
	}
	if(HandleidForPlayer[playerid] != 0)
	{
	    Audio_Stop(playerid,HandleidForPlayer[playerid]);
		HandleidForPlayer[playerid] = 0;
	}
	Audio_StopRadio(playerid);
	HandleidForPlayer[playerid] = Audio_PlayStreamed(playerid,RadioParams[online][1]);
	Audio_SetVolume(playerid,HandleidForPlayer[playerid],volume);
	new str[64];
    format(str,sizeof(str),"~n~~n~~n~~n~~n~~n~~n~~n~~y~Volume: %d%%",volume);
    GameTextForPlayer(playerid,str,3500,5);
	WaitForBuf[playerid] = true;
	SetTimerEx("NonChangeRadio",5000,false,"i",playerid);
	SetTimerEx("HideStationTitle",3500,false,"id",playerid,online);
	return 1;
}

public SetVolume(playerid,volume)
{
    Audio_SetVolume(playerid,HandleidForPlayer[playerid],volume);
    new str[128];
    format(str,sizeof(str),"~n~~n~~n~~n~~n~~n~~n~~n~~y~Volume: %d%%",volume);
    GameTextForPlayer(playerid,str,3500,5);
    return 1;
}

public NonChangeRadio(playerid) return WaitForBuf[playerid] = false;

public HideStationTitle(playerid,numberid) return TextDrawHideForPlayer(playerid,StationText[numberid]);

public IsAVel(vehicleid)
{
	new model = GetVehicleModel(vehicleid);
	if(model == 481 || model == 509 || model == 510) return 1;
	return 0;
}

public CalculateX(numberid)
{
	new symbols = strlen(RadioParams[numberid][0]);
	if(24-symbols > 0) return 200+((24-symbols)*5);
	if(24-symbols < 0) return 200-((symbols - 24)*5);
	return 200;
}

public LoadRadioParams()
{
	new rf = ini_openFile("radio_settings.ini");
	ini_getInteger(rf,"Radios",NumOfRadio);
	for(new i = 1; i <= NumOfRadio; i++)
	{
	    new str[32];
		format(str,sizeof(str),"Radio_Title%d",i);
	    ini_getString(rf,str,RadioParams[i][0]);
	    format(str,sizeof(str),"Radio_URL%d",i);
	    ini_getString(rf,str,RadioParams[i][1]);
	}
	ini_closeFile(rf);
	return 1;
}
