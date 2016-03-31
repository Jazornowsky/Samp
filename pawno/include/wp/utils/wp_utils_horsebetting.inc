/***
*
* File: wp_utils_horsebetting.inc
* Auth: Damian Wojdat
* Date: 9.06.2012
* Desc: Internal script function related to horse betting.
*
*************************************************************************************************************/

stock HorseInfo(Text:horseid)
{
    TextDrawFont(horseid, 4); 
    TextDrawColor(horseid,0xFFFFFFFF);
    TextDrawTextSize(horseid,64,64); 
}

stock HorseNumInfo(Text:horsenumid)
{
    TextDrawFont(horsenumid, 4); 
    TextDrawColor(horsenumid,0xFFFFFFFF);
    TextDrawTextSize(horsenumid,32,32); 
}

stock HorseRacePrepare(step)
{
	switch(step)
	{
		case 1:
		{
			gHorseCD = 3;
			gHorseStop = 0;

			gHorseBG2 = TextDrawCreate(0, 0, "LD_OTB:bckgrnd");
			TextDrawFont(gHorseBG2, 4);
			TextDrawColor(gHorseBG2,0xFFFFFFFF);
			TextDrawTextSize(gHorseBG2,640,200);

			gHorseBG1 = TextDrawCreate(0, 0, "LD_OTB:trees");
			TextDrawFont(gHorseBG1, 4);
			TextDrawColor(gHorseBG1,0xFFFFFFFF);
			TextDrawTextSize(gHorseBG1,640,480);

			gHorseStart2 = TextDrawCreate(-170, 145, "LD_OTB:pole2");
			TextDrawFont(gHorseStart2, 4);
			TextDrawColor(gHorseStart2,0xFFFFFFFF);
			TextDrawTextSize(gHorseStart2,256,200);

			gHorseFinish2 = TextDrawCreate(365, 145, "LD_OTB:pole2");
			TextDrawFont(gHorseFinish2, 4);
			TextDrawColor(gHorseFinish2,0xFFFFFFFF);
			TextDrawTextSize(gHorseFinish2,256,200);

			gHorse1 = TextDrawCreate(0, 200, "LD_OTB:hrs8");
			HorseInfo(gHorse1);
			gHorsePosX1 = 0;

			gHorse2 = TextDrawCreate(0, 250, "LD_OTB:hrs8");
			HorseInfo(gHorse2);
			gHorsePosX2 = 0;

			gHorse3 = TextDrawCreate(0, 300, "LD_OTB:hrs8");
			HorseInfo(gHorse3);
			gHorsePosX3 = 0;

			gHorse4 = TextDrawCreate(0, 350, "LD_OTB:hrs8");
			HorseInfo(gHorse4);
			gHorsePosX4 = 0;

			gHorseNum1 = TextDrawCreate(15, 204, "LD_OTB2:Ric1");
			HorseNumInfo(gHorseNum1);

			gHorseNum2 = TextDrawCreate(15, 254, "LD_OTB2:Ric2");
			HorseNumInfo(gHorseNum2);

			gHorseNum3 = TextDrawCreate(15, 304, "LD_OTB2:Ric3");
			HorseNumInfo(gHorseNum3);

			gHorseNum4 = TextDrawCreate(15, 354, "LD_OTB2:Ric4");
			HorseNumInfo(gHorseNum4);

			gHorseStart = TextDrawCreate(-170, 338, "LD_OTB:pole2");
			TextDrawFont(gHorseStart, 4);
			TextDrawColor(gHorseStart,0xFFFFFFFF);
			TextDrawTextSize(gHorseStart,256,200);

			gHorseFinish = TextDrawCreate(365, 338, "LD_OTB:pole2");
			TextDrawFont(gHorseFinish, 4);
			TextDrawColor(gHorseFinish,0xFFFFFFFF);
			TextDrawTextSize(gHorseFinish,256,200);

			gHorseCDTextDraw = TextDrawCreate(310,235,"3");
			TextDrawAlignment(gHorseCDTextDraw,0);
			TextDrawBackgroundColor(gHorseCDTextDraw,0x000000ff);
			TextDrawFont(gHorseCDTextDraw,2);
			TextDrawLetterSize(gHorseCDTextDraw,0.5,2);
			TextDrawColor(gHorseCDTextDraw,0x00ff0099);
			TextDrawSetOutline(gHorseCDTextDraw,1);
			TextDrawSetProportional(gHorseCDTextDraw,1);
			TextDrawSetShadow(gHorseCDTextDraw,1);

			gHorseAnimCount = 1;
			gHorsePrepared = 1;
		}
		case 2:
		{
			foreach(Player, i)
			{
				if(gPlayerVars[i][mAtBuildingId] == 121)
				{
					SendClientMessage(i, COLOR_LIGHTYELLOW2, "[INFO:] Wyœcig siê rozpoczyna, koniec zak³adów ! Wpisz /ogladaj aby zobaczyæ wyœcig");
					PlayerPlaySound(i, 5410, 0, 0, 0);
				}
			}
			gHorseRaceStarted = 1;
			gHorsePrepared = 0;
		}
	}
}

