#include <wp\wfactory\wp_wfactory_itemfncs>

SelectFactoryWeapon( playerid )
{
	new rType, sType;
	new passes = 0;
	again:
	rType = random(3) + 1;
	if( passes == 100 )
	{
		gPlayerData[playerid][pPartType] = 0;
		gPlayerData[playerid][pPartItem] = 0;
		return 0;
	}
	again2:
	new wRandom = random(10);
	if( ( WFactoryLegalLight[WFactory9MMO] || WFactoryLegalLight[WFactory9MMSilO] ) && passes < 30 && wRandom == 0 )
	{
		rType = WF_WEAPON;
		sType = WF_9MM;
		if( !LFactoryHaveWFItems( rType, sType ) )
		{
			rType = WF_PART;
			sType = random(3);
			if( sType == 0 )
			{
				if( WFactoryLegalLight[WFactoryPistolPart1] > 0 )
				{
					passes++;
					goto again;
				}
				if( !LFactoryHaveWFItems( rType, WF_PISTOLPART1 ) )
				{
					passes++;
					goto again;
				}
				else
				{
					gPlayerData[playerid][pPartType] = WF_PART;
					gPlayerData[playerid][pPartItem] = WF_PISTOLPART1;
					return 1;
				}
			}
			else if( sType == 1 )
			{
				if( WFactoryLegalLight[WFactoryPistolPart2] > 0 )
				{
					passes++;
					goto again;
				}
				if( !LFactoryHaveWFItems( rType, WF_PISTOLPART2 ) )
				{
					passes++;
					goto again;
				}
				else
				{
					gPlayerData[playerid][pPartType] = WF_PART;
					gPlayerData[playerid][pPartItem] = WF_PISTOLPART2;
					return 1;
				}
			}
			else if( sType == 2 )
			{
				if( WFactoryLegalLight[WFactoryPistolPart3] > 0 )
				{
					passes++;
					goto again;
				}
				if( !LFactoryHaveWFItems( rType, WF_PISTOLPART3 ) )
				{
					passes++;
					goto again;
				}
				else
				{
					gPlayerData[playerid][pPartType] = WF_PART;
					gPlayerData[playerid][pPartItem] = WF_PISTOLPART3;
					return 1;
				}
			}
		}
		else
		{
			gPlayerData[playerid][pPartType] = WF_WEAPON;
			gPlayerData[playerid][pPartItem] = WF_9MM;
			return 1;
		}
	}
	if( WFactoryLegalLight[WFactoryDesEagleO] && passes < 30 && wRandom == 1 )
	{
		rType = WF_WEAPON;
		sType = WF_DESEAGLE;
		if( !LFactoryHaveWFItems( rType, sType ) )
		{
			rType = WF_PART;
			sType = random(3);
			if( sType == 0 )
			{
				if( WFactoryLegalLight[WFactoryPistolPart1] > 0 )
				{
					passes++;
					goto again;
				}
				if( !LFactoryHaveWFItems( rType, WF_PISTOLPART1 ) )
				{
					passes++;
					goto again;
				}
				else
				{
					gPlayerData[playerid][pPartType] = WF_PART;
					gPlayerData[playerid][pPartItem] = WF_PISTOLPART1;
					return 1;
				}
			}
			else if( sType == 1 )
			{
				if( WFactoryLegalLight[WFactoryPistolPart2] > 0 )
				{
					passes++;
					goto again;
				}
				if( !LFactoryHaveWFItems( rType, WF_PISTOLPART2 ) )
				{
					passes++;
					goto again;
				}
				else
				{
					gPlayerData[playerid][pPartType] = WF_PART;
					gPlayerData[playerid][pPartItem] = WF_PISTOLPART2;
					return 1;
				}
			}
			else if( sType == 2 )
			{
				if( WFactoryLegalLight[WFactoryPistolPart3] > 0 )
				{
					passes++;
					goto again;
				}
				if( !LFactoryHaveWFItems( rType, WF_PISTOLPART3 ) )
				{
					passes++;
					goto again;
				}
				else
				{
					gPlayerData[playerid][pPartType] = WF_PART;
					gPlayerData[playerid][pPartItem] = WF_PISTOLPART3;
					return 1;
				}
			}
		}
		else
		{
			gPlayerData[playerid][pPartType] = WF_WEAPON;
			gPlayerData[playerid][pPartItem] = WF_DESEAGLE;
			return 1;
		}
	}
	if( WFactoryLegalHeavy[WFactoryM4O] && passes < 30 && wRandom == 2 )
	{
		rType = WF_WEAPON;
		sType = WF_M4;
		if( !LFactoryHaveWFItems( rType, sType ) )
		{
			rType = WF_PART;
			sType = random(3);
			if( sType == 0 )
			{
				if( WFactoryLegalHeavy[WFactoryRiflePart1] >= 3 )
				{
					passes++;
					goto again;
				}
				if( !LFactoryHaveWFItems( rType, WF_RIFLEPART1 ) )
				{
					passes++;
					goto again;
				}
				else
				{
					gPlayerData[playerid][pPartType] = WF_PART;
					gPlayerData[playerid][pPartItem] = WF_RIFLEPART1;
					return 1;
				}
			}
			if( sType == 1 )
			{
				if( WFactoryLegalHeavy[WFactoryRiflePart2] >= 2 )
				{
					passes++;
					goto again;
				}
				if( !LFactoryHaveWFItems( rType, WF_RIFLEPART2 ) )
				{
					passes++;
					goto again;
				}
				else
				{
					gPlayerData[playerid][pPartType] = WF_PART;
					gPlayerData[playerid][pPartItem] = WF_RIFLEPART2;
					return 1;
				}
			}
			if( sType == 2 )
			{
				if( WFactoryLegalHeavy[WFactoryRiflePart3] >= 2 )
				{
					passes++;
					goto again;
				}
				if( !LFactoryHaveWFItems( rType, WF_RIFLEPART3 ) )
				{
					passes++;
					goto again;
				}
				else
				{
					gPlayerData[playerid][pPartType] = WF_PART;
					gPlayerData[playerid][pPartItem] = WF_RIFLEPART3;
					return 1;
				}
			}
		}
		else
		{
			gPlayerData[playerid][pPartType] = WF_WEAPON;
			gPlayerData[playerid][pPartItem] = WF_M4;
			return 1;
		}
	}
	if( WFactoryLegalHeavy[WFactoryShotgunO] && passes < 30 && wRandom == 3 )
	{
		rType = WF_WEAPON;
		sType = WF_SHOTGUN;
		if( !LFactoryHaveWFItems( rType, sType ) )
		{
			rType = WF_PART;
			sType = random(3);
			if( sType == 0 )
			{
				if( WFactoryLegalHeavy[WFactoryRiflePart1] >= 2 )
				{
					passes++;
					goto again;
				}
				if( !LFactoryHaveWFItems( rType, WF_RIFLEPART1 ) )
				{
					passes++;
					goto again;
				}
				else
				{
					gPlayerData[playerid][pPartType] = WF_PART;
					gPlayerData[playerid][pPartItem] = WF_RIFLEPART1;
					return 1;
				}
			}
			if( sType == 1 )
			{
				if( WFactoryLegalHeavy[WFactoryRiflePart2] >= 1 )
				{
					passes++;
					goto again;
				}
				if( !LFactoryHaveWFItems( rType, WF_RIFLEPART2 ) )
				{
					passes++;
					goto again;
				}
				else
				{
					gPlayerData[playerid][pPartType] = WF_PART;
					gPlayerData[playerid][pPartItem] = WF_RIFLEPART2;
					return 1;
				}
			}
			if( sType == 2 )
			{
				if( WFactoryLegalHeavy[WFactoryRiflePart3] >= 1 )
				{
					passes++;
					goto again;
				}
				if( !LFactoryHaveWFItems( rType, WF_RIFLEPART3 ) )
				{
					passes++;
					goto again;
				}
				else
				{
					gPlayerData[playerid][pPartType] = WF_PART;
					gPlayerData[playerid][pPartItem] = WF_RIFLEPART3;
					return 1;
				}
			}
		}
		else
		{
			gPlayerData[playerid][pPartType] = WF_WEAPON;
			gPlayerData[playerid][pPartItem] = WF_SHOTGUN;
			return 1;
		}
	}
	if( WFactoryLegalLight[WFactoryMP5O] && passes < 30 && wRandom == 4 )
	{
		rType = WF_WEAPON;
		sType = WF_MP5;
		if( !LFactoryHaveWFItems( rType, sType ) )
		{
			rType = WF_PART;
			sType = random(3);
			if( sType == 0 )
			{
				if( WFactoryLegalHeavy[WFactoryRiflePart1] >= 2 )
				{
					passes++;
					goto again;
				}
				if( !LFactoryHaveWFItems( rType, WF_RIFLEPART1 ) )
				{
					passes++;
					goto again;
				}
				else
				{
					gPlayerData[playerid][pPartType] = WF_PART;
					gPlayerData[playerid][pPartItem] = WF_RIFLEPART1;
					return 1;
				}
			}
			if( sType == 1 )
			{
				if( WFactoryLegalHeavy[WFactoryRiflePart2] >= 2 )
				{
					passes++;
					goto again;
				}
				if( !LFactoryHaveWFItems( rType, WF_RIFLEPART2 ) )
				{
					passes++;
					goto again;
				}
				else
				{
					gPlayerData[playerid][pPartType] = WF_PART;
					gPlayerData[playerid][pPartItem] = WF_RIFLEPART2;
					return 1;
				}
			}
			if( sType == 2 )
			{
				if( WFactoryLegalHeavy[WFactoryRiflePart3] >= 1 )
				{
					passes++;
					goto again;
				}
				if( !LFactoryHaveWFItems( rType, WF_RIFLEPART3 ) )
				{
					passes++;
					goto again;
				}
				else
				{
					gPlayerData[playerid][pPartType] = WF_PART;
					gPlayerData[playerid][pPartItem] = WF_RIFLEPART3;
					return 1;
				}
			}
		}
		else
		{
			gPlayerData[playerid][pPartType] = WF_WEAPON;
			gPlayerData[playerid][pPartItem] = WF_MP5;
			return 1;
		}
	}
	if( WFactoryLegalHeavy[WFactoryAK47O] && passes < 30 && wRandom == 5 )
	{
		rType = WF_WEAPON;
		sType = WF_AK47;
		if( !LFactoryHaveWFItems( rType, sType ) )
		{
			rType = WF_PART;
			sType = random(3);
			if( sType == 0 )
			{
				if( WFactoryLegalHeavy[WFactoryRiflePart1] >= 3 )
				{
					passes++;
					goto again;
				}
				if( !LFactoryHaveWFItems( rType, WF_RIFLEPART1 ) )
				{
					passes++;
					goto again;
				}
				else
				{
					gPlayerData[playerid][pPartType] = WF_PART;
					gPlayerData[playerid][pPartItem] = WF_RIFLEPART1;
					return 1;
				}
			}
			if( sType == 1 )
			{
				if( WFactoryLegalHeavy[WFactoryRiflePart2] >= 2 )
				{
					passes++;
					goto again;
				}
				if( !LFactoryHaveWFItems( rType, WF_RIFLEPART2 ) )
				{
					passes++;
					goto again;
				}
				else
				{
					gPlayerData[playerid][pPartType] = WF_PART;
					gPlayerData[playerid][pPartItem] = WF_RIFLEPART2;
					return 1;
				}
			}
			if( sType == 2 )
			{
				if( WFactoryLegalHeavy[WFactoryRiflePart3] >= 2 )
				{
					passes++;
					goto again;
				}
				if( !LFactoryHaveWFItems( rType, WF_RIFLEPART3 ) )
				{
					passes++;
					goto again;
				}
				else
				{
					gPlayerData[playerid][pPartType] = WF_PART;
					gPlayerData[playerid][pPartItem] = WF_RIFLEPART3;
					return 1;
				}
			}
		}
		else
		{
			gPlayerData[playerid][pPartType] = WF_WEAPON;
			gPlayerData[playerid][pPartItem] = WF_AK47;
			return 1;
		}
	}
	if( WFactoryLegalLight[WFactoryTec9O] && passes < 30 && wRandom == 6 )
	{
		rType = WF_WEAPON;
		sType = WF_TEC9;
		if( !LFactoryHaveWFItems( rType, sType ) )
		{
			rType = WF_PART;
			sType = random(3);
			if( sType == 0 )
			{
				if( WFactoryLegalLight[WFactoryPistolPart1] >= 3 )
				{
					passes++;
					goto again;
				}
				if( !LFactoryHaveWFItems( rType, WF_PISTOLPART1 ) )
				{
					passes++;
					goto again;
				}
				else
				{
					gPlayerData[playerid][pPartType] = WF_PART;
					gPlayerData[playerid][pPartItem] = WF_PISTOLPART1;
					return 1;
				}
			}
			else if( sType == 1 )
			{
				if( WFactoryLegalLight[WFactoryPistolPart2] >= 2 )
				{
					passes++;
					goto again;
				}
				if( !LFactoryHaveWFItems( rType, WF_PISTOLPART2 ) )
				{
					passes++;
					goto again;
				}
				else
				{
					gPlayerData[playerid][pPartType] = WF_PART;
					gPlayerData[playerid][pPartItem] = WF_PISTOLPART2;
					return 1;
				}
			}
			else if( sType == 2 )
			{
				if( WFactoryLegalLight[WFactoryPistolPart3] >= 2 )
				{
					passes++;
					goto again;
				}
				if( !LFactoryHaveWFItems( rType, WF_PISTOLPART3 ) )
				{
					passes++;
					goto again;
				}
				else
				{
					gPlayerData[playerid][pPartType] = WF_PART;
					gPlayerData[playerid][pPartItem] = WF_PISTOLPART3;
					return 1;
				}
			}
		}
		else
		{
			gPlayerData[playerid][pPartType] = WF_WEAPON;
			gPlayerData[playerid][pPartItem] = WF_TEC9;
			return 1;
		}
	}
	if( WFactoryLegalLight[WFactoryMicroSMGO] && passes < 30 && wRandom == 7 )
	{
		rType = WF_WEAPON;
		sType = WF_MICROSMG;
		if( !LFactoryHaveWFItems( rType, sType ) )
		{
			rType = WF_PART;
			sType = random(3);
			if( sType == 0 )
			{
				if( WFactoryLegalLight[WFactoryPistolPart1] >= 4 )
				{
					passes++;
					goto again;
				}
				if( !LFactoryHaveWFItems( rType, WF_PISTOLPART1 ) )
				{
					passes++;
					goto again;
				}
				else
				{
					gPlayerData[playerid][pPartType] = WF_PART;
					gPlayerData[playerid][pPartItem] = WF_PISTOLPART1;
					return 1;
				}
			}
			else if( sType == 1 )
			{
				if( WFactoryLegalLight[WFactoryPistolPart2] >= 4 )
				{
					passes++;
					goto again;
				}
				if( !LFactoryHaveWFItems( rType, WF_PISTOLPART2 ) )
				{
					passes++;
					goto again;
				}
				else
				{
					gPlayerData[playerid][pPartType] = WF_PART;
					gPlayerData[playerid][pPartItem] = WF_PISTOLPART2;
					return 1;
				}
			}
			else if( sType == 2 )
			{
				if( WFactoryLegalLight[WFactoryPistolPart3] >= 4 )
				{
					passes++;
					goto again;
				}
				if( !LFactoryHaveWFItems( rType, WF_PISTOLPART3 ) )
				{
					passes++;
					goto again;
				}
				else
				{
					gPlayerData[playerid][pPartType] = WF_PART;
					gPlayerData[playerid][pPartItem] = WF_PISTOLPART3;
					return 1;
				}
			}
		}
		else
		{
			gPlayerData[playerid][pPartType] = WF_WEAPON;
			gPlayerData[playerid][pPartItem] = WF_MICROSMG;
			return 1;
		}
	}
	if( WFactoryLegalHeavy[WFactoryRifleO] && passes < 30 && wRandom == 8 )
	{
		rType = WF_WEAPON;
		sType = WF_RIFLE;
		if( !LFactoryHaveWFItems( rType, sType ) )
		{
			rType = WF_PART;
			sType = random(3);
			if( sType == 0 )
			{
				if( WFactoryLegalHeavy[WFactoryRiflePart1] >= 3 )
				{
					passes++;
					goto again;
				}
				if( !LFactoryHaveWFItems( rType, WF_RIFLEPART1 ) )
				{
					passes++;
					goto again;
				}
				else
				{
					gPlayerData[playerid][pPartType] = WF_PART;
					gPlayerData[playerid][pPartItem] = WF_RIFLEPART1;
					return 1;
				}
			}
			if( sType == 1 )
			{
				if( WFactoryLegalHeavy[WFactoryRiflePart2] >= 2 )
				{
					passes++;
					goto again;
				}
				if( !LFactoryHaveWFItems( rType, WF_RIFLEPART2 ) )
				{
					passes++;
					goto again;
				}
				else
				{
					gPlayerData[playerid][pPartType] = WF_PART;
					gPlayerData[playerid][pPartItem] = WF_RIFLEPART2;
					return 1;
				}
			}
			if( sType == 2 )
			{
				if( WFactoryLegalHeavy[WFactoryRiflePart3] >= 2 )
				{
					passes++;
					goto again;
				}
				if( !LFactoryHaveWFItems( rType, WF_RIFLEPART3 ) )
				{
					passes++;
					goto again;
				}
				else
				{
					gPlayerData[playerid][pPartType] = WF_PART;
					gPlayerData[playerid][pPartItem] = WF_RIFLEPART3;
					return 1;
				}
			}
		}
		else
		{
			gPlayerData[playerid][pPartType] = WF_WEAPON;
			gPlayerData[playerid][pPartItem] = WF_RIFLE;
			return 1;
		}
	}
	if( WFactoryLegalHeavy[WFactorySRifleO] && passes < 30 && wRandom == 9 )
	{
		rType = WF_WEAPON;
		sType = WF_SRIFLE;
		if( !LFactoryHaveWFItems( rType, sType ) )
		{
			rType = WF_PART;
			sType = random(3);
			if( sType == 0 )
			{
				if( WFactoryLegalHeavy[WFactoryRiflePart1] >= 3 )
				{
					passes++;
					goto again;
				}
				if( !LFactoryHaveWFItems( rType, WF_RIFLEPART1 ) )
				{
					passes++;
					goto again;
				}
				else
				{
					gPlayerData[playerid][pPartType] = WF_PART;
					gPlayerData[playerid][pPartItem] = WF_RIFLEPART1;
					return 1;
				}
			}
			if( sType == 1 )
			{
				if( WFactoryLegalHeavy[WFactoryRiflePart2] >= 2 )
				{
					passes++;
					goto again;
				}
				if( !LFactoryHaveWFItems( rType, WF_RIFLEPART2 ) )
				{
					passes++;
					goto again;
				}
				else
				{
					gPlayerData[playerid][pPartType] = WF_PART;
					gPlayerData[playerid][pPartItem] = WF_RIFLEPART2;
					return 1;
				}
			}
			if( sType == 2 )
			{
				if( WFactoryLegalHeavy[WFactoryRiflePart3] >= 2 )
				{
					passes++;
					goto again;
				}
				if( !LFactoryHaveWFItems( rType, WF_RIFLEPART3 ) )
				{
					passes++;
					goto again;
				}
				else
				{
					gPlayerData[playerid][pPartType] = WF_PART;
					gPlayerData[playerid][pPartItem] = WF_RIFLEPART3;
					return 1;
				}
			}
		}
		else
		{
			gPlayerData[playerid][pPartType] = WF_WEAPON;
			gPlayerData[playerid][pPartItem] = WF_SRIFLE;
			return 1;
		}
	}
	if( passes < 30 )
	{
		passes++;
		goto again2;
	}
	switch( rType )
	{
		case WF_WEAPON:
		{
			gPlayerData[playerid][pPartType] = rType;
			sType = random(12) + 1;
			gPlayerData[playerid][pPartItem] = sType;
			if( !LFactoryHaveWFItems( rType, sType ) )
			{
				passes++;
				goto again;
			}
		}
		case WF_AMMO:
		{
			gPlayerData[playerid][pPartType] = rType;
			sType = random(5) + 1;
			gPlayerData[playerid][pPartItem] = sType;
			if( !LFactoryHaveWFItems( rType, sType ) )
			{
				passes++;
				goto again;
			}
			
		}
		case WF_PART:
		{
			againp:
			sType = random(13) + 1;
			if( sType != 4 && sType != 5 && sType != 6 && sType != 10 && sType != 11 && sType != 12 )
			{
				gPlayerData[playerid][pPartType] = rType;
				gPlayerData[playerid][pPartItem] = sType;
				if( !LFactoryHaveWFItems( rType, sType ) )
				{
					passes++;
					if( passes > 70 )
						goto again;
					else
						goto againp;
				}
			}
			else
			{
				goto again;
			}
		}
	}
	return 1;
}

