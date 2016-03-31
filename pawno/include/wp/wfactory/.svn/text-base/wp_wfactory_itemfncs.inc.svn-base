/* 
* Checks if player have apropriate items for weapon/part/ammo production
* If possible take item from faction storage 
*/
stock PlayerHaveWFItemsEx( playerid, partType, partItem )
{
	switch( partType )
	{
		case WF_WEAPON:
		{
			switch( partItem )
			{
				case WF_9MM:
				{
					#define P0COUNT1 1
					#define P0COUNT2 1
					#define P0COUNT3 1
					#define P0COUNT4 1
					#define P0COUNT5 1
					new slot, enough;
					if ( !( slot = PHaveItem( playerid, 1, 48 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart1] - P0COUNT1 ) < 0 )
							return 0;
						InsertPlayerItemEx( playerid, 1, 48, 0, 0, 0, 0, "Puste", P0COUNT1 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart1] -= P0COUNT1;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolPart1" );
					}
					else
					{
						enough = P0COUNT1 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart1] - enough) < 0 )
							return 0;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 48, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart1] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolPart1" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 49 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart2] - P0COUNT2 ) < 0 )
							return 0;
						InsertPlayerItemEx( playerid, 1, 49, 0, 0, 0, 0, "Puste", P0COUNT2 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart2] -= P0COUNT2;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolPart2" );
					}
					else
					{
						enough = P0COUNT2 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart2] - enough) < 0 )
							return 0;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 49, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart2] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolPart2" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 50 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart3] - P0COUNT3 ) < 0 )
							return 0;
						InsertPlayerItemEx( playerid, 1, 50, 0, 0, 0, 0, "Puste", P0COUNT3 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart3] -= P0COUNT3;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolPart3" );
					}
					else
					{
						enough = P0COUNT3 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart3] - enough) < 0 )
							return 0;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 50, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart3] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolPart3" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 51 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart4] - P0COUNT4 ) < 0 )
							return 0;
						InsertPlayerItemEx( playerid, 1, 51, 0, 0, 0, 0, "Puste", P0COUNT4 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart4] -= P0COUNT4;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolPart4" );
					}
					else
					{
						enough = P0COUNT4 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart4] - enough) < 0 )
							return 0;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 51, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart4] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolPart4" );
						}
					}
					if ( !( slot = PHaveItem( playerid, 1, 52 ) ) )
					{
						if( ( DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart5] - P0COUNT5 ) < 0 )
							return 0;
						InsertPlayerItemEx( playerid, 1, 52, 0, 0, 0, 0, "Puste", P0COUNT5 );
						DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart5] -= P0COUNT5;
						SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolPart5" );
					}
					else
					{
						enough = P0COUNT5 - SlotParam6(playerid, slot);
						if( enough > 0 && (DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart5] - enough) < 0 )
							return 0;
						if( enough > 0 )
						{
							InsertPlayerItemEx( playerid, 1, 52, 0, 0, 0, 0, "Puste", enough );
							DynamicFactions[ gPlayerData[playerid][pFaction] ][WFactoryPistolPart5] -= enough;
							SaveFData( gPlayerData[playerid][pFaction], "WFactoryPistolPart5" );
						}
					}
					#undef P0COUNT1
					#undef P0COUNT2
					#undef P0COUNT3
					#undef P0COUNT4
					#undef P0COUNT5
					return 1;
				}
			}
		}
	}
	return 0;
}

