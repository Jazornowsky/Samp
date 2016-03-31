/***
*
* File: wp_utils_weapons.inc
* Auth: Damian Wojdat and Robert B¹bel
* Date: 11.03.2012
* Desc: Internal script function related to weapons.
*
*************************************************************************************************************/

stock PlayerHaveWeapon(playerid, gunID)
{
	new tGunID, tGunAmmo, slot;
	if( GetPlayerWeapon(playerid) == gunID )
		return GetPlayerAmmo(playerid);
	slot = WeaponSlot(gunID);
	GetPlayerWeaponData(playerid, slot, tGunID, tGunAmmo);
	if( tGunID == gunID )
		return tGunAmmo;
	return 0;
}	

stock AddPlayerAmmo(playerid, gunID, gunAmmo)
{
	new tGunID, tGunAmmo, slot;
	if( GetPlayerWeapon(playerid) == gunID ) // sprawdzenie czy aktualnie wybrana bron gracza to bron == gunID
	{
		tGunAmmo = GetPlayerAmmo(playerid);
		GivePlayerGun(playerid, gunID, tGunAmmo + gunAmmo);
		return 1;
	}
	slot = WeaponSlot(gunID);
	GetPlayerWeaponData(playerid, slot, tGunID, tGunAmmo);
	if(tGunID == 0 || tGunID != gunID) // sprawdzenie czy gracz posiada bron na pozostalych slotach ( domyslnie 13 slotow w grze )
	{
		switch(gunID)
		{
			case 22: 
			{
				InsertPlayerItemEx(playerid, 1, 16, 0, 0, 0, 0, "Puste", 1);
				InsertPlayerItemEx(playerid, 1, 36, 0, 0, 0, 0, "Puste", gunAmmo);
			}
			case 23: 
			{
				InsertPlayerItemEx(playerid, 1, 17, 0, 0, 0, 0, "Puste", 1);
				InsertPlayerItemEx(playerid, 1, 36, 0, 0, 0, 0, "Puste", gunAmmo);
			}
			case 24:
			{
				InsertPlayerItemEx(playerid, 1, 18, 0, 0, 0, 0, "Puste", 1);
				InsertPlayerItemEx(playerid, 1, 37, 0, 0, 0, 0, "Puste", gunAmmo);
			}
			case 25:
			{
				InsertPlayerItemEx(playerid, 1, 19, 0, 0, 0, 0, "Puste", 1);
				InsertPlayerItemEx(playerid, 1, 39, 0, 0, 0, 0, "Puste", gunAmmo);
			}
			case 26:
			{
				InsertPlayerItemEx(playerid, 1, 20, 0, 0, 0, 0, "Puste", 1);
				InsertPlayerItemEx(playerid, 1, 38, 0, 0, 0, 0, "Puste", gunAmmo);
			}
			case 27:
			{
				InsertPlayerItemEx(playerid, 1, 21, 0, 0, 0, 0, "Puste", 1);
				InsertPlayerItemEx(playerid, 1, 38, 0, 0, 0, 0, "Puste", gunAmmo);
			}
			case 28:
			{
				InsertPlayerItemEx(playerid, 1, 22, 0, 0, 0, 0, "Puste", 1);
				InsertPlayerItemEx(playerid, 1, 36, 0, 0, 0, 0, "Puste", gunAmmo);
			}
			case 29:
			{
				InsertPlayerItemEx(playerid, 1, 23, 0, 0, 0, 0, "Puste", 1);
				InsertPlayerItemEx(playerid, 1, 36, 0, 0, 0, 0, "Puste", gunAmmo);
			}
			case 30:
			{
				InsertPlayerItemEx(playerid, 1, 24, 0, 0, 0, 0, "Puste", 1);
				InsertPlayerItemEx(playerid, 1, 39, 0, 0, 0, 0, "Puste", gunAmmo);
			}
			case 31:
			{
				InsertPlayerItemEx(playerid, 1, 25, 0, 0, 0, 0, "Puste", 1);
				InsertPlayerItemEx(playerid, 1, 39, 0, 0, 0, 0, "Puste", gunAmmo);
			}
			case 32:
			{
				InsertPlayerItemEx(playerid, 1, 26, 0, 0, 0, 0, "Puste", 1);
				InsertPlayerItemEx(playerid, 1, 36, 0, 0, 0, 0, "Puste", gunAmmo);
			}
			case 33:
			{
				InsertPlayerItemEx(playerid, 1, 27, 0, 0, 0, 0, "Puste", 1);
				InsertPlayerItemEx(playerid, 1, 40, 0, 0, 0, 0, "Puste", gunAmmo);
			}
			case 34:
			{
				InsertPlayerItemEx(playerid, 1, 28, 0, 0, 0, 0, "Puste", 1);
				InsertPlayerItemEx(playerid, 1, 40, 0, 0, 0, 0, "Puste", gunAmmo);
			}
			case 35:
			{
				InsertPlayerItemEx(playerid, 1, 29, 0, 0, 0, 0, "Puste", gunAmmo);
				InsertPlayerItemEx(playerid, 1, 41, 0, 0, 0, 0, "Puste", gunAmmo);
			}
			case 36:
			{
				InsertPlayerItemEx(playerid, 1, 30, 0, 0, 0, 0, "Puste", 1);
				InsertPlayerItemEx(playerid, 1, 41, 0, 0, 0, 0, "Puste", gunAmmo);
			}
			case 37:
			{
				InsertPlayerItemEx(playerid, 1, 31, 0, 0, 0, 0, "Puste", 1);
				InsertPlayerItemEx(playerid, 1, 42, 0, 0, 0, 0, "Puste", gunAmmo);
			}
			case 38:
			{
				InsertPlayerItemEx(playerid, 1, 32, 0, 0, 0, 0, "Puste", 1);
				InsertPlayerItemEx(playerid, 1, 39, 0, 0, 0, 0, "Puste", gunAmmo);
			}
			case 39: InsertPlayerItemEx(playerid, 1, 33, 0, 0, 0, 0, "Puste", gunAmmo);
			case 41: InsertPlayerItemEx(playerid, 1, 34, 0, 0, 0, 0, "Puste", gunAmmo);
			case 42: InsertPlayerItemEx(playerid, 1, 35, 0, 0, 0, 0, "Puste", gunAmmo);
		}
		return 1;
	}
	GivePlayerGun(playerid, gunID, gunAmmo); // przekazanie graczowi nowej broni
	return 0;
}

