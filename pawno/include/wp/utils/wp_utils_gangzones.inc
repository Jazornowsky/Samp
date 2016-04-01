/***
*
* File: wp_utils_gangzones.inc
* Auth: Damian Wojdat
* Date: 24.05.2012
* Desc: Internal script function related to gang zones.
*
*************************************************************************************************************/

IsPlayerInAlliedGangZone(playerid)
{
	for(new i = 0; i < sizeof(DynamicZones); i++)
	{
		if(IsPlayerInArea(playerid, DynamicZones[i][mPosMaxX], DynamicZones[i][mPosMinX], DynamicZones[i][mPosMaxY], DynamicZones[i][mPosMinY])
			&& DynamicZones[i][mFaction] == gPlayerData[playerid][pFaction])
			return 1;
	}
	return 0;
}

VehInZoneStealTimeLeft(vehId)
{
	GetVehiclePos(vehId, gVehData[vehId-1][mVehX], gVehData[vehId-1][mVehY], gVehData[vehId-1][mVehZ]);
	for(new i = 0; i < sizeof(DynamicZones); i++)
	{
		if(IsPointInArea(DynamicZones[i][mPosMinX], DynamicZones[i][mPosMinY], DynamicZones[i][mPosMaxX], DynamicZones[i][mPosMaxY], gVehData[vehId-1][mVehX], gVehData[vehId-1][mVehY]))
			return DynamicZones[i][mVehStealTimeLeft];
	}
	return -1;
}

VehInZoneStealTimeLeftSave(vehId)
{
	GetVehiclePos(vehId, gVehData[vehId-1][mVehX], gVehData[vehId-1][mVehY], gVehData[vehId-1][mVehZ]);
	for(new i = 0; i < sizeof(DynamicZones); i++)
	{
		if(IsPointInArea(DynamicZones[i][mPosMinX], DynamicZones[i][mPosMinY], DynamicZones[i][mPosMaxX], DynamicZones[i][mPosMaxY], gVehData[vehId-1][mVehX], gVehData[vehId-1][mVehY]))
		{	
			DynamicZones[i][mVehStealTimeLeft] = gVehExport[mTimeBeforeNextSteal];
			SaveGangZone(i, "VehStealTimeLeft");
		}
	}
}


VehInZoneBreakTimeLeft(vehId)
{
	GetVehiclePos(vehId, gVehData[vehId-1][mVehX], gVehData[vehId-1][mVehY], gVehData[vehId-1][mVehZ]);
	for(new i = 0; i < sizeof(DynamicZones); i++)
	{
		if(IsPointInArea(DynamicZones[i][mPosMinX], DynamicZones[i][mPosMinY], DynamicZones[i][mPosMaxX], DynamicZones[i][mPosMaxY], gVehData[vehId-1][mVehX], gVehData[vehId-1][mVehY]))
			return DynamicZones[i][mVehBreakTimeLeft];
	}
	return -1;
}

VehInZoneBreakTimeLeftSave(vehId)
{
	GetVehiclePos(vehId, gVehData[vehId-1][mVehX], gVehData[vehId-1][mVehY], gVehData[vehId-1][mVehZ]);
	for(new i = 0; i < sizeof(DynamicZones); i++)
	{
		if(IsPointInArea(DynamicZones[i][mPosMinX], DynamicZones[i][mPosMinY], DynamicZones[i][mPosMaxX], DynamicZones[i][mPosMaxY], gVehData[vehId-1][mVehX], gVehData[vehId-1][mVehY]))
		{	
			DynamicZones[i][mVehBreakTimeLeft] = gVehExport[mTimeBeforeNextSteal];
			SaveGangZone(i, "VehBreakTimeLeft");
		}
	}
}

HouseInAlliedZone(playerid)
{
	for(new i = 0; i < sizeof(DynamicZones); i++)
	{
		if(IsPointInArea(DynamicZones[i][mPosMinX], DynamicZones[i][mPosMinY], DynamicZones[i][mPosMaxX], DynamicZones[i][mPosMaxY], Houses[gPlayerVars[playerid][mAtHouseID]][EnterX], Houses[gPlayerVars[playerid][mAtHouseID]][EnterY])
			&& DynamicZones[i][mFaction] == gPlayerData[playerid][pFaction])
			return 1;
	}
	return 0;
}

