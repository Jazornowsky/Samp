/***
*
* File: wp_utils_buildings.inc
* Auth: Damian Wojdat
* Date: 15.07.2013
* Desc: Internal script function related to buildings.
*
*************************************************************************************************************/

stock ResetBuildingData(bId)
{
	format(Building[bId][BuildingName], 128, "");
	Building[bId][FactionOwnerId] = -1;
	Building[bId][ForSale] = 0;
	Building[bId][Cash] = 0;
	Building[bId][EntranceFee] = 0;
	Building[bId][Locked] = 0;
	Building[bId][Opened] = 0;
	Building[bId][Closed] = 0;
	
	SaveBData(bId, "BuildingName");
	SaveBData(bId, "FactionOwnerId");
	SaveBData(bId, "Cash");
	SaveBData(bId, "ForSale");
	SaveBData(bId, "EntranceFee");
	SaveBData(bId, "Locked");
	SaveBData(bId, "Opened");
	SaveBData(bId, "Closed");
	
	RefreshBuildingDescription(bId);
}

stock RefreshBuildingDescription(bId)
{
	new string[128], bLocation[MAX_ZONE_NAME];
	
	if(Buildings3DTextLabelA[bId])
	{
		DestroyDynamic3DTextLabel(Buildings3DTextLabelA[bId]);
	}
	if(Buildings3DTextLabelB[bId])
	{
		DestroyDynamic3DTextLabel(Buildings3DTextLabelB[bId]);
	}
	if(Buildings3DTextLabelC[bId])
	{
		DestroyDynamic3DTextLabel(Buildings3DTextLabelC[bId]);
	}
	
	if(Building[bId][EnterPickupId])
	{
		DestroyDynamicPickup(Building[bId][EnterPickupId]);
	}
	
	if(Building[bId][ExitPickupId])
	{
		DestroyDynamicPickup(Building[bId][ExitPickupId]);
	}
	
	if(Building[bId][ExitX] != 0.0 || Building[bId][ExitY] != 0.0)
	{
		Building[bId][ExitPickupId] = CreateDynamicPickup(1318, 1, Building[bId][ExitX], Building[bId][ExitY], Building[bId][ExitZ], bId, Building[bId][ExitInterior]);
	}
	
	if(Building[bId][EnterX] != 0.0 || Building[bId][EnterY] != 0.0)
	{
		Building[bId][EnterPickupId] = CreateDynamicPickup(1272, 1, Building[bId][EnterX], Building[bId][EnterY], Building[bId][EnterZ], Building[bId][EnterWorld], Building[bId][EnterInterior]);	
		
		GetCoords2DZone(Building[bId][EnterX], Building[bId][EnterY], bLocation, MAX_ZONE_NAME);
		
		if(strlen(Building[bId][BuildingName]) == 0)
		{
			format(string, sizeof(string), "%s %d", bLocation, Building[bId][StreetNo]);
		}
		else
		{
			format(string, sizeof(string), "%s %d, %s", bLocation, Building[bId][StreetNo], Building[bId][BuildingName]);
		}
		
		Buildings3DTextLabelA[bId] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE2, Building[bId][EnterX], Building[bId][EnterY], Building[bId][EnterZ]+1.0, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
		
		if(Building[bId][FactionOwnerId] == -1 || Building[bId][ForSale])
		{
			format(string, sizeof(string), "Budynek jest na sprzeda¿ za $%d /kupbudynek", Building[bId][Price]);
		}
		else if(DynamicFactions[Building[bId][FactionOwnerId]][fType] != FACTIONT_GANG)
		{
			format(string, sizeof(string), " ");
		}
		else
		{
			format(string, sizeof(string), " ");
		}
		
		Buildings3DTextLabelB[bId] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE2, Building[bId][EnterX], Building[bId][EnterY], Building[bId][EnterZ]+0.5, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
		
		if(Building[bId][EntranceFee] >= 1)
		{
			format(string, sizeof(string), "Wejsciowka $%d", Building[bId][EntranceFee]);
		}
		else
		{
			format(string, sizeof(string), " ");
		}
		
		Buildings3DTextLabelC[bId] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE2, Building[bId][EnterX], Building[bId][EnterY], Building[bId][EnterZ], 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
	}
}