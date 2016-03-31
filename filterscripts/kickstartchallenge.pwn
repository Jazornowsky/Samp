#include <a_samp>
// Kickstart Challange 2.0 by =>Sandra<= & O.K.Style

#define RED_PACKAGE 19290 // or 19282 solid red
#define GREEN_PACKAGE 19291 // or 19283 solid green
#define YELLOW_PACKAGE 19294 // 19284 solid blue

#define SLOTS 500

new PU_KSS[SLOTS][32], KSSV[SLOTS], Text:KSC[10], Text:TDT[SLOTS], Text:TDS[SLOTS];

public OnFilterScriptInit()
{
	KSC[0] = TextDrawCreate(643.0, 2.0, "~n~");
	TextDrawLetterSize(KSC[0], 0.50, 10.800002);
	TextDrawUseBox(KSC[0], 1);
	TextDrawBoxColor(KSC[0], 0x000000FF);
	TextDrawTextSize(KSC[0], -3.0, 0.0);

	KSC[1] = TextDrawCreate(643.0, 343.0, "~n~");
	TextDrawLetterSize(KSC[1], 0.50, 11.400004);
	TextDrawUseBox(KSC[1], 1);
	TextDrawBoxColor(KSC[1], 255);
	TextDrawTextSize(KSC[1], -3.0, 0.0);

	KSC[2] = TextDrawCreate(320.0, 375.0, "Use the Sanchez to collect Coronas. The ~g~Green Corona ~w~ is~n~worth 1 point. The ~y~Amber Corona ~w~ is worth 2 points. The~n~~r~Red Corona ~w~is worth 3 points.");
	TextDrawAlignment(KSC[2], 2);
	TextDrawFont(KSC[2], 1);
	TextDrawLetterSize(KSC[2], 0.48, 1.3);
	TextDrawSetOutline(KSC[2], 1);

	KSC[3] = TextDrawCreate(320.0, 375.0, "To leave the stadium stand in the ~r~red highlighted ~w~area on foot.");
	TextDrawAlignment(KSC[3], 2);
	TextDrawFont(KSC[3], 1);
	TextDrawLetterSize(KSC[3], 0.48, 1.3);
	TextDrawSetOutline(KSC[3], 1);

	KSC[4] = TextDrawCreate(330.0, 375.0, "Get on the ~b~bike~w~!");
	TextDrawAlignment(KSC[4], 2);
	TextDrawFont(KSC[4], 1);
	TextDrawLetterSize(KSC[4], 0.419999, 1.5);
	TextDrawSetShadow(KSC[4], 1);
	
	KSC[5] = TextDrawCreate(330.0, 375.0, "Collect as many points as possible.");
	TextDrawAlignment(KSC[5], 2);
	TextDrawFont(KSC[5], 1);
	TextDrawLetterSize(KSC[5], 0.419999, 1.5);
	TextDrawSetShadow(KSC[5], 1);
	TextDrawColor(KSC[5], 0xFFFFFFFF);

	KSC[6] = TextDrawCreate(330.0, 375.0, "You have collected an ~g~Green Corona~w~ +1");
	TextDrawAlignment(KSC[6], 2);
	TextDrawFont(KSC[6], 1);
	TextDrawLetterSize(KSC[6], 0.419999, 1.5);
	TextDrawSetShadow(KSC[6], 1);
	
	KSC[7] = TextDrawCreate(330.0, 375.0, "You have collected an ~y~Amber Corona~w~ +2");
	TextDrawAlignment(KSC[7], 2);
	TextDrawFont(KSC[7], 1);
	TextDrawLetterSize(KSC[7], 0.419999, 1.5);
	TextDrawSetShadow(KSC[7], 1);
	
	KSC[8] = TextDrawCreate(330.0, 375.0, "You have collected an ~r~Red Corona~w~ +3");
	TextDrawAlignment(KSC[8], 2);
	TextDrawFont(KSC[8], 1);
	TextDrawLetterSize(KSC[8], 0.419999, 1.5);
	TextDrawSetShadow(KSC[8], 1);

	return 1;
}
public OnFilterScriptExit()
{
	for(new i, j = GetMaxPlayers(); i != j; i++)
	{
	    if(IsPlayerConnected(i) && GetPVarInt(i, "KSIter") > 1)
	    {
	        DisablePlayerCheckpoint(i);
			DestroyVehicle(KSSV[i]);
			for(new k; k < 50; k++)
			{
			    DestroyPickup(PU_KSS[i][k]);
			}
			TextDrawHideForAll(TDT[i]);
			TextDrawDestroy(TDT[i]);
			TextDrawHideForAll(TDS[i]);
			TextDrawDestroy(TDS[i]);
		}
	}
	for(new l; l < sizeof(KSC); l++)
	{
	    TextDrawHideForAll(KSC[l]);
	    TextDrawDestroy(KSC[l]);
	}
	return 1;
}
public OnPlayerCommandText(playerid, cmdtext[])
{
	if(strcmp(cmdtext, "/ksc", true) == 0)
	{
		if(!IsPlayerInRangeOfPoint(playerid, 1.0, 1099.5934, 1601.7084, 12.5469)) return 0;
		GameTextForPlayer(playerid, "KICKSTART", 1000, 1);
		SetPlayerInterior(playerid, 14);
		SetPlayerPos(playerid, -1469.9823, 1564.8439, 1052.7500);
		SetPlayerFacingAngle(playerid, 270.0);
		SetPlayerVirtualWorld(playerid, playerid);
		KSSV[playerid] = CreateVehicle(468, -1459.8287, 1558.5782, 1052.1995, -90.0, -1, -1, -1);
		LinkVehicleToInterior(KSSV[playerid], 14);
		SetVehicleVirtualWorld(KSSV[playerid], playerid);
		SetPlayerWeather(playerid, 21); // or 25
		TogglePlayerControllable(playerid, 0);
		SetTimerEx("LoadKickstart", 1000, 0, "d", playerid);
		return 1;
	}
	return 0;
}
public OnPlayerStateChange(playerid, newstate, oldstate)
{
	if(oldstate == PLAYER_STATE_ONFOOT && newstate == PLAYER_STATE_DRIVER && GetPVarInt(playerid, "KSIter") < 5)
	{
		TogglePlayerControllable(playerid, 0);
		TextDrawShowForPlayer(playerid, KSC[0]);
		TextDrawShowForPlayer(playerid, KSC[1]);
		TextDrawHideForPlayer(playerid, KSC[4]);
		SetTimerEx("LoadKickstart", 1000, 0, "d", playerid);
	}
	if(oldstate == PLAYER_STATE_DRIVER && newstate == PLAYER_STATE_ONFOOT && GetPVarInt(playerid, "KSIter") > 4)
	{
		TextDrawShowForPlayer(playerid, KSC[9]);
//		SetTimerEx("KickstartFallBike", 1000, 0, "d", playerid);
	}
	return 1;
}
public OnPlayerPickUpPickup(playerid, pickupid)
{
	if(pickupid == PU_KSS[playerid][0] || pickupid == PU_KSS[playerid][1]
	|| pickupid == PU_KSS[playerid][2] || pickupid == PU_KSS[playerid][3]
	|| pickupid == PU_KSS[playerid][4] || pickupid == PU_KSS[playerid][5]
	|| pickupid == PU_KSS[playerid][6] || pickupid == PU_KSS[playerid][7]
	|| pickupid == PU_KSS[playerid][8] || pickupid == PU_KSS[playerid][9]
	|| pickupid == PU_KSS[playerid][10] || pickupid == PU_KSS[playerid][11]
	|| pickupid == PU_KSS[playerid][12])
	{
	    SetPVarInt(playerid, "KickstartScore", GetPVarInt(playerid, "KickstartScore") + 1);
		new string[30];
	    format(string, sizeof string, "SCORE_______%d", GetPVarInt(playerid, "KickstartScore"));
	    TextDrawSetString(TDS[playerid], string);
	    TextDrawShowForPlayer(playerid, KSC[6]);
	    SetTimerEx("ClearCoronas", 800, 0, "d", playerid);
	    return 1;
	}
	else if(pickupid == PU_KSS[playerid][13] || pickupid == PU_KSS[playerid][14]
	|| pickupid == PU_KSS[playerid][15] || pickupid == PU_KSS[playerid][16]
	|| pickupid == PU_KSS[playerid][17] || pickupid == PU_KSS[playerid][18]
	|| pickupid == PU_KSS[playerid][19] || pickupid == PU_KSS[playerid][20]
	|| pickupid == PU_KSS[playerid][21] || pickupid == PU_KSS[playerid][22]
	|| pickupid == PU_KSS[playerid][23])
	{
	    SetPVarInt(playerid, "KickstartScore", GetPVarInt(playerid, "KickstartScore") + 2);
		new string[30];
	    format(string, sizeof string, "SCORE_______%d", GetPVarInt(playerid, "KickstartScore"));
	    TextDrawSetString(TDS[playerid], string);
	    TextDrawShowForPlayer(playerid, KSC[7]);
	    SetTimerEx("ClearCoronas", 800, 0, "d", playerid);
	    return 1;
	}
	else if(pickupid == PU_KSS[playerid][24] || pickupid == PU_KSS[playerid][25]
	|| pickupid == PU_KSS[playerid][26] || pickupid == PU_KSS[playerid][27]
	|| pickupid == PU_KSS[playerid][28] || pickupid == PU_KSS[playerid][29]
	|| pickupid == PU_KSS[playerid][30] || pickupid == PU_KSS[playerid][31])
	{
	    SetPVarInt(playerid, "KickstartScore", GetPVarInt(playerid, "KickstartScore") + 3);
		new string[30];
	    format(string, sizeof string, "SCORE_______%d", GetPVarInt(playerid, "KickstartScore"));
	    TextDrawSetString(TDS[playerid], string);
	    TextDrawShowForPlayer(playerid, KSC[8]);
	    SetTimerEx("ClearCoronas", 800, 0, "d", playerid);
	    return 1;
	}
	return 0;
}
forward LoadKickstart(playerid);
public LoadKickstart(playerid)
{
	SetPVarInt(playerid, "KSIter", GetPVarInt(playerid, "KSIter") + 1);
	new ksiter = GetPVarInt(playerid, "KSIter");
	switch(ksiter)
	{
	    case 1:
	    {
	        TextDrawShowForPlayer(playerid, KSC[0]); // top
	        TextDrawShowForPlayer(playerid, KSC[1]); // bottom
	        SetTimerEx("LoadKickstart", 1000, 0, "d", playerid);
	    }
	    case 2:
	    {
			SetPlayerCheckpoint(playerid, -1464.7694, 1557.4290, 1052.5313, 3.0);
	        TextDrawShowForPlayer(playerid, KSC[2]); // text
	        SetTimerEx("LoadKickstart", 9000, 0, "d", playerid);
	    }
	    case 3:
	    {
	        SetPlayerCameraPos(playerid, -1473.1202, 1564.9624, 1053.0);
	        SetPlayerCameraLookAt(playerid, -1455.2076, 1556.7408, 1052.5313);
	        TextDrawHideForPlayer(playerid, KSC[2]);
	        TextDrawShowForPlayer(playerid, KSC[3]); // next text
	        SetTimerEx("LoadKickstart", 7000, 0, "d", playerid);
	    }
	    case 4:
	    {
	        TextDrawHideForPlayer(playerid, KSC[0]);
	        TextDrawHideForPlayer(playerid, KSC[1]);
	        TextDrawHideForPlayer(playerid, KSC[3]);
	        TextDrawShowForPlayer(playerid, KSC[4]);
	        SetCameraBehindPlayer(playerid);
			TogglePlayerControllable(playerid, 1);
	    }
// other timer
	    case 5:
	    {
	        GameTextForPlayer(playerid, "3", 1000, 3);
	        SetTimerEx("LoadKickstart", 1000, 0, "d", playerid);
	    }
	    case 6:
	    {
	        GameTextForPlayer(playerid, "2", 1000, 3);
	        SetTimerEx("LoadKickstart", 1000, 0, "d", playerid);
	    }
	    case 7:
	    {
	        GameTextForPlayer(playerid, "1", 1000, 3);
	        SetTimerEx("LoadKickstart", 1000, 0, "d", playerid);
	    }
	    case 8:
	    {
	        GameTextForPlayer(playerid, "~b~~h~GO!", 1000, 5);
	        TextDrawHideForPlayer(playerid, KSC[0]);
	        TextDrawHideForPlayer(playerid, KSC[1]);
	        TextDrawHideForPlayer(playerid, KSC[4]);

			TDT[playerid] = TextDrawCreate(607.0, 128.0, "TIME__04:00");
			TextDrawAlignment(TDT[playerid], 3);
			TextDrawFont(TDT[playerid], 2);
			TextDrawLetterSize(TDT[playerid], 0.459999, 1.899999);
			TextDrawSetOutline(TDT[playerid], 1);
			SetPVarInt(playerid, "KickstartTime", 240);

			TDS[playerid] = TextDrawCreate(607.0, 145.0, "SCORE_______0");
			TextDrawAlignment(TDS[playerid], 3);
			TextDrawFont(TDS[playerid], 2);
			TextDrawLetterSize(TDS[playerid], 0.459999, 1.899999);
			TextDrawColor(TDS[playerid], 0xABCBF2FF);
			TextDrawSetOutline(TDS[playerid], 1);
	        
	        TextDrawShowForPlayer(playerid, TDT[playerid]);
	        TextDrawShowForPlayer(playerid, TDS[playerid]);
	        SetTimerEx("LoadKickstart", 1000, 0, "d", playerid);
			TogglePlayerControllable(playerid, 1);

			PU_KSS[playerid][0] = CreatePickup(GREEN_PACKAGE, 14, -1408.4288, 1585.5469, 1055.7598, playerid);
			PU_KSS[playerid][1] = CreatePickup(GREEN_PACKAGE, 14, -1408.2796, 1592.9285, 1055.6417, playerid);
			PU_KSS[playerid][2] = CreatePickup(GREEN_PACKAGE, 14, -1456.8065, 1648.6833, 1054.4140, playerid);
			PU_KSS[playerid][3] = CreatePickup(GREEN_PACKAGE, 14, -1442.9694, 1648.5679, 1054.4140, playerid);
			PU_KSS[playerid][4] = CreatePickup(GREEN_PACKAGE, 14, -1431.2161, 1598.0710, 1054.4641, playerid);
			PU_KSS[playerid][5] = CreatePickup(GREEN_PACKAGE, 14, -1420.9184, 1597.8729, 1054.4744, playerid);
			PU_KSS[playerid][6] = CreatePickup(GREEN_PACKAGE, 14, -1486.8350, 1630.4362, 1056.5468, playerid);
			PU_KSS[playerid][7] = CreatePickup(GREEN_PACKAGE, 14, -1384.6793, 1603.8028, 1053.7109, playerid);
			PU_KSS[playerid][8] = CreatePickup(GREEN_PACKAGE, 14, -1408.5103, 1568.8586, 1056.0468, playerid);
			PU_KSS[playerid][9] = CreatePickup(GREEN_PACKAGE, 14, -1354.7637, 1583.5765, 1058.3596, playerid);
			PU_KSS[playerid][10] = CreatePickup(GREEN_PACKAGE, 14, -1377.0338, 1562.3503, 1057.3807, playerid);
			PU_KSS[playerid][11] = CreatePickup(GREEN_PACKAGE, 14, -1398.7708, 1604.2564, 1055.1312, playerid);
			PU_KSS[playerid][12] = CreatePickup(GREEN_PACKAGE, 14, -1387.9177, 1572.2270, 1053.8020, playerid);

			PU_KSS[playerid][13] = CreatePickup(YELLOW_PACKAGE, 14, -1362.8763, 1613.4726, 1055.4641, playerid);
			PU_KSS[playerid][14] = CreatePickup(YELLOW_PACKAGE, 14, -1371.5153, 1623.3035, 1054.8885, playerid);
			PU_KSS[playerid][15] = CreatePickup(YELLOW_PACKAGE, 14, -1462.0891, 1622.5404, 1054.4140, playerid);
			PU_KSS[playerid][16] = CreatePickup(YELLOW_PACKAGE, 14, -1461.9200, 1636.1784, 1054.4140, playerid);
			PU_KSS[playerid][17] = CreatePickup(YELLOW_PACKAGE, 14, -1454.1529, 1636.0413, 1056.4218, playerid);
			PU_KSS[playerid][18] = CreatePickup(YELLOW_PACKAGE, 14, -1431.0374, 1580.7763, 1055.7191, playerid);
			PU_KSS[playerid][19] = CreatePickup(YELLOW_PACKAGE, 14, -1417.8778, 1606.6501, 1055.3203, playerid);
			PU_KSS[playerid][20] = CreatePickup(YELLOW_PACKAGE, 14, -1409.0939, 1618.0404, 1055.3203, playerid);
			PU_KSS[playerid][21] = CreatePickup(YELLOW_PACKAGE, 14, -1405.0095, 1644.5498, 1071.8583, playerid);
			PU_KSS[playerid][22] = CreatePickup(YELLOW_PACKAGE, 14, -1452.8483, 1573.9895, 1057.4111, playerid);
			PU_KSS[playerid][23] = CreatePickup(YELLOW_PACKAGE, 14, -1488.2212, 1564.8015, 1056.6328, playerid);
			
			PU_KSS[playerid][24] = CreatePickup(RED_PACKAGE, 14, -1370.9227, 1635.2860, 1055.8389, playerid);
			PU_KSS[playerid][25] = CreatePickup(RED_PACKAGE, 14, -1359.5809, 1637.7708, 1056.1621, playerid);
			PU_KSS[playerid][26] = CreatePickup(RED_PACKAGE, 14, -1453.9658, 1628.5312, 1054.4140, playerid);
			PU_KSS[playerid][27] = CreatePickup(RED_PACKAGE, 14, -1451.1343, 1620.8309, 1056.0069, playerid);
			PU_KSS[playerid][28] = CreatePickup(RED_PACKAGE, 14, -1454.3531, 1617.3087, 1056.3424, playerid);
			PU_KSS[playerid][29] = CreatePickup(RED_PACKAGE, 14, -1485.1008, 1643.4156, 1060.6718, playerid);
			PU_KSS[playerid][30] = CreatePickup(RED_PACKAGE, 14, -1466.1433, 1594.2271, 1057.6219, playerid);
			PU_KSS[playerid][31] = CreatePickup(RED_PACKAGE, 14, -1390.0844, 1622.2866, 1055.3203, playerid);
	    }
	    case 9..248:
	    {
			SetPVarInt(playerid, "KickstartTime", GetPVarInt(playerid, "KickstartTime") - 1);
			new seconds = GetPVarInt(playerid, "KickstartTime");
			new minutes = floatround(seconds/60);
			seconds -= minutes*60;
	        new string[30];
	        format(string, sizeof string, "TIME__%02d:%02d", minutes, seconds);
	        TextDrawSetString(TDT[playerid], string);
	        SetTimerEx("LoadKickstart", 1000, 0, "d", playerid);
	    }
	    case 249:
	    {
	        TextDrawHideForPlayer(playerid, TDT[playerid]);
	        TextDrawDestroy(TDT[playerid]);
	        TextDrawHideForPlayer(playerid, TDS[playerid]);
	        TextDrawDestroy(TDS[playerid]);
	        GameTextForPlayer(playerid, "FINISH!", 2000, 3);
	        SetTimerEx("LoadKickstart", 2000, 0, "d", playerid);
	    }
	    case 250:
	    {
	        SetPlayerInterior(playerid, 0);
	        SetPlayerVirtualWorld(playerid, 0);
	        SetPlayerWeather(playerid, 0);
	        SetPlayerPos(playerid, 0.0, 0.0, 3.0);
	        SetPlayerFacingAngle(playerid, 0.0);
	        SetCameraBehindPlayer(playerid);
	        GivePlayerMoney(playerid, 5000 * GetPVarInt(playerid, "KickstartScore"));
	        SetPVarInt(playerid, "KickstartScore", 0);
	        SetPVarInt(playerid, "KSIter", 0);
	    }
	}
	return 1;
}
forward ClearCoronas(playerid);
public ClearCoronas(playerid)
{
	TextDrawHideForPlayer(playerid, KSC[6]);
	TextDrawHideForPlayer(playerid, KSC[7]);
	TextDrawHideForPlayer(playerid, KSC[8]);
	return 1;
}