HouseInZoneStealTimeLeft(playerid)
{
	for(new i = 0; i < sizeof(DynamicZones); i++)
	{
		if(IsPointInArea(DynamicZones[i][mPosMinX], DynamicZones[i][mPosMinY], DynamicZones[i][mPosMaxX], DynamicZones[i][mPosMaxY], Houses[gPlayerVars[playerid][mAtHouseID]][EnterX], Houses[gPlayerVars[playerid][mAtHouseID]][EnterY]))
			return DynamicZones[i][mHouseStealTimeLeft];
	}
	return -1;
}

HouseInZoneStealTimeLeftSave(playerid)
{
	for(new i = 0; i < sizeof(DynamicZones); i++)
	{
		if(IsPointInArea(DynamicZones[i][mPosMinX], DynamicZones[i][mPosMinY], DynamicZones[i][mPosMaxX], DynamicZones[i][mPosMaxY], Houses[gPlayerVars[playerid][mAtHouseID]][EnterX], Houses[gPlayerVars[playerid][mAtHouseID]][EnterY]))
		{	
			DynamicZones[i][mHouseStealTimeLeft] = HOUSE_BREAK_COOLDOWN;
			SaveGangZone(i, "HouseStealTimeLeft");
		}
	}
	return -1;
}

HouseInZoneBreakTimeLeft(houseId)
{
	for(new i = 0; i < sizeof(DynamicZones); i++)
	{
		if(IsPointInArea(DynamicZones[i][mPosMinX], DynamicZones[i][mPosMinY], DynamicZones[i][mPosMaxX], DynamicZones[i][mPosMaxY], Houses[houseId][EnterX], Houses[houseId][EnterY]))
			return DynamicZones[i][mHouseBreakTimeLeft];
	}
	return -1;
}

HouseInZoneBreakTimeLeftSave(houseId)
{
	for(new i = 0; i < sizeof(DynamicZones); i++)
	{
		if(IsPointInArea(DynamicZones[i][mPosMinX], DynamicZones[i][mPosMinY], DynamicZones[i][mPosMaxX], DynamicZones[i][mPosMaxY], Houses[houseId][EnterX], Houses[houseId][EnterY]))
		{	
			DynamicZones[i][mHouseBreakTimeLeft] = HOUSE_BREAK_COOLDOWN;
			SaveGangZone(i, "HouseBreakTimeLeft");
		}
	}
}

CharInZoneStealTimeLeft(playerid)
{
	GetPlayerPos(playerid, gPlayerData[playerid][pCrashX], gPlayerData[playerid][pCrashY], gPlayerData[playerid][pCrashZ]);
	for(new i = 0; i < sizeof(DynamicZones); i++)
	{
		if(IsPointInArea(DynamicZones[i][mPosMinX], DynamicZones[i][mPosMinY], DynamicZones[i][mPosMaxX], DynamicZones[i][mPosMaxY],  gPlayerData[playerid][pCrashX], gPlayerData[playerid][pCrashY]))
			return DynamicZones[i][mCharStealTimeLeft];
	}
	return -1;
}

CharInZoneStealTimeLeftSave(playerid, value)
{
	GetPlayerPos(playerid, gPlayerData[playerid][pCrashX], gPlayerData[playerid][pCrashY], gPlayerData[playerid][pCrashZ]);
	for(new i = 0; i < sizeof(DynamicZones); i++)
	{
		if(IsPointInArea(DynamicZones[i][mPosMinX], DynamicZones[i][mPosMinY], DynamicZones[i][mPosMaxX], DynamicZones[i][mPosMaxY],  gPlayerData[playerid][pCrashX], gPlayerData[playerid][pCrashY]))
		{
			DynamicZones[i][mCharStealTimeLeft] = value;
			SaveGangZone(i, "CharStealTimeLeft");
		}
	}
}