/* 
* Only checks if player have apropriate items for weapon/part/ammo production
*/
stock PlayerHaveWFItems( playerid, partType, partItem )
{
	switch( partType )
	{
		case WF_WEAPON:
		{
			switch( partItem )
			{
				case WF_9MM:
				{
					if ( !PHaveItem( playerid, 1, 48 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 49 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 50 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 51 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 52 ) )
						return 0;
					return 1;
				}
				case WF_9MMSIL:
				{
					if ( !PHaveItem( playerid, 1, 48 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 49 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 50 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 51 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 52 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 59 ) )
						return 0;
					return 1;
				}
				case WF_DESEAGLE:
				{
					if ( !PHaveItem( playerid, 1, 87 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 48 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 49 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 50 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 51 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 52 ) )
						return 0;
					return 1;
				}
				case WF_SHOTGUN:
				{
					if ( !PHaveItem( playerid, 1, 86 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 53 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 54 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 55 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 56 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 57 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 58 ) )
						return 0;
					return 1;
				}
				case WF_MICROSMG:
				{
					if ( !PHaveItem( playerid, 1, 48 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 49 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 50 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 51 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 52 ) )
						return 0;
					return 1;
				}
				case WF_MP5:
				{
					if ( !PHaveItem( playerid, 1, 83 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 53 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 54 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 55 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 56 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 57 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 58 ) )
						return 0;
					return 1;
				}
				case WF_AK47:
				{
					if ( !PHaveItem( playerid, 1, 84 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 53 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 54 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 55 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 56 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 57 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 58 ) )
						return 0;
					return 1;
				}
				case WF_M4:
				{
					if ( !PHaveItem( playerid, 1, 85 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 53 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 54 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 55 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 56 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 57 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 58 ) )
						return 0;
					return 1;
				}
				case WF_TEC9:
				{
					if ( !PHaveItem( playerid, 1, 82 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 48 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 49 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 50 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 51 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 52 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 59 ) )
						return 0;
					return 1;
				}
				case WF_RIFLE:
				{
					if ( !PHaveItem( playerid, 1, 88 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 53 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 54 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 55 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 56 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 57 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 58 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 60 ) )
						return 0;
					return 1;
				}
				case WF_SRIFLE:
				{
					if ( !PHaveItem( playerid, 1, 89 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 53 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 54 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 55 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 56 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 57 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 58 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 60 ) )
						return 0;
					return 1;
				}
			}
		}
		case WF_PART:
		{
			switch( partItem )
			{
				case WF_PISTOLPART1:
				{
					if( !PHaveItem( playerid, 1, 61 ) )
						return 0;
					if( !PHaveItem( playerid, 1, 62 ) )
						return 0;
					if( !PHaveItem( playerid, 1, 63 ) )
						return 0;
					return 1;
				}
				case WF_PISTOLPART2:
				{
					if( !PHaveItem( playerid, 1, 64 ) )
						return 0;
					if( !PHaveItem( playerid, 1, 65 ) )
						return 0;
					if( !PHaveItem( playerid, 1, 66 ) )
						return 0;
					return 1;
				}
				case WF_PISTOLPART3:
				{
					if( !PHaveItem( playerid, 1, 67 ) )
						return 0;
					if( !PHaveItem( playerid, 1, 68 ) )
						return 0;
					if( !PHaveItem( playerid, 1, 69 ) )
						return 0;
					if( !PHaveItem( playerid, 1, 70 ) )
						return 0;
					return 1;
				}
				case WF_RIFLEPART1:
				{
					if( !PHaveItem( playerid, 1, 71 ) )
						return 0;
					if( !PHaveItem( playerid, 1, 72 ) )
						return 0;
					if( !PHaveItem( playerid, 1, 63 ) )
						return 0;
					return 1;
				}
				case WF_RIFLEPART2:
				{
					if( !PHaveItem( playerid, 1, 73 ) )
						return 0;
					if( !PHaveItem( playerid, 1, 74 ) )
						return 0;
					if( !PHaveItem( playerid, 1, 75 ) )
						return 0;
					return 1;
				}
				case WF_RIFLEPART3:
				{
					if( !PHaveItem( playerid, 1, 76 ) )
						return 0;
					if( !PHaveItem( playerid, 1, 77 ) )
						return 0;
					if( !PHaveItem( playerid, 1, 78 ) )
						return 0;
					if( !PHaveItem( playerid, 1, 79 ) )
						return 0;
					return 1;
				}
				case WF_RIFLEPART7:
				{
					if( !PHaveItem( playerid, 1, 80 ) )
						return 0;
					if( !PHaveItem( playerid, 1, 81 ) )
						return 0;
					return 1;
				}
			}
		}
		case WF_AMMO:
		{
			switch( partItem )
			{
				case WF_9MM:
				{
					if ( !PHaveItem( playerid, 1, 43 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 44 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 45 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 46 ) )
						return 0;
					return 1;
				}
				case WF_50AEAMMO:
				{
					if ( !PHaveItem( playerid, 1, 101 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 102 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 103 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 104 ) )
						return 0;
					return 1;
				}
				case WF_BUCKSHOT:
				{
					if ( !PHaveItem( playerid, 1, 47 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 90 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 91 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 92 ) )
						return 0;
					return 1;
				}
				case WF_762MMAMMO:
				{
					if ( !PHaveItem( playerid, 1, 93 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 94 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 95 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 96 ) )
						return 0;
					return 1;
				}
				case WF_127MMAMMO:
				{
					if ( !PHaveItem( playerid, 1, 97 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 98 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 99 ) )
						return 0;
					if ( !PHaveItem( playerid, 1, 100 ) )
						return 0;
					return 1;
				}
			}
		}
	}
	return 0;
}

