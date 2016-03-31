/***
*
* File: wp_itemfncs.inc
* Auth: Damian Wojdat
* Date: 13.05.2012
* Desc: Functions related to player/vehicle/house items.
*
*************************************************************************************************************/

#include <wp\itemfncs\wp_itemfncs_player>
#include <wp\itemfncs\wp_itemfncs_biz>
#include <wp\itemfncs\wp_itemfncs_veh>
#include <wp\itemfncs\wp_itemfncs_house>

stock ItemCountOfType(type)
{
	if(type == 5)
		return 23;
	if(type == 8)
		return 69;
	if(type == 9)
		return 6;
	return 0;
}

stock ItemPrice(itemtype, itemid)
{
	if(itemtype == 1)
	{
		if(itemid == 1) // ³om
			return 0;
		if(itemid == 2) // kostka
			return 0;
		if(itemid == 3) // karta kredytowa TODO: move it to type 3
			return 0;
		if(itemid == 4) // ksi¹¿ka telefoniczna
			return 0;
		if(itemid == 5) // plecak
			return 0;
		if(itemid == 6) // rakieta
			return 0;
		if(itemid == 7) // ¿arówka H7
			return 0;
		if(itemid == 8) // zestaw fajerwerków
			return 0;
		if(itemid == 9) // baton WParty
			return 0;
		if(itemid == 10) // hak holowniczy
			return 0;
		if(itemid == 11) // alarm
			return 0;
		if(itemid == 12) // cygaro
			return 0;
		if(itemid == 13) // granat
			return 0;
		if(itemid == 14) // gas pieprzowy
			return 0;
		if(itemid == 15) // koktail mo³otowa
			return 0;
		if(itemid == 16) // pistolet 9mm
			return 950;
		if(itemid == 17) // pistolet 9mm z t³umikiem
			return 1050;
		if(itemid == 18) // pistolet Desert Eagle
			return 7000;
		if(itemid == 19) // shotgun
			return 4000;
		if(itemid == 20) // obrzyn
			return 0;
		if(itemid == 21) // shotgun bojowy
			return 0;
		if(itemid == 22) // pistolet maszynowy micro SMG
			return 4500;
		if(itemid == 23) // pistolet maszynowy MP5
			return 5000;
		if(itemid == 24) // karabinek AK-47
			return 7000;
		if(itemid == 25) // karabinek M4
			return 5000;
		if(itemid == 26) // tec9
			return 4500;
		if(itemid == 27) // karabin
			return 4000;
		if(itemid == 28) // karabin snajperski
			return 11000;
		if(itemid == 29) // wyrzutnia rakiet
			return 0;
		if(itemid == 30) // wyrzutnia rakiet z HS
			return 0;
		if(itemid == 31) // miotacz ognia
			return 0;
		if(itemid == 32) // minigun
			return 0;
		if(itemid == 33) // ³adunek wybuchowy
			return 0;
		if(itemid == 34) // spray
			return 0;
		if(itemid == 35) // gaœnica
			return 0;
		if(itemid == 36) // nabój 9mm
			return 4;
		if(itemid == 37) // nabój .50AE
			return 20;
		if(itemid == 38) // œrut
			return 10;
		if(itemid == 39) // nabój 7.62mm
			return 10;
		if(itemid == 40) // nabój 12.7mm
			return 50;
		if(itemid == 41) // KGP 66mm
			return 0;
		if(itemid == 42) // napalm
			return 0;
		if(itemid == 43) // pocisk pistol
			return 1;
		if(itemid == 44) // ³uska pistol
			return 1;
		if(itemid == 45) // proch pistol
			return 1;
		if(itemid == 46) // sp³onka pistol
			return 1;
		if(itemid == 47) // o³ów strzelb
			return 6;
		if(itemid == 48) // szkielet broni
			return 400;
		if(itemid == 49) // zespó³ zamka
			return 300;
		if(itemid == 50) // magazynek
			return 200;
		if(itemid == 51) // sprê¿yna powrotna
			return 40;
		if(itemid == 52) // komplet œrubek
			return 10;
		if(itemid == 53) // szkielet broni karabinowej
			return 1200;
		if(itemid == 54) // zespó³ zamka karabinu
			return 800;
		if(itemid == 55) // magazynek karabinu
			return 500;
		if(itemid == 56) // sprê¿yna powrotna karabinu
			return 40;
		if(itemid == 57) // kolba
			return 100;
		if(itemid == 58) // komplet œrubek karabinu
			return 10;
		if(itemid == 59) // t³umik
			return 100;
		if(itemid == 60) // luneta
			return 1000;
		if(itemid == 61) // lufa
			return 200;
		if(itemid == 62) // mechanizm spustowo-uderzeniowy
			return 100;
		if(itemid == 63) // nak³adki z tworzywa sztucznego
			return 100;
		if(itemid == 64) // mechanizm iglicy
			return 150;
		if(itemid == 65) // bezpiecznik typu listkowego
			return 100;
		if(itemid == 66) // przyrz¹dy celownicze
			return 50;
		if(itemid == 67) // szkielet
			return 70;
		if(itemid == 68) // stopka
			return 40;
		if(itemid == 69) // wew. sprê¿yna
			return 30;
		if(itemid == 70) // dosy³acz
			return 60;
		if(itemid == 71) // lufa karabinu
			return 600;
		if(itemid == 72) // mechanizm spustowo-uderzeniowy karabinu
			return 400;
		if(itemid == 73) // mechanizm iglicy karabinu
			return 450;
		if(itemid == 74) // bezpiecznik typu listkowego karabinu
			return 250;
		if(itemid == 75) // przyrz¹dy celownicze karabinu
			return 100;
		if(itemid == 76) // szkielet karabinu
			return 180;
		if(itemid == 77) // stopka karabinu
			return 110;
		if(itemid == 78) // wew. sprê¿yna karabinu
			return 60;
		if(itemid == 79) // dosy³acz karabinu
			return 150;
		if(itemid == 80) // szkielet lunety
			return 400;
		if(itemid == 81) // soczewki
			return 600;
		if(itemid == 82) // zestaw monta¿owy Tec9
			return 2150;
		if(itemid == 83) // skrzynka monta¿owa MP5
			return 350;
		if(itemid == 84) // zestaw monta¿owy AK-47
			return 150;
		if(itemid == 85) // skrzynka monta¿owa M4
			return 650;
		if(itemid == 86) // rêkojeœæ prze³adowania
			return 70;
		if(itemid == 87) // carbon
			return 4310;
		if(itemid == 88) // skrzynka monta¿owa karabinu
			return 150;
		if(itemid == 89) // siatka maskuj¹ca
			return 2700;
		if(itemid == 90) // luska strzelb
			return 1;
		if(itemid == 91) // proch strzelb
			return 2;
		if(itemid == 92) // splonka strzelb
			return 1;
		if(itemid == 93) // pocisk karab
			return 4;
		if(itemid == 94) // luska karab
			return 2;
		if(itemid == 95) // proch karab
			return 2;
		if(itemid == 96) // splonka karab
			return 2;
		if(itemid == 97) // pocisk snajp
			return 25;
		if(itemid == 98) // luska snajp
			return 10;
		if(itemid == 99) // proch snajp
			return 10;
		if(itemid == 100) // splonka snajp
			return 5;
		if(itemid == 101) // pocisk des eagle
			return 10;
		if(itemid == 102) // luska des eagle
			return 5;
		if(itemid == 103) // proch des eagle
			return 2;
		if(itemid == 104) // splonka des eagle
			return 2;
		if(itemid == 105) // mapa
			return 4;
		if(itemid == 106) // radio
			return 26;
	}
	return 0;
}

