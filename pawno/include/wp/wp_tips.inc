/***
*
* File: wp_tips.inc
* Auth: Damian Wojdat
* Date: 17.08.2013
* Desc: Gameplay tips.
*
*************************************************************************************************************/

stock ShowNewTip()
{	
	CurrentInformationTmp = random(15);
	while(CurrentInformation  == CurrentInformationTmp)
	{
		CurrentInformationTmp = random(15);
	}
	CurrentInformation = CurrentInformationTmp;
	switch(CurrentInformation)
	{
		case 0:
		{
			format(string, sizeof(string), "[TIPS:] Numery publiczne: 999 - Pogotowie, 997 - Policja, 411 - HALO Taxi, 555 - Warsztat Samochodowy");
		}
		case 1:
		{
			format(string, sizeof(string), "[TIPS:] Nie wiesz o co chodzi ? Masz propozycje zmian ? Wejdź na forum - WParty.eu");
		}
		case 2:
		{
			format(string, sizeof(string), "[TIPS:] Potrzebujesz pieniędzy ? Zatrudnij sie do pracy wybierając z pośród wielu ofert !");
			format(string2, sizeof(string2), "[TIPS:] Część prac znajduje się pod urzędem, reszta rozmieszczona jest po całym mieście.");
		}
		case 3:
		{
			format(string, sizeof(string), "[TIPS:] Widzisz cheatera lub gracza łamiącego zasady gry ? Skorzystaj z komendy /donos");
			format(string2, sizeof(string2), "[TIPS:] lub napisz na GG");
		}
		case 4:
		{
			format(string, sizeof(string), "[TIPS:] Chcesz wyróżniać się pośród inny ? Udaj się na do sklepu z ubraniami");
			format(string2, sizeof(string2), "[TIPS:] i wybierz jeden z modeli czapek czy też okularów");
		}
		case 5:
		{
			format(string, sizeof(string), "[TIPS:] Dołącz do grupy WParty SA:MP na facebooku już dziś !");
			format(string2, sizeof(string2), "[TIPS:] Bądź na bieżąco z wydarzeniami na serwerze i komentuj je");
		}
		case 6:
		{
			format(string, sizeof(string), "[TIPS:] Zostało Ci mało życia ? Udaj się do jednej z kilkudzisięciu knajp/restauracji");
			format(string2, sizeof(string2), "[TIPS:] i użyj komendy /jedz ew. idź do baru i napij sie - /kupdrink");
		}
		case 7:
		{
			format(string, sizeof(string), "[TIPS:] Zadaj nam pytanie na GG !");
			format(string2, sizeof(string2), "[TIPS:] GG: 20677329");
		}
		case 8:
		{
			format(string, sizeof(string), "[TIPS:] Gdy jesteś w pojeździe skorzystaj z komendy /radios !");
			format(string2, sizeof(string2), "[TIPS:] Do wyboru masz kilka różnych stacji (np. Radio ZET). ");
		}
		case 9:
		{
			format(string, sizeof(string), "[TIPS:] Czeste uzywanie /ja /do dodaje do gry urozmaicenie rozgrywki na WParty !");
			format(string2, sizeof(string2), "[TIPS:] Gra z dnia na dzien moze nas zadziwic uzywiajac akcji RP");
		}
		case 10:
		{
			format(string, sizeof(string), "[TIPS:] Stosujac mottto serwera : Zatrzymaj sie !!! : pomysl przed nastepna akcja czy jest ona Non RP czy RP");
			format(string2, sizeof(string2), "[TIPS:] W ten sposob uzyskasz 100 procent z frajdy z gry oraz zaufanie obecnych graczy");
		}
		case 11:
		{
			format(string, sizeof(string), "[TIPS:] Jeśli jesteś pracownikiem służb publicznych zalecane jest posiadanie GPSu.");
			format(string2, sizeof(string2), "[TIPS:] Dzięki niemu dużo łatwiej odnajdziesz ludzi w potrzebie.");
		}
		case 12:
		{
			format(string, sizeof(string), "[TIPS:] Posiadanie GPSu oraz telefonu ulatwi Ci gre oraz sluzbom publicznym.");
			format(string2, sizeof(string2), "[TIPS:] GPS kupisz w kazdym 24/7 a Telefon w dowolnej sieci komorkowej.");
		}
		case 13:
		{
			format(string, sizeof(string), "[TIPS:] Jeśli posiadasz już pojazd możesz go ubezpieczyć.");
			format(string2, sizeof(string2), "[TIPS:] Umowe o ubezpieczenie OC/AC możesz otrzymać od urzędnika.");
		}
		case 14:
		{
			format(string, sizeof(string), "[TIPS:] Chcesz się pozbyć pojazdu ? Udaj się na złomowisko i wpisz /zezlomuj pojazd.");
			format(string2, sizeof(string), "[TIPS:] Pobrana zostanie odgórnie ustalona stawka za złomowanie. Więcej informacji na forum.");
		}
	}
}
	