CharInZoneMoneyStealTimeLeft(playerid)
{
	GetPlayerPos(playerid, gPlayerData[playerid][pCrashX], gPlayerData[playerid][pCrashY], gPlayerData[playerid][pCrashZ]);
	for(new i = 0; i < sizeof(DynamicZones); i++)
	{
		if(IsPointInArea(DynamicZones[i][mPosMinX], DynamicZones[i][mPosMinY], DynamicZones[i][mPosMaxX], DynamicZones[i][mPosMaxY],  gPlayerData[playerid][pCrashX], gPlayerData[playerid][pCrashY]))
			return DynamicZones[i][mCharMoneyStealTimeLeft];
	}
	return -1;
}

CharInZoneCashStealTimeLeftSave(playerid, value)
{
	GetPlayerPos(playerid, gPlayerData[playerid][pCrashX], gPlayerData[playerid][pCrashY], gPlayerData[playerid][pCrashZ]);
	for(new i = 0; i < sizeof(DynamicZones); i++)
	{
		if(IsPointInArea(DynamicZones[i][mPosMinX], DynamicZones[i][mPosMinY], DynamicZones[i][mPosMaxX], DynamicZones[i][mPosMaxY],  gPlayerData[playerid][pCrashX], gPlayerData[playerid][pCrashY]))
		{
			DynamicZones[i][mCharMoneyStealTimeLeft] = value;
			SaveGangZone(i, "CharMoneyStealTimeLeft");
		}
	}
}

BizInAlliedZone(playerid)
{
	for(new i = 0; i < sizeof(DynamicZones); i++)
	{
		if(IsPointInArea(DynamicZones[i][mPosMinX], DynamicZones[i][mPosMinY], DynamicZones[i][mPosMaxX], DynamicZones[i][mPosMaxY], Businesses[gPlayerVars[playerid][mAtBizID]][EnterX], Businesses[gPlayerVars[playerid][mAtBizID]][EnterY])
			&& DynamicZones[i][mFaction] == gPlayerData[playerid][pFaction])
			return 1;
	}
	return 0;
}

BizInZoneStealTimeLeft(playerid)
{
	for(new i = 0; i < sizeof(DynamicZones); i++)
	{
		if(IsPointInArea(DynamicZones[i][mPosMinX], DynamicZones[i][mPosMinY], DynamicZones[i][mPosMaxX], DynamicZones[i][mPosMaxY], Businesses[gPlayerVars[playerid][mAtBizID]][EnterX], Businesses[gPlayerVars[playerid][mAtBizID]][EnterY]))
			return DynamicZones[i][mBizStealTimeLeft];
	}
	return -1;
}

BizInZoneStealTimeLeftSave(playerid)
{
	for(new i = 0; i < sizeof(DynamicZones); i++)
	{
		if(IsPointInArea(DynamicZones[i][mPosMinX], DynamicZones[i][mPosMinY], DynamicZones[i][mPosMaxX], DynamicZones[i][mPosMaxY], Houses[gPlayerVars[playerid][mAtBizID]][EnterX], Houses[gPlayerVars[playerid][mAtBizID]][EnterY]))
		{	
			DynamicZones[i][mBizStealTimeLeft] = BIZ_BREAK_COOLDOWN;
			SaveGangZone(i, "BizStealTimeLeft");
		}
	}
	return -1;
}

BizInZoneBreakTimeLeft(bizId)
{
	for(new i = 0; i < sizeof(DynamicZones); i++)
	{
		if(IsPointInArea(DynamicZones[i][mPosMinX], DynamicZones[i][mPosMinY], DynamicZones[i][mPosMaxX], DynamicZones[i][mPosMaxY], Businesses[bizId][EnterX], Businesses[bizId][EnterY]))
			return DynamicZones[i][mBizBreakTimeLeft];
	}
	return -1;
}

BizInZoneBreakTimeLeftSave(bizId)
{
	for(new i = 0; i < sizeof(DynamicZones); i++)
	{
		if(IsPointInArea(DynamicZones[i][mPosMinX], DynamicZones[i][mPosMinY], DynamicZones[i][mPosMaxX], DynamicZones[i][mPosMaxY], Businesses[bizId][EnterX], Businesses[bizId][EnterY]))
		{	
			DynamicZones[i][mBizBreakTimeLeft] = BIZ_BREAK_COOLDOWN;
			SaveGangZone(i, "BizBreakTimeLeft");
		}
	}
	return -1;
}