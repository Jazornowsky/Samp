/***
*
* File: wp_utils_houses.inc
* Auth: Damian Wojdat
* Date: 16.07.2013
* Desc: Internal script function related to houses.
*
*************************************************************************************************************/


ResetHouseData(hID, type = 1)
{
	// type 0 - reset all data
	// type 1 - removes owner, etc, just prepare for next buyer
	
	DestroyDynamicPickup(Houses[hID][PickupID]);
	
	strdel(Houses[hID][Description], 0, 128);
	format(Houses[hID][Owner], 128, "Brak");
	strdel(Houses[hID][HRenter], 0, MAX_PLAYER_NAME);
	format(Houses[hID][HRenter], MAX_PLAYER_NAME, "Brak");
	Houses[hID][HUID] = 0;
	Houses[hID][Owned] = 0;
	Houses[hID][Rentable] = 0;
	Houses[hID][RentCost] = 0;
	Houses[hID][Locked] = 0;
	Houses[hID][HConfiscated] = 0;
	Houses[hID][HouseType] = 0;
	
	SaveHouseData(hID, "Description");
	SaveHouseData(hID, "UID");
	SaveHouseData(hID, "Owner");
	SaveHouseData(hID, "Renter");
	SaveHouseData(hID, "Owned");
	SaveHouseData(hID, "Rentable");
	SaveHouseData(hID, "RentCost");
	SaveHouseData(hID, "Locked");
	SaveHouseData(hID, "Confiscated");
	SaveHouseData(hID, "HouseType");
	
	if(type)
		Houses[hID][PickupID] = CreateDynamicPickup(1273, 1, Houses[hID][EnterX], Houses[hID][EnterY], Houses[hID][EnterZ]);
	else
	{
		Houses[hID][EnterX] = 0.0;
		Houses[hID][EnterY] = 0.0;
		Houses[hID][EnterZ] = 0.0;
		Houses[hID][EnterWorld] = 0;
		Houses[hID][EnterInterior] = 0;
		Houses[hID][EnterAngle] = 0;	
		Houses[hID][HousePrice] = 0;
		Houses[hID][Money] = 0;	
		Houses[hID][HItem1] = 0;
		Houses[hID][HItem2] = 0;
		Houses[hID][HItem3] = 0;
		Houses[hID][HItem4] = 0;
		Houses[hID][HItem5] = 0;
		Houses[hID][HItem1type] = 0;
		Houses[hID][HItem2type] = 0;
		Houses[hID][HItem3type] = 0;
		Houses[hID][HItem4type] = 0;
		Houses[hID][HItem5type] = 0;
		if(Houses[hID][HRadio1Bought])
			DestroyDynamicObject(Businesses[hID][BRadio1Obj]);
		Houses[hID][HRadio1On] = 0;
		
		SaveHouseData(hID, "EnterX");
		SaveHouseData(hID, "EnterY");
		SaveHouseData(hID, "EnterZ");
		SaveHouseData(hID, "EnterWorld");
		SaveHouseData(hID, "EnterInterior");
		SaveHouseData(hID, "EnterAngle");
		SaveHouseData(hID, "HousePrice");
		SaveHouseData(hID, "Materials");
		SaveHouseData(hID, "Drugs");
		SaveHouseData(hID, "Money");
		SaveHouseData(hID, "HItem1");
		SaveHouseData(hID, "HItem2");
		SaveHouseData(hID, "HItem3");
		SaveHouseData(hID, "HItem4");
		SaveHouseData(hID, "HItem5");
		SaveHouseData(hID, "HItem1type");
		SaveHouseData(hID, "HItem2type");
		SaveHouseData(hID, "HItem3type");
		SaveHouseData(hID, "HItem4type");
		SaveHouseData(hID, "HItem5type");
	}
	
	RefreshHouseDescription(hID);
}