timer HorseAnim[100]()
{
	new string[12], lHorseWon;
 	format(string, sizeof(string), "LD_OTB:hrs%i", gHorseAnimCount);
 	gHorseAnimCount++;
 	if(gHorseAnimCount == 9)
		gHorseAnimCount = 1;

  	gHorsePosX1 = gHorsePosX1 + (random(600) / 100);
  	gHorsePosX2 = gHorsePosX2 + (random(600) / 100);
  	gHorsePosX3 = gHorsePosX3 + (random(600) / 100);
  	gHorsePosX4 = gHorsePosX4 + (random(600) / 100);

  	TextDrawDestroy(gHorse1);
  	TextDrawDestroy(gHorse2);
  	TextDrawDestroy(gHorse3);
  	TextDrawDestroy(gHorse4);
  	TextDrawDestroy(gHorseNum1);
  	TextDrawDestroy(gHorseNum2);
  	TextDrawDestroy(gHorseNum3);
  	TextDrawDestroy(gHorseNum4);


    gHorse1 = TextDrawCreate(gHorsePosX1, 200, string); 
    HorseInfo(gHorse1);
    gHorse2 = TextDrawCreate(gHorsePosX2, 250, string); 
    HorseInfo(gHorse2);
    gHorse3 = TextDrawCreate(gHorsePosX3, 300, string); 
    HorseInfo(gHorse3);
    gHorse4 = TextDrawCreate(gHorsePosX4, 350, string); 
    HorseInfo(gHorse4);
    gHorseNum1 = TextDrawCreate(gHorsePosX1 + 15, 204, "LD_OTB2:Ric1"); 
    HorseNumInfo(gHorseNum1);
    gHorseNum2 = TextDrawCreate(gHorsePosX2 + 15, 254, "LD_OTB2:Ric2"); 
    HorseNumInfo(gHorseNum2);
    gHorseNum3 = TextDrawCreate(gHorsePosX3 + 15, 304, "LD_OTB2:Ric3"); 
    HorseNumInfo(gHorseNum3);
    gHorseNum4 = TextDrawCreate(gHorsePosX4 + 15, 354, "LD_OTB2:Ric4"); 
    HorseNumInfo(gHorseNum4);

	new betsOnHorse[4], allBets;
	
	foreach(Player, i)
	{
		if(gHorseWatching[i] == 1)
		{
			TextDrawShowForPlayer(i, gHorse1);
			TextDrawShowForPlayer(i, gHorse2);
			TextDrawShowForPlayer(i, gHorse3);
			TextDrawShowForPlayer(i, gHorse4);
			TextDrawShowForPlayer(i, gHorseNum1);
			TextDrawShowForPlayer(i, gHorseNum2);
			TextDrawShowForPlayer(i, gHorseNum3);
			TextDrawShowForPlayer(i, gHorseNum4);
		}
		if(gHorseBetOnHorse[i] == 1)
			betsOnHorse[0]++;
		else if(gHorseBetOnHorse[i] == 2)
			betsOnHorse[1]++;
		else if(gHorseBetOnHorse[i] == 3)
			betsOnHorse[2]++;
		else if(gHorseBetOnHorse[i] == 4)
			betsOnHorse[3]++;
		if(gHorseBetOnHorse[i] != 0)
			allBets++;
	}
	
	new Float:winValue;
	// Wzor na wygrana
	// MAX_LOOSE_IN_%^(LOG(LP_ALL,LP_STACK))
	if(gHorsePosX1 >= 560)
	{
		foreach(Player, i)
		{
			if(gHorseBetOnHorse[i] == 1)
			{
				if(allBets == 1)
					winValue = gHorseMoneyBet[i];
				else
					winValue = (3.0 - (floatpower(2.0, floatlog(float(allBets), float(betsOnHorse[0]))))) * gHorseMoneyBet[i];
				
				gPlayerData[i][pBank] += floatround(winValue - (winValue * DynamicTaxes[VatTaxMax]));
				DynamicFactions[FACTIONID_GOVERNMENT][fBank] -= floatround(winValue - (winValue * DynamicTaxes[VatTaxMax]));
			}
			if(gPlayerVars[i][mAtBuildingId] == 121)
				SendClientMessage(i, COLOR_ORANGE, "[INFO:] Wygra³ koñ z numerem 1 !");
		}
		gHorseStop = 1;
		lHorseWon = 1;
	}
	else if(gHorsePosX2 >= 560)
	{
		foreach(Player, i)
		{
			if(gHorseBetOnHorse[i] == 2)
			{
				if(allBets == 1)
					winValue = gHorseMoneyBet[i];
				else
					winValue = (3.0 - (floatpower(2.0, floatlog(float(allBets), float(betsOnHorse[1]))))) * gHorseMoneyBet[i];
				
				if(gPlayerVars[i][mAtBuildingId] == 121)
					GivePlayerCash(i, floatround(winValue - (winValue * DynamicTaxes[VatTaxMax])));
				else
					gPlayerData[i][pBank] += floatround(winValue - (winValue * DynamicTaxes[VatTaxMax]));
				DynamicFactions[FACTIONID_GOVERNMENT][fBank] -= floatround(winValue - (winValue * DynamicTaxes[VatTaxMax]));
			}
			if(gPlayerVars[i][mAtBuildingId] == 121)
				SendClientMessage(i, COLOR_ORANGE, "[INFO:] Wygra³ koñ z numerem 2 !");
		}
		gHorseStop = 1;
		lHorseWon = 2;
	}
	else if(gHorsePosX3 >= 560)
	{
		foreach(Player, i)
		{
			if(gHorseBetOnHorse[i] == 3)
			{
				if(allBets == 1)
					winValue = gHorseMoneyBet[i];
				else
					winValue = (3.0 - (floatpower(2.0, floatlog(float(allBets), float(betsOnHorse[2]))))) * gHorseMoneyBet[i];
				
				gPlayerData[i][pBank] += floatround(winValue - (winValue * DynamicTaxes[VatTaxMax]));
				DynamicFactions[FACTIONID_GOVERNMENT][fBank] -= floatround(winValue - (winValue * DynamicTaxes[VatTaxMax]));
			}
			if(gPlayerVars[i][mAtBuildingId] == 121)
				SendClientMessage(i, COLOR_ORANGE, "[INFO:] Wygra³ koñ z numerem 3 !");
		}
		gHorseStop = 1;
		lHorseWon = 3;
	}
	else if(gHorsePosX4 >= 560)
	{
		foreach(Player, i)
		{
			if(gHorseBetOnHorse[i] == 4)
			{
				if(allBets == 1)
					winValue = gHorseMoneyBet[i];
				else
					winValue = (3.0 - (floatpower(2.0, floatlog(float(allBets), float(betsOnHorse[3]))))) * gHorseMoneyBet[i];
				
				gPlayerData[i][pBank] += floatround(winValue - (winValue * DynamicTaxes[VatTaxMax]));
				DynamicFactions[FACTIONID_GOVERNMENT][fBank] -= floatround(winValue - (winValue * DynamicTaxes[VatTaxMax]));
			}
			if(gPlayerVars[i][mAtBuildingId] == 121)
				SendClientMessage(i, COLOR_ORANGE, "[INFO:] Wygra³ koñ z numerem 4 !");
		}
		gHorseStop = 1;
		lHorseWon = 4;
	}
	
	if(gHorseStop)
	{
		gHorseStop = 0;
		gHorseRaceStarted = 0;
		TextDrawDestroy(gHorseBG2);
		TextDrawDestroy(gHorseBG1);
		TextDrawDestroy(gHorseStart2);
		TextDrawDestroy(gHorseFinish2);
		TextDrawDestroy(gHorse1);
		TextDrawDestroy(gHorse2);
		TextDrawDestroy(gHorse3);
		TextDrawDestroy(gHorse4);
		TextDrawDestroy(gHorseNum1);
		TextDrawDestroy(gHorseNum2);
		TextDrawDestroy(gHorseNum3);
		TextDrawDestroy(gHorseNum4);
		TextDrawDestroy(gHorseStart);
		TextDrawDestroy(gHorseFinish);
		foreach(Player, i)
		{
			if(gHorseMoneyBet[i] != 0)
			{
				if(gHorseBetOnHorse[i] == lHorseWon)
				{
					if(gPlayerVars[i][mAtBuildingId] == 121)
					{
						PlayerPlaySound(i, 5448, 0, 0, 0);
						SendClientMessage(i, COLOR_GREEN, "Wygra³eœ !");
					}
				}
				else if(gHorseBetOnHorse[i] != lHorseWon)
				{
					if(gPlayerVars[i][mAtBuildingId] == 121)
					{
						PlayerPlaySound(i, 5453, 0, 0, 0);
						SendClientMessage(i, COLOR_GREEN, "Przegra³eœ !");
					}
				}
				gHorseMoneyBet[i] = 0;
				gHorseBetOnHorse[i] = 0;
			}
			if(gHorseWatching[i] == 1)
			{
				TogglePlayerControllable(i, 1);
			}
		}
	}
	else
		defer HorseAnim();
}