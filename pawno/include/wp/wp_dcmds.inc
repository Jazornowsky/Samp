/***
*
* File: wp_dcmds.inc
* Auth: Damian Wojdat
* Date: 15.09.2011
* Desc: Player commands.
*
*************************************************************************************************************/

#include <string>

dcmd_noooc(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] < 5)
		return 0;
	if(!noooc)
	{
		noooc = 1;
		BroadCast(COLOR_GRAD2, "[INFO:] Globalny chat (OOC) zostal WY£¥CZONY !");
	}
	else
	{
		noooc = 0;
		BroadCast(COLOR_GRAD2, "[INFO:] Globalny chat (OOC) zostal W£¥CZONY !");
	}
	return 1;
}

dcmd_nofooc(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] < 5)
		return 0;
	if(!nofooc)
	{
		nofooc = 1;
		BroadCast(COLOR_GRAD2, "   Globalny chat frakcyjny (FOOC) zostal WY£¥CZONY !");
	}
	else
	{
		nofooc = 0;
		BroadCast(COLOR_GRAD2, "   Globalny chat frakcyjny (FOOC) zostal W£¥CZONY !");
	}
	return 1;
}

dcmd_nopwooc(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] < 5)
		return 0;
	if(!nopwooc)
	{
		nopwooc = 1;
		BroadCast(COLOR_GRAD2, "[INFO:] Globalny chat pw (PWOOC) zostal WY£¥CZONY !");
	}
	else
	{
		nopwooc = 0;
		BroadCast(COLOR_GRAD2, "[INFO:] Globalny chat pw (PWOOC) zostal W£¥CZONY !");
	}
	return 1;
}

dcmd_radios(playerid, params[])
{
	#pragma unused params
	
	ShowPlayerDialog(playerid, DIALOG_RADIO_CHANNELS, DIALOG_STYLE_LIST, "Lista radiostacji", RADIO_CHANNELS_DIALOG, "Wybierz kana³", "Zamknij");
	
	return 1;
}

dcmd_radiosoff(playerid, params[])
{
	#pragma unused params
	new vehid = GetPlayerVehicleID(playerid);
	if(vehid == 0)
		return 1;

	if(gVehData[vehid-1][RadioOn] != 0)
	{
		StopCarRadioStation(vehid);
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2,"[INFO:] Wy³¹czy³eœ radio");
		PlayerActionMessage(playerid,15.0,"wy³¹czy³ radio");
	}
	else
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2,"[INFO:] Nie masz w³¹czonego radia !");
	}
	return 1;
}

dcmd_komendywojska(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pFaction] == 6)
	{
		SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[WSOSP:] /kuojczyznie - /owoj1 - /owoj2 - /zwoj2 - /ar");
		return 1;
	}
	else
	{
		SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] Niew³aœciwa frakcja");
		return 1;
	}
}

dcmd_danebiz(playerid, params[])
{
	if(gPlayerData[playerid][pFaction] != FACTIONID_GOVERNMENT)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ urzêdnikiem");
		return 1;
	}
	new bizID;
	if(sscanf(params, "d", bizID))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /danebiz [id biznesu (0-299)]");
		return 1;
	}
	if(bizID >= sizeof(Businesses) || bizID < 0)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] /danebiz [id biznesu (0-299)]");
		return 1;
	}
	new string[128];
	format(string, sizeof(string), "[INFO:] Kupiony - %d, W³aœciciel - %s, ID interioru - %d", Businesses[bizID][Owned], Businesses[bizID][Owner], Businesses[bizID][BInterior]);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	return 1;
}

dcmd_danedomu(playerid, params[])
{
	if(gPlayerData[playerid][pFaction] != FACTIONID_GOVERNMENT)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ urzêdnikiem");
		return 1;
	}
	new hID;
	if(sscanf(params, "d", hID))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /danedomu [id domu (0-499)]");
		return 1;
	}
	if(hID >= 500 || hID < 0)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] /danedomu [id domu (0-499)]");
		return 1;
	}
	new string[128];
	format(string, sizeof(string), "[INFO:] Kupiony - %d, W³aœciciel - %s, ID interioru - %d", Houses[hID][Owned], Houses[hID][Owner], Houses[hID][HInterior]);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	return 1;
}

dcmd_abizdata(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] == 0)
		return 0;
	
	new string[512];
	new bizId;
	
	if(sscanf(params, "d", bizId))
	{
		if(gPlayerVars[playerid][mAtBizID] != -1)
		{
			format(string, sizeof(string), "ID: %d\nOwner: %s\nEnterWorld: %d\nEnterInterior: %d\nExitInterior: %d\nOwned: %d\nEnterable: %d\nBizPrice: %d\nTill: %d\n",
			gPlayerVars[playerid][mAtBizID], Businesses[gPlayerVars[playerid][mAtBizID]][Owner], Businesses[gPlayerVars[playerid][mAtBizID]][EnterWorld],Businesses[gPlayerVars[playerid][mAtBizID]][EnterInterior],Businesses[gPlayerVars[playerid][mAtBizID]][ExitInterior],Businesses[gPlayerVars[playerid][mAtBizID]][Owned],Businesses[gPlayerVars[playerid][mAtBizID]][Enterable],Businesses[gPlayerVars[playerid][mAtBizID]][BizPrice],Businesses[gPlayerVars[playerid][mAtBizID]][Till]);

			format(string, sizeof(string),"%sEntranceCost: %d\n Locked: %d\nBizType: %d\nProducts: %d\nPickupID: %d\nMaxVehicles: %d\nVehSpawned: %d\n",
			string, Businesses[gPlayerVars[playerid][mAtBizID]][EntranceCost],Businesses[gPlayerVars[playerid][mAtBizID]][Locked],Businesses[gPlayerVars[playerid][mAtBizID]][BizType],Businesses[gPlayerVars[playerid][mAtBizID]][Products],Businesses[gPlayerVars[playerid][mAtBizID]][PickupID], Businesses[gPlayerVars[playerid][mAtBizID]][MaxVehicles], Businesses[gPlayerVars[playerid][mAtBizID]][VehicleSpawned]);

			format(string, sizeof(string),"%sVehCount: %d\nVehOrderCount: %d\nConfiscated: %d\nOwner: %s\nInterior: %d\nUID: %d\nName: %s",
			string, Businesses[gPlayerVars[playerid][mAtBizID]][VehicleCount], Businesses[gPlayerVars[playerid][mAtBizID]][VehicleOrderCount], Businesses[gPlayerVars[playerid][mAtBizID]][BConfiscated], Businesses[gPlayerVars[playerid][mAtBizID]][Owner], Businesses[gPlayerVars[playerid][mAtBizID]][BInterior], Businesses[gPlayerVars[playerid][mAtBizID]][BUID], Businesses[gPlayerVars[playerid][mAtBizID]][BusinessName]);

			ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Biznes", string, "Zamknij", "");
			
			return 1;
		}
		
		for(bizId = 0; bizId < sizeof(Businesses); bizId++)
		{
			if(!PlayerToPoint(2.0, playerid, Businesses[bizId][EnterX], Businesses[bizId][EnterY], Businesses[bizId][EnterZ]))
			{
				continue;
			}
			
			format(string, sizeof(string), "ID: %d\nOwner: %s\nEnterWorld: %d\nEnterInterior: %d\nExitInterior: %d\nOwned: %d\nEnterable: %d\nBizPrice: %d\nTill: %d\n",
			bizId, Businesses[bizId][Owner], Businesses[bizId][EnterWorld], Businesses[bizId][EnterInterior],Businesses[bizId][ExitInterior],Businesses[bizId][Owned],Businesses[bizId][Enterable],Businesses[bizId][BizPrice],Businesses[bizId][Till]);

			format(string, sizeof(string),"%sEntranceCost: %d\n Locked: %d\nBizType: %d\nProducts: %d\nPickupID: %d\nMaxVehicles: %d\nVehSpawned: %d\n",
			string, Businesses[bizId][EntranceCost],Businesses[bizId][Locked],Businesses[bizId][BizType],Businesses[bizId][Products],Businesses[bizId][PickupID], Businesses[bizId][MaxVehicles], Businesses[bizId][VehicleSpawned]);

			format(string, sizeof(string),"%sVehCount: %d\nVehOrderCount: %d\nConfiscated: %d\nInterior: %d\nUID: %d\nName: %s",
			string, Businesses[bizId][VehicleCount], Businesses[bizId][VehicleOrderCount], Businesses[bizId][BConfiscated], Businesses[bizId][BInterior], Businesses[bizId][BUID], Businesses[bizId][BusinessName]);
			
			ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Biznes", string, "Zamknij", "");
			
			return 1;
		}
		
		SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] /abizdata [id biznesu]");
		return 1;
	}
	
	format(string, sizeof(string), "ID: %d\nOwner: %s\nEnterWorld: %d\nEnterInterior: %d\nExitInterior: %d\nOwned: %d\nEnterable: %d\nBizPrice: %d\nTill: %d\n",
	bizId, Businesses[bizId][Owner], Businesses[bizId][EnterWorld],Businesses[bizId][EnterInterior],Businesses[bizId][ExitInterior],Businesses[bizId][Owned],Businesses[bizId][Enterable],Businesses[bizId][BizPrice],Businesses[bizId][Till]);

	format(string, sizeof(string),"%sEntranceCost: %d\n Locked: %d\nBizType: %d\nProducts: %d\nPickupID: %d\nMaxVehicles: %d\nVehSpawned: %d\n",
	string, Businesses[bizId][EntranceCost],Businesses[bizId][Locked],Businesses[bizId][BizType],Businesses[bizId][Products],Businesses[bizId][PickupID], Businesses[bizId][MaxVehicles], Businesses[bizId][VehicleSpawned]);

	format(string, sizeof(string),"%sVehCount: %d\nVehOrderCount: %d\nConfiscated: %d\nInterior: %d\nUID: %d\nName: %s",
	string, Businesses[bizId][VehicleCount], Businesses[bizId][VehicleOrderCount], Businesses[bizId][BConfiscated], Businesses[bizId][BInterior], Businesses[bizId][BUID], Businesses[bizId][BusinessName]);
	
	ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Biznes", string, "Zamknij", "");
	
	return 1;
}

dcmd_ahousedata(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] == 0)
		return 0;
	
	new string[1024];
	new hId;
	
	if(sscanf(params, "d", hId))
	{
		if(gPlayerVars[playerid][mAtHouseID] != -1)
		{
			format(string, sizeof(string), "ID: %d\nOwner: %s\nEnterWorld: %d\nEnterInterior: %d\nExitInterior: %d\nOwned: %d\nRentable: %d\nRentCost: %d\n",
				gPlayerVars[playerid][mAtHouseID], Houses[gPlayerVars[playerid][mAtHouseID]][Owner], Houses[gPlayerVars[playerid][mAtHouseID]][EnterWorld], Houses[gPlayerVars[playerid][mAtHouseID]][EnterInterior], Houses[gPlayerVars[playerid][mAtHouseID]][ExitInterior], Houses[gPlayerVars[playerid][mAtHouseID]][Owned], Houses[gPlayerVars[playerid][mAtHouseID]][Rentable], Houses[gPlayerVars[playerid][mAtHouseID]][RentCost]);
			format(string, sizeof(string), "%sHousePrice: %d\nMoney: %d\nLocked: %d\nPickupID: %d\nConfiscated: %d\nHUID: %d\n",
				string, Houses[gPlayerVars[playerid][mAtHouseID]][HousePrice], Houses[gPlayerVars[playerid][mAtHouseID]][Money], Houses[gPlayerVars[playerid][mAtHouseID]][Locked], Houses[gPlayerVars[playerid][mAtHouseID]][PickupID], Houses[gPlayerVars[playerid][mAtHouseID]][HConfiscated], Houses[gPlayerVars[playerid][mAtHouseID]][HUID]);
			
			ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Dom", string, "Zamknij", "");
			return 1;
		}
		
		for(hId = 0; hId < sizeof(Houses); hId++)
		{
			if(!PlayerToPoint(2.0, playerid, Houses[hId][EnterX], Houses[hId][EnterY], Houses[hId][EnterZ]))
			{
				continue;
			}
			
			format(string, sizeof(string), "ID: %d\nOwner: %s\nEnterWorld: %d\nEnterInterior: %d\nExitInterior: %d\nOwned: %d\nRentable: %d\nRentCost: %d\n",
				hId, Houses[hId][EnterWorld], Houses[hId][Owner], Houses[hId][EnterInterior], Houses[hId][ExitInterior], Houses[hId][Owned], Houses[hId][Rentable], Houses[hId][RentCost]);
			format(string, sizeof(string), "%sHousePrice: %d\nMoney: %d\nLocked: %d\nPickupID: %d\nConfiscated: %d\nHUID: %d\n",
				string, Houses[hId][HousePrice], Houses[hId][Money], Houses[hId][Locked], Houses[hId][PickupID], Houses[hId][HConfiscated], Houses[hId][HUID]);
			
			ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Dom", string, "Zamknij", "");
			return 1;
		}
		
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Podaj id domu lub przejdŸ do ikonki");
		return 1;
	}
	
	if(hId < 0 || hId >= sizeof(Houses))
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Niepoprawne id domu");
		return 1;
	}
	format(string, sizeof(string), "ID: %d\nOwner: %s\nEnterWorld: %d\nEnterInterior: %d\nExitInterior: %d\nOwned: %d\nRentable: %d\nRentCost: %d\n",
		hId, Houses[hId][EnterWorld], Houses[hId][Owner], Houses[hId][EnterInterior], Houses[hId][ExitInterior], Houses[hId][Owned], Houses[hId][Rentable], Houses[hId][RentCost]);
	format(string, sizeof(string), "%sHousePrice: %d\nMoney: %d\nLocked: %d\nPickupID: %d\nConfiscated: %d\nHUID: %d\n",
		string, Houses[hId][HousePrice], Houses[hId][Money], Houses[hId][Locked], Houses[hId][PickupID], Houses[hId][HConfiscated], Houses[hId][HUID]);
	
	ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Dom", string, "Zamknij", "");
	return 1;
}

dcmd_abuildingopent(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] < 4)
		return 0;
	new string[128];
	new idbuilding;
	new hour;
	if(sscanf(params, "dd", idbuilding, hour))
	{
		SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] /abuildingopent [buildingid] [hour]");
		return 1;
	}
	Building[idbuilding][Opened] = hour;
	format(string, sizeof(string), "[ADMIN:] %s has changed open hour for building id: %d to %d", GetPlayerNameEx(playerid), idbuilding, hour);
	SendAdminMessage(COLOR_YELLOW, string);
	return 1;
}

dcmd_abuildingcloset(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] < 4)
		return 0;
	new string[128];
	new idbuilding;
	new hour;
	if(sscanf(params, "dd", idbuilding, hour))
	{
		SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] /abuildingcloset [buildingid] [hour]");
		return 1;
	}
	Building[idbuilding][Closed] = hour;
	format(string, sizeof(string), "[ADMIN:] %s has changed close hour for building id: %d to %d", GetPlayerNameEx(playerid), idbuilding, hour);
	SendAdminMessage(COLOR_YELLOW, string);
	return 1;
}
/*
dcmd_kupczesci(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pJob] == 17)
	{
		if(PlayerToPoint(3.0,playerid,MechanicJob2[BuyProductsX],MechanicJob2[BuyProductsY],MechanicJob2[BuyProductsZ]))
		{
			if(gPlayerData[playerid][pParts] <= 10)
			{
				if(gPlayerData[playerid][pParts] + 1 <= 10)
				{
					new string[128];
					if(GetPlayerCash(playerid) >= PARTS_PRICE)
					{
						format(string, sizeof(string), "[INFO:] Kupi³eœ czêœæ - koszt: $%d", PARTS_PRICE);
						SendClientMessage(playerid, COLOR_GREEN, string);
						SendClientMessage(playerid, COLOR_GREEN, "[INFO:] Mo¿esz teraz u¿yæ tych czêœci do naprawy pojazdów.");

						// TODO: Cash is gone to nowhere, we need to do something with this
						GivePlayerCash(playerid, -PARTS_PRICE);

						gPlayerData[playerid][pParts]++;
						SavePlayerData(playerid, "Parts");

						return 1;
					}
					else
					{
						SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie masz wystarczaj¹cej iloœci pieniêdzy");
						return 1;
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie mo¿esz przenosiæ wiêcej ni¿ 10 czêœci.");
					return 1;
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie mo¿esz przenosiæ wiêcej ni¿ 10 czêœci.");
				return 1;
			}
		}
		else
		{
			SendClientMessage(playerid,COLOR_RED, "[INFO:] Nie jesteœ w miejscu skupu czêœci.");
			return 1;
		}
	}
	else
	{
		SendClientMessage(playerid,COLOR_RED, "[INFO:] Nie jesteœ mechanikiem !");
		return 1;
	}
} // end of dcmd_kupczesci*/

dcmd_wyrobkarte(playerid, params[])
{
	#pragma unused params
	if(IsAtBank(playerid))
	{
		if(PHaveItem(playerid, 1, 3) == 0)
		{
			if(InsertPlayerItem(playerid, 1, 3, 0, 0) == 0)
			{
				SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie posiadasz ju¿ miejsca !");
				return 1;
			}
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[SUKCES:] Otrzyma³eœ karte p³atnicz¹ !");
		}
		else
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Posiadasz ju¿ karte p³atnicz¹ !");
			return 1;
		}
	}
	return 1;
}

dcmd_podladujakumulator(playerid, params[])
{
	#pragma unused params
	
	if(gPlayerData[playerid][pJob] != JOB_MECHANIC && !AdminDuty[playerid])
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie jesteœ mechanikiem");
		return 1;
	}
	
	if(gPlayerData[playerid][pFaction2] == 255)
	{
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Musisz nale¿eæ do firmy aby naprawiaæ pojazdy.", "Wróæ", "");
		return 1;
	}
	
	if(IsPlayerInAnyVehicle(playerid))
	{
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Musisz byæ obok pojazdu.", "Wróæ", "");
		return 1;
	}
	
	new inCompanyMech = 0;
	
	for(new i = 0; i < sizeof(Building); i++)
	{
		if(Building[i][FactionOwnerId] != gPlayerData[playerid][pFaction2])
		{
			continue;
		}
		
		if(!PlayerToPoint(15.0, playerid, Building[i][EnterX], Building[i][EnterY], Building[i][EnterZ]) && !PlayerToPoint(30.0, playerid, Building[i][ExitX], Building[i][ExitY], Building[i][ExitZ]))
		{
			continue;
		}
		
		inCompanyMech = 1;
	}
	
	if(!inCompanyMech && !AdminDuty[playerid])
	{
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Musisz znajdowaæ siê przy warsztacie twojej firmy.", "Wróæ", "");
		return 1;
	}
	
	new vehId = GetClosestVehicle(playerid);
	
	if(vehId != INVALID_VEHICLE_ID)
	{
		if(gVehData[vehId-1][EngineOn])
		{
			ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Wy³¹cz silnik przed rozpoczêciem napraw.", "Wróæ", "");
			return 1;
		}
		
		if(!IsInFrontOfHood(playerid, vehId) && !IsAMotorBike(vehId))
		{
			ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Musisz byæ przed mask¹ aby pod³adowaæ akumulator.", "Wróæ", "");
			return 1;
		}
		
		if(!IsHoodOpened(playerid, vehId) && !IsAMotorBike(vehId))
		{
			ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Otwórz maske przed rozpoczêciem naprawy.", "Wróæ", "");
			return 1;
		}
		
		if(gVehData[vehId-1][BatteryMaxCapacity] < 10.0)
		{
			ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Napiêcie akumulatora wskazuje na jego wysokie zu¿ycie.", "Wróæ", "");
		}
		
		if(gVehData[vehId-1][BatteryCapacity] < gVehData[vehId-1][BatteryMaxCapacity]*0.2)
		{
			gVehData[vehId-1][BatteryCapacity] = gVehData[vehId-1][BatteryMaxCapacity]*0.2;
			return 1;
		}
		
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Akumulator zosta³ pod³adowany !");
		
		return 1;
	}
	
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ przy ¿adnym pojeŸdzie");
	return 1;
}
/*
dcmd_naprawpojazd(playerid, params[])
{
	if(gPlayerData[playerid][pJob] != 17)
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie jesteœ mechanikiem !");
		return 1;
	}
	new inPoint = 0;
	if( ( !PlayerToPoint(50.0,playerid,MechanicJob1[RepairPointX],MechanicJob1[RepairPointY],MechanicJob1[RepairPointZ]) &&
	!PlayerToPoint(50.0,playerid,MechanicJob1[RepairPointX2],MechanicJob1[RepairPointY2],MechanicJob1[RepairPointZ2]) ) &&
	!PlayerToPoint(50.0,playerid,-2099.0,-2240.0,30.0))
	{
		for(new i = 0; i < 10; i++)
		{
			if(PlayerToPoint(50.0, playerid, MechanicJob1[RepairPointX3][i], MechanicJob1[RepairPointY3][i], MechanicJob1[RepairPointZ3][i]))
				inPoint = 1;
		}
		if(!inPoint)
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Aby naprawiæ pojazd musisz byæ w warsztacie !");
			return 1;
		}
	}
	new string[128];
	if(gPlayerData[playerid][pMechanicCoolDown]> 0)
	{
		format(string, sizeof(string), "[INFO:] Jesteœ ju¿ zajêty jednym pojazdem. Musisz jeszcze odczekaæ %d sekund", gPlayerData[playerid][pMechanicCoolDown]);
		SendClientMessage(playerid, COLOR_ORANGE, string);
		return 1;
	}
	if(gPlayerData[playerid][pParts] >= 1)
	{
		new idcar;
		if(sscanf(params, "d", idcar))
		{
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] /naprawpojazd [rejestracja]");
			return 1;
		}
		idcar = CarSerialToID(idcar);
		if(idcar == -1)
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie ma pojazdu z tak¹ rejestracj¹ !");
			return 1;
		}
		GetVehiclePos(idcar+1, gVehData[idcar][mVehX], gVehData[idcar][mVehY], gVehData[idcar][mVehZ]);
		if(!PlayerToPoint(50.0, playerid, gVehData[idcar][mVehX], gVehData[idcar][mVehY], gVehData[idcar][mVehZ]))
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Naprawiany pojazd musi byæ w punkcie naprawy");
			return 1;
		}
		if(gVehData[idcar][EngineOn])
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Wy³¹cz silnik przed rozpoczêciem napraw");
			return 1;
		}
		new Float:vehiclehp;
		GetVehicleHealth(idcar+1, vehiclehp);
		if(vehiclehp >= 1000.0)
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten pojazd jest w bardzo dobrym stanie i nie wymaga naprawy");
			return 1;
		}
		new Float:percenttorepair = 1000.0 - vehiclehp;
		if(percenttorepair > 500.0)
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Ten pojazd ma zbyt powa¿ne uszkodzenia i nie da siê go naprawiæ");
			return 1;
		}
		gVehData[idcar][CarRepairTimeLeft] = (floatround(percenttorepair,floatround_round) * REPAIR_TIME_MULTIPLIER)/10;
		gPlayerData[playerid][pParts]--;
		SavePlayerData(playerid, "Parts");
		if(gVehData[idcar][CarRepairTimeLeft] < 5)
		{
			gVehData[idcar][CarRepairTimeLeft] = 5;
			SaveVehData(idcar, "CarRepairTimeLeft");

			format(string, sizeof(string), "[INFO:] Naprawa pojazdu potrwa %d minut", gVehData[idcar][CarRepairTimeLeft]);
			printf("[VEHICLE:] Repaired by: %s, time left: %d", GetPlayerNameEx(playerid), gVehData[idcar][CarRepairTimeLeft]);
		}
		else
		{
			if(floatround(percenttorepair,floatround_round) >= 60) // 60 = 1 minuta
			{
				format(string, sizeof(string), "[INFO:] Naprawa pojazdu potrwa %d godzin", floatround(gVehData[idcar][CarRepairTimeLeft]/60));
			}
			else
			{
				format(string, sizeof(string), "[INFO:] Naprawa pojazdu potrwa %d minut", gVehData[idcar][CarRepairTimeLeft]);
			}
			printf("[VEHICLE:] Repaired by: %s, time left: %d", GetPlayerNameEx(playerid), gVehData[idcar][CarRepairTimeLeft]);
		}
		gPlayerData[playerid][pMechanicCoolDown] = 600;
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
		PlayerActionMessage(playerid,15.0,"zacz¹³ grzebaæ przy pojeŸdzie");
	}
	else
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Musisz zakupiæ czêœci zanim naprawisz pojazd !");
		return 1;
	}
	return 1;
} // end of dcmd_naprawpojazd*/

dcmd_owoj1(playerid,params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pFaction] == 6 && DynamicFactions[gPlayerData[playerid][pFaction]][fType] == 1)
	{
		SetDynamicObjectRot (gGateSfMilitary1a, 0.000000, 0.000000, 9.75);
		ArmyGate1Close();
		SendFactionMessage(6, COLOR_NATIONALGUARD,"[WSOSP:] G³ówny wjazd otwarty !");
		return 1;
	}
	else
	{
		new tmpstring[256];
		format(tmpstring, sizeof(tmpstring), "Frakcja: %d, Typ: %d",gPlayerData[playerid][pFaction], DynamicFactions[gPlayerData[playerid][pFaction]][fType]);
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Niew³aœciwa frakcja/typ.");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, tmpstring);
		return 1;
	}
}

dcmd_owoj2(playerid,params[])
{
	#pragma unused params
	#pragma unused playerid
	SetDynamicObjectRot (gGateSfMilitary2a,0.0,359.74731445313,79.8076171875);
	SetDynamicObjectRot (gGateSfMilitary3a,0.000000, 359.75, 82.370025634766);
	SendFactionMessage(6, COLOR_NATIONALGUARD,"[WSOSP:] Wjazd do wojska otwarty !");
	return 1;
}

dcmd_zwoj2(playerid,params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pFaction] == 6 && DynamicFactions[gPlayerData[playerid][pFaction]][fType] == 1 )
	{
		SetDynamicObjectRot (gGateSfMilitary2a, 0.0, 270.64294433594, 79.619995117188);
		SetDynamicObjectRot (gGateSfMilitary3a, 0.0, 88.36669921875, 85.869995117188);
		SendFactionMessage(6, COLOR_NATIONALGUARD,"[WSOSP:] Wjazd do wojska zakmniêty !");
		return 1;
	 }
	else
	{
		new tmpstring[256];
		format(tmpstring, sizeof(tmpstring), "Frakcja: %d, Typ: %d",gPlayerData[playerid][pFaction], DynamicFactions[gPlayerData[playerid][pFaction]][fType]);
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Niew³aœciwa frakcja/typ.");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, tmpstring);
		return 1;
	}
}

dcmd_zslums(playerid,params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pFaction] == 9)
	{
		SetDynamicObjectRot(gGateSfGov1a, 0.000000, 270.74499511719, 0.25);
		SendClientMessageToAll(COLOR_URZAD,"[URZ¥D SF:] Brama do slumsów zamkniêta");
		return 1;
	}
	else
	{
		new tmpstring[256];
		format(tmpstring, sizeof(tmpstring), "Frakcja: %d, Typ: %d",gPlayerData[playerid][pFaction], DynamicFactions[gPlayerData[playerid][pFaction]][fType]);
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Niew³aœciwa frakcja/typ.");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, tmpstring);
		return 1;
	}
}

dcmd_oslums(playerid,params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pFaction] == 9)
	{
		SetDynamicObjectRot(gGateSfGov1a, 0.000000, 0.000000, 0.000000);
		SendClientMessageToAll(COLOR_URZAD,"[URZ¥D SF:] Brama do slumsów otwarta");
		return 1;
	}
	else
	{
		new tmpstring[256];
		format(tmpstring, sizeof(tmpstring), "Frakcja: %d, Typ: %d",gPlayerData[playerid][pFaction], DynamicFactions[gPlayerData[playerid][pFaction]][fType]);
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Niew³aœciwa frakcja/typ.");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, tmpstring);
		return 1;
	}
}

dcmd_staxi(playerid,params[])
{
	#pragma unused params
	if(PlayerToPoint(7.0, playerid, -1739.2216796875, 985.66516113281, 17.714046478271) && PlayerToPoint(7.0, playerid, -1739.2216796875, 985.6650390625, 17.714046478271) && OpenGateTaxi[playerid] == 0)
		{
			if(gPlayerData[playerid][pFaction] != 4)
			{
				//SendClientMessage(playerid, 0x008000FF,"Nie jesteœ z policji !");
			}
			else
			{
				OpenGateTaxi[playerid] = 1;
				SetDynamicObjectRot (gGateSfTaxi1a, 0.000000, 0.000000, 100.51391601563);
				SetDynamicObjectRot (gGateSfTaxi2a, 0.000000, 0.000000, 239.47448730469);
				PlayerActionMessage(playerid,15.0,"u¿ywa pilota do otwarcia szlabanu.");

			}

		}
		else if(!PlayerToPoint(7.0, playerid, -2607.9067382813, 1399.2681884766, 8.0038661956787) && !PlayerToPoint(7.0, playerid, -2607.90625, 1399.267578125, 11.403814315796) && OpenGateTaxi[playerid] == 1)
		{
			OpenGateTaxi[playerid] = 0;
			SetDynamicObjectRot (gGateSfTaxi1a, 0.000000, 90, 100.51501464844);
			SetDynamicObjectRot (gGateSfTaxi2a, 0.000000, 90, 239.47900390625);
			PlayerActionMessage(playerid,15.0,"u¿ywa pilota do zamkniêcia szlabanu.");

		}
	return 1;
}

dcmd_zmost(playerid,params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pFaction] == 9)
	{
		SetDynamicObjectRot (gGateSfGov2a, 0.000000, 88.430023193359, 0.000000);
		SetDynamicObjectRot (gGateSfGov3a, 0.000000, 270.67504882813, 0.25);
		SetDynamicObjectRot (gGateSfGov4a, 0.000000, 270.87997436523, 0.000000);
		SetDynamicObjectRot (gGateSfGov5a, 0.000000, 270.67498779297, 0.000000);
		SendClientMessageToAll(COLOR_FACTIONCHAT,"(( [RADIO:] Urz¹d SF: Most pó³nocny zamkniêty ))");
		return 1;
	}
	else
	{
		new tmpstring[256];
		format(tmpstring, sizeof(tmpstring), "Frakcja: %d, Typ: %d",gPlayerData[playerid][pFaction], DynamicFactions[gPlayerData[playerid][pFaction]][fType]);
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Niew³aœciwa frakcja/typ.");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, tmpstring);
		return 1;
	}
}

dcmd_omost(playerid,params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pFaction] == 9)
	{
		SetDynamicObjectRot (gGateSfGov2a, 0.000000, 0.000000, 0.0);
		SetDynamicObjectRot (gGateSfGov3a, 0.000000, 0.000000, 0.0);
		SetDynamicObjectRot (gGateSfGov4a, 0.000000, 0.000000, 0.0);
		SetDynamicObjectRot (gGateSfGov5a, 0.000000, 0.000000, 0.0);
		SendFactionMessage(9, COLOR_FACTIONCHAT,"(( [RADIO:] Urz¹d SF: Most pó³nocny otwarty ))");
		return 1;
	}
	else
	{
		new tmpstring[256];
		format(tmpstring, sizeof(tmpstring), "Frakcja: %d, Typ: %d",gPlayerData[playerid][pFaction], DynamicFactions[gPlayerData[playerid][pFaction]][fType]);
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Niew³aœciwa frakcja/typ.");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, tmpstring);
		return 1;
	}
}

dcmd_ohq(playerid,params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	MoveDynamicObject(gGateSfParking1a,-1990.5186767578, 543.30401611328, 24.789016723633, 6.5);
	GateClose2();
	SendFactionMessage(0, COLOR_FACTIONCHAT,"(( [RADIO:] SFPD: Brama g³ówna otwarta ))");
	return 1;
}

dcmd_ohq2(playerid,params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	MoveDynamicObject(gGateSfParking1b,-2061.861328125, 434.58581542969, 13.348533630371, 6.5);
	GateClose3();
	SendFactionMessage(gPlayerData[playerid][pFaction], COLOR_LSPD,"[SFPD:] Cela otwarta");
	return 1;
}

dcmd_abizowner(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] < 4)
		return 0;
	new id;
	new businessowner[MAX_PLAYER_NAME];
	if(sscanf(params, "ds[MAX_PLAYER_NAME]", id, businessowner))
	{
		SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] /abizowner [businessid] [owner]");
		return 1;
	}
	strmid(Businesses[id][Owner], businessowner, 0, strlen(businessowner), 255);
	if(strcmp(businessowner, "None", false, 4) == 0)
	{
		Businesses[id][Owned] = 0;
	}
	else
	{
		Businesses[id][Owned] = 1;
	}
	SaveBizData(id, "Owned");
	SaveBizData(id, "Owner");
	return 1;
}

dcmd_ahouseowner(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] < 4)
		return 0;
	new id;
	new houseowner[MAX_PLAYER_NAME];
	if(sscanf(params, "ds[MAX_PLAYER_NAME]", id, houseowner))
	{
		SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] /ahouseowner [businessid] [owner]");
		return 1;
	}
	strmid(Houses[id][Owner], houseowner, 0, strlen(houseowner), 255);
	if(strcmp(houseowner, "None", false, 4) == 0)
	{
		Houses[id][Owned] = 0;
	}
	else
	{
		Houses[id][Owned] = 1;
	}
	SaveHouseData(id, "Owned");
	SaveHouseData(id, "Owner");
	return 1;
}

dcmd_aplayerbizid(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] < 4)
		return 0;
	new id;
	new businessid;
	if(sscanf(params, "dd", id, businessid))
	{
		SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] /aplayerbizid [playerid] [businessid]");
		return 1;
	}
	gPlayerData[id][pBizKey] = businessid;

	SavePlayerData(id, "BizKey");

	new string[128];
	format(string, sizeof(string), "UPDATE `samp_users_keys` SET `BizKey` = '%d' WHERE `PlayerName` = '%s'", gPlayerData[id][pBizKey], gPlayerData[id][pName]);
	wp_mysql_query(string, SAVE, id, db_con2);
	return 1;
}

dcmd_podatki1(playerid, params[])
{
	if(gPlayerData[playerid][pFaction] == 9 && gPlayerData[playerid][pRank] <= 2)
	{
		new id;
		new taxvalue;
		new string[128];
		if(sscanf(params, "dd", id, taxvalue))
		{
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] /podatki [id podatku] [wartosc]");
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"1 - [RadioTax], 2 - [TelTax], 3 - [TheRich]");
			return 1;
		}
		if(id == 1)
		{
			format(string, sizeof(string), "[GOVERNMENT:] Player: %s change radio tax from %d to %d", gPlayerData[playerid][pName], DynamicTaxes[RadioTax], taxvalue);
			GovermentLog(string);
			if(DynamicTaxes[RadioTax] < taxvalue)
			{
				format(string, sizeof(string),"[Urz¹d] Podniesiono podatek za radio do $%d", taxvalue);
				SendClientMessageToAll(COLOR_URZAD,string);
			}
			else if(DynamicTaxes[RadioTax] > taxvalue)
			{
				format(string, sizeof(string),"[Urz¹d] Obni¿ono podatek za radio do $%d", taxvalue);
				SendClientMessageToAll(COLOR_URZAD,string);
			}
			format(string, sizeof(string),"[INFO:] Ustawi³eœ now¹ wysokoœæ podatku od radia - $%d", taxvalue);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			DynamicTaxes[RadioTax] = taxvalue;
			SaveDynamicTaxes();

			return 1;
		}
		if(id == 2)
		{
			format(string, sizeof(string), "[GOVERNMENT:] Player: %s change phone tax from %d to %d", gPlayerData[playerid][pName], DynamicTaxes[RadioTax], taxvalue);
			GovermentLog(string);
			if(DynamicTaxes[TelTax] < taxvalue)
			{
				format(string, sizeof(string),"[Urz¹d] Podniesiono podatek za telefon do $%d", taxvalue);
				SendClientMessageToAll(COLOR_URZAD,string);
			}
			else if(DynamicTaxes[TelTax] > taxvalue)
			{
				format(string, sizeof(string),"[Urz¹d] Obni¿ono podatek za telefon do $%d", taxvalue);
				SendClientMessageToAll(COLOR_URZAD,string);
			}
			format(string, sizeof(string),"[INFO:] Ustawi³eœ now¹ wysokoœæ podatku od telefonu - $%d", taxvalue);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			DynamicTaxes[TelTax] = taxvalue;
			SaveDynamicTaxes();
			return 1;
		}
		if(id == 3)
		{
			format(string, sizeof(string),"[Urz¹d] Ustawiono najni¿sz¹ iloœæ posiadanych pieniêdzy dla przynale¿noœci grupy najbogatszych - $%d", taxvalue);
			SendClientMessageToAll(COLOR_URZAD,string);
			format(string, sizeof(string),"[INFO:] Ustawi³eœ doln¹ granice pieniêdzy do bycia najbogatszym - $%d", taxvalue);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			DynamicTaxes[TheRich] = taxvalue;
			SaveDynamicTaxes();
			return 1;
		}

	}
	return 1;
}

dcmd_podatki2(playerid, params[])
{
	if(gPlayerData[playerid][pFaction] == 9 && gPlayerData[playerid][pRank] <= 2)
	{
		new id;
		new Float:taxvalue;
		new string[128];
		if(sscanf(params, "df", id, taxvalue))
		{
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] /podatki [id podatku] [wartosc]");
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"1 - [CarTax], 2 - [HeliTax], 3 - [PlaneTax], 4 - [BoatTax], 5 - [HouseTax]");
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"6 - [BusinessTax], 7 - [RichTax], 8 - [EkoTax], 9 - [VatTaxMax], 10 - [VatTaxMin]");
			return 1;
		}
		if(id == 1)
		{
			format(string, sizeof(string), "[GOVERNMENT:] Player: %s change car tax from %d to %d", gPlayerData[playerid][pName], DynamicTaxes[CarTax], floatround(taxvalue*100, floatround_round));
			GovermentLog(string);
			if(DynamicTaxes[CarTax] < taxvalue)
			{
				format(string, sizeof(string),"[Urz¹d] Podniesiono podatek za samochód do %d procent", floatround(taxvalue*100,floatround_round));
				SendClientMessageToAll(COLOR_URZAD,string);
			}
			else if(DynamicTaxes[CarTax] > taxvalue)
			{
				format(string, sizeof(string),"[Urz¹d] Obni¿ono podatek za samochód do %d procent", floatround(taxvalue*100,floatround_round));
				SendClientMessageToAll(COLOR_URZAD,string);
			}
			format(string, sizeof(string),"[INFO:] Ustawi³eœ now¹ wysokoœæ podatku od samochodu - %d procent", floatround(taxvalue*100,floatround_round));
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			DynamicTaxes[CarTax] = taxvalue;
			SaveDynamicTaxes();
			return 1;
		}
		if(id == 2)
		{
			format(string, sizeof(string), "[GOVERNMENT:] Player: %s change heli tax from %d to %d", gPlayerData[playerid][pName], DynamicTaxes[RadioTax], floatround(taxvalue*100, floatround_round));
			GovermentLog(string);
			if(DynamicTaxes[HeliTax] < taxvalue)
			{
				format(string, sizeof(string),"[Urz¹d] Podniesiono podatek za helikopter do %d procent", floatround(taxvalue*100,floatround_round));
				SendClientMessageToAll(COLOR_URZAD,string);
			}
			else if(DynamicTaxes[HeliTax] > taxvalue)
			{
				format(string, sizeof(string),"[Urz¹d] Obni¿ono podatek za helikopter do %d procent", floatround(taxvalue*100,floatround_round));
				SendClientMessageToAll(COLOR_URZAD,string);
			}
			format(string, sizeof(string),"[INFO:] Ustawi³eœ now¹ wysokoœæ podatku od helikoptera - %d procent", floatround(taxvalue*100,floatround_round));
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			DynamicTaxes[HeliTax] = taxvalue;
			SaveDynamicTaxes();
			return 1;
		}
		if(id == 3)
		{
			format(string, sizeof(string), "[GOVERNMENT:] Player: %s change plane tax from %d to %d", gPlayerData[playerid][pName], DynamicTaxes[RadioTax], floatround(taxvalue*100, floatround_round));
			GovermentLog(string);
			if(DynamicTaxes[PlaneTax] < taxvalue)
			{
				format(string, sizeof(string),"[Urz¹d] Podniesiono podatek za samolot do %d procent",floatround(taxvalue*100,floatround_round));
				SendClientMessageToAll(COLOR_URZAD,string);
			}
			else if(DynamicTaxes[PlaneTax] > taxvalue)
			{
				format(string, sizeof(string),"[Urz¹d] Obni¿ono podatek za samolot do %d procent", floatround(taxvalue*100,floatround_round));
				SendClientMessageToAll(COLOR_URZAD,string);
			}
			format(string, sizeof(string),"[INFO:] Ustawi³eœ now¹ wysokoœæ podatku od samolotu - %d procent", floatround(taxvalue*100,floatround_round));
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			DynamicTaxes[PlaneTax] = taxvalue;
			SaveDynamicTaxes();
			return 1;
		}
		if(id == 4)
		{
			format(string, sizeof(string), "[GOVERNMENT:] Player: %s change boat tax from %d to %d", gPlayerData[playerid][pName], DynamicTaxes[RadioTax], floatround(taxvalue*100, floatround_round));
			GovermentLog(string);
			if(DynamicTaxes[BoatTax] < taxvalue)
			{
				format(string, sizeof(string),"[Urz¹d] Podniesiono podatek za ³ódŸ do %d procent", floatround(taxvalue*100,floatround_round));
				SendClientMessageToAll(COLOR_URZAD,string);
			}
			else if(DynamicTaxes[BoatTax] > taxvalue)
			{
				format(string, sizeof(string),"[Urz¹d] Obni¿ono podatek za ³ódŸ do %d procent", floatround(taxvalue*100,floatround_round));
				SendClientMessageToAll(COLOR_URZAD,string);
			}
			format(string, sizeof(string),"[INFO:] Ustawi³eœ now¹ wysokoœæ podatku od ³odzi - %d procent", floatround(taxvalue*100,floatround_round));
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			DynamicTaxes[BoatTax] = taxvalue;
			SaveDynamicTaxes();
			return 1;
		}
		if(id == 5)
		{
			format(string, sizeof(string), "[GOVERNMENT:] Player: %s change house tax from %d to %d", gPlayerData[playerid][pName], DynamicTaxes[RadioTax], floatround(taxvalue*100, floatround_round));
			GovermentLog(string);
			if(DynamicTaxes[HouseTax] < taxvalue)
			{
				format(string, sizeof(string),"[Urz¹d] Podniesiono podatek za dom do %d procent", floatround(taxvalue*100,floatround_round));
				SendClientMessageToAll(COLOR_URZAD,string);
			}
			else if(DynamicTaxes[HouseTax] > taxvalue)
			{
				format(string, sizeof(string),"[Urz¹d] Obni¿ono podatek za dom do %d procent", floatround(taxvalue*100,floatround_round));
				SendClientMessageToAll(COLOR_URZAD,string);
			}
			format(string, sizeof(string),"[INFO:] Ustawi³eœ now¹ wysokoœæ podatku od domu - %d procent", floatround(taxvalue*100,floatround_round));
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			DynamicTaxes[HouseTax] = taxvalue;
			SaveDynamicTaxes();
			return 1;
		}
		if(id == 6)
		{
			format(string, sizeof(string), "[GOVERNMENT:] Player: %s change business tax from %d to %d", gPlayerData[playerid][pName], DynamicTaxes[RadioTax], floatround(taxvalue*100, floatround_round));
			GovermentLog(string);
			if(DynamicTaxes[BusinessTax] < taxvalue)
			{
				format(string, sizeof(string),"[Urz¹d] Podniesiono podatek za biznes do %d procent", floatround(taxvalue*100,floatround_round));
				SendClientMessageToAll(COLOR_URZAD,string);
			}
			else if(DynamicTaxes[BusinessTax] > taxvalue)
			{
				format(string, sizeof(string),"[Urz¹d] Obni¿ono podatek za biznes do %d procent", floatround(taxvalue*100,floatround_round));
				SendClientMessageToAll(COLOR_URZAD,string);
			}
			format(string, sizeof(string),"[INFO:] Ustawi³eœ now¹ wysokoœæ podatku od biznesu - %d procent", floatround(taxvalue*100,floatround_round));
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			DynamicTaxes[BusinessTax] = taxvalue;
			SaveDynamicTaxes();
			return 1;
		}
		if(id == 7)
		{
			format(string, sizeof(string), "[GOVERNMENT:] Player: %s change reachest tax from %d to %d", gPlayerData[playerid][pName], DynamicTaxes[RadioTax], floatround(taxvalue*100, floatround_round));
			GovermentLog(string);
			if(DynamicTaxes[RichTax] < taxvalue)
			{
				format(string, sizeof(string),"[Urz¹d] Podniesiono podatek od najbogatszych do %d procent", floatround(taxvalue*100,floatround_round));
				SendClientMessageToAll(COLOR_URZAD,string);
			}
			else if(DynamicTaxes[RichTax] > taxvalue)
			{
				format(string, sizeof(string),"[Urz¹d] Obni¿ono podatek od najbogatszych do %d procent", floatround(taxvalue*100,floatround_round));
				SendClientMessageToAll(COLOR_URZAD,string);
			}
			format(string, sizeof(string),"[INFO:] Ustawi³eœ now¹ wysokoœæ podatku od najbogatszych - %d procent", floatround(taxvalue*100,floatround_round));
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			DynamicTaxes[RichTax] = taxvalue;
			SaveDynamicTaxes();
			return 1;
		}
		if(id == 8)
		{
			format(string, sizeof(string), "[GOVERNMENT:] Player: %s change eco tax from %d to %d", gPlayerData[playerid][pName], DynamicTaxes[RadioTax], floatround(taxvalue*100, floatround_round));
			GovermentLog(string);
			if(DynamicTaxes[EkoTax] < taxvalue)
			{
				format(string, sizeof(string),"[Urz¹d] Podniesiono podatek ekologiczny do %d procent", floatround(taxvalue*100,floatround_round));
				SendClientMessageToAll(COLOR_URZAD,string);
			}
			else if(DynamicTaxes[EkoTax] > taxvalue)
			{
				format(string, sizeof(string),"[Urz¹d] Obni¿ono podatek ekologicznego do %d procent", floatround(taxvalue*100,floatround_round));
				SendClientMessageToAll(COLOR_URZAD,string);
			}
			format(string, sizeof(string),"[INFO:] Ustawi³eœ now¹ wysokoœæ podatku ekologicznego - %d procent", floatround(taxvalue*100,floatround_round));
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			DynamicTaxes[EkoTax] = taxvalue;
			SaveDynamicTaxes();
			return 1;
		}
		if(id == 9)
		{
			format(string, sizeof(string), "[GOVERNMENT:] Player: %s change VATmax tax from %d to %d", gPlayerData[playerid][pName], DynamicTaxes[RadioTax], floatround(taxvalue*100, floatround_round));
			GovermentLog(string);
			if(DynamicTaxes[VatTaxMax] < taxvalue)
			{
				format(string, sizeof(string),"[Urz¹d] Podniesiono podatek VAT do %d procent", floatround(taxvalue*100,floatround_round));
				SendClientMessageToAll(COLOR_URZAD,string);
			}
			else if(DynamicTaxes[VatTaxMax] > taxvalue)
			{
				format(string, sizeof(string),"[Urz¹d] Obni¿ono podatek VAT do %d procent", floatround(taxvalue*100,floatround_round));
				SendClientMessageToAll(COLOR_URZAD,string);
			}
			format(string, sizeof(string),"[INFO:] Ustawi³eœ now¹ wysokoœæ podatku VAT - %d procent", floatround(taxvalue*100,floatround_round));
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			DynamicTaxes[VatTaxMax] = taxvalue;
			SaveDynamicTaxes();
			return 1;
		}
		if(id == 10)
		{
			format(string, sizeof(string), "[GOVERNMENT:] Player: %s change VATmin tax from %d to %d", gPlayerData[playerid][pName], DynamicTaxes[RadioTax], floatround(taxvalue*100, floatround_round));
			GovermentLog(string);
			if(DynamicTaxes[VatTaxMin] < taxvalue)
			{
				format(string, sizeof(string),"[Urz¹d] Podniesiono podatek VAT do %d procent", floatround(taxvalue*100,floatround_round));
				SendClientMessageToAll(COLOR_URZAD,string);
			}
			else if(DynamicTaxes[VatTaxMin] > taxvalue)
			{
				format(string, sizeof(string),"[Urz¹d] Obni¿ono podatek VAT do %d procent", floatround(taxvalue*100,floatround_round));
				SendClientMessageToAll(COLOR_URZAD,string);
			}
			format(string, sizeof(string),"[INFO:] Ustawi³eœ now¹ wysokoœæ podatku VAT - %d procent", floatround(taxvalue*100,floatround_round));
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			DynamicTaxes[VatTaxMin] = taxvalue;
			SaveDynamicTaxes();
			return 1;
		}
		SaveDynamicTaxes();
	}
	return 1;
}

dcmd_okradnijbiznes(playerid, params[])
{
	#pragma unused params
	new string[128], pCount;
	
	if(gPlayerData[playerid][pFaction] == 255)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie nale¿ysz do gangu");
		return 1;
	}
	if(DynamicFactions[gPlayerData[playerid][pFaction]][fType] != FACTIONT_GANG)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie nale¿ysz do gangu");
		return 1;
	}
	
	if(gPlayerVars[playerid][mAtBizID] == -1)
	{		
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Nie znajdujesz siê w ¿adnym biznesie", "Zamknij", "");
		return 1;
	}
	
	if(BizInZoneStealTimeLeft(playerid) > 0)
	{
		format(string, sizeof(string), "[INFO:] Musisz odczekaæ jeszcze %d godzin zanim bêdziesz móg³ okraœæ ten biznes", BizInZoneStealTimeLeft(playerid));
		SendClientMessage(playerid, COLOR_ORANGE, string);
		return 1;
	}
	else if(BizInZoneStealTimeLeft(playerid) == -1)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Biznes nie znajduje siê na ¿adnym terytorium - nie mo¿esz go okraœæ");
		return 1;
	}
	
	if(!BizInAlliedZone(playerid))
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Biznes nie znajduje siê na terytorium twojego gangu i nie mo¿esz go okraœæ");
		return 1;
	}
	
	new i = gPlayerVars[playerid][mAtBizID];
	
	if(Businesses[i][BConfiscated] || !Businesses[i][Owned])
	{
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Nie mo¿esz okraœæ tego biznesu.", "Zamknij", "");
		return 1;
	}
	
	if(Businesses[i][mAlarm])
	{
		foreach(Player, j)
		{
			if(gPlayerData[j][pFaction] != 255)
			{
				if(DynamicFactions[gPlayerData[j][pFaction]][fType] == FACTIONT_POLICE)
				{
					pCount++;
				}
			}
		}
		
		if(!pCount)
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Aby okraœæ ten biznes, na serwerze musi byæ przynajmniej jedna osoba z policji");
			return 1;
		}
		SendPoliceCbMessage(playerid, POLICE_MSGT_BIZ_BREAK);
	}
	
	if((gHour >= 17 && gHour <= 23) || (gHour >= 0 && gHour <= 4) || Businesses[i][mAlarm])
	{
		gPlayerVars[playerid][mRobbingBusinessStage] = 1;
	
		format(string, sizeof(string), "okrada biznes", GetPlayerNameEx(playerid));
		PlayerActionMessage(playerid, AR_BUSINESS_STEALING, string);
		
		return 1;
	}
	else
	{
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Jest zbyt wczeœnie ¿eby kraœæ ! Wróæ miêdzy godzin¹ 17 a 4.", "Zamknij", "");
		return 1;
	}
}

dcmd_okradnijdom(playerid, params[])
{
	#pragma unused params
	new string[128], pCount;
	
	if(gPlayerData[playerid][pFaction] == 255)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie nale¿ysz do gangu");
		return 1;
	}
	if(DynamicFactions[gPlayerData[playerid][pFaction]][fType] != FACTIONT_GANG)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie nale¿ysz do gangu");
		return 1;
	}
	
	if(gPlayerVars[playerid][mAtHouseID] == -1)
	{		
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Nie znajdujesz siê w ¿adnym domu.", "Zamknij", "");
		return 1;
	}
	
	if(HouseInZoneStealTimeLeft(playerid) > 0)
	{
		format(string, sizeof(string), "[INFO:] Musisz odczekaæ jeszcze %d godzin zanim bêdziesz móg³ okraœæ ten domu", HouseInZoneStealTimeLeft(playerid));
		SendClientMessage(playerid, COLOR_ORANGE, string);
		return 1;
	}
	else if(HouseInZoneStealTimeLeft(playerid) == -1)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Dom nie znajduje siê na ¿adnym terytorium - nie mo¿esz go okraœæ");
		return 1;
	}
	
	if(!HouseInAlliedZone(playerid))
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Dom nie znajduje siê na terytorium twojego gangu i nie mo¿esz go okraœæ");
		return 1;
	}
	
	new i = gPlayerVars[playerid][mAtHouseID];
	
	if(Houses[i][HConfiscated] || !Houses[i][Owned])
	{
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Nie mo¿esz okraœæ tego domu.", "Zamknij", "");
		return 1;
	}
	
	printf("[WARNING:] /okradnijdom used by %s, time: %d:%d, hId: %d, carserial %d, owner: %s", gPlayerData[playerid][pName], gHour, gMin, i, Houses[i][Owner]);
	
	if(Houses[i][HAlarm])
	{
		foreach(Player, j)
		{
			if(gPlayerData[j][pFaction] != 255)
			{
				if(DynamicFactions[gPlayerData[j][pFaction]][fType] == FACTIONT_POLICE)
				{
					pCount++;
				}
			}
		}
		if(!pCount)
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Aby okraœæ ten dom, na serwerze musi byæ przynajmniej jedna osoba z policji");
			return 1;
		}
		SendPoliceCbMessage(playerid, POLICE_MSGT_HOUSE_BREAK);
	}
	
	if((gHour >= 17 && gHour <= 23) || (gHour >= 0 && gHour <= 4) || Houses[i][HAlarm])
	{
		gPlayerVars[playerid][mRobbingHouseStage] = 1;
	
		format(string, sizeof(string), "okrada dom", GetPlayerNameEx(playerid));
		PlayerActionMessage(playerid, AR_HOUSE_STEALING, string);
		
		return 1;
	}
	else
	{
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Jest zbyt wczeœnie ¿eby kraœæ ! Wróæ miêdzy godzin¹ 17 a 4.", "Zamknij", "");
		return 1;
	}
}
	
dcmd_wlamsiedobiznesu(playerid, params[])
{
	#pragma unused params
	new string[128], pCount;
	
	if(gPlayerVars[playerid][mIsPlayerBizJacking])
	{
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Jesteœ ju¿ w trakcie w³amywania siê do domu !", "Zamknij", "");
		return 1;
	}

	if(gPlayerData[playerid][pFaction] == 255)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie nale¿ysz do gangu");
		return 1;
	}
	if(DynamicFactions[gPlayerData[playerid][pFaction]][fType] != FACTIONT_GANG)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie nale¿ysz do gangu");
		return 1;
	}
	
	new slot = PHaveItem(playerid, 3, 21);
	if(!slot)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz wytychu");
		return 1;
	}
	
	if(!IsPlayerInAlliedGangZone(playerid))
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie znajdujesz siê na swoim terytorium i nie mo¿esz tutaj kraœæ !");
		return 1;
	}
	
	for(new i = 0; i < sizeof(Businesses); i++)
	{
		if(!PlayerToPoint(1.0, playerid, Businesses[i][EnterX], Businesses[i][EnterY], Businesses[i][EnterZ]))
			continue;
		if(GetPlayerVirtualWorld(playerid) != Businesses[i][EnterWorld])
			continue;
			
		if(BizInZoneBreakTimeLeft(i) > 0)
		{
			format(string, sizeof(string), "[INFO:] Musisz odczekaæ jeszcze %d godzin zanim bêdziesz móg³ w³amaæ siê do tego biznesu", BizInZoneBreakTimeLeft(i));
			SendClientMessage(playerid, COLOR_ORANGE, string);
			return 1;
		}
		else if(BizInZoneBreakTimeLeft(i) == -1)
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Biznes nie znajduje siê na ¿adnym terytorium - nie mo¿esz siê do niego w³amaæ");
			return 1;
		}
		if(!Businesses[i][Locked])
		{
			ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Ten biznes nie jest zamkniêty.", "Zamknij", "");
			return 1;
		}
		if(Businesses[i][BConfiscated] || !Businesses[i][Owned])
		{
			ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Nie mo¿esz siê w³amaæ do tego biznesu.", "Zamknij", "");
			return 1;
		}
		
		printf("[WARNING:] /wlamsiedobiznesu used by %s, time: %d:%d, bizid: %d, carserial %d, owner: %s", gPlayerData[playerid][pName], gHour, gMin, i, Businesses[i][Owner]);
		format(string, sizeof(string), "próbuje w³amaæ siê do biznesu", GetPlayerNameEx(playerid));
		PlayerActionMessage(playerid,15.0,string);
		
		if(Businesses[i][mAlarm])
		{
			foreach(Player, j)
			{
				if(gPlayerData[j][pFaction] == 255)
				{
					continue;
				}
				if(DynamicFactions[gPlayerData[j][pFaction]][fType] == FACTIONT_POLICE)
					pCount++;
			}
			if(!pCount)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Aby w³amaæ siê do tego biznesu, na serwerze musi byæ przynajmniej jedna osoba z policji");
				return 1;
			}
			SendPoliceCbMessage(playerid, POLICE_MSGT_BIZ_BREAK);
		}
		
		if((gHour >= 17 && gHour <= 23) || (gHour >= 0 && gHour <= 4) || Businesses[i][mAlarm])
		{
			GameTextForPlayer(playerid, "Proba otwarcia zamka...", 15000, 6);
			gPlayerVars[playerid][mIsPlayerBizJacking] = 1;
			defer BizCrack(playerid, i);
			SetPSlotParam1(playerid, slot, SlotParam1(playerid, slot)-1);
			if(SlotParam1(playerid, slot) <= 0)
				RemovePlayerItemExUsed(playerid, slot);
			return 1;
		}
		else
		{
			ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Jest zbyt wczeœnie ¿eby kraœæ ! Wróæ miêdzy godzin¹ 17 a 4.", "Zamknij", "");
			return 1;
		}
	}
	ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Nie znajdujesz siê przy wejœciu do ¿adnego biznesu.", "Zamknij", "");
	return 1;
}
	
dcmd_wlamsiedodomu(playerid, params[])
{
	#pragma unused params
	new string[128], pCount;
	
	if(gPlayerVars[playerid][mIsPlayerHouseJacking])
	{
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Jesteœ ju¿ w trakcie w³amywania siê do biznesu !", "Zamknij", "");
		return 1;
	}
	
	if(gPlayerData[playerid][pFaction] == 255)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie nale¿ysz do gangu");
		return 1;
	}
	
	if(DynamicFactions[gPlayerData[playerid][pFaction]][fType] != FACTIONT_GANG)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie nale¿ysz do gangu");
		return 1;
	}
	
	if(!IsPlayerInAlliedGangZone(playerid))
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie znajdujesz siê na swoim terytorium i nie mo¿esz tutaj kraœæ !");
		return 1;
	}
	
	new slot = PHaveItem(playerid, 3, 21);
	if(!slot)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz wytychu");
		return 1;
	}
	
	for(new i = 0; i < sizeof(Houses); i++)
	{
		if(!PlayerToPoint(1.0, playerid,Houses[i][EnterX], Houses[i][EnterY], Houses[i][EnterZ]))
			continue;
		if(GetPlayerVirtualWorld(playerid) != Houses[i][EnterWorld])
			continue;
		if(!Houses[i][Owned])
		{
			ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Nie mo¿esz w³amaæ siê do tego domu", "Zamknij", "");
			return 1;
		}
		if(HouseInZoneBreakTimeLeft(i) > 0)
		{
			format(string, sizeof(string), "[INFO:] Musisz odczekaæ jeszcze %d godzin zanim bêdziesz móg³ w³amaæ siê do tego domu", HouseInZoneBreakTimeLeft(playerid));
			SendClientMessage(playerid, COLOR_ORANGE, string);
			return 1;
		}
		else if(HouseInZoneBreakTimeLeft(i) == -1)
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Dom nie znajduje siê na ¿adnym terytorium - nie mo¿esz siê do niego w³amaæ");
			return 1;
		}
		if(!Houses[i][Locked])
		{
			ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Ten dom nie jest zamkniêty.", "Zamknij", "");
			return 1;
		}
		if(Houses[i][HConfiscated])
		{
			ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Nie mo¿esz siê w³amaæ do tego domu.", "Zamknij", "");
			return 1;
		}
		
		printf("[WARNING:] /wlamsiedodomu used by %s, time: %d:%d, houseid: %d, carserial %d, owner: %s", gPlayerData[playerid][pName], gHour, gMin, i, Houses[i][Owner]);
		format(string, sizeof(string), "próbuje w³amaæ siê do domu", GetPlayerNameEx(playerid));
		PlayerActionMessage(playerid,15.0,string);
		
		if(Houses[i][HAlarm])
		{
			foreach(Player, j)
			{
				if(gPlayerData[j][pFaction] == 255)
				{
					continue;
				}
				if(DynamicFactions[gPlayerData[j][pFaction]][fType] == FACTIONT_POLICE)
					pCount++;
			}
			if(!pCount)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Aby w³amaæ siê do tego domu, na serwerze musi byæ przynajmniej jedna osoba z policji");
				return 1;
			}
			SendPoliceCbMessage(playerid, POLICE_MSGT_HOUSE_BREAK);
		}
		
		if((gHour >= 17 && gHour <= 23) || (gHour >= 0 && gHour <= 4) || Houses[i][HAlarm])
		{
			gPlayerVars[playerid][mIsPlayerHouseJacking] = 1;
			defer HouseCrack(playerid, i);
			SetPSlotParam1(playerid, slot, SlotParam1(playerid, slot)-1);
			if(SlotParam1(playerid, slot) <= 0)
				RemovePlayerItemExUsed(playerid, slot);
			return 1;
		}
		else
		{
			ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Jest zbyt wczeœnie ¿eby kraœæ ! Wróæ miêdzy godzin¹ 17 a 4.", "Zamknij", "");
			return 1;
		}
	}
	ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Nie znajdujesz siê przy wejœciu do ¿adnego domu.", "Zamknij", "");
	return 1;
}

dcmd_wlamsiedopojazdu(playerid, params[])
{
	#pragma unused params
	new string[128];
	
	if(gPlayerData[playerid][pFaction] == 255)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie nale¿ysz do gangu");
		return 1;
	}
	
	if(DynamicFactions[gPlayerData[playerid][pFaction]][fType] != FACTIONT_GANG)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie nale¿ysz do gangu");
		return 1;
	}
	
	if(!IsPlayerInAlliedGangZone(playerid))
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie znajdujesz siê na swoim terytorium i nie mo¿esz tutaj kraœæ !");
		return 1;
	}
	
	new slot = PHaveItem(playerid, 3, 20);
	if(!slot)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz ³omu");
		return 1;
	}
	
	new pCount, Float:lVehRange = 4.0;
	new vehid = GetClosestVehicle(playerid, lVehRange);
	
	if(vehid == INVALID_VEHICLE_ID)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Jesteœ zbyt daleko od pojazdu");
		return 1;
	}
	
	if(!gVehData[vehid-1][Closed])
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Pojazd jest ju¿ otwarty");
		return 1;
	}
	
	if(gVehData[vehid-1][mVehType] != 0 && gVehData[vehid-1][mVehType] != 9)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz w³amaæ siê do tego pojazdu");
		return 1;
	}
	
	if(VehInZoneBreakTimeLeft(vehid) > 0)
	{
		format(string, sizeof(string), "[INFO:] Musisz odczekaæ jeszcze %d godzin zanim bêdziesz móg³ w³amaæ siê do tego pojazdu", VehInZoneBreakTimeLeft(vehid));
		SendClientMessage(playerid, COLOR_ORANGE, string);
		return 1;
	}
	else if(VehInZoneBreakTimeLeft(vehid) == -1)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Pojazd nie znajduje siê na ¿adnym terytorium - nie mo¿esz siê do niego w³amaæ");
		return 1;
	}
	
	if(IsCarJackerOpening[playerid])
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Jesteœ ju¿ w trakcie otwierania pojazdu !");
		return 1;
	}
	
	printf("[WARNING:] /wlamsiedopojazdu used by %s, time: %d:%d, vehicleid: %d, carserial %d, owner: %s", gPlayerData[playerid][pName], gHour, gMin, vehid+1, gVehData[vehid][Owner]);
	format(string, sizeof(string), "próbuje w³amaæ siê do pojazdu", GetPlayerNameEx(playerid));
	PlayerActionMessage(playerid,15.0,string);
	if(gVehData[vehid-1][Alarm])
	{
		new enginedyn, lights, alarm, doors, bonnet, boot, objective;
		GetVehicleParamsEx(vehid, enginedyn, lights, alarm, doors, bonnet, boot, objective);
		SetVehicleParamsEx(vehid, enginedyn,1,1, doors, bonnet, boot, objective);
		defer CarAlarmOff[25000](vehid);
		foreach(Player, i)
		{
			if(gPlayerData[i][pFaction] == 255)
			{
				continue;
			}
			if(DynamicFactions[gPlayerData[i][pFaction]][fType] == FACTIONT_POLICE)
				pCount++;
		}		
		if(!pCount)
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Aby ukraœæ ten pojazd na serwerze musi byæ przynajmniej jedna osoba z policji");
			return 1;
		}
		SendPoliceCbMessage(playerid, POLICE_MSGT_VEHICLE_BREAK);
	}
	if((gHour >= 17 && gHour <= 23) || (gHour >= 0 && gHour <= 4) || gVehData[vehid-1][Alarm])
	{
		IsCarJackerOpening[playerid] = 1;
		if(gPlayerData[playerid][pCarJackerJobLvl] <= 5)
		{
			defer VehicleCrack2[20000](playerid, vehid-1);
			SetPSlotParam1(playerid, slot, SlotParam1(playerid, slot)-1);
			if(!SlotParam1(playerid, slot))
				RemovePlayerItemExUsed(playerid, slot);
			return 1;
		}
		else if(gPlayerData[playerid][pCarJackerJobLvl] <= 8 && gPlayerData[playerid][pCarJackerJobLvl] >= 5)
		{
			defer VehicleCrack2[17000](playerid, vehid-1);
			SetPSlotParam1(playerid, slot, SlotParam1(playerid, slot)-1);
			if(!SlotParam1(playerid, slot))
				RemovePlayerItemExUsed(playerid, slot);
			return 1;
		}
		else if(gPlayerData[playerid][pCarJackerJobLvl] <= 15 && gPlayerData[playerid][pCarJackerJobLvl] >= 8)
		{
			defer VehicleCrack2[15000](playerid, vehid-1);
			SetPSlotParam1(playerid, slot, SlotParam1(playerid, slot)-1);
			if(!SlotParam1(playerid, slot))
				RemovePlayerItemExUsed(playerid, slot);
			return 1;
		}
		else if(gPlayerData[playerid][pCarJackerJobLvl] <= 20)
		{
			defer VehicleCrack2[13000](playerid, vehid-1);
			SetPSlotParam1(playerid, slot, SlotParam1(playerid, slot)-1);
			if(!SlotParam1(playerid, slot))
				RemovePlayerItemExUsed(playerid, slot);
		}
		return 1;
	}
	else
	{
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Jest zbyt wczeœnie ¿eby kraœæ ! Wróæ miêdzy godzin¹ 17 a 4.", "Zamknij", "");
		return 1;
	}
}

dcmd_acarmodelprice(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new vehiclemodel;
	new vehicleprice;
	if(sscanf(params, "dd", vehiclemodel, vehicleprice))
	{
		SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] /acarmodelprice [modelid] [price]");
		return 1;
	}
	for(new i = 0; i < sizeof(gVehData); i++)
	{
		if(gVehData[i][mVehModel] == vehiclemodel)
		{
			gVehData[i][Price] = vehicleprice;

			SaveVehData(i, "Price");
		}
	}
	new string[128];
	format(string, sizeof(string), "[INFO:] Price for vehicle model %d is set by %s to $%d", vehiclemodel, GetPlayerNameEx(playerid), vehicleprice);
	SendAdminMessage(COLOR_YELLOW,string);
	return 1;
}

dcmd_abizreset(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	for(new i = 0; i < sizeof(Businesses); i++)
	{
		Businesses[i][Owned] = 0;
		Businesses[i][Locked] = 0;
		Businesses[i][Till] = 0;
		Businesses[i][Products] = 100;
		Businesses[i][EntranceCost] = 10;
		strdel(Businesses[i][Owner], 0, 128);
		strins(Businesses[i][Owner], "None", 0, 128);

		SaveBizData(i, "Owned");
		SaveBizData(i, "Locked");
		SaveBizData(i, "Till");
		SaveBizData(i, "Products");
		SaveBizData(i, "EntranceCost");
		SaveBizData(i, "Owner");
	}
	SendAdminMessage(COLOR_YELLOW, "[INFO:] Biznesy zosta³y zresetowane");
	return 1;
}

dcmd_ahousesreset(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	for(new i = 0; i < sizeof(Houses); i++)
	{
		Houses[i][Owned] = 0;
		Houses[i][Rentable] = 0;
		Houses[i][Money] = 0;
		Houses[i][Locked] = 0;
		strdel(Houses[i][Owner], 0, 128);
		strins(Houses[i][Owner], "None", 0, 128);

		SaveHouseData(i, "Owned");
		SaveHouseData(i, "Rentable");
		SaveHouseData(i, "Money");
		SaveHouseData(i, "Locked");
		SaveHouseData(i, "Owner");
	}
	SendAdminMessage(COLOR_YELLOW, "[INFO:] Domy zosta³y zresetowane");
	return 1;
}

dcmd_acarsreset(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	for(new i = 0; i < sizeof(gVehData); i++)
	{
		gVehData[i][mVehOwned] = 0;
		strmid(gVehData[i][Owner], "None", 0, 4, 128);
		gVehData[i][mVehX] = 0.0;
		gVehData[i][mVehY] = 0.0;
		gVehData[i][mVehZ] = 0.0;
		gVehData[i][mVehA] = 0.0;
		gVehData[i][mVehColor1] = -1;
		gVehData[i][mVehColor2] = -1;
		gVehData[i][Closed] = 0;
		gVehData[i][CarFuel] = float(VehFTank(i+1));
		gVehData[i][CarHealth] = 1000.0;
		gVehData[i][BusinessID] = 255;
		gVehData[i][CarRepairTimeLeft] = 0;
		gVehData[i][CarDamaged] = 0;
		gVehData[i][CarResetT] = 0;
		gVehData[i][Price] = 0;
		gVehData[i][mVehType] = 0;
		gVehData[i][mVehFaction] = 255;

		DestroyVehicle(i+1);
	}

	SendAdminMessage(COLOR_YELLOW, "[INFO:] Pojazdy zosta³y zresetowane");
	return 1;
}

dcmd_acarparkdynamic(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] < 2)
		return 0;
	if(IsPlayerInAnyVehicle(playerid))
	{
		new idcar = GetPlayerVehicleID(playerid);
		new tmpcar = GetPlayerVehicleID(playerid) - 1;
		new Float:x,Float:y,Float:z;
		new Float:a;
		GetVehiclePos(idcar, x, y, z);
		GetVehicleZAngle(idcar, a);
		gVehData[tmpcar][mVehX] = x;
		gVehData[tmpcar][mVehY] = y;
		gVehData[tmpcar][mVehZ] = z;
		gVehData[tmpcar][mVehA] = a;
		DestroyVehicle(idcar);
		CreateVehicle(gVehData[tmpcar][mVehModel],gVehData[tmpcar][mVehX],gVehData[tmpcar][mVehY],gVehData[tmpcar][mVehZ],gVehData[tmpcar][mVehA],gVehData[tmpcar][mVehColor1],gVehData[tmpcar][mVehColor2], -1);
		SetVehLicensePlate(idcar);
		SetVehicleToRespawnEx(idcar);
		PutPlayerIntoVehicle(playerid,idcar,0);
		SaveVehData(tmpcar, "VehPos");
		new wstring[128];
		format(wstring, sizeof(wstring), "[ADMIN:] %s has parked vehicle ID %d", GetPlayerNameEx(playerid),idcar);
		SendAdminMessage(COLOR_YELLOW, wstring);
	}
	else
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "Your not in a vehicle!");
	}
	return 1;
}

dcmd_arepairallvehicles(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] != HADM)
		return 0;
	for(new i = 0; i < sizeof(gVehData); i++)
	{
		gVehData[i][CarDamaged] = 0;
	}
	new string[128];
	format(string, sizeof(string), "[ADMIN:] Wszystkie pojazdy naprawione przez %s", GetPlayerNameEx(playerid));
	SendAdminMessage(COLOR_YELLOW, string);
	return 1;
}

dcmd_resetpracy(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new id;
	new job;
	if(sscanf(params, "ui", id, job))
	{
		gPlayerData[id][pJob] = job;
		gPlayerData[id][pJobTimeChange] = 0;

		SavePlayerData(id, "Job");
		SavePlayerData(id, "JobTimeChange");
	}
	return 1;
}

dcmd_fixdamage(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] < 4)
		return 0;
	if(IsPlayerInAnyVehicle(playerid))
	{
		new idcar = GetPlayerVehicleID(playerid);
		gVehData[idcar][CarDamaged] = 0;
	}
	return 1;
}

dcmd_ajail(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] == 0 && gPlayerData[playerid][pModerator] == 0)
	{
		return 0;
	}
	
	new string[128];
	new playa;
	new time;
	new reason[128];
	if(sscanf(params, "dds[128]", playa, time, reason))
	{
		SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] /ajail [playerid] [minutes] [reason]");
		return 1;
	}
	if(IsPlayerConnected(playa))
	{
		if(playa != INVALID_PLAYER_ID)
		{
			if(time != 0)
			{
				format(string, sizeof(string), "[INFO:] Uwiêzi³eœ %s na %d munut.", GetPlayerNameEx(playa), time);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
				
				format(string, sizeof(string), "[INFO:] Zosta³eœ uwiêziony przez %s na %d minut", GetPlayerNameEx(playerid),time);
				SendClientMessage(playa, COLOR_RED, string);
				
				format(string, sizeof(string), "[INFO:] Powód: %s ", reason);
				SendClientMessage(playa, COLOR_RED, string);
				
				format(string, sizeof(string), "[ADMIN:] %s zosta³ uwiêziony przez %s na %d minut", GetPlayerNameEx(playa), GetPlayerNameEx(playerid), time);
				SendAdminMessage(COLOR_YELLOW, string);
				SendModMessage(COLOR_GREEN, string);
				
				format(string, sizeof(string), "[INFO:] Powód: %s ", reason);
				SendAdminMessage(COLOR_YELLOW, string);
				SendModMessage(COLOR_GREEN, string);
				
				ResetPlayerWeapons(playa);
				
				gPlayerData[playa][pJailed] = 1;
				gPlayerData[playa][pJailTime] = time*60;

				SetPlayerSkinEx( playa, 96 );

				SavePlayerData(playa, "Jailed");
				SavePlayerData(playa, "JailTime");
				SetPlayerVirtualWorld(playa,21); //BUILDING ID 2, MAKE SURE PD IS ID 2
				SetPlayerInterior(playa, 0);

				DBVariables[2][varDValue]++;
				switch(DBVariables[2][varDValue])
				{
					case 0: SetPlayerToPos(playa, 1778.6060791016,-1581.3503417969,1738.7172851563);
					case 1: SetPlayerToPos(playa, 1778.60546875,-1581.349609375,1734.9417724609);
					case 2: SetPlayerToPos(playa, 1774.3107910156,-1580.8834228516,1734.9429931641);
					case 3: SetPlayerToPos(playa, 1770.0396728516,-1580.9715576172,1734.9429931641);
					case 4: SetPlayerToPos(playa, 1765.6442871094,-1581.0885009766,1734.9429931641);
					case 5: SetPlayerToPos(playa, 1761.5192871094,-1580.9661865234,1734.9429931641);
					case 6: SetPlayerToPos(playa, 1757.1713867188,-1581.1558837891,1734.9429931641);
					case 7: SetPlayerToPos(playa, 1757.3331298828,-1565.4664306641,1734.9429931641);
					case 8: SetPlayerToPos(playa, 1761.7298583984,-1565.6207275391,1734.9429931641);
					case 9: SetPlayerToPos(playa, 1765.9074707031,-1565.1364746094,1734.9429931641);
					case 10: SetPlayerToPos(playa, 1770.2448730469,-1565.3743896484,1734.9429931641);
					case 11: SetPlayerToPos(playa, 1774.5153808594,-1565.1875,1734.9429931641);
					case 12: SetPlayerToPos(playa, 1778.6448974609,-1565.0377197266,1734.9429931641);
					case 13: SetPlayerToPos(playa, 1774.236328125,-1580.9116210938,1738.7172851563);
					case 14: SetPlayerToPos(playa, 1770.1110839844,-1580.9205322266,1738.7172851563);
					case 15: SetPlayerToPos(playa, 1765.7939453125,-1581.2406005859,1738.7172851563);
					case 16: SetPlayerToPos(playa, 1761.4822998047,-1581.0185546875,1738.7172851563);
					case 17: SetPlayerToPos(playa, 1757.3651123047,-1581.0830078125,1738.7172851563);
					case 18: SetPlayerToPos(playa, 1757.3023681641,-1565.8057861328,1738.6934814453);
					case 19: SetPlayerToPos(playa, 1761.7540283203,-1565.4591064453,1738.6934814453);
					case 20: SetPlayerToPos(playa, 1765.8216552734,-1565.5594482422,1738.6934814453);
					case 21: SetPlayerToPos(playa, 1770.0919189453,-1565.4733886719,1738.6934814453);
					case 22: SetPlayerToPos(playa, 1774.4881591797,-1565.1726074219,1738.6934814453);
					case 23: SetPlayerToPos(playa, 1778.5562744141,-1565.2510986328,1738.6937255859);
				}
				if(DBVariables[2][varDValue] == 23)
					DBVariables[2][varDValue] = 0;

				TogglePlayerControllable(playa, 0);
				defer UnfreezePlayer(playa);
			}
			else
			{
				if( gPlayerData[playa][pDuty] && DynamicFactions[ gPlayerData[playerid][pFaction] ][fUseSkins] )
					SetPlayerToFactionSkin(playa);
				else
					SetPlayerSkinEx(playa,gPlayerData[playa][pSkin]);

				gPlayerData[playa][pJailed] = 0;
				SavePlayerData(playa, "Jailed");

				gPlayerData[playa][pJailTime] = 0;
				SavePlayerData(playa, "JailTime");

				SendClientMessage(playa, COLOR_LIGHTYELLOW2,"[INFO:] Zosta³eœ rozgrzeszony i wypuszczony.");
				SetPlayerToPos(playa,-302.0,1504.0, 76.5);
				SetPlayerInterior(playa, 0);
				SetPlayerVirtualWorld(playa,0);

				gPlayerData[playerid][pCrashX] = -302.0;
				gPlayerData[playerid][pCrashY] = 1504.0;
				gPlayerData[playerid][pCrashZ] = 76.5;
				gPlayerData[playa][pCrashInt] = 0;
				gPlayerData[playa][pCrashW] = 0;
			}
		}
	}
	else
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Gracz nie jest online");
	}
	return 1;
}

dcmd_amechanicjobpos(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] < 4)
		return 0;
	new Float:x, Float:y, Float:z;
	GetPlayerPos(playerid, x, y, z);
	new Float:angle;
	GetPlayerFacingAngle(playerid, angle);
	MechanicJob[TakeJobX] = x;
	MechanicJob[TakeJobY] = y;
	MechanicJob[TakeJobZ] = z;
	MechanicJob[TakeJobPickupID] = ChangePickupModel(MechanicJob[TakeJobPickupID], 1239,MechanicJob[TakeJobX], MechanicJob[TakeJobY], MechanicJob[TakeJobZ]);
	SaveMechanicJob();
	SendClientMessage(playerid, COLOR_ADMINCMD, "You have successfully set the Mechanic Job Position.");
	return 1;
}

dcmd_amechanicrepairpoint(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] < 3)
		return 0;
	new Float:x, Float:y, Float:z;
	GetPlayerPos(playerid, x, y, z);
	MechanicJob1[RepairPointX] = x;
	MechanicJob1[RepairPointY] = y;
	MechanicJob1[RepairPointZ] = z;
	DestroyDynamicPickup( MechanicJob1[RepairPointPickupID] );
	MechanicJob1[RepairPointPickupID] = CreateDynamicPickup(1239,1,MechanicJob1[RepairPointX],MechanicJob1[RepairPointY],MechanicJob1[RepairPointZ]);
	SaveMechanicJob1();
	SendClientMessage(playerid, COLOR_ADMINCMD, "You have successfully set the Mechanic Repair Position.");
	return 1;
}

dcmd_amechanicrepairpoint2(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] < 3)
		return 0;
	new Float:x, Float:y, Float:z;
	GetPlayerPos(playerid, x, y, z);
	MechanicJob1[RepairPointX2] = x;
	MechanicJob1[RepairPointY2] = y;
	MechanicJob1[RepairPointZ2] = z;
	DestroyDynamicPickup( MechanicJob1[RepairPointPickupID2] );
	MechanicJob1[RepairPointPickupID2] = CreateDynamicPickup(1239,1,MechanicJob1[RepairPointX2],MechanicJob1[RepairPointY2],MechanicJob1[RepairPointZ2]);
	SaveMechanicJob1();
	SendClientMessage(playerid, COLOR_ADMINCMD, "You have successfully set the Mechanic Repair Position 2.");
	return 1;
}

dcmd_amechanicrepairpoint3(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] < 3)
		return 0;
	new id;
	if(sscanf(params, "d", id))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /amechanicrepairpoint3 [id 0-9]");
		return 1;
	}
	new Float:x, Float:y, Float:z;
	GetPlayerPos(playerid, x, y, z);
	MechanicJob1[RepairPointX3][id] = x;
	MechanicJob1[RepairPointY3][id] = y;
	MechanicJob1[RepairPointZ3][id] = z;
	DestroyDynamicPickup( MechanicJob1[RepairPointPickupID3][id] );
	MechanicJob1[RepairPointPickupID3][id] = CreateDynamicPickup(1239,1,MechanicJob1[RepairPointX3][id],MechanicJob1[RepairPointY3][id],MechanicJob1[RepairPointZ3][id]);
	SaveMechanicJob1();
	SendClientMessage(playerid, COLOR_ADMINCMD, "You have successfully set the Mechanic Repair Position > 3.");
	return 1;
}

dcmd_amechanicpartspoint(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] < 4)
		return 0;
	new Float:x,Float:y,Float:z;
	GetPlayerPos(playerid, x, y, z);
	new Float:angle;
	GetPlayerFacingAngle(playerid, angle);
	MechanicJob2[BuyProductsX] = x;
	MechanicJob2[BuyProductsY] = y;
	MechanicJob2[BuyProductsZ] = z;
	MechanicJob2[BuyProductsWorld] = GetPlayerVirtualWorld(playerid);
	MechanicJob2[BuyProductsInterior] = GetPlayerInterior(playerid);
	MechanicJob2[BuyProductsAngle] = angle;

	MechanicJob2[BuyProductsPickupID] = ChangePickupModel(MechanicJob2[BuyProductsPickupID], 1239, MechanicJob2[BuyProductsX],MechanicJob2[BuyProductsY],MechanicJob2[BuyProductsZ]);

	SaveMechanicJob2();
	SendClientMessage(playerid, COLOR_ADMINCMD, "You have successfully set the mechanic job. (buy parts place)");
	return 1;
}

dcmd_reanimuj(playerid, params[])
{
	if(gPlayerData[playerid][pFaction] == 2 || gPlayerData[playerid][pAdmin] > 0)
	{
		if(!gPlayerData[playerid][pDuty] && gPlayerData[playerid][pAdmin] <= 0)
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie masz przy sobie respiratora, nie mo¿e reanimowaæ tej osoby !");
			return 1;
		}
		
		if(gPlayerVars[playerid][mIsReanimate])
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Mo¿esz reanimowaæ tylko jedn¹ osobê");
			return 1;
		}
		
		new targetID;
		
		if(sscanf(params, "d", targetID))
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /reanimuj [id gracza]");
			return 1;
		}
		
		if(targetID == playerid && !AdminDuty[playerid])
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz sam siebie reanimowaæ !");
			return 1;
		}
		
		if(gPlayerData[playerid][pCharacterDying] == 0 || AdminDuty[playerid])
		{
			if(gPlayerData[targetID][pCharacterDying] == 0)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ta osoba nie wymaga reanimacji !");
				return 1;
			}
			
			new Float:x, Float:y, Float:z;
			GetPlayerPos(targetID, x, y, z);
			
			if(PlayerToPoint(3.0, playerid, x, y, z) || AdminDuty[playerid])
			{
				PlayerPlayerActionMessage(playerid, targetID, 20.0, "reanimuje");

				ApplyAnimation(playerid,"MEDIC","CPR",4.0, 0, 1, 1, 0, 8500, 1);
				ApplyAnimation(playerid,"MEDIC","CPR",4.0, 0, 1, 1, 0, 8500, 1);

				gPlayerVars[playerid][mIsReanimate] = 9;
				
				defer RPC(targetID);
			}
			else
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Gracz jest zbyt daleko by wykonaæ reanimacje");
				return 1;
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Twoja postaæ jest nieprzytomna, nie mo¿e nikogo reanimowaæ");
			return 1;
		}
	}
	else
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ ratownikiem");
		return 1;
	}
	
	return 1;
}

dcmd_smierc(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pCharacterDying] > 0)
	{
		gPlayerData[playerid][pCharacterDeath] = 1;

		SavePlayerData(playerid, "CharacterDeath");

		gPlayerLogged[playerid] = 0;
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Twoja postaæ zginê³a ! Mo¿esz wyjœæ z gry i zarejestrowaæ now¹ na forum.");
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Istnieje te¿ mo¿liwoœæ wykupienia starej postaæ przez SMS.");

		Kick(playerid);
	}
	return 1;
}

dcmd_zezlomujpojazdf(playerid, params[])
{
	#pragma unused params
	new tmpcar = GetPlayerVehicleID(playerid) - 1;
	new idcar = GetPlayerVehicleID(playerid);
	if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Musisz znajdowaæ siê w pojeŸdzie aby go zez³omowaæ !");
		return 1;
	}
	if(gPlayerData[playerid][pFaction] != 255)
	{
		if(!CheckRankPrivilidges(gPlayerData[playerid][pFaction], gPlayerData[playerid][pRank], "zezlomujpojazdf"))
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie posiadasz uprawnieñ do sprzedawania pojazdów frakcyjnych !");
			return 1;
		}
		if(150 < DynamicFactions[gPlayerData[playerid][pFaction]][fBank])
		{
			if( gVehData[tmpcar][mVehFaction] == 255 )
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz zez³omowaæ tego pojazdu !");
				return 1;
			}
			if(gVehData[tmpcar][mVehFaction] != gPlayerData[playerid][pFaction])
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ten pojazd nie nale¿y do Twojej frakcji !");
				return 1;
			}
			new string[128];

			DynamicFactions[gVehData[tmpcar][mVehFaction]][fBank] -= floatround(gVehData[tmpcar][Price] * 0.20, floatround_round);
			DynamicFactions[FACTIONID_GOVERNMENT][fBank] += floatround(gVehData[tmpcar][Price] * 0.20, floatround_round);

			SaveFData(gVehData[tmpcar][mVehFaction], "Bank");
			SaveFData(FACTIONID_GOVERNMENT, "Bank");

			gVehData[tmpcar][mVehModel] = 0;
			gVehData[tmpcar][mVehX] = 0.0;
			gVehData[tmpcar][mVehY] = 0.0;
			gVehData[tmpcar][mVehZ] = 0.0;
			gVehData[tmpcar][mVehA] = 0.0;
			gVehData[tmpcar][mVehColor1] = -1;
			gVehData[tmpcar][mVehColor2] = -1;
			if(gVehData[tmpcar][mVehFaction] != 255)
			{
				if(!(DynamicFactions[gVehData[tmpcar][mVehFaction]][fCarsCount] <= 0))
				{
					DynamicFactions[gVehData[tmpcar][mVehFaction]][fCarsCount]--;
				}
			}
			gVehData[tmpcar][mVehFaction] = 255;
			gVehData[tmpcar][mVehType] = 0;
			gVehData[tmpcar][mVehOwned] = 0;
			strmid(gVehData[tmpcar][Owner], "None", 0, 4, 128);
			gVehData[tmpcar][Price] = 0;
			gVehData[tmpcar][Closed] = 0;
			gVehData[tmpcar][CarResetT] = 0;
			gVehData[tmpcar][CarDamaged] = 0;
			gVehData[tmpcar][CarRepairTimeLeft] = 0;
			gVehData[tmpcar][BusinessID] = 255;
			gVehData[tmpcar][CarFuel] = float(VehFTank(idcar));
			gVehData[tmpcar][CarHealth] = 1000.0;

			SaveVehData(tmpcar, "VehModel");
			SaveVehData(tmpcar, "VehPos");
			SaveVehData(tmpcar, "VehColor1");
			SaveVehData(tmpcar, "VehColor2");
			SaveVehData(tmpcar, "VehFaction");
			SaveVehData(tmpcar, "VehType");
			SaveVehData(tmpcar, "VehOwned");
			SaveVehData(tmpcar, "Owner");
			SaveVehData(tmpcar, "Price");
			SaveVehData(tmpcar, "Closed");
			SaveVehData(tmpcar, "CarResetT");
			SaveVehData(tmpcar, "CarDamaged");
			SaveVehData(tmpcar, "CarRepairTimeLeft");
			SaveVehData(tmpcar, "BusinessID");
			SaveVehData(tmpcar, "CarFuel");
			SaveVehData(tmpcar, "CarHealth");

			// DestroyVehicle(idcar);
			defer ResetVehicleData(idcar,1);
			TogglePlayerControllable(playerid, 1);

			format(string, sizeof(string), "[INFO:] Zez³omowa³eœ pojazd frakcji");
			SendClientMessage(playerid, COLOR_GREEN, string);

			SaveFData(4, "CarsCount");
			return 1;
		}
		else
		{
			new string[128];
			format(string, sizeof(string), "[INFO:] Nie masz wystarczaj¹cej iloœci pieniêdzy na koncie frakcji aby zez³omowaæ pojazd ($%d) !", floatround(gVehData[tmpcar][Price] * 0.20, floatround_round));
			SendClientMessage(playerid, COLOR_RED, string);
			return 1;
		}
	}
	else
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie nale¿ysz do ¿adnej frakcji !");
		return 1;
	}
}

dcmd_sprowadzpojazd(playerid, params[])
{
	new modelID, fuelType, isFuelType;
	isFuelType = 0;
	new string[128];
	if(sscanf(params, "dd", modelID, fuelType))
	{
		SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] /sprowadzpojazd [id modelu] [typ paliwa]");
		return 1;
	}
	for(new i = 0; i < sizeof(Businesses); i++)
	{
		if(!PlayerToPoint(100.0, playerid, Businesses[i][ExitX], Businesses[i][ExitY], Businesses[i][ExitZ]) || GetPlayerVirtualWorld(playerid) != i)
			continue;
		if(strcmp(gPlayerData[playerid][pName], Businesses[i][Owner], false) != 0 && !Businesses[i][BGov])
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w³aœcicielem tego biznesu");
			return 1;
		}
		if(Businesses[i][BGov] && gPlayerData[playerid][pFaction] != FACTIONID_GOVERNMENT)
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ urzêdnikiem");
			return 1;
		}
		if(Businesses[i][BizType] != 10)
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Ten biznes nie jest salonem samochodowym !");
			return 1;
		}
		if(modelID < 400 || modelID > 611)
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Modele pojazdów nale¿¹ do zakresu od 400 do 611.");
			return 1;
		}
		if(cenyPojazdow[modelID-400] == 0)
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie mo¿esz sprowadziæ tego pojazdu !");
			return 1;
		}
		if(Businesses[i][Till] >= cenyPojazdow[modelID-400])
		{
			if((Businesses[i][VehicleCount] + Businesses[i][VehicleOrderCount]) < Businesses[i][MaxVehicles])
			{
				gBuyBusinessID[playerid] = i;
				for(new n = 0; n < sizeof(CarsData); n++)
				{
					if(CarsData[n][Model] == modelID)
					{
						if(CarsData[n][Paliwo] == fuelType)
						{
							isFuelType = 1;
							gPlayerVars[playerid][mVehMaxHealth] = CarsData[n][MaxHealth];
							// printf("Car Health recognized as %d", CarsData[n][MaxHealth]);
							break;
						}
					}
				}
				if(isFuelType == 0)
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ten pojazd nie wystêpuje z tego typu silnikiem");
					return 1;
				}
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Sprawdzanie danych, za chwile dostaniesz informacje o importowanym pojeŸdzie", "Zamknij", "");
				
				gPlayerVars[playerid][mFuelType] = fuelType;
				
				format(string, sizeof(string), "SELECT HIGH_PRIORITY * FROM `samp_vehicles_limits` WHERE `modelID` = '%d'", modelID);
				wp_mysql_query(string, CHECK_VEHICLE_AVAILABLE, playerid, db_con4);				
				
				return 1;
			}
			else
			{
				format(string, sizeof(string), "[INFO:] Osi¹gn¹³eœ limit iloœci pojazdów dla tego biznesu (%d)", Businesses[i][MaxVehicles]);
				SendClientMessage(playerid, COLOR_RED, string);
				return 1;
			}
		}
		else
		{
			format(string, sizeof(string), "[INFO:] Nie wystarczaj¹ca iloœæ pieniêdzy w kasie biznesu do sprowadzenia pojazdu ! Koszt: $%d", cenyPojazdow[modelID-400]);
			SendClientMessage(playerid, COLOR_RED, string);
			return 1;
		}
	}
	SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ wewn¹trz ¿adnego biznesu !");
	return 1;
}

dcmd_statuszamowien(playerid, params[])
{
	#pragma unused params
	for(new i = 0; i < sizeof(Businesses); i++)
	{
		if(!PlayerToPoint(100.0, playerid, Businesses[i][ExitX], Businesses[i][ExitY], Businesses[i][ExitZ]) || GetPlayerVirtualWorld(playerid) != i)
			continue;
		if(strcmp(gPlayerData[playerid][pName], Businesses[i][Owner], false) != 0)
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w³aœcicielem tego biznesu !");
			return 1;
		}
		if(Businesses[i][BizType] != 10)
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Niew³aœciwy typ biznesu !");
			return 1;
		}
		if(Businesses[i][VehicleOrderCount] == 0)
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Aktualnie nie masz aktywnych zamówieñ");
			return 1;
		}
		new string[128];
		format(string, sizeof(string), "[INFO:] Aktualnie masz %d aktywnych zamówieñ pojazdów", Businesses[i][VehicleOrderCount]);
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
		return 1;
	}
	SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Musisz znajdowaæ siê wewn¹trz biznesu");
	return 1;
}

dcmd_cenapojazdu(playerid, params[])
{
	new vehicleID = GetPlayerVehicleID(playerid);
	new cena;
	new string[128];
	if(sscanf(params, "d", cena))
	{
		SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] /cenapojazdu [cena]");
		return 1;
	}
	if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Musisz byæ w pojeŸdzie aby ustaliæ jego cene !");
		return 1;
	}
	if(strcmp(gPlayerData[playerid][pName], Businesses[gVehData[vehicleID-1][BusinessID]][Owner], false) != 0)
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Ten pojazd nie nale¿y do twojego biznesu");
		return 1;
	}
	format(string, sizeof(string), "[INFO:] Zmieni³eœ cene pojazdu na $%d", cena);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	gVehData[vehicleID-1][Price] = cena;

	SaveVehData(vehicleID-1, "Price");
	return 1;
}

dcmd_aplayercmds(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] == 0)
		return 0;
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "================================================================================================================================");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "/ban - /unban - /banaccount - /unbanaccount - /getip - /update - /error - /retaketut - /setvw - disarm");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "/checkweapons - /prison - /unprison - /name - /destroy - /setskin - /explode - /slap - /asetleader");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "/aplayerbizid - /resetpracy - /additem - /rmplayeritem - /playeritems - /spec - /specoff - /getip");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "/error - /setvw - /disarm - /checkweapons - /prison - /unprison - /name - /destroy - /setskin - /explode");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "/slap - /banaccount - /mbanaccount - /asetplayervipafk - /asetplayervipafkt - /asetplayervipexp - /ahoursplayed - /setvipobj");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "================================================================================================================================");
	return 1;
}

dcmd_achatcmds(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] == 0)
		return 0;
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "================================================================================================================================");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[ADMIN:] /nonewbie - /ao(oc) - /mo - /noooc - /nonewbie - /nopwooc - /listenchat");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "================================================================================================================================");
	return 1;
}

dcmd_afactioncmds(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] == 0)
		return 0;
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "================================================================================================================================");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[ADMIN:] /afactionspawn - /aresetfaction - /afactioncolor");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[ADMIN:] /afactionuseskins - /afactionname - /afactiontype - /afactionjoinrank - /afactionbank - /afactiondrugs");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[ADMIN:] /afactionmats - /afactionrankamount - /afactionrankname - /afactionskin - /afactionusecolor - /gotoffactory");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[ADMIN:] /asetplayerfaction - /afactionkick - /afactionmaxvehicles - /afactionvehiclescount - /agotofaction");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "================================================================================================================================");
	return 1;
}

dcmd_avehcmds(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] == 0)
		return 0;
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "================================================================================================================================");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "/rtc - /supervehslap - /afuelcar - /fixveh - /fixveh2 - /agetcar - /acarlocations - /moatv - /rotvobj - /mvvobj - /rvobj");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "/acarsreset - /arepairallvehicles - /acarpark(dynamic) - /acarmodelprice - /acarmodel - /afactioncar - /vehtypelist");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "/acarcolor(ex) - /acartype - /acarenter - /acarsetpos - /acardata - /acarint - /acarbiz - /acarrepairtl - /fullbattery");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "/acarresett - /acarclosed - /acarkm - /acarbusinessid - /acarreadytosell - /setcar(r)serial - /fullbatteries");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "/setcarserialtoall - /acarcomponentslot - /acaraddcomponent - /acarcomponentslottype - /setvehicletosell - /setvehicletorent");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "/offvehlights - /offvehradio - /setvehhp - /vehcb - /vehhook - /vehalarm - /oddajkluczykipoj - /changestacyjka - /vehfueltype");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "================================================================================================================================");
	return 1;
}

dcmd_abuildingcmds(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] == 0)
		return 0;
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "================================================================================================================================");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[ADMIN:] /abuildingint - /abuildingentrance - /agotobuilding - /abuldinglock - /abuildingexit - /abuildingname - /resetbuilding");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[ADMIN:] /abuildingfee - /abuildingcloset - /abuildingopent - /abuildingstreetno - /abuildingdata - /abuildingtype");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "================================================================================================================================");
	return 1;
}

dcmd_ahousecmds(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] == 0)
		return 0;
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "================================================================================================================================");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[ADMIN:] /ahousedata - /agotohouse - /ahouseint - /ahouseprice - /ahouseentrance - /ahouseexit - /ahousedescription");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[ADMIN:] /houseplaced - /houseintset - /ahouseconfiscated - /ahousestreetno");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "================================================================================================================================");
	return 1;
}

dcmd_abizcmds(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] == 0)
		return 0;
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "================================================================================================================================");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "/abizdata - /agotobiz - /abizproducts - /abizprice - /abiztype - /abizentrance - /bizintset - /abiztill - /abizaddtill");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "/abizexit - /abizint - /abizname - /abizsell - /abizreset - /abizowner - /abizconfiscated - /abusinessprudcts");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "/aplayerbizid - /abusinessmaxcars - /abizvehorders - /abizvehcount - /abizvehspawned - /gspos - /abizlock - /abizstreetno");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "/abizidtogasstation - /setgasstationresources - /setgasstationmaxresources - /setgasstationfuelprice - /gstl2pos - /gstl1pos");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "/abizfaction - /abizfactiontime - /abizentrancefee - /bizplaced - /abizicon");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "================================================================================================================================");
	return 1;
}

dcmd_alocationscmds(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] == 0)
		return 0;
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "================================================================================================================================");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[ADMIN:] /agotobiz - /agotohouse - /agotobuilding - /agotobank - /agotodrivingtestpos");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[ADMIN:] /agotoflyingtestpos - /agotopolicearrestpos - /agotopolicedutypos - /agotofmatsstorage");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[ADMIN:] /abankpos - /agotoweaponlicensepos");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[ADMIN:] /aflyingtestpos - /adrivingtestpos - /apolicearrestpos - /apolicedutypos - /acivilianspawn");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[ADMIN:] /afactionspawn - /agotofaction - /gotols - /gotosf - /gotolv - /gotoprison - /gotohosp");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "================================================================================================================================");
	return 1;
}

dcmd_ajobcmds(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] == 0)
		return 0;
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "================================================================================================================================");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[ADMIN:] /adetectivejobpos - /alawyerjobpos - /adrugjobpos - /adrugjobpos2 - /adrugjobpos3 - /aRapistjobpos - /amechanicpartspoint");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[ADMIN:] /aWhorejobpos - /aDirjobpos - /aStuntjobpos - /aCarjackjobpos - /aBodyjobpos - /aBoxerjobpos");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[ADMIN:] /aproductjobpos - /aproductjobpos2 - /agunjobpos - /agunjobpos2 - /agunjobpos3 - /afarmerjobpos - /awfworkerjobpos");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[ADMIN:] /abusjobpos - /amzgkjobpos - /asweeperjobpos - /ataxijobpos - /anewsboyjobpos - /anewsboyjobreward - /anewsboyjobpapers");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "================================================================================================================================");
	return 1;
}

dcmd_umowaoc(playerid, params[])
{
	new form[256];
	new givePlayerID;
	new slot;
	
	if(sscanf(params, "dd", givePlayerID, slot))
	{
		SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] /umowaoc [id gracza] [slot]");
		SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] slot: (1-25) zawieraj¹cy dowód rejestracyjny");
		return 1;
	}
	
	if(gPlayerData[playerid][pFaction] != FACTIONID_GOVERNMENT)
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie jesteœ urzêdnikiem !");
		return 1;
	}
	
	if(slot > 25 || slot <= 0)
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Niepoprawne ID slotu");
		return 1;
	}
	
	if(!gPlayerLogged[givePlayerID])
	{
		SendClientMessage(playerid,COLOR_RED,"[INFO:] Podany gracz nie jest on-line !");
		return 1;
	}
	
	if(!PSlotItemTypeCompare(givePlayerID, slot, 3) || ShowSlotItem(givePlayerID, slot) != 19)
	{
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Na tym slocie ta osoba nie posiada dowodu rejestracyjnego pojazdu", "Zamknij", "");
		return 1;
	}
	
	if(SlotParam3(givePlayerID, slot) != 0)
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ta osoba podpisa³a ju¿ umowe OC !");
		return 1;
	}
	
	GetPlayerPos(givePlayerID, gPlayerData[givePlayerID][pCrashX], gPlayerData[givePlayerID][pCrashY], gPlayerData[givePlayerID][pCrashZ]);
	
	if(!PlayerToPoint(3.5, playerid, gPlayerData[givePlayerID][pCrashX], gPlayerData[givePlayerID][pCrashY], gPlayerData[givePlayerID][pCrashZ]))
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Jesteœ zbyt daleko od tej osoby !");
		return 1;
	}
	
	EnsuranceOC[givePlayerID][vehicleNr] = slot;
	EnsuranceOC[givePlayerID][Level] = 1;
	
	PlayerPlayerActionMessage(playerid, givePlayerID, 10.0, "przekaza³ umowe");
	
	format(form, sizeof(form), "Umowa OC\nKoszt podpisania umowy wynosi 150$\nW przypadku straty pojazdu uzyskuje siê 30%% zwrotu z rynkowej ceny pojazdu.\nAby uzyskaæ 60%% zwrotu nale¿y dodatkowo wykupiæ ubezpieczenie AC\nSk³adka dzienna: 4$\n\nAby podpisaæ umowe wpisz /akceptuj umoweoc");
	ShowPlayerDialog(givePlayerID, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", form, "Zamknij", "");

	// log
	format(form, sizeof(form), "[GOVERNMENT:] OC agreement prepeared by %s for %s, veh serial %d", gPlayerData[playerid][pName], gPlayerData[givePlayerID][pName], ShowSlotItem(givePlayerID, slot));
	GovermentLog(form);

	return 1;
}

dcmd_umowaac(playerid, params[])
{
	new form[256];
	new givePlayerID;
	new slot;
	
	if(sscanf(params, "dd", givePlayerID, slot))
	{
		SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] /umowaac [id gracza] [slot]");
		SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] slot: (1-25) zawieraj¹cy dowód rejestracyjny");
		return 1;
	}
	
	if(gPlayerData[playerid][pFaction] != FACTIONID_GOVERNMENT)
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie jesteœ urzêdnikiem !");
		return 1;
	}
	
	if(slot > 25 || slot <= 0)
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Niepoprawne ID slotu");
		return 1;
	}
	
	if(!gPlayerLogged[givePlayerID])
	{
		SendClientMessage(playerid,COLOR_RED,"[INFO:] Podany gracz nie jest on-line !");
		return 1;
	}
	
	if(!PSlotItemTypeCompare(givePlayerID, slot, 3) || ShowSlotItem(givePlayerID, slot) != 19)
	{
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Na tym slocie ta osoba nie posiada dowodu rejestracyjnego pojazdu", "Zamknij", "");
		return 1;
	}
	
	if(SlotParam4(givePlayerID, slot) != 0)
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ta osoba podpisa³a ju¿ umowe AC !");
		return 1;
	}
	
	GetPlayerPos(givePlayerID, gPlayerData[givePlayerID][pCrashX], gPlayerData[givePlayerID][pCrashY], gPlayerData[givePlayerID][pCrashZ]);
	
	if(!PlayerToPoint(3.5, playerid, gPlayerData[givePlayerID][pCrashX], gPlayerData[givePlayerID][pCrashY], gPlayerData[givePlayerID][pCrashZ]))
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Jesteœ zbyt daleko od tej osoby !");
		return 1;
	}
	
	EnsuranceAC[givePlayerID][vehicleNr] = slot;
	EnsuranceAC[givePlayerID][Level] = 1;
	
	PlayerPlayerActionMessage(playerid, givePlayerID, 10.0, "przekaza³ umowe");
	
	format(form, sizeof(form), "Umowa AC\nKoszt podpisania umowy wynosi 450$\nW przypadku straty pojazdu uzyskuje siê 30%% zwrotu z rynkowej ceny pojazdu.\nSk³adka dzienna: 6$\n\nAby podpisaæ umowe wpisz /akceptuj umoweac");
	ShowPlayerDialog(givePlayerID, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", form, "Zamknij", "");

	// log
	format(form, sizeof(form), "[GOVERNMENT:] AC agreement prepeared by %s for %s, veh serial %d",gPlayerData[playerid][pName], gPlayerData[givePlayerID][pName], ShowSlotItem(givePlayerID, slot));
	GovermentLog(form);
	return 1;
}

dcmd_zrezygnujzoc(playerid, params[])
{
	new slot;
	if(sscanf(params, "d", slot))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /zrezygnujzoc [slot(1-25)]");
		return 1;
	}
	if(PSlotItemTypeCompare(playerid, slot, 3) && ShowSlotItem(playerid, slot) == 19 && SlotParam3(playerid, slot))
	{
		SetPSlotParam3(playerid, slot, 0);
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Zrezygnowa³eœ z ubezpieczenia OC");
		return 1;
	}
	else
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Na tym slocie nie posiadasz dowodu rejestracyjnego z aktywnym ubezpieczeniem");
		return 1;
	}
}

dcmd_zrezygnujzac(playerid, params[])
{
	new slot;
	if(sscanf(params, "d", slot))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /zrezygnujzac [slot(1-25)]");
		return 1;
	}
	if(PSlotItemTypeCompare(playerid, slot, 3) && ShowSlotItem(playerid, slot) == 19 && SlotParam4(playerid, slot))
	{
		SetPSlotParam3(playerid, slot, 0);
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Zrezygnowa³eœ z ubezpieczenia AC");
		return 1;
	}
	else
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Na tym slocie nie posiadasz dowodu rejestracyjnego z aktywnym ubezpieczeniem");
		return 1;
	}
}

dcmd_wyplacodszkodowanieoc(playerid, params[])
{
	new slot;
	new givePlayerID;
	new string[128];
	if(sscanf(params, "dd", givePlayerID, slot))
	{
		SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] /wyplacodszkodowanieoc [id gracza] [slot(1-25)]");
		return 1;
	}
	if(gPlayerData[playerid][pFaction] != 9)
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie jesteœ urzêdnikiem !");
		return 1;
	}
	if(playerid == givePlayerID)
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie mo¿esz sam sobie wyp³aciæ odszkodowania !");
		return 1;
	}
	if(PItemSlotStatus(givePlayerID, slot) == 0 || !PSlotItemTypeCompare(givePlayerID, slot, 3))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ta osoba na tym slocie nie posiada dowodu rejestracyjnego pojazdu");
		return 1;
	}
	if(SlotParam3(givePlayerID, slot) == 0)
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ta osoba nie posiada ubezpieczenia OC na wybrany pojazd !");
		return 1;
	}
	new match, matchserial;
	for(new i = 0; i < sizeof(gVehData); i++)
	{
		if(gVehData[i][mVehVinNo] == SlotParam2(givePlayerID, slot))
		{
			match = 1;
		}
		if(gVehData[i][CarSerial] == SlotParam1(givePlayerID, slot))
		{
			matchserial = 1;
		}
	}
	if(!matchserial && !match)
	{
		GivePlayerCash(givePlayerID, SlotParam3(givePlayerID, slot));
		DynamicFactions[FACTIONID_GOVERNMENT][fBank] -= SlotParam3(givePlayerID, slot);
		SaveFData(FACTIONID_GOVERNMENT, "Bank");

		format(string, sizeof(string),"[INFO:] Wyp³acono odszkodowanie dla %s", gPlayerData[givePlayerID][pName]);
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);

		format(string, sizeof(string), "[INFO:] Wyp³acono odszkodowanie za strate samochodu w wysokoœci %d", SlotParam3(givePlayerID, slot));
		SendClientMessage(givePlayerID, COLOR_GREEN, string);

		PlayerPlayerActionMessage(playerid, givePlayerID, 20.0, "przekazuje pieni¹dze");
		
		SetPSlotParam3(givePlayerID, slot, 0);

		format(string, sizeof(string), "[GOVERNMENT:] Player: %s payed ensurance OC for %s, vehicle serial: %d", gPlayerData[playerid][pName], gPlayerData[givePlayerID][pName], ShowSlotItem(givePlayerID, slot));
		GovermentLog(string);
	}
	else
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Pojazd tej osoby nie jest zniszczony");
	}
	return 1;
}

dcmd_wyplacodszkodowanieac(playerid, params[])
{
	new slot;
	new givePlayerID;
	new string[128];
	if(sscanf(params, "dd", givePlayerID, slot))
	{
		SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] /wyplacodszkodowanieac [id gracza] [slot(1-25)]");
		return 1;
	}
	if(gPlayerData[playerid][pFaction] != 9)
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie jesteœ urzêdnikiem !");
		return 1;
	}
	if(playerid == givePlayerID)
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie mo¿esz sam sobie wyp³aciæ odszkodowania !");
		return 1;
	}
	if(PItemSlotStatus(givePlayerID, slot) == 0 || !PSlotItemTypeCompare(givePlayerID, slot, 3))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ta osoba na tym slocie nie posiada dowodu rejestracyjnego pojazdu");
		return 1;
	}
	if(SlotParam4(givePlayerID, slot) == 0)
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ta osoba nie posiada ubezpieczenia AC na wybrany pojazd !");
		return 1;
	}
	new match, matchserial;
	for(new i = 0; i < sizeof(gVehData); i++)
	{
		if(gVehData[i][mVehVinNo] == SlotParam2(givePlayerID, slot))
		{
			match = 1;
		}
		if(gVehData[i][CarSerial] == SlotParam1(givePlayerID, slot))
		{
			matchserial = 1;
		}
	}
	if(!matchserial && !match)
	{
		GivePlayerCash(givePlayerID, SlotParam4(givePlayerID, slot));
		DynamicFactions[FACTIONID_GOVERNMENT][fBank] -= SlotParam4(givePlayerID, slot);
		SaveFData(FACTIONID_GOVERNMENT, "Bank");

		format(string, sizeof(string),"[INFO:] Wyp³acono odszkodowanie dla %s", gPlayerData[givePlayerID][pName]);
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);

		format(string, sizeof(string), "[INFO:] Wyp³acono odszkodowanie za strate samochodu w wysokoœci %d", SlotParam4(givePlayerID, slot));
		SendClientMessage(givePlayerID, COLOR_GREEN, string);

		SetPSlotParam4(givePlayerID, slot, 0);

		format(string, sizeof(string), "[GOVERNMENT:] Player: %s payed ensurance AC for %s, vehicle serial: %d", gPlayerData[playerid][pName], gPlayerData[givePlayerID][pName], ShowSlotItem(givePlayerID, slot));
		GovermentLog(string);
	}
	else
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Pojazd tej osoby nie jest zniszczony");
	}
	return 1;
}

dcmd_przemaluj(playerid, params[])
{
	new color1;
	new color2;
	new vehicleID;
	
	if(sscanf(params, "dd", color1, color2))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /przemaluj [kolor1] [kolor2]");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] kolor1/kolor2 - od 0 do 255");
		return 1;
	}
	
	if(gPlayerData[playerid][pJob] != JOB_MECHANIC && !AdminDuty[playerid])
	{
		ShowPlayerDialog(playerid, DIALOG_ITEM_3, DIALOG_STYLE_MSGBOX, "Informacja", "Nie mo¿esz zamontowaæ tej czêœci - nie jesteœ mechanikiem !", "Wróæ", "");
		return 1;
	}
	
	if(gPlayerData[playerid][pFaction2] == 255)
	{
		ShowPlayerDialog(playerid, DIALOG_ITEM_3, DIALOG_STYLE_MSGBOX, "Informacja", "Musisz nale¿eæ do firmy aby naprawiaæ pojazdy.", "Wróæ", "");
		return 1;
	}
	
	new inCompanyMech = 0;
		
	for(new i = 0; i < sizeof(Building); i++)
	{
		if(Building[i][FactionOwnerId] != gPlayerData[playerid][pFaction2])
		{
			continue;
		}
		
		if(!PlayerToPoint(15.0, playerid, Building[i][EnterX], Building[i][EnterY], Building[i][EnterZ]) && !PlayerToPoint(30.0, playerid, Building[i][ExitX], Building[i][ExitY], Building[i][ExitZ]))
		{
			continue;
		}
		
		inCompanyMech = 1;
	}
	
	if(!inCompanyMech && !AdminDuty[playerid])
	{
		ShowPlayerDialog(playerid, DIALOG_ITEM_3, DIALOG_STYLE_MSGBOX, "Informacja", "Musisz znajdowaæ siê przy warsztacie twojej firmy.", "Wróæ", "");
		return 1;
	}
	
	vehicleID = GetClosestVehicle(playerid);

	if(vehicleID == INVALID_VEHICLE_ID)
	{
		ShowPlayerDialog(playerid, DIALOG_ITEM_3, DIALOG_STYLE_MSGBOX, "Informacja", "Musisz znajdowaæ siê przy pojeŸdzie aby u¿yæ tych czêœci.", "Wróæ", "");
		return 1;
	}
	
	if(gVehData[vehicleID-1][EngineOn])
	{
		ShowPlayerDialog(playerid, DIALOG_ITEM_3, DIALOG_STYLE_MSGBOX, "Informacja", "Wy³¹cz silnik przed rozpoczêciem napraw.", "Wróæ", "");
		return 1;
	}
	
	if(color1 < 0 || color1 >  255 || color2 < 0 || color2 > 255)
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] kolor1/kolor2 - od 0 do 255");
		return 1;
	}
	
	new Float:x, Float:y, Float:z;
	GetVehiclePos(vehicleID, x, y, z);
	
	if(!PlayerToPoint(8, playerid, x, y, z))
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Jesteœ zbyt daleko od pojazdu");
		return 1;
	}
	
	new panels, doors, lights, tires;
	GetVehicleDamageStatus(vehicleID, panels, doors, lights, tires);

	if(panels != 0 || doors != 0)
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Musisz naprawiæ karoserie pojazdu zanim bêdziesz móg³ go przemalowaæ !");
		return 1;
	}
	
	if(isPainting[vehicleID-1])
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Zanim przejdziesz do nastêpnego etapu malowania musisz ukoñczyæ poprzedni !");
		return 1;
	}
	
	if(gVehData[vehicleID-1][PaintStep] == 0)
	{
		PlayerActionMessage(playerid, 20.0, "zaczyna nak³adaæ lakier");
		gVehData[vehicleID-1][PaintStep] = 1;
		isPainting[vehicleID-1] = 1;
		defer PaintTimer(vehicleID-1);

		SaveVehData(vehicleID-1, "PaintStep");

		return 1;
	}
	
	if(gVehData[vehicleID-1][PaintStep] == 1)
	{
		PlayerActionMessage(playerid, 20.0, "kontynuuje nak³adanie lakieru z przodu pojazdu");
		gVehData[vehicleID-1][PaintStep] = 2;
		isPainting[vehicleID-1] = 1;
		defer PaintTimer(vehicleID-1);

		SaveVehData(vehicleID-1, "PaintStep");

		return 1;
	}
	
	if(gVehData[vehicleID-1][PaintStep] == 2)
	{
		PlayerActionMessage(playerid, 20.0, "rozpoczyna nak³adanie lakieru z prawej strony pojazdu");
		gVehData[vehicleID-1][PaintStep] = 3;
		isPainting[vehicleID-1] = 1;
		defer PaintTimer(vehicleID-1);

		SaveVehData(vehicleID-1, "PaintStep");

		return 1;
	}
	
	if(gVehData[vehicleID-1][PaintStep] == 3)
	{
		PlayerActionMessage(playerid, 20.0, "rozpoczyna nak³adanie lakieru z lewej strony pojazdu");
		gVehData[vehicleID-1][PaintStep] = 4;
		isPainting[vehicleID-1] = 1;
		defer PaintTimer(vehicleID-1);

		SaveVehData(vehicleID-1, "PaintStep");

		return 1;
	}
	
	if(gVehData[vehicleID-1][PaintStep] == 4)
	{
		PlayerActionMessage(playerid, 20.0, "rozpoczyna nak³adanie lakieru z ty³u pojazdu");
		gVehData[vehicleID-1][PaintStep] = 5;
		isPainting[vehicleID-1] = 1;
		defer PaintTimer(vehicleID-1);

		SaveVehData(vehicleID-1, "PaintStep");

		return 1;
	}
	
	if(gVehData[vehicleID-1][PaintStep] == 5)
	{
		PlayerActionMessage(playerid, 20.0, "sprawdza stan lakieru");
		gVehData[vehicleID-1][PaintStep] = 0;

		SaveVehData(vehicleID-1, "PaintStep");
	}

	gVehData[vehicleID-1][mVehColor1] = color1;
	gVehData[vehicleID-1][mVehColor2] = color2;
	ChangeVehicleColor(vehicleID, color1, color2);
	// TODO: Cash is going nowhere... Fix this
	GivePlayerCash(playerid, -500);
	
	SendClientMessage(playerid, COLOR_GREEN, "[INFO:] Kolor pojazdu zosta³ zmieniony !");
	SendClientMessage(playerid, COLOR_GREEN, "[INFO:] Koszt malowania: 500$");
	
	SaveVehData(vehicleID-1, "VehColor1");
	SaveVehData(vehicleID-1, "VehColor2");
	return 1;
}

dcmd_acarbiz(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] < 4)
		return 0;
	new vehBizID;
	new vehicleID;
	new string[128];
	if(sscanf(params, "d", vehBizID))
	{
		SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] /acarbiz [business ID]");
		return 1;
	}
	if(IsPlayerInAnyVehicle(playerid))
	{
		vehicleID = GetPlayerVehicleID(playerid);
		gVehData[vehicleID-1][BusinessID] = vehBizID;
		format(string,sizeof(string), "[INFO:] Business ID vehicle ID: %d change to: %d", vehicleID, vehBizID);
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);

		SaveVehData(vehicleID-1, "BusinessID");
	}
	else
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] You're not in a vehicle");
	return 1;
}

dcmd_abusinessmaxcars(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] < 4)
		return 0;
	new maxVehicles;
	new businessID;
	new string[128];
	if(sscanf(params, "dd", businessID, maxVehicles))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /abusinessmaxcars [biz ID] [max vehicles]");
		return 1;
	}
	Businesses[businessID][MaxVehicles] = maxVehicles;
	SaveBizData(businessID, "MaxVehicles");

	format(string, sizeof(string), "[INFO:] Business id: %d, Max Vehicles set to: %d", businessID, maxVehicles);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	return 1;
}

dcmd_acarint(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] < 4)
		return 0;
	new interiorID;
	new vehicleID;
	new string[128];
	if(sscanf(params, "dd", vehicleID, interiorID))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /acarint [veh ID] [int ID]");
		return 1;
	}
	LinkVehicleToInterior(vehicleID, interiorID);
	format(string, sizeof(string), "[INFO:] Do³¹czy³eœ pojazd o ID: %d, do interioru o ID: %d", vehicleID, interiorID);
	SendClientMessage(playerid, COLOR_GREEN, string);
	return 1;
}

dcmd_acarrepairtl(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] < 4)
		return 0;
	new vehRTL;
	new vehicleID;
	new string[128];
	if(sscanf(params, "d", vehRTL))
	{
		SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] /acarrepairtl [time left]");
		return 1;
	}
	if(IsPlayerInAnyVehicle(playerid))
	{
		vehicleID = GetPlayerVehicleID(playerid);
		gVehData[vehicleID-1][CarRepairTimeLeft] = vehRTL;
		format(string,sizeof(string), "[INFO:] Repair Time Left for vehicle ID: %d change to: %d", vehicleID, vehRTL);
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);

		SaveVehData(vehicleID-1, "CarRepairTimeLeft");
	}
	else
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] You're not in a vehicle");
		return 1;
	}
	return 1;
}

dcmd_acarresett(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new vehRT;
	new vehicleID;
	new string[128];
	if(sscanf(params, "d", vehRT))
	{
		SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] /acarresett [time left]");
		return 1;
	}
	if(IsPlayerInAnyVehicle(playerid))
	{
		vehicleID = GetPlayerVehicleID(playerid);
		gVehData[vehicleID-1][CarResetT] = vehRT;
		format(string,sizeof(string), "[INFO:] Reset Time for vehicle ID: %d change to: %d", vehicleID, vehRT);
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
		SaveVehData(vehicleID-1, "CarResetT");
	}
	else
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] You're not in a vehicle");
	return 1;
}

dcmd_acarclosed(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] < 4)
		return 0;
	new vehClosed;
	new vehicleID;
	new string[128];
	if(sscanf(params, "d", vehClosed))
	{
		SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] /acarclosed [closed 0/1]");
		return 1;
	}
	if(IsPlayerInAnyVehicle(playerid))
	{
		vehicleID = GetPlayerVehicleID(playerid);

		new enginedyn,lights,alarm,doors,bonnet,boot,objective;
		GetVehicleParamsEx(vehicleID,enginedyn,lights,alarm,doors,bonnet,boot,objective);
        SetVehicleParamsEx(vehicleID,enginedyn,lights,alarm,vehClosed,bonnet,boot,objective);

		gVehData[vehicleID-1][Closed] = vehClosed;

		SaveVehData(vehicleID-1, "Closed");

		format(string,sizeof(string), "[INFO:] Vehicle ID: %d lock status changed to: %d", vehicleID, vehClosed);
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	}
	else
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] You're not in a vehicle");
	return 1;
}

dcmd_abizconfiscated(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] <= 4)
		return 0;
	new bizID;
	new bizConfiscated;
	if(sscanf(params, "dd", bizID, bizConfiscated))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /abizconfiscated [biz ID] [confiscated 0/1]");
		return 1;
	}
	Businesses[bizID][BConfiscated] = bizConfiscated;
	SaveBizData(bizID, "Confiscated");
	new string[128];
	format(string, sizeof(string), "[INFO:] Business ID: %d confiscated status changed to: %d", bizID, bizConfiscated);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	return 1;
}

dcmd_ahouseconfiscated(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] <= 4)
		return 0;
	new hID;
	new hConfiscated;
	if(sscanf(params, "dd", hID, hConfiscated))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /ahouseconfiscated [biz ID] [confiscated 0/1]");
		return 1;
	}
	Houses[hID][HConfiscated] = hConfiscated;
	SaveHouseData(hID, "Confiscated");
	new string[128];
	format(string, sizeof(string), "[INFO:] House ID: %d confiscated status changed to: %d", hID, hConfiscated);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	return 1;
}

dcmd_abizlock(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] <= 4)
		return 0;
	new bizID;
	new bizLock;
	if(sscanf(params, "dd", bizID, bizLock))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /abizlock [biz ID] [lock 0/1]");
		return 1;
	}
	Businesses[bizID][Locked] = bizLock;
	SaveBizData(bizID, "Locked");
	new string[128];
	format(string, sizeof(string), "[INFO:] Business ID: %d lock status changed to: %d", bizID, bizLock);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	return 1;
}

dcmd_ahouselock(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] <= 4)
		return 0;
	new houseId;
	new houseLock;
	if(sscanf(params, "dd", houseId, houseLock))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /ahouselock [house Id] [lock 0/1]");
		return 1;
	}
	Houses[houseId][Locked] = houseLock;
	SaveHouseData(houseId, "Locked");
	new string[128];
	format(string, sizeof(string), "[INFO:] House ID: %d lock status changed to: %d", houseId, houseLock);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	return 1;
}

dcmd_abizvehorders(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] < 4)
		return 0;
	new bizID;
	new bizOrders;
	new string[128];
	if(sscanf(params, "dd", bizID, bizOrders))
	{
		SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] /abizvehorders [biz ID] [biz orders count]");
		return 1;
	}
	Businesses[bizID][VehicleOrderCount] = bizOrders;
	SaveBizData(bizID, "VehicleOrderCount");
	format(string, sizeof(string), "[INFO:] Business ID: %d orders count changed to: %d", bizID, bizOrders);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	return 1;
}

dcmd_abizvehcount(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] < 4)
		return 0;
	new bizID;
	new bizVehCount;
	new string[128];
	if(sscanf(params, "dd", bizID, bizVehCount))
	{
		SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] /abizvehcount [biz ID] [biz veh count]");
		return 1;
	}
	Businesses[bizID][VehicleCount] = bizVehCount;
	SaveBizData(bizID, "VehicleCount");
	format(string, sizeof(string), "[INFO:] Business ID: %d vehicles count changed to: %d", bizID, bizVehCount);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	return 1;
}

dcmd_abizvehspawned(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] < 4)
		return 0;
	new bizID;
	new bizVehSpawned;
	new string[128];
	if(sscanf(params, "dd", bizID, bizVehSpawned))
	{
		SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] /abizvehcount [biz ID] [biz veh spawned]");
		return 1;
	}
	Businesses[bizID][VehicleSpawned] = bizVehSpawned;
	format(string, sizeof(string), "[INFO:] Business ID: %d vehicle spawned to: %d", bizID, bizVehSpawned);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	return 1;
}

dcmd_sprawdzoc(playerid, params[])
{
	new givePlayerID;
	new slot;
	new string[128];
	if(gPlayerData[playerid][pFaction] == 255 && gPlayerData[playerid][pAdmin] <= 0)
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Niew³aœciwa frakcja !");
		return 1;
	}
	if(DynamicFactions[gPlayerData[playerid][pFaction]][fType] != 1)
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Niew³aœciwa frakcja !");
		return 1;
	}
	if(sscanf(params, "dd", givePlayerID, slot))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /sprawdzoce [id gracza] [slot]");
		return 1;
	}
	if(PSlotItemTypeCompare(playerid, slot, 2) == 0)
	{
		format(string, sizeof(string), "[INFO:] Na tym slocie gracz nie posiada kluczyków do ¿adnego pojazdu !");
	}
	else
	{
		if(SlotParam3(playerid, slot) > 0)
		{
			format(string, sizeof(string), "[INFO:] Ubezpieczenie OC / kwota OC: %d", SlotParam1(playerid, slot));
		}
		else
		{
			format(string, sizeof(string), "[INFO:] Ta osoba nie posiada ubezpieczenia OC na ten pojazd !");
		}
	}
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	return 1;
}

dcmd_sprzedajpojazd(playerid, params[])
{
	new vehicleID = GetPlayerVehicleID(playerid);
	new tmpVehicleID = vehicleID - 1;
	new carPrice;
	new string[128];
	if(sscanf(params, "d", carPrice))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /sprzedajpojaz [cena]");
		return 1;
	}
	if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
	{
		if(gVehData[tmpVehicleID][CarSerial] == 0)
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Pojazd nie posiada tablic rejestracyjnych, nie mo¿esz go sprzedaæ");
			return 1;
		}
		if( gVehData[tmpVehicleID][mVehOwned] == 1 && strcmp(gPlayerData[playerid][pName], gVehData[tmpVehicleID][Owner], true) == 0)
		{
			if(gVehData[tmpVehicleID][ReadyToSell] == 1)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW, "[INFO:] Ten pojazd jest ju¿ wystawiony na sprzeda¿ !");
				return 1;
			}
			
			new Float:x, Float:y, Float:z;
			GetPlayerPos(playerid, x, y, z);
			
			gVehData[tmpVehicleID][Price] = carPrice;
			gVehData[tmpVehicleID][ReadyToSell] = 1;

			SaveVehData(tmpVehicleID, "Price");
			SaveVehData(tmpVehicleID, "ReadyToSell");

			RefreshVehicleDescription(tmpVehicleID+1);
			
			format(string, sizeof(string), "[INFO:] Wystawi³eœ swój pojazd na sprzeda¿ za $%d", carPrice);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Mo¿esz kontunuowaæ jazde swoim samochodem.");
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "Zainteresowany aby kupiæ pojazd musi do niego wsi¹œæ i wpisaæ komende /kuppojazd");
		}
		else
			SendClientMessage(playerid, COLOR_RED, "[INFO:] To nie jest Twój pojazd, nie mo¿esz go sprzedaæ");
	}
	else
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w pojeŸdzie !");
	return 1;
}

dcmd_anulujsprzedazpojazdu(playerid, params[])
{
	#pragma unused params
	new vehicleID = GetPlayerVehicleID(playerid);
	new tmpVehicleID = vehicleID - 1;
	new string[128];
	
	if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
	{
		if(gVehData[tmpVehicleID][mVehOwned] == 1 && strcmp(gPlayerData[playerid][pName], gVehData[tmpVehicleID][Owner], false) == 0)
		{
			gVehData[tmpVehicleID][ReadyToSell] = 0;
			SaveVehData(tmpVehicleID, "ReadyToSell");

			RefreshVehicleDescription(vehicleID);
			
			format(string, sizeof(string), "[INFO:] Anulowa³eœ sprzeda¿ swojego pojazdu !");
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
		}
		else
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] To nie jest twój pojazd !");
		}
	}
	else
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Musisz byc w pojeŸdzie");
	}
	
	return 1;
}

dcmd_sprzedajpojazdf(playerid, params[])
{
	new vehicleID = GetPlayerVehicleID(playerid);
	new tmpVehicleID = vehicleID - 1;
	new carPrice;
	new string[128];
	new Float:x, Float:y, Float:z;

	if(gPlayerData[playerid][pFaction] != gVehData[tmpVehicleID][mVehFaction])
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten pojazd nie nale¿y do frakcji !");
		return 1;
	}
	
	if(!CheckRankPrivilidges(gPlayerData[playerid][pFaction], gPlayerData[playerid][pRank], "sprzedajpojazdf"))
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie posiadasz uprawnieñ do sprzedawania pojazdów frakcyjnych !");
		return 1;
	}
	
	if(sscanf(params, "d", carPrice))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /sprzedajpojazdf [cena]");
		return 1;
	}
	
	if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
	{
		if(gVehData[tmpVehicleID][ReadyToSell] == 1)
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW, "[INFO:] Ten pojazd jest ju¿ wystawiony na sprzeda¿ !");
			return 1;
		}
		
		GetVehiclePos(vehicleID, x, y, z);
		gVehData[tmpVehicleID][Price] = carPrice;
		gVehData[tmpVehicleID][ReadyToSell] = 1;

		SaveVehData(tmpVehicleID, "Price");
		SaveVehData(tmpVehicleID, "ReadyToSell");

		RefreshVehicleDescription(vehicleID);
		
		format(string, sizeof(string), "[INFO:] Wystawi³eœ frakcyjny pojazd na sprzeda¿ za $%d", carPrice);
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
		
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Mo¿esz kontunuowaæ jazde tym samochodem.");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Zainteresowany aby kupiæ pojazd musi do niego wsi¹œæ i wpisaæ komende /kuppojazd");
	}
	return 1;
}

dcmd_anulujsprzedazpojazduf(playerid, params[])
{
	#pragma unused params
	new vehicleID = GetPlayerVehicleID(playerid);
	new tmpVehicleID = vehicleID - 1;
	new string[128];
	if(gPlayerData[playerid][pFaction] == 255)
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie nale¿ysz do ¿adnej frakcji !");
		return 1;
	}
	if(gPlayerData[playerid][pRank] != 1)
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ liderem frakcji !");
		return 1;
	}
	if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
	{
		if(gVehData[tmpVehicleID][mVehFaction] != gPlayerData[playerid][pFaction])
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten pojazd nie nale¿y do Twojej frakcji !");
			return 1;
		}
		if(gVehData[tmpVehicleID][ReadyToSell] == 0)
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten pojazd nie jest wystawiony na sprzeda¿ !");
			return 1;
		}
		else
		{
			gVehData[tmpVehicleID][ReadyToSell] = 0;

			SaveVehData(tmpVehicleID, "ReadyToSell");

			RefreshVehicleDescription(tmpVehicleID+1);
			
			format(string, sizeof(string), "[INFO:] Anulowa³eœ sprzeda¿ frakcyjnego pojazdu !");
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
		}
	}
	return 1;
}

dcmd_ulecz(playerid, params[])
{
	if(gPlayerData[playerid][pFaction] == FACTIONID_MEDICS || AdminDuty[playerid])
	{
		new targetID, string[128];
		new Float:targetX, Float:targetY, Float:targetZ;
		if(sscanf(params, "d", targetID))
		{
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] /ulecz [id gracza]");
			return 1;
		}
		if(targetID != playerid || gPlayerData[playerid][pAdmin] > 0)
		{
			if(gPlayerData[playerid][pCharacterDying] == 0)
			{
				if(gPlayerData[targetID][pCharacterDying] > 1)
				{
					SendClientMessage(targetID, COLOR_GREEN, "[INFO:] Ta osoba jest nieprzytomna ! Musisz j¹ najpierw reanimowaæ !");
					return 1;
				}
				else
				{
					GetPlayerPos(targetID, targetX, targetY, targetZ);
					if(PlayerToPoint(5.0, playerid, targetX, targetY, targetZ) || AdminDuty[playerid])
					{
						gPlayerVars[targetID][mHealID] = playerid;
						format(string, sizeof(string), "Czy zgadzasz siê ponieœæ op³ate za uleczenie w wysokoœci $%d ?",
							DynamicFactions[FACTIONID_MEDICS][fHealPrice]);
						ShowPlayerDialog(targetID, DIALOG_HEAL_ASK, DIALOG_STYLE_MSGBOX, "Leczenie", string, "Tak", "Nie");						
						return 1;
					}
					else
					{
						SendClientMessage(playerid, COLOR_RED, "[INFO:] Ta osoba jest zbyt daleko by opatrzeæ jej rany");
						return 1;
					}
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_RED, "[INFO:] Twoja postaæ jest nieprzytomna, nie mo¿e nikogo uleczyæ !");
				return 1;
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie mo¿esz sam siebie uleczyæ !");
			return 1;
		}
	}
	else
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie jesteœ ratownikiem !");
		return 1;
	}
}

dcmd_pozszywaj(playerid, params[])
{
	new targetID;
	if(gPlayerData[playerid][pFaction] == 2 && gPlayerData[playerid][pRank] <= 6  || gPlayerData[playerid][pAdmin] > 0)
	{
		if(IsPlayerConnected(targetID))
		{
			if(sscanf(params, "d", targetID))
			{
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] /pozszywaj [id gracza]");
				return 1;
			}
			if(targetID != playerid)
			{
				if(PlayerToPoint(5.0, playerid, -2636.6081, 670.9566, 11.3357) ||PlayerToPoint(5.0, playerid, 1205.0, -899.0, 1094.0))
				{
					if(PlayerToPoint(5.0, targetID, -2636.6081, 670.9566, 11.3357) || PlayerToPoint(5.0, targetID, 1205.0, -899.0, 1094.0))
					{
						PlayerPlayerActionMessage(playerid, targetID, 20.0, "zaczyna zszywanie rany");
						SetPlayerHealth(targetID, 100.0);
						SendClientMessage(targetID, COLOR_GREEN, "[INFO:] Zosta³eœ poskladany !");
						gPlayerData[targetID][pHead] = 0 ;
						gPlayerData[targetID][pTorso] = 0 ;
						gPlayerData[targetID][pLegs] = 0 ;

						SavePlayerData(targetID, "Head");
						SavePlayerData(targetID, "Torso");
						SavePlayerData(targetID, "Legs");
					}
					else
					{
						SendClientMessage(playerid, COLOR_RED, "[INFO:] Pacjent jest zbyt daleko od sali operacyjnej !");
						return 1;
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_RED, "[INFO:] Jest zbyt daleko od sali operacyjnej !");
					return 1;
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie mo¿esz sam siebie uleczyæ !");
				return 1;
			}
		}
	}
	else
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie jesteœ ratownikiem !");
		return 1;
	}
	return 1;
}

dcmd_detoksykacja(playerid, params[])
{
	new targetID, isNearChamber;
	if(gPlayerData[playerid][pFaction] != FACTIONID_MEDICS && !AdminDuty[playerid])
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie jesteœ ratownikiem !");
		return 1;
	}
	if(!IsPlayerConnected(targetID) || !gPlayerLogged[targetID]) 
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ten gracz nie jest po³¹czony");
		return 1;
	}
	if(sscanf(params, "d", targetID))
	{
		SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] /detoksykacja [id gracza]");
		return 1;
	}
	if(targetID == playerid && !AdminDuty[playerid])
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie mo¿esz sam siebie uleczyæ !");
		return 1;
	}
	for(new i = 0; i < sizeof(gAdmissionChambers); i++)
	{			
		if(PlayerToPoint(10.0, playerid, gAdmissionChambers[i][mPosX], gAdmissionChambers[i][mPosY], gAdmissionChambers[i][mPosZ]) && 
			GetPlayerVirtualWorld(playerid) == gAdmissionChambers[i][mWorld] && GetPlayerInterior(playerid) == gAdmissionChambers[i][mInt])
		{
			isNearChamber = 1;
		}
	}
	if(!isNearChamber && !AdminDuty[playerid])
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Jesteœ zbyt daleko od sali operacyjnej !");
		return 1;
	}			
	if(GetDistanceBetweenPlayers(playerid, targetID) > 2.0 && !AdminDuty[playerid])
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Jesteœ zbyt daleko od pacjenta");
		return 1;
	}
	if(gPlayerData[targetID][pDrugsAddicted] == 0)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ten pacjent nie potrzebuje detoksykacji !");
		return 1;
	}
	if(gPlayerData[targetID][pDetoks] < 10)
	{			
		PlayerPlayerActionMessage(playerid, targetID, 20.0, "zaczyna detoksyzacje");
		SetPlayerHealth(targetID, 100.0);
		SendClientMessage(targetID, COLOR_GREEN, "[INFO:] Otrzyma³eœ niewielk¹ dawke detoxu !");
		gPlayerData[targetID][pDetoks] ++ ;
		SetPlayerDrunkLevelEx(targetID, 2000);

		SavePlayerData(targetID, "Detoks");
	}
	else
	{
		PlayerPlayerActionMessage(playerid, targetID, 20.0, "zaczyna detoksyzacje");
		SetPlayerHealth(targetID, 100.0);
		SendClientMessage(targetID, COLOR_GREEN, "[INFO:] Zosta³eœ wyleczony z uzaleznienia !");
		gPlayerData[targetID][pDrugsAddicted] = 0 ;
		gPlayerData[targetID][pDetoks] = 0 ;
		SetPlayerDrunkLevelEx(targetID, 2000);

		SavePlayerData(targetID, "DrugsAddicted");
		SavePlayerData(targetID, "Detoks");			
	}
	return 1;
}

dcmd_statusfrakcji(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pFaction] == 255)
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie nale¿ysz do ¿adnej frakcji !");
		return 1;
	}
	if(!CheckRankPrivilidges(gPlayerData[playerid][pFaction], gPlayerData[playerid][pRank], "statusfrakcji"))
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie posiadasz uprawnieñ do sprawdzenie statusu frakcji !");
		return 1;
	}
	new factionID = gPlayerData[playerid][pFaction];
	if(!PlayerToPoint(20.0, playerid, DynamicFactions[factionID][fXDuty],DynamicFactions[factionID][fYDuty],DynamicFactions[factionID][fZDuty]))
	{
		if(DynamicFactions[factionID][fType] == 1)
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Musisz znajdowaæ siê w pobli¿u punktu przyjmowania s³u¿by !");
		}
		if(DynamicFactions[factionID][fType] == 3)
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Musisz znajdowaæ siê w pobli¿u sk³adu broni !");
		}
		else
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Musisz znajdowaæ siê w pobli¿u przebieralni !");
		}
		return 1;
	}
	new string[128];

	format(string, sizeof(string), "[FRAKCJA:] Nazwa: %s, iloœæ rang: %d, kasa: %d", DynamicFactions[factionID][Name], DynamicFactions[factionID][fRankAmount], DynamicFactions[factionID][fBank]);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	format(string, sizeof(string), "[FRAKCJA:] Iloœæ pojazdów: %d, maksymalna iloœæ pojazdów: %d", DynamicFactions[factionID][fCarsCount], DynamicFactions[factionID][fMaxCars]);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	return 1;
}

dcmd_abiztill(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] < 4)
		return 0;
	new businessID;
	new cash;
	new string[128];
	if(sscanf(params, "dd", businessID, cash))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /abiztill [businessID] [cash]");
		return 1;
	}
	Businesses[businessID][Till] = cash;
	SaveBizData(businessID, "Till");
	format(string, sizeof(string), "[INFO:] Ustawi³eœ iloœæ pieniedzy w biznesie na $%d", Businesses[businessID][Till]);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	return 1;
}

dcmd_abizentrancefee(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] < 4)
		return 0;
	new businessID;
	new cash;
	new string[128];
	if(sscanf(params, "dd", businessID, cash))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /abizentrancefee [businessID] [cash]");
		return 1;
	}
	Businesses[businessID][EntranceCost] = cash;
	SaveBizData(businessID, "EntranceCost");
	format(string, sizeof(string), "[INFO:] Ustawi³eœ wejœciówke na $%d", Businesses[businessID][Till]);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	return 1;
}

dcmd_abizaddtill(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] < 4)
		return 0;
	new businessID;
	new cash;
	new string[128];
	if(sscanf(params, "dd", businessID, cash))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /abizaddtill [businessID] [cash]");
		return 1;
	}
	Businesses[businessID][Till] += cash;
	SaveBizData(businessID, "Till");
	format(string, sizeof(string), "[INFO:] Ustawi³eœ iloœæ pieniedzy w kasie frakcji na $%d", Businesses[businessID][Till]);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	return 1;
}

dcmd_afactionmaxvehicles(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] < 4)
		return 0;
	new factionID;
	new maxVehicles;
	new string[128];
	if(sscanf(params, "dd", factionID, maxVehicles))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /afactionmaxvehicles [factionID] [maxVehicles]");
		return 1;
	}
	DynamicFactions[factionID][fMaxCars] = maxVehicles;
	format(string, sizeof(string), "[INFO:] Faction %s [%d] fMaxCars set to: %d", DynamicFactions[factionID][Name], factionID, maxVehicles);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	return 1;
}

dcmd_afactionvehiclescount(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] < 4)
		return 0;
	new factionID;
	new vehiclesCount;
	new string[128];
	if(sscanf(params, "dd", factionID, vehiclesCount))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /afactionvehiclescount [factionID] [vehiclesCount]");
		return 1;
	}
	DynamicFactions[factionID][fCarsCount] = vehiclesCount;
	format(string, sizeof(string), "[INFO:] Faction %s [%d] fCarsCount set to: %d", DynamicFactions[factionID][Name], factionID, vehiclesCount);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	return 1;
}

dcmd_statusvip(playerid, params[])
{
	#pragma unused params
	new vipExp, vipExpT, vipAFK, vipAFKT, vipItem;

	vipExp = gPlayerData[playerid][pVipExp];
	vipExpT = gPlayerData[playerid][pVipExpT];
	vipAFK = gPlayerData[playerid][pVipAFK];
	vipAFKT = gPlayerData[playerid][pVipAFKT];
	vipItem = gPlayerData[playerid][pVipItem];

	if(vipItem != 0)
	{
		SendClientMessage(playerid, COLOR_WHITE, "[INFO:] VIP Item aktywny");
	}
	if(vipItem == 0)
	{
		SendClientMessage(playerid, COLOR_WHITE, "[INFO:] VIP Item nieaktywny");
	}
	if(vipExpT !=  0 && vipAFKT != 0)
	{
		SendClientMessage(playerid, COLOR_WHITE, "[INFO:] VIP AFK oraz VIP EXP aktywny");
	}
	if(vipExpT == 0 && vipAFKT == 0)
	{
		SendClientMessage(playerid, COLOR_WHITE, "[INFO:] VIP AFK oraz VIP EXP nieaktywny");
	}
	if(vipAFK == 1)
	{
		SendClientMessage(playerid, COLOR_WHITE, "[INFO:] VIP AFK aktywny (bez limitu czasowego)");
	}
	if(vipExp == 1)
	{
		SendClientMessage(playerid, COLOR_WHITE, "[INFO:] VIP EXP aktywny (bez limitu czasowego)");
	}
	return 1;
}

dcmd_uzyjnarkotykow(playerid, params[])
{
	if(gPlayerData[playerid][pCharacterDying] > 0)
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Twoja postaæ jest nieprzytomna ! Nie mo¿esz u¿yæ narkotyków !");
		return 1;
	}
	if(gPlayerData[playerid][pDrugs] > 0)
	{
		new grams;
		if(sscanf(params, "d", grams))
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] /uzyjnarkotykow [gram]");
			return 1;
		}
		if(grams < 0)
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Wartoœæ nie mo¿e byæ ujemna !");
			return 1;
		}
		if(gPlayerData[playerid][pDrugs] < grams)
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie posiadasz tyle gram narkotyków !");
			return 1;
		}
		new Float:armour;
		new Float:hp;
		new string[128];
		GetPlayerArmour(playerid, armour);
		GetPlayerHealth(playerid, hp);
		if(pDrugsUsedStartHP[playerid] == 0.0)
		{
			pDrugsUsedStartHP[playerid] = hp;
		}
		if(pDrugsUsedStartArmour[playerid] == 0.0)
		{
			pDrugsUsedStartArmour[playerid] = armour;
		}
		if(armour < 150.0)
		{
			SetPlayerArmourEx(playerid, armour + 2.0);
		}
		if(hp < 150.0)
		{
			SetPlayerHealth(playerid, hp + 5.0);
		}
		format(string, sizeof(string), "[INFO:] U¿yto %d gram narkotyków", grams);
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
		gPlayerData[playerid][pDrugs] -= grams;
		gPlayerData[playerid][pDrugsTaken] += grams;
		gPlayerData[playerid][pDrugsEffect] = 1;

		ApplyAnimation(playerid,"JST_BUISNESS","smoke_01",1.0, 0, 1, 1, 0, 0);

		SavePlayerData(playerid, "Drugs");
		SavePlayerData(playerid, "DrugsTaken");
		SavePlayerData(playerid, "DrugsEffect");

		LastDrug[playerid] = 4;
		if(gPlayerData[playerid][pDrugsTaken] >= 4 && gPlayerData[playerid][pDrugsTaken] < 8)
			DrugEffect(playerid);
		if(gPlayerData[playerid][pDrugsTaken] >= 8)
			DrugEffectHard(playerid);
	}
	else
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie posiadasz ¿adnych narkotyków.");
	}
	return 1;
}

dcmd_stanstacji(playerid, params[])
{
	#pragma unused params
	new string[128];
	for(new i = 0; i < sizeof(GasStations); i++)
	{
		if(PlayerToPoint(10.0, playerid, GasStations[i][GSposX], GasStations[i][GSposY], GasStations[i][GSposZ]))
		{
			if(gPlayerData[playerid][pFaction] == 11 || strcmp(gPlayerData[playerid][pName], Businesses[GasStations[i][BusinessID]][Owner]) == 0 || AdminDuty[playerid])
			{
				format(string, sizeof(string), "[INFO:] Zasoby: %f litrów benzyny, zapotrzebowanie: %.1f litrów", GasStations[i][PetrolResourceValue], GasStations[i][MaxPetrolResourceValue] - GasStations[i][PetrolResourceValue]);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
				format(string, sizeof(string), "[INFO:] Zasoby: %f litrów ropy, zapotrzebowanie: %.1f litrów", GasStations[i][OilResourceValue], GasStations[i][MaxOilResourceValue] - GasStations[i][OilResourceValue]);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
				format(string, sizeof(string), "[INFO:] Zasoby: %f litrów gazu, zapotrzebowanie: %.1f litrów", GasStations[i][GasResourceValue], GasStations[i][MaxGasResourceValue] - GasStations[i][GasResourceValue]);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
				return 1;
			}
			else
			{
				SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie jesteœ pracownikiem rafinerii lub nie jesteœ w³aœcicielem tej stacji !");
				return 1;
			}
		}
	}
	SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie znajdujesz siê na ¿adnej stacji lub musisz podejœæ bli¿ej");
	return 1;
}

dcmd_napelnijzbiorniki(playerid, params[])
{
	#pragma unused params
	
	if(gPlayerData[playerid][pFaction] != 11)
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie jesteœ pracownikiem rafinerii !");
		return 1;
	}
	
	new vehID = GetPlayerVehicleID(playerid);
	
	/* Player has no truck */
	if( vehID == INVALID_VEHICLE_ID )
	{
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_INFO_HEADER, RAF_GS_INV_VEHID, DIALOG_INFO_EXIT, "");
		return 1;
	}
	
	new tlID = GetVehicleTrailer(vehID);
	
	/* Truck has no tanker */
	if( tlID == INVALID_VEHICLE_ID )
	{
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_INFO_HEADER, RAF_GS_INV_TLID, DIALOG_INFO_EXIT, "");
		return 1;
	}
	
	/* Tanker already refueling */
	if(gVehData[tlID-1][TankerIsRefueling])
	{
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_INFO_HEADER, RAF_GS_AREFUELING, DIALOG_INFO_EXIT, "");
		return 1;
	}
	
	/* Tanker has no fuel defined type */
	if( gVehData[tlID-1][TankerResourceType] == TANKER_TYPE_NONE )
	{
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_INFO_HEADER, RAF_GS_NO_TYPE, DIALOG_INFO_EXIT, "");
		return 1;
	}
	
	/* Tanker has no fuel defined type */
	if( gVehData[tlID-1][TankerResourceType] == TANKER_TYPE_FLY )
	{
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_INFO_HEADER, "Paliwo lotnicze nie mo¿e byæ zatankowane na stacji paliwowej.", DIALOG_INFO_EXIT, "");
		return 1;
	}
	
	/* Tanker is empty */
	if( gVehData[tlID-1][TankerResourceValue] <= 0 )
	{
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_INFO_HEADER, RAF_GS_REFUELED_C, DIALOG_INFO_EXIT, "");
		return 1;
	}
	
	for(new i = 0; i < sizeof(GasStations); i++)
	{
		if(PlayerToPoint(10.0, playerid, GasStations[i][GSposX], GasStations[i][GSposY], GasStations[i][GSposZ]))
		{
			switch(gVehData[tlID-1][TankerResourceType])
			{
				case TANKER_TYPE_PETROL:
				{
					if(!GasStations[i][RefuelPetrolResources])
					{
						ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_INFO_HEADER, RAF_GS_NO_REFUEL, DIALOG_INFO_EXIT, "");
						return 1;
					}
					
					/* No till to refuel*/
					if(Businesses[GasStations[i][BusinessID]][Till] < gRafinery[RafPetrolLtrCost])
					{
						ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_INFO_HEADER, RAF_GS_NO_TILL, DIALOG_INFO_EXIT, "");
						return 1;
					}
					
					if(GasStations[i][PetrolResourceValue] >= GasStations[i][MaxPetrolResourceValue])
					{
						ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_INFO_HEADER, RAF_GS_FULL_PETROL, DIALOG_INFO_EXIT, "");
						return 1;
					}
					
					gVehData[tlID-1][TankerIsRefueling] = 1;
					
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Rozpoczêto nape³nianie zbiorników stacji");
					
					defer RefuelingStation(playerid, i);
					return 1;
				}
				case TANKER_TYPE_OIL:
				{
					if(!GasStations[i][RefuelOilResources])
					{
						ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_INFO_HEADER, RAF_GS_NO_REFUEL, DIALOG_INFO_EXIT, "");
						return 1;
					}
					
					/* No till to refuel*/
					if(Businesses[GasStations[i][BusinessID]][Till] < gRafinery[RafOilLtrCost])
					{
						ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_INFO_HEADER, RAF_GS_NO_TILL, DIALOG_INFO_EXIT, "");
						return 1;
					}
					
					if(GasStations[i][OilResourceValue] >= GasStations[i][MaxOilResourceValue])
					{
						ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_INFO_HEADER, RAF_GS_FULL_OIL, DIALOG_INFO_EXIT, "");
						return 1;
					}
					
					gVehData[tlID-1][TankerIsRefueling] = 1;
					
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Rozpoczêto nape³nianie zbiorników stacji");
					
					defer RefuelingStation(playerid, i);
					return 1;
				}
				case TANKER_TYPE_GAS:
				{
					if(!GasStations[i][RefuelGasResources])
					{
						ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_INFO_HEADER, RAF_GS_NO_REFUEL, DIALOG_INFO_EXIT, "");
						return 1;
					}
					
					/* No till to refuel*/
					if(Businesses[GasStations[i][BusinessID]][Till] < gRafinery[RafGasLtrCost])
					{
						ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_INFO_HEADER, RAF_GS_NO_TILL, DIALOG_INFO_EXIT, "");
						return 1;
					}
					
					if(GasStations[i][GasResourceValue] >= GasStations[i][MaxGasResourceValue])
					{
						ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_INFO_HEADER, RAF_GS_FULL_GAS, DIALOG_INFO_EXIT, "");
						return 1;
					}
					
					gVehData[tlID-1][TankerIsRefueling] = 1;
					
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Rozpoczêto nape³nianie zbiorników stacji");
					
					defer RefuelingStation(playerid, i);
					return 1;
				}
			}
		}
	}
	SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie znajdujesz siê na ¿adnej stacji benzynowej !");
	return 1;
}

dcmd_komendyrafinerii(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pFaction] == 11)
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /odczepnaczepe - /stanstacji - /napelnijzbiorniki - /zatankujlotnicze - /cenypaliw");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /cenazalitrbenzyny - /cenazalitrropy - /cenazalitrgazu - /cenazalitrlotniczego - /wynagrodzenie");
		return 1;
	}
	else
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie jesteœ pracownikiem rafinerii !");
		return 1;
	}
}

dcmd_cenypaliw(playerid, params[])
{
	#pragma unused params
	new string[128];
	if(gPlayerData[playerid][pFaction] != FACTIONID_SANNEWS && gPlayerData[playerid][pFaction] != FACTIONID_RAFINERY)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie nale¿ysz do frakcji: RAFINERIA ani SAN NEWS");
		return 1;
	}
	format(string, sizeof(string), "Aktualne ceny paliw\n\nBENZYNA: $%d\n\nDIESEL: $%d\n\nGAS: $%d\n\nLOTNICZE: $%d",
		gRafinery[RafPetrolLtrCost],
		gRafinery[RafOilLtrCost],
		gRafinery[RafGasLtrCost],
		gRafinery[RafFlyLtrCost]
	);
	ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", string, "Zamknij", "");
	return 1;
}

dcmd_cenazalitrbenzyny(playerid, params[])
{
	if(gPlayerData[playerid][pFaction] == FACTIONID_RAFINERY || gPlayerData[playerid][pFaction] == 9)
	{
		if(gPlayerData[playerid][pRank] == 1)
		{
			new cost;

			if(sscanf(params, "d", cost))
			{
				SendClientMessage(playerid, COLOR_RED, "[INFO:] /cenazalitrbenzyny [kwota]");
				return 1;
			}
			if(cost <= 0)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Kwota musi byæ wiêksza od 0 !");
				return 1;
			}
			gRafinery[RafPetrolLtrCost] = cost;

			new string[128];
			format(string, sizeof(string), "[INFO:] Ustali³eœ now¹ cene za litr paliwa (beznyna): $%d", cost);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			printf("[WARNING:] Fuel price set to: $%d by %s", cost, gPlayerData[playerid][pName]);
			SaveRafinery();
			return 1;
		}
		else
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie jesteœ prezesem rafinerii !");
			return 1;
		}
	}
	if(gPlayerData[playerid][pFaction] != 11 && gPlayerData[playerid][pFaction] != 9)
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie jesteœ pracownikiem rafinerii !");
		return 1;
	}
	return 1;
}

dcmd_cenazalitrropy(playerid, params[])
{
	if(gPlayerData[playerid][pFaction] == 11 || gPlayerData[playerid][pFaction] == 9)
	{
		if(gPlayerData[playerid][pRank] == 1)
		{
			new cost;

			if(sscanf(params, "d", cost))
			{
				SendClientMessage(playerid, COLOR_RED, "[INFO:] /cenazalitrropy [kwota]");
				return 1;
			}
			if(cost <= 0)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Kwota musi byæ wiêksza od 0 !");
				return 1;
			}
			gRafinery[RafOilLtrCost] = cost;

			new string[128];
			format(string, sizeof(string), "[INFO:] Ustali³eœ now¹ cene za litr paliwa (diesel): $%d", cost);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			printf("[WARNING:] Fuel (diesel) price set to: $%d by %s", cost, gPlayerData[playerid][pName]);
			SaveRafinery();
			return 1;
		}
		else
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie jesteœ prezesem rafinerii !");
			return 1;
		}
	}
	if(gPlayerData[playerid][pFaction] != 11 && gPlayerData[playerid][pFaction] != 9)
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie jesteœ pracownikiem rafinerii !");
		return 1;
	}
	return 1;
}

dcmd_cenazalitrgazu(playerid, params[])
{
	if(gPlayerData[playerid][pFaction] == 11 || gPlayerData[playerid][pFaction] == 9)
	{
		if(gPlayerData[playerid][pRank] == 1)
		{
			new cost;

			if(sscanf(params, "d", cost))
			{
				SendClientMessage(playerid, COLOR_RED, "[INFO:] /cenazalitrgazu [kwota]");
				return 1;
			}
			if(cost <= 0)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Kwota musi byæ wiêksza od 0 !");
				return 1;
			}
			gRafinery[RafGasLtrCost] = cost;

			new string[128];
			format(string, sizeof(string), "[INFO:] Ustali³eœ now¹ cene za litr paliwa (gaz): $%d", cost);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			printf("[WARNING:] Fuel (gas) price set to: $%d by %s", cost, gPlayerData[playerid][pName]);
			SaveRafinery();
			return 1;
		}
		else
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie jesteœ prezesem rafinerii !");
			return 1;
		}
	}
	if(gPlayerData[playerid][pFaction] != 11 && gPlayerData[playerid][pFaction] != 9)
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie jesteœ pracownikiem rafinerii !");
		return 1;
	}
	return 1;
}

dcmd_cenazalitrlotniczego(playerid, params[])
{
	if(gPlayerData[playerid][pFaction] == 11 || gPlayerData[playerid][pFaction] == 9)
	{
		if(gPlayerData[playerid][pRank] == 1)
		{
			new cost;

			if(sscanf(params, "d", cost))
			{
				SendClientMessage(playerid, COLOR_RED, "[INFO:] /cenazalitrlotniczego [kwota]");
				return 1;
			}
			if(cost <= 0)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Kwota musi byæ wiêksza od 0 !");
				return 1;
			}
			gRafinery[RafFlyLtrCost] = cost;

			new string[128];
			format(string, sizeof(string), "[INFO:] Ustali³eœ now¹ cene za litr paliwa (paliwo lotnicze): $%d", cost);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			printf("[WARNING:] Fuel (fly) price set to: $%d by %s", cost, gPlayerData[playerid][pName]);
			SaveRafinery();
			return 1;
		}
		else
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie jesteœ prezesem rafinerii !");
			return 1;
		}
	}
	if(gPlayerData[playerid][pFaction] != 11 && gPlayerData[playerid][pFaction] != 9)
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie jesteœ pracownikiem rafinerii !");
		return 1;
	}
	return 1;
}

dcmd_cenazalitrsbenzyny(playerid, params[])
{
	new cost;
	new string[128];
	for(new i = 0; i < sizeof(GasStations); i++)
	{
		if(PlayerToPoint(10.0, playerid, GasStations[i][GSposX], GasStations[i][GSposY], GasStations[i][GSposZ]))
		{
			if(strcmp(gPlayerData[playerid][pName], Businesses[GasStations[i][BusinessID]][Owner], false) == 0 || gPlayerData[playerid][pAdmin] == 5)
			{
				if(sscanf(params, "d", cost))
				{
					SendClientMessage(playerid, COLOR_RED, "[INFO:] /cenazalitrs [kwota]");
					return 1;
				}
				if(cost <= 0)
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Kwota musi byæ wiêksza od 0 !");
					return 1;
				}
				GasStations[i][PetrolPrice] = cost;

				format(string, sizeof(string), "Benzyna: $%d", GasStations[i][PetrolPrice]);
				UpdateDynamic3DTextLabelText(GasStations[i][GS3dTextLabel], COLOR_GREEN, string);

				format(string, sizeof(string), "[INFO:] Ustali³eœ now¹ cene za litr paliwa (benzyna): $%d", cost);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);

				SaveFuleStationData(i, "PetrolPrice");

				return 1;
			}
		}
	}
	SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie znajdujesz siê na ¿adnej stacji !");
	return 1;
}

dcmd_cenazalitrsropy(playerid, params[])
{
	new cost;
	new string[128];
	for(new i = 0; i < sizeof(GasStations); i++)
	{
		if(PlayerToPoint(10.0, playerid, GasStations[i][GSposX], GasStations[i][GSposY], GasStations[i][GSposZ]))
		{
			if(strcmp(gPlayerData[playerid][pName], Businesses[GasStations[i][BusinessID]][Owner], false) == 0 || gPlayerData[playerid][pAdmin] == 5 )
			{
				if(sscanf(params, "d", cost))
				{
					SendClientMessage(playerid, COLOR_RED, "[INFO:] /cenazalitrs [kwota]");
					return 1;
				}
				if(cost <= 0)
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Kwota musi byæ wiêksza od 0 !");
					return 1;
				}
				GasStations[i][OilPrice] = cost;

				format(string, sizeof(string), "Diesel: $%d", GasStations[i][OilPrice]);
				UpdateDynamic3DTextLabelText(GasStations[i][GS3dTextLabel2], COLOR_GREEN, string);

				format(string, sizeof(string), "[INFO:] Ustali³eœ now¹ cene za litr paliwa (diesel): $%d", cost);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);

				SaveFuleStationData(i, "OilPrice");

				return 1;
			}
		}
	}
	SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie znajdujesz siê na ¿adnej stacji !");
	return 1;
}

dcmd_cenazalitrsgazu(playerid, params[])
{
	new cost;
	new string[128];
	for(new i = 0; i < sizeof(GasStations); i++)
	{
		if(PlayerToPoint(10.0, playerid, GasStations[i][GSposX], GasStations[i][GSposY], GasStations[i][GSposZ]))
		{
			if(strcmp(gPlayerData[playerid][pName], Businesses[GasStations[i][BusinessID]][Owner], false) == 0|| gPlayerData[playerid][pAdmin] == 5)
			{
				if(sscanf(params, "d", cost))
				{
					SendClientMessage(playerid, COLOR_RED, "[INFO:] /cenazalitrs [kwota]");
					return 1;
				}
				if(cost <= 0)
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Kwota musi byæ wiêksza od 0 !");
					return 1;
				}
				GasStations[i][GasPrice] = cost;

				format(string, sizeof(string), "Gaz: $%d", GasStations[i][GasPrice]);
				UpdateDynamic3DTextLabelText(GasStations[i][GS3dTextLabel3], COLOR_GREEN, string);

				format(string, sizeof(string), "[INFO:] Ustali³eœ now¹ cene za litr paliwa (gaz): $%d", cost);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);

				SaveFuleStationData(i, "GasPrice");

				return 1;
			}
		}
	}
	SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie znajdujesz siê na ¿adnej stacji !");
	return 1;
}

/*dcmd_wynagrodzenie(playerid, params[])
{
	if(gPlayerData[playerid][pFaction] == 11)
	{
		if(gPlayerData[playerid][pRank] == 1)
		{
			new cost;
			if(sscanf(params, "d", cost))
			{
				SendClientMessage(playerid, COLOR_RED, "[INFO:] /wyngrodzenie [kwota]");
				return 1;
			}
			if(cost <= 0)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Kwota musi byæ wiêksza od 0 !");
				return 1;
			}
			gRafinery[RafRefuelReward] = cost;
			new string[128];
			format(string, sizeof(string), "[INFO:] Ustali³eœ now¹ kwote wynagrodzenia dla pracowników: $%d", cost);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			return 1;
		}
		else
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie jesteœ prezesem rafinerii !");
			return 1;
		}
	}
	else
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie jesteœ pracownikiem rafinerii !");
		return 1;
	}
}*/

dcmd_uzupelnianiebenzyny(playerid, params[])
{
	#pragma unused params
	for(new i = 0; i < sizeof(GasStations); i++)
	{
		if(PlayerToPoint(10.0, playerid, GasStations[i][GSposX], GasStations[i][GSposY], GasStations[i][GSposZ]))
		{
			if(strcmp(gPlayerData[playerid][pName], Businesses[GasStations[i][BusinessID]][Owner], false) == 0 || (Businesses[GasStations[i][BusinessID]][BGov] && gPlayerData[playerid][pFaction] == FACTIONID_GOVERNMENT))
			{
				if(GasStations[i][RefuelPetrolResources])
				{
					GasStations[i][RefuelPetrolResources] = 0;
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Anulowa³eœ dostawy paliwa od rafinerii");
				}
				else
				{
					GasStations[i][RefuelPetrolResources] = 1;
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Aktywowa³eœ dostawy paliwa od rafinerii");
				}
				PlayerActionMessage(playerid,15.0,"podpisuje dokumenty");
				return 1;
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ta stacja paliwowa nie nale¿y do Ciebie !");
				return 1;
			}
		}
	}
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie znajdujesz sie na ¿adnej stacji !");
	return 1;
}

dcmd_uzupelnianieropy(playerid, params[])
{
	#pragma unused params
	for(new i = 0; i < sizeof(GasStations); i++)
	{
		if(PlayerToPoint(10.0, playerid, GasStations[i][GSposX], GasStations[i][GSposY], GasStations[i][GSposZ]))
		{
			if(strcmp(gPlayerData[playerid][pName], Businesses[GasStations[i][BusinessID]][Owner], false) == 0 || (Businesses[GasStations[i][BusinessID]][BGov] && gPlayerData[playerid][pFaction] == FACTIONID_GOVERNMENT))
			{
				if(GasStations[i][RefuelOilResources])
				{
					GasStations[i][RefuelOilResources] = 0;
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Anulowa³eœ dostawy paliwa od rafinerii");
				}
				else
				{
					GasStations[i][RefuelOilResources] = 1;
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Aktywowa³eœ dostawy paliwa od rafinerii");
				}
				PlayerActionMessage(playerid,15.0,"podpisuje dokumenty");
				return 1;
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ta stacja paliwowa nie nale¿y do Ciebie !");
				return 1;
			}
		}
	}
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie znajdujesz sie na ¿adnej stacji !");
	return 1;
}

dcmd_uzupelnianiegazu(playerid, params[])
{
	#pragma unused params
	for(new i = 0; i < sizeof(GasStations); i++)
	{
		if(PlayerToPoint(10.0, playerid, GasStations[i][GSposX], GasStations[i][GSposY], GasStations[i][GSposZ]))
		{
			if(strcmp(gPlayerData[playerid][pName], Businesses[GasStations[i][BusinessID]][Owner], false) == 0 || (Businesses[GasStations[i][BusinessID]][BGov] && gPlayerData[playerid][pFaction] == FACTIONID_GOVERNMENT))
			{
				if(GasStations[i][RefuelGasResources])
				{
					GasStations[i][RefuelGasResources] = 0;
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Anulowa³eœ dostawy paliwa od rafinerii");
				}
				else
				{
					GasStations[i][RefuelGasResources] = 1;
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Aktywowa³eœ dostawy paliwa od rafinerii");
				}
				PlayerActionMessage(playerid,15.0,"podpisuje dokumenty");
				return 1;
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ta stacja paliwowa nie nale¿y do Ciebie !");
				return 1;
			}
		}
	}
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie znajdujesz sie na ¿adnej stacji !");
	return 1;
}

dcmd_abizidtogasstation(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] <= 4)
		return 0;
	new businessID;
	new string[128];
	if(sscanf(params, "d", businessID))
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] /abizidtogasstation [id biznesu]");
		return 1;
	}
	for(new i = 0; i < sizeof(GasStations); i++)
	{
		if(PlayerToPoint(10.0, playerid, GasStations[i][GSposX], GasStations[i][GSposY], GasStations[i][GSposZ]))
		{
			GasStations[i][BusinessID] = businessID;
			SaveFuleStationData(i, "BusinessID");
			
			format(string, sizeof(string), "[INFO:] Business ID: %d connected with Gas Station ID: %d", businessID, i);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
		}
	}
	return 1;
}

dcmd_setrafineryresources(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] <= 4)
		return 0;
	new resources;
	if(sscanf(params, "d", resources))
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] /asetrafineryresources [resources]");
		return 1;
	}
	gRafinery[RafResourcePetrol] = resources;
	new string[128];
	format(string, sizeof(string), "[INFO:] Rafinery resources set to: %d", resources);
	SendClientMessage(playerid, COLOR_RED, string);
	return 1;
}

dcmd_setRafineryResources2(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] <= 4)
		return 0;
	new resources;
	if(sscanf(params, "d", resources))
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] /asetgRafineryResources2 [resources]");
		return 1;
	}
	gRafinery[RafResourceOil] = resources;
	new string[128];
	format(string, sizeof(string), "[INFO:] Rafinery resources 2 set to: %d", resources);
	SendClientMessage(playerid, COLOR_RED, string);
	return 1;
}

dcmd_setRafineryResources3(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] <= 4)
		return 0;
	new resources;
	if(sscanf(params, "d", resources))
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] /asetgRafineryResources3 [resources]");
		return 1;
	}
	gRafinery[RafResourceGas] = resources;
	new string[128];
	format(string, sizeof(string), "[INFO:] Rafinery resources 3 set to: %d", resources);
	SendClientMessage(playerid, COLOR_RED, string);
	return 1;
}

dcmd_setmaxrafineryresources(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] <= 4)
		return 0;
	new resources;
	if(sscanf(params, "d", resources))
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] /asetmaxrafineryresources [resources]");
		return 1;
	}
	gRafinery[RafMaxResources] = resources;
	new string[128];
	format(string, sizeof(string), "[INFO:] Rafinery max resources set to: %d", resources);
	SendClientMessage(playerid, COLOR_RED, string);
	return 1;
}

dcmd_giveplayerweapon(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	GivePlayerWeapon(playerid, 31, 999);
	return 1;
}

dcmd_rafinerycmds(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] == 0)
		return 0;
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /abizidtogasstation - /setrafineryresources(2/3) - /setmaxrafineryresources(2/3) - /setrafineryltrcost(2/3)");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /setgasstationfuelprice(2/3) - /setgasstationmaxresources(2/3) - /setgasstationresources(2/3)");
	return 1;
}

dcmd_setrafineryltrcost(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin]  < 4)
		return 0;
	new cost;
	if(sscanf(params, "d", cost))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /asetrafineryltrcost [cost]");
		return 1;
	}
	gRafinery[RafPetrolLtrCost] = cost;
	new string[128];
	format(string, sizeof(string), "[INFO:] Rafinery fuel ltr cost set to $%d", cost);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	return 1;
}

dcmd_setrafineryltrcost2(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin]  < 4)
		return 0;
	new cost;
	if(sscanf(params, "d", cost))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /asetrafineryltrcost2 [cost]");
		return 1;
	}
	gRafinery[RafOilLtrCost] = cost;
	new string[128];
	format(string, sizeof(string), "[INFO:] Rafinery fuel ltr cost set to $%d", cost);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	return 1;
}

dcmd_setrafineryltrcost3(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin]  < 4)
		return 0;
	new cost;
	if(sscanf(params, "d", cost))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /asetrafineryltrcost3 [cost]");
		return 1;
	}
	gRafinery[RafGasLtrCost] = cost;
	new string[128];
	format(string, sizeof(string), "[INFO:] Rafinery fuel ltr cost set to $%d", cost);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	return 1;
}

dcmd_setgasstationresources(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] < 5)
		return 0;
	
	new resources;
	new string[128];
	if(sscanf(params, "d", resources))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /asetgasstationresources [resources]");
		return 1;
	}
	for(new i = 0; i < sizeof(GasStations); i++)
	{
		if(PlayerToPoint(10.0, playerid, GasStations[i][GSposX], GasStations[i][GSposY], GasStations[i][GSposZ]))
		{
			GasStations[i][PetrolResourceValue] = resources;
			format(string, sizeof(string), "[INFO:] Gas station ID: %d resources set to %d", i, resources);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			return 1;
		}
	}
	return 1;
}

dcmd_setgasstationresources2(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] < 5)
		return 0;
		
	new resources;
	new string[128];
	if(sscanf(params, "d", resources))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /asetgasstationresources [resources]");
		return 1;
	}
	for(new i = 0; i < sizeof(GasStations); i++)
	{
		if(PlayerToPoint(10.0, playerid, GasStations[i][GSposX], GasStations[i][GSposY], GasStations[i][GSposZ]))
		{
			GasStations[i][OilResourceValue] = resources;
			format(string, sizeof(string), "[INFO:] Gas station ID: %d resources 2 set to %d", i, resources);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			return 1;
		}
	}
	return 1;
}

dcmd_setgasstationresources3(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] < 5)
		return 0;
		
	new resources;
	new string[128];
	if(sscanf(params, "d", resources))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /asetgasstationresources [resources]");
		return 1;
	}
	for(new i = 0; i < sizeof(GasStations); i++)
	{
		if(PlayerToPoint(10.0, playerid, GasStations[i][GSposX], GasStations[i][GSposY], GasStations[i][GSposZ]))
		{
			GasStations[i][GasResourceValue] = resources;
			format(string, sizeof(string), "[INFO:] Gas station ID: %d resources 3 set to %d", i, resources);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			return 1;
		}
	}
	return 1;
}

dcmd_setgasstationmaxresources(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] >= 10)
	{
		new string[128];
		new Float:resources;
		if(sscanf(params, "f", resources))
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /asetgasstationmaxresources [resources]");
			return 1;
		}
		for(new i = 0; i < sizeof(GasStations); i++)
		{
			if(PlayerToPoint(10.0, playerid, GasStations[i][GSposX], GasStations[i][GSposY], GasStations[i][GSposZ]))
			{
				GasStations[i][MaxPetrolResourceValue] = resources;
				format(string, sizeof(string), "[INFO:] Gas station ID: %d max resources set to %d", i, resources);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
				return 1;
			}
		}
	}
	return 1;
}

dcmd_setgasstationmaxresources2(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] >= 10)
	{
		new string[128];
		new Float:resources;
		if(sscanf(params, "f", resources))
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /asetgasstationmaxresources2 [resources]");
			return 1;
		}
		for(new i = 0; i < sizeof(GasStations); i++)
		{
			if(PlayerToPoint(10.0, playerid, GasStations[i][GSposX], GasStations[i][GSposY], GasStations[i][GSposZ]))
			{
				GasStations[i][MaxOilResourceValue] = resources;
				format(string, sizeof(string), "[INFO:] Gas station ID: %d max resources 2 set to %d", i, resources);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
				return 1;
			}
		}
	}
	return 1;
}

dcmd_setgasstationmaxresources3(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] >= 10)
	{
		new string[128];
		new Float:resources;
		if(sscanf(params, "f", resources))
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /asetgasstationmaxresources3 [resources]");
			return 1;
		}
		for(new i = 0; i < sizeof(GasStations); i++)
		{
			if(PlayerToPoint(10.0, playerid, GasStations[i][GSposX], GasStations[i][GSposY], GasStations[i][GSposZ]))
			{
				GasStations[i][MaxGasResourceValue] = resources;
				format(string, sizeof(string), "[INFO:] Gas station ID: %d max resources 3 set to %d", i, resources);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
				return 1;
			}
		}
	}
	return 1;
}

dcmd_setgasstationfuelprice(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] >= 10)
	{
		new resources;
		new string[128];
		if(sscanf(params, "d", resources))
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /asetgasstationfuelprice [price]");
			return 1;
		}
		for(new i = 0; i < sizeof(GasStations); i++)
		{
			if(PlayerToPoint(10.0, playerid, GasStations[i][GSposX], GasStations[i][GSposY], GasStations[i][GSposZ]))
			{
				GasStations[i][PetrolPrice] = resources;
				format(string, sizeof(string), "[INFO:] Gas station ID: %d ltr price set to %d", i, resources);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
				return 1;
			}
		}
	}
	return 1;
}

dcmd_setgasstationfuelprice2(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] >= 10)
	{
		new resources;
		new string[128];
		if(sscanf(params, "d", resources))
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /asetgasstationfuelprice [price]");
			return 1;
		}
		for(new i = 0; i < sizeof(GasStations); i++)
		{
			if(PlayerToPoint(10.0, playerid, GasStations[i][GSposX], GasStations[i][GSposY], GasStations[i][GSposZ]))
			{
				GasStations[i][OilPrice] = resources;
				format(string, sizeof(string), "[INFO:] Gas station ID: %d ltr price 2 set to %d", i, resources);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
				return 1;
			}
		}
	}
	return 1;
}

dcmd_setgasstationfuelprice3(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] >= 10)
	{
		new resources;
		new string[128];
		if(sscanf(params, "d", resources))
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /asetgasstationfuelprice [price]");
			return 1;
		}
		for(new i = 0; i < sizeof(GasStations); i++)
		{
			if(PlayerToPoint(10.0, playerid, GasStations[i][GSposX], GasStations[i][GSposY], GasStations[i][GSposZ]))
			{
				GasStations[i][GasPrice] = resources;
				format(string, sizeof(string), "[INFO:] Gas station ID: %d ltr price 3 set to %d", i, resources);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
				return 1;
			}
		}
	}
	return 1;
}

dcmd_payday(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	PayDay();
	return 1;
}

dcmd_acarreadytosell(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] < 4)
		return 0;
	new ready, vehID;
	if(sscanf(params, "d", ready))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /acarreadytosell [ready]");
		return 1;
	}
	if(!IsPlayerInAnyVehicle(playerid))
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] You are not in a vehicle !");
		return 1;
	}
	vehID = GetPlayerVehicleID(playerid)-1;
	new string[128];
	gVehData[vehID][ReadyToSell] = ready;
	SaveVehData(vehID, "ReadyToSell");

	RefreshVehicleDescription(vehID+1);

	format(string, sizeof(string), "[INFO:] Vehicle ID: %d, ReadyToSell set to: %d", GetPlayerVehicleID(playerid), ready);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	return 1;
}

dcmd_acarbusinessid(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] < 4)
		return 0;
	new businessID;
	if(sscanf(params, "d", businessID))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /acarbusinessid [business id]");
		return 1;
	}
	if(!IsPlayerInAnyVehicle(playerid))
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] You are not in a vehicle !");
		return 1;
	}
	new string[128];
	gVehData[GetPlayerVehicleID(playerid)-1][BusinessID] = businessID;

	SaveVehData(GetPlayerVehicleID(playerid)-1, "BusinessID");

	format(string, sizeof(string), "[INFO:] Vehicle ID: %d, BusinessID set to: %d", GetPlayerVehicleID(playerid), businessID);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	return 1;
}

dcmd_afillcarscpartstable(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new string[128];
	for(new i = 1; i <= sizeof(gVehData); i++)
	{
		format(string, sizeof(string), "INSERT INTO `samp_cars_cparts` (`CustomObj1Model`) VALUES ('0') ");
		wp_mysql_query(string, SAVE, playerid, db_con2);
	}
	return 1;
}

dcmd_afillftable(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new string[128];
	for(new i = 1; i <= sizeof(DynamicFactions); i++)
	{
		format(string, sizeof(string), "INSERT INTO `samp_factions` (`Name`) VALUES ('None') ");
		wp_mysql_query(string, SAVE, playerid, db_con2);
	}
	return 1;
}

dcmd_afillcarstable(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new string[128];
	for(new i = 0; i < 1500; i++)
	{
		format(string, sizeof(string), "INSERT INTO `samp_vehicles` (`VehModel`) VALUES ('0') ");
		wp_mysql_query(string, SAVE, playerid, db_con2);
	}
	return 1;
}

dcmd_afillcarsctable(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new string[128];
	for(new i = 0; i < 1500; i++)
	{
		format(string, sizeof(string), "INSERT INTO `samp_vehicles_customize` (`Spoiler`) VALUES ('594') ");
		wp_mysql_query(string, SAVE, playerid, db_con2);
	}
	return 1;
}

dcmd_afillracestable(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new string[128];
	for(new i = 0; i < 50; i++)
	{
		format(string, sizeof(string), "INSERT INTO `samp_races_tracks` (`Enabled`) VALUES ('0') ");
		wp_mysql_query(string, SAVE, playerid, db_con2);
		for(new j = 0; j < 150; j++)
		{
			format(string, sizeof(string), "INSERT INTO `samp_races_tracks_data` (`RaceId` , `CpId`) VALUES ('%d' , '%d') ", i, j);
			wp_mysql_query(string, SAVE, playerid, db_con2);
		}
	}
	return 1;
}

dcmd_afillweedtable(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new string[128];
	for(new i = 0; i < 200; i++)
	{
		format(string, sizeof(string), "INSERT INTO `samp_weed` (`Type`) VALUES ('0')");
		wp_mysql_query(string, SAVE, playerid, db_con2);
	}
	return 1;
}

dcmd_savepayrank(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	SavePayRank();

	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Zapis rang uruchomiony !");
	return 1;
}

dcmd_przekazlidera(playerid, params[])
{
	if(gPlayerData[playerid][pFaction] == 255)
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie jesteœ liderem ¿adnej frakcji !");
		return 1;
	}
	if(gPlayerData[playerid][pRank] != 1)
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie jesteœ liderem tej frakcji !");
		return 1;
	}
	new giveplayerid;
	if(sscanf(params, "d", giveplayerid))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /przekazlidera [id gracza]");
		return 1;
	}
	if(IsPlayerConnected(playerid) == 0)
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Gracz nie jest ON-LINE !");
		return 1;
	}
	gPlayerData[playerid][pRank] = 2;
	gPlayerData[giveplayerid][pRank] = 1;
	gPlayerData[giveplayerid][pFaction] = gPlayerData[playerid][pFaction];

	SavePlayerData(playerid, "Rank");
	SavePlayerData(giveplayerid, "Rank");
	SavePlayerData(giveplayerid, "Faction");

	new string[128];
	format(string, sizeof(string), "[INFO:] Przekaza³eœ lidera frakcji osobie o imieniu %s !", GetPlayerNameEx(giveplayerid));
	SendClientMessage(playerid, COLOR_GREEN, string);

	if(gPlayerData[giveplayerid][pFirstLeader])
	{
		format(string, sizeof(string), "[INFO:] %s mianowa³ Ciê liderem frakcji %s !", GetPlayerNameEx(playerid), DynamicFactions[gPlayerData[playerid][pFaction]][Name]);
		SendClientMessage(giveplayerid, COLOR_GREEN, string);
	}
	else
	{
		format(string, sizeof(string), "[INFO:] Zosta³eœ mianowany na lidera frakcji %s ! Przekazuj¹cy: %s.", DynamicFactions[gPlayerData[playerid][pFaction]][Name],GetPlayerNameEx(playerid));
		SendClientMessage(giveplayerid, COLOR_LIGHTBLUE, string);

		// AddExpPoint(giveplayerid);
		gPlayerData[giveplayerid][pFirstLeader] = 1;

		SavePlayerData(giveplayerid, "FirstLeader");
	}
	return 1;
}

dcmd_azoneowner(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] < 4)
		return 0;
	new zoneid;
	new factionid;
	if(sscanf(params, "dd", zoneid, factionid))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /azoneowner [zoneid] [factionid]");
		return 1;
	}
	DynamicZones[zoneid][mFaction] = factionid;
	foreach(Player, i)
	{
		GangZoneHideForPlayer(i, DynamicZones[zoneid][mZoneId]);
		if(DynamicZones[zoneid][mFaction] == gPlayerData[i][pFaction])
			GangZoneShowForPlayer(i, DynamicZones[zoneid][mZoneId], 0x00FF0090);
		else
			GangZoneShowForPlayer(i, DynamicZones[zoneid][mZoneId], 0xFF000090);				
	}
	new string[128];
	format(string, sizeof(string), "[INFO:] Zone id: %d owner set to faction: %s [%d]", zoneid, DynamicFactions[factionid][Name], factionid);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	SaveGangZone(zoneid, "Faction");
	return 1;
}

dcmd_acarkm(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] < 4)
		return 0;
	new carid, km;
	if(sscanf(params, "dd", carid, km))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /acarkm [vehid] [m]");
		return 1;
	}
	gVehData[carid-1][CarCounter] = km;

	return 1;
}

dcmd_widd(playerid, params[])
{
	dcmd_wlozitemdodomu(playerid, params);
	return 1;
}
dcmd_wlozitemdodomu(playerid, params[])
{
	#pragma unused params
	for(new i = 0; i < sizeof(Houses); i++)
	{
		if(PlayerToPoint(15.0, playerid,Houses[i][ExitX], Houses[i][ExitY], Houses[i][ExitZ]) && i == GetPlayerVirtualWorld(playerid))
		{
			gDSelectedHItemHouse[playerid] = i;
			ShowPItemsHIns(playerid);
			return 1;
		}
	}
	return 1;
}

dcmd_mojeitemywpojezdzie(playerid, params[])
{
	dcmd_miwp(playerid, params);
	return 1;
}

dcmd_miwp(playerid, params[])
{
	#pragma unused params
	if(IsPlayerInAnyVehicle(playerid))
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Musisz byæ przy baga¿niku aby w³o¿yæ item");
		return 1;
	}
	new vehicleid = GetClosestVehicle(playerid);
	new Float:xc, Float:yc, Float:ac, Float:bc, Float:vx, Float:vy, Float:vz, Float:va;
	if(vehicleid == INVALID_VEHICLE_ID)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Musisz byæ przy baga¿niku aby w³o¿yæ item");
		return 1;
	}
	GetVehiclePos(vehicleid, vx, vy, vz);
	GetVehicleZAngle(vehicleid, va);
	GetPlayerFacingAngle(playerid, ac);
	for(new i = 0; i < sizeof(CarsLenghts); i++)
	{
		if(CarsLenghts[i][lenghtModel] == gVehData[vehicleid-1][mVehModel])
		{
			GetXYInFrontOfPlayer(playerid, xc, yc, CarsLenghts[i][trunkDistance]);
			if(CarsLenghts[i][trunkAngle] == 0)
			{
				if(ac-180 < 0)
					ac += 180;
				else
					ac -= 180;
			}
			else if(CarsLenghts[i][trunkAngle] == 2)
			{
				bc = ac;
				if(ac-90.0 < 0.0)
					ac = 270.0+ac;
				else
					ac -= 90.0;
				if(bc+90.0 > 360.0)
					bc = 430.0-bc;
				else
					bc += 90.0;
			}
			if((floatabs(xc-vx) > 0.9 || floatabs(yc-vy) > 0.9) || (floatabs(va-ac) > 28.0 && (IsAMotorBike(vehicleid) && floatabs(va-bc) > 28.0)))
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Jesteœ zbyt daleko od pojazdu/baga¿nika !");
				return 1;
			}
			else
			{
				if(((CarsLenghts[i][trunkAngle] == 0 || CarsLenghts[i][trunkAngle] == 2) && !gVehData[vehicleid-1][BootUp]) || (CarsLenghts[i][trunkAngle] == 1 && !gVehData[vehicleid-1][BonnetUp]))
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Musisz wpierw otworzyæ baga¿nik !");
					return 1;
				}
				gDSelectedVItemVID[playerid] = vehicleid;
				gDSelectedVItemVTSpace[playerid] = CarsLenghts[i][trunkSpace];
				ShowPVItems(playerid, gDSelectedVItemVID[playerid], CarsLenghts[i][trunkSpace]);
				return 1;
			}
		}
	}
	return 1;
}

dcmd_widp(playerid, params[])
{
	dcmd_wlozitemdopojazdu(playerid, params);
	return 1;
}

dcmd_wlozitemdopojazdu(playerid, params[])
{
	#pragma unused params
	if(IsPlayerInAnyVehicle(playerid))
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Musisz byæ przy baga¿niku aby w³o¿yæ item");
		return 1;
	}
	new vehicleid = GetClosestVehicle(playerid);
	new Float:xc, Float:yc, Float:ac, Float:bc, Float:vx, Float:vy, Float:vz, Float:va;
	GetVehiclePos(vehicleid, vx, vy, vz);
	GetVehicleZAngle(vehicleid, va);
	GetPlayerFacingAngle(playerid, ac);
	for(new i = 0; i < sizeof(CarsLenghts); i++)
	{
		if(CarsLenghts[i][lenghtModel] == gVehData[vehicleid-1][mVehModel])
		{
			GetXYInFrontOfPlayer(playerid, xc, yc, CarsLenghts[i][trunkDistance]);
			if(CarsLenghts[i][trunkAngle] == 1)
			{
				if(ac-180 < 0)
					ac += 180;
				else
					ac -= 180;
			}
			else if(CarsLenghts[i][trunkAngle] == 2)
			{
				bc = ac;
				if(ac-90.0 < 0.0)
					ac = 270.0+ac;
				else
					ac -= 90.0;
				if(bc+90.0 > 360.0)
					bc = 430.0-bc;
				else
					bc += 90.0;
			}
			if( ( floatabs(xc-vx) > 0.9 || floatabs(yc-vy) > 0.9 ) || (floatabs(va-ac) > 28.0 && (IsAMotorBike(vehicleid) && floatabs(va-bc) > 28.0)))
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Jesteœ zbyt daleko od pojazdu/baga¿nika !");
				return 1;
			}
			else
			{
				new enginedyn, lights, alarm, bonnet, boot, objective, doors;
				GetVehicleParamsEx(vehicleid, enginedyn, lights, alarm, doors, bonnet, boot, objective);
				if(!boot)
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Przed w³o¿eniem itema otwórz baga¿nik !");
					return 1;
				}
				gDSelectedVItemVID[playerid] = vehicleid;
				ShowPItemsVIns(playerid);
			}
		}
	}
	return 1;
}

dcmd_wezitemzdomu(playerid, params[])
{
	new slot;
	new slotin;
	new string[128];
	for(new i = 0; i < sizeof(Houses); i++)
	{
		if(!PlayerToPoint(15.0, playerid,Houses[i][ExitX], Houses[i][ExitY], Houses[i][ExitZ]) || i != GetPlayerVirtualWorld(playerid))
		{
			continue;
		}
		if(sscanf(params, "d", slot))
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /wezitemzdomu [slot(1-5)]");
			return 1;
		}
		if(!HItemSlotStatus(i, slot))
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten slot jest pusty !");
			return 1;
		}
		if(slot == 1)
		{
			slotin = InsertPlayerItemEx(playerid, Houses[i][HItem1type], Houses[i][HItem1], Houses[i][HItem1param], Houses[i][HItem1param2], Houses[i][HItem1param3],Houses[i][HItem1param4],Houses[i][HItem1param5]);
			if(slotin == 0)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz przenosiæ wiêcej przedmiotów !");
				return 1;
			}
		}
		if(slot == 2)
		{
			slotin = InsertPlayerItemEx(playerid, Houses[i][HItem2type], Houses[i][HItem2], Houses[i][HItem2param], Houses[i][HItem2param2], Houses[i][HItem2param3],Houses[i][HItem2param4],Houses[i][HItem2param5]);
			if(slotin == 0)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz przenosiæ wiêcej przedmiotów !");
				return 1;
			}
		}
		if(slot == 3)
		{
			slotin = InsertPlayerItemEx(playerid, Houses[i][HItem3type], Houses[i][HItem3], Houses[i][HItem3param], Houses[i][HItem3param2], Houses[i][HItem3param3],Houses[i][HItem3param4],Houses[i][HItem3param5]);
			if(slotin == 0)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz przenosiæ wiêcej przedmiotów !");
				return 1;
			}
		}
		if(slot == 4)
		{
			slotin = InsertPlayerItemEx(playerid, Houses[i][HItem4type], Houses[i][HItem4], Houses[i][HItem4param], Houses[i][HItem4param2], Houses[i][HItem4param3],Houses[i][HItem4param4],Houses[i][HItem4param5]);
			if(slotin == 0)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz przenosiæ wiêcej przedmiotów !");
				return 1;
			}
		}
		if(slot == 5)
		{
			slotin = InsertPlayerItemEx(playerid, Houses[i][HItem5type], Houses[i][HItem5], Houses[i][HItem5param], Houses[i][HItem5param2], Houses[i][HItem5param3],Houses[i][HItem5param4],Houses[i][HItem5param5]);
			if(slotin == 0)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz przenosiæ wiêcej przedmiotów !");
				return 1;
			}
		}
		RemoveHouseItemEx(i, slot);
		format(string, sizeof(string), "[INFO:] Zabra³eœ item z pokoju (ze slotu %d)", slot);
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
		PlayerActionMessage(playerid, 15.0, "zabiera przedmiot z pó³ki");
		return 1;
	}
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Musisz byæ w domu ¿eby zabraæ z niego przedmiot");

	return 1;
}

dcmd_miwd(playerid, params[])
{
	#pragma unused params
	new string[1024];
	new string2[64];
	for(new i = 0; i < sizeof(Houses); i++)
	{
		if(PlayerToPoint(15.0, playerid,Houses[i][ExitX], Houses[i][ExitY], Houses[i][ExitZ]) && i == GetPlayerVirtualWorld(playerid))
		{
			gDSelectedHItemHouse[playerid] = i;
			format(string, sizeof(string), "1. %s [iloœæ: %d] [waga: %d]\n2. %s [iloœæ: %d] [waga: %d]\n3. %s [iloœæ: %d] [waga: %d]\n4. %s [iloœæ: %d] [waga: %d]\n5. %s [iloœæ: %d] [waga: %d]",
			ItemName(Houses[i][HItem1type], Houses[i][HItem1]),HSlotParam6(i, 1), ItemWeight(Houses[i][HItem1type], Houses[i][HItem1]),
			ItemName(Houses[i][HItem2type], Houses[i][HItem2]),HSlotParam6(i, 2), ItemWeight(Houses[i][HItem2type], Houses[i][HItem2]),
			ItemName(Houses[i][HItem3type], Houses[i][HItem3]),HSlotParam6(i, 3), ItemWeight(Houses[i][HItem3type], Houses[i][HItem3]),
			ItemName(Houses[i][HItem4type], Houses[i][HItem4]),HSlotParam6(i, 4), ItemWeight(Houses[i][HItem4type], Houses[i][HItem4]),
			ItemName(Houses[i][HItem5type], Houses[i][HItem5]),HSlotParam6(i, 5), ItemWeight(Houses[i][HItem5type], Houses[i][HItem5]) );
			format(string2, sizeof(string2), "Moje itemy w domu - waga ca³kowita %d", HItemWeight(i));
			ShowPlayerDialog(playerid,DIALOG_HITEM_1,DIALOG_STYLE_LIST,string2,string,"Wybierz","Anuluj");
			return 1;
		}
	}
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Musisz byæ w domu ¿eby czegoœ poszukaæ");

	return 1;
}

dcmd_mi(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pCharacterDying] > 0 || gPlayerData[playerid][pCharacterDeath] > 0)
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Jesteœ nieprzytomny, nie mo¿esz u¿ywaæ swoich itemów");
		return 1;
	}
	if(gPlayerData[playerid][pJailed])
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Twoje itemy zosta³y skonfiskowane na czas aresztu");
		return 1;
	}
	ShowPItemsEx(playerid);
	return 1;
}

dcmd_mojeitemy(playerid, params[])
{
	dcmd_mi(playerid, params);
	return 1;
}

dcmd_additem(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] < 5)
		return 0;
	new giveplayerid, type, item, param1, param2;
	if(sscanf(params, "ddddd", giveplayerid, type, item, param1, param2))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /additem [playerid] [type] [item] [param1] [param2]");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] TYPE 1 : 1 - £OM , 2 - KOSTKA, 3 - KARTA KREDYTOWA, 4 - KSIAZKA TEL, 5 - PLECAK, 6 - RAKIETA, 7- ZAROWKA ");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] TYPE 1 : 8 - ZESTAW FAJER, 9 - BATON, 10 - HAK, 11 - ALARM, 12 - CYGARO., 105 - MAPA , 106 - RADIO ");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] TYPE 2 : Klucze do samochodu, TYPE 4 - Klucze do domu");
		return 1;
	}
	new slot = InsertPlayerItem(giveplayerid, type, item, param1, param2);
	if(slot == 0)
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Player has no space in inventory !");
		return 1;
	}
	new string[128];
	format(string, sizeof(string), "[INFO:] You have insert item to player inventory [slot:%d]", slot);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	return 1;
}

dcmd_additemex(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] < 5)
		return 0;
	new giveplayerid, type, item, param1, param2, param3, param4, param5[64], param6;
	if(sscanf(params, "ddddddds[64]d", giveplayerid, type, item, param1, param2, param3, param4, param5, param6))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /additemex [playerid] [type] [item] [param1] [param2] [param3] [param4] [param5] [param6]");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] TYPE 1 ; 1 - £OM , 2 - KOSTKA, 3 - KARTA KREDYTOWA, 4 - KSIAZKA TEL, 5 - PLECAK, 6 - RAKIETA, 7- ZAROWKA ");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] TYPE 1 : 8 - ZESTAW FAJER, 9 - BATON, 10 - HAK, 11 - ALARM, 12 - CYGARO., 105 - MAPA , 106 - RADIO ");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] TYPE 2 : Klucze do samochodu, TYPE 4 - Klucze do domu");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Parametr 6 - iloœæ");
		return 1;
	}
	new slot = InsertPlayerItemEx(giveplayerid, type, item, param1, param2, param3, param4, param5, param6);
	if(slot == 0)
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Player has no space in inventory !");
		return 1;
	}
	new string[128];
	format(string, sizeof(string), "[INFO:] You have insert item to player inventory [slot:%d]", slot);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	return 1;
}

dcmd_rmplayeritem(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] <= 0)
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie jesteœ upowa¿niony do u¿ywania tej komendy !");
		return 1;
	}
	new giveplayerid, slot;
	if(sscanf(params, "dd", giveplayerid, slot))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /delitem [playerid] [slot]");
		return 1;
	}
	if(RemovePlayerItemExUsed(giveplayerid, slot))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] You have cleared player slot !");
		return 1;
	}
	else
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Player slot already empty or error occured");
		return 1;
	}
}

dcmd_playeritems(playerid, params[])
{
	if(gPlayerData[playerid][pModerator] == 0)
		return 0;
	new giveplayerid;
	if(sscanf(params, "d", giveplayerid))
	{
		if(gPlayerData[playerid][pVipItem] > 0)
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /playeritems [playerid]");
			return 1;
		}
		else
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /playeritems [playerid]");
			return 1;
		}
	}
	ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_LIST, "Lista itemów osoby okradanej", ShowPItems(giveplayerid), "Zabierz", "Zamknij");
	return 1;

	// new string[128];
	// if(slot == 1)
	// {
		// format(string, sizeof(string), "[INFO:] Przedmiot: %s", ItemName(gPlayerData[giveplayerid][pItem1type], gPlayerData[giveplayerid][pItem1]));

		// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);

		// return 1;
	// }
	// if(slot == 2)
	// {
		// format(string, sizeof(string), "[INFO:] Przedmiot: %s", ItemName(gPlayerData[giveplayerid][pItem2type], gPlayerData[giveplayerid][pItem2]));

		// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);

		// return 1;
	// }
	// if(slot == 3)
	// {
		// format(string, sizeof(string), "[INFO:] Przedmiot: %s", ItemName(gPlayerData[giveplayerid][pItem3type], gPlayerData[giveplayerid][pItem3]));

		// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);

		// return 1;
	// }
	// if(slot == 4)
	// {
		// format(string, sizeof(string), "[INFO:] Przedmiot: %s", ItemName(gPlayerData[giveplayerid][pItem4type], gPlayerData[giveplayerid][pItem4]));

		// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);

		// return 1;
	// }
	// if(slot == 5)
	// {
		// format(string, sizeof(string), "[INFO:] Przedmiot: %s", ItemName(gPlayerData[giveplayerid][pItem5type], gPlayerData[giveplayerid][pItem5]));

		// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);

		// return 1;
	// }
	// if(gPlayerData[giveplayerid][pVipItem] > 0)
	// {
		// if(slot == 6)
		// {
			// format(string, sizeof(string), "[INFO:] Przedmiot: %s", ItemName(gPlayerData[giveplayerid][pItem6type], gPlayerData[giveplayerid][pItem6]));

			// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);

			// return 1;
		// }
		// if(slot == 7)
		// {
			// format(string, sizeof(string), "[INFO:] Przedmiot: %s", ItemName(gPlayerData[giveplayerid][pItem7type], gPlayerData[giveplayerid][pItem7]));

			// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);

			// return 1;
		// }
		// if(slot == 8)
		// {
			// format(string, sizeof(string), "[INFO:] Przedmiot: %s", ItemName(gPlayerData[giveplayerid][pItem8type], gPlayerData[giveplayerid][pItem8]));

			// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);

			// return 1;
		// }
		// if(slot == 9)
		// {
			// format(string, sizeof(string), "[INFO:] Przedmiot: %s", ItemName(gPlayerData[giveplayerid][pItem9type], gPlayerData[giveplayerid][pItem9]));

			// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);

			// return 1;
		// }
		// if(slot == 10)
		// {
			// format(string, sizeof(string), "[INFO:] Przedmiot: %s", ItemName(gPlayerData[giveplayerid][pItem10type], gPlayerData[giveplayerid][pItem10]));

			// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);

			// return 1;
		// }
		// if(slot > 10)
		// {
			// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /playeritems [playerid] [slot(1-10)]");
			// return 1;
		// }
	// }
	// if(slot > 5)
	// {
		// {
			// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /playeritems [playerid] [slot(1-5)]");
			// return 1;
		// }
	// }
	// return 1;
}

dcmd_vipitem(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new giveplayerid, days;
	if(sscanf(params, "dd", giveplayerid, days))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /vipitem [playerid] [days]");
		return 1;
	}
	printf("[WARNING:] %s used /vipitem", gPlayerData[playerid][pName]);
	gPlayerData[giveplayerid][pVipItem] = days;

	SavePlayerData(giveplayerid, "VipItem");

	return 1;
}

dcmd_aservercmds(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] < 1)
		return 0;
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[ADMIN:] /afillcarstable - /carssource - /payday - /vipitem - /afillbiztable - /mysqlcharacterset");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[ADMIN:] /afillhousetable - /housesource - /afillhouseitemstable - /afillracestable - /afillweedtable");
	return 1;
}

dcmd_savefactions(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	SaveDynamicFactions();
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Rozpoczêto zapis frakcji.");
	return 1;
}

dcmd_afillbiztable(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new string[128];
	for(new i = 1; i <= 700; i++)
	{
		format(string, sizeof(string), "INSERT INTO `samp_businesses` (`BusinessName`) VALUES ('None') ");
		wp_mysql_query(string, SAVE, playerid, db_con2);
	}
	return 1;
}

dcmd_afillhousetable(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new string[128];
	for(new i = 1; i <= 1000; i++)
	{
		format(string, sizeof(string), "INSERT INTO `samp_houses` (`Owner`) VALUES ('NONE') ");
		wp_mysql_query(string, SAVE, playerid, db_con2);
	}
	return 1;
}

dcmd_afillhouseitemstable(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new string[128];
	for(new i = 1; i <= 1000; i++)
	{
		format(string, sizeof(string), "INSERT INTO `samp_houses_items` (`HItem1`) VALUES ('0') ");
		wp_mysql_query(string, SAVE, playerid, db_con2);
	}
	return 1;
}

dcmd_housesource(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new source;
	if(sscanf(params, "d", source))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /housesource [source(0/1)]");
		return 1;
	}
	new string[128];
	houseSource = source;
	format(string, sizeof(string), "[INFO:] ród³o domów ustawione na %d", source);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	return 1;
}

dcmd_setcarserialtoall(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	for(new i = 0; i < sizeof(gVehData); i++)
	{
		if(gVehData[i][CarSerial] == 0)
		{
			gVehData[i][CarSerial] = random(99999);

			SaveVehData(i, "CarSerial");
		}
	}
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2,  "[INFO:] Done");
	return 1;
}

dcmd_setcarrserial(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] < 4)
		return 0;
	new vehicleid;
	if(sscanf(params, "d", vehicleid))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /setcarserial [carid]");
		return 1;
	}
	gVehData[vehicleid-1][CarSerial] = random(2000);
	for(new i = 0; i < sizeof(gVehData); i++)
	{
		if(i != vehicleid-1)
		{
			if(gVehData[vehicleid-1][CarSerial] == gVehData[i][CarSerial])
			{
				i = 0;
				gVehData[vehicleid-1][CarSerial] = random(2000);
			}
		}
	}

	SaveVehData(vehicleid-1, "CarSerial");

	new string[128];

	if(gVehData[vehicleid-1][CarSerial] < 10 && gVehData[vehicleid-1][CarSerial] > 0)
	{
		format(string, sizeof(string), "SA-000%d", gVehData[vehicleid-1][CarSerial]);
	}
	if(gVehData[vehicleid-1][CarSerial] > 10 && gVehData[vehicleid-1][CarSerial] < 100)
	{
		format(string, sizeof(string), "SA-00%d", gVehData[vehicleid-1][CarSerial]);
	}
	if(gVehData[vehicleid-1][CarSerial] > 100 && gVehData[vehicleid-1][CarSerial] < 1000)
	{
		format(string, sizeof(string), "SA-0%d", gVehData[vehicleid-1][CarSerial]);
	}
	if(gVehData[vehicleid-1][CarSerial] > 1000)
	{
		format(string, sizeof(string), "SA-%d", gVehData[vehicleid-1][CarSerial]);
	}

	// DestroyDynamic3DTextLabel( gVehData[vehicleid-1][Veh3DSerial] );

	if(gVehData[vehicleid-1][CarSerial] > 0)
	{
		if(IsAMotorBike(vehicleid) && gVehData[vehicleid][mVehModel] != 522 && gVehData[vehicleid][mVehModel] != 471 && gVehData[vehicleid][mVehModel] != 468)
		{
			// SetVehicleNumberPlate(vehicleid, string);
			//veh3dserial[vehicleid-1] = CreateDynamic3DTextLabel(string, COLOR_WHITE, 0.0, -1.0, 0.3, 20.0, INVALID_PLAYER_ID, vehicleid, 0);
		}
		if(gVehData[vehicleid][mVehModel] == 522 || gVehData[vehicleid][mVehModel] == 471 || gVehData[vehicleid][mVehModel] == 468)
		{
			gVehData[vehicleid-1][Veh3DSerial] = CreateDynamic3DTextLabel(string, COLOR_WHITE, 0.0, -1.0, 0.3, 20.0, INVALID_PLAYER_ID, vehicleid, 0);
		}
		if(IsABoat(vehicleid))
		{
			gVehData[vehicleid-1][Veh3DSerial] = CreateDynamic3DTextLabel(string, COLOR_WHITE, 0.0, 1.0, 0.2, 25.0, INVALID_PLAYER_ID, vehicleid, 0);
		}
		if(IsAPlane(vehicleid))
		{
			gVehData[vehicleid-1][Veh3DSerial] = CreateDynamic3DTextLabel(string, COLOR_WHITE, 0.0, 1.0, 0.2, 25.0, INVALID_PLAYER_ID, vehicleid, 0);
		}
		if(IsAHelicopter(vehicleid))
		{
			gVehData[vehicleid-1][Veh3DSerial] = CreateDynamic3DTextLabel(string, COLOR_WHITE, 0.0, -2.5, 0.9, 25.0, INVALID_PLAYER_ID, vehicleid, 0);
		}
		if(IsABoat(vehicleid) == 0 && IsABike(vehicleid) == 0 && IsAPlane(vehicleid) == 0 && IsAHelicopter(vehicleid) == 0 && IsAMotorBike(vehicleid) == 0)
		{
			SetVehicleNumberPlate(vehicleid, string);
			// veh3dserial[vehicleid-1] = CreateDynamic3DTextLabel(string, COLOR_WHITE, 0.0, -2.5, -0.5, 20.0, INVALID_PLAYER_ID, vehicleid, 0);
		}
	}

	format(string, sizeof(string), "[INFO:] Car id %d serial changed to %d", vehicleid, gVehData[vehicleid-1][CarSerial]);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);

	return 1;
}

dcmd_setcarserial(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] < 4)
		return 0;
	new vehicleid, serial;
	if(sscanf(params, "dd", vehicleid, serial))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /setcarserial [carid] [serial]");
		return 1;
	}
	gVehData[vehicleid-1][CarSerial] = serial;
	for(new i = 0; i < sizeof(gVehData); i++)
	{
		if(i != vehicleid-1)
		{
			if(gVehData[vehicleid-1][CarSerial] == gVehData[i][CarSerial])
			{
				SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Istnieje ju¿ pojazd z tak¹ rejestracj¹ !" );
				return 1;
			}
		}
	}

	SaveVehData(vehicleid-1, "CarSerial");

	new string[128];

	if(gVehData[vehicleid-1][CarSerial] < 10 && gVehData[vehicleid-1][CarSerial] > 0)
	{
		format(string, sizeof(string), "SA-000%d", gVehData[vehicleid-1][CarSerial]);
	}
	if(gVehData[vehicleid-1][CarSerial] > 10 && gVehData[vehicleid-1][CarSerial] < 100)
	{
		format(string, sizeof(string), "SA-00%d", gVehData[vehicleid-1][CarSerial]);
	}
	if(gVehData[vehicleid-1][CarSerial] > 100 && gVehData[vehicleid-1][CarSerial] < 1000)
	{
		format(string, sizeof(string), "SA-0%d", gVehData[vehicleid-1][CarSerial]);
	}
	if(gVehData[vehicleid-1][CarSerial] > 1000)
	{
		format(string, sizeof(string), "SA-%d", gVehData[vehicleid-1][CarSerial]);
	}

	// DestroyDynamic3DTextLabel( gVehData[vehicleid-1][Veh3DSerial] );

	if(gVehData[vehicleid-1][CarSerial] > 0)
	{
		if(IsAMotorBike(vehicleid) && gVehData[vehicleid][mVehModel] != 522 && gVehData[vehicleid][mVehModel] != 471 && gVehData[vehicleid][mVehModel] != 468)
		{
			// SetVehicleNumberPlate(vehicleid, string);
			//veh3dserial[vehicleid-1] = CreateDynamic3DTextLabel(string, COLOR_WHITE, 0.0, -1.0, 0.3, 20.0, INVALID_PLAYER_ID, vehicleid, 0);
		}
		if(gVehData[vehicleid][mVehModel] == 522 || gVehData[vehicleid][mVehModel] == 471 || gVehData[vehicleid][mVehModel] == 468)
		{
			gVehData[vehicleid-1][Veh3DSerial] = CreateDynamic3DTextLabel(string, COLOR_WHITE, 0.0, -1.0, 0.3, 20.0, INVALID_PLAYER_ID, vehicleid, 0);
		}
		if(IsABoat(vehicleid))
		{
			gVehData[vehicleid-1][Veh3DSerial] = CreateDynamic3DTextLabel(string, COLOR_WHITE, 0.0, 1.0, 0.2, 25.0, INVALID_PLAYER_ID, vehicleid, 0);
		}
		if(IsAPlane(vehicleid))
		{
			gVehData[vehicleid-1][Veh3DSerial] = CreateDynamic3DTextLabel(string, COLOR_WHITE, 0.0, 1.0, 0.2, 25.0, INVALID_PLAYER_ID, vehicleid, 0);
		}
		if(IsAHelicopter(vehicleid))
		{
			gVehData[vehicleid-1][Veh3DSerial] = CreateDynamic3DTextLabel(string, COLOR_WHITE, 0.0, -2.5, 0.9, 25.0, INVALID_PLAYER_ID, vehicleid, 0);
		}
		if(IsABoat(vehicleid) == 0 && IsABike(vehicleid) == 0 && IsAPlane(vehicleid) == 0 && IsAHelicopter(vehicleid) == 0 && IsAMotorBike(vehicleid) == 0)
		{
			SetVehicleNumberPlate(vehicleid, string);
			// veh3dserial[vehicleid-1] = CreateDynamic3DTextLabel(string, COLOR_WHITE, 0.0, -2.5, -0.5, 20.0, INVALID_PLAYER_ID, vehicleid, 0);
		}
	}

	format(string, sizeof(string), "[INFO:] Car id %d serial changed to %d", vehicleid, gVehData[vehicleid-1][CarSerial]);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);

	return 1;
}

dcmd_pktorganizacyjny(playerid, params[])
{
	#pragma unused params
	
	if(gPlayerData[playerid][pFaction] == 255)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie nale¿ysz do ¿adnej frakcji !");
		return 1;
	}
	
	if(gPlayerData[playerid][pAdmin] != 5)
	{
		if(gPlayerData[playerid][pRank] != 1)
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ liderem");
			return 1;
		}
		
		if(gPlayerVars[playerid][mAtBuildingId] == -1 && gPlayerVars[playerid][mAtHouseID] == -1)
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w swojej kryjówce");
			return 1;
		}
		
		if(Building[gPlayerVars[playerid][mAtBuildingId]][FactionOwnerId] != gPlayerData[playerid][pFaction] && gPlayerVars[playerid][mAtBuildingId] != -1)
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] To nie jest twoja kryjówka");
			return 1;
		}
	}
	
	GetPlayerPos(playerid, DynamicFactions[gPlayerData[playerid][pFaction]][fXDuty], DynamicFactions[gPlayerData[playerid][pFaction]][fYDuty], DynamicFactions[gPlayerData[playerid][pFaction]][fZDuty]);
	DynamicFactions[gPlayerData[playerid][pFaction]][fWorldDuty] = GetPlayerVirtualWorld(playerid);
	DynamicFactions[gPlayerData[playerid][pFaction]][fInteriorDuty] = GetPlayerInterior(playerid);
	
	SaveFData(gPlayerData[playerid][pFaction], "XDuty");
	SaveFData(gPlayerData[playerid][pFaction], "YDuty");
	SaveFData(gPlayerData[playerid][pFaction], "ZDuty");
	SaveFData(gPlayerData[playerid][pFaction], "WorldDuty");
	SaveFData(gPlayerData[playerid][pFaction], "InteriorDuty");

	DestroyDynamicPickup(DynamicFactions[gPlayerData[playerid][pFaction]][fCP]);
	DynamicFactions[gPlayerData[playerid][pFaction]][fCP] = CreateDynamicPickup(1239,1,DynamicFactions[gPlayerData[playerid][pFaction]][fXDuty],DynamicFactions[gPlayerData[playerid][pFaction]][fYDuty],DynamicFactions[gPlayerData[playerid][pFaction]][fZDuty],DynamicFactions[gPlayerData[playerid][pFaction]][fWorldDuty], DynamicFactions[gPlayerData[playerid][pFaction]][fInteriorDuty], -1, 10.0);

	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ustawi³eœ pierwszy punkt organizacyjny swojej frakcji");
	
	return 1;
}

dcmd_pktorganizacyjny2(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pFaction] == 255)
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie nale¿ysz do ¿adnej frakcji !");
		return 1;
	}
	
	if(gPlayerData[playerid][pAdmin] != 5)
	{
		if(gPlayerData[playerid][pRank] != 1)
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ liderem");
			return 1;
		}
		
		if(gPlayerVars[playerid][mAtBuildingId] == -1 && gPlayerVars[playerid][mAtHouseID] == -1)
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w swojej kryjówce");
			return 1;
		}
	}
	
	GetPlayerPos(playerid, DynamicFactions[gPlayerData[playerid][pFaction]][fXDuty2], DynamicFactions[gPlayerData[playerid][pFaction]][fYDuty2], DynamicFactions[gPlayerData[playerid][pFaction]][fZDuty2]);
	DynamicFactions[gPlayerData[playerid][pFaction]][fWorldDuty2] = GetPlayerVirtualWorld(playerid);
	DynamicFactions[gPlayerData[playerid][pFaction]][fInteriorDuty2] = GetPlayerInterior(playerid);

	SaveFData(gPlayerData[playerid][pFaction], "XDuty2");
	SaveFData(gPlayerData[playerid][pFaction], "YDuty2");
	SaveFData(gPlayerData[playerid][pFaction], "ZDuty2");
	SaveFData(gPlayerData[playerid][pFaction], "WorldDuty2");
	SaveFData(gPlayerData[playerid][pFaction], "InteriorDuty2");
	
	DestroyDynamicPickup(DynamicFactions[gPlayerData[playerid][pFaction]][fCP2]);
	DynamicFactions[gPlayerData[playerid][pFaction]][fCP2] = CreateDynamicPickup(1239,1,DynamicFactions[gPlayerData[playerid][pFaction]][fXDuty2],DynamicFactions[gPlayerData[playerid][pFaction]][fYDuty2],DynamicFactions[gPlayerData[playerid][pFaction]][fZDuty2],DynamicFactions[gPlayerData[playerid][pFaction]][fWorldDuty2], DynamicFactions[gPlayerData[playerid][pFaction]][fInteriorDuty2], -1, 10.0);

	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ustawi³eœ drugi punkt organizacyjny swojej frakcji");
	
	return 1;
}

dcmd_przebierzsie(playerid, params[])
{
	#pragma unused params
	
	if(gPlayerData[playerid][pFaction] == 255)
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie nale¿ysz do ¿adnej frakcji !");
		return 1;
	}
	
	new fid = gPlayerData[playerid][pFaction];
	
	if(DynamicFactions[fid][fType] == 0 || DynamicFactions[fid][fType] == 3)
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Niew³aœciwa frakcja");
		return 1;
	}
	
	if((PlayerToPoint(5.0, playerid, DynamicFactions[fid][fXDuty], DynamicFactions[fid][fYDuty], DynamicFactions[fid][fZDuty]) && GetPlayerVirtualWorld(playerid) == DynamicFactions[fid][fWorldDuty]) ||
		   (PlayerToPoint(5.0, playerid, DynamicFactions[fid][fXDuty2], DynamicFactions[fid][fYDuty2], DynamicFactions[fid][fZDuty2]) && GetPlayerVirtualWorld(playerid) == DynamicFactions[fid][fWorldDuty2]))
	{
		if(gPlayerData[playerid][pDuty])
		{
			gPlayerData[playerid][pDuty] = 0;
			SavePlayerData(playerid, "Duty");
			
			SetPlayerSkinEx(playerid, gPlayerData[playerid][pSkin]);

			PlayerActionMessage(playerid, 15.0, "przebiera i odmeldowuje siê z frakcji");

			return 1;
		}
		else 
		{
			gPlayerData[playerid][pDuty] = 1;
			SavePlayerData(playerid, "Duty");
			
			SetPlayerToFactionSkin(playerid);
			PlayerActionMessage(playerid, 15.0, "przebiera i zameldowuje siê do frakcji");
		}
	}
	return 1;
}

dcmd_givelev(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new giveplayerid, lvl;
	if(sscanf(params, "dd", giveplayerid, lvl))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /givelev [playerid] [lvl]");
		return 1;
	}
	gPlayerData[giveplayerid][pLevel] = lvl;
	SavePlayerData(giveplayerid, "Level");

	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Player level changed and saved");

	new string[128];
	format(string, sizeof(string), "[INFO:] Administrator %s zmieni³ level Twojej postaci na %d", gPlayerData[playerid][pOOCName], gPlayerData[giveplayerid][pLevel]);
	SendClientMessage(giveplayerid, COLOR_LIGHTYELLOW2, string);

	return 1;
}

dcmd_addlev(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new giveplayerid, lvl;
	if(sscanf(params, "dd", giveplayerid, lvl))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /addlev [playerid] [lvl]");
		return 1;
	}
	gPlayerData[giveplayerid][pLevel] += lvl;
	SavePlayerData(giveplayerid, "Level");

	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Player level changed and saved");

	new string[128];
	format(string, sizeof(string), "[INFO:] Administrator %s zmieni³ level Twojej postaci na %d", gPlayerData[playerid][pOOCName], gPlayerData[giveplayerid][pLevel]);
	SendClientMessage(giveplayerid, COLOR_LIGHTYELLOW2, string);

	return 1;
}

dcmd_giveexp(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new giveplayerid, exp;
	if(sscanf(params, "dd", giveplayerid, exp))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /giveexp [playerid] [exp]");
		return 1;
	}
	gPlayerData[giveplayerid][pExp] = exp;
	SavePlayerData(giveplayerid, "Exp");

	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Player exp changed and saved");

	new string[128];
	format(string, sizeof(string), "[INFO:] Administrator %s zmieni³ doœwiadczenie Twojej postaci na %d", gPlayerData[playerid][pOOCName], gPlayerData[giveplayerid][pExp]);
	SendClientMessage(giveplayerid, COLOR_LIGHTYELLOW2, string);

	return 1;
}

dcmd_addexp(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new giveplayerid, exp;
	if(sscanf(params, "dd", giveplayerid, exp))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /giveexp [playerid] [exp]");
		return 1;
	}
	gPlayerData[giveplayerid][pExp] += exp;
	SavePlayerData(giveplayerid, "Exp");

	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Player exp changed and saved");

	new string[128];
	format(string, sizeof(string), "[INFO:] Administrator %s zmieni³ doœwiadczenie Twojej postaci na %d", gPlayerData[playerid][pOOCName], gPlayerData[giveplayerid][pExp]);
	SendClientMessage(giveplayerid, COLOR_LIGHTYELLOW2, string);

	return 1;
}

dcmd_rfdata(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new string[128];
	format(string, sizeof(string), "SELECT HIGH_PRIORITY * FROM samp_factions ORDER BY `ID` ASC");
	wp_mysql_query(string, RELOAD_DYNAMIC_FACTIONS, INVALID_PLAYER_ID, db_con1);

	format(string, sizeof(string), "SELECT HIGH_PRIORITY * FROM samp_factions_weapons ORDER BY `FactionID` ASC");
	wp_mysql_query(string, LOAD_DYNAMIC_FACTIONS_WEAPONS, INVALID_PLAYER_ID, db_con2);

	format(string, sizeof(string), "SELECT HIGH_PRIORITY * FROM samp_factions_weapons2 ORDER BY `FactionID` ASC");
	wp_mysql_query(string, LOAD_DYNAMIC_FACTIONS_WEAPONS2, INVALID_PLAYER_ID, db_con2);

	format(string, sizeof(string), " SELECT HIGH_PRIORITY * FROM `samp_factions_payrank` ORDER BY `FactionID` ASC");
	wp_mysql_query(string, LOAD_FACTIONS_PAYRANK, INVALID_PLAYER_ID, db_con2);

	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Rozpoczêto odœwie¿anie danych frakcji");
	return 1;
}

dcmd_wl(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pPlayingHours] <= 4)
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz wy³¹czyæ limitera prêdkoœci dopóki nie przegrasz 5 godzin !");
		return 1;
	}
	if(gPlayerData[playerid][pSpeedLimiter])
	{
		gPlayerData[playerid][pSpeedLimiter] = 0;
		SavePlayerData(playerid, "SpeedLimiter");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Wy³¹czy³eœ limiter prêdkoœci");
		return 1;
	}
	if(!gPlayerData[playerid][pSpeedLimiter])
	{
		gPlayerData[playerid][pSpeedLimiter] = 1;
		SavePlayerData(playerid, "SpeedLimiter");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] W³¹czy³eœ limiter prêdkoœci");
		return 1;
	}
	return 1;
}

dcmd_statuspojazdow(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pBizKey] != 255)
	{
		new carS1[10];
		new carS2[10];
		new carS3[10];
		new carS4[10];
		new carS5[10];
		new carS6[10];
		new carS7[10];
		new carS8[10];
		new carS9[10];
		new carS10[10];
		new string[256];
		new k = 0;
		for(new i = 0; i < sizeof(gVehData); i++)
		{
			if(gVehData[i][BusinessID] == gPlayerData[playerid][pBizKey] && gVehData[i][mVehOwned] == 0 && gVehData[i][mVehFaction] == 255)
			{
				if(k == 0)
				{
					format(carS1, sizeof(carS1), "SA-%d", gVehData[i][CarSerial]);
					k++;
				}
				else if(k == 1)
				{
					format(carS2, sizeof(carS2), "SA-%d", gVehData[i][CarSerial]);
					k++;
				}
				else if(k == 2)
				{
					format(carS3, sizeof(carS3), "SA-%d", gVehData[i][CarSerial]);
					k++;
				}
				else if(k == 3)
				{
					format(carS4, sizeof(carS4), "SA-%d", gVehData[i][CarSerial]);
					k++;
				}
				else if(k == 4)
				{
					format(carS5, sizeof(carS5), "SA-%d", gVehData[i][CarSerial]);
					k++;
				}
				else if(k == 5)
				{
					format(carS6, sizeof(carS6), "SA-%d", gVehData[i][CarSerial]);
					k++;
				}
				else if(k == 6)
				{
					format(carS7, sizeof(carS7), "SA-%d", gVehData[i][CarSerial]);
					k++;
				}
				else if(k == 7)
				{
					format(carS8, sizeof(carS8), "SA-%d", gVehData[i][CarSerial]);
					k++;
				}
				else if(k == 8)
				{
					format(carS9, sizeof(carS9), "SA-%d", gVehData[i][CarSerial]);
					k++;
				}
				else if(k == 9)
				{
					format(carS10, sizeof(carS10), "SA-%d", gVehData[i][CarSerial]);
					k++;
					break;
				}
			}
		}
		format(string, sizeof(string), "1. %s \n 2. %s \n 3. %s \n 4. %s \n 5. %s \n 6. %s \n 7. %s \n 8. %s \n 9. %s \n 10. %s", carS1, carS2, carS3, carS4, carS5, carS6, carS7, carS8, carS9, carS10);
		ShowPlayerDialog(playerid,4,DIALOG_STYLE_LIST, "Rejestracje aut nie sprzedanych", string, "Zamknij", "Zamknij");
		return 1;
	}
	return 1;
}

dcmd_gcash(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new cash;
	if(sscanf(params, "d", cash))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /gcash [money]");
		return 1;
	}
	new string[128];
	format(string, sizeof(string), "UPDATE `samp_users` SET `Money` = %d", cash);
	wp_mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Rozpoczêto modyfikowanie iloœci pieniêdzy graczy");
	return 1;
}

dcmd_gbank(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new cash;
	if(sscanf(params, "d", cash))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /gbank [money]");
		return 1;
	}
	new string[128];
	format(string, sizeof(string), "UPDATE `samp_users` SET `Bank` = %d", cash);
	wp_mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Rozpoczêto modyfikowanie iloœci pieniêdzy graczy w banku");
	return 1;
}

dcmd_gbizcash(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] < 4)
		return 0;
	new cash;
	if(sscanf(params, "d", cash))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /gbizcash [money]");
		return 1;
	}
	new string[128];
	format(string, sizeof(string), "UPDATE `samp_businesses` SET `Till` = %d", cash);
	wp_mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Rozpoczêto modyfikowanie iloœci pieniêdzy w biznesach");
	return 1;
}

dcmd_gfaccash(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new cash;
	if(sscanf(params, "d", cash))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /gfaccash [money]");
		return 1;
	}
	new string[128];
	format(string, sizeof(string), "UPDATE `samp_factions` SET `Bank` = %d", cash);
	wp_mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Rozpoczêto modyfikowanie iloœci pieniêdzy we frakcjach");
	return 1;
}

dcmd_ghousecash(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new cash;
	if(sscanf(params, "d", cash))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /ghousecash [money]");
		return 1;
	}
	new string[128];
	format(string, sizeof(string), "UPDATE `samp_houses` SET `Bank` = %d", cash);
	wp_mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Rozpoczêto modyfikowanie iloœci pieniêdzy we frakcjach");
	return 1;
}

dcmd_pasy(playerid, params[])
{
	#pragma unused params
	if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
	{
		SendClientMessage(playerid,COLOR_GREY,"[INFO:] Musisz byæ w pojeŸdzie aby zapi¹æ pasy");
		return 1;
	}
	if(gPlayerData[playerid][pSeatBelt] == 1)
	{
		gPlayerData[playerid][pSeatBelt] = 0;

		new stringtosee[128];
		format(stringtosee, sizeof(stringtosee), "*** %s rozpi¹³ pas.", gPlayerData[playerid][pName]);
		ProxDetector(30.0, playerid, stringtosee, COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE);
		return 1;
	}
	gPlayerData[playerid][pSeatBelt] = 1;

	new stringtosee[128];
	format(stringtosee, sizeof(stringtosee), "*** %s zapi¹³ pas.", gPlayerData[playerid][pName]);
	ProxDetector(30.0, playerid, stringtosee, COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE);
	return 1;
}

dcmd_sprawdzpasy(playerid, params[])
{
	new giveplayerid;
	if(sscanf(params, "d", giveplayerid))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /sprawdzpasy [id gracza]");
		return 1;
	}
	if(gPlayerData[playerid][pFaction] == 255)
	{
		return 0;
	}
	if(DynamicFactions[gPlayerData[playerid][pFaction]][fType] == 1)
	{
		if(ProxDetectorS(9.0, playerid, giveplayerid))
		{
			if(gPlayerData[giveplayerid][pSeatBelt] == 0)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Pasy tej osoby nie s¹ zapiête");
				return 1;
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Pasy tej osoby s¹ zapiête");
				return 1;
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_GREY, "[INFO:] Ta osoba jest zbyt daleko od ciebie!");
			return 1;
		}
	}
	return 0;
}

dcmd_wdgaraz(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	if(IsPlayerInAnyVehicle(playerid))
	{
		SetVehicleToPos(GetPlayerVehicleID(playerid), -1979.3, 419.7, 24.5);
		SendClientMessage(playerid, COLOR_LSPD,"[SFPD:] Wjecha³eœ do gara¿u");
	}
	else
	{
		SetPlayerToPos(playerid, -1979.3, 419.7, 24.5);
		SendClientMessage(playerid, COLOR_LSPD,"[SFPD:] Wszed³eœ do gara¿u");
	}
	return 1;
}

dcmd_wzgaraz(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	if(IsPlayerInAnyVehicle(playerid))
	{
		SetVehicleToPos(GetPlayerVehicleID(playerid), -1979.3, 432.0, 25.4);
		SendClientMessage(playerid, 0xFF0000AA,"[SFPD:] Wyjecha³eœ z gara¿u ");
	}
	else
	{
		SetPlayerToPos(playerid, -1979.3, 432.0, 25.4);
		SendClientMessage(playerid, 0xFF0000AA,"[SFPD:] Wyszed³eœ z gara¿u");
	}
	return 1;
}

dcmd_loguj(playerid, params[])
{
	#pragma unused params
	if(gPlayerLogged[playerid] == 1)
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[SERVER:] Jesteœ ju¿ zalogowany.");
		return 1;
	}
	if(gPlayerData[playerid][pLoading] == 1)
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[SERVER:] Proces logowania w toku - czekaj...");
		return 1;
	}
	new string[1024];
	strcat( string, "{FFFFFF}Witaj na serwerze WParty !\n\n" );
	strcat( string, "Aby siê zalogowaæ wpisz swoje has³o do postaci.\n\n\n" );
	strcat( string, "{F52222}Jeœli nie posiadasz jeszcze postaci musisz wpierw zarejestrowaæ swoje konto\nna forum WParty.eu a nastêpnie utworzyæ postaæ\npostêpuj¹æ wed³ug podanych tam wskazówek.\n\n" );
	strcat( string, "{FAEC25}Jeœli zapomnia³eœ has³a do postaci mo¿esz je zmieniæ loguj¹c siê na forum\na nastêpnie przechodz¹c do panelu zarz¹dzania postaciami.\n\n\n" );
	strcat( string, "{FFFFFF}Wpisz has³o:" );
	ShowPlayerDialog(playerid, DIALOG_LOGIN, DIALOG_STYLE_PASSWORD, ""#COLOR_TITLE"Logowanie", string, "Zaloguj", "");
	return 1;
}

dcmd_l(playerid, params[])
{
	dcmd_loguj(playerid, params);
	return 1;
}

dcmd_unban(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] < 4)
		return 0;
	new plname[64];
	if(sscanf(params, "s", plname))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /unban [Imie_Nazwisko]");
		return 1;
	}
	new string[128];
	format(string, sizeof(string), "UPDATE `samp_users` SET `Banned` = '0' WHERE `PlayerName` = '%s'", plname);
	wp_mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Konto zosta³o odbanowane");
	return 1;
}

dcmd_opisdomu(playerid, params[])
{
	#pragma unused params
	SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Komenda zosta³ wy³aczona");
	return 1;
	// new id;
	// new dis[64];
	// new string[128];
	// if(gPlayerData[playerid][pFaction] != 9)
	// {
		// return 0;
	// }
	// if(sscanf(params, "ds[64]", id,dis))
	// {
		// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /opisdomu [houseid] [opis]");
		// return 1;
	// }
	// new idx = 0;
	// new length = strlen(dis);
	// while ((idx < length) && (dis[idx] <= ' '))
	// {
		// idx++;
	// }
	// new offset = idx;
	// new result[64];
	// while ((idx < length) && ((idx - offset) < (sizeof(result) - 1)))
	// {
		// result[idx - offset] = dis[idx];
		// idx++;
	// }
	// result[idx - offset] = EOS;
	// if(!strlen(result))
	// {
		// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /opisdomu [houseid] [opis]");
		// return 1;
	// }
	// new string2[256];
	// format(string2, sizeof(string2), "[GOVERNMENT:] House description changed by: %s, from %s to %s, house id: %d", gPlayerData[playerid][pName], Houses[id][Description], result, id);
	// GovermentLog(string2);
	// strmid(Houses[id][Description], (result), 0, strlen((result)), 64);
	// if(Houses[id][Owned] == 0)
	// {
		// format(string, sizeof(string), "Opis: %s, Cena: $%d",Houses[id][Description],Houses[id][HousePrice]);
		// UpdateDynamic3DTextLabelText(Houses3DTextLabelC[id], COLOR_LIGHTYELLOW2, string);
	// }
	// else
	// {
		// if(Houses[id][Rentable] == 1)
		// {
			// format(string, sizeof(string), "Opis: %s Czynsz: $%d (/wynajmijdom)",Houses[id][Description],Houses[id][RentCost]);
			// UpdateDynamic3DTextLabelText(Houses3DTextLabelC[id], COLOR_LIGHTYELLOW2, string);
		// }
		// else
		// {
			// format(string, sizeof(string), "Opis: %s",Houses[id][Description]);
			// UpdateDynamic3DTextLabelText(Houses3DTextLabelC[id], COLOR_LIGHTYELLOW2, string);
		// }
	// }
	// format(string, sizeof(string), "[INFO:] Ustawi³eœ opis domu: %d na %s", id,(result));
	// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);

	// SaveHouseData(id, "Description");
	// return 1;
}

dcmd_siad(playerid, params[])
{
	#pragma unused params
	SetPlayerSpecialAction(playerid,SPECIAL_ACTION_SITTING);
	return 1;
}

dcmd_zygaj1(playerid, params[])
{
	#pragma unused params
	ApplyAnimation(playerid,"FOOD","EAT_Vomit_P",4.1,0,1,1,0,0);
	return 1;
}

dcmd_zygaj2(playerid, params[])
{
	#pragma unused params
	ApplyAnimation(playerid,"FOOD","EAT_Vomit_SK",4.1,0,1,1,0,0);
	return 1;
}

dcmd_tancz1(playerid, params[])
{
	#pragma unused params
	ApplyAnimation(playerid,"DANCING","dance_loop",4.1,1,1,1,1,1);
	return 1;
}

dcmd_tancz2(playerid, params[])
{
	#pragma unused params
	ApplyAnimation(playerid,"DANCING","bd_clap",4.1,1,1,1,1,1);
	return 1;
}

dcmd_tancz3(playerid, params[])
{
	#pragma unused params
	ApplyAnimation(playerid,"DANCING","bd_clap1",4.1,1,1,1,1,1);
	return 1;
}

dcmd_tancz4(playerid, params[])
{
	#pragma unused params
	ApplyAnimation(playerid,"DANCING","DAN_Down_A",4.1,1,1,1,1,1);
	return 1;
}

dcmd_tancz5(playerid, params[])
{
	#pragma unused params
	ApplyAnimation(playerid,"DANCING","dnce_M_a",4.1,1,1,1,1,1);
	return 1;
}

dcmd_tancz6(playerid, params[])
{
	#pragma unused params
	ApplyAnimation(playerid,"DANCING","dnce_M_b",4.1,1,1,1,1,1);
	return 1;
}

dcmd_tancz7(playerid, params[])
{
	#pragma unused params
	ApplyAnimation(playerid,"DANCING","dnce_M_c",4.1,1,1,1,1,1);
	return 1;
}

dcmd_rejestruj(playerid, params[])
{
	#pragma unused params
	SendClientMessage(playerid, COLOR_RED, "Aby stworzyæ konto na tym serwerze musisz zarejestrowaæ siê na stronie");
	SendClientMessage(playerid, COLOR_RED, "WParty.eu a nastepnie tam przez odpowiedni link stworzyæ konto");
	return 1;
}

dcmd_asellerjobpos(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] < 4)
		return 0;
	new Float:x, Float:y, Float:z;
	GetPlayerPos(playerid, x, y, z);
	new Float:angle;
	GetPlayerFacingAngle(playerid, angle);
	SellerJob[TakeJobX] = x;
	SellerJob[TakeJobY] = y;
	SellerJob[TakeJobZ] = z;
	SellerJob[TakeJobWorld]= GetPlayerVirtualWorld(playerid);
	SellerJob[TakeJobInterior] = GetPlayerInterior(playerid);
	SellerJob[TakeJobAngle] = angle;
	SellerJob[TakeJobPickupID] = ChangePickupModel(SellerJob[TakeJobPickupID],1239, SellerJob[TakeJobX], SellerJob[TakeJobY], SellerJob[TakeJobZ]);
	SaveSellerJob();
	SendClientMessage(playerid, COLOR_ADMINCMD, "You have successfully set the Seller Job Position.");
	return 1;
}

dcmd_aaccountantjobpos(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] < 4)
		return 0;
	new Float:x, Float:y, Float:z;
	GetPlayerPos(playerid, x, y, z);
	new Float:angle;
	GetPlayerFacingAngle(playerid, angle);
	AccountantJob[TakeJobX] = x;
	AccountantJob[TakeJobY] = y;
	AccountantJob[TakeJobZ] = z;
	AccountantJob[TakeJobWorld]= GetPlayerVirtualWorld(playerid);
	AccountantJob[TakeJobInterior] = GetPlayerInterior(playerid);
	AccountantJob[TakeJobAngle] = angle;
	AccountantJob[TakeJobPickupID] = ChangePickupModel(AccountantJob[TakeJobPickupID],1239, AccountantJob[TakeJobX], AccountantJob[TakeJobY], AccountantJob[TakeJobZ]);
	SaveAccountantJob();
	SendClientMessage(playerid, COLOR_ADMINCMD, "You have successfully set the Accountant Job Position.");
	return 1;
}

dcmd_ww(playerid, params[])
{
	#pragma unused params
	
	if(gPlayerData[playerid][pFaction] == 255)
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie nale¿ysz do ¿adnej frakcji");
		return 1;
	}
	
	if(DynamicFactions[gPlayerData[playerid][pFaction]][fType] != FACTIONT_POLICE)
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Niew³aœciwy typ frakcji");
		return 1;
	}
	
	new Float:x, Float:y, Float:z, slot[MAX_PLAYER_ITEM_SLOT], gpsOn;
	GetPlayerPos(playerid, x, y, z);
	
	PHaveItemEx(playerid, 3, 12, slot);
	for(new i = 0; i < MAX_PLAYER_ITEM_SLOT; i++)
	{
		if(slot[i] && SlotParam1(playerid, i+1))
		{
			gpsOn = 1;
		}
	}
	
	for(new i = 0; i < CUSTOM_MAX_PLAYERS; i++)
	{
		if(gPlayerData[i][pFaction] == 255 || !gpsOn)
		{
			continue;
		}
		
		if(DynamicFactions[gPlayerData[i][pFaction]][fType] != FACTIONT_POLICE)
		{
			continue;
		}
		
		SetPlayerCheckpoint(i, x, y, z, 10.0);
		defer ClearCheckpointsForPlayer(playerid);
	}
	
	new string[128];
	new location[MAX_ZONE_NAME];
	GetPlayer2DZone(playerid, location, MAX_ZONE_NAME);
	format(string, sizeof(string), "[SFPD:] Funkcjonariusz %s potrzebuje wsparcia przy %s", gPlayerData[playerid][pName], location);
	SendFactionTypeMessage(1, COLOR_LSPD, string);
	
	return 1;
}

dcmd_zmienrejestracje(playerid, params[])
{
	new giveplayerid, id, sn, string[256];
	if(gPlayerData[playerid][pFaction] != 9 && !AdminDuty[playerid])
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Niew³aœciwa frakcja !");
		return 1;
	}
	if(sscanf(params, "ddd", giveplayerid, id, sn))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /zmienrejestracje [id wlasciciela] [aktualna rejestracja] [nowa rejestracja]");
		return 1;
	}

	id = CarSerialToID(id);
	new slot = PHaveItem(giveplayerid, 2, gVehData[id][CarSerial]);
	if(slot > 0)
	{
		if(sn < 0 && sn > 2000)
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nr rejestracj nie mo¿e byæ mniejszy od 0 i wiêkszy od 2000");
			return 1;
		}
		for(new i = 0; i < sizeof(gVehData); i++)
		{
			if(i != id) // sprawdzenie czy inny pojazd nie posiada juz takiej rejestracji
			{
				if(gVehData[id][CarSerial] == sn)
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ta rejestracja jest ju¿ przypisana do innego pojazdu !");
					return 1;
				}
			}
		}
		gVehData[id][CarSerial] = sn;
		SaveVehData(id, "CarSerial");
		
		ChangeItem(giveplayerid, slot, sn); // zamiana parametru pItem na obecna rejestracje

		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Rejestracja pojazdu zosta³a zmieniona !");
		new tmpcar = id;
		// DestroyDynamic3DTextLabel( gVehData[tmpcar][Veh3DSerial]);

		if(gVehData[tmpcar][CarSerial] < 10)
		{
			format(string, sizeof(string), "SA-000%d", gVehData[tmpcar][CarSerial]);
		}
		if(gVehData[tmpcar][CarSerial] > 10 && gVehData[tmpcar][CarSerial] < 100)
		{
			format(string, sizeof(string), "SA-00%d", gVehData[tmpcar][CarSerial]);
		}
		if(gVehData[tmpcar][CarSerial] > 100 && gVehData[tmpcar][CarSerial] < 1000)
		{
			format(string, sizeof(string), "SA-0%d", gVehData[tmpcar][CarSerial]);
		}
		if(gVehData[tmpcar][CarSerial] > 1000)
		{
			format(string, sizeof(string), "SA-%d", gVehData[tmpcar][CarSerial]);
		}
		if(IsAMotorBike(tmpcar+1) && gVehData[tmpcar][mVehModel] != 522 && gVehData[tmpcar][mVehModel] != 471 && gVehData[tmpcar][mVehModel] != 468)
		{
			SetVehicleNumberPlate(tmpcar+1, string);
		}
		if(gVehData[tmpcar][mVehModel] == 522 || gVehData[tmpcar][mVehModel] == 471 || gVehData[tmpcar][mVehModel] == 468)
		{
			gVehData[tmpcar][Veh3DSerial] = CreateDynamic3DTextLabel(string, COLOR_WHITE, 0.0, -1.0, 0.3, 20.0, INVALID_PLAYER_ID, tmpcar+1, 0);
		}
		else if(IsABoat(tmpcar+1))
		{
			gVehData[tmpcar][Veh3DSerial] = CreateDynamic3DTextLabel(string, COLOR_WHITE, 0.0, 1.0, 0.2, 25.0, INVALID_PLAYER_ID, tmpcar+1, 0);
		}
		else if(IsAPlane(tmpcar+1))
		{
			gVehData[tmpcar][Veh3DSerial] = CreateDynamic3DTextLabel(string, COLOR_WHITE, 0.0, 1.0, 0.2, 25.0, INVALID_PLAYER_ID, tmpcar+1, 0);
		}
		else if(IsAHelicopter(tmpcar+1))
		{
			gVehData[tmpcar][Veh3DSerial] = CreateDynamic3DTextLabel(string, COLOR_WHITE, 0.0, -2.5, 0.9, 25.0, INVALID_PLAYER_ID, tmpcar+1, 0);
		}
		else if(IsABoat(tmpcar+1) == 0 && IsABike(tmpcar+1) == 0 && IsAPlane(tmpcar+1) == 0 && IsAHelicopter(tmpcar+1) == 0 && IsAMotorBike(tmpcar+1) == 0)
		{
			SetVehicleNumberPlate(tmpcar+1, string);
		}
		
		format(string, sizeof(string), "[WARNING:] Vehicle [%d] serial [%d] has been changed to [%d] by %s", id+1, gVehData[id][CarSerial], gPlayerData[playerid][pName]); 
		GovermentLog(string);
	}
	else
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ta osoba nie posiada kluczyków do auta o tej rejestracji");
	}
	return 1;
}

dcmd_wejdznaskocznie(playerid, params[])
{
	#pragma unused params
	if(PlayerToPoint(2.0, playerid, 578.6855, -2195.5337, 1.6288))
	{
		SetPlayerToPos(playerid, 578.5896, -2194.7065, 7.1380);
	}
	else
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ przy skoczni !");
	}
	return 1;
}

dcmd_stanpojazdu(playerid, params[])
{
	if(gPlayerData[playerid][pJob] == 17)
	{
		new Float:vHP, serial, id;
		if(sscanf(params, "d", serial))
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /stanpojazdu [nr rejestracji]");
			return 1;
		}
		id = CarSerialToID(serial);
		GetVehicleHealth(id+1,vHP);
		new string[128];
		format(string, sizeof(string), "Stan pojazdu: %.1f/1000.0", vHP);
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
		return 1;
	}
	return 0;
}

/*dcmd_wezpilke(playerid, params[])
{
	#pragma unused params
	if(PlayerToPoint(3.0, playerid, 598.0, -2149.0, 2.0))
	{
		CreateDynamicObject(1598, 598.0, -2149.0, 2.0, 0.0, 0.0, 90.0, -1, -1, -1, 300.0);
		return 1;
	}
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Musisz byæ na basenie obok szafki z przedmiotami");
	return 1;
}*/

dcmd_apjob(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] < 4)
		return 0;
	new jobid, giveplayerid;
	if(sscanf(params, "dd", giveplayerid, jobid))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /apjob [playerid] [jobid]");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "1 - Diler broni , 2 - Diler narkotyków , 3 - Detektyw , 4 - Prawnik, 5 - Sprzedawca produktów");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "6 - Praca dziwki , 7 - Boxer , 8 - Gwa³ciciel , 9 - Ochroniarz , 10 - Z³odziej samochodów ,");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "11 - Kaskader , 12 - Re¿yser , 13 - Kierowca autobusu , 14 - Kierowca œmieciarki , 1");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "5 - Kierowca myjki drogowej , 16 - Taksówkarz , 17 - Mechanik , 18 - Farmer , 19 - Sprzedawca/ekspedient ");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "20 - Ksiêgowy , 21 - newsman , 22 - workerfactory");
		return 1;
	}
	gPlayerData[giveplayerid][pJob] = jobid;
	SavePlayerData(giveplayerid, "Job");

	SendClientMessage(playerid, COLOR_GREEN, "[INFO:] Player job changed");

	return 1;
}

dcmd_przedstawrozliczenie(playerid, params[])
{
	if(gPlayerData[playerid][pJob] != 20)
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ ksiêgowym !");
		return 1;
	}
	new giveplayerid, cost;
	if(sscanf(params, "dd", giveplayerid, cost))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /przedstawrozliczenie [id gracza] [cena]");
		return 1;
	}
	if(IsPlayerConnected(giveplayerid))
	{
		if(ProxDetectorS(5.0, playerid, giveplayerid))
		{
			AccountantOffer[giveplayerid] = playerid;
			AccountantCost[giveplayerid] = cost;
			new string[128];
			format(string, sizeof(string), "[INFO:] Zaoferowano Tobie kosztorys za kwote $%d (/akceptuj kosztorys)", cost);
			SendClientMessage(giveplayerid, COLOR_LIGHTYELLOW2, string);
			format(string, sizeof(string), "[INFO:] Przedstawi³eœ propozycje kosztorysu dla %s", gPlayerData[giveplayerid][pName]);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			return 1;
		}
		else
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Jesteœ zbyt daleko od tej osoby !");
			return 1;
		}
	}
	else
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Gracz nie jest po³¹czony !");
		return 1;
	}
}

dcmd_vehdamage(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new vehicleid, mydoors;
	if(sscanf(params, "dd", vehicleid, mydoors))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /vehdamagedoor [veh id] [biteset]");
	}
	new panels,doors,lights,tires;
	GetVehicleDamageStatus(vehicleid,panels,doors,lights,tires);
	printf("panels: %b, doors: %b, lights: %b", panels, doors, lights);
	UpdateVehicleDamageStatus(vehicleid,panels,mydoors,lights,tires);
	return 1;
}

dcmd_explodencars(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new Float:Xcar, Float:Ycar, Float:Zcar;
	for(new i = 0; i < sizeof(gVehData); i++)
	{
		GetVehiclePos(i+1, Xcar, Ycar, Zcar);
		if(PlayerToPoint(10.0, playerid, Xcar, Ycar, Zcar))
		{
			DestroyVehicle(i+1);

			defer ResetVehicleData(i+1,1);
		}
	}
	return 1;
}
/*
dcmd_montazgazu(playerid, params[])
{
	if(gPlayerData[playerid][pJob] != 17)
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie jesteœ mechanikiem !");
		return 1;
	}
	new serial;
	if(sscanf(params, "d", serial))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /montazgazu [rejestracja pojazdu]");
		return 1;
	}
	new id = CarSerialToID(serial);
	if(id == -1)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie ma pojazdu o takiej rejestracji ");
		return 1;
	}
	new pToGas = 0;
	for(new i = 0; i < sizeof(CarsData); i++)
	{
		if(CarsData[i][Model] == gVehData[id][mVehModel])
		{
			if(CarsData[i][ToGas])
			{
				pToGas = 1;
				break;
			}
		}
	}
	if(pToGas == 0)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Tego samochodu nie mo¿na przerobiæ na gaz");
		return 1;
	}
	GetVehiclePos(id+1, gVehData[id][mVehX], gVehData[id][mVehY], gVehData[id][mVehZ]);
	if(isGasMounting[id])
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Musisz ukoñczyæ wpierw poprzedni¹ czynnoœæ by przejœæ do nastêpnej, b¹dŸ cierpliwy");
		return 1;
	}
	if(gVehData[id][Fuel] == 2)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ten pojazd jest ju¿ wyposa¿ony w instalacje gazow¹");
		return 1;
	}
	if(gVehData[id][GasStep] == 0)
	{
		if(!PlayerToPoint(15.0, playerid, gVehData[id][mVehX], gVehData[id][mVehY], gVehData[id][mVehZ]))
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Jesteœ zbyt daleko od pojazdu !");
			return 1;
		}
		PlayerActionMessage(playerid, 15.0, "podchodzi do pojazdu, szuka dogodnego miejsca do zamontowania zbiornika");
		gVehData[id][GasStep] = 1;

		SaveVehData(id, "GasStep");
		return 1;
	}
	if(gVehData[id][GasStep] == 1)
	{
		if(!PlayerToPoint(5.0, playerid, gVehData[id][mVehX], gVehData[id][mVehY], gVehData[id][mVehZ]))
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Jesteœ zbyt daleko od pojazdu !");
			return 1;
		}
		PlayerActionMessage(playerid, 15.0, "przygotowuje miejsce");
		gVehData[id][GasStep] = 2;
		isGasMounting[id] = 1;
		gVehData[id][CarDamaged] = 1;
		defer GasChangingTimer[5000](id);

		SaveVehData(id, "GasStep");
		SaveVehData(id, "CarDamaged");
		return 1;
	}
	if(gVehData[id][GasStep] == 2)
	{
		if(!PlayerToPoint(5.0, playerid, gVehData[id][mVehX], gVehData[id][mVehY], gVehData[id][mVehZ]))
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Jesteœ zbyt daleko od pojazdu !");
			return 1;
		}
		PlayerActionMessage(playerid, 15.0, "montuje zbiornik");
		gVehData[id][GasStep] = 3;
		isGasMounting[id] = 1;
		gVehData[id][CarDamaged] = 1;
		defer GasChangingTimer[20000](id);

		SaveVehData(id, "GasStep");
		SaveVehData(id, "CarDamaged");
		return 1;
	}
	if(gVehData[id][GasStep] == 3)
	{
		if(!PlayerToPoint(5.0, playerid, gVehData[id][mVehX], gVehData[id][mVehY], gVehData[id][mVehZ]))
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Jesteœ zbyt daleko od pojazdu !");
			return 1;
		}
		PlayerActionMessage(playerid, 15.0, "montuje wskaznik na desce rozdzieczej");
		gVehData[id][GasStep] = 4;
		isGasMounting[id] = 1;
		gVehData[id][CarDamaged] = 1;
		defer GasChangingTimer[10000](id);

		SaveVehData(id, "GasStep");
		SaveVehData(id, "CarDamaged");
		return 1;
	}
	if(gVehData[id][GasStep] == 4)
	{
		if(!PlayerToPoint(5.0, playerid, gVehData[id][mVehX], gVehData[id][mVehY], gVehData[id][mVehZ]))
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Jesteœ zbyt daleko od pojazdu !");
			return 1;
		}
		PlayerActionMessage(playerid, 15.0, "sprzata pozostalosci, sprawdza instalacje");
		gVehData[id][GasStep] = 5;
		isGasMounting[id] = 1;
		gVehData[id][CarDamaged] = 1;
		defer GasChangingTimer[20000](id);

		SaveVehData(id, "GasStep");
		SaveVehData(id, "CarDamaged");
		return 1;
	}
	if(gVehData[id][GasStep] == 5)
	{
		if(!PlayerToPoint(5.0, playerid, gVehData[id][mVehX], gVehData[id][mVehY], gVehData[id][mVehZ]))
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Jesteœ zbyt daleko od pojazdu !");
			return 1;
		}
		PlayerActionMessage(playerid, 15.0, "koñczy prace");
		gVehData[id][GasStep] = 0;
		gVehData[id][CarDamaged] = 0;
		gVehData[id][Fuel] = 2;
		gVehData[id][CarFuel] = 10.0;
		// TODO: Cash is going nowhere. Fix this...
		GivePlayerCash(playerid, -2500);

		SaveVehData(id, "GasStep");
		SaveVehData(id, "CarDamaged");
		SaveVehData(id, "Fuel");
		SaveVehData(id, "CarFuel");
		return 1;
	}
	return 1;
}*/
/*
dcmd_wymianaopon(playerid, params[])
{
	if(gPlayerData[playerid][pJob] != 17)
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie jesteœ mechanikiem !");
		return 1;
	}
	new serial;
	if(sscanf(params, "d", serial))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /wymianaopon [rejestracja pojazdu]");
		return 1;
	}
	new id = CarSerialToID(serial);
	if(id == -1)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie ma pojazdu o takiej rejestracji ");
		return 1;
	}
	new Float:x, Float:y, Float:z;
	GetVehiclePos(id+1, x, y, z);

	if(isWheelChanging[id])
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Musisz ukoñczyæ odkrêcanie ko³a/wymiane opony zanim przejdziesz do nastêpnej opony !");
		return 1;
	}
	// lewe przednie
	if(gVehData[id][WheelStep] == 0)
	{
		if(!PlayerToPoint(15.0, playerid, x, y, z))
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Jesteœ zbyt daleko od pojazdu !");
			return 1;
		}
		PlayerActionMessage(playerid, 15.0, "podchodzi do lewego przedniego ko³a");
		gVehData[id][WheelStep] = 1;

		SaveVehData(id, "WheelStep");
		return 1;
	}
	if(gVehData[id][WheelStep] == 1)
	{
		if(!PlayerToPoint(5.0, playerid, x, y, z))
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Jesteœ zbyt daleko od pojazdu !");
			return 1;
		}
		PlayerActionMessage(playerid, 15.0, "luzuje nakrêtki");
		gVehData[id][WheelStep] = 2;
		isWheelChanging[id] = 1;
		gVehData[id][CarDamaged] = 1;
		defer WheelChangingTimer[20000](id);

		SaveVehData(id, "WheelStep");
		SaveVehData(id, "CarDamaged");
		return 1;
	}
	if(gVehData[id][WheelStep] == 2)
	{
		if(!PlayerToPoint(5.0, playerid, x, y, z))
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Jesteœ zbyt daleko od pojazdu !");
			return 1;
		}
		PlayerActionMessage(playerid, 15.0, "podnosi pojazd");
		gVehData[id][WheelStep] = 3;
		isWheelChanging[id] = 1;
		gVehData[id][CarDamaged] = 1;
		defer WheelChangingTimer[15000](id);

		SaveVehData(id, "WheelStep");
		SaveVehData(id, "CarDamaged");
		return 1;
	}
	if(gVehData[id][WheelStep] == 3)
	{
		if(!PlayerToPoint(5.0, playerid, x, y, z))
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Jesteœ zbyt daleko od pojazdu !");
			return 1;
		}
		PlayerActionMessage(playerid, 15.0, "odkrêca lewe przednie ko³o");
		gVehData[id][WheelStep] = 4;
		isWheelChanging[id] = 1;
		gVehData[id][CarDamaged] = 1;
		defer WheelChangingTimer[25000](id);

		SaveVehData(id, "WheelStep");
		SaveVehData(id, "CarDamaged");
		return 1;
	}
	if(gVehData[id][WheelStep] == 4)
	{
		if(!PlayerToPoint(5.0, playerid, x, y, z))
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Jesteœ zbyt daleko od pojazdu !");
			return 1;
		}
		PlayerActionMessage(playerid, 15.0, "idzie do warsztatu");
		gVehData[id][WheelStep] = 5;

		SaveVehData(id, "WheelStep");
		return 1;
	}
	if(gVehData[id][WheelStep] == 5)
	{
		if(!isInWheelChangePoint(playerid))
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w punkcie wymiany opon !");
			return 1;
		}
		PlayerActionMessage(playerid, 15.0, "wymienia opone");
		gVehData[id][WheelStep] = 6;
		isWheelChanging[id] = 1;
		defer WheelChangingTimer[40000](id);

		SaveVehData(id, "WheelStep");
		return 1;
	}
	if(gVehData[id][WheelStep] == 6)
	{
		if(!isInWheelChangePoint(playerid))
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w punkcie wymiany opon !");
			return 1;
		}
		PlayerActionMessage(playerid, 15.0, "zabiera ko³o i idzie do samochodu");
		gVehData[id][WheelStep] = 7;

		SaveVehData(id, "WheelStep");
		return 1;
	}
	if(gVehData[id][WheelStep] == 7)
	{
		if(!PlayerToPoint(5.0, playerid, x, y, z))
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Jesteœ zbyt daleko od pojazdu !");
			return 1;
		}
		PlayerActionMessage(playerid, 15.0, "zak³ada ko³o");
		gVehData[id][WheelStep] = 8;
		isWheelChanging[id] = 1;
		defer WheelChangingTimer[25000](id);

		SaveVehData(id, "WheelStep");
		return 1;
	}
	if(gVehData[id][WheelStep] == 8)
	{
		if(!PlayerToPoint(5.0, playerid, x, y, z))
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Jesteœ zbyt daleko od pojazdu !");
			return 1;
		}
		PlayerActionMessage(playerid, 15.0, "opuszcza pojazd i przykrêca ko³o");
		gVehData[id][WheelStep] = 9;
		isWheelChanging[id] = 1;
		gVehData[id][CarDamaged] = 1;
		defer WheelChangingTimer[50000](id);

		SaveVehData(id, "WheelStep");
		SaveVehData(id, "CarDamaged");
		return 1;
	}
	// prawe przednie
	if(gVehData[id][WheelStep] == 9)
	{
		if(!PlayerToPoint(15.0, playerid, x, y, z))
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Jesteœ zbyt daleko od pojazdu !");
			return 1;
		}
		PlayerActionMessage(playerid, 15.0, "podchodzi do prawego przedniego ko³a");
		gVehData[id][WheelStep] = 10;

		SaveVehData(id, "WheelStep");
		return 1;
	}
	if(gVehData[id][WheelStep] == 10)
	{
		if(!PlayerToPoint(5.0, playerid, x, y, z))
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Jesteœ zbyt daleko od pojazdu !");
			return 1;
		}
		PlayerActionMessage(playerid, 15.0, "luzuje nakrêtki");
		gVehData[id][WheelStep] = 11;
		isWheelChanging[id] = 1;
		gVehData[id][CarDamaged] = 1;
		defer WheelChangingTimer[20000](id);

		SaveVehData(id, "WheelStep");
		SaveVehData(id, "CarDamaged");
		return 1;
	}
	if(gVehData[id][WheelStep] == 11)
	{
		if(!PlayerToPoint(5.0, playerid, x, y, z))
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Jesteœ zbyt daleko od pojazdu !");
			return 1;
		}
		PlayerActionMessage(playerid, 15.0, "podnosi pojazd");
		gVehData[id][WheelStep] = 12;
		isWheelChanging[id] = 1;
		gVehData[id][CarDamaged] = 1;
		defer WheelChangingTimer[15000](id);

		SaveVehData(id, "WheelStep");
		SaveVehData(id, "CarDamaged");
		return 1;
	}
	if(gVehData[id][WheelStep] == 12)
	{
		if(!PlayerToPoint(5.0, playerid, x, y, z))
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Jesteœ zbyt daleko od pojazdu !");
			return 1;
		}
		PlayerActionMessage(playerid, 15.0, "odkrêca prawe przednie ko³o");
		gVehData[id][WheelStep] = 13;
		isWheelChanging[id] = 1;
		defer WheelChangingTimer[25000](id);

		SaveVehData(id, "WheelStep");
		return 1;
	}
	if(gVehData[id][WheelStep] == 13)
	{
		if(!PlayerToPoint(5.0, playerid, x, y, z))
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Jesteœ zbyt daleko od pojazdu !");
			return 1;
		}
		PlayerActionMessage(playerid, 15.0, "idzie do warsztatu");
		gVehData[id][WheelStep] = 14;

		SaveVehData(id, "WheelStep");
		return 1;
	}
	if(gVehData[id][WheelStep] == 14)
	{
		if(!isInWheelChangePoint(playerid))
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w punkcie wymiany opon !");
			return 1;
		}
		PlayerActionMessage(playerid, 15.0, "wymienia opone");
		gVehData[id][WheelStep] = 15;
		isWheelChanging[id] = 1;
		defer WheelChangingTimer[40000](id);

		SaveVehData(id, "WheelStep");
		return 1;
	}
	if(gVehData[id][WheelStep] == 15)
	{
		if(!isInWheelChangePoint(playerid))
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w punkcie wymiany opon !");
			return 1;
		}
		PlayerActionMessage(playerid, 15.0, "zabiera prawe przednie ko³o i idzie do samochodu");
		gVehData[id][WheelStep] = 16;

		SaveVehData(id, "WheelStep");
		return 1;
	}
	if(gVehData[id][WheelStep] == 16)
	{
		if(!PlayerToPoint(5.0, playerid, x, y, z))
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Jesteœ zbyt daleko od pojazdu !");
			return 1;
		}
		PlayerActionMessage(playerid, 15.0, "zak³ada prawe przednie ko³o");
		gVehData[id][WheelStep] = 17;
		isWheelChanging[id] = 1;
		defer WheelChangingTimer[25000](id);

		SaveVehData(id, "WheelStep");
		return 1;
	}
	if(gVehData[id][WheelStep] == 17)
	{
		if(!PlayerToPoint(5.0, playerid, x, y, z))
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Jesteœ zbyt daleko od pojazdu !");
			return 1;
		}
		PlayerActionMessage(playerid, 15.0, "opuszcza pojazd i przykrêca ko³o");
		gVehData[id][WheelStep] = 18;
		isWheelChanging[id] = 1;
		gVehData[id][CarDamaged] = 1;
		defer WheelChangingTimer[50000](id);

		SaveVehData(id, "WheelStep");
		SaveVehData(id, "CarDamaged");
		return 1;
	}
	// tylne lewe
	if(gVehData[id][WheelStep] == 18)
	{
		if(!PlayerToPoint(15.0, playerid, x, y, z))
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Jesteœ zbyt daleko od pojazdu !");
			return 1;
		}
		PlayerActionMessage(playerid, 15.0, "podchodzi do lewego tylnego ko³a");
		gVehData[id][WheelStep] = 19;

		SaveVehData(id, "WheelStep");
		return 1;
	}
	if(gVehData[id][WheelStep] == 19)
	{
		if(!PlayerToPoint(5.0, playerid, x, y, z))
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Jesteœ zbyt daleko od pojazdu !");
			return 1;
		}
		PlayerActionMessage(playerid, 15.0, "luzuje nakrêtki");
		gVehData[id][WheelStep] = 20;
		isWheelChanging[id] = 1;
		gVehData[id][CarDamaged] = 1;
		defer WheelChangingTimer[20000](id);

		SaveVehData(id, "WheelStep");
		SaveVehData(id, "CarDamaged");
		return 1;
	}
	if(gVehData[id][WheelStep] == 20)
	{
		if(!PlayerToPoint(5.0, playerid, x, y, z))
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Jesteœ zbyt daleko od pojazdu !");
			return 1;
		}
		PlayerActionMessage(playerid, 15.0, "podnosi pojazd");
		gVehData[id][WheelStep] = 21;
		isWheelChanging[id] = 1;
		gVehData[id][CarDamaged] = 1;
		defer WheelChangingTimer[15000](id);

		SaveVehData(id, "WheelStep");
		SaveVehData(id, "CarDamaged");
		return 1;
	}
	if(gVehData[id][WheelStep] == 21)
	{
		if(!PlayerToPoint(5.0, playerid, x, y, z))
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Jesteœ zbyt daleko od pojazdu !");
			return 1;
		}
		PlayerActionMessage(playerid, 15.0, "odkrêca lewe tylne ko³o");
		gVehData[id][WheelStep] = 22;
		isWheelChanging[id] = 1;
		defer WheelChangingTimer[25000](id);

		SaveVehData(id, "WheelStep");
		return 1;
	}
	if(gVehData[id][WheelStep] == 22)
	{
		if(!PlayerToPoint(5.0, playerid, x, y, z))
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Jesteœ zbyt daleko od pojazdu !");
			return 1;
		}
		PlayerActionMessage(playerid, 15.0, "idzie do warsztatu");
		gVehData[id][WheelStep] = 23;

		SaveVehData(id, "WheelStep");
		return 1;
	}
	if(gVehData[id][WheelStep] == 23)
	{
		if(!isInWheelChangePoint(playerid))
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w punkcie wymiany opon !");
			return 1;
		}
		PlayerActionMessage(playerid, 15.0, "wymienia opone");
		gVehData[id][WheelStep] = 24;
		isWheelChanging[id] = 1;
		defer WheelChangingTimer[40000](id);

		SaveVehData(id, "WheelStep");
		return 1;
	}
	if(gVehData[id][WheelStep] == 24)
	{
		if(!isInWheelChangePoint(playerid))
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w punkcie wymiany opon !");
			return 1;
		}
		PlayerActionMessage(playerid, 15.0, "zabiera lewe tylne ko³o i idzie do samochodu");
		gVehData[id][WheelStep] = 25;

		SaveVehData(id, "WheelStep");
		return 1;
	}
	if(gVehData[id][WheelStep] == 25)
	{
		if(!PlayerToPoint(5.0, playerid, x, y, z))
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Jesteœ zbyt daleko od pojazdu !");
			return 1;
		}
		PlayerActionMessage(playerid, 15.0, "zak³ada lewe tylne ko³o");
		gVehData[id][WheelStep] = 26;
		isWheelChanging[id] = 1;
		defer WheelChangingTimer[25000](id);

		SaveVehData(id, "WheelStep");
		return 1;
	}
	if(gVehData[id][WheelStep] == 26)
	{
		if(!PlayerToPoint(5.0, playerid, x, y, z))
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Jesteœ zbyt daleko od pojazdu !");
			return 1;
		}
		PlayerActionMessage(playerid, 15.0, "opuszcza pojazd i przykrêca ko³o");
		gVehData[id][WheelStep] = 27;
		isWheelChanging[id] = 1;
		gVehData[id][CarDamaged] = 1;
		defer WheelChangingTimer[50000](id);

		SaveVehData(id, "WheelStep");
		SaveVehData(id, "CarDamaged");
		return 1;
	}
	// prawe tylne
	if(gVehData[id][WheelStep] == 27)
	{
		if(!PlayerToPoint(15.0, playerid, x, y, z))
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Jesteœ zbyt daleko od pojazdu !");
			return 1;
		}
		PlayerActionMessage(playerid, 15.0, "podchodzi do lewego tylnego ko³a");
		gVehData[id][WheelStep] = 28;

		SaveVehData(id, "WheelStep");
		return 1;
	}
	if(gVehData[id][WheelStep] == 28)
	{
		if(!PlayerToPoint(5.0, playerid, x, y, z))
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Jesteœ zbyt daleko od pojazdu !");
			return 1;
		}
		PlayerActionMessage(playerid, 15.0, "luzuje nakrêtki");
		gVehData[id][WheelStep] = 29;
		isWheelChanging[id] = 1;
		gVehData[id][CarDamaged] = 1;
		defer WheelChangingTimer[20000](id);

		SaveVehData(id, "WheelStep");
		SaveVehData(id, "CarDamaged");
		return 1;
	}
	if(gVehData[id][WheelStep] == 29)
	{
		if(!PlayerToPoint(5.0, playerid, x, y, z))
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Jesteœ zbyt daleko od pojazdu !");
			return 1;
		}
		PlayerActionMessage(playerid, 15.0, "podnosi pojazd");
		gVehData[id][WheelStep] = 30;
		isWheelChanging[id] = 1;
		gVehData[id][CarDamaged] = 1;
		defer WheelChangingTimer[15000](id);

		SaveVehData(id, "WheelStep");
		SaveVehData(id, "CarDamaged");
		return 1;
	}
	if(gVehData[id][WheelStep] == 30)
	{
		if(!PlayerToPoint(5.0, playerid, x, y, z))
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Jesteœ zbyt daleko od pojazdu !");
			return 1;
		}
		PlayerActionMessage(playerid, 15.0, "odkrêca prawe tylne ko³o");
		gVehData[id][WheelStep] = 31;
		isWheelChanging[id] = 1;
		defer WheelChangingTimer[25000](id);

		SaveVehData(id, "WheelStep");
		return 1;
	}
	if(gVehData[id][WheelStep] == 31)
	{
		if(!PlayerToPoint(5.0, playerid, x, y, z))
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Jesteœ zbyt daleko od pojazdu !");
			return 1;
		}
		PlayerActionMessage(playerid, 15.0, "idzie do warsztatu");
		gVehData[id][WheelStep] = 32;

		SaveVehData(id, "WheelStep");
		return 1;
	}
	if(gVehData[id][WheelStep] == 32)
	{
		if(!isInWheelChangePoint(playerid))
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w punkcie wymiany opon !");
			return 1;
		}
		PlayerActionMessage(playerid, 15.0, "wymienia opone");
		gVehData[id][WheelStep] = 33;
		isWheelChanging[id] = 1;
		defer WheelChangingTimer[40000](id);

		SaveVehData(id, "WheelStep");
		return 1;
	}
	if(gVehData[id][WheelStep] == 33)
	{
		if(!isInWheelChangePoint(playerid))
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w punkcie wymiany opon !");
			return 1;
		}
		PlayerActionMessage(playerid, 15.0, "zabiera prawe tylne ko³o i idzie do samochodu");
		gVehData[id][WheelStep] = 34;

		SaveVehData(id, "WheelStep");
		return 1;
	}
	if(gVehData[id][WheelStep] == 34)
	{
		if(!PlayerToPoint(5.0, playerid, x, y, z))
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Jesteœ zbyt daleko od pojazdu !");
			return 1;
		}
		PlayerActionMessage(playerid, 15.0, "zak³ada prawe tylne ko³o, koñczy prace");
		gVehData[id][WheelStep] = 0;
		gVehData[id][CarDamaged] = 0;
		isWheelChanging[id] = 0;
		new panels, doors, lights, tires;
		GetVehicleDamageStatus(id+1, panels, doors, lights, tires);
		UpdateVehicleDamageStatus(id+1, panels, doors, lights, 0);
		SaveVehData(id, "WheelStep");
		SaveVehData(id, "CarDamaged");
		return 1;
	}
	return 1;
}
*/
dcmd_fly(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] <= 0)
		return 0;
	new Float:px, Float:py, Float:pz, Float:pa;
	GetPlayerFacingAngle(playerid,pa);
	if(pa >= 0.0 && pa <= 22.5) //n1
	{
		GetPlayerPos(playerid, px, py, pz);
		SetPlayerToPos(playerid, px, py+30, pz+5);
	}
	if(pa >= 332.5 && pa < 0.0) //n2
	{
		GetPlayerPos(playerid, px, py, pz);
		SetPlayerToPos(playerid, px, py+30, pz+5);
	}
	if(pa >= 22.5 && pa <= 67.5) //nw
	{
		GetPlayerPos(playerid, px, py, pz);
		SetPlayerToPos(playerid, px-15, py+15, pz+5);
	}
	if(pa >= 67.5 && pa <= 112.5) //w
	{
		GetPlayerPos(playerid, px, py, pz);
		SetPlayerToPos(playerid, px-30, py, pz+5);
	}
	if(pa >= 112.5 && pa <= 157.5) //sw
	{
		GetPlayerPos(playerid, px, py, pz);
		SetPlayerToPos(playerid, px-15, py-15, pz+5);
	}
	if(pa >= 157.5 && pa <= 202.5) //s
	{
		GetPlayerPos(playerid, px, py, pz);
		SetPlayerToPos(playerid, px, py-30, pz+5);
	}
	if(pa >= 202.5 && pa <= 247.5)//se
	{
		GetPlayerPos(playerid, px, py, pz);
		SetPlayerToPos(playerid, px+15, py-15, pz+5);
	}
	if(pa >= 247.5 && pa <= 292.5)//e
	{
		GetPlayerPos(playerid, px, py, pz);
		SetPlayerToPos(playerid, px+30, py, pz+5);
	}
	if(pa >= 292.5 && pa <= 332.5)//e
	{
		GetPlayerPos(playerid, px, py, pz);
		SetPlayerToPos(playerid, px+15, py+15, pz+5);
	}
	return 1;
}

dcmd_rtc(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] <= 0)
		return 0;	
	if(IsPlayerInAnyVehicle(playerid))
	{
		new string[128];
		new vehid = GetPlayerVehicleID(playerid);
		format(string, sizeof(string), "%s has just respawned vehicle id %d", gPlayerData[playerid][pName], vehid);
		ABroadCast(COLOR_YELLOW, string, 1);
		gVehData[vehid-1][EngineOn] = 0;
		SaveVehData(vehid-1, "EngineOn");
		SetVehicleToRespawnEx(vehid);
		SetVehicleToPos(vehid, gVehData[vehid-1][mVehX], gVehData[vehid-1][mVehY], gVehData[vehid-1][mVehZ]);
		RemovePlayerFromVehicle(playerid);
	}
	return 1;
}

dcmd_getip(playerid, params[])
{
	if(!gPlayerData[playerid][pModerator])
		return 0;
	new giveplayerid, playersip[256], string[128];
	if(sscanf(params, "d", giveplayerid))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /getip [playerid]");
		return 1;
	}
	GetPlayerIp( giveplayerid,playersip,sizeof(playersip));
	format(string, sizeof(string), "Player: %s IP: %s", gPlayerData[giveplayerid][pName], playersip);
	SendClientMessage(playerid,COLOR_GRAD2,string);
	return 1;
}

dcmd_odbierznagrode(playerid, params[])
{
	#pragma unused params
	if(!PlayerToPoint(1.0, playerid, 358.78, 186.86, 1008.38))
	{
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Nie jesteœ w punkcie odbioru nagród !\nPunkt ten znajduje siê w urzêdzie.", "Zamknij", "");
		return 1;
	}
	if(gPlayerData[playerid][mPickupEventRewardReceived])
	{
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Odebra³eœ ju¿ swoj¹ nagrode w tym konkursie !\nPoczekaj na nastêpny !", "Zamknij", "");
		return 1;
	}
	new string[128], count;
	for(new i = 0; i < gPickupEventCount; i++)
	{
		if(!gPlayerData[playerid][mPickupEventPickupStatus][i])
			count++;
	}
	if(count == 0)
	{
		switch(gPickupEventPrizeType)
		{
			case 0:
			{
				GivePlayerCash(playerid, gPickupEventCashPrize);
				DynamicFactions[FACTIONID_GOVERNMENT][fBank] -= gPickupEventCashPrize;
				SaveFData(FACTIONID_GOVERNMENT, "Bank");
				format(string, sizeof(string), "Otrzyma³eœ nagrode pieniê¿n¹ w wysokoœci $%d", gPickupEventCashPrize);
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", string, "Zamknij", "");
				gPlayerData[playerid][mPickupEventRewardReceived] = 1;
				SavePlayerData(playerid, "PickupEventRewardReceived");
			}
			case 1:
			{
				if(!PlayerFreeSlotCount(playerid))
				{
					ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Musisz posiadaæ co najmniej jeden wolny slot aby otrzymaæ nagrode !", "Zamknij", "");
					return 1;
				}
				InsertPlayerItemEx(playerid, gPickupEventItemType, gPickupEventItem, 0, 0, 0, 0, "Puste", gPickupEventItemCount);
				format(string, sizeof(string), "Otrzyma³eœ nagrode w postaci przedmiotu - %s", ItemName(gPickupEventItemType, gPickupEventItem));
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", string, "Zamknij", "");
				gPlayerData[playerid][mPickupEventRewardReceived] = 1;
				SavePlayerData(playerid, "PickupEventRewardReceived");
			}
			case 2:
			{
				new value = random(7);
				switch(value)
				{
					case 0:
					{
						gPlayerData[playerid][pVipRedNeon]++;
						SavePlayerData(playerid, "VipRedNeon");
					}
					case 1:
					{
						gPlayerData[playerid][pVipBlueNeon]++;
						SavePlayerData(playerid, "VipBlueNeon");
					}
					case 2:
					{
						gPlayerData[playerid][pVipGreenNeon]++;
						SavePlayerData(playerid, "VipGreenNeon");
					}
					case 3:
					{
						gPlayerData[playerid][pVipYellowNeon]++;
						SavePlayerData(playerid, "VipYellowNeon");
					}
					case 4:
					{
						gPlayerData[playerid][pVipPinkNeon]++;
						SavePlayerData(playerid, "VipPinkNeon");
					}
					case 5:
					{
						gPlayerData[playerid][pVipWhiteNeon]++;
						SavePlayerData(playerid, "VipWhiteNeon");
					}
					case 6:
					{
						gPlayerData[playerid][pVipAFKT] += 2;
						SavePlayerData(playerid, "VipAFKT");
						gPlayerData[playerid][pVipExpT] += 2;
						SavePlayerData(playerid, "VipExpT");
					}
				}
			}
			case 3:
			{
				if(!PlayerFreeSlotCount(playerid))
				{
					ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Musisz posiadaæ co najmniej jeden wolny slot aby otrzymaæ nagrode !", "Zamknij", "");
					return 1;
				}
				InsertPlayerItemEx(playerid, gPickupEventItemType, gPickupEventItem, 0, 0, 0, 0, "Puste", gPickupEventItemCount);
				GivePlayerCash(playerid, gPickupEventCashPrize);
				DynamicFactions[FACTIONID_GOVERNMENT][fBank] -= gPickupEventCashPrize;
				SaveFData(FACTIONID_GOVERNMENT, "Bank");
				
				gPlayerData[playerid][mPickupEventRewardReceived] = 1;				
				SavePlayerData(playerid, "PickupEventRewardReceived");
				
				format(string, sizeof(string), "Otrzyma³eœ nagrode w postaci przedmiotu - %s oraz pieniêdzy - $%d", ItemName(gPickupEventItemType, gPickupEventItem), gPickupEventCashPrize);
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", string, "Zamknij", "");
			}
		}
		return 1;
	}
	else
	{
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Nie zebra³eœ jeszcze wszystkich obiektów !", "Zamknij", "");
		return 1;
	}
}	

dcmd_afk(playerid, params[])
{
	#pragma unused params
	
	new string[128], Hour, Minute, Second;
	
	gettime(Hour, Minute, Second);
	format(string, sizeof(string), "{33CCFF}AFK od %d:%d", Hour, Minute);
	
	UpdateDynamic3DTextLabelText(playerAFK[playerid], COLOR_BLACK, string);
	
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Zmieni³eœ swój status na AFK");
	
	return 1;
}

// dcmd_lightfw(playerid, params[])
// {
	// if(gPlayerData[playerid][pAdmin] != 5)
		// return 0;
	// new distance;
    // if(AllowedFirework[FWNDrawDistance] == 0) distance = 15;
    // if(AllowedFirework[FWNDrawDistance] == 1) distance = 22;
    // if(AllowedFirework[FWNDrawDistance] == 2) distance = 30;
    // if(!strlen(params))
	// {
		// SendClientMessage(playerid, COLOR_TAN, "Right Usage: /lightfw [type]");
		// SendClientMessage(playerid, COLOR_TAN, "Types: Firecracker, crackerroll, firerocket1, firerocket2, fountain1, fountain2, fountain3, rocketbox");
		// return 1;
	// }
	// if(strcmp("firecracker", params, true, 8) == 0)
	// {
	    // if(AllowedFirework[FireCracker] == 1 && IsPlayerAdmin(playerid) || AllowedFirework[FireCracker] == 0)
	    // {
		    // if(firecrackertime[playerid] == 0)
		    // {
		        // new Float:Xj, Float:Yj, Float:Zj;
		        // firecrackertime[playerid] = 1;
			    // new string[128];
				// new sendername[MAX_PLAYER_NAME];
				// GetPlayerName(playerid, sendername, sizeof(sendername));
				// format(string, sizeof(string), "<> %s throws away a firecracker.", sendername);
				// ProxDetector(15.0, playerid, string, WHITE,WHITE,WHITE,WHITE,WHITE);
				// GetPlayerPos(playerid,Xj,Yj,Zj);
				// GetXYInFrontOfPlayer(playerid, Xj,Yj, 8);
				// Firecracker[playerid] = CreateObject(1672, Xj,Yj,(Zj-0.9), 0, 0, 0);
				// SetTimerEx("FirecrackerTime", (2000+(random(3000))), 0, "i", playerid);
				// return 1;
			// }
			// else return SendClientMessage(playerid, RED, "ERROR: You already threw a firecracker.");
		// }
		// else return SendClientMessage(playerid, RED, "ERROR: The Firecracker is enabled for rcon admins only");
	// }
	// if(strcmp("crackerroll", params, true, 11) == 0)
	// {
	    // if(AllowedFirework[Crackerroll] == 1 && IsPlayerAdmin(playerid) || AllowedFirework[Crackerroll] == 0)
	    // {
		    // if(firecrackerroll[playerid] == 0)
		    // {
		        // new Float:Xj, Float:Yj,Float:Zj;
		        // firecrackerroll[playerid] = 1;
			    // new string[128];
				// new sendername[MAX_PLAYER_NAME];
				// GetPlayerName(playerid, sendername, sizeof(sendername));
				// format(string, sizeof(string), "<> %s Places down a firecracker roll", sendername);
				// ProxDetector(15.0, playerid, string, WHITE,WHITE,WHITE,WHITE,WHITE);
				// GetPlayerPos(playerid,Xj,Yj,Zj);
				// GetXYInFrontOfPlayer(playerid, Xj,Yj, 8);
				// FireCrackerRoll[playerid] = CreateRoll(playerid,Xj,Yj,(Zj-1.00));
				// RollStartX[playerid] = Xj;
				// RollStartY[playerid] = Yj;
				// RollStartZ[playerid] = (Zj-1.00);
				// CrackerRollSmoke[playerid] = CreateObject(2780, Xj, Yj, (Zj-5.00), 0, 0, 0);
				// SetTimerEx("CrackerRollTime", (2000+(random(3000))), 0, "i", playerid);
				// return 1;
			// }
			// else return SendClientMessage(playerid, RED, "ERROR: You already placed a firecracker roll.");
		// }
		// else return SendClientMessage(playerid, RED, "ERROR: The CrackerRoll is enabled for rcon admins only");
	// }
	// if(strcmp("firerocket1", params, true, 11) == 0)
	// {
	    // if(AllowedFirework[Firerocket1] == 1 && IsPlayerAdmin(playerid) || AllowedFirework[Firerocket1] == 0)
	    // {
		    // if(firerockettime[playerid] == 0)
		    // {
		        // new Float:Xj, Float:Yj,Float:Zj;
		        // firerockettime[playerid] = 1;
			    // new string[128];
				// new sendername[MAX_PLAYER_NAME];
				// GetPlayerName(playerid, sendername, sizeof(sendername));
				// format(string, sizeof(string), "<> %s lights up a fire rocket.", sendername);
				// ProxDetector(15.0, playerid, string, WHITE,WHITE,WHITE,WHITE,WHITE);
				// GetPlayerPos(playerid,Xj,Yj,Zj);
				// GetXYInFrontOfPlayer(playerid, Xj,Yj, distance);
				// Firerocket[playerid] = CreateObject(354, Xj,Yj,(Zj), 0, 0, 0);
				// rocketsmoke[playerid] = CreateObject(2780, Xj,Yj,(Zj), 0, 0, 0);
				// MoveObject(Firerocket[playerid], Xj, Yj, Zj+30, 10);
				// MoveObject(rocketsmoke[playerid], Xj, Yj, Zj+30, 10);
				// SetTimerEx("FirerocketTime", 3000, 0, "i", playerid);
				// return 1;
			// }
			// else return SendClientMessage(playerid, RED, "ERROR: You already lightd a firerocket.");
        // }
		// else return SendClientMessage(playerid, RED, "ERROR: The FireRocket 1 is enabled for rcon admins only");
	// }
	// if(strcmp("firerocket2", params, true, 11) == 0)
	// {
	    // if(AllowedFirework[Firerocket2] == 1 && IsPlayerAdmin(playerid) || AllowedFirework[Firerocket2] == 0)
	    // {
			// if(firerockettime[playerid] == 0)
			// {
			    // new Float:Xj, Float:Yj,Float:Zj;
			    // firerockettime[playerid] = 2;
			    // new string[128];
				// new sendername[MAX_PLAYER_NAME];
				// GetPlayerName(playerid, sendername, sizeof(sendername));
				// format(string, sizeof(string), "<> %s lights up a fire rocket.", sendername);
				// ProxDetector(15.0, playerid, string, WHITE,WHITE,WHITE,WHITE,WHITE);
				// GetPlayerPos(playerid,Xj,Yj,Zj);
				// GetXYInFrontOfPlayer(playerid, Xj,Yj, distance);
				// Firerocket[playerid] = CreateObject(354, Xj,Yj,(Zj), 0, 0, 0);
				// rocketsmoke[playerid] = CreateObject(2780, Xj,Yj,(Zj), 0, 0, 0);
				// MoveObject(Firerocket[playerid], Xj, Yj, Zj+50, 15);
				// MoveObject(rocketsmoke[playerid], Xj, Yj, Zj+50, 15);
				// SetTimerEx("FirerocketTime", 3000, 0, "i", playerid);
				// return 1;
			// }
			// else return SendClientMessage(playerid, RED, "ERROR: You already Light a firerocket.");
		// }
		// else return SendClientMessage(playerid, RED, "ERROR: The FireRocket 2 is enabled for rcon admins only");
	// }
	// if(strcmp("fountain1", params, true, 9) == 0)
	// {
	    // if(AllowedFirework[Fountain1] == 1 && IsPlayerAdmin(playerid) || AllowedFirework[Fountain1] == 0)
	    // {
			// if(Fountain1Time[playerid] == 0 && Fountain2Time[playerid] == 0 && Fountain3Time[playerid] == 0)
			// {
			    // new Float:Xj, Float:Yj,Float:Zj;
			    // Fountain1Time[playerid] = 1;
			    // new string[128];
				// new sendername[MAX_PLAYER_NAME];
				// GetPlayerName(playerid, sendername, sizeof(sendername));
				// format(string, sizeof(string), "<> %s places a Firework Fountain on the ground.", sendername);
				// ProxDetector(15.0, playerid, string, WHITE,WHITE,WHITE,WHITE,WHITE);
				// GetPlayerPos(playerid,Xj,Yj,Zj);
				// GetXYInFrontOfPlayer(playerid, Xj,Yj, 15);
				// FTX[playerid] = Xj;
				// FTY[playerid] = Yj;
				// FTZ[playerid] = (Zj-1.0);
				// Fountain[playerid] = CreateObject(354, Xj,Yj,(Zj-1.0), 0, 0, 0);
				// FountainSmoke[playerid] = CreateObject(2780, Xj,Yj,(Zj-1.0), 0, 0, 0);
				// SetTimerEx("FountainTimer", 3000, 0, "i", playerid);
				// return 1;
			// }
			// else return SendClientMessage(playerid, RED, "ERROR: You already Light a Firework Fountain.");
		// }
		// else return SendClientMessage(playerid, RED, "ERROR: The Fountain 1 is enabled for rcon admins only");
	// }
	// if(strcmp("fountain2", params, true, 9) == 0)
	// {
	    // if(AllowedFirework[Fountain2] == 1 && IsPlayerAdmin(playerid) || AllowedFirework[Fountain2] == 0)
	    // {
			// if(Fountain1Time[playerid] == 0 && Fountain2Time[playerid] == 0 && Fountain3Time[playerid] == 0)
			// {
			    // new Float:Xj, Float:Yj,Float:Zj;
			    // Fountain2Time[playerid] = 1;
			    // new string[128];
				// new sendername[MAX_PLAYER_NAME];
				// GetPlayerName(playerid, sendername, sizeof(sendername));
				// format(string, sizeof(string), "<> %s places a Firework Fountain on the ground.", sendername);
				// ProxDetector(15.0, playerid, string, WHITE,WHITE,WHITE,WHITE,WHITE);
				// GetPlayerPos(playerid,Xj,Yj,Zj);
				// GetXYInFrontOfPlayer(playerid, Xj,Yj, 15);
				// FTX[playerid] = Xj;
				// FTY[playerid] = Yj;
				// FTZ[playerid] = (Zj-1.0);
				// Fountain[playerid] = CreateObject(354, Xj,Yj,(Zj-1.0), 0, 0, 0);
				// FountainSmoke[playerid] = CreateObject(2780, Xj,Yj,(Zj-1.0), 0, 0, 0);
				// SetTimerEx("FountainTimer", 3000, 0, "i", playerid);
				// return 1;
			// }
			// else return SendClientMessage(playerid, RED, "ERROR: You already Light a Firework Fountain.");
		// }
		// else return SendClientMessage(playerid, RED, "ERROR: The Fountain 2 is enabled for rcon admins only");
	// }
	// if(strcmp("fountain3", params, true, 9) == 0)
	// {
	    // if(AllowedFirework[Fountain3] == 1 && IsPlayerAdmin(playerid) || AllowedFirework[Fountain3] == 0)
	    // {
			// if(Fountain1Time[playerid] == 0 && Fountain2Time[playerid] == 0 && Fountain3Time[playerid] == 0)
			// {
			    // new Float:Xj, Float:Yj,Float:Zj;
			    // Fountain3Time[playerid] = 1;
			    // new string[128];
				// new sendername[MAX_PLAYER_NAME];
				// GetPlayerName(playerid, sendername, sizeof(sendername));
				// format(string, sizeof(string), "<> %s places a Firework Fountain on the ground.", sendername);
				// ProxDetector(15.0, playerid, string, WHITE,WHITE,WHITE,WHITE,WHITE);
				// GetPlayerPos(playerid,Xj,Yj,Zj);
				// GetXYInFrontOfPlayer(playerid, Xj,Yj, 15);
				// FTX[playerid] = Xj;
				// FTY[playerid] = Yj;
				// FTZ[playerid] = (Zj-1.0);
				// Fountain[playerid] = CreateObject(354, Xj,Yj,(Zj-1.0), 0, 0, 0);
				// FountainSmoke[playerid] = CreateObject(2780, Xj,Yj,(Zj-1.0), 0, 0, 0);
				// SetTimerEx("FountainTimer", 3000, 0, "i", playerid);
				// return 1;
			// }
			// else return SendClientMessage(playerid, RED, "ERROR: You already Light a Firework Fountain.");
		// }
		// else return SendClientMessage(playerid, RED, "ERROR: The Fountain 3 is enabled for rcon admins only");
	// }
	// if(strcmp("rocketbox", params, true, 9) == 0)
	// {
	    // if(AllowedFirework[RocketB] == 1 && IsPlayerAdmin(playerid) || AllowedFirework[RocketB] == 0)
	    // {
			// if(RocketBoxTime[playerid] == 0)
			// {
			    // new Float:Xj, Float:Yj,Float:Zj;
			    // RocketBoxTime[playerid] = 1;
			    // new string[128];
				// new sendername[MAX_PLAYER_NAME];
				// GetPlayerName(playerid, sendername, sizeof(sendername));
				// format(string, sizeof(string), "<> %s places a Rocketbox on the ground.", sendername);
				// ProxDetector(15.0, playerid, string, WHITE,WHITE,WHITE,WHITE,WHITE);
				// GetPlayerPos(playerid,Xj,Yj,Zj);
				// GetXYInFrontOfPlayer(playerid, Xj,Yj, distance);
				// RBX[playerid] = Xj;
				// RBY[playerid] = Yj;
				// RBZ[playerid] = (Zj-1.0);
				// RocketBox[playerid] = CreateObject(354, Xj,Yj,(Zj-1.0), 0, 0, 0);
				// RocketBoxSmoke[playerid] = CreateObject(2780, Xj,Yj,(Zj-1.0), 0, 0, 0);
				// SetTimerEx("RocketBoxTimer", 3000, 0, "i", playerid);
				// return 1;
			// }
			// else return SendClientMessage(playerid, RED, "ERROR: You already Light a Firework RocketBox.");
		// }
		// else return SendClientMessage(playerid, RED, "ERROR: The RocketBox is enabled for rcon admins only");
	// }
	// else return SendClientMessage(playerid, COLOR_TAN, "Right Usage: /lightfirework [type]");
// }

// dcmd_fwcp(playerid, params[])
// {
	// #pragma unused params
	// if(gPlayerData[playerid][pAdmin] != 5)
		// return 0;
	// new string[512];
	// format(string, sizeof(string), "DrawDistance: %s\nFire Cracker: %s\nFirerocket1: %s\nFirerocket2: %s\nCrackerRoll: %s\nFountain1: %s\nFountain2: %s\nFountain3: %s\nRocketBox: %s",
	// DrawDistanceWord[AllowedFirework[FWNDrawDistance]], UsageFW[AllowedFirework[FireCracker]], UsageFW[AllowedFirework[Firerocket1]], UsageFW[AllowedFirework[Firerocket2]], UsageFW[AllowedFirework[Crackerroll]], UsageFW[AllowedFirework[Fountain1]], UsageFW[AllowedFirework[Fountain2]], UsageFW[AllowedFirework[Fountain3]], UsageFW[AllowedFirework[RocketB]]);
	// ShowPlayerDialog(playerid, FWCPM,2,"FireWork Control Panel", string,"Select", "Close");
	// return 1;
// }

dcmd_fixwheels(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new panels, doors, lights, tires;
	GetVehicleDamageStatus(GetPlayerVehicleID(playerid), panels, doors, lights, tires);
	UpdateVehicleDamageStatus(GetPlayerVehicleID(playerid), panels, doors, lights, 0);
	return 1;
}

dcmd_holuj(playerid, params[])
{
	#pragma unused params
	new towCarId, playerVehId;
	new Float:Xv, Float:Yv, Float:Zv;
	playerVehId = GetPlayerVehicleID(playerid);
	towCarId = INVALID_VEHICLE_ID;
	if(gVehData[playerVehId-1][mVehModel] != 525 && !AdminDuty[playerid] && (!gVehData[playerVehId-1][Hook] || PHaveItem(playerid, 3, 8) == 0))
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ten pojazd nie jest przeznaczony do holowania lub nie posiadasz linki holowniczej !");
		return 1;
	}
	for(new  i = 1; i <= sizeof(gVehData); i++)
	{
		if(playerVehId == i)
			continue;

		GetVehiclePos(i, Xv, Yv, Zv);
		if(PlayerToPoint(8.0, playerid, Xv, Yv, Zv))
		{
			towCarId = i;
			break;
		}
	}
	if(towCarId == INVALID_VEHICLE_ID)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Brak pojazdu do holowania");
		return 1;
	}
	if(gVehData[towCarId-1][Alarm] && gVehData[towCarId-1][Closed])
	{
		defer CarAlarmOff[25000](towCarId);
		SendPoliceCbMessage(playerid, POLICE_MSGT_VEHICLE_BREAK);
	}
	AttachTrailerToVehicle(towCarId, playerVehId);
	printf("[WARNING:] /holuj used by %s, towed veh id: %d, towing veh id: %d", gPlayerData[playerid][pName], towCarId, playerVehId);
	return 1;
}

dcmd_acaralarm(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] < 4)
		return 0;
	new alarm2, idcar;
	if(sscanf(params, "d", alarm2))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /acaralarm [0/1]");
		return 1;
	}
	idcar = GetPlayerVehicleID(playerid);
	new enginedyn,lights,alarm,doors,bonnet,boot,objective;
	GetVehicleParamsEx(idcar,enginedyn,lights,alarm,doors,bonnet,boot,objective);
	SetVehicleParamsEx(idcar,enginedyn,lights,alarm2,doors,bonnet,boot,objective);
	return 1;
}

dcmd_onoffobiektpoj(playerid, params[])
{
	new slot, vehid;
	vehid = GetPlayerVehicleID(playerid);
	if(vehid == 0)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w pojeŸdzie !");
		return 1;
	}
	if(sscanf(params, "d", slot))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /onoffobiektpoj [slot]");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] slot: 0 - 6");
		return 1;
	}
	if(slot > 6 || slot < 0)
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /onoffobiektpoj [slot]");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] slot: 0 - 6");
		return 1;
	}
	if(slot == 0)
	{
		if(gVehData[vehid-1][CustomObj1On] == 0)
		{
			if(gVehData[vehid-1][CustomObj1Model] == 0)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz neonu na tym slocie !");
				return 1;
			}
			gVehData[vehid-1][CustomObj1On] = 1;
			SaveVehData(vehid-1, "CustomObj1On");
			gVehData[vehid-1][CustomObj1ID] = CreateDynamicObject(
				gVehData[vehid-1][CustomObj1Model],
				gVehData[vehid-1][CustomObj1][0],
				gVehData[vehid-1][CustomObj1][1],
				gVehData[vehid-1][CustomObj1][2],
				gVehData[vehid-1][CustomObj1][3],
				gVehData[vehid-1][CustomObj1][4],
				gVehData[vehid-1][CustomObj1][5]);
			AttachDynamicObjectToVehicle(gVehData[vehid-1][CustomObj1ID], vehid, gVehData[vehid-1][CustomObj1][0], gVehData[vehid-1][CustomObj1][1], gVehData[vehid-1][CustomObj1][2], gVehData[vehid-1][CustomObj1][3], gVehData[vehid-1][CustomObj1][4], gVehData[vehid-1][CustomObj1][5]);
			return 1;
		}
		else
		{
			gVehData[vehid-1][CustomObj1On] = 0;
			SaveVehData(vehid-1, "CustomObj1On");
			DestroyDynamicObject(gVehData[vehid-1][CustomObj1ID]);
		}
	}
	if(slot == 1)
	{
		if(gVehData[vehid-1][CustomObj2On] == 0)
		{
			if(gVehData[vehid-1][CustomObj2Model] == 0)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz neonu na tym slocie !");
				return 1;
			}
			gVehData[vehid-1][CustomObj2On] = 1;
			SaveVehData(vehid-1, "CustomObj2On");
			gVehData[vehid-1][CustomObj2ID] = CreateDynamicObject(
				gVehData[vehid-1][CustomObj2Model],
				gVehData[vehid-1][CustomObj2][0],
				gVehData[vehid-1][CustomObj2][1],
				gVehData[vehid-1][CustomObj2][2],
				gVehData[vehid-1][CustomObj2][3],
				gVehData[vehid-1][CustomObj2][4],
				gVehData[vehid-1][CustomObj2][5]);
			AttachDynamicObjectToVehicle(gVehData[vehid-1][CustomObj2ID], vehid, gVehData[vehid-1][CustomObj2][0], gVehData[vehid-1][CustomObj2][1], gVehData[vehid-1][CustomObj2][2], gVehData[vehid-1][CustomObj2][3], gVehData[vehid-1][CustomObj2][4], gVehData[vehid-1][CustomObj2][5]);
			return 1;
		}
		else
		{
			gVehData[vehid-1][CustomObj2On] = 0;
			SaveVehData(vehid-1, "CustomObj2On");
			DestroyDynamicObject(gVehData[vehid-1][CustomObj2ID]);
		}
	}
	if(slot == 2)
	{
		if(gVehData[vehid-1][CustomObj3On] == 0)
		{
			if(gVehData[vehid-1][CustomObj3Model] == 0)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz neonu na tym slocie !");
				return 1;
			}
			gVehData[vehid-1][CustomObj3On] = 1;
			SaveVehData(vehid-1, "CustomObj3On");
			gVehData[vehid-1][CustomObj3ID] = CreateDynamicObject(
				gVehData[vehid-1][CustomObj3Model],
				gVehData[vehid-1][CustomObj3][0],
				gVehData[vehid-1][CustomObj3][1],
				gVehData[vehid-1][CustomObj3][2],
				gVehData[vehid-1][CustomObj3][3],
				gVehData[vehid-1][CustomObj3][4],
				gVehData[vehid-1][CustomObj3][5]);
			AttachDynamicObjectToVehicle(gVehData[vehid-1][CustomObj3ID], vehid, gVehData[vehid-1][CustomObj3][0], gVehData[vehid-1][CustomObj3][1], gVehData[vehid-1][CustomObj3][2], gVehData[vehid-1][CustomObj3][3], gVehData[vehid-1][CustomObj3][4], gVehData[vehid-1][CustomObj3][5]);
			return 1;
		}
		else
		{
			gVehData[vehid-1][CustomObj3On] = 0;
			SaveVehData(vehid-1, "CustomObj3On");
			DestroyDynamicObject(gVehData[vehid-1][CustomObj3ID]);
		}
	}
	if(slot == 3)
	{
		if(gVehData[vehid-1][CustomObj4On] == 0)
		{
			if(gVehData[vehid-1][CustomObj4Model] == 0)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz neonu na tym slocie !");
				return 1;
			}
			gVehData[vehid-1][CustomObj4On] = 1;
			SaveVehData(vehid-1, "CustomObj4On");
			gVehData[vehid-1][CustomObj4ID] = CreateDynamicObject(
				gVehData[vehid-1][CustomObj4Model],
				gVehData[vehid-1][CustomObj4][0],
				gVehData[vehid-1][CustomObj4][1],
				gVehData[vehid-1][CustomObj4][2],
				gVehData[vehid-1][CustomObj4][3],
				gVehData[vehid-1][CustomObj4][4],
				gVehData[vehid-1][CustomObj4][5]);
			AttachDynamicObjectToVehicle(gVehData[vehid-1][CustomObj4ID], vehid, gVehData[vehid-1][CustomObj4][0], gVehData[vehid-1][CustomObj4][1], gVehData[vehid-1][CustomObj4][2], gVehData[vehid-1][CustomObj4][3], gVehData[vehid-1][CustomObj4][4], gVehData[vehid-1][CustomObj4][5]);
			return 1;
		}
		else
		{
			gVehData[vehid-1][CustomObj4On] = 0;
			SaveVehData(vehid-1, "CustomObj4On");
			DestroyDynamicObject(gVehData[vehid-1][CustomObj4ID]);
		}
	}
	if(slot == 4)
	{
		if(gVehData[vehid-1][CustomObj5On] == 0)
		{
			if(gVehData[vehid-1][CustomObj5Model] == 0)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz neonu na tym slocie !");
				return 1;
			}
			gVehData[vehid-1][CustomObj5On] = 1;
			SaveVehData(vehid-1, "CustomObj5On");
			gVehData[vehid-1][CustomObj5ID] = CreateDynamicObject(
				gVehData[vehid-1][CustomObj5Model],
				gVehData[vehid-1][CustomObj5][0],
				gVehData[vehid-1][CustomObj5][1],
				gVehData[vehid-1][CustomObj5][2],
				gVehData[vehid-1][CustomObj5][3],
				gVehData[vehid-1][CustomObj5][4],
				gVehData[vehid-1][CustomObj5][5]);
			AttachDynamicObjectToVehicle(gVehData[vehid-1][CustomObj5ID], vehid, gVehData[vehid-1][CustomObj5][0], gVehData[vehid-1][CustomObj5][1], gVehData[vehid-1][CustomObj5][2], gVehData[vehid-1][CustomObj5][3], gVehData[vehid-1][CustomObj5][4], gVehData[vehid-1][CustomObj5][5]);
			return 1;
		}
		else
		{
			gVehData[vehid-1][CustomObj5On] = 0;
			SaveVehData(vehid-1, "CustomObj5On");
			DestroyDynamicObject(gVehData[vehid-1][CustomObj5ID]);
		}
	}
	if(slot == 5)
	{
		if(gVehData[vehid-1][CustomObj6On] == 0)
		{
			if(gVehData[vehid-1][CustomObj6Model] == 0)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz neonu na tym slocie !");
				return 1;
			}
			gVehData[vehid-1][CustomObj6On] = 1;
			SaveVehData(vehid-1, "CustomObj6On");
			gVehData[vehid-1][CustomObj6ID] = CreateDynamicObject(
				gVehData[vehid-1][CustomObj6Model],
				gVehData[vehid-1][CustomObj6][0],
				gVehData[vehid-1][CustomObj6][1],
				gVehData[vehid-1][CustomObj6][2],
				gVehData[vehid-1][CustomObj6][3],
				gVehData[vehid-1][CustomObj6][4],
				gVehData[vehid-1][CustomObj6][5]);
			AttachDynamicObjectToVehicle(gVehData[vehid-1][CustomObj6ID], vehid, gVehData[vehid-1][CustomObj6][0], gVehData[vehid-1][CustomObj6][1], gVehData[vehid-1][CustomObj6][2], gVehData[vehid-1][CustomObj6][3], gVehData[vehid-1][CustomObj6][4], gVehData[vehid-1][CustomObj6][5]);
			return 1;
		}
		else
		{
			gVehData[vehid-1][CustomObj6On] = 0;
			SaveVehData(vehid-1, "CustomObj6On");
			DestroyDynamicObject(gVehData[vehid-1][CustomObj6ID]);
		}
	}
	if(slot == 6)
	{
		if(gVehData[vehid-1][CustomObj7On] == 0)
		{
			if(gVehData[vehid-1][CustomObj7Model] == 0)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz neonu na tym slocie !");
				return 1;
			}
			gVehData[vehid-1][CustomObj7On] = 1;
			SaveVehData(vehid-1, "CustomObj7On");
			gVehData[vehid-1][CustomObj7ID] = CreateDynamicObject(
				gVehData[vehid-1][CustomObj7Model],
				gVehData[vehid-1][CustomObj7][0],
				gVehData[vehid-1][CustomObj7][1],
				gVehData[vehid-1][CustomObj7][2],
				gVehData[vehid-1][CustomObj7][3],
				gVehData[vehid-1][CustomObj7][4],
				gVehData[vehid-1][CustomObj7][5]);
			AttachDynamicObjectToVehicle(gVehData[vehid-1][CustomObj7ID], vehid, gVehData[vehid-1][CustomObj7][0], gVehData[vehid-1][CustomObj7][1], gVehData[vehid-1][CustomObj7][2], gVehData[vehid-1][CustomObj7][3], gVehData[vehid-1][CustomObj7][4], gVehData[vehid-1][CustomObj7][5]);
			return 1;
		}
		else
		{
			gVehData[vehid-1][CustomObj7On] = 0;
			SaveVehData(vehid-1, "CustomObj7On");
			DestroyDynamicObject(gVehData[vehid-1][CustomObj7ID]);
		}
	}
	return 1;
}

dcmd_zdemontujobiektzpoj(playerid, params[])
{
	new vehid, slot;
	vehid = GetPlayerVehicleID(playerid);
	if( vehid == 0 )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w pojeŸdzie !");
		return 1;
	}
	if(sscanf(params, "d", slot))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /zdemontujobiektzpojazdu [slot 0-4]");
		return 1;
	}
	if(!PlayerFreeSlotCount(playerid))
	{
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Nie posiadasz wolnego miejsca na item.", "Zamknij", "");
		return 1;
	}
	if(slot == 0)
	{
		if(gVehData[vehid-1][CustomObj1Model] == 0)
		{
			ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Nie posiadasz ¿adnego obiektu na tym slocie.", "Zamknij", "");
			return 1;
		}
		if(!ObjectModelToItemInsert(playerid, gVehData[vehid-1][CustomObj1Model]))
		{
			ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Nie mo¿esz zdemontowaæ tego obiektu.", "Zamknij", "");
			return 1;
		}
		if(gVehData[vehid-1][CustomObj1On])
			DestroyDynamicObject(gVehData[vehid-1][CustomObj1ID]);
		gVehData[vehid-1][CustomObj1On] = 0;
		gVehData[vehid-1][CustomObj1ID] = 0;
		gVehData[vehid-1][CustomObj1Model] = 0;
		SaveVehData(vehid-1, "CustomObj1Model");		
	}
	if(slot == 1)
	{
		if(gVehData[vehid-1][CustomObj2Model] == 0)
		{
			ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Nie posiadasz ¿adnego obiektu na tym slocie.", "Zamknij", "");
			return 1;
		}
		if(!ObjectModelToItemInsert(playerid, gVehData[vehid-1][CustomObj2Model]))
		{
			ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Nie mo¿esz zdemontowaæ tego obiektu.", "Zamknij", "");
			return 1;
		}
		if(gVehData[vehid-1][CustomObj2On])
			DestroyDynamicObject(gVehData[vehid-1][CustomObj2ID]);
		gVehData[vehid-1][CustomObj2On] = 0;
		gVehData[vehid-1][CustomObj2ID] = 0;
		gVehData[vehid-1][CustomObj2Model] = 0;
		SaveVehData(vehid-1, "CustomObj2Model");		
	}
	if(slot == 2)
	{
		if(gVehData[vehid-1][CustomObj3Model] == 0)
		{
			ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Nie posiadasz ¿adnego obiektu na tym slocie.", "Zamknij", "");
			return 1;
		}
		if(!ObjectModelToItemInsert(playerid, gVehData[vehid-1][CustomObj3Model]))
		{
			ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Nie mo¿esz zdemontowaæ tego obiektu.", "Zamknij", "");
			return 1;
		}
		if(gVehData[vehid-1][CustomObj3On])
			DestroyDynamicObject(gVehData[vehid-1][CustomObj3ID]);
		gVehData[vehid-1][CustomObj3On] = 0;
		gVehData[vehid-1][CustomObj3ID] = 0;
		gVehData[vehid-1][CustomObj3Model] = 0;
		SaveVehData(vehid-1, "CustomObj3Model");		
	}
	if(slot == 3)
	{
		if(gVehData[vehid-1][CustomObj4Model] == 0)
		{
			ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Nie posiadasz ¿adnego obiektu na tym slocie.", "Zamknij", "");
			return 1;
		}
		if(!ObjectModelToItemInsert(playerid, gVehData[vehid-1][CustomObj4Model]))
		{
			ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Nie mo¿esz zdemontowaæ tego obiektu.", "Zamknij", "");
			return 1;
		}
		if(gVehData[vehid-1][CustomObj4On])
			DestroyDynamicObject(gVehData[vehid-1][CustomObj4ID]);
		gVehData[vehid-1][CustomObj4On] = 0;
		gVehData[vehid-1][CustomObj4ID] = 0;
		gVehData[vehid-1][CustomObj4Model] = 0;
		SaveVehData(vehid-1, "CustomObj4Model");		
	}
	if(slot == 4)
	{
		if(gVehData[vehid-1][CustomObj5Model] == 0)
		{
			ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Nie posiadasz ¿adnego obiektu na tym slocie.", "Zamknij", "");
			return 1;
		}
		if(!ObjectModelToItemInsert(playerid, gVehData[vehid-1][CustomObj5Model]))
		{
			ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Nie mo¿esz zdemontowaæ tego obiektu.", "Zamknij", "");
			return 1;
		}
		if(gVehData[vehid-1][CustomObj5On])
			DestroyDynamicObject(gVehData[vehid-1][CustomObj5ID]);
		gVehData[vehid-1][CustomObj5On] = 0;
		gVehData[vehid-1][CustomObj5ID] = 0;
		gVehData[vehid-1][CustomObj5Model] = 0;
		SaveVehData(vehid-1, "CustomObj5Model");
	}
	if(slot == 5)
	{
		if(gVehData[vehid-1][CustomObj6Model] == 0)
		{
			ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Nie posiadasz ¿adnego obiektu na tym slocie.", "Zamknij", "");
			return 1;
		}
		if(!ObjectModelToItemInsert(playerid, gVehData[vehid-1][CustomObj6Model]))
		{
			ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Nie mo¿esz zdemontowaæ tego obiektu.", "Zamknij", "");
			return 1;
		}
		if(gVehData[vehid-1][CustomObj6On])
			DestroyDynamicObject(gVehData[vehid-1][CustomObj6ID]);
		gVehData[vehid-1][CustomObj6On] = 0;
		gVehData[vehid-1][CustomObj6ID] = 0;
		gVehData[vehid-1][CustomObj6Model] = 0;
		SaveVehData(vehid-1, "CustomObj6Model");
	}
	if(slot == 6)
	{
		if(gVehData[vehid-1][CustomObj7Model] == 0)
		{
			ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Nie posiadasz ¿adnego obiektu na tym slocie.", "Zamknij", "");
			return 1;
		}
		if(!ObjectModelToItemInsert(playerid, gVehData[vehid-1][CustomObj7Model]))
		{
			ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Nie mo¿esz zdemontowaæ tego obiektu.", "Zamknij", "");
			return 1;
		}
		if(gVehData[vehid-1][CustomObj7On])
			DestroyDynamicObject(gVehData[vehid-1][CustomObj7ID]);
		gVehData[vehid-1][CustomObj7On] = 0;
		gVehData[vehid-1][CustomObj7ID] = 0;
		gVehData[vehid-1][CustomObj7Model] = 0;
		SaveVehData(vehid-1, "CustomObj7Model");
	}
	return 1;
}

dcmd_doczepobiekt(playerid, params[])
{
	new color[32], model, slot, Float:Xobj, Float:Yobj, Float:Zobj, Float:rX, Float:rY, Float:rZ, vehid;
	if(sscanf(params, "s[32]dffffff", color, slot, Xobj, Yobj, Zobj, rX, rY, rZ))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /doczepobiekt [obiekt] [slot] [X] [Y] [Z] [rX] [rY] [rZ]");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] obiekt: neonczerwony/neonniebieski/neonzielony/neon¿ó³ty/neonró¿owy/neonbia³y");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] obiekt: lampahalogenowa/diodabiala/diodaczerwona/diodazielona/diodaniebieska/");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] slot: 0-6, rXYZ: obrót neona w osiach XYZ");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[U¯YCIE] X = 0; Y = 0; Z = 0 to œrodek pojazdu");
		return 1;
	}
	if(slot < 0 || slot > 6)
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /doczepobiekt [obiekt] [slot] [X] [Y] [Z] [rX] [rY] [rZ]");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] obiekt: neonczerwony/neonniebieski/neonzielony/neon¿ó³ty/neonró¿owy/neonbia³y/");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] obiekt: lampahalogenowa/diodabiala/diodaczerwona/diodazielona/diodaniebieska/");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] slot: 0-6, rXYZ: obrót neona w osiach XYZ");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[U¯YCIE] X = 0; Y = 0; Z = 0 to œrodek pojazdu");
		return 1;
	}
	if(strcmp(color, "neonczerwony", true, sizeof(color)) == 0)
	{
		if(gPlayerData[playerid][pVipRedNeon] <= 0)
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz wykupionego neonu koloru czerwonego !");
			return 1;
		}
		model = 18647;
	}
	else if(strcmp(color, "neonniebieski", true, sizeof(color)) == 0)
	{
		if(gPlayerData[playerid][pVipBlueNeon] <= 0)
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz wykupionego neonu koloru niebieskiego !");
			return 1;
		}
		model = 18648;
	}
	else if(strcmp(color, "neonzielony", true, sizeof(color)) == 0)
	{
		if(gPlayerData[playerid][pVipGreenNeon] <= 0)
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz wykupionego neonu koloru zielonego !");
			return 1;
		}
		model = 18649;
	}
	else if(strcmp(color, "neon¿ó³ty", true, sizeof(color)) == 0)
	{
		if(gPlayerData[playerid][pVipYellowNeon] <= 0)
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz wykupionego neonu koloru ¿ó³tego !");
			return 1;
		}
		model = 18650;
	}
	else if(strcmp(color, "neonró¿owy", true, sizeof(color)) == 0)
	{
		if(gPlayerData[playerid][pVipPinkNeon] <= 0)
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz wykupionego neonu koloru ró¿owego !");
			return 1;
		}
		model = 18651;
	}
	else if(strcmp(color, "neonbia³y", true, sizeof(color)) == 0)
	{
		if(gPlayerData[playerid][pVipWhiteNeon] <= 0)
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz wykupionego neonu koloru bia³ego !");
			return 1;
		}
		model = 18652;
	}
	else if(strcmp(color, "lampahalogenowa", true, sizeof(color)) == 0)
	{
		if(gPlayerData[playerid][pVipHalogenLight] <= 0)
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz wykupionej lampy halogenowej !");
			return 1;
		}
		model = 19280;
	}
	else if(strcmp(color, "diodabiala", true, sizeof(color)) == 0)
	{
		if(gPlayerData[playerid][pVipWhitePointLight] <= 0)
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz wykupionej bialej diody !");
			return 1;
		}
		model = 19281;
	}
	else if(strcmp(color, "diodaczerwona", true, sizeof(color)) == 0)
	{
		if(gPlayerData[playerid][pVipRedPointLight] <= 0)
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz wykupionej czerwonej diody !");
			return 1;
		}
		model = 19282;
	}
	else if(strcmp(color, "diodazielona", true, sizeof(color)) == 0)
	{
		if(gPlayerData[playerid][pVipGreenPointLight] <= 0)
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz wykupionej zielonej diody !");
			return 1;
		}
		model = 19283;
	}
	else if(strcmp(color, "diodaniebieska", true, sizeof(color)) == 0)
	{
		if(gPlayerData[playerid][pVipBluePointLight] <= 0)
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz wykupionej niebieskiej diody !");
			return 1;
		}
		model = 19284;
	}
	else
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Poda³eœ niew³aœciwy kolor !");
		return 1;
	}
	
	vehid = GetPlayerVehicleID(playerid);
	
	if(IsABike(vehid))
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Obiektów nie mo¿na doczepiaæ do rowerów");
		return 1;
	}
	
	if(vehid == INVALID_VEHICLE_ID)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w pojeŸdzie !");
		return 1;
	}
	if(Xobj > 1.0)
		Xobj = 1.0;
	else if(Xobj < -1.0)
		Xobj = -1.0;
	if(Yobj > 3.3)
		Yobj = 3.3;
	else if(Yobj < -3.5)
		Yobj = -3.5;
	if(Zobj > 2.0)
		Zobj = 2.0;
	else if(Zobj < -1.5)
		Zobj = -1.5;
	if(slot == 0)
	{
		if(gVehData[vehid-1][CustomObj1Model] != 0)
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ten slot jest ju¿ zajêty przez inny obiekt !");
			return 1;
		}
		gVehData[vehid-1][CustomObj1Model] = model;
		gVehData[vehid-1][CustomObj1On] = 1;
		gVehData[vehid-1][CustomObj1][0] = Xobj;
		gVehData[vehid-1][CustomObj1][1] = Yobj;
		gVehData[vehid-1][CustomObj1][2] = Zobj;
		gVehData[vehid-1][CustomObj1][3] = rX;
		gVehData[vehid-1][CustomObj1][4] = rY;
		gVehData[vehid-1][CustomObj1][5] = rZ;
		gVehData[vehid-1][CustomObj1ID] = CreateDynamicObject(
			gVehData[vehid-1][CustomObj1Model],
			gVehData[vehid-1][CustomObj1][0],
			gVehData[vehid-1][CustomObj1][1],
			gVehData[vehid-1][CustomObj1][2],
			gVehData[vehid-1][CustomObj1][3],
			gVehData[vehid-1][CustomObj1][4],
			gVehData[vehid-1][CustomObj1][5]);
		AttachDynamicObjectToVehicle(gVehData[vehid-1][CustomObj1ID], vehid, gVehData[vehid-1][CustomObj1][0], gVehData[vehid-1][CustomObj1][1], gVehData[vehid-1][CustomObj1][2], gVehData[vehid-1][CustomObj1][3], gVehData[vehid-1][CustomObj1][4], gVehData[vehid-1][CustomObj1][5]);
		SaveVehData(vehid-1, "CustomObj1Model");
		SaveVehData(vehid-1, "CustomObj1", 0);
		SaveVehData(vehid-1, "CustomObj1", 1);
		SaveVehData(vehid-1, "CustomObj1", 2);
		SaveVehData(vehid-1, "CustomObj1", 3);
		SaveVehData(vehid-1, "CustomObj1", 4);
		SaveVehData(vehid-1, "CustomObj1", 5);
		SaveVehData(vehid-1, "CustomObj1On");
	}
	if(slot == 1)
	{
		if(gVehData[vehid-1][CustomObj2Model] != 0)
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ten slot jest ju¿ zajêty przez inny obiekt !");
			return 1;
		}
		gVehData[vehid-1][CustomObj2Model] = model;
		gVehData[vehid-1][CustomObj2On] = 1;
		gVehData[vehid-1][CustomObj2][0] = Xobj;
		gVehData[vehid-1][CustomObj2][1] = Yobj;
		gVehData[vehid-1][CustomObj2][2] = Zobj;
		gVehData[vehid-1][CustomObj2][3] = rX;
		gVehData[vehid-1][CustomObj2][4] = rY;
		gVehData[vehid-1][CustomObj2][5] = rZ;
		gVehData[vehid-1][CustomObj2ID] = CreateDynamicObject(
			gVehData[vehid-1][CustomObj2Model],
			gVehData[vehid-1][CustomObj2][0],
			gVehData[vehid-1][CustomObj2][1],
			gVehData[vehid-1][CustomObj2][2],
			gVehData[vehid-1][CustomObj2][3],
			gVehData[vehid-1][CustomObj2][4],
			gVehData[vehid-1][CustomObj2][5]);
		AttachDynamicObjectToVehicle(gVehData[vehid-1][CustomObj2ID], vehid, gVehData[vehid-1][CustomObj2][0], gVehData[vehid-1][CustomObj2][1], gVehData[vehid-1][CustomObj2][2], gVehData[vehid-1][CustomObj2][3], gVehData[vehid-1][CustomObj2][4], gVehData[vehid-1][CustomObj2][5]);
		SaveVehData(vehid-1, "CustomObj2Model");
		SaveVehData(vehid-1, "CustomObj2", 0);
		SaveVehData(vehid-1, "CustomObj2", 1);
		SaveVehData(vehid-1, "CustomObj2", 2);
		SaveVehData(vehid-1, "CustomObj2", 3);
		SaveVehData(vehid-1, "CustomObj2", 4);
		SaveVehData(vehid-1, "CustomObj2", 5);
		SaveVehData(vehid-1, "CustomObj2On");
	}
	if(slot == 2)
	{
		if(gVehData[vehid-1][CustomObj3Model] != 0)
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ten slot jest ju¿ zajêty przez inny obiekt !");
			return 1;
		}
		gVehData[vehid-1][CustomObj3Model] = model;
		gVehData[vehid-1][CustomObj3On] = 1;
		gVehData[vehid-1][CustomObj3][0] = Xobj;
		gVehData[vehid-1][CustomObj3][1] = Yobj;
		gVehData[vehid-1][CustomObj3][2] = Zobj;
		gVehData[vehid-1][CustomObj3][3] = rX;
		gVehData[vehid-1][CustomObj3][4] = rY;
		gVehData[vehid-1][CustomObj3][5] = rZ;
		gVehData[vehid-1][CustomObj3ID] = CreateDynamicObject(
			gVehData[vehid-1][CustomObj3Model],
			gVehData[vehid-1][CustomObj3][0],
			gVehData[vehid-1][CustomObj3][1],
			gVehData[vehid-1][CustomObj3][2],
			gVehData[vehid-1][CustomObj3][3],
			gVehData[vehid-1][CustomObj3][4],
			gVehData[vehid-1][CustomObj3][5]);
		AttachDynamicObjectToVehicle(gVehData[vehid-1][CustomObj3ID], vehid, gVehData[vehid-1][CustomObj3][0], gVehData[vehid-1][CustomObj3][1], gVehData[vehid-1][CustomObj3][2], gVehData[vehid-1][CustomObj3][3], gVehData[vehid-1][CustomObj3][4], gVehData[vehid-1][CustomObj3][5]);
		SaveVehData(vehid-1, "CustomObj3Model");
		SaveVehData(vehid-1, "CustomObj3", 0);
		SaveVehData(vehid-1, "CustomObj3", 1);
		SaveVehData(vehid-1, "CustomObj3", 2);
		SaveVehData(vehid-1, "CustomObj3", 3);
		SaveVehData(vehid-1, "CustomObj3", 4);
		SaveVehData(vehid-1, "CustomObj3", 5);
		SaveVehData(vehid-1, "CustomObj3On");
	}
	if(slot == 3)
	{
		if(gVehData[vehid-1][CustomObj4Model] != 0)
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ten slot jest ju¿ zajêty przez inny obiekt !");
			return 1;
		}
		gVehData[vehid-1][CustomObj4Model] = model;
		gVehData[vehid-1][CustomObj4On] = 1;
		gVehData[vehid-1][CustomObj4][0] = Xobj;
		gVehData[vehid-1][CustomObj4][1] = Yobj;
		gVehData[vehid-1][CustomObj4][2] = Zobj;
		gVehData[vehid-1][CustomObj4][3] = rX;
		gVehData[vehid-1][CustomObj4][4] = rY;
		gVehData[vehid-1][CustomObj4][5] = rZ;
		gVehData[vehid-1][CustomObj4ID] = CreateDynamicObject(
			gVehData[vehid-1][CustomObj4Model],
			gVehData[vehid-1][CustomObj4][0],
			gVehData[vehid-1][CustomObj4][1],
			gVehData[vehid-1][CustomObj4][2],
			gVehData[vehid-1][CustomObj4][3],
			gVehData[vehid-1][CustomObj4][4],
			gVehData[vehid-1][CustomObj4][5]);
		AttachDynamicObjectToVehicle(gVehData[vehid-1][CustomObj4ID], vehid, gVehData[vehid-1][CustomObj4][0], gVehData[vehid-1][CustomObj4][1], gVehData[vehid-1][CustomObj4][2], gVehData[vehid-1][CustomObj4][3], gVehData[vehid-1][CustomObj4][4], gVehData[vehid-1][CustomObj4][5]);
		SaveVehData(vehid-1, "CustomObj4Model");
		SaveVehData(vehid-1, "CustomObj4", 0);
		SaveVehData(vehid-1, "CustomObj4", 1);
		SaveVehData(vehid-1, "CustomObj4", 2);
		SaveVehData(vehid-1, "CustomObj4", 3);
		SaveVehData(vehid-1, "CustomObj4", 4);
		SaveVehData(vehid-1, "CustomObj4", 5);
		SaveVehData(vehid-1, "CustomObj4On");
	}
	if(slot == 4)
	{
		if(gVehData[vehid-1][CustomObj5Model] != 0)
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ten slot jest ju¿ zajêty przez inny obiekt !");
			return 1;
		}
		gVehData[vehid-1][CustomObj5Model] = model;
		gVehData[vehid-1][CustomObj5On] = 1;
		gVehData[vehid-1][CustomObj5][0] = Xobj;
		gVehData[vehid-1][CustomObj5][1] = Yobj;
		gVehData[vehid-1][CustomObj5][2] = Zobj;
		gVehData[vehid-1][CustomObj5][3] = rX;
		gVehData[vehid-1][CustomObj5][4] = rY;
		gVehData[vehid-1][CustomObj5][5] = rZ;
		gVehData[vehid-1][CustomObj5ID] = CreateDynamicObject(
			gVehData[vehid-1][CustomObj5Model],
			gVehData[vehid-1][CustomObj5][0],
			gVehData[vehid-1][CustomObj5][1],
			gVehData[vehid-1][CustomObj5][2],
			gVehData[vehid-1][CustomObj5][3],
			gVehData[vehid-1][CustomObj5][4],
			gVehData[vehid-1][CustomObj5][5]);
		AttachDynamicObjectToVehicle(gVehData[vehid-1][CustomObj5ID], vehid, gVehData[vehid-1][CustomObj5][0], gVehData[vehid-1][CustomObj5][1], gVehData[vehid-1][CustomObj5][2], gVehData[vehid-1][CustomObj5][3], gVehData[vehid-1][CustomObj5][4], gVehData[vehid-1][CustomObj5][5]);
		SaveVehData(vehid-1, "CustomObj5Model");
		SaveVehData(vehid-1, "CustomObj5", 0);
		SaveVehData(vehid-1, "CustomObj5", 1);
		SaveVehData(vehid-1, "CustomObj5", 2);
		SaveVehData(vehid-1, "CustomObj5", 3);
		SaveVehData(vehid-1, "CustomObj5", 4);
		SaveVehData(vehid-1, "CustomObj5", 5);
		SaveVehData(vehid-1, "CustomObj5On");
	}
	if(slot == 5)
	{
		if(gVehData[vehid-1][CustomObj6Model] != 0)
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ten slot jest ju¿ zajêty przez inny obiekt !");
			return 1;
		}
		gVehData[vehid-1][CustomObj6Model] = model;
		gVehData[vehid-1][CustomObj6On] = 1;
		gVehData[vehid-1][CustomObj6][0] = Xobj;
		gVehData[vehid-1][CustomObj6][1] = Yobj;
		gVehData[vehid-1][CustomObj6][2] = Zobj;
		gVehData[vehid-1][CustomObj6][3] = rX;
		gVehData[vehid-1][CustomObj6][4] = rY;
		gVehData[vehid-1][CustomObj6][5] = rZ;
		gVehData[vehid-1][CustomObj6ID] = CreateDynamicObject(
			gVehData[vehid-1][CustomObj6Model],
			gVehData[vehid-1][CustomObj6][0],
			gVehData[vehid-1][CustomObj6][1],
			gVehData[vehid-1][CustomObj6][2],
			gVehData[vehid-1][CustomObj6][3],
			gVehData[vehid-1][CustomObj6][4],
			gVehData[vehid-1][CustomObj6][5]);
		AttachDynamicObjectToVehicle(gVehData[vehid-1][CustomObj6ID], vehid, gVehData[vehid-1][CustomObj6][0], gVehData[vehid-1][CustomObj6][1], gVehData[vehid-1][CustomObj6][2], gVehData[vehid-1][CustomObj6][3], gVehData[vehid-1][CustomObj6][4], gVehData[vehid-1][CustomObj6][5]);
		SaveVehData(vehid-1, "CustomObj6Model");
		SaveVehData(vehid-1, "CustomObj6", 0);
		SaveVehData(vehid-1, "CustomObj6", 1);
		SaveVehData(vehid-1, "CustomObj6", 2);
		SaveVehData(vehid-1, "CustomObj6", 3);
		SaveVehData(vehid-1, "CustomObj6", 4);
		SaveVehData(vehid-1, "CustomObj6", 5);
		SaveVehData(vehid-1, "CustomObj6On");
	}
	if(slot == 6)
	{
		if(gVehData[vehid-1][CustomObj7Model] != 0)
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ten slot jest ju¿ zajêty przez inny obiekt !");
			return 1;
		}
		gVehData[vehid-1][CustomObj7Model] = model;
		gVehData[vehid-1][CustomObj7On] = 1;
		gVehData[vehid-1][CustomObj7][0] = Xobj;
		gVehData[vehid-1][CustomObj7][1] = Yobj;
		gVehData[vehid-1][CustomObj7][2] = Zobj;
		gVehData[vehid-1][CustomObj7][3] = rX;
		gVehData[vehid-1][CustomObj7][4] = rY;
		gVehData[vehid-1][CustomObj7][5] = rZ;
		gVehData[vehid-1][CustomObj7ID] = CreateDynamicObject(
			gVehData[vehid-1][CustomObj7Model],
			gVehData[vehid-1][CustomObj7][0],
			gVehData[vehid-1][CustomObj7][1],
			gVehData[vehid-1][CustomObj7][2],
			gVehData[vehid-1][CustomObj7][3],
			gVehData[vehid-1][CustomObj7][4],
			gVehData[vehid-1][CustomObj7][5]);
		AttachDynamicObjectToVehicle(gVehData[vehid-1][CustomObj7ID], vehid, gVehData[vehid-1][CustomObj7][0], gVehData[vehid-1][CustomObj7][1], gVehData[vehid-1][CustomObj7][2], gVehData[vehid-1][CustomObj7][3], gVehData[vehid-1][CustomObj7][4], gVehData[vehid-1][CustomObj7][5]);
		SaveVehData(vehid-1, "CustomObj7Model");
		SaveVehData(vehid-1, "CustomObj7", 0);
		SaveVehData(vehid-1, "CustomObj7", 1);
		SaveVehData(vehid-1, "CustomObj7", 2);
		SaveVehData(vehid-1, "CustomObj7", 3);
		SaveVehData(vehid-1, "CustomObj7", 4);
		SaveVehData(vehid-1, "CustomObj7", 5);
		SaveVehData(vehid-1, "CustomObj7On");
	}
	if(model == 18647)
	{
		gPlayerData[playerid][pVipRedNeon]--;
		SavePlayerData(playerid, "VipRedNeon");
		printf("[VIP:] /doczepneon used by %s - color: red", GetPlayerNameEx(playerid));
	}
	else if(model == 18648)
	{
		gPlayerData[playerid][pVipBlueNeon]--;
		SavePlayerData(playerid, "VipBlueNeon");
		printf("[VIP:] /doczepneon used by %s - color: blue", GetPlayerNameEx(playerid));
	}
	else if(model == 18649)
	{
		gPlayerData[playerid][pVipBlueNeon]--;
		SavePlayerData(playerid, "VipGreenNeon");
		printf("[VIP:] /doczepneon used by %s - color: green", GetPlayerNameEx(playerid));
	}
	else if(model == 18650)
	{
		gPlayerData[playerid][pVipYellowNeon]--;
		SavePlayerData(playerid, "VipYellowNeon");
		printf("[VIP:] /doczepneon used by %s - color: yellow", GetPlayerNameEx(playerid));
	}
	else if(model == 18651)
	{
		gPlayerData[playerid][pVipPinkNeon]--;
		SavePlayerData(playerid, "VipPinkNeon");
		printf("[VIP:] /doczepneon used by %s - color: pink", GetPlayerNameEx(playerid));
	}
	else if(model == 18652)
	{
		gPlayerData[playerid][pVipWhiteNeon]--;
		SavePlayerData(playerid, "VipWhiteNeon");
		printf("[VIP:] /doczepneon used by %s - color: white", GetPlayerNameEx(playerid));
	}
	else if(model == 19280)
	{
		gPlayerData[playerid][pVipHalogenLight]--;
		SavePlayerData(playerid, "VipHalogenLight");
		printf("[VIP:] /doczepobiekt used by %s - object: halogen light", GetPlayerNameEx(playerid));
	}
	else if(model == 19281)
	{
		gPlayerData[playerid][pVipWhitePointLight]--;
		SavePlayerData(playerid, "VipWhitePointLight");
		printf("[VIP:] /doczepobiekt used by %s - object: point white", GetPlayerNameEx(playerid));
	}
	else if(model == 19282)
	{
		gPlayerData[playerid][pVipRedPointLight]--;
		SavePlayerData(playerid, "VipRedPointLight");
		printf("[VIP:] /doczepobiekt used by %s - object: point red", GetPlayerNameEx(playerid));
	}
	else if(model == 19283)
	{
		gPlayerData[playerid][pVipGreenPointLight]--;
		SavePlayerData(playerid, "VipGreenPointLight");
		printf("[VIP:] /doczepobiekt used by %s - object: point green", GetPlayerNameEx(playerid));
	}
	else if(model == 19284)
	{
		gPlayerData[playerid][pVipBluePointLight]--;
		SavePlayerData(playerid, "VipBluePointLight");
		printf("[VIP:] /doczepobiekt used by %s - object: point blue", GetPlayerNameEx(playerid));
	}
	return 1;
}

dcmd_moatv(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;

	new slot, modelid, Float:Xobj, Float:Yobj, Float:Zobj, Float:rX, Float:rY, Float:rZ, vehid;
	if(sscanf(params, "ddffffff", slot, modelid, Xobj, Yobj, Zobj, rX, rY, rZ))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /moatv [slot] [modelid] [X] [Y] [Z] [rX] [rY] [rZ]");
		return 1;
	}
	vehid = GetPlayerVehicleID(playerid);
	if( Xobj > 1.5 )
		Xobj = 1.5;
	else if( Xobj < -1.5 )
		Xobj = -1.5;
	if( Yobj > 3.3 )
		Yobj = 3.3;
	else if( Yobj < -3.5 )
		Yobj = -3.5;
	if( Zobj > 2.0 )
		Zobj = 2.0;
	else if( Zobj < -1.5 )
		Zobj = -1.5;
	if( slot == 0 )
	{
		gVehData[vehid-1][CustomObj1Model] = modelid;
		gVehData[vehid-1][CustomObj1][0] = Xobj;
		gVehData[vehid-1][CustomObj1][1] = Yobj;
		gVehData[vehid-1][CustomObj1][2] = Zobj;
		gVehData[vehid-1][CustomObj1][3] = rX;
		gVehData[vehid-1][CustomObj1][4] = rY;
		gVehData[vehid-1][CustomObj1][5] = rZ;
		if( gVehData[vehid-1][CustomObj1ID] != 0 )
			DestroyDynamicObject(gVehData[vehid-1][CustomObj1ID]);
		gVehData[vehid-1][CustomObj1ID] = CreateDynamicObject(
																	gVehData[vehid-1][CustomObj1Model],
																	gVehData[vehid-1][CustomObj1][0],
																	gVehData[vehid-1][CustomObj1][1],
																	gVehData[vehid-1][CustomObj1][2],
																	gVehData[vehid-1][CustomObj1][3],
																	gVehData[vehid-1][CustomObj1][4],
																	gVehData[vehid-1][CustomObj1][5]);
		AttachDynamicObjectToVehicle(gVehData[vehid-1][CustomObj1ID], vehid, gVehData[vehid-1][CustomObj1][0], gVehData[vehid-1][CustomObj1][1], gVehData[vehid-1][CustomObj1][2], gVehData[vehid-1][CustomObj1][3], gVehData[vehid-1][CustomObj1][4], gVehData[vehid-1][CustomObj1][5]);
		SaveVehData(vehid-1, "CustomObj1Model" );
		SaveVehData(vehid-1, "CustomObj1", 0 );
		SaveVehData(vehid-1, "CustomObj1", 1 );
		SaveVehData(vehid-1, "CustomObj1", 2 );
		SaveVehData(vehid-1, "CustomObj1", 3 );
		SaveVehData(vehid-1, "CustomObj1", 4 );
		SaveVehData(vehid-1, "CustomObj1", 5 );
	}
	if( slot == 1 )
	{
		gVehData[vehid-1][CustomObj2Model] = modelid;
		gVehData[vehid-1][CustomObj2][0] = Xobj;
		gVehData[vehid-1][CustomObj2][1] = Yobj;
		gVehData[vehid-1][CustomObj2][2] = Zobj;
		gVehData[vehid-1][CustomObj2][3] = rX;
		gVehData[vehid-1][CustomObj2][4] = rY;
		gVehData[vehid-1][CustomObj2][5] = rZ;
		if(  gVehData[vehid-1][CustomObj2ID] != 0 )
			DestroyDynamicObject(gVehData[vehid-1][CustomObj2ID]);
		gVehData[vehid-1][CustomObj2ID] = CreateDynamicObject(
																	gVehData[vehid-1][CustomObj2Model],
																	gVehData[vehid-1][CustomObj2][0],
																	gVehData[vehid-1][CustomObj2][1],
																	gVehData[vehid-1][CustomObj2][2],
																	gVehData[vehid-1][CustomObj2][3],
																	gVehData[vehid-1][CustomObj2][4],
																	gVehData[vehid-1][CustomObj2][5]);
		AttachDynamicObjectToVehicle(gVehData[vehid-1][CustomObj2ID], vehid, gVehData[vehid-1][CustomObj2][0], gVehData[vehid-1][CustomObj2][1], gVehData[vehid-1][CustomObj2][2], gVehData[vehid-1][CustomObj2][3], gVehData[vehid-1][CustomObj2][4], gVehData[vehid-1][CustomObj2][5]);
		SaveVehData(vehid-1, "CustomObj2Model" );
		SaveVehData(vehid-1, "CustomObj2", 0 );
		SaveVehData(vehid-1, "CustomObj2", 1 );
		SaveVehData(vehid-1, "CustomObj2", 2 );
		SaveVehData(vehid-1, "CustomObj2", 3 );
		SaveVehData(vehid-1, "CustomObj2", 4 );
		SaveVehData(vehid-1, "CustomObj2", 5 );
	}
	if( slot == 2 )
	{
		gVehData[vehid-1][CustomObj3Model] = modelid;
		gVehData[vehid-1][CustomObj3][0] = Xobj;
		gVehData[vehid-1][CustomObj3][1] = Yobj;
		gVehData[vehid-1][CustomObj3][2] = Zobj;
		gVehData[vehid-1][CustomObj3][3] = rX;
		gVehData[vehid-1][CustomObj3][4] = rY;
		gVehData[vehid-1][CustomObj3][5] = rZ;
		if( gVehData[vehid-1][CustomObj3ID] != 0 )
			DestroyDynamicObject(gVehData[vehid-1][CustomObj3ID]);
		gVehData[vehid-1][CustomObj3ID] = CreateDynamicObject(
																	gVehData[vehid-1][CustomObj3Model],
																	gVehData[vehid-1][CustomObj3][0],
																	gVehData[vehid-1][CustomObj3][1],
																	gVehData[vehid-1][CustomObj3][2],
																	gVehData[vehid-1][CustomObj3][3],
																	gVehData[vehid-1][CustomObj3][4],
																	gVehData[vehid-1][CustomObj3][5]);
		AttachDynamicObjectToVehicle(gVehData[vehid-1][CustomObj3ID], vehid, gVehData[vehid-1][CustomObj3][0], gVehData[vehid-1][CustomObj3][1], gVehData[vehid-1][CustomObj3][2], gVehData[vehid-1][CustomObj3][3], gVehData[vehid-1][CustomObj3][4], gVehData[vehid-1][CustomObj3][5]);
		SaveVehData(vehid-1, "CustomObj3Model" );
		SaveVehData(vehid-1, "CustomObj3", 0 );
		SaveVehData(vehid-1, "CustomObj3", 1 );
		SaveVehData(vehid-1, "CustomObj3", 2 );
		SaveVehData(vehid-1, "CustomObj3", 3 );
		SaveVehData(vehid-1, "CustomObj3", 4 );
		SaveVehData(vehid-1, "CustomObj3", 5 );
	}
	if( slot == 3 )
	{
		gVehData[vehid-1][CustomObj4Model] = modelid;
		gVehData[vehid-1][CustomObj4][0] = Xobj;
		gVehData[vehid-1][CustomObj4][1] = Yobj;
		gVehData[vehid-1][CustomObj4][2] = Zobj;
		gVehData[vehid-1][CustomObj4][3] = rX;
		gVehData[vehid-1][CustomObj4][4] = rY;
		gVehData[vehid-1][CustomObj4][5] = rZ;
		if( gVehData[vehid-1][CustomObj4ID] != 0 )
			DestroyDynamicObject(gVehData[vehid-1][CustomObj4ID]);
		gVehData[vehid-1][CustomObj4ID] = CreateDynamicObject(
																	gVehData[vehid-1][CustomObj4Model],
																	gVehData[vehid-1][CustomObj4][0],
																	gVehData[vehid-1][CustomObj4][1],
																	gVehData[vehid-1][CustomObj4][2],
																	gVehData[vehid-1][CustomObj4][3],
																	gVehData[vehid-1][CustomObj4][4],
																	gVehData[vehid-1][CustomObj4][5]);
		AttachDynamicObjectToVehicle(gVehData[vehid-1][CustomObj4ID], vehid, gVehData[vehid-1][CustomObj4][0], gVehData[vehid-1][CustomObj4][1], gVehData[vehid-1][CustomObj4][2], gVehData[vehid-1][CustomObj4][3], gVehData[vehid-1][CustomObj4][4], gVehData[vehid-1][CustomObj4][5]);
		SaveVehData(vehid-1, "CustomObj4Model" );
		SaveVehData(vehid-1, "CustomObj4", 0 );
		SaveVehData(vehid-1, "CustomObj4", 1 );
		SaveVehData(vehid-1, "CustomObj4", 2 );
		SaveVehData(vehid-1, "CustomObj4", 3 );
		SaveVehData(vehid-1, "CustomObj4", 4 );
		SaveVehData(vehid-1, "CustomObj4", 5 );
	}
	if( slot == 4 )
	{
		gVehData[vehid-1][CustomObj5Model] = modelid;
		gVehData[vehid-1][CustomObj5][0] = Xobj;
		gVehData[vehid-1][CustomObj5][1] = Yobj;
		gVehData[vehid-1][CustomObj5][2] = Zobj;
		gVehData[vehid-1][CustomObj5][3] = rX;
		gVehData[vehid-1][CustomObj5][4] = rY;
		gVehData[vehid-1][CustomObj5][5] = rZ;
		if( gVehData[vehid-1][CustomObj5ID] != 0 )
			DestroyDynamicObject(gVehData[vehid-1][CustomObj5ID]);
		gVehData[vehid-1][CustomObj5ID] = CreateDynamicObject(
																	gVehData[vehid-1][CustomObj5Model],
																	gVehData[vehid-1][CustomObj5][0],
																	gVehData[vehid-1][CustomObj5][1],
																	gVehData[vehid-1][CustomObj5][2],
																	gVehData[vehid-1][CustomObj5][3],
																	gVehData[vehid-1][CustomObj5][4],
																	gVehData[vehid-1][CustomObj5][5]);
		AttachDynamicObjectToVehicle(gVehData[vehid-1][CustomObj5ID], vehid, gVehData[vehid-1][CustomObj5][0], gVehData[vehid-1][CustomObj5][1], gVehData[vehid-1][CustomObj5][2], gVehData[vehid-1][CustomObj5][3], gVehData[vehid-1][CustomObj5][4], gVehData[vehid-1][CustomObj5][5]);
		SaveVehData(vehid-1, "CustomObj5Model" );
		SaveVehData(vehid-1, "CustomObj5", 0 );
		SaveVehData(vehid-1, "CustomObj5", 1 );
		SaveVehData(vehid-1, "CustomObj5", 2 );
		SaveVehData(vehid-1, "CustomObj5", 3 );
		SaveVehData(vehid-1, "CustomObj5", 4 );
		SaveVehData(vehid-1, "CustomObj5", 5 );
	}
	if( slot == 5 )
	{
		gVehData[vehid-1][CustomObj6Model] = modelid;
		gVehData[vehid-1][CustomObj6][0] = Xobj;
		gVehData[vehid-1][CustomObj6][1] = Yobj;
		gVehData[vehid-1][CustomObj6][2] = Zobj;
		gVehData[vehid-1][CustomObj6][3] = rX;
		gVehData[vehid-1][CustomObj6][4] = rY;
		gVehData[vehid-1][CustomObj6][5] = rZ;
		if( gVehData[vehid-1][CustomObj6ID] != 0 )
			DestroyDynamicObject(gVehData[vehid-1][CustomObj6ID]);
		gVehData[vehid-1][CustomObj6ID] = CreateDynamicObject(
																	gVehData[vehid-1][CustomObj6Model],
																	gVehData[vehid-1][CustomObj6][0],
																	gVehData[vehid-1][CustomObj6][1],
																	gVehData[vehid-1][CustomObj6][2],
																	gVehData[vehid-1][CustomObj6][3],
																	gVehData[vehid-1][CustomObj6][4],
																	gVehData[vehid-1][CustomObj6][5]);
		AttachDynamicObjectToVehicle(gVehData[vehid-1][CustomObj6ID], vehid, gVehData[vehid-1][CustomObj6][0], gVehData[vehid-1][CustomObj6][1], gVehData[vehid-1][CustomObj6][2], gVehData[vehid-1][CustomObj6][3], gVehData[vehid-1][CustomObj6][4], gVehData[vehid-1][CustomObj6][5]);
		SaveVehData(vehid-1, "CustomObj6Model" );
		SaveVehData(vehid-1, "CustomObj6", 0 );
		SaveVehData(vehid-1, "CustomObj6", 1 );
		SaveVehData(vehid-1, "CustomObj6", 2 );
		SaveVehData(vehid-1, "CustomObj6", 3 );
		SaveVehData(vehid-1, "CustomObj6", 4 );
		SaveVehData(vehid-1, "CustomObj6", 5 );
	}
	if( slot == 6 )
	{
		gVehData[vehid-1][CustomObj7Model] = modelid;
		gVehData[vehid-1][CustomObj7][0] = Xobj;
		gVehData[vehid-1][CustomObj7][1] = Yobj;
		gVehData[vehid-1][CustomObj7][2] = Zobj;
		gVehData[vehid-1][CustomObj7][3] = rX;
		gVehData[vehid-1][CustomObj7][4] = rY;
		gVehData[vehid-1][CustomObj7][5] = rZ;
		if( gVehData[vehid-1][CustomObj7ID] != 0 )
			DestroyDynamicObject(gVehData[vehid-1][CustomObj7ID]);
		gVehData[vehid-1][CustomObj7ID] = CreateDynamicObject(
																	gVehData[vehid-1][CustomObj7Model],
																	gVehData[vehid-1][CustomObj7][0],
																	gVehData[vehid-1][CustomObj7][1],
																	gVehData[vehid-1][CustomObj7][2],
																	gVehData[vehid-1][CustomObj7][3],
																	gVehData[vehid-1][CustomObj7][4],
																	gVehData[vehid-1][CustomObj7][5]);
		AttachDynamicObjectToVehicle(gVehData[vehid-1][CustomObj7ID], vehid, gVehData[vehid-1][CustomObj7][0], gVehData[vehid-1][CustomObj7][1], gVehData[vehid-1][CustomObj7][2], gVehData[vehid-1][CustomObj7][3], gVehData[vehid-1][CustomObj7][4], gVehData[vehid-1][CustomObj7][5]);
		SaveVehData(vehid-1, "CustomObj7Model" );
		SaveVehData(vehid-1, "CustomObj7", 0 );
		SaveVehData(vehid-1, "CustomObj7", 1 );
		SaveVehData(vehid-1, "CustomObj7", 2 );
		SaveVehData(vehid-1, "CustomObj7", 3 );
		SaveVehData(vehid-1, "CustomObj7", 4 );
		SaveVehData(vehid-1, "CustomObj7", 5 );
	}
	return 1;
}

// TODO: Add save
dcmd_rvobj(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new slot;
	if(sscanf(params, "d", slot))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /rvobj [slot]");
		return 1;
	}
	new vehid = GetPlayerVehicleID(playerid);
	if( slot == 0 )
	{
		DestroyDynamicObject(gVehData[vehid-1][CustomObj1ID]);
		gVehData[vehid-1][CustomObj1Model] = 0;
	}
	if( slot == 1 )
	{
		DestroyDynamicObject(gVehData[vehid-1][CustomObj2ID]);
		gVehData[vehid-1][CustomObj2Model] = 0;
	}
	if( slot == 2 )
	{
		DestroyDynamicObject(gVehData[vehid-1][CustomObj3ID]);
		gVehData[vehid-1][CustomObj3Model] = 0;
	}
	if( slot == 3 )
	{
		DestroyDynamicObject(gVehData[vehid-1][CustomObj4ID]);
		gVehData[vehid-1][CustomObj4Model] = 0;
	}
	if( slot == 4 )
	{
		DestroyDynamicObject(gVehData[vehid-1][CustomObj5ID]);
		gVehData[vehid-1][CustomObj5Model] = 0;
	}
	if( slot == 5 )
	{
		DestroyDynamicObject(gVehData[vehid-1][CustomObj6ID]);
		gVehData[vehid-1][CustomObj6Model] = 0;
	}
	return 1;
}

dcmd_pozycjaobiektupoj(playerid, params[])
{
	new slot, string[128];
	if(sscanf(params, "d", slot))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /pozycjaobiektupoj [slot (0-6)]");
		return 1;
	}
	new vehid = GetPlayerVehicleID(playerid);
	if(vehid == 0)
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w pojeŸdzie !");
		return 1;
	}
	if(slot < 0 || slot > 6)
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /pozycjaobiektupoj [slot (0-6)]");
		return 1;
	}
	switch(slot)
	{
		case 0:
		{
			if(gVehData[vehid-1][CustomObj1Model] == 0)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz obiektu na tym slocie");
				return 1;
			}
			format(string, sizeof(string), "X: %.2f, Y: %.2f, Z: %.2f, Xr: %.2f, Yr: %.2f, Zr: %.2f",
				gVehData[vehid-1][CustomObj1][0], 
				gVehData[vehid-1][CustomObj1][1], 
				gVehData[vehid-1][CustomObj1][2], 
				gVehData[vehid-1][CustomObj1][3], 
				gVehData[vehid-1][CustomObj1][4], 
				gVehData[vehid-1][CustomObj1][5]);
		}
		case 1:
		{
			if(gVehData[vehid-1][CustomObj2Model] == 0)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz obiektu na tym slocie");
				return 1;
			}
			format(string, sizeof(string), "X: %.2f, Y: %.2f, Z: %.2f, Xr: %.2f, Yr: %.2f, Zr: %.2f",
				gVehData[vehid-1][CustomObj2][0], 
				gVehData[vehid-1][CustomObj2][1], 
				gVehData[vehid-1][CustomObj2][2], 
				gVehData[vehid-1][CustomObj2][3], 
				gVehData[vehid-1][CustomObj2][4], 
				gVehData[vehid-1][CustomObj2][5]);
		}
		case 2:
		{
			if(gVehData[vehid-1][CustomObj3Model] == 0)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz obiektu na tym slocie");
				return 1;
			}
			format(string, sizeof(string), "X: %.2f, Y: %.2f, Z: %.2f, Xr: %.2f, Yr: %.2f, Zr: %.2f",
				gVehData[vehid-1][CustomObj3][0], 
				gVehData[vehid-1][CustomObj3][1], 
				gVehData[vehid-1][CustomObj3][2], 
				gVehData[vehid-1][CustomObj3][3], 
				gVehData[vehid-1][CustomObj3][4], 
				gVehData[vehid-1][CustomObj3][5]);
		}
		case 3:
		{
			if(gVehData[vehid-1][CustomObj4Model] == 0)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz obiektu na tym slocie");
				return 1;
			}
			format(string, sizeof(string), "X: %.2f, Y: %.2f, Z: %.2f, Xr: %.2f, Yr: %.2f, Zr: %.2f",
				gVehData[vehid-1][CustomObj4][0], 
				gVehData[vehid-1][CustomObj4][1], 
				gVehData[vehid-1][CustomObj4][2], 
				gVehData[vehid-1][CustomObj4][3], 
				gVehData[vehid-1][CustomObj4][4], 
				gVehData[vehid-1][CustomObj4][5]);
		}
		case 4:
		{
			if(gVehData[vehid-1][CustomObj5Model] == 0)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz obiektu na tym slocie");
				return 1;
			}
			format(string, sizeof(string), "X: %.2f, Y: %.2f, Z: %.2f, Xr: %.2f, Yr: %.2f, Zr: %.2f",
				gVehData[vehid-1][CustomObj5][0], 
				gVehData[vehid-1][CustomObj5][1], 
				gVehData[vehid-1][CustomObj5][2], 
				gVehData[vehid-1][CustomObj5][3], 
				gVehData[vehid-1][CustomObj5][4], 
				gVehData[vehid-1][CustomObj5][5]);
		}
		case 5:
		{
			if(gVehData[vehid-1][CustomObj6Model] == 0)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz obiektu na tym slocie");
				return 1;
			}
			format(string, sizeof(string), "X: %.2f, Y: %.2f, Z: %.2f, Xr: %.2f, Yr: %.2f, Zr: %.2f",
				gVehData[vehid-1][CustomObj6][0], 
				gVehData[vehid-1][CustomObj6][1], 
				gVehData[vehid-1][CustomObj6][2], 
				gVehData[vehid-1][CustomObj6][3], 
				gVehData[vehid-1][CustomObj6][4], 
				gVehData[vehid-1][CustomObj6][5]);
		}
		case 6:
		{
			if(gVehData[vehid-1][CustomObj7Model] == 0)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz obiektu na tym slocie");
				return 1;
			}
			format(string, sizeof(string), "X: %.2f, Y: %.2f, Z: %.2f, Xr: %.2f, Yr: %.2f, Zr: %.2f",
				gVehData[vehid-1][CustomObj7][0], 
				gVehData[vehid-1][CustomObj7][1], 
				gVehData[vehid-1][CustomObj7][2], 
				gVehData[vehid-1][CustomObj7][3], 
				gVehData[vehid-1][CustomObj7][4], 
				gVehData[vehid-1][CustomObj7][5]);
		}
	}
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	return 1;
}

dcmd_ustawobiektpoj(playerid, params[])
{
	new slot, Float:mx, Float:my, Float:mz;
	if(sscanf(params, "dfff", slot, mx, my, mz))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /ustawobiektpoj [slot] [x] [y] [z]");
		return 1;
	}
	new vehid = GetPlayerVehicleID(playerid);
	if(vehid == 0)
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w pojeŸdzie !");
		return 1;
	}
	if(slot < 0 || slot > 6)
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /ustawobiektpoj [slot (0-6)] [x] [y] [z]");
		return 1;
	}
		
	if( mx > 2.5 )
		mx = 2.5;
	else if( mx < -2.5 )
		mx = -2.5;
	if( my > 3.3 )
		my = 3.3;
	else if( my < -5.0 )
		my = -5.0;
	if( mz > 2.5 )
		mz = 2.5;
	else if( mz < -1.5 )
		mz = -1.5;
	
	if( slot == 0)
	{
		if(gVehData[vehid-1][CustomObj1On] && gVehData[vehid-1][CustomObj1Model] != 0)
		{
			gVehData[vehid-1][CustomObj1][0] = mx;
			gVehData[vehid-1][CustomObj1][1] = my;
			gVehData[vehid-1][CustomObj1][2] = mz;
			SaveVehData( vehid-1, "CustomObj1", 0 );
			SaveVehData( vehid-1, "CustomObj1", 1 );
			SaveVehData( vehid-1, "CustomObj1", 2 );
			AttachDynamicObjectToVehicle( gVehData[vehid-1][CustomObj1ID], vehid, gVehData[vehid-1][CustomObj1][0], gVehData[vehid-1][CustomObj1][1], gVehData[vehid-1][CustomObj1][2], gVehData[vehid-1][CustomObj1][3], gVehData[vehid-1][CustomObj1][4], gVehData[vehid-1][CustomObj1][5] );
		}
	}
	if( slot == 1)
	{
		if(gVehData[vehid-1][CustomObj2On] && gVehData[vehid-1][CustomObj2Model] != 0)
		{
			gVehData[vehid-1][CustomObj2][0] = mx;
			gVehData[vehid-1][CustomObj2][1] = my;
			gVehData[vehid-1][CustomObj2][2] = mz;
			SaveVehData( vehid-1, "CustomObj2", 0 );
			SaveVehData( vehid-1, "CustomObj2", 1 );
			SaveVehData( vehid-1, "CustomObj2", 2 );
			AttachDynamicObjectToVehicle( gVehData[vehid-1][CustomObj2ID], vehid, gVehData[vehid-1][CustomObj2][0], gVehData[vehid-1][CustomObj2][1], gVehData[vehid-1][CustomObj2][2], gVehData[vehid-1][CustomObj2][3], gVehData[vehid-1][CustomObj2][4], gVehData[vehid-1][CustomObj2][5] );
		}
	}
	if( slot == 2)
	{
		if(gVehData[vehid-1][CustomObj3On] && gVehData[vehid-1][CustomObj3Model] != 0)
		{
			gVehData[vehid-1][CustomObj3][0] = mx;
			gVehData[vehid-1][CustomObj3][1] = my;
			gVehData[vehid-1][CustomObj3][2] = mz;
			SaveVehData( vehid-1, "CustomObj3", 0 );
			SaveVehData( vehid-1, "CustomObj3", 1 );
			SaveVehData( vehid-1, "CustomObj3", 2 );
			AttachDynamicObjectToVehicle(gVehData[vehid-1][CustomObj3ID], vehid, gVehData[vehid-1][CustomObj3][0], gVehData[vehid-1][CustomObj3][1], gVehData[vehid-1][CustomObj3][2], gVehData[vehid-1][CustomObj3][3], gVehData[vehid-1][CustomObj3][4], gVehData[vehid-1][CustomObj3][5]);
		}
	}
	if( slot == 3)
	{
		if( gVehData[vehid-1][CustomObj4On] && gVehData[vehid-1][CustomObj4Model] != 0 )
		{
			gVehData[vehid-1][CustomObj4][0] = mx;
			gVehData[vehid-1][CustomObj4][1] = my;
			gVehData[vehid-1][CustomObj4][2] = mz;
			SaveVehData( vehid-1, "CustomObj4", 0 );
			SaveVehData( vehid-1, "CustomObj4", 1 );
			SaveVehData( vehid-1, "CustomObj4", 2 );
			AttachDynamicObjectToVehicle(gVehData[vehid-1][CustomObj4ID], vehid, gVehData[vehid-1][CustomObj4][0], gVehData[vehid-1][CustomObj4][1], gVehData[vehid-1][CustomObj4][2], gVehData[vehid-1][CustomObj4][3], gVehData[vehid-1][CustomObj4][4], gVehData[vehid-1][CustomObj4][5]);
		}
	}
	if( slot == 4)
	{
		if( gVehData[vehid-1][CustomObj5On] && gVehData[vehid-1][CustomObj5Model] != 0 )
		{
			gVehData[vehid-1][CustomObj5][0] = mx;
			gVehData[vehid-1][CustomObj5][1] = my;
			gVehData[vehid-1][CustomObj5][2] = mz;
			SaveVehData( vehid-1, "CustomObj5", 0 );
			SaveVehData( vehid-1, "CustomObj5", 1 );
			SaveVehData( vehid-1, "CustomObj5", 2 );
			AttachDynamicObjectToVehicle(gVehData[vehid-1][CustomObj5ID], vehid, gVehData[vehid-1][CustomObj5][0], gVehData[vehid-1][CustomObj5][1], gVehData[vehid-1][CustomObj5][2], gVehData[vehid-1][CustomObj5][3], gVehData[vehid-1][CustomObj5][4], gVehData[vehid-1][CustomObj5][5]);
		}
	}
	if( slot == 5)
	{
		if( gVehData[vehid-1][CustomObj6On] && gVehData[vehid-1][CustomObj6Model] != 0 )
		{
			gVehData[vehid-1][CustomObj6][0] = mx;
			gVehData[vehid-1][CustomObj6][1] = my;
			gVehData[vehid-1][CustomObj6][2] = mz;
			SaveVehData( vehid-1, "CustomObj6", 0 );
			SaveVehData( vehid-1, "CustomObj6", 1 );
			SaveVehData( vehid-1, "CustomObj6", 2 );
			AttachDynamicObjectToVehicle(gVehData[vehid-1][CustomObj6ID], vehid, gVehData[vehid-1][CustomObj6][0], gVehData[vehid-1][CustomObj6][1], gVehData[vehid-1][CustomObj6][2], gVehData[vehid-1][CustomObj6][3], gVehData[vehid-1][CustomObj6][4], gVehData[vehid-1][CustomObj6][5]);
		}
	}
	if( slot == 6)
	{
		if( gVehData[vehid-1][CustomObj7On] && gVehData[vehid-1][CustomObj7Model] != 0 )
		{
			gVehData[vehid-1][CustomObj7][0] = mx;
			gVehData[vehid-1][CustomObj7][1] = my;
			gVehData[vehid-1][CustomObj7][2] = mz;
			SaveVehData( vehid-1, "CustomObj7", 0 );
			SaveVehData( vehid-1, "CustomObj7", 1 );
			SaveVehData( vehid-1, "CustomObj7", 2 );
			AttachDynamicObjectToVehicle(gVehData[vehid-1][CustomObj7ID], vehid, gVehData[vehid-1][CustomObj7][0], gVehData[vehid-1][CustomObj7][1], gVehData[vehid-1][CustomObj7][2], gVehData[vehid-1][CustomObj7][3], gVehData[vehid-1][CustomObj7][4], gVehData[vehid-1][CustomObj7][5]);
		}
	}
	new string[128];
	format(string, sizeof(string), "[INFO:] Nowa pozycja neonu X: %f, Y: %f, Z: %f", mx, my, mz);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	return 1;
}

dcmd_obrocobiektpoj(playerid, params[])
{
	new slot, Float:mx, Float:my, Float:mz;
	if(sscanf(params, "dfff", slot, mx, my, mz))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /movobj [slot] [x] [y] [z]");
		return 1;
	}
	new vehid = GetPlayerVehicleID(playerid);
	if( vehid == INVALID_VEHICLE_ID )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w pojeŸdzie !");
		return 1;
	}
	if( slot == 0 )
	{
		if( gVehData[vehid-1][CustomObj1Model] != 0 && gVehData[vehid-1][CustomObj1On] )
		{
			gVehData[vehid-1][CustomObj1][3] = mx;
			gVehData[vehid-1][CustomObj1][4] = my;
			gVehData[vehid-1][CustomObj1][5] = mz;
			SaveVehData( vehid-1, "CustomObj1", 3 );
			SaveVehData( vehid-1, "CustomObj1", 4 );
			SaveVehData( vehid-1, "CustomObj1", 5 );
			AttachDynamicObjectToVehicle( gVehData[vehid-1][CustomObj1ID], vehid, gVehData[vehid-1][CustomObj1][0], gVehData[vehid-1][CustomObj1][1], gVehData[vehid-1][CustomObj1][2], gVehData[vehid-1][CustomObj1][3], gVehData[vehid-1][CustomObj1][4], gVehData[vehid-1][CustomObj1][5] );
		}
	}
	if( slot == 1 )
	{
		if( gVehData[vehid-1][CustomObj2Model] != 0 && gVehData[vehid-1][CustomObj2On] )
		{
			gVehData[vehid-1][CustomObj2][3] = mx;
			gVehData[vehid-1][CustomObj2][4] = my;
			gVehData[vehid-1][CustomObj2][5] = mz;
			SaveVehData( vehid-1, "CustomObj2", 3 );
			SaveVehData( vehid-1, "CustomObj2", 4 );
			SaveVehData( vehid-1, "CustomObj2", 5 );
			AttachDynamicObjectToVehicle( gVehData[vehid-1][CustomObj2ID], vehid, gVehData[vehid-1][CustomObj2][0], gVehData[vehid-1][CustomObj2][1], gVehData[vehid-1][CustomObj2][2], gVehData[vehid-1][CustomObj2][3], gVehData[vehid-1][CustomObj2][4], gVehData[vehid-1][CustomObj2][5] );
		}
	}
	if( slot == 2 )
	{
		if( gVehData[vehid-1][CustomObj3Model] != 0 && gVehData[vehid-1][CustomObj3On] )
		{
			gVehData[vehid-1][CustomObj3][3] = mx;
			gVehData[vehid-1][CustomObj3][4] = my;
			gVehData[vehid-1][CustomObj3][5] = mz;
			SaveVehData( vehid-1, "CustomObj3", 3 );
			SaveVehData( vehid-1, "CustomObj3", 4 );
			SaveVehData( vehid-1, "CustomObj3", 5 );
			AttachDynamicObjectToVehicle(gVehData[vehid-1][CustomObj3ID], vehid, gVehData[vehid-1][CustomObj3][0], gVehData[vehid-1][CustomObj3][1], gVehData[vehid-1][CustomObj3][2], gVehData[vehid-1][CustomObj3][3], gVehData[vehid-1][CustomObj3][4], gVehData[vehid-1][CustomObj3][5]);
		}
	}
	if( slot == 3 )
	{
		if( gVehData[vehid-1][CustomObj4Model] != 0 && gVehData[vehid-1][CustomObj4On] )
		{
			gVehData[vehid-1][CustomObj4][3] = mx;
			gVehData[vehid-1][CustomObj4][4] = my;
			gVehData[vehid-1][CustomObj4][5] = mz;
			SaveVehData( vehid-1, "CustomObj4", 3 );
			SaveVehData( vehid-1, "CustomObj4", 4 );
			SaveVehData( vehid-1, "CustomObj4", 5 );
			AttachDynamicObjectToVehicle(gVehData[vehid-1][CustomObj4ID], vehid, gVehData[vehid-1][CustomObj4][0], gVehData[vehid-1][CustomObj4][1], gVehData[vehid-1][CustomObj4][2], gVehData[vehid-1][CustomObj4][3], gVehData[vehid-1][CustomObj4][4], gVehData[vehid-1][CustomObj4][5]);
		}
	}
	if( slot == 4 )
	{
		if( gVehData[vehid-1][CustomObj5Model] != 0 && gVehData[vehid-1][CustomObj5On] )
		{
			gVehData[vehid-1][CustomObj5][3] = mx;
			gVehData[vehid-1][CustomObj5][4] = my;
			gVehData[vehid-1][CustomObj5][5] = mz;
			SaveVehData( vehid-1, "CustomObj5", 3 );
			SaveVehData( vehid-1, "CustomObj5", 4 );
			SaveVehData( vehid-1, "CustomObj5", 5 );
			AttachDynamicObjectToVehicle(gVehData[vehid-1][CustomObj5ID], vehid, gVehData[vehid-1][CustomObj5][0], gVehData[vehid-1][CustomObj5][1], gVehData[vehid-1][CustomObj5][2], gVehData[vehid-1][CustomObj5][3], gVehData[vehid-1][CustomObj5][4], gVehData[vehid-1][CustomObj5][5]);
		}
	}
	if( slot == 5 )
	{
		if( gVehData[vehid-1][CustomObj6Model] != 0 && gVehData[vehid-1][CustomObj6On] )
		{
			gVehData[vehid-1][CustomObj6][3] = mx;
			gVehData[vehid-1][CustomObj6][4] = my;
			gVehData[vehid-1][CustomObj6][5] = mz;
			SaveVehData( vehid-1, "CustomObj6", 3 );
			SaveVehData( vehid-1, "CustomObj6", 4 );
			SaveVehData( vehid-1, "CustomObj6", 5 );
			AttachDynamicObjectToVehicle(gVehData[vehid-1][CustomObj6ID], vehid, gVehData[vehid-1][CustomObj6][0], gVehData[vehid-1][CustomObj6][1], gVehData[vehid-1][CustomObj6][2], gVehData[vehid-1][CustomObj6][3], gVehData[vehid-1][CustomObj6][4], gVehData[vehid-1][CustomObj6][5]);
		}
	}
	if( slot == 6 )
	{
		if( gVehData[vehid-1][CustomObj7Model] != 0 && gVehData[vehid-1][CustomObj7On] )
		{
			gVehData[vehid-1][CustomObj7][3] = mx;
			gVehData[vehid-1][CustomObj7][4] = my;
			gVehData[vehid-1][CustomObj7][5] = mz;
			SaveVehData( vehid-1, "CustomObj7", 3 );
			SaveVehData( vehid-1, "CustomObj7", 4 );
			SaveVehData( vehid-1, "CustomObj7", 5 );
			AttachDynamicObjectToVehicle(gVehData[vehid-1][CustomObj7ID], vehid, gVehData[vehid-1][CustomObj7][0], gVehData[vehid-1][CustomObj7][1], gVehData[vehid-1][CustomObj7][2], gVehData[vehid-1][CustomObj7][3], gVehData[vehid-1][CustomObj7][4], gVehData[vehid-1][CustomObj7][5]);
		}
	}
	new string[128];
	format(string, sizeof(string), "[INFO:] New obj rot X: %f, Y: %f, Z: %f", mx, my, mz);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	return 1;
}

dcmd_mvvobj(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;

	new slot, Float:ox, Float:oy, Float:oz, Float:mx, Float:my, Float:mz;
	if(sscanf(params, "dfff", slot, mx, my, mz))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /mvobj [slot] [x] [y] [z]");
		return 1;
	}
	new vehid = GetPlayerVehicleID(playerid);
	if( slot == 0)
	{
		gVehData[vehid-1][CustomObj1][0] += mx;
		gVehData[vehid-1][CustomObj1][1] += my;
		gVehData[vehid-1][CustomObj1][2] += mz;
		SaveVehData( vehid-1, "CustomObj1", 0 );
		SaveVehData( vehid-1, "CustomObj1", 1 );
		SaveVehData( vehid-1, "CustomObj1", 2 );
		MoveObject(gVehData[vehid-1][CustomObj1ID], gVehData[vehid-1][CustomObj1][0], gVehData[vehid-1][CustomObj1][1], gVehData[vehid-1][CustomObj1][2], 100.0 );
	}
	if( slot == 1)
	{
		gVehData[vehid-1][CustomObj2][0] += mx;
		gVehData[vehid-1][CustomObj2][1] += my;
		gVehData[vehid-1][CustomObj2][2] += mz;
		SaveVehData( vehid-1, "CustomObj2", 0 );
		SaveVehData( vehid-1, "CustomObj2", 1 );
		SaveVehData( vehid-1, "CustomObj2", 2 );
		MoveObject(gVehData[vehid-1][CustomObj2ID], gVehData[vehid-1][CustomObj2][0], gVehData[vehid-1][CustomObj2][1], gVehData[vehid-1][CustomObj2][2], 100.0 );
	}
	if( slot == 2)
	{
		gVehData[vehid-1][CustomObj3][0] += mx;
		gVehData[vehid-1][CustomObj3][1] += my;
		gVehData[vehid-1][CustomObj3][2] += mz;
		SaveVehData( vehid-1, "CustomObj3", 0 );
		SaveVehData( vehid-1, "CustomObj3", 1 );
		SaveVehData( vehid-1, "CustomObj3", 2 );
		MoveObject(gVehData[vehid-1][CustomObj3ID], gVehData[vehid-1][CustomObj3][0], gVehData[vehid-1][CustomObj3][1], gVehData[vehid-1][CustomObj3][2], 100.0 );
	}
	if( slot == 3)
	{
		gVehData[vehid-1][CustomObj4][0] += mx;
		gVehData[vehid-1][CustomObj4][1] += my;
		gVehData[vehid-1][CustomObj4][2] += mz;
		SaveVehData( vehid-1, "CustomObj4", 0 );
		SaveVehData( vehid-1, "CustomObj4", 1 );
		SaveVehData( vehid-1, "CustomObj4", 2 );
		MoveObject(gVehData[vehid-1][CustomObj4ID], gVehData[vehid-1][CustomObj4][0], gVehData[vehid-1][CustomObj4][1], gVehData[vehid-1][CustomObj4][2], 100.0 );
	}
	if( slot == 4)
	{
		gVehData[vehid-1][CustomObj5][0] += mx;
		gVehData[vehid-1][CustomObj5][1] += my;
		gVehData[vehid-1][CustomObj5][2] += mz;
		SaveVehData( vehid-1, "CustomObj5", 0 );
		SaveVehData( vehid-1, "CustomObj5", 1 );
		SaveVehData( vehid-1, "CustomObj5", 2 );
		MoveObject(gVehData[vehid-1][CustomObj5ID], gVehData[vehid-1][CustomObj5][0], gVehData[vehid-1][CustomObj5][1], gVehData[vehid-1][CustomObj5][2], 100.0 );
	}
	if( slot == 5)
	{
		gVehData[vehid-1][CustomObj6][0] += mx;
		gVehData[vehid-1][CustomObj6][1] += my;
		gVehData[vehid-1][CustomObj6][2] += mz;
		SaveVehData( vehid-1, "CustomObj6", 0 );
		SaveVehData( vehid-1, "CustomObj6", 1 );
		SaveVehData( vehid-1, "CustomObj6", 2 );
		MoveObject(gVehData[vehid-1][CustomObj6ID], gVehData[vehid-1][CustomObj6][0], gVehData[vehid-1][CustomObj6][1], gVehData[vehid-1][CustomObj6][2], 100.0 );
	}
	new string[128];
	format(string, sizeof(string), "[INFO:] New obj pos X: %f, Y: %f, Z: %f", ox+mx, oy+my, oz+mz);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	return 1;
}

dcmd_rotvobj(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;

	new slot, Float:ox, Float:oy, Float:oz, Float:mx, Float:my, Float:mz;
	if(sscanf(params, "dfff", slot, mx, my, mz))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /movobj [slot] [x] [y] [z]");
		return 1;
	}
	new vehid = GetPlayerVehicleID(playerid);
	if( slot == 0 )
	{
		gVehData[vehid-1][CustomObj1][3] += mx;
		gVehData[vehid-1][CustomObj1][4] += my;
		gVehData[vehid-1][CustomObj1][5] += mz;
		SetObjectRot(gVehData[vehid-1][CustomObj1Model], gVehData[vehid-1][CustomObj1][3]+mx, gVehData[vehid-1][CustomObj1][4]+my, gVehData[vehid-1][CustomObj1][5]+mz);
		SaveVehData( vehid-1, "CustomObj1", 3 );
		SaveVehData( vehid-1, "CustomObj1", 4 );
		SaveVehData( vehid-1, "CustomObj1", 5 );
	}
	if( slot == 1 )
	{
		gVehData[vehid-1][CustomObj2][3] += mx;
		gVehData[vehid-1][CustomObj2][4] += my;
		gVehData[vehid-1][CustomObj2][5] += mz;
		SetObjectRot(gVehData[vehid-1][CustomObj2Model], gVehData[vehid-1][CustomObj2][3]+mx, gVehData[vehid-1][CustomObj2][4]+my, gVehData[vehid-1][CustomObj2][5]+mz);
		SaveVehData( vehid-1, "CustomObj2", 3 );
		SaveVehData( vehid-1, "CustomObj2", 4 );
		SaveVehData( vehid-1, "CustomObj2", 5 );
	}
	if( slot == 2 )
	{
		gVehData[vehid-1][CustomObj3][3] += mx;
		gVehData[vehid-1][CustomObj3][4] += my;
		gVehData[vehid-1][CustomObj3][5] += mz;
		SetObjectRot(gVehData[vehid-1][CustomObj3Model], gVehData[vehid-1][CustomObj3][3]+mx, gVehData[vehid-1][CustomObj3][4]+my, gVehData[vehid-1][CustomObj3][5]+mz);
		SaveVehData( vehid-1, "CustomObj3", 3 );
		SaveVehData( vehid-1, "CustomObj3", 4 );
		SaveVehData( vehid-1, "CustomObj3", 5 );
	}
	if( slot == 3 )
	{
		gVehData[vehid-1][CustomObj4][3] += mx;
		gVehData[vehid-1][CustomObj4][4] += my;
		gVehData[vehid-1][CustomObj4][5] += mz;
		SetObjectRot(gVehData[vehid-1][CustomObj4Model], gVehData[vehid-1][CustomObj4][3]+mx, gVehData[vehid-1][CustomObj4][4]+my, gVehData[vehid-1][CustomObj4][5]+mz);
		SaveVehData( vehid-1, "CustomObj4", 3 );
		SaveVehData( vehid-1, "CustomObj4", 4 );
		SaveVehData( vehid-1, "CustomObj4", 5 );
	}
	if( slot == 4 )
	{
		gVehData[vehid-1][CustomObj5][3] += mx;
		gVehData[vehid-1][CustomObj5][4] += my;
		gVehData[vehid-1][CustomObj5][5] += mz;
		SetObjectRot(gVehData[vehid-1][CustomObj5Model], gVehData[vehid-1][CustomObj5][3]+mx, gVehData[vehid-1][CustomObj5][4]+my, gVehData[vehid-1][CustomObj5][5]+mz);
		SaveVehData( vehid-1, "CustomObj5", 3 );
		SaveVehData( vehid-1, "CustomObj5", 4 );
		SaveVehData( vehid-1, "CustomObj5", 5 );
	}
	if( slot == 5 )
	{
		gVehData[vehid-1][CustomObj6][3] += mx;
		gVehData[vehid-1][CustomObj6][4] += my;
		gVehData[vehid-1][CustomObj6][5] += mz;
		SetObjectRot(gVehData[vehid-1][CustomObj6Model], gVehData[vehid-1][CustomObj6][3]+mx, gVehData[vehid-1][CustomObj6][4]+my, gVehData[vehid-1][CustomObj6][5]+mz);
		SaveVehData( vehid-1, "CustomObj6", 3 );
		SaveVehData( vehid-1, "CustomObj6", 4 );
		SaveVehData( vehid-1, "CustomObj6", 5 );
	}
	new string[128];
	format(string, sizeof(string), "[INFO:] New obj rot X: %f, Y: %f, Z: %f", ox+mx, oy+my, oz+mz);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	return 1;
}

dcmd_gotocobj(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] < 2)
		return 0;
	new slot, Float:Xobj, Float:Yobj, Float:Zobj;
	if( sscanf( params, "d", slot ) )
	{
		SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] /gotocobj [slot]");
		return 1;
	}
	if( !gCustomObj[slot][cstSlotUsed] )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Ten slot nie zawiera ¿adnego obiektu !");
		return 1;
	}
	GetDynamicObjectPos( gCustomObj[slot][cstObjID], Xobj, Yobj, Zobj );
	SetPlayerToPos( playerid, Xobj+2.0, Yobj, Zobj );
	return 1;
}

dcmd_descobj(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] < 2)
		return 0;
	new Float:Xobj, Float:Yobj, Float:Zobj, Float:RXobj, Float:RYobj, Float:RZobj, string[128];
	if(gCustomObjShow[playerid]) { gCustomObjShow[playerid] = 0; } else { gCustomObjShow[playerid] = 1; }
	for(new i = 0; i < sizeof(gCustomObj); i++)
	{
		if(gCustomObj[i][cstSlotUsed])
		{
			if(!gCustomObjShowed[playerid][i] && gCustomObjShow[playerid])
			{
				GetDynamicObjectPos( gCustomObj[i][cstObjID], Xobj, Yobj, Zobj );
				GetDynamicObjectRot( gCustomObj[i][cstObjID], RXobj, RYobj, RZobj );
				format(string, sizeof(string), "objID = %d | objModel = %d | objSlot = %d", gCustomObj[i][cstObjID], gCustomObj[i][cstObjModel], i );
				gCustomObjTextID1[playerid][i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE, Xobj, Yobj, Zobj, 100.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, gCustomObj[i][cstObjVW], -1, playerid );
				format(string, sizeof(string), "objIX = %f | objY = %f | objZ = %f", Xobj, Yobj, Zobj );
				gCustomObjTextID2[playerid][i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE, Xobj, Yobj, Zobj-0.2, 100.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, gCustomObj[i][cstObjVW], -1, playerid );
				format(string, sizeof(string), "objIRX = %f | objRY = %f | objRZ = %f", RXobj, RYobj, RZobj );
				gCustomObjTextID3[playerid][i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE, Xobj, Yobj, Zobj-0.4, 100.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, gCustomObj[i][cstObjVW], -1, playerid );
				format(string, sizeof(string), "made by: %s", gCustomObj[i][cstObjOwner] );
				gCustomObjTextID4[playerid][i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE, Xobj, Yobj, Zobj+0.2, 100.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, gCustomObj[i][cstObjVW], -1, playerid );
				gCustomObjShowed[playerid][i] = 1;
			}
			else if(gCustomObjShowed[playerid][i])
			{
				DestroyDynamic3DTextLabel(gCustomObjTextID1[playerid][i]);
				DestroyDynamic3DTextLabel(gCustomObjTextID2[playerid][i]);
				DestroyDynamic3DTextLabel(gCustomObjTextID3[playerid][i]);
				DestroyDynamic3DTextLabel(gCustomObjTextID4[playerid][i]);
				gCustomObjShowed[playerid][i] = 0;
			}
		}
	}
	return 1;
}

dcmd_daneobiektow(playerid, params[])
{
	#pragma unused params
	new Float:Xobj, Float:Yobj, Float:Zobj, Float:RXobj, Float:RYobj, Float:RZobj, string[128];
	if(	gCustomObjShow[playerid] ) { gCustomObjShow[playerid] = 0; } else { gCustomObjShow[playerid] = 1; }
	for( new i = 0; i < sizeof(gCustomObj); i++ )
	{
		if( gCustomObj[i][cstSlotUsed] && strcmp( gCustomObj[i][cstObjOwner], gPlayerData[playerid][pName], false ) == 0 )
		{
			if( !gCustomObjShowed[playerid][i] && gCustomObjShow[playerid] )
			{
				GetDynamicObjectPos( gCustomObj[i][cstObjID], Xobj, Yobj, Zobj );
				GetDynamicObjectRot( gCustomObj[i][cstObjID], RXobj, RYobj, RZobj );
				format(string, sizeof(string), "objID = %d | objModel = %d | objSlot = %d", gCustomObj[i][cstObjID], gCustomObj[i][cstObjModel], i );
				gCustomObjTextID1[playerid][i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE, Xobj, Yobj, Zobj, 100.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, gCustomObj[i][cstObjVW], -1, playerid );
				format(string, sizeof(string), "objIX = %f | objY = %f | objZ = %f", Xobj, Yobj, Zobj );
				gCustomObjTextID2[playerid][i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE, Xobj, Yobj, Zobj-0.2, 100.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, gCustomObj[i][cstObjVW], -1, playerid );
				format(string, sizeof(string), "objIRX = %f | objRY = %f | objRZ = %f", RXobj, RYobj, RZobj );
				gCustomObjTextID3[playerid][i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE, Xobj, Yobj, Zobj-0.4, 100.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, gCustomObj[i][cstObjVW], -1, playerid );
				format(string, sizeof(string), "made by: %s", gCustomObj[i][cstObjOwner] );
				gCustomObjTextID4[playerid][i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE, Xobj, Yobj, Zobj+0.2, 100.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, gCustomObj[i][cstObjVW], -1, playerid );
				gCustomObjShowed[playerid][i] = 1;
			}
			else if( gCustomObjShowed[playerid][i] )
			{
				DestroyDynamic3DTextLabel(gCustomObjTextID1[playerid][i]);
				DestroyDynamic3DTextLabel(gCustomObjTextID2[playerid][i]);
				DestroyDynamic3DTextLabel(gCustomObjTextID3[playerid][i]);
				DestroyDynamic3DTextLabel(gCustomObjTextID4[playerid][i]);
				gCustomObjShowed[playerid][i] = 0;
			}
		}
	}
	return 1;
}

dcmd_makeobj(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] < 2)
		return 0;
	new modelid, Float:Xobj, Float:Yobj, Float:Zobj, Float:rX, Float:rY, Float:rZ, vw, interior, string[128];
	if(sscanf(params, "dffffff", modelid, Xobj, Yobj, Zobj, rX, rY, rZ))
	{
		if( sscanf(params, "d", modelid ) )
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /makeobj [modelid] [X] [Y] [Z] [rX] [rY] [rZ]");
			return 1;
		}
	}
	if( Xobj == 0 && Yobj == 0 && Zobj == 0 )
		GetPlayerPos( playerid, Xobj, Yobj, Zobj );
	vw = GetPlayerVirtualWorld(playerid);
	interior = GetPlayerInterior(playerid);
	for(new i = 0; i < sizeof(gCustomObj); i++)
	{
		if(!gCustomObj[i][cstSlotUsed])
		{
			gCustomObj[i][cstObjID] = CreateDynamicObject(modelid, Xobj, Yobj, Zobj, rX, rY, rZ, vw, interior);
			gCustomObj[i][cstObjModel] = modelid;
			gCustomObj[i][cstObjVW] = vw;
			gCustomObj[i][cstObjInt] = interior;
			gCustomObj[i][cstSlotUsed] = true;
			GetPlayerName( playerid, string, sizeof(string) );
			format( gCustomObj[i][cstObjOwner], MAX_PLAYER_NAME, "%s", string );
			if(!gCustomObjShow[playerid])
			{
				gCustomObjShowed[playerid][i] = 0;
			}
			else
			{
				format(string, sizeof(string), "objID = %d | objModel = %d | objSlot = %d", gCustomObj[i][cstObjID], gCustomObj[i][cstObjModel], i );
				gCustomObjTextID1[playerid][i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE, Xobj, Yobj, Zobj, 100.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, vw, -1, playerid );
				format(string, sizeof(string), "objIX = %f | objY = %f | objZ = %f", Xobj, Yobj, Zobj );
				gCustomObjTextID2[playerid][i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE, Xobj, Yobj, Zobj-0.2, 100.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, vw, -1, playerid );
				format(string, sizeof(string), "objIRX = %f | objRY = %f | objRZ = %f", rX, rY, rZ );
				gCustomObjTextID3[playerid][i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE, Xobj, Yobj, Zobj-0.4, 100.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, vw, -1, playerid );
				format(string, sizeof(string), "made by: %s", gCustomObj[i][cstObjOwner] );
				gCustomObjTextID4[playerid][i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE, Xobj, Yobj, Zobj+0.2, 100.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, vw, -1, playerid );
				gCustomObjShowed[playerid][i] = 1;
			}
			SaveObjData(i);
			return 1;
		}
	}
	SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Osi¹gniêto limit obiektów !");
	return 1;
}

dcmd_stworzobiekt(playerid, params[])
{
	if(gPlayerData[playerid][pPlayingHours] < 5)
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Musisz przegraæ co najmniej 5 godzin aby móc tworzyæ obiekty !" );
		return 1;
	}
	new modelid, Float:Xobj, Float:Yobj, Float:Zobj, Float:rX, Float:rY, Float:rZ, vw, interior, string[128], allowed = 0;
	if(CountPlayerObjects(playerid) >= gPlayerData[playerid][pVipCustomObjects]+10)
	{
		format( string, sizeof(string), "[INFO:] Osi¹gn¹³eœ limit obiektów (%d) !", gPlayerData[playerid][pVipCustomObjects]+10);
		SendClientMessage( playerid, COLOR_ORANGE, string );
		return 1;
	}
	if(IsPlayerInDynamicArea(playerid, gArea_Prison1) && !gPlayerData[playerid][pAdmin])
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz tutaj stawiaæ obiektów !");
		return 1;
	}
	if(sscanf(params, "dffffff", modelid, Xobj, Yobj, Zobj, rX, rY, rZ))
	{
		if( sscanf(params, "d", modelid ) )
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /stworzobiekt [id modelu]");
			return 1;
		}
	}
	for( new i = 0; i < sizeof( gAllowedObjectList ); i++ )
	{
		if( gAllowedObjectList[i] == modelid )
		{
			allowed = 1;
			break;
		}
	}
	if( allowed == 0 )
	{
		if( modelid < 18632 && modelid > 19338 )
		{
			SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz utworzyæ tego obiektu ! Wybierz inny" );
			return 1;
		}
	}
	if( Xobj == 0 && Yobj == 0 && Zobj == 0 )
		GetPlayerPos( playerid, Xobj, Yobj, Zobj );
	vw = GetPlayerVirtualWorld(playerid);
	interior = GetPlayerInterior(playerid);
	if(vw == 0 && gPlayerData[playerid][pPlayingHours] < 30)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Musisz mieæ przegrane 30 godzin aby móc tworzyæ obiekty za zewn¹trz");
		return 1;
	}
	for(new i = 0; i < sizeof(gCustomObj); i++)
	{
		if(!gCustomObj[i][cstSlotUsed])
		{
			gCustomObj[i][cstObjID] = CreateDynamicObject(modelid, Xobj, Yobj, Zobj, rX, rY, rZ, vw, interior);
			gCustomObj[i][cstObjModel] = modelid;
			gCustomObj[i][cstObjVW] = vw;
			gCustomObj[i][cstObjInt] = interior;
			gCustomObj[i][cstSlotUsed] = true;
			GetPlayerName( playerid, string, sizeof(string) );
			format( gCustomObj[i][cstObjOwner], MAX_PLAYER_NAME, "%s", string );
			if(	!gCustomObjShow[playerid] )
			{
				gCustomObjShowed[playerid][i] = 0;
			}
			else
			{
				format(string, sizeof(string), "objID = %d | objModel = %d | objSlot = %d", gCustomObj[i][cstObjID], gCustomObj[i][cstObjModel], i );
				gCustomObjTextID1[playerid][i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE, Xobj, Yobj, Zobj, 100.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, vw, -1, playerid );
				format(string, sizeof(string), "objIX = %f | objY = %f | objZ = %f", Xobj, Yobj, Zobj );
				gCustomObjTextID2[playerid][i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE, Xobj, Yobj, Zobj-0.2, 100.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, vw, -1, playerid );
				format(string, sizeof(string), "objIRX = %f | objRY = %f | objRZ = %f", rX, rY, rZ );
				gCustomObjTextID3[playerid][i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE, Xobj, Yobj, Zobj-0.4, 100.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, vw, -1, playerid );
				format(string, sizeof(string), "made by: %s", gCustomObj[i][cstObjOwner] );
				gCustomObjTextID4[playerid][i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE, Xobj, Yobj, Zobj+0.2, 100.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, vw, -1, playerid );
				gCustomObjShowed[playerid][i] = 1;
			}
			SaveObjData(i);
			return 1;
		}
	}
	SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Osi¹gniêto limit obiektów !");
	return 1;
}

dcmd_removeobj(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] < 2)
		return 0;
	new objid;
	if(sscanf(params, "d", objid))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /removeobj [custom obj id]");
		return 1;
	}
	for( new i = 0; i < sizeof(gCustomObj); i++ )
	{
		if( gCustomObj[i][cstSlotUsed] && gCustomObj[i][cstObjID] == objid )
		{
			DestroyDynamic3DTextLabel( gCustomObjTextID1[playerid][i] );
			DestroyDynamic3DTextLabel( gCustomObjTextID2[playerid][i] );
			DestroyDynamic3DTextLabel( gCustomObjTextID3[playerid][i] );
			DestroyDynamic3DTextLabel( gCustomObjTextID4[playerid][i] );
			DestroyDynamicObject( gCustomObj[i][cstObjID] );
			gCustomObj[i][cstObjID] = 0;
			gCustomObj[i][cstSlotUsed] = false;
			gCustomObj[i][cstObjModel] = 0;
			gCustomObj[i][cstObjVW] = 0;
			gCustomObj[i][cstObjInt] = 0;
			gCustomObjShowed[playerid][i] = 0;
			strdel( gCustomObj[i][cstObjOwner], 0, MAX_PLAYER_NAME );
			SaveObjData(i);
			return 1;
		}
	}
	SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Wrong object ID !" );
	return 1;
}

dcmd_usunobiekt(playerid, params[])
{
	new objid;
	if(sscanf(params, "d", objid))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /usunobiekt [id obiektu]");
		return 1;
	}
	for( new i = 0; i < sizeof(gCustomObj); i++ )
	{
		if( gCustomObj[i][cstSlotUsed] && gCustomObj[i][cstObjID] == objid )
		{
			if( strcmp( gCustomObj[i][cstObjOwner], gPlayerData[playerid][pName], false ) != 0 )
			{
				SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz usun¹æ tego obiektu poniewa¿ nie zosta³ stworzony przez ciebie" );
				return 1;
			}
			DestroyDynamic3DTextLabel( gCustomObjTextID1[playerid][i] );
			DestroyDynamic3DTextLabel( gCustomObjTextID2[playerid][i] );
			DestroyDynamic3DTextLabel( gCustomObjTextID3[playerid][i] );
			DestroyDynamic3DTextLabel( gCustomObjTextID4[playerid][i] );
			DestroyDynamicObject( gCustomObj[i][cstObjID] );
			gCustomObj[i][cstObjID] = 0;
			gCustomObj[i][cstSlotUsed] = false;
			gCustomObj[i][cstObjModel] = 0;
			gCustomObj[i][cstObjVW] = 0;
			gCustomObj[i][cstObjInt] = 0;
			gCustomObjShowed[playerid][i] = 0;
			strdel( gCustomObj[i][cstObjOwner], 0, MAX_PLAYER_NAME );
			SaveObjData(i);
			return 1;
		}
	}
	SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Poda³eœ nieprawid³owe ID obiektu !" );
	return 1;
}

dcmd_aotv(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new objID, vehID, Float:OffsetX, Float:OffsetY, Float:OffsetZ, Float:RotX, Float:RotY, Float:RotZ;
	if(sscanf(params, "ddffffff", objID, vehID, OffsetX, OffsetY, OffsetZ,RotX, RotY, RotZ))
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] /aotv [objID] [vehID] [OffsetX] [OffsetY] [OffsetZ] [RotX] [RotY] [RotZ]");
		return 1;
	}
	AttachDynamicObjectToVehicle(objID, vehID, OffsetX, OffsetY, OffsetZ, RotX, RotY, RotZ);
	return 1;
}

dcmd_movobj(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] < 2)
		return 0;

	new objID, Float:ox, Float:oy, Float:oz, Float:mx, Float:my, Float:mz, Float:rx, Float:ry, Float:rz, string[128], vw;
	if(sscanf(params, "dfff", objID, mx, my, mz))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /movobj [objid] [x] [y] [z]");
		return 1;
	}
	for( new i = 0; i < sizeof(gCustomObj); i++ )
	{
		if( gCustomObj[i][cstSlotUsed] && gCustomObj[i][cstObjID] == objID )
		{
			vw = GetPlayerVirtualWorld(playerid);
			GetDynamicObjectPos( objID, ox, oy, oz );
			SetDynamicObjectPos( objID, ox+mx, oy+my, oz+mz );
			GetDynamicObjectRot( objID, rx, ry, rz );
			DestroyDynamic3DTextLabel( gCustomObjTextID1[playerid][i] );
			DestroyDynamic3DTextLabel( gCustomObjTextID2[playerid][i] );
			DestroyDynamic3DTextLabel( gCustomObjTextID3[playerid][i] );
			DestroyDynamic3DTextLabel( gCustomObjTextID4[playerid][i] );
			if( gCustomObjShow[playerid] )
			{
				format(string, sizeof(string), "objID = %d | objModel = %d | objSlot = %d", gCustomObj[i][cstObjID], gCustomObj[i][cstObjModel], i );
				gCustomObjTextID1[playerid][i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE, ox+mx, oy+my, oz+mz, 100.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, vw, -1, playerid);
				format(string, sizeof(string), "objIX = %f | objY = %f | objZ = %f", ox+mx, oy+my, oz+mz );
				gCustomObjTextID2[playerid][i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE, ox+mx, oy+my, oz+mz-0.2, 100.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, vw, -1, playerid);
				format(string, sizeof(string), "objIRX = %f | objRY = %f | objRZ = %f", rx, ry, rz );
				gCustomObjTextID3[playerid][i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE, ox+mx, oy+my, oz+mz-0.4, 100.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, vw, -1, playerid);
				format(string, sizeof(string), "made by: %s", gCustomObj[i][cstObjOwner] );
				gCustomObjTextID4[playerid][i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE, ox+mx, oy+my, oz+mz+0.2, 100.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, vw, -1, playerid);
				gCustomObjShowed[playerid][i] = 1;
			}
			else
			{
				gCustomObjShowed[playerid][i] = 0;
			}
			SaveObjData(i);
			GetPlayerName(playerid, string, sizeof(string));
			printf("[WARNING:] %s used /movobj for obj %d, slot %d", string, gCustomObj[i][cstObjID], i);
			return 1;
		}
	}
	SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Wrong object ID !" );
	return 1;
}

dcmd_edytujobiekt(playerid, params[])
{
	new objId;
	
	if(sscanf(params, "d", objId))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /edytujobiekt [id slotu w którym znajduje siê obiekt]");
		return 1;
	}
	
	if(gPlayerData[playerid][pAdmin] != 5)
	{
		for(new i = 0; i < sizeof(gCustomObj); i++)
		{
			if(gCustomObj[i][cstSlotUsed] && gCustomObj[i][cstObjID] == objId)
			{
				if(strcmp(gCustomObj[i][cstObjOwner], gPlayerData[playerid][pName], false) != 0)
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz edytowaæ tego obiektu poniewa¿ nie zosta³ stworzony przez ciebie");
					return 1;
				}
			}
		}
	}
	
	EditDynamicObject(playerid, objId);
	return 1;
}

dcmd_przesunobiekt(playerid, params[])
{
	new objID, Float:ox, Float:oy, Float:oz, Float:mx, Float:my, Float:mz, Float:rx, Float:ry, Float:rz, string[128], vw;
	if(sscanf(params, "dfff", objID, mx, my, mz))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /przesunobiekt [id obiektu] [x] [y] [z]");
		return 1;
	}
	for( new i = 0; i < sizeof(gCustomObj); i++ )
	{
		if( gCustomObj[i][cstSlotUsed] && gCustomObj[i][cstObjID] == objID )
		{
			if( strcmp( gCustomObj[i][cstObjOwner], gPlayerData[playerid][pName], false ) != 0 )
			{
				SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz przesun¹æ tego obiektu poniewa¿ nie zosta³ stworzony przez ciebie" );
				return 1;
			}
			vw = GetPlayerVirtualWorld(playerid);
			GetDynamicObjectPos(objID, ox, oy, oz);
			SetDynamicObjectPos(objID, ox+mx, oy+my, oz+mz);
			GetDynamicObjectRot(objID, rx, ry, rz);
			DestroyDynamic3DTextLabel(gCustomObjTextID1[playerid][i]);
			DestroyDynamic3DTextLabel(gCustomObjTextID2[playerid][i]);
			DestroyDynamic3DTextLabel(gCustomObjTextID3[playerid][i]);
			DestroyDynamic3DTextLabel(gCustomObjTextID4[playerid][i]);
			if( gCustomObjShow[playerid] )
			{
				format(string, sizeof(string), "objID = %d | objModel = %d | objSlot = %d", gCustomObj[i][cstObjID], gCustomObj[i][cstObjModel], i );
				gCustomObjTextID1[playerid][i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE, ox+mx, oy+my, oz+mz, 100.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, vw, -1, playerid);
				format(string, sizeof(string), "objIX = %f | objY = %f | objZ = %f", ox+mx, oy+my, oz+mz );
				gCustomObjTextID2[playerid][i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE, ox+mx, oy+my, oz+mz-0.2, 100.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, vw, -1, playerid);
				format(string, sizeof(string), "objIRX = %f | objRY = %f | objRZ = %f", rx, ry, rz );
				gCustomObjTextID3[playerid][i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE, ox+mx, oy+my, oz+mz-0.4, 100.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, vw, -1, playerid);
				format(string, sizeof(string), "made by: %s", gCustomObj[i][cstObjOwner] );
				gCustomObjTextID4[playerid][i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE, ox+mx, oy+my, oz+mz+0.2, 100.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, vw, -1, playerid);
				gCustomObjShowed[playerid][i] = 1;
			}
			else
			{
				gCustomObjShowed[playerid][i] = 0;
			}
			SaveObjData(i);
			GetPlayerName(playerid, string, sizeof(string));
			printf("[WARNING:] %s used /movobj for obj %d, slot %d", string, gCustomObj[i][cstObjID], i);
			return 1;
		}
	}
	SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Poda³eœ nieprawid³owe ID obiektu !" );
	return 1;
}

dcmd_rotobj(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] < 2)
		return 0;

	new objID, Float:ox, Float:oy, Float:oz, Float:mx, Float:my, Float:mz, string[128];
	if(sscanf(params, "dfff", objID, mx, my, mz))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /movobj [objid] [x] [y] [z]");
		return 1;
	}
	for( new i = 0; i < sizeof(gCustomObj); i++ )
	{
		if( gCustomObj[i][cstSlotUsed] && gCustomObj[i][cstObjID] == objID )
		{
			GetDynamicObjectRot(objID, ox, oy, oz);
			SetDynamicObjectRot(objID, ox+mx, oy+my, oz+mz);
			format(string, sizeof(string), "objIRX = %f | objRY = %f | objRZ = %f", ox+mx, oy+my, oz+mz );
			UpdateDynamic3DTextLabelText( gCustomObj[i][cstText3dID3], COLOR_LIGHTBLUE, string );
			SaveObjData(i);
			return 1;
		}
	}
	SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Wrong obj ID !");
	return 1;
}

dcmd_obrocobiekt(playerid, params[])
{
	new objID, Float:ox, Float:oy, Float:oz, Float:mx, Float:my, Float:mz, string[128];
	if(sscanf(params, "dfff", objID, mx, my, mz))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /obrocobiekt [id obiektu] [x] [y] [z]");
		return 1;
	}
	for( new i = 0; i < sizeof(gCustomObj); i++ )
	{
		if( gCustomObj[i][cstSlotUsed] && gCustomObj[i][cstObjID] == objID )
		{
			if( strcmp( gCustomObj[i][cstObjOwner], gPlayerData[playerid][pName], false ) != 0 )
			{
				SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz obróciæ tego obiektu poniewa¿ nie zosta³ stworzony przez ciebie" );
				return 1;
			}
			GetDynamicObjectRot(objID, ox, oy, oz);
			SetDynamicObjectRot(objID, ox+mx, oy+my, oz+mz);
			format(string, sizeof(string), "objIRX = %f | objRY = %f | objRZ = %f", ox+mx, oy+my, oz+mz );
			UpdateDynamic3DTextLabelText( gCustomObj[i][cstText3dID3], COLOR_LIGHTBLUE, string );
			SaveObjData(i);
			return 1;
		}
	}
	SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Poda³eœ nieprawid³owe ID obiektu !" );
	return 1;
}

dcmd_setobjpos(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] < 2)
		return 0;

	new objID, Float:ox, Float:oy, Float:oz, vw, Float:rx, Float:ry, Float:rz, string[128];
	if(sscanf(params, "dfff", objID, ox, oy, oz))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /setobjpos [objid] [x] [y] [z]");
		return 1;
	}
	for( new i = 0; i < sizeof(gCustomObj); i++ )
	{
		if( gCustomObj[i][cstSlotUsed] && gCustomObj[i][cstObjID] == objID )
		{
			vw = GetPlayerVirtualWorld(playerid);
			SetDynamicObjectPos( objID, ox, oy, oz );
			GetDynamicObjectRot( objID, rx, ry, rz );
			DestroyDynamic3DTextLabel( gCustomObjTextID1[playerid][i] );
			DestroyDynamic3DTextLabel( gCustomObjTextID2[playerid][i] );
			DestroyDynamic3DTextLabel( gCustomObjTextID3[playerid][i] );
			DestroyDynamic3DTextLabel( gCustomObjTextID4[playerid][i] );
			if( gCustomObjShow[playerid] )
			{
				format(string, sizeof(string), "objID = %d | objModel = %d | objSlot = %d", gCustomObj[i][cstObjID], gCustomObj[i][cstObjModel], i );
				gCustomObjTextID1[playerid][i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE, ox, oy, oz, 100.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, vw, -1, playerid);
				format(string, sizeof(string), "objIX = %f | objY = %f | objZ = %f", ox, oy, oz );
				gCustomObjTextID2[playerid][i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE, ox, oy, oz-0.2, 100.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, vw, -1, playerid);
				format(string, sizeof(string), "objIRX = %f | objRY = %f | objRZ = %f", rx, ry, rz );
				gCustomObjTextID3[playerid][i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE, ox, oy, oz-0.4, 100.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, vw, -1, playerid);
				format(string, sizeof(string), "made by: %s", gCustomObj[i][cstObjOwner] );
				gCustomObjTextID4[playerid][i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE, ox, oy, oz+0.2, 100.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, vw, -1, playerid);
				gCustomObjShowed[playerid][i] = 1;
			}
			else
			{
				gCustomObjShowed[playerid][i] = 0;
			}
			SaveObjData(i);
			GetPlayerName(playerid, string, sizeof(string));
			printf("[WARNING:] %s used /movobj for obj %d, slot %d", string, gCustomObj[i][cstObjID], i);
			return 1;
		}
	}
	SetDynamicObjectPos(objID, ox, oy, oz);
	format(string, sizeof(string), "[INFO:] New obj pos X: %f, Y: %f, Z: %f", ox, oy, oz);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	return 1;
}

dcmd_edytujobiektpoj(playerid, params[])
{
	new slot;

	if(sscanf(params, "d", slot))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /edytujobiektpoj [slot (0-6)]");
		return 1;
	}
	
	new vehid = GetPlayerVehicleID(playerid);
	
	if(vehid == 0)
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w pojeŸdzie !");
		return 1;
	}
	
	if(slot < 0 || slot > 6)
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /edytujobiektpoj [slot (0-6)]");
		return 1;
	}
	
	if(slot == 0)
	{
		if(gVehData[vehid-1][CustomObj1On] && gVehData[vehid-1][CustomObj1Model] != 0)
		{
			EditObject(playerid, gVehData[vehid-1][CustomObj1ID]);
		}
	}
	if(slot == 1)
	{
		if(gVehData[vehid-1][CustomObj2On] && gVehData[vehid-1][CustomObj2Model] != 0)
		{
			EditObject(playerid, gVehData[vehid-1][CustomObj2ID]);
		}
	}
	if(slot == 2)
	{
		if(gVehData[vehid-1][CustomObj3On] && gVehData[vehid-1][CustomObj3Model] != 0)
		{
			EditObject(playerid, gVehData[vehid-1][CustomObj3ID]);
		}
	}
	if(slot == 3)
	{
		if(gVehData[vehid-1][CustomObj4On] && gVehData[vehid-1][CustomObj4Model] != 0)
		{
			EditObject(playerid, gVehData[vehid-1][CustomObj4ID]);
		}
	}
	if(slot == 4)
	{
		if(gVehData[vehid-1][CustomObj5On] && gVehData[vehid-1][CustomObj5Model] != 0)
		{
			EditObject(playerid, gVehData[vehid-1][CustomObj5ID]);
		}
	}
	if(slot == 5)
	{
		if(gVehData[vehid-1][CustomObj6On] && gVehData[vehid-1][CustomObj6Model] != 0)
		{
			EditObject(playerid, gVehData[vehid-1][CustomObj6ID]);
		}
	}
	if(slot == 6)
	{
		if(gVehData[vehid-1][CustomObj7On] && gVehData[vehid-1][CustomObj7Model] != 0)
		{
			EditObject(playerid, gVehData[vehid-1][CustomObj7ID]);
		}
	}
	
	return 1;
}

dcmd_ustawobiekt(playerid, params[])
{
	new objID, Float:ox, Float:oy, Float:oz, vw, Float:rx, Float:ry, Float:rz, string[128];
	if(sscanf(params, "dfff", objID, ox, oy, oz))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /ustawobiekt [id obiektu] [x] [y] [z]");
		return 1;
	}
	for( new i = 0; i < sizeof(gCustomObj); i++ )
	{
		if( gCustomObj[i][cstSlotUsed] && gCustomObj[i][cstObjID] == objID )
		{
			if( strcmp( gCustomObj[i][cstObjOwner], gPlayerData[playerid][pName], false ) != 0 )
			{
				SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz ustawiæ tego obiektu poniewa¿ nie zosta³ stworzony przez ciebie" );
				return 1;
			}
			vw = GetPlayerVirtualWorld(playerid);
			SetDynamicObjectPos( objID, ox, oy, oz );
			GetDynamicObjectRot( objID, rx, ry, rz );
			DestroyDynamic3DTextLabel( gCustomObjTextID1[playerid][i] );
			DestroyDynamic3DTextLabel( gCustomObjTextID2[playerid][i] );
			DestroyDynamic3DTextLabel( gCustomObjTextID3[playerid][i] );
			DestroyDynamic3DTextLabel( gCustomObjTextID4[playerid][i] );
			if( gCustomObjShow[playerid] )
			{
				format(string, sizeof(string), "objID = %d | objModel = %d | objSlot = %d", gCustomObj[i][cstObjID], gCustomObj[i][cstObjModel], i );
				gCustomObjTextID1[playerid][i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE, ox, oy, oz, 100.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, vw, -1, playerid);
				format(string, sizeof(string), "objIX = %f | objY = %f | objZ = %f", ox, oy, oz );
				gCustomObjTextID2[playerid][i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE, ox, oy, oz-0.2, 100.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, vw, -1, playerid);
				format(string, sizeof(string), "objIRX = %f | objRY = %f | objRZ = %f", rx, ry, rz );
				gCustomObjTextID3[playerid][i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE, ox, oy, oz-0.4, 100.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, vw, -1, playerid);
				format(string, sizeof(string), "made by: %s", gCustomObj[i][cstObjOwner] );
				gCustomObjTextID4[playerid][i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE, ox, oy, oz+0.2, 100.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, vw, -1, playerid);
				gCustomObjShowed[playerid][i] = 1;
			}
			else
			{
				gCustomObjShowed[playerid][i] = 0;
			}
			SaveObjData(i);
			GetPlayerName(playerid, string, sizeof(string));
			printf("[WARNING:] %s used /movobj for obj %d, slot %d", string, gCustomObj[i][cstObjID], i);
			return 1;
		}
	}
	SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Poda³eœ nieprawid³owe ID obiektu !" );
	return 1;
}

dcmd_otworzmaske(playerid, params[])
{
	#pragma unused params
	if(!IsPlayerInAnyVehicle(playerid))
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Musisz byæ w pojeŸdzie aby otworzyæ maske");
		return 1;
	}
	new seat = GetPlayerVehicleSeat(playerid);
	if(seat != 0)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Musisz byæ na miejscu kierowcy aby otworzyæ maske");
		return 1;
	}
	new vehicleid = GetPlayerVehicleID(playerid);
	if(IsABoat(vehicleid) == 0 && IsABike(vehicleid) == 0 && IsAPlane(vehicleid) == 0 && IsAHelicopter(vehicleid) == 0 && IsAMotorBike(vehicleid) == 0)
	{
		new objective;
		GetVehicleParamsEx(vehicleid, gVehData[vehicleid-1][EngineOn], gVehData[vehicleid-1][LightsOn], gVehData[vehicleid-1][Alarm], gVehData[vehicleid-1][CarDoors], gVehData[vehicleid-1][BonnetUp], gVehData[vehicleid-1][BootUp], objective);
		for(new i = 0; i < sizeof(CarsLenghts); i++)
		{
			if(CarsLenghts[i][lenghtModel] == gVehData[vehicleid-1][mVehModel])
			{
				if(CarsLenghts[i][trunkAngle] == 1)
				{
					if(gVehData[vehicleid-1][BootUp])
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Maska jest ju¿ otwarta !");
					else
					{
						gVehData[vehicleid-1][BootUp] = 1;
						SaveVehData(vehicleid-1, "BootUp");
						SetVehicleParamsEx(vehicleid, gVehData[vehicleid-1][EngineOn], gVehData[vehicleid-1][LightsOn], gVehData[vehicleid-1][Alarm], gVehData[vehicleid-1][CarDoors], gVehData[vehicleid-1][BonnetUp], gVehData[vehicleid-1][BootUp], objective);
						PlayerActionMessage(playerid, 15.0, "otwiera maske pojazdu");						
					}
				}
				else
				{
					if(gVehData[vehicleid-1][BonnetUp])
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Maska jest ju¿ otwarta !");
					else
					{
						gVehData[vehicleid-1][BonnetUp] = 1;
						SaveVehData(vehicleid-1, "BonnetUp");
						SetVehicleParamsEx(vehicleid, gVehData[vehicleid-1][EngineOn], gVehData[vehicleid-1][LightsOn], gVehData[vehicleid-1][Alarm], gVehData[vehicleid-1][CarDoors], gVehData[vehicleid-1][BonnetUp], gVehData[vehicleid-1][BootUp], objective);
						PlayerActionMessage(playerid, 15.0, "otwiera maske pojazdu");						
					}
				}
			}
		}
	}
	return 1;
}

dcmd_zamknijmaske(playerid, params[])
{
	#pragma unused params
	if(IsPlayerInAnyVehicle(playerid))
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Musisz byæ przed mask¹ ¿eby j¹ zamkn¹æ");
		return 1;
	}
	new vehicleid = GetClosestVehicle(playerid);
	new Float:xc, Float:yc, Float:ac, Float:vx, Float:vy, Float:vz, Float:va;
	GetVehiclePos(vehicleid, vx, vy, vz);
	GetVehicleZAngle(vehicleid, va);
	GetPlayerFacingAngle(playerid, ac);
	for(new i = 0; i < sizeof(CarsLenghts); i++)
	{
		if(CarsLenghts[i][lenghtModel] == gVehData[vehicleid-1][mVehModel])
		{
			GetXYInFrontOfPlayer(playerid, xc, yc, CarsLenghts[i][hoodDistance]);
			if(CarsLenghts[i][hoodAngle] == 1)
			{
				if(ac-180.0 < 0.0)
					ac += 180.0;
				else
					ac -= 180.0;
			}
			if( ( floatabs(xc-vx) > 0.9 || floatabs(yc-vy) > 0.9 ) || floatabs(va-ac) > 28.0)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Jesteœ zbyt daleko od pojazdu ¿eby zamkn¹æ maske !");
				return 1;
			}
			else
			{
				if(IsABoat(vehicleid) == 0 && IsABike(vehicleid) == 0 && IsAPlane(vehicleid) == 0 && IsAHelicopter(vehicleid) == 0 && IsAMotorBike(vehicleid) == 0)
				{
					new objective;
					GetVehicleParamsEx(vehicleid, gVehData[vehicleid-1][EngineOn], gVehData[vehicleid-1][LightsOn], gVehData[vehicleid-1][Alarm], gVehData[vehicleid-1][CarDoors], gVehData[vehicleid-1][BonnetUp], gVehData[vehicleid-1][BootUp], objective);
					if(CarsLenghts[i][trunkAngle] == 1)
					{
						if(!gVehData[vehicleid-1][BootUp])
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Maska jest ju¿ zamkniêta !");
						else
						{
							gVehData[vehicleid-1][BootUp] = 0;
							SaveVehData(vehicleid-1, "BootUp");
							SetVehicleParamsEx(vehicleid, gVehData[vehicleid-1][EngineOn], gVehData[vehicleid-1][LightsOn], gVehData[vehicleid-1][Alarm], gVehData[vehicleid-1][CarDoors], gVehData[vehicleid-1][BonnetUp], gVehData[vehicleid-1][BootUp], objective);
							PlayerActionMessage(playerid, 15.0, "zamyka maske pojazdu");							
						}
					}
					else
					{
						if(!gVehData[vehicleid-1][BonnetUp])
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Maska jest ju¿ zamkniêta !");
						else
						{
							gVehData[vehicleid-1][BonnetUp] = 0;
							SaveVehData(vehicleid-1, "BonnetUp");
							SetVehicleParamsEx(vehicleid, gVehData[vehicleid-1][EngineOn], gVehData[vehicleid-1][LightsOn], gVehData[vehicleid-1][Alarm], gVehData[vehicleid-1][CarDoors], gVehData[vehicleid-1][BonnetUp], gVehData[vehicleid-1][BootUp], objective);
							PlayerActionMessage(playerid, 15.0, "zamyka maske pojazdu");							
						}
					}
				}
			}
		}
	}
	return 1;
}

dcmd_zamknijbagaznik(playerid, params[])
{
	#pragma unused params
	if(IsPlayerInAnyVehicle(playerid))
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Musisz byæ przed klap¹ ¿eby j¹ zamkn¹æ");
		return 1;
	}
	new vehicleid = GetClosestVehicle(playerid);
	new Float:xc, Float:yc, Float:ac, Float:bc, Float:vx, Float:vy, Float:vz, Float:va;
	GetVehiclePos(vehicleid, vx, vy, vz);
	GetVehicleZAngle(vehicleid, va);
	GetPlayerFacingAngle(playerid, ac);
	for(new i = 0; i < sizeof(CarsLenghts); i++)
	{
		if(CarsLenghts[i][lenghtModel] == gVehData[vehicleid-1][mVehModel])
		{
			GetXYInFrontOfPlayer(playerid, xc, yc, CarsLenghts[i][trunkDistance]);
			if(CarsLenghts[i][trunkAngle] == 1)
			{
				if(ac-180.0 < 0.0)
					ac += 180.0;
				else
					ac -= 180.0;
			}
			else if(CarsLenghts[i][trunkAngle] == 2)
			{
				bc = ac;
				if(ac-90.0 < 0.0)
					ac = 270.0+ac;
				else
					ac -= 90.0;
				if(bc+90.0 > 360.0)
					bc = 430.0-bc;
				else
					bc += 90.0;
			}
			if( ( floatabs(xc-vx) > 0.9 || floatabs(yc-vy) > 0.9 ) || (floatabs(va-ac) > 28.0 && (IsAMotorBike(vehicleid) && floatabs(va-bc) > 28.0)))
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Jesteœ zbyt daleko od pojazdu ¿eby zamkn¹æ baga¿nik !");
				return 1;
			}
			else
			{
				new objective;
				GetVehicleParamsEx(vehicleid, gVehData[vehicleid-1][EngineOn], gVehData[vehicleid-1][LightsOn], gVehData[vehicleid-1][Alarm], gVehData[vehicleid-1][CarDoors], gVehData[vehicleid-1][BonnetUp], gVehData[vehicleid-1][BootUp], objective);
				if(IsABoat(vehicleid) == 0 && IsABike(vehicleid) == 0 && IsAPlane(vehicleid) == 0 && IsAHelicopter(vehicleid) == 0)
				{
					if(CarsLenghts[i][trunkAngle])
					{
						if(!gVehData[vehicleid-1][BonnetUp])
							PlayerActionMessage(playerid, 15.0, "sprawdza baga¿nik");
						else
						{
							gVehData[vehicleid-1][BonnetUp] = 0;
							SaveVehData(vehicleid-1, "BonnetUp");
							PlayerActionMessage(playerid, 15.0, "zamyka baga¿nik pojazdu");
							SetVehicleParamsEx(vehicleid, gVehData[vehicleid-1][EngineOn], gVehData[vehicleid-1][LightsOn], gVehData[vehicleid-1][Alarm], gVehData[vehicleid-1][CarDoors], gVehData[vehicleid-1][BonnetUp], gVehData[vehicleid-1][BootUp], objective);
						}
					}
					else
					{
						if(!gVehData[vehicleid-1][BootUp])
							PlayerActionMessage(playerid, 15.0, "sprawdza baga¿nik");
						else
						{
							gVehData[vehicleid-1][BootUp] = 0;
							SaveVehData(vehicleid-1, "BootUp");
							PlayerActionMessage(playerid, 15.0, "zamyka baga¿nik pojazdu");
							SetVehicleParamsEx(vehicleid, gVehData[vehicleid-1][EngineOn], gVehData[vehicleid-1][LightsOn], gVehData[vehicleid-1][Alarm], gVehData[vehicleid-1][CarDoors], gVehData[vehicleid-1][BonnetUp], gVehData[vehicleid-1][BootUp], objective);						
						}
					}
				}
			}
		}
	}
	return 1;
}

dcmd_otworzbagaznik(playerid, params[])
{
	#pragma unused params
	if(IsPlayerInAnyVehicle(playerid))
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Musisz byæ przed klap¹ ¿eby j¹ otworzyæ");
		return 1;
	}
	new vehicleid = GetClosestVehicle(playerid);
	new Float:xc, Float:yc, Float:ac, Float:bc, Float:vx, Float:vy, Float:vz, Float:va;
	GetVehiclePos(vehicleid, vx, vy, vz);
	GetVehicleZAngle(vehicleid, va);
	GetPlayerFacingAngle(playerid, ac);
	for(new i = 0; i < sizeof(CarsLenghts); i++)
	{
		if(CarsLenghts[i][lenghtModel] == gVehData[vehicleid-1][mVehModel])
		{
			GetXYInFrontOfPlayer(playerid, xc, yc, CarsLenghts[i][trunkDistance]);
			if(CarsLenghts[i][trunkAngle] == 1)
			{
				if(ac-180 < 0)
					ac += 180;
				else
					ac -= 180;
			}
			else if(CarsLenghts[i][trunkAngle] == 2)
			{
				bc = ac;
				if(ac-90.0 < 0.0)
					ac = 270.0+ac;
				else
					ac -= 90.0;
				if(bc+90.0 > 360.0)
					bc = 430.0-bc;
				else
					bc += 90.0;
			}
			if( ( floatabs(xc-vx) > 0.9 || floatabs(yc-vy) > 0.9 ) || (floatabs(va-ac) > 28.0 && (IsAMotorBike(vehicleid) && floatabs(va-bc) > 28.0)))
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Jesteœ zbyt daleko od pojazdu ¿eby otworzyæ baga¿nik !");
				return 1;
			}
			else
			{
				new objective;
				GetVehicleParamsEx(vehicleid, gVehData[vehicleid-1][EngineOn], gVehData[vehicleid-1][LightsOn], gVehData[vehicleid-1][Alarm], gVehData[vehicleid-1][CarDoors], gVehData[vehicleid-1][BonnetUp], gVehData[vehicleid-1][BootUp], objective);
				if(gVehData[vehicleid-1][Closed])
				{
					SendClientMessage(playerid, COLOR_RED, "[INFO:] Pojazd jest zamkniêty, nie mo¿esz otworzyæ baga¿nika");
					return 1;
				}
				if(IsABoat(vehicleid) == 0 && IsABike(vehicleid) == 0 && IsAPlane(vehicleid) == 0 && IsAHelicopter(vehicleid) == 0 )
				{
					if(CarsLenghts[i][trunkAngle])
					{
						if(gVehData[vehicleid-1][BonnetUp])
							SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] Baga¿nik jest ju¿ otwarty !" );
						else
						{
							gVehData[vehicleid-1][BonnetUp] = 1;
							SaveVehData(vehicleid-1, "BonnetUp");
							PlayerActionMessage(playerid, 15.0, "otwiera baga¿nik pojazdu");
							SetVehicleParamsEx(vehicleid, gVehData[vehicleid-1][EngineOn], gVehData[vehicleid-1][LightsOn], gVehData[vehicleid-1][Alarm], gVehData[vehicleid-1][CarDoors], gVehData[vehicleid-1][BonnetUp], gVehData[vehicleid-1][BootUp], objective);				
						}
					}
					else
					{
						if(gVehData[vehicleid-1][BootUp])
							SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] Baga¿nik jest ju¿ otwarty !" );
						else
						{
							gVehData[vehicleid-1][BootUp] = 1;
							SaveVehData(vehicleid-1, "BootUp");
							PlayerActionMessage(playerid, 15.0, "otwiera baga¿nik pojazdu");
							SetVehicleParamsEx(vehicleid, gVehData[vehicleid-1][EngineOn], gVehData[vehicleid-1][LightsOn], gVehData[vehicleid-1][Alarm], gVehData[vehicleid-1][CarDoors], gVehData[vehicleid-1][BonnetUp], gVehData[vehicleid-1][BootUp], objective);
						}
					}
				}
			}
		}
	}
	return 1;
}
/*
dcmd_wymienzarowke(playerid, params[])
{
	new select[32];
	new carid;
	if(gPlayerData[playerid][pJob] != 17)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ mechanikiem !");
		return 1;
	}
	if(sscanf(params, "s[32]dd", select, carid))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /wymienzarowke [lewa/prawa] [rejestracja pojazdu]");
		return 1;
	}
	carid = CarSerialToID(carid);
	new panels, doors, lights, tires, slot;
	slot = PHaveItem(playerid, 1, 7);
	if(slot == 0)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz ¿arówki !");
		return 1;
	}
	if(strcmp(select, "lewa", true) == 0)
	{
		GetVehicleDamageStatus(carid+1, panels, doors, lights, tires);

		if(lights == 4 || lights == 232) //prawa
		{
			UpdateVehicleDamageStatus(carid+1, panels, doors, 0, tires);
		}
		if(lights == 5) //obydwie
		{
			UpdateVehicleDamageStatus(carid+1, panels, doors, 1, tires);
		}
		PlayerActionMessage(playerid, 15.0, "wyjmuje star¹ i wkrêca now¹ ¿arówke");
		RemovePlayerItemExUsed(playerid, slot);
	}
	if(strcmp(select, "prawa", true) == 0)
	{
		GetVehicleDamageStatus(carid+1, panels, doors, lights, tires);

		if(lights == 1)//lewa
		{
			UpdateVehicleDamageStatus(carid+1, panels, doors, 0, tires);
		}
		if(lights == 5)//obydwie
		{
			UpdateVehicleDamageStatus(carid+1, panels, doors, 1000, tires);
		}
		PlayerActionMessage(playerid, 15.0, "wyjmuje star¹ i wkrêca now¹ ¿arówke");
		RemovePlayerItemExUsed(playerid, slot);
	}
	return 1;
}*/

dcmd_kolczatka(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pFaction] == 255)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie nale¿ysz do ¿adnej frakcji");
		return 1;
	}
	
	if(DynamicFactions[gPlayerData[playerid][pFaction]][fType] != FACTIONT_POLICE)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Niew³aœciwa frakcja");
		return 1;
	}
	
	if(!gPlayerData[playerid][pDuty])
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ na s³u¿bie !");
		return 1;
	}
	
	new Float:Xj, Float:Yj,Float:Zj, Float:angle;
	
	if(IsPlayerInAnyVehicle(playerid))
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Musisz wyjœæ z pojazdu aby roz³o¿yæ kolczatke");
		return 1;
	}
	
	GetPlayerPos(playerid,Xj,Yj,Zj);
	GetPlayerFacingAngle(playerid, angle);
	CreateStrip(Xj,Yj,Zj,angle);
	PlayerActionMessage(playerid,15.0, "rozk³ada kolczatke");
	return 1;
}

dcmd_zwinkolczatke(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pFaction] == 255)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie nale¿ysz do ¿adnej frakcji");
		return 1;
	}
	if(DynamicFactions[gPlayerData[playerid][pFaction]][fType] != 1)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Niew³aœciwa frakcja");
		return 1;
	}
	if(!gPlayerData[playerid][pDuty])
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ na s³u¿bie !");
		return 1;
	}
	DeleteClosestStrip(playerid);
	PlayerActionMessage(playerid,15.0, "zwija kolczatke");
	return 1;
}

dcmd_zgaslampki(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	for(new i = 0; i <= 50; i++)
	{
		DestroyDynamicObject(lampki[i]);
	}
	return 1;
}

dcmd_zapallampki(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	lampki[0] = CreateDynamicObject(3472, -2706.1550292969, 375.78982543945, 2.8929057121277, 0, 0, 9);
	lampki[1] = CreateDynamicObject(3534, -2705.6997070313, 371.72854614258, 15.519973754883, 0, 0, 0);
	lampki[2] = CreateDynamicObject(3472, -2706.154296875, 375.7890625, 2.8929057121277, 0, 0, 70.997802734375);
	lampki[3] = CreateDynamicObject(3534, -2702.3251953125, 374.30419921875, 15.519973754883, 0, 0, 0);
	lampki[4] = CreateDynamicObject(3534, -2702.9965820313, 378.45223999023, 15.519973754883, 0, 0, 0);
	lampki[5] = CreateDynamicObject(3534, -2706.9777832031, 379.99160766602, 15.519973754883, 0, 0, 0);
	lampki[6] = CreateDynamicObject(3534, -2710.4416503906, 377.25756835938, 15.519973754883, 0, 0, 0);
	lampki[7] = CreateDynamicObject(3534, -2709.4470214844, 372.87069702148, 15.519973754883, 0, 0, 0);
	lampki[8] = CreateDynamicObject(3472, -2706.154296875, 375.7890625, 7.0679140090942, 0, 0, 324.99365234375);
	lampki[9] = CreateDynamicObject(3472, -2706.1577148438, 375.63671875, 7.0679140090942, 0, 0, 34.99365234375);
	lampki[10] = CreateDynamicObject(3534, -2703.4255371094, 375.50555419922, 19.719982147217, 0, 0, 0);
	lampki[11] = CreateDynamicObject(3534, -2704.1799316406, 378.34268188477, 19.719982147217, 0, 0, 0);
	lampki[12] = CreateDynamicObject(3534, -2707.4841308594, 378.72827148438, 19.719982147217, 0, 0, 0);
	lampki[13] = CreateDynamicObject(3534, -2709.826171875, 375.79632568359, 19.719982147217, 0, 0, 0);
	lampki[14] = CreateDynamicObject(3534, -2707.9919433594, 372.66094970703, 19.719982147217, 0, 0, 0);
	lampki[15] = CreateDynamicObject(3534, -2704.3283691406, 372.77670288086, 19.719982147217, 0, 0, 0);
	lampki[16] = CreateDynamicObject(3472, -2706.1235351563, 375.84185791016, 11.277879714966, 0, 0, 64.99365234375);
	lampki[17] = CreateDynamicObject(3472, -2706.1650390625, 375.82421875, 11.277879714966, 0, 0, 0.9896240234375);
	lampki[18] = CreateDynamicObject(3534, -2704.7834472656, 376.71600341797, 23.394975662231, 0, 0, 0);
	lampki[19] = CreateDynamicObject(3534, -2704.853515625, 375.08264160156, 23.394975662231, 0, 0, 0);
	lampki[20] = CreateDynamicObject(3534, -2706.1584472656, 374.28622436523, 23.394975662231, 0, 0, 0);
	lampki[21] = CreateDynamicObject(3534, -2707.5517578125, 374.9313659668, 23.394975662231, 0, 0, 0);
	lampki[22] = CreateDynamicObject(3534, -2707.5888671875, 376.50729370117, 23.394975662231, 0, 0, 0);
	lampki[23] = CreateDynamicObject(3534, -2706.326171875, 377.49975585938, 23.394975662231, 0, 0, 0);
	lampki[24] = CreateDynamicObject(1262, -2702.7143554688, 375.80667114258, 15.391092300415, 0, 0, 268);
	lampki[25] = CreateDynamicObject(1262, -2704.6826171875, 378.99771118164, 15.391092300415, 0, 0, 343.99499511719);
	lampki[26] = CreateDynamicObject(1262, -2708.4245605469, 378.42178344727, 15.391092300415, 0, 0, 27.992919921875);
	lampki[27] = CreateDynamicObject(1262, -2709.3117675781, 374.82434082031, 15.391092300415, 0, 0, 93.987670898438);
	lampki[28] = CreateDynamicObject(1262, -2707.2048339844, 372.9743347168, 15.391092300415, 0, 0, 145.98254394531);
	lampki[29] = CreateDynamicObject(1262, -2704.3208007813, 373.56674194336, 15.391092300415, 0, 0, 217.98083496094);
	lampki[30] = CreateDynamicObject(1262, -2706.4538574219, 372.8544921875, 20.141092300415, 0, 0, 173.97973632813);
	lampki[31] = CreateDynamicObject(1262, -2706.0747070313, 378.69476318359, 20.141092300415, 0, 0, 359.97946166992);
	lampki[32] = CreateDynamicObject(1262, -2708.0883789063, 374.65997314453, 20.141092300415, 0, 0, 125.22805786133);
	lampki[33] = CreateDynamicObject(1262, -2704.2888183594, 377.2370300293, 20.141092300415, 0, 0, 297.97805786133);
	lampki[34] = CreateDynamicObject(1262, -2704.1677246094, 374.52209472656, 20.141092300415, 0, 0, 237.97668457031);
	lampki[35] = CreateDynamicObject(1262, -2708.0766601563, 376.90200805664, 20.141092300415, 0, 0, 57.974853515625);
	lampki[36] = CreateDynamicObject(7666, -2706.2939453125, 375.23712158203, 29.835269927979, 0, 0, 0);
	lampki[37] = CreateDynamicObject(7666, -2706.2939453125, 375.236328125, 29.835269927979, 0, 0, 60);
	lampki[38] = CreateDynamicObject(7666, -2706.2939453125, 375.236328125, 29.835269927979, 0, 0, 119.99633789063);
	lampki[39] = CreateDynamicObject(7666, -2706.2939453125, 375.236328125, 29.835269927979, 0, 0, 39.99267578125);
	lampki[40] = CreateDynamicObject(7666, -2706.2939453125, 375.236328125, 29.835269927979, 0, 0, 159.990234375);
	lampki[41] = CreateDynamicObject(7666, -2706.2939453125, 375.236328125, 29.835269927979, 0, 0, 239.98838806152);
	lampki[42] = CreateDynamicObject(7666, -2706.2939453125, 375.236328125, 29.835269927979, 0, 0, 329.9853515625);
	lampki[43] = CreateDynamicObject(7666, -2706.2939453125, 375.236328125, 29.835269927979, 0, 0, 29.9853515625);
	lampki[44] = CreateDynamicObject(7666, -2706.2731933594, 375.25021362305, 29.835269927979, 0, 0, 85.981689453125);
	lampki[45] = CreateDynamicObject(3472, -2706.314453125, 375.80249023438, 14.777894973755, 0, 0, 40.989624023438);
	lampki[46] = CreateDynamicObject(3472, -2706.115234375, 375.8173828125, 15.027879714966, 0, 0, 91.984466552734);
	lampki[47] = CreateDynamicObject(3534, -2707.5517578125, 374.9306640625, 26.894975662231, 0, 0, 0);
	lampki[48] = CreateDynamicObject(3534, -2706.4760742188, 376.70639038086, 26.894975662231, 0, 0, 0);
	lampki[49] = CreateDynamicObject(3534, -2704.6840820313, 375.99844360352, 26.894975662231, 0, 0, 0);
	lampki[50] = CreateDynamicObject(3534, -2705.1484375, 374.25082397461, 26.894975662231, 0, 0, 0);
	return 1;
}

dcmd_lightdamagevalue(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new vehicleid, string[128];
	if(sscanf(params, "d", vehicleid))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /vehdamagedoor [veh id]");
	}
	new panels,doors,lights,tires;
	GetVehicleDamageStatus(vehicleid,panels,doors,lights,tires);
	format(string, sizeof(string), "[INFO:] value: %d", lights);
	SendClientMessage(playerid, COLOR_WHITE, string);
	return 1;
}

dcmd_acarenters(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] < 1)
		return 0;
	new serial, id;
	if(sscanf(params, "d", serial))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /acarenters [rejestracja]");
		return 1;
	}
	id = CarSerialToID(serial);
	if(id == -1)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie ma pojazdu z tak¹ rejestracj¹ !");
		return 1;
	}
	PutPlayerIntoVehicle(playerid,id+1,0);
	return 1;
}

dcmd_acarentersex(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] < 1)
		return 0;
	new serial, id;
	if(sscanf(params, "d", serial))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /acarentersex [rejestracja]");
		return 1;
	}
	id = CarSerialToID(serial);
	if(id == -1)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie ma pojazdu z tak¹ rejestracj¹ !");
		return 1;
	}
	SetPlayerVirtualWorld(playerid, gVehData[id-1][mVehVW]);
	SetPlayerInterior(playerid, gVehData[id-1][mVehInt]);
	PutPlayerIntoVehicle(playerid,id+1,0);
	return 1;
}
/*
dcmd_zamontujhak(playerid, params[])
{
	if(gPlayerData[playerid][pJob] != 17)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ mechanikiem !");
		return 1;
	}
	new vehicleID = INVALID_VEHICLE_ID;
	if(sscanf(params, "d", vehicleID))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /zamontujhak [rejestracja]");
		return 1;
	}
	if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Musisz byæ przy pojeŸdzie aby zamontowaæ hak !");
		return 1;
	}
	vehicleID = CarSerialToID(vehicleID);
	if(vehicleID == -1)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie ma pojazdu o takiej rejestracji");
		return 1;
	}
	new Float:xpos, Float:ypos, Float:zpos;
	GetVehiclePos(vehicleID+1, xpos, ypos, zpos);
	if(!PlayerToPoint(8.0,playerid, xpos, ypos, zpos))
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Jesteœ zbyt daleko od tego pojazdu !");
		return 1;
	}
	new slot = PHaveItem(playerid, 1, 10);
	if(slot == 0)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz haku holowniczego do zamontowania !");
		return 1;
	}
	RemovePlayerItemExUsed(playerid, slot);
	PlayerActionMessage(playerid,15.0, "montuje hak holowniczy");
	gVehData[vehicleID][Hook] = 1;
	SaveVehData(vehicleID, "Hook");
	SendClientMessage(playerid, COLOR_GREEN, "[INFO:] Zamontowa³eœ hak holowniczy !");
	return 1;
}*/

dcmd_zarzadzajfirma(playerid, params[])
{
	#pragma unused params
	
	if(gPlayerData[playerid][pFaction2] == 255)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w³aœcicielem firmy");
		return 1;
	}
	
	if(gPlayerData[playerid][pRank2] != 1)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w³aœcicielem firmy");
		return 1;
	}

	ShowPlayerDialog(playerid, DIALOG_COMPANY, DIALOG_STYLE_LIST, "Panel firmy", "Zatrudnij pracownika\nZwolnij pracownika\nWynagrodzenie", "Wybierz", "Zamknij");
	return 1;
}

dcmd_zarzadzajfrakcja(playerid, params[])
{
	#pragma unused params
	
	if(gPlayerData[playerid][pFaction] == 255)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ liderem frakcji");
		return 1;
	}
	
	if(gPlayerData[playerid][pRank] != 1)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ liderem frakcji");
		return 1;
	}

	if(DynamicFactions[gPlayerData[playerid][pFaction]][fType] == FACTIONT_GANG)
	{
		ShowPlayerDialog(playerid, DIALOG_FACTION, DIALOG_STYLE_LIST, "Panel frakcji", "Zaproœ do frakcji\nWyproœ z frakcji\nZmieñ rangê", "Wybierz", "Zamknij");
	}
	else
	{
		ShowPlayerDialog(playerid, DIALOG_FACTION, DIALOG_STYLE_LIST, "Panel frakcji", "Zaproœ do frakcji\nWyproœ z frakcji\nZmieñ rangê\nZmieñ skin", "Wybierz", "Zamknij");
	}
	
	return 1;
}

// dcmd_c3dtv(playerid, params[])
// {
	// new Float:xpos, Float:ypos, Float:zpos, vehicleID;
	// new string[128];
	// if(gPlayerData[playerid][pAdmin] != 5)
		// return 0;

	// if(sscanf(params, "s[128]dfff", string, vehicleID, xpos, ypos, zpos))
	// {
		// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /c3dtv [string] [vehid] [x] [y] [z]");
		// return 1;
	// }

	// CreateDynamic3DTextLabel(string, COLOR_LIGHTYELLOW, xpos, ypos, zpos, 50.0, INVALID_PLAYER_ID, vehicleID, 1);
	// return 1;
// }

// dcmd_d3dt(playerid, params[])
// {
	// new Text3D:objid;
	// if(gPlayerData[playerid][pAdmin] != 3)
		// return 0;

	// if(sscanf(params, "d", objid))
	// {
		// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /c3dtv [objid]");
		// return 1;
	// }

	// DestroyDynamic3DTextLabel(objid);
	// return 1;
// }

dcmd_agodmode(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;

	switch(gAdminGodMode[playerid])
	{
		case 0:
		{
			gAdminGodMode[playerid] = 1;
			SendClientMessage(playerid, COLOR_GREEN, "[INFO:] Admin vehicle god mode ON");
		}
		case 1:
		{
			gAdminGodMode[playerid] = 0;
			SendClientMessage(playerid, COLOR_GREEN, "[INFO:] Admin vehicle god mode OFF");
		}
	}
	return 1;
}

dcmd_acarmodel(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] < 4)
		return 0;

	new carmodel, vehicleid;
	if(sscanf(params, "d", carmodel))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /acarmodel [model]");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "415 - ferrari ; 451 - ferrari ; 521 - pcj900 ; 522 - nrg ; 488 - sannew ; 510 - MTB ; 411 - infernus ; 562 - elegy ");
		return 1;
	}
	vehicleid = GetPlayerVehicleID(playerid);
	if(vehicleid == 0)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w pojeŸdzie !");
		return 1;
	}
	if(carmodel < 400 || carmodel > 611 || carmodel == 537 || carmodel == 538 || carmodel == 569 || carmodel == 570 || carmodel == 590)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nieprawid³owy model !");
		return 1;
	}
	
	gVehData[vehicleid-1][mVehModel] = carmodel;
	
	GetVehiclePos(vehicleid, gVehData[vehicleid-1][mVehX], gVehData[vehicleid-1][mVehY], gVehData[vehicleid-1][mVehZ]);
	GetVehicleZAngle(vehicleid, gVehData[vehicleid-1][mVehA]);
	
	DestroyVehicle(vehicleid);
	CreateVehicle(gVehData[vehicleid-1][mVehModel],gVehData[vehicleid-1][mVehX],gVehData[vehicleid-1][mVehY],gVehData[vehicleid-1][mVehZ],gVehData[vehicleid-1][mVehA],gVehData[vehicleid-1][mVehColor1],gVehData[vehicleid-1][mVehColor2],-1);
	
	SetVehicleVirtualWorld(vehicleid, GetPlayerVirtualWorld(playerid));
	LinkVehicleToInterior(vehicleid, GetPlayerInterior(playerid));
	PutPlayerInVehicle(playerid, vehicleid, 0);
	
	new enginedyn,lights,alarm,doors,bonnet,boot,objective;
	
	GetVehicleParamsEx(vehicleid,enginedyn,lights,alarm,doors,bonnet,boot,objective);
	SetVehicleParamsEx(vehicleid,gVehData[vehicleid-1][EngineOn],gVehData[vehicleid-1][LightsOn],alarm,0,gVehData[vehicleid-1][BonnetUp],gVehData[vehicleid-1][BootUp],objective);
	
	SendClientMessage(playerid, COLOR_GREEN, "[INFO:] Zmieni³eœ model pojazdu");
	
	SaveVehData(vehicleid-1, "VehModel");
	SaveVehData(vehicleid-1, "VehPos");
	
	return 1;
}

dcmd_acarcolor(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] < 1)
		return 0;

	new color1, color2, vehicleid;
	if(sscanf(params, "dd", color1, color2))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /acarcolor [color1id] [color2id]");
		return 1;
	}
	if(color1 < -1 || color1 > 126 || color2 < -1 || color2 > 127)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Zakres kolorów: 0-126 oraz -1");
		return 1;
	}
	vehicleid = GetPlayerVehicleID(playerid);
	if(vehicleid == 0)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w pojeŸdzie !");
		return 1;
	}
	gVehData[vehicleid-1][mVehColor1] = color1;
	gVehData[vehicleid-1][mVehColor2] = color2;
	ChangeVehicleColor(vehicleid, color1, color2);
	SendClientMessage(playerid, COLOR_GREEN, "[INFO:] Zmieni³eœ kolor pojazdu");
	SaveVehData(vehicleid-1, "VehColor1");
	SaveVehData(vehicleid-1, "VehColor2");
	return 1;
}

dcmd_acarcolorex(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] < 1)
		return 0;

	new color1, color2, vehicleid;
	if(sscanf(params, "dd", color1, color2))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /acarcolor [color1id] [color2id]");
		return 1;
	}
	if(color1 < -1 || color1 > 255 || color2 < -1 || color2 > 255)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Zakres kolorów: 0-255 oraz -1");
		return 1;
	}
	vehicleid = GetPlayerVehicleID(playerid);
	if(vehicleid == 0)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w pojeŸdzie !");
		return 1;
	}
	gVehData[vehicleid-1][mVehColor1] = color1;
	gVehData[vehicleid-1][mVehColor2] = color2;
	ChangeVehicleColor(vehicleid, color1, color2);
	SendClientMessage(playerid, COLOR_GREEN, "[INFO:] Zmieni³eœ kolor pojazdu");
	SaveVehData(vehicleid-1, "VehColor1");
	SaveVehData(vehicleid-1, "VehColor2");
	return 1;
}

dcmd_gotoap(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] < 1)
		return 0;

	new vehicleid = GetPlayerVehicleID(playerid);
	if(vehicleid == 0)
	{
		SetPlayerToPos(playerid, -2206.0, -2282.0, 31);
	}
	else
	{
		SetVehicleToPos(vehicleid, -2206.0, -2282.0, 31);
	}
	SetPlayerInterior(playerid,0);
	SetPlayerVirtualWorld(playerid,0);
	return 1;
}

dcmd_gotofc(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] < 1)
		return 0;
	new vehicleid = GetPlayerVehicleID(playerid);
	if(!vehicleid)
		SetPlayerToPos(playerid, -142.87, 1269.18, 19.8);
	else
		SetVehicleToPos(vehicleid, -142.87, 1269.18, 19.8);
	return 1;
}

dcmd_gotosf(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] < 1)
		return 0;
	new tpID;
	sscanf(params, "d", tpID);
	new vehicleid = GetPlayerVehicleID(playerid);
	switch(tpID)
	{
		case 0:
		{
			if(!vehicleid)
				SetPlayerToPos(playerid, -1417.0,-295.8,14.1);
			else
				SetVehicleToPos(vehicleid, -1417.0,-295.8,14.1);
		}
		case 1:
		{
			if(!vehicleid)
				SetPlayerToPos(playerid, -1985.41, 138.34, 27.68);
			else
				SetVehicleToPos(vehicleid, -1985.41, 138.34, 27.68);
		}
	}	
	SetPlayerVirtualWorld(playerid,0);
	SetPlayerInterior(playerid,0);
	return 1;
}

dcmd_gotosf2(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] < 1)
		return 0;

	new vehicleid = GetPlayerVehicleID(playerid);
	if(vehicleid == 0)
		SetPlayerToPos(playerid, -2649.0,-46.0,4.1);
	else
		SetVehicleToPos(vehicleid, -2649.0,-46.0,4.1);
	SetPlayerInterior(playerid,0);
	SetPlayerVirtualWorld(playerid,0);
	return 1;
}

dcmd_gotomg(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] < 1)
		return 0;

	new vehicleid = GetPlayerVehicleID(playerid);
	if(vehicleid == 0)
	{
		SetPlayerToPos(playerid, 1262.0, 362.0, 20.0);
	}
	else
	{
		SetVehicleToPos(vehicleid, 1262.0, 362.0, 20.0);
	}
	SetPlayerInterior(playerid,0);
	SetPlayerVirtualWorld(playerid,0);
	return 1;
}

dcmd_gotobb(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] < 1)
		return 0;

	new vehicleid = GetPlayerVehicleID(playerid);
	if(vehicleid == 0)
	{
		SetPlayerToPos(playerid, 260.0, -140.0, 2.0);
	}
	else
	{
		SetVehicleToPos(vehicleid, 260.0, -140.0, 2.0);
	}
	SetPlayerInterior(playerid,0);
	SetPlayerVirtualWorld(playerid,0);
	return 1;
}

dcmd_gotodm(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] < 1)
		return 0;

	new vehicleid = GetPlayerVehicleID(playerid);
	if(vehicleid == 0)
	{
		SetPlayerToPos(playerid, 663.0, -585.0, 16.0);
	}
	else
	{
		SetVehicleToPos(vehicleid, 663.0, -585.0, 16.0);
	}
	SetPlayerInterior(playerid,0);
	SetPlayerVirtualWorld(playerid,0);
	return 1;
}

dcmd_gotopc(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] < 1)
		return 0;

	new vehicleid = GetPlayerVehicleID(playerid);
	if(vehicleid == 0)
	{
		SetPlayerToPos(playerid, 2317.0, 3.0, 26.0);
	}
	else
	{
		SetVehicleToPos(vehicleid, 2317.0, 3.0, 26.0);
	}
	SetPlayerInterior(playerid,0);
	SetPlayerVirtualWorld(playerid,0);
	return 1;
}

dcmd_acarcomponentslot(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new slot, vehicleid, componentid;
	if(sscanf(params, "d", slot))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /acarcomponentslot [slot]");
		return 1;
	}
	vehicleid = GetPlayerVehicleID(playerid);
	if(vehicleid == 0)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w pojeŸdzie !");
		return 1;
	}
	componentid = GetVehicleComponentInSlot(vehicleid, slot);
	new string[128];
	format(string, sizeof(string), "[INFO:] Model komponentu: %d, slot: %d", componentid, slot);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	return 1;
}

dcmd_acaraddcomponent(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new componentid, vehicleid;
	if(sscanf(params, "d", componentid))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /acaraddcomponent [componentid]");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "NOS - 1010 ");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "ELEGY 562 : 1034,1035,1036,1037,1038,1039,1040,1041,1146,1147,1148,1149,1171,1172");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "SULTAN 560  : 1026,1027,1028,1029,1030,1031,1032,1033,1138,1139,1140,1141,1169,1170");
		return 1;
	}
	vehicleid = GetPlayerVehicleID(playerid);
	if(vehicleid == 0)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w pojeŸdzie !");
		return 1;
	}
	if(componentid > 1193 || componentid < 1000)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Zakres komponentów: 1000-1193");
		return 1;
	}
	AddVehicleComponent(vehicleid, componentid);
	SendClientMessage(playerid, COLOR_GREEN, "[INFO:] Dodano komponent do pojazdu");
	return 1;
}

dcmd_acarcomponentslottype(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new componentid, vehicleid, componentslot;
	if(sscanf(params, "d", componentid))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /acarcomponentslottype [componentid]");
		return 1;
	}
	vehicleid = GetPlayerVehicleID(playerid);
	if(vehicleid == 0)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w pojeŸdzie !");
		return 1;
	}
	componentslot = GetVehicleComponentType(componentid);
	new string[128];
	format(string, sizeof(string), "[INFO:] Komponent ID: %d, slot: %d",componentid, componentslot);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	return 1;
}

dcmd_acarpark(playerid, params[])
{
	#pragma unused params
	
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	
	new vehicleid = GetPlayerVehicleID(playerid);
	
	if(vehicleid == 0)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w pojeŸdzie !");
		return 1;
	}
	
	GetVehiclePos(vehicleid, gVehData[vehicleid-1][mVehX], gVehData[vehicleid-1][mVehY], gVehData[vehicleid-1][mVehZ]);
	GetVehicleZAngle(vehicleid, gVehData[vehicleid-1][mVehA]);

	SaveVehData(vehicleid-1, "VehPos");

	new wstring[128];
	format(wstring, sizeof(wstring), "[ADMIN:] %s has parked vehicle ID %d.", gPlayerData[playerid][pName],vehicleid);
	SendAdminMessage(COLOR_YELLOW, wstring);
	return 1;
}

dcmd_vehfueltype(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] < 4)
		return 0;

	new vehicleid = GetPlayerVehicleID(playerid);
	if(vehicleid == 0)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w pojeŸdzie !");
		return 1;
	}
	new fueltype;
	if(sscanf(params, "d", fueltype))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /vehfueltype [typ paliwa]");
		return 1;
	}
	if(fueltype < 0 || fueltype > 3)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Zakres typów: 0-3");
		return 1;
	}
	gVehData[vehicleid-1][Fuel] = fueltype;
	SendClientMessage(playerid, COLOR_GREEN, "[INFO:] Zmieni³eœ typ paliwa dla pojazdu");
	SaveVehData(vehicleid-1, "Fuel");
	return 1;
}

// dcmd_wantedex(playerid, params[])
// {
	// #pragma unused params
	// if(gPlayerData[playerid][pFaction] == 255)
	// {
		// SendClientMessage(playerid, COLOR_RED, "[INFO:] Niew³aœciwa frakcja !");
		// return 1;
	// }
	// if(DynamicFactions[gPlayerData[playerid][pFaction]][fType] != 1)
	// {
		// SendClientMessage(playerid, COLOR_RED, "[INFO:] Niew³aœciwa frakcja !");
		// return 1;
	// }
	// ShowPlayerDialog(playerid, DIALOG_WANTED, DIALOG_STYLE_INPUT, "Wanted", "Wpisz imie oraz nazwisko osoby w formie \"Imie_Nazwisko\"", "Wyszukaj", "Anuluj");
	// return 1;
// }

dcmd_ignorujooc(playerid, params[])
{
	#pragma unused params
	if(gOOC[playerid])
	{
		gOOC[playerid] = 0;
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Przesta³eœ ignorowaæ chat OOC");
		return 1;
	}
	else
	{
		gOOC[playerid] = 1;
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ignorujesz chat OOC");
		return 1;
	}
}

dcmd_afiregov2(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] < 4)
		return 0;

	CreateObject(18688, -2171.4, -2314.1, 32.3, 0.0, 0.0, 0.0, 150.0);
	return 1;
}

dcmd_pobierzgazety(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pJob] != 21)
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ roznosicielem gazet !");
		return 1;
	}
	if(!PlayerToPoint(1.5, playerid, NewsBoyJob[TakeJobX], NewsBoyJob[TakeJobY], NewsBoyJob[TakeJobZ]))
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w punkcie poboru gazet");
		return 1;
	}
	new string[128];
	if(gPapers[playerid] == NewsBoyJob[TakeJobPapersCount])
	{
		format(string, sizeof(string), "[INFO:] Posiadasz ju¿ maksymaln¹ iloœæ gazet (%d)", NewsBoyJob[TakeJobPapersCount]);
		SendClientMessage(playerid, COLOR_ORANGE, string);
		return 1;
	}
	gPapers[playerid] = NewsBoyJob[TakeJobPapersCount];

	format(string, sizeof(string), "[INFO:] Pobra³eœ %d gazet", NewsBoyJob[TakeJobPapersCount]);
	SendClientMessage(playerid, COLOR_ORANGE, string);
	return 1;
}

dcmd_rzucgazete(playerid, params[])
{
	#pragma unused params
	
	if(gPlayerData[playerid][pJob] != 21)
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ roznosicielem gazet !");
		return 1;
	}
	
	if(gPapers[playerid] == 0)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie masz przy sobie ¿adnych gazet ! Wpisz /komendypracy aby uzyskaæ pomoc");
		return 1;
	}
	
	new string[128];
	
	for(new i = 0; i < sizeof(Houses); i++)
	{
		if(PlayerToPoint(2.0, playerid, Houses[i][EnterX], Houses[i][EnterY], Houses[i][EnterZ]) && GetPlayerVirtualWorld(playerid) == Houses[i][EnterWorld])
		{
			if(gLastHVisit[playerid][i] > 0)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ktoœ ju¿ rzuci³ gazete pod tym domem, wróæ póŸniej !");
				return 1;
			}
			
			PlayerActionMessage(playerid, 10.0, "rzuca gazete");
			
			gPapers[playerid]--;
			
			format(string, sizeof(string), "[INFO:] Pozosta³o gazet: %d", gPapers[playerid]);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
		
			GivePlayerCash(playerid, NewsBoyJob[TakeJobReward]);
			
			gLastHVisit[playerid][i] = 300;
			
			DynamicFactions[FACTIONID_GOVERNMENT][fBank] -= NewsBoyJob[TakeJobReward];
			SaveFData(FACTIONID_GOVERNMENT, "Bank");
			
			return 1;
		}
	}
	for(new i = 0; i < sizeof(Businesses); i++)
	{
		if(PlayerToPoint(2.0, playerid, Businesses[i][EnterX], Businesses[i][EnterY], Businesses[i][EnterZ]) && GetPlayerVirtualWorld(playerid) == Businesses[i][EnterWorld])
		{
			if(gLastBVisit[playerid][i] > 0)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ktoœ ju¿ rzuci³ gazete pod tym biznesem, wróæ póŸniej !");
				return 1;
			}
			
			PlayerActionMessage(playerid, 10.0, "rzuca gazete");
			
			gPapers[playerid]--;
			
			format(string, sizeof(string), "[INFO:] Pozosta³o gazet: %d", gPapers[playerid]);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			
			GivePlayerCash(playerid, NewsBoyJob[TakeJobReward]);
			
			gLastBVisit[playerid][i] = 300;
			
			DynamicFactions[FACTIONID_GOVERNMENT][fBank] -= NewsBoyJob[TakeJobReward];
			SaveFData(FACTIONID_GOVERNMENT, "Bank");
			
			return 1;
		}
	}
	
	SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ przed wejœciem do ¿adnego domu ani biynesu");
	
	return 1;
}

dcmd_anewsboyjobpos(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] < 4)
		return 0;

	new Float:x, Float:y, Float:z;
	GetPlayerPos(playerid, x, y, z);
	new Float:angle;
	GetPlayerFacingAngle(playerid, angle);
	NewsBoyJob[TakeJobX] = x;
	NewsBoyJob[TakeJobY] = y;
	NewsBoyJob[TakeJobZ] = z;
	NewsBoyJob[TakeJobWorld]= GetPlayerVirtualWorld(playerid);
	NewsBoyJob[TakeJobInterior] = GetPlayerInterior(playerid);
	NewsBoyJob[TakeJobAngle] = angle;
	NewsBoyJob[TakeJobPickupID] = ChangePickupModel(NewsBoyJob[TakeJobPickupID],1239, NewsBoyJob[TakeJobX], NewsBoyJob[TakeJobY], NewsBoyJob[TakeJobZ]);
	SaveNewsBoyJob();
	SendClientMessage(playerid, COLOR_ADMINCMD, "You have successfully set the NewsBoy Job Position.");
	return 1;
}

dcmd_anewsboyjobreward(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] < 4)
		return 0;

	new reward;
	if(sscanf(params, "d", reward))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /anewsboyjobreward [reward]");
		return 1;
	}
	new string[128];
	NewsBoyJob[TakeJobReward] = reward;
	SaveNewsBoyJob();
	format(string, sizeof(string), "[INFO:] NewsBoy job reward set to $%d", reward);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	return 1;
}

dcmd_anewsboyjobpapers(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] < 4)
		return 0;

	new papers;
	if(sscanf(params, "d", papers))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /anewsboyjobpapers [papers]");
		return 1;
	}
	new string[128];
	NewsBoyJob[TakeJobPapersCount] = papers;
	SaveNewsBoyJob();
	format(string, sizeof(string), "[INFO:] NewsBoy job papers count set to %d", papers);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	return 1;
}

dcmd_aradio(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;

	new slot, idstation;
	if(sscanf(params, "dd", slot, idstation))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[U¯YCIE] /aradio [slot (0-4)] [idstation]");
		SendClientMessage(playerid,COLOR_LIGHTYELLOW2, RADIO_CHANNELS);
		SendClientMessage(playerid,COLOR_LIGHTYELLOW2, RADIO_CHANNELS2);
		SendClientMessage(playerid,COLOR_LIGHTYELLOW2, RADIO_CHANNELS3);
		return 1;
	}
	GetPlayerPos(playerid, gRadioSet[slot][AudioX], gRadioSet[slot][AudioY], gRadioSet[slot][AudioZ]);
	gRadioSet[slot][StationID] = idstation;
	if(IsValidDynamicArea(gRadioSet[slot][AreaID]))
	{
		DestroyDynamicArea(gRadioSet[slot][AreaID]);
	}
	GetPlayerPos(playerid,gPlayerData[playerid][pCrashX], gPlayerData[playerid][pCrashY], gPlayerData[playerid][pCrashZ]);
	gRadioSet[slot][AreaID] = CreateDynamicCircle(gPlayerData[playerid][pCrashX], gPlayerData[playerid][pCrashY], 80.0);
	for(new i = 0; i < CUSTOM_MAX_PLAYERS; i++)
	{
		Audio_Stop(i, gRadioID[slot][i] );
		if(IsPlayerInDynamicArea(i, gRadioSet[slot][AreaID]))
		{
			gRadioID[slot][i] = Audio_PlayStreamed(i, gRadio[gRadioSet[slot][StationID]], false, false, false);
		}
	}
	return 1;
}

dcmd_aradiovol(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;

	new slot, vol;
	if(sscanf(params, "dd", slot, vol))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /aradiovol  [slot] [volume]");
		return 1;
	}
	gRadioSet[slot][Volume] = vol;
	for(new i = 0; i < CUSTOM_MAX_PLAYERS; i++)
	{
		Audio_SetVolume(i, gRadioID[slot][i], gRadioSet[slot][Volume]);
	}
	return 1;
}

dcmd_sprzedajnarkotyki(playerid, params[])
{
	new string[128];
	if(gPlayerData[playerid][pJob] != 2)
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ dilerem narkotyków !");
		return 1;
	}
	new playa, needed;
	if(sscanf(params, "dd", playa, needed))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /sprzedajnarkotyki [playerid] [iloœæ]");
		return 1;
	}
	if(needed < 1 || needed > 50)
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] od 1 do 50.");
		return 1;
	}
	if(needed > gPlayerData[playerid][pDrugs])
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie posiadasz przy sobie tylu narkotyków !");
		return 1;
	}
	if(IsPlayerConnected(playa))
	{
		if(ProxDetectorS(8.0, playerid, playa))
		{
			if(playa != playerid)
			{
				format(string, sizeof(string), "[INFO:] Przekaza³eœ graczowi %s %d gramów narkotyków.", GetPlayerNameEx(playa), needed);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
				format(string, sizeof(string), "[INFO:] %s da³ Tobie %d gram narkotyków.", GetPlayerNameEx(playerid), needed);
				SendClientMessage(playa, COLOR_LIGHTYELLOW2, string);
				gPlayerData[playa][pDrugs] += needed;
				gPlayerData[playerid][pDrugs] -= needed;

				SavePlayerData(playa, "Drugs");
				SavePlayerData(playerid, "Drugs");
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz sam sobie sprzedaæ narkotyków !");
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ blisko tej osoby !");
		}
	}
	else
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Niew³aœciwe ID.");
	}
	return 1;
}

dcmd_animacje(playerid, params[])
{
	#pragma unused params
	
	new string[300];

	format(string, sizeof(string), ""#COLOR_BEGIN2" * Animacje *\n   "#COLOR_DEFAULT"/recedogory - /schowajkomorke - /stoj - /deal - /gsign - /zaloz - /cygaro - /caluj - /bat\n");
	strcat(string, "   /spray - /throw - /uthrow - /bthrow - /zaplac - /machaj - /chat - /idz - /fuckyou - /joga");
	strcat(string, "   /siadz1 - /siadz2 - /wstan - /wstan2 - /wstan3 - /padnij1 - /padnij2 - /padnij3 - /ranny\n\n"#COLOR_BEGIN"/animacje2");
	
	ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, ""#COLOR_TITLE"Animacje", string, "Zamknij", "");
	
	return 1;
}

dcmd_animacje2(playerid, params[])
{
	#pragma unused params
	SendClientMessage(playerid, COLOR_GREEN,"[INFO:] /animcrib /animjump /animdealer /animdildo /animdodge /animdozer  /animdrivebys /animfat");
	SendClientMessage(playerid, COLOR_GREEN,"[INFO:] /animfightb /animfightc /animfightd /animfighte /animfinale /animfinale2 /animflamef");
	SendClientMessage(playerid, COLOR_GREEN,"[INFO:] /animflowers /animghands /animfw /animghetto /animgog /animgraffity /animgreya /animgren");
	SendClientMessage(playerid, COLOR_GREEN,"[INFO:] /animhaircut /animheist  /animinthouse /animintoffice /animplayerdbf /animplayidles /animpolice");
	SendClientMessage(playerid, COLOR_GREEN,"[INFO:] /animpool /animpoor /animpython /animquad /animquadbz /animrapping  /animrifle /animriot /animrobbank ");
	SendClientMessage(playerid, COLOR_GREEN,"[INFO:] /animrocket /animrustler /animryder /animscrat /animshamal /animshop /animskate /animshotgun");
	SendClientMessage(playerid, COLOR_GREEN,"[INFO:] /animvortex /animtec /animtrain /animsil /animtattoo  /animsmoking /animsniper /animspray /animstrip");
	SendClientMessage(playerid, COLOR_GREEN,"[INFO:] /animbath /animswat /animsweet /animswim /animsword /animtank /animtruck /animuzi  /animvan /animvending");
	SendClientMessage(playerid, COLOR_GREEN,"[INFO:] /animacje3");
	return 1;
}

dcmd_animacje3(playerid, params[])
{
	#pragma unused params
	SendClientMessage(playerid, COLOR_GREEN,"[INFO:] /animped /dance /handsup /animclothes /animcoach /animcolt /animcopa /animcod /animcrack");
	SendClientMessage(playerid, COLOR_GREEN,"[INFO:] /animairport /animat /animbar /animball /animfire /animbeach");
	SendClientMessage(playerid, COLOR_GREEN,"[INFO:] /animbp /animinf /animbiked /animbh /animfood /animbikelp /animms /animbikes /animcar");
	SendClientMessage(playerid, COLOR_GREEN,"[INFO:] /animbikev /animbmx /animbikedbz /animchase /animbox /animbomber /animbsp /animcamera ");
	SendClientMessage(playerid, COLOR_GREEN,"[INFO:] /animgym /animpara /animgangs /animlookers /animcarchat /animcasino /animbuddy /animbus");
	SendClientMessage(playerid, COLOR_GREEN,"[INFO:] /animcarry /animintshop /animjst /animkart /animkissing /animknife /animlapdan /animdend");
	SendClientMessage(playerid, COLOR_GREEN,"[INFO:] /animmedic /animmtb /animmusc /animotb /animnevada /animpark /animsaw /animchoppa");
	SendClientMessage(playerid, COLOR_GREEN,"[INFO:] /animway /animweap");
	return 1;
}

dcmd_gotoxyz(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] < 1)
		return 0;

	new Float:Xpos, Float:Ypos, Float:Zpos;
	if(sscanf(params, "fff",Xpos,Ypos,Zpos))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /gotoxyz [x] [y] [z]");
		return 1;
	}
	SetPlayerToPos(playerid,Xpos,Ypos,Zpos);
	return 1;
}

dcmd_loginonoff(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;

	if(gLoginOn == 1)
	{
		SendClientMessage(playerid, COLOR_GREEN, "[INFO:] Logowanie zosta³o wy³¹czone !");
		gLoginOn = 0;
	}
	else
	{
		SendClientMessage(playerid, COLOR_GREEN, "[INFO:] Logowanie zosta³o w³¹czone !");
		gLoginOn = 1;
	}
	return 1;
}

dcmd_abizproducts(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] < 4)
		return 0;

	new id, amount;
	if(sscanf(params, "dd", id, amount))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /abizproducts [businessid] [amount]");
		return 1;
	}
	if(amount < 0 && amount > 200)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Iloœæ produktów nie mo¿e byæ mniejsza od 0 i wiêksza od 200");
		return 1;
	}
	if(id < 0 || id > sizeof(Businesses))
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Business ID out of bounds");
		return 1;
	}
	Businesses[id][Products] = amount;
	SaveBizData( id, "Products");
	new string[128];
	format(string, sizeof(string), "[INFO:] Business id: %d products set to: %d", id, amount);
	SendClientMessage(playerid, COLOR_ORANGE, string);
	return 1;
}

dcmd_gstl1pos(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] < 4)
		return 0;

	new id;
	new Float:px, Float:py, Float:pz;
	if(sscanf(params, "dfff", id, px, py, pz))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /gstl1pos [id] [x] [y] [z]");
		return 1;
	}
	new string[128];
	GasStations[id][Pos3dTextX] = px;
	GasStations[id][Pos3dTextY] = py;
	GasStations[id][Pos3dTextZ] = pz;

	GasStations[id][Pos3dTextX2] = px;
	GasStations[id][Pos3dTextY2] = py;
	GasStations[id][Pos3dTextZ2] = pz + 0.6;

	GasStations[id][Pos3dTextX3] = px;
	GasStations[id][Pos3dTextY3] = py;
	GasStations[id][Pos3dTextZ3] = pz + 1.2;

	DestroyDynamic3DTextLabel(GasStations[id][GS3dTextLabel]);
	DestroyDynamic3DTextLabel(GasStations[id][GS3dTextLabel2]);
	DestroyDynamic3DTextLabel(GasStations[id][GS3dTextLabel3]);

	format(string, sizeof(string), "Benzyna: $%d", GasStations[id][PetrolPrice]);
	GasStations[id][GS3dTextLabel] = CreateDynamic3DTextLabel(string, COLOR_GREEN, GasStations[id][Pos3dTextX], GasStations[id][Pos3dTextY], GasStations[id][Pos3dTextZ], 50.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID);
	format(string, sizeof(string), "Diesel: $%d", GasStations[id][OilPrice]);
	GasStations[id][GS3dTextLabel2] = CreateDynamic3DTextLabel(string, COLOR_GREEN, GasStations[id][Pos3dTextX2], GasStations[id][Pos3dTextY2], GasStations[id][Pos3dTextZ2], 50.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID);
	format(string, sizeof(string), "Gaz: $%d", GasStations[id][GasPrice]);
	GasStations[id][GS3dTextLabel3] = CreateDynamic3DTextLabel(string, COLOR_GREEN, GasStations[id][Pos3dTextX3], GasStations[id][Pos3dTextY3], GasStations[id][Pos3dTextZ3], 50.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID);

	return 1;
}

dcmd_gstl2pos(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] < 4)
		return 0;

	new id;
	new Float:px, Float:py, Float:pz;
	if(sscanf(params, "dfff", id, px, py, pz))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /gstl2pos [id] [x] [y] [z]");
		return 1;
	}
	new string[128];
	GasStations[id][Pos3dTextX4] = px;
	GasStations[id][Pos3dTextY4] = py;
	GasStations[id][Pos3dTextZ4] = pz;

	DestroyDynamic3DTextLabel(GasStations[id][GS3dTextLabel4]);

	format(string, sizeof(string), "Nr stacji: %d", id+1);
	GasStations[id][GS3dTextLabel4] = CreateDynamic3DTextLabel(string, COLOR_GREEN, GasStations[id][Pos3dTextX4], GasStations[id][Pos3dTextY4], GasStations[id][Pos3dTextZ4], 50.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID);

	return 1;
}

dcmd_gspos(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] < 4)
		return 0;
	new id;

	if(sscanf(params, "d", id))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /gspos [id] [x] [y] [z]");
		return 1;
	}
	
	GetPlayerPos(playerid, GasStations[id][GSposX], GasStations[id][GSposY], GasStations[id][GSposZ]);
	SaveGasStations();
	
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] station pos changed");
	
	return 1;
}

dcmd_cdp(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new id, model;
	if(sscanf(params, "d", model))
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] /cdp [model]");
		return 1;
	}
	new Float:px, Float:py, Float:pz;
	GetPlayerPos(playerid, px,py,pz);
	id = CreateDynamicPickup(model, 1, px, py, pz, -1, -1, -1, 100.0);
	new string[128];
	format(string, sizeof(string), "[INFO:] Pickup created, id: %d", id);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	return 1;
}

dcmd_menubroni(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pJob] != 1)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ dilerem broni !");
		return 1;
	}
	if(gPlayerData[playerid][pFaction] == 255)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ cz³onkiem gangu !");
		return 1;
	}
	if(DynamicFactions[gPlayerData[playerid][pFaction]][fType] != 3)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ cz³onkiem gangu !");
		return 1;
	}
	if(!DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryEnabled])
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie ma aktywnej fabryki !");
		return 1;
	}
	if(!IsPlayerInDynamicCP(playerid, DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryCPPartTakeID]))
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w punkcie skladu czêœci !");
		return 1;
	}
	ShowPlayerDialog(playerid, DIALOG_WMENU_1, DIALOG_STYLE_LIST, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_MAIN_TXT, "Wybierz", "Anuluj" );
	return 1;
}

dcmd_fillbtable(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new string[128];
	for(new i = 0; i < sizeof(Building); i++)
	{
		format(string, sizeof(string), "INSERT INTO `samp_buildings` (`BuildingName`) VALUES ('Brak') ");
		wp_mysql_query(string, SAVE, playerid, db_con2);
	}
	return 1;
}

dcmd_ustawwiadomosc(playerid, params[])
{
	#pragma unused params
	/*if(gPlayerData[playerid][pFaction] != FACTIONID_SANNEWS && gPlayerData[playerid][pFaction] != FACTIONID_POLICE)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ dziennikarzem");
		return 1;
	}
	
	new lmId, lMcontent[255];
	
	if(sscanf(params, "ds[254]", lmId, lMcontent))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /ustawwiadomosc [id wiadomosci (0-9)] [treœæ]");
		return 1;
	}
	
	format(lMcontent, sizeof(lMcontent), "%s%s", "SAN NEWS: ", lMcontent);
	
	format(gSanNewsMsg[lmId], 255, lMcontent);
	
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ustawi³eœ now¹ wiadomoœæ");
	*/
	return 1;
}

dcmd_wyczyscwiadomosc(playerid, params[])
{
	#pragma unused params
	
	/*if(gPlayerData[playerid][pFaction] != FACTIONID_SANNEWS && gPlayerData[playerid][pFaction] != FACTIONID_POLICE)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ dziennikarzem");
		return 1;
	}
	new lmId;
	if(sscanf(params, "d", lmId))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /wyczyscwiadomosc [id wiadomosci (0-9)]");
		return 1;
	}	
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Wyczyœci³eœ wiadomoœæ");
	*/
	return 1;
}

/* Set temporary CP of take parts in illegal faction */

/* Need fix ! */

// dcmd_setwfactorytakecp(playerid, params[])
// {
	// #pragma unused params
	// if(gPlayerData[playerid][pAdmin] != 5)
		// return 0;
	// new Float:px, Float:py, Float:pz;
	// GetPlayerPos(playerid, px,py,pz);
	// DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryCPPartTakeX] = px;
	// DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryCPPartTakeY] = py;
	// DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryCPPartTakeZ] = pz;
	// CreateDynamicCP(DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryCPPartTakeX], DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryCPPartTakeY], DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryCPPartTakeZ], 10.0);

	// return 1;
// }

/* Set temporary CP of parts setup 1 in illegal faction */
/* Need fix ! */
// dcmd_setwfactorysetupcp1(playerid, params[])
// {
	// #pragma unused params
	// if(gPlayerData[playerid][pAdmin] != 5)
		// return 0;
	// new Float:px, Float:py, Float:pz;
	// GetPlayerPos(playerid, px, py, pz);
	// DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryCPPartSetup1X] = px;
	// DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryCPPartSetup1Y] = py;
	// DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryCPPartSetup1Z] = pz;
	// CreateDynamicPickup( 1239, 1, px, py, pz);

	// return 1;
// }

/* Remove factory building( and data ) if exists */
dcmd_rfactory(playerid, params[])
{
	#pragma unused params
	if( gPlayerData[playerid][pAdmin] < 4 )
		return 0;
	for( new i = 0; i < sizeof(DynamicFactions); i++ )
	{
		if( PlayerToPoint( 10.0, playerid, DynamicFactions[i][WFactoryCentrePosX],DynamicFactions[i][WFactoryCentrePosY], DynamicFactions[i][WFactoryCentrePosZ] ) )
		{
			if( DynamicFactions[i][WFactoryBurning] )
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ta baza zosta³a ju¿ podpalona !");
				return 1;
			}
			if( !DynamicFactions[i][WFactoryEnabled] )
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Fabryka nie istnieje !");
				return 1;
			}
			DynamicFactions[i][WFactoryEnabled] = 0;
			DynamicFactions[i][WFactoryBurning] = 1;
			DestroyFactory( i, gPlayerData[playerid][pFaction] );
			SendClientMessage( playerid, COLOR_GREEN, "[INFO:] Podpali³eœ fabryke !");
			return 1;
		}
	}
	SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Musisz byæ wewn¹trz fabryki aby j¹ podpaliæ !");
	return 1;
}

dcmd_savetune(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	for(new i = 0; i < sizeof(gVehData); i++)
	{
		SaveVehData(i, "VehSaveTune");
	}
	printf("[WARNING:] Saving tune data... by %s", GetPlayerNameEx(playerid));
	return 1;
}

dcmd_unmodcar(playerid, params[])
{
	if(!gPlayerData[playerid][pAdmin])
	{
		return 0;
	}
	
	new vehid;
	
	if(sscanf(params, "d", vehid))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /unmodcar [vehid]");
		return 1;
	}
	
	UnmodVehicle(vehid);
	
	printf("[WARNING:] Veh id %d unmoded by %s", vehid, GetPlayerNameEx(playerid));
	return 1;
}

dcmd_fabryka(playerid, params[])
{
	#pragma unused params
	
	new string[128];
	
	if( gPlayerData[playerid][pFaction] == 255 )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ cz³onkiem gangu !" );
		return 1;
	}
	
	if( DynamicFactions[gPlayerData[playerid][pFaction]][fType] != 3 )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ cz³onkiem gangu !" );
		return 1;
	}
	
	if( gPlayerData[playerid][pRank] != 1 )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ liderem gangu !" );
		return 1;
	}
	
	new fID = gPlayerData[playerid][pFaction];
	
	if( DynamicFactions[fID][WFactoryJustBought] )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Ju¿ zakupi³eœ fabryke !" );
		return 1;
	}
	
	if(DynamicFactions[fID][WFactoryEnabled] || DynamicFactions[fID][WFactoryBurning] != 0)
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Aktualnie mo¿liwe jest postawienie tylko jednej fabryki !");
		return 1;
	}
	
	if(gPlayerData[playerid][pBank] < WFACTORY_COST)
	{
		format(string, sizeof(string), "[INFO:] Masz za ma³o pieniêdzy na swoim koncie. Wymagana kwota: %d", WFACTORY_COST);
		SendClientMessage(playerid, COLOR_ORANGE, string);
		return 1;
	}
	
	format(string, sizeof(string), "Czy chcesz postawiæ fabryke broni za $%d ?\nFabryka zostanie zbudowana w ci¹gu nocy bezpoœrednio w miejscu w którym siê znajdujesz.", WFACTORY_COST);
	ShowPlayerDialog(playerid, DIALOG_FACTORY_BUILD, DIALOG_STYLE_MSGBOX, "Fabryka", string, "Tak", "Nie");
	
	return 1;
}

dcmd_fillbuildingstable(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new string[128];
	for(new i = 0; i < 150; i++)
	{
		format(string, sizeof(string), "INSERT INTO `samp_buildings` (`Locked`) VALUES ('0') ");
		wp_mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
	}
	return 1;
}

dcmd_odczepnaczepe(playerid, params[])
{
	#pragma unused params
	DetachTrailerFromVehicle(GetPlayerVehicleID(playerid));
	return 1;
}

dcmd_skladaj(playerid, params[])
{
	#pragma unused params
	if( gPlayerData[playerid][pJob] != 1 && gPlayerData[playerid][pJob] != 22 )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ dilerem broni ani pracownikiem fabryki !" );
		return 1;
	}
	if( !gPlayerData[playerid][pPartType] )
	{
		ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, WF_ASSEMBLE_NOT_SLCTED, DIALOG_INFO_EXIT, "" );
		return 1;
	}
	if( gPlayerData[playerid][pMountingW] )
	{
		ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, WF_ASSEMBLE_ALREADY, DIALOG_INFO_EXIT, "" );
		return 1;
	}
	new string[256];
	switch( gPlayerData[playerid][pPartType] )
	{
		case WF_WEAPON:
		{
			if( ( gPlayerData[playerid][pJob] == 1 &&
				!IsPlayerInDynamicCP( playerid, DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryCPPartSetup1ID] ) &&
				!IsPlayerInDynamicCP( playerid, DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryCPPartSetup2ID] ) ) ||
				( gPlayerData[playerid][pJob] == 22 &&
				!IsPlayerInDynamicCP( playerid, WFactoryLegal[WFactoryCPPartSetup1ID] ) &&
				!IsPlayerInDynamicCP( playerid, WFactoryLegal[WFactoryCPPartSetup2ID] ) &&
				!IsPlayerInDynamicCP( playerid, WFactoryLegal[WFactoryCPPartSetup3ID] ) &&
				!IsPlayerInDynamicCP( playerid, WFactoryLegal[WFactoryCPPartSetup4ID] ) &&
				!IsPlayerInDynamicCP( playerid, WFactoryLegal[WFactoryCPPartSetup5ID] ) &&
				!IsPlayerInDynamicCP( playerid, WFactoryLegal[WFactoryCPPartSetup6ID] ) ) )
			{
				ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, WF_ASSEMBLE_NOT_WCP, DIALOG_INFO_EXIT, "" );
				return 1;
			}
			switch( gPlayerData[playerid][pPartItem] )
			{
				case WF_9MM,
						WF_9MMSIL,
						WF_MICROSMG,
						WF_DESEAGLE,
						WF_TEC9:
				{
					if( gPlayerData[playerid][pMountsPasses] != WF_LPT && gPlayerData[playerid][pMountsPasses] != 0 )
					{
						ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, WF_ASSEMBLE_ALREADY, DIALOG_INFO_EXIT, "" );
						return 1;
					}
					else
					{
						format(string, sizeof(string), "[MOUNT:] Started - WEAPON LIGHT by %s", GetPlayerNameEx(playerid));
						WFactoryLog(string);
						gPlayerData[playerid][pMountingW] = 1;
						gPlayerData[playerid][pMountsPasses] = WF_LPT;
					}
				}
				case WF_MP5,
						WF_SHOTGUN,
						WF_AK47,
						WF_M4,
						WF_RIFLE,
						WF_SRIFLE,
						WF_SCHARGE:
				{
					if( gPlayerData[playerid][pMountsPasses] != WF_HPT && gPlayerData[playerid][pMountsPasses] != 0 )
					{
						ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, WF_ASSEMBLE_ALREADY, DIALOG_INFO_EXIT, "" );
						return 1;
					}
					else
					{
						format(string, sizeof(string), "[MOUNT:] Started - WEAPON HEAVY by %s", GetPlayerNameEx(playerid));
						WFactoryLog(string);
						gPlayerData[playerid][pMountingW] = 1;
						gPlayerData[playerid][pMountsPasses] = WF_HPT;
					}
				}
			}
		}
		case WF_PART:
		{
			if( ( gPlayerData[playerid][pJob] == 1 &&
				!IsPlayerInDynamicCP( playerid, DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryCPPartSetup1ID] ) &&
				!IsPlayerInDynamicCP( playerid, DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryCPPartSetup2ID] ) ) ||
				( gPlayerData[playerid][pJob] == 22 &&
				!IsPlayerInDynamicCP( playerid, WFactoryLegal[WFactoryCPPartSetup1ID] ) &&
				!IsPlayerInDynamicCP( playerid, WFactoryLegal[WFactoryCPPartSetup2ID] ) &&
				!IsPlayerInDynamicCP( playerid, WFactoryLegal[WFactoryCPPartSetup3ID] ) &&
				!IsPlayerInDynamicCP( playerid, WFactoryLegal[WFactoryCPPartSetup4ID] ) &&
				!IsPlayerInDynamicCP( playerid, WFactoryLegal[WFactoryCPPartSetup5ID] ) &&
				!IsPlayerInDynamicCP( playerid, WFactoryLegal[WFactoryCPPartSetup6ID] ) ) )
			{
				ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, WF_ASSEMBLE_NOT_WCP, DIALOG_INFO_EXIT, "" );
				return 1;
			}
			switch( gPlayerData[playerid][pPartItem] )
			{
				case WF_PISTOLPART1,
						WF_PISTOLPART2,
						WF_PISTOLPART3,
						WF_PISTOLPART4,
						WF_PISTOLPART5,
						WF_PISTOLPART6:
				{
					if( gPlayerData[playerid][pMountsPasses] != WF_LSPT && gPlayerData[playerid][pMountsPasses] != 0 )
					{
						ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, WF_ASSEMBLE_ALREADY, DIALOG_INFO_EXIT, "" );
						return 1;
					}
					else
					{
						format(string, sizeof(string), "[MOUNT:] Started - PART LIGHT by %s", GetPlayerNameEx(playerid));
						WFactoryLog(string);
						gPlayerData[playerid][pMountingW] = 1;
						gPlayerData[playerid][pMountsPasses] = WF_LSPT;
					}
				}
				case WF_RIFLEPART1,
						WF_RIFLEPART2,
						WF_RIFLEPART3,
						WF_RIFLEPART4,
						WF_RIFLEPART5,
						WF_RIFLEPART6,
						WF_RIFLEPART7:
				{
					if( gPlayerData[playerid][pMountsPasses] != WF_HSPT && gPlayerData[playerid][pMountsPasses] != 0 )
					{
						ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, WF_ASSEMBLE_ALREADY, DIALOG_INFO_EXIT, "" );
						return 1;
					}
					else
					{
						format(string, sizeof(string), "[MOUNT:] Started - PART HEAVY by %s", GetPlayerNameEx(playerid));
						WFactoryLog(string);
						gPlayerData[playerid][pMountingW] = 1;
						gPlayerData[playerid][pMountsPasses] = WF_HSPT;
					}
				}
			}
		}
		case WF_AMMO:
		{
			if( ( gPlayerData[playerid][pJob] == 1 &&
				!IsPlayerInDynamicCP( playerid, DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryCPPartSetup1ID] ) &&
				!IsPlayerInDynamicCP( playerid, DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryCPPartSetup2ID] ) ) ||
				( gPlayerData[playerid][pJob] == 22 &&
				!IsPlayerInDynamicCP( playerid, WFactoryLegal[WFactoryCPAmmoSetup1ID] ) &&
				!IsPlayerInDynamicCP( playerid, WFactoryLegal[WFactoryCPAmmoSetup2ID] ) &&
				!IsPlayerInDynamicCP( playerid, WFactoryLegal[WFactoryCPAmmoSetup3ID] ) &&
				!IsPlayerInDynamicCP( playerid, WFactoryLegal[WFactoryCPAmmoSetup4ID] ) &&
				!IsPlayerInDynamicCP( playerid, WFactoryLegal[WFactoryCPAmmoSetup5ID] ) &&
				!IsPlayerInDynamicCP( playerid, WFactoryLegal[WFactoryCPAmmoSetup6ID] ) ) )
			{
				ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, WF_ASSEMBLE_NOT_ACP, DIALOG_INFO_EXIT, "" );
				return 1;
			}
			switch( gPlayerData[playerid][pPartItem] )
			{
				case WF_9MMAMMO,
						WF_50AEAMMO,
						WF_BUCKSHOT,
						WF_762MMAMMO,
						WF_127MMAMMO,
						WF_KGP66MMAMMO,
						WF_NAPALM,
						WF_AMMOT:
				{
					if( gPlayerData[playerid][pMountsPasses] != 10 && gPlayerData[playerid][pMountsPasses] != 0 )
					{
						ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, WF_ASSEMBLE_ALREADY, DIALOG_INFO_EXIT, "" );
						return 1;
					}
					else
					{
						format(string, sizeof(string), "[MOUNT:] Started - AMMO by %s", GetPlayerNameEx(playerid));
						WFactoryLog(string);
						gPlayerData[playerid][pMountsPasses] = 10;
						gPlayerData[playerid][pMountingW] = 1;
					}
				}
			}
		}
	}
	defer PartsMount(playerid);
	return 1;
}

dcmd_radiosv( playerid, params[] )
{
	new volume, string[128];
	if( sscanf( params, "d", volume ) )
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /radiov [g³oœnoœæ (0-100)]");
		return 1;
	}
	if( !IsPlayerInAnyVehicle(playerid) )
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w pojeŸdzie !");
		return 1;
	}
	if( volume > 100 || volume < 0)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Zakres g³oœnoœci: 0-100");
		return 1;
	}
	new vehID = GetPlayerVehicleID(playerid);
	if( !gVehData[vehID-1][RadioOn] )
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Radio nie jest w³¹czone !");
		return 1;
	}
	ChangeCarRadioVolume(vehID, volume);
	format( string, sizeof(string), "[INFO:] G³oœnoœæ radia: %d%%", volume );
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	return 1;
}

dcmd_ugasfab( playerid, params[] )
{
	#pragma unused params
	if( gPlayerData[playerid][pFaction] == 255 )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie nale¿ysz do ¿adnej frakcji !");
		return 1;
	}
	if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fType] != 1 && DynamicFactions[ gPlayerData[playerid][pFaction] ][fType] != 3)
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Ta frakcja nie mo¿e ugaszaæ fabryk !");
		return 1;
	}
	new fID = gPlayerData[playerid][pFaction];
	if( !DynamicFactions[fID][WFactoryBurning] )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Fabryka nie zosta³a podpalona !" );
		return 1;
	}
	foreach(Player, i )
	{
		if( i == playerid)
			continue;
		if( PlayerToPoint( 45.0, i, DynamicFactions[fID][WFactoryCentrePosX],DynamicFactions[fID][WFactoryCentrePosY], DynamicFactions[fID][WFactoryCentrePosZ] ) && ( DynamicFactions[ gPlayerData[i][pFaction] ][fType] == 1 || DynamicFactions[ gPlayerData[i][pFaction] ][fType] ) && gPlayerData[i][pFaction] != gPlayerData[playerid][pFaction] )
		{
			SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz ugasiæ fabryki poniewa¿ w pobli¿u znajduje siê policja" );
			return 1;
		}
	}
	GetPlayerHealth(playerid, gPlayerData[playerid][pHP]);
	new succeed = 1 + random(2);
	if( succeed )
	{
		DynamicFactions[fID][WFactoryBurning] = 0;
		DynamicFactions[fID][WFactoryEnabled] = 1;
		SendClientMessage( playerid, COLOR_GREEN, "[INFO:] Ugasi³eœ fabryke !");		
		gPlayerData[playerid][pHP] -= 15.0;
		SetPlayerHealth( playerid, gPlayerData[playerid][pHP] );
		SaveFData(fID, "WFactoryBurning");
		SaveFData(fID, "WFactoryEnabled");
	}
	else
	{
		SendClientMessage( playerid, COLOR_GREEN, "[INFO:] Nie uda³o ci siê ugasiæ fabryki !");
		gPlayerData[playerid][pHP] -= 25.0;
		SetPlayerHealth( playerid, gPlayerData[playerid][pHP] );
	}
	return 1;
}

dcmd_podpalfab( playerid, params[] )
{
	#pragma unused params
	if( gPlayerData[playerid][pFaction] == 255 )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie nale¿ysz do ¿adnej frakcji !");
		return 1;
	}
	if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fType] != 1 && DynamicFactions[ gPlayerData[playerid][pFaction] ][fType] != 3)
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Ta frakcja nie mo¿e podpalaæ fabryk !");
		return 1;
	}
	for( new i = 0; i < sizeof(DynamicFactions); i++ )
	{
		if( PlayerToPoint( 10.0, playerid, DynamicFactions[i][WFactoryCentrePosX],DynamicFactions[i][WFactoryCentrePosY], DynamicFactions[i][WFactoryCentrePosZ] ) )
		{
			if( DynamicFactions[i][WFactoryBurning] )
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ta baza zosta³a ju¿ podpalona !");
				return 1;
			}
			if( !DynamicFactions[i][WFactoryEnabled] )
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Fabryka nie istnieje !");
				return 1;
			}
			for( new j = 0; j < CUSTOM_MAX_PLAYERS; j++ )
			{
				if( j == playerid )
					continue;
				if( PlayerToPoint( 35.0, j, DynamicFactions[i][WFactoryCentrePosX],DynamicFactions[i][WFactoryCentrePosY], DynamicFactions[i][WFactoryCentrePosZ] ) && gPlayerData[j][pFaction] == i)
				{
					SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz podpaliæ fabryki. W pobli¿u znajduj¹ siê cz³onkowie gangu !");
					return 1;
				}
			}
			DynamicFactions[i][WFactoryEnabled] = 0;
			DynamicFactions[i][WFactoryBurning] = 1;
			defer DestroyFactory( i, gPlayerData[playerid][pFaction] );
			SaveFData( i, "WFactoryEnabled" );
			SaveFData( i, "WFactoryBurning" );
			SendClientMessage( playerid, COLOR_GREEN, "[INFO:] Podpali³eœ fabryke !");
			return 1;
		}
	}
	SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Musisz byæ wewn¹trz fabryki aby j¹ podpaliæ !");
	return 1;
}

dcmd_pobierzczesci(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pJob] != 22 )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ pracownikiem fabryki broni !");
		return 1;
	}
	if( !IsPlayerInDynamicCP( playerid, WFactoryLegal[WFactoryCPPartTakeID] ) )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w punkcie poboru czêœci !");
		return 1;
	}
	if( gPlayerData[playerid][pPartType] != 0 )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Posiadasz ju¿ wyznaczony element do montowania. Udaj siê na jedno ze stanowis monta¿owych i u¿yj komendy /skladaj");
		return 1;
	}
	if( !SelectFactoryWeapon(playerid) )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Niestety aktualnie brakuje czêœci w magazynie, spróbuj jeszcze raz za chwile");
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Jeœli problem bêdzie siê powtarza³ wróæ nastêpnego dnia");
	}
	else
	{
		new slot, enough;
		switch( gPlayerData[playerid][pPartType] )
		{
			case WF_WEAPON:
			{
				if(gPlayerData[playerid][pPartItem] == WF_9MM) // 9mm
				{
					if( PlayerFreeSlotCount( playerid ) < 5 )
					{
						gPlayerData[playerid][pPartType] = 0;
						SavePlayerData( playerid, "PartType" );
						ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_3_NO_SPACE_TXT, "Wróæ", "" );
						return 1;
					}
					#define LP0COUNT1 1
					#define LP0COUNT2 1
					#define LP0COUNT3 1
					#define LP0COUNT4 1
					#define LP0COUNT5 1
					if ( !( slot = PHaveItem( playerid, 1, 48 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 48, 0, 0, 0, 0, "Puste", LP0COUNT1 );
						WFactoryLegalLight[WFactoryPistolPart1] -= LP0COUNT1;
						SaveWFactoryData( "WFactoryPistolPart1" );
					}
					else
					{
						enough = LP0COUNT1 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 48, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalLight[WFactoryPistolPart1] -= enough;
							SaveWFactoryData( "WFactoryPistolPart1" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 49 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 49, 0, 0, 0, 0, "Puste", LP0COUNT2 );
						WFactoryLegalLight[WFactoryPistolPart2] -= LP0COUNT2;
						SaveWFactoryData( "WFactoryPistolPart2" );
					}
					else
					{
						enough = LP0COUNT2 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 49, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalLight[WFactoryPistolPart2] -= enough;
							SaveWFactoryData( "WFactoryPistolPart2" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 50 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 50, 0, 0, 0, 0, "Puste", LP0COUNT3 );
						WFactoryLegalLight[WFactoryPistolPart3] -= LP0COUNT3;
						SaveWFactoryData( "WFactoryPistolPart3" );
					}
					else
					{
						enough = LP0COUNT3 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 50, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalLight[WFactoryPistolPart3] -= enough;
							SaveWFactoryData( "WFactoryPistolPart3" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 51 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 51, 0, 0, 0, 0, "Puste", LP0COUNT4 );
						WFactoryLegalLight[WFactoryPistolPart4] -= LP0COUNT4;
						SaveWFactoryData( "WFactoryPistolPart4" );
					}
					else
					{
						enough = LP0COUNT4 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 51, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalLight[WFactoryPistolPart4] -= enough;
							SaveWFactoryData( "WFactoryPistolPart4" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 52 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 52, 0, 0, 0, 0, "Puste", LP0COUNT5 );
						WFactoryLegalLight[WFactoryPistolPart5] -= LP0COUNT5;
						SaveWFactoryData( "WFactoryPistolPart5" );
					}
					else
					{
						enough = LP0COUNT5 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 52, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalLight[WFactoryPistolPart5] -= enough;
							SaveWFactoryData( "WFactoryPistolPart5" );
						}
					}
					gPlayerData[playerid][pMountsLeft] = 5;
					gPlayerData[playerid][pMountsPasses] = WF_LPT;
					SavePlayerData( playerid, "MountsLeft" );
				}
				else if(gPlayerData[playerid][pPartItem] == WF_9MMSIL) // 9mm tlumik
				{
					if( PlayerFreeSlotCount( playerid ) < 6 )
					{
						gPlayerData[playerid][pPartType] = 0;
						SavePlayerData( playerid, "PartType" );
						ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_3_NO_SPACE_TXT, "Wróæ", "" );
						return 1;
					}
					#define LP1COUNT1 1
					#define LP1COUNT2 1
					#define LP1COUNT3 1
					#define LP1COUNT4 1
					#define LP1COUNT5 1
					#define LP1COUNT6 1
					if ( !( slot = PHaveItem( playerid, 1, 48 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 48, 0, 0, 0, 0, "Puste", LP1COUNT1 );
						WFactoryLegalLight[WFactoryPistolPart1] -= LP1COUNT1;
						SaveWFactoryData( "WFactoryPistolPart1" );
					}
					else
					{
						enough = LP1COUNT1 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 48, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalLight[WFactoryPistolPart1] -= enough;
							SaveWFactoryData( "WFactoryPistolPart1" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 49 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 49, 0, 0, 0, 0, "Puste", LP1COUNT2 );
						WFactoryLegalLight[WFactoryPistolPart2] -= LP1COUNT2;
						SaveWFactoryData( "WFactoryPistolPart2" );
					}
					else
					{
						enough = LP1COUNT2 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 49, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalLight[WFactoryPistolPart2] -= enough;
							SaveWFactoryData( "WFactoryPistolPart2" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 50 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 50, 0, 0, 0, 0, "Puste", LP1COUNT3 );
						WFactoryLegalLight[WFactoryPistolPart3] -= LP1COUNT3;
						SaveWFactoryData( "WFactoryPistolPart3" );
					}
					else
					{
						enough = LP1COUNT3 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 50, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalLight[WFactoryPistolPart3] -= enough;
							SaveWFactoryData( "WFactoryPistolPart3" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 51 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 51, 0, 0, 0, 0, "Puste", LP1COUNT4 );
						WFactoryLegalLight[WFactoryPistolPart4] -= LP1COUNT4;
						SaveWFactoryData( "WFactoryPistolPart4" );
					}
					else
					{
						enough = LP1COUNT4 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 51, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalLight[WFactoryPistolPart4] -= enough;
							SaveWFactoryData( "WFactoryPistolPart4" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 52 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 52, 0, 0, 0, 0, "Puste", LP1COUNT5 );
						WFactoryLegalLight[WFactoryPistolPart5] -= LP1COUNT5;
						SaveWFactoryData( "WFactoryPistolPart5" );
					}
					else
					{
						enough = LP1COUNT5 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 52, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalLight[WFactoryPistolPart5] -= enough;
							SaveWFactoryData( "WFactoryPistolPart5" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 59 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 59, 0, 0, 0, 0, "Puste", LP1COUNT6 );
						WFactoryLegalLight[WFactoryPistolPart6] -= LP1COUNT6;
						SaveWFactoryData( "WFactoryPistolPart6" );
					}
					else
					{
						enough = LP1COUNT6 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 59, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalLight[WFactoryPistolPart6] -= enough;
							SaveWFactoryData( "WFactoryPistolPart6" );
						}
					}
					gPlayerData[playerid][pMountsLeft] = 6;
					gPlayerData[playerid][pMountsPasses] = WF_LPT;
					SavePlayerData( playerid, "MountsLeft" );
				}
				else if(gPlayerData[playerid][pPartItem] == WF_DESEAGLE) // desert eagle
				{
					if( PlayerFreeSlotCount( playerid ) < 6 )
					{
						gPlayerData[playerid][pPartType] = 0;
						SavePlayerData( playerid, "PartType" );
						ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_3_NO_SPACE_TXT, "Wróæ", "" );
						return 1;
					}
					#define LP2COUNT1 1
					#define LP2COUNT2 2
					#define LP2COUNT3 2
					#define LP2COUNT4 2
					#define LP2COUNT5 1
					#define LP2COUNT6 1
					if ( !(slot = PHaveItem( playerid, 1, 87 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 87, 0, 0, 0, 0, "Puste", LP2COUNT6 );
						WFactoryLegalLight[WFactoryDesEaglePart] -= LP2COUNT6;
						SaveWFactoryData( "WFactoryDesEaglePart" );
					}
					else
					{
						enough = LP2COUNT6 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 87, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalLight[WFactoryDesEaglePart] -= enough;
							SaveWFactoryData( "WFactoryDesEaglePart" );
						}
					}
					if ( !(slot = PHaveItem( playerid, 1, 48 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 48, 0, 0, 0, 0, "Puste", LP2COUNT1 );
						WFactoryLegalLight[WFactoryPistolPart1] -= LP2COUNT1;
						SaveWFactoryData( "WFactoryPistolPart1" );
					}
					else
					{
						enough = LP2COUNT1 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 48, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalLight[WFactoryPistolPart1] -= enough;
							SaveWFactoryData( "WFactoryPistolPart1" );
						}
					}
					if ( !(slot = PHaveItem( playerid, 1, 49 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 49, 0, 0, 0, 0, "Puste", LP2COUNT2 );
						WFactoryLegalLight[WFactoryPistolPart2] -= LP2COUNT2;
						SaveWFactoryData( "WFactoryPistolPart2" );
					}
					else
					{
						enough = LP2COUNT2 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 49, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalLight[WFactoryPistolPart2] -= enough;
							SaveWFactoryData( "WFactoryPistolPart2" );
						}
					}
					if ( !(slot = PHaveItem( playerid, 1, 50 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 50, 0, 0, 0, 0, "Puste", LP2COUNT3 );
						WFactoryLegalLight[WFactoryPistolPart3] -= LP2COUNT3;
						SaveWFactoryData( "WFactoryPistolPart3" );
					}
					else
					{
						enough = LP2COUNT3 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 50, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalLight[WFactoryPistolPart3] -= enough;
							SaveWFactoryData( "WFactoryPistolPart3" );
						}
					}
					if ( !(slot = PHaveItem( playerid, 1, 51 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 51, 0, 0, 0, 0, "Puste", LP2COUNT4 );
						WFactoryLegalLight[WFactoryPistolPart4] -= LP2COUNT4;
						SaveWFactoryData( "WFactoryPistolPart4" );
					}
					else
					{
						enough = LP2COUNT4 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 51, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalLight[WFactoryPistolPart4] -= enough;
							SaveWFactoryData( "WFactoryPistolPart4" );
						}
					}
					if ( !(slot = PHaveItem( playerid, 1, 52 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 52, 0, 0, 0, 0, "Puste", LP2COUNT5 );
						WFactoryLegalLight[WFactoryPistolPart5] -= LP2COUNT5;
						SaveWFactoryData( "WFactoryPistolPart5" );
					}
					else
					{
						enough = LP2COUNT5 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 51, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalLight[WFactoryPistolPart5] -= enough;
							SaveWFactoryData( "WFactoryPistolPart5" );
						}
					}
					gPlayerData[playerid][pMountsLeft] = 6;
					gPlayerData[playerid][pMountsPasses] = WF_LPT;
					SavePlayerData( playerid, "MountsLeft" );
				}
				else if(gPlayerData[playerid][pPartItem] == WF_SHOTGUN) // shotgun
				{
					if( PlayerFreeSlotCount( playerid ) < 7 )
					{
						gPlayerData[playerid][pPartType] = 0;
						SavePlayerData( playerid, "PartType" );
						ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_3_NO_SPACE_TXT, "Wróæ", "" );
						return 1;
					}
					#define LP3COUNT1 3
					#define LP3COUNT2 2
					#define LP3COUNT3 2
					#define LP3COUNT4 1
					#define LP3COUNT5 1
					#define LP3COUNT6 1
					#define LP3COUNT7 1
					if ( !( slot = PHaveItem( playerid, 1, 86 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 86, 0, 0, 0, 0, "Puste", LP3COUNT7 );
						WFactoryLegalHeavy[WFactoryShotPart] -= LP3COUNT7;
						SaveWFactoryData( "WFactoryShotPart" );
					}
					else
					{
						enough = LP3COUNT7 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 86, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalHeavy[WFactoryShotPart] -= enough;
							SaveWFactoryData( "WFactoryShotPart" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 53 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 53, 0, 0, 0, 0, "Puste", LP3COUNT1 );
						WFactoryLegalHeavy[WFactoryRiflePart1] -= LP3COUNT1;
						SaveWFactoryData( "WFactoryRiflePart1" );
					}
					else
					{
						enough = LP3COUNT1 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 53, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalHeavy[WFactoryRiflePart1] -= enough;
							SaveWFactoryData( "WFactoryRiflelPart1" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 54 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 54, 0, 0, 0, 0, "Puste", LP3COUNT2 );
						WFactoryLegalHeavy[WFactoryRiflePart2] -= LP3COUNT2;
						SaveWFactoryData( "WFactoryRiflePart2" );
					}
					else
					{
						enough = LP3COUNT2 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 54, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalHeavy[WFactoryRiflePart2] -= enough;
							SaveWFactoryData( "WFactoryRiflePart2" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 55 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 55, 0, 0, 0, 0, "Puste", LP3COUNT3 );
						WFactoryLegalHeavy[WFactoryRiflePart3] -= LP3COUNT3;
						SaveWFactoryData( "WFactoryRiflePart3" );
					}
					else
					{
						enough = LP3COUNT3 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 55, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalHeavy[WFactoryRiflePart3] -= enough;
							SaveWFactoryData( "WFactoryRiflelPart3" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 56 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 56, 0, 0, 0, 0, "Puste", LP3COUNT4 );
						WFactoryLegalHeavy[WFactoryRiflePart4] -= LP3COUNT4;
						SaveWFactoryData( "WFactoryRiflePart4" );
					}
					else
					{
						enough = LP3COUNT4 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 56, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalHeavy[WFactoryRiflePart4] -= enough;
							SaveWFactoryData( "WFactoryRiflelPart4" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 57 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 57, 0, 0, 0, 0, "Puste", LP3COUNT5 );
						WFactoryLegalHeavy[WFactoryRiflePart5] -= LP3COUNT5;
						SaveWFactoryData( "WFactoryRiflePart5" );
					}
					else
					{
						enough = LP3COUNT5 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 57, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalHeavy[WFactoryRiflePart5] -= enough;
							SaveWFactoryData( "WFactoryRiflelPart5" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 58 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 58, 0, 0, 0, 0, "Puste", LP3COUNT6 );
						WFactoryLegalHeavy[WFactoryRiflePart6] -= LP3COUNT6;
						SaveWFactoryData( "WFactoryRiflePart6" );
					}
					else
					{
						enough = LP3COUNT6 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 58, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalHeavy[WFactoryRiflePart6] -= enough;
							SaveWFactoryData( "WFactoryRiflelPart6" );
						}
					}
					gPlayerData[playerid][pMountsLeft] = 7;
					gPlayerData[playerid][pMountsPasses] = WF_HPT;
					SavePlayerData( playerid, "MountsLeft" );
				}
				else if(gPlayerData[playerid][pPartItem] == WF_MICROSMG) // micro smg
				{
					if( PlayerFreeSlotCount( playerid ) < 5 )
					{
						gPlayerData[playerid][pPartType] = 0;
						SavePlayerData( playerid, "PartType" );
						ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_3_NO_SPACE_TXT, "Wróæ", "" );
						return 1;
					}
					#define LP4COUNT1 4
					#define LP4COUNT2 4
					#define LP4COUNT3 4
					#define LP4COUNT4 1
					#define LP4COUNT5 1
					if ( !( slot = PHaveItem( playerid, 1, 48 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 48, 0, 0, 0, 0, "Puste", LP4COUNT1 );
						WFactoryLegalLight[WFactoryPistolPart1] -= LP4COUNT1;
						SaveWFactoryData( "WFactoryPistolPart1" );
					}
					else
					{
						enough = LP4COUNT1 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 48, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalLight[WFactoryPistolPart1] -= enough;
							SaveWFactoryData( "WFactoryPistolPart1" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 49 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 49, 0, 0, 0, 0, "Puste", LP4COUNT2 );
						WFactoryLegalLight[WFactoryPistolPart2] -= LP4COUNT2;
						SaveWFactoryData( "WFactoryPistolPart2" );
					}
					else
					{
						enough = LP4COUNT2 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 49, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalLight[WFactoryPistolPart2] -= enough;
							SaveWFactoryData( "WFactoryPistolPart2" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 50 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 50, 0, 0, 0, 0, "Puste", LP4COUNT3 );
						WFactoryLegalLight[WFactoryPistolPart3] -= LP4COUNT3;
						SaveWFactoryData( "WFactoryPistolPart3" );
					}
					else
					{
						enough = LP4COUNT3 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 50, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalLight[WFactoryPistolPart3] -= enough;
							SaveWFactoryData( "WFactoryPistolPart3" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 51 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 51, 0, 0, 0, 0, "Puste", LP4COUNT4 );
						WFactoryLegalLight[WFactoryPistolPart4] -= LP4COUNT4;
						SaveWFactoryData( "WFactoryPistolPart4" );
					}
					else
					{
						enough = LP4COUNT4 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 51, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalLight[WFactoryPistolPart4] -= enough;
							SaveWFactoryData( "WFactoryPistolPart4" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 52 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 52, 0, 0, 0, 0, "Puste", LP4COUNT5 );
						WFactoryLegalLight[WFactoryPistolPart5] -= LP4COUNT5;
						SaveWFactoryData( "WFactoryPistolPart5" );
					}
					else
					{
						enough = LP4COUNT5 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 52, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalLight[WFactoryPistolPart5] -= enough;
							SaveWFactoryData( "WFactoryPistolPart5" );
						}
					}
					gPlayerData[playerid][pMountsLeft] = 5;
					gPlayerData[playerid][pMountsPasses] = WF_LPT;
					SavePlayerData( playerid, "MountsLeft" );
				}
				else if(gPlayerData[playerid][pPartItem] == WF_MP5) // mp5
				{
					if( PlayerFreeSlotCount( playerid ) < 7 )
					{
						gPlayerData[playerid][pPartType] = 0;
						SavePlayerData( playerid, "PartType" );
						ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_3_NO_SPACE_TXT, "Wróæ", "" );
						return 1;
					}
					#define LP5COUNT1 2
					#define LP5COUNT2 2
					#define LP5COUNT3 1
					#define LP5COUNT4 1
					#define LP5COUNT5 1
					#define LP5COUNT6 1
					#define LP5COUNT7 1
					if ( !( slot = PHaveItem( playerid, 1, 83 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 83, 0, 0, 0, 0, "Puste", LP5COUNT7 );
						WFactoryLegalHeavy[WFactoryMP5Part] -= LP5COUNT7;
						SaveWFactoryData( "WFactoryMP5Part" );
					}
					else
					{
						enough = LP5COUNT7 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 83, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalHeavy[WFactoryMP5Part] -= enough;
							SaveWFactoryData( "WFactoryMP5Part" );
						}
					}
					if ( !(slot = PHaveItem( playerid, 1, 53 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 53, 0, 0, 0, 0, "Puste", LP5COUNT1 );
						WFactoryLegalHeavy[WFactoryRiflePart1] -= LP5COUNT1;
						SaveWFactoryData( "WFactoryRiflePart1" );
					}
					else
					{
						enough = LP5COUNT1 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 53, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalHeavy[WFactoryRiflePart1] -= enough;
							SaveWFactoryData( "WFactoryRiflelPart1" );
						}
					}
					if ( !(slot = PHaveItem( playerid, 1, 54 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 54, 0, 0, 0, 0, "Puste", LP5COUNT2 );
						WFactoryLegalHeavy[WFactoryRiflePart2] -= LP5COUNT2;
						SaveWFactoryData( "WFactoryRiflePart2" );
					}
					else
					{
						enough = LP5COUNT2 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 54, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalHeavy[WFactoryRiflePart2] -= enough;
							SaveWFactoryData( "WFactoryRiflelPart2" );
						}
					}
					if ( !(slot = PHaveItem( playerid, 1, 55 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 55, 0, 0, 0, 0, "Puste", LP5COUNT3 );
						WFactoryLegalHeavy[WFactoryRiflePart3] -= LP5COUNT3;
						SaveWFactoryData( "WFactoryRiflePart3" );
					}
					else
					{
						enough = LP5COUNT3 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 55, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalHeavy[WFactoryRiflePart3] -= enough;
							SaveWFactoryData( "WFactoryRiflelPart3" );
						}
					}
					if ( !(slot = PHaveItem( playerid, 1, 56 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 56, 0, 0, 0, 0, "Puste", LP5COUNT4 );
						WFactoryLegalHeavy[WFactoryRiflePart4] -= LP5COUNT4;
						SaveWFactoryData( "WFactoryRiflePart4" );
					}
					else
					{
						enough = LP5COUNT4 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 56, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalHeavy[WFactoryRiflePart4] -= enough;
							SaveWFactoryData( "WFactoryRiflelPart4" );
						}
					}
					if ( !(slot = PHaveItem( playerid, 1, 57 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 57, 0, 0, 0, 0, "Puste", LP5COUNT5 );
						WFactoryLegalHeavy[WFactoryRiflePart5] -= LP5COUNT5;
						SaveWFactoryData( "WFactoryRiflePart5" );
					}
					else
					{
						enough = LP5COUNT5 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 57, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalHeavy[WFactoryRiflePart5] -= enough;
							SaveWFactoryData( "WFactoryRiflelPart5" );
						}
					}
					if ( !(slot = PHaveItem( playerid, 1, 58 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 58, 0, 0, 0, 0, "Puste", LP5COUNT6 );
						WFactoryLegalHeavy[WFactoryRiflePart6] -= LP5COUNT6;
						SaveWFactoryData( "WFactoryRiflePart6" );
					}
					else
					{
						enough = LP5COUNT6 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 58, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalHeavy[WFactoryRiflePart6] -= enough;
							SaveWFactoryData( "WFactoryRiflelPart6" );
						}
					}
					gPlayerData[playerid][pMountsLeft] = 7;
					gPlayerData[playerid][pMountsPasses] = WF_HPT;
					SavePlayerData( playerid, "MountsLeft" );
				}
				else if(gPlayerData[playerid][pPartItem] == WF_AK47) // ak-47
				{
					if( PlayerFreeSlotCount( playerid ) < 7 )
					{
						gPlayerData[playerid][pPartType] = 0;
						SavePlayerData( playerid, "PartType" );
						ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_3_NO_SPACE_TXT, "Wróæ", "" );
						return 1;
					}
					#define LP6COUNT1 3
					#define LP6COUNT2 2
					#define LP6COUNT3 2
					#define LP6COUNT4 1
					#define LP6COUNT5 1
					#define LP6COUNT6 1
					#define LP6COUNT7 1
					if ( !( slot = PHaveItem( playerid, 1, 84 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 84, 0, 0, 0, 0, "Puste", LP6COUNT7 );
						WFactoryLegalHeavy[WFactoryAK47Part] -= LP6COUNT7;
						SaveWFactoryData( "WFactoryAK47Part" );
					}
					else
					{
						enough = LP6COUNT7 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 84, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalHeavy[WFactoryAK47Part] -= enough;
							SaveWFactoryData( "WFactoryAK47Part" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 53 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 53, 0, 0, 0, 0, "Puste", LP6COUNT1 );
						WFactoryLegalHeavy[WFactoryRiflePart1] -= LP6COUNT1;
						SaveWFactoryData( "WFactoryRiflePart1" );
					}
					else
					{
						enough = LP6COUNT1 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 53, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalHeavy[WFactoryRiflePart1] -= enough;
							SaveWFactoryData( "WFactoryRiflelPart1" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 54 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 54, 0, 0, 0, 0, "Puste", LP6COUNT2 );
						WFactoryLegalHeavy[WFactoryRiflePart2] -= LP6COUNT2;
						SaveWFactoryData( "WFactoryRiflePart2" );
					}
					else
					{
						enough = LP6COUNT2 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 54, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalHeavy[WFactoryRiflePart2] -= enough;
							SaveWFactoryData( "WFactoryRiflelPart2" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 55 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 55, 0, 0, 0, 0, "Puste", LP6COUNT3 );
						WFactoryLegalHeavy[WFactoryRiflePart3] -= LP6COUNT3;
						SaveWFactoryData( "WFactoryRiflePart3" );
					}
					else
					{
						enough = LP6COUNT3 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 55, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalHeavy[WFactoryRiflePart3] -= enough;
							SaveWFactoryData( "WFactoryRiflelPart3" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 56 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 56, 0, 0, 0, 0, "Puste", LP6COUNT4 );
						WFactoryLegalHeavy[WFactoryRiflePart4] -= LP6COUNT4;
						SaveWFactoryData( "WFactoryRiflePart4" );
					}
					else
					{
						enough = LP6COUNT4 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 56, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalHeavy[WFactoryRiflePart4] -= enough;
							SaveWFactoryData( "WFactoryRiflelPart4" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 57 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 57, 0, 0, 0, 0, "Puste", LP6COUNT5  );
						WFactoryLegalHeavy[WFactoryRiflePart5] -= LP6COUNT5 ;
						SaveWFactoryData( "WFactoryRiflePart5" );
					}
					else
					{
						enough = LP6COUNT5 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 57, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalHeavy[WFactoryRiflePart5] -= enough;
							SaveWFactoryData( "WFactoryRiflelPart5" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 58 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 58, 0, 0, 0, 0, "Puste", LP6COUNT6 );
						WFactoryLegalHeavy[WFactoryRiflePart6] -= LP6COUNT6;
						SaveWFactoryData( "WFactoryRiflePart6" );
					}
					else
					{
						enough = LP6COUNT6 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 58, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalHeavy[WFactoryRiflePart6] -= enough;
							SaveWFactoryData( "WFactoryRiflelPart6" );
						}
					}
					gPlayerData[playerid][pMountsLeft] = 7;
					gPlayerData[playerid][pMountsPasses] = WF_HPT;
					SavePlayerData( playerid, "MountsLeft" );
				}
				else if(gPlayerData[playerid][pPartItem] == WF_M4) // m4
				{
					if( PlayerFreeSlotCount( playerid ) < 7 )
					{
						gPlayerData[playerid][pPartType] = 0;
						SavePlayerData( playerid, "PartType" );
						ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_3_NO_SPACE_TXT, "Wróæ", "" );
						return 1;
					}
					#define LP7COUNT1 3
					#define LP7COUNT2 2
					#define LP7COUNT3 2
					#define LP7COUNT4 1
					#define LP7COUNT5 1
					#define LP7COUNT6 1
					#define LP7COUNT7 1
					if ( !( slot = PHaveItem( playerid, 1, 85 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 85, 0, 0, 0, 0, "Puste", LP7COUNT7 );
						WFactoryLegalHeavy[WFactoryM4Part] -= LP7COUNT7;
						SaveWFactoryData( "WFactoryM4Part" );
					}
					else
					{
						enough = LP7COUNT7 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 85, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalHeavy[WFactoryM4Part] -= enough;
							SaveWFactoryData( "WFactoryM4Part" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 53 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 53, 0, 0, 0, 0, "Puste", LP7COUNT1 );
						WFactoryLegalHeavy[WFactoryRiflePart1] -= LP7COUNT1;
						SaveWFactoryData( "WFactoryRiflePart1" );
					}
					else
					{
						enough = LP7COUNT1 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 53, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalHeavy[WFactoryRiflePart1] -= enough;
							SaveWFactoryData( "WFactoryRiflelPart1" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 54 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 54, 0, 0, 0, 0, "Puste", LP7COUNT2 );
						WFactoryLegalHeavy[WFactoryRiflePart2] -= LP7COUNT2;
						SaveWFactoryData( "WFactoryRiflePart2" );
					}
					else
					{
						enough = LP7COUNT2 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 54, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalHeavy[WFactoryRiflePart2] -= enough;
							SaveWFactoryData( "WFactoryRiflelPart2" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 55 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 55, 0, 0, 0, 0, "Puste", LP7COUNT3 );
						WFactoryLegalHeavy[WFactoryRiflePart3] -= LP7COUNT3;
						SaveWFactoryData( "WFactoryRiflePart3" );
					}
					else
					{
						enough = LP7COUNT3 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 55, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalHeavy[WFactoryRiflePart3] -= enough;
							SaveWFactoryData( "WFactoryRiflelPart3" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 56 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 56, 0, 0, 0, 0, "Puste", LP7COUNT4 );
						WFactoryLegalHeavy[WFactoryRiflePart4] -= LP7COUNT4;
						SaveWFactoryData( "WFactoryRiflePart4" );
					}
					else
					{
						enough = LP7COUNT4 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 56, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalHeavy[WFactoryRiflePart4] -= enough;
							SaveWFactoryData( "WFactoryRiflelPart4" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 57 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 57, 0, 0, 0, 0, "Puste", LP7COUNT5 );
						WFactoryLegalHeavy[WFactoryRiflePart5] -= LP7COUNT5;
						SaveWFactoryData( "WFactoryRiflePart5" );
					}
					else
					{
						enough = LP7COUNT5 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 57, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalHeavy[WFactoryRiflePart5] -= enough;
							SaveWFactoryData( "WFactoryRiflelPart5" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 58 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 58, 0, 0, 0, 0, "Puste", LP7COUNT6 );
						WFactoryLegalHeavy[WFactoryRiflePart6] -= LP7COUNT6;
						SaveWFactoryData( "WFactoryRiflePart6" );
					}
					else
					{
						enough = LP7COUNT6 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 58, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalHeavy[WFactoryRiflePart6] -= enough;
							SaveWFactoryData( "WFactoryRiflelPart6" );
						}
					}
					gPlayerData[playerid][pMountsLeft] = 7;
					gPlayerData[playerid][pMountsPasses] = WF_HPT;
					SavePlayerData( playerid, "MountsLeft" );
				}
				else if(gPlayerData[playerid][pPartItem] == WF_TEC9) // tec9
				{
					if( PlayerFreeSlotCount( playerid ) < 7 )
					{
						gPlayerData[playerid][pPartType] = 0;
						SavePlayerData( playerid, "PartType" );
						ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_3_NO_SPACE_TXT, "Wróæ", "" );
						return 1;
					}
					#define LP8COUNT1 3
					#define LP8COUNT2 2
					#define LP8COUNT3 2
					#define LP8COUNT4 1
					#define LP8COUNT5 1
					#define LP8COUNT6 1
					#define LP8COUNT7 1
					if ( !( slot = PHaveItem( playerid, 1, 82 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 82, 0, 0, 0, 0, "Puste", LP8COUNT7 );
						WFactoryLegalLight[WFactoryTec9Part] -= LP8COUNT7;
						SaveWFactoryData( "WFactoryTec9Part" );
					}
					else
					{
						enough = LP8COUNT7 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 82, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalLight[WFactoryTec9Part] -= enough;
							SaveWFactoryData( "WFactoryTec9Part" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 48 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 48, 0, 0, 0, 0, "Puste", LP8COUNT1 );
						WFactoryLegalLight[WFactoryPistolPart1] -= LP8COUNT1;
						SaveWFactoryData( "WFactoryPistolPart1" );
					}
					else
					{
						enough = LP8COUNT1 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 48, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalLight[WFactoryPistolPart1] -= enough;
							SaveWFactoryData( "WFactoryPistolPart1" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 49 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 49, 0, 0, 0, 0, "Puste", LP8COUNT2 );
						WFactoryLegalLight[WFactoryPistolPart2] -= LP8COUNT2;
						SaveWFactoryData( "WFactoryPistolPart2" );
					}
					else
					{
						enough = LP8COUNT2 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 49, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalLight[WFactoryPistolPart2] -= enough;
							SaveWFactoryData( "WFactoryPistolPart2" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 50 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 50, 0, 0, 0, 0, "Puste", LP8COUNT3 );
						WFactoryLegalLight[WFactoryPistolPart3] -= LP8COUNT3;
						SaveWFactoryData( "WFactoryPistolPart3" );
					}
					else
					{
						enough = LP8COUNT3 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 50, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalLight[WFactoryPistolPart3] -= enough;
							SaveWFactoryData( "WFactoryPistolPart3" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 51 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 51, 0, 0, 0, 0, "Puste", LP8COUNT4 );
						WFactoryLegalLight[WFactoryPistolPart4] -= LP8COUNT4;
						SaveWFactoryData( "WFactoryPistolPart4" );
					}
					else
					{
						enough = LP8COUNT4 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 51, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalLight[WFactoryPistolPart4] -= enough;
							SaveWFactoryData( "WFactoryPistolPart4" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 52 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 52, 0, 0, 0, 0, "Puste", LP8COUNT5 );
						WFactoryLegalLight[WFactoryPistolPart5] -= LP8COUNT5;
						SaveWFactoryData( "WFactoryPistolPart5" );
					}
					else
					{
						enough = LP8COUNT5 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 52, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalLight[WFactoryPistolPart5] -= enough;
							SaveWFactoryData( "WFactoryPistolPart5" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 59 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 59, 0, 0, 0, 0, "Puste", LP8COUNT6 );
						WFactoryLegalLight[WFactoryPistolPart6] -= LP8COUNT6;
						SaveWFactoryData( "WFactoryPistolPart6" );
					}
					else
					{
						enough = LP8COUNT6 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 59, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalLight[WFactoryPistolPart6] -= enough;
							SaveWFactoryData( "WFactoryPistolPart6" );
						}
					}
					gPlayerData[playerid][pMountsLeft] = 7;
					gPlayerData[playerid][pMountsPasses] = WF_LPT;
					SavePlayerData( playerid, "MountsLeft" );
				}
				else if(gPlayerData[playerid][pPartItem] == WF_RIFLE) // country rifle (karabin)
				{
					if( PlayerFreeSlotCount( playerid ) < 7 )
					{
						gPlayerData[playerid][pPartType] = 0;
						SavePlayerData( playerid, "PartType" );
						ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_3_NO_SPACE_TXT, "Wróæ", "" );
						return 1;
					}
					#define LP9COUNT1 2
					#define LP9COUNT2 1
					#define LP9COUNT3 1
					#define LP9COUNT4 1
					#define LP9COUNT5 1
					#define LP9COUNT6 1
					#define LP9COUNT7 1
					if ( !( slot = PHaveItem( playerid, 1, 88 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 88, 0, 0, 0, 0, "Puste", LP9COUNT7 );
						WFactoryLegalHeavy[WFactoryRiflePart] -= LP9COUNT7;
						SaveWFactoryData( "WFactoryRiflePart1" );
					}
					else
					{
						enough = LP9COUNT7 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 88, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalHeavy[WFactoryRiflePart] -= enough;
							SaveWFactoryData( "WFactoryRiflelPart" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 53 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 53, 0, 0, 0, 0, "Puste", LP9COUNT1 );
						WFactoryLegalHeavy[WFactoryRiflePart1] -= LP9COUNT1;
						SaveWFactoryData( "WFactoryRiflePart1" );
					}
					else
					{
						enough = LP9COUNT1 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 53, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalHeavy[WFactoryRiflePart1] -= enough;
							SaveWFactoryData( "WFactoryRiflelPart1" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 54 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 54, 0, 0, 0, 0, "Puste", LP9COUNT2 );
						WFactoryLegalHeavy[WFactoryRiflePart2] -= LP9COUNT2;
						SaveWFactoryData( "WFactoryRiflePart2" );
					}
					else
					{
						enough = LP9COUNT2 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 54, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalHeavy[WFactoryRiflePart2] -= enough;
							SaveWFactoryData( "WFactoryRiflelPart2" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 55 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 55, 0, 0, 0, 0, "Puste", LP9COUNT3 );
						WFactoryLegalHeavy[WFactoryRiflePart3] -= LP9COUNT3;
						SaveWFactoryData( "WFactoryRiflePart3" );
					}
					else
					{
						enough = LP9COUNT3 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 55, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalHeavy[WFactoryRiflePart3] -= enough;
							SaveWFactoryData( "WFactoryRiflelPart3" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 56 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 56, 0, 0, 0, 0, "Puste", LP9COUNT4 );
						WFactoryLegalHeavy[WFactoryRiflePart4] -= LP9COUNT4;
						SaveWFactoryData( "WFactoryRiflePart4" );
					}
					else
					{
						enough = LP9COUNT4 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 56, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalHeavy[WFactoryRiflePart4] -= enough;
							SaveWFactoryData( "WFactoryRiflelPart4" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 57 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 57, 0, 0, 0, 0, "Puste", LP9COUNT5 );
						WFactoryLegalHeavy[WFactoryRiflePart5] -= LP9COUNT5;
						SaveWFactoryData( "WFactoryRiflePart5" );
					}
					else
					{
						enough = LP9COUNT5 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 57, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalHeavy[WFactoryRiflePart5] -= enough;
							SaveWFactoryData( "WFactoryRiflelPart5" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 58 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 58, 0, 0, 0, 0, "Puste", LP9COUNT6 );
						WFactoryLegalHeavy[WFactoryRiflePart6] -= LP9COUNT6;
						SaveWFactoryData( "WFactoryRiflePart6" );
					}
					else
					{
						enough = LP9COUNT6 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 58, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalHeavy[WFactoryRiflePart6] -= enough;
							SaveWFactoryData( "WFactoryRiflelPart6" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 60 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 60, 0, 0, 0, 0, "Puste", LP9COUNT7 );
						WFactoryLegalHeavy[WFactoryRiflePart7] -= LP9COUNT7;
						SaveWFactoryData( "WFactoryRiflePart7" );
					}
					else
					{
						enough = LP9COUNT7 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 60, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalHeavy[WFactoryRiflePart7] -= enough;
							SaveWFactoryData( "WFactoryRiflelPart6" );
						}
					}
					gPlayerData[playerid][pMountsLeft] = 7;
					gPlayerData[playerid][pMountsPasses] = WF_HPT;
					SavePlayerData( playerid, "MountsLeft" );
				}
				else if(gPlayerData[playerid][pPartItem] == WF_SRIFLE) // snajperka
				{
					if( PlayerFreeSlotCount( playerid ) < 8 )
					{
						gPlayerData[playerid][pPartType] = 0;
						SavePlayerData( playerid, "PartType" );
						ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_3_NO_SPACE_TXT, "Wróæ", "" );
						return 1;
					}
					#define LP10COUNT1 3
					#define LP10COUNT2 3
					#define LP10COUNT3 2
					#define LP10COUNT4 2
					#define LP10COUNT5 2
					#define LP10COUNT6 2
					#define LP10COUNT7 1
					#define LP10COUNT8 1
					if ( !( slot = PHaveItem( playerid, 1, 89 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 89, 0, 0, 0, 0, "Puste", LP10COUNT8 );
						WFactoryLegalHeavy[WFactorySniperPart] -= LP10COUNT8;
						SaveWFactoryData( "WFactorySniperPart" );
					}
					else
					{
						enough = LP10COUNT8 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 89, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalHeavy[WFactorySniperPart] -= enough;
							SaveWFactoryData( "WFactorySniperPart" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 53 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 53, 0, 0, 0, 0, "Puste", LP10COUNT1 );
						WFactoryLegalHeavy[WFactoryRiflePart1] -= LP10COUNT1;
						SaveWFactoryData( "WFactoryRiflePart1" );
					}
					else
					{
						enough = LP10COUNT1 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 53, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalHeavy[WFactoryRiflePart1] -= enough;
							SaveWFactoryData( "WFactoryRiflelPart1" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 54 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 54, 0, 0, 0, 0, "Puste", LP10COUNT2 );
						WFactoryLegalHeavy[WFactoryRiflePart2] -= LP10COUNT2;
						SaveWFactoryData( "WFactoryRiflePart2" );
					}
					else
					{
						enough = LP10COUNT2 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 54, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalHeavy[WFactoryRiflePart2] -= enough;
							SaveWFactoryData( "WFactoryRiflelPart2" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 55 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 55, 0, 0, 0, 0, "Puste", LP10COUNT3 );
						WFactoryLegalHeavy[WFactoryRiflePart3] -= LP10COUNT3;
						SaveWFactoryData( "WFactoryRiflePart3" );
					}
					else
					{
						enough = LP10COUNT3 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 55, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalHeavy[WFactoryRiflePart3] -= enough;
							SaveWFactoryData( "WFactoryRiflelPart3" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 56 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 56, 0, 0, 0, 0, "Puste", LP10COUNT4 );
						WFactoryLegalHeavy[WFactoryRiflePart4] -= LP10COUNT4;
						SaveWFactoryData( "WFactoryRiflePart4" );
					}
					else
					{
						enough = LP10COUNT4 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 56, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalHeavy[WFactoryRiflePart4] -= enough;
							SaveWFactoryData( "WFactoryRiflelPart4" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 57 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 57, 0, 0, 0, 0, "Puste", LP10COUNT5 );
						WFactoryLegalHeavy[WFactoryRiflePart5] -= LP10COUNT5;
						SaveWFactoryData( "WFactoryRiflePart5" );
					}
					else
					{
						enough = LP10COUNT5 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 57, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalHeavy[WFactoryRiflePart5] -= enough;
							SaveWFactoryData( "WFactoryRiflelPart5" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 58 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 58, 0, 0, 0, 0, "Puste", LP10COUNT6 );
						WFactoryLegalHeavy[WFactoryRiflePart6] -= LP10COUNT6;
						SaveWFactoryData( "WFactoryRiflePart6" );
					}
					else
					{
						enough = LP10COUNT6 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 58, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalHeavy[WFactoryRiflePart6] -= enough;
							SaveWFactoryData( "WFactoryRiflelPart6" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 60 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 60, 0, 0, 0, 0, "Puste", LP10COUNT7 );
						WFactoryLegalHeavy[WFactoryRiflePart7] -= LP10COUNT7;
						SaveWFactoryData( "WFactoryRiflePart7" );
					}
					else
					{
						enough = LP10COUNT7 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 60, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalHeavy[WFactoryRiflePart7] -= enough;
							SaveWFactoryData( "WFactoryRiflelPart6" );
						}
					}
					gPlayerData[playerid][pMountsLeft] = 8;
					gPlayerData[playerid][pMountsPasses] = WF_HPT;
					SavePlayerData( playerid, "MountsLeft" );
				}
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Pobra³eœ czêœci do monta¿u broni. Udaj siê na jedno ze stanowisk monta¿u broni");
				#undef LP1COUNT1
				#undef LP1COUNT2
				#undef LP1COUNT3
				#undef LP1COUNT4
				#undef LP1COUNT5
				#undef LP1COUNT6
				#undef LP2COUNT1
				#undef LP2COUNT2
				#undef LP2COUNT3
				#undef LP2COUNT4
				#undef LP2COUNT5
				#undef LP2COUNT6
				#undef LP3COUNT1
				#undef LP3COUNT2
				#undef LP3COUNT3
				#undef LP3COUNT4
				#undef LP3COUNT5
				#undef LP3COUNT6
				#undef LP3COUNT7
				#undef LP4COUNT1
				#undef LP4COUNT2
				#undef LP4COUNT3
				#undef LP4COUNT4
				#undef LP4COUNT5
				#undef LP5COUNT1
				#undef LP5COUNT2
				#undef LP5COUNT3
				#undef LP5COUNT4
				#undef LP5COUNT5
				#undef LP5COUNT6
				#undef LP5COUNT7
				#undef LP6COUNT1
				#undef LP6COUNT2
				#undef LP6COUNT3
				#undef LP6COUNT4
				#undef LP6COUNT5
				#undef LP6COUNT6
				#undef LP6COUNT7
				#undef LP7COUNT1
				#undef LP7COUNT2
				#undef LP7COUNT3
				#undef LP7COUNT4
				#undef LP7COUNT5
				#undef LP7COUNT6
				#undef LP7COUNT7
				#undef LP8COUNT1
				#undef LP8COUNT2
				#undef LP8COUNT3
				#undef LP8COUNT4
				#undef LP8COUNT5
				#undef LP8COUNT6
				#undef LP9COUNT1
				#undef LP9COUNT2
				#undef LP9COUNT3
				#undef LP9COUNT4
				#undef LP9COUNT5
				#undef LP9COUNT6
				#undef LP9COUNT7
				#undef LP10COUNT1
				#undef LP10COUNT2
				#undef LP10COUNT3
				#undef LP10COUNT4
				#undef LP10COUNT5
				#undef LP10COUNT6
				#undef LP10COUNT7
				#undef LP10COUNT8
			}
			case WF_AMMO:
			{
				if (gPlayerData[playerid][pPartItem] == 1) // nabój 9mm
				{
					if( PlayerFreeSlotCount( playerid ) < 4 )
					{
						gPlayerData[playerid][pPartType] = 0;
						SavePlayerData( playerid, "PartType" );
						ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_3_NO_SPACE_TXT, "Wróæ", "" );
						return 1;
					}
					if( !PHaveItem( playerid, 1, 43 ) )
					{
						InsertPlayerItemEx( playerid, 1, 43, 0, 0, 0, 0, "Puste", 1 );
						WFactoryLegalLight[WFactoryAmmoPart1a] -= 1;
						SaveWFactoryData( "WFactoryAmmoPart1a" );
					}
					if( !PHaveItem( playerid, 1, 44 ) )
					{
						InsertPlayerItemEx( playerid, 1, 44, 0, 0, 0, 0, "Puste", 1 );
						WFactoryLegalLight[WFactoryAmmoPart2a] -= 1;
						SaveWFactoryData( "WFactoryAmmoPart2a" );
					}
					if( !PHaveItem( playerid, 1, 45 ) )
					{
						InsertPlayerItemEx( playerid, 1, 45, 0, 0, 0, 0, "Puste", 1 );
						WFactoryLegalLight[WFactoryAmmoPart3a] -= 1;
						SaveWFactoryData( "WFactoryAmmoPart3a" );
					}
					if( !PHaveItem( playerid, 1, 46 ) )
					{
						InsertPlayerItemEx( playerid, 1, 46, 0, 0, 0, 0, "Puste", 1 );
						WFactoryLegalLight[WFactoryAmmoPart4a] -= 1;
						SaveWFactoryData( "WFactoryAmmoPart4a" );
					}
					gPlayerData[playerid][pMountsLeft] = 4;
					gPlayerData[playerid][pMountsPasses] = WF_AMMOT;
					SavePlayerData( playerid, "MountsLeft" );
				}
				else if (gPlayerData[playerid][pPartItem] == 2) // nabój .50 AE
				{
					if( PlayerFreeSlotCount( playerid ) < 4 )
					{
						gPlayerData[playerid][pPartType] = 0;
						SavePlayerData( playerid, "PartType" );
						ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_3_NO_SPACE_TXT, "Wróæ", "" );
						return 1;
					}
					#define LP1COUNT1 10
					#define LP1COUNT2 5
					#define LP1COUNT3 2
					#define LP1COUNT4 2
					if( !( slot = PHaveItem( playerid, 1, 101 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 101, 0, 0, 0, 0, "Puste", LP1COUNT1 );
						WFactoryLegalLight[WFactoryAmmoPart1e] -= LP1COUNT1;
						SaveWFactoryData( "WFactoryAmmoPart1e" );
					}
					else
					{
						enough = LP1COUNT1 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 101, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalLight[WFactoryAmmoPart1e] -= enough;
							SaveWFactoryData( "WFactoryAmmoPart1e" );
						}
					}
					if( !( slot = PHaveItem( playerid, 1, 102 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 102, 0, 0, 0, 0, "Puste", LP1COUNT2 );
						WFactoryLegalLight[WFactoryAmmoPart2e] -= LP1COUNT2;
						SaveWFactoryData( "WFactoryAmmoPart2e" );
					}
					else
					{
						enough = LP1COUNT2 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 102, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalLight[WFactoryAmmoPart2e] -= enough;
							SaveWFactoryData( "WFactoryAmmoPart2e" );
						}
					}
					if( !( slot = PHaveItem( playerid, 1, 103 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 103, 0, 0, 0, 0, "Puste", LP1COUNT3 );
						WFactoryLegalLight[WFactoryAmmoPart3e] -= LP1COUNT3;
						SaveWFactoryData( "WFactoryAmmoPart3e" );
					}
					else
					{
						enough = LP1COUNT3 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 103, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalLight[WFactoryAmmoPart3e] -= enough;
							SaveWFactoryData( "WFactoryAmmoPart3e" );
						}
					}
					if( !( slot = PHaveItem( playerid, 1, 104 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 104, 0, 0, 0, 0, "Puste", LP1COUNT4 );
						WFactoryLegalLight[WFactoryAmmoPart4e] -= LP1COUNT4;
						SaveWFactoryData( "WFactoryAmmoPart4e" );
					}
					else
					{
						enough = LP1COUNT4 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 104, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalLight[WFactoryAmmoPart4e] -= enough;
							SaveWFactoryData( "WFactoryAmmoPart4e" );
						}
					}
					gPlayerData[playerid][pMountsLeft] = 4;
					gPlayerData[playerid][pMountsPasses] = WF_AMMOT;
					SavePlayerData( playerid, "MountsLeft" );
				}
				else if (gPlayerData[playerid][pPartItem] == 3) // œrut
				{
					if( PlayerFreeSlotCount( playerid ) < 4 )
					{
						gPlayerData[playerid][pPartType] = 0;
						SavePlayerData( playerid, "PartType" );
						ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_3_NO_SPACE_TXT, "Wróæ", "" );
						return 1;
					}
					#define LP2COUNT1 6
					#define LP2COUNT2 1
					#define LP2COUNT3 2
					#define LP2COUNT4 2
					if( !( slot = PHaveItem( playerid, 1, 47 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 47, 0, 0, 0, 0, "Puste", LP2COUNT1 );
						WFactoryLegalLight[WFactoryAmmoPart1b] -= LP2COUNT1;
						SaveWFactoryData( "WFactoryAmmoPart1b" );
					}
					else
					{
						enough = LP2COUNT1 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 47, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalLight[WFactoryAmmoPart1b] -= enough;
							SaveWFactoryData( "WFactoryAmmoPart1b" );
						}
					}
					if( !( slot = PHaveItem( playerid, 1, 90 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 90, 0, 0, 0, 0, "Puste", LP2COUNT2 );
						WFactoryLegalLight[WFactoryAmmoPart2b] -= LP2COUNT2;
						SaveWFactoryData( "WFactoryAmmoPart2b" );
					}
					else
					{
						enough = LP2COUNT2 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 90, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalLight[WFactoryAmmoPart2b] -= enough;
							SaveWFactoryData( "WFactoryAmmoPart2b" );
						}
					}
					if( !( slot = PHaveItem( playerid, 1, 91 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 91, 0, 0, 0, 0, "Puste", LP2COUNT3 );
						WFactoryLegalLight[WFactoryAmmoPart3b] -= LP2COUNT3;
						SaveWFactoryData( "WFactoryAmmoPart3b" );
					}
					else
					{
						enough = LP2COUNT3 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 91, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalLight[WFactoryAmmoPart3b] -= enough;
							SaveWFactoryData( "WFactoryAmmoPart3b" );
						}
					}
					if( !( slot = PHaveItem( playerid, 1, 92 ) ) )
					{
						InsertPlayerItemEx( playerid, 1, 92, 0, 0, 0, 0, "Puste", LP2COUNT4 );
						WFactoryLegalLight[WFactoryAmmoPart4b] -= LP2COUNT4;
						SaveWFactoryData( "WFactoryAmmoPart4b" );
					}
					else
					{
						enough = LP2COUNT4 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 92, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalLight[WFactoryAmmoPart4b] -= enough;
							SaveWFactoryData( "WFactoryAmmoPart4b" );
						}
					}
					gPlayerData[playerid][pMountsLeft] = 4;
					gPlayerData[playerid][pMountsPasses] = WF_AMMOT;
					SavePlayerData( playerid, "MountsLeft" );
					return 1;
				}
				else if (gPlayerData[playerid][pPartItem] == 4) // nabój 7.62
				{
					if( PlayerFreeSlotCount( playerid ) < 4 )
					{
						gPlayerData[playerid][pPartType] = 0;
						SavePlayerData( playerid, "PartType" );
						ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_3_NO_SPACE_TXT, "Wróæ", "" );
						return 1;
					}
					#define LP3COUNT1 4
					#define LP3COUNT2 2
					#define LP3COUNT3 2
					#define LP3COUNT4 2
					if( !PHaveItem( playerid, 1, 93 ) )
					{
						InsertPlayerItemEx( playerid, 1, 93, 0, 0, 0, 0, "Puste", LP3COUNT1 );
						WFactoryLegalLight[WFactoryAmmoPart1c] -= LP3COUNT1;
						SaveWFactoryData( "WFactoryAmmoPart1c" );
					}
					else
					{
						enough = LP3COUNT1 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 93, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalLight[WFactoryAmmoPart1c] -= enough;
							SaveWFactoryData( "WFactoryAmmoPart1c" );
						}
					}
					if( !PHaveItem( playerid, 1, 94 ) )
					{
						InsertPlayerItemEx( playerid, 1, 94, 0, 0, 0, 0, "Puste", LP3COUNT2 );
						WFactoryLegalLight[WFactoryAmmoPart2c] -= LP3COUNT2;
						SaveWFactoryData( "WFactoryAmmoPart2c" );
					}
					else
					{
						enough = LP3COUNT2 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 94, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalLight[WFactoryAmmoPart2c] -= enough;
							SaveWFactoryData( "WFactoryAmmoPart2c" );
						}
					}
					if( !PHaveItem( playerid, 1, 95 ) )
					{
						InsertPlayerItemEx( playerid, 1, 95, 0, 0, 0, 0, "Puste", LP3COUNT3 );
						WFactoryLegalLight[WFactoryAmmoPart3c] -= LP3COUNT3;
						SaveWFactoryData( "WFactoryAmmoPart3c" );
					}
					else
					{
						enough = LP3COUNT3 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 95, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalLight[WFactoryAmmoPart3c] -= enough;
							SaveWFactoryData( "WFactoryAmmoPart3c" );
						}
					}
					if( !PHaveItem( playerid, 1, 96 ) )
					{
						InsertPlayerItemEx( playerid, 1, 96, 0, 0, 0, 0, "Puste", LP3COUNT4 );
						WFactoryLegalLight[WFactoryAmmoPart4c] -= LP3COUNT4;
						SaveWFactoryData( "WFactoryAmmoPart4c" );
					}
					else
					{
						enough = LP3COUNT4 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 96, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalLight[WFactoryAmmoPart4c] -= enough;
							SaveWFactoryData( "WFactoryAmmoPart4c" );
						}
					}
					gPlayerData[playerid][pMountsLeft] = 4;
					gPlayerData[playerid][pMountsPasses] = WF_AMMOT;
					SavePlayerData( playerid, "MountsLeft" );
				}
				else if (gPlayerData[playerid][pPartItem] == 5) // nabój 12.7
				{
					if( PlayerFreeSlotCount( playerid ) < 4 )
					{
						gPlayerData[playerid][pPartType] = 0;
						SavePlayerData( playerid, "PartType" );
						ShowPlayerDialog( playerid, DIALOG_WMENU_3_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_3_NO_SPACE_TXT, "Wróæ", "" );
						return 1;
					}
					#define LP4COUNT1 4
					#define LP4COUNT2 2
					#define LP4COUNT3 2
					#define LP4COUNT4 2
					if( !PHaveItem( playerid, 1, 97 ) )
					{
						InsertPlayerItemEx( playerid, 1, 97, 0, 0, 0, 0, "Puste", LP4COUNT1 );
						WFactoryLegalLight[WFactoryAmmoPart1d] -= LP4COUNT1;
						SaveWFactoryData( "WFactoryAmmoPart1d" );
					}
					else
					{
						enough = LP4COUNT1 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 97, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalLight[WFactoryAmmoPart1d] -= enough;
							SaveWFactoryData( "WFactoryAmmoPart1d" );
						}
					}
					if( !PHaveItem( playerid, 1, 98 ) )
					{
						InsertPlayerItemEx( playerid, 1, 98, 0, 0, 0, 0, "Puste", LP4COUNT2 );
						WFactoryLegalLight[WFactoryAmmoPart2d] -= LP4COUNT2;
						SaveWFactoryData( "WFactoryAmmoPart2d" );
					}
					else
					{
						enough = LP4COUNT2 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 98, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalLight[WFactoryAmmoPart2d] -= enough;
							SaveWFactoryData( "WFactoryAmmoPart2d" );
						}
					}
					if( !PHaveItem( playerid, 1, 99 ) )
					{
						InsertPlayerItemEx( playerid, 1, 99, 0, 0, 0, 0, "Puste", LP4COUNT3 );
						WFactoryLegalLight[WFactoryAmmoPart3d] -= LP4COUNT3;
						SaveWFactoryData( "WFactoryAmmoPart3d" );
					}
					else
					{
						enough = LP4COUNT3 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 99, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalLight[WFactoryAmmoPart3d] -= enough;
							SaveWFactoryData( "WFactoryAmmoPart3d" );
						}
					}
					if( !PHaveItem( playerid, 1, 100 ) )
					{
						InsertPlayerItemEx( playerid, 1, 100, 0, 0, 0, 0, "Puste", LP4COUNT4 );
						WFactoryLegalLight[WFactoryAmmoPart4d] -= LP4COUNT4;
						SaveWFactoryData( "WFactoryAmmoPart4d" );
					}
					else
					{
						enough = LP4COUNT4 - SlotParam6(playerid, slot);
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 99, 0, 0, 0, 0, "Puste", enough );
							WFactoryLegalLight[WFactoryAmmoPart4d] -= enough;
							SaveWFactoryData( "WFactoryAmmoPart4d" );
						}
					}
					gPlayerData[playerid][pMountsLeft] = 4;
					gPlayerData[playerid][pMountsPasses] = WF_AMMOT;
					SavePlayerData( playerid, "MountsLeft" );
				}
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Pobra³eœ czêœci do monta¿u amunicji. Udaj siê na jedno ze stanowisk monta¿u amunicji");
				#undef LP1COUNT1
				#undef LP1COUNT2
				#undef LP1COUNT3
				#undef LP1COUNT4
				#undef LP2COUNT1
				#undef LP2COUNT2
				#undef LP2COUNT3
				#undef LP2COUNT4
				#undef LP3COUNT1
				#undef LP3COUNT2
				#undef LP3COUNT3
				#undef LP3COUNT4
				#undef LP4COUNT1
				#undef LP4COUNT2
				#undef LP4COUNT3
				#undef LP4COUNT4
			}
			case WF_PART:
			{
				if (gPlayerData[playerid][pPartItem] == 1) // szkielet broni
				{
					if( PlayerFreeSlotCount( playerid ) < 3 )
					{
						gPlayerData[playerid][pPartType] = 0;
						SavePlayerData( playerid, "PartType" );
						ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_3_NO_SPACE_TXT, "Wróæ", "" );
						return 1;
					}
					if( !PHaveItem( playerid, 1, 61 ) )
					{
						InsertPlayerItemEx( playerid, 1, 61, 0, 0, 0, 0, "Puste", 1);
						WFactoryLegalLight[WFactoryPistolS1Part1]--;
						SaveWFactoryData( "WFactoryPistolS1Part1" );
					}
					if( !PHaveItem( playerid, 1, 62 ) )
					{
						InsertPlayerItemEx( playerid, 1, 62, 0, 0, 0, 0, "Puste", 1);
						WFactoryLegalLight[WFactoryPistolS1Part2]--;
						SaveWFactoryData( "WFactoryPistolS1Part2" );
					}
					if( !PHaveItem( playerid, 1, 63 ) )
					{
						InsertPlayerItemEx( playerid, 1, 63, 0, 0, 0, 0, "Puste", 1);
						WFactoryLegalLight[WFactoryPistolS1Part3]--;
						SaveWFactoryData( "WFactoryPistolS1Part3" );
					}
					gPlayerData[playerid][pMountsLeft] = 3;
					gPlayerData[playerid][pMountsPasses] = WF_LSPT;
					SavePlayerData( playerid, "MountsLeft" );
				}
				else if(gPlayerData[playerid][pPartItem] == 2) // Zespó³ zamka
				{
					if( PlayerFreeSlotCount( playerid ) < 3 )
					{
						gPlayerData[playerid][pPartType] = 0;
						SavePlayerData( playerid, "PartType" );
						ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_3_NO_SPACE_TXT, "Wróæ", "" );
						return 1;
					}
					if ( !PHaveItem( playerid, 1, 64 ) )
					{
						InsertPlayerItemEx( playerid, 1, 64, 0, 0, 0, 0, "Puste", 1 );
						WFactoryLegalLight[WFactoryPistolS2Part1]--;
						SaveWFactoryData( "WFactoryPistolS2Part1" );
					}
					if ( !PHaveItem( playerid, 1, 65 ) )
					{
						InsertPlayerItemEx( playerid, 1, 65, 0, 0, 0, 0, "Puste", 1 );
						WFactoryLegalLight[WFactoryPistolS2Part2]--;
						SaveWFactoryData( "WFactoryPistolS2Part2" );
					}
					if ( !PHaveItem( playerid, 1, 66 ) )
					{
						InsertPlayerItemEx( playerid, 1, 66, 0, 0, 0, 0, "Puste", 1 );
						WFactoryLegalLight[WFactoryPistolS2Part3]--;
						SaveWFactoryData( "WFactoryPistolS2Part3" );
					}
					gPlayerData[playerid][pMountsLeft] = 3;
					gPlayerData[playerid][pMountsPasses] = WF_LSPT;
					SavePlayerData( playerid, "MountsLeft" );
				}
				else if(gPlayerData[playerid][pPartItem] == 3) // Magazynek
				{
					if( PlayerFreeSlotCount( playerid ) < 4 )
					{
						gPlayerData[playerid][pPartType] = 0;
						SavePlayerData( playerid, "PartType" );
						ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_3_NO_SPACE_TXT, "Wróæ", "" );
						return 1;
					}
					if ( !PHaveItem( playerid, 1, 67 ) )
					{
						InsertPlayerItemEx( playerid, 1, 67, 0, 0, 0, 0, "Puste", 1);
						WFactoryLegalLight[WFactoryPistolS3Part1]--;
						SaveWFactoryData( "WFactoryPistolS3Part1" );
					}
					if ( !PHaveItem( playerid, 1, 68 ) )
					{
						InsertPlayerItemEx( playerid, 1, 68, 0, 0, 0, 0, "Puste", 1);
						WFactoryLegalLight[WFactoryPistolS3Part2]--;
						SaveWFactoryData( "WFactoryPistolS3Part2" );
					}
					if ( !PHaveItem( playerid, 1, 69 ) )
					{
						InsertPlayerItemEx( playerid, 1, 69, 0, 0, 0, 0, "Puste", 1);
						WFactoryLegalLight[WFactoryPistolS3Part3]--;
						SaveWFactoryData( "WFactoryPistolS3Part3" );
					}
					if ( !PHaveItem( playerid, 1, 70 ) )
					{
						InsertPlayerItemEx( playerid, 1, 70, 0, 0, 0, 0, "Puste", 1);
						WFactoryLegalLight[WFactoryPistolS3Part4]--;
						SaveWFactoryData( "WFactoryPistolS3Part4" );
					}
					SendClientMessage( playerid, COLOR_LIGHTYELLOW2, DIALOG_WMENU_GOTO1_TXT );
					SendClientMessage( playerid, COLOR_LIGHTYELLOW2, DIALOG_WMENU_GOTO2_TXT );
					gPlayerData[playerid][pPartType] = WF_PART;
					gPlayerData[playerid][pPartItem] = WF_PISTOLPART3;
					gPlayerData[playerid][pMountsLeft] = 4;
					gPlayerData[playerid][pMountsPasses] = WF_LSPT;
					SavePlayerData( playerid, "PartType" );
					SavePlayerData( playerid, "PartItem" );
					SavePlayerData( playerid, "MountsLeft" );
				}
				else if(gPlayerData[playerid][pPartItem] == 7) // szkielet broni karabinowej
				{
					if( PlayerFreeSlotCount( playerid ) < 3 )
					{
						gPlayerData[playerid][pPartType] = 0;
						SavePlayerData( playerid, "PartType" );
						ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_3_NO_SPACE_TXT, "Wróæ", "" );
						return 1;
					}
					if ( !PHaveItem( playerid, 1, 71 ) )
					{
						InsertPlayerItemEx( playerid, 1, 71, 0, 0, 0, 0, "Puste", 1);
						WFactoryLegalHeavy[WFactoryRifleS1Part1]--;
						SaveWFactoryData( "WFactoryRifleS1Part1" );
					}
					if ( !PHaveItem( playerid, 1, 72 ) )
					{
						InsertPlayerItemEx( playerid, 1, 72, 0, 0, 0, 0, "Puste", 1);
						WFactoryLegalHeavy[WFactoryRifleS1Part2]--;
						SaveWFactoryData( "WFactoryRifleS1Part2" );
					}
					if ( !PHaveItem( playerid, 1, 63 ) )
					{
						InsertPlayerItemEx( playerid, 1, 63, 0, 0, 0, 0, "Puste", 1);
						WFactoryLegalLight[WFactoryPistolS1Part3]--;
						SaveWFactoryData( "WFactoryPistolS1Part3" );
					}
					gPlayerData[playerid][pMountsLeft] = 3;
					gPlayerData[playerid][pMountsPasses] = WF_HSPT;
					SavePlayerData( playerid, "MountsLeft" );
				}
				else if(gPlayerData[playerid][pPartItem] == 8) // zespó³ zamka karabinu
				{
					if( PlayerFreeSlotCount( playerid ) < 3 )
					{
						gPlayerData[playerid][pPartType] = 0;
						SavePlayerData( playerid, "PartType" );
						ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_3_NO_SPACE_TXT, "Wróæ", "" );
						return 1;
					}
					if ( !PHaveItem( playerid, 1, 73 ) )
					{
						InsertPlayerItemEx( playerid, 1, 73, 0, 0, 0, 0, "Puste", 1);
						WFactoryLegalHeavy[WFactoryRifleS2Part1]--;
						SaveWFactoryData( "WFactoryRifleS2Part1" );
					}
					if ( !PHaveItem( playerid, 1, 74 ) )
					{
						InsertPlayerItemEx( playerid, 1, 74, 0, 0, 0, 0, "Puste", 1);
						WFactoryLegalHeavy[WFactoryRifleS2Part2]--;
						SaveWFactoryData( "WFactoryRifleS2Part2" );
					}
					if ( !PHaveItem( playerid, 1, 75 ) )
					{
						InsertPlayerItemEx( playerid, 1, 75, 0, 0, 0, 0, "Puste", 1);
						WFactoryLegalHeavy[WFactoryRifleS2Part3]--;
						SaveWFactoryData( "WFactoryRifleS2Part3" );
					}
					gPlayerData[playerid][pMountsLeft] = 3;
					gPlayerData[playerid][pMountsPasses] = WF_HSPT;
					SavePlayerData( playerid, "MountsLeft" );
				}
				else if(gPlayerData[playerid][pPartItem] == 9) // magazynek karabinu
				{
					if( PlayerFreeSlotCount( playerid ) < 4 )
					{
						gPlayerData[playerid][pPartType] = 0;
						SavePlayerData( playerid, "PartType" );
						ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_3_NO_SPACE_TXT, "Wróæ", "" );
						return 1;
					}
					if ( !PHaveItem( playerid, 1, 76 ) )
					{
						InsertPlayerItemEx( playerid, 1, 76, 0, 0, 0, 0, "Puste", 1);
						WFactoryLegalHeavy[WFactoryRifleS3Part1]--;
						SaveWFactoryData( "WFactoryRifleS3Part1" );
					}
					if ( !PHaveItem( playerid, 1, 77 ) )
					{
						InsertPlayerItemEx( playerid, 1, 77, 0, 0, 0, 0, "Puste", 1);
						WFactoryLegalHeavy[WFactoryRifleS3Part2]--;
						SaveWFactoryData( "WFactoryRifleS3Part2" );
					}
					if ( !PHaveItem( playerid, 1, 78 ) )
					{
						InsertPlayerItemEx( playerid, 1, 78, 0, 0, 0, 0, "Puste", 1);
						WFactoryLegalHeavy[WFactoryRifleS3Part3]--;
						SaveWFactoryData( "WFactoryRifleS3Part3" );
					}
					if ( !PHaveItem( playerid, 1, 79 ) )
					{
						InsertPlayerItemEx( playerid, 1, 79, 0, 0, 0, 0, "Puste", 1);
						WFactoryLegalHeavy[WFactoryRifleS3Part4]--;
						SaveWFactoryData( "WFactoryRifleS3Part4" );
					}
					SendClientMessage( playerid, COLOR_LIGHTYELLOW2, DIALOG_WMENU_GOTO1_TXT );
					SendClientMessage( playerid, COLOR_LIGHTYELLOW2, DIALOG_WMENU_GOTO2_TXT );
					gPlayerData[playerid][pPartType] = WF_PART;
					gPlayerData[playerid][pPartItem] = WF_RIFLEPART3;
					gPlayerData[playerid][pMountsLeft] = 3;
					gPlayerData[playerid][pMountsPasses] = WF_HSPT;
					SavePlayerData( playerid, "PartType" );
					SavePlayerData( playerid, "PartItem" );
					SavePlayerData( playerid, "MountsLeft" );
					return 1;
				}
				else if(gPlayerData[playerid][pPartItem] == 13) // luneta
				{
					if( PlayerFreeSlotCount( playerid ) < 2 )
					{
						gPlayerData[playerid][pPartType] = 0;
						SavePlayerData( playerid, "PartType" );
						ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_3_NO_SPACE_TXT, "Wróæ", "" );
						return 1;
					}
					if( !PHaveItem( playerid, 1, 80 ) )
					{
						InsertPlayerItemEx( playerid, 1, 80, 0, 0, 0, 0, "Puste", 1);
						WFactoryLegalHeavy[WFactoryRifleS6Part1]--;
						SaveWFactoryData( "WFactoryRifleS6Part1" );
					}
					if( !PHaveItem( playerid, 1, 81 ) )
					{
						InsertPlayerItemEx( playerid, 1, 81, 0, 0, 0, 0, "Puste", 1);
						WFactoryLegalHeavy[WFactoryRifleS6Part2]--;
						SaveWFactoryData( "WFactoryRifleS6Part2" );
					}
					gPlayerData[playerid][pMountsLeft] = 2;
					gPlayerData[playerid][pMountsPasses] = WF_HSPT;
					SavePlayerData( playerid, "MountsLeft" );
				}
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Pobra³eœ czêœci do monta¿u czêœci g³ównej. Udaj siê na jedno ze stanowisk monta¿u czêœci");
			}
		}
		SavePlayerData(playerid, "PartType");
		SavePlayerData(playerid, "PartItem");
	}
	return 1;
}

dcmd_zamowbron( playerid, params[] )
{
	#pragma unused params
	ShowPlayerDialog( playerid, DIALOG_WLMENU_1_SELECT, DIALOG_STYLE_LIST, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_SEL_OB_TXT, "Wybierz", "Anuluj" );
	return 1;
}

dcmd_setcameratop( playerid, params[] )
{
	#pragma unused params
	if( gPlayerData[playerid][pAdmin] != 5 )
		return 0;
	new Float: px, Float: py, Float: pz;
	GetPlayerPos( playerid, px, py, pz );
	SetPlayerCameraPos( playerid, px, py, pz+5.0 );
	SetPlayerCameraLookAt( playerid, px, py, pz+50.0 );
	return 1;
}

dcmd_resetcamera( playerid, params[] )
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	SetCameraBehindPlayer( playerid );
	return 1;
}

dcmd_setcamerapos( playerid, params[] )
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new Float:lfX, Float:lfY, Float:lfZ;
	if(sscanf(params, "fff", lfX, lfY, lfZ))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /setcamerapos [m_fX] [m_fY] [m_fZ]");
		return 1;
	}
	new string[128];
	format(string, sizeof(string), "[INFO:] Camera pos set to %f %f %f", lfX, lfY, lfZ);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	SetPlayerCameraPos(playerid, lfX, lfY, lfZ);
	return 1;
}

dcmd_setcameralookat( playerid, params[] )
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new Float:lfX, Float:lfY, Float:lfZ;
	if(sscanf(params, "fff", lfX, lfY, lfZ))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /setcameralookat [m_fX] [m_fY] [m_fZ]");
		return 1;
	}
	new string[128];
	format(string, sizeof(string), "[INFO:] Camera look at set to %f %f %f", lfX, lfY, lfZ);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	SetPlayerCameraLookAt(playerid, lfX, lfY, lfZ);
	return 1;
}

dcmd_quat( playerid, params[] )
{
	#pragma unused params
	if( gPlayerData[playerid][pAdmin] != 5 )
		return 0;
	new Float:w, Float:x, Float:y, Float:z, string[128];
	GetVehicleRotationQuat( GetPlayerVehicleID(playerid), w, x, y, z );
	format( string, sizeof(string), "w: %f, x: %f, y: %f, z: %f", w, x, y, z );
	SendClientMessage( playerid, COLOR_ORANGE, string );
	return 1;
}

dcmd_danepojazdu( playerid, params[] )
{
	new vehid = GetPlayerVehicleID(playerid);
	if(vehid == 0)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Musisz byæ w radiowozie aby skorzystaæ z tej komendy !");
		return 1;
	}
	if(!gVehData[vehid-1][VPoliceComputer])
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ten pojazd nie posiada komputera w którym mo¿na by by³o sprawdziæ dane podejrzanego");
		return 1;
	}
	new serial, string[128];
	if( sscanf( params, "d", serial ) )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] /danepojazdu [rejestracja pojazdu]" );
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Podaj¹c rejestracje wpisz jedynie jej numery bez przedrostka miasta !");
		return 1;
	}
	for(new i = 0; i < sizeof(gVehData); i++)
	{
		if(gVehData[i][CarSerial] == serial)
		{
			if(strcmp( gVehData[i][Owner], "none", true, sizeof(gVehData)) == 0)
			{
				SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Pojazd nie posiada w³aœciciela. Prawdopodonie nale¿y do frakcji lub zosta³ porzucony przez w³aœciciela.");
				return 1;
			}
			format(string, sizeof(string), "Dane dla pojazdu o rejestracji: %d\n\nModel: %s\nW³aœciciel: %s", gVehData[i][CarSerial], GetVehicleName(i+1), gVehData[i][Owner]);
			if(gVehData[i][VConfiscated])
				strcat(string, "\nSkonfiskowany: tak");
			else
				strcat(string, "\nSkonfiskowany: nie");
			ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", string, "Zamknij", "");
			return 1;
		}
	}
	SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie znaleziono w bazie pojazdu o takiej rejestracji.");
	return 1;
}

dcmd_mp( playerid, params[] )
{
	#pragma unused params
	if( gPlayerData[playerid][pFaction] != 255 )
	{
		if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fType] != F_POLICE )
		{
			SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Niew³aœciwa frakcja.");
			return 1;
		}
	}
	else
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Niew³aœciwa frakcja.");
		return 1;
	}
	gPlayerData[playerid][pSpeedGunOn] = 1;
	defer GetPlayerSpeed(playerid);
	SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Miernik prêdkoœci uruchomiony");
	return 1;
}

dcmd_komendypojazdow(playerid, params[])
{
	#pragma unused params
	new string[2048];
	
	format(string, sizeof(string), ""#COLOR_BEGIN2" * Komendy pojazdów *\n\n");
	strcat(string, ""#COLOR_BEGIN"Podstawowe\n  "#COLOR_DEFAULT"/engine (/e) - /zamknij - /wyposazeniepojazdu - /pasy - /otworzmaske - /zamknijmaske - /otworzbagaznik - /zamknijbagaznik\n");
	strcat(string, ""  #COLOR_DEFAULT"/zatankuj - /kuppojazd - /kuppojazdf - /sprzedajpojazd - /anulujsprzedazpojazdu - /anulujsprzedazpojazdu(f)\n\n");
	strcat(string, ""#COLOR_BEGIN"Radio\n  "#COLOR_DEFAULT"/radios - /radiosv\n\n");
	strcat(string, ""#COLOR_BEGIN"Baga¿nik\n  "#COLOR_DEFAULT"/mojeitemywpojezdzie (/miwp) - /wlozitemdopojazdu (/widp)\n\n");
	strcat(string, ""#COLOR_BEGIN"CB radio\n  "#COLOR_DEFAULT"/kanalcb - /cbv - /kanalcb - /onoffcb\n\n");
	strcat(string, ""#COLOR_BEGIN"Naczepa\n  "#COLOR_DEFAULT"/wjedzdonaczepy - /wyjedzznaczepy - /wejdzdonaczepy - /wyjdzznaczepy - /holuj - /odczepnaczepe\n\n");
	strcat(string, ""#COLOR_BEGIN"Kamper\n  "#COLOR_DEFAULT"/wejdzdokampera - /wyjdzzkampera\n\n");
	strcat(string, ""#COLOR_BEGIN"Wynajem pojazdu\n  "#COLOR_DEFAULT"/wynajmijpojazd - /zwrocpojazd\n\n");
	strcat(string, ""#COLOR_BEGIN"Ubezpieczenie\n  "#COLOR_DEFAULT"/zrezygnujzoc - /zrezygnujzac\n\n");
	strcat(string, ""#COLOR_BEGIN"Obiekty\n  "#COLOR_DEFAULT"/doczepobiekt - /ustawobiektpoj - /obrocobiektpoj - /pozycjaobiektupoj - /onoffobiektpoj - /zdemontujobiektzpoj - /zdemontujobiektzpojazdu\n\n");
	strcat(string, ""#COLOR_BEGIN"Inne\n  "#COLOR_DEFAULT"/wywal - /zezlomujpojazd - /zezlomujpojazdf");

	ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, ""#COLOR_TITLE"Komendy", string, "Zamknij", ""); 
	
	return 1;
}

dcmd_proba( playerid, params[] )
{
	new string[128];
	if(gTryCoolDown[playerid] > 0)
	{
		format(string, sizeof(string), "[INFO:] Musisz odczekaæ jeszcze %d sekund aby znów u¿yæ tej komendy", gTryCoolDown[playerid]);
		SendClientMessage(playerid, COLOR_ORANGE, string);
		return 1;
	}
	new action[128];
	if( sscanf( params, "s", action ) )
	{
		SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] /proba [akcja]" );
		return 1;
	}
	new succeed = 1 + random(2);
	if(succeed == 1)
	{
		format(string, sizeof(string), "[AKCJA:] %s spróbowa³ %s i osi¹gn¹³ sukces", GetPlayerNameEx(playerid), action);
		ProxDetector(10.0, playerid, string, COLOR_GREEN,COLOR_GREEN,COLOR_GREEN,COLOR_GREEN,COLOR_GREEN);
	}
	else if(succeed == 2)
	{
		format(string, sizeof(string), "[AKCJA:] %s spróbowa³ %s bez rezultatu", GetPlayerNameEx(playerid), action);
		ProxDetector(10.0, playerid, string, COLOR_RED,COLOR_RED,COLOR_RED,COLOR_RED,COLOR_RED);
	}
	return 1;
}

dcmd_kanalcb(playerid, params[])
{
	new vehid = GetPlayerVehicleID(playerid);
	if(vehid == 0)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w pojeŸdzie !");
		return 1;
	}
	if(!gVehData[vehid-1][VCBRadio])
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie posaidasz CB Radia w tym pojeŸdzie !");
		return 1;
	}
	if(!gVehData[vehid-1][VCBRadioStatus])
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] CB Radio jest wy³¹czone !");
		return 1;
	}
	new chanel;
	if(sscanf(params, "d", chanel))
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] /kanalcb [kanal]");
		return 1;
	}
	if(chanel < 0 || chanel > 45)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Zakres kanalów: 0-45");
		return 1;
	}
	if(gVehData[vehid-1][VCBRadio] == 1 && chanel > 40)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] To CB Radio nie obs³uguje tych kana³ów !");
		return 1;
	}
	gVehData[vehid-1][VCBRadioChanel] = chanel;
	SaveVehData(vehid-1, "CBRadioChanel");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Zmieni³eœ kana³ swojego CB Radia");
	return 1;
}

dcmd_cbv(playerid, params[])
{
	if(gPlayerData[playerid][pMuted] && gPlayerData[playerid][pAdmin] == 0)
	{
		SendClientMessage(playerid, COLOR_LIGHTRED, "[INFO:] Nie mo¿esz u¿ywaæ tego chatu kiedy jesteœ uciszony !");
		return 1;
	}
	new vehid = GetPlayerVehicleID(playerid);
	if(vehid == 0)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w pojeŸdzie !");
		return 1;
	}
	if(!gVehData[vehid-1][VCBRadio])
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ten pojazd nie posaida CB Radia !");
		return 1;
	}
	if(!gVehData[vehid-1][VCBRadioStatus])
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] CB radio jest wy³¹czone !");
		return 1;
	}
	new string[128];
	if(sscanf(params, "s[128]", string))
	{
		SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] /cbv [text]" );
		return 1;
	}
	PlayerActionMessage(playerid, 15.0, "mówi przez CB radio");
	SendCBMessage(gVehData[vehid-1][VCBRadioChanel], string);
	return 1;
}

dcmd_onoffcb(playerid, params[])
{
	#pragma unused params
	new vehid = GetPlayerVehicleID(playerid);
	if(vehid == 0)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w pojeŸdzie !");
		return 1;
	}
	if(!gVehData[vehid-1][VCBRadio])
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ten pojazd nie posaida CB Radia !");
		return 1;
	}
	if(gVehData[vehid-1][VCBRadioStatus])
	{
		PlayerActionMessage(playerid, 15.0, "wy³¹cza CB radio");
		gVehData[vehid-1][VCBRadioStatus] = 0;
		SaveVehData(vehid-1, "CBRadioStatus");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Wy³¹czy³eœ CB w pojeŸdzie");
		return 1;
	}
	else
	{
		PlayerActionMessage(playerid, 15.0, "w³¹cza CB radio");
		gVehData[vehid-1][VCBRadioStatus] = 1;
		SaveVehData(vehid-1, "CBRadioStatus");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] W³¹czy³eœ CB w pojeŸdzie");
		return 1;
	}
}

dcmd_cb(playerid, params[])
{
	if(gPlayerData[playerid][pCharacterDying] || PlayerTazed[playerid])
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz teraz u¿yæ CB radia !");
		return 1;
	}
	if(gPlayerData[playerid][pMuted] && gPlayerData[playerid][pAdmin] == 0)
	{
		SendClientMessage(playerid, COLOR_LIGHTRED, "[INFO:] Nie mo¿esz u¿ywaæ tego chatu kiedy jesteœ uciszony !");
		return 1;
	}
	new chanel, string[128];
	if(sscanf(params, "ds[128]", chanel, string))
	{
		SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] /cb [kana³] [text]" );
		return 1;
	}
	new slot[MAX_PLAYER_ITEM_SLOT];
	PHaveItemEx(playerid, 3, 2, slot);
	new sended = 0;
	for(new i = 0; i < sizeof(slot); i++)
	{
		if(slot[i] && SlotParam1(playerid, i+1) && SlotParam2(playerid, i+1) == chanel)
			sended = 1;
	}
	if(!sended)
	{
		PHaveItemEx(playerid, 3, 13, slot);
		for(new i = 0; i < sizeof(slot); i++)
		{
			if(slot[i] && SlotParam1(playerid, i+1) && SlotParam2(playerid, i+1) == chanel)
				sended = 1;
		}
	}
	if(sended)
	{
		PlayerActionMessage(playerid, 15.0, "mówi przez krótkofalówke");
		SendCBMessage(chanel, string);	
		format(string, sizeof(string), "%s mówi: %s", GetPlayerNameEx(playerid), string);
		ProxDetector(20.0, playerid, string, COLOR_FADE1, COLOR_FADE2, COLOR_FADE3, COLOR_FADE4, COLOR_FADE5);
	}
	else
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] ¯adna krótkofalówka nie jest ustawiona na ten kanal lub nie jest w³¹czona !");
	return 1;
}

dcmd_b(playerid, params[])
{
	new string[256], string2[128], part1[75], part2[75];
	if( sscanf( params, "s[256]", string ) )
	{
		SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] /b [text]" );
		return 1;
	}
	if( gPlayerData[playerid][pMuted] && gPlayerData[playerid][pAdmin] == 0)
	{
		SendClientMessage(playerid, COLOR_LIGHTRED, "[INFO:] Nie mo¿esz u¿ywaæ tego chatu kiedy jesteœ uciszony !");
		return 1;
	}
	if(strlen(string) > 75)
	{
		strmid(part1, string, 0, 74 );
		strmid(part2, string, 74, 149 );
		
		format(string, sizeof(string), "[LOOC][%d][%s]: %s", playerid, gPlayerData[playerid][pOOCName], part1);
		ProxDetector(20.0, playerid, string, COLOR_FADE1,COLOR_FADE2,COLOR_FADE3,COLOR_FADE4,COLOR_FADE5);
		
		format(string2, sizeof(string2), "[LOOC][%d][%s]: %s", playerid, gPlayerData[playerid][pOOCName], part2);
		ProxDetector(20.0, playerid, string2, COLOR_FADE1,COLOR_FADE2,COLOR_FADE3,COLOR_FADE4,COLOR_FADE5);
		
		foreach(Player, i)
		{
			if(!gPlayerLogged[i])
			{
				continue;
			}
			
			if(!BigEar[i])
			{
				continue;
			}
			
			SendClientMessage(playerid, COLOR_WHITE, string);
			SendClientMessage(playerid, COLOR_WHITE, string2);
		}
	}
	else
	{
		format(string, sizeof(string), "[LOOC][%d][%s]: %s", playerid, gPlayerData[playerid][pOOCName], string);
		ProxDetector(20.0, playerid, string, COLOR_FADE1,COLOR_FADE2,COLOR_FADE3,COLOR_FADE4,COLOR_FADE5);
		
		foreach(Player, i)
		{
			if(!gPlayerLogged[i])
			{
				continue;
			}
			
			if(!BigEar[i])
			{
				continue;
			}
			
			SendClientMessage(playerid, COLOR_WHITE, string);
		}
	}
	return 1;
}

dcmd_k(playerid, params[])
{
	dcmd_krzycz(playerid, params);
	return 1;
}

dcmd_krzycz(playerid, params[])
{
	new string[256], part0[256], part1[80], part2[80];
	if(sscanf(params, "s[256]", part0))
	{
		SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] /krzycz [text]" );
		return 1;
	}
	if(strlen(part0) > 80)
	{
		strmid(part1, part0, 0, 79);
		strmid(part2, part0, 79, 159);
		
		format(string, sizeof(string), "%s krzyczy: %s !!!", GetPlayerNameEx(playerid), part1);
		printf("%s", string);
		ProxDetector(30.0, playerid, string, COLOR_WHITE, COLOR_WHITE, COLOR_WHITE, COLOR_FADE1, COLOR_FADE2);	
		
		format(string, sizeof(string), "%s krzyczy: %s !!!", GetPlayerNameEx(playerid), part2);
		printf("%s", string);
		ProxDetector(30.0, playerid, string, COLOR_WHITE, COLOR_WHITE, COLOR_WHITE, COLOR_FADE1, COLOR_FADE2);	
	}
	else
	{
		format(string, sizeof(string), "%s krzyczy: %s !!!", GetPlayerNameEx(playerid), part0);
		printf("%s", string);
		ProxDetector(30.0, playerid, string, COLOR_WHITE, COLOR_WHITE, COLOR_WHITE, COLOR_FADE1, COLOR_FADE2);
	}
	return 1;
}

dcmd_ao(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] <= 0)
		return 0;
	new string[256], part0[256], part1[80], part2[80];
	if(sscanf(params, "s[256]", part0))
	{
		SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] /ao [text]" );
		return 1;
	}
	if(strlen(part0) > 80)
	{
		strmid(part1, part0, 0, 79);
		strmid(part2, part0, 79, 159);
		format(string, sizeof(string), "[AOOC-%d][%d][%s]: %s", gPlayerData[playerid][pOOCChanell], playerid, gPlayerData[playerid][pOOCName], part1);
		printf("%s", string);
		OOCLog(string);
		foreach(Player, i)
		{
			if((gPlayerData[i][pOOCStatus] && gPlayerLogged[i] && (gPlayerData[i][pOOCChanell] == gPlayerData[playerid][pOOCChanell]) && gPlayerData[i][pQuiz]) || BigEar[i])
				SendClientMessage(i, 0x62B382AA, string);
		}		
		format(string, sizeof(string), "[AOOC-%d][%d][%s]: %s", gPlayerData[playerid][pOOCChanell], playerid, gPlayerData[playerid][pOOCName], part2);
		printf("%s", string);
		OOCLog(string);
		foreach(Player, i)
		{
			if((gPlayerData[i][pOOCStatus] && gPlayerLogged[i] && (gPlayerData[i][pOOCChanell] == gPlayerData[playerid][pOOCChanell]) && gPlayerData[i][pQuiz]) || BigEar[i])
				SendClientMessage(i, 0x62B382AA, string);
		}		
	}
	else
	{
		format(string, sizeof(string), "[AOOC-%d][%d][%s]: %s", gPlayerData[playerid][pOOCChanell], playerid, gPlayerData[playerid][pOOCName], part0);
		printf("%s", string);
		OOCLog(string);
		foreach(Player, i)
		{
			if((gPlayerData[i][pOOCStatus] && gPlayerLogged[i] && (gPlayerData[i][pOOCChanell] == gPlayerData[playerid][pOOCChanell]) && gPlayerData[i][pQuiz]) || BigEar[i])
				SendClientMessage(i, 0x62B382AA, string);
		}
	}
	return 1;
}

dcmd_o(playerid, params[])
{
	new string[256], part0[256], part1[80], part2[80];
	if(sscanf( params, "s[256]", part0))
	{
		SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] /o [text]");
		return 1;
	}
	if(noooc && gPlayerData[playerid][pAdmin] < 1 && gPlayerData[playerid][pModerator] == 0)
	{
		SendClientMessage(playerid, COLOR_GRAD2, "[INFO:] Chat OOC zosta³ wy³¹czony przez administratora !");
		return 1;
	}
	if(gPlayerData[playerid][pMuted] && gPlayerData[playerid][pAdmin] == 0)
	{
		SendClientMessage(playerid, COLOR_LIGHTRED, "[INFO:] Nie mo¿esz u¿ywaæ tego chatu kiedy jesteœ uciszony !");
		return 1;
	}
	if(!gPlayerData[playerid][pOOCStatus])
	{
		SendClientMessage(playerid, COLOR_RED, "[UWAGA:] Masz wy³¹czone otrzymywanie wiadomoœci OOC !");
		return 1;
	}
	if( strlen(part0) > 80 )
	{
		strmid( part1, part0, 0, 79 );
		strmid( part2, part0, 79, 159 );
		format( string, sizeof(string), "[OOC-%d][%d][%s]: %s", gPlayerData[playerid][pOOCChanell], playerid, gPlayerData[playerid][pOOCName], part1 );
		foreach(Player, i)
		{
			if((gPlayerData[i][pOOCStatus] && gPlayerLogged[i] && gPlayerData[i][pOOCChanell] == gPlayerData[playerid][pOOCChanell] && gPlayerData[i][pQuiz]) || BigEar[i])
				SendClientMessage(i, COLOR_OOC, string);
		}
		printf("%s", string);
		OOCLog(string);
		format( string, sizeof(string), "[OOC-%d][%d][%s]: %s", gPlayerData[playerid][pOOCChanell], playerid, gPlayerData[playerid][pOOCName], part2 );
		foreach(Player, i)
		{
			if((gPlayerData[i][pOOCStatus] && gPlayerLogged[i] && gPlayerData[i][pOOCChanell] == gPlayerData[playerid][pOOCChanell] && gPlayerData[i][pQuiz]) || BigEar[i])
				SendClientMessage(i, COLOR_OOC, string);
		}
		printf("%s", string);
		OOCLog(string);
	}
	else
	{
		format( string, sizeof(string), "[OOC-%d][%d][%s]: %s", gPlayerData[playerid][pOOCChanell], playerid, gPlayerData[playerid][pOOCName], part0 );
		foreach(Player, i)
		{
			if((gPlayerData[i][pOOCStatus] && gPlayerLogged[i] && gPlayerData[i][pOOCChanell] == gPlayerData[playerid][pOOCChanell] && gPlayerData[i][pQuiz]) || BigEar[i])
				SendClientMessage(i, COLOR_OOC, string);
		}
		printf("%s", string);
		OOCLog(string);
	}
	return 1;
}

dcmd_me(playerid, params[])
{
	new string[256];
	if( sscanf( params, "s[256]", string ) )
	{
		SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] /ja [text]" );
		return 1;
	}
	if( gPlayerData[playerid][pMuted] && gPlayerData[playerid][pAdmin] == 0)
	{
		SendClientMessage(playerid, COLOR_LIGHTRED, "[INFO:] Nie mo¿esz u¿ywaæ tego chatu kiedy jesteœ uciszony !");
		return 1;
	}
	PlayerActionMessage( playerid, 15.0, string );
	gPlayerData[playerid][pRPCount]++;
	SavePlayerData(playerid, "RPCount");
	return 1;
}

dcmd_ja(playerid, params[])
{
	new string[256];
	if( sscanf( params, "s[256]", string ) )
	{
		SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] /ja [text]" );
		return 1;
	}
	if( gPlayerData[playerid][pMuted] && gPlayerData[playerid][pAdmin] == 0)
	{
		SendClientMessage(playerid, COLOR_LIGHTRED, "[INFO:] Nie mo¿esz u¿ywaæ tego chatu kiedy jesteœ uciszony !");
		return 1;
	}
	if( !gPlayerData[playerid][pFirstAction] )
	{
		gPlayerData[playerid][pFirstAction] = 1;
		SavePlayerData( playerid, "FirstAction" );
		// AddExpPoint(playerid);
		SendClientMessage( playerid, COLOR_GREEN, "[INFO:] Pierwszy raz u¿y³eœ akcji RP !" );
	}
	PlayerActionMessage( playerid, 15.0, string );
	TalkLog(string);
	gPlayerData[playerid][pRPCount]++;
	SavePlayerData(playerid, "RPCount");
	return 1;
}

dcmd_do(playerid, params[])
{
	new string[256], part0[256], part1[87], part2[87];
	new Year, Month, Day, Hour, Minute, Second;
	if( sscanf( params, "s[256]", part0 ) )
	{
		SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] /ja [text]" );
		return 1;
	}
	if( gPlayerData[playerid][pMuted] && gPlayerData[playerid][pAdmin] == 0)
	{
		SendClientMessage(playerid, COLOR_LIGHTRED, "[INFO:] Nie mo¿esz u¿ywaæ tego chatu kiedy jesteœ uciszony !");
		return 1;
	}
	getdate(Year, Month, Day);
	gettime(Hour, Minute, Second);
	if( strlen(part0) > 87 )
	{
		strmid( part1, part0, 0, 86 );
		strmid( part2, part0, 86, 173 );
		format( string, sizeof(string), "* %s (( %s ))", GetPlayerNameEx(playerid), part1 );
		ProxDetector(15.0, playerid, string, COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE);
		PlayerActionLog(string);
		format( string, sizeof(string), "* %s (( %s ))", GetPlayerNameEx(playerid), part2 );
		ProxDetector(15.0, playerid, string, COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE);
		PlayerActionLog(string);
		TalkLog(string);
	}
	else
	{
		format( string, sizeof(string), "* %s (( %s ))", GetPlayerNameEx(playerid), part0 );
		ProxDetector(15.0, playerid, string, COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE);
		PlayerActionLog(string);
		TalkLog(string);
	}
	if( !gPlayerData[playerid][pFirstAction] )
	{
		gPlayerData[playerid][pFirstAction] = 1;
		SavePlayerData( playerid, "FirstAction" );
		// AddExpPoint(playerid);
		SendClientMessage( playerid, COLOR_GREEN, "[INFO:] Pierwszy raz u¿y³eœ akcji RP !" );
	}
	gPlayerData[playerid][pRPCount]++;
	SavePlayerData(playerid, "RPCount");
	return 1;
}

dcmd_gotofactorytakecp(playerid, params[])
{
	#pragma unused params
	if( gPlayerData[playerid][pAdmin] < 4 )
		return 0;
	new vehicleid = GetPlayerVehicleID(playerid);
	if(vehicleid == 0)
		SetPlayerToPos(playerid, WFactoryLegal[WFactoryCPPartTakeX], WFactoryLegal[WFactoryCPPartTakeY], WFactoryLegal[WFactoryCPPartTakeZ]);
	else
		SetVehicleToPos(vehicleid, WFactoryLegal[WFactoryCPPartTakeX], WFactoryLegal[WFactoryCPPartTakeY], WFactoryLegal[WFactoryCPPartTakeZ]);
	SetPlayerInterior(playerid, WFactoryLegal[WFactoryCPPartTakeInt]);
	SetPlayerVirtualWorld(playerid, WFactoryLegal[WFactoryCPPartTakeWV]);
	return 1;
}

dcmd_factorytakecp(playerid, params[])
{
	#pragma unused params
	if( gPlayerData[playerid][pAdmin] < 4 )
		return 0;
	new Float:px, Float:py, Float:pz;
	GetPlayerPos( playerid, px, py, pz );
	WFactoryLegal[WFactoryCPPartTakeX] = px;
	WFactoryLegal[WFactoryCPPartTakeY] = py;
	WFactoryLegal[WFactoryCPPartTakeZ] = pz;
	WFactoryLegal[WFactoryCPPartTakeWV] = GetPlayerVirtualWorld( playerid );
	WFactoryLegal[WFactoryCPPartTakeInt] = GetPlayerInterior( playerid );
	SaveWFactoryData( "WFactoryCPPartTakeX" );
	SaveWFactoryData( "WFactoryCPPartTakeY" );
	SaveWFactoryData( "WFactoryCPPartTakeZ" );
	SaveWFactoryData( "WFactoryCPPartTakeWV" );
	SaveWFactoryData( "WFactoryCPPartTakeInt" );
	DestroyDynamicCP(WFactoryLegal[WFactoryCPPartTakeID]);
	WFactoryLegal[WFactoryCPPartTakeID] = CreateDynamicCP( WFactoryLegal[WFactoryCPPartTakeX], WFactoryLegal[WFactoryCPPartTakeY], WFactoryLegal[WFactoryCPPartTakeZ], 2.0 );
	return 1;
}

dcmd_factorysetup1(playerid, params[])
{
	#pragma unused params
	if( gPlayerData[playerid][pAdmin] < 4 )
		return 0;
	new Float:px, Float:py, Float:pz;
	GetPlayerPos( playerid, px, py, pz );
	WFactoryLegal[WFactoryCPPartSetup1X] = px;
	WFactoryLegal[WFactoryCPPartSetup1Y] = py;
	WFactoryLegal[WFactoryCPPartSetup1Z] = pz;
	SaveWFactoryData( "WFactoryCPPartSetup1X" );
	SaveWFactoryData( "WFactoryCPPartSetup1Y" );
	SaveWFactoryData( "WFactoryCPPartSetup1Z" );
	DestroyDynamicCP(WFactoryLegal[WFactoryCPPartSetup1ID]);
	WFactoryLegal[WFactoryCPPartSetup1ID] = CreateDynamicCP( WFactoryLegal[WFactoryCPPartSetup1X], WFactoryLegal[WFactoryCPPartSetup1Y], WFactoryLegal[WFactoryCPPartSetup1Z], 2.0 );
	return 1;
}

dcmd_factorysetup2(playerid, params[])
{
	#pragma unused params
	if( gPlayerData[playerid][pAdmin] < 4 )
		return 0;
	new Float:px, Float:py, Float:pz;
	GetPlayerPos( playerid, px, py, pz );
	WFactoryLegal[WFactoryCPPartSetup2X] = px;
	WFactoryLegal[WFactoryCPPartSetup2Y] = py;
	WFactoryLegal[WFactoryCPPartSetup2Z] = pz;
	SaveWFactoryData( "WFactoryCPPartSetup2X" );
	SaveWFactoryData( "WFactoryCPPartSetup2Y" );
	SaveWFactoryData( "WFactoryCPPartSetup2Z" );
	DestroyDynamicCP(WFactoryLegal[WFactoryCPPartSetup2ID]);
	WFactoryLegal[WFactoryCPPartSetup2ID] = CreateDynamicCP( WFactoryLegal[WFactoryCPPartSetup2X], WFactoryLegal[WFactoryCPPartSetup2Y], WFactoryLegal[WFactoryCPPartSetup2Z], 2.0 );
	return 1;
}

dcmd_factorysetup3(playerid, params[])
{
	#pragma unused params
	if( gPlayerData[playerid][pAdmin] < 4 )
		return 0;
	new Float:px, Float:py, Float:pz;
	GetPlayerPos( playerid, px, py, pz );
	WFactoryLegal[WFactoryCPPartSetup3X] = px;
	WFactoryLegal[WFactoryCPPartSetup3Y] = py;
	WFactoryLegal[WFactoryCPPartSetup3Z] = pz;
	SaveWFactoryData( "WFactoryCPPartSetup3X" );
	SaveWFactoryData( "WFactoryCPPartSetup3Y" );
	SaveWFactoryData( "WFactoryCPPartSetup3Z" );
	DestroyDynamicCP(WFactoryLegal[WFactoryCPPartSetup3ID]);
	WFactoryLegal[WFactoryCPPartSetup3ID] = CreateDynamicCP( WFactoryLegal[WFactoryCPPartSetup3X], WFactoryLegal[WFactoryCPPartSetup3Y], WFactoryLegal[WFactoryCPPartSetup3Z], 2.0 );
	return 1;
}

dcmd_factorysetup4(playerid, params[])
{
	#pragma unused params
	if( gPlayerData[playerid][pAdmin] < 4 )
		return 0;
	new Float:px, Float:py, Float:pz;
	GetPlayerPos( playerid, px, py, pz );
	WFactoryLegal[WFactoryCPPartSetup4X] = px;
	WFactoryLegal[WFactoryCPPartSetup4Y] = py;
	WFactoryLegal[WFactoryCPPartSetup4Z] = pz;
	SaveWFactoryData( "WFactoryCPPartSetup4X" );
	SaveWFactoryData( "WFactoryCPPartSetup4Y" );
	SaveWFactoryData( "WFactoryCPPartSetup4Z" );
	DestroyDynamicCP(WFactoryLegal[WFactoryCPPartSetup4ID]);
	WFactoryLegal[WFactoryCPPartSetup4ID] = CreateDynamicCP( WFactoryLegal[WFactoryCPPartSetup4X], WFactoryLegal[WFactoryCPPartSetup4Y], WFactoryLegal[WFactoryCPPartSetup4Z], 2.0 );
	return 1;
}

dcmd_factorysetup5(playerid, params[])
{
	#pragma unused params
	if( gPlayerData[playerid][pAdmin] < 4 )
		return 0;
	new Float:px, Float:py, Float:pz;
	GetPlayerPos( playerid, px, py, pz );
	WFactoryLegal[WFactoryCPPartSetup5X] = px;
	WFactoryLegal[WFactoryCPPartSetup5Y] = py;
	WFactoryLegal[WFactoryCPPartSetup5Z] = pz;
	SaveWFactoryData( "WFactoryCPPartSetup5X" );
	SaveWFactoryData( "WFactoryCPPartSetup5Y" );
	SaveWFactoryData( "WFactoryCPPartSetup5Z" );
	DestroyDynamicCP(WFactoryLegal[WFactoryCPPartSetup5ID]);
	WFactoryLegal[WFactoryCPPartSetup5ID] = CreateDynamicCP( WFactoryLegal[WFactoryCPPartSetup5X], WFactoryLegal[WFactoryCPPartSetup5Y], WFactoryLegal[WFactoryCPPartSetup5Z], 2.0 );
	return 1;
}

dcmd_factorysetup6(playerid, params[])
{
	#pragma unused params
	if( gPlayerData[playerid][pAdmin] < 4 )
		return 0;
	new Float:px, Float:py, Float:pz;
	GetPlayerPos( playerid, px, py, pz );
	WFactoryLegal[WFactoryCPPartSetup6X] = px;
	WFactoryLegal[WFactoryCPPartSetup6Y] = py;
	WFactoryLegal[WFactoryCPPartSetup6Z] = pz;
	SaveWFactoryData( "WFactoryCPPartSetup6X" );
	SaveWFactoryData( "WFactoryCPPartSetup6Y" );
	SaveWFactoryData( "WFactoryCPPartSetup6Z" );
	DestroyDynamicCP(WFactoryLegal[WFactoryCPPartSetup6ID]);
	WFactoryLegal[WFactoryCPPartSetup6ID] = CreateDynamicCP( WFactoryLegal[WFactoryCPPartSetup6X], WFactoryLegal[WFactoryCPPartSetup6Y], WFactoryLegal[WFactoryCPPartSetup6Z], 2.0 );
	return 1;
}

dcmd_afactorylegalcmds(playerid, params[])
{
	#pragma unused params
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "================================================================================================================================");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[ADMIN:] /factorytakecp - /gotofactorytakecp - /factorysetup1-6 - /factoryasetup1-6 - /fillfactoryparts - /buyfactorycp");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "================================================================================================================================");
	return 1;
}

dcmd_afactorycmds(playerid, params[])
{
	#pragma unused params
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "================================================================================================================================");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[ADMIN:] /rfactory - /gotofactorytakecpi");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "================================================================================================================================");
	return 1;
}

dcmd_fillfactoryparts(playerid, params[])
{
	#pragma unused params
	#pragma unused playerid
	WFactoryLegalLight[WFactoryPistolS1Part1] += 100;
	WFactoryLegalLight[WFactoryPistolS1Part2] += 100;
	WFactoryLegalLight[WFactoryPistolS1Part3] += 100;
	WFactoryLegalLight[WFactoryPistolS2Part1] += 100;
	WFactoryLegalLight[WFactoryPistolS2Part2] += 100;
	WFactoryLegalLight[WFactoryPistolS2Part3] += 100;
	WFactoryLegalLight[WFactoryPistolS3Part1] += 100;
	WFactoryLegalLight[WFactoryPistolS3Part2] += 100;
	WFactoryLegalLight[WFactoryPistolS3Part3] += 100;
	WFactoryLegalLight[WFactoryPistolS3Part4] += 100;
	WFactoryLegalLight[WFactoryPistolPart4] += 100;
	WFactoryLegalLight[WFactoryPistolPart5] += 100;
	WFactoryLegalLight[WFactoryPistolPart6] += 100;
	WFactoryLegalHeavy[WFactoryRifleS1Part1] += 100;
	WFactoryLegalHeavy[WFactoryRifleS1Part2] += 100;
	WFactoryLegalHeavy[WFactoryRifleS2Part1] += 100;
	WFactoryLegalHeavy[WFactoryRifleS2Part2] += 100;
	WFactoryLegalHeavy[WFactoryRifleS2Part3] += 100;
	WFactoryLegalHeavy[WFactoryRifleS3Part1] += 100;
	WFactoryLegalHeavy[WFactoryRifleS3Part2] += 100;
	WFactoryLegalHeavy[WFactoryRifleS3Part3] += 100;
	WFactoryLegalHeavy[WFactoryRifleS3Part4] += 100;
	WFactoryLegalHeavy[WFactoryRiflePart4] += 100;
	WFactoryLegalHeavy[WFactoryRiflePart5] += 100;
	WFactoryLegalHeavy[WFactoryRiflePart6] += 100;
	WFactoryLegalHeavy[WFactoryRiflePart7] += 100;
	WFactoryLegalHeavy[WFactoryRifleS6Part1] += 100;
	WFactoryLegalHeavy[WFactoryRifleS6Part2] += 100;
	WFactoryLegalLight[WFactoryAmmoPart1a] += 100;
	WFactoryLegalLight[WFactoryAmmoPart2a] += 100;
	WFactoryLegalLight[WFactoryAmmoPart3a] += 100;
	WFactoryLegalLight[WFactoryAmmoPart4a] += 100;
	WFactoryLegalLight[WFactoryAmmoPart1b] += 100;
	WFactoryLegalLight[WFactoryAmmoPart2b] += 100;
	WFactoryLegalLight[WFactoryAmmoPart3b] += 100;
	WFactoryLegalLight[WFactoryAmmoPart4b] += 100;
	WFactoryLegalLight[WFactoryAmmoPart1c] += 100;
	WFactoryLegalLight[WFactoryAmmoPart2c] += 100;
	WFactoryLegalLight[WFactoryAmmoPart3c] += 100;
	WFactoryLegalLight[WFactoryAmmoPart4c] += 100;
	WFactoryLegalLight[WFactoryAmmoPart1d] += 100;
	WFactoryLegalLight[WFactoryAmmoPart2d] += 100;
	WFactoryLegalLight[WFactoryAmmoPart3d] += 100;
	WFactoryLegalLight[WFactoryAmmoPart4d] += 100;
	WFactoryLegalLight[WFactoryAmmoPart1e] += 100;
	WFactoryLegalLight[WFactoryAmmoPart2e] += 100;
	WFactoryLegalLight[WFactoryAmmoPart3e] += 100;
	WFactoryLegalLight[WFactoryAmmoPart4e] += 100;
	SaveWFactoryData( "WFactoryPistolS1Part1" );
	SaveWFactoryData( "WFactoryPistolS1Part2" );
	SaveWFactoryData( "WFactoryPistolS1Part3" );
	SaveWFactoryData( "WFactoryPistolS2Part1" );
	SaveWFactoryData( "WFactoryPistolS2Part2" );
	SaveWFactoryData( "WFactoryPistolS2Part3" );
	SaveWFactoryData( "WFactoryPistolS3Part1" );
	SaveWFactoryData( "WFactoryPistolS3Part2" );
	SaveWFactoryData( "WFactoryPistolS3Part3" );
	SaveWFactoryData( "WFactoryPistolS3Part4" );
	SaveWFactoryData( "WFactoryPistolPart4" );
	SaveWFactoryData( "WFactoryPistolPart5" );
	SaveWFactoryData( "WFactoryPistolPart6" );
	SaveWFactoryData( "WFactoryRifleS1Part1" );
	SaveWFactoryData( "WFactoryRifleS1Part2" );
	SaveWFactoryData( "WFactoryRifleS2Part1" );
	SaveWFactoryData( "WFactoryRifleS2Part2" );
	SaveWFactoryData( "WFactoryRifleS2Part3" );
	SaveWFactoryData( "WFactoryRifleS3Part1" );
	SaveWFactoryData( "WFactoryRifleS3Part2" );
	SaveWFactoryData( "WFactoryRifleS3Part3" );
	SaveWFactoryData( "WFactoryRifleS3Part4" );
	SaveWFactoryData( "WFactoryRiflePart4" );
	SaveWFactoryData( "WFactoryRiflePart5" );
	SaveWFactoryData( "WFactoryRiflePart6" );
	SaveWFactoryData( "WFactoryRiflePart7" );
	SaveWFactoryData( "WFactoryRifleS6Part1" );
	SaveWFactoryData( "WFactoryRifleS6Part2" );
	SaveWFactoryData( "WFactoryAmmoPart1a" );
	SaveWFactoryData( "WFactoryAmmoPart2a" );
	SaveWFactoryData( "WFactoryAmmoPart3a" );
	SaveWFactoryData( "WFactoryAmmoPart4a" );
	SaveWFactoryData( "WFactoryAmmoPart1b" );
	SaveWFactoryData( "WFactoryAmmoPart2b" );
	SaveWFactoryData( "WFactoryAmmoPart3b" );
	SaveWFactoryData( "WFactoryAmmoPart4b" );
	SaveWFactoryData( "WFactoryAmmoPart1c" );
	SaveWFactoryData( "WFactoryAmmoPart2c" );
	SaveWFactoryData( "WFactoryAmmoPart3c" );
	SaveWFactoryData( "WFactoryAmmoPart4c" );
	SaveWFactoryData( "WFactoryAmmoPart1d" );
	SaveWFactoryData( "WFactoryAmmoPart2d" );
	SaveWFactoryData( "WFactoryAmmoPart3d" );
	SaveWFactoryData( "WFactoryAmmoPart4d" );
	SaveWFactoryData( "WFactoryAmmoPart1e" );
	SaveWFactoryData( "WFactoryAmmoPart2e" );
	SaveWFactoryData( "WFactoryAmmoPart3e" );
	SaveWFactoryData( "WFactoryAmmoPart4e" );
	DynamicFactions[FACTIONID_GOVERNMENT][fBank] -= 1167000;
	SaveFData( FACTIONID_GOVERNMENT, "Bank" );
	return 1;
}

dcmd_factoryasetup1(playerid, params[])
{
	#pragma unused params
	if( gPlayerData[playerid][pAdmin] < 4 )
		return 0;
	new Float:px, Float:py, Float:pz;
	GetPlayerPos( playerid, px, py, pz );
	WFactoryLegal[WFactoryCPAmmoSetup1X] = px;
	WFactoryLegal[WFactoryCPAmmoSetup1Y] = py;
	WFactoryLegal[WFactoryCPAmmoSetup1Z] = pz;
	SaveWFactoryData( "WFactoryCPAmmoSetup1X" );
	SaveWFactoryData( "WFactoryCPAmmoSetup1Y" );
	SaveWFactoryData( "WFactoryCPAmmoSetup1Z" );
	DestroyDynamicCP(WFactoryLegal[WFactoryCPAmmoSetup1ID]);
	WFactoryLegal[WFactoryCPAmmoSetup1ID] = CreateDynamicCP( WFactoryLegal[WFactoryCPAmmoSetup1X], WFactoryLegal[WFactoryCPAmmoSetup1Y], WFactoryLegal[WFactoryCPAmmoSetup1Z], 2.0, WFactoryLegal[WFactoryCPPartTakeWV],  WFactoryLegal[WFactoryCPPartTakeInt]);
	return 1;
}

dcmd_factoryasetup2(playerid, params[])
{
	#pragma unused params
	if( gPlayerData[playerid][pAdmin] < 4 )
		return 0;
	new Float:px, Float:py, Float:pz;
	GetPlayerPos( playerid, px, py, pz );
	WFactoryLegal[WFactoryCPAmmoSetup2X] = px;
	WFactoryLegal[WFactoryCPAmmoSetup2Y] = py;
	WFactoryLegal[WFactoryCPAmmoSetup2Z] = pz;
	SaveWFactoryData( "WFactoryCPAmmoSetup2X" );
	SaveWFactoryData( "WFactoryCPAmmoSetup2Y" );
	SaveWFactoryData( "WFactoryCPAmmoSetup2Z" );
	DestroyDynamicCP(WFactoryLegal[WFactoryCPAmmoSetup2ID]);
	WFactoryLegal[WFactoryCPAmmoSetup2ID] = CreateDynamicCP( WFactoryLegal[WFactoryCPAmmoSetup2X], WFactoryLegal[WFactoryCPAmmoSetup2Y], WFactoryLegal[WFactoryCPAmmoSetup2Z], 2.0, WFactoryLegal[WFactoryCPPartTakeWV],  WFactoryLegal[WFactoryCPPartTakeInt]);
	return 1;
}

dcmd_factoryasetup3(playerid, params[])
{
	#pragma unused params
	if( gPlayerData[playerid][pAdmin] < 4 )
		return 0;
	new Float:px, Float:py, Float:pz;
	GetPlayerPos( playerid, px, py, pz );
	WFactoryLegal[WFactoryCPAmmoSetup3X] = px;
	WFactoryLegal[WFactoryCPAmmoSetup3Y] = py;
	WFactoryLegal[WFactoryCPAmmoSetup3Z] = pz;
	SaveWFactoryData( "WFactoryCPAmmoSetup3X" );
	SaveWFactoryData( "WFactoryCPAmmoSetup3Y" );
	SaveWFactoryData( "WFactoryCPAmmoSetup3Z" );
	DestroyDynamicCP(WFactoryLegal[WFactoryCPAmmoSetup3ID]);
	WFactoryLegal[WFactoryCPAmmoSetup3ID] = CreateDynamicCP( WFactoryLegal[WFactoryCPAmmoSetup3X], WFactoryLegal[WFactoryCPAmmoSetup3Y], WFactoryLegal[WFactoryCPAmmoSetup3Z], 2.0, WFactoryLegal[WFactoryCPPartTakeWV],  WFactoryLegal[WFactoryCPPartTakeInt]);
	return 1;
}

dcmd_factoryasetup4(playerid, params[])
{
	#pragma unused params
	if( gPlayerData[playerid][pAdmin] < 4 )
		return 0;
	new Float:px, Float:py, Float:pz;
	GetPlayerPos( playerid, px, py, pz );
	WFactoryLegal[WFactoryCPAmmoSetup4X] = px;
	WFactoryLegal[WFactoryCPAmmoSetup4Y] = py;
	WFactoryLegal[WFactoryCPAmmoSetup4Z] = pz;
	SaveWFactoryData( "WFactoryCPAmmoSetup4X" );
	SaveWFactoryData( "WFactoryCPAmmoSetup4Y" );
	SaveWFactoryData( "WFactoryCPAmmoSetup4Z" );
	DestroyDynamicCP(WFactoryLegal[WFactoryCPAmmoSetup4ID]);
	WFactoryLegal[WFactoryCPAmmoSetup4ID] = CreateDynamicCP( WFactoryLegal[WFactoryCPAmmoSetup4X], WFactoryLegal[WFactoryCPAmmoSetup4Y], WFactoryLegal[WFactoryCPAmmoSetup4Z], 2.0, WFactoryLegal[WFactoryCPPartTakeWV],  WFactoryLegal[WFactoryCPPartTakeInt]);
	return 1;
}

dcmd_factoryasetup5(playerid, params[])
{
	#pragma unused params
	if( gPlayerData[playerid][pAdmin] < 4 )
		return 0;
	new Float:px, Float:py, Float:pz;
	GetPlayerPos( playerid, px, py, pz );
	WFactoryLegal[WFactoryCPAmmoSetup5X] = px;
	WFactoryLegal[WFactoryCPAmmoSetup5Y] = py;
	WFactoryLegal[WFactoryCPAmmoSetup5Z] = pz;
	SaveWFactoryData( "WFactoryCPAmmoSetup5X" );
	SaveWFactoryData( "WFactoryCPAmmoSetup5Y" );
	SaveWFactoryData( "WFactoryCPAmmoSetup5Z" );
	DestroyDynamicCP(WFactoryLegal[WFactoryCPAmmoSetup5ID]);
	WFactoryLegal[WFactoryCPAmmoSetup5ID] = CreateDynamicCP( WFactoryLegal[WFactoryCPAmmoSetup5X], WFactoryLegal[WFactoryCPAmmoSetup5Y], WFactoryLegal[WFactoryCPAmmoSetup5Z], 2.0, WFactoryLegal[WFactoryCPPartTakeWV],  WFactoryLegal[WFactoryCPPartTakeInt]);
	return 1;
}

dcmd_factoryasetup6(playerid, params[])
{
	#pragma unused params
	if( gPlayerData[playerid][pAdmin] < 4 )
		return 0;
	new Float:px, Float:py, Float:pz;
	GetPlayerPos( playerid, px, py, pz );
	WFactoryLegal[WFactoryCPAmmoSetup6X] = px;
	WFactoryLegal[WFactoryCPAmmoSetup6Y] = py;
	WFactoryLegal[WFactoryCPAmmoSetup6Z] = pz;
	SaveWFactoryData( "WFactoryCPAmmoSetup6X" );
	SaveWFactoryData( "WFactoryCPAmmoSetup6Y" );
	SaveWFactoryData( "WFactoryCPAmmoSetup6Z" );
	DestroyDynamicCP(WFactoryLegal[WFactoryCPAmmoSetup6ID]);
	WFactoryLegal[WFactoryCPAmmoSetup6ID] = CreateDynamicCP( WFactoryLegal[WFactoryCPAmmoSetup6X], WFactoryLegal[WFactoryCPAmmoSetup6Y], WFactoryLegal[WFactoryCPAmmoSetup6Z], 2.0, WFactoryLegal[WFactoryCPPartTakeWV],  WFactoryLegal[WFactoryCPPartTakeInt]);
	return 1;
}

dcmd_gotofduty(playerid, params[])
{
	if( gPlayerData[playerid][pAdmin] < 4 )
		return 0;
	new fID;
	if( sscanf( params, "d", fID ) )
	{
		SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] /gotofduty [fID]" );
		return 1;
	}
	SetPlayerToPos( playerid, DynamicFactions[fID][fXDuty], DynamicFactions[fID][fYDuty], DynamicFactions[fID][fZDuty] );
	SetPlayerVirtualWorld( playerid, DynamicFactions[fID][fWorldDuty] );
	SetPlayerInterior( playerid, DynamicFactions[fID][fInteriorDuty] );
	return 1;
}

dcmd_fillfactionweapons(playerid, params[])
{
	if( gPlayerData[playerid][pAdmin] != 5 )
		return 0;
	new fID;
	if( sscanf( params, "d", fID ) )
	{
		SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] /fillfactionweapons [fID]" );
		return 1;
	}
	DynamicFactions[fID][WFactory9MM] += 10;
	DynamicFactions[fID][WFactory9MMAmmo] += 1000;
	DynamicFactions[fID][WFactoryAK47] += 10;
	DynamicFactions[fID][WFactoryM4] += 10;
	DynamicFactions[fID][WFactory762MMAmmo] += 1000;
	return 1;
}

dcmd_awfworkerjobpos(playerid, params[])
{
	#pragma unused params
	if( gPlayerData[playerid][pAdmin] < 4 )
		return 0;
	new Float:x,Float:y,Float:z;
	GetPlayerPos(playerid, x, y, z);
	new Float:angle;
	GetPlayerFacingAngle(playerid, angle);
	WFWorkerJob[TakeJobX] = x;
	WFWorkerJob[TakeJobY] = y;
	WFWorkerJob[TakeJobZ] = z;
	WFWorkerJob[TakeJobWorld] = GetPlayerVirtualWorld(playerid);
	WFWorkerJob[TakeJobInterior] = GetPlayerInterior(playerid);
	WFWorkerJob[TakeJobAngle] = angle;
	DestroyDynamicPickup(WFWorkerJob[TakeJobPickupID]);
	WFWorkerJob[TakeJobPickupID] = CreateDynamicPickup(1239,1,WFWorkerJob[TakeJobX],WFWorkerJob[TakeJobY],WFWorkerJob[TakeJobZ]);
	SaveWFactoryJob();
	SendClientMessage(playerid, COLOR_ADMINCMD, "You have successfully set the Weapon Factory Worker Job.");
	return 1;
}

dcmd_radiob(playerid, params[])
{
	new channelID;
	for( new i = 0; i < sizeof(Businesses); i++ )
	{
		if( PlayerToPoint(150.0, playerid, Businesses[i][ExitX], Businesses[i][ExitY], Businesses[i][ExitZ]) && i == GetPlayerVirtualWorld(playerid) )
		{
			if( !Businesses[i][BRadio1Bought] )
			{
				SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz radia w tym biznesie !");
				return 1;
			}
			if( !PlayerToPoint( 2.0, playerid, Businesses[i][BRadio1X], Businesses[i][BRadio1Y], Businesses[i][BRadio1Z]) )
			{
				SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ obok radia !");
				return 1;
			}
			if( sscanf( params, "d", channelID ) )
			{
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] /radiob [nr stacji]");
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2, RADIO_CHANNELS);
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2, RADIO_CHANNELS2);
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2, RADIO_CHANNELS3);
				return 1;
			}
			if(channelID > 18 || channelID < 1)
			{
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] Niew³aœciwy nr kana³u");
				return 1;
			}
			if( Businesses[i][BRadio1On] )
				PlayerActionMessage(playerid,15.0,"zmienia kana³");
			else
			{
				PlayerActionMessage(playerid,15.0,"w³¹cza radio");
				Businesses[i][BRadio1On] = 1;
				SaveBizData( i, "BRadio1On" );
			}
			Businesses[i][BRadio1Ch] = channelID;
			SaveBizData( i, "BRadio1Ch" );
			PlayBizRadio( i, channelID, GetPlayerVirtualWorld(playerid) );
			return 1;
		}
	}
	SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie znajdujesz siê w biznesie !");
	return 1;
}

dcmd_radiod(playerid, params[])
{
	new channelID;
	for( new i = 0; i < sizeof(Houses); i++ )
	{
		if( PlayerToPoint(150.0, playerid, Houses[i][ExitX], Houses[i][ExitY], Houses[i][ExitZ]) && i == GetPlayerVirtualWorld(playerid) )
		{
			if( !Houses[i][HRadio1Bought] )
			{
				SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz radia w tym domu !");
				return 1;
			}
			if( !PlayerToPoint( 2.0, playerid, Houses[i][HRadio1X], Houses[i][HRadio1Y], Houses[i][HRadio1Z]) )
			{
				SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ obok radia !");
				return 1;
			}
			if( sscanf( params, "d", channelID ) )
			{
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] /radiod [nr stacji]");
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2, RADIO_CHANNELS);
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2, RADIO_CHANNELS2);
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2, RADIO_CHANNELS3);
				return 1;
			}
			if(channelID > 18 || channelID < 1)
			{
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] Niew³aœciwy nr kana³u");
				return 1;
			}
			if( Houses[i][HRadio1On] )
				PlayerActionMessage(playerid,15.0,"zmienia kana³");
			else
			{
				PlayerActionMessage(playerid,15.0,"w³¹cza radio");
				Houses[i][HRadio1On] = 1;
				SaveHouseData( i, "HRadio1On" );
			}
			Houses[i][HRadio1Ch] = channelID;
			SaveHouseData( i, "HRadio1Ch" );
			PlayHouseRadio( i, channelID, GetPlayerVirtualWorld(playerid) );
			return 1;
		}
	}
	SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie znajdujesz siê w domu !");
	return 1;
}

dcmd_radiozabierz(playerid, params[])
{
	#pragma unused params
	for( new i = 0; i < sizeof(Businesses); i++ )
	{
		if( PlayerToPoint(150.0, playerid, Businesses[i][ExitX], Businesses[i][ExitY], Businesses[i][ExitZ]) && i == GetPlayerVirtualWorld(playerid) )
		{
			if( !Businesses[i][BRadio1Bought] )
			{
				SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz radia w tym biznesie !");
				return 1;
			}
			if( !PlayerToPoint( 2.0, playerid, Businesses[i][BRadio1X], Businesses[i][BRadio1Y], Businesses[i][BRadio1Z]) )
			{
				SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ obok radia !");
				return 1;
			}
			if(	InsertPlayerItem(playerid, 1, 106, 0, 0 ) == 0 )
			{
				SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Jesteœ przeci¹¿ony !");
				return 1;
			}
			SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Zabra³eœ radio" );
			StopBizRadioStation(i);
			Businesses[i][BRadio1Bought] = 0;
			Businesses[i][BRadio1On] = 0;
			Businesses[i][BRadio1X] = 0.0;
			Businesses[i][BRadio1Y] = 0.0;
			Businesses[i][BRadio1Z] = 0.0;
			Businesses[i][BRadio1Angle] = 0.0;
			DestroyDynamicObject(Businesses[i][BRadio1Obj]);
			SaveBizData( i, "BRadio1Bought");
			SaveBizData( i, "BRadio1On" );
			SaveBizData( i, "BRadio1X" );
			SaveBizData( i, "BRadio1Y" );
			SaveBizData( i, "BRadio1Z" );
			SaveBizData( i, "BRadio1Angle" );
			return 1;
		}
	}
	for( new i = 0; i < sizeof(Houses); i++ )
	{
		if( PlayerToPoint(150.0, playerid, Houses[i][ExitX], Houses[i][ExitY], Houses[i][ExitZ]) && i == GetPlayerVirtualWorld(playerid) )
		{
			if( !Houses[i][HRadio1Bought] )
			{
				SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz radia w tym domu !");
				return 1;
			}
			if( !PlayerToPoint( 2.0, playerid, Houses[i][HRadio1X], Houses[i][HRadio1Y], Houses[i][HRadio1Z]) )
			{
				SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ obok radia !");
				return 1;
			}
			if(	InsertPlayerItem(playerid, 1, 106, 0, 0 ) == 0 )
			{
				SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Jesteœ przeci¹¿ony !");
				return 1;
			}
			SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Zabra³eœ radio" );
			StopHouseRadioStation(i);
			Houses[i][HRadio1Bought] = 0;
			Houses[i][HRadio1On] = 0;
			Houses[i][HRadio1X] = 0.0;
			Houses[i][HRadio1Y] = 0.0;
			Houses[i][HRadio1Z] = 0.0;
			DestroyDynamicObject(Houses[i][HRadio1Obj]);
			SaveHouseData( i, "HRadio1Bought");
			SaveHouseData( i, "HRadio1On" );
			SaveHouseData( i, "HRadio1X" );
			SaveHouseData( i, "HRadio1Y" );
			SaveHouseData( i, "HRadio1Z" );
			return 1;
		}
	}
	SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie znajdujesz siê w domu/biznesie !");
	return 1;
}

dcmd_radioboff(playerid, params[])
{
	#pragma unused params
	for( new i = 0; i < sizeof(Businesses); i++ )
	{
		if( PlayerToPoint(150.0, playerid, Businesses[i][ExitX], Businesses[i][ExitY], Businesses[i][ExitZ]) && i == GetPlayerVirtualWorld(playerid) )
		{
			if( !Businesses[i][BRadio1Bought] )
			{
				SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz radia w tym biznesie !");
				return 1;
			}
			if( !PlayerToPoint( 2.0, playerid, Businesses[i][BRadio1X], Businesses[i][BRadio1Y], Businesses[i][BRadio1Z]) )
			{
				SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ obok radia !");
				return 1;
			}
			if( !Businesses[i][BRadio1On] )
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2,"[INFO:] Nie masz w³¹czonego radia !");
				return 1;
			}
			StopBizRadioStation(i);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2,"[INFO:] Wy³¹czy³eœ radio");
			PlayerActionMessage(playerid,15.0,"wy³¹czy³ radio");
			return 1;
		}
	}
	SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie znajdujesz siê w biznesie !");
	return 1;
}

dcmd_radiodoff(playerid, params[])
{
	#pragma unused params
	for( new i = 0; i < sizeof(Houses); i++ )
	{
		if( PlayerToPoint(60.0, playerid, Houses[i][ExitX], Houses[i][ExitY], Houses[i][ExitZ]) && i == GetPlayerVirtualWorld(playerid) )
		{
			if( !Houses[i][HRadio1Bought] )
			{
				SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz radia w tym domu !");
				return 1;
			}
			if( !PlayerToPoint( 2.0, playerid, Houses[i][HRadio1X], Houses[i][HRadio1Y], Houses[i][HRadio1Z]) )
			{
				SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ obok radia !");
				return 1;
			}
			if( !Houses[i][HRadio1On] )
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2,"[INFO:] Nie masz w³¹czonego radia !");
				return 1;
			}
			StopHouseRadioStation(i);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2,"[INFO:] Wy³¹czy³eœ radio");
			PlayerActionMessage(playerid,15.0,"wy³¹czy³ radio");
			return 1;
		}
	}
	SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie znajdujesz siê w domu !");
	return 1;
}

dcmd_radiobv(playerid, params[])
{
	new rv, string[128];
	if( sscanf( params, "d", rv ) )
	{
		SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] /radiohv [g³oœnoœæ]" );
		return 1;
	}
	if( rv > 100 || rv < 0 )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] g³oœnoœæ od 0 do 100 !");
		return 1;
	}
	for( new i = 0; i < sizeof(Businesses); i++ )
	{
		if( PlayerToPoint(150.0, playerid, Businesses[i][ExitX], Businesses[i][ExitY], Businesses[i][ExitZ]) && i == GetPlayerVirtualWorld(playerid) )
		{
			if( !Businesses[i][BRadio1Bought] )
			{
				SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz radia w tym biznesie !");
				return 1;
			}
			if( !PlayerToPoint( 2.0, playerid, Businesses[i][BRadio1X], Businesses[i][BRadio1Y], Businesses[i][BRadio1Z]) )
			{
				SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ obok radia !");
				return 1;
			}
			if( !Businesses[i][BRadio1On] )
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2,"[INFO:] Nie masz w³¹czonego radia !");
				return 1;
			}
			ChangeBizRadioVolume( i, rv );
			format( string, sizeof(string), "[INFO:] g³oœnoœæ: %d", rv );
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			PlayerActionMessage(playerid,15.0,"przekrêca ");
			return 1;
		}
	}
	SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie znajdujesz siê w biznesie !");
	return 1;
}

dcmd_radiodv(playerid, params[])
{
	new rv, string[128];
	if( sscanf( params, "d", rv ) )
	{
		SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] /radiohv [g³oœnoœæ]" );
		return 1;
	}
	if( rv > 100 || rv < 0 )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] g³oœnoœæ od 0 do 100 !");
		return 1;
	}
	for( new i = 0; i < sizeof(Houses); i++ )
	{
		if( PlayerToPoint(60.0, playerid, Houses[i][ExitX], Houses[i][ExitY], Houses[i][ExitZ]) && i == GetPlayerVirtualWorld(playerid) )
		{
			if( !Houses[i][HRadio1Bought] )
			{
				SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz radia w tym domu !");
				return 1;
			}
			if( !PlayerToPoint( 2.0, playerid, Houses[i][HRadio1X], Houses[i][HRadio1Y], Houses[i][HRadio1Z]) )
			{
				SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ obok radia !");
				return 1;
			}
			if( !Houses[i][HRadio1On] )
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2,"[INFO:] Nie masz w³¹czonego radia !");
				return 1;
			}
			ChangeHouseRadioVolume( i, rv );
			format( string, sizeof(string), "[INFO:] g³oœnoœæ: %d", rv );
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			PlayerActionMessage(playerid,15.0,"przekrêca ");
			return 1;
		}
	}
	SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie znajdujesz siê w domu !");
	return 1;
}

dcmd_gotofactorytakecpi( playerid, params[] )
{
	if( gPlayerData[playerid][pAdmin] < 4 )
		return 0;
	new fID;
	if( sscanf( params, "d", fID ) )
	{
		SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] /gotofactorytakecpi [fID]" );
		return 1;
	}
	if( !DynamicFactions[fID][WFactoryEnabled] )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Fabryka nie jest aktywna" );
		return 1;
	}
	new vehicleid = GetPlayerVehicleID(playerid);
	if(vehicleid == INVALID_VEHICLE_ID)
		SetPlayerToPos(playerid, DynamicFactions[fID][WFactoryCentrePosX], DynamicFactions[fID][WFactoryCentrePosY], DynamicFactions[fID][WFactoryCentrePosZ] );
	else
		SetVehicleToPos(vehicleid, DynamicFactions[fID][WFactoryCentrePosX], DynamicFactions[fID][WFactoryCentrePosY], DynamicFactions[fID][WFactoryCentrePosZ] );
	return 1;
}

dcmd_setstartspawn(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] < 1)
		return 0;
	GetPlayerPos(playerid, gStartSpawnX, gStartSpawnY, gStartSpawnZ);
	SendClientMessage( playerid, COLOR_GREEN, "[INFO:] Ustawi³eœ spawn nowych graczy !");
	SaveSpawnInfo();
	return 1;
}

dcmd_setstartmoney( playerid, params[] )
{
	if( gPlayerData[playerid][pAdmin] < 1 )
		return 0;
	new money;
	if( sscanf( params, "d", money ) )
	{
		SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] /setstartmoney [money]" );
		return 1;
	}
	gStartMoney = money;
	SendClientMessage( playerid, COLOR_GREEN, "[INFO:] Ustawi³eœ pocz¹tkow¹ iloœæ kasy gracza !");
	SaveSpawnInfo();
	return 1;
}

dcmd_setstartbank( playerid, params[] )
{
	if( gPlayerData[playerid][pAdmin] < 1 )
		return 0;
	new bank;
	if( sscanf( params, "d", bank ) )
	{
		SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] /setstartbank [bank]" );
		return 1;
	}
	gStartBank = bank;
	SendClientMessage( playerid, COLOR_GREEN, "[INFO:] Ustawi³eœ pocz¹tkow¹ iloœæ kasy w banku gracza !");
	SaveSpawnInfo();
	return 1;
}

dcmd_setstartskin( playerid, params[] )
{
	if( gPlayerData[playerid][pAdmin] < 1 )
		return 0;
	new skin;
	if( sscanf( params, "d", skin ) )
	{
		SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] /setstartskin [skinid]" );
		return 1;
	}
	gStartBank = skin;
	SendClientMessage( playerid, COLOR_GREEN, "[INFO:] Ustawi³eœ pocz¹tkow¹ skin gracza !");
	SaveSpawnInfo();
	return 1;
}

dcmd_vehtank( playerid, params[] )
{
	#pragma unused params
	if( gPlayerData[playerid][pAdmin] != 5 )
		return 0;
	new vehid = GetPlayerVehicleID(playerid);
	if( vehid != INVALID_VEHICLE_ID )
	{
		new Float:tank = float( VehFTank(vehid) );
		new string[128];
		format( string, sizeof(string), "[INFO:] Pojemnoœæ baku tego pojazdu: %f ltr", tank );
		SendClientMessage( playerid, COLOR_LIGHTYELLOW2, string );
		return 1;
	}
	return 1;
}

dcmd_reconnect( playerid, params[] )
{
	#pragma unused params
	if( gPlayerData[playerid][pAdmin] < 4 )
		return 0;
	// mysql_close(db_con1);
	// mysql_close(db_con2);
	// mysql_close(db_con3);
	// mysql_close(db_con4);
	// mysql_connect(db_host,db_user,db_pass,db_database, db_con1, 1);
	// mysql_connect(db_host,db_user,db_pass,db_database, db_con2, 1);
	// mysql_connect(db_host,db_user,db_pass,db_database, db_con3, 1);
	// mysql_connect(db_host,db_user,db_pass,db_database, db_con4, 1);
	SendClientMessage(playerid, COLOR_GREEN, "WYKONANO");
	return 1;
}

dcmd_rp( playerid, params[] )
{
	#pragma unused params
	if( gPlayerData[playerid][pJob] != 19)
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Niew³aœciwa praca !");
		return 1;
	}
	for(new k = 0; k < sizeof(Businesses); k++)
	{
		if(GetPlayerVirtualWorld(playerid) == k)
		{
			if(PlayerToPoint(30.0, playerid,Businesses[k][ExitX],Businesses[k][ExitY],Businesses[k][ExitZ]))
			{
				if( Businesses[k][Till] <= 0 )
				{
					SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz tutaj pracowaæ - brak pieniêdzy w kasie" );
					return 1;
				}
				else if( Businesses[k][Products] <= 0 )
				{
					SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz tutaj pracowaæ - brak produktów" );
					return 1;
				}
				else if(Businesses[k][Till] > 0 && Businesses[k][Products] > 0)
				{
					gPlayerData[playerid][pSellerJobOn] = 1;
					SendClientMessage(playerid, COLOR_GREEN, "[INFO:] Rozpocz¹³eœ prace !");
					return 1;
				}
			}
		}
	}
	SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w biznesie !");
	return 1;
}

dcmd_avehpj(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
	{
		return 0;
	}
	
	new vehicleid = GetPlayerVehicleID(playerid);
	new pj;
	
	if(sscanf(params, "d", pj))
	{
		SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] /ahevpj [id paint job]" );
		return 1;
	}
	
	ChangeVehiclePaintjob(vehicleid, pj);
	
	gVehData[vehicleid-1][mVehPaintJob] = pj;
	SaveVehData(vehicleid-1, "VehPaintJob");
	
	return 1;
}

dcmd_wyjedzzgarazu(playerid, params[])
{
	#pragma unused params
	for( new i = 0; i < sizeof(Houses); i++ )
	{
		if( !PlayerToPoint( 5.0, playerid, Houses[i][ExitX], Houses[i][ExitY], Houses[i][ExitZ] ) )
			continue;
		
		if( GetPlayerVirtualWorld(playerid) != i )
			continue;
		
		if( Houses[i][Locked] && !AdminDuty[playerid] )
		{
			SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Gara¿ jest zamkniêty !");
			return 1;
		}
		
		new vehid = GetPlayerVehicleID(playerid);
		
		if( vehid == INVALID_VEHICLE_ID )
		{
			SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w pojeŸdzie !");
			return 1;
		}
		
		PlayerActionMessage(playerid, 15.0, "otwiera gara¿ pilotem i z niego wyje¿dz¹");
		LinkVehicleToInterior( vehid, 0 );
		SetVehicleVirtualWorld( vehid, 0 );
		SetVehicleToPos( vehid, Houses[i][EnterX], Houses[i][EnterY], Houses[i][EnterZ] );
		SetVehicleZAngle( vehid, Houses[i][EnterAngle] );
		// PutPlayerIntoVehicle( playerid, vehid, 0 );
		SetPlayerInterior( playerid, 0 );
		SetPlayerVirtualWorld( playerid, 0 );

		gVehData[vehid-1][mVehX] = Houses[i][EnterX];
		gVehData[vehid-1][mVehY] = Houses[i][EnterY];
		gVehData[vehid-1][mVehZ] = Houses[i][EnterZ];
		gVehData[vehid-1][mVehA] = Houses[i][EnterAngle];
		gVehData[vehid-1][mVehInt] = Houses[i][EnterInterior];
		gVehData[vehid-1][mVehVW] = 0;
		SaveVehData( vehid-1, "VehPos" );
		SaveVehData( vehid-1, "VehInt" );
		SaveVehData( vehid-1, "VehVW" );

		gPlayerData[playerid][pCrashX] = Houses[i][EnterX];
		gPlayerData[playerid][pCrashY] = Houses[i][EnterY];
		gPlayerData[playerid][pCrashZ] = Houses[i][EnterZ];
		gPlayerData[playerid][pCrashAngle] = Houses[i][EnterAngle];
		gPlayerData[playerid][pCrashInt] = Houses[i][EnterInterior];
		gPlayerData[playerid][pCrashW] = i;
		
		if( Houses[i][HRadio1Bought] && Houses[i][HRadio1On] )
			Audio_Stop( playerid, Houses[i][HRadio1ID][playerid] );
		return 1;
	}
	for(new i = 0; i < sizeof(Building); i++)
	{
		if(!PlayerToPoint(5.0, playerid, Building[i][ExitX], Building[i][ExitY], Building[i][ExitZ]))
		{
			continue;
		}
		
		if(Building[i][BuildingType] != BUILDINGT_GARAGE)
		{
			continue;
		}
		
		if(GetPlayerVirtualWorld(playerid) != i)
		{
			continue;
		}
		
		new vehid = GetPlayerVehicleID(playerid);
	
		if(vehid == INVALID_VEHICLE_ID)
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w pojeŸdzie !");
			return 1;
		}
		
		PlayerActionMessage(playerid, 15.0, "otwiera gara¿ pilotem i do niego wje¿d¿a");
		LinkVehicleToInterior(vehid, 0);
		SetVehicleVirtualWorld(vehid, 0);
		SetVehicleToPos(vehid, Building[i][EnterX], Building[i][EnterY], Building[i][EnterZ]);
		SetVehicleZAngle(vehid, Building[i][EnterAngle]);
		SetPlayerInterior(playerid, 0);
		SetPlayerVirtualWorld(playerid, 0);

		gVehData[vehid-1][mVehX] = Building[i][EnterX];
		gVehData[vehid-1][mVehY] = Building[i][EnterY];
		gVehData[vehid-1][mVehZ] = Building[i][EnterZ];
		gVehData[vehid-1][mVehA] = Building[i][EnterAngle];
		gVehData[vehid-1][mVehInt] = 0;
		gVehData[vehid-1][mVehVW] = 0;
		SaveVehData( vehid-1, "VehPos" );
		SaveVehData( vehid-1, "VehInt" );
		SaveVehData( vehid-1, "VehVW" );

		gPlayerData[playerid][pCrashX] = Building[i][EnterX];
		gPlayerData[playerid][pCrashY] = Building[i][EnterY];
		gPlayerData[playerid][pCrashZ] = Building[i][EnterZ];
		gPlayerData[playerid][pCrashAngle] = Building[i][EnterAngle];
		gPlayerData[playerid][pCrashInt] = 0;
		gPlayerData[playerid][pCrashW] = 0;
		
		return 1;
	}
	SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ przy wyjeŸdzie z gara¿u !");
	return 1;
}

dcmd_wjedzdogarazu(playerid, params[])
{
	#pragma unused params
	
	new vehid = GetPlayerVehicleID(playerid);
	
	if(vehid == INVALID_VEHICLE_ID)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w pojeŸdzie !");
		return 1;
	}
	
	for(new i = 0; i < sizeof(Houses); i++)
	{
		if(!PlayerToPoint(5.0, playerid, Houses[i][EnterX], Houses[i][EnterY], Houses[i][EnterZ]))
			continue;
		
		if(GetPlayerVirtualWorld(playerid) != Houses[i][EnterWorld])
			continue;
		
		if(Houses[i][HouseType] != 1 && Houses[i][HouseType] != 2)
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] To nie jest gara¿ !");
			return 1;
		}
		
		if(Houses[i][Locked] && !AdminDuty[playerid])
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Gara¿ jest zamkniêty !");
			return 1;
		}
		
		PlayerActionMessage(playerid, 15.0, "otwiera gara¿ pilotem i do niego wje¿d¿a");
		LinkVehicleToInterior(vehid, Houses[i][ExitInterior]);
		SetVehicleVirtualWorld(vehid, i);
		SetVehicleToPos(vehid, Houses[i][ExitX], Houses[i][ExitY], Houses[i][ExitZ]);
		SetVehicleZAngle(vehid, Houses[i][ExitAngle]);
		SetPlayerInterior(playerid,Houses[i][ExitInterior]);
		SetPlayerVirtualWorld(playerid, i);

		gVehData[vehid-1][mVehX] = Houses[i][ExitX];
		gVehData[vehid-1][mVehY] = Houses[i][ExitY];
		gVehData[vehid-1][mVehZ] = Houses[i][ExitZ];
		gVehData[vehid-1][mVehA] = Houses[i][ExitAngle];
		gVehData[vehid-1][mVehInt] = Houses[i][ExitInterior];
		gVehData[vehid-1][mVehVW] = i;
		SaveVehData(vehid-1, "VehPos");
		SaveVehData(vehid-1, "VehInt");
		SaveVehData(vehid-1, "VehVW");

		gPlayerData[playerid][pCrashX] = Houses[i][ExitX];
		gPlayerData[playerid][pCrashY] = Houses[i][ExitY];
		gPlayerData[playerid][pCrashZ] = Houses[i][ExitZ];
		gPlayerData[playerid][pCrashAngle] = Houses[i][ExitAngle];
		gPlayerData[playerid][pCrashInt] = Houses[i][ExitInterior];
		gPlayerData[playerid][pCrashW] = i;

		if(Houses[i][HRadio1On] && Houses[i][HRadio1Bought])
			PlayerPHouseRadio(playerid, i);
		return 1;
	}
	for(new i = 0; i < sizeof(Building); i++)
	{
		if(!PlayerToPoint(5.0, playerid, Building[i][EnterX], Building[i][EnterY], Building[i][EnterZ]))
		{
			continue;
		}
		
		if(GetPlayerVirtualWorld(playerid) != Building[i][EnterWorld])
		{
			continue;
		}
		
		if(Building[i][BuildingType] != BUILDINGT_GARAGE)
		{
			continue;
		}
		
		PlayerActionMessage(playerid, 15.0, "otwiera gara¿ pilotem i do niego wje¿d¿a");
		LinkVehicleToInterior(vehid, Building[i][ExitInterior]);
		SetVehicleVirtualWorld(vehid, i);
		SetVehicleToPos(vehid, Building[i][ExitX], Building[i][ExitY], Building[i][ExitZ]);
		SetVehicleZAngle(vehid, Building[i][ExitAngle]);
		// PutPlayerIntoVehicle(playerid, vehid, 0);
		SetPlayerInterior(playerid,Building[i][ExitInterior]);
		SetPlayerVirtualWorld(playerid, i);

		gVehData[vehid-1][mVehX] = Building[i][ExitX];
		gVehData[vehid-1][mVehY] = Building[i][ExitY];
		gVehData[vehid-1][mVehZ] = Building[i][ExitZ];
		gVehData[vehid-1][mVehA] = Building[i][ExitAngle];
		gVehData[vehid-1][mVehInt] = Building[i][ExitInterior];
		gVehData[vehid-1][mVehVW] = i;
		SaveVehData(vehid-1, "VehPos");
		SaveVehData(vehid-1, "VehInt");
		SaveVehData(vehid-1, "VehVW");

		gPlayerData[playerid][pCrashX] = Building[i][ExitX];
		gPlayerData[playerid][pCrashY] = Building[i][ExitY];
		gPlayerData[playerid][pCrashZ] = Building[i][ExitZ];
		gPlayerData[playerid][pCrashAngle] = Building[i][ExitAngle];
		gPlayerData[playerid][pCrashInt] = Building[i][ExitInterior];
		gPlayerData[playerid][pCrashW] = i;
		
		return 1;
	}
	SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ przy wjeŸdzie do gara¿u !");
	return 1;
}

dcmd_zwrocczesci( playerid, params[] )
{
	#pragma unused params
	if( gPlayerData[playerid][pJob] != 22 )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ pracownikiem fabryki broni !");
		return 1;
	}
	/* Slot 1 */
	new slotitem = -1;
	if( PSlotItemType( playerid, I_SLOT1 ) == 1 )
	{
		slotitem = ShowSlotItem( playerid, I_SLOT1 );
		if ( slotitem >= 43 && slotitem <= 104 )
		{
			InsertItemToFactory( gPlayerData[playerid][pFaction], slotitem, SlotParam6( playerid, I_SLOT1 ) );
			RemovePlayerItemUsed( playerid, I_SLOT1 );
		}
	}
	if( PSlotItemType( playerid, I_SLOT2 ) == 1 )
	{
		slotitem = ShowSlotItem( playerid, I_SLOT2 );
		if ( slotitem >= 43 && slotitem <= 104 )
		{
			InsertItemToFactory( gPlayerData[playerid][pFaction], slotitem, SlotParam6( playerid, I_SLOT2 ) );
			RemovePlayerItemUsed( playerid, I_SLOT2 );
		}
	}
	if( PSlotItemType( playerid, I_SLOT3 ) == 1 )
	{
		slotitem = ShowSlotItem( playerid, I_SLOT3 );
		if ( slotitem >= 43 && slotitem <= 104 )
		{
			InsertItemToFactory( gPlayerData[playerid][pFaction], slotitem, SlotParam6( playerid, I_SLOT3 ) );
			RemovePlayerItemUsed( playerid, I_SLOT3 );
		}
	}
	if( PSlotItemType( playerid, I_SLOT4 ) == 1 )
	{
		slotitem = ShowSlotItem( playerid, I_SLOT4 );
		if ( slotitem >= 43 && slotitem <= 104 )
		{
			InsertItemToFactory( gPlayerData[playerid][pFaction], slotitem, SlotParam6( playerid, I_SLOT4 ) );
			RemovePlayerItemUsed( playerid, I_SLOT4 );
		}
	}
	if( PSlotItemType( playerid, I_SLOT5 ) == 1 )
	{
		slotitem = ShowSlotItem( playerid, I_SLOT5 );
		if ( slotitem >= 43 && slotitem <= 104 )
		{
			InsertItemToFactory( gPlayerData[playerid][pFaction], slotitem, SlotParam6( playerid, I_SLOT5 ) );
			RemovePlayerItemUsed( playerid, I_SLOT5 );
		}
	}
	if( PSlotItemType( playerid, I_SLOT6 ) == 1 )
	{
		slotitem = ShowSlotItem( playerid, I_SLOT6 );
		if ( slotitem >= 43 && slotitem <= 104 )
		{
			InsertItemToFactory( gPlayerData[playerid][pFaction], slotitem, SlotParam6( playerid, I_SLOT6 ) );
			RemovePlayerItemUsed( playerid, I_SLOT6 );
		}
	}
	if( PSlotItemType( playerid, I_SLOT7 ) == 1 )
	{
		slotitem = ShowSlotItem( playerid, I_SLOT7 );
		if ( slotitem >= 43 && slotitem <= 104 )
		{
			InsertItemToFactory( gPlayerData[playerid][pFaction], slotitem, SlotParam6( playerid, I_SLOT7 ) );
			RemovePlayerItemUsed( playerid, I_SLOT7 );
		}
	}
	if( PSlotItemType( playerid, I_SLOT8 ) == 1 )
	{
		slotitem = ShowSlotItem( playerid, I_SLOT8 );
		if ( slotitem >= 43 && slotitem <= 104 )
		{
			InsertItemToFactory( gPlayerData[playerid][pFaction], slotitem, SlotParam6( playerid, I_SLOT8 ) );
			RemovePlayerItemUsed( playerid, I_SLOT8 );
		}
	}
	if( PSlotItemType( playerid, I_SLOT9 ) == 1 )
	{
		slotitem = ShowSlotItem( playerid, I_SLOT9 );
		if ( slotitem >= 43 && slotitem <= 104 )
		{
			InsertItemToFactory( gPlayerData[playerid][pFaction], slotitem, SlotParam6( playerid, I_SLOT9 ) );
			RemovePlayerItemUsed( playerid, I_SLOT9 );
		}
	}
	if( PSlotItemType( playerid, I_SLOT10 ) == 1 )
	{
		slotitem = ShowSlotItem( playerid, I_SLOT10 );
		if ( slotitem >= 43 && slotitem <= 104 )
		{
			InsertItemToFactory( gPlayerData[playerid][pFaction], slotitem, SlotParam6( playerid, I_SLOT10 ) );
			RemovePlayerItemUsed( playerid, I_SLOT10 );
		}
	}
	if( PSlotItemType( playerid, I_SLOT11 ) == 1 )
	{
		slotitem = ShowSlotItem( playerid, I_SLOT11 );
		if ( slotitem >= 43 && slotitem <= 104 )
		{
			InsertItemToFactory( gPlayerData[playerid][pFaction], slotitem, SlotParam6( playerid, I_SLOT11 ) );
			RemovePlayerItemUsed( playerid, I_SLOT11 );
		}
	}
	if( PSlotItemType( playerid, I_SLOT12 ) == 1 )
	{
		slotitem = ShowSlotItem( playerid, I_SLOT12 );
		if ( slotitem >= 43 && slotitem <= 104 )
		{
			InsertItemToFactory( gPlayerData[playerid][pFaction], slotitem, SlotParam6( playerid, I_SLOT12 ) );
			RemovePlayerItemUsed( playerid, I_SLOT12 );
		}
	}
	if( PSlotItemType( playerid, I_SLOT13 ) == 1 )
	{
		slotitem = ShowSlotItem( playerid, I_SLOT13 );
		if ( slotitem >= 43 && slotitem <= 104 )
		{
			InsertItemToFactory( gPlayerData[playerid][pFaction], slotitem, SlotParam6( playerid, I_SLOT13 ) );
			RemovePlayerItemUsed( playerid, I_SLOT13 );
		}
	}
	if( PSlotItemType( playerid, I_SLOT14 ) == 1 )
	{
		slotitem = ShowSlotItem( playerid, I_SLOT14 );
		if ( slotitem >= 43 && slotitem <= 104 )
		{
			InsertItemToFactory( gPlayerData[playerid][pFaction], slotitem, SlotParam6( playerid, I_SLOT14 ) );
			RemovePlayerItemUsed( playerid, I_SLOT14 );
		}
	}
	if( PSlotItemType( playerid, I_SLOT15 ) == 1 )
	{
		slotitem = ShowSlotItem( playerid, I_SLOT15 );
		if ( slotitem >= 43 && slotitem <= 104 )
		{
			InsertItemToFactory( gPlayerData[playerid][pFaction], slotitem, SlotParam6( playerid, I_SLOT15 ) );
			RemovePlayerItemUsed( playerid, I_SLOT15 );
		}
	}
	if( PSlotItemType( playerid, I_SLOT16 ) == 1 )
	{
		slotitem = ShowSlotItem( playerid, I_SLOT16 );
		if ( slotitem >= 43 && slotitem <= 104 )
		{
			InsertItemToFactory( gPlayerData[playerid][pFaction], slotitem, SlotParam6( playerid, I_SLOT16 ) );
			RemovePlayerItemUsed( playerid, I_SLOT16 );
		}
	}
	if( PSlotItemType( playerid, I_SLOT17 ) == 1 )
	{
		slotitem = ShowSlotItem( playerid, I_SLOT17 );
		if ( slotitem >= 43 && slotitem <= 104 )
		{
			InsertItemToFactory( gPlayerData[playerid][pFaction], slotitem, SlotParam6( playerid, I_SLOT17 ) );
			RemovePlayerItemUsed( playerid, I_SLOT17 );
		}
	}
	if( PSlotItemType( playerid, I_SLOT18 ) == 1 )
	{
		slotitem = ShowSlotItem( playerid, I_SLOT18 );
		if ( slotitem >= 43 && slotitem <= 104 )
		{
			InsertItemToFactory( gPlayerData[playerid][pFaction], slotitem, SlotParam6( playerid, I_SLOT18 ) );
			RemovePlayerItemUsed( playerid, I_SLOT18 );
		}
	}
	if( PSlotItemType( playerid, I_SLOT19 ) == 1 )
	{
		slotitem = ShowSlotItem( playerid, I_SLOT19 );
		if ( slotitem >= 43 && slotitem <= 104 )
		{
			InsertItemToFactory( gPlayerData[playerid][pFaction], slotitem, SlotParam6( playerid, I_SLOT19 ) );
			RemovePlayerItemUsed( playerid, I_SLOT19 );
		}
	}
	if( PSlotItemType( playerid, I_SLOT20 ) == 1 )
	{
		slotitem = ShowSlotItem( playerid, I_SLOT20 );
		if ( slotitem >= 43 && slotitem <= 104 )
		{
			InsertItemToFactory( gPlayerData[playerid][pFaction], slotitem, SlotParam6( playerid, I_SLOT20 ) );
			RemovePlayerItemUsed( playerid, I_SLOT20 );
		}
	}
	if( PSlotItemType( playerid, I_SLOT21 ) == 1 )
	{
		slotitem = ShowSlotItem( playerid, I_SLOT21 );
		if ( slotitem >= 43 && slotitem <= 104 )
		{
			InsertItemToFactory( gPlayerData[playerid][pFaction], slotitem, SlotParam6( playerid, I_SLOT21 ) );
			RemovePlayerItemUsed( playerid, I_SLOT21 );
		}
	}
	if( PSlotItemType( playerid, I_SLOT22 ) == 1 )
	{
		slotitem = ShowSlotItem( playerid, I_SLOT22 );
		if ( slotitem >= 43 && slotitem <= 104 )
		{
			InsertItemToFactory( gPlayerData[playerid][pFaction], slotitem, SlotParam6( playerid, I_SLOT22 ) );
			RemovePlayerItemUsed( playerid, I_SLOT22 );
		}
	}
	if( PSlotItemType( playerid, I_SLOT23 ) == 1 )
	{
		slotitem = ShowSlotItem( playerid, I_SLOT23 );
		if ( slotitem >= 43 && slotitem <= 104 )
		{
			InsertItemToFactory( gPlayerData[playerid][pFaction], slotitem, SlotParam6( playerid, I_SLOT23 ) );
			RemovePlayerItemUsed( playerid, I_SLOT23 );
		}
	}
	if( PSlotItemType( playerid, I_SLOT24 ) == 1 )
	{
		slotitem = ShowSlotItem( playerid, I_SLOT24 );
		if ( slotitem >= 43 && slotitem <= 104 )
		{
			InsertItemToFactory( gPlayerData[playerid][pFaction], slotitem, SlotParam6( playerid, I_SLOT24 ) );
			RemovePlayerItemUsed( playerid, I_SLOT24 );
		}
	}
	if( PSlotItemType( playerid, I_SLOT25 ) == 1 )
	{
		slotitem = ShowSlotItem( playerid, I_SLOT25 );
		if ( slotitem >= 43 && slotitem <= 104 )
		{
			InsertItemToFactory( gPlayerData[playerid][pFaction], slotitem, SlotParam6( playerid, I_SLOT25 ) );
			RemovePlayerItemUsed( playerid, I_SLOT25 );
		}
	}
	gPlayerData[playerid][pPartType] = 0;
	gPlayerData[playerid][pPartItem] = 0;
	gPlayerData[playerid][pMountsLeft] = 0;
	gPlayerData[playerid][pMountingW] = 0;
	SavePlayerData( playerid, "PartType" );
	SavePlayerData( playerid, "PartItem" );
	SavePlayerData( playerid, "MountsLeft" );
	SendClientMessage(playerid, COLOR_GREEN, "[INFO:] Zwróci³eœ wszystkie posiadane czêœci do magazynu");
	return 1;
}

dcmd_buyfactorycp(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] < 4 )
		return 0;
	new Float:x, Float:y, Float:z;
	GetPlayerPos(playerid, x, y, z );
	WFactoryLegal[WFactoryCPDocsX] = x;
	WFactoryLegal[WFactoryCPDocsY] = y;
	WFactoryLegal[WFactoryCPDocsZ] = z;

	if( WFactoryLegal[WFactoryCPDocsID] != 0 )
		DestroyDynamicCP( WFactoryLegal[WFactoryCPDocsID] );
	WFactoryLegal[WFactoryCPDocsID] = CreateDynamicCP(x, y, z, 1.0, -1, -1, -1, 5.0);

	SaveWFactoryData( "WFactoryCPDocsX" );
	SaveWFactoryData( "WFactoryCPDocsY" );
	SaveWFactoryData( "WFactoryCPDocsZ" );
	return 1;
}

dcmd_idznaspacerniak(playerid, params[])
{
	#pragma unused params
	if( gPlayerData[playerid][pJailed] == 0 )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie znajdujesz siê w wiêzieniu !");
		return 1;
	}
	if( PlayerToPoint(8.0, playerid, 268.0, 77.0, 1001.0) )
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] To wiêzienie nie posiada spacerniaka !");
		return 1;
	}
	SetPlayerInterior( playerid, 0 );
	SetPlayerVirtualWorld( playerid, 0 );
	SetPlayerToPos( playerid, -333.0, 1533.0, 75.0 );
	gPlayerData[playerid][pCrashX] = -333.0;
	gPlayerData[playerid][pCrashY] = 1533.0;
	gPlayerData[playerid][pCrashZ] = 75.0;
	gPlayerData[playerid][pCrashW] = 0;
	gPlayerData[playerid][pCrashInt] = 0;
	
	TogglePlayerControllable(playerid, 0);
	defer UnfreezePlayer(playerid);

	return 1;
}

dcmd_wrocdowiezienia(playerid, params[])
{
	#pragma unused params
	if( gPlayerData[playerid][pJailed] == 0 )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie znajdujesz siê w wiêzieniu !");
		return 1;
	}
	if( !PlayerToPoint(2.0, playerid, -333.0, 1533.0, 75.0) )
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ przy wejœciu do wiêzienia !");
		return 1;
	}
	DBVariables[2][varDValue]++;
	SetPlayerInterior(playerid, 0);
	SetPlayerVirtualWorld(playerid,21); //BUILDING ID 2, MAKE SURE PD IS ID 2
	switch(DBVariables[2][varDValue])
	{
		case 0: SetPlayerToPos(playerid, 1778.6060791016,-1581.3503417969,1738.7172851563);
		case 1: SetPlayerToPos(playerid, 1778.60546875,-1581.349609375,1734.9417724609);
		case 2: SetPlayerToPos(playerid, 1774.3107910156,-1580.8834228516,1734.9429931641);
		case 3: SetPlayerToPos(playerid, 1770.0396728516,-1580.9715576172,1734.9429931641);
		case 4: SetPlayerToPos(playerid, 1765.6442871094,-1581.0885009766,1734.9429931641);
		case 5: SetPlayerToPos(playerid, 1761.5192871094,-1580.9661865234,1734.9429931641);
		case 6: SetPlayerToPos(playerid, 1757.1713867188,-1581.1558837891,1734.9429931641);
		case 7: SetPlayerToPos(playerid, 1757.3331298828,-1565.4664306641,1734.9429931641);
		case 8: SetPlayerToPos(playerid, 1761.7298583984,-1565.6207275391,1734.9429931641);
		case 9: SetPlayerToPos(playerid, 1765.9074707031,-1565.1364746094,1734.9429931641);
		case 10: SetPlayerToPos(playerid, 1770.2448730469,-1565.3743896484,1734.9429931641);
		case 11: SetPlayerToPos(playerid, 1774.5153808594,-1565.1875,1734.9429931641);
		case 12: SetPlayerToPos(playerid, 1778.6448974609,-1565.0377197266,1734.9429931641);
		case 13: SetPlayerToPos(playerid, 1774.236328125,-1580.9116210938,1738.7172851563);
		case 14: SetPlayerToPos(playerid, 1770.1110839844,-1580.9205322266,1738.7172851563);
		case 15: SetPlayerToPos(playerid, 1765.7939453125,-1581.2406005859,1738.7172851563);
		case 16: SetPlayerToPos(playerid, 1761.4822998047,-1581.0185546875,1738.7172851563);
		case 17: SetPlayerToPos(playerid, 1757.3651123047,-1581.0830078125,1738.7172851563);
		case 18: SetPlayerToPos(playerid, 1757.3023681641,-1565.8057861328,1738.6934814453);
		case 19: SetPlayerToPos(playerid, 1761.7540283203,-1565.4591064453,1738.6934814453);
		case 20: SetPlayerToPos(playerid, 1765.8216552734,-1565.5594482422,1738.6934814453);
		case 21: SetPlayerToPos(playerid, 1770.0919189453,-1565.4733886719,1738.6934814453);
		case 22: SetPlayerToPos(playerid, 1774.4881591797,-1565.1726074219,1738.6934814453);
		case 23: SetPlayerToPos(playerid, 1778.5562744141,-1565.2510986328,1738.6937255859);
	}
	if(DBVariables[2][varDValue] == 23)
	{
		DBVariables[2][varDValue] = 0;
	}

	TogglePlayerControllable(playerid, 0);
	defer UnfreezePlayer(playerid);

	gPlayerData[playerid][pCrashInt] = 0;
	gPlayerData[playerid][pCrashW] = 21;
	return 1;
}/*

dcmd_czesci(playerid, params[])
{
	#pragma unused params
	if( gPlayerData[playerid][pJob] != 17 )
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ mechanikiem !");
		return 1;
	}
	new string[128];
	format(string, sizeof(string), "[INFO:] Pozosta³ tobie %d czêœci", gPlayerData[playerid][pParts]);
	SendClientMessage( playerid, COLOR_LIGHTYELLOW2, string);
	return 1;
}*/

dcmd_ileneonow(playerid, params[])
{
	#pragma unused params
	new string[128];
	format( string, sizeof(string), "CZERWONY = %d, NIEBIESKI = %d, ZIELONY = %d, ¯Ó£TY = %d, RÓ¯OWY = %d, BIA£Y = %d",
	gPlayerData[playerid][pVipRedNeon],
	gPlayerData[playerid][pVipBlueNeon],
	gPlayerData[playerid][pVipGreenNeon],
	gPlayerData[playerid][pVipYellowNeon],
	gPlayerData[playerid][pVipPinkNeon],
	gPlayerData[playerid][pVipWhiteNeon]);
	SendClientMessage( playerid, COLOR_GREEN, string );
	return 1;
}

dcmd_uwolnij(playerid, params[])
{
	if( gPlayerData[playerid][pJob] != 4 )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ prawnikiem !");
		return 1;
	}
	new giveplayerid, cost;
	if( sscanf( params, "dd", giveplayerid, cost ) )
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /uwolnij [id gracza] [kwota]");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Gdzie kwota to oferowana cena za uwolnienie (gracz p³aci dan¹ sume za uwolnienie)");
		return 1;
	}
	if(!IsPlayerConnected(giveplayerid))
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ten gracz nie jest online !");
		return 1;
	}
	if(giveplayerid == playerid) { SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz sam siebie uwolniæ."); return 1; }
	if(gPlayerData[giveplayerid][pJailed] == 0)
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Gracz nie jest uwiêziony.");
		return 1;
	}
	if(GetDistanceBetweenPlayers(playerid,giveplayerid) > 5)
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ blisko tej osoby.");
		return 1;
	}
	new freeward;
	if( gPlayerData[giveplayerid][pFaction] != 255 )
	{
		for(new n = 0; n < sizeof(DynamicFactions); n++)
		{
			if( PayRank[n][FactionID] == gPlayerData[giveplayerid][pFaction] )
			{
				switch( gPlayerData[giveplayerid][pRank] )
				{
					case 1: { freeward += PayRank[n][Rank1]; }
					case 2: { freeward += PayRank[n][Rank2]; }
					case 3: { freeward += PayRank[n][Rank3]; }
					case 4: { freeward += PayRank[n][Rank4]; }
					case 5: { freeward += PayRank[n][Rank5]; }
					case 6: { freeward += PayRank[n][Rank6]; }
					case 7: { freeward += PayRank[n][Rank7]; }
					case 8: { freeward += PayRank[n][Rank8]; }
					case 9: { freeward += PayRank[n][Rank9]; }
					case 10: { freeward += PayRank[n][Rank10]; }
				}
			}
		}
	}
	else
		freeward = 50;
	freeward = floatround( gPlayerData[giveplayerid][pJailTime] / 800, floatround_round ) * freeward;
	gLawyerOffer[giveplayerid][playerOffering] = playerid;
	gLawyerOffer[giveplayerid][offerCost] = cost;
	gLawyerOffer[giveplayerid][govCost] = freeward;
	new string[256], string2[128];
	format( string, sizeof(string), "Prawnik %s zaoferowa³ tobie pomoc prawn¹ w zwi¹zku z wydostaniem siê z wiêzienia.\n", GetPlayerNameEx(playerid) );
	format( string2, sizeof(string), "Za swoj¹ pomoc ¿¹da $%d\nJeœli uda mu siê ciebie wydostaæ z wiêzienia przeka¿esz mu 100%% kwoty.\n", cost+freeward);
	strcat( string, string2 );
	format( string2, sizeof(string), "W przeciwnym wypadku zap³acisz 50%% wy¿ej wymienionej kwoty.\n");
	strcat( string, string2 );
	ShowPlayerDialog(giveplayerid, DIALOG_LAWYER_1, DIALOG_STYLE_MSGBOX, "Oferta prawnika", string, "Akceptuj", "Odrzuæ");
	return 1;
}

dcmd_fillobjtable(playerid, params[])
{
	#pragma unused params
	if( gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new string[128];
	for( new i = 0; i < 5000; i++ )
	{
		format(string, sizeof(string), "INSERT INTO `samp_objects` (`cstObjModel`, `ID`) VALUES ('0', '%d')", i+1);
		wp_mysql_query(string, SAVE, CUSTOM_MAX_PLAYERS, db_con2);
	}
	return 1;
}

dcmd_wnetrzebiz(playerid, params[])
{
	#pragma unused params
	
	if(gPlayerData[playerid][pFaction] != FACTIONID_GOVERNMENT)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ urzêdnikiem");
		return 1;
	}
	
	new id = -1;
	
	for(new i = 0; i < sizeof(Businesses); i++)
	{
		if(!PlayerToPoint(2.0, playerid, Businesses[i][EnterX], Businesses[i][EnterY], Businesses[i][EnterZ]))
		{
			continue;
		}
		
		if(Businesses[i][Owned])
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie mo¿na zmieniæ ceny tego biznesu");
			return 1;
		}
		
		id = i;
	}
	
	if(id == -1)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ przy wejœciu do ¿adnego biznesu lub nie ma mo¿liwoœci zmiany wnêtrza");
		return 1;
	}
	
	gPlayerVars[playerid][mBizIdIntEdit] = id;
	
	new string2[1024];
	
	format(string2, sizeof(string2), "");
	strcat(string2, "1. Marco Bistro (EAT)\n2. Big Spread Ranch (BAR)\n3. Burger Shot (EAT)\n4. Clickin Bell (EAT)\n5. Well Stacked Pizza (EAT)\n6. Rusty Browns Dohnuts (EAT)\n7. Jays Diner (EAT)\n");
	strcat(string2, "8. Pump Truck Stop Diner (EAT)\n9. Alhambra (DRINK)\n10. Mistys (DRINK)\n11. Lil' Probe Inn (DRINK)\n12. Exclusive (CLOTHES)\n13. Binco (CLOTHES)\n14. ProLaps (CLOTHES)\n15. SubUrban (CLOTHES)\n");
	strcat(string2, "16. Victim (CLOTHES)\n17. Zip (CLOTHES)\n18. Redsands Casino\n19. Off Track Betting\n20. Sex Shop\n21. Zero's RC Shop\n22. Ammunation 1\n23. Ammunation 2\n24. Ammunation 3\n25. Ammunation 4\n");
	strcat(string2, "26. Ammunation 5\n27. Jizzys (DRINK)\n28. 24-7 1\n29. 24-7 2\n30. 24-7 3\n31. 24-7 4\n32. 24-7 5\n33. 24-7 6\n34. missing?\n35. Kibelek\n36. Wiejskie Disco (DRINK)\n37. Disco (DRINK)\n38. Shop Elex\n");
	strcat(string2, "39. Restauracja (EAT/DRINK)\n40. Restrauracja (EAT/DRINK)\n41. Computer Shop\n42. Apteka\n43. Moto Shop\n44. Bar\n45. Restauracja/bar\n46. Restauracja\n47. 24/7\n48. Sklep meblowy\n49. Biz\n50. office\n");
	strcat(string2, "51. Bar na eventy\n52. Bar\n53. Club");

	ShowPlayerDialog(playerid, DIALOG_SELECT_BIZ_INT, DIALOG_STYLE_LIST, "Interiory biznesów", string2, "Wybierz", "Anuluj");
	
	return 1;
	
	// new bizID, intID, string[128];
	// if( gPlayerData[playerid][pFaction] != 9 )
	// {
		// SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ urzêdnikiem !");
		// return 1;
	// }
	// if( sscanf(params, "dd", bizID, intID) )
	// {
		// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /wnetrzebiz [id biznesu] [id wnetrza 1-41]");
		// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INTS:] [1:] Marcos Bistro (Eat) - [2:] Big Spread Ranch (Bar) - [3:] Burger Shot (Eat) - [4:] Cluckin Bell (Eat)");
		// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INTS:] [5:] Well Stacked Pizza (Eat) - [6:] Rusty Browns Dohnuts (Eat) - [7:] Jays Diner (Eat) - [8:] Pump Truck Stop Diner (Eat)");
		// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INTS:] [9:] Alhambra (Drink) - [10:] Mistys (Drink) - [11:] Lil' Probe Inn (Drink) - [12:] Exclusive (Clothes) - [13:] Binco (Clothes)");
		// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INTS:] [14:] ProLaps (Clothes) - [15:] SubUrban (Clothes) - [16:] Victim (Clothes) - [17:] Zip (Clothes) - [18:] Redsands Casino");
		// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INTS:] [19:] Off Track Betting - [20:] Sex Shop - [21:] Zero's RC Shop - [22-26:] Ammunations");
		// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INTS:] [27:] Jizzys (Drink) - [27-33:] 24-7's (Buy) - [35:] Kibelek - [36:] Wiejskie Disco (Drink) - [37:] Disco (Drink) - [38:] Shop Elex ");
		// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INTS:] [39:] Restauracja (Eat/Drink) - [40:] Restauracja (Eat/Drink) - [41:] Computer Shop (Buy)");
		// return 1;
	// }
	// if(intID < 1 || intID > 41)
	// {
		// SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] /wnetrzebiz [id biznesu] [id wnetrza 1-41]");
		// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INTS:] [1:] Marcos Bistro (Eat) - [2:] Big Spread Ranch (Bar) - [3:] Burger Shot (Eat) - [4:] Cluckin Bell (Eat)");
		// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INTS:] [5:] Well Stacked Pizza (Eat) - [6:] Rusty Browns Dohnuts (Eat) - [7:] Jays Diner (Eat) - [8:] Pump Truck Stop Diner (Eat)");
		// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INTS:] [9:] Alhambra (Drink) - [10:] Mistys (Drink) - [11:] Lil' Probe Inn (Drink) - [12:] Exclusive (Clothes) - [13:] Binco (Clothes)");
		// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INTS:] [14:] ProLaps (Clothes) - [15:] SubUrban (Clothes) - [16:] Victim (Clothes) - [17:] Zip (Clothes) - [18:] Redsands Casino");
		// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INTS:] [19:] Off Track Betting - [20:] Sex Shop - [21:] Zero's RC Shop - [22-26:] Ammunations");
		// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INTS:] [27:] Jizzys (Drink) - [27-33:] 24-7's (Buy) - [35:] Kibelek - [36:] Wiejskie Disco (Drink) - [37:] Disco (Drink) - [38:] Shop Elex ");
		// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INTS:] [39:] Restauracja (Eat/Drink) - [40:] Restauracja (Eat/Drink) - [41:] Computer Shop (Buy)");
		// return 1;
	// }
	// if(Businesses[bizID][BIntSet])
	// {
		// SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Interior tego biznesu zosta³ ju¿ ustawiony i nie mo¿na go zmieniæ");
		// return 1;
	// }
	// Businesses[bizID][BIntSet] = 1;
	// SaveBizData(bizID, "IntSet");
	// Businesses[bizID][BInterior] = intID;
	// SaveBizData(bizID, "Interior");
	// if(intID == 1)
	// {
		// Businesses[bizID][ExitX] = -794.806396;
		// Businesses[bizID][ExitY] = 489.284973;
		// Businesses[bizID][ExitZ] = 1376.195;
		// Businesses[bizID][ExitInterior] = 1;
		// Businesses[bizID][ExitAngle] = 0.458332;
		// format(string, sizeof string, "Business ID: %d - Description: Marcos Bistro.", bizID);
		// SendClientMessage(playerid, COLOR_ADMINCMD,string);
	// }
	// else if(intID == 2)
	// {
		// Businesses[bizID][ExitX] = 1212.265625;
		// Businesses[bizID][ExitY] = -25.877540;
		// Businesses[bizID][ExitZ] = 1001.089966;
		// Businesses[bizID][ExitInterior] = 3;
		// Businesses[bizID][ExitAngle] = 181.8332;
		// format(string, sizeof string, "Business ID: %d - Description: Big Spread Ranch Strip Club.", bizID);
		// SendClientMessage(playerid, COLOR_ADMINCMD,string);
	// }
	// else if(intID == 3)
	// {
		// Businesses[bizID][ExitX] = 362.909484;
		// Businesses[bizID][ExitY] = -75.193481;
		// Businesses[bizID][ExitZ] = 1001.507812;
		// Businesses[bizID][ExitInterior] = 10;
		// Businesses[bizID][ExitAngle] = 311.5311;
		// format(string, sizeof string, "Business ID: %d - Description: Burger Shot.", bizID);
		// SendClientMessage(playerid, COLOR_ADMINCMD,string);
	// }
	// else if(intID == 4)
	// {
		// Businesses[bizID][ExitX] = 365.672974;
		// Businesses[bizID][ExitY] = -10.713200;
		// Businesses[bizID][ExitZ] = 1001.869995;
		// Businesses[bizID][ExitInterior] = 9;
		// Businesses[bizID][ExitAngle] = 0.458332;
		// format(string, sizeof string, "Business ID: %d - Description: Cluckin Bell.", bizID);
		// SendClientMessage(playerid, COLOR_ADMINCMD,string);
	// }
	// else if(intID == 5)
	// {
		// Businesses[bizID][ExitX] = 372.579650;
		// Businesses[bizID][ExitY] = -133.515899;
		// Businesses[bizID][ExitZ] = 1001.449951;
		// Businesses[bizID][ExitInterior] = 5;
		// Businesses[bizID][ExitAngle] = 3.834877;
		// format(string, sizeof string, "Business ID: %d - Description: Well Stacked Pizza.", bizID);
		// SendClientMessage(playerid, COLOR_ADMINCMD,string);
	// }
	// else if(intID == 6)
	// {
		// Businesses[bizID][ExitX] = 377.098999;
		// Businesses[bizID][ExitY] = -192.439987;
		// Businesses[bizID][ExitZ] = 1000.643982;
		// Businesses[bizID][ExitInterior] = 17;
		// Businesses[bizID][ExitAngle] = 0.458332;
		// format(string, sizeof string, "Business ID: %d - Description: Rusty Brown Dohnuts.", bizID);
		// SendClientMessage(playerid, COLOR_ADMINCMD,string);
	// }
	// else if(intID == 7)
	// {
		// Businesses[bizID][ExitX] = 460.099976;
		// Businesses[bizID][ExitY] = -88.428497;
		// Businesses[bizID][ExitZ] = 999.621948;
		// Businesses[bizID][ExitInterior] = 4;
		// Businesses[bizID][ExitAngle] = 0.458332;
		// format(string, sizeof string, "Business ID: %d - Description: Jays Diner.", bizID);
		// SendClientMessage(playerid, COLOR_ADMINCMD,string);
	// }
	// else if(intID == 8)
	// {
		// Businesses[bizID][ExitX] = 681.474976;
		// Businesses[bizID][ExitY] = -451.150970;
		// Businesses[bizID][ExitZ] = -25.616798;
		// Businesses[bizID][ExitInterior] = 1;
		// Businesses[bizID][ExitAngle] = 0.458332;
		// format(string, sizeof string, "Business ID: %d - Description: Pump Truck Stop Diner DZIURA W PODLODZE.", bizID);
		// SendClientMessage(playerid, COLOR_ADMINCMD,string);
	// }
	// else if(intID == 9)
	// {
		// Businesses[bizID][ExitX] = 493.484588;
		// Businesses[bizID][ExitY] = -24.906007;
		// Businesses[bizID][ExitZ] = 1000.671875;
		// Businesses[bizID][ExitInterior] = 17;
		// Businesses[bizID][ExitAngle] = 356.2913;
		// format(string, sizeof string, "Business ID: %d - Description: Alhambra.", bizID);
		// SendClientMessage(playerid, COLOR_ADMINCMD,string);
	// }
	// else if(intID == 10)
	// {
		// Businesses[bizID][ExitX] = 502.039733;
		// Businesses[bizID][ExitY] = -67.637390;
		// Businesses[bizID][ExitZ] = 998.834961;
		// Businesses[bizID][ExitInterior] = 11;
		// Businesses[bizID][ExitAngle] = 191.93478;
		// format(string, sizeof string, "Business ID: %d - Description: Mistys.", bizID);
		// SendClientMessage(playerid, COLOR_ADMINCMD,string);
	// }
	// else if(intID == 11)
	// {
		// Businesses[bizID][ExitX] = -229.289276;
		// Businesses[bizID][ExitY] = 1401.314331;
		// Businesses[bizID][ExitZ] = 27.769798;
		// Businesses[bizID][ExitInterior] = 18;
		// Businesses[bizID][ExitAngle] = 270.3904;
		// format(string, sizeof string, "Business ID: %d - Description: Lil' Probe Inn.", bizID);
		// SendClientMessage(playerid, COLOR_ADMINCMD,string);
	// }
	// else if(intID == 12)
	// {
		// Businesses[bizID][ExitX] = 204.608230;
		// Businesses[bizID][ExitY] = -168.851776;
		// Businesses[bizID][ExitZ] = 1000.578979;
		// Businesses[bizID][ExitInterior] = 14;
		// Businesses[bizID][ExitAngle] = 6.87463;
		// format(string, sizeof string, "Business ID: %d - Description: EXcLusive.", bizID);
		// SendClientMessage(playerid, COLOR_ADMINCMD,string);
	// }
	// else if(intID == 13)
	// {
		// Businesses[bizID][ExitX] = 207.801361;
		// Businesses[bizID][ExitY] = -111.258720;
		// Businesses[bizID][ExitZ] = 1005.269958;
		// Businesses[bizID][ExitInterior] = 15;
		// Businesses[bizID][ExitAngle] = 358.414;
		// format(string, sizeof string, "Business ID: %d - Description: Binco.", bizID);
		// SendClientMessage(playerid, COLOR_ADMINCMD,string);
	// }
	// else if(intID == 14)
	// {
		// Businesses[bizID][ExitX] = 207.054993;
		// Businesses[bizID][ExitY] = -138.804993;
		// Businesses[bizID][ExitZ] = 1003.519958;
		// Businesses[bizID][ExitInterior] = 3;
		// Businesses[bizID][ExitAngle] = 0.458332;
		// format(string, sizeof string, "Business ID: %d - Description: ProLaps.", bizID);
		// SendClientMessage(playerid, COLOR_ADMINCMD,string);
	// }
	// else if(intID == 15)
	// {
		// Businesses[bizID][ExitX] = 203.568298;
		// Businesses[bizID][ExitY] = -50.662452;
		// Businesses[bizID][ExitZ] = 1001.799988;
		// Businesses[bizID][ExitInterior] = 1;
		// Businesses[bizID][ExitAngle] = 356.82446;
		// format(string, sizeof string, "Business ID: %d - Description: SubUrban.", bizID);
		// SendClientMessage(playerid, COLOR_ADMINCMD,string);
	// }
	// else if(intID == 16)
	// {
		// Businesses[bizID][ExitX] = 227.542633;
		// Businesses[bizID][ExitY] = -8.100092;
		// Businesses[bizID][ExitZ] = 1002.259949;
		// Businesses[bizID][ExitInterior] = 5;
		// Businesses[bizID][ExitAngle] = 88.921981;
		// format(string, sizeof string, "Business ID: %d - Description: Victim.", bizID);
		// SendClientMessage(playerid, COLOR_ADMINCMD,string);
	// }
	// else if(intID == 17)
	// {
		// Businesses[bizID][ExitX] = 161.205780;
		// Businesses[bizID][ExitY] = -97.102127;
		// Businesses[bizID][ExitZ] = 1001.804687;
		// Businesses[bizID][ExitInterior] = 18;
		// Businesses[bizID][ExitAngle] = 356.4877;
		// format(string, sizeof string, "Business ID: %d - Description: Zip.", bizID);
		// SendClientMessage(playerid, COLOR_ADMINCMD,string);
	// }
	// else if(intID == 18)
	// {
		// Businesses[bizID][ExitX] = 1133.523559;
		// Businesses[bizID][ExitY] = -15.807713;
		// Businesses[bizID][ExitZ] = 1000.750000;
		// Businesses[bizID][ExitInterior] = 12;
		// Businesses[bizID][ExitAngle] = 0.22441;
		// format(string, sizeof string, "Business ID: %d - Description: Small Casino in Redsands West.", bizID);
		// SendClientMessage(playerid, COLOR_ADMINCMD,string);
	// }
	// else if(intID == 19)
	// {
		// Businesses[bizID][ExitX] = 834.660888;
		// Businesses[bizID][ExitY] = 7.240708;
		// Businesses[bizID][ExitZ] = 1004.179993;
		// Businesses[bizID][ExitInterior] = 3;
		// Businesses[bizID][ExitAngle] = 92.031906;
		// format(string, sizeof string, "Business ID: %d - Description: Off Track Betting.", bizID);
		// SendClientMessage(playerid, COLOR_ADMINCMD,string);
	// }
	// else if(intID == 20)
	// {
		// Businesses[bizID][ExitX] = -100.083061;
		// Businesses[bizID][ExitY] = -25.029542;
		// Businesses[bizID][ExitZ] = 1000.741943;
		// Businesses[bizID][ExitInterior] = 3;
		// Businesses[bizID][ExitAngle] = 0.224439;
		// format(string, sizeof string, "Business ID: %d - Description: Sex Shop.", bizID);
		// SendClientMessage(playerid, COLOR_ADMINCMD,string);
	// }
	// else if(intID == 21)
	// {
		// Businesses[bizID][ExitX] = -2240.955322;
		// Businesses[bizID][ExitY] = 128.451400;
		// Businesses[bizID][ExitZ] = 1035.419922;
		// Businesses[bizID][ExitInterior] = 6;
		// Businesses[bizID][ExitAngle] = 268.416;
		// format(string, sizeof string, "Business ID: %d - Description: Zero's RC Shop.", bizID);
		// SendClientMessage(playerid, COLOR_ADMINCMD,string);
	// }
	// else if(intID == 22)
	// {
		// Businesses[bizID][ExitX] = 285.404602;
		// Businesses[bizID][ExitY] = -41.745178;
		// Businesses[bizID][ExitZ] = 1001.569946;
		// Businesses[bizID][ExitInterior] = 1;
		// Businesses[bizID][ExitAngle] =357.69436;
		// format(string, sizeof string, "Business ID: %d - Description: Ammunation 1.", bizID);
		// SendClientMessage(playerid, COLOR_ADMINCMD,string);
	// }
	// else if(intID == 23)
	// {
		// Businesses[bizID][ExitX] = 285.780487;
		// Businesses[bizID][ExitY] = -86.71318;
		// Businesses[bizID][ExitZ] = 1001.539978;
		// Businesses[bizID][ExitInterior] = 4;
		// Businesses[bizID][ExitAngle] = 351.74093;
		// format(string, sizeof string, "Business ID: %d - Description: Ammunation 2.", bizID);
		// SendClientMessage(playerid, COLOR_ADMINCMD,string);
	// }
	// else if(intID == 24)
	// {
		// Businesses[bizID][ExitX] = 296.711975;
		// Businesses[bizID][ExitY] = -112.048240;
		// Businesses[bizID][ExitZ] = 1001.569946;
		// Businesses[bizID][ExitInterior] = 6;
		// Businesses[bizID][ExitAngle] = 358.6343;
		// format(string, sizeof string, "Business ID: %d - Description: Ammunation 3.", bizID);
		// SendClientMessage(playerid, COLOR_ADMINCMD,string);
	// }
	// else if(intID == 25)
	// {
		// Businesses[bizID][ExitX] = 316.569549;
		// Businesses[bizID][ExitY] = -170.279464;
		// Businesses[bizID][ExitZ] = 999.661987;
		// Businesses[bizID][ExitInterior] = 6;
		// Businesses[bizID][ExitAngle] = 2.081076;
		// format(string, sizeof string, "Business ID: %d - Description: Ammunation 4.", bizID);
		// SendClientMessage(playerid, COLOR_ADMINCMD,string);
	// }
	// else if(intID == 26)
	// {
		// Businesses[bizID][ExitX] = 304.572479;
		// Businesses[bizID][ExitY] = -142.094192;
		// Businesses[bizID][ExitZ] = 1004.062500;
		// Businesses[bizID][ExitInterior] = 7;
		// Businesses[bizID][ExitAngle] = 94.17852;
		// format(string, sizeof string, "Business ID: %d - Description: Ammunation Shooting Range.", bizID);
		// SendClientMessage(playerid, COLOR_ADMINCMD,string);
	// }
	// else if(intID == 27)
	// {
		// Businesses[bizID][ExitX] = -2636.974121;
		// Businesses[bizID][ExitY] = 1402.319213;
		// Businesses[bizID][ExitZ] = 906.457947;
		// Businesses[bizID][ExitInterior] = 3;
		// Businesses[bizID][ExitAngle] = 8.61428;
		// format(string, sizeof string, "Business ID: %d - Description: Jizzys.", bizID);
		// SendClientMessage(playerid, COLOR_ADMINCMD,string);
	// }
	// else if(intID == 28)
	// {
		// Businesses[bizID][ExitX] = -25.819719;
		// Businesses[bizID][ExitY] = -188.238037;
		// Businesses[bizID][ExitZ] = 1003.549988;
		// Businesses[bizID][ExitInterior] = 17;
		// Businesses[bizID][ExitAngle] = 1.72090;
		// format(string, sizeof string, "Business ID: %d - Description: 24-7 1.", bizID);
		// SendClientMessage(playerid, COLOR_ADMINCMD,string);
	// }
	// else if(intID == 29)
	// {
		// Businesses[bizID][ExitX] = 5.933865;
		// Businesses[bizID][ExitY] = -31.750873;
		// Businesses[bizID][ExitZ] = 1003.549988;
		// Businesses[bizID][ExitInterior] = 10;
		// Businesses[bizID][ExitAngle] = 359.527526;
		// format(string, sizeof string, "Business ID: %d - Description: 24-7 2.", bizID);
		// SendClientMessage(playerid, COLOR_ADMINCMD,string);
	// }
	// else if(intID == 30)
	// {
		// Businesses[bizID][ExitX] = -30.683946;
		// Businesses[bizID][ExitY] = -92.002952;
		// Businesses[bizID][ExitZ] = 1003.549988;
		// Businesses[bizID][ExitInterior] = 18;
		// Businesses[bizID][ExitAngle] = 2.660877;
		// format(string, sizeof string, "Business ID: %d - Description: 24-7 3.", bizID);
		// SendClientMessage(playerid, COLOR_ADMINCMD,string);
	// }
	// else if(intID == 31)
	// {
		// Businesses[bizID][ExitX] = -25.878168;
		// Businesses[bizID][ExitY] = -141.549636;
		// Businesses[bizID][ExitZ] = 1003.549988;
		// Businesses[bizID][ExitInterior] = 16;
		// Businesses[bizID][ExitAngle] = 352.320;
		// format(string, sizeof string, "Business ID: %d - Description: 24-7 4.", bizID);
		// SendClientMessage(playerid, COLOR_ADMINCMD,string);
	// }
	// else if(intID == 32)
	// {
		// Businesses[bizID][ExitX] = -27.321363;
		// Businesses[bizID][ExitY] = -31.754938;
		// Businesses[bizID][ExitZ] = 1003.549988;
		// Businesses[bizID][ExitInterior] = 4;
		// Businesses[bizID][ExitAngle] = 356.70745;
		// format(string, sizeof string, "Business ID: %d - Description: 24-7 5.", bizID);
		// SendClientMessage(playerid, COLOR_ADMINCMD,string);
	// }
	// else if(intID == 33)
	// {
		// Businesses[bizID][ExitX] = -27.389696;
		// Businesses[bizID][ExitY] = -58.260951;
		// Businesses[bizID][ExitZ] = 1003.549988;
		// Businesses[bizID][ExitInterior] = 6;
		// Businesses[bizID][ExitAngle] = 358.27413;
		// Businesses[bizID][BizPrice] = 4000000;
		// format(string, sizeof string, "Business ID: %d - Description: 24-7 6.", bizID);
		// SendClientMessage(playerid, COLOR_ADMINCMD,string);
	// }
	// else if(intID == 35)
	// {
		// Businesses[bizID][ExitX] = -2213.684814;
		// Businesses[bizID][ExitY] = 1143.244140;
		// Businesses[bizID][ExitZ] = 173.895568;
		// Businesses[bizID][ExitInterior] = 0;
		// Businesses[bizID][ExitAngle] = 0.0;
		// format(string, sizeof string, "Business ID: %d - Description: Kibelek", bizID);
		// SendClientMessage(playerid, COLOR_ADMINCMD,string);
	// }
	// else if(intID == 36)
	// {
		// Businesses[bizID][ExitX] = -461.70;
		// Businesses[bizID][ExitY] = -2016.68;
		// Businesses[bizID][ExitZ] = 24.97;
		// Businesses[bizID][ExitInterior] = 1;
		// Businesses[bizID][ExitAngle] = 0.0;
		// format(string, sizeof string, "Business ID: %d - Description: Wiejskie Disco", bizID);
		// SendClientMessage(playerid, COLOR_ADMINCMD,string);
	// }
	// else if(intID == 37)
	// {
		// Businesses[bizID][ExitX] = 1285.54;
		// Businesses[bizID][ExitY] = -1652.21;
		// Businesses[bizID][ExitZ] = 13.74;
		// Businesses[bizID][ExitInterior] = 0;
		// Businesses[bizID][ExitAngle] = 0.458332;
		// format(string, sizeof string, "Business ID: %d - Description: Disco", bizID);
		// SendClientMessage(playerid, COLOR_ADMINCMD,string);
	// }
	// else if(intID == 38)
	// {
		// Businesses[bizID][ExitX] = 1003.77;
		// Businesses[bizID][ExitY] = 52.20;
		// Businesses[bizID][ExitZ] = 55.42;
		// Businesses[bizID][ExitInterior] = 3;
		// Businesses[bizID][ExitAngle] = 0.458332;
		// format(string, sizeof string, "Business ID: %d - Description: Sklep Elektrolux", bizID);
		// SendClientMessage(playerid, COLOR_ADMINCMD,string);
	// }
	// else if(intID == 39)
	// {
		// Businesses[bizID][ExitX] = 1513.09;
		// Businesses[bizID][ExitY] = -1576.66;
		// Businesses[bizID][ExitZ] = 24.55;
		// Businesses[bizID][ExitInterior] = 0;
		// Businesses[bizID][ExitAngle] = 0.458332;
		// format(string, sizeof string, "Business ID: %d - Description: Restauracja", bizID);
		// SendClientMessage(playerid, COLOR_ADMINCMD,string);
	// }
	// else if(intID == 40)
	// {
		// Businesses[bizID][ExitX] = 370.46;
		// Businesses[bizID][ExitY] = -1720.76;
		// Businesses[bizID][ExitZ] = 17.1;
		// Businesses[bizID][ExitInterior] = 0;
		// Businesses[bizID][ExitAngle] = 0.458332;
		// format(string, sizeof string, "Business ID: %d - Description: Restauracja", bizID);
		// SendClientMessage(playerid, COLOR_ADMINCMD,string);
	// }
	// else if(intID == 41)
	// {
		// Businesses[bizID][ExitX] = 2247.9302;
		// Businesses[bizID][ExitY] = 1595.4698;
		// Businesses[bizID][ExitZ] = 1018.8124;
		// Businesses[bizID][ExitInterior] = 10;
		// Businesses[bizID][ExitAngle] = 0.0;
		// format(string, sizeof string, "Business ID: %d - Description: Sklep komputerowy", bizID);
		// SendClientMessage(playerid, COLOR_ADMINCMD,string);
	// }
	// SaveBizData(bizID, "ExitX");
	// SaveBizData(bizID, "ExitY");
	// SaveBizData(bizID, "ExitZ");
	// SaveBizData(bizID, "ExitInterior");
	// SaveBizData(bizID, "ExitAngle");

	// format(string, sizeof(string), "[GOVERNMENT:] Business interior change by: %s, biz id: %d, interior id: %d", gPlayerData[playerid][pName], bizID, intID);
	// GovermentLog(string);
	// return 1;
}

dcmd_onofftraseb(playerid, params[])
{
	if( gPlayerData[playerid][pFaction] != 9 && gPlayerData[playerid][pAdmin] == 0 )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ urzêdnikiem !");
		return 1;
	}
	if( gPlayerData[playerid][pRank] > 3 && gPlayerData[playerid][pAdmin] == 0 )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Masz za nisk¹ rangê - nie mo¿esz konfigurowaæ tras autobusów !");
		return 1;
	}
	new trackID, enabled;
	if( sscanf( params, "dd", trackID, enabled ) )
	{
		SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] /onofftraseb [id trasy] [onf/off]");
		return 1;
	}
	gBusTrackEnabled[trackID] = enabled;
	SaveBusTrack( trackID, "gBusTrackEnabled" );
	return 1;
}

dcmd_trasybon(playerid, params[])
{
	#pragma unused params
	if( gPlayerData[playerid][pAdmin] == 0 )
		return 0;
	new string[128];
	for(new i = 0; i < 50; i++ )
	{
		if( gBusTrackEnabled[i] )
			format(string, sizeof(string), "%s %d -", string, i );
	}
	SendClientMessage( playerid, COLOR_LIGHTYELLOW2, string );
	return 1;
}

dcmd_ustawcpb(playerid, params[])
{
	if( gPlayerData[playerid][pAdmin] == 0 )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ urzêdnikiem !");
		return 1;
	}
	if( gPlayerData[playerid][pAdmin] == 0 )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Masz za nisk¹ rangê - nie mo¿esz konfigurowaæ tras autobusów !");
		return 1;
	}
	new trackID, CPID, cpReward, cpType, cpTime, Float:cpX, Float: cpY, Float:cpZ, string[128];
	if( sscanf( params, "dddddfff", trackID, CPID, cpReward, cpType, cpTime, cpX, cpY, cpZ) )
	{
		if( sscanf( params, "ddddd", trackID, CPID, cpReward, cpType, cpTime ) )
		{
			SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] /ustawcpb [id trasy] [id cp] [reward] [typ cp] [time] [X] [Y] [Z]" );
			SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] X Z Y - optional" );
			return 1;
		}
	}
	if( cpX == 0.0 && cpY == 0.0 && cpZ == 0.0 )
		GetPlayerPos(playerid, cpX, cpY, cpZ);
	if( cpType == 0 )
	{
		if( IsPlayerInDynamicArea(playerid, gASanFierro) )
			gBusTrackStartArea[ trackID ] = 0;
		else if( IsPlayerInDynamicArea(playerid, gALosSantos1) )
			gBusTrackStartArea[ trackID ] = 1;
		else if( IsPlayerInDynamicArea(playerid, gALosSantos2) )
			gBusTrackStartArea[ trackID ] = 2;
		else if( IsPlayerInDynamicArea(playerid, gAAngelPine) )
			gBusTrackStartArea[ trackID ] = 3;
		else if( IsPlayerInDynamicArea(playerid, gAMontgomery) )
			gBusTrackStartArea[ trackID ] = 4;
		else if( IsPlayerInDynamicArea(playerid, gAPalominoCreek) )
			gBusTrackStartArea[ trackID ] = 5;
		else if( IsPlayerInDynamicArea(playerid, gABountyBay) )
			gBusTrackStartArea[ trackID ] = 6;
		else if( IsPlayerInDynamicArea(playerid, gADilimore) )
			gBusTrackStartArea[ trackID ] = 7;
		else if( IsPlayerInDynamicArea(playerid, gAFortCarson) )
			gBusTrackStartArea[ trackID ] = 8;
		else if( IsPlayerInDynamicArea(playerid, gALosSantos3) )
			gBusTrackStartArea[ trackID ] = 9;
		else if( IsPlayerInDynamicArea(playerid, gALosSantos4) )
			gBusTrackStartArea[ trackID ] = 10;
		else if( IsPlayerInDynamicArea(playerid, gALosSantos5) )
			gBusTrackStartArea[ trackID ] = 11;
		else if( IsPlayerInDynamicArea(playerid, gALosSantos6) )
			gBusTrackStartArea[ trackID ] = 12;
		else if( IsPlayerInDynamicArea(playerid, gALosSantos7) )
			gBusTrackStartArea[ trackID ] = 13;
		else if( IsPlayerInDynamicArea(playerid, gABlueBerryFarm) )
			gBusTrackStartArea[ trackID ] = 14;
		else if( IsPlayerInDynamicArea(playerid, gALosSantos8) )
			gBusTrackStartArea[ trackID ] = 15;
		else
		{
			SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Aby postawiæ punkt startowy musisz znajdowaæ siê na obszarze jednego z miast/wsi !");
			return 1;
		}
	}
	gBusTrackCpX[ trackID ][ CPID] = cpX;
	gBusTrackCpY[ trackID ][ CPID] = cpY;
	gBusTrackCpZ[ trackID ][ CPID] = cpZ;
	gBusTrackCpReward[ trackID ][ CPID] = cpReward;
	gBusTrackCpType[ trackID ][ CPID] = cpType;
	gBusTrackCpTime[ trackID ][ CPID] = cpTime;
	SaveBusTrack( trackID, "gBusTrackCP", CPID );
	SaveBusTrack( trackID, "gBusTrackStartArea" );
	
	format(string, sizeof(string), "[INFO:] New CP set, track id: %d, cp id: %d", trackID, CPID);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	
	return 1;
}

dcmd_onofftraset(playerid, params[])
{
	if( gPlayerData[playerid][pFaction] != 9 && gPlayerData[playerid][pAdmin] == 0 )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ urzêdnikiem !");
		return 1;
	}
	if( gPlayerData[playerid][pRank] > 3 && gPlayerData[playerid][pAdmin] == 0 )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Masz za nisk¹ rangê - nie mo¿esz konfigurowaæ trasy œmieciarek !");
		return 1;
	}
	new trackID, enabled;
	if( sscanf( params, "dd", trackID, enabled ) )
	{
		SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] /onofftraset [id trasy] [onf/off]");
		return 1;
	}
	gTrashTrackEnabled[trackID] = enabled;
	SaveTrashTrack( trackID, "gTrashTrackEnabled" );
	return 1;
}

dcmd_trasyton(playerid, params[])
{
	#pragma unused params
	if( gPlayerData[playerid][pAdmin] == 0 )
		return 0;
	new string[128];
	for(new i = 0; i < 50; i++ )
	{
		if( gTrashTrackEnabled[i] )
			format(string, sizeof(string), "%s %d -", string, i );
	}
	SendClientMessage( playerid, COLOR_LIGHTYELLOW2, string );
	return 1;
}

dcmd_ustawcpt(playerid, params[])
{
	if( gPlayerData[playerid][pAdmin] == 0 )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ urzêdnikiem !");
		return 1;
	}
	if( gPlayerData[playerid][pAdmin] == 0 )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Masz za nisk¹ rangê - nie mo¿esz konfigurowaæ tras œmierciarek !");
		return 1;
	}
	new trackID, CPID, cpReward, cpType, cpTime, Float:cpX, Float: cpY, Float:cpZ, string[128];
	if( sscanf( params, "dddddfff", trackID, CPID, cpReward, cpType, cpTime, cpX, cpY, cpZ) )
	{
		if( sscanf( params, "ddddd", trackID, CPID, cpReward, cpType, cpTime ) )
		{
			SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] /ustawcpt [id trasy] [id cp] [reward] [typ cp] [time] [X] [Y] [Z]" );
			SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] X Z Y - optional" );
			return 1;
		}
	}
	if( cpX == 0.0 && cpY == 0.0 && cpZ == 0.0 )
		GetPlayerPos(playerid, cpX, cpY, cpZ);
	if( cpType == 0 )
	{
		if( IsPlayerInDynamicArea(playerid, gASanFierro) )
			gTrashTrackStartArea[ trackID ] = 0;
		else if( IsPlayerInDynamicArea(playerid, gALosSantos1) )
			gTrashTrackStartArea[ trackID ] = 1;
		else if( IsPlayerInDynamicArea(playerid, gALosSantos2) )
			gTrashTrackStartArea[ trackID ] = 2;
		else if( IsPlayerInDynamicArea(playerid, gAAngelPine) )
			gTrashTrackStartArea[ trackID ] = 3;
		else if( IsPlayerInDynamicArea(playerid, gAMontgomery) )
			gTrashTrackStartArea[ trackID ] = 4;
		else if( IsPlayerInDynamicArea(playerid, gAPalominoCreek) )
			gTrashTrackStartArea[ trackID ] = 5;
		else if( IsPlayerInDynamicArea(playerid, gABountyBay) )
			gTrashTrackStartArea[ trackID ] = 6;
		else if( IsPlayerInDynamicArea(playerid, gADilimore) )
			gTrashTrackStartArea[ trackID ] = 7;
		else if( IsPlayerInDynamicArea(playerid, gAFortCarson) )
			gTrashTrackStartArea[ trackID ] = 8;
		else if( IsPlayerInDynamicArea(playerid, gALosSantos3) )
			gTrashTrackStartArea[ trackID ] = 9;
		else if( IsPlayerInDynamicArea(playerid, gALosSantos4) )
			gTrashTrackStartArea[ trackID ] = 10;
		else if( IsPlayerInDynamicArea(playerid, gALosSantos5) )
			gTrashTrackStartArea[ trackID ] = 11;
		else if( IsPlayerInDynamicArea(playerid, gALosSantos6) )
			gTrashTrackStartArea[ trackID ] = 12;
		else if( IsPlayerInDynamicArea(playerid, gALosSantos7) )
			gTrashTrackStartArea[ trackID ] = 13;
		else if( IsPlayerInDynamicArea(playerid, gALosSantos8) )
			gTrashTrackStartArea[ trackID ] = 15;
		else
		{
			SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Aby postawiæ punkt startowy musisz znajdowaæ siê na obszarze jednego z miast/wsi !");
			return 1;
		}
	}
	gTrashTrackCpX[ trackID ][ CPID] = cpX;
	gTrashTrackCpY[ trackID ][ CPID] = cpY;
	gTrashTrackCpZ[ trackID ][ CPID] = cpZ;
	gTrashTrackCpReward[ trackID ][ CPID] = cpReward;
	gTrashTrackCpType[ trackID ][ CPID] = cpType;
	gTrashTrackCpTime[ trackID ][ CPID] = cpTime;
	SaveTrashTrack( trackID, "gTrashTrackCP", CPID );
	SaveTrashTrack( trackID, "gTrashTrackStartArea" );
	
	format(string, sizeof(string), "[INFO:] New CP set, track id: %d, cp id: %d", trackID, CPID);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	
	return 1;
}

dcmd_onofftrases(playerid, params[])
{
	if(!gPlayerData[playerid][pAdmin])
		return 0;
	new trackID, enabled;
	if(sscanf( params, "dd", trackID, enabled))
	{
		SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] /onofftrases [id trasy] [onf/off]");
		return 1;
	}
	gSweeperTrackEnabled[trackID] = enabled;
	SaveSweeperTrack(trackID, "gSweeperTrackEnabled");
	return 1;
}

dcmd_onofftrasef(playerid, params[])
{
	if(!gPlayerData[playerid][pAdmin])
		return 0;
	new trackID, enabled;
	if(sscanf( params, "dd", trackID, enabled))
	{
		SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] /onofftrasef [id trasy] [onf/off]");
		return 1;
	}
	gFarmerTrackEnabled[trackID] = enabled;
	SaveFarmerTrack(trackID, "gFarmerTrackEnabled");
	return 1;
}

dcmd_trasyson(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new string[128];
	for(new i = 0; i < 50; i++)
	{
		if(gSweeperTrackEnabled[i])
			format(string, sizeof(string), "%s %d -", string, i);
	}
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	return 1;
}

dcmd_trasyfon(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new string[128];
	for(new i = 0; i < 50; i++)
	{
		if(gFarmerTrackEnabled[i])
			format(string, sizeof(string), "%s %d -", string, i);
	}
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	return 1;
}

dcmd_ustawcps(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new trackID, CPID, cpReward, cpType, cpTime, Float:cpX, Float: cpY, Float:cpZ, string[128];
	if(sscanf(params, "dddddfff", trackID, CPID, cpReward, cpType, cpTime, cpX, cpY, cpZ))
	{
		if(sscanf(params, "ddddd", trackID, CPID, cpReward, cpType, cpTime))
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /ustawcps [id trasy] [id cp] [reward] [typ cp] [time] [X] [Y] [Z]");
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] X Z Y - optional");
			return 1;
		}
	}
	if(cpX == 0.0 && cpY == 0.0 && cpZ == 0.0)
		GetPlayerPos(playerid, cpX, cpY, cpZ);
	if(cpType == 0)
	{
		if(IsPlayerInDynamicArea(playerid, gASanFierro))
			gSweeperTrackStartArea[ trackID ] = 0;
		else if(IsPlayerInDynamicArea(playerid, gALosSantos1))
			gSweeperTrackStartArea[ trackID ] = 1;
		else if(IsPlayerInDynamicArea(playerid, gALosSantos2))
			gSweeperTrackStartArea[ trackID ] = 2;
		else if(IsPlayerInDynamicArea(playerid, gAAngelPine))
			gSweeperTrackStartArea[ trackID ] = 3;
		else if(IsPlayerInDynamicArea(playerid, gAMontgomery))
			gSweeperTrackStartArea[ trackID ] = 4;
		else if(IsPlayerInDynamicArea(playerid, gAPalominoCreek))
			gSweeperTrackStartArea[ trackID ] = 5;
		else if(IsPlayerInDynamicArea(playerid, gABountyBay))
			gSweeperTrackStartArea[ trackID ] = 6;
		else if(IsPlayerInDynamicArea(playerid, gADilimore))
			gSweeperTrackStartArea[ trackID ] = 7;
		else if(IsPlayerInDynamicArea(playerid, gAFortCarson))
			gSweeperTrackStartArea[ trackID ] = 8;
		else if( IsPlayerInDynamicArea(playerid, gALosSantos3) )
			gSweeperTrackStartArea[ trackID ] = 9;
		else if( IsPlayerInDynamicArea(playerid, gALosSantos4) )
			gSweeperTrackStartArea[ trackID ] = 10;
		else if( IsPlayerInDynamicArea(playerid, gALosSantos5) )
			gSweeperTrackStartArea[ trackID ] = 11;
		else if( IsPlayerInDynamicArea(playerid, gALosSantos6) )
			gSweeperTrackStartArea[ trackID ] = 12;
		else if( IsPlayerInDynamicArea(playerid, gALosSantos7) )
			gSweeperTrackStartArea[ trackID ] = 13;
		else if( IsPlayerInDynamicArea(playerid, gALosSantos8) )
			gSweeperTrackStartArea[ trackID ] = 15;
		else
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Aby postawiæ punkt startowy musisz znajdowaæ siê na obszarze jednego z miast/wsi !");
			return 1;
		}
	}
	gSweeperTrackCpX[trackID][CPID] = cpX;
	gSweeperTrackCpY[trackID][CPID] = cpY;
	gSweeperTrackCpZ[trackID][CPID] = cpZ;
	gSweeperTrackCpReward[trackID][CPID] = cpReward;
	gSweeperTrackCpType[trackID][CPID] = cpType;
	gSweeperTrackCpTime[trackID][CPID] = cpTime;
	SaveSweeperTrack(trackID, "gSweeperTrackCP", CPID);
	SaveSweeperTrack(trackID, "gSweeperTrackStartArea");
	
	format(string, sizeof(string), "[INFO:] New CP set, track id: %d, cp id: %d", trackID, CPID);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	
	return 1;
}

dcmd_ustawcpf(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new trackID, CPID, cpReward, cpType, cpTime, Float:cpX, Float: cpY, Float:cpZ, string[128];
	if(sscanf(params, "dddddfff", trackID, CPID, cpReward, cpType, cpTime, cpX, cpY, cpZ))
	{
		if(sscanf(params, "ddddd", trackID, CPID, cpReward, cpType, cpTime))
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /ustawcps [id trasy] [id cp] [reward] [typ cp] [time] [X] [Y] [Z]");
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] X Z Y - optional");
			return 1;
		}
	}
	if(cpX == 0.0 && cpY == 0.0 && cpZ == 0.0)
		GetPlayerPos(playerid, cpX, cpY, cpZ);
	if(cpType == 0)
	{
		if(IsPlayerInDynamicArea(playerid, gASanFierro))
			gFarmerTrackStartArea[ trackID ] = 0;
		else if(IsPlayerInDynamicArea(playerid, gALosSantos1))
			gFarmerTrackStartArea[ trackID ] = 1;
		else if(IsPlayerInDynamicArea(playerid, gALosSantos2))
			gFarmerTrackStartArea[ trackID ] = 2;
		else if(IsPlayerInDynamicArea(playerid, gAAngelPine))
			gFarmerTrackStartArea[ trackID ] = 3;
		else if(IsPlayerInDynamicArea(playerid, gAMontgomery))
			gFarmerTrackStartArea[ trackID ] = 4;
		else if(IsPlayerInDynamicArea(playerid, gAPalominoCreek))
			gFarmerTrackStartArea[ trackID ] = 5;
		else if(IsPlayerInDynamicArea(playerid, gABountyBay))
			gFarmerTrackStartArea[ trackID ] = 6;
		else if(IsPlayerInDynamicArea(playerid, gADilimore))
			gFarmerTrackStartArea[ trackID ] = 7;
		else if(IsPlayerInDynamicArea(playerid, gAFortCarson))
			gFarmerTrackStartArea[ trackID ] = 8;
		else if(IsPlayerInDynamicArea(playerid, gABlueBerryFarm))
			gFarmerTrackStartArea[ trackID ] = 14;
		else if( IsPlayerInDynamicArea(playerid, gALosSantos3) )
			gFarmerTrackStartArea[ trackID ] = 9;
		else if( IsPlayerInDynamicArea(playerid, gALosSantos4) )
			gFarmerTrackStartArea[ trackID ] = 10;
		else if( IsPlayerInDynamicArea(playerid, gALosSantos5) )
			gFarmerTrackStartArea[ trackID ] = 11;
		else if( IsPlayerInDynamicArea(playerid, gALosSantos6) )
			gFarmerTrackStartArea[ trackID ] = 12;
		else if( IsPlayerInDynamicArea(playerid, gALosSantos7) )
			gFarmerTrackStartArea[ trackID ] = 13;
		else if( IsPlayerInDynamicArea(playerid, gALosSantos8) )
			gFarmerTrackStartArea[ trackID ] = 15;
		else
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Aby postawiæ punkt startowy musisz znajdowaæ siê na obszarze jednego z miast/wsi !");
			return 1;
		}
	}
	gFarmerTrackCpX[trackID][CPID] = cpX;
	gFarmerTrackCpY[trackID][CPID] = cpY;
	gFarmerTrackCpZ[trackID][CPID] = cpZ;
	gFarmerTrackCpReward[trackID][CPID] = cpReward;
	gFarmerTrackCpType[trackID][CPID] = cpType;
	gFarmerTrackCpTime[trackID][CPID] = cpTime;
	SaveFarmerTrack(trackID, "gFarmerTrackCP", CPID);
	SaveFarmerTrack(trackID, "gFarmerTrackStartArea");
	
	format(string, sizeof(string), "[INFO:] New CP set, track id: %d, cp id: %d", trackID, CPID);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	
	return 1;
}

dcmd_vehtypelist(playerid, params[])
{
	#pragma unused params
	if( gPlayerData[playerid][pAdmin] == 0 )
		return 0;
	new type;
	if( sscanf( params, "d", type ) )
	{
		SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] /vehtypelist [type id]" );
		return 1;
	}
	new string[128], string2[128], string3[128], string4[128], tmpstring[16], strsel;
	for(new i = 0; i < sizeof(gVehData); i++ )
	{
		if( gVehData[i][mVehType] == type )
		{
			if( strsel == 0 )
			{
				if( strlen( string ) > 121 )
					strsel = 1;
				else
				{
					format( tmpstring, sizeof(tmpstring), "- %d - ", i+1 );
					strcat( string, tmpstring );
				}
			}
			if( strsel == 1 )
			{
				if( strlen( string2 ) > 121 )
					strsel = 2;
				else
				{
					format( tmpstring, sizeof(tmpstring), "- %d - ", i+1 );
					strcat( string2, tmpstring );
				}
			}
			if( strsel == 2 )
			{
				if( strlen( string3 ) > 121 )
					strsel = 3;
				else
				{
					format( tmpstring, sizeof(tmpstring), "- %d - ", i+1 );
					strcat( string3, tmpstring );
				}
			}
			if( strsel == 3 )
			{
				if( strlen( string4 ) <= 121 )
				{
					format( tmpstring, sizeof(tmpstring), "- %d - ", i+1 );
					strcat( string4, tmpstring );
				}
			}
		}
	}
	SendClientMessage( playerid, COLOR_LIGHTYELLOW2, string );
	if( strsel > 0 )
		SendClientMessage( playerid, COLOR_LIGHTYELLOW2, string2 );
	if( strsel > 1 )
		SendClientMessage( playerid, COLOR_LIGHTYELLOW2, string3 );
	if( strsel > 2 )
		SendClientMessage( playerid, COLOR_LIGHTYELLOW2, string4 );
	return 1;
}

dcmd_fillbustracks( playerid, params[] )
{
	#pragma unused params
	if( gPlayerData[playerid][pAdmin] != 5 )
		return 0;
	new string[128];
	for( new i = 0; i < 50; i++ )
	{
		format( string, sizeof(string), "INSERT INTO `samp_bus_tracks` (`Enabled`) VALUES ('0')" );
		wp_mysql_query( string, SAVE, INVALID_PLAYER_ID, db_con2 );
	}
	for( new i = 0; i < 50; i++ )
	{
		for( new k = 0; k < 50; k++ )
		{
			format( string, sizeof(string), "INSERT INTO `samp_bus_tracks_data` (`TrackID`, `CPID`) VALUES ('%d', '%d')", i, k );
			wp_mysql_query( string, SAVE, INVALID_PLAYER_ID, db_con2 );
		}
	}
	return 1;
}

dcmd_filltrashtracks( playerid, params[] )
{
	#pragma unused params
	if( gPlayerData[playerid][pAdmin] != 5 )
		return 0;
	new string[128];
	for( new i = 0; i < 50; i++ )
	{
		format( string, sizeof(string), "INSERT INTO `samp_trash_tracks` (`Enabled`) VALUES ('0')" );
		wp_mysql_query( string, SAVE, INVALID_PLAYER_ID, db_con2 );
	}
	for( new i = 0; i < 50; i++ )
	{
		for( new k = 0; k < 50; k++ )
		{
			format( string, sizeof(string), "INSERT INTO `samp_trash_tracks_data` (`TrackID`, `CPID`) VALUES ('%d', '%d')", i, k );
			wp_mysql_query( string, SAVE, INVALID_PLAYER_ID, db_con2 );
		}
	}
	return 1;
}

dcmd_fillsweepertracks( playerid, params[] )
{
	#pragma unused params
	if( gPlayerData[playerid][pAdmin] != 5 )
		return 0;
	new string[128];
	for( new i = 0; i < 50; i++ )
	{
		format( string, sizeof(string), "INSERT INTO `samp_sweeper_tracks` (`Enabled`) VALUES ('0')" );
		wp_mysql_query( string, SAVE, INVALID_PLAYER_ID, db_con2 );
	}
	for( new i = 0; i < 50; i++ )
	{
		for( new k = 0; k < 50; k++ )
		{
			format( string, sizeof(string), "INSERT INTO `samp_sweeper_tracks_data` (`TrackID`, `CPID`) VALUES ('%d', '%d')", i, k );
			wp_mysql_query( string, SAVE, INVALID_PLAYER_ID, db_con2 );
		}
	}
	return 1;
}

dcmd_fillfarmertracks( playerid, params[] )
{
	#pragma unused params
	if( gPlayerData[playerid][pAdmin] != 5 )
		return 0;
	new string[128];
	for( new i = 0; i < 50; i++ )
	{
		format( string, sizeof(string), "INSERT INTO `samp_farmer_tracks` (`Enabled`) VALUES ('0')" );
		wp_mysql_query( string, SAVE, INVALID_PLAYER_ID, db_con2 );
	}
	for( new i = 0; i < 50; i++ )
	{
		for( new k = 0; k < 50; k++ )
		{
			format( string, sizeof(string), "INSERT INTO `samp_farmer_tracks_data` (`TrackID`, `CPID`) VALUES ('%d', '%d')", i, k );
			wp_mysql_query( string, SAVE, INVALID_PLAYER_ID, db_con2 );
		}
	}
	return 1;
}

dcmd_filltuning( playerid, params[] )
{
	#pragma unused params
	if( gPlayerData[playerid][pAdmin] != 5 )
		return 0;
	new string[128];
	for( new i = 0; i < sizeof(gVehData); i++ )
	{
		format( string, sizeof(string), "INSERT INTO `samp_vehicles_customize` (`Spoiler`) VALUES ('0')" );
		wp_mysql_query( string, SAVE, INVALID_PLAYER_ID, db_con2 );
	}
	return 1;
}

dcmd_abizprice( playerid, params[] )
{
	if( gPlayerData[playerid][pAdmin] < 2 )
		return 0;
	new bizID, bizPrice, string[128];
	if( sscanf( params, "dd", bizID, bizPrice ) )
	{
		SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] /abizprice [bizID] [bizPrice]" );
		return 1;
	}
	if( bizPrice < 0 )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] bizPrice > 0" );
		return 1;
	}
	Businesses[bizID][BizPrice] = bizPrice;
	SaveBizData(bizID, "BizPrice");
	if(Businesses[bizID][Owned] == 0)
	{
		format(string, sizeof(string), "Cena: $%d",Businesses[bizID][BizPrice]);
		UpdateDynamic3DTextLabelText(Business3DTextLabelC[bizID], COLOR_LIGHTBLUE2, string);
	}
	return 1;
}

dcmd_produkty(playerid, params[])
{
	if(gPlayerData[playerid][pJob] != 5)
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ sprzedawc¹ produktów");
		return 1;
	}
	if(!IsPlayerInAnyVehicle(playerid))
	{
		// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie 
	}
	new option[8];
	if(sscanf(params, "s[8]", option))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /produkty [kup/sprzedaj]");
		return 1;
	}
	if(strcmp( option, "kup", false, 3) == 0)
	{
		for(new i = 0; i < sizeof(gItemFactories); i++)
		{
		}
		return 1;
	}
	if(strcmp(option, "sprzedaj", false, 8) == 0)
	{
	
		return 1;
	}
	SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] /produkty [kup/sprzedaj]" );
	return 1;
}

dcmd_fullbatteries( playerid, params[] )
{
	#pragma unused params
	if( gPlayerData[playerid][pAdmin] != 5 )
		return 0;
	for( new i = 0; i < sizeof(gVehData); i++ )
	{
		gVehData[i][BatteryCapacity] = gVehData[i][BatteryMaxCapacity];
		SaveVehData(i, "BatteryCapacity" );
	}
	SendClientMessage( playerid, COLOR_GREEN, "[INFO:] Vehicle batteries fulled up u mother... !");
	return 1;
}

dcmd_fullbattery( playerid, params[] )
{
	#pragma unused params
	if( gPlayerData[playerid][pAdmin] < 3 )
		return 0;
	new vehid = GetPlayerVehicleID(playerid);
	if( vehid == INVALID_VEHICLE_ID )
		return 1;
	gVehData[vehid][BatteryCapacity] = gVehData[vehid][BatteryMaxCapacity];
	SaveVehData( vehid, "BatteryCapacity" );
	return 1;
}

dcmd_offvehlights( playerid, params[] )
{
	#pragma unused params
	if( gPlayerData[playerid][pAdmin] != 5 )
		return 0;
	for( new i = 0; i < sizeof(gVehData); i++ )
	{
		gVehData[i][LightsOn] = 0;
		SaveVehData( i, "LightsOn" );
		new enginedyn,lights,alarm,bonnet,boot,objective,doors;
		GetVehicleParamsEx(i-1, enginedyn, lights, alarm, doors, bonnet, boot, objective);
		SetVehicleParamsEx(i-1, enginedyn, 0, alarm, doors, bonnet, boot, objective);
	}
	SendClientMessage( playerid, COLOR_GREEN, "[INFO:] Tak kurwa, wy³¹czone");
	return 1;
}

dcmd_offvehradio( playerid, params[] )
{
	#pragma unused params
	if( gPlayerData[playerid][pAdmin] != 5 )
		return 0;
	for( new i = 0; i < sizeof(gVehData); i++ )
	{
		gVehData[i][RadioOn] = 0;
		SaveVehData( i, "RadioOn" );
	}
	SendClientMessage( playerid, COLOR_GREEN, "[INFO:] Potwierdzenie kurwa");
	return 1;
}

dcmd_radio( playerid, params[] )
{
	#pragma unused params
	SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] [DOM:] /radiod - /radiodoff" );
	SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] [BIZNES:] /radiob - /radioboff" );
	SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] [POJAZD:] /radios - /radiosoff - /radiosv" );
	return 1;
}

dcmd_taxi( playerid, params[] )
{
	new string[128];
	if( gPlayerData[playerid][pFaction] == 255 )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ liderem frakcji taksówkarskiej !" );
		return 1;
	}
	if( gPlayerData[playerid][pRank] != 1 || DynamicFactions[ gPlayerData[playerid][pFaction] ][fType] != 6 )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ liderem frakcji taksówkarskiej !" );
		return 1;
	}
	new option[16], value;
	if( sscanf( params, "s[16]d", option, value ) )
	{
		SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] /taxi [opcja] [kwota]" );
		SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] [opcja:] cenakm, wejsciowka" );
		return 1;
	}
	if( strcmp( option, "cenakm", true, 6 ) )
	{
		if( value <= 0 || value > 20 )
		{
			SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] /taxi cenakm [kwota]" );
			SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] [kwota:] od 1 do 20 ($)" );
			return 1;
		}
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fTaxiKMCost] = value;
		SaveFData( gPlayerData[playerid][pFaction], "TaxiKMCost" );
		
		for(new i = 0; i < sizeof(gVehData); i++)
		{
			if(gVehData[i][mVehFaction] == 255)
				continue;
			if(DynamicFactions[gVehData[i][mVehFaction]][fType] != 6)
				continue;
			UpdateDynamic3DTextLabelText(gVehData[i][Veh3DTaxiNfo], COLOR_YELLOW, "TAXI");
			if( DynamicFactions[ gVehData[i][mVehFaction] ][fTaxiEnterCost] > 0 )
				format( string, sizeof(string), "cena za KM: $%d + $%d", DynamicFactions[ gVehData[i][mVehFaction] ][fTaxiKMCost], DynamicFactions[ gVehData[i][mVehFaction] ][fTaxiEnterCost] );
			else
				format( string, sizeof(string), "cena za KM: $%d", DynamicFactions[ gVehData[i][mVehFaction] ][fTaxiKMCost] );
			UpdateDynamic3DTextLabelText(gVehData[i][Veh3DTaxiNfo2], COLOR_YELLOW, string);
		}
		return 1;
	}
	else if( strcmp( option, "wejsciowka", true, 10 ) )
	{
		if( value < 0 || value > 10 )
		{
			SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] /taxi wejsciowka [kwota]" );
			SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] [kwota:] od 0 do 10 ($)" );
			return 1;
		}
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fTaxiEnterCost] = value;
		SaveFData( gPlayerData[playerid][pFaction], "TaxiEnterCost" );
		
		for(new i = 0; i < sizeof(gVehData); i++)
		{
			if(gVehData[i][mVehFaction] == 255)
				continue;
			if(DynamicFactions[gVehData[i][mVehFaction]][fType] != 6)
				continue;
			UpdateDynamic3DTextLabelText(gVehData[i][Veh3DTaxiNfo], COLOR_YELLOW, "TAXI");
			if( DynamicFactions[ gVehData[i][mVehFaction] ][fTaxiEnterCost] > 0 )
				format( string, sizeof(string), "cena za KM: $%d + $%d", DynamicFactions[ gVehData[i][mVehFaction] ][fTaxiKMCost], DynamicFactions[ gVehData[i][mVehFaction] ][fTaxiEnterCost] );
			else
				format( string, sizeof(string), "cena za KM: $%d", DynamicFactions[ gVehData[i][mVehFaction] ][fTaxiKMCost] );
			UpdateDynamic3DTextLabelText(gVehData[i][Veh3DTaxiNfo2], COLOR_YELLOW, string);
		}
		return 1;
	}
	else
	{
		SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] /taxi [opcja] [kwota]" );
		SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] [opcja:] cenakm, wejsciowka" );
		return 1;
	}
}

dcmd_usunfrakcje( playerid, params[] )
{
	#pragma unused params
	if( gPlayerData[playerid][pFaction] == 255 )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ liderem ¿adnej frakcji !" );
		return 1;
	}
	if( gPlayerData[playerid][pRank] != 1 )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ liderem ¿adnej frakcji !" );
		return 1;
	}

	if( gPlayerData[playerid][pFaction] > 13 )
	{
		new string[256];

		format( string, sizeof(string), "UPDATE `samp_users` SET `Faction` = '255' WHERE `Faction` = '%d'", gPlayerData[playerid][pFaction] );
		wp_mysql_query( string, SAVE, INVALID_PLAYER_ID, db_con2);
		foreach(Player, i)
		{
			if( gPlayerData[i][pFaction] == gPlayerData[playerid][pFaction] && playerid != i )
			{
				gPlayerData[i][pFaction] = 255;
				SavePlayerData( i, "Faction" );
			}
		}

		for(new i = 0; i < sizeof(gVehData); i++)
		{
			if(gVehData[i][mVehFaction] == i)
				defer ResetVehicleData(i+1, 1);
		}

		ResetFactionData(gPlayerData[playerid][pFaction]);

		gPlayerData[playerid][pFaction] = 255;
		SavePlayerData( playerid, "Faction" );

		SendClientMessage( playerid, COLOR_GREEN, "[INFO:] Usun¹³eœ frakcje !" );
		return 1;
	}
	SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Tej frakcji nie mo¿na usun¹æ !" );
	return 1;
}

dcmd_usunfirme(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pFaction2] == 255)
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ prezesem ¿adnej firmy !" );
		return 1;
	}
	if(gPlayerData[playerid][pRank2] != 1)
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ prezesem ¿adnej firmy !" );
		return 1;
	}

	if(gPlayerData[playerid][pFaction2] > 13)
	{
		new string[256];

		format(string, sizeof(string), "DELETE FROM `samp_phones` WHERE `Faction` = '%d' ", gPlayerData[playerid][pFaction2]);
		wp_mysql_query( string, SAVE, INVALID_PLAYER_ID, db_con2);
		
		format(string, sizeof(string), "UPDATE `samp_users_other` SET `Faction2` = '255' WHERE `Faction2` = '%d'", gPlayerData[playerid][pFaction2]);
		wp_mysql_query( string, SAVE, INVALID_PLAYER_ID, db_con2);
		foreach(Player, i)
		{
			if( gPlayerData[i][pFaction2] == gPlayerData[playerid][pFaction] && playerid != i )
			{
				gPlayerData[i][pFaction2] = 255;
				SavePlayerData(i, "Faction2");
			}
		}

		for(new i = 0; i < sizeof(gVehData); i++)
		{
			if(gVehData[i][mVehFaction] == i)
				defer ResetVehicleData(i+1, 1);
		}
		
		
		ResetFactionData(gPlayerData[playerid][pFaction2]);

		gPlayerData[playerid][pFaction2] = 255;
		SavePlayerData( playerid, "Faction2" );

		SendClientMessage(playerid, COLOR_GREEN, "[INFO:] Usun¹³eœ frakcje !");
		return 1;
	}
	SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Tej frakcji nie mo¿na usun¹æ !" );
	return 1;
}

dcmd_utworzfrakcje(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pPlayingHours] < 30)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Musisz przegraæ co najmniej 30 godzin aby za³o¿yæ frakcje !" );
		return 1;
	}
	new string[256];
	format(string, sizeof(string), "1. Gang\n2. Korporacja taksówkarska\n3. Firma telekomunikacyjna\n4. Firma - sieæ obiektów us³ugowych");
	ShowPlayerDialog(playerid, DIALOG_MAKE_FACTION, DIALOG_STYLE_LIST, "Dostêpne typy frakcji", string, "Wybierz", "WyjdŸ");
	return 1;
}

dcmd_snews( playerid, params[] )
{
	if( gPlayerData[playerid][pAdmin] == 0 )
		return 0;
	new string[128];
	if( sscanf( params, "s[128]", string ) )
	{
		SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] /snews [content]" );
		return 1;
	}
	SendClientMessageToAll( COLOR_WHITE, "|___________WIADOMOŒÆ___________|" );
	format( string, sizeof(string), "Admin %s: %s", GetPlayerNameEx(playerid), string );
	SendClientMessageToAll( COLOR_DBLUE, string );
	return 1;
}

dcmd_news( playerid, params[] )
{
	if( gPlayerData[playerid][pFaction] != 9 )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ urzêdnikiem !" );
		return 1;
	}
	new string[128];
	if( sscanf( params, "s[128]", string ) )
	{
		SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] /news [treœæ]" );
		return 1;
	}
	SendClientMessageToAll( COLOR_WHITE, "|___________WIADOMOŒÆ OD URZÊDU___________|" );
	new rankName[64];
	switch( gPlayerData[playerid][pRank] )
	{
		case 1: { format(rankName, sizeof(rankName), "%s", DynamicFactions[ gPlayerData[playerid][pFaction] ][fRank1]); }
		case 2: { format(rankName, sizeof(rankName), "%s", DynamicFactions[ gPlayerData[playerid][pFaction] ][fRank2]); }
		case 3: { format(rankName, sizeof(rankName), "%s", DynamicFactions[ gPlayerData[playerid][pFaction] ][fRank3]); }
		case 4: { format(rankName, sizeof(rankName), "%s", DynamicFactions[ gPlayerData[playerid][pFaction] ][fRank4]); }
		case 5: { format(rankName, sizeof(rankName), "%s", DynamicFactions[ gPlayerData[playerid][pFaction] ][fRank5]); }
		case 6: { format(rankName, sizeof(rankName), "%s", DynamicFactions[ gPlayerData[playerid][pFaction] ][fRank6]); }
		case 7: { format(rankName, sizeof(rankName), "%s", DynamicFactions[ gPlayerData[playerid][pFaction] ][fRank7]); }
		case 8: { format(rankName, sizeof(rankName), "%s", DynamicFactions[ gPlayerData[playerid][pFaction] ][fRank8]); }
		case 9: { format(rankName, sizeof(rankName), "%s", DynamicFactions[ gPlayerData[playerid][pFaction] ][fRank9]); }
		case 10: { format(rankName, sizeof(rankName), "%s", DynamicFactions[ gPlayerData[playerid][pFaction] ][fRank10]); }
	}
	format( string, sizeof(string), "%s %s: %s", rankName, GetPlayerNameEx(playerid), string );
	SendClientMessageToAll( COLOR_NEWS, string );
	return 1;
}

dcmd_specoff(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pModerator] == 0)
	{
		return 0;
	}
	
	TogglePlayerSpectating(playerid, 0);
	
	gSpectateID[playerid] = INVALID_PLAYER_ID;
	gSpectateType[playerid] = ADMIN_SPEC_TYPE_NONE;
	
	SetPlayerToPos(playerid, gPlayerData[playerid][pCrashX], gPlayerData[playerid][pCrashY], gPlayerData[playerid][pCrashZ]);
	SetPlayerVirtualWorld(playerid, gPlayerData[playerid][pCrashW]);
	SetPlayerInterior(playerid, gPlayerData[playerid][pCrashInt]);
	SetPlayerHealth(playerid, gPlayerData[playerid][pHP]);
	
	TogglePlayerControllable(playerid, 0);
	defer UnfreezePlayer(playerid);
	
	return 1;
}

dcmd_spec(playerid, params[])
{
	if(gPlayerData[playerid][pModerator] == 0)
		return 0;
	new givePlayerID;
	if(sscanf(params, "d", givePlayerID))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /spec [player id]");
		return 1;
	}
	
	if(!gPlayerLogged[givePlayerID])
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Player is offline");
		return 1;
	}

	// save weapon data
	GetPlayerWeaponData(playerid, 0, gPlayerData[playerid][pWSlot0], gPlayerData[playerid][pWSlot0Ammo]);
	SavePlayerData(playerid, "WSlot0");
	SavePlayerData(playerid, "WSlot0Ammo");

	GetPlayerWeaponData(playerid, 1, gPlayerData[playerid][pWSlot1], gPlayerData[playerid][pWSlot1Ammo]);
	SavePlayerData(playerid, "WSlot1");
	SavePlayerData(playerid, "WSlot1Ammo");

	GetPlayerWeaponData(playerid, 2, gPlayerData[playerid][pWSlot2], gPlayerData[playerid][pWSlot2Ammo]);
	SavePlayerData(playerid, "WSlot2");
	SavePlayerData(playerid, "WSlot2Ammo");

	GetPlayerWeaponData(playerid, 3, gPlayerData[playerid][pWSlot3], gPlayerData[playerid][pWSlot3Ammo]);
	SavePlayerData(playerid, "WSlot3");
	SavePlayerData(playerid, "WSlot3Ammo");

	GetPlayerWeaponData(playerid, 4, gPlayerData[playerid][pWSlot4], gPlayerData[playerid][pWSlot4Ammo]);
	SavePlayerData(playerid, "WSlot4");
	SavePlayerData(playerid, "WSlot4Ammo");

	GetPlayerWeaponData(playerid, 5, gPlayerData[playerid][pWSlot5], gPlayerData[playerid][pWSlot5Ammo]);
	SavePlayerData(playerid, "WSlot5");
	SavePlayerData(playerid, "WSlot5Ammo");

	GetPlayerWeaponData(playerid, 6, gPlayerData[playerid][pWSlot6], gPlayerData[playerid][pWSlot6Ammo]);
	SavePlayerData(playerid, "WSlot6");
	SavePlayerData(playerid, "WSlot6Ammo");

	GetPlayerWeaponData(playerid, 7, gPlayerData[playerid][pWSlot7], gPlayerData[playerid][pWSlot7Ammo]);
	SavePlayerData(playerid, "WSlot7");
	SavePlayerData(playerid, "WSlot7Ammo");

	GetPlayerWeaponData(playerid, 8, gPlayerData[playerid][pWSlot8], gPlayerData[playerid][pWSlot8Ammo]);
	SavePlayerData(playerid, "WSlot8");
	SavePlayerData(playerid, "WSlot8Ammo");

	GetPlayerWeaponData(playerid, 9, gPlayerData[playerid][pWSlot9], gPlayerData[playerid][pWSlot9Ammo]);
	SavePlayerData(playerid, "WSlot9");
	SavePlayerData(playerid, "WSlot9Ammo");

	GetPlayerWeaponData(playerid, 10, gPlayerData[playerid][pWSlot10], gPlayerData[playerid][pWSlot10Ammo]);
	SavePlayerData(playerid, "WSlot10");
	SavePlayerData(playerid, "WSlot10Ammo");

	GetPlayerWeaponData(playerid, 11, gPlayerData[playerid][pWSlot11], gPlayerData[playerid][pWSlot11Ammo]);
	SavePlayerData(playerid, "WSlot11");
	SavePlayerData(playerid, "WSlot11Ammo");

	GetPlayerWeaponData(playerid, 12, gPlayerData[playerid][pWSlot12], gPlayerData[playerid][pWSlot12Ammo]);
	SavePlayerData(playerid, "WSlot12");
	SavePlayerData(playerid, "WSlot12Ammo");

	GetPlayerPos(playerid, gPlayerData[playerid][pCrashX], gPlayerData[playerid][pCrashY], gPlayerData[playerid][pCrashZ]);
	gPlayerData[playerid][pCrashW] = GetPlayerVirtualWorld(playerid);
	gPlayerData[playerid][pCrashInt] = GetPlayerInterior(playerid);
	GetPlayerHealth(playerid, gPlayerData[playerid][pHP]);
	
	TogglePlayerSpectating(playerid, 1);
	SetPlayerVirtualWorld(playerid, GetPlayerVirtualWorld( givePlayerID ) );
	SetPlayerInterior(playerid, GetPlayerInterior( givePlayerID ) );
	
	if(IsPlayerInAnyVehicle(givePlayerID))
	{
		PlayerSpectateVehicle(playerid, GetPlayerVehicleID(givePlayerID));
		gSpectateType[playerid] = ADMIN_SPEC_TYPE_VEHICLE;
	}
	else
	{
		PlayerSpectatePlayer( playerid, givePlayerID );
		gSpectateType[playerid] = ADMIN_SPEC_TYPE_PLAYER;
	}
	
	gSpectateID[playerid] = givePlayerID;
	
	return 1;
}

dcmd_fillfactionstable( playerid, params[] )
{
	#pragma unused params
	if( gPlayerData[playerid][pAdmin] != 5 )
		return 0;
	new string[256];
	for( new i = 13; i < 500; i++ )
	{
		format( string, sizeof(string), "INSERT INTO `samp_factions_weapons` (`FactionID`) VALUES ('%d') ", i );
		wp_mysql_query( string, SAVE, INVALID_PLAYER_ID, db_con2 );
	}
	for( new i = 13; i < 500; i++ )
	{
		format( string, sizeof(string), "INSERT INTO `samp_factions_weapons2` (`FactionID`) VALUES ('%d') ", i );
		wp_mysql_query( string, SAVE, INVALID_PLAYER_ID, db_con2 );
	}
	for( new i = 13; i < 500; i++ )
	{
		format( string, sizeof(string), "INSERT INTO `samp_factions_payrank` (`FactionID`) VALUES ('%d') ", i );
		wp_mysql_query( string, SAVE, INVALID_PLAYER_ID, db_con2 );
	}
	return 1;
}

dcmd_svhp( playerid, params[] )
{
	dcmd_setvehhp( playerid, params );
	return 1;
}

dcmd_setvehhp( playerid, params[] )
{
	if( gPlayerData[playerid][pAdmin] != 5 )
		return 0;
	new vehID, Float:vehHP;
	if( sscanf( params, "df", vehID, vehHP ) )
	{
		SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] /setvehhp [vehid] [hp]" );
		return 1;
	}
	SetVehicleHealth( vehID, vehHP );
	gVehData[vehID-1][CarHealth] = vehHP;
	SaveVehData( vehID-1, "CarHealth" );
	return 1;
}

dcmd_ustawopis(playerid, params[])
{
	new string[128];
	
	if(sscanf(params, "s[128]", string))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /ustawopis [opis...]");
		return 1;
	}
	
	if(!gPlayerData[playerid][pFirstDescription])
	{
		gPlayerData[playerid][pFirstDescription] = 1;
		SavePlayerData(playerid, "FirstDescription");
		
		SendClientMessage(playerid, COLOR_GREEN, "[INFO:] Ustawi³eœ swój pierwszy poziom postaci !");
	}
	
	format(gPlayerData[playerid][pCharDescription], 128, string);
	SavePlayerData(playerid, "CharDescription");
	
	UpdateCharDescription(playerid);
	
	return 1;
}

dcmd_usunopis(playerid, params[])
{
	#pragma unused params
	
	strdel(gPlayerData[playerid][pCharDescription], 0, 64);
	strins(gPlayerData[playerid][pCharDescription], " ", 0);
	SavePlayerData(playerid, "CharDescription");
	
	UpdateCharDescription(playerid);
	
	return 1;
}

dcmd_pokazopis(playerid, params[])
{
	#pragma unused params
	
	new string[128];
	
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Twój opis:");
	
	if(strcmp(gPlayerData[playerid][pCharDescriptionColor], "white", true) == 0)
	{
		format(string, sizeof(string), "{FFFFFF} %s", gPlayerData[playerid][pCharDescription]);		
	}
	else if(strcmp(gPlayerData[playerid][pCharDescriptionColor], "yellow", true) == 0)
	{
		format(string, sizeof(string), "{FFFF00} %s", gPlayerData[playerid][pCharDescription]);		
	}
	else if(strcmp(gPlayerData[playerid][pCharDescriptionColor], "green", true) == 0)
	{
		format(string, sizeof(string), "{9ACD32} %s", gPlayerData[playerid][pCharDescription]);		
	}
	else if(strcmp(gPlayerData[playerid][pCharDescriptionColor], "red", true) == 0)
	{
		format(string, sizeof(string), "{A10000} %s", gPlayerData[playerid][pCharDescription]);		
	}
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	
	return 1;
}

dcmd_koloropisu(playerid, params[])
{
	new string[128];
	
	if(sscanf(params, "s[128]", string))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /koloropisu [kolor]");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] [kolor:] bialy, zolty, zielony, czerwony");
		
		return 1;
	}
	
	if(strcmp(string, "bialy", true, 5) == 0)
	{
		format(gPlayerData[playerid][pCharDescriptionColor], 32, "white");
		// format(gPlayerData[playerid][pCharDescriptionColor], 32, "%s", "{FFFFFF}");
		SavePlayerData(playerid, "CharDescriptionColor");
		
		UpdateCharDescription(playerid);
		
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Zmieni³eœ kolor opisu !");
		
		return 1;
	}
	else if(strcmp(string, "zolty", true, 5) == 0)
	{
		//format(gPlayerData[playerid][pCharDescriptionColor], 32, "FFFF00");
		format(gPlayerData[playerid][pCharDescriptionColor], 32, "yellow");
		SavePlayerData(playerid, "CharDescriptionColor");
		
		UpdateCharDescription(playerid);
		
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Zmieni³eœ kolor opisu !");
		
		return 1;
	}
	else if(strcmp(string, "zielony", true, 7) == 0)
	{
		//format(gPlayerData[playerid][pCharDescriptionColor], 32, "9ACD32");
		format(gPlayerData[playerid][pCharDescriptionColor], 32, "green");
		SavePlayerData(playerid, "CharDescriptionColor");
		
		UpdateCharDescription(playerid);
		
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Zmieni³eœ kolor opisu !");
		
		return 1;
	}
	else if(strcmp(string, "czerwony", true, 7) == 0)
	{
		//format(gPlayerData[playerid][pCharDescriptionColor], 32, "A10000");
		format(gPlayerData[playerid][pCharDescriptionColor], 32, "red");
		SavePlayerData(playerid, "CharDescriptionColor");
		
		UpdateCharDescription(playerid);
		
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Zmieni³eœ kolor opisu !");
		
		return 1;
	}
	else
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /koloropisu [kolor]");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] [kolor:] bialy, zolty, zielony, czerwony");
		
		return 1;
	}
}

dcmd_opis( playerid, params[] )
{
	#pragma unused params
	SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] /ustawopis - /usunopis - /pokazopis - /koloropisu" );
	return 1;
}

dcmd_obiekty( playerid, params[] )
{
	#pragma unused params
	
	ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, ""#COLOR_TITLE"Komendy", ""#COLOR_BEGIN2" * Komendy obiektów *\n   /stworzobiekt - /usunobiekt - /edytujobiekt - /przesunobiekt\n   /ustawobiekt - /daneobiektow - /listaobiektow", "Zamknij", "");
	
	return 1;
}

dcmd_listaobiektow(playerid, params[])
{
	#pragma unused params
	
	new string[1024];
	
	format(string, sizeof(string), "Lista stworzonych przez ciebie obiektów:\n\n");
	
	for(new i = 0; i < sizeof(gCustomObj); i++)
	{
		if(gCustomObj[i][cstSlotUsed] && strcmp(gCustomObj[i][cstObjOwner], gPlayerData[playerid][pName], false) == 0 && strlen(gCustomObj[i][cstObjOwner]) > 0)
		{
			format(string, sizeof(string), "%sObject ID: %d   -   model: %d\n", string, gCustomObj[i][cstObjID], gCustomObj[i][cstObjModel]);
		}
	}
	
	ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Lista obiektów", string, "Zamknij", "");
	return 1;
}

dcmd_prosbaobiznes(playerid, params[])
{
	new givePlayerID, bizID = -1;
	
	for(new i = 0; i < sizeof(Businesses); i++)
	{
		if(PlayerToPoint(1.0, playerid, Businesses[i][EnterX], Businesses[i][EnterY], Businesses[i][EnterZ]))
		{
			bizID = i;
			break;
		}
	}
	
	if(bizID == -1)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie znajdujesz siê przy ¿adnym biznesie");
		return 1;
	}
	
	if(sscanf(params, "d", givePlayerID))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /prosbaobzines [id urzêdnika]");
		return 1;
	}
	
	if(!IsPlayerConnected(givePlayerID))
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ten gracz nie jest po³¹czony !");
		return 1;
	}
	
	if(gPlayerData[givePlayerID][pFaction] != 9)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ta osoba nie jest urzêdnikiem !");
		return 1;
	}
	
	if(bizID > sizeof(Businesses) || bizID < 0)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie ma takiego biznesu !");
		return 1;
	}
	
	if(Businesses[bizID][Owned])
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ten biznes nie jest na sprzeda¿ !");
		return 1;
	}
	
	new Float:x, Float:y, Float:z;
	
	GetPlayerPos(givePlayerID, x, y, z);
	
	if(!IsPlayerInRangeOfPoint(playerid, 5.0, x, y, z))
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Jesteœ zbyt daleko od tej osoby !");
		return 1;
	}
	
	new string[128];
	
	gBizBoughtApprovalSendBy[givePlayerID] = playerid;
	gBizBoughtApprovalID[playerid] = bizID;
	
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Przekaz³eœ swoj¹ proœbe o biznes do urzêdnika");
	
	format(string, sizeof(string), "[INFO:] %s prosi o pozwolenie na kupno biznesu ID: %d", GetPlayerNameEx(playerid), bizID);
	SendClientMessage(givePlayerID, COLOR_LIGHTYELLOW2, string);
	
	SendClientMessage(givePlayerID, COLOR_LIGHTYELLOW2, "[INFO:] Aby wydaæ pozwolenie wpisz: /akceptuj kupnobiznesu");
	
	return 1;
}

dcmd_lotterycash(playerid, params[])
{
	if( gPlayerData[playerid][pAdmin] != 5 )
		return 0;
	new value;
	if( sscanf( params, "d", value ) )
	{
		SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] /lotterycash [value]" );
		return 1;
	}
	gLuckyLotteryCash = value;
	SaveLotteryData(-1);
	return 1;
}

dcmd_kumulacja(playerid, params[])
{
	#pragma unused params
	
	if(!IsPlayerInRangeOfPoint(playerid, 1.0, 359.0, 167.0, 1008.0) && gPlayerData[playerid][pAdmin] != 5)
	{
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Nie jesteœ w kolekturze !", "Zamknij", "");
		return 1;
	}
	
	new string[128], string2[128], Hour, Minute, Second;
	
	gettime(Hour, Minute, Second);

	if((gLuckyLotteryLastLottery == 2 && Hour < 21) || (gLuckyLotteryLastLottery == 3 && Hour >= 21))
	{
		format(string2, sizeof(string2), "ju¿ jutro!");
	}
	else if(gLuckyLotteryLastLottery == 3 && Hour < 21)
	{
		format(string2, sizeof(string2), "ju¿ dziœ!");
	}
	else if((gLuckyLotteryLastLottery == 1 && Hour < 21) || (gLuckyLotteryLastLottery == 2 && Hour >= 21))
	{
		format(string2, sizeof(string2), "odbêdzie siê za dwa dni.");
	}
	else if((gLuckyLotteryLastLottery == 0 && Hour < 21) || (gLuckyLotteryLastLottery == 1 && Hour >= 21))
	{
		format(string2, sizeof(string2), "odbêdzie siê za trzy dni.");
	}

	format(string, sizeof(string), "Kumulacja: $%d\n\nNastêpne losowanie %s", gLuckyLotteryCash, string2);
	ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", string, "Zamknij", "");
	
	return 1;
}

dcmd_ostatnielosowanie(playerid, params[])
{
	#pragma unused params
	
	if(!IsPlayerInRangeOfPoint(playerid, 1.0, 359.0, 167.0, 1008.0))
	{
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Nie jesteœ w kolekturze !", "Zamknij", "");
		return 1;
	}
	
	new string[128];
	
	format(string, sizeof(string), "Numer ostatniego losowania: %d\n\n[Numerek 1: %d]   [numerek 2: %d]   [numerek 3: %d]   [numerek 4: %d]", gLuckyLotteryID, gLuckyLotteryNumbers[0], gLuckyLotteryNumbers[1], gLuckyLotteryNumbers[2], gLuckyLotteryNumbers[3]);
	ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", string, "Zamknij", "" );
	
	return 1;
}

dcmd_wypelnijkupon(playerid, params[])
{
	if( gPlayerData[playerid][pCash] < 5 )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie masz pieniêdzy na kupon !" );
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Koszt kuponu to 5$" );
		return 1;
	}
	if( !IsPlayerInRangeOfPoint( playerid, 1.0, 359.0, 167.0, 1008.0 ) )
	{
		ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Nie jesteœ w kolekturze !", "Zamknij", "" );
		return 1;
	}

	new numbers[4];
	if( sscanf( params, "dddd", numbers[0], numbers[1], numbers[2], numbers[3] ) )
	{
		SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] /wypelnijkupon [numerek 1] [numerek 2] [numerek 3] [numerek 4]" );
		SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] Numerki od 0 do 49, nie mog¹ siê powtarzaæ" );
		return 1;
	}
	if( numbers[0] < 0 || numbers[0] > 49 || numbers[1] < 0 || numbers[1] > 49 || numbers[2] < 0 || numbers[2] > 49 || numbers[3] < 0 || numbers[3] > 49 )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Numerki od 0 do 49" );
		return 1;
	}
	if( numbers[0] == numbers[1] || numbers[0] == numbers[2] || numbers[0] == numbers[3] ||
		numbers[1] == numbers[2] || numbers[1] == numbers[3] ||
		numbers[2] == numbers[3] )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] /wypelnijkupon [numerek 1] [numerek 2] [numerek 3] [numerek 4]" );
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Numerki od 0 do 49, nie mog¹ siê powtarzaæ" );
		return 1;
	}
	for( new i = 0; i < sizeof(gLuckyLottery); i++ )
	{
		if( gLuckyLottery[i][LuckyNumbers][0] == numbers[0] && gLuckyLottery[i][LuckyNumbers][1] == numbers[1] &&
			gLuckyLottery[i][LuckyNumbers][2] == numbers[2] && gLuckyLottery[i][LuckyNumbers][3] == numbers[3] && strcmp( gLuckyLottery[i][LuckyPlayerName], gPlayerData[playerid][pName] ) == 0 )
		{
			SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Wystawi³eœ ju¿ kupon z identycznymi numerkami !" );
			SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Kupony nie mog¹ mieæ identycznych cyfr !" );
			return 1;
		}
	}
	new string[32];
	valstr(string,gLuckyLotteryID+1);
	if(InsertPlayerItemEx(playerid, 3, 10, numbers[0], numbers[1], numbers[2], numbers[3], string) == 0)
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie masz miejsca na kupon !" );
		return 1;
	}
	for(new i = 0; i < sizeof(gLuckyLottery); i++)
	{
		if( strcmp( gLuckyLottery[i][LuckyPlayerName], "None", false ) != 0 )
			continue;
		gLuckyLottery[i][LuckyID] = gLuckyLotteryID+1;
		format( gLuckyLottery[i][LuckyPlayerName], MAX_PLAYER_NAME, "%s", gPlayerData[playerid][pName] );
		gLuckyLottery[i][LuckyNumbers][0] = numbers[0];
		gLuckyLottery[i][LuckyNumbers][1] = numbers[1];
		gLuckyLottery[i][LuckyNumbers][2] = numbers[2];
		gLuckyLottery[i][LuckyNumbers][3] = numbers[3];
		gLuckyLotteryCash += 5;
		GivePlayerCash(playerid, -5);
		SaveLotteryData(i);
		break;
	}
	SendClientMessage( playerid, COLOR_GREEN, "[INFO:] Wype³ni³eœ kupon !" );
	return 1;
}

dcmd_filllotterytable(playerid, params[])
{
	#pragma unused params
	if( gPlayerData[playerid][pAdmin] != 5 )
		return 0;
	new string[128];
	for( new i = 0; i < 1000; i++ )
	{
		format( string, sizeof(string), "INSERT INTO `samp_lucky_lottery` (`number1`) VALUES ('-1')" );
		wp_mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
	}
	return 1;
}

dcmd_glosujza(playerid, params[])
{
	#pragma unused params
	if( gKickVotePlayerToKick == INVALID_PLAYER_ID )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] W tej chwili nie odbywa siê ¿adne g³osowanie !" );
		return 1;
	}
	if( gKickVotePlayerVote[playerid] == 1 )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Odda³eœ ju¿ swój g³os w tym g³osowaniu !" );
		return 1;
	}
	gKickVotePlayerVote[playerid] = 1;
	new string[128];
	format( string, sizeof(string), "[INFO:] Odda³eœ swój g³os w sprawie wyrzucenia gracza o ID %d", gKickVotePlayerToKick );
	SendClientMessage( playerid, COLOR_GREEN, string );
	return 1;
}

dcmd_wyrzucgracza(playerid, params[])
{
	new string[128];
	if( gPlayerData[playerid][pPlayingHours] < 10 )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Musisz przegraæ co najmniej 10 godzin aby rozpocz¹æ g³osowanie" );
		return 1;
	}
	if( gKickVoteStartCooldown[playerid] > 0 )
	{
		format( string, sizeof(string), "[INFO:] Musisz odczekaæ jeszcze %d sekund przed nastêpnym g³osowaniem !", gKickVoteStartCooldown[playerid] );
		SendClientMessage( playerid, COLOR_ORANGE, string );
		return 1;
	}
	if( gKickVotePlayerToKick != INVALID_PLAYER_ID )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Jest ju¿ rozpoczête inne g³osowanie, musisz poczekaæ na jego zakoñczenie zanim bêdziesz móg³ rozpocz¹æ nastêpne" );
		return 1;
	}
	new givePlayerID;
	if( sscanf( params, "d", givePlayerID ) )
	{
		SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] /wyrzucgracza [id gracza]" );
		return 1;
	}
	if( !IsPlayerConnected(givePlayerID) )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Ten gracz nie jest po³¹czony !" );
		return 1;
	}
	if( gPlayerData[givePlayerID][pAdmin] > 0 )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz g³osowaæ za wyrzuceniem administratora z gry !" );
		return 1;
	}
	gKickVotePlayerToKick = givePlayerID;
	gKickVoteStartCooldown[playerid] = 300; // 300s = 5min
	gKickVotePlayerVote[playerid] = 1;
	gKickVoteTimeLeft = 30;
	format( string, sizeof(string), "{DF013A}[WParty SERVER:]{FFFFFF} Gracz %s [%d] rozpocz¹³ g³osowanie w sprawie wyrzucenia gracza %s [%d]", gPlayerData[playerid][pOOCName], playerid, gPlayerData[givePlayerID][pOOCName], givePlayerID );
	SendClientMessageToAll( COLOR_DARKRED, string );
	SendClientMessageToAll( COLOR_DARKRED, "{DF013A}[WParty SERVER:]{FFFFFF} Aby oddaæ g³os za wpisz /glosujza" );
	return 1;
}

dcmd_dap(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	DestroyAllDynamicPickups();
	SendClientMessage( playerid, COLOR_GREEN, "[INFO:] Usuniêto wszystkie pickupy !" );
	return 1;
}

dcmd_przejmijster(playerid, params[])
{
	#pragma unused params
	new Float:pX, Float:pY, Float:pZ;
	GetPlayerPos(playerid, pX, pY, pZ);
	for(new i = 0; i < sizeof(gShips); i++)
	{
		if(PlayerToPoint(30.0, playerid, gShips[i][shipX], gShips[i][shipY], gShips[i][shipZ]))
		{
			for(new j = 0; j < CUSTOM_MAX_PLAYERS; j++)
			{
				if(!gPlayerLogged[j])
					continue;
				if(gIsOnAShip[j] == i)
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ktoœ ju¿ kieruje tym statkiem !");
					return 1;
				}
			}
			SendClientMessage(playerid, COLOR_GREEN, "[INFO:] Jesteœ teraz kapitanem tego statku !");
			gIsOnAShip[playerid] = i;
			return 1;
		}
	}
	return 1;
}

dcmd_opuscster(playerid, params[])
{
	#pragma unused params
	SendClientMessage(playerid, COLOR_GREEN, "[INFO:] Nie kierujesz ju¿ statkiem !");
	gIsOnAShip[playerid] = -1;
	return 1;
}

dcmd_houseplaced(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new hID, status;
	if(sscanf(params, "dd", hID, status))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /houseplaced [house ID] [0/1]");
		return 1;
	}
	Houses[hID][HPlaced] = status;
	SaveHouseData(hID, "Placed");
	return 1;
}

dcmd_bizplaced(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new bID, status;
	if(sscanf(params, "dd", bID, status))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /bizplaced [biz ID] [0/1]");
		return 1;
	}
	Businesses[bID][BPlaced] = status;
	SaveBizData(bID, "Placed");
	return 1;
}

dcmd_houseintset(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new hID, status;
	if(sscanf(params, "dd", hID, status))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /houseintset [house ID] [0/1]");
		return 1;
	}
	Houses[hID][HIntSet] = status;
	SaveHouseData(hID, "IntSet");
	return 1;
}

dcmd_bizintset(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new bID, status;
	if(sscanf(params, "dd", bID, status))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /bizintset [biz ID] [0/1]");
		return 1;
	}
	Businesses[bID][BIntSet] = status;
	SaveBizData(bID, "IntSet");
	return 1;
}

dcmd_itemfactorycmds(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /itemfactoryitemdata - /itemfactoryname - /itemfactorypos - /itemfactoryitem - /itemfactorycount - /itemfactoryminbuy");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /itemfactoryreproducecount - /itemfactoryprice");
	return 1;
}

dcmd_itemfactorydata(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new fID, slot;
	if(sscanf(params, "dd", fID, slot))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /itemfactorydata [fID] [slot (1-10)]");
		return 1;
	}
	new string[128];
	switch(slot)
	{
		case 1:
		{
			format(string, sizeof(string), "[INFO:] Item: %d, type: %d, count: %d, minBuy: %d, reproduceCount: %d, price: %d",
				gItemFactories[fID][item1], gItemFactories[fID][item1type], gItemFactories[fID][item1count], gItemFactories[fID][item1minBuy], gItemFactories[fID][item1reproduceCount], gItemFactories[fID][item1price]);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			format(string, sizeof(string), "[INFO:] Item name: %s", ItemName(gItemFactories[fID][item1type], gItemFactories[fID][item1]));
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
		}
		case 2:
		{
			format(string, sizeof(string), "[INFO:] Item: %d, type: %d, count: %d, minBuy: %d, reproduceCount: %d, price: %d",
				gItemFactories[fID][item2], gItemFactories[fID][item2type], gItemFactories[fID][item2count], gItemFactories[fID][item2minBuy], gItemFactories[fID][item2reproduceCount], gItemFactories[fID][item2price]);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			format(string, sizeof(string), "[INFO:] Item name: %s", ItemName(gItemFactories[fID][item2type], gItemFactories[fID][item2]));
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
		}
		case 3:
		{
			format(string, sizeof(string), "[INFO:] Item: %d, type: %d, count: %d, minBuy: %d, reproduceCount: %d, price: %d",
				gItemFactories[fID][item3], gItemFactories[fID][item3type], gItemFactories[fID][item3count], gItemFactories[fID][item3minBuy], gItemFactories[fID][item3reproduceCount], gItemFactories[fID][item3price]);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			format(string, sizeof(string), "[INFO:] Item name: %s", ItemName(gItemFactories[fID][item3type], gItemFactories[fID][item3]));
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
		}
		case 4:
		{
			format(string, sizeof(string), "[INFO:] Item: %d, type: %d, count: %d, minBuy: %d, reproduceCount: %d, price: %d",
				gItemFactories[fID][item4], gItemFactories[fID][item4type], gItemFactories[fID][item4count], gItemFactories[fID][item4minBuy], gItemFactories[fID][item4reproduceCount], gItemFactories[fID][item4price]);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			format(string, sizeof(string), "[INFO:] Item name: %s", ItemName(gItemFactories[fID][item4type], gItemFactories[fID][item4]));
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
		}
		case 5:
		{
			format(string, sizeof(string), "[INFO:] Item: %d, type: %d, count: %d, minBuy: %d, reproduceCount: %d, price: %d",
				gItemFactories[fID][item5], gItemFactories[fID][item5type], gItemFactories[fID][item5count], gItemFactories[fID][item5minBuy], gItemFactories[fID][item5reproduceCount], gItemFactories[fID][item5price]);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			format(string, sizeof(string), "[INFO:] Item name: %s", ItemName(gItemFactories[fID][item5type], gItemFactories[fID][item5]));
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
		}
		case 6:
		{
			format(string, sizeof(string), "[INFO:] Item: %d, type: %d, count: %d, minBuy: %d, reproduceCount: %d, price: %d",
				gItemFactories[fID][item6], gItemFactories[fID][item6type], gItemFactories[fID][item6count], gItemFactories[fID][item6minBuy], gItemFactories[fID][item6reproduceCount], gItemFactories[fID][item6price]);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			format(string, sizeof(string), "[INFO:] Item name: %s", ItemName(gItemFactories[fID][item6type], gItemFactories[fID][item6]));
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
		}
		case 7:
		{
			format(string, sizeof(string), "[INFO:] Item: %d, type: %d, count: %d, minBuy: %d, reproduceCount: %d, price: %d",
				gItemFactories[fID][item7], gItemFactories[fID][item7type], gItemFactories[fID][item7count], gItemFactories[fID][item7minBuy], gItemFactories[fID][item7reproduceCount], gItemFactories[fID][item7price]);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			format(string, sizeof(string), "[INFO:] Item name: %s", ItemName(gItemFactories[fID][item7type], gItemFactories[fID][item7]));
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
		}
		case 8:
		{
			format(string, sizeof(string), "[INFO:] Item: %d, type: %d, count: %d, minBuy: %d, reproduceCount: %d, price: %d",
				gItemFactories[fID][item8], gItemFactories[fID][item8type], gItemFactories[fID][item8count], gItemFactories[fID][item8minBuy], gItemFactories[fID][item8reproduceCount], gItemFactories[fID][item8price]);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			format(string, sizeof(string), "[INFO:] Item name: %s", ItemName(gItemFactories[fID][item8type], gItemFactories[fID][item8]));
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
		}
		case 9:
		{
			format(string, sizeof(string), "[INFO:] Item: %d, type: %d, count: %d, minBuy: %d, reproduceCount: %d, price: %d",
				gItemFactories[fID][item9], gItemFactories[fID][item9type], gItemFactories[fID][item9count], gItemFactories[fID][item9minBuy], gItemFactories[fID][item9reproduceCount], gItemFactories[fID][item9price]);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			format(string, sizeof(string), "[INFO:] Item name: %s", ItemName(gItemFactories[fID][item9type], gItemFactories[fID][item9]));
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
		}
		case 10:
		{
			format(string, sizeof(string), "[INFO:] Item: %d, type: %d, count: %d, minBuy: %d, reproduceCount: %d, price: %d",
				gItemFactories[fID][item10], gItemFactories[fID][item10type], gItemFactories[fID][item10count], gItemFactories[fID][item10minBuy], gItemFactories[fID][item10reproduceCount], gItemFactories[fID][item10price]);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			format(string, sizeof(string), "[INFO:] Item name: %s", ItemName(gItemFactories[fID][item10type], gItemFactories[fID][item10]));
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
		}
		default:
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /itemfactorydata [fID] [slot (1-10)]");
			return 1;
		}
	}
	return 1;
}

dcmd_itemfactoryname(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new fID, name[128];
	if(sscanf(params, "ds[128]", fID, name))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /itemfactoryname [fID] [name]");
		return 1;
	}
	strmid(gItemFactories[fID][fName], name, 0, strlen(name));
	SaveItemFactory(fID, "Name");
	ABroadCast(COLOR_YELLOW, "[INFO:] Item factory name has been changed", 5);
	return 1;
}

dcmd_itemfactorypos(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new fID;
	if(sscanf(params, "d", fID))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /itemfactorypos [fID]");
		return 1;
	}
	GetPlayerPos(playerid, gItemFactories[fID][fPosX], gItemFactories[fID][fPosY], gItemFactories[fID][fPosZ]);
	SaveItemFactory(fID, "Pos");
	DestroyDynamicCP(gItemFactories[fID][fCPID]);
	gItemFactories[fID][fCPID] = CreateDynamicCP(gItemFactories[fID][fPosX], gItemFactories[fID][fPosY], gItemFactories[fID][fPosZ], 3.0);
	ABroadCast(COLOR_YELLOW, "[INFO:] Item factory position has been changed", 5);
	return 1;
}

dcmd_itemfactoryitem(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new fID, slot, itemID, itemType;
	if(sscanf(params, "dddd", fID, slot, itemID, itemType))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /itemfactoryitem [fID] [slot (1-10)] [item ID] [item type]");
		return 1;
	}
	switch(slot)
	{
		case 1:
		{
			gItemFactories[fID][item1] = itemID;
			gItemFactories[fID][item1type] = itemType;
			SaveItemFactory(fID, "item1");
		}
		case 2:
		{
			gItemFactories[fID][item2] = itemID;
			gItemFactories[fID][item2type] = itemType;
			SaveItemFactory(fID, "item2");
		}
		case 3:
		{
			gItemFactories[fID][item3] = itemID;
			gItemFactories[fID][item3type] = itemType;
			SaveItemFactory(fID, "item3");
		}
		case 4:
		{
			gItemFactories[fID][item4] = itemID;
			gItemFactories[fID][item4type] = itemType;
			SaveItemFactory(fID, "item4");
		}
		case 5:
		{
			gItemFactories[fID][item5] = itemID;
			gItemFactories[fID][item5type] = itemType;
			SaveItemFactory(fID, "item5");
		}
		case 6:
		{
			gItemFactories[fID][item6] = itemID;
			gItemFactories[fID][item6type] = itemType;
			SaveItemFactory(fID, "item6");
		}
		case 7:
		{
			gItemFactories[fID][item7] = itemID;
			gItemFactories[fID][item7type] = itemType;
			SaveItemFactory(fID, "item7");
		}
		case 8:
		{
			gItemFactories[fID][item8] = itemID;
			gItemFactories[fID][item8type] = itemType;
			SaveItemFactory(fID, "item8");
		}
		case 9:
		{
			gItemFactories[fID][item9] = itemID;
			gItemFactories[fID][item9type] = itemType;
			SaveItemFactory(fID, "item9");
		}
		case 10:
		{
			gItemFactories[fID][item10] = itemID;
			gItemFactories[fID][item10type] = itemType;
			SaveItemFactory(fID, "item10");
		}
		default:
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /itemfactoryitem [fID] [slot (1-10)] [item ID] [item type]");
			return 1;
		}
	}
	ABroadCast(COLOR_YELLOW, "[INFO:] Item factory item has been changed", 5);
	return 1;
}

dcmd_itemfactorycount(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new fID, slot, itemCount;
	if(sscanf(params, "ddd", fID, slot, itemCount))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /itemfactorycount [fID] [slot (1-10)] [item count]");
		return 1;
	}
	switch(slot)
	{
		case 1:
		{
			gItemFactories[fID][item1count] = itemCount;
			SaveItemFactory(fID, "item1");
		}
		case 2:
		{
			gItemFactories[fID][item2count] = itemCount;
			SaveItemFactory(fID, "item2");
		}
		case 3:
		{
			gItemFactories[fID][item3count] = itemCount;
			SaveItemFactory(fID, "item3");
		}
		case 4:
		{
			gItemFactories[fID][item4count] = itemCount;
			SaveItemFactory(fID, "item4");
		}
		case 5:
		{
			gItemFactories[fID][item5count] = itemCount;
			SaveItemFactory(fID, "item5");
		}
		case 6:
		{
			gItemFactories[fID][item6count] = itemCount;
			SaveItemFactory(fID, "item6");
		}
		case 7:
		{
			gItemFactories[fID][item7count] = itemCount;
			SaveItemFactory(fID, "item7");
		}
		case 8:
		{
			gItemFactories[fID][item8count] = itemCount;
			SaveItemFactory(fID, "item8");
		}
		case 9:
		{
			gItemFactories[fID][item9count] = itemCount;
			SaveItemFactory(fID, "item9");
		}
		case 10:
		{
			gItemFactories[fID][item10count] = itemCount;
			SaveItemFactory(fID, "item10");
		}
		default:
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /itemfactoryitem [fID] [slot (1-10)] [item count]");
			return 1;
		}
	}
	ABroadCast(COLOR_YELLOW, "[INFO:] Item factory item count has been changed", 5);
	return 1;
}

dcmd_itemfactoryminbuy(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new fID, slot, itemMinBuy;
	if(sscanf(params, "ddd", fID, slot, itemMinBuy))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /itemfactoryminbuy [fID] [slot (1-10)] [item min buy]");
		return 1;
	}
	switch(slot)
	{
		case 1:
		{
			gItemFactories[fID][item1minBuy] = itemMinBuy;
			SaveItemFactory(fID, "item1");
		}
		case 2:
		{
			gItemFactories[fID][item2minBuy] = itemMinBuy;
			SaveItemFactory(fID, "item2");
		}
		case 3:
		{
			gItemFactories[fID][item3minBuy] = itemMinBuy;
			SaveItemFactory(fID, "item3");
		}
		case 4:
		{
			gItemFactories[fID][item4minBuy] = itemMinBuy;
			SaveItemFactory(fID, "item4");
		}
		case 5:
		{
			gItemFactories[fID][item5minBuy] = itemMinBuy;
			SaveItemFactory(fID, "item5");
		}
		case 6:
		{
			gItemFactories[fID][item6minBuy] = itemMinBuy;
			SaveItemFactory(fID, "item6");
		}
		case 7:
		{
			gItemFactories[fID][item7minBuy] = itemMinBuy;
			SaveItemFactory(fID, "item7");
		}
		case 8:
		{
			gItemFactories[fID][item8minBuy] = itemMinBuy;
			SaveItemFactory(fID, "item8");
		}
		case 9:
		{
			gItemFactories[fID][item9minBuy] = itemMinBuy;
			SaveItemFactory(fID, "item9");
		}
		case 10:
		{
			gItemFactories[fID][item10minBuy] = itemMinBuy;
			SaveItemFactory(fID, "item10");
		}
		default:
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /itemfactoryitem [fID] [slot (1-10)] [item min buy]");
			return 1;
		}
	}
	ABroadCast(COLOR_YELLOW, "[INFO:] Item factory item min buy has been changed", 5);
	return 1;
}

dcmd_itemfactoryreproducecount(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new fID, slot, itemProduceCount;
	if(sscanf(params, "ddd", fID, slot, itemProduceCount))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /itemfactoryproducecount [fID] [slot (1-10)] [item produce count]");
		return 1;
	}
	switch(slot)
	{
		case 1:
		{
			gItemFactories[fID][item1reproduceCount] = itemProduceCount;
			SaveItemFactory(fID, "item1");
		}
		case 2:
		{
			gItemFactories[fID][item2reproduceCount] = itemProduceCount;
			SaveItemFactory(fID, "item2");
		}
		case 3:
		{
			gItemFactories[fID][item3reproduceCount] = itemProduceCount;
			SaveItemFactory(fID, "item3");
		}
		case 4:
		{
			gItemFactories[fID][item4reproduceCount] = itemProduceCount;
			SaveItemFactory(fID, "item4");
		}
		case 5:
		{
			gItemFactories[fID][item5reproduceCount] = itemProduceCount;
			SaveItemFactory(fID, "item5");
		}
		case 6:
		{
			gItemFactories[fID][item6reproduceCount] = itemProduceCount;
			SaveItemFactory(fID, "item6");
		}
		case 7:
		{
			gItemFactories[fID][item7reproduceCount] = itemProduceCount;
			SaveItemFactory(fID, "item7");
		}
		case 8:
		{
			gItemFactories[fID][item8reproduceCount] = itemProduceCount;
			SaveItemFactory(fID, "item8");
		}
		case 9:
		{
			gItemFactories[fID][item9reproduceCount] = itemProduceCount;
			SaveItemFactory(fID, "item9");
		}
		case 10:
		{
			gItemFactories[fID][item10reproduceCount] = itemProduceCount;
			SaveItemFactory(fID, "item10");
		}
		default:
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /itemfactoryproducecount [fID] [slot (1-10)] [item produce count]");
			return 1;
		}
	}
	ABroadCast(COLOR_YELLOW, "[INFO:] Item factory item produce count has been changed", 5);
	return 1;
}

dcmd_itemfactoryprice(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new fID, slot, itemPrice;
	if(sscanf(params, "ddd", fID, slot, itemPrice))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /itemfactoryprice [fID] [slot (1-10)] [item price]");
		return 1;
	}
	switch(slot)
	{
		case 1:
		{
			gItemFactories[fID][item1price] = itemPrice;
			SaveItemFactory(fID, "item1");
		}
		case 2:
		{
			gItemFactories[fID][item2price] = itemPrice;
			SaveItemFactory(fID, "item2");
		}
		case 3:
		{
			gItemFactories[fID][item3price] = itemPrice;
			SaveItemFactory(fID, "item3");
		}
		case 4:
		{
			gItemFactories[fID][item4price] = itemPrice;
			SaveItemFactory(fID, "item4");
		}
		case 5:
		{
			gItemFactories[fID][item5price] = itemPrice;
			SaveItemFactory(fID, "item5");
		}
		case 6:
		{
			gItemFactories[fID][item6price] = itemPrice;
			SaveItemFactory(fID, "item6");
		}
		case 7:
		{
			gItemFactories[fID][item7price] = itemPrice;
			SaveItemFactory(fID, "item7");
		}
		case 8:
		{
			gItemFactories[fID][item8price] = itemPrice;
			SaveItemFactory(fID, "item8");
		}
		case 9:
		{
			gItemFactories[fID][item9price] = itemPrice;
			SaveItemFactory(fID, "item9");
		}
		case 10:
		{
			gItemFactories[fID][item10price] = itemPrice;
			SaveItemFactory(fID, "item10");
		}
		default:
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /itemfactoryprice [fID] [slot (1-10)] [item price]");
			return 1;
		}
	}
	ABroadCast(COLOR_YELLOW, "[INFO:] Item factory item price has been changed", 5);
	return 1;
}

dcmd_testdriveareabuypos(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] < 5)
		return 0;
	GetPlayerPos(playerid, gDrivingTestAreaBuy[mPosX], gDrivingTestAreaBuy[mPosY], gDrivingTestAreaBuy[mPosZ]);
	gDrivingTestAreaBuy[mPosWorld] = GetPlayerVirtualWorld(playerid);
	gDrivingTestAreaBuy[mPosInterior] = GetPlayerInterior(playerid);
	SaveDrivingTestAreaBuy();
	DestroyDynamicPickup(gDrivingTestAreaBuy[pickupID]);
	gDrivingTestAreaBuy[pickupID] = CreateDynamicPickup(1239, 1, gDrivingTestAreaBuy[mPosX], gDrivingTestAreaBuy[mPosY], gDrivingTestAreaBuy[mPosZ], gDrivingTestAreaBuy[mPosWorld], gDrivingTestAreaBuy[mPosInterior]);
	ABroadCast(COLOR_YELLOW, "[INFO:] Test driving area buy pos changed", 5);
	return 1;
}

dcmd_testdriveareabuyprice(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] < 5)
		return 0;
	new price;
	if(sscanf(params, "d", price))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /testdriveareabuyprice [price]");
		return 1;
	}
	gDrivingTestAreaBuy[mPrice] = price;
	SaveDrivingTestAreaBuy();
	ABroadCast(COLOR_YELLOW, "Test drive area buy price changed", 5);
	return 1;
}

dcmd_testdriveareabuytime(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] < 5)
		return 0;
	new time;
	if(sscanf(params, "d", time))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /testdriveareabuytime [time]");
		return 1;
	}
	gDrivingTestAreaBuy[mTime] = time;
	SaveDrivingTestAreaBuy();
	ABroadCast(COLOR_YELLOW, "Test drive area buy time changed", 5);
	return 1;
}

dcmd_wykupdostepdoplacu(playerid, params[])
{
	#pragma unused params
	if(!PlayerToPoint(1.0, playerid, gDrivingTestAreaBuy[mPosX], gDrivingTestAreaBuy[mPosY], gDrivingTestAreaBuy[mPosZ]))
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w punkcie wykupu !");
		return 1;
	}
	if(gPlayerData[playerid][pCash] < gDrivingTestAreaBuy[mPrice])
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie masz wystarczaj¹co du¿o pieniêdzy !");
		return 1;
	}
	new string[128];
	GivePlayerCash(playerid, -gDrivingTestAreaBuy[mPrice]);
	gPlayerData[playerid][pTestAreaTimeLeft] += gDrivingTestAreaBuy[mTime];
	format(string, sizeof(string), "[INFO:] Wykupi³eœ dodatkowo %d minut na placu treningowym - suma %d minut", gDrivingTestAreaBuy[mTime], gPlayerData[playerid][pTestAreaTimeLeft]); 
	SendClientMessage(playerid, COLOR_GREEN, string);
	return 1;
}

dcmd_testdriveareaentrancepos(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] < 5)
		return 0;
	GetPlayerPos(playerid, gDrivingTestArea[posEntranceX], gDrivingTestArea[posEntranceY], gDrivingTestArea[posEntranceZ]);
	GetPlayerFacingAngle(playerid, gDrivingTestArea[posEntranceAngle]);
	gDrivingTestArea[posEntranceWorld] = GetPlayerVirtualWorld(playerid);
	gDrivingTestArea[posEntranceInterior] = GetPlayerInterior(playerid);
	SaveDrivingTestArea();
	DestroyDynamicPickup(gDrivingTestArea[pickupID1]);
	gDrivingTestArea[pickupID1] = CreateDynamicPickup(1239, 1, gDrivingTestArea[posEntranceX], gDrivingTestArea[posEntranceY], gDrivingTestArea[posEntranceZ], gDrivingTestArea[posEntranceWorld], gDrivingTestArea[posEntranceInterior]);
	ABroadCast(COLOR_YELLOW, "[INFO:] Test driving area entrance pos changed", 5);	
	return 1;
}

dcmd_testdriveareaexitpos(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] < 5)
		return 0;
	GetPlayerPos(playerid, gDrivingTestArea[posExitX], gDrivingTestArea[posExitY], gDrivingTestArea[posExitZ]);
	GetPlayerFacingAngle(playerid, gDrivingTestArea[posExitAngle]);
	gDrivingTestArea[posExitWorld] = GetPlayerVirtualWorld(playerid);
	gDrivingTestArea[posExitInterior] = GetPlayerInterior(playerid);
	SaveDrivingTestArea();
	DestroyDynamicPickup(gDrivingTestArea[pickupID2]);
	gDrivingTestArea[pickupID2] = CreateDynamicPickup(1239, 1, gDrivingTestArea[posExitX], gDrivingTestArea[posExitY], gDrivingTestArea[posExitZ], gDrivingTestArea[posExitWorld], gDrivingTestArea[posExitInterior]);
	ABroadCast(COLOR_YELLOW, "[INFO:] Test driving area exit pos changed", 5);	
	return 1;
}

dcmd_testdriveprice(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] < 5)
		return 0;
	new category[4], price;
	if(sscanf(params, "s[4]d", category, price))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /testdriveprice [category] [price]");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] category: a, b, ce");
		return 1;
	}
	if(strcmp(category, "a", true) == 0)
	{
		gDrivingTestPosition[mPriceA] = price;
		SaveDrivingTestPosition();
	}
	else if(strcmp(category, "b", true) == 0)
	{
		gDrivingTestPosition[mPriceB] = price;
		SaveDrivingTestPosition();
	}
	else if(strcmp(category, "ce", true) == 0)
	{
		gDrivingTestPosition[mPriceCE] = price;
		SaveDrivingTestPosition();
	}
	ABroadCast(COLOR_YELLOW, "[INFO:] Test driver price changed", 5);
	return 1;
}

dcmd_testdrivelowprice(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] < 5)
		return 0;
	new category[4], price;
	if(sscanf(params, "s[4]d", category, price))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /testdrivelowprice [category] [price]");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] category: a, b, ce");
		return 1;
	}
	if(strcmp(category, "a", true) == 0)
	{
		gDrivingTestPosition[mPriceLowA] = price;
		SaveDrivingTestPosition();
	}
	else if(strcmp(category, "b", true) == 0)
	{
		gDrivingTestPosition[mPriceLowB] = price;
		SaveDrivingTestPosition();
	}
	else if(strcmp(category, "ce", true) == 0)
	{
		gDrivingTestPosition[mPriceLowCE] = price;
		SaveDrivingTestPosition();
	}
	ABroadCast(COLOR_YELLOW, "[INFO:] Test driver price changed", 5);
	return 1;
}

dcmd_testdrivebuypos(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] < 5)
		return 0;
	new category[8];
	if(sscanf(params, "%s[8]", category))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /testdrivebuypos [category]");
		return 1;
	}
	if(strcmp(category, "a", true, 1) == 0)
	{
		GetPlayerPos(playerid, gDrivingTestPosition[mPosXA], gDrivingTestPosition[mPosYA], gDrivingTestPosition[mPosZA]);
		gDrivingTestPosition[mPosWorldA] = GetPlayerVirtualWorld(playerid);
		gDrivingTestPosition[mPosInteriorA] = GetPlayerInterior(playerid);
		DestroyDynamicPickup(gDrivingTestPosition[PickupIDA]);
		gDrivingTestPosition[PickupIDA] = CreateDynamicPickup(1239, 1, gDrivingTestPosition[mPosXA], gDrivingTestPosition[mPosYA], gDrivingTestPosition[mPosZA], gDrivingTestPosition[mPosWorldA], gDrivingTestPosition[mPosInteriorA]);
	}
	else if(strcmp(category, "b", true, 1) == 0)
	{
		GetPlayerPos(playerid, gDrivingTestPosition[mPosXB], gDrivingTestPosition[mPosYB], gDrivingTestPosition[mPosZB]);				
		gDrivingTestPosition[mPosWorldB] = GetPlayerVirtualWorld(playerid);
		gDrivingTestPosition[mPosInteriorB] = GetPlayerInterior(playerid);
		DestroyDynamicPickup(gDrivingTestPosition[PickupIDB]);
		gDrivingTestPosition[PickupIDB] = CreateDynamicPickup(1239, 1, gDrivingTestPosition[mPosXB], gDrivingTestPosition[mPosYB], gDrivingTestPosition[mPosZB], gDrivingTestPosition[mPosWorldB], gDrivingTestPosition[mPosInteriorB]);
	}
	else if(strcmp(category, "ce", true, 2) == 0)
	{
		GetPlayerPos(playerid, gDrivingTestPosition[mPosXCE], gDrivingTestPosition[mPosYCE], gDrivingTestPosition[mPosZCE]);		
		gDrivingTestPosition[mPosWorldCE] = GetPlayerVirtualWorld(playerid);
		gDrivingTestPosition[mPosInteriorCE] = GetPlayerInterior(playerid);
		DestroyDynamicPickup(gDrivingTestPosition[PickupIDCE]);
		gDrivingTestPosition[PickupIDCE] = CreateDynamicPickup(1239, 1, gDrivingTestPosition[mPosXCE], gDrivingTestPosition[mPosYCE], gDrivingTestPosition[mPosZCE], gDrivingTestPosition[mPosWorldCE], gDrivingTestPosition[mPosInteriorCE]);
	}
	SaveDrivingTestPosition();
	ABroadCast(COLOR_YELLOW, "[INFO:] Test driver pos changed", 5);
	return 1;
}

dcmd_rozpocznijtest(playerid, params[])
{
	#pragma unused params
	if(!PlayerToPoint(15.0, playerid, gDrivingTestPosition[mPosXA], gDrivingTestPosition[mPosYA], gDrivingTestPosition[mPosZA]) &&
		!PlayerToPoint(15.0, playerid, gDrivingTestPosition[mPosXB], gDrivingTestPosition[mPosYB], gDrivingTestPosition[mPosZB]) &&
		!PlayerToPoint(15.0, playerid, gDrivingTestPosition[mPosXCE], gDrivingTestPosition[mPosYCE], gDrivingTestPosition[mPosZCE]))
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Musisz znajdowaæ siê w pomieszczeniu WORDu aby rozpocz¹æ test");
		return 1;
	}
	if(gTestResult[playerid])
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Zaliczy³eœ ju¿ test ! Teraz porozmawiaj z egzaminatorem");
		return 1;
	}
	gSelectedTest[playerid] = random(sizeof(gTestQuestions));
	new string[1024];
	if(TakingDrivingTestA[playerid] || TakingDrivingTestB[playerid] || TakingDrivingTestCE[playerid])
	{
		format(string, sizeof(string), "Pytanie nr 1\nPytanie nr 2\nPytanie nr 3\nPytanie nr 4\nPytanie nr 5\nZakoñcz test i poka¿ wynik");
		ShowPlayerDialog(playerid, DIALOG_DRIVINGTESTQ, DIALOG_STYLE_LIST, DIALOG_DRIVINGTESTQ_TITLE, string, "Wybierz", "");
		return 1;
	}
	else
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie wykupi³eœ ¿adnego testu !");
		return 1;
	}
}

dcmd_showq(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] < 5)
		return 0;
	new qNr;
	if(sscanf(params, "d", qNr))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /showq [q nr]");
		return 1;
	}
	SendClientMessage(playerid, COLOR_WHITE, gTestQuestions[qNr][q1]);
	return 1;
}

dcmd_wyrobdowod(playerid, params[])
{
	if(gPlayerData[playerid][pFaction] != FACTIONID_GOVERNMENT && !AdminDuty[playerid])
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ urzêdnikiem !");
		return 1;
	}
	new giveplayerid;
	if(sscanf(params, "d", giveplayerid))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /wyrobdowod [playerid]");
		return 1;
	}
	if(!IsPlayerConnected(giveplayerid) || !gPlayerLogged[giveplayerid])
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nieprawid³owe ID gracza");
		return 1;
	}
	if(InsertPlayerItemEx(giveplayerid, 3, 5, 0, 0, 0, 0, gPlayerData[giveplayerid][pName]) == 0)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ta osoba nie ma miejsca na otrzymanie dokumentu");
		return 1;
	}
	new string[128];
	format(string, sizeof(string), "[INFO:] Przekaza³eœ dowód %s", GetPlayerNameEx(giveplayerid));
	SendClientMessage(playerid, COLOR_GREEN, string);
	format(string, sizeof(string), "[INFO:] Otrzyma³eœ dowód od %s", GetPlayerNameEx(playerid));
	SendClientMessage(giveplayerid, COLOR_GREEN, string);
	format(string, sizeof(string), "przekazuje dowód %s", GetPlayerNameEx(giveplayerid));
	PlayerActionMessage(playerid, 15.0, string);	
	format(string, sizeof(string), "odbiera dowód od %s", GetPlayerNameEx(playerid));
	PlayerActionMessage(giveplayerid, 15.0, string);
	format(string, sizeof(string), "[GOVERNMENT:] Identity maked by: %s for %s", gPlayerData[playerid][pName], gPlayerData[giveplayerid][pName]);
	GovermentLog(string);
	return 1;
}

dcmd_wyrobprawojazdy(playerid, params[])
{
	if(gPlayerData[playerid][pFaction] != FACTIONID_GOVERNMENT && !AdminDuty[playerid])
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ urzêdnikiem !");
		return 1;
	}
	new giveplayerid, cat[2], string[128];
	if(sscanf(params, "ds[2]", giveplayerid, cat))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /wyrobdowod [playerid] [kategoria]");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] kategoria: a, b, ce");
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Jeœli osoba otrzymywa³a ju¿ prawo jazdy a nie posiada aktualnie przy sobie tego dokumentu poproœ j¹");
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] aby wróci³a wraz z nim chyba ¿e ten dokument zosta³ zagubiony");
		return 1;
	}
	if(!IsPlayerConnected(giveplayerid) || !gPlayerLogged[giveplayerid])
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nieprawid³owe ID gracza");
		return 1;
	}
	if(GetDistanceBetweenPlayers(playerid,giveplayerid) > 5.0)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ta osoba jest zbyt daleko !");
		return 1;
	}
	if(gPlayerData[giveplayerid][pCash] < DRIVING_LICENCE_COST)
	{
		format(string, sizeof(string), "[INFO:] Ta osoba nie ma pieniêdzy na prawo jazdy ! (koszt: %d)", DRIVING_LICENCE_COST);
		SendClientMessage(playerid, COLOR_ORANGE, string);
		return 1;
	}
	new slot, licSlot, days;
	slot = PHaveItem(giveplayerid, 3, 11);
	if(slot == 0)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ta osoba nie posiada dokumentu potwierdzaj¹cego zdanie prawa jazdy !");
		return 1;
	}
	PlayerActionMessage(playerid, 15.0, "sprawdza dokument");
	SlotParam5(giveplayerid, slot);
	if(strcmp(gDSelectedItemP5[giveplayerid], gPlayerData[giveplayerid][pName], false, strlen(gDSelectedItemP5[giveplayerid])) != 0)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Dokument przedstawiony przez t¹ osobe nie nale¿y do niej");
		return 1;
	}
	
	if(strcmp(cat, "a", true, 1) == 0 && SlotParam1(giveplayerid, slot) == 0)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Dokument posiadany przez t¹ osobe nie odnosi siê do prawa jazdy kat. A !");
		return 1;
	}
	else if(strcmp(cat, "a", true, 1) == 0 && SlotParam1(giveplayerid, slot) > 0)
	{
		days = SlotParam1(giveplayerid, slot);
		licSlot = PHaveItem(giveplayerid, 3, 6);
		if(licSlot > 0)
		{
			if(SlotParam1(giveplayerid, licSlot) > 0)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ta osoba posiada ju¿ prawo jazdy kat. A i nie mo¿na go przed³u¿yæ !");
				return 1;
			}
			else
			{
				SetPSlotParam1(giveplayerid, licSlot, days);
				RemovePlayerItemExUsed(giveplayerid, slot);
			}
		}
		else
		{
			licSlot = InsertPlayerItemEx(giveplayerid, 3, 6, days, 0, 0, 0, gPlayerData[giveplayerid][pName], 1);
			if(licSlot <= 0)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ta osoba nie ma miejsca na otrzymanie dokumentu");
				return 1;
			}
			RemovePlayerItemExUsed(giveplayerid, slot);		
		}
		format(string, sizeof(string), "[INFO:] Przekaza³eœ prawo jazdy dla %s", GetPlayerNameEx(giveplayerid));
		SendClientMessage(playerid, COLOR_GREEN, string);
		format(string, sizeof(string), "[INFO:] Otrzyma³eœ prawo jazdy kat. A od %s", GetPlayerNameEx(playerid));				
		SendClientMessage(playerid, COLOR_GREEN, string);
		format(string, sizeof(string), "przekazuje dokument oraz pieni¹dze do %s", GetPlayerNameEx(playerid));
		PlayerActionMessage(giveplayerid, 15.0, string);
		format(string, sizeof(string), "odbiera dokument oraz pieni¹dze od %s i przekazuje mu prawo jazdy", GetPlayerNameEx(giveplayerid));
		PlayerActionMessage(playerid, 15.0, string);
		format(string, sizeof(string), "odbiera prawo jazdy od %s", GetPlayerNameEx(playerid));
		PlayerActionMessage(giveplayerid, 15.0, string);
	}
	
	else if(strcmp(cat, "b", true, 1) == 0 && SlotParam2(giveplayerid, slot) == 0)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Dokument posiadany przez t¹ osobe nie odnosi siê do prawa jazdy kat. B !");
		return 1;
	}
	else if(strcmp(cat, "b", true, 1) == 0 && SlotParam2(giveplayerid, slot) > 0)
	{
		days = SlotParam2(giveplayerid, slot);
		licSlot = PHaveItem(giveplayerid, 3, 6);
		if(licSlot > 0)
		{
			if(SlotParam2(giveplayerid, licSlot) > 0)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ta osoba posiada ju¿ prawo jazdy kat. B i nie mo¿na go przed³u¿yæ !");
				return 1;
			}
			else
			{
				SetPSlotParam2(giveplayerid, licSlot, days);
				RemovePlayerItemExUsed(giveplayerid, slot);
			}
		}
		else
		{
			licSlot = InsertPlayerItemEx(giveplayerid, 3, 6, 0, days, 0, 0, gPlayerData[giveplayerid][pName], 1);
			if(licSlot <= 0)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ta osoba nie ma miejsca na otrzymanie dokumentu");
				return 1;
			}
			RemovePlayerItemExUsed(giveplayerid, slot);		
		}
		format(string, sizeof(string), "[INFO:] Przekaza³eœ prawo jazdy dla %s", GetPlayerNameEx(giveplayerid));
		SendClientMessage(playerid, COLOR_GREEN, string);
		format(string, sizeof(string), "[INFO:] Otrzyma³eœ prawo jazdy kat. B od %s", GetPlayerNameEx(playerid));				
		SendClientMessage(playerid, COLOR_GREEN, string);
		format(string, sizeof(string), "przekazuje dokument oraz pieni¹dze do %s", GetPlayerNameEx(playerid));
		PlayerActionMessage(giveplayerid, 15.0, string);
		format(string, sizeof(string), "odbiera dokument oraz pieni¹dze od %s i przekazuje mu prawo jazdy", GetPlayerNameEx(giveplayerid));
		PlayerActionMessage(playerid, 15.0, string);
		format(string, sizeof(string), "odbiera prawo jazdy od %s", GetPlayerNameEx(playerid));
		PlayerActionMessage(giveplayerid, 15.0, string);
	}
	else if(strcmp(cat, "ce", true, 1) == 0 && SlotParam3(giveplayerid, slot) == 0)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Dokument posiadany przez t¹ osobe nie odnosi siê do prawa jazdy kat. C+E !");
		return 1;
	}
	else if(strcmp(cat, "ce", true, 1) == 0 && SlotParam3(giveplayerid, slot) > 0)
	{
		days = SlotParam3(giveplayerid, slot);
		licSlot = PHaveItem(giveplayerid, 3, 6);
		if(licSlot > 0)
		{
			if(SlotParam3(giveplayerid, licSlot) > 0)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ta osoba posiada ju¿ prawo jazdy kat. C+E i nie mo¿na go przed³u¿yæ !");
				return 1;
			}
			else
			{
				SetPSlotParam3(giveplayerid, licSlot, days);
				RemovePlayerItemExUsed(giveplayerid, slot);
			}
		}
		else
		{
			licSlot = InsertPlayerItemEx(giveplayerid, 3, 6, 0, 0, days, 0, gPlayerData[giveplayerid][pName], 1);
			if(licSlot <= 0)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ta osoba nie ma miejsca na otrzymanie dokumentu");
				return 1;
			}
			RemovePlayerItemExUsed(giveplayerid, slot);		
		}
		format(string, sizeof(string), "[INFO:] Przekaza³eœ prawo jazdy dla %s", GetPlayerNameEx(giveplayerid));
		SendClientMessage(playerid, COLOR_GREEN, string);
		format(string, sizeof(string), "[INFO:] Otrzyma³eœ prawo jazdy kat. C+E od %s", GetPlayerNameEx(playerid));				
		SendClientMessage(playerid, COLOR_GREEN, string);
		format(string, sizeof(string), "przekazuje dokument oraz pieni¹dze do %s", GetPlayerNameEx(playerid));
		PlayerActionMessage(giveplayerid, 15.0, string);
		format(string, sizeof(string), "odbiera dokument oraz pieni¹dze od %s i przekazuje mu prawo jazdy", GetPlayerNameEx(giveplayerid));
		PlayerActionMessage(playerid, 15.0, string);
		format(string, sizeof(string), "odbiera prawo jazdy od %s", GetPlayerNameEx(playerid));
		PlayerActionMessage(giveplayerid, 15.0, string);
	}
	GivePlayerCash(giveplayerid, -DRIVING_LICENCE_COST);
	DynamicFactions[FACTIONID_GOVERNMENT][fBank] += DRIVING_LICENCE_COST;
	SaveFData(FACTIONID_GOVERNMENT, "Bank");
	return 1;
}
	
dcmd_egzaminnaprawko(playerid, params[])
{
	if(PHaveItemParam5Ex(playerid, 3, 18, gPlayerData[playerid][pName]) == -1)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ instruktorem nauki jazdy !");
		return 1;
	}
	
	new giveplayerid, status;
	
	if(sscanf(params, "dd", giveplayerid, status))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /egzaminnaprawko [playerid] [days] ");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] 0 - niezaliczony, >1 - zaliczony/liczba dni");
		return 1;
	}
	
	if(!TakingDrivingTestA[giveplayerid] && !TakingDrivingTestB[giveplayerid] && !TakingDrivingTestCE[giveplayerid])
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ta osoba nie bierze udzia³u w ¿adnym egzaminie !");
		return 1;
	}
	
	new string[128];
	
	format(string, sizeof(string), "[INFO:] Otrzyma³eœ $%d za przeprowadzenie egzaminu", DRIVING_INSTRUCTOR_REWARD);
	SendClientMessage(playerid, COLOR_GREEN, string);
	
	GivePlayerCash(playerid, DRIVING_INSTRUCTOR_REWARD);
	
	if(status > 0)
	{
		gTestResult[giveplayerid] = 0;
		if(TakingDrivingTestA[giveplayerid])
		{
			if(InsertPlayerItemEx(giveplayerid, 3, 11, status, 0, 0, 0, gPlayerData[giveplayerid][pName], 1) <= 0)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Gracz nie ma miejsca na przyjêcie dokumentu");
				return 1;
			}
			TakingDrivingTestA[giveplayerid] = 0;
			SendClientMessage(giveplayerid, COLOR_GREEN, "[INFO:] Zda³eœ prawo jazdy kat. A !");
			SendClientMessage(giveplayerid, COLOR_LIGHTYELLOW2, "[INFO:] Aby je otrzymaæ udaj siê do urzêdnika i przedstaw mu otrzymany dokument");
			return 1;
		}
		else if(TakingDrivingTestB[giveplayerid])
		{
			if(InsertPlayerItemEx(giveplayerid, 3, 11, 0, status, 0, 0, gPlayerData[giveplayerid][pName], 1) <= 0)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Gracz nie ma miejsca na przyjêcie dokumentu");
				return 1;
			}
			TakingDrivingTestB[giveplayerid] = 0;
			SendClientMessage(giveplayerid, COLOR_GREEN, "[INFO:] Zda³eœ prawo jazdy kat. B !");
			SendClientMessage(giveplayerid, COLOR_LIGHTYELLOW2, "[INFO:] Aby je otrzymaæ udaj siê do urzêdnika i przedstaw mu otrzymany dokument");
			return 1;
		}
		else if(TakingDrivingTestCE[giveplayerid])
		{
			if(InsertPlayerItemEx(giveplayerid, 3, 11, 0, 0, status, 0, gPlayerData[giveplayerid][pName], 1) <= 0)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Gracz nie ma miejsca na przyjêcie dokumentu");
				return 1;
			}
			TakingDrivingTestCE[giveplayerid] = 0;
			SendClientMessage(giveplayerid, COLOR_GREEN, "[INFO:] Zda³eœ prawo jazdy kat. C+E !");
			SendClientMessage(giveplayerid, COLOR_LIGHTYELLOW2, "[INFO:] Aby je otrzymaæ udaj siê do urzêdnika i przedstaw mu otrzymany dokument");
			return 1;
		}
	}
	else
	{
		gTestResult[giveplayerid] = 0;
		if(TakingDrivingTestA[giveplayerid])
		{
			TakingDrivingTestA[giveplayerid] = 0;
			SendClientMessage(giveplayerid, COLOR_RED, "[INFO:] Nie uda³o ci siê zaliczyæ egzaminu na prawo jazdy kat. A !");
			return 1;
		}
		else if(TakingDrivingTestB[giveplayerid])
		{
			TakingDrivingTestB[giveplayerid] = 0;
			SendClientMessage(giveplayerid, COLOR_RED, "[INFO:] Nie uda³o ci siê zaliczyæ egzaminu na prawo jazdy kat. B !");
			return 1;
		}
		else if(TakingDrivingTestCE[giveplayerid])
		{
			TakingDrivingTestCE[giveplayerid] = 0;
			SendClientMessage(giveplayerid, COLOR_RED, "[INFO:] Nie uda³o ci siê zaliczyæ egzaminu na prawo jazdy kat. CE !");
			return 1;
		}
	}
	return 1;
}

dcmd_ustawpacholki(playerid, params[])
{
	#pragma unused params
	if(IsPlayerInDynamicArea(playerid, gArea_CarTest))
	{
		// TODO: Load this FS olso by SendRconCommand instread config
		SendRconCommand("unloadfs wp_objects_testdrive");
		SendRconCommand("reloadfs wp_objects_testdrive");
		return 1;
	}
	SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie znajdujesz siê na placu manewrowym !");
	return 1;
}

dcmd_kanalooc(playerid, params[])
{
	new oocid;
	if(sscanf(params, "d", oocid))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /kanalooc [id kanalu (0-3)]");
		return 1;
	}
	if(oocid < 0 || oocid > 3)
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /kanalooc [id kanalu (0-3)]");
		return 1;
	}
	if(oocid == 3 && (gPlayerData[playerid][pVipAFK] > 0 || gPlayerData[playerid][pVipAFKT] > 0 || gPlayerData[playerid][pVipExp] > 0 || gPlayerData[playerid][pVipExpT] > 0))
	{
		gPlayerData[playerid][pOOCChanell] = 3;
		SavePlayerData(playerid, "OOCChanell");
	}
	else if(oocid == 3 && (gPlayerData[playerid][pVipAFK] <= 0 && gPlayerData[playerid][pVipAFKT] <= 0 && gPlayerData[playerid][pVipExp] <= 0 && gPlayerData[playerid][pVipExpT] <= 0))
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ten kana³ jest dostêpny tylko dla u¿ytkowników premium");
		return 1;
	}
	gPlayerData[playerid][pOOCChanell] = oocid;
	SavePlayerData(playerid, "OOCChanell");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Zmieni³eœ kana³ OOC");
	return 1;
}

dcmd_punktykarne(playerid, params[])
{
	if(gPlayerData[playerid][pFaction] == 255)
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Niew³aœciwa frakcja");
		return 1;
	}
	if(DynamicFactions[gPlayerData[playerid][pFaction]][fType] != F_POLICE)
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Niew³aœciwa frakcja");
		return 1;
	}
	if(!IsPlayerInAnyVehicle(playerid))
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Musisz byæ w radiowozie aby sprawdziæ te dane !");
		return 1;
	}
	new vehid = GetPlayerVehicleID(playerid);
	if(!gVehData[vehid-1][VPoliceComputer])
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ten pojazd nie posiada komputera w którym mo¿na by by³o sprawdziæ dane podejrzanego");
		return 1;
	}
	new giveplayerid;
	if(sscanf(params, "d", giveplayerid))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /punktykarne [playerid]");
		return 1;
	}
	if(!IsPlayerConnected(giveplayerid))
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Niew³aœciwe ID");
		return 1;
	}
	new string[128];
	format(string, sizeof(string), "Osoba: %s\n\nPunkty karne:\nKat. A: %d\nKat. B: %d\nKat. C: %d",
		GetPlayerNameEx(giveplayerid), gPlayerData[giveplayerid][pPenaltyPointsA],
		gPlayerData[giveplayerid][pPenaltyPointsB],
		gPlayerData[giveplayerid][pPenaltyPointsCE]);
	ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Komputer", string, "Zamknij", "");
	return 1;
}

dcmd_wymontujcb(playerid, params[])
{
	#pragma unused params
	
	if(gPlayerData[playerid][pJob] != JOB_MECHANIC && !AdminDuty[playerid])
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ mechanikiem");
		return 1;
	}
	
	if(gPlayerData[playerid][pFaction2] == 255)
	{
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Musisz nale¿eæ do firmy aby naprawiaæ pojazdy.", "Wróæ", "");
		return 1;
	}
	
	new inCompanyMech = 0;
	
	for(new i = 0; i < sizeof(Building); i++)
	{
		if(Building[i][FactionOwnerId] != gPlayerData[playerid][pFaction2])
		{
			continue;
		}
		
		if(!PlayerToPoint(15.0, playerid, Building[i][EnterX], Building[i][EnterY], Building[i][EnterZ]) && !PlayerToPoint(30.0, playerid, Building[i][ExitX], Building[i][ExitY], Building[i][ExitZ]))
		{
			continue;
		}
		
		inCompanyMech = 1;
	}
	
	if(!inCompanyMech && !AdminDuty[playerid])
	{
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Musisz znajdowaæ siê przy warsztacie twojej firmy.", "Wróæ", "");
		return 1;
	}
	
	new vehid = GetPlayerVehicleID(playerid);
	
	if(vehid == 0)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w pojeŸdzie");
		return 1;
	}
	
	if(!gVehData[vehid-1][VCBRadio])
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ten pojazd nie posiada CB radia !");
		return 1;
	}
	
	PlayerActionMessage(playerid, 15.0, "wymontowuje CB radio z pojazdu");
	
	if(gVehData[vehid-1][VCBRadio] == 1)
	{
		new slot = InsertPlayerItemEx(playerid, 1, 123, 0, 0, 0, 0, "Puste", 1);
		if(slot <= 0)
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie masz miejsca w schowku");
			return 1;
		}
		gVehData[vehid-1][VCBRadio] = 0;
		SaveVehData(vehid-1, "CBRadio");
	}
	else if(gVehData[vehid-1][VCBRadio] == 2)
	{
		new slot = InsertPlayerItemEx(playerid, 1, 124, 0, 0, 0, 0, "Puste", 1);
		if(slot <= 0)
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie masz miejsca w schowku");
			return 1;
		}
		gVehData[vehid-1][VCBRadio] = 0;
		SaveVehData(vehid-1, "CBRadio");
	}
	
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Wymontowa³eœ CB radio z pojazdu");
	
	return 1;
}
	
// dcmd_nadajpunktykarne(playerid, params[])
// {
	// new string[128];
	// if(gPlayerData[playerid][pFaction] == 255)
	// {
		// SendClientMessage(playerid, COLOR_RED, "[INFO:] Niew³aœciwa frakcja");
		// return 1;
	// }
	// if(DynamicFactions[gPlayerData[playerid][pFaction]][fType] != F_POLICE)
	// {
		// SendClientMessage(playerid, COLOR_RED, "[INFO:] Niew³aœciwa frakcja");
		// return 1;
	// }
	// if(!IsPlayerInAnyVehicle(playerid))
	// {
		// SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Musisz byæ w radiowozie aby sprawdziæ te dane !");
		// return 1;
	// }
	// new vehid = GetPlayerVehicleID(playerid);
	// if(!gVehData[vehid-1][VPoliceComputer])
	// {
		// SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ten pojazd nie posiada komputera w którym mo¿na by by³o sprawdziæ dane podejrzanego");
		// return 1;
	// }
	// new giveplayerid, count, category[2];
	// if(sscanf(params, "ds[2]d", giveplayerid, category, count))
	// {
		// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /nadajpunktkarny [playerid] [kategoria] [iloœæ]");
		// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] iloœæ: , kategorie: a, b, ce");
		// return 1;
	// }
	// if(!IsPlayerConnected(giveplayerid))
	// {
		// SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Niepoprawne ID !");
		// return 1;
	// }
	// new slot[MAX_PLAYER_ITEM_SLOT], haveLic;
	// PHaveItemEx(giveplayerid, 3, 6, slot);
	// PlayerActionMessage(playerid, 15.0, "sprawdza dane w kompuetrze");
	// if(strcmp(category, "a", true, 1) == 0)
	// {
		// for(new j = 0; j < MAX_PLAYER_ITEM_SLOT; j++)
		// {
			// SlotParam5(playerid, j+1);
			// if(slot[j] && SlotParam1(giveplayerid, j+1) && strcmp(gDSelectedItemP5[playerid], gPlayerData[playerid][pName], false, strlen(gPlayerData[playerid][pName])) == 0)
				// haveLic = j+1;
		// }
		// if(!haveLic)
		// {
			// SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz przyznaæ punktów karnych tej osobie poniewa¿ nie posiada ona prawa jazdy danej kategorii !");
			// return 1;
		// }
		// else
		// {
			// gPlayerData[giveplayerid][pPenaltyPointsA] += count;
			// SavePlayerData(giveplayerid, "PenaltyPointsA");
			// if(gPlayerData[giveplayerid][pPenaltyPointsA] >= MAX_PENALTY_POINTS)
			// {
				// format(string, sizeof(string), "[INFO:] Ta osoba przekroczy³a limit punktów (%d/%d) ! Prawo jazdy musi zostaæ skonfiskowane", gPlayerData[giveplayerid][pPenaltyPointsA], MAX_PENALTY_POINTS);
				// SendClientMessage(playerid, COLOR_RED, string);
				// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Aby skonfiskowaæ prawo jazdy wpisz /skonfiskuj prawko");
			// }
		// }
	// }
	// else if(strcmp(category, "b", true, 1) == 0)
	// {
		// for(new j = 0; j < MAX_PLAYER_ITEM_SLOT; j++)
		// {
			// if(slot[j] && SlotParam2(giveplayerid, j+1))
				// haveLic = j+1;
		// }
		// if(!haveLic)
		// {
			// SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz przyznaæ punktów karnych tej osobie poniewa¿ nie posiada ona prawa jazdy danej kategorii !");
			// return 1;
		// }
		// else
		// {
			// gPlayerData[giveplayerid][pPenaltyPointsB] += count;
			// SavePlayerData(giveplayerid, "PenaltyPointsB");
			// if(gPlayerData[giveplayerid][pPenaltyPointsB] >= MAX_PENALTY_POINTS)
			// {
				// format(string, sizeof(string), "[INFO:] Ta osoba przekroczy³a limit punktów (%d/%d) ! Prawo jazdy musi zostaæ skonfiskowane", gPlayerData[giveplayerid][pPenaltyPointsB], MAX_PENALTY_POINTS);
				// SendClientMessage(playerid, COLOR_RED, string);
				// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Aby skonfiskowaæ prawo jazdy wpisz /skonfiskuj prawko");
			// }
		// }
	// }
	// else if(strcmp(category, "ce", true, 1) == 0)
	// {
		// for(new j = 0; j < MAX_PLAYER_ITEM_SLOT; j++)
		// {
			// if(slot[j] && SlotParam3(giveplayerid, j+1))
				// haveLic = j+1;
		// }
		// if(!haveLic)
		// {
			// SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz przyznaæ punktów karnych tej osobie poniewa¿ nie posiada ona prawa jazdy danej kategorii !");
			// return 1;
		// }
		// else
		// {
			// gPlayerData[giveplayerid][pPenaltyPointsCE] += count;
			// SavePlayerData(giveplayerid, "PenaltyPointsCE");
			// if(gPlayerData[giveplayerid][pPenaltyPointsCE] >= MAX_PENALTY_POINTS)
			// {
				// format(string, sizeof(string), "[INFO:] Ta osoba przekroczy³a limit punktów (%d/%d) ! Prawo jazdy musi zostaæ skonfiskowane", gPlayerData[giveplayerid][pPenaltyPointsCE], MAX_PENALTY_POINTS);
				// SendClientMessage(playerid, COLOR_RED, string);
				// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Aby skonfiskowaæ prawo jazdy wpisz /skonfiskuj prawko");
			// }
		// }
	// }
	// return 1;
// }

dcmd_panelgracza(playerid, params[])
{
	dcmd_onoff(playerid, params);
	return 1;
}

dcmd_onoff(playerid, params[])
{
	#pragma unused params
	new form[1024];
	if(gPlayerData[playerid][pOOCStatus])
		format(form, sizeof(form), "Chat OOC					{33AA33}ON\n");
	else
		format(form, sizeof(form), "Chat OOC					{A10000}OFF\n");
	if(gPlayerData[playerid][pPWStatus])
		format(form, sizeof(form), "%sChat PW					{33AA33}ON\n", form);
	else
		format(form, sizeof(form), "%sChat PW					{A10000}OFF\n", form);
	if(PlayerStatusShowed[playerid])
		format(form, sizeof(form), "%sPasek statusu gracza				{33AA33}ON\n", form);
	else
		format(form, sizeof(form), "%sPasek statusu gracza				{A10000}OFF\n", form);
	if(ShowFuel[playerid])
		format(form, sizeof(form), "%sPasek statusu pojazdu				{33AA33}ON\n", form);
	else
		format(form, sizeof(form), "%sPasek statusu pojazdu				{A10000}OFF\n", form);
	if(gPlayerData[playerid][pShowHealthBars])
		format(form, sizeof(form), "%sPaski stanu zdrowia				{33AA33}ON\n", form);
	else
		format(form, sizeof(form), "%sPaski stanu zdrowia				{A10000}OFF\n", form);
	if(gPlayerData[playerid][pJoinInfoStatus])
		format(form, sizeof(form), "%sInfo o do³¹czeniu nowych graczy		{33AA33}ON\n", form);
	else
		format(form, sizeof(form), "%sInfo o do³¹czeniu nowych graczy		{A10000}OFF\n", form);
	if(gPlayerData[playerid][pLeaveInfoStatus])
		format(form, sizeof(form), "%sInfo o opuszczeniu gry przez graczy		{33AA33}ON\n", form);
	else
		format(form, sizeof(form), "%sInfo o opuszczeniu gry przez graczy		{A10000}OFF\n", form);
	if(gPlayerData[playerid][pTipsStatus])
		format(form, sizeof(form), "%sTipsy						{33AA33}ON\n", form);
	else
		format(form, sizeof(form), "%sTipsy						{A10000}OFF\n", form);
	if(gPlayerData[playerid][pBackgroundSoundStatus])
		format(form, sizeof(form), "%sDŸwiêki otoczenia				{33AA33}ON\n", form);
	else
		format(form, sizeof(form), "%sDŸwiêki otoczenia				{A10000}OFF\n", form);
	ShowPlayerDialog(playerid, DIALOG_ONOFF, DIALOG_STYLE_LIST, "Panel gracza", form, "Wybierz", "Zamknij");	
	return 1;
}

dcmd_hstatus(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new option[64], Float:value;
	if(sscanf(params, "s[64]f", option, value))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /hstatus [option] [value]");
		return 1;
	}
	if(strcmp(option, "energy", true, 6) == 0)
	{
		gPlayerData[playerid][pEnergy] = value;
		SavePlayerData(playerid, "Energy");
	}
	else if(strcmp(option, "hunger", true, 6) == 0)
	{
		gPlayerData[playerid][pHunger] = value;
		SavePlayerData(playerid, "Hunger");
	}
	else if(strcmp(option, "thirst", true, 6) == 0)
	{
		gPlayerData[playerid][pThirst] = value;
		SavePlayerData(playerid, "Thirst");
	}
	else if(strcmp(option, "poison", true, 6) == 0)
	{
		gPlayerData[playerid][pPoison] = value;
		SavePlayerData(playerid, "Poison");
	}
	else if(strcmp(option, "fat", true, 3) == 0)
	{
		gPlayerData[playerid][pFat] = value;
		SavePlayerData(playerid, "Fat");
	}
	else if(strcmp(option, "stomach", true, 7) == 0)
	{
		gPlayerData[playerid][pStomach] = value;
		SavePlayerData(playerid, "Stomach");
	}
	else if(strcmp(option, "vitamins", true, 8) == 0)
	{
		gPlayerData[playerid][pVitamins] = value;
		SavePlayerData(playerid, "Vitamins");
	}
	else if(strcmp(option, "drunk", true, 8) == 0)
	{
		gPlayerData[playerid][pDrunk] = value;
		SavePlayerData(playerid, "Drunk");
	}
	SetProgressBarValue(gPlayerData[playerid][pEnergyProgressBarID], gPlayerData[playerid][pEnergy]);
	UpdateProgressBar(gPlayerData[playerid][pEnergyProgressBarID], playerid);
	SetProgressBarValue(gPlayerData[playerid][pHungerProgressBarID], gPlayerData[playerid][pHunger]);
	UpdateProgressBar(gPlayerData[playerid][pHungerProgressBarID], playerid);
	SetProgressBarValue(gPlayerData[playerid][pThirstProgressBarID], gPlayerData[playerid][pThirst]);
	UpdateProgressBar(gPlayerData[playerid][pThirstProgressBarID], playerid);
	// SetProgressBarValue(gPlayerData[playerid][pPoisonProgressBarID], gPlayerData[playerid][pPoison]);
	// UpdateProgressBar(gPlayerData[playerid][pPoisonProgressBarID], playerid);
	// SetProgressBarValue(gPlayerData[playerid][pFatProgressBarID], gPlayerData[playerid][pFat]);
	// UpdateProgressBar(gPlayerData[playerid][pFatProgressBarID], playerid);
	// SetProgressBarValue(gPlayerData[playerid][pStomachProgressBarID], gPlayerData[playerid][pStomach]);
	// UpdateProgressBar(gPlayerData[playerid][pStomachProgressBarID], playerid);
	// SetProgressBarValue(gPlayerData[playerid][pVitaminsProgressBarID], gPlayerData[playerid][pVitamins]);
	// UpdateProgressBar(gPlayerData[playerid][pVitaminsProgressBarID], playerid);
	// SetProgressBarValue(gPlayerData[playerid][pDrunkProgressBarID], gPlayerData[playerid][pDrunk]);
	// UpdateProgressBar(gPlayerData[playerid][pDrunkProgressBarID], playerid);
	// SetProgressBarValue(gPlayerData[playerid][pNarcoticProgressBarID], gPlayerData[playerid][pNarcotic]);
	// UpdateProgressBar(gPlayerData[playerid][pNarcoticProgressBarID], playerid);
	if(!gPlayerData[playerid][pShowHealthBars])
	{
		HideProgressBarForPlayer(playerid, gPlayerData[playerid][pEnergyProgressBarID]);
		HideProgressBarForPlayer(playerid, gPlayerData[playerid][pHungerProgressBarID]);
		HideProgressBarForPlayer(playerid, gPlayerData[playerid][pThirstProgressBarID]);
		// HideProgressBarForPlayer(playerid, gPlayerData[playerid][pPoisonProgressBarID]);
		// HideProgressBarForPlayer(playerid, gPlayerData[playerid][pFatProgressBarID]);
		// HideProgressBarForPlayer(playerid, gPlayerData[playerid][pStomachProgressBarID]);
		// HideProgressBarForPlayer(playerid, gPlayerData[playerid][pVitaminsProgressBarID]);
		// HideProgressBarForPlayer(playerid, gPlayerData[playerid][pDrunkProgressBarID]);
		// HideProgressBarForPlayer(playerid, gPlayerData[playerid][pNarcoticProgressBarID]);
	}
	return 1;
}

dcmd_setplayerdrunk(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new lvl;
	if(sscanf(params, "d", lvl))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /setplayerdrunk [lvl]");
		return 1;
	}
	SetPlayerDrunkLevelEx(playerid, lvl);
	return 1;
}

dcmd_admissionchamberpos(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new id;
	if(sscanf(params, "d", id))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /admissionchamberpos [id (0-29)]");
		return 1;
	}
	GetPlayerPos(playerid, gAdmissionChambers[id][mPosX], gAdmissionChambers[id][mPosY], gAdmissionChambers[id][mPosZ]);
	gAdmissionChambers[id][mWorld] = GetPlayerVirtualWorld(playerid);
	gAdmissionChambers[id][mInt] = GetPlayerInterior(playerid);
	DestroyDynamicPickup(gAdmissionChambers[id][mPickupID]);
	gAdmissionChambers[id][mPickupID] = CreateDynamicPickup(1239, 23, gAdmissionChambers[id][mPosX], gAdmissionChambers[id][mPosY], gAdmissionChambers[id][mPosZ], gAdmissionChambers[id][mWorld], gAdmissionChambers[id][mInt]);
	SaveAdmissionChambers();
	ABroadCast(COLOR_YELLOW, "Admission chamber position has been changed", 5);
	return 1;
}

dcmd_przebadajpacjenta(playerid, params[])
{
	new targetid, isNearChamber, string[128];
	if(gPlayerData[playerid][pFaction] != FACTIONID_MEDICS && !AdminDuty[playerid])
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie jesteœ ratownikiem !");
		return 1;
	}
	if(!IsPlayerConnected(targetid) || !gPlayerLogged[targetid])
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ten gracz nie jest po³¹czony");
		return 1;
	}
	if(sscanf(params, "d", targetid))
	{
		SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] /przebadajpacjenta [id gracza]");
		return 1;
	}
	if(targetid == playerid && !AdminDuty[playerid])
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie mo¿esz sam siebie przebadaæ !");
		return 1;
	}
	for(new i = 0; i < sizeof(gAdmissionChambers); i++)
	{			
		if(PlayerToPoint(10.0, playerid, gAdmissionChambers[i][mPosX], gAdmissionChambers[i][mPosY], gAdmissionChambers[i][mPosZ]) && 
			GetPlayerVirtualWorld(playerid) == gAdmissionChambers[i][mWorld] && GetPlayerInterior(playerid) == gAdmissionChambers[i][mInt])
		{
			isNearChamber = 1;
		}
	}
	if(!isNearChamber && !AdminDuty[playerid])
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Jesteœ zbyt daleko od sali operacyjnej !");
		return 1;
	}			
	if(GetDistanceBetweenPlayers(playerid, targetid) > 2.0 && !AdminDuty[playerid])
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Jesteœ zbyt daleko od pacjenta");
		return 1;
	}
	gPlayerVars[targetid][mExamineID] = playerid;
	format(string, sizeof(string), "Czy zgadzasz siê ponieœæ op³ate za przebadanie w wysokoœci $%d ?",
		DynamicFactions[FACTIONID_MEDICS][fExaminePrice]);
	ShowPlayerDialog(targetid, DIALOG_EXAMINE_ASK, DIALOG_STYLE_MSGBOX, "Badanie", string, "Tak", "Nie");	
	return 1;
}

dcmd_govbiz(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new bizid, gov;

	if(sscanf(params, "dd", bizid, gov))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /govbiz [bizid] [gov]");
		return 1;
	}
	
	Businesses[bizid][BGov] = gov;
	strmid(Businesses[bizid][Owner], "Urz¹d", 0, 5, 255);
	
	SaveBizData(bizid, "Gov");
	SaveBizData(bizid, "Owner");	
	
	RefreshBizDescription(bizid);
	
	ABroadCast(COLOR_YELLOW, "businesses usable by government value changed", 5);
	return 1;
}

dcmd_wplacdobiznesu(playerid, params[])
{
	new cashdeposit, string[128];
	if(sscanf(params, "d", cashdeposit))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /wplacdobiznesu [kwota]");
		return 1;
	}
	if(cashdeposit <= 0)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Wp³acana wartoœæ musi byæ wiêksza od 0");
		return 1;
	}
	if(GetPlayerCash(playerid) < cashdeposit)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie masz tyle pieniêdzy !");
		return 1;
	}
	for(new i = 0; i < sizeof(Businesses); i++)
	{
		if(!PlayerToPoint(100.0, playerid, Businesses[i][ExitX], Businesses[i][ExitY], Businesses[i][ExitZ]) || GetPlayerVirtualWorld(playerid) != i)
			continue;
		if(strcmp(gPlayerData[playerid][pName], Businesses[i][Owner], false) != 0 && !Businesses[i][BGov])
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w³aœcicielem tego biznesu !");
			return 1;
		}
		if(Businesses[i][BGov] && gPlayerData[playerid][pFaction] != FACTIONID_GOVERNMENT)
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ urzêdnikiem");
			return 1;
		}
		
		ApplyAnimation(playerid, "DEALER", "shop_pay", 4.1, 0, 0, 0, 0, 0);
		
		GivePlayerCash(playerid, -cashdeposit);
		Businesses[i][Till] += cashdeposit;
		format(string, sizeof(string), "[INFO:] W³o¿y³eœ do kasy $%d, nowy stan: $%d", cashdeposit,Businesses[i][Till]);
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
		SaveBizData(i, "Till");
		format(string, sizeof(string), "[CASH:] Player: %s, donate: $%d, to biz id: %d", gPlayerData[playerid][pName], cashdeposit, i);
		PayLog(string);
		return 1;
	}
	SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Musisz znajdowaæ siê w biznesie aby wp³aciæ pieni¹dze");
	return 1;
}

dcmd_wyposazeniepojazdu(playerid, params[])
{
	#pragma unused params
	new vehid = GetPlayerVehicleID(playerid);
	if(vehid == 0)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w ¿adnym pojeŸdzie !");
		return 1;
	}
	new string[256];
	format(string, sizeof(string), "Model: %s", GetVehicleName(vehid));
	format(string, sizeof(string), "%s\nNr VIN: %d", string, gVehData[vehid-1][mVehVinNo]);
	if(gVehData[vehid-1][Fuel] == 0)
		strcat(string, "\nPaliwo: benzyna");
	else if(gVehData[vehid-1][Fuel] == 1)
		strcat(string, "\nPaliwo: ropa");
	else if(gVehData[vehid-1][Fuel] == 2)
		strcat(string, "\nPaliwo: LPG");
	else if(gVehData[vehid-1][Fuel] == 3)
		strcat(string, "\nPaliwo: paliwo lotnicze");
	format(string, sizeof(string), "%s\nSpalanie: %d", string, GetVehicleCombustion(vehid));
	format(string, sizeof(string), "%s\nPojemnoœæ baku: %dl", string, GetVehicleFuelTankSize(vehid)/1000);
	if(gVehData[vehid-1][Hook])
		strcat(string, "\nHak: tak");
	else
		strcat(string, "\nHak: nie");
	if(gVehData[vehid-1][Alarm])
		strcat(string, "\nAlarm: tak");
	else
		strcat(string, "\nAlarm: nie");
	if(gVehData[vehid-1][VCBRadio])
		strcat(string, "\nCB Radio: tak");
	else
		strcat(string, "\nCB Radio: nie");
	if(gVehData[vehid-1][VPoliceComputer])
		strcat(string, "\nKomputer policyjny: tak");
	else
		strcat(string, "\nKomputer policyjny: nie");
	switch(gVehData[vehid-1][BatteryID])
	{
		case 0: strcat(string, "\nAkumulator: fabryczny");
		case 1: strcat(string, "\nAkumulator: MaxKart");
		case 2: strcat(string, "\nAkumulator: Boss Light");
		case 3: strcat(string, "\nAkumulator: Boss Hard");
		case 4: strcat(string, "\nAkumulator: Vamta Standart");
		case 5: strcat(string, "\nAkumulator: Titanum Silver");
		case 6: strcat(string, "\nAkumulator: Ultivers Pro");
	}
	ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", string, "Zamknij", "");
	return 1;
}

dcmd_komputerpolicyjny(playerid, params[])
{
	dcmd_kp(playerid, params);
	return 1;
}

dcmd_kp(playerid, params[])
{
	#pragma unused params
	new vehid = GetPlayerVehicleID(playerid);
	
	if(vehid == 0)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Musisz byæ w radiowozie aby skorzystaæ z tej komendy !");
		return 1;
	}
	
	if(!gVehData[vehid-1][VPoliceComputer])
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ten pojazd nie posiada komputera policyjnego");
		return 1;
	}
	
	ShowPlayerDialog(playerid, DIALOG_LOGIN_KP, DIALOG_STYLE_INPUT, ""#COLOR_TITLE"Logowanie do panelu", "Podaj has³o do bazy danych.\nHas³o mo¿e zmieniæ lider frakcji.", "Loguj", "WyjdŸ");
	return 1;
}

dcmd_haslokp(playerid, params[])
{
	new string[64];
	if(gPlayerData[playerid][pFaction] != FACTIONID_POLICE && gPlayerData[playerid][pRank] != 1 && !AdminDuty[playerid])
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ liderem policji");
		return 1;
	}
	if(sscanf(params, "s[64]", string))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /haslokp [haslo]");
		return 1;
	}
	strmid(gPoliceComputerPassword, string, 0, 64, 255);
	SavePoliceComputerPassword();
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Zmieni³eœ has³o do komputer policyjnego");
	return 1;
}

dcmd_checkhp(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new giveplayerid;
	if(sscanf(params, "d", giveplayerid))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /checkhp [playerid]");
		return 1;
	}
	new string[128];
	format(string, sizeof(string), "[INFO:] Hunger: %.3f, Thirst: %.3f, Energy: %.3f, Poison: %.3f, Stomach: %.3f, Vitamins: %.3f",
		gPlayerData[giveplayerid][pHunger], gPlayerData[giveplayerid][pThirst], gPlayerData[giveplayerid][pEnergy], gPlayerData[giveplayerid][pPoison], gPlayerData[giveplayerid][pStomach], gPlayerData[giveplayerid][pVitamins]);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	
	format(string, sizeof(string), "[INFO:] Fat: %.3f, Alcohol: %.3f, Drugs: %.3f, Drug addict: %d, Drug effect: %d",
		gPlayerData[giveplayerid][pFat], gPlayerData[giveplayerid][pDrunk], gPlayerData[giveplayerid][pDrugs], gPlayerData[giveplayerid][pDrugsAddicted], gPlayerData[giveplayerid][pDrugsEffect]);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	
	return 1;
}

dcmd_setpgarage(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new giveplayerid, count, string[128];
	if(sscanf(params, "dd", giveplayerid, count))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /setpgarage [playerid] [count]");
		return 1;
	}
	if(!IsPlayerConnected(giveplayerid) || !gPlayerLogged[giveplayerid])
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Player not connected or not logged");
		return 1;
	}
	gPlayerData[giveplayerid][pVipGarage] = count;
	SavePlayerData(giveplayerid, "VipGarage");
	format(string, sizeof(string), "[INFO:] playerid %s [%d] garage count set to %d by %s [%d]",
		GetPlayerNameEx(giveplayerid), giveplayerid, count, GetPlayerNameEx(playerid), playerid);
	ABroadCast(COLOR_YELLOW, string, 5);
	return 1;
}

dcmd_setpneon(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new giveplayerid, string[128], count;
	if(sscanf(params, "ds[128]d", giveplayerid, string, count))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /giveneon [playerid] [color] [count]");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] color: red, blue, green, yellow, pink, white");
		return 1;
	}
	if(!IsPlayerConnected(giveplayerid) || !gPlayerLogged[giveplayerid])
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Player not connected or not logged");
		return 1;
	}
	if(strcmp(string, "red", false, 3) == 0)
	{
		gPlayerData[giveplayerid][pVipRedNeon] = count;
		SavePlayerData(giveplayerid, "VipRedNeon");
		format(string, sizeof(string), "player %s [%d] red neons count set to %d by %s [%d]",
			GetPlayerNameEx(giveplayerid), giveplayerid, count, GetPlayerNameEx(playerid), playerid);
		ABroadCast(COLOR_YELLOW, string, 5);
	}
	else if(strcmp(string, "blue", false, 4) == 0)
	{
		gPlayerData[giveplayerid][pVipBlueNeon] = count;
		SavePlayerData(giveplayerid, "VipBlueNeon");
		format(string, sizeof(string), "player %s [%d] blue neons count set to %d by %s [%d]",
			GetPlayerNameEx(giveplayerid), giveplayerid, count, GetPlayerNameEx(playerid), playerid);
		ABroadCast(COLOR_YELLOW, string, 5);
	}
	else if(strcmp(string, "green", false, 5) == 0)
	{
		gPlayerData[giveplayerid][pVipGreenNeon] = count;
		SavePlayerData(giveplayerid, "VipGreenNeon");
		format(string, sizeof(string), "player %s [%d] green neons count set to %d by %s [%d]",
			GetPlayerNameEx(giveplayerid), giveplayerid, count, GetPlayerNameEx(playerid), playerid);
		ABroadCast(COLOR_YELLOW, string, 5);
	}
	else if(strcmp(string, "yellow", false, 6) == 0)
	{
		gPlayerData[giveplayerid][pVipYellowNeon] = count;
		SavePlayerData(giveplayerid, "VipYellowNeon");
		format(string, sizeof(string), "player %s [%d] yellow neons count set to %d by %s [%d]",
			GetPlayerNameEx(giveplayerid), giveplayerid, count, GetPlayerNameEx(playerid), playerid);
		ABroadCast(COLOR_YELLOW, string, 5);
	}
	else if(strcmp(string, "pink", false, 4) == 0)
	{
		gPlayerData[giveplayerid][pVipPinkNeon] = count;
		SavePlayerData(giveplayerid, "VipPinkNeon");
		format(string, sizeof(string), "player %s [%d] pink neons count set to %d by %s [%d]",
			GetPlayerNameEx(giveplayerid), giveplayerid, count, GetPlayerNameEx(playerid), playerid);
		ABroadCast(COLOR_YELLOW, string, 5);
	}
	else if(strcmp(string, "white", false, 5) == 0)
	{
		gPlayerData[giveplayerid][pVipWhiteNeon] = count;
		SavePlayerData(giveplayerid, "VipWhiteNeon");
		format(string, sizeof(string), "player %s [%d] white neons count set to %d by %s [%d]",
			GetPlayerNameEx(giveplayerid), giveplayerid, count, GetPlayerNameEx(playerid), playerid);
		ABroadCast(COLOR_YELLOW, string, 5);
	}
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /giveneon [playerid] [color] [count]");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] color: red, blue, green, yellow, pink, white");
	return 1;
}	

dcmd_gotoffactory(playerid, params[])
{
	if(!gPlayerData[playerid][pAdmin])
		return 0;
	new fID;
	if(sscanf(params, "d", fID))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /gotofactory [faction id]");
		return 1;
	}
	if(fID >= sizeof(DynamicFactions) || fID < 0)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Niepoprawne ID");
		return 1;
	}
	if(!DynamicFactions[fID][WFactoryEnabled])
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ta frakcja nie posiada aktywnej fabryki");
		return 1;
	}
	SetPlayerToPos(playerid, DynamicFactions[fID][WFactoryCentrePosX], DynamicFactions[fID][WFactoryCentrePosY], DynamicFactions[fID][WFactoryCentrePosZ]);
	return 1;
}

dcmd_pa(playerid, params[])
{
	dcmd_paralizuj(playerid, params);
	return 1;
}

dcmd_paralizuj(playerid, params[])
{
	new string[128];
	if(gPlayerData[playerid][pFaction] == 255)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie nale¿ysz do ¿adnej frakcji !");
		return 1;
	}
	if(DynamicFactions[gPlayerData[playerid][pFaction]][fType] != 1)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Niew³aœciwa frakcja !");
		return 1;
	}
	if(!gPlayerData[playerid][pDuty])
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ na s³u¿bie !");
		return 1;
	}
	if(IsPlayerInAnyVehicle(playerid))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz u¿yæ paralizatora siedz¹c w samochodzie !");
		return 1;
	}
	new suspect;
	if(sscanf(params, "u", suspect))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /paralizuj [playerid]");
		return 1;
	}
	if(!IsPlayerConnected(suspect))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ta osoba nie jest w grze");
		return 1;
	}
	if(PlayerCuffed[suspect])
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ta osoba jest skuta ! Nie mo¿esz jej sparali¿owaæ");
		return 1;
	}
	if(GetDistanceBetweenPlayers(playerid, suspect) > 4)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ta osoba nie jest w zasiêgu !");
		return 1;
	}
	if(IsPlayerInAnyVehicle(suspect))
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Wydostañ podejrzanego z wozu !");
		return 1;
	}
	PlayerActionMessage(playerid, 15.0, "wyci¹ga z kabury paralizator X26C i u¿ywa go");
	format(string, sizeof(string), "[INFO:] Zosta³eœ sparali¿owany przez %s na 10 sekund.", GetPlayerNameEx(playerid));
	SendClientMessage(suspect, COLOR_RED, string);
	format(string, sizeof(string), "[INFO:] Sparali¿owa³eœ %s na 10 sekund.", GetPlayerNameEx(suspect));
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	TogglePlayerControllable(suspect, 0);
	PlayerTazed[suspect] = 1;
	defer UntazePlayer(suspect);
	return 1;
}

dcmd_vehcb(playerid, params[])
{
	new vehid, cb, string[128];
	if(sscanf(params, "dd", vehid, cb))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /vehcb [vehid] [cb type 0-2]");
		return 1;
	}
	if(vehid > sizeof(gVehData))
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Veh ID too high");
		return 1;
	}
	if(vehid < 0)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Bad veh ID");
		return 1;
	}
	gVehData[vehid][VCBRadio] = cb;
	SaveVehData(vehid, "CBRadio");
	if(cb)
		format(string, sizeof(string), "[INFO:] CB Radio type %d mounted in veh ID %d", cb, vehid);
	else
		format(string, sizeof(string), "[INFO:] CB Radio type %d unmounted from veh ID %d", cb, vehid);
	SendClientMessage(playerid, COLOR_GREEN, string);
	return 1;
}

dcmd_vehhook(playerid, params[])
{
	new vehid, hook, string[128];
	if(sscanf(params, "dd", vehid, hook))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /vehhook [vehid] [hook]");
		return 1;
	}
	if(vehid > sizeof(gVehData))
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Veh ID too high");
		return 1;
	}
	if(vehid < 0)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Bad veh ID");
		return 1;
	}
	gVehData[vehid-1][Hook] = hook;
	SaveVehData(vehid-1, "Hook");
	if(hook)
		format(string, sizeof(string), "[INFO:] Hook mounted in veh ID %d", vehid);
	else
		format(string, sizeof(string), "[INFO:] Hook unmounted from veh ID %d", vehid);
	SendClientMessage(playerid, COLOR_GREEN, string);
	return 1;
}

dcmd_vehalarm(playerid, params[])
{
	new vehid, alarm, string[128];
	if(sscanf(params, "dd", vehid, alarm))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /vehalarm [vehid] [alarm]");
		return 1;
	}
	if(vehid > sizeof(gVehData))
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Veh ID too high");
		return 1;
	}
	if(vehid < 0)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Bad veh ID");
		return 1;
	}
	gVehData[vehid][Alarm] = alarm;
	SaveVehData(vehid, "Alarm");
	if(alarm)
		format(string, sizeof(string), "[INFO:] Alarm mounted in veh ID %d", vehid);
	else
		format(string, sizeof(string), "[INFO:] Alarm unmounted from veh ID %d", vehid);
	SendClientMessage(playerid, COLOR_GREEN, string);
	return 1;
}

dcmd_osiagniecia(playerid, params[])
{
	#pragma unused params
	new string[1024];
	if(gPlayerData[playerid][pFirstCar])
		format(string, sizeof(string), "{4F5EFF}Zmotoryzowany - kup swój pierwszy pojazd\n");
	else
		format(string, sizeof(string), "{CCCCCC}Zmotoryzowany - kup swój pierwszy pojazd\n");
	if(gPlayerData[playerid][pFirstReanimation])
		strcat(string, "{4F5EFF}Bliskie spotkanie ze œmierci¹ - zostañ uratowany przez reanimacje\n");
	else
		strcat(string, "{CCCCCC}Bliskie spotkanie ze œmierci¹ - zostañ uratowany przez reanimacje\n");
	if(gPlayerData[playerid][pFirstPhone])
		strcat(string, "{4F5EFF}Rozmówca - kup telefon\n");
	else
		strcat(string, "{CCCCCC}Rozmówca - kup telefon\n");
	if(gPlayerData[playerid][pFirstLeader])
		strcat(string, "{4F5EFF}Przywódca - zostañ liderem frakcji\n");
	else
		strcat(string, "{CCCCCC}Przywódca - zostañ liderem frakcji\n");
	if(gPlayerData[playerid][pFirstJob])
		strcat(string, "{4F5EFF}Pracownik - zacznij swoj¹ pierwsz¹ prace\n");
	else
		strcat(string, "{CCCCCC}Pracownik - zacznij swoj¹ pierwsz¹ prace\n");
	if(gPlayerData[playerid][pFirstID])
		strcat(string, "{4F5EFF}Zidentyfikowany - wyrób swój dowód osobisty\n");
	else
		strcat(string, "{CCCCCC}Zidentyfikowany - wyrób swój dowód osobisty\n");
	if(gPlayerData[playerid][pFirstBuy])
		strcat(string, "{4F5EFF}Pierwsze zakupy - kup jak¹kolwiek rzecz w 24/7\n");
	else
		strcat(string, "{CCCCCC}Pierwsze zakupy - kup jak¹kolwiek rzecz w 24/7\n");
	if(gPlayerData[playerid][pFirstHouse])
		strcat(string, "{4F5EFF}W³asny k¹t - kup swój pierwszy dom\n");
	else
		strcat(string, "{CCCCCC}W³asny k¹t - kup swój pierwszy dom\n");
	if(gPlayerData[playerid][pFirstDescription])
		strcat(string, "{4F5EFF}Plakietkowiec - ustaw swój opis postaci\n");
	else
		strcat(string, "{CCCCCC}Plakietkowiec - ustaw swój opis postaci\n");
	if(gPlayerData[playerid][pFirstAction])
		strcat(string, "{4F5EFF}RPowiec - odegraj akcje RP\n");
	else
		strcat(string, "{CCCCCC}RPowiec - odegraj akcje RP\n");
	if(gPlayerData[playerid][pFirstBankUse])
		strcat(string, "{4F5EFF}Bankowiec - skorzystaj ze swojego konta w banku\n");
	else
		strcat(string, "{CCCCCC}Bankowiec - skorzystaj ze swojego konta w banku\n");
	if(gPlayerData[playerid][pFirstStats])
		strcat(string, "{4F5EFF}Statystyki - wyœwietl swoje statystyki\n");
	else
		strcat(string, "{CCCCCC}Statystyki - wyœwietl swoje statystyki\n");
	if(gPlayerData[playerid][pFirstJail])
		strcat(string, "{4F5EFF}Karany - poznaj uroki celi\n");
	else
		strcat(string, "{CCCCCC}Karany - poznaj uroki celi\n");
	if(gPlayerData[playerid][pFirstStudy])
		strcat(string, "{4F5EFF}Uczony - osi¹gnij pierwszy poziom w danej dziedzinie\n");
	else
		strcat(string, "{CCCCCC}Uczony - osi¹gnij pierwszy poziom w danej dziedzinie\n");
	if(gPlayerData[playerid][pPlayingHours] >= 50)
		strcat(string, "{4F5EFF}Bywalec - przegraj 50 godzin\n");
	else
		strcat(string, "{CCCCCC}Bywalec - przegraj 50 godzin\n");
	if(gPlayerData[playerid][pPlayingHours] >= 100)
		strcat(string, "{4F5EFF}Rozpoznawalny - przegraj 100 godzin\n");
	else
		strcat(string, "{CCCCCC}Rozpoznawalny - przegraj 100 godzin\n");
	if(gPlayerData[playerid][pPlayingHours] >= 500)
		strcat(string, "{4F5EFF}Sta³y gracz - przegraj 500 godzin\n");
	else
		strcat(string, "{CCCCCC}Sta³y gracz - przegraj 500 godzin\n");
	if(gPlayerData[playerid][pPlayingHours] >= 1000)
		strcat(string, "{4F5EFF}Weteran - przegraj 1000 godzin\n");
	else
		strcat(string, "{CCCCCC}Weteran - przegraj 1000 godzin\n");
	
	strcat(string, "{CCCCCC}\n\nDalsza czêœæ listy dostêpna pod /osiagniecia2");
	
	ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Osi¹gniêcia", string, "Zamknij", "");
	return 1;
}

dcmd_osiagniecia2(playerid, params[])
{
	#pragma unused params
	new string[1024];
	if(gPlayerData[playerid][pAchieveTickets] >= 50)
		format(string, sizeof(string), "{4F5EFF}Stra¿nik miejski - wlep 50 mandatów\n");
	else
		format(string, sizeof(string), "{CCCCCC}Stra¿nik miejski - wlep 50 mandatów\n");
	if(gPlayerData[playerid][pAchieveArrests])
		strcat(string, "{4F5EFF}Klawisz - aresztuj 10 osób\n");
	else
		strcat(string, "{CCCCCC}Klawisz - aresztuj 10 osób\n");
	if(gPlayerData[playerid][pAchieveDistance] >= 100000)
		strcat(string, "{4F5EFF}Miejski wyjadacz - przejedŸ dowolnym œrodkiem transportu 100 km\n");
	else
		strcat(string, "{CCCCCC}Miejski wyjadacz - przejedŸ dowolnym œrodkiem transportu 100 km\n");
	if(gPlayerData[playerid][pAchieveDistance] >= 1000000)
		strcat(string, "{4F5EFF}Podró¿nik - przejedŸ dowolnym œrodkiem transportu 1 000 km\n");
	else
		strcat(string, "{CCCCCC}Podró¿nik - przejedŸ dowolnym œrodkiem transportu 1 000 km\n");
	if(gPlayerData[playerid][pAchieveDistance] >= 100000000)
		strcat(string, "{4F5EFF}Odkrywca - przejedŸ dowolnym œrodkiem transportu 100 000 km\n");
	else
		strcat(string, "{CCCCCC}Odkrywca - przejedŸ dowolnym œrodkiem transportu 100 000 km\n");
	
	ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Osi¹gniêcia", string, "Zamknij", "");
	return 1;
}

dcmd_wyplata(playerid, params[])
{
	#pragma unused params
	new string[1024];
	if(gPlayerData[playerid][pPayDayMessage])
	{
		gPlayerData[playerid][pPayDayMessage] = 0;
		SavePlayerData(playerid, "PayDayMessage");
		TextDrawHideForPlayer(playerid, gPayDayText);
	}
	format(string, sizeof(string), "Wyci¹g z konta %s\n\nStan konta po wszystkich rozliczeniach: $%d\nStan konta przed rozliczeniem: $%d\nŒrodki które wp³ynê³y na konto: $%d\nOp³aty (podatki, etc.): $%d\n\n",
		GetPlayerNameEx(playerid), gPlayerData[playerid][pBankNew], gPlayerData[playerid][pBankOld], gPlayerData[playerid][pBankIncome], gPlayerData[playerid][pBankLoose]);
	
	if(gPlayerData[playerid][mCreditValue])
	{
		format(string, sizeof(string), "%sKwota kredytu: $%d\nSp³acono: $%d\nWysokoœæ raty: $%d\n\n",
			string,
			gPlayerData[playerid][mCreditValue],
			gPlayerData[playerid][mCreditPayed],
			gPlayerData[playerid][mCreditRepayment]);
	}
	
	if((gPlayerData[playerid][pBankNew] - gPlayerData[playerid][pBankOld]) > 0)
	{
		format(string, sizeof(string), "%sBilans: {2FED33}$%d", string, (gPlayerData[playerid][pBankNew] - gPlayerData[playerid][pBankOld]));
	}
	else if((gPlayerData[playerid][pBankNew] - gPlayerData[playerid][pBankOld]) < 0)
	{
		format(string, sizeof(string), "%sBilans: {E60000}$%d", string, (gPlayerData[playerid][pBankNew] - gPlayerData[playerid][pBankOld]));
	}
	else
	{
		format(string, sizeof(string), "%sBilans: $%d", string, (gPlayerData[playerid][pBankNew] - gPlayerData[playerid][pBankOld]));
	}
	
	ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "$$$ Bank San Andreas $$$", string, "Zamknij" ,"");
	
	return 1;
}

dcmd_abuildingiconshow(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] < 4)
		return 0;
	new buildingID, showIco;
	if(sscanf(params, "dd", buildingID, showIco))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /abuildingiconshow [building ID] [0/1]");
		return 1;
	}
	Building[buildingID][ShowIcon] = showIco;
	SaveBData(buildingID, "ShowIcon");
	return 1;
}

dcmd_dekonfiskata(playerid, params[])
{
	if(gPlayerData[playerid][pFaction] != FACTIONID_GOVERNMENT)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ urzêdnikiem");
		return 1;
	}
	
	new giveplayerid;
	if(sscanf(params, "d", giveplayerid))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /dekonfiskata [playerid]");
		return 1;
	}
	
	if(!gPlayerData[giveplayerid][pIsDeptor])
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ta osoba nie jest na liscie d³u¿ników !");
		return 1;
	}
	
	if(gPlayerData[giveplayerid][pBank] < -5000)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ta osoba nie mo¿e zostaæ usuniêta z listy d³u¿ników poniewa¿ bilans jej konta jest wci¹¿ ujemny");
		return 1;
	}
	
	gPlayerData[giveplayerid][pIsDeptor] = 0;
	SavePlayerData(giveplayerid, "IsDeptor");
	
	for(new i = 0; i < sizeof(Houses); i++)
	{
		if( strcmp(Houses[i][Owner], gPlayerData[giveplayerid][pName], false) == 0 && strlen(Houses[i][Owner]) > 0 )
		{
			Houses[i][HConfiscated] = 0;
			SaveHouseData(i, "Confiscated");
		}
	}
	
	for(new i = 0; i < sizeof(Businesses); i++)
	{
		if(strcmp(Businesses[i][Owner], gPlayerData[giveplayerid][pName], false) == 0 && strlen(Businesses[i][Owner]) > 0)
		{
			Businesses[i][BConfiscated] = 0;
			SaveBizData(i, "Confiscated");
		}
	}
	
	for(new i = 0; i < sizeof(gVehData); i++)
	{
		if(strcmp(gVehData[i][Owner], gPlayerData[giveplayerid][pName], false) == 0 && strlen(gVehData[i][Owner]) > 0)
		{
			new enginedyn,lights,alarm,doors,bonnet,boot,objective;
			GetVehicleParamsEx(i+1,enginedyn,lights,alarm,doors,bonnet,boot,objective);
			SetVehicleParamsEx(i+1,enginedyn,lights,alarm,0,bonnet,boot,objective);

			gVehData[i][Closed] = 0;
			SaveVehData(i, "Closed");
			gVehData[i][VConfiscated] = 0;
			SaveVehData(i, "Confiscated");
		}
	}
	
	SendClientMessage(playerid, COLOR_GREEN, "[INFO:] Osoba zosta³a usuniêta z rejestru d³u¿ników");
	
	return 1;
}

dcmd_sethealcost(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new healCost = 0, fID = 255;
	if(sscanf(params, "dd", fID, healCost))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /sethealcost [fID] [heal cost]");
		return 1;
	}
	DynamicFactions[fID][fHealCost] = healCost;
	SaveFData(fID, "HealCost");
	return 1;
}

dcmd_cenazaleczenie(playerid, params[])
{
	if(gPlayerData[playerid][pFaction] != FACTIONID_MEDICS)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Niew³aœciwa frakcja");
		return 1;
	}
	if(gPlayerData[playerid][pRank] != 1)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ liderem");
		return 1;
	}
	new healPrice = 0, string[128];
	if(sscanf(params, "d", healPrice))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /cenazaleczenie [cena]");
		format(string, sizeof(string), "[INFO:] Aktualna cena za leczenie: $%d, koszty leczenia: $%d",
			DynamicFactions[FACTIONID_MEDICS][fHealPrice], DynamicFactions[FACTIONID_MEDICS][fHealCost]+floatround(DynamicFactions[FACTIONID_MEDICS][fHealCost]*DynamicTaxes[VatTaxMin]));
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
		return 1;
	}
	DynamicFactions[FACTIONID_MEDICS][fHealPrice] = healPrice;
	SaveFData(FACTIONID_MEDICS, "HealPrice");
	return 1;
}

dcmd_setexaminecost(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new examineCost = 0, fID = 255;
	if(sscanf(params, "dd", fID, examineCost))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /setexaminecost [fID] [examine cost]");
		return 1;
	}
	DynamicFactions[fID][fExamineCost] = examineCost;
	SaveFData(fID, "ExamineCost");
	return 1;
}

dcmd_cenazabadanie(playerid, params[])
{
	if(gPlayerData[playerid][pFaction] != FACTIONID_MEDICS)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Niew³aœciwa frakcja");
		return 1;
	}
	if(gPlayerData[playerid][pRank] != 1)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ liderem");
		return 1;
	}
	new examinePrice = 0, string[128];
	if(sscanf(params, "d", examinePrice))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /cenazaleczenie [cena]");
		format(string, sizeof(string), "[INFO:] Aktualna cena za leczenie: $%d, koszty leczenia: $%d",
			DynamicFactions[FACTIONID_MEDICS][fExaminePrice], DynamicFactions[FACTIONID_MEDICS][fExamineCost]+floatround(DynamicFactions[FACTIONID_MEDICS][fExamineCost]*DynamicTaxes[VatTaxMin]));
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
		return 1;
	}
	DynamicFactions[FACTIONID_MEDICS][fExaminePrice] = examinePrice;
	SaveFData(FACTIONID_MEDICS, "ExaminePrice");
	return 1;
}

dcmd_zone1(playerid, params[])
{
	#pragma unused params
	GetPlayerPos(playerid, gZone1X, gZone1Y, gPlayerData[playerid][pCrashZ]);
	SendClientMessage(playerid, COLOR_WHITE, "[INFO:] Zapisano pozycje nr 1");
	return 1;
}

dcmd_zone2(playerid, params[])
{
	#pragma unused params
	GetPlayerPos(playerid, gZone2X, gZone2Y, gPlayerData[playerid][pCrashZ]);
	SendClientMessage(playerid, COLOR_WHITE, "[INFO:] Zapisano pozycje nr 2");
	return 1;
}	

dcmd_zone(playerid, params[])
{
	if(gZone1X == 0.0 || gZone1Y == 0.0)
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Pozycja nr 1 nie zosta³a ustalona");
		return 1;
	}
	
	if(gZone2X == 0.0 || gZone2Y == 0.0)
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Pozycja nr 2 nie zosta³a ustalona");
		return 1;
	}
	
	new color[16], string[128];
	if(sscanf(params, "s[16]", color))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /zone [color]");
		return 1;
	}
	
	if(strcmp(color, "black", false) == 0)
		GangZoneShowForAll(GangZoneCreate(gZone1X, gZone1Y, gZone2X, gZone2Y), COLOR_BLACK);
	else if(strcmp(color, "red", false) == 0)
		GangZoneShowForAll(GangZoneCreate(gZone1X, gZone1Y, gZone2X, gZone2Y), COLOR_RED);
	else if(strcmp(color, "white", false) == 0)
		GangZoneShowForAll(GangZoneCreate(gZone1X, gZone1Y, gZone2X, gZone2Y), COLOR_WHITE);
	else if(strcmp(color, "yellow", false) == 0)
		GangZoneShowForAll(GangZoneCreate(gZone1X, gZone1Y, gZone2X, gZone2Y), COLOR_YELLOW);
	
	new Float:x2, Float:y2;
	x2 = floatabs(gZone2X - gZone1X);
	y2 = floatabs(gZone2Y - gZone1Y);
	
	SendClientMessage(playerid, COLOR_GREEN, "[INFO:] Zone created");
	format(string, sizeof(string), "[INFO:] Zone size: x2*y2 = %.3fm square, x2 = %.2f, y2 = %.2f", x2*y2, x2, y2);
	SendClientMessage(playerid, COLOR_GREEN, string);
	format(string, sizeof(string), "[INFO:] gZone2X(%.2f) - gZone1X(%.2f)", gZone2X, gZone1X);
	SendClientMessage(playerid, COLOR_GREEN, string);
	format(string, sizeof(string), "[INFO:] gZone2Y(%.2f) - gZone1Y(%.2f)", gZone2Y, gZone1Y);
	SendClientMessage(playerid, COLOR_GREEN, string);
	
	gZone1X = 0.0;
	gZone1Y = 0.0;
	gZone2X = 0.0;
	gZone2Y = 0.0;
	
	return 1;
}	

dcmd_genbuid(playerid, params[])
{
	new bizid, string[128];
	if(sscanf(params, "d", bizid))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /genbuid [bizid]");
		return 1;
	}
	Businesses[bizid][BUID] = random(99999);
	SaveBizData(bizid, "UID");
	format(string, sizeof(string), "Business ID %d UID generated: %d", bizid, Businesses[bizid][BUID]);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	return 1;
}

dcmd_genhuid(playerid, params[])
{
	new hid, string[128];
	if(sscanf(params, "d", hid))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /genhuid [hid]");
		return 1;
	}
	Houses[hid][HUID] = random(99999);
	SaveHouseData(hid, "UID");
	format(string, sizeof(string), "House ID %d UID generated: %d", hid, Houses[hid][HUID]);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	return 1;
}

dcmd_ktowynajmuje(playerid, params[])
{
	#pragma unused params
	new string[128];
	for(new i = 0; i < sizeof(Houses); i++)
	{
		if(!PlayerToPoint(100.0, playerid, Houses[i][ExitX], Houses[i][ExitY], Houses[i][ExitZ]) || GetPlayerVirtualWorld(playerid) != i)
			continue;
		if(strcmp(gPlayerData[playerid][pName], Houses[i][Owner], false) != 0 && !AdminDuty[playerid])
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w³aœcicielem tego domu");
			return 1;
		}
		format(string, sizeof(string), "Osoba wynajmuj¹ca ten dom: %s", Houses[i][HRenter]);
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Dom", string, "Zamknij", "");
		return 1;
	}
	SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Musisz znajdowaæ siê wewnatrz domu aby sprawdziæ kto go wynajmuje");
	return 1;
}

dcmd_statystykibiznesu(playerid, params[])
{
	#pragma unused params
	new string[2048];
	for(new i = 0; i < sizeof(Businesses); i++)
	{
		if(!PlayerToPoint(100.0, playerid, Businesses[i][ExitX], Businesses[i][ExitY], Businesses[i][ExitZ]) || GetPlayerVirtualWorld(playerid) != i)
			continue;
		if(strcmp(gPlayerData[playerid][pName], Businesses[i][Owner], false) != 0 && !AdminDuty[playerid] && (!Businesses[i][BGov] || gPlayerData[playerid][pFaction] != FACTIONID_GOVERNMENT))
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w³aœcicielem tego biznesu !");
			return 1;
		}
		switch(Businesses[i][BizType])
		{
			case 1:
			{
				new todayincome = Businesses[i][Product1incomeToday]+Businesses[i][Product2incomeToday]+Businesses[i][Product3incomeToday]+Businesses[i][Product4incomeToday]+Businesses[i][Product5incomeToday];
				todayincome += Businesses[i][Product6incomeToday]+Businesses[i][Product7incomeToday]+Businesses[i][Product8incomeToday]+Businesses[i][Product9incomeToday]+Businesses[i][Product10incomeToday];
				todayincome += Businesses[i][mIncomeEntranceToday];
				format(string, sizeof(string),
					"{FFFFFF}Zysk ca³kowity: $%d\n\nZysk dzisiejszy: $%d\n\nZysk z wejœciówki dzisiejszy/ca³kowity: $%d/%d\n\nZysk dzisiejszy/ca³kowity z poszczególnych produktów:\n1. %s: $%d/$%d\n2. %s: $%d/$%d\n3. %s: $%d/$%d\n4. %s: $%d/$%d\n5. %s: $%d/$%d\n",
					Businesses[i][mIncomeTotal], todayincome, Businesses[i][mIncomeEntranceToday], Businesses[i][mIncomeEntranceTotal],
					ItemName(Businesses[i][Product1type], Businesses[i][Product1]), Businesses[i][Product1incomeToday], Businesses[i][Product1incomeTotal],
					ItemName(Businesses[i][Product2type], Businesses[i][Product2]), Businesses[i][Product2incomeToday], Businesses[i][Product2incomeTotal],
					ItemName(Businesses[i][Product3type], Businesses[i][Product3]), Businesses[i][Product3incomeToday], Businesses[i][Product3incomeTotal],
					ItemName(Businesses[i][Product4type], Businesses[i][Product4]), Businesses[i][Product4incomeToday], Businesses[i][Product4incomeTotal],
					ItemName(Businesses[i][Product5type], Businesses[i][Product5]), Businesses[i][Product5incomeToday], Businesses[i][Product5incomeTotal]);
				format(string, sizeof(string), "%s6. %s: $%d/$%d\n7. %s: $%d/$%d\n8. %s: $%d/$%d\n9. %s: $%d/$%d\n10. %s: $%d/$%d\n",
					string,
					ItemName(Businesses[i][Product6type], Businesses[i][Product6]), Businesses[i][Product6incomeToday], Businesses[i][Product6incomeTotal],
					ItemName(Businesses[i][Product7type], Businesses[i][Product7]), Businesses[i][Product7incomeToday], Businesses[i][Product7incomeTotal],
					ItemName(Businesses[i][Product8type], Businesses[i][Product8]), Businesses[i][Product8incomeToday], Businesses[i][Product8incomeTotal],
					ItemName(Businesses[i][Product9type], Businesses[i][Product9]), Businesses[i][Product9incomeToday], Businesses[i][Product9incomeTotal],
					ItemName(Businesses[i][Product10type], Businesses[i][Product10]), Businesses[i][Product10incomeToday], Businesses[i][Product10incomeTotal]);
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, Businesses[i][BusinessName], string, "Zamknij", "");
				return 1;
			}
			case 3:
			{
				new todayincome = Businesses[i][Product1incomeToday]+Businesses[i][Product2incomeToday]+Businesses[i][Product3incomeToday]+Businesses[i][Product4incomeToday]+Businesses[i][Product5incomeToday];
				todayincome += Businesses[i][Product6incomeToday]+Businesses[i][Product7incomeToday]+Businesses[i][Product8incomeToday]+Businesses[i][Product9incomeToday]+Businesses[i][Product10incomeToday];
				todayincome += Businesses[i][mIncomeEntranceToday];
				format(string, sizeof(string),
					"{FFFFFF}Zysk ca³kowity: $%d\n\nZysk dzisiejszy: $%d\n\nZysk z wejœciówki dzisiejszy/ca³kowity: $%d/%d\n\nZysk dzisiejszy/ca³kowity z poszczególnych produktów:\n1. %s: $%d/$%d\n2. %s: $%d/$%d\n3. %s: $%d/$%d\n4. %s: $%d/$%d\n5. %s: $%d/$%d\n",
					Businesses[i][mIncomeTotal], todayincome, Businesses[i][mIncomeEntranceToday], Businesses[i][mIncomeEntranceTotal],
					ItemName(Businesses[i][Product1type], Businesses[i][Product1]), Businesses[i][Product1incomeToday], Businesses[i][Product1incomeTotal],
					ItemName(Businesses[i][Product2type], Businesses[i][Product2]), Businesses[i][Product2incomeToday], Businesses[i][Product2incomeTotal],
					ItemName(Businesses[i][Product3type], Businesses[i][Product3]), Businesses[i][Product3incomeToday], Businesses[i][Product3incomeTotal],
					ItemName(Businesses[i][Product4type], Businesses[i][Product4]), Businesses[i][Product4incomeToday], Businesses[i][Product4incomeTotal],
					ItemName(Businesses[i][Product5type], Businesses[i][Product5]), Businesses[i][Product5incomeToday], Businesses[i][Product5incomeTotal]);
				format(string, sizeof(string), "%s6. %s: $%d/$%d\n7. %s: $%d/$%d\n8. %s: $%d/$%d\n9. %s: $%d/$%d\n10. %s: $%d/$%d\n",
					string,
					ItemName(Businesses[i][Product6type], Businesses[i][Product6]), Businesses[i][Product6incomeToday], Businesses[i][Product6incomeTotal],
					ItemName(Businesses[i][Product7type], Businesses[i][Product7]), Businesses[i][Product7incomeToday], Businesses[i][Product7incomeTotal],
					ItemName(Businesses[i][Product8type], Businesses[i][Product8]), Businesses[i][Product8incomeToday], Businesses[i][Product8incomeTotal],
					ItemName(Businesses[i][Product9type], Businesses[i][Product9]), Businesses[i][Product9incomeToday], Businesses[i][Product9incomeTotal],
					ItemName(Businesses[i][Product10type], Businesses[i][Product10]), Businesses[i][Product10incomeToday], Businesses[i][Product10incomeTotal]);
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, Businesses[i][BusinessName], string, "Zamknij", "");
				return 1;
			}
			case 2:
			{
				new todayincome = Businesses[i][mIncomeEntranceToday] + Businesses[i][mIncomePhoneToday];
				format(string, sizeof(string),
					"{FFFFFF}Zysk ca³kowity: $%d\n\nZysk dzisiejszy: $%d\n\nZysk z wejœciówki dzisiejszy/ca³kowity: $%d/%d\n\nZysk dzisiejszy/ca³kowity z po³¹czeñ: $%d/$%d\n",
					Businesses[i][mIncomeTotal], todayincome, Businesses[i][mIncomeEntranceToday], Businesses[i][mIncomeEntranceTotal],
					Businesses[i][mIncomePhoneToday], Businesses[i][mIncomePhoneTotal]);
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, Businesses[i][BusinessName], string, "Zamknij", "");
				return 1;
			}
			case 4:
			{
				new todayincome = Businesses[i][mIncomeEntranceToday] + Businesses[i][mIncomePhoneToday];
				format(string, sizeof(string),
					"{FFFFFF}Zysk ca³kowity: $%d\n\nZysk dzisiejszy: $%d\n\nZysk z wejœciówki dzisiejszy/ca³kowity: $%d/%d\n\n",
					Businesses[i][mIncomeTotal], todayincome, Businesses[i][mIncomeEntranceToday], Businesses[i][mIncomeEntranceTotal]);
				format(string, sizeof(string),
					"%sZysk dzisiejszy/ca³kowity z poszczególnych produktów:\n1. 9MM: $%d/%$%d\n2. 9MM z t³umikiem: $%d/%$%d\n4. Desert Eagle: $%d/%$%d\n5. Micro SMG: $%d/%$%d\n",
					string,
					Businesses[i][mW9MMIncomeToday], Businesses[i][mW9MMIncomeTotal], Businesses[i][mW9MMSilIncomeTotal], Businesses[i][mW9MMSilIncomeToday],
					Businesses[i][mWDesEagleIncomeToday], Businesses[i][mWDesEagleIncomeTotal], Businesses[i][mWMicroSMGIncomeToday], Businesses[i][mWMicroSMGIncomeTotal]);
				format(string, sizeof(string),
					"%s6. MP5: $%d/%$%d\n6. Tec9: $%d/%$%d\n7. Shotgun: $%d/%$%d\n8. AK-47: $%d/%$%d\n9. M4: $%d/%$%d\n10. Karabin: $%d/%$%d\n",
					string,
					Businesses[i][mWMP5IncomeToday], Businesses[i][mWMP5IncomeTotal], Businesses[i][mWTec9IncomeToday], Businesses[i][mWTec9IncomeTotal],
					Businesses[i][mWShotgunIncomeToday], Businesses[i][mWShotgunIncomeTotal], Businesses[i][mWAK47IncomeToday], Businesses[i][mWAK47IncomeTotal],
					Businesses[i][mWM4IncomeToday], Businesses[i][mWM4IncomeTotal], Businesses[i][mWRifleIncomeToday], Businesses[i][mWRifleIncomeTotal]);
				format(string, sizeof(string),
					"%s11. Karabin snajperski: $%d/$%d\n12. Pocisk 9MM: $%d/$%d\n13. Pocisk .50AE: $%d/$%d\n14. Œrut: $%d/$%d\n15. Pocisk 7.62MM: $%d/$%d\n16. Pocisk 12.7MM: $%d/$%d\n",
					Businesses[i][mWSRifleIncomeToday], Businesses[i][mWSRifleIncomeTotal], Businesses[i][mW9MMAmmoIncomeToday], Businesses[i][mW9MMAmmoIncomeTotal],
					Businesses[i][mW50AEAmmoIncomeToday], Businesses[i][mW50AEAmmoIncomeTotal], Businesses[i][mWBuckshotIncomeToday], Businesses[i][mWBuckshotIncomeTotal],
					Businesses[i][mW762MMAmmoIncomeToday], Businesses[i][mW762MMAmmoIncomeTotal], Businesses[i][mW127MMAmmoIncomeToday], Businesses[i][mW127MMAmmoIncomeTotal]);
					
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, Businesses[i][BusinessName], string, "Zamknij", "");
				return 1;
			}
			case 10:
			{
				new todayincome = Businesses[i][mIncomeEntranceToday] + Businesses[i][mIncomeVehicleToday];
				format(string, sizeof(string),
					"{FFFFFF}Zysk ca³kowity: $%d\n\nZysk dzisiejszy: $%d\n\nZysk z wejœciówki dzisiejszy/ca³kowity: $%d/%d\n\nZysk ze sprzeda¿y pojazdów dzisiejszy/ca³kowity: $%d/$%d",
					Businesses[i][mIncomeTotal], todayincome, Businesses[i][mIncomeEntranceToday], Businesses[i][mIncomeEntranceTotal],
					Businesses[i][mIncomeVehicleToday], Businesses[i][mIncomeVehicleTotal]);
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, Businesses[i][BusinessName], string, "Zamknij", "");
			}	
			case 11:
			{
				new todayincome = Businesses[i][mIncomeEntranceToday] + Businesses[i][mIncomeFuelPetrolToday] + Businesses[i][mIncomeFuelOilToday] + Businesses[i][mIncomeFuelGasToday];
				format(string, sizeof(string),
					"{FFFFFF}Zysk ca³kowity: $%d\n\nZysk dzisiejszy: $%d\n\nZysk z wejœciówki dzisiejszy/ca³kowity: $%d/%d\n\nZysk ze sprzeda¿y paliw dzisiejszy/ca³kowity:\nbenzyna: $%d/$%d\nropa: $%d/$%d\ngaz: $%d/$%d",
					Businesses[i][mIncomeTotal], todayincome, Businesses[i][mIncomeEntranceToday], Businesses[i][mIncomeEntranceTotal],
					Businesses[i][mIncomeFuelPetrolToday], Businesses[i][mIncomeFuelPetrolTotal],
					Businesses[i][mIncomeFuelOilToday], Businesses[i][mIncomeFuelOilTotal],
					Businesses[i][mIncomeFuelGasToday], Businesses[i][mIncomeFuelGasTotal]);
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, Businesses[i][BusinessName], string, "Zamknij", "");
			}
			default:
			{
				new todayincome = Businesses[i][mIncomeEntranceToday];
				format(string, sizeof(string),
					"{FFFFFF}Zysk ca³kowity: $%d\n\nZysk dzisiejszy: $%d\n\nZysk z wejœciówki dzisiejszy/ca³kowity: $%d/%d\n\n",
					Businesses[i][mIncomeTotal], todayincome, Businesses[i][mIncomeEntranceToday], Businesses[i][mIncomeEntranceTotal]);
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, Businesses[i][BusinessName], string, "Zamknij", "");
				return 1;
			}
		}
	}
	SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie znajdujesz siê w ¿adnym biznesie !");
	return 1;
}

dcmd_wnetrzedomu(playerid, params[])
{
	new hID = -1, hInt;
	
	if(sscanf(params, "d", hInt))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /wnetrzedomu [id wnetrza]");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Raz ustawionego wnêtrza nie mo¿na zmieniæ !");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /listawnetrz");
		return 1;
	}
	
	if(hInt > sizeof(HousesData) || hInt < 0)
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Poda³eœ nieprawid³owe ID wnêtrza !");
		return 1;
	}
	
	for(new i = 0; i < sizeof(Houses); i++)
	{
		if(!PlayerToPoint(2.0, playerid, Houses[i][EnterX], Houses[i][EnterY], Houses[i][EnterZ]))
		{
			continue;
		}
		
		hID = i;
	}
	
	if(hID == -1)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie stoisz przy wejœciu do ¿adnego domu");
		return 1;
	}
	
	// if(Houses[hID][HIntSet])
	// {
		// SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ten dom ma ju¿ ustawione wnêtrze i nie mo¿esz go przestawiæ");
		// return 1;
	// }
	
	Houses[hID][HIntSet] = 1;
	Houses[hID][ExitX] = HousesData[hInt][mExitX];
	Houses[hID][ExitY] = HousesData[hInt][mExitY];
	Houses[hID][ExitZ] = HousesData[hInt][mExitZ];
	Houses[hID][ExitAngle] = HousesData[hInt][mExitA];
	Houses[hID][ExitInterior] = HousesData[hInt][mExitInt];
	Houses[hID][HInterior]  = hInt;
	format(Houses[hID][Description], 128, "%s", HousesData[hInt][mDescription]);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, Houses[hID][Description]);
	
	SaveHouseData(hID, "ExitX");
	SaveHouseData(hID, "ExitY");
	SaveHouseData(hID, "ExitZ");
	SaveHouseData(hID, "ExitAngle");
	SaveHouseData(hID, "ExitInterior");
	SaveHouseData(hID, "Description");
	SaveHouseData(hID, "IntSet");
	SaveHouseData(hID, "Interior");
	
	return 1;
}

dcmd_ahouseintex(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new hID, hInt;
	if(sscanf(params, "dd", hID, hInt))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /ahouseintex [house id] [int id]");
		return 1;
	}
	Houses[hID][ExitX] = HousesData[hInt][mExitX];
	Houses[hID][ExitY] = HousesData[hInt][mExitY];
	Houses[hID][ExitZ] = HousesData[hInt][mExitZ];
	Houses[hID][ExitAngle] = HousesData[hInt][mExitA];
	Houses[hID][ExitInterior] = HousesData[hInt][mExitInt];
	Houses[hID][HInterior]  = hInt;
	format(Houses[hID][Description], 128, "%s", HousesData[hInt][mDescription]);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, Houses[hID][Description]);
	SaveHouseData(hID, "ExitX");
	SaveHouseData(hID, "ExitY");
	SaveHouseData(hID, "ExitZ");
	SaveHouseData(hID, "ExitAngle");
	SaveHouseData(hID, "ExitInterior");
	SaveHouseData(hID, "Description");
	SaveHouseData(hID, "Interior");
	return 1;
}

dcmd_listawnetrz(playerid, params[])
{
	#pragma unused params
	
	new string[2048], page, count = 0;
	
	if(sscanf(params, "d", page))
	{
		page = 1;
	}
	
	format(string, sizeof(string), "{FFFFFF}Aktualnie dostêpne wnêtrza:\n\n");
	
	while(count < sizeof(HousesData))
	{
		if(count > page*20-20 && count <= page*20)
		{
			format(string, sizeof(string), "%s"#COLOR_BEGIN"%d. "#COLOR_DEFAULT"%.64s", string, count, HousesData[count][mDescription]);
			
			if(++count < sizeof(HousesData))
			{
				format(string, sizeof(string), "%s     *     "#COLOR_BEGIN"%d. "#COLOR_DEFAULT"%.64s\n", string, count, HousesData[count][mDescription]);
			}
		}
		
		count++;
	}
	
	format(string, sizeof(string), "%s\n\n"#COLOR_BEGIN"Strona "#COLOR_DEFAULT"%d/%d", string, page, count/20);
	
	ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Lista wnêtrz", string, "Zamknij", "");
	
	return 1;
}

dcmd_zgloszenia(playerid, params[])
{
	if(gPlayerData[playerid][pFaction] == 255)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ta komenda jest przeznaczone dla s³u¿b porz¹dkowych");
		return 1;
	}

	if(gPlayerData[playerid][pFaction] != FACTIONID_MEDICS && DynamicFactions[gPlayerData[playerid][pFaction]][fType] != FACTIONT_POLICE)
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Ta komenda jest przeznaczona dla s³u¿b porz¹dkowych");
		return 1;
	}
	new slot[MAX_PLAYER_ITEM_SLOT], id, Float:x, Float:y, Float:z;
	if(sscanf(params, "d", id))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /zgloszenia [id 1-5]");
		return 1;
	}
	switch(id)
	{
		case 1:
		{
			if(DynamicFactions[gPlayerData[playerid][pFaction]][fNotification1])
			{
				GetPlayerPos(DynamicFactions[gPlayerData[playerid][pFaction]][fNotification1ID], x, y, z);
				PHaveItemEx(playerid, 3, 12, slot);
				for(new j = 0; j < MAX_PLAYER_ITEM_SLOT; j++)
				{
					if(slot[j] && SlotParam1(playerid, j+1))
					{
						if(gPlayerVars[DynamicFactions[gPlayerData[playerid][pFaction]][fNotification1ID]][mAtHouseID] != -1)
							SetPlayerCheckpoint(playerid, Houses[gPlayerVars[DynamicFactions[gPlayerData[playerid][pFaction]][fNotification1ID]][mAtHouseID]][EnterX], Houses[gPlayerVars[DynamicFactions[gPlayerData[playerid][pFaction]][fNotification1ID]][mAtHouseID]][EnterY], Houses[gPlayerVars[DynamicFactions[gPlayerData[playerid][pFaction]][fNotification1ID]][mAtHouseID]][EnterZ], 10.0);
						else if(gPlayerVars[DynamicFactions[gPlayerData[playerid][pFaction]][fNotification1ID]][mAtBuildingId] != -1)
							SetPlayerCheckpoint(playerid, Building[gPlayerVars[DynamicFactions[gPlayerData[playerid][pFaction]][fNotification1ID]][mAtBuildingId]][EnterX], Building[gPlayerVars[DynamicFactions[gPlayerData[playerid][pFaction]][fNotification1ID]][mAtBuildingId]][EnterY], Building[gPlayerVars[DynamicFactions[gPlayerData[playerid][pFaction]][fNotification1ID]][mAtBuildingId]][EnterZ], 10.0);
						else if(gPlayerVars[DynamicFactions[gPlayerData[playerid][pFaction]][fNotification1ID]][mAtBizID] != -1)
							SetPlayerCheckpoint(playerid, Businesses[gPlayerVars[DynamicFactions[gPlayerData[playerid][pFaction]][fNotification1ID]][mAtBizID]][EnterX], Businesses[gPlayerVars[DynamicFactions[gPlayerData[playerid][pFaction]][fNotification1ID]][mAtBizID]][EnterY], Businesses[gPlayerVars[DynamicFactions[gPlayerData[playerid][pFaction]][fNotification1ID]][mAtBizID]][EnterZ], 10.0);
						else
							SetPlayerCheckpoint(playerid, x, y, z, 10.0);
						defer ClearCheckpointsForPlayer(playerid);
						return 1;
					}
				}
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz GPSu");
				return 1;
			}
		}
		case 2:
		{
			if(DynamicFactions[gPlayerData[playerid][pFaction]][fNotification2])
			{
				GetPlayerPos(DynamicFactions[gPlayerData[playerid][pFaction]][fNotification2ID], x, y, z);
				PHaveItemEx(playerid, 3, 12, slot);
				for(new j = 0; j < MAX_PLAYER_ITEM_SLOT; j++)
				{
					if(slot[j] && SlotParam1(playerid, j+1))
					{
						if(gPlayerVars[DynamicFactions[gPlayerData[playerid][pFaction]][fNotification2ID]][mAtHouseID] != -1)
							SetPlayerCheckpoint(playerid, Houses[gPlayerVars[DynamicFactions[gPlayerData[playerid][pFaction]][fNotification2ID]][mAtHouseID]][EnterX], Houses[gPlayerVars[DynamicFactions[gPlayerData[playerid][pFaction]][fNotification2ID]][mAtHouseID]][EnterY], Houses[gPlayerVars[DynamicFactions[gPlayerData[playerid][pFaction]][fNotification2ID]][mAtHouseID]][EnterZ], 10.0);
						else if(gPlayerVars[DynamicFactions[gPlayerData[playerid][pFaction]][fNotification2ID]][mAtBuildingId] != -1)
							SetPlayerCheckpoint(playerid, Building[gPlayerVars[DynamicFactions[gPlayerData[playerid][pFaction]][fNotification2ID]][mAtBuildingId]][EnterX], Building[gPlayerVars[DynamicFactions[gPlayerData[playerid][pFaction]][fNotification2ID]][mAtBuildingId]][EnterY], Building[gPlayerVars[DynamicFactions[gPlayerData[playerid][pFaction]][fNotification2ID]][mAtBuildingId]][EnterZ], 10.0);
						else if(gPlayerVars[DynamicFactions[gPlayerData[playerid][pFaction]][fNotification2ID]][mAtBizID] != -1)
							SetPlayerCheckpoint(playerid, Businesses[gPlayerVars[DynamicFactions[gPlayerData[playerid][pFaction]][fNotification2ID]][mAtBizID]][EnterX], Businesses[gPlayerVars[DynamicFactions[gPlayerData[playerid][pFaction]][fNotification2ID]][mAtBizID]][EnterY], Businesses[gPlayerVars[DynamicFactions[gPlayerData[playerid][pFaction]][fNotification2ID]][mAtBizID]][EnterZ], 10.0);
						else
							SetPlayerCheckpoint(playerid, x, y, z, 10.0);
						defer ClearCheckpointsForPlayer(playerid);
						return 1;
					}
				}
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz GPSu");
				return 1;
			}
		}
		case 3:
		{
			if(DynamicFactions[gPlayerData[playerid][pFaction]][fNotification3])
			{
				GetPlayerPos(DynamicFactions[gPlayerData[playerid][pFaction]][fNotification3ID], x, y, z);
				PHaveItemEx(playerid, 3, 12, slot);
				for(new j = 0; j < MAX_PLAYER_ITEM_SLOT; j++)
				{
					if(slot[j] && SlotParam1(playerid, j+1))
					{
						if(gPlayerVars[DynamicFactions[gPlayerData[playerid][pFaction]][fNotification3ID]][mAtHouseID] != -1)
							SetPlayerCheckpoint(playerid, Houses[gPlayerVars[DynamicFactions[gPlayerData[playerid][pFaction]][fNotification3ID]][mAtHouseID]][EnterX], Houses[gPlayerVars[DynamicFactions[gPlayerData[playerid][pFaction]][fNotification3ID]][mAtHouseID]][EnterY], Houses[gPlayerVars[DynamicFactions[gPlayerData[playerid][pFaction]][fNotification3ID]][mAtHouseID]][EnterZ], 10.0);
						else if(gPlayerVars[DynamicFactions[gPlayerData[playerid][pFaction]][fNotification3ID]][mAtBuildingId] != -1)
							SetPlayerCheckpoint(playerid, Building[gPlayerVars[DynamicFactions[gPlayerData[playerid][pFaction]][fNotification3ID]][mAtBuildingId]][EnterX], Building[gPlayerVars[DynamicFactions[gPlayerData[playerid][pFaction]][fNotification3ID]][mAtBuildingId]][EnterY], Building[gPlayerVars[DynamicFactions[gPlayerData[playerid][pFaction]][fNotification3ID]][mAtBuildingId]][EnterZ], 10.0);
						else if(gPlayerVars[DynamicFactions[gPlayerData[playerid][pFaction]][fNotification3ID]][mAtBizID] != -1)
							SetPlayerCheckpoint(playerid, Businesses[gPlayerVars[DynamicFactions[gPlayerData[playerid][pFaction]][fNotification3ID]][mAtBizID]][EnterX], Businesses[gPlayerVars[DynamicFactions[gPlayerData[playerid][pFaction]][fNotification3ID]][mAtBizID]][EnterY], Businesses[gPlayerVars[DynamicFactions[gPlayerData[playerid][pFaction]][fNotification3ID]][mAtBizID]][EnterZ], 10.0);
						else
							SetPlayerCheckpoint(playerid, x, y, z, 10.0);
						defer ClearCheckpointsForPlayer(playerid);
						return 1;
					}
				}
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz GPSu");
				return 1;
			}
		}
		case 4:
		{
			if(DynamicFactions[gPlayerData[playerid][pFaction]][fNotification4])
			{
				GetPlayerPos(DynamicFactions[gPlayerData[playerid][pFaction]][fNotification4ID], x, y, z);
				PHaveItemEx(playerid, 3, 12, slot);
				for(new j = 0; j < MAX_PLAYER_ITEM_SLOT; j++)
				{
					if(slot[j] && SlotParam1(playerid, j+1))
					{
						if(gPlayerVars[DynamicFactions[gPlayerData[playerid][pFaction]][fNotification4ID]][mAtHouseID] != -1)
							SetPlayerCheckpoint(playerid, Houses[gPlayerVars[DynamicFactions[gPlayerData[playerid][pFaction]][fNotification4ID]][mAtHouseID]][EnterX], Houses[gPlayerVars[DynamicFactions[gPlayerData[playerid][pFaction]][fNotification4ID]][mAtHouseID]][EnterY], Houses[gPlayerVars[DynamicFactions[gPlayerData[playerid][pFaction]][fNotification4ID]][mAtHouseID]][EnterZ], 10.0);
						else if(gPlayerVars[DynamicFactions[gPlayerData[playerid][pFaction]][fNotification4ID]][mAtBuildingId] != -1)
							SetPlayerCheckpoint(playerid, Building[gPlayerVars[DynamicFactions[gPlayerData[playerid][pFaction]][fNotification4ID]][mAtBuildingId]][EnterX], Building[gPlayerVars[DynamicFactions[gPlayerData[playerid][pFaction]][fNotification4ID]][mAtBuildingId]][EnterY], Building[gPlayerVars[DynamicFactions[gPlayerData[playerid][pFaction]][fNotification4ID]][mAtBuildingId]][EnterZ], 10.0);
						else if(gPlayerVars[DynamicFactions[gPlayerData[playerid][pFaction]][fNotification4ID]][mAtBizID] != -1)
							SetPlayerCheckpoint(playerid, Businesses[gPlayerVars[DynamicFactions[gPlayerData[playerid][pFaction]][fNotification4ID]][mAtBizID]][EnterX], Businesses[gPlayerVars[DynamicFactions[gPlayerData[playerid][pFaction]][fNotification4ID]][mAtBizID]][EnterY], Businesses[gPlayerVars[DynamicFactions[gPlayerData[playerid][pFaction]][fNotification4ID]][mAtBizID]][EnterZ], 10.0);
						else
							SetPlayerCheckpoint(playerid, x, y, z, 10.0);
						defer ClearCheckpointsForPlayer(playerid);
						return 1;
					}
				}
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz GPSu");
				return 1;
			}
		}
		case 5:
		{
			if(DynamicFactions[gPlayerData[playerid][pFaction]][fNotification5])
			{
				GetPlayerPos(DynamicFactions[gPlayerData[playerid][pFaction]][fNotification5ID], x, y, z);
				PHaveItemEx(playerid, 3, 12, slot);
				for(new j = 0; j < MAX_PLAYER_ITEM_SLOT; j++)
				{
					if(slot[j] && SlotParam1(playerid, j+1))
					{
						if(gPlayerVars[DynamicFactions[gPlayerData[playerid][pFaction]][fNotification5ID]][mAtHouseID] != -1)
							SetPlayerCheckpoint(playerid, Houses[gPlayerVars[DynamicFactions[gPlayerData[playerid][pFaction]][fNotification5ID]][mAtHouseID]][EnterX], Houses[gPlayerVars[DynamicFactions[gPlayerData[playerid][pFaction]][fNotification5ID]][mAtHouseID]][EnterY], Houses[gPlayerVars[DynamicFactions[gPlayerData[playerid][pFaction]][fNotification5ID]][mAtHouseID]][EnterZ], 10.0);
						else if(gPlayerVars[DynamicFactions[gPlayerData[playerid][pFaction]][fNotification5ID]][mAtBuildingId] != -1)
							SetPlayerCheckpoint(playerid, Building[gPlayerVars[DynamicFactions[gPlayerData[playerid][pFaction]][fNotification5ID]][mAtBuildingId]][EnterX], Building[gPlayerVars[DynamicFactions[gPlayerData[playerid][pFaction]][fNotification5ID]][mAtBuildingId]][EnterY], Building[gPlayerVars[DynamicFactions[gPlayerData[playerid][pFaction]][fNotification5ID]][mAtBuildingId]][EnterZ], 10.0);
						else if(gPlayerVars[DynamicFactions[gPlayerData[playerid][pFaction]][fNotification5ID]][mAtBizID] != -1)
							SetPlayerCheckpoint(playerid, Businesses[gPlayerVars[DynamicFactions[gPlayerData[playerid][pFaction]][fNotification5ID]][mAtBizID]][EnterX], Businesses[gPlayerVars[DynamicFactions[gPlayerData[playerid][pFaction]][fNotification5ID]][mAtBizID]][EnterY], Businesses[gPlayerVars[DynamicFactions[gPlayerData[playerid][pFaction]][fNotification5ID]][mAtBizID]][EnterZ], 10.0);
						else
							SetPlayerCheckpoint(playerid, x, y, z, 10.0);
						defer ClearCheckpointsForPlayer(playerid);
						return 1;
					}
				}
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz GPSu");
				return 1;
			}
		}
	}
	SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] To zg³oszenie nie jest aktywne");
	return 1;
}

dcmd_sieckomorkowa(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pFaction2] == 255)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz firmy");
		return 1;
	}
	
	if(DynamicFactions[gPlayerData[playerid][pFaction2]][fType] != FACTIONT_COMPANY_PHONE)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz sieci komórkowej");
		return 1;
	}
	
	ShowPlayerPhoneCompany(playerid);
	
	return 1;
}

dcmd_globalsms(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new string[256], number;
	if(sscanf(params, "ds[256]", number, string))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /globalsms [sender number] [content]");
		return 1;
	}
	SendSmsToAll(playerid, number, string);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Rozpoczêto rozsy³anie wiadomoœci");
	return 1;
}

dcmd_quiz(playerid, params[])
{
	#pragma unused params
	gPlayerData[playerid][pQuiz] = 0;
	gPlayerVars[playerid][mQuizQuestionNo] = 0;
	gPlayerVars[playerid][mQuizWrongAnsweres] = 0;
	ShowPlayerQuiz(playerid);
}

dcmd_resetallvehicles(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] != 5 && !IsPlayerAdmin(playerid))
		return 0;
	for(new i = 0; i < sizeof(gVehData); i++)
	{
		defer ResetVehicleData(i, 1);
	}
	SendClientMessage(playerid, COLOR_GREEN, "[INFO:] All vehicles has been reseted");
	return 1;
}

dcmd_resetallhouses(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] != 5 && !IsPlayerAdmin(playerid))
		return 0;
	for(new i = 0; i < sizeof(Houses); i++)
	{
		ResetHouseData(i, 1);
	}
	SendClientMessage(playerid, COLOR_GREEN, "[INFO:] All houses has been reseted");
	return 1;
}

dcmd_resetallbusinesses(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] != 5 && !IsPlayerAdmin(playerid))
		return 0;
	for(new i = 0; i < sizeof(Businesses); i++)
	{
		ResetBizData(i);
	}
	SendClientMessage(playerid, COLOR_GREEN, "[INFO:] All businesses has been reseted");
	return 1;
}

dcmd_showterritories(playerid, params[])
{
	#pragma unused params
	if(!gPlayerData[playerid][pAdmin])
		return 0;
	for(new i = 0; i < sizeof(DynamicZones); i++)
	{
		GangZoneShowForPlayer(playerid, DynamicZones[i][mZoneId], HexToInt(DynamicFactions[DynamicZones[i][mFaction]][fColor]));
	}
	SendClientMessage(playerid, COLOR_GREEN, "[INFO:] Gang territoriees has been showed");
	return 1;
}

dcmd_hideterritories(playerid, params[])
{
	#pragma unused params
	if(!gPlayerData[playerid][pAdmin])
		return 0;
	for(new i = 0; i < sizeof(DynamicZones); i++)
	{
		GangZoneHideForPlayer(playerid, DynamicZones[i][mZoneId]);
	}
	SendClientMessage(playerid, COLOR_GREEN, "[INFO:] Gang territoriees has been hidden");
	return 1;
}

dcmd_terytoria(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pFaction] == 255)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie nale¿ysz do ¿adnej frakcji !");
		return 1;
	}
	new fId = gPlayerData[playerid][pFaction];
	if(DynamicFactions[fId][fType] != FACTIONT_GANG)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie nale¿ysz do gangu");
		return 1;
	}
	new count;
	for(new i = 0; i < sizeof(DynamicZones); i++)
	{
		if(DynamicZones[DynamicZones[i][mZoneId]][mFaction] == fId)
			count++;
	}
	new string[128];
	format(string, sizeof(string), "Twoja frakcja posiada %d terytoriów z %d\nTerytoria przynosz¹ $%d zysku co godzine\n\nWojny o terytoria\nWygrane: %d\nPrzegrane: %d",
		count, sizeof(DynamicZones), count*2, DynamicFactions[fId][fTerritoryWarWins], DynamicFactions[fId][fTerritoryWarLooses]);
	ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", string, "Zamknij", "");
	return 1;
}

dcmd_wjedzdonaczepy(playerid, params[])
{
	#pragma unused params
	new vehicleid = GetPlayerVehicleID(playerid);
	new transportVeh = GetClosestVehicle(playerid);
	if(GetPlayerVirtualWorld(playerid) != 0)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie znajdujesz siê wystarczaj¹co blisko naczepy");
		return 1;
	}
	if(!vehicleid)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Musisz byæ w pojeŸdzie aby wjechaæ nim do naczepy");
		return 1;
	}
	if(!gVehData[vehicleid-1][EngineOn] && !IsABike(vehicleid))
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Musisz mieæ uruchomiony silnik aby wjechaæ do naczepy");
		return 1;
	}
	new result = SetVehicleIntoTransport(vehicleid, transportVeh);
	if(result == 0)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] W tej naczepie nie ma ju¿ miejsca");
		return 1;
	}
	if(result == -1)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie znajdujesz siê wystarczaj¹co blisko naczepy");
		return 1;
	}
	SetPlayerInterior(playerid, gVehTransport[mPosInterior]);
	SetPlayerVirtualWorld(playerid, transportVeh);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Wjecha³eœ pojazdem do naczepy");
	return 1;
}

dcmd_wejdzdonaczepy(playerid, params[])
{
	#pragma unused params
	new transportVeh = GetClosestVehicle(playerid);
	if(GetPlayerVirtualWorld(playerid) != 0)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie znajdujesz siê wystarczaj¹co blisko naczepy");
		return 1;
	}
	if(transportVeh == INVALID_VEHICLE_ID)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie znajdujesz siê wystarczaj¹co blisko naczepy");
		return 1;
	}
	if(gVehData[transportVeh-1][mVehModel] != 435)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie znajdujesz siê wystarczaj¹co blisko naczepy");
		return 1;
	}
	SetPlayerInterior(playerid, gVehTransport[mPosInterior]);
	SetPlayerVirtualWorld(playerid, transportVeh);
	SetPlayerToPos(playerid, 348.82, 172.05, 1014.18);
	return 1;
}

dcmd_wyjdzznaczepy(playerid, params[])
{
	#pragma unused params
	new vehicleTransport = GetPlayerVirtualWorld(playerid);
	GetVehicleZAngle(vehicleTransport, gVehData[vehicleTransport-1][mVehA]);
	new Float:vehicleTransportAngle = gVehData[vehicleTransport-1][mVehA];
	if(vehicleTransportAngle-180 < 0)
		vehicleTransportAngle += 180;
	else
		vehicleTransportAngle -= 180;
	SetPlayerInterior(playerid, 0);
	SetPlayerVirtualWorld(playerid, 0);
	SetPlayerToPos(playerid, gVehData[vehicleTransport-1][mVehX]+floatsin(vehicleTransportAngle, degrees)*9.0, gVehData[vehicleTransport-1][mVehY]+ floatcos(vehicleTransportAngle, degrees)*9.0, gVehData[vehicleTransport-1][mVehZ]);	
	return 1;
}
	
dcmd_wyjedzznaczepy(playerid, params[])
{
	#pragma unused params
	new vehicleid = GetPlayerVehicleID(playerid);
	if(!vehicleid)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Musisz byæ w pojeŸdzie aby wjechaæ nim do naczepy");
		return 1;
	}
	if(!gVehData[vehicleid-1][EngineOn])
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Musisz mieæ uruchomiony silnik aby wjechaæ do naczepy");
		return 1;
	}
	SetVehicleOutOfTransport(vehicleid);
	SetPlayerInterior(playerid, 0);
	SetPlayerVirtualWorld(playerid, 0);
	return 1;
}

dcmd_okradnijzkasy(playerid, params[])
{
	new pId;
	if(sscanf(params, "u", pId))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /okradnijzkasy [id gracza]");
		return 1;
	}
	new police, string[128];
	foreach(Player, i)
	{
		if(gPlayerData[i][pFaction] == FACTIONID_POLICE)
			police++;
	}
	if(!police)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Brak obecnie policji, kradzie¿ nie jest mo¿liwa");
		return 1;
	}
	if(gPlayerData[playerid][pFaction] == 255)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie nale¿ysz do gangu");
		return 1;
	}
	if(DynamicFactions[gPlayerData[playerid][pFaction]][fType] != FACTIONT_GANG)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie nale¿ysz do gangu");
		return 1;
	}
	if(!IsPlayerInAlliedGangZone(playerid))
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie znajdujesz siê na swoim terytorium i nie mo¿esz tutaj kraœæ !");
		return 1;
	}
	if(CharInZoneMoneyStealTimeLeft(playerid) > 0)
	{
		format(string, sizeof(string), "Musisz odczekaæ jeszcze %d dni zanim bêdziesz móg³ znów kogoœ okraœæ na tym terytorium", CharInZoneStealTimeLeft(playerid));
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", string, "Zamknij", "");
		return 1;
	}
	else if(CharInZoneMoneyStealTimeLeft(playerid) == -1)
	{
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Nie znajdujesz siê na ¿adnym terytorium i nie mo¿esz nikogo tutaj okraœæ", "Zamknij", "");
		return 1;
	}
	if(!IsPlayerConnected(pId))
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ten gracz nie jest ON-LINE");
		return 1;
	}
	if(!gPlayerData[pId][pCharacterDying])
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Osoba musi byæ nieprzytomna aby j¹ okraœæ");
		return 1;
	}
	CharInZoneCashStealTimeLeftSave(playerid, CHAR_STEAL_COOLDOWN);
	GivePlayerCash(playerid, floatround(gPlayerData[pId][pCash]*0.20));
	format(string, sizeof(string), "[INFO:] Ukrad³eœ $%d", floatround(gPlayerData[pId][pCash]*0.20));
	GivePlayerCash(pId, -floatround(gPlayerData[pId][pCash]*0.20));
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	return 1;
}

dcmd_skonfiskuj(playerid, params[])
{
	new pId;
	if(sscanf(params, "u", pId))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /skonfiskuj [id gracza]");
		return 1;
	}
	
	if(gPlayerData[playerid][pFaction] == 255)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ policjantem");
		return 1;
	}
	
	if(DynamicFactions[gPlayerData[playerid][pFaction]][fType] != FACTIONT_POLICE)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ policjantem");
		return 1;
	}
	
	if(!IsPlayerConnected(pId))
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ten gracz nie jest ON-LINE");
		return 1;
	}
	
	if(!PlayerCuffed[pId])
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ta osoba musi byæ skuta");
		return 1;
	}
	
	gSendingPlayer[playerid] = pId;
	ShowPlayerDialog(playerid, DIALOG_STEAL_FROM_PLAYER, DIALOG_STYLE_LIST, "Lista itemów osoby skutej", ShowPItems(pId), "Zabierz", "Zamknij");
	return 1;
}

dcmd_okradnij(playerid, params[])
{
	new pId;
	if(sscanf(params, "u", pId))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /okradnij [id gracza]");
		return 1;
	}
	new police, string[128];
	foreach(Player, i)
	{
		if(gPlayerData[i][pFaction] == FACTIONID_POLICE)
			police++;
	}
	if(!police)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Brak obecnie policji, kradzie¿ nie jest mo¿liwa");
		return 1;
	}
	if(gPlayerData[playerid][pFaction] == 255)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie nale¿ysz do gangu");
		return 1;
	}
	if(DynamicFactions[gPlayerData[playerid][pFaction]][fType] != FACTIONT_GANG)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie nale¿ysz do gangu");
		return 1;
	}
	if(!IsPlayerInAlliedGangZone(playerid))
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie znajdujesz siê na swoim terytorium i nie mo¿esz tutaj kraœæ !");
		return 1;
	}
	if(CharInZoneStealTimeLeft(playerid) > 0)
	{
		format(string, sizeof(string), "Musisz odczekaæ jeszcze %d dni zanim bêdziesz móg³ znów kogoœ okraœæ na tym terytorium", CharInZoneStealTimeLeft(playerid));
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", string, "Zamknij", "");
		return 1;
	}
	else if(CharInZoneStealTimeLeft(playerid) == -1)
	{
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Nie znajdujesz siê na ¿adnym terytorium i nie mo¿esz nikogo tutaj okraœæ", "Zamknij", "");
		return 1;
	}
	if(!IsPlayerConnected(pId))
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ten gracz nie jest ON-LINE");
		return 1;
	}
	if(!gPlayerData[pId][pCharacterDying])
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Osoba musi byæ nieprzytomna aby j¹ okraœæ");
		return 1;
	}
	gSendingPlayer[playerid] = pId;
	ShowPlayerDialog(playerid, DIALOG_STEAL_FROM_PLAYER, DIALOG_STYLE_LIST, "Lista itemów osoby okradanej", ShowPItems(pId), "Zabierz", "Zamknij");
	return 1;
}

dcmd_przeszukaj(playerid, params[])
{
	new pId;
	if(sscanf(params, "u", pId))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /przeszukaj [id gracza]");
		return 1;
	}
	if(gPlayerData[playerid][pFaction] == 255)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ policjantem");
		return 1;
	}
	if(DynamicFactions[gPlayerData[playerid][pFaction]][fType] != FACTIONT_POLICE)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ policjantem");
		return 1;
	}
	if(!IsPlayerConnected(pId))
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ten gracz nie jest ON-LINE");
		return 1;
	}
	if(GetDistanceBetweenPlayers(playerid, pId) > 2.0)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ta osoba jest zbyt daleko od ciebie");
		return 1;
	}
	if(!PlayerCuffed[pId])
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Osoba musi byæ skuta aby j¹ przeszukaæ");
		return 1;
	}
	gSendingPlayer[playerid] = pId;
	ShowPlayerDialog(playerid, DIALOG_STEAL_FROM_PLAYER, DIALOG_STYLE_LIST, "Lista itemów osoby przeszukiwanej", ShowPItems(pId), "Zabierz", "Zamknij");
	return 1;
}

dcmd_wyrobdowodrejestracyjny(playerid, params[])
{
	if(gPlayerData[playerid][pFaction] != FACTIONID_GOVERNMENT)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ urzêdnikiem");
		return 1;
	}
	new givePlayerId, carSerial;
	if(sscanf(params, "ud", givePlayerId, carSerial))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /wyrobdowodrejestracyjny [id gracza] [nr rejestracyjny]");
		return 1;
	}
	if(!IsPlayerConnected(givePlayerId))
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ta osoba nie jest ON-LINE");
		return 1;
	}
	if(!PlayerFreeSlotCount(givePlayerId))
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ta osoba nie ma miejsca na dowód rejestracyjny");
		return 1;
	}
	new vehId = CarSerialToID(carSerial);
	if(vehId == -1)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie ma pojazdu o takiej rejestracji");
		return 1;
	}
	if(strcmp(gVehData[vehId][Owner], gPlayerData[givePlayerId], false) != 0)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ta osoba nie jest w³aœcicielem tego pojazdu");
		return 1;
	}
	InsertPlayerItemEx(givePlayerId, 3, 19, carSerial, gVehData[vehId][mVehVinNo], 0, 0, gPlayerData[givePlayerId][pName]);
	PlayerPlayerActionMessage(playerid, givePlayerId, 20.0, "wyrabia dowód i przekazuje go");
	return 1;
}

dcmd_pokazpunkteksportu(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pFaction] == 255)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ cz³onkiem gangu");
		return 1;
	}
	if(DynamicFactions[gPlayerData[playerid][pFaction]][fType] != FACTIONT_GANG)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ cz³onkiem gangu");
		return 1;
	}
	TogglePlayerDynamicCP(playerid, DynamicFactions[gPlayerData[playerid][pFaction]][mVehicleStealExportCpId], 1);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Punkt eksportu zosta³ pokazany na twojej mapie");
	return 1;
}

dcmd_ukryjpunkteksportu(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pFaction] == 255)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ cz³onkiem gangu");
		return 1;
	}
	if(DynamicFactions[gPlayerData[playerid][pFaction]][fType] != FACTIONT_GANG)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ cz³onkiem gangu");
		return 1;
	}
	TogglePlayerDynamicCP(playerid, DynamicFactions[gPlayerData[playerid][pFaction]][mVehicleStealExportCpId], 0);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Punkt eksportu zosta³ ukryty");
	return 1;
}

dcmd_eksportujpojazd(playerid, params[])
{
	#pragma unused params
	
	new string[512], bool:isPayed = false;
	
	if(gPlayerData[playerid][pFaction] == 255)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ cz³onkiem gangu");
		return 1;
	}
	
	if(DynamicFactions[gPlayerData[playerid][pFaction]][fType] != FACTIONT_GANG)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ cz³onkiem gangu");
		return 1;
	}
	
	if(!IsPlayerInDynamicCP(playerid, DynamicFactions[gPlayerData[playerid][pFaction]][mVehicleStealExportCpId]))
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w wyznaczonym punkcie eksportu");
		return 1;
	}
	
	new vehid = GetPlayerVehicleID(playerid);
	
	if(gVehData[vehid-1][mVehType] != 0)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz eksportowaæ tego pojazdu");
		return 1;
	}
	
	new Float:x, Float:y, Float:z;
	if(DynamicFactions[gPlayerData[playerid][pFaction]][mVehicleStealExportCpId] == gVehExport[mCpId1])
	{
		x = gVehExport[mPosX1];
		y = gVehExport[mPosY1];
		z = gVehExport[mPosZ1];
	}
	else if(DynamicFactions[gPlayerData[playerid][pFaction]][mVehicleStealExportCpId] == gVehExport[mCpId2])
	{
		x = gVehExport[mPosX2];
		y = gVehExport[mPosY2];
		z = gVehExport[mPosZ2];
	}
	else if(DynamicFactions[gPlayerData[playerid][pFaction]][mVehicleStealExportCpId] == gVehExport[mCpId3])
	{
		x = gVehExport[mPosX3];
		y = gVehExport[mPosY3];
		z = gVehExport[mPosZ3];
	}
	else if(DynamicFactions[gPlayerData[playerid][pFaction]][mVehicleStealExportCpId] == gVehExport[mCpId4])
	{
		x = gVehExport[mPosX4];
		y = gVehExport[mPosY4];
		z = gVehExport[mPosZ4];
	}
	else if(DynamicFactions[gPlayerData[playerid][pFaction]][mVehicleStealExportCpId] == gVehExport[mCpId5])
	{
		x = gVehExport[mPosX5];
		y = gVehExport[mPosY5];
		z = gVehExport[mPosZ5];
	}
	else if(DynamicFactions[gPlayerData[playerid][pFaction]][mVehicleStealExportCpId] == gVehExport[mCpId6])
	{
		x = gVehExport[mPosX6];
		y = gVehExport[mPosY6];
		z = gVehExport[mPosZ6];
	}
	else if(DynamicFactions[gPlayerData[playerid][pFaction]][mVehicleStealExportCpId] == gVehExport[mCpId7])
	{
		x = gVehExport[mPosX7];
		y = gVehExport[mPosY7];
		z = gVehExport[mPosZ7];
	}
	

	if(DynamicFactions[gPlayerData[playerid][pFaction]][mVehicleStealExportTimeLeft])
	{
		format(string, sizeof(string), "[INFO:] Musisz odczekaæ jeszcze %d godzin zanim wyeksportujesz pojazd", DynamicFactions[gPlayerData[playerid][pFaction]][mVehicleStealExportTimeLeft]);
		SendClientMessage(playerid, COLOR_ORANGE, string);
		return 1;
	}
	
	foreach(Player, i)
	{
		if(!gPlayerLogged[i] || playerid == i)
		{
			continue;
		}
		
		if(PlayerToPoint(80.0, i, x, y, z))
		{
			if(gPlayerData[playerid][pFaction] == 255)
			{
				continue;
			}	
				
			if(gPlayerData[playerid][pFaction] == FACTIONID_POLICE)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz wyeksportowac pojazdu poniewa¿ w pobli¿u znajduj¹ siê jednostki policji");
				return 1;
			}
		}
	}
	
	format(string, sizeof(string), "[EXPORT:] by %s, vehId in game %d, model %d, earn %d, faction %s",
		gPlayerData[playerid][pName], vehid, gVehData[vehid-1][mVehModel], floatround(cenyPojazdow[gVehData[vehid-1][mVehModel]-400]*0.1), DynamicFactions[gPlayerData[playerid][pFaction]][Name]);
	ExportVehLog(string);
	format(string, sizeof(string), "[EXPORT:] pos %.1f, %.1f, %.1f", x, y, z);
	ExportVehLog(string);
	ExportVehLog("--------------------------------------------------------------------------------------------------------------------------------");
	
	
	// Przekazanie pieniêdzy
	
	if(gPlayerData[playerid][pRank] == 1)
	{
		gPlayerData[playerid][pBank] += floatround(cenyPojazdow[gVehData[vehid-1][mVehModel]-400]*0.1);
		isPayed = true;
	}
	
	if(!isPayed)
	{
		foreach(Player, i)
		{
			if(!gPlayerLogged[i] || playerid == i)
			{
				if(gPlayerData[i][pRank] != 1)
				{
					continue;
				}
				
				if(gPlayerData[i][pFaction] == gPlayerData[playerid][pFaction])
				{
					gPlayerData[i][pBank] += floatround(cenyPojazdow[gVehData[vehid-1][mVehModel]-400]*0.1);
					isPayed = true;
				}
			}
		}
	}
	
	if(!isPayed)
	{
		format(string, sizeof(string), "SELECT `PlayerName` FROM `samp_users` WHERE `Faction` = '%d' AND `Rank` = '1'", gPlayerData[playerid][pFaction]);
		wp_mysql_query(string, CASH_FOR_EXPORT_VEH, vehid, db_con2);
	}
	
	format(string, sizeof(string), "[INFO:] Na konto lidera frakcji wp³ynê³o $%d za wyeksportowany pojazd", floatround(cenyPojazdow[gVehData[vehid-1][mVehModel]-400]*0.1));
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	
	ResetVehicleData(vehid, 1);
	
	return 1;
}

dcmd_naprawstacyjke(playerid, params[])
{
	#pragma unused params
	
	if(gPlayerData[playerid][pJob] != JOB_MECHANIC && !AdminDuty[playerid])
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ mechanikiem");
		return 1;
	}
	
	if(gPlayerData[playerid][pFaction2] == 255)
	{
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Musisz nale¿eæ do firmy aby naprawiaæ pojazdy.", "Zamknij", "");
		return 1;
	}
	
	if(!PHaveItem(playerid, 1, 174))
	{
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Inforamcja", "Potrzebujesz skrzynki z narzêdziami !", "Zamknij", "");
		return 1;
	}
	
	new inCompanyMech = 0;
	
	for(new i = 0; i < sizeof(Building); i++)
	{
		if(Building[i][FactionOwnerId] != gPlayerData[playerid][pFaction2])
		{
			continue;
		}
		
		if(!PlayerToPoint(15.0, playerid, Building[i][EnterX], Building[i][EnterY], Building[i][EnterZ]) && !PlayerToPoint(30.0, playerid, Building[i][ExitX], Building[i][ExitY], Building[i][ExitZ]))
		{
			continue;
		}
		
		inCompanyMech = 1;
	}
	
	if(!inCompanyMech && !AdminDuty[playerid])
	{
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Musisz znajdowaæ siê przy warsztacie twojej firmy.", "Wróæ", "");
		return 1;
	}
	
	new vehid = GetPlayerVehicleID(playerid);
	if(!vehid)
	{
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Musisz byæ w pojeŸdzie aby naprawiæ stacyjke.", "Wróæ", "");	
		return 1;
	}
	
	if(!gVehData[vehid-1][mVehIgnitionHacked] && !gVehData[vehid-1][mVehIgnitionDamaged])
	{
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Stacyjka nie jest uszkodzona.", "Wróæ", "");
		return 1;
	}
	
	defer VehicleIgnitionFix(playerid, vehid-1);
	ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Naprawiasz stacyjke... Czekaj 10 sekund.", "Wróæ", "");
	TogglePlayerControllable(playerid, 0);
	defer UnfreezePlayer[10000](playerid);
	
	return 1;
}

dcmd_zdemontuj(playerid, params[])
{
	if(!PlayerFreeSlotCount(playerid))
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie masz miejsca na czêœci !");
		return 1;
	}
	new vehid = GetPlayerVehicleID(playerid);
	if(!vehid)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Musisz byæ w pojeŸdzie aby zdemontowaæ czêœæ");
		return 1;
	}
	new element[64];
	if(sscanf(params, "s[64]", element))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /zdemontuj [czêœæ]");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] czêœæ: spojler, wydech, przedni_zderzak, tylny_zderzak");
		return 1;
	}
	if(strcmp(element, "spojler", true) == 0)
	{
		if(!gVehData[vehid-1][mVehSpoiler])
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ten pojazd nie posiada spojlera !");
			return 1;
		}
		ComponentToItem(playerid, gVehData[vehid-1][mVehSpoiler]);
		RemoveVehicleComponent(vehid, gVehData[vehid-1][mVehSpoiler]);
		gVehData[vehid-1][mVehSpoiler] = 0;
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Zdemontowa³eœ spojler");
		return 1;
	}
	if(strcmp(element, "wydech", true) == 0)
	{
		if(!gVehData[vehid-1][mVehExhaust])
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ten pojazd nie posiada stuningowanego wydechu !");
			return 1;
		}
		ComponentToItem(playerid, gVehData[vehid-1][mVehExhaust]);
		RemoveVehicleComponent(vehid, gVehData[vehid-1][mVehExhaust]);
		gVehData[vehid-1][mVehExhaust] = 0;
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Zdemontowa³eœ wydech");
		return 1;
	}
	if(strcmp(element, "przedni_zderzak", true) == 0)
	{
		if(!gVehData[vehid-1][mVehFrontBumper])
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ten pojazd nie posiada stuningowanego przedniego zderzaka !");
			return 1;
		}
		ComponentToItem(playerid, gVehData[vehid-1][mVehFrontBumper]);
		RemoveVehicleComponent(vehid, gVehData[vehid-1][mVehFrontBumper]);
		gVehData[vehid-1][mVehFrontBumper] = 0;
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Zdemontowa³eœ przedni zderzak");
		return 1;
	}
	if(strcmp(element, "tylny_zderzak", true) == 0)
	{
		if(!gVehData[vehid-1][mVehRearBumper])
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ten pojazd nie posiada stuningowanego tylnego zderzaka !");
			return 1;
		}
		ComponentToItem(playerid, gVehData[vehid-1][mVehRearBumper]);
		RemoveVehicleComponent(vehid, gVehData[vehid-1][mVehRearBumper]);
		gVehData[vehid-1][mVehRearBumper] = 0;
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Zdemontowa³eœ tylny zderzak");
		return 1;
	}
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /zdemontuj [czêœæ]");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] czêœæ: spojler, wydech, przedni_zderzak, tylny_zderzak");
	return 1;
}

dcmd_zamknij(playerid, params[])
{
	#pragma unused params
	new lPlayerState = GetPlayerState(playerid);
	if(lPlayerState == PLAYER_STATE_DRIVER)
	{
		new vehid = GetPlayerVehicleID(playerid);
		if(!gVehData[vehid-1][Closed])
		{
			if((gVehData[vehid-1][mVehFaction] == gPlayerData[playerid][pFaction] && gVehData[vehid-1][mVehFaction] != 255 && gPlayerData[playerid][pDuty]) || (PHaveItemParam5Ex(playerid, 3, 18, gPlayerData[playerid][pName]) >= 0))
			{
				if(!CheckRankPrivilidges(gPlayerData[playerid][pFaction], gPlayerData[playerid][pRank], "vehdrive") && gVehData[vehid-1][mVehFaction] == gPlayerData[playerid][pFaction] && gVehData[vehid-1][mVehFaction] != 255 && gPlayerData[playerid][pDuty])
				{
					SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie posiadasz uprawnieñ do zamykania pojazdów frakcyjnych !");
					return 1;
				}
				if(!IsABike(vehid) && !IsAMotorBike(vehid))
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Zamkn¹³eœ swój pojazd");
					PlayerActionMessage(playerid, 15.0, "wyjmuje kluczyki i zamyka pojazd");
					
					SetVehicleParamsEx(vehid, gVehData[vehid-1][EngineOn], gVehData[vehid-1][LightsOn], 0, 1, gVehData[vehid-1][BonnetUp], gVehData[vehid-1][BootUp], 0);
				}
				if(IsABike(vehid))
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2,"[INFO:] Zapi¹³eœ swój rower.");
					PlayerActionMessage(playerid, 15.0, "wyjmuje kluczyki i zapina zapiêcie");					
				}
				gVehData[vehid-1][Closed] = 1;
				SaveVehData(vehid-1, "Closed");
				return 1;
			}
		}
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Pojazd jest ju¿ zamkniêty");
		return 1;
	}
	else if(lPlayerState == PLAYER_STATE_ONFOOT)
	{
		new Float:dist = 5.0;
		new vehid = GetClosestVehicle(playerid, dist);
		
		if(gVehData[vehid-1][Closed])
		{
			if((gVehData[vehid-1][mVehFaction] == gPlayerData[playerid][pFaction] && gVehData[vehid-1][mVehFaction] != 255 && gPlayerData[playerid][pDuty]) || (PHaveItemParam5Ex(playerid, 3, 18, gPlayerData[playerid][pName]) >= 0 && gVehData[vehid-1][mVehType] == 1))
			{
				if(!CheckRankPrivilidges(gPlayerData[playerid][pFaction], gPlayerData[playerid][pRank], "vehdrive"))
				{
					SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie posiadasz uprawnieñ do zamykania pojazdów frakcyjnych !");
					return 1;
				}
				if(!IsABike(vehid) && !IsAMotorBike(vehid))
				{
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] Pojazd zosta³ otworzony.");
					PlayerActionMessage(playerid,15.0, "wyjmuje kluczyki i otwiera pojazd");
					
					SetVehicleParamsEx(vehid, gVehData[vehid-1][EngineOn], gVehData[vehid-1][LightsOn], 0, 0, gVehData[vehid-1][BonnetUp], gVehData[vehid-1][BootUp], 0);
				}
				if(IsABike(vehid))
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Zapiêcie rozpiête");
					PlayerActionMessage(playerid, 15.0, "wyjmuje kluczyki i rozpina zapiêcie");
				}
				gVehData[vehid-1][Closed] = 0;
				SaveVehData(vehid-1, "Closed");
				return 1;
			}
		}
	}
	return 1;
}

dcmd_debugtextdraw(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	TextDrawSetString(gPayDayText, "DEBUG1");
	TextDrawSetString(gPhoneCall, "DEBUG2");
	TextDrawSetString(gPhoneText, "DEBUG3");
	TextDrawSetString(GangWar[playerid], "DEBUG4");
	TextDrawSetString(GangWarTime[playerid], "DEBUG5");
	TextDrawSetString(Status[playerid], "DEBUG6");
	TextDrawSetString(gRaceStatus[0][mRaceInfo], "DEBUG7");
	TextDrawSetString(gPlayerVars[0][mRacePlace1Info], "DEBUG8");
	TextDrawUseBox(gPlayerVars[0][mRacePlace1Info], 1);
	TextDrawBoxColor(gPlayerVars[0][mRacePlace1Info], 0x000000FF);
	
	TextDrawShowForPlayer(playerid, gPayDayText);
	TextDrawShowForPlayer(playerid, gPhoneCall);
	TextDrawShowForPlayer(playerid, gPhoneText);
	TextDrawShowForPlayer(playerid, GangWar[playerid]);
	TextDrawShowForPlayer(playerid, GangWarTime[playerid]);
	TextDrawShowForPlayer(playerid, Status[playerid]);
	TextDrawShowForPlayer(playerid, gRaceStatus[0][mRaceInfo]);
	TextDrawShowForPlayer(playerid, gPlayerVars[0][mRacePlace1Info]);
	return 1;
}

dcmd_racestatus(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new raceId, status;
	if(sscanf(params, "dd", raceId, status))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /racestatus [race ID] [0/1]");
		return 1;
	}
	gRaceTrackEnabled[raceId] = status;
	SaveRaceData(raceId, "RaceTrackEnabled");
	return 1;
}

dcmd_raceinfopos(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new raceId;
	if(sscanf(params, "d", raceId))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /raceinfopos [race ID]");
		return 1;
	}
	GetPlayerPos(playerid, gRaceTrackInfoCpX[raceId], gRaceTrackInfoCpY[raceId], gRaceTrackInfoCpZ[raceId]);
	SaveRaceData(raceId, "RaceTrackInfoCpX");
	if(gRaceTrackEnabled[raceId])
	{
		if(gRaceTrackInfoPickupId[raceId])
			DestroyDynamicPickup(gRaceTrackInfoPickupId[raceId]);
		gRaceTrackInfoPickupId[raceId] = CreateDynamicPickup(1008, 23, gRaceTrackInfoCpX[raceId], gRaceTrackInfoCpY[raceId], gRaceTrackInfoCpZ[raceId]);
	}
	new string[128];
	format(string, sizeof(string), "[INFO:] Race info pos of track %d has been changed", raceId);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	return 1;
}

dcmd_racestartposcount(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new raceId, startPosCount;
	if(sscanf(params, "dd", raceId, startPosCount))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /racestartposcount [race ID] [start pos count 2-10]");
		return 1;
	}
	gRaceTrackStartPosCount[raceId] = startPosCount;
	SaveRaceData(raceId, "RaceTrackStartPosCount");
	new string[128];
	format(string, sizeof(string), "[INFO:] Race start pos count of track %d has been changed", raceId);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	return 1;
}

dcmd_racestartpos(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new raceId, startPosNo;
	if(sscanf(params, "dd", raceId, startPosNo))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /racestartpos [race ID] [start pos nr (1-10)]");
		return 1;
	}
	if(startPosNo == 1)
	{
		GetPlayerPos(playerid, gRaceTrackStart1CpX[raceId], gRaceTrackStart1CpY[raceId], gRaceTrackStart1CpZ[raceId]);
		SaveRaceData(raceId, "RaceTrackStart1Cp");
	}
	else if(startPosNo == 2)
	{
		GetPlayerPos(playerid, gRaceTrackStart2CpX[raceId], gRaceTrackStart2CpY[raceId], gRaceTrackStart2CpZ[raceId]);
		SaveRaceData(raceId, "RaceTrackStart2Cp");
	}
	else if(startPosNo == 3)
	{
		GetPlayerPos(playerid, gRaceTrackStart3CpX[raceId], gRaceTrackStart3CpY[raceId], gRaceTrackStart3CpZ[raceId]);
		SaveRaceData(raceId, "RaceTrackStart3Cp");
	}
	else if(startPosNo == 4)
	{
		GetPlayerPos(playerid, gRaceTrackStart4CpX[raceId], gRaceTrackStart4CpY[raceId], gRaceTrackStart4CpZ[raceId]);
		SaveRaceData(raceId, "RaceTrackStart4Cp");
	}
	else if(startPosNo == 5)
	{
		GetPlayerPos(playerid, gRaceTrackStart5CpX[raceId], gRaceTrackStart5CpY[raceId], gRaceTrackStart5CpZ[raceId]);
		SaveRaceData(raceId, "RaceTrackStart5Cp");
	}
	else if(startPosNo == 6)
	{
		GetPlayerPos(playerid, gRaceTrackStart6CpX[raceId], gRaceTrackStart6CpY[raceId], gRaceTrackStart6CpZ[raceId]);
		SaveRaceData(raceId, "RaceTrackStart6Cp");
	}
	else if(startPosNo == 7)
	{
		GetPlayerPos(playerid, gRaceTrackStart7CpX[raceId], gRaceTrackStart7CpY[raceId], gRaceTrackStart7CpZ[raceId]);
		SaveRaceData(raceId, "RaceTrackStart7Cp");
	}
	else if(startPosNo == 8)
	{
		GetPlayerPos(playerid, gRaceTrackStart8CpX[raceId], gRaceTrackStart8CpY[raceId], gRaceTrackStart8CpZ[raceId]);
		SaveRaceData(raceId, "RaceTrackStart8Cp");
	}
	else if(startPosNo == 9)
	{
		GetPlayerPos(playerid, gRaceTrackStart9CpX[raceId], gRaceTrackStart9CpY[raceId], gRaceTrackStart9CpZ[raceId]);
		SaveRaceData(raceId, "RaceTrackStart9Cp");
	}
	else if(startPosNo == 10)
	{
		GetPlayerPos(playerid, gRaceTrackStart10CpX[raceId], gRaceTrackStart10CpY[raceId], gRaceTrackStart10CpZ[raceId]);
		SaveRaceData(raceId, "RaceTrackStart10Cp");
	}
	new string[128];
	format(string, sizeof(string), "[INFO:] Starting pos %d of track %d has been changed", startPosNo, raceId);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	return 1;
}

dcmd_racecppos(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new raceId, cpType, cpId;
	if(sscanf(params, "ddd", raceId, cpType, cpId))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /racecppos [race ID] [cp type] [cp ID 0-99]");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] type: 0 - NONE, 1 - START, 2 - CP, 3 - SPLIT, 4 - FINISH");
		return 1;
	}
	GetPlayerPos(playerid, gRaceTrackCpX[raceId][cpId], gRaceTrackCpY[raceId][cpId], gRaceTrackCpZ[raceId][cpId]);
	gRaceTrackCpType[raceId][cpId] = cpType;
	SaveRaceData(raceId, "RaceTrackCp", cpId);
	new string[128];
	format(string, sizeof(string), "[INFO:] Race CP ID: %d pos and type of track %d has been changed", cpId, raceId);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	return 1;
}

dcmd_showracecp(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new raceId, cpId;
	if(sscanf(params, "dd", raceId, cpId))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /showracecp [raceId] [cpId]");
		return 1;
	}
	SetPlayerCheckpoint(playerid, gRaceTrackCpX[raceId][cpId], gRaceTrackCpY[raceId][cpId], gRaceTrackCpZ[raceId][cpId], 10.0); 
	defer ClearCheckpointsForPlayer(playerid);
	return 1;
}

dcmd_racecmds(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	SendClientMessage(playerid, COLOR_YELLOW, "/afillracestable - /racestartpos - /raceinfopos - /racestartposcount - /racecppos - /racestatus - /showracecp");
	return 1;
}

dcmd_menuwyscigu(playerid, params[])
{
	#pragma unused params
	new string[128], string2[128], Float:distance;
	for(new i = 0; i < MAX_RACES; i++)
	{
		if(PlayerToPoint(4.0, playerid, gRaceTrackInfoCpX[i], gRaceTrackInfoCpY[i], gRaceTrackInfoCpZ[i]))
		{
			format(string, sizeof(string), "1. Zorganizuj wyœcig\n2. Do³¹cz do istniej¹cego wyœcigu\n3. Zobacz statystyki tego wyœcigu");
			distance = CalculateTrackLenght(i);
			if(distance > 1000)
				format(string2, sizeof(string2), "Wyœcig - d³ugoœæ: %.1fkm", distance/1000);
			else
				format(string2, sizeof(string2), "Wyœcig - d³ugoœæ: %.1fkm", distance);
			ShowPlayerDialog(playerid, DIALOG_RACE, DIALOG_STYLE_LIST, string2, string, "Wybierz", "Zamknij");
			gPlayerVars[playerid][mSelectedRace] = i;
			return 1;
		}
	}
	SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w punkcie ¿adnego wyœcigu");
	return 1;
}

dcmd_przerwijwyscig(playerid, params[])
{
	#pragma unused params
	for(new i = 0; i < MAX_RACES; i++)
	{
		if(gRaceStatus[i][mRaceEntrant1Id] == playerid)
		{
			ResetRaceData(i);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Przerwa³eœ wyœcig");
			return 1;
		}
	}
	return 1;
}

dcmd_rozpocznijwyscig(playerid, params[])
{
	#pragma unused params
	for(new i = 0; i < MAX_RACES; i++)
	{
		if(gRaceStatus[i][mRaceEntrant1Id] == playerid)
		{
			gRaceStatus[i][mRaceTimeToStart] = 10;
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Rozpocz¹³eœ wyœcig");
			return 1;
		}
	}
	return 1;
}

dcmd_napisobj(playerid, params[])
{
	#pragma unused params
	ShowPlayerDialog(playerid, DIALOG_OBJECT_TXT, DIALOG_STYLE_INPUT, "TEST", "id obiektu", "Ok", "");
	return 1;
}

dcmd_objmaterial(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new objId, index, modelId, txdname[64], texturename[64];
	if(sscanf(params, "ddds[64]s[64]", objId, index, modelId, txdname, texturename))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /objmaterial [objId] [modelId] [txdname] [texturename]");
		return 1;
	}
	SetDynamicObjectMaterial(objId, index, modelId, txdname, texturename, 0);
	return 1;
}

dcmd_pilotpd(playerid, params[])
{
	#pragma unused params
	
	if(gPlayerData[playerid][pFaction] == 255)
	{
		SendClientMessage(playerid, COLOR_RED,"[INFO:] Nie jesteœ z policji !");
		return 1;
	}
	
	if(DynamicFactions[gPlayerData[playerid][pFaction]][fType] != FACTIONT_POLICE)
	{
		SendClientMessage(playerid, COLOR_RED,"[INFO:] Nie jesteœ z policji !");
		return 1;
	}

	if(!gPlayerData[playerid][pDuty])
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ na s³u¿bie !");
		return 1;
	}
	
	/* DM small parking */
	if(PlayerToPoint(15.0, playerid, 618.72, -599.32, 17.23))
	{
		if(gGateDmPd1aStatus)
		{
			gGateDmPd1aStatus = 0;
			MoveDynamicObject(gGateDmPd1a, 618.110168, -601.536499, 18.532262, 1.0, 0.0, 0.0, 180.0);
			PlayerActionMessage(playerid, 15.0, "u¿ywa pilota do zamkniêcia bramy");
		}
		else
		{
			gGateDmPd1aStatus = 1;
			MoveDynamicObject(gGateDmPd1a, 615.884826, -601.536499, 19.703029, 1.0, 0.0, 90.0, 180.0);			
		}
		if(gGateDmPd2aStatus)
		{
			gGateDmPd2aStatus = 0;
			MoveDynamicObject(gGateDmPd2a, 618.110168, -597.027770, 18.532262, 1.0, 0.0, 0.0, 180.0);
		}
		else
		{
			gGateDmPd2aStatus = 1;
			MoveDynamicObject(gGateDmPd2a, 615.884826, -597.027770, 19.703029, 1.0, 0.0, 90.0, 180.0);
		}
	}
	
	/* Big prison */
	else if(PlayerToPoint(15.0, playerid, -302.0, 1507.0, 75.0))
	{
		if(!gMainGateZomo[1])
		{
			gMainGateZomo[1] = 1;
			MoveDynamicObject(gGatePrison1a, -286.70373535156, 1507.1206054688, 74.4619140625, 1);
			MoveDynamicObject(gGatePrison1b, -308.84664916992, 1507.1439208984, 74.4619140625, 1);
			MoveDynamicObject(gGatePrison1c, -286.70965576172, 1507.1311035156, 77.586952209473, 1);
			MoveDynamicObject(gGatePrison1d, -308.87326049805, 1506.9456787109, 77.586952209473, 1);
		}
		else
		{
			gMainGateZomo[1] = 0;
			MoveDynamicObject(gGatePrison1a, -293.45800781, 1507.03222656, 74.46191406,1);
			MoveDynamicObject(gGatePrison1b, -302.32324219, 1506.92089844, 74.46191406,1);
			MoveDynamicObject(gGatePrison1c, -293.45800781, 1507.03222656, 77.58695221,1);
			MoveDynamicObject(gGatePrison1d, -302.32324219, 1506.92089844, 77.58695221,1);
		}
	}
	
	/* SF main pd gate */
	else if(PlayerToPoint(15.0, playerid, -1630.0, 679.0, 7.0))
	{
		if(!gMainGateZomo[0])
		{
			gMainGateZomo[0] = 1;
			MoveDynamicObject(gGateSfPd1a, -1644.5200, 688.500000, 7.468800, 2);
			MoveDynamicObject(gGateSfPd1b, -1644.5200, 688.500000, 7.468800, 2);
		}
		else
		{
			gMainGateZomo[0] = 0;
			MoveDynamicObject(gGateSfPd1a, -1635.600000, 688.500000, 7.468800, 2);
			MoveDynamicObject(gGateSfPd1b, -1627.790000, 688.500000, 7.468800, 2);
		}
	}
	
	/* SF west pd gate */
	else if(PlayerToPoint(15.0, playerid, -1700.0, 687.0, 24.0))
	{
		MoveDynamicObject(gGateSfPd3a, -1701.430664, 687.677, 24.70, 0.01, 0.0, 0.0, 90.0);
		defer PoliceGate2Close();
	}
	
	/* SF east pd gate */
	else if(PlayerToPoint(15.0, playerid, -1572.1822, 658.74, 6.74))
	{
		MoveDynamicObject(gGateSfPd2a, -1572.1822, 658.74, 6.80, 0.8, 0.0, 0.0, 90.0);
		defer PoliceGate1Close();
	}
	
	/* LS PD main garage */
	else if(PlayerToPoint(15.0, playerid, 1589.03, -1638.09, 14.14))
	{
		MoveDynamicObject(gGateLsPd1, 1597.06, -1638.03, 14.14, 0.9, 0.0, 0.0, 0.0);
		defer PoliceGateLs1Close();
	}
	
	PlayerActionMessage(playerid, 15.0, "u¿ywa pilota do bramy");
	
	return 1;
}

dcmd_zbierzplony(playerid, params[])
{
	#pragma unused params
	
	new lRandom, string[64], seed, plant;
	
	for(new i = 0; i < sizeof(gWeed); i++)
	{
		if(!PlayerToPoint(2.5, playerid, gWeed[i][mPosX], gWeed[i][mPosY], gWeed[i][mPosZ]) )
			continue;
		if(gWeed[i][mPhase] != 4)
			continue;
		DestroyDynamicObject(gWeed[i][mObjId]);
		gWeed[i][mPhase] = 0;
		SaveWeedData(i, "Phase");
		lRandom = random(100);
		if(gWeed[i][mType] == 0)
		{
			if(lRandom >= 0 && lRandom <= 26)
			{
				seed = 1;
				InsertPlayerItemEx(playerid, 1, 163, 0, 0, 0, 0, "Puste", 1);
			}
			else if(lRandom >= 27 && lRandom <= 51)
			{
				seed = 2;
				InsertPlayerItemEx(playerid, 1, 163, 0, 0, 0, 0, "Puste", 2);
			}
			lRandom = random(100);
			if(lRandom >= 50 && lRandom <= 74)
			{
				plant = 1;
				InsertPlayerItemEx(playerid, 1, 164, 0, 0, 0, 0, "Puste", 1);
			}
			else if(lRandom >= 75 && lRandom <= 100)
			{
				plant = 2;
				InsertPlayerItemEx(playerid, 1, 164, 0, 0, 0, 0, "Puste", 2);
			}
			format(string, sizeof(string), "Uda³o ci siê zebraæ %d nasion i %d liœci marihuany", seed, plant);
		}
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", string, "Zamknij", "");
		return 1;
	}
	SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie ma tutaj nic do zebrania");
	return 1;
}

dcmd_eventpos(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
		
	new eventid, string[256], Float:posX, Float:posY, Float:posZ, pickupModel;
	
	if(sscanf(params, "dd", eventid, pickupModel))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /eventpos [eventid] [model pickupa]");
		return 1;
	}
	
	GetPlayerPos(playerid, posX, posY, posZ);
	
	format(string, sizeof(string), "INSERT INTO `samp_pickup_events_locations` (`EventID` , `PosX` , `PosY` , `PosZ`, `PickupModel`) VALUES ('%d', '%f', '%f', '%f', '%d')",
		eventid, posX, posY, posZ, pickupModel);
	wp_mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
	
	return 1;
}

dcmd_getplayerweather(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new givePlayerId;
	if(sscanf(params, "d", givePlayerId))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /getplayerweatherall [playerid]");
		return 1;
	}
	new string[128];
	format(string, sizeof(string), "Player real weather ID = %d", GetRealWeatherEx());
	SendClientMessage(playerid, COLOR_ORANGE, string);
	return 1;
}

dcmd_uprawnieniarangi(playerid, params[])
{
	if(gPlayerData[playerid][pFaction] == 255)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie nale¿ysz do ¿adnej frakcji !");
		return 1;
	}
	if(gPlayerData[playerid][pRank] != 1)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ liderem frakcji !");
		return 1;
	}
	new rank, string[512];
	if(sscanf(params, "d", rank))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /uprawnieniarangi [ranga (2-10)]");
		return 1;
	}
	new fId = gPlayerData[playerid][pFaction];
	switch(rank)
	{
		case 2: 
		{
			if(DynamicFactions[fId][fRank2TillCheck])
				format(string, sizeof(string), "Sprawdzanie funduszy frakcji - TAK");
			else
				format(string, sizeof(string), "Sprawdzanie funduszy frakcji - NIE");
			if(DynamicFactions[fId][fRank2FactionStatus])
				format(string, sizeof(string), "%s\nSprawdzanie statusu frakcji - TAK", string);
			else	
				format(string, sizeof(string), "%s\nSprawdzanie statusu frakcji - NIE", string);
			if(DynamicFactions[fId][fRank2VehBuy])
				format(string, sizeof(string), "%s\nKupowanie pojazdów - TAK", string);
			else	
				format(string, sizeof(string), "%s\nKupowanie pojazdów - NIE", string);
			if(DynamicFactions[fId][fRank2VehSell])
				format(string, sizeof(string), "%s\nSprzedawanie pojazdów - TAK", string);
			else	
				format(string, sizeof(string), "%s\nSprzedawnie pojazdów - NIE", string);
			if(DynamicFactions[fId][fRank2VehSalvage])
				format(string, sizeof(string), "%s\nZ³omowanie pojazdów - TAK", string);
			else	
				format(string, sizeof(string), "%s\nZ³omowanie pojazdów - NIE", string);
			if(DynamicFactions[fId][fType] == FACTIONT_GANG)
			{
				if(DynamicFactions[fId][fRank2TerritoryWar])
					format(string, sizeof(string), "%s\nRozpoczynanie wojny o terytoria - TAK", string);
				else	
					format(string, sizeof(string), "%s\nRozpoczynanie wojny o terytoria - NIE", string);
				if(DynamicFactions[fId][fRank2BurnFactory])
					format(string, sizeof(string), "%s\nPodpalanie fabryk - TAK", string);
				else	
					format(string, sizeof(string), "%s\nPodpalanie fabryk - NIE", string);
			}
		}
		case 3: 
		{
			if(DynamicFactions[fId][fRank3TillCheck])
				format(string, sizeof(string), "Sprawdzanie funduszy frakcji - TAK");
			else
				format(string, sizeof(string), "Sprawdzanie funduszy frakcji - NIE");
			if(DynamicFactions[fId][fRank3FactionStatus])
				format(string, sizeof(string), "%s\nSprawdzanie statusu frakcji - TAK", string);
			else	
				format(string, sizeof(string), "%s\nSprawdzanie statusu frakcji - NIE", string);
			if(DynamicFactions[fId][fRank3VehBuy])
				format(string, sizeof(string), "%s\nKupowanie pojazdów - TAK", string);
			else	
				format(string, sizeof(string), "%s\nKupowanie pojazdów - NIE", string);
			if(DynamicFactions[fId][fRank3VehSell])
				format(string, sizeof(string), "%s\nSprzedawanie pojazdów - TAK", string);
			else	
				format(string, sizeof(string), "%s\nSprzedawanie pojazdów - NIE", string);
			if(DynamicFactions[fId][fRank3VehSalvage])
				format(string, sizeof(string), "%s\nZ³omowanie pojazdów - TAK", string);
			else	
				format(string, sizeof(string), "%s\nZ³omowanie pojazdów - NIE", string);
			if(DynamicFactions[fId][fRank3VehDrive])
				format(string, sizeof(string), "%s\nProwadzenie pojazdów (uruchamianie, zamykanie) - TAK", string);
			else	
				format(string, sizeof(string), "%s\nProwadzenie pojazdów (uruchamianie, zamykanie) - NIE", string);
			if(DynamicFactions[fId][fType] == FACTIONT_GANG)
			{
				if(DynamicFactions[fId][fRank3TerritoryWar])
					format(string, sizeof(string), "%s\nRozpoczynanie wojny o terytoria - TAK", string);
				else	
					format(string, sizeof(string), "%s\nRozpoczynanie wojny o terytoria - NIE", string);
				if(DynamicFactions[fId][fRank3BurnFactory])
					format(string, sizeof(string), "%s\nPodpalanie fabryk - TAK", string);
				else	
					format(string, sizeof(string), "%s\nPodpalanie fabryk - NIE", string);
			}
		}
		case 4: 
		{
			if(DynamicFactions[fId][fRank4TillCheck])
				format(string, sizeof(string), "Sprawdzanie funduszy frakcji - TAK");
			else
				format(string, sizeof(string), "Sprawdzanie funduszy frakcji - NIE");
			if(DynamicFactions[fId][fRank4FactionStatus])
				format(string, sizeof(string), "%s\nSprawdzanie statusu frakcji - TAK", string);
			else	
				format(string, sizeof(string), "%s\nSprawdzanie statusu frakcji - NIE", string);
			if(DynamicFactions[fId][fRank4VehBuy])
				format(string, sizeof(string), "%s\nKupowanie pojazdów - TAK", string);
			else	
				format(string, sizeof(string), "%s\nKupowanie pojazdów - NIE", string);
			if(DynamicFactions[fId][fRank4VehSell])
				format(string, sizeof(string), "%s\nSprzedawanie pojazdów - TAK", string);
			else	
				format(string, sizeof(string), "%s\nSprzedawanie pojazdów - NIE", string);
			if(DynamicFactions[fId][fRank4VehSalvage])
				format(string, sizeof(string), "%s\nZ³omowanie pojazdów - TAK", string);
			else	
				format(string, sizeof(string), "%s\nZ³omowanie pojazdów - NIE", string);
			if(DynamicFactions[fId][fRank4VehDrive])
				format(string, sizeof(string), "%s\nProwadzenie pojazdów (uruchamianie, zamykanie) - TAK", string);
			else	
				format(string, sizeof(string), "%s\nProwadzenie pojazdów (uruchamianie, zamykanie) - NIE", string);
			if(DynamicFactions[fId][fType] == FACTIONT_GANG)
			{
				if(DynamicFactions[fId][fRank4TerritoryWar])
					format(string, sizeof(string), "%s\nRozpoczynanie wojny o terytoria - TAK", string);
				else	
					format(string, sizeof(string), "%s\nRozpoczynanie wojny o terytoria - NIE", string);
				if(DynamicFactions[fId][fRank4BurnFactory])
					format(string, sizeof(string), "%s\nPodpalanie fabryk - TAK", string);
				else	
					format(string, sizeof(string), "%s\nPodpalanie fabryk - NIE", string);
			}
		}
		case 5: 
		{
			if(DynamicFactions[fId][fRank5TillCheck])
				format(string, sizeof(string), "Sprawdzanie funduszy frakcji - TAK");
			else
				format(string, sizeof(string), "Sprawdzanie funduszy frakcji - NIE");
			if(DynamicFactions[fId][fRank5FactionStatus])
				format(string, sizeof(string), "%s\nSprawdzanie statusu frakcji - TAK", string);
			else	
				format(string, sizeof(string), "%s\nSprawdzanie statusu frakcji - NIE", string);
			if(DynamicFactions[fId][fRank5VehBuy])
				format(string, sizeof(string), "%s\nKupowanie pojazdów - TAK", string);
			else	
				format(string, sizeof(string), "%s\nKupowanie pojazdów - NIE", string);
			if(DynamicFactions[fId][fRank5VehSell])
				format(string, sizeof(string), "%s\nSprzedawanie pojazdów - TAK", string);
			else	
				format(string, sizeof(string), "%s\nSprzedawanie pojazdów - NIE", string);
			if(DynamicFactions[fId][fRank5VehSalvage])
				format(string, sizeof(string), "%s\nZ³omowanie pojazdów - TAK", string);
			else	
				format(string, sizeof(string), "%s\nZ³omowanie pojazdów - NIE", string);
			if(DynamicFactions[fId][fRank5VehDrive])
				format(string, sizeof(string), "%s\nProwadzenie pojazdów (uruchamianie, zamykanie) - TAK", string);
			else	
				format(string, sizeof(string), "%s\nProwadzenie pojazdów (uruchamianie, zamykanie) - NIE", string);
			if(DynamicFactions[fId][fType] == FACTIONT_GANG)
			{
				if(DynamicFactions[fId][fRank5TerritoryWar])
					format(string, sizeof(string), "%s\nRozpoczynanie wojny o terytoria - TAK", string);
				else	
					format(string, sizeof(string), "%s\nRozpoczynanie wojny o terytoria - NIE", string);
				if(DynamicFactions[fId][fRank5BurnFactory])
					format(string, sizeof(string), "%s\nPodpalanie fabryk - TAK", string);
				else	
					format(string, sizeof(string), "%s\nPodpalanie fabryk - NIE", string);
			}
		}
		case 6: 
		{
			if(DynamicFactions[fId][fRank6TillCheck])
				format(string, sizeof(string), "Sprawdzanie funduszy frakcji - TAK");
			else
				format(string, sizeof(string), "Sprawdzanie funduszy frakcji - NIE");
			if(DynamicFactions[fId][fRank6FactionStatus])
				format(string, sizeof(string), "%s\nSprawdzanie statusu frakcji - TAK", string);
			else	
				format(string, sizeof(string), "%s\nSprawdzanie statusu frakcji - NIE", string);
			if(DynamicFactions[fId][fRank6VehBuy])
				format(string, sizeof(string), "%s\nKupowanie pojazdów - TAK", string);
			else	
				format(string, sizeof(string), "%s\nKupowanie pojazdów - NIE", string);
			if(DynamicFactions[fId][fRank6VehSell])
				format(string, sizeof(string), "%s\nSprzedawanie pojazdów - TAK", string);
			else	
				format(string, sizeof(string), "%s\nSprzedawanie pojazdów - NIE", string);
			if(DynamicFactions[fId][fRank6VehSalvage])
				format(string, sizeof(string), "%s\nZ³omowanie pojazdów - TAK", string);
			else	
				format(string, sizeof(string), "%s\nZ³omowanie pojazdów - NIE", string);
			if(DynamicFactions[fId][fRank6VehDrive])
				format(string, sizeof(string), "%s\nProwadzenie pojazdów (uruchamianie, zamykanie) - TAK", string);
			else	
				format(string, sizeof(string), "%s\nProwadzenie pojazdów (uruchamianie, zamykanie) - NIE", string);
			if(DynamicFactions[fId][fType] == FACTIONT_GANG)
			{
				if(DynamicFactions[fId][fRank6TerritoryWar])
					format(string, sizeof(string), "%s\nRozpoczynanie wojny o terytoria - TAK", string);
				else	
					format(string, sizeof(string), "%s\nRozpoczynanie wojny o terytoria - NIE", string);
				if(DynamicFactions[fId][fRank6BurnFactory])
					format(string, sizeof(string), "%s\nPodpalanie fabryk - TAK", string);
				else	
					format(string, sizeof(string), "%s\nPodpalanie fabryk - NIE", string);
			}
		}
		case 7: 
		{
			if(DynamicFactions[fId][fRank7TillCheck])
				format(string, sizeof(string), "Sprawdzanie funduszy frakcji - TAK");
			else
				format(string, sizeof(string), "Sprawdzanie funduszy frakcji - NIE");
			if(DynamicFactions[fId][fRank7FactionStatus])
				format(string, sizeof(string), "%s\nSprawdzanie statusu frakcji - TAK", string);
			else	
				format(string, sizeof(string), "%s\nSprawdzanie statusu frakcji - NIE", string);
			if(DynamicFactions[fId][fRank7VehBuy])
				format(string, sizeof(string), "%s\nKupowanie pojazdów - TAK", string);
			else	
				format(string, sizeof(string), "%s\nKupowanie pojazdów - NIE", string);
			if(DynamicFactions[fId][fRank7VehSell])
				format(string, sizeof(string), "%s\nSprzedawanie pojazdów - TAK", string);
			else	
				format(string, sizeof(string), "%s\nSprzedawanie pojazdów - NIE", string);
			if(DynamicFactions[fId][fRank7VehSalvage])
				format(string, sizeof(string), "%s\nZ³omowanie pojazdów - TAK", string);
			else	
				format(string, sizeof(string), "%s\nZ³omowanie pojazdów - NIE", string);
			if(DynamicFactions[fId][fRank7VehDrive])
				format(string, sizeof(string), "%s\nProwadzenie pojazdów (uruchamianie, zamykanie) - TAK", string);
			else	
				format(string, sizeof(string), "%s\nProwadzenie pojazdów (uruchamianie, zamykanie) - NIE", string);
			if(DynamicFactions[fId][fType] == FACTIONT_GANG)
			{
				if(DynamicFactions[fId][fRank7TerritoryWar])
					format(string, sizeof(string), "%s\nRozpoczynanie wojny o terytoria - TAK", string);
				else	
					format(string, sizeof(string), "%s\nRozpoczynanie wojny o terytoria - NIE", string);
				if(DynamicFactions[fId][fRank7BurnFactory])
					format(string, sizeof(string), "%s\nPodpalanie fabryk - TAK", string);
				else	
					format(string, sizeof(string), "%s\nPodpalanie fabryk - NIE", string);
			}
		}
		case 8: 
		{
			if(DynamicFactions[fId][fRank8TillCheck])
				format(string, sizeof(string), "Sprawdzanie funduszy frakcji - TAK");
			else
				format(string, sizeof(string), "Sprawdzanie funduszy frakcji - NIE");
			if(DynamicFactions[fId][fRank8FactionStatus])
				format(string, sizeof(string), "%s\nSprawdzanie statusu frakcji - TAK", string);
			else	
				format(string, sizeof(string), "%s\nSprawdzanie statusu frakcji - NIE", string);
			if(DynamicFactions[fId][fRank8VehBuy])
				format(string, sizeof(string), "%s\nKupowanie pojazdów - TAK", string);
			else	
				format(string, sizeof(string), "%s\nKupowanie pojazdów - NIE", string);
			if(DynamicFactions[fId][fRank8VehSell])
				format(string, sizeof(string), "%s\nSprzedawanie pojazdów - TAK", string);
			else	
				format(string, sizeof(string), "%s\nSprzedawanie pojazdów - NIE", string);
			if(DynamicFactions[fId][fRank8VehSalvage])
				format(string, sizeof(string), "%s\nZ³omowanie pojazdów - TAK", string);
			else	
				format(string, sizeof(string), "%s\nZ³omowanie pojazdów - NIE", string);
			if(DynamicFactions[fId][fRank8VehDrive])
				format(string, sizeof(string), "%s\nProwadzenie pojazdów (uruchamianie, zamykanie) - TAK", string);
			else	
				format(string, sizeof(string), "%s\nProwadzenie pojazdów (uruchamianie, zamykanie) - NIE", string);
			if(DynamicFactions[fId][fType] == FACTIONT_GANG)
			{
				if(DynamicFactions[fId][fRank8TerritoryWar])
					format(string, sizeof(string), "%s\nRozpoczynanie wojny o terytoria - TAK", string);
				else	
					format(string, sizeof(string), "%s\nRozpoczynanie wojny o terytoria - NIE", string);
				if(DynamicFactions[fId][fRank8BurnFactory])
					format(string, sizeof(string), "%s\nPodpalanie fabryk - TAK", string);
				else	
					format(string, sizeof(string), "%s\nPodpalanie fabryk - NIE", string);
			}
		}
		case 9: 
		{
			if(DynamicFactions[fId][fRank9TillCheck])
				format(string, sizeof(string), "Sprawdzanie funduszy frakcji - TAK");
			else
				format(string, sizeof(string), "Sprawdzanie funduszy frakcji - NIE");
			if(DynamicFactions[fId][fRank9FactionStatus])
				format(string, sizeof(string), "%s\nSprawdzanie statusu frakcji - TAK", string);
			else	
				format(string, sizeof(string), "%s\nSprawdzanie statusu frakcji - NIE", string);
			if(DynamicFactions[fId][fRank9VehBuy])
				format(string, sizeof(string), "%s\nKupowanie pojazdów - TAK", string);
			else	
				format(string, sizeof(string), "%s\nKupowanie pojazdów - NIE", string);
			if(DynamicFactions[fId][fRank9VehSell])
				format(string, sizeof(string), "%s\nSprzedawanie pojazdów - TAK", string);
			else	
				format(string, sizeof(string), "%s\nSprzedawanie pojazdów - NIE", string);
			if(DynamicFactions[fId][fRank9VehSalvage])
				format(string, sizeof(string), "%s\nZ³omowanie pojazdów - TAK", string);
			else	
				format(string, sizeof(string), "%s\nZ³omowanie pojazdów - NIE", string);
			if(DynamicFactions[fId][fRank9VehDrive])
				format(string, sizeof(string), "%s\nProwadzenie pojazdów (uruchamianie, zamykanie) - TAK", string);
			else	
				format(string, sizeof(string), "%s\nProwadzenie pojazdów (uruchamianie, zamykanie) - NIE", string);
			if(DynamicFactions[fId][fType] == FACTIONT_GANG)
			{
				if(DynamicFactions[fId][fRank9TerritoryWar])
					format(string, sizeof(string), "%s\nRozpoczynanie wojny o terytoria - TAK", string);
				else	
					format(string, sizeof(string), "%s\nRozpoczynanie wojny o terytoria - NIE", string);
				if(DynamicFactions[fId][fRank9BurnFactory])
					format(string, sizeof(string), "%s\nPodpalanie fabryk - TAK", string);
				else	
					format(string, sizeof(string), "%s\nPodpalanie fabryk - NIE", string);
			}
		}
		case 10: 
		{
			if(DynamicFactions[fId][fRank10TillCheck])
				format(string, sizeof(string), "Sprawdzanie funduszy frakcji - TAK");
			else
				format(string, sizeof(string), "Sprawdzanie funduszy frakcji - NIE");
			if(DynamicFactions[fId][fRank10FactionStatus])
				format(string, sizeof(string), "%s\nSprawdzanie statusu frakcji - TAK", string);
			else	
				format(string, sizeof(string), "%s\nSprawdzanie statusu frakcji - NIE", string);
			if(DynamicFactions[fId][fRank10VehBuy])
				format(string, sizeof(string), "%s\nKupowanie pojazdów - TAK", string);
			else	
				format(string, sizeof(string), "%s\nKupowanie pojazdów - NIE", string);
			if(DynamicFactions[fId][fRank10VehSell])
				format(string, sizeof(string), "%s\nSprzedawanie pojazdów - TAK", string);
			else	
				format(string, sizeof(string), "%s\nSprzedawanie pojazdów - NIE", string);
			if(DynamicFactions[fId][fRank10VehSalvage])
				format(string, sizeof(string), "%s\nZ³omowanie pojazdów - TAK", string);
			else	
				format(string, sizeof(string), "%s\nZ³omowanie pojazdów - NIE", string);
			if(DynamicFactions[fId][fRank10VehDrive])
				format(string, sizeof(string), "%s\nProwadzenie pojazdów (uruchamianie, zamykanie) - TAK", string);
			else	
				format(string, sizeof(string), "%s\nProwadzenie pojazdów (uruchamianie, zamykanie) - NIE", string);
			if(DynamicFactions[fId][fType] == FACTIONT_GANG)
			{
				if(DynamicFactions[fId][fRank10TerritoryWar])
					format(string, sizeof(string), "%s\nRozpoczynanie wojny o terytoria - TAK", string);
				else	
					format(string, sizeof(string), "%s\nRozpoczynanie wojny o terytoria - NIE", string);
				if(DynamicFactions[fId][fRank10BurnFactory])
					format(string, sizeof(string), "%s\nPodpalanie fabryk - TAK", string);
				else	
					format(string, sizeof(string), "%s\nPodpalanie fabryk - NIE", string);
			}
		}
	}
	new string2[64];
	format(string2, sizeof(string2), "Uprawnienia rangi %d", rank);
	ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, string2, string, "Zamknij", "");
	return 1;
}

dcmd_zmienuprawnieniarangi(playerid, params[])
{
	new fId, rank, type[64];
	if(gPlayerData[playerid][pFaction] == 255)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ liderem frakcji");
		return 1;
	}
	if(gPlayerData[playerid][pRank] != 1)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ liderem frakcji");
		return 1;
	}
	if(sscanf(params, "ds[64]", rank, type))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /zmienuprawnieniarangi [ranga (2-10)] [uprawnienie]");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] uprawnienia: stankonta, statusfrakcji, kupnopojazdu, sprzedazpojazdu, zlomowaniepojazdu");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] walkaoterytorium, podpalaniefabryk");
		return 1;
	}
	fId = gPlayerData[playerid][pFaction];
	if(strcmp(type, "stankonta") == 0)
	{
		switch(rank)
		{
			case 2:
			{
				if(DynamicFactions[fId][fRank2TillCheck])
					DynamicFactions[fId][fRank2TillCheck] = 0;
				else	
					DynamicFactions[fId][fRank2TillCheck] = 1;
				SaveFData(fId, "Rank2TillCheck");
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Zmieni³eœ uprawnienia podgl¹du stanu konta frakcji dla rangi 2", "Zamknij", "");
				return 1;
			}
			case 3:
			{
				if(DynamicFactions[fId][fRank3TillCheck])
					DynamicFactions[fId][fRank3TillCheck] = 0;
				else	
					DynamicFactions[fId][fRank3TillCheck] = 1;
				SaveFData(fId, "Rank3TillCheck");
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Zmieni³eœ uprawnienia podgl¹du stanu konta frakcji dla rangi 3", "Zamknij", "");
				return 1;
			}
			case 4:
			{
				if(DynamicFactions[fId][fRank4TillCheck])
					DynamicFactions[fId][fRank4TillCheck] = 0;
				else	
					DynamicFactions[fId][fRank4TillCheck] = 1;
				SaveFData(fId, "Rank4TillCheck");
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Zmieni³eœ uprawnienia podgl¹du stanu konta frakcji dla rangi 4", "Zamknij", "");
				return 1;
			}
			case 5:
			{
				if(DynamicFactions[fId][fRank5TillCheck])
					DynamicFactions[fId][fRank5TillCheck] = 0;
				else	
					DynamicFactions[fId][fRank5TillCheck] = 1;
				SaveFData(fId, "Rank5TillCheck");
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Zmieni³eœ uprawnienia podgl¹du stanu konta frakcji dla rangi 5", "Zamknij", "");
				return 1;
			}
			case 6:
			{
				if(DynamicFactions[fId][fRank6TillCheck])
					DynamicFactions[fId][fRank6TillCheck] = 0;
				else	
					DynamicFactions[fId][fRank6TillCheck] = 1;
				SaveFData(fId, "Rank6TillCheck");
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Zmieni³eœ uprawnienia podgl¹du stanu konta frakcji dla rangi 6", "Zamknij", "");
				return 1;
			}
			case 7:
			{
				if(DynamicFactions[fId][fRank7TillCheck])
					DynamicFactions[fId][fRank7TillCheck] = 0;
				else	
					DynamicFactions[fId][fRank7TillCheck] = 1;
				SaveFData(fId, "Rank7TillCheck");
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Zmieni³eœ uprawnienia podgl¹du stanu konta frakcji dla rangi 7", "Zamknij", "");
				return 1;
			}
			case 8:
			{
				if(DynamicFactions[fId][fRank8TillCheck])
					DynamicFactions[fId][fRank8TillCheck] = 0;
				else	
					DynamicFactions[fId][fRank8TillCheck] = 1;
				SaveFData(fId, "Rank8TillCheck");
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Zmieni³eœ uprawnienia podgl¹du stanu konta frakcji dla rangi 8", "Zamknij", "");
				return 1;
			}
			case 9:
			{
				if(DynamicFactions[fId][fRank9TillCheck])
					DynamicFactions[fId][fRank9TillCheck] = 0;
				else	
					DynamicFactions[fId][fRank9TillCheck] = 1;
				SaveFData(fId, "Rank9TillCheck");
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Zmieni³eœ uprawnienia podgl¹du stanu konta frakcji dla rangi 9", "Zamknij", "");
				return 1;
			}
			case 10:
			{
				if(DynamicFactions[fId][fRank10TillCheck])
					DynamicFactions[fId][fRank10TillCheck] = 0;
				else	
					DynamicFactions[fId][fRank10TillCheck] = 1;
				SaveFData(fId, "Rank10TillCheck");
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Zmieni³eœ uprawnienia podgl¹du stanu konta frakcji dla rangi 10", "Zamknij", "");
				return 1;
			}
		}
	}
	else if(strcmp(type, "statusfrakcji") == 0)
	{
		switch(rank)
		{
			case 2:
			{
				if(DynamicFactions[fId][fRank2FactionStatus])
					DynamicFactions[fId][fRank2FactionStatus] = 0;
				else	
					DynamicFactions[fId][fRank2FactionStatus] = 1;
				SaveFData(fId, "Rank2FactionStatus");
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Zmieni³eœ uprawnienia podgl¹du statusu frakcji dla rangi 2", "Zamknij", "");
				return 1;
			}
			case 3:
			{
				if(DynamicFactions[fId][fRank3FactionStatus])
					DynamicFactions[fId][fRank3FactionStatus] = 0;
				else	
					DynamicFactions[fId][fRank3FactionStatus] = 1;
				SaveFData(fId, "Rank3FactionStatus");
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Zmieni³eœ uprawnienia podgl¹du statusu frakcji dla rangi 3", "Zamknij", "");
				return 1;
			}
			case 4:
			{
				if(DynamicFactions[fId][fRank4FactionStatus])
					DynamicFactions[fId][fRank4FactionStatus] = 0;
				else	
					DynamicFactions[fId][fRank4FactionStatus] = 1;
				SaveFData(fId, "Rank4FactionStatus");
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Zmieni³eœ uprawnienia podgl¹du statusu frakcji dla rangi 4", "Zamknij", "");
				return 1;
			}
			case 5:
			{
				if(DynamicFactions[fId][fRank5FactionStatus])
					DynamicFactions[fId][fRank5FactionStatus] = 0;
				else	
					DynamicFactions[fId][fRank5FactionStatus] = 1;
				SaveFData(fId, "Rank5FactionStatus");
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Zmieni³eœ uprawnienia podgl¹du statusu frakcji dla rangi 5", "Zamknij", "");
				return 1;
			}
			case 6:
			{
				if(DynamicFactions[fId][fRank6FactionStatus])
					DynamicFactions[fId][fRank6FactionStatus] = 0;
				else	
					DynamicFactions[fId][fRank6FactionStatus] = 1;
				SaveFData(fId, "Rank6FactionStatus");
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Zmieni³eœ uprawnienia podgl¹du statusu frakcji dla rangi 6", "Zamknij", "");
				return 1;
			}
			case 7:
			{
				if(DynamicFactions[fId][fRank7FactionStatus])
					DynamicFactions[fId][fRank7FactionStatus] = 0;
				else	
					DynamicFactions[fId][fRank7FactionStatus] = 1;
				SaveFData(fId, "Rank7FactionStatus");
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Zmieni³eœ uprawnienia podgl¹du statusu frakcji dla rangi 7", "Zamknij", "");
				return 1;
			}
			case 8:
			{
				if(DynamicFactions[fId][fRank8FactionStatus])
					DynamicFactions[fId][fRank8FactionStatus] = 0;
				else	
					DynamicFactions[fId][fRank8FactionStatus] = 1;
				SaveFData(fId, "Rank8FactionStatus");
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Zmieni³eœ uprawnienia podgl¹du statusu frakcji dla rangi 8", "Zamknij", "");
				return 1;
			}
			case 9:
			{
				if(DynamicFactions[fId][fRank9FactionStatus])
					DynamicFactions[fId][fRank9FactionStatus] = 0;
				else	
					DynamicFactions[fId][fRank9FactionStatus] = 1;
				SaveFData(fId, "Rank9FactionStatus");
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Zmieni³eœ uprawnienia podgl¹du statusu frakcji dla rangi 9", "Zamknij", "");
				return 1;
			}
			case 10:
			{
				if(DynamicFactions[fId][fRank10FactionStatus])
					DynamicFactions[fId][fRank10FactionStatus] = 0;
				else	
					DynamicFactions[fId][fRank10FactionStatus] = 1;
				SaveFData(fId, "Rank10FactionStatus");
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Zmieni³eœ uprawnienia podgl¹du statusu frakcji dla rangi 10", "Zamknij", "");
				return 1;
			}
		}
	}
	else if(strcmp(type, "kupnopojazdu") == 0)
	{
		switch(rank)
		{
			case 2:
			{
				if(DynamicFactions[fId][fRank2VehBuy])
					DynamicFactions[fId][fRank2VehBuy] = 0;
				else	
					DynamicFactions[fId][fRank2VehBuy] = 1;
				SaveFData(fId, "Rank2VehBuy");
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Zmieni³eœ uprawnienia kupna pojazdu dla frakcji dla rangi 2", "Zamknij", "");
				return 1;
			}
			case 3:
			{
				if(DynamicFactions[fId][fRank3VehBuy])
					DynamicFactions[fId][fRank3VehBuy] = 0;
				else	
					DynamicFactions[fId][fRank3VehBuy] = 1;
				SaveFData(fId, "Rank3VehBuy");
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Zmieni³eœ uprawnienia kupna pojazdu dla frakcji dla rangi 3", "Zamknij", "");
				return 1;
			}
			case 4:
			{
				if(DynamicFactions[fId][fRank4VehBuy])
					DynamicFactions[fId][fRank4VehBuy] = 0;
				else	
					DynamicFactions[fId][fRank4VehBuy] = 1;
				SaveFData(fId, "Rank4VehBuy");
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Zmieni³eœ uprawnienia kupna pojazdu dla frakcji dla rangi 4", "Zamknij", "");
				return 1;
			}
			case 5:
			{
				if(DynamicFactions[fId][fRank5VehBuy])
					DynamicFactions[fId][fRank5VehBuy] = 0;
				else	
					DynamicFactions[fId][fRank5VehBuy] = 1;
				SaveFData(fId, "Rank5VehBuy");
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Zmieni³eœ uprawnienia kupna pojazdu dla frakcji dla rangi 5", "Zamknij", "");
				return 1;
			}
			case 6:
			{
				if(DynamicFactions[fId][fRank6VehBuy])
					DynamicFactions[fId][fRank6VehBuy] = 0;
				else	
					DynamicFactions[fId][fRank6VehBuy] = 1;
				SaveFData(fId, "Rank6VehBuy");
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Zmieni³eœ uprawnienia kupna pojazdu dla frakcji dla rangi 6", "Zamknij", "");
				return 1;
			}
			case 7:
			{
				if(DynamicFactions[fId][fRank7VehBuy])
					DynamicFactions[fId][fRank7VehBuy] = 0;
				else	
					DynamicFactions[fId][fRank7VehBuy] = 1;
				SaveFData(fId, "Rank7VehBuy");
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Zmieni³eœ uprawnienia kupna pojazdu dla frakcji dla rangi 7", "Zamknij", "");
				return 1;
			}
			case 8:
			{
				if(DynamicFactions[fId][fRank8VehBuy])
					DynamicFactions[fId][fRank8VehBuy] = 0;
				else	
					DynamicFactions[fId][fRank8VehBuy] = 1;
				SaveFData(fId, "Rank8VehBuy");
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Zmieni³eœ uprawnienia kupna pojazdu dla frakcji dla rangi 8", "Zamknij", "");
				return 1;
			}
			case 9:
			{
				if(DynamicFactions[fId][fRank9VehBuy])
					DynamicFactions[fId][fRank9VehBuy] = 0;
				else	
					DynamicFactions[fId][fRank9VehBuy] = 1;
				SaveFData(fId, "Rank9VehBuy");
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Zmieni³eœ uprawnienia kupna pojazdu dla frakcji dla rangi 9", "Zamknij", "");
				return 1;
			}
			case 10:
			{
				if(DynamicFactions[fId][fRank10VehBuy])
					DynamicFactions[fId][fRank10VehBuy] = 0;
				else	
					DynamicFactions[fId][fRank10VehBuy] = 1;
				SaveFData(fId, "Rank10VehBuy");
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Zmieni³eœ uprawnienia kupna pojazdu dla frakcji dla rangi 10", "Zamknij", "");
				return 1;
			}
		}
	}
	else if(strcmp(type, "sprzedazpojazdu") == 0)
	{
		switch(rank)
		{
			case 2:
			{
				if(DynamicFactions[fId][fRank2VehSell])
					DynamicFactions[fId][fRank2VehSell] = 0;
				else	
					DynamicFactions[fId][fRank2VehSell] = 1;
				SaveFData(fId, "Rank2VehSell");
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Zmieni³eœ uprawnienia sprzeda¿y pojazdu frakcji dla rangi 2", "Zamknij", "");
				return 1;
			}
			case 3:
			{
				if(DynamicFactions[fId][fRank3VehSell])
					DynamicFactions[fId][fRank3VehSell] = 0;
				else	
					DynamicFactions[fId][fRank3VehSell] = 1;
				SaveFData(fId, "Rank3VehSell");
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Zmieni³eœ uprawnienia sprzeda¿y pojazdu frakcji dla rangi 3", "Zamknij", "");
				return 1;
			}
			case 4:
			{
				if(DynamicFactions[fId][fRank4VehSell])
					DynamicFactions[fId][fRank4VehSell] = 0;
				else	
					DynamicFactions[fId][fRank4VehSell] = 1;
				SaveFData(fId, "Rank4VehSell");
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Zmieni³eœ uprawnienia sprzeda¿y pojazdu frakcji dla rangi 4", "Zamknij", "");
				return 1;
			}
			case 5:
			{
				if(DynamicFactions[fId][fRank5VehSell])
					DynamicFactions[fId][fRank5VehSell] = 0;
				else	
					DynamicFactions[fId][fRank5VehSell] = 1;
				SaveFData(fId, "Rank5VehSell");
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Zmieni³eœ uprawnienia sprzeda¿y pojazdu frakcji dla rangi 5", "Zamknij", "");
				return 1;
			}
			case 6:
			{
				if(DynamicFactions[fId][fRank6VehSell])
					DynamicFactions[fId][fRank6VehSell] = 0;
				else	
					DynamicFactions[fId][fRank6VehSell] = 1;
				SaveFData(fId, "Rank6VehSell");
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Zmieni³eœ uprawnienia sprzeda¿y pojazdu frakcji dla rangi 6", "Zamknij", "");
				return 1;
			}
			case 7:
			{
				if(DynamicFactions[fId][fRank7VehSell])
					DynamicFactions[fId][fRank7VehSell] = 0;
				else	
					DynamicFactions[fId][fRank7VehSell] = 1;
				SaveFData(fId, "Rank7VehSell");
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Zmieni³eœ uprawnienia sprzeda¿y pojazdu frakcji dla rangi 7", "Zamknij", "");
				return 1;
			}
			case 8:
			{
				if(DynamicFactions[fId][fRank8VehSell])
					DynamicFactions[fId][fRank8VehSell] = 0;
				else	
					DynamicFactions[fId][fRank8VehSell] = 1;
				SaveFData(fId, "Rank8VehSell");
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Zmieni³eœ uprawnienia sprzeda¿y pojazdu frakcji dla rangi 8", "Zamknij", "");
				return 1;
			}
			case 9:
			{
				if(DynamicFactions[fId][fRank9VehSell])
					DynamicFactions[fId][fRank9VehSell] = 0;
				else	
					DynamicFactions[fId][fRank9VehSell] = 1;
				SaveFData(fId, "Rank9VehSell");
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Zmieni³eœ uprawnienia sprzeda¿y pojazdu frakcji dla rangi 9", "Zamknij", "");
				return 1;
			}
			case 10:
			{
				if(DynamicFactions[fId][fRank10VehSell])
					DynamicFactions[fId][fRank10VehSell] = 0;
				else	
					DynamicFactions[fId][fRank10VehSell] = 1;
				SaveFData(fId, "Rank10VehSell");
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Zmieni³eœ uprawnienia sprzeda¿y pojazdu frakcji dla rangi 10", "Zamknij", "");
				return 1;
			}
		}
	}
	else if(strcmp(type, "zlomowaniepojazdu") == 0)
	{
		switch(rank)
		{
			case 2:
			{
				if(DynamicFactions[fId][fRank2VehSalvage])
					DynamicFactions[fId][fRank2VehSalvage] = 0;
				else	
					DynamicFactions[fId][fRank2VehSalvage] = 1;
				SaveFData(fId, "Rank2VehSalvage");
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Zmieni³eœ uprawnienia z³omowania pojazdu frakcji dla rangi 2", "Zamknij", "");
				return 1;
			}
			case 3:
			{
				if(DynamicFactions[fId][fRank3VehSalvage])
					DynamicFactions[fId][fRank3VehSalvage] = 0;
				else	
					DynamicFactions[fId][fRank3VehSalvage] = 1;
				SaveFData(fId, "Rank3VehSalvage");
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Zmieni³eœ uprawnienia z³omowania pojazdu frakcji dla rangi 3", "Zamknij", "");
				return 1;
			}
			case 4:
			{
				if(DynamicFactions[fId][fRank4VehSalvage])
					DynamicFactions[fId][fRank4VehSalvage] = 0;
				else	
					DynamicFactions[fId][fRank4VehSalvage] = 1;
				SaveFData(fId, "Rank4VehSalvage");
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Zmieni³eœ uprawnienia z³omowania pojazdu frakcji dla rangi 4", "Zamknij", "");
				return 1;
			}
			case 5:
			{
				if(DynamicFactions[fId][fRank5VehSalvage])
					DynamicFactions[fId][fRank5VehSalvage] = 0;
				else	
					DynamicFactions[fId][fRank5VehSalvage] = 1;
				SaveFData(fId, "Rank5VehSalvage");
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Zmieni³eœ uprawnienia z³omowania pojazdu frakcji dla rangi 5", "Zamknij", "");
				return 1;
			}
			case 6:
			{
				if(DynamicFactions[fId][fRank6VehSalvage])
					DynamicFactions[fId][fRank6VehSalvage] = 0;
				else	
					DynamicFactions[fId][fRank6VehSalvage] = 1;
				SaveFData(fId, "Rank6VehSalvage");
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Zmieni³eœ uprawnienia z³omowania pojazdu frakcji dla rangi 6", "Zamknij", "");
				return 1;
			}
			case 7:
			{
				if(DynamicFactions[fId][fRank7VehSalvage])
					DynamicFactions[fId][fRank7VehSalvage] = 0;
				else	
					DynamicFactions[fId][fRank7VehSalvage] = 1;
				SaveFData(fId, "Rank7VehSalvage");
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Zmieni³eœ uprawnienia z³omowania pojazdu frakcji dla rangi 7", "Zamknij", "");
				return 1;
			}
			case 8:
			{
				if(DynamicFactions[fId][fRank8VehSalvage])
					DynamicFactions[fId][fRank8VehSalvage] = 0;
				else	
					DynamicFactions[fId][fRank8VehSalvage] = 1;
				SaveFData(fId, "Rank8VehSalvage");
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Zmieni³eœ uprawnienia z³omowania pojazdu frakcji dla rangi 8", "Zamknij", "");
				return 1;
			}
			case 9:
			{
				if(DynamicFactions[fId][fRank9VehSalvage])
					DynamicFactions[fId][fRank9VehSalvage] = 0;
				else	
					DynamicFactions[fId][fRank9VehSalvage] = 1;
				SaveFData(fId, "Rank9VehSalvage");
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Zmieni³eœ uprawnienia z³omowania pojazdu frakcji dla rangi 9", "Zamknij", "");
				return 1;
			}
			case 10:
			{
				if(DynamicFactions[fId][fRank10VehSalvage])
					DynamicFactions[fId][fRank10VehSalvage] = 0;
				else	
					DynamicFactions[fId][fRank10VehSalvage] = 1;
				SaveFData(fId, "Rank10VehSalvage");
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Zmieni³eœ uprawnienia z³omowania pojazdu frakcji dla rangi 10", "Zamknij", "");
				return 1;
			}
		}
	}
	else if(strcmp(type, "walkaoterytorium") == 0)
	{
		switch(rank)
		{
			case 2:
			{
				if(DynamicFactions[fId][fRank2TerritoryWar])
					DynamicFactions[fId][fRank2TerritoryWar] = 0;
				else	
					DynamicFactions[fId][fRank2TerritoryWar] = 1;
				SaveFData(fId, "Rank2TerritoryWar");
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Zmieni³eœ uprawnienia rozpoczynania wojny o terytorium dla rangi 2", "Zamknij", "");
				return 1;
			}
			case 3:
			{
				if(DynamicFactions[fId][fRank3TerritoryWar])
					DynamicFactions[fId][fRank3TerritoryWar] = 0;
				else	
					DynamicFactions[fId][fRank3TerritoryWar] = 1;
				SaveFData(fId, "Rank3TerritoryWar");
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Zmieni³eœ uprawnienia rozpoczynania wojny o terytorium dla rangi 3", "Zamknij", "");
				return 1;
			}
			case 4:
			{
				if(DynamicFactions[fId][fRank4TerritoryWar])
					DynamicFactions[fId][fRank4TerritoryWar] = 0;
				else	
					DynamicFactions[fId][fRank4TerritoryWar] = 1;
				SaveFData(fId, "Rank4TerritoryWar");
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Zmieni³eœ uprawnienia rozpoczynania wojny o terytorium dla rangi 4", "Zamknij", "");
				return 1;
			}
			case 5:
			{
				if(DynamicFactions[fId][fRank5TerritoryWar])
					DynamicFactions[fId][fRank5TerritoryWar] = 0;
				else	
					DynamicFactions[fId][fRank5TerritoryWar] = 1;
				SaveFData(fId, "Rank5TerritoryWar");
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Zmieni³eœ uprawnienia rozpoczynania wojny o terytorium dla rangi 5", "Zamknij", "");
				return 1;
			}
			case 6:
			{
				if(DynamicFactions[fId][fRank6TerritoryWar])
					DynamicFactions[fId][fRank6TerritoryWar] = 0;
				else	
					DynamicFactions[fId][fRank6TerritoryWar] = 1;
				SaveFData(fId, "Rank6TerritoryWar");
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Zmieni³eœ uprawnienia rozpoczynania wojny o terytorium dla rangi 6", "Zamknij", "");
				return 1;
			}
			case 7:
			{
				if(DynamicFactions[fId][fRank7TerritoryWar])
					DynamicFactions[fId][fRank7TerritoryWar] = 0;
				else	
					DynamicFactions[fId][fRank7TerritoryWar] = 1;
				SaveFData(fId, "Rank7TerritoryWar");
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Zmieni³eœ uprawnienia rozpoczynania wojny o terytorium dla rangi 7", "Zamknij", "");
				return 1;
			}
			case 8:
			{
				if(DynamicFactions[fId][fRank8TerritoryWar])
					DynamicFactions[fId][fRank8TerritoryWar] = 0;
				else	
					DynamicFactions[fId][fRank8TerritoryWar] = 1;
				SaveFData(fId, "Rank8TerritoryWar");
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Zmieni³eœ uprawnienia rozpoczynania wojny o terytorium dla rangi 8", "Zamknij", "");
				return 1;
			}
			case 9:
			{
				if(DynamicFactions[fId][fRank9TerritoryWar])
					DynamicFactions[fId][fRank9TerritoryWar] = 0;
				else	
					DynamicFactions[fId][fRank9TerritoryWar] = 1;
				SaveFData(fId, "Rank9TerritoryWar");
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Zmieni³eœ uprawnienia rozpoczynania wojny o terytorium dla rangi 9", "Zamknij", "");
				return 1;
			}
			case 10:
			{
				if(DynamicFactions[fId][fRank10TerritoryWar])
					DynamicFactions[fId][fRank10TerritoryWar] = 0;
				else	
					DynamicFactions[fId][fRank10TerritoryWar] = 1;
				SaveFData(fId, "Rank10TerritoryWar");
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Zmieni³eœ uprawnienia rozpoczynania wojny o terytorium dla rangi 10", "Zamknij", "");
				return 1;
			}
		}
	}
	else if(strcmp(type, "podpalaniefabryk") == 0)
	{
		switch(rank)
		{
			case 2:
			{
				if(DynamicFactions[fId][fRank2BurnFactory])
					DynamicFactions[fId][fRank2BurnFactory] = 0;
				else	
					DynamicFactions[fId][fRank2BurnFactory] = 1;
				SaveFData(fId, "Rank2BurnFactory");
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Zmieni³eœ uprawnienia podpalania fabryk dla rangi 2", "Zamknij", "");
				return 1;
			}
			case 3:
			{
				if(DynamicFactions[fId][fRank3BurnFactory])
					DynamicFactions[fId][fRank3BurnFactory] = 0;
				else	
					DynamicFactions[fId][fRank3BurnFactory] = 1;
				SaveFData(fId, "Rank3BurnFactory");
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Zmieni³eœ uprawnienia podpalania fabryk dla rangi 3", "Zamknij", "");
				return 1;
			}
			case 4:
			{
				if(DynamicFactions[fId][fRank4BurnFactory])
					DynamicFactions[fId][fRank4BurnFactory] = 0;
				else	
					DynamicFactions[fId][fRank4BurnFactory] = 1;
				SaveFData(fId, "Rank4BurnFactory");
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Zmieni³eœ uprawnienia podpalania fabryk dla rangi 4", "Zamknij", "");
				return 1;
			}
			case 5:
			{
				if(DynamicFactions[fId][fRank5BurnFactory])
					DynamicFactions[fId][fRank5BurnFactory] = 0;
				else	
					DynamicFactions[fId][fRank5BurnFactory] = 1;
				SaveFData(fId, "Rank5BurnFactory");
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Zmieni³eœ uprawnienia podpalania fabryk dla rangi 5", "Zamknij", "");
				return 1;
			}
			case 6:
			{
				if(DynamicFactions[fId][fRank6BurnFactory])
					DynamicFactions[fId][fRank6BurnFactory] = 0;
				else	
					DynamicFactions[fId][fRank6BurnFactory] = 1;
				SaveFData(fId, "Rank6BurnFactory");
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Zmieni³eœ uprawnienia podpalania fabryk dla rangi 6", "Zamknij", "");
				return 1;
			}
			case 7:
			{
				if(DynamicFactions[fId][fRank7BurnFactory])
					DynamicFactions[fId][fRank7BurnFactory] = 0;
				else	
					DynamicFactions[fId][fRank7BurnFactory] = 1;
				SaveFData(fId, "Rank7BurnFactory");
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Zmieni³eœ uprawnienia podpalania fabryk dla rangi 7", "Zamknij", "");
				return 1;
			}
			case 8:
			{
				if(DynamicFactions[fId][fRank8BurnFactory])
					DynamicFactions[fId][fRank8BurnFactory] = 0;
				else	
					DynamicFactions[fId][fRank8BurnFactory] = 1;
				SaveFData(fId, "Rank8BurnFactory");
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Zmieni³eœ uprawnienia podpalania fabryk dla rangi 8", "Zamknij", "");
				return 1;
			}
			case 9:
			{
				if(DynamicFactions[fId][fRank9BurnFactory])
					DynamicFactions[fId][fRank9BurnFactory] = 0;
				else	
					DynamicFactions[fId][fRank9BurnFactory] = 1;
				SaveFData(fId, "Rank9BurnFactory");
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Zmieni³eœ uprawnienia podpalania fabryk dla rangi 9", "Zamknij", "");
				return 1;
			}
			case 10:
			{
				if(DynamicFactions[fId][fRank10BurnFactory])
					DynamicFactions[fId][fRank10BurnFactory] = 0;
				else	
					DynamicFactions[fId][fRank10BurnFactory] = 1;
				SaveFData(fId, "Rank10BurnFactory");
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Zmieni³eœ uprawnienia podpalania fabryk dla rangi 10", "Zamknij", "");
				return 1;
			}
		}
	}
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /zmienuprawnieniarangi [ranga (2-10)] [uprawnienie]");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] uprawnienia: stankonta, statusfrakcji, kupnopojazdu, sprzedazpojazdu, zlomowaniepojazdu, prowadzeniepojazdu");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] walkaoterytorium, podpalaniefabryk");
	return 1;
}
	
dcmd_oddajterytorium(playerid, params[])
{
	new givePlayerId;
	if(gPlayerData[playerid][pFaction] == 255)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ liderem gangu");
		return 1;
	}
	if(gPlayerData[playerid][pRank] != 1)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ liderem gangu");
		return 1;
	}
	if(DynamicFactions[gPlayerData[playerid][pFaction]][fType] != FACTIONT_GANG)
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ liderem gangu !");
		return 1;
	}
	if(sscanf(params, "d", givePlayerId))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /oddajterytorium [playerid]");
		return 1;
	}
	if(!IsPlayerConnected(givePlayerId))
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Osoba której chcesz oddaæ terytorium nie jest online");
		return 1;
	}
	if(gPlayerData[givePlayerId][pFaction] == 255)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Osoba której chcesz oddaæ terytorium nie jest cz³onkiem gangu");
		return 1;
	}
	if(DynamicFactions[gPlayerData[givePlayerId][pFaction]][fType] != FACTIONT_GANG)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Osoba której chcesz oddaæ terytorium nie jest cz³onkiem gangu");
		return 1;
	}
	if(gPlayerData[playerid][pFaction] == gPlayerData[givePlayerId][pFaction])
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Osoba której chcesz oddaæ terytorium nale¿y do tej samej frakcji");
		return 1;
	}
	for(new i = 0; i < sizeof(DynamicZones); i++)
	{
		if(IsPlayerInArea(playerid, DynamicZones[i][mPosMaxX], DynamicZones[i][mPosMinX], DynamicZones[i][mPosMaxY], DynamicZones[i][mPosMinY]))
		{
			if(DynamicZones[i][mFaction] != gPlayerData[playerid][pFaction])
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz oddaæ terytorium które nie nale¿y do twojej frakcji");
				return 1;
			}
			DynamicZones[i][mFaction] = gPlayerData[givePlayerId][pFaction];
			SaveGangZone(i, "Faction");
			foreach(Player, j)
			{
				if(!gPlayerLogged[j])
					continue;
				if(gPlayerData[j][pFaction] != 255)
				{
					if(DynamicFactions[gPlayerData[j][pFaction]][fType] == 3)
					{						
						GangZoneHideForPlayer(j, DynamicZones[i][mZoneId]);
						if(gPlayerData[j][pFaction] == DynamicZones[i][mFaction])
							GangZoneShowForPlayer(j, DynamicZones[i][mZoneId], 0x00FF0090);
						else
							GangZoneShowForPlayer(j, DynamicZones[i][mZoneId], 0xFF000090);
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Terytorium zosta³o przekazane");
						return 1;
					}
				}
			}
		}
	}
	SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie znajdujesz siê na ¿adnym terytorium");
	return 1;
}

dcmd_wyrzuczwyscigu(playerid, params[])
{
	new entrant;
	for(new i = 0; i < sizeof(gRaceStatus); i++)
	{
		if(gRaceStatus[i][mRaceEntrant1Id] != playerid || gRaceStatus[i][mRaceEntrant1Status] != PLAYER_RACE_STATE_CONNECTED)
			continue;
		if(sscanf(params, "d", entrant))
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /wyrzuczwyscigu [slot (2-10)]");
			return 1;
		}
		switch(entrant)
		{
			case 2:
			{
				if(gRaceStatus[i][mRaceEntrant2Status] == PLAYER_RACE_STATE_CONNECTED)
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Wyrzuci³eœ zadownika z wyœcigu");
					SendClientMessage(gRaceStatus[i][mRaceEntrant2Id], COLOR_ORANGE, "[INFO:] Zosta³eœ wyrzucony z wyœcigu przez organizatora");
					RemovePlayerFromRace(gRaceStatus[i][mRaceEntrant2Id]);
					return 1;
				}
			}
			case 3:
			{
				if(gRaceStatus[i][mRaceEntrant3Status] == PLAYER_RACE_STATE_CONNECTED)
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Wyrzuci³eœ zadownika z wyœcigu");
					SendClientMessage(gRaceStatus[i][mRaceEntrant3Id], COLOR_ORANGE, "[INFO:] Zosta³eœ wyrzucony z wyœcigu przez organizatora");
					RemovePlayerFromRace(gRaceStatus[i][mRaceEntrant3Id]);
					return 1;
				}
			}
			case 4:
			{
				if(gRaceStatus[i][mRaceEntrant4Status] == PLAYER_RACE_STATE_CONNECTED)
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Wyrzuci³eœ zadownika z wyœcigu");
					SendClientMessage(gRaceStatus[i][mRaceEntrant4Id], COLOR_ORANGE, "[INFO:] Zosta³eœ wyrzucony z wyœcigu przez organizatora");
					RemovePlayerFromRace(gRaceStatus[i][mRaceEntrant4Id]);
					return 1;
				}
			}
			case 5:
			{
				if(gRaceStatus[i][mRaceEntrant5Status] == PLAYER_RACE_STATE_CONNECTED)
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Wyrzuci³eœ zadownika z wyœcigu");
					SendClientMessage(gRaceStatus[i][mRaceEntrant5Id], COLOR_ORANGE, "[INFO:] Zosta³eœ wyrzucony z wyœcigu przez organizatora");
					RemovePlayerFromRace(gRaceStatus[i][mRaceEntrant5Id]);
					return 1;
				}
			}
			case 6:
			{
				if(gRaceStatus[i][mRaceEntrant6Status] == PLAYER_RACE_STATE_CONNECTED)
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Wyrzuci³eœ zadownika z wyœcigu");
					SendClientMessage(gRaceStatus[i][mRaceEntrant6Id], COLOR_ORANGE, "[INFO:] Zosta³eœ wyrzucony z wyœcigu przez organizatora");
					RemovePlayerFromRace(gRaceStatus[i][mRaceEntrant6Id]);
					return 1;
				}
			}
			case 7:
			{
				if(gRaceStatus[i][mRaceEntrant7Status] == PLAYER_RACE_STATE_CONNECTED)
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Wyrzuci³eœ zadownika z wyœcigu");
					SendClientMessage(gRaceStatus[i][mRaceEntrant7Id], COLOR_ORANGE, "[INFO:] Zosta³eœ wyrzucony z wyœcigu przez organizatora");
					RemovePlayerFromRace(gRaceStatus[i][mRaceEntrant7Id]);
					return 1;
				}
			}
			case 8:
			{
				if(gRaceStatus[i][mRaceEntrant8Status] == PLAYER_RACE_STATE_CONNECTED)
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Wyrzuci³eœ zadownika z wyœcigu");
					SendClientMessage(gRaceStatus[i][mRaceEntrant8Id], COLOR_ORANGE, "[INFO:] Zosta³eœ wyrzucony z wyœcigu przez organizatora");
					RemovePlayerFromRace(gRaceStatus[i][mRaceEntrant8Id]);
					return 1;
				}
			}
			case 9:
			{
				if(gRaceStatus[i][mRaceEntrant9Status] == PLAYER_RACE_STATE_CONNECTED)
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Wyrzuci³eœ zadownika z wyœcigu");
					SendClientMessage(gRaceStatus[i][mRaceEntrant9Id], COLOR_ORANGE, "[INFO:] Zosta³eœ wyrzucony z wyœcigu przez organizatora");
					RemovePlayerFromRace(gRaceStatus[i][mRaceEntrant9Id]);
					return 1;
				}
			}
			case 10:
			{
				if(gRaceStatus[i][mRaceEntrant10Status] == PLAYER_RACE_STATE_CONNECTED)
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Wyrzuci³eœ zadownika z wyœcigu");
					SendClientMessage(gRaceStatus[i][mRaceEntrant10Id], COLOR_ORANGE, "[INFO:] Zosta³eœ wyrzucony z wyœcigu przez organizatora");
					RemovePlayerFromRace(gRaceStatus[i][mRaceEntrant10Id]);
					return 1;
				}
			}
		}
	}
	SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz wyrzuciæ tej osoby z wyœcigu lub nie jesteœ organizatorem tego wyœcigu");
	return 1;
}

dcmd_wejdzdokampera(playerid, params[])
{
	#pragma unused params
	if(gPlayerVars[playerid][mAtCamperId] != -1)
		return 1;
	new vehicleid = GetClosestVehicle(playerid);
	new Float:xc, Float:yc, Float:ac, Float:bc, Float:vx, Float:vy, Float:vz, Float:va;
	GetVehiclePos(vehicleid, vx, vy, vz);
	GetVehicleZAngle(vehicleid, va);
	GetPlayerFacingAngle(playerid, ac);
	GetXYInFrontOfPlayer(playerid, xc, yc, 1.86);
	bc = ac;
	if(ac-90.0 < 0.0)
		ac = 270.0+ac;
	else
		ac -= 90.0;
	if(bc+90.0 > 360.0)
		bc = 430.0-bc;
	else
		bc += 90.0;
	if(floatabs(va-bc) > 28.0)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Jesteœ zbyt daleko aby wejœæ do pojazdu !");
		return 1;
	}
	if(gVehData[vehicleid-1][Closed] && !AdminDuty[playerid])
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Pojazd jest zamkniêty");
		return 1;
	}
	gPlayerVars[playerid][mAtCamperId] = vehicleid-1;
	SetPlayerInterior(playerid, 1);
	SetPlayerToPos(playerid, 1808.83, -1593.94, 5209.09);
	SetPlayerVirtualWorld(playerid, vehicleid-1);
	SetPlayerFacingAngle(playerid, 269.65);
	TogglePlayerControllable(playerid, 0);
	defer UnfreezePlayer(playerid);
	return 1;
}

dcmd_wyjdzzkampera(playerid, params[])
{
	#pragma unused params
	if(gPlayerVars[playerid][mAtCamperId] == -1)
		return 1;
	new vehId = gPlayerVars[playerid][mAtCamperId];
	GetVehiclePos(vehId+1, gVehData[vehId][mVehX], gVehData[vehId][mVehY], gVehData[vehId][mVehZ]);
	
	SetPlayerInterior(playerid, gVehData[vehId][mVehInt]);
	SetPlayerToPos(playerid, gVehData[vehId][mVehX], gVehData[vehId][mVehY], gVehData[vehId][mVehZ]);
	SetPlayerVirtualWorld(playerid, gVehData[vehId][mVehVW]);
	SetPlayerFacingAngle(playerid, gVehData[vehId][mVehA]);
	
	gPlayerVars[playerid][mAtCamperId] = -1;
	
	TogglePlayerControllable(playerid, 0);
	defer UnfreezePlayer(playerid);
	return 1;
}

dcmd_tod(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new lHour, lMin;
	if(sscanf(params, "dd", lHour, lMin))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /tod [Hour] [Min]");
		return 1;
	}
	gHour = lHour;
	gMin = lMin;
	SetPlayerTime(playerid, gHour, gMin);
	return 1;
}

dcmd_przerwijogladanie(playerid, params[])
{
	#pragma unused params
	if(gHorseWatching[playerid] == 1)
	{ 		
		TogglePlayerControllable(playerid, 1);
	    TextDrawHideForPlayer(playerid, gHorseBG2);
	    TextDrawHideForPlayer(playerid, gHorseBG1);
	    TextDrawHideForPlayer(playerid, gHorseStart2);
	    TextDrawHideForPlayer(playerid, gHorseFinish2);
		TextDrawHideForPlayer(playerid, gHorse1);
	    TextDrawHideForPlayer(playerid, gHorse2);
	    TextDrawHideForPlayer(playerid, gHorse3);
	    TextDrawHideForPlayer(playerid, gHorse4);
	    TextDrawHideForPlayer(playerid, gHorseNum1);
	    TextDrawHideForPlayer(playerid, gHorseNum2);
	    TextDrawHideForPlayer(playerid, gHorseNum3);
	    TextDrawHideForPlayer(playerid, gHorseNum4);
	    TextDrawHideForPlayer(playerid, gHorseStart);
	    TextDrawHideForPlayer(playerid, gHorseFinish);
	    gHorseWatching[playerid] = 1;
	    SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Przerwa³eœ ogl¹danie wyœcigu");
	}
	return 1;
}

dcmd_ogladaj(playerid, params[])
{
	#pragma unused params
	if(gPlayerVars[playerid][mAtBuildingId] != 121)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie znajdujesz siê w budynku wyœcigów konnych");
		return 1;
	}
	if(gHorsePrepared || gHorseRaceStarted)
	{
		TogglePlayerControllable(playerid, 0);
	    TextDrawShowForPlayer(playerid, gHorseBG2);
	    TextDrawShowForPlayer(playerid, gHorseBG1);
	    TextDrawShowForPlayer(playerid, gHorseStart2);
	    TextDrawShowForPlayer(playerid, gHorseFinish2);
		TextDrawShowForPlayer(playerid, gHorse1);
	    TextDrawShowForPlayer(playerid, gHorse2);
	    TextDrawShowForPlayer(playerid, gHorse3);
	    TextDrawShowForPlayer(playerid, gHorse4);
	    TextDrawShowForPlayer(playerid, gHorseNum1);
	    TextDrawShowForPlayer(playerid, gHorseNum2);
	    TextDrawShowForPlayer(playerid, gHorseNum3);
	    TextDrawShowForPlayer(playerid, gHorseNum4);
	    TextDrawShowForPlayer(playerid, gHorseStart);
	    TextDrawShowForPlayer(playerid, gHorseFinish);
	    gHorseWatching[playerid] = 1;
  	}
  	else
  	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Wyœcig jescze siê nie rozpocz¹³");
  	}
	return 1;
}

dcmd_komendybuchmacherskie(playerid, params[])
{
	#pragma unused params
	
	if(gPlayerVars[playerid][mAtBuildingId] != 121)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie znajdujesz siê w budynku wyœcigów konnych");
		return 1;
	}
	
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /ogladaj - /przerwijogladanie - /obstawiaj - /mojezaklady - /listazakladow");
	return 1;
}

dcmd_listazakladow(playerid, params[])
{
	#pragma unused params
	
	if(gPlayerVars[playerid][mAtBuildingId] != 121)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie znajdujesz siê w budynku wyœcigów konnych");
		return 1;
	}

	new betOnHorses[4], betOnHorsesValue[4];
	
	foreach(Player, i)
	{
		if(!gPlayerLogged[i])
		{
			continue;
		}
		
		if(gHorseMoneyBet[i] > 0)
		{
			betOnHorsesValue[gHorseBetOnHorse[i]-1] += gHorseMoneyBet[i];
			betOnHorses[gHorseBetOnHorse[i]-1]++;
		}
	}
	
	new string[512];
	
	format(string, sizeof(string), ""#COLOR_BEGIN2"Aktualne zak³ady:\n\n"#COLOR_BEGIN"Koñ nr 1, zak³adów: "#COLOR_DEFAULT"%d, "#COLOR_BEGIN"wartoœc zak³adów: "#COLOR_DEFAULT"$%d\n",
		betOnHorses[0], betOnHorsesValue[0]);
	
	format(string, sizeof(string), "%s"#COLOR_BEGIN"Koñ nr 2, zak³adów: "#COLOR_DEFAULT"%d, wartoœc zak³adów: "#COLOR_DEFAULT"$%d\n",
		string, betOnHorses[1], betOnHorsesValue[1]);
	
	format(string, sizeof(string), "%s"#COLOR_BEGIN"Koñ nr 3, zak³adów: "#COLOR_DEFAULT"%d, wartoœc zak³adów: "#COLOR_DEFAULT"$%d\n",
		string, betOnHorses[2], betOnHorsesValue[2]);
	
	format(string, sizeof(string), "%s"#COLOR_BEGIN"Koñ nr 4, zak³adów: "#COLOR_DEFAULT"%d, wartoœc zak³adów: "#COLOR_DEFAULT"$%d\n",
		string, betOnHorses[3], betOnHorsesValue[3]);
	
	ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Zak³ady", string, "Zamknij", "");
	
	return 1;
}
	
dcmd_obstawiaj(playerid, params[])
{
	if(gPlayerVars[playerid][mAtBuildingId] != 121)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie znajdujesz siê w budynku wyœcigów konnych");
		return 1;
	}
	
	new lCash, lHorse;
	
	if(sscanf(params, "dd", lCash, lHorse))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /obstawiaj [iloœæ $] [nr konia (1-4)]");
		return 1;
	}
	
	if(lHorse < 1 || lHorse > 4)
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /obstawiaj [iloœæ $] [nr konia (1-4)]");
		return 1;
	}
	
	if(lCash > gPlayerData[playerid][pCash])
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz tylu pieniêdzy");
		return 1;
	}
	
	if(lCash < 100 || lCash > 5000)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Stawki zak³adów ograniczone s¹ od 100$ do 5000$");
		return 1;
	}
	
	if(gHorseMoneyBet[playerid])
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ju¿ obstawi³eœ jednego konia ! Nie mo¿esz dokonaæ zmian");
		return 1;
	}
	
	if(gHorseRaceStarted)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Wyœcig ju¿ siê rozpocz¹³ - nie mo¿na ju¿ obstawiaæ");
		return 1;
	}

	
	gHorseMoneyBet[playerid] = lCash;
	GivePlayerCash(playerid, -lCash);
	gHorseBetOnHorse[playerid] = lHorse;
	
	new string[128];
	
	format(string, sizeof(string), "[INFO:] Obstawi³eœ konia o nr %d na $%d ! Pamiêtaj, ¿e zak³ad jest tylko wa¿ny jeœli pozostaniesz w grze !", gHorseBetOnHorse[playerid], gHorseMoneyBet[playerid]);
	SendClientMessage(playerid, COLOR_GREEN, string);

	return 1;
}

dcmd_mojezaklady(playerid, params[])
{
	#pragma unused params
	new string[128];
	if(gHorseMoneyBet[playerid])
		format(string, sizeof(string), "[INFO:] Obstawi³eœ $%d na konia nr %d", gHorseMoneyBet[playerid], gHorseBetOnHorse[playerid]);
	else
		format(string, sizeof(string), "[INFO:] Nie dokona³eœ jeszcze obstawienia !");
	SendClientMessage(playerid, COLOR_ORANGE, string);
	return 1;
}

dcmd_zdejmijpancerz(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pArmour])
	{
		if(gPlayerData[playerid][pArmour] > 50.0)
		{
			InsertPlayerItemEx(playerid, 3, 23, floatround(gPlayerData[playerid][pArmour]), 0, 0, 0, "Puste", 1);
			SetPlayerArmourEx(playerid, 0);
		}
		else
		{
			InsertPlayerItemEx(playerid, 3, 22, floatround(gPlayerData[playerid][pArmour]), 0, 0, 0, "Puste", 1);
			SetPlayerArmourEx(playerid, 0);
		}
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Zdj¹³eœ pancerz");
	}
	else
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie posiadasz pancerza !");
	return 1;
}

dcmd_wezkredyt(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
	{
		if(!IsAtBank(playerid))
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w banku !");
			return 1;
		}
		
		if(gPlayerData[playerid][pWarnings])
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz wzi¹œæ kredytu - posiadasz ostrze¿enia");
			return 1;
		}
		
		if(!gPlayerData[playerid][pJob])
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Musisz posiadaæ prace aby ubiegaæ siê o kredyt");
			return 1;
		}
	}
	
	if(gPlayerData[playerid][mCreditValue])
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Posiadasz ju¿ jeden kredyt ! Aby wzi¹œæ kolejny musisz sp³aciæ poprzedni");
		return 1;
	}
	
	new creditId, creditTime, string[128];
	
	if(sscanf(params, "dd", creditId, creditTime))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /wezkredyt [id kredytu] [czas sp³aty]");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] id kredytu: [1 - 5 000$] , [2 - 15 000$] , [3 - 25 000$]");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] czas sp³aty: [1 - 1 miesi¹c - 5%%] , [2 - 3 miesi¹ce - 10%%] , [3 - 6 miesiêcy - 15%%]");
		return 1;
	}
	
	if(creditTime < 0 || creditTime > 3)
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /wezkredyt [id kredytu] [czas sp³aty]");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] id kredytu: [1 - 5 000$] , [2 - 15 000$] , [3 - 25 000$]");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] czas sp³aty: [1 - 1 miesi¹c - 5%%] , [2 - 3 miesi¹ce - 10%%] , [3 - 6 miesiêcy - 15%%]");
		return 1;
	}
	
	if(creditId < 0 || creditId > 3)
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /wezkredyt [id kredytu] [czas sp³aty]");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] id kredytu: [1 - 5 000$] , [2 - 15 000$] , [3 - 25 000$]");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] czas sp³aty: [1 - 1 miesi¹c - 5%%] , [2 - 3 miesi¹ce - 10%%] , [3 - 6 miesiêcy - 15%%]");
		return 1;
	}
	
	switch(creditId)
	{
		case 1:
		{
			if(gPlayerData[playerid][pPlayingHours] < 5)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Musisz mieæ przegrane 5 godzin aby móc ubiegaæ siê o ten kredyt !");
				return 1;
			}
			
			gPlayerData[playerid][pBank] += 5000;
			
			DynamicFactions[FACTIONID_GOVERNMENT][fBank] -= 5000;
			SaveFData(FACTIONID_GOVERNMENT, "Bank");
			
			switch(creditTime)
			{
				case 1:
				{
					gPlayerData[playerid][mCreditValue] = 5000+floatround(5000*0.05);
					gPlayerData[playerid][mCreditRepayment] = floatround(5000/7);
					format(string, sizeof(string), "[INFO:] Kredyt przyznany, iloœæ rat: 7, kwota sp³aty pojedynczej raty: $%d, ca³kowita kwota do sp³aty: $%d",
						gPlayerData[playerid][mCreditRepayment], gPlayerData[playerid][mCreditValue]);
				}
				case 2:
				{
					gPlayerData[playerid][mCreditValue] = 5000+floatround(5000*0.10);
					gPlayerData[playerid][mCreditRepayment] = floatround(5000/21);
					format(string, sizeof(string), "[INFO:] Kredyt przyznany, iloœæ rat: 21, kwota sp³aty pojedynczej raty: $%d, ca³kowita kwota do sp³aty: $%d",
						gPlayerData[playerid][mCreditRepayment], gPlayerData[playerid][mCreditValue]);
				}
				case 3:
				{
					gPlayerData[playerid][mCreditValue] = 5000+floatround(5000*0.15);
					gPlayerData[playerid][mCreditRepayment] = floatround(5000/42);
					format(string, sizeof(string), "[INFO:] Kredyt przyznany, iloœæ rat: 42, kwota sp³aty pojedynczej raty: $%d, ca³kowita kwota do sp³aty: $%d",
						gPlayerData[playerid][mCreditRepayment], gPlayerData[playerid][mCreditValue]);
				}
			}
		}
		case 2:
		{
			if(gPlayerData[playerid][pPlayingHours] < 15)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Musisz mieæ przegrane 15 godzin aby móc ubiegaæ siê o ten kredyt !");
				return 1;
			}
			
			gPlayerData[playerid][pBank] += 15000;
			
			DynamicFactions[FACTIONID_GOVERNMENT][fBank] -= 15000;
			SaveFData(FACTIONID_GOVERNMENT, "Bank");
			
			switch(creditTime)
			{
				case 1:
				{
					gPlayerData[playerid][mCreditValue] = 15000+floatround(15000*0.05);
					gPlayerData[playerid][mCreditRepayment] = floatround(15000/7);
					format(string, sizeof(string), "[INFO:] Kredyt przyznany, iloœæ rat: 7, kwota sp³aty pojedynczej raty: $%d, ca³kowita kwota do sp³aty: $%d",
						gPlayerData[playerid][mCreditRepayment], gPlayerData[playerid][mCreditValue]);
				}
				case 2:
				{
					gPlayerData[playerid][mCreditValue] = 15000+floatround(15000*0.10);
					gPlayerData[playerid][mCreditRepayment] = floatround(15000/21);
					format(string, sizeof(string), "[INFO:] Kredyt przyznany, iloœæ rat: 21, kwota sp³aty pojedynczej raty: $%d, ca³kowita kwota do sp³aty: $%d",
						gPlayerData[playerid][mCreditRepayment], gPlayerData[playerid][mCreditValue]);
				}
				case 3:
				{
					gPlayerData[playerid][mCreditValue] = 15000+floatround(15000*0.15);
					gPlayerData[playerid][mCreditRepayment] = floatround(15000/42);
					format(string, sizeof(string), "[INFO:] Kredyt przyznany, iloœæ rat: 42, kwota sp³aty pojedynczej raty: $%d, ca³kowita kwota do sp³aty: $%d",
						gPlayerData[playerid][mCreditRepayment], gPlayerData[playerid][mCreditValue]);
				}
			}
		}
		case 3:
		{
			if(gPlayerData[playerid][pPlayingHours] < 25)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Musisz mieæ przegrane 25 godzin aby móc ubiegaæ siê o ten kredyt !");
				return 1;
			}
			
			gPlayerData[playerid][pBank] += 25000;
			
			DynamicFactions[FACTIONID_GOVERNMENT][fBank] -= 25000;
			SaveFData(FACTIONID_GOVERNMENT, "Bank");
			
			switch(creditTime)
			{
				case 1:
				{
					gPlayerData[playerid][mCreditValue] = 25000+floatround(25000*0.05);
					gPlayerData[playerid][mCreditRepayment] = floatround(25000/7);
					format(string, sizeof(string), "[INFO:] Kredyt przyznany, iloœæ rat: 7, kwota sp³aty pojedynczej raty: $%d, ca³kowita kwota do sp³aty: $%d",
						gPlayerData[playerid][mCreditRepayment], gPlayerData[playerid][mCreditValue]);
				}
				case 2:
				{
					gPlayerData[playerid][mCreditValue] = 25000+floatround(25000*0.10);
					gPlayerData[playerid][mCreditRepayment] = floatround(25000/21);
					format(string, sizeof(string), "[INFO:] Kredyt przyznany, iloœæ rat: 21, kwota sp³aty pojedynczej raty: $%d, ca³kowita kwota do sp³aty: $%d",
						gPlayerData[playerid][mCreditRepayment], gPlayerData[playerid][mCreditValue]);
				}
				case 3:
				{
					gPlayerData[playerid][mCreditValue] = 25000+floatround(25000*0.15);
					gPlayerData[playerid][mCreditRepayment] = floatround(25000/42);
					format(string, sizeof(string), "[INFO:] Kredyt przyznany, iloœæ rat: 42, kwota sp³aty pojedynczej raty: $%d, ca³kowita kwota do sp³aty: $%d",
						gPlayerData[playerid][mCreditRepayment], gPlayerData[playerid][mCreditValue]);
				}
			}
		}
	}
	
	if(!strlen(string))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /wezkredyt [id kredytu] [czas sp³aty]");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] id kredytu: [1 - 5 000$] , [2 - 15 000$] , [3 - 25 000$]");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] czas sp³aty: [1 - 1 miesi¹c - 5%%] , [2 - 3 miesi¹ce - 10%%] , [3 - 6 miesiêcy - 15%%]");
	}
	else
	{
		SavePlayerData(playerid, "CreditValue");
		SavePlayerData(playerid, "CreditRepayment");
		
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	}
	return 1;
}		

dcmd_stankredytu(playerid, params[])
{
	#pragma unused params
	if(!IsAtBank(playerid) && gPlayerData[playerid][pAdmin] != 5)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w banku !");
		return 1;
	}
	
	new string[128];
	if(gPlayerData[playerid][mCreditValue])
	{
		format(string, sizeof(string), "[INFO:] Kwota kredytu: $%d, sp³acono: $%d, wysokoœæ raty: $%d",
			gPlayerData[playerid][mCreditValue],
			gPlayerData[playerid][mCreditPayed],
			gPlayerData[playerid][mCreditRepayment]);
	}
	else
		format(string, sizeof(string), "[INFO:] Nie posiadasz ¿adnego kredytu");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	return 1;
}

dcmd_splackredyt(playerid, params[])
{
	if(!IsAtBank(playerid) && gPlayerData[playerid][pAdmin] != 5)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w banku !");
		return 1;
	}
	
	if(!gPlayerData[playerid][mCreditValue])
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz kredytu do sp³acenia");
		return 1;
	}
	
	new value;
	if(sscanf(params, "d", value))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /splackredyt [kwota]");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Po wpisaniu komendy dana kwota zostanie przelana z twojego konta bankowego");
	}
	
	if(value <= 0)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Wartoœæ wp³aty musi byæ wiêksza od 0");
		return 1;
	}
	
	if(value > gPlayerData[playerid][pBank])
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz tyle pieniedzy na koncie !");
		return 1;
	}
	
	gPlayerData[playerid][pBank] -= value;
	gPlayerData[playerid][mCreditPayed] += value;
	
	if(gPlayerData[playerid][mCreditPayed] >= gPlayerData[playerid][mCreditValue])
	{
		gPlayerData[playerid][mCreditValue] = 0;
		gPlayerData[playerid][mCreditRepayment] = 0;
		gPlayerData[playerid][mCreditPayed] = 0;
		
		SavePlayerData(playerid, "CreditValue");
		SavePlayerData(playerid, "CreditRepayment");
		
		SendClientMessage(playerid, COLOR_GREEN, "[INFO:] Kredyt zosta³ ca³kowicie sp³acony");
	}
	else
	{
		new string[128];
		format(string, sizeof(string), "[INFO:] Dokonano sp³aty kredytu w wysokoœci: $%d, pozosta³o do sp³aty: $%d",
			value, gPlayerData[playerid][mCreditValue] - gPlayerData[playerid][mCreditPayed]);
		
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	}
	
	SavePlayerData(playerid, "CreditPayed");
	
	return 1;
}

dcmd_payoffgrant(playerid, params[])
{
	new fId, value;
	if(sscanf(params, "dd", fId, value))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "/payoffgrant [fId] [0/1]");
		return 1;
	}
	DynamicFactions[fId][mPayOffGranted] = value;
	if(value)
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] PayOff has been granted");
	else
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] PayOff has been banned");
	return 1;
}

dcmd_zglosproblem(playerid, params[])
{
	#pragma unused params
	if(gPlayerVars[playerid][mBugInfoCoolDown] && gPlayerData[playerid][pAdmin] == 0)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Musisz jeszcze poczekaæ zanim zg³osisz kolejny problem");
		return 1;
	}
	ShowPlayerDialog(playerid, DIALOG_REPORT_PROBLEM, DIALOG_STYLE_INPUT, "Okno dialogowe zg³aszania problemów",
		"Witaj w narzêdziu umo¿liwiaj¹cy zg³oszenie problemów.\n\n\nPodaj w krótkiej formie opis problemu.", "Dalej", "Anuluj");
	return 1;
}

dcmd_zac(playerid, params[])
{
	dcmd_zaciagnij(playerid, params);
	return 1;
}

dcmd_zaciagnij(playerid, params[])
{
	if(gPlayerData[playerid][pFaction] == 255)
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie nale¿ysz do ¿adnej frakcji !");
		return 1;
	}
	if(DynamicFactions[gPlayerData[playerid][pFaction]][fType] != FACTIONT_POLICE)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ policjantem !");
		return 1;
	}
	new giveplayerid, vehicleId;
	if(sscanf(params, "u", giveplayerid))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] [/zac]iagnij [playerid]");
		return 1;
	}
	if(!IsPlayerConnected(giveplayerid))
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ten gracz nie jest online");
		return 1;
	}
	vehicleId = GetPlayerVehicleID(playerid);
	if(vehicleId == 0)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w radiowozie !");
		return 1;
	}
	if(gVehData[vehicleId-1][mVehFaction] == 255)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w radiowozie !");
		return 1;
	}
	if(DynamicFactions[gVehData[vehicleId-1][mVehFaction]][fType] != FACTIONT_POLICE)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w radiowozie !");
		return 1;
	}
	if(gVehData[vehicleId-1][mVehModel] != 596 &&
		gVehData[vehicleId-1][mVehModel] != 597 &&
		gVehData[vehicleId-1][mVehModel] != 598 &&
		gVehData[vehicleId-1][mVehModel] != 596 &&
		gVehData[vehicleId-1][mVehModel] != 490 &&
		gVehData[vehicleId-1][mVehModel] != 427 &&
		gVehData[vehicleId-1][mVehModel] != 560 &&
		gVehData[vehicleId-1][mVehModel] != 482)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ten pojazd nie jest przystosowany do przewo¿enia podejrzanych");
		return 1;
	}
	GetPlayerPos(giveplayerid, gPlayerData[giveplayerid][pCrashX], gPlayerData[giveplayerid][pCrashY], gPlayerData[giveplayerid][pCrashZ]);
	if(!PlayerToPoint(5.0, playerid,gPlayerData[giveplayerid][pCrashX], gPlayerData[giveplayerid][pCrashY], gPlayerData[giveplayerid][pCrashZ]))
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ta osoba jest za daleko od ciebie");
		return 1;
	}
	if(PutPlayerIntoVehicle(giveplayerid, vehicleId, 2) == 0)
	{
		if(PutPlayerIntoVehicle(giveplayerid, vehicleId, 3) == 0)
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie ma miejsca w tym pojeŸdzie !");
			return 1;
		}
	}
	new string[128];
	format(string, sizeof(string), "* %s zaci¹gn¹³ %s do swojego pojazdu", GetPlayerNameEx(playerid), GetPlayerNameEx(giveplayerid));
	ProxDetector(25.0, playerid, string, COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE);
	return 1;
}

dcmd_nonewbie(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] != 1)
		return 0;
	if(nonewbie)
	{
		nonewbie = 0;
		ABroadCast(COLOR_YELLOW, "[INFO:] Newbie chat OFF", 1);
	}
	else
	{
		nonewbie = 1;
		ABroadCast(COLOR_YELLOW, "[INFO:] Newbie chat ON", 1);
	}
	return 1;
}

dcmd_n(playerid, params[])
{
	dcmd_newbie(playerid, params);
	return 1;
}

dcmd_newbie(playerid, params[])
{
	if(gPlayerData[playerid][pMuted])
	{
		SendClientMessage(playerid, COLOR_GREY, "[INFO:] Jestes uciszony, nie mo¿esz u¿ywaæ tego chatu");
		return 1;
	}
	if(nonewbie && gPlayerData[playerid][pAdmin] == 0 && gPlayerData[playerid][pModerator] == 0)
	{
		SendClientMessage(playerid, COLOR_GRAD2, "[INFO:] Chat dla newbie jest WY£ACZONY !");
		return 1;
	}
	if(gPlayerVars[playerid][mNewbieCoolDown] && gPlayerData[playerid][pModerator] == 0 && gPlayerData[playerid][pAdmin] == 0)
	{
		SendClientMessage(playerid, COLOR_GREY, "[INFO:] Musisz odczekaæ 50 sekund zanim bêdziesz móg³ wys³aæ kolejn¹ wiadomoœæ !");
		return 1;
	}
	new string[128];
	if(sscanf(params, "s[128]", string))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] [/n]ewbie [treœæ]");
		return 1;
	}	
	if(gPlayerData[playerid][pAdmin] >= 5)
	{
		format(string, sizeof(string), "[NOOC][%d][Head Admin %s]: %s", playerid, gPlayerData[playerid][pOOCName], string);
	}
	else if(gPlayerData[playerid][pAdmin] > 0 && gPlayerData[playerid][pAdmin] < 5)
	{
		format(string, sizeof(string), "[NOOC][%d][Administrator %s]: %s", playerid, gPlayerData[playerid][pOOCName], string);
	}
	else if(gPlayerData[playerid][pModerator] && gPlayerData[playerid][pAdmin] == 0)
	{
		format(string, sizeof(string), "[NOOC][%d][Supporter %s]: %s", playerid, gPlayerData[playerid][pOOCName], string);
	}
	else if(gPlayerData[playerid][pModerator] >= 2 && gPlayerData[playerid][pAdmin] == 0)
	{
		format(string, sizeof(string), "[NOOC][%d][Supporter 2 %s]: %s", playerid, gPlayerData[playerid][pOOCName], string);
	}
	else
	{
		format(string, sizeof(string), "** Newbie %s: %s **", GetPlayerNameEx(playerid), string);
		gPlayerVars[playerid][mNewbieCoolDown] = 50;
	}
	NewbieOff(COLOR_LIGHTGREEN, string);
	printf("%s", string);
	
	return 1;
}

dcmd_setvehpos(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new vehId;
	if(sscanf(params, "dfff", vehId, gVehData[vehId-1][mVehX], gVehData[vehId-1][mVehY], gVehData[vehId-1][mVehZ]))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /setvehpos [vehid] [x] [y] [z]");
		return 1;
	}
	SetVehicleToPos(vehId, gVehData[vehId-1][mVehX], gVehData[vehId-1][mVehY], gVehData[vehId-1][mVehZ]);
	return 1;
}

// TODO: /abuildingdata

dcmd_oddajkluczykipoj(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] == 0)
		return 0;
	
	new givePlayerId, vehId;
	if(sscanf(params, "dd", givePlayerId, vehId))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /oddajkluczykipoj [id gracza] [id pojazdu]");
		return 1;
	}
	
	new slot = InsertPlayerItem(givePlayerId, 2, gVehData[vehId-1][CarSerial], 0, 0);
	if(slot == 0)
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Player has no space in inventory !");
		return 1;
	}
	
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Oddano kluczyki.");
	return 1;
}

dcmd_changestacyjka(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] == 0)
		return 0;
	
	new vehId, status;
	
	if(sscanf(params, "dd", vehId, status))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /changestacyjka [id pojazdu] [0/1]");
		return 1;
	}
	
	gVehData[vehId-1][mVehIgnitionDamaged] = status;
	SaveVehData(vehId-1, "VehIgnitionDamaged");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Stacyjka changed ");
	return 1;
}

dcmd_opuscprzymierzalnie(playerid, params[])
{
	#pragma unused params
	gPlayerVars[playerid][mAtClotheStore] = false;
	
	PlayerTextDrawHide(playerid, gPlayerVars[playerid][mWardrobeExitText]);
	
	SetPlayerToBiz(playerid, gPlayerVars[playerid][mAtBizID]);
	SetPlayerSkinEx(playerid, gPlayerData[playerid][pSkin]);
	SetCameraBehindPlayer(playerid);
	return 1;
}

dcmd_ahousestreetno(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	
	new hId, no;
	
	if(sscanf(params, "dd", hId, no))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /ahousestreetno [id domu] [numer]");
		return 1;
	}
	
	Houses[hId][StreetNo] = no;
	SaveHouseData(hId, "StreetNo");
	
	RefreshHouseDescription(hId);
	
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] House number changed");
	return 1;
}

dcmd_nrbudynku(playerid, params[])
{
	if(gPlayerData[playerid][pFaction] != FACTIONID_GOVERNMENT)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ urzêdnikiem");
		return 1;
	}
	
	new no;
	
	if(sscanf(params, "d", no))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /nrbudynku [numer]");
		return 1;
	}
	
	for(new i = 0; i < sizeof(Houses); i++)
	{
		if(!PlayerToPoint(1.0, playerid, Houses[i][EnterX], Houses[i][EnterY], Houses[i][EnterZ]))
		{
			continue;
		}
		
		Houses[i][StreetNo] = no;
		SaveHouseData(i, "StreetNo");
		
		RefreshHouseDescription(i);
		
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Numer budynku zmieniony");
		
		return 1;
	}
	
	for(new bId = 0; bId < sizeof(Building); bId++)
	{
		if(!PlayerToPoint(1.0, playerid, Building[bId][EnterX], Building[bId][EnterY], Building[bId][EnterZ]))
		{
			continue;
		}
		
		Building[bId][StreetNo] = no;
		SaveBData(bId, "StreetNo");
		
		RefreshBuildingDescription(bId);
		
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Numer budynku zmieniony");
		
		return 1;
	}
	
	for(new bizId = 0; bizId < sizeof(Businesses); bizId++)
	{
		if(!PlayerToPoint(1.0, playerid, Businesses[bizId][EnterX], Businesses[bizId][EnterY], Businesses[bizId][EnterZ]))
		{
			continue;
		}
		
		Businesses[bizId][StreetNo] = no;
		SaveBizData(bizId, "StreetNo");
		
		RefreshBizDescription(bizId);
		
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Numer budynku zmieniony");
		
		return 1;
	}
	
	SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Brak budynku w okolicy");
	
	return 1;
}

dcmd_abizstreetno(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	
	new bizId, no;
	
	if(sscanf(params, "dd", bizId, no))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /abizstreetno [id biznesu] [numer]");
		return 1;
	}
	
	Businesses[bizId][StreetNo] = no;
	SaveBizData(bizId, "StreetNo");
	
	RefreshBizDescription(bizId);
	
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Business number changed");
	return 1;
}

dcmd_abuildingstreetno(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	
	new bId, no;
	
	if(sscanf(params, "dd", bId, no))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /abuildingstreetno [id budynki] [numer]");
		return 1;
	}
	
	Building[bId][StreetNo] = no;
	SaveBData(bId, "StreetNo");
	
	RefreshBuildingDescription(bId);
	
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Building number changed");
	return 1;
}

// TODO: opodatkowaæ
dcmd_kupbudynek(playerid, params[])
{
	#pragma unused params
	
	for(new bId = 0; bId < sizeof(Building); bId++)
	{
		if(!PlayerToPoint(2.0, playerid, Building[bId][EnterX], Building[bId][EnterY], Building[bId][EnterZ]))
			continue;
		
		if((Building[bId][FactionOwnerId] != -1 && Building[bId][ForSale] == 0) || Building[bId][Price] == 0)
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ten budynek nie jest na sprzeda¿");
			return 1;
		}
		
		if(gPlayerData[playerid][pBank] < Building[bId][Price])
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie masz wystarczaj¹cej iloœci pieniêdzy");
			return 1;
		}
		
		gPlayerVars[playerid][mBuildingBuyId] = bId;
		
		ShowPlayerDialog(playerid, DIALOG_BUY_BUILDING, DIALOG_STYLE_LIST, "Kup budynek", "Kup budynek na frakcje\nKup budynek na firme", "Kup", "Anuluj");
		
		return 1;
	}
	
	SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ przy ¿adnym budynku");
	
	return 1;
}

dcmd_swplac(playerid, params[])
{
	if(gPlayerData[playerid][pFaction] == 255)
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie przynale¿ysz do ¿adnej frakcji");
		return 1;
	}
	
	new cashDeposit, string[128];
	
	if(sscanf(params, "d", cashDeposit))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /swplac [kwota]");
		return 1;
	}

	if(cashDeposit <= 0)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Kwota musi byæ wiêksza od 0");
		return 1;
	}
	
	if(GetPlayerCash(playerid) < cashDeposit)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz tylu pieniêdzy");
		return 1;
	}
	
	if(gPlayerData[playerid][pRank] != 1)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ za³o¿ycielem frakcji");
		return 1;
	}
	
	for(new i = 0; i < sizeof(DynamicFactions); i++)
	{
		if(!IsPlayerInDynamicCP(playerid, DynamicFactions[i][WFactoryCPSafeID]))
		{
			continue;
		}
		
		if(gPlayerData[playerid][pFaction] != i)
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie przynale¿ysz do tej frakcji !");
			return 1;
		}
		
		DynamicFactions[i][fBank] += cashDeposit;		
		SaveFData(i, "Bank");
		
		GivePlayerCash(playerid, -cashDeposit);
		
		format(string, sizeof(string), "[INFO:] Wp³aci³eœ do sejfu $%d, ³¹czna suma pieniêdzy to $%d", cashDeposit, DynamicFactions[i][fBank]);
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	}
	
	SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie znajdujesz siê przy sejfie");
	return 1;
}

dcmd_swyplac(playerid, params[])
{
	if(gPlayerData[playerid][pFaction] == 255)
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie przynale¿ysz do ¿adnej frakcji");
		return 1;
	}
	
	new cashDeposit, string[128];
	
	if(sscanf(params, "d", cashDeposit))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /swyplac [kwota]");
		return 1;
	}

	if(cashDeposit <= 0)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Kwota musi byæ wiêksza od 0");
		return 1;
	}
	
	if(gPlayerData[playerid][pRank] != 1)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ za³o¿ycielem frakcji");
		return 1;
	}
	
	for(new i = 0; i < sizeof(DynamicFactions); i++)
	{
		if(!IsPlayerInDynamicCP(playerid, DynamicFactions[i][WFactoryCPSafeID]))
		{
			continue;
		}
		
		if(gPlayerData[playerid][pFaction] != i)
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie przynale¿ysz do tej frakcji !");
			return 1;
		}
		
		if(DynamicFactions[i][fBank] < cashDeposit)
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz tylu pieniêdzy w sejfie");
			return 1;
		}
		
		DynamicFactions[i][fBank] -= cashDeposit;		
		SaveFData(i, "Bank");
		
		GivePlayerCash(playerid, cashDeposit);
		
		format(string, sizeof(string), "[INFO:] Wyp³aci³eœ z sejfu $%d, ³¹czna suma pieniêdzy to $%d", cashDeposit, DynamicFactions[i][fBank]);
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	}
	
	SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie znajdujesz siê przy sejfie");
	return 1;
}

dcmd_sstan(playerid, params[])
{
	#pragma unused params
	
	if(gPlayerData[playerid][pFaction] == 255)
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie przynale¿ysz do ¿adnej frakcji");
		return 1;
	}
	
	new string[128];
	
	for(new i = 0; i < sizeof(DynamicFactions); i++)
	{
		if(!IsPlayerInDynamicCP(playerid, DynamicFactions[i][WFactoryCPSafeID]))
		{
			continue;
		}
		
		if(gPlayerData[playerid][pFaction] != i)
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie przynale¿ysz do tej frakcji !");
			return 1;
		}
		
		format(string, sizeof(string), "[INFO:] £¹czna suma pieniêdzy to $%d", DynamicFactions[i][fBank]);
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	}
	
	SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie znajdujesz siê przy sejfie");
	return 1;
}

dcmd_fwplac(playerid, params[])
{
	if(gPlayerData[playerid][pFaction] == 255)
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie przynale¿ysz do ¿adnej frakcji");
		return 1;
	}
	
	new cashDeposit, string[128];
	
	if(sscanf(params, "d", cashDeposit))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /fwplac [kwota]");
		return 1;
	}
	
	if(cashDeposit <= 0)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Kwota musi byæ wiêksza od 0");
		return 1;
	}
	
	if(GetPlayerCash(playerid) < cashDeposit)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz tylu pieniêdzy");
		return 1;
	}
	
	if(DynamicFactions[gPlayerData[playerid][pFaction]][fType] != FACTIONT_GANG)
	{
		if(!IsAtBank(playerid))
		{				
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ w banku !");
			return 1;
		}
		
		DynamicFactions[gPlayerData[playerid][pFaction]][fBank] += cashDeposit;		
		SaveFData(gPlayerData[playerid][pFaction], "Bank");
		
		format(string, sizeof(string), "[CASH:] Player: %s, donate: $%d, to faction id: %d", gPlayerData[playerid][pName], cashDeposit, gPlayerData[playerid][pFaction]);
		PayLog(string);
		
		format(string, sizeof(string), "[INFO:] Wp³aci³eœ $%d na konto frakcji, nowy stan: $%d", cashDeposit,DynamicFactions[gPlayerData[playerid][pFaction]][fBank]);
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	}
	else
	{
		if(gPlayerVars[playerid][mAtBuildingId] == -1)
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w swojej kryjówce");
			return 1;
		}
		
		if(Building[gPlayerVars[playerid][mAtBuildingId]][FactionOwnerId] != gPlayerData[playerid][pFaction])
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] To nie jest twoja kryjówka");
			return 1;
		}
		
		Building[gPlayerVars[playerid][mAtBuildingId]][Cash] += cashDeposit;
		SaveBData(gPlayerVars[playerid][mAtBuildingId], "Cash");
		
		format(string, sizeof(string), "[INFO:] Wp³aci³eœ $%d do sejfu, nowy stan: $%d", cashDeposit, Building[gPlayerVars[playerid][mAtBuildingId]][Cash]);
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	}

	
	ApplyAnimation(playerid, "DEALER", "shop_pay", 4.1, 0, 0, 0, 0, 0);
	GivePlayerCash(playerid, -cashDeposit);
	
	return 1;
}

dcmd_fstankonta(playerid, params[])
{
	#pragma unused params
	
	new string[128];
	
	if(gPlayerData[playerid][pFaction] == 255)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie przynale¿ysz do ¿adnej frakcji");
		return 1;
	}

	if(!CheckRankPrivilidges(gPlayerData[playerid][pFaction], gPlayerData[playerid][pRank], "fstankonta"))
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie posiadasz uprawnieñ do sprawdzenie stanu konta frakcji");
		return 1;
	}
	
	if(DynamicFactions[gPlayerData[playerid][pFaction]][fType] != FACTIONT_GANG)
	{
		if(!IsAtBank(playerid) && !IsAtAtm(playerid))
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] ¯eby sprawdziæ stan konta musisz znajdowaæ siê w banku lub przy automacie");
			return 1;
		}
		
		format(string, sizeof(string), "Stan konta frakcji: $%d", DynamicFactions[gPlayerData[playerid][pFaction]][fBank]);
	}
	else
	{
		if(gPlayerVars[playerid][mAtBuildingId] == -1)
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w swojej kryjówce");
			return 1;
		}
		
		if(Building[gPlayerVars[playerid][mAtBuildingId]][FactionOwnerId] != gPlayerData[playerid][pFaction])
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w swojej kryjówce");
			return 1;
		}
		
		format(string, sizeof(string), "W sejfie znajduje siê $%d", Building[gPlayerVars[playerid][mAtBuildingId]][Cash]);
	}
	
	ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", string, "Zamknij", "");
	
	return 1;
}

dcmd_abuildingprice(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	
	new bId, price;
	
	if(sscanf(params, "dd", bId, price))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /abuildingprice [bId] [price]");
		return 1;
	}
	
	Building[bId][Price] = price;
	SaveBData(bId, "Price");
	
	RefreshBuildingDescription(bId);	
	
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Cena budynku zosta³a zmieniona");
	return 1;
}

dcmd_abuildingtype(playerid, params[])
{
	new bId, type;
	
	if(sscanf(params, "dd", bId, type))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /abuildingtype [bId] [type]");
		return 1;
	}
	
	Building[bId][BuildingType] = type;
	SaveBData(bId, "BuildingType");
	
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Building type changed");

	return 1;
}

dcmd_abuildingdata(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] == 0)
		return 0;
		
	new bId, string[512];
	
	if(sscanf(params, "d", bId))
	{
		if(gPlayerVars[playerid][mAtBuildingId] != -1)
		{
			format(string, sizeof(string), "Budynek id %d\nNazwa: \"%s\"\nNumer: %d\nCena: $%d\nNa sprzeda¿: %d\nPozycja: %.3f; %.3f; %.3f\nWejœciówka: $%d\nZamkniêty: %d\nOtwarcie (godzina): %d\nZamkniêcie (godzina): %d\nTyp budynku (id typu): %d\nID w³aœciciela (frakcja, -1 jeœli brak): %d",
				gPlayerVars[playerid][mAtBuildingId],
				Building[gPlayerVars[playerid][mAtBuildingId]][BuildingName],
				Building[gPlayerVars[playerid][mAtBuildingId]][StreetNo],
				Building[gPlayerVars[playerid][mAtBuildingId]][Price],
				Building[gPlayerVars[playerid][mAtBuildingId]][ForSale],
				Building[gPlayerVars[playerid][mAtBuildingId]][EnterX],
				Building[gPlayerVars[playerid][mAtBuildingId]][EnterY],
				Building[gPlayerVars[playerid][mAtBuildingId]][EnterZ],
				Building[gPlayerVars[playerid][mAtBuildingId]][EntranceFee],
				Building[gPlayerVars[playerid][mAtBuildingId]][Locked],
				Building[gPlayerVars[playerid][mAtBuildingId]][Opened],
				Building[gPlayerVars[playerid][mAtBuildingId]][Closed],
				Building[gPlayerVars[playerid][mAtBuildingId]][BuildingType],
				Building[gPlayerVars[playerid][mAtBuildingId]][FactionOwnerId]);
			ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", string, "Zamknij", "");
			return 1;
		}
				
		for(bId = 0; bId < sizeof(Building); bId++)
		{
			if(!PlayerToPoint(2.0, playerid, Building[bId][EnterX], Building[bId][EnterY], Building[bId][EnterZ]))
			{
				continue;
			}
			
			format(string, sizeof(string), "Budynek id %d\nNazwa: \"%s\"\nNumer: %d\nCena: $%d\nNa sprzeda¿: %d\nPozycja: %.3f; %.3f; %.3f\nWejœciówka: $%d\nZamkniêty: %d\nOtwarcie (godzina): %d\nZamkniêcie (godzina): %d\nTyp budynku (id typu): %d\nID w³aœciciela (frakcja, -1 jeœli brak): %d",
				bId,
				Building[bId][BuildingName],
				Building[bId][StreetNo],
				Building[bId][Price],
				Building[bId][ForSale],
				Building[bId][EnterX],
				Building[bId][EnterY],
				Building[bId][EnterZ],
				Building[bId][EntranceFee],
				Building[bId][Locked],
				Building[bId][Opened],
				Building[bId][Closed],
				Building[bId][BuildingType],
				Building[bId][FactionOwnerId]);
			ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", string, "Zamknij", "");
			
			return 1;
		}
		
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Podaj id budynku lub przejdŸ do budynku");
		return 1;
	}
	
	if(bId < 0 || bId >= sizeof(Building))
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Niepoprawne id budynku");
		return 1;
	}
	
	format(string, sizeof(string), "Budynek id %d\nNazwa: \"%s\"\nNumer: %d\nCena: $%d\nNa sprzeda¿: %d\nPozycja: %.3f; %.3f; %.3f\nWejœciówka: $%d\nZamkniêty: %d\nOtwarcie (godzina): %d\nZamkniêcie (godzina): %d\nTyp budynku (id typu): %d\nID w³aœciciela (frakcja, -1 jeœli brak): %d",
		bId,
		Building[bId][BuildingName],
		Building[bId][StreetNo],
		Building[bId][Price],
		Building[bId][ForSale],
		Building[bId][EnterX],
		Building[bId][EnterY],
		Building[bId][EnterZ],
		Building[bId][EntranceFee],
		Building[bId][Locked],
		Building[bId][Opened],
		Building[bId][Closed],
		Building[bId][BuildingType],
		Building[bId][FactionOwnerId]);
	ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", string, "Zamknij", "");

	return 1;
}

dcmd_wynagrodzenie(playerid, params[])
{
	#pragma unused params
	
	if(gPlayerData[playerid][pFaction] == 255)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie przynale¿ysz do ¿adnej frakcji");
		return 1;
	}
	
	if(gPlayerData[playerid][pRank] != 1)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ liderem frakcji");
		return 1;
	}
	
	if(DynamicFactions[gPlayerData[playerid][pFaction]][fType] == FACTIONT_GANG)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ta komenda nie jest dostêpna dla gangu");
		return 1;
	}
	
	new string[1024];
	format(string, sizeof(string), "1. Ranga 1 - %s", DynamicFactions[gPlayerData[playerid][pFaction]][fRank1]);
	if(DynamicFactions[gPlayerData[playerid][pFaction]][fRankAmount] >= 2)
	{
		format(string, sizeof(string), "%s\n2. Ranga 2 - %s", string, DynamicFactions[gPlayerData[playerid][pFaction]][fRank2]);
	}
	if(DynamicFactions[gPlayerData[playerid][pFaction]][fRankAmount] >= 3)
	{
		format(string, sizeof(string), "%s\n3. Ranga 3 - %s", string, DynamicFactions[gPlayerData[playerid][pFaction]][fRank3]);
	}
	if(DynamicFactions[gPlayerData[playerid][pFaction]][fRankAmount] >= 4)
	{
		format(string, sizeof(string), "%s\n4. Ranga 4 - %s", string, DynamicFactions[gPlayerData[playerid][pFaction]][fRank4]);
	}
	if(DynamicFactions[gPlayerData[playerid][pFaction]][fRankAmount] >= 5)
	{
		format(string, sizeof(string), "%s\n5. Ranga 5 - %s", string, DynamicFactions[gPlayerData[playerid][pFaction]][fRank5]);
	}
	if(DynamicFactions[gPlayerData[playerid][pFaction]][fRankAmount] >= 6)
	{
		format(string, sizeof(string), "%s\n6. Ranga 6 - %s", string, DynamicFactions[gPlayerData[playerid][pFaction]][fRank6]);
	}
	if(DynamicFactions[gPlayerData[playerid][pFaction]][fRankAmount] >= 7)
	{
		format(string, sizeof(string), "%s\n7. Ranga 7 - %s", string, DynamicFactions[gPlayerData[playerid][pFaction]][fRank7]);
	}
	if(DynamicFactions[gPlayerData[playerid][pFaction]][fRankAmount] >= 8)
	{
		format(string, sizeof(string), "%s\n8. Ranga 8 - %s", string, DynamicFactions[gPlayerData[playerid][pFaction]][fRank8]);
	}
	if(DynamicFactions[gPlayerData[playerid][pFaction]][fRankAmount] >= 9)
	{
		format(string, sizeof(string), "%s\n9. Ranga 9 - %s", string, DynamicFactions[gPlayerData[playerid][pFaction]][fRank9]);
	}
	if(DynamicFactions[gPlayerData[playerid][pFaction]][fRankAmount] >= 10)
	{
		format(string, sizeof(string), "%s\n10. Ranga 10 - %s", string, DynamicFactions[gPlayerData[playerid][pFaction]][fRank10]);
	}
	ShowPlayerDialog(playerid, DIALOG_F_PAYMENT_1, DIALOG_STYLE_LIST, "Wybierz range któr¹ chcesz edytowaæ", string, "Wybierz", "Zamknij");
	return 1;
}

dcmd_uzbrojenie(playerid, params[])
{
	#pragma unused params
	
	if(gPlayerData[playerid][pFaction] == 255)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie przynale¿ysz do ¿adnej frakcji");
		return 1;
	}
	
	if(gPlayerData[playerid][pRank] != 1)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ liderem frakcji");
		return 1;
	}
	
	new string[1024];
	format(string, sizeof(string), "1. Ranga 1 - %s", DynamicFactions[gPlayerData[playerid][pFaction]][fRank1]);
	if(DynamicFactions[gPlayerData[playerid][pFaction]][fRankAmount] >= 2)
	{
		format(string, sizeof(string), "%s\n2. Ranga 2 - %s", string, DynamicFactions[gPlayerData[playerid][pFaction]][fRank2]);
	}
	if(DynamicFactions[gPlayerData[playerid][pFaction]][fRankAmount] >= 3)
	{
		format(string, sizeof(string), "%s\n3. Ranga 3 - %s", string, DynamicFactions[gPlayerData[playerid][pFaction]][fRank3]);
	}
	if(DynamicFactions[gPlayerData[playerid][pFaction]][fRankAmount] >= 4)
	{
		format(string, sizeof(string), "%s\n4. Ranga 4 - %s", string, DynamicFactions[gPlayerData[playerid][pFaction]][fRank4]);
	}
	if(DynamicFactions[gPlayerData[playerid][pFaction]][fRankAmount] >= 5)
	{
		format(string, sizeof(string), "%s\n5. Ranga 5 - %s", string, DynamicFactions[gPlayerData[playerid][pFaction]][fRank5]);
	}
	if(DynamicFactions[gPlayerData[playerid][pFaction]][fRankAmount] >= 6)
	{
		format(string, sizeof(string), "%s\n6. Ranga 6 - %s", string, DynamicFactions[gPlayerData[playerid][pFaction]][fRank6]);
	}
	if(DynamicFactions[gPlayerData[playerid][pFaction]][fRankAmount] >= 7)
	{
		format(string, sizeof(string), "%s\n7. Ranga 7 - %s", string, DynamicFactions[gPlayerData[playerid][pFaction]][fRank7]);
	}
	if(DynamicFactions[gPlayerData[playerid][pFaction]][fRankAmount] >= 8)
	{
		format(string, sizeof(string), "%s\n8. Ranga 8 - %s", string, DynamicFactions[gPlayerData[playerid][pFaction]][fRank8]);
	}
	if(DynamicFactions[gPlayerData[playerid][pFaction]][fRankAmount] >= 9)
	{
		format(string, sizeof(string), "%s\n9. Ranga 9 - %s", string, DynamicFactions[gPlayerData[playerid][pFaction]][fRank9]);
	}
	if(DynamicFactions[gPlayerData[playerid][pFaction]][fRankAmount] >= 10)
	{
		format(string, sizeof(string), "%s\n10. Ranga 10 - %s", string, DynamicFactions[gPlayerData[playerid][pFaction]][fRank10]);
	}
	ShowPlayerDialog(playerid, DIALOG_F_ARMENT_1, DIALOG_STYLE_LIST, "Wybierz range któr¹ chcesz edytowaæ", string, "Wybierz", "Zamknij");
	return 1;
}

dcmd_stanuzbrojenia(playerid, params[])
{
	#pragma unused params
	
	if(gPlayerData[playerid][pFaction] == 255)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie przynale¿ysz do ¿adnej frakcji");
		return 1;
	}
	
	if(gPlayerData[playerid][pRank] != 1)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ liderem frakcji");
		return 1;
	}
	
	new string[1024];
	
	format(string, sizeof(string),
		"Pistolet 9MM: %d\nPistol 9MM z t³umikiem: %d\nDesert Eagle: %d\nUZI: %d\nMP5: %d\nTec-9: %d\nShotgun: %d\nAK-47: %d\nM4: %d\nSnajperka: %d\n",
		DynamicFactions[gPlayerData[playerid][pFaction]][WFactory9MM],
		DynamicFactions[gPlayerData[playerid][pFaction]][WFactory9MMSil],
		DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryDesEagle],
		DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryMicroSMG],
		DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryMP5],
		DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryTec9],
		DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryShotgun],
		DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryAK47],
		DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryM4],
		DynamicFactions[gPlayerData[playerid][pFaction]][WFactorySRifle]);
	
	format(string, sizeof(string),
		"%s\nDostêpna amunicja\n9MM: %d\n50AE: %d\nBuckshot: %d\n7.62MM: %d\n12.7MM: %d",
		string,
		DynamicFactions[gPlayerData[playerid][pFaction]][WFactory9MMAmmo],
		DynamicFactions[gPlayerData[playerid][pFaction]][WFactory50AEAmmo],
		DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryBuckshot],
		DynamicFactions[gPlayerData[playerid][pFaction]][WFactory762MMAmmo],
		DynamicFactions[gPlayerData[playerid][pFaction]][WFactory127MMAmmo]);
	
	ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Magazyn", string, "Zamknij", "");
	return 1;
}

dcmd_resetbuilding(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
		
	new bId;
	
	if(sscanf(params, "d", bId))
	{
		if(gPlayerVars[playerid][mAtBuildingId] != -1)
		{
			ResetBuildingData(gPlayerVars[playerid][mAtBuildingId]);
			
			return 1;
		}
		
		for(bId = 0; bId < sizeof(Building); bId++)
		{
			if(!PlayerToPoint(2.0, playerid, Building[bId][EnterX], Building[bId][EnterY], Building[bId][EnterZ]))
			{
				continue;
			}
			
			ResetBuildingData(bId);
			
			return 1;
		}
		
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Podaj id budynku lub przejdŸ do budynku");
		return 1;
	}
	
	if(bId < 0 || bId >= sizeof(Building))
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Niepoprawne id budynku");
		return 1;
	}

	ResetBuildingData(bId);
	
	return 1;
}

dcmd_sprzedajbudynek(playerid, params[])
{
	#pragma unused params
	
	if(gPlayerData[playerid][pFaction] == 255)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie przynale¿ysz do ¿adnej frakcji");
		return 1;
	}
	
	if(gPlayerData[playerid][pRank] != 1)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ liderem ¿adnej frakcji");
		return 1;
	}
	
	new bId, string[128];
	
	if(gPlayerVars[playerid][mAtBuildingId] != -1)
	{
		if(Building[gPlayerVars[playerid][mAtBuildingId]][FactionOwnerId] != gPlayerData[playerid][pFaction])
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ten budynek nie nale¿y do twojej frakcji");
			return 1;
		}
		
		gPlayerData[playerid][pBank] += Building[gPlayerVars[playerid][mAtBuildingId]][Cash] + floatround(Building[gPlayerVars[playerid][mAtBuildingId]][Price]*0.80);
		
		DynamicFactions[FACTIONID_GOVERNMENT][fBank] -= floatround(Building[gPlayerVars[playerid][mAtBuildingId]][Price]*0.80);
		SaveFData(FACTIONID_GOVERNMENT, "Bank");
		
		format(string, sizeof(string), "Uzyska³eœ %d ze sprzeda¿y budynku", floatround(Building[gPlayerVars[playerid][mAtBuildingId]][Price]*0.80));
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", string, "Zamknij", "");
		
		ResetBuildingData(gPlayerVars[playerid][mAtBuildingId]);
		
		return 1;
	}
		
	for(bId = 0; bId < sizeof(Building); bId++)
	{
		if(!PlayerToPoint(2.0, playerid, Building[bId][EnterX], Building[bId][EnterY], Building[bId][EnterZ]))
		{
			continue;
		}
		
		if(Building[bId][FactionOwnerId] != gPlayerData[playerid][pFaction])
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ten budynek nie nale¿y do twojej frakcji");
			return 1;
		}
		
		gPlayerData[playerid][pBank] += Building[bId][Cash] + floatround(Building[bId][Price]*0.80);
		
		DynamicFactions[FACTIONID_GOVERNMENT][fBank] -= floatround(Building[bId][Price]*0.80);
		SaveFData(FACTIONID_GOVERNMENT, "Bank");
		
		format(string, sizeof(string), "Uzyska³eœ %d ze sprzeda¿y budynku", floatround(Building[bId][Price]*0.80));
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", string, "Zamknij", "");
		
		ResetBuildingData(bId);
		
		return 1;
	}
	
	SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ przy ¿adnym budynku");
	
	return 1;
}

dcmd_adeletemapicon(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	
	new iconId;
	
	if(sscanf(params, "d", iconId))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /adeletemapicon [iconId]");
		return 1;
	}
	
	if(gMapIcon[iconId][mIconId])
	{
		DestroyDynamicMapIcon(gMapIcon[iconId][mIconId]);
	}
	
	gMapIcon[iconId][mPosX] = 0;
	gMapIcon[iconId][mPosY] = 0;
	gMapIcon[iconId][mPosZ] = 0;
	
	SaveMapIconData(iconId, "Pos");
	
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Icon has been deleted");
	return 1;
}
	
dcmd_asetmapicon(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	
	new iconId = -1, type = -1, color = 0, world = -1, interior = -1, streamDistance = 200, Float:posX, Float:posY, Float:posZ;
	
	if(sscanf(params, "dddddd", iconId, type, color, world, interior, streamDistance))
	{
		if(iconId == -1 || type == -1)
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /asetmapicon [iconId] [type] [color] [world] [interior] [streamDistance]");
			return 1;
		}
	}
	
	GetPlayerPos(playerid, posX, posY, posZ);
	
	gMapIcon[iconId][mPosX] = posX;
	gMapIcon[iconId][mPosY] = posY;
	gMapIcon[iconId][mPosZ] = posZ;
	gMapIcon[iconId][mType] = type;
	gMapIcon[iconId][mColor] = color;
	gMapIcon[iconId][mWorld] = world;
	gMapIcon[iconId][mInterior] = interior;
	gMapIcon[iconId][mStreamDistance] = streamDistance;
	
	SaveMapIconData(iconId, "Pos");
	SaveMapIconData(iconId, "Type");
	SaveMapIconData(iconId, "Color");
	SaveMapIconData(iconId, "World");
	SaveMapIconData(iconId, "Interior");
	SaveMapIconData(iconId, "StreamDistance");
	
	gMapIcon[iconId][mIconId] = CreateDynamicMapIcon(posX, posY, posZ, type, color, world, interior, -1, streamDistance);

	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Map icon set");
	
	return 1;
}

dcmd_setpublicad(playerid, params[])
{	
	if(gPlayerData[playerid][pAdmin] != 5)
	{
		return 0;
	}
	
	new adId;
	
	if(sscanf(params, "d", adId))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /setpublicad [adId]");
		return 1;
	}
	
	GetPlayerPos(playerid, gPublicAds[adId][mObjPosX], gPublicAds[adId][mObjPosY], gPublicAds[adId][mObjPosZ]);
	gPublicAds[adId][mObjWorld] = GetPlayerVirtualWorld(playerid);
	
	SavePublicAdsData(adId, "ObjPos");
	
	if(gPublicAds[adId][mObjId])
	{
		DestroyDynamicObject(gPublicAds[adId][mObjId]);
	}
	
	gPublicAds[adId][mObjId] = CreateDynamicObject(3335, gPublicAds[adId][mObjPosX], gPublicAds[adId][mObjPosY], gPublicAds[adId][mObjPosZ], gPublicAds[adId][mObjRotX], gPublicAds[adId][mObjRotY], gPublicAds[adId][mObjRotZ], gPublicAds[adId][mObjWorld]);
	
	defer RefreshPublicAd(adId);
	
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] New public ad placed");
	
	return 1;
}

dcmd_setpublicadcp(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
	{
		return 0;
	}
	
	new adId;
	
	if(sscanf(params, "d", adId))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /setpublicadcp [adId]");
		return 1;
	}
	
	GetPlayerPos(playerid, gPublicAds[adId][mObjPosX], gPublicAds[adId][mObjPosY], gPublicAds[adId][mObjPosZ]);
	gPublicAds[adId][mObjWorld] = GetPlayerVirtualWorld(playerid);
	
	SavePublicAdsData(adId, "CpPos");
	
	if(gPublicAds[adId][mCpId])
	{
		DestroyDynamicCP(gPublicAds[adId][mCpId]);
	}
	
	//gPublicAds[adId][mCpId] = CreateDynamicCP(gPublicAds[adId][mCpPosX], gPublicAds[adId][mCpPosY], gPublicAds[adId][mCpPosZ], 0.5, gPublicAds[adId][mCpWorld], -1, 10.0);

	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Public ad CP set");
	return 1;
}

dcmd_putnewpublicad(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
	{
		return 0;
	}
	
	new adId, adSlot, adContent[65];
	
	if(sscanf(params, "dds[65]", adId, adSlot, adContent))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /putnewpublicad [adId] [adSlot] [adContent[65]]");
		return 1;
	}
	
	switch(adSlot)
	{
		case 0:
		{
			format(gPublicAds[adId][mAdLine1Content], 65, adContent);
			SavePublicAdsData(adId, "AdLine1");
		}
		case 1:
		{
			format(gPublicAds[adId][mAdLine2Content], 65, adContent);
			SavePublicAdsData(adId, "AdLine2");
		}
		case 2:
		{
			format(gPublicAds[adId][mAdLine3Content], 65, adContent);
			SavePublicAdsData(adId, "AdLine3");
		}
		case 3:
		{
			format(gPublicAds[adId][mAdLine4Content], 65, adContent);
			SavePublicAdsData(adId, "AdLine4");
		}
		case 4:
		{
			format(gPublicAds[adId][mAdLine5Content], 65, adContent);
			SavePublicAdsData(adId, "AdLine5");
		}
		case 5:
		{
			format(gPublicAds[adId][mAdLine6Content], 65, adContent);
			SavePublicAdsData(adId, "AdLine6");
		}
		case 6:
		{
			format(gPublicAds[adId][mAdLine7Content], 65, adContent);
			SavePublicAdsData(adId, "AdLine7");
		}
		case 7:
		{
			format(gPublicAds[adId][mAdLine8Content], 65, adContent);
			SavePublicAdsData(adId, "AdLine8");
		}
		case 8:
		{
			format(gPublicAds[adId][mAdLine9Content], 65, adContent);
			SavePublicAdsData(adId, "AdLine9");
		}
		case 9:
		{
			format(gPublicAds[adId][mAdLine10Content], 65, adContent);
			SavePublicAdsData(adId, "AdLine10");
		}
	}
	
	defer RefreshPublicAd(adId);
	
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Add has been changed");
	return 1;
}

dcmd_editpublicad(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
	{
		return 0;
	}
	
	new adId;
	
	if(sscanf(params, "d", adId))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /editpublicad [adId]");
		return 1;
	}
	
	EditDynamicObject(playerid, gPublicAds[adId][mObjId]);
	return 1;
}

dcmd_fillpublicadstable(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new string[128];
	for(new i = 0; i < MAX_PUBLIC_ADS; i++)
	{
		format(string, sizeof(string), "INSERT INTO `samp_public_ads` (`ObjPosX`) VALUES ('0') ");
		wp_mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
	}
	return 1;
}

dcmd_removepublicad(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
	{
		return 0;
	}
	
	new adId, adSlot;
	
	if(sscanf(params, "dd", adId, adSlot))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /removepublicad [adId] [adSlot]");
		return 1;
	}
	
	switch(adSlot)
	{
		case 0:
		{
			format(gPublicAds[adId][mAdLine1Content], 65, "");
			gPublicAds[adId][mAdLine1TimeLeft] = 0;
			SavePublicAdsData(adId, "AdLine1");
		}
		case 1:
		{
			format(gPublicAds[adId][mAdLine2Content], 65, "");
			gPublicAds[adId][mAdLine2TimeLeft] = 0;
			SavePublicAdsData(adId, "AdLine2");
		}
		case 2:
		{
			format(gPublicAds[adId][mAdLine3Content], 65, "");
			gPublicAds[adId][mAdLine3TimeLeft] = 0;
			SavePublicAdsData(adId, "AdLine3");
		}
		case 3:
		{
			format(gPublicAds[adId][mAdLine4Content], 65, "");
			gPublicAds[adId][mAdLine4TimeLeft] = 0;
			SavePublicAdsData(adId, "AdLine4");
		}
		case 4:
		{
			format(gPublicAds[adId][mAdLine5Content], 65, "");
			gPublicAds[adId][mAdLine5TimeLeft] = 0;
			SavePublicAdsData(adId, "AdLine5");
		}
		case 5:
		{
			format(gPublicAds[adId][mAdLine6Content], 65, "");
			gPublicAds[adId][mAdLine6TimeLeft] = 0;
			SavePublicAdsData(adId, "AdLine6");
		}
		case 6:
		{
			format(gPublicAds[adId][mAdLine7Content], 65, "");
			gPublicAds[adId][mAdLine7TimeLeft] = 0;
			SavePublicAdsData(adId, "AdLine7");
		}
		case 7:
		{
			format(gPublicAds[adId][mAdLine8Content], 65, "");
			gPublicAds[adId][mAdLine8TimeLeft] = 0;
			SavePublicAdsData(adId, "AdLine8");
		}
		case 8:
		{
			format(gPublicAds[adId][mAdLine9Content], 65, "");
			gPublicAds[adId][mAdLine9TimeLeft] = 0;
			SavePublicAdsData(adId, "AdLine9");
		}
		case 9:
		{
			format(gPublicAds[adId][mAdLine10Content], 65, "");
			gPublicAds[adId][mAdLine10TimeLeft] = 0;
			SavePublicAdsData(adId, "AdLine10");
		}
	}
	
	defer RefreshPublicAd(adId);
	
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Add has been removed");
	return 1;
}

dcmd_publicadscmds(playerid, params[])
{
	#pragma unused params
	
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /setpublicad - /setpublicadcp - /putnewpublicad - /editpublicad - /setpublicadtime - /removepublicad - /fillpublicadstable");
	return 1;
}

dcmd_setpublicadtime(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
	{
		return 0;
	}
	
	new adId, adSlot, timeLeft;
	
	if(sscanf(params, "ddd", adId, adSlot, timeLeft))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /setpublicadtime [adId] [adSlot] [timeLeft");
		return 1;
	}
	
	switch(adSlot)
	{
		case 0:
		{
			gPublicAds[adId][mAdLine1TimeLeft] = timeLeft;
			SavePublicAdsData(adId, "AdLine1");
		}
		case 1:
		{
			gPublicAds[adId][mAdLine2TimeLeft] = timeLeft;
			SavePublicAdsData(adId, "AdLine2");
		}
		case 2:
		{
			gPublicAds[adId][mAdLine3TimeLeft] = timeLeft;
			SavePublicAdsData(adId, "AdLine3");
		}
		case 3:
		{
			gPublicAds[adId][mAdLine4TimeLeft] = timeLeft;
			SavePublicAdsData(adId, "AdLine4");
		}
		case 4:
		{
			gPublicAds[adId][mAdLine5TimeLeft] = timeLeft;
			SavePublicAdsData(adId, "AdLine5");
		}
		case 5:
		{
			gPublicAds[adId][mAdLine6TimeLeft] = timeLeft;
			SavePublicAdsData(adId, "AdLine6");
		}
		case 6:
		{
			gPublicAds[adId][mAdLine7TimeLeft] = timeLeft;
			SavePublicAdsData(adId, "AdLine7");
		}
		case 7:
		{
			gPublicAds[adId][mAdLine8TimeLeft] = timeLeft;
			SavePublicAdsData(adId, "AdLine8");
		}
		case 8:
		{
			gPublicAds[adId][mAdLine9TimeLeft] = timeLeft;
			SavePublicAdsData(adId, "AdLine9");
		}
		case 9:
		{
			gPublicAds[adId][mAdLine10TimeLeft] = timeLeft;
			SavePublicAdsData(adId, "AdLine10");
		}
	}
	
	defer RefreshPublicAd(adId);
	
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Add time left has been changed");
	return 1;
}

dcmd_edytujogloszenie(playerid, params[])
{
	new adId, content[65];
	
	if(sscanf(params, "ds[65]", adId, content))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /edytujogloszenie [id og³oszenia (1-10)] [treœæ (65 znaków)]");
		return 1;
	}
	
	if(adId < 1 || adId > 10)
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Niepoprawne ID og³oszenia");
		return 1;
	}
	
	for(new i = 0; i < sizeof(gPublicAds); i++)
	{
		if(!PlayerToPoint(2.0, playerid, gPublicAds[i][mObjPosX], gPublicAds[i][mObjPosY], gPublicAds[i][mObjPosZ]))
		{
			continue;
		}
		
		if(strcmp(gPublicAds[i][mOwner], gPlayerData[playerid][pName], false) != 0 || strlen(gPublicAds[i][mOwner]) == 0)
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz edytowaæ og³oszeñ na tej tablicy");
			return 1;
		}
		
		switch(adId)
		{
			case 1:
			{
				format(gPublicAds[i][mAdLine1Content], 65, content);
				format(gPublicAds[i][mAdLine1Owner], MAX_PLAYER_NAME, gPlayerData[playerid][pName]);
				
				gPublicAds[i][mAdLine1TimeLeft] = -1;
				SavePublicAdsData(i, "AdLine1");
			}
			case 2:
			{
				format(gPublicAds[i][mAdLine2Content], 65, content);
				format(gPublicAds[i][mAdLine2Owner], MAX_PLAYER_NAME, gPlayerData[playerid][pName]);
				
				gPublicAds[i][mAdLine2TimeLeft] = -1;
				SavePublicAdsData(i, "AdLine2");
			}
			case 3:
			{
				format(gPublicAds[i][mAdLine3Content], 65, content);
				format(gPublicAds[i][mAdLine3Owner], MAX_PLAYER_NAME, gPlayerData[playerid][pName]);
				
				gPublicAds[i][mAdLine3TimeLeft] = -1;
				SavePublicAdsData(i, "AdLine3");
			}
			case 4:
			{
				format(gPublicAds[i][mAdLine4Content], 65, content);
				format(gPublicAds[i][mAdLine4Owner], MAX_PLAYER_NAME, gPlayerData[playerid][pName]);
				
				gPublicAds[i][mAdLine4TimeLeft] = -1;
				SavePublicAdsData(i, "AdLine4");
			}
			case 5:
			{
				format(gPublicAds[i][mAdLine5Content], 65, content);
				format(gPublicAds[i][mAdLine5Owner], MAX_PLAYER_NAME, gPlayerData[playerid][pName]);
				
				gPublicAds[i][mAdLine5TimeLeft] = -1;
				SavePublicAdsData(i, "AdLine5");
			}
			case 6:
			{
				format(gPublicAds[i][mAdLine6Content], 65, content);
				format(gPublicAds[i][mAdLine6Owner], MAX_PLAYER_NAME, gPlayerData[playerid][pName]);
				
				gPublicAds[i][mAdLine6TimeLeft] = -1;
				SavePublicAdsData(i, "AdLine6");
			}
			case 7:
			{
				format(gPublicAds[i][mAdLine7Content], 65, content);
				format(gPublicAds[i][mAdLine7Owner], MAX_PLAYER_NAME, gPlayerData[playerid][pName]);
				
				gPublicAds[i][mAdLine7TimeLeft] = -1;
				SavePublicAdsData(i, "AdLine7");
			}
			case 8:
			{
				format(gPublicAds[i][mAdLine8Content], 65, content);
				format(gPublicAds[i][mAdLine8Owner], MAX_PLAYER_NAME, gPlayerData[playerid][pName]);
				
				gPublicAds[i][mAdLine8TimeLeft] = -1;
				SavePublicAdsData(i, "AdLine8");
			}
			case 9:
			{
				format(gPublicAds[i][mAdLine9Content], 65, content);
				format(gPublicAds[i][mAdLine9Owner], MAX_PLAYER_NAME, gPlayerData[playerid][pName]);
				
				gPublicAds[i][mAdLine9TimeLeft] = -1;
				SavePublicAdsData(i, "AdLine9");
			}
			case 10:
			{
				format(gPublicAds[i][mAdLine10Content], 65, content);
				format(gPublicAds[i][mAdLine10Owner], MAX_PLAYER_NAME, gPlayerData[playerid][pName]);
				
				gPublicAds[i][mAdLine10TimeLeft] = -1;
				SavePublicAdsData(i, "AdLine10");
			}
		}
		
		defer RefreshPublicAd(i);
		
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Zmodyfikowa³eœ og³oszenie");
	}
	
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ przy ¿adnej tablicy og³oszeñ");
	
	return 1;
}

dcmd_usunogloszenie(playerid, params[])
{
	#pragma unused params
	
	new removed = 0;
	
	for(new i = 0; i < sizeof(gPublicAds); i++)
	{
		if(!PlayerToPoint(2.0, playerid, gPublicAds[i][mObjPosX], gPublicAds[i][mObjPosY], gPublicAds[i][mObjPosZ]))
		{
			continue;
		}
		
		if(strcmp(gPublicAds[i][mAdLine1Owner], gPlayerData[playerid][pName], true) == 0 && strlen(gPublicAds[i][mAdLine1Owner]))
		{
			format(gPublicAds[i][mAdLine1Content], 65, "");
			gPublicAds[i][mAdLine1TimeLeft] = 0;
			format(gPublicAds[i][mAdLine1Owner], MAX_PLAYER_NAME, "");
			SavePublicAdsData(i, "AdLine1");
			
			removed = 1;
		}		
		else if(strcmp(gPublicAds[i][mAdLine2Owner], gPlayerData[playerid][pName], true) == 0 && strlen(gPublicAds[i][mAdLine2Owner]))
		{
			format(gPublicAds[i][mAdLine2Content], 65, "");
			gPublicAds[i][mAdLine2TimeLeft] = 0;
			format(gPublicAds[i][mAdLine2Owner], MAX_PLAYER_NAME, "");
			SavePublicAdsData(i, "AdLine2");
			
			removed = 1;
		}	
		else if(strcmp(gPublicAds[i][mAdLine3Owner], gPlayerData[playerid][pName], true) == 0 && strlen(gPublicAds[i][mAdLine3Owner]))
		{
			format(gPublicAds[i][mAdLine3Content], 65, "");
			gPublicAds[i][mAdLine3TimeLeft] = 0;
			format(gPublicAds[i][mAdLine3Owner], MAX_PLAYER_NAME, "");
			SavePublicAdsData(i, "AdLine3");
			
			removed = 1;
		}	
		else if(strcmp(gPublicAds[i][mAdLine4Owner], gPlayerData[playerid][pName], true) == 0 && strlen(gPublicAds[i][mAdLine4Owner]))
		{
			format(gPublicAds[i][mAdLine4Content], 65, "");
			gPublicAds[i][mAdLine4TimeLeft] = 0;
			format(gPublicAds[i][mAdLine4Owner], MAX_PLAYER_NAME, "");
			SavePublicAdsData(i, "AdLine4");
			
			removed = 1;
		}	
		else if(strcmp(gPublicAds[i][mAdLine5Owner], gPlayerData[playerid][pName], true) == 0 && strlen(gPublicAds[i][mAdLine5Owner]))
		{
			format(gPublicAds[i][mAdLine5Content], 65, "");
			gPublicAds[i][mAdLine5TimeLeft] = 0;
			format(gPublicAds[i][mAdLine5Owner], MAX_PLAYER_NAME, "");
			SavePublicAdsData(i, "AdLine5");
			
			removed = 1;
		}	
		else if(strcmp(gPublicAds[i][mAdLine6Owner], gPlayerData[playerid][pName], true) == 0 && strlen(gPublicAds[i][mAdLine6Owner]))
		{
			format(gPublicAds[i][mAdLine6Content], 65, "");
			gPublicAds[i][mAdLine6TimeLeft] = 0;
			format(gPublicAds[i][mAdLine6Owner], MAX_PLAYER_NAME, "");
			SavePublicAdsData(i, "AdLine6");
			
			removed = 1;
		}	
		else if(strcmp(gPublicAds[i][mAdLine7Owner], gPlayerData[playerid][pName], true) == 0 && strlen(gPublicAds[i][mAdLine7Owner]))
		{
			format(gPublicAds[i][mAdLine7Content], 65, "");
			gPublicAds[i][mAdLine7TimeLeft] = 0;
			format(gPublicAds[i][mAdLine7Owner], MAX_PLAYER_NAME, "");
			SavePublicAdsData(i, "AdLine7");
			
			removed = 1;
		}	
		else if(strcmp(gPublicAds[i][mAdLine8Owner], gPlayerData[playerid][pName], true) == 0 && strlen(gPublicAds[i][mAdLine8Owner]))
		{
			format(gPublicAds[i][mAdLine8Content], 65, "");
			gPublicAds[i][mAdLine8TimeLeft] = 0;
			format(gPublicAds[i][mAdLine8Owner], MAX_PLAYER_NAME, "");
			SavePublicAdsData(i, "AdLine8");
			
			removed = 1;
		}	
		else if(strcmp(gPublicAds[i][mAdLine9Owner], gPlayerData[playerid][pName], true) == 0 && strlen(gPublicAds[i][mAdLine9Owner]))
		{
			format(gPublicAds[i][mAdLine9Content], 65, "");
			gPublicAds[i][mAdLine9TimeLeft] = 0;
			format(gPublicAds[i][mAdLine9Owner], MAX_PLAYER_NAME, "");
			SavePublicAdsData(i, "AdLine9");
			
			removed = 1;
		}	
		else if(strcmp(gPublicAds[i][mAdLine10Owner], gPlayerData[playerid][pName], true) == 0 && strlen(gPublicAds[i][mAdLine10Owner]))
		{
			format(gPublicAds[i][mAdLine10Content], 65, "");
			gPublicAds[i][mAdLine10TimeLeft] = 0;
			format(gPublicAds[i][mAdLine10Owner], MAX_PLAYER_NAME, "");
			SavePublicAdsData(i, "AdLine10");
			
			removed = 1;
		}
		// TODO: to lower case
		if(removed)
		{
			defer RefreshPublicAd(i);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Zdj¹³eœ swoje og³oszenie");
		}
		else
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Na tej tablicy nie ma ¿adnych twoich og³oszeñ");
		}
		return 1;
	}
	
	SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ przy ¿adnej tablicy og³oszeñ");
	return 1;
}

dcmd_dodajogloszenie(playerid, params[])
{
	if(gPlayerData[playerid][pPlayingHours] < 1)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Musisz przegraæ 1 godzin na serwerze aby móc dodawaæ og³oszenia");
		return 1;
	}
	
	new content[65], added = 0;
	
	if(sscanf(params, "s[65]", content))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /dodajogloszenie [treœæ]");
		return 1;
	}
	
	for(new i = 0; i < sizeof(gPublicAds); i++)
	{
		if(!PlayerToPoint(2.0, playerid, gPublicAds[i][mObjPosX], gPublicAds[i][mObjPosY], gPublicAds[i][mObjPosZ]))
		{
			continue;
		}
		
		if(strlen(gPublicAds[i][mOwner]) > 0 && strcmp(gPublicAds[i][mOwner], gPlayerData[playerid][pName], false) != 0)
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ta tablica zosta³a przez kogoœ wykupiona i nie mo¿na dodawaæ na niej og³oszeñ");
			return 1;
		}
		
		if((strcmp(gPublicAds[i][mOwner], gPlayerData[playerid][pName], false) != 0 || strlen(gPublicAds[i][mOwner]) == 0) &&
		((strcmp(gPublicAds[i][mAdLine1Owner], gPlayerData[playerid][pName], true) == 0 && strlen(gPublicAds[i][mAdLine1Owner]) && gPublicAds[i][mAdLine1TimeLeft] > 0) ||
		(strcmp(gPublicAds[i][mAdLine2Owner], gPlayerData[playerid][pName], true) == 0 && strlen(gPublicAds[i][mAdLine2Owner]) && gPublicAds[i][mAdLine2TimeLeft] > 0) ||
		(strcmp(gPublicAds[i][mAdLine3Owner], gPlayerData[playerid][pName], true) == 0 && strlen(gPublicAds[i][mAdLine3Owner]) && gPublicAds[i][mAdLine3TimeLeft] > 0) ||
		(strcmp(gPublicAds[i][mAdLine4Owner], gPlayerData[playerid][pName], true) == 0 && strlen(gPublicAds[i][mAdLine4Owner]) && gPublicAds[i][mAdLine4TimeLeft] > 0) ||
		(strcmp(gPublicAds[i][mAdLine5Owner], gPlayerData[playerid][pName], true) == 0 && strlen(gPublicAds[i][mAdLine5Owner]) && gPublicAds[i][mAdLine5TimeLeft] > 0) ||
		(strcmp(gPublicAds[i][mAdLine6Owner], gPlayerData[playerid][pName], true) == 0 && strlen(gPublicAds[i][mAdLine6Owner]) && gPublicAds[i][mAdLine6TimeLeft] > 0) ||
		(strcmp(gPublicAds[i][mAdLine7Owner], gPlayerData[playerid][pName], true) == 0 && strlen(gPublicAds[i][mAdLine7Owner]) && gPublicAds[i][mAdLine7TimeLeft] > 0) ||
		(strcmp(gPublicAds[i][mAdLine8Owner], gPlayerData[playerid][pName], true) == 0 && strlen(gPublicAds[i][mAdLine8Owner]) && gPublicAds[i][mAdLine8TimeLeft] > 0) ||
		(strcmp(gPublicAds[i][mAdLine9Owner], gPlayerData[playerid][pName], true) == 0 && strlen(gPublicAds[i][mAdLine9Owner]) && gPublicAds[i][mAdLine9TimeLeft] > 0) ||
		(strcmp(gPublicAds[i][mAdLine10Owner], gPlayerData[playerid][pName], true) == 0 && strlen(gPublicAds[i][mAdLine10Owner]) && gPublicAds[i][mAdLine10TimeLeft] > 0)))
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Doda³eœ ju¿ jedno og³oszenie na tej tablicy");
			return 1;
		}
		
		if(gPublicAds[i][mAdLine1TimeLeft] == 0)
		{
			format(gPublicAds[i][mAdLine1Content], 65, content);
			format(gPublicAds[i][mAdLine1Owner], MAX_PLAYER_NAME, gPlayerData[playerid][pName]);
			gPublicAds[i][mAdLine1TimeLeft] = 144; // 2 dni - liczy po 10 min
			SavePublicAdsData(i, "AdLine1");
			added = 1;
		}
		else if(gPublicAds[i][mAdLine2TimeLeft] == 0)
		{
			format(gPublicAds[i][mAdLine2Content], 65, content);
			format(gPublicAds[i][mAdLine2Owner], MAX_PLAYER_NAME, gPlayerData[playerid][pName]);
			gPublicAds[i][mAdLine2TimeLeft] = 144; // 2 dni - liczy po 10 min
			SavePublicAdsData(i, "AdLine2");
			added = 1;
		}
		else if(gPublicAds[i][mAdLine3TimeLeft] == 0)
		{
			format(gPublicAds[i][mAdLine3Content], 65, content);
			format(gPublicAds[i][mAdLine3Owner], MAX_PLAYER_NAME, gPlayerData[playerid][pName]);
			gPublicAds[i][mAdLine3TimeLeft] = 144; // 2 dni - liczy po 10 min
			SavePublicAdsData(i, "AdLine3");
			added = 1;
		}
		else if(gPublicAds[i][mAdLine4TimeLeft] == 0)
		{
			format(gPublicAds[i][mAdLine4Content], 65, content);
			format(gPublicAds[i][mAdLine4Owner], MAX_PLAYER_NAME, gPlayerData[playerid][pName]);
			gPublicAds[i][mAdLine4TimeLeft] = 144; // 2 dni - liczy po 10 min
			SavePublicAdsData(i, "AdLine4");
			added = 1;
		}
		else if(gPublicAds[i][mAdLine5TimeLeft] == 0)
		{
			format(gPublicAds[i][mAdLine5Content], 65, content);
			format(gPublicAds[i][mAdLine5Owner], MAX_PLAYER_NAME, gPlayerData[playerid][pName]);
			gPublicAds[i][mAdLine5TimeLeft] = 144; // 2 dni - liczy po 10 min
			SavePublicAdsData(i, "AdLine5");
			added = 1;
		}
		else if(gPublicAds[i][mAdLine6TimeLeft] == 0)
		{
			format(gPublicAds[i][mAdLine6Content], 65, content);
			format(gPublicAds[i][mAdLine6Owner], MAX_PLAYER_NAME, gPlayerData[playerid][pName]);
			gPublicAds[i][mAdLine6TimeLeft] = 144; // 2 dni - liczy po 10 min
			SavePublicAdsData(i, "AdLine6");
			added = 1;
		}
		else if(gPublicAds[i][mAdLine7TimeLeft] == 0)
		{
			format(gPublicAds[i][mAdLine7Content], 65, content);
			format(gPublicAds[i][mAdLine7Owner], MAX_PLAYER_NAME, gPlayerData[playerid][pName]);
			gPublicAds[i][mAdLine7TimeLeft] = 144; // 2 dni - liczy po 10 min
			SavePublicAdsData(i, "AdLine7");
			added = 1;
		}
		else if(gPublicAds[i][mAdLine8TimeLeft] == 0)
		{
			format(gPublicAds[i][mAdLine8Content], 65, content);
			format(gPublicAds[i][mAdLine8Owner], MAX_PLAYER_NAME, gPlayerData[playerid][pName]);
			gPublicAds[i][mAdLine8TimeLeft] = 144; // 2 dni - liczy po 10 min
			SavePublicAdsData(i, "AdLine8");
			added = 1;
		}
		else if(gPublicAds[i][mAdLine9TimeLeft] == 0)
		{
			format(gPublicAds[i][mAdLine9Content], 65, content);
			format(gPublicAds[i][mAdLine9Owner], MAX_PLAYER_NAME, gPlayerData[playerid][pName]);
			gPublicAds[i][mAdLine9TimeLeft] = 144; // 2 dni - liczy po 10 min
			SavePublicAdsData(i, "AdLine9");
			added = 1;
		}
		else if(gPublicAds[i][mAdLine10TimeLeft] == 0)
		{
			format(gPublicAds[i][mAdLine10Content], 65, content);
			format(gPublicAds[i][mAdLine10Owner], MAX_PLAYER_NAME, gPlayerData[playerid][pName]);
			gPublicAds[i][mAdLine10TimeLeft] = 144; // 2 dni - liczy po 10 min
			SavePublicAdsData(i, "AdLine10");
			added = 1;
		}
		
		defer RefreshPublicAd(i);
		
		if(added)
		{
			SendClientMessage(playerid, COLOR_GREEN, "[INFO:] Zamieœci³eœ og³oszenie - bêdzie ono nienadpisywalne przez dwa dni");
		}
		else
		{
			SendClientMessage(playerid, COLOR_GREEN, "[INFO:] Brak miejsca na kolejne og³oszenie");
		}
		return 1;
	}
	
	SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie znajdujesz siê przy ¿adnej tablicy z og³oszeniami");
	return 1;
}

dcmd_przesuntablice(playerid, params[])
{
	#pragma unused params
	
	for(new i = 0; i < sizeof(gPublicAds); i++)
	{
		if(!PlayerToPoint(2.0, playerid, gPublicAds[i][mObjPosX], gPublicAds[i][mObjPosY], gPublicAds[i][mObjPosZ]))
		{
			continue;
		}
		
		if(strcmp(gPublicAds[i][mOwner], gPlayerData[playerid][pName], false) != 0 || strlen(gPublicAds[i][mOwner]) == 0)
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ta tablica nie nale¿y do ciebie");
			return 1;
		}
		
		EditDynamicObject(playerid, gPublicAds[i][mObjId]);
	}
	
	SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie znajdujesz siê przy ¿adnej tablicy og³oszeñ");
	return 1;
}

dcmd_ogloszenia(playerid, params[])
{
	#pragma unused params
	
	SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "/dodajogloszenie - /usunogloszenie - /edytujogloszenie - /przesuntablice - /zdemontujtablice");

	return 1;
}

dcmd_zdemontujtablice(playerid, params[])
{
	#pragma unused params

	for(new i = 0; i < sizeof(gPublicAds); i++)
	{
		if(!PlayerToPoint(2.0, playerid, gPublicAds[i][mObjPosX], gPublicAds[i][mObjPosY], gPublicAds[i][mObjPosZ]))
		{
			continue;
		}
		
		if((strcmp(gPublicAds[i][mOwner], gPlayerData[playerid][pName], false) != 0 || strlen(gPublicAds[i][mOwner]) == 0))
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ta tablica nie nale¿y do ciebie");
			return 1;
		}
		
		DestroyDynamicObject(gPublicAds[i][mObjId]);
		
		gPublicAds[i][mObjId] = 0;		
		format(gPublicAds[i][mOwner], MAX_PLAYER_NAME, "");
		gPublicAds[i][mObjPosX] = 0.0;
		gPublicAds[i][mObjPosY] = 0.0;
		gPublicAds[i][mObjPosZ] = 0.0;
		
		SavePublicAdsData(i, "ObjPos");
		SavePublicAdsData(i, "Owner");
		
		InsertPlayerItem(playerid, 1, 178, 0, 0);
	}
	
	SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ przy ¿adnej tablicy og³oszeñ");
	
	return 1;
}

dcmd_antibh(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
	{
		return 0;
	}
	
	if(sscanf(params, "d", gIsAntiBH))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /antibh [0/1]");
		return 1;
	}
	
	if(gIsAntiBH == 0)
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] AntiBH zosta³o WY£¥CZONE");
		return 1;
	}
	else
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] AntiBH zosta³o W£¥CZONE");
		return 1;
	}
	
}

dcmd_abizfaction(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
	{
		return 0;
	}
	
	new bizId, factionId;
	
	if(sscanf(params, "dd", bizId, factionId))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /abizfaction [bizId] [factionId]");
		return 1;
	}
	
	Businesses[bizId][mFaction] = factionId;
	SaveBizData(bizId, "Faction");
	
	RefreshBizDescription(bizId);
	
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Business faction changed");
	
	return 1;
}

dcmd_abizfactiontime(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
	{
		return 0;
	}
	
	new bizId, factionTime;
	
	if(sscanf(params, "dd", bizId, factionTime))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /abizfactiontime [bizId] [factionTime]");
		return 1;
	}
	
	Businesses[bizId][mFactionTimeLeft] = factionTime;
	SaveBizData(bizId, "FactionTimeLeft");
	
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Business faction time left changed");
	
	return 1;
}

dcmd_zatankujlotnicze(playerid, params[])
{
	new planeId;
	
	if(sscanf(params, "d", planeId))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /zatankujlotnicze [rejestracja]");
		return 1;
	}
	
	planeId = CarSerialToID(planeId);
	
	if(planeId == -1)
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Pojazd o takiej rejestracji nie istnieje");
		return 1;
	}
	
	new vehID = GetPlayerVehicleID(playerid);
	
	/* No truck */
	if(vehID == 0)
	{
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", RAF_RSC_CP_MENU_INV_VEHID, RAF_RSC_CP_MENU_EXIT, "");
		return 1;
	}
	
	if(gVehData[vehID][EngineOn])
	{
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Wy³¹cz silnik przed tankowaniem.", RAF_RSC_CP_MENU_EXIT, "");
		return 1;
	}
	
	/* Not a faction truck */
	if(gVehData[vehID-1][mVehFaction] != FACTIONID_RAFINERY)
	{
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", RAF_RSC_CP_MENU_INV_VEHFAC, RAF_RSC_CP_MENU_EXIT, "");
		return 1;
	}
	
	new Float:truckXpos, Float:truckYpos, Float:truckZpos;
	
	if(!PlayerToPoint(30.0, playerid, truckXpos, truckYpos, truckZpos))
	{
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Jesteœ zbyt daleko od tankowanego pojazdu.", RAF_RSC_CP_MENU_EXIT, "");
		return 1;
	}
	
	new tlID = GetVehicleTrailer(vehID);
	
	/* Truck has no attached tanker */
	if(tlID == 0)
	{
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", RAF_RSC_CP_MENU_INV_TLID, RAF_RSC_CP_MENU_EXIT, "");
		return 1;
	}
	
	/* Not a faction tanker */
	if(gVehData[tlID-1][mVehFaction] != FACTIONID_RAFINERY)
	{
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", RAF_RSC_CP_MENU_INV_TLFAC, RAF_RSC_CP_MENU_EXIT, "");
		return 1;
	}
	
	/* Tanker is already filled with other type of fuel */
	if(gVehData[tlID-1][TankerResourceType] != TANKER_TYPE_FLY)
	{
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Cysterna jest zatankowana innym paliwem ni¿ lotnicze", "Zamknij", "");
		return 1;
	}
	
	/* Tanker is already refueling */
	if(gVehData[tlID-1][TankerIsRefueling])
	{
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", RAF_RSC_CP_MENU_AREFUELING, RAF_RSC_CP_MENU_EXIT, "");
		return 1;
	}
	
	/* Tanker is empty */
	if(gVehData[tlID-1][TankerResourceValue] == 0)
	{
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Cysterna jest pusta.", "Zamknij", "");
		return 1;
	}
	
	new Float:tX, Float:tY, Float:tZ;
	GetPlayerPos(playerid, tX, tY, tZ);
	
	gVehData[tlID-1][TankerIsRefueling] = 1;
	
	SetTimerEx("RefuelVehicleFly", 1000, false, "iffffddd", playerid, 0.0, tX, tY, tZ, vehID, tlID, planeId);
	
	ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", RAF_RSC_CP_MENU_REFUELING, RAF_RSC_CP_MENU_EXIT, "");
	
	return 1;
}

dcmd_startevent(playerid, params[])
{
	#pragma unused params
	
	if(gPlayerData[playerid][pAdmin] <= 0)
	{
		return 0;
	}
	
	ShowPlayerDialog(playerid, DIALOG_EVENT_SELECT, DIALOG_STYLE_LIST, "Wybierz event do rozpoczêcia", "Event 1 - Area51 Code Search\nEvent 2 - Lowrider Game", "Wybierz", "Zamknij");
	return 1;
}

dcmd_stopevent(playerid, params[])
{
	#pragma unused params
	
	new string[512], activeListItem = 0;
	
	if(!gPlayerData[playerid][pAdmin])
	{
		return 0;
	}
	
	if(gEvent1isRunning)
	{
		format(string, sizeof(string), "Area51\n");
		for(; activeListItem < 10; activeListItem++)
		{
			gActiveEventList[playerid][activeListItem] = 1;
		}
	}
	
	if(gEvent2isRunning)
	{
		format(string, sizeof(string), "Lowerider game\n");
		for(; activeListItem < 10; activeListItem++)
		{
			gActiveEventList[playerid][activeListItem] = 2;
		}
	}
	
	if(strlen(string) == 0)
	{		
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Brak aktywnych eventów.", "Wybierz", "Anuluj");
	}
	else
	{
		ShowPlayerDialog(playerid, DIALOG_EVENT_STOP, DIALOG_STYLE_LIST, "Wybierz event który chcesz przerwaæ", string, "Wybierz", "Anuluj");
	}
	
	return 1;
}

dcmd_dolaczdoeventu(playerid, params[])
{
	#pragma unused params

	new string[512], activeListItem = 0;
	
	if(gEvent1isRunning)
	{
		for(new i = 0; i < sizeof(gEvent1players); i++)
		{
			if(gEvent1players[i] == playerid)
			{
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Uczestniczysz ju¿ w jednym z eventów.", "Zamknij", "");
				return 1;
			}
		}
		
		if(gEvent1timeToJoin > 0)
		{
			format(string, sizeof(string), "Area51\n");
			for(; activeListItem < 10; activeListItem++)
			{
				gActiveEventList[playerid][activeListItem] = 1;
			}
		}
	}
	
	if(gEvent2isRunning)
	{
		for(new i = 0; i < sizeof(gEvent2players); i++)
		{
			if(gEvent2players[i] == playerid)
			{
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Uczestniczysz ju¿ w jednym z eventów.", "Zamknij", "");
				return 1;
			}
		}
		
		if(gEvent2timeToJoin > 0)
		{
			format(string, sizeof(string), "Lowrider game\n");
			for(; activeListItem < 10; activeListItem++)
			{
				gActiveEventList[playerid][activeListItem] = 2;
			}
		}
	}
	
	if(strlen(string) == 0)
	{		
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Brak aktywnych eventów.", "Zamknij", "");
	}
	else
	{
		ShowPlayerDialog(playerid, DIALOG_EVENT_JOIN, DIALOG_STYLE_LIST, "Wybierz event", string, "Wybierz", "Anuluj");
	}
	
	return 1;
}

dcmd_opuscevent(playerid, params[])
{
	#pragma unused params
	
	RemovePlayerFormEvents(playerid);
	
	return 1;
}

dcmd_events(playerid, params[])
{
	#pragma unused params
	
	if(!gPlayerData[playerid][pAdmin])
	{
		return 0;
	}
	
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /startevent - /stopevent");
	return 1;
}

dcmd_przerwijprace(playerid, params[])
{
	#pragma unused params
	
	StopJob(playerid);
	
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Przerwa³eœ wykonywanie aktualnego zlecenia");
	return 1;
}

dcmd_abustrackcmds(playerid, params[])
{
	#pragma unused params
	
	if(gPlayerData[playerid][pAdmin] != 5)
	{
		return 0;
	}
	
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /onofftraseb - /trasybon - /ustawcpb");
	return 1;
}

dcmd_atrashtrackcmds(playerid, params[])
{
	#pragma unused params
	
	if(gPlayerData[playerid][pAdmin] != 5)
	{
		return 0;
	}
	
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /onofftraset - /trasyton - /ustawcpt - /showtrash - /hidetrash");
	return 1;
}

dcmd_asweepertrackcmds(playerid, params[])
{
	#pragma unused params
	
	if(gPlayerData[playerid][pAdmin] != 5)
	{
		return 0;
	}
	
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /onofftrases - /trasyson - /ustawcps - /showgarbage - /hidegarbage");
	return 1;
}

dcmd_afarmertrackcmds(playerid, params[])
{
	#pragma unused params
	
	if(gPlayerData[playerid][pAdmin] != 5)
	{
		return 0;
	}
	
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /onofftrasef - /trasyfon - /ustawcpf");
	return 1;
}

dcmd_ahoursplayed(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
	{
		return 0;
	}
	
	new givePlayerId, hours;
	
	if(sscanf(params, "dd", givePlayerId, hours))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /ahoursplayed [playerid] [hours]");
		return 1;
	}
	
	gPlayerData[givePlayerId][pPlayingHours] = hours;
	SavePlayerData(givePlayerId, "PlayingHours");
	
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Playing hours for player has been changed");
	
	return 1;
}
dcmd_vehbreaktimeleft(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
	{
		return 0;
	}
	
	new string[128], value;
	
	if(sscanf(params, "d", value))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /vehbreaktimeleft [time]");
		return 1;
	}
	
	GetPlayerPos(playerid, gPlayerData[playerid][pCrashX], gPlayerData[playerid][pCrashY], gPlayerData[playerid][pCrashZ]);
	
	for(new i = 0; i < sizeof(DynamicZones); i++)
	{
		if(IsPointInArea(DynamicZones[i][mPosMinX], DynamicZones[i][mPosMinY], DynamicZones[i][mPosMaxX], DynamicZones[i][mPosMaxY], gPlayerData[playerid][pCrashX], gPlayerData[playerid][pCrashY]))
		{	
			DynamicZones[i][mVehBreakTimeLeft] = value;
			SaveGangZone(i, "VehBreakTimeLeft");
			
			format(string, sizeof(string), "Czas zmieniony w streie %d", i);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			return 1;
		}
	}
	
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ w ¿adnej strefie");
	return 1;
}

dcmd_zonecmds(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] != 5)
	{
		return 0;
	}
	
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "/vehbreaktimeleft");
	return 1;
}

dcmd_abroadcastmessages(playerid, params[])
{
	#pragma unused params
	
	if(gPlayerData[playerid][pAdmin] == 0)
	{
		return 0;
	}
	
	if(gPlayerData[playerid][mBroadCastMessages])
	{
		gPlayerData[playerid][mBroadCastMessages] = 0;
		SavePlayerData(playerid, "BroadCastMessages");
		
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Wy³¹czy³eœ informacje administracyjne");
	}
	else
	{
		gPlayerData[playerid][mBroadCastMessages] = 1;
		SavePlayerData(playerid, "BroadCastMessages");
		
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] W³¹czy³eœ informacje administracyjne");
	}
	
	return 1;
}

dcmd_setpt(playerid, params[])
{
	#pragma unused params
	
	if(gPlayerData[playerid][pAdmin] != 5)
	{
		return 0;
	}
	
	GetPlayerPos(playerid, gPlayerVars[playerid][measurePointX], gPlayerVars[playerid][measurePointY], gPlayerVars[playerid][measurePointZ]);
	
	new string[128];
	
	format(string, sizeof(string), "Point saved at X: %.3f, Y: %.3f, Z: %.3f", gPlayerVars[playerid][measurePointX], gPlayerVars[playerid][measurePointY], gPlayerVars[playerid][measurePointZ]);
	
	SendClientMessage(playerid, COLOR_WHITE, string);
	
	return 1;
}

dcmd_getdist(playerid, params[])
{
	#pragma unused params 

	new string[128];
	
	format(string, sizeof(string), "Distance to point: %d", GetDistanceToPoint(playerid, gPlayerVars[playerid][measurePointX], gPlayerVars[playerid][measurePointY], gPlayerVars[playerid][measurePointZ]));
	
	SendClientMessage(playerid, COLOR_WHITE, string);
	
	return 1;
}

dcmd_showgarbage(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
	{
		return 0;
	}
	
	new trackId;
	
	if(sscanf(params, "d", trackId))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /showgarbage [trasa]");
		return 1;
	}
	
	if(!gSweeperTrackEnabled[trackId])
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ta trasa nie jest wy³¹czona");
		return 1;
	}
	
	for(new i = 0; i < sizeof(gSweeperTrackEnabled); i++)
	{
		if(gSweeperTrackCpX[trackId][i] == 0.0 || gSweeperTrackCpY[trackId][i] == 0.0)
		{
			continue;
		}
		
		if(gSweeperTrackCpTrashId[trackId][i])
		{
			DestroyDynamicObject(gSweeperTrackCpTrashId[trackId][i]);
		}
		
		gSweeperTrackCpTrashId[trackId][i] = CreateDynamicObject(852, gSweeperTrackCpX[trackId][i], gSweeperTrackCpY[trackId][i], gSweeperTrackCpZ[trackId][i]-0.7, 0.0, 0.0, 0.0, 0, 0);
	}
	
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Objects should now be visible");
	return 1;
}

dcmd_hidegarbage(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
	{
		return 0;
	}
	
	new trackId;
	
	if(sscanf(params, "d", trackId))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /hidegarbage [trasa]");
		return 1;
	}
	
	if(!gSweeperTrackEnabled[trackId])
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ta trasa nie jest w³¹czona");
		return 1;
	}
	
	for(new i = 0; i < sizeof(gSweeperTrackEnabled); i++)
	{
		if(gSweeperTrackCpTrashId[trackId][i])
		{
			DestroyDynamicObject(gSweeperTrackCpTrashId[trackId][i]);
		}
	}
	
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Objects should now be destroyed");
	return 1;
}

dcmd_showtrash(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
	{
		return 0;
	}
	
	new trackId;
	
	if(sscanf(params, "d", trackId))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /showtrash [trasa]");
		return 1;
	}
	
	if(!gTrashTrackEnabled[trackId])
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ta trasa nie jest w³¹czona");
		return 1;
	}
	
	for(new i = 0; i < sizeof(gTrashTrackEnabled); i++)
	{
		if(gTrashTrackCpX[trackId][i] == 0.0 || gTrashTrackCpY[trackId][i] == 0.0)
		{
			continue;
		}
	
		if(gTrashTrackCpTrashId[trackId][i])
		{
			DestroyDynamicObject(gTrashTrackCpTrashId[trackId][i]);
		}
		
		gTrashTrackCpTrashId[trackId][i] = CreateDynamicObject(1343, gTrashTrackCpX[trackId][i], gTrashTrackCpY[trackId][i], gTrashTrackCpZ[trackId][i]-0.75, 0.0, 0.0, 0.0, 0, 0);
	}
	
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Objects should be now visible");
	return 1;
}

dcmd_hidetrash(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
	{
		return 0;
	}
	
	new trackId;
	
	if(sscanf(params, "d", trackId))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /hidetrash [trasa]");
		return 1;
	}
	
	if(!gTrashTrackEnabled[trackId])
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ta trasa nie jest w³¹czona");
		return 1;
	}
	
	for(new i = 0; i < sizeof(gTrashTrackEnabled); i++)
	{
		if(gTrashTrackCpX[trackId][i] == 0.0 || gTrashTrackCpY[trackId][i] == 0.0)
		{
			continue;
		}
	
		if(gTrashTrackCpTrashId[trackId][i])
		{
			DestroyDynamicObject(gTrashTrackCpTrashId[trackId][i]);
		}
	}
	
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Objects should be now destroy");
	return 1;
}

dcmd_gotoevent(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
	{
		return 0;
	}
	
	new eventId;
	if(sscanf(params, "d", eventId))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /gotoevent [id od 1]");
		return 1;
	}
	
	switch(eventId)
	{
		case 2:
		{
			SetPlayerInterior(playerid, EVENT2INT);
			SetPlayerVirtualWorld(playerid, EVENT2WORLD);
			SetPlayerPos(playerid, -1398.394, 993.989, 1024.2);
			
			return 1;
		}
	}
	
	SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Wrong event ID");
	return 1;
}

dcmd_agotocmds(playerid, params[])
{
	#pragma unused params
	
	if(gPlayerData[playerid][pAdmin] == 0)
	{
		return 0;
	}
	
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /gotomg - /gotosf - /gotols - /gotoevent");
	return 1;
}

dcmd_walkower(playerid, params[])
{
	#pragma unused params
	
	new string[128];
	
	if(gPlayerData[playerid][pFaction] == 255)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ liderem gangu");
		return 1;
	}
	
	if(DynamicFactions[gPlayerData[playerid][pFaction]][fType] != FACTIONT_GANG)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ liderem gangu");
		return 1;
	}
	
	if(!CheckRankPrivilidges(gPlayerData[playerid][pFaction], gPlayerData[playerid][pRank], "walczoterytorium"))
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie posiadasz uprawnieñ do przerwania wojny o terytorium !");
		return 1;
	}
	
	if(!gGangWar[Enabled])
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] W tej chwili nie ma ¿adnej walki o terytorium");
		return 1;
	}
	
	foreach(Player, i)
	{
		if(!gPlayerLogged[i])
		{
			continue;
		}
		
		if(gPlayerData[i][pFaction] != 255)
		{
			if(DynamicFactions[gPlayerData[i][pFaction]][fType] == FACTIONT_GANG)
			{
				TextDrawSetString(GangWar[i], " ");
				TextDrawSetString(GangWarTime[i], " ");
				
				GangZoneStopFlashForPlayer(i, gGangWar[AreaID]);
			}
		}
	}
	
	gGangWar[TimeLeft] = 0;
	gGangWar[Enabled] = 0;
	
	if(gGangWar[FactionStarted] == gPlayerData[playerid][pFaction])
	{
		DynamicFactions[gGangWar[FactionAttacked]][fTerritoryWarWins]++;
		SaveFData(gGangWar[FactionAttacked], "TerritoryWarWins");
		
		DynamicFactions[gGangWar[FactionStarted]][fTerritoryWarLooses]++;
		SaveFData(gGangWar[FactionStarted], "TerritoryWarLooses");
		
		RefreshZoneColorAfterWar();
		
		format(string, sizeof(string), "Terytorium zostaje pod kontrola~n~%s", DynamicFactions[DynamicZones[gGangWar[AreaID]][mFaction]][Name]);
		
		foreach(Player, i)
		{
			if(!gPlayerLogged[i])
			{
				continue;
			}
			
			if(gPlayerData[i][pFaction] != gGangWar[FactionStarted] && gPlayerData[i][pFaction] != gGangWar[FactionAttacked])
			{
				continue;
			}
			
			GameTextForPlayer(i, string, 6000, 6);
		}
		
		return 1;
	}
	else if(gGangWar[FactionAttacked] == gPlayerData[playerid][pFaction])
	{
		DynamicFactions[gGangWar[FactionStarted]][fTerritoryWarWins]++;
		SaveFData(gGangWar[FactionStarted], "TerritoryWarWins");
		
		DynamicFactions[gGangWar[FactionAttacked]][fTerritoryWarLooses]++;
		SaveFData(gGangWar[FactionAttacked], "TerritoryWarLooses");
		
		DynamicZones[gGangWar[AreaID]][mFaction] = gGangWar[FactionStarted];
		SaveGangZone(gGangWar[AreaID], "Faction");
		
		RefreshZoneColorAfterWar();
		
		format(string, sizeof(string), "Terytorium zostalo przejete przez~n~%s", DynamicFactions[gGangWar[FactionStarted]]);
		
		foreach(Player, i)
		{
			if(!gPlayerLogged[i])
			{
				continue;
			}
			
			if(gPlayerData[i][pFaction] != gGangWar[FactionStarted] && gPlayerData[i][pFaction] != gGangWar[FactionAttacked])
			{
				continue;
			}
			
			GameTextForPlayer(i, string, 6000, 6);
		}
		
		return 1;
	}
	
	return 1;
}

dcmd_nazwabudynku(playerid, params[])
{
	if(gPlayerData[playerid][pFaction] != FACTIONID_GOVERNMENT)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ urzêdnikiem");
		return 1;
	}
	
	new string[128], bId = -1;
	
	if(sscanf(params, "s[128]", string))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /nazwabudynku [nazwa]");
		return 1;
	}
	
	for(new i = 0; i < sizeof(Building); i++)
	{
		if(!PlayerToPoint(2.0, playerid, Building[i][EnterX], Building[i][EnterY], Building[i][EnterZ]))
		{
			continue;
		}
		
		bId = i;
	}
	
	if(bId == -1)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ przy wejœciu do ¿adnego budynku");
		return 1;
	}
	
	format(Building[bId][BuildingName], sizeof(string), string);
	SaveBData(bId, "BuildingName");
	
	RefreshBuildingDescription(bId);
	
	format(string, sizeof(string), "[INFO:] Zmieni³eœ nazwe budynku o ID %d na %s", bId, Building[bId][BuildingName]);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	
	format(string, sizeof(string), "[GOVERNMENT:] Building id: %d, name changed to $%s by %s", 
		bId, Building[bId][BuildingName], gPlayerData[playerid][pName]);
	GovermentLog(string);
	
	return 1;
}

dcmd_cenabudynku(playerid, params[])
{
	if(gPlayerData[playerid][pFaction] != FACTIONID_GOVERNMENT)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ urzêdnikiem");
		return 1;
	}
	
	new string[128], bId = -1, bPrice;
	
	if(sscanf(params, "d", bPrice))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /cenabudynku [cena]");
		return 1;
	}
	
	for(new i = 0; i < sizeof(Building); i++)
	{
		if(!PlayerToPoint(2.0, playerid, Building[i][EnterX], Building[i][EnterY], Building[i][EnterZ]))
		{
			continue;
		}
		
		bId = i;
	}
	
	if(bId == -1)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ przy wejœciu do ¿adnego budynku");
		return 1;
	}
	
	Building[bId][Price] = bPrice;
	SaveBData(bId, "Price");
	
	RefreshBuildingDescription(bId);
	
	format(string, sizeof(string), "[INFO:] Zmieni³eœ cene budynku o ID %d na %d", bId, Building[bId][Price]);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	
	format(string, sizeof(string), "[GOVERNMENT:] Building id: %d, price changed to $%d by %s", 
		bId, Building[bId][Price], gPlayerData[playerid][pName]);
	GovermentLog(string);
	
	return 1;
}

dcmd_listadonosow(playerid, params[])
{
	#pragma unused params
	
	if(!gPlayerData[playerid][pAdmin] && !gPlayerData[playerid][pModerator])
	{
		return 0;
	}
	
	new string[1024];
	
	for(new i = 0; i < sizeof(gPlayersReports); i++)
	{
		if(!gPlayersReports[i][mReportUsed])
		{
			continue;
		}
		
		format(string, sizeof(string), "%sReporter: %s, time left: %d(min)\n", string, gPlayersReports[i][mReporter], floatround(gPlayersReports[i][mReportTimeLeft]/60));
	}

	ShowPlayerDialog(playerid, DIALOG_REPORTS, DIALOG_STYLE_LIST, "Lista raportów", string, "Wybierz", "Zamknij");
	return 1;
}

dcmd_komendybudynkow(playerid, params[])
{
	#pragma unused params
	
	new string[256];
	format(string, sizeof(string), ""#COLOR_BEGIN"* Komendy budynkow *\n\n"#COLOR_DEFAULT"\n  /kupbudynek - /sprzedajbudynek - /fwplac - /fwyplac");
	
	ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, ""#COLOR_TITLE#"Lista komend", string, "Zamknij", "");
	return 1;
}

dcmd_setinfopickup(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
	{
		return 0;
	}
	
	new pickupId;

	if(sscanf(params, "d", pickupId))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /setinfopickup [pickupId]");
		return 1;
	}
	
	if(gPickupInfos[pickupId][mPickupId])
	{
		DestroyDynamicPickup(gPickupInfos[pickupId][mPickupId]);
	}
	
	GetPlayerPos(playerid, gPickupInfos[pickupId][mPosX], gPickupInfos[pickupId][mPosY], gPickupInfos[pickupId][mPosZ]);
	gPickupInfos[pickupId][mWorld] = GetPlayerVirtualWorld(playerid);
	gPickupInfos[pickupId][mInterior] = GetPlayerInterior(playerid);
	
	gPickupInfos[pickupId][mPickupId] = CreateDynamicPickup(gPickupInfos[pickupId][mPickupModel], gPickupInfos[pickupId][mPickupType], gPickupInfos[pickupId][mPosX], gPickupInfos[pickupId][mPosY], gPickupInfos[pickupId][mPosZ], gPickupInfos[pickupId][mWorld], gPickupInfos[pickupId][mInterior]); 
	
	SavePickupInfos(pickupId, "Pos");
	
	SendClientMessage(playerid, COLOR_GREEN, "[INFO:] Pickup placed");
	
	return 1;
}

dcmd_wynajmijpojazd(playerid, params[])
{
	#pragma unused params
	
	new vehId = GetPlayerVehicleID(playerid);
	
	if(vehId == 0)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w ¿adnym pojeŸdzie");
		return 1;
	}

	if(gVehData[vehId-1][mVehOwned] || gVehData[vehId-1][mVehFaction] != 255 || gVehData[vehId-1][BusinessID] == 255)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ten pojazd nie jest do wynajêcia");
		return 1;
	}
	
	if(gPlayerData[playerid][pIsDeptor])
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Znajdujesz siê w rejestrze d³u¿ników i nie mo¿esz wynaj¹æ tego pojazdu");
		return 1;
	}
	
	if(strlen(gVehData[vehId-1][mRenter]) > 0)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ten pojazd jest ju¿ przez kogoœ wynajmowany - nie mo¿esz teraz zmienic parametrów wynajmuj");
		return 1;
	}
	
	new string[256];
	
	format(string, sizeof(string), ""#COLOR_DEFAULT"Zamierzasz wynaj¹c pojazd za $%d dziennie.\nOp³ata za wynajem jest równa op³acie dziennej.\nKara za zniszczenie pojazdu to $%d.",
		gVehData[vehId-1][mRentPrice], gVehData[vehId-1][mRentPenalty]);
	
	ShowPlayerDialog(playerid, DIALOG_RENT_VEH, DIALOG_STYLE_MSGBOX, ""#COLOR_TITLE"Wynajem pojazdu", string, "Wynajmij", "Anuluj");
	
	return 1;
}

dcmd_wynajempojazdu(playerid, params[])
{
	new vehId = GetPlayerVehicleID(playerid);
	
	if(vehId == 0)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w ¿adnym pojeŸdzie");
		return 1;
	}
	
	if(gVehData[vehId-1][mVehOwned] || gVehData[vehId-1][mVehFaction] != 255 || gVehData[vehId-1][BusinessID] == 255)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w³aœcicielem tego pojazdu");
		return 1;
	}
	
	if(strcmp(Businesses[gVehData[vehId-1][BusinessID]][Owner], gPlayerData[playerid][pName], false) != 0)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w³aœcicielem tego pojazdu salonowego");
		return 1;
	}
	
	if(strlen(gVehData[vehId-1][mRenter]) > 0)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ten pojazd jest ju¿ przez kogoœ wynajmowany - nie mo¿esz teraz zmienic parametrów wynajmuj");
		return 1;
	}
	
	new rentPrice, rentPenalty;
	
	if(sscanf(params, "dd", rentPrice, rentPenalty))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /wynajempojazdu [cena za wynajem] [kara za zniszczenie pojazdu]");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Kwota bêdzie pobierana do kasy biznesu przy ka¿dym wynajêciu pojazdu oraz co wyp³atê a¿ do zwrotu pojazdu");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Aby anulowaæ wynajem pojazdu nale¿y u¿yæ kwoty 0");
		return 1;
	}
	
	newVehSerial(vehId-1);
	
	gVehData[vehId-1][mRentPrice] = rentPrice;
	gVehData[vehId-1][mRentPenalty] = rentPenalty;
	SaveVehData(vehId-1, "RentPrice");
	SaveVehData(vehId-1, "RentPenalty");
	
	if(gVehData[vehId-1][mRentPrice] == 0)
	{
		format(gVehData[vehId-1][Owner], MAX_PLAYER_NAME, "None");
	}
	else
	{
		format(gVehData[vehId-1][Owner], MAX_PLAYER_NAME, gPlayerData[playerid][pName]);
	}
	
	SaveVehData(vehId-1, "Owner");
	
	RefreshVehicleDescription(vehId);
	
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Pojazd zosta³ udostêpniony do wynajmu");
	
	return 1;
}
	
dcmd_zwrocpojazd(playerid, params[])
{
	#pragma unused params
	
	new vehId = GetPlayerVehicleID(playerid);
	
	if(vehId == 0)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w pojeŸdzie");
		return 1;
	}
	
	if(strcmp(gVehData[vehId-1][mRenter], gPlayerData[playerid][pName], false) != 0 || !strlen(gVehData[vehId-1][mRenter]))
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ten pojazd nie jest wynajêty przez ciebie !");
		return 1;
	}
	
	new slot[MAX_PLAYER_ITEM_SLOT], haveKeys = 0, haveAgreement = 0;
	
	slot = PHaveItemEx(playerid, 2, gVehData[vehId-1][CarSerial], slot);
	
	for(new i = 0; i < MAX_PLAYER_ITEM_SLOT; i++)
	{
		if(slot[i])
		{
			haveKeys = i+1;
			break;
		}
	}
	
	if(!haveKeys)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz ze sob¹ kluczyków do tego pojazdu");
		return 1;
	}
	
	PHaveItemEx(playerid, 3, 25, slot);
	
	for(new i = 0; i < MAX_PLAYER_ITEM_SLOT; i++)
	{
		if(slot[i])
		{
			SlotParam5(playerid, i+1);
			if(strcmp(gDSelectedItemP5[playerid], gPlayerData[playerid][pName], false) == 0 && strlen(gDSelectedItemP5[playerid]))
			{
				haveAgreement = i+1;
				break;
			}
		}
	}
	
	if(!haveAgreement)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz umowy wypo¿yczenia pojazdu");
		return 1;
	}
	
	if(!PlayerToPoint(20.0, playerid, Businesses[gVehData[vehId-1][BusinessID]][EnterX], Businesses[gVehData[vehId-1][BusinessID]][EnterY], Businesses[gVehData[vehId-1][BusinessID]][EnterZ]))
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ przy salonie z którego wypo¿yczy³eœ pojazd");
		return 1;
	}
	
	if(gVehData[vehId-1][EngineOn])
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Zgaœ silnik pojazdu");
		return 1;
	}
	
	RemovePlayerItemUsed(playerid, haveKeys);
	RemovePlayerItemUsed(playerid, haveAgreement);
	
	format(gVehData[vehId-1][mRenter], MAX_PLAYER_NAME, "");
	SaveVehData(vehId-1, "Renter");
	
	RefreshVehicleDescription(vehId);

	SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Zrezygnowa³eœ z wynajmu pojazdu");
	
	return 1;
}

dcmd_listapojazdownawynajem(playerid, params[])
{
	#pragma unused params
	
	new bId = -1, page;
	
	if(sscanf(params, "d", page))
	{
		page = 1;
	}
	
	for(new i = 0; i < sizeof(Businesses); i++)
	{
		if(!PlayerToPoint(10.0, playerid, Businesses[i][ExitX], Businesses[i][ExitY], Businesses[i][ExitZ]))
		{
			continue;
		}
		
		if(strcmp(Businesses[i][Owner], gPlayerData[playerid][pName], false) != 0 && strlen(Businesses[i][Owner]) == 0)
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ten biznes nie nale¿y do ciebie");
			return 1;
		}
		
		bId = i;
	}
	
	if(bId == -1)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ przy wyjœciu z ¿adnego biznesu");
		return 1;
	}
	
	new string[1536], count = 0;
	
	for(new i = 0; i < sizeof(gVehData); i++)
	{
		if(gVehData[i][BusinessID] == bId)
		{
			if(strlen(gVehData[i][mRenter]))
			{
				count++;
				
				if(count > page*10-10 && count <= page*10)
				{
					format(string, sizeof(string), "%s"#COLOR_BEGIN"Pojazd o rej: "#COLOR_DEFAULT"%d, "#COLOR_BEGIN"wynajêty przez: "#COLOR_DEFAULT"%s\n",
						string, gVehData[i][CarSerial], gVehData[i][mRenter]);
				}
			}
			else if(gVehData[i][mRentPrice] > 0)
			{
				count++;
				
				if(count > page*10-10 && count <= page*10)
				{
					format(string, sizeof(string), "%s"#COLOR_BEGIN"Pojazd o rej: "#COLOR_DEFAULT"%d, "#COLOR_BEGIN"wynajêty przez: "#COLOR_DEFAULT"brak\n",
						string, gVehData[i][CarSerial]);
				}
			}
		}
	}
	
	format(string, sizeof(string), "%s\n"#COLOR_BEGIN2"Strona %d\nAby wyœwietliæ pozosta³e strony u¿yj /listapojazdownawynajem [strona]", string, page);
	
	ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, ""#COLOR_TITLE"Lista pojazdów", string, "Zamknij", "");
	return 1;
}

dcmd_typbiz(playerid, params[])
{
	if(gPlayerData[playerid][pFaction] != FACTIONID_GOVERNMENT)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ urzêdnikiem");
		return 1;
	}
		
	new id = -1;
	
	for(new i = 0; i < sizeof(Businesses); i++)
	{
		if(!PlayerToPoint(2.0, playerid, Businesses[i][EnterX], Businesses[i][EnterY], Businesses[i][EnterZ]))
		{
			continue;
		}
	
		if(Businesses[i][Owned])
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz zmieniæ ceny biznesu kupionego !");
			return 1;
		}
		
		id = i;
	}
	
	if(id == -1)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ przy wejœciu do ¿adnego biznesu");
		return 1;
	}
	
	new id2;
	
	if(sscanf(params, "d", id2))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /typbiz [typ biznesu]");
		return 1;
	}
	
	Businesses[id][BizType] = id2;
	SaveBizData(id, "BizType");
	
	RefreshBizDescription(id);
	
	new string[128];
	
	format(string, sizeof string, "[INFO:] Ustawi³eœ typ biznesu o ID %d na typ %d", id, id2);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	
	return 1;
}

dcmd_cenabiz(playerid, params[])
{	
	if(gPlayerData[playerid][pFaction] != FACTIONID_GOVERNMENT)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ urzêdnikiem");
		return 1;
	}
		
	new id = -1;
	
	for(new i = 0; i < sizeof(Businesses); i++)
	{
		if(!PlayerToPoint(2.0, playerid, Businesses[i][EnterX], Businesses[i][EnterY], Businesses[i][EnterZ]))
		{
			continue;
		}
	
		if(Businesses[i][Owned])
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz zmieniæ ceny biznesu kupionego !");
			return 1;
		}
		
		id = i;
	}
	
	if(id == -1)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ przy wejœciu do ¿adnego biznesu");
		return 1;
	}
	
	new id2;
	
	if(sscanf(params, "d", id2))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /cenabiz [cena]");
		return 1;
	}

	if(id2 < 0)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Cena musi byæ wiêksza lub równa zeru");
		return 1;
	}
	
	Businesses[id][BizPrice] = id2;
	
	
	new form[128];
	format(form, sizeof form, "[INFO:] Ustawiles cene biznesu ID: %d na $%d", id,id2);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, form);
	SaveBizData(id, "BizPrice");
	
	RefreshBizDescription(id);

	// log
	format(form, sizeof(form), "[GOVERNMENT:] Business id: %d, price set up to %d by %s", id, id2, gPlayerData[playerid][pName]);
	GovermentLog(form);
	
	return 1;
}

dcmd_setalign(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
	{
		return 1;
	}
	
	new align, givePlayerId;
	
	if(sscanf(params, "dd", givePlayerId, align))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /setalign [align]");
		return 1;
	}
	
	gPlayerData[givePlayerId][pCrashAngle] = align;
	
	SetPlayerFacingAngle(givePlayerId, align);
	
	return 1;
}

dcmd_zdrowie(playerid, params[])
{
	#pragma unused params

	new string[512];
	new color[64];
	new value;
	
	if(IsPlayerVip(playerid))
	{
		format(string, sizeof(string), ""#COLOR_BEGIN2" * Stan zdrowia bohatera *\n\n");
		
		value = floatround((gPlayerData[playerid][pEnergy]*MAX_ENERGY_VIP)/100.0);
		if(value <= 15)
		{
			format(string, sizeof(string), "%s"#COLOR_BEGIN"  Energia: "#COLOR_RED_T"%d/100%%\n\n", string, floatround((gPlayerData[playerid][pEnergy]*MAX_ENERGY_VIP)/100.0));
		}
		else if(value > 15 && value <= 50)
		{
			format(string, sizeof(string), "%s"#COLOR_BEGIN"  Energia: "#COLOR_YELLOW_T"%d/100%%\n\n", string, floatround((gPlayerData[playerid][pEnergy]*MAX_ENERGY_VIP)/100.0));
		}
		else if(value > 50)
		{
			format(string, sizeof(string), "%s"#COLOR_BEGIN"  Energia: "#COLOR_GREEN_T"%d/100%%\n\n", string, floatround((gPlayerData[playerid][pEnergy]*MAX_ENERGY_VIP)/100.0));
		}
		
		
		value = floatround((gPlayerData[playerid][pHunger]*MAX_HUNGER_VIP)/100.0);
		if(value <= 20)
		{
			format(string, sizeof(string), "%s"#COLOR_BEGIN"  G³ód: "#COLOR_GREEN_T"%d/100%%\n\n", string, floatround((gPlayerData[playerid][pHunger]*MAX_HUNGER_VIP)/100.0));
		}
		else if(value > 20 && value < MAX_HUNGER_VIP)
		{
			format(string, sizeof(string), "%s"#COLOR_BEGIN"  G³ód: "#COLOR_YELLOW_T"%d/100%%\n\n", string, floatround((gPlayerData[playerid][pHunger]*MAX_HUNGER_VIP)/100.0));
		}
		else if(value >= MAX_HUNGER_VIP)
		{
			format(string, sizeof(string), "%s"#COLOR_BEGIN"  G³ód:  "#COLOR_RED_T"%d/100%%\n\n", string, floatround((gPlayerData[playerid][pHunger]*MAX_HUNGER_VIP)/100.0));
		}
		
		
		value = floatround((gPlayerData[playerid][pThirst]*MAX_THIRST_VIP)/100.0);
		if(value <= 30)
		{
			format(string, sizeof(string), "%s"#COLOR_BEGIN"  %s"#COLOR_GREEN_T"%d/100%%\n\n", string, "Pragnienie: ", floatround((gPlayerData[playerid][pThirst]*MAX_THIRST_VIP)/100.0));
		}
		else if(value > 30 && value < MAX_THIRST_VIP)
		{
			format(string, sizeof(string), "%s"#COLOR_BEGIN"  %s"#COLOR_YELLOW_T"%d/100%%\n\n", string, "Pragnienie: ", floatround((gPlayerData[playerid][pThirst]*MAX_THIRST_VIP)/100.0));
		}
		else if(value >= MAX_THIRST_VIP)
		{
			format(string, sizeof(string), "%s"#COLOR_BEGIN"  %s"#COLOR_RED_T"%d/100%%\n\n", string, "Pragnienie: ", floatround((gPlayerData[playerid][pThirst]*MAX_THIRST_VIP)/100.0));
		}
		
		
		value = floatround((gPlayerData[playerid][pVitamins]*MAX_VITAMINS_VIP)/100.0);
		if((value <= 30 && value > 0) || (value > 70 && value < MAX_VITAMINS_VIP))
		{
			format(string, sizeof(string), "%s"#COLOR_BEGIN"  %s"#COLOR_YELLOW_T"%d/100%%\n\n", string, "Witaminy: ", floatround((gPlayerData[playerid][pVitamins]*MAX_VITAMINS_VIP)/100.0));
		}
		else if(value == 0 || value == MAX_VITAMINS_VIP)
		{
			format(string, sizeof(string), "%s"#COLOR_BEGIN"  %s"#COLOR_RED_T"%d/100%%\n\n", string, "Witaminy: ", floatround((gPlayerData[playerid][pVitamins]*MAX_VITAMINS_VIP)/100.0));
		}
		else
		{
			format(string, sizeof(string), "%s"#COLOR_BEGIN"  %s"#COLOR_GREEN_T"%d/100%%\n\n", string, "Witaminy: ", floatround((gPlayerData[playerid][pVitamins]*MAX_VITAMINS_VIP)/100.0));
		}
		
		
		value = floatround((gPlayerData[playerid][pStomach]*MAX_STOMACH_VIP)/100.0);
		if(value > 80 && value < MAX_STOMACH_VIP)
		{
			format(string, sizeof(string), "%s"#COLOR_BEGIN"  %s"#COLOR_YELLOW_T"%d/100%%\n\n", string, "¯o³¹dek: ", floatround((gPlayerData[playerid][pStomach]*MAX_STOMACH_VIP)/100.0));
		}
		else if(value == MAX_STOMACH_VIP)
		{
			format(string, sizeof(string), "%s"#COLOR_BEGIN"  %s"#COLOR_RED_T"%d/100%%\n\n", string, "¯o³¹dek: ", floatround((gPlayerData[playerid][pStomach]*MAX_STOMACH_VIP)/100.0));
		}
		else
		{
			format(string, sizeof(string), "%s"#COLOR_BEGIN"  %s"#COLOR_GREEN_T"%d/100%%\n\n", string, "¯o³¹dek: ", floatround((gPlayerData[playerid][pStomach]*MAX_STOMACH_VIP)/100.0));
		}
		
		
		value = floatround((gPlayerData[playerid][pFat]*MAX_FAT_VIP)/100.0);
		if((value > 0 && value <= 30) || (value < MAX_FAT_VIP && value > 85))
		{
			format(string, sizeof(string), "%s"#COLOR_BEGIN"  %s"#COLOR_YELLOW_T"%d/100%%\n\n", string, "Cholesterol: ",floatround((gPlayerData[playerid][pFat]*MAX_FAT_VIP)/100.0));
		}
		else if(value == MAX_FAT_VIP || value == 0)
		{
			format(string, sizeof(string), "%s"#COLOR_BEGIN"  %s"#COLOR_RED_T"%d/100%%\n\n", string, "Cholesterol: ", floatround((gPlayerData[playerid][pFat]*MAX_FAT_VIP)/100.0));
		}
		else
		{
			format(string, sizeof(string), "%s"#COLOR_BEGIN"  %s"#COLOR_GREEN_T"%d/100%%\n\n", string, "Cholesterol: ", floatround((gPlayerData[playerid][pFat]*MAX_FAT_VIP)/100.0));
		}
		
		
		format(string, sizeof(string), "%s"#COLOR_BEGIN"  %s"#COLOR_DEFAULT"%d/100%%\n\n", string, "Alkohol: ", floatround((gPlayerData[playerid][pDrunk]*MAX_DRUNK_VIP)/100.0));
		format(string, sizeof(string), "%s"#COLOR_BEGIN"  %s"#COLOR_DEFAULT"%d/100%%\n\n", string, "Narkotyki: ", floatround((gPlayerData[playerid][pNarcotic]*MAX_NARCOTIC_VIP)/100.0));
	}
	else
	{
		format(string, sizeof(string), ""#COLOR_BEGIN2" * Stan zdrowia bohatera *\n\n");
		
		value = floatround((gPlayerData[playerid][pEnergy]*MAX_ENERGY)/100.0);
		if(value <= 15)
		{
			format(color, sizeof(color), #COLOR_RED_T);
		}
		else if(value > 15 && value <= 50)
		{
			format(color, sizeof(color), #COLOR_YELLOW_T);
		}
		else if(value > 50)
		{
			format(color, sizeof(color), #COLOR_GREEN_T);
		}
		format(string, sizeof(string), "%s"#COLOR_BEGIN"  Energia: %s%d/100%%\n", string, color, floatround((gPlayerData[playerid][pEnergy]*MAX_ENERGY)/100.0));
		
		value = floatround((gPlayerData[playerid][pHunger]*MAX_HUNGER)/100.0);
		if(value <= 20)
		{
			format(color, sizeof(color), #COLOR_GREEN_T);
		}
		else if(value > 20 && value < MAX_HUNGER)
		{
			format(color, sizeof(color), #COLOR_YELLOW_T);
		}
		else if(value >= MAX_HUNGER)
		{
			format(color, sizeof(color), #COLOR_RED_T);
		}
		format(string, sizeof(string), "%s"#COLOR_BEGIN"  G³ód: %s%d/100%%\n", string, color, floatround((gPlayerData[playerid][pHunger]*MAX_HUNGER)/100.0));
		
		value = floatround((gPlayerData[playerid][pThirst]*MAX_THIRST)/100.0);
		if(value <= 30)
		{
			format(color, sizeof(color), #COLOR_GREEN_T);
		}
		else if(value > 30 && value < MAX_THIRST)
		{
			format(color, sizeof(color), #COLOR_YELLOW_T);
		}
		else if(value >= MAX_THIRST)
		{
			format(color, sizeof(color), #COLOR_RED_T);
		}
		format(string, sizeof(string), "%s"#COLOR_BEGIN"  Pragnienie: %s%d/100%%\n", string, color, floatround((gPlayerData[playerid][pThirst]*MAX_THIRST)/100.0));
		
		value = floatround((gPlayerData[playerid][pVitamins]*MAX_VITAMINS)/100.0);
		if((value <= 30 && value > 0) || (value > 70 && value < MAX_VITAMINS))
		{
			format(color, sizeof(color), #COLOR_YELLOW_T);
		}
		else if(value == 0 || value == MAX_VITAMINS)
		{
			format(color, sizeof(color), #COLOR_RED_T);
		}
		else
		{
			format(color, sizeof(color), #COLOR_GREEN_T);
		}
		format(string, sizeof(string), "%s"#COLOR_BEGIN"  Witaminy: %s%d/100%%\n", string, color, floatround((gPlayerData[playerid][pVitamins]*MAX_VITAMINS)/100.0));
		
		value = floatround((gPlayerData[playerid][pStomach]*MAX_STOMACH)/100.0);
		if(value > 80 && value < MAX_STOMACH)
		{
			format(color, sizeof(color), #COLOR_YELLOW_T);
		}
		else if(value == MAX_STOMACH)
		{
			format(color, sizeof(color), #COLOR_RED_T);
		}
		else
		{
			format(color, sizeof(color), #COLOR_GREEN_T);
		}
		format(string, sizeof(string), "%s"#COLOR_BEGIN"  ¯o³¹dek: %s%d/100%%\n", string, color, floatround((gPlayerData[playerid][pStomach]*MAX_STOMACH)/100.0));
		
		value = floatround((gPlayerData[playerid][pFat]*MAX_FAT)/100.0);
		if((value > 0 && value <= 30) || (value < MAX_FAT && value > 85))
		{
			format(color, sizeof(color), #COLOR_YELLOW_T);
		}
		else if(value == MAX_FAT || value == 0)
		{
			format(color, sizeof(color), #COLOR_RED_T);
		}
		else
		{
			format(color, sizeof(color), #COLOR_GREEN_T);
		}
		format(string, sizeof(string), "%s"#COLOR_BEGIN"  Cholesterol: %s%d/100%%\n", string, color, floatround((gPlayerData[playerid][pFat]*MAX_FAT)/100.0));
		
		
		
		format(string, sizeof(string), "%s"#COLOR_BEGIN"  Alkohol: "#COLOR_DEFAULT"%d/%d\n", string, floatround(gPlayerData[playerid][pDrunk]), floatround(MAX_DRUNK));
		format(string, sizeof(string), "%s"#COLOR_BEGIN"  Narkotyki: "#COLOR_DEFAULT"%d/%d\n", string, floatround(gPlayerData[playerid][pNarcotic]), floatround(MAX_NARCOTIC));
	}
	
	ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, ""#COLOR_TITLE"Zdrowie", string, "Zamknij", "");
	
	return 1;
}

dcmd_setvipobj(playerid, params[])
{
	new vipObjCount = 0, givePlayerId;
	
	if(sscanf(params, "dd", givePlayerId, vipObjCount))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /setvipobj [givePlayerId] [vipObjCount]");
		return 1;
	}
	
	gPlayerData[givePlayerId][pVipCustomObjects] = vipObjCount;
	SavePlayerData(givePlayerId, "VipCustomObjects");
	
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Vip objects count changed");
	return 1;
}

dcmd_dodajnews(playerid, params[])
{
	#pragma unused params

	if(gPlayerData[playerid][pAdmin] == 0)
	{
		return 0;
	}
	
	ShowPlayerDialog(playerid, DIALOG_NEW_NEWS, DIALOG_STYLE_INPUT, #COLOR_TITLE"News panel", "WprowadŸ treœæ newsa:", "Dalej", "Zamknij");
	return 1;
}

dcmd_usunnews(playerid, params[])
{
	new id;
	
	if(gPlayerData[playerid][pAdmin] == 0)
	{
		return 0;
	}
	
	if(sscanf(params, "d", id))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /usunnews [id]");
		return 1;
	}
	
	if(id >= 20 || id < 0)
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /usunnews [id (0-19)]");
		return 1;
	}
	
	gSanNewsMsgs[id][mUsed] = 0;
	SaveNews(id, "Used");
	
	gSanNewsTimeLeft = 0;
	
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] News zosta³ usuniêty - lista newsów zostanie wkrótce odœwie¿ona");
	
	return 1;
}

dcmd_pokaznews(playerid, params[])
{
	new id;
	
	if(gPlayerData[playerid][pAdmin] == 0)
	{
		return 0;
	}
	
	if(sscanf(params, "d", id))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /usunnews [id]");
		return 1;
	}
	
	if(id >= 20 || id < 0)
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /usunnews [id (0-19)]");
		return 1;
	}
	
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Treœæ newsa:");
	SendClientMessage(playerid, COLOR_WHITE, gSanNewsMsgs[id][mContent]);
	
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Treœæ newsa mo¿e nie zmieœciæ ");
	
	return 1;
}

dcmd_dom(playerid, params[])
{
	#pragma unused params
	
	if(gPlayerVars[playerid][mAtHouseID] == -1)
	{
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, #COLOR_TITLE"Panel domu", #COLOR_DEFAULT"Nie jesteœ w domu.", "Zamknij", "");
		
		return 1;
	}
	
	if(strcmp(Houses[gPlayerVars[playerid][mAtHouseID]][Owner], gPlayerData[playerid][pName], false) == 0)
	{
		ShowPlayerDialog(playerid, DIALOG_HOUSE, DIALOG_STYLE_LIST, #COLOR_TITLE"Panel domu", #COLOR_DEFAULT"Sejf\nPrzedmioty\nWynajem", "Wybierz", "Zamknij");
	}
	else
	{
		ShowPlayerDialog(playerid, DIALOG_HOUSE, DIALOG_STYLE_LIST, #COLOR_TITLE"Panel domu", #COLOR_DEFAULT"Sejf\nPrzedmioty", "Wybierz", "Zamknij");
	}
	return 1;
}

dcmd_setvehicletosell(playerid, params[])
{
	new price;
	
	if(gPlayerData[playerid][pAdmin] < 5)
	{
		return 0;
	}
	
	if(sscanf(params, "d", price))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /setvehicletosell [cena sprzeda¿y]");
		return 1;
	}
	
	new vehId = GetPlayerVehicleID(playerid);
	
	if(vehId == 0)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w pojeŸdzie");
		return 1;
	}
	
	gVehData[vehId-1][mVehOwned] = 0;
	format(gVehData[vehId-1][Owner], 128, "None");
	gVehData[vehId-1][mVehFaction] = 255;
	gVehData[vehId-1][mVehType] = 0;
	gVehData[vehId-1][Price] = price;
	format(gVehData[vehId-1][mRenter], MAX_PLAYER_NAME, "");
	gVehData[vehId-1][mRentPrice] = 0;
	gVehData[vehId-1][mRentPenalty] = 0;
	
	SaveVehData(vehId-1, "VehOwned");
	SaveVehData(vehId-1, "Owner");
	SaveVehData(vehId-1, "VehFaction");
	SaveVehData(vehId-1, "VehType");
	SaveVehData(vehId-1, "Price");
	SaveVehData(vehId-1, "Renter");
	SaveVehData(vehId-1, "RentPrice");
	SaveVehData(vehId-1, "RentPenalty");
	
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Pojazd przeznaczono na sprzeda¿");
	
	return 1;
}

dcmd_setvehicletorent(playerid, params[])
{
	new rentPrice;
	
	if(gPlayerData[playerid][pAdmin] < 5)
	{
		return 0;
	}
	
	if(sscanf(params, "d", rentPrice))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /setvehicletorent [cena wynajmu]");
		return 1;
	}
	
	new vehId = GetPlayerVehicleID(playerid);
	
	if(vehId == 0)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w pojeŸdzie");
		return 1;
	}
	
	gVehData[vehId-1][mVehOwned] = 0;
	format(gVehData[vehId-1][Owner], 128, "None");
	gVehData[vehId-1][mVehFaction] = 255;
	gVehData[vehId-1][mVehType] = 0;
	format(gVehData[vehId-1][mRenter], MAX_PLAYER_NAME, "");
	gVehData[vehId-1][mRentPrice] = rentPrice;
	gVehData[vehId-1][mRentPenalty] = 0;
	
	SaveVehData(vehId-1, "VehOwned");
	SaveVehData(vehId-1, "Owner");
	SaveVehData(vehId-1, "VehFaction");
	SaveVehData(vehId-1, "VehType");
	SaveVehData(vehId-1, "Renter");
	SaveVehData(vehId-1, "RentPrice");
	SaveVehData(vehId-1, "RentPenalty");
	
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Pojazd przeznaczono na sprzeda¿");
	
	return 1;
}

/*
dcmd_abizicon(playerid, params[])
{

	if(gPlayerData[playerid][pAdmin] != 5)
	{
		return 0;
	}
	
	new bizId, iconType;
	
	if(sscanf(params, "dd", bizId, iconType))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /abizicon [bizId] [iconType]");
		return 1;
	}
	
	Businesses[bizId][IconType] = iconType;
	SaveBizData(bizId, "IconType");
	
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Biz iconType changed");

	return 1;
}*/

// dcmd_faq(playerid, params[])
// {
	// #pragma unused params
	// ShowPlayerDialog(playerid, DIALOG_FAQ, DIALOG_STYLE_LIST, "FAQ", DIALOG_HELP_MAIN_TXT, "Wybierz", "WyjdŸ");
	// return 1;
// }

// dcmd_factoryfill( playerid, params[] )
// {
	// #pragma unused params
	// new fID = gPlayerData[playerid][pFaction];
	// DynamicFactions[fID][WFactory9MM] = 1;
	// DynamicFactions[fID][WFactory9MMSil] = 1;
// }

// dcmd_fixldrzwi( playerid, params[] )
// {
	// new panels, doors, lights, tires;
	// new driver_door, passenger_door = 0;
	// new bonnet, boot = 0;
	// driver_door = doors >> 16 & 0x7;
	// passenger_door = doors >> 24 & 0x7;
	// bonnet = doors & 0x7;
    // boot = doors >> 8 & 0x7;
	// GetVehicleDamageStatus(GetPlayerVehicleID(playerid), panels, doors, lights, tires);
	// doors = encode_doors(0, 0, 0, 0, 0, 0);
	// doors = encode_doors(4, 4, 4, 4, 0, 0); // make them all fall off
	// UpdateVehicleDamageStatus(  GetPlayerVehicleID(playerid), panels, doors, lights, tires );
	// return 1;
// }