stock ItemName(itemtype, itemid)
{
	new string[64];
	if(itemtype == 1)
	{
		if(itemid == 1)
		{
			format(string, sizeof(string), "{A0C544}³om (DEPRECATED){FFFFFF}");
			return string;
		}
		else if(itemid == 2)
		{
			format(string, sizeof(string), "{A0C544}kostka{FFFFFF}");
			return string;
		}
		else if(itemid == 3)
		{
			format(string, sizeof(string), "{6698FF}karta kredytowa{FFFFFF}");
			return string;
		}
		else if(itemid == 4)
		{
			format(string, sizeof(string), "{A0C544}ksi¹¿ka telefoniczna{FFFFFF}");
			return string;
		}
		else if(itemid == 5)
		{
			format(string, sizeof(string), "{A0C544}plecak{FFFFFF}");
			return string;
		}
		else if(itemid == 6)
		{
			format(string, sizeof(string), "{A0C544}rakieta{FFFFFF}");
			return string;
		}
		else if(itemid == 7)
		{
			format(string, sizeof(string), "{FFF380}¿arówka H7{FFFFFF}");
			return string;
		}
		else if(itemid == 8)
		{
			format(string, sizeof(string), "{A0C544}zestaw fajerwerków{FFFFFF}");
			return string;
		}
		else if(itemid == 9)
		{
			format(string, sizeof(string), "{A0C544}baton WParty{FFFFFF}");
			return string;
		}
		else if(itemid == 10)
		{
			format(string, sizeof(string), "{FFF380}hak holowniczy{FFFFFF}");
			return string;
		}
		else if(itemid == 11)
		{
			format(string, sizeof(string), "{FFF380}alarm{FFFFFF}");
			return string;
		}
		else if(itemid == 12)
		{
			format(string, sizeof(string), "{A0C544}cygaro{FFFFFF}");
			return string;
		}
		else if(itemid == 13)
		{
			format(string, sizeof(string), "{7E2217}granat{FFFFFF}");
			return string;
		}
		else if(itemid == 14)
		{
			format(string, sizeof(string), "{7E2217}gas pieprzowy{FFFFFF}");
			return string;
		}
		else if(itemid == 15)
		{
			format(string, sizeof(string), "{7E2217}koktail mo³otowa{FFFFFF}");
			return string;
		}
		else if(itemid == 16)
		{
			format(string, sizeof(string), "{663399}pistolet 9mm{FFFFFF}");
			return string;
		}
		else if(itemid == 17)
		{
			format(string, sizeof(string), "{663399}pistolet 9mm z t³umikiem{FFFFFF}");
			return string;
		}
		else if(itemid == 18)
		{
			format(string, sizeof(string), "{663399}pistolet Desert Eagle{FFFFFF}");
			return string;
		}
		else if(itemid == 19)
		{
			format(string, sizeof(string), "{663399}shotgun{FFFFFF}");
			return string;
		}
		else if(itemid == 20)
		{
			format(string, sizeof(string), "{663399}obrzyn{FFFFFF}");
			return string;
		}
		else if(itemid == 21)
		{
			format(string, sizeof(string), "{663399}shotgun bojowy{FFFFFF}");
			return string;
		}
		else if(itemid == 22)
		{
			format(string, sizeof(string), "{663399}pistolet maszynowy micro SMG{FFFFFF}");
			return string;
		}
		else if(itemid == 23)
		{
			format(string, sizeof(string), "{663399}pistolet maszynowy MP5{FFFFFF}");
			return string;
		}
		else if(itemid == 24)
		{
			format(string, sizeof(string), "{663399}karabinek AK-47{FFFFFF}");
			return string;
		}
		else if(itemid == 25)
		{
			format(string, sizeof(string), "{663399}karabinek M4{FFFFFF}");
			return string;
		}
		else if(itemid == 26)
		{
			format(string, sizeof(string), "{663399}Tec9{FFFFFF}");
			return string;
		}
		else if(itemid == 27)
		{
			format(string, sizeof(string), "{663399}karabin{FFFFFF}");
			return string;
		}
		else if(itemid == 28)
		{
			format(string, sizeof(string), "{663399}karabin snajperski{FFFFFF}");
			return string;
		}
		else if(itemid == 29)
		{
			format(string, sizeof(string), "{663399}wyrzutnia rakiet{FFFFFF}");
			return string;
		}
		else if(itemid == 30)
		{
			format(string, sizeof(string), "{663399}wyrzutnia rakiet z HS{FFFFFF}");
			return string;
		}
		else if(itemid == 31)
		{
			format(string, sizeof(string), "{663399}miotacz ognia{FFFFFF}");
			return string;
		}
		else if(itemid == 32)
		{
			format(string, sizeof(string), "{663399}minigun{FFFFFF}");
			return string;
		}
		else if(itemid == 33)
		{
			format(string, sizeof(string), "{663399}³adunek wybuchowy{FFFFFF}");
			return string;
		}
		else if(itemid == 34)
		{
			format(string, sizeof(string), "{663399}spray{FFFFFF}");
			return string;
		}
		else if(itemid == 35)
		{
			format(string, sizeof(string), "{663399}gaœnica{FFFFFF}");
			return string;
		}
		else if(itemid == 36)
		{
			format(string, sizeof(string), "{6633DD}nabój 9mm{FFFFFF}");
			return string;
		}
		else if(itemid == 37)
		{
			format(string, sizeof(string), "{6633DD}nabój .50 AE{FFFFFF}");
			return string;
		}
		else if(itemid == 38)
		{
			format(string, sizeof(string), "{6633DD}œrut{FFFFFF}");
			return string;
		}
		else if(itemid == 39)
		{
			format(string, sizeof(string), "{6633DD}nabój 7.62mm{FFFFFF}");
			return string;
		}
		else if(itemid == 40)
		{
			format(string, sizeof(string), "{6633DD}nabój 12.7mm{FFFFFF}");
			return string;
		}
		else if(itemid == 41)
		{
			format(string, sizeof(string), "{6633DD}KGP 66mm{FFFFFF}");
			return string;
		}
		else if(itemid == 42)
		{
			format(string, sizeof(string), "{6633DD}napalm{FFFFFF}");
			return string;
		}
		else if(itemid == 43)
		{
			format(string, sizeof(string), "{995500}pocisk 9mm{FFFFFF}");
			return string;
		}
		else if(itemid == 44)
		{
			format(string, sizeof(string), "{995500}³uska 9mm{FFFFFF}");
			return string;
		}
		else if(itemid == 45)
		{
			format(string, sizeof(string), "{995500}proch admidowy{FFFFFF}");
			return string;
		}
		else if(itemid == 46)
		{
			format(string, sizeof(string), "{995500}sp³onka 9mm{FFFFFF}");
			return string;
		}
		else if(itemid == 47)
		{
			format(string, sizeof(string), "{995500}o³ów{FFFFFF}");
			return string;
		}
		else if(itemid == 48)
		{
			format(string, sizeof(string), "{995500}szkielet broni{FFFFFF}");
			return string;
		}
		else if(itemid == 49)
		{
			format(string, sizeof(string), "{995500}zespó³ zamka{FFFFFF}");
			return string;
		}
		else if(itemid == 50)
		{
			format(string, sizeof(string), "{995500}magazynek{FFFFFF}");
			return string;
		}
		else if(itemid == 51)
		{
			format(string, sizeof(string), "{995500}sprê¿yna powrotna{FFFFFF}");
			return string;
		}
		else if(itemid == 52)
		{
			format(string, sizeof(string), "{995500}komplet œrubek{FFFFFF}");
			return string;
		}
		else if(itemid == 53)
		{
			format(string, sizeof(string), "{995500}szkielet broni karabinowej{FFFFFF}");
			return string;
		}
		else if(itemid == 54)
		{
			format(string, sizeof(string), "{995500}zespó³ zamka karabinu{FFFFFF}");
			return string;
		}
		else if(itemid == 55)
		{
			format(string, sizeof(string), "{995500}magazynek karabinu{FFFFFF}");
			return string;
		}
		else if(itemid == 56)
		{
			format(string, sizeof(string), "{995500}sprê¿yna powrotna karabinu{FFFFFF}");
			return string;
		}
		else if(itemid == 57)
		{
			format(string, sizeof(string), "{995500}kolba{FFFFFF}");
			return string;
		}
		else if(itemid == 58)
		{
			format(string, sizeof(string), "{995500}komplet œrubek karabinu{FFFFFF}");
			return string;
		}
		else if(itemid == 59)
		{
			format(string, sizeof(string), "{995500}t³umik{FFFFFF}");
			return string;
		}
		else if(itemid == 60)
		{
			format(string, sizeof(string), "{995500}luneta{FFFFFF}");
			return string;
		}
		else if(itemid == 61)
		{
			format(string, sizeof(string), "{99AA00}lufa{FFFFFF}");
			return string;
		}
		else if(itemid == 62)
		{
			format(string, sizeof(string), "{99AA00}mechanizm spustowo-uderzeniowy{FFFFFF}");
			return string;
		}
		else if(itemid == 63)
		{
			format(string, sizeof(string), "{99AA00}nak³adki z tworzywa sztucznego{FFFFFF}");
			return string;
		}
		else if(itemid == 64)
		{
			format(string, sizeof(string), "{99AA00}mechanizm iglicy{FFFFFF}");
			return string;
		}
		else if(itemid == 65)
		{
			format(string, sizeof(string), "{99AA00}bezpiecznik typu listkowego{FFFFFF}");
			return string;
		}
		else if(itemid == 66)
		{
			format(string, sizeof(string), "{99AA00}przyrz¹dy celownicze{FFFFFF}");
			return string;
		}
		else if(itemid == 67)
		{
			format(string, sizeof(string), "{99AA00}szkielet{FFFFFF}");
			return string;
		}
		else if(itemid == 68)
		{
			format(string, sizeof(string), "{99AA00}stopka{FFFFFF}");
			return string;
		}
		else if(itemid == 69)
		{
			format(string, sizeof(string), "{99AA00}wew. sprê¿yna{FFFFFF}");
			return string;
		}
		else if(itemid == 70)
		{
			format(string, sizeof(string), "{99AA00}dosy³acz{FFFFFF}");
			return string;
		}
		else if(itemid == 71)
		{
			format(string, sizeof(string), "{99AA00}lufa karabinu{FFFFFF}");
			return string;
		}
		else if(itemid == 72)
		{
			format(string, sizeof(string), "{99AA00}mechanizm spustowo-uderzeniowy karabinu{FFFFFF}");
			return string;
		}
		else if(itemid == 73)
		{
			format(string, sizeof(string), "{99AA00}mechanizm iglicy karabinu{FFFFFF}");
			return string;
		}
		else if(itemid == 74)
		{
			format(string, sizeof(string), "{99AA00}bezpiecznik typu listkowego karabinu{FFFFFF}");
			return string;
		}
		else if(itemid == 75)
		{
			format(string, sizeof(string), "{99AA00}przyrz¹dy celownicze karabinu{FFFFFF}");
			return string;
		}
		else if(itemid == 76)
		{
			format(string, sizeof(string), "{99AA00}szkielet karabinu{FFFFFF}");
			return string;
		}
		else if(itemid == 77)
		{
			format(string, sizeof(string), "{99AA00}stopka karabinu{FFFFFF}");
			return string;
		}
		else if(itemid == 78)
		{
			format(string, sizeof(string), "{99AA00}wew. sprê¿yna karabinu{FFFFFF}");
			return string;
		}
		else if(itemid == 79)
		{
			format(string, sizeof(string), "{99AA00}dosy³acz karabinu{FFFFFF}");
			return string;
		}
		else if(itemid == 80)
		{
			format(string, sizeof(string), "{99AA00}szkielet lunety{FFFFFF}");
			return string;
		}
		else if(itemid == 81)
		{
			format(string, sizeof(string), "{99AA00}soczewki{FFFFFF}");
			return string;
		}
		else if(itemid == 82)
		{
			format(string, sizeof(string), "{99AA00}zestaw monta¿owy Tec9{FFFFFF}");
			return string;
		}
		else if(itemid == 83)
		{
			format(string, sizeof(string), "{99AA00}skrzynka monta¿owa MP5{FFFFFF}");
			return string;
		}
		else if(itemid == 84)
		{
			format(string, sizeof(string), "{99AA00}zestaw monta¿owy AK-47{FFFFFF}");
			return string;
		}
		else if(itemid == 85)
		{
			format(string, sizeof(string), "{99AA00}skrzynka monta¿owa M4{FFFFFF}");
			return string;
		}
		else if(itemid == 86)
		{
			format(string, sizeof(string), "{99AA00}rêkojeœæ prze³adowania{FFFFFF}");
			return string;
		}
		else if(itemid == 87)
		{
			format(string, sizeof(string), "{99AA00}carbon{FFFFFF}");
			return string;
		}
		else if(itemid == 88)
		{
			format(string, sizeof(string), "{99AA00}skrzynka monta¿owa karabinu{FFFFFF}");
			return string;
		}
		else if(itemid == 89)
		{
			format(string, sizeof(string), "{99AA00}siatka maskuj¹ca{FFFFFF}");
			return string;
		}
		else if(itemid == 90)
		{
			format(string, sizeof(string), "{99AA00}³uska do strzelby{FFFFFF}");
			return string;
		}
		else if(itemid == 91)
		{
			format(string, sizeof(string), "{99AA00}proch œwiszcz¹cy{FFFFFF}");
			return string;
		}
		else if(itemid == 92)
		{
			format(string, sizeof(string), "{99AA00}sp³onka do strzelby{FFFFFF}");
			return string;
		}
		else if(itemid == 93)
		{
			format(string, sizeof(string), "{99AA00}pocisk 7.62mm{FFFFFF}");
			return string;
		}
		else if(itemid == 94)
		{
			format(string, sizeof(string), "{99AA00}luska 7.62mm{FFFFFF}");
			return string;
		}
		else if(itemid == 95)
		{
			format(string, sizeof(string), "{99AA00}proch czarny{FFFFFF}");
			return string;
		}
		else if(itemid == 96)
		{
			format(string, sizeof(string), "{99AA00}sp³onka 7.62mm{FFFFFF}");
			return string;
		}
		else if(itemid == 97)
		{
			format(string, sizeof(string), "{99AA00}pocisk 12.7mm{FFFFFF}");
			return string;
		}
		else if(itemid == 98)
		{
			format(string, sizeof(string), "{99AA00}³uska 12.7mm{FFFFFF}");
			return string;
		}
		else if(itemid == 99)
		{
			format(string, sizeof(string), "{99AA00}proch bobinit{FFFFFF}");
			return string;
		}
		else if(itemid == 100)
		{
			format(string, sizeof(string), "{99AA00}sp³onka 12.7mm{FFFFFF}");
			return string;
		}
		else if(itemid == 101)
		{
			format(string, sizeof(string), "{99AA00}pocisk .50AE{FFFFFF}");
			return string;
		}
		else if(itemid == 102)
		{
			format(string, sizeof(string), "{99AA00}luska .50AE{FFFFFF}");
			return string;
		}
		else if(itemid == 103)
		{
			format(string, sizeof(string), "{99AA00}proch ignis volatilis{FFFFFF}");
			return string;
		}
		else if(itemid == 104)
		{
			format(string, sizeof(string), "{99AA00}sp³onka .50AE{FFFFFF}");
			return string;
		}
		else if(itemid == 105)
		{
			format(string, sizeof(string), "{A0C544}Mapa San Andreas{FFFFFF}");
			return string;
		}
		else if(itemid == 106)
		{
			format(string, sizeof(string), "{A0C544}radioodbiornik{FFFFFF}");
			return string;
		}
		else if(itemid == 107)
		{
			format(string, sizeof(string), "{A0C544}zegarek Classy z³oty, bia³a tarcza{FFFFFF}");
			return string;
		}
		else if(itemid == 108)
		{
			format(string, sizeof(string), "{A0C544}zegarek Classy srebrny, czarna tarcza{FFFFFF}");
			return string;
		}
		else if(itemid == 109)
		{
			format(string, sizeof(string), "{A0C544}zegarek Classy miedziany, czarna tarcza{FFFFFF}");
			return string;
		}
		else if(itemid == 110)
		{
			format(string, sizeof(string), "{A0C544}zegarek Classy z³oty, czarna tarcza{FFFFFF}");
			return string;
		}
		else if(itemid == 111)
		{
			format(string, sizeof(string), "{A0C544}zegarek Classy srebrny, bia³¹ tarcza{FFFFFF}");
			return string;
		}
		else if(itemid == 112)
		{
			format(string, sizeof(string), "{A0C544}zegarek Fashio fioletowy, czarna tarcza{FFFFFF}");
			return string;
		}
		else if(itemid == 113)
		{
			format(string, sizeof(string), "{A0C544}zegarek Fashio czerwony, czarna tarcza{FFFFFF}");
			return string;
		}
		else if(itemid == 114)
		{
			format(string, sizeof(string), "{A0C544}zegarek Fashio zielony, czarna tarcza{FFFFFF}");
			return string;
		}
		else if(itemid == 115)
		{
			format(string, sizeof(string), "{A0C544}zegarek Fashio ciemny fiolet, czarna tarcza{FFFFFF}");
			return string;
		}
		else if(itemid == 116)
		{
			format(string, sizeof(string), "{A0C544}zegarek Fashio Limited E1, czarna tarcza{FFFFFF}");
			return string;
		}
		else if(itemid == 117)
		{
			format(string, sizeof(string), "{A0C544}zegarek Fashio Limited E2, czarna tarcza{FFFFFF}");
			return string;
		}
		else if(itemid == 118)
		{
			format(string, sizeof(string), "{A0C544}zegarek Fashio Limited E3, czarna tarcza{FFFFFF}");
			return string;
		}
		else if(itemid == 119)
		{
			format(string, sizeof(string), "{A0C544}zegarek Fashio Limited E4, czarna tarcza{FFFFFF}");
			return string;
		}
		else if(itemid == 120)
		{
			format(string, sizeof(string), "{A0C544}zegarek Fashio Limited E5, czarna tarcza{FFFFFF}");
			return string;
		}
		else if(itemid == 121)
		{
			format(string, sizeof(string), "{A0C544}zegarek Fashio Limited E6, czarna tarcza{FFFFFF}");
			return string;
		}
		else if(itemid == 122)
		{
			format(string, sizeof(string), "{FFF380}Samochodowy Komputer Policyjny{FFFFFF}");
			return string;
		}
		else if(itemid == 123)
		{
			format(string, sizeof(string), "{FFF380}CB Radio C{FFFFFF}");
			return string;
		}
		else if(itemid == 124)
		{
			format(string, sizeof(string), "{FFF380}CB Radio SE{FFFFFF}");
			return string;
		}
		else if(itemid == 125)
		{
			format(string, sizeof(string), "{A0C544}Cola WParty{FFFFFF}");
			return string;
		}
		else if(itemid == 126)
		{
			format(string, sizeof(string), "{A0C544}woda mineralna{FFFFFF}");
			return string;
		}
		else if(itemid == 127)
		{
			format(string, sizeof(string), "{A0C544}woda Ÿródlana{FFFFFF}");
			return string;
		}
		else if(itemid == 128)
		{
			format(string, sizeof(string), "{A0C544}baton Leon{FFFFFF}");
			return string;
		}
		else if(itemid == 129)
		{
			format(string, sizeof(string), "{A0C544}czekolada WParty{FFFFFF}");
			return string;
		}
		else if(itemid == 130)
		{
			format(string, sizeof(string), "{A0C544}jab³ko{FFFFFF}");
			return string;
		}
		else if(itemid == 131)
		{
			format(string, sizeof(string), "{A0C544}marchewka{FFFFFF}");
			return string;
		}
		else if(itemid == 132)
		{
			format(string, sizeof(string), "{A0C544}mandarynka{FFFFFF}");
			return string;
		}
		else if(itemid == 133)
		{
			format(string, sizeof(string), "{A0C544}mleko{FFFFFF}");
			return string;
		}
		else if(itemid == 134)
		{
			format(string, sizeof(string), "{A0C544}Atat{FFFFFF}");
			return string;
		}
		else if(itemid == 135)
		{
			format(string, sizeof(string), "{A0C544}2kace{FFFFFF}");
			return string;
		}
		else if(itemid == 136)
		{
			format(string, sizeof(string), "{A0C544}Pigu³ka Cud{FFFFFF}");
			return string;
		}
		else if(itemid == 137)
		{
			format(string, sizeof(string), "{A0C544}Krople ¿o³¹dkowe{FFFFFF}");
			return string;
		}
		else if(itemid == 138)
		{
			format(string, sizeof(string), "{A0C544}MultiVit{FFFFFF}");
			return string;
		}
		else if(itemid == 139)
		{
			format(string, sizeof(string), "{A0C544}Untoxin{FFFFFF}");
			return string;
		}
		else if(itemid == 140)
		{
			format(string, sizeof(string), "{A0C544}PowerBuild{FFFFFF}");
			return string;
		}
		else if(itemid == 141)
		{
			format(string, sizeof(string), "{A0C544}OutOff{FFFFFF}");
			return string;
		}
		else if(itemid == 142)
		{
			format(string, sizeof(string), "{A0C544}Lewatyks{FFFFFF}");
			return string;
		}
		else if(itemid == 143)
		{
			format(string, sizeof(string), "{A0C544}Zestaw do wyrabiania kluczy{FFFFFF}");
			return string;
		}
		else if(itemid == 144)
		{
			format(string, sizeof(string), "{A0C544}Zu¿yte do³adowanie karty SIM{FFFFFF}");
			return string;
		}
		else if(itemid == 145)
		{
			format(string, sizeof(string), "{6633DD}pa³ka{FFFFFF}");
			return string;
		}
		else if(itemid == 146)
		{
			format(string, sizeof(string), "{6633DD}kij bilardowy{FFFFFF}");
			return string;
		}
		else if(itemid == 147)
		{
			format(string, sizeof(string), "{6633DD}kastet{FFFFFF}");
			return string;
		}
		else if(itemid == 148)
		{
			format(string, sizeof(string), "{6633DD}nó¿{FFFFFF}");
			return string;
		}
		else if(itemid == 149)
		{
			format(string, sizeof(string), "{6633DD}³opata{FFFFFF}");
			return string;
		}
		else if(itemid == 150)
		{
			format(string, sizeof(string), "{6633DD}laska{FFFFFF}");
			return string;
		}
		else if(itemid == 151)
		{
			format(string, sizeof(string), "{FFF380}zestaw do monitoringu{FFFFFF}");
			return string;
		}
		else if(itemid == 152)
		{
			format(string, sizeof(string), "{FFEC80}œwiat³o policyjne (listwa){FFFFFF}");
			return string;
		}
		else if(itemid == 153)
		{
			format(string, sizeof(string), "{FFEC80}œwiat³o policyjne (pojedyncze){FFFFFF}");
			return string;
		}
		else if(itemid == 154)
		{
			format(string, sizeof(string), "{FFEC80}listwa TAXI styl 1{FFFFFF}");
			return string;
		}
		else if(itemid == 155)
		{
			format(string, sizeof(string), "{FFEC80}listwa TAXI styl 2{FFFFFF}");
			return string;
		}
		else if(itemid == 156)
		{
			format(string, sizeof(string), "{FFEC80}listwa TAXI styl 3{FFFFFF}");
			return string;
		}
		else if(itemid == 157)
		{
			format(string, sizeof(string), "{FFEC80}listwa TAXI styl 4{FFFFFF}");
			return string;
		}
		else if(itemid == 158)
		{
			format(string, sizeof(string), "{FFEC80}lampa halogenowa{FFFFFF}");
			return string;
		}
		else if(itemid == 159)
		{
			format(string, sizeof(string), "{FFEC80}dioda bia³a{FFFFFF}");
			return string;
		}
		else if(itemid == 160)
		{
			format(string, sizeof(string), "{FFEC80}dioda czerwona{FFFFFF}");
			return string;
		}
		else if(itemid == 161)
		{
			format(string, sizeof(string), "{FFEC80}dioda zielona{FFFFFF}");
			return string;
		}
		else if(itemid == 162)
		{
			format(string, sizeof(string), "{FFEC80}dioda niebieska{FFFFFF}");
			return string;
		}
		else if(itemid == 163)
		{
			format(string, sizeof(string), "{A0C544}nasiona marihuany{FFFFFF}");
			return string;
		}
		else if(itemid == 164)
		{
			format(string, sizeof(string), "{A0C544}liœæ marihuany{FFFFFF}");
			return string;
		}
		else if(itemid == 165)
		{
			format(string, sizeof(string), "{A0C544}joint{FFFFFF}");
			return string;
		}
		else if(itemid == 166)
		{
			format(string, sizeof(string), "{A0C544}ksi¹¿ka do nauki zasad ruchu drogowego{FFFFFF}");
			return string;
		}
		else if(itemid == 167)
		{
			format(string, sizeof(string), "{FFEC80}neon czerwony{FFFFFF}");
			return string;
		}
		else if(itemid == 168)
		{
			format(string, sizeof(string), "{FFEC80}neon niebieski{FFFFFF}");
			return string;
		}
		else if(itemid == 169)
		{
			format(string, sizeof(string), "{FFEC80}neon zielony{FFFFFF}");
			return string;
		}
		else if(itemid == 170)
		{
			format(string, sizeof(string), "{FFEC80}neon ¿ó³ty{FFFFFF}");
			return string;
		}
		else if(itemid == 171)
		{
			format(string, sizeof(string), "{FFEC80}neon ró¿owy{FFFFFF}");
			return string;
		}
		else if(itemid == 172)
		{
			format(string, sizeof(string), "{FFEC80}neon bia³y{FFFFFF}");
			return string;
		}
		else if(itemid == 173)
		{
			format(string, sizeof(string), "{A0C544}aparat{FFFFFF}");
			return string;
		}
		else if(itemid == 174)
		{
			format(string, sizeof(string), "{A0C544}skrzynka z narzêdziami{FFFFFF}");
			return string;
		}
		else if(itemid == 175)
		{
			format(string, sizeof(string), "{FFEC80}czêœci silnika{FFFFFF}");
			return string;
		}
		else if(itemid == 176)
		{
			format(string, sizeof(string), "{FFEC80}opona{FFFFFF}");
			return string;
		}
		else if(itemid == 177)
		{
			format(string, sizeof(string), "{FFEC80}instalacja gazowa{FFFFFF}");
			return string;
		}
		else if(itemid == 178)
		{
			format(string, sizeof(string), "{A0C544}tablica og³oszeñ{FFFFFF}");
			return string;
		}
	}
	if(itemtype == 2)
	{
		format(string, sizeof(string), "{E56717}kluczyki do pojazdu o nr rejestracyjnym: %d{FFFFFF}", itemid);
		return string;
	}
	if(itemtype == 3)
	{
		if(itemid == 1)
		{
			format(string, sizeof(string), "{A0C544}kanister{FFFFFF}");
			return string;
		}
		if(itemid == 2)
		{
			format(string, sizeof(string), "{A0C544}krótkofalówka{FFFFFF}");
			return string;
		}
		if(itemid == 3)
		{
			format(string, sizeof(string), "{A0C544}telefon bez radia FM{FFFFFF}");
			return string;
		}
		if(itemid == 4)
		{
			format(string, sizeof(string), "{A0C544}telefon z radiem FM{FFFFFF}");
			return string;
		}
		if(itemid == 5)
		{
			format(string, sizeof(string), "{6698FF}dowód{FFFFFF}");
			return string;
		}
		if(itemid == 6)
		{
			format(string, sizeof(string), "{6698FF}prawo jazdy{FFFFFF}");
			return string;
		}
		if(itemid == 7)
		{
			format(string, sizeof(string), "{7E2217}okulary{FFFFFF}");
			return string;
		}
		if(itemid == 8)
		{
			format(string, sizeof(string), "{FFF380}linka holownicza{FFFFFF}");
			return string;
		}
		if(itemid == 9)
		{
			format(string, sizeof(string), "{7E2217}czapka{FFFFFF}");
			return string;
		}
		if(itemid == 10)
		{
			format(string, sizeof(string), "{7E2217}kupon Szczêœliwej Loterii{FFFFFF}");
			return string;
		}
		if(itemid == 11)
		{
			format(string, sizeof(string), "{6698FF}dokument ukoñczenia egzaminu na prawo jazdy{FFFFFF}");
			return string;
		}
		if(itemid == 12)
		{
			format(string, sizeof(string), "{A0C544}GPS{FFFFFF}");
			return string;
		}
		if(itemid == 13)
		{
			format(string, sizeof(string), "{A0C544}krótkofalówka SE{FFFFFF}");
			return string;
		}
		if(itemid == 14)
		{
			format(string, sizeof(string), "{7E2217}chusta{FFFFFF}");
			return string;
		}
		if(itemid == 15)
		{
			format(string, sizeof(string), "{A0C544}zamek do drzwi{FFFFFF}");
			return string;
		}
		if(itemid == 16)
		{
			format(string, sizeof(string), "{A0C544}karta SIM{FFFFFF}");
			return string;
		}
		if(itemid == 17)
		{
			format(string, sizeof(string), "{A0C544}do³adowanie karty SIM{FFFFFF}");
			return string;
		}
		if(itemid == 18)
		{
			format(string, sizeof(string), "{A0C544}legitymacja egzaminatora WORDu{FFFFFF}");
			return string;
		}
		if(itemid == 19)
		{
			format(string, sizeof(string), "{A0C544}dowód rejestracyjny pojazdu{FFFFFF}");
			return string;
		}
		if(itemid == 20)
		{
			format(string, sizeof(string), "{A0C544}³om{FFFFFF}");
			return string;
		}
		if(itemid == 21)
		{
			format(string, sizeof(string), "{A0C544}wytrych{FFFFFF}");
			return string;
		}
		if(itemid == 22)
		{
			format(string, sizeof(string), "{7E2217}lekki pancerz{FFFFFF}");
			return string;
		}
		if(itemid == 23)
		{
			format(string, sizeof(string), "{7E2217}ciê¿ki pancerz{FFFFFF}");
			return string;
		}
		if(itemid == 24)
		{
			format(string, sizeof(string), "{7E2217}ubranie{FFFFFF}");
			return string;
		}
		if(itemid == 25)
		{
			format(string, sizeof(string), "{A0C544}umowa wypo¿yczenia pojazdu{FFFFFF}");
			return string;
		}
	}
	if(itemtype == 4)
	{
		format(string, sizeof(string), "{C35617}kluczyki do domu/gara¿u od id: %d{FFFFFF}", itemid);
		return string;
	}
	if(itemtype == 5)
	{
		if(itemid == 1)
		{
			format(string, sizeof(string), "{A0C544}kurczak z ziemniakami{FFFFFF}");
			return string;
		}
		else if(itemid == 2)
		{
			format(string, sizeof(string), "{A0C544}kebab z frytkami{FFFFFF}");
			return string;
		}
		else if(itemid == 3)
		{
			format(string, sizeof(string), "{A0C544}pizza z makaronem{FFFFFF}");
			return string;
		}
		else if(itemid == 4)
		{
			format(string, sizeof(string), "{A0C544}pizza WParty{FFFFFF}");
			return string;
		}
		else if(itemid == 5)
		{
			format(string, sizeof(string), "{A0C544}ziemniaki z kotletem{FFFFFF}");
			return string;
		}
		else if(itemid == 6)
		{
			format(string, sizeof(string), "{A0C544}sa³atka owocowa{FFFFFF}");
			return string;
		}
		else if(itemid == 7)
		{
			format(string, sizeof(string), "{A0C544}sa³atka jajeczna z porem{FFFFFF}");
			return string;
		}
		else if(itemid == 8)
		{
			format(string, sizeof(string), "{A0C544}hamburger{FFFFFF}");
			return string;
		}
		else if(itemid == 9)
		{
			format(string, sizeof(string), "{A0C544}cheesburger{FFFFFF}");
			return string;
		}
		else if(itemid == 10)
		{
			format(string, sizeof(string), "{A0C544}lody w kubku{FFFFFF}");
			return string;
		}
		else if(itemid == 11)
		{
			format(string, sizeof(string), "{A0C544}perski kebab{FFFFFF}");
			return string;
		}
		else if(itemid == 12)
		{
			format(string, sizeof(string), "{A0C544}meksykañska tortilla{FFFFFF}");
			return string;
		}
		else if(itemid == 13)
		{
			format(string, sizeof(string), "{A0C544}kawa luwak{FFFFFF}");
			return string;
		}
		else if(itemid == 14)
		{
			format(string, sizeof(string), "{A0C544}schab po kapitañsku{FFFFFF}");
			return string;
		}
		else if(itemid == 15)
		{
			format(string, sizeof(string), "{A0C544}placek mazura{FFFFFF}");
			return string;
		}
		else if(itemid == 16)
		{
			format(string, sizeof(string), "{A0C544}sa³atka z tuñczykiem{FFFFFF}");
			return string;
		}
		else if(itemid == 17)
		{
			format(string, sizeof(string), "{A0C544}lin w œmietanie{FFFFFF}");
			return string;
		}
		else if(itemid == 18)
		{
			format(string, sizeof(string), "{A0C544}kie³basa z grila{FFFFFF}");
			return string;
		}
		else if(itemid == 19)
		{
			format(string, sizeof(string), "{A0C544}zapiekanka z PRL-u{FFFFFF}");
			return string;
		}
		else if(itemid == 20)
		{
			format(string, sizeof(string), "{A0C544}gruszka œnie¿na{FFFFFF}");
			return string;
		}
		else if(itemid == 21)
		{
			format(string, sizeof(string), "{A0C544}kapusta szparagowa{FFFFFF}");
			return string;
		}
		else if(itemid == 22)
		{
			format(string, sizeof(string), "{A0C544}szpinak{FFFFFF}");
			return string;
		}
		else if(itemid == 23)
		{
			format(string, sizeof(string), "{A0C544}EnergyKons{FFFFFF}");
			return string;
		}
	}
	if(itemtype == 6)
	{
		if(itemid == 1)
		{
			format(string, sizeof(string), "{A0C544}Janiec (piwo jasne){FFFFFF}");
			return string;
		}
		else if(itemid == 2)
		{
			format(string, sizeof(string), "{A0C544}Jagutka (piwo ciemne){FFFFFF}");
			return string;
		}
		else if(itemid == 3)
		{
			format(string, sizeof(string), "{A0C544}Denaturat 99%%{FFFFFF}");
			return string;
		}
		else if(itemid == 4)
		{
			format(string, sizeof(string), "{A0C544}Vojtat (wódka 40%%){FFFFFF}");
			return string;
		}
		else if(itemid == 5)
		{
			format(string, sizeof(string), "{A0C544}Czerwony Byk (wino){FFFFFF}");
			return string;
		}
		else if(itemid == 6)
		{
			format(string, sizeof(string), "{A0C544}Jasna Pokrzywa (jabol){FFFFFF}");
			return string;
		}
		else if(itemid == 7)
		{
			format(string, sizeof(string), "{A0C544}Czarna Per³a (rum){FFFFFF}");
			return string;
		}
		else if(itemid == 8)
		{
			format(string, sizeof(string), "{A0C544}Ró¿owa wró¿ka (wódka zio³owa){FFFFFF}");
			return string;
		}
	}
	if(itemtype == 7)
	{
		if(itemid == 1)
		{
			format(string, sizeof(string), "{FFF380}MaxKart akumulator{FFFFFF}"); // najslabszy
			return string;
		}
		if(itemid == 2)
		{
			format(string, sizeof(string), "{FFF380}Boss Light akumulator{FFFFFF}"); // lepszy
			return string;
		}
		if(itemid == 3)
		{
			format(string, sizeof(string), "{FFF380}Boss Hard akumulator{FFFFFF}"); // lepszy
			return string;
		}
		if(itemid == 4)
		{
			format(string, sizeof(string), "{FFF380}Vamta Standart akumulator{FFFFFF}"); // lepszy
			return string;
		}
		if(itemid == 5)
		{
			format(string, sizeof(string), "{FFF380}Titanum Silver akumulator{FFFFFF}"); // lepszy
			return string;
		}
		if(itemid == 6)
		{
			format(string, sizeof(string), "{FFF380}Ultivers Pro akumulator{FFFFFF}"); // najlepszy
			return string;
		}
	}
	if(itemtype == 8)
	{
		if(itemid == 1)
		{
			format(string, sizeof(string), "{FFEC80}Wheel Arch Alien (wydech){FFFFFF}");
			return string;
		}
		if(itemid == 2)
		{
			format(string, sizeof(string), "{FFEC80}Wheel Arch X-Flow (wydech){FFFFFF}");
			return string;
		}
		if(itemid == 3)
		{
			format(string, sizeof(string), "{FFEC80}Locos Low Chrome (wydech){FFFFFF}");
			return string;
		}
		if(itemid == 4)
		{
			format(string, sizeof(string), "{FFEC80}Locos Low Slamin (wydech){FFFFFF}");
			return string;
		}
		if(itemid == 5)
		{
			format(string, sizeof(string), "{FFEC80}Wheel Arch Alien (przedni zderzak){FFFFFF}");
			return string;
		}
		if(itemid == 6)
		{
			format(string, sizeof(string), "{FFEC80}Wheel Arch X-Flow (przedni zderzak){FFFFFF}");
			return string;
		}
		if(itemid == 7)
		{
			format(string, sizeof(string), "{FFEC80}Locos Low Chrome (przedni zderzak){FFFFFF}");
			return string;
		}
		if(itemid == 8)
		{
			format(string, sizeof(string), "{FFEC80}Locos Low Slamin (przedni zderzak){FFFFFF}");
			return string;
		}
		if(itemid == 9)
		{
			format(string, sizeof(string), "{FFEC80}Wheel Arch Alien (tylny zderzak){FFFFFF}");
			return string;
		}
		if(itemid == 10)
		{
			format(string, sizeof(string), "{FFEC80}Wheel Arch X-Flow (tylny zderzak){FFFFFF}");
			return string;
		}
		if(itemid == 11)
		{
			format(string, sizeof(string), "{FFEC80}Locos Low Chrome (tylny zderzak){FFFFFF}");
			return string;
		}
		if(itemid == 12)
		{
			format(string, sizeof(string), "{FFEC80}Locos Low Slamin (tylny zderzak){FFFFFF}");
			return string;
		}
		if(itemid == 13)
		{
			format(string, sizeof(string), "{FFEC80}Wheel Arch Alien (wlot powietrza){FFFFFF}");
			return string;
		}
		if(itemid == 14)
		{
			format(string, sizeof(string), "{FFEC80}Wheel Arch X-Flow (wlot powietrza){FFFFFF}");
			return string;
		}
		if(itemid == 15)
		{
			format(string, sizeof(string), "{FFEC80}Locos Low Hardtop{FFFFFF}");
			return string;
		}
		if(itemid == 16)
		{
			format(string, sizeof(string), "{FFEC80}Locos Low Softtop{FFFFFF}");
			return string;
		}
		if(itemid == 17)
		{
			format(string, sizeof(string), "{FFEC80}Alien Spoiler{FFFFFF}");
			return string;
		}
		if(itemid == 18)
		{
			format(string, sizeof(string), "{FFEC80}X-Flow Spoiler{FFFFFF}");
			return string;
		}
		if(itemid == 19)
		{
			format(string, sizeof(string), "{FFEC80}Wheel Arch Alien (nak³adka progowa){FFFFFF}");
			return string;
		}
		if(itemid == 20)
		{
			format(string, sizeof(string), "{FFEC80}Wheel Arch X-Flow (nak³adka progowa){FFFFFF}");
			return string;
		}
		if(itemid == 21)
		{
			format(string, sizeof(string), "{FFEC80}Locos Low Chrome Flames{FFFFFF}");
			return string;
		}
		if(itemid == 22)
		{
			format(string, sizeof(string), "{FFEC80}Locos Low Chrome Arches{FFFFFF}");
			return string;
		}
		if(itemid == 23)
		{
			format(string, sizeof(string), "{FFEC80}Locos Low Chrome Trim{FFFFFF}");
			return string;
		}
		if(itemid == 24)
		{
			format(string, sizeof(string), "{FFEC80}Locos Low Wheelcovers{FFFFFF}");
			return string;
		}
		if(itemid == 25)
		{
			format(string, sizeof(string), "{FFEC80}Locos Low Chrome Grill{FFFFFF}");
			return string;
		}
		if(itemid == 26)
		{
			format(string, sizeof(string), "{FFEC80}Locos Low Chrome Bars{FFFFFF}");
			return string;
		}
		if(itemid == 27)
		{
			format(string, sizeof(string), "{FFEC80}Locos Low Chrome Lights{FFFFFF}");
			return string;
		}
		if(itemid == 28)
		{
			format(string, sizeof(string), "{FFEC80}Offroad{FFFFFF}");
			return string;
		}
		if(itemid == 29)
		{
			format(string, sizeof(string), "{FFEC80}Mega{FFFFFF}");
			return string;
		}
		if(itemid == 30)
		{
			format(string, sizeof(string), "{FFEC80}Wires{FFFFFF}");
			return string;
		}
		if(itemid == 31)
		{
			format(string, sizeof(string), "{FFEC80}Twist{FFFFFF}");
			return string;
		}
		if(itemid == 32)
		{
			format(string, sizeof(string), "{FFEC80}Grove{FFFFFF}");
			return string;
		}
		if(itemid == 33)
		{
			format(string, sizeof(string), "{FFEC80}Import{FFFFFF}");
			return string;
		}
		if(itemid == 34)
		{
			format(string, sizeof(string), "{FFEC80}Atomic{FFFFFF}");
			return string;
		}
		if(itemid == 35)
		{
			format(string, sizeof(string), "{FFEC80}Ahab{FFFFFF}");
			return string;
		}
		if(itemid == 36)
		{
			format(string, sizeof(string), "{FFEC80}Virtual{FFFFFF}");
			return string;
		}
		if(itemid == 37)
		{
			format(string, sizeof(string), "{FFEC80}Access{FFFFFF}");
			return string;
		}
		if(itemid == 38)
		{
			format(string, sizeof(string), "{FFEC80}Trance{FFFFFF}");
			return string;
		}
		if(itemid == 39)
		{
			format(string, sizeof(string), "{FFEC80}Shadow{FFFFFF}");
			return string;
		}
		if(itemid == 40)
		{
			format(string, sizeof(string), "{FFEC80}Rimshine{FFFFFF}");
			return string;
		}
		if(itemid == 41)
		{
			format(string, sizeof(string), "{FFEC80}Classic{FFFFFF}");
			return string;
		}
		if(itemid == 42)
		{
			format(string, sizeof(string), "{FFEC80}Cutter{FFFFFF}");
			return string;
		}
		if(itemid == 43)
		{
			format(string, sizeof(string), "{FFEC80}Switch{FFFFFF}");
			return string;
		}
		if(itemid == 44)
		{
			format(string, sizeof(string), "{FFEC80}Dollar{FFFFFF}");
			return string;
		}
		if(itemid == 45)
		{
			format(string, sizeof(string), "{FFEC80}Hydraulika{FFFFFF}");
			return string;
		}
		if(itemid == 46)
		{
			format(string, sizeof(string), "{FFEC80}Nitro 2x{FFFFFF}");
			return string;
		}
		if(itemid == 47)
		{
			format(string, sizeof(string), "{FFEC80}Nitro 5x{FFFFFF}");
			return string;
		}
		if(itemid == 48)
		{
			format(string, sizeof(string), "{FFEC80}Nitro 10x{FFFFFF}");
			return string;
		}
		if(itemid == 49)
		{
			format(string, sizeof(string), "{FFEC80}Upswept (wydech){FFFFFF}");
			return string;
		}
		if(itemid == 50)
		{
			format(string, sizeof(string), "{FFEC80}Twin (wydech){FFFFFF}");
			return string;
		}
		if(itemid == 51)
		{
			format(string, sizeof(string), "{FFEC80}Large (wydech){FFFFFF}");
			return string;
		}
		if(itemid == 52)
		{
			format(string, sizeof(string), "{FFEC80}Medium (wydech){FFFFFF}");
			return string;
		}
		if(itemid == 53)
		{
			format(string, sizeof(string), "{FFEC80}Small (wydech){FFFFFF}");
			return string;
		}
		if(itemid == 54)
		{
			format(string, sizeof(string), "{FFEC80}Pro (spoiler){FFFFFF}");
			return string;
		}
		if(itemid == 55)
		{
			format(string, sizeof(string), "{FFEC80}Win (spoiler){FFFFFF}");
			return string;
		}
		if(itemid == 56)
		{
			format(string, sizeof(string), "{FFEC80}Drag (spoiler){FFFFFF}");
			return string;
		}
		if(itemid == 57)
		{
			format(string, sizeof(string), "{FFEC80}Alpha (spoiler){FFFFFF}");
			return string;
		}
		if(itemid == 58)
		{
			format(string, sizeof(string), "{FFEC80}Champ (spoiler){FFFFFF}");
			return string;
		}
		if(itemid == 59)
		{
			format(string, sizeof(string), "{FFEC80}Race (spoiler){FFFFFF}");
			return string;
		}
		if(itemid == 60)
		{
			format(string, sizeof(string), "{FFEC80}Worx (spoiler){FFFFFF}");
			return string;
		}
		if(itemid == 61)
		{
			format(string, sizeof(string), "{FFEC80}Fury (spoiler){FFFFFF}");
			return string;
		}
		if(itemid == 62)
		{
			format(string, sizeof(string), "{FFEC80}Left Oval Vents{FFFFFF}");
			return string;
		}
		if(itemid == 63)
		{
			format(string, sizeof(string), "{FFEC80}Right Oval Vents{FFFFFF}");
			return string;
		}
		if(itemid == 64)
		{
			format(string, sizeof(string), "{FFEC80}Left Square Vents{FFFFFF}");
			return string;
		}
		if(itemid == 65)
		{
			format(string, sizeof(string), "{FFEC80}Right Square Vents{FFFFFF}");
			return string;
		}
		if(itemid == 66)
		{
			format(string, sizeof(string), "{FFEC80}Lamps Round Fog{FFFFFF}");
			return string;
		}
		if(itemid == 67)
		{
			format(string, sizeof(string), "{FFEC80}Lamps Square Fog{FFFFFF}");
			return string;
		}
		if(itemid == 68)
		{
			format(string, sizeof(string), "{FFEC80}Hood Race Scoop{FFFFFF}");
			return string;
		}
		if(itemid == 69)
		{
			format(string, sizeof(string), "{FFEC80}Hood Worx Scoop{FFFFFF}");
			return string;
		}
	}
	if(itemtype == 9)
	{
		if(itemid == 1)
		{
			format(string, sizeof(string), "{FFEC80}Maska - fabryczna{FFFFFF}");
			return string;
		}
		if(itemid == 2)
		{
			format(string, sizeof(string), "{FFEC80}Klapa baga¿nika - fabryczna{FFFFFF}");
			return string;
		}
		if(itemid == 3)
		{
			format(string, sizeof(string), "{FFEC80}Drzwi przednie, lewe - fabryczne{FFFFFF}");
			return string;
		}
		if(itemid == 4)
		{
			format(string, sizeof(string), "{FFEC80}Drzwi przednie, prawe - fabryczne{FFFFFF}");
			return string;
		}
		if(itemid == 5)
		{
			format(string, sizeof(string), "{FFEC80}Zderzak przedni - fabryczny {FFFFFF}");
			return string;
		}
		if(itemid == 6)
		{
			format(string, sizeof(string), "{FFEC80}Zderzak tylny - fabryczny {FFFFFF}");
			return string;
		}
	}
	if(itemtype == 10)
	{
		format(string, sizeof(string), "{E56717}kluczyki do biznesu od id: %d{FFFFFF}", itemid);
		return string;
	}
	if(itemtype == 11)
	{
		format(string, sizeof(string), "{E56717}kluczyki z zestawu (uID %d){FFFFFF}", itemid);
		return string;
	}
	if(itemtype == 0)
	{
		format(string, sizeof(string), "slot pusty{FFFFFF}");
		return string;
	}
	format(string, sizeof(string), "przedmiot nieznanego pochodzenia{FFFFFF}");
	return string;
}