/*
* Checks if player carry weapon in normal slot, if not, add weapon to player items.
* Also checks if player factions have enough ammo or weapons for player.
* Removes apropriate amount of weapon/ammo from faction
*/
stock AddPlayerAmmoF(playerid, gunID, gunAmmo)
{
	new string[256];
	new fID = gPlayerData[playerid][pFaction];
	if( GetPlayerWeapon(playerid) != gunID )
	{
		switch( gunID )
		{
			case 22: // 9mm
			{
				if( DynamicFactions[fID][WFactory9MM] <= 0 )
					return 0;
				else if( !PHaveItem( playerid, 1, 16 ) )
				{
					InsertPlayerItemEx(playerid, 1, 16, 0, 0, 0, 0, "Puste", 1);
					DynamicFactions[fID][WFactory9MM]--;
					SaveFData( fID, "WFactory9MM" );
					format(string, sizeof(string), "[DUTY:] Taken WFactory9MM from factionid %d by %s", fID, GetPlayerNameEx(playerid));
					DutyLog(string);
				}
			}
			case 23: // 9mm sil
			{
				if( DynamicFactions[fID][WFactory9MMSil] <= 0 )
					return 0;
				else if( !PHaveItem( playerid, 1, 17 ) )
				{
					InsertPlayerItemEx(playerid, 1, 17, 0, 0, 0, 0, "Puste", 1);
					DynamicFactions[fID][WFactory9MMSil]--;
					SaveFData( fID, "WFactory9MMSil" );
					format(string, sizeof(string), "[DUTY:] Taken WFactory9MMSil from factionid %d by %s", fID, GetPlayerNameEx(playerid));
					DutyLog(string);
				}
			}
			case 24: // des eagle
			{
				if( DynamicFactions[fID][WFactoryDesEagle] <= 0 )
					return 0;
				else if( !PHaveItem( playerid, 1, 18 ) )
				{
					InsertPlayerItemEx(playerid, 1, 18, 0, 0, 0, 0, "Puste", 1);
					DynamicFactions[fID][WFactoryDesEagle]--;
					SaveFData( fID, "WFactoryDesEagle" );
					format(string, sizeof(string), "[DUTY:] Taken WFactoryDesEagle from factionid %d by %s", fID, GetPlayerNameEx(playerid));
					DutyLog(string);
				}
			}
			case 25: // shotgun
			{
				if( DynamicFactions[fID][WFactoryShotgun] <= 0 )
					return 0;
				else if( !PHaveItem( playerid, 1, 19 ) )
				{
					InsertPlayerItemEx(playerid, 1, 19, 0, 0, 0, 0, "Puste", 1);
					DynamicFactions[fID][WFactoryShotgun]--;
					SaveFData( fID, "WFactoryShotgun" );
					format(string, sizeof(string), "[DUTY:] Taken WFactoryShotgun from factionid %d by %s", fID, GetPlayerNameEx(playerid));
					DutyLog(string);
				}
			}
			case 28: // msmg
			{
				if( DynamicFactions[fID][WFactoryMicroSMG] <= 0 )
					return 0;
				else if( !PHaveItem( playerid, 1, 22 ) )
				{
					InsertPlayerItemEx(playerid, 1, 22, 0, 0, 0, 0, "Puste", 1);
					DynamicFactions[fID][WFactoryMicroSMG]--;
					SaveFData( fID, "WFactoryMicroSMG" );
					format(string, sizeof(string), "[DUTY:] Taken WFactoryMicroSMG from factionid %d by %s", fID, GetPlayerNameEx(playerid));
					DutyLog(string);
				}
			}
			case 29: // mp5
			{
				if( DynamicFactions[fID][WFactoryMP5] <= 0 )
					return 0;
				else if( !PHaveItem( playerid, 1, 23 ) )
				{
					InsertPlayerItemEx(playerid, 1, 23, 0, 0, 0, 0, "Puste", 1);
					DynamicFactions[fID][WFactoryMP5]--;
					SaveFData( fID, "WFactoryMP5" );
					format(string, sizeof(string), "[DUTY:] Taken WFactoryMP5 from factionid %d by %s", fID, GetPlayerNameEx(playerid));
					DutyLog(string);
				}
			}
			case 30: // AK47
			{
				if( DynamicFactions[fID][WFactoryAK47] <= 0 )
					return 0;
				else if( !PHaveItem( playerid, 1, 24 ) )
				{
					InsertPlayerItemEx(playerid, 1, 24, 0, 0, 0, 0, "Puste", 1);
					DynamicFactions[fID][WFactoryAK47]--;
					SaveFData( fID, "WFactoryAK47" );
					format(string, sizeof(string), "[DUTY:] Taken WFactoryAK47 from factionid %d by %s", fID, GetPlayerNameEx(playerid));
					DutyLog(string);
				}
			}
			case 31: // m4
			{
				if( DynamicFactions[fID][WFactoryM4] <= 0 )
					return 0;
				else if( !PHaveItem( playerid, 1, 25 ) )
				{
					InsertPlayerItemEx(playerid, 1, 25, 0, 0, 0, 0, "Puste", 1);
					DynamicFactions[fID][WFactoryM4]--;
					SaveFData( fID, "WFactoryM4" );
					format(string, sizeof(string), "[DUTY:] Taken WFactoryM4 from factionid %d by %s", fID, GetPlayerNameEx(playerid));
					DutyLog(string);
				}
			}
			case 32: // tec9
			{
				if( DynamicFactions[fID][WFactoryTec9] <= 0 )
					return 0;
				else if( !PHaveItem( playerid, 1, 26 ) )
				{
					InsertPlayerItemEx(playerid, 1, 26, 0, 0, 0, 0, "Puste", 1);
					DynamicFactions[fID][WFactoryTec9]--;
					SaveFData( fID, "WFactoryTec9" );
					format(string, sizeof(string), "[DUTY:] Taken WFactoryTec9 from factionid %d by %s", fID, GetPlayerNameEx(playerid));
					DutyLog(string);
				}
			}
			case 33: // rifle
			{
				if( DynamicFactions[fID][WFactoryRifle] <= 0 )
					return 0;
				else if( !PHaveItem( playerid, 1, 27 ) )
				{
					InsertPlayerItemEx(playerid, 1, 27, 0, 0, 0, 0, "Puste", 1);
					DynamicFactions[fID][WFactoryRifle]--;
					SaveFData( fID, "WFactoryRifle" );
					format(string, sizeof(string), "[DUTY:] Taken WFactoryRifle from factionid %d by %s", fID, GetPlayerNameEx(playerid));
					DutyLog(string);
				}
			}
			case 34: // srifle
			{
				if( DynamicFactions[fID][WFactorySRifle] <= 0 )
					return 0;
				else if( !PHaveItem( playerid, 1, 28 ) )
				{
					InsertPlayerItemEx(playerid, 1, 28, 0, 0, 0, 0, "Puste", 1);
					DynamicFactions[fID][WFactorySRifle]--;
					SaveFData( fID, "WFactorySRifle" );
					format(string, sizeof(string), "[DUTY:] Taken WFactorySRifle from factionid %d by %s", fID, GetPlayerNameEx(playerid));
					DutyLog(string);
				}
			}
		}
	}
	switch( gunID )
	{
		case 22, 23, 28, 29, 32: // 9mm ammo
		{
			if( DynamicFactions[fID][WFactory9MMAmmo] < gunAmmo )
				return 0;
			else
			{
				InsertPlayerItemEx(playerid, 1, 36, 0, 0, 0, 0, "Puste", gunAmmo);
				DynamicFactions[fID][WFactory9MMAmmo] -= gunAmmo;
				SaveFData( fID, "WFactory9MMAmmo" );
				format(string, sizeof(string), "[DUTY:] Taken %d WFactory9MMAmmo from factionid %d by %s", gunAmmo, fID, GetPlayerNameEx(playerid));
				DutyLog(string);
			}
		}
		case 24: // des eagle
		{
			if( DynamicFactions[fID][WFactory50AEAmmo] < gunAmmo )
				return 0;
			else
			{
				InsertPlayerItemEx(playerid, 1, 37, 0, 0, 0, 0, "Puste", gunAmmo);
				DynamicFactions[fID][WFactory50AEAmmo] -= gunAmmo;
				SaveFData( fID, "WFactory50AEAmmo" );
				format(string, sizeof(string), "[DUTY:] Taken %d WFactory50AEAmmo from factionid %d by %s", gunAmmo, fID, GetPlayerNameEx(playerid));
				DutyLog(string);
			}
		}
		case 25: // shotgun
		{
			if( DynamicFactions[fID][WFactoryBuckshot] < gunAmmo )
				return 0;
			else
			{
				InsertPlayerItemEx(playerid, 1, 38, 0, 0, 0, 0, "Puste", gunAmmo);
				DynamicFactions[fID][WFactoryBuckshot] -= gunAmmo;
				SaveFData( fID, "WFactoryBuckshot" );
				format(string, sizeof(string), "[DUTY:] Taken %d WFactoryBuckshot from factionid %d by %s", gunAmmo, fID, GetPlayerNameEx(playerid));
				DutyLog(string);
			}
		}
		case 30, 31, 33: // AK47
		{
			if( DynamicFactions[fID][WFactory762MMAmmo] < gunAmmo )
				return 0;
			else
			{
				InsertPlayerItemEx(playerid, 1, 39, 0, 0, 0, 0, "Puste", gunAmmo);
				DynamicFactions[fID][WFactory762MMAmmo] -= gunAmmo;
				SaveFData( fID, "WFactory762MMAmmo" );
				format(string, sizeof(string), "[DUTY:] Taken %d WFactory762MMAmmo from factionid %d by %s", gunAmmo, fID, GetPlayerNameEx(playerid));
				DutyLog(string);
			}
		}
		case 34: // srifle
		{
			if( DynamicFactions[fID][WFactory127MMAmmo] < gunAmmo )
				return 0;
			else
			{
				InsertPlayerItemEx(playerid, 1, 40, 0, 0, 0, 0, "Puste", gunAmmo);
				DynamicFactions[fID][WFactory127MMAmmo] -= gunAmmo;
				SaveFData( fID, "WFactory127MMAmmo" );
				format(string, sizeof(string), "[DUTY:] Taken %d WFactory127MMAmmo from factionid %d by %s", gunAmmo, fID, GetPlayerNameEx(playerid));
				DutyLog(string);
			}
		}
	}
	return 0;
}

