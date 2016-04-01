/***
*
* File: wp_utils_shop_view.inc
* Auth: Damian Wojdat
* Date: 4.04.2012
* Desc: Internal script function related to shop gui.
*
*************************************************************************************************************/

stock ShowShopMenu(playerid)
{
	static string[2048];
	strdel(string, 0, sizeof(string));
	switch(Businesses[gBuyBusinessID[playerid]][BizType])
	{
		case BIZT_GAS:
		{
			format( string, sizeof( string ), "1. Produkty\n2. Zap³aæ za paliwo" );
			ShowPlayerDialog(playerid,DIALOG_BUY_1,DIALOG_STYLE_LIST,"Stacja paliw",
			string,
			"Kup","WyjdŸ");
		}
		case BIZT_PHONE:
		{
			if(Businesses[gBuyBusinessID[playerid]][mFaction] == 255)
			{
				if(strcmp(gPlayerData[playerid][pName], Businesses[gBuyBusinessID[playerid]][Owner], false) != 0)
				{				
					ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "W³aœciciel biznesu nie podpisa³ umowy z ¿adn¹ sieci¹ przez co nie jest mo¿liwe podpisanie nowej umowy na karte/abonament.", "Zamknij", "");
				}
				else 
				{
					format(string, sizeof(string), "Twój biznes jest obecnie nieaktywny.\nAby umo¿liwiæ jego funkcjonowanie nale¿y podpisaæ umowe z jedn¹ z sieci komórkowych.\n");
					format(string, sizeof(string), "%sW³aœciciele sieci komórkowy oferuj¹ w zamian za udostêpnienie biznesu odpowiedni¹ wartoœci zysku ze sprzeda¿y oraz po³¹czeñ\n", string);
					format(string, sizeof(string), "%sKliknij dalej aby zobaczyæ liste dostêpnych sieci", string);
					ShowPlayerDialog(playerid, DIALOG_SELECT_PHONE_COMPANY, DIALOG_STYLE_MSGBOX, "Informacja", string, "Dalej", "Zamknij");
				}
			}
			else if(DynamicFactions[Businesses[gBuyBusinessID[playerid]][mFaction]][fType] != FACTIONT_COMPANY_PHONE)
			{
				if(strcmp(gPlayerData[playerid][pName], Businesses[gBuyBusinessID[playerid]][Owner], false) != 0)
				{
					ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "W³aœciciel biznesu nie podpisa³ umowy z ¿adn¹ sieci¹ przez co nie jest mo¿liwe podpisanie nowej umowy na karte/abonament.", "Zamknij", "");
				}
				else
				{
					format(string, sizeof(string), "Twój biznes jest obecnie nieaktywny.\nAby umo¿liwiæ jego funkcjonowanie nale¿y podpisaæ umowe z jedn¹ z sieci komórkowych.\n");
					format(string, sizeof(string), "%sW³aœciciele sieci komórkowy oferuj¹ w zamian za udostêpnienie biznesu odpowiedni¹ wartoœci zysku ze sprzeda¿y oraz po³¹czeñ\n", string);
					format(string, sizeof(string), "%sKliknij dalej aby zobaczyæ liste dostêpnych sieci", string);
					ShowPlayerDialog(playerid, DIALOG_SELECT_PHONE_COMPANY, DIALOG_STYLE_MSGBOX, "Informacja", string, "Dalej", "Zamknij");
				}
			}
			else
			{
				format(string, sizeof(string), "1. Oferta na abonament\n2. Oferta na karte\n3. Wyrób now¹ karte SIM\n4. Zrezygnuj z abonamentu\n5. Kup karte do³adowywuj¹c¹\n");
				if(strcmp(Businesses[gBuyBusinessID[playerid]][Owner], gPlayerData[playerid][pName], false) == 0 ||
					(Businesses[gBuyBusinessID[playerid]][BGov] && gPlayerData[playerid][pFaction] == FACTIONID_GOVERNMENT))
					format(string, sizeof(string), "%s6. Rozwi¹¿ umowe", string);
				ShowPlayerDialog(playerid, DIALOG_BUY_SIM, DIALOG_STYLE_LIST, "Sieæ", string, "Kup karte", "Zamknij");
			}
		}
		case BIZT_WEAPONS:
		{
			format( string, sizeof(string), "1.Broñ\n2.Amunicja" );
			ShowPlayerDialog( playerid, DIALOG_BUYW_1, DIALOG_STYLE_LIST, "Sklep z broni¹", string, "Wybierz", "WyjdŸ");
		}
		case BIZT_CLOTHES:
		{
			format( string, sizeof( string), "1.Ubrania\n2. Okulary\n3. Czapki" );
			ShowPlayerDialog( playerid, DIALOG_CBUY_1, DIALOG_STYLE_LIST, "Sklep z ubraniami", string, "Wybierz", "WyjdŸ" );
		}
		case BIZT_EATING:
		{
			format(string, sizeof(string), FOOD_PRODUCT_LIST,
				ItemName(Businesses[gBuyBusinessID[playerid]][Product1type], Businesses[gBuyBusinessID[playerid]][Product1]),
				Businesses[gBuyBusinessID[playerid]][Product1price],
				Businesses[gBuyBusinessID[playerid]][Product1count],
				ItemName(Businesses[gBuyBusinessID[playerid]][Product2type], Businesses[gBuyBusinessID[playerid]][Product2]),
				Businesses[gBuyBusinessID[playerid]][Product2price],
				Businesses[gBuyBusinessID[playerid]][Product2count],
				ItemName(Businesses[gBuyBusinessID[playerid]][Product3type], Businesses[gBuyBusinessID[playerid]][Product3]),
				Businesses[gBuyBusinessID[playerid]][Product3price],
				Businesses[gBuyBusinessID[playerid]][Product3count],
				ItemName(Businesses[gBuyBusinessID[playerid]][Product4type], Businesses[gBuyBusinessID[playerid]][Product4]),
				Businesses[gBuyBusinessID[playerid]][Product4price],
				Businesses[gBuyBusinessID[playerid]][Product4count],
				ItemName(Businesses[gBuyBusinessID[playerid]][Product5type], Businesses[gBuyBusinessID[playerid]][Product5]),
				Businesses[gBuyBusinessID[playerid]][Product5price],
				Businesses[gBuyBusinessID[playerid]][Product5count]
			);
			if(strcmp(gPlayerData[playerid][pName], Businesses[gBuyBusinessID[playerid]][Owner], false) == 0)
				ShowPlayerDialog(playerid, DIALOG_FBUY_1, DIALOG_STYLE_LIST, "Restauracja", string, "Wybierz", "Zamknij");
			else
				ShowPlayerDialog(playerid, DIALOG_FBUY_1, DIALOG_STYLE_LIST, "Restauracja", string, "Jedz/pij", "Zamknij");			
		}
		default:
		{
			format(string, sizeof( string ), "1. Produkty");
			ShowPlayerDialog(playerid,DIALOG_BUY_1,DIALOG_STYLE_LIST,"Sklep 24/7", string, "Kup","WyjdŸ");
		}
	}
}