/***
*
* File: wp_onplayereditobject.inc
* Auth: Damian Wojdat
* Date: 15.09.2011
* Desc: OnPlayerEditDynamicObject function.
*
*************************************************************************************************************/

public OnPlayerEditDynamicObject(playerid, objectid, response, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz)
{
	new string[256];
	for(new i = 0; i < sizeof(gCustomObj); i++)
	{
		if(gCustomObj[i][cstSlotUsed] && gCustomObj[i][cstObjID] == objectid)
		{
			new lVw;
			lVw = GetPlayerVirtualWorld(playerid);
			SetDynamicObjectPos(objectid, x, y, z);
			SetDynamicObjectRot(objectid, rx, ry, rz);
			DestroyDynamic3DTextLabel(gCustomObjTextID1[playerid][i]);
			DestroyDynamic3DTextLabel(gCustomObjTextID2[playerid][i]);
			DestroyDynamic3DTextLabel(gCustomObjTextID3[playerid][i]);
			DestroyDynamic3DTextLabel(gCustomObjTextID4[playerid][i]);
			if(gCustomObjShow[playerid])
			{
				format(string, sizeof(string), "objID = %d | objModel = %d | objSlot = %d", gCustomObj[i][cstObjID], gCustomObj[i][cstObjModel], i);
				gCustomObjTextID1[playerid][i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE, x, y, z, 100.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, lVw, -1, playerid);
				format(string, sizeof(string), "objIX = %f | objY = %f | objZ = %f", x, y, z);
				gCustomObjTextID2[playerid][i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE, x, y, z-0.2, 100.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, lVw, -1, playerid);
				format(string, sizeof(string), "objIRX = %f | objRY = %f | objRZ = %f", rx, ry, rz );
				gCustomObjTextID3[playerid][i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE, x, y, z-0.4, 100.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, lVw, -1, playerid);
				format(string, sizeof(string), "made by: %s", gCustomObj[i][cstObjOwner] );
				gCustomObjTextID4[playerid][i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE, x, y, z+0.2, 100.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, lVw, -1, playerid);
				gCustomObjShowed[playerid][i] = 1;
			}
			else
			{
				gCustomObjShowed[playerid][i] = 0;
			}
			if(response == EDIT_RESPONSE_FINAL)
				SaveObjData(i);
		}
	}
}