/*
* Return weapons and ammo gained in duty
*/
stock ReturnPlayerAmmoF(playerid, gunID, gunAmmo)
{
	new fID = gPlayerData[playerid][pFaction];
	new weaponInSlot, ammoInSlot, slot[MAX_PLAYER_ITEM_SLOT];
	switch(gunID)
	{
		case 1: // kastet
		{
			if(PHaveItem(playerid, 1, 147))
			{
				RemovePlayerItemExUsed(playerid, PHaveItem(playerid, 1, 147));
			}
			else
			{
				GetPlayerWeaponData(playerid, WeaponIdToSlot(gunID), weaponInSlot, ammoInSlot);
				if(weaponInSlot == gunID)
				{
					RemoveWeaponFromSlot(playerid, WeaponIdToSlot(gunID));
				}
			}
		}
		case 3: // pa³ka
		{
			if(PHaveItem(playerid, 1, 145))
			{
				RemovePlayerItemExUsed(playerid, PHaveItem(playerid, 1, 145));
			}
			else
			{
				GetPlayerWeaponData(playerid, WeaponIdToSlot(gunID), weaponInSlot, ammoInSlot);
				if(weaponInSlot == gunID)
				{
					RemoveWeaponFromSlot(playerid, WeaponIdToSlot(gunID));
				}
			}
		}
		case 4: // nó¿
		{
			if(PHaveItem(playerid, 1, 148))
			{
				RemovePlayerItemExUsed(playerid, PHaveItem(playerid, 1, 148));
			}
			else
			{
				GetPlayerWeaponData(playerid, WeaponIdToSlot(gunID), weaponInSlot, ammoInSlot);
				if(weaponInSlot == gunID)
				{
					RemoveWeaponFromSlot(playerid, WeaponIdToSlot(gunID));
				}
			}
		}
		case 5: // baseball
		{
			GetPlayerWeaponData(playerid, WeaponIdToSlot(gunID), weaponInSlot, ammoInSlot);
			if(weaponInSlot == gunID)
			{
				RemoveWeaponFromSlot(playerid, WeaponIdToSlot(gunID));
			}
		}
		case 22: // 9mm
		{
			if(PHaveItem(playerid, 1, 16))
			{
				RemovePlayerItemExUsed(playerid, PHaveItem(playerid, 1, 16));
				DynamicFactions[fID][WFactory9MM]++;
				SaveFData(fID, "WFactory9MM");
			}
			else
			{
				GetPlayerWeaponData(playerid, WeaponIdToSlot(gunID), weaponInSlot, ammoInSlot);
				if(weaponInSlot == gunID)
				{
					RemoveWeaponFromSlot(playerid, WeaponIdToSlot(gunID));
					DynamicFactions[fID][WFactory9MM]++;
					SaveFData(fID, "WFactory9MM");
				}
			}
		}
		case 23: // 9mm sil
		{
			if(PHaveItem(playerid, 1, 17))
			{
				RemovePlayerItemExUsed(playerid, PHaveItem(playerid, 1, 17));
				DynamicFactions[fID][WFactory9MMSil]++;
				SaveFData(fID, "WFactory9MMSil");
			}
			else
			{
				GetPlayerWeaponData(playerid, WeaponIdToSlot(gunID), weaponInSlot, ammoInSlot);
				if(weaponInSlot == gunID)
				{
					RemoveWeaponFromSlot(playerid, WeaponIdToSlot(gunID));
					DynamicFactions[fID][WFactory9MMSil]++;
					SaveFData(fID, "WFactory9MMSil");
				}
			}
		}
		case 24: // des eagle
		{
			if(PHaveItem(playerid, 1, 18))
			{
				RemovePlayerItemExUsed(playerid, PHaveItem(playerid, 1, 18));
				DynamicFactions[fID][WFactoryDesEagle]++;
				SaveFData(fID, "WFactoryDesEagle");
			}
			else
			{
				GetPlayerWeaponData(playerid, WeaponIdToSlot(gunID), weaponInSlot, ammoInSlot);
				if(weaponInSlot == gunID)
				{
					RemoveWeaponFromSlot(playerid, WeaponIdToSlot(gunID));
					DynamicFactions[fID][WFactoryDesEagle]++;
					SaveFData(fID, "WFactoryDesEagle");
				}
			}
		}
		case 25: // shotgun
		{
			if(PHaveItem(playerid, 1, 19))
			{
				RemovePlayerItemExUsed(playerid, PHaveItem(playerid, 1, 19));
				DynamicFactions[fID][WFactoryShotgun]++;
				SaveFData(fID, "WFactoryShotgun");
			}
			else
			{
				GetPlayerWeaponData(playerid, WeaponIdToSlot(gunID), weaponInSlot, ammoInSlot);
				if(weaponInSlot == gunID)
				{
					RemoveWeaponFromSlot(playerid, WeaponIdToSlot(gunID));
					DynamicFactions[fID][WFactoryShotgun]++;
					SaveFData(fID, "WFactoryShotgun");
				}
			}
		}
		case 28: // msmg
		{
			if(PHaveItem(playerid, 1, 22))
			{
				RemovePlayerItemExUsed(playerid, PHaveItem(playerid, 1, 22));
				DynamicFactions[fID][WFactoryMicroSMG]++;
				SaveFData(fID, "WFactoryMicroSMG");
			}
			else
			{
				GetPlayerWeaponData(playerid, WeaponIdToSlot(gunID), weaponInSlot, ammoInSlot);
				if(weaponInSlot == gunID)
				{
					RemoveWeaponFromSlot(playerid, WeaponIdToSlot(gunID));
					DynamicFactions[fID][WFactoryMicroSMG]++;
					SaveFData(fID, "WFactoryMicroSMG");
				}
			}
		}
		case 29: // mp5
		{
			if(PHaveItem(playerid, 1, 23))
			{
				RemovePlayerItemExUsed(playerid, PHaveItem(playerid, 1, 23));
				DynamicFactions[fID][WFactoryMP5]++;
				SaveFData(fID, "WFactoryMP5");
			}
			else
			{
				GetPlayerWeaponData(playerid, WeaponIdToSlot(gunID), weaponInSlot, ammoInSlot);
				if(weaponInSlot == gunID)
				{
					RemoveWeaponFromSlot(playerid, WeaponIdToSlot(gunID));
					DynamicFactions[fID][WFactoryMP5]++;
					SaveFData(fID, "WFactoryMP5");
				}
			}
		}
		case 30: // AK47
		{
			if(PHaveItem(playerid, 1, 24))
			{
				RemovePlayerItemExUsed(playerid, PHaveItem(playerid, 1, 24));
				DynamicFactions[fID][WFactoryAK47]++;
				SaveFData(fID, "WFactoryAK47");
			}
			else
			{
				GetPlayerWeaponData(playerid, WeaponIdToSlot(gunID), weaponInSlot, ammoInSlot);
				if(weaponInSlot == gunID)
				{
					RemoveWeaponFromSlot(playerid, WeaponIdToSlot(gunID));
					DynamicFactions[fID][WFactoryAK47]++;
					SaveFData(fID, "WFactoryAK47");
				}
			}
		}
		case 31: // m4
		{
			if(PHaveItem(playerid, 1, 25))
			{
				RemovePlayerItemExUsed(playerid, PHaveItem(playerid, 1, 25));
				DynamicFactions[fID][WFactoryM4]++;
				SaveFData(fID, "WFactoryM4");
			}
		}
		case 32: // tec9
		{
			if(PHaveItem(playerid, 1, 26))
			{
				RemovePlayerItemExUsed(playerid, PHaveItem(playerid, 1, 26));
				DynamicFactions[fID][WFactoryTec9]++;
				SaveFData(fID, "WFactoryTec9");
			}
			else
			{
				GetPlayerWeaponData(playerid, WeaponIdToSlot(gunID), weaponInSlot, ammoInSlot);
				if(weaponInSlot == gunID)
				{
					RemoveWeaponFromSlot(playerid, WeaponIdToSlot(gunID));
					DynamicFactions[fID][WFactoryTec9]++;
					SaveFData(fID, "WFactoryTec9");
				}
			}
		}
		case 33: // rifle
		{
			if(PHaveItem(playerid, 1, 27))
			{
				RemovePlayerItemExUsed(playerid, PHaveItem(playerid, 1, 27));
				DynamicFactions[fID][WFactoryRifle]++;
				SaveFData(fID, "WFactoryRifle");
			}
			else
			{
				GetPlayerWeaponData(playerid, WeaponIdToSlot(gunID), weaponInSlot, ammoInSlot);
				if(weaponInSlot == gunID)
				{
					RemoveWeaponFromSlot(playerid, WeaponIdToSlot(gunID));
					DynamicFactions[fID][WFactoryRifle]++;
					SaveFData(fID, "WFactoryRifle");
				}
			}
		}
		case 34: // srifle
		{
			if(PHaveItem(playerid, 1, 28))
			{
				RemovePlayerItemExUsed(playerid, PHaveItem(playerid, 1, 28));
				DynamicFactions[fID][WFactorySRifle]++;
				SaveFData(fID, "WFactorySRifle");
			}
			else
			{
				GetPlayerWeaponData(playerid, WeaponIdToSlot(gunID), weaponInSlot, ammoInSlot);
				if(weaponInSlot == gunID)
				{
					RemoveWeaponFromSlot(playerid, WeaponIdToSlot(gunID));
					DynamicFactions[fID][WFactorySRifle]++;
					SaveFData(fID, "WFactorySRifle");
				}
			}
		}
	}
	
	switch(gunID)
	{
		case 22, 23, 28, 29, 32: // 9mm ammo
		{
			PHaveItemEx(playerid, 1, 36, slot);
			
			for(new k = 1; k <= MAX_PLAYER_ITEM_SLOT; k++)
			{
				if(slot[k-1])
				{
					DynamicFactions[fID][WFactory9MMAmmo] += SlotParam6(playerid, slot[k-1]);
					RemovePlayerItemUsed(playerid, k);
				}
			}
			
			SaveFData(fID, "WFactory9MMAmmo");
		}
		case 24: // des eagle
		{
			PHaveItemEx(playerid, 1, 37, slot);
			
			for(new k = 1; k <= MAX_PLAYER_ITEM_SLOT; k++)
			{
				if(slot[k-1])
				{
					DynamicFactions[fID][WFactory50AEAmmo] += SlotParam6(playerid, slot[k-1]);
					RemovePlayerItemUsed(playerid, k);
				}
			}
			
			SaveFData(fID, "WFactory50AEAmmo");
		}
		case 25: // shotgun
		{
			PHaveItemEx(playerid, 1, 38, slot);
			
			for(new k = 1; k <= MAX_PLAYER_ITEM_SLOT; k++)
			{
				if(slot[k-1])
				{
					DynamicFactions[fID][WFactoryBuckshot] += SlotParam6(playerid, slot[k-1]);
					RemovePlayerItemUsed(playerid, k);
				}
			}
			
			SaveFData(fID, "WFactoryBuckshot");
		}
		case 30, 31, 33: // AK47
		{
			PHaveItemEx(playerid, 1, 39, slot);
			
			for(new k = 1; k <= MAX_PLAYER_ITEM_SLOT; k++)
			{
				if(slot[k-1])
				{
					DynamicFactions[fID][WFactory762MMAmmo] += SlotParam6(playerid, slot[k-1]);
					RemovePlayerItemUsed(playerid, k);
				}
			}
		
			SaveFData(fID, "WFactory762MMAmmo");
		}
		case 34: // srifle
		{
			PHaveItemEx(playerid, 1, 40, slot);
			
			for(new k = 1; k <= MAX_PLAYER_ITEM_SLOT; k++)
			{
				if(slot[k-1])
				{
					DynamicFactions[fID][WFactory127MMAmmo] += SlotParam6(playerid, slot[k-1]);
					RemovePlayerItemUsed(playerid, k);
				}
			}
		
			SaveFData(fID, "WFactory127MMAmmo");
		}
	}
	return 0;
}

stock GivePlayerGun(playerid, weaponid, ammo) // Thx to Seif
{
	Gun[playerid][Weapon][WeaponSlot(weaponid)] = weaponid;
	Ammo[playerid][weaponid] = ammo;
	GivePlayerWeapon(playerid, weaponid, ammo);
}

stock WeaponSlot(weaponid) // Thx to Seif
{
	switch (weaponid)
	{
	    case 0,1: return 0;
	    case 2..9: return 1;
	    case 22,23,24: return 2;
	    case 25,26,27: return 3;
	    case 28,29,32: return 4;
		case 30,31: return 5;
	    case 33,34: return 6;
	    case 35,36,37,38: return 7;
	    case 16,17,18,39: return 8;
		case 41,42,43: return 9;
	    case 10,11,12,13,14,15: return 10;
	    case 44,45,46: return 11;
	    default: return 12;
	}
	return true;
}