stock ItemWeight(itemtype, itemid)
{
	if(itemtype == 1)
	{
		if(itemid == 1) // ³om
			return 15000;
		if(itemid == 2) // kostka
			return  30;
		if(itemid == 3) // karta kredytowa
			return  20;
		if(itemid == 4) // ksi¹¿ka telefoniczna
			return  500;
		if(itemid == 5) // plecak
			return  700;
		if(itemid == 6) // rakieta
			return 5000;
		if(itemid == 7) // ¿arówka H7
			return  400;
		if(itemid == 8) // zestaw fajerwerków
			return  30000;
		if(itemid == 9) // baton WParty
			return  200;
		if(itemid == 10) // hak holowniczy
			return  4000;
		if(itemid == 11) // alarm
			return  950;
		if(itemid == 12) // cygaro
			return  25;
		if(itemid == 13) // granat
			return 440;
		if(itemid == 14) // gas pieprzowy
			return 50;
		if(itemid == 15) // koktail mo³otowa
			return 150;
		if(itemid == 16) // pistolet 9mm
			return 955;
		if(itemid == 17) // pistolet 9mm z t³umikiem
			return 1055;
		if(itemid == 18) // pistolet Desert Eagle
			return 1700;
		if(itemid == 19) // shotgun
			return 2900;
		if(itemid == 20) // obrzyn
			return 2040;
		if(itemid == 21) // shotgun bojowy
			return 3000;
		if(itemid == 22) // pistolet maszynowy micro SMG
			return 2600;
		if(itemid == 23) // pistolet maszynowy MP5
			return 3080;
		if(itemid == 24) // karabinek AK-47
			return 4050;
		if(itemid == 25) // karabinek M4
			return 3100;
		if(itemid == 26) // tec9
			return 1300;
		if(itemid == 27) // karabin
			return 1500;
		if(itemid == 28) // karabin snajperski
			return 4300;
		if(itemid == 29) // wyrzutnia rakiet
			return 7000;
		if(itemid == 30) // wyrzutnia rakiet z HS
			return 7500;
		if(itemid == 31) // miotacz ognia
			return 1200; 
		if(itemid == 32) // minigun
			return 15000;
		if(itemid == 33) // ³adunek wybuchowy
			return 500;
		if(itemid == 34) // spray
			return 100;
		if(itemid == 35) // gaœnica
			return 1100;
		if(itemid == 36) // nabój 9mm
			return 7;
		if(itemid == 37) // nabój .50 AE
			return 19;
		if(itemid == 38) // œrut
			return 36;
		if(itemid == 39) // nabój 7.62mm
			return 15;
		if(itemid == 40) // nabój 12.7mm
			return 50;
		if(itemid == 41) // KGP 66mm (kumulacyjny pocisk rakietowy)
			return 50;
		if(itemid == 42) // napalm
			return 0;
		if(itemid == 43) // pocisk pistol
			return 0;
		if(itemid == 44) // ³uska pistol
			return 0;
		if(itemid == 45) // proch pistol
			return 0;
		if(itemid == 46) // sp³onka pistol
			return 0;
		if(itemid == 47) // o³ów
			return 0;
		if(itemid == 48) // szkielet broni
			return 240;
		if(itemid == 49) // zespó³ zamka
			return 180;
		if(itemid == 50) // magazynke
			return 120;
		if(itemid == 51) // sprê¿yna powrotna
			return 25;
		if(itemid == 52) // komplet œrubek
			return 10;
		if(itemid == 53) // szkielet broni karabinowej
			return 1000;
		if(itemid == 54) // zespó³ zamka karabinu
			return 800;
		if(itemid == 55) // magazynek karabinu
			return 300;
		if(itemid == 56) // sprê¿yna powrotna karabinu
			return 40;
		if(itemid == 57) // kolba
			return 200;
		if(itemid == 58) // komplet œrubek karabinu
			return 10;
		if(itemid == 59) // t³umik
			return 0;
		if(itemid == 60) // luneta
			return 500;
		if(itemid == 61) // lufa
			return 120;
		if(itemid == 62) // mechanizm spustowo-uderzeniowy
			return 60;
		if(itemid == 63) // nak³adki z tworzywa sztucznego
			return 60;
		if(itemid == 64) // mechanizm iglicy
			return 115;
		if(itemid == 65) // bezpiecznik typu listkowego
			return 60;
		if(itemid == 66) // przyrz¹dy celownicze
			return 40;
		if(itemid == 67) // szkielet
			return 55;
		if(itemid == 68) // stopka
			return 25;
		if(itemid == 69) // wew. sprê¿yna
			return 25;
		if(itemid == 70) // dosy³acz
			return 35;
		if(itemid == 71) // lufa karabinu
			return 400;
		if(itemid == 72) // mechanizm spustowo-uderzeniowy karabinu
			return 300;
		if(itemid == 73) // mechanizm iglicy karabinu
			return 350;
		if(itemid == 74) // bezpiecznik typu listkowego karabinu
			return 250;
		if(itemid == 75) // przyrz¹dy celownicze karabinu
			return 200;
		if(itemid == 76) // szkielet karabinu
			return 90;
		if(itemid == 77) // stopka karabinu
			return 70;
		if(itemid == 78) // wew. sprê¿yna karabinu
			return 40;
		if(itemid == 79) // dosy³acz karabinu
			return 100;
		if(itemid == 80) // szkielet lunety
			return 250;
		if(itemid == 81) // soczewki
			return 250;
		if(itemid == 82) // zestaw monta¿owy Tec9
			return 10;
		if(itemid == 83) // skrzynka monta¿owa MP5
			return 730;
		if(itemid == 84) // zestaw monta¿owy AK-47
			return 610;
		if(itemid == 85) // skrzynka monta¿owa M4
			return 200;
		if(itemid == 86) // rêkojeœæ prze³adowania
			return 870;
		if(itemid == 87) // carbon
			return 80;
		if(itemid == 88) // skrzynka monta¿owa karabinu
			return 300;
		if(itemid == 89) // siatka maskuj¹ca
			return 100;
		if(itemid == 90) // luska strzelb
			return 10;
		if(itemid == 91) // proch 5gr
			return 5;
		if(itemid == 92) // splonka strzelb
			return 1;
		if(itemid == 93) // pocisk karab
			return 7;
		if(itemid == 94) // luska karab
			return 3;
		if(itemid == 95) // proch 3gr
			return 3;
		if(itemid == 96) // splonka karab
			return 2;
		if(itemid == 97) // pocisk snajp
			return 25;
		if(itemid == 98) // luska snajp
			return 10;
		if(itemid == 99) // proch 10gr
			return 10;
		if(itemid == 100) // splonka snajp
			return 5;
		if(itemid == 101) // pocisk .50AE
			return 9;
		if(itemid == 102) // luska .50AE
			return 5;
		if(itemid == 103) //  proch 2gr
			return 2;
		if(itemid == 104) // splonka .50AE
			return 2;
		if(itemid == 105) // mapa
			return 5;
		if(itemid == 106) // radioodiornik
			return 1200;
		if(itemid == 107) //  zegarek
			return 100;
		if(itemid == 108) //  zegarek
			return 100;
		if(itemid == 109) // zegarek
			return 100;
		if(itemid == 110) //   zegarek
			return 100;
		if(itemid == 111) //  zegarek
			return 100;
		if(itemid == 112) //  zegarek
			return 100;
		if(itemid == 113) //  zegarek
			return 100;	
		if(itemid == 114) //  zegarek
			return 100;
		if(itemid == 115) //  zegarek
			return 100;
		if(itemid == 116) // zegarek
			return 100;
		if(itemid == 117) //   zegarek
			return 100;
		if(itemid == 118) //  zegarek
			return 100;
		if(itemid == 119) //  zegarek
			return 100;
		if(itemid == 120) //  zegarek
			return 100;	
		if(itemid == 121) //  zegarek
			return 100;		
		if(itemid == 122) //  samochodowy komputer pidi
			return 3000;	
		if(itemid == 123) // CB radio c  
			return 2000;
		if(itemid == 124) // CB radio SE
			return 2500;
		if(itemid == 125) // cola WParty  
			return 500;
		if(itemid == 126) // woda mine  
			return 500;
		if(itemid == 127) // woda zrpd  
			return 500;
		if(itemid == 128) // baton  
			return 60;
		if(itemid == 129) // czekolada 
			return 100;
		if(itemid == 130) //  jablko
			return 150;
		if(itemid == 131) // marchewka  
			return 100;
		if(itemid == 132) //  mandarynka
			return 80;
		if(itemid == 133) // mleko  
			return 1000;
		if(itemid == 134) //atat  
			return 100;
		if(itemid == 135) // 2kace 
			return 100;
		if(itemid == 136) // pigulka cud 
			return 1;
		if(itemid == 137) // krople zoladkowe 
			return 100;
		if(itemid == 138) // multivit  
			return 100;	
		if(itemid == 139) // untoxin 
			return 100;	
		if(itemid == 140) // powerbuild  
			return 100;
		if(itemid == 141) //  outoff
			return 100;
		if(itemid == 142) //  lewatyks
			return 100;	
		if(itemid == 143) //  zestaw do wyrabiania kluczy
			return 2000;
		if(itemid == 144) // zuzyte doladowanie karty sim
			return 10;
		if(itemid == 145) // palka 
			return 1000;	
		if(itemid == 146) // kij bilardowy 
			return 500;
		if(itemid == 147) // kastet 
			return 300;
		if(itemid == 148) // noz 
			return 400;	
		if(itemid == 149) // lopata 
			return 1000;
		if(itemid == 150) // laska
			return 1500;
		if(itemid == 151) // zestaw do monitoringu 
			return 5000;
		if(itemid == 152) // swiatla policujne listwa
			return 2000;
		if(itemid == 153) // swiatlo pidi pojedyncze
			return 500;	
		if(itemid == 173)
			return 50;
		if(itemid == 174)
			return 5000;	
		if(itemid == 175)
			return 20000;	
		if(itemid == 176)
			return 2000;	
		if(itemid == 177)
			return 15000;	
		if(itemid == 178)
			return 1000;	
	}
	if(itemtype == 2)
	{
		return  45;
	}
	if(itemtype == 3)
	{
		if(itemid == 1)
		{
			return 22000;
		}
		if(itemid == 2)
		{
			return 600;
		}
		if(itemid == 3)
		{
			return 300;
		}
		if(itemid == 4)
		{
			return 350;
		}
		if(itemid == 5)
		{
			return 20;
		}
		if(itemid == 6)
		{
			return 20;
		}
		if(itemid == 7)
		{
			return 50;
		}
		if(itemid == 8)
		{
			return 1500;
		}
		if(itemid == 9) // czapka
		{
			return 500;
		}
		if(itemid == 10) // kupon
		{
			return 10;
		}
		if(itemid == 11) // dokument ukonczenia prawka
		{
			return 50;
		}
		if(itemid == 12) // gps
		{
			return 1000;
		}
		if(itemid == 13) // krotkofalowka se
		{
			return 1000;
		}
		if(itemid == 14) // chusta
		{
			return 100;
		}
		if(itemid == 15) // zamek do dzwi
		{
			return 1100;
		}
		if(itemid == 16) // karta sim
		{
			return 10;
		}
		if(itemid == 17) // doladowanie karty
		{
			return 10;
		}
		if(itemid == 18) // legitymacja wordu
		{
			return 100;
		}
		if(itemid == 19) // dowod reje samo
		{
			return 100;
		}
		if(itemid == 20) // lom
		{
			return 1500;
		}
		if(itemid == 21) // wytrych
		{
			return 100;
		}
		if(itemid == 22) // pancerz
		{
			return 2500;
		}
		if(itemid == 23) // ciezki pancerz
		{
			return 5000;
		}
		if(itemid == 21) // ubranie
		{
			return 100;
		}
		
	}
	if(itemtype == 4)
	{
		return  50;
	}
	
	if(itemtype == 5)
	{
		if(itemid == 1)
		{
			return 500;
		}
		if(itemid == 2)
		{
			return 500;
		}
		if(itemid == 3)
		{
			return 1000;
		}
		if(itemid == 4)
		{
			return 1500;
		}
		if(itemid == 5)
		{
			return 1000;
		}
		if(itemid == 6)
		{
			return 300;
		}
		if(itemid == 7)
		{
			return 300;
		}
		if(itemid == 8)
		{
			return 500;
		}
		if(itemid == 9)
		{
			return 500;
		}
		if(itemid == 10) 
		{
			return 200;
		}
		if(itemid == 11) 
		{
			return 300;
		}
		if(itemid == 12) 
		{
			return 300;
		}
		if(itemid == 13) 
		{
			return 100;
		}
		if(itemid == 14)
		{
			return 400;
		}
		if(itemid == 15) 
		{
			return 300;
		}
		if(itemid == 16) 
		{
			return 300;
		}
		if(itemid == 17) 
		{
			return 200;
		}
		if(itemid == 18) 
		{
			return  500;
		}
		if(itemid == 19) 
		{
			return 150;
		}
		if(itemid == 20) 
		{
			return 100;
		}
		if(itemid == 21) 
		{
			return 200;
		}
		if(itemid == 22) 
		{
			return 100;
		}
		if(itemid == 23) 
		{
			return 100;
		}
	}
	if(itemtype == 6)
	{
		if(itemid == 1)
		{
			return 500;
		}
		if(itemid == 2)
		{
			return 500;
		}
		if(itemid == 3)
		{
			return 500;
		}
		if(itemid == 4)
		{
			return 750;
		}
		if(itemid == 5)
		{
			return 500;
		}
		if(itemid == 6)
		{
			return 500;
		}
		if(itemid == 7)
		{
			return 500;
		}
		if(itemid == 8)
		{
			return 500;
		}
	}
	if(itemtype == 7)
	{
		if(itemid == 1)
		{
			return 5000;
		}
		if(itemid == 2)
		{
			return 5000;
		}
		if(itemid == 3)
		{
			return 5000;
		}
		if(itemid == 4)
		{
			return 5000;
		}
		if(itemid == 5)
		{
			return 5000;
		}
		if(itemid == 6)
		{
			return 5000;
		}	
	}
	if(itemtype == 8)
	{
		if(itemid == 1)
		{
			return 10000;
		}
		if(itemid == 2)
		{
			return 10000;
		}
		if(itemid == 3)
		{
			return 10000;
		}
		if(itemid == 4)
		{
			return 10000;
		}
		if(itemid == 5)
		{
			return 5000;
		}
		if(itemid == 6)
		{
			return 5000;
		}
		if(itemid == 7)
		{
			return 5000;
		}
		if(itemid == 8)
		{
			return 5000;
		}
		if(itemid == 9)
		{
			return 5000;
		}
		if(itemid == 10) 
		{
			return 5000;
		}
		if(itemid == 11) 
		{
			return 5000;
		}
		if(itemid == 12) 
		{
			return 5000;
		}
		if(itemid == 13) 
		{
			return 1000;
		}
		if(itemid == 14)
		{
			return 1000;
		}
		if(itemid == 15) 
		{
			return 1000;
		}
		if(itemid == 16) 
		{
			return 1000;
		}
		if(itemid == 17) 
		{
			return 1000;
		}
		if(itemid == 18) 
		{
			return 1000;
		}
		if(itemid == 19) 
		{
			return 700;
		}
		if(itemid == 20) 
		{
			return 700;
		}
		if(itemid == 21) 
		{
			return 1000;
		}
		if(itemid == 22) 
		{
			return 1000;
		}
		if(itemid == 23) 
		{
			return 1000;
		}
		if(itemid == 24) 
		{
			return 1000;
		}
		if(itemid == 25) 
		{
			return 1000;
		}
		if(itemid == 26) 
		{
			return 1000;
		}
		if(itemid == 27) 
		{
			return 1000;
		}
		if(itemid == 28) 
		{
			return 20000;
		}
		if(itemid == 29) 
		{
			return 20000;
		}
		if(itemid == 30) 
		{
			return 20000;
		}
		if(itemid == 31) 
		{
			return 20000;
		}
		if(itemid == 32) 
		{
			return 20000;
		}
		if(itemid == 33) 
		{
			return 20000;
		}
		if(itemid == 34) 
		{
			return 20000;
		}
		if(itemid == 35) 
		{
			return 20000;
		}
		if(itemid == 36) 
		{
			return 20000;
		}
		if(itemid == 37) 
		{
			return 20000;
		}
		if(itemid == 38) 
		{
			return 20000;
		}
		if(itemid == 39) 
		{
			return 20000;
		}
		if(itemid == 40) 
		{
			return 20000;
		}
		if(itemid == 41) 
		{
			return 20000;
		}
		if(itemid == 42) 
		{
			return 20000;
		}
		if(itemid == 43) 
		{
			return 20000;
		}
		if(itemid == 44) 
		{
			return 20000;
		}
		if(itemid == 45) 
		{
			return 10000;
		}
		if(itemid == 46) 
		{
			return 1000;
		}
		if(itemid == 47) 
		{
			return 2000;
		}
		if(itemid == 48) 
		{
			return 10000;
		}
		if(itemid == 49) 
		{
			return 10000;
		}
		if(itemid == 50) 
		{
			return 10000;
		}
		if(itemid == 51) 
		{
			return 10000;
		}
		if(itemid == 52) 
		{
			return 10000;
		}
		if(itemid == 53) 
		{
			return 10000;
		}
		if(itemid == 54) 
		{
			return 1000;
		}
		if(itemid == 55) 
		{
			return 1000;
		}
		if(itemid == 56) 
		{
			return 1000;
		}
		if(itemid == 57) 
		{
			return 1000;
		}
		if(itemid == 58) 
		{
			return 1000;
		}
		if(itemid == 59) 
		{
			return 1000;
		}
		if(itemid == 60) 
		{
			return 1000;
		}
		if(itemid == 61) 
		{
			return 1000;
		}
		if(itemid == 62) 
		{
			return 500;
		}
		if(itemid == 63) 
		{
			return 500;
		}
		if(itemid == 64) 
		{
			return 500;
		}
		if(itemid == 65) 
		{
			return 500;
		}
		if(itemid == 66) 
		{
			return 1000;
		}
		if(itemid == 67) 
		{
			return 1000;
		}
		if(itemid == 68) 
		{
			return 500;
		}
		if(itemid == 69) 
		{
			return 500;
		}
	}	
	if(itemtype == 9)
	{
		if(itemid == 1)
		{
			return 5000;
		}
		if(itemid == 2)
		{
			return 5000;
		}
		if(itemid == 3)
		{
			return 5000;
		}
		if(itemid == 4)
		{
			return 5000;
		}
		if(itemid == 5)
		{
			return 5000;
		}
		if(itemid == 6)
		{
			return 5000;
		}	
	}
	return 0;
}

