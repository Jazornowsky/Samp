dcmd_noooc(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pModerator] == 0)
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
	if(gPlayerData[playerid][pModerator] == 0)
		return 0;
	if((gPlayerData[playerid][pAdmin] >= 2 || gPlayerData[playerid][pModerator] == 1) && (!nofooc))
	{
		nofooc = 1;
		BroadCast(COLOR_GRAD2, "   Globalny chat frakcyjny (FOOC) zostal WY£¥CZONY !");
	}
	else if((gPlayerData[playerid][pAdmin] >= 2 || gPlayerData[playerid][pModerator] == 1) && (nofooc))
	{
		nofooc = 0;
		BroadCast(COLOR_GRAD2, "   Globalny chat frakcyjny (FOOC) zostal W£¥CZONY !");
	}
	else
		SendClientMessage(playerid, COLOR_GRAD1, "[INFO:] Nie jesteœ uprawniony do u¿ywania tej komendy!");
	return 1;
}

dcmd_nopwooc(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pModerator] == 0)
		return 0;
	if((gPlayerData[playerid][pAdmin] >= 2 || gPlayerData[playerid][pModerator] == 1) && (!nopwooc))
	{
		nopwooc = 1;
		BroadCast(COLOR_GRAD2, "[INFO:] Globalny chat pw (PWOOC) zostal WY£¥CZONY !");
	}
	else if((gPlayerData[playerid][pAdmin] >= 2 || gPlayerData[playerid][pModerator] == 1) && (nopwooc))
	{
		nopwooc = 0;
		BroadCast(COLOR_GRAD2, "[INFO:] Globalny chat pw (PWOOC) zostal W£¥CZONY !");
	}
	else
		SendClientMessage(playerid, COLOR_GRAD1, "[INFO:] Nie jesteœ uprawniony do u¿ywania tej komendy!");
	return 1;
}

dcmd_radios(playerid, params[])
{
	#pragma unused params
	new idstacji;
	if(sscanf(params, "d", idstacji))
	{
		SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] /radio [nr stacji]");
		SendClientMessage(playerid,COLOR_LIGHTYELLOW2, RADIO_CHANNELS);
		SendClientMessage(playerid,COLOR_LIGHTYELLOW2, RADIO_CHANNELS2);
		return 1;
	}
	if(idstacji > 12 || idstacji < 1)
	{
		SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] Niew³aœciwy nr stacji");
		return 1;
	}
	if(IsPlayerInAnyVehicle(playerid))
	{
		new vehid = GetPlayerVehicleID(playerid);
		if(gVehData[vehid-1][RadioOn])
		{
			PlayerActionMessage(playerid,15.0,"zmienia kana³");
		}
		else
		{
			PlayerActionMessage(playerid,15.0,"w³¹cza radio");
		}
		PlayCarRadioStation(playerid, idstacji, vehid);

		return 1;
	}
	else
	{
		SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] Nie jesteœ w ¿adnym pojeŸdzie !");
		return 1;
	}
} // end of dcmd_radio

dcmd_radiosoff(playerid, params[])
{
	#pragma unused params
	new vehid = GetPlayerVehicleID(playerid);
	if(vehid == INVALID_VEHICLE_ID)
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
		SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] Niew³aœciwa frakcja");
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
	new string[128];
	new idbiz;
	if(sscanf(params, "d", idbiz))
	{
		SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] /abizdata [id biznesu]");
		return 1;
	}
	format(string, sizeof(string),"[BIZ-DATA:] EnterWorld - %d, EnterInterior - %d, ExitInterior - %d, Owned - %d, Enterable - %d, BizPrice - %d, Till - %d", Businesses[idbiz][EnterWorld],Businesses[idbiz][EnterInterior],Businesses[idbiz][ExitInterior],Businesses[idbiz][Owned],Businesses[idbiz][Enterable],Businesses[idbiz][BizPrice],Businesses[idbiz][Till]);
	SendClientMessage(playerid,COLOR_YELLOW, string);
	format(string, sizeof(string),"[BIZ-DATA:] EntranceCost - %d, Locked - %d, BizType - %d, Products - %d, PickupID - %d, MaxVehicles - %d, VehSpawned - %d", Businesses[idbiz][EntranceCost],Businesses[idbiz][Locked],Businesses[idbiz][BizType],Businesses[idbiz][Products],Businesses[idbiz][PickupID], Businesses[idbiz][MaxVehicles], Businesses[idbiz][VehicleSpawned]);
	SendClientMessage(playerid,COLOR_YELLOW, string);
	format(string, sizeof(string),"[BIZ-DATA:] VehCount - %d, VehOrderCount - %d, Confiscated - %d, Owner - %s, Interior - %d", Businesses[idbiz][VehicleCount], Businesses[idbiz][VehicleOrderCount], Businesses[idbiz][BConfiscated], Businesses[idbiz][Owner], Businesses[idbiz][BInterior]);
	SendClientMessage(playerid,COLOR_YELLOW, string);
	return 1;
}

dcmd_ahousedata(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] == 0)
		return 0;
	new string[128];
	new idhouse;
	if(sscanf(params, "d", idhouse))
	{
		SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] /ahousedata [id domu]");
		return 1;
	}
	format(string, sizeof(string),"[HOUSE-DATA:] EnterWorld - %d, EnterInterior - %d, ExitInterior - %d, Owned - %d, Rentable - %d, RentCost - %d", Houses[idhouse][EnterWorld],Houses[idhouse][EnterInterior],Houses[idhouse][ExitInterior],Houses[idhouse][Owned],Houses[idhouse][Rentable],Houses[idhouse][RentCost]);
	SendClientMessage(playerid,COLOR_YELLOW, string);
	format(string, sizeof(string),"[HOUSE-DATA:] HousePrice - %d, Materials - %d, Drugs - %d, Money - %d, Locked - %d, PickupID - %d, Confiscated - %d", Houses[idhouse][HousePrice],Houses[idhouse][Materials],Houses[idhouse][Drugs],Houses[idhouse][Money],Houses[idhouse][Locked],Houses[idhouse][PickupID],Houses[idhouse][HConfiscated]);
	SendClientMessage(playerid,COLOR_YELLOW, string);
	format(string, sizeof(string),"[HOUSE-DATA:] Interior - %d", Houses[idhouse][HInterior]);
	SendClientMessage(playerid,COLOR_YELLOW, string);
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
						format(string, sizeof(string), "[INFO:] Kupi³eœ czêœæ - koszt: $%d.", PARTS_PRICE);
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
						SendClientMessage(playerid, COLOR_RED, "[B£¥D:] Nie masz wystarczaj¹cej iloœci pieniêdzy");
						return 1;
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_RED, "[B£¥D:] Nie mo¿esz przenosiæ wiêcej ni¿ 10 czêœci.");
					return 1;
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_RED, "[B£¥D:] Nie mo¿esz przenosiæ wiêcej ni¿ 10 czêœci.");
				return 1;
			}
		}
		else
		{
			SendClientMessage(playerid,COLOR_RED, "[B£¥D:] Nie jesteœ w miejscu skupu czêœci.");
			return 1;
		}
	}
	else
	{
		SendClientMessage(playerid,COLOR_RED, "[B£¥D:] Nie jesteœ mechanikiem !");
		return 1;
	}
} // end of dcmd_kupczesci

dcmd_wyrobkarte(playerid, params[])
{
	#pragma unused params
	new Float:pPosX, Float:pPosY, Float:pPosZ;
	GetPlayerPos(playerid, pPosX, pPosY, pPosZ);
	if(PlayerToPoint(2.0, playerid, BankPosition[X], BankPosition[Y], BankPosition[Z]) || PlayerToPoint(2.0, playerid, BankPosition2[X], BankPosition2[Y], BankPosition2[Z]))
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
			SendClientMessage(playerid, COLOR_RED, "[B£¥D:] Posiadasz ju¿ karte p³atnicz¹ !");
			return 1;
		}
	}
	return 1;
}

dcmd_podladujakumulator(playerid, params[])
{
	if(gPlayerData[playerid][pJob] != 17)
	{
		SendClientMessage(playerid, COLOR_RED, "[B£¥D:] Nie jesteœ mechanikiem !");
		return 1;
	}
	if( ( !PlayerToPoint(50.0,playerid,MechanicJob1[RepairPointX],MechanicJob1[RepairPointY],MechanicJob1[RepairPointZ]) &&
	!PlayerToPoint(50.0,playerid,MechanicJob1[RepairPointX2],MechanicJob1[RepairPointY2],MechanicJob1[RepairPointZ2]) ) &&
	!PlayerToPoint(50.0,playerid,-2099.0,-2240.0,30.0 ) )
	{
		SendClientMessage(playerid, COLOR_RED, "[B£¥D:] Aby naprawiæ pojazd musisz byæ w warsztacie !");
		return 1;
	}
	if(gPlayerData[playerid][pMechanicCoolDown]> 0)
	{
		new string[128];
		format(string, sizeof(string), "[INFO:] Jesteœ ju¿ zajêty jednym pojazdem. Musisz jeszcze odczekaæ %d sekund", gPlayerData[playerid][pMechanicCoolDown]);
		SendClientMessage(playerid, COLOR_ORANGE, string);
		return 1;
	}
	new carSerial;
	if( sscanf( params, "d", carSerial ) )
	{
		SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] /podladujakumulator [rejestracja pojazdu]" );
		return 1;
	}
	new vehid = CarSerialToID(carSerial);
	if( vehid == -1 )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie ma takiego pojazdu !");
		return 1;
	}
	GetVehiclePos( vehid+1, gVehData[vehid][CarX], gVehData[vehid][CarY], gVehData[vehid][CarZ] );
	if( !PlayerToPoint( 5.0, playerid, gVehData[vehid][CarX], gVehData[vehid][CarY], gVehData[vehid][CarZ] ) )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Musisz znajdowaæ siê przy pojeŸdzie aby pod³adowaæ akumulator !" );
		return 1;
	}
	if( gVehData[vehid][BonnetUp] == 0 && !IsAMotorBike(vehid+1) )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Musisz otworzyæ maske pojazdu aby pod³adowaæ akumulator !" );
		return 1;
	}
	if( gVehData[vehid][BatteryCapacity] > 5.0 )
	{
		SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie ma potrzeby pod³adowywania akumulator !");
		return 1;
	}
	gVehData[vehid][BatteryCapacity] = 5.0;
	SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] Akumulator zosta³ pod³adowany !");
	return 1;
}

dcmd_naprawpojazd(playerid, params[])
{
	if(gPlayerData[playerid][pJob] != 17)
	{
		SendClientMessage(playerid, COLOR_RED, "[B£¥D:] Nie jesteœ mechanikiem !");
		return 1;
	}
	if( ( !PlayerToPoint(50.0,playerid,MechanicJob1[RepairPointX],MechanicJob1[RepairPointY],MechanicJob1[RepairPointZ]) &&
	!PlayerToPoint(50.0,playerid,MechanicJob1[RepairPointX2],MechanicJob1[RepairPointY2],MechanicJob1[RepairPointZ2]) ) &&
	!PlayerToPoint(50.0,playerid,-2099.0,-2240.0,30.0))
	{
		SendClientMessage(playerid, COLOR_RED, "[B£¥D:] Aby naprawiæ pojazd musisz byæ w warsztacie !");
		return 1;
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
		new Float:vehiclehp;
		GetVehicleHealth(idcar+1, vehiclehp);
		new Float:percenttorepair = 1000.0 - vehiclehp;
		gVehData[idcar][CarRepairTimeLeft] = (floatround(percenttorepair,floatround_round) * REPAIR_TIME_MULTIPLIER)/10;
		gPlayerData[playerid][pParts]--;
		SavePlayerData(playerid, "Parts");
		if(gVehData[idcar][CarRepairTimeLeft] >= 0 && gVehData[idcar][CarRepairTimeLeft] < 3)
		{
			gVehData[idcar][CarRepairTimeLeft] = 3;

			SaveVehData(idcar, "CarRepairTimeLeft");

			format(string, sizeof(string), "[INFO:] Naprawa pojazdu potrwa %d minut", gVehData[idcar][CarRepairTimeLeft]*10);

			printf("[VEHICLE:] Repaired by: %s, time left: %d", GetPlayerNameEx(playerid), gVehData[idcar][CarRepairTimeLeft]);
		}
		else
		{
			if(floatround(percenttorepair,floatround_round)/60 >= 1) // 60 = 1 minuta
			{
				format(string, sizeof(string), "[INFO:] Naprawa pojazdu potrwa %d godzin", floatround(percenttorepair,floatround_round)/60);
			}
			else
			{
				format(string, sizeof(string), "[INFO:] Naprawa pojazdu potrwa %d minut", floatround(percenttorepair,floatround_round));
			}
			printf("[VEHICLE:] Repaired by: %s, time left: %d", GetPlayerNameEx(playerid), gVehData[idcar][CarRepairTimeLeft]);
		}
		gPlayerData[playerid][pMechanicCoolDown] = 600;
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
		PlayerActionMessage(playerid,15.0,"zacz¹³ grzebaæ przy pojeŸdzie");
	}
	else
	{
		SendClientMessage(playerid, COLOR_RED, "[B£¥D:] Musisz zakupiæ czêœci zanim naprawisz pojazd !");
		return 1;
	}
	return 1;
} // end of dcmd_naprawpojazd

dcmd_specoff(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pModerator] == 0)
		return 0;
	TogglePlayerSpectating(playerid, 0);
	gSpectateID[playerid] = INVALID_PLAYER_ID;
	gSpectateType[playerid] = ADMIN_SPEC_TYPE_NONE;
	SetPlayerVirtualWorld(playerid,gPlayerData[playerid][pCrashW]);
	SetPlayerInterior(playerid,gPlayerData[playerid][pCrashInt]);

	SetPlayerHealth(playerid, gPlayerData[playerid][pHP]);
	return 1;
}

dcmd_owoj1(playerid,params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pFaction] == 6 && DynamicFactions[gPlayerData[playerid][pFaction]][fType] == 1)
	{
		SetDynamicObjectRot (bramawojsko1, 0.000000, 0.000000, 9.75);
		ArmyGate1Close();
		SendFactionMessage(6, COLOR_NATIONALGUARD,"[WSOSP:] G³ówny wjazd otwarty !");
		return 1;
	}
	else
	{
		new tmpstring[256];
		format(tmpstring, sizeof(tmpstring), "Frakcja: %d, Typ: %d",gPlayerData[playerid][pFaction], DynamicFactions[gPlayerData[playerid][pFaction]][fType]);
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Niew³aœciwa frakcja/typ.");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, tmpstring);
		return 1;
	}
}

dcmd_owoj2(playerid,params[])
{
	#pragma unused params
	#pragma unused playerid
	SetDynamicObjectRot (bramawojsko2,0.0,359.74731445313,79.8076171875);
	SetDynamicObjectRot (bramawojsko3,0.000000, 359.75, 82.370025634766);
	SendFactionMessage(6, COLOR_NATIONALGUARD,"[WSOSP:] Wjazd do wojska otwarty !");
	return 1;
}

dcmd_zwoj2(playerid,params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pFaction] == 6 && DynamicFactions[gPlayerData[playerid][pFaction]][fType] == 1 )
	{
		SetDynamicObjectRot (bramawojsko2, 0.0, 270.64294433594, 79.619995117188);
		SetDynamicObjectRot (bramawojsko3, 0.0, 88.36669921875, 85.869995117188);
		SendFactionMessage(6, COLOR_NATIONALGUARD,"[WSOSP:] Wjazd do wojska zakmniêty !");
		return 1;
	 }
	else
	{
		new tmpstring[256];
		format(tmpstring, sizeof(tmpstring), "Frakcja: %d, Typ: %d",gPlayerData[playerid][pFaction], DynamicFactions[gPlayerData[playerid][pFaction]][fType]);
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Niew³aœciwa frakcja/typ.");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, tmpstring);
		return 1;
	}
}

dcmd_zslums(playerid,params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pFaction] == 9)
	{
		SetDynamicObjectRot(slums, 0.000000, 270.74499511719, 0.25);
		SendClientMessageToAll(COLOR_URZAD,"[URZ¥D SF:] Brama do slumsów zamkniêta");
		return 1;
	}
	else
	{
		new tmpstring[256];
		format(tmpstring, sizeof(tmpstring), "Frakcja: %d, Typ: %d",gPlayerData[playerid][pFaction], DynamicFactions[gPlayerData[playerid][pFaction]][fType]);
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Niew³aœciwa frakcja/typ.");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, tmpstring);
		return 1;
	}
}

dcmd_oslums(playerid,params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pFaction] == 9)
	{
		SetDynamicObjectRot(slums, 0.000000, 0.000000, 0.000000);
		SendClientMessageToAll(COLOR_URZAD,"[URZ¥D SF:] Brama do slumsów otwarta");
		return 1;
	}
	else
	{
		new tmpstring[256];
		format(tmpstring, sizeof(tmpstring), "Frakcja: %d, Typ: %d",gPlayerData[playerid][pFaction], DynamicFactions[gPlayerData[playerid][pFaction]][fType]);
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Niew³aœciwa frakcja/typ.");
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
				SetDynamicObjectRot (bramataxi1, 0.000000, 0.000000, 100.51391601563);
				SetDynamicObjectRot (bramataxi2, 0.000000, 0.000000, 239.47448730469);
				PlayerActionMessage(playerid,15.0,"u¿ywa pilota do otwarcia szlabanu.");

			}

		}
		else if(!PlayerToPoint(7.0, playerid, -2607.9067382813, 1399.2681884766, 8.0038661956787) && !PlayerToPoint(7.0, playerid, -2607.90625, 1399.267578125, 11.403814315796) && OpenGateTaxi[playerid] == 1)
		{
			OpenGateTaxi[playerid] = 0;
			SetDynamicObjectRot (bramataxi1, 0.000000, 90, 100.51501464844);
			SetDynamicObjectRot (bramataxi2, 0.000000, 90, 239.47900390625);
			PlayerActionMessage(playerid,15.0,"u¿ywa pilota do zamkniêcia szlabanu.");

		}
	return 1;
}

dcmd_ozomo0(playerid,params[])
{
	#pragma unused params
	if( gPlayerData[playerid][pFaction] != 0 )
	{
		SendClientMessage(playerid, COLOR_RED,"[B£¥D:] Nie jesteœ z policji !");
		return 1;
	}
	if( !gPlayerData[playerid][pDuty] )
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ na s³u¿bie !");
		return 1;
	}
	if( PlayerToPoint(15.0, playerid, -1630.0, 679.0, 7.0) )
	{
		if( gMainGateZomo[0] == 0 )
		{
			gMainGateZomo[0] = 1;
			MoveDynamicObject(pdgate1a, -1644.5200,688.500000,7.468800,2);
			MoveDynamicObject(pdgate1b, -1644.5200,688.500000,7.468800,2);
			SendFactionMessage(0, COLOR_FACTIONCHAT,"(( [Radio:] SFPD: G³ówna brama otwarta ))");
			PlayerActionMessage(playerid,15.0,"u¿ywa pilota do otwarcia bramy");
		}
		else
		{
			gMainGateZomo[0] = 0;
			MoveDynamicObject(pdgate1a, -1635.600000,688.500000,7.468800,2);
			MoveDynamicObject(pdgate1b, -1627.790000,688.500000,7.468800,2);
			SendFactionMessage(0, COLOR_FACTIONCHAT,"(( [Radio:] SFPD: G³ówna brama zamkniêta ))");
			PlayerActionMessage(playerid,15.0,"u¿ywa pilota do zamkniêcia bramy");
		}
	}
	else if( PlayerToPoint(15.0, playerid, -302.0, 1507.0, 75.0) )
	{
		if( gMainGateZomo[1] == 0 )
		{
			gMainGateZomo[1] = 1;
			MoveDynamicObject(pdgate2a, -286.70373535156, 1507.1206054688, 74.4619140625, 2);
			MoveDynamicObject(pdgate2b, -308.84664916992, 1507.1439208984, 74.4619140625, 2);
			MoveDynamicObject(pdgate2c, -286.70965576172, 1507.1311035156, 77.586952209473, 2);
			MoveDynamicObject(pdgate2d, -308.87326049805, 1506.9456787109, 77.586952209473, 2);
			SendFactionMessage(0, COLOR_FACTIONCHAT,"(( [Radio:] SFPD: G³ówna brama wiêzienia otwarta ))");
			PlayerActionMessage(playerid,15.0,"u¿ywa pilota do otwarcia bramy");
		}
		else
		{
			gMainGateZomo[1] = 0;
			MoveDynamicObject(pdgate2a,-293.45800781,1507.03222656,74.46191406,2);
			MoveDynamicObject(pdgate2b,-302.32324219,1506.92089844,74.46191406,2);
			MoveDynamicObject(pdgate2c,-293.45800781,1507.03222656,77.58695221,2);
			MoveDynamicObject(pdgate2d,-302.32324219,1506.92089844,77.58695221,2);
			SendFactionMessage(0, COLOR_FACTIONCHAT,"(( [Radio:] SFPD: G³ówna brama wiêzienia otwarta ))");
			PlayerActionMessage(playerid,15.0,"u¿ywa pilota do zamkniêcia bramy");
		}
	}
	return 1;
}

dcmd_ozomo1(playerid,params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pFaction] == 0 && DynamicFactions[gPlayerData[playerid][pFaction]][fType] == 1)
	{
		SetDynamicObjectRot (zomo1, 0.000000, 0.000000, 87.340026855469);
		PoliceGate1Close();
		SendFactionMessage(0, COLOR_FACTIONCHAT,"(( [Radio:] SFPD: Wschodnia brama otwarta ))");
		return 1;
	}
	else
	{
		new tmpstring[256];
		format(tmpstring, sizeof(tmpstring), "Frakcja: %d, Typ: %d",gPlayerData[playerid][pFaction], DynamicFactions[gPlayerData[playerid][pFaction]][fType]);
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Niew³aœciwa frakcja/typ.");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, tmpstring);
		return 1;
	}
}

dcmd_ozomo2(playerid,params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pFaction] == 0 && DynamicFactions[gPlayerData[playerid][pFaction]][fType] == 1)
	{
		SetDynamicObjectRot (zomo2, 0.000000, 0.000000, 91.289978027344);
		PoliceGate2Close();
		SendFactionMessage(0, COLOR_FACTIONCHAT,"(( [Radio:] SFPD: Zachodnia brama otwarta ))");
		return 1;
	}
	else
	{
		new tmpstring[256];
		format(tmpstring, sizeof(tmpstring), "Frakcja: %d, Typ: %d",gPlayerData[playerid][pFaction], DynamicFactions[gPlayerData[playerid][pFaction]][fType]);
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[URZ¥D SF:] Niew³aœciwa frakcja/typ.");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, tmpstring);
		return 1;
	}
}

dcmd_zmost(playerid,params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pFaction] == 9)
	{
		SetDynamicObjectRot (mostpol1, 0.000000, 88.430023193359, 0.000000);
		SetDynamicObjectRot (mostpol2, 0.000000, 270.67504882813, 0.25);
		SetDynamicObjectRot (mostpol3, 0.000000, 270.87997436523, 0.000000);
		SetDynamicObjectRot (mostpol4, 0.000000, 270.67498779297, 0.000000);
		SendClientMessageToAll(COLOR_FACTIONCHAT,"(( [Radio:] Urz¹d SF: Most pó³nocny zamkniêty ))");
		return 1;
	}
	else
	{
		new tmpstring[256];
		format(tmpstring, sizeof(tmpstring), "Frakcja: %d, Typ: %d",gPlayerData[playerid][pFaction], DynamicFactions[gPlayerData[playerid][pFaction]][fType]);
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Niew³aœciwa frakcja/typ.");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, tmpstring);
		return 1;
	}
}

dcmd_omost(playerid,params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pFaction] == 9)
	{
		SetDynamicObjectRot (mostpol1, 0.000000, 0.000000, 0.0);
		SetDynamicObjectRot (mostpol2, 0.000000, 0.000000, 0.0);
		SetDynamicObjectRot (mostpol3, 0.000000, 0.000000, 0.0);
		SetDynamicObjectRot (mostpol4, 0.000000, 0.000000, 0.0);
		SendFactionMessage(9, COLOR_FACTIONCHAT,"(( [Radio:] Urz¹d SF: Most pó³nocny otwarty ))");
		return 1;
	}
	else
	{
		new tmpstring[256];
		format(tmpstring, sizeof(tmpstring), "Frakcja: %d, Typ: %d",gPlayerData[playerid][pFaction], DynamicFactions[gPlayerData[playerid][pFaction]][fType]);
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Niew³aœciwa frakcja/typ.");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, tmpstring);
		return 1;
	}
}

dcmd_ohq(playerid,params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	MoveDynamicObject(HQ,-1990.5186767578, 543.30401611328, 24.789016723633, 6.5);
	GateClose2();
	SendFactionMessage(0, COLOR_FACTIONCHAT,"(( [Radio:] SFPD: Brama g³ówna otwarta ))");
	return 1;
}

dcmd_ohq2(playerid,params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	MoveDynamicObject(HQ2,-2061.861328125, 434.58581542969, 13.348533630371, 6.5);
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
	mysql_query(string, SAVE, id, db_con2);
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

dcmd_wlamsiedopojazdu(playerid, params[])
{
	#pragma unused params
	new Hour, Minute, Second;
	gettime(Hour, Minute, Second);
	if(gPlayerData[playerid][pJob] == 10)
	{
		new id;
		new string[128];
		new Float:x,Float:y,Float:z;
		new slot;

		for(new i = 0; i < sizeof(gVehData); i++)
		{
			GetVehiclePos(i+1, x, y, z);
			if(IsPlayerInRangeOfPoint(playerid,2.0, x, y, z))
			{
				if(gVehData[i][Closed])
				{
					if(IsCarJackerOpening[playerid] == 0)
					{
						id = i;
						printf("[WARNING:] /wlamsiedopojazdu used by %s, time: %d:%d, vehicleid: %d, carserial %d, owner: %s", gPlayerData[playerid][pName], Hour, Minute, i+1, gVehData[i][Owner]);
						format(string, sizeof(string), "próbuje w³amaæ siê do pojazdu.", GetPlayerNameEx(playerid));
						PlayerActionMessage(playerid,15.0,string);
						if(gVehData[i][Alarm])
						{
							new enginedyn,lights,alarm,doors,bonnet,boot,objective;
							GetVehicleParamsEx(i+1,enginedyn,lights,alarm,doors,bonnet,boot,objective);
							SetVehicleParamsEx(i+1,enginedyn,1,1,doors,bonnet,boot,objective);
							delay:CarAlarmOff[25000](i+1);
						}
						slot = PHaveItem(playerid, 1, 1);
						if(slot != 0)
						{
							if(gPlayerData[playerid][JemmyUses] > 0)
							{
								if(Hour >= 21 || Hour <= 5)
								{
									if(gPlayerData[playerid][pCarJackerJobLvl] <= 5)
									{
										if(gVehData[id][FactionCar] == 255)
										{
											SetTimerEx("VehicleCrack", 20000, false, "dd", playerid, id);
											gPlayerData[playerid][JemmyUses]--;

											SavePlayerData(playerid, "JemmyUses");
											return 1;
										}
										else
										{
											SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie potrafisz jeszcze otwieraæ pojazdów rz¹dowych");
											return 1;
										}
									}
									else if(gPlayerData[playerid][pCarJackerJobLvl] <= 8 && gPlayerData[playerid][pCarJackerJobLvl] >= 5)
									{
										if(gVehData[id][FactionCar] == 255)
										{
											SetTimerEx("VehicleCrack", 15000, false, "dd", playerid, id);
											gPlayerData[playerid][JemmyUses]--;

											SavePlayerData(playerid, "JemmyUses");
											return 1;
										}
										else
										{
											SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie potrafisz jeszcze otwieraæ pojazdów rz¹dowych");
											return 1;
										}
									}
									else if(gPlayerData[playerid][pCarJackerJobLvl] <= 15 && gPlayerData[playerid][pCarJackerJobLvl] >= 8)
									{
										SetTimerEx("VehicleCrack2", 15000, false, "dd", playerid, id);
										gPlayerData[playerid][JemmyUses]--;

										SavePlayerData(playerid, "JemmyUses");
										return 1;
									}
									else if(gPlayerData[playerid][pCarJackerJobLvl] <= 20)
									{
										SetTimerEx("VehicleCrack2", 10000, false, "dd", playerid, id);
										gPlayerData[playerid][JemmyUses]--;

										SavePlayerData(playerid, "JemmyUses");
										return 1;
									}
								}
								else
								{
									SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Jest zbyt wczeœnie ¿eby kraœæ ! Spróbuj póŸniej");
								}
							}
							else
							{
								RemovePlayerItemExUsed(playerid, slot);

								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Twój ³om jest uszkodzony, musisz kupiæ nowy");
								return 1;
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D] Nie posiadasz ³omu");
							return 1;
						}
					}
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2,"[INFO:] Jesteœ ju¿ w trakcie otwierania pojazdu !");
					return 1;
				}
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2,"[INFO:] Pojazd jest otwarty !");
				return 1;
			}
		}
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2,"[INFO:] Nie jesteœ w pobli¿u ¿adnego pojazdu !");
		return 1;
	}
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D] Nie jesteœ z³odziejem pojazdów");
	return 1;
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
		if(gVehData[i][CarModel] == vehiclemodel)
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
		Houses[i][Materials] = 0;
		Houses[i][Drugs] = 0;
		Houses[i][Money] = 0;
		Houses[i][Locked] = 0;
		strdel(Houses[i][Owner], 0, 128);
		strins(Houses[i][Owner], "None", 0, 128);

		SaveHouseData(i, "Owned");
		SaveHouseData(i, "Rentable");
		SaveHouseData(i, "Materials");
		SaveHouseData(i, "Drugs");
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
		gVehData[i][Owned] = 0;
		strmid(gVehData[i][Owner], "None", 0, 4, 128);
		gVehData[i][CarX] = 0.0;
		gVehData[i][CarY] = 0.0;
		gVehData[i][CarZ] = 0.0;
		gVehData[i][CarAngle] = 0.0;
		gVehData[i][CarColor1] = -1;
		gVehData[i][CarColor2] = -1;
		gVehData[i][Closed] = 0;
		gVehData[i][CarFuel] = float(VehFTank(i+1));
		gVehData[i][CarHealth] = 1000.0;
		gVehData[i][BusinessID] = 255;
		gVehData[i][CarRepairTimeLeft] = 0;
		gVehData[i][CarDamaged] = 0;
		gVehData[i][CarResetT] = 0;
		gVehData[i][Price] = 0;
		gVehData[i][CarType] = 0;
		gVehData[i][FactionCar] = 255;

		DestroyVehicle(i+1);
	}
	SaveDynamicCars();

	SendAdminMessage(COLOR_YELLOW, "[INFO:] Pojazdy zosta³y zresetowane");
	return 1;
}

dcmd_acarparkdynamic(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] != HADM)
		return 0;
	if(IsPlayerInAnyVehicle(playerid))
	{
		new idcar = GetPlayerVehicleID(playerid);
		new tmpcar = GetPlayerVehicleID(playerid) - 1;
		new Float:x,Float:y,Float:z;
		new Float:a;
		GetVehiclePos(idcar, x, y, z);
		GetVehicleZAngle(idcar, a);
		gVehData[tmpcar][CarX] = x;
		gVehData[tmpcar][CarY] = y;
		gVehData[tmpcar][CarZ] = z;
		gVehData[tmpcar][CarAngle] = a;
		DestroyVehicle(idcar);
		CreateVehicle(gVehData[tmpcar][CarModel],gVehData[tmpcar][CarX],gVehData[tmpcar][CarY],gVehData[tmpcar][CarZ],gVehData[tmpcar][CarAngle],gVehData[tmpcar][CarColor1],gVehData[tmpcar][CarColor2], -1);
		SetVehLicensePlate(idcar);
		SetVehicleToRespawn(idcar);
		PutPlayerIntoVehicle(playerid,idcar,0);
		SaveVehData(tmpcar, "CarPos");
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
		return 0;
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
				format(string, sizeof(string), "[INFO:] Zosta³eœ uwiêziony przez %s na %d minut.", GetPlayerNameEx(playerid),time);
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
				//WantedPoints[playa] = 0;
				gPlayerData[playa][pJailed] = 1;
				gPlayerData[playa][pJailTime] = time*60;

				SetPlayerSkin( playa, 96 );

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
				unfreezeTPPlayer(playa);
			}
			else
			{
				if( gPlayerData[playa][pDuty] && DynamicFactions[ gPlayerData[playerid][pFaction] ][fUseSkins] )
					SetPlayerToFactionSkin(playa);
				else
					SetPlayerSkin(playa,gPlayerData[playa][pSkin]);

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

				SavePlayerData(playa, "Crash");
			}
		}
	}
	else
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Gracz nie jest online");
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

dcmd_przewodnik(playerid, params[])
{
	#pragma unused playerid
	#pragma unused params
	ShowMenuForPlayer(przewodnik, playerid);
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
		new targetID;
		if(sscanf(params, "d", targetID))
		{
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] /reanimuj [id gracza]");
			return 1;
		}
		if(targetID == playerid)
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie mo¿esz sam siebie reanimowaæ !");
			return 1;
		}
		if( gPlayerData[playerid][pCharacterDying] == 0 || AdminDuty[playerid] )
		{
			if( gPlayerData[targetID][pCharacterDying] == 0 )
			{
				SendClientMessage(playerid, COLOR_RED, "[INFO:] Ten gracz nie wymaga reanimacji !");
				return 1;
			}
			new Float:x, Float:y, Float:z;
			GetPlayerPos(targetID, x, y, z);
			if( PlayerToPoint(3.0, playerid, x, y, z ) || AdminDuty[playerid] )
			{
				PlayerPlayerActionMessage( playerid, targetID, 20.0, "reanimuje" );

				ApplyAnimation(playerid,"MEDIC","CPR",4.0, 0, 1, 1, 0, 8500, 1);
				ApplyAnimation(playerid,"MEDIC","CPR",4.0, 0, 1, 1, 0, 8500, 1);

				RPC( targetID );
			}
			else
			{
				SendClientMessage(playerid, COLOR_RED, "[INFO:] Gracz jest zbyt daleko by wykonaæ reanimacje.");
				return 1;
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Twoja postaæ jest nieprzytomna, nie mo¿e nikogo reanimowaæ !");
			return 1;
		}
	}
	else
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie jesteœ ratownikiem !");
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

dcmd_kuppojazdf(playerid, params[])
{
	#pragma unused params
	new tmpcar = GetPlayerVehicleID(playerid) - 1;
	// sprawdzene czy gracz nalezy do frakcji i jest jej liderem
	if(gPlayerData[playerid][pFaction] != 255 && gPlayerData[playerid][pRank] == 1)
	{
		// warunki zalezne od ktorych pojazd jest na sprzedaz
		if(gVehData[tmpcar][ReadyToSell] == 0 && (gVehData[tmpcar][FactionCar] != 255 || gVehData[tmpcar][Owned] == 1))
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Ten pojazd nie jest na sprzeda¿ !");
			return 1;
		}
		// sprawdzenie slotow pojazdow sprowadzonych
		for(new i = 0; i < sizeof(SpawnPlaceCars); i++)
		{
			// jesli pojazd wciaz jest w slocie to znaczy ze nie zostal jeszcze odebrany przez wlasciciela salonu
			if(SpawnPlaceCars[i][VehicleID] == tmpcar+1 || SpawnPlacePlanes[i][VehicleID] == tmpcar+1 || SpawnPlaceBoats[i][VehicleID] == tmpcar+1)
			{
				SendClientMessage(playerid, COLOR_RED, "[INFO:] Ten pojazd nie jest na sprzeda¿ !");
				return 1;
			}
		}
		// pojazd nowy - salonowy
		if(gVehData[tmpcar][Owned] == 0 && gVehData[tmpcar][CarType] == 0 && gVehData[tmpcar][FactionCar] == 255)
		{
			// sprawdzenie czy kupujacy posiada wystarczajaca ilosc pieniedzy na koncie frakcji
			if(DynamicFactions[gPlayerData[playerid][pFaction]][fBank] < floatround(gVehData[tmpcar][Price] * DynamicTaxes[VatTaxMax],floatround_round))
			{
				SendClientMessage(playerid, COLOR_WHITE, "[INFO:] Nie masz wystarczaj¹co du¿o pieniêdzy na koncie frakcji aby zakupiæ ten pojazd.");
				return 1;
			}
			// sprawdza limit pojazdow
			if(DynamicFactions[gPlayerData[playerid][pFaction]][fCarsCount] <= DynamicFactions[gPlayerData[playerid][pFaction]][fMaxCars])
			{
				// limity modeli pojazdow dla danej frakcji i/lub dodatkowe ustawienia
				if(gPlayerData[playerid][pFaction] == 0)
				{
					if(gVehData[tmpcar][CarModel] != 601 && gVehData[tmpcar][CarModel] != 599 && gVehData[tmpcar][CarModel] != 597 && gVehData[tmpcar][CarModel] != 525 && gVehData[tmpcar][CarModel] != 596 && gVehData[tmpcar][CarModel] != 598 && gVehData[tmpcar][CarModel] != 528&& gVehData[tmpcar][CarModel] != 427 && gVehData[tmpcar][CarModel] != 523 && gVehData[tmpcar][CarModel] != 497 && gVehData[tmpcar][CarModel] != 430)
					{
						SendClientMessage(playerid, COLOR_RED, "[INFO:] Ten pojazd nie mo¿e byæ zakupiony dla tej frakcji !");
						return 1;
					}
				}
				if(gPlayerData[playerid][pFaction] == 2)
				{
					if(gVehData[tmpcar][CarModel] != 487 && gVehData[tmpcar][CarModel] != 416)
					{
						SendClientMessage(playerid, COLOR_RED, "[INFO:] Ten pojazd nie mo¿e byæ zakupiony dla tej frakcji !");
						return 1;
					}
				}
				if(gPlayerData[playerid][pFaction] == 6)
				{
					if(gVehData[tmpcar][CarModel] != 433 && gVehData[tmpcar][CarModel] != 432 && gVehData[tmpcar][CarModel] != 425 && gVehData[tmpcar][CarModel] != 548 && gVehData[tmpcar][CarModel] != 470)
					{
						SendClientMessage(playerid, COLOR_RED, "[INFO:] Ten pojazd nie mo¿e byæ zakupiony dla tej frakcji !");
						return 1;
					}
				}
				if(gPlayerData[playerid][pFaction] == 7 || gPlayerData[playerid][pFaction] == 8 || gPlayerData[playerid][pFaction] == 10)
				{
					if(gVehData[tmpcar][CarModel] == 602 || gVehData[tmpcar][CarModel] == 429 || gVehData[tmpcar][CarModel] == 402 || gVehData[tmpcar][CarModel] == 541 || gVehData[tmpcar][CarModel] == 587
					|| 	gVehData[tmpcar][CarModel] == 494 || gVehData[tmpcar][CarModel] == 502 || gVehData[tmpcar][CarModel] == 559 || gVehData[tmpcar][CarModel] == 411 || gVehData[tmpcar][CarModel] == 603
					|| gVehData[tmpcar][CarModel] == 559 || gVehData[tmpcar][CarModel] == 506 || gVehData[tmpcar][CarModel] == 451 || gVehData[tmpcar][CarModel] == 477 || gVehData[tmpcar][CarModel] == 522
					|| gVehData[tmpcar][CarModel] == 495 || gVehData[tmpcar][CarModel] == 557 || gVehData[tmpcar][CarModel] == 556 || gVehData[tmpcar][CarModel] == 444 || gVehData[tmpcar][CarModel] == 504
					|| gVehData[tmpcar][CarModel] == 562 || gVehData[tmpcar][CarModel] == 560 || gVehData[tmpcar][CarModel] == 447 || gVehData[tmpcar][CarModel] == 433 || gVehData[tmpcar][CarModel] == 432
					|| gVehData[tmpcar][CarModel] == 425 || gVehData[tmpcar][CarModel] == 548 || gVehData[tmpcar][CarModel] == 470 || gVehData[tmpcar][CarModel] == 601 || gVehData[tmpcar][CarModel] == 599
					|| gVehData[tmpcar][CarModel] == 597 || gVehData[tmpcar][CarModel] == 596 || gVehData[tmpcar][CarModel] == 598 || gVehData[tmpcar][CarModel] == 528 || gVehData[tmpcar][CarModel] == 427
					|| gVehData[tmpcar][CarModel] == 523 || gVehData[tmpcar][CarModel] == 497 || gVehData[tmpcar][CarModel] == 430 || gVehData[tmpcar][CarModel] == 416)
					{
						SendClientMessage(playerid, COLOR_RED, "[INFO:] Ten pojazd nie mo¿e byæ zakupiony dla tej frakcji !");
						return 1;
					}
				}
				if(gPlayerData[playerid][pFaction] == 4)
				{
					if(gVehData[tmpcar][CarModel] != 438 && gVehData[tmpcar][CarModel] != 420 && gVehData[tmpcar][CarModel] != 409)
					{
						SendClientMessage(playerid, COLOR_RED, "[INFO:] Ten pojazd nie mo¿e byæ zakupiony dla tej frakcji !");
						return 1;
					}
					else
					{
						gVehData[tmpcar][CarType] = 0;

						SaveVehData(tmpcar, "CarType");
					}
				}
				if(gPlayerData[playerid][pFaction] == 11)
				{
					if(gVehData[tmpcar][CarModel] != 514 && gVehData[tmpcar][CarModel] != 515 && gVehData[tmpcar][CarModel] != 584)
					{
						SendClientMessage(playerid, COLOR_RED, "[INFO:] Ten pojazd nie mo¿e byæ zakupiony dla tej frakcji !");
						return 1;
					}
				}

				new string[128];
				if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fType] == 6 )
				{
					gVehData[tmpcar][Veh3DTaxiNfo] = CreateDynamic3DTextLabel("TAXI", COLOR_YELLOW, 0.0, 0.0, 3.0, INVALID_PLAYER_ID, tmpcar+1, 1);
					if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fTaxiEnterCost] > 0 )
						format( string, sizeof(string), "cena za KM: %d$ + %d$", DynamicFactions[ gPlayerData[playerid][pFaction] ][fTaxiKMCost], DynamicFactions[ gPlayerData[playerid][pFaction] ][fTaxiEnterCost] );
					else
						format( string, sizeof(string), "cena za KM: %d$", DynamicFactions[ gPlayerData[playerid][pFaction] ][fTaxiKMCost] );
					gVehData[tmpcar][Veh3DTaxiNfo2] = CreateDynamic3DTextLabel(string, COLOR_YELLOW, 0.0, 0.0, 2.7, INVALID_PLAYER_ID, tmpcar+1, 1);
				}

				gVehData[tmpcar][CarSerial] = random(2000);
				for(new i = 0; i < sizeof(gVehData); i++)
				{
					if(i != tmpcar)
					{
						if(gVehData[tmpcar][CarSerial] == gVehData[i][CarSerial])
						{
							i = 0;
							gVehData[tmpcar][CarSerial] = random(2000);
						}
					}
				}
				SaveVehData(tmpcar, "CarSerial");

				DestroyDynamic3DTextLabel( gVehData[tmpcar][Veh3DSerial] );

				if(gVehData[tmpcar][CarSerial] < 10)
				{
					format(string, sizeof(string), "SF-000%d", gVehData[tmpcar][CarSerial]);
				}
				else if(gVehData[tmpcar][CarSerial] > 10 && gVehData[tmpcar][CarSerial] < 100)
				{
					format(string, sizeof(string), "SF-00%d", gVehData[tmpcar][CarSerial]);
				}
				else if(gVehData[tmpcar][CarSerial] > 100 && gVehData[tmpcar][CarSerial] < 1000)
				{
					format(string, sizeof(string), "SF-0%d", gVehData[tmpcar][CarSerial]);
				}
				else if(gVehData[tmpcar][CarSerial] > 1000)
				{
					format(string, sizeof(string), "SF-%d", gVehData[tmpcar][CarSerial]);
				}

				if(IsAMotorBike(tmpcar+1) && gVehData[tmpcar][CarModel] != 522 && gVehData[tmpcar][CarModel] != 471 && gVehData[tmpcar][CarModel] != 468)
				{
					SetVehicleNumberPlate(tmpcar+1, string);
				}
				else if(gVehData[tmpcar][CarModel] == 522 || gVehData[tmpcar][CarModel] == 471 || gVehData[tmpcar][CarModel] == 468)
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

				// log
				new Year, Month, Day;
				getdate(Year, Month, Day);
				printf("[%d-%d-%d] [VEHICLE:] Vehicle id: %d has been bought by %s for faction ID: %d from faction ID: %d for %d$", Year, Month, Day, tmpcar+1, GetPlayerNameEx(playerid), gPlayerData[playerid][pFaction], gVehData[tmpcar][FactionCar], gVehData[tmpcar][Price]);
				// Nie wiem po kijj ten podatek tu
				//Businesses[gVehData[tmpcar][BusinessID]][Till] += floatround(gVehData[tmpcar][Price] * DynamicTaxes[VatTaxMax],floatround_round);

				// podatek od ceny pojazdu
				DynamicFactions[gPlayerData[playerid][pFaction]][fBank] -= floatround(gVehData[tmpcar][Price] * DynamicTaxes[VatTaxMax],floatround_round);

				// ustawienie frakcji pojazdu
				gVehData[tmpcar][FactionCar] = gPlayerData[playerid][pFaction];

				SaveVehData(tmpcar, "FactionCar");

				// zwolnienie slotu dla wlasciciela biznesu/salonu
				if(Businesses[gVehData[tmpcar][BusinessID]][VehicleCount] > 0)
				{
					Businesses[gVehData[tmpcar][BusinessID]][VehicleCount]--;
				}

				// zwiekszenie licznika pojazdow frakcji
				DynamicFactions[gPlayerData[playerid][pFaction]][fCarsCount]++;

				// zysk dla wlasciciela salonu
				Businesses[gVehData[tmpcar][BusinessID]][Till] += gVehData[tmpcar][Price];

				// dodatkowe ustawienia dla pojazdow publicznych zakupionych przez urzad
				if(gPlayerData[playerid][pFaction] == 9)
				{
					if(gVehData[tmpcar][CarModel] == 431 || gVehData[tmpcar][CarModel] == 437)
					{
						gVehData[tmpcar][FactionCar] = 255;
						gVehData[tmpcar][CarType] = 2;
						strmid(gVehData[tmpcar][Owner], "None", 0, 4, 128);

						SaveVehData(tmpcar, "FactionCar");
						SaveVehData(tmpcar, "CarType");
						SaveVehData(tmpcar, "Owner");

						// zmniejszenie licznika pojazdow frakcji
						DynamicFactions[gPlayerData[playerid][pFaction]][fCarsCount]--;
					}
					if(gVehData[tmpcar][CarModel] == 507) // dla WORDU
					{
						gVehData[tmpcar][FactionCar] = 255;
						gVehData[tmpcar][CarType] = 1;
						strmid(gVehData[tmpcar][Owner], "None", 0, 4, 128);

						SaveVehData(tmpcar, "FactionCar");
						SaveVehData(tmpcar, "CarType");
						SaveVehData(tmpcar, "Owner");

						// zmniejszenie licznika pojazdow frakcji
						DynamicFactions[gPlayerData[playerid][pFaction]][fCarsCount]--;
					}
					if(gVehData[tmpcar][CarModel] == 408)
					{
						gVehData[tmpcar][FactionCar] = 255;
						gVehData[tmpcar][CarType] = 4;
						strmid(gVehData[tmpcar][Owner], "None", 0, 4, 128);

						SaveVehData(tmpcar, "FactionCar");
						SaveVehData(tmpcar, "CarType");
						SaveVehData(tmpcar, "Owner");

						// zmniejszenie licznika pojazdow frakcji
						DynamicFactions[gPlayerData[playerid][pFaction]][fCarsCount]--;
					}
					if(gVehData[tmpcar][CarModel] == 574)
					{
						gVehData[tmpcar][FactionCar] = 255;
						gVehData[tmpcar][CarType] = 5;
						strmid(gVehData[tmpcar][Owner], "None", 0, 4, 128);

						SaveVehData(tmpcar, "FactionCar");
						SaveVehData(tmpcar, "CarType");
						SaveVehData(tmpcar, "Owner");

						// zmniejszenie licznika pojazdow frakcji
						DynamicFactions[gPlayerData[playerid][pFaction]][fCarsCount]--;
					}
				}

				// info dla lidera frakcji
				format(string, sizeof(string), "[INFO:] Kupi³eœ pojazd na frakcje za %d$", gVehData[tmpcar][Price]);
				SendClientMessage(playerid, COLOR_GREEN, string);
				return 1;
			}

			// info dla lidera frakcji
			new string[128];
			format(string, sizeof(string), "[INFO:] Osi¹gn¹³eœ limit pojazdów dla frakcji (%d) !", DynamicFactions[gPlayerData[playerid][pFaction]][fMaxCars]);
			SendClientMessage(playerid, COLOR_RED, string);
		}
		// pojazd uzywany
		if(gVehData[tmpcar][ReadyToSell])
		{
			// sprawdzenie ilosci pieniedzy
			if(DynamicFactions[gPlayerData[playerid][pFaction]][fBank] < gVehData[tmpcar][Price])
			{
				SendClientMessage(playerid, COLOR_WHITE, "[INFO:] Nie masz wystarczaj¹co du¿o pieniêdzy na koncie frakcji aby zakupiæ ten pojazd.");
				return 1;
			}
			// sprawdza limit pojazdow
			if(DynamicFactions[gPlayerData[playerid][pFaction]][fCarsCount] <= DynamicFactions[gPlayerData[playerid][pFaction]][fMaxCars])
			{
				// limity modeli pojazdow dla danej frakcji i/lub dodatkowe ustawienia
				if(gPlayerData[playerid][pFaction] == 0)
				{
					if(gVehData[tmpcar][CarModel] != 601 && gVehData[tmpcar][CarModel] != 599 && gVehData[tmpcar][CarModel] != 597 && gVehData[tmpcar][CarModel] != 525 && gVehData[tmpcar][CarModel] != 596 && gVehData[tmpcar][CarModel] != 598 && gVehData[tmpcar][CarModel] != 528&& gVehData[tmpcar][CarModel] != 427 && gVehData[tmpcar][CarModel] != 523 && gVehData[tmpcar][CarModel] != 497 && gVehData[tmpcar][CarModel] != 430)
					{
						SendClientMessage(playerid, COLOR_RED, "[INFO:] Ten pojazd nie mo¿e byæ zakupiony dla tej frakcji !");
						return 1;
					}
				}
				if(gPlayerData[playerid][pFaction] == 2)
				{
					if(gVehData[tmpcar][CarModel] != 487 && gVehData[tmpcar][CarModel] != 416)
					{
						SendClientMessage(playerid, COLOR_RED, "[INFO:] Ten pojazd nie mo¿e byæ zakupiony dla tej frakcji !");
						return 1;
					}
				}
				if(gPlayerData[playerid][pFaction] == 6)
				{
					if(gVehData[tmpcar][CarModel] != 433 && gVehData[tmpcar][CarModel] != 432 && gVehData[tmpcar][CarModel] != 425 && gVehData[tmpcar][CarModel] != 548 && gVehData[tmpcar][CarModel] != 470)
					{
						SendClientMessage(playerid, COLOR_RED, "[INFO:] Ten pojazd nie mo¿e byæ zakupiony dla tej frakcji !");
						return 1;
					}
				}
				if(gPlayerData[playerid][pFaction] == 7 || gPlayerData[playerid][pFaction] == 8 || gPlayerData[playerid][pFaction] == 10)
				{
					if(gVehData[tmpcar][CarModel] == 602 || gVehData[tmpcar][CarModel] == 429 || gVehData[tmpcar][CarModel] == 402 || gVehData[tmpcar][CarModel] == 541 || gVehData[tmpcar][CarModel] == 587
					|| 	gVehData[tmpcar][CarModel] == 494 || gVehData[tmpcar][CarModel] == 502 || gVehData[tmpcar][CarModel] == 559 || gVehData[tmpcar][CarModel] == 411 || gVehData[tmpcar][CarModel] == 603
					|| gVehData[tmpcar][CarModel] == 559 || gVehData[tmpcar][CarModel] == 506 || gVehData[tmpcar][CarModel] == 451 || gVehData[tmpcar][CarModel] == 477 || gVehData[tmpcar][CarModel] == 522
					|| gVehData[tmpcar][CarModel] == 495 || gVehData[tmpcar][CarModel] == 557 || gVehData[tmpcar][CarModel] == 556 || gVehData[tmpcar][CarModel] == 444 || gVehData[tmpcar][CarModel] == 504
					|| gVehData[tmpcar][CarModel] == 562 || gVehData[tmpcar][CarModel] == 560 || gVehData[tmpcar][CarModel] == 447 || gVehData[tmpcar][CarModel] == 433 || gVehData[tmpcar][CarModel] == 432
					|| gVehData[tmpcar][CarModel] == 425 || gVehData[tmpcar][CarModel] == 548 || gVehData[tmpcar][CarModel] == 470 || gVehData[tmpcar][CarModel] == 601 || gVehData[tmpcar][CarModel] == 599
					|| gVehData[tmpcar][CarModel] == 597 || gVehData[tmpcar][CarModel] == 596 || gVehData[tmpcar][CarModel] == 598 || gVehData[tmpcar][CarModel] == 528 || gVehData[tmpcar][CarModel] == 427
					|| gVehData[tmpcar][CarModel] == 523 || gVehData[tmpcar][CarModel] == 497 || gVehData[tmpcar][CarModel] == 430 || gVehData[tmpcar][CarModel] == 416)
					{
						SendClientMessage(playerid, COLOR_RED, "[INFO:] Ten pojazd nie mo¿e byæ zakupiony dla tej frakcji !");
						return 1;
					}
				}
				if(gPlayerData[playerid][pFaction] == 4)
				{
					if(gVehData[tmpcar][CarModel] != 438 && gVehData[tmpcar][CarModel] != 420 && gVehData[tmpcar][CarModel] != 409)
					{
						SendClientMessage(playerid, COLOR_RED, "[INFO:] Ten pojazd nie mo¿e byæ zakupiony dla tej frakcji !");
						return 1;
					}
					else
					{
						gVehData[tmpcar][CarType] = 3;

						SaveVehData(tmpcar, "CarType");

						if(gVehData[tmpcar][CarSerial] == 0)
						{
							gVehData[tmpcar][CarSerial] = random(2000);
							for(new i = 0; i < sizeof(gVehData); i++)
							{
								if(i != tmpcar)
								{
									if(gVehData[tmpcar][CarSerial] == gVehData[i][CarSerial])
									{
										i = 0;
										gVehData[tmpcar][CarSerial] = random(2000);

										SaveVehData(tmpcar, "CarSerial");
									}
								}
							}
						}
					}
				}
				if(gPlayerData[playerid][pFaction] == 11)
				{
					if(gVehData[tmpcar][CarModel] != 514 && gVehData[tmpcar][CarModel] != 515 && gVehData[tmpcar][CarModel] != 584)
					{
						SendClientMessage(playerid, COLOR_RED, "[INFO:] Ten pojazd nie mo¿e byæ zakupiony dla tej frakcji !");
						return 1;
					}
				}
				if(gVehData[tmpcar][CarType] != 6 && gVehData[tmpcar][CarType] != 3)
				{
					gVehData[tmpcar][CarType] = 0;

					SaveVehData(tmpcar, "CarType");
				}
				new slot;
				// pojazd uzywany - prywatny
				if(gVehData[tmpcar][Owned] == 1 && gVehData[tmpcar][FactionCar] == 255)
				{
					new tmpplname[128];
					new string[128];
					foreach(Player, i )
					{
						GetPlayerName(i, tmpplname, sizeof(tmpplname));

						// sprawdza czy dany gracz jest wlascicielem sprzedawanego pojazdu
						slot = PHaveItem(i, 2, gVehData[tmpcar][CarSerial]);
						if(slot != 0 && strcmp(tmpplname, gVehData[tmpcar][Owner], true, strlen(gVehData[tmpcar][Owner])) == 0)
						{
							// przekazanie pieniedzy sprzedajacemu
							GivePlayerCash(i, gVehData[tmpcar][Price]);

							// wyzerowanie slotu sprzedajacemu pojazd
							RemovePlayerItemExUsed(i, slot);

							// pobranie pieniedzy od frakcji/lidera
							DynamicFactions[gPlayerData[playerid][pFaction]][fBank] -= gVehData[tmpcar][Price];

							// ustawienie danych pojazdu
							gVehData[tmpcar][FactionCar] = gPlayerData[playerid][pFaction];
							gVehData[tmpcar][Owned] = 0;
							strmid(gVehData[tmpcar][Owner], "None", 0, 4, 128);
							gVehData[tmpcar][ReadyToSell] = 0;

							SaveVehData(tmpcar, "FactionCar");
							SaveVehData(tmpcar, "CarType");
							SaveVehData(tmpcar, "Owned");
							SaveVehData(tmpcar, "Owner");
							SaveVehData(tmpcar, "ReadyToSell");

							// zwiekszenie licznika pojazdow frakcji
							DynamicFactions[gPlayerData[playerid][pFaction]][fCarsCount]++;

							// usuniecie napisow z pojazdu
							DestroyDynamic3DTextLabel( gVehData[tmpcar][Veh3DSell] );

							if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fType] == 6 )
							{
								gVehData[tmpcar][Veh3DTaxiNfo] = CreateDynamic3DTextLabel("TAXI", COLOR_YELLOW, 0.0, 0.0, 3.0, INVALID_PLAYER_ID, tmpcar+1, 1);
								if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fTaxiEnterCost] > 0 )
									format( string, sizeof(string), "cena za KM: %d$ + %d$", DynamicFactions[ gPlayerData[playerid][pFaction] ][fTaxiKMCost], DynamicFactions[ gPlayerData[playerid][pFaction] ][fTaxiEnterCost] );
								else
									format( string, sizeof(string), "cena za KM: %d$", DynamicFactions[ gPlayerData[playerid][pFaction] ][fTaxiKMCost] );
								gVehData[tmpcar][Veh3DTaxiNfo2] = CreateDynamic3DTextLabel(string, COLOR_YELLOW, 0.0, 0.0, 2.7, INVALID_PLAYER_ID, tmpcar+1, 1);
							}

							// dodatkowe ustawienia dla pojazdow publicznych zakupionych przez urzad
							if(gPlayerData[playerid][pFaction] == 9)
							{
								if(gVehData[tmpcar][CarModel] == 431 || gVehData[tmpcar][CarModel] == 437)
								{
									gVehData[tmpcar][FactionCar] = 255;
									gVehData[tmpcar][CarType] = 2;
									strmid(gVehData[tmpcar][Owner], "None", 0, 4, 128);

									SaveVehData(tmpcar, "FactionCar");
									SaveVehData(tmpcar, "CarType");
									SaveVehData(tmpcar, "Owner");

									// zmniejszenie licznika pojazdow frakcji
									DynamicFactions[gPlayerData[playerid][pFaction]][fCarsCount]--;
								}
								if(gVehData[tmpcar][CarModel] == 507) // dla WORDU
								{
									gVehData[tmpcar][FactionCar] = 255;
									gVehData[tmpcar][CarType] = 1;
									strmid(gVehData[tmpcar][Owner], "None", 0, 4, 128);

									SaveVehData(tmpcar, "FactionCar");
									SaveVehData(tmpcar, "CarType");
									SaveVehData(tmpcar, "Owner");

									// zmniejszenie licznika pojazdow frakcji
									DynamicFactions[gPlayerData[playerid][pFaction]][fCarsCount]--;
								}
								if(gVehData[tmpcar][CarModel] == 408)
								{
									gVehData[tmpcar][FactionCar] = 255;
									gVehData[tmpcar][CarType] = 4;
									strmid(gVehData[tmpcar][Owner], "None", 0, 4, 128);

									SaveVehData(tmpcar, "FactionCar");
									SaveVehData(tmpcar, "CarType");
									SaveVehData(tmpcar, "Owner");

									// zmniejszenie licznika pojazdow frakcji
									DynamicFactions[gPlayerData[playerid][pFaction]][fCarsCount]--;
								}
								if(gVehData[tmpcar][CarModel] == 574)
								{
									gVehData[tmpcar][FactionCar] = 255;
									gVehData[tmpcar][CarType] = 5;
									strmid(gVehData[tmpcar][Owner], "None", 0, 4, 128);

									SaveVehData(tmpcar, "FactionCar");
									SaveVehData(tmpcar, "CarType");
									SaveVehData(tmpcar, "Owner");

									// zmniejszenie licznika pojazdow frakcji
									DynamicFactions[gPlayerData[playerid][pFaction]][fCarsCount]--;
								}

								// informacja dla kupujacego
								format(string, sizeof(string), "[INFO:] Kupi³eœ pojazd na frakcje za %d$", gVehData[tmpcar][Price]);
								SendClientMessage(playerid, COLOR_GREEN, string);

								// informacja dla sprzedajacego
								format(string, sizeof(string), "[INFO:] Gracz %s [%d] kupi³ od Ciebie pojazd !", GetPlayerNameEx(playerid), playerid);
								SendClientMessage(i, COLOR_LIGHTYELLOW2, string);
								return 1;
							}
						}
					}
					// informacja dla kupujacego
					SendClientMessage(playerid, COLOR_RED, "[INFO:] W³aœciciela pojazdu nie ma obecnie na serwerze. Musisz poczekaæ na jego przybycie jeœli chcesz kupiæ ten pojazd !");
					return 1;
				}
				// samochod uzywany - frakcyjny
				if(gVehData[tmpcar][Owned] == 0 && gVehData[tmpcar][FactionCar] != 255)
				{
					// zysk dla frakcji sprzedajacej pojazd
					DynamicFactions[gVehData[tmpcar][FactionCar]][fBank] += gVehData[tmpcar][Price];

					// zmniejszenie licznika posiadanych pojazdow przez frakcje
					if(DynamicFactions[gVehData[tmpcar][FactionCar]][fCarsCount] > 0)
					{
						DynamicFactions[gVehData[tmpcar][FactionCar]][fCarsCount]--;
					}

					// zmniejszenie ilosci posiadanych pojazdow przez frakcje
					DynamicFactions[gPlayerData[playerid][pFaction]][fCarsCount]++;

					if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fType] == 6 )
					{
						DestroyDynamic3DTextLabel( gVehData[tmpcar][Veh3DTaxiNfo] );
						DestroyDynamic3DTextLabel( gVehData[tmpcar][Veh3DTaxiNfo2] );
					}

					// ustawienie danych pojazdu
					gVehData[tmpcar][FactionCar] = gPlayerData[playerid][pFaction];
					gVehData[tmpcar][ReadyToSell] = 0;

					SaveVehData(tmpcar, "FactionCar");
					SaveVehData(tmpcar, "ReadyToSell");

					// usuniecie napisow znad pojazdu
					DestroyDynamic3DTextLabel( gVehData[tmpcar][Veh3DSell] );
					if( DynamicFactions[ gVehData[tmpcar][FactionCar] ][fType] == 6 )
					{
						new string[128];
						if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fType] == 6 )
						{
							gVehData[tmpcar][Veh3DTaxiNfo] = CreateDynamic3DTextLabel("TAXI", COLOR_YELLOW, 0.0, 0.0, 3.0, INVALID_PLAYER_ID, tmpcar+1, 1);
							if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fTaxiEnterCost] > 0 )
								format( string, sizeof(string), "cena za KM: %d$ + %d$", DynamicFactions[ gPlayerData[playerid][pFaction] ][fTaxiKMCost], DynamicFactions[ gPlayerData[playerid][pFaction] ][fTaxiEnterCost] );
							else
								format( string, sizeof(string), "cena za KM: %d$", DynamicFactions[ gPlayerData[playerid][pFaction] ][fTaxiKMCost] );
							gVehData[tmpcar][Veh3DTaxiNfo2] = CreateDynamic3DTextLabel(string, COLOR_YELLOW, 0.0, 0.0, 2.7, INVALID_PLAYER_ID, tmpcar+1, 1);
						}
					}

					// informacja dla kupujacego
					new string[128];
					format(string, sizeof(string), "[INFO:] Kupi³eœ pojazd na frakcje za %d$", gVehData[tmpcar][Price]);
					SendClientMessage(playerid, COLOR_GREEN, string);
					return 1;
				}
			}
			else
			{
				// informacja dla kupujacego
				SendClientMessage(playerid, COLOR_RED, "[INFO:] Osi¹gniêto limit pojazdów we frakcji ! Nie mo¿esz kupiæ nowego pojazdu !");
				return 1;
			}
		}
	}
	else
	{
		// informacja dla kupujacego
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie jesteœ liderem ¿adnej frakcji !");
		return 1;
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
		if(gPlayerData[playerid][pRank] == 1)
		{
			if(floatround(gVehData[tmpcar][Price] * 0.20, floatround_round) < DynamicFactions[gPlayerData[playerid][pFaction]][fBank])
			{
				if( gVehData[tmpcar][FactionCar] == 255 )
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz zez³omowaæ tego pojazdu !");
					return 1;
				}
				if(gVehData[tmpcar][FactionCar] != gPlayerData[playerid][pFaction])
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ten pojazd nie nale¿y do Twojej frakcji !");
					return 1;
				}
				new string[128];

				DynamicFactions[gVehData[tmpcar][FactionCar]][fBank] -= floatround(gVehData[tmpcar][Price] * 0.20, floatround_round);
				DynamicFactions[FACTIONID_GOVERNMENT][fBank] += floatround(gVehData[tmpcar][Price] * 0.20, floatround_round);

				SaveFData(gVehData[tmpcar][FactionCar], "Bank");
				SaveFData(FACTIONID_GOVERNMENT, "Bank");

				gVehData[tmpcar][CarModel] = 0;
				gVehData[tmpcar][CarX] = 0.0;
				gVehData[tmpcar][CarY] = 0.0;
				gVehData[tmpcar][CarZ] = 0.0;
				gVehData[tmpcar][CarAngle] = 0.0;
				gVehData[tmpcar][CarColor1] = -1;
				gVehData[tmpcar][CarColor2] = -1;
				if(gVehData[tmpcar][FactionCar] != 255)
				{
					if(!(DynamicFactions[gVehData[tmpcar][FactionCar]][fCarsCount] <= 0))
					{
						DynamicFactions[gVehData[tmpcar][FactionCar]][fCarsCount]--;
					}
				}
				gVehData[tmpcar][FactionCar] = 255;
				gVehData[tmpcar][CarType] = 0;
				gVehData[tmpcar][Owned] = 0;
				strmid(gVehData[tmpcar][Owner], "None", 0, 4, 128);
				gVehData[tmpcar][Price] = 0;
				gVehData[tmpcar][Closed] = 0;
				gVehData[tmpcar][CarResetT] = 0;
				gVehData[tmpcar][CarDamaged] = 0;
				gVehData[tmpcar][CarRepairTimeLeft] = 0;
				gVehData[tmpcar][BusinessID] = 255;
				gVehData[tmpcar][CarFuel] = float(VehFTank(idcar));
				gVehData[tmpcar][CarHealth] = 1000.0;

				SaveVehData(tmpcar, "CarModel");
				SaveVehData(tmpcar, "CarPos");
				SaveVehData(tmpcar, "CarColor1");
				SaveVehData(tmpcar, "CarColor2");
				SaveVehData(tmpcar, "FactionCar");
				SaveVehData(tmpcar, "CarType");
				SaveVehData(tmpcar, "Owned");
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
				ResetVehicleData(idcar,1);
				TogglePlayerControllable(playerid, 1);

				format(string, sizeof(string), "[INFO:] Zez³omowa³eœ pojazd frakcji");
				SendClientMessage(playerid, COLOR_GREEN, string);

				SaveFData(4, "CarsCount");
				return 1;
			}
			else
			{
				new string[128];
				format(string, sizeof(string), "[INFO:] Nie masz wystarczaj¹cej iloœci pieniêdzy na koncie frakcji aby zez³omowaæ pojazd (%d$) !", floatround(gVehData[tmpcar][Price] * 0.20, floatround_round));
				SendClientMessage(playerid, COLOR_RED, string);
				return 1;
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie jesteœ liderem frakcji !");
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
	if(gPlayerData[playerid][pBizKey] == 255)
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie jesteœ w³aœcicielem ¿adnego biznesu !");
		return 1;
	}
	if(Businesses[gPlayerData[playerid][pBizKey]][BizType] != 10)
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Niew³aœciwy typ biznesu !");
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
	if(Businesses[gPlayerData[playerid][pBizKey]][Till] >= cenyPojazdow[modelID-400])
	{
		if((Businesses[gPlayerData[playerid][pBizKey]][VehicleCount] + Businesses[gPlayerData[playerid][pBizKey]][VehicleOrderCount]) < Businesses[gPlayerData[playerid][pBizKey]][MaxVehicles])
		{
			for(new n = 0; n < sizeof(CarsData); n++)
			{
				if(CarsData[n][Model] == modelID)
				{
					if(CarsData[n][Paliwo] == fuelType)
					{
						isFuelType = 1;
						break;
					}
				}
			}
			if(isFuelType == 0)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ten pojazd nie wystêpuje z tego typu silnikiem");
				return 1;
			}
			new plname[MAX_PLAYER_NAME];
			GetPlayerName(playerid, plname, sizeof(plname));
			ImportVeh(gPlayerData[playerid][pBizKey], modelID, plname, fuelType);

			format(string, sizeof(string), "[INFO:] Twój pojazd jest gotowy do odebrania. Koszt: %d$", cenyPojazdow[modelID-400]);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Pamiêtaj ¿e kwota pieniêdzy wyznaczona za pojazd pobierana jest dopiero w momencie sprowadzenia pojazdu !");
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "        Jeœli w kasie biznesu nie bêdzie wystarczaj¹cej iloœci pieniêdzy samochód zostanie odes³any !");

			Businesses[gPlayerData[playerid][pBizKey]][VehicleOrderCount]++;

			SaveBizData(gPlayerData[playerid][pBizKey], "VehicleOrderCount");
			return 1;
		}
		else
		{
			format(string, sizeof(string), "[INFO:] Osi¹gn¹³eœ limit iloœci pojazdów dla tego biznesu (%d)", Businesses[gPlayerData[playerid][pBizKey]][MaxVehicles]);
			SendClientMessage(playerid, COLOR_RED, string);
			return 1;
		}
	}
	else
	{
		format(string, sizeof(string), "[INFO:] Nie wystarczaj¹ca iloœæ pieniêdzy w kasie biznesu do sprowadzenia pojazdu ! Koszt: %d$", cenyPojazdow[modelID-400]);
		SendClientMessage(playerid, COLOR_RED, string);
		return 1;
	}
}

dcmd_statuszamowien(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pBizKey] == 255)
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie jesteœ w³aœcicielem ¿adnego biznesu !");
		return 1;
	}
	if(Businesses[gPlayerData[playerid][pBizKey]][BizType] != 10)
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Niew³aœciwy typ biznesu !");
		return 1;
	}
	if(Businesses[gPlayerData[playerid][pBizKey]][VehicleOrderCount] == 0)
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Aktualnie nie masz aktywnych zamówieñ");
		return 1;
	}
	new string[128];
	format(string, sizeof(string), "[INFO:] Aktualnie masz %d aktywnych zamówieñ", Businesses[gPlayerData[playerid][pBizKey]][VehicleOrderCount]);
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
	if(gPlayerData[playerid][pBizKey] == 255)
	{
		SendClientMessage(playerid,COLOR_RED, "[INFO:] Nie jesteœ w³aœcicielem salonu !");
		return 1;
	}
	if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
	{
		SendClientMessage(playerid,COLOR_RED, "[INFO:] Musisz byæ w pojeŸdzie aby ustaliæ jego cene !");
		return 1;
	}
	if(gPlayerData[playerid][pBizKey] != gVehData[vehicleID-1][BusinessID])
	{
		SendClientMessage(playerid,COLOR_RED, "[INFO:] Nie mo¿esz zmieniæ ceny tego pojazdu !");
		return 1;
	}
	format(string, sizeof(string), "[INFO:] Zmieni³eœ cene pojazdu na %d$", cena);
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
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[ADMIN:] /ban - /unban - /banaccount - /unbanaccount - /getip - /update - /error - /retaketut - /setvw - disarm");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[ADMIN:] /checkweapons - /prison - /unprison - /name - /destroy - /setskin - /explode - /slap - /asetleader");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[ADMIN:] /aplayerbizid - /resetpracy - /additem - /rmplayeritem - /playeritems - /spec - /specoff - /getip");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[ADMIN:] /error - /setvw - /disarm - /checkweapons - /prison - /unprison - /name - /destroy - /setskin - /explode");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[ADMIN:] /slap - /banaccount - /mbanaccount - /asetplayervipafk - /asetplayervipafkt - /asetplayervipexp");
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
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[ADMIN:] /afactionmatsstoraga - /afactiondrugsstorage - /afactionspawn - /aresetfaction - /afactioncolor");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[ADMIN:] /afactionuseskins - /afactionname - /afactiontype - /afactionjoinrank - /afactionbank - /afactiondrugs");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[ADMIN:] /afactionmats - /afactionrankamount - /afactionrankname - /afactionskin - /afactionusecolor");
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
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[ADMIN:] /rtc - /supervehslap - /afuelcar - /fixveh - /fixveh2 - /agetcar - /acarlocations - /moatv - /rotvobj - /mvvobj - /rvobj");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[ADMIN:] /acarsreset - /arepairallvehicles - /acarpark(dynamic) - /acarmodelprice - /acarmodel - /afactioncar - /vehtypelist");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[ADMIN:] /acarcolor(ex) - /acartype - /acarenter - /acarsetpos - /acardata - /acarint - /acarbiz - /acarrepairtl - /fullbattery");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[ADMIN:] /acarresett - /acarclosed - /acarkm - /acarbusinessid - /acarreadytosell - /setcar(r)serial - /fullbatteries");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[ADMIN:] /setcarserialtoall - /acarcomponentslot - /acaraddcomponent - /acarcomponentslottype - /avehfueltype");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[ADMIN:] /offvehlights - /offvehradio - /setvehhp");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "================================================================================================================================");
	return 1;
}

dcmd_abuildingcmds(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] == 0)
		return 0;
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "================================================================================================================================");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[ADMIN:] /abuildingint - /abuildingentrance - /agotobuilding - /abuldinglock - /abuildingexit - /abuildingname");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[ADMIN:] /abuildingfee - /abuildingcloset - /abuildingopent");
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
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[ADMIN:] /houseplaced - /houseintset");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "================================================================================================================================");
	return 1;
}

dcmd_abusinesscmds(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] == 0)
		return 0;
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "================================================================================================================================");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[ADMIN:] /abizdata - /agotobiz - /abizproducts - /abizprice - /abiztype - /abizentrance - /bizplaced - /bizintset");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[ADMIN:] /abizexit - /abizint - /abizname - /abizsell - /abizreset - /abizowner - /abizconfiscated");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[ADMIN:] /aplayerbizid - /abusinessmaxcars - /abizvehorders - /abizvehcount - /abizvehspawned - /gspos - /abizlock");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[ADMIN:] /abusinesstill - /abizidtogasstation - /asetgasstationresources - /asetgasstationmaxresources - /asetgasstationfuelprice - /gstl2pos - /gstl1pos");
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
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[ADMIN:] /afactionmatsstorage - /agotofdrugsstorage - /afactiondrugsstorage - /abankpos - /agotoweaponlicensepos");
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
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[ADMIN:] /aproductjobpos - /aproductjobpos2 - /agunjobpos - /agunjobpos2 - /agunjobpos3 - /afarmerjobpos");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[ADMIN:] /abusjobpos - /amzgkjobpos - /asweeperjobpos - /ataxijobpos - /anewsboyjobpos - /anewsboyjobreward - /anewsboyjobpapers");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[ADMIN:] /afactionspawn - /agotofaction - /gotols - /gotosf - /gotolv - /gotoprison - /gotohosp");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "================================================================================================================================");
	return 1;
}

dcmd_umowaoc(playerid, params[])
{
	new form[256];
	new givePlayerID;
	new slot;
	new level;
	if(sscanf(params, "ddd", givePlayerID, slot, level))
	{
		SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] /umowaoc [id gracza] [slot] [poziom oc]");
		SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] slot: (1-15)");
		SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] poziom: 1 - 2 - 3");
		return 1;
	}
	if(gPlayerData[playerid][pFaction] != 9)
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie jesteœ urzêdnikiem !");
		return 1;
	}
	if(!IsPlayerConnected(givePlayerID))
	{
		SendClientMessage(playerid,COLOR_RED,"[INFO:] Podany gracz nie jest on-line !");
		return 1;
	}
	if(PItemSlotStatus(givePlayerID, slot) == 0)
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten slot postaci jest pusty !");
		return 1;
	}
	if(!PSlotItemTypeCompare(givePlayerID, slot, 2))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Na tym slocie ta osoba nie posiada kluczyków do ¿adnego pojazdu !");
		return 1;
	}
	if(SlotParam1(givePlayerID, slot) != 0)
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ta osoba podpisa³a ju¿ umowe OC !");
		return 1;
	}
	if(level == 1)
	{
		new Float:x, Float:y, Float:z;
		GetPlayerPos(givePlayerID,x,y,z);
		if(!PlayerToPoint(4, playerid, x, y, z))
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Jesteœ zbyt daleko od tej osoby !");
			return 1;
		}
		EnsuranceOC[givePlayerID][vehicleNr] = slot;
		EnsuranceOC[givePlayerID][Level] = 1;
		PlayerPlayerActionMessage(playerid, givePlayerID, 10.0, "przekaza³ umowe");
		SendClientMessage(givePlayerID, COLOR_LIGHTYELLOW2, "[INFO:] Koszt podpisania umowy wynosi 2000$");

		// log
		format(form, sizeof(form), "[GOVERNMENT:] OC agreement lev 1 prepeared by %s for %s, veh serial %d",gPlayerData[playerid][pName], gPlayerData[givePlayerID][pName], ShowSlotItem(givePlayerID, slot));
		print(form);
		GovermentLog(form);

		return 1;
	}
	if(level == 2)
	{
		new Float:x, Float:y, Float:z;
		GetPlayerPos(givePlayerID,x,y,z);
		if(!PlayerToPoint(4, playerid, x, y, z))
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Jesteœ zbyt daleko od tej osoby !");
			return 1;
		}
		EnsuranceOC[givePlayerID][vehicleNr] = slot;
		EnsuranceOC[givePlayerID][Level] = 2;
		PlayerPlayerActionMessage(playerid, givePlayerID, 10.0, "przekaza³ umowe");
		SendClientMessage(givePlayerID, COLOR_LIGHTYELLOW2, "[INFO:] Koszt podpisania umowy wynosi 2000$");

		// log
		format(form, sizeof(form), "[GOVERNMENT:] OC agreement lev 2 prepeared by %s for %s, veh serial %d",gPlayerData[playerid][pName], gPlayerData[givePlayerID][pName], ShowSlotItem(givePlayerID, slot));
		print(form);
		GovermentLog(form);

		return 1;
	}
	if(level == 3)
	{
		new Float:x, Float:y, Float:z;
		GetPlayerPos(givePlayerID,x,y,z);
		if(!PlayerToPoint(4, playerid, x, y, z))
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Jesteœ zbyt daleko od tej osoby !");
			return 1;
		}
		EnsuranceOC[givePlayerID][vehicleNr] = slot;
		EnsuranceOC[givePlayerID][Level] = 3;
		PlayerPlayerActionMessage(playerid, givePlayerID, 10.0, "przekaza³ umowe");
		SendClientMessage(givePlayerID, COLOR_LIGHTYELLOW2, "[INFO:] Koszt podpisania umowy wynosi 2000$");

		// log
		format(form, sizeof(form), "[GOVERNMENT:] OC agreement lev 3 prepeared by %s for %s, veh serial %d",gPlayerData[playerid][pName], gPlayerData[givePlayerID][pName], ShowSlotItem(givePlayerID, slot));
		print(form);
		GovermentLog(form);

		return 1;
	}
	return 1;
}

dcmd_umowaac(playerid, params[])
{
	new form[256];
	new givePlayerID;
	new slot;
	new level;
	if(sscanf(params, "ddd", givePlayerID, slot, level))
	{
		SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] /umowaac [id gracza] [slot] [poziom ac]");
		SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] slot: (1-15)");
		SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] poziom: 1 - 2 - 3");
		return 1;
	}
	if(gPlayerData[playerid][pFaction] != 9)
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie jesteœ urzêdnikiem !");
		return 1;
	}
	if(IsPlayerConnected(givePlayerID) == 0)
	{
		SendClientMessage(playerid,COLOR_RED,"[INFO:] Podany gracz nie jest on-line !");
		return 1;
	}
	if(PItemSlotStatus(givePlayerID, 1) == 0)
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten slot postaci jest pusty !");
		return 1;
	}
	if(!PSlotItemTypeCompare(givePlayerID, slot, 2))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Na tym slocie ta osoba nie posiada kluczyków do ¿adnego pojazdu !");
		return 1;
	}
	if(SlotParam2(givePlayerID, slot) != 0)
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ta osoba podpisa³a ju¿ umowe AC !");
		return 1;
	}
	if(level == 1)
	{
		new Float:x, Float:y, Float:z;
		GetPlayerPos(givePlayerID,x,y,z);
		if(!PlayerToPoint(4, playerid, x, y, z))
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Jesteœ zbyt daleko od tej osoby !");
			return 1;
		}
		EnsuranceAC[givePlayerID][vehicleNr] = 1;
		EnsuranceAC[givePlayerID][Level] = 1;
		PlayerPlayerActionMessage(playerid, givePlayerID, 10.0, "przekaza³ umowe");
		SendClientMessage(givePlayerID, COLOR_LIGHTYELLOW2, "[INFO:] Koszt podpisania umowy wynosi 2000$");

		// log
		format(form, sizeof(form), "[GOVERNMENT:] AC agreement lev 1 prepeared by %s for %s, veh serial %d",gPlayerData[playerid][pName], gPlayerData[givePlayerID][pName], ShowSlotItem(givePlayerID, slot));
		print(form);
		GovermentLog(form);

		return 1;
	}
	if(level == 2)
	{
		new Float:x, Float:y, Float:z;
		GetPlayerPos(givePlayerID,x,y,z);
		if(!PlayerToPoint(4, playerid, x, y, z))
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Jesteœ zbyt daleko od tej osoby !");
			return 1;
		}
		EnsuranceAC[givePlayerID][vehicleNr] = 1;
		EnsuranceAC[givePlayerID][Level] = 2;
		PlayerPlayerActionMessage(playerid, givePlayerID, 10.0, "przekaza³ umowe");
		SendClientMessage(givePlayerID, COLOR_LIGHTYELLOW2, "[INFO:] Koszt podpisania umowy wynosi 2000$");

		// log
		format(form, sizeof(form), "[GOVERNMENT:] AC agreement lev 2 prepeared by %s for %s, veh serial %d",gPlayerData[playerid][pName], gPlayerData[givePlayerID][pName], ShowSlotItem(givePlayerID, slot));
		print(form);
		GovermentLog(form);

		return 1;
	}
	if(level == 3)
	{
		new Float:x, Float:y, Float:z;
		GetPlayerPos(givePlayerID,x,y,z);
		if(!PlayerToPoint(4, playerid, x, y, z))
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Jesteœ zbyt daleko od tej osoby !");
			return 1;
		}
		EnsuranceAC[givePlayerID][vehicleNr] = 1;
		EnsuranceAC[givePlayerID][Level] = 3;
		PlayerPlayerActionMessage(playerid, givePlayerID, 10.0, "przekaza³ umowe");
		SendClientMessage(givePlayerID, COLOR_LIGHTYELLOW2, "[INFO:] Koszt podpisania umowy wynosi 2000$");

		// log
		format(form, sizeof(form), "[GOVERNMENT:] AC agreement lev 3 prepeared by %s for %s, veh serial %d",gPlayerData[playerid][pName], gPlayerData[givePlayerID][pName], ShowSlotItem(givePlayerID, slot));
		print(form);
		GovermentLog(form);

		return 1;
	}
	return 1;
}

dcmd_zrezygnujzoc(playerid, params[])
{
	new slot;
	if(sscanf(params, "d", slot))
	{
		if(gPlayerData[playerid][pVipItem] > 0)
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /zrezygnujzoc [slot(1-10)]");
			return 1;
		}
		else
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /zrezygnujzoc [slot(1-5)]");
			return 1;
		}
	}
	if(slot == 1)
	{
		if(PItemSlotStatus(playerid, 1) == 0)
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten slot jest pusty !");
			return 1;
		}
		if(gPlayerData[playerid][pItem1type] != 2)
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten slot nie zawiera kluczyków do pojazdu !");
			return 1;
		}
		if(gPlayerData[playerid][pItem1param] == 0)
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten pojazd nie posiada ubezpieczenia OC !");
			return 1;
		}
		gPlayerData[playerid][pItem1param] = 0;

		SavePlayerData(playerid, "Item1param");

		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Zrezygnowa³eœ ze swojego ubezpieczenia OC ");
		return 1;
	}
	if(slot == 2)
	{
		if(PItemSlotStatus(playerid, 1) == 0)
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten slot jest pusty !");
			return 1;
		}
		if(gPlayerData[playerid][pItem2type] != 2)
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten slot nie zawiera kluczyków do pojazdu !");
			return 1;
		}
		if(gPlayerData[playerid][pItem2param] == 0)
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten pojazd nie posiada ubezpieczenia OC !");
			return 1;
		}
		gPlayerData[playerid][pItem2param] = 0;

		SavePlayerData(playerid, "Item2param");

		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Zrezygnowa³eœ ze swojego ubezpieczenia OC ");
		return 1;
	}
	if(slot == 3)
	{
		if(PItemSlotStatus(playerid, 1) == 0)
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten slot jest pusty !");
			return 1;
		}
		if(gPlayerData[playerid][pItem3type] != 2)
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten slot nie zawiera kluczyków do pojazdu !");
			return 1;
		}
		if(gPlayerData[playerid][pItem3param] == 0)
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten pojazd nie posiada ubezpieczenia OC !");
			return 1;
		}
		gPlayerData[playerid][pItem3param] = 0;

		SavePlayerData(playerid, "Item3param");

		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Zrezygnowa³eœ ze swojego ubezpieczenia OC ");
		return 1;
	}
	if(slot == 4)
	{
		if(PItemSlotStatus(playerid, 1) == 0)
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten slot jest pusty !");
			return 1;
		}
		if(gPlayerData[playerid][pItem4type] != 2)
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten slot nie zawiera kluczyków do pojazdu !");
			return 1;
		}
		if(gPlayerData[playerid][pItem4param] == 0)
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten pojazd nie posiada ubezpieczenia OC !");
			return 1;
		}
		gPlayerData[playerid][pItem4param] = 0;

		SavePlayerData(playerid, "Item4param");

		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Zrezygnowa³eœ ze swojego ubezpieczenia OC ");
		return 1;
	}
	if(slot == 5)
	{
		if(PItemSlotStatus(playerid, 1) == 0)
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten slot jest pusty !");
			return 1;
		}
		if(gPlayerData[playerid][pItem5type] != 2)
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten slot nie zawiera kluczyków do pojazdu !");
			return 1;
		}
		if(gPlayerData[playerid][pItem5param] == 0)
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten pojazd nie posiada ubezpieczenia OC !");
			return 1;
		}
		gPlayerData[playerid][pItem5param] = 0;

		SavePlayerData(playerid, "Item5param");

		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Zrezygnowa³eœ ze swojego ubezpieczenia OC ");
		return 1;
	}
	if(gPlayerData[playerid][pVipItem] > 0)
	{
		if(slot == 6)
		{
			if(PItemSlotStatus(playerid, 1) == 0)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten slot jest pusty !");
				return 1;
			}
			if(gPlayerData[playerid][pItem6type] != 2)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten slot nie zawiera kluczyków do pojazdu !");
				return 1;
			}
			if(gPlayerData[playerid][pItem6param] == 0)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten pojazd nie posiada ubezpieczenia OC !");
				return 1;
			}
			gPlayerData[playerid][pItem6param] = 0;

			SavePlayerData(playerid, "Item6param");

			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Zrezygnowa³eœ ze swojego ubezpieczenia OC ");
			return 1;
		}
		if(slot == 7)
		{
			if(PItemSlotStatus(playerid, 1) == 0)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten slot jest pusty !");
				return 1;
			}
			if(gPlayerData[playerid][pItem7type] != 2)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten slot nie zawiera kluczyków do pojazdu !");
				return 1;
			}
			if(gPlayerData[playerid][pItem7param] == 0)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten pojazd nie posiada ubezpieczenia OC !");
				return 1;
			}
			gPlayerData[playerid][pItem7param] = 0;

			SavePlayerData(playerid, "Item7param");

			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Zrezygnowa³eœ ze swojego ubezpieczenia OC ");
			return 1;
		}
		if(slot == 8)
		{
			if(PItemSlotStatus(playerid, 1) == 0)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten slot jest pusty !");
				return 1;
			}
			if(gPlayerData[playerid][pItem8type] != 2)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten slot nie zawiera kluczyków do pojazdu !");
				return 1;
			}
			if(gPlayerData[playerid][pItem8param] == 0)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten pojazd nie posiada ubezpieczenia OC !");
				return 1;
			}
			gPlayerData[playerid][pItem8param] = 0;

			SavePlayerData(playerid, "Item8param");

			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Zrezygnowa³eœ ze swojego ubezpieczenia OC ");
			return 1;
		}
		if(slot == 9)
		{
			if(PItemSlotStatus(playerid, 1) == 0)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten slot jest pusty !");
				return 1;
			}
			if(gPlayerData[playerid][pItem9type] != 2)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten slot nie zawiera kluczyków do pojazdu !");
				return 1;
			}
			if(gPlayerData[playerid][pItem9param] == 0)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten pojazd nie posiada ubezpieczenia OC !");
				return 1;
			}
			gPlayerData[playerid][pItem9param] = 0;

			SavePlayerData(playerid, "Item9param");

			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Zrezygnowa³eœ ze swojego ubezpieczenia OC ");
			return 1;
		}
		if(slot == 10)
		{
			if(PItemSlotStatus(playerid, 1) == 0)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten slot jest pusty !");
				return 1;
			}
			if(gPlayerData[playerid][pItem10type] != 2)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten slot nie zawiera kluczyków do pojazdu !");
				return 1;
			}
			if(gPlayerData[playerid][pItem10param] == 0)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten pojazd nie posiada ubezpieczenia OC !");
				return 1;
			}
			gPlayerData[playerid][pItem10param] = 0;

			SavePlayerData(playerid, "Item10param");

			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Zrezygnowa³eœ ze swojego ubezpieczenia OC ");
			return 1;
		}
	}
	return 1;
}

dcmd_zrezygnujzac(playerid, params[])
{
	new slot;
	if(sscanf(params, "d", slot))
	{
		if(gPlayerData[playerid][pVipItem] > 0)
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /zrezygnujzac [slot(1-10)]");
			return 1;
		}
		else
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /zrezygnujzac [slot(1-5)]");
			return 1;
		}
	}
	if(slot == 1)
	{
		if(PItemSlotStatus(playerid, 1) == 0)
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten slot jest pusty !");
			return 1;
		}
		if(gPlayerData[playerid][pItem1type] != 2)
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten slot nie zawiera kluczyków do pojazdu !");
			return 1;
		}
		if(gPlayerData[playerid][pItem1param2] == 0)
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten pojazd nie posiada ubezpieczenia AC !");
			return 1;
		}
		gPlayerData[playerid][pItem1param2] = 0;

		SavePlayerData(playerid, "Item1param2");

		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Zrezygnowa³eœ ze swojego ubezpieczenia AC ");
		return 1;
	}
	if(slot == 2)
	{
		if(PItemSlotStatus(playerid, 1) == 0)
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten slot jest pusty !");
			return 1;
		}
		if(gPlayerData[playerid][pItem2type] != 2)
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten slot nie zawiera kluczyków do pojazdu !");
			return 1;
		}
		if(gPlayerData[playerid][pItem2param] == 0)
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten pojazd nie posiada ubezpieczenia AC !");
			return 1;
		}
		gPlayerData[playerid][pItem2param] = 0;

		SavePlayerData(playerid, "Item2param");

		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Zrezygnowa³eœ ze swojego ubezpieczenia AC ");
		return 1;
	}
	if(slot == 3)
	{
		if(PItemSlotStatus(playerid, 1) == 0)
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten slot jest pusty !");
			return 1;
		}
		if(gPlayerData[playerid][pItem3type] != 2)
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten slot nie zawiera kluczyków do pojazdu !");
			return 1;
		}
		if(gPlayerData[playerid][pItem3param] == 0)
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten pojazd nie posiada ubezpieczenia AC !");
			return 1;
		}
		gPlayerData[playerid][pItem3param] = 0;

		SavePlayerData(playerid, "Item3param");

		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Zrezygnowa³eœ ze swojego ubezpieczenia AC ");
		return 1;
	}
	if(slot == 4)
	{
		if(PItemSlotStatus(playerid, 1) == 0)
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten slot jest pusty !");
			return 1;
		}
		if(gPlayerData[playerid][pItem4type] != 2)
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten slot nie zawiera kluczyków do pojazdu !");
			return 1;
		}
		if(gPlayerData[playerid][pItem4param] == 0)
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten pojazd nie posiada ubezpieczenia AC !");
			return 1;
		}
		gPlayerData[playerid][pItem4param] = 0;

		SavePlayerData(playerid, "Item4param");

		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Zrezygnowa³eœ ze swojego ubezpieczenia AC ");
		return 1;
	}
	if(slot == 5)
	{
		if(PItemSlotStatus(playerid, 1) == 0)
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten slot jest pusty !");
			return 1;
		}
		if(gPlayerData[playerid][pItem5type] != 2)
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten slot nie zawiera kluczyków do pojazdu !");
			return 1;
		}
		if(gPlayerData[playerid][pItem5param] == 0)
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten pojazd nie posiada ubezpieczenia AC !");
			return 1;
		}
		gPlayerData[playerid][pItem5param] = 0;

		SavePlayerData(playerid, "Item5param");

		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Zrezygnowa³eœ ze swojego ubezpieczenia AC ");
		return 1;
	}
	if(gPlayerData[playerid][pVipItem] > 0)
	{
		if(slot == 6)
		{
			if(PItemSlotStatus(playerid, 1) == 0)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten slot jest pusty !");
				return 1;
			}
			if(gPlayerData[playerid][pItem6type] != 2)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten slot nie zawiera kluczyków do pojazdu !");
				return 1;
			}
			if(gPlayerData[playerid][pItem6param] == 0)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten pojazd nie posiada ubezpieczenia AC !");
				return 1;
			}
			gPlayerData[playerid][pItem6param] = 0;

			SavePlayerData(playerid, "Item6param");

			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Zrezygnowa³eœ ze swojego ubezpieczenia AC ");
			return 1;
		}
		if(slot == 7)
		{
			if(PItemSlotStatus(playerid, 1) == 0)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten slot jest pusty !");
				return 1;
			}
			if(gPlayerData[playerid][pItem7type] != 2)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten slot nie zawiera kluczyków do pojazdu !");
				return 1;
			}
			if(gPlayerData[playerid][pItem7param] == 0)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten pojazd nie posiada ubezpieczenia AC !");
				return 1;
			}
			gPlayerData[playerid][pItem7param] = 0;

			SavePlayerData(playerid, "Item7param");

			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Zrezygnowa³eœ ze swojego ubezpieczenia AC ");
			return 1;
		}
		if(slot == 8)
		{
			if(PItemSlotStatus(playerid, 1) == 0)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten slot jest pusty !");
				return 1;
			}
			if(gPlayerData[playerid][pItem8type] != 2)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten slot nie zawiera kluczyków do pojazdu !");
				return 1;
			}
			if(gPlayerData[playerid][pItem8param] == 0)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten pojazd nie posiada ubezpieczenia AC !");
				return 1;
			}
			gPlayerData[playerid][pItem8param] = 0;

			SavePlayerData(playerid, "Item8param");

			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Zrezygnowa³eœ ze swojego ubezpieczenia AC ");
			return 1;
		}
		if(slot == 9)
		{
			if(PItemSlotStatus(playerid, 1) == 0)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten slot jest pusty !");
				return 1;
			}
			if(gPlayerData[playerid][pItem9type] != 2)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten slot nie zawiera kluczyków do pojazdu !");
				return 1;
			}
			if(gPlayerData[playerid][pItem9param] == 0)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten pojazd nie posiada ubezpieczenia AC !");
				return 1;
			}
			gPlayerData[playerid][pItem9param] = 0;

			SavePlayerData(playerid, "Item9param");

			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Zrezygnowa³eœ ze swojego ubezpieczenia AC ");
			return 1;
		}
		if(slot == 10)
		{
			if(PItemSlotStatus(playerid, 1) == 0)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten slot jest pusty !");
				return 1;
			}
			if(gPlayerData[playerid][pItem10type] != 2)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten slot nie zawiera kluczyków do pojazdu !");
				return 1;
			}
			if(gPlayerData[playerid][pItem10param] == 0)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten pojazd nie posiada ubezpieczenia AC !");
				return 1;
			}
			gPlayerData[playerid][pItem10param] = 0;

			SavePlayerData(playerid, "Item10param");

			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Zrezygnowa³eœ ze swojego ubezpieczenia AC ");
			return 1;
		}
	}
	return 1;
}

dcmd_wyplacodszkodowanieoc(playerid, params[])
{
	new slot;
	new givePlayerID;
	new string[128];
	if(sscanf(params, "dd", givePlayerID, slot))
	{
		if(gPlayerData[givePlayerID][pVipItem] > 0)
		{
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] /wyplacodszkodowanieoc [id gracza] [slot(1-10)]");
		}
		else
		{
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] /wyplacodszkodowanieoc [id gracza] [slot(1-5)]");
		}
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
	if(PItemSlotStatus(givePlayerID, slot) == 0)
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten slot postaci jest pusty !");
		return 1;
	}
	if(!PSlotItemTypeCompare(givePlayerID, slot, 2))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Na tym slocie ta osoba nie posiada kluczyków do ¿adnego pojazdu !");
		return 1;
	}
	if(SlotParam1(givePlayerID, slot) == 0)
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ta osoba nie posiada ubezpieczenia OC na wybrany pojazd !");
		return 1;
	}
	new vehid = CheckPlayerCarSerial(givePlayerID, slot);
	if(vehid == 255 || strcmp(gVehData[vehid][Owner], gPlayerData[givePlayerID][pName], false) != 0)
	{
		GivePlayerCash(givePlayerID, SlotParam1(givePlayerID, slot));
		DynamicFactions[FACTIONID_GOVERNMENT][fBank] -= SlotParam1(givePlayerID, slot);
		SaveFData(FACTIONID_GOVERNMENT, "Bank");

		format(string, sizeof(string),"[INFO:] Wyp³acono odszkodowanie dla %s", gPlayerData[givePlayerID][pName]);
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);

		format(string, sizeof(string), "[INFO:] Wyp³acono odszkodowanie za strate samochodu w wysokoœci %d", SlotParam1(givePlayerID, slot));
		SendClientMessage(givePlayerID, COLOR_GREEN, string);

		SetPSlotParam1(givePlayerID, slot, 0);

		format(string, sizeof(string), "[GOVERNMENT:] Player: %s payed ensurance OC for %s, vehicle serial: %d", gPlayerData[playerid][pName], gPlayerData[givePlayerID][pName], ShowSlotItem(givePlayerID, slot));
		GovermentLog(string);
	}
	else
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Pojazd tej osoby nie jest zniszczony");
	}
	return 1;
}

dcmd_wyplacodszkodowanieac(playerid, param2s[])
{
	new slot;
	new givePlayerID;
	new string[128];
	if(sscanf(param2s, "dd", givePlayerID, slot))
	{
		if(gPlayerData[givePlayerID][pVipItem] > 0)
		{
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] /wyplacodszkodowanieac [id gracza] [slot(1-10)]");
		}
		else
		{
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] /wyplacodszkodowanieac [id gracza] [slot(1-5)]");
		}
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
	if(PItemSlotStatus(givePlayerID, slot) == 0)
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten slot postaci jest pusty !");
		return 1;
	}
	if(!PSlotItemTypeCompare(givePlayerID, slot, 2))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Na tym slocie ta osoba nie posiada kluczyków do ¿adnego pojazdu !");
		return 1;
	}
	if(SlotParam2(givePlayerID, slot) == 0)
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ta osoba nie posiada ubezpieczenia AC na wybrany pojazd !");
		return 1;
	}
	new vehid = CheckPlayerCarSerial(givePlayerID, slot);
	if(vehid == 255 || strcmp(gVehData[vehid][Owner], gPlayerData[givePlayerID][pName], false) != 0)
	{
		GivePlayerCash(givePlayerID, SlotParam2(givePlayerID, slot));
		DynamicFactions[FACTIONID_GOVERNMENT][fBank] -= SlotParam2(givePlayerID, slot);
		SaveFData(FACTIONID_GOVERNMENT, "Bank");

		format(string, sizeof(string),"[INFO:] Wyp³acono odszkodowanie dla %s", gPlayerData[givePlayerID][pName]);
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);

		format(string, sizeof(string), "[INFO:] Wyp³acono odszkodowanie za strate samochodu w wysokoœci %d", SlotParam2(givePlayerID, slot));
		SendClientMessage(givePlayerID, COLOR_GREEN, string);

		SetPSlotParam2(givePlayerID, slot, 0);

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
	if(sscanf(params, "ddd", vehicleID, color1, color2))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /przemaluj [rejestracja] [kolor1] [kolor2]");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] kolor1/kolor2 - od 0 do 255");
		return 1;
	}
	if(gPlayerData[playerid][pJob] != 17)
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ mechanikiem !");
		return 1;
	}
	if(color1 < 0 || color1 >  255 || color2 < 0 || color2 > 255)
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] kolor1/kolor2 - od 0 do 255");
		return 1;
	}
	vehicleID = CarSerialToID(vehicleID) + 1;
	new Float:x, Float:y, Float:z;
	GetVehiclePos(vehicleID, x, y, z);
	if(!PlayerToPoint(8, playerid, x, y, z))
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Jesteœ zbyt daleko od pojazdu !");
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
		PaintTimer(vehicleID-1);

		SaveVehData(vehicleID-1, "PaintStep");

		return 1;
	}
	if(gVehData[vehicleID-1][PaintStep] == 1)
	{
		PlayerActionMessage(playerid, 20.0, "kontynuuje nak³adanie lakieru z przodu pojazdu");
		gVehData[vehicleID-1][PaintStep] = 2;
		isPainting[vehicleID-1] = 1;
		PaintTimer(vehicleID-1);

		SaveVehData(vehicleID-1, "PaintStep");

		return 1;
	}
	if(gVehData[vehicleID-1][PaintStep] == 2)
	{
		PlayerActionMessage(playerid, 20.0, "rozpoczyna nak³adanie lakieru z prawej strony pojazdu");
		gVehData[vehicleID-1][PaintStep] = 3;
		isPainting[vehicleID-1] = 1;
		PaintTimer(vehicleID-1);

		SaveVehData(vehicleID-1, "PaintStep");

		return 1;
	}
	if(gVehData[vehicleID-1][PaintStep] == 3)
	{
		PlayerActionMessage(playerid, 20.0, "rozpoczyna nak³adanie lakieru z lewej strony pojazdu");
		gVehData[vehicleID-1][PaintStep] = 4;
		isPainting[vehicleID-1] = 1;
		PaintTimer(vehicleID-1);

		SaveVehData(vehicleID-1, "PaintStep");

		return 1;
	}
	if(gVehData[vehicleID-1][PaintStep] == 4)
	{
		PlayerActionMessage(playerid, 20.0, "rozpoczyna nak³adanie lakieru z ty³u pojazdu");
		gVehData[vehicleID-1][PaintStep] = 5;
		isPainting[vehicleID-1] = 1;
		PaintTimer(vehicleID-1);

		SaveVehData(vehicleID-1, "PaintStep");

		return 1;
	}
	if(gVehData[vehicleID-1][PaintStep] == 5)
	{
		PlayerActionMessage(playerid, 20.0, "sprawdza stan lakieru");
		gVehData[vehicleID-1][PaintStep] = 0;

		SaveVehData(vehicleID-1, "PaintStep");
	}

	gVehData[vehicleID-1][CarColor1] = color1;
	gVehData[vehicleID-1][CarColor2] = color2;
	ChangeVehicleColor(vehicleID, color1, color2);
	// TODO: Cash is going nowhere... Fix this
	GivePlayerCash(playerid, -500);
	SendClientMessage(playerid, COLOR_GREEN, "[INFO:] Kolor pojazdu zosta³ zmieniony !");
	SendClientMessage(playerid, COLOR_GREEN, "[INFO:] Koszt malowania: 500$");
	SaveVehData(vehicleID-1, "CarColor1");
	SaveVehData(vehicleID-1, "CarColor2");
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
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /abizlock [biz ID] [confiscated 0/1]");
		return 1;
	}
	Businesses[bizID][BConfiscated] = bizConfiscated;
	SaveBizData(bizID, "Confiscated");
	new string[128];
	format(string, sizeof(string), "[INFO:] Business ID: %d confiscated status changed to: %d", bizID, bizConfiscated);
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
		if(SlotParam1(playerid, slot)> 0)
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
		if( gVehData[tmpVehicleID][Owned] == 1 && strcmp(gPlayerData[playerid][pName], gVehData[tmpVehicleID][Owner], true) == 0)
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

			gVehData[tmpVehicleID][Veh3DSell] = CreateDynamic3DTextLabel("Ten pojazd jest na sprzedaz !", COLOR_LIGHTBLUE, 0.0, 0.0, 0.6, 80.0, INVALID_PLAYER_ID, vehicleID, 1);
			format(string, sizeof(string), "[INFO:] Wystawi³eœ swój pojazd na sprzeda¿ za %d$", carPrice);
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
		if(PHaveItem(playerid, 2, gVehData[tmpVehicleID][CarSerial]) > 0 && gVehData[tmpVehicleID][Owned] == 1 && strcmp(gPlayerData[playerid][pName], gVehData[tmpVehicleID][Owner], false) == 0)
		{
			gVehData[tmpVehicleID][ReadyToSell] = 0;

			SaveVehData(tmpVehicleID, "ReadyToSell");

			DestroyDynamic3DTextLabel( gVehData[vehicleID-1][Veh3DSell] );
			format(string, sizeof(string), "[INFO:] Anulowa³eœ sprzeda¿ swojego pojazdu !");
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
		}
		else
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] To nie jest Twój pojazd !");
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
			//GetPlayerPos(playerid, x, y, z);

	if(gPlayerData[playerid][pRank] != 1)
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ liderem frakcji. Nie mo¿esz sprzedaæ tego pojazdu !");
		return 1;
	}
	if(gPlayerData[playerid][pFaction] != gVehData[tmpVehicleID][FactionCar])
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten pojazd nie nale¿y do frakcji !");
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

		gVehData[tmpVehicleID][Veh3DSell] = CreateDynamic3DTextLabel("Ten pojazd jest na sprzedaz !", COLOR_LIGHTBLUE, 0.0, 0.0, 0.6, 80.0, INVALID_PLAYER_ID, vehicleID, 1);
		format(string, sizeof(string), "[INFO:] Wystawi³eœ frakcyjny pojazd na sprzeda¿ za %d$", carPrice);
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
		if(gVehData[tmpVehicleID][FactionCar] != gPlayerData[playerid][pFaction])
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

			DestroyDynamic3DTextLabel( gVehData[vehicleID-1][Veh3DSell] );
			format(string, sizeof(string), "[INFO:] Anulowa³eœ sprzeda¿ frakcyjnego pojazdu !");
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
		}
	}
	return 1;
}

dcmd_ulecz(playerid, params[])
{
	if(gPlayerData[playerid][pFaction] == 2 || gPlayerData[playerid][pAdmin] == 5)
	{
		new targetID;
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
					if( PlayerToPoint(5.0, playerid, targetX, targetY, targetZ) || gPlayerData[playerid][pAdmin] > 0)
					{
						PlayerPlayerActionMessage(playerid, targetID, 20.0, "opatruje rany");
						SetPlayerHealth(targetID, 100.0);
						gPlayerData[targetID][pHP] = 100.0;
						SavePlayerData( targetID, "HP" );
						SendClientMessage(targetID, COLOR_GREEN, "[INFO:] Zosta³eœ uleczony !");
						SetPlayerDrunkLevel(targetID, 2000);
					}
					else
					{
						SendClientMessage(playerid, COLOR_RED, "[INFO:] Ta osoba jest zbyt daleko by wykonaæ reanimacje.");
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
	return 1;
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
	new targetID;
	if(gPlayerData[playerid][pFaction] == 2 && gPlayerData[playerid][pRank] <= 6  || gPlayerData[playerid][pAdmin] > 0)
	{
		if(IsPlayerConnected(targetID))
		{
			if(sscanf(params, "d", targetID))
			{
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] /detoksykacja [id gracza]");
				return 1;
			}
			if(targetID != playerid)
			{
				if(gPlayerData[targetID][pDetoks] < 10)
				{
					if(PlayerToPoint(5.0, playerid, -2636.6081, 670.9566, 11.3357) || PlayerToPoint(5.0, playerid, 1205.0, -899.0, 1094.0))
					{
						if(PlayerToPoint(5.0, targetID, -2636.6081, 670.9566, 11.3357) || PlayerToPoint(5.0, targetID, 1205.0, -899.0, 1094.0))
						{
							PlayerPlayerActionMessage(playerid, targetID, 20.0, "zaczyna detoksyzacje");
							SetPlayerHealth(targetID, 100.0);
							SendClientMessage(targetID, COLOR_GREEN, "[INFO:] Otrzyma³eœ niewielk¹ dawke detoxu !");
							gPlayerData[targetID][pDetoks] ++ ;
							SetPlayerDrunkLevel(targetID, 2000);

							SavePlayerData(targetID, "Detoks");
						}
						else
						{
							SendClientMessage(playerid, COLOR_RED, "[INFO:] Pacjent jest zbyt daleko od sali operacyjnej !");
							return 1;
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_RED, "[INFO:] Jesteœ zbyt daleko od sali operacyjnej !");
						return 1;
					}
				}
				else
				{
					if(PlayerToPoint(5.0, playerid, -2636.6081, 670.9566, 11.3357) || PlayerToPoint(5.0, playerid, 1205.0, -899.0, 1094.0))
					{
						if(PlayerToPoint(5.0, targetID, -2636.6081, 670.9566, 11.3357) || PlayerToPoint(5.0, targetID, 1205.0, -899.0, 1094.0))
						{
							PlayerPlayerActionMessage(playerid, targetID, 20.0, "zaczyna detoksyzacje");
							SetPlayerHealth(targetID, 100.0);
							SendClientMessage(targetID, COLOR_GREEN, "[INFO:] Zosta³eœ wyleczony z uzaleznienia !");
							gPlayerData[targetID][pDrugsAddicted] = 0 ;
							gPlayerData[targetID][pDetoks] = 0 ;
							SetPlayerDrunkLevel(targetID, 2000);

							SavePlayerData(targetID, "DrugsAddicted");
							SavePlayerData(targetID, "Detoks");
						}
						else
						{
							SendClientMessage(playerid, COLOR_RED, "[INFO:] Pacjent jest zbyt daleko od sali operacyjnej !");
							return 1;
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_RED, "[INFO:] Jesteœ zbyt daleko od sali operacyjnej !");
						return 1;
					}
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

dcmd_statusfrakcji(playerid, params[])
{
	#pragma unused params
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

dcmd_abusinesstill(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] < 4)
		return 0;
	new businessID;
	new cash;
	new string[128];
	if(sscanf(params, "dd", businessID, cash))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /abusinesstill [businessID] [cash]");
		return 1;
	}
	Businesses[businessID][Till] = cash;
	format(string, sizeof(string), "[INFO:] Ustawi³eœ iloœæ pieniedzy w kasie frakcji na %d$", Businesses[businessID][Till]);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	return 1;
}

dcmd_abusinessaddtill(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] < 4)
		return 0;
	new businessID;
	new cash;
	new string[128];
	if(sscanf(params, "dd", businessID, cash))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /abusinessaddtill [businessID] [cash]");
		return 1;
	}
	Businesses[businessID][Till] += cash;
	format(string, sizeof(string), "[INFO:] Ustawi³eœ iloœæ pieniedzy w kasie frakcji na %d$", Businesses[businessID][Till]);
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
			SetPlayerArmour(playerid, armour + 2.0);
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
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie posiadasz ¿adnych narkotyków.");
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
			if(gPlayerData[playerid][pFaction] == 11 || gPlayerData[playerid][pBizKey] == GasStations[i][BusinessID] || gPlayerData[playerid][pAdmin] >= 5)
			{
				format(string, sizeof(string), "[INFO:] Zasoby: %f litrów benzyny, zapotrzebowanie: %f litrów", GasStations[i][PetrolResourceValue], GasStations[i][MaxPetrolResourceValue] - GasStations[i][PetrolResourceValue]);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
				format(string, sizeof(string), "[INFO:] Zasoby: %f litrów ropy, zapotrzebowanie: %f litrów", GasStations[i][OilResourceValue], GasStations[i][MaxOilResourceValue] - GasStations[i][OilResourceValue]);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
				format(string, sizeof(string), "[INFO:] Zasoby: %f litrów gazu, zapotrzebowanie: %f litrów", GasStations[i][GasResourceValue], GasStations[i][MaxGasResourceValue] - GasStations[i][GasResourceValue]);
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
		ShowPlayerDialog(playerid,
										DIALOG_INFO,
										DIALOG_STYLE_MSGBOX,
										DIALOG_INFO_HEADER,
										RAF_GS_INV_VEHID,
										DIALOG_INFO_EXIT,
										"" );
		return 1;
	}
	new tlID = GetVehicleTrailer(vehID);
	/* Truck has no tanker */
	if( tlID == INVALID_VEHICLE_ID )
	{
		ShowPlayerDialog(playerid,
										DIALOG_INFO,
										DIALOG_STYLE_MSGBOX,
										DIALOG_INFO_HEADER,
										RAF_GS_INV_TLID,
										DIALOG_INFO_EXIT,
										"" );
		return 1;
	}
	/* Tanker already refueling */
	if ( gVehData[tlID-1][TankerIsRefueling] )
	{
		ShowPlayerDialog(playerid,
										DIALOG_INFO,
										DIALOG_STYLE_MSGBOX,
										DIALOG_INFO_HEADER,
										RAF_GS_AREFUELING,
										DIALOG_INFO_EXIT,
										"" );
		return 1;
	}
	/* Tanker has no fuel defined type */
	if( gVehData[tlID-1][TankerResourceType] == TANKER_TYPE_NONE )
	{
		ShowPlayerDialog(playerid,
										DIALOG_INFO,
										DIALOG_STYLE_MSGBOX,
										DIALOG_INFO_HEADER,
										RAF_GS_NO_TYPE,
										DIALOG_INFO_EXIT,
										"" );
		return 1;
	}
	/* Tanker is empty */
	if( gVehData[tlID-1][TankerResourceValue] <= 0 )
	{
		ShowPlayerDialog(playerid,
										DIALOG_INFO,
										DIALOG_STYLE_MSGBOX,
										DIALOG_INFO_HEADER,
										RAF_GS_REFUELED_C,
										DIALOG_INFO_EXIT,
										"" );
		return 1;
	}
	for(new i = 0; i < sizeof(GasStations); i++)
	{
		if(PlayerToPoint(10.0, playerid, GasStations[i][GSposX], GasStations[i][GSposY], GasStations[i][GSposZ]))
		{
			switch( gVehData[tlID-1][TankerResourceType] )
			{
				case TANKER_TYPE_PETROL:
				{
					if( !GasStations[i][RefuelPetrolResources] )
					{
						ShowPlayerDialog(playerid,
														DIALOG_INFO,
														DIALOG_STYLE_MSGBOX,
														DIALOG_INFO_HEADER,
														RAF_GS_NO_REFUEL,
														DIALOG_INFO_EXIT,
														"" );
						return 1;
					}
					/* No till to refuel*/
					if( Businesses[GasStations[i][BusinessID]][Till] < gRafinery[RafPetrolLtrCost] )
					{
						ShowPlayerDialog(playerid,
														DIALOG_INFO,
														DIALOG_STYLE_MSGBOX,
														DIALOG_INFO_HEADER,
														RAF_GS_NO_TILL,
														DIALOG_INFO_EXIT,
														"" );
						return 1;
					}
					if( GasStations[i][PetrolResourceValue] >= GasStations[i][MaxPetrolResourceValue] )
					{
						ShowPlayerDialog(playerid,
														DIALOG_INFO,
														DIALOG_STYLE_MSGBOX,
														DIALOG_INFO_HEADER,
														RAF_GS_FULL_PETROL,
														DIALOG_INFO_EXIT,
														"" );
						return 1;
					}
					gVehData[tlID-1][TankerIsRefueling] = 1;
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Rozpoczêto nape³nianie zbiorników stacji");
					RefuelingStation(playerid, i);
					return 1;
				}
				case TANKER_TYPE_OIL:
				{
					if( !GasStations[i][RefuelOilResources] )
					{
						ShowPlayerDialog(playerid,
														DIALOG_INFO,
														DIALOG_STYLE_MSGBOX,
														DIALOG_INFO_HEADER,
														RAF_GS_NO_REFUEL,
														DIALOG_INFO_EXIT,
														"" );
						return 1;
					}
					/* No till to refuel*/
					if( Businesses[GasStations[i][BusinessID]][Till] < gRafinery[RafOilLtrCost] )
					{
						ShowPlayerDialog(playerid,
														DIALOG_INFO,
														DIALOG_STYLE_MSGBOX,
														DIALOG_INFO_HEADER,
														RAF_GS_NO_TILL,
														DIALOG_INFO_EXIT,
														"" );
						return 1;
					}
					if( GasStations[i][OilResourceValue] >= GasStations[i][MaxOilResourceValue] )
					{
						ShowPlayerDialog(playerid,
														DIALOG_INFO,
														DIALOG_STYLE_MSGBOX,
														DIALOG_INFO_HEADER,
														RAF_GS_FULL_OIL,
														DIALOG_INFO_EXIT,
														"" );
						return 1;
					}
					gVehData[tlID-1][TankerIsRefueling] = 1;
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Rozpoczêto nape³nianie zbiorników stacji");
					RefuelingStation(playerid, i);
					return 1;
				}
				case TANKER_TYPE_GAS:
				{
					if( !GasStations[i][RefuelGasResources] )
					{
						ShowPlayerDialog(playerid,
														DIALOG_INFO,
														DIALOG_STYLE_MSGBOX,
														DIALOG_INFO_HEADER,
														RAF_GS_NO_REFUEL,
														DIALOG_INFO_EXIT,
														"" );
						return 1;
					}
					/* No till to refuel*/
					if( Businesses[GasStations[i][BusinessID]][Till] < gRafinery[RafGasLtrCost] )
					{
						ShowPlayerDialog(playerid,
														DIALOG_INFO,
														DIALOG_STYLE_MSGBOX,
														DIALOG_INFO_HEADER,
														RAF_GS_NO_TILL,
														DIALOG_INFO_EXIT,
														"" );
						return 1;
					}
					if( GasStations[i][GasResourceValue] >= GasStations[i][MaxGasResourceValue] )
					{
						ShowPlayerDialog(playerid,
														DIALOG_INFO,
														DIALOG_STYLE_MSGBOX,
														DIALOG_INFO_HEADER,
														RAF_GS_FULL_GAS,
														DIALOG_INFO_EXIT,
														"" );
						return 1;
					}
					gVehData[tlID-1][TankerIsRefueling] = 1;
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Rozpoczêto nape³nianie zbiorników stacji");
					RefuelingStation(playerid, i);
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
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /odczepnaczepe - /stanstacji - /napelnijzbiorniki");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /cenazalitrbenzyny - /cenazalitrropy - /cenazalitrgazu - /wynagrodzenie");
		return 1;
	}
	else
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie jesteœ pracownikiem rafinerii !");
		return 1;
	}
}

dcmd_cenazalitrbenzyny(playerid, params[])
{
	if(gPlayerData[playerid][pFaction] == 11 || gPlayerData[playerid][pFaction] == 9)
	{
		if(gPlayerData[playerid][pRank] == 1)
		{
			new cost;

			if(sscanf(params, "d", cost))
			{
				SendClientMessage(playerid, COLOR_RED, "[INFO:] /cenazalitrr [kwota]");
				return 1;
			}
			if(cost <= 0)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Kwota musi byæ wiêksza od 0 !");
				return 1;
			}
			gRafinery[RafPetrolLtrCost] = cost;

			new string[128];
			format(string, sizeof(string), "[INFO:] Ustali³eœ now¹ cene za litr paliwa (beznyna): %d$", cost);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			printf("[WARNING:] Fuel price set to: %d$ by %s", cost, gPlayerData[playerid][pName]);
			SaveRafinery();
			return 1;
		}
		else
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie jesteœ prezesem rafinerii !");
			return 1;
		}
	}
	if(gPlayerData[playerid][pFaction] != 11 && gPlayerData[playerid][pFaction] != 9 && Businesses[gPlayerData[playerid][pBizKey]][BizType] != 11)
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
				SendClientMessage(playerid, COLOR_RED, "[INFO:] /cenazalitrr [kwota]");
				return 1;
			}
			if(cost <= 0)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Kwota musi byæ wiêksza od 0 !");
				return 1;
			}
			gRafinery[RafOilLtrCost] = cost;

			new string[128];
			format(string, sizeof(string), "[INFO:] Ustali³eœ now¹ cene za litr paliwa (diesel): %d$", cost);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			printf("[WARNING:] Fuel (diesel) price set to: %d$ by %s", cost, gPlayerData[playerid][pName]);
			SaveRafinery();
			return 1;
		}
		else
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie jesteœ prezesem rafinerii !");
			return 1;
		}
	}
	if(gPlayerData[playerid][pFaction] != 11 && gPlayerData[playerid][pFaction] != 9 && Businesses[gPlayerData[playerid][pBizKey]][BizType] != 11)
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
				SendClientMessage(playerid, COLOR_RED, "[INFO:] /cenazalitrr [kwota]");
				return 1;
			}
			if(cost <= 0)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Kwota musi byæ wiêksza od 0 !");
				return 1;
			}
			gRafinery[RafGasLtrCost] = cost;

			new string[128];
			format(string, sizeof(string), "[INFO:] Ustali³eœ now¹ cene za litr paliwa (gaz): %d$", cost);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			printf("[WARNING:] Fuel (gas) price set to: %d$ by %s", cost, gPlayerData[playerid][pName]);
			SaveRafinery();
			return 1;
		}
		else
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie jesteœ prezesem rafinerii !");
			return 1;
		}
	}
	if(gPlayerData[playerid][pFaction] != 11 && gPlayerData[playerid][pFaction] != 9 && Businesses[gPlayerData[playerid][pBizKey]][BizType] != 11)
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
			if(gPlayerData[playerid][pBizKey] == GasStations[i][BusinessID] || gPlayerData[playerid][pAdmin] == 5)
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

				format(string, sizeof(string), "Benzyna: %d$", GasStations[i][PetrolPrice]);
				UpdateDynamic3DTextLabelText(GasStations[i][GS3dTextLabel], COLOR_GREEN, string);

				format(string, sizeof(string), "[INFO:] Ustali³eœ now¹ cene za litr paliwa (benzyna): %d$", cost);
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
			if(gPlayerData[playerid][pBizKey] == GasStations[i][BusinessID] || gPlayerData[playerid][pAdmin] == 5 )
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

				format(string, sizeof(string), "Diesel: %d$", GasStations[i][OilPrice]);
				UpdateDynamic3DTextLabelText(GasStations[i][GS3dTextLabel2], COLOR_GREEN, string);

				format(string, sizeof(string), "[INFO:] Ustali³eœ now¹ cene za litr paliwa (diesel): %d$", cost);
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
			if(gPlayerData[playerid][pBizKey] == GasStations[i][BusinessID] || gPlayerData[playerid][pAdmin] == 5)
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

				format(string, sizeof(string), "Gaz: %d$", GasStations[i][GasPrice]);
				UpdateDynamic3DTextLabelText(GasStations[i][GS3dTextLabel3], COLOR_GREEN, string);

				format(string, sizeof(string), "[INFO:] Ustali³eœ now¹ cene za litr paliwa (gaz): %d$", cost);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);

				SaveFuleStationData(i, "GasPrice");

				return 1;
			}
		}
	}
	SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie znajdujesz siê na ¿adnej stacji !");
	return 1;
}

dcmd_wynagrodzenie(playerid, params[])
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
			format(string, sizeof(string), "[INFO:] Ustali³eœ now¹ kwote wynagrodzenia dla pracowników: %d$", cost);
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
}

dcmd_uzupelnianiebenzyny(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pBizKey] != 255)
	{
		for(new i = 0; i < sizeof(GasStations); i++)
		{
			if(PlayerToPoint(10.0, playerid, GasStations[i][GSposX], GasStations[i][GSposY], GasStations[i][GSposZ]))
			{
				if(gPlayerData[playerid][pBizKey] == GasStations[i][BusinessID])
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
	else
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie posiadasz ¿adnego biznesu !");
		return 1;
	}
}

dcmd_uzupelnianieropy(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pBizKey] != 255)
	{
		for(new i = 0; i < sizeof(GasStations); i++)
		{
			if(PlayerToPoint(10.0, playerid, GasStations[i][GSposX], GasStations[i][GSposY], GasStations[i][GSposZ]))
			{
				if(gPlayerData[playerid][pBizKey] == GasStations[i][BusinessID])
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
	else
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie posiadasz ¿adnego biznesu !");
		return 1;
	}
}

dcmd_uzupelnianiegazu(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pBizKey] != 255)
	{
		for(new i = 0; i < sizeof(GasStations); i++)
		{
			if(PlayerToPoint(10.0, playerid, GasStations[i][GSposX], GasStations[i][GSposY], GasStations[i][GSposZ]))
			{
				if(gPlayerData[playerid][pBizKey] == GasStations[i][BusinessID])
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
	else
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie posiadasz ¿adnego biznesu !");
		return 1;
	}
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
			format(string, sizeof(string), "[INFO:] Business ID: %d connected with Gas Station ID: %d", businessID, i);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			SaveGasStations();
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
	format(string, sizeof(string), "[INFO:] Rafinery fuel ltr cost set to %d$", cost);
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
	format(string, sizeof(string), "[INFO:] Rafinery fuel ltr cost set to %d$", cost);
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
	format(string, sizeof(string), "[INFO:] Rafinery fuel ltr cost set to %d$", cost);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	return 1;
}

dcmd_setgasstationresources(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] >= 10)
	{
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
	}
	return 1;
}

dcmd_setgasstationresources2(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] >= 10)
	{
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
	}
	return 1;
}

dcmd_setgasstationresources3(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] >= 10)
	{
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

	DestroyDynamic3DTextLabel(gVehData[vehID][Veh3DSell]);

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
		mysql_query(string, SAVE, playerid, db_con2);
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
		mysql_query(string, SAVE, playerid, db_con2);
	}
	return 1;
}

dcmd_afillcarstable(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new string[128];
	for(new i = 1; i <= sizeof(gVehData); i++)
	{
		format(string, sizeof(string), "INSERT INTO `samp_vehicles` (`CarModel`) VALUES ('594') ");
		mysql_query(string, SAVE, playerid, db_con2);
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

		AddExpPoint(giveplayerid);
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
	DynamicZones[zoneid][zFaction] = factionid;
	GangZoneDestroy(zoneid);
	gangZoneIDtmp = GangZoneCreate(DynamicZones[ gGangWar[AreaID] ][zMin_X]*1.0, DynamicZones[ gGangWar[AreaID] ][zMin_Y]*1.0, DynamicZones[ gGangWar[AreaID] ][zMax_X]*1.0, DynamicZones[ gGangWar[AreaID] ][zMax_Y]*1.0);
	for(new i = 0; i < CUSTOM_MAX_PLAYERS; i++)
	{
		if(gPlayerData[i][pFaction] < sizeof(DynamicFactions))
		{
			if(DynamicFactions[ gPlayerData[i][pFaction] ][fType] == 3)
				GangZoneShowForPlayer(i, gangZoneIDtmp, HexToInt( DynamicFactions[ gPlayerData[i][pFaction] ][fColor] ) );
		}
	}
	new string[128];
	format(string, sizeof(string), "[INFO:] Zone id: %d owner set to faction: %s [%d]", zoneid, DynamicFactions[factionid][Name], factionid);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	SaveDynamicZones();
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
	new string[1024];
	new string2[128];
	if( vehicleid == INVALID_VEHICLE_ID )
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Musisz byæ przy baga¿niku aby w³o¿yæ item");
		return 1;
	}
	GetVehiclePos(vehicleid, vx, vy, vz);
	GetVehicleZAngle(vehicleid, va);
	GetPlayerFacingAngle(playerid, ac);
	for(new i = 0; i < sizeof(CarsLenghts); i++)
	{
		if(CarsLenghts[i][lenghtModel] == gVehData[vehicleid-1][CarModel])
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
				if((CarsLenghts[i][trunkAngle] == 1 && !boot) || (CarsLenghts[i][trunkAngle] == 2 && !bonnet))
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Musisz wpierw otworzyæ baga¿nik !");
					return 1;
				}
				gDSelectedVItemVID[playerid] = vehicleid;
				if(CarsLenghts[i][trunkSpace] == 1)
				{
					format(string, sizeof(string), "1. %s [iloœæ: %d] [waga: %d]",
						ItemName(gVehData[vehicleid-1][VItem1type], gVehData[vehicleid-1][VItem1]), VSlotParam6(vehicleid, 1), ItemWeight(gVehData[vehicleid-1][VItem1type], gVehData[vehicleid-1][VItem1]) );
				}
				else if(CarsLenghts[i][trunkSpace] == 2)
				{
					format(string, sizeof(string), "1. %s [iloœæ: %d] [waga: %d]\n2. %s [iloœæ: %d] [waga: %d]",
						ItemName(gVehData[vehicleid-1][VItem1type], gVehData[vehicleid-1][VItem1]), VSlotParam6(vehicleid, 1), ItemWeight(gVehData[vehicleid-1][VItem1type], gVehData[vehicleid-1][VItem1]),
						ItemName(gVehData[vehicleid-1][VItem2type], gVehData[vehicleid-1][VItem2]), VSlotParam6(vehicleid, 2), ItemWeight(gVehData[vehicleid-1][VItem2type], gVehData[vehicleid-1][VItem2]) );
				}
				else if(CarsLenghts[i][trunkSpace] == 3)
				{
					format(string, sizeof(string), "1. %s [iloœæ: %d] [waga: %d]\n2. %s [iloœæ: %d] [waga: %d]\n3. %s [iloœæ: %d] [waga: %d]",
						ItemName(gVehData[vehicleid-1][VItem1type], gVehData[vehicleid-1][VItem1]), VSlotParam6(vehicleid, 1), ItemWeight(gVehData[vehicleid-1][VItem1type], gVehData[vehicleid-1][VItem1]),
						ItemName(gVehData[vehicleid-1][VItem2type], gVehData[vehicleid-1][VItem2]), VSlotParam6(vehicleid, 2), ItemWeight(gVehData[vehicleid-1][VItem2type], gVehData[vehicleid-1][VItem2]),
						ItemName(gVehData[vehicleid-1][VItem3type], gVehData[vehicleid-1][VItem3]), VSlotParam6(vehicleid, 3), ItemWeight(gVehData[vehicleid-1][VItem3type], gVehData[vehicleid-1][VItem3]) );
				}
				else if(CarsLenghts[i][trunkSpace] == 4)
				{
					format(string, sizeof(string), "1. %s [iloœæ: %d] [waga: %d]\n2. %s [iloœæ: %d] [waga: %d]\n3. %s [iloœæ: %d] [waga: %d]\n4. %s [iloœæ: %d] [waga: %d]",
						ItemName(gVehData[vehicleid-1][VItem1type], gVehData[vehicleid-1][VItem1]), VSlotParam6(vehicleid, 1), ItemWeight(gVehData[vehicleid-1][VItem1type], gVehData[vehicleid-1][VItem1]),
						ItemName(gVehData[vehicleid-1][VItem2type], gVehData[vehicleid-1][VItem2]), VSlotParam6(vehicleid, 2), ItemWeight(gVehData[vehicleid-1][VItem2type], gVehData[vehicleid-1][VItem2]),
						ItemName(gVehData[vehicleid-1][VItem3type], gVehData[vehicleid-1][VItem3]), VSlotParam6(vehicleid, 3), ItemWeight(gVehData[vehicleid-1][VItem3type], gVehData[vehicleid-1][VItem3]),
						ItemName(gVehData[vehicleid-1][VItem4type], gVehData[vehicleid-1][VItem4]), VSlotParam6(vehicleid, 4), ItemWeight(gVehData[vehicleid-1][VItem4type], gVehData[vehicleid-1][VItem4]) );
				}
				else if(CarsLenghts[i][trunkSpace] == 5)
				{
					format(string, sizeof(string), "1. %s [iloœæ: %d] [waga: %d]\n2. %s [iloœæ: %d] [waga: %d]\n3. %s [iloœæ: %d] [waga: %d]\n4. %s [iloœæ: %d] [waga: %d]\n5. %s [iloœæ: %d] [waga: %d]",
						ItemName(gVehData[vehicleid-1][VItem1type], gVehData[vehicleid-1][VItem1]), VSlotParam6(vehicleid, 1), ItemWeight(gVehData[vehicleid-1][VItem1type], gVehData[vehicleid-1][VItem1]),
						ItemName(gVehData[vehicleid-1][VItem2type], gVehData[vehicleid-1][VItem2]), VSlotParam6(vehicleid, 2), ItemWeight(gVehData[vehicleid-1][VItem2type], gVehData[vehicleid-1][VItem2]),
						ItemName(gVehData[vehicleid-1][VItem3type], gVehData[vehicleid-1][VItem3]), VSlotParam6(vehicleid, 3), ItemWeight(gVehData[vehicleid-1][VItem3type], gVehData[vehicleid-1][VItem3]),
						ItemName(gVehData[vehicleid-1][VItem4type], gVehData[vehicleid-1][VItem4]), VSlotParam6(vehicleid, 4), ItemWeight(gVehData[vehicleid-1][VItem4type], gVehData[vehicleid-1][VItem4]),
						ItemName(gVehData[vehicleid-1][VItem5type], gVehData[vehicleid-1][VItem5]), VSlotParam6(vehicleid, 5), ItemWeight(gVehData[vehicleid-1][VItem5type], gVehData[vehicleid-1][VItem5]) );
				}
				else if(CarsLenghts[i][trunkSpace] == 6)
				{
					format(string, sizeof(string), "1. %s [iloœæ: %d] [waga: %d]\n2. %s [iloœæ: %d] [waga: %d]\n3. %s [iloœæ: %d] [waga: %d]\n4. %s [iloœæ: %d] [waga: %d]\n5. %s [iloœæ: %d] [waga: %d]\n6. %s [iloœæ: %d] [waga: %d]",
						ItemName(gVehData[vehicleid-1][VItem1type], gVehData[vehicleid-1][VItem1]), VSlotParam6(vehicleid, 1), ItemWeight(gVehData[vehicleid-1][VItem1type], gVehData[vehicleid-1][VItem1]),
						ItemName(gVehData[vehicleid-1][VItem2type], gVehData[vehicleid-1][VItem2]), VSlotParam6(vehicleid, 2), ItemWeight(gVehData[vehicleid-1][VItem2type], gVehData[vehicleid-1][VItem2]),
						ItemName(gVehData[vehicleid-1][VItem3type], gVehData[vehicleid-1][VItem3]), VSlotParam6(vehicleid, 3), ItemWeight(gVehData[vehicleid-1][VItem3type], gVehData[vehicleid-1][VItem3]),
						ItemName(gVehData[vehicleid-1][VItem4type], gVehData[vehicleid-1][VItem4]), VSlotParam6(vehicleid, 4), ItemWeight(gVehData[vehicleid-1][VItem4type], gVehData[vehicleid-1][VItem4]),
						ItemName(gVehData[vehicleid-1][VItem5type], gVehData[vehicleid-1][VItem5]), VSlotParam6(vehicleid, 5), ItemWeight(gVehData[vehicleid-1][VItem5type], gVehData[vehicleid-1][VItem5]),
						ItemName(gVehData[vehicleid-1][VItem6type], gVehData[vehicleid-1][VItem6]), VSlotParam6(vehicleid, 5), ItemWeight(gVehData[vehicleid-1][VItem6type], gVehData[vehicleid-1][VItem6]) );
				}
				else if(CarsLenghts[i][trunkSpace] == 7)
				{
					format(string, sizeof(string), "1. %s [iloœæ: %d] [waga: %d]\n2. %s [iloœæ: %d] [waga: %d]\n3. %s [iloœæ: %d] [waga: %d]\n4. %s [iloœæ: %d] [waga: %d]\n5. %s [iloœæ: %d] [waga: %d]\n6. %s [iloœæ: %d] [waga: %d]\n7. %s [iloœæ: %d] [waga: %d]",
						ItemName(gVehData[vehicleid-1][VItem1type], gVehData[vehicleid-1][VItem1]), VSlotParam6(vehicleid, 1), ItemWeight(gVehData[vehicleid-1][VItem1type], gVehData[vehicleid-1][VItem1]),
						ItemName(gVehData[vehicleid-1][VItem2type], gVehData[vehicleid-1][VItem2]), VSlotParam6(vehicleid, 2), ItemWeight(gVehData[vehicleid-1][VItem2type], gVehData[vehicleid-1][VItem2]),
						ItemName(gVehData[vehicleid-1][VItem3type], gVehData[vehicleid-1][VItem3]), VSlotParam6(vehicleid, 3), ItemWeight(gVehData[vehicleid-1][VItem3type], gVehData[vehicleid-1][VItem3]),
						ItemName(gVehData[vehicleid-1][VItem4type], gVehData[vehicleid-1][VItem4]), VSlotParam6(vehicleid, 4), ItemWeight(gVehData[vehicleid-1][VItem4type], gVehData[vehicleid-1][VItem4]),
						ItemName(gVehData[vehicleid-1][VItem5type], gVehData[vehicleid-1][VItem5]), VSlotParam6(vehicleid, 5), ItemWeight(gVehData[vehicleid-1][VItem5type], gVehData[vehicleid-1][VItem5]),
						ItemName(gVehData[vehicleid-1][VItem6type], gVehData[vehicleid-1][VItem6]), VSlotParam6(vehicleid, 6), ItemWeight(gVehData[vehicleid-1][VItem6type], gVehData[vehicleid-1][VItem6]),
						ItemName(gVehData[vehicleid-1][VItem7type], gVehData[vehicleid-1][VItem7]), VSlotParam6(vehicleid, 7), ItemWeight(gVehData[vehicleid-1][VItem7type], gVehData[vehicleid-1][VItem7]) );
				}
				else if(CarsLenghts[i][trunkSpace] == 8)
				{
					format(string, sizeof(string), "1. %s [iloœæ: %d] [waga: %d]\n2. %s [iloœæ: %d] [waga: %d]\n3. %s [iloœæ: %d] [waga: %d]\n4. %s [iloœæ: %d] [waga: %d]\n5. %s [iloœæ: %d] [waga: %d]\n6. %s [iloœæ: %d] [waga: %d]\n7. %s [iloœæ: %d] [waga: %d]\n8. %s [iloœæ: %d] [waga: %d]",
						ItemName(gVehData[vehicleid-1][VItem1type], gVehData[vehicleid-1][VItem1]), VSlotParam6(vehicleid, 1), ItemWeight(gVehData[vehicleid-1][VItem1type], gVehData[vehicleid-1][VItem1]),
						ItemName(gVehData[vehicleid-1][VItem2type], gVehData[vehicleid-1][VItem2]), VSlotParam6(vehicleid, 2), ItemWeight(gVehData[vehicleid-1][VItem2type], gVehData[vehicleid-1][VItem2]),
						ItemName(gVehData[vehicleid-1][VItem3type], gVehData[vehicleid-1][VItem3]), VSlotParam6(vehicleid, 3), ItemWeight(gVehData[vehicleid-1][VItem3type], gVehData[vehicleid-1][VItem3]),
						ItemName(gVehData[vehicleid-1][VItem4type], gVehData[vehicleid-1][VItem4]), VSlotParam6(vehicleid, 4), ItemWeight(gVehData[vehicleid-1][VItem4type], gVehData[vehicleid-1][VItem4]),
						ItemName(gVehData[vehicleid-1][VItem5type], gVehData[vehicleid-1][VItem5]), VSlotParam6(vehicleid, 5), ItemWeight(gVehData[vehicleid-1][VItem5type], gVehData[vehicleid-1][VItem5]),
						ItemName(gVehData[vehicleid-1][VItem6type], gVehData[vehicleid-1][VItem6]), VSlotParam6(vehicleid, 6), ItemWeight(gVehData[vehicleid-1][VItem6type], gVehData[vehicleid-1][VItem6]),
						ItemName(gVehData[vehicleid-1][VItem7type], gVehData[vehicleid-1][VItem7]), VSlotParam6(vehicleid, 7), ItemWeight(gVehData[vehicleid-1][VItem7type], gVehData[vehicleid-1][VItem7]),
						ItemName(gVehData[vehicleid-1][VItem8type], gVehData[vehicleid-1][VItem8]), VSlotParam6(vehicleid, 8), ItemWeight(gVehData[vehicleid-1][VItem8type], gVehData[vehicleid-1][VItem8]) );
				}
				else if(CarsLenghts[i][trunkSpace] == 9)
				{
					format(string, sizeof(string), "1. %s [iloœæ: %d] [waga: %d]\n2. %s [iloœæ: %d] [waga: %d]\n3. %s [iloœæ: %d] [waga: %d]\n4. %s [iloœæ: %d] [waga: %d]\n5. %s [iloœæ: %d] [waga: %d]\n6. %s [iloœæ: %d] [waga: %d]\n7. %s [iloœæ: %d] [waga: %d]\n8. %s [iloœæ: %d] [waga: %d]\n9. %s [iloœæ: %d] [waga: %d]",
						ItemName(gVehData[vehicleid-1][VItem1type], gVehData[vehicleid-1][VItem1]), VSlotParam6(vehicleid, 1), ItemWeight(gVehData[vehicleid-1][VItem1type], gVehData[vehicleid-1][VItem1]),
						ItemName(gVehData[vehicleid-1][VItem2type], gVehData[vehicleid-1][VItem2]), VSlotParam6(vehicleid, 2), ItemWeight(gVehData[vehicleid-1][VItem2type], gVehData[vehicleid-1][VItem2]),
						ItemName(gVehData[vehicleid-1][VItem3type], gVehData[vehicleid-1][VItem3]), VSlotParam6(vehicleid, 3), ItemWeight(gVehData[vehicleid-1][VItem3type], gVehData[vehicleid-1][VItem3]),
						ItemName(gVehData[vehicleid-1][VItem4type], gVehData[vehicleid-1][VItem4]), VSlotParam6(vehicleid, 4), ItemWeight(gVehData[vehicleid-1][VItem4type], gVehData[vehicleid-1][VItem4]),
						ItemName(gVehData[vehicleid-1][VItem5type], gVehData[vehicleid-1][VItem5]), VSlotParam6(vehicleid, 5), ItemWeight(gVehData[vehicleid-1][VItem5type], gVehData[vehicleid-1][VItem5]),
						ItemName(gVehData[vehicleid-1][VItem6type], gVehData[vehicleid-1][VItem6]), VSlotParam6(vehicleid, 6), ItemWeight(gVehData[vehicleid-1][VItem6type], gVehData[vehicleid-1][VItem6]),
						ItemName(gVehData[vehicleid-1][VItem7type], gVehData[vehicleid-1][VItem7]), VSlotParam6(vehicleid, 7), ItemWeight(gVehData[vehicleid-1][VItem7type], gVehData[vehicleid-1][VItem7]),
						ItemName(gVehData[vehicleid-1][VItem8type], gVehData[vehicleid-1][VItem8]), VSlotParam6(vehicleid, 8), ItemWeight(gVehData[vehicleid-1][VItem8type], gVehData[vehicleid-1][VItem8]),
						ItemName(gVehData[vehicleid-1][VItem9type], gVehData[vehicleid-1][VItem9]), VSlotParam6(vehicleid, 9), ItemWeight(gVehData[vehicleid-1][VItem9type], gVehData[vehicleid-1][VItem9]) );
				}
				else if(CarsLenghts[i][trunkSpace] == 10)
				{
					format(string, sizeof(string), "1. %s [iloœæ: %d] [waga: %d]\n2. %s [iloœæ: %d] [waga: %d]\n3. %s [iloœæ: %d] [waga: %d]\n4. %s [iloœæ: %d] [waga: %d]\n5. %s [iloœæ: %d] [waga: %d]\n6. %s [iloœæ: %d] [waga: %d]\n7. %s [iloœæ: %d] [waga: %d]\n8. %s [iloœæ: %d] [waga: %d]\n9. %s [iloœæ: %d] [waga: %d]\n10. %s [iloœæ: %d] [waga: %d]",
						ItemName(gVehData[vehicleid-1][VItem1type], gVehData[vehicleid-1][VItem1]), VSlotParam6(vehicleid, 1), ItemWeight(gVehData[vehicleid-1][VItem1type], gVehData[vehicleid-1][VItem1]),
						ItemName(gVehData[vehicleid-1][VItem2type], gVehData[vehicleid-1][VItem2]), VSlotParam6(vehicleid, 2), ItemWeight(gVehData[vehicleid-1][VItem2type], gVehData[vehicleid-1][VItem2]),
						ItemName(gVehData[vehicleid-1][VItem3type], gVehData[vehicleid-1][VItem3]), VSlotParam6(vehicleid, 3), ItemWeight(gVehData[vehicleid-1][VItem3type], gVehData[vehicleid-1][VItem3]),
						ItemName(gVehData[vehicleid-1][VItem4type], gVehData[vehicleid-1][VItem4]), VSlotParam6(vehicleid, 4), ItemWeight(gVehData[vehicleid-1][VItem4type], gVehData[vehicleid-1][VItem4]),
						ItemName(gVehData[vehicleid-1][VItem5type], gVehData[vehicleid-1][VItem5]), VSlotParam6(vehicleid, 5), ItemWeight(gVehData[vehicleid-1][VItem5type], gVehData[vehicleid-1][VItem5]),
						ItemName(gVehData[vehicleid-1][VItem6type], gVehData[vehicleid-1][VItem6]), VSlotParam6(vehicleid, 6), ItemWeight(gVehData[vehicleid-1][VItem6type], gVehData[vehicleid-1][VItem6]),
						ItemName(gVehData[vehicleid-1][VItem7type], gVehData[vehicleid-1][VItem7]), VSlotParam6(vehicleid, 7), ItemWeight(gVehData[vehicleid-1][VItem7type], gVehData[vehicleid-1][VItem7]),
						ItemName(gVehData[vehicleid-1][VItem8type], gVehData[vehicleid-1][VItem8]), VSlotParam6(vehicleid, 8), ItemWeight(gVehData[vehicleid-1][VItem8type], gVehData[vehicleid-1][VItem8]),
						ItemName(gVehData[vehicleid-1][VItem9type], gVehData[vehicleid-1][VItem9]), VSlotParam6(vehicleid, 9), ItemWeight(gVehData[vehicleid-1][VItem9type], gVehData[vehicleid-1][VItem9]),
						ItemName(gVehData[vehicleid-1][VItem10type], gVehData[vehicleid-1][VItem10]), VSlotParam6(vehicleid, 10), ItemWeight(gVehData[vehicleid-1][VItem10type], gVehData[vehicleid-1][VItem10]) );
				}
				else if(CarsLenghts[i][trunkSpace] == 11)
				{
					format(string, sizeof(string), "1. %s [iloœæ: %d] [waga: %d]\n2. %s [iloœæ: %d] [waga: %d]\n3. %s [iloœæ: %d] [waga: %d]\n4. %s [iloœæ: %d] [waga: %d]\n5. %s [iloœæ: %d] [waga: %d]\n6. %s [iloœæ: %d] [waga: %d]\n7. %s [iloœæ: %d] [waga: %d]\n8. %s [iloœæ: %d] [waga: %d]\n9. %s [iloœæ: %d] [waga: %d]\n10. %s [iloœæ: %d] [waga: %d]",
						ItemName(gVehData[vehicleid-1][VItem1type], gVehData[vehicleid-1][VItem1]), VSlotParam6(vehicleid, 1), ItemWeight(gVehData[vehicleid-1][VItem1type], gVehData[vehicleid-1][VItem1]),
						ItemName(gVehData[vehicleid-1][VItem2type], gVehData[vehicleid-1][VItem2]), VSlotParam6(vehicleid, 2), ItemWeight(gVehData[vehicleid-1][VItem2type], gVehData[vehicleid-1][VItem2]),
						ItemName(gVehData[vehicleid-1][VItem3type], gVehData[vehicleid-1][VItem3]), VSlotParam6(vehicleid, 3), ItemWeight(gVehData[vehicleid-1][VItem3type], gVehData[vehicleid-1][VItem3]),
						ItemName(gVehData[vehicleid-1][VItem4type], gVehData[vehicleid-1][VItem4]), VSlotParam6(vehicleid, 4), ItemWeight(gVehData[vehicleid-1][VItem4type], gVehData[vehicleid-1][VItem4]),
						ItemName(gVehData[vehicleid-1][VItem5type], gVehData[vehicleid-1][VItem5]), VSlotParam6(vehicleid, 5), ItemWeight(gVehData[vehicleid-1][VItem5type], gVehData[vehicleid-1][VItem5]),
						ItemName(gVehData[vehicleid-1][VItem6type], gVehData[vehicleid-1][VItem6]), VSlotParam6(vehicleid, 6), ItemWeight(gVehData[vehicleid-1][VItem6type], gVehData[vehicleid-1][VItem6]),
						ItemName(gVehData[vehicleid-1][VItem7type], gVehData[vehicleid-1][VItem7]), VSlotParam6(vehicleid, 7), ItemWeight(gVehData[vehicleid-1][VItem7type], gVehData[vehicleid-1][VItem7]),
						ItemName(gVehData[vehicleid-1][VItem8type], gVehData[vehicleid-1][VItem8]), VSlotParam6(vehicleid, 8), ItemWeight(gVehData[vehicleid-1][VItem8type], gVehData[vehicleid-1][VItem8]),
						ItemName(gVehData[vehicleid-1][VItem9type], gVehData[vehicleid-1][VItem9]), VSlotParam6(vehicleid, 9), ItemWeight(gVehData[vehicleid-1][VItem9type], gVehData[vehicleid-1][VItem9]),
						ItemName(gVehData[vehicleid-1][VItem10type], gVehData[vehicleid-1][VItem10]), VSlotParam6(vehicleid, 10), ItemWeight(gVehData[vehicleid-1][VItem10type], gVehData[vehicleid-1][VItem10]) );
					format(string, sizeof(string), "%s\n11. %s [iloœæ: %d] [waga: %d]",
						string,
						ItemName(gVehData[vehicleid-1][VItem11type], gVehData[vehicleid-1][VItem11]), VSlotParam6(vehicleid, 11), ItemWeight(gVehData[vehicleid-1][VItem11type], gVehData[vehicleid-1][VItem11]) );
				}
				else if(CarsLenghts[i][trunkSpace] == 12)
				{
					format(string, sizeof(string), "1. %s [iloœæ: %d] [waga: %d]\n2. %s [iloœæ: %d] [waga: %d]\n3. %s [iloœæ: %d] [waga: %d]\n4. %s [iloœæ: %d] [waga: %d]\n5. %s [iloœæ: %d] [waga: %d]\n6. %s [iloœæ: %d] [waga: %d]\n7. %s [iloœæ: %d] [waga: %d]\n8. %s [iloœæ: %d] [waga: %d]\n9. %s [iloœæ: %d] [waga: %d]\n10. %s [iloœæ: %d] [waga: %d]",
						ItemName(gVehData[vehicleid-1][VItem1type], gVehData[vehicleid-1][VItem1]), VSlotParam6(vehicleid, 1), ItemWeight(gVehData[vehicleid-1][VItem1type], gVehData[vehicleid-1][VItem1]),
						ItemName(gVehData[vehicleid-1][VItem2type], gVehData[vehicleid-1][VItem2]), VSlotParam6(vehicleid, 2), ItemWeight(gVehData[vehicleid-1][VItem2type], gVehData[vehicleid-1][VItem2]),
						ItemName(gVehData[vehicleid-1][VItem3type], gVehData[vehicleid-1][VItem3]), VSlotParam6(vehicleid, 3), ItemWeight(gVehData[vehicleid-1][VItem3type], gVehData[vehicleid-1][VItem3]),
						ItemName(gVehData[vehicleid-1][VItem4type], gVehData[vehicleid-1][VItem4]), VSlotParam6(vehicleid, 4), ItemWeight(gVehData[vehicleid-1][VItem4type], gVehData[vehicleid-1][VItem4]),
						ItemName(gVehData[vehicleid-1][VItem5type], gVehData[vehicleid-1][VItem5]), VSlotParam6(vehicleid, 5), ItemWeight(gVehData[vehicleid-1][VItem5type], gVehData[vehicleid-1][VItem5]),
						ItemName(gVehData[vehicleid-1][VItem6type], gVehData[vehicleid-1][VItem6]), VSlotParam6(vehicleid, 6), ItemWeight(gVehData[vehicleid-1][VItem6type], gVehData[vehicleid-1][VItem6]),
						ItemName(gVehData[vehicleid-1][VItem7type], gVehData[vehicleid-1][VItem7]), VSlotParam6(vehicleid, 7), ItemWeight(gVehData[vehicleid-1][VItem7type], gVehData[vehicleid-1][VItem7]),
						ItemName(gVehData[vehicleid-1][VItem8type], gVehData[vehicleid-1][VItem8]), VSlotParam6(vehicleid, 8), ItemWeight(gVehData[vehicleid-1][VItem8type], gVehData[vehicleid-1][VItem8]),
						ItemName(gVehData[vehicleid-1][VItem9type], gVehData[vehicleid-1][VItem9]), VSlotParam6(vehicleid, 9), ItemWeight(gVehData[vehicleid-1][VItem9type], gVehData[vehicleid-1][VItem9]),
						ItemName(gVehData[vehicleid-1][VItem10type], gVehData[vehicleid-1][VItem10]), VSlotParam6(vehicleid, 10), ItemWeight(gVehData[vehicleid-1][VItem10type], gVehData[vehicleid-1][VItem10]) );
					format(string, sizeof(string), "%s\n11. %s [iloœæ: %d] [waga: %d]\n12. %s [iloœæ: %d] [waga: %d]",
						string,
						ItemName(gVehData[vehicleid-1][VItem11type], gVehData[vehicleid-1][VItem11]),VSlotParam6(vehicleid, 11), ItemWeight(gVehData[vehicleid-1][VItem11type], gVehData[vehicleid-1][VItem11]),
						ItemName(gVehData[vehicleid-1][VItem12type], gVehData[vehicleid-1][VItem12]),VSlotParam6(vehicleid, 12), ItemWeight(gVehData[vehicleid-1][VItem12type], gVehData[vehicleid-1][VItem12]) );
				}
				else if(CarsLenghts[i][trunkSpace] == 13)
				{
					format(string, sizeof(string), "1. %s [iloœæ: %d] [waga: %d]\n2. %s [iloœæ: %d] [waga: %d]\n3. %s [iloœæ: %d] [waga: %d]\n4. %s [iloœæ: %d] [waga: %d]\n5. %s [iloœæ: %d] [waga: %d]\n6. %s [iloœæ: %d] [waga: %d]\n7. %s [iloœæ: %d] [waga: %d]\n8. %s [iloœæ: %d] [waga: %d]\n9. %s [iloœæ: %d] [waga: %d]\n10. %s [iloœæ: %d] [waga: %d]",
						ItemName(gVehData[vehicleid-1][VItem1type], gVehData[vehicleid-1][VItem1]), VSlotParam6(vehicleid, 1), ItemWeight(gVehData[vehicleid-1][VItem1type], gVehData[vehicleid-1][VItem1]),
						ItemName(gVehData[vehicleid-1][VItem2type], gVehData[vehicleid-1][VItem2]), VSlotParam6(vehicleid, 2), ItemWeight(gVehData[vehicleid-1][VItem2type], gVehData[vehicleid-1][VItem2]),
						ItemName(gVehData[vehicleid-1][VItem3type], gVehData[vehicleid-1][VItem3]), VSlotParam6(vehicleid, 3), ItemWeight(gVehData[vehicleid-1][VItem3type], gVehData[vehicleid-1][VItem3]),
						ItemName(gVehData[vehicleid-1][VItem4type], gVehData[vehicleid-1][VItem4]), VSlotParam6(vehicleid, 4), ItemWeight(gVehData[vehicleid-1][VItem4type], gVehData[vehicleid-1][VItem4]),
						ItemName(gVehData[vehicleid-1][VItem5type], gVehData[vehicleid-1][VItem5]), VSlotParam6(vehicleid, 5), ItemWeight(gVehData[vehicleid-1][VItem5type], gVehData[vehicleid-1][VItem5]),
						ItemName(gVehData[vehicleid-1][VItem6type], gVehData[vehicleid-1][VItem6]), VSlotParam6(vehicleid, 6), ItemWeight(gVehData[vehicleid-1][VItem6type], gVehData[vehicleid-1][VItem6]),
						ItemName(gVehData[vehicleid-1][VItem7type], gVehData[vehicleid-1][VItem7]), VSlotParam6(vehicleid, 7), ItemWeight(gVehData[vehicleid-1][VItem7type], gVehData[vehicleid-1][VItem7]),
						ItemName(gVehData[vehicleid-1][VItem8type], gVehData[vehicleid-1][VItem8]), VSlotParam6(vehicleid, 8), ItemWeight(gVehData[vehicleid-1][VItem8type], gVehData[vehicleid-1][VItem8]),
						ItemName(gVehData[vehicleid-1][VItem9type], gVehData[vehicleid-1][VItem9]), VSlotParam6(vehicleid, 9), ItemWeight(gVehData[vehicleid-1][VItem9type], gVehData[vehicleid-1][VItem9]),
						ItemName(gVehData[vehicleid-1][VItem10type], gVehData[vehicleid-1][VItem10]), VSlotParam6(vehicleid, 10), ItemWeight(gVehData[vehicleid-1][VItem10type], gVehData[vehicleid-1][VItem10]) );
					format(string, sizeof(string), "%s\n11. %s [iloœæ: %d] [waga: %d]\n12. %s [iloœæ: %d] [waga: %d]\n13. %s [iloœæ: %d] [waga: %d]",
						string,
						ItemName(gVehData[vehicleid-1][VItem11type], gVehData[vehicleid-1][VItem11]), VSlotParam6(vehicleid, 11), ItemWeight(gVehData[vehicleid-1][VItem11type], gVehData[vehicleid-1][VItem11]),
						ItemName(gVehData[vehicleid-1][VItem12type], gVehData[vehicleid-1][VItem12]), VSlotParam6(vehicleid, 12), ItemWeight(gVehData[vehicleid-1][VItem12type], gVehData[vehicleid-1][VItem12]),
						ItemName(gVehData[vehicleid-1][VItem13type], gVehData[vehicleid-1][VItem13]), VSlotParam6(vehicleid, 13), ItemWeight(gVehData[vehicleid-1][VItem13type], gVehData[vehicleid-1][VItem13]) );
				}
				else if(CarsLenghts[i][trunkSpace] == 14)
				{
					format(string, sizeof(string), "1. %s [iloœæ: %d] [waga: %d]\n2. %s [iloœæ: %d] [waga: %d]\n3. %s [iloœæ: %d] [waga: %d]\n4. %s [iloœæ: %d] [waga: %d]\n5. %s [iloœæ: %d] [waga: %d]\n6. %s [iloœæ: %d] [waga: %d]\n7. %s [iloœæ: %d] [waga: %d]\n8. %s [iloœæ: %d] [waga: %d]\n9. %s [iloœæ: %d] [waga: %d]\n10. %s [iloœæ: %d] [waga: %d]",
						ItemName(gVehData[vehicleid-1][VItem1type], gVehData[vehicleid-1][VItem1]), VSlotParam6(vehicleid, 1), ItemWeight(gVehData[vehicleid-1][VItem1type], gVehData[vehicleid-1][VItem1]),
						ItemName(gVehData[vehicleid-1][VItem2type], gVehData[vehicleid-1][VItem2]), VSlotParam6(vehicleid, 2), ItemWeight(gVehData[vehicleid-1][VItem2type], gVehData[vehicleid-1][VItem2]),
						ItemName(gVehData[vehicleid-1][VItem3type], gVehData[vehicleid-1][VItem3]), VSlotParam6(vehicleid, 3), ItemWeight(gVehData[vehicleid-1][VItem3type], gVehData[vehicleid-1][VItem3]),
						ItemName(gVehData[vehicleid-1][VItem4type], gVehData[vehicleid-1][VItem4]), VSlotParam6(vehicleid, 4), ItemWeight(gVehData[vehicleid-1][VItem4type], gVehData[vehicleid-1][VItem4]),
						ItemName(gVehData[vehicleid-1][VItem5type], gVehData[vehicleid-1][VItem5]), VSlotParam6(vehicleid, 5), ItemWeight(gVehData[vehicleid-1][VItem5type], gVehData[vehicleid-1][VItem5]),
						ItemName(gVehData[vehicleid-1][VItem6type], gVehData[vehicleid-1][VItem6]), VSlotParam6(vehicleid, 6), ItemWeight(gVehData[vehicleid-1][VItem6type], gVehData[vehicleid-1][VItem6]),
						ItemName(gVehData[vehicleid-1][VItem7type], gVehData[vehicleid-1][VItem7]), VSlotParam6(vehicleid, 7), ItemWeight(gVehData[vehicleid-1][VItem7type], gVehData[vehicleid-1][VItem7]),
						ItemName(gVehData[vehicleid-1][VItem8type], gVehData[vehicleid-1][VItem8]), VSlotParam6(vehicleid, 8), ItemWeight(gVehData[vehicleid-1][VItem8type], gVehData[vehicleid-1][VItem8]),
						ItemName(gVehData[vehicleid-1][VItem9type], gVehData[vehicleid-1][VItem9]), VSlotParam6(vehicleid, 9), ItemWeight(gVehData[vehicleid-1][VItem9type], gVehData[vehicleid-1][VItem9]),
						ItemName(gVehData[vehicleid-1][VItem10type], gVehData[vehicleid-1][VItem10]), VSlotParam6(vehicleid, 10), ItemWeight(gVehData[vehicleid-1][VItem10type], gVehData[vehicleid-1][VItem10]) );
					format(string, sizeof(string), "%s\n11. %s [iloœæ: %d] [waga: %d]\n12. %s [iloœæ: %d] [waga: %d]\n13. %s [iloœæ: %d] [waga: %d]\n14. %s [iloœæ: %d] [waga: %d]",
						string,
						ItemName(gVehData[vehicleid-1][VItem11type], gVehData[vehicleid-1][VItem11]), VSlotParam6(vehicleid, 11), ItemWeight(gVehData[vehicleid-1][VItem11type], gVehData[vehicleid-1][VItem11]),
						ItemName(gVehData[vehicleid-1][VItem12type], gVehData[vehicleid-1][VItem12]), VSlotParam6(vehicleid, 12), ItemWeight(gVehData[vehicleid-1][VItem12type], gVehData[vehicleid-1][VItem12]),
						ItemName(gVehData[vehicleid-1][VItem13type], gVehData[vehicleid-1][VItem13]), VSlotParam6(vehicleid, 13), ItemWeight(gVehData[vehicleid-1][VItem13type], gVehData[vehicleid-1][VItem13]),
						ItemName(gVehData[vehicleid-1][VItem14type], gVehData[vehicleid-1][VItem14]), VSlotParam6(vehicleid, 14), ItemWeight(gVehData[vehicleid-1][VItem14type], gVehData[vehicleid-1][VItem14]) );
				}
				else if(CarsLenghts[i][trunkSpace] == 15)
				{
					format(string, sizeof(string), "1. %s [iloœæ: %d] [waga: %d]\n2. %s [iloœæ: %d] [waga: %d]\n3. %s [iloœæ: %d] [waga: %d]\n4. %s [iloœæ: %d] [waga: %d]\n5. %s [iloœæ: %d] [waga: %d]\n6. %s [iloœæ: %d] [waga: %d]\n7. %s [iloœæ: %d] [waga: %d]\n8. %s [iloœæ: %d] [waga: %d]\n9. %s [iloœæ: %d] [waga: %d]\n10. %s [iloœæ: %d] [waga: %d]",
						ItemName(gVehData[vehicleid-1][VItem1type], gVehData[vehicleid-1][VItem1]), VSlotParam6(vehicleid, 1), ItemWeight(gVehData[vehicleid-1][VItem1type], gVehData[vehicleid-1][VItem1]),
						ItemName(gVehData[vehicleid-1][VItem2type], gVehData[vehicleid-1][VItem2]), VSlotParam6(vehicleid, 2), ItemWeight(gVehData[vehicleid-1][VItem2type], gVehData[vehicleid-1][VItem2]),
						ItemName(gVehData[vehicleid-1][VItem3type], gVehData[vehicleid-1][VItem3]), VSlotParam6(vehicleid, 3), ItemWeight(gVehData[vehicleid-1][VItem3type], gVehData[vehicleid-1][VItem3]),
						ItemName(gVehData[vehicleid-1][VItem4type], gVehData[vehicleid-1][VItem4]), VSlotParam6(vehicleid, 4), ItemWeight(gVehData[vehicleid-1][VItem4type], gVehData[vehicleid-1][VItem4]),
						ItemName(gVehData[vehicleid-1][VItem5type], gVehData[vehicleid-1][VItem5]), VSlotParam6(vehicleid, 5), ItemWeight(gVehData[vehicleid-1][VItem5type], gVehData[vehicleid-1][VItem5]),
						ItemName(gVehData[vehicleid-1][VItem6type], gVehData[vehicleid-1][VItem6]), VSlotParam6(vehicleid, 6), ItemWeight(gVehData[vehicleid-1][VItem6type], gVehData[vehicleid-1][VItem6]),
						ItemName(gVehData[vehicleid-1][VItem7type], gVehData[vehicleid-1][VItem7]), VSlotParam6(vehicleid, 7), ItemWeight(gVehData[vehicleid-1][VItem7type], gVehData[vehicleid-1][VItem7]),
						ItemName(gVehData[vehicleid-1][VItem8type], gVehData[vehicleid-1][VItem8]), VSlotParam6(vehicleid, 8), ItemWeight(gVehData[vehicleid-1][VItem8type], gVehData[vehicleid-1][VItem8]),
						ItemName(gVehData[vehicleid-1][VItem9type], gVehData[vehicleid-1][VItem9]), VSlotParam6(vehicleid, 9), ItemWeight(gVehData[vehicleid-1][VItem9type], gVehData[vehicleid-1][VItem9]),
						ItemName(gVehData[vehicleid-1][VItem10type], gVehData[vehicleid-1][VItem10]), VSlotParam6(vehicleid, 10), ItemWeight(gVehData[vehicleid-1][VItem10type], gVehData[vehicleid-1][VItem10]) );
					format(string, sizeof(string), "%s\n11. %s [iloœæ: %d] [waga: %d]\n12. %s [iloœæ: %d] [waga: %d]\n13. %s [iloœæ: %d] [waga: %d]\n14. %s [iloœæ: %d] [waga: %d]\n15. %s [iloœæ: %d] [waga: %d]",
						string,
						ItemName(gVehData[vehicleid-1][VItem11type], gVehData[vehicleid-1][VItem11]), VSlotParam6(vehicleid, 11), ItemWeight(gVehData[vehicleid-1][VItem11type], gVehData[vehicleid-1][VItem11]),
						ItemName(gVehData[vehicleid-1][VItem12type], gVehData[vehicleid-1][VItem12]), VSlotParam6(vehicleid, 12), ItemWeight(gVehData[vehicleid-1][VItem12type], gVehData[vehicleid-1][VItem12]),
						ItemName(gVehData[vehicleid-1][VItem13type], gVehData[vehicleid-1][VItem13]), VSlotParam6(vehicleid, 13), ItemWeight(gVehData[vehicleid-1][VItem13type], gVehData[vehicleid-1][VItem13]),
						ItemName(gVehData[vehicleid-1][VItem14type], gVehData[vehicleid-1][VItem14]), VSlotParam6(vehicleid, 14), ItemWeight(gVehData[vehicleid-1][VItem14type], gVehData[vehicleid-1][VItem14]),
						ItemName(gVehData[vehicleid-1][VItem15type], gVehData[vehicleid-1][VItem15]), VSlotParam6(vehicleid, 15), ItemWeight(gVehData[vehicleid-1][VItem15type], gVehData[vehicleid-1][VItem15]) );
				}
				format(string2, sizeof(string2), "Moje itemy w schowku - waga ca³kowita %d", VItemWeight(vehicleid));
				ShowPlayerDialog(playerid,DIALOG_VITEM_1,DIALOG_STYLE_LIST,string2,string,"Wybierz","Anuluj");
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
		if(CarsLenghts[i][lenghtModel] == gVehData[vehicleid-1][CarModel])
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
	if( gPlayerData[playerid][pCharacterDying] > 0 || gPlayerData[playerid][pCharacterDeath] > 0 )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Jesteœ nieprzytomny, nie mo¿esz u¿ywaæ swoich itemów");
		return 1;
	}
	ShowPItems(playerid);
	return 1;
}

dcmd_mojeitemy(playerid, params[])
{
	#pragma unused params
	if( gPlayerData[playerid][pCharacterDying] > 0 || gPlayerData[playerid][pCharacterDeath] > 0 )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Jesteœ nieprzytomny, nie mo¿esz u¿ywaæ swoich itemów");
		return 1;
	}
	ShowPItems(playerid);
	return 1;
}

dcmd_additem(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] < 4)
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
	if(gPlayerData[playerid][pAdmin] < 4)
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
	ShowPItems(giveplayerid);
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
	gPlayerData[giveplayerid][pVipItem] = getdate() + days;

	SavePlayerData(giveplayerid, "VipItem");

	return 1;
}

dcmd_aservercmds(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] < 1)
		return 0;
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[ADMIN:] /afillcarstable - /carssource - /payday - /vipitem - /savebiz - /afillbiztable - /mysqlcharacterset");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[ADMIN:] /afillhousetable - /housesource - /savehouses - /afillhouseitemstable");
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

dcmd_savebiz(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	SaveBusinesses();
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Rozpoczêto zapis biznesów.");
	return 1;
}

dcmd_afillbiztable(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new string[128];
	for(new i = 0; i < sizeof(Businesses); i++)
	{
		format(string, sizeof(string), "INSERT INTO `samp_businesses` (`BusinessName`) VALUES ('None') ");
		mysql_query(string, SAVE, playerid, db_con2);
	}
	return 1;
}

dcmd_afillhousetable(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new string[128];
	for(new i = 0; i < 200; i++)
	{
		format(string, sizeof(string), "INSERT INTO `samp_houses` (`Owner`) VALUES ('NONE') ");
		mysql_query(string, SAVE, playerid, db_con2);
	}
	return 1;
}

dcmd_afillhouseitemstable(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new string[128];
	for(new i = 0; i < sizeof(Houses); i++)
	{
		format(string, sizeof(string), "INSERT INTO `samp_houses_items` (`HItem1`) VALUES ('0') ");
		mysql_query(string, SAVE, playerid, db_con2);
	}
	return 1;
}

dcmd_savehouses(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	SaveHouses(houseSource);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Rozpoczêto zapis domów.");
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
		format(string, sizeof(string), "SF-000%d", gVehData[vehicleid-1][CarSerial]);
	}
	if(gVehData[vehicleid-1][CarSerial] > 10 && gVehData[vehicleid-1][CarSerial] < 100)
	{
		format(string, sizeof(string), "SF-00%d", gVehData[vehicleid-1][CarSerial]);
	}
	if(gVehData[vehicleid-1][CarSerial] > 100 && gVehData[vehicleid-1][CarSerial] < 1000)
	{
		format(string, sizeof(string), "SF-0%d", gVehData[vehicleid-1][CarSerial]);
	}
	if(gVehData[vehicleid-1][CarSerial] > 1000)
	{
		format(string, sizeof(string), "SF-%d", gVehData[vehicleid-1][CarSerial]);
	}

	// DestroyDynamic3DTextLabel( gVehData[vehicleid-1][Veh3DSerial] );

	if(gVehData[vehicleid-1][CarSerial] > 0)
	{
		if(IsAMotorBike(vehicleid) && gVehData[vehicleid][CarModel] != 522 && gVehData[vehicleid][CarModel] != 471 && gVehData[vehicleid][CarModel] != 468)
		{
			// SetVehicleNumberPlate(vehicleid, string);
			//veh3dserial[vehicleid-1] = CreateDynamic3DTextLabel(string, COLOR_WHITE, 0.0, -1.0, 0.3, 20.0, INVALID_PLAYER_ID, vehicleid, 0);
		}
		if(gVehData[vehicleid][CarModel] == 522 || gVehData[vehicleid][CarModel] == 471 || gVehData[vehicleid][CarModel] == 468)
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
		format(string, sizeof(string), "SF-000%d", gVehData[vehicleid-1][CarSerial]);
	}
	if(gVehData[vehicleid-1][CarSerial] > 10 && gVehData[vehicleid-1][CarSerial] < 100)
	{
		format(string, sizeof(string), "SF-00%d", gVehData[vehicleid-1][CarSerial]);
	}
	if(gVehData[vehicleid-1][CarSerial] > 100 && gVehData[vehicleid-1][CarSerial] < 1000)
	{
		format(string, sizeof(string), "SF-0%d", gVehData[vehicleid-1][CarSerial]);
	}
	if(gVehData[vehicleid-1][CarSerial] > 1000)
	{
		format(string, sizeof(string), "SF-%d", gVehData[vehicleid-1][CarSerial]);
	}

	// DestroyDynamic3DTextLabel( gVehData[vehicleid-1][Veh3DSerial] );

	if(gVehData[vehicleid-1][CarSerial] > 0)
	{
		if(IsAMotorBike(vehicleid) && gVehData[vehicleid][CarModel] != 522 && gVehData[vehicleid][CarModel] != 471 && gVehData[vehicleid][CarModel] != 468)
		{
			// SetVehicleNumberPlate(vehicleid, string);
			//veh3dserial[vehicleid-1] = CreateDynamic3DTextLabel(string, COLOR_WHITE, 0.0, -1.0, 0.3, 20.0, INVALID_PLAYER_ID, vehicleid, 0);
		}
		if(gVehData[vehicleid][CarModel] == 522 || gVehData[vehicleid][CarModel] == 471 || gVehData[vehicleid][CarModel] == 468)
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
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie nale¿ysz do ¿adnej frakcji !");
		return 1;
	}
	if(gPlayerData[playerid][pRank] == 1)
	{
		new fid = gPlayerData[playerid][pFaction];
		new Float:x,Float:y,Float:z;
		GetPlayerPos(playerid, x, y, z);
		DynamicFactions[fid][fXDuty] = x;
		DynamicFactions[fid][fYDuty] = y;
		DynamicFactions[fid][fZDuty] = z;
		DynamicFactions[fid][fWorldDuty] = GetPlayerVirtualWorld(playerid);
		DynamicFactions[fid][fInteriorDuty] = GetPlayerInterior(playerid);

		DestroyDynamicPickup(DynamicFactions[fid][fCP]);
		DynamicFactions[fid][fCP] = CreateDynamicPickup(1239,0,DynamicFactions[fid][fXDuty],DynamicFactions[fid][fYDuty],DynamicFactions[fid][fZDuty],DynamicFactions[fid][fWorldDuty], DynamicFactions[fid][fInteriorDuty], -1, 10.0);

		SaveFData(fid, "XDuty");
		SaveFData(fid, "YDuty");
		SaveFData(fid, "ZDuty");
		SaveFData(fid, "WorldDuty");
		SaveFData(fid, "InteriorDuty");

		SendClientMessage(playerid, COLOR_ADMINCMD, "[INFO:] Ustawi³eœ punkt organizacyjny swojej frakcji");
	}
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
	if(gPlayerData[playerid][pRank] == 1)
	{
		new fid = gPlayerData[playerid][pFaction];
		new Float:x,Float:y,Float:z;
		GetPlayerPos(playerid, x, y, z);
		DynamicFactions[fid][fXDuty2] = x;
		DynamicFactions[fid][fYDuty2] = y;
		DynamicFactions[fid][fZDuty2] = z;
		DynamicFactions[fid][fWorldDuty2] = GetPlayerVirtualWorld(playerid);
		DynamicFactions[fid][fInteriorDuty2] = GetPlayerInterior(playerid);

		DestroyDynamicPickup(DynamicFactions[fid][fCP2]);
		DynamicFactions[fid][fCP2] = CreateDynamicPickup(1239,0,DynamicFactions[fid][fXDuty2],DynamicFactions[fid][fYDuty2],DynamicFactions[fid][fZDuty2],DynamicFactions[fid][fWorldDuty2], DynamicFactions[fid][fInteriorDuty2], -1, 10.0);

		SaveFData(fid, "XDuty2");
		SaveFData(fid, "YDuty2");
		SaveFData(fid, "ZDuty2");
		SaveFData(fid, "WorldDuty2");
		SaveFData(fid, "InteriorDuty2");

		SendClientMessage(playerid, COLOR_ADMINCMD, "[INFO:] Ustawi³eœ punkt organizacyjny swojej frakcji");
	}
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
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Niew³aœciwa frakcja !");
		return 1;
	}
	if((PlayerToPoint(5.0, playerid, DynamicFactions[fid][fXDuty], DynamicFactions[fid][fYDuty], DynamicFactions[fid][fZDuty]) && GetPlayerVirtualWorld(playerid) == DynamicFactions[fid][fWorldDuty]) ||
		   (PlayerToPoint(5.0, playerid, DynamicFactions[fid][fXDuty2], DynamicFactions[fid][fYDuty2], DynamicFactions[fid][fZDuty2]) && GetPlayerVirtualWorld(playerid) == DynamicFactions[fid][fWorldDuty2]))
	{
		if(gPlayerData[playerid][pDuty] == 1)
		{
			SetPlayerSkin(playerid,gPlayerData[playerid][pSkin]);
			gPlayerData[playerid][pDuty] = 0;

			SavePlayerData(playerid, "Duty");

			PlayerActionMessage(playerid, 15.0, "przebiera i odmeldowuje siê z frakcji");

			return 1;
		}
		if(gPlayerData[playerid][pDuty] == 0)
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
	format(string, sizeof(string), "SELECT * FROM samp_factions");
	mysql_query(string, RELOAD_DYNAMIC_FACTIONS, INVALID_PLAYER_ID, db_con1);

	format(string, sizeof(string), "SELECT * FROM samp_factions_weapons");
	mysql_query(string, LOAD_DYNAMIC_FACTIONS_WEAPONS, INVALID_PLAYER_ID, db_con2);

	format(string, sizeof(string), "SELECT * FROM samp_factions_weapons2");
	mysql_query(string, LOAD_DYNAMIC_FACTIONS_WEAPONS2, INVALID_PLAYER_ID, db_con2);

	format(string, sizeof(string), " SELECT * FROM `samp_factions_payrank` ");
	mysql_query(string, LOAD_FACTIONS_PAYRANK, INVALID_PLAYER_ID, db_con2);

	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Rozpoczêto odœwie¿anie danych frakcji");
	return 1;
}

dcmd_wl(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pLevel] <= 4)
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz wy³¹czyæ limitera prêdkoœci dopóki nie zdobêdziesz 5 poziomu postaci !");
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
			if(gVehData[i][BusinessID] == gPlayerData[playerid][pBizKey] && gVehData[i][Owned] == 0 && gVehData[i][FactionCar] == 255)
			{
				if(k == 0)
				{
					format(carS1, sizeof(carS1), "SF-%d", gVehData[i][CarSerial]);
					k++;
				}
				else if(k == 1)
				{
					format(carS2, sizeof(carS2), "SF-%d", gVehData[i][CarSerial]);
					k++;
				}
				else if(k == 2)
				{
					format(carS3, sizeof(carS3), "SF-%d", gVehData[i][CarSerial]);
					k++;
				}
				else if(k == 3)
				{
					format(carS4, sizeof(carS4), "SF-%d", gVehData[i][CarSerial]);
					k++;
				}
				else if(k == 4)
				{
					format(carS5, sizeof(carS5), "SF-%d", gVehData[i][CarSerial]);
					k++;
				}
				else if(k == 5)
				{
					format(carS6, sizeof(carS6), "SF-%d", gVehData[i][CarSerial]);
					k++;
				}
				else if(k == 6)
				{
					format(carS7, sizeof(carS7), "SF-%d", gVehData[i][CarSerial]);
					k++;
				}
				else if(k == 7)
				{
					format(carS8, sizeof(carS8), "SF-%d", gVehData[i][CarSerial]);
					k++;
				}
				else if(k == 8)
				{
					format(carS9, sizeof(carS9), "SF-%d", gVehData[i][CarSerial]);
					k++;
				}
				else if(k == 9)
				{
					format(carS10, sizeof(carS10), "SF-%d", gVehData[i][CarSerial]);
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
	mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
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
	mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
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
	mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
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
	mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
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
	mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
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
	SavePlayerData(playerid, "SeatBelt");

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

dcmd_panoramaon(playerid, params[])
{
	#pragma unused params
	TextDrawShowForPlayer(playerid, Textdraw0);
	TextDrawShowForPlayer(playerid, Textdraw1);
	return 1;
}

dcmd_panoramaoff(playerid, params[])
{
	#pragma unused params
	TextDrawHideForPlayer(playerid, Textdraw0);
	TextDrawHideForPlayer(playerid, Textdraw1);
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
	new string[1024];
	strcat( string, "{FFFFFF}Witaj na serwerze WParty !\n\n" );
	strcat( string, "Aby siê zalogowaæ wpisz swoje has³o do postaci.\n\n\n" );
	strcat( string, "{F52222}Jeœli nie posiadasz jeszcze postaci musisz wpierw zarejestrowaæ swoje konto\nna forum wpartyrp.pl a nastêpnei utworzyæ postaæ\npostêpuj¹æ wed³ug podanych tam wskazówek.\n\n" );
	strcat( string, "{FAEC25}Jeœli zapomnia³eœ has³a do postaci mo¿esz je zmieniæ loguj¹c siê na forum\na nastêpnie przechodz¹c do panelu zarz¹dzania postaciami.\n\n\n" );
	strcat( string, "{FFFFFF}Wpisz has³o:" );
	ShowPlayerDialog(playerid, DIALOG_LOGIN, DIALOG_STYLE_PASSWORD, "Logowanie", string, "Zaloguj", "");
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
	mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Konto zosta³o odbanowane");
	return 1;
}

dcmd_opisdomu(playerid, params[])
{
	new id;
	new dis[64];
	new string[128];
	if(gPlayerData[playerid][pFaction] != 9)
	{
		return 0;
	}
	if(sscanf(params, "ds[64]", id,dis))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /opisdomu [houseid] [opis]");
		return 1;
	}
	new idx = 0;
	new length = strlen(dis);
	while ((idx < length) && (dis[idx] <= ' '))
	{
		idx++;
	}
	new offset = idx;
	new result[64];
	while ((idx < length) && ((idx - offset) < (sizeof(result) - 1)))
	{
		result[idx - offset] = dis[idx];
		idx++;
	}
	result[idx - offset] = EOS;
	if(!strlen(result))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /opisdomu [houseid] [opis]");
		return 1;
	}
	new string2[256];
	format(string2, sizeof(string2), "[GOVERNMENT:] House description changed by: %s, from %s to %s, house id: %d", gPlayerData[playerid][pName], Houses[id][Description], result, id);
	GovermentLog(string2);
	strmid(Houses[id][Description], (result), 0, strlen((result)), 64);
	if(Houses[id][Owned] == 0)
	{
		format(string, sizeof(string), "Opis: %s, Cena: $%d",Houses[id][Description],Houses[id][HousePrice]);
		UpdateDynamic3DTextLabelText(Houses3DTextLabelC[id], COLOR_LIGHTYELLOW2, string);
	}
	else
	{
		if(Houses[id][Rentable] == 1)
		{
			format(string, sizeof(string), "Opis: %s Czynsz: $%d",Houses[id][Description],Houses[id][RentCost]);
			UpdateDynamic3DTextLabelText(Houses3DTextLabelC[id], COLOR_LIGHTYELLOW2, string);
		}
		else
		{
			format(string, sizeof(string), "Opis: %s",Houses[id][Description]);
			UpdateDynamic3DTextLabelText(Houses3DTextLabelC[id], COLOR_LIGHTYELLOW2, string);
		}
	}
	format(string, sizeof(string), "[INFO:] Ustawi³eœ opis domu: %d na %s", id,(result));
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);

	SaveHouseData(id, "Description");
	return 1;
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
	SendClientMessage(playerid, COLOR_RED, "wpartyrp.pl a nastepnie tam przez odpowiedni link stworzyæ konto");
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
	if(DynamicFactions[gPlayerData[playerid][pFaction]][fType] != 1)
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Niew³aœciwy typ frakcji");
		return 1;
	}
	new Float:x, Float:y, Float:z;
	GetPlayerPos( playerid, x, y, z );
	for(new i = 0; i < CUSTOM_MAX_PLAYERS; i++ )
	{
		if(gPlayerData[i][pFaction] != 255 && gPlayerData[i][pGPS] == 1 )
		{
			if( DynamicFactions[gPlayerData[i][pFaction]][fType] != 1 )
				continue;
			SetPlayerCheckpoint(i,x,y,z,10.0);

			ClearCheckpointsForPlayer(playerid);
		}
	}
	new string[128];
	new location[MAX_ZONE_NAME];
	GetPlayer2DZone(playerid, location, MAX_ZONE_NAME);
	format(string, sizeof(string), "[SFPD:] Funkcjonariusz %s potrzebuje wsparcia przy %s", gPlayerData[playerid][pName], location);
	SendFactionTypeMessage(1,COLOR_LSPD,string);
	return 1;
}

dcmd_zmienrejestracje(playerid, params[])
{
	new giveplayerid, id, sn;
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
		new string[128];
		// DestroyDynamic3DTextLabel( gVehData[tmpcar][Veh3DSerial]);

		if(gVehData[tmpcar][CarSerial] < 10)
		{
			format(string, sizeof(string), "SF-000%d", gVehData[tmpcar][CarSerial]);
		}
		if(gVehData[tmpcar][CarSerial] > 10 && gVehData[tmpcar][CarSerial] < 100)
		{
			format(string, sizeof(string), "SF-00%d", gVehData[tmpcar][CarSerial]);
		}
		if(gVehData[tmpcar][CarSerial] > 100 && gVehData[tmpcar][CarSerial] < 1000)
		{
			format(string, sizeof(string), "SF-0%d", gVehData[tmpcar][CarSerial]);
		}
		if(gVehData[tmpcar][CarSerial] > 1000)
		{
			format(string, sizeof(string), "SF-%d", gVehData[tmpcar][CarSerial]);
		}

		if(IsAMotorBike(tmpcar+1) && gVehData[tmpcar][CarModel] != 522 && gVehData[tmpcar][CarModel] != 471 && gVehData[tmpcar][CarModel] != 468)
		{
			SetVehicleNumberPlate(tmpcar+1, string);
		}
		if(gVehData[tmpcar][CarModel] == 522 || gVehData[tmpcar][CarModel] == 471 || gVehData[tmpcar][CarModel] == 468)
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
		format(string, sizeof(string), "Stan pojazdu: %f/1000.0", vHP);
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
			format(string, sizeof(string), "[INFO:] Zaoferowano Tobie kosztorys za kwote %d$ (/akceptuj kosztorys)", cost);
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

			ResetVehicleData(i+1,1);
		}
	}
	return 1;
}

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
		if(CarsData[i][Model] == gVehData[id][CarModel])
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
	GetVehiclePos(id+1, gVehData[id][CarX], gVehData[id][CarY], gVehData[id][CarZ]);
	if(isGasMounting[id])
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Musisz ukoñczyæ wpierw poprzedni¹ czynnoœæ by przejœæ do nastêpnej, b¹dŸ cierpliwy");
		return 1;
	}
	if(gVehData[id][Fuel] == 3)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ten pojazd jest ju¿ wyposa¿ony w instalacje gazow¹");
		return 1;
	}
	if(gVehData[id][GasStep] == 0)
	{
		if(!PlayerToPoint(15.0, playerid, gVehData[id][CarX], gVehData[id][CarY], gVehData[id][CarZ]))
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
		if(!PlayerToPoint(5.0, playerid, gVehData[id][CarX], gVehData[id][CarY], gVehData[id][CarZ]))
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Jesteœ zbyt daleko od pojazdu !");
			return 1;
		}
		PlayerActionMessage(playerid, 15.0, "przygotowuje miejsce");
		gVehData[id][GasStep] = 2;
		isGasMounting[id] = 1;
		gVehData[id][CarDamaged] = 1;
		delay:GasChangingTimer[5000](id);

		SaveVehData(id, "GasStep");
		SaveVehData(id, "CarDamaged");
		return 1;
	}
	if(gVehData[id][GasStep] == 2)
	{
		if(!PlayerToPoint(5.0, playerid, gVehData[id][CarX], gVehData[id][CarY], gVehData[id][CarZ]))
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Jesteœ zbyt daleko od pojazdu !");
			return 1;
		}
		PlayerActionMessage(playerid, 15.0, "montuje zbiornik");
		gVehData[id][GasStep] = 3;
		isGasMounting[id] = 1;
		gVehData[id][CarDamaged] = 1;
		delay:GasChangingTimer[20000](id);

		SaveVehData(id, "GasStep");
		SaveVehData(id, "CarDamaged");
		return 1;
	}
	if(gVehData[id][GasStep] == 3)
	{
		if(!PlayerToPoint(5.0, playerid, gVehData[id][CarX], gVehData[id][CarY], gVehData[id][CarZ]))
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Jesteœ zbyt daleko od pojazdu !");
			return 1;
		}
		PlayerActionMessage(playerid, 15.0, "montuje wskaznik na desce rozdzieczej");
		gVehData[id][GasStep] = 4;
		isGasMounting[id] = 1;
		gVehData[id][CarDamaged] = 1;
		delay:GasChangingTimer[10000](id);

		SaveVehData(id, "GasStep");
		SaveVehData(id, "CarDamaged");
		return 1;
	}
	if(gVehData[id][GasStep] == 4)
	{
		if(!PlayerToPoint(5.0, playerid, gVehData[id][CarX], gVehData[id][CarY], gVehData[id][CarZ]))
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Jesteœ zbyt daleko od pojazdu !");
			return 1;
		}
		PlayerActionMessage(playerid, 15.0, "sprzata pozostalosci, sprawdza instalacje");
		gVehData[id][GasStep] = 5;
		isGasMounting[id] = 1;
		gVehData[id][CarDamaged] = 1;
		delay:GasChangingTimer[20000](id);

		SaveVehData(id, "GasStep");
		SaveVehData(id, "CarDamaged");
		return 1;
	}
	if(gVehData[id][GasStep] == 5)
	{
		if(!PlayerToPoint(5.0, playerid, gVehData[id][CarX], gVehData[id][CarY], gVehData[id][CarZ]))
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
}
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
		delay:WheelChangingTimer[20000](id);

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
		delay:WheelChangingTimer[15000](id);

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
		delay:WheelChangingTimer[25000](id);

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
		delay:WheelChangingTimer[40000](id);

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
		delay:WheelChangingTimer[25000](id);

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
		delay:WheelChangingTimer[50000](id);

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
		delay:WheelChangingTimer[20000](id);

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
		delay:WheelChangingTimer[15000](id);

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
		delay:WheelChangingTimer[25000](id);

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
		delay:WheelChangingTimer[40000](id);

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
		delay:WheelChangingTimer[25000](id);

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
		delay:WheelChangingTimer[50000](id);

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
		delay:WheelChangingTimer[20000](id);

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
		delay:WheelChangingTimer[15000](id);

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
		delay:WheelChangingTimer[25000](id);

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
		delay:WheelChangingTimer[40000](id);

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
		delay:WheelChangingTimer[25000](id);

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
		delay:WheelChangingTimer[50000](id);

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
		delay:WheelChangingTimer[20000](id);

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
		delay:WheelChangingTimer[15000](id);

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
		delay:WheelChangingTimer[25000](id);

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
		delay:WheelChangingTimer[40000](id);

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

// dcmd_afk(playerid, params[])
// {
	// #pragma unused params
	// UpdateDynamic3DTextLabelText(playerAFK[playerid], COLOR_LIGHTBLUE, "AFK");
	// return 1;
// }

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
	if(gVehData[playerVehId-1][CarModel] != 525 && !AdminDuty[playerid] && (!gVehData[playerVehId-1][Hook] || PHaveItem(playerid, 3, 8) == 0))
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

dcmd_onoffneon(playerid, params[])
{
	new slot, vehid;
	vehid = GetPlayerVehicleID(playerid);
	if( vehid == INVALID_VEHICLE_ID )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w pojeŸdzie !");
		return 1;
	}
	if( sscanf( params, "d", slot ) )
	{
		SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] /onoffneon [slot]" );
		SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] slot: 0, 1 lub 2" );
		return 1;
	}
	if( slot > 2 || slot < 0 )
	{
		SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] /onoffneon [slot]" );
		SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] slot: 0, 1 lub 2" );
		return 1;
	}
	if( slot == 0 )
	{
		if( gVehData[vehid-1][CustomObj1On] == 0 )
		{
			if( gVehData[vehid-1][CustomObj1Model] == 0 )
			{
				SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz neonu na tym slocie !");
				return 1;
			}
			gVehData[vehid-1][CustomObj1On] = 1;
			SaveVehData( vehid-1, "CustomObj1On" );
			gVehData[vehid-1][CustomObj1ID] = CreateObject(
				gVehData[vehid-1][CustomObj1Model],
				gVehData[vehid-1][CustomObj1][0],
				gVehData[vehid-1][CustomObj1][1],
				gVehData[vehid-1][CustomObj1][2],
				gVehData[vehid-1][CustomObj1][3],
				gVehData[vehid-1][CustomObj1][4],
				gVehData[vehid-1][CustomObj1][5]);
			AttachObjectToVehicle(gVehData[vehid-1][CustomObj1ID], vehid, gVehData[vehid-1][CustomObj1][0], gVehData[vehid-1][CustomObj1][1], gVehData[vehid-1][CustomObj1][2], gVehData[vehid-1][CustomObj1][3], gVehData[vehid-1][CustomObj1][4], gVehData[vehid-1][CustomObj1][5]);
			return 1;
		}
		else
		{
			gVehData[vehid-1][CustomObj1On] = 0;
			SaveVehData( vehid-1, "CustomObj1On" );
			DestroyObject( gVehData[vehid-1][CustomObj1ID] );
		}
	}
	if( slot == 1 )
	{
		if( gVehData[vehid-1][CustomObj2On] == 0 )
		{
			if( gVehData[vehid-1][CustomObj2Model] == 0 )
			{
				SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz neonu na tym slocie !");
				return 1;
			}
			gVehData[vehid-1][CustomObj2On] = 1;
			SaveVehData( vehid-1, "CustomObj2On" );
			gVehData[vehid-1][CustomObj2ID] = CreateObject(
				gVehData[vehid-1][CustomObj2Model],
				gVehData[vehid-1][CustomObj2][0],
				gVehData[vehid-1][CustomObj2][1],
				gVehData[vehid-1][CustomObj2][2],
				gVehData[vehid-1][CustomObj2][3],
				gVehData[vehid-1][CustomObj2][4],
				gVehData[vehid-1][CustomObj2][5]);
			AttachObjectToVehicle(gVehData[vehid-1][CustomObj2ID], vehid, gVehData[vehid-1][CustomObj2][0], gVehData[vehid-1][CustomObj2][1], gVehData[vehid-1][CustomObj2][2], gVehData[vehid-1][CustomObj2][3], gVehData[vehid-1][CustomObj2][4], gVehData[vehid-1][CustomObj2][5]);
			return 1;
		}
		else
		{
			gVehData[vehid-1][CustomObj2On] = 0;
			SaveVehData( vehid-1, "CustomObj2On" );
			DestroyObject( gVehData[vehid-1][CustomObj2ID] );
		}
	}
	if( slot == 2 )
	{
		if( gVehData[vehid-1][CustomObj3On] == 0 )
		{
			if( gVehData[vehid-1][CustomObj3Model] == 0 )
			{
				SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz neonu na tym slocie !");
				return 1;
			}
			gVehData[vehid-1][CustomObj3On] = 1;
			SaveVehData( vehid-1, "CustomObj3On" );
			gVehData[vehid-1][CustomObj3ID] = CreateObject(
				gVehData[vehid-1][CustomObj3Model],
				gVehData[vehid-1][CustomObj3][0],
				gVehData[vehid-1][CustomObj3][1],
				gVehData[vehid-1][CustomObj3][2],
				gVehData[vehid-1][CustomObj3][3],
				gVehData[vehid-1][CustomObj3][4],
				gVehData[vehid-1][CustomObj3][5]);
			AttachObjectToVehicle(gVehData[vehid-1][CustomObj3ID], vehid, gVehData[vehid-1][CustomObj3][0], gVehData[vehid-1][CustomObj3][1], gVehData[vehid-1][CustomObj3][2], gVehData[vehid-1][CustomObj3][3], gVehData[vehid-1][CustomObj3][4], gVehData[vehid-1][CustomObj3][5]);
			return 1;
		}
		else
		{
			gVehData[vehid-1][CustomObj3On] = 0;
			SaveVehData( vehid-1, "CustomObj3On" );
			DestroyObject( gVehData[vehid-1][CustomObj3ID] );
		}
	}
	return 1;
}

dcmd_doczepneon(playerid, params[])
{
	new color[32], model, slot, Float:Xobj, Float:Yobj, Float:Zobj, Float:rX, Float:rY, Float:rZ, vehid;
	if(!PlayerToPoint(50.0,playerid,MechanicJob1[RepairPointX],MechanicJob1[RepairPointY],MechanicJob1[RepairPointZ]) && !PlayerToPoint(50.0,playerid,-2099.0,-2240.0,30.0))
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Aby doczepiæ neon musisz udaæ siê do warsztatu (mechanik w MG) !");
		return 1;
	}
	if(sscanf(params, "s[32]dffffff", color, slot, Xobj, Yobj, Zobj, rX, rY, rZ))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /doczepneon [kolor] [slot] [X] [Y] [Z] [rX] [rY] [rZ]");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] kolor: czerwony/niebieski/zielony/¿ó³ty/ró¿owy/bia³y");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] slot: 0, 1 lub 2, rXYZ: obrót neona w osiach XYZ");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[U¯YCIEL] X = 0; Y = 0; Z = 0 to œrodek pojazdu");
		return 1;
	}
	if( slot < 0 || slot > 2 )
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /doczepneon [kolor] [slot] [X] [Y] [Z] [rX] [rY] [rZ]");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] kolor: czerwony/niebieski/zielony/¿ó³ty/ró¿owy/bia³y");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] slot: 0, 1 lub 2, rXYZ: obrót neona w osiach XYZ");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[U¯YCIEL] X = 0; Y = 0; Z = 0 to œrodek pojazdu");
		return 1;
	}
	if( strcmp( color, "czerwony", true, sizeof(color) ) == 0 )
	{
		if( gPlayerData[playerid][pVipRedNeon] <= 0 )
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz wykupionego neonu koloru czerwonego !");
			return 1;
		}
		model = 18647;
	}
	else if( strcmp( color, "niebieski", true, sizeof(color) ) == 0 )
	{
		if( gPlayerData[playerid][pVipBlueNeon] <= 0 )
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz wykupionego neonu koloru niebieskiego !");
			return 1;
		}
		model = 18648;
	}
	else if( strcmp( color, "zielony", true, sizeof(color) ) == 0 )
	{
		if( gPlayerData[playerid][pVipGreenNeon] <= 0 )
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz wykupionego neonu koloru zielonego !");
			return 1;
		}
		model = 18649;
	}
	else if( strcmp( color, "¿ó³ty", true, sizeof(color) ) == 0 )
	{
		if( gPlayerData[playerid][pVipYellowNeon] <= 0 )
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz wykupionego neonu koloru ¿ó³tego !");
			return 1;
		}
		model = 18650;
	}
	else if( strcmp( color, "ró¿owy", true, sizeof(color) ) == 0 )
	{
		if( gPlayerData[playerid][pVipPinkNeon] <= 0 )
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz wykupionego neonu koloru ró¿owego !");
			return 1;
		}
		model = 18651;
	}
	else if( strcmp( color, "bia³y", true, sizeof(color) ) == 0 )
	{
		if( gPlayerData[playerid][pVipWhiteNeon] <= 0 )
		{
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz wykupionego neonu koloru bia³ego !");
			return 1;
		}
		model = 18652;
	}
	else
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Poda³eœ niew³aœciwy kolor !");
		return 1;
	}
	vehid = GetPlayerVehicleID(playerid);
	if( vehid == INVALID_VEHICLE_ID )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w pojeŸdzie !");
		return 1;
	}
	if( Xobj > 1.0 )
		Xobj = 1.0;
	else if( Xobj < -1.0 )
		Xobj = -1.0;
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
		if( gVehData[vehid-1][CustomObj1Model] != 0 )
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
		gVehData[vehid-1][CustomObj1ID] = CreateObject(
			gVehData[vehid-1][CustomObj1Model],
			gVehData[vehid-1][CustomObj1][0],
			gVehData[vehid-1][CustomObj1][1],
			gVehData[vehid-1][CustomObj1][2],
			gVehData[vehid-1][CustomObj1][3],
			gVehData[vehid-1][CustomObj1][4],
			gVehData[vehid-1][CustomObj1][5]);
		AttachObjectToVehicle(gVehData[vehid-1][CustomObj1ID], vehid, gVehData[vehid-1][CustomObj1][0], gVehData[vehid-1][CustomObj1][1], gVehData[vehid-1][CustomObj1][2], gVehData[vehid-1][CustomObj1][3], gVehData[vehid-1][CustomObj1][4], gVehData[vehid-1][CustomObj1][5]);
		SaveVehData(vehid-1, "CustomObj1Model" );
		SaveVehData(vehid-1, "CustomObj1", 0 );
		SaveVehData(vehid-1, "CustomObj1", 1 );
		SaveVehData(vehid-1, "CustomObj1", 2 );
		SaveVehData(vehid-1, "CustomObj1", 3 );
		SaveVehData(vehid-1, "CustomObj1", 4 );
		SaveVehData(vehid-1, "CustomObj1", 5 );
		SaveVehData(vehid-1, "CustomObj1On" );
		if( model == 18647 )
		{
			gPlayerData[playerid][pVipRedNeon]--;
			SavePlayerData( playerid, "VipRedNeon" );
			printf("[VIP:] /doczepneon used by %s - color: red", GetPlayerNameEx(playerid));
		}
		else if( model == 18648 )
		{
			gPlayerData[playerid][pVipBlueNeon]--;
			SavePlayerData( playerid, "VipBlueNeon" );
			printf("[VIP:] /doczepneon used by %s - color: blue", GetPlayerNameEx(playerid));
		}
		else if( model == 18649 )
		{
			gPlayerData[playerid][pVipBlueNeon]--;
			SavePlayerData( playerid, "VipGreenNeon" );
			printf("[VIP:] /doczepneon used by %s - color: green", GetPlayerNameEx(playerid));
		}
		else if( model == 18650 )
		{
			gPlayerData[playerid][pVipYellowNeon]--;
			SavePlayerData( playerid, "VipYellowNeon" );
			printf("[VIP:] /doczepneon used by %s - color: yellow", GetPlayerNameEx(playerid));
		}
		else if( model == 18651 )
		{
			gPlayerData[playerid][pVipPinkNeon]--;
			SavePlayerData( playerid, "VipPinkNeon" );
			printf("[VIP:] /doczepneon used by %s - color: pink", GetPlayerNameEx(playerid));
		}
		else if( model == 18652 )
		{
			gPlayerData[playerid][pVipWhiteNeon]--;
			SavePlayerData( playerid, "VipWhiteNeon" );
			printf("[VIP:] /doczepneon used by %s - color: white", GetPlayerNameEx(playerid));
		}
	}
	if( slot == 1 )
	{
		if( gVehData[vehid-1][CustomObj2Model] != 0 )
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
		gVehData[vehid-1][CustomObj2ID] = CreateObject(
			gVehData[vehid-1][CustomObj2Model],
			gVehData[vehid-1][CustomObj2][0],
			gVehData[vehid-1][CustomObj2][1],
			gVehData[vehid-1][CustomObj2][2],
			gVehData[vehid-1][CustomObj2][3],
			gVehData[vehid-1][CustomObj2][4],
			gVehData[vehid-1][CustomObj2][5]);
		AttachObjectToVehicle(gVehData[vehid-1][CustomObj2ID], vehid, gVehData[vehid-1][CustomObj2][0], gVehData[vehid-1][CustomObj2][1], gVehData[vehid-1][CustomObj2][2], gVehData[vehid-1][CustomObj2][3], gVehData[vehid-1][CustomObj2][4], gVehData[vehid-1][CustomObj2][5]);
		SaveVehData(vehid-1, "CustomObj2Model" );
		SaveVehData(vehid-1, "CustomObj2", 0 );
		SaveVehData(vehid-1, "CustomObj2", 1 );
		SaveVehData(vehid-1, "CustomObj2", 2 );
		SaveVehData(vehid-1, "CustomObj2", 3 );
		SaveVehData(vehid-1, "CustomObj2", 4 );
		SaveVehData(vehid-1, "CustomObj2", 5 );
		SaveVehData(vehid-1, "CustomObj2On" );
		if( model == 18647 )
		{
			gPlayerData[playerid][pVipRedNeon]--;
			SavePlayerData( playerid, "VipRedNeon" );
			printf("[VIP:] /doczepneon used by %s - color: red", GetPlayerNameEx(playerid));
		}
		else if( model == 18648 )
		{
			gPlayerData[playerid][pVipBlueNeon]--;
			SavePlayerData( playerid, "VipBlueNeon" );
			printf("[VIP:] /doczepneon used by %s - color: blue", GetPlayerNameEx(playerid));
		}
		else if( model == 18649 )
		{
			gPlayerData[playerid][pVipBlueNeon]--;
			SavePlayerData( playerid, "VipGreenNeon" );
			printf("[VIP:] /doczepneon used by %s - color: green", GetPlayerNameEx(playerid));
		}
		else if( model == 18650 )
		{
			gPlayerData[playerid][pVipYellowNeon]--;
			SavePlayerData( playerid, "VipYellowNeon" );
			printf("[VIP:] /doczepneon used by %s - color: yellow", GetPlayerNameEx(playerid));
		}
		else if( model == 18651 )
		{
			gPlayerData[playerid][pVipPinkNeon]--;
			SavePlayerData( playerid, "VipPinkNeon" );
			printf("[VIP:] /doczepneon used by %s - color: pink", GetPlayerNameEx(playerid));
		}
		else if( model == 18652 )
		{
			gPlayerData[playerid][pVipWhiteNeon]--;
			SavePlayerData( playerid, "VipWhiteNeon" );
			printf("[VIP:] /doczepneon used by %s - color: white", GetPlayerNameEx(playerid));
		}
	}
	if( slot == 2 )
	{
		if( gVehData[vehid-1][CustomObj3Model] != 0 )
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
		gVehData[vehid-1][CustomObj3ID] = CreateObject(
			gVehData[vehid-1][CustomObj3Model],
			gVehData[vehid-1][CustomObj3][0],
			gVehData[vehid-1][CustomObj3][1],
			gVehData[vehid-1][CustomObj3][2],
			gVehData[vehid-1][CustomObj3][3],
			gVehData[vehid-1][CustomObj3][4],
			gVehData[vehid-1][CustomObj3][5]);
		AttachObjectToVehicle(gVehData[vehid-1][CustomObj3ID], vehid, gVehData[vehid-1][CustomObj3][0], gVehData[vehid-1][CustomObj3][1], gVehData[vehid-1][CustomObj3][2], gVehData[vehid-1][CustomObj3][3], gVehData[vehid-1][CustomObj3][4], gVehData[vehid-1][CustomObj3][5]);
		SaveVehData(vehid-1, "CustomObj3Model" );
		SaveVehData(vehid-1, "CustomObj3", 0 );
		SaveVehData(vehid-1, "CustomObj3", 1 );
		SaveVehData(vehid-1, "CustomObj3", 2 );
		SaveVehData(vehid-1, "CustomObj3", 3 );
		SaveVehData(vehid-1, "CustomObj3", 4 );
		SaveVehData(vehid-1, "CustomObj3", 5 );
		SaveVehData(vehid-1, "CustomObj3On" );
		if( model == 18647 )
		{
			gPlayerData[playerid][pVipRedNeon]--;
			SavePlayerData( playerid, "VipRedNeon" );
			printf("[VIP:] /doczepneon used by %s - color: red", GetPlayerNameEx(playerid));
		}
		else if( model == 18648 )
		{
			gPlayerData[playerid][pVipBlueNeon]--;
			SavePlayerData( playerid, "VipBlueNeon" );
			printf("[VIP:] /doczepneon used by %s - color: blue", GetPlayerNameEx(playerid));
		}
		else if( model == 18649 )
		{
			gPlayerData[playerid][pVipBlueNeon]--;
			SavePlayerData( playerid, "VipGreenNeon" );
			printf("[VIP:] /doczepneon used by %s - color: green", GetPlayerNameEx(playerid));
		}
		else if( model == 18650 )
		{
			gPlayerData[playerid][pVipYellowNeon]--;
			SavePlayerData( playerid, "VipYellowNeon" );
			printf("[VIP:] /doczepneon used by %s - color: yellow", GetPlayerNameEx(playerid));
		}
		else if( model == 18651 )
		{
			gPlayerData[playerid][pVipPinkNeon]--;
			SavePlayerData( playerid, "VipPinkNeon" );
			printf("[VIP:] /doczepneon used by %s - color: pink", GetPlayerNameEx(playerid));
		}
		else if( model == 18652 )
		{
			gPlayerData[playerid][pVipWhiteNeon]--;
			SavePlayerData( playerid, "VipWhiteNeon" );
			printf("[VIP:] /doczepneon used by %s - color: white", GetPlayerNameEx(playerid));
		}
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
			DestroyObject(gVehData[vehid-1][CustomObj1ID]);
		gVehData[vehid-1][CustomObj1ID] = CreateObject(
																	gVehData[vehid-1][CustomObj1Model],
																	gVehData[vehid-1][CustomObj1][0],
																	gVehData[vehid-1][CustomObj1][1],
																	gVehData[vehid-1][CustomObj1][2],
																	gVehData[vehid-1][CustomObj1][3],
																	gVehData[vehid-1][CustomObj1][4],
																	gVehData[vehid-1][CustomObj1][5]);
		AttachObjectToVehicle(gVehData[vehid-1][CustomObj1ID], vehid, gVehData[vehid-1][CustomObj1][0], gVehData[vehid-1][CustomObj1][1], gVehData[vehid-1][CustomObj1][2], gVehData[vehid-1][CustomObj1][3], gVehData[vehid-1][CustomObj1][4], gVehData[vehid-1][CustomObj1][5]);
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
			DestroyObject(gVehData[vehid-1][CustomObj2ID]);
		gVehData[vehid-1][CustomObj2ID] = CreateObject(
																	gVehData[vehid-1][CustomObj2Model],
																	gVehData[vehid-1][CustomObj2][0],
																	gVehData[vehid-1][CustomObj2][1],
																	gVehData[vehid-1][CustomObj2][2],
																	gVehData[vehid-1][CustomObj2][3],
																	gVehData[vehid-1][CustomObj2][4],
																	gVehData[vehid-1][CustomObj2][5]);
		AttachObjectToVehicle(gVehData[vehid-1][CustomObj2ID], vehid, gVehData[vehid-1][CustomObj2][0], gVehData[vehid-1][CustomObj2][1], gVehData[vehid-1][CustomObj2][2], gVehData[vehid-1][CustomObj2][3], gVehData[vehid-1][CustomObj2][4], gVehData[vehid-1][CustomObj2][5]);
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
			DestroyObject(gVehData[vehid-1][CustomObj3ID]);
		gVehData[vehid-1][CustomObj3ID] = CreateObject(
																	gVehData[vehid-1][CustomObj3Model],
																	gVehData[vehid-1][CustomObj3][0],
																	gVehData[vehid-1][CustomObj3][1],
																	gVehData[vehid-1][CustomObj3][2],
																	gVehData[vehid-1][CustomObj3][3],
																	gVehData[vehid-1][CustomObj3][4],
																	gVehData[vehid-1][CustomObj3][5]);
		AttachObjectToVehicle(gVehData[vehid-1][CustomObj3ID], vehid, gVehData[vehid-1][CustomObj3][0], gVehData[vehid-1][CustomObj3][1], gVehData[vehid-1][CustomObj3][2], gVehData[vehid-1][CustomObj3][3], gVehData[vehid-1][CustomObj3][4], gVehData[vehid-1][CustomObj3][5]);
		SaveVehData(vehid-1, "CustomObj3Model" );
		SaveVehData(vehid-1, "CustomObj3", 0 );
		SaveVehData(vehid-1, "CustomObj3", 1 );
		SaveVehData(vehid-1, "CustomObj3", 2 );
		SaveVehData(vehid-1, "CustomObj3", 3 );
		SaveVehData(vehid-1, "CustomObj3", 4 );
		SaveVehData(vehid-1, "CustomObj3", 5 );
	}
	return 1;
}

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
		DestroyObject(gVehData[vehid-1][CustomObj1ID]);
	if( slot == 1 )
		DestroyObject(gVehData[vehid-1][CustomObj2ID]);
	if( slot == 2 )
		DestroyObject(gVehData[vehid-1][CustomObj3ID]);
	return 1;
}

dcmd_ustawneon(playerid, params[])
{
	new slot, Float:mx, Float:my, Float:mz;
	if(sscanf(params, "dfff", slot, mx, my, mz))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /ustawneon [slot] [x] [y] [z]");
		return 1;
	}
	new vehid = GetPlayerVehicleID(playerid);
	vehid = GetPlayerVehicleID(playerid);
	if( vehid == INVALID_VEHICLE_ID )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w pojeŸdzie !");
		return 1;
	}
	if( mx > 1.5 )
		mx = 1.5;
	else if( mx < -1.5 )
		mx = -1.5;
	if( my > 3.3 )
		my = 3.3;
	else if( my < -3.5 )
		my = -3.5;
	if( mz > 2.0 )
		mz = 2.0;
	else if( mz < -1.5 )
		mz = -1.5;
	if( slot < 0 || slot > 2 )
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /ustawneon [slot (0-2)] [x] [y] [z]");
		return 1;
	}
	if( slot == 0)
	{
		if( gVehData[vehid-1][CustomObj1On] && gVehData[vehid-1][CustomObj1Model] != 0 )
		{
			gVehData[vehid-1][CustomObj1][0] = mx;
			gVehData[vehid-1][CustomObj1][1] = my;
			gVehData[vehid-1][CustomObj1][2] = mz;
			SaveVehData( vehid-1, "CustomObj1", 0 );
			SaveVehData( vehid-1, "CustomObj1", 1 );
			SaveVehData( vehid-1, "CustomObj1", 2 );
			AttachObjectToVehicle( gVehData[vehid-1][CustomObj1ID], vehid, gVehData[vehid-1][CustomObj1][0], gVehData[vehid-1][CustomObj1][1], gVehData[vehid-1][CustomObj1][2], gVehData[vehid-1][CustomObj1][3], gVehData[vehid-1][CustomObj1][4], gVehData[vehid-1][CustomObj1][5] );
		}
	}
	if( slot == 1)
	{
		if( gVehData[vehid-1][CustomObj2On] && gVehData[vehid-1][CustomObj2Model] != 0 )
		{
			gVehData[vehid-1][CustomObj2][0] = mx;
			gVehData[vehid-1][CustomObj2][1] = my;
			gVehData[vehid-1][CustomObj2][2] = mz;
			SaveVehData( vehid-1, "CustomObj2", 0 );
			SaveVehData( vehid-1, "CustomObj2", 1 );
			SaveVehData( vehid-1, "CustomObj2", 2 );
			AttachObjectToVehicle( gVehData[vehid-1][CustomObj2ID], vehid, gVehData[vehid-1][CustomObj2][0], gVehData[vehid-1][CustomObj2][1], gVehData[vehid-1][CustomObj2][2], gVehData[vehid-1][CustomObj2][3], gVehData[vehid-1][CustomObj2][4], gVehData[vehid-1][CustomObj2][5] );
		}
	}
	if( slot == 2)
	{
		if( gVehData[vehid-1][CustomObj3On] && gVehData[vehid-1][CustomObj3Model] != 0 )
		{
			gVehData[vehid-1][CustomObj3][0] = mx;
			gVehData[vehid-1][CustomObj3][1] = my;
			gVehData[vehid-1][CustomObj3][2] = mz;
			SaveVehData( vehid-1, "CustomObj3", 0 );
			SaveVehData( vehid-1, "CustomObj3", 1 );
			SaveVehData( vehid-1, "CustomObj3", 2 );
			AttachObjectToVehicle(gVehData[vehid-1][CustomObj3ID], vehid, gVehData[vehid-1][CustomObj3][0], gVehData[vehid-1][CustomObj3][1], gVehData[vehid-1][CustomObj3][2], gVehData[vehid-1][CustomObj3][3], gVehData[vehid-1][CustomObj3][4], gVehData[vehid-1][CustomObj3][5]);
		}
	}
	new string[128];
	format(string, sizeof(string), "[INFO:] Nowa pozycja neonu X: %f, Y: %f, Z: %f", mx, my, mz);
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	return 1;
}

dcmd_obrocneon(playerid, params[])
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
			AttachObjectToVehicle( gVehData[vehid-1][CustomObj1ID], vehid, gVehData[vehid-1][CustomObj1][0], gVehData[vehid-1][CustomObj1][1], gVehData[vehid-1][CustomObj1][2], gVehData[vehid-1][CustomObj1][3], gVehData[vehid-1][CustomObj1][4], gVehData[vehid-1][CustomObj1][5] );
		}
	}
	if( slot == 1 )
	{
		if( gVehData[vehid-1][CustomObj1Model] != 0 && gVehData[vehid-1][CustomObj1On] )
		{
			gVehData[vehid-1][CustomObj2][3] = mx;
			gVehData[vehid-1][CustomObj2][4] = my;
			gVehData[vehid-1][CustomObj2][5] = mz;
			SaveVehData( vehid-1, "CustomObj2", 3 );
			SaveVehData( vehid-1, "CustomObj2", 4 );
			SaveVehData( vehid-1, "CustomObj2", 5 );
			AttachObjectToVehicle( gVehData[vehid-1][CustomObj2ID], vehid, gVehData[vehid-1][CustomObj2][0], gVehData[vehid-1][CustomObj2][1], gVehData[vehid-1][CustomObj2][2], gVehData[vehid-1][CustomObj2][3], gVehData[vehid-1][CustomObj2][4], gVehData[vehid-1][CustomObj2][5] );
		}
	}
	if( slot == 2 )
	{
		if( gVehData[vehid-1][CustomObj1Model] != 0 && gVehData[vehid-1][CustomObj1On] )
		{
			gVehData[vehid-1][CustomObj3][3] = mx;
			gVehData[vehid-1][CustomObj3][4] = my;
			gVehData[vehid-1][CustomObj3][5] = mz;
			SaveVehData( vehid-1, "CustomObj3", 3 );
			SaveVehData( vehid-1, "CustomObj3", 4 );
			SaveVehData( vehid-1, "CustomObj3", 5 );
			AttachObjectToVehicle(gVehData[vehid-1][CustomObj3ID], vehid, gVehData[vehid-1][CustomObj3][0], gVehData[vehid-1][CustomObj3][1], gVehData[vehid-1][CustomObj3][2], gVehData[vehid-1][CustomObj3][3], gVehData[vehid-1][CustomObj3][4], gVehData[vehid-1][CustomObj3][5]);
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
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /movobj [slot] [x] [y] [z]");
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
	if(	gCustomObjShow[playerid] ) { gCustomObjShow[playerid] = 0; } else { gCustomObjShow[playerid] = 1; }
	for( new i = 0; i < sizeof(gCustomObj); i++ )
	{
		if( gCustomObj[i][cstSlotUsed] )
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
	for( new i = 0; i < sizeof(gCustomObj); i++ )
	{
		if( !gCustomObj[i][cstSlotUsed] )
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

dcmd_stworzobiekt(playerid, params[])
{
	if( gPlayerData[playerid][pLevel] < 2 )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Musisz osi¹gn¹æ 2 poziom postaci aby móc tworzyæ obiekty !" );
		return 1;
	}
	new modelid, Float:Xobj, Float:Yobj, Float:Zobj, Float:rX, Float:rY, Float:rZ, vw, interior, string[128], allowed = 0;
	if( CountPlayerObjects(playerid) >= gPlayerData[playerid][pVipCustomObjects]+10 )
	{
		format( string, sizeof(string), "[INFO:] Osi¹gn¹³eœ limit obiektów (%d) !", gPlayerData[playerid][pVipCustomObjects]+10 );
		SendClientMessage( playerid, COLOR_ORANGE, string );
		return 1;
	}
	if(IsPlayerInDynamicArea(playerid, gArea_Prison1) && gPlayerData[playerid][pAdmin] == 0)
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
	for( new i = 0; i < sizeof(gCustomObj); i++ )
	{
		if( !gCustomObj[i][cstSlotUsed] )
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
	AttachObjectToVehicle(objID, vehID, OffsetX, OffsetY, OffsetZ, RotX, RotY, RotZ);
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
	new vehicleid = GetClosestVehicle(playerid);
	if(IsABoat(vehicleid) == 0 && IsABike(vehicleid) == 0 && IsAPlane(vehicleid) == 0 && IsAHelicopter(vehicleid) == 0 && IsAMotorBike(vehicleid) == 0)
	{
		new enginedyn, lights, alarm, bonnet, boot, objective, doors;
		GetVehicleParamsEx(vehicleid, enginedyn, lights, alarm, doors, bonnet, boot, objective);
		if(bonnet)
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Maska jest ju¿ otwarta !");
		else
		{
			SetVehicleParamsEx(vehicleid, enginedyn, lights, alarm, doors, 1, boot, objective);
			PlayerActionMessage(playerid, 15.0, "otwiera maske pojazdu");
			gVehData[vehicleid-1][BonnetUp] = 1;
			SaveVehData(vehicleid-1, "BonnetUp");
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
		if(CarsLenghts[i][lenghtModel] == gVehData[vehicleid-1][CarModel])
		{
			GetXYInFrontOfPlayer(playerid, xc, yc, CarsLenghts[i][hoodDistance]);
			if(CarsLenghts[i][hoodAngle] == 1)
			{
				if(ac-180.0 < 0.0)
					ac += 180.0;
				else
					ac -= 180.0;
			}
			if( ( floatabs(xc-vx) > 0.9 || floatabs(yc-vy) > 0.9 ) ||
				floatabs(va-ac) > 28.0)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Jesteœ zbyt daleko od pojazdu ¿eby zamkn¹æ maske !");
				return 1;
			}
			else
			{
				if(IsABoat(vehicleid) == 0 && IsABike(vehicleid) == 0 && IsAPlane(vehicleid) == 0 && IsAHelicopter(vehicleid) == 0 && IsAMotorBike(vehicleid) == 0)
				{
					new enginedyn,lights,alarm,bonnet,boot,objective,doors;
					GetVehicleParamsEx(vehicleid, enginedyn, lights, alarm, doors, bonnet, boot, objective);
					if(CarsLenghts[i][hoodAngle] == 0)
					{
						if(!boot)
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Maska jest ju¿ zamkniêta !");
						else
						{
							SetVehicleParamsEx(vehicleid, enginedyn, lights, alarm, doors, 0, boot, objective);
							PlayerActionMessage(playerid, 15.0, "zamyka maske pojazdu");
							gVehData[vehicleid-1][BootUp] = 0;
							SaveVehData(vehicleid-1, "BootUp");
						}
					}
					else
					{
						if(!bonnet)
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Maska jest ju¿ zamkniêta !");
						else
						{
							SetVehicleParamsEx(vehicleid, enginedyn, lights, alarm, doors, 0, boot, objective);
							PlayerActionMessage(playerid, 15.0, "zamyka maske pojazdu");
							gVehData[vehicleid-1][BonnetUp] = 0;
							SaveVehData(vehicleid-1, "BonnetUp");
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
		if(CarsLenghts[i][lenghtModel] == gVehData[vehicleid-1][CarModel])
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
				if(IsABoat(vehicleid) == 0 && IsABike(vehicleid) == 0 && IsAPlane(vehicleid) == 0 && IsAHelicopter(vehicleid) == 0)
				{
					new enginedyn,lights,alarm,bonnet,boot,objective,doors;
					GetVehicleParamsEx(vehicleid, enginedyn, lights, alarm, doors, bonnet, boot, objective);
					if(CarsLenghts[i][trunkAngle])
					{
						if(!bonnet)
							PlayerActionMessage(playerid, 15.0, "sprawdza baga¿nik");
						else
						{
							PlayerActionMessage(playerid, 15.0, "zamyka baga¿nik pojazdu");
							SetVehicleParamsEx(vehicleid, enginedyn, lights, alarm, doors, 0, boot, objective);
							gVehData[vehicleid-1][BonnetUp] = 0;
							SaveVehData(vehicleid-1, "BonnetUp");
						}
					}
					else
					{
						if(!boot)
							PlayerActionMessage(playerid, 15.0, "sprawdza baga¿nik");
						else
						{
							PlayerActionMessage(playerid, 15.0, "zamyka baga¿nik pojazdu");
							SetVehicleParamsEx(vehicleid, enginedyn, lights, alarm, doors, bonnet, 0, objective);
							gVehData[vehicleid-1][BootUp] = 0;
							SaveVehData(vehicleid-1, "BootUp");
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
		if(CarsLenghts[i][lenghtModel] == gVehData[vehicleid-1][CarModel])
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
				new enginedyn, lights, alarm, bonnet, boot, objective, doors;
				GetVehicleParamsEx(vehicleid, enginedyn, lights, alarm, doors, bonnet, boot, objective);
				if(doors == 1)
				{
					SendClientMessage(playerid, COLOR_RED, "[INFO:] Pojazd jest zamkniêty, nie mo¿esz otworzyæ baga¿nika");
					return 1;
				}
				if(IsABoat(vehicleid) == 0 && IsABike(vehicleid) == 0 && IsAPlane(vehicleid) == 0 && IsAHelicopter(vehicleid) == 0 )
				{
					if(CarsLenghts[i][trunkAngle])
					{
						if(bonnet)
							SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] Baga¿nik jest ju¿ otwarty !" );
						else
						{
							PlayerActionMessage(playerid, 15.0, "otwiera baga¿nik pojazdu");
							SetVehicleParamsEx(vehicleid,enginedyn,lights,alarm,doors,bonnet,1,objective);
							gVehData[vehicleid-1][BonnetUp] = 1;
							SaveVehData(vehicleid-1, "BonnetUp");
						}
					}
					else
					{
						if(boot)
							SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] Baga¿nik jest ju¿ otwarty !" );
						else
						{
							PlayerActionMessage(playerid, 15.0, "otwiera baga¿nik pojazdu");
							SetVehicleParamsEx(vehicleid,enginedyn,lights,alarm,doors,bonnet,1,objective);
							gVehData[vehicleid-1][BootUp] = 1;
							SaveVehData(vehicleid-1, "BootUp");
						}
					}
				}
			}
		}
	}
	return 1;
}

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
}

dcmd_kolczatka(playerid, params[])
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
	new Float:Xj, Float:Yj,Float:Zj, Float:angle;
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
	SetPlayerVirtualWorld(playerid, gVehData[id-1][CarVW]);
	SetPlayerInterior(playerid, gVehData[id-1][CarInterior]);
	PutPlayerIntoVehicle(playerid,id+1,0);
	return 1;
}

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
}

dcmd_zamontujalarm(playerid, params[])
{
	if(gPlayerData[playerid][pJob] != 17)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ mechanikiem !");
		return 1;
	}
	new vehicleID = INVALID_VEHICLE_ID;
	if(sscanf(params, "d", vehicleID))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /zamontujalarm [rejestracja]");
		return 1;
	}
	if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Musisz byæ przy pojeŸdzie aby zamontowaæ alarm !");
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
	new slot = PHaveItem(playerid, 1, 11);
	if(slot == 0)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz alarmu samochodowego do zamontowania !");
		return 1;
	}
	RemovePlayerItemExUsed(playerid, slot);
	PlayerActionMessage(playerid,15.0, "montuje alarm samochodowy");
	gVehData[vehicleID][Alarm] = 1;
	SaveVehData(vehicleID, "Alarm");
	SendClientMessage(playerid, COLOR_GREEN, "[INFO:] Zamontowa³eœ alarm !");
	return 1;
}

dcmd_c3dtv(playerid, params[])
{
	new Text3D:objid, Float:xpos, Float:ypos, Float:zpos, vehicleID;
	new string[128];
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;

	if(sscanf(params, "s[128]dfff", string, vehicleID, xpos, ypos, zpos))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /c3dtv [string] [vehid] [x] [y] [z]");
		return 1;
	}

	objid = CreateDynamic3DTextLabel(string, COLOR_LIGHTYELLOW, xpos, ypos, zpos, 50.0, INVALID_PLAYER_ID, vehicleID, 1);
	format(string, sizeof(string), "[INFO:] id obiektu: %d", objid);
	SendClientMessage(playerid, COLOR_GREEN, string);
	return 1;
}

dcmd_d3dt(playerid, params[])
{
	new Text3D:objid;
	if(gPlayerData[playerid][pAdmin] != 3)
		return 0;

	if(sscanf(params, "d", objid))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /c3dtv [objid]");
		return 1;
	}

	DestroyDynamic3DTextLabel(objid);
	return 1;
}

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
	gVehData[vehicleid-1][CarModel] = carmodel;
	GetVehiclePos(vehicleid, gVehData[vehicleid-1][CarX], gVehData[vehicleid-1][CarY], gVehData[vehicleid-1][CarZ]);
	GetVehicleZAngle(vehicleid, gVehData[vehicleid-1][CarAngle]);
	DestroyVehicle(vehicleid);
	CreateVehicle(gVehData[vehicleid-1][CarModel],gVehData[vehicleid-1][CarX],gVehData[vehicleid-1][CarY],gVehData[vehicleid-1][CarZ],gVehData[vehicleid-1][CarAngle],gVehData[vehicleid-1][CarColor1],gVehData[vehicleid-1][CarColor2],-1);
	PutPlayerInVehicle(playerid,vehicleid,0);
	new enginedyn,lights,alarm,doors,bonnet,boot,objective;
	GetVehicleParamsEx(vehicleid,enginedyn,lights,alarm,doors,bonnet,boot,objective);
	SetVehicleParamsEx(vehicleid,gVehData[vehicleid-1][EngineOn],gVehData[vehicleid-1][LightsOn],alarm,0,gVehData[vehicleid-1][BonnetUp],gVehData[vehicleid-1][BootUp],objective);
	SendClientMessage(playerid, COLOR_GREEN, "[INFO:] Zmieni³eœ model pojazdu");
	SaveVehData(vehicleid-1, "CarModel");
	SaveVehData(vehicleid-1, "CarPos");
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
	gVehData[vehicleid-1][CarColor1] = color1;
	gVehData[vehicleid-1][CarColor2] = color2;
	ChangeVehicleColor(vehicleid, color1, color2);
	SendClientMessage(playerid, COLOR_GREEN, "[INFO:] Zmieni³eœ kolor pojazdu");
	SaveVehData(vehicleid-1, "CarColor1");
	SaveVehData(vehicleid-1, "CarColor2");
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
	gVehData[vehicleid-1][CarColor1] = color1;
	gVehData[vehicleid-1][CarColor2] = color2;
	ChangeVehicleColor(vehicleid, color1, color2);
	SendClientMessage(playerid, COLOR_GREEN, "[INFO:] Zmieni³eœ kolor pojazdu");
	SaveVehData(vehicleid-1, "CarColor1");
	SaveVehData(vehicleid-1, "CarColor2");
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

dcmd_gotosf(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] < 1)
		return 0;

	new vehicleid = GetPlayerVehicleID(playerid);
	if(vehicleid == 0)
		SetPlayerToPos(playerid, -1417.0,-295.8,14.1);
	else
		SetVehicleToPos(vehicleid, -1417.0,-295.8,14.1);
	SetPlayerInterior(playerid,0);
	SetPlayerVirtualWorld(playerid,0);
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
	GetVehiclePos(vehicleid, gVehData[vehicleid-1][CarX], gVehData[vehicleid-1][CarY], gVehData[vehicleid-1][CarZ]);
	GetVehicleZAngle(vehicleid, gVehData[vehicleid-1][CarAngle]);

	SaveVehData(vehicleid-1, "CarPos");

	new wstring[128];
	format(wstring, sizeof(wstring), "[ADMIN:] %s has parked vehicle ID %d.", gPlayerData[playerid][pName],vehicleid);
	SendAdminMessage(COLOR_YELLOW, wstring);
	return 1;
}

dcmd_avehfueltype(playerid, params[])
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
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /avehfueltype [typ paliwa]");
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

dcmd_wantedex(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pFaction] == 255)
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Niew³aœciwa frakcja !");
		return 1;
	}
	if(DynamicFactions[gPlayerData[playerid][pFaction]][fType] != 1)
	{
		SendClientMessage(playerid, COLOR_RED, "[INFO:] Niew³aœciwa frakcja !");
		return 1;
	}
	ShowPlayerDialog(playerid, DIALOG_WANTED, DIALOG_STYLE_INPUT, "Wanted", "Wpisz imie oraz nazwisko osoby w formie \"Imie_Nazwisko\"", "Wyszukaj", "Anuluj");
	return 1;
}

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
		if(PlayerToPoint(2.0,playerid,Houses[i][EnterX],Houses[i][EnterY],Houses[i][EnterZ])
		&& GetPlayerVirtualWorld(playerid) == Houses[i][EnterWorld])
		{
			if(gLastHVisit[playerid][i] > 0)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ktoœ ju¿ rzuci³ gazete pod tym domem, wróæ póŸniej !");
				return 1;
			}
			PlayerActionMessage(playerid,10.0,"rzuca gazete");
			gPapers[playerid]--;
			format(string, sizeof(string), "[INFO:] Pozosta³o gazet: %d", gPapers[playerid]);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			GivePlayerCash(playerid,NewsBoyJob[TakeJobReward]);
			gLastHVisit[playerid][i] = 300;
			DynamicFactions[FACTIONID_GOVERNMENT][fBank] -= NewsBoyJob[TakeJobReward];
			SaveFData(FACTIONID_GOVERNMENT, "Bank");
			return 1;
		}
	}
	for(new i = 0; i < sizeof(Businesses); i++)
	{
		if(PlayerToPoint(2.0,playerid,Businesses[i][EnterX],Businesses[i][EnterY],Businesses[i][EnterZ])
		&& GetPlayerVirtualWorld(playerid) == Businesses[i][EnterWorld])
		{
			if(gLastBVisit[playerid][i] > 0)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ktoœ ju¿ rzuci³ gazete pod tym biznesem, wróæ póŸniej !");
				return 1;
			}
			PlayerActionMessage(playerid,10.0,"rzuca gazete");
			gPapers[playerid]--;
			format(string, sizeof(string), "[INFO:] Pozosta³o gazet: %d", gPapers[playerid]);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			GivePlayerCash(playerid,NewsBoyJob[TakeJobReward]);
			gLastBVisit[playerid][i] = 300;
			DynamicFactions[FACTIONID_GOVERNMENT][fBank] -= NewsBoyJob[TakeJobReward];
			SaveFData(FACTIONID_GOVERNMENT, "Bank");
			return 1;
		}
	}
	SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ przed wejœciem do ¿adnego domu !");
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
	format(string, sizeof(string), "[INFO:] NewsBoy job reward set to %d$", reward);
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
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[U¯YCIE] /aradio [slot (0-4)] [idstation (0-8)]");
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
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie jesteœ dilerem narkotyków !");
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
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] od 1 do 50.");
		return 1;
	}
	if(needed > gPlayerData[playerid][pDrugs])
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie posiadasz przy sobie tylu narkotyków !");
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
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie mo¿esz sam sobie sprzedaæ narkotyków !");
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie jesteœ blisko tej osoby !");
		}
	}
	else
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Niew³aœciwe ID.");
	}
	return 1;
}

dcmd_animacje(playerid, params[])
{
	#pragma unused params
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "________________________________________________________________________________________________________________________________");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "/zygaj(1-2) - /tancz(1-7) - /recedogory - /schowajkomorke - /bat - /caluj - /cygaro");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "/stoj - /deal - /gsign - /zaloz - /spray - /throw - /uthrow - /zaplac - /machaj - /chat - /idz - /fuckyou");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "/joga - /siadz(1-2) - /wstan(1-3) - /padnij(1-3) - /ranny - /strip(1-17)");
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "________________________________________________________________________________________________________________________________");
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

	format(string, sizeof(string), "Benzyna: %d$", GasStations[id][PetrolPrice]);
	GasStations[id][GS3dTextLabel] = CreateDynamic3DTextLabel(string, COLOR_GREEN, GasStations[id][Pos3dTextX], GasStations[id][Pos3dTextY], GasStations[id][Pos3dTextZ], 50.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID);
	format(string, sizeof(string), "Diesel: %d$", GasStations[id][OilPrice]);
	GasStations[id][GS3dTextLabel2] = CreateDynamic3DTextLabel(string, COLOR_GREEN, GasStations[id][Pos3dTextX2], GasStations[id][Pos3dTextY2], GasStations[id][Pos3dTextZ2], 50.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID);
	format(string, sizeof(string), "Gaz: %d$", GasStations[id][GasPrice]);
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
	new Float:px, Float:py, Float:pz;

	if(sscanf(params, "dfff", id, px, py, pz))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /gspos [id] [x] [y] [z]");
		return 1;
	}
	GasStations[id][GSposX] = px;
	GasStations[id][GSposY] = py;
	GasStations[id][GSposZ] = pz;
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
	if( gPlayerData[playerid][pJob] != 1 )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ dilerem broni !" );
		return 1;
	}
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
	if( !DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryEnabled] )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie ma aktywnej fabryki !");
		return 1;
	}
	if( !IsPlayerInDynamicCP( playerid, DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryCPPartTakeID] ) )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w punkcie skladu czêœci !");
		return 1;
	}
	ShowPlayerDialog( playerid, DIALOG_WMENU_1, DIALOG_STYLE_LIST, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_MAIN_TXT, "Wybierz", "Anuluj" );
	return 1;
}

dcmd_savebuildings(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	SaveBuildings();
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Rozpoczêto zapis budynków");
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
		mysql_query(string, SAVE, playerid, db_con2);
	}
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

dcmd_fabryka(playerid, params[])
{
	#pragma unused params
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
	if( DynamicFactions[fID][WFactoryEnabled] || DynamicFactions[fID][WFactoryBurning] != 0 )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Aktualnie mo¿liwe jest postawienie tylko jednej fabryki !");
		return 1;
	}
	if( DynamicFactions[fID][fBank] < WFACTORY_COST )
	{
		new string[128];
		format( string, sizeof(string), "[INFO:] Za ma³o pieniêdzy w kasie frakcji na postawienie fabryki. Wymagana kwota: %d", WFACTORY_COST );
		SendClientMessage( playerid, COLOR_ORANGE, string );
		return 1;
	}
	DynamicFactions[fID][fBank] -= WFACTORY_COST;
	new Float:px, Float:py, Float:pz;
	GetPlayerPos(playerid, px, py, pz);
	DynamicFactions[fID][WFactoryJustBought] = 1;
	DynamicFactions[fID][WFactoryCentrePosX] = px;
	DynamicFactions[fID][WFactoryCentrePosY] = py;
	DynamicFactions[fID][WFactoryCentrePosZ] = pz;
	SaveFData( fID, "Bank" );
	SaveFData( fID, "WFactoryCentrePosX" );
	SaveFData( fID, "WFactoryCentrePosY" );
	SaveFData( fID, "WFactoryCentrePosZ" );
	SaveFData( fID, "WFactoryJustBought" );
	SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Zakupi³eœ fabryke broni. Zostanie ona postawiona nastêpnego dnia." );
	return 1;
}

dcmd_fillbuildingstable(playerid, params[])
{
	#pragma unused params
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new string[128];
	format(string, sizeof(string), "INSERT INTO `samp_buildings` VALUE `Locked` = '0'");
	mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
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
	PartsMount(playerid);
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
	new succeed = 1 + random(2);
	if( succeed )
	{
		DynamicFactions[fID][WFactoryBurning] = 0;
		DynamicFactions[fID][WFactoryEnabled] = 1;
		SendClientMessage( playerid, COLOR_GREEN, "[INFO:] Ugasi³eœ fabryke !");
		gPlayerData[playerid][pHP] -= 15;
		SavePlayerData( playerid, "HP" );
		SetPlayerHealth( playerid, gPlayerData[playerid][pHP] );
	}
	else
	{
		SendClientMessage( playerid, COLOR_GREEN, "[INFO:] Nie uda³o ci siê ugasiæ fabryki !");
		gPlayerData[playerid][pHP] -= 25;
		SavePlayerData( playerid, "HP" );
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
			DestroyFactory( i, gPlayerData[playerid][pFaction] );
			SaveFData( i, "WFactoryEnabled" );
			SaveFData( i, "WfactoryBurning" );
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
	if( gPlayerData[playerid][pBizKey] == 255 && gPlayerData[playerid][pFaction] == 255 )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz tutaj kupowaæ broni ! Udaj siê do sklepu z broni¹.");
		return 1;
	}
	if( gPlayerData[playerid][pFaction] != 255 && gPlayerData[playerid][pBizKey] == 255 )
	{
		if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fType] != F_POLICE )
		{
			SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz tutaj kupowaæ broni ! Udaj siê do sklepu z broni¹.");
			return 1;
		}
		if( gPlayerData[playerid][pRank] != 1 )
		{
			SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz tutaj kupowaæ broni ! Udaj siê do sklepu z broni¹.");
			return 1;
		}
	}
	if( gPlayerData[playerid][pFaction] == 255 && gPlayerData[playerid][pBizKey] != 255 )
	{
		if( Businesses[ gPlayerData[playerid][pBizKey] ][BizType] != BIZT_WEAPONS )
		{
			SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz tutaj kupowaæ broni ! Udaj siê do sklepu z broni¹.");
			return 1;
		}
	}
	if( gPlayerData[playerid][pFaction] != 255 && gPlayerData[playerid][pBizKey] != 255 )
	{
		if( Businesses[ gPlayerData[playerid][pBizKey] ][BizType] != BIZT_WEAPONS )
		{
			if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fType] != F_POLICE )
			{
				SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz tutaj kupowaæ broni ! Udaj siê do sklepu z broni¹.");
				return 1;
			}
		}
	}
	if( !IsPlayerInDynamicCP( playerid, WFactoryLegal[WFactoryCPDocsID] ) )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w punkcie skupu !");
		return 1;
	}
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

dcmd_setcameranorm( playerid, params[] )
{
	#pragma unused params
	if( gPlayerData[playerid][pAdmin] != 5 )
		return 0;
	SetCameraBehindPlayer( playerid );
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

dcmd_wlascicielpoj( playerid, params[] )
{
	new serial, string[128];
	if( sscanf( params, "d", serial ) )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] /wlascicielpoj [rejestracja pojazdu]" );
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Podaj¹c rejestracje wpisz jedynie jej numery bez przedrostka miasta !");
		return 1;
	}
	for( new i = 0; i < sizeof(gVehData); i++ )
	{
		if( gVehData[i][CarSerial] == serial )
		{
			if( strcmp( gVehData[i][Owner], "none", true, sizeof(gVehData) ) == 0 )
			{
				SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Pojazd nie posiada w³aœciciela. Prawdopodonie nale¿y do frakcji lub zosta³ porzucony przez w³aœciciela.");
				return 1;
			}
			format( string, sizeof(string), "[INFO:] W³aœcicielem pojazdu jest: %s", gVehData[i][Owner] );
			SendClientMessage( playerid, COLOR_GREEN, string );
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
	GetPlayerSpeed(playerid);
	SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Miernik prêdkoœci uruchomiony");
	return 1;
}

dcmd_komendypojazdow( playerid, params[] )
{
	#pragma unused params
	new string[128];
	format( string, sizeof(string), "/(e)ngine - /zamknij - /kuppojazd - /sprzedajpojazd - /anulujsprzedazpojazdu(f) - /pasy - /zatankuj - /radios - /radiosv" );
	SendClientMessage( playerid, COLOR_LIGHTYELLOW2, string );
	format( string, sizeof(string), "/zrezygnujzoc - /zrezygnujzac - /zezlomujpojazd(f) - /odczepnaczepe - /otworzbagaznik - /zamknijbagaznik - /otworzmaske" );
	SendClientMessage( playerid, COLOR_LIGHTYELLOW2, string );
	format( string, sizeof(string), "/zamknijmaske" );
	SendClientMessage( playerid, COLOR_LIGHTYELLOW2, string );
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
		ProxDetector(10.0, playerid, string, COLOR_GREEN,COLOR_LIGHTBLUE,COLOR_LIGHTBLUE,COLOR_LIGHTBLUE,COLOR_LIGHTBLUE);
	}
	else if(succeed == 2)
	{
		format(string, sizeof(string), "[AKCJA:] %s spróbowa³ %s bez rezultatu", GetPlayerNameEx(playerid), action);
		ProxDetector(10.0, playerid, string, COLOR_RED,COLOR_LIGHTBLUE,COLOR_LIGHTBLUE,COLOR_LIGHTBLUE,COLOR_LIGHTBLUE);
	}
	return 1;
}

dcmd_b(playerid, params[])
{
	new string[256], part1[75], part2[75];
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
	if( strlen(string) > 75 )
	{
		strmid( part1, string, 0, 74 );
		strmid( part2, string, 74, 149 );
		format( string, sizeof(string), "(( [%i] [%s] mówi: %s ))", playerid, gPlayerData[playerid][pOOCName], part1 );
		ProxDetector(20.0, playerid, string, COLOR_FADE1,COLOR_FADE2,COLOR_FADE3,COLOR_FADE4,COLOR_FADE5);
		format( string, sizeof(string), "(( [%i] [%s] mówi: %s ))", playerid, gPlayerData[playerid][pOOCName], part2 );
		ProxDetector(20.0, playerid, string, COLOR_FADE1,COLOR_FADE2,COLOR_FADE3,COLOR_FADE4,COLOR_FADE5);
	}
	else
	{
		format( string, sizeof(string), "(( [%i] [%s] mówi: %s ))", playerid, gPlayerData[playerid][pOOCName], string );
		ProxDetector(20.0, playerid, string, COLOR_FADE1,COLOR_FADE2,COLOR_FADE3,COLOR_FADE4,COLOR_FADE5);
	}
	return 1;
}

dcmd_ao(playerid, params[])
{
	if( gPlayerData[playerid][pAdmin] <= 0 )
		return 0;
	new string[256], part0[256], part1[80], part2[80];
	new Year, Month, Day, Hour, Minute, Second;
	if( sscanf( params, "s[256]", part0 ) )
	{
		SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] /ao [text]" );
		return 1;
	}
	getdate(Year, Month, Day);
	gettime(Hour, Minute, Second);
	if( strlen(part0) > 80 )
	{
		strmid( part1, part0, 0, 79 );
		strmid( part2, part0, 79, 159 );
		format( string, sizeof(string), "[AOOC] [%d] [%s]: %s", playerid, gPlayerData[playerid][pOOCName], part1 );
		foreach(Player, i)
		{
			if( gPlayerLogged[i] )
				SendClientMessage(i, 0x62B382AA, string);
		}
		format(string, sizeof(string), "[AOOC][%02d/%02d/%d][%02d:%02d:%02d] [%s] [%d] : %s", Day, Month, Year, Hour, Minute, Second, gPlayerData[playerid][pOOCName], playerid, part1);
		printf("%s", string);
		OOCLog(string);
		format( string, sizeof(string), "[AOOC] [%d] [%s]: %s", playerid, gPlayerData[playerid][pOOCName], part2 );
		foreach(Player, i)
		{
			if( gPlayerLogged[i] )
				SendClientMessage(i, 0x62B382AA, string);
		}
		format(string, sizeof(string), "[AOOC][%02d/%02d/%d][%02d:%02d:%02d] [%s] [%d] : %s", Day, Month, Year, Hour, Minute, Second, gPlayerData[playerid][pOOCName], playerid, part2);
		printf("%s", string);
		OOCLog(string);
	}
	else
	{
		format( string, sizeof(string), "[AOOC] [%d] [%s]: %s", playerid, gPlayerData[playerid][pOOCName], part0 );
		foreach(Player, i)
		{
			if( gPlayerLogged[i] )
				SendClientMessage(i, 0x62B382AA, string);
		}
		format(string, sizeof(string), "[AOOC][%02d/%02d/%d][%02d:%02d:%02d] [%s] [%d] : %s", Day, Month, Year, Hour, Minute, Second, gPlayerData[playerid][pOOCName], playerid, part0);
		printf("%s", string);
		OOCLog(string);
	}
	return 1;
}

dcmd_o(playerid, params[])
{
	new string[256], part0[256], part1[80], part2[80];
	new Year, Month, Day, Hour, Minute, Second;
	if( sscanf( params, "s[256]", part0 ) )
	{
		SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] /o [text]" );
		return 1;
	}
	if( noooc && gPlayerData[playerid][pAdmin] < 1 && gPlayerData[playerid][pModerator] == 0 )
	{
		SendClientMessage(playerid, COLOR_GRAD2, "[INFO:] Chat OOC zosta³ wy³¹czony przez administratora !");
		return 1;
	}
	if( gPlayerData[playerid][pMuted] && gPlayerData[playerid][pAdmin] == 0)
	{
		SendClientMessage(playerid, COLOR_LIGHTRED, "[INFO:] Nie mo¿esz u¿ywaæ tego chatu kiedy jesteœ uciszony !");
		return 1;
	}
	if( !gPlayerData[playerid][pOOCStatus] )
	{
		SendClientMessage(playerid, COLOR_RED, "[UWAGA:] Masz wy³¹czone otrzymywanie wiadomoœci OOC !");
		return 1;
	}
	getdate(Year, Month, Day);
	gettime(Hour, Minute, Second);
	if( strlen(part0) > 80 )
	{
		strmid( part1, part0, 0, 79 );
		strmid( part2, part0, 79, 159 );
		format( string, sizeof(string), "[OOC] [%d] [%s]: %s", playerid, gPlayerData[playerid][pOOCName], part1 );
		foreach(Player, i)
		{
			if( gPlayerData[i][pOOCStatus] && gPlayerLogged[i] )
				SendClientMessage(i, COLOR_OOC, string);
		}
		format(string, sizeof(string), "[OOC][%02d/%02d/%d][%02d:%02d:%02d] [%s] [%d] : %s", Day, Month, Year, Hour, Minute, Second, gPlayerData[playerid][pOOCName], playerid, part1);
		printf("%s", string);
		OOCLog(string);
		format( string, sizeof(string), "[OOC] [%d] [%s]: %s", playerid, gPlayerData[playerid][pOOCName], part2 );
		foreach(Player, i)
		{
			if( gPlayerData[i][pOOCStatus] && gPlayerLogged[i] )
				SendClientMessage(i, COLOR_OOC, string);
		}
		format(string, sizeof(string), "[OOC][%02d/%02d/%d][%02d:%02d:%02d] [%s] [%d] : %s", Day, Month, Year, Hour, Minute, Second, gPlayerData[playerid][pOOCName], playerid, part2);
		printf("%s", string);
		OOCLog(string);
	}
	else
	{
		format( string, sizeof(string), "[OOC] [%d] [%s]: %s", playerid, gPlayerData[playerid][pOOCName], part0 );
		foreach(Player, i)
		{
			if( gPlayerData[i][pOOCStatus] && gPlayerLogged[i] )
				SendClientMessage(i, COLOR_OOC, string);
		}
		format(string, sizeof(string), "[OOC][%02d/%02d/%d][%02d:%02d:%02d] [%s] [%d] : %s", Day, Month, Year, Hour, Minute, Second, gPlayerData[playerid][pOOCName], playerid, part0);
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
		AddExpPoint(playerid);
		SendClientMessage( playerid, COLOR_GREEN, "[INFO:] Pierwszy raz u¿y³eœ akcji RP !" );
	}
	PlayerActionMessage( playerid, 15.0, string );
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
		format(string, sizeof(string), "[DO][%02d/%02d/%d][%02d:%02d:%02d] [%s] [%d] : %s", Day, Month, Year, Hour, Minute, Second, gPlayerData[playerid][pOOCName], playerid, part1);
		printf("%s", string);
		PlayerActionLog(string);
		format( string, sizeof(string), "* %s (( %s ))", GetPlayerNameEx(playerid), part2 );
		ProxDetector(15.0, playerid, string, COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE);
		format(string, sizeof(string), "[DO][%02d/%02d/%d][%02d:%02d:%02d] [%s] [%d] : %s", Day, Month, Year, Hour, Minute, Second, gPlayerData[playerid][pOOCName], playerid, part2);
		printf("%s", string);
		PlayerActionLog(string);
	}
	else
	{
		format( string, sizeof(string), "* %s (( %s ))", GetPlayerNameEx(playerid), part0 );
		ProxDetector(15.0, playerid, string, COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE);
		format(string, sizeof(string), "[DO][%02d/%02d/%d][%02d:%02d:%02d] [%s] [%d] : %s", Day, Month, Year, Hour, Minute, Second, gPlayerData[playerid][pOOCName], playerid, part0);
		printf("%s", string);
		PlayerActionLog(string);
	}
	if( !gPlayerData[playerid][pFirstAction] )
	{
		gPlayerData[playerid][pFirstAction] = 1;
		SavePlayerData( playerid, "FirstAction" );
		AddExpPoint(playerid);
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
				SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] /radiod [nr kanalu]" );
				return 1;
			}
			if(channelID > 12 || channelID < 1)
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
				SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] /radiod [nr kanalu]" );
				return 1;
			}
			if(channelID > 12 || channelID < 1)
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

dcmd_setstartspawn( playerid, params[] )
{
	#pragma unused params
	if( gPlayerData[playerid][pAdmin] < 1 )
		return 0;
	new Float:x, Float:y, Float:z;
	GetPlayerPos( playerid, x, y, z );
	gStartSpawnX = x;
	gStartSpawnY = y;
	gStartSpawnZ = z;
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
	mysql_close(db_con1);
	mysql_close(db_con2);
	mysql_close(db_con3);
	mysql_close(db_con4);
	mysql_connect(db_host,db_user,db_pass,db_database, db_con1, 1);
	mysql_connect(db_host,db_user,db_pass,db_database, db_con2, 1);
	mysql_connect(db_host,db_user,db_pass,db_database, db_con3, 1);
	mysql_connect(db_host,db_user,db_pass,db_database, db_con4, 1);
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
	if( gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new vehicleid = GetPlayerVehicleID(playerid);
	new pj;
	if( sscanf( params, "d", pj ) )
	{
		SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] /ahevpj [paint job]" );
		return 1;
	}
	ChangeVehiclePaintjob(vehicleid, pj );
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
		SetVehiclePos( vehid, Houses[i][EnterX], Houses[i][EnterY], Houses[i][EnterZ] );
		SetVehicleZAngle( vehid, Houses[i][EnterAngle] );
		// PutPlayerIntoVehicle( playerid, vehid, 0 );
		SetPlayerInterior( playerid, 0 );
		SetPlayerVirtualWorld( playerid, 0 );

		gVehData[vehid-1][CarX] = Houses[i][EnterX];
		gVehData[vehid-1][CarY] = Houses[i][EnterY];
		gVehData[vehid-1][CarZ] = Houses[i][EnterZ];
		gVehData[vehid-1][CarAngle] = Houses[i][EnterAngle];
		gVehData[vehid-1][CarInterior] = Houses[i][EnterInterior];
		gVehData[vehid-1][CarVW] = 0;
		SaveVehData( vehid-1, "CarPos" );
		SaveVehData( vehid-1, "CarInterior" );
		SaveVehData( vehid-1, "CarVW" );

		gPlayerData[playerid][pCrashX] = Houses[i][EnterX];
		gPlayerData[playerid][pCrashY] = Houses[i][EnterY];
		gPlayerData[playerid][pCrashZ] = Houses[i][EnterZ];
		gPlayerData[playerid][pCrashAngle] = Houses[i][EnterAngle];
		gPlayerData[playerid][pCrashInt] = Houses[i][EnterInterior];
		gPlayerData[playerid][pCrashW] = i;
		SavePlayerData( playerid, "Crash" );

		if( Houses[i][HRadio1Bought] && Houses[i][HRadio1On] )
			Audio_Stop( playerid, Houses[i][HRadio1ID][playerid] );
		return 1;
	}
	SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ przy wyjeŸdzie z gara¿u !");
	return 1;
}

dcmd_wjedzdogarazu(playerid, params[])
{
	#pragma unused params
	for( new i = 0; i < sizeof(Houses); i++ )
	{
		if( !PlayerToPoint( 5.0, playerid, Houses[i][EnterX], Houses[i][EnterY], Houses[i][EnterZ] ) )
			continue;
		if( GetPlayerVirtualWorld(playerid) != Houses[i][EnterWorld] )
			continue;
		if( Houses[i][HouseType] != 1 && Houses[i][HouseType] != 2 )
		{
			SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] To nie jest gara¿ !");
			return 1;
		}
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
		PlayerActionMessage(playerid, 15.0, "otwiera gara¿ pilotem i do niego wje¿d¿a");
		LinkVehicleToInterior( vehid, Houses[i][ExitInterior] );
		SetVehicleVirtualWorld( vehid, i );
		SetVehiclePos( vehid, Houses[i][ExitX], Houses[i][ExitY], Houses[i][ExitZ] );
		SetVehicleZAngle( vehid, Houses[i][ExitAngle] );
		// PutPlayerIntoVehicle( playerid, vehid, 0 );
		SetPlayerInterior( playerid,Houses[i][ExitInterior] );
		SetPlayerVirtualWorld( playerid, i );

		gVehData[vehid-1][CarX] = Houses[i][ExitX];
		gVehData[vehid-1][CarY] = Houses[i][ExitY];
		gVehData[vehid-1][CarZ] = Houses[i][ExitZ];
		gVehData[vehid-1][CarAngle] = Houses[i][ExitAngle];
		gVehData[vehid-1][CarInterior] = Houses[i][ExitInterior];
		gVehData[vehid-1][CarVW] = i;
		SaveVehData( vehid-1, "CarPos" );
		SaveVehData( vehid-1, "CarInterior" );
		SaveVehData( vehid-1, "CarVW" );

		gPlayerData[playerid][pCrashX] = Houses[i][ExitX];
		gPlayerData[playerid][pCrashY] = Houses[i][ExitY];
		gPlayerData[playerid][pCrashZ] = Houses[i][ExitZ];
		gPlayerData[playerid][pCrashAngle] = Houses[i][ExitAngle];
		gPlayerData[playerid][pCrashInt] = Houses[i][ExitInterior];
		gPlayerData[playerid][pCrashW] = i;
		SavePlayerData( playerid, "Crash" );

		if( Houses[i][HRadio1On] && Houses[i][HRadio1Bought] )
			PlayerPHouseRadio( playerid, i );
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
	WFactoryLegal[WFactoryCPDocsID] = CreateDynamicCP( x, y, z, 1.0 );

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
	SavePlayerData( playerid, "Crash" );

	TogglePlayerControllable(playerid, 0);
	unfreezeTPPlayer(playerid);

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
	unfreezeTPPlayer(playerid);

	gPlayerData[playerid][pCrashInt] = 0;
	gPlayerData[playerid][pCrashW] = 21;
	SavePlayerData(playerid, "CrashInt");
	SavePlayerData(playerid, "CrashW");
	return 1;
}

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
}

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
	if(giveplayerid == playerid) { SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie mo¿esz sam siebie uwolniæ."); return 1; }
	if(gPlayerData[giveplayerid][pJailed] == 0)
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Gracz nie jest uwiêziony.");
		return 1;
	}
	if(GetDistanceBetweenPlayers(playerid,giveplayerid) > 5)
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie jesteœ blisko tej osoby.");
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
	format( string2, sizeof(string), "Za swoj¹ pomoc ¿¹da %d$\nJeœli uda mu siê ciebie wydostaæ z wiêzienia przeka¿esz mu 100%% kwoty.\n", cost+freeward);
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
		format(string, sizeof(string), "INSERT INTO `samp_objects` (`cstObjModel`) VALUES ('0')");
		mysql_query(string, SAVE, CUSTOM_MAX_PLAYERS, db_con2);
	}
	return 1;
}

dcmd_wnetrzebiz(playerid, params[])
{
	new bizID, intID, string[128];
	if( gPlayerData[playerid][pFaction] != 9 )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ urzêdnikiem !");
		return 1;
	}
	if( sscanf(params, "dd", bizID, intID) )
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /wnetrzebiz [id biznesu] [id wnetrza 1-40]");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Raz ustawionego wnêtrza nie mo¿na zmieniæ !");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INTS:] [1:] Marcos Bistro (Eat) - [2:] Big Spread Ranch (Bar) - [3:] Burger Shot (Eat) - [4:] Cluckin Bell (EAT)");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INTS:] [5:] Well Stacked Pizza (Eat) - [6:] Rusty Browns Dohnuts (Eat) - [7:] Jays Diner (Eat) - [8:] Pump Truck Stop Diner (Eat)");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INTS:] [9:] Alhambra (Drink) - [10:] Mistys (Drink) - [11:] Lil' Probe Inn (Drink) - [12:] Exclusive (Clothes) - [13:] Binco (Clothes)");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INTS:] [14:] ProLaps (Clothes) - [15:] SubUrban (Clothes) - 16: Victim (Clothes) - [17:] Zip (Clothes) - [18:] Redsands Casino");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INTS:] [27:] Jizzys (Drink) - [27-33:] 24-7's (Buy) - [35:] Kibelek - [36:] Wiejskie Disco - [37:] Disco - [38:] Shop Elex ");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INTS:] [39:] Restauracja - [40:] Restauracja ");
		return 1;
	}
	if(intID < 1 || intID > 41)
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] /wnetrzebiz [id biznesu] [id wnetrza 1-40]");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INTS:] [1:] Marcos Bistro (Eat) - [2:] Big Spread Ranch (Bar) - [3:] Burger Shot (Eat) - [4:] Cluckin Bell (EAT)");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INTS:] [5:] Well Stacked Pizza (Eat) - [6:] Rusty Browns Dohnuts (Eat) - [7:] Jays Diner (Eat) - [8:] Pump Truck Stop Diner (Eat)");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INTS:] [9:] Alhambra (Drink) - [10:] Mistys (Drink) - [11:] Lil' Probe Inn (Drink) - [12:] Exclusive (Clothes) - [13:] Binco (Clothes)");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INTS:] [14:] ProLaps (Clothes) - [15:] SubUrban (Clothes) - 16: Victim (Clothes) - [17:] Zip (Clothes) - [18:] Redsands Casino");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INTS:] [27:] Jizzys (Drink) - [27-33:] 24-7's (Buy) - [35:] Kibelek - [36:] Wiejskie Disco - [37:] Disco - [38:] Shop Elex ");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INTS:] [39:] Restauracja - [40:] Restauracja ");
		return 1;
	}
	if(Businesses[bizID][BIntSet])
	{
		SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Interior tego biznesu zosta³ ju¿ ustawiony i nie mo¿na go zmieniæ");
		return 1;
	}
	Businesses[bizID][BIntSet] = 1;
	SaveBizData(bizID, "IntSet");
	Businesses[bizID][BInterior] = intID;
	SaveBizData(bizID, "Interior");
	if(intID == 1)
	{
		Businesses[bizID][ExitX] = -794.806396;
		Businesses[bizID][ExitY] = 489.284973;
		Businesses[bizID][ExitZ] = 1376.195;
		Businesses[bizID][ExitInterior] = 1;
		Businesses[bizID][ExitAngle] = 0.458332;
		format(string, sizeof string, "Business ID: %d - Description: Marcos Bistro.", bizID);
		SendClientMessage(playerid, COLOR_ADMINCMD,string);
	}
	else if(intID == 2)
	{
		Businesses[bizID][ExitX] = 1212.265625;
		Businesses[bizID][ExitY] = -25.877540;
		Businesses[bizID][ExitZ] = 1001.089966;
		Businesses[bizID][ExitInterior] = 3;
		Businesses[bizID][ExitAngle] = 181.8332;
		format(string, sizeof string, "Business ID: %d - Description: Big Spread Ranch Strip Club.", bizID);
		SendClientMessage(playerid, COLOR_ADMINCMD,string);
	}
	else if(intID == 3)
	{
		Businesses[bizID][ExitX] = 362.909484;
		Businesses[bizID][ExitY] = -75.193481;
		Businesses[bizID][ExitZ] = 1001.507812;
		Businesses[bizID][ExitInterior] = 10;
		Businesses[bizID][ExitAngle] = 311.5311;
		format(string, sizeof string, "Business ID: %d - Description: Burger Shot.", bizID);
		SendClientMessage(playerid, COLOR_ADMINCMD,string);
	}
	else if(intID == 4)
	{
		Businesses[bizID][ExitX] = 365.672974;
		Businesses[bizID][ExitY] = -10.713200;
		Businesses[bizID][ExitZ] = 1001.869995;
		Businesses[bizID][ExitInterior] = 9;
		Businesses[bizID][ExitAngle] = 0.458332;
		format(string, sizeof string, "Business ID: %d - Description: Cluckin Bell.", bizID);
		SendClientMessage(playerid, COLOR_ADMINCMD,string);
	}
	else if(intID == 5)
	{
		Businesses[bizID][ExitX] = 372.579650;
		Businesses[bizID][ExitY] = -133.515899;
		Businesses[bizID][ExitZ] = 1001.449951;
		Businesses[bizID][ExitInterior] = 5;
		Businesses[bizID][ExitAngle] = 3.834877;
		format(string, sizeof string, "Business ID: %d - Description: Well Stacked Pizza.", bizID);
		SendClientMessage(playerid, COLOR_ADMINCMD,string);
	}
	else if(intID == 6)
	{
		Businesses[bizID][ExitX] = 377.098999;
		Businesses[bizID][ExitY] = -192.439987;
		Businesses[bizID][ExitZ] = 1000.643982;
		Businesses[bizID][ExitInterior] = 17;
		Businesses[bizID][ExitAngle] = 0.458332;
		format(string, sizeof string, "Business ID: %d - Description: Rusty Brown Dohnuts.", bizID);
		SendClientMessage(playerid, COLOR_ADMINCMD,string);
	}
	else if(intID == 7)
	{
		Businesses[bizID][ExitX] = 460.099976;
		Businesses[bizID][ExitY] = -88.428497;
		Businesses[bizID][ExitZ] = 999.621948;
		Businesses[bizID][ExitInterior] = 4;
		Businesses[bizID][ExitAngle] = 0.458332;
		format(string, sizeof string, "Business ID: %d - Description: Jays Diner.", bizID);
		SendClientMessage(playerid, COLOR_ADMINCMD,string);
	}
	else if(intID == 8)
	{
		Businesses[bizID][ExitX] = 681.474976;
		Businesses[bizID][ExitY] = -451.150970;
		Businesses[bizID][ExitZ] = -25.616798;
		Businesses[bizID][ExitInterior] = 1;
		Businesses[bizID][ExitAngle] = 0.458332;
		format(string, sizeof string, "Business ID: %d - Description: Pump Truck Stop Diner DZIURA W PODLODZE.", bizID);
		SendClientMessage(playerid, COLOR_ADMINCMD,string);
	}
	else if(intID == 9)
	{
		Businesses[bizID][ExitX] = 493.484588;
		Businesses[bizID][ExitY] = -24.906007;
		Businesses[bizID][ExitZ] = 1000.671875;
		Businesses[bizID][ExitInterior] = 17;
		Businesses[bizID][ExitAngle] = 356.2913;
		format(string, sizeof string, "Business ID: %d - Description: Alhambra.", bizID);
		SendClientMessage(playerid, COLOR_ADMINCMD,string);
	}
	else if(intID == 10)
	{
		Businesses[bizID][ExitX] = 502.039733;
		Businesses[bizID][ExitY] = -67.637390;
		Businesses[bizID][ExitZ] = 998.834961;
		Businesses[bizID][ExitInterior] = 11;
		Businesses[bizID][ExitAngle] = 191.93478;
		format(string, sizeof string, "Business ID: %d - Description: Mistys.", bizID);
		SendClientMessage(playerid, COLOR_ADMINCMD,string);
	}
	else if(intID == 11)
	{
		Businesses[bizID][ExitX] = -229.289276;
		Businesses[bizID][ExitY] = 1401.314331;
		Businesses[bizID][ExitZ] = 27.769798;
		Businesses[bizID][ExitInterior] = 18;
		Businesses[bizID][ExitAngle] = 270.3904;
		format(string, sizeof string, "Business ID: %d - Description: Lil' Probe Inn.", bizID);
		SendClientMessage(playerid, COLOR_ADMINCMD,string);
	}
	else if(intID == 12)
	{
		Businesses[bizID][ExitX] = 204.608230;
		Businesses[bizID][ExitY] = -168.851776;
		Businesses[bizID][ExitZ] = 1000.578979;
		Businesses[bizID][ExitInterior] = 14;
		Businesses[bizID][ExitAngle] = 6.87463;
		format(string, sizeof string, "Business ID: %d - Description: EXcLusive.", bizID);
		SendClientMessage(playerid, COLOR_ADMINCMD,string);
	}
	else if(intID == 13)
	{
		Businesses[bizID][ExitX] = 207.801361;
		Businesses[bizID][ExitY] = -111.258720;
		Businesses[bizID][ExitZ] = 1005.269958;
		Businesses[bizID][ExitInterior] = 15;
		Businesses[bizID][ExitAngle] = 358.414;
		format(string, sizeof string, "Business ID: %d - Description: Binco.", bizID);
		SendClientMessage(playerid, COLOR_ADMINCMD,string);
	}
	else if(intID == 14)
	{
		Businesses[bizID][ExitX] = 207.054993;
		Businesses[bizID][ExitY] = -138.804993;
		Businesses[bizID][ExitZ] = 1003.519958;
		Businesses[bizID][ExitInterior] = 3;
		Businesses[bizID][ExitAngle] = 0.458332;
		format(string, sizeof string, "Business ID: %d - Description: ProLaps.", bizID);
		SendClientMessage(playerid, COLOR_ADMINCMD,string);
	}
	else if(intID == 15)
	{
		Businesses[bizID][ExitX] = 203.568298;
		Businesses[bizID][ExitY] = -50.662452;
		Businesses[bizID][ExitZ] = 1001.799988;
		Businesses[bizID][ExitInterior] = 1;
		Businesses[bizID][ExitAngle] = 356.82446;
		format(string, sizeof string, "Business ID: %d - Description: SubUrban.", bizID);
		SendClientMessage(playerid, COLOR_ADMINCMD,string);
	}
	else if(intID == 16)
	{
		Businesses[bizID][ExitX] = 227.542633;
		Businesses[bizID][ExitY] = -8.100092;
		Businesses[bizID][ExitZ] = 1002.259949;
		Businesses[bizID][ExitInterior] = 5;
		Businesses[bizID][ExitAngle] = 88.921981;
		format(string, sizeof string, "Business ID: %d - Description: Victim.", bizID);
		SendClientMessage(playerid, COLOR_ADMINCMD,string);
	}
	else if(intID == 17)
	{
		Businesses[bizID][ExitX] = 161.205780;
		Businesses[bizID][ExitY] = -97.102127;
		Businesses[bizID][ExitZ] = 1001.804687;
		Businesses[bizID][ExitInterior] = 18;
		Businesses[bizID][ExitAngle] = 356.4877;
		format(string, sizeof string, "Business ID: %d - Description: Zip.", bizID);
		SendClientMessage(playerid, COLOR_ADMINCMD,string);
	}
	else if(intID == 18)
	{
		Businesses[bizID][ExitX] = 1133.523559;
		Businesses[bizID][ExitY] = -15.807713;
		Businesses[bizID][ExitZ] = 1000.750000;
		Businesses[bizID][ExitInterior] = 12;
		Businesses[bizID][ExitAngle] = 0.22441;
		format(string, sizeof string, "Business ID: %d - Description: Small Casino in Redsands West.", bizID);
		SendClientMessage(playerid, COLOR_ADMINCMD,string);
	}
	else if(intID == 19)
	{
		Businesses[bizID][ExitX] = 834.660888;
		Businesses[bizID][ExitY] = 7.240708;
		Businesses[bizID][ExitZ] = 1004.179993;
		Businesses[bizID][ExitInterior] = 3;
		Businesses[bizID][ExitAngle] = 92.031906;
		format(string, sizeof string, "Business ID: %d - Description: Off Track Betting.", bizID);
		SendClientMessage(playerid, COLOR_ADMINCMD,string);
	}
	else if(intID == 20)
	{
		Businesses[bizID][ExitX] = -100.083061;
		Businesses[bizID][ExitY] = -25.029542;
		Businesses[bizID][ExitZ] = 1000.741943;
		Businesses[bizID][ExitInterior] = 3;
		Businesses[bizID][ExitAngle] = 0.224439;
		format(string, sizeof string, "Business ID: %d - Description: Sex Shop.", bizID);
		SendClientMessage(playerid, COLOR_ADMINCMD,string);
	}
	else if(intID == 21)
	{
		Businesses[bizID][ExitX] = -2240.955322;
		Businesses[bizID][ExitY] = 128.451400;
		Businesses[bizID][ExitZ] = 1035.419922;
		Businesses[bizID][ExitInterior] = 6;
		Businesses[bizID][ExitAngle] = 268.416;
		format(string, sizeof string, "Business ID: %d - Description: Zero's RC Shop.", bizID);
		SendClientMessage(playerid, COLOR_ADMINCMD,string);
	}
	else if(intID == 22)
	{
		Businesses[bizID][ExitX] = 285.404602;
		Businesses[bizID][ExitY] = -41.745178;
		Businesses[bizID][ExitZ] = 1001.569946;
		Businesses[bizID][ExitInterior] = 1;
		Businesses[bizID][ExitAngle] =357.69436;
		format(string, sizeof string, "Business ID: %d - Description: Ammunation 1.", bizID);
		SendClientMessage(playerid, COLOR_ADMINCMD,string);
	}
	else if(intID == 23)
	{
		Businesses[bizID][ExitX] = 285.780487;
		Businesses[bizID][ExitY] = -86.71318;
		Businesses[bizID][ExitZ] = 1001.539978;
		Businesses[bizID][ExitInterior] = 4;
		Businesses[bizID][ExitAngle] = 351.74093;
		format(string, sizeof string, "Business ID: %d - Description: Ammunation 2.", bizID);
		SendClientMessage(playerid, COLOR_ADMINCMD,string);
	}
	else if(intID == 24)
	{
		Businesses[bizID][ExitX] = 296.711975;
		Businesses[bizID][ExitY] = -112.048240;
		Businesses[bizID][ExitZ] = 1001.569946;
		Businesses[bizID][ExitInterior] = 6;
		Businesses[bizID][ExitAngle] = 358.6343;
		format(string, sizeof string, "Business ID: %d - Description: Ammunation 3.", bizID);
		SendClientMessage(playerid, COLOR_ADMINCMD,string);
	}
	else if(intID == 25)
	{
		Businesses[bizID][ExitX] = 316.569549;
		Businesses[bizID][ExitY] = -170.279464;
		Businesses[bizID][ExitZ] = 999.661987;
		Businesses[bizID][ExitInterior] = 6;
		Businesses[bizID][ExitAngle] = 2.081076;
		format(string, sizeof string, "Business ID: %d - Description: Ammunation 4.", bizID);
		SendClientMessage(playerid, COLOR_ADMINCMD,string);
	}
	else if(intID == 26)
	{
		Businesses[bizID][ExitX] = 304.572479;
		Businesses[bizID][ExitY] = -142.094192;
		Businesses[bizID][ExitZ] = 1004.062500;
		Businesses[bizID][ExitInterior] = 7;
		Businesses[bizID][ExitAngle] = 94.17852;
		format(string, sizeof string, "Business ID: %d - Description: Ammunation Shooting Range.", bizID);
		SendClientMessage(playerid, COLOR_ADMINCMD,string);
	}
	else if(intID == 27)
	{
		Businesses[bizID][ExitX] = -2636.974121;
		Businesses[bizID][ExitY] = 1402.319213;
		Businesses[bizID][ExitZ] = 906.457947;
		Businesses[bizID][ExitInterior] = 3;
		Businesses[bizID][ExitAngle] = 8.61428;
		format(string, sizeof string, "Business ID: %d - Description: Jizzys.", bizID);
		SendClientMessage(playerid, COLOR_ADMINCMD,string);
	}
	else if(intID == 28)
	{
		Businesses[bizID][ExitX] = -25.819719;
		Businesses[bizID][ExitY] = -188.238037;
		Businesses[bizID][ExitZ] = 1003.549988;
		Businesses[bizID][ExitInterior] = 17;
		Businesses[bizID][ExitAngle] = 1.72090;
		format(string, sizeof string, "Business ID: %d - Description: 24-7 1.", bizID);
		SendClientMessage(playerid, COLOR_ADMINCMD,string);
	}
	else if(intID == 29)
	{
		Businesses[bizID][ExitX] = 5.933865;
		Businesses[bizID][ExitY] = -31.750873;
		Businesses[bizID][ExitZ] = 1003.549988;
		Businesses[bizID][ExitInterior] = 10;
		Businesses[bizID][ExitAngle] = 359.527526;
		format(string, sizeof string, "Business ID: %d - Description: 24-7 2.", bizID);
		SendClientMessage(playerid, COLOR_ADMINCMD,string);
	}
	else if(intID == 30)
	{
		Businesses[bizID][ExitX] = -30.683946;
		Businesses[bizID][ExitY] = -92.002952;
		Businesses[bizID][ExitZ] = 1003.549988;
		Businesses[bizID][ExitInterior] = 18;
		Businesses[bizID][ExitAngle] = 2.660877;
		format(string, sizeof string, "Business ID: %d - Description: 24-7 3.", bizID);
		SendClientMessage(playerid, COLOR_ADMINCMD,string);
	}
	else if(intID == 31)
	{
		Businesses[bizID][ExitX] = -25.878168;
		Businesses[bizID][ExitY] = -141.549636;
		Businesses[bizID][ExitZ] = 1003.549988;
		Businesses[bizID][ExitInterior] = 16;
		Businesses[bizID][ExitAngle] = 352.320;
		format(string, sizeof string, "Business ID: %d - Description: 24-7 4.", bizID);
		SendClientMessage(playerid, COLOR_ADMINCMD,string);
	}
	else if(intID == 32)
	{
		Businesses[bizID][ExitX] = -27.321363;
		Businesses[bizID][ExitY] = -31.754938;
		Businesses[bizID][ExitZ] = 1003.549988;
		Businesses[bizID][ExitInterior] = 4;
		Businesses[bizID][ExitAngle] = 356.70745;
		format(string, sizeof string, "Business ID: %d - Description: 24-7 5.", bizID);
		SendClientMessage(playerid, COLOR_ADMINCMD,string);
	}
	else if(intID == 33)
	{
		Businesses[bizID][ExitX] = -27.389696;
		Businesses[bizID][ExitY] = -58.260951;
		Businesses[bizID][ExitZ] = 1003.549988;
		Businesses[bizID][ExitInterior] = 6;
		Businesses[bizID][ExitAngle] = 358.27413;
		Businesses[bizID][BizPrice] = 4000000;
		format(string, sizeof string, "Business ID: %d - Description: 24-7 6.", bizID);
		SendClientMessage(playerid, COLOR_ADMINCMD,string);
	}
	else if(intID == 35)
	{
		Businesses[bizID][ExitX] = -2213.684814;
		Businesses[bizID][ExitY] = 1143.244140;
		Businesses[bizID][ExitZ] = 173.895568;
		Businesses[bizID][ExitInterior] = 0;
		Businesses[bizID][ExitAngle] = 0.0;
		format(string, sizeof string, "Business ID: %d - Description: Kibelek", bizID);
		SendClientMessage(playerid, COLOR_ADMINCMD,string);
	}
	else if(intID == 36)
	{
		Businesses[bizID][ExitX] = -461.70;
		Businesses[bizID][ExitY] = -2016.68;
		Businesses[bizID][ExitZ] = 24.97;
		Businesses[bizID][ExitInterior] = 1;
		Businesses[bizID][ExitAngle] = 0.0;
		format(string, sizeof string, "Business ID: %d - Description: Wiejskie Disco", bizID);
		SendClientMessage(playerid, COLOR_ADMINCMD,string);
	}
	else if(intID == 37)
	{
		Businesses[bizID][ExitX] = 1285.54;
		Businesses[bizID][ExitY] = -1652.21;
		Businesses[bizID][ExitZ] = 13.74;
		Businesses[bizID][ExitInterior] = 0;
		Businesses[bizID][ExitAngle] = 0.458332;
		format(string, sizeof string, "Business ID: %d - Description: Disco", bizID);
		SendClientMessage(playerid, COLOR_ADMINCMD,string);
	}
	else if(intID == 38)
	{
		Businesses[bizID][ExitX] = 1003.77;
		Businesses[bizID][ExitY] = 52.20;
		Businesses[bizID][ExitZ] = 55.42;
		Businesses[bizID][ExitInterior] = 3;
		Businesses[bizID][ExitAngle] = 0.458332;
		format(string, sizeof string, "Business ID: %d - Description: Sklep Elektrolux", bizID);
		SendClientMessage(playerid, COLOR_ADMINCMD,string);
	}
	else if(intID == 39)
	{
		Businesses[bizID][ExitX] = 1513.09;
		Businesses[bizID][ExitY] = -1576.66;
		Businesses[bizID][ExitZ] = 24.55;
		Businesses[bizID][ExitInterior] = 0;
		Businesses[bizID][ExitAngle] = 0.458332;
		format(string, sizeof string, "Business ID: %d - Description: Restauracja", bizID);
		SendClientMessage(playerid, COLOR_ADMINCMD,string);
	}
	else if(intID == 40)
	{
		Businesses[bizID][ExitX] = 370.46;
		Businesses[bizID][ExitY] = -1720.76;
		Businesses[bizID][ExitZ] = 17.1;
		Businesses[bizID][ExitInterior] = 0;
		Businesses[bizID][ExitAngle] = 0.458332;
		format(string, sizeof string, "Business ID: %d - Description: Restauracja", bizID);
		SendClientMessage(playerid, COLOR_ADMINCMD,string);
	}
	else if(intID == 41)
	{
		Businesses[bizID][ExitX] = Businesses[bizID][EnterX];
		Businesses[bizID][ExitY] = Businesses[bizID][EnterY];
		Businesses[bizID][ExitZ] = Businesses[bizID][EnterZ];
		Businesses[bizID][ExitInterior] = 0;
		Businesses[bizID][ExitAngle] = 0.0;
		format(string, sizeof string, "Business ID: %d - Description: Kibelek", bizID);
		SendClientMessage(playerid, COLOR_ADMINCMD,string);
	}
	SaveBizData(bizID, "ExitX");
	SaveBizData(bizID, "ExitY");
	SaveBizData(bizID, "ExitZ");
	SaveBizData(bizID, "ExitInterior");
	SaveBizData(bizID, "ExitAngle");

	format(string, sizeof(string), "[GOVERNMENT:] Business interior change by: %s, biz id: %d, interior id: %d", gPlayerData[playerid][pName], bizID, intID);
	GovermentLog(string);
	return 1;
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

dcmd_trasyon(playerid, params[])
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
	new trackID, CPID, cpReward, cpType, cpTime, Float:cpX, Float: cpY, Float:cpZ;
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
		else
		{
			SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Aby postawiæ punkt startowy musisz znajdowaæ siê na obszarze jednego z miast/wsi !");
			return 1;
		}
	}
	gBusTrackCPX[ trackID ][ CPID] = cpX;
	gBusTrackCPY[ trackID ][ CPID] = cpY;
	gBusTrackCPZ[ trackID ][ CPID] = cpZ;
	gBusTrackCPReward[ trackID ][ CPID] = cpReward;
	gBusTrackCPType[ trackID ][ CPID] = cpType;
	gBusTrackCPTime[ trackID ][ CPID] = cpTime;
	SaveBusTrack( trackID, "gBusTrackCP", CPID );
	SaveBusTrack( trackID, "gBusTrackStartArea" );
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
		if( gVehData[i][CarType] == type )
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
	for( new i = 0; i < 49; i++ )
	{
		format( string, sizeof(string), "INSERT INTO `samp_bus_tracks` (`Enabled`) VALUES ('0')" );
		mysql_query( string, SAVE, INVALID_PLAYER_ID, db_con2 );
	}
	for( new i = 0; i < 50; i++ )
	{
		for( new k = 0; k < 50; k++ )
		{
			format( string, sizeof(string), "INSERT INTO `samp_bus_tracks_data` (`TrackID`, `CPID`) VALUES ('%d', '%d')", i, k );
			mysql_query( string, SAVE, INVALID_PLAYER_ID, db_con2 );
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
		mysql_query( string, SAVE, INVALID_PLAYER_ID, db_con2 );
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
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie 
	new option[8]
	if(sscanf(params, "s[8]", option))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /produkty [kup/sprzedaj]");
		return 1;
	}
	if(strcmp( option, "kup", false, 3) == 0)
	{
		for(new i = 0; i < sizeof(gItemFactories); i++)
		{
			
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
		SaveVehData( i, "BatteryCapacity" );
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
		mysql_query( string, SAVE, INVALID_PLAYER_ID, db_con2);
		foreach(Player, i)
		{
			if( gPlayerData[i][pFaction] == gPlayerData[playerid][pFaction] && playerid != i )
			{
				gPlayerData[i][pFaction] = 255;
				SavePlayerData( i, "Faction" );
			}
		}

		for( new i = 0; i < sizeof(gVehData); i++ )
		{
			if( gVehData[i][FactionCar] == i )
				ResetVehicleData(i+1, 1);
		}

		DynamicFactions[ gPlayerData[playerid][pFaction] ][IsEnabled] = 0;
		strdel( DynamicFactions[ gPlayerData[playerid][pFaction] ][Name], 0, 49 );
		strins( DynamicFactions[ gPlayerData[playerid][pFaction] ][Name], "Brak", 0 );
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fX] = 0.0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fY] = 0.0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fZ] = 0.0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fMaterials] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fDrugs] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] = 0;
		strdel( DynamicFactions[ gPlayerData[playerid][pFaction] ][fRank1], 0, 34 );
		strins( DynamicFactions[ gPlayerData[playerid][pFaction] ][fRank1], "Ranga1", 0 );
		strdel( DynamicFactions[ gPlayerData[playerid][pFaction] ][fRank2], 0, 34 );
		strins( DynamicFactions[ gPlayerData[playerid][pFaction] ][fRank2], "Ranga2", 0 );
		strdel( DynamicFactions[ gPlayerData[playerid][pFaction] ][fRank3], 0, 34 );
		strins( DynamicFactions[ gPlayerData[playerid][pFaction] ][fRank3], "Ranga3", 0 );
		strdel( DynamicFactions[ gPlayerData[playerid][pFaction] ][fRank4], 0, 34 );
		strins( DynamicFactions[ gPlayerData[playerid][pFaction] ][fRank4], "Ranga4", 0 );
		strdel( DynamicFactions[ gPlayerData[playerid][pFaction] ][fRank5], 0, 34 );
		strins( DynamicFactions[ gPlayerData[playerid][pFaction] ][fRank5], "Ranga5", 0 );
		strdel( DynamicFactions[ gPlayerData[playerid][pFaction] ][fRank6], 0, 34 );
		strins( DynamicFactions[ gPlayerData[playerid][pFaction] ][fRank6], "Ranga6", 0 );
		strdel( DynamicFactions[ gPlayerData[playerid][pFaction] ][fRank7], 0, 34 );
		strins( DynamicFactions[ gPlayerData[playerid][pFaction] ][fRank7], "Ranga7", 0 );
		strdel( DynamicFactions[ gPlayerData[playerid][pFaction] ][fRank8], 0, 34 );
		strins( DynamicFactions[ gPlayerData[playerid][pFaction] ][fRank8], "Ranga8", 0 );
		strdel( DynamicFactions[ gPlayerData[playerid][pFaction] ][fRank9], 0, 34 );
		strins( DynamicFactions[ gPlayerData[playerid][pFaction] ][fRank9], "Ranga9", 0 );
		strdel( DynamicFactions[ gPlayerData[playerid][pFaction] ][fRank10], 0, 34 );
		strins( DynamicFactions[ gPlayerData[playerid][pFaction] ][fRank10], "Ranga10", 0 );
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fSkin1] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fSkin2] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fSkin3] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fSkin4] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fSkin5] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fSkin6] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fSkin7] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fSkin8] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fSkin9] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fSkin10] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fJoinRank] = 2;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fUseSkins] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fType] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fRankAmount] = 2;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fColor] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fMaxCars] = 2;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fCarsCount] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fXDuty] = 0.0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fYDuty] = 0.0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fZDuty] = 0.0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fWorldDuty] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fInteriorDuty] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fXDuty2] = 0.0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fYDuty2] = 0.0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fZDuty2] = 0.0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fWorldDuty2] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fInteriorDuty2] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fTaxiKMCost] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fTaxiEnterCost] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fGun1Rank1] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fGun1Rank2] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fGun1Rank3] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fGun1Rank4] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fGun1Rank5] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fGun1Rank6] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fGun1Rank7] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fGun1Rank8] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fGun1Rank9] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fGun1Rank10] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fGun2Rank1] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fGun2Rank2] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fGun2Rank3] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fGun2Rank4] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fGun2Rank5] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fGun2Rank6] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fGun2Rank7] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fGun2Rank8] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fGun2Rank9] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fGun2Rank10] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fGun3Rank1] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fGun3Rank2] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fGun3Rank3] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fGun3Rank4] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fGun3Rank5] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fGun3Rank6] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fGun3Rank7] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fGun3Rank8] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fGun3Rank9] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fGun3Rank10] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fAmmo1Rank1] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fAmmo1Rank2] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fAmmo1Rank3] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fAmmo1Rank4] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fAmmo1Rank5] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fAmmo1Rank6] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fAmmo1Rank7] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fAmmo1Rank8] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fAmmo1Rank9] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fAmmo1Rank10] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fAmmo2Rank1] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fAmmo2Rank2] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fAmmo2Rank3] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fAmmo2Rank4] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fAmmo2Rank5] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fAmmo2Rank6] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fAmmo2Rank7] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fAmmo2Rank8] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fAmmo2Rank9] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fAmmo2Rank10] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fAmmo3Rank1] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fAmmo3Rank2] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fAmmo3Rank3] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fAmmo3Rank4] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fAmmo3Rank5] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fAmmo3Rank6] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fAmmo3Rank7] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fAmmo3Rank8] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fAmmo3Rank9] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][fAmmo3Rank10] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryEnabled] = 0;
		DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryBurning] = 1;
		DestroyFactory( gPlayerData[playerid][pFaction], gPlayerData[playerid][pFaction] );
		SaveFData( gPlayerData[playerid][pFaction], "Name" );
		SaveFData( gPlayerData[playerid][pFaction], "IsEnabled" );
		SaveFData( gPlayerData[playerid][pFaction], "X" );
		SaveFData( gPlayerData[playerid][pFaction], "Y" );
		SaveFData( gPlayerData[playerid][pFaction], "Z" );
		SaveFData( gPlayerData[playerid][pFaction], "Materials" );
		SaveFData( gPlayerData[playerid][pFaction], "Drugs" );
		SaveFData( gPlayerData[playerid][pFaction], "Bank" );
		SaveFData( gPlayerData[playerid][pFaction], "Rank1" );
		SaveFData( gPlayerData[playerid][pFaction], "Rank2" );
		SaveFData( gPlayerData[playerid][pFaction], "Rank3" );
		SaveFData( gPlayerData[playerid][pFaction], "Rank4" );
		SaveFData( gPlayerData[playerid][pFaction], "Rank5" );
		SaveFData( gPlayerData[playerid][pFaction], "Rank6" );
		SaveFData( gPlayerData[playerid][pFaction], "Rank7" );
		SaveFData( gPlayerData[playerid][pFaction], "Rank8" );
		SaveFData( gPlayerData[playerid][pFaction], "Rank9" );
		SaveFData( gPlayerData[playerid][pFaction], "Rank10" );
		SaveFData( gPlayerData[playerid][pFaction], "Skin1" );
		SaveFData( gPlayerData[playerid][pFaction], "Skin2" );
		SaveFData( gPlayerData[playerid][pFaction], "Skin3" );
		SaveFData( gPlayerData[playerid][pFaction], "Skin4" );
		SaveFData( gPlayerData[playerid][pFaction], "Skin5" );
		SaveFData( gPlayerData[playerid][pFaction], "Skin6" );
		SaveFData( gPlayerData[playerid][pFaction], "Skin7" );
		SaveFData( gPlayerData[playerid][pFaction], "Skin8" );
		SaveFData( gPlayerData[playerid][pFaction], "Skin9" );
		SaveFData( gPlayerData[playerid][pFaction], "Skin10" );
		SaveFData( gPlayerData[playerid][pFaction], "JoinRank" );
		SaveFData( gPlayerData[playerid][pFaction], "UseSkins" );
		SaveFData( gPlayerData[playerid][pFaction], "Type" );
		SaveFData( gPlayerData[playerid][pFaction], "RankAmount" );
		SaveFData( gPlayerData[playerid][pFaction], "Color" );
		SaveFData( gPlayerData[playerid][pFaction], "UseColor" );
		SaveFData( gPlayerData[playerid][pFaction], "MaxCars" );
		SaveFData( gPlayerData[playerid][pFaction], "CarsCount" );
		SaveFData( gPlayerData[playerid][pFaction], "XDuty" );
		SaveFData( gPlayerData[playerid][pFaction], "YDuty" );
		SaveFData( gPlayerData[playerid][pFaction], "ZDuty" );
		SaveFData( gPlayerData[playerid][pFaction], "WorldDuty" );
		SaveFData( gPlayerData[playerid][pFaction], "InteriorDuty" );
		SaveFData( gPlayerData[playerid][pFaction], "XDuty2" );
		SaveFData( gPlayerData[playerid][pFaction], "YDuty2" );
		SaveFData( gPlayerData[playerid][pFaction], "ZDuty2" );
		SaveFData( gPlayerData[playerid][pFaction], "WorldDuty2" );
		SaveFData( gPlayerData[playerid][pFaction], "InteriorDuty2" );
		SaveFData( gPlayerData[playerid][pFaction], "TaxiKMCost" );
		SaveFData( gPlayerData[playerid][pFaction], "TaxiEnterCost" );
		SaveFData( gPlayerData[playerid][pFaction], "Gun1Rank1" );
		SaveFData( gPlayerData[playerid][pFaction], "Gun1Rank2" );
		SaveFData( gPlayerData[playerid][pFaction], "Gun1Rank3" );
		SaveFData( gPlayerData[playerid][pFaction], "Gun1Rank4" );
		SaveFData( gPlayerData[playerid][pFaction], "Gun1Rank5" );
		SaveFData( gPlayerData[playerid][pFaction], "Gun1Rank6" );
		SaveFData( gPlayerData[playerid][pFaction], "Gun1Rank7" );
		SaveFData( gPlayerData[playerid][pFaction], "Gun1Rank8" );
		SaveFData( gPlayerData[playerid][pFaction], "Gun1Rank9" );
		SaveFData( gPlayerData[playerid][pFaction], "Gun1Rank10" );
		SaveFData( gPlayerData[playerid][pFaction], "Gun2Rank1" );
		SaveFData( gPlayerData[playerid][pFaction], "Gun2Rank2" );
		SaveFData( gPlayerData[playerid][pFaction], "Gun2Rank3" );
		SaveFData( gPlayerData[playerid][pFaction], "Gun2Rank4" );
		SaveFData( gPlayerData[playerid][pFaction], "Gun2Rank5" );
		SaveFData( gPlayerData[playerid][pFaction], "Gun2Rank6" );
		SaveFData( gPlayerData[playerid][pFaction], "Gun2Rank7" );
		SaveFData( gPlayerData[playerid][pFaction], "Gun2Rank8" );
		SaveFData( gPlayerData[playerid][pFaction], "Gun2Rank9" );
		SaveFData( gPlayerData[playerid][pFaction], "Gun2Rank10" );
		SaveFData( gPlayerData[playerid][pFaction], "Gun3Rank1" );
		SaveFData( gPlayerData[playerid][pFaction], "Gun3Rank2" );
		SaveFData( gPlayerData[playerid][pFaction], "Gun3Rank3" );
		SaveFData( gPlayerData[playerid][pFaction], "Gun3Rank4" );
		SaveFData( gPlayerData[playerid][pFaction], "Gun3Rank5" );
		SaveFData( gPlayerData[playerid][pFaction], "Gun3Rank6" );
		SaveFData( gPlayerData[playerid][pFaction], "Gun3Rank7" );
		SaveFData( gPlayerData[playerid][pFaction], "Gun3Rank8" );
		SaveFData( gPlayerData[playerid][pFaction], "Gun3Rank9" );
		SaveFData( gPlayerData[playerid][pFaction], "Gun3Rank10" );
		SaveFData( gPlayerData[playerid][pFaction], "Ammo1Rank1" );
		SaveFData( gPlayerData[playerid][pFaction], "Ammo1Rank2" );
		SaveFData( gPlayerData[playerid][pFaction], "Ammo1Rank3" );
		SaveFData( gPlayerData[playerid][pFaction], "Ammo1Rank4" );
		SaveFData( gPlayerData[playerid][pFaction], "Ammo1Rank5" );
		SaveFData( gPlayerData[playerid][pFaction], "Ammo1Rank6" );
		SaveFData( gPlayerData[playerid][pFaction], "Ammo1Rank7" );
		SaveFData( gPlayerData[playerid][pFaction], "Ammo1Rank8" );
		SaveFData( gPlayerData[playerid][pFaction], "Ammo1Rank9" );
		SaveFData( gPlayerData[playerid][pFaction], "Ammo1Rank10" );
		SaveFData( gPlayerData[playerid][pFaction], "Ammo2Rank1" );
		SaveFData( gPlayerData[playerid][pFaction], "Ammo2Rank2" );
		SaveFData( gPlayerData[playerid][pFaction], "Ammo2Rank3" );
		SaveFData( gPlayerData[playerid][pFaction], "Ammo2Rank4" );
		SaveFData( gPlayerData[playerid][pFaction], "Ammo2Rank5" );
		SaveFData( gPlayerData[playerid][pFaction], "Ammo2Rank6" );
		SaveFData( gPlayerData[playerid][pFaction], "Ammo2Rank7" );
		SaveFData( gPlayerData[playerid][pFaction], "Ammo2Rank8" );
		SaveFData( gPlayerData[playerid][pFaction], "Ammo2Rank9" );
		SaveFData( gPlayerData[playerid][pFaction], "Ammo2Rank10" );
		SaveFData( gPlayerData[playerid][pFaction], "Ammo3Rank1" );
		SaveFData( gPlayerData[playerid][pFaction], "Ammo3Rank2" );
		SaveFData( gPlayerData[playerid][pFaction], "Ammo3Rank3" );
		SaveFData( gPlayerData[playerid][pFaction], "Ammo3Rank4" );
		SaveFData( gPlayerData[playerid][pFaction], "Ammo3Rank5" );
		SaveFData( gPlayerData[playerid][pFaction], "Ammo3Rank6" );
		SaveFData( gPlayerData[playerid][pFaction], "Ammo3Rank7" );
		SaveFData( gPlayerData[playerid][pFaction], "Ammo3Rank8" );
		SaveFData( gPlayerData[playerid][pFaction], "Ammo3Rank9" );
		SaveFData( gPlayerData[playerid][pFaction], "Ammo3Rank10" );
		SaveFData( gPlayerData[playerid][pFaction], "WFactoryEnabled" );
		SaveFData( gPlayerData[playerid][pFaction], "WFactoryBurning" );

		gPlayerData[playerid][pFaction] = 255;
		SavePlayerData( playerid, "Faction" );

		SendClientMessage( playerid, COLOR_GREEN, "[INFO:] Usun¹³eœ frakcje !" );
		return 1;
	}
	SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Tej frakcji nie mo¿na usun¹æ !" );
	return 1;
}

dcmd_utworzfrakcje( playerid, params[] )
{
	if( gPlayerData[playerid][pLevel] < 10 )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Musisz mieæ co najmniej 10 poziom postaci aby za³o¿yæ frakcje !" );
		return 1;
	}
	if( gPlayerData[playerid][pCash] < 100000 )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Musisz mieæ co najmniej 100 000 $ aby za³o¿yæ frakcj !" );
		return 1;
	}
	new factionName[50], factionType[5];
	if( sscanf( params, "s[50]s[5]", factionName, factionType ) )
	{
		SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] /utworzfrakcje [nazwa] [typ]" );
		SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] [typ:] gang, taxi" );
		return 1;
	}
	if( strlen(factionName) < 4 )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nazwa frakcji musi sk³adaæ siê z conajmniej 4 znaków" );
		return 1;
	}
	if( strcmp( factionType, "gang", true ) != 0 && strcmp( factionType, "taxi", true ) != 0 )
	{
		SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] /utworzfrakcje [nazwa] [typ]" );
		SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] [typ:] gang, taxi" );
		return 1;
	}
	for( new i = 14; i < sizeof(DynamicFactions); i++ )
	{
		if( i == 255 )
			continue;
		if( DynamicFactions[i][IsEnabled] )
			continue;
		DynamicFactions[i][IsEnabled] = 1;
		if( strcmp( factionType, "gang", true ) )
			DynamicFactions[i][fType] = 3;
		else
			DynamicFactions[i][fType] = 6;
		strdel( DynamicFactions[i][Name], 0, 49 );
		strins( DynamicFactions[i][Name], factionName, 0, sizeof(factionName) );
		new lowerCasePos;
		while( ( lowerCasePos = strfind( DynamicFactions[i][Name], "_", true ) ) != -1 )
		{
			strdel( DynamicFactions[i][Name], lowerCasePos, lowerCasePos+1 );
			strins( DynamicFactions[i][Name], " ", lowerCasePos );
		}
		SaveFData( i, "Name" );
		SaveFData( i, "IsEnabled" );
		gPlayerData[playerid][pFaction] = i;
		gPlayerData[playerid][pRank] = 1;
		// TODO: Cash is going nowhere, fix this
		GivePlayerCash( playerid, -100000 );
		SavePlayerData( playerid, "Faction" );
		SavePlayerData( playerid, "Rank" );
		SavePlayerData( playerid, "Type" );
		SendClientMessage( playerid, COLOR_GREEN, "[INFO:] Utworzy³eœ now¹ frakcje !" );
		return 1;
	}
	SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Brak wolnych slotów na now¹ frakcje !" );
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

dcmd_spec( playerid, params[] )
{
	if( gPlayerData[playerid][pModerator] == 0 )
		return 0;
	new givePlayerID;
	if( sscanf( params, "d", givePlayerID ) )
	{
		SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] /spec [player id]" );
		return 1;
	}
	if( !IsPlayerConnected( givePlayerID ) )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Player is offline" );
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

	TogglePlayerSpectating( playerid, 1 );
	SetPlayerVirtualWorld( playerid, GetPlayerVirtualWorld( givePlayerID ) );
	SetPlayerInterior( playerid, GetPlayerInterior( givePlayerID ) );
	if( IsPlayerInAnyVehicle( givePlayerID ) )
	{
		PlayerSpectateVehicle( playerid, GetPlayerVehicleID( givePlayerID ) );
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
		mysql_query( string, SAVE, INVALID_PLAYER_ID, db_con2 );
	}
	for( new i = 13; i < 500; i++ )
	{
		format( string, sizeof(string), "INSERT INTO `samp_factions_weapons2` (`FactionID`) VALUES ('%d') ", i );
		mysql_query( string, SAVE, INVALID_PLAYER_ID, db_con2 );
	}
	for( new i = 13; i < 500; i++ )
	{
		format( string, sizeof(string), "INSERT INTO `samp_factions_payrank` (`FactionID`) VALUES ('%d') ", i );
		mysql_query( string, SAVE, INVALID_PLAYER_ID, db_con2 );
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

dcmd_ustawopis( playerid, params[] )
{
	new string[64];
	if( sscanf( params, "s[64]", string ) )
	{
		SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] /ustawopis [opis...]" );
		return 1;
	}
	if( !gPlayerData[playerid][pFirstDescription] )
	{
		gPlayerData[playerid][pFirstDescription] = 1;
		SavePlayerData( playerid, "FirstDescription" );
		AddExpPoint(playerid);
		SendClientMessage( playerid, COLOR_GREEN, "[INFO:] Ustawi³eœ swój pierwszy poziom postaci !" );
		return 1;
	}
	strdel( gPlayerData[playerid][pCharDescription], 0, 64 );
	strins( gPlayerData[playerid][pCharDescription], string, 0 );
	Update3DTextLabelText( gPlayerData[playerid][pCharDescriptionID], gPlayerData[playerid][pCharDescriptionColor], gPlayerData[playerid][pCharDescription] );
	SavePlayerData( playerid, "CharDescription" );
	return 1;
}

dcmd_usunopis( playerid, params[] )
{
	#pragma unused params
	strdel( gPlayerData[playerid][pCharDescription], 0, 64 );
	strins( gPlayerData[playerid][pCharDescription], " ", 0 );
	Update3DTextLabelText( gPlayerData[playerid][pCharDescriptionID], gPlayerData[playerid][pCharDescriptionColor], gPlayerData[playerid][pCharDescription] );
	SavePlayerData( playerid, "CharDescription" );
	return 1;
}

dcmd_pokazopis( playerid, params[] )
{
	#pragma unused params
	new string[128];
	SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] Twój opis:" );
	format( string, sizeof(string), "[OPIS:] %s", gPlayerData[playerid][pCharDescription] );
	SendClientMessage( playerid, gPlayerData[playerid][pCharDescriptionColor], string );
	return 1;
}

dcmd_koloropisu( playerid, params[] )
{
	new string[30];
	if( sscanf( params, "s[30]", string ) )
	{
		SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] /koloropisu [kolor]" );
		SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] [kolor:] bialy, zolty, zielony, czerwony" );
		return 1;
	}
	if( strcmp( string, "bialy", true, 5 ) == 0 )
	{
		gPlayerData[playerid][pCharDescriptionColor] = 0xFFFFFFAA;
		Update3DTextLabelText( gPlayerData[playerid][pCharDescriptionID], gPlayerData[playerid][pCharDescriptionColor], gPlayerData[playerid][pCharDescription] );
		SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] Zmieni³eœ kolor opisu !" );
		SavePlayerData( playerid, "CharDescriptionColor" );
		return 1;
	}
	else if( strcmp( string, "zolty", true, 5 ) == 0 )
	{
		gPlayerData[playerid][pCharDescriptionColor] = 0xFFFF00AA;
		Update3DTextLabelText( gPlayerData[playerid][pCharDescriptionID], gPlayerData[playerid][pCharDescriptionColor], gPlayerData[playerid][pCharDescription] );
		SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] Zmieni³eœ kolor opisu !" );
		SavePlayerData( playerid, "CharDescriptionColor" );
		return 1;
	}
	else if( strcmp( string, "zielony", true, 7 ) == 0 )
	{
		gPlayerData[playerid][pCharDescriptionColor] = 0x9ACD32AA;
		Update3DTextLabelText( gPlayerData[playerid][pCharDescriptionID], gPlayerData[playerid][pCharDescriptionColor], gPlayerData[playerid][pCharDescription] );
		SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] Zmieni³eœ kolor opisu !" );
		SavePlayerData( playerid, "CharDescriptionColor" );
		return 1;
	}
	else if( strcmp( string, "czerwony", true, 7 ) == 0 )
	{
		gPlayerData[playerid][pCharDescriptionColor] = 0xA10000AA;
		Update3DTextLabelText( gPlayerData[playerid][pCharDescriptionID], gPlayerData[playerid][pCharDescriptionColor], gPlayerData[playerid][pCharDescription] );
		SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] Zmieni³eœ kolor opisu !" );
		SavePlayerData( playerid, "CharDescriptionColor" );
		return 1;
	}
	else
	{
		SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] /koloropisu [kolor]" );
		SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] [kolor:] bialy, zolty, zielony, czerwony" );
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
	SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] /stworzobiekt - /usunobiekt - /przesunobiekt - /ustawobiekt - /daneobiektow" );
	return 1;
}

dcmd_prosbaobiznes( playerid, params[] )
{
	if( gPlayerData[playerid][pBizKey] != 255 )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Posiadasz ju¿ biznes !" );
		return 1;
	}
	new givePlayerID, bizID;
	if( sscanf( params, "dd", givePlayerID, bizID ) )
	{
		SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] /prosbaobzines [id urzêdnika] [id biznesu]" );
		return 1;
	}
	if( !IsPlayerConnected( givePlayerID ) )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Ten gracz nie jest po³¹czony !" );
		return 1;
	}
	if( gPlayerData[givePlayerID][pFaction] != 9 )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Ta osoba nie jest urzêdnikiem !" );
		return 1;
	}
	if( bizID > sizeof(Businesses) || bizID < 0 )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie ma takiego biznesu !" );
		return 1;
	}
	if( Businesses[bizID][Owned] )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Ten biznes nie jest na sprzeda¿ !" );
		return 1;
	}
	new Float:x, Float:y, Float:z;
	GetPlayerPos( givePlayerID, x, y, z );
	if( !IsPlayerInRangeOfPoint( playerid, 5.0, x, y, z ) )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Jesteœ zbyt daleko od tej osoby !" );
		return 1;
	}
	new string[128];
	gBizBoughtApprovalSendBy[givePlayerID] = playerid;
	gBizBoughtApprovalID[playerid] = bizID;
	SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] Przekaz³eœ swoj¹ proœbe o biznes do urzêdnika" );
	format( string, sizeof(string), "[INFO:] %s prosi o pozwolenie na kupno biznesu ID: %d", GetPlayerNameEx(playerid), bizID );
	SendClientMessage( givePlayerID, COLOR_LIGHTYELLOW2, string );
	SendClientMessage( givePlayerID, COLOR_LIGHTYELLOW2, "[INFO:] Aby wydaæ pozwolenie wpisz: /akceptuj kupnobiznesu" );
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
	if( !IsPlayerInRangeOfPoint( playerid, 1.0, 359.0, 167.0, 1008.0 ) )
	{
		ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Nie jesteœ w kolekturze !", "Zamknij", "" );
		return 1;
	}
	new string[128], string2[128], Hour, Minute, Second;
	gettime(Hour, Minute, Second);

	if( ( gLuckyLotteryLastLottery == 2 && Hour < 21 ) || ( gLuckyLotteryLastLottery == 3 && Hour >= 21 ) )
		format( string2, sizeof(string2), "jutro !" );
	else if( gLuckyLotteryLastLottery == 3 && Hour < 21 )
		format( string2, sizeof(string2), "dzisiaj !" );
	else if( ( gLuckyLotteryLastLottery == 1 && Hour < 21 ) || ( gLuckyLotteryLastLottery == 2 && Hour >= 21 ) )
		format( string2, sizeof(string2), "za dwa dni" );
	else if( ( gLuckyLotteryLastLottery == 0 && Hour < 21 ) || ( gLuckyLotteryLastLottery == 1 && Hour >= 21 ) )
		format( string2, sizeof(string2), "za trzy dni" );

	format( string, sizeof(string), "Kumulacja: %d\nNastêpne losowanie: %s", gLuckyLotteryCash, string2 );
	ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", string, "Zamknij", "" );
	return 1;
}

dcmd_ostatnielosowanie(playerid, params[])
{
	#pragma unused params
	if( !IsPlayerInRangeOfPoint( playerid, 1.0, 359.0, 167.0, 1008.0 ) )
	{
		ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Nie jesteœ w kolekturze !", "Zamknij", "" );
		return 1;
	}
	new string[128];
	format( string, sizeof(string), "Numer ostatniego losowania: %d\n[Numerek 1: %d] [numerek 2: %d] [numerek 3: %d] [numerek 4: %d]", gLuckyLotteryID, gLuckyLotteryNumbers[0], gLuckyLotteryNumbers[1], gLuckyLotteryNumbers[2], gLuckyLotteryNumbers[3] );
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
	if( InsertPlayerItemEx(playerid, 3, 10, numbers[0], numbers[1], numbers[2], numbers[3], string ) == 0 )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie masz miejsca na kupon !" );
		return 1;
	}
	for( new i = 0; i < sizeof(gLuckyLottery); i++ )
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
		GivePlayerCash( playerid, -5 );
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
		mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
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
	if( gPlayerData[playerid][pLevel] < 2 )
	{
		SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Musisz mieæ 2 poziom postaci aby rozpocz¹æ g³osowanie" );
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

dcmd_wheelchangepos(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new slot;
	if(sscanf(params, "d", slot))
	{
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /wheelchangepos [slot(1-4)]");
		return 1;
	}
	new Float:posX, Float:posY, Float:posZ;
	GetPlayerPos(playerid, posX, posY, posZ);
	switch(slot)
	{
		case 1:
		{
			DestroyDynamicPickup(gWheelChangePos[pickup1]);
			gWheelChangePos[pos1X] = posX;
			gWheelChangePos[pos1Y] = posY;
			gWheelChangePos[pos1Z] = posZ;
			gWheelChangePos[pickup1] = CreateDynamicPickup(1239, 1, gWheelChangePos[pos1X], gWheelChangePos[pos1Y], gWheelChangePos[pos1Z]);
		}
		case 2:
		{
			DestroyDynamicPickup(gWheelChangePos[pickup2]);
			gWheelChangePos[pos2X] = posX;
			gWheelChangePos[pos2Y] = posY;
			gWheelChangePos[pos2Z] = posZ;
			gWheelChangePos[pickup3] = CreateDynamicPickup(1239, 1, gWheelChangePos[pos2X], gWheelChangePos[pos2Y], gWheelChangePos[pos2Z]);
		}
		case 3:
		{
			DestroyDynamicPickup(gWheelChangePos[pickup3]);
			gWheelChangePos[pos3X] = posX;
			gWheelChangePos[pos3Y] = posY;
			gWheelChangePos[pos3Z] = posZ;
			gWheelChangePos[pickup3] = CreateDynamicPickup(1239, 1, gWheelChangePos[pos3X], gWheelChangePos[pos3Y], gWheelChangePos[pos3Z]);
		}
		case 4:
		{
			DestroyDynamicPickup(gWheelChangePos[pickup4]);
			gWheelChangePos[pos4X] = posX;
			gWheelChangePos[pos4Y] = posY;
			gWheelChangePos[pos4Z] = posZ;
			gWheelChangePos[pickup4] = CreateDynamicPickup(1239, 1, gWheelChangePos[pos4X], gWheelChangePos[pos4Y], gWheelChangePos[pos4Z]);
		}
	}
	SaveWheelChangePosition();
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
	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /itemreproducecount - /itemprice");
	return 1;
}

dcmd_itemfactorydata(playerid, params[])
{
	if(gPlayerData[playerid][pAdmin] != 5)
		return 0;
	new fID, slot;
	if(sscanf(params, "dd", fID))
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
	strmid(gItemFactories[fID][fName], name, 0, 128);
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
	DestroyDynamicPickup(gItemFactories[fID][fPickupID]);
	gItemFactories[fID][fPickupID] = CreateDynamicPickup(1239, 1, gItemFactories[fID][fPosX], gItemFactories[fID][fPosY], gItemFactories[fID][fPosZ]);
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
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /itemfactoryitem [fID] [slot (1-10)] [item count]");
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

dcmd_itemfactoryproducecount(playerid, params[])
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
			gItemFactories[fID][item1minBuy] = itemProduceCount;
			SaveItemFactory(fID, "item1");
		}
		case 2:
		{
			gItemFactories[fID][item2minBuy] = itemProduceCount;
			SaveItemFactory(fID, "item2");
		}
		case 3:
		{
			gItemFactories[fID][item3minBuy] = itemProduceCount;
			SaveItemFactory(fID, "item3");
		}
		case 4:
		{
			gItemFactories[fID][item4minBuy] = itemProduceCount;
			SaveItemFactory(fID, "item4");
		}
		case 5:
		{
			gItemFactories[fID][item5minBuy] = itemProduceCount;
			SaveItemFactory(fID, "item5");
		}
		case 6:
		{
			gItemFactories[fID][item6minBuy] = itemProduceCount;
			SaveItemFactory(fID, "item6");
		}
		case 7:
		{
			gItemFactories[fID][item7minBuy] = itemProduceCount;
			SaveItemFactory(fID, "item7");
		}
		case 8:
		{
			gItemFactories[fID][item8minBuy] = itemProduceCount;
			SaveItemFactory(fID, "item8");
		}
		case 9:
		{
			gItemFactories[fID][item9minBuy] = itemProduceCount;
			SaveItemFactory(fID, "item9");
		}
		case 10:
		{
			gItemFactories[fID][item10minBuy] = itemProduceCount;
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
			gItemFactories[fID][item1minBuy] = itemPrice;
			SaveItemFactory(fID, "item1");
		}
		case 2:
		{
			gItemFactories[fID][item2minBuy] = itemPrice;
			SaveItemFactory(fID, "item2");
		}
		case 3:
		{
			gItemFactories[fID][item3minBuy] = itemPrice;
			SaveItemFactory(fID, "item3");
		}
		case 4:
		{
			gItemFactories[fID][item4minBuy] = itemPrice;
			SaveItemFactory(fID, "item4");
		}
		case 5:
		{
			gItemFactories[fID][item5minBuy] = itemPrice;
			SaveItemFactory(fID, "item5");
		}
		case 6:
		{
			gItemFactories[fID][item6minBuy] = itemPrice;
			SaveItemFactory(fID, "item6");
		}
		case 7:
		{
			gItemFactories[fID][item7minBuy] = itemPrice;
			SaveItemFactory(fID, "item7");
		}
		case 8:
		{
			gItemFactories[fID][item8minBuy] = itemPrice;
			SaveItemFactory(fID, "item8");
		}
		case 9:
		{
			gItemFactories[fID][item9minBuy] = itemPrice;
			SaveItemFactory(fID, "item9");
		}
		case 10:
		{
			gItemFactories[fID][item10minBuy] = itemPrice;
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