Delay:PartsMount[1000, i](playerid)
{
	if( gPlayerData[playerid][pPartType] == 0 || gPlayerData[playerid][pPartItem] == 0 )
		return 0;
	new string[128];
	if( !PlayerHaveWFItems( playerid, gPlayerData[playerid][pPartType], gPlayerData[playerid][pPartItem] ) )
	{
		ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, DIALOG_WMENU_NOSPAREPART_TXT, DIALOG_INFO_EXIT, "" );
		return 1;
	}
	/* Mounting pass info */
	format( string, sizeof(string), WF_ASSEMBLE_T_LEFT, gPlayerData[playerid][pMountsPasses] );
	GameTextForPlayer( playerid, string, 1000, GAME_TEXT_STYLE_6 );
	gPlayerData[playerid][pMountsPasses]--;
	if( gPlayerData[playerid][pMountsPasses] == 0 )
	{
		switch( gPlayerData[playerid][pPartType] )
		{
			case WF_WEAPON:
			{
				switch( gPlayerData[playerid][pPartItem] )
				{
					case WF_9MM: { format( string, sizeof( string ), DIALOG_WMENU_PASS_WL_TXT, 6 - gPlayerData[playerid][pMountsLeft], 5 ); }
					case WF_9MMSIL: { format( string, sizeof( string ), DIALOG_WMENU_PASS_WL_TXT, 7 - gPlayerData[playerid][pMountsLeft], 6 ); }
					case WF_MICROSMG: { format( string, sizeof( string ), DIALOG_WMENU_PASS_WL_TXT, 6 - gPlayerData[playerid][pMountsLeft], 5 ); }
					case WF_DESEAGLE: { format( string, sizeof( string ), DIALOG_WMENU_PASS_WL_TXT, 7 - gPlayerData[playerid][pMountsLeft], 6 ); }
					case WF_TEC9: { format( string, sizeof( string ), DIALOG_WMENU_PASS_WL_TXT, 8 - gPlayerData[playerid][pMountsLeft], 7 ); }
					case WF_MP5: { format( string, sizeof( string ), DIALOG_WMENU_PASS_WL_TXT, 8 - gPlayerData[playerid][pMountsLeft], 7 ); }
					case WF_SHOTGUN: { format( string, sizeof( string ), DIALOG_WMENU_PASS_WL_TXT, 8 - gPlayerData[playerid][pMountsLeft], 7 ); }
					case WF_AK47: { format( string, sizeof( string ), DIALOG_WMENU_PASS_WL_TXT, 8 - gPlayerData[playerid][pMountsLeft], 7 ); }
					case WF_M4: { format( string, sizeof( string ), DIALOG_WMENU_PASS_WL_TXT, 8 - gPlayerData[playerid][pMountsLeft], 7 ); }
					case WF_RIFLE: { format( string, sizeof( string ), DIALOG_WMENU_PASS_WL_TXT, 8 - gPlayerData[playerid][pMountsLeft], 7 ); }
					case WF_SRIFLE: { format( string, sizeof( string ), DIALOG_WMENU_PASS_WL_TXT, 9 - gPlayerData[playerid][pMountsLeft], 8 ); }
					case WF_SCHARGE: { format( string, sizeof( string ), DIALOG_WMENU_PASS_WL_TXT, 11 - gPlayerData[playerid][pMountsLeft], 10 ); }
				}
			}
			case WF_PART:
			{
				switch( gPlayerData[playerid][pPartItem] )
				{
					case WF_PISTOLPART1: { format( string, sizeof( string ), DIALOG_WMENU_PASS_WL_TXT, 4 - gPlayerData[playerid][pMountsLeft], 3 ); }
					case WF_PISTOLPART2: { format( string, sizeof( string ), DIALOG_WMENU_PASS_WL_TXT, 4 - gPlayerData[playerid][pMountsLeft], 3 ); }
					case WF_PISTOLPART3: { format( string, sizeof( string ), DIALOG_WMENU_PASS_WL_TXT, 5 - gPlayerData[playerid][pMountsLeft], 4 ); }
							// WF_PISTOLPART4,
							// WF_PISTOLPART5,
							// WF_PISTOLPART6:
					// {
						// format( string, sizeof( string ), DIALOG_WMENU_PASS_WL_TXT, gPlayerData[playerid][pMountsLeft], WF_LPT );
					// }
					case WF_RIFLEPART1: { format( string, sizeof( string ), DIALOG_WMENU_PASS_WL_TXT, 4 - gPlayerData[playerid][pMountsLeft], 3 ); }
					case WF_RIFLEPART2: { format( string, sizeof( string ), DIALOG_WMENU_PASS_WL_TXT, 4 - gPlayerData[playerid][pMountsLeft], 3 ); }
					case WF_RIFLEPART3: { format( string, sizeof( string ), DIALOG_WMENU_PASS_WL_TXT, 5 - gPlayerData[playerid][pMountsLeft], 4 ); }
						// WF_RIFLEPART4,
						// WF_RIFLEPART5,
						// WF_RIFLEPART6,
					case WF_RIFLEPART7: { format( string, sizeof( string ), DIALOG_WMENU_PASS_WL_TXT, 3 - gPlayerData[playerid][pMountsLeft], 2 ); }
				}
			}
			case WF_AMMO:
			{
				format( string, sizeof( string ), DIALOG_WMENU_PASS_WL_TXT, 5 - gPlayerData[playerid][pMountsLeft], 4 );
			}
		}
		ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, string, "Zamknij", "" );
	}
	new fID = gPlayerData[playerid][pFaction];
	switch( gPlayerData[playerid][pPartType] )
	{
		case WF_WEAPON:
		{
			switch( gPlayerData[playerid][pPartItem] )
			{
				case WF_9MM:
				{
					if( gPlayerData[playerid][pMountsPasses] == 0 )
					{
						gPlayerData[playerid][pMountsLeft]--;
						SavePlayerData(playerid, "MountsLeft");
						/* Weapon receave */
						if( gPlayerData[playerid][pMountsLeft] == 0 )
						{
							if( gPlayerData[playerid][pJob] == 22 )
							{
								WFactoryLegalLight[WFactory9MM]++;
								SaveWFactoryData("WFactory9MM");
								if( WFactoryLegalLight[WFactory9MMO] > 0 )
								{
									WFactoryLegalLight[WFactory9MMO]--;
									SaveWFactoryData("WFactory9MMO");
								}
								GivePlayerCash( playerid, FACTORY_L_REWARD );
								DynamicFactions[FACTIONID_GOVERNMENT][fBank] -= FACTORY_L_REWARD;
								SaveFData(FACTIONID_GOVERNMENT, "Bank");
								format(string, sizeof(string), "[MOUNT:] End - WFactory9MM ++ for legal factory by %s", GetPlayerNameEx(playerid));
								WFactoryLog(string);
							}
							else
							{
								DynamicFactions[gPlayerData[playerid][pFaction]][WFactory9MM]++;
								SaveFData( fID, "WFactory9MM" );
								format(string, sizeof(string), "[MOUNT:] End - WFactory9MM ++ for illegal factory id %d by %s", fID, GetPlayerNameEx(playerid));
								WFactoryLog(string);
							}
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 48 ) );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 49 ) );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 50 ) );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 51 ) );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 52 ) );
							gPlayerData[playerid][pPartType] = 0;
							gPlayerData[playerid][pPartItem] = 0;
							SavePlayerData( playerid, "PartType" );
							SavePlayerData( playerid, "PartItem" );
							ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, WF_ASSEMBLE_F_WEAPON, DIALOG_INFO_EXIT, "" );
							gPlayerData[playerid][pMountingW] = 0;
							return 1;
						}
						gPlayerData[playerid][pMountingW] = 0;
						return 1;
					}
				}
				case WF_9MMSIL:
				{
					if( gPlayerData[playerid][pMountsPasses] == 0 )
					{
						gPlayerData[playerid][pMountsLeft]--;
						SavePlayerData(playerid, "MountsLeft");
						/* Weapon receave */
						if( gPlayerData[playerid][pMountsLeft] == 0 )
						{
							if( gPlayerData[playerid][pJob] == 22 )
							{
								WFactoryLegalLight[WFactory9MMSil]++;
								SaveWFactoryData("WFactory9MMSil");
								if( WFactoryLegalLight[WFactory9MMSilO] > 0 )
								{
									WFactoryLegalLight[WFactory9MMSilO]--;
									SaveWFactoryData("WFactory9MMSilO");
								}
								GivePlayerCash( playerid, FACTORY_L_REWARD );
								DynamicFactions[FACTIONID_GOVERNMENT][fBank] -= FACTORY_L_REWARD;
								SaveFData(FACTIONID_GOVERNMENT, "Bank");
								format(string, sizeof(string), "[MOUNT:] End - WFactory9MMSil ++ for legal factory by %s", GetPlayerNameEx(playerid));
								WFactoryLog(string);
							}
							else
							{
								DynamicFactions[gPlayerData[playerid][pFaction]][WFactory9MMSil]++;
								SaveFData( fID, "WFactory9MMSil" );
								format(string, sizeof(string), "[MOUNT:] End - WFactory9MMSil ++ for illegal factory id %d by %s", fID, GetPlayerNameEx(playerid));
								WFactoryLog(string);
							}
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 48 ) );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 49 ) );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 50 ) );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 51 ) );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 52 ) );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 59 ) );
							gPlayerData[playerid][pPartType] = 0;
							gPlayerData[playerid][pPartItem] = 0;
							SavePlayerData( playerid, "PartType" );
							SavePlayerData( playerid, "PartItem" );
							ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, WF_ASSEMBLE_F_WEAPON, DIALOG_INFO_EXIT, "" );
							gPlayerData[playerid][pMountingW] = 0;
							return 1;
						}
						gPlayerData[playerid][pMountingW] = 0;
						return 1;
					}
				}
				case WF_DESEAGLE:
				{
					if( gPlayerData[playerid][pMountsPasses] == 0 )
					{
						gPlayerData[playerid][pMountsLeft]--;
						SavePlayerData(playerid, "MountsLeft");
						/* Weapon receave */
						if( gPlayerData[playerid][pMountsLeft] == 0 )
						{
							if( gPlayerData[playerid][pJob] == 22 )
							{
								WFactoryLegalLight[WFactoryDesEagle]++;
								SaveWFactoryData("WFactoryDesEagle");
								if( WFactoryLegalLight[WFactoryDesEagleO] > 0 )
								{
									WFactoryLegalLight[WFactoryDesEagleO]--;
									SaveWFactoryData("WFactoryDesEagleO");
								}
								GivePlayerCash( playerid, FACTORY_L_REWARD );
								DynamicFactions[FACTIONID_GOVERNMENT][fBank] -= FACTORY_L_REWARD;
								SaveFData(FACTIONID_GOVERNMENT, "Bank");
								format(string, sizeof(string), "[MOUNT:] End - WFactoryDesEagle ++ for legal factory by %s", GetPlayerNameEx(playerid));
								WFactoryLog(string);
							}
							else
							{
								DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryDesEagle]++;
								SaveFData( fID, "WFactoryDesEagle" );
								format(string, sizeof(string), "[MOUNT:] End - WFactoryDesEagle ++ for illegal factory id %d by %s", fID, GetPlayerNameEx(playerid));
								WFactoryLog(string);
							}
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 87 ) );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 48 ) );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 49 ), 2 );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 50 ), 2 );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 51 ), 2 );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 52 ) );
							gPlayerData[playerid][pPartType] = 0;
							gPlayerData[playerid][pPartItem] = 0;
							SavePlayerData( playerid, "PartType" );
							SavePlayerData( playerid, "PartItem" );
							ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, WF_ASSEMBLE_F_WEAPON, DIALOG_INFO_EXIT, "" );
							gPlayerData[playerid][pMountingW] = 0;
							return 1;
						}
						gPlayerData[playerid][pMountingW] = 0;
						return 1;
					}
				}
				case WF_SHOTGUN:
				{
					if( gPlayerData[playerid][pMountsPasses] == 0 )
					{
						gPlayerData[playerid][pMountsLeft]--;
						SavePlayerData(playerid, "MountsLeft");
						/* Weapon receave */
						if( gPlayerData[playerid][pMountsLeft] == 0 )
						{
							if( gPlayerData[playerid][pJob] == 22 )
							{
								WFactoryLegalHeavy[WFactoryShotgun]++;
								SaveWFactoryData("WFactoryShotgun");
								if( WFactoryLegalHeavy[WFactoryShotgunO] > 0 )
								{
									WFactoryLegalHeavy[WFactoryShotgunO]--;
									SaveWFactoryData("WFactoryShotgunO");
								}
								GivePlayerCash( playerid, FACTORY_L_REWARD );
								DynamicFactions[FACTIONID_GOVERNMENT][fBank] -= FACTORY_L_REWARD;
								SaveFData(FACTIONID_GOVERNMENT, "Bank");
								format(string, sizeof(string), "[MOUNT:] End - WFactoryShotgun ++ for legal factory by %s", GetPlayerNameEx(playerid));
								WFactoryLog(string);
							}
							else
							{
								DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryShotgun]++;
								SaveFData( fID, "WFactoryShotgun" );
								format(string, sizeof(string), "[MOUNT:] End - WFactoryShotgun ++ for illegal factory id %d by %s", fID, GetPlayerNameEx(playerid));
								WFactoryLog(string);
							}
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 86 ) );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 53 ), 3 );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 54 ), 2 );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 55 ), 2 );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 56 ) );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 57 ) );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 58 ) );
							gPlayerData[playerid][pPartType] = 0;
							gPlayerData[playerid][pPartItem] = 0;
							SavePlayerData( playerid, "PartType" );
							SavePlayerData( playerid, "PartItem" );
							ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, WF_ASSEMBLE_F_WEAPON, DIALOG_INFO_EXIT, "" );
							gPlayerData[playerid][pMountingW] = 0;
							return 1;
						}
						gPlayerData[playerid][pMountingW] = 0;
						return 1;
					}
				}
				case WF_MICROSMG:
				{
					if( gPlayerData[playerid][pMountsPasses] == 0 )
					{
						gPlayerData[playerid][pMountsLeft]--;
						SavePlayerData(playerid, "MountsLeft");
						/* Weapon receave */
						if( gPlayerData[playerid][pMountsLeft] == 0 )
						{
							if( gPlayerData[playerid][pJob] == 22 )
							{
								WFactoryLegalLight[WFactoryMicroSMG]++;
								SaveWFactoryData("WFactoryMicroSMG");
								if( WFactoryLegalLight[WFactoryMicroSMGO] > 0 )
								{
									WFactoryLegalLight[WFactoryMicroSMGO]--;
									SaveWFactoryData("WFactoryMicroSMGO");
								}
								GivePlayerCash( playerid, FACTORY_L_REWARD );
								DynamicFactions[FACTIONID_GOVERNMENT][fBank] -= FACTORY_L_REWARD;
								SaveFData(FACTIONID_GOVERNMENT, "Bank");
								format(string, sizeof(string), "[MOUNT:] End - WFactoryMicroSMG ++ for legal factory by %s", GetPlayerNameEx(playerid));
								WFactoryLog(string);
							}
							else
							{
								DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryMicroSMG]++;
								SaveFData( fID, "WFactoryMicroSMG" );
								format(string, sizeof(string), "[MOUNT:] End - WFactoryMicroSMG ++ for illegal factory id %d by %s", fID, GetPlayerNameEx(playerid));
								WFactoryLog(string);
							}
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 48 ), 4 );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 49 ), 4 );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 50 ), 4 );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 51 ) );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 52 ) );
							gPlayerData[playerid][pPartType] = 0;
							gPlayerData[playerid][pPartItem] = 0;
							SavePlayerData( playerid, "PartType" );
							SavePlayerData( playerid, "PartItem" );
							ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, WF_ASSEMBLE_F_WEAPON, DIALOG_INFO_EXIT, "" );
							gPlayerData[playerid][pMountingW] = 0;
							return 1;
						}
						gPlayerData[playerid][pMountingW] = 0;
						return 1;
					}
				}
				case WF_MP5:
				{
					if( gPlayerData[playerid][pMountsPasses] == 0 )
					{
						gPlayerData[playerid][pMountsLeft]--;
						SavePlayerData(playerid, "MountsLeft");
						/* Weapon receave */
						if( gPlayerData[playerid][pMountsLeft] == 0 )
						{
							if( gPlayerData[playerid][pJob] == 22 )
							{
								WFactoryLegalLight[WFactoryMP5]++;
								SaveWFactoryData("WFactoryMP5");
								if( WFactoryLegalLight[WFactoryMP5O] > 0 )
								{
									WFactoryLegalLight[WFactoryMP5O]--;
									SaveWFactoryData("WFactoryMP5O");
								}
								GivePlayerCash( playerid, FACTORY_L_REWARD );
								DynamicFactions[FACTIONID_GOVERNMENT][fBank] -= FACTORY_L_REWARD;
								SaveFData(FACTIONID_GOVERNMENT, "Bank");
								format(string, sizeof(string), "[MOUNT:] End - WFactoryMP5 ++ for legal factory by %s", GetPlayerNameEx(playerid));
								WFactoryLog(string);
							}
							else
							{
								DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryMP5]++;
								SaveFData( fID, "WFactoryMP5" );
								format(string, sizeof(string), "[MOUNT:] End - WFactoryMP5 ++ for illegal factory id %d by %s", fID, GetPlayerNameEx(playerid));
								WFactoryLog(string);
							}
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 83 ), 2 );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 53 ) );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 54 ), 2 );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 55 ) );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 56 ) );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 57 ) );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 58 ) );
							gPlayerData[playerid][pPartType] = 0;
							gPlayerData[playerid][pPartItem] = 0;
							SavePlayerData( playerid, "PartType" );
							SavePlayerData( playerid, "PartItem" );
							ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, WF_ASSEMBLE_F_WEAPON, DIALOG_INFO_EXIT, "" );
							gPlayerData[playerid][pMountingW] = 0;
							return 1;
						}
						gPlayerData[playerid][pMountingW] = 0;
						return 1;
					}
				}
				case WF_AK47:
				{
					if( gPlayerData[playerid][pMountsPasses] == 0 )
					{
						gPlayerData[playerid][pMountsLeft]--;
						SavePlayerData(playerid, "MountsLeft");
						/* Weapon receave */
						if( gPlayerData[playerid][pMountsLeft] == 0 )
						{
							if( gPlayerData[playerid][pJob] == 22 )
							{
								WFactoryLegalHeavy[WFactoryAK47]++;
								SaveWFactoryData("WFactoryAK47");
								if( WFactoryLegalHeavy[WFactoryAK47O] > 0 )
								{
									WFactoryLegalHeavy[WFactoryAK47O]--;
									SaveWFactoryData("WFactoryAK47O");
								}
								GivePlayerCash( playerid, FACTORY_L_REWARD );
								DynamicFactions[FACTIONID_GOVERNMENT][fBank] -= FACTORY_L_REWARD;
								SaveFData(FACTIONID_GOVERNMENT, "Bank");
								format(string, sizeof(string), "[MOUNT:] End - WFactoryAK47 ++ for legal factory by %s", GetPlayerNameEx(playerid));
								WFactoryLog(string);
							}
							else
							{
								DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryAK47]++;
								SaveFData( fID, "WFactoryAK47" );
								format(string, sizeof(string), "[MOUNT:] End - WFactoryAK47 ++ for illegal factory id %d by %s", fID, GetPlayerNameEx(playerid));
								WFactoryLog(string);
							}
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 84 ) );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 53 ), 3 );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 54 ), 2 );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 55 ), 2 );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 56 ) );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 57 ) );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 58 ) );
							gPlayerData[playerid][pPartType] = 0;
							gPlayerData[playerid][pPartItem] = 0;
							SavePlayerData( playerid, "PartType" );
							SavePlayerData( playerid, "PartItem" );
							ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, WF_ASSEMBLE_F_WEAPON, DIALOG_INFO_EXIT, "" );
							gPlayerData[playerid][pMountingW] = 0;
							return 1;
						}
						gPlayerData[playerid][pMountingW] = 0;
						return 1;
					}
				}
				case WF_M4:
				{
					if( gPlayerData[playerid][pMountsPasses] == 0 )
					{
						gPlayerData[playerid][pMountsLeft]--;
						SavePlayerData(playerid, "MountsLeft");
						/* Weapon receave */
						if( gPlayerData[playerid][pMountsLeft] == 0 )
						{
							if( gPlayerData[playerid][pJob] == 22 )
							{
								WFactoryLegalHeavy[WFactoryM4]++;
								SaveWFactoryData("WFactoryM4");
								if( WFactoryLegalHeavy[WFactoryM4O] > 0 )
								{
									WFactoryLegalHeavy[WFactoryM4O]--;
									SaveWFactoryData("WFactoryM4O");
								}
								GivePlayerCash( playerid, FACTORY_L_REWARD );
								DynamicFactions[FACTIONID_GOVERNMENT][fBank] -= FACTORY_L_REWARD;
								SaveFData(FACTIONID_GOVERNMENT, "Bank");
								format(string, sizeof(string), "[MOUNT:] End - WFactoryM4 ++ for legal factory by %s", GetPlayerNameEx(playerid));
								WFactoryLog(string);
							}
							else
							{
								DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryM4]++;
								SaveFData( fID, "WFactoryM4" );
								format(string, sizeof(string), "[MOUNT:] End - WFactoryM4 ++ for illegal factory id %d by %s", fID, GetPlayerNameEx(playerid));
								WFactoryLog(string);
							}
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 85 ) );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 53 ), 3 );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 54 ), 2 );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 55 ), 2 );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 56 ) );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 57 ) );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 58 ) );
							gPlayerData[playerid][pPartType] = 0;
							gPlayerData[playerid][pPartItem] = 0;
							SavePlayerData( playerid, "PartType" );
							SavePlayerData( playerid, "PartItem" );
							ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, WF_ASSEMBLE_F_WEAPON, DIALOG_INFO_EXIT, "" );
							gPlayerData[playerid][pMountingW] = 0;
							return 1;
						}
						gPlayerData[playerid][pMountingW] = 0;
						return 1;
					}
				}
				case WF_TEC9:
				{
					if( gPlayerData[playerid][pMountsPasses] == 0 )
					{
						gPlayerData[playerid][pMountsLeft]--;
						SavePlayerData(playerid, "MountsLeft");
						/* Weapon receave */
						if( gPlayerData[playerid][pMountsLeft] == 0 )
						{
							if( gPlayerData[playerid][pJob] == 22 )
							{
								WFactoryLegalLight[WFactoryTec9]++;
								SaveWFactoryData("WFactoryTec9");
								if( WFactoryLegalLight[WFactoryTec9O] > 0 )
								{
									WFactoryLegalLight[WFactoryTec9O]--;
									SaveWFactoryData("WFactoryTec9O");
								}
								GivePlayerCash( playerid, FACTORY_L_REWARD );
								DynamicFactions[FACTIONID_GOVERNMENT][fBank] -= FACTORY_L_REWARD;
								SaveFData(FACTIONID_GOVERNMENT, "Bank");
								format(string, sizeof(string), "[MOUNT:] End - WFactoryTec9 ++ for legal factory by %s", GetPlayerNameEx(playerid));
								WFactoryLog(string);
							}
							else
							{
								DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryTec9]++;
								SaveFData( fID, "WFactoryTec9" );
								format(string, sizeof(string), "[MOUNT:] End - WFactoryTec9 ++ for illegal factory id %d by %s", fID, GetPlayerNameEx(playerid));
								WFactoryLog(string);
							}
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 82 ) );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 48 ), 3 );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 49 ), 2 );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 50 ), 2 );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 51 ) );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 52 ) );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 59 ) );
							gPlayerData[playerid][pPartType] = 0;
							gPlayerData[playerid][pPartItem] = 0;
							SavePlayerData( playerid, "PartType" );
							SavePlayerData( playerid, "PartItem" );
							ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, WF_ASSEMBLE_F_WEAPON, DIALOG_INFO_EXIT, "" );
							gPlayerData[playerid][pMountingW] = 0;
							return 1;
						}
						gPlayerData[playerid][pMountingW] = 0;
						return 1;
					}
				}
				case WF_RIFLE:
				{
					if( gPlayerData[playerid][pMountsPasses] == 0 )
					{
						gPlayerData[playerid][pMountsLeft]--;
						SavePlayerData(playerid, "MountsLeft");
						/* Weapon receave */
						if( gPlayerData[playerid][pMountsLeft] == 0 )
						{
							if( gPlayerData[playerid][pJob] == 22 )
							{
								WFactoryLegalHeavy[WFactoryRifle]++;
								SaveWFactoryData("WFactoryRifle");
								if( WFactoryLegalHeavy[WFactoryRifleO] > 0 )
								{
									WFactoryLegalHeavy[WFactoryRifleO]--;
									SaveWFactoryData("WFactoryRifleO");
								}
								GivePlayerCash( playerid, FACTORY_L_REWARD );
								DynamicFactions[FACTIONID_GOVERNMENT][fBank] -= FACTORY_L_REWARD;
								SaveFData(FACTIONID_GOVERNMENT, "Bank");
								format(string, sizeof(string), "[MOUNT:] End - WFactoryRifle ++ for legal factory by %s", GetPlayerNameEx(playerid));
								WFactoryLog(string);
							}
							else
							{
								DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryRifle]++;
								SaveFData( fID, "WFactoryRifle" );
								format(string, sizeof(string), "[MOUNT:] End - WFactoryRifle ++ for illegal factory id %d by %s", fID, GetPlayerNameEx(playerid));
								WFactoryLog(string);
							}
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 88 ) );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 53 ), 2 );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 54 ) );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 55 ) );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 56 ) );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 57 ) );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 58 ) );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 60 ) );
							gPlayerData[playerid][pPartType] = 0;
							gPlayerData[playerid][pPartItem] = 0;
							SavePlayerData( playerid, "PartType" );
							SavePlayerData( playerid, "PartItem" );
							ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, WF_ASSEMBLE_F_WEAPON, DIALOG_INFO_EXIT, "" );
							gPlayerData[playerid][pMountingW] = 0;
							return 1;
						}
						gPlayerData[playerid][pMountingW] = 0;
						return 1;
					}
				}
				case WF_SRIFLE:
				{
					if( gPlayerData[playerid][pMountsPasses] == 0 )
					{
						gPlayerData[playerid][pMountsLeft]--;
						SavePlayerData(playerid, "MountsLeft");
						/* Weapon receave */
						if( gPlayerData[playerid][pMountsLeft] == 0 )
						{
							if( gPlayerData[playerid][pJob] == 22 )
							{
								WFactoryLegalHeavy[WFactorySRifle]++;
								SaveWFactoryData("WFactorySRifle");
								if( WFactoryLegalHeavy[WFactorySRifleO] > 0 )
								{
									WFactoryLegalHeavy[WFactorySRifleO]--;
									SaveWFactoryData("WFactorySRifleO");
								}
								GivePlayerCash( playerid, FACTORY_L_REWARD );
								DynamicFactions[FACTIONID_GOVERNMENT][fBank] -= FACTORY_L_REWARD;
								SaveFData(FACTIONID_GOVERNMENT, "Bank");
								format(string, sizeof(string), "[MOUNT:] End - WFactorySRifle ++ for legal factory by %s", GetPlayerNameEx(playerid));
								WFactoryLog(string);
							}
							else
							{
								DynamicFactions[gPlayerData[playerid][pFaction]][WFactorySRifle]++;
								SaveFData( fID, "WFactorySRifle" );
								format(string, sizeof(string), "[MOUNT:] End - WFactorySRifle ++ for illegal factory id %d by %s", fID, GetPlayerNameEx(playerid));
								WFactoryLog(string);
							}
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 89 ) );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 53 ), 3 );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 54 ), 3 );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 55 ), 2 );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 56 ), 2 );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 57 ), 2 );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 58 ), 2 );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 60 ) );
							gPlayerData[playerid][pPartType] = 0;
							gPlayerData[playerid][pPartItem] = 0;
							SavePlayerData( playerid, "PartType" );
							SavePlayerData( playerid, "PartItem" );
							ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, WF_ASSEMBLE_F_WEAPON, DIALOG_INFO_EXIT, "" );
							gPlayerData[playerid][pMountingW] = 0;
							return 1;
						}
						gPlayerData[playerid][pMountingW] = 0;
						return 1;
					}
				}
			}
		}
		case WF_AMMO:
		{
			switch( gPlayerData[playerid][pPartItem] )
			{
				case WF_9MMAMMO:
				{
					if( gPlayerData[playerid][pMountsPasses] == 0 )
					{
						gPlayerData[playerid][pMountsLeft]--;
						SavePlayerData(playerid, "MountsLeft");
						if( gPlayerData[playerid][pMountsLeft] == 0 )
						{
							if( gPlayerData[playerid][pJob] == 22 )
							{
								WFactoryLegalLight[WFactory9MMAmmo] += 10;
								SaveWFactoryData("WFactory9MMAmmo");
								GivePlayerCash( playerid, FACTORY_L_REWARD );
								DynamicFactions[FACTIONID_GOVERNMENT][fBank] -= FACTORY_L_REWARD;
								SaveFData(FACTIONID_GOVERNMENT, "Bank");
								format(string, sizeof(string), "[MOUNT:] End - WFactory9MMAmmo ++ for legal factory by %s", GetPlayerNameEx(playerid));
								WFactoryLog(string);
							}
							else
							{
								DynamicFactions[gPlayerData[playerid][pFaction]][WFactory9MMAmmo] += 10;
								SaveFData( fID, "WFactory9MMAmmo" );
								format(string, sizeof(string), "[MOUNT:] End - WFactory9MMAmmo ++ for illegal factory id %d by %s", fID, GetPlayerNameEx(playerid));
								WFactoryLog(string);
							}
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 43 ) );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 44 ) );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 45 ) );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 46 ) );
							gPlayerData[playerid][pPartType] = 0;
							gPlayerData[playerid][pPartItem] = 0;
							SavePlayerData( playerid, "PartType" );
							SavePlayerData( playerid, "PartItem" );
							ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, WF_ASSEMBLE_F_AMMO, DIALOG_INFO_EXIT, "" );
							gPlayerData[playerid][pMountingW] = 0;
							return 1;
						}
						gPlayerData[playerid][pMountingW] = 0;
						return 1;
					}
				}
				case WF_50AEAMMO:
				{
					if( gPlayerData[playerid][pMountsPasses] == 0 )
					{
						gPlayerData[playerid][pMountsLeft]--;
						SavePlayerData(playerid, "MountsLeft");
						if( gPlayerData[playerid][pMountsLeft] == 0 )
						{
							if( gPlayerData[playerid][pJob] == 22 )
							{
								WFactoryLegalLight[WFactory50AEAmmo] += 5;
								SaveWFactoryData("WFactory50AEAmmo");
								GivePlayerCash( playerid, FACTORY_L_REWARD );
								DynamicFactions[FACTIONID_GOVERNMENT][fBank] -= FACTORY_L_REWARD;
								SaveFData(FACTIONID_GOVERNMENT, "Bank");
								format(string, sizeof(string), "[MOUNT:] End - WFactory50AEAmmo ++ for legal factory by %s", GetPlayerNameEx(playerid));
								WFactoryLog(string);
							}
							else
							{
								DynamicFactions[gPlayerData[playerid][pFaction]][WFactory50AEAmmo] += 5;
								SaveFData( fID, "WFactory50AEAmmo");
								format(string, sizeof(string), "[MOUNT:] End - WFactory50AEAmmo ++ for illegal factory id %d by %s", fID, GetPlayerNameEx(playerid));
								WFactoryLog(string);
							}
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 101 ), 10 );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 102 ), 5 );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 103 ), 2 );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 104 ), 2 );
							gPlayerData[playerid][pPartType] = 0;
							gPlayerData[playerid][pPartItem] = 0;
							SavePlayerData( playerid, "PartType" );
							SavePlayerData( playerid, "PartItem" );
							ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, WF_ASSEMBLE_F_AMMO, DIALOG_INFO_EXIT, "" );
							gPlayerData[playerid][pMountingW] = 0;
							return 1;
						}
						gPlayerData[playerid][pMountingW] = 0;
						return 1;
					}
				}
				case WF_BUCKSHOT:
				{
					if( gPlayerData[playerid][pMountsPasses] == 0 )
					{
						gPlayerData[playerid][pMountsLeft]--;
						SavePlayerData(playerid, "MountsLeft");
						if( gPlayerData[playerid][pMountsLeft] == 0 )
						{
							if( gPlayerData[playerid][pJob] == 22 )
							{
								WFactoryLegalHeavy[WFactoryBuckshot] += 5;
								SaveWFactoryData("WFactoryBuckshot");
								GivePlayerCash( playerid, FACTORY_L_REWARD );
								DynamicFactions[FACTIONID_GOVERNMENT][fBank] -= FACTORY_L_REWARD;
								SaveFData(FACTIONID_GOVERNMENT, "Bank");
								format(string, sizeof(string), "[MOUNT:] End - WFactoryBuckshot ++ for legal factory by %s", GetPlayerNameEx(playerid));
								WFactoryLog(string);
							}
							else
							{
								DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryBuckshot] += 5;
								SaveFData( fID, "WFactoryBuckshot");
								format(string, sizeof(string), "[MOUNT:] End - WFactoryBuckshot ++ for illegal factory id %d by %s", fID, GetPlayerNameEx(playerid));
								WFactoryLog(string);
							}
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 47 ), 6 );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 90 ), 1);
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 91 ), 2 );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 92 ), 2 );
							gPlayerData[playerid][pPartType] = 0;
							gPlayerData[playerid][pPartItem] = 0;
							SavePlayerData( playerid, "PartType" );
							SavePlayerData( playerid, "PartItem" );
							ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, WF_ASSEMBLE_F_AMMO, DIALOG_INFO_EXIT, "" );
							gPlayerData[playerid][pMountingW] = 0;
							return 1;
						}
						gPlayerData[playerid][pMountingW] = 0;
						return 1;
					}
				}
				case WF_762MMAMMO:
				{
					if( gPlayerData[playerid][pMountsPasses] == 0 )
					{
						gPlayerData[playerid][pMountsLeft]--;
						SavePlayerData(playerid, "MountsLeft");
						if( gPlayerData[playerid][pMountsLeft] == 0 )
						{
							if( gPlayerData[playerid][pJob] == 22 )
							{
								WFactoryLegalHeavy[WFactory762MMAmmo] += 1;
								SaveWFactoryData("WFactory762MMAmmo");
								GivePlayerCash( playerid, FACTORY_L_REWARD );
								DynamicFactions[FACTIONID_GOVERNMENT][fBank] -= FACTORY_L_REWARD;
								SaveFData(FACTIONID_GOVERNMENT, "Bank");
								format(string, sizeof(string), "[MOUNT:] End - WFactory762MMAmmo ++ for legal factory by %s", GetPlayerNameEx(playerid));
								WFactoryLog(string);
							}
							else
							{
								DynamicFactions[gPlayerData[playerid][pFaction]][WFactory762MMAmmo] += 5;
								SaveFData( fID, "WFactory762MMAmmo" );
								format(string, sizeof(string), "[MOUNT:] End - WFactory762MMAmmo ++ for illegal factory id %d by %s", fID, GetPlayerNameEx(playerid));
								WFactoryLog(string);
							}
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 93 ), 4 );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 94 ), 2 );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 95 ), 2 );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 96 ), 2 );
							gPlayerData[playerid][pPartType] = 0;
							gPlayerData[playerid][pPartItem] = 0;
							SavePlayerData( playerid, "PartType" );
							SavePlayerData( playerid, "PartItem" );
							ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, WF_ASSEMBLE_F_AMMO, DIALOG_INFO_EXIT, "" );
							gPlayerData[playerid][pMountingW] = 0;
							return 1;
						}
						gPlayerData[playerid][pMountingW] = 0;
						return 1;
					}
				}
				case WF_127MMAMMO:
				{
					if( gPlayerData[playerid][pMountsPasses] == 0 )
					{
						gPlayerData[playerid][pMountsLeft]--;
						if( gPlayerData[playerid][pMountsLeft] == 0 )
						{
							if( gPlayerData[playerid][pJob] == 22 )
							{
								WFactoryLegalHeavy[WFactory127MMAmmo] += 5;
								SaveWFactoryData("WFactory127MMAmmo");
								GivePlayerCash( playerid, FACTORY_L_REWARD );
								DynamicFactions[FACTIONID_GOVERNMENT][fBank] -= FACTORY_L_REWARD;
								SaveFData(FACTIONID_GOVERNMENT, "Bank");
								format(string, sizeof(string), "[MOUNT:] End - WFactory127MMAmmo ++ for legal factory by %s", GetPlayerNameEx(playerid));
								WFactoryLog(string);
							}
							else
							{
								DynamicFactions[gPlayerData[playerid][pFaction]][WFactory127MMAmmo] += 1;
								SaveFData( fID, "WFactory127MMAmmo" );
								format(string, sizeof(string), "[MOUNT:] End - WFactory127MMAmmo ++ for illegal factory id %d by %s", fID, GetPlayerNameEx(playerid));
								WFactoryLog(string);
							}
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 97 ), 4 );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 98 ), 2 );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 99 ), 2 );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 100 ), 2 );
							gPlayerData[playerid][pPartType] = 0;
							gPlayerData[playerid][pPartItem] = 0;
							SavePlayerData( playerid, "PartType" );
							SavePlayerData( playerid, "PartItem" );
							ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, WF_ASSEMBLE_F_AMMO, DIALOG_INFO_EXIT, "" );
							gPlayerData[playerid][pMountingW] = 0;
							return 1;
						}
						gPlayerData[playerid][pMountingW] = 0;
						return 1;
					}
				}
			}
		}
		case WF_PART:
		{
			switch( gPlayerData[playerid][pPartItem] )
			{
				case WF_PISTOLPART1:
				{
					if( gPlayerData[playerid][pMountsPasses] == 0 )
					{
						gPlayerData[playerid][pMountsLeft]--;
						SavePlayerData(playerid, "MountsLeft");
						/* Weapon receave */
						if( gPlayerData[playerid][pMountsLeft] == 0 )
						{
							if( gPlayerData[playerid][pJob] == 22 )
							{
								WFactoryLegalLight[WFactoryPistolPart1]++;
								SaveWFactoryData("WFactoryPistolPart1");
								GivePlayerCash( playerid, FACTORY_L_REWARD );
								DynamicFactions[FACTIONID_GOVERNMENT][fBank] -= FACTORY_L_REWARD;
								SaveFData(FACTIONID_GOVERNMENT, "Bank");
								format(string, sizeof(string), "[MOUNT:] End - WFactoryPistolPart1 ++ for legal factory by %s", GetPlayerNameEx(playerid));
								WFactoryLog(string);
							}
							else
							{
								DynamicFactions[fID][WFactoryPistolPart1]++;
								SaveFData( fID, "WFactoryPistolPart1" );
								format(string, sizeof(string), "[MOUNT:] End - WFactoryPistolPart1 ++ for illegal factory id %d by %s", fID, GetPlayerNameEx(playerid));
								WFactoryLog(string);
							}
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 61 ) );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 62 ) );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 63 ) );
							gPlayerData[playerid][pPartType] = 0;
							gPlayerData[playerid][pPartItem] = 0;
							SavePlayerData(playerid, "PartType");
							SavePlayerData(playerid, "PartItem");
							ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, WF_ASSEMBLE_F_PART, DIALOG_INFO_EXIT, "" );
							gPlayerData[playerid][pMountingW] = 0;
							return 1;
						}
						gPlayerData[playerid][pMountingW] = 0;
						return 1;
					}
				}
				case WF_PISTOLPART2:
				{
					if( gPlayerData[playerid][pMountsPasses] == 0 )
					{
						gPlayerData[playerid][pMountsLeft]--;
						SavePlayerData(playerid, "MountsLeft");
						/* Weapon receave */
						if( gPlayerData[playerid][pMountsLeft] == 0 )
						{
							if( gPlayerData[playerid][pJob] == 22 )
							{
								WFactoryLegalLight[WFactoryPistolPart2]++;
								SaveWFactoryData("WFactoryPistolPart2");
								GivePlayerCash( playerid, FACTORY_L_REWARD );
								DynamicFactions[FACTIONID_GOVERNMENT][fBank] -= FACTORY_L_REWARD;
								SaveFData(FACTIONID_GOVERNMENT, "Bank");
								format(string, sizeof(string), "[MOUNT:] End - WFactoryPistolPart2 ++ for legal factory by %s", GetPlayerNameEx(playerid));
								WFactoryLog(string);
							}
							else
							{
								DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryPistolPart2]++;
								SaveFData( fID, "WFactoryPistolPart2" );
								format(string, sizeof(string), "[MOUNT:] End - WFactoryPistolPart2 ++ for illegal factory id %d by %s", fID, GetPlayerNameEx(playerid));
								WFactoryLog(string);
							}
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 64 ) );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 65 ) );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 66 ) );
							gPlayerData[playerid][pPartType] = 0;
							gPlayerData[playerid][pPartItem] = 0;
							SavePlayerData(playerid, "PartType");
							SavePlayerData(playerid, "PartItem");
							ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, WF_ASSEMBLE_F_PART, DIALOG_INFO_EXIT, "" );
							gPlayerData[playerid][pMountingW] = 0;
							return 1;
						}
						gPlayerData[playerid][pMountingW] = 0;
						return 1;
					}
				}
				case WF_PISTOLPART3:
				{
					if( gPlayerData[playerid][pMountsPasses] == 0 )
					{
						gPlayerData[playerid][pMountsLeft]--;
						SavePlayerData(playerid, "MountsLeft");
						/* Weapon receave */
						if( gPlayerData[playerid][pMountsLeft] == 0 )
						{
							if( gPlayerData[playerid][pJob] == 22 )
							{
								WFactoryLegalLight[WFactoryPistolPart3]++;
								SaveWFactoryData("WFactoryPistolPart3");
								GivePlayerCash( playerid, FACTORY_L_REWARD );
								DynamicFactions[FACTIONID_GOVERNMENT][fBank] -= FACTORY_L_REWARD;
								SaveFData(FACTIONID_GOVERNMENT, "Bank");
								format(string, sizeof(string), "[MOUNT:] End - WFactoryPistolPart3 ++ for legal factory by %s", GetPlayerNameEx(playerid));
								WFactoryLog(string);
							}
							else
							{
								DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryPistolPart3]++;
								SaveFData( fID, "WFactoryPistolPart3" );
								format(string, sizeof(string), "[MOUNT:] End - WFactoryPistolPart3 ++ for illegal factory id %d by %s", fID, GetPlayerNameEx(playerid));
								WFactoryLog(string);
							}
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 67 ) );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 68 ) );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 69 ) );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 70 ) );
							gPlayerData[playerid][pPartType] = 0;
							gPlayerData[playerid][pPartItem] = 0;
							SavePlayerData(playerid, "PartType");
							SavePlayerData(playerid, "PartItem");
							ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, WF_ASSEMBLE_F_PART, DIALOG_INFO_EXIT, "" );
							gPlayerData[playerid][pMountingW] = 0;
							return 1;
						}
						gPlayerData[playerid][pMountingW] = 0;
						return 1;
					}
				}
				case WF_RIFLEPART1:
				{
					if( gPlayerData[playerid][pMountsPasses] == 0 )
					{
						gPlayerData[playerid][pMountsLeft]--;
						SavePlayerData(playerid, "MountsLeft");
						/* Weapon receave */
						if( gPlayerData[playerid][pMountsLeft] == 0 )
						{
							if( gPlayerData[playerid][pJob] == 22 )
							{
								WFactoryLegalHeavy[WFactoryRiflePart1]++;
								SaveWFactoryData("WFactoryRiflePart1");
								GivePlayerCash( playerid, FACTORY_L_REWARD );
								DynamicFactions[FACTIONID_GOVERNMENT][fBank] -= FACTORY_L_REWARD;
								SaveFData(FACTIONID_GOVERNMENT, "Bank");
								format(string, sizeof(string), "[MOUNT:] End - WFactoryRiflePart1 ++ for legal factory by %s", GetPlayerNameEx(playerid));
								WFactoryLog(string);
							}
							else
							{
								DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryRiflePart1]++;
								SaveFData( fID, "WFactoryRiflePart1" );
								format(string, sizeof(string), "[MOUNT:] End - WFactoryRiflePart1 ++ for illegal factory id %d by %s", fID, GetPlayerNameEx(playerid));
								WFactoryLog(string);
							}
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 71 ) );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 72 ) );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 63 ) );
							gPlayerData[playerid][pPartType] = 0;
							gPlayerData[playerid][pPartItem] = 0;
							SavePlayerData(playerid, "PartType");
							SavePlayerData(playerid, "PartItem");
							ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, WF_ASSEMBLE_F_PART, DIALOG_INFO_EXIT, "" );
							gPlayerData[playerid][pMountingW] = 0;
							return 1;
						}
						gPlayerData[playerid][pMountingW] = 0;
						return 1;
					}
				}
				case WF_RIFLEPART2:
				{
					if( gPlayerData[playerid][pMountsPasses] == 0 )
					{
						gPlayerData[playerid][pMountsLeft]--;
						SavePlayerData(playerid, "MountsLeft");
						/* Weapon receave */
						if( gPlayerData[playerid][pMountsLeft] == 0 )
						{
							if( gPlayerData[playerid][pJob] == 22 )
							{
								WFactoryLegalHeavy[WFactoryRiflePart2]++;
								SaveWFactoryData("WFactoryRiflePart2");
								GivePlayerCash( playerid, FACTORY_L_REWARD );
								DynamicFactions[FACTIONID_GOVERNMENT][fBank] -= FACTORY_L_REWARD;
								SaveFData(FACTIONID_GOVERNMENT, "Bank");
								format(string, sizeof(string), "[MOUNT:] End - WFactoryRiflePart2 ++ for legal factory by %s", GetPlayerNameEx(playerid));
								WFactoryLog(string);
							}
							else
							{
								DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryRiflePart2]++;
								SaveFData( fID, "WFactoryRiflePart2" );
								format(string, sizeof(string), "[MOUNT:] End - WFactoryRiflePart2 ++ for illegal factory id %d by %s", fID, GetPlayerNameEx(playerid));
								WFactoryLog(string);
							}
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 73 ) );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 74 ) );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 75 ) );
							gPlayerData[playerid][pPartType] = 0;
							gPlayerData[playerid][pPartItem] = 0;
							SavePlayerData(playerid, "PartType");
							SavePlayerData(playerid, "PartItem");
							ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, WF_ASSEMBLE_F_PART, DIALOG_INFO_EXIT, "" );
							gPlayerData[playerid][pMountingW] = 0;
							return 1;
						}
						gPlayerData[playerid][pMountingW] = 0;
						return 1;
					}
				}
				case WF_RIFLEPART3:
				{
					if( gPlayerData[playerid][pMountsPasses] == 0 )
					{
						gPlayerData[playerid][pMountsLeft]--;
						SavePlayerData(playerid, "MountsLeft");
						/* Weapon receave */
						if( gPlayerData[playerid][pMountsLeft] == 0 )
						{
							if( gPlayerData[playerid][pJob] == 22 )
							{
								WFactoryLegalHeavy[WFactoryRiflePart3]++;
								SaveWFactoryData("WFactoryRiflePart3");
								GivePlayerCash( playerid, FACTORY_L_REWARD );
								
								format(string, sizeof(string), "[MOUNT:] End - WFactoryRiflePart3 ++ for legal factory by %s", GetPlayerNameEx(playerid));
								WFactoryLog(string);
							}
							else
							{
								DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryRiflePart3]++;
								SaveFData( fID, "WFactoryRiflePart3" );
								format(string, sizeof(string), "[MOUNT:] End - WFactoryRiflePart3 ++ for illegal factory id %d by %s", fID, GetPlayerNameEx(playerid));
								WFactoryLog(string);
							}
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 76 ) );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 77 ) );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 78 ) );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 79 ) );
							gPlayerData[playerid][pPartType] = 0;
							gPlayerData[playerid][pPartItem] = 0;
							SavePlayerData(playerid, "PartType");
							SavePlayerData(playerid, "PartItem");
							ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, WF_ASSEMBLE_F_PART, DIALOG_INFO_EXIT, "" );
							gPlayerData[playerid][pMountingW] = 0;
							return 1;
						}
						gPlayerData[playerid][pMountingW] = 0;
						return 1;
					}
				}
				case WF_RIFLEPART7:
				{
					if( gPlayerData[playerid][pMountsPasses] == 0 )
					{
						gPlayerData[playerid][pMountsLeft]--;
						SavePlayerData(playerid, "MountsLeft");
						/* Weapon receave */
						if( gPlayerData[playerid][pMountsLeft] == 0 )
						{
							if( gPlayerData[playerid][pJob] == 22 )
							{
								WFactoryLegalHeavy[WFactoryRiflePart7]++;
								SaveWFactoryData("WFactoryRiflePart7");
								GivePlayerCash( playerid, FACTORY_L_REWARD );
								DynamicFactions[FACTIONID_GOVERNMENT][fBank] -= FACTORY_L_REWARD;
								SaveFData(FACTIONID_GOVERNMENT, "Bank");
								format(string, sizeof(string), "[MOUNT:] End - WFactoryRiflePart7 ++ for legal factory by %s", GetPlayerNameEx(playerid));
								WFactoryLog(string);
							}
							else
							{
								DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryRiflePart7]++;
								SaveFData( fID, "WFactoryRiflePart7" );
								format(string, sizeof(string), "[MOUNT:] End - WFactoryRiflePart7 ++ for illegal factory id %d by %s", fID, GetPlayerNameEx(playerid));
								WFactoryLog(string);
							}
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 80 ) );
							RemovePlayerItemExUsed( playerid, PHaveItem( playerid, 1, 81 ) );
							gPlayerData[playerid][pPartType] = 0;
							gPlayerData[playerid][pPartItem] = 0;
							SavePlayerData(playerid, "PartType");
							SavePlayerData(playerid, "PartItem");
							ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, DIALOG_WMENU_TITLE_TXT, WF_ASSEMBLE_F_PART, DIALOG_INFO_EXIT, "" );
							gPlayerData[playerid][pMountingW] = 0;
							return 1;
						}
						gPlayerData[playerid][pMountingW] = 0;
						return 1;
					}
				}
			}
		}
	}
	PartsMount(playerid);
	return 1;
}