stock InsertItemToFactory( fID, itemid, value = 1 )
{
	switch( itemid )
	{
		case 43: 
		{
			DynamicFactions[fID][WFactoryAmmoPart1a] += value;
			SaveFData( fID, "WFactoryAmmoPart1a" );
		}
		case 44: 
		{
			DynamicFactions[fID][WFactoryAmmoPart2a] += value;
			SaveFData( fID, "WFactoryAmmoPart2a" );
		}
		case 45: 
		{
			DynamicFactions[fID][WFactoryAmmoPart3a] += value;
			SaveFData( fID, "WFactoryAmmoPart3a" );
		}
		case 46: 
		{
			DynamicFactions[fID][WFactoryAmmoPart4a] += value;
			SaveFData( fID, "WFactoryAmmoPart4a" );
		}
		case 47: 
		{
			DynamicFactions[fID][WFactoryAmmoPart1b] += value;
			SaveFData( fID, "WFactoryAmmoPart1b" );
		}
		case 48: 
		{
			DynamicFactions[fID][WFactoryPistolPart1] += value;
			SaveFData( fID, "WFactoryPistolPart1" );
		}
		case 49: 
		{
			DynamicFactions[fID][WFactoryPistolPart2] += value;
			SaveFData( fID, "WFactoryPistolPart2" );
		}
		case 50: 
		{
			DynamicFactions[fID][WFactoryPistolPart3] += value;
			SaveFData( fID, "WFactoryPistolPart3" );
		}
		case 51: 
		{
			DynamicFactions[fID][WFactoryPistolPart4] += value;
			SaveFData( fID, "WFactoryPistolPart4" );
		}
		case 52: 
		{
			DynamicFactions[fID][WFactoryPistolPart5] += value;
			SaveFData( fID, "WFactoryPistolPart5" );
		}
		case 53: 
		{
			DynamicFactions[fID][WFactoryRiflePart1] += value;
			SaveFData( fID, "WFactoryRiflePart1" );
		}
		case 54: 
		{
			DynamicFactions[fID][WFactoryRiflePart2] += value;
			SaveFData( fID, "WFactoryRiflePart2" );
		}
		case 55: 
		{
			DynamicFactions[fID][WFactoryRiflePart3] += value;
			SaveFData( fID, "WFactoryRiflePart3" );
		}
		case 56: 
		{
			DynamicFactions[fID][WFactoryRiflePart4] += value;
			SaveFData( fID, "WFactoryRiflePart4" );
		}
		case 57: 
		{
			DynamicFactions[fID][WFactoryRiflePart5] += value;
			SaveFData( fID, "WFactoryRiflePart5" );
		}
		case 58: 
		{
			DynamicFactions[fID][WFactoryRiflePart6] += value;
			SaveFData( fID, "WFactoryRiflePart6" );
		}
		case 59: 
		{
			DynamicFactions[fID][WFactoryPistolPart6] += value;
			SaveFData( fID, "WFactoryPistolPart6" );
		}
		case 60: 
		{
			DynamicFactions[fID][WFactoryRiflePart7] += value;
			SaveFData( fID, "WFactoryRiflePart7" );
		}
		case 61: 
		{
			DynamicFactions[fID][WFactoryPistolS1Part1] += value;
			SaveFData( fID, "WFactoryPistolS1Part1" );
		}
		case 62: 
		{
			DynamicFactions[fID][WFactoryPistolS1Part2] += value;
			SaveFData( fID, "WFactoryPistolS1Part2" );
		}
		case 63: 
		{
			DynamicFactions[fID][WFactoryPistolS1Part3] += value;
			SaveFData( fID, "WFactoryPistolS1Part3" );
		}
		case 64: 
		{
			DynamicFactions[fID][WFactoryPistolS2Part1] += value;
			SaveFData( fID, "WFactoryPistolS2Part1" );
		}
		case 65: 
		{
			DynamicFactions[fID][WFactoryPistolS2Part2] += value;
			SaveFData( fID, "WFactoryPistolS2Part2" );
		}
		case 66: 
		{
			DynamicFactions[fID][WFactoryPistolS2Part3] += value;
			SaveFData( fID, "WFactoryPistolS2Part3" );
		}
		case 67: 
		{
			DynamicFactions[fID][WFactoryPistolS3Part1] += value;
			SaveFData( fID, "WFactoryPistolS3Part1" );
		}
		case 68: 
		{
			DynamicFactions[fID][WFactoryPistolS3Part2] += value;
			SaveFData( fID, "WFactoryPistolS3Part2" );
		}
		case 69: 
		{
			DynamicFactions[fID][WFactoryPistolS3Part3] += value;
			SaveFData( fID, "WFactoryPistolS3Part3" );
		}
		case 70: 
		{
			DynamicFactions[fID][WFactoryPistolS3Part4] += value;
			SaveFData( fID, "WFactoryPistolS3Part4" );
		}
		case 71: 
		{
			DynamicFactions[fID][WFactoryRifleS1Part1] += value;
			SaveFData( fID, "WFactoryRifleS1Part1" );
		}
		case 72: 
		{
			DynamicFactions[fID][WFactoryRifleS1Part2] += value;
			SaveFData( fID, "WFactoryRifleS1Part2" );
		}
		case 73: 
		{
			DynamicFactions[fID][WFactoryRifleS2Part1] += value;
			SaveFData( fID, "WFactoryRifleS2Part1" );
		}
		case 74: 
		{
			DynamicFactions[fID][WFactoryRifleS2Part2] += value;
			SaveFData( fID, "WFactoryRifleS2Part2" );
		}
		case 75: 
		{
			DynamicFactions[fID][WFactoryRifleS2Part3] += value;
			SaveFData( fID, "WFactoryRifleS2Part3" );
		}
		case 76: 
		{
			DynamicFactions[fID][WFactoryRifleS3Part1] += value;
			SaveFData( fID, "WFactoryRifleS3Part1" );
		}
		case 77: 
		{
			DynamicFactions[fID][WFactoryRifleS3Part2] += value;
			SaveFData( fID, "WFactoryRifleS3Part2" );
		}
		case 78: 
		{
			DynamicFactions[fID][WFactoryRifleS3Part3] += value;
			SaveFData( fID, "WFactoryRifleS3Part3" );
		}
		case 79: 
		{
			DynamicFactions[fID][WFactoryRifleS3Part4] += value;
			SaveFData( fID, "WFactoryRifleS3Part4" );
		}
		case 80: 
		{
			DynamicFactions[fID][WFactoryRifleS6Part1] += value;
			SaveFData( fID, "WFactoryRifleS6Part1" );
		}
		case 81: 
		{
			DynamicFactions[fID][WFactoryRifleS6Part2] += value;
			SaveFData( fID, "WFactoryRifleS6Part2" );
		}
		case 82: 
		{
			DynamicFactions[fID][WFactoryTec9Part] += value;
			SaveFData( fID, "WFactoryTec9Part" );
		}
		case 83: 
		{
			DynamicFactions[fID][WFactoryMP5Part] += value;
			SaveFData( fID, "WFactoryMP5Part" );
		}
		case 84: 
		{
			DynamicFactions[fID][WFactoryAK47Part] += value;
			SaveFData( fID, "WFactoryAK47Part" );
		}
		case 85: 
		{
			DynamicFactions[fID][WFactoryM4Part] += value;
			SaveFData( fID, "WFactoryM4Part" );
		}
		case 86: 
		{
			DynamicFactions[fID][WFactoryShotPart] += value;
			SaveFData( fID, "WFactoryShotPart" );
		}
		case 87: 
		{
			DynamicFactions[fID][WFactoryDesEaglePart] += value;
			SaveFData( fID, "WFactoryDesEaglePart" );
		}
		case 88: 
		{
			DynamicFactions[fID][WFactoryRiflePart] += value;
			SaveFData( fID, "WFactoryRiflePart" );
		}
		case 89: 
		{
			DynamicFactions[fID][WFactorySniperPart] += value;
			SaveFData( fID, "WFactorySniperPart" );
		}
		case 90: 
		{
			DynamicFactions[fID][WFactoryAmmoPart2b] += value;
			SaveFData( fID, "WFactoryAmmoPart2b" );
		}
		case 91: 
		{
			DynamicFactions[fID][WFactoryAmmoPart3b] += value;
			SaveFData( fID, "WFactoryAmmoPart3b" );
		}
		case 92: 
		{
			DynamicFactions[fID][WFactoryAmmoPart4b] += value;
			SaveFData( fID, "WFactoryAmmoPart4b" );
		}
		case 93: 
		{
			DynamicFactions[fID][WFactoryAmmoPart1c] += value;
			SaveFData( fID, "WFactoryAmmoPart1c" );
		}
		case 94: 
		{
			DynamicFactions[fID][WFactoryAmmoPart2c] += value;
			SaveFData( fID, "WFactoryAmmoPart2c" );
		}
		case 95: 
		{
			DynamicFactions[fID][WFactoryAmmoPart3c] += value;
			SaveFData( fID, "WFactoryAmmoPart3c" );
		}
		case 96: 
		{
			DynamicFactions[fID][WFactoryAmmoPart4c] += value;
			SaveFData( fID, "WFactoryAmmoPart4c" );
		}
		case 97: 
		{
			DynamicFactions[fID][WFactoryAmmoPart1d] += value;
			SaveFData( fID, "WFactoryAmmoPart1d" );
		}
		case 98: 
		{
			DynamicFactions[fID][WFactoryAmmoPart2d] += value;
			SaveFData( fID, "WFactoryAmmoPart2d" );
		}
		case 99: 
		{
			DynamicFactions[fID][WFactoryAmmoPart3d] += value;
			SaveFData( fID, "WFactoryAmmoPart3d" );
		}
		case 100: 
		{
			DynamicFactions[fID][WFactoryAmmoPart4d] += value;
			SaveFData( fID, "WFactoryAmmoPart4d" );
		}
		case 101: 
		{
			DynamicFactions[fID][WFactoryAmmoPart1e] += value;
			SaveFData( fID, "WFactoryAmmoPart1e" );
		}
		case 102: 
		{
			DynamicFactions[fID][WFactoryAmmoPart2e] += value;
			SaveFData( fID, "WFactoryAmmoPart2e" );
		}
		case 103: 
		{
			DynamicFactions[fID][WFactoryAmmoPart3e] += value;
			SaveFData( fID, "WFactoryAmmoPart3e" );
		}
		case 104: 
		{
			DynamicFactions[fID][WFactoryAmmoPart4e] += value;
			SaveFData( fID, "WFactoryAmmoPart4e" );
		}
	}
}