/*
* Only checks if legal factory have apropriate items for weapon/part/ammo production
*/
stock LFactoryHaveWFItems( partType, partItem )
{
	switch( partType )
	{
		case WF_WEAPON:
		{
			switch( partItem )
			{
				case WF_9MM:
				{
					if ( !WFactoryLegalLight[WFactoryPistolPart1] )
						return 0;
					if ( !WFactoryLegalLight[WFactoryPistolPart2] )
						return 0;
					if ( !WFactoryLegalLight[WFactoryPistolPart3] )
						return 0;
					if ( !WFactoryLegalLight[WFactoryPistolPart4] )
						return 0;
					if ( !WFactoryLegalLight[WFactoryPistolPart5] )
						return 0;
					return 1;
				}
				case WF_9MMSIL:
				{
					if ( !WFactoryLegalLight[WFactoryPistolPart1] )
						return 0;
					if ( !WFactoryLegalLight[WFactoryPistolPart2] )
						return 0;
					if ( !WFactoryLegalLight[WFactoryPistolPart3] )
						return 0;
					if ( !WFactoryLegalLight[WFactoryPistolPart4] )
						return 0;
					if ( !WFactoryLegalLight[WFactoryPistolPart5] )
						return 0;
					if ( !WFactoryLegalLight[WFactoryPistolPart6] )
						return 0;
					return 1;
				}
				case WF_DESEAGLE:
				{
					if ( !WFactoryLegalLight[WFactoryDesEaglePart] )
						return 0;
					if ( !WFactoryLegalLight[WFactoryPistolPart1] )
						return 0;
					if ( !WFactoryLegalLight[WFactoryPistolPart2] )
						return 0;
					if ( !WFactoryLegalLight[WFactoryPistolPart3] )
						return 0;
					if ( !WFactoryLegalLight[WFactoryPistolPart4] )
						return 0;
					if ( !WFactoryLegalLight[WFactoryPistolPart5] )
						return 0;
					return 1;
				}
				case WF_SHOTGUN:
				{
					if ( !WFactoryLegalHeavy[WFactoryShotPart] )
						return 0;
					if ( !WFactoryLegalHeavy[WFactoryRiflePart1] )
						return 0;
					if ( !WFactoryLegalHeavy[WFactoryRiflePart2] )
						return 0;
					if ( !WFactoryLegalHeavy[WFactoryRiflePart3] )
						return 0;
					if ( !WFactoryLegalHeavy[WFactoryRiflePart4] )
						return 0;
					if ( !WFactoryLegalHeavy[WFactoryRiflePart5] )
						return 0;
					if ( !WFactoryLegalHeavy[WFactoryRiflePart6] )
						return 0;
					return 1;
				}
				case WF_MICROSMG:
				{
					if ( !WFactoryLegalLight[WFactoryPistolPart1] )
						return 0;
					if ( !WFactoryLegalLight[WFactoryPistolPart2] )
						return 0;
					if ( !WFactoryLegalLight[WFactoryPistolPart3] )
						return 0;
					if ( !WFactoryLegalLight[WFactoryPistolPart4] )
						return 0;
					if ( !WFactoryLegalLight[WFactoryPistolPart5] )
						return 0;
					return 1;
				}
				case WF_MP5:
				{
					if ( !WFactoryLegalHeavy[WFactoryMP5Part] )
						return 0;
					if ( !WFactoryLegalHeavy[WFactoryRiflePart1] )
						return 0;
					if ( !WFactoryLegalHeavy[WFactoryRiflePart2] )
						return 0;
					if ( !WFactoryLegalHeavy[WFactoryRiflePart3] )
						return 0;
					if ( !WFactoryLegalHeavy[WFactoryRiflePart4] )
						return 0;
					if ( !WFactoryLegalHeavy[WFactoryRiflePart5] )
						return 0;
					if ( !WFactoryLegalHeavy[WFactoryRiflePart6] )
						return 0;
					return 1;
				}
				case WF_AK47:
				{
					if ( !WFactoryLegalHeavy[WFactoryAK47Part] )
						return 0;
					if ( !WFactoryLegalHeavy[WFactoryRiflePart1] )
						return 0;
					if ( !WFactoryLegalHeavy[WFactoryRiflePart2] )
						return 0;
					if ( !WFactoryLegalHeavy[WFactoryRiflePart3] )
						return 0;
					if ( !WFactoryLegalHeavy[WFactoryRiflePart4] )
						return 0;
					if ( !WFactoryLegalHeavy[WFactoryRiflePart5] )
						return 0;
					if ( !WFactoryLegalHeavy[WFactoryRiflePart6] )
						return 0;
					return 1;
				}
				case WF_M4:
				{
					if ( !WFactoryLegalHeavy[WFactoryM4Part] )
						return 0;
					if ( !WFactoryLegalHeavy[WFactoryRiflePart1] )
						return 0;
					if ( !WFactoryLegalHeavy[WFactoryRiflePart2] )
						return 0;
					if ( !WFactoryLegalHeavy[WFactoryRiflePart3] )
						return 0;
					if ( !WFactoryLegalHeavy[WFactoryRiflePart4] )
						return 0;
					if ( !WFactoryLegalHeavy[WFactoryRiflePart5] )
						return 0;
					if ( !WFactoryLegalHeavy[WFactoryRiflePart6] )
						return 0;
					return 1;
				}
				case WF_TEC9:
				{
					if ( !WFactoryLegalLight[WFactoryTec9Part] )
						return 0;
					if ( !WFactoryLegalLight[WFactoryPistolPart1] )
						return 0;
					if ( !WFactoryLegalLight[WFactoryPistolPart2] )
						return 0;
					if ( !WFactoryLegalLight[WFactoryPistolPart3] )
						return 0;
					if ( !WFactoryLegalLight[WFactoryPistolPart4] )
						return 0;
					if ( !WFactoryLegalLight[WFactoryPistolPart5] )
						return 0;
					if ( !WFactoryLegalLight[WFactoryPistolPart6] )
						return 0;
					return 1;
				}
				case WF_RIFLE:
				{
					if ( !WFactoryLegalHeavy[WFactoryRiflePart] )
						return 0;
					if ( !WFactoryLegalHeavy[WFactoryRiflePart1] )
						return 0;
					if ( !WFactoryLegalHeavy[WFactoryRiflePart2] )
						return 0;
					if ( !WFactoryLegalHeavy[WFactoryRiflePart3] )
						return 0;
					if ( !WFactoryLegalHeavy[WFactoryRiflePart4] )
						return 0;
					if ( !WFactoryLegalHeavy[WFactoryRiflePart5] )
						return 0;
					if ( !WFactoryLegalHeavy[WFactoryRiflePart6] )
						return 0;
					return 1;
				}
				case WF_SRIFLE:
				{
					if ( !WFactoryLegalHeavy[WFactorySniperPart] )
						return 0;
					if ( !WFactoryLegalHeavy[WFactoryRiflePart1] )
						return 0;
					if ( !WFactoryLegalHeavy[WFactoryRiflePart2] )
						return 0;
					if ( !WFactoryLegalHeavy[WFactoryRiflePart3] )
						return 0;
					if ( !WFactoryLegalHeavy[WFactoryRiflePart4] )
						return 0;
					if ( !WFactoryLegalHeavy[WFactoryRiflePart5] )
						return 0;
					if ( !WFactoryLegalHeavy[WFactoryRiflePart6] )
						return 0;
					if ( !WFactoryLegalHeavy[WFactoryRiflePart7] )
						return 0;
					return 1;
				}
			}
		}
		case WF_PART:
		{
			switch( partItem )
			{
				case WF_PISTOLPART1:
				{
					if ( !WFactoryLegalLight[WFactoryPistolS1Part1] )
						return 0;
					if ( !WFactoryLegalLight[WFactoryPistolS1Part2] )
						return 0;
					if ( !WFactoryLegalLight[WFactoryPistolS1Part3] )
						return 0;
					return 1;
				}
				case WF_PISTOLPART2:
				{
					if ( !WFactoryLegalLight[WFactoryPistolS2Part1] )
						return 0;
					if ( !WFactoryLegalLight[WFactoryPistolS2Part2] )
						return 0;
					if ( !WFactoryLegalLight[WFactoryPistolS2Part3] )
						return 0;
					return 1;
				}
				case WF_PISTOLPART3:
				{
					if ( !WFactoryLegalLight[WFactoryPistolS3Part1] )
						return 0;
					if ( !WFactoryLegalLight[WFactoryPistolS3Part2] )
						return 0;
					if ( !WFactoryLegalLight[WFactoryPistolS3Part3] )
						return 0;
					if ( !WFactoryLegalLight[WFactoryPistolS3Part4] )
						return 0;
					return 1;
				}
				case WF_RIFLEPART1:
				{
					if ( !WFactoryLegalHeavy[WFactoryRifleS1Part1] )
						return 0;
					if ( !WFactoryLegalHeavy[WFactoryRifleS1Part2] )
						return 0;
					if ( !WFactoryLegalLight[WFactoryPistolS1Part3] )
						return 0;
					return 1;
				}
				case WF_RIFLEPART2:
				{
					if ( !WFactoryLegalHeavy[WFactoryRifleS2Part1] )
						return 0;
					if ( !WFactoryLegalHeavy[WFactoryRifleS2Part2] )
						return 0;
					if ( !WFactoryLegalHeavy[WFactoryRifleS2Part3] )
						return 0;
					return 1;
				}
				case WF_RIFLEPART3:
				{
					if ( !WFactoryLegalHeavy[WFactoryRifleS3Part1] )
						return 0;
					if ( !WFactoryLegalHeavy[WFactoryRifleS3Part2] )
						return 0;
					if ( !WFactoryLegalHeavy[WFactoryRifleS3Part3] )
						return 0;
					if ( !WFactoryLegalHeavy[WFactoryRifleS3Part4] )
						return 0;
					return 1;
				}
				case WF_RIFLEPART7:
				{
					if ( !WFactoryLegalHeavy[WFactoryRifleS6Part1] )
						return 0;
					if ( !WFactoryLegalHeavy[WFactoryRifleS6Part2] )
						return 0;
					return 1;
				}
			}
		}
		case WF_AMMO:
		{
			switch( partItem )
			{
				case WF_9MM:
				{
					if ( !WFactoryLegalLight[WFactoryAmmoPart1a] )
						return 0;
					if ( !WFactoryLegalLight[WFactoryAmmoPart2a] )
						return 0;
					if ( !WFactoryLegalLight[WFactoryAmmoPart3a] )
						return 0;
					if ( !WFactoryLegalLight[WFactoryAmmoPart4a] )
						return 0;
					return 1;
				}
				case WF_50AEAMMO:
				{
					if ( !WFactoryLegalLight[WFactoryAmmoPart1e] )
						return 0;
					if ( !WFactoryLegalLight[WFactoryAmmoPart2e] )
						return 0;
					if ( !WFactoryLegalLight[WFactoryAmmoPart3e] )
						return 0;
					if ( !WFactoryLegalLight[WFactoryAmmoPart4e] )
						return 0;
					return 1;
				}
				case WF_BUCKSHOT:
				{
					if ( !WFactoryLegalLight[WFactoryAmmoPart1b] )
						return 0;
					if ( !WFactoryLegalLight[WFactoryAmmoPart2b] )
						return 0;
					if ( !WFactoryLegalLight[WFactoryAmmoPart3b] )
						return 0;
					if ( !WFactoryLegalLight[WFactoryAmmoPart4b] )
						return 0;
					return 1;
				}
				case WF_762MMAMMO:
				{
					if ( !WFactoryLegalLight[WFactoryAmmoPart1c] )
						return 0;
					if ( !WFactoryLegalLight[WFactoryAmmoPart2c] )
						return 0;
					if ( !WFactoryLegalLight[WFactoryAmmoPart3c] )
						return 0;
					if ( !WFactoryLegalLight[WFactoryAmmoPart4c] )
						return 0;
					return 1;
				}
				case WF_127MMAMMO:
				{
					if ( !WFactoryLegalLight[WFactoryAmmoPart1d] )
						return 0;
					if ( !WFactoryLegalLight[WFactoryAmmoPart2d] )
						return 0;
					if ( !WFactoryLegalLight[WFactoryAmmoPart3d] )
						return 0;
					if ( !WFactoryLegalLight[WFactoryAmmoPart4d] )
						return 0;
					return 1;
				}
			}
		}
	}
	return 0;
}
