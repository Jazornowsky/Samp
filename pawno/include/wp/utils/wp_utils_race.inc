/***
*
* File: wp_utils_race.inc
* Auth: Damian Wojdat
* Date: 30.04.2012
* Desc: Internal script function related to races.
*
*************************************************************************************************************/

stock ResetRaceData(raceId)
{
	gRaceStatus[raceId][mRaceId] = -1;
	gRaceStatus[raceId][mRaceRacersCount] = 0;
	gRaceStatus[raceId][mRaceState] = RACE_STATE_NONE;
	gRaceStatus[raceId][mRaceEntrant1Lap] = 1;
	gRaceStatus[raceId][mRaceEntrant2Lap] = 1;
	gRaceStatus[raceId][mRaceEntrant3Lap] = 1;
	gRaceStatus[raceId][mRaceEntrant4Lap] = 1;
	gRaceStatus[raceId][mRaceEntrant5Lap] = 1;
	gRaceStatus[raceId][mRaceEntrant6Lap] = 1;
	gRaceStatus[raceId][mRaceEntrant7Lap] = 1;
	gRaceStatus[raceId][mRaceEntrant8Lap] = 1;
	gRaceStatus[raceId][mRaceEntrant9Lap] = 1;
	gRaceStatus[raceId][mRaceEntrant10Lap] = 1;
	gRaceStatus[raceId][mRaceEntrant1NextCpId] = 0;
	gRaceStatus[raceId][mRaceEntrant2NextCpId] = 0;
	gRaceStatus[raceId][mRaceEntrant3NextCpId] = 0;
	gRaceStatus[raceId][mRaceEntrant4NextCpId] = 0;
	gRaceStatus[raceId][mRaceEntrant5NextCpId] = 0;
	gRaceStatus[raceId][mRaceEntrant6NextCpId] = 0;
	gRaceStatus[raceId][mRaceEntrant7NextCpId] = 0;
	gRaceStatus[raceId][mRaceEntrant8NextCpId] = 0;
	gRaceStatus[raceId][mRaceEntrant9NextCpId] = 0;
	gRaceStatus[raceId][mRaceEntrant10NextCpId] = 0;
	gRaceStatus[raceId][mRaceEntrant1IsOnStartPos] = 0;
	gRaceStatus[raceId][mRaceEntrant2IsOnStartPos] = 0;
	gRaceStatus[raceId][mRaceEntrant3IsOnStartPos] = 0;
	gRaceStatus[raceId][mRaceEntrant4IsOnStartPos] = 0;
	gRaceStatus[raceId][mRaceEntrant5IsOnStartPos] = 0;
	gRaceStatus[raceId][mRaceEntrant6IsOnStartPos] = 0;
	gRaceStatus[raceId][mRaceEntrant7IsOnStartPos] = 0;
	gRaceStatus[raceId][mRaceEntrant8IsOnStartPos] = 0;
	gRaceStatus[raceId][mRaceEntrant9IsOnStartPos] = 0;
	gRaceStatus[raceId][mRaceEntrant10IsOnStartPos] = 0;
	if(gRaceStatus[raceId][mRaceEntrant1CpId] != -1)
	{
		DestroyDynamicRaceCP(gRaceStatus[raceId][mRaceEntrant1CpId]);
		gRaceStatus[raceId][mRaceEntrant1CpId] = -1;
	}
	if(gRaceStatus[raceId][mRaceEntrant2CpId] != -1)
	{
		DestroyDynamicRaceCP(gRaceStatus[raceId][mRaceEntrant2CpId]);
		gRaceStatus[raceId][mRaceEntrant2CpId] = -1;
	}
	if(gRaceStatus[raceId][mRaceEntrant3CpId] != -1)
	{
		DestroyDynamicRaceCP(gRaceStatus[raceId][mRaceEntrant3CpId]);
		gRaceStatus[raceId][mRaceEntrant3CpId] = -1;
	}
	if(gRaceStatus[raceId][mRaceEntrant4CpId] != -1)
	{
		DestroyDynamicRaceCP(gRaceStatus[raceId][mRaceEntrant4CpId]);
		gRaceStatus[raceId][mRaceEntrant4CpId] = -1;
	}
	if(gRaceStatus[raceId][mRaceEntrant5CpId] != -1)
	{
		DestroyDynamicRaceCP(gRaceStatus[raceId][mRaceEntrant5CpId]);
		gRaceStatus[raceId][mRaceEntrant5CpId] = -1;
	}
	if(gRaceStatus[raceId][mRaceEntrant6CpId] != -1)
	{
		DestroyDynamicRaceCP(gRaceStatus[raceId][mRaceEntrant6CpId]);
		gRaceStatus[raceId][mRaceEntrant6CpId] = -1;
	}
	if(gRaceStatus[raceId][mRaceEntrant7CpId] != -1)
	{
		DestroyDynamicRaceCP(gRaceStatus[raceId][mRaceEntrant7CpId]);
		gRaceStatus[raceId][mRaceEntrant7CpId] = -1;
	}
	if(gRaceStatus[raceId][mRaceEntrant8CpId] != -1)
	{
		DestroyDynamicRaceCP(gRaceStatus[raceId][mRaceEntrant8CpId]);
		gRaceStatus[raceId][mRaceEntrant8CpId] = -1;
	}
	if(gRaceStatus[raceId][mRaceEntrant9CpId] != -1)
	{
		DestroyDynamicRaceCP(gRaceStatus[raceId][mRaceEntrant9CpId]);
		gRaceStatus[raceId][mRaceEntrant9CpId] = -1;
	}
	if(gRaceStatus[raceId][mRaceEntrant10CpId] != -1)
	{
		DestroyDynamicRaceCP(gRaceStatus[raceId][mRaceEntrant10CpId]);
		gRaceStatus[raceId][mRaceEntrant10CpId] = -1;
	}
	if(gRaceStatus[raceId][mRaceEntrant1Id] != -1)
	{
		TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant1Id], gRaceStatus[raceId][mRaceInfo]);
		
		TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant1Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant1Id]][mRacePlace1Info]);
		
		if(gRaceStatus[raceId][mRaceEntrant2Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant2Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant1Id]][mRacePlace1Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant3Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant3Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant1Id]][mRacePlace1Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant4Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant4Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant1Id]][mRacePlace1Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant5Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant5Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant1Id]][mRacePlace1Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant6Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant6Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant1Id]][mRacePlace1Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant7Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant7Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant1Id]][mRacePlace1Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant8Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant8Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant1Id]][mRacePlace1Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant9Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant9Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant1Id]][mRacePlace1Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant10Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant10Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant1Id]][mRacePlace1Info]);
	}
	if(gRaceStatus[raceId][mRaceEntrant2Id] != -1)
	{
		TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant2Id], gRaceStatus[raceId][mRaceInfo]);
		
		TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant2Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant2Id]][mRacePlace2Info]);
		
		if(gRaceStatus[raceId][mRaceEntrant1Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant1Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant2Id]][mRacePlace2Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant3Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant3Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant2Id]][mRacePlace2Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant4Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant4Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant2Id]][mRacePlace2Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant5Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant5Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant2Id]][mRacePlace2Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant6Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant6Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant2Id]][mRacePlace2Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant7Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant7Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant2Id]][mRacePlace2Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant8Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant8Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant2Id]][mRacePlace2Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant9Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant9Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant2Id]][mRacePlace2Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant10Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant10Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant2Id]][mRacePlace2Info]);
	}
	if(gRaceStatus[raceId][mRaceEntrant3Id] != -1)
	{
		TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant3Id], gRaceStatus[raceId][mRaceInfo]);
		
		TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant3Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant3Id]][mRacePlace3Info]);
		
		if(gRaceStatus[raceId][mRaceEntrant1Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant1Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant3Id]][mRacePlace3Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant2Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant2Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant3Id]][mRacePlace3Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant4Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant4Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant3Id]][mRacePlace3Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant5Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant5Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant3Id]][mRacePlace3Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant6Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant6Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant3Id]][mRacePlace3Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant7Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant7Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant3Id]][mRacePlace3Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant8Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant8Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant3Id]][mRacePlace3Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant9Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant9Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant3Id]][mRacePlace3Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant10Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant10Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant3Id]][mRacePlace3Info]);
	}
	if(gRaceStatus[raceId][mRaceEntrant4Id] != -1)
	{
		TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant4Id], gRaceStatus[raceId][mRaceInfo]);
		
		TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant4Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant4Id]][mRacePlace4Info]);
		
		if(gRaceStatus[raceId][mRaceEntrant1Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant1Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant4Id]][mRacePlace4Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant2Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant2Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant4Id]][mRacePlace4Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant3Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant3Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant4Id]][mRacePlace4Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant5Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant5Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant4Id]][mRacePlace4Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant6Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant6Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant4Id]][mRacePlace4Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant7Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant7Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant4Id]][mRacePlace4Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant8Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant8Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant4Id]][mRacePlace4Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant9Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant9Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant4Id]][mRacePlace4Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant10Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant10Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant4Id]][mRacePlace4Info]);
	}
	if(gRaceStatus[raceId][mRaceEntrant5Id] != -1)
	{
		TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant5Id], gRaceStatus[raceId][mRaceInfo]);
		
		TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant5Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant5Id]][mRacePlace5Info]);
		
		if(gRaceStatus[raceId][mRaceEntrant1Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant1Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant5Id]][mRacePlace5Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant2Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant2Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant5Id]][mRacePlace5Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant3Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant3Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant5Id]][mRacePlace5Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant4Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant4Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant5Id]][mRacePlace5Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant6Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant6Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant5Id]][mRacePlace5Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant7Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant7Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant5Id]][mRacePlace5Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant8Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant8Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant5Id]][mRacePlace5Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant9Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant9Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant5Id]][mRacePlace5Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant10Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant10Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant5Id]][mRacePlace5Info]);
	}
	if(gRaceStatus[raceId][mRaceEntrant6Id] != -1)
	{
		TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant6Id], gRaceStatus[raceId][mRaceInfo]);
		
		TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant6Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant6Id]][mRacePlace6Info]);
		
		if(gRaceStatus[raceId][mRaceEntrant1Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant1Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant6Id]][mRacePlace6Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant2Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant2Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant6Id]][mRacePlace6Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant3Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant3Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant6Id]][mRacePlace6Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant4Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant4Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant6Id]][mRacePlace6Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant5Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant5Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant6Id]][mRacePlace6Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant7Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant7Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant6Id]][mRacePlace6Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant8Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant8Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant6Id]][mRacePlace6Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant9Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant9Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant6Id]][mRacePlace6Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant10Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant10Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant6Id]][mRacePlace6Info]);
	}
	if(gRaceStatus[raceId][mRaceEntrant7Id] != -1)
	{
		TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant7Id], gRaceStatus[raceId][mRaceInfo]);
		
		TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant7Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant7Id]][mRacePlace7Info]);
		
		if(gRaceStatus[raceId][mRaceEntrant1Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant1Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant7Id]][mRacePlace7Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant2Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant2Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant7Id]][mRacePlace7Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant3Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant3Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant7Id]][mRacePlace7Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant4Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant4Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant7Id]][mRacePlace7Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant5Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant5Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant7Id]][mRacePlace7Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant6Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant6Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant7Id]][mRacePlace7Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant8Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant8Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant7Id]][mRacePlace7Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant9Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant9Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant7Id]][mRacePlace7Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant10Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant10Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant7Id]][mRacePlace7Info]);
	}
	if(gRaceStatus[raceId][mRaceEntrant8Id] != -1)
	{
		TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant8Id], gRaceStatus[raceId][mRaceInfo]);
		
		TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant8Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant8Id]][mRacePlace8Info]);
		
		if(gRaceStatus[raceId][mRaceEntrant1Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant1Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant8Id]][mRacePlace8Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant2Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant2Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant8Id]][mRacePlace8Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant3Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant3Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant8Id]][mRacePlace8Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant4Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant4Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant8Id]][mRacePlace8Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant5Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant5Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant8Id]][mRacePlace8Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant6Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant6Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant8Id]][mRacePlace8Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant7Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant7Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant8Id]][mRacePlace8Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant9Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant9Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant8Id]][mRacePlace8Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant10Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant10Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant8Id]][mRacePlace8Info]);
	}
	if(gRaceStatus[raceId][mRaceEntrant9Id] != -1)
	{
		TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant9Id], gRaceStatus[raceId][mRaceInfo]);
		
		TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant9Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant9Id]][mRacePlace9Info]);
		
		if(gRaceStatus[raceId][mRaceEntrant1Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant1Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant9Id]][mRacePlace9Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant2Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant2Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant9Id]][mRacePlace9Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant3Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant3Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant9Id]][mRacePlace9Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant4Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant4Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant9Id]][mRacePlace9Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant5Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant5Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant9Id]][mRacePlace9Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant6Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant6Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant9Id]][mRacePlace9Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant7Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant7Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant9Id]][mRacePlace9Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant8Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant8Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant9Id]][mRacePlace9Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant10Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant10Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant9Id]][mRacePlace9Info]);
	}
	if(gRaceStatus[raceId][mRaceEntrant10Id] != -1)
	{
		TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant10Id], gRaceStatus[raceId][mRaceInfo]);
		
		TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant10Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant10Id]][mRacePlace10Info]);
		
		if(gRaceStatus[raceId][mRaceEntrant1Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant1Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant10Id]][mRacePlace10Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant2Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant2Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant10Id]][mRacePlace10Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant3Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant3Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant10Id]][mRacePlace10Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant4Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant4Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant10Id]][mRacePlace10Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant5Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant5Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant10Id]][mRacePlace10Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant6Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant6Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant10Id]][mRacePlace10Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant7Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant7Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant10Id]][mRacePlace10Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant8Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant8Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant10Id]][mRacePlace10Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant9Status] != PLAYER_RACE_STATE_NONE)
			TextDrawHideForPlayer(gRaceStatus[raceId][mRaceEntrant9Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant10Id]][mRacePlace10Info]);
	}
	gRaceStatus[raceId][mRaceEntrant1Id] = -1;
	gRaceStatus[raceId][mRaceEntrant2Id] = -1;
	gRaceStatus[raceId][mRaceEntrant3Id] = -1;
	gRaceStatus[raceId][mRaceEntrant4Id] = -1;
	gRaceStatus[raceId][mRaceEntrant5Id] = -1;
	gRaceStatus[raceId][mRaceEntrant6Id] = -1;
	gRaceStatus[raceId][mRaceEntrant7Id] = -1;
	gRaceStatus[raceId][mRaceEntrant8Id] = -1;
	gRaceStatus[raceId][mRaceEntrant9Id] = -1;
	gRaceStatus[raceId][mRaceEntrant10Id] = -1;
	gRaceStatus[raceId][mRaceEntrant1Status] = PLAYER_RACE_STATE_NONE;
	gRaceStatus[raceId][mRaceEntrant2Status] = PLAYER_RACE_STATE_NONE;
	gRaceStatus[raceId][mRaceEntrant3Status] = PLAYER_RACE_STATE_NONE;
	gRaceStatus[raceId][mRaceEntrant4Status] = PLAYER_RACE_STATE_NONE;
	gRaceStatus[raceId][mRaceEntrant5Status] = PLAYER_RACE_STATE_NONE;
	gRaceStatus[raceId][mRaceEntrant6Status] = PLAYER_RACE_STATE_NONE;
	gRaceStatus[raceId][mRaceEntrant7Status] = PLAYER_RACE_STATE_NONE;
	gRaceStatus[raceId][mRaceEntrant8Status] = PLAYER_RACE_STATE_NONE;
	gRaceStatus[raceId][mRaceEntrant9Status] = PLAYER_RACE_STATE_NONE;
	gRaceStatus[raceId][mRaceEntrant10Status] = PLAYER_RACE_STATE_NONE;
	TextDrawSetString(gRaceStatus[raceId][mRaceInfo], " ");
}

stock JoinPlayerToRace(playerid, raceId)
{
	if(gRaceStatus[raceId][mRaceEntrant1Id] == -1)
	{
		gRaceStatus[raceId][mRaceRacersCount]++;		
		gRaceStatus[raceId][mRaceEntrant1Id] = playerid;
		gRaceStatus[raceId][mRaceEntrant1Status] = PLAYER_RACE_STATE_CONNECTED;
		gRaceStatus[raceId][mRaceEntrant1Place] = 1;
		format(gRaceStatus[raceId][mRaceEntrant1], MAX_PLAYER_NAME, gPlayerData[playerid][pName]);
		TextDrawShowForPlayer(playerid, gRaceStatus[raceId][mRaceInfo]);
		gRaceStatus[raceId][mRaceEntrant1CpId] = CreateDynamicRaceCP(0, gRaceTrackStart1CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart1CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart1CpZ[gRaceStatus[raceId][mRaceId]], 
			gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][0], 2.0, -1, -1, playerid);
		return 1;
	}
	else if(gRaceStatus[raceId][mRaceEntrant2Id] == -1)
	{
		gRaceStatus[raceId][mRaceRacersCount]++;
		gRaceStatus[raceId][mRaceEntrant2Id] = playerid;
		gRaceStatus[raceId][mRaceEntrant2Status] = PLAYER_RACE_STATE_CONNECTED;		
		gRaceStatus[raceId][mRaceEntrant2Place] = 2;
		format(gRaceStatus[raceId][mRaceEntrant2], MAX_PLAYER_NAME, gPlayerData[playerid][pName]);
		TextDrawShowForPlayer(playerid, gRaceStatus[raceId][mRaceInfo]);
		gRaceStatus[raceId][mRaceEntrant2CpId] = CreateDynamicRaceCP(0, gRaceTrackStart2CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart2CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart2CpZ[gRaceStatus[raceId][mRaceId]], 
			gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][0], 2.0, -1, -1, playerid);
		return 1;
	}
	else if(gRaceStatus[raceId][mRaceEntrant3Id] == -1 && gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 3)
	{
		gRaceStatus[raceId][mRaceRacersCount]++;
		gRaceStatus[raceId][mRaceEntrant3Id] = playerid;
		gRaceStatus[raceId][mRaceEntrant3Status] = PLAYER_RACE_STATE_CONNECTED;
		gRaceStatus[raceId][mRaceEntrant3Place] = 3;
		format(gRaceStatus[raceId][mRaceEntrant3], MAX_PLAYER_NAME, gPlayerData[playerid][pName]);
		TextDrawShowForPlayer(playerid, gRaceStatus[raceId][mRaceInfo]);
		gRaceStatus[raceId][mRaceEntrant3CpId] = CreateDynamicRaceCP(0, gRaceTrackStart3CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart3CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart3CpZ[gRaceStatus[raceId][mRaceId]], 
			gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][0], 2.0, -1, -1, playerid);
		return 1;
	}
	else if(gRaceStatus[raceId][mRaceEntrant4Id] == -1 && gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 4)
	{
		gRaceStatus[raceId][mRaceRacersCount]++;		
		gRaceStatus[raceId][mRaceEntrant4Id] = playerid;
		gRaceStatus[raceId][mRaceEntrant4Status] = PLAYER_RACE_STATE_CONNECTED;
		gRaceStatus[raceId][mRaceEntrant4Place] = 4;
		format(gRaceStatus[raceId][mRaceEntrant4], MAX_PLAYER_NAME, gPlayerData[playerid][pName]);
		TextDrawShowForPlayer(playerid, gRaceStatus[raceId][mRaceInfo]);
		gRaceStatus[raceId][mRaceEntrant4CpId] = CreateDynamicRaceCP(0, gRaceTrackStart4CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart4CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart4CpZ[gRaceStatus[raceId][mRaceId]], 
			gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][0], 2.0, -1, -1, playerid);
		return 1;
	}
	else if(gRaceStatus[raceId][mRaceEntrant5Id] == -1 && gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 5)
	{
		gRaceStatus[raceId][mRaceRacersCount]++;		
		gRaceStatus[raceId][mRaceEntrant5Id] = playerid;
		gRaceStatus[raceId][mRaceEntrant5Status] = PLAYER_RACE_STATE_CONNECTED;
		gRaceStatus[raceId][mRaceEntrant5Place] = 5;
		format(gRaceStatus[raceId][mRaceEntrant5], MAX_PLAYER_NAME, gPlayerData[playerid][pName]);
		TextDrawShowForPlayer(playerid, gRaceStatus[raceId][mRaceInfo]);
		gRaceStatus[raceId][mRaceEntrant5CpId] = CreateDynamicRaceCP(0, gRaceTrackStart5CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart5CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart5CpZ[gRaceStatus[raceId][mRaceId]], 
			gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][0], 2.0, -1, -1, playerid);
		return 1;
	}
	else if(gRaceStatus[raceId][mRaceEntrant6Id] == -1 && gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 6)
	{
		gRaceStatus[raceId][mRaceRacersCount]++;		
		gRaceStatus[raceId][mRaceEntrant6Id] = playerid;
		gRaceStatus[raceId][mRaceEntrant6Status] = PLAYER_RACE_STATE_CONNECTED;
		gRaceStatus[raceId][mRaceEntrant6Place] = 6;
		format(gRaceStatus[raceId][mRaceEntrant6], MAX_PLAYER_NAME, gPlayerData[playerid][pName]);
		TextDrawShowForPlayer(playerid, gRaceStatus[raceId][mRaceInfo]);
		gRaceStatus[raceId][mRaceEntrant6CpId] = CreateDynamicRaceCP(0, gRaceTrackStart6CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart6CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart6CpZ[gRaceStatus[raceId][mRaceId]], 
			gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][0], 2.0, -1, -1, playerid);
		return 1;
	}
	else if(gRaceStatus[raceId][mRaceEntrant7Id] == -1 && gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 7)
	{
		gRaceStatus[raceId][mRaceRacersCount]++;		
		gRaceStatus[raceId][mRaceEntrant7Id] = playerid;
		gRaceStatus[raceId][mRaceEntrant7Status] = PLAYER_RACE_STATE_CONNECTED;
		gRaceStatus[raceId][mRaceEntrant7Place] = 7;
		format(gRaceStatus[raceId][mRaceEntrant7], MAX_PLAYER_NAME, gPlayerData[playerid][pName]);
		TextDrawShowForPlayer(playerid, gRaceStatus[raceId][mRaceInfo]);
		gRaceStatus[raceId][mRaceEntrant7CpId] = CreateDynamicRaceCP(0, gRaceTrackStart7CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart7CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart7CpZ[gRaceStatus[raceId][mRaceId]], 
			gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][0], 2.0, -1, -1, playerid);
		return 1;
	}
	else if(gRaceStatus[raceId][mRaceEntrant8Id] == -1 && gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 8)
	{
		gRaceStatus[raceId][mRaceRacersCount]++;		
		gRaceStatus[raceId][mRaceEntrant8Id] = playerid;
		gRaceStatus[raceId][mRaceEntrant8Status] = PLAYER_RACE_STATE_CONNECTED;
		gRaceStatus[raceId][mRaceEntrant8Place] = 8;
		format(gRaceStatus[raceId][mRaceEntrant8], MAX_PLAYER_NAME, gPlayerData[playerid][pName]);
		TextDrawShowForPlayer(playerid, gRaceStatus[raceId][mRaceInfo]);
		gRaceStatus[raceId][mRaceEntrant8CpId] = CreateDynamicRaceCP(0, gRaceTrackStart8CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart8CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart8CpZ[gRaceStatus[raceId][mRaceId]], 
			gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][0], 2.0, -1, -1, playerid);
		return 1;
	}
	else if(gRaceStatus[raceId][mRaceEntrant9Id] == -1 && gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 9)
	{
		gRaceStatus[raceId][mRaceRacersCount]++;
		gRaceStatus[raceId][mRaceEntrant9Id] = playerid;
		gRaceStatus[raceId][mRaceEntrant9Status] = PLAYER_RACE_STATE_CONNECTED;		
		gRaceStatus[raceId][mRaceEntrant9Place] = 9;
		format(gRaceStatus[raceId][mRaceEntrant9], MAX_PLAYER_NAME, gPlayerData[playerid][pName]);
		TextDrawShowForPlayer(playerid, gRaceStatus[raceId][mRaceInfo]);
		gRaceStatus[raceId][mRaceEntrant9CpId] = CreateDynamicRaceCP(0, gRaceTrackStart9CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart9CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart9CpZ[gRaceStatus[raceId][mRaceId]], 
			gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][0], 2.0, -1, -1, playerid);
		return 1;
	}
	else if(gRaceStatus[raceId][mRaceEntrant10Id] == -1 && gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 10)
	{
		gRaceStatus[raceId][mRaceRacersCount]++;
		gRaceStatus[raceId][mRaceEntrant10Id] = playerid;
		gRaceStatus[raceId][mRaceEntrant10Status] = PLAYER_RACE_STATE_CONNECTED;		
		gRaceStatus[raceId][mRaceEntrant10Place] = 10;
		format(gRaceStatus[raceId][mRaceEntrant10], MAX_PLAYER_NAME, gPlayerData[playerid][pName]);
		TextDrawShowForPlayer(playerid, gRaceStatus[raceId][mRaceInfo]);
		gRaceStatus[raceId][mRaceEntrant10CpId] = CreateDynamicRaceCP(0, gRaceTrackStart10CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart10CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart10CpZ[gRaceStatus[raceId][mRaceId]], 
			gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][0], 2.0, -1, -1, playerid);
		return 1;
	}
	return 0;
}

stock RemovePlayerFromRace(playerid)
{
	for(new i = 0; i < MAX_RACES; i++)
	{
		if(gRaceStatus[i][mRaceState] != RACE_STATE_NONE)
		{
			if(gRaceStatus[i][mRaceEntrant1Id] == playerid)
			{
				DestroyDynamicRaceCP(gRaceStatus[i][mRaceEntrant1CpId]);				
				TextDrawHideForPlayer(gRaceStatus[i][mRaceEntrant1Id], gRaceStatus[i][mRaceInfo]);	
				TextDrawHideForPlayer(gRaceStatus[i][mRaceEntrant1Id], gPlayerVars[gRaceStatus[i][mRaceEntrant1Id]][mRacePlace1Info]);
				
				if(gRaceStatus[i][mRaceEntrant2Status] == PLAYER_RACE_STATE_CONNECTED)
					TextDrawHideForPlayer(gRaceStatus[i][mRaceEntrant2Id], gPlayerVars[gRaceStatus[i][mRaceEntrant1Id]][mRacePlace1Info]);
					
				if(gRaceStatus[i][mRaceEntrant3Status] == PLAYER_RACE_STATE_CONNECTED)
					TextDrawHideForPlayer(gRaceStatus[i][mRaceEntrant3Id], gPlayerVars[gRaceStatus[i][mRaceEntrant1Id]][mRacePlace1Info]);
					
				if(gRaceStatus[i][mRaceEntrant4Status] == PLAYER_RACE_STATE_CONNECTED)
					TextDrawHideForPlayer(gRaceStatus[i][mRaceEntrant4Id], gPlayerVars[gRaceStatus[i][mRaceEntrant1Id]][mRacePlace1Info]);
					
				if(gRaceStatus[i][mRaceEntrant5Status] == PLAYER_RACE_STATE_CONNECTED)
					TextDrawHideForPlayer(gRaceStatus[i][mRaceEntrant5Id], gPlayerVars[gRaceStatus[i][mRaceEntrant1Id]][mRacePlace1Info]);
					
				if(gRaceStatus[i][mRaceEntrant6Status] == PLAYER_RACE_STATE_CONNECTED)
					TextDrawHideForPlayer(gRaceStatus[i][mRaceEntrant6Id], gPlayerVars[gRaceStatus[i][mRaceEntrant1Id]][mRacePlace1Info]);
					
				if(gRaceStatus[i][mRaceEntrant7Status] == PLAYER_RACE_STATE_CONNECTED)
					TextDrawHideForPlayer(gRaceStatus[i][mRaceEntrant7Id], gPlayerVars[gRaceStatus[i][mRaceEntrant1Id]][mRacePlace1Info]);
					
				if(gRaceStatus[i][mRaceEntrant8Status] == PLAYER_RACE_STATE_CONNECTED)
					TextDrawHideForPlayer(gRaceStatus[i][mRaceEntrant8Id], gPlayerVars[gRaceStatus[i][mRaceEntrant1Id]][mRacePlace1Info]);
					
				if(gRaceStatus[i][mRaceEntrant9Status] == PLAYER_RACE_STATE_CONNECTED)
					TextDrawHideForPlayer(gRaceStatus[i][mRaceEntrant9Id], gPlayerVars[gRaceStatus[i][mRaceEntrant1Id]][mRacePlace1Info]);
					
				if(gRaceStatus[i][mRaceEntrant10Status] == PLAYER_RACE_STATE_CONNECTED)
					TextDrawHideForPlayer(gRaceStatus[i][mRaceEntrant10Id], gPlayerVars[gRaceStatus[i][mRaceEntrant1Id]][mRacePlace1Info]);
			
				gRaceStatus[i][mRaceEntrant1CpId] = 0;
				
				if(gRaceStatus[i][mRaceState] == RACE_STATE_JOINING)
				{
					gRaceStatus[i][mRaceEntrant1Status] = PLAYER_RACE_STATE_NONE;
					gRaceStatus[i][mRaceEntrant1Id] = -1;
					format(gRaceStatus[i][mRaceEntrant1], MAX_PLAYER_NAME, "Puste");
					gRaceStatus[i][mRaceRacersCount]--;
					
				}
				else if(gRaceStatus[i][mRaceState] == RACE_STATE_RACE || gRaceStatus[i][mRaceState] == RACE_STATE_COUNTDOWN)
					gRaceStatus[i][mRaceEntrant1Status] = PLAYER_RACE_STATE_LEFT;
				
				return 1;
			}
			if(gRaceStatus[i][mRaceEntrant2Id] == playerid)
			{
				if(gRaceStatus[i][mRaceState] == RACE_STATE_JOINING)
				{
					gRaceStatus[i][mRaceEntrant2Status] = PLAYER_RACE_STATE_NONE;
					gRaceStatus[i][mRaceEntrant2Id] = -1;
					format(gRaceStatus[i][mRaceEntrant2], MAX_PLAYER_NAME, "Puste");
					gRaceStatus[i][mRaceRacersCount]--;
				}
				else if(gRaceStatus[i][mRaceState] == RACE_STATE_RACE || gRaceStatus[i][mRaceState] == RACE_STATE_COUNTDOWN)
					gRaceStatus[i][mRaceEntrant2Status] = PLAYER_RACE_STATE_LEFT;
				if(gRaceStatus[i][mRaceEntrant2CpId])
				{
					DestroyDynamicRaceCP(gRaceStatus[i][mRaceEntrant2CpId]);
					
					TextDrawHideForPlayer(gRaceStatus[i][mRaceEntrant2Id], gRaceStatus[i][mRaceInfo]);
		
					TextDrawHideForPlayer(gRaceStatus[i][mRaceEntrant2Id], gPlayerVars[gRaceStatus[i][mRaceEntrant2Id]][mRacePlace2Info]);
					
					if(gRaceStatus[i][mRaceEntrant1Status] == PLAYER_RACE_STATE_CONNECTED)
						TextDrawHideForPlayer(gRaceStatus[i][mRaceEntrant1Id], gPlayerVars[gRaceStatus[i][mRaceEntrant2Id]][mRacePlace2Info]);
						
					if(gRaceStatus[i][mRaceEntrant3Status] == PLAYER_RACE_STATE_CONNECTED)
						TextDrawHideForPlayer(gRaceStatus[i][mRaceEntrant3Id], gPlayerVars[gRaceStatus[i][mRaceEntrant2Id]][mRacePlace2Info]);
						
					if(gRaceStatus[i][mRaceEntrant4Status] == PLAYER_RACE_STATE_CONNECTED)
						TextDrawHideForPlayer(gRaceStatus[i][mRaceEntrant4Id], gPlayerVars[gRaceStatus[i][mRaceEntrant2Id]][mRacePlace2Info]);
						
					if(gRaceStatus[i][mRaceEntrant5Status] == PLAYER_RACE_STATE_CONNECTED)
						TextDrawHideForPlayer(gRaceStatus[i][mRaceEntrant5Id], gPlayerVars[gRaceStatus[i][mRaceEntrant2Id]][mRacePlace2Info]);
						
					if(gRaceStatus[i][mRaceEntrant6Status] == PLAYER_RACE_STATE_CONNECTED)
						TextDrawHideForPlayer(gRaceStatus[i][mRaceEntrant6Id], gPlayerVars[gRaceStatus[i][mRaceEntrant2Id]][mRacePlace2Info]);
						
					if(gRaceStatus[i][mRaceEntrant7Status] == PLAYER_RACE_STATE_CONNECTED)
						TextDrawHideForPlayer(gRaceStatus[i][mRaceEntrant7Id], gPlayerVars[gRaceStatus[i][mRaceEntrant2Id]][mRacePlace2Info]);
						
					if(gRaceStatus[i][mRaceEntrant8Status] == PLAYER_RACE_STATE_CONNECTED)
						TextDrawHideForPlayer(gRaceStatus[i][mRaceEntrant8Id], gPlayerVars[gRaceStatus[i][mRaceEntrant2Id]][mRacePlace2Info]);
						
					if(gRaceStatus[i][mRaceEntrant9Status] == PLAYER_RACE_STATE_CONNECTED)
						TextDrawHideForPlayer(gRaceStatus[i][mRaceEntrant9Id], gPlayerVars[gRaceStatus[i][mRaceEntrant2Id]][mRacePlace2Info]);
						
					if(gRaceStatus[i][mRaceEntrant10Status] == PLAYER_RACE_STATE_CONNECTED)
						TextDrawHideForPlayer(gRaceStatus[i][mRaceEntrant10Id], gPlayerVars[gRaceStatus[i][mRaceEntrant2Id]][mRacePlace2Info]);
					
					gRaceStatus[i][mRaceEntrant2CpId] = 0;
				}
				TextDrawHideForPlayer(playerid, gRaceStatus[i][mRaceInfo]);
				return 1;
			}
			if(gRaceStatus[i][mRaceEntrant3Id] == playerid)
			{
				if(gRaceStatus[i][mRaceState] == RACE_STATE_JOINING)
				{
					gRaceStatus[i][mRaceEntrant3Status] = PLAYER_RACE_STATE_NONE;
					gRaceStatus[i][mRaceEntrant3Id] = -1;
					format(gRaceStatus[i][mRaceEntrant3], MAX_PLAYER_NAME, "Puste");
					gRaceStatus[i][mRaceRacersCount]--;
				}
				else if(gRaceStatus[i][mRaceState] == RACE_STATE_RACE || gRaceStatus[i][mRaceState] == RACE_STATE_COUNTDOWN)
					gRaceStatus[i][mRaceEntrant3Status] = PLAYER_RACE_STATE_LEFT;
				if(gRaceStatus[i][mRaceEntrant3CpId])
				{
					DestroyDynamicRaceCP(gRaceStatus[i][mRaceEntrant3CpId]);
					gRaceStatus[i][mRaceEntrant3CpId] = 0;
				}
				TextDrawHideForPlayer(playerid, gRaceStatus[i][mRaceInfo]);
				return 1;
			}
			if(gRaceStatus[i][mRaceEntrant4Id] == playerid)
			{
				if(gRaceStatus[i][mRaceState] == RACE_STATE_JOINING)
				{
					gRaceStatus[i][mRaceEntrant4Status] = PLAYER_RACE_STATE_NONE;
					gRaceStatus[i][mRaceEntrant4Id] = -1;
					format(gRaceStatus[i][mRaceEntrant4], MAX_PLAYER_NAME, "Puste");
					gRaceStatus[i][mRaceRacersCount]--;
				}
				else if(gRaceStatus[i][mRaceState] == RACE_STATE_RACE || gRaceStatus[i][mRaceState] == RACE_STATE_COUNTDOWN)
					gRaceStatus[i][mRaceEntrant4Status] = PLAYER_RACE_STATE_LEFT;
				if(gRaceStatus[i][mRaceEntrant4CpId])
				{
					DestroyDynamicRaceCP(gRaceStatus[i][mRaceEntrant4CpId]);
					gRaceStatus[i][mRaceEntrant4CpId] = 0;
				}
				TextDrawHideForPlayer(playerid, gRaceStatus[i][mRaceInfo]);
				return 1;
			}
			if(gRaceStatus[i][mRaceEntrant5Id] == playerid)
			{
				if(gRaceStatus[i][mRaceState] == RACE_STATE_JOINING)
				{
					gRaceStatus[i][mRaceEntrant5Status] = PLAYER_RACE_STATE_NONE;
					gRaceStatus[i][mRaceEntrant5Id] = -1;
					format(gRaceStatus[i][mRaceEntrant5], MAX_PLAYER_NAME, "Puste");
					gRaceStatus[i][mRaceRacersCount]--;
				}
				else if(gRaceStatus[i][mRaceState] == RACE_STATE_RACE || gRaceStatus[i][mRaceState] == RACE_STATE_COUNTDOWN)
					gRaceStatus[i][mRaceEntrant5Status] = PLAYER_RACE_STATE_LEFT;
				if(gRaceStatus[i][mRaceEntrant5CpId])
				{
					DestroyDynamicRaceCP(gRaceStatus[i][mRaceEntrant5CpId]);
					gRaceStatus[i][mRaceEntrant5CpId] = 0;
				}
				TextDrawHideForPlayer(playerid, gRaceStatus[i][mRaceInfo]);
				return 1;
			}
			if(gRaceStatus[i][mRaceEntrant6Id] == playerid)
			{
				if(gRaceStatus[i][mRaceState] == RACE_STATE_JOINING)
				{
					gRaceStatus[i][mRaceEntrant6Status] = PLAYER_RACE_STATE_NONE;
					gRaceStatus[i][mRaceEntrant6Id] = -1;
					format(gRaceStatus[i][mRaceEntrant6], MAX_PLAYER_NAME, "Puste");
					gRaceStatus[i][mRaceRacersCount]--;
				}
				else if(gRaceStatus[i][mRaceState] == RACE_STATE_RACE || gRaceStatus[i][mRaceState] == RACE_STATE_COUNTDOWN)
					gRaceStatus[i][mRaceEntrant6Status] = PLAYER_RACE_STATE_LEFT;
				if(gRaceStatus[i][mRaceEntrant6CpId])
				{
					DestroyDynamicRaceCP(gRaceStatus[i][mRaceEntrant6CpId]);
					gRaceStatus[i][mRaceEntrant6CpId] = 0;
				}
				TextDrawHideForPlayer(playerid, gRaceStatus[i][mRaceInfo]);
				return 1;
			}
			if(gRaceStatus[i][mRaceEntrant7Id] == playerid)
			{
				if(gRaceStatus[i][mRaceState] == RACE_STATE_JOINING)
				{
					gRaceStatus[i][mRaceEntrant7Status] = PLAYER_RACE_STATE_NONE;
					gRaceStatus[i][mRaceEntrant7Id] = -1;
					format(gRaceStatus[i][mRaceEntrant7], MAX_PLAYER_NAME, "Puste");
					gRaceStatus[i][mRaceRacersCount]--;
				}
				else if(gRaceStatus[i][mRaceState] == RACE_STATE_RACE || gRaceStatus[i][mRaceState] == RACE_STATE_COUNTDOWN)
					gRaceStatus[i][mRaceEntrant7Status] = PLAYER_RACE_STATE_LEFT;
				if(gRaceStatus[i][mRaceEntrant7CpId])
				{
					DestroyDynamicRaceCP(gRaceStatus[i][mRaceEntrant7CpId]);
					gRaceStatus[i][mRaceEntrant7CpId] = 0;
				}
				TextDrawHideForPlayer(playerid, gRaceStatus[i][mRaceInfo]);
				return 1;
			}
			if(gRaceStatus[i][mRaceEntrant8Id] == playerid)
			{
				if(gRaceStatus[i][mRaceState] == RACE_STATE_JOINING)
				{
					gRaceStatus[i][mRaceEntrant8Status] = PLAYER_RACE_STATE_NONE;
					gRaceStatus[i][mRaceEntrant8Id] = -1;
					format(gRaceStatus[i][mRaceEntrant8], MAX_PLAYER_NAME, "Puste");
					gRaceStatus[i][mRaceRacersCount]--;
				}
				else if(gRaceStatus[i][mRaceState] == RACE_STATE_RACE || gRaceStatus[i][mRaceState] == RACE_STATE_COUNTDOWN)
					gRaceStatus[i][mRaceEntrant8Status] = PLAYER_RACE_STATE_LEFT;
				if(gRaceStatus[i][mRaceEntrant8CpId])
				{
					DestroyDynamicRaceCP(gRaceStatus[i][mRaceEntrant8CpId]);
					gRaceStatus[i][mRaceEntrant8CpId] = 0;
				}
				TextDrawHideForPlayer(playerid, gRaceStatus[i][mRaceInfo]);				
				return 1;
			}
			if(gRaceStatus[i][mRaceEntrant9Id] == playerid)
			{
				if(gRaceStatus[i][mRaceState] == RACE_STATE_JOINING)
				{
					gRaceStatus[i][mRaceEntrant9Status] = PLAYER_RACE_STATE_NONE;
					gRaceStatus[i][mRaceEntrant9Id] = -1;
					format(gRaceStatus[i][mRaceEntrant9], MAX_PLAYER_NAME, "Puste");
					gRaceStatus[i][mRaceRacersCount]--;
				}
				else if(gRaceStatus[i][mRaceState] == RACE_STATE_RACE || gRaceStatus[i][mRaceState] == RACE_STATE_COUNTDOWN)
					gRaceStatus[i][mRaceEntrant9Status] = PLAYER_RACE_STATE_LEFT;
				if(gRaceStatus[i][mRaceEntrant9CpId])
				{
					DestroyDynamicRaceCP(gRaceStatus[i][mRaceEntrant9CpId]);
					gRaceStatus[i][mRaceEntrant9CpId] = 0;
				}
				TextDrawHideForPlayer(playerid, gRaceStatus[i][mRaceInfo]);
				return 1;
			}
			if(gRaceStatus[i][mRaceEntrant10Id] == playerid)
			{
				if(gRaceStatus[i][mRaceState] == RACE_STATE_JOINING)
				{
					gRaceStatus[i][mRaceEntrant10Status] = PLAYER_RACE_STATE_NONE;
					gRaceStatus[i][mRaceEntrant10Id] = -1;
					format(gRaceStatus[i][mRaceEntrant10], MAX_PLAYER_NAME, "Puste");
					gRaceStatus[i][mRaceRacersCount]--;
				}
				else if(gRaceStatus[i][mRaceState] == RACE_STATE_RACE || gRaceStatus[i][mRaceState] == RACE_STATE_COUNTDOWN)
					gRaceStatus[i][mRaceEntrant10Status] = PLAYER_RACE_STATE_LEFT;
				if(gRaceStatus[i][mRaceEntrant10CpId])
				{
					DestroyDynamicRaceCP(gRaceStatus[i][mRaceEntrant10CpId]);
					gRaceStatus[i][mRaceEntrant10CpId] = 0;
				}
				TextDrawHideForPlayer(playerid, gRaceStatus[i][mRaceInfo]);
				return 1;
			}
		}
	}
	return 0;
}

stock CheckRacersStartPos(raceId)
{
	if(gRaceStatus[raceId][mRaceEntrant1Status] == PLAYER_RACE_STATE_CONNECTED)
	{
		if(!IsPlayerInAnyVehicle(gRaceStatus[raceId][mRaceEntrant1Id]) || !gRaceStatus[raceId][mRaceEntrant1IsOnStartPos])
		{
			SendClientMessage(gRaceStatus[raceId][mRaceEntrant1Id], COLOR_ORANGE, "[INFO:] Zosta³eœ wyrzucony z wyœcigu");
			RemovePlayerFromRace(gRaceStatus[raceId][mRaceEntrant1Id]);
		}
	}
	if(gRaceStatus[raceId][mRaceEntrant2Status] == PLAYER_RACE_STATE_CONNECTED)
	{
		if(!IsPlayerInAnyVehicle(gRaceStatus[raceId][mRaceEntrant2Id]) || !gRaceStatus[raceId][mRaceEntrant2IsOnStartPos])
		{
			SendClientMessage(gRaceStatus[raceId][mRaceEntrant2Id], COLOR_ORANGE, "[INFO:] Zosta³eœ wyrzucony z wyœcigu");
			RemovePlayerFromRace(gRaceStatus[raceId][mRaceEntrant2Id]);
		}
	}
	if(gRaceStatus[raceId][mRaceEntrant3Status] == PLAYER_RACE_STATE_CONNECTED)
	{
		if(!IsPlayerInAnyVehicle(gRaceStatus[raceId][mRaceEntrant3Id]) || !gRaceStatus[raceId][mRaceEntrant3IsOnStartPos])
		{
			SendClientMessage(gRaceStatus[raceId][mRaceEntrant3Id], COLOR_ORANGE, "[INFO:] Zosta³eœ wyrzucony z wyœcigu");
			RemovePlayerFromRace(gRaceStatus[raceId][mRaceEntrant3Id]);
		}
	}
	if(gRaceStatus[raceId][mRaceEntrant4Status] == PLAYER_RACE_STATE_CONNECTED)
	{
		if(!IsPlayerInAnyVehicle(gRaceStatus[raceId][mRaceEntrant4Id]) || !gRaceStatus[raceId][mRaceEntrant4IsOnStartPos])
		{
			SendClientMessage(gRaceStatus[raceId][mRaceEntrant4Id], COLOR_ORANGE, "[INFO:] Zosta³eœ wyrzucony z wyœcigu");
			RemovePlayerFromRace(gRaceStatus[raceId][mRaceEntrant4Id]);
		}
	}
	if(gRaceStatus[raceId][mRaceEntrant5Status] == PLAYER_RACE_STATE_CONNECTED)
	{
		if(!IsPlayerInAnyVehicle(gRaceStatus[raceId][mRaceEntrant5Id]) || !gRaceStatus[raceId][mRaceEntrant5IsOnStartPos])
		{
			SendClientMessage(gRaceStatus[raceId][mRaceEntrant5Id], COLOR_ORANGE, "[INFO:] Zosta³eœ wyrzucony z wyœcigu");
			RemovePlayerFromRace(gRaceStatus[raceId][mRaceEntrant5Id]);
		}
	}
	if(gRaceStatus[raceId][mRaceEntrant6Status] == PLAYER_RACE_STATE_CONNECTED)
	{
		if(!IsPlayerInAnyVehicle(gRaceStatus[raceId][mRaceEntrant6Id]) || !gRaceStatus[raceId][mRaceEntrant6IsOnStartPos])
		{
			SendClientMessage(gRaceStatus[raceId][mRaceEntrant6Id], COLOR_ORANGE, "[INFO:] Zosta³eœ wyrzucony z wyœcigu");
			RemovePlayerFromRace(gRaceStatus[raceId][mRaceEntrant6Id]);
		}
	}
	if(gRaceStatus[raceId][mRaceEntrant7Status] == PLAYER_RACE_STATE_CONNECTED)
	{
		if(!IsPlayerInAnyVehicle(gRaceStatus[raceId][mRaceEntrant7Id]) || !gRaceStatus[raceId][mRaceEntrant7IsOnStartPos])
		{
			SendClientMessage(gRaceStatus[raceId][mRaceEntrant7Id], COLOR_ORANGE, "[INFO:] Zosta³eœ wyrzucony z wyœcigu");
			RemovePlayerFromRace(gRaceStatus[raceId][mRaceEntrant7Id]);
		}
	}
	if(gRaceStatus[raceId][mRaceEntrant8Status] == PLAYER_RACE_STATE_CONNECTED)
	{
		if(!IsPlayerInAnyVehicle(gRaceStatus[raceId][mRaceEntrant8Id]) || !gRaceStatus[raceId][mRaceEntrant8IsOnStartPos])
		{
			SendClientMessage(gRaceStatus[raceId][mRaceEntrant8Id], COLOR_ORANGE, "[INFO:] Zosta³eœ wyrzucony z wyœcigu");
			RemovePlayerFromRace(gRaceStatus[raceId][mRaceEntrant8Id]);
		}
	}
	if(gRaceStatus[raceId][mRaceEntrant9Status] == PLAYER_RACE_STATE_CONNECTED)
	{
		if(!IsPlayerInAnyVehicle(gRaceStatus[raceId][mRaceEntrant9Id]) || !gRaceStatus[raceId][mRaceEntrant9IsOnStartPos])
		{
			SendClientMessage(gRaceStatus[raceId][mRaceEntrant9Id], COLOR_ORANGE, "[INFO:] Zosta³eœ wyrzucony z wyœcigu");
			RemovePlayerFromRace(gRaceStatus[raceId][mRaceEntrant9Id]);
		}
	}
	if(gRaceStatus[raceId][mRaceEntrant10Status] == PLAYER_RACE_STATE_CONNECTED)
	{
		if(!IsPlayerInAnyVehicle(gRaceStatus[raceId][mRaceEntrant10Id]) || !gRaceStatus[raceId][mRaceEntrant10IsOnStartPos])
		{
			SendClientMessage(gRaceStatus[raceId][mRaceEntrant10Id], COLOR_ORANGE, "[INFO:] Zosta³eœ wyrzucony z wyœcigu");
			RemovePlayerFromRace(gRaceStatus[raceId][mRaceEntrant10Id]);
		}
	}
}

