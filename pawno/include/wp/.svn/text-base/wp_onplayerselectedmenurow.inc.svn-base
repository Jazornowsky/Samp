public OnPlayerSelectedMenuRow(playerid, row)
{
	new Menu:CurrentMenu = GetPlayerMenu(playerid);
	if(CurrentMenu == przewodnik)
	{
		switch(row)
		{
			case 0: // zasady
			{
				SendClientMessage(playerid, COLOR_GREEN, "Podstawowe zasady serwera Wparty znajdziesz pod komenda /zasady");
				SendClientMessage(playerid, COLOR_GREEN, "Szczegolowe zasady obowiazujace znajdziesz na naszym forum www.wpartyrp.pl");
				SendClientMessage(playerid, COLOR_GREEN, "Wbijajac 2 lev postaci obejmuja Cie wszystkie zasady obowiazujace na Wparty");
				SendClientMessage(playerid, COLOR_GREEN, "Stosujac mottto serwera Zatrzymaj sie !!! pomysl przed nastepna akcja czy jest ona Non RP czy RP ");
				SendClientMessage(playerid, COLOR_GREEN, "Uzywajac motta serwera uzyskasz 100 procent z frajdy z gry oraz zaufanie obecnych graczy");
				SendClientMessage(playerid, COLOR_GREEN, "Administracja zyczy milej gry");
			}
			case 1: // kontakt
			{
				SendClientMessage(playerid, COLOR_GREEN, "Kontakt z administracja :");
				SendClientMessage(playerid, COLOR_GREEN, "1. www.wpartyrp.pl ");
				SendClientMessage(playerid, COLOR_GREEN, "2. aqq : wparty@aqq.eu gg : 20677329 - Prosze uzywac tylko w naglym wypadku ");
			}
			case 2: // Licencje
			{
				HideMenuForPlayer(przewodnik, playerid);
	            ShowMenuForPlayer(licencje, playerid);
			}
			case 3: //prace
			{
				HideMenuForPlayer(przewodnik, playerid);
	            ShowMenuForPlayer(prace, playerid);
			}
		/*	case 2: //test3
			{
				SendClientMessage(playerid, 0xFFFFFFFF, "test3");
			}
			case 3: //test4
			{
				SendClientMessage(playerid, 0xFFFFFFFF, "test4");
			}
			case 4: //test5
			{
				SendClientMessage(playerid, 0xFFFFFFFF, "test5");
			} */
		}
	}
	if(CurrentMenu == prace)
	{
		switch(row)
		{
			case 0: // Œmieciarka
			{
				SendClientMessage(playerid, COLOR_GREEN, "Praca zostala zaznaczona na mapie.");
	            SetPlayerCheckpoint(playerid,MzgkJob[TakeJobX],MzgkJob[TakeJobY],MzgkJob[TakeJobZ],5.0);
	            TogglePlayerControllable(playerid,1);
			}
			case 1: // Myjki drogowej
			{
				SendClientMessage(playerid, COLOR_GREEN, "Praca zostala zaznaczona na mapie.");
	            SetPlayerCheckpoint(playerid,SweeperJob[TakeJobX],SweeperJob[TakeJobY],SweeperJob[TakeJobZ],5.0);
	            TogglePlayerControllable(playerid,1);
			}
			case 2: //Kierowca Autobusu PKS
			{
				SendClientMessage(playerid, COLOR_GREEN, "Praca zostala zaznaczona na mapie.");
	            SetPlayerCheckpoint(playerid,BusJob[TakeJobX],BusJob[TakeJobY],BusJob[TakeJobZ],5.0);
	            TogglePlayerControllable(playerid,1);
			}
			case 3: //Farmer
			{
				SendClientMessage(playerid, COLOR_GREEN, "Praca zostala zaznaczona na mapie.");
	            SetPlayerCheckpoint(playerid,FarmerJob[TakeJobX],FarmerJob[TakeJobY],FarmerJob[TakeJobZ],5.0);
	            TogglePlayerControllable(playerid,1);
			}
			case 4: //Mechanik
			{
				SendClientMessage(playerid, COLOR_GREEN, "Praca zostala zaznaczona na mapie.");
	            SetPlayerCheckpoint(playerid,-2766.519531,375.653350,6.334681,5.0);
	            TogglePlayerControllable(playerid,1);
			}
			case 5: //Detektyw
			{
				SendClientMessage(playerid, COLOR_GREEN, "Praca zostala zaznaczona na mapie.");
	            SetPlayerCheckpoint(playerid,-2766.519531,375.653350,6.334681,5.0);
	            TogglePlayerControllable(playerid,1);
			}
			case 6: //Diler broni
			{
				SendClientMessage(playerid, COLOR_GREEN, "Praca zostala zaznaczona na mapie.");
	            SetPlayerCheckpoint(playerid,GunJob[TakeJobX],GunJob[TakeJobY],GunJob[TakeJobZ],5.0);
	            TogglePlayerControllable(playerid,1);
			}
			case 7: //Diler narkotyków
			{
				SendClientMessage(playerid, COLOR_GREEN, "Praca zostala zaznaczona na mapie.");
	            SetPlayerCheckpoint(playerid,DrugJob[TakeJobX],DrugJob[TakeJobY],DrugJob[TakeJobZ],5.0);
	            TogglePlayerControllable(playerid,1);
			}
			case 8: //Sprzedawca produktów
			{
				SendClientMessage(playerid, COLOR_GREEN, "Praca zostala zaznaczona na mapie.");
	            SetPlayerCheckpoint(playerid,ProductsSellerJob[TakeJobX],ProductsSellerJob[TakeJobY],ProductsSellerJob[TakeJobZ],5.0);
	            TogglePlayerControllable(playerid,1);
			}
			case 9: //Praca dziwki
			{
				SendClientMessage(playerid, COLOR_GREEN, "Praca zostala zaznaczona na mapie.");
	            SetPlayerCheckpoint(playerid,WhoreJob[TakeJobX],WhoreJob[TakeJobY],WhoreJob[TakeJobZ],5.0);
	            TogglePlayerControllable(playerid,1);
			}
			case 10: //Gwa³ciciel
			{
				SendClientMessage(playerid, COLOR_GREEN, "Praca zostala zaznaczona na mapie.");
	            SetPlayerCheckpoint(playerid,RapistJob[TakeJobX],RapistJob[TakeJobY],RapistJob[TakeJobZ],5.0);
	            TogglePlayerControllable(playerid,1);
			}
			case 11: //
			{
				HideMenuForPlayer(przewodnik, playerid);
	            ShowMenuForPlayer(prace2, playerid);
			}
		}
	}
	if(CurrentMenu == licencje)
	{
		switch(row)
		{
			case 0: // prawko
			{
				SendClientMessage(playerid, COLOR_GREEN, "Licencja zostala zaznaczona na mapie.");
	            SetPlayerCheckpoint(playerid,-2026.525146,-102.065269,35.164062,5.0);
	            TogglePlayerControllable(playerid,1);
			}
			case 1: //Licencja pilota
			{
				SendClientMessage(playerid, COLOR_GREEN, "Licencja zostala zaznaczona na mapie.");
	            SetPlayerCheckpoint(playerid,FlyingTestPosition[X],FlyingTestPosition[Y],FlyingTestPosition[Z],5.0);
	            TogglePlayerControllable(playerid,1);
			}
			case 2: //Licencja na bron
			{
				SendClientMessage(playerid, COLOR_GREEN, "Licencja zostala zaznaczona na mapie.");
	            SetPlayerCheckpoint(playerid,WeaponLicensePosition[X],WeaponLicensePosition[Y],WeaponLicensePosition[Z],5.0);
	            TogglePlayerControllable(playerid,1);
			}
			case 3: //Licencja na ³odzie
			{
				SendClientMessage(playerid, COLOR_GREEN, "Licencja zostala zaznaczona na mapie.");
	            SetPlayerCheckpoint(playerid,BoatTestPosition[X],BoatTestPosition[Y],BoatTestPosition[Z],5.0);
	            TogglePlayerControllable(playerid,1);
			}
		}
	}
	if(CurrentMenu == prace2)
	{
		switch(row)
		{
			case 0: // Prawnik
			{
				SendClientMessage(playerid, COLOR_GREEN, "Praca zostala zaznaczona na mapie.");
	            SetPlayerCheckpoint(playerid,-2766.519531,375.653350,6.334681,5.0);
	            TogglePlayerControllable(playerid,1);
			}
			case 1: //Boxer
			{
				//SendClientMessage(playerid, COLOR_GREEN, "Praca zostala zaznaczona na mapie.");
				SendClientMessage(playerid, COLOR_GREEN, "Dana praca jest w toku naprawy przez administracje .");
	           // SetPlayerCheckpoint(playerid,RapistJob[TakeJobX],RapistJob[TakeJobY],RapistJob[TakeJobZ],5.0);
	            TogglePlayerControllable(playerid,1);
			}
			case 2: //Z³odziej samochodów
			{
				SendClientMessage(playerid, COLOR_GREEN, "Praca zostala zaznaczona na mapie.");
	            SetPlayerCheckpoint(playerid,CarjackJob[TakeJobX],CarjackJob[TakeJobY],CarjackJob[TakeJobZ],5.0);
	            TogglePlayerControllable(playerid,1);
			}
			case 3: //Kaskader
			{
				//SendClientMessage(playerid, COLOR_GREEN, "Licencja zostala zaznaczona na mapie.");
	            //SetPlayerCheckpoint(playerid,BoatTestPosition[X],BoatTestPosition[Y],BoatTestPosition[Z],5.0);
				SendClientMessage(playerid, COLOR_GREEN, "Dana praca zosta³a wy³¹czona");
	            TogglePlayerControllable(playerid,1);
			}
			case 4: //Re¿yser
			{
				SendClientMessage(playerid, COLOR_GREEN, "Dana praca jest w toku naprawy przez administracje .");
				//SendClientMessage(playerid, COLOR_GREEN, "Praca zostala zaznaczona na mapie.");
	            //SetPlayerCheckpoint(playerid,RapistJob[TakeJobX],RapistJob[TakeJobY],RapistJob[TakeJobZ],5.0);
	            TogglePlayerControllable(playerid,1);
			}
			case 5: //"Ochroniarz"
			{
				SendClientMessage(playerid, COLOR_GREEN, "Praca zostala zaznaczona na mapie.");
	            SetPlayerCheckpoint(playerid,BodyJob[TakeJobX],BodyJob[TakeJobY],BodyJob[TakeJobZ],5.0);
	            TogglePlayerControllable(playerid,1);
			}
		}
	}
	return 1;
} // end of OnPlayerSelectedMenuRow
