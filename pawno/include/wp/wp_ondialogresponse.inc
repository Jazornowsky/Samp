 /***
* wp_ondialogresponse.inc - Contain OnDialogResponse function.
*
*							Made by Damian Wojdat
*
*Last modified:
*						21-09-2011
*
*************************************************************************************************************/

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	new string[1024];
	new string2[512];
	new string3[256];
	
	switch(dialogid)
	{
		// case DIALOG_MAKE_OBJECT:
		// {
			// if(response)
			// {
				// new Float: objX, Float: objY, Float:objZ;
				// GetPlayerPos( playerid, objX, objY, objZ );
				// switch( listitem )
				// {
					// case 0:
					// {
						// if( CountPlayerObjects( playerid ) >= gPlayerData[playerid][pVipCustomObjects] )
						// {
							// format( string, sizeof(string), "Osi¹gn¹³eœ limit wykupionych slotów (%d) na obiekty", gPlayerData[playerid][pVipCustomObjects] );
							// ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Limit slotów", string, "Zamknij", " " );
							// return 1;
						// }
						// CreateCustomObject( playerid, 1010110 /* some model */, objX, objY, objZ );
					// }
				// }
			// }
		// }
		case DIALOG_LAWYER_1:
		{
			if(response)
			{
				new giveplayerid = gLawyerOffer[playerid][playerOffering];
				new Float:time, roundedjailtime;
				roundedjailtime = floatround( gPlayerData[playerid][pJailTime]/3600, floatround_round );
				if( roundedjailtime >= 0 && roundedjailtime <= 1 )
					time = 0.0;
				else if( roundedjailtime > 1 && roundedjailtime <= 2 )
					time = 0.1;
				else if( roundedjailtime > 2 && roundedjailtime <= 12 )
					time = 0.2;
				else if( roundedjailtime > 12 && roundedjailtime <= 24 )
					time = 0.5;
				else if( roundedjailtime > 24 )
					time = 0.8;
				new Float:addchance;
				if( gPlayerData[giveplayerid][pDoktor] )
					addchance += 0.1;
				if( gPlayerData[giveplayerid][pMagister] )
					addchance += 0.05;
				new Float:chance = 0.006*float(gPlayerData[giveplayerid][pAng])+0.006*float(gPlayerData[giveplayerid][pPol])+0.006*float(gPlayerData[giveplayerid][pMat])+0.006*float(gPlayerData[giveplayerid][pHis])+0.2*float(gPlayerData[giveplayerid][pLevel])-time+addchance;
				if( chance < 0 )
					chance = 0.0;
				if( ( gPlayerData[playerid][pBank] >= ( gLawyerOffer[playerid][offerCost] + gLawyerOffer[playerid][govCost] ) ) || ( gPlayerData[playerid][pCash] >= ( gLawyerOffer[playerid][offerCost] + gLawyerOffer[playerid][govCost] ) ) )
				{
					gPlayerData[playerid][pBank] -= gLawyerOffer[playerid][offerCost] + gLawyerOffer[playerid][govCost];
					gPlayerData[ gLawyerOffer[playerid][playerOffering] ][pBank] += gLawyerOffer[playerid][offerCost];
					SavePlayerData( playerid, "Bank" );
					SavePlayerData( gLawyerOffer[playerid][playerOffering], "Bank" );
					new rand = random(100)+1;
					new chanced = floatround( chance*100, floatround_round);
					printf(" chanced is %d", chanced);
					if( rand < chanced )
					{
						gPlayerData[playerid][pJailed] = 0;
						SavePlayerData(playerid, "Jailed");

						if(!PlayerToPoint(8.0, playerid, 268.0, 77.0, 1001.0))
						{
							SetPlayerToPos(playerid,-302.0,1504.0, 76.5);
							SetPlayerInterior(playerid, 0);
							SetPlayerVirtualWorld(playerid,0);

							gPlayerData[playerid][pCrashInt] = 0;
							gPlayerData[playerid][pCrashW] = 0;
						}
						else
							SetPlayerToPos(playerid,268.0,77.0, 1001.0);

						if( gPlayerData[playerid][pDuty] && DynamicFactions[ gLawyerOffer[playerid][playerOffering] ][fUseSkins] )
							SetPlayerToFactionSkin(playerid);
						else
							SetPlayerSkin(playerid,gPlayerData[playerid][pSkin]);
						
						GetPlayerPos(playerid,gPlayerData[playerid][pCrashX],gPlayerData[playerid][pCrashY],gPlayerData[playerid][pCrashZ]);

						SavePlayerData(playerid, "Crash");

						TogglePlayerControllable(playerid, 0);
						unfreezeTPPlayer(playerid);

						SendClientMessage(playerid, COLOR_LIGHTYELLOW2,"[INFO:] Zosta³eœ rozgrzeszony i wypuszczony.");
						
						gPlayerData[ gLawyerOffer[playerid][playerOffering] ][pLawyerPts]++;
						if( gPlayerData[ gLawyerOffer[playerid][playerOffering] ][pLawyerPts] >= 3*gPlayerData[ gLawyerOffer[playerid][playerOffering] ][pLawyerLvl]^2+5*gPlayerData[ gLawyerOffer[playerid][playerOffering] ][pLawyerLvl]+10 )
						{
							gPlayerData[ gLawyerOffer[playerid][playerOffering] ][pLawyerLvl]++;
							gPlayerData[ gLawyerOffer[playerid][playerOffering] ][pLawyerPts] = 0;
							SavePlayerData( gLawyerOffer[playerid][playerOffering], "LawyerLvl" );
							SavePlayerData( gLawyerOffer[playerid][playerOffering], "LawyerPts" );
						}
						format(string, sizeof(string), "[INFO:] Osi¹gna³eœ nowy poziom pracy prawnika ! - %d", gPlayerData[ gLawyerOffer[playerid][playerOffering] ][pLawyerLvl]);
						SendClientMessage( gLawyerOffer[playerid][playerOffering], COLOR_LIGHTYELLOW2, string ); 
						return 1;
					}
					else
					{
						ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Oferta prawnika", "Nie uda³o siê prawnikowi wygraæ sprawy. Zostajesz w pace !", "Zamknij", "" );
						return 1;
					}
				}
				else
				{
					ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Oferta prawnika", "Niestety nie posiadasz wy¿ej wymienionej kwoty.", "Zamknij", "" );
					return 1;
				}
			}
		}
		case DIALOG_REFUEL_VEH:
		{
		}
		case DIALOG_RAF_RSC_CP_MAIN:
		{
			if(response)
			{
				new vehID = GetPlayerVehicleID(playerid);
				/* No truck */
				if( vehID == INVALID_VEHICLE_ID )
				{
					ShowPlayerDialog(playerid, 
													DIALOG_RAF_RSC_CP_INFO_A, 
													DIALOG_STYLE_MSGBOX, 
													RAF_RSC_CP_MENU_HEADER, 
													RAF_RSC_CP_MENU_INV_VEHID, 
													RAF_RSC_CP_MENU_EXIT, 
													"" );
					return 1;
				}
				/* Not a faction truck */
				if( gVehData[vehID-1][FactionCar] != FACTIONID_RAFINERY )
				{
					ShowPlayerDialog(playerid,
													DIALOG_RAF_RSC_CP_INFO_A,
													DIALOG_STYLE_MSGBOX,
													RAF_RSC_CP_MENU_HEADER,
													RAF_RSC_CP_MENU_INV_VEHFAC,
													RAF_RSC_CP_MENU_EXIT,
													"" );
					return 1;
				}
				new tlID = GetVehicleTrailer(vehID);
				/* Truck has no attached tanker */
				if( tlID == 0 )
				{
					ShowPlayerDialog(playerid,
													DIALOG_RAF_RSC_CP_INFO_A,
													DIALOG_STYLE_MSGBOX,
													RAF_RSC_CP_MENU_HEADER,
													RAF_RSC_CP_MENU_INV_TLID,
													RAF_RSC_CP_MENU_EXIT,
													"");
					return 1;
				}
				/* Not a faction tanker */
				if( gVehData[tlID-1][FactionCar] != FACTIONID_RAFINERY )
				{
					ShowPlayerDialog(playerid,
													DIALOG_RAF_RSC_CP_INFO_A,
													DIALOG_STYLE_MSGBOX,
													RAF_RSC_CP_MENU_HEADER,
													RAF_RSC_CP_MENU_INV_TLFAC,
													RAF_RSC_CP_MENU_EXIT,
													"" );
					return 1;
				}
				/* Refuel petrol */
				if( listitem == 0 )
				{
					/* Tanker is already filled with other type of fuel */
					if( gVehData[tlID-1][TankerResourceType] != TANKER_TYPE_PETROL && gVehData[tlID-1][TankerResourceType] != TANKER_TYPE_NONE )
					{
						ShowPlayerDialog(playerid,
														DIALOG_RAF_RSC_CP_INFO_B,
														DIALOG_STYLE_MSGBOX,
														RAF_RSC_CP_MENU_HEADER,
														RAF_RSC_CP_MENU_INV_TYPE,
														RAF_RSC_CP_MENU_BACK,
														"" );
						return 1;
					}
					/* Tanker is already refueling */
					if( gVehData[tlID-1][TankerIsRefueling] )
					{
						ShowPlayerDialog(playerid,
														DIALOG_RAF_RSC_CP_INFO_A,
														DIALOG_STYLE_MSGBOX,
														RAF_RSC_CP_MENU_HEADER,
														RAF_RSC_CP_MENU_AREFUELING,
														RAF_RSC_CP_MENU_EXIT,
														"" );
						return 1;
					}
					/* Tanker is already full */
					if( gVehData[tlID-1][TankerResourceValue] >= MAX_TANKER_RESOURCE_VALUE )
					{
						ShowPlayerDialog(playerid,
														DIALOG_RAF_RSC_CP_INFO_A,
														DIALOG_STYLE_MSGBOX,
														RAF_RSC_CP_MENU_HEADER,
														RAF_RSC_CP_MENU_AMAX,
														RAF_RSC_CP_MENU_EXIT,
														"" );
						return 1;
					}
					/* No rafinery resource */
					if( gRafinery[RafResourcePetrol] <= 0 )
					{
						ShowPlayerDialog(playerid,
														DIALOG_RAF_RSC_CP_INFO_A,
														DIALOG_STYLE_MSGBOX,
														RAF_RSC_CP_MENU_HEADER,
														RAF_RSC_CP_MENU_REFUELED_B,
														RAF_RSC_CP_MENU_EXIT,
														"" );
						return 1;
					}
					new Float:tX, Float:tY, Float:tZ;
					GetPlayerPos(playerid, tX, tY, tZ);
					gVehData[tlID-1][TankerIsRefueling] = 1;
					SaveVehData(tlID-1, "TankerIsRefueling" );
					gVehData[tlID-1][TankerResourceType] = TANKER_TYPE_PETROL;
					SaveVehData(tlID-1, "TankerResourceType");
					SetTimerEx("FuelTankerPetrol", FUEL_TANKER_STEP, false, "ifff", playerid, tX, tY, tZ);
					ShowPlayerDialog(playerid,
													DIALOG_RAF_RSC_CP_INFO_A,
													DIALOG_STYLE_MSGBOX,
													RAF_RSC_CP_MENU_HEADER,
													RAF_RSC_CP_MENU_REFUELING,
													RAF_RSC_CP_MENU_EXIT,
													"" );
					return 1;													
				}
				/* Refuel oil */
				if( listitem == 1 )
				{
					/* Tanker is already filled with other type of fuel */
					if( gVehData[tlID-1][TankerResourceType] != TANKER_TYPE_OIL && gVehData[tlID-1][TankerResourceType] != TANKER_TYPE_NONE )
					{
						ShowPlayerDialog(playerid,
														DIALOG_RAF_RSC_CP_INFO_B,
														DIALOG_STYLE_MSGBOX,
														RAF_RSC_CP_MENU_HEADER,
														RAF_RSC_CP_MENU_INV_TYPE,
														RAF_RSC_CP_MENU_BACK,
														"" );
						return 1;
					}
					/* Tanker is already refueling */
					if( gVehData[tlID-1][TankerIsRefueling] )
					{
						ShowPlayerDialog(playerid,
														DIALOG_RAF_RSC_CP_INFO_A,
														DIALOG_STYLE_MSGBOX,
														RAF_RSC_CP_MENU_HEADER,
														RAF_RSC_CP_MENU_AREFUELING,
														RAF_RSC_CP_MENU_EXIT,
														"" );
						return 1;
					}
					/* Tanker is already full */
					if( gVehData[tlID-1][TankerResourceValue] >= MAX_TANKER_RESOURCE_VALUE )
					{
						ShowPlayerDialog(playerid,
														DIALOG_RAF_RSC_CP_INFO_A,
														DIALOG_STYLE_MSGBOX,
														RAF_RSC_CP_MENU_HEADER,
														RAF_RSC_CP_MENU_AMAX,
														RAF_RSC_CP_MENU_EXIT,
														"" );
						return 1;
					}
					/* No rafinery resource */
					if( gRafinery[RafResourceOil] <= 0 )
					{
						ShowPlayerDialog(playerid,
														DIALOG_RAF_RSC_CP_INFO_A,
														DIALOG_STYLE_MSGBOX,
														RAF_RSC_CP_MENU_HEADER,
														RAF_RSC_CP_MENU_REFUELED_B,
														RAF_RSC_CP_MENU_EXIT,
														"" );
						return 1;
					}
					new Float:tX, Float:tY, Float:tZ;
					GetPlayerPos(playerid, tX, tY, tZ);
					gVehData[tlID-1][TankerIsRefueling] = 1;
					SaveVehData(tlID-1, "TankerIsRefueling" );
					gVehData[tlID-1][TankerResourceType] = TANKER_TYPE_OIL;
					SaveVehData(tlID-1, "TankerResourceType");
					SetTimerEx("FuelTankerOil", FUEL_TANKER_STEP, false, "ifff", playerid, tX, tY, tZ);
					ShowPlayerDialog(playerid,
													DIALOG_RAF_RSC_CP_INFO_A,
													DIALOG_STYLE_MSGBOX,
													RAF_RSC_CP_MENU_HEADER,
													RAF_RSC_CP_MENU_REFUELING,
													RAF_RSC_CP_MENU_EXIT,
													"" );
					return 1;													
				}
				/* Refuel gas */
				if( listitem == 2 )
				{
					/* Tanker is already filled with other type of fuel */
					if( gVehData[tlID-1][TankerResourceType] != TANKER_TYPE_GAS && gVehData[tlID-1][TankerResourceType] != TANKER_TYPE_NONE )
					{
						ShowPlayerDialog(playerid,
														DIALOG_RAF_RSC_CP_INFO_B,
														DIALOG_STYLE_MSGBOX,
														RAF_RSC_CP_MENU_HEADER,
														RAF_RSC_CP_MENU_INV_TYPE,
														RAF_RSC_CP_MENU_BACK,
														"" );
						return 1;
					}
					/* Tanker is already refueling */
					if( gVehData[tlID-1][TankerIsRefueling] )
					{
						ShowPlayerDialog(playerid,
														DIALOG_RAF_RSC_CP_INFO_A,
														DIALOG_STYLE_MSGBOX,
														RAF_RSC_CP_MENU_HEADER,
														RAF_RSC_CP_MENU_AREFUELING,
														RAF_RSC_CP_MENU_EXIT,
														"" );
						return 1;
					}
					/* Tanker is already full */
					if( gVehData[tlID-1][TankerResourceValue] >= MAX_TANKER_RESOURCE_VALUE )
					{
						ShowPlayerDialog(playerid,
														DIALOG_RAF_RSC_CP_INFO_A,
														DIALOG_STYLE_MSGBOX,
														RAF_RSC_CP_MENU_HEADER,
														RAF_RSC_CP_MENU_AMAX,
														RAF_RSC_CP_MENU_EXIT,
														"" );
						return 1;
					}
					/* No rafinery resource */
					if( gRafinery[RafResourceGas] <= 0 )
					{
						ShowPlayerDialog(playerid,
														DIALOG_RAF_RSC_CP_INFO_A,
														DIALOG_STYLE_MSGBOX,
														RAF_RSC_CP_MENU_HEADER,
														RAF_RSC_CP_MENU_REFUELED_B,
														RAF_RSC_CP_MENU_EXIT,
														"" );
						return 1;
					}
					new Float:tX, Float:tY, Float:tZ;
					GetPlayerPos(playerid, tX, tY, tZ);
					gVehData[tlID-1][TankerIsRefueling] = 1;
					SaveVehData(tlID-1, "TankerIsRefueling" );
					gVehData[tlID-1][TankerResourceType] = TANKER_TYPE_GAS;
					SaveVehData(tlID-1, "TankerResourceType");
					SetTimerEx("FuelTankerGas", FUEL_TANKER_STEP, false, "ifff", playerid, tX, tY, tZ);
					ShowPlayerDialog(playerid,
													DIALOG_RAF_RSC_CP_INFO_A,
													DIALOG_STYLE_MSGBOX,
													RAF_RSC_CP_MENU_HEADER,
													RAF_RSC_CP_MENU_REFUELING,
													RAF_RSC_CP_MENU_EXIT,
													"" );
					return 1;													
				}
				/* Return fuel to rafinery */
				if( listitem == 3 )
				{
					/* Tanker has no defined fuel type */
					if( gVehData[tlID-1][TankerResourceType] == TANKER_TYPE_NONE )
					{
						ShowPlayerDialog(playerid,
														DIALOG_RAF_RSC_CP_INFO_B,
														DIALOG_STYLE_MSGBOX,
														RAF_RSC_CP_MENU_HEADER,
														RAF_RSC_CP_MENU_NO_TYPE,
														RAF_RSC_CP_MENU_BACK,
														"" );
						return 1;
					}
					/* Tanker is empty */
					if( gVehData[tlID-1][TankerResourceValue] == 0 )
					{
						ShowPlayerDialog(playerid,
														DIALOG_RAF_RSC_CP_INFO_A,
														DIALOG_STYLE_MSGBOX,
														RAF_RSC_CP_MENU_HEADER,
														RAF_RSC_CP_MENU_EMPTY,
														RAF_RSC_CP_MENU_EXIT,
														"" );
						return 1;
					}
					new Float:tX, Float:tY, Float:tZ;
					GetPlayerPos(playerid, tX, tY, tZ);
					gVehData[tlID-1][TankerIsRefueling] = 1;
					SaveVehData(tlID-1, "TankerIsRefueling" );
					SetTimerEx("DrainTankerFuel", FUEL_TANKER_STEP, false, "ifff", playerid, tX, tY, tZ);
					ShowPlayerDialog(playerid,
													DIALOG_RAF_RSC_CP_INFO_A,
													DIALOG_STYLE_MSGBOX,
													RAF_RSC_CP_MENU_HEADER,
													RAF_RSC_CP_MENU_DRAINING,
													RAF_RSC_CP_MENU_EXIT,
													"" );
					return 1;	
				}
			}
		}
		case DIALOG_RAF_RSC_CP_INFO_A:
		{
			/* Just confirm that dialog has been handled */
			return 1;
		}
		case DIALOG_RAF_RSC_CP_INFO_B:
		{
			/* Return to main menu */
			ShowPlayerDialog(playerid,
											DIALOG_RAF_RSC_CP_MAIN,
											DIALOG_STYLE_LIST,
											RAF_RSC_CP_MENU_HEADER,
											RAF_RSC_CP_MENU_OPTIONS_MAIN,
											RAF_RSC_CP_MENU_EXIT,
											"" );
			return 1;
		}				
		case DIALOG_WMENU_1:
		{
			if(response)
			{
				gListItem[playerid] = listitem;
				if(listitem == 0)
				{
					format( string, sizeof(string),
					DIALOG_WMENU_W_LIST_TXT,
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactory9MM],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactory9MMSil],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryDesEagle],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryMicroSMG],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryMP5],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryTec9],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryShotgun],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAK47],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryM4],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRifle],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactorySRifle]);
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_2_WEAPON, DIALOG_STYLE_LIST, DIALOG_WMENU_TITLE_TXT, string, "Wybierz", "Wróæ" );
					
					return 1;
				}
				if(listitem == 1)
				{
					format( string, sizeof(string),
					"1. Czêœci g³ówne\n2. Podczêœci");
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_2_PARTS, DIALOG_STYLE_LIST, DIALOG_WMENU_TITLE_TXT, string, "Wybierz", "Wróæ" );
					
					return 1;
				}
				if(listitem == 2)
				{
					format( string, sizeof(string),
					"1. Nabój 9mm [%d]\n2. Nabój .50 AE [%d]\n3. Œrut [%d]\n4. Nabój 7.62mm [%d]\n5. Nabój 12.7 [%d]",
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactory9MMAmmo],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactory50AEAmmo],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryBuckshot],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactory762MMAmmo],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactory127MMAmmo]);
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_2_AMMO, DIALOG_STYLE_LIST, DIALOG_WMENU_TITLE_TXT, string, "Wybierz", "Wróæ" );
					
					return 1;
				}
				if (listitem == 3)
				{
					format( string, sizeof(string),
					"Czy napewno chcesz zwróciæ posiadane czêœci ?\n Jeœli bêdziesz chcia³ ponownie zmontowaæ broñ poprostu wybierz z menu odpowiedniej czêœci opcje \"zmontuj\"" );
					ShowPlayerDialog( playerid, DIALOG_WMENU_2_RETURN, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Tak", "Nie" );
					
					return 1;
				}
			}
		}
		case DIALOG_WLMENU_1_SELECT:
		{
			if( response )
			{
				gListItem[playerid] = listitem;
				if( listitem == 0 )
				{
					if( gPlayerData[playerid][pWFOrderedCount] >= PMAX_ORDERS )
					{
						ShowPlayerDialog( playerid, DIALOG_WLMENU_2_LIMIT, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_LIM_TXT, "Wróæ", "" );
						return 1;
					}
					ShowPlayerDialog( playerid, DIALOG_WLMENU_2_SEL_ORD, DIALOG_STYLE_LIST, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_SEL_TXT, "Wybierz", "Wróæ" );
				}
				if( listitem == 1 )
				{
					ShowPlayerDialog( playerid, DIALOG_WLMENU_2_SEL_BUY, DIALOG_STYLE_LIST, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_SEL_TXT, "Wybierz", "Wróæ" );
				}
				return 1;
			}
		}
		case DIALOG_WLMENU_2_SEL_BUY:
		{
			if( response )
			{
				if( listitem == 0 )
				{
					format( string, sizeof(string),
					DIALOG_WMENU_W_LIST_TXT,
					WFactoryLegalLight[WFactory9MM],
					WFactoryLegalLight[WFactory9MMSil],
					WFactoryLegalLight[WFactoryDesEagle],
					WFactoryLegalLight[WFactoryMicroSMG],
					WFactoryLegalLight[WFactoryMP5],
					WFactoryLegalLight[WFactoryTec9],
					WFactoryLegalHeavy[WFactoryShotgun],
					WFactoryLegalHeavy[WFactoryAK47],
					WFactoryLegalHeavy[WFactoryM4],
					WFactoryLegalHeavy[WFactoryRifle],
					WFactoryLegalHeavy[WFactorySRifle]);
					
					ShowPlayerDialog( playerid, DIALOG_WLMENU_2_WEAPON_B, DIALOG_STYLE_LIST, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
					
					return 1;
				}
				if( listitem == 1 )
				{
					format( string, sizeof(string),
					"1. Nabój 9mm [%d]\n2. Nabój .50 AE [%d]\n3. Œrut [%d]\n4. Nabój 7.62mm [%d]\n5. Nabój 12.7mm [%d]",
					WFactoryLegalLight[WFactory9MMAmmo],
					WFactoryLegalLight[WFactory50AEAmmo],
					WFactoryLegalHeavy[WFactoryBuckshot],
					WFactoryLegalHeavy[WFactory762MMAmmo],
					WFactoryLegalHeavy[WFactory127MMAmmo]);
					
					ShowPlayerDialog( playerid, DIALOG_WLMENU_2_AMMO_B, DIALOG_STYLE_LIST, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
					
					return 1;
				}
			}
			else
			{
				ShowPlayerDialog( playerid, DIALOG_WLMENU_1_SELECT, DIALOG_STYLE_LIST, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_SEL_OB_TXT, "Wybierz", "Anuluj" );
				return 1;
			}
		}
		case DIALOG_WLMENU_2_SEL_ORD:
		{
			if( response )
			{
				gListItem[playerid] = listitem;
				if( listitem == 0 )
				{
					format( string, sizeof(string),
					DIALOG_WMENU_W_LIST_TXT,
					WFactoryLegalLight[WFactory9MM],
					WFactoryLegalLight[WFactory9MMSil],
					WFactoryLegalLight[WFactoryDesEagle],
					WFactoryLegalLight[WFactoryMicroSMG],
					WFactoryLegalLight[WFactoryMP5],
					WFactoryLegalLight[WFactoryTec9],
					WFactoryLegalHeavy[WFactoryShotgun],
					WFactoryLegalHeavy[WFactoryAK47],
					WFactoryLegalHeavy[WFactoryM4],
					WFactoryLegalHeavy[WFactoryRifle],
					WFactoryLegalHeavy[WFactorySRifle]);
					
					ShowPlayerDialog( playerid, DIALOG_WLMENU_2_WEAPON_O, DIALOG_STYLE_LIST, DIALOG_WMENU_TITLE_TXT, string, "Zamów", "Wróæ" );
					
					return 1;
				}
				if( listitem == 1 )
				{
					format( string, sizeof(string),
					"1. Nabój 9mm [%d]\n2. Nabój .50 AE [%d]\n3. Œrut [%d]\n4. Nabój 7.62mm [%d]\n5. Nabój 12.7mm [%d]",
					WFactoryLegalLight[WFactory9MMAmmo],
					WFactoryLegalLight[WFactory50AEAmmo],
					WFactoryLegalHeavy[WFactoryBuckshot],
					WFactoryLegalHeavy[WFactory762MMAmmo],
					WFactoryLegalHeavy[WFactory127MMAmmo]);
					
					ShowPlayerDialog( playerid, DIALOG_WLMENU_2_AMMO_O, DIALOG_STYLE_LIST, DIALOG_WMENU_TITLE_TXT, string, "Zamów", "Wróæ" );
					
					return 1;
				}
			}
			else
			{
				ShowPlayerDialog( playerid, DIALOG_WLMENU_1_SELECT, DIALOG_STYLE_LIST, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_SEL_OB_TXT, "Wybierz", "Zamknij" );
				return 1;
			}
		}
		case DIALOG_WLMENU_2_LIMIT:
		{
			if( response )
			{
				ShowPlayerDialog( playerid, DIALOG_WLMENU_1_SELECT, DIALOG_STYLE_LIST, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_SEL_OB_TXT, "Wybierz", "Zamknij" );
				return 1;
			}
		}
		case DIALOG_WLMENU_2_WEAPON_O:
		{
			if( response )
			{
				GOTO_WLMENU_2_WEAPON_O:
				if( gPlayerData[playerid][pWFOrderedCount] >= PMAX_ORDERS )
				{
					ShowPlayerDialog( playerid, DIALOG_WLMENU_2_LIMIT, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_LIM_TXT, "Wróæ", "" );
					return 1;
				}
				gListItem[playerid] = listitem;
				if( gListOverItem[playerid] != -1 )
				{
					gListItem[playerid] = gListOverItem[playerid];
					gListOverItem[playerid] = -1;
				}
				switch( gListItem[playerid] )
				{
					case 0: // 9MM
					{
						format( string, sizeof(string), DIALOG_WMENU_ORD_W_TXT,
						ItemName( 1, 16 ),
						WFactoryLegalLight[WFactory9MM],
						WFactoryLegalLight[WFactory9MMO],
						ItemPrice( 1, 16 ) );	
					}
					case 1: // 9MMSIL 
					{
						format( string, sizeof(string), DIALOG_WMENU_ORD_W_TXT,
						ItemName( 1, 17 ),
						WFactoryLegalLight[WFactory9MMSil],
						WFactoryLegalLight[WFactory9MMSilO],
						ItemPrice( 1, 17 ) );	
					}
					case 2: // DesEagle
					{
						format( string, sizeof(string), DIALOG_WMENU_ORD_W_TXT,
						ItemName( 1, 18 ),
						WFactoryLegalLight[WFactoryDesEagle],
						WFactoryLegalLight[WFactoryDesEagleO],
						ItemPrice( 1, 18 ) );	
					}
					case 3: // msmg
					{
						format( string, sizeof(string), DIALOG_WMENU_ORD_W_TXT,
						ItemName( 1, 22 ),
						WFactoryLegalLight[WFactoryMicroSMG],
						WFactoryLegalLight[WFactoryMicroSMGO],
						ItemPrice( 1, 22 ) );	
					}
					case 4: // mp5
					{
						format( string, sizeof(string), DIALOG_WMENU_ORD_W_TXT,
						ItemName( 1, 23 ),
						WFactoryLegalLight[WFactoryMP5],
						WFactoryLegalLight[WFactoryMP5O],
						ItemPrice( 1, 23 ) );	
					}
					case 5: // tec9
					{
						format( string, sizeof(string), DIALOG_WMENU_ORD_W_TXT,
						ItemName( 1, 26 ),
						WFactoryLegalLight[WFactoryTec9],
						WFactoryLegalLight[WFactoryTec9O],
						ItemPrice( 1, 26 ) );	
					}
					case 6: // shot
					{
						format( string, sizeof(string), DIALOG_WMENU_ORD_W_TXT,
						ItemName( 1, 19 ),
						WFactoryLegalHeavy[WFactoryShotgun],
						WFactoryLegalHeavy[WFactoryShotgunO],
						ItemPrice( 1, 19 ) );	
					}
					case 7: // ak47
					{
						format( string, sizeof(string), DIALOG_WMENU_ORD_W_TXT,
						ItemName( 1, 24 ),
						WFactoryLegalHeavy[WFactoryAK47],
						WFactoryLegalHeavy[WFactoryAK47O],
						ItemPrice( 1, 24 ) );	
					}
					case 8: // m4
					{
						format( string, sizeof(string), DIALOG_WMENU_ORD_W_TXT,
						ItemName( 1, 25 ),
						WFactoryLegalHeavy[WFactoryM4],
						WFactoryLegalHeavy[WFactoryM4O],
						ItemPrice( 1, 25 ) );	
					}
					case 9: // rifle
					{
						format( string, sizeof(string), DIALOG_WMENU_ORD_W_TXT,
						ItemName( 1, 27 ),
						WFactoryLegalHeavy[WFactoryRifle],
						WFactoryLegalHeavy[WFactoryRifleO],
						ItemPrice( 1, 27 ) );	
					}
					case 10: // srifle
					{
						format( string, sizeof(string), DIALOG_WMENU_ORD_W_TXT,
						ItemName( 1, 28 ),
						WFactoryLegalHeavy[WFactorySRifle],
						WFactoryLegalHeavy[WFactorySRifleO],
						ItemPrice( 1, 28 ) );	
					}
				}
				ShowPlayerDialog( playerid, DIALOG_WLMENU_3_WEAPON_O, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Zamów", "Wróæ" );
				return 1;
			}
			else
			{
				ShowPlayerDialog( playerid, DIALOG_WLMENU_2_SEL_ORD, DIALOG_STYLE_LIST, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_SEL_TXT, "Wybierz", "Wróæ" );
				return 1;
			}
		}
		case DIALOG_WLMENU_3_WEAPON_O:
		{
			if( response )
			{
				gListOverItem[playerid] = gListItem[playerid];
				switch( gListItem[playerid] )
				{
					case 0: // 9MM
					{
						WFactoryLegalLight[WFactory9MMO]++;
						SaveWFactoryData("WFactory9MMO");
						gPlayerData[playerid][pWFOrderedCount]++;
					}
					case 1: // 9MMSIL 
					{
						WFactoryLegalLight[WFactory9MMSilO]++;
						SaveWFactoryData("WFactory9MMSilO");
						gPlayerData[playerid][pWFOrderedCount]++;
					}
					case 2: // DesEagle
					{
						WFactoryLegalLight[WFactoryDesEagleO]++;
						SaveWFactoryData("WFactoryDesEagleO");
						gPlayerData[playerid][pWFOrderedCount]++;
					}
					case 3: // msmg
					{
						WFactoryLegalLight[WFactoryMicroSMGO]++;
						SaveWFactoryData("WFactoryMicroSMGO");
						gPlayerData[playerid][pWFOrderedCount]++;
					}
					case 4: // mp5
					{
						WFactoryLegalLight[WFactoryMP5O]++;
						SaveWFactoryData("WFactoryMP5O");
						gPlayerData[playerid][pWFOrderedCount]++;
					}
					case 5: // tec9
					{
						WFactoryLegalLight[WFactoryTec9O]++;
						SaveWFactoryData("WFactoryTec9O");
						gPlayerData[playerid][pWFOrderedCount]++;
					}
					case 6: // Shot
					{
						WFactoryLegalHeavy[WFactoryShotgunO]++;
						SaveWFactoryData("WFactoryShotgunO");
						gPlayerData[playerid][pWFOrderedCount]++;
					}
					case 7: // AK47
					{
						WFactoryLegalHeavy[WFactoryAK47O]++;
						SaveWFactoryData("WFactoryAK47O");
						gPlayerData[playerid][pWFOrderedCount]++;
					}
					case 8: // M4
					{
						WFactoryLegalHeavy[WFactoryM4O]++;
						SaveWFactoryData("WFactoryM4O");
						gPlayerData[playerid][pWFOrderedCount]++;
					}
					case 9: // Rifle
					{
						WFactoryLegalHeavy[WFactoryRifleO]++;
						SaveWFactoryData("WFactoryRifleO");
						gPlayerData[playerid][pWFOrderedCount]++;
					}
					case 10: // SRifle
					{
						WFactoryLegalHeavy[WFactorySRifleO]++;
						SaveWFactoryData("WFactorySRifleO");
						gPlayerData[playerid][pWFOrderedCount]++;
					}
				}
				goto GOTO_WLMENU_2_WEAPON_O;
				return 1;
			}
			else
			{
				format( string, sizeof(string),
				DIALOG_WMENU_W_LIST_TXT,
				WFactoryLegalLight[WFactory9MM],
				WFactoryLegalLight[WFactory9MMSil],
				WFactoryLegalLight[WFactoryDesEagle],
				WFactoryLegalLight[WFactoryMicroSMG],
				WFactoryLegalLight[WFactoryMP5],
				WFactoryLegalLight[WFactoryTec9],
				WFactoryLegalHeavy[WFactoryShotgun],
				WFactoryLegalHeavy[WFactoryAK47],
				WFactoryLegalHeavy[WFactoryM4],
				WFactoryLegalHeavy[WFactoryRifle],
				WFactoryLegalHeavy[WFactorySRifle]);
				
				ShowPlayerDialog( playerid, DIALOG_WLMENU_2_WEAPON_O, DIALOG_STYLE_LIST, DIALOG_WMENU_TITLE_TXT, string, "Zamów", "Wróæ" );
				
				return 1;
			}
		}
		case DIALOG_WLMENU_2_WEAPON_B:
		{
			if( response )
			{
				GOTO_WLMENU_2_WEAPON_B:
				gListItem[playerid] = listitem;
				if( gListOverItem[playerid] != -1 )
				{
					gListItem[playerid] = gListOverItem[playerid];
					gListOverItem[playerid] = -1;
				}
				switch( gListItem[playerid] )
				{
					case 0: // 9MM
					{
						format( string, sizeof(string), DIALOG_WMENU_BUY_W_TXT,
						ItemName( 1, 16 ),
						WFactoryLegalLight[WFactory9MM],
						ItemPrice( 1, 16 ) );
						
						ShowPlayerDialog( playerid, DIALOG_WLMENU_3_WEAPON_B, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
					}
					case 1: // 9mm sil
					{
						format( string, sizeof(string), DIALOG_WMENU_BUY_W_TXT,
						ItemName( 1, 17 ),
						WFactoryLegalLight[WFactory9MMSil],
						ItemPrice( 1, 17 ) );
						
						ShowPlayerDialog( playerid, DIALOG_WLMENU_3_WEAPON_B, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
					}
					case 2: // deag
					{
						format( string, sizeof(string), DIALOG_WMENU_BUY_W_TXT,
						ItemName( 1, 18 ),
						WFactoryLegalLight[WFactoryDesEagle],
						ItemPrice( 1, 18 ) );
						
						ShowPlayerDialog( playerid, DIALOG_WLMENU_3_WEAPON_B, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
					}
					case 3: // msmg
					{
						format( string, sizeof(string), DIALOG_WMENU_BUY_W_TXT,
						ItemName( 1, 22 ),
						WFactoryLegalLight[WFactoryMicroSMG],
						ItemPrice( 1, 22 ) );
						
						ShowPlayerDialog( playerid, DIALOG_WLMENU_3_WEAPON_B, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
					}
					case 4: // mp5
					{
						format( string, sizeof(string), DIALOG_WMENU_BUY_W_TXT,
						ItemName( 1, 23 ),
						WFactoryLegalLight[WFactoryMP5],
						ItemPrice( 1, 23 ) );
						
						ShowPlayerDialog( playerid, DIALOG_WLMENU_3_WEAPON_B, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
					}
					case 5: // tec9
					{
						format( string, sizeof(string), DIALOG_WMENU_BUY_W_TXT,
						ItemName( 1, 26 ),
						WFactoryLegalLight[WFactoryTec9],
						ItemPrice( 1, 26 ) );
						
						ShowPlayerDialog( playerid, DIALOG_WLMENU_3_WEAPON_B, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
					}
					case 6: // shot
					{
						format( string, sizeof(string), DIALOG_WMENU_BUY_W_TXT,
						ItemName( 1, 19 ),
						WFactoryLegalHeavy[WFactoryShotgun],
						ItemPrice( 1, 19 ) );
						
						ShowPlayerDialog( playerid, DIALOG_WLMENU_3_WEAPON_B, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
					}
					case 7: // ak47
					{
						format( string, sizeof(string), DIALOG_WMENU_BUY_W_TXT,
						ItemName( 1, 24 ),
						WFactoryLegalHeavy[WFactoryAK47],
						ItemPrice( 1, 24 ) );
						
						ShowPlayerDialog( playerid, DIALOG_WLMENU_3_WEAPON_B, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
					}
					case 8: // m4
					{
						format( string, sizeof(string), DIALOG_WMENU_BUY_W_TXT,
						ItemName( 1, 25 ),
						WFactoryLegalHeavy[WFactoryM4],
						ItemPrice( 1, 25 ) );
						
						ShowPlayerDialog( playerid, DIALOG_WLMENU_3_WEAPON_B, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
					}
					case 9: // rifle
					{
						format( string, sizeof(string), DIALOG_WMENU_BUY_W_TXT,
						ItemName( 1, 27 ),
						WFactoryLegalHeavy[WFactoryRifle],
						ItemPrice( 1, 27 ) );
						
						ShowPlayerDialog( playerid, DIALOG_WLMENU_3_WEAPON_B, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
					}
					case 10: // srifle
					{
						format( string, sizeof(string), DIALOG_WMENU_BUY_W_TXT,
						ItemName( 1, 28 ),
						WFactoryLegalHeavy[WFactorySRifle],
						ItemPrice( 1, 28 ) );
						
						ShowPlayerDialog( playerid, DIALOG_WLMENU_3_WEAPON_B, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
					}
				}
				return 1;
			}
			else
			{
				ShowPlayerDialog( playerid, DIALOG_WLMENU_2_SEL_BUY, DIALOG_STYLE_LIST, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_SEL_TXT, "Wybierz", "Wróæ" );
				return 1;
			}
		}
		case DIALOG_WLMENU_3_WEAPON_B:
		{
			if( response )
			{
				gListOverItem[playerid] = gListItem[playerid];
				new WTG; // where to transfer new weapon
				if( gPlayerData[playerid][pFaction] != 255 && gPlayerData[playerid][pRank] == 1 )
				{
					if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fType] == 1)
						WTG = 1;
				}
				else if( gPlayerData[playerid][pBizKey] != 255 )
					WTG = 2;
				if( gPlayerData[playerid][pBizKey] != 255 && gPlayerData[playerid][pFaction] != 255 && gPlayerData[playerid][pRank] == 1 )
				{
					SendClientMessage( playerid, COLOR_RED, "[INFO:] Jesteœ liderem frakcji a tak¿e posiadasz biznes - zakupiona broñ trafi do frakcji !" );
				}
				switch( gListItem[playerid] )
				{
					case 0: // 9mm
					{
						if( WFactoryLegalLight[WFactory9MM] == 0 )
						{
							ShowPlayerDialog( playerid, DIALOG_WLMENU_2_WEAPON_B, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_B_OUT_TXT, "Wróæ", "" );
							return 1;
						}
						DynamicFactions[FACTIONID_GOVERNMENT][fBank] += ItemPrice( 1, 16 );
						SaveFData( FACTIONID_GOVERNMENT, "Bank" );
						WFactoryLegalLight[WFactory9MM]--;
						SaveWFactoryData( "WFactory9MM" );
						if( WTG == 1 )
						{
							DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 16 );						
							SaveFData( gPlayerData[playerid][pFaction], "Bank" );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactory9MM]++;
							SaveFData( gPlayerData[playerid][pFaction], "WFactory9MM" );
						}
						else if( WTG == 2 )
						{
							Businesses[ gPlayerData[playerid][pBizKey] ][W9MM]++;
							SaveBizData( gPlayerData[playerid][pBizKey], "W9MM" );
						}
					}
					case 1: // 9mm sil
					{
						if( WFactoryLegalLight[WFactory9MMSil] == 0 )
						{
							ShowPlayerDialog( playerid, DIALOG_WLMENU_2_WEAPON_B, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_B_OUT_TXT, "Wróæ", "" );
							return 1;
						}
						DynamicFactions[FACTIONID_GOVERNMENT][fBank] += ItemPrice( 1, 17 );
						SaveFData( FACTIONID_GOVERNMENT, "Bank" );
						WFactoryLegalLight[WFactory9MMSil]--;
						SaveWFactoryData( "WFactory9MMSil" );
						if( WTG == 1 )
						{
							DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 17 );						
							SaveFData( gPlayerData[playerid][pFaction], "Bank" );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactory9MMSil]++;
							SaveFData( gPlayerData[playerid][pFaction], "WFactory9MMSil" );
						}
						else if( WTG == 2 )
						{
							Businesses[ gPlayerData[playerid][pBizKey] ][W9MM]++;
							SaveBizData( gPlayerData[playerid][pBizKey], "W9MMSil" );
						}
					}
					case 2: // deag
					{
						if( WFactoryLegalLight[WFactoryDesEagle] == 0 )
						{
							ShowPlayerDialog( playerid, DIALOG_WLMENU_2_WEAPON_B, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_B_OUT_TXT, "Wróæ", "" );
							return 1;
						}
						DynamicFactions[FACTIONID_GOVERNMENT][fBank] += ItemPrice( 1, 18 );
						SaveFData( FACTIONID_GOVERNMENT, "Bank" );
						WFactoryLegalLight[WFactoryDesEagle]--;
						SaveWFactoryData( "WFactoryDesEagle" );
						if( WTG == 1 )
						{
							DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 18 );						
							SaveFData( gPlayerData[playerid][pFaction], "Bank" );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryDesEagle]++;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryDesEagle" );
						}
						else if( WTG == 2 )
						{
							Businesses[ gPlayerData[playerid][pBizKey] ][WDesEagle]++;
							SaveBizData( gPlayerData[playerid][pBizKey], "WDesEagle" );
						}
					}
					case 3: // micro smg
					{
						if( WFactoryLegalLight[WFactoryMicroSMG] == 0 )
						{
							ShowPlayerDialog( playerid, DIALOG_WLMENU_2_WEAPON_B, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_B_OUT_TXT, "Wróæ", "" );
							return 1;
						}
						DynamicFactions[FACTIONID_GOVERNMENT][fBank] += ItemPrice( 1, 22 );
						SaveFData( FACTIONID_GOVERNMENT, "Bank" );
						WFactoryLegalLight[WFactoryMicroSMG]--;
						SaveWFactoryData( "WFactoryMicroSMG" );
						if( WTG == 1 )
						{
							DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 22 );						
							SaveFData( gPlayerData[playerid][pFaction], "Bank" );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryMicroSMG]++;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryMicroSMG" );
						}
						else if( WTG == 2 )
						{
							Businesses[ gPlayerData[playerid][pBizKey] ][WMicroSMG]++;
							SaveBizData( gPlayerData[playerid][pBizKey], "WMicroSMG" );
						}
					}
					case 4: // mp5
					{
						if( WFactoryLegalLight[WFactoryMP5] == 0 )
						{
							ShowPlayerDialog( playerid, DIALOG_WLMENU_2_WEAPON_B, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_B_OUT_TXT, "Wróæ", "" );
							return 1;
						}
						DynamicFactions[FACTIONID_GOVERNMENT][fBank] += ItemPrice( 1, 23 );
						SaveFData( FACTIONID_GOVERNMENT, "Bank" );
						WFactoryLegalLight[WFactoryMP5]--;
						SaveWFactoryData( "WFactoryMP5" );
						if( WTG == 1 )
						{
							DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 23 );						
							SaveFData( gPlayerData[playerid][pFaction], "Bank" );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryMP5]++;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryMP5" );
						}
						else if( WTG == 2 )
						{
							Businesses[ gPlayerData[playerid][pBizKey] ][WMP5]++;
							SaveBizData( gPlayerData[playerid][pBizKey], "WMP5" );
						}
					}
					case 5: // tec9
					{
						if( WFactoryLegalLight[WFactoryTec9] == 0 )
						{
							ShowPlayerDialog( playerid, DIALOG_WLMENU_2_WEAPON_B, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_B_OUT_TXT, "Wróæ", "" );
							return 1;
						}
						DynamicFactions[FACTIONID_GOVERNMENT][fBank] += ItemPrice( 1, 23 );
						SaveFData( FACTIONID_GOVERNMENT, "Bank" );
						WFactoryLegalLight[WFactoryTec9]--;
						SaveWFactoryData( "WFactoryTec9" );
						if( WTG == 1 )
						{
							DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 23 );						
							SaveFData( gPlayerData[playerid][pFaction], "Bank" );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryTec9]++;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryTec9" );
						}
						else if( WTG == 2 )
						{
							Businesses[ gPlayerData[playerid][pBizKey] ][WTec9]++;
							SaveBizData( gPlayerData[playerid][pBizKey], "WTec9" );
						}
					}
					case 6: // shot
					{
						if( WFactoryLegalHeavy[WFactoryShotgun] == 0 )
						{
							ShowPlayerDialog( playerid, DIALOG_WLMENU_2_WEAPON_B, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_B_OUT_TXT, "Wróæ", "" );
							return 1;
						}
						DynamicFactions[FACTIONID_GOVERNMENT][fBank] += ItemPrice( 1, 19 );
						SaveFData( FACTIONID_GOVERNMENT, "Bank" );
						WFactoryLegalHeavy[WFactoryShotgun]--;
						SaveWFactoryData( "WFactoryShotgun" );
						if( WTG == 1 )
						{
							DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 19 );						
							SaveFData( gPlayerData[playerid][pFaction], "Bank" );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryShotgun]++;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryShotgun" );
						}
						else if( WTG == 2 )
						{
							Businesses[ gPlayerData[playerid][pBizKey] ][WShotgun]++;
							SaveBizData( gPlayerData[playerid][pBizKey], "WShotgun" );
						}
					}
					case 7: // ak47
					{
						if( WFactoryLegalHeavy[WFactoryAK47] == 0 )
						{
							ShowPlayerDialog( playerid, DIALOG_WLMENU_2_WEAPON_B, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_B_OUT_TXT, "Wróæ", "" );
							return 1;
						}
						DynamicFactions[FACTIONID_GOVERNMENT][fBank] += ItemPrice( 1, 24 );
						SaveFData( FACTIONID_GOVERNMENT, "Bank" );
						WFactoryLegalHeavy[WFactoryAK47]--;
						SaveWFactoryData( "WFactoryAK47" );
						if( WTG == 1 )
						{
							DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 24 );						
							SaveFData( gPlayerData[playerid][pFaction], "Bank" );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAK47]++;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryAK47" );
						}
						else if( WTG == 2 )
						{
							Businesses[ gPlayerData[playerid][pBizKey] ][WAK47]++;
							SaveBizData( gPlayerData[playerid][pBizKey], "WAK47" );
						}
					}
					case 8: // m4
					{
						if( WFactoryLegalHeavy[WFactoryM4] == 0 )
						{
							ShowPlayerDialog( playerid, DIALOG_WLMENU_2_WEAPON_B, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_B_OUT_TXT, "Wróæ", "" );
							return 1;
						}
						DynamicFactions[FACTIONID_GOVERNMENT][fBank] += ItemPrice( 1, 25 );
						SaveFData( FACTIONID_GOVERNMENT, "Bank" );
						WFactoryLegalHeavy[WFactoryM4]--;
						SaveWFactoryData( "WFactoryM4" );
						if( WTG == 1 )
						{
							DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 25 );						
							SaveFData( gPlayerData[playerid][pFaction], "Bank" );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryM4]++;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryM4" );
						}
						else if( WTG == 2 )
						{
							Businesses[ gPlayerData[playerid][pBizKey] ][WM4]++;
							SaveBizData( gPlayerData[playerid][pBizKey], "WM4" );
						}
					}
					case 9: // rifle
					{
						if( WFactoryLegalHeavy[WFactoryRifle] == 0 )
						{
							ShowPlayerDialog( playerid, DIALOG_WLMENU_2_WEAPON_B, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_B_OUT_TXT, "Wróæ", "" );
							return 1;
						}
						DynamicFactions[FACTIONID_GOVERNMENT][fBank] += ItemPrice( 1, 27 );
						SaveFData( FACTIONID_GOVERNMENT, "Bank" );
						WFactoryLegalHeavy[WFactoryRifle]--;
						SaveWFactoryData( "WFactoryRifle" );
						if( WTG == 1 )
						{
							DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 27 );						
							SaveFData( gPlayerData[playerid][pFaction], "Bank" );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRifle]++;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryRifle" );
						}
						else if( WTG == 2 )
						{
							Businesses[ gPlayerData[playerid][pBizKey] ][WRifle]++;
							SaveBizData( gPlayerData[playerid][pBizKey], "WRifle" );
						}
					}
					case 10: // srifle
					{
						if( WFactoryLegalHeavy[WFactorySRifle] == 0 )
						{
							ShowPlayerDialog( playerid, DIALOG_WLMENU_2_WEAPON_B, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_B_OUT_TXT, "Wróæ", "" );
							return 1;
						}
						DynamicFactions[FACTIONID_GOVERNMENT][fBank] += ItemPrice( 1, 28 );
						SaveFData( FACTIONID_GOVERNMENT, "Bank" );
						WFactoryLegalHeavy[WFactorySRifle]--;
						SaveWFactoryData( "WFactorySRifle" );
						if( WTG == 1 )
						{
							DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 28 );						
							SaveFData( gPlayerData[playerid][pFaction], "Bank" );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactorySRifle]++;
							SaveFData( gPlayerData[playerid][pFaction], "WFactorySRifle" );
						}
						else if( WTG == 2 )
						{
							Businesses[ gPlayerData[playerid][pBizKey] ][WSRifle]++;
							SaveBizData( gPlayerData[playerid][pBizKey], "WSRifle" );
						}
					}
				}
				goto GOTO_WLMENU_2_WEAPON_B;
				return 1;
			}
			else
			{
				format( string, sizeof(string),
				DIALOG_WMENU_W_LIST_TXT,
				WFactoryLegalLight[WFactory9MM],
				WFactoryLegalLight[WFactory9MMSil],
				WFactoryLegalLight[WFactoryDesEagle],
				WFactoryLegalLight[WFactoryMicroSMG],
				WFactoryLegalLight[WFactoryMP5],
				WFactoryLegalLight[WFactoryTec9],
				WFactoryLegalHeavy[WFactoryShotgun],
				WFactoryLegalHeavy[WFactoryAK47],
				WFactoryLegalHeavy[WFactoryM4],
				WFactoryLegalHeavy[WFactoryRifle],
				WFactoryLegalHeavy[WFactorySRifle]);
				
				ShowPlayerDialog( playerid, DIALOG_WLMENU_2_WEAPON_B, DIALOG_STYLE_LIST, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
				return 1;
			}
		}				
		case DIALOG_WLMENU_2_AMMO_O:
		{
			if( response )
			{
				GOTO_WLMENU_2_AMMO_O:
				if( gPlayerData[playerid][pWFOrderedCount] >= PMAX_ORDERS )
				{
					ShowPlayerDialog( playerid, DIALOG_WLMENU_2_LIMIT, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_LIM_TXT, "Wróæ", "" );
					return 1;
				}
				gListItem[playerid] = listitem;
				if( gListOverItem[playerid] != -1 )
				{
					gListItem[playerid] = gListOverItem[playerid];
					gListOverItem[playerid] = -1;
				}
				switch( gListItem[playerid] )
				{
					case 0: // 9mm ammo
					{
						format( string, sizeof(string), DIALOG_WMENU_ORD_A_TXT,
						ItemName( 1, 36 ),
						WFactoryLegalLight[WFactory9MMAmmo],
						WFactoryLegalLight[WFactory9MMAmmoO],
						ItemPrice( 1, 36 ) );	
					}
					case 1: // 50ae
					{
						format( string, sizeof(string), DIALOG_WMENU_ORD_A_TXT,
						ItemName( 1, 37 ),
						WFactoryLegalLight[WFactory50AEAmmo],
						WFactoryLegalLight[WFactory50AEAmmoO],
						ItemPrice( 1, 37 ) );	
					}
					case 2: // buckshot
					{
						format( string, sizeof(string), DIALOG_WMENU_ORD_A_TXT,
						ItemName( 1, 38 ),
						WFactoryLegalHeavy[WFactoryBuckshot],
						WFactoryLegalHeavy[WFactoryBuckshotO],
						ItemPrice( 1, 38 ) );	
					}
					case 3: // 762mm
					{
						format( string, sizeof(string), DIALOG_WMENU_ORD_A_TXT,
						ItemName( 1, 39 ),
						WFactoryLegalHeavy[WFactory762MMAmmo],
						WFactoryLegalHeavy[WFactory762MMAmmoO],
						ItemPrice( 1, 39 ) );	
					}
					case 4: //  127mm
					{
						format( string, sizeof(string), DIALOG_WMENU_ORD_A_TXT,
						ItemName( 1, 40 ),
						WFactoryLegalHeavy[WFactory127MMAmmo],
						WFactoryLegalHeavy[WFactory127MMAmmoO],
						ItemPrice( 1, 40 ) );	
					}
				}
				ShowPlayerDialog( playerid, DIALOG_WLMENU_3_AMMO_O, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Zamów", "Wróæ" );
				return 1;
			}
			else
			{
				ShowPlayerDialog( playerid, DIALOG_WLMENU_2_SEL_ORD, DIALOG_STYLE_LIST, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_SEL_TXT, "Wybierz", "Wróæ" );
				return 1;
			}
		}
		case DIALOG_WLMENU_3_AMMO_O:
		{
			if( response )
			{
				gListOverItem[playerid] = gListItem[playerid];
				switch( gListItem[playerid] )
				{
					case 0: // 9mm ammo
					{
						WFactoryLegalLight[WFactory9MMAmmoO]++;
						gPlayerData[playerid][pWFOrderedCount]++;
					}
					case 1: // 50ae
					{
						WFactoryLegalLight[WFactory50AEAmmoO]++;
						gPlayerData[playerid][pWFOrderedCount]++;
					}
					case 2: // buckshot
					{
						WFactoryLegalHeavy[WFactoryBuckshotO]++;
						gPlayerData[playerid][pWFOrderedCount]++;
					}
					case 3: // 762mm
					{
						WFactoryLegalHeavy[WFactory762MMAmmoO]++;
						gPlayerData[playerid][pWFOrderedCount]++;
					}
					case 4: //  127mm
					{
						WFactoryLegalHeavy[WFactory127MMAmmoO]++;
						gPlayerData[playerid][pWFOrderedCount]++;
					}
				}
				goto GOTO_WLMENU_2_AMMO_O;
				return 1;
			}
			else
			{
				format( string, sizeof(string),
				"1. Nabój 9mm [%d]\n2. Nabój .50 AE [%d]\n3. Œrut [%d]\n4. Nabój 7.62mm [%d]\n5. Nabój 12.7mm [%d]",
				WFactoryLegalLight[WFactory9MMAmmo],
				WFactoryLegalLight[WFactory50AEAmmo],
				WFactoryLegalHeavy[WFactoryBuckshot],
				WFactoryLegalHeavy[WFactory762MMAmmo],
				WFactoryLegalHeavy[WFactory127MMAmmo]);
				
				ShowPlayerDialog( playerid, DIALOG_WLMENU_2_AMMO_O, DIALOG_STYLE_LIST, DIALOG_WMENU_TITLE_TXT, string, "Zamów", "Wróæ" );
				
				return 1;
			}
		}
		case DIALOG_WLMENU_2_AMMO_B:
		{
			if( response )
			{
				GOTO_WLMENU_2_AMMO_B:
				gListItem[playerid] = listitem;
				if( gListOverItem[playerid] != -1 )
				{
					gListItem[playerid] = gListOverItem[playerid];
					gListOverItem[playerid] = -1;
				}
				switch( gListItem[playerid] )
				{
					case 0: // 9mm ammo
					{
						format( string, sizeof(string), DIALOG_WMENU_BUY_A_TXT,
						ItemName( 1, 36 ),
						WFactoryLegalLight[WFactory9MMAmmo],
						ItemPrice( 1, 36 ) );	
					}
					case 1: // 50ae
					{
						format( string, sizeof(string), DIALOG_WMENU_BUY_A_TXT,
						ItemName( 1, 37 ),
						WFactoryLegalLight[WFactory50AEAmmo],
						ItemPrice( 1, 37 ) );	
					}
					case 2: // buckshot
					{
						format( string, sizeof(string), DIALOG_WMENU_BUY_A_TXT,
						ItemName( 1, 38 ),
						WFactoryLegalHeavy[WFactoryBuckshot],
						ItemPrice( 1, 38 ) );	
					}
					case 3: // 762mm
					{
						format( string, sizeof(string), DIALOG_WMENU_BUY_A_TXT,
						ItemName( 1, 39 ),
						WFactoryLegalHeavy[WFactory762MMAmmo],
						ItemPrice( 1, 39 ) );	
					}
					case 4: //  127mm
					{
						format( string, sizeof(string), DIALOG_WMENU_BUY_A_TXT,
						ItemName( 1, 40 ),
						WFactoryLegalHeavy[WFactory127MMAmmo],
						ItemPrice( 1, 40 ) );	
					}
				}
				ShowPlayerDialog( playerid, DIALOG_WLMENU_3_AMMO_B, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
				return 1;
			}
			else
			{
				ShowPlayerDialog( playerid, DIALOG_WLMENU_2_SEL_ORD, DIALOG_STYLE_LIST, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_SEL_TXT, "Wybierz", "Wróæ" );
				return 1;
			}				
		}
		case DIALOG_WLMENU_3_AMMO_B:
		{
			if( response )
			{
				gListOverItem[playerid] = gListItem[playerid];
				new WTG; // where to transfer new weapon
				if( gPlayerData[playerid][pFaction] != 255 && gPlayerData[playerid][pRank] == 1)
				{
					if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fType] == 1)
						WTG = 1;
				}
				else if( gPlayerData[playerid][pBizKey] != 255 )
					WTG = 2;
				switch( gListItem[playerid] )
				{
					case 0: // 9mm ammo
					{
						if( WFactoryLegalLight[WFactory9MMAmmo] == 0 )
						{
							ShowPlayerDialog( playerid, DIALOG_WLMENU_2_AMMO_B, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_B_OUT_TXT, "Wróæ", "" );
							return 1;
						}
						DynamicFactions[FACTIONID_GOVERNMENT][fBank] += ItemPrice( 1, 36 );
						SaveFData( FACTIONID_GOVERNMENT, "Bank" );
						WFactoryLegalLight[WFactory9MMAmmo]--;
						SaveWFactoryData( "WFactory9MMAmmo" );
						if( WTG == 1 )
						{
							DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 36 );						
							SaveFData( gPlayerData[playerid][pFaction], "Bank" );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactory9MMAmmo]++;
							SaveFData( gPlayerData[playerid][pFaction], "WFactory9MMAmmo" );
						}
						else if( WTG == 2 )
						{
							Businesses[ gPlayerData[playerid][pBizKey] ][W9MMAmmo]++;
							SaveBizData( gPlayerData[playerid][pBizKey], "W9MMAmmo" );
						}
					}
					case 1: // 50ae
					{
						if( WFactoryLegalLight[WFactory50AEAmmo] == 0 )
						{
							ShowPlayerDialog( playerid, DIALOG_WLMENU_2_AMMO_B, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_B_OUT_TXT, "Wróæ", "" );
							return 1;
						}
						DynamicFactions[FACTIONID_GOVERNMENT][fBank] += ItemPrice( 1, 37 );
						SaveFData( FACTIONID_GOVERNMENT, "Bank" );
						WFactoryLegalLight[WFactory50AEAmmo]--;
						SaveWFactoryData( "WFactory50AEAmmo" );
						if( WTG == 1 )
						{
							DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 37 );						
							SaveFData( gPlayerData[playerid][pFaction], "Bank" );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactory50AEAmmo]++;
							SaveFData( gPlayerData[playerid][pFaction], "WFactory50AEAmmo" );
						}
						else if( WTG == 2 )
						{
							Businesses[ gPlayerData[playerid][pBizKey] ][W50AEAmmo]++;
							SaveBizData( gPlayerData[playerid][pBizKey], "W50AEAmmo" );
						}
					}
					case 2: // buckshot
					{
						if( WFactoryLegalHeavy[WFactoryBuckshot] == 0 )
						{
							ShowPlayerDialog( playerid, DIALOG_WLMENU_2_AMMO_B, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_B_OUT_TXT, "Wróæ", "" );
							return 1;
						}
						DynamicFactions[FACTIONID_GOVERNMENT][fBank] += ItemPrice( 1, 38 );
						SaveFData( FACTIONID_GOVERNMENT, "Bank" );
						WFactoryLegalHeavy[WFactoryBuckshot]--;
						SaveWFactoryData( "WFactoryBuckshot" );
						if( WTG == 1 )
						{
							DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 38 );						
							SaveFData( gPlayerData[playerid][pFaction], "Bank" );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryBuckshot]++;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryBuckshot" );
						}
						else if( WTG == 2 )
						{
							Businesses[ gPlayerData[playerid][pBizKey] ][WBuckshot]++;
							SaveBizData( gPlayerData[playerid][pBizKey], "WBuckshot" );
						}
					}
					case 3: // 762mm
					{
						if( WFactoryLegalHeavy[WFactory762MMAmmo] == 0 )
						{
							ShowPlayerDialog( playerid, DIALOG_WLMENU_2_AMMO_B, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_B_OUT_TXT, "Wróæ", "" );
							return 1;
						}
						DynamicFactions[FACTIONID_GOVERNMENT][fBank] += ItemPrice( 1, 39 );
						SaveFData( FACTIONID_GOVERNMENT, "Bank" );
						WFactoryLegalHeavy[WFactory762MMAmmo]--;
						SaveWFactoryData( "WFactory762MMAmmo" );
						if( WTG == 1 )
						{
							DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 39 );						
							SaveFData( gPlayerData[playerid][pFaction], "Bank" );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactory762MMAmmo]++;
							SaveFData( gPlayerData[playerid][pFaction], "WFactory762MMAmmo" );
						}
						else if( WTG == 2 )
						{
							Businesses[ gPlayerData[playerid][pBizKey] ][W762MMAmmo]++;
							SaveBizData( gPlayerData[playerid][pBizKey], "W762MMAmmo" );
						}
					}
					case 4: //  127mm
					{
						if( WFactoryLegalHeavy[WFactory127MMAmmo] == 0 )
						{
							ShowPlayerDialog( playerid, DIALOG_WLMENU_2_AMMO_B, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_B_OUT_TXT, "Wróæ", "" );
							return 1;
						}
						DynamicFactions[FACTIONID_GOVERNMENT][fBank] += ItemPrice( 1, 40 );
						SaveFData( FACTIONID_GOVERNMENT, "Bank" );
						WFactoryLegalHeavy[WFactory127MMAmmo]--;
						SaveWFactoryData( "WFactory127MMAmmo" );
						if( WTG == 1 )
						{
							DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 40 );						
							SaveFData( gPlayerData[playerid][pFaction], "Bank" );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactory127MMAmmo]++;
							SaveFData( gPlayerData[playerid][pFaction], "WFactory127MMAmmo" );
						}
						else if( WTG == 2 )
						{
							Businesses[ gPlayerData[playerid][pBizKey] ][W127MMAmmo]++;
							SaveBizData( gPlayerData[playerid][pBizKey], "W127MMAmmo" );
						}
					}
				}
				goto GOTO_WLMENU_2_AMMO_B;
				return 1;
			}
			else
			{
				format( string, sizeof(string),
				"1. Nabój 9mm [%d]\n2. Nabój .50 AE [%d]\n3. Œrut [%d]\n4. Nabój 7.62mm [%d]\n5. Nabój 12.7mm [%d]",
				WFactoryLegalLight[WFactory9MMAmmo],
				WFactoryLegalLight[WFactory50AEAmmo],
				WFactoryLegalHeavy[WFactoryBuckshot],
				WFactoryLegalHeavy[WFactory762MMAmmo],
				WFactoryLegalHeavy[WFactory127MMAmmo]);
				
				ShowPlayerDialog( playerid, DIALOG_WLMENU_2_AMMO_B, DIALOG_STYLE_LIST, DIALOG_WMENU_TITLE_TXT, string, "Zamów", "Wróæ" );
				
				return 1;
			}
		}
		case DIALOG_WMENU_2_RETURN:
		{
			if (response)
			{
				new slotitem = -1;
				/* Slot 1 */
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
				SavePlayerData( playerid, "PartType" );
				SavePlayerData( playerid, "PartItem" );
				SavePlayerData( playerid, "MountsLeft" );
				SendClientMessage(playerid, COLOR_GREEN, "[INFO:] Zwróci³eœ wszystkie posiadane czêœci do magazynu");
				return 1;
			}
		}
		case DIALOG_WMENU_2_WEAPON:
		{
			if(response)
			{
				gListItem[playerid] = listitem;
				if (listitem == 0) // 9mm
				{
					format( string2, sizeof(string2), DIALOG_WMENU_BUY_CHECKOUT2_TXT,
					ItemName( 1, 16 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactory9MM] );
					format( string, sizeof(string), "%sWymagane czêœci:\n- szkielet broni [%d/1]\n- zespó³ zamka [%d/1]\n- magazynek [%d/1]\n- sprê¿yna powrotna [%d/1]\n- komplet œrubek [%d/1]",
					string2,
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart1],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart2],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart3],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart4],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart5]);
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_3_WEAPON_MAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Zmontuj", "Wróæ" );

					return 1;
				}
				else if (listitem == 1) // 9mm tlumik
				{
					format( string2, sizeof(string2), DIALOG_WMENU_BUY_CHECKOUT2_TXT,
					ItemName( 1, 17 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactory9MMSil] );
					format( string, sizeof(string), "%sWymagane czêœci:\n- szkielet broni [%d/1]\n- zespó³ zamka [%d/1]\n- magazynek [%d/1]\n- sprê¿yna powrotna [%d/1]\n- komplet œrubek [%d/1]\n- t³umik [%d/1]",
					string2,
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart1],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart2],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart3],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart4],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart5],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart6]);
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_3_WEAPON_MAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Zmontuj", "Wróæ" );

					return 1;
				}
				else if (listitem == 2) // desert eagle
				{
					format( string2, sizeof(string2), DIALOG_WMENU_BUY_CHECKOUT2_TXT,
					ItemName( 1, 18 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryDesEagle] );
					format( string, sizeof(string), "%sWymagane czêœci:\n- szkielet broni [%d/4]\n- zespó³ zamka [%d/2]\n- magazynek [%d/2]\n- sprê¿yna powrotna [%d/2]\n- komplet œrubek [%d/1]\n- carbon [%d/1]",
					string2,
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart1],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart2],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart3],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart4],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart5],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryDesEaglePart]);
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_3_WEAPON_MAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Zmontuj", "Wróæ" );

					return 1;
				}
				else if (listitem == 6) // shotgun
				{
					format( string2, sizeof(string2), DIALOG_WMENU_BUY_CHECKOUT2_TXT,
					ItemName( 1, 19 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryShotgun] );
					format( string, sizeof(string), "%sWymagane czêœci:\n- szkielet broni karabinowej [%d/2]\n- zespó³ zamka karabinu [%d/1]\n- magazynek karabinu [%d/1]\n- sprê¿yna powrotna karabinu [%d/3]\n- kolba [%d/1]\n- komplet œrubek karabinu [%d/1]\n- rêkojeœæ prze³adowania [%d/1]",
					string2,
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart1],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart2],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart3],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart4],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart5],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart6],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryShotPart]);
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_3_WEAPON_MAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Zmontuj", "Wróæ" );

					return 1;
				}
				else if (listitem == 3) // micro smg
				{
					format( string2, sizeof(string2), DIALOG_WMENU_BUY_CHECKOUT2_TXT,
					ItemName( 1, 22 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryMicroSMG] );
					format( string, sizeof(string), "%sWymagane czêœci:\n- szkielet broni [%d/4]\n- zespó³ zamka [%d/4]\n- magazynek [%d/4]\n- sprê¿yna powrotna [%d/1]\n- komplet œrubek [%d/1]",
					string2,
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart1],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart2],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart3],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart4],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart5]);
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_3_WEAPON_MAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Zmontuj", "Wróæ" );

					return 1;
				}
				else if (listitem == 4) // mp5
				{
					format( string2, sizeof(string2), DIALOG_WMENU_BUY_CHECKOUT2_TXT,
					ItemName( 1, 23 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryMP5] );
					format( string, sizeof(string), "%sWymagane czêœci:\n- szkielet broni karabinowej [%d/2]\n- zespó³ zamka karabinu [%d/2]\n- magazynek karabinu [%d/1]\n- sprê¿yna powrotna karabinu [%d/1]\n- kolba [%d/1]\n- komplet œrubek karabinu [%d/1]\n- skrzynka monta¿owa MP5 [%d/1]",
					string2,
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart1],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart2],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart3],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart4],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart5],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart6],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryMP5Part]);
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_3_WEAPON_MAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Zmontuj", "Wróæ" );

					return 1;
				}
				else if (listitem == 7) // ak-47
				{
					format( string2, sizeof(string2), DIALOG_WMENU_BUY_CHECKOUT2_TXT,
					ItemName( 1, 24 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAK47] );
					format( string, sizeof(string), "%sWymagane czêœci:\n- szkielet broni karabinowej [%d/3]\n- zespó³ zamka karabinu [%d/2]\n- magazynek karabinu [%d/2]\n- sprê¿yna powrotna karabinu [%d/1]\n- kolba [%d/1]\n- komplet œrubek karabinu [%d/1]\n- zestaw monta¿owy AK-47 [%d/1]",
					string2,
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart1],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart2],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart3],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart4],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart5],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart6],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAK47Part]);
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_3_WEAPON_MAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Zmontuj", "Wróæ" );

					return 1;
				}
				else if (listitem == 8) // m4
				{
					format( string2, sizeof(string2), DIALOG_WMENU_BUY_CHECKOUT2_TXT,
					ItemName( 1, 25 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryM4] );
					format( string, sizeof(string), "%sWymagane czêœci:\n- szkielet broni karabinowej [%d/3]\n- zespó³ zamka karabinu [%d/2]\n- magazynek karabinu [%d/2]\n- sprê¿yna powrotna karabinu [%d/1]\n- kolba [%d/1]\n- komplet œrubek karabinu [%d/1]\n- skrzynka monta¿owa M4 [%d/1]",
					string2,
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart1],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart2],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart3],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart4],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart5],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart6],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryM4Part]);
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_3_WEAPON_MAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Zmontuj", "Wróæ" );

					return 1;
				}
				else if (listitem == 5) // tec9
				{
					format( string2, sizeof(string2), DIALOG_WMENU_BUY_CHECKOUT2_TXT,
					ItemName( 1, 26 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryTec9] );
					format( string, sizeof(string), "%sWymagane czêœci:\n- szkielet broni [%d/3]\n- zespó³ zamka [%d/2]\n- magazynek [%d/2]\n- sprê¿yna powrotna [%d/1]\n- komplet œrubek [%d/1]\n- t³umik [%d/1]\n- zestaw monta¿owy Tec9 [%d/1]",
					string2,
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart1],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart2],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart3],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart4],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart5],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart6],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryTec9Part]);
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_3_WEAPON_MAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Zmontuj", "Wróæ" );

					return 1;
				}
				else if (listitem == 9) // country rifle (karabin)
				{
					format( string2, sizeof(string2), DIALOG_WMENU_BUY_CHECKOUT2_TXT,
					ItemName( 1, 27 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRifle] );
					format( string, sizeof(string), "%sWymagane czêœci:\n- szkielet broni karabinowej [%d/2]\n- zespó³ zamka karabinu [%d/1]\n- magazynek karabinu [%d/1]\n- sprê¿yna powrotna karabinu [%d/1]\n- kolba [%d/1]\n- komplet œrubek karabinu [%d/1]\n- skrzynka monta¿owa karabinu [%d/1]",
					string2,
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart1],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart2],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart3],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart4],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart5],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart6],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart]);
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_3_WEAPON_MAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Zmontuj", "Wróæ" );

					return 1;
				}
				else if (listitem == 10) // snajperka
				{
					format( string2, sizeof(string2), DIALOG_WMENU_BUY_CHECKOUT2_TXT,
					ItemName( 1, 28 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactorySRifle] );
					format( string, sizeof(string), "%sWymagane czêœci:\n- szkielet broni karabinowej [%d/3]\n- zespó³ zamka karabinu [%d/3]\n- magazynek karabinu [%d/2]\n- sprê¿yna powrotna karabinu [%d/2]\n- kolba [%d/2]\n- komplet œrubek karabinu [%d/2]\n- luneta [%d/1]\n- siatka maskuj¹ca [%d/1]",
					string2,
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart1],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart2],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart3],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart4],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart5],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart6],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart7],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactorySniperPart]);
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_3_WEAPON_MAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Zmontuj", "Wróæ" );

					return 1;
				}
			}
			else
			{
				ShowPlayerDialog( playerid, DIALOG_WMENU_1, DIALOG_STYLE_LIST, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_MAIN_TXT, "Wybierz", "Anuluj" );
				return 1;
			}
		}
		case DIALOG_WMENU_3_INFO:
		{
			if(response)
				ShowPlayerDialog( playerid, DIALOG_WMENU_1, DIALOG_STYLE_LIST, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_MAIN_TXT, "Wybierz", "Anuluj" );
			return 1;
		}
		case DIALOG_WMENU_3_WEAPON_MAKE:
		{
			if(response)
			{
				if( gPlayerData[playerid][pMountsLeft] != 0 )
				{
					ShowPlayerDialog( playerid, DIALOG_WMENU_3_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_3_WEAPON_INFO_TXT, "Wróæ", "" );
					return 1;
				}
				new slot, enough;
				if(gListItem[playerid] == 0) // 9mm
				{
					if( PlayerFreeSlotCount( playerid ) < 5 )
					{
						ShowPlayerDialog( playerid, DIALOG_WMENU_3_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_3_NO_SPACE_TXT, "Wróæ", "" );
						return 1;
					}
					if( !PlayerHaveWFItemsEx( playerid, WF_WEAPON, WF_9MM ) )
						goto nosparepart;
					SendClientMessage( playerid, COLOR_LIGHTYELLOW2, DIALOG_WMENU_GOTO1_TXT );
					SendClientMessage( playerid, COLOR_LIGHTYELLOW2, DIALOG_WMENU_GOTO2_TXT );
					gPlayerData[playerid][pPartType] = WF_WEAPON;
					gPlayerData[playerid][pPartItem] = WF_9MM;
					gPlayerData[playerid][pMountsLeft] = 5;
					gPlayerData[playerid][pMountsPasses] = WF_LPT;
					SavePlayerData( playerid, "PartType" );
					SavePlayerData( playerid, "PartItem" );
					SavePlayerData( playerid, "MountsLeft" );
					SavePlayerData( playerid, "MountsPasses" );
					return 1;
				}
				else if(gListItem[playerid] == 1) // 9mm tlumik
				{
					if( PlayerFreeSlotCount( playerid ) < 6 )
					{
						ShowPlayerDialog( playerid, DIALOG_WMENU_3_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_3_NO_SPACE_TXT, "Wróæ", "" );
						return 1;
					}
					#define P1COUNT1 1
					#define P1COUNT2 1
					#define P1COUNT3 1
					#define P1COUNT4 1
					#define P1COUNT5 1
					#define P1COUNT6 1
					if ( !( slot = PHaveItem( playerid, 1, 48 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart1] - P1COUNT1 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 48, 0, 0, 0, 0, "Puste", P1COUNT1 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart1] -= P1COUNT1;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolPart1" );
					}
					else
					{
						enough = P1COUNT1 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart1] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 48, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart1] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolPart1" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 49 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart2] - P1COUNT2 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 49, 0, 0, 0, 0, "Puste", P1COUNT2 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart2] -= P1COUNT2;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolPart2" );
					}
					else
					{
						enough = P1COUNT2 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart2] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 49, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart2] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolPart2" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 50 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart3] - P1COUNT3 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 50, 0, 0, 0, 0, "Puste", P1COUNT3 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart3] -= P1COUNT3;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolPart3" );
					}
					else
					{
						enough = P1COUNT3 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart3] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 50, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart3] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolPart3" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 51 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart4] - P1COUNT4 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 51, 0, 0, 0, 0, "Puste", P1COUNT4 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart4] -= P1COUNT4;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolPart4" );
					}
					else
					{
						enough = P1COUNT4 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart4] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 51, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart4] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolPart4" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 52 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart5] - P1COUNT5 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 52, 0, 0, 0, 0, "Puste", P1COUNT5 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart5] -= P1COUNT5;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolPart5" );
					}
					else
					{
						enough = P1COUNT5 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart5] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 52, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart5] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolPart5" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 59 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart6] - P1COUNT6 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 59, 0, 0, 0, 0, "Puste", P1COUNT6 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart6] -= P1COUNT6;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolPart6" );
					}
					else
					{
						enough = P1COUNT6 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart6] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 59, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart6] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolPart6" );
						}
					}
					SendClientMessage( playerid, COLOR_LIGHTYELLOW2, DIALOG_WMENU_GOTO1_TXT );
					SendClientMessage( playerid, COLOR_LIGHTYELLOW2, DIALOG_WMENU_GOTO2_TXT );
					gPlayerData[playerid][pPartType] = WF_WEAPON;
					gPlayerData[playerid][pPartItem] = WF_9MMSIL;
					gPlayerData[playerid][pMountsLeft] = 6;
					gPlayerData[playerid][pMountsPasses] = WF_LPT;
					SavePlayerData( playerid, "PartType" );
					SavePlayerData( playerid, "PartItem" );
					SavePlayerData( playerid, "MountsLeft" );
					SavePlayerData( playerid, "MountsPasses" );
					return 1;
				}
				else if(gListItem[playerid] == 2) // desert eagle
				{
					if( PlayerFreeSlotCount( playerid ) < 6 )
					{
						ShowPlayerDialog( playerid, DIALOG_WMENU_3_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_3_NO_SPACE_TXT, "Wróæ", "" );
						return 1;
					}
					#define P2COUNT1 1
					#define P2COUNT2 2
					#define P2COUNT3 2
					#define P2COUNT4 2
					#define P2COUNT5 1
					#define P2COUNT6 1
					if ( !(slot = PHaveItem( playerid, 1, 87 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryDesEaglePart] - P2COUNT6 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 87, 0, 0, 0, 0, "Puste", P2COUNT6 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryDesEaglePart] -= P2COUNT6;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryDesEaglePart" );
					}
					else
					{
						enough = P2COUNT6 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryDesEaglePart] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 87, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryDesEaglePart] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryDesEaglePart" );
						}
					}
					if ( !(slot = PHaveItem( playerid, 1, 48 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart1] - P2COUNT1 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 48, 0, 0, 0, 0, "Puste", P2COUNT1 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart1] -= P2COUNT1;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolPart1" );
					}
					else
					{
						enough = P2COUNT1 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart1] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 48, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart1] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolPart1" );
						}
					}
					if ( !(slot = PHaveItem( playerid, 1, 49 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart2] - P2COUNT2 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 49, 0, 0, 0, 0, "Puste", P2COUNT2 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart2] -= P2COUNT2;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolPart2" );
					}
					else
					{
						enough = P2COUNT2 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart2] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 49, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart2] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolPart2" );
						}
					}
					if ( !(slot = PHaveItem( playerid, 1, 50 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart3] - P2COUNT3 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 50, 0, 0, 0, 0, "Puste", P2COUNT3 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart3] -= P2COUNT3;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolPart3" );
					}
					else
					{
						enough = P2COUNT3 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart3] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 50, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart3] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolPart3" );
						}
					}
					if ( !(slot = PHaveItem( playerid, 1, 51 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart4] - P2COUNT4 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 51, 0, 0, 0, 0, "Puste", P2COUNT4 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart4] -= P2COUNT4;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolPart4" );
					}
					else
					{
						enough = P2COUNT4 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart4] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 51, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart4] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolPart4" );
						}
					}
					if ( !(slot = PHaveItem( playerid, 1, 52 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart5] - P2COUNT5 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 52, 0, 0, 0, 0, "Puste", P2COUNT5 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart5] -= P2COUNT5;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolPart5" );
					}
					else
					{
						enough = P2COUNT5 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart5] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 51, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart5] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolPart5" );
						}
					}
					SendClientMessage( playerid, COLOR_LIGHTYELLOW2, DIALOG_WMENU_GOTO1_TXT );
					SendClientMessage( playerid, COLOR_LIGHTYELLOW2, DIALOG_WMENU_GOTO2_TXT );
					gPlayerData[playerid][pPartType] = WF_WEAPON;
					gPlayerData[playerid][pPartItem] = WF_DESEAGLE;
					gPlayerData[playerid][pMountsLeft] = 6;
					gPlayerData[playerid][pMountsPasses] = WF_LPT;
					SavePlayerData( playerid, "PartType" );
					SavePlayerData( playerid, "PartItem" );
					SavePlayerData( playerid, "MountsLeft" );
					SavePlayerData( playerid, "MountsPasses" );
					return 1;
				}
				else if(gListItem[playerid] == 6) // shotgun
				{
					if( PlayerFreeSlotCount( playerid ) < 7 )
					{
						ShowPlayerDialog( playerid, DIALOG_WMENU_3_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_3_NO_SPACE_TXT, "Wróæ", "" );
						return 1;
					}
					#define P3COUNT1 3
					#define P3COUNT2 2
					#define P3COUNT3 2
					#define P3COUNT4 1
					#define P3COUNT5 1
					#define P3COUNT6 1
					#define P3COUNT7 1
					if ( !( slot = PHaveItem( playerid, 1, 86 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryShotPart] - P3COUNT7 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 86, 0, 0, 0, 0, "Puste", P3COUNT7 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryShotPart] -= P3COUNT7;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryShotPart" );
					}
					else
					{
						enough = P3COUNT7 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryShotPart] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 86, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryShotPart] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryShotPart" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 53 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart1] - P3COUNT1 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 53, 0, 0, 0, 0, "Puste", P3COUNT1 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart1] -= P3COUNT1;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflePart1" );
					}
					else
					{
						enough = P3COUNT1 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart1] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 53, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart1] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflelPart1" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 54 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart2] - P3COUNT2 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 54, 0, 0, 0, 0, "Puste", P3COUNT2 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart2] -= P3COUNT2;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflePart2" );
					}
					else
					{
						enough = P3COUNT2 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart2] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 54, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart2] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflePart2" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 55 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart3] - P3COUNT3 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 55, 0, 0, 0, 0, "Puste", P3COUNT3 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart3] -= P3COUNT3;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflePart3" );
					}
					else
					{
						enough = P3COUNT3 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart3] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 55, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart3] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflelPart3" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 56 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart4] - P3COUNT4 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 56, 0, 0, 0, 0, "Puste", P3COUNT4 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart4] -= P3COUNT4;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflePart4" );
					}
					else
					{
						enough = P3COUNT4 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart4] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 56, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart4] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflelPart4" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 57 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart5] - P3COUNT5 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 57, 0, 0, 0, 0, "Puste", P3COUNT5 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart5] -= P3COUNT5;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflePart5" );
					}
					else
					{
						enough = P3COUNT5 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart5] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 57, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart5] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflelPart5" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 58 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart6] - P3COUNT6 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 58, 0, 0, 0, 0, "Puste", P3COUNT6 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart6] -= P3COUNT6;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflePart6" );
					}
					else
					{
						enough = P3COUNT6 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart6] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 58, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart6] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflelPart6" );
						}
					}
					SendClientMessage( playerid, COLOR_LIGHTYELLOW2, DIALOG_WMENU_GOTO1_TXT );
					SendClientMessage( playerid, COLOR_LIGHTYELLOW2, DIALOG_WMENU_GOTO2_TXT );
					gPlayerData[playerid][pPartType] = WF_WEAPON;
					gPlayerData[playerid][pPartItem] = WF_SHOTGUN;
					gPlayerData[playerid][pMountsLeft] = 7;
					gPlayerData[playerid][pMountsPasses] = WF_HPT;
					SavePlayerData( playerid, "PartType" );
					SavePlayerData( playerid, "PartItem" );
					SavePlayerData( playerid, "MountsLeft" );
					SavePlayerData( playerid, "MountsPasses" );
					return 1;
				}
				else if(gListItem[playerid] == 3) // micro smg
				{
					if( PlayerFreeSlotCount( playerid ) < 5 )
					{
						ShowPlayerDialog( playerid, DIALOG_WMENU_3_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_3_NO_SPACE_TXT, "Wróæ", "" );
						return 1;
					}
					#define P4COUNT1 4
					#define P4COUNT2 4
					#define P4COUNT3 4
					#define P4COUNT4 1
					#define P4COUNT5 1
					if ( !( slot = PHaveItem( playerid, 1, 48 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart1] - P4COUNT1 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 48, 0, 0, 0, 0, "Puste", P4COUNT1 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart1] -= P4COUNT1;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolPart1" );
					}
					else
					{
						enough = P4COUNT1 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart1] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 48, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart1] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolPart1" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 49 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart2] - P4COUNT2 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 49, 0, 0, 0, 0, "Puste", P4COUNT2 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart2] -= P4COUNT2;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolPart2" );
					}
					else
					{
						enough = P4COUNT2 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart2] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 49, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart2] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolPart2" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 50 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart3] - P4COUNT3 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 50, 0, 0, 0, 0, "Puste", P4COUNT3 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart3] -= P4COUNT3;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolPart3" );
					}
					else
					{
						enough = P4COUNT3 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart3] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 50, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart3] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolPart3" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 51 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart4] - P4COUNT4 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 51, 0, 0, 0, 0, "Puste", P4COUNT4 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart4] -= P4COUNT4;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolPart4" );
					}
					else
					{
						enough = P4COUNT4 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart4] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 51, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart4] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolPart4" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 52 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart5] - P4COUNT5 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 52, 0, 0, 0, 0, "Puste", P4COUNT5 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart5] -= P4COUNT5;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolPart5" );
					}
					else
					{
						enough = P4COUNT5 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart5] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 52, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart5] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolPart5" );
						}
					}
					SendClientMessage( playerid, COLOR_LIGHTYELLOW2, DIALOG_WMENU_GOTO1_TXT );
					SendClientMessage( playerid, COLOR_LIGHTYELLOW2, DIALOG_WMENU_GOTO2_TXT );
					gPlayerData[playerid][pPartType] = WF_WEAPON;
					gPlayerData[playerid][pPartItem] = WF_MICROSMG;
					gPlayerData[playerid][pMountsLeft] = 5;
					gPlayerData[playerid][pMountsPasses] = WF_LPT;
					SavePlayerData( playerid, "PartType" );
					SavePlayerData( playerid, "PartItem" );
					SavePlayerData( playerid, "MountsLeft" );
					SavePlayerData( playerid, "MountsPasses" );
					return 1;
				}
				else if(gListItem[playerid] == 4) // mp5
				{
					if( PlayerFreeSlotCount( playerid ) < 7 )
					{
						ShowPlayerDialog( playerid, DIALOG_WMENU_3_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_3_NO_SPACE_TXT, "Wróæ", "" );
						return 1;
					}
					#define P5COUNT1 2
					#define P5COUNT2 2
					#define P5COUNT3 1
					#define P5COUNT4 1
					#define P5COUNT5 1
					#define P5COUNT6 1
					#define P5COUNT7 1
					if ( !( slot = PHaveItem( playerid, 1, 83 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryMP5Part] - P5COUNT7 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 83, 0, 0, 0, 0, "Puste", P5COUNT7 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryMP5Part] -= P5COUNT7;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryMP5Part" );
					}
					else
					{
						enough = P5COUNT7 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryMP5Part] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 83, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryMP5Part] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryMP5Part" );
						}
					}
					if ( !(slot = PHaveItem( playerid, 1, 53 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart1] - P5COUNT1 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 53, 0, 0, 0, 0, "Puste", P5COUNT1 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart1] -= P5COUNT1;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflePart1" );
					}
					else
					{
						enough = P5COUNT1 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart1] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 53, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart1] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflelPart1" );
						}
					}
					if ( !(slot = PHaveItem( playerid, 1, 54 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart2] - P5COUNT2 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 54, 0, 0, 0, 0, "Puste", P5COUNT2 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart2] -= P5COUNT2;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflePart2" );
					}
					else
					{
						enough = P5COUNT2 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart2] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 54, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart2] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflelPart2" );
						}
					}
					if ( !(slot = PHaveItem( playerid, 1, 55 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart3] - P5COUNT3 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 55, 0, 0, 0, 0, "Puste", P5COUNT3 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart3] -= P5COUNT3;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflePart3" );
					}
					else
					{
						enough = P5COUNT3 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart3] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 55, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart3] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflelPart3" );
						}
					}
					if ( !(slot = PHaveItem( playerid, 1, 56 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart4] - P5COUNT4 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 56, 0, 0, 0, 0, "Puste", P5COUNT4 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart4] -= P5COUNT4;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflePart4" );
					}
					else
					{
						enough = P5COUNT4 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart4] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 56, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart4] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflelPart4" );
						}
					}
					if ( !(slot = PHaveItem( playerid, 1, 57 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart5] - P5COUNT5 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 57, 0, 0, 0, 0, "Puste", P5COUNT5 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart5] -= P5COUNT5;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflePart5" );
					}
					else
					{
						enough = P5COUNT5 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart5] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 57, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart5] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflelPart5" );
						}
					}
					if ( !(slot = PHaveItem( playerid, 1, 58 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart6] - P5COUNT6 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 58, 0, 0, 0, 0, "Puste", P5COUNT6 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart6] -= P5COUNT6;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflePart6" );
					}
					else
					{
						enough = P5COUNT6 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart6] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 58, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart6] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflelPart6" );
						}
					}
					SendClientMessage( playerid, COLOR_LIGHTYELLOW2, DIALOG_WMENU_GOTO1_TXT );
					SendClientMessage( playerid, COLOR_LIGHTYELLOW2, DIALOG_WMENU_GOTO2_TXT );
					gPlayerData[playerid][pPartType] = WF_WEAPON;
					gPlayerData[playerid][pPartItem] = WF_MP5;
					gPlayerData[playerid][pMountsLeft] = 7;
					gPlayerData[playerid][pMountsPasses] = WF_HPT;
					SavePlayerData( playerid, "PartType" );
					SavePlayerData( playerid, "PartItem" );
					SavePlayerData( playerid, "MountsLeft" );
					SavePlayerData( playerid, "MountsPasses" );
					return 1;
				}
				else if(gListItem[playerid] == 7) // ak-47
				{
					if( PlayerFreeSlotCount( playerid ) < 7 )
					{
						ShowPlayerDialog( playerid, DIALOG_WMENU_3_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_3_NO_SPACE_TXT, "Wróæ", "" );
						return 1;
					}
					#define P6COUNT1 3
					#define P6COUNT2 2
					#define P6COUNT3 2
					#define P6COUNT4 1
					#define P6COUNT5 1
					#define P6COUNT6 1
					#define P6COUNT7 1
					if ( !( slot = PHaveItem( playerid, 1, 84 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAK47Part] - P6COUNT7 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 84, 0, 0, 0, 0, "Puste", P6COUNT7 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAK47Part] -= P6COUNT7;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryAK47Part" );
					}
					else
					{
						enough = P6COUNT7 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAK47Part] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 84, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAK47Part] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryAK47Part" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 53 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart1] - P6COUNT1 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 53, 0, 0, 0, 0, "Puste", P6COUNT1 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart1] -= P6COUNT1;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflePart1" );
					}
					else
					{
						enough = P6COUNT1 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart1] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 53, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart1] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflelPart1" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 54 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart2] - P6COUNT2 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 54, 0, 0, 0, 0, "Puste", P6COUNT2 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart2] -= P6COUNT2;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflePart2" );
					}
					else
					{
						enough = P6COUNT2 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart2] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 54, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart2] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflelPart2" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 55 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart3] - P6COUNT3 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 55, 0, 0, 0, 0, "Puste", P6COUNT3 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart3] -= P6COUNT3;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflePart3" );
					}
					else
					{
						enough = P6COUNT3 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart3] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 55, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart3] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflelPart3" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 56 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart4] - P6COUNT4 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 56, 0, 0, 0, 0, "Puste", P6COUNT4 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart4] -= P6COUNT4;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflePart4" );
					}
					else
					{
						enough = P6COUNT4 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart4] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 56, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart4] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflelPart4" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 57 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart5] - P6COUNT5 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 57, 0, 0, 0, 0, "Puste", P6COUNT5  );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart5] -= P6COUNT5 ;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflePart5" );
					}
					else
					{
						enough = P6COUNT5 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart5] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 57, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart5] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflelPart5" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 58 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart6] - P6COUNT6 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 58, 0, 0, 0, 0, "Puste", P6COUNT6 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart6] -= P6COUNT6;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflePart6" );
					}
					else
					{
						enough = P6COUNT6 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart6] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 58, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart6] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflelPart6" );
						}
					}
					SendClientMessage( playerid, COLOR_LIGHTYELLOW2, DIALOG_WMENU_GOTO1_TXT );
					SendClientMessage( playerid, COLOR_LIGHTYELLOW2, DIALOG_WMENU_GOTO2_TXT );
					gPlayerData[playerid][pPartType] = WF_WEAPON;
					gPlayerData[playerid][pPartItem] = WF_AK47;
					gPlayerData[playerid][pMountsLeft] = 7;
					gPlayerData[playerid][pMountsPasses] = WF_HPT;
					SavePlayerData( playerid, "PartType" );
					SavePlayerData( playerid, "PartItem" );
					SavePlayerData( playerid, "MountsLeft" );
					SavePlayerData( playerid, "MountsPasses" );
					return 1;
				}
				else if(gListItem[playerid] == 8) // m4
				{
					if( PlayerFreeSlotCount( playerid ) < 7 )
					{
						ShowPlayerDialog( playerid, DIALOG_WMENU_3_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_3_NO_SPACE_TXT, "Wróæ", "" );
						return 1;
					}
					#define P7COUNT1 3
					#define P7COUNT2 2
					#define P7COUNT3 2
					#define P7COUNT4 1
					#define P7COUNT5 1
					#define P7COUNT6 1
					#define P7COUNT7 1
					if ( !( slot = PHaveItem( playerid, 1, 85 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryM4Part] - P7COUNT7 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 85, 0, 0, 0, 0, "Puste", P7COUNT7 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryM4Part] -= P7COUNT7;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryM4Part" );
					}
					else
					{
						enough = P7COUNT7 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryM4Part] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 85, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryM4Part] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryM4Part" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 53 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart1] - P7COUNT1 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 53, 0, 0, 0, 0, "Puste", P7COUNT1 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart1] -= P7COUNT1;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflePart1" );
					}
					else
					{
						enough = P7COUNT1 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart1] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 53, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart1] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflelPart1" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 54 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart2] - P7COUNT2 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 54, 0, 0, 0, 0, "Puste", P7COUNT2 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart2] -= P7COUNT2;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflePart2" );
					}
					else
					{
						enough = P7COUNT2 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart2] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 54, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart2] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflelPart2" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 55 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart3] - P7COUNT3 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 55, 0, 0, 0, 0, "Puste", P7COUNT3 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart3] -= P7COUNT3;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflePart3" );
					}
					else
					{
						enough = P7COUNT3 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart3] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 55, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart3] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflelPart3" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 56 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart4] - P7COUNT4 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 56, 0, 0, 0, 0, "Puste", P7COUNT4 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart4] -= P7COUNT4;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflePart4" );
					}
					else
					{
						enough = P7COUNT4 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart4] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 56, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart4] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflelPart4" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 57 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart5] - P7COUNT5 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 57, 0, 0, 0, 0, "Puste", P7COUNT5 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart5] -= P7COUNT5;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflePart5" );
					}
					else
					{
						enough = P7COUNT5 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart5] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 57, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart5] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflelPart5" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 58 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart6] - P7COUNT6 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 58, 0, 0, 0, 0, "Puste", P7COUNT6 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart6] -= P7COUNT6;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflePart6" );
					}
					else
					{
						enough = P7COUNT6 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart6] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 58, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart6] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflelPart6" );
						}
					}
					SendClientMessage( playerid, COLOR_LIGHTYELLOW2, DIALOG_WMENU_GOTO1_TXT );
					SendClientMessage( playerid, COLOR_LIGHTYELLOW2, DIALOG_WMENU_GOTO2_TXT );
					gPlayerData[playerid][pPartType] = WF_WEAPON;
					gPlayerData[playerid][pPartItem] = WF_M4;
					gPlayerData[playerid][pMountsLeft] = 7;
					gPlayerData[playerid][pMountsPasses] = WF_HPT;
					SavePlayerData( playerid, "PartType" );
					SavePlayerData( playerid, "PartItem" );
					SavePlayerData( playerid, "MountsLeft" );
					SavePlayerData( playerid, "MountsPasses" );
					return 1;
				}
				else if(gListItem[playerid] == 5) // tec9
				{
					if( PlayerFreeSlotCount( playerid ) < 7 )
					{
						ShowPlayerDialog( playerid, DIALOG_WMENU_3_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_3_NO_SPACE_TXT, "Wróæ", "" );
						return 1;
					}
					#define P8COUNT1 3
					#define P8COUNT2 2
					#define P8COUNT3 2
					#define P8COUNT4 1
					#define P8COUNT5 1
					#define P8COUNT6 1
					#define P8COUNT7 1
					if ( !( slot = PHaveItem( playerid, 1, 82 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryTec9Part] - P8COUNT7 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 82, 0, 0, 0, 0, "Puste", P8COUNT7 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryTec9Part] -= P8COUNT7;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryTec9Part" );
					}
					else
					{
						enough = P8COUNT7 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryTec9Part] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 82, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryTec9Part] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryTec9Part" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 48 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart1] - P8COUNT1 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 48, 0, 0, 0, 0, "Puste", P8COUNT1 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart1] -= P8COUNT1;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolPart1" );
					}
					else
					{
						enough = P8COUNT1 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart1] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 48, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart1] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolPart1" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 49 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart2] - P8COUNT2 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 49, 0, 0, 0, 0, "Puste", P8COUNT2 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart2] -= P8COUNT2;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolPart2" );
					}
					else
					{
						enough = P8COUNT2 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart2] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 49, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart2] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolPart2" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 50 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart3] - P8COUNT3 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 50, 0, 0, 0, 0, "Puste", P8COUNT3 );							
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart3] -= P8COUNT3;	
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolPart3" );
					}
					else
					{
						enough = P8COUNT3 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart3] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 50, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart3] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolPart3" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 51 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart4] - P8COUNT4 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 51, 0, 0, 0, 0, "Puste", P8COUNT4 );													
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart4] -= P8COUNT4;	
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolPart4" );
					}
					else
					{
						enough = P8COUNT4 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart4] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 51, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart4] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolPart4" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 52 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart5] - P8COUNT5 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 52, 0, 0, 0, 0, "Puste", P8COUNT5 );						
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart5] -= P8COUNT5;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolPart5" );
					}
					else
					{
						enough = P8COUNT5 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart5] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 52, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart5] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolPart5" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 59 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart6] - P8COUNT6 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 59, 0, 0, 0, 0, "Puste", P8COUNT6 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart6] -= P8COUNT6;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolPart6" );
					}
					else
					{
						enough = P8COUNT6 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart6] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 59, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart6] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolPart6" );
						}
					}
					SendClientMessage( playerid, COLOR_LIGHTYELLOW2, DIALOG_WMENU_GOTO1_TXT );
					SendClientMessage( playerid, COLOR_LIGHTYELLOW2, DIALOG_WMENU_GOTO2_TXT );
					gPlayerData[playerid][pPartType] = WF_WEAPON;
					gPlayerData[playerid][pPartItem] = WF_TEC9;
					gPlayerData[playerid][pMountsLeft] = 7;
					gPlayerData[playerid][pMountsPasses] = WF_LPT;
					SavePlayerData( playerid, "PartType" );
					SavePlayerData( playerid, "PartItem" );
					SavePlayerData( playerid, "MountsLeft" );
					SavePlayerData( playerid, "MountsPasses" );
					return 1;
				}
				else if(gListItem[playerid] == 9) // country rifle (karabin)
				{
					if( PlayerFreeSlotCount( playerid ) < 7 )
					{
						ShowPlayerDialog( playerid, DIALOG_WMENU_3_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_3_NO_SPACE_TXT, "Wróæ", "" );
						return 1;
					}
					#define P9COUNT1 2
					#define P9COUNT2 1
					#define P9COUNT3 1
					#define P9COUNT4 1
					#define P9COUNT5 1
					#define P9COUNT6 1
					#define P9COUNT7 1
					if ( !( slot = PHaveItem( playerid, 1, 88 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart] - P9COUNT7 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 88, 0, 0, 0, 0, "Puste", P9COUNT7 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart] -= P9COUNT7;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflePart1" );
					}
					else
					{
						enough = P9COUNT7 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 88, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflelPart" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 53 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart1] - P9COUNT1 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 53, 0, 0, 0, 0, "Puste", P9COUNT1 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart1] -= P9COUNT1;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflePart1" );
					}
					else
					{
						enough = P9COUNT1 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart1] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 53, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart1] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflelPart1" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 54 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart2] - P9COUNT2 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 54, 0, 0, 0, 0, "Puste", P9COUNT2 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart2] -= P9COUNT2;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflePart2" );
					}
					else
					{
						enough = P9COUNT2 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart2] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 54, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart2] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflelPart2" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 55 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart3] - P9COUNT3 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 55, 0, 0, 0, 0, "Puste", P9COUNT3 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart3] -= P9COUNT3;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflePart3" );
					}
					else
					{
						enough = P9COUNT3 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart3] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 55, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart3] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflelPart3" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 56 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart4] - P9COUNT4 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 56, 0, 0, 0, 0, "Puste", P9COUNT4 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart4] -= P9COUNT4;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflePart4" );
					}
					else
					{
						enough = P9COUNT4 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart4] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 56, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart4] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflelPart4" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 57 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart5] - P9COUNT5 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 57, 0, 0, 0, 0, "Puste", P9COUNT5 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart5] -= P9COUNT5;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflePart5" );
					}
					else
					{
						enough = P9COUNT5 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart5] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 57, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart5] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflelPart5" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 58 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart6] - P9COUNT6 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 58, 0, 0, 0, 0, "Puste", P9COUNT6 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart6] -= P9COUNT6;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflePart6" );
					}
					else
					{
						enough = P9COUNT6 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart6] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 58, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart6] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflelPart6" );
						}
					}
					SendClientMessage( playerid, COLOR_LIGHTYELLOW2, DIALOG_WMENU_GOTO1_TXT );
					SendClientMessage( playerid, COLOR_LIGHTYELLOW2, DIALOG_WMENU_GOTO2_TXT );
					gPlayerData[playerid][pPartType] = WF_WEAPON;
					gPlayerData[playerid][pPartItem] = WF_RIFLE;
					gPlayerData[playerid][pMountsLeft] = 7;
					gPlayerData[playerid][pMountsPasses] = WF_HPT;
					SavePlayerData( playerid, "PartType" );
					SavePlayerData( playerid, "PartItem" );
					SavePlayerData( playerid, "MountsLeft" );
					SavePlayerData( playerid, "MountsPasses" );
					return 1;
				}
				else if(gListItem[playerid] == 10) // snajperka
				{
					if( PlayerFreeSlotCount( playerid ) < 8 )
					{
						ShowPlayerDialog( playerid, DIALOG_WMENU_3_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_3_NO_SPACE_TXT, "Wróæ", "" );
						return 1;
					}
					#define P10COUNT1 3
					#define P10COUNT2 3
					#define P10COUNT3 2
					#define P10COUNT4 2
					#define P10COUNT5 2
					#define P10COUNT6 2
					#define P10COUNT7 1
					#define P10COUNT8 1
					if ( !( slot = PHaveItem( playerid, 1, 89 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactorySniperPart] - P10COUNT8 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 89, 0, 0, 0, 0, "Puste", P10COUNT8 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactorySniperPart] -= P10COUNT8;
						SaveFData( gPlayerData[playerid][pFaction], "WFactorySniperPart" );
					}
					else
					{
						enough = P10COUNT8 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactorySniperPart] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 89, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactorySniperPart] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactorySniperPart" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 53 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart1] - P10COUNT1 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 53, 0, 0, 0, 0, "Puste", P10COUNT1 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart1] -= P10COUNT1;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflePart1" );
					}
					else
					{
						enough = P10COUNT1 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart1] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 53, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart1] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflelPart1" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 54 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart2] - P10COUNT2 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 54, 0, 0, 0, 0, "Puste", P10COUNT2 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart2] -= P10COUNT2;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflePart2" );
					}
					else
					{
						enough = P10COUNT2 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart2] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 54, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart2] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflelPart2" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 55 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart3] - P10COUNT3 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 55, 0, 0, 0, 0, "Puste", P10COUNT3 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart3] -= P10COUNT3;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflePart3" );
					}
					else
					{
						enough = P10COUNT3 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart3] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 55, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart3] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflelPart3" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 56 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart4] - P10COUNT4 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 56, 0, 0, 0, 0, "Puste", P10COUNT4 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart4] -= P10COUNT4;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflePart4" );
					}
					else
					{
						enough = P10COUNT4 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart4] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 56, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart4] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflelPart4" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 57 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart5] - P10COUNT5 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 57, 0, 0, 0, 0, "Puste", P10COUNT5 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart5] -= P10COUNT5;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflePart5" );
					}
					else
					{
						enough = P10COUNT5 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart5] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 57, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart5] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflelPart5" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 58 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart6] - P10COUNT6 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 58, 0, 0, 0, 0, "Puste", P10COUNT6 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart6] -= P10COUNT6;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflePart6" );
					}
					else
					{
						enough = P10COUNT6 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart6] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 58, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart6] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflelPart6" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 60 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart7] - P10COUNT7 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 60, 0, 0, 0, 0, "Puste", P10COUNT7 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart7] -= P10COUNT7;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflePart7" );
					}
					else
					{
						enough = P10COUNT7 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart7] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 60, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart7] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflelPart6" );
						}
					}
					SendClientMessage( playerid, COLOR_LIGHTYELLOW2, DIALOG_WMENU_GOTO1_TXT );
					SendClientMessage( playerid, COLOR_LIGHTYELLOW2, DIALOG_WMENU_GOTO2_TXT );
					gPlayerData[playerid][pPartType] = WF_WEAPON;
					gPlayerData[playerid][pPartItem] = WF_SRIFLE;
					gPlayerData[playerid][pMountsLeft] = 8;
					gPlayerData[playerid][pMountsPasses] = WF_HPT;
					SavePlayerData( playerid, "PartType" );
					SavePlayerData( playerid, "PartItem" );
					SavePlayerData( playerid, "MountsLeft" );
					SavePlayerData( playerid, "MountsPasses" );
					return 1;
				}
				nosparepart:
				#undef P1COUNT1
				#undef P1COUNT2
				#undef P1COUNT3
				#undef P1COUNT4
				#undef P1COUNT5
				#undef P1COUNT6
				#undef P2COUNT1
				#undef P2COUNT2
				#undef P2COUNT3
				#undef P2COUNT4
				#undef P2COUNT5
				#undef P2COUNT6
				#undef P3COUNT1
				#undef P3COUNT2
				#undef P3COUNT3
				#undef P3COUNT4
				#undef P3COUNT5
				#undef P3COUNT6
				#undef P3COUNT7
				#undef P4COUNT1
				#undef P4COUNT2
				#undef P4COUNT3
				#undef P4COUNT4
				#undef P4COUNT5 
				#undef P5COUNT1
				#undef P5COUNT2
				#undef P5COUNT3
				#undef P5COUNT4
				#undef P5COUNT5
				#undef P5COUNT6
				#undef P5COUNT7
				#undef P6COUNT1
				#undef P6COUNT2
				#undef P6COUNT3
				#undef P6COUNT4
				#undef P6COUNT5
				#undef P6COUNT6
				#undef P6COUNT7
				#undef P7COUNT1
				#undef P7COUNT2
				#undef P7COUNT3
				#undef P7COUNT4
				#undef P7COUNT5
				#undef P7COUNT6
				#undef P7COUNT7
				#undef P8COUNT1
				#undef P8COUNT2
				#undef P8COUNT3
				#undef P8COUNT4
				#undef P8COUNT5
				#undef P8COUNT6
				#undef P9COUNT1
				#undef P9COUNT2
				#undef P9COUNT3
				#undef P9COUNT4
				#undef P9COUNT5
				#undef P9COUNT6
				#undef P9COUNT7
				#undef P10COUNT1
				#undef P10COUNT2
				#undef P10COUNT3
				#undef P10COUNT4
				#undef P10COUNT5
				#undef P10COUNT6
				#undef P10COUNT7
				#undef P10COUNT8
				ShowPlayerDialog( playerid, DIALOG_WMENU_NOSPAREPART, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_NOSPAREPART_TXT, "Wróæ", "" );
				return 1;
			}
			else
			{
				format( string, sizeof(string),
				DIALOG_WMENU_W_LIST_TXT,
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactory9MM],
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactory9MMSil],
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryDesEagle],
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryMicroSMG],
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryMP5],
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryTec9],
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryShotgun],
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAK47],
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryM4],
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRifle],
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactorySRifle],
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactorySCharge]);
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_2_WEAPON, DIALOG_STYLE_LIST, DIALOG_WMENU_TITLE_TXT, string, "Wybierz", "Wróæ" );
				
				return 1;
			}
		}
		case DIALOG_WMENU_2_AMMO:
		{
			if(response)
			{
				gListItem[playerid] = listitem;
				if (listitem == 0) // nabój 9mm
				{
					format( string2, sizeof(string2), DIALOG_WMENU_BUY_CHECKOUT2_TXT,
					ItemName( 1, 36 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactory9MMAmmo] );
					format( string, sizeof(string), "%sWymagane czêœci:\n- pocisk [%d/1]\n- ³uska [%d/1]\n- proch admidowy [%d/1]\n- sp³onka [%d/1]",
					string2,
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart1a],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart2a],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart3a],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart4a] );
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_3_AMMO_MAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Zmontuj", "Wróæ" );

					return 1;
				}
				if (listitem == 1) // nabój .50 AE
				{
					format( string2, sizeof(string2), DIALOG_WMENU_BUY_CHECKOUT2_TXT,
					ItemName( 1, 37 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactory50AEAmmo] );
					format( string, sizeof(string), "%sWymagane czêœci:\n- pocisk [%d/10]\n- ³uska [%d/5]\n- proch ignis volatilis [%d/2]\n- sp³onka [%d/2]",
					string2,
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart1e],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart2e],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart3e],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart4e] );
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_3_AMMO_MAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Zmontuj", "Wróæ" );

					return 1;
				}
				if (listitem == 2) // œrut
				{
					format( string2, sizeof(string2), DIALOG_WMENU_BUY_CHECKOUT2_TXT,
					ItemName( 1, 38 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryBuckshot] );
					format( string, sizeof(string), "%sWymagane czêœci:\n- o³ów [%d/6]\n- ³uska [%d/1]\n- proch œwiszcz¹cy [%d/2]\n- sp³onka [%d/2]",
					string2,
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart1b],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart2b],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart3b],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart4b] );
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_3_AMMO_MAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Zmontuj", "Wróæ" );

					return 1;
				}
				if (listitem == 3) // nabój 7.62
				{
					format( string2, sizeof(string2), DIALOG_WMENU_BUY_CHECKOUT2_TXT,
					ItemName( 1, 39 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactory762MMAmmo] );
					format( string, sizeof(string), "%sWymagane czêœci:\n- pocisk [%d/4]\n- ³uska [%d/2]\n- proch czarny [%d/2]\n- sp³onka [%d/2]",
					string2,
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart1c],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart2c],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart3c],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart4c] );
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_3_AMMO_MAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Zmontuj", "Wróæ" );

					return 1;
				}
				if (listitem == 4) // nabój 12.7mm
				{
					format( string2, sizeof(string2), DIALOG_WMENU_BUY_CHECKOUT2_TXT,
					ItemName( 1, 40 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactory127MMAmmo] );
					format( string, sizeof(string), "%sWymagane czêœci:\n- pocisk [%d/4]\n- ³uska [%d/2]\n- proch czarny [%d/2]\n- sp³onka [%d/2]",
					string2,
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart1d],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart2d],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart3d],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart4d] );
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_3_AMMO_MAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Zmontuj", "Wróæ" );

					return 1;
				}
			}
			else
			{
				ShowPlayerDialog( playerid, DIALOG_WMENU_1, DIALOG_STYLE_LIST, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_MAIN_TXT, "Wybierz", "Anuluj" );
				return 1;
			}
		}
		case DIALOG_WMENU_3_AMMO_MAKE:
		{
			if(response)
			{
				if( gPlayerData[playerid][pMountsLeft] != 0 )
				{
					ShowPlayerDialog( playerid, DIALOG_WMENU_3_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_3_WEAPON_INFO_TXT, "Wróæ", "" );
					return 1;
				}
				new slot, enough;
				if (gListItem[playerid] == 0) // nabój 9mm
				{
					if( PlayerFreeSlotCount( playerid ) < 4 )
					{
						ShowPlayerDialog( playerid, DIALOG_WMENU_3_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_3_NO_SPACE_TXT, "Wróæ", "" );
						return 1;
					}
					if ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart1a] >= 1 &&
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart2a] >= 1 &&
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart3a] >= 1 &&
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart4a] >= 1 )
					{
						if( !PHaveItem( playerid, 1, 43 ) )
						{
							InsertPlayerItemEx( playerid, 1, 43, 0, 0, 0, 0, "Puste", 1 );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart1a] -= 1;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryAmmoPart1a" );
						}
						if( !PHaveItem( playerid, 1, 44 ) )
						{
							InsertPlayerItemEx( playerid, 1, 44, 0, 0, 0, 0, "Puste", 1 );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart2a] -= 1;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryAmmoPart2a" );
						}
						if( !PHaveItem( playerid, 1, 45 ) )
						{
							InsertPlayerItemEx( playerid, 1, 45, 0, 0, 0, 0, "Puste", 1 );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart3a] -= 1;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryAmmoPart3a" );
						}
						if( !PHaveItem( playerid, 1, 46 ) )
						{
							InsertPlayerItemEx( playerid, 1, 46, 0, 0, 0, 0, "Puste", 1 );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart4a] -= 1;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryAmmoPart4a" );
						}
						SendClientMessage( playerid, COLOR_LIGHTYELLOW2, DIALOG_WMENU_GOTO1_TXT );
						SendClientMessage( playerid, COLOR_LIGHTYELLOW2, DIALOG_WMENU_GOTO2_TXT );
						gPlayerData[playerid][pPartType] = WF_AMMO;
						gPlayerData[playerid][pPartItem] = WF_9MMAMMO;
						gPlayerData[playerid][pMountsLeft] = 4;
						gPlayerData[playerid][pMountsPasses] = WF_AMMOT;
						SavePlayerData( playerid, "PartType" );
						SavePlayerData( playerid, "PartItem" );
						SavePlayerData( playerid, "MountsLeft" );
						SavePlayerData( playerid, "MountsPasses" );
						return 1;
					}
				}
				else if (gListItem[playerid] == 1) // nabój .50 AE
				{
					if( PlayerFreeSlotCount( playerid ) < 4 )
					{
						ShowPlayerDialog( playerid, DIALOG_WMENU_3_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_3_NO_SPACE_TXT, "Wróæ", "" );
						return 1;
					}
					#define P1COUNT1 10
					#define P1COUNT2 5
					#define P1COUNT3 2
					#define P1COUNT4 2
					if( !( slot = PHaveItem( playerid, 1, 101 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart1e] - P1COUNT1 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 101, 0, 0, 0, 0, "Puste", P1COUNT1 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart1e] -= P1COUNT1;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryAmmoPart1e" );
					}
					else
					{
						enough = P1COUNT1 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart1e] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 101, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart1e] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryAmmoPart1e" );
						}
					}
					if( !( slot = PHaveItem( playerid, 1, 102 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart2e] - P1COUNT2 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 102, 0, 0, 0, 0, "Puste", P1COUNT2 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart2e] -= P1COUNT2;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryAmmoPart2e" );
					}
					else
					{
						enough = P1COUNT2 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart2e] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 102, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart2e] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryAmmoPart2e" );
						}
					}
					if( !( slot = PHaveItem( playerid, 1, 103 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart3e] - P1COUNT3 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 103, 0, 0, 0, 0, "Puste", P1COUNT3 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart3e] -= P1COUNT3;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryAmmoPart3e" );
					}
					else
					{
						enough = P1COUNT3 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart3e] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 103, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart3e] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryAmmoPart3e" );
						}
					}
					if( !( slot = PHaveItem( playerid, 1, 104 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart4e] - P1COUNT4 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 104, 0, 0, 0, 0, "Puste", P1COUNT4 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart4e] -= P1COUNT4;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryAmmoPart4e" );
					}
					else
					{
						enough = P1COUNT4 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart4e] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 104, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart4e] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryAmmoPart4e" );
						}
					}
					SendClientMessage( playerid, COLOR_LIGHTYELLOW2, DIALOG_WMENU_GOTO1_TXT );
					SendClientMessage( playerid, COLOR_LIGHTYELLOW2, DIALOG_WMENU_GOTO2_TXT );
					gPlayerData[playerid][pPartType] = WF_AMMO;
					gPlayerData[playerid][pPartItem] = WF_50AEAMMO;
					gPlayerData[playerid][pMountsLeft] = 4;
					gPlayerData[playerid][pMountsPasses] = WF_AMMOT;
					SavePlayerData( playerid, "PartType" );
					SavePlayerData( playerid, "PartItem" );
					SavePlayerData( playerid, "MountsLeft" );
					SavePlayerData( playerid, "MountsPasses" );
					return 1;
				}
				else if (gListItem[playerid] == 2) // œrut
				{
					if( PlayerFreeSlotCount( playerid ) < 4 )
					{
						ShowPlayerDialog( playerid, DIALOG_WMENU_3_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_3_NO_SPACE_TXT, "Wróæ", "" );
						return 1;
					}
					#define P2COUNT1 6
					#define P2COUNT2 1
					#define P2COUNT3 2
					#define P2COUNT4 2
					if( !( slot = PHaveItem( playerid, 1, 47 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart1b] - P2COUNT1 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 47, 0, 0, 0, 0, "Puste", P2COUNT1 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart1b] -= P2COUNT1;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryAmmoPart1b" );
					}
					else
					{
						enough = P2COUNT1 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart1b] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 47, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart1b] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryAmmoPart1b" );
						}
					}
					if( !( slot = PHaveItem( playerid, 1, 90 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart2b] - P2COUNT2 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 90, 0, 0, 0, 0, "Puste", P2COUNT2 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart2b] -= P2COUNT2;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryAmmoPart2b" );
					}
					else
					{
						enough = P2COUNT2 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart2b] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 90, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart2b] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryAmmoPart2b" );
						}
					}
					if( !( slot = PHaveItem( playerid, 1, 91 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart3b] - P2COUNT3 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 91, 0, 0, 0, 0, "Puste", P2COUNT3 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart3b] -= P2COUNT3;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryAmmoPart3b" );
					}
					else
					{
						enough = P2COUNT3 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart3b] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 91, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart3b] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryAmmoPart3b" );
						}
					}
					if( !( slot = PHaveItem( playerid, 1, 92 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart4b] - P2COUNT4 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 92, 0, 0, 0, 0, "Puste", P2COUNT4 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart4b] -= P2COUNT4;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryAmmoPart4b" );
					}
					else
					{
						enough = P2COUNT4 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart4b] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 92, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart4b] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryAmmoPart4b" );
						}
					}
					SendClientMessage( playerid, COLOR_LIGHTYELLOW2, DIALOG_WMENU_GOTO1_TXT );
					SendClientMessage( playerid, COLOR_LIGHTYELLOW2, DIALOG_WMENU_GOTO2_TXT );
					gPlayerData[playerid][pPartType] = WF_AMMO;
					gPlayerData[playerid][pPartItem] = WF_BUCKSHOT;
					gPlayerData[playerid][pMountsLeft] = 4;
					gPlayerData[playerid][pMountsPasses] = WF_AMMOT;
					SavePlayerData( playerid, "PartType" );
					SavePlayerData( playerid, "PartItem" );
					SavePlayerData( playerid, "MountsLeft" );
					SavePlayerData( playerid, "MountsPasses" );
					return 1;
				}
				else if (gListItem[playerid] == 3) // nabój 7.62
				{
					if( PlayerFreeSlotCount( playerid ) < 4 )
					{
						ShowPlayerDialog( playerid, DIALOG_WMENU_3_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_3_NO_SPACE_TXT, "Wróæ", "" );
						return 1;
					}
					#define P3COUNT1 4
					#define P3COUNT2 2
					#define P3COUNT3 2
					#define P3COUNT4 2
					if( !PHaveItem( playerid, 1, 93 ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart1c] - P3COUNT1 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 93, 0, 0, 0, 0, "Puste", P3COUNT1 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart1c] -= P3COUNT1;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryAmmoPart1c" );
					}
					else
					{
						enough = P3COUNT1 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart1c] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 93, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart1c] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryAmmoPart1c" );
						}
					}
					if( !PHaveItem( playerid, 1, 94 ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart2c] - P3COUNT2 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 94, 0, 0, 0, 0, "Puste", P3COUNT2 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart2c] -= P3COUNT2;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryAmmoPart2c" );
					}
					else
					{
						enough = P3COUNT2 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart2c] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 94, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart2c] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryAmmoPart2c" );
						}
					}
					if( !PHaveItem( playerid, 1, 95 ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart3c] - P3COUNT3 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 95, 0, 0, 0, 0, "Puste", P3COUNT3 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart3c] -= P3COUNT3;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryAmmoPart3c" );
					}
					else
					{
						enough = P3COUNT3 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart3c] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 95, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart3c] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryAmmoPart3c" );
						}
					}
					if( !PHaveItem( playerid, 1, 96 ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart3c] - P3COUNT4 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 96, 0, 0, 0, 0, "Puste", P3COUNT4 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart4c] -= P3COUNT4;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryAmmoPart4c" );
					}
					else
					{
						enough = P3COUNT4 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart4c] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 96, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart4c] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryAmmoPart4c" );
						}
					}
					SendClientMessage( playerid, COLOR_LIGHTYELLOW2, DIALOG_WMENU_GOTO1_TXT );
					SendClientMessage( playerid, COLOR_LIGHTYELLOW2, DIALOG_WMENU_GOTO2_TXT );
					gPlayerData[playerid][pPartType] = WF_AMMO;
					gPlayerData[playerid][pPartItem] = WF_762MMAMMO;
					gPlayerData[playerid][pMountsLeft] = 4;
					gPlayerData[playerid][pMountsPasses] = WF_AMMOT;
					SavePlayerData( playerid, "PartType" );
					SavePlayerData( playerid, "PartItem" );
					SavePlayerData( playerid, "MountsLeft" );
					SavePlayerData( playerid, "MountsPasses" );
					return 1;
				}
				else if (gListItem[playerid] == 4) // nabój 12.7
				{
					if( PlayerFreeSlotCount( playerid ) < 4 )
					{
						ShowPlayerDialog( playerid, DIALOG_WMENU_3_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_3_NO_SPACE_TXT, "Wróæ", "" );
						return 1;
					}
					#define P4COUNT1 4
					#define P4COUNT2 2
					#define P4COUNT3 2
					#define P4COUNT4 2
					if( !PHaveItem( playerid, 1, 97 ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart1d] - P4COUNT1 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 97, 0, 0, 0, 0, "Puste", P4COUNT1 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart1d] -= P4COUNT1;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryAmmoPart1d" );
					}
					else
					{
						enough = P4COUNT1 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart1d] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 97, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart1d] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryAmmoPart1d" );
						}
					}
					if( !PHaveItem( playerid, 1, 98 ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart2d] - P4COUNT2 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 98, 0, 0, 0, 0, "Puste", P4COUNT2 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart2d] -= P4COUNT2;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryAmmoPart2d" );
					}
					else
					{
						enough = P4COUNT2 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart2d] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 98, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart2d] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryAmmoPart2d" );
						}
					}
					if( !PHaveItem( playerid, 1, 99 ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart3d] - P4COUNT3 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 99, 0, 0, 0, 0, "Puste", P4COUNT3 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart3d] -= P4COUNT3;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryAmmoPart3d" );
					}
					else
					{
						enough = P4COUNT3 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart3d] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 99, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart3d] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryAmmoPart3d" );
						}
					}
					if( !PHaveItem( playerid, 1, 100 ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart4d] - P4COUNT4 ) < 0 )
							goto nosparepart;
						InsertPlayerItemEx( playerid, 1, 100, 0, 0, 0, 0, "Puste", P4COUNT4 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart4d] -= P4COUNT4;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryAmmoPart4d" );
					}
					else
					{
						enough = P4COUNT4 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart4d] - enough) < 0 )
							goto nosparepart;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 99, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart4d] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryAmmoPart4d" );
						}
					}
					SendClientMessage( playerid, COLOR_LIGHTYELLOW2, DIALOG_WMENU_GOTO1_TXT );
					SendClientMessage( playerid, COLOR_LIGHTYELLOW2, DIALOG_WMENU_GOTO2_TXT );
					gPlayerData[playerid][pPartType] = WF_AMMO;
					gPlayerData[playerid][pPartItem] = WF_127MMAMMO;
					gPlayerData[playerid][pMountsLeft] = 4;
					gPlayerData[playerid][pMountsPasses] = WF_AMMOT;
					SavePlayerData( playerid, "PartType" );
					SavePlayerData( playerid, "PartItem" );
					SavePlayerData( playerid, "MountsLeft" );
					SavePlayerData( playerid, "MountsPasses" );
					return 1;
				}
				nosparepart:
				ShowPlayerDialog( playerid, DIALOG_WMENU_3_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_NOSPAREPART_TXT, "Wróæ", "" );
				return 1;
			}
			else
			{
				format( string, sizeof(string),
				"1. Nabój 9mm [%d]\n2. Nabój .50 AE [%d]\n3. Œrut [%d]\n4. Nabój 7.62mm [%d]\n5. Nabój 12.7 [%d]",
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactory9MMAmmo],
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactory50AEAmmo],
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryBuckshot],
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactory762MMAmmo],
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactory127MMAmmo]);
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_2_AMMO, DIALOG_STYLE_LIST, DIALOG_WMENU_TITLE_TXT, string, "Wybierz", "Wróæ" );
				
				return 1;
			}
		}
		case DIALOG_WMENU_2_PARTS:
		{
			if(response)
			{
				if(listitem == 0)
				{
					format( string3, sizeof(string3),
					"34. Zestaw monta¿owy Tec9 [%d]\n35. Skrzynka monta¿owa MP5 [%d]\n36. Zestaw monta¿owy AK-47 [%d]\n37. Skrzynka montazowa M4 [%d]\n38. Rêkojeœæ prze³adowania [%d]\n39. Skrzynka monta¿owa karabinu [%d]\n40. Siatka maskuj¹ca [%d]\n41.Carbon [%d]",
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryTec9Part],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryMP5Part],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAK47Part],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryM4Part],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryShotPart],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactorySniperPart],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryDesEaglePart]);
					
					format( string2, sizeof(string2),
					"20. Proch œwiszcz¹cy [%d]\n21. Sp³onka do strzelby [%d]\n22. Pocisk 7.62mm [%d]\n23. £uska 7.62mm [%d]\n24. Proch czarny [%d]\n25. Sp³onka 7.62 [%d]\n26. Pocisk 12.7mm [%d]\n27. £uska 12.7mm [%d]\n28. Proch bobinit [%d]\n29. Sp³onka 12.7mm [%d]\n30. Pocisk .50AE [%d]\n31. £uska .50AE [%d]\n32. Proch ignis volatilis [%d]\n33. Sp³onka .50AE [%d]",
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryAmmoPart3b],
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryAmmoPart4b],
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryAmmoPart1c],
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryAmmoPart2c],
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryAmmoPart3c],
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryAmmoPart4c],
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryAmmoPart1d],
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryAmmoPart2d],
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryAmmoPart3d],
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryAmmoPart4d],
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryAmmoPart1e],
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryAmmoPart2e],
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryAmmoPart3e],
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryAmmoPart4e] );
					
					format( string, sizeof(string),
					"1. Szkielet broni [%d]\n2. Zespó³ zamka [%d]\n3. Magazynek [%d]\n4. Sprê¿yna powrotna [%d]\n5. Komplet œrubek [%d]\n6. T³umik [%d]\n7. Szkielet broni karabinowej [%d]\n8. Zespó³ zamka karabinu [%d]\n9. Magazynek karabinu [%d]\n10. Sprê¿yna powrotna karabinu [%d]\n11. Kolba [%d]\n12. Komplet œrubek karabinu [%d]\n13. Luneta [%d]\n14. Pocisk 9mm [%d]\n15. £uska 9mm [%d]\n16. Proch admidowy [%d]\n17. Sp³onka 9mm [%d]\n18. O³ów [%d]\n19. £uska do strzelby [%d]\n%s\n%s",
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryPistolPart1],
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryPistolPart2],
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryPistolPart3],
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryPistolPart4],
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryPistolPart5],
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryPistolPart6],
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryRiflePart1],
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryRiflePart2],
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryRiflePart3],
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryRiflePart4],
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryRiflePart5],
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryRiflePart6],
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryRiflePart7],
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryAmmoPart1a],
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryAmmoPart2a],
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryAmmoPart3a],
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryAmmoPart4a],
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryAmmoPart1b],
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryAmmoPart2b],
					string2,
					string3 );
					
					gListItem[playerid] = listitem;
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_3_PARTS_MMAKE, DIALOG_STYLE_LIST, DIALOG_WMENU_TITLE_TXT, string, "Wybierz", "Wróæ" );
					
					return 1;
				}
				else
				{
					format( string, sizeof(string),
					"1. Lufa [%d]\n2. Mechanizm spustowo-uderzeniowy [%d]\n3. Nak³adki z tworzywa sztucznego [%d]\n4. Mechanizm iglicy [%d]\n5. Bezpiecznik typu listkowego [%d]\n6. Przyrz¹dy celownicze [%d]\n7. Szkielet [%d]\n8. Stopka [%d]\n9. Wew. sprê¿yna [%d]\n10. Dosy³acz [%d]\n11. Lufa karabinu [%d]\n12. Mechanizm spustowo-uderzeniowy karabinu [%d]\n13. Mechanizm iglicy karabinu [%d]",
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryPistolS1Part1],
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryPistolS1Part2],
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryPistolS1Part3],
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryPistolS2Part1],
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryPistolS2Part2],
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryPistolS2Part3],
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryPistolS3Part1],
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryPistolS3Part2],
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryPistolS3Part3],
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryPistolS3Part4],
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryRifleS1Part1],
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryRifleS1Part2],
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryRifleS2Part1] );
					
					format( string2, sizeof(string2),
					"14. Bezpiecznik typu listkowego karabinu [%d]\n15. Przyrz¹dy celownicze karabinu [%d]\n16. Szkielet karabinu [%d]\n17. Stopka karabinu [%d]\n18. Wew. sprê¿yna karabinu [%d]\n19. Dosy³acz karabinu [%d]\n20. Szkielet lunety [%d]\n21. Soczewki [%d]",
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryRifleS2Part2],
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryRifleS2Part3],
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryRifleS3Part1],
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryRifleS3Part2],
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryRifleS3Part3],
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryRifleS3Part4],
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryRifleS6Part1],
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryRifleS6Part2] );
					
					format( string, sizeof(string), "%s\n%s", string, string2 );
					
					gListItem[playerid] = listitem;
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_3_PARTS_SBUY, DIALOG_STYLE_LIST, DIALOG_WMENU_TITLE_TXT, string, "Wybierz", "Wróæ" );
					
					return 1;
				}
			}
			else
			{
				ShowPlayerDialog( playerid, DIALOG_WMENU_1, DIALOG_STYLE_LIST, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_MAIN_TXT, "Wybierz", "Anuluj" );
				return 1;
			}
		}
		case DIALOG_WMENU_3_PARTS_MMAKE:
		{
			if(response)
			{				
				gListItem[playerid] = listitem;
				if (listitem == 0) // szkielet broni
				{
					format( string, sizeof(string), "Nazwa: %s\nDostêpna iloœæ w magazynie frakcji: %d\nWymagane czêœci:\n- lufa [%d/1]\n- mechanizm spustowo-uderzeniowy [%d/1]\n- nak³adki z tworzywa sztucznego [%d/1]",
					ItemName( 1, 48 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart1],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolS1Part1],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolS1Part2],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolS1Part3] );
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Zmontuj", "Wróæ" );
					return 1;
				}
				else if (listitem == 1) // Zespó³ zamka
				{
					format( string, sizeof(string), "Nazwa: %s\nDostêpna iloœæ w magazynie frakcji: %d\nWymagane czêœci:\n- mechanizm iglicy [%d/1]\n- bezpiecznik typu listkowego [%d/1]\n- przyrz¹dy celownicze [%d/1]",
					ItemName( 1, 49 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart2],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolS2Part1],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolS2Part2],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolS2Part3] );
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Zmontuj", "Wróæ" );
					return 1;
				}
				else if (listitem == 2) // Magazynek
				{
					format( string, sizeof(string), "Nazwa: %s\nDostêpna iloœæ w magazynie frakcji: %d\nWymagane czêœci:\n- szkielet [%d/1]\n- stopka [%d/1]\n- wew. sprê¿yna [%d/1]\n- dosy³acz [%d/1]",
					ItemName( 1, 50 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart3],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolS3Part1],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolS3Part2],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolS3Part3],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolS3Part4] );
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Zmontuj", "Wróæ" );
					return 1;
				}
				else if (listitem == 3) // sprê¿yna powrotna
				{
					format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
					ItemName( 1, 51 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart4],
					ItemPrice( 1, 51 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
					return 1;
				}
				else if (listitem == 4) // komplet œrubek
				{
					format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
					ItemName( 1, 52 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart5],
					ItemPrice( 1, 52 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
					return 1;
				}
				else if (listitem == 5) // t³umik
				{
					format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
					ItemName( 1, 59 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart6],
					ItemPrice( 1, 59 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
					return 1;
				}
				else if (listitem == 6) // szkielet broni karabinowej
				{
					format( string, sizeof(string), "Nazwa: %s\nDostêpna iloœæ w magazynie frakcji: %d\nWymagane czêœci:\n- lufa karabinu [%d/1]\n- mechanizm spustowo-uderzeniowy karabinu [%d/1]\n- nak³adki z tworzywa sztucznego [%d/1]",
					ItemName( 1, 53 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart1],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRifleS1Part1],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRifleS1Part2],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolS1Part3] );
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Zmontuj", "Wróæ" );
					return 1;
				}
				else if (listitem == 7) // zespó³ zamka karabinu
				{
					format( string, sizeof(string), "Nazwa: %s\nDostêpna iloœæ w magazynie frakcji: %d\nWymagane czêœci:\n- mechanizm iglicy karabinu [%d/1]\n- bezpiecznik typu listkowego karabinu [%d/1]\n- przyrz¹dy celownicze karabinu [%d/1]",
					ItemName( 1, 54 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart2],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRifleS2Part1],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRifleS2Part2],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRifleS2Part3] );
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Zmontuj", "Wróæ" );
					return 1;
				}
				else if (listitem == 8) // magazynek karabinu
				{
					format( string, sizeof(string), "Nazwa: %s\nDostêpna iloœæ w magazynie frakcji: %d\nWymagane czêœci:\n- szkielet karabinu [%d/1]\n- stopka karabinu [%d/1]\n- wew. sprê¿yna karabinu [%d/1]\n- dosy³acz karabinu [%d/1]",
					ItemName( 1, 55 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart3],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRifleS3Part1],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRifleS3Part2],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRifleS3Part3],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRifleS3Part4] );
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Zmontuj", "Wróæ" );
					return 1;
				}
				else if (listitem == 9) // sprê¿yna powrotna karabinu
				{
					format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
					ItemName( 1, 56 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart4],
					ItemPrice( 1, 56 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
					return 1;
				}
				else if (listitem == 10) // kolba
				{
					format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
					ItemName( 1, 57 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart5],
					ItemPrice( 1, 57 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
					return 1;
				}
				else if (listitem == 11) // komplet œrubek karabinu
				{
					format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
					ItemName( 1, 58 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart6],
					ItemPrice( 1, 58 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
					return 1;
				}
				else if (listitem == 12) // luneta
				{
					format( string, sizeof(string), "Nazwa: %s\nDostêpna iloœæ w magazynie frakcji: %d\nWymagane czêœci:\n- szkielet lunety [%d/1]\n- soczewki [%d/1]",
					ItemName( 1, 60 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart6],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRifleS6Part1],
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRifleS6Part2] );
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Zmontuj", "Wróæ" );
					return 1;
				}
				else if (listitem == 13) // pocisk 9mm
				{
					format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
					ItemName( 1, 43 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart1a],
					ItemPrice( 1, 43 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
					return 1;
				}
				else if (listitem == 14) // ³uska 9mm
				{
					format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
					ItemName( 1, 44 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart2a],
					ItemPrice( 1, 44 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
					return 1;
				}
				else if (listitem == 15) // proch 1gr
				{
					format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
					ItemName( 1, 45 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart3a],
					ItemPrice( 1, 45 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
					return 1;
				}
				else if (listitem == 16) // sp³onka 9mm
				{
					format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
					ItemName( 1, 46 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart4a],
					ItemPrice( 1, 46 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
					return 1;
				}
				else if (listitem == 17) // o³ów
				{
					format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
					ItemName( 1, 47 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart1b],
					ItemPrice( 1, 47 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
					return 1;
				}
				else if (listitem == 18) // ³uska do strzelby
				{
					format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
					ItemName( 1, 90 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart2b],
					ItemPrice( 1, 90 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
					return 1;
				}
				else if (listitem == 19) // proch 5gr
				{
					format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
					ItemName( 1, 91 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart3b],
					ItemPrice( 1, 91 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
					return 1;
				}
				else if (listitem == 20) // sp³onka do strzelby
				{
					format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
					ItemName( 1, 92 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart4b],
					ItemPrice( 1, 92 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
					return 1;
				}
				else if (listitem == 21) // pocisk karabinu
				{
					format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
					ItemName( 1, 93 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart1c],
					ItemPrice( 1, 93 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
					return 1;
				}
				else if (listitem == 22) // ³uska karabinu
				{
					format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
					ItemName( 1, 94 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart2c],
					ItemPrice( 1, 94 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
					return 1;
				}
				else if (listitem == 23) // proch 3gr
				{
					format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
					ItemName( 1, 95 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart3c],
					ItemPrice( 1, 95 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
					return 1;
				}
				else if (listitem == 24) // sp³onka karabinu
				{
					format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
					ItemName( 1, 96 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart4c],
					ItemPrice( 1, 96 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
					return 1;
				}
				else if (listitem == 25) // pocisk snajp
				{
					format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
					ItemName( 1, 97 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart1d],
					ItemPrice( 1, 97 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
					return 1;
				}
				else if (listitem == 26) // ³uska snajp
				{
					format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
					ItemName( 1, 98 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart2d],
					ItemPrice( 1, 98 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
					return 1;
				}
				else if (listitem == 27) // proch 10gr
				{
					format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
					ItemName( 1, 99 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart3d],
					ItemPrice( 1, 99 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
					return 1;
				}
				else if (listitem == 28) // sp³onka snajp
				{
					format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
					ItemName( 1, 100 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart4d],
					ItemPrice( 1, 100 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
					return 1;
				}
				else if (listitem == 29) // pocisk des ea
				{
					format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
					ItemName( 1, 101 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart1e],
					ItemPrice( 1, 101 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
					return 1;
				}
				else if (listitem == 30) // ³uska des ea
				{
					format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
					ItemName( 1, 102 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart2e],
					ItemPrice( 1, 102 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
					return 1;
				}
				else if (listitem == 31) // proch 2gr
				{
					format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
					ItemName( 1, 103 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart3e],
					ItemPrice( 1, 103 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
					return 1;
				}
				else if (listitem == 32) // sp³onka des ea
				{
					format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
					ItemName( 1, 104 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart4e],
					ItemPrice( 1, 104 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
					return 1;
				}
				else if (listitem == 33) // zestaw montazowy tec9
				{
					format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
					ItemName( 1, 82 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryTec9Part],
					ItemPrice( 1, 82 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
					return 1;
				}
				else if (listitem == 34) // zestaw montazowy MP5
				{
					format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
					ItemName( 1, 83 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryMP5Part],
					ItemPrice( 1, 83 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
					return 1;
				}
				else if (listitem == 35) // zestaw montazowy AK47
				{
					format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
					ItemName( 1, 84 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAK47Part],
					ItemPrice( 1, 84 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
					return 1;
				}
				else if (listitem == 36) // zestaw montazowy M4
				{
					format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
					ItemName( 1, 85 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryM4Part],
					ItemPrice( 1, 85 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
					return 1;
				}
				else if (listitem == 37) // zestaw montazowy shot
				{
					format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
					ItemName( 1, 86 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryShotPart],
					ItemPrice( 1, 86 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
					return 1;
				}
				else if (listitem == 38) // zestaw montazowy rifle
				{
					format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
					ItemName( 1, 88 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart],
					ItemPrice( 1, 88 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
					return 1;
				}
				else if (listitem == 39) // zestaw montazowy sniper
				{
					format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
					ItemName( 1, 89 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactorySniperPart],
					ItemPrice( 1, 89 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
					return 1;
				}
				else if (listitem == 40) // zestaw montazowy des eagl
				{
					format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
					ItemName( 1, 87 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryDesEaglePart],
					ItemPrice( 1, 87 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
					return 1;
				}
				return 1;
			}
			else
			{
				format( string, sizeof(string),
				"1. Czêœci g³ówne\n2. Podczêœci");
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_2_PARTS, DIALOG_STYLE_LIST, DIALOG_WMENU_TITLE_TXT, string, "Wybierz", "Wróæ" );
				
				return 1;
			}
		}
		case DIALOG_WMENU_4_PARTS_MMAKE:
		{
			if(response)
			{
				if( gPlayerData[playerid][pMountsLeft] != 0 )
				{
					ShowPlayerDialog( playerid, DIALOG_WMENU_3_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_3_WEAPON_INFO_TXT, "Wróæ", "" );
					return 1;
				}
				if (gListItem[playerid] == 0) // szkielet broni
				{
					if( PlayerFreeSlotCount( playerid ) < 3 )
					{
						ShowPlayerDialog( playerid, DIALOG_WMENU_3_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_3_NO_SPACE_TXT, "Wróæ", "" );
						return 1;
					}
					if( DynamicFactions[ gPlayerData[playerid][pFaction]] [WFactoryPistolS1Part1] >= 1 &&
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolS1Part2] >= 1 &&
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolS1Part3] >= 1 )
					{
						if( !PHaveItem( playerid, 1, 61 ) )
						{
							InsertPlayerItemEx( playerid, 1, 61, 0, 0, 0, 0, "Puste", 1);
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolS1Part1]--;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolS1Part1" );
						}
						if( !PHaveItem( playerid, 1, 62 ) )
						{
							InsertPlayerItemEx( playerid, 1, 62, 0, 0, 0, 0, "Puste", 1);
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolS1Part2]--;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolS1Part2" );
						}
						if( !PHaveItem( playerid, 1, 63 ) )
						{
							InsertPlayerItemEx( playerid, 1, 63, 0, 0, 0, 0, "Puste", 1);
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolS1Part3]--;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolS1Part3" );
						}
						SendClientMessage( playerid, COLOR_LIGHTYELLOW2, DIALOG_WMENU_GOTO1_TXT );
						SendClientMessage( playerid, COLOR_LIGHTYELLOW2, DIALOG_WMENU_GOTO2_TXT );
						gPlayerData[playerid][pPartType] = WF_PART;
						gPlayerData[playerid][pPartItem] = WF_PISTOLPART1;
						gPlayerData[playerid][pMountsLeft] = 3;
						gPlayerData[playerid][pMountsPasses] = WF_LSPT;
						SavePlayerData( playerid, "PartType" );
						SavePlayerData( playerid, "PartItem" );
						SavePlayerData( playerid, "MountsLeft" );
						SavePlayerData( playerid, "MountsPasses" );
						return 1;
					}
				}
				else if(gListItem[playerid] == 1) // Zespó³ zamka
				{
					if( PlayerFreeSlotCount( playerid ) < 3 )
					{
						ShowPlayerDialog( playerid, DIALOG_WMENU_3_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_3_NO_SPACE_TXT, "Wróæ", "" );
						return 1;
					}
					if( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolS2Part1] >= 1 &&
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolS2Part2] >= 1 &&
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolS2Part3] >= 1 )
					{
						if ( !PHaveItem( playerid, 1, 64 ) )
						{
							InsertPlayerItemEx( playerid, 1, 64, 0, 0, 0, 0, "Puste", 1 );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolS2Part1]--;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolS2Part1" );
						}
						if ( !PHaveItem( playerid, 1, 65 ) )
						{
							InsertPlayerItemEx( playerid, 1, 65, 0, 0, 0, 0, "Puste", 1 );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolS2Part2]--;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolS2Part2" );
						}
						if ( !PHaveItem( playerid, 1, 66 ) )
						{
							InsertPlayerItemEx( playerid, 1, 66, 0, 0, 0, 0, "Puste", 1 );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolS2Part3]--;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolS2Part3" );
						}
						SendClientMessage( playerid, COLOR_LIGHTYELLOW2, DIALOG_WMENU_GOTO1_TXT );
						SendClientMessage( playerid, COLOR_LIGHTYELLOW2, DIALOG_WMENU_GOTO2_TXT );
						gPlayerData[playerid][pPartType] = WF_PART;
						gPlayerData[playerid][pPartItem] = WF_PISTOLPART2;
						gPlayerData[playerid][pMountsLeft] = 3;
						gPlayerData[playerid][pMountsPasses] = WF_LSPT;
						SavePlayerData( playerid, "PartType" );
						SavePlayerData( playerid, "PartItem" );
						SavePlayerData( playerid, "MountsLeft" );
						SavePlayerData( playerid, "MountsPasses" );
						return 1;
					}
				}
				else if(gListItem[playerid] == 2) // Magazynek
				{
					if( PlayerFreeSlotCount( playerid ) < 4 )
					{
						ShowPlayerDialog( playerid, DIALOG_WMENU_3_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_3_NO_SPACE_TXT, "Wróæ", "" );
						return 1;
					}
					if( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolS3Part1] >= 1 &&
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolS3Part2] >= 1 &&
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolS3Part3] >= 1 &&
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolS3Part4] >= 1 )
					{
						if ( !PHaveItem( playerid, 1, 67 ) )
						{
							InsertPlayerItemEx( playerid, 1, 67, 0, 0, 0, 0, "Puste", 1);
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolS3Part1]--;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolS3Part1" );
						}
						if ( !PHaveItem( playerid, 1, 68 ) )
						{
							InsertPlayerItemEx( playerid, 1, 68, 0, 0, 0, 0, "Puste", 1);
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolS3Part2]--;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolS3Part2" );
						}
						if ( !PHaveItem( playerid, 1, 69 ) )
						{
							InsertPlayerItemEx( playerid, 1, 69, 0, 0, 0, 0, "Puste", 1);
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolS3Part3]--;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolS3Part3" );
						}
						if ( !PHaveItem( playerid, 1, 70 ) )
						{
							InsertPlayerItemEx( playerid, 1, 70, 0, 0, 0, 0, "Puste", 1);
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolS3Part4]--;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolS3Part4" );
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
						SavePlayerData( playerid, "MountsPasses" );
						return 1;
					}
				}
				else if(gListItem[playerid] == 3) // sprê¿yna powrotna
				{
					if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] >= ItemPrice( 1, 51 ) )
					{
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart4]++;
						DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 51 );
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolPart4" );
						SaveFData( gPlayerData[playerid][pFaction], "Bank" );
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_BOUGHT_PART_TXT, "Wróæ", "" );
						return 1;
					}
					else
					{
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_NOCASH_TXT, "Wróæ", "" );
						return 1;
					}
				}
				else if(gListItem[playerid] == 4) // komplet œrubek
				{
					if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] >= ItemPrice( 1, 52 ) )
					{
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart5]++;
						DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 52 );
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolPart5" );
						SaveFData( gPlayerData[playerid][pFaction], "Bank" );
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_BOUGHT_PART_TXT, "Wróæ", "" );
						return 1;
					}
					else
					{
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_NOCASH_TXT, "Wróæ", "" );
						return 1;
					}
				}
				else if(gListItem[playerid] == 5) // t³umik
				{
					if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] >= ItemPrice( 1, 59 ) )
					{
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart6]++;
						DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 59 );
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolPart6" );
						SaveFData( gPlayerData[playerid][pFaction], "Bank" );
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_BOUGHT_PART_TXT, "Wróæ", "" );
						return 1;
					}
					else
					{
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_NOCASH_TXT, "Wróæ", "" );
						return 1;
					}
				}
				else if(gListItem[playerid] == 6) // szkielet broni karabinowej
				{
					if( PlayerFreeSlotCount( playerid ) < 3 )
					{
						ShowPlayerDialog( playerid, DIALOG_WMENU_3_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_3_NO_SPACE_TXT, "Wróæ", "" );
						return 1;
					}
					if( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRifleS1Part1] >= 1 &&
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRifleS1Part2] >= 1 &&
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolS1Part3] >= 1 )
					{
						if ( !PHaveItem( playerid, 1, 71 ) )
						{
							InsertPlayerItemEx( playerid, 1, 71, 0, 0, 0, 0, "Puste", 1);
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRifleS1Part1]--;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryRifleS1Part1" );
						}
						if ( !PHaveItem( playerid, 1, 72 ) )
						{
							InsertPlayerItemEx( playerid, 1, 72, 0, 0, 0, 0, "Puste", 1);
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRifleS1Part2]--;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryRifleS1Part2" );
						}
						if ( !PHaveItem( playerid, 1, 63 ) )
						{
							InsertPlayerItemEx( playerid, 1, 63, 0, 0, 0, 0, "Puste", 1);
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolS1Part3]--;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolS1Part3" );
						}
						SendClientMessage( playerid, COLOR_LIGHTYELLOW2, DIALOG_WMENU_GOTO1_TXT );
						SendClientMessage( playerid, COLOR_LIGHTYELLOW2, DIALOG_WMENU_GOTO2_TXT );
						gPlayerData[playerid][pPartType] = WF_PART;
						gPlayerData[playerid][pPartItem] = WF_RIFLEPART1;
						gPlayerData[playerid][pMountsLeft] = 3;
						gPlayerData[playerid][pMountsPasses] = WF_HSPT;
						SavePlayerData( playerid, "PartType" );
						SavePlayerData( playerid, "PartItem" );
						SavePlayerData( playerid, "MountsLeft" );
						SavePlayerData( playerid, "MountsPasses" );
						return 1;
					}
				}
				else if(gListItem[playerid] == 7) // zespó³ zamka karabinu
				{
					if( PlayerFreeSlotCount( playerid ) < 3 )
					{
						ShowPlayerDialog( playerid, DIALOG_WMENU_3_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_3_NO_SPACE_TXT, "Wróæ", "" );
						return 1;
					}
					if( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRifleS2Part1] >= 1 &&
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRifleS2Part2] >= 1 &&
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRifleS2Part3] >= 1 )
					{
						if ( !PHaveItem( playerid, 1, 73 ) )
						{
							InsertPlayerItemEx( playerid, 1, 73, 0, 0, 0, 0, "Puste", 1);
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRifleS2Part1]--;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryRifleS2Part1" );
						}
						if ( !PHaveItem( playerid, 1, 74 ) )
						{
							InsertPlayerItemEx( playerid, 1, 74, 0, 0, 0, 0, "Puste", 1);
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRifleS2Part2]--;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryRifleS2Part2" );
						}
						if ( !PHaveItem( playerid, 1, 75 ) )
						{
							InsertPlayerItemEx( playerid, 1, 75, 0, 0, 0, 0, "Puste", 1);
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRifleS2Part3]--;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryRifleS2Part3" );
						}
						SendClientMessage( playerid, COLOR_LIGHTYELLOW2, DIALOG_WMENU_GOTO1_TXT );
						SendClientMessage( playerid, COLOR_LIGHTYELLOW2, DIALOG_WMENU_GOTO2_TXT );
						gPlayerData[playerid][pPartType] = WF_PART;
						gPlayerData[playerid][pPartItem] = WF_RIFLEPART2;
						gPlayerData[playerid][pMountsLeft] = 3;
						gPlayerData[playerid][pMountsPasses] = WF_HSPT;
						SavePlayerData( playerid, "PartType" );
						SavePlayerData( playerid, "PartItem" );
						SavePlayerData( playerid, "MountsLeft" );
						SavePlayerData( playerid, "MountsPasses" );
						return 1;
					}
				}
				else if(gListItem[playerid] == 8) // magazynek karabinu
				{
					if( PlayerFreeSlotCount( playerid ) < 4 )
					{
						ShowPlayerDialog( playerid, DIALOG_WMENU_3_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_3_NO_SPACE_TXT, "Wróæ", "" );
						return 1;
					}
					if( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRifleS3Part1] >= 1 &&
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRifleS3Part2] >= 1 &&
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRifleS3Part3] >= 1 &&
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRifleS3Part4] >= 1 )
					{
						if ( !PHaveItem( playerid, 1, 76 ) )
						{
							InsertPlayerItemEx( playerid, 1, 76, 0, 0, 0, 0, "Puste", 1);
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRifleS3Part1]--;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryRifleS3Part1" );
						}
						if ( !PHaveItem( playerid, 1, 77 ) )
						{
							InsertPlayerItemEx( playerid, 1, 77, 0, 0, 0, 0, "Puste", 1);
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRifleS3Part2]--;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryRifleS3Part2" );
						}
						if ( !PHaveItem( playerid, 1, 78 ) )
						{
							InsertPlayerItemEx( playerid, 1, 78, 0, 0, 0, 0, "Puste", 1);
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRifleS3Part3]--;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryRifleS3Part3" );
						}
						if ( !PHaveItem( playerid, 1, 79 ) )
						{
							InsertPlayerItemEx( playerid, 1, 79, 0, 0, 0, 0, "Puste", 1);
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRifleS3Part4]--;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryRifleS3Part4" );
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
						SavePlayerData( playerid, "MountsPasses" );
						return 1;
					}
				}
				else if(gListItem[playerid] == 9) // sprê¿yna powrotna karabinu
				{
					if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] >= ItemPrice( 1, 56 ) )
					{
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart4]++;
						DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 56 );
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflePart4" );
						SaveFData( gPlayerData[playerid][pFaction], "Bank" );
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_BOUGHT_PART_TXT, "Wróæ", "" );
						return 1;
					}
					else
					{
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_NOCASH_TXT, "Wróæ", "" );
						return 1;
					}
				}
				else if(gListItem[playerid] == 10) // kolba
				{
					if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] >= ItemPrice( 1, 57 ) )
					{
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart5]++;
						DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 57 );
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflePart5" );
						SaveFData( gPlayerData[playerid][pFaction], "Bank" );
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_BOUGHT_PART_TXT, "Wróæ", "" );
						return 1;
					}
					else
					{
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_NOCASH_TXT, "Wróæ", "" );
						return 1;
					}
				}
				else if(gListItem[playerid] == 11) // komplet œrubek karabinu
				{
					if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] >= ItemPrice( 1, 58 ) )
					{
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart6]++;
						DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 58 );
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflePart6" );
						SaveFData( gPlayerData[playerid][pFaction], "Bank" );
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_BOUGHT_PART_TXT, "Wróæ", "" );
						return 1;
					}
					else
					{
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_NOCASH_TXT, "Wróæ", "" );
						return 1;
					}
				}
				else if(gListItem[playerid] == 12) // luneta
				{
					if( PlayerFreeSlotCount( playerid ) < 2 )
					{
						ShowPlayerDialog( playerid, DIALOG_WMENU_3_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_3_NO_SPACE_TXT, "Wróæ", "" );
						return 1;
					}
					if( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRifleS6Part1] >= 1 &&
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRifleS6Part2] >= 1 )
					{
						if( !PHaveItem( playerid, 1, 80 ) )
						{
							InsertPlayerItemEx( playerid, 1, 80, 0, 0, 0, 0, "Puste", 1);
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRifleS6Part1]--;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolS6Part1" );
						}
						if( !PHaveItem( playerid, 1, 81 ) )
						{
							InsertPlayerItemEx( playerid, 1, 81, 0, 0, 0, 0, "Puste", 1);
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRifleS6Part2]--;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolS6Part2" );
						}
						SendClientMessage( playerid, COLOR_LIGHTYELLOW2, DIALOG_WMENU_GOTO1_TXT );
						SendClientMessage( playerid, COLOR_LIGHTYELLOW2, DIALOG_WMENU_GOTO2_TXT );
						gPlayerData[playerid][pPartType] = WF_PART;
						gPlayerData[playerid][pPartItem] = WF_RIFLEPART7;
						gPlayerData[playerid][pMountsLeft] = 2;
						gPlayerData[playerid][pMountsPasses] = WF_HSPT;
						SavePlayerData( playerid, "PartType" );
						SavePlayerData( playerid, "PartItem" );
						SavePlayerData( playerid, "MountsLeft" );
						SavePlayerData( playerid, "MountsPasses" );
						return 1;
					}
				}
				else if(gListItem[playerid] == 13) // pocisk 9mm
				{
					if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] >= ItemPrice( 1, 43 ) )
					{
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart1a]++;
						DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 43 );
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryAmmoPart1a" );
						SaveFData( gPlayerData[playerid][pFaction], "Bank" );
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_BOUGHT_PART_TXT, "Wróæ", "" );
						return 1;
					}
					else
					{
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_NOCASH_TXT, "Wróæ", "" );
						return 1;
					}
				}
				else if(gListItem[playerid] == 14) // ³uska 9mm
				{
					if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] >= ItemPrice( 1, 44 ) )
					{
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart2a]++;
						DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 44 );
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryAmmoPart2a" );
						SaveFData( gPlayerData[playerid][pFaction], "Bank" );
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_BOUGHT_PART_TXT, "Wróæ", "" );
						return 1;
					}
					else
					{
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_NOCASH_TXT, "Wróæ", "" );
						return 1;
					}
				}
				else if(gListItem[playerid] == 15) // proch 1gr
				{
					if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] >= ItemPrice( 1, 45 ) )
					{
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart3a]++;
						DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 45 );
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryAmmoPart3a" );
						SaveFData( gPlayerData[playerid][pFaction], "Bank" );
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_BOUGHT_PART_TXT, "Wróæ", "" );
						return 1;
					}
					else
					{
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_NOCASH_TXT, "Wróæ", "" );
						return 1;
					}
				}
				else if(gListItem[playerid] == 16) // sp³onka 9mm
				{
					if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] >= ItemPrice( 1, 46 ) )
					{
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart4a]++;
						DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 46 );
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryAmmoPart4a" );
						SaveFData( gPlayerData[playerid][pFaction], "Bank" );
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_BOUGHT_PART_TXT, "Wróæ", "" );
						return 1;
					}
					else
					{
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_NOCASH_TXT, "Wróæ", "" );
						return 1;
					}
				}
				else if(gListItem[playerid] == 17) // o³ów
				{
					if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] >= ItemPrice( 1, 47 ) )
					{
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart1b]++;
						DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 47 );
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryAmmoPart1b" );
						SaveFData( gPlayerData[playerid][pFaction], "Bank" );
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_BOUGHT_PART_TXT, "Wróæ", "" );
						return 1;
					}
					else
					{
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_NOCASH_TXT, "Wróæ", "" );
						return 1;
					}
				}
				else if(gListItem[playerid] == 18) // ³uska do strzelby
				{
					if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] >= ItemPrice( 1, 90 ) )
					{
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart2b]++;
						DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 90 );
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryAmmoPart2b" );
						SaveFData( gPlayerData[playerid][pFaction], "Bank" );
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_BOUGHT_PART_TXT, "Wróæ", "" );
						return 1;
					}
					else
					{
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_NOCASH_TXT, "Wróæ", "" );
						return 1;
					}
				}
				else if(gListItem[playerid] == 19) // proch 5gr
				{
					if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] >= ItemPrice( 1, 91 ) )
					{
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart3b]++;
						DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 91 );
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryAmmoPart3b" );
						SaveFData( gPlayerData[playerid][pFaction], "Bank" );
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_BOUGHT_PART_TXT, "Wróæ", "" );
						return 1;
					}
					else
					{
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_NOCASH_TXT, "Wróæ", "" );
						return 1;
					}
				}
				else if(gListItem[playerid] == 20) // sp³onka do strzelby
				{
					if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] >= ItemPrice( 1, 92 ) )
					{
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart4b]++;
						DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 92 );
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryAmmoPart4b" );
						SaveFData( gPlayerData[playerid][pFaction], "Bank" );
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_BOUGHT_PART_TXT, "Wróæ", "" );
						return 1;
					}
					else
					{
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_NOCASH_TXT, "Wróæ", "" );
						return 1;
					}
				}
				else if(gListItem[playerid] == 21) // pocisk karabinu
				{
					if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] >= ItemPrice( 1, 93 ) )
					{
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart1c]++;
						DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 93 );
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryAmmoPart1c" );
						SaveFData( gPlayerData[playerid][pFaction], "Bank" );
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_BOUGHT_PART_TXT, "Wróæ", "" );
						return 1;
					}
					else
					{
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_NOCASH_TXT, "Wróæ", "" );
						return 1;
					}
				}
				else if(gListItem[playerid] == 22) // ³uska karabinu
				{
					if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] >= ItemPrice( 1, 94 ) )
					{
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart2c]++;
						DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 94 );
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryAmmoPart2c" );
						SaveFData( gPlayerData[playerid][pFaction], "Bank" );
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_BOUGHT_PART_TXT, "Wróæ", "" );
						return 1;
					}
					else
					{
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_NOCASH_TXT, "Wróæ", "" );
						return 1;
					}
				}
				else if(gListItem[playerid] == 23) // proch 3gr
				{
					if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] >= ItemPrice( 1, 95 ) )
					{
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart3c]++;
						DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 95 );
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryAmmoPart3c" );
						SaveFData( gPlayerData[playerid][pFaction], "Bank" );
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_BOUGHT_PART_TXT, "Wróæ", "" );
						return 1;
					}
					else
					{
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_NOCASH_TXT, "Wróæ", "" );
						return 1;
					}
				}
				else if(gListItem[playerid] == 24) // sp³onka karabinu
				{
					if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] >= ItemPrice( 1, 96 ) )
					{
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart4c]++;
						DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 96 );
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryAmmoPart4c" );
						SaveFData( gPlayerData[playerid][pFaction], "Bank" );
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_BOUGHT_PART_TXT, "Wróæ", "" );
						return 1;
					}
					else
					{
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_NOCASH_TXT, "Wróæ", "" );
						return 1;
					}
				}
				else if(gListItem[playerid] == 25) // pocisk snajp
				{
					if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] >= ItemPrice( 1, 97 ) )
					{
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart1d]++;
						DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 97 );
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryAmmoPart1d" );
						SaveFData( gPlayerData[playerid][pFaction], "Bank" );
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_BOUGHT_PART_TXT, "Wróæ", "" );
						return 1;
					}
					else
					{
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_NOCASH_TXT, "Wróæ", "" );
						return 1;
					}
				}
				else if(gListItem[playerid] == 26) // ³uska snajp
				{
					if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] >= ItemPrice( 1, 98 ) )
					{
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart2d]++;
						DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 98 );
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryAmmoPart2d" );
						SaveFData( gPlayerData[playerid][pFaction], "Bank" );
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_BOUGHT_PART_TXT, "Wróæ", "" );
						return 1;
					}
					else
					{
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_NOCASH_TXT, "Wróæ", "" );
						return 1;
					}
				}
				else if(gListItem[playerid] == 27) // proch 10gr
				{
					if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] >= ItemPrice( 1, 99 ) )
					{
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart3d]++;
						DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 99 );
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryAmmoPart3d" );
						SaveFData( gPlayerData[playerid][pFaction], "Bank" );
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_BOUGHT_PART_TXT, "Wróæ", "" );
						return 1;
					}
					else
					{
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_NOCASH_TXT, "Wróæ", "" );
						return 1;
					}
				}
				else if(gListItem[playerid] == 28) // sp³onka snajp
				{
					if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] >= ItemPrice( 1, 100 ) )
					{
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart4d]++;
						DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 100 );
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryAmmoPart4d" );
						SaveFData( gPlayerData[playerid][pFaction], "Bank" );
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_BOUGHT_PART_TXT, "Wróæ", "" );
						return 1;
					}
					else
					{
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_NOCASH_TXT, "Wróæ", "" );
						return 1;
					}
				}
				else if(gListItem[playerid] == 29) // pocisk des ea
				{
					if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] >= ItemPrice( 1, 101 ) )
					{
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart1e]++;
						DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 101 );
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryAmmoPart1e" );
						SaveFData( gPlayerData[playerid][pFaction], "Bank" );
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_BOUGHT_PART_TXT, "Wróæ", "" );
						return 1;
					}
					else
					{
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_NOCASH_TXT, "Wróæ", "" );
						return 1;
					}
				}
				else if(gListItem[playerid] == 30) // ³uska des ea
				{
					if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] >= ItemPrice( 1, 102 ) )
					{
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart2e]++;
						DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 102 );
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryAmmoPart2e" );
						SaveFData( gPlayerData[playerid][pFaction], "Bank" );
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_BOUGHT_PART_TXT, "Wróæ", "" );
						return 1;
					}
					else
					{
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_NOCASH_TXT, "Wróæ", "" );
						return 1;
					}
				}
				else if(gListItem[playerid] == 31) // proch 2gr
				{
					if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] >= ItemPrice( 1, 103 ) )
					{
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart3e]++;
						DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 103 );
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryAmmoPart3e" );
						SaveFData( gPlayerData[playerid][pFaction], "Bank" );
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_BOUGHT_PART_TXT, "Wróæ", "" );
						return 1;
					}
					else
					{
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_NOCASH_TXT, "Wróæ", "" );
						return 1;
					}
				}
				else if(gListItem[playerid] == 32) // sp³onka des ea
				{
					if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] >= ItemPrice( 1, 104 ) )
					{
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart4e]++;
						DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 104 );
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryAmmoPart4e" );
						SaveFData( gPlayerData[playerid][pFaction], "Bank" );
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_BOUGHT_PART_TXT, "Wróæ", "" );
						return 1;
					}
					else
					{
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_NOCASH_TXT, "Wróæ", "" );
						return 1;
					}
				}
				else if(gListItem[playerid] == 33) // zestaw montazowy tec9
				{
					if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] >= ItemPrice( 1, 82 ) )
					{
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryTec9Part]++;
						DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 82 );
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryTec9Part" );
						SaveFData( gPlayerData[playerid][pFaction], "Bank" );
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_BOUGHT_PART_TXT, "Wróæ", "" );
						return 1;
					}
					else
					{
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_NOCASH_TXT, "Wróæ", "" );
						return 1;
					}
				}
				else if(gListItem[playerid] == 34) // zestaw montazowy mp5
				{
					if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] >= ItemPrice( 1, 83 ) )
					{
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryMP5Part]++;
						DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 83 );
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryMP5Part" );
						SaveFData( gPlayerData[playerid][pFaction], "Bank" );
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_BOUGHT_PART_TXT, "Wróæ", "" );
						return 1;
					}
					else
					{
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_NOCASH_TXT, "Wróæ", "" );
						return 1;
					}
				}
				else if(gListItem[playerid] == 35) // zestaw montazowy ak-47
				{
					if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] >= ItemPrice( 1, 84 ) )
					{
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAK47Part]++;
						DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 84 );
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryAK47Part" );
						SaveFData( gPlayerData[playerid][pFaction], "Bank" );
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_BOUGHT_PART_TXT, "Wróæ", "" );
						return 1;
					}
					else
					{
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_NOCASH_TXT, "Wróæ", "" );
						return 1;
					}
				}
				else if(gListItem[playerid] == 36) // zestaw montazowy m4
				{
					if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] >= ItemPrice( 1, 85 ) )
					{
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryM4Part]++;
						DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 85 );
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryM4Part" );
						SaveFData( gPlayerData[playerid][pFaction], "Bank" );
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_BOUGHT_PART_TXT, "Wróæ", "" );
						return 1;
					}
					else
					{
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_NOCASH_TXT, "Wróæ", "" );
						return 1;
					}
				}
				else if(gListItem[playerid] == 37) // zestaw montazowy shot
				{
					if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] >= ItemPrice( 1, 86 ) )
					{
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryShotPart]++;
						DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 86 );
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryShotPart" );
						SaveFData( gPlayerData[playerid][pFaction], "Bank" );
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_BOUGHT_PART_TXT, "Wróæ", "" );
						return 1;
					}
					else
					{
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_NOCASH_TXT, "Wróæ", "" );
						return 1;
					}
				}
				else if(gListItem[playerid] == 38) // zestaw montazowy rifle
				{
					if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] >= ItemPrice( 1, 88 ) )
					{
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart]++;
						DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 88 );
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryRiflePart" );
						SaveFData( gPlayerData[playerid][pFaction], "Bank" );
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_BOUGHT_PART_TXT, "Wróæ", "" );
						return 1;
					}
					else
					{
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_NOCASH_TXT, "Wróæ", "" );
						return 1;
					}
				}
				else if(gListItem[playerid] == 39) // zestaw montazowy sniper
				{
					if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] >= ItemPrice( 1, 89 ) )
					{
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactorySniperPart]++;
						DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 89 );
						SaveFData( gPlayerData[playerid][pFaction], "WFactorySniperPart" );
						SaveFData( gPlayerData[playerid][pFaction], "Bank" );
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_BOUGHT_PART_TXT, "Wróæ", "" );
						return 1;
					}
					else
					{
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_NOCASH_TXT, "Wróæ", "" );
						return 1;
					}
				}
				else if(gListItem[playerid] == 40) // zestaw montazowy des eag
				{
					if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] >= ItemPrice( 1, 87 ) )
					{
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryDesEaglePart]++;
						DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 87 );
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryDesEaglePart" );
						SaveFData( gPlayerData[playerid][pFaction], "Bank" );
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_BOUGHT_PART_TXT, "Wróæ", "" );
						return 1;
					}
					else
					{
						ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_NOCASH_TXT, "Wróæ", "" );
						return 1;
					}
				}
				ShowPlayerDialog( playerid, DIALOG_WMENU_5_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_NOSPAREPART_TXT, "Wróæ", "" );
				return 1;
			}
			else
			{
				format( string3, sizeof(string3),
				"34. Zestaw monta¿owy Tec9 [%d]\n35. Skrzynka monta¿owa MP5 [%d]\n36. Zestaw monta¿owy AK-47 [%d]\n37. Skrzynka montazowa M4 [%d]\n38. Rêkojeœæ prze³adowania [%d]\n39. Skrzynka monta¿owa karabinu [%d]\n40. Siatka maskuj¹ca [%d]\n41.Carbon [%d]",
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryTec9Part],
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryMP5Part],
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAK47Part],
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryM4Part],
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryShotPart],
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart],
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactorySniperPart],
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryDesEaglePart]);
				
				format( string2, sizeof(string2),
				"20. Proch œwiszcz¹cy [%d]\n21. Sp³onka do strzelby [%d]\n22. Pocisk 7.62mm [%d]\n23. £uska 7.62mm [%d]\n24. Proch czarny [%d]\n25. Sp³onka 7.62 [%d]\n26. Pocisk 12.7mm [%d]\n27. £uska 12.7mm [%d]\n28. Proch bobinit [%d]\n29. Sp³onka 12.7mm [%d]\n30. Pocisk .50AE [%d]\n31. £uska .50AE [%d]\n32. Proch ignis volatilis [%d]\n33. Sp³onka .50AE [%d]",
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryAmmoPart3b],
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryAmmoPart4b],
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryAmmoPart1c],
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryAmmoPart2c],
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryAmmoPart3c],
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryAmmoPart4c],
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryAmmoPart1d],
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryAmmoPart2d],
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryAmmoPart3d],
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryAmmoPart4d],
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryAmmoPart1e],
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryAmmoPart2e],
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryAmmoPart3e],
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryAmmoPart4e] );
				
				format( string, sizeof(string),
				"1. Szkielet broni [%d]\n2. Zespó³ zamka [%d]\n3. Magazynek [%d]\n4. Sprê¿yna powrotna [%d]\n5. Komplet œrubek [%d]\n6. T³umik [%d]\n7. Szkielet broni karabinowej [%d]\n8. Zespó³ zamka karabinu [%d]\n9. Magazynek karabinu [%d]\n10. Sprê¿yna powrotna karabinu [%d]\n11. Kolba [%d]\n12. Komplet œrubek karabinu [%d]\n13. Luneta [%d]\n14. Pocisk 9mm [%d]\n15. £uska 9mm [%d]\n16. Proch admidowy [%d]\n17. Sp³onka 9mm [%d]\n18. O³ów [%d]\n19. £uska do strzelby [%d]\n%s\n%s",
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryPistolPart1],
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryPistolPart2],
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryPistolPart3],
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryPistolPart4],
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryPistolPart5],
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryPistolPart6],
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryRiflePart1],
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryRiflePart2],
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryRiflePart3],
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryRiflePart4],
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryRiflePart5],
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryRiflePart6],
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryRiflePart7],
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryAmmoPart1a],
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryAmmoPart2a],
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryAmmoPart3a],
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryAmmoPart4a],
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryAmmoPart1b],
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryAmmoPart2b],
				string2,
				string3 );
				
				gListItem[playerid] = listitem;
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_3_PARTS_MMAKE, DIALOG_STYLE_LIST, DIALOG_WMENU_TITLE_TXT, string, "Wybierz", "Wróæ" );
				
				return 1;
			}
		}
		case DIALOG_WMENU_5_PARTS_MMAKE:
		{
			listitem = gListItem[playerid];
			if (listitem == 0) // szkielet broni
			{
				format( string, sizeof(string), "Nazwa: %s\nDostêpna iloœæ w magazynie frakcji: %d\nWymagane czêœci:\n- lufa [%d/1]\n- mechanizm spustowo-uderzeniowy [%d/1]\n- nak³adki z tworzywa sztucznego [%d/1]",
				ItemName( 1, 48 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart1],
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolS1Part1],
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolS1Part2],
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolS1Part3] );
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Zmontuj", "Wróæ" );
				return 1;
			}
			else if (listitem == 1) // Zespó³ zamka
			{
				format( string, sizeof(string), "Nazwa: %s\nDostêpna iloœæ w magazynie frakcji: %d\nWymagane czêœci:\n- mechanizm iglicy [%d/1]\n- bezpiecznik typu listkowego [%d/1]\n- przyrz¹dy celownicze [%d/1]",
				ItemName( 1, 49 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart2],
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolS2Part1],
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolS2Part2],
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolS2Part3] );
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Zmontuj", "Wróæ" );
				return 1;
			}
			else if (listitem == 2) // Magazynek
			{
				format( string, sizeof(string), "Nazwa: %s\nDostêpna iloœæ w magazynie frakcji: %d\nWymagane czêœci:\n- szkielet [%d/1]\n- stopka [%d/1]\n- wew. sprê¿yna [%d/1]\n- dosy³acz [%d/1]",
				ItemName( 1, 50 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart3],
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolS3Part1],
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolS3Part2],
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolS3Part3],
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolS3Part4] );
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Zmontuj", "Wróæ" );
				return 1;
			}
			else if (listitem == 3) // sprê¿yna powrotna
			{
				format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
				ItemName( 1, 51 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart4],
				ItemPrice( 1, 51 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
				return 1;
			}
			else if (listitem == 4) // komplet œrubek
			{
				format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
				ItemName( 1, 52 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart5],
				ItemPrice( 1, 52 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
				return 1;
			}
			else if (listitem == 5) // t³umik
			{
				format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
				ItemName( 1, 59 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart6],
				ItemPrice( 1, 59 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
				return 1;
			}
			else if (listitem == 6) // szkielet broni karabinowej
			{
				format( string, sizeof(string), "Nazwa: %s\nDostêpna iloœæ w magazynie frakcji: %d\nWymagane czêœci:\n- lufa karabinu [%d/1]\n- mechanizm spustowo-uderzeniowy karabinu [%d/1]\n- nak³adki z tworzywa sztucznego [%d/1]",
				ItemName( 1, 53 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart1],
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRifleS1Part1],
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRifleS1Part2],
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolS1Part3] );
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Zmontuj", "Wróæ" );
				return 1;
			}
			else if (listitem == 7) // zespó³ zamka karabinu
			{
				format( string, sizeof(string), "Nazwa: %s\nDostêpna iloœæ w magazynie frakcji: %d\nWymagane czêœci:\n- mechanizm iglicy karabinu [%d/1]\n- bezpiecznik typu listkowego karabinu [%d/1]\n- przyrz¹dy celownicze karabinu [%d/1]",
				ItemName( 1, 54 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart2],
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRifleS2Part1],
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRifleS2Part2],
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRifleS2Part3] );
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Zmontuj", "Wróæ" );
				return 1;
			}
			else if (listitem == 8) // magazynek karabinu
			{
				format( string, sizeof(string), "Nazwa: %s\nDostêpna iloœæ w magazynie frakcji: %d\nWymagane czêœci:\n- szkielet karabinu [%d/1]\n- stopka karabinu [%d/1]\n- wew. sprê¿yna karabinu [%d/1]\n- dosy³acz karabinu [%d/1]",
				ItemName( 1, 55 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart3],
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRifleS3Part1],
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRifleS3Part2],
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRifleS3Part3],
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRifleS3Part4] );
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Zmontuj", "Wróæ" );
				return 1;
			}
			else if (listitem == 9) // sprê¿yna powrotna karabinu
			{
				format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
				ItemName( 1, 56 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart4],
				ItemPrice( 1, 56 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
				return 1;
			}
			else if (listitem == 10) // kolba
			{
				format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
				ItemName( 1, 57 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart5],
				ItemPrice( 1, 57 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
				return 1;
			}
			else if (listitem == 11) // komplet œrubek karabinu
			{
				format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
				ItemName( 1, 58 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart6],
				ItemPrice( 1, 58 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
				return 1;
			}
			else if (listitem == 12) // luneta
			{
				format( string, sizeof(string), "Nazwa: %s\nDostêpna iloœæ w magazynie frakcji: %d\nWymagane czêœci:\n- szkielet lunety [%d/1]\n- soczewki [%d/1]",
				ItemName( 1, 58 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart6],
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRifleS6Part1],
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRifleS6Part2] );
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Zmontuj", "Wróæ" );
				return 1;
			}
			else if (listitem == 13) // pocisk 9mm
			{
				format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
				ItemName( 1, 43 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart1a],
				ItemPrice( 1, 43 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
				return 1;
			}
			else if (listitem == 14) // ³uska 9mm
			{
				format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
				ItemName( 1, 44 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart2a],
				ItemPrice( 1, 44 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
				return 1;
			}
			else if (listitem == 15) // proch 1gr
			{
				format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
				ItemName( 1, 45 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart3a],
				ItemPrice( 1, 45 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
				return 1;
			}
			else if (listitem == 16) // sp³onka 9mm
			{
				format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
				ItemName( 1, 46 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart4a],
				ItemPrice( 1, 46 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
				return 1;
			}
			else if (listitem == 17) // o³ów
			{
				format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
				ItemName( 1, 47 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart1b],
				ItemPrice( 1, 47 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
				return 1;
			}
			else if (listitem == 18) // ³uska do strzelby
			{
				format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
				ItemName( 1, 90 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart2b],
				ItemPrice( 1, 90 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
				return 1;
			}
			else if (listitem == 19) // proch 5gr
			{
				format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
				ItemName( 1, 91 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart3b],
				ItemPrice( 1, 91 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
				return 1;
			}
			else if (listitem == 20) // sp³onka do strzelby
			{
				format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
				ItemName( 1, 92 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart4b],
				ItemPrice( 1, 92 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
				return 1;
			}
			else if (listitem == 21) // pocisk karabinu
			{
				format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
				ItemName( 1, 93 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart1c],
				ItemPrice( 1, 93 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
				return 1;
			}
			else if (listitem == 22) // ³uska karabinu
			{
				format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
				ItemName( 1, 94 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart2c],
				ItemPrice( 1, 94 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
				return 1;
			}
			else if (listitem == 23) // proch 3gr
			{
				format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
				ItemName( 1, 95 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart3c],
				ItemPrice( 1, 95 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
				return 1;
			}
			else if (listitem == 24) // sp³onka karabinu
			{
				format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
				ItemName( 1, 96 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart4c],
				ItemPrice( 1, 96 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
				return 1;
			}
			else if (listitem == 25) // pocisk snajp
			{
				format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
				ItemName( 1, 97 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart1d],
				ItemPrice( 1, 97 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
				return 1;
			}
			else if (listitem == 26) // ³uska snajp
			{
				format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
				ItemName( 1, 98 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart2d],
				ItemPrice( 1, 98 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
				return 1;
			}
			else if (listitem == 27) // proch 10gr
			{
				format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
				ItemName( 1, 99 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart3d],
				ItemPrice( 1, 99 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
				return 1;
			}
			else if (listitem == 28) // sp³onka snajp
			{
				format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
				ItemName( 1, 100 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart4d],
				ItemPrice( 1, 100 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
				return 1;
			}
			else if (listitem == 29) // pocisk des ea
			{
				format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
				ItemName( 1, 101 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart1e],
				ItemPrice( 1, 101 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
				return 1;
			}
			else if (listitem == 30) // ³uska des ea
			{
				format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
				ItemName( 1, 102 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart2e],
				ItemPrice( 1, 102 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
				return 1;
			}
			else if (listitem == 31) // proch 2gr
			{
				format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
				ItemName( 1, 103 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart3e],
				ItemPrice( 1, 103 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
				return 1;
			}
			else if (listitem == 32) // sp³onka des ea
			{
				format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
				ItemName( 1, 104 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAmmoPart4e],
				ItemPrice( 1, 104 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
				return 1;
			}
			else if (listitem == 33) // zestaw montazowy tec9
			{
				format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
				ItemName( 1, 82 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryTec9Part],
				ItemPrice( 1, 82 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
				return 1;
			}
			else if (listitem == 34) // zestaw montazowy MP5
			{
				format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
				ItemName( 1, 83 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryMP5Part],
				ItemPrice( 1, 83 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
				return 1;
			}
			else if (listitem == 35) // zestaw montazowy AK47
			{
				format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
				ItemName( 1, 84 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryAK47Part],
				ItemPrice( 1, 84 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
				return 1;
			}
			else if (listitem == 36) // zestaw montazowy M4
			{
				format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
				ItemName( 1, 85 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryM4Part],
				ItemPrice( 1, 85 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
				return 1;
			}
			else if (listitem == 37) // zestaw montazowy shot
			{
				format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
				ItemName( 1, 86 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryShotPart],
				ItemPrice( 1, 86 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
				return 1;
			}
			else if (listitem == 38) // zestaw montazowy rifle
			{
				format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
				ItemName( 1, 88 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRiflePart],
				ItemPrice( 1, 88 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
				return 1;
			}
			else if (listitem == 39) // zestaw montazowy sniper
			{
				format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
				ItemName( 1, 89 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactorySniperPart],
				ItemPrice( 1, 89 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
				return 1;
			}
			else if (listitem == 40) // zestaw montazowy des eagl
			{
				format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
				ItemName( 1, 87 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryDesEaglePart],
				ItemPrice( 1, 87 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_MMAKE, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
				return 1;
			}
			return 1;
		}
		case DIALOG_WMENU_3_PARTS_SBUY:
		{
			if (response)
			{
				gListItem[playerid] = listitem;
				if (listitem == 0) // lufa
				{
					format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
					ItemName( 1, 61 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolS1Part1],
					ItemPrice( 1, 61 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_SBUY, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
				}
				else if (listitem == 1) // mechanizm spustowo-uderzeniowy
				{
					format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
					ItemName( 1, 62 ),
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryPistolS1Part2],
					ItemPrice( 1, 62 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_SBUY, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
				}
				else if (listitem == 2) // nak³adki z tworzywa sztucznego
				{
					format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
					ItemName( 1, 63 ),
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryPistolS1Part3],
					ItemPrice( 1, 63 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_SBUY, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
				}
				else if (listitem == 3) // mechanizm iglicy
				{
					format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
					ItemName( 1, 64 ),
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryPistolS2Part1],
					ItemPrice( 1, 64 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_SBUY, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
				}
				else if (listitem == 4) // bezpiecznik typu listkowego
				{
					format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
					ItemName( 1, 65 ),
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryPistolS2Part2],
					ItemPrice( 1, 65 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_SBUY, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
				}
				else if (listitem == 5) // przyrz¹dy celownicze
				{
					format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
					ItemName( 1, 66 ),
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryPistolS2Part3],
					ItemPrice( 1, 66 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_SBUY, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
				}
				else if (listitem == 6) // szkielet
				{
					format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
					ItemName( 1, 67 ),
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryPistolS3Part1],
					ItemPrice( 1, 67 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_SBUY, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
				}
				else if (listitem == 7) // stopka
				{
					format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
					ItemName( 1, 68 ),
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryPistolS3Part2],
					ItemPrice( 1, 68 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_SBUY, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
				}
				else if (listitem == 8) // wew. sprê¿yna
				{
					format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
					ItemName( 1, 69 ),
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryPistolS3Part3],
					ItemPrice( 1, 69 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_SBUY, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
				}
				else if (listitem == 9) // dosy³acz
				{
					format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
					ItemName( 1, 70 ),
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryPistolS3Part4],
					ItemPrice( 1, 70 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_SBUY, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
				}
				else if (listitem == 10) // lufa karabinu
				{
					format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
					ItemName( 1, 71 ),
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryRifleS1Part1],
					ItemPrice( 1, 71 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_SBUY, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
				}
				else if (listitem == 11) // mechanizm spustowo-uderzeniowy karabinu
				{
					format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
					ItemName( 1, 72 ),
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryRifleS1Part2],
					ItemPrice( 1, 72 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_SBUY, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
				}
				else if (listitem == 12) // mechanizm iglicy karabinu
				{
					format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
					ItemName( 1, 73 ),
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryRifleS2Part1],
					ItemPrice( 1, 73 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_SBUY, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
				}
				else if (listitem == 13) // bezpiecznik typu listkowego karabinu
				{
					format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
					ItemName( 1, 74 ),
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryRifleS2Part2],
					ItemPrice( 1, 74 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_SBUY, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
				}
				else if (listitem == 14) // przyrz¹dy celownicze karabinu
				{
					format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
					ItemName( 1, 75 ),
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryRifleS2Part3],					
					ItemPrice( 1, 75 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_SBUY, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
				}
				else if (listitem == 15) // szkielet karabinu
				{
					format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
					ItemName( 1, 76 ),
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryRifleS3Part1],
					ItemPrice( 1, 76 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_SBUY, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
				}
				else if (listitem == 16) // stopka
				{
					format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
					ItemName( 1, 77 ),
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryRifleS3Part2],
					ItemPrice( 1, 77 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_SBUY, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
				}
				else if (listitem == 17) // wew. sprê¿yna karabinu
				{
					format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
					ItemName( 1, 78 ),
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryRifleS3Part3],
					ItemPrice( 1, 78 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_SBUY, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
				}
				else if (listitem == 18) // dosy³acz
				{
					format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
					ItemName( 1, 79 ),
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryRifleS3Part4],
					ItemPrice( 1, 79 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_SBUY, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
				}
				else if (listitem == 19) // szkielet
				{
					format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
					ItemName( 1, 80 ),
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryRifleS6Part1],
					ItemPrice( 1, 80 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_SBUY, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
				}
				else if (listitem == 20) // soczewki
				{
					format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
					ItemName( 1, 81 ),
					DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryRifleS6Part2],
					ItemPrice( 1, 81 ),
					DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
					
					ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_SBUY, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
				}
				return 1;
			}
			else
			{
				format( string, sizeof(string),
				"1. Czêœci g³ówne\n2. Podczêœci");
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_2_PARTS, DIALOG_STYLE_LIST, DIALOG_WMENU_TITLE_TXT, string, "Wybierz", "Wróæ" );
				
				return 1;
			}
		}
		case DIALOG_WMENU_4_PARTS_SBUY:
		{
			if (response)
			{
				new bought = 0;
				switch(gListItem[playerid])
				{
					case 0:
					{
						if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] > ItemPrice( 1, 61 ) )
						{
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolS1Part1]++;
							DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 61 );
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolS1Part1" );
							SaveFData( gPlayerData[playerid][pFaction], "Bank" );
							bought = 1;
						}
					}
					case 1:
					{
						if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] > ItemPrice( 1, 62 ) )
						{
							DynamicFactions[ gPlayerData[playerid][pFaction]] [WFactoryPistolS1Part2]++;
							DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 62 );
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolS1Part2" );
							SaveFData( gPlayerData[playerid][pFaction], "Bank" );
							bought = 1;
						}
					}
					case 2:
					{
						if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] > ItemPrice( 1, 63 ) )
						{
							DynamicFactions[ gPlayerData[playerid][pFaction]] [WFactoryPistolS1Part3]++;
							DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 62 );
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolS1Part3" );
							SaveFData( gPlayerData[playerid][pFaction], "Bank" );
							bought = 1;
						}
					}
					case 3:
					{
						if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] > ItemPrice( 1, 64 ) )
						{
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolS2Part1]++;
							DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 64 );
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolS2Part1" );
							SaveFData( gPlayerData[playerid][pFaction], "Bank" );
							bought = 1;
						}
					}
					case 4:
					{
						if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] > ItemPrice( 1, 65 ) )
						{
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolS2Part2]++;
							DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 65 );
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolS2Part2" );
							SaveFData( gPlayerData[playerid][pFaction], "Bank" );
							bought = 1;
						}
					}
					case 5:
					{
						if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] > ItemPrice( 1, 66 ) )
						{
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolS2Part3]++;
							DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 66 );
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolS2Part3" );
							SaveFData( gPlayerData[playerid][pFaction], "Bank" );
							bought = 1;
						}
					}
					case 6:
					{
						if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] > ItemPrice( 1, 67 ) )
						{
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolS3Part1]++;
							DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 67 );
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolS3Part1" );
							SaveFData( gPlayerData[playerid][pFaction], "Bank" );
							bought = 1;
						}
					}
					case 7:
					{
						if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] > ItemPrice( 1, 68 ) )
						{
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolS3Part2]++;
							DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 68 );
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolS3Part2" );
							SaveFData( gPlayerData[playerid][pFaction], "Bank" );
							bought = 1;
						}
					}
					case 8:
					{
						if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] > ItemPrice( 1, 69 ) )
						{
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolS3Part3]++;
							DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 69 );
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolS3Part3" );
							SaveFData( gPlayerData[playerid][pFaction], "Bank" );
							bought = 1;
						}
					}
					case 9:
					{
						if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] > ItemPrice( 1, 70 ) )
						{
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolS3Part4]++;
							DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 70 );
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolS3Part4" );
							SaveFData( gPlayerData[playerid][pFaction], "Bank" );
							bought = 1;
						}
					}
					case 10:
					{
						if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] > ItemPrice( 1, 71 ) )
						{
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRifleS1Part1]++;
							DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 71 );
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryRifleS1Part1" );
							SaveFData( gPlayerData[playerid][pFaction], "Bank" );
							bought = 1;
						}
					}
					case 11:
					{
						if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] > ItemPrice( 1, 72 ) )
						{
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRifleS1Part2]++;
							DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 72 );
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryRifleS1Part2" );
							SaveFData( gPlayerData[playerid][pFaction], "Bank" );
							bought = 1;
						}
					}
					case 12:
					{
						if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] > ItemPrice( 1, 73 ) )
						{
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRifleS2Part1]++;
							DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 73 );
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryRifleS2Part1" );
							SaveFData( gPlayerData[playerid][pFaction], "Bank" );
							bought = 1;
						}
					}
					case 13:
					{
						if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] > ItemPrice( 1, 74 ) )
						{
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRifleS2Part2]++;
							DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 74 );
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryRifleS2Part2" );
							SaveFData( gPlayerData[playerid][pFaction], "Bank" );
							bought = 1;
						}
					}
					case 14:
					{
						if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] > ItemPrice( 1, 75 ) )
						{
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRifleS2Part3]++;
							DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 75 );
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryRifleS2Part3" );
							SaveFData( gPlayerData[playerid][pFaction], "Bank" );
							bought = 1;
						}
					}
					case 15:
					{
						if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] > ItemPrice( 1, 76 ) )
						{
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRifleS3Part1]++;
							DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 76 );
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryRifleS3Part1" );
							SaveFData( gPlayerData[playerid][pFaction], "Bank" );
							bought = 1;
						}
					}
					case 16:
					{
						if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] > ItemPrice( 1, 77 ) )
						{
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRifleS3Part2]++;
							DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 77 );
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryRifleS3Part2" );
							SaveFData( gPlayerData[playerid][pFaction], "Bank" );
							bought = 1;
						}
					}
					case 17:
					{
						if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] > ItemPrice( 1, 78 ) )
						{
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRifleS3Part3]++;
							DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 78 );
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryRifleS3Part3" );
							SaveFData( gPlayerData[playerid][pFaction], "Bank" );
							bought = 1;
						}
					}
					case 18:
					{
						if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] > ItemPrice( 1, 79 ) )
						{
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRifleS3Part4]++;
							DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 79 );
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryRifleS3Part4" );
							SaveFData( gPlayerData[playerid][pFaction], "Bank" );
							bought = 1;
						}
					}
					case 19:
					{
						if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] > ItemPrice( 1, 80 ) )
						{
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRifleS6Part1]++;
							DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 80 );
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryRifleS6Part1" );
							SaveFData( gPlayerData[playerid][pFaction], "Bank" );
							bought = 1;
						}
					}
					case 20:
					{
						if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] > ItemPrice( 1, 81 ) )
						{
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryRifleS6Part2]++;
							DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] -= ItemPrice( 1, 81 );
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryRifleS6Part2" );
							SaveFData( gPlayerData[playerid][pFaction], "Bank" );
							bought = 1;
						}
					}
				}
				if (bought == 1)
				{
					ShowPlayerDialog(playerid, DIALOG_WMENU_5_PARTS_SBUY, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, "Kupi³eœ czêœæ !", "Wróæ", "");
					return 1;
				}
				else
				{
					ShowPlayerDialog(playerid, DIALOG_WMENU_5_PARTS_SBUY, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, "Brakuje pieniêdzy w kasie frakcji !", "Wróæ", "");
					return 1;
				}
			}
			else
			{
				format( string, sizeof(string),
				"1. Lufa [%d]\n2. Mechanizm spustowo-uderzeniowy [%d]\n3. Nak³adki z tworzywa sztucznego [%d]\n4. Mechanizm iglicy [%d]\n5. Bezpiecznik typu listkowego [%d]\n6. Przyrz¹dy celownicze [%d]\n7. Szkielet [%d]\n8. Stopka [%d]\n9. Wew. sprê¿yna [%d]\n10. Dosy³acz [%d]\n11. Lufa karabinu [%d]\n12. Mechanizm spustowo-uderzeniowy karabinu [%d]\n13. Mechanizm iglicy karabinu [%d]",
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryPistolS1Part1],
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryPistolS1Part2],
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryPistolS1Part3],
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryPistolS2Part1],
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryPistolS2Part2],
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryPistolS2Part3],
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryPistolS3Part1],
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryPistolS3Part2],
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryPistolS3Part3],
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryPistolS3Part4],
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryRifleS1Part1],
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryRifleS1Part2],
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryRifleS2Part1] );
				
				format( string2, sizeof(string2),
				"14. Bezpiecznik typu listkowego karabinu [%d]\n15. Przyrz¹dy celownicze karabinu [%d]\n16. Szkielet karabinu [%d]\n17. Stopka karabinu [%d]\n18. Wew. sprê¿yna karabinu [%d]\n19. Dosy³acz karabinu [%d]\n20. Szkielet lunety [%d]\n21. Soczewki [%d]",
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryRifleS2Part2],
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryRifleS2Part3],
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryRifleS3Part1],
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryRifleS3Part2],
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryRifleS3Part3],
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryRifleS3Part4],
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryRifleS6Part1],
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryRifleS6Part2] );
				
				format( string, sizeof(string), "%s\n%s", string, string2 );
				
				gListItem[playerid] = listitem;
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_3_PARTS_SBUY, DIALOG_STYLE_LIST, DIALOG_WMENU_TITLE_TXT, string, "Wybierz", "Wróæ" );
				
				return 1;
			}
		}	
		case DIALOG_WMENU_5_PARTS_SBUY:
		{
			listitem = gListItem[playerid];
			if (listitem == 0)
			{
				format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
				ItemName( 1, 61 ),
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryPistolS1Part1],
				ItemPrice( 1, 61 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_SBUY, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
			}
			else if(listitem == 1)
			{
				format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
				ItemName( 1, 62 ),
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryPistolS1Part2],
				ItemPrice( 1, 62 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_SBUY, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
			}
			else if (listitem == 2)
			{
				format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
				ItemName( 1, 63 ),
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryPistolS1Part3],
				ItemPrice( 1, 63 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_SBUY, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
			}
			else if (listitem == 3)
			{
				format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
				ItemName( 1, 64 ),
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryPistolS2Part1],
				ItemPrice( 1, 64 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_SBUY, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
			}
			else if (listitem == 4)
			{
				format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
				ItemName( 1, 65 ),
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryPistolS2Part2],
				ItemPrice( 1, 65 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_SBUY, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
			}
			else if (listitem == 5)
			{
				format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
				ItemName( 1, 66 ),
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryPistolS2Part3],
				ItemPrice( 1, 66 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_SBUY, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
			}
			else if (listitem == 6)
			{
				format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
				ItemName( 1, 67 ),
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryPistolS3Part1],
				ItemPrice( 1, 67 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_SBUY, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
			}
			else if (listitem == 7)
			{
				format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
				ItemName( 1, 68 ),
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryPistolS3Part2],
				ItemPrice( 1, 68 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_SBUY, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
			}
			else if (listitem == 8)
			{
				format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
				ItemName( 1, 69 ),
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryPistolS3Part3],
				ItemPrice( 1, 69 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_SBUY, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
			}
			else if (listitem == 9)
			{
				format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
				ItemName( 1, 70 ),
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryPistolS3Part4],
				ItemPrice( 1, 70 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_SBUY, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
			}
			else if (listitem == 10)
			{
				format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
				ItemName( 1, 71 ),
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryRifleS1Part1],
				ItemPrice( 1, 71 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_SBUY, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
			}
			else if (listitem == 11)
			{
				format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
				ItemName( 1, 72 ),
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryRifleS1Part2],
				ItemPrice( 1, 72 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_SBUY, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
			}
			else if (listitem == 12)
			{
				format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
				ItemName( 1, 73 ),
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryRifleS2Part1],
				ItemPrice( 1, 73 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_SBUY, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
			}
			else if (listitem == 13)
			{
				format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
				ItemName( 1, 74 ),
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryRifleS2Part2],
				ItemPrice( 1, 74 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_SBUY, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
			}
			else if (listitem == 14)
			{
				format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
				ItemName( 1, 75 ),
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryRifleS2Part3],					
				ItemPrice( 1, 75 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_SBUY, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
			}
			else if (listitem == 15)
			{
				format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
				ItemName( 1, 76 ),
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryRifleS3Part1],
				ItemPrice( 1, 76 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_SBUY, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
			}
			else if (listitem == 16)
			{
				format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
				ItemName( 1, 77 ),
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryRifleS3Part2],
				ItemPrice( 1, 77 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_SBUY, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
			}
			else if (listitem == 17)
			{
				format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
				ItemName( 1, 78 ),
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryRifleS3Part3],
				ItemPrice( 1, 78 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_SBUY, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
			}
			else if (listitem == 18)
			{
				format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
				ItemName( 1, 79 ),
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryRifleS3Part4],
				ItemPrice( 1, 79 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_SBUY, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
			}
			else if (listitem == 19)
			{
				format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
				ItemName( 1, 80 ),
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryRifleS6Part1],
				ItemPrice( 1, 80 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_SBUY, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
			}
			else if (listitem == 20)
			{
				format( string, sizeof(string), DIALOG_WMENU_BUY_CHECKOUT_TXT,
				ItemName( 1, 81 ),
				DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryRifleS6Part2],
				ItemPrice( 1, 81 ),
				DynamicFactions[ gPlayerData[playerid][pFaction] ][fBank] );
				
				ShowPlayerDialog( playerid, DIALOG_WMENU_4_PARTS_SBUY, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Kup", "Wróæ" );
			}
			return 1;
		}
		case DIALOG_BUYW_1:
		{
			if( response )
			{
				switch( listitem )
				{
					case 0: // broñ
					{
						format( string, sizeof( string ), DIALOG_BUYW_TXT, 
						Businesses[ gBuyBusiness[playerid] ][W9MM], ItemPrice( 1, 16 ), 
						Businesses[ gBuyBusiness[playerid] ][W9MMSil], ItemPrice( 1, 17 ), 
						Businesses[ gBuyBusiness[playerid] ][WDesEagle], ItemPrice( 1, 18 ), 
						Businesses[ gBuyBusiness[playerid] ][WMicroSMG], ItemPrice( 1, 22 ), 
						Businesses[ gBuyBusiness[playerid] ][WMP5], ItemPrice( 1, 23 ), 
						Businesses[ gBuyBusiness[playerid] ][WTec9], ItemPrice( 1, 26 ), 
						Businesses[ gBuyBusiness[playerid] ][WShotgun], ItemPrice( 1, 19 ), 
						Businesses[ gBuyBusiness[playerid] ][WAK47], ItemPrice( 1, 24 ), 
						Businesses[ gBuyBusiness[playerid] ][WM4], ItemPrice( 1, 25 ), 
						Businesses[ gBuyBusiness[playerid] ][WRifle], ItemPrice( 1, 27 ), 
						Businesses[ gBuyBusiness[playerid] ][WSRifle], ItemPrice( 1, 28 ) );
						ShowPlayerDialog( playerid, DIALOG_BUYW_2W, DIALOG_STYLE_LIST, "Sklep z broni¹", string, "Kup", "Wróæ" );
						return 1;
					}
					case 1: // ammo
					{
						format( string, sizeof( string ), DIALOG_BUYA_TXT,
						Businesses[ gBuyBusiness[playerid] ][W9MMAmmo], ItemPrice( 1, 36 ),
						Businesses[ gBuyBusiness[playerid] ][W50AEAmmo], ItemPrice( 1, 37 ),
						Businesses[ gBuyBusiness[playerid] ][WBuckshot], ItemPrice( 1, 38 ),
						Businesses[ gBuyBusiness[playerid] ][W762MMAmmo], ItemPrice( 1, 39 ),
						Businesses[ gBuyBusiness[playerid] ][W127MMAmmo], ItemPrice( 1, 40 ) );
						ShowPlayerDialog( playerid, DIALOG_BUYW_2A, DIALOG_STYLE_LIST, "Sklep z broni¹", string, "Kup", "Wróæ" );
						return 1;
					}
				}
				return 1;
			}
		}
		case DIALOG_BUYW_2A:
		{
			if( response )
			{
				GOTO_BUYW_2A:
				gListItem[playerid] = listitem;
				if( gListOverItem[playerid] != -1 )
				{
					gListItem[playerid] = gListOverItem[playerid];
					gListOverItem[playerid] = -1;
				}
				switch( gListItem[playerid] )
				{
					case 0: // 9mm ammo
					{
						format( string, sizeof(string), DIALOG_WMENU_BUY_W_TXT,
						ItemName( 1, 36 ),
						Businesses[ gBuyBusiness[playerid] ][W9MMAmmo],
						ItemPrice( 1, 36 ) );
						
						ShowPlayerDialog( playerid, DIALOG_BUYW_3A, DIALOG_STYLE_MSGBOX, "Sklep z broni¹", string, "Kup", "Wróæ" );
					}
					case 1: // .50ae ammo
					{
						format( string, sizeof(string), DIALOG_WMENU_BUY_W_TXT,
						ItemName( 1, 37 ),
						Businesses[ gBuyBusiness[playerid] ][W50AEAmmo],
						ItemPrice( 1, 37 ) );
						
						ShowPlayerDialog( playerid, DIALOG_BUYW_3A, DIALOG_STYLE_MSGBOX, "Sklep z broni¹", string, "Kup", "Wróæ" );
					}
					case 2: // buckshot
					{
						format( string, sizeof(string), DIALOG_WMENU_BUY_W_TXT,
						ItemName( 1, 38 ),
						Businesses[ gBuyBusiness[playerid] ][WBuckshot],
						ItemPrice( 1, 38 ) );
						
						ShowPlayerDialog( playerid, DIALOG_BUYW_3A, DIALOG_STYLE_MSGBOX, "Sklep z broni¹", string, "Kup", "Wróæ" );
					}
					case 3: // 762mm ammo
					{
						format( string, sizeof(string), DIALOG_WMENU_BUY_W_TXT,
						ItemName( 1, 39 ),
						Businesses[ gBuyBusiness[playerid] ][W762MMAmmo],
						ItemPrice( 1, 39 ) );
						
						ShowPlayerDialog( playerid, DIALOG_BUYW_3A, DIALOG_STYLE_MSGBOX, "Sklep z broni¹", string, "Kup", "Wróæ" );
					}
					case 4: // 127mm ammo
					{
						format( string, sizeof(string), DIALOG_WMENU_BUY_W_TXT,
						ItemName( 1, 40 ),
						Businesses[ gBuyBusiness[playerid] ][W127MMAmmo],
						ItemPrice( 1, 40 ) );
						
						ShowPlayerDialog( playerid, DIALOG_BUYW_3A, DIALOG_STYLE_MSGBOX, "Sklep z broni¹", string, "Kup", "Wróæ" );
					}
				}
				return 1;
			}
			else
			{
				format( string, sizeof(string), "1.Broñ\n2.Amunicja" );
				ShowPlayerDialog( playerid, DIALOG_BUYW_1, DIALOG_STYLE_LIST, "Sklep z broni¹",
				string,
				"Wybierz","WyjdŸ");
				return 1;
			}
		}
		case DIALOG_BUYW_3A:
		{
			if( response )
			{
				gListOverItem[playerid] = gListItem[playerid];
				switch( gListItem[playerid] )
				{
					case 0: // 9mm ammo
					{
						if( Businesses[ gBuyBusiness[playerid] ][W9MMAmmo] <= 0 )
						{
							ShowPlayerDialog( playerid, DIALOG_BUYW_4A, DIALOG_STYLE_MSGBOX, "Sklep z broni¹", "Brak broni w sklepie !", "Wróæ", "" );
							return 1;
						}
						else
						{
							if( gPlayerData[playerid][pCash] < ItemPrice( 1, 36 ) )
							{
								ShowPlayerDialog( playerid, DIALOG_BUYW_4W, DIALOG_STYLE_MSGBOX, "Sklep z broni¹", "Nie masz wystarczaj¹cej iloœci pieniêdzy !", "Wróæ", "" );
								return 1;
							}
							if( InsertPlayerItemEx( playerid, 1, 36, 0, 0, 0, 0, "Puste", 10, true ) == -1 )
							{
								ShowPlayerDialog( playerid, DIALOG_BUYW_4W, DIALOG_STYLE_MSGBOX, "Sklep z broni¹", "Jesteœ przeci¹¿ony !", "Wróæ", "" );
								return 1;
							}
							Businesses[ gBuyBusiness[playerid] ][W9MMAmmo] -= 10;
							SaveBizData( gBuyBusiness[playerid], "W9MMAmmo" );
							GivePlayerCash( playerid, -ItemPrice( 1, 36 ) );
							Businesses[ gBuyBusiness[playerid] ][Till] += ItemPrice( 1, 36 );
							SaveBizData( gBuyBusiness[playerid], "Till" );
							goto GOTO_BUYW_2A;
						}
					}
					case 1: // .50 ae ammo
					{
						if( Businesses[ gBuyBusiness[playerid] ][W50AEAmmo] <= 0 )
						{
							ShowPlayerDialog( playerid, DIALOG_BUYW_4A, DIALOG_STYLE_MSGBOX, "Sklep z broni¹", "Brak broni w sklepie !", "Wróæ", "" );
							return 1;
						}
						else
						{
							if( gPlayerData[playerid][pCash] < ItemPrice( 1, 37 ) )
							{
								ShowPlayerDialog( playerid, DIALOG_BUYW_4W, DIALOG_STYLE_MSGBOX, "Sklep z broni¹", "Nie masz wystarczaj¹cej iloœci pieniêdzy !", "Wróæ", "" );
								return 1;
							}
							if( InsertPlayerItemEx( playerid, 1, 37, 0, 0, 0, 0, "Puste", 5, true ) == -1 )
							{
								ShowPlayerDialog( playerid, DIALOG_BUYW_4W, DIALOG_STYLE_MSGBOX, "Sklep z broni¹", "Jesteœ przeci¹¿ony !", "Wróæ", "" );
								return 1;
							}
							Businesses[ gBuyBusiness[playerid] ][W50AEAmmo] -= 5;
							SaveBizData( gBuyBusiness[playerid], "W50AEAmmo" );
							GivePlayerCash( playerid, -ItemPrice( 1, 37 ) );
							Businesses[ gBuyBusiness[playerid] ][Till] += ItemPrice( 1, 37 );
							SaveBizData( gBuyBusiness[playerid], "Till" );
							goto GOTO_BUYW_2A;
						}
					}
					case 2: // buckshot
					{
						if( Businesses[ gBuyBusiness[playerid] ][WBuckshot] <= 0 )
						{
							ShowPlayerDialog( playerid, DIALOG_BUYW_4A, DIALOG_STYLE_MSGBOX, "Sklep z broni¹", "Brak broni w sklepie !", "Wróæ", "" );
							return 1;
						}
						else
						{
							if( gPlayerData[playerid][pCash] < ItemPrice( 1, 38 ) )
							{
								ShowPlayerDialog( playerid, DIALOG_BUYW_4W, DIALOG_STYLE_MSGBOX, "Sklep z broni¹", "Nie masz wystarczaj¹cej iloœci pieniêdzy !", "Wróæ", "" );
								return 1;
							}
							if( InsertPlayerItemEx( playerid, 1, 38, 0, 0, 0, 0, "Puste", 5, true ) == -1 )
							{
								ShowPlayerDialog( playerid, DIALOG_BUYW_4W, DIALOG_STYLE_MSGBOX, "Sklep z broni¹", "Jesteœ przeci¹¿ony !", "Wróæ", "" );
								return 1;
							}
							Businesses[ gBuyBusiness[playerid] ][WBuckshot] -= 5;
							SaveBizData( gBuyBusiness[playerid], "WBuckshot" );
							GivePlayerCash( playerid, -ItemPrice( 1, 38 ) );
							Businesses[ gBuyBusiness[playerid] ][Till] += ItemPrice( 1, 38 );
							SaveBizData( gBuyBusiness[playerid], "Till" );
							goto GOTO_BUYW_2A;
						}
					}
					case 3: // 762mm ammo
					{
						if( Businesses[ gBuyBusiness[playerid] ][W762MMAmmo] <= 0 )
						{
							ShowPlayerDialog( playerid, DIALOG_BUYW_4A, DIALOG_STYLE_MSGBOX, "Sklep z broni¹", "Brak broni w sklepie !", "Wróæ", "" );
							return 1;
						}
						else
						{
							if( gPlayerData[playerid][pCash] < ItemPrice( 1, 39 ) )
							{
								ShowPlayerDialog( playerid, DIALOG_BUYW_4W, DIALOG_STYLE_MSGBOX, "Sklep z broni¹", "Nie masz wystarczaj¹cej iloœci pieniêdzy !", "Wróæ", "" );
								return 1;
							}
							if( InsertPlayerItemEx( playerid, 1, 39, 0, 0, 0, 0, "Puste", 5, true ) == -1 )
							{
								ShowPlayerDialog( playerid, DIALOG_BUYW_4W, DIALOG_STYLE_MSGBOX, "Sklep z broni¹", "Jesteœ przeci¹¿ony !", "Wróæ", "" );
								return 1;
							}
							Businesses[ gBuyBusiness[playerid] ][W762MMAmmo] -= 5;
							SaveBizData( gBuyBusiness[playerid], "W762MMAmmo" );
							GivePlayerCash( playerid, -ItemPrice( 1, 39 ) );
							Businesses[ gBuyBusiness[playerid] ][Till] += ItemPrice( 1, 39 );
							SaveBizData( gBuyBusiness[playerid], "Till" );
							goto GOTO_BUYW_2A;
						}
					}
					case 4: // 127mm ammo
					{
						if( Businesses[ gBuyBusiness[playerid] ][W127MMAmmo] <= 0 )
						{
							ShowPlayerDialog( playerid, DIALOG_BUYW_4A, DIALOG_STYLE_MSGBOX, "Sklep z broni¹", "Brak broni w sklepie !", "Wróæ", "" );
							return 1;
						}
						else
						{
							if( gPlayerData[playerid][pCash] < ItemPrice( 1, 40 ) )
							{
								ShowPlayerDialog( playerid, DIALOG_BUYW_4W, DIALOG_STYLE_MSGBOX, "Sklep z broni¹", "Nie masz wystarczaj¹cej iloœci pieniêdzy !", "Wróæ", "" );
								return 1;
							}
							if( InsertPlayerItemEx( playerid, 1, 40, 0, 0, 0, 0, "Puste", 5, true ) == -1 )
							{
								ShowPlayerDialog( playerid, DIALOG_BUYW_4W, DIALOG_STYLE_MSGBOX, "Sklep z broni¹", "Jesteœ przeci¹¿ony !", "Wróæ", "" );
								return 1;
							}
							Businesses[ gBuyBusiness[playerid] ][W127MMAmmo] -= 5;
							SaveBizData( gBuyBusiness[playerid], "W127MMAmmo" );
							GivePlayerCash( playerid, -ItemPrice( 1, 40 ) );
							Businesses[ gBuyBusiness[playerid] ][Till] += ItemPrice( 1, 40 );
							SaveBizData( gBuyBusiness[playerid], "Till" );
							goto GOTO_BUYW_2A;
						}
					}
				}
				return 1;
			}
			else
			{
				format( string, sizeof( string ), DIALOG_BUYA_TXT,
				Businesses[ gBuyBusiness[playerid] ][W9MMAmmo], ItemPrice( 1, 36 ),
				Businesses[ gBuyBusiness[playerid] ][W50AEAmmo], ItemPrice( 1, 37 ),
				Businesses[ gBuyBusiness[playerid] ][WBuckshot], ItemPrice( 1, 38 ),
				Businesses[ gBuyBusiness[playerid] ][W762MMAmmo], ItemPrice( 1, 39 ),
				Businesses[ gBuyBusiness[playerid] ][W127MMAmmo], ItemPrice( 1, 40 ) );
				ShowPlayerDialog( playerid, DIALOG_BUYW_2A, DIALOG_STYLE_LIST, "Sklep z broni¹", string, "Kup", "Wróæ" );
				return 1;
			}
		}
		case DIALOG_BUYW_4A:
		{
			format( string, sizeof( string ), DIALOG_BUYA_TXT,
			Businesses[ gBuyBusiness[playerid] ][W9MMAmmo], ItemPrice( 1, 36 ),
			Businesses[ gBuyBusiness[playerid] ][W50AEAmmo], ItemPrice( 1, 37 ),
			Businesses[ gBuyBusiness[playerid] ][WBuckshot], ItemPrice( 1, 38 ),
			Businesses[ gBuyBusiness[playerid] ][W762MMAmmo], ItemPrice( 1, 39 ),
			Businesses[ gBuyBusiness[playerid] ][W127MMAmmo], ItemPrice( 1, 40 ) );
			ShowPlayerDialog( playerid, DIALOG_BUYW_2A, DIALOG_STYLE_LIST, "Sklep z broni¹", string, "Kup", "Wróæ" );
			return 1;
		}
		case DIALOG_BUYW_2W:
		{
			if( response )
			{
				GOTO_BUYW_2W:
				gListItem[playerid] = listitem;
				if( gListOverItem[playerid] != -1 )
				{
					gListItem[playerid] = gListOverItem[playerid];
					gListOverItem[playerid] = -1;
				}
				switch( gListItem[playerid] )
				{
					case 0: // 9MM
					{
						format( string, sizeof(string), DIALOG_WMENU_BUY_W_TXT,
						ItemName( 1, 16 ),
						Businesses[ gBuyBusiness[playerid] ][W9MM],
						ItemPrice( 1, 16 ) );
						
						ShowPlayerDialog( playerid, DIALOG_BUYW_3W, DIALOG_STYLE_MSGBOX, "Sklep z broni¹", string, "Kup", "Wróæ" );
					}
					case 1: // 9mm sil
					{
						format( string, sizeof(string), DIALOG_WMENU_BUY_W_TXT,
						ItemName( 1, 17 ),
						Businesses[ gBuyBusiness[playerid] ][W9MMSil],
						ItemPrice( 1, 17 ) );
						
						ShowPlayerDialog( playerid, DIALOG_BUYW_3W, DIALOG_STYLE_MSGBOX, "Sklep z broni¹", string, "Kup", "Wróæ" );
					}
					case 2: // deag
					{
						format( string, sizeof(string), DIALOG_WMENU_BUY_W_TXT,
						ItemName( 1, 18 ),
						Businesses[ gBuyBusiness[playerid] ][WDesEagle],
						ItemPrice( 1, 18 ) );
						
						ShowPlayerDialog( playerid, DIALOG_BUYW_3W, DIALOG_STYLE_MSGBOX, "Sklep z broni¹", string, "Kup", "Wróæ" );
					}
					case 3: // msmg
					{
						format( string, sizeof(string), DIALOG_WMENU_BUY_W_TXT,
						ItemName( 1, 22 ),
						Businesses[ gBuyBusiness[playerid] ][WMicroSMG],
						ItemPrice( 1, 22 ) );
						
						ShowPlayerDialog( playerid, DIALOG_BUYW_3W, DIALOG_STYLE_MSGBOX, "Sklep z broni¹", string, "Kup", "Wróæ" );
					}
					case 4: // mp5
					{
						format( string, sizeof(string), DIALOG_WMENU_BUY_W_TXT,
						ItemName( 1, 23 ),
						Businesses[ gBuyBusiness[playerid] ][WMP5],
						ItemPrice( 1, 23 ) );
						
						ShowPlayerDialog( playerid, DIALOG_BUYW_3W, DIALOG_STYLE_MSGBOX, "Sklep z broni¹", string, "Kup", "Wróæ" );
					}
					case 5: // tec9
					{
						format( string, sizeof(string), DIALOG_WMENU_BUY_W_TXT,
						ItemName( 1, 26 ),
						Businesses[ gBuyBusiness[playerid] ][WTec9],
						ItemPrice( 1, 26 ) );
						
						ShowPlayerDialog( playerid, DIALOG_BUYW_3W, DIALOG_STYLE_MSGBOX, "Sklep z broni¹", string, "Kup", "Wróæ" );
					}
					case 6: // shot
					{
						format( string, sizeof(string), DIALOG_WMENU_BUY_W_TXT,
						ItemName( 1, 19 ),
						Businesses[ gBuyBusiness[playerid] ][WShotgun],
						ItemPrice( 1, 19 ) );
						
						ShowPlayerDialog( playerid, DIALOG_BUYW_3W, DIALOG_STYLE_MSGBOX, "Sklep z broni¹", string, "Kup", "Wróæ" );
					}
					case 7: // ak47
					{
						format( string, sizeof(string), DIALOG_WMENU_BUY_W_TXT,
						ItemName( 1, 24 ),
						Businesses[ gBuyBusiness[playerid] ][WAK47],
						ItemPrice( 1, 24 ) );
						
						ShowPlayerDialog( playerid, DIALOG_BUYW_3W, DIALOG_STYLE_MSGBOX, "Sklep z broni¹", string, "Kup", "Wróæ" );
					}
					case 8: // m4
					{
						format( string, sizeof(string), DIALOG_WMENU_BUY_W_TXT,
						ItemName( 1, 25 ),
						Businesses[ gBuyBusiness[playerid] ][WM4],
						ItemPrice( 1, 25 ) );
						
						ShowPlayerDialog( playerid, DIALOG_BUYW_3W, DIALOG_STYLE_MSGBOX, "Sklep z broni¹", string, "Kup", "Wróæ" );
					}
					case 9: // rifle
					{
						format( string, sizeof(string), DIALOG_WMENU_BUY_W_TXT,
						ItemName( 1, 27 ),
						Businesses[ gBuyBusiness[playerid] ][WRifle],
						ItemPrice( 1, 27 ) );
						
						ShowPlayerDialog( playerid, DIALOG_BUYW_3W, DIALOG_STYLE_MSGBOX, "Sklep z broni¹", string, "Kup", "Wróæ" );
					}
					case 10: // srifle
					{
						format( string, sizeof(string), DIALOG_WMENU_BUY_W_TXT,
						ItemName( 1, 28 ),
						Businesses[ gBuyBusiness[playerid] ][WSRifle],
						ItemPrice( 1, 28 ) );
						
						ShowPlayerDialog( playerid, DIALOG_BUYW_3W, DIALOG_STYLE_MSGBOX, "Sklep z broni¹", string, "Kup", "Wróæ" );
					}
				}
				return 1;
			}
			else
			{
				format( string, sizeof(string), "1.Broñ\n2.Amunicja" );
				ShowPlayerDialog( playerid, DIALOG_BUYW_1, DIALOG_STYLE_LIST, "Sklep z broni¹",
				string,
				"Wybierz","WyjdŸ");
				return 1;
			}
		}
		case DIALOG_BUYW_3W:
		{
			if( response )
			{
				gListOverItem[playerid] = gListItem[playerid];
				switch( gListItem[playerid] )
				{
					case 0: // 9mm
					{
						if( Businesses[ gBuyBusiness[playerid] ][W9MM] <= 0 )
						{
							ShowPlayerDialog( playerid, DIALOG_BUYW_4W, DIALOG_STYLE_MSGBOX, "Sklep z broni¹", "Brak broni w sklepie !", "Wróæ", "" );
							return 1;
						}
						else
						{
							if( gPlayerData[playerid][pCash] < ItemPrice( 1, 16 ) )
							{
								ShowPlayerDialog( playerid, DIALOG_BUYW_4W, DIALOG_STYLE_MSGBOX, "Sklep z broni¹", "Nie masz wystarczaj¹cej iloœci pieniêdzy !", "Wróæ", "" );
								return 1;
							}
							if( InsertPlayerItemEx( playerid, 1, 16, 0, 0, 0, 0, "Puste", 1, true ) == -1 )
							{
								ShowPlayerDialog( playerid, DIALOG_BUYW_4W, DIALOG_STYLE_MSGBOX, "Sklep z broni¹", "Jesteœ przeci¹¿ony !", "Wróæ", "" );
								return 1;
							}
							Businesses[ gBuyBusiness[playerid] ][W9MM]--;
							SaveBizData( gBuyBusiness[playerid], "W9MM" );
							GivePlayerCash( playerid, -ItemPrice( 1, 16 ) );
							Businesses[ gBuyBusiness[playerid] ][Till] += ItemPrice( 1, 16 );
							SaveBizData( gBuyBusiness[playerid], "Till" );
							goto GOTO_BUYW_2W;
						}
					}
					case 1: // 9mm sil
					{
						if( Businesses[ gBuyBusiness[playerid] ][W9MMSil] <= 0 )
						{
							ShowPlayerDialog( playerid, DIALOG_BUYW_4W, DIALOG_STYLE_MSGBOX, "Sklep z broni¹", "Brak broni w sklepie !", "Wróæ", "" );
							return 1;
						}
						else
						{
							if( gPlayerData[playerid][pCash] < ItemPrice( 1, 17 ) )
							{
								ShowPlayerDialog( playerid, DIALOG_BUYW_4W, DIALOG_STYLE_MSGBOX, "Sklep z broni¹", "Nie masz wystarczaj¹cej iloœci pieniêdzy !", "Wróæ", "" );
								return 1;
							}
							if( InsertPlayerItemEx( playerid, 1, 17, 0, 0, 0, 0, "Puste", 1, true ) == -1 )
							{
								ShowPlayerDialog( playerid, DIALOG_BUYW_4W, DIALOG_STYLE_MSGBOX, "Sklep z broni¹", "Jesteœ przeci¹¿ony !", "Wróæ", "" );
								return 1;
							}
							Businesses[ gBuyBusiness[playerid] ][W9MMSil]--;
							SaveBizData( gBuyBusiness[playerid], "W9MMSil" );
							GivePlayerCash( playerid, -ItemPrice( 1, 17 ) );
							Businesses[ gBuyBusiness[playerid] ][Till] += ItemPrice( 1, 17 );
							SaveBizData( gBuyBusiness[playerid], "Till" );
							goto GOTO_BUYW_2W;
						}
					}
					case 2: // des eagle
					{
						if( Businesses[ gBuyBusiness[playerid] ][WDesEagle] <= 0 )
						{
							ShowPlayerDialog( playerid, DIALOG_BUYW_4W, DIALOG_STYLE_MSGBOX, "Sklep z broni¹", "Brak broni w sklepie !", "Wróæ", "" );
							return 1;
						}
						else
						{
							if( gPlayerData[playerid][pCash] < ItemPrice( 1, 18 ) )
							{
								ShowPlayerDialog( playerid, DIALOG_BUYW_4W, DIALOG_STYLE_MSGBOX, "Sklep z broni¹", "Nie masz wystarczaj¹cej iloœci pieniêdzy !", "Wróæ", "" );
								return 1;
							}
							if( InsertPlayerItemEx( playerid, 1, 18, 0, 0, 0, 0, "Puste", 1, true ) == -1 )
							{
								ShowPlayerDialog( playerid, DIALOG_BUYW_4W, DIALOG_STYLE_MSGBOX, "Sklep z broni¹", "Jesteœ przeci¹¿ony !", "Wróæ", "" );
								return 1;
							}
							Businesses[ gBuyBusiness[playerid] ][WDesEagle]--;
							SaveBizData( gBuyBusiness[playerid], "WDesEagle" );
							GivePlayerCash( playerid, -ItemPrice( 1, 18 ) );
							Businesses[ gBuyBusiness[playerid] ][Till] += ItemPrice( 1, 18 );
							SaveBizData( gBuyBusiness[playerid], "Till" );
							goto GOTO_BUYW_2W;
						}
					}
					case 3: // msmg
					{
						if( Businesses[ gBuyBusiness[playerid] ][WMicroSMG] <= 0 )
						{
							ShowPlayerDialog( playerid, DIALOG_BUYW_4W, DIALOG_STYLE_MSGBOX, "Sklep z broni¹", "Brak broni w sklepie !", "Wróæ", "" );
							return 1;
						}
						else
						{
							if( gPlayerData[playerid][pCash] < ItemPrice( 1, 22 ) )
							{
								ShowPlayerDialog( playerid, DIALOG_BUYW_4W, DIALOG_STYLE_MSGBOX, "Sklep z broni¹", "Nie masz wystarczaj¹cej iloœci pieniêdzy !", "Wróæ", "" );
								return 1;
							}
							if( InsertPlayerItemEx( playerid, 1, 22, 0, 0, 0, 0, "Puste", 1, true ) == -1 )
							{
								ShowPlayerDialog( playerid, DIALOG_BUYW_4W, DIALOG_STYLE_MSGBOX, "Sklep z broni¹", "Jesteœ przeci¹¿ony !", "Wróæ", "" );
								return 1;
							}
							Businesses[ gBuyBusiness[playerid] ][WMicroSMG]--;
							SaveBizData( gBuyBusiness[playerid], "WMicroSMG" );
							GivePlayerCash( playerid, -ItemPrice( 1, 22 ) );
							Businesses[ gBuyBusiness[playerid] ][Till] += ItemPrice( 1, 22 );
							SaveBizData( gBuyBusiness[playerid], "Till" );
							goto GOTO_BUYW_2W;
						}
					}
					case 4: // mp5
					{
						if( Businesses[ gBuyBusiness[playerid] ][WMP5] <= 0 )
						{
							ShowPlayerDialog( playerid, DIALOG_BUYW_4W, DIALOG_STYLE_MSGBOX, "Sklep z broni¹", "Brak broni w sklepie !", "Wróæ", "" );
							return 1;
						}
						else
						{
							if( gPlayerData[playerid][pCash] < ItemPrice( 1, 23 ) )
							{
								ShowPlayerDialog( playerid, DIALOG_BUYW_4W, DIALOG_STYLE_MSGBOX, "Sklep z broni¹", "Nie masz wystarczaj¹cej iloœci pieniêdzy !", "Wróæ", "" );
								return 1;
							}
							if( InsertPlayerItemEx( playerid, 1, 23, 0, 0, 0, 0, "Puste", 1, true ) == -1 )
							{
								ShowPlayerDialog( playerid, DIALOG_BUYW_4W, DIALOG_STYLE_MSGBOX, "Sklep z broni¹", "Jesteœ przeci¹¿ony !", "Wróæ", "" );
								return 1;
							}
							Businesses[ gBuyBusiness[playerid] ][WMP5]--;
							SaveBizData( gBuyBusiness[playerid], "WMP5" );
							GivePlayerCash( playerid, -ItemPrice( 1, 23 ) );
							Businesses[ gBuyBusiness[playerid] ][Till] += ItemPrice( 1, 23 );
							SaveBizData( gBuyBusiness[playerid], "Till" );
							goto GOTO_BUYW_2W;
						}
					}
					case 5: // tec9
					{
						if( Businesses[ gBuyBusiness[playerid] ][WTec9] <= 0 )
						{
							ShowPlayerDialog( playerid, DIALOG_BUYW_4W, DIALOG_STYLE_MSGBOX, "Sklep z broni¹", "Brak broni w sklepie !", "Wróæ", "" );
							return 1;
						}
						else
						{
							if( gPlayerData[playerid][pCash] < ItemPrice( 1, 26 ) )
							{
								ShowPlayerDialog( playerid, DIALOG_BUYW_4W, DIALOG_STYLE_MSGBOX, "Sklep z broni¹", "Nie masz wystarczaj¹cej iloœci pieniêdzy !", "Wróæ", "" );
								return 1;
							}
							if( InsertPlayerItemEx( playerid, 1, 26, 0, 0, 0, 0, "Puste", 1, true ) == -1 )
							{
								ShowPlayerDialog( playerid, DIALOG_BUYW_4W, DIALOG_STYLE_MSGBOX, "Sklep z broni¹", "Jesteœ przeci¹¿ony !", "Wróæ", "" );
								return 1;
							}
							Businesses[ gBuyBusiness[playerid] ][WTec9]--;
							SaveBizData( gBuyBusiness[playerid], "WTec9" );
							GivePlayerCash( playerid, -ItemPrice( 1, 26 ) );
							Businesses[ gBuyBusiness[playerid] ][Till] += ItemPrice( 1, 26 );
							SaveBizData( gBuyBusiness[playerid], "Till" );
							goto GOTO_BUYW_2W;
						}
					}
					case 6: // shotgun
					{
						if( Businesses[ gBuyBusiness[playerid] ][WShotgun] <= 0 )
						{
							ShowPlayerDialog( playerid, DIALOG_BUYW_4W, DIALOG_STYLE_MSGBOX, "Sklep z broni¹", "Brak broni w sklepie !", "Wróæ", "" );
							return 1;
						}
						else
						{
							if( gPlayerData[playerid][pCash] < ItemPrice( 1, 19 ) )
							{
								ShowPlayerDialog( playerid, DIALOG_BUYW_4W, DIALOG_STYLE_MSGBOX, "Sklep z broni¹", "Nie masz wystarczaj¹cej iloœci pieniêdzy !", "Wróæ", "" );
								return 1;
							}
							if( InsertPlayerItemEx( playerid, 1, 19, 0, 0, 0, 0, "Puste", 1, true ) == -1 )
							{
								ShowPlayerDialog( playerid, DIALOG_BUYW_4W, DIALOG_STYLE_MSGBOX, "Sklep z broni¹", "Jesteœ przeci¹¿ony !", "Wróæ", "" );
								return 1;
							}
							Businesses[ gBuyBusiness[playerid] ][WShotgun]--;
							SaveBizData( gBuyBusiness[playerid], "WShotgun" );
							GivePlayerCash( playerid, -ItemPrice( 1, 19 ) );
							Businesses[ gBuyBusiness[playerid] ][Till] += ItemPrice( 1, 19 );
							SaveBizData( gBuyBusiness[playerid], "Till" );
							goto GOTO_BUYW_2W;
						}
					}
					case 7: // ak47
					{
						if( Businesses[ gBuyBusiness[playerid] ][WAK47] <= 0 )
						{
							ShowPlayerDialog( playerid, DIALOG_BUYW_4W, DIALOG_STYLE_MSGBOX, "Sklep z broni¹", "Brak broni w sklepie !", "Wróæ", "" );
							return 1;
						}
						else
						{
							if( gPlayerData[playerid][pCash] < ItemPrice( 1, 24 ) )
							{
								ShowPlayerDialog( playerid, DIALOG_BUYW_4W, DIALOG_STYLE_MSGBOX, "Sklep z broni¹", "Nie masz wystarczaj¹cej iloœci pieniêdzy !", "Wróæ", "" );
								return 1;
							}
							if( InsertPlayerItemEx( playerid, 1, 24, 0, 0, 0, 0, "Puste", 1, true ) == -1 )
							{
								ShowPlayerDialog( playerid, DIALOG_BUYW_4W, DIALOG_STYLE_MSGBOX, "Sklep z broni¹", "Jesteœ przeci¹¿ony !", "Wróæ", "" );
								return 1;
							}
							Businesses[ gBuyBusiness[playerid] ][WAK47]--;
							SaveBizData( gBuyBusiness[playerid], "WAK47" );
							GivePlayerCash( playerid, -ItemPrice( 1, 24 ) );
							Businesses[ gBuyBusiness[playerid] ][Till] += ItemPrice( 1, 24 );
							SaveBizData( gBuyBusiness[playerid], "Till" );
							goto GOTO_BUYW_2W;
						}
					}
					case 8: // m4
					{
						if( Businesses[ gBuyBusiness[playerid] ][WM4] <= 0 )
						{
							ShowPlayerDialog( playerid, DIALOG_BUYW_4W, DIALOG_STYLE_MSGBOX, "Sklep z broni¹", "Brak broni w sklepie !", "Wróæ", "" );
							return 1;
						}
						else
						{
							if( gPlayerData[playerid][pCash] < ItemPrice( 1, 25 ) )
							{
								ShowPlayerDialog( playerid, DIALOG_BUYW_4W, DIALOG_STYLE_MSGBOX, "Sklep z broni¹", "Nie masz wystarczaj¹cej iloœci pieniêdzy !", "Wróæ", "" );
								return 1;
							}
							if( InsertPlayerItemEx( playerid, 1, 25, 0, 0, 0, 0, "Puste", 1, true ) == -1 )
							{
								ShowPlayerDialog( playerid, DIALOG_BUYW_4W, DIALOG_STYLE_MSGBOX, "Sklep z broni¹", "Jesteœ przeci¹¿ony !", "Wróæ", "" );
								return 1;
							}
							Businesses[ gBuyBusiness[playerid] ][WM4]--;
							SaveBizData( gBuyBusiness[playerid], "WM4" );
							GivePlayerCash( playerid, -ItemPrice( 1, 25 ) );
							Businesses[ gBuyBusiness[playerid] ][Till] += ItemPrice( 1, 25 );
							SaveBizData( gBuyBusiness[playerid], "Till" );
							goto GOTO_BUYW_2W;
						}
					}
					case 9: // rifle
					{
						if( Businesses[ gBuyBusiness[playerid] ][WRifle] <= 0 )
						{
							ShowPlayerDialog( playerid, DIALOG_BUYW_4W, DIALOG_STYLE_MSGBOX, "Sklep z broni¹", "Brak broni w sklepie !", "Wróæ", "" );
							return 1;
						}
						else
						{
							if( gPlayerData[playerid][pCash] < ItemPrice( 1, 27 ) )
							{
								ShowPlayerDialog( playerid, DIALOG_BUYW_4W, DIALOG_STYLE_MSGBOX, "Sklep z broni¹", "Nie masz wystarczaj¹cej iloœci pieniêdzy !", "Wróæ", "" );
								return 1;
							}
							if( InsertPlayerItemEx( playerid, 1, 27, 0, 0, 0, 0, "Puste", 1, true ) == -1 )
							{
								ShowPlayerDialog( playerid, DIALOG_BUYW_4W, DIALOG_STYLE_MSGBOX, "Sklep z broni¹", "Jesteœ przeci¹¿ony !", "Wróæ", "" );
								return 1;
							}
							Businesses[ gBuyBusiness[playerid] ][WRifle]--;
							SaveBizData( gBuyBusiness[playerid], "WRifle" );
							GivePlayerCash( playerid, -ItemPrice( 1, 27 ) );
							Businesses[ gBuyBusiness[playerid] ][Till] += ItemPrice( 1, 27 );
							SaveBizData( gBuyBusiness[playerid], "Till" );
							goto GOTO_BUYW_2W;
						}
					}
					case 10: // rifle
					{
						if( Businesses[ gBuyBusiness[playerid] ][WSRifle] <= 0 )
						{
							ShowPlayerDialog( playerid, DIALOG_BUYW_4W, DIALOG_STYLE_MSGBOX, "Sklep z broni¹", "Brak broni w sklepie !", "Wróæ", "" );
							return 1;
						}
						else
						{
							if( gPlayerData[playerid][pCash] < ItemPrice( 1, 28 ) )
							{
								ShowPlayerDialog( playerid, DIALOG_BUYW_4W, DIALOG_STYLE_MSGBOX, "Sklep z broni¹", "Nie masz wystarczaj¹cej iloœci pieniêdzy !", "Wróæ", "" );
								return 1;
							}
							if( InsertPlayerItemEx( playerid, 1, 28, 0, 0, 0, 0, "Puste", 1, true ) == -1 )
							{
								ShowPlayerDialog( playerid, DIALOG_BUYW_4W, DIALOG_STYLE_MSGBOX, "Sklep z broni¹", "Jesteœ przeci¹¿ony !", "Wróæ", "" );
								return 1;
							}
							Businesses[ gBuyBusiness[playerid] ][WSRifle]--;
							SaveBizData( gBuyBusiness[playerid], "WSRifle" );
							GivePlayerCash( playerid, -ItemPrice( 1, 28 ) );
							Businesses[ gBuyBusiness[playerid] ][Till] += ItemPrice( 1, 28 );
							SaveBizData( gBuyBusiness[playerid], "Till" );
							goto GOTO_BUYW_2W;
						}
					}
				}
				return 1;
			}
			else
			{
				format( string, sizeof( string ), DIALOG_BUYW_TXT, 
				Businesses[ gBuyBusiness[playerid] ][W9MM], ItemPrice( 1, 16 ), 
				Businesses[ gBuyBusiness[playerid] ][W9MMSil], ItemPrice( 1, 17 ), 
				Businesses[ gBuyBusiness[playerid] ][WDesEagle], ItemPrice( 1, 18 ), 
				Businesses[ gBuyBusiness[playerid] ][WMicroSMG], ItemPrice( 1, 22 ), 
				Businesses[ gBuyBusiness[playerid] ][WMP5], ItemPrice( 1, 23 ), 
				Businesses[ gBuyBusiness[playerid] ][WTec9], ItemPrice( 1, 26 ), 
				Businesses[ gBuyBusiness[playerid] ][WShotgun], ItemPrice( 1, 19 ), 
				Businesses[ gBuyBusiness[playerid] ][WAK47], ItemPrice( 1, 24 ), 
				Businesses[ gBuyBusiness[playerid] ][WM4], ItemPrice( 1, 25 ), 
				Businesses[ gBuyBusiness[playerid] ][WRifle], ItemPrice( 1, 27 ), 
				Businesses[ gBuyBusiness[playerid] ][WSRifle], ItemPrice( 1, 28 ) );
				ShowPlayerDialog( playerid, DIALOG_BUYW_2W, DIALOG_STYLE_LIST, "Sklep z broni¹", string, "Kup", "Wróæ" );
				return 1;
			}
		}
		case DIALOG_BUYW_4W:
		{
			format( string, sizeof( string ), DIALOG_BUYW_TXT, 
			Businesses[ gBuyBusiness[playerid] ][W9MM], ItemPrice( 1, 16 ), 
			Businesses[ gBuyBusiness[playerid] ][W9MMSil], ItemPrice( 1, 17 ), 
			Businesses[ gBuyBusiness[playerid] ][WDesEagle], ItemPrice( 1, 18 ), 
			Businesses[ gBuyBusiness[playerid] ][WMicroSMG], ItemPrice( 1, 22 ), 
			Businesses[ gBuyBusiness[playerid] ][WMP5], ItemPrice( 1, 23 ), 
			Businesses[ gBuyBusiness[playerid] ][WTec9], ItemPrice( 1, 26 ), 
			Businesses[ gBuyBusiness[playerid] ][WShotgun], ItemPrice( 1, 19 ), 
			Businesses[ gBuyBusiness[playerid] ][WAK47], ItemPrice( 1, 24 ), 
			Businesses[ gBuyBusiness[playerid] ][WM4], ItemPrice( 1, 25 ), 
			Businesses[ gBuyBusiness[playerid] ][WRifle], ItemPrice( 1, 27 ), 
			Businesses[ gBuyBusiness[playerid] ][WSRifle], ItemPrice( 1, 28 ) );
			ShowPlayerDialog( playerid, DIALOG_BUYW_2W, DIALOG_STYLE_LIST, "Sklep z brioni¹", string, "Kup", "Wróæ" );
			return 1;
		}
		case DIALOG_CBUY_1:
		{
			if( response )
			{
				switch( listitem )
				{
					case 0:
					{
						gListItem[playerid] = 0;
						ShowPlayerDialog(playerid, DIALOG_CBUY_2, DIALOG_STYLE_INPUT, "Sklep z ubraniami", "Wpisz ID skina (1-299)", "Wybierz", "Wróæ" );
						return 1;
					}
					case 1:
					{
						gListItem[playerid] = 1;
						ShowPlayerDialog(playerid, DIALOG_CBUY_2, DIALOG_STYLE_INPUT, "Sklep z ubraniami", "Wpisz ID okularów (1-30)", "Wybierz", "Wróæ" );
						return 1;
					}
					case 2:
					{
						gListItem[playerid] = 2;
						ShowPlayerDialog(playerid, DIALOG_CBUY_2, DIALOG_STYLE_INPUT, "Sklep z ubraniami", "Wpisz ID czapki (1-16)", "Wybierz", "Wróc" );
						return 1;
					}
				}
				return 1;
			}
		}
		case DIALOG_CBUY_2:
		{
			if( response )
			{
				switch( gListItem[playerid])
				{
					case 0:
					{
						if(Businesses[gBuyBusiness[playerid]][Products] == 0)
						{
							SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Brak produktów !");
							return 1;
						}
						if( GetPlayerCash(playerid) < 80 )
						{
							SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie masz wystarczaj¹co du¿o pieniêdzy na ubranie" );
							return 1;
						}
						if( IsACopSkin(strval(inputtext) ) )
						{
							SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz zakupiæ stroju mundurowego");
							return 1;
						}
						if( strval(inputtext) > 0 && strval(inputtext) < 300 )
						{
							SetPlayerSkin(playerid,strval(inputtext));
							GivePlayerCash(playerid, -80);
							gPlayerData[playerid][pSkin] = strval(inputtext);
							Businesses[gBuyBusiness[playerid]][Products]--;
							Businesses[gBuyBusiness[playerid]][Till]+=80;
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ubranie kupione, $-80.");
							SaveBizData(gBuyBusiness[playerid], "Products");
							SaveBizData(gBuyBusiness[playerid], "Till");
							SavePlayerData(playerid, "Skin");
							SaveStatsData("ubranie", gPlayerData[playerid][pName], 80, gBuyBusiness[playerid], Businesses[gBuyBusiness[playerid]][BizType]);
						}
					}
					case 1:
					{
						if(Businesses[gBuyBusiness[playerid]][Products] == 0)
						{
							SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Brak produktów !");
							return 1;
						}
						if( GetPlayerCash(playerid) < 25 )
						{
							SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie masz wystarczaj¹co du¿o pieniêdzy na okulary" );
							return 1;
						}
						if( strval(inputtext) > 0 && strval(inputtext) <= 30 )
						{
							if((strval(inputtext) != 1 && strval(inputtext) != 2 && strval(inputtext) != 6 && strval(inputtext) != 8 && strval(inputtext) != 12 && strval(inputtext) != 15 && strval(inputtext) != 19 && strval(inputtext) != 22 && strval(inputtext) != 25 && strval(inputtext) != 27 && strval(inputtext) != 30) && gPlayerData[playerid][pVipAFKT] == 0 && gPlayerData[playerid][pVipExpT] == 0)
							{
								SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Aby kupiæ t¹ pare okularów musisz posiadaæ wykupiony pakiet VIP");
								return 1;
							}
							new slot = InsertPlayerItem(playerid, 3, 7, strval(inputtext)-1, 0);
							if(slot == 0)
							{
								SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie masz miejsca na okulary !");
								return 1;
							}
							SendClientMessage(playerid, COLOR_GREEN, "[INFO:] Kupi³eœ okulary !");
							GivePlayerCash(playerid,-30);
							Businesses[gBuyBusiness[playerid]][Products]--;
							Businesses[gBuyBusiness[playerid]][Till]+=30;
							SaveBizData(gBuyBusiness[playerid], "Products");
							SaveBizData(gBuyBusiness[playerid], "Till");
							SaveStatsData("czapka", gPlayerData[playerid][pName], 30, gBuyBusiness[playerid], Businesses[gBuyBusiness[playerid]][BizType]);
							return 1;
						}
					}
					case 2:
					{
						if(Businesses[gBuyBusiness[playerid]][Products] == 0)
						{
							SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Brak produktów !");
							return 1;
						}
						if( GetPlayerCash(playerid) < 25 )
						{
							SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie masz wystarczaj¹co du¿o pieniêdzy na czapke" );
							return 1;
						}
						if( strval(inputtext) > 0 && strval(inputtext) <= 16 )
						{
							if((strval(inputtext) != 1 && strval(inputtext) != 4) && gPlayerData[playerid][pVipAFKT] == 0 && gPlayerData[playerid][pVipExpT] == 0)
							{
								SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Aby kupiæ t¹ czapke musisz posiadaæ wykupiony pakiet VIP");
								return 1;
							}
							new slot;
							if(strval(inputtext) > 6)
								slot = InsertPlayerItem(playerid, 3, 9, strval(inputtext)-1, 1); // we got -1 to get id 0 (offset) for real hat id
							else	
								slot = InsertPlayerItem(playerid, 3, 9, strval(inputtext)-7, 0); // -7 is because id of other hats is completly different
							if(slot == 0)
							{
								SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie masz miejsca na czapke !");
								return 1;
							}
							SendClientMessage(playerid, COLOR_GREEN, "[INFO:] Kupi³eœ czapke !");
							GivePlayerCash(playerid,-30);
							Businesses[gBuyBusiness[playerid]][Products]--;
							Businesses[gBuyBusiness[playerid]][Till]+=30;
							SaveBizData(gBuyBusiness[playerid], "Products");
							SaveBizData(gBuyBusiness[playerid], "Till");
							SaveStatsData("czapka", gPlayerData[playerid][pName], 30, gBuyBusiness[playerid], Businesses[gBuyBusiness[playerid]][BizType]);
							return 1;
						}
					}
				}
			}
		}
		case DIALOG_BUY_1:
		{
			if( response )
			{
				switch( listitem )
				{
					case 0:
					{
						new i = gBuyBusiness[playerid];
						ProdList:
						if( Businesses[i][Products] > 0)
						{
							format( string, sizeof(string), SHOP_PRODUCT_LIST, 
								Businesses[i][Product1Price], 
								Businesses[i][Product2Price], 
								Businesses[i][Product3Price], 
								Businesses[i][Product4Price], 
								Businesses[i][Product5Price], 
								Businesses[i][Product6Price], 
								Businesses[i][Product7Price], 
								Businesses[i][Product8Price], 
								Businesses[i][Product9Price], 
								Businesses[i][Product10Price], 
								Businesses[i][Product11Price], 
								Businesses[i][Product12Price], 
								Businesses[i][Product13Price], 
								Businesses[i][Product14Price], 
								Businesses[i][Product15Price], 
								Businesses[i][Product16Price],
								Businesses[i][Product17Price],
								Businesses[i][Product18Price] );
							format( string2, sizeof(string2), SHOP_PRODUCT_LIST2,
								Businesses[i][Product19Price],
								Businesses[i][Product20Price],
								Businesses[i][Product21Price] );
							format( string, sizeof(string), "%s%s", string, string2);
							if( gPlayerData[playerid][pBizKey] == i )
							{
								ShowPlayerDialog(playerid,DIALOG_BUY_2P,DIALOG_STYLE_LIST,"Sklep 24/7",
								string,
								"Wybierz","WyjdŸ");
							}
							else
							{
								ShowPlayerDialog(playerid,DIALOG_BUY_2P,DIALOG_STYLE_LIST,"Sklep 24/7",
								string,
								"Kup","WyjdŸ");
							}
						}
						else
						{
							ShowPlayerDialog(playerid,DIALOG_INFO,DIALOG_STYLE_MSGBOX,"Sklep 24/7",
							"Brak produktów !",
							"WyjdŸ", "" );
						}
					}
					case 1:
					{
						new GSID, refillprice;
						for( new i = 0; i < sizeof(GasStations); i++ )
						{
							if( GasStations[i][BusinessID] == gBuyBusiness[playerid] )
							{
								GSID = i;
								break;
							}
						}
						refillprice += floatround( gPlayerData[playerid][pGasStationRefPetrol][ gBuyBusiness[playerid] ] * GasStations[GSID][PetrolPrice], floatround_round );
						refillprice += floatround( gPlayerData[playerid][pGasStationRefOil][ gBuyBusiness[playerid] ] * GasStations[GSID][OilPrice], floatround_round );	
						refillprice += floatround( gPlayerData[playerid][pGasStationRefGas][ gBuyBusiness[playerid] ] * GasStations[GSID][GasPrice], floatround_round );
						format( string, sizeof( string ), "Zatankowano:\n- %dltr benzyny za %d$\n- %dltr ropy za %d$\n- %dltr gazu za %d$\n\n£¹czna kwota do zap³aty: %d$",
						floatround( gPlayerData[playerid][pGasStationRefPetrol][ gBuyBusiness[playerid] ] ),
						floatround( gPlayerData[playerid][pGasStationRefPetrol][ gBuyBusiness[playerid] ] * GasStations[GSID][PetrolPrice], floatround_round ),
						floatround( gPlayerData[playerid][pGasStationRefOil][ gBuyBusiness[playerid] ] ),
						floatround( gPlayerData[playerid][pGasStationRefOil][ gBuyBusiness[playerid] ] * GasStations[GSID][OilPrice], floatround_round ),
						floatround( gPlayerData[playerid][pGasStationRefGas][ gBuyBusiness[playerid] ] ),
						floatround( gPlayerData[playerid][pGasStationRefGas][ gBuyBusiness[playerid] ] * GasStations[GSID][GasPrice], floatround_round ),
						refillprice );
						ShowPlayerDialog( playerid, DIALOG_BUY_2F, DIALOG_STYLE_MSGBOX, "Stacja paliw", string, "Zap³aæ", "Wróæ" );
					}
				}
				return 1;
			}
		}
		case DIALOG_BUY_2F:
		{
			if( response )
			{
				new GSID, refillpricep, refillpriceo, refillpriceg, refillprice;
				for( new i = 0; i < sizeof(GasStations); i++ )
				{
					if( GasStations[i][BusinessID] == gBuyBusiness[playerid] )
					{
						GSID = i;
						break;
					}
				}
				refillpricep = refillprice += floatround( gPlayerData[playerid][pGasStationRefPetrol][ gBuyBusiness[playerid] ] * GasStations[GSID][PetrolPrice], floatround_round );
				refillpriceo = refillprice += floatround( gPlayerData[playerid][pGasStationRefOil][ gBuyBusiness[playerid] ] * GasStations[GSID][OilPrice], floatround_round );	
				refillpriceg = refillprice += floatround( gPlayerData[playerid][pGasStationRefGas][ gBuyBusiness[playerid] ] * GasStations[GSID][GasPrice], floatround_round );
				if( refillprice > gPlayerData[playerid][pCash] )
				{
					new lefttp = refillprice - gPlayerData[playerid][pCash];
					format( string, sizeof(string), "Zap³acono: %d$\nPozosta³o do zap³aty: %d$\n\nMusisz jak najszybciej op³aciæ zaleg³¹ kwote !\nW przeciwnym wypadku zacznie siê Tob¹ interesowaæ policja !", gPlayerData[playerid][pCash], lefttp );
					ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Stacja paliw", string, "Zamknij", "" );
					if( refillpricep > gPlayerData[playerid][pCash] )
					{
						gPlayerData[playerid][pGasStationRefPetrol][ gBuyBusiness[playerid] ] = refillpricep - gPlayerData[playerid][pCash];
						SavePlayerData( playerid, "GasStationRefPetrol", gBuyBusiness[playerid] );
						Businesses[ gBuyBusiness[playerid] ][Till] += gPlayerData[playerid][pCash];
						GivePlayerCash( playerid, -gPlayerData[playerid][pCash] );
						return 1;
					}
					else
					{
						gPlayerData[playerid][pGasStationRefPetrol][ gBuyBusiness[playerid] ] = 0;
						Businesses[ gBuyBusiness[playerid] ][Till] += refillpricep;
						GivePlayerCash( playerid, -refillpricep );
					}
					if( refillpriceo > gPlayerData[playerid][pCash] )
					{
						gPlayerData[playerid][pGasStationRefOil][ gBuyBusiness[playerid] ] = refillpriceo - gPlayerData[playerid][pCash];
						SavePlayerData( playerid, "GasStationRefOil", gBuyBusiness[playerid] );
						Businesses[ gBuyBusiness[playerid] ][Till] += gPlayerData[playerid][pCash];
						GivePlayerCash( playerid, -gPlayerData[playerid][pCash] );
						return 1;
					}
					else
					{
						gPlayerData[playerid][pGasStationRefPetrol][ gBuyBusiness[playerid] ] = 0;
						Businesses[ gBuyBusiness[playerid] ][Till] += refillpriceo;
						GivePlayerCash( playerid, -refillpriceo );
					}
					if( refillpriceg > gPlayerData[playerid][pCash] )
					{
						gPlayerData[playerid][pGasStationRefGas][ gBuyBusiness[playerid] ] = refillpriceg -= gPlayerData[playerid][pCash];
						SavePlayerData( playerid, "GasStationRefGas", gBuyBusiness[playerid] );
						Businesses[ gBuyBusiness[playerid] ][Till] += gPlayerData[playerid][pCash];
						GivePlayerCash( playerid, -gPlayerData[playerid][pCash] );
						return 1;
					}
					else
					{
						gPlayerData[playerid][pGasStationRefPetrol][ gBuyBusiness[playerid] ] = 0;
						Businesses[ gBuyBusiness[playerid] ][Till] += refillpriceg;
						GivePlayerCash( playerid, -refillpriceg );
					}
					SaveBizData( gBuyBusiness[playerid], "Till" );					
				}
				else
				{
					format( string, sizeof(string), "Zap³acono: %d$\nPozosta³o do zap³aty: %d$\n\nZatankowane paliwo zosta³o op³acone !", refillprice, 0 );
					ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Stacja paliw", string, "Zamknij", "" );
					Businesses[ gBuyBusiness[playerid] ][Till] += refillprice;
					GivePlayerCash( playerid, -refillprice );
					gPlayerData[playerid][pGasStationRefPetrol][ gBuyBusiness[playerid] ] = 0;
					gPlayerData[playerid][pGasStationRefOil][ gBuyBusiness[playerid] ] = 0;
					gPlayerData[playerid][pGasStationRefGas][ gBuyBusiness[playerid] ] = 0;
					SavePlayerData( playerid, "GasStationRefPetrol", gBuyBusiness[playerid] );
					SavePlayerData( playerid, "GasStationRefOil", gBuyBusiness[playerid] );
					SavePlayerData( playerid, "GasStationRefGas", gBuyBusiness[playerid] );
					SaveBizData( gBuyBusiness[playerid], "Till" );
				}
				return 1;
			}
		}
		case DIALOG_BUY_2P:
		{
			if(response)
			{
				new slot;
				new i = gBuyBusiness[playerid];
				if( gPlayerData[playerid][pBizKey] == i )
				{
					BuyMenu:
					if( gListOverItem[playerid] == 1 )
					{
						gListOverItem[playerid] = -1;
						listitem = gListItem[playerid];
					}
					gListItem[playerid] = listitem;
					format( string, sizeof(string), "1. Zmieñ cene\n2. Kup" );
					ShowPlayerDialog( playerid, DIALOG_BUY_3P, DIALOG_STYLE_LIST, "Sklep 24/7", string, "Wybierz", "Wróæ" );
					return 1;
				}
				else
				{
					BuyItem:
					if( gListOverItem[playerid] == 1 )
					{
						gListOverItem[playerid] = -1;
						listitem = gListItem[playerid];
					}
					if(listitem == 0)
					{
						if(Businesses[i][Product1Price] <= 0 )
						{
							ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Niepowodzenie",DIALOG_BUY_6_TXT,"Wróæ","");
							return 1;
						}
						if( GetPlayerCash(playerid) >= Businesses[i][Product1Price] )
						{
							GivePlayerGun(playerid,5,1);
							GivePlayerCash(playerid,-Businesses[i][Product1Price]);

							Businesses[i][Products]--;
							Businesses[i][Till] += Businesses[i][Product1Price];

							SaveBizData(i, "Products");
							SaveBizData(i, "Till");
							SaveStatsData("palka", gPlayerData[playerid][pName], Businesses[i][Product1Price], i, Businesses[i][BizType]);

							
							ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Sukces",DIALOG_BUY_1_TXT,"Wróæ","");
							Audio_Play(playerid, AUDIO_BUY1, false, false, false);
							
							return 1;
						}
					}
					else if(listitem == 1)
					{
						if(Businesses[i][Product2Price] <= 0 )
						{
							ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Niepowodzenie",DIALOG_BUY_6_TXT,"Wróæ","");
							return 1;
						}
						if(ItemWeight(3, 1) + PItemWeight(playerid) > gPlayerData[playerid][pMaxWeight])
						{
							ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Niepowodzenie",DIALOG_BUY_3_TXT,"Wróæ","");
							return 1;
						}
						if(GetPlayerCash(playerid) >= Businesses[i][Product2Price])
						{
							if(InsertPlayerItem(playerid, 3, 1, 0, 0) == 0)
							{
								ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Niepowodzenie",DIALOG_BUY_4_TXT,"Wróæ","");
								return 1;
							}
							GivePlayerCash(playerid, -Businesses[i][Product2Price]);
							
							ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Sukces",DIALOG_BUY_1_TXT,"Wróæ","");
							Audio_Play(playerid, AUDIO_BUY1, false, false, false);
							
							Businesses[i][Products]--;
							Businesses[i][Till] += Businesses[i][Product2Price];
							
							SaveBizData(i, "Products");
							SaveBizData(i, "Till");
							SaveStatsData("kanister", gPlayerData[playerid][pName], Businesses[i][Product2Price], i, Businesses[i][BizType]);

							return 1;
						}
					}
					else if(listitem == 2)
					{
						if(Businesses[i][Product3Price] <= 0 )
						{
							ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Niepowodzenie",DIALOG_BUY_6_TXT,"Wróæ","");
							return 1;
						}
						if(GetPlayerCash(playerid) >= Businesses[i][Product3Price])
						{
							GivePlayerGun(playerid,6,1);
							GivePlayerCash(playerid,-Businesses[i][Product3Price]);
							
							ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Sukces",DIALOG_BUY_1_TXT,"Wróæ","");
							Audio_Play(playerid, AUDIO_BUY1, false, false, false);
							
							Businesses[i][Products]--;
							Businesses[i][Till] += Businesses[i][Product3Price];
							SaveBizData(i, "Products");
							SaveBizData(i, "Till");
							SaveStatsData("lopata", gPlayerData[playerid][pName], Businesses[i][Product3Price], i, Businesses[i][BizType]);
							return 1;
						}
					}
					else if(listitem == 3)
					{
						if(Businesses[i][Product4Price] <= 0 )
						{
							ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Niepowodzenie",DIALOG_BUY_6_TXT,"Wróæ","");
							return 1;
						}
						if(ItemWeight(1, 5) + PItemWeight(playerid) > gPlayerData[playerid][pMaxWeight])
						{
							ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Niepowodzenie",DIALOG_BUY_3_TXT,"Wróæ","");
							return 1;
						}
						if(GetPlayerCash(playerid) >= Businesses[i][Product4Price])
						{
							slot = PHaveItem(playerid, 1, 5);
							if(slot > 0)
							{
								SetPSlotParam6(playerid, slot, SlotParam6(playerid,slot)+1);
							}
							else 
							{
								if(InsertPlayerItemEx(playerid, 1, 5, 0, 0, 0, 0, "Puste", 1) == 0)
								{
									ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Niepowodzenie",DIALOG_BUY_4_TXT,"Wróæ","");
									return 1;
								}
							}
							GivePlayerCash(playerid, -Businesses[i][Product4Price]);
							
							ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Sukces",DIALOG_BUY_1_TXT,"Wróæ","");
							Audio_Play(playerid, AUDIO_BUY1, false, false, false);
							
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Pamiêtaj, ¿e plecak jest przydatny tylko na pierwszych piêciu slotach !");
							
							Businesses[i][Products]--;
							Businesses[i][Till] += Businesses[i][Product4Price];
							
							SaveBizData(i, "Products");
							SaveBizData(i, "Till");
							SaveStatsData("plecak", gPlayerData[playerid][pName], Businesses[i][Product4Price], i, Businesses[i][BizType]);

							return 1;
						}
					}
					else if(listitem == 4)
					{
						if(Businesses[i][Product5Price] <= 0 )
						{
							ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Niepowodzenie",DIALOG_BUY_6_TXT,"Wróæ","");
							return 1;
						}
						if(GetPlayerCash(playerid) >= Businesses[i][Product5Price])
						{
							GivePlayerGun(playerid,7,1);
							GivePlayerCash(playerid,-Businesses[i][Product5Price]);
							ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Sukces",DIALOG_BUY_1_TXT,"Wróæ","");
							Audio_Play(playerid, AUDIO_BUY1, false, false, false);
							Businesses[i][Products]--;
							Businesses[i][Till] += Businesses[i][Product5Price];
							SaveBizData(i, "Products");
							SaveBizData(i, "Till");
							SaveStatsData("kijbilardowy", gPlayerData[playerid][pName], Businesses[i][Product5Price], i, Businesses[i][BizType]);
							return 1;
						}
					}
					else if(listitem == 5)
					{
						if(Businesses[i][Product6Price] <= 0 )
						{
							ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Niepowodzenie",DIALOG_BUY_6_TXT,"Wróæ","");
							return 1;
						}
						ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Niepowodzenie","Aktualnie brak produktu.","Wróæ","");
						return 1;
						// if(ItemWeight(1, 6) + PItemWeight(playerid) > gPlayerData[playerid][pMaxWeight])
						// {
							// ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Niepowodzenie",DIALOG_BUY_3_TXT,"Wróæ","");
							// return 1;
						// }
						// if(GetPlayerCash(playerid) >= 8)
						// {
							// slot = PHaveItem(playerid, 1, 6);
							// if(slot > 0)
							// {
								// SetPSlotParam6(playerid, slot, SlotParam6(playerid,slot)+1);
							// }
							// else 
							// {
								// if(InsertPlayerItemEx(playerid, 1, 6, 0, 0, 0, 0, "Puste", 1) == 0)
								// {
									// ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Niepowodzenie",DIALOG_BUY_4_TXT,"Wróæ","");
									// return 1;
								// }
							// }
							// GivePlayerCash(playerid, -8);
							// ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Sukces",DIALOG_BUY_1_TXT,"Wróæ","");
							// Audio_Play(playerid, AUDIO_BUY1, false, false, false);
							
							// Businesses[i][Products]--;
							// Businesses[i][Till] += 8;
							
							// SaveBizData(i, "Products");
							// SaveBizData(i, "Till");
							// SaveStatsData("rakieta", gPlayerData[playerid][pName], 8, i, Businesses[i][BizType]);

							// return 1;
						// }
					}
					else if(listitem == 6)
					{
						if(Businesses[i][Product7Price] <= 0 )
						{
							ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Niepowodzenie",DIALOG_BUY_6_TXT,"Wróæ","");
							return 1;
						}
						if(ItemWeight(1, 4) + PItemWeight(playerid) > gPlayerData[playerid][pMaxWeight])
						{
							ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Niepowodzenie",DIALOG_BUY_3_TXT,"Wróæ","");
							return 1;
						}
						if(GetPlayerCash(playerid) >= Businesses[i][Product7Price])
						{
							slot = PHaveItem(playerid, 1, 4);
							if(slot > 0)
							{
								SetPSlotParam6(playerid, slot, SlotParam6(playerid,slot)+1);
							}
							else 
							{
								if(InsertPlayerItemEx(playerid, 1, 4, 0, 0, 0, 0, "Puste", 1) == 0)
								{
									ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Niepowodzenie",DIALOG_BUY_4_TXT,"Wróæ","");
									return 1;
								}
							}
							if( !gPlayerData[playerid][pFirstBuy] )
							{
								gPlayerData[playerid][pFirstBuy] = 1;
								SavePlayerData( playerid, "FirstBuy" );
								AddExpPoint(playerid);
								SendClientMessage( playerid, COLOR_GREEN, "[INFO:] Kupi³eœ pierwszy produkt !" );
							}
							GivePlayerCash(playerid,-Businesses[i][Product7Price]);
							ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Sukces",DIALOG_BUY_1_TXT,"Wróæ","");
							Audio_Play(playerid, AUDIO_BUY1, false, false, false);
							Businesses[i][Products]--;
							Businesses[i][Till] += Businesses[i][Product7Price];

							SaveBizData(i, "Products");
							SaveBizData(i, "Till");
							SaveStatsData("ksiazkatel", gPlayerData[playerid][pName], Businesses[i][Product7Price], i, Businesses[i][BizType]);
							return 1;
						}
					}
					else if(listitem == 7)
					{
						if(Businesses[i][Product8Price] <= 0 )
						{
							ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Niepowodzenie",DIALOG_BUY_6_TXT,"Wróæ","");
							return 1;
						}
						if(GetPlayerCash(playerid) >= 400)
						{										
							GivePlayerCash(playerid, -400);
							GivePlayerGun(playerid, 43, 299);
							ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Sukces",DIALOG_BUY_1_TXT,"Wróæ","");
							Audio_Play(playerid, AUDIO_BUY1, false, false, false);
							Businesses[i][Products]--;
							Businesses[i][Till] += 400;
							SaveBizData(i, "Products");
							SaveBizData(i, "Till");
							SaveStatsData("aparat", gPlayerData[playerid][pName], 400, i, Businesses[i][BizType]);
							return 1;
						}
					}
					else if(listitem == 8)
					{
						if(Businesses[i][Product9Price] <= 0 )
						{
							ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Niepowodzenie",DIALOG_BUY_6_TXT,"Wróæ","");
							return 1;
						}
						if(GetPlayerCash(playerid) >= Businesses[i][Product9Price])
						{
							GivePlayerGun(playerid,14,1);
							GivePlayerCash(playerid,-Businesses[i][Product9Price]);
							ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Sukces",DIALOG_BUY_1_TXT,"Wróæ","");
							Audio_Play(playerid, AUDIO_BUY1, false, false, false);
							Businesses[i][Products]--;
							Businesses[i][Till] += Businesses[i][Product9Price];
							SaveBizData(i, "Products");
							SaveBizData(i, "Till");
							SaveStatsData("kwiaty", gPlayerData[playerid][pName], Businesses[i][Product9Price], i, Businesses[i][BizType]);
							return 1;
						}
					}
					else if(listitem == 9)
					{
						if(Businesses[i][Product10Price] <= 0 )
						{
							ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Niepowodzenie",DIALOG_BUY_6_TXT,"Wróæ","");
							return 1;
						}
						if(GetPlayerCash(playerid) >= Businesses[i][Product10Price])
						{			
							if(ItemWeight(1, 7) + PItemWeight(playerid) > gPlayerData[playerid][pMaxWeight])
							{
								ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Niepowodzenie",DIALOG_BUY_3_TXT,"Wróæ","");
								return 1;
							}
							slot = PHaveItem(playerid, 1, 7);
							if(slot > 0)
							{
								SetPSlotParam6(playerid, slot, SlotParam6(playerid,slot)+1);
							}
							else 
							{
								if(InsertPlayerItemEx(playerid, 1, 7, 0, 0, 0, 0, "Puste", 1) == 0)
								{
									ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Niepowodzenie",DIALOG_BUY_4_TXT,"Wróæ","");
									return 1;
								}
							}
							GivePlayerCash(playerid, -Businesses[i][Product10Price]);
							ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Sukces",DIALOG_BUY_1_TXT,"Wróæ","");
							Audio_Play(playerid, AUDIO_BUY1, false, false, false);
							
							Businesses[i][Products]--;
							Businesses[i][Till] += Businesses[i][Product10Price];
							
							SaveBizData(i, "Products");
							SaveBizData(i, "Till");
							SaveStatsData("zarowka", gPlayerData[playerid][pName],Businesses[i][Product10Price], i, Businesses[i][BizType]);

							return 1;
						}
					}
					else if(listitem == 10)
					{
						if(Businesses[i][Product11Price] <= 0 )
						{
							ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Niepowodzenie",DIALOG_BUY_6_TXT,"Wróæ","");
							return 1;
						}
						if(GetPlayerCash(playerid) >= Businesses[i][Product11Price])
						{			
							if(ItemWeight(1, 2) + PItemWeight(playerid) > gPlayerData[playerid][pMaxWeight])
							{
								ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Niepowodzenie",DIALOG_BUY_3_TXT,"Wróæ","");
								return 1;
							}
							slot = PHaveItem(playerid, 1, 2);
							if(slot > 0)
							{
								SetPSlotParam6(playerid, slot, SlotParam6(playerid,slot)+1);
							}
							else 
							{
								if(InsertPlayerItemEx(playerid, 1, 2, 0, 0, 0, 0, "Puste", 1) == 0)
								{
									ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Niepowodzenie",DIALOG_BUY_4_TXT,"Wróæ","");
									return 1;
								}
							}
							GivePlayerCash(playerid, -Businesses[i][Product11Price]);
							ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Sukces",DIALOG_BUY_1_TXT,"Wróæ","");
							Audio_Play(playerid, AUDIO_BUY1, false, false, false);
							
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /kostka");
							
							Businesses[i][Products]--;
							Businesses[i][Till] += Businesses[i][Product11Price];
							
							SaveBizData(i, "Products");
							SaveBizData(i, "Till");
							SaveStatsData("kostka", gPlayerData[playerid][pName],Businesses[i][Product11Price], i, Businesses[i][BizType]);

							return 1;
						}
					}
					else if(listitem == 11)
					{
						if(Businesses[i][Product12Price] <= 0 )
						{
							ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Niepowodzenie",DIALOG_BUY_6_TXT,"Wróæ","");
							return 1;
						}
						if(GetPlayerCash(playerid) >= Businesses[i][Product12Price])
						{					
							if(ItemWeight(1, 12) + PItemWeight(playerid) > gPlayerData[playerid][pMaxWeight])
							{
								ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Niepowodzenie",DIALOG_BUY_3_TXT,"Wróæ","");
								return 1;
							}
							slot = PHaveItem(playerid, 1, 12);
							if(slot > 0)
							{
								SetPSlotParam6(playerid, slot, SlotParam6(playerid,slot)+1);
							}
							else 
							{
								if(InsertPlayerItemEx(playerid, 1, 12, 0, 0, 0, 0, "Puste", 1) == 0)
								{
									ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Niepowodzenie",DIALOG_BUY_4_TXT,"Wróæ","");
									return 1;
								}
							}
							GivePlayerCash(playerid, -Businesses[i][Product12Price]);
							ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Sukces",DIALOG_BUY_1_TXT,"Wróæ","");
							Audio_Play(playerid, AUDIO_BUY1, false, false, false);
							
							Businesses[i][Products]--;
							Businesses[i][Till] += Businesses[i][Product12Price];
							
							SaveBizData(i, "Products");
							SaveBizData(i, "Till");
							SaveStatsData("alarm", gPlayerData[playerid][pName], Businesses[i][Product12Price], i, Businesses[i][BizType]);

							return 1;
						}
					}
					else if(listitem == 12)
					{
						if(Businesses[i][Product13Price] <= 0 )
						{
							ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Niepowodzenie",DIALOG_BUY_6_TXT,"Wróæ","");
							return 1;
						}
						if(ItemWeight(1, 1) + PItemWeight(playerid) > gPlayerData[playerid][pMaxWeight])
						{
							ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Niepowodzenie",DIALOG_BUY_3_TXT,"Wróæ","");
							return 1;
						}
						if(GetPlayerCash(playerid) >= Businesses[i][Product13Price])
						{
							if(PHaveItem(playerid, 1, 1) == 0)
							{
								if(InsertPlayerItem(playerid, 1, 1, 0, 0) == 0)
								{
									ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Niepowodzenie",DIALOG_BUY_4_TXT,"Wróæ","");
									return 1;
								}
								gPlayerData[playerid][JemmyUses] = 5;

								GivePlayerCash(playerid,-Businesses[i][Product13Price]);

								ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Sukces",DIALOG_BUY_1_TXT,"Wróæ","");
								Audio_Play(playerid, AUDIO_BUY1, false, false, false);

								Businesses[i][Products]--;
								Businesses[i][Till]+= Businesses[i][Product13Price];

								SaveBizData(i, "Products");
								SaveBizData(i, "Till");
								SaveStatsData("lom", gPlayerData[playerid][pName], Businesses[i][Product13Price], i, Businesses[i][BizType]);

								SavePlayerData(playerid, "JemmyUses");
								return 1;
							}
							else
							{
								ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Niepowodzenie",DIALOG_BUY_5_TXT,"Wróæ","");
								return 1;
							}
						}
					}
					else if(listitem == 13)
					{
						if(Businesses[i][Product14Price] <= 0 )
						{
							ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Niepowodzenie",DIALOG_BUY_6_TXT,"Wróæ","");
							return 1;
						}
						if(GetPlayerCash(playerid) >= Businesses[i][Product14Price])
						{
							if(ItemWeight(1, 10) + PItemWeight(playerid) > gPlayerData[playerid][pMaxWeight])
							{
								ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Niepowodzenie",DIALOG_BUY_3_TXT,"Wróæ","");
								return 1;
							}
							slot = PHaveItem(playerid, 1, 10);
							if(slot > 0)
							{
								SetPSlotParam6(playerid, slot, SlotParam6(playerid,slot)+1);
							}
							else 
							{
								if(InsertPlayerItemEx(playerid, 1, 10, 0, 0, 0, 0, "Puste", 1) == 0)
								{
									ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Niepowodzenie",DIALOG_BUY_4_TXT,"Wróæ","");
									return 1;
								}
							}
							GivePlayerCash(playerid, -Businesses[i][Product14Price]);
							ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Sukces",DIALOG_BUY_1_TXT,"Wróæ","");
							Audio_Play(playerid, AUDIO_BUY1, false, false, false);
							
							Businesses[i][Products]--;
							Businesses[i][Till] += Businesses[i][Product14Price];
							
							SaveBizData(i, "Products");
							SaveBizData(i, "Till");
							SaveStatsData("hak", gPlayerData[playerid][pName], Businesses[i][Product14Price], i, Businesses[i][BizType]);

							return 1;
						}
					}
					else if(listitem == 14)
					{
						if(Businesses[i][Product15Price] <= 0 )
						{
							ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Niepowodzenie",DIALOG_BUY_6_TXT,"Wróæ","");
							return 1;
						}
						if(!gPlayerData[playerid][pGPS])
						{
							if(GetPlayerCash(playerid) >= Businesses[i][Product15Price])
							{
								gPlayerData[playerid][pGPS] = 1;

								SavePlayerData(playerid, "GPS");

								GivePlayerCash(playerid, -Businesses[i][Product15Price]);
								ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Sukces",DIALOG_BUY_1_TXT,"Wróæ","");
								Audio_Play(playerid, AUDIO_BUY1, false, false, false);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /onoff gps");
								Businesses[i][Products]--;
								Businesses[i][Till] += Businesses[i][Product15Price];
								SaveBizData(i, "Products");
								SaveBizData(i, "Till");
								SavePlayerData(playerid, "GPS");
								SaveStatsData("gps", gPlayerData[playerid][pName], Businesses[i][Product15Price], i, Businesses[i][BizType]);
								return 1;
							}
						}
						else
						{
							ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Niepowodzenie",DIALOG_BUY_5_TXT,"Wróæ","");
							return 1;
						}
					}
					else if(listitem == 15)
					{
						if(Businesses[i][Product16Price] <= 0 )
						{
							ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Niepowodzenie",DIALOG_BUY_6_TXT,"Wróæ","");
							return 1;
						}
						if(GetPlayerCash(playerid) >= Businesses[i][Product16Price])
						{	
							if(ItemWeight(3, 8) + PItemWeight(playerid) > gPlayerData[playerid][pMaxWeight])
							{
								ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Niepowodzenie",DIALOG_BUY_3_TXT,"Wróæ","");
								return 1;
							}
							if(InsertPlayerItem(playerid, 3, 8, 20, 0) == 0)
							{
								ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Niepowodzenie",DIALOG_BUY_4_TXT,"Wróæ","");
								return 1;
							}
							GivePlayerCash(playerid, -Businesses[i][Product16Price]);
							ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Sukces",DIALOG_BUY_1_TXT,"Wróæ","");
							Audio_Play(playerid, AUDIO_BUY1, false, false, false);
							
							Businesses[i][Products]--;
							Businesses[i][Till] += Businesses[i][Product16Price];
							
							SaveBizData(i, "Products");
							SaveBizData(i, "Till");
							SaveStatsData("linka", gPlayerData[playerid][pName], Businesses[i][Product16Price], i, Businesses[i][BizType]);

							return 1;
						}
					}
					else if(listitem == 16)
					{
						if(Businesses[i][Product17Price] <= 0 )
						{
							ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Niepowodzenie",DIALOG_BUY_6_TXT,"Wróæ","");
							return 1;
						}
						if(ItemWeight(3, 2) + PItemWeight(playerid) > gPlayerData[playerid][pMaxWeight])
						{
							ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Niepowodzenie",DIALOG_BUY_3_TXT,"Wróæ","");
							return 1;
						}
						if(GetPlayerCash(playerid) >= Businesses[i][Product17Price])
						{
							if(PHaveItem(playerid, 3, 2) == 0)
							{
								if(InsertPlayerItem(playerid, 3, 2, 0, 0) == 0)
								{
									ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Niepowodzenie",DIALOG_BUY_4_TXT,"Wróæ","");
									return 1;
								}
								GivePlayerCash(playerid, -Businesses[i][Product17Price]);
								ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Sukces",DIALOG_BUY_1_TXT,"Wróæ","");
								Audio_Play(playerid, AUDIO_BUY1, false, false, false);

								Businesses[i][Products]--;
								Businesses[i][Till]+= Businesses[i][Product17Price];

								SaveBizData(i, "Products");
								SaveBizData(i, "Till");
								SaveStatsData("krotkofalowka", gPlayerData[playerid][pName], Businesses[i][Product17Price], i, Businesses[i][BizType]);

								return 1;
							}
							else
							{
								ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Niepowodzenie",DIALOG_BUY_5_TXT,"Wróæ","");
								return 1;
							}
						}
					}
					else if(listitem == 17)
					{
						if(Businesses[i][Product18Price] <= 0 )
						{
							ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Niepowodzenie",DIALOG_BUY_6_TXT,"Wróæ","");
							return 1;
						}
						if(GetPlayerCash(playerid) >= Businesses[i][Product18Price])
						{
							if(ItemWeight(1, 11) + PItemWeight(playerid) > gPlayerData[playerid][pMaxWeight])
							{
								ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Niepowodzenie",DIALOG_BUY_3_TXT,"Wróæ","");
								return 1;
							}
							slot = PHaveItem(playerid, 1, 11);
							if(slot > 0)
							{
								SetPSlotParam6(playerid, slot, SlotParam6(playerid,slot)+1);
							}
							else 
							{
								if(InsertPlayerItemEx(playerid, 1, 11, 0, 0, 0, 0, "Puste", 1) == 0)
								{
									ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Niepowodzenie",DIALOG_BUY_4_TXT,"Wróæ","");
									return 1;
								}
							}
							GivePlayerCash(playerid, -Businesses[i][Product18Price]);
							ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Sukces",DIALOG_BUY_1_TXT,"Wróæ","");
							Audio_Play(playerid, AUDIO_BUY1, false, false, false);
							
							Businesses[i][Products]--;
							Businesses[i][Till] += Businesses[i][Product18Price];
							
							SaveBizData(i, "Products");
							SaveBizData(i, "Till");
							SaveStatsData("alarm", gPlayerData[playerid][pName], Businesses[i][Product18Price], i, Businesses[i][BizType]);

							return 1;
						}
					}
					else if(listitem == 18)
					{
						if(Businesses[i][Product19Price] <= 0 )
						{
							ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Niepowodzenie",DIALOG_BUY_6_TXT,"Wróæ","");
							return 1;
						}
						if(GetPlayerCash(playerid) >= Businesses[i][Product19Price])
						{
							if(ItemWeight(1, 105) + PItemWeight(playerid) > gPlayerData[playerid][pMaxWeight])
							{
								ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Niepowodzenie",DIALOG_BUY_3_TXT,"Wróæ","");
								return 1;
							}
							slot = PHaveItem(playerid, 1, 105);
							if(slot > 0)
							{
								SetPSlotParam6(playerid, slot, SlotParam6(playerid,slot)+1);
							}
							else 
							{
								if(InsertPlayerItemEx(playerid, 1, 105, 0, 0, 0, 0, "Puste", 1) == 0)
								{
									ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Niepowodzenie",DIALOG_BUY_4_TXT,"Wróæ","");
									return 1;
								}
							}
							GivePlayerCash(playerid, -Businesses[i][Product19Price]);
							ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Sukces",DIALOG_BUY_1_TXT,"Wróæ","");
							Audio_Play(playerid, AUDIO_BUY1, false, false, false);
							
							Businesses[i][Products]--;
							Businesses[i][Till] += Businesses[i][Product19Price];
							
							SaveBizData(i, "Products");
							SaveBizData(i, "Till");
							SaveStatsData("mapa", gPlayerData[playerid][pName], Businesses[i][Product19Price], i, Businesses[i][BizType]);

							return 1;
						}
					}
					else if(listitem == 19)
					{
						if(Businesses[i][Product20Price] <= 0 )
						{
							ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Niepowodzenie",DIALOG_BUY_6_TXT,"Wróæ","");
							return 1;
						}
						if(GetPlayerCash(playerid) >= Businesses[i][Product20Price] )
						{
							if(ItemWeight(1, 106) + PItemWeight(playerid) > gPlayerData[playerid][pMaxWeight])
							{
								ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Niepowodzenie",DIALOG_BUY_3_TXT,"Wróæ","");
								return 1;
							}
							slot = PHaveItem(playerid, 1, 106);
							if(slot > 0)
							{
								SetPSlotParam6(playerid, slot, SlotParam6(playerid,slot)+1);
							}
							else 
							{
								if(InsertPlayerItemEx(playerid, 1, 106, 0, 0, 0, 0, "Puste", 1) == 0)
								{
									ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Niepowodzenie",DIALOG_BUY_4_TXT,"Wróæ","");
									return 1;
								}
							}
							GivePlayerCash(playerid, -Businesses[i][Product20Price] );
							ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Sukces",DIALOG_BUY_1_TXT,"Wróæ","");
							Audio_Play(playerid, AUDIO_BUY1, false, false, false);
							
							Businesses[i][Products]--;
							Businesses[i][Till] += Businesses[i][Product20Price];
							
							SaveBizData(i, "Products");
							SaveBizData(i, "Till");
							SaveStatsData("mapa", gPlayerData[playerid][pName], Businesses[i][Product20Price], i, Businesses[i][BizType]);

							return 1;
						}
					}
					else if(listitem == 20)
					{
						if(Businesses[i][Product21Price] <= 0 )
						{
							ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Niepowodzenie",DIALOG_BUY_6_TXT,"Wróæ","");
							return 1;
						}
						if(GetPlayerCash(playerid) >= Businesses[i][Product21Price] )
						{
							if(ItemWeight(1, 9) + PItemWeight(playerid) > gPlayerData[playerid][pMaxWeight])
							{
								ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Niepowodzenie",DIALOG_BUY_3_TXT,"Wróæ","");
								return 1;
							}
							slot = PHaveItem(playerid, 1, 9);
							if(slot > 0)
							{
								SetPSlotParam6(playerid, slot, SlotParam6(playerid,slot)+1);
							}
							else 
							{
								if(InsertPlayerItemEx(playerid, 1, 9, 0, 0, 0, 0, "Puste", 1) == 0)
								{
									ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Niepowodzenie",DIALOG_BUY_4_TXT,"Wróæ","");
									return 1;
								}
							}
							GivePlayerCash(playerid, -Businesses[i][Product21Price] );
							ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Sukces",DIALOG_BUY_1_TXT,"Wróæ","");
							Audio_Play(playerid, AUDIO_BUY1, false, false, false);
							
							Businesses[i][Products]--;
							Businesses[i][Till] += Businesses[i][Product21Price];
							
							SaveBizData(i, "Products");
							SaveBizData(i, "Till");
							SaveStatsData("mapa", gPlayerData[playerid][pName], Businesses[i][Product21Price], i, Businesses[i][BizType]);

							return 1;
						}
					}
					ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Niepowodzenie",DIALOG_BUY_2_TXT,"Wróæ","");
				}
				return 1;
			}
		}
		case DIALOG_BUY_2P_MSG:
		{
			if(response)
			{
				new i = gBuyBusiness[playerid];
				if( Businesses[i][Products] > 0)
				{
					format( string, sizeof(string), SHOP_PRODUCT_LIST, 
						Businesses[i][Product1Price], 
						Businesses[i][Product2Price], 
						Businesses[i][Product3Price], 
						Businesses[i][Product4Price], 
						Businesses[i][Product5Price], 
						Businesses[i][Product6Price], 
						Businesses[i][Product7Price], 
						Businesses[i][Product8Price], 
						Businesses[i][Product9Price], 
						Businesses[i][Product10Price], 
						Businesses[i][Product11Price], 
						Businesses[i][Product12Price], 
						Businesses[i][Product13Price], 
						Businesses[i][Product14Price], 
						Businesses[i][Product15Price], 
						Businesses[i][Product16Price],
						Businesses[i][Product17Price],
						Businesses[i][Product18Price] );
					format( string2, sizeof(string2), SHOP_PRODUCT_LIST2,
						Businesses[i][Product19Price],
						Businesses[i][Product20Price],
						Businesses[i][Product21Price] );
					format( string, sizeof(string), "%s%s", string, string2);
					if( gPlayerData[playerid][pBizKey] == i )
					{
						ShowPlayerDialog(playerid,DIALOG_BUY_2P,DIALOG_STYLE_LIST,"Sklep 24/7",
						string,
						"Wybierz","WyjdŸ");
					}
					else
					{
						ShowPlayerDialog(playerid,DIALOG_BUY_2P,DIALOG_STYLE_LIST,"Sklep 24/7",
						string,
						"Kup","WyjdŸ");
					}
				}
			}
		}
		case DIALOG_BUY_3P:
		{
			if( response )
			{
				new i = gBuyBusiness[playerid];
				if( listitem == 0 )
				{
					new price;
					switch( gListItem[playerid] )
					{
						case 0: { price = Businesses[i][Product1Price]; }
						case 1: { price = Businesses[i][Product2Price]; }
						case 2: { price = Businesses[i][Product3Price]; }
						case 3: { price = Businesses[i][Product4Price]; }
						case 4: { price = Businesses[i][Product5Price]; }
						case 5: { price = Businesses[i][Product6Price]; }
						case 6: { price = Businesses[i][Product7Price]; }
						case 7: { price = Businesses[i][Product8Price]; }
						case 8: { price = Businesses[i][Product9Price]; }
						case 9: { price = Businesses[i][Product10Price]; }
						case 10: { price = Businesses[i][Product11Price]; }
						case 11: { price = Businesses[i][Product12Price]; }
						case 12: { price = Businesses[i][Product13Price]; }
						case 13: { price = Businesses[i][Product14Price]; }
						case 14: { price = Businesses[i][Product15Price]; }
						case 15: { price = Businesses[i][Product16Price]; }
						case 16: { price = Businesses[i][Product17Price]; }
						case 17: { price = Businesses[i][Product18Price]; }
						case 18: { price = Businesses[i][Product19Price]; }
						case 19: { price = Businesses[i][Product20Price]; }
						case 20: { price = Businesses[i][Product21Price]; }
					}
					format( string, sizeof(string), "Stara cena: %d$\n\nWpisz now¹ cene produktu:", price );
					ShowPlayerDialog( playerid, DIALOG_BUY_4P, DIALOG_STYLE_INPUT, "Sklep 24/7", string, "Zmieñ", "Wróæ" );
					return 1;
				}
				else
				{
					gListOverItem[playerid] = 1;
					goto BuyItem;
				}
			}
			else
			{
				goto ProdList;
				return 1;
			}
		}
		case DIALOG_BUY_4P:
		{
			if( response )
			{
				new i = gBuyBusiness[playerid];
				switch( gListItem[playerid] )
				{
					case 0:
					{
						Businesses[i][Product1Price] = strval(inputtext);
						SaveBizData( i, "Product1Price" );
					}
					case 1:
					{
						Businesses[i][Product2Price] = strval(inputtext);
						SaveBizData( i, "Product2Price" );
					}
					case 2:
					{
						Businesses[i][Product3Price] = strval(inputtext);
						SaveBizData( i, "Product3Price" );
					}
					case 3:
					{
						Businesses[i][Product4Price] = strval(inputtext);
						SaveBizData( i, "Product4Price" );
					}
					case 4:
					{
						Businesses[i][Product5Price] = strval(inputtext);
						SaveBizData( i, "Product5Price" );
					}
					case 5:
					{
						Businesses[i][Product6Price] = strval(inputtext);
						SaveBizData( i, "Product6Price" );
					}
					case 6:
					{
						Businesses[i][Product7Price] = strval(inputtext);
						SaveBizData( i, "Product7Price" );
					}
					case 7:
					{
						Businesses[i][Product8Price] = strval(inputtext);
						SaveBizData( i, "Product8Price" );
					}
					case 8:
					{
						Businesses[i][Product9Price] = strval(inputtext);
						SaveBizData( i, "Product9Price" );
					}
					case 9:
					{
						Businesses[i][Product10Price] = strval(inputtext);
						SaveBizData( i, "Product10Price" );
					}
					case 10:
					{
						Businesses[i][Product11Price] = strval(inputtext);
						SaveBizData( i, "Product11Price" );
					}
					case 11:
					{
						Businesses[i][Product12Price] = strval(inputtext);
						SaveBizData( i, "Product12Price" );
					}
					case 12:
					{
						Businesses[i][Product13Price] = strval(inputtext);
						SaveBizData( i, "Product13Price" );
					}
					case 13:
					{
						Businesses[i][Product14Price] = strval(inputtext);
						SaveBizData( i, "Product14Price" );
					}
					case 14:
					{
						Businesses[i][Product15Price] = strval(inputtext);
						SaveBizData( i, "Product15Price" );
					}
					case 15:
					{
						Businesses[i][Product16Price] = strval(inputtext);
						SaveBizData( i, "Product16Price" );
					}
					case 16:
					{
						Businesses[i][Product17Price] = strval(inputtext);
						SaveBizData( i, "Product17Price" );
					}
					case 17:
					{
						Businesses[i][Product18Price] = strval(inputtext);
						SaveBizData( i, "Product18Price" );
					}
					case 18:
					{
						Businesses[i][Product19Price] = strval(inputtext);
						SaveBizData( i, "Product19Price" );
					}
					case 19:
					{
						Businesses[i][Product20Price] = strval(inputtext);
						SaveBizData( i, "Product20Price" );
					}
					case 20:
					{
						Businesses[i][Product21Price] = strval(inputtext);
						SaveBizData( i, "Product21Price" );
					}
					case 21:
					{
						Businesses[i][Product22Price] = strval(inputtext);
						SaveBizData( i, "Product22Price" );
					}
					case 22:
					{
						Businesses[i][Product23Price] = strval(inputtext);
						SaveBizData( i, "Product23Price" );
					}
					case 23:
					{
						Businesses[i][Product24Price] = strval(inputtext);
						SaveBizData( i, "Product24Price" );
					}
					case 24:
					{
						Businesses[i][Product25Price] = strval(inputtext);
						SaveBizData( i, "Product25Price" );
					}
					case 25:
					{
						Businesses[i][Product26Price] = strval(inputtext);
						SaveBizData( i, "Product26Price" );
					}
					case 26:
					{
						Businesses[i][Product27Price] = strval(inputtext);
						SaveBizData( i, "Product27Price" );
					}
					case 27:
					{
						Businesses[i][Product28Price] = strval(inputtext);
						SaveBizData( i, "Product28Price" );
					}
					case 28:
					{
						Businesses[i][Product29Price] = strval(inputtext);
						SaveBizData( i, "Product29Price" );
					}
					case 29:
					{
						Businesses[i][Product30Price] = strval(inputtext);
						SaveBizData( i, "Product30Price" );
					}
				}
				ShowPlayerDialog(playerid,DIALOG_BUY_2P_MSG,DIALOG_STYLE_MSGBOX,"Sklep 24/7", "Zmieni³eœ cene produktu !", "Wróæ", "" );
				return 1;
			}
			else
			{
				gListOverItem[playerid] = 1;
				goto BuyMenu;
			}
		}
		case DIALOG_GOVERNMENT_1:
		{
			if(response)
			{
				if(listitem == 0)
				{
					ShowPlayerDialog(playerid,DIALOG_GOVERNMENT_JOBS,DIALOG_STYLE_LIST,"Zatrudnij siê","1. Roznosiciel gazet \n2. Detektyw \n3. Prawnik \n4. Sprzedawca produktów \n5. Kierowca autobusu \n6. Kierowca œmieciarki \n7. Kierowca myjki drogowej \n8. Farmer \n9. Mechanik \n10. Sprzedawca/ekspedient \n11. Zrezygnuj z obecnej pracy", "Wybierz","Wróæ");
				}
				else
				{
					format(string, sizeof(string), "1. Podatek VAT - %d%% \n2. Podatek od radia - %d$ \n3. Podatek od bogatych (próg: %d$) - %d%%\n4. Podatek od biznesu - %d%%",
					floatround(DynamicTaxes[VatTaxMin]*100,floatround_round), 
					DynamicTaxes[RadioTax],
					DynamicTaxes[TheRich],
					floatround(DynamicTaxes[RichTax]*100,floatround_round),
					floatround(DynamicTaxes[BusinessTax]*100,floatround_round) );
					ShowPlayerDialog(playerid,DIALOG_GOVERNMENT_TAX,DIALOG_STYLE_MSGBOX,"Aktualne podatki",string,"Zamknij","Wróæ");
				}
			}
		}
		case DIALOG_GOVERNMENT_TAX:
		{
			if(!response)
				ShowPlayerDialog(playerid,DIALOG_GOVERNMENT_1,DIALOG_STYLE_LIST,"Co chcesz zrobiæ ?",DIALOG_GOVERNMENT_1_TXT,"Wybierz","Zamknij");
		}
		case DIALOG_GOVERNMENT_JOBS:
		{
			if(response)
			{
				gSelectedSlot[playerid] = listitem;
				if(listitem == 0) // roznosiciel gazet
					ShowPlayerDialog(playerid,DIALOG_GOVERNMENT_JOBS_2,DIALOG_STYLE_MSGBOX,"Zatrudnij siê","W tej pracy twoim zadaniem bêdzie roznoszenie gazet pod domy w mieœcie.\nWynagrodzenie za jedn¹ dostarczon¹ gazete to 2$\n\nWymagania:\nBRAK",DIALOG_GOV_APPLY_TXT,"Wróæ");
				else if (listitem == 1) // detektyw
					ShowPlayerDialog(playerid,DIALOG_GOVERNMENT_JOBS_2,DIALOG_STYLE_MSGBOX,"Zatrudnij siê","Jako detektyw masz mo¿liwoœæ œledzenia osób oraz pojazdów.\nMo¿esz zarabiaæ oferuj¹c swoje uslugi innym.\n\nWymagania:\n2 poziom WF-u\n4 poziom matematyki",DIALOG_GOV_APPLY_TXT,"Wróæ");
				else if (listitem == 2) // prawnik
					ShowPlayerDialog(playerid,DIALOG_GOVERNMENT_JOBS_2,DIALOG_STYLE_MSGBOX,"Zatrudnij siê","Prawnik ma mo¿liwoœæ skrócenia kary osobom siedz¹cym w wiêzieniu.\nMo¿esz zarabiaæ oferuj¹c swoje uslugi innym.\n\nWymagania:\n4 poaziom matematyki",DIALOG_GOV_APPLY_TXT,"Wróæ");
				else if (listitem == 3) // sprzedawca produktów
					ShowPlayerDialog(playerid,DIALOG_GOVERNMENT_JOBS_2,DIALOG_STYLE_MSGBOX,"Zatrudnij siê","Sprzedawca produktów sprzedaje produkty wlaœcicielom biznesów przy czym sam ustala ich cene.\n\nWymagania:\nPrawo jazdy",DIALOG_GOV_APPLY_TXT,"Wróæ");
				else if (listitem == 4) // kierowca autobusu
					ShowPlayerDialog(playerid,DIALOG_GOVERNMENT_JOBS_2,DIALOG_STYLE_MSGBOX,"Zatrudnij siê","Kierowca autobusu jeŸdzi po wyznaczonych trasach, zatrzymuj¹c sie na przystankach i zabieraj¹c pasa¿erów.\nWynagrodzenie jest zale¿ne od trasy.\n\nWymagania:\nPrawo jazdy",DIALOG_GOV_APPLY_TXT,"Wróæ");
				else if (listitem == 5) // kierowca œmieciarki
					ShowPlayerDialog(playerid,DIALOG_GOVERNMENT_JOBS_2,DIALOG_STYLE_MSGBOX,"Zatrudnij siê","Kierowca œmieciarki zbiera œmieci z miast w San Andreas.\n\nWymagania:\nPrawo jazdy",DIALOG_GOV_APPLY_TXT,"Wróæ");
				else if (listitem == 6) // kierowca myjki drogowej
					ShowPlayerDialog(playerid,DIALOG_GOVERNMENT_JOBS_2,DIALOG_STYLE_MSGBOX,"Zatrudnij siê","Kierowca myjki drogowej dba o czystoœæ ulic w San Andreas\n\nWymagania:\nPrawo jazdy",DIALOG_GOV_APPLY_TXT,"Wróæ");
				else if (listitem == 7) // farmer
					ShowPlayerDialog(playerid,DIALOG_GOVERNMENT_JOBS_2,DIALOG_STYLE_MSGBOX,"Zatrudnij siê","Farmer œcina plony je¿d¿¹c kombajnem, nastêpnie zsypuje to co udalo mu sie uzbieraæ do magazynu.\n\nWymagania:\nBRAK",DIALOG_GOV_APPLY_TXT,"Wróæ");
				else if (listitem == 8) // mechanik
					ShowPlayerDialog(playerid,DIALOG_GOVERNMENT_JOBS_2,DIALOG_STYLE_MSGBOX,"Zatrudnij siê","Mechanik zajmuje siê ró¿nymi pojazdami i dba o ich sprawnoœæ za co uzyskuje odpowiednie wynagordzenie.\n\nWymagania:\n1 poziom WF-u\n1 poziom Matematyki",DIALOG_GOV_APPLY_TXT,"Wróæ");
				else if (listitem == 9) // sprzedawca/ekspedient
					ShowPlayerDialog(playerid,DIALOG_GOVERNMENT_JOBS_2,DIALOG_STYLE_MSGBOX,"Zatrudnij siê","Sprzedawca/ekspedient sprzedaje produkty w sklepie (biznesie).\nPraca polega na przesiadywaniu w biznesie i obsludze wchodz¹cych klientów.\n\nWymagania:\nBRAK",DIALOG_GOV_APPLY_TXT,"Wróæ");
				else if (listitem == 10)
				{
					if(gPlayerData[playerid][pJob] != 0)
					{
						if(gPlayerData[playerid][pJobTimeChange] == 0)
						{
							if(gBusDriverOnDuty[playerid] == 1)
								gBusDriverOnDuty[playerid] = 0;

							gPlayerData[playerid][pJob] = 0;
							SavePlayerData(playerid, "Job");

							SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] Zrezygnowa³eœ ze swojej pracy.");
						}
						else
						{
							format(string, sizeof(string), "[B£¥D:] Nie mo¿esz zrezygnowaæ ze swoje pracy. Musisz przepracowaæ jeszcze oko³o %d godzin", gPlayerData[playerid][pJobTimeChange]);
							SendClientMessage(playerid,COLOR_RED, string);
						}
					}
					else
					{
						SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] Nie masz aktualnie pracy !");
					}
					return 1;
				}
			}
			else
			{
				ShowPlayerDialog(playerid,DIALOG_GOVERNMENT_1,DIALOG_STYLE_LIST,"Co chcesz zrobiæ ?",DIALOG_GOVERNMENT_1_TXT,"Wybierz","Zamknij");
			}
		}
		case DIALOG_GOVERNMENT_JOBS_2:
		{
			if(response)
			{
				if(gPlayerData[playerid][pJob] != 0)
					ShowPlayerDialog(playerid,DIALOG_GOVERNMENT_JOBS_3,DIALOG_STYLE_MSGBOX,"Informacja","Posiadasz ju¿ prace !\nZanim weŸmiesz now¹ musisz zwolniæ siê ze starej.","Wróæ","");
				else
				{
					if (gSelectedSlot[playerid] == 0)
					{
						gPlayerData[playerid][pJob] = 21; //NewsBoy
						SavePlayerData(playerid, "Job");
					}
					else if (gSelectedSlot[playerid] == 1)
					{
						if(gPlayerData[playerid][pWf] < 2 || gPlayerData[playerid][pMat] < 4)
						{
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] Do tej pracy wymagany jest przynajmniej 2 poziom WFu oraz 4 poziom matematyki");
						}
						else
						{
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[SUKCES:] Jesteœ teraz detektywem, wpisz /komendypracy.");
							gPlayerData[playerid][pJob] = 3; //Detective Job

							SavePlayerData(playerid, "Job");
						}
					}
					else if (gSelectedSlot[playerid] == 2)
					{
						if(gPlayerData[playerid][pMat] < 5)
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Musisz mieæ co najmniej 5 poziom matematyki aby zdobyæ t¹ prace");
						}
						else
						{
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[SUKCES:] Jesteœ teraz prawnikiem, wpisz /komendypracy.");
							gPlayerData[playerid][pJob] = 4; //Lawyer Job

							SavePlayerData(playerid, "Job");
						}
					}
					else if (gSelectedSlot[playerid] == 3)
					{
						if(gPlayerData[playerid][pCarLic] == 0)
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] Prawo jazdy jest wymagane do tej pracy !");
						else
						{
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[SUKCES:] Jesteœ teraz sprzedawc¹ produktów, wpisz /komendypracy.");
							gPlayerData[playerid][pJob] = 5; //Products Seller Job
							
							SavePlayerData(playerid, "Job");
						}
					}
					else if (gSelectedSlot[playerid] == 4)
					{
						if(gPlayerData[playerid][pCarLic] == 0)
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] Prawo jazdy jest wymagane do tej pracy !");
						else
						{
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[SUKCES:] Jesteœ teraz kierowc¹ autobusu, wpisz /komendypracy.");
							gPlayerData[playerid][pJob] = 13; //Bus Driver

							SavePlayerData(playerid, "Job");
						}
					}
					else if (gSelectedSlot[playerid] == 5)
					{
						if(gPlayerData[playerid][pCarLic] == 0)
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] Prawo jazdy jest wymagane do tej pracy !");
						else
						{
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[SUKCES:] Jesteœ teraz kierowc¹ œmieciarki wpisz /komendypracy.");
							gPlayerData[playerid][pJob] = 14; //Mzgk Driver

							SavePlayerData(playerid, "Job");
						}
					}
					else if (gSelectedSlot[playerid] == 6)
					{
						if(gPlayerData[playerid][pCarLic] == 0)
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] Prawo jazdy jest wymagane do tej pracy !");
						else
						{
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[SUKCES:] Jesteœ teraz kierowc¹ myjki samochodowej, wpisz /komendypracy.");
							gPlayerData[playerid][pJob] = 15; //Sweeper Driver

							SavePlayerData(playerid, "Job");
						}
					}
					else if (gSelectedSlot[playerid] == 7)
					{
						if( gPlayerData[playerid][pLevel] < 2 )
						{
							SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz wzi¹œæ tej pracy - musisz mieæ 2 poziom postaci");
							return 1;
						}
						SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[SUKCES:] Jesteœ teraz Farmerem, wpisz /komendypracy.");
						gPlayerData[playerid][pJob] = 18; //Farmer Driver

						SavePlayerData(playerid, "Job");
					}
					else if (gSelectedSlot[playerid] == 8)
					{
						if(gPlayerData[playerid][pWf] < 1 || gPlayerData[playerid][pMat] < 1)
						{
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] Musisz mieæ co najmniej 1 poziom WFu i 1 poziom matematyki ¿eby zdobyæ t¹ prace");
						}
						else
						{
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[SUKCES:] Jesteœ teraz mechanikiem, wpisz /komendypracy.");
							gPlayerData[playerid][pJob] = 17; // Mechanik

							SavePlayerData(playerid, "Job");
						}
					}
					else if (gSelectedSlot[playerid] == 9)
					{
						SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[SUKCES:] Jesteœ teraz sprzedawc¹/ekspedientem, wpisz /komendypracy.");
						gPlayerData[playerid][pJob] = 19; //Seller

						SavePlayerData(playerid, "Job");
					}
				}
				return 1;
			}
			else
			{
				ShowPlayerDialog(playerid,DIALOG_GOVERNMENT_JOBS,DIALOG_STYLE_LIST,"Zatrudnij siê","1. Roznosiciel gazet \n2. Detektyw \n3. Prawnik \n4. Sprzedawca produktów \n5. Kierowca autobusu \n6. Kierowca œmieciarki \n7. Kierowca myjki drogowej \n8. Farmer \n9. Mechanik \n10. Sprzedawca/ekspedient \n11. Zrezygnuj z obecnej pracy", "Wybierz","Wróæ");
				return 1;
			}
		}
		case DIALOG_GOVERNMENT_JOBS_3:
		{
			if(response)
				ShowPlayerDialog(playerid,DIALOG_GOVERNMENT_1,DIALOG_STYLE_LIST,"Co chcesz zrobiæ ?",DIALOG_GOVERNMENT_1_TXT,"Wybierz","Zamknij");
			return 1;
		}
		case DIALOG_HITEM_1: // menu glowne itemow w domu
		{
			if(response)
			{
				gDSelectedHItem[playerid] = listitem+1;
				selectItem:
				ShowPlayerDialog(playerid,DIALOG_HITEM_2,DIALOG_STYLE_LIST,"Dzia³anie","1. Zabierz item\n2. Wyrzuc item","Akceptuj","Wróæ");
			}
			return 1;
		}
		case DIALOG_HITEM_2:
		{
			if(response)
			{
				if(listitem == 0) // zabierz item
				{
					/*
					* PUSTY SLOT
					*/
					if(!HItemSlotStatus(gDSelectedHItemHouse[playerid], gDSelectedHItem[playerid]))
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten slot jest pusty !");
						return 1;
					}
					if( HSlotParam6(gDSelectedHItemHouse[playerid], gDSelectedHItem[playerid]) > 1 )
					{
						ShowPlayerDialog(playerid,DIALOG_HITEM_4,DIALOG_STYLE_INPUT,"Wpisz iloœæ","Podaj wartoœæ reprezentuj¹c¹ iloœæ itemów do zabrania z domu","Akceptuj","Wróæ");
						return 1;
					}
					new slotin;
					if (gDSelectedHItem[playerid] == 1)
					{
						slotin = InsertPlayerItemEx(playerid, 
							Houses[gDSelectedHItemHouse[playerid]][HItem1type],
							Houses[gDSelectedHItemHouse[playerid]][HItem1], 
							Houses[gDSelectedHItemHouse[playerid]][HItem1param], 
							Houses[gDSelectedHItemHouse[playerid]][HItem1param2], 
							Houses[gDSelectedHItemHouse[playerid]][HItem1param3],
							Houses[gDSelectedHItemHouse[playerid]][HItem1param4],
							Houses[gDSelectedHItemHouse[playerid]][HItem1param5],
							Houses[gDSelectedHItemHouse[playerid]][HItem1param6]);
						if(slotin == 0)
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz przenosiæ wiêcej przedmiotów !");
							return 1;
						}
					}
					else if (gDSelectedHItem[playerid] == 2)
					{
						slotin = InsertPlayerItemEx(playerid,
							Houses[gDSelectedHItemHouse[playerid]][HItem2type], 
							Houses[gDSelectedHItemHouse[playerid]][HItem2], 
							Houses[gDSelectedHItemHouse[playerid]][HItem2param], 
							Houses[gDSelectedHItemHouse[playerid]][HItem2param2], 
							Houses[gDSelectedHItemHouse[playerid]][HItem2param3],
							Houses[gDSelectedHItemHouse[playerid]][HItem2param4],
							Houses[gDSelectedHItemHouse[playerid]][HItem2param5],
							Houses[gDSelectedHItemHouse[playerid]][HItem2param6]);
						if(slotin == 0)
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz przenosiæ wiêcej przedmiotów !");
							return 1;
						}
					}
					else if (gDSelectedHItem[playerid] == 3)
					{
						slotin = InsertPlayerItemEx(playerid, 
						Houses[gDSelectedHItemHouse[playerid]][HItem3type], 
						Houses[gDSelectedHItemHouse[playerid]][HItem3], 
						Houses[gDSelectedHItemHouse[playerid]][HItem3param], 
						Houses[gDSelectedHItemHouse[playerid]][HItem3param2], 
						Houses[gDSelectedHItemHouse[playerid]][HItem3param3],
						Houses[gDSelectedHItemHouse[playerid]][HItem3param4],
						Houses[gDSelectedHItemHouse[playerid]][HItem3param5],
						Houses[gDSelectedHItemHouse[playerid]][HItem3param6]);
						if(slotin == 0)
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz przenosiæ wiêcej przedmiotów !");
							return 1;
						}
					}
					else if (gDSelectedHItem[playerid] == 4)
					{
						slotin = InsertPlayerItemEx(playerid, 
						Houses[gDSelectedHItemHouse[playerid]][HItem4type], 
						Houses[gDSelectedHItemHouse[playerid]][HItem4], 
						Houses[gDSelectedHItemHouse[playerid]][HItem4param], 
						Houses[gDSelectedHItemHouse[playerid]][HItem4param2], 
						Houses[gDSelectedHItemHouse[playerid]][HItem4param3],
						Houses[gDSelectedHItemHouse[playerid]][HItem4param4],
						Houses[gDSelectedHItemHouse[playerid]][HItem4param5],
						Houses[gDSelectedHItemHouse[playerid]][HItem4param6]);
						if(slotin == 0)
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz przenosiæ wiêcej przedmiotów !");
							return 1;
						}
					}
					else if (gDSelectedHItem[playerid] == 5)
					{
						slotin = InsertPlayerItemEx(playerid, 
						Houses[gDSelectedHItemHouse[playerid]][HItem5type], 
						Houses[gDSelectedHItemHouse[playerid]][HItem5], 
						Houses[gDSelectedHItemHouse[playerid]][HItem5param], 
						Houses[gDSelectedHItemHouse[playerid]][HItem5param2], 
						Houses[gDSelectedHItemHouse[playerid]][HItem5param3],
						Houses[gDSelectedHItemHouse[playerid]][HItem5param4],
						Houses[gDSelectedHItemHouse[playerid]][HItem5param5],
						Houses[gDSelectedHItemHouse[playerid]][HItem5param6]);
						if(slotin == 0)
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz przenosiæ wiêcej przedmiotów !");
							return 1;
						}
					}
					RemoveHouseItemEx(gDSelectedHItemHouse[playerid],gDSelectedHItem[playerid]);
					format(string, sizeof(string), "[INFO:] Zabra³eœ item z pokoju (ze slotu %d)", gDSelectedHItem[playerid]);
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
					PlayerActionMessage(playerid, 15.0, "zabiera przedmiot z pó³ki");
					return 1;
				}
				else // wyrzuc item
				{
					if(HSlotItemTypeCompare(gDSelectedHItemHouse[playerid], gDSelectedHItem[playerid], 1) && HSlotParam6(gDSelectedHItemHouse[playerid], gDSelectedHItem[playerid] > 1))
					{
						ShowPlayerDialog(playerid,DIALOG_HITEM_3,DIALOG_STYLE_INPUT,"Wpisz iloœæ","Wpisz ile itemów danego typu chcesz wyrzuciæ","Wyrzuæ","Anuluj");
						return 1;
					}
					RemoveHouseItemEx(gDSelectedHItemHouse[playerid], gDSelectedHItem[playerid]);
					format(string, sizeof(string), "[INFO:] Wyrzuci³eœ item z domu (ze slotu %d)", gDSelectedHItem[playerid]);
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
					PlayerActionMessage(playerid, 15.0, "wyrzuca przedmiot z pó³ki");
					return 1;
				}
			}
			else
			{
				format(string, sizeof(string), "1. %s [iloœæ: %d] [waga: %d]\n2. %s [iloœæ: %d] [waga: %d]\n3. %s [iloœæ: %d] [waga: %d]\n4. %s [iloœæ: %d] [waga: %d]\n5. %s [iloœæ: %d] [waga: %d]",
				ItemName(Houses[gDSelectedHItemHouse[playerid]][HItem1type], Houses[gDSelectedHItemHouse[playerid]][HItem1]),HSlotParam6(gDSelectedHItemHouse[playerid], 1), ItemWeight(Houses[gDSelectedHItemHouse[playerid]][HItem1type], Houses[gDSelectedHItemHouse[playerid]][HItem1]),
				ItemName(Houses[gDSelectedHItemHouse[playerid]][HItem2type], Houses[gDSelectedHItemHouse[playerid]][HItem2]),HSlotParam6(gDSelectedHItemHouse[playerid], 2), ItemWeight(Houses[gDSelectedHItemHouse[playerid]][HItem2type], Houses[gDSelectedHItemHouse[playerid]][HItem2]),
				ItemName(Houses[gDSelectedHItemHouse[playerid]][HItem3type], Houses[gDSelectedHItemHouse[playerid]][HItem3]),HSlotParam6(gDSelectedHItemHouse[playerid], 3), ItemWeight(Houses[gDSelectedHItemHouse[playerid]][HItem3type], Houses[gDSelectedHItemHouse[playerid]][HItem3]),
				ItemName(Houses[gDSelectedHItemHouse[playerid]][HItem4type], Houses[gDSelectedHItemHouse[playerid]][HItem4]),HSlotParam6(gDSelectedHItemHouse[playerid], 4), ItemWeight(Houses[gDSelectedHItemHouse[playerid]][HItem4type], Houses[gDSelectedHItemHouse[playerid]][HItem4]),
				ItemName(Houses[gDSelectedHItemHouse[playerid]][HItem5type], Houses[gDSelectedHItemHouse[playerid]][HItem5]),HSlotParam6(gDSelectedHItemHouse[playerid], 5), ItemWeight(Houses[gDSelectedHItemHouse[playerid]][HItem5type], Houses[gDSelectedHItemHouse[playerid]][HItem5]) );
				format(string2, sizeof(string2), "Moje itemy w domu - waga ca³kowita %d", HItemWeight(gDSelectedHItemHouse[playerid]));
				ShowPlayerDialog(playerid,DIALOG_HITEM_1,DIALOG_STYLE_LIST,string2,string,"Wybierz","Anuluj");
				return 1;
			}
		}
		case DIALOG_HITEM_3:
		{
			new howMuch = strval(inputtext);
			if(HSlotParam6(gDSelectedHItemHouse[playerid], gDSelectedHItem[playerid]) <= 0)
			{
				RemoveHouseItemEx(gDSelectedHItemHouse[playerid], gDSelectedHItem[playerid]);
				format(string, sizeof(string), "[INFO:] Wyrzuci³eœ item ze slotu %d", gDSelectedHItem[playerid]);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2,string);
				return 1;
			}
			if(howMuch > HSlotParam6(gDSelectedHItemHouse[playerid], gDSelectedHItem[playerid]))
			{
				ShowPlayerDialog(playerid,DIALOG_HITEM_3,DIALOG_STYLE_INPUT,"Wpisz iloœæ","Nie posiadasz tyle przedmiotów danego typu !\nWpisz now¹ wartoœæ","Wyrzuæ","Anuluj");
				return 1;
			}
			else if(howMuch == 0)
			{
				ShowPlayerDialog(playerid,DIALOG_HITEM_3,DIALOG_STYLE_INPUT,"Wpisz iloœæ","Poda³eœ b³êdn¹ wartoœæ\nWpisz now¹","Wyrzuæ","Anuluj");
				return 1;
			}
			if(HSlotParam6(gDSelectedHItemHouse[playerid], gDSelectedHItem[playerid])-howMuch == 0)
				RemoveHouseItemEx(gDSelectedHItemHouse[playerid], gDSelectedHItem[playerid]);
			else
				SetHSlotParam6(gDSelectedHItemHouse[playerid], gDSelectedHItem[playerid], HSlotParam6(gDSelectedHItemHouse[playerid], gDSelectedHItem[playerid])-howMuch);
			format(string, sizeof(string), "[INFO:] Wyrzuci³eœ %d itemów", howMuch);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			return 1;
		}
		case DIALOG_HITEM_4:
		{
			if(response)
			{
				if( strval(inputtext) <= 0 || strval(inputtext) > HSlotParam6(gDSelectedHItemHouse[playerid], gDSelectedHItem[playerid]) )
				{
					ShowPlayerDialog(playerid,DIALOG_HITEM_4,DIALOG_STYLE_INPUT,"Wpisz iloœæ", "Poda³eœ nieprawid³ow¹ wartoœæ !\nWpisz wartoœæ ponownie","Akceptuj","Wróæ");
					return 1;
				}
				new howMuch = strval(inputtext);
				new slotin;
				if (gDSelectedHItem[playerid] == 1)
				{
					if(PlayerCountMaxItemCarry(playerid, Houses[gDSelectedHItemHouse[playerid]][HItem1type], Houses[gDSelectedHItemHouse[playerid]][HItem1]) < howMuch)
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie uniesiesz tylu itemów !");
						format(string, sizeof(string), "[INFO:] Mo¿esz przenieœæ tylko %d tych itemów", PlayerCountMaxItemCarry(playerid, Houses[gDSelectedHItemHouse[playerid]][HItem1type], Houses[gDSelectedHItemHouse[playerid]][HItem1]));
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
						return 1;
					}
					slotin = InsertPlayerItemEx(playerid, 
						Houses[gDSelectedHItemHouse[playerid]][HItem1type],
						Houses[gDSelectedHItemHouse[playerid]][HItem1], 
						Houses[gDSelectedHItemHouse[playerid]][HItem1param], 
						Houses[gDSelectedHItemHouse[playerid]][HItem1param2], 
						Houses[gDSelectedHItemHouse[playerid]][HItem1param3],
						Houses[gDSelectedHItemHouse[playerid]][HItem1param4],
						Houses[gDSelectedHItemHouse[playerid]][HItem1param5],
						howMuch);
					if(slotin == 0)
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz przenosiæ wiêcej przedmiotów !");
						return 1;
					}
				}
				else if (gDSelectedHItem[playerid] == 2)
				{
					if(PlayerCountMaxItemCarry(playerid, Houses[gDSelectedHItemHouse[playerid]][HItem2type], Houses[gDSelectedHItemHouse[playerid]][HItem2]) < howMuch)
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie uniesiesz tylu itemów !");
						format(string, sizeof(string), "[INFO:] Mo¿esz przenieœæ tylko %d tych itemów", PlayerCountMaxItemCarry(playerid, Houses[gDSelectedHItemHouse[playerid]][HItem2type], Houses[gDSelectedHItemHouse[playerid]][HItem2]));
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
						return 1;
					}
					slotin = InsertPlayerItemEx(playerid,
						Houses[gDSelectedHItemHouse[playerid]][HItem2type], 
						Houses[gDSelectedHItemHouse[playerid]][HItem2], 
						Houses[gDSelectedHItemHouse[playerid]][HItem2param], 
						Houses[gDSelectedHItemHouse[playerid]][HItem2param2], 
						Houses[gDSelectedHItemHouse[playerid]][HItem2param3],
						Houses[gDSelectedHItemHouse[playerid]][HItem2param4],
						Houses[gDSelectedHItemHouse[playerid]][HItem2param5],
						howMuch);
					if(slotin == 0)
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz przenosiæ wiêcej przedmiotów !");
						return 1;
					}
				}
				else if (gDSelectedHItem[playerid] == 3)
				{
					if(PlayerCountMaxItemCarry(playerid, Houses[gDSelectedHItemHouse[playerid]][HItem3type], Houses[gDSelectedHItemHouse[playerid]][HItem3]) < howMuch)
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie uniesiesz tylu itemów !");
						format(string, sizeof(string), "[INFO:] Mo¿esz przenieœæ tylko %d tych itemów", PlayerCountMaxItemCarry(playerid, Houses[gDSelectedHItemHouse[playerid]][HItem3type], Houses[gDSelectedHItemHouse[playerid]][HItem3]));
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
						return 1;
					}
					slotin = InsertPlayerItemEx(playerid, 
					Houses[gDSelectedHItemHouse[playerid]][HItem3type], 
					Houses[gDSelectedHItemHouse[playerid]][HItem3], 
					Houses[gDSelectedHItemHouse[playerid]][HItem3param], 
					Houses[gDSelectedHItemHouse[playerid]][HItem3param2], 
					Houses[gDSelectedHItemHouse[playerid]][HItem3param3],
					Houses[gDSelectedHItemHouse[playerid]][HItem3param4],
					Houses[gDSelectedHItemHouse[playerid]][HItem3param5],
					howMuch);
					if(slotin == 0)
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz przenosiæ wiêcej przedmiotów !");
						return 1;
					}
				}
				else if (gDSelectedHItem[playerid] == 4)
				{
					if(PlayerCountMaxItemCarry(playerid, Houses[gDSelectedHItemHouse[playerid]][HItem4type], Houses[gDSelectedHItemHouse[playerid]][HItem4]) < howMuch)
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie uniesiesz tylu itemów !");
						format(string, sizeof(string), "[INFO:] Mo¿esz przenieœæ tylko %d tych itemów", PlayerCountMaxItemCarry(playerid, Houses[gDSelectedHItemHouse[playerid]][HItem4type], Houses[gDSelectedHItemHouse[playerid]][HItem4]));
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
						return 1;
					}
					slotin = InsertPlayerItemEx(playerid, 
					Houses[gDSelectedHItemHouse[playerid]][HItem4type], 
					Houses[gDSelectedHItemHouse[playerid]][HItem4], 
					Houses[gDSelectedHItemHouse[playerid]][HItem4param], 
					Houses[gDSelectedHItemHouse[playerid]][HItem4param2], 
					Houses[gDSelectedHItemHouse[playerid]][HItem4param3],
					Houses[gDSelectedHItemHouse[playerid]][HItem4param4],
					Houses[gDSelectedHItemHouse[playerid]][HItem4param5],
					howMuch);
					if(slotin == 0)
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz przenosiæ wiêcej przedmiotów !");
						return 1;
					}
				}
				else if (gDSelectedHItem[playerid] == 5)
				{
					if(PlayerCountMaxItemCarry(playerid, Houses[gDSelectedHItemHouse[playerid]][HItem5type], Houses[gDSelectedHItemHouse[playerid]][HItem5]) < howMuch)
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie uniesiesz tylu itemów !");
						format(string, sizeof(string), "[INFO:] Mo¿esz przenieœæ tylko %d tych itemów", PlayerCountMaxItemCarry(playerid, Houses[gDSelectedHItemHouse[playerid]][HItem5type], Houses[gDSelectedHItemHouse[playerid]][HItem5]));
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
						return 1;
					}
					slotin = InsertPlayerItemEx(playerid, 
					Houses[gDSelectedHItemHouse[playerid]][HItem5type], 
					Houses[gDSelectedHItemHouse[playerid]][HItem5], 
					Houses[gDSelectedHItemHouse[playerid]][HItem5param], 
					Houses[gDSelectedHItemHouse[playerid]][HItem5param2], 
					Houses[gDSelectedHItemHouse[playerid]][HItem5param3],
					Houses[gDSelectedHItemHouse[playerid]][HItem5param4],
					Houses[gDSelectedHItemHouse[playerid]][HItem5param5],
					howMuch);
					if(slotin == 0)
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz przenosiæ wiêcej przedmiotów !");
						return 1;
					}
				}
				RemoveHouseItemEx(gDSelectedHItemHouse[playerid], gDSelectedHItem[playerid], howMuch);
				format(string, sizeof(string), "[INFO:] Zabra³eœ item z pokoju (ze slotu %d)", gDSelectedHItem[playerid]);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
				PlayerActionMessage(playerid, 15.0, "zabiera przedmiot z pó³ki");
				return 1;
			}
			else
			{
				goto selectItem;
				return 1;
			}
		}
		case DIALOG_VITEM_1: // menu glowne itemow w pojedzie
		{
			if(response)
			{
				gDSelectedVItemSlot[playerid] = listitem+1;
				selectVItem:
				ShowPlayerDialog(playerid,DIALOG_VITEM_2,DIALOG_STYLE_LIST,"Dzia³anie","1. Zabierz item\n2. Wyrzuc item","Akceptuj","Wróæ");
			}
			return 1;
		}
		case DIALOG_VITEM_2:
		{
			if(response)
			{
				if(listitem == 0) // zabierz item
				{
					/*
					* PUSTY SLOT
					*/
					if(!VItemSlotStatus(gDSelectedVItemVID[playerid], gDSelectedVItemSlot[playerid]))
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten slot jest pusty !");
						return 1;
					}
					if( VSlotParam6(gDSelectedVItemVID[playerid], gDSelectedVItemSlot[playerid]) > 1 )
					{
						ShowPlayerDialog(playerid,DIALOG_VITEM_4,DIALOG_STYLE_INPUT,"Wpisz iloœæ","Podaj wartoœæ reprezentuj¹c¹ iloœæ itemów do zabrania ze schowka","Akceptuj","Wróæ");
						return 1;
					}
					new slotin;
					if (gDSelectedVItemSlot[playerid] == 1)
					{
						slotin = InsertPlayerItemEx(playerid, 
							gVehData[gDSelectedVItemVID[playerid]-1][VItem1type],
							gVehData[gDSelectedVItemVID[playerid]-1][VItem1], 
							gVehData[gDSelectedVItemVID[playerid]-1][VItem1param], 
							gVehData[gDSelectedVItemVID[playerid]-1][VItem1param2], 
							gVehData[gDSelectedVItemVID[playerid]-1][VItem1param3],
							gVehData[gDSelectedVItemVID[playerid]-1][VItem1param4],
							gVehData[gDSelectedVItemVID[playerid]-1][VItem1param5],
							gVehData[gDSelectedVItemVID[playerid]-1][VItem1param6]);
						if(slotin == 0)
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz przenosiæ wiêcej przedmiotów !");
							return 1;
						}
					}
					else if (gDSelectedVItemSlot[playerid] == 2)
					{
						slotin = InsertPlayerItemEx(playerid,
							gVehData[gDSelectedVItemVID[playerid]-1][VItem2type], 
							gVehData[gDSelectedVItemVID[playerid]-1][VItem2], 
							gVehData[gDSelectedVItemVID[playerid]-1][VItem2param], 
							gVehData[gDSelectedVItemVID[playerid]-1][VItem2param2], 
							gVehData[gDSelectedVItemVID[playerid]-1][VItem2param3],
							gVehData[gDSelectedVItemVID[playerid]-1][VItem2param4],
							gVehData[gDSelectedVItemVID[playerid]-1][VItem2param5],
							gVehData[gDSelectedVItemVID[playerid]-1][VItem2param6]);
						if(slotin == 0)
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz przenosiæ wiêcej przedmiotów !");
							return 1;
						}
					}
					else if (gDSelectedVItemSlot[playerid] == 3)
					{
						slotin = InsertPlayerItemEx(playerid, 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem3type], 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem3], 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem3param], 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem3param2], 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem3param3],
						gVehData[gDSelectedVItemVID[playerid]-1][VItem3param4],
						gVehData[gDSelectedVItemVID[playerid]-1][VItem3param5],
						gVehData[gDSelectedVItemVID[playerid]-1][VItem3param6]);
						if(slotin == 0)
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz przenosiæ wiêcej przedmiotów !");
							return 1;
						}
					}
					else if (gDSelectedVItemSlot[playerid] == 4)
					{
						slotin = InsertPlayerItemEx(playerid, 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem4type], 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem4], 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem4param], 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem4param2], 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem4param3],
						gVehData[gDSelectedVItemVID[playerid]-1][VItem4param4],
						gVehData[gDSelectedVItemVID[playerid]-1][VItem4param5],
						gVehData[gDSelectedVItemVID[playerid]-1][VItem4param6]);
						if(slotin == 0)
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz przenosiæ wiêcej przedmiotów !");
							return 1;
						}
					}
					else if (gDSelectedVItemSlot[playerid] == 5)
					{
						slotin = InsertPlayerItemEx(playerid, 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem5type], 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem5], 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem5param], 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem5param2], 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem5param3],
						gVehData[gDSelectedVItemVID[playerid]-1][VItem5param4],
						gVehData[gDSelectedVItemVID[playerid]-1][VItem5param5],
						gVehData[gDSelectedVItemVID[playerid]-1][VItem5param6]);
						if(slotin == 0)
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz przenosiæ wiêcej przedmiotów !");
							return 1;
						}
					}
					else if (gDSelectedVItemSlot[playerid] == 6)
					{
						slotin = InsertPlayerItemEx(playerid, 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem6type], 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem6], 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem6param], 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem6param2], 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem6param3],
						gVehData[gDSelectedVItemVID[playerid]-1][VItem6param4],
						gVehData[gDSelectedVItemVID[playerid]-1][VItem6param5],
						gVehData[gDSelectedVItemVID[playerid]-1][VItem6param6]);
						if(slotin == 0)
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz przenosiæ wiêcej przedmiotów !");
							return 1;
						}
					}
					else if (gDSelectedVItemSlot[playerid] == 7)
					{
						slotin = InsertPlayerItemEx(playerid, 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem7type], 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem7], 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem7param], 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem7param2], 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem7param3],
						gVehData[gDSelectedVItemVID[playerid]-1][VItem7param4],
						gVehData[gDSelectedVItemVID[playerid]-1][VItem7param5],
						gVehData[gDSelectedVItemVID[playerid]-1][VItem7param6]);
						if(slotin == 0)
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz przenosiæ wiêcej przedmiotów !");
							return 1;
						}
					}
					else if (gDSelectedVItemSlot[playerid] == 8)
					{
						slotin = InsertPlayerItemEx(playerid, 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem8type], 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem8], 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem8param], 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem8param2], 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem8param3],
						gVehData[gDSelectedVItemVID[playerid]-1][VItem8param4],
						gVehData[gDSelectedVItemVID[playerid]-1][VItem8param5],
						gVehData[gDSelectedVItemVID[playerid]-1][VItem8param6]);
						if(slotin == 0)
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz przenosiæ wiêcej przedmiotów !");
							return 1;
						}
					}
					else if (gDSelectedVItemSlot[playerid] == 9)
					{
						slotin = InsertPlayerItemEx(playerid, 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem9type], 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem9], 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem9param], 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem9param2], 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem9param3],
						gVehData[gDSelectedVItemVID[playerid]-1][VItem9param4],
						gVehData[gDSelectedVItemVID[playerid]-1][VItem9param5],
						gVehData[gDSelectedVItemVID[playerid]-1][VItem9param6]);
						if(slotin == 0)
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz przenosiæ wiêcej przedmiotów !");
							return 1;
						}
					}
					else if (gDSelectedVItemSlot[playerid] == 10)
					{
						slotin = InsertPlayerItemEx(playerid, 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem10type], 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem10], 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem10param], 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem10param2], 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem10param3],
						gVehData[gDSelectedVItemVID[playerid]-1][VItem10param4],
						gVehData[gDSelectedVItemVID[playerid]-1][VItem10param5],
						gVehData[gDSelectedVItemVID[playerid]-1][VItem10param6]);
						if(slotin == 0)
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz przenosiæ wiêcej przedmiotów !");
							return 1;
						}
					}
					else if (gDSelectedVItemSlot[playerid] == 11)
					{
						slotin = InsertPlayerItemEx(playerid, 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem11type], 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem11], 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem11param], 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem11param2], 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem11param3],
						gVehData[gDSelectedVItemVID[playerid]-1][VItem11param4],
						gVehData[gDSelectedVItemVID[playerid]-1][VItem11param5],
						gVehData[gDSelectedVItemVID[playerid]-1][VItem11param6]);
						if(slotin == 0)
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz przenosiæ wiêcej przedmiotów !");
							return 1;
						}
					}
					else if (gDSelectedVItemSlot[playerid] == 12)
					{
						slotin = InsertPlayerItemEx(playerid, 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem12type], 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem12], 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem12param], 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem12param2], 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem12param3],
						gVehData[gDSelectedVItemVID[playerid]-1][VItem12param4],
						gVehData[gDSelectedVItemVID[playerid]-1][VItem12param5],
						gVehData[gDSelectedVItemVID[playerid]-1][VItem12param6]);
						if(slotin == 0)
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz przenosiæ wiêcej przedmiotów !");
							return 1;
						}
					}
					else if (gDSelectedVItemSlot[playerid] == 13)
					{
						slotin = InsertPlayerItemEx(playerid, 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem13type], 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem13], 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem13param], 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem13param2], 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem13param3],
						gVehData[gDSelectedVItemVID[playerid]-1][VItem13param4],
						gVehData[gDSelectedVItemVID[playerid]-1][VItem13param5],
						gVehData[gDSelectedVItemVID[playerid]-1][VItem13param6]);
						if(slotin == 0)
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz przenosiæ wiêcej przedmiotów !");
							return 1;
						}
					}
					else if (gDSelectedVItemSlot[playerid] == 14)
					{
						slotin = InsertPlayerItemEx(playerid, 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem14type], 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem14], 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem14param], 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem14param2], 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem14param3],
						gVehData[gDSelectedVItemVID[playerid]-1][VItem14param4],
						gVehData[gDSelectedVItemVID[playerid]-1][VItem14param5],
						gVehData[gDSelectedVItemVID[playerid]-1][VItem14param6]);
						if(slotin == 0)
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz przenosiæ wiêcej przedmiotów !");
							return 1;
						}
					}
					else if (gDSelectedVItemSlot[playerid] == 15)
					{
						slotin = InsertPlayerItemEx(playerid, 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem15type], 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem15], 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem15param], 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem15param2], 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem15param3],
						gVehData[gDSelectedVItemVID[playerid]-1][VItem15param4],
						gVehData[gDSelectedVItemVID[playerid]-1][VItem15param5],
						gVehData[gDSelectedVItemVID[playerid]-1][VItem15param6]);
						if(slotin == 0)
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz przenosiæ wiêcej przedmiotów !");
							return 1;
						}
					}
					RemoveVehItemEx(gDSelectedVItemVID[playerid],gDSelectedVItemSlot[playerid]);
					format(string, sizeof(string), "[INFO:] Zabra³eœ item ze schowka (ze slotu %d)", gDSelectedVItemSlot[playerid]);
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
					PlayerActionMessage(playerid, 15.0, "zabiera przedmiot ze schowka");
					return 1;
				}
				else // wyrzuc item
				{
					if(VSlotItemTypeCompare(gDSelectedVItemVID[playerid], gDSelectedVItemSlot[playerid], 1) && VSlotParam6(gDSelectedVItemVID[playerid], gDSelectedVItemSlot[playerid]) > 1)
					{
						ShowPlayerDialog(playerid,DIALOG_VITEM_3,DIALOG_STYLE_INPUT,"Wpisz iloœæ","Wpisz ile itemów danego typu chcesz wyrzuciæ","Wyrzuæ","Anuluj");
						return 1;
					}
					RemoveVehItemEx(gDSelectedVItemVID[playerid], gDSelectedVItemSlot[playerid]);
					format(string, sizeof(string), "[INFO:] Wyrzuci³eœ item z domu (ze slotu %d)", gDSelectedVItemSlot[playerid]);
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
					PlayerActionMessage(playerid, 15.0, "wyrzuca przedmiot ze schowka");
					return 1;
				}
			}
			else
			{
				// TODO: need some function to show list again - /miwp
				goto selectVItem;
			}
		}
		case DIALOG_VITEM_3:
		{
			if(response)
			{
				new howMuch = strval(inputtext);
				if(VSlotParam6(gDSelectedVItemVID[playerid], gDSelectedVItemSlot[playerid]) <= 0)
				{
					RemoveVehItemEx(gDSelectedVItemVID[playerid], gDSelectedVItemSlot[playerid]);
					format(string, sizeof(string), "[INFO:] Wyrzuci³eœ item ze slotu %d", gDSelectedVItemSlot[playerid]);
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2,string);
					return 1;
				}
				if(howMuch > VSlotParam6(gDSelectedVItemVID[playerid], gDSelectedVItemSlot[playerid]))
				{
					ShowPlayerDialog(playerid,DIALOG_VITEM_3,DIALOG_STYLE_INPUT,"Wpisz iloœæ","Nie posiadasz tyle przedmiotów danego typu !\nWpisz now¹ wartoœæ","Wyrzuæ","Anuluj");
					return 1;
				}
				else if(howMuch == 0)
				{
					ShowPlayerDialog(playerid,DIALOG_VITEM_3,DIALOG_STYLE_INPUT,"Wpisz iloœæ","Poda³eœ b³êdn¹ wartoœæ\nWpisz now¹","Wyrzuæ","Anuluj");
					return 1;
				}
				RemoveVehItemEx(gDSelectedVItemVID[playerid], gDSelectedVItemSlot[playerid], howMuch);
				format(string, sizeof(string), "[INFO:] Wyrzuci³eœ %d itemów", howMuch);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			}
			else
				goto selectVItem;
			return 1;
		}
		case DIALOG_VITEM_4:
		{
			if(response)
			{
				if( strval(inputtext) <= 0 || strval(inputtext) > VSlotParam6(gDSelectedVItemVID[playerid], gDSelectedVItemSlot[playerid]) )
				{
					ShowPlayerDialog(playerid,DIALOG_VITEM_4,DIALOG_STYLE_INPUT,"Wpisz iloœæ", "Poda³eœ nieprawid³ow¹ wartoœæ !\nWpisz wartoœæ ponownie","Akceptuj","Wróæ");
					return 1;
				}
				new howMuch = strval(inputtext);
				new slotin;
				if (gDSelectedVItemSlot[playerid] == 1)
				{
					if(PlayerCountMaxItemCarry(playerid, gVehData[gDSelectedVItemVID[playerid]-1][VItem1type], gVehData[gDSelectedVItemVID[playerid]-1][VItem1]) < howMuch)
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie uniesiesz tylu itemów !");
						format(string, sizeof(string), "[INFO:] Mo¿esz przenieœæ tylko %d tych itemów", PlayerCountMaxItemCarry(playerid, gVehData[gDSelectedVItemVID[playerid]-1][VItem1type], gVehData[gDSelectedVItemVID[playerid]-1][VItem1]));
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
						return 1;
					}
					slotin = InsertPlayerItemEx(playerid, 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem1type],
						gVehData[gDSelectedVItemVID[playerid]-1][VItem1], 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem1param], 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem1param2], 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem1param3],
						gVehData[gDSelectedVItemVID[playerid]-1][VItem1param4],
						gVehData[gDSelectedVItemVID[playerid]-1][VItem1param5],
						howMuch);
					if(slotin == 0)
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz przenosiæ wiêcej przedmiotów !");
						return 1;
					}
				}
				else if (gDSelectedVItemSlot[playerid] == 2)
				{
					if(PlayerCountMaxItemCarry(playerid, gVehData[gDSelectedVItemVID[playerid]-1][VItem2type], gVehData[gDSelectedVItemVID[playerid]-1][VItem2]) < howMuch)
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie uniesiesz tylu itemów !");
						format(string, sizeof(string), "[INFO:] Mo¿esz przenieœæ tylko %d tych itemów", PlayerCountMaxItemCarry(playerid, gVehData[gDSelectedVItemVID[playerid]-1][VItem2type], gVehData[gDSelectedVItemVID[playerid]-1][VItem2]));
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
						return 1;
					}
					slotin = InsertPlayerItemEx(playerid,
						gVehData[gDSelectedVItemVID[playerid]-1][VItem2type], 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem2], 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem2param], 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem2param2], 
						gVehData[gDSelectedVItemVID[playerid]-1][VItem2param3],
						gVehData[gDSelectedVItemVID[playerid]-1][VItem2param4],
						gVehData[gDSelectedVItemVID[playerid]-1][VItem2param5],
						howMuch);
					if(slotin == 0)
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz przenosiæ wiêcej przedmiotów !");
						return 1;
					}
				}
				else if (gDSelectedVItemSlot[playerid] == 3)
				{
					if(PlayerCountMaxItemCarry(playerid, gVehData[gDSelectedVItemVID[playerid]-1][VItem3type], gVehData[gDSelectedVItemVID[playerid]-1][VItem3]) < howMuch)
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie uniesiesz tylu itemów !");
						format(string, sizeof(string), "[INFO:] Mo¿esz przenieœæ tylko %d tych itemów", PlayerCountMaxItemCarry(playerid, gVehData[gDSelectedVItemVID[playerid]-1][VItem3type], gVehData[gDSelectedVItemVID[playerid]-1][VItem3]));
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
						return 1;
					}
					slotin = InsertPlayerItemEx(playerid, 
					gVehData[gDSelectedVItemVID[playerid]-1][VItem3type], 
					gVehData[gDSelectedVItemVID[playerid]-1][VItem3], 
					gVehData[gDSelectedVItemVID[playerid]-1][VItem3param], 
					gVehData[gDSelectedVItemVID[playerid]-1][VItem3param2], 
					gVehData[gDSelectedVItemVID[playerid]-1][VItem3param3],
					gVehData[gDSelectedVItemVID[playerid]-1][VItem3param4],
					gVehData[gDSelectedVItemVID[playerid]-1][VItem3param5],
					howMuch);
					if(slotin == 0)
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz przenosiæ wiêcej przedmiotów !");
						return 1;
					}
				}
				else if (gDSelectedVItemSlot[playerid] == 4)
				{
					if(PlayerCountMaxItemCarry(playerid, gVehData[gDSelectedVItemVID[playerid]-1][VItem4type], gVehData[gDSelectedVItemVID[playerid]-1][VItem4]) < howMuch)
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie uniesiesz tylu itemów !");
						format(string, sizeof(string), "[INFO:] Mo¿esz przenieœæ tylko %d tych itemów", PlayerCountMaxItemCarry(playerid, gVehData[gDSelectedVItemVID[playerid]-1][VItem4type], gVehData[gDSelectedVItemVID[playerid]-1][VItem4]));
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
						return 1;
					}
					slotin = InsertPlayerItemEx(playerid, 
					gVehData[gDSelectedVItemVID[playerid]-1][VItem4type], 
					gVehData[gDSelectedVItemVID[playerid]-1][VItem4], 
					gVehData[gDSelectedVItemVID[playerid]-1][VItem4param], 
					gVehData[gDSelectedVItemVID[playerid]-1][VItem4param2], 
					gVehData[gDSelectedVItemVID[playerid]-1][VItem4param3],
					gVehData[gDSelectedVItemVID[playerid]-1][VItem4param4],
					gVehData[gDSelectedVItemVID[playerid]-1][VItem4param5],
					howMuch);
					if(slotin == 0)
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz przenosiæ wiêcej przedmiotów !");
						return 1;
					}
				}
				else if (gDSelectedVItemSlot[playerid] == 5)
				{
					if(PlayerCountMaxItemCarry(playerid, gVehData[gDSelectedVItemVID[playerid]-1][VItem5type], gVehData[gDSelectedVItemVID[playerid]-1][VItem5]) < howMuch)
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie uniesiesz tylu itemów !");
						format(string, sizeof(string), "[INFO:] Mo¿esz przenieœæ tylko %d tych itemów", PlayerCountMaxItemCarry(playerid, gVehData[gDSelectedVItemVID[playerid]-1][VItem5type], gVehData[gDSelectedVItemVID[playerid]-1][VItem5]));
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
						return 1;
					}
					slotin = InsertPlayerItemEx(playerid, 
					gVehData[gDSelectedVItemVID[playerid]-1][VItem5type], 
					gVehData[gDSelectedVItemVID[playerid]-1][VItem5], 
					gVehData[gDSelectedVItemVID[playerid]-1][VItem5param], 
					gVehData[gDSelectedVItemVID[playerid]-1][VItem5param2], 
					gVehData[gDSelectedVItemVID[playerid]-1][VItem5param3],
					gVehData[gDSelectedVItemVID[playerid]-1][VItem5param4],
					gVehData[gDSelectedVItemVID[playerid]-1][VItem5param5],
					howMuch);
					if(slotin == 0)
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz przenosiæ wiêcej przedmiotów !");
						return 1;
					}
				}
				else if (gDSelectedVItemSlot[playerid] == 6)
				{
					if(PlayerCountMaxItemCarry(playerid, gVehData[gDSelectedVItemVID[playerid]-1][VItem6type], gVehData[gDSelectedVItemVID[playerid]-1][VItem6]) < howMuch)
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie uniesiesz tylu itemów !");
						format(string, sizeof(string), "[INFO:] Mo¿esz przenieœæ tylko %d tych itemów", PlayerCountMaxItemCarry(playerid, gVehData[gDSelectedVItemVID[playerid]-1][VItem6type], gVehData[gDSelectedVItemVID[playerid]-1][VItem6]));
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
						return 1;
					}
					slotin = InsertPlayerItemEx(playerid, 
					gVehData[gDSelectedVItemVID[playerid]-1][VItem6type], 
					gVehData[gDSelectedVItemVID[playerid]-1][VItem6], 
					gVehData[gDSelectedVItemVID[playerid]-1][VItem6param], 
					gVehData[gDSelectedVItemVID[playerid]-1][VItem6param2], 
					gVehData[gDSelectedVItemVID[playerid]-1][VItem6param3],
					gVehData[gDSelectedVItemVID[playerid]-1][VItem6param4],
					gVehData[gDSelectedVItemVID[playerid]-1][VItem6param5],
					howMuch);
					if(slotin == 0)
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz przenosiæ wiêcej przedmiotów !");
						return 1;
					}
				}
				else if (gDSelectedVItemSlot[playerid] == 7)
				{
					if(PlayerCountMaxItemCarry(playerid, gVehData[gDSelectedVItemVID[playerid]-1][VItem7type], gVehData[gDSelectedVItemVID[playerid]-1][VItem7]) < howMuch)
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie uniesiesz tylu itemów !");
						format(string, sizeof(string), "[INFO:] Mo¿esz przenieœæ tylko %d tych itemów", PlayerCountMaxItemCarry(playerid, gVehData[gDSelectedVItemVID[playerid]-1][VItem7type], gVehData[gDSelectedVItemVID[playerid]-1][VItem7]));
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
						return 1;
					}
					slotin = InsertPlayerItemEx(playerid, 
					gVehData[gDSelectedVItemVID[playerid]-1][VItem7type], 
					gVehData[gDSelectedVItemVID[playerid]-1][VItem7], 
					gVehData[gDSelectedVItemVID[playerid]-1][VItem7param], 
					gVehData[gDSelectedVItemVID[playerid]-1][VItem7param2], 
					gVehData[gDSelectedVItemVID[playerid]-1][VItem7param3],
					gVehData[gDSelectedVItemVID[playerid]-1][VItem7param4],
					gVehData[gDSelectedVItemVID[playerid]-1][VItem7param5],
					howMuch);
					if(slotin == 0)
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz przenosiæ wiêcej przedmiotów !");
						return 1;
					}
				}
				else if (gDSelectedVItemSlot[playerid] == 8)
				{
					if(PlayerCountMaxItemCarry(playerid, gVehData[gDSelectedVItemVID[playerid]-1][VItem8type], gVehData[gDSelectedVItemVID[playerid]-1][VItem8]) < howMuch)
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie uniesiesz tylu itemów !");
						format(string, sizeof(string), "[INFO:] Mo¿esz przenieœæ tylko %d tych itemów", PlayerCountMaxItemCarry(playerid, gVehData[gDSelectedVItemVID[playerid]-1][VItem8type], gVehData[gDSelectedVItemVID[playerid]-1][VItem8]));
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
						return 1;
					}
					slotin = InsertPlayerItemEx(playerid, 
					gVehData[gDSelectedVItemVID[playerid]-1][VItem8type], 
					gVehData[gDSelectedVItemVID[playerid]-1][VItem8], 
					gVehData[gDSelectedVItemVID[playerid]-1][VItem8param], 
					gVehData[gDSelectedVItemVID[playerid]-1][VItem8param2], 
					gVehData[gDSelectedVItemVID[playerid]-1][VItem8param3],
					gVehData[gDSelectedVItemVID[playerid]-1][VItem8param4],
					gVehData[gDSelectedVItemVID[playerid]-1][VItem8param5],
					howMuch);
					if(slotin == 0)
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz przenosiæ wiêcej przedmiotów !");
						return 1;
					}
				}
				else if (gDSelectedVItemSlot[playerid] == 9)
				{
					if(PlayerCountMaxItemCarry(playerid, gVehData[gDSelectedVItemVID[playerid]-1][VItem9type], gVehData[gDSelectedVItemVID[playerid]-1][VItem9]) < howMuch)
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie uniesiesz tylu itemów !");
						format(string, sizeof(string), "[INFO:] Mo¿esz przenieœæ tylko %d tych itemów", PlayerCountMaxItemCarry(playerid, gVehData[gDSelectedVItemVID[playerid]-1][VItem9type], gVehData[gDSelectedVItemVID[playerid]-1][VItem9]));
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
						return 1;
					}
					slotin = InsertPlayerItemEx(playerid, 
					gVehData[gDSelectedVItemVID[playerid]-1][VItem9type], 
					gVehData[gDSelectedVItemVID[playerid]-1][VItem9], 
					gVehData[gDSelectedVItemVID[playerid]-1][VItem9param], 
					gVehData[gDSelectedVItemVID[playerid]-1][VItem9param2], 
					gVehData[gDSelectedVItemVID[playerid]-1][VItem9param3],
					gVehData[gDSelectedVItemVID[playerid]-1][VItem9param4],
					gVehData[gDSelectedVItemVID[playerid]-1][VItem9param5],
					howMuch);
					if(slotin == 0)
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz przenosiæ wiêcej przedmiotów !");
						return 1;
					}
				}
				else if (gDSelectedVItemSlot[playerid] == 10)
				{
					if(PlayerCountMaxItemCarry(playerid, gVehData[gDSelectedVItemVID[playerid]-1][VItem10type], gVehData[gDSelectedVItemVID[playerid]-1][VItem10]) < howMuch)
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie uniesiesz tylu itemów !");
						format(string, sizeof(string), "[INFO:] Mo¿esz przenieœæ tylko %d tych itemów", PlayerCountMaxItemCarry(playerid, gVehData[gDSelectedVItemVID[playerid]-1][VItem10type], gVehData[gDSelectedVItemVID[playerid]-1][VItem10]));
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
						return 1;
					}
					slotin = InsertPlayerItemEx(playerid, 
					gVehData[gDSelectedVItemVID[playerid]-1][VItem10type], 
					gVehData[gDSelectedVItemVID[playerid]-1][VItem10], 
					gVehData[gDSelectedVItemVID[playerid]-1][VItem10param], 
					gVehData[gDSelectedVItemVID[playerid]-1][VItem10param2], 
					gVehData[gDSelectedVItemVID[playerid]-1][VItem10param3],
					gVehData[gDSelectedVItemVID[playerid]-1][VItem10param4],
					gVehData[gDSelectedVItemVID[playerid]-1][VItem10param5],
					howMuch);
					if(slotin == 0)
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz przenosiæ wiêcej przedmiotów !");
						return 1;
					}
				}
				else if (gDSelectedVItemSlot[playerid] == 11)
				{
					if(PlayerCountMaxItemCarry(playerid, gVehData[gDSelectedVItemVID[playerid]-1][VItem11type], gVehData[gDSelectedVItemVID[playerid]-1][VItem11]) < howMuch)
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie uniesiesz tylu itemów !");
						format(string, sizeof(string), "[INFO:] Mo¿esz przenieœæ tylko %d tych itemów", PlayerCountMaxItemCarry(playerid, gVehData[gDSelectedVItemVID[playerid]-1][VItem11type], gVehData[gDSelectedVItemVID[playerid]-1][VItem11]));
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
						return 1;
					}
					slotin = InsertPlayerItemEx(playerid, 
					gVehData[gDSelectedVItemVID[playerid]-1][VItem11type], 
					gVehData[gDSelectedVItemVID[playerid]-1][VItem11], 
					gVehData[gDSelectedVItemVID[playerid]-1][VItem11param], 
					gVehData[gDSelectedVItemVID[playerid]-1][VItem11param2], 
					gVehData[gDSelectedVItemVID[playerid]-1][VItem11param3],
					gVehData[gDSelectedVItemVID[playerid]-1][VItem11param4],
					gVehData[gDSelectedVItemVID[playerid]-1][VItem11param5],
					howMuch);
					if(slotin == 0)
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz przenosiæ wiêcej przedmiotów !");
						return 1;
					}
				}
				else if (gDSelectedVItemSlot[playerid] == 12)
				{
					if(PlayerCountMaxItemCarry(playerid, gVehData[gDSelectedVItemVID[playerid]-1][VItem12type], gVehData[gDSelectedVItemVID[playerid]-1][VItem12]) < howMuch)
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie uniesiesz tylu itemów !");
						format(string, sizeof(string), "[INFO:] Mo¿esz przenieœæ tylko %d tych itemów", PlayerCountMaxItemCarry(playerid, gVehData[gDSelectedVItemVID[playerid]-1][VItem12type], gVehData[gDSelectedVItemVID[playerid]-1][VItem12]));
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
						return 1;
					}
					slotin = InsertPlayerItemEx(playerid, 
					gVehData[gDSelectedVItemVID[playerid]-1][VItem12type], 
					gVehData[gDSelectedVItemVID[playerid]-1][VItem12], 
					gVehData[gDSelectedVItemVID[playerid]-1][VItem12param], 
					gVehData[gDSelectedVItemVID[playerid]-1][VItem12param2], 
					gVehData[gDSelectedVItemVID[playerid]-1][VItem12param3],
					gVehData[gDSelectedVItemVID[playerid]-1][VItem12param4],
					gVehData[gDSelectedVItemVID[playerid]-1][VItem12param5],
					howMuch);
					if(slotin == 0)
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz przenosiæ wiêcej przedmiotów !");
						return 1;
					}
				}
				else if (gDSelectedVItemSlot[playerid] == 13)
				{
					if(PlayerCountMaxItemCarry(playerid, gVehData[gDSelectedVItemVID[playerid]-1][VItem13type], gVehData[gDSelectedVItemVID[playerid]-1][VItem13]) < howMuch)
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie uniesiesz tylu itemów !");
						format(string, sizeof(string), "[INFO:] Mo¿esz przenieœæ tylko %d tych itemów", PlayerCountMaxItemCarry(playerid, gVehData[gDSelectedVItemVID[playerid]-1][VItem13type], gVehData[gDSelectedVItemVID[playerid]-1][VItem13]));
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
						return 1;
					}
					slotin = InsertPlayerItemEx(playerid, 
					gVehData[gDSelectedVItemVID[playerid]-1][VItem13type], 
					gVehData[gDSelectedVItemVID[playerid]-1][VItem13], 
					gVehData[gDSelectedVItemVID[playerid]-1][VItem13param], 
					gVehData[gDSelectedVItemVID[playerid]-1][VItem13param2], 
					gVehData[gDSelectedVItemVID[playerid]-1][VItem13param3],
					gVehData[gDSelectedVItemVID[playerid]-1][VItem13param4],
					gVehData[gDSelectedVItemVID[playerid]-1][VItem13param5],
					howMuch);
					if(slotin == 0)
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz przenosiæ wiêcej przedmiotów !");
						return 1;
					}
				}
				else if (gDSelectedVItemSlot[playerid] == 14)
				{
					if(PlayerCountMaxItemCarry(playerid, gVehData[gDSelectedVItemVID[playerid]-1][VItem14type], gVehData[gDSelectedVItemVID[playerid]-1][VItem14]) < howMuch)
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie uniesiesz tylu itemów !");
						format(string, sizeof(string), "[INFO:] Mo¿esz przenieœæ tylko %d tych itemów", PlayerCountMaxItemCarry(playerid, gVehData[gDSelectedVItemVID[playerid]-1][VItem14type], gVehData[gDSelectedVItemVID[playerid]-1][VItem14]));
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
						return 1;
					}
					slotin = InsertPlayerItemEx(playerid, 
					gVehData[gDSelectedVItemVID[playerid]-1][VItem14type], 
					gVehData[gDSelectedVItemVID[playerid]-1][VItem14], 
					gVehData[gDSelectedVItemVID[playerid]-1][VItem14param], 
					gVehData[gDSelectedVItemVID[playerid]-1][VItem14param2], 
					gVehData[gDSelectedVItemVID[playerid]-1][VItem14param3],
					gVehData[gDSelectedVItemVID[playerid]-1][VItem14param4],
					gVehData[gDSelectedVItemVID[playerid]-1][VItem14param5],
					howMuch);
					if(slotin == 0)
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz przenosiæ wiêcej przedmiotów !");
						return 1;
					}
				}
				else if (gDSelectedVItemSlot[playerid] == 15)
				{
					if(PlayerCountMaxItemCarry(playerid, gVehData[gDSelectedVItemVID[playerid]-1][VItem15type], gVehData[gDSelectedVItemVID[playerid]-1][VItem15]) < howMuch)
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie uniesiesz tylu itemów !");
						format(string, sizeof(string), "[INFO:] Mo¿esz przenieœæ tylko %d tych itemów", PlayerCountMaxItemCarry(playerid, gVehData[gDSelectedVItemVID[playerid]-1][VItem15type], gVehData[gDSelectedVItemVID[playerid]-1][VItem15]));
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
						return 1;
					}
					slotin = InsertPlayerItemEx(playerid, 
					gVehData[gDSelectedVItemVID[playerid]-1][VItem15type], 
					gVehData[gDSelectedVItemVID[playerid]-1][VItem15], 
					gVehData[gDSelectedVItemVID[playerid]-1][VItem15param], 
					gVehData[gDSelectedVItemVID[playerid]-1][VItem15param2], 
					gVehData[gDSelectedVItemVID[playerid]-1][VItem15param3],
					gVehData[gDSelectedVItemVID[playerid]-1][VItem15param4],
					gVehData[gDSelectedVItemVID[playerid]-1][VItem15param5],
					howMuch);
					if(slotin == 0)
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz przenosiæ wiêcej przedmiotów !");
						return 1;
					}
				}
				RemoveVehItemEx(gDSelectedVItemVID[playerid], gDSelectedVItemSlot[playerid], howMuch);
				format(string, sizeof(string), "[INFO:] Zabra³eœ item ze schowka (ze slotu %d)", gDSelectedVItemSlot[playerid]);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
				PlayerActionMessage(playerid, 15.0, "zabiera przedmiot ze schowka");
				return 1;
			}
			else
			{
				goto selectVItem;
				return 1;
			}
		}
		case DIALOG_HITEM_INS_1:
		{
			if(response)
			{
				gSelectedSlot[playerid] = listitem+1;
				SlotParam5(playerid, gSelectedSlot[playerid]);
				if(PSlotItemTypeCompare(playerid, gSelectedSlot[playerid], 1))
				{
					ShowPlayerDialog(playerid,DIALOG_HITEM_INS_2,DIALOG_STYLE_INPUT,"Wpisz iloœæ","Wpisz ile itemów danego typu chcesz schowaæ","Schowaj","Wróæ");
					return 1;
				}
				if(InsertHouseItem(gDSelectedHItemHouse[playerid], PSlotItemType(playerid, gSelectedSlot[playerid]), ShowSlotItem(playerid, gSelectedSlot[playerid]), SlotParam1(playerid, gSelectedSlot[playerid]), SlotParam2(playerid, gSelectedSlot[playerid]), SlotParam3(playerid, gSelectedSlot[playerid]), SlotParam4(playerid, gSelectedSlot[playerid]), gDSelectedItemP5[playerid], 1) == 0)
				{
					SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie masz ju¿ miejsca w schowku !");
					return 1;
				}
				if(PSlotItemTypeCompare(playerid,  gSelectedSlot[playerid], 3) && SlotItem(playerid, gSelectedSlot[playerid], 7) ||  SlotItem(playerid, gSelectedSlot[playerid], 9))
				{
					if(gGlassesWearingModel[playerid] == SlotParam1(playerid, gSelectedSlot[playerid]))
					{
						gGlassesWearingModel[playerid] = 0;
						StopPlayerHoldingObject(playerid);
					}
					if(gHatWearingModel[playerid] == SlotParam1(playerid, gSelectedSlot[playerid]))
					{
						RemovePlayerAttachedObject(playerid, MAX_PLAYER_ATTACHED_OBJECTS-2);
						gHatWearingModel[playerid] = 255;
					}
				}
				RemovePlayerItemExUsed(playerid, gSelectedSlot[playerid]);

				format(string, sizeof(string), "[INFO:] Schowa³eœ item do schowka ze slotu %d", gSelectedSlot[playerid]);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);

				PlayerActionMessage(playerid, 15.0, "wyjmuje przedmiot i wk³ada go do schowka");

				return 1;
			}
		}
		case DIALOG_HITEM_INS_2:
		{
			if(response)
			{
				new howMuch = strval(inputtext);
				new hSlot = HHaveItem(gDSelectedHItemHouse[playerid], PSlotItemType(playerid, gSelectedSlot[playerid]), ShowSlotItem(playerid, gSelectedSlot[playerid]));
				if(SlotParam6(playerid, gSelectedSlot[playerid]) <= 0)
				{
					if(hSlot > 0)
					{
						SetHSlotParam6(gDSelectedHItemHouse[playerid], hSlot, HSlotParam6(gDSelectedHItemHouse[playerid], hSlot) + 1);
					}
					else
					{
						if(InsertHouseItem(gDSelectedHItemHouse[playerid], PSlotItemType(playerid, gSelectedSlot[playerid]), ShowSlotItem(playerid, gSelectedSlot[playerid]), SlotParam1(playerid, gSelectedSlot[playerid]), SlotParam2(playerid, gSelectedSlot[playerid]), SlotParam3(playerid, gSelectedSlot[playerid]), SlotParam4(playerid, gSelectedSlot[playerid]), gDSelectedItemP5[playerid], 1 ) == 0)
						{
							SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie masz ju¿ miejsca w schowku !");
							return 1;
						}
					}
					RemovePlayerItemExUsed(playerid, gSelectedSlot[playerid]);
					format(string, sizeof(string), "[INFO:] Schowa³eœ do schowka item ze slotu %d", gSelectedSlot[playerid]);
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2,string);
					return 1;
				}
				if(howMuch > SlotParam6(playerid, gSelectedSlot[playerid]))
				{
					ShowPlayerDialog(playerid,DIALOG_HITEM_INS_2,DIALOG_STYLE_INPUT,"Wpisz iloœæ","Nie posiadasz tyle przedmiotów danego typu !\nWpisz now¹ wartoœæ","Wyrzuæ","Anuluj");
					return 1;
				}
				if(howMuch == 0)
				{
					ShowPlayerDialog(playerid,DIALOG_HITEM_INS_2,DIALOG_STYLE_INPUT,"Wpisz iloœæ","Poda³eœ b³êdn¹ wartoœæ\nWpisz now¹","Wyrzuæ","Anuluj");
					return 1;
				}
				if(SlotParam6(playerid, gSelectedSlot[playerid])-howMuch == 0)
				{
					if(hSlot > 0)
						SetHSlotParam6(gDSelectedHItemHouse[playerid], hSlot, HSlotParam6(gDSelectedHItemHouse[playerid], hSlot) + howMuch);
					else
					{
						if(InsertHouseItem(gDSelectedHItemHouse[playerid], PSlotItemType(playerid, gSelectedSlot[playerid]), ShowSlotItem(playerid, gSelectedSlot[playerid]), SlotParam1(playerid, gSelectedSlot[playerid]), SlotParam2(playerid, gSelectedSlot[playerid]), SlotParam3(playerid, gSelectedSlot[playerid]), SlotParam4(playerid, gSelectedSlot[playerid]), gDSelectedItemP5[playerid], SlotParam6(playerid, gSelectedSlot[playerid]) ) == 0)
						{
							SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie masz ju¿ miejsca w schowku !");
							return 1;
						}
					}
					RemovePlayerItemExUsed(playerid, gSelectedSlot[playerid], howMuch);
				}
				else
				{
					if(hSlot > 0)
						SetHSlotParam6(gDSelectedHItemHouse[playerid], hSlot, HSlotParam6(gDSelectedHItemHouse[playerid], hSlot) + howMuch);
					else
					{
						if(InsertHouseItem(gDSelectedHItemHouse[playerid], PSlotItemType(playerid, gSelectedSlot[playerid]), ShowSlotItem(playerid, gSelectedSlot[playerid]), SlotParam1(playerid, gSelectedSlot[playerid]), SlotParam2(playerid, gSelectedSlot[playerid]), SlotParam3(playerid, gSelectedSlot[playerid]), SlotParam4(playerid, gSelectedSlot[playerid]), gDSelectedItemP5[playerid], howMuch) == 0)
						{
							SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie masz ju¿ miejsca w schowku !");
							return 1;
						}
					}
					SetPSlotParam6(playerid, gSelectedSlot[playerid], SlotParam6(playerid, gSelectedSlot[playerid])-howMuch);
				}
				format(string, sizeof(string), "[INFO:] Schowa³eœ do schowka %d itemów ze slotu %d", howMuch, gSelectedSlot[playerid]);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
				return 1;
			}
		}
		case DIALOG_VITEM_INS_1:
		{
			if(response)
			{
				gSelectedSlot[playerid] = listitem+1;
				SlotParam5(playerid, gSelectedSlot[playerid]);
				if(PSlotItemTypeCompare(playerid, gSelectedSlot[playerid], 1))
				{
					ShowPlayerDialog(playerid,DIALOG_VITEM_INS_2,DIALOG_STYLE_INPUT,"Wpisz iloœæ","Wpisz ile itemów danego typu chcesz schowaæ","Schowaj","Wróæ");
					return 1;
				}
				if(InsertVehItem(gDSelectedVItemVID[playerid], PSlotItemType(playerid, gSelectedSlot[playerid]), ShowSlotItem(playerid, gSelectedSlot[playerid]), SlotParam1(playerid, gSelectedSlot[playerid]), SlotParam2(playerid, gSelectedSlot[playerid]), SlotParam3(playerid, gSelectedSlot[playerid]), SlotParam4(playerid, gSelectedSlot[playerid]), gDSelectedItemP5[playerid], 1) == 0)
				{
					SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie masz ju¿ miejsca w schowku !");
					return 1;
				}
				if(PSlotItemTypeCompare(playerid,  gSelectedSlot[playerid], 3) && SlotItem(playerid, gSelectedSlot[playerid], 7) ||  SlotItem(playerid, gSelectedSlot[playerid], 9))
				{
					if(gGlassesWearingModel[playerid] == SlotParam1(playerid, gSelectedSlot[playerid]))
					{
						gGlassesWearingModel[playerid] = 0;
						StopPlayerHoldingObject(playerid);
					}
					if(gHatWearingModel[playerid] == SlotParam1(playerid, gSelectedSlot[playerid]))
					{
						RemovePlayerAttachedObject(playerid, MAX_PLAYER_ATTACHED_OBJECTS-2);
						gHatWearingModel[playerid] = 255;
					}
				}
				RemovePlayerItemExUsed(playerid, gSelectedSlot[playerid]);

				format(string, sizeof(string), "[INFO:] Schowa³eœ item do schowka ze slotu %d", gSelectedSlot[playerid]);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);

				PlayerActionMessage(playerid, 15.0, "wyjmuje przedmiot i wk³ada go do schowka");

				return 1;
			}
		}
		case DIALOG_VITEM_INS_2:
		{
			if(response)
			{
				new howMuch = strval(inputtext);
				if(SlotParam6(playerid, gSelectedSlot[playerid]) <= 0)
				{
					if(InsertVehItem(gDSelectedVItemVID[playerid], PSlotItemType(playerid, gSelectedSlot[playerid]), ShowSlotItem(playerid, gSelectedSlot[playerid]), SlotParam1(playerid, gSelectedSlot[playerid]), SlotParam2(playerid, gSelectedSlot[playerid]), SlotParam3(playerid, gSelectedSlot[playerid]), SlotParam4(playerid, gSelectedSlot[playerid]), gDSelectedItemP5[playerid], 1 ) == 0)
					{
						SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie masz ju¿ miejsca w schowku !");
						return 1;
					}
					RemovePlayerItemExUsed(playerid, gSelectedSlot[playerid]);
					format(string, sizeof(string), "[INFO:] Schowa³eœ do schowka item ze slotu %d", gSelectedSlot[playerid]);
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2,string);
					return 1;
				}
				if(howMuch > SlotParam6(playerid, gSelectedSlot[playerid]))
				{
					ShowPlayerDialog(playerid,DIALOG_VITEM_INS_2,DIALOG_STYLE_INPUT,"Wpisz iloœæ","Nie posiadasz tyle przedmiotów danego typu !\nWpisz now¹ wartoœæ","Wyrzuæ","Anuluj");
					return 1;
				}
				if(howMuch == 0)
				{
					ShowPlayerDialog(playerid,DIALOG_VITEM_INS_2,DIALOG_STYLE_INPUT,"Wpisz iloœæ","Poda³eœ b³êdn¹ wartoœæ\nWpisz now¹","Wyrzuæ","Anuluj");
					return 1;
				}
				if(InsertVehItem(gDSelectedVItemVID[playerid], PSlotItemType(playerid, gSelectedSlot[playerid]), ShowSlotItem(playerid, gSelectedSlot[playerid]), SlotParam1(playerid, gSelectedSlot[playerid]), SlotParam2(playerid, gSelectedSlot[playerid]), SlotParam3(playerid, gSelectedSlot[playerid]), SlotParam4(playerid, gSelectedSlot[playerid]), gDSelectedItemP5[playerid], SlotParam6(playerid, gSelectedSlot[playerid]) ) == 0)
				{
					SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie masz ju¿ miejsca w schowku !");
					return 1;
				}
				format(string, sizeof(string), "[INFO:] Schowa³eœ do schowka %d itemów ze slotu %d", howMuch, gSelectedSlot[playerid]);
				RemovePlayerItemExUsed(playerid, gSelectedSlot[playerid], howMuch);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
				return 1;
			}
		}
		case DIALOG_ITEM_1: // Items main menu
		{
			if(response)
			{
				/* 
				TRICKY: dont change it unless u know what are u doing...
				Whic page should be loaded ?
				*/
				gSelectedSlot[playerid] = listitem+1;
				if( gPreviousDialogList[playerid] != -1 )
					gSelectedSlot[playerid] = gPreviousDialogList[playerid];
				else
					gPreviousDialogList[playerid] = gSelectedSlot[playerid];
					
				/* Luck Lottery Ticket */
				if(PSlotItemTypeCompare(playerid, gSelectedSlot[playerid], 3) && SlotItem(playerid, gSelectedSlot[playerid], 10))
					ShowPlayerDialog(playerid,DIALOG_ITEM_2,DIALOG_STYLE_LIST,"Dzia³anie","1. Przeka¿ item\n2. Wyrzuæ item\n3. Poka¿ skreœlone liczby\n4. Odbierz wygran¹","Akceptuj","Wróæ");
				/* Canister */
				else if(PSlotItemTypeCompare(playerid, gSelectedSlot[playerid], 3) && SlotItem(playerid, gSelectedSlot[playerid], 1))
					ShowPlayerDialog(playerid,DIALOG_ITEM_2,DIALOG_STYLE_LIST,"Dzia³anie","1. Przeka¿ item\n2. Wyrzuæ item\n3. Zatankuj pojazd\n4. Zawartoœæ\n5. Zatankuj kanister","Akceptuj","Wróæ");
				/* Phone */
				else if(PSlotItemTypeCompare(playerid, gSelectedSlot[playerid], 3) && (SlotItem(playerid, gSelectedSlot[playerid], 3) || SlotItem(playerid, gSelectedSlot[playerid], 4)))
					ShowPlayerDialog(playerid,DIALOG_ITEM_2,DIALOG_STYLE_LIST,"Dzia³anie","1. Przeka¿ item\n2. Wyrzuæ item\n3. Dzwon\n4. Mój numer\n5. Stan\n6. SMS\n7. Numery publiczne\n8. Ukryj numery\n9. On/off tel.","Akceptuj","Wróæ");
				/* Items type 3 */
				else if( ( PSlotItemTypeCompare(playerid, gSelectedSlot[playerid], 1) && (SlotItem(playerid, gSelectedSlot[playerid], 6) || SlotItem(playerid, gSelectedSlot[playerid], 8))) || (PSlotItemTypeCompare(playerid, gSelectedSlot[playerid], 2)))
					ShowPlayerDialog(playerid,DIALOG_ITEM_2,DIALOG_STYLE_LIST,"Dzia³anie","1. Przeka¿ item\n2. Wyrzuæ item\n3. U¿yj","Akceptuj","Wróæ");
				/* Weapons */
				else if( ( PSlotItemTypeCompare(playerid, gSelectedSlot[playerid], 1) && ShowSlotItem(playerid, gSelectedSlot[playerid]) >= 13 && ShowSlotItem(playerid, gSelectedSlot[playerid]) <= 32) ) 
					ShowPlayerDialog(playerid,DIALOG_ITEM_2,DIALOG_STYLE_LIST,"Dzia³anie","1. Przeka¿ item\n2. Wyrzuæ item\n3. WeŸ broñ","Akceptuj","Wróæ");
				/* House radio */
				else if( ( PSlotItemTypeCompare(playerid, gSelectedSlot[playerid], 1) && SlotItem(playerid, gSelectedSlot[playerid], 106) ) )
					ShowPlayerDialog(playerid,DIALOG_ITEM_2,DIALOG_STYLE_LIST,"Dzia³anie","1.Przeka¿ item\n2. Wyrzuæ item\n3. Ustaw radio","Akceptuj","Wróæ");
				/* Glasses */
				else if(PSlotItemTypeCompare(playerid, gSelectedSlot[playerid], 3) && SlotItem(playerid, gSelectedSlot[playerid], 7))
				{
					if(IsPlayerHoldingObject(playerid) && SlotParam1(playerid, gSelectedSlot[playerid]) == gGlassesWearingModel[playerid])
						ShowPlayerDialog(playerid,DIALOG_ITEM_2,DIALOG_STYLE_LIST,"Dzia³anie","1. Przeka¿ item\n2. Wyrzuæ item\n3. Zdejmij","Akceptuj","Wróæ");
					else
						ShowPlayerDialog(playerid,DIALOG_ITEM_2,DIALOG_STYLE_LIST,"Dzia³anie","1. Przeka¿ item\n2. Wyrzuæ item\n3. Za³ó¿","Akceptuj","Wróæ");
				}
				/* Hats */
				else if(PSlotItemTypeCompare(playerid, gSelectedSlot[playerid], 3) && SlotItem(playerid, gSelectedSlot[playerid], 9))
				{
					if(IsPlayerAttachedObjectSlotUsed(playerid, MAX_PLAYER_ATTACHED_OBJECTS-2) && SlotParam1(playerid, gSelectedSlot[playerid]) == gHatWearingModel[playerid])
						ShowPlayerDialog(playerid,DIALOG_ITEM_2,DIALOG_STYLE_LIST,"Dzia³anie","1. Przeka¿ item\n2. Wyrzuæ item\n3. Zdejmij","Akceptuj","Wróæ");
					else
						ShowPlayerDialog(playerid,DIALOG_ITEM_2,DIALOG_STYLE_LIST,"Dzia³anie","1. Przeka¿ item\n2. Wyrzuæ item\n3. Za³ó¿","Akceptuj","Wróæ");
				}
				else // pozostale itemy
					ShowPlayerDialog(playerid,DIALOG_ITEM_2,DIALOG_STYLE_LIST,"Dzia³anie","1. Przeka¿ item\n2. Wyrzuæ item","Akceptuj","Wróæ");
				return 1;
			}
		}
		case DIALOG_ITEM_2: // Items sub menu
		{
			if(response)
			{
				/* Item giving */
				if(listitem == 0)
				{
					if( PSlotItemType( playerid, gSelectedSlot[playerid] ) == 0 )
					{
						SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz przekazaæ pustego slotu !");
						return 1;
					}
					ShowPlayerDialog(playerid,DIALOG_ITEM_TRANSFER,DIALOG_STYLE_INPUT,"ID gracza","Wpisz ID gracza któremu chcesz przekazaæ item","Przeka¿","Wróæ");
					return 1;
				}
				/* Item drop */
				if(listitem == 1)
				{
					if(PSlotItemTypeCompare(playerid, gSelectedSlot[playerid], 1) && SlotParam6(playerid, gSelectedSlot[playerid]) > 1)
					{
						ShowPlayerDialog(playerid,DIALOG_ITEM_REMOVE,DIALOG_STYLE_INPUT,"Wpisz iloœæ","Wpisz ile itemów danego typu chcesz wyrzuciæ","Wyrzuæ","Wróæ");
						return 1;
					}
					if(PItemSlotStatus(playerid, gSelectedSlot[playerid]))
					{
						if(PSlotItemTypeCompare(playerid,  gSelectedSlot[playerid], 3) && SlotItem(playerid, gSelectedSlot[playerid], 7) ||  SlotItem(playerid, gSelectedSlot[playerid], 9))
						{
							if(gGlassesWearingModel[playerid] == SlotParam1(playerid, gSelectedSlot[playerid]))
							{
								gGlassesWearingModel[playerid] = 0;
								StopPlayerHoldingObject(playerid);
							}
							if(gHatWearingModel[playerid] == SlotParam1(playerid, gSelectedSlot[playerid]))
							{
								RemovePlayerAttachedObject(playerid, MAX_PLAYER_ATTACHED_OBJECTS-2);
								gHatWearingModel[playerid] = 255;
							}
						}
						RemovePlayerItemEx(playerid, gSelectedSlot[playerid]);

						format(string, sizeof(string), "[INFO:] Wyrzuci³eœ item ze slotu nr %d", gSelectedSlot[playerid]);
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
						PlayerActionMessage(playerid, 15.0, "wyjmuje przedmiot i rzuca go na ziemie");
						ShowPItems(playerid);
						return 1;
					}
					else
					{
						format(string, sizeof(string), "[INFO:] %d slot jest pusty !", gSelectedSlot[playerid]);
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
						ShowPItems(playerid);
						return 1;
					}
				}	
				/* Complex */
				if(listitem == 2)
				{
					/* Lucky Lottery Ticked */
					if( PSlotItemTypeCompare(playerid, gSelectedSlot[playerid], 3) && SlotItem(playerid, gSelectedSlot[playerid], 10) )
					{
						SlotParam5( playerid, gSelectedSlot[playerid] );
						format( string, sizeof(string), "[1: %d] [2: %d] [3: %d] [4: %d]\nLosowanie nr: %d", SlotParam1( playerid, gSelectedSlot[playerid] ), SlotParam2( playerid, gSelectedSlot[playerid] ), SlotParam3( playerid, gSelectedSlot[playerid] ), SlotParam4( playerid, gSelectedSlot[playerid] ), strval( gDSelectedItemP5[playerid] ) );
						ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Twoje numerki", string, "Zamknij", "" );
					}
					/* Kluczyki do pojazdu */
					if( PSlotItemTypeCompare(playerid, gSelectedSlot[playerid], 2) )
					{
						new vehid = CarSerialToID(ShowSlotItem(playerid, gSelectedSlot[playerid]));
						if(vehid == -1)
						{
							PlayerActionMessage(playerid, 15.0, "wciska pilot od pojazdu");
							return 1;
						}
						
						if(!IsAMotorBike(vehid+1) && !IsABike(vehid+1))
							PlayerActionMessage(playerid, 15.0, "wciska pilot od pojazdu");
						if( IsABike(vehid+1) )
							return 1;
						
						new Float:ox, Float:oy, Float:oz;
						GetVehiclePos(vehid+1, ox, oy, oz);
						if(PlayerToPoint(40.0, playerid, ox, oy, oz) && !IsAMotorBike(vehid+1) && !IsABike(vehid+1))
						{
							new enginedyn,lights,alarm,doors,bonnet,boot,objective;
							GetVehicleParamsEx(vehid+1,enginedyn,lights,alarm,doors,bonnet,boot,objective);
							if(doors == 1 && !gVehData[vehid][VConfiscated] )
							{
								doors = 0;
								format(string, sizeof(string),  "* pojazd otwarty (( %s ))", gPlayerData[playerid][pName]);
								ProxDetector(30.0, playerid, string, COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE);
								gVehData[vehid][Closed] = 0;
								SaveVehData(vehid, "Closed");
							}
							else if(doors == 1 && gVehData[vehid][VConfiscated] )
							{
								SendClientMessage( playerid, COLOR_RED, "[INFO:] Pojazd skonfiskowany ! Nie mo¿esz go otworzyæ !" );
							}
							else
							{
								doors = 1;
								format(string, sizeof(string),  "* pojazd zamkniêty (( %s ))", gPlayerData[playerid][pName]);
								ProxDetector(30.0, playerid, string, COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE);
								gVehData[vehid][Closed] = 1;
								SaveVehData(vehid, "Closed");
							}
							if(gVehData[vehid][Alarm])
								SetVehicleParamsEx(vehid+1,enginedyn,1,1,doors,bonnet,boot,objective);
							else
								SetVehicleParamsEx(vehid+1,enginedyn,1,alarm,doors,bonnet,boot,objective);
							delay:CarAlarmOff[700](vehid+1);
						}					
					}
					/* Telefon */
					if( PSlotItemTypeCompare(playerid, gSelectedSlot[playerid], 3) && ( SlotItem(playerid, gSelectedSlot[playerid], 3) || SlotItem(playerid, gSelectedSlot[playerid], 4) ) )
					{
						if(SlotParam1(playerid, gSelectedSlot[playerid] == 0))
						{
							SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Telefon jest wy³¹czony, przed u¿yciem musisz go w³¹czyæ");
						}
						else
						{
							if(PHaveItem(playerid, 1, 4))
							{
								ShowPlayerDialog(playerid,DIALOG_PHONE_BOOK,DIALOG_STYLE_INPUT,"Wybierz osobe","Wpisz numer id odbiorcy","Dzwon","Anuluj");
							}
							else
							{
								ShowPlayerDialog(playerid,DIALOG_PHONE,DIALOG_STYLE_INPUT,"Numer telefonu","Wpisz numer telefonu odbiorcy","Dzwon","Anuluj");
							}
							gSendingSMS[playerid] = 0;
						}
					}
					/* Okulary */
					if( PSlotItemTypeCompare(playerid, gSelectedSlot[playerid], 3) && SlotItem(playerid, gSelectedSlot[playerid], 7) )
					{
						if(IsPlayerHoldingObject(playerid) && SlotParam1(playerid, gSelectedSlot[playerid]) == gGlassesWearingModel[playerid])
						{
							StopPlayerHoldingObject(playerid);
							PlayerActionMessage(playerid, 15.0, "zdejmuje okulary");
							gGlassesWearingModel[playerid] = 0;
							return 1;
						}
						if(IsPlayerHoldingObject(playerid) && SlotParam1(playerid, gSelectedSlot[playerid]) != gGlassesWearingModel[playerid])
						{
							StopPlayerHoldingObject(playerid);
							new skin = GetPlayerSkin(playerid);
							SetPlayerHoldingObject(playerid, 19006 + (SlotParam1(playerid, gSelectedSlot[playerid])-1),2,SkinOffSet[skin][0], SkinOffSet[skin][1], SkinOffSet[skin][2], SkinOffSet[skin][3], SkinOffSet[skin][4], SkinOffSet[skin][5]);
							gGlassesWearingModel[playerid] = SlotParam1(playerid, gSelectedSlot[playerid]);
							PlayerActionMessage(playerid, 15.0, "zmienia okulary");
							return 1;
						}
						else
						{
							new skin = GetPlayerSkin(playerid);
							SetPlayerHoldingObject(playerid, 19006 + (SlotParam1(playerid, gSelectedSlot[playerid])-1),2,SkinOffSet[skin][0], SkinOffSet[skin][1], SkinOffSet[skin][2], SkinOffSet[skin][3], SkinOffSet[skin][4], SkinOffSet[skin][5]);
							gGlassesWearingModel[playerid] = SlotParam1(playerid, gSelectedSlot[playerid]);
							PlayerActionMessage(playerid, 15.0, "zak³ada okulary");
							return 1;
						}
					}
					/* Czapki */
					if( PSlotItemTypeCompare(playerid, gSelectedSlot[playerid], 3) && SlotItem(playerid, gSelectedSlot[playerid], 9) )
					{
						if(IsPlayerAttachedObjectSlotUsed(playerid, MAX_PLAYER_ATTACHED_OBJECTS-2) && SlotParam1(playerid, gSelectedSlot[playerid]) == gHatWearingModel[playerid])
						{
							RemovePlayerAttachedObject(playerid, MAX_PLAYER_ATTACHED_OBJECTS-2);
							PlayerActionMessage(playerid, 15.0, "zdejmuje czapke");
							gHatWearingModel[playerid] = 255;
							return 1;
						}
						if(IsPlayerAttachedObjectSlotUsed(playerid, MAX_PLAYER_ATTACHED_OBJECTS-2) && SlotParam1(playerid, gSelectedSlot[playerid]) != gHatWearingModel[playerid])
						{
							RemovePlayerAttachedObject(playerid, MAX_PLAYER_ATTACHED_OBJECTS-2);
							new skin = GetPlayerSkin(playerid);
							if(SlotParam2(playerid, gSelectedSlot[playerid]) == 0) // inne id obiektow czapek mikolaja
								SetPlayerAttachedObject(playerid, MAX_PLAYER_ATTACHED_OBJECTS-2, 19064 + (SlotParam1(playerid, gSelectedSlot[playerid])), 2, Hat2OffSet[skin][0], Hat2OffSet[skin][1], Hat2OffSet[skin][2], Hat2OffSet[skin][3], Hat2OffSet[skin][4], Hat2OffSet[skin][5], Hat2OffSet[skin][6], Hat2OffSet[skin][7], Hat2OffSet[skin][8]);
							else
								SetPlayerAttachedObject(playerid, MAX_PLAYER_ATTACHED_OBJECTS-2, 18926 + (SlotParam1(playerid, gSelectedSlot[playerid])), 2, Hat1OffSet[skin][0], Hat1OffSet[skin][1], Hat1OffSet[skin][2], Hat1OffSet[skin][3], Hat1OffSet[skin][4], Hat1OffSet[skin][5], Hat1OffSet[skin][6], Hat1OffSet[skin][7], Hat1OffSet[skin][8]);
							gHatWearingModel[playerid] = SlotParam1(playerid, gSelectedSlot[playerid]);
							PlayerActionMessage(playerid, 15.0, "zmienia czapke");
							return 1;
						}
						else
						{
							new skin = GetPlayerSkin(playerid);
							// SetPlayerAttachedObject(playerid, MAX_PLAYER_ATTACHED_OBJECTS-2, 18926 + (SlotParam1(playerid, gSelectedSlot[playerid])),2,Hat1OffSet[skin][0],Hat1OffSet[skin][1], Hat1OffSet[skin][2], Hat1OffSet[skin][3],Hat1OffSet[skin][4],Hat1OffSet[skin][5],Hat1OffSet[skin][6],Hat1OffSet[skin][7],Hat1OffSet[skin][8]);
							RemovePlayerAttachedObject(playerid, MAX_PLAYER_ATTACHED_OBJECTS-2);
							if(SlotParam1(playerid, gSelectedSlot[playerid]) > 0) // inne id obiektow czapek mikolaja
								SetPlayerAttachedObject(playerid, MAX_PLAYER_ATTACHED_OBJECTS-2, 19064 + (SlotParam1(playerid, gSelectedSlot[playerid]) - 1),2,Hat2OffSet[skin][0],Hat2OffSet[skin][1],Hat2OffSet[skin][2], Hat2OffSet[skin][3], Hat2OffSet[skin][4],Hat2OffSet[skin][5],Hat2OffSet[skin][6],Hat2OffSet[skin][7],Hat2OffSet[skin][8]);
							else
								SetPlayerAttachedObject(playerid, MAX_PLAYER_ATTACHED_OBJECTS-2, 18926 + (SlotParam1(playerid, gSelectedSlot[playerid])),2,Hat1OffSet[skin][0],Hat1OffSet[skin][1],Hat1OffSet[skin][2], Hat1OffSet[skin][3], Hat1OffSet[skin][4],Hat1OffSet[skin][5],Hat1OffSet[skin][6],Hat1OffSet[skin][7],Hat1OffSet[skin][8]);
							gHatWearingModel[playerid] = SlotParam1(playerid, gSelectedSlot[playerid]);
							PlayerActionMessage(playerid, 15.0, "zak³ada czapke");
							return 1;
						}
					}
					/* Rakieta (fajerwerek) */
					if( PSlotItemTypeCompare(playerid, gSelectedSlot[playerid], 1) && SlotItem(playerid, gSelectedSlot[playerid], 6) )
					{
						ShowPItems(playerid);
						return 1;
						// if(firerockettime[playerid] == 0)
						// {
							// new distance;
							// if(AllowedFirework[FWNDrawDistance] == 0) distance = 15;
							// if(AllowedFirework[FWNDrawDistance] == 1) distance = 22;
							// if(AllowedFirework[FWNDrawDistance] == 2) distance = 30;
							// new Float:Xj, Float:Yj,Float:Zj;
							// firerockettime[playerid] = 1;
							// new sendername[MAX_PLAYER_NAME];
							// GetPlayerName(playerid, sendername, sizeof(sendername));
							// PlayerActionMessage(playerid, 15.0, "rozstawia rakiete");
							// GetPlayerPos(playerid,Xj,Yj,Zj);
							// GetXYInFrontOfPlayer(playerid, Xj,Yj, distance);
							// Firerocket[playerid] = CreateObject(354, Xj,Yj,(Zj), 0, 0, 0);
							// rocketsmoke[playerid] = CreateObject(2780, Xj,Yj,(Zj), 0, 0, 0);
							// MoveObject(Firerocket[playerid], Xj, Yj, Zj+30, 10);
							// MoveObject(rocketsmoke[playerid], Xj, Yj, Zj+30, 10);
							// SetTimerEx("FirerocketTime", 3000, 0, "i", playerid);
							// RemovePlayerItemExUsed(playerid, gSelectedSlot[playerid]);
							// return 1;
						// }
						// else return SendClientMessage(playerid, RED, "[INFO:] Ju¿ u¿y³eœ jednego zestawu, musisz poczekaæ a¿ siê skoñczy");
					}
					/* Zestaw fajerwerków */
					// if( PSlotItemTypeCompare(playerid,  gSelectedSlot[playerid], 1) && SlotItem(playerid, gSelectedSlot[playerid], 8) )
					// {
						// if(RocketBoxTime[playerid] == 0)
						// {
							// new distance;
							// if(AllowedFirework[FWNDrawDistance] == 0) distance = 15;
							// if(AllowedFirework[FWNDrawDistance] == 1) distance = 22;
							// if(AllowedFirework[FWNDrawDistance] == 2) distance = 30;
							// new Float:Xj, Float:Yj,Float:Zj;
							// RocketBoxTime[playerid] = 1;
							// PlayerActionMessage(playerid, 15.0, "rozstawia fajerwerki");
							// GetPlayerPos(playerid,Xj,Yj,Zj);
							// GetXYInFrontOfPlayer(playerid, Xj,Yj, distance);
							// RBX[playerid] = Xj;
							// RBY[playerid] = Yj;
							// RBZ[playerid] = (Zj-1.0);
							// RocketBox[playerid] = CreateObject(354, Xj,Yj,(Zj-1.0), 0, 0, 0);
							// RocketBoxSmoke[playerid] = CreateObject(2780, Xj,Yj,(Zj-1.0), 0, 0, 0);
							// SetTimerEx("RocketBoxTimer", 3000, 0, "i", playerid);
							// RemovePlayerItemExUsed(playerid, gSelectedSlot[playerid]);
							// return 1;
						// }
						// else return SendClientMessage(playerid, RED, "[INFO:] Ju¿ u¿y³eœ jednego zestawu, musisz poczekaæ a¿ siê skoñczy");
					// }
					/* Kanister */
					if( PSlotItemTypeCompare(playerid, gSelectedSlot[playerid], 3) && SlotItem(playerid, gSelectedSlot[playerid], 1) )
					{
						if(SlotParam1(playerid, gSelectedSlot[playerid]) == 0)
						{
							SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Kanister jest pusty !");
							return 1;
						}
						ShowPlayerDialog(playerid,DIALOG_KANISTER,DIALOG_STYLE_INPUT,"Rejestracja pojazdu","Wpisz rejestracje pojazdu który chcesz zatankowaæ","Tankuj","Anuluj");
					}
					/* Pobór broni */
					if( PSlotItemTypeCompare(playerid, gSelectedSlot[playerid], 1) && ShowSlotItem(playerid, gSelectedSlot[playerid]) >= 13 && ShowSlotItem(playerid, gSelectedSlot[playerid]) <= 32 && !IsPlayerInAnyVehicle(playerid) )
					{
						new slot;
						printf("[WEAPON:] Player %s took weapon item ID: %d from /mi", GetPlayerNameEx(playerid), ShowSlotItem(playerid, gSelectedSlot[playerid]));
						switch(ShowSlotItem(playerid, gSelectedSlot[playerid]))
						{
							case 16: // example
							{
								if( ( slot = PHaveItem( playerid, 1, 36 ) ) != 0 ) // sprawdzenie czy gracz posiada ammo na itemach
								{
									if( PlayerHaveWeapon( playerid, 22 ) == 0 )
										RemovePlayerItemExUsed( playerid, gSelectedSlot[playerid] );
									GivePlayerGun( playerid, 22, SlotParam6( playerid, slot ) );
									RemovePlayerItemUsed( playerid, slot );
									return 1;
								}
							}
							case 17:
							{
								if( ( slot = PHaveItem( playerid, 1, 36 ) ) != 0 )
								{
									if( PlayerHaveWeapon( playerid, 23 ) == 0 )
										RemovePlayerItemExUsed( playerid, gSelectedSlot[playerid] );
									GivePlayerGun( playerid, 23, SlotParam6( playerid, slot ) );
									RemovePlayerItemUsed( playerid, slot );
									return 1;
								}
							}
							case 18:
							{
								if( ( slot = PHaveItem( playerid, 1, 37 ) ) != 0 )
								{
									if( PlayerHaveWeapon( playerid, 24 ) == 0 )
										RemovePlayerItemExUsed( playerid, gSelectedSlot[playerid] );
									GivePlayerGun( playerid, 24, SlotParam6( playerid, slot ) );
									RemovePlayerItemUsed( playerid, slot );
									return 1;
								}
							}
							case 19:
							{
								if( ( slot = PHaveItem( playerid, 1, 38 ) ) != 0 )
								{
									if( PlayerHaveWeapon( playerid, 25 ) == 0 )
										RemovePlayerItemExUsed( playerid, gSelectedSlot[playerid] );
									GivePlayerGun( playerid, 25, SlotParam6( playerid, slot ) );
									RemovePlayerItemUsed( playerid, slot );
									return 1;
								}
							}
							case 20:
							{
								if( ( slot = PHaveItem( playerid, 1, 38 ) ) != 0 )
								{
									if( PlayerHaveWeapon( playerid, 26 ) == 0 )
										RemovePlayerItemExUsed( playerid, gSelectedSlot[playerid] );
									GivePlayerGun( playerid, 26, SlotParam6( playerid, slot ) );
									RemovePlayerItemUsed( playerid, slot );
									return 1;
								}
							}
							case 21:
							{
								if( ( slot = PHaveItem( playerid, 1, 38 ) ) != 0 )
								{
									if( PlayerHaveWeapon( playerid, 27 ) == 0 )
										RemovePlayerItemExUsed( playerid, gSelectedSlot[playerid] );
									GivePlayerGun( playerid, 27, SlotParam6( playerid, slot ) );
									RemovePlayerItemUsed( playerid, slot );
									return 1;
								}
							}
							case 22:
							{
								if( ( slot = PHaveItem( playerid, 1, 36 ) ) != 0 )
								{
									if( PlayerHaveWeapon( playerid, 28 ) == 0 )
										RemovePlayerItemExUsed( playerid, gSelectedSlot[playerid] );
									GivePlayerGun( playerid, 28, SlotParam6( playerid, slot ) );
									RemovePlayerItemUsed( playerid, slot );
									return 1;
								}
							}
							case 23:
							{
								if( ( slot = PHaveItem( playerid, 1, 36 ) ) != 0 )
								{
									if( PlayerHaveWeapon( playerid, 29 ) == 0 )
										RemovePlayerItemExUsed( playerid, gSelectedSlot[playerid] );
									GivePlayerGun( playerid, 29, SlotParam6( playerid, slot ) );
									RemovePlayerItemUsed( playerid, slot );
									return 1;
								}
							}
							case 24:
							{
								if( ( slot = PHaveItem( playerid, 1, 39 ) ) != 0 )
								{
									if( PlayerHaveWeapon( playerid, 30 ) == 0 )
										RemovePlayerItemExUsed( playerid, gSelectedSlot[playerid] );
									GivePlayerGun( playerid, 30, SlotParam6( playerid, slot ) );
									RemovePlayerItemUsed( playerid, slot );
									return 1;
								}
							}
							case 25:
							{
								if( ( slot = PHaveItem( playerid, 1, 39 ) ) != 0 )
								{
									if( PlayerHaveWeapon( playerid, 31 ) == 0 )
										RemovePlayerItemExUsed( playerid, gSelectedSlot[playerid] );
									GivePlayerGun( playerid, 31, SlotParam6( playerid, slot ) );
									RemovePlayerItemUsed( playerid, slot );
									return 1;
								}
							}
							case 26:
							{
								if( ( slot = PHaveItem( playerid, 1, 36 ) ) != 0 )
								{
									if( PlayerHaveWeapon( playerid, 32 ) == 0 )
										RemovePlayerItemExUsed( playerid, gSelectedSlot[playerid] );
									GivePlayerGun( playerid, 32, SlotParam6( playerid, slot ) );
									RemovePlayerItemUsed( playerid, slot );
									return 1;
								}
							}
							case 27:
							{
								if( ( slot = PHaveItem( playerid, 1, 40 ) ) != 0 )
								{
									if( PlayerHaveWeapon( playerid, 33 ) == 0 )
										RemovePlayerItemExUsed( playerid, gSelectedSlot[playerid] );
									GivePlayerGun( playerid, 33, SlotParam6( playerid, slot ) );
									RemovePlayerItemUsed( playerid, slot );
									return 1;
								}
							}
							case 28:
							{
								if( ( slot = PHaveItem( playerid, 1, 40 ) ) != 0 )
								{
									if( PlayerHaveWeapon( playerid, 34 ) == 0 )
										RemovePlayerItemExUsed( playerid, gSelectedSlot[playerid] );
									GivePlayerGun( playerid, 34, SlotParam6( playerid, slot ) );
									RemovePlayerItemUsed( playerid, slot );
									return 1;
								}
							}
							case 29:
							{
								if( ( slot = PHaveItem( playerid, 1, 41 ) ) != 0 )
								{
									if( PlayerHaveWeapon( playerid, 35 ) == 0 )
										RemovePlayerItemExUsed( playerid, gSelectedSlot[playerid] );
									GivePlayerGun( playerid, 35, SlotParam6( playerid, slot ) );
									RemovePlayerItemUsed( playerid, slot );
									return 1;
								}
							}
							case 30:
							{
								if( ( slot = PHaveItem( playerid, 1, 41 ) ) != 0 )
								{
									if( PlayerHaveWeapon( playerid, 36 ) == 0 )
										RemovePlayerItemExUsed( playerid, gSelectedSlot[playerid] );
									GivePlayerGun( playerid, 36, SlotParam6( playerid, slot ) );
									RemovePlayerItemUsed( playerid, slot );
									return 1;
								}
							}
							case 31:
							{
								if( ( slot = PHaveItem( playerid, 1, 42 ) ) != 0 )
								{
									if( PlayerHaveWeapon( playerid, 37 ) == 0 )
										RemovePlayerItemExUsed( playerid, gSelectedSlot[playerid] );
									GivePlayerGun( playerid, 37, SlotParam6( playerid, slot ) );
									RemovePlayerItemUsed( playerid, slot );
									return 1;
								}
							}
							case 32:
							{
								if( ( slot = PHaveItem( playerid, 1, 39 ) ) != 0 )
								{
									if( PlayerHaveWeapon( playerid, 38 ) == 0 )
										RemovePlayerItemExUsed( playerid, gSelectedSlot[playerid] );
									GivePlayerGun( playerid, 38, SlotParam6( playerid, slot ) );
									RemovePlayerItemUsed( playerid, slot );		
									return 1;
								}
							}
							case 33:
							{
								GivePlayerGun( playerid, 39, SlotParam6(playerid, gSelectedSlot[playerid] ) );
								RemovePlayerItemUsed( playerid, gSelectedSlot[playerid] );
								return 1;
							}
							case 34:
							{
								GivePlayerGun(playerid, 41, SlotParam6(playerid, gSelectedSlot[playerid]));
								RemovePlayerItemUsed( playerid, gSelectedSlot[playerid] );
								return 1;
							}
							case 35:
							{
								GivePlayerGun( playerid, 42, SlotParam6(playerid, gSelectedSlot[playerid] ) );
								RemovePlayerItemUsed( playerid, gSelectedSlot[playerid] );
								return 1;
							}
						}
						SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Brak amunicji !");
						return 1;
					}
					/* Radio */
					if( PSlotItemTypeCompare(playerid, gSelectedSlot[playerid], 1) && SlotItem(playerid, gSelectedSlot[playerid], 106) )
					{
						new Float:x, Float:y, Float:z, Float:angle;
						for( new i = 0; i < sizeof(Businesses); i++ )
						{
							if( PlayerToPoint(100.0, playerid, Businesses[i][ExitX], Businesses[i][ExitY], Businesses[i][ExitZ]) && i == GetPlayerVirtualWorld(playerid) )
							{
								if( Businesses[i][BRadio1Bought] )
								{
									SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Posiadasz ju¿ radio w tym biznesie !");
									return 1;
								}
								Businesses[i][BRadio1Bought] = 1;
								Businesses[i][BRadio1On] = 0;
								Businesses[i][BRadio1Vol] = 50;
								SaveBizData( i, "BRadio1Bought" );
								SaveBizData( i, "BRadio1On" );
								SaveBizData( i, "BRadio1Vol" );
								GetPlayerPos( playerid, x, y, z );
								GetPlayerFacingAngle(playerid, angle);
								Businesses[i][BRadio1X] = x;
								Businesses[i][BRadio1Y] = y;
								Businesses[i][BRadio1Z] = z;
								Businesses[i][BRadio1Angle] = angle;
								Businesses[i][BRadio1Obj] = CreateDynamicObject(O_RADIO_T_1, x, y, z-1.0, 0, 0, angle, i, Businesses[i][ExitInterior]);
								SaveBizData( i, "BRadio1X" );
								SaveBizData( i, "BRadio1Y" );
								SaveBizData( i, "BRadio1Z" );
								SaveBizData( i, "BRadio1Angle" );
								RemovePlayerItemExUsed( playerid, gSelectedSlot[playerid] );
								return 1;
							}
						}
						for( new i = 0; i < sizeof(Houses); i++ )
						{
							if( PlayerToPoint(50.0, playerid, Houses[i][ExitX], Houses[i][ExitY], Houses[i][ExitZ]) && i == GetPlayerVirtualWorld(playerid) )
							{
								if( Houses[i][HRadio1Bought] )
								{
									SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Posiadasz ju¿ radio w tym domu !");
									return 1;
								}
								Houses[i][HRadio1Bought] = 1;
								Houses[i][HRadio1On] = 0;
								Houses[i][HRadio1Vol] = 50;
								SaveHouseData( i, "HRadio1Bought" );
								SaveHouseData( i, "HRadio1On" );
								SaveHouseData( i, "HRadio1Vol" );
								GetPlayerPos( playerid, x, y, z );
								GetPlayerFacingAngle(playerid, angle);
								Houses[i][HRadio1X] = x;
								Houses[i][HRadio1Y] = y;
								Houses[i][HRadio1Z] = z;
								Houses[i][HRadio1Angle] = angle;
								Houses[i][HRadio1Obj] = CreateDynamicObject(O_RADIO_T_1, x, y, z-1.0, 0, 0, angle, i, Houses[i][ExitInterior]);
								SaveHouseData( i, "HRadio1X" );
								SaveHouseData( i, "HRadio1Y" );
								SaveHouseData( i, "HRadio1Z" );
								SaveHouseData( i, "HRadio1Angle" );
								RemovePlayerItemExUsed( playerid, gSelectedSlot[playerid] );
								return 1;
							}
						}
						SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie znajdujesz siê w domu !");
						return 1;
					}
				}
				/* Complex */
				if(listitem == 3)
				{
					/* Lucky Lottery Ticked */
					if( PSlotItemTypeCompare(playerid, gSelectedSlot[playerid], 3) && SlotItem(playerid, gSelectedSlot[playerid], 10) )
					{
						if( !IsPlayerInRangeOfPoint( playerid, 1.0, 359.0, 167.0, 1008.0 ) )
						{
							ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Nie jesteœ w kolekturze !", "Zamknij", "" );
							return 1;
						}
						
						/* Check ticket ID ( validity ) */
						SlotParam5( playerid, gSelectedSlot[playerid] );
						if( strval(gDSelectedItemP5[playerid]) > gLuckyLotteryID )
						{
							ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "To losowanie jeszcze siê nie odby³o !", "Zamknij", "" );
							return 1;
						}
						if( strval(gDSelectedItemP5[playerid]) < gLuckyLotteryID )
						{
							ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Ten kupon jest ju¿ niewa¿ny !", "Zamknij", "" );
							return 1;
						}
						
						/* Check if player winn */
						for( new i = 0; i < sizeof(gLuckyLottery); i++ )
						{
							if( gLuckyLottery[i][LuckyNumbers][0] == SlotParam1( playerid, gSelectedSlot[playerid] ) && gLuckyLottery[i][LuckyNumbers][1] == SlotParam2( playerid, gSelectedSlot[playerid] ) &&
								gLuckyLottery[i][LuckyNumbers][2] == SlotParam1( playerid, gSelectedSlot[playerid] ) && gLuckyLottery[i][LuckyNumbers][3] == SlotParam2( playerid, gSelectedSlot[playerid] ) )
							{
								RemovePlayerItemUsed( playerid, gSelectedSlot[playerid] );
								if( gLuckyLotteryWinnersCount > 0 )
								{
									GivePlayerCash( playerid, floatround( gLuckyLotteryCash/gLuckyLotteryWinnersCount, floatround_round ) );
									gLuckyLotteryCash -= floatround( gLuckyLotteryCash/gLuckyLotteryWinnersCount, floatround_round );
								}
								else
								{
									GivePlayerCash( playerid, gLuckyLotteryCash );
									gLuckyLotteryCash = 0;
								}
								SaveLotteryData( -1 );
								ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Odebra³eœ nagrode !", "Zamknij", "" );
								return 1;
							}
						}
						ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Te numery nie zosta³y wylosowane !", "Zamknij", "" );
						return 1;
					}						
					/* Telefon - wyœwietlenie numeru */
					if(PSlotItemTypeCompare(playerid, gSelectedSlot[playerid], 3) && (SlotItem(playerid, gSelectedSlot[playerid], 3) || SlotItem(playerid, gSelectedSlot[playerid], 4)))
					{
						format(string, sizeof(string), "[INFO:] Twój numer to: %d", SlotParam2(playerid, gSelectedSlot[playerid]));
						SendClientMessage(playerid, COLOR_WHITE, string);
					}
					/* Kanister - zawartoœæ */
					if(PSlotItemTypeCompare(playerid, gSelectedSlot[playerid], 3) && SlotItem(playerid, gSelectedSlot[playerid], 1))
					{
						new fuelType = SlotParam2(playerid, gSelectedSlot[playerid]);
						new fuelTypeTXT[32];
						if( fuelType == 0 )
							strins( fuelTypeTXT, "benzyna", 0 );
						else
							strins( fuelTypeTXT, "ropa", 0 );
						format(string, sizeof(string), "Zawartoœæ kanistra: %d/25ltr\nTyp: %s", SlotParam1(playerid, gSelectedSlot[playerid]), fuelTypeTXT);
						ShowPlayerDialog(playerid, DIALOG_ITEM_1, DIALOG_STYLE_MSGBOX, "Kanister", string, "Wróæ", "" );
						return 1;
					}
				}
				/* Complex */
				if(listitem == 4)
				{
					/* Telefon - status */
					if(PSlotItemTypeCompare(playerid, gSelectedSlot[playerid], 3) && (SlotItem(playerid, gSelectedSlot[playerid], 3) || SlotItem(playerid, gSelectedSlot[playerid], 4)))
					{
						if(SlotParam1(playerid, gSelectedSlot[playerid]) == 0)	{ SendClientMessage(playerid, COLOR_WHITE, "[INFO:] Telefon jest wy³¹czony"); }
						if(SlotParam1(playerid, gSelectedSlot[playerid]) == 1)	{ SendClientMessage(playerid, COLOR_WHITE, "[INFO:] Telefon jest w³¹czony"); }
					}
					/* Kanister - tankowanie */
					if(PSlotItemTypeCompare(playerid, gSelectedSlot[playerid], 3) && SlotItem(playerid, gSelectedSlot[playerid], 1))
					{
						if(SlotParam1(playerid, gSelectedSlot[playerid]) == 25)
						{
							SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Kanister jest pe³ny !");
							return 1;
						}
						ShowPlayerDialog(playerid, DIALOG_KANISTER_REFUEL, DIALOG_STYLE_LIST, "Wybierz paliwo którym chcesz nape³niæ kanister", "Beznyna\nDiesel","Wybierz","Anuluj");
					}
				}
				/* Complex */
				if(listitem == 5)
				{
					/* Telefon - wykonywanie po³¹czenia */
					if(PSlotItemTypeCompare(playerid, gSelectedSlot[playerid], 3) && (SlotItem(playerid, gSelectedSlot[playerid], 3) || SlotItem(playerid, gSelectedSlot[playerid], 4)))
					{
						if(SlotParam1(playerid, gSelectedSlot[playerid] == 0))
						{
							SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Telefon jest wy³¹czony, przed u¿yciem musisz go w³¹czyæ");
						}
						else
						{
							if(PHaveItem(playerid, 1, 4))
							{
								ShowPlayerDialog(playerid,DIALOG_PHONE_BOOK,DIALOG_STYLE_INPUT,"Wybierz osobe","Wpisz numer id odbiorcy","Wybierz","Anuluj");
							}
							else
							{
								ShowPlayerDialog(playerid,DIALOG_PHONE,DIALOG_STYLE_INPUT,"Numer telefonu","Wpisz numer telefonu odbiorcy","Wybierz","Anuluj");
							}
							gSendingSMS[playerid] = 1;
						}
					}
				}
				/* Complex */
				if(listitem == 6)
				{
					/* Telefon - numery alarmowe */
					if(PSlotItemTypeCompare(playerid, gSelectedSlot[playerid], 3) && (SlotItem(playerid, gSelectedSlot[playerid], 3) || SlotItem(playerid, gSelectedSlot[playerid], 4)))
					{
						if(SlotParam1(playerid, gSelectedSlot[playerid]) == 0) 
						{
							SendClientMessage(playerid, COLOR_WHITE, "[INFO:] Telefon jest wy³¹czony"); 
							return 1;
						}
						ShowPlayerDialog(playerid,DIALOG_PHONE_ALARMS,DIALOG_STYLE_LIST, "Wybierz numer", "1. 999 - pogotwie\n2. 997 - policja\n3. 555 - warsztat samochodowy","Dzwoñ","Anuluj");
					}
				}
				/* Complex */
				if(listitem == 7)
				{
					/* Telefon - ukryj numery */
					if(PSlotItemTypeCompare(playerid, gSelectedSlot[playerid], 3) && (SlotItem(playerid, gSelectedSlot[playerid], 3) || SlotItem(playerid, gSelectedSlot[playerid], 4)))
					{
						if(gPlayerData[playerid][pListNumber])
						{
							SendClientMessage(playerid,  COLOR_LIGHTYELLOW2, "[INFO:] Twój numer zosta³ ukryty i nie bêdzie pokazywany w ksi¹¿ce telefonicznej.");
							gPlayerData[playerid][pListNumber] = 0;
							SavePlayerData(playerid, "ListNumber");
						}
						else
						{
							SendClientMessage(playerid,  COLOR_LIGHTYELLOW2, "[INFO:] Twój numer jest widoczny w ksi¹¿ce telefonicznej.");
							gPlayerData[playerid][pListNumber] = 1;
							SavePlayerData(playerid, "ListNumber");
						}
					}
				}
				/* Complex */
				if(listitem == 8)
				{
					/* Telefon - on/off */
					if(PSlotItemTypeCompare(playerid, gSelectedSlot[playerid], 3) && (SlotItem(playerid, gSelectedSlot[playerid], 3) || SlotItem(playerid, gSelectedSlot[playerid], 4)))
					{
						if(SlotParam1(playerid, gSelectedSlot[playerid]) == 0) 
						{
							SetPSlotParam1(playerid, gSelectedSlot[playerid], 1);
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] W³¹czy³eœ swój telefon");
						}
						else
						{
							SetPSlotParam1(playerid, gSelectedSlot[playerid], 0);
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Wy³¹czy³eœ swój telefon");
						}
					}
				}
			}
			else
			{
				ShowPItems(playerid);
			}
		}
		case DIALOG_ITEM_TRANSFER: // przekazywanie itema
		{
			if(response)
			{
				new giveplayerid = strval(inputtext);
				new slot = gSelectedSlot[playerid];
				gSelectedSlot[giveplayerid] = gSelectedSlot[playerid];
				gSendingPlayer[giveplayerid] = playerid;	
				if(IsPlayerConnected(giveplayerid) == 0)
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten gracz nie jest ON-LINE");
					return 1;
				}
				if( giveplayerid == playerid )
				{
					SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz sam sobie przekazaæ itemu !" );
					return 1;
				}
				new Float: posX, Float: posY, Float: posZ;
				GetPlayerPos(playerid, posX, posY, posZ);
				if(PlayerToPoint(2.0, giveplayerid, posX, posY, posZ) == 0)
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ta osoba jest zbyt daleko od Ciebie !");
					return 1;
				}
				if( PlayerFreeSlotCount( giveplayerid ) > 0 )
				{
					format(string, sizeof(string), "Czy zgadzasz siê na odebranie itemu: %s od %s?", ItemName( PSlotItemType(playerid, slot), ShowSlotItem(playerid, slot) ), gPlayerData[playerid][pName] );
					ShowPlayerDialog(giveplayerid, DIALOG_ITEM_TRANSFER_RESPONSE, DIALOG_STYLE_MSGBOX,"PotwierdŸ transakcje", string, "Tak", "Nie");
					ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Zaoferowa³eœ graczowi przedmiot", "Zamknij", "");
					return 1;
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ta osoba nie ma miejsca aby przyj¹æ od ciebie item");
					ShowPItems(playerid);
					return 1;
				}
			}
			else
			{	
				ShowPItems(playerid);
				return 1;
			}
		}
		case DIALOG_ITEM_TRANSFER_RESPONSE:
		{
			if(response)
			{
				new giveplayerid = gSendingPlayer[playerid];
				
				format(string, sizeof(string), "[INFO:] Przekaza³eœ item ze slotu nr %d", gSelectedSlot[playerid]);
				SendClientMessage(giveplayerid, COLOR_LIGHTYELLOW2, string);

				format(string, sizeof(string), "[INFO:] Otrzyma³eœ item od %s, slot %d", gPlayerData[giveplayerid][pName], gSelectedSlot[playerid]);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);

				format(string, sizeof(string), "wyjmuje %s i przekazuje go/je", ItemName( PSlotItemType(giveplayerid, gSelectedSlot[giveplayerid] ), ShowSlotItem(giveplayerid, gSelectedSlot[giveplayerid]) ));
				PlayerPlayerActionMessage(giveplayerid, playerid, 20.0, string);

				SlotParam5(giveplayerid, gSelectedSlot[playerid]);
				InsertPlayerItemEx(playerid, PSlotItemType(giveplayerid, gSelectedSlot[playerid]), ShowSlotItem(giveplayerid, gSelectedSlot[playerid]), SlotParam1(giveplayerid, gSelectedSlot[playerid]), SlotParam2(giveplayerid, gSelectedSlot[playerid]), SlotParam3(giveplayerid, gSelectedSlot[playerid]), SlotParam4(giveplayerid, gSelectedSlot[playerid]), gDSelectedItemP5[giveplayerid], SlotParam6(giveplayerid, gSelectedSlot[playerid]));
				
				RemovePlayerItemExUsed(giveplayerid, gSelectedSlot[playerid], SlotParam6(giveplayerid, gSelectedSlot[playerid]));
				ShowPItems(playerid);
			}
			else
			{
				SendClientMessage(gSendingPlayer[playerid], COLOR_ORANGE, "[INFO:] Gracz odrzuci³ twoj¹ propozycje !");
				return 1;
			}
		}				
		case DIALOG_ITEM_REMOVE: // wyrzucanie itema
		{
			if(response)
			{
				new howMuch = strval(inputtext);
				if(SlotParam6(playerid, gSelectedSlot[playerid]) <= 0)
				{
					RemovePlayerItemEx(playerid, gSelectedSlot[playerid]);
					format(string, sizeof(string), "[INFO:] Wyrzuci³eœ item ze slotu %d", gSelectedSlot[playerid]);
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2,string);
					ShowPItems(playerid);
					return 1;
				}
				if(howMuch > SlotParam6(playerid, gSelectedSlot[playerid]))
				{
					ShowPlayerDialog(playerid,DIALOG_ITEM_REMOVE,DIALOG_STYLE_INPUT,"Wpisz iloœæ","Nie posiadasz tyle przedmiotów danego typu !\nWpisz now¹ wartoœæ","Wyrzuæ","Anuluj");
					return 1;
				}
				if(howMuch == 0)
				{
					ShowPlayerDialog(playerid,DIALOG_ITEM_REMOVE,DIALOG_STYLE_INPUT,"Wpisz iloœæ","Poda³eœ b³êdn¹ wartoœæ\nWpisz now¹","Wyrzuæ","Anuluj");
					return 1;
				}
				if(SlotParam6(playerid, gSelectedSlot[playerid])-howMuch == 0)
				{
					RemovePlayerItem(playerid, gSelectedSlot[playerid]);
				}
				else
				{
					SetPSlotParam6(playerid, gSelectedSlot[playerid], SlotParam6(playerid, gSelectedSlot[playerid])-howMuch);
					InsertPlayerPickupItem(playerid, gSelectedSlot[playerid], howMuch); // tworze pickupa do podniesienie
				}
				format(string, sizeof(string), "[INFO:] Wyrzuci³eœ %d itemów", howMuch);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
				ShowPItems(playerid);
				return 1;
			}
			else
			{
				ShowPItems(playerid);
			}
		}
		case DIALOG_KANISTER:
		{
			if(response)
			{
				new Float:xpos, Float:ypos, Float:zpos, Float:carx, Float:cary, Float:carz;
				new serial = strval(inputtext);
				for(new i = 0; i < sizeof(gVehData); i++)
				{
					if(gVehData[i][CarSerial] == serial)
					{
						if(gVehData[i][CarFuel] == float(VehFTank(i+1)))
						{
							SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Bak tego pojazdu jest pe³ny !");
							return 1;
						}
						if(gVehData[i][EngineOn])
						{
							SendClientMessage(playerid, COLOR_LIGHTBLUE, "[INFO:] Wy³¹cz silnik zanim zatankujesz !");
							return 1;
						}
						if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT)
						{
							SendClientMessage(playerid, COLOR_LIGHTBLUE, "[INFO:] Musisz byæ przy pojeŸdzie !");
							return 1;
						}
						if(SlotParam2(playerid, gSelectedSlot[playerid]) != gVehData[i][Fuel])
						{
							SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ten kanister zawiera paliwo które nie jest przeznaczone do tego pojazdu");
							return 1;
						}
						GetPlayerPos(playerid,xpos,ypos,zpos);
						GetVehiclePos(i+1,carx,cary,carz);
						if(!PlayerToPoint(11.0, playerid, carx, cary, carz))
						{
							SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Jesteœ zbyt daleko od tego pojazdu !");
							return 1;
						}
						SetTimerEx("RefuelingVehicleCanister",DBVariables[1][varDValue] * floatround(float(VehFTank(i+1)) - gVehData[i][CarFuel]), false, "idfff", playerid, i+1, carx, cary, carz);
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Rozpoczê³eœ tankowanie");
						PlayerActionMessage(playerid, 15.0, "wlewa paliwo z kanistra");
						return 1;
					}
				}
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie ma takiego pojazdu !");
				return 1;
			}
			else
				ShowPlayerDialog(playerid,DIALOG_ITEM_2,DIALOG_STYLE_LIST,"Dzia³anie", DIALOG_KANISTER_TXT,"Akceptuj","Wróæ");
			return 1;
		}
		case DIALOG_KANISTER_REFUEL:
		{
			if(response)
			{
				new refillprice;
				new Float:posx, Float:posy, Float:posz;
				GetPlayerPos(playerid,posx,posy,posz);
				for(new i = 0; i < sizeof(GasStations); i++)
				{
					if(PlayerToPoint(10.0, playerid, GasStations[i][GSposX], GasStations[i][GSposY], GasStations[i][GSposZ]))
					{
						if(listitem == 0 && GasStations[i][PetrolResourceValue] <= 0)
						{
							SendClientMessage(playerid, COLOR_RED, "[INFO:] Brak zasobów na stacji !");
							return 1;
						}
						else if(listitem == 1 && GasStations[i][OilResourceValue] <= 0)
						{
							SendClientMessage(playerid, COLOR_RED, "[INFO:] Brak zasobów na stacji !");
							return 1;
						}
						if(listitem == 0)
						{
							SetPSlotParam2(playerid, gSelectedSlot[playerid], 0);
							SaveStatsData("kanister-benzyna", gPlayerData[playerid][pName], refillprice, GasStations[i][BusinessID], Businesses[GasStations[i][BusinessID]][BizType]);
						}							
						else if(listitem == 1)
						{
							SetPSlotParam2(playerid, gSelectedSlot[playerid], 1);
							SaveStatsData("kanister-diesel", gPlayerData[playerid][pName], refillprice, GasStations[i][BusinessID], Businesses[GasStations[i][BusinessID]][BizType]);
						}							
						RefuelingCanister(playerid, 0.0, gSelectedSlot[playerid], i, posx, posy, posz);
						return 1;
					}
				}
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie znajdujesz siê na stacji beznynowej !");
				return 1;
			}
			else
				ShowPlayerDialog(playerid,DIALOG_ITEM_2,DIALOG_STYLE_LIST,"Dzia³anie", DIALOG_KANISTER_TXT,"Akceptuj","Wróæ");
			return 1;				
		}
		case DIALOG_BUY_PHONE:
		{
			if(response)
			{
				for(new i = 0; i < sizeof(Businesses); i++)
				{
					if (PlayerToPoint(25.0, playerid,Businesses[i][ExitX], Businesses[i][ExitY], Businesses[i][ExitZ]))
					{
						if(GetPlayerVirtualWorld(playerid) == i)
						{
							if(listitem == 0)
							{
								if(GetPlayerCash(playerid) < 650)
								{
									SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie masz wystarczaj¹cej iloœci pieniêdzy");
									return 1;
								}
								gRandNumber[playerid] = 600000000 + random(999999);
								gPhoneC[playerid] = i;
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Trwa generowanie numeru...");
								format(string, sizeof(string), "SELECT `Nr` FROM `samp_phones` WHERE `Nr` = '%d'",gRandNumber[playerid]);
								mysql_query(string, CHECK_PHONE, playerid, db_con2);
								return 1;
							}
						}
					}
				}
			}
		}
		case DIALOG_PHONE:
		{
			if(response)
			{
				if(gPlayerData[playerid][pCharacterDying] > 0)
				{
					SendClientMessage(playerid, COLOR_RED, "[INFO:] Twoja postaæ jest nieprzytomna. Nie mo¿esz teraz u¿yæ telefonu.");
				}
				if(gPlayerData[playerid][pJailed] != 0)
				{
					SendClientMessage(playerid, COLOR_RED, "[B£¥D:] Twój telefon zosta³ skonfiskowany ! Odzyskasz go po wyjœciu z wiêzienia");
					return 1;
				}
				new giveplayerid;
				new giveplayeridslot;
				new number;
				if(PHaveItem(playerid, 1, 4) > 0)
				{
					giveplayerid = gSelectedNumberID[playerid];
					if(IsPlayerConnected(giveplayerid) == 0)
					{
						SendClientMessage(playerid, COLOR_RED, "[INFO:] Dany gracz nie jest on-line !");
						return 1;
					}
					
					gSelectedSlot[playerid] = listitem+1;
					number = SlotParam2(giveplayerid, gSelectedSlot[playerid]);
					if(gSendingSMS[playerid])
					{
						ShowPlayerDialog(playerid,DIALOG_SMS,DIALOG_STYLE_INPUT,"Treœæ SMS","Wpisz tutaj treœæ swojego SMSa","Wyœlij","Anuluj");
						return 1;
					}
				}
				else
				{
					number = strval(inputtext);
					foreach(Player, i )
					{
						if(gPlayerLogged[i])
						{
							giveplayeridslot = PHaveItem(i, 3, 3);
							if(giveplayeridslot > 0)
							{
								giveplayerid = i;
								if(SlotParam2(giveplayerid, giveplayeridslot) == number)
								{
									if(SlotParam1(giveplayerid, giveplayeridslot) == 0)
									{
										SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[OPERATOR:] Telefon tego u¿ytkownika jest wy³¹czony lub poza zasiegiem, prosimy zadzwoniæ póŸniej.");
										return 1;
									}
									gSelectedSlot[playerid] = giveplayeridslot;
									gSelectedNumber[playerid] = number;
									gSelectedNumberID[playerid] = giveplayerid;
									if(gSendingSMS[playerid])
									{
										ShowPlayerDialog(playerid,DIALOG_SMS,DIALOG_STYLE_INPUT,"Treœæ SMS","Wpisz tutaj treœæ swojego SMSa","Wyœlij","Anuluj");
										return 1;
									}			
								}
							}
						}
					}
				}				
				if(number == 555)
				{
					SendClientMessage(playerid, COLOR_WHITE, "Operator: Witamy, Warsztat Samochodowy SF, zg³oszenie przyjête, prosimy o cierpliwoœæ.");
					new location[MAX_ZONE_NAME];
					GetPlayer2DZone(playerid, location, MAX_ZONE_NAME);
					format(string, sizeof(string), "[Warsztat Samochodowy] Osoba potrzebuje pomocy mechanika %s - Lokacja: %s.", GetPlayerNameEx(playerid),location);
					SendJobMessage(17, 0xFFFF00AA,string);
					new Float:x,Float:y,Float:z;
					GetPlayerPos(playerid,x,y,z);
					PhoneAnimation(playerid);
					foreach(Player, i )
					{
						if(gPlayerData[i][pJob] == 17 && gPlayerData[i][pGPS] == 1)
						{
							SetPlayerCheckpoint(i,x,y,z,10.0);
							ClearCheckpointsForPlayer(playerid);
						}
					}
					return 1;
				}
				if(number == 997)
				{
					new Float:x,Float:y,Float:z;
					new location[MAX_ZONE_NAME];
					for( new n = 0; n < CUSTOM_MAX_PLAYERS; n++ )
					{
						if(gPlayerData[n][pFaction] == 0 && IsPlayerConnected(n))
						{
							SendClientMessage(playerid, COLOR_WHITE, "[Operator:] Komisariat policji w SF, w czym moge pomóc ?.");
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Opisz swój problem w jednym zdaniu.");
							Mobile[playerid] = 997;
							GetPlayer2DZone(playerid, location, MAX_ZONE_NAME);
							format(string, sizeof(string), "[Policja] Osoba potrzebuje pomocy %s - Lokacja: %s.", GetPlayerNameEx(playerid),location);
							SendFactionMessage(0, COLOR_LSPD,string);
							GetPlayerPos(playerid,x,y,z);
							if(!IsPlayerInAnyVehicle(playerid))
							{
								SetPlayerSpecialAction(playerid,SPECIAL_ACTION_USECELLPHONE);
								SetPlayerAttachedObject(playerid, 4, 330, 6);
							}
							for(new i = 0; i < CUSTOM_MAX_PLAYERS; i++)
							{
								if(gPlayerData[i][pFaction] == 0 && gPlayerData[i][pGPS] == 1)
								{
									SetPlayerCheckpoint(i,x,y,z,10.0);
									ClearCheckpointsForPlayer(playerid);
								}
							}
							break;
						}
						if(n == CUSTOM_MAX_PLAYERS-1)
						{
							SendClientMessage(playerid, COLOR_WHITE, "[Operator:] Komisariat policji w SF, przepraszamy, niestety w tym momencie nie dysponujemy ¿adnymi wolnymi jednostkami wsparcia.");
							break;
						}
					}
					return 1;
				}
				if(number == 999)
				{
					new Float:x,Float:y,Float:z;
					new location[MAX_ZONE_NAME];
					for(new i = 0; i < CUSTOM_MAX_PLAYERS; i++)
					{
						if(gPlayerData[i][pFaction] == 2)
						{
							SendClientMessage(playerid, COLOR_WHITE, "[Operator:] Pogotowie w SF, zg³oszenie przyjête.");
							GetPlayer2DZone(playerid, location, MAX_ZONE_NAME);
							format(string, sizeof(string), "[Pogotowie] Osoba potrzebuje pomocy %s - Lokacja: %s.", GetPlayerNameEx(playerid),location);
							SendFactionMessage(2, 0xFFFF00AA,string);
							GetPlayerPos(playerid,x,y,z);
							PhoneAnimation(playerid);
							for(new n = 0; n < CUSTOM_MAX_PLAYERS; n++)
							{
								if(gPlayerData[n][pFaction] == 2 && gPlayerData[n][pGPS] == 1)
								{
									SetPlayerCheckpoint(n,x,y,z,10.0);
									ClearCheckpointsForPlayer(playerid);
								}
							}
							break;
						}
						if(i == CUSTOM_MAX_PLAYERS-1)
						{
							SendClientMessage(playerid, COLOR_WHITE, "[Operator:] Przepraszamy, niestety w regionie w którym siê znajdujesz nie ma wolnej karetki.");
							break;
						}
					}
					return 1;
				}
				if(number == 411)
				{
					SendClientMessage(playerid, COLOR_WHITE, "Operator: Witamy, firma Halo Taxi, przyjeliœmy zg³oszenie, prosimy o cierpliwoœæ.");
					//SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Proszê chwileczke poczekaæ, wiadomoœæ zaraz dotrze do taksówkarzy !");
					new location[MAX_ZONE_NAME];
					GetPlayer2DZone(playerid, location, MAX_ZONE_NAME);
					format(string, sizeof(string), "[TAXI CO.] Osoba potrzebuje taxówki %s - Lokacja: %s.", GetPlayerNameEx(playerid),location);
					SendFactionMessage(4, 0xFFFF00AA,string);
					new Float:x,Float:y,Float:z;
					GetPlayerPos(playerid,x,y,z);
					PhoneAnimation(playerid);
					for(new i = 0; i < CUSTOM_MAX_PLAYERS; i++)
					{
						if(gPlayerData[i][pFaction] == 4 && gPlayerData[i][pGPS])
						{
							SetPlayerCheckpoint(i,x,y,z,10.0);
							ClearCheckpointsForPlayer(playerid);
						}
					}
					return 1;
				}
				if(Mobile[playerid] != 255)
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Jesteœ ju¿ po³¹czony.");
					return 1;
				}
				if(PHaveItem(playerid, 1, 4) > 0)
				{
					if(SlotParam1(giveplayerid, gSelectedSlot[playerid]) == 0)
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[OPERATOR:] Telefon tego u¿ytkownika jest wy³¹czony lub poza zasiêgiem, prosimy zadzwoniæ póŸniej.");
						return 1;
					}
					if(giveplayerid == playerid)
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[OPERATOR:] Telefon tego u¿ytkownika jest wy³¹czony lub poza zasiêgiem, prosimy zadzwoniæ póŸniej.");
						return 1;
					}
					if(Mobile[giveplayerid] == 255 && IncommingCall[giveplayerid] == 0)
					{
						Mobile[playerid] = giveplayerid; //caller connecting
						IncommingCall[giveplayerid] = 1;

						StartedCall[playerid] = 1;
						StartedCall[giveplayerid] = 0;						
						gCallCost[playerid] = 2;						
						gCalledCompany[playerid] = SlotParam3(playerid, gSelectedSlot[playerid]);

						format(string, sizeof(string), "[TELEFON:] Ring... Ring...");
						SendClientMessage(giveplayerid, COLOR_LIGHTGREEN, string);

						if(!IsPlayerInAnyVehicle(playerid))
						{
							SetPlayerSpecialAction(playerid,SPECIAL_ACTION_USECELLPHONE);
							SetPlayerAttachedObject(playerid, 4, 330, 6);
						}
						return 1;
					}
				}
				else
				{
					if(number == SlotParam2(playerid, gSelectedSlot[playerid]))
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Linia jest zajêta.");
						return 1;
					}
					for(new i = 0; i < CUSTOM_MAX_PLAYERS; i++)
					{
						if(IsPlayerConnected(i) && gPlayerLogged[i])
						{
							giveplayeridslot = PHaveItem(i, 3, 3);
							if(giveplayeridslot > 0)
							{
								giveplayerid = i;
								if(SlotParam2(giveplayerid, giveplayeridslot) == number)
								{
									if(SlotParam1(giveplayerid, giveplayeridslot) == 0)
									{
										SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[OPERATOR:] Telefon tego u¿ytkownika jest wy³¹czony lub poza zasiegiem, prosimy zadzwoniæ póŸniej.");
										return 1;
									}
									if(Mobile[giveplayerid] == 255 && IncommingCall[giveplayerid] == 0)
									{
										Mobile[playerid] = giveplayerid; //caller connecting
										IncommingCall[giveplayerid] = 1;

										StartedCall[playerid] = 1;
										StartedCall[giveplayerid] = 0;
										gCallCost[playerid] = 2;						
										gCalledCompany[playerid] = SlotParam3(playerid, gSelectedSlot[playerid]);

										format(string, sizeof(string), "[TELEFON:] Ring... Ring...");
										SendClientMessage(giveplayerid, COLOR_LIGHTGREEN, string);

										if(!IsPlayerInAnyVehicle(playerid))
										{
											SetPlayerSpecialAction(playerid,SPECIAL_ACTION_USECELLPHONE);
											SetPlayerAttachedObject(playerid, 4, 330, 6);
										}
										return 1;
									}
								}
							}
							giveplayeridslot = PHaveItem(i, 3, 4);
							if(giveplayeridslot > 0)
							{
								giveplayerid = i;
								if(SlotParam2(giveplayerid, giveplayeridslot) == number)
								{
									if(SlotParam1(giveplayerid, giveplayeridslot) == 0)
									{
										SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[OPERATOR:] Telefon tego u¿ytkownika jest wy³¹czony lub poza zasiegiem, prosimy zadzwoniæ póŸniej.");
										return 1;
									}
									if(Mobile[giveplayerid] == 255 && IncommingCall[giveplayerid] == 0)
									{
										Mobile[playerid] = giveplayerid; //caller connecting
										IncommingCall[giveplayerid] = 1;

										StartedCall[playerid] = 1;
										StartedCall[giveplayerid] = 0;
										gCallCost[playerid] = 2;						
										gCalledCompany[playerid] = SlotParam3(playerid, gSelectedSlot[playerid]);

										format(string, sizeof(string), "[TELEFON:] Ring... Ring...");
										SendClientMessage(giveplayerid, COLOR_LIGHTGREEN, string);

										if(!IsPlayerInAnyVehicle(playerid))
										{
											SetPlayerSpecialAction(playerid,SPECIAL_ACTION_USECELLPHONE);
											SetPlayerAttachedObject(playerid, 4, 330, 6);
										}
										if(!IsPlayerInAnyVehicle(giveplayerid))
										{
											SetPlayerSpecialAction(giveplayerid,SPECIAL_ACTION_USECELLPHONE);
											SetPlayerAttachedObject(giveplayerid, 4, 330, 6);
										}
										return 1;
									}
								}
							}
						}
					}
				}
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Linia jest zajêta.");
			}
		}
		case DIALOG_PHONE2:
		{
			if(response)
			{
				new number;
				switch(listitem)
				{
					case 0: { if(gPhoneBookNumber[playerid][ln1] == 0) { return 1; } else { number = gPhoneBookNumber[playerid][ln1]; } }
					case 1:	{ if(gPhoneBookNumber[playerid][ln2] == 0) { return 1; } else { number = gPhoneBookNumber[playerid][ln2]; } }
					case 2:	{ if(gPhoneBookNumber[playerid][ln3] == 0) { return 1; } else {	number = gPhoneBookNumber[playerid][ln3]; } }
					case 3:	{ if(gPhoneBookNumber[playerid][ln4] == 0) { return 1; } else { number = gPhoneBookNumber[playerid][ln4]; } }
					case 4:	{ if(gPhoneBookNumber[playerid][ln5] == 0) { return 1; } else { number = gPhoneBookNumber[playerid][ln5]; } }
					case 5:	{ if(gPhoneBookNumber[playerid][ln6] == 0) { return 1; } else { number = gPhoneBookNumber[playerid][ln6]; } }
					case 6:	{ if(gPhoneBookNumber[playerid][ln7] == 0) { return 1; } else { number = gPhoneBookNumber[playerid][ln7]; } }
					case 7:	{ if(gPhoneBookNumber[playerid][ln8] == 0) { return 1; } else { number = gPhoneBookNumber[playerid][ln8]; } }
					case 8:	{ if(gPhoneBookNumber[playerid][ln9] == 0) { return 1; } else { number = gPhoneBookNumber[playerid][ln9]; } }
					case 9:	{ if(gPhoneBookNumber[playerid][ln10] == 0) { return 1; } else { number = gPhoneBookNumber[playerid][ln10]; } }
				}
				format(string, sizeof(string), "[INFO:] Numer telefonu: %d", number);
				SendClientMessage(playerid, COLOR_WHITE, string);
			}
		}
		case DIALOG_PHONE_BOOK:
		{
			if(response)
			{
				new giveplayerid = strval(inputtext);
				if(!IsPlayerConnected(giveplayerid) && giveplayerid == INVALID_PLAYER_ID)
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Niew³aœciwe ID/nazwa gracza.");
					return 1;
				}
				if(!gPlayerLogged[giveplayerid])
				{
					SendClientMessage(playerid, COLOR_LIGHTGREEN, "[B£¥D:] Ten gracz nie jest zalogowany");
					return 1;
				}
				if(gPlayerData[giveplayerid][pListNumber] == 0)
				{
					SendClientMessage(playerid, COLOR_RED, "[INFO:] Ta osoba zastrzeg³a swoje numery");
					return 1;
				}
				new p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18, p19, p20, p21, p22, p23, p24, p25;
				gSelectedNumberID[playerid] = giveplayerid;
				if(gPlayerData[giveplayerid][pItem1type] == 3 && (gPlayerData[giveplayerid][pItem1] == 3 || gPlayerData[giveplayerid][pItem1] == 4)) { p1 = gPlayerData[giveplayerid][pItem1param2]; }
				if(gPlayerData[giveplayerid][pItem2type] == 3 && (gPlayerData[giveplayerid][pItem2] == 3 || gPlayerData[giveplayerid][pItem2] == 4)) { p2 = gPlayerData[giveplayerid][pItem2param2]; }
				if(gPlayerData[giveplayerid][pItem3type] == 3 && (gPlayerData[giveplayerid][pItem3] == 3 || gPlayerData[giveplayerid][pItem3] == 4)) { p3 = gPlayerData[giveplayerid][pItem3param2]; }
				if(gPlayerData[giveplayerid][pItem4type] == 3 && (gPlayerData[giveplayerid][pItem4] == 3 || gPlayerData[giveplayerid][pItem4] == 4)) { p4 = gPlayerData[giveplayerid][pItem4param2]; }
				if(gPlayerData[giveplayerid][pItem5type] == 3 && (gPlayerData[giveplayerid][pItem5] == 3 || gPlayerData[giveplayerid][pItem5] == 4)) { p5 = gPlayerData[giveplayerid][pItem5param2]; }
				if(PHaveExpandItem(giveplayerid) || gPlayerData[giveplayerid][pVipItem] > 0)
				{
					if(gPlayerData[giveplayerid][pItem6type] == 3 && (gPlayerData[giveplayerid][pItem6] == 3 || gPlayerData[giveplayerid][pItem6] == 4)) { p6 = gPlayerData[giveplayerid][pItem6param2]; }
					if(gPlayerData[giveplayerid][pItem7type] == 3 && (gPlayerData[giveplayerid][pItem7] == 3 || gPlayerData[giveplayerid][pItem7] == 4)) { p7 = gPlayerData[giveplayerid][pItem7param2]; }
					if(gPlayerData[giveplayerid][pItem8type] == 3 && (gPlayerData[giveplayerid][pItem8] == 3 || gPlayerData[giveplayerid][pItem8] == 4)) { p8 = gPlayerData[giveplayerid][pItem8param2]; }
					if(gPlayerData[giveplayerid][pItem9type] == 3 && (gPlayerData[giveplayerid][pItem9] == 3 || gPlayerData[giveplayerid][pItem9] == 4)) { p9 = gPlayerData[giveplayerid][pItem9param2]; }					
					if(gPlayerData[giveplayerid][pItem10type] == 3 && (gPlayerData[giveplayerid][pItem10] == 3 || gPlayerData[giveplayerid][pItem10] == 4)) { p10 = gPlayerData[giveplayerid][pItem10param2]; }
					if(gPlayerData[giveplayerid][pItem11type] == 3 && (gPlayerData[giveplayerid][pItem11] == 3 || gPlayerData[giveplayerid][pItem11] == 4)) { p11 = gPlayerData[giveplayerid][pItem11param2]; }
					if(gPlayerData[giveplayerid][pItem12type] == 3 && (gPlayerData[giveplayerid][pItem12] == 3 || gPlayerData[giveplayerid][pItem12] == 4)) { p12 = gPlayerData[giveplayerid][pItem12param2]; }
					if(gPlayerData[giveplayerid][pItem13type] == 3 && (gPlayerData[giveplayerid][pItem13] == 3 || gPlayerData[giveplayerid][pItem13] == 4)) { p13 = gPlayerData[giveplayerid][pItem13param2]; }
					if(gPlayerData[giveplayerid][pItem14type] == 3 && (gPlayerData[giveplayerid][pItem14] == 3 || gPlayerData[giveplayerid][pItem14] == 4)) { p14 = gPlayerData[giveplayerid][pItem14param2]; }
					if(gPlayerData[giveplayerid][pItem15type] == 3 && (gPlayerData[giveplayerid][pItem15] == 3 || gPlayerData[giveplayerid][pItem15] == 4)) { p15 = gPlayerData[giveplayerid][pItem15param2]; }
					if(gPlayerData[giveplayerid][pVipItem] > 0)
					{
						if(gPlayerData[giveplayerid][pItem16type] == 3 && (gPlayerData[giveplayerid][pItem16] == 3 || gPlayerData[giveplayerid][pItem16] == 4)) { p16 = gPlayerData[giveplayerid][pItem16param2]; }
						if(gPlayerData[giveplayerid][pItem17type] == 3 && (gPlayerData[giveplayerid][pItem17] == 3 || gPlayerData[giveplayerid][pItem17] == 4)) { p17 = gPlayerData[giveplayerid][pItem17param2]; }
						if(gPlayerData[giveplayerid][pItem18type] == 3 && (gPlayerData[giveplayerid][pItem18] == 3 || gPlayerData[giveplayerid][pItem18] == 4)) { p18 = gPlayerData[giveplayerid][pItem18param2]; }
						if(gPlayerData[giveplayerid][pItem19type] == 3 && (gPlayerData[giveplayerid][pItem19] == 3 || gPlayerData[giveplayerid][pItem19] == 4)) { p19 = gPlayerData[giveplayerid][pItem19param2]; }
						if(gPlayerData[giveplayerid][pItem20type] == 3 && (gPlayerData[giveplayerid][pItem20] == 3 || gPlayerData[giveplayerid][pItem20] == 4)) { p20 = gPlayerData[giveplayerid][pItem20param2]; }
						if(gPlayerData[giveplayerid][pItem21type] == 3 && (gPlayerData[giveplayerid][pItem21] == 3 || gPlayerData[giveplayerid][pItem21] == 4)) { p21 = gPlayerData[giveplayerid][pItem21param2]; }
						if(gPlayerData[giveplayerid][pItem22type] == 3 && (gPlayerData[giveplayerid][pItem22] == 3 || gPlayerData[giveplayerid][pItem22] == 4)) { p22 = gPlayerData[giveplayerid][pItem22param2]; }
						if(gPlayerData[giveplayerid][pItem23type] == 3 && (gPlayerData[giveplayerid][pItem23] == 3 || gPlayerData[giveplayerid][pItem23] == 4)) { p23 = gPlayerData[giveplayerid][pItem23param2]; }
						if(gPlayerData[giveplayerid][pItem24type] == 3 && (gPlayerData[giveplayerid][pItem24] == 3 || gPlayerData[giveplayerid][pItem24] == 4)) { p24 = gPlayerData[giveplayerid][pItem24param2]; }
						if(gPlayerData[giveplayerid][pItem25type] == 3 && (gPlayerData[giveplayerid][pItem25] == 3 || gPlayerData[giveplayerid][pItem25] == 4)) { p25 = gPlayerData[giveplayerid][pItem25param2]; }
						format(string, sizeof(string), "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d", 
							p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18, p19, p20, p21, p22, p23, p24, p25);	
					}
					else
						format(string, sizeof(string), "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d", p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15);					
				}
				else
					format(string, sizeof(string), "%d\n%d\n%d\n%d\n%d", p1, p2, p3, p4, p5);
				
				ShowPlayerDialog(playerid,DIALOG_PHONE,DIALOG_STYLE_LIST,"Nr telefonów",string,"Po³¹cz","Anuluj");
				
				PlayerActionMessage(playerid, 15.0, "przegl¹da ksi¹¿ke telefoniczn¹");
			}
		}
		case DIALOG_SMS:
		{
			if(response)
			{
				new giveplayerid;
				new giveplayeridslot;
				new number;
				if(PHaveItem(playerid, 1, 4) > 0)
				{
					giveplayerid = gSelectedNumberID[playerid];
					giveplayeridslot = gSelectedSlot[playerid];
					number = SlotParam2(giveplayerid, giveplayeridslot);
				}
				else
				{
					giveplayerid = gSelectedNumberID[playerid];
					giveplayeridslot = gSelectedSlot[playerid];
					number = gSelectedNumber[playerid];			
				}
				if(!strlen(inputtext))
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Wiadomoœæ musi zawieraæ treœæ !");
					return 1;
				}
				if(SlotParam1(giveplayerid, giveplayeridslot) == 0)
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[OPERATOR:] Telefon tego u¿ytkownika jest wy³¹czony lub poza zasiegiem, prosimy zadzwoniæ póŸniej.");
					return 1;
				}
				format(string, sizeof(string), "[TXT:] OD: %s (%d), WIADOMOŒÆ: %s", gPlayerData[playerid][pName],SlotParam2(playerid, gSelectedSlot[playerid]),inputtext);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Wiadomoœæ wys³ana.");
				SendClientMessage(giveplayerid, COLOR_LIGHTGREEN, string);
				format(string, sizeof(string), "[TXT:] DO: %s (%d), WIADOMOŒÆ: %s", gPlayerData[giveplayerid][pName],number,inputtext);
				SendClientMessage(playerid,  COLOR_LIGHTGREEN, string);
				PhoneAnimation(playerid);
				SMSLog(string);
				GivePlayerCash(playerid,-SMS_COST);
				Businesses[SlotParam3(playerid, gSelectedSlot[playerid])][Till] += SMS_COST;
				return 1;
			}
		}
		case DIALOG_PHONE_ALARMS:
		{
			if(response)
			{
				if(gPlayerData[playerid][pCharacterDying] > 0)
				{
					ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Twoja postaæ jest nieprzytomna, nie mo¿esz u¿yæ telefonu !", "Zamknij", "" );
					return 1;
				}
				if(gPlayerData[playerid][pJailed] != 0)
				{
					SendClientMessage(playerid, COLOR_RED, "[B£¥D:] Twój telefon zosta³ skonfiskowany ! Odzyskasz go po wyjœciu z wiêzienia");
					return 1;
				}
				new number;
				switch(listitem)
				{
					case 0: number = 999;
					case 1: number = 997;
					case 2: number = 555;
				}
				if(number == 555)
				{
					SendClientMessage(playerid, COLOR_WHITE, "[TELEFON:] Witamy, Warsztat Samochodowy, zg³oszenie przyjête, prosimy o cierpliwoœæ.");
					new location[MAX_ZONE_NAME];
					GetPlayer2DZone(playerid, location, MAX_ZONE_NAME);
					format(string, sizeof(string), "[RADIO:] Osoba potrzebuje pomocy mechanika %s - Lokacja: %s.", GetPlayerNameEx(playerid),location);
					SendJobMessage(17, 0xFFFF00AA,string);
					new Float:x,Float:y,Float:z;
					GetPlayerPos(playerid,x,y,z);
					PhoneAnimation(playerid);
					for(new i = 0; i < CUSTOM_MAX_PLAYERS; i++)
					{
						if(gPlayerData[i][pJob] == 17 && gPlayerData[i][pGPS] == 1)
						{
							SetPlayerCheckpoint(i,x,y,z,10.0);
							ClearCheckpointsForPlayer(playerid);
						}
					}
					return 1;
				}
				if(number == 997)
				{
					new Float:x,Float:y,Float:z;
					new location[MAX_ZONE_NAME];
					for(new n = 0; n < CUSTOM_MAX_PLAYERS; n++)
					{
						if(gPlayerData[n][pFaction] == 0 && IsPlayerConnected(n))
						{
							SendClientMessage(playerid, COLOR_WHITE, "[TELEFON:] Komisariat policji, w czym moge pomóc ?.");
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Opisz swój problem w jednym zdaniu.");
							Mobile[playerid] = 997;
							GetPlayer2DZone(playerid, location, MAX_ZONE_NAME);
							format(string, sizeof(string), "[RADIO:] Osoba potrzebuje pomocy %s - Lokacja: %s.", GetPlayerNameEx(playerid),location);
							SendFactionMessage(0, COLOR_LSPD,string);
							GetPlayerPos(playerid,x,y,z);
							if(!IsPlayerInAnyVehicle(playerid))
							{
								SetPlayerSpecialAction(playerid,SPECIAL_ACTION_USECELLPHONE);
								SetPlayerAttachedObject(playerid, 4, 330, 6);
							}
							for(new i = 0; i < CUSTOM_MAX_PLAYERS; i++)
							{
								if(gPlayerData[i][pFaction] == 0 && gPlayerData[i][pGPS] == 1)
								{
									SetPlayerCheckpoint(i,x,y,z,10.0);
									ClearCheckpointsForPlayer(playerid);
								}
							}
							break;
						}
						if(n == CUSTOM_MAX_PLAYERS-1)
						{
							SendClientMessage(playerid, COLOR_WHITE, "[Operator:] Komisariat policji, przepraszamy, niestety w tym momencie nie dysponujemy ¿adnymi wolnymi jednostkami wsparcia.");
							break;
						}
					}
					return 1;
				}
				if(number == 999)
				{
					new Float:x,Float:y,Float:z;
					new location[MAX_ZONE_NAME];
					for(new i = 0; i < CUSTOM_MAX_PLAYERS; i++)
					{
						if(gPlayerData[i][pFaction] == 2)
						{
							SendClientMessage(playerid, COLOR_WHITE, "[TELEFON:] Pogotowie, zg³oszenie przyjête.");
							GetPlayer2DZone(playerid, location, MAX_ZONE_NAME);
							format(string, sizeof(string), "[RADIO:] Osoba potrzebuje pomocy %s - Lokacja: %s.", GetPlayerNameEx(playerid),location);
							SendFactionMessage(2, 0xFFFF00AA,string);
							GetPlayerPos(playerid,x,y,z);
							PhoneAnimation(playerid);
							for(new n = 0; n < CUSTOM_MAX_PLAYERS; n++)
							{
								if(gPlayerData[n][pFaction] == 2 && gPlayerData[n][pGPS] == 1)
								{
									SetPlayerCheckpoint(n,x,y,z,10.0);
									ClearCheckpointsForPlayer(playerid);
								}
							}
							break;
						}
						if(i == CUSTOM_MAX_PLAYERS-1)
						{
							SendClientMessage(playerid, COLOR_WHITE, "[Operator:] Przepraszamy, niestety w regionie w którym siê znajdujesz nie ma wolnej karetki.");
							break;
						}
					}
					return 1;
				}
			}
		}
		case DIALOG_WANTED:
		{
			if(response)
			{
				format(string, sizeof(string), "SELECT * FROM `samp_wanted` WHERE `PlayerName` = '%s'", inputtext);
				mysql_query(string, SHOW_WANTED_LIST, playerid, db_con2);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Wyszukiwanie...");
			}
		}
		case DIALOG_LOGIN:
		{
			if(response)
			{
				if(gLoginOn)
					OnPlayerLogin(playerid, inputtext);
				else
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Logowanie zosta³o wy³¹czone przez administratora, wróæ póŸniej !");
					return 1;
				}
			}
			else
			{
				new tmpstr[1024];
				strcat( tmpstr, "{FFFFFF}Witaj na serwerze WParty !\n\n" );
				strcat( tmpstr, "Aby siê zalogowaæ wpisz swoje has³o do postaci.\n\n\n" );
				strcat( tmpstr, "{F52222}Jeœli nie posiadasz jeszcze postaci musisz wpierw zarejestrowaæ swoje konto\nna forum wpartyrp.pl a nastêpnei utworzyæ postaæ\npostêpuj¹æ wed³ug podanych tam wskazówek.\n\n" );
				strcat( tmpstr, "{FAEC25}Jeœli zapomnia³eœ has³a do postaci mo¿esz je zmieniæ loguj¹c siê na forum\na nastêpnie przechodz¹c do panelu zarz¹dzania postaciami.\n\n\n" );
				strcat( tmpstr, "{FFFFFF}Wpisz has³o:" );
				ShowPlayerDialog(playerid, DIALOG_LOGIN, DIALOG_STYLE_PASSWORD, "Logowanie", tmpstr, "Zaloguj", "");
			}
		}
		/*case FWCPM:
		{
			if(response == 0) return SendClientMessage(playerid, WHITE, "[NotimeBot]: You closed the Fire Work Control Panel");
			if(response == 1)
			{
				switch (listitem)
				{
					case 0: //DrawDistance
					{
						ShowPlayerDialog(playerid, FWCPDD, DIALOG_STYLE_LIST, "FireWork Control Panel > -Draw Distance Setting-", "Low\nMedium\nHigh", "Select", "Back");
						return 1;
					}
					case 1://Firecracker
					{
						ShowPlayerDialog(playerid, FWCPFC, DIALOG_STYLE_LIST, "FireWork Control Panel > -FireCracker Usable for:-", "Usable for all players\nUsable for Rcon Admins only", "Select", "Back");
						return 1;
					}
					case 2://Firerocket1
					{
						ShowPlayerDialog(playerid, FWCPFR1, DIALOG_STYLE_LIST, "FireWork Control Panel > -FireRocket1 Usable for:-", "Usable for all players\nUsable for Rcon Admins only", "Select", "Back");
						return 1;
					}
					case 3://Firerocket2
					{
						ShowPlayerDialog(playerid, FWCPFR2, DIALOG_STYLE_LIST, "FireWork Control Panel > -FireRocket2 Usable for:-", "Usable for all players\nUsable for Rcon Admins only", "Select", "Back");
						return 1;
					}
					case 4://Crackerroll
					{
						ShowPlayerDialog(playerid, FWCPCR, DIALOG_STYLE_LIST, "FireWork Control Panel > -CrackerRoll Usable for:-", "Usable for all players\nUsable for Rcon Admins only", "Select", "Back");
						return 1;
					}
					case 5://Fountain1
					{
						ShowPlayerDialog(playerid, FWCPFT1, DIALOG_STYLE_LIST, "FireWork Control Panel > -Fountain1 Usable for:-", "Usable for all players\nUsable for Rcon Admins only", "Select", "Back");
						return 1;
					}
					case 6://Fountain2
					{
						ShowPlayerDialog(playerid, FWCPFT2, DIALOG_STYLE_LIST, "FireWork Control Panel > -Fountain2 Usable for:-", "Usable for all players\nUsable for Rcon Admins only", "Select", "Back");
						return 1;
					}
					case 7://Fountain3
					{
						ShowPlayerDialog(playerid, FWCPFT3, DIALOG_STYLE_LIST, "FireWork Control Panel > -Fountain3 Usable for:-", "Usable for all players\nUsable for Rcon Admins only", "Select", "Back");
						return 1;
					}
					case 8://RocketBox
					{
						ShowPlayerDialog(playerid, FWCPRB, DIALOG_STYLE_LIST, "FireWork Control Panel > -RocketBox Usable for:-", "Usable for all players\nUsable for Rcon Admins only", "Select", "Back");
						return 1;
					}
				}
				return 1;
			}
			return 1;
		}
		case FWCPDD:
		{
			if(response == 0)
			{
				format(string2, sizeof(string2), "DrawDistance: %s\nFire Cracker: %s\nFirerocket1: %s\nFirerocket2: %s\nCrackerRoll: %s\nFountain1: %s\nFountain2: %s\nFountain3: %s\nRocketBox: %s",
				DrawDistanceWord[AllowedFirework[FWNDrawDistance]], UsageFW[AllowedFirework[FireCracker]], UsageFW[AllowedFirework[Firerocket1]], UsageFW[AllowedFirework[Firerocket2]], UsageFW[AllowedFirework[Crackerroll]], UsageFW[AllowedFirework[Fountain1]], UsageFW[AllowedFirework[Fountain2]], UsageFW[AllowedFirework[Fountain3]], UsageFW[AllowedFirework[RocketB]]);
				ShowPlayerDialog(playerid, FWCPM,2,"FireWork Control Panel", string2,"Select", "Close");
				return 1;
			}
			if(response == 1)
			{
				switch (listitem)
				{
					case 0: //Low DrawDistance
					{
						SendClientMessage(playerid, WHITE, "[FWCP]: Draw distance set to low.");
						AllowedFirework[FWNDrawDistance] = 0;
						format(string2, sizeof(string2), "DrawDistance: %s\nFire Cracker: %s\nFirerocket1: %s\nFirerocket2: %s\nCrackerRoll: %s\nFountain1: %s\nFountain2: %s\nFountain3: %s\nRocketBox: %s",
						DrawDistanceWord[AllowedFirework[FWNDrawDistance]], UsageFW[AllowedFirework[FireCracker]], UsageFW[AllowedFirework[Firerocket1]], UsageFW[AllowedFirework[Firerocket2]], UsageFW[AllowedFirework[Crackerroll]], UsageFW[AllowedFirework[Fountain1]], UsageFW[AllowedFirework[Fountain2]], UsageFW[AllowedFirework[Fountain3]], UsageFW[AllowedFirework[RocketB]]);
						ShowPlayerDialog(playerid, FWCPM,2,"FireWork Control Panel", string2,"Select", "Close");
						SaveFireWorkInfo();
						return 1;
					}
					case 1://Medium DrawDistance
					{
						SendClientMessage(playerid, WHITE, "[FWCP]: Draw distance set to medium.");
						AllowedFirework[FWNDrawDistance] = 1;
						format(string2, sizeof(string2), "DrawDistance: %s\nFire Cracker: %s\nFirerocket1: %s\nFirerocket2: %s\nCrackerRoll: %s\nFountain1: %s\nFountain2: %s\nFountain3: %s\nRocketBox: %s",
						DrawDistanceWord[AllowedFirework[FWNDrawDistance]], UsageFW[AllowedFirework[FireCracker]], UsageFW[AllowedFirework[Firerocket1]], UsageFW[AllowedFirework[Firerocket2]], UsageFW[AllowedFirework[Crackerroll]], UsageFW[AllowedFirework[Fountain1]], UsageFW[AllowedFirework[Fountain2]], UsageFW[AllowedFirework[Fountain3]], UsageFW[AllowedFirework[RocketB]]);
						ShowPlayerDialog(playerid, FWCPM,2,"FireWork Control Panel", string2,"Select", "Close");
						SaveFireWorkInfo();
						return 1;
					}
					case 2://High DrawDistance
					{
						SendClientMessage(playerid, WHITE, "[FWCP]: Draw distance set to High.");
						AllowedFirework[FWNDrawDistance] = 2;
						format(string2, sizeof(string2), "DrawDistance: %s\nFire Cracker: %s\nFirerocket1: %s\nFirerocket2: %s\nCrackerRoll: %s\nFountain1: %s\nFountain2: %s\nFountain3: %s\nRocketBox: %s",
						DrawDistanceWord[AllowedFirework[FWNDrawDistance]], UsageFW[AllowedFirework[FireCracker]], UsageFW[AllowedFirework[Firerocket1]], UsageFW[AllowedFirework[Firerocket2]], UsageFW[AllowedFirework[Crackerroll]], UsageFW[AllowedFirework[Fountain1]], UsageFW[AllowedFirework[Fountain2]], UsageFW[AllowedFirework[Fountain3]], UsageFW[AllowedFirework[RocketB]]);
						ShowPlayerDialog(playerid, FWCPM,2,"FireWork Control Panel", string2,"Select", "Close");
						SaveFireWorkInfo();
						return 1;
					}
				}
				return 1;
			}
			return 1;
		}
		case FWCPFC:
		{
			if(response == 0)
			{
				format(string2, sizeof(string2), "DrawDistance: %s\nFire Cracker: %s\nFirerocket1: %s\nFirerocket2: %s\nCrackerRoll: %s\nFountain1: %s\nFountain2: %s\nFountain3: %s\nRocketBox: %s",
				DrawDistanceWord[AllowedFirework[FWNDrawDistance]], UsageFW[AllowedFirework[FireCracker]], UsageFW[AllowedFirework[Firerocket1]], UsageFW[AllowedFirework[Firerocket2]], UsageFW[AllowedFirework[Crackerroll]], UsageFW[AllowedFirework[Fountain1]], UsageFW[AllowedFirework[Fountain2]], UsageFW[AllowedFirework[Fountain3]], UsageFW[AllowedFirework[RocketB]]);
				ShowPlayerDialog(playerid, FWCPM,2,"FireWork Control Panel", string2,"Select", "Close");
				return 1;
			}
			if(response == 1)
			{
				switch (listitem)
				{
					case 0: //FireCracker usable for all
					{
						SendClientMessage(playerid, WHITE, "[FWCP]: The Firecracker is now enabled for all players.");
						AllowedFirework[FireCracker] = 0;
						format(string2, sizeof(string2), "DrawDistance: %s\nFire Cracker: %s\nFirerocket1: %s\nFirerocket2: %s\nCrackerRoll: %s\nFountain1: %s\nFountain2: %s\nFountain3: %s\nRocketBox: %s",
						DrawDistanceWord[AllowedFirework[FWNDrawDistance]], UsageFW[AllowedFirework[FireCracker]], UsageFW[AllowedFirework[Firerocket1]], UsageFW[AllowedFirework[Firerocket2]], UsageFW[AllowedFirework[Crackerroll]], UsageFW[AllowedFirework[Fountain1]], UsageFW[AllowedFirework[Fountain2]], UsageFW[AllowedFirework[Fountain3]], UsageFW[AllowedFirework[RocketB]]);
						ShowPlayerDialog(playerid, FWCPM,2,"FireWork Control Panel", string2,"Select", "Close");
						SaveFireWorkInfo();
						return 1;
					}
					case 1://FireCracker usable for rcon only
					{
						SendClientMessage(playerid, WHITE, "[FWCP]: The Firecracker is now enabled for Rcon Admins only.");
						AllowedFirework[FireCracker] = 1;
						format(string2, sizeof(string2), "DrawDistance: %s\nFire Cracker: %s\nFirerocket1: %s\nFirerocket2: %s\nCrackerRoll: %s\nFountain1: %s\nFountain2: %s\nFountain3: %s\nRocketBox: %s",
						DrawDistanceWord[AllowedFirework[FWNDrawDistance]], UsageFW[AllowedFirework[FireCracker]], UsageFW[AllowedFirework[Firerocket1]], UsageFW[AllowedFirework[Firerocket2]], UsageFW[AllowedFirework[Crackerroll]], UsageFW[AllowedFirework[Fountain1]], UsageFW[AllowedFirework[Fountain2]], UsageFW[AllowedFirework[Fountain3]], UsageFW[AllowedFirework[RocketB]]);
						ShowPlayerDialog(playerid, FWCPM,2,"FireWork Control Panel", string2,"Select", "Close");
						SaveFireWorkInfo();
						return 1;
					}
				}
				return 1;
			}
			return 1;
		}
		case FWCPFR1:
		{
			if(response == 0)
			{
				format(string2, sizeof(string2), "DrawDistance: %s\nFire Cracker: %s\nFirerocket1: %s\nFirerocket2: %s\nCrackerRoll: %s\nFountain1: %s\nFountain2: %s\nFountain3: %s\nRocketBox: %s",
				DrawDistanceWord[AllowedFirework[FWNDrawDistance]], UsageFW[AllowedFirework[FireCracker]], UsageFW[AllowedFirework[Firerocket1]], UsageFW[AllowedFirework[Firerocket2]], UsageFW[AllowedFirework[Crackerroll]], UsageFW[AllowedFirework[Fountain1]], UsageFW[AllowedFirework[Fountain2]], UsageFW[AllowedFirework[Fountain3]], UsageFW[AllowedFirework[RocketB]]);
				ShowPlayerDialog(playerid, FWCPM,2,"FireWork Control Panel", string2,"Select", "Close");
				return 1;
			}
			if(response == 1)
			{
				switch (listitem)
				{
					case 0: //FireRocket1 usable for all
					{
						SendClientMessage(playerid, WHITE, "[FWCP]: The FireRocket 1 is now enabled for all players.");
						AllowedFirework[Firerocket1] = 0;
						format(string2, sizeof(string2), "DrawDistance: %s\nFire Cracker: %s\nFirerocket1: %s\nFirerocket2: %s\nCrackerRoll: %s\nFountain1: %s\nFountain2: %s\nFountain3: %s\nRocketBox: %s",
						DrawDistanceWord[AllowedFirework[FWNDrawDistance]], UsageFW[AllowedFirework[FireCracker]], UsageFW[AllowedFirework[Firerocket1]], UsageFW[AllowedFirework[Firerocket2]], UsageFW[AllowedFirework[Crackerroll]], UsageFW[AllowedFirework[Fountain1]], UsageFW[AllowedFirework[Fountain2]], UsageFW[AllowedFirework[Fountain3]], UsageFW[AllowedFirework[RocketB]]);
						ShowPlayerDialog(playerid, FWCPM,2,"FireWork Control Panel", string2,"Select", "Close");
						SaveFireWorkInfo();
						return 1;
					}
					case 1://FireRocket1 usable for rcon only
					{
						SendClientMessage(playerid, WHITE, "[FWCP]: The FireRocket 1 is now enabled for Rcon Admins only.");
						AllowedFirework[Firerocket1] = 1;
						format(string2, sizeof(string2), "DrawDistance: %s\nFire Cracker: %s\nFirerocket1: %s\nFirerocket2: %s\nCrackerRoll: %s\nFountain1: %s\nFountain2: %s\nFountain3: %s\nRocketBox: %s",
						DrawDistanceWord[AllowedFirework[FWNDrawDistance]], UsageFW[AllowedFirework[FireCracker]], UsageFW[AllowedFirework[Firerocket1]], UsageFW[AllowedFirework[Firerocket2]], UsageFW[AllowedFirework[Crackerroll]], UsageFW[AllowedFirework[Fountain1]], UsageFW[AllowedFirework[Fountain2]], UsageFW[AllowedFirework[Fountain3]], UsageFW[AllowedFirework[RocketB]]);
						ShowPlayerDialog(playerid, FWCPM,2,"FireWork Control Panel", string2,"Select", "Close");
						SaveFireWorkInfo();
						return 1;
					}
				}
				return 1;
			}
			return 1;
		}
 		case FWCPFR2:
		{
			if(response == 0)
			{
				format(string2, sizeof(string2), "DrawDistance: %s\nFire Cracker: %s\nFirerocket1: %s\nFirerocket2: %s\nCrackerRoll: %s\nFountain1: %s\nFountain2: %s\nFountain3: %s\nRocketBox: %s",
				DrawDistanceWord[AllowedFirework[FWNDrawDistance]], UsageFW[AllowedFirework[FireCracker]], UsageFW[AllowedFirework[Firerocket1]], UsageFW[AllowedFirework[Firerocket2]], UsageFW[AllowedFirework[Crackerroll]], UsageFW[AllowedFirework[Fountain1]], UsageFW[AllowedFirework[Fountain2]], UsageFW[AllowedFirework[Fountain3]], UsageFW[AllowedFirework[RocketB]]);
				ShowPlayerDialog(playerid, FWCPM,2,"FireWork Control Panel", string2,"Select", "Close");
				return 1;
			}
			if(response == 1)
			{
				switch (listitem)
				{
					case 0: //FireRocket2 usable for all
					{
						SendClientMessage(playerid, WHITE, "[FWCP]: The FireRocket 2 is now enabled for all players.");
						AllowedFirework[Firerocket2] = 0;
						format(string2, sizeof(string2), "DrawDistance: %s\nFire Cracker: %s\nFirerocket1: %s\nFirerocket2: %s\nCrackerRoll: %s\nFountain1: %s\nFountain2: %s\nFountain3: %s\nRocketBox: %s",
						DrawDistanceWord[AllowedFirework[FWNDrawDistance]], UsageFW[AllowedFirework[FireCracker]], UsageFW[AllowedFirework[Firerocket1]], UsageFW[AllowedFirework[Firerocket2]], UsageFW[AllowedFirework[Crackerroll]], UsageFW[AllowedFirework[Fountain1]], UsageFW[AllowedFirework[Fountain2]], UsageFW[AllowedFirework[Fountain3]], UsageFW[AllowedFirework[RocketB]]);
						ShowPlayerDialog(playerid, FWCPM,2,"FireWork Control Panel", string2,"Select", "Close");
						SaveFireWorkInfo();
						return 1;
					}
					case 1://FireRocket2 usable for rcon only
					{
						SendClientMessage(playerid, WHITE, "[FWCP]: The FireRocket 2 is now enabled for Rcon Admins only.");
						AllowedFirework[Firerocket2] = 1;
						format(string2, sizeof(string2), "DrawDistance: %s\nFire Cracker: %s\nFirerocket1: %s\nFirerocket2: %s\nCrackerRoll: %s\nFountain1: %s\nFountain2: %s\nFountain3: %s\nRocketBox: %s",
						DrawDistanceWord[AllowedFirework[FWNDrawDistance]], UsageFW[AllowedFirework[FireCracker]], UsageFW[AllowedFirework[Firerocket1]], UsageFW[AllowedFirework[Firerocket2]], UsageFW[AllowedFirework[Crackerroll]], UsageFW[AllowedFirework[Fountain1]], UsageFW[AllowedFirework[Fountain2]], UsageFW[AllowedFirework[Fountain3]], UsageFW[AllowedFirework[RocketB]]);
						ShowPlayerDialog(playerid, FWCPM,2,"FireWork Control Panel", string2,"Select", "Close");
						SaveFireWorkInfo();
						return 1;
					}
				}
				return 1;
			}
			return 1;
		}
		case FWCPCR:
		{
			if(response == 0)
			{
				format(string2, sizeof(string2), "DrawDistance: %s\nFire Cracker: %s\nFirerocket1: %s\nFirerocket2: %s\nCrackerRoll: %s\nFountain1: %s\nFountain2: %s\nFountain3: %s\nRocketBox: %s",
				DrawDistanceWord[AllowedFirework[FWNDrawDistance]], UsageFW[AllowedFirework[FireCracker]], UsageFW[AllowedFirework[Firerocket1]], UsageFW[AllowedFirework[Firerocket2]], UsageFW[AllowedFirework[Crackerroll]], UsageFW[AllowedFirework[Fountain1]], UsageFW[AllowedFirework[Fountain2]], UsageFW[AllowedFirework[Fountain3]], UsageFW[AllowedFirework[RocketB]]);
				ShowPlayerDialog(playerid, FWCPM,2,"FireWork Control Panel", string2,"Select", "Close");
				return 1;
			}
			if(response == 1)
			{
				switch (listitem)
				{
					case 0: //CrackerRoll usable for all
					{
						SendClientMessage(playerid, WHITE, "[FWCP]: The CrackerRoll is now enabled for all players.");
						AllowedFirework[Crackerroll] = 0;
						format(string2, sizeof(string2), "DrawDistance: %s\nFire Cracker: %s\nFirerocket1: %s\nFirerocket2: %s\nCrackerRoll: %s\nFountain1: %s\nFountain2: %s\nFountain3: %s\nRocketBox: %s",
						DrawDistanceWord[AllowedFirework[FWNDrawDistance]], UsageFW[AllowedFirework[FireCracker]], UsageFW[AllowedFirework[Firerocket1]], UsageFW[AllowedFirework[Firerocket2]], UsageFW[AllowedFirework[Crackerroll]], UsageFW[AllowedFirework[Fountain1]], UsageFW[AllowedFirework[Fountain2]], UsageFW[AllowedFirework[Fountain3]], UsageFW[AllowedFirework[RocketB]]);
						ShowPlayerDialog(playerid, FWCPM,2,"FireWork Control Panel", string2,"Select", "Close");
						SaveFireWorkInfo();
						return 1;
					}
					case 1://CrackerRoll usable for rcon only
					{
						SendClientMessage(playerid, WHITE, "[FWCP]: The CrackerRoll is now enabled for Rcon Admins only.");
						AllowedFirework[Crackerroll] = 1;
						format(string2, sizeof(string2), "DrawDistance: %s\nFire Cracker: %s\nFirerocket1: %s\nFirerocket2: %s\nCrackerRoll: %s\nFountain1: %s\nFountain2: %s\nFountain3: %s\nRocketBox: %s",
						DrawDistanceWord[AllowedFirework[FWNDrawDistance]], UsageFW[AllowedFirework[FireCracker]], UsageFW[AllowedFirework[Firerocket1]], UsageFW[AllowedFirework[Firerocket2]], UsageFW[AllowedFirework[Crackerroll]], UsageFW[AllowedFirework[Fountain1]], UsageFW[AllowedFirework[Fountain2]], UsageFW[AllowedFirework[Fountain3]], UsageFW[AllowedFirework[RocketB]]);
						ShowPlayerDialog(playerid, FWCPM,2,"FireWork Control Panel", string2,"Select", "Close");
						SaveFireWorkInfo();
						return 1;
					}
				}
				return 1;
			}
			return 1;
		}
		case FWCPFT1:
		{
			if(response == 0)
			{
				format(string2, sizeof(string2), "DrawDistance: %s\nFire Cracker: %s\nFirerocket1: %s\nFirerocket2: %s\nCrackerRoll: %s\nFountain1: %s\nFountain2: %s\nFountain3: %s\nRocketBox: %s",
				DrawDistanceWord[AllowedFirework[FWNDrawDistance]], UsageFW[AllowedFirework[FireCracker]], UsageFW[AllowedFirework[Firerocket1]], UsageFW[AllowedFirework[Firerocket2]], UsageFW[AllowedFirework[Crackerroll]], UsageFW[AllowedFirework[Fountain1]], UsageFW[AllowedFirework[Fountain2]], UsageFW[AllowedFirework[Fountain3]], UsageFW[AllowedFirework[RocketB]]);
				ShowPlayerDialog(playerid, FWCPM,2,"FireWork Control Panel", string2,"Select", "Close");
				return 1;
			}
			if(response == 1)
			{
				switch (listitem)
				{
					case 0: //Fountain1 usable for all
					{
						SendClientMessage(playerid, WHITE, "[FWCP]: The Fountain 1 is now enabled for all players.");
						AllowedFirework[Fountain1] = 0;
						format(string2, sizeof(string2), "DrawDistance: %s\nFire Cracker: %s\nFirerocket1: %s\nFirerocket2: %s\nCrackerRoll: %s\nFountain1: %s\nFountain2: %s\nFountain3: %s\nRocketBox: %s",
						DrawDistanceWord[AllowedFirework[FWNDrawDistance]], UsageFW[AllowedFirework[FireCracker]], UsageFW[AllowedFirework[Firerocket1]], UsageFW[AllowedFirework[Firerocket2]], UsageFW[AllowedFirework[Crackerroll]], UsageFW[AllowedFirework[Fountain1]], UsageFW[AllowedFirework[Fountain2]], UsageFW[AllowedFirework[Fountain3]], UsageFW[AllowedFirework[RocketB]]);
						ShowPlayerDialog(playerid, FWCPM,2,"FireWork Control Panel", string2,"Select", "Close");
						SaveFireWorkInfo();
						return 1;
					}
					case 1://Fountain1 usable for rcon only
					{
						SendClientMessage(playerid, WHITE, "[FWCP]: The Fountain 1 is now enabled for Rcon Admins only.");
						AllowedFirework[Fountain1] = 1;
						format(string2, sizeof(string2), "DrawDistance: %s\nFire Cracker: %s\nFirerocket1: %s\nFirerocket2: %s\nCrackerRoll: %s\nFountain1: %s\nFountain2: %s\nFountain3: %s\nRocketBox: %s",
						DrawDistanceWord[AllowedFirework[FWNDrawDistance]], UsageFW[AllowedFirework[FireCracker]], UsageFW[AllowedFirework[Firerocket1]], UsageFW[AllowedFirework[Firerocket2]], UsageFW[AllowedFirework[Crackerroll]], UsageFW[AllowedFirework[Fountain1]], UsageFW[AllowedFirework[Fountain2]], UsageFW[AllowedFirework[Fountain3]], UsageFW[AllowedFirework[RocketB]]);
						ShowPlayerDialog(playerid, FWCPM,2,"FireWork Control Panel", string2,"Select", "Close");
						SaveFireWorkInfo();
						return 1;
					}
				}
				return 1;
			}
			return 1;
		}
		case FWCPFT2:
		{
			if(response == 0)
			{
				format(string2, sizeof(string2), "DrawDistance: %s\nFire Cracker: %s\nFirerocket1: %s\nFirerocket2: %s\nCrackerRoll: %s\nFountain1: %s\nFountain2: %s\nFountain3: %s\nRocketBox: %s",
				DrawDistanceWord[AllowedFirework[FWNDrawDistance]], UsageFW[AllowedFirework[FireCracker]], UsageFW[AllowedFirework[Firerocket1]], UsageFW[AllowedFirework[Firerocket2]], UsageFW[AllowedFirework[Crackerroll]], UsageFW[AllowedFirework[Fountain1]], UsageFW[AllowedFirework[Fountain2]], UsageFW[AllowedFirework[Fountain3]], UsageFW[AllowedFirework[RocketB]]);
				ShowPlayerDialog(playerid, FWCPM,2,"FireWork Control Panel", string2,"Select", "Close");
				return 1;
			}
			if(response == 1)
			{
				switch (listitem)
				{
					case 0: //Fountain2 usable for all
					{
						SendClientMessage(playerid, WHITE, "[FWCP]: The Fountain 2 is now enabled for all players.");
						AllowedFirework[Fountain2] = 0;
						format(string2, sizeof(string2), "DrawDistance: %s\nFire Cracker: %s\nFirerocket1: %s\nFirerocket2: %s\nCrackerRoll: %s\nFountain1: %s\nFountain2: %s\nFountain3: %s\nRocketBox: %s",
						DrawDistanceWord[AllowedFirework[FWNDrawDistance]], UsageFW[AllowedFirework[FireCracker]], UsageFW[AllowedFirework[Firerocket1]], UsageFW[AllowedFirework[Firerocket2]], UsageFW[AllowedFirework[Crackerroll]], UsageFW[AllowedFirework[Fountain1]], UsageFW[AllowedFirework[Fountain2]], UsageFW[AllowedFirework[Fountain3]], UsageFW[AllowedFirework[RocketB]]);
						ShowPlayerDialog(playerid, FWCPM,2,"FireWork Control Panel", string2,"Select", "Close");
						SaveFireWorkInfo();
						return 1;
					}
					case 1://Fountain2 usable for rcon only
					{
						SendClientMessage(playerid, WHITE, "[FWCP]: The Fountain 2 is now enabled for Rcon Admins only.");
						AllowedFirework[Fountain2] = 1;
						format(string2, sizeof(string2), "DrawDistance: %s\nFire Cracker: %s\nFirerocket1: %s\nFirerocket2: %s\nCrackerRoll: %s\nFountain1: %s\nFountain2: %s\nFountain3: %s\nRocketBox: %s",
						DrawDistanceWord[AllowedFirework[FWNDrawDistance]], UsageFW[AllowedFirework[FireCracker]], UsageFW[AllowedFirework[Firerocket1]], UsageFW[AllowedFirework[Firerocket2]], UsageFW[AllowedFirework[Crackerroll]], UsageFW[AllowedFirework[Fountain1]], UsageFW[AllowedFirework[Fountain2]], UsageFW[AllowedFirework[Fountain3]], UsageFW[AllowedFirework[RocketB]]);
						ShowPlayerDialog(playerid, FWCPM,2,"FireWork Control Panel", string2,"Select", "Close");
						SaveFireWorkInfo();
						return 1;
					}
				}
				return 1;
			}
			return 1;
		}
		case FWCPFT3:
		{
			if(response == 0)
			{
				format(string2, sizeof(string2), "DrawDistance: %s\nFire Cracker: %s\nFirerocket1: %s\nFirerocket2: %s\nCrackerRoll: %s\nFountain1: %s\nFountain2: %s\nFountain3: %s\nRocketBox: %s",
				DrawDistanceWord[AllowedFirework[FWNDrawDistance]], UsageFW[AllowedFirework[FireCracker]], UsageFW[AllowedFirework[Firerocket1]], UsageFW[AllowedFirework[Firerocket2]], UsageFW[AllowedFirework[Crackerroll]], UsageFW[AllowedFirework[Fountain1]], UsageFW[AllowedFirework[Fountain2]], UsageFW[AllowedFirework[Fountain3]], UsageFW[AllowedFirework[RocketB]]);
				ShowPlayerDialog(playerid, FWCPM,2,"FireWork Control Panel", string2,"Select", "Close");
				return 1;
			}
			if(response == 1)
			{
				switch (listitem)
				{
					case 0: //Fountain3 usable for all
					{
						SendClientMessage(playerid, WHITE, "[FWCP]: The Fountain 3 is now enabled for all players.");
						AllowedFirework[Fountain3] = 0;
						format(string2, sizeof(string2), "DrawDistance: %s\nFire Cracker: %s\nFirerocket1: %s\nFirerocket2: %s\nCrackerRoll: %s\nFountain1: %s\nFountain2: %s\nFountain3: %s\nRocketBox: %s",
						DrawDistanceWord[AllowedFirework[FWNDrawDistance]], UsageFW[AllowedFirework[FireCracker]], UsageFW[AllowedFirework[Firerocket1]], UsageFW[AllowedFirework[Firerocket2]], UsageFW[AllowedFirework[Crackerroll]], UsageFW[AllowedFirework[Fountain1]], UsageFW[AllowedFirework[Fountain2]], UsageFW[AllowedFirework[Fountain3]], UsageFW[AllowedFirework[RocketB]]);
						ShowPlayerDialog(playerid, FWCPM,2,"FireWork Control Panel", string2,"Select", "Close");
						SaveFireWorkInfo();
						return 1;
					}
					case 1://Fountain3 usable for rcon only
					{
						SendClientMessage(playerid, WHITE, "[FWCP]: The Fountain 3 is now enabled for Rcon Admins only.");
						AllowedFirework[Fountain3] = 1;
						format(string2, sizeof(string2), "DrawDistance: %s\nFire Cracker: %s\nFirerocket1: %s\nFirerocket2: %s\nCrackerRoll: %s\nFountain1: %s\nFountain2: %s\nFountain3: %s\nRocketBox: %s",
						DrawDistanceWord[AllowedFirework[FWNDrawDistance]], UsageFW[AllowedFirework[FireCracker]], UsageFW[AllowedFirework[Firerocket1]], UsageFW[AllowedFirework[Firerocket2]], UsageFW[AllowedFirework[Crackerroll]], UsageFW[AllowedFirework[Fountain1]], UsageFW[AllowedFirework[Fountain2]], UsageFW[AllowedFirework[Fountain3]], UsageFW[AllowedFirework[RocketB]]);
						ShowPlayerDialog(playerid, FWCPM,2,"FireWork Control Panel", string2,"Select", "Close");
						SaveFireWorkInfo();
						return 1;
					}
				}
				return 1;
			}
			return 1;
		}
		case FWCPRB:
		{
			if(response == 0)
			{
				format(string2, sizeof(string2), "DrawDistance: %s\nFire Cracker: %s\nFirerocket1: %s\nFirerocket2: %s\nCrackerRoll: %s\nFountain1: %s\nFountain2: %s\nFountain3: %s\nRocketBox: %s",
				DrawDistanceWord[AllowedFirework[FWNDrawDistance]], UsageFW[AllowedFirework[FireCracker]], UsageFW[AllowedFirework[Firerocket1]], UsageFW[AllowedFirework[Firerocket2]], UsageFW[AllowedFirework[Crackerroll]], UsageFW[AllowedFirework[Fountain1]], UsageFW[AllowedFirework[Fountain2]], UsageFW[AllowedFirework[Fountain3]], UsageFW[AllowedFirework[RocketB]]);
				ShowPlayerDialog(playerid, FWCPM,2,"FireWork Control Panel", string2,"Select", "Close");
				return 1;
			}
			if(response == 1)
			{
				switch (listitem)
				{
					case 0: //RocketBox usable for all
					{
						SendClientMessage(playerid, WHITE, "[FWCP]: The RocketBox is now enabled for all players.");
						AllowedFirework[RocketB] = 0;
						format(string2, sizeof(string2), "DrawDistance: %s\nFire Cracker: %s\nFirerocket1: %s\nFirerocket2: %s\nCrackerRoll: %s\nFountain1: %s\nFountain2: %s\nFountain3: %s\nRocketBox: %s",
						DrawDistanceWord[AllowedFirework[FWNDrawDistance]], UsageFW[AllowedFirework[FireCracker]], UsageFW[AllowedFirework[Firerocket1]], UsageFW[AllowedFirework[Firerocket2]], UsageFW[AllowedFirework[Crackerroll]], UsageFW[AllowedFirework[Fountain1]], UsageFW[AllowedFirework[Fountain2]], UsageFW[AllowedFirework[Fountain3]], UsageFW[AllowedFirework[RocketB]]);
						ShowPlayerDialog(playerid, FWCPM,2,"FireWork Control Panel", string2,"Select", "Close");
						SaveFireWorkInfo();
						return 1;
					}
					case 1://RocketBox usable for rcon only
					{
						SendClientMessage(playerid, WHITE, "[FWCP]: The RocketBox is now enabled for Rcon Admins only.");
						AllowedFirework[RocketB] = 1;
						format(string2, sizeof(string2), "DrawDistance: %s\nFire Cracker: %s\nFirerocket1: %s\nFirerocket2: %s\nCrackerRoll: %s\nFountain1: %s\nFountain2: %s\nFountain3: %s\nRocketBox: %s",
						DrawDistanceWord[AllowedFirework[FWNDrawDistance]], UsageFW[AllowedFirework[FireCracker]], UsageFW[AllowedFirework[Firerocket1]], UsageFW[AllowedFirework[Firerocket2]], UsageFW[AllowedFirework[Crackerroll]], UsageFW[AllowedFirework[Fountain1]], UsageFW[AllowedFirework[Fountain2]], UsageFW[AllowedFirework[Fountain3]], UsageFW[AllowedFirework[RocketB]]);
						ShowPlayerDialog(playerid, FWCPM,2,"FireWork Control Panel", string2,"Select", "Close");
						SaveFireWorkInfo();
						return 1;
					}
				}
				return 1;
			}
			return 1;
		}*/
		case DIALOG_HELP:
		{
			if(response)
			{
				switch(listitem)
				{
					case 0:
					{
						new tmpstring[512];
						strcat( tmpstring, "Dostêpne czaty w grze:\n\n" );
						strcat( tmpstring, "OOC - czat globalny - /o\n" );
						strcat( tmpstring, "LOOC - czat lokalny - /b\n" );
						strcat( tmpstring, "POOC - czat prywatny (PW) - /pw\n" );
						ShowPlayerDialog( playerid, DIALOG_HELP_2, DIALOG_STYLE_MSGBOX, "WParty - czaty", tmpstring, "Wróæ", "");// To ktoœ musi skoñczyæ.
					}
					case 1:
					{
						new tmpstring[512];
						strcat( tmpstring, "Do wyboru mamy prawo jazdy, licencje na samoloty/helikoptery jak i licencje na broñ.\n\n" );
						strcat( tmpstring, "PRAWO JAZDY\nUdaj siê pod Pizzeriê, gdzie spogl¹daj¹c na prawo od niej ujrzysz czerwone pojazdy/\n" );
						strcat( tmpstring, "Aby rozpocz¹æ test musisz wejœæ do budynku przed którym znajduj¹ siê te pojazdy i zakupiæ test wchodz¹æ w czerwony marker.\n\n" );
						strcat( tmpstring, "LICENCJA PILOTA\nMo¿na j¹ kupiæ na lotnisku w San Fierro.\n\n" );
						strcat( tmpstring, "LICENCJA NA BROÑ\nDo kupienia przed sklepem z broni¹ znajduj¹cym siê niedaleko urzêdu San Fierro" );
						ShowPlayerDialog( playerid, DIALOG_HELP_2, DIALOG_STYLE_MSGBOX, "WParty - Licencje", tmpstring, "Wróæ", "" );
					}
					case 2:
					{
						ShowPlayerDialog( playerid, DIALOG_HELP_2, DIALOG_STYLE_MSGBOX, "WParty - Animacje", "Animacje znajdziesz pod komend¹ /animacje", "Wróæ", "" );// tu te¿ uzupe³niæ.
					}
					case 3:
					{
						new tmpstring[1024];
						strcat( tmpstring, "Istnieje mo¿liwoœæ kupna pojazdu nowego lub u¿ywanego.\n\n" );
						strcat( tmpstring, "POJAZDY NOWE\nS¹ one importowane przez w³aœcicieli salonów samochodowych.\n" );
						strcat( tmpstring, "Ich cene ustawia tak¿e w³aœciciel salonu.\n" );
						strcat( tmpstring, "Kupuj¹c pojazd z salonu mamy pewnoœæ ¿e nie posiada on ¿adnych mankamentów.\n\n" );
						strcat( tmpstring, "POJAZDY U¯YWANE\nWystawiane na sprzeda¿ w ró¿nych stanach i o ró¿nych przebiegach przez swoich w³aœcicieli" );
						strcat( tmpstring, "Taki pojazd mo¿e wygl¹daæ dobrze ale mo¿e posiadaæ ukryte mankamenty\n\n" );
						strcat( tmpstring, "LICENCJE\nAby legalnie prowadziæ samochód lub motor wymagane jest PRAWO JAZDY.\nW przypadku samolotów czy te¿ helikopterów jest to licencja pilota.\n\n" );
						strcat( tmpstring, "KOMENDY\n/komendypojazdow\n\n" );
						strcat( tmpstring, "Aby zamkn¹æ pojazd skorzystaj z kluczyka - przejdŸ do /mi, nastêpnie wybierz kluczyk o odpowiednio przypisanej rejestracji a nastêpnie wybierz \"u¿yj\"." );
						ShowPlayerDialog( playerid, DIALOG_HELP_2, DIALOG_STYLE_MSGBOX, "WParty - Pojazd", tmpstring, "Wróæ", "");
					}
					case 4:
					{
						new tmpstring[512];
						strcat( tmpstring, "Do wyboru jest wiele ró¿nego typu prac, jednak¿e niektóre maj¹ pewne wymagania na które napotkasz próbuj¹c podj¹c siê danej pracy.\n\n" );
						strcat( tmpstring, "Pierwsz¹ prace naj³atwiej dostaæ w Urzêdzie Miasta który jest oznaczony ¿ó³t¹ kropk¹ na Twoje mapie.\n" );
						strcat( tmpstring, "Aby zatrudniæ siê nale¿y wpisaæ /wezprace\n\n" );
						strcat( tmpstring, "Aby dowiedzieæ siê wiêcej o danej pracy po jej wyborze nale¿y wpisaæ komendê /komendypracy\n" );
						strcat( tmpstring, "Zrezygnowaæ z pracy mo¿na wpisuj¹c /zrezygnujzpracy" );
						ShowPlayerDialog( playerid, DIALOG_HELP_2, DIALOG_STYLE_MSGBOX, "WParty - Praca", tmpstring, "Wróæ", "");
					}
				}
			}
			return 1;
		}
		case DIALOG_HELP_2:
		{
			ShowPlayerDialog(playerid, DIALOG_HELP, DIALOG_STYLE_LIST, "WParty - Pomoc", DIALOG_HELP_MAIN_TXT, "Akceptuj", "Wstecz");
			return 1;
		}
	}
	return 1;
} // end of OnDialogResponse