stock CheckRacersVehicles(raceId)
{
	if(gRaceStatus[raceId][mRaceEntrant1Status] == PLAYER_RACE_STATE_CONNECTED)
	{
		if(!IsPlayerInAnyVehicle(gRaceStatus[raceId][mRaceEntrant1Id]))
		{
			SendClientMessage(gRaceStatus[raceId][mRaceEntrant1Id], COLOR_ORANGE, "[INFO:] Zosta³eœ wyrzucony z wyœcigu");
			RemovePlayerFromRace(gRaceStatus[raceId][mRaceEntrant1Id]);
		}
	}
	if(gRaceStatus[raceId][mRaceEntrant2Status] == PLAYER_RACE_STATE_CONNECTED)
	{
		if(!IsPlayerInAnyVehicle(gRaceStatus[raceId][mRaceEntrant2Id]))
		{
			SendClientMessage(gRaceStatus[raceId][mRaceEntrant2Id], COLOR_ORANGE, "[INFO:] Zosta³eœ wyrzucony z wyœcigu");
			RemovePlayerFromRace(gRaceStatus[raceId][mRaceEntrant2Id]);
		}
	}
	if(gRaceStatus[raceId][mRaceEntrant3Status] == PLAYER_RACE_STATE_CONNECTED)
	{
		if(!IsPlayerInAnyVehicle(gRaceStatus[raceId][mRaceEntrant3Id]))
		{
			SendClientMessage(gRaceStatus[raceId][mRaceEntrant3Id], COLOR_ORANGE, "[INFO:] Zosta³eœ wyrzucony z wyœcigu");
			RemovePlayerFromRace(gRaceStatus[raceId][mRaceEntrant3Id]);
		}
	}
	if(gRaceStatus[raceId][mRaceEntrant4Status] == PLAYER_RACE_STATE_CONNECTED)
	{
		if(!IsPlayerInAnyVehicle(gRaceStatus[raceId][mRaceEntrant4Id]))
		{
			SendClientMessage(gRaceStatus[raceId][mRaceEntrant4Id], COLOR_ORANGE, "[INFO:] Zosta³eœ wyrzucony z wyœcigu");
			RemovePlayerFromRace(gRaceStatus[raceId][mRaceEntrant4Id]);
		}
	}
	if(gRaceStatus[raceId][mRaceEntrant5Status] == PLAYER_RACE_STATE_CONNECTED)
	{
		if(!IsPlayerInAnyVehicle(gRaceStatus[raceId][mRaceEntrant5Id]))
		{
			SendClientMessage(gRaceStatus[raceId][mRaceEntrant5Id], COLOR_ORANGE, "[INFO:] Zosta³eœ wyrzucony z wyœcigu");
			RemovePlayerFromRace(gRaceStatus[raceId][mRaceEntrant5Id]);
		}
	}
	if(gRaceStatus[raceId][mRaceEntrant6Status] == PLAYER_RACE_STATE_CONNECTED)
	{
		if(!IsPlayerInAnyVehicle(gRaceStatus[raceId][mRaceEntrant6Id]))
		{
			SendClientMessage(gRaceStatus[raceId][mRaceEntrant6Id], COLOR_ORANGE, "[INFO:] Zosta³eœ wyrzucony z wyœcigu");
			RemovePlayerFromRace(gRaceStatus[raceId][mRaceEntrant6Id]);
		}
	}
	if(gRaceStatus[raceId][mRaceEntrant7Status] == PLAYER_RACE_STATE_CONNECTED)
	{
		if(!IsPlayerInAnyVehicle(gRaceStatus[raceId][mRaceEntrant7Id]))
		{
			SendClientMessage(gRaceStatus[raceId][mRaceEntrant7Id], COLOR_ORANGE, "[INFO:] Zosta³eœ wyrzucony z wyœcigu");
			RemovePlayerFromRace(gRaceStatus[raceId][mRaceEntrant7Id]);
		}
	}
	if(gRaceStatus[raceId][mRaceEntrant8Status] == PLAYER_RACE_STATE_CONNECTED)
	{
		if(!IsPlayerInAnyVehicle(gRaceStatus[raceId][mRaceEntrant8Id]))
		{
			SendClientMessage(gRaceStatus[raceId][mRaceEntrant8Id], COLOR_ORANGE, "[INFO:] Zosta³eœ wyrzucony z wyœcigu");
			RemovePlayerFromRace(gRaceStatus[raceId][mRaceEntrant8Id]);
		}
	}
	if(gRaceStatus[raceId][mRaceEntrant9Status] == PLAYER_RACE_STATE_CONNECTED)
	{
		if(!IsPlayerInAnyVehicle(gRaceStatus[raceId][mRaceEntrant9Id]))
		{
			SendClientMessage(gRaceStatus[raceId][mRaceEntrant9Id], COLOR_ORANGE, "[INFO:] Zosta³eœ wyrzucony z wyœcigu");
			RemovePlayerFromRace(gRaceStatus[raceId][mRaceEntrant9Id]);
		}
	}
	if(gRaceStatus[raceId][mRaceEntrant10Status] == PLAYER_RACE_STATE_CONNECTED)
	{
		if(!IsPlayerInAnyVehicle(gRaceStatus[raceId][mRaceEntrant10Id]))
		{
			SendClientMessage(gRaceStatus[raceId][mRaceEntrant10Id], COLOR_ORANGE, "[INFO:] Zosta³eœ wyrzucony z wyœcigu");
			RemovePlayerFromRace(gRaceStatus[raceId][mRaceEntrant10Id]);
		}
	}
}

stock ResetRaceStandings(raceId)
{
	if(gRaceStatus[raceId][mRaceEntrant1Status] == PLAYER_RACE_STATE_CONNECTED)
	{
		if(gPlayerVars[gRaceStatus[raceId][mRaceEntrant1Id]][mRacePlace1Info])
			TextDrawDestroy(gPlayerVars[gRaceStatus[raceId][mRaceEntrant1Id]][mRacePlace1Info]);
		gPlayerVars[gRaceStatus[raceId][mRaceEntrant1Id]][mRacePlace1Info] = TextDrawCreate(580.0, 220.0, " ");
		TextDrawLetterSize(gPlayerVars[gRaceStatus[raceId][mRaceEntrant1Id]][mRacePlace1Info], 0.15, 0.6);
		TextDrawTextSize(gPlayerVars[gRaceStatus[raceId][mRaceEntrant1Id]][mRacePlace1Info], 200.0, 50.0);
		
		TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant1Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant1Id]][mRacePlace1Info]);
		
		if(gRaceStatus[raceId][mRaceEntrant2Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant2Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant1Id]][mRacePlace1Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant3Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant3Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant1Id]][mRacePlace1Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant4Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant4Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant1Id]][mRacePlace1Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant5Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant5Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant1Id]][mRacePlace1Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant6Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant6Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant1Id]][mRacePlace1Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant7Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant7Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant1Id]][mRacePlace1Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant8Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant8Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant1Id]][mRacePlace1Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant9Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant9Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant1Id]][mRacePlace1Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant10Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant10Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant1Id]][mRacePlace1Info]);
	}
	if(gRaceStatus[raceId][mRaceEntrant2Status] == PLAYER_RACE_STATE_CONNECTED)
	{
		if(gPlayerVars[gRaceStatus[raceId][mRaceEntrant2Id]][mRacePlace2Info])
			TextDrawDestroy(gPlayerVars[gRaceStatus[raceId][mRaceEntrant2Id]][mRacePlace2Info]);
		gPlayerVars[gRaceStatus[raceId][mRaceEntrant2Id]][mRacePlace2Info] = TextDrawCreate(580.0, 230.0, " ");
		TextDrawLetterSize(gPlayerVars[gRaceStatus[raceId][mRaceEntrant2Id]][mRacePlace2Info], 0.15, 0.6);
		TextDrawTextSize(gPlayerVars[gRaceStatus[raceId][mRaceEntrant2Id]][mRacePlace2Info], 200.0, 50.0);
		
		TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant2Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant2Id]][mRacePlace2Info]);
		
		if(gRaceStatus[raceId][mRaceEntrant1Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant1Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant2Id]][mRacePlace2Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant3Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant3Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant2Id]][mRacePlace2Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant4Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant4Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant2Id]][mRacePlace2Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant5Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant5Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant2Id]][mRacePlace2Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant6Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant6Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant2Id]][mRacePlace2Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant7Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant7Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant2Id]][mRacePlace2Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant8Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant8Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant2Id]][mRacePlace2Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant9Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant9Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant2Id]][mRacePlace2Info]);
			
		if(gRaceStatus[raceId][mRaceEntrant10Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant10Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant2Id]][mRacePlace2Info]);
	}
	if(gRaceStatus[raceId][mRaceEntrant3Status] == PLAYER_RACE_STATE_CONNECTED)
	{
		if(gPlayerVars[gRaceStatus[raceId][mRaceEntrant3Id]][mRacePlace3Info])
			TextDrawDestroy(gPlayerVars[gRaceStatus[raceId][mRaceEntrant3Id]][mRacePlace3Info]);
		gPlayerVars[gRaceStatus[raceId][mRaceEntrant3Id]][mRacePlace3Info] = TextDrawCreate(580.0, 240.0, " ");
		TextDrawLetterSize(gPlayerVars[gRaceStatus[raceId][mRaceEntrant3Id]][mRacePlace3Info], 0.15, 0.6);
		TextDrawTextSize(gPlayerVars[gRaceStatus[raceId][mRaceEntrant3Id]][mRacePlace3Info], 100.0, 50.0);
		
		TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant3Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant3Id]][mRacePlace3Info]);
		
		if(gRaceStatus[raceId][mRaceEntrant1Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant1Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant3Id]][mRacePlace3Info]);
		if(gRaceStatus[raceId][mRaceEntrant2Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant2Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant3Id]][mRacePlace3Info]);
		if(gRaceStatus[raceId][mRaceEntrant4Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant4Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant3Id]][mRacePlace3Info]);
		if(gRaceStatus[raceId][mRaceEntrant5Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant5Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant3Id]][mRacePlace3Info]);
		if(gRaceStatus[raceId][mRaceEntrant6Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant6Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant3Id]][mRacePlace3Info]);
		if(gRaceStatus[raceId][mRaceEntrant7Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant7Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant3Id]][mRacePlace3Info]);
		if(gRaceStatus[raceId][mRaceEntrant8Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant8Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant3Id]][mRacePlace3Info]);
		if(gRaceStatus[raceId][mRaceEntrant9Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant9Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant3Id]][mRacePlace3Info]);
		if(gRaceStatus[raceId][mRaceEntrant10Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant10Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant3Id]][mRacePlace3Info]);
	}
	if(gRaceStatus[raceId][mRaceEntrant4Status] == PLAYER_RACE_STATE_CONNECTED)
	{
		if(gPlayerVars[gRaceStatus[raceId][mRaceEntrant4Id]][mRacePlace4Info])
			TextDrawDestroy(gPlayerVars[gRaceStatus[raceId][mRaceEntrant4Id]][mRacePlace4Info]);
		gPlayerVars[gRaceStatus[raceId][mRaceEntrant4Id]][mRacePlace4Info] = TextDrawCreate(580.0, 250.0, " ");
		TextDrawLetterSize(gPlayerVars[gRaceStatus[raceId][mRaceEntrant4Id]][mRacePlace4Info], 0.15, 0.6);
		TextDrawTextSize(gPlayerVars[gRaceStatus[raceId][mRaceEntrant4Id]][mRacePlace4Info], 100.0, 50.0);
		
		TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant4Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant4Id]][mRacePlace4Info]);
		
		if(gRaceStatus[raceId][mRaceEntrant1Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant1Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant4Id]][mRacePlace4Info]);
		if(gRaceStatus[raceId][mRaceEntrant2Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant2Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant4Id]][mRacePlace4Info]);
		if(gRaceStatus[raceId][mRaceEntrant3Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant3Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant4Id]][mRacePlace4Info]);
		if(gRaceStatus[raceId][mRaceEntrant5Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant5Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant4Id]][mRacePlace4Info]);
		if(gRaceStatus[raceId][mRaceEntrant6Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant6Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant4Id]][mRacePlace4Info]);
		if(gRaceStatus[raceId][mRaceEntrant7Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant7Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant4Id]][mRacePlace4Info]);
		if(gRaceStatus[raceId][mRaceEntrant8Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant8Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant4Id]][mRacePlace4Info]);
		if(gRaceStatus[raceId][mRaceEntrant9Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant9Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant4Id]][mRacePlace4Info]);
		if(gRaceStatus[raceId][mRaceEntrant10Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant10Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant4Id]][mRacePlace4Info]);
	}
	if(gRaceStatus[raceId][mRaceEntrant5Status] == PLAYER_RACE_STATE_CONNECTED)
	{
		if(gPlayerVars[gRaceStatus[raceId][mRaceEntrant5Id]][mRacePlace5Info])
			TextDrawDestroy(gPlayerVars[gRaceStatus[raceId][mRaceEntrant5Id]][mRacePlace5Info]);
		gPlayerVars[gRaceStatus[raceId][mRaceEntrant5Id]][mRacePlace5Info] = TextDrawCreate(580.0, 260.0, " ");
		TextDrawLetterSize(gPlayerVars[gRaceStatus[raceId][mRaceEntrant5Id]][mRacePlace5Info], 0.15, 0.6);
		TextDrawTextSize(gPlayerVars[gRaceStatus[raceId][mRaceEntrant5Id]][mRacePlace5Info], 100.0, 50.0);
		
		TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant5Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant5Id]][mRacePlace5Info]);
		
		if(gRaceStatus[raceId][mRaceEntrant1Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant1Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant5Id]][mRacePlace5Info]);
		if(gRaceStatus[raceId][mRaceEntrant2Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant2Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant5Id]][mRacePlace5Info]);
		if(gRaceStatus[raceId][mRaceEntrant3Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant3Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant5Id]][mRacePlace5Info]);
		if(gRaceStatus[raceId][mRaceEntrant4Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant4Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant5Id]][mRacePlace5Info]);
		if(gRaceStatus[raceId][mRaceEntrant6Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant6Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant5Id]][mRacePlace5Info]);
		if(gRaceStatus[raceId][mRaceEntrant7Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant7Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant5Id]][mRacePlace5Info]);
		if(gRaceStatus[raceId][mRaceEntrant8Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant8Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant5Id]][mRacePlace5Info]);
		if(gRaceStatus[raceId][mRaceEntrant9Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant9Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant5Id]][mRacePlace5Info]);
		if(gRaceStatus[raceId][mRaceEntrant10Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant10Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant5Id]][mRacePlace5Info]);
	}
	if(gRaceStatus[raceId][mRaceEntrant6Status] == PLAYER_RACE_STATE_CONNECTED)
	{
		if(gPlayerVars[gRaceStatus[raceId][mRaceEntrant6Id]][mRacePlace6Info])
			TextDrawDestroy(gPlayerVars[gRaceStatus[raceId][mRaceEntrant6Id]][mRacePlace6Info]);
		gPlayerVars[gRaceStatus[raceId][mRaceEntrant6Id]][mRacePlace6Info] = TextDrawCreate(580.0, 270.0, " ");
		TextDrawLetterSize(gPlayerVars[gRaceStatus[raceId][mRaceEntrant6Id]][mRacePlace6Info], 0.15, 0.6);
		TextDrawTextSize(gPlayerVars[gRaceStatus[raceId][mRaceEntrant6Id]][mRacePlace6Info], 100.0, 50.0);
		
		TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant6Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant6Id]][mRacePlace6Info]);
		
		if(gRaceStatus[raceId][mRaceEntrant1Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant1Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant6Id]][mRacePlace6Info]);
		if(gRaceStatus[raceId][mRaceEntrant2Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant2Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant6Id]][mRacePlace6Info]);
		if(gRaceStatus[raceId][mRaceEntrant3Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant3Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant6Id]][mRacePlace6Info]);
		if(gRaceStatus[raceId][mRaceEntrant4Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant4Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant6Id]][mRacePlace6Info]);
		if(gRaceStatus[raceId][mRaceEntrant5Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant5Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant6Id]][mRacePlace6Info]);
		if(gRaceStatus[raceId][mRaceEntrant7Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant7Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant6Id]][mRacePlace6Info]);
		if(gRaceStatus[raceId][mRaceEntrant8Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant8Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant6Id]][mRacePlace6Info]);
		if(gRaceStatus[raceId][mRaceEntrant9Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant9Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant6Id]][mRacePlace6Info]);
		if(gRaceStatus[raceId][mRaceEntrant10Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant10Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant6Id]][mRacePlace6Info]);
	}
	if(gRaceStatus[raceId][mRaceEntrant7Status] == PLAYER_RACE_STATE_CONNECTED)
	{
		if(gPlayerVars[gRaceStatus[raceId][mRaceEntrant7Id]][mRacePlace7Info])
			TextDrawDestroy(gPlayerVars[gRaceStatus[raceId][mRaceEntrant7Id]][mRacePlace7Info]);
		gPlayerVars[gRaceStatus[raceId][mRaceEntrant7Id]][mRacePlace7Info] = TextDrawCreate(580.0, 280.0, " ");
		TextDrawLetterSize(gPlayerVars[gRaceStatus[raceId][mRaceEntrant7Id]][mRacePlace7Info], 0.15, 0.6);
		TextDrawTextSize(gPlayerVars[gRaceStatus[raceId][mRaceEntrant7Id]][mRacePlace7Info], 100.0, 50.0);
		
		TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant7Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant7Id]][mRacePlace7Info]);
		
		if(gRaceStatus[raceId][mRaceEntrant1Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant1Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant7Id]][mRacePlace7Info]);
		if(gRaceStatus[raceId][mRaceEntrant2Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant2Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant7Id]][mRacePlace7Info]);
		if(gRaceStatus[raceId][mRaceEntrant3Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant3Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant7Id]][mRacePlace7Info]);
		if(gRaceStatus[raceId][mRaceEntrant4Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant4Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant7Id]][mRacePlace7Info]);
		if(gRaceStatus[raceId][mRaceEntrant5Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant5Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant7Id]][mRacePlace7Info]);
		if(gRaceStatus[raceId][mRaceEntrant6Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant6Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant7Id]][mRacePlace7Info]);
		if(gRaceStatus[raceId][mRaceEntrant8Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant8Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant7Id]][mRacePlace7Info]);
		if(gRaceStatus[raceId][mRaceEntrant9Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant9Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant7Id]][mRacePlace7Info]);
		if(gRaceStatus[raceId][mRaceEntrant10Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant10Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant7Id]][mRacePlace7Info]);
	}
	if(gRaceStatus[raceId][mRaceEntrant8Status] == PLAYER_RACE_STATE_CONNECTED)
	{
		if(gPlayerVars[gRaceStatus[raceId][mRaceEntrant8Id]][mRacePlace8Info])
			TextDrawDestroy(gPlayerVars[gRaceStatus[raceId][mRaceEntrant8Id]][mRacePlace8Info]);
		gPlayerVars[gRaceStatus[raceId][mRaceEntrant8Id]][mRacePlace8Info] = TextDrawCreate(580.0, 290.0, " ");
		TextDrawLetterSize(gPlayerVars[gRaceStatus[raceId][mRaceEntrant8Id]][mRacePlace8Info], 0.15, 0.6);
		TextDrawTextSize(gPlayerVars[gRaceStatus[raceId][mRaceEntrant8Id]][mRacePlace8Info], 100.0, 50.0);
		
		TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant8Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant8Id]][mRacePlace8Info]);
		
		if(gRaceStatus[raceId][mRaceEntrant1Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant1Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant8Id]][mRacePlace8Info]);
		if(gRaceStatus[raceId][mRaceEntrant2Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant2Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant8Id]][mRacePlace8Info]);
		if(gRaceStatus[raceId][mRaceEntrant3Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant3Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant8Id]][mRacePlace8Info]);
		if(gRaceStatus[raceId][mRaceEntrant4Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant4Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant8Id]][mRacePlace8Info]);
		if(gRaceStatus[raceId][mRaceEntrant5Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant5Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant8Id]][mRacePlace8Info]);
		if(gRaceStatus[raceId][mRaceEntrant6Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant6Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant8Id]][mRacePlace8Info]);
		if(gRaceStatus[raceId][mRaceEntrant7Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant7Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant8Id]][mRacePlace8Info]);
		if(gRaceStatus[raceId][mRaceEntrant9Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant9Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant8Id]][mRacePlace8Info]);
		if(gRaceStatus[raceId][mRaceEntrant10Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant10Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant8Id]][mRacePlace8Info]);
	}
	if(gRaceStatus[raceId][mRaceEntrant9Status] == PLAYER_RACE_STATE_CONNECTED)
	{
		if(gPlayerVars[gRaceStatus[raceId][mRaceEntrant9Id]][mRacePlace9Info])
			TextDrawDestroy(gPlayerVars[gRaceStatus[raceId][mRaceEntrant9Id]][mRacePlace9Info]);
		gPlayerVars[gRaceStatus[raceId][mRaceEntrant9Id]][mRacePlace9Info] = TextDrawCreate(580.0, 300.0, " ");
		TextDrawLetterSize(gPlayerVars[gRaceStatus[raceId][mRaceEntrant9Id]][mRacePlace9Info], 0.15, 0.6);
		TextDrawTextSize(gPlayerVars[gRaceStatus[raceId][mRaceEntrant9Id]][mRacePlace9Info], 100.0, 50.0);
		
		TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant9Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant9Id]][mRacePlace9Info]);
		
		if(gRaceStatus[raceId][mRaceEntrant1Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant1Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant9Id]][mRacePlace9Info]);
		if(gRaceStatus[raceId][mRaceEntrant2Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant2Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant9Id]][mRacePlace9Info]);
		if(gRaceStatus[raceId][mRaceEntrant3Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant3Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant9Id]][mRacePlace9Info]);
		if(gRaceStatus[raceId][mRaceEntrant4Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant4Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant9Id]][mRacePlace9Info]);
		if(gRaceStatus[raceId][mRaceEntrant5Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant5Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant9Id]][mRacePlace9Info]);
		if(gRaceStatus[raceId][mRaceEntrant6Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant6Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant9Id]][mRacePlace9Info]);
		if(gRaceStatus[raceId][mRaceEntrant7Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant7Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant9Id]][mRacePlace9Info]);
		if(gRaceStatus[raceId][mRaceEntrant8Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant8Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant9Id]][mRacePlace9Info]);
		if(gRaceStatus[raceId][mRaceEntrant10Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant10Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant9Id]][mRacePlace9Info]);
	}
	if(gRaceStatus[raceId][mRaceEntrant10Status] == PLAYER_RACE_STATE_CONNECTED)
	{
		if(gPlayerVars[gRaceStatus[raceId][mRaceEntrant10Id]][mRacePlace10Info])
			TextDrawDestroy(gPlayerVars[gRaceStatus[raceId][mRaceEntrant10Id]][mRacePlace10Info]);
		gPlayerVars[gRaceStatus[raceId][mRaceEntrant10Id]][mRacePlace10Info] = TextDrawCreate(550.0, 210.0, " ");
		TextDrawLetterSize(gPlayerVars[gRaceStatus[raceId][mRaceEntrant10Id]][mRacePlace10Info], 0.15, 0.6);
		TextDrawTextSize(gPlayerVars[gRaceStatus[raceId][mRaceEntrant10Id]][mRacePlace10Info], 100.0, 50.0);
		
		TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant10Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant10Id]][mRacePlace10Info]);
		
		if(gRaceStatus[raceId][mRaceEntrant1Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant1Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant10Id]][mRacePlace10Info]);
		if(gRaceStatus[raceId][mRaceEntrant2Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant2Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant10Id]][mRacePlace10Info]);
		if(gRaceStatus[raceId][mRaceEntrant3Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant3Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant10Id]][mRacePlace10Info]);
		if(gRaceStatus[raceId][mRaceEntrant4Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant4Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant10Id]][mRacePlace10Info]);
		if(gRaceStatus[raceId][mRaceEntrant5Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant5Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant10Id]][mRacePlace10Info]);
		if(gRaceStatus[raceId][mRaceEntrant6Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant6Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant10Id]][mRacePlace10Info]);
		if(gRaceStatus[raceId][mRaceEntrant7Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant7Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant10Id]][mRacePlace10Info]);
		if(gRaceStatus[raceId][mRaceEntrant8Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant8Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant10Id]][mRacePlace10Info]);
		if(gRaceStatus[raceId][mRaceEntrant9Status] == PLAYER_RACE_STATE_CONNECTED)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant9Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant10Id]][mRacePlace10Info]);
	}
}

stock IsAnyPlayerInRace(raceId)
{
	if(gRaceStatus[raceId][mRaceEntrant1Status] == PLAYER_RACE_STATE_CONNECTED)
		return 1;
	if(gRaceStatus[raceId][mRaceEntrant2Status] == PLAYER_RACE_STATE_CONNECTED)
		return 1;
	if(gRaceStatus[raceId][mRaceEntrant3Status] == PLAYER_RACE_STATE_CONNECTED)
		return 1;
	if(gRaceStatus[raceId][mRaceEntrant4Status] == PLAYER_RACE_STATE_CONNECTED)
		return 1;
	if(gRaceStatus[raceId][mRaceEntrant5Status] == PLAYER_RACE_STATE_CONNECTED)
		return 1;
	if(gRaceStatus[raceId][mRaceEntrant6Status] == PLAYER_RACE_STATE_CONNECTED)
		return 1;
	if(gRaceStatus[raceId][mRaceEntrant7Status] == PLAYER_RACE_STATE_CONNECTED)
		return 1;
	if(gRaceStatus[raceId][mRaceEntrant8Status] == PLAYER_RACE_STATE_CONNECTED)
		return 1;
	if(gRaceStatus[raceId][mRaceEntrant9Status] == PLAYER_RACE_STATE_CONNECTED)
		return 1;
	if(gRaceStatus[raceId][mRaceEntrant10Status] == PLAYER_RACE_STATE_CONNECTED)
		return 1;
	return 0;
}