stock RefreshHouseDescription(hId)
{
	new string[128], houselocation[MAX_ZONE_NAME];
	
	if(Houses3DTextLabelA[hId])
	{
		DestroyDynamic3DTextLabel(Houses3DTextLabelA[hId]);
	}
	
	if(Houses3DTextLabelB[hId])
	{
		DestroyDynamic3DTextLabel(Houses3DTextLabelB[hId]);
	}	
		
	if(Houses3DTextLabelC[hId])
	{
		DestroyDynamic3DTextLabel(Houses3DTextLabelC[hId]);
	}
		
	if(Houses[hId][PickupID])
	{
		DestroyDynamicPickup(Houses[hId][PickupID]);
	}
	
	if(Houses[hId][ExitPickupId])
	{
		DestroyDynamicPickup(Houses[hId][ExitPickupId]);
	}
	
	if(Houses[hId][ExitX] != 0.0 || Houses[hId][ExitY] != 0.0)
	{
		Houses[hId][ExitPickupId] = CreateDynamicPickup(1318, 1, Houses[hId][ExitX], Houses[hId][ExitY], Houses[hId][ExitZ], hId, Houses[hId][ExitInterior]);
	}
	
	if(Houses[hId][EnterX] != 0.0 || Houses[hId][EnterY] != 0.0)
	{
		Houses[hId][PickupID] = CreateDynamicPickup(1273, 1, Houses[hId][EnterX], Houses[hId][EnterY], Houses[hId][EnterZ]);
	
		GetCoords2DZone(Houses[hId][EnterX], Houses[hId][EnterY], houselocation, MAX_ZONE_NAME);
		
		if(!Houses[hId][Owned])
		{
			format(string, sizeof(string), "%s %d", houselocation, Houses[hId][StreetNo]);			
			Houses3DTextLabelA[hId] = CreateDynamic3DTextLabel(string, COLOR_LIGHTYELLOW2, Houses[hId][EnterX], Houses[hId][EnterY], Houses[hId][EnterZ]+1.0, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

			format(string, sizeof(string), "Ten dom jest na sprzedaz! /kupdom");
			Houses3DTextLabelB[hId] = CreateDynamic3DTextLabel(string, COLOR_LIGHTYELLOW2, Houses[hId][EnterX], Houses[hId][EnterY], Houses[hId][EnterZ]+0.5, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

			format(string, sizeof(string), "Cena $%d", Houses[hId][HousePrice]);
			Houses3DTextLabelC[hId] = CreateDynamic3DTextLabel(string, COLOR_LIGHTYELLOW2, Houses[hId][EnterX], Houses[hId][EnterY], Houses[hId][EnterZ], 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
		}
		else
		{
			if(Houses[hId][Rentable])
			{
				if(strcmp(Houses[hId][HRenter], "Brak", true) != 0 && strcmp(Houses[hId][HRenter], "None", true) != 0)
				{
					goto nonRentable;
				}
				else
				{
					format(string, sizeof(string), "%s %d", houselocation, Houses[hId][StreetNo]);
					Houses3DTextLabelA[hId] = CreateDynamic3DTextLabel(string, COLOR_LIGHTYELLOW2, Houses[hId][EnterX], Houses[hId][EnterY], Houses[hId][EnterZ]+1.0, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
					
					format(string, sizeof(string), "Ten dom jest do wynajêcia /wynajmijdom");
					Houses3DTextLabelB[hId] = CreateDynamic3DTextLabel(string, COLOR_LIGHTYELLOW2, Houses[hId][EnterX], Houses[hId][EnterY], Houses[hId][EnterZ]+0.5, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

					format(string, sizeof(string), "Czynsz $%d", Houses[hId][RentCost]);
					Houses3DTextLabelC[hId] = CreateDynamic3DTextLabel(string, COLOR_LIGHTYELLOW2, Houses[hId][EnterX], Houses[hId][EnterY], Houses[hId][EnterZ], 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
				}
			}
			else
			{
				nonRentable:
				
				format(string, sizeof(string), "%s %d", houselocation, Houses[hId][StreetNo]);
				Houses3DTextLabelA[hId] = CreateDynamic3DTextLabel(string, COLOR_LIGHTYELLOW2, Houses[hId][EnterX], Houses[hId][EnterY], Houses[hId][EnterZ]+1.0, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
				
				format(string, sizeof(string), " ");
				Houses3DTextLabelB[hId] = CreateDynamic3DTextLabel(string, COLOR_LIGHTYELLOW2, Houses[hId][EnterX], Houses[hId][EnterY], Houses[hId][EnterZ]+0.5, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

				format(string, sizeof(string), " ");
				Houses3DTextLabelC[hId] = CreateDynamic3DTextLabel(string, COLOR_LIGHTYELLOW2, Houses[hId][EnterX], Houses[hId][EnterY], Houses[hId][EnterZ], 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
			}
		}
	}
}
	
// Thats all folks :-)