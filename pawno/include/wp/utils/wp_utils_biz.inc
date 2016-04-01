/***
*
* File: wp_utils_biz.inc
* Auth: Damian Wojdat
* Date: 28.05.2012
* Desc: Internal script function related to businesses.
*
*************************************************************************************************************/

stock RefreshBizDescription(bizId)
{
	if(Business3DTextLabelA[bizId])
		DestroyDynamic3DTextLabel(Business3DTextLabelA[bizId]);
	if(Business3DTextLabelB[bizId])
		DestroyDynamic3DTextLabel(Business3DTextLabelB[bizId]);
	if(Business3DTextLabelC[bizId])
		DestroyDynamic3DTextLabel(Business3DTextLabelC[bizId]);
	new businesstype[64], string[128];
	if(Businesses[bizId][BizType] != 0)
	{
		if(Businesses[bizId][BizType] == 1) { businesstype = "Restauracja"; }
		else if(Businesses[bizId][BizType] == 2) { businesstype = "Siec komorkowa"; }
		else if(Businesses[bizId][BizType] == 3) { businesstype = "Sklep 24/7"; }
		else if(Businesses[bizId][BizType] == 4) { businesstype = "Sklep z bronia"; }
		else if(Businesses[bizId][BizType] == 5) { businesstype = "Studio reklamowe"; }
		else if(Businesses[bizId][BizType] == 6) { businesstype = "Sklep z ubraniami"; }
		else if(Businesses[bizId][BizType] == 7) { businesstype = "Bar/Club"; }
		else if(Businesses[bizId][BizType] == 8) { businesstype = "Studio nagraniowe"; }
		else if(Businesses[bizId][BizType] == 9) { businesstype = "Studio"; }
		else if(Businesses[bizId][BizType] == 10) { businesstype = "Salon samochodowy"; }
		else if(Businesses[bizId][BizType] == 11) { businesstype = "Stacja paliw"; }
	}
	else { businesstype = "Nie ustawione"; }
	
	if(Businesses[bizId][Owned] == 0)
	{
		if( Businesses[bizId][EnterX] != 0.0 || Businesses[bizId][EnterY] != 0.0 )
			Businesses[bizId][PickupID] = CreateDynamicPickup(1272, 1, Businesses[bizId][EnterX], Businesses[bizId][EnterY], Businesses[bizId][EnterZ]);

		format(string, sizeof(string), "Ten biznes jest na sprzeda¿!");
		Business3DTextLabelA[bizId] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE2, Businesses[bizId][EnterX], Businesses[bizId][EnterY], Businesses[bizId][EnterZ]+1.0, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

		format(string, sizeof(string), "Numer Budynku: %d, Nazwa biznesu: %s, Typ biznesu: %s", bizId, Businesses[bizId][BusinessName],businesstype);
		Business3DTextLabelB[bizId] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE2, Businesses[bizId][EnterX], Businesses[bizId][EnterY], Businesses[bizId][EnterZ]+0.5, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

		format(string, sizeof(string), "Cena: %d$", Businesses[bizId][BizPrice]);
		Business3DTextLabelC[bizId] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE2, Businesses[bizId][EnterX], Businesses[bizId][EnterY], Businesses[bizId][EnterZ], 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
	}
	else if(Businesses[bizId][Owned] == 1)
	{
		if( Businesses[bizId][EnterX] != 0.0 || Businesses[bizId][EnterY] != 0.0 )
			Businesses[bizId][PickupID] = CreateDynamicPickup(1239, 1, Businesses[bizId][EnterX], Businesses[bizId][EnterY], Businesses[bizId][EnterZ]);

		format(string, sizeof(string), "Nazwa biznesu: %s, Typ biznesu: %s", Businesses[bizId][BusinessName],businesstype);
		Business3DTextLabelA[bizId] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE2, Businesses[bizId][EnterX], Businesses[bizId][EnterY], Businesses[bizId][EnterZ]+1.0, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

		format(string, sizeof(string), "Numer Budynku: %d, W³aœciciel: %s", bizId, GetRealName(Businesses[bizId][Owner]));
		Business3DTextLabelB[bizId] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE2, Businesses[bizId][EnterX], Businesses[bizId][EnterY], Businesses[bizId][EnterZ]+0.5, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

		format(string, sizeof(string), "Wejœciówka: %d$",Businesses[bizId][EntranceCost]);
		Business3DTextLabelC[bizId] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE2, Businesses[bizId][EnterX], Businesses[bizId][EnterY], Businesses[bizId][EnterZ], 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
	}
}