stock ComponentToItem(playerid, component)
{
	switch(component)
	{
		case 1000: InsertPlayerItemEx(playerid, 8, 54, 0, 0, 0, 0, "Puste", 1);
		case 1001: InsertPlayerItemEx(playerid, 8, 55, 0, 0, 0, 0, "Puste", 1);
		case 1002: InsertPlayerItemEx(playerid, 8, 56, 0, 0, 0, 0, "Puste", 1);
		case 1003: InsertPlayerItemEx(playerid, 8, 57, 0, 0, 0, 0, "Puste", 1);
		case 1008: InsertPlayerItemEx(playerid, 8, 47, 0, 0, 0, 0, "Puste", 1);
		case 1009: InsertPlayerItemEx(playerid, 8, 46, 0, 0, 0, 0, "Puste", 1);
		case 1010: InsertPlayerItemEx(playerid, 8, 48, 0, 0, 0, 0, "Puste", 1);
		case 1011: InsertPlayerItemEx(playerid, 8, 68, 0, 0, 0, 0, "Puste", 1);
		case 1012: InsertPlayerItemEx(playerid, 8, 69, 0, 0, 0, 0, "Puste", 1);
		case 1013: InsertPlayerItemEx(playerid, 8, 66, 0, 0, 0, 0, "Puste", 1);
		case 1014: InsertPlayerItemEx(playerid, 8, 58, 0, 0, 0, 0, "Puste", 1);
		case 1015: InsertPlayerItemEx(playerid, 8, 59, 0, 0, 0, 0, "Puste", 1);
		case 1016: InsertPlayerItemEx(playerid, 8, 60, 0, 0, 0, 0, "Puste", 1);
		case 1018: InsertPlayerItemEx(playerid, 8, 49, 0, 0, 0, 0, "Puste", 1);
		case 1019: InsertPlayerItemEx(playerid, 8, 50, 0, 0, 0, 0, "Puste", 1);
		case 1020: InsertPlayerItemEx(playerid, 8, 51, 0, 0, 0, 0, "Puste", 1);
		case 1021: InsertPlayerItemEx(playerid, 8, 52, 0, 0, 0, 0, "Puste", 1);
		case 1022: InsertPlayerItemEx(playerid, 8, 53, 0, 0, 0, 0, "Puste", 1);
		case 1023: InsertPlayerItemEx(playerid, 8, 61, 0, 0, 0, 0, "Puste", 1);
		case 1024: InsertPlayerItemEx(playerid, 8, 67, 0, 0, 0, 0, "Puste", 1);
		case 1025: InsertPlayerItemEx(playerid, 8, 28, 0, 0, 0, 0, "Puste", 1);
		case 1026: InsertPlayerItemEx(playerid, 8, 19, 0, 0, 0, 0, "Puste", 1);
		case 1028: InsertPlayerItemEx(playerid, 8, 1, 0, 0, 0, 0, "Puste", 1);
		case 1029: InsertPlayerItemEx(playerid, 8, 2, 0, 0, 0, 0, "Puste", 1);
		case 1031: InsertPlayerItemEx(playerid, 8, 20, 0, 0, 0, 0, "Puste", 1);
		case 1032: InsertPlayerItemEx(playerid, 8, 14, 0, 0, 0, 0, "Puste", 1);
		case 1033: InsertPlayerItemEx(playerid, 8, 13, 0, 0, 0, 0, "Puste", 1);
		case 1034: InsertPlayerItemEx(playerid, 8, 1, 0, 0, 0, 0, "Puste", 1);
		case 1035: InsertPlayerItemEx(playerid, 8, 13, 0, 0, 0, 0, "Puste", 1);
		case 1036: InsertPlayerItemEx(playerid, 8, 19, 0, 0, 0, 0, "Puste", 1);
		case 1037: InsertPlayerItemEx(playerid, 8, 2, 0, 0, 0, 0, "Puste", 1);
		case 1038: InsertPlayerItemEx(playerid, 8, 14, 0, 0, 0, 0, "Puste", 1);
		case 1039: InsertPlayerItemEx(playerid, 8, 18, 0, 0, 0, 0, "Puste", 1);
		case 1041: InsertPlayerItemEx(playerid, 8, 20, 0, 0, 0, 0, "Puste", 1);
		case 1043: InsertPlayerItemEx(playerid, 8, 4, 0, 0, 0, 0, "Puste", 1);
		case 1044: InsertPlayerItemEx(playerid, 8, 3, 0, 0, 0, 0, "Puste", 1);
		case 1045: InsertPlayerItemEx(playerid, 8, 2, 0, 0, 0, 0, "Puste", 1);
		case 1046: InsertPlayerItemEx(playerid, 8, 1, 0, 0, 0, 0, "Puste", 1);
		case 1047: InsertPlayerItemEx(playerid, 8, 19, 0, 0, 0, 0, "Puste", 1);
		case 1048: InsertPlayerItemEx(playerid, 8, 20, 0, 0, 0, 0, "Puste", 1);
		case 1049: InsertPlayerItemEx(playerid, 8, 17, 0, 0, 0, 0, "Puste", 1);
		case 1050: InsertPlayerItemEx(playerid, 8, 18, 0, 0, 0, 0, "Puste", 1);
		case 1053: InsertPlayerItemEx(playerid, 8, 13, 0, 0, 0, 0, "Puste", 1);
		case 1054: InsertPlayerItemEx(playerid, 8, 14, 0, 0, 0, 0, "Puste", 1);
		case 1056: InsertPlayerItemEx(playerid, 8, 19, 0, 0, 0, 0, "Puste", 1);
		case 1057: InsertPlayerItemEx(playerid, 8, 20, 0, 0, 0, 0, "Puste", 1);
		case 1058: InsertPlayerItemEx(playerid, 8, 17, 0, 0, 0, 0, "Puste", 1);
		case 1059: InsertPlayerItemEx(playerid, 8, 2, 0, 0, 0, 0, "Puste", 1);
		case 1060: InsertPlayerItemEx(playerid, 8, 18, 0, 0, 0, 0, "Puste", 1);
		case 1061: InsertPlayerItemEx(playerid, 8, 13, 0, 0, 0, 0, "Puste", 1);
		case 1064: InsertPlayerItemEx(playerid, 8, 1, 0, 0, 0, 0, "Puste", 1);
		case 1065: InsertPlayerItemEx(playerid, 8, 1, 0, 0, 0, 0, "Puste", 1);
		case 1066: InsertPlayerItemEx(playerid, 8, 2, 0, 0, 0, 0, "Puste", 1);
		case 1067: InsertPlayerItemEx(playerid, 8, 14, 0, 0, 0, 0, "Puste", 1);
		case 1068: InsertPlayerItemEx(playerid, 8, 13, 0, 0, 0, 0, "Puste", 1);
		case 1069: InsertPlayerItemEx(playerid, 8, 19, 0, 0, 0, 0, "Puste", 1);
		case 1070: InsertPlayerItemEx(playerid, 8, 20, 0, 0, 0, 0, "Puste", 1);
		case 1073: InsertPlayerItemEx(playerid, 8, 39, 0, 0, 0, 0, "Puste", 1);
		case 1074: InsertPlayerItemEx(playerid, 8, 29, 0, 0, 0, 0, "Puste", 1);
		case 1075: InsertPlayerItemEx(playerid, 8, 40, 0, 0, 0, 0, "Puste", 1);
		case 1076: InsertPlayerItemEx(playerid, 8, 30, 0, 0, 0, 0, "Puste", 1);
		case 1077: InsertPlayerItemEx(playerid, 8, 41, 0, 0, 0, 0, "Puste", 1);
		case 1078: InsertPlayerItemEx(playerid, 8, 31, 0, 0, 0, 0, "Puste", 1);
		case 1079: InsertPlayerItemEx(playerid, 8, 42, 0, 0, 0, 0, "Puste", 1);
		case 1080: InsertPlayerItemEx(playerid, 8, 43, 0, 0, 0, 0, "Puste", 1);
		case 1081: InsertPlayerItemEx(playerid, 8, 32, 0, 0, 0, 0, "Puste", 1);
		case 1082: InsertPlayerItemEx(playerid, 8, 33, 0, 0, 0, 0, "Puste", 1);
		case 1083: InsertPlayerItemEx(playerid, 8, 44, 0, 0, 0, 0, "Puste", 1);
		case 1084: InsertPlayerItemEx(playerid, 8, 38, 0, 0, 0, 0, "Puste", 1);
		case 1085: InsertPlayerItemEx(playerid, 8, 34, 0, 0, 0, 0, "Puste", 1);
		case 1087: InsertPlayerItemEx(playerid, 8, 45, 0, 0, 0, 0, "Puste", 1);
		case 1088: InsertPlayerItemEx(playerid, 8, 14, 0, 0, 0, 0, "Puste", 1);
		case 1089: InsertPlayerItemEx(playerid, 8, 2, 0, 0, 0, 0, "Puste", 1);
		case 1090: InsertPlayerItemEx(playerid, 8, 19, 0, 0, 0, 0, "Puste", 1);
		case 1091: InsertPlayerItemEx(playerid, 8, 13, 0, 0, 0, 0, "Puste", 1);
		case 1092: InsertPlayerItemEx(playerid, 8, 1, 0, 0, 0, 0, "Puste", 1);
		case 1093: InsertPlayerItemEx(playerid, 8, 20, 0, 0, 0, 0, "Puste", 1);
		case 1096: InsertPlayerItemEx(playerid, 8, 35, 0, 0, 0, 0, "Puste", 1);
		case 1097: InsertPlayerItemEx(playerid, 8, 36, 0, 0, 0, 0, "Puste", 1);
		case 1098: InsertPlayerItemEx(playerid, 8, 37, 0, 0, 0, 0, "Puste", 1);
		case 1100: InsertPlayerItemEx(playerid, 8, 25, 0, 0, 0, 0, "Puste", 1);
		case 1104: InsertPlayerItemEx(playerid, 8, 3, 0, 0, 0, 0, "Puste", 1);
		case 1105: InsertPlayerItemEx(playerid, 8, 4, 0, 0, 0, 0, "Puste", 1);
		case 1106: InsertPlayerItemEx(playerid, 8, 22, 0, 0, 0, 0, "Puste", 1);
		case 1113: InsertPlayerItemEx(playerid, 8, 3, 0, 0, 0, 0, "Puste", 1);
		case 1114: InsertPlayerItemEx(playerid, 8, 4, 0, 0, 0, 0, "Puste", 1);
		case 1116: InsertPlayerItemEx(playerid, 8, 7, 0, 0, 0, 0, "Puste", 1);
		case 1118: InsertPlayerItemEx(playerid, 8, 23, 0, 0, 0, 0, "Puste", 1);
		case 1119: InsertPlayerItemEx(playerid, 8, 24, 0, 0, 0, 0, "Puste", 1);
		case 1122: InsertPlayerItemEx(playerid, 8, 21, 0, 0, 0, 0, "Puste", 1);
		case 1123: InsertPlayerItemEx(playerid, 8, 26, 0, 0, 0, 0, "Puste", 1);
		case 1125: InsertPlayerItemEx(playerid, 8, 27, 0, 0, 0, 0, "Puste", 1);
		case 1126: InsertPlayerItemEx(playerid, 8, 3, 0, 0, 0, 0, "Puste", 1);
		case 1127: InsertPlayerItemEx(playerid, 8, 4, 0, 0, 0, 0, "Puste", 1);
		case 1128: InsertPlayerItemEx(playerid, 8, 15, 0, 0, 0, 0, "Puste", 1);
		case 1129: InsertPlayerItemEx(playerid, 8, 3, 0, 0, 0, 0, "Puste", 1);
		case 1130: InsertPlayerItemEx(playerid, 8, 15, 0, 0, 0, 0, "Puste", 1);
		case 1131: InsertPlayerItemEx(playerid, 8, 16, 0, 0, 0, 0, "Puste", 1);
		case 1132: InsertPlayerItemEx(playerid, 8, 4, 0, 0, 0, 0, "Puste", 1);
		case 1135: InsertPlayerItemEx(playerid, 8, 4, 0, 0, 0, 0, "Puste", 1);
		case 1136: InsertPlayerItemEx(playerid, 8, 3, 0, 0, 0, 0, "Puste", 1);
		case 1137: InsertPlayerItemEx(playerid, 8, 4, 0, 0, 0, 0, "Puste", 1);		
		case 1138: InsertPlayerItemEx(playerid, 8, 17, 0, 0, 0, 0, "Puste", 1);		
		case 1140: InsertPlayerItemEx(playerid, 8, 10, 0, 0, 0, 0, "Puste", 1);
		case 1141: InsertPlayerItemEx(playerid, 8, 9, 0, 0, 0, 0, "Puste", 1);
		case 1142: InsertPlayerItemEx(playerid, 8, 62, 0, 0, 0, 0, "Puste", 1);
		case 1143: InsertPlayerItemEx(playerid, 8, 63, 0, 0, 0, 0, "Puste", 1);
		case 1144: InsertPlayerItemEx(playerid, 8, 64, 0, 0, 0, 0, "Puste", 1);
		case 1145: InsertPlayerItemEx(playerid, 8, 65, 0, 0, 0, 0, "Puste", 1);
		case 1147: InsertPlayerItemEx(playerid, 8, 17, 0, 0, 0, 0, "Puste", 1);
		case 1146: InsertPlayerItemEx(playerid, 8, 18, 0, 0, 0, 0, "Puste", 1);
		case 1148: InsertPlayerItemEx(playerid, 8, 10, 0, 0, 0, 0, "Puste", 1);
		case 1149: InsertPlayerItemEx(playerid, 8, 9, 0, 0, 0, 0, "Puste", 1);
		case 1150: InsertPlayerItemEx(playerid, 8, 9, 0, 0, 0, 0, "Puste", 1);
		case 1151: InsertPlayerItemEx(playerid, 8, 10, 0, 0, 0, 0, "Puste", 1);
		case 1152: InsertPlayerItemEx(playerid, 8, 6, 0, 0, 0, 0, "Puste", 1);
		case 1153: InsertPlayerItemEx(playerid, 8, 5, 0, 0, 0, 0, "Puste", 1);
		case 1154: InsertPlayerItemEx(playerid, 8, 9, 0, 0, 0, 0, "Puste", 1);
		case 1155: InsertPlayerItemEx(playerid, 8, 5, 0, 0, 0, 0, "Puste", 1);
		case 1156: InsertPlayerItemEx(playerid, 8, 10, 0, 0, 0, 0, "Puste", 1);
		case 1157: InsertPlayerItemEx(playerid, 8, 6, 0, 0, 0, 0, "Puste", 1);
		case 1158: InsertPlayerItemEx(playerid, 8, 18, 0, 0, 0, 0, "Puste", 1);
		case 1162: InsertPlayerItemEx(playerid, 8, 17, 0, 0, 0, 0, "Puste", 1);
		case 1163: InsertPlayerItemEx(playerid, 8, 18, 0, 0, 0, 0, "Puste", 1);
		case 1164: InsertPlayerItemEx(playerid, 8, 17, 0, 0, 0, 0, "Puste", 1);
		case 1165: InsertPlayerItemEx(playerid, 8, 6, 0, 0, 0, 0, "Puste", 1);
		case 1166: InsertPlayerItemEx(playerid, 8, 5, 0, 0, 0, 0, "Puste", 1);
		case 1167: InsertPlayerItemEx(playerid, 8, 10, 0, 0, 0, 0, "Puste", 1);
		case 1168: InsertPlayerItemEx(playerid, 8, 9, 0, 0, 0, 0, "Puste", 1);
		case 1169: InsertPlayerItemEx(playerid, 8, 5, 0, 0, 0, 0, "Puste", 1);
		case 1170: InsertPlayerItemEx(playerid, 8, 6, 0, 0, 0, 0, "Puste", 1);
		case 1171: InsertPlayerItemEx(playerid, 8, 5, 0, 0, 0, 0, "Puste", 1);
		case 1172: InsertPlayerItemEx(playerid, 8, 6, 0, 0, 0, 0, "Puste", 1);
		case 1174: InsertPlayerItemEx(playerid, 8, 7, 0, 0, 0, 0, "Puste", 1);
		case 1175: InsertPlayerItemEx(playerid, 8, 8, 0, 0, 0, 0, "Puste", 1);
		case 1176: InsertPlayerItemEx(playerid, 8, 11, 0, 0, 0, 0, "Puste", 1);
		case 1177: InsertPlayerItemEx(playerid, 8, 12, 0, 0, 0, 0, "Puste", 1);
		case 1178: InsertPlayerItemEx(playerid, 8, 12, 0, 0, 0, 0, "Puste", 1);
		case 1179: InsertPlayerItemEx(playerid, 8, 7, 0, 0, 0, 0, "Puste", 1);
		case 1180: InsertPlayerItemEx(playerid, 8, 11, 0, 0, 0, 0, "Puste", 1);
		case 1181: InsertPlayerItemEx(playerid, 8, 8, 0, 0, 0, 0, "Puste", 1);
		case 1182: InsertPlayerItemEx(playerid, 8, 7, 0, 0, 0, 0, "Puste", 1);
		case 1183: InsertPlayerItemEx(playerid, 8, 12, 0, 0, 0, 0, "Puste", 1);
		case 1184: InsertPlayerItemEx(playerid, 8, 11, 0, 0, 0, 0, "Puste", 1);
		case 1185: InsertPlayerItemEx(playerid, 8, 8, 0, 0, 0, 0, "Puste", 1);
		case 1186: InsertPlayerItemEx(playerid, 8, 12, 0, 0, 0, 0, "Puste", 1);
		case 1187: InsertPlayerItemEx(playerid, 8, 11, 0, 0, 0, 0, "Puste", 1);
		case 1188: InsertPlayerItemEx(playerid, 8, 8, 0, 0, 0, 0, "Puste", 1);
		case 1189: InsertPlayerItemEx(playerid, 8, 7, 0, 0, 0, 0, "Puste", 1);
		case 1190: InsertPlayerItemEx(playerid, 8, 8, 0, 0, 0, 0, "Puste", 1);
		case 1191: InsertPlayerItemEx(playerid, 8, 7, 0, 0, 0, 0, "Puste", 1);
		case 1192: InsertPlayerItemEx(playerid, 8, 11, 0, 0, 0, 0, "Puste", 1);
		case 1193: InsertPlayerItemEx(playerid, 8, 12, 0, 0, 0, 0, "Puste", 1);
	}
}

stock ObjectModelToItemInsert(playerid, model)
{
	switch(model)
	{
		case 18647: InsertPlayerItemEx(playerid, 1, 167, 0, 0, 0, 0, "Puste", 1);
		case 18648: InsertPlayerItemEx(playerid, 1, 168, 0, 0, 0, 0, "Puste", 1);
		case 18649: InsertPlayerItemEx(playerid, 1, 169, 0, 0, 0, 0, "Puste", 1);
		case 18650: InsertPlayerItemEx(playerid, 1, 170, 0, 0, 0, 0, "Puste", 1);
		case 18651: InsertPlayerItemEx(playerid, 1, 171, 0, 0, 0, 0, "Puste", 1);
		case 18652: InsertPlayerItemEx(playerid, 1, 172, 0, 0, 0, 0, "Puste", 1);
		case 19308:	InsertPlayerItemEx(playerid, 1, 154, 0, 0, 0, 0, "Puste", 1);
		case 19309:	InsertPlayerItemEx(playerid, 1, 155, 0, 0, 0, 0, "Puste", 1);
		case 19310:	InsertPlayerItemEx(playerid, 1, 156, 0, 0, 0, 0, "Puste", 1);
		case 19311:	InsertPlayerItemEx(playerid, 1, 157, 0, 0, 0, 0, "Puste", 1);
		case 19280:	InsertPlayerItemEx(playerid, 1, 158, 0, 0, 0, 0, "Puste", 1);
		case 19281:	InsertPlayerItemEx(playerid, 1, 159, 0, 0, 0, 0, "Puste", 1);
		case 19282:	InsertPlayerItemEx(playerid, 1, 160, 0, 0, 0, 0, "Puste", 1);
		case 19283:	InsertPlayerItemEx(playerid, 1, 161, 0, 0, 0, 0, "Puste", 1);
		case 19284:	InsertPlayerItemEx(playerid, 1, 162, 0, 0, 0, 0, "Puste", 1);
	}
	return 1;
}

stock ItemToWeapon(itemId)
{
	switch(itemId)
	{
		case 13: return 16;
		case 14: return 17;
		case 15: return 18;
		case 16: return 22;
		case 17: return 23;
		case 18: return 24;
		case 19: return 25;
		case 20: return 26;
		case 21: return 27;
		case 22: return 28;
		case 23: return 29;
		case 24: return 30;
		case 25: return 31;
		case 26: return 32;
		case 27: return 33;
		case 28: return 34;
		case 29: return 35;
		case 30: return 36;
		case 31: return 37;
		case 32: return 38;
		case 33: return 39;
		case 34: return 41;
		case 35: return 42;
	}
	return 0;
}

stock RemoveItemFromAll(itemType, itemId, param1 = -999, param2 = -999, param3 = -999, param4 = -999, param5[] = "")
{
	new slot, slotId, string[64];

	gSearchItemType = itemType;
	gSearchItemId = itemId;
	gSearchItemParam1 = param1;
	gSearchItemParam2 = param2;
	gSearchItemParam3 = param3;
	gSearchItemParam4 = param4;
	format(gSearchItemParam5, 64, param5);

	for(new i = 0; i < CUSTOM_MAX_PLAYERS; i++)
	{
		if(!gPlayerLogged[i])
		{
			continue;
		}

		for(new pSlotId = 0; pSlotId < MAX_PLAYER_ITEM_SLOT; pSlotId++)
		{
			slot = PHaveItem(i, itemType, itemId, pSlotId);

			if(param1 != -999)
			{
				if(SlotParam1(i, slotId) != param1)
				{
					continue;
				}
			}
				
			if(param2 != -999)
			{
				if(SlotParam2(i, slotId) != param2)
				{
					continue;
				}
			}
			
			if(param3 != -999)
			{
				if(SlotParam3(i, slotId) != param3)
				{
					continue;
				}
			}
			
			if(param4 != -999)
			{	
				if(SlotParam4(i, slotId) != param4)
				{
					continue;
				}
			}
			
			if(strcmp(gDSelectedItemP5[i], "", false) != 0)
			{
				SlotParam5(i, slotId);
				
				if(strcmp(gDSelectedItemP5[i], param5, false) != 0)
				{
					continue;
				}
			}

			RemovePlayerItemUsed(i, slotId);

		}
	}

	// Load players from db and check
	
	format(string, sizeof(string), "SELECT HIGH_PRIORITY * FROM `samp_users_items`");
	wp_mysql_query(string, LOAD_ITEMS_FOR_DELETE, CUSTOM_MAX_PLAYERS, db_con2);

	for(new i = 0; i < sizeof(Houses); i++)
	{

		houseBegin:
		slot = HHaveItem(i, itemType, itemId);
		
		if(slot == 0)
		{
			continue;
		}
		
		if(param1 != -999)
		{
			if(HSlotParam1(i, slot) != param1)
			{
				continue;
			}
		}
		
		if(param2 != -999)
		{
			if(HSlotParam2(i, slot) != param2)
			{
				continue;
			}
		}
		
		if(param3 != -999)
		{
			if(HSlotParam3(i, slot) != param3)
			{
				continue;
			}
		}
		
		if(param4 != -999)
		{
			if(HSlotParam4(i, slot) != param4)
			{
				continue;
			}
		}
		
		HSlotParam5(i, slot);
		if(strlen(param5) > 0)
		{
			if(strcmp(gHSelectedItemP5[i], param5, false) == 0 && strlen(gHSelectedItemP5[i]) > 0)
			{
				continue;
			}
		}

		RemoveHouseItem(i, slot);

		goto houseBegin;
	}

	for(new i = 0; i < sizeof(gVehData); i++)
	{
		for(new pSlotId = 0; pSlotId < MAX_VEHICLE_ITEM_SLOT; pSlotId++)
		{
			slot = VHaveItem(i+1, itemType, itemId, pSlotId);
			
			if(slot == 0)
			{
				continue;
			}

			if(param1 != -999)
			{
				if(VSlotParam1(i, slotId) != param1)
				{
					continue;
				}
			}

			if(param2 != -999)
			{
				if(VSlotParam2(i, slotId) != param2)
				{
					continue;
				}
			}

			if(param3 != -999)
			{
				if(VSlotParam3(i, slotId) != param3)
				{
					continue;
				}
			}

			if(param4 != -999)
			{	
				if(VSlotParam4(i, slotId) != param4)
				{
					continue;
				}
			}

			if(strlen(param5) != 0)
			{
				VSlotParam5(i, slotId);
				
				if(strcmp(gVSelectedItemP5[i], param5, false) != 0)
				{
					continue;
				}
			}

			RemoveVehItem(i, slotId);
		}
	}

}

// Thats all