stock FreezeRacers(raceId)
{
	if(gRaceStatus[raceId][mRaceEntrant1Status] == PLAYER_RACE_STATE_CONNECTED)
		TogglePlayerControllable(gRaceStatus[raceId][mRaceEntrant1Id], 0);
	if(gRaceStatus[raceId][mRaceEntrant2Status] == PLAYER_RACE_STATE_CONNECTED)
		TogglePlayerControllable(gRaceStatus[raceId][mRaceEntrant2Id], 0);
	if(gRaceStatus[raceId][mRaceEntrant3Status] == PLAYER_RACE_STATE_CONNECTED)
		TogglePlayerControllable(gRaceStatus[raceId][mRaceEntrant3Id], 0);
	if(gRaceStatus[raceId][mRaceEntrant4Status] == PLAYER_RACE_STATE_CONNECTED)
		TogglePlayerControllable(gRaceStatus[raceId][mRaceEntrant4Id], 0);
	if(gRaceStatus[raceId][mRaceEntrant5Status] == PLAYER_RACE_STATE_CONNECTED)
		TogglePlayerControllable(gRaceStatus[raceId][mRaceEntrant5Id], 0);
	if(gRaceStatus[raceId][mRaceEntrant6Status] == PLAYER_RACE_STATE_CONNECTED)
		TogglePlayerControllable(gRaceStatus[raceId][mRaceEntrant6Id], 0);
	if(gRaceStatus[raceId][mRaceEntrant7Status] == PLAYER_RACE_STATE_CONNECTED)
		TogglePlayerControllable(gRaceStatus[raceId][mRaceEntrant7Id], 0);
	if(gRaceStatus[raceId][mRaceEntrant8Status] == PLAYER_RACE_STATE_CONNECTED)
		TogglePlayerControllable(gRaceStatus[raceId][mRaceEntrant8Id], 0);
	if(gRaceStatus[raceId][mRaceEntrant9Status] == PLAYER_RACE_STATE_CONNECTED)
		TogglePlayerControllable(gRaceStatus[raceId][mRaceEntrant9Id], 0);
	if(gRaceStatus[raceId][mRaceEntrant10Status] == PLAYER_RACE_STATE_CONNECTED)
		TogglePlayerControllable(gRaceStatus[raceId][mRaceEntrant10Id], 0);
}

stock UnfreezeRacers(raceId)
{
	if(gRaceStatus[raceId][mRaceEntrant1Status] == PLAYER_RACE_STATE_CONNECTED)
		TogglePlayerControllable(gRaceStatus[raceId][mRaceEntrant1Id], 1);
	if(gRaceStatus[raceId][mRaceEntrant2Status] == PLAYER_RACE_STATE_CONNECTED)
		TogglePlayerControllable(gRaceStatus[raceId][mRaceEntrant2Id], 1);
	if(gRaceStatus[raceId][mRaceEntrant3Status] == PLAYER_RACE_STATE_CONNECTED)
		TogglePlayerControllable(gRaceStatus[raceId][mRaceEntrant3Id], 1);
	if(gRaceStatus[raceId][mRaceEntrant4Status] == PLAYER_RACE_STATE_CONNECTED)
		TogglePlayerControllable(gRaceStatus[raceId][mRaceEntrant4Id], 1);
	if(gRaceStatus[raceId][mRaceEntrant5Status] == PLAYER_RACE_STATE_CONNECTED)
		TogglePlayerControllable(gRaceStatus[raceId][mRaceEntrant5Id], 1);
	if(gRaceStatus[raceId][mRaceEntrant6Status] == PLAYER_RACE_STATE_CONNECTED)
		TogglePlayerControllable(gRaceStatus[raceId][mRaceEntrant6Id], 1);
	if(gRaceStatus[raceId][mRaceEntrant7Status] == PLAYER_RACE_STATE_CONNECTED)
		TogglePlayerControllable(gRaceStatus[raceId][mRaceEntrant7Id], 1);
	if(gRaceStatus[raceId][mRaceEntrant8Status] == PLAYER_RACE_STATE_CONNECTED)
		TogglePlayerControllable(gRaceStatus[raceId][mRaceEntrant8Id], 1);
	if(gRaceStatus[raceId][mRaceEntrant9Status] == PLAYER_RACE_STATE_CONNECTED)
		TogglePlayerControllable(gRaceStatus[raceId][mRaceEntrant9Id], 1);
	if(gRaceStatus[raceId][mRaceEntrant10Status] == PLAYER_RACE_STATE_CONNECTED)
		TogglePlayerControllable(gRaceStatus[raceId][mRaceEntrant10Id], 1);
}

stock SetCameraBehindRacers(raceId)
{
	if(gRaceStatus[raceId][mRaceEntrant1Status] == PLAYER_RACE_STATE_CONNECTED)
		SetCameraBehindPlayer(gRaceStatus[raceId][mRaceEntrant1Id]);
	if(gRaceStatus[raceId][mRaceEntrant2Status] == PLAYER_RACE_STATE_CONNECTED)
		SetCameraBehindPlayer(gRaceStatus[raceId][mRaceEntrant2Id]);
	if(gRaceStatus[raceId][mRaceEntrant3Status] == PLAYER_RACE_STATE_CONNECTED)
		SetCameraBehindPlayer(gRaceStatus[raceId][mRaceEntrant3Id]);
	if(gRaceStatus[raceId][mRaceEntrant4Status] == PLAYER_RACE_STATE_CONNECTED)
		SetCameraBehindPlayer(gRaceStatus[raceId][mRaceEntrant4Id]);
	if(gRaceStatus[raceId][mRaceEntrant5Status] == PLAYER_RACE_STATE_CONNECTED)
		SetCameraBehindPlayer(gRaceStatus[raceId][mRaceEntrant5Id]);
	if(gRaceStatus[raceId][mRaceEntrant6Status] == PLAYER_RACE_STATE_CONNECTED)
		SetCameraBehindPlayer(gRaceStatus[raceId][mRaceEntrant6Id]);
	if(gRaceStatus[raceId][mRaceEntrant7Status] == PLAYER_RACE_STATE_CONNECTED)
		SetCameraBehindPlayer(gRaceStatus[raceId][mRaceEntrant7Id]);
	if(gRaceStatus[raceId][mRaceEntrant8Status] == PLAYER_RACE_STATE_CONNECTED)
		SetCameraBehindPlayer(gRaceStatus[raceId][mRaceEntrant8Id]);
	if(gRaceStatus[raceId][mRaceEntrant9Status] == PLAYER_RACE_STATE_CONNECTED)
		SetCameraBehindPlayer(gRaceStatus[raceId][mRaceEntrant9Id]);
	if(gRaceStatus[raceId][mRaceEntrant10Status] == PLAYER_RACE_STATE_CONNECTED)
		SetCameraBehindPlayer(gRaceStatus[raceId][mRaceEntrant10Id]);
}

stock PlayerRaceStartSound(raceId, step = 5)
{
	if(gRaceStatus[raceId][mRaceEntrant1Status] == PLAYER_RACE_STATE_CONNECTED)
	{
		if(step > 0)
			PlayerPlaySound(gRaceStatus[raceId][mRaceEntrant1Id], 1056, 0, 0, 0);
		else
			PlayerPlaySound(gRaceStatus[raceId][mRaceEntrant1Id], 1057, 0, 0, 0);
	}
	// TODO: Fill the rest
}

stock SetCameraAtStart(raceId, step = 1)
{
	if(gRaceStatus[raceId][mRaceEntrant1Status] == PLAYER_RACE_STATE_CONNECTED)
	{
		if(step == 1)
		{
			SetPlayerCameraLookAt(gRaceStatus[raceId][mRaceEntrant1Id], gRaceTrackStart1CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart1CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart1CpZ[gRaceStatus[raceId][mRaceId]]);
			SetPlayerCameraPos(gRaceStatus[raceId][mRaceEntrant1Id], gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][0]+10.0);
		}
		if(step == 2)
		{
			InterpolateCameraPos(gRaceStatus[raceId][mRaceEntrant1Id], gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][0]+10.0, gRaceTrackStart1CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart1CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart1CpZ[gRaceStatus[raceId][mRaceId]], 2500, CAMERA_MOVE);
		}
		else if(step == 3)
		{
			InterpolateCameraPos(gRaceStatus[raceId][mRaceEntrant1Id], gRaceTrackStart2CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart2CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart2CpZ[gRaceStatus[raceId][mRaceId]]+10.0, gRaceTrackStart1CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart1CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart1CpZ[gRaceStatus[raceId][mRaceId]], 2500, CAMERA_MOVE);
			InterpolateCameraLookAt(gRaceStatus[raceId][mRaceEntrant1Id], gRaceTrackStart3CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart3CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart3CpZ[gRaceStatus[raceId][mRaceId]], gRaceTrackStart1CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart1CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart1CpZ[gRaceStatus[raceId][mRaceId]], 1000, CAMERA_MOVE);
		}
		else if(step == 4)
		{
			InterpolateCameraPos(gRaceStatus[raceId][mRaceEntrant1Id], gRaceTrackStart3CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart3CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart3CpZ[gRaceStatus[raceId][mRaceId]]+10.0, gRaceTrackStart1CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart1CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart1CpZ[gRaceStatus[raceId][mRaceId]], 2500, CAMERA_MOVE);
			InterpolateCameraLookAt(gRaceStatus[raceId][mRaceEntrant1Id], gRaceTrackStart2CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart2CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart2CpZ[gRaceStatus[raceId][mRaceId]], gRaceTrackStart1CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart1CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart1CpZ[gRaceStatus[raceId][mRaceId]], 1000, CAMERA_MOVE);
		}
	}
	if(gRaceStatus[raceId][mRaceEntrant2Status] == PLAYER_RACE_STATE_CONNECTED)
	{
		if(step == 1)
		{
			SetPlayerCameraLookAt(gRaceStatus[raceId][mRaceEntrant2Id], gRaceTrackStart2CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart2CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart2CpZ[gRaceStatus[raceId][mRaceId]]);
			SetPlayerCameraPos(gRaceStatus[raceId][mRaceEntrant2Id], gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][0]+10.0);
		}
		if(step == 2)
		{
			InterpolateCameraPos(gRaceStatus[raceId][mRaceEntrant2Id], gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][0]+10.0, gRaceTrackStart2CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart2CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart2CpZ[gRaceStatus[raceId][mRaceId]], 2500, CAMERA_MOVE);
		}
		else if(step == 3)
		{
			InterpolateCameraPos(gRaceStatus[raceId][mRaceEntrant2Id], gRaceTrackStart1CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart1CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart1CpZ[gRaceStatus[raceId][mRaceId]]+10.0, gRaceTrackStart2CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart2CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart2CpZ[gRaceStatus[raceId][mRaceId]], 2500, CAMERA_MOVE);
			InterpolateCameraLookAt(gRaceStatus[raceId][mRaceEntrant2Id], gRaceTrackStart3CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart3CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart3CpZ[gRaceStatus[raceId][mRaceId]], gRaceTrackStart2CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart2CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart2CpZ[gRaceStatus[raceId][mRaceId]], 1000, CAMERA_MOVE);
		}
		else if(step == 4)
		{
			InterpolateCameraPos(gRaceStatus[raceId][mRaceEntrant2Id], gRaceTrackStart3CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart3CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart3CpZ[gRaceStatus[raceId][mRaceId]]+10.0, gRaceTrackStart2CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart2CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart2CpZ[gRaceStatus[raceId][mRaceId]], 2500, CAMERA_MOVE);
			InterpolateCameraLookAt(gRaceStatus[raceId][mRaceEntrant2Id], gRaceTrackStart1CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart1CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart1CpZ[gRaceStatus[raceId][mRaceId]], gRaceTrackStart2CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart2CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart2CpZ[gRaceStatus[raceId][mRaceId]], 1000, CAMERA_MOVE);
		}
	}
	if(gRaceStatus[raceId][mRaceEntrant3Status] == PLAYER_RACE_STATE_CONNECTED)
	{
		if(step == 1)
		{
			SetPlayerCameraLookAt(gRaceStatus[raceId][mRaceEntrant3Id], gRaceTrackStart3CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart3CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart3CpZ[gRaceStatus[raceId][mRaceId]]);
			SetPlayerCameraPos(gRaceStatus[raceId][mRaceEntrant3Id], gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][0]+10.0);
		}
		if(step == 2)
		{
			InterpolateCameraPos(gRaceStatus[raceId][mRaceEntrant3Id], gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][0]+10.0, gRaceTrackStart2CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart2CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart2CpZ[gRaceStatus[raceId][mRaceId]], 2500, CAMERA_MOVE);
		}
		else if(step == 3)
		{
			InterpolateCameraPos(gRaceStatus[raceId][mRaceEntrant3Id], gRaceTrackStart2CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart2CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart2CpZ[gRaceStatus[raceId][mRaceId]]+10.0, gRaceTrackStart3CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart3CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart3CpZ[gRaceStatus[raceId][mRaceId]], 2500, CAMERA_MOVE);
			InterpolateCameraLookAt(gRaceStatus[raceId][mRaceEntrant3Id], gRaceTrackStart4CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart4CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart4CpZ[gRaceStatus[raceId][mRaceId]], gRaceTrackStart3CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart3CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart3CpZ[gRaceStatus[raceId][mRaceId]], 1000, CAMERA_MOVE);
		}
		else if(step == 4)
		{
			InterpolateCameraPos(gRaceStatus[raceId][mRaceEntrant3Id], gRaceTrackStart2CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart2CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart2CpZ[gRaceStatus[raceId][mRaceId]]+10.0, gRaceTrackStart3CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart3CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart3CpZ[gRaceStatus[raceId][mRaceId]], 2500, CAMERA_MOVE);
			InterpolateCameraLookAt(gRaceStatus[raceId][mRaceEntrant3Id], gRaceTrackStart4CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart4CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart4CpZ[gRaceStatus[raceId][mRaceId]], gRaceTrackStart3CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart3CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart3CpZ[gRaceStatus[raceId][mRaceId]], 1000, CAMERA_MOVE);
		}
	}
	if(gRaceStatus[raceId][mRaceEntrant4Status] == PLAYER_RACE_STATE_CONNECTED)
	{
		if(step == 1)
		{
			SetPlayerCameraLookAt(gRaceStatus[raceId][mRaceEntrant4Id], gRaceTrackStart4CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart4CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart4CpZ[gRaceStatus[raceId][mRaceId]]);
			SetPlayerCameraPos(gRaceStatus[raceId][mRaceEntrant4Id], gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][0]+10.0);
		}
		if(step == 2)
		{
			InterpolateCameraPos(gRaceStatus[raceId][mRaceEntrant4Id], gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][0]+10.0, gRaceTrackStart4CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart4CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart4CpZ[gRaceStatus[raceId][mRaceId]], 2500, CAMERA_MOVE);
		}
		else if(step == 3)
		{
			InterpolateCameraPos(gRaceStatus[raceId][mRaceEntrant4Id], gRaceTrackStart3CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart3CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart3CpZ[gRaceStatus[raceId][mRaceId]]+10.0, gRaceTrackStart4CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart4CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart4CpZ[gRaceStatus[raceId][mRaceId]], 2500, CAMERA_MOVE);
			InterpolateCameraLookAt(gRaceStatus[raceId][mRaceEntrant4Id], gRaceTrackStart2CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart2CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart2CpZ[gRaceStatus[raceId][mRaceId]], gRaceTrackStart4CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart4CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart4CpZ[gRaceStatus[raceId][mRaceId]], 1000, CAMERA_MOVE);
		}
		else if(step == 4)
		{
			InterpolateCameraPos(gRaceStatus[raceId][mRaceEntrant4Id], gRaceTrackStart2CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart2CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart2CpZ[gRaceStatus[raceId][mRaceId]]+10.0, gRaceTrackStart4CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart4CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart4CpZ[gRaceStatus[raceId][mRaceId]], 2500, CAMERA_MOVE);
			InterpolateCameraLookAt(gRaceStatus[raceId][mRaceEntrant4Id], gRaceTrackStart3CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart3CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart3CpZ[gRaceStatus[raceId][mRaceId]], gRaceTrackStart4CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart4CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart4CpZ[gRaceStatus[raceId][mRaceId]], 1000, CAMERA_MOVE);
		}
	}
	if(gRaceStatus[raceId][mRaceEntrant5Status] == PLAYER_RACE_STATE_CONNECTED)
	{
		if(step == 1)
		{
			SetPlayerCameraLookAt(gRaceStatus[raceId][mRaceEntrant5Id], gRaceTrackStart5CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart5CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart5CpZ[gRaceStatus[raceId][mRaceId]]);
			SetPlayerCameraPos(gRaceStatus[raceId][mRaceEntrant5Id], gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][0]+5.0);
		}
		if(step == 2)
		{
			InterpolateCameraPos(gRaceStatus[raceId][mRaceEntrant5Id], gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][0]+10.0, gRaceTrackStart4CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart4CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart4CpZ[gRaceStatus[raceId][mRaceId]], 2500, CAMERA_MOVE);
		}
		else if(step == 3)
		{
			InterpolateCameraPos(gRaceStatus[raceId][mRaceEntrant5Id], gRaceTrackStart4CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart4CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart4CpZ[gRaceStatus[raceId][mRaceId]]+10.0, gRaceTrackStart5CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart5CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart5CpZ[gRaceStatus[raceId][mRaceId]], 2500, CAMERA_MOVE);
			InterpolateCameraLookAt(gRaceStatus[raceId][mRaceEntrant5Id], gRaceTrackStart3CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart3CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart3CpZ[gRaceStatus[raceId][mRaceId]], gRaceTrackStart5CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart5CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart5CpZ[gRaceStatus[raceId][mRaceId]], 1000, CAMERA_MOVE);
		}
		else if(step == 4)
		{
			InterpolateCameraPos(gRaceStatus[raceId][mRaceEntrant5Id], gRaceTrackStart3CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart3CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart3CpZ[gRaceStatus[raceId][mRaceId]]+10.0, gRaceTrackStart5CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart5CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart5CpZ[gRaceStatus[raceId][mRaceId]], 2500, CAMERA_MOVE);
			InterpolateCameraLookAt(gRaceStatus[raceId][mRaceEntrant5Id], gRaceTrackStart4CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart4CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart4CpZ[gRaceStatus[raceId][mRaceId]], gRaceTrackStart5CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart5CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart5CpZ[gRaceStatus[raceId][mRaceId]], 1000, CAMERA_MOVE);
		}
	}
	if(gRaceStatus[raceId][mRaceEntrant6Status] == PLAYER_RACE_STATE_CONNECTED)
	{
		if(step == 1)
		{
			SetPlayerCameraLookAt(gRaceStatus[raceId][mRaceEntrant6Id], gRaceTrackStart6CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart6CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart6CpZ[gRaceStatus[raceId][mRaceId]]);
			SetPlayerCameraPos(gRaceStatus[raceId][mRaceEntrant6Id], gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][0]+5.0);
		}
		if(step == 2)
		{
			InterpolateCameraPos(gRaceStatus[raceId][mRaceEntrant6Id], gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][0]+10.0, gRaceTrackStart4CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart4CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart4CpZ[gRaceStatus[raceId][mRaceId]], 2500, CAMERA_MOVE);
		}
		else if(step == 3)
		{
			InterpolateCameraPos(gRaceStatus[raceId][mRaceEntrant6Id], gRaceTrackStart5CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart5CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart5CpZ[gRaceStatus[raceId][mRaceId]]+10.0, gRaceTrackStart6CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart6CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart6CpZ[gRaceStatus[raceId][mRaceId]], 2500, CAMERA_MOVE);
			InterpolateCameraLookAt(gRaceStatus[raceId][mRaceEntrant6Id], gRaceTrackStart4CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart4CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart4CpZ[gRaceStatus[raceId][mRaceId]], gRaceTrackStart6CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart6CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart6CpZ[gRaceStatus[raceId][mRaceId]], 1000, CAMERA_MOVE);
		}
		else if(step == 4)
		{
			InterpolateCameraPos(gRaceStatus[raceId][mRaceEntrant6Id], gRaceTrackStart4CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart4CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart4CpZ[gRaceStatus[raceId][mRaceId]]+10.0, gRaceTrackStart6CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart6CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart6CpZ[gRaceStatus[raceId][mRaceId]], 2500, CAMERA_MOVE);
			InterpolateCameraLookAt(gRaceStatus[raceId][mRaceEntrant6Id], gRaceTrackStart5CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart5CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart5CpZ[gRaceStatus[raceId][mRaceId]], gRaceTrackStart6CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart6CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart6CpZ[gRaceStatus[raceId][mRaceId]], 1000, CAMERA_MOVE);
		}
	}
	if(gRaceStatus[raceId][mRaceEntrant7Status] == PLAYER_RACE_STATE_CONNECTED)
	{
		SetPlayerCameraLookAt(gRaceStatus[raceId][mRaceEntrant7Id], gRaceTrackStart7CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart7CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart7CpZ[gRaceStatus[raceId][mRaceId]]);
		SetPlayerCameraPos(gRaceStatus[raceId][mRaceEntrant7Id], gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][0]+5.0);
	}
	if(gRaceStatus[raceId][mRaceEntrant8Status] == PLAYER_RACE_STATE_CONNECTED)
	{
		SetPlayerCameraLookAt(gRaceStatus[raceId][mRaceEntrant8Id], gRaceTrackStart8CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart8CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart8CpZ[gRaceStatus[raceId][mRaceId]]);
		SetPlayerCameraPos(gRaceStatus[raceId][mRaceEntrant8Id], gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][0]+5.0);
	}
	if(gRaceStatus[raceId][mRaceEntrant9Status] == PLAYER_RACE_STATE_CONNECTED)
	{
		SetPlayerCameraLookAt(gRaceStatus[raceId][mRaceEntrant9Id], gRaceTrackStart9CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart9CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart9CpZ[gRaceStatus[raceId][mRaceId]]);
		SetPlayerCameraPos(gRaceStatus[raceId][mRaceEntrant9Id], gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][0]+5.0);
	}
	if(gRaceStatus[raceId][mRaceEntrant10Status] == PLAYER_RACE_STATE_CONNECTED)
	{
		SetPlayerCameraLookAt(gRaceStatus[raceId][mRaceEntrant10Id], gRaceTrackStart10CpX[gRaceStatus[raceId][mRaceId]], gRaceTrackStart10CpY[gRaceStatus[raceId][mRaceId]], gRaceTrackStart10CpZ[gRaceStatus[raceId][mRaceId]]);
		SetPlayerCameraPos(gRaceStatus[raceId][mRaceEntrant10Id], gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][0]+5.0);
	}
}

stock GameTextForRacers(raceId, string[], duration, style)
{
	if(gRaceStatus[raceId][mRaceEntrant1Status] == PLAYER_RACE_STATE_CONNECTED)
		GameTextForPlayer(gRaceStatus[raceId][mRaceEntrant1Id], string, duration, style);
	if(gRaceStatus[raceId][mRaceEntrant2Status] == PLAYER_RACE_STATE_CONNECTED)
		GameTextForPlayer(gRaceStatus[raceId][mRaceEntrant2Id], string, duration, style);
	if(gRaceStatus[raceId][mRaceEntrant3Status] == PLAYER_RACE_STATE_CONNECTED)
		GameTextForPlayer(gRaceStatus[raceId][mRaceEntrant3Id], string, duration, style);
	if(gRaceStatus[raceId][mRaceEntrant4Status] == PLAYER_RACE_STATE_CONNECTED)
		GameTextForPlayer(gRaceStatus[raceId][mRaceEntrant4Id], string, duration, style);
	if(gRaceStatus[raceId][mRaceEntrant5Status] == PLAYER_RACE_STATE_CONNECTED)
		GameTextForPlayer(gRaceStatus[raceId][mRaceEntrant5Id], string, duration, style);
	if(gRaceStatus[raceId][mRaceEntrant6Status] == PLAYER_RACE_STATE_CONNECTED)
		GameTextForPlayer(gRaceStatus[raceId][mRaceEntrant6Id], string, duration, style);
	if(gRaceStatus[raceId][mRaceEntrant7Status] == PLAYER_RACE_STATE_CONNECTED)
		GameTextForPlayer(gRaceStatus[raceId][mRaceEntrant7Id], string, duration, style);
	if(gRaceStatus[raceId][mRaceEntrant8Status] == PLAYER_RACE_STATE_CONNECTED)
		GameTextForPlayer(gRaceStatus[raceId][mRaceEntrant8Id], string, duration, style);
	if(gRaceStatus[raceId][mRaceEntrant9Status] == PLAYER_RACE_STATE_CONNECTED)
		GameTextForPlayer(gRaceStatus[raceId][mRaceEntrant9Id], string, duration, style);
	if(gRaceStatus[raceId][mRaceEntrant10Status] == PLAYER_RACE_STATE_CONNECTED)
		GameTextForPlayer(gRaceStatus[raceId][mRaceEntrant10Id], string, duration, style);
}

stock GameTextForRacerFinish(raceId, racerNo)
{
	new string[128];
	format(string, sizeof(string), "UKONCZYLES WYSCIG JAKO ");
	if(racerNo == 1)
	{
		if(gRaceStatus[raceId][mRaceEntrant1Place] == 1)
			strcat(string, "PIERWSZY");
		if(gRaceStatus[raceId][mRaceEntrant1Place] == 2)
			strcat(string, "DRUGI");
		if(gRaceStatus[raceId][mRaceEntrant1Place] == 3)
			strcat(string, "TRZECI");
		if(gRaceStatus[raceId][mRaceEntrant1Place] == 4)
			strcat(string, "CZWARTY");
		if(gRaceStatus[raceId][mRaceEntrant1Place] == 5)
			strcat(string, "PIATY");
		if(gRaceStatus[raceId][mRaceEntrant1Place] == 6)
			strcat(string, "SZOSTY");
		if(gRaceStatus[raceId][mRaceEntrant1Place] == 7)
			strcat(string, "SIODMY");
		if(gRaceStatus[raceId][mRaceEntrant1Place] == 8)
			strcat(string, "OSMY");
		if(gRaceStatus[raceId][mRaceEntrant1Place] == 9)
			strcat(string, "DZIEWIATY");
		if(gRaceStatus[raceId][mRaceEntrant1Place] == 10)
			strcat(string, "DZIESIATY");
		
		strcat(string, "~n~CZAS: ");		
		format(string, sizeof(string), "%s%d:", string, gRaceStatus[raceId][mRaceEntrant1Hour]);
		
		if(gRaceStatus[raceId][mRaceEntrant1Min] < 10)
			format(string, sizeof(string), "%s0%d:", string, gRaceStatus[raceId][mRaceEntrant1Min]);
		else
			format(string, sizeof(string), "%s%d:", string, gRaceStatus[raceId][mRaceEntrant1Min]);
		
		if(gRaceStatus[raceId][mRaceEntrant1Sec] < 10)
			format(string, sizeof(string), "%s0%d", string, gRaceStatus[raceId][mRaceEntrant1Sec]);
		else
			format(string, sizeof(string), "%s%d", string, gRaceStatus[raceId][mRaceEntrant1Sec]);
			
		GameTextForPlayer(gRaceStatus[raceId][mRaceEntrant1Id], string, 5000, 3);
	}
	else if(racerNo == 2)
	{
		if(gRaceStatus[raceId][mRaceEntrant2Place] == 1)
			strcat(string, "PIERWSZY");
		if(gRaceStatus[raceId][mRaceEntrant2Place] == 2)
			strcat(string, "DRUGI");
		if(gRaceStatus[raceId][mRaceEntrant2Place] == 3)
			strcat(string, "TRZECI");
		if(gRaceStatus[raceId][mRaceEntrant2Place] == 4)
			strcat(string, "CZWARTY");
		if(gRaceStatus[raceId][mRaceEntrant2Place] == 5)
			strcat(string, "PIATY");
		if(gRaceStatus[raceId][mRaceEntrant2Place] == 6)
			strcat(string, "SZOSTY");
		if(gRaceStatus[raceId][mRaceEntrant2Place] == 7)
			strcat(string, "SIODMY");
		if(gRaceStatus[raceId][mRaceEntrant2Place] == 8)
			strcat(string, "OSMY");
		if(gRaceStatus[raceId][mRaceEntrant2Place] == 9)
			strcat(string, "DZIEWIATY");
		if(gRaceStatus[raceId][mRaceEntrant2Place] == 10)
			strcat(string, "DZIESIATY");
		
		strcat(string, "~n~CZAS: ");		
		format(string, sizeof(string), "%s%d:", string, gRaceStatus[raceId][mRaceEntrant2Hour]);
		
		if(gRaceStatus[raceId][mRaceEntrant2Min] < 10)
			format(string, sizeof(string), "%s0%d:", string, gRaceStatus[raceId][mRaceEntrant2Min]);
		else
			format(string, sizeof(string), "%s%d:", string, gRaceStatus[raceId][mRaceEntrant2Min]);
		
		if(gRaceStatus[raceId][mRaceEntrant2Sec] < 10)
			format(string, sizeof(string), "%s0%d", string, gRaceStatus[raceId][mRaceEntrant2Sec]);
		else
			format(string, sizeof(string), "%s%d", string, gRaceStatus[raceId][mRaceEntrant2Sec]);
			
		GameTextForPlayer(gRaceStatus[raceId][mRaceEntrant2Id], string, 5000, 3);
	}
	else if(racerNo == 3)
	{
		if(gRaceStatus[raceId][mRaceEntrant3Place] == 1)
			strcat(string, "PIERWSZY");
		if(gRaceStatus[raceId][mRaceEntrant3Place] == 2)
			strcat(string, "DRUGI");
		if(gRaceStatus[raceId][mRaceEntrant3Place] == 3)
			strcat(string, "TRZECI");
		if(gRaceStatus[raceId][mRaceEntrant3Place] == 4)
			strcat(string, "CZWARTY");
		if(gRaceStatus[raceId][mRaceEntrant3Place] == 5)
			strcat(string, "PIATY");
		if(gRaceStatus[raceId][mRaceEntrant3Place] == 6)
			strcat(string, "SZOSTY");
		if(gRaceStatus[raceId][mRaceEntrant3Place] == 7)
			strcat(string, "SIODMY");
		if(gRaceStatus[raceId][mRaceEntrant3Place] == 8)
			strcat(string, "OSMY");
		if(gRaceStatus[raceId][mRaceEntrant3Place] == 9)
			strcat(string, "DZIEWIATY");
		if(gRaceStatus[raceId][mRaceEntrant3Place] == 10)
			strcat(string, "DZIESIATY");
		
		strcat(string, "~n~CZAS: ");		
		format(string, sizeof(string), "%s%d:", string, gRaceStatus[raceId][mRaceEntrant3Hour]);
		
		if(gRaceStatus[raceId][mRaceEntrant3Min] < 10)
			format(string, sizeof(string), "%s0%d:", string, gRaceStatus[raceId][mRaceEntrant3Min]);
		else
			format(string, sizeof(string), "%s%d:", string, gRaceStatus[raceId][mRaceEntrant3Min]);
		
		if(gRaceStatus[raceId][mRaceEntrant3Sec] < 10)
			format(string, sizeof(string), "%s0%d", string, gRaceStatus[raceId][mRaceEntrant3Sec]);
		else
			format(string, sizeof(string), "%s%d", string, gRaceStatus[raceId][mRaceEntrant3Sec]);
			
		GameTextForPlayer(gRaceStatus[raceId][mRaceEntrant3Id], string, 5000, 3);
	}
	else if(racerNo == 4)
	{
		if(gRaceStatus[raceId][mRaceEntrant4Place] == 1)
			strcat(string, "PIERWSZY");
		if(gRaceStatus[raceId][mRaceEntrant4Place] == 2)
			strcat(string, "DRUGI");
		if(gRaceStatus[raceId][mRaceEntrant4Place] == 3)
			strcat(string, "TRZECI");
		if(gRaceStatus[raceId][mRaceEntrant4Place] == 4)
			strcat(string, "CZWARTY");
		if(gRaceStatus[raceId][mRaceEntrant4Place] == 5)
			strcat(string, "PIATY");
		if(gRaceStatus[raceId][mRaceEntrant4Place] == 6)
			strcat(string, "SZOSTY");
		if(gRaceStatus[raceId][mRaceEntrant4Place] == 7)
			strcat(string, "SIODMY");
		if(gRaceStatus[raceId][mRaceEntrant4Place] == 8)
			strcat(string, "OSMY");
		if(gRaceStatus[raceId][mRaceEntrant4Place] == 9)
			strcat(string, "DZIEWIATY");
		if(gRaceStatus[raceId][mRaceEntrant4Place] == 10)
			strcat(string, "DZIESIATY");
		
		strcat(string, "~n~CZAS: ");		
		format(string, sizeof(string), "%s%d:", string, gRaceStatus[raceId][mRaceEntrant4Hour]);
		
		if(gRaceStatus[raceId][mRaceEntrant4Min] < 10)
			format(string, sizeof(string), "%s0%d:", string, gRaceStatus[raceId][mRaceEntrant4Min]);
		else
			format(string, sizeof(string), "%s%d:", string, gRaceStatus[raceId][mRaceEntrant4Min]);
		
		if(gRaceStatus[raceId][mRaceEntrant4Sec] < 10)
			format(string, sizeof(string), "%s0%d", string, gRaceStatus[raceId][mRaceEntrant4Sec]);
		else
			format(string, sizeof(string), "%s%d", string, gRaceStatus[raceId][mRaceEntrant4Sec]);
			
		GameTextForPlayer(gRaceStatus[raceId][mRaceEntrant4Id], string, 5000, 3);
	}
	else if(racerNo == 5)
	{
		if(gRaceStatus[raceId][mRaceEntrant5Place] == 1)
			strcat(string, "PIERWSZY");
		if(gRaceStatus[raceId][mRaceEntrant5Place] == 2)
			strcat(string, "DRUGI");
		if(gRaceStatus[raceId][mRaceEntrant5Place] == 3)
			strcat(string, "TRZECI");
		if(gRaceStatus[raceId][mRaceEntrant5Place] == 4)
			strcat(string, "CZWARTY");
		if(gRaceStatus[raceId][mRaceEntrant5Place] == 5)
			strcat(string, "PIATY");
		if(gRaceStatus[raceId][mRaceEntrant5Place] == 6)
			strcat(string, "SZOSTY");
		if(gRaceStatus[raceId][mRaceEntrant5Place] == 7)
			strcat(string, "SIODMY");
		if(gRaceStatus[raceId][mRaceEntrant5Place] == 8)
			strcat(string, "OSMY");
		if(gRaceStatus[raceId][mRaceEntrant5Place] == 9)
			strcat(string, "DZIEWIATY");
		if(gRaceStatus[raceId][mRaceEntrant5Place] == 10)
			strcat(string, "DZIESIATY");
		
		strcat(string, "~n~CZAS: ");		
		format(string, sizeof(string), "%s%d:", string, gRaceStatus[raceId][mRaceEntrant5Hour]);
		
		if(gRaceStatus[raceId][mRaceEntrant5Min] < 10)
			format(string, sizeof(string), "%s0%d:", string, gRaceStatus[raceId][mRaceEntrant5Min]);
		else
			format(string, sizeof(string), "%s%d:", string, gRaceStatus[raceId][mRaceEntrant5Min]);
		
		if(gRaceStatus[raceId][mRaceEntrant5Sec] < 10)
			format(string, sizeof(string), "%s0%d", string, gRaceStatus[raceId][mRaceEntrant5Sec]);
		else
			format(string, sizeof(string), "%s%d", string, gRaceStatus[raceId][mRaceEntrant5Sec]);
			
		GameTextForPlayer(gRaceStatus[raceId][mRaceEntrant5Id], string, 5000, 3);
	}
	else if(racerNo == 6)
	{
		if(gRaceStatus[raceId][mRaceEntrant6Place] == 1)
			strcat(string, "PIERWSZY");
		if(gRaceStatus[raceId][mRaceEntrant6Place] == 2)
			strcat(string, "DRUGI");
		if(gRaceStatus[raceId][mRaceEntrant6Place] == 3)
			strcat(string, "TRZECI");
		if(gRaceStatus[raceId][mRaceEntrant6Place] == 4)
			strcat(string, "CZWARTY");
		if(gRaceStatus[raceId][mRaceEntrant6Place] == 5)
			strcat(string, "PIATY");
		if(gRaceStatus[raceId][mRaceEntrant6Place] == 6)
			strcat(string, "SZOSTY");
		if(gRaceStatus[raceId][mRaceEntrant6Place] == 7)
			strcat(string, "SIODMY");
		if(gRaceStatus[raceId][mRaceEntrant6Place] == 8)
			strcat(string, "OSMY");
		if(gRaceStatus[raceId][mRaceEntrant6Place] == 9)
			strcat(string, "DZIEWIATY");
		if(gRaceStatus[raceId][mRaceEntrant6Place] == 10)
			strcat(string, "DZIESIATY");
		
		strcat(string, "~n~CZAS: ");		
		format(string, sizeof(string), "%s%d:", string, gRaceStatus[raceId][mRaceEntrant6Hour]);
		
		if(gRaceStatus[raceId][mRaceEntrant6Min] < 10)
			format(string, sizeof(string), "%s0%d:", string, gRaceStatus[raceId][mRaceEntrant6Min]);
		else
			format(string, sizeof(string), "%s%d:", string, gRaceStatus[raceId][mRaceEntrant6Min]);
		
		if(gRaceStatus[raceId][mRaceEntrant6Sec] < 10)
			format(string, sizeof(string), "%s0%d", string, gRaceStatus[raceId][mRaceEntrant6Sec]);
		else
			format(string, sizeof(string), "%s%d", string, gRaceStatus[raceId][mRaceEntrant6Sec]);
			
		GameTextForPlayer(gRaceStatus[raceId][mRaceEntrant6Id], string, 5000, 3);
	}
	else if(racerNo == 7)
	{
		if(gRaceStatus[raceId][mRaceEntrant7Place] == 1)
			strcat(string, "PIERWSZY");
		if(gRaceStatus[raceId][mRaceEntrant7Place] == 2)
			strcat(string, "DRUGI");
		if(gRaceStatus[raceId][mRaceEntrant7Place] == 3)
			strcat(string, "TRZECI");
		if(gRaceStatus[raceId][mRaceEntrant7Place] == 4)
			strcat(string, "CZWARTY");
		if(gRaceStatus[raceId][mRaceEntrant7Place] == 5)
			strcat(string, "PIATY");
		if(gRaceStatus[raceId][mRaceEntrant7Place] == 6)
			strcat(string, "SZOSTY");
		if(gRaceStatus[raceId][mRaceEntrant7Place] == 7)
			strcat(string, "SIODMY");
		if(gRaceStatus[raceId][mRaceEntrant7Place] == 8)
			strcat(string, "OSMY");
		if(gRaceStatus[raceId][mRaceEntrant7Place] == 9)
			strcat(string, "DZIEWIATY");
		if(gRaceStatus[raceId][mRaceEntrant7Place] == 10)
			strcat(string, "DZIESIATY");
		
		strcat(string, "~n~CZAS: ");		
		format(string, sizeof(string), "%s%d:", string, gRaceStatus[raceId][mRaceEntrant7Hour]);
		
		if(gRaceStatus[raceId][mRaceEntrant7Min] < 10)
			format(string, sizeof(string), "%s0%d:", string, gRaceStatus[raceId][mRaceEntrant7Min]);
		else
			format(string, sizeof(string), "%s%d:", string, gRaceStatus[raceId][mRaceEntrant7Min]);
		
		if(gRaceStatus[raceId][mRaceEntrant7Sec] < 10)
			format(string, sizeof(string), "%s0%d", string, gRaceStatus[raceId][mRaceEntrant7Sec]);
		else
			format(string, sizeof(string), "%s%d", string, gRaceStatus[raceId][mRaceEntrant7Sec]);
			
		GameTextForPlayer(gRaceStatus[raceId][mRaceEntrant7Id], string, 5000, 3);
	}
	else if(racerNo == 8)
	{
		if(gRaceStatus[raceId][mRaceEntrant8Place] == 1)
			strcat(string, "PIERWSZY");
		if(gRaceStatus[raceId][mRaceEntrant8Place] == 2)
			strcat(string, "DRUGI");
		if(gRaceStatus[raceId][mRaceEntrant8Place] == 3)
			strcat(string, "TRZECI");
		if(gRaceStatus[raceId][mRaceEntrant8Place] == 4)
			strcat(string, "CZWARTY");
		if(gRaceStatus[raceId][mRaceEntrant8Place] == 5)
			strcat(string, "PIATY");
		if(gRaceStatus[raceId][mRaceEntrant8Place] == 6)
			strcat(string, "SZOSTY");
		if(gRaceStatus[raceId][mRaceEntrant8Place] == 7)
			strcat(string, "SIODMY");
		if(gRaceStatus[raceId][mRaceEntrant8Place] == 8)
			strcat(string, "OSMY");
		if(gRaceStatus[raceId][mRaceEntrant8Place] == 9)
			strcat(string, "DZIEWIATY");
		if(gRaceStatus[raceId][mRaceEntrant8Place] == 10)
			strcat(string, "DZIESIATY");
		
		strcat(string, "~n~CZAS: ");		
		format(string, sizeof(string), "%s%d:", string, gRaceStatus[raceId][mRaceEntrant8Hour]);
		
		if(gRaceStatus[raceId][mRaceEntrant8Min] < 10)
			format(string, sizeof(string), "%s0%d:", string, gRaceStatus[raceId][mRaceEntrant8Min]);
		else
			format(string, sizeof(string), "%s%d:", string, gRaceStatus[raceId][mRaceEntrant8Min]);
		
		if(gRaceStatus[raceId][mRaceEntrant8Sec] < 10)
			format(string, sizeof(string), "%s0%d", string, gRaceStatus[raceId][mRaceEntrant8Sec]);
		else
			format(string, sizeof(string), "%s%d", string, gRaceStatus[raceId][mRaceEntrant8Sec]);
			
		GameTextForPlayer(gRaceStatus[raceId][mRaceEntrant8Id], string, 5000, 3);
	}
	else if(racerNo == 9)
	{
		if(gRaceStatus[raceId][mRaceEntrant9Place] == 1)
			strcat(string, "PIERWSZY");
		if(gRaceStatus[raceId][mRaceEntrant9Place] == 2)
			strcat(string, "DRUGI");
		if(gRaceStatus[raceId][mRaceEntrant9Place] == 3)
			strcat(string, "TRZECI");
		if(gRaceStatus[raceId][mRaceEntrant9Place] == 4)
			strcat(string, "CZWARTY");
		if(gRaceStatus[raceId][mRaceEntrant9Place] == 5)
			strcat(string, "PIATY");
		if(gRaceStatus[raceId][mRaceEntrant9Place] == 6)
			strcat(string, "SZOSTY");
		if(gRaceStatus[raceId][mRaceEntrant9Place] == 7)
			strcat(string, "SIODMY");
		if(gRaceStatus[raceId][mRaceEntrant9Place] == 8)
			strcat(string, "OSMY");
		if(gRaceStatus[raceId][mRaceEntrant9Place] == 9)
			strcat(string, "DZIEWIATY");
		if(gRaceStatus[raceId][mRaceEntrant9Place] == 10)
			strcat(string, "DZIESIATY");
		
		strcat(string, "~n~CZAS: ");		
		format(string, sizeof(string), "%s%d:", string, gRaceStatus[raceId][mRaceEntrant9Hour]);
		
		if(gRaceStatus[raceId][mRaceEntrant9Min] < 10)
			format(string, sizeof(string), "%s0%d:", string, gRaceStatus[raceId][mRaceEntrant9Min]);
		else
			format(string, sizeof(string), "%s%d:", string, gRaceStatus[raceId][mRaceEntrant9Min]);
		
		if(gRaceStatus[raceId][mRaceEntrant9Sec] < 10)
			format(string, sizeof(string), "%s0%d", string, gRaceStatus[raceId][mRaceEntrant9Sec]);
		else
			format(string, sizeof(string), "%s%d", string, gRaceStatus[raceId][mRaceEntrant9Sec]);
			
		GameTextForPlayer(gRaceStatus[raceId][mRaceEntrant9Id], string, 5000, 3);
	}
	else if(racerNo == 10)
	{
		if(gRaceStatus[raceId][mRaceEntrant10Place] == 1)
			strcat(string, "PIERWSZY");
		if(gRaceStatus[raceId][mRaceEntrant10Place] == 2)
			strcat(string, "DRUGI");
		if(gRaceStatus[raceId][mRaceEntrant10Place] == 3)
			strcat(string, "TRZECI");
		if(gRaceStatus[raceId][mRaceEntrant10Place] == 4)
			strcat(string, "CZWARTY");
		if(gRaceStatus[raceId][mRaceEntrant10Place] == 5)
			strcat(string, "PIATY");
		if(gRaceStatus[raceId][mRaceEntrant10Place] == 6)
			strcat(string, "SZOSTY");
		if(gRaceStatus[raceId][mRaceEntrant10Place] == 7)
			strcat(string, "SIODMY");
		if(gRaceStatus[raceId][mRaceEntrant10Place] == 8)
			strcat(string, "OSMY");
		if(gRaceStatus[raceId][mRaceEntrant10Place] == 9)
			strcat(string, "DZIEWIATY");
		if(gRaceStatus[raceId][mRaceEntrant10Place] == 10)
			strcat(string, "DZIESIATY");
		
		strcat(string, "~n~CZAS: ");		
		format(string, sizeof(string), "%s%d:", string, gRaceStatus[raceId][mRaceEntrant10Hour]);
		
		if(gRaceStatus[raceId][mRaceEntrant10Min] < 10)
			format(string, sizeof(string), "%s0%d:", string, gRaceStatus[raceId][mRaceEntrant10Min]);
		else
			format(string, sizeof(string), "%s%d:", string, gRaceStatus[raceId][mRaceEntrant10Min]);
		
		if(gRaceStatus[raceId][mRaceEntrant10Sec] < 10)
			format(string, sizeof(string), "%s0%d", string, gRaceStatus[raceId][mRaceEntrant10Sec]);
		else
			format(string, sizeof(string), "%s%d", string, gRaceStatus[raceId][mRaceEntrant10Sec]);
			
		GameTextForPlayer(gRaceStatus[raceId][mRaceEntrant10Id], string, 5000, 3);
	}
}

stock SaveRacerStats(raceId, racerNo)
{
	// TODO: fill this for other racers
	new string[512];
	if(racerNo == 1)
	{
		format(string, sizeof(string), "INSERT INTO `samp_races_tracks_hotlaps` (`Name` , `Time` , `RaceId`) VALUES ('%s' , IF(`Time` > MAKETIME(%d , %d , %d) OR `Time` = '00:00:00' , MAKETIME(%d, %d, %d), `Time`) , '%d') ON DUPLICATE KEY UPDATE `Time` = IF(`Time` > MAKETIME(%d, %d, %d) , MAKETIME(%d, %d, %d), `Time`)",
			gRaceStatus[raceId][mRaceEntrant1], gRaceStatus[raceId][mRaceEntrant1Hour], gRaceStatus[raceId][mRaceEntrant1Min], gRaceStatus[raceId][mRaceEntrant1Sec],
			gRaceStatus[raceId][mRaceEntrant1Hour], gRaceStatus[raceId][mRaceEntrant1Min], gRaceStatus[raceId][mRaceEntrant1Sec],
			gRaceStatus[raceId][mRaceId], 
			gRaceStatus[raceId][mRaceEntrant1Hour], gRaceStatus[raceId][mRaceEntrant1Min], gRaceStatus[raceId][mRaceEntrant1Sec],
			gRaceStatus[raceId][mRaceEntrant1Hour], gRaceStatus[raceId][mRaceEntrant1Min], gRaceStatus[raceId][mRaceEntrant1Sec]
		);
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
	}
}

stock RefreshRaceStandings(raceId)
{
	new string[64];
	if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 1 && gRaceStatus[raceId][mRaceEntrant1Id] != -1)
	{
		if(gRaceStatus[raceId][mRaceEntrant1Status] == PLAYER_RACE_STATE_FINISHED)
			format(string, sizeof(string), "%d. %s UKONCZYL", gRaceStatus[raceId][mRaceEntrant1Place], gRaceStatus[raceId][mRaceEntrant1]);
		else if(gRaceStatus[raceId][mRaceEntrant1Status] == PLAYER_RACE_STATE_LEFT)
			format(string, sizeof(string), "%d. %s OPUSCIL", gRaceStatus[raceId][mRaceEntrant1Place], gRaceStatus[raceId][mRaceEntrant1]);	
		else if(gRaceStatus[raceId][mRaceEntrant1Status] == PLAYER_RACE_STATE_CONNECTED)
			format(string, sizeof(string), "%d. %s %d m", gRaceStatus[raceId][mRaceEntrant1Place], gRaceStatus[raceId][mRaceEntrant1], floatround(gRaceStatus[raceId][mRaceEntrant1DistanceLeft]));
		
		TextDrawDestroy(gPlayerVars[gRaceStatus[raceId][mRaceEntrant1Id]][mRacePlace1Info]);
		gPlayerVars[gRaceStatus[raceId][mRaceEntrant1Id]][mRacePlace1Info] = TextDrawCreate(570.0, 230.0+(gRaceStatus[raceId][mRaceEntrant1Place]*10), string);
		TextDrawLetterSize(gPlayerVars[gRaceStatus[raceId][mRaceEntrant1Id]][mRacePlace1Info], 0.15, 0.6);
		TextDrawTextSize(gPlayerVars[gRaceStatus[raceId][mRaceEntrant1Id]][mRacePlace1Info], 150.0, 50.0);
		TextDrawAlignment(gPlayerVars[gRaceStatus[raceId][mRaceEntrant1Id]][mRacePlace1Info], 3);
	}
	if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 2 && gRaceStatus[raceId][mRaceEntrant2Id] != -1)
	{
		if(gRaceStatus[raceId][mRaceEntrant2Status] == PLAYER_RACE_STATE_FINISHED)
			format(string, sizeof(string), "%d. %s UKONCZYL", gRaceStatus[raceId][mRaceEntrant2Place], gRaceStatus[raceId][mRaceEntrant2]);
		else if(gRaceStatus[raceId][mRaceEntrant2Status] == PLAYER_RACE_STATE_LEFT)
			format(string, sizeof(string), "%d. %s OPUSCIL", gRaceStatus[raceId][mRaceEntrant2Place], gRaceStatus[raceId][mRaceEntrant2]);	
		else if(gRaceStatus[raceId][mRaceEntrant2Status] == PLAYER_RACE_STATE_CONNECTED)
			format(string, sizeof(string), "%d. %s %d m", gRaceStatus[raceId][mRaceEntrant2Place], gRaceStatus[raceId][mRaceEntrant2], floatround(gRaceStatus[raceId][mRaceEntrant2DistanceLeft]));
		
		TextDrawDestroy(gPlayerVars[gRaceStatus[raceId][mRaceEntrant2Id]][mRacePlace2Info]);
		gPlayerVars[gRaceStatus[raceId][mRaceEntrant2Id]][mRacePlace2Info] = TextDrawCreate(570.0, 230.0+(gRaceStatus[raceId][mRaceEntrant2Place]*10), string);
		TextDrawLetterSize(gPlayerVars[gRaceStatus[raceId][mRaceEntrant2Id]][mRacePlace2Info], 0.15, 0.6);
		TextDrawTextSize(gPlayerVars[gRaceStatus[raceId][mRaceEntrant2Id]][mRacePlace2Info], 200.0, 50.0);
		TextDrawAlignment(gPlayerVars[gRaceStatus[raceId][mRaceEntrant2Id]][mRacePlace2Info], 3);
	}
	if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 3 && gRaceStatus[raceId][mRaceEntrant3Id] != -1)
	{
		if(gRaceStatus[raceId][mRaceEntrant3Status] == PLAYER_RACE_STATE_FINISHED)
			format(string, sizeof(string), "%d. %s UKONCZYL", gRaceStatus[raceId][mRaceEntrant3Place], gRaceStatus[raceId][mRaceEntrant3]);
		else if(gRaceStatus[raceId][mRaceEntrant3Status] == PLAYER_RACE_STATE_LEFT)
			format(string, sizeof(string), "%d. %s OPUSCIL", gRaceStatus[raceId][mRaceEntrant3Place], gRaceStatus[raceId][mRaceEntrant3]);	
		else if(gRaceStatus[raceId][mRaceEntrant3Status] == PLAYER_RACE_STATE_CONNECTED)
			format(string, sizeof(string), "%d. %s %d m", gRaceStatus[raceId][mRaceEntrant3Place], gRaceStatus[raceId][mRaceEntrant3], floatround(gRaceStatus[raceId][mRaceEntrant3DistanceLeft]));
		
		TextDrawDestroy(gPlayerVars[gRaceStatus[raceId][mRaceEntrant3Id]][mRacePlace3Info]);
		gPlayerVars[gRaceStatus[raceId][mRaceEntrant3Id]][mRacePlace3Info] = TextDrawCreate(570.0, 230.0+(gRaceStatus[raceId][mRaceEntrant3Place]*10), string);
		TextDrawLetterSize(gPlayerVars[gRaceStatus[raceId][mRaceEntrant3Id]][mRacePlace3Info], 0.15, 0.6);
		TextDrawTextSize(gPlayerVars[gRaceStatus[raceId][mRaceEntrant3Id]][mRacePlace3Info], 200.0, 50.0);
		TextDrawAlignment(gPlayerVars[gRaceStatus[raceId][mRaceEntrant3Id]][mRacePlace3Info], 3);
	}
	if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 4 && gRaceStatus[raceId][mRaceEntrant4Id] != -1)
	{
		if(gRaceStatus[raceId][mRaceEntrant4Status] == PLAYER_RACE_STATE_FINISHED)
			format(string, sizeof(string), "%d. %s UKONCZYL", gRaceStatus[raceId][mRaceEntrant4Place], gRaceStatus[raceId][mRaceEntrant4]);
		else if(gRaceStatus[raceId][mRaceEntrant4Status] == PLAYER_RACE_STATE_LEFT)
			format(string, sizeof(string), "%d. %s OPUSCIL", gRaceStatus[raceId][mRaceEntrant4Place], gRaceStatus[raceId][mRaceEntrant4]);	
		else if(gRaceStatus[raceId][mRaceEntrant4Status] == PLAYER_RACE_STATE_CONNECTED)
			format(string, sizeof(string), "%d. %s %d m", gRaceStatus[raceId][mRaceEntrant4Place], gRaceStatus[raceId][mRaceEntrant4], floatround(gRaceStatus[raceId][mRaceEntrant4DistanceLeft]));
		
		TextDrawDestroy(gPlayerVars[gRaceStatus[raceId][mRaceEntrant4Id]][mRacePlace4Info]);
		gPlayerVars[gRaceStatus[raceId][mRaceEntrant4Id]][mRacePlace4Info] = TextDrawCreate(570.0, 230.0+(gRaceStatus[raceId][mRaceEntrant4Place]*10), string);
		TextDrawLetterSize(gPlayerVars[gRaceStatus[raceId][mRaceEntrant4Id]][mRacePlace4Info], 0.15, 0.6);
		TextDrawTextSize(gPlayerVars[gRaceStatus[raceId][mRaceEntrant4Id]][mRacePlace4Info], 200.0, 50.0);
		TextDrawAlignment(gPlayerVars[gRaceStatus[raceId][mRaceEntrant4Id]][mRacePlace4Info], 3);
	}
	if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 5 && gRaceStatus[raceId][mRaceEntrant5Id] != -1)
	{
		if(gRaceStatus[raceId][mRaceEntrant5Status] == PLAYER_RACE_STATE_FINISHED)
			format(string, sizeof(string), "%d. %s UKONCZYL", gRaceStatus[raceId][mRaceEntrant5Place], gRaceStatus[raceId][mRaceEntrant5]);
		else if(gRaceStatus[raceId][mRaceEntrant5Status] == PLAYER_RACE_STATE_LEFT)
			format(string, sizeof(string), "%d. %s OPUSCIL", gRaceStatus[raceId][mRaceEntrant5Place], gRaceStatus[raceId][mRaceEntrant5]);	
		else if(gRaceStatus[raceId][mRaceEntrant5Status] == PLAYER_RACE_STATE_CONNECTED)
			format(string, sizeof(string), "%d. %s %d m", gRaceStatus[raceId][mRaceEntrant5Place], gRaceStatus[raceId][mRaceEntrant5], floatround(gRaceStatus[raceId][mRaceEntrant5DistanceLeft]));
		
		TextDrawDestroy(gPlayerVars[gRaceStatus[raceId][mRaceEntrant5Id]][mRacePlace5Info]);
		gPlayerVars[gRaceStatus[raceId][mRaceEntrant5Id]][mRacePlace5Info] = TextDrawCreate(570.0, 230.0+(gRaceStatus[raceId][mRaceEntrant5Place]*10), string);
		TextDrawLetterSize(gPlayerVars[gRaceStatus[raceId][mRaceEntrant5Id]][mRacePlace5Info], 0.15, 0.6);
		TextDrawTextSize(gPlayerVars[gRaceStatus[raceId][mRaceEntrant5Id]][mRacePlace5Info], 200.0, 50.0);
		TextDrawAlignment(gPlayerVars[gRaceStatus[raceId][mRaceEntrant5Id]][mRacePlace5Info], 3);
	}
	if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 6 && gRaceStatus[raceId][mRaceEntrant6Id] != -1)
	{
		if(gRaceStatus[raceId][mRaceEntrant6Status] == PLAYER_RACE_STATE_FINISHED)
			format(string, sizeof(string), "%d. %s UKONCZYL", gRaceStatus[raceId][mRaceEntrant6Place], gRaceStatus[raceId][mRaceEntrant6]);
		else if(gRaceStatus[raceId][mRaceEntrant6Status] == PLAYER_RACE_STATE_LEFT)
			format(string, sizeof(string), "%d. %s OPUSCIL", gRaceStatus[raceId][mRaceEntrant6Place], gRaceStatus[raceId][mRaceEntrant6]);	
		else if(gRaceStatus[raceId][mRaceEntrant6Status] == PLAYER_RACE_STATE_CONNECTED)
			format(string, sizeof(string), "%d. %s %d m", gRaceStatus[raceId][mRaceEntrant6Place], gRaceStatus[raceId][mRaceEntrant6], floatround(gRaceStatus[raceId][mRaceEntrant6DistanceLeft]));
			
		TextDrawDestroy(gPlayerVars[gRaceStatus[raceId][mRaceEntrant6Id]][mRacePlace6Info]);
		gPlayerVars[gRaceStatus[raceId][mRaceEntrant6Id]][mRacePlace6Info] = TextDrawCreate(570.0, 230.0+(gRaceStatus[raceId][mRaceEntrant6Place]*10), string);
		TextDrawLetterSize(gPlayerVars[gRaceStatus[raceId][mRaceEntrant6Id]][mRacePlace6Info], 0.15, 0.6);
		TextDrawTextSize(gPlayerVars[gRaceStatus[raceId][mRaceEntrant6Id]][mRacePlace6Info], 200.0, 50.0);
		TextDrawAlignment(gPlayerVars[gRaceStatus[raceId][mRaceEntrant6Id]][mRacePlace6Info], 3);
	}
	if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 7 && gRaceStatus[raceId][mRaceEntrant7Id] != -1)
	{
		if(gRaceStatus[raceId][mRaceEntrant7Status] == PLAYER_RACE_STATE_FINISHED)
			format(string, sizeof(string), "%d. %s UKONCZYL", gRaceStatus[raceId][mRaceEntrant7Place], gRaceStatus[raceId][mRaceEntrant7]);
		else if(gRaceStatus[raceId][mRaceEntrant7Status] == PLAYER_RACE_STATE_LEFT)
			format(string, sizeof(string), "%d. %s OPUSCIL", gRaceStatus[raceId][mRaceEntrant7Place], gRaceStatus[raceId][mRaceEntrant7]);	
		else if(gRaceStatus[raceId][mRaceEntrant7Status] == PLAYER_RACE_STATE_CONNECTED)
			format(string, sizeof(string), "%d. %s %d m", gRaceStatus[raceId][mRaceEntrant7Place], gRaceStatus[raceId][mRaceEntrant7], floatround(gRaceStatus[raceId][mRaceEntrant7DistanceLeft]));
		
		TextDrawDestroy(gPlayerVars[gRaceStatus[raceId][mRaceEntrant7Id]][mRacePlace7Info]);
		gPlayerVars[gRaceStatus[raceId][mRaceEntrant7Id]][mRacePlace7Info] = TextDrawCreate(570.0, 230.0+(gRaceStatus[raceId][mRaceEntrant7Place]*10), string);
		TextDrawLetterSize(gPlayerVars[gRaceStatus[raceId][mRaceEntrant7Id]][mRacePlace7Info], 0.15, 0.6);
		TextDrawTextSize(gPlayerVars[gRaceStatus[raceId][mRaceEntrant7Id]][mRacePlace7Info], 200.0, 50.0);
		TextDrawAlignment(gPlayerVars[gRaceStatus[raceId][mRaceEntrant7Id]][mRacePlace7Info], 3);
	}
	if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 8 && gRaceStatus[raceId][mRaceEntrant8Id] != -1)
	{
		if(gRaceStatus[raceId][mRaceEntrant8Status] == PLAYER_RACE_STATE_FINISHED)
			format(string, sizeof(string), "%d. %s UKONCZYL", gRaceStatus[raceId][mRaceEntrant8Place], gRaceStatus[raceId][mRaceEntrant8]);
		else if(gRaceStatus[raceId][mRaceEntrant8Status] == PLAYER_RACE_STATE_LEFT)
			format(string, sizeof(string), "%d. %s OPUSCIL", gRaceStatus[raceId][mRaceEntrant8Place], gRaceStatus[raceId][mRaceEntrant8]);	
		else if(gRaceStatus[raceId][mRaceEntrant8Status] == PLAYER_RACE_STATE_CONNECTED)
			format(string, sizeof(string), "%d. %s %d m", gRaceStatus[raceId][mRaceEntrant8Place], gRaceStatus[raceId][mRaceEntrant8], floatround(gRaceStatus[raceId][mRaceEntrant8DistanceLeft]));
		
		TextDrawDestroy(gPlayerVars[gRaceStatus[raceId][mRaceEntrant8Id]][mRacePlace8Info]);
		gPlayerVars[gRaceStatus[raceId][mRaceEntrant8Id]][mRacePlace8Info] = TextDrawCreate(570.0, 230.0+(gRaceStatus[raceId][mRaceEntrant8Place]*10), string);
		TextDrawLetterSize(gPlayerVars[gRaceStatus[raceId][mRaceEntrant8Id]][mRacePlace8Info], 0.15, 0.6);
		TextDrawTextSize(gPlayerVars[gRaceStatus[raceId][mRaceEntrant8Id]][mRacePlace8Info], 200.0, 50.0);
		TextDrawAlignment(gPlayerVars[gRaceStatus[raceId][mRaceEntrant8Id]][mRacePlace8Info], 3);
	}
	if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 9 && gRaceStatus[raceId][mRaceEntrant9Id] != -1)
	{
		if(gRaceStatus[raceId][mRaceEntrant9Status] == PLAYER_RACE_STATE_FINISHED)
			format(string, sizeof(string), "%d. %s UKONCZYL", gRaceStatus[raceId][mRaceEntrant9Place], gRaceStatus[raceId][mRaceEntrant9]);
		else if(gRaceStatus[raceId][mRaceEntrant9Status] == PLAYER_RACE_STATE_LEFT)
			format(string, sizeof(string), "%d. %s OPUSCIL", gRaceStatus[raceId][mRaceEntrant9Place], gRaceStatus[raceId][mRaceEntrant9]);	
		else if(gRaceStatus[raceId][mRaceEntrant9Status] == PLAYER_RACE_STATE_CONNECTED)
			format(string, sizeof(string), "%d. %s %d m", gRaceStatus[raceId][mRaceEntrant9Place], gRaceStatus[raceId][mRaceEntrant9], floatround(gRaceStatus[raceId][mRaceEntrant9DistanceLeft]));
			
		TextDrawDestroy(gPlayerVars[gRaceStatus[raceId][mRaceEntrant9Id]][mRacePlace9Info]);
		gPlayerVars[gRaceStatus[raceId][mRaceEntrant9Id]][mRacePlace9Info] = TextDrawCreate(570.0, 230.0+(gRaceStatus[raceId][mRaceEntrant9Place]*10), string);
		TextDrawLetterSize(gPlayerVars[gRaceStatus[raceId][mRaceEntrant9Id]][mRacePlace9Info], 0.15, 0.6);
		TextDrawTextSize(gPlayerVars[gRaceStatus[raceId][mRaceEntrant9Id]][mRacePlace9Info], 200.0, 50.0);
		TextDrawAlignment(gPlayerVars[gRaceStatus[raceId][mRaceEntrant9Id]][mRacePlace9Info], 3);
	}
	if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 10 && gRaceStatus[raceId][mRaceEntrant10Id] != -1)
	{
		if(gRaceStatus[raceId][mRaceEntrant10Status] == PLAYER_RACE_STATE_FINISHED)
			format(string, sizeof(string), "%d. %s UKONCZYL", gRaceStatus[raceId][mRaceEntrant10Place], gRaceStatus[raceId][mRaceEntrant10]);
		else if(gRaceStatus[raceId][mRaceEntrant10Status] == PLAYER_RACE_STATE_LEFT)
			format(string, sizeof(string), "%d. %s OPUSCIL", gRaceStatus[raceId][mRaceEntrant10Place], gRaceStatus[raceId][mRaceEntrant10]);	
		else if(gRaceStatus[raceId][mRaceEntrant10Status] == PLAYER_RACE_STATE_CONNECTED)
			format(string, sizeof(string), "%d. %s %d m", gRaceStatus[raceId][mRaceEntrant10Place], gRaceStatus[raceId][mRaceEntrant10], floatround(gRaceStatus[raceId][mRaceEntrant10DistanceLeft]));
			
		TextDrawSetString(gPlayerVars[gRaceStatus[raceId][mRaceEntrant10Id]][mRacePlace10Info], string);
		TextDrawDestroy(gPlayerVars[gRaceStatus[raceId][mRaceEntrant10Id]][mRacePlace10Info]);
		gPlayerVars[gRaceStatus[raceId][mRaceEntrant10Id]][mRacePlace10Info] = TextDrawCreate(570.0, 230.0+(gRaceStatus[raceId][mRaceEntrant10Place]*10), string);
		TextDrawLetterSize(gPlayerVars[gRaceStatus[raceId][mRaceEntrant10Id]][mRacePlace10Info], 0.15, 0.6);
		TextDrawTextSize(gPlayerVars[gRaceStatus[raceId][mRaceEntrant10Id]][mRacePlace10Info], 200.0, 50.0);
		TextDrawAlignment(gPlayerVars[gRaceStatus[raceId][mRaceEntrant10Id]][mRacePlace10Info], 3);
	}
	
	if(gRaceStatus[raceId][mRaceEntrant1Status] == PLAYER_RACE_STATE_CONNECTED || gRaceStatus[raceId][mRaceEntrant1Status] == PLAYER_RACE_STATE_FINISHED)
	{
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 1 && gRaceStatus[raceId][mRaceEntrant1Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant1Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant1Id]][mRacePlace1Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 2 && gRaceStatus[raceId][mRaceEntrant2Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant1Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant2Id]][mRacePlace2Info]);

		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 3 && gRaceStatus[raceId][mRaceEntrant3Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant1Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant3Id]][mRacePlace3Info]);

		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 4 && gRaceStatus[raceId][mRaceEntrant4Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant1Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant4Id]][mRacePlace4Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 5 && gRaceStatus[raceId][mRaceEntrant5Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant1Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant5Id]][mRacePlace5Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 6 && gRaceStatus[raceId][mRaceEntrant6Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant1Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant6Id]][mRacePlace6Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 7 && gRaceStatus[raceId][mRaceEntrant7Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant1Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant7Id]][mRacePlace7Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 8 && gRaceStatus[raceId][mRaceEntrant8Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant1Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant8Id]][mRacePlace8Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 9 && gRaceStatus[raceId][mRaceEntrant9Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant1Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant9Id]][mRacePlace9Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 10 && gRaceStatus[raceId][mRaceEntrant10Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant1Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant10Id]][mRacePlace10Info]);
	}
	if(gRaceStatus[raceId][mRaceEntrant2Status] == PLAYER_RACE_STATE_CONNECTED || gRaceStatus[raceId][mRaceEntrant2Status] == PLAYER_RACE_STATE_FINISHED)
	{
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 1 && gRaceStatus[raceId][mRaceEntrant1Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant2Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant1Id]][mRacePlace1Info]);
			
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 2 && gRaceStatus[raceId][mRaceEntrant2Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant2Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant2Id]][mRacePlace2Info]);	
			
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 3 && gRaceStatus[raceId][mRaceEntrant3Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant2Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant3Id]][mRacePlace3Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 4 && gRaceStatus[raceId][mRaceEntrant4Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant2Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant4Id]][mRacePlace4Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 5 && gRaceStatus[raceId][mRaceEntrant5Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant2Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant5Id]][mRacePlace5Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 6 && gRaceStatus[raceId][mRaceEntrant6Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant2Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant6Id]][mRacePlace6Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 7 && gRaceStatus[raceId][mRaceEntrant7Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant2Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant7Id]][mRacePlace7Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 8 && gRaceStatus[raceId][mRaceEntrant8Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant2Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant8Id]][mRacePlace8Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 9 && gRaceStatus[raceId][mRaceEntrant9Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant2Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant9Id]][mRacePlace9Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 10 && gRaceStatus[raceId][mRaceEntrant10Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant2Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant10Id]][mRacePlace10Info]);
	}
	if(gRaceStatus[raceId][mRaceEntrant3Status] == PLAYER_RACE_STATE_CONNECTED || gRaceStatus[raceId][mRaceEntrant3Status] == PLAYER_RACE_STATE_FINISHED)
	{
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 1 && gRaceStatus[raceId][mRaceEntrant1Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant3Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant1Id]][mRacePlace1Info]);
			
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 2 && gRaceStatus[raceId][mRaceEntrant2Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant3Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant2Id]][mRacePlace2Info]);	
			
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 3 && gRaceStatus[raceId][mRaceEntrant3Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant3Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant3Id]][mRacePlace3Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 4 && gRaceStatus[raceId][mRaceEntrant4Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant3Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant4Id]][mRacePlace4Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 5 && gRaceStatus[raceId][mRaceEntrant5Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant3Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant5Id]][mRacePlace5Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 6 && gRaceStatus[raceId][mRaceEntrant6Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant3Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant6Id]][mRacePlace6Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 7 && gRaceStatus[raceId][mRaceEntrant7Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant3Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant7Id]][mRacePlace7Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 8 && gRaceStatus[raceId][mRaceEntrant8Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant3Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant8Id]][mRacePlace8Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 9 && gRaceStatus[raceId][mRaceEntrant9Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant3Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant9Id]][mRacePlace9Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 10 && gRaceStatus[raceId][mRaceEntrant10Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant3Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant10Id]][mRacePlace10Info]);
	}
	if(gRaceStatus[raceId][mRaceEntrant4Status] == PLAYER_RACE_STATE_CONNECTED || gRaceStatus[raceId][mRaceEntrant4Status] == PLAYER_RACE_STATE_FINISHED)
	{
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 1 && gRaceStatus[raceId][mRaceEntrant1Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant4Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant1Id]][mRacePlace1Info]);
			
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 2 && gRaceStatus[raceId][mRaceEntrant2Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant4Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant2Id]][mRacePlace2Info]);	
			
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 3 && gRaceStatus[raceId][mRaceEntrant3Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant4Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant3Id]][mRacePlace3Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 4 && gRaceStatus[raceId][mRaceEntrant4Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant4Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant4Id]][mRacePlace4Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 5 && gRaceStatus[raceId][mRaceEntrant5Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant4Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant5Id]][mRacePlace5Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 6 && gRaceStatus[raceId][mRaceEntrant6Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant4Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant6Id]][mRacePlace6Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 7 && gRaceStatus[raceId][mRaceEntrant7Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant4Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant7Id]][mRacePlace7Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 8 && gRaceStatus[raceId][mRaceEntrant8Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant4Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant8Id]][mRacePlace8Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 9 && gRaceStatus[raceId][mRaceEntrant9Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant4Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant9Id]][mRacePlace9Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 10 && gRaceStatus[raceId][mRaceEntrant10Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant4Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant10Id]][mRacePlace10Info]);
	}
	if(gRaceStatus[raceId][mRaceEntrant5Status] == PLAYER_RACE_STATE_CONNECTED || gRaceStatus[raceId][mRaceEntrant5Status] == PLAYER_RACE_STATE_FINISHED)
	{
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 1 && gRaceStatus[raceId][mRaceEntrant1Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant5Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant1Id]][mRacePlace1Info]);
			
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 2 && gRaceStatus[raceId][mRaceEntrant2Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant5Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant2Id]][mRacePlace2Info]);	
			
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 3 && gRaceStatus[raceId][mRaceEntrant3Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant5Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant3Id]][mRacePlace3Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 4 && gRaceStatus[raceId][mRaceEntrant4Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant5Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant4Id]][mRacePlace4Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 5 && gRaceStatus[raceId][mRaceEntrant5Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant5Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant5Id]][mRacePlace5Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 6 && gRaceStatus[raceId][mRaceEntrant6Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant5Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant6Id]][mRacePlace6Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 7 && gRaceStatus[raceId][mRaceEntrant7Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant5Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant7Id]][mRacePlace7Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 8 && gRaceStatus[raceId][mRaceEntrant8Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant5Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant8Id]][mRacePlace8Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 9 && gRaceStatus[raceId][mRaceEntrant9Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant5Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant9Id]][mRacePlace9Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 10 && gRaceStatus[raceId][mRaceEntrant10Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant5Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant10Id]][mRacePlace10Info]);
	}
	if(gRaceStatus[raceId][mRaceEntrant6Status] == PLAYER_RACE_STATE_CONNECTED || gRaceStatus[raceId][mRaceEntrant6Status] == PLAYER_RACE_STATE_FINISHED)
	{
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 1 && gRaceStatus[raceId][mRaceEntrant1Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant6Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant1Id]][mRacePlace1Info]);
			
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 2 && gRaceStatus[raceId][mRaceEntrant2Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant6Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant2Id]][mRacePlace2Info]);	
			
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 3 && gRaceStatus[raceId][mRaceEntrant3Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant6Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant3Id]][mRacePlace3Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 4 && gRaceStatus[raceId][mRaceEntrant4Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant6Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant4Id]][mRacePlace4Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 5 && gRaceStatus[raceId][mRaceEntrant5Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant6Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant5Id]][mRacePlace5Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 6 && gRaceStatus[raceId][mRaceEntrant6Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant6Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant6Id]][mRacePlace6Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 7 && gRaceStatus[raceId][mRaceEntrant7Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant6Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant7Id]][mRacePlace7Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 8 && gRaceStatus[raceId][mRaceEntrant8Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant6Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant8Id]][mRacePlace8Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 9 && gRaceStatus[raceId][mRaceEntrant9Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant6Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant9Id]][mRacePlace9Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 10 && gRaceStatus[raceId][mRaceEntrant10Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant6Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant10Id]][mRacePlace10Info]);
	}
	if(gRaceStatus[raceId][mRaceEntrant7Status] == PLAYER_RACE_STATE_CONNECTED || gRaceStatus[raceId][mRaceEntrant7Status] == PLAYER_RACE_STATE_FINISHED)
	{
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 1 && gRaceStatus[raceId][mRaceEntrant1Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant7Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant1Id]][mRacePlace1Info]);
			
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 2 && gRaceStatus[raceId][mRaceEntrant2Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant7Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant2Id]][mRacePlace2Info]);	
			
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 3 && gRaceStatus[raceId][mRaceEntrant3Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant7Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant3Id]][mRacePlace3Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 4 && gRaceStatus[raceId][mRaceEntrant4Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant7Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant4Id]][mRacePlace4Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 5 && gRaceStatus[raceId][mRaceEntrant5Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant7Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant5Id]][mRacePlace5Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 6 && gRaceStatus[raceId][mRaceEntrant6Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant7Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant6Id]][mRacePlace6Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 7 && gRaceStatus[raceId][mRaceEntrant7Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant7Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant7Id]][mRacePlace7Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 8 && gRaceStatus[raceId][mRaceEntrant8Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant7Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant8Id]][mRacePlace8Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 9 && gRaceStatus[raceId][mRaceEntrant9Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant7Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant9Id]][mRacePlace9Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 10 && gRaceStatus[raceId][mRaceEntrant10Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant7Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant10Id]][mRacePlace10Info]);
	}
	if(gRaceStatus[raceId][mRaceEntrant8Status] == PLAYER_RACE_STATE_CONNECTED || gRaceStatus[raceId][mRaceEntrant8Status] == PLAYER_RACE_STATE_FINISHED)
	{
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 1 && gRaceStatus[raceId][mRaceEntrant1Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant8Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant1Id]][mRacePlace1Info]);
			
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 2 && gRaceStatus[raceId][mRaceEntrant2Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant8Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant2Id]][mRacePlace2Info]);	
			
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 3 && gRaceStatus[raceId][mRaceEntrant3Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant8Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant3Id]][mRacePlace3Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 4 && gRaceStatus[raceId][mRaceEntrant4Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant8Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant4Id]][mRacePlace4Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 5 && gRaceStatus[raceId][mRaceEntrant5Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant8Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant5Id]][mRacePlace5Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 6 && gRaceStatus[raceId][mRaceEntrant6Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant8Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant6Id]][mRacePlace6Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 7 && gRaceStatus[raceId][mRaceEntrant7Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant8Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant7Id]][mRacePlace7Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 8 && gRaceStatus[raceId][mRaceEntrant8Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant8Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant8Id]][mRacePlace8Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 9 && gRaceStatus[raceId][mRaceEntrant9Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant8Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant9Id]][mRacePlace9Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 10 && gRaceStatus[raceId][mRaceEntrant10Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant8Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant10Id]][mRacePlace10Info]);
	}
	if(gRaceStatus[raceId][mRaceEntrant9Status] == PLAYER_RACE_STATE_CONNECTED || gRaceStatus[raceId][mRaceEntrant9Status] == PLAYER_RACE_STATE_FINISHED)
	{
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 1 && gRaceStatus[raceId][mRaceEntrant1Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant9Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant1Id]][mRacePlace1Info]);
			
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 2 && gRaceStatus[raceId][mRaceEntrant2Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant9Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant2Id]][mRacePlace2Info]);	
			
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 3 && gRaceStatus[raceId][mRaceEntrant3Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant9Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant3Id]][mRacePlace3Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 4 && gRaceStatus[raceId][mRaceEntrant4Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant9Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant4Id]][mRacePlace4Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 5 && gRaceStatus[raceId][mRaceEntrant5Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant9Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant5Id]][mRacePlace5Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 6 && gRaceStatus[raceId][mRaceEntrant6Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant9Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant6Id]][mRacePlace6Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 7 && gRaceStatus[raceId][mRaceEntrant7Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant9Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant7Id]][mRacePlace7Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 8 && gRaceStatus[raceId][mRaceEntrant8Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant9Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant8Id]][mRacePlace8Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 9 && gRaceStatus[raceId][mRaceEntrant9Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant9Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant9Id]][mRacePlace9Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 10 && gRaceStatus[raceId][mRaceEntrant10Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant9Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant10Id]][mRacePlace10Info]);
	}
	if(gRaceStatus[raceId][mRaceEntrant10Status] == PLAYER_RACE_STATE_CONNECTED || gRaceStatus[raceId][mRaceEntrant10Status] == PLAYER_RACE_STATE_FINISHED)
	{
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 1 && gRaceStatus[raceId][mRaceEntrant1Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant10Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant1Id]][mRacePlace1Info]);
			
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 2 && gRaceStatus[raceId][mRaceEntrant2Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant10Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant2Id]][mRacePlace2Info]);	
			
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 3 && gRaceStatus[raceId][mRaceEntrant3Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant10Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant3Id]][mRacePlace3Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 4 && gRaceStatus[raceId][mRaceEntrant4Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant10Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant4Id]][mRacePlace4Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 5 && gRaceStatus[raceId][mRaceEntrant5Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant10Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant5Id]][mRacePlace5Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 6 && gRaceStatus[raceId][mRaceEntrant6Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant10Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant6Id]][mRacePlace6Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 7 && gRaceStatus[raceId][mRaceEntrant7Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant10Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant7Id]][mRacePlace7Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 8 && gRaceStatus[raceId][mRaceEntrant8Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant10Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant8Id]][mRacePlace8Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 9 && gRaceStatus[raceId][mRaceEntrant9Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant10Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant9Id]][mRacePlace9Info]);
		
		if(gRaceTrackStartPosCount[gRaceStatus[raceId][mRaceId]] >= 10 && gRaceStatus[raceId][mRaceEntrant10Id] != -1)
			TextDrawShowForPlayer(gRaceStatus[raceId][mRaceEntrant10Id], gPlayerVars[gRaceStatus[raceId][mRaceEntrant10Id]][mRacePlace10Info]);
	}	
}

stock Float:CalculateTrackLenght(raceId)
{
	new Float:distance;
	
	for(new nextCpId = 0; nextCpId < MAX_RACES_CP-1; nextCpId++)
	{
		if(gRaceTrackCpType[raceId][nextCpId+1] == RACE_CP_TYPE_NONE)
			break;
		distance += floatsqroot(floatpower(floatabs(floatsub(gRaceTrackCpX[raceId][nextCpId],  gRaceTrackCpX[raceId][nextCpId+1])), 2)+floatpower(floatabs(floatsub(gRaceTrackCpY[raceId][nextCpId], gRaceTrackCpY[raceId][nextCpId+1])), 2)+floatpower(floatabs(floatsub(gRaceTrackCpZ[raceId][nextCpId], gRaceTrackCpZ[raceId][nextCpId+1])), 2));
	}
	return distance;
}

stock Float:DistanceToFinish(raceId, entrantNo, nextCpId)
{
	new
		Float:distance,
		vehId = 0,
		lapsLeft;

	if(entrantNo == 1)
	{
		vehId = GetPlayerVehicleID(gRaceStatus[raceId][mRaceEntrant1Id]);
		lapsLeft = gRaceStatus[raceId][mRaceLaps] - gRaceStatus[raceId][mRaceEntrant1Lap];
	}
	if(entrantNo == 2)
	{
		vehId = GetPlayerVehicleID(gRaceStatus[raceId][mRaceEntrant2Id]);
		lapsLeft = gRaceStatus[raceId][mRaceLaps] - gRaceStatus[raceId][mRaceEntrant2Lap];
	}
	if(entrantNo == 3)
	{
		vehId = GetPlayerVehicleID(gRaceStatus[raceId][mRaceEntrant3Id]);
		lapsLeft = gRaceStatus[raceId][mRaceLaps] - gRaceStatus[raceId][mRaceEntrant3Lap];
	}
	if(entrantNo == 4)
	{
		vehId = GetPlayerVehicleID(gRaceStatus[raceId][mRaceEntrant4Id]);
		lapsLeft = gRaceStatus[raceId][mRaceLaps] - gRaceStatus[raceId][mRaceEntrant4Lap];
	}
	if(entrantNo == 5)
	{
		vehId = GetPlayerVehicleID(gRaceStatus[raceId][mRaceEntrant5Id]);
		lapsLeft = gRaceStatus[raceId][mRaceLaps] - gRaceStatus[raceId][mRaceEntrant5Lap];
	}
	if(entrantNo == 6)
	{
		vehId = GetPlayerVehicleID(gRaceStatus[raceId][mRaceEntrant6Id]);
		lapsLeft = gRaceStatus[raceId][mRaceLaps] - gRaceStatus[raceId][mRaceEntrant6Lap];
	}
	if(entrantNo == 7)
	{
		vehId = GetPlayerVehicleID(gRaceStatus[raceId][mRaceEntrant7Id]);
		lapsLeft = gRaceStatus[raceId][mRaceLaps] - gRaceStatus[raceId][mRaceEntrant7Lap];
	}
	if(entrantNo == 8)
	{
		vehId = GetPlayerVehicleID(gRaceStatus[raceId][mRaceEntrant8Id]);
		lapsLeft = gRaceStatus[raceId][mRaceLaps] - gRaceStatus[raceId][mRaceEntrant8Lap];
	}
	if(entrantNo == 9)
	{
		vehId = GetPlayerVehicleID(gRaceStatus[raceId][mRaceEntrant9Id]);
		lapsLeft = gRaceStatus[raceId][mRaceLaps] - gRaceStatus[raceId][mRaceEntrant9Lap];
	}
	if(entrantNo == 10)
	{
		vehId = GetPlayerVehicleID(gRaceStatus[raceId][mRaceEntrant10Id]);
		lapsLeft = gRaceStatus[raceId][mRaceLaps] - gRaceStatus[raceId][mRaceEntrant10Lap];
	}
	
	if(vehId == 0)
		return 0.0;
		
	GetVehiclePos(vehId, gVehData[vehId-1][mVehX], gVehData[vehId-1][mVehY], gVehData[vehId-1][mVehZ]);
	distance += floatsqroot(floatpower(floatabs(floatsub(gVehData[vehId-1][mVehX],  gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][nextCpId])), 2)+floatpower(floatabs(floatsub(gVehData[vehId-1][mVehY],  gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][nextCpId])), 2)+floatpower(floatabs(floatsub(gVehData[vehId-1][mVehZ],  gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][nextCpId])), 2));
	
	reCountDistance:
	for(; nextCpId < MAX_RACES_CP-1; nextCpId++)
	{
		if(gRaceTrackCpType[gRaceStatus[raceId][mRaceId]][nextCpId+1] == RACE_CP_TYPE_NONE)
		{
			lapsLeft--;
			nextCpId = 0;
			break;
		}
		distance += floatsqroot(floatpower(floatabs(floatsub(gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][nextCpId],  gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][nextCpId+1])), 2)+floatpower(floatabs(floatsub(gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][nextCpId], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][nextCpId+1])), 2)+floatpower(floatabs(floatsub(gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][nextCpId], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][nextCpId+1])), 2));
	}
	if(lapsLeft >= 0)
		goto reCountDistance;
	
	return distance;
}

stock CheckPlayerStandings(raceId)
{
	new Float:distanceSorted[10], Float:distance[10];
	if(gRaceStatus[raceId][mRaceEntrant1Status] != PLAYER_RACE_STATE_NONE && gRaceStatus[raceId][mRaceEntrant1Status] != PLAYER_RACE_STATE_LEFT && gRaceStatus[raceId][mRaceEntrant1Status] != PLAYER_RACE_STATE_FINISHED)
	{
		distanceSorted[0] = DistanceToFinish(raceId, 1, gRaceStatus[raceId][mRaceEntrant1NextCpId]);
		distance[0] = distanceSorted[0];
		gRaceStatus[raceId][mRaceEntrant1DistanceLeft] = distance[0];
	}
	else if(gRaceStatus[raceId][mRaceEntrant1Status] == PLAYER_RACE_STATE_NONE || gRaceStatus[raceId][mRaceEntrant1Status] == PLAYER_RACE_STATE_LEFT)
		distanceSorted[0] = -2;
	else if(gRaceStatus[raceId][mRaceEntrant1Status] == PLAYER_RACE_STATE_FINISHED)
		distanceSorted[0] = -1;
	
	
	if(gRaceStatus[raceId][mRaceEntrant2Status] != PLAYER_RACE_STATE_NONE && gRaceStatus[raceId][mRaceEntrant2Status] != PLAYER_RACE_STATE_LEFT && gRaceStatus[raceId][mRaceEntrant2Status] != PLAYER_RACE_STATE_FINISHED)
	{
		distanceSorted[1] = DistanceToFinish(raceId, 2, gRaceStatus[raceId][mRaceEntrant2NextCpId]);
		distance[1] = distanceSorted[1];
		gRaceStatus[raceId][mRaceEntrant2DistanceLeft] = distance[1];
	}
	else if(gRaceStatus[raceId][mRaceEntrant2Status] == PLAYER_RACE_STATE_NONE || gRaceStatus[raceId][mRaceEntrant2Status] == PLAYER_RACE_STATE_LEFT)
		distanceSorted[1] = -3;
	else if(gRaceStatus[raceId][mRaceEntrant2Status] == PLAYER_RACE_STATE_FINISHED)
		distanceSorted[1] = -1;
	
	
	if(gRaceStatus[raceId][mRaceEntrant3Status] != PLAYER_RACE_STATE_NONE && gRaceStatus[raceId][mRaceEntrant3Status] != PLAYER_RACE_STATE_LEFT && gRaceStatus[raceId][mRaceEntrant3Status] != PLAYER_RACE_STATE_FINISHED)
	{
		distanceSorted[2] = DistanceToFinish(raceId, 3, gRaceStatus[raceId][mRaceEntrant3NextCpId]);
		distance[2] = distanceSorted[2];
		gRaceStatus[raceId][mRaceEntrant3DistanceLeft] = distance[2];
	}
	else if(gRaceStatus[raceId][mRaceEntrant3Status] == PLAYER_RACE_STATE_NONE || gRaceStatus[raceId][mRaceEntrant3Status] == PLAYER_RACE_STATE_LEFT)
		distanceSorted[2] = -4;
	else if(gRaceStatus[raceId][mRaceEntrant3Status] == PLAYER_RACE_STATE_FINISHED)
		distanceSorted[2] = -1;
	
	
	if(gRaceStatus[raceId][mRaceEntrant4Status] != PLAYER_RACE_STATE_NONE && gRaceStatus[raceId][mRaceEntrant4Status] != PLAYER_RACE_STATE_LEFT && gRaceStatus[raceId][mRaceEntrant4Status] != PLAYER_RACE_STATE_FINISHED)
	{
		distanceSorted[3] = DistanceToFinish(raceId, 4, gRaceStatus[raceId][mRaceEntrant4NextCpId]);
		distance[3] = distanceSorted[3];
		gRaceStatus[raceId][mRaceEntrant4DistanceLeft] = distance[3];
	}
	else if(gRaceStatus[raceId][mRaceEntrant4Status] == PLAYER_RACE_STATE_NONE || gRaceStatus[raceId][mRaceEntrant4Status] == PLAYER_RACE_STATE_LEFT)
		distanceSorted[3] = -5;
	else if(gRaceStatus[raceId][mRaceEntrant4Status] == PLAYER_RACE_STATE_FINISHED)
		distanceSorted[3] = -1;

		
	if(gRaceStatus[raceId][mRaceEntrant5Status] != PLAYER_RACE_STATE_NONE && gRaceStatus[raceId][mRaceEntrant5Status] != PLAYER_RACE_STATE_LEFT && gRaceStatus[raceId][mRaceEntrant5Status] != PLAYER_RACE_STATE_FINISHED)
	{
		distanceSorted[4] = DistanceToFinish(raceId, 5, gRaceStatus[raceId][mRaceEntrant5NextCpId]);
		distance[4] = distanceSorted[4];
		gRaceStatus[raceId][mRaceEntrant5DistanceLeft] = distance[4];
	}
	else if(gRaceStatus[raceId][mRaceEntrant5Status] == PLAYER_RACE_STATE_NONE || gRaceStatus[raceId][mRaceEntrant5Status] == PLAYER_RACE_STATE_LEFT)
		distanceSorted[4] = -6;
	else if(gRaceStatus[raceId][mRaceEntrant5Status] == PLAYER_RACE_STATE_FINISHED)
		distanceSorted[4] = -1;
	
	
	if(gRaceStatus[raceId][mRaceEntrant6Status] != PLAYER_RACE_STATE_NONE && gRaceStatus[raceId][mRaceEntrant6Status] != PLAYER_RACE_STATE_LEFT && gRaceStatus[raceId][mRaceEntrant6Status] != PLAYER_RACE_STATE_FINISHED)
	{
		distanceSorted[5] = DistanceToFinish(raceId, 6, gRaceStatus[raceId][mRaceEntrant6NextCpId]);
		distance[5] = distanceSorted[5];
		gRaceStatus[raceId][mRaceEntrant6DistanceLeft] = distance[5];
	}
	else if(gRaceStatus[raceId][mRaceEntrant6Status] == PLAYER_RACE_STATE_NONE || gRaceStatus[raceId][mRaceEntrant6Status] == PLAYER_RACE_STATE_LEFT)
		distanceSorted[5] = -7;
	else if(gRaceStatus[raceId][mRaceEntrant6Status] == PLAYER_RACE_STATE_FINISHED)
		distanceSorted[5] = -1;
	
	
	if(gRaceStatus[raceId][mRaceEntrant7Status] != PLAYER_RACE_STATE_NONE && gRaceStatus[raceId][mRaceEntrant7Status] != PLAYER_RACE_STATE_LEFT && gRaceStatus[raceId][mRaceEntrant7Status] != PLAYER_RACE_STATE_FINISHED)
	{
		distanceSorted[6] = DistanceToFinish(raceId, 7, gRaceStatus[raceId][mRaceEntrant7NextCpId]);
		distance[6] = distanceSorted[6];
		gRaceStatus[raceId][mRaceEntrant7DistanceLeft] = distance[6];
	}
	else if(gRaceStatus[raceId][mRaceEntrant7Status] == PLAYER_RACE_STATE_NONE || gRaceStatus[raceId][mRaceEntrant7Status] == PLAYER_RACE_STATE_LEFT)
		distanceSorted[6] = -8;
	else if(gRaceStatus[raceId][mRaceEntrant7Status] == PLAYER_RACE_STATE_FINISHED)
		distanceSorted[6] = -1;

		
	if(gRaceStatus[raceId][mRaceEntrant8Status] != PLAYER_RACE_STATE_NONE && gRaceStatus[raceId][mRaceEntrant8Status] != PLAYER_RACE_STATE_LEFT && gRaceStatus[raceId][mRaceEntrant8Status] != PLAYER_RACE_STATE_FINISHED)
	{
		distanceSorted[7] = DistanceToFinish(raceId, 8, gRaceStatus[raceId][mRaceEntrant8NextCpId]);
		distance[7] = distanceSorted[7];
		gRaceStatus[raceId][mRaceEntrant8DistanceLeft] = distance[7];
	}
	else if(gRaceStatus[raceId][mRaceEntrant8Status] == PLAYER_RACE_STATE_NONE || gRaceStatus[raceId][mRaceEntrant8Status] == PLAYER_RACE_STATE_LEFT)
		distanceSorted[7] = -9;
	else if(gRaceStatus[raceId][mRaceEntrant8Status] == PLAYER_RACE_STATE_FINISHED)
		distanceSorted[7] = -1;
	
	
	if(gRaceStatus[raceId][mRaceEntrant9Status] != PLAYER_RACE_STATE_NONE && gRaceStatus[raceId][mRaceEntrant9Status] != PLAYER_RACE_STATE_LEFT && gRaceStatus[raceId][mRaceEntrant9Status] != PLAYER_RACE_STATE_FINISHED)
	{
		distanceSorted[8] = DistanceToFinish(raceId, 9, gRaceStatus[raceId][mRaceEntrant9NextCpId]);
		distance[8] = distanceSorted[8];
		gRaceStatus[raceId][mRaceEntrant8DistanceLeft] = distance[8];
	}
	else if(gRaceStatus[raceId][mRaceEntrant9Status] == PLAYER_RACE_STATE_NONE || gRaceStatus[raceId][mRaceEntrant9Status] == PLAYER_RACE_STATE_LEFT)
		distanceSorted[8] = -10;
	else if(gRaceStatus[raceId][mRaceEntrant9Status] == PLAYER_RACE_STATE_FINISHED)
		distanceSorted[8] = -1;
	
	
	if(gRaceStatus[raceId][mRaceEntrant10Status] != PLAYER_RACE_STATE_NONE && gRaceStatus[raceId][mRaceEntrant10Status] != PLAYER_RACE_STATE_LEFT && gRaceStatus[raceId][mRaceEntrant10Status] != PLAYER_RACE_STATE_FINISHED)
	{
		distanceSorted[9] = DistanceToFinish(raceId, 10, gRaceStatus[raceId][mRaceEntrant10NextCpId]);
		distance[9] = distanceSorted[9];
		gRaceStatus[raceId][mRaceEntrant10DistanceLeft] = distance[9];
	}
	else if(gRaceStatus[raceId][mRaceEntrant10Status] == PLAYER_RACE_STATE_NONE || gRaceStatus[raceId][mRaceEntrant10Status] == PLAYER_RACE_STATE_LEFT)
		distanceSorted[9] = -11;
	else if(gRaceStatus[raceId][mRaceEntrant10Status] == PLAYER_RACE_STATE_FINISHED)
		distanceSorted[9] = -1;
	
	new Float:cmp = 0;	
	for(new i = 0; i < 10; i++)
	{
		for(new j = 0; j < 10; j++)
		{
			if(i == j)
				continue;
			if((distanceSorted[i] > distanceSorted[j] || distanceSorted[i] <= -2) && i < j && (distanceSorted[j] >= 0 || distanceSorted[j] == -1))
			{
				cmp = distanceSorted[j];
				distanceSorted[j] = distanceSorted[i];
				distanceSorted[i] = cmp;
			}
		}
	}
	for(new i = 0; i < 10; i++)
	{
		if(distance[0] == distanceSorted[i] || distanceSorted[i] == -2)
			gRaceStatus[raceId][mRaceEntrant1Place] = i+1;
		else if(distance[1] == distanceSorted[i] || distanceSorted[i] == -3)
			gRaceStatus[raceId][mRaceEntrant2Place] = i+1;
		else if(distance[2] == distanceSorted[i] || distanceSorted[i] == -4)
			gRaceStatus[raceId][mRaceEntrant3Place] = i+1;
		else if(distance[3] == distanceSorted[i] || distanceSorted[i] == -5)
			gRaceStatus[raceId][mRaceEntrant4Place] = i+1;
		else if(distance[4] == distanceSorted[i] || distanceSorted[i] == -6)
			gRaceStatus[raceId][mRaceEntrant5Place] = i+1;
		else if(distance[5] == distanceSorted[i] || distanceSorted[i] == -7)
			gRaceStatus[raceId][mRaceEntrant6Place] = i+1;
		else if(distance[6] == distanceSorted[i] || distanceSorted[i] == -8)
			gRaceStatus[raceId][mRaceEntrant7Place] = i+1;
		else if(distance[7] == distanceSorted[i] || distanceSorted[i] == -9)
			gRaceStatus[raceId][mRaceEntrant8Place] = i+1;
		else if(distance[8] == distanceSorted[i] || distanceSorted[i] == -10)
			gRaceStatus[raceId][mRaceEntrant9Place] = i+1;
		else if(distance[9] == distanceSorted[i] || distanceSorted[i] == -11)
			gRaceStatus[raceId][mRaceEntrant10Place] = i+1;
	}
}

stock IsPlayerInAnyRace(playerid)
{
	for(new i = 0; i < MAX_RACES; i++)
	{
		if(gRaceStatus[i][mRaceState] != RACE_STATE_NONE)
		{
			if(gRaceStatus[i][mRaceEntrant1Id] == playerid)
				return 1;
			if(gRaceStatus[i][mRaceEntrant2Id] == playerid)
				return 1;
			if(gRaceStatus[i][mRaceEntrant3Id] == playerid)
				return 1;
			if(gRaceStatus[i][mRaceEntrant4Id] == playerid)
				return 1;
			if(gRaceStatus[i][mRaceEntrant5Id] == playerid)
				return 1;
			if(gRaceStatus[i][mRaceEntrant6Id] == playerid)
				return 1;
			if(gRaceStatus[i][mRaceEntrant7Id] == playerid)
				return 1;
			if(gRaceStatus[i][mRaceEntrant8Id] == playerid)
				return 1;
			if(gRaceStatus[i][mRaceEntrant9Id] == playerid)
				return 1;
			if(gRaceStatus[i][mRaceEntrant10Id] == playerid)
				return 1;
		}
	}
	return 0;
}

stock ShowFirstRaceCheckpoint(raceId)
{
	if(gRaceStatus[raceId][mRaceEntrant1Status] == PLAYER_RACE_STATE_CONNECTED)
	{
		DestroyDynamicRaceCP(gRaceStatus[raceId][mRaceEntrant1CpId]);
		gRaceStatus[raceId][mRaceEntrant1CpId] = CreateDynamicRaceCP(0, gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][0],
			gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][1], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][1], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][1], 7.0, -1, -1, gRaceStatus[raceId][mRaceEntrant1Id]);
	}
	if(gRaceStatus[raceId][mRaceEntrant2Status] == PLAYER_RACE_STATE_CONNECTED)
	{
		DestroyDynamicRaceCP(gRaceStatus[raceId][mRaceEntrant2CpId]);
		gRaceStatus[raceId][mRaceEntrant2CpId] = CreateDynamicRaceCP(0, gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][0],
			gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][1], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][1], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][1], 7.0, -1, -1, gRaceStatus[raceId][mRaceEntrant2Id]);
	}
	if(gRaceStatus[raceId][mRaceEntrant3Status] == PLAYER_RACE_STATE_CONNECTED)
	{
		DestroyDynamicRaceCP(gRaceStatus[raceId][mRaceEntrant3CpId]);
		gRaceStatus[raceId][mRaceEntrant3CpId] = CreateDynamicRaceCP(0, gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][0],
			gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][1], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][1], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][1], 7.0, -1, -1, gRaceStatus[raceId][mRaceEntrant3Id]);
	}
	if(gRaceStatus[raceId][mRaceEntrant4Status] == PLAYER_RACE_STATE_CONNECTED)
	{
		DestroyDynamicRaceCP(gRaceStatus[raceId][mRaceEntrant4CpId]);
		gRaceStatus[raceId][mRaceEntrant4CpId] = CreateDynamicRaceCP(0, gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][0],
			gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][1], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][1], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][1], 7.0, -1, -1, gRaceStatus[raceId][mRaceEntrant4Id]);
	}
	if(gRaceStatus[raceId][mRaceEntrant5Status] == PLAYER_RACE_STATE_CONNECTED)
	{
		DestroyDynamicRaceCP(gRaceStatus[raceId][mRaceEntrant5CpId]);
		gRaceStatus[raceId][mRaceEntrant5CpId] = CreateDynamicRaceCP(0, gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][0],
			gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][1], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][1], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][1], 7.0, -1, -1, gRaceStatus[raceId][mRaceEntrant5Id]);
	}
	if(gRaceStatus[raceId][mRaceEntrant6Status] == PLAYER_RACE_STATE_CONNECTED)
	{
		DestroyDynamicRaceCP(gRaceStatus[raceId][mRaceEntrant6CpId]);
		gRaceStatus[raceId][mRaceEntrant6CpId] = CreateDynamicRaceCP(0, gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][0],
			gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][1], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][1], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][1], 7.0, -1, -1, gRaceStatus[raceId][mRaceEntrant6Id]);
	}
	if(gRaceStatus[raceId][mRaceEntrant7Status] == PLAYER_RACE_STATE_CONNECTED)
	{
		DestroyDynamicRaceCP(gRaceStatus[raceId][mRaceEntrant7CpId]);
		gRaceStatus[raceId][mRaceEntrant7CpId] = CreateDynamicRaceCP(0, gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][0],
			gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][1], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][1], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][1], 7.0, -1, -1, gRaceStatus[raceId][mRaceEntrant7Id]);
	}
	if(gRaceStatus[raceId][mRaceEntrant8Status] == PLAYER_RACE_STATE_CONNECTED)
	{
		DestroyDynamicRaceCP(gRaceStatus[raceId][mRaceEntrant8CpId]);
		gRaceStatus[raceId][mRaceEntrant8CpId] = CreateDynamicRaceCP(0, gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][0],
			gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][1], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][1], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][1], 7.0, -1, -1, gRaceStatus[raceId][mRaceEntrant8Id]);
	}
	if(gRaceStatus[raceId][mRaceEntrant9Status] == PLAYER_RACE_STATE_CONNECTED)
	{
		DestroyDynamicRaceCP(gRaceStatus[raceId][mRaceEntrant9CpId]);
		gRaceStatus[raceId][mRaceEntrant9CpId] = CreateDynamicRaceCP(0, gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][0],
			gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][1], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][1], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][1], 7.0, -1, -1, gRaceStatus[raceId][mRaceEntrant9Id]);
	}
	if(gRaceStatus[raceId][mRaceEntrant10Status] == PLAYER_RACE_STATE_CONNECTED)
	{
		DestroyDynamicRaceCP(gRaceStatus[raceId][mRaceEntrant10CpId]);
		gRaceStatus[raceId][mRaceEntrant10CpId] = CreateDynamicRaceCP(0, gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][0], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][0],
			gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][1], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][1], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][1], 7.0, -1, -1, gRaceStatus[raceId][mRaceEntrant10Id]);
	}
}

stock CalculateRacerTime(raceId, racerNo)
{
	new lHour, lMin, lSec;
	gettime(lHour, lMin, lSec);
	
	lHour -= gRaceStatus[raceId][mRaceStartHour];
	
	lMin -= gRaceStatus[raceId][mRaceStartMin];
	if(lMin < 0)
	{
		lMin += 60;
		lHour--;
	}
	
	lSec -= gRaceStatus[raceId][mRaceStartSec];
	if(lSec < 0)
	{
		lSec += 60;
		lMin--;
		if(lMin < 0)
		{
			lHour--;
			lMin += 60;
		}		
	}
	
	if(racerNo == 1)
	{
		if(lHour > 0)
			gRaceStatus[raceId][mRaceEntrant1Hour] = lHour;
		else
			gRaceStatus[raceId][mRaceEntrant1Hour] = 0;
		if(lMin > 0)
			gRaceStatus[raceId][mRaceEntrant1Min] = lMin;
		else
			gRaceStatus[raceId][mRaceEntrant1Min] = 0;
		if(lSec > 0)
			gRaceStatus[raceId][mRaceEntrant1Sec] = lSec;
		else
			gRaceStatus[raceId][mRaceEntrant1Sec] = 0;
	}
	else if(racerNo == 2)
	{
		if(lHour > 0)
			gRaceStatus[raceId][mRaceEntrant2Hour] = lHour;
		else
			gRaceStatus[raceId][mRaceEntrant2Hour] = 0;
		if(lMin > 0)
			gRaceStatus[raceId][mRaceEntrant2Min] = lMin;
		else
			gRaceStatus[raceId][mRaceEntrant2Min] = 0;
		if(lSec > 0)
			gRaceStatus[raceId][mRaceEntrant2Sec] = lSec;
		else
			gRaceStatus[raceId][mRaceEntrant2Sec] = 0;
	}
	else if(racerNo == 3)
	{
		if(lHour > 0)
			gRaceStatus[raceId][mRaceEntrant3Hour] = lHour;
		else
			gRaceStatus[raceId][mRaceEntrant3Hour] = 0;
		if(lMin > 0)
			gRaceStatus[raceId][mRaceEntrant3Min] = lMin;
		else
			gRaceStatus[raceId][mRaceEntrant3Min] = 0;
		if(lSec > 0)
			gRaceStatus[raceId][mRaceEntrant3Sec] = lSec;
		else
			gRaceStatus[raceId][mRaceEntrant3Sec] = 0;
	}
	else if(racerNo == 4)
	{
		if(lHour > 0)
			gRaceStatus[raceId][mRaceEntrant4Hour] = lHour;
		else
			gRaceStatus[raceId][mRaceEntrant4Hour] = 0;
		if(lMin > 0)
			gRaceStatus[raceId][mRaceEntrant4Min] = lMin;
		else
			gRaceStatus[raceId][mRaceEntrant4Min] = 0;
		if(lSec > 0)
			gRaceStatus[raceId][mRaceEntrant4Sec] = lSec;
		else
			gRaceStatus[raceId][mRaceEntrant4Sec] = 0;
	}
	else if(racerNo == 5)
	{
		if(lHour > 0)
			gRaceStatus[raceId][mRaceEntrant5Hour] = lHour;
		else
			gRaceStatus[raceId][mRaceEntrant5Hour] = 0;
		if(lMin > 0)
			gRaceStatus[raceId][mRaceEntrant5Min] = lMin;
		else
			gRaceStatus[raceId][mRaceEntrant5Min] = 0;
		if(lSec > 0)
			gRaceStatus[raceId][mRaceEntrant5Sec] = lSec;
		else
			gRaceStatus[raceId][mRaceEntrant5Sec] = 0;
	}
	else if(racerNo == 6)
	{
		if(lHour > 0)
			gRaceStatus[raceId][mRaceEntrant6Hour] = lHour;
		else
			gRaceStatus[raceId][mRaceEntrant6Hour] = 0;
		if(lMin > 0)
			gRaceStatus[raceId][mRaceEntrant6Min] = lMin;
		else
			gRaceStatus[raceId][mRaceEntrant6Min] = 0;
		if(lSec > 0)
			gRaceStatus[raceId][mRaceEntrant6Sec] = lSec;
		else
			gRaceStatus[raceId][mRaceEntrant6Sec] = 0;
	}
	else if(racerNo == 7)
	{
		if(lHour > 0)
			gRaceStatus[raceId][mRaceEntrant7Hour] = lHour;
		else
			gRaceStatus[raceId][mRaceEntrant7Hour] = 0;
		if(lMin > 0)
			gRaceStatus[raceId][mRaceEntrant7Min] = lMin;
		else
			gRaceStatus[raceId][mRaceEntrant7Min] = 0;
		if(lSec > 0)
			gRaceStatus[raceId][mRaceEntrant7Sec] = lSec;
		else
			gRaceStatus[raceId][mRaceEntrant7Sec] = 0;
	}
	else if(racerNo == 8)
	{
		if(lHour > 0)
			gRaceStatus[raceId][mRaceEntrant8Hour] = lHour;
		else
			gRaceStatus[raceId][mRaceEntrant8Hour] = 0;
		if(lMin > 0)
			gRaceStatus[raceId][mRaceEntrant8Min] = lMin;
		else
			gRaceStatus[raceId][mRaceEntrant8Min] = 0;
		if(lSec > 0)
			gRaceStatus[raceId][mRaceEntrant8Sec] = lSec;
		else
			gRaceStatus[raceId][mRaceEntrant8Sec] = 0;
	}
	else if(racerNo == 9)
	{
		if(lHour > 0)
			gRaceStatus[raceId][mRaceEntrant9Hour] = lHour;
		else
			gRaceStatus[raceId][mRaceEntrant9Hour] = 0;
		if(lMin > 0)
			gRaceStatus[raceId][mRaceEntrant9Min] = lMin;
		else
			gRaceStatus[raceId][mRaceEntrant9Min] = 0;
		if(lSec > 0)
			gRaceStatus[raceId][mRaceEntrant9Sec] = lSec;
		else
			gRaceStatus[raceId][mRaceEntrant9Sec] = 0;
	}
	else if(racerNo == 10)
	{
		if(lHour > 0)
			gRaceStatus[raceId][mRaceEntrant10Hour] = lHour;
		else
			gRaceStatus[raceId][mRaceEntrant10Hour] = 0;
		if(lMin > 0)
			gRaceStatus[raceId][mRaceEntrant10Min] = lMin;
		else
			gRaceStatus[raceId][mRaceEntrant10Min] = 0;
		if(lSec > 0)
			gRaceStatus[raceId][mRaceEntrant10Sec] = lSec;
		else
			gRaceStatus[raceId][mRaceEntrant10Sec] = 0;
	}
}

stock ShowNextRaceCheckpoint(raceId, entrantNo)
{
	if(entrantNo == 1 && gRaceStatus[raceId][mRaceEntrant1Status] == PLAYER_RACE_STATE_CONNECTED)
	{
		DestroyDynamicRaceCP(gRaceStatus[raceId][mRaceEntrant1CpId]);
		if(gRaceStatus[raceId][mRaceEntrant1NextCpId]+1 <= MAX_RACES_CP-1)
		{
			if(gRaceTrackCpType[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant1NextCpId]+1] != RACE_CP_TYPE_NONE && gRaceTrackCpType[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant1NextCpId]] != RACE_CP_TYPE_FINISH)
			{
				gRaceStatus[raceId][mRaceEntrant1CpId] = CreateDynamicRaceCP(0, gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant1NextCpId]], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant1NextCpId]], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant1NextCpId]],
					gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant1NextCpId]+1], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant1NextCpId]+1], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant1NextCpId]+1], 10.5, -1, -1, gRaceStatus[raceId][mRaceEntrant1Id], 200.0);
			}
		}
		if(gRaceTrackCpType[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant1NextCpId]] == RACE_CP_TYPE_FINISH)
		{
			gRaceStatus[raceId][mRaceEntrant1CpId] = CreateDynamicRaceCP(1, gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant1NextCpId]], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant1NextCpId]], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant1NextCpId]],
				gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant1NextCpId]], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant1NextCpId]], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant1NextCpId]], 10.5, -1, -1, gRaceStatus[raceId][mRaceEntrant1Id], 200.0);
		}
	}
	if(entrantNo == 2 && gRaceStatus[raceId][mRaceEntrant2Status] == PLAYER_RACE_STATE_CONNECTED)
	{
		DestroyDynamicRaceCP(gRaceStatus[raceId][mRaceEntrant2CpId]);
		if(gRaceStatus[raceId][mRaceEntrant2NextCpId]+1 <= MAX_RACES_CP-1)
		{
			if(gRaceTrackCpType[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant2NextCpId]+1] != RACE_CP_TYPE_NONE)
			{
				gRaceStatus[raceId][mRaceEntrant2CpId] = CreateDynamicRaceCP(0, gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant2NextCpId]], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant2NextCpId]], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant2NextCpId]],
					gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant2NextCpId]+1], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant2NextCpId]+1], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant2NextCpId]+1], 10.5, -1, -1, gRaceStatus[raceId][mRaceEntrant2Id], 200.0);
			}
		}
		if(gRaceTrackCpType[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant2NextCpId]] == RACE_CP_TYPE_FINISH)
		{	
			gRaceStatus[raceId][mRaceEntrant2CpId] = CreateDynamicRaceCP(1, gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant2NextCpId]], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant2NextCpId]], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant2NextCpId]],
				gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant2NextCpId]], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant2NextCpId]], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant2NextCpId]], 10.5, -1, -1, gRaceStatus[raceId][mRaceEntrant2Id], 200.0);
		}
	}
	if(entrantNo == 3 && gRaceStatus[raceId][mRaceEntrant3Status] == PLAYER_RACE_STATE_CONNECTED)
	{
		DestroyDynamicRaceCP(gRaceStatus[raceId][mRaceEntrant3CpId]);
		if(gRaceStatus[raceId][mRaceEntrant3NextCpId]+1 <= MAX_RACES_CP-1)
		{			
			if(gRaceTrackCpType[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant3NextCpId]+1] != RACE_CP_TYPE_NONE)
			{
				gRaceStatus[raceId][mRaceEntrant3CpId] = CreateDynamicRaceCP(0, gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant3NextCpId]], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant3NextCpId]], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant3NextCpId]],
					gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant3NextCpId]+1], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant3NextCpId]+1], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant3NextCpId]+1], 10.5, -1, -1, gRaceStatus[raceId][mRaceEntrant3Id], 200.0);
			}
		}
		if(gRaceTrackCpType[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant3NextCpId]] == RACE_CP_TYPE_FINISH)
		{
			gRaceStatus[raceId][mRaceEntrant3CpId] = CreateDynamicRaceCP(1, gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant3NextCpId]], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant3NextCpId]], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant3NextCpId]],
				gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant3NextCpId]], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant3NextCpId]], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant3NextCpId]], 10.5, -1, -1, gRaceStatus[raceId][mRaceEntrant3Id], 200.0);
		}
	}
	if(entrantNo == 4 && gRaceStatus[raceId][mRaceEntrant4Status] == PLAYER_RACE_STATE_CONNECTED)
	{
		DestroyDynamicRaceCP(gRaceStatus[raceId][mRaceEntrant4CpId]);
		if(gRaceStatus[raceId][mRaceEntrant4NextCpId]+1 <= MAX_RACES_CP-1)
		{
			if(gRaceTrackCpType[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant4NextCpId]+1] != RACE_CP_TYPE_NONE)
			{
				gRaceStatus[raceId][mRaceEntrant4CpId] = CreateDynamicRaceCP(0, gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant4NextCpId]], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant4NextCpId]], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant4NextCpId]],
					gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant4NextCpId]+1], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant4NextCpId]+1], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant4NextCpId]+1], 10.5, -1, -1, gRaceStatus[raceId][mRaceEntrant4Id], 200.0);
			}
		}
		if(gRaceTrackCpType[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant4NextCpId]] == RACE_CP_TYPE_FINISH)
		{	
			gRaceStatus[raceId][mRaceEntrant4CpId] = CreateDynamicRaceCP(1, gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant4NextCpId]], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant4NextCpId]], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant4NextCpId]],
				gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant4NextCpId]], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant4NextCpId]], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant4NextCpId]], 10.5, -1, -1, gRaceStatus[raceId][mRaceEntrant4Id], 200.0);
		}
	}
	if(entrantNo == 5 && gRaceStatus[raceId][mRaceEntrant5Status] == PLAYER_RACE_STATE_CONNECTED)
	{
		DestroyDynamicRaceCP(gRaceStatus[raceId][mRaceEntrant5CpId]);
		if(gRaceStatus[raceId][mRaceEntrant5NextCpId]+1 <= MAX_RACES_CP-1)
		{
			if(gRaceTrackCpType[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant5NextCpId]+1] != RACE_CP_TYPE_NONE)
			{	
				gRaceStatus[raceId][mRaceEntrant5CpId] = CreateDynamicRaceCP(0, gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant5NextCpId]], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant5NextCpId]], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant5NextCpId]],
					gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant5NextCpId]+1], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant5NextCpId]+1], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant5NextCpId]+1], 10.5, -1, -1, gRaceStatus[raceId][mRaceEntrant5Id], 200.0);
			}
		}
		if(gRaceTrackCpType[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant5NextCpId]] == RACE_CP_TYPE_FINISH)
		{
			gRaceStatus[raceId][mRaceEntrant5CpId] = CreateDynamicRaceCP(0, gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant5NextCpId]], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant5NextCpId]], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant5NextCpId]],
				gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant5NextCpId]], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant5NextCpId]], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant5NextCpId]], 10.5, -1, -1, gRaceStatus[raceId][mRaceEntrant5Id], 200.0);
		}
	}
	if(entrantNo == 6 && gRaceStatus[raceId][mRaceEntrant6Status] == PLAYER_RACE_STATE_CONNECTED)
	{
		DestroyDynamicRaceCP(gRaceStatus[raceId][mRaceEntrant6CpId]);
		if(gRaceStatus[raceId][mRaceEntrant6NextCpId]+1 <= MAX_RACES_CP-1)
		{			
			if(gRaceTrackCpType[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant6NextCpId]+1] != RACE_CP_TYPE_NONE)
			{
				gRaceStatus[raceId][mRaceEntrant6CpId] = CreateDynamicRaceCP(0, gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant6NextCpId]], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant6NextCpId]], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant6NextCpId]],
					gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant6NextCpId]+1], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant6NextCpId]+1], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant6NextCpId]+1], 10.5, -1, -1, gRaceStatus[raceId][mRaceEntrant6Id], 200.0);
			}
		}
		if(gRaceTrackCpType[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant6NextCpId]] == RACE_CP_TYPE_FINISH)
		{
			gRaceStatus[raceId][mRaceEntrant6CpId] = CreateDynamicRaceCP(0, gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant6NextCpId]], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant6NextCpId]], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant6NextCpId]],
				gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant6NextCpId]], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant6NextCpId]], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant6NextCpId]], 10.5, -1, -1, gRaceStatus[raceId][mRaceEntrant6Id], 200.0);
		}
	}
	if(entrantNo == 7 && gRaceStatus[raceId][mRaceEntrant7Status] == PLAYER_RACE_STATE_CONNECTED)
	{
		DestroyDynamicRaceCP(gRaceStatus[raceId][mRaceEntrant7CpId]);
		if(gRaceStatus[raceId][mRaceEntrant7NextCpId]+1 <= MAX_RACES_CP-1)
		{
			if(gRaceTrackCpType[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant7NextCpId]+1] != RACE_CP_TYPE_NONE)
			{
				gRaceStatus[raceId][mRaceEntrant7CpId] = CreateDynamicRaceCP(0, gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant7NextCpId]], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant7NextCpId]], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant7NextCpId]],
					gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant7NextCpId]+1], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant7NextCpId]+1], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant7NextCpId]+1], 10.5, -1, -1, gRaceStatus[raceId][mRaceEntrant7Id], 200.0);
			}
		}
		if(gRaceTrackCpType[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant7NextCpId]] == RACE_CP_TYPE_FINISH)
		{
			gRaceStatus[raceId][mRaceEntrant7CpId] = CreateDynamicRaceCP(0, gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant7NextCpId]], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant7NextCpId]], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant7NextCpId]],
				gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant7NextCpId]], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant7NextCpId]], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant7NextCpId]], 10.5, -1, -1, gRaceStatus[raceId][mRaceEntrant7Id], 200.0);
		}
	}
	if(entrantNo == 8 && gRaceStatus[raceId][mRaceEntrant8Status] == PLAYER_RACE_STATE_CONNECTED)
	{
		DestroyDynamicRaceCP(gRaceStatus[raceId][mRaceEntrant8CpId]);
		if(gRaceStatus[raceId][mRaceEntrant8NextCpId]+1 <= MAX_RACES_CP-1)
		{			
			if(gRaceTrackCpType[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant8NextCpId]+1] != RACE_CP_TYPE_NONE)
			{
				gRaceStatus[raceId][mRaceEntrant8CpId] = CreateDynamicRaceCP(0, gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant8NextCpId]], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant8NextCpId]], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant8NextCpId]],
					gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant8NextCpId]+1], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant8NextCpId]+1], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant8NextCpId]+1], 10.5, -1, -1, gRaceStatus[raceId][mRaceEntrant8Id], 200.0);
			}
		}
		if(gRaceTrackCpType[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant8NextCpId]] == RACE_CP_TYPE_FINISH)
		{
			gRaceStatus[raceId][mRaceEntrant8CpId] = CreateDynamicRaceCP(0, gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant8NextCpId]], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant8NextCpId]], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant8NextCpId]],
				gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant8NextCpId]], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant8NextCpId]], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant8NextCpId]], 10.5, -1, -1, gRaceStatus[raceId][mRaceEntrant8Id], 200.0);
		}
	}
	if(entrantNo == 9 && gRaceStatus[raceId][mRaceEntrant9Status] == PLAYER_RACE_STATE_CONNECTED)
	{
		DestroyDynamicRaceCP(gRaceStatus[raceId][mRaceEntrant9CpId]);
		if(gRaceStatus[raceId][mRaceEntrant9NextCpId]+1 <= MAX_RACES_CP-1)
		{			
			if(gRaceTrackCpType[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant9NextCpId]+1] != RACE_CP_TYPE_NONE)
			{
				gRaceStatus[raceId][mRaceEntrant9CpId] = CreateDynamicRaceCP(0, gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant9NextCpId]], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant9NextCpId]], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant9NextCpId]],
					gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant9NextCpId]+1], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant9NextCpId]+1], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant9NextCpId]+1], 10.5, -1, -1, gRaceStatus[raceId][mRaceEntrant9Id], 200.0);
			}
		}
		if(gRaceTrackCpType[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant9NextCpId]] == RACE_CP_TYPE_FINISH)
		{
			gRaceStatus[raceId][mRaceEntrant9CpId] = CreateDynamicRaceCP(0, gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant9NextCpId]], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant9NextCpId]], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant9NextCpId]],
				gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant9NextCpId]], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant9NextCpId]], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant9NextCpId]], 10.5, -1, -1, gRaceStatus[raceId][mRaceEntrant9Id], 200.0);
		}
	}
	if(entrantNo == 10 && gRaceStatus[raceId][mRaceEntrant10Status] == PLAYER_RACE_STATE_CONNECTED)
	{
		DestroyDynamicRaceCP(gRaceStatus[raceId][mRaceEntrant10CpId]);
		if(gRaceStatus[raceId][mRaceEntrant10NextCpId]+1 <= MAX_RACES_CP-1)
		{			
			if(gRaceTrackCpType[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant10NextCpId]+1] != RACE_CP_TYPE_NONE)
			{	
				gRaceStatus[raceId][mRaceEntrant10CpId] = CreateDynamicRaceCP(0, gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant10NextCpId]], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant10NextCpId]], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant10NextCpId]],
					gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant10NextCpId]+1], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant10NextCpId]+1], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant10NextCpId]+1], 10.5, -1, -1, gRaceStatus[raceId][mRaceEntrant10Id], 200.0);
			}
		}
		if(gRaceTrackCpType[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant10NextCpId]] == RACE_CP_TYPE_FINISH)
		{	
			gRaceStatus[raceId][mRaceEntrant10CpId] = CreateDynamicRaceCP(0, gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant10NextCpId]], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant10NextCpId]], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant10NextCpId]],
				gRaceTrackCpX[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant10NextCpId]], gRaceTrackCpY[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant10NextCpId]], gRaceTrackCpZ[gRaceStatus[raceId][mRaceId]][gRaceStatus[raceId][mRaceEntrant10NextCpId]], 10.5, -1, -1, gRaceStatus[raceId][mRaceEntrant10Id], 200.0);
		}
	}
}