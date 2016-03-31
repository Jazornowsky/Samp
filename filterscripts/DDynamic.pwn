/*



									-= Dynamic System By [U]214 =-


		^^Credits : [___]P0thead  -  Help Getting Started, and helping me understand better the loading functions..
				  : Dracoblue - Dini
				  : ZeeX - ZCMD
				  : Y_Less - SSCANF Plugin
				  : Incognito - streamer plugin



				** Pickups, Map Icons, Vehicles, 3D Text Labels are currently Dynamic!!!!

		***READ - THE SAVE LOCATIONS FOR THE EACH DYNAMIC TYPE, MUST NOT BE THE SAME!!! AS YOU SEE ON THE DEFAUL SAVE LOCATIONS..
				  THAT IS THE WAY TO SAVE THEM..

		***OTHER NOTE - WHEN YOU FIRST CREATE SOMETHING, A PICKUP, MAPICON, 3D LABEL, OR VEHICLE. IT WILL RETURN AN UNKNOWN COMMAND
						REMEMBER, ONLY THE FIRST TIME YOU CREATE SOMETHING!!!!! AND THE REASON IS THAT IT CREATES THE 'ID' FILE TO KEEP
						TRACK OF THE TOTAL DYNAMIC STUFF YOU GOT XD

*/


#include <a_samp>
#include <streamer>
#include <Dini>
#include <zcmd>
#include <sscanf2>
//==============================================================================
// Map Icons
//==============================================================================
#define MAPICONFILE "Dynamic/MapIcons/%d.ini"
#define MAPICONIDFILE "Dynamic/MapIcons/id.ini"

#define MAX_MAPICONS 30

new
	mIDFile[75],mFile[120];

enum MAPICON_INFO
{
	MID,
	MType,
	Float:MapX,
	Float:MapY,
	Float:MapZ
}
new mInfo[MAX_MAPICONS][MAPICON_INFO];
new MapIconUpdate;

forward SaveMapIcons();
//==============================================================================
// Pickups
//==============================================================================
#define PICKUPFILE "Dynamic/Pickups/%d.ini"
#define PICKUPIDFILE "Dynamic/Pickups/id.ini"

#define MAX_DPICKUPS 30

new
	pIDFile[75], pFile[120];

enum PICKUP_INFO
{
	PID,
	PModel,
	PType,
	Float:PickupX,
	Float:PickupY,
	Float:PickupZ
}
new pInfo[MAX_DPICKUPS][PICKUP_INFO];
new PickupUpdate;

forward SavePickups();
//==============================================================================
// 3D Text Labels
//==============================================================================
#define LABELFILE "Dynamic/3DLabels/%d.ini"
#define LABELIDFILE "Dynamic/3DLabels/id.ini"

#define MAX_LABELS 30

new
	lIDFile[75],lFile[120];

enum LABEL_INFO
{
	Text3D:LID,
	LInfo[128],
	Float:LabelX,
	Float:LabelY,
	Float:LabelZ
}
new lInfo[MAX_LABELS][LABEL_INFO];
new LabelUpdate;

forward SaveLabels();
//==============================================================================
// Objects
//==============================================================================
#define VEHICLESFILE "Dynamic/Vehicles/%d.ini"
#define VEHICLESIDFILE "Dynamic/Vehicles/id.ini"

#define MAX_DVEHICLES 50

new
	vIDFile[75],vFile[120];

enum VEHICLE_INFO
{
	Model,
	VID,
	Float:SpawnX,
	Float:SpawnY,
	Float:SpawnZ,
	Float:SpawnA
}
new vInfo[MAX_DVEHICLES][VEHICLE_INFO];
new VehicleUpdate;

forward SaveVehicles();
/*******************************************************************************
************************ ON FILTER SCRIPT INIT/EXIT ****************************
*******************************************************************************/
public OnFilterScriptInit()
{
// 	Map Icons
	LoadMapIcons();
	MapIconUpdate = SetTimer("SaveMapIcons",5000,1);
// 	Pickups
	LoadPickups();
	PickupUpdate = SetTimer("SavePickups", 5000, 1);
//  3D Labels
	LoadLabels();
	LabelUpdate = SetTimer("SaveLabels",5000,1);
//  Vehicles
	LoadVehicles();
	VehicleUpdate = SetTimer("SaveVehicles",5000,1);

	print("\n\n**************** Dynamic System By [U]214 Loaded ****************\n\n"); // Don't remove this line ;)
	return 1;
}

public OnFilterScriptExit()
{
// 	Pickups
	DestroyAllDynamicPickups();
	KillTimer(PickupUpdate);
// 	Map Icons
	DestroyAllDynamicMapIcons();
	KillTimer(MapIconUpdate);
//  3D Labels
	DestroyAllDynamic3DTextLabels();
	KillTimer(LabelUpdate);
//  Vehicles
	KillTimer(VehicleUpdate);

    print("\n\n*************** Dynamic System By [U]214 Unloaded ***************\n\n");
	return 1;
}
//==============================================================================
// Map Icons
//==============================================================================
CMD:addicon(playerid, params[])
{
	if(IsPlayerAdmin(playerid))
		return 0;
	new ModelID;
	if(unformat(params,"d",ModelID)) return SendClientMessage(playerid, 0xFFFFFFF,"USAGE: /AddIcon < Icon ID >");

	new Float:X,Float:Y,Float:Z;
	GetPlayerPos(playerid,X,Y,Z);
	CreateSavedIcon(ModelID,X,Y,Z);
	new Msg[128];
	format(Msg,sizeof(Msg),"Map Icon Successfully Created. (Model: %d)",ModelID);
	SendClientMessage(playerid, 0xFFFFFF,Msg);
	return 1;
}

CMD:removeicon(playerid,params[])
{
	if(IsPlayerAdmin(playerid))
		return 0;
	new IconID;
	if(unformat(params,"d",IconID)) return SendClientMessage(playerid, 0xFFFFFFF,"USAGE: /RemoveIcon < Icon ID >");
	if(!IsValidDynamicMapIcon(mInfo[IconID][MID])) return SendClientMessage(playerid, 0xFFFFFF,"ERROR: Pickup Does Not Exist!");

	DestroyDynamicMapIcon(mInfo[IconID][MID]);

	format(mFile,sizeof(mFile),MAPICONFILE,IconID);
	if(dini_Exists(mFile))
	{
		dini_Remove(mFile);
		dini_IntSet(mIDFile,"Total Map Icons:",dini_Int(mIDFile,"Total Map Icons:")-1);
	}

	new Msg[128];
	format(Msg,sizeof(Msg),"Map Icon ID: %d Was Destroyed",IconID);
	SendClientMessage(playerid, 0xFFFFFF,Msg);
	return 1;
}
//==============================================================================
// Pickups
//==============================================================================
CMD:addpickup(playerid, params[])
{
	if(IsPlayerAdmin(playerid))
		return 0;
	new ModelID, Type;
	if(unformat(params,"dd",ModelID,Type)) return SendClientMessage(playerid, 0xFFFFFF,"USAGE: /AddPickup < Pickup ID > < Type >");

	new Float:X,Float:Y,Float:Z;
	GetPlayerPos(playerid,X,Y,Z);
	CreateSavedPickup(ModelID,Type,X,Y,Z);
	new Msg[128];
	format(Msg,sizeof(Msg),"Pickup Successfully Created. (Model: %d) (Type: %d)",ModelID,Type);
	SendClientMessage(playerid, 0xFFFFFF,Msg);
	return 1;
}

CMD:removepickup(playerid, params[])
{
	if(IsPlayerAdmin(playerid))
		return 0;
	new PickupID;
	if(unformat(params,"d",PickupID)) return SendClientMessage(playerid, 0xFFFFFF,"USAGE: /RemovePickup < Pickup ID >");
	if(!IsValidDynamicPickup(pInfo[PickupID][PID])) return SendClientMessage(playerid, 0xFFFFFFF, "ERROR: Pickup Does Not Exist!");

	DestroyDynamicPickup(pInfo[PickupID][PID]);

	format(pFile, sizeof(pFile), PICKUPFILE, PickupID);
	if(dini_Exists(pFile))
	{
		dini_Remove(pFile);
		dini_IntSet(pIDFile, "Total Pickups:", dini_Int(pIDFile, "Total Pickups:")-1);
	}

	new Msg[128];
	format(Msg,sizeof(Msg),"Pickup ID: %d Was 1Destroyed!",PickupID);
	SendClientMessage(playerid, 0xFFFFFFF,Msg);
	return 1;
}
//==============================================================================
// Labels
//==============================================================================
CMD:addlabel(playerid, params[])
{
	if(IsPlayerAdmin(playerid))
		return 0;
	if(unformat(params,"s[128]",params)) return SendClientMessage(playerid,0xFFFFFF,"USAGE: /AddLabel < Description >");

	new Float:X,Float:Y,Float:Z;
	GetPlayerPos(playerid, X,Y,Z);
	CreateSavedLabel(params,X,Y,Z);
	new Msg[128];
	format(Msg,sizeof(Msg),"3D Text Label Successfully Created. (Description: %s)",params);
	SendClientMessage(playerid, 0xFFFFFF,Msg);
	return 1;
}

CMD:removelabel(playerid,params[])
{
	if(IsPlayerAdmin(playerid))
		return 0;
	new LabelID;
	if(unformat(params,"d",LabelID)) return SendClientMessage(playerid, 0xFFFFF,"USAGE: /RemoveLable < Label ID >");
	if(!IsValidDynamic3DTextLabel(Text3D:lInfo[LabelID][LID])) return SendClientMessage(playerid, 0xFFFFF,"ERROR: Label Does Not Exist!");

    DestroyDynamic3DTextLabel(Text3D:lInfo[LabelID][LID]);

	format(lFile,sizeof(lFile),LABELFILE,LabelID);
	if(dini_Exists(lFile))
	{
		dini_Remove(lFile);
		dini_IntSet(lIDFile,"Total 3D Labels:", dini_Int(lIDFile,"Total 3D Labels:")-1);
	}

	new Msg[128];
	format(Msg,sizeof(Msg),"3D Label ID: %d Was Destroyed!",LabelID);
	SendClientMessage(playerid, 0xFFFFFF,Msg);
	return 1;
}
//==============================================================================
// Vehicles
//==============================================================================
CMD:addveh(playerid, params[])
{
	if(IsPlayerAdmin(playerid))
		return 0;
	if(IsPlayerInAnyVehicle(playerid))
	{
		new Float:X,Float:Y,Float:Z,Float:A,ModelID;
		GetPlayerPos(playerid, X, Y, Z);
		GetVehicleZAngle(GetPlayerVehicleID(playerid), A);
		ModelID = GetVehicleModel(GetPlayerVehicleID(playerid));

		CreateSavedVehicle(ModelID, X, Y, Z, A);
		new Msg[128];
		format(Msg,sizeof(Msg),"Vehicle Successfully Created. (Model: %d)",ModelID);
		SendClientMessage(playerid, 0xFFFFFF,Msg);
		return 1;
	}
	else
	{
	    SendClientMessage(playerid, 0xFFFFFF,"You Need To Be Inside A Vehicle To Use This Command!");
	}
	return 1;
}

CMD:removeveh(playerid,params[])
{
	if(IsPlayerAdmin(playerid))
		return 0;
	new dVehicleID;
	if(unformat(params,"d",dVehicleID)) return SendClientMessage(playerid, 0xFFFFFF,"USAGE: /RemoveVeh < Dynamic Vehicle ID >");

	format(vFile,sizeof(vFile),VEHICLESFILE,dVehicleID);
	if(dini_Exists(vFile))
	{
	    dini_Remove(vFile);
	    dini_IntSet(vIDFile,"Total Vehicles:", dini_Int(vIDFile, "Total Vehicles:")-1);
	}

	new Msg[128];
	format(Msg,sizeof(Msg),"Dynamic Vehicle ID: %d Was Destroyed!",dVehicleID);
	SendClientMessage(playerid, 0xFFFFF,Msg);
	return 1;
}
//==============================================================================
// Map Icons
//==============================================================================
stock LoadMapIcons()
{
	for(new x = 0; x< MAX_MAPICONS; x++)
	{
	    format(mFile,sizeof(mFile),MAPICONFILE,x);
	    mInfo[x][MType]     = dini_Int	(mFile,"MType");
	    mInfo[x][MapX]      = dini_Float(mFile,"MapX");
	    mInfo[x][MapY]      = dini_Float(mFile,"MapY");
	    mInfo[x][MapZ]      = dini_Float(mFile,"MapZ");
	    mInfo[x][MID]       = CreateDynamicMapIcon(mInfo[x][MapX],mInfo[x][MapY],mInfo[x][MapZ],mInfo[x][MType],0,-1,-1,-1,100);
	}
}

stock CreateSavedIcon(modelid,Float:x,Float:y,Float:z)
{
	format(mIDFile,sizeof(mIDFile),MAPICONIDFILE);
	if(!dini_Exists(mIDFile))
	{
	    dini_Create(mIDFile);
	    dini_IntSet(mIDFile,"Total Map Icons:",-1);
	}
	else
	{
	    dini_IntSet(mIDFile,"Total Map Icons:",dini_Int(mIDFile,"Total Map Icons:")+1);
	}

	new mID = dini_Int(mIDFile,"Total Map Icons:");
	format(mFile,sizeof(mFile),MAPICONFILE,mID);
	if(!dini_Exists(mFile)) dini_Create(mFile);

	mInfo[mID][MType]   = modelid;
	mInfo[mID][MapX]    = x;
	mInfo[mID][MapY]    = y;
	mInfo[mID][MapZ]    = z;
	mInfo[mID][MID] 	= CreateDynamicMapIcon(x,y,z,modelid,0,-1,-1,-1,100);
}

public SaveMapIcons()
{
	for(new x = 0; x<MAX_MAPICONS; x++)
	{
	    format(mFile,sizeof(mFile),MAPICONFILE,x);
	    dini_IntSet     (mFile,"MType",	mInfo[x][MType]);
	    dini_FloatSet   (mFile,"MapX",	mInfo[x][MapX]);
	    dini_FloatSet   (mFile,"MapY",	mInfo[x][MapY]);
	    dini_FloatSet   (mFile,"MapZ",	mInfo[x][MapZ]);
	}
}
//==============================================================================
// Pickups
//==============================================================================
stock LoadPickups()
{
	for(new x=0; x<MAX_DPICKUPS; x++)
	{
		format(pFile, sizeof(pFile), PICKUPFILE, x);
	    pInfo[x][PModel] 	= dini_Int	(pFile, "PModel");
 		pInfo[x][PType] 	= dini_Int	(pFile, "PType");
	    pInfo[x][PickupX] 	= dini_Float(pFile, "PickupX");
	    pInfo[x][PickupY] 	= dini_Float(pFile, "PickupY");
	    pInfo[x][PickupZ] 	= dini_Float(pFile, "PickupZ");
	    pInfo[x][PID] 		= CreateDynamicPickup(pInfo[x][PModel], pInfo[x][PType], pInfo[x][PickupX], pInfo[x][PickupY], pInfo[x][PickupZ], -1, -1, -1, 50);
	}
}

stock CreateSavedPickup(modelid, type, Float:x, Float:y, Float:z)
{
	format(pIDFile, sizeof(pIDFile), PICKUPIDFILE);
	if(!dini_Exists(pIDFile))
	{
		dini_Create(pIDFile);
		dini_IntSet(pIDFile, "Total Pickups:", -1);
	}
	else
	{
		dini_IntSet(pIDFile, "Total Pickups:", dini_Int(pIDFile, "Total Pickups:")+1);
	}

	new pID = dini_Int(pIDFile, "Total Pickups:");
	format(pFile, sizeof(pFile), PICKUPFILE, pID);
	if(!dini_Exists(pFile)) dini_Create(pFile);

	pInfo[pID][PModel] 		= modelid;
	pInfo[pID][PType] 		= type;
	pInfo[pID][PickupX] 	= x;
	pInfo[pID][PickupY] 	= y;
	pInfo[pID][PickupZ] 	= z;
	pInfo[pID][PID] 		= CreateDynamicPickup(modelid, type, x, y, z, -1, -1, -1, 50);
}

public SavePickups()
{
	for(new x=0; x<MAX_DPICKUPS; x++)
	{
		format(pFile, sizeof(pFile), 	PICKUPFILE, x);
		dini_IntSet		(pFile, "PModel", 	pInfo[x][PModel]);
		dini_IntSet		(pFile, "PType", 	pInfo[x][PType]);
		dini_FloatSet	(pFile, "PickupX", 	pInfo[x][PickupX]);
		dini_FloatSet	(pFile, "PickupY", 	pInfo[x][PickupY]);
		dini_FloatSet	(pFile, "PickupZ", 	pInfo[x][PickupZ]);
	}
}
//==============================================================================
// 3D Text Labels
//==============================================================================
stock LoadLabels()
{
	for(new x = 0; x <MAX_LABELS; x++)
	{
	    format(lFile,sizeof(lFile),LABELFILE,x);
		format(lInfo[x][LInfo], 100, "%s", dini_Get(lFile, "LInfo"));
	    lInfo[x][LabelX]    = dini_Float(lFile,"LabelX");
	    lInfo[x][LabelY]    = dini_Float(lFile,"LabelY");
	    lInfo[x][LabelZ]    = dini_Float(lFile,"LabelZ");
	    lInfo[x][LID] 		= CreateDynamic3DTextLabel(lInfo[x][LInfo], 0xFFFFFF,lInfo[x][LabelX],lInfo[x][LabelY],lInfo[x][LabelZ],100,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,0,-1,-1,-1,100);
	}
}

stock CreateSavedLabel(name[], Float:x, Float:y, Float:z)
{
	format(lIDFile, sizeof(lIDFile), LABELIDFILE);
	if(!dini_Exists(lIDFile))
	{
		dini_Create(lIDFile);
		dini_IntSet(lIDFile, "Total 3D Labels:", -1);
	}
	else
	{
		dini_IntSet(lIDFile, "Total 3D Labels:", dini_Int(lIDFile, "Total 3D Labels:")+1);
	}

	new lID = dini_Int(lIDFile, "Total 3D Labels:");
	format(lFile, sizeof(lFile), LABELFILE, lID);
	if(!dini_Exists(lFile)) dini_Create(lFile);

	format(lInfo[lID][LInfo], 100, "%s", name);
	lInfo[lID][LabelX] 	= x;
	lInfo[lID][LabelY] 	= y;
	lInfo[lID][LabelZ] 	= z;
 	lInfo[lID][LID] 	= CreateDynamic3DTextLabel(name, 0xFFFFFF, x, y, z, 100, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1, -1, -1, 100);
}

public SaveLabels()
{
	for(new x=0; x<MAX_LABELS; x++)
	{
		format(lFile, sizeof(lFile), 	LABELFILE, x);

		dini_Set(lFile, "LInfo", lInfo[x][LInfo]);
		dini_FloatSet	(lFile, "LabelX", 	lInfo[x][LabelX]);
		dini_FloatSet	(lFile, "LabelY", 	lInfo[x][LabelY]);
		dini_FloatSet	(lFile, "LabelZ", 	lInfo[x][LabelZ]);
	}
}
//==============================================================================
// Vehicles
//==============================================================================
stock LoadVehicles()
{
	for(new x = 0; x < MAX_DVEHICLES; x++)
	{
	    format(vFile,sizeof(vFile),VEHICLESFILE,x);
	    vInfo[x][Model]		= dini_Int  (vFile,"Model");
	    vInfo[x][SpawnX]    = dini_Float(vFile,"SpawnX");
	    vInfo[x][SpawnY]    = dini_Float(vFile,"SpawnY");
	    vInfo[x][SpawnZ]    = dini_Float(vFile,"SpawnZ");
	    vInfo[x][SpawnA]    = dini_Float(vFile,"SpawnA");
	    vInfo[x][VID]       = AddStaticVehicleEx(vInfo[x][Model],vInfo[x][SpawnX],vInfo[x][SpawnY],vInfo[x][SpawnZ]+2,vInfo[x][SpawnA],-1,-1,(30*60));
	}
}

stock CreateSavedVehicle(modelid, Float:x, Float:y, Float:z, Float:a)
{
	format(vIDFile,sizeof(vIDFile),VEHICLESIDFILE);
	if(!dini_Exists(vIDFile))
	{
	    dini_Create(vIDFile);
	    dini_IntSet(vIDFile,"Total Vehicles:",-1);
	}
	else
	{
	    dini_IntSet(vIDFile,"Total Vehicles:", dini_Int(vIDFile,"Total Vehicles:")+1);
	}

	new vID = dini_Int(vIDFile,"Total Vehicles:");
	format(vFile,sizeof(vFile),VEHICLESFILE,vID);
	if(!dini_Exists(vFile)) dini_Create(vFile);

	vInfo[vID][Model]	= modelid;
	vInfo[vID][SpawnX]	= x;
	vInfo[vID][SpawnY]	= y;
	vInfo[vID][SpawnZ]  = z;
	vInfo[vID][SpawnA]  = a;
//	vInfo[vID][VID]     = AddStaticVehicleEx(modelid, x, y, z+2, a, -1, -1, (30*60));
}

public SaveVehicles()
{
	for(new x = 0; x < MAX_DVEHICLES; x++)
	{
	    format(vFile,sizeof(vFile),VEHICLESFILE,x);
	    dini_IntSet     (vFile,"Model",     vInfo[x][Model]);
	    dini_FloatSet   (vFile,"SpawnX",    vInfo[x][SpawnX]);
	    dini_FloatSet   (vFile,"SpawnY",    vInfo[x][SpawnY]);
	    dini_FloatSet   (vFile,"SpawnZ",    vInfo[x][SpawnZ]);
	    dini_FloatSet   (vFile,"SpawnA",    vInfo[x][SpawnA]);
	}
}
