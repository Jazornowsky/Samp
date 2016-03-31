/***
*
* File: wp_itemfncs_player.inc
* Auth: Damian Wojdat
* Date: 13.05.2012
* Desc: Functions related to player items.
*
*************************************************************************************************************/

/*
How many of items of given type and id can be hold on one slot
*/
stock ItemsOnCharacterSlot(itemtype, itemid)
{
	if(itemtype == 1)
	{
		switch(itemid)
		{
			case 1: return 1;
			case 2: return 7;
			case 3: return 1;
			case 4: return 2;
			case 5: return 1;
			case 6: return 1;
			case 7: return 4;
			case 8: return 1;
			case 9: return 15;
			case 10: return 1;
			case 11: return 1;
			case 12: return 5;
			case 13: return 2;
			case 14: return 2;
			case 15: return 1;
			case 16: return 3;
			case 17: return 3;
			case 18: return 3;
			case 19: return 1;
			case 20: return 1;
			case 21: return 1;
			case 22: return 2;
			case 23: return 1;
			case 24: return 1;
			case 25: return 1;
			case 26: return 2;
			case 27: return 1;
			case 28: return 1;
			case 29: return 1;
			case 30: return 1;
			case 31: return 1;
			case 32: return 1;
			case 33: return 1;
			case 34: return 4;
			case 35: return 1;
			case 36: return 60;
			case 37: return 60;
			case 38: return 60;
			case 39: return 50;
			case 40: return 60;
			case 41: return 60;
			case 42: return 60;
			case 105: return 3;
			case 106: return 4;
			case 107..121: return 10;
			case 122: return 1;
			case 123: return 2;
			case 124: return 2;
			case 125: return 6;
			case 126: return 6;
			case 127: return 6;
			case 128: return 15;
			case 129: return 10;
			case 130: return 20;
			case 131: return 18;
			case 132: return 25;
			case 133: return 6;
			case 134..142: return 6;
			case 143: return 2;
			case 144: return 10;
			case 145..147: return 4;
			case 148: return 1;
			case 149..150: return 4;
			case 151: return 3;
			case 152: return 2;
			case 153: return 5;
			case 173: return 100;
			case 174: return 1;
			case 175: return 4;
			case 176: return 2;
			case 177: return 2;
			case 178: return 4;
			default: return 100;
		}
	}
	else if(itemtype == 5)
	{
		switch(itemid)
		{
			case 1: return 5;
			case 2: return 5;
			case 3: return 4;
			case 4: return 4;
			case 5: return 5;
			case 6: return 10;
			case 7: return 10;
			case 8: return 15;
			case 9: return 15;
			case 10: return 20;
			case 11: return 15;
			case 12: return 15;
			case 13: return 20;
			case 14..15: return 15;
			case 16..22: return 20;
			case 23: return 20;
			default: return 100;
		}
	}
	else if(itemtype == 6)
	{
		switch(itemid)
		{
			case	1: return 3;
			case	2: return 3;
			case	3: return 2;
			case	4: return 2;
			case	5: return 2;
			case	6: return 2;
			case	7: return 2;
			case	8: return 2;
			default: return 100;
		}
	}
	else if(itemtype == 7)
	{
		switch(itemid)
		{
			case	1..5: return 2;
			default: return 100;
		}
	}
	else if(itemtype == 8)
	{
		switch(itemid)
		{
			case	1..28: return 2;
			case	45..69: return 2;
			default: return 1;
		}
	}
	else if(itemtype == 9)
	{
		switch(itemid)
		{
			case	1..6: return 2;
			default: return 1;
		}
	}
	return 1;
}

stock PItemWeight(playerid)
{
	new weight = 0;
	weight += ItemWeight(gPlayerData[playerid][pItem1type], gPlayerData[playerid][pItem1]) * gPlayerData[playerid][pItem1param6];
	weight += ItemWeight(gPlayerData[playerid][pItem2type], gPlayerData[playerid][pItem2]) * gPlayerData[playerid][pItem2param6];
	weight += ItemWeight(gPlayerData[playerid][pItem3type], gPlayerData[playerid][pItem3]) * gPlayerData[playerid][pItem3param6];
	weight += ItemWeight(gPlayerData[playerid][pItem4type], gPlayerData[playerid][pItem4]) * gPlayerData[playerid][pItem4param6];
	weight += ItemWeight(gPlayerData[playerid][pItem5type], gPlayerData[playerid][pItem5]) * gPlayerData[playerid][pItem5param6];
	if(PHaveExpandItem(playerid) || gPlayerData[playerid][pVipItem] > 0)
	{
		weight += ItemWeight(gPlayerData[playerid][pItem6type], gPlayerData[playerid][pItem6]) * gPlayerData[playerid][pItem6param6];
		weight += ItemWeight(gPlayerData[playerid][pItem7type], gPlayerData[playerid][pItem7]) * gPlayerData[playerid][pItem7param6];
		weight += ItemWeight(gPlayerData[playerid][pItem8type], gPlayerData[playerid][pItem8]) * gPlayerData[playerid][pItem8param6];
		weight += ItemWeight(gPlayerData[playerid][pItem9type], gPlayerData[playerid][pItem9]) * gPlayerData[playerid][pItem9param6];
		weight += ItemWeight(gPlayerData[playerid][pItem10type], gPlayerData[playerid][pItem10]) * gPlayerData[playerid][pItem10param6];
		weight += ItemWeight(gPlayerData[playerid][pItem11type], gPlayerData[playerid][pItem11]) * gPlayerData[playerid][pItem11param6];
		weight += ItemWeight(gPlayerData[playerid][pItem12type], gPlayerData[playerid][pItem12]) * gPlayerData[playerid][pItem12param6];
		weight += ItemWeight(gPlayerData[playerid][pItem13type], gPlayerData[playerid][pItem13]) * gPlayerData[playerid][pItem13param6];
		weight += ItemWeight(gPlayerData[playerid][pItem14type], gPlayerData[playerid][pItem14]) * gPlayerData[playerid][pItem14param6];
		weight += ItemWeight(gPlayerData[playerid][pItem15type], gPlayerData[playerid][pItem15]) * gPlayerData[playerid][pItem15param6];
		if(gPlayerData[playerid][pVipItem] > 0)
		{
			weight += ItemWeight(gPlayerData[playerid][pItem16type], gPlayerData[playerid][pItem16]) * gPlayerData[playerid][pItem16param6];
			weight += ItemWeight(gPlayerData[playerid][pItem17type], gPlayerData[playerid][pItem17]) * gPlayerData[playerid][pItem17param6];
			weight += ItemWeight(gPlayerData[playerid][pItem18type], gPlayerData[playerid][pItem18]) * gPlayerData[playerid][pItem18param6];
			weight += ItemWeight(gPlayerData[playerid][pItem19type], gPlayerData[playerid][pItem19]) * gPlayerData[playerid][pItem19param6];
			weight += ItemWeight(gPlayerData[playerid][pItem20type], gPlayerData[playerid][pItem20]) * gPlayerData[playerid][pItem20param6];
			weight += ItemWeight(gPlayerData[playerid][pItem21type], gPlayerData[playerid][pItem21]) * gPlayerData[playerid][pItem21param6];
			weight += ItemWeight(gPlayerData[playerid][pItem22type], gPlayerData[playerid][pItem22]) * gPlayerData[playerid][pItem22param6];
			weight += ItemWeight(gPlayerData[playerid][pItem23type], gPlayerData[playerid][pItem23]) * gPlayerData[playerid][pItem23param6];
			weight += ItemWeight(gPlayerData[playerid][pItem24type], gPlayerData[playerid][pItem24]) * gPlayerData[playerid][pItem24param6];
			weight += ItemWeight(gPlayerData[playerid][pItem25type], gPlayerData[playerid][pItem25]) * gPlayerData[playerid][pItem25param6];
		}
	}
	return weight;
}

/*
* Check if player have keys for vehicle
*/
stock CheckPlayerCarSerial(playerid, slot)
{
	for(new i = 0; i < sizeof(gVehData); i++)
	{
		if (slot == 1 && gVehData[i][CarSerial] == gPlayerData[playerid][pItem1])
			return i;
		else if (slot == 2 && gVehData[i][CarSerial] == gPlayerData[playerid][pItem2])
			return i;
		else if (slot == 3 && gVehData[i][CarSerial] == gPlayerData[playerid][pItem3])
			return i;
		else if (slot == 4 && gVehData[i][CarSerial] == gPlayerData[playerid][pItem4])
			return i;
		else if (slot == 5 && gVehData[i][CarSerial] == gPlayerData[playerid][pItem5])
			return i;
		if (PHaveExpandItem(playerid) || gPlayerData[playerid][pVipItem] > 0)
		{
			if (slot == 6 && gVehData[i][CarSerial] == gPlayerData[playerid][pItem6])
				return i;
			else if (slot == 7 && gVehData[i][CarSerial] == gPlayerData[playerid][pItem7])
				return i;
			else if (slot == 8 && gVehData[i][CarSerial] == gPlayerData[playerid][pItem8])
				return i;
			else if (slot == 9 && gVehData[i][CarSerial] == gPlayerData[playerid][pItem9])
				return i;
			else if (slot == 10 && gVehData[i][CarSerial] == gPlayerData[playerid][pItem10])
				return i;
			else if(slot == 11 && gVehData[i][CarSerial] == gPlayerData[playerid][pItem11])
				return i;
			else if (slot == 12 && gVehData[i][CarSerial] == gPlayerData[playerid][pItem12])
				return i;
			else if (slot == 13 && gVehData[i][CarSerial] == gPlayerData[playerid][pItem13])
				return i;
			else if (slot == 14 && gVehData[i][CarSerial] == gPlayerData[playerid][pItem14])
				return i;
			else if (slot == 15 && gVehData[i][CarSerial] == gPlayerData[playerid][pItem15])
				return i;
			if( gPlayerData[playerid][pVipItem] > 0 )
			{
				if (slot == 16 && gVehData[i][CarSerial] == gPlayerData[playerid][pItem16])
					return i;
				else if (slot == 17 && gVehData[i][CarSerial] == gPlayerData[playerid][pItem17])
					return i;
				else if (slot == 18 && gVehData[i][CarSerial] == gPlayerData[playerid][pItem18])
					return i;
				else if (slot == 19 && gVehData[i][CarSerial] == gPlayerData[playerid][pItem19])
					return i;
				else if (slot == 20 && gVehData[i][CarSerial] == gPlayerData[playerid][pItem20])
					return i;
				else if (slot == 21 && gVehData[i][CarSerial] == gPlayerData[playerid][pItem21])
					return i;
				else if (slot == 22 && gVehData[i][CarSerial] == gPlayerData[playerid][pItem22])
					return i;
				else if (slot == 23 && gVehData[i][CarSerial] == gPlayerData[playerid][pItem23])
					return i;
				else if (slot == 24 && gVehData[i][CarSerial] == gPlayerData[playerid][pItem24])
					return i;
				else if (slot == 25 && gVehData[i][CarSerial] == gPlayerData[playerid][pItem25])
					return i;
			}
		}
	}
	return 255;
}

stock InsertPlayerPickupItem(playerid, slot, size = 1)
{
	new Float:px, Float:py, Float:pz, Float:pa;
	new hour, minute, second;
	new Float:fSecond;
	GetPlayerPos(playerid, px, py, pz);
	GetPlayerFacingAngle(playerid, pa);
	gettime(hour, minute, second);
	fSecond = float(second);
	fSecond /= 40.0;
	GetXYInFrontOfPlayer(playerid, px, py, 2.0+fSecond);
	for(new i = 0; i < sizeof(gPickupItem); i++)
	{
		if(gPickupItem[i][pickupLifeTime] > 0)
			continue;			
		if (slot == 1)
		{
			gPickupItem[i][PickupItem] = gPlayerData[playerid][pItem1];
			gPickupItem[i][PickupItemType] = gPlayerData[playerid][pItem1type];
			gPickupItem[i][PickupItemParam1] = gPlayerData[playerid][pItem1param];
			gPickupItem[i][PickupItemParam2] = gPlayerData[playerid][pItem1param2];
			gPickupItem[i][PickupItemParam3] = gPlayerData[playerid][pItem1param3];
			gPickupItem[i][PickupItemParam4] = gPlayerData[playerid][pItem1param4];
			strdel(gPickupItem[i][PickupItemParam5], 0, 64);
			strins(gPickupItem[i][PickupItemParam5], gPlayerData[playerid][pItem1param5], 0, 64);
			gPickupItem[i][PickupItemParam6] = size;
		}
		else if (slot == 2)
		{
			gPickupItem[i][PickupItem] = gPlayerData[playerid][pItem2];
			gPickupItem[i][PickupItemType] = gPlayerData[playerid][pItem2type];
			gPickupItem[i][PickupItemParam1] = gPlayerData[playerid][pItem2param];
			gPickupItem[i][PickupItemParam2] = gPlayerData[playerid][pItem2param2];
			gPickupItem[i][PickupItemParam3] = gPlayerData[playerid][pItem2param3];
			gPickupItem[i][PickupItemParam4] = gPlayerData[playerid][pItem2param4];
			strdel(gPickupItem[i][PickupItemParam5], 0, 64);
			strins(gPickupItem[i][PickupItemParam5], gPlayerData[playerid][pItem2param5], 0, 64);
			gPickupItem[i][PickupItemParam6] = size;
		}
		else if (slot == 3)
		{
			gPickupItem[i][PickupItem] = gPlayerData[playerid][pItem3];
			gPickupItem[i][PickupItemType] = gPlayerData[playerid][pItem3type];
			gPickupItem[i][PickupItemParam1] = gPlayerData[playerid][pItem3param];
			gPickupItem[i][PickupItemParam2] = gPlayerData[playerid][pItem3param2];
			gPickupItem[i][PickupItemParam3] = gPlayerData[playerid][pItem3param3];
			gPickupItem[i][PickupItemParam4] = gPlayerData[playerid][pItem3param4];
			strdel(gPickupItem[i][PickupItemParam5], 0, 64);
			strins(gPickupItem[i][PickupItemParam5], gPlayerData[playerid][pItem3param5], 0, 64);
			gPickupItem[i][PickupItemParam6] = size;
		}
		else if (slot == 4)
		{
			gPickupItem[i][PickupItem] = gPlayerData[playerid][pItem4];
			gPickupItem[i][PickupItemType] = gPlayerData[playerid][pItem4type];
			gPickupItem[i][PickupItemParam1] = gPlayerData[playerid][pItem4param];
			gPickupItem[i][PickupItemParam2] = gPlayerData[playerid][pItem4param2];
			gPickupItem[i][PickupItemParam3] = gPlayerData[playerid][pItem4param3];
			gPickupItem[i][PickupItemParam4] = gPlayerData[playerid][pItem4param4];
			strdel(gPickupItem[i][PickupItemParam5], 0, 64);
			strins(gPickupItem[i][PickupItemParam5], gPlayerData[playerid][pItem4param5], 0, 64);
			gPickupItem[i][PickupItemParam6] = size;
		}
		else if (slot == 5)
		{
			gPickupItem[i][PickupItem] = gPlayerData[playerid][pItem5];
			gPickupItem[i][PickupItemType] = gPlayerData[playerid][pItem5type];
			gPickupItem[i][PickupItemParam1] = gPlayerData[playerid][pItem5param];
			gPickupItem[i][PickupItemParam2] = gPlayerData[playerid][pItem5param2];
			gPickupItem[i][PickupItemParam3] = gPlayerData[playerid][pItem5param3];
			gPickupItem[i][PickupItemParam4] = gPlayerData[playerid][pItem5param4];
			strdel(gPickupItem[i][PickupItemParam5], 0, 64);
			strins(gPickupItem[i][PickupItemParam5], gPlayerData[playerid][pItem5param5], 0, 64);
			gPickupItem[i][PickupItemParam6] = size;
		}
		else if (slot == 6)
		{
			gPickupItem[i][PickupItem] = gPlayerData[playerid][pItem6];
			gPickupItem[i][PickupItemType] = gPlayerData[playerid][pItem6type];
			gPickupItem[i][PickupItemParam1] = gPlayerData[playerid][pItem6param];
			gPickupItem[i][PickupItemParam2] = gPlayerData[playerid][pItem6param2];
			gPickupItem[i][PickupItemParam3] = gPlayerData[playerid][pItem6param3];
			gPickupItem[i][PickupItemParam4] = gPlayerData[playerid][pItem6param4];
			strdel(gPickupItem[i][PickupItemParam5], 0, 64);
			strins(gPickupItem[i][PickupItemParam5], gPlayerData[playerid][pItem6param5], 0, 64);
			gPickupItem[i][PickupItemParam6] = size;
		}
		else if (slot == 7)
		{
			gPickupItem[i][PickupItem] = gPlayerData[playerid][pItem7];
			gPickupItem[i][PickupItemType] = gPlayerData[playerid][pItem7type];
			gPickupItem[i][PickupItemParam1] = gPlayerData[playerid][pItem7param];
			gPickupItem[i][PickupItemParam2] = gPlayerData[playerid][pItem7param2];
			gPickupItem[i][PickupItemParam3] = gPlayerData[playerid][pItem7param3];
			gPickupItem[i][PickupItemParam4] = gPlayerData[playerid][pItem7param4];
			strdel(gPickupItem[i][PickupItemParam5], 0, 64);
			strins(gPickupItem[i][PickupItemParam5], gPlayerData[playerid][pItem7param5], 0, 64);
			gPickupItem[i][PickupItemParam6] = size;
		}
		else if (slot == 8)
		{
			gPickupItem[i][PickupItem] = gPlayerData[playerid][pItem8];
			gPickupItem[i][PickupItemType] = gPlayerData[playerid][pItem8type];
			gPickupItem[i][PickupItemParam1] = gPlayerData[playerid][pItem8param];
			gPickupItem[i][PickupItemParam2] = gPlayerData[playerid][pItem8param2];
			gPickupItem[i][PickupItemParam3] = gPlayerData[playerid][pItem8param3];
			gPickupItem[i][PickupItemParam4] = gPlayerData[playerid][pItem8param4];
			strdel(gPickupItem[i][PickupItemParam5], 0, 64);
			strins(gPickupItem[i][PickupItemParam5], gPlayerData[playerid][pItem8param5], 0, 64);
			gPickupItem[i][PickupItemParam6] = size;
		}
		else if (slot == 9)
		{
			gPickupItem[i][PickupItem] = gPlayerData[playerid][pItem9];
			gPickupItem[i][PickupItemType] = gPlayerData[playerid][pItem9type];
			gPickupItem[i][PickupItemParam1] = gPlayerData[playerid][pItem9param];
			gPickupItem[i][PickupItemParam2] = gPlayerData[playerid][pItem9param2];
			gPickupItem[i][PickupItemParam3] = gPlayerData[playerid][pItem9param3];
			gPickupItem[i][PickupItemParam4] = gPlayerData[playerid][pItem9param4];
			strdel(gPickupItem[i][PickupItemParam5], 0, 64);
			strins(gPickupItem[i][PickupItemParam5], gPlayerData[playerid][pItem9param5], 0, 64);
			gPickupItem[i][PickupItemParam6] = size;
		}
		else if (slot == 10)
		{
			gPickupItem[i][PickupItem] = gPlayerData[playerid][pItem10];
			gPickupItem[i][PickupItemType] = gPlayerData[playerid][pItem10type];
			gPickupItem[i][PickupItemParam1] = gPlayerData[playerid][pItem10param];
			gPickupItem[i][PickupItemParam2] = gPlayerData[playerid][pItem10param2];
			gPickupItem[i][PickupItemParam3] = gPlayerData[playerid][pItem10param3];
			gPickupItem[i][PickupItemParam4] = gPlayerData[playerid][pItem10param4];
			strdel(gPickupItem[i][PickupItemParam5], 0, 64);
			strins(gPickupItem[i][PickupItemParam5], gPlayerData[playerid][pItem10param5], 0, 64);
			gPickupItem[i][PickupItemParam6] =size;
		}
		else if (slot == 11)
		{
			gPickupItem[i][PickupItem] = gPlayerData[playerid][pItem11];
			gPickupItem[i][PickupItemType] = gPlayerData[playerid][pItem11type];
			gPickupItem[i][PickupItemParam1] = gPlayerData[playerid][pItem11param];
			gPickupItem[i][PickupItemParam2] = gPlayerData[playerid][pItem11param2];
			gPickupItem[i][PickupItemParam3] = gPlayerData[playerid][pItem11param3];
			gPickupItem[i][PickupItemParam4] = gPlayerData[playerid][pItem11param4];
			strdel(gPickupItem[i][PickupItemParam5], 0, 64);
			strins(gPickupItem[i][PickupItemParam5], gPlayerData[playerid][pItem11param5], 0, 64);
			gPickupItem[i][PickupItemParam6] = size;
		}
		else if (slot == 12)
		{
			gPickupItem[i][PickupItem] = gPlayerData[playerid][pItem12];
			gPickupItem[i][PickupItemType] = gPlayerData[playerid][pItem12type];
			gPickupItem[i][PickupItemParam1] = gPlayerData[playerid][pItem12param];
			gPickupItem[i][PickupItemParam2] = gPlayerData[playerid][pItem12param2];
			gPickupItem[i][PickupItemParam3] = gPlayerData[playerid][pItem12param3];
			gPickupItem[i][PickupItemParam4] = gPlayerData[playerid][pItem12param4];
			strdel(gPickupItem[i][PickupItemParam5], 0, 64);
			strins(gPickupItem[i][PickupItemParam5], gPlayerData[playerid][pItem12param5], 0, 64);
			gPickupItem[i][PickupItemParam6] = size;
		}
		else if (slot == 13)
		{
			gPickupItem[i][PickupItem] = gPlayerData[playerid][pItem13];
			gPickupItem[i][PickupItemType] = gPlayerData[playerid][pItem13type];
			gPickupItem[i][PickupItemParam1] = gPlayerData[playerid][pItem13param];
			gPickupItem[i][PickupItemParam2] = gPlayerData[playerid][pItem13param2];
			gPickupItem[i][PickupItemParam3] = gPlayerData[playerid][pItem13param3];
			gPickupItem[i][PickupItemParam4] = gPlayerData[playerid][pItem13param4];
			strdel(gPickupItem[i][PickupItemParam5], 0, 64);
			strins(gPickupItem[i][PickupItemParam5], gPlayerData[playerid][pItem13param5], 0, 64);
			gPickupItem[i][PickupItemParam6] = size;
		}
		else if (slot == 14)
		{
			gPickupItem[i][PickupItem] = gPlayerData[playerid][pItem14];
			gPickupItem[i][PickupItemType] = gPlayerData[playerid][pItem14type];
			gPickupItem[i][PickupItemParam1] = gPlayerData[playerid][pItem14param];
			gPickupItem[i][PickupItemParam2] = gPlayerData[playerid][pItem14param2];
			gPickupItem[i][PickupItemParam3] = gPlayerData[playerid][pItem14param3];
			gPickupItem[i][PickupItemParam4] = gPlayerData[playerid][pItem14param4];
			strdel(gPickupItem[i][PickupItemParam5], 0, 64);
			strins(gPickupItem[i][PickupItemParam5], gPlayerData[playerid][pItem14param5], 0, 64);
			gPickupItem[i][PickupItemParam6] = size;
		}
		else if (slot == 15)
		{
			gPickupItem[i][PickupItem] = gPlayerData[playerid][pItem15];
			gPickupItem[i][PickupItemType] = gPlayerData[playerid][pItem15type];
			gPickupItem[i][PickupItemParam1] = gPlayerData[playerid][pItem15param];
			gPickupItem[i][PickupItemParam2] = gPlayerData[playerid][pItem15param2];
			gPickupItem[i][PickupItemParam3] = gPlayerData[playerid][pItem15param3];
			gPickupItem[i][PickupItemParam4] = gPlayerData[playerid][pItem15param4];
			strdel(gPickupItem[i][PickupItemParam5], 0, 64);
			strins(gPickupItem[i][PickupItemParam5], gPlayerData[playerid][pItem15param5], 0, 64);
			gPickupItem[i][PickupItemParam6] = size;
		}
		else if (slot == 16)
		{
			gPickupItem[i][PickupItem] = gPlayerData[playerid][pItem16];
			gPickupItem[i][PickupItemType] = gPlayerData[playerid][pItem16type];
			gPickupItem[i][PickupItemParam1] = gPlayerData[playerid][pItem16param];
			gPickupItem[i][PickupItemParam2] = gPlayerData[playerid][pItem16param2];
			gPickupItem[i][PickupItemParam3] = gPlayerData[playerid][pItem16param3];
			gPickupItem[i][PickupItemParam4] = gPlayerData[playerid][pItem16param4];
			strdel(gPickupItem[i][PickupItemParam5], 0, 64);
			strins(gPickupItem[i][PickupItemParam5], gPlayerData[playerid][pItem16param5], 0, 64);
			gPickupItem[i][PickupItemParam6] = size;
		}
		else if (slot == 17)
		{
			gPickupItem[i][PickupItem] = gPlayerData[playerid][pItem17];
			gPickupItem[i][PickupItemType] = gPlayerData[playerid][pItem17type];
			gPickupItem[i][PickupItemParam1] = gPlayerData[playerid][pItem17param];
			gPickupItem[i][PickupItemParam2] = gPlayerData[playerid][pItem17param2];
			gPickupItem[i][PickupItemParam3] = gPlayerData[playerid][pItem17param3];
			gPickupItem[i][PickupItemParam4] = gPlayerData[playerid][pItem17param4];
			strdel(gPickupItem[i][PickupItemParam5], 0, 64);
			strins(gPickupItem[i][PickupItemParam5], gPlayerData[playerid][pItem17param5], 0, 64);
			gPickupItem[i][PickupItemParam6] = size;
		}
		else if (slot == 18)
		{
			gPickupItem[i][PickupItem] = gPlayerData[playerid][pItem18];
			gPickupItem[i][PickupItemType] = gPlayerData[playerid][pItem18type];
			gPickupItem[i][PickupItemParam1] = gPlayerData[playerid][pItem18param];
			gPickupItem[i][PickupItemParam2] = gPlayerData[playerid][pItem18param2];
			gPickupItem[i][PickupItemParam3] = gPlayerData[playerid][pItem18param3];
			gPickupItem[i][PickupItemParam4] = gPlayerData[playerid][pItem18param4];
			strdel(gPickupItem[i][PickupItemParam5], 0, 64);
			strins(gPickupItem[i][PickupItemParam5], gPlayerData[playerid][pItem18param5], 0, 64);
			gPickupItem[i][PickupItemParam6] = size;
		}
		else if (slot == 19)
		{
			gPickupItem[i][PickupItem] = gPlayerData[playerid][pItem19];
			gPickupItem[i][PickupItemType] = gPlayerData[playerid][pItem19type];
			gPickupItem[i][PickupItemParam1] = gPlayerData[playerid][pItem19param];
			gPickupItem[i][PickupItemParam2] = gPlayerData[playerid][pItem19param2];
			gPickupItem[i][PickupItemParam3] = gPlayerData[playerid][pItem19param3];
			gPickupItem[i][PickupItemParam4] = gPlayerData[playerid][pItem19param4];
			strdel(gPickupItem[i][PickupItemParam5], 0, 64);
			strins(gPickupItem[i][PickupItemParam5], gPlayerData[playerid][pItem19param5], 0, 64);
			gPickupItem[i][PickupItemParam6] = size;
		}
		else if (slot == 20)
		{
			gPickupItem[i][PickupItem] = gPlayerData[playerid][pItem20];
			gPickupItem[i][PickupItemType] = gPlayerData[playerid][pItem20type];
			gPickupItem[i][PickupItemParam1] = gPlayerData[playerid][pItem20param];
			gPickupItem[i][PickupItemParam2] = gPlayerData[playerid][pItem20param2];
			gPickupItem[i][PickupItemParam3] = gPlayerData[playerid][pItem20param3];
			gPickupItem[i][PickupItemParam4] = gPlayerData[playerid][pItem20param4];
			strdel(gPickupItem[i][PickupItemParam5], 0, 64);
			strins(gPickupItem[i][PickupItemParam5], gPlayerData[playerid][pItem20param5], 0, 64);
			gPickupItem[i][PickupItemParam6] = size;
		}
		else if (slot == 21)
		{
			gPickupItem[i][PickupItem] = gPlayerData[playerid][pItem21];
			gPickupItem[i][PickupItemType] = gPlayerData[playerid][pItem21type];
			gPickupItem[i][PickupItemParam1] = gPlayerData[playerid][pItem21param];
			gPickupItem[i][PickupItemParam2] = gPlayerData[playerid][pItem21param2];
			gPickupItem[i][PickupItemParam3] = gPlayerData[playerid][pItem21param3];
			gPickupItem[i][PickupItemParam4] = gPlayerData[playerid][pItem21param4];
			strdel(gPickupItem[i][PickupItemParam5], 0, 64);
			strins(gPickupItem[i][PickupItemParam5], gPlayerData[playerid][pItem21param5], 0, 64);
			gPickupItem[i][PickupItemParam6] = size;
		}
		else if (slot == 22)
		{
			gPickupItem[i][PickupItem] = gPlayerData[playerid][pItem22];
			gPickupItem[i][PickupItemType] = gPlayerData[playerid][pItem22type];
			gPickupItem[i][PickupItemParam1] = gPlayerData[playerid][pItem22param];
			gPickupItem[i][PickupItemParam2] = gPlayerData[playerid][pItem22param2];
			gPickupItem[i][PickupItemParam3] = gPlayerData[playerid][pItem22param3];
			gPickupItem[i][PickupItemParam4] = gPlayerData[playerid][pItem22param4];
			strdel(gPickupItem[i][PickupItemParam5], 0, 64);
			strins(gPickupItem[i][PickupItemParam5], gPlayerData[playerid][pItem22param5], 0, 64);
			gPickupItem[i][PickupItemParam6] = size;
		}
		else if (slot == 23)
		{
			gPickupItem[i][PickupItem] = gPlayerData[playerid][pItem23];
			gPickupItem[i][PickupItemType] = gPlayerData[playerid][pItem23type];
			gPickupItem[i][PickupItemParam1] = gPlayerData[playerid][pItem23param];
			gPickupItem[i][PickupItemParam2] = gPlayerData[playerid][pItem23param2];
			gPickupItem[i][PickupItemParam3] = gPlayerData[playerid][pItem23param3];
			gPickupItem[i][PickupItemParam4] = gPlayerData[playerid][pItem23param4];
			strdel(gPickupItem[i][PickupItemParam5], 0, 64);
			strins(gPickupItem[i][PickupItemParam5], gPlayerData[playerid][pItem23param5], 0, 64);
			gPickupItem[i][PickupItemParam6] = size;
		}
		else if (slot == 24)
		{
			gPickupItem[i][PickupItem] = gPlayerData[playerid][pItem24];
			gPickupItem[i][PickupItemType] = gPlayerData[playerid][pItem24type];
			gPickupItem[i][PickupItemParam1] = gPlayerData[playerid][pItem24param];
			gPickupItem[i][PickupItemParam2] = gPlayerData[playerid][pItem24param2];
			gPickupItem[i][PickupItemParam3] = gPlayerData[playerid][pItem24param3];
			gPickupItem[i][PickupItemParam4] = gPlayerData[playerid][pItem24param4];
			strdel(gPickupItem[i][PickupItemParam5], 0, 64);
			strins(gPickupItem[i][PickupItemParam5], gPlayerData[playerid][pItem24param5], 0, 64);
			gPickupItem[i][PickupItemParam6] = size;
		}
		else if (slot == 25)
		{
			gPickupItem[i][PickupItem] = gPlayerData[playerid][pItem25];
			gPickupItem[i][PickupItemType] = gPlayerData[playerid][pItem25type];
			gPickupItem[i][PickupItemParam1] = gPlayerData[playerid][pItem25param];
			gPickupItem[i][PickupItemParam2] = gPlayerData[playerid][pItem25param2];
			gPickupItem[i][PickupItemParam3] = gPlayerData[playerid][pItem25param3];
			gPickupItem[i][PickupItemParam4] = gPlayerData[playerid][pItem25param4];
			strdel(gPickupItem[i][PickupItemParam5], 0, 64);
			strins(gPickupItem[i][PickupItemParam5], gPlayerData[playerid][pItem25param5], 0, 64);
			gPickupItem[i][PickupItemParam6] = size;
		}
		gPickupItem[i][pickupLifeTime] = PICKUP_LIFE_TIME;
		
		if(gPickupItem[i][PickupItemType] == 1 && gPickupItem[i][PickupItem] >= 13 && gPickupItem[i][PickupItem] <= 35)
		{
			gPickupItem[i][pickupID] = CreateDynamicPickup(ItemToWeapon(gPickupItem[i][PickupItem]), 1, px, py, pz, GetPlayerVirtualWorld(i), -1, -1, 50.0);
		}
		else
		{			
			gPickupItem[i][pickupID] = CreateDynamicPickup(1559, 1, px, py, pz, GetPlayerVirtualWorld(i), -1, -1, 50.0);
		}
		gPickupItem[i][pickupX] = px;
		gPickupItem[i][pickupY] = py;
		gPickupItem[i][pickupZ] = pz;
		return 1;
	}
	return 1;
}

/*
* Count how many items in all slot of given type player can carry
*/
stock PlayerCountMaxItemCarry(playerid, itemtype, itemid)
{
	new itemCanCarryCount = 0;
	if(gPlayerData[playerid][pItem1type] == 0)
		itemCanCarryCount += ItemsOnCharacterSlot(itemtype, itemid);
	else if(gPlayerData[playerid][pItem1type] == itemtype && gPlayerData[playerid][pItem1] == itemid)
		itemCanCarryCount += ItemsOnCharacterSlot(itemtype, itemid) - SlotParam6(playerid, 1);
	if(gPlayerData[playerid][pItem2type] == 0)
		itemCanCarryCount += ItemsOnCharacterSlot(itemtype, itemid);
	else if(gPlayerData[playerid][pItem2type] == itemtype && gPlayerData[playerid][pItem2] == itemid)
		itemCanCarryCount += ItemsOnCharacterSlot(itemtype, itemid) - SlotParam6(playerid, 2);
	if(gPlayerData[playerid][pItem3type] == 0)
		itemCanCarryCount += ItemsOnCharacterSlot(itemtype, itemid);
	else if(gPlayerData[playerid][pItem3type] == itemtype && gPlayerData[playerid][pItem3] == itemid)
		itemCanCarryCount += ItemsOnCharacterSlot(itemtype, itemid) - SlotParam6(playerid, 3);
	if(gPlayerData[playerid][pItem4type] == 0)
		itemCanCarryCount += ItemsOnCharacterSlot(itemtype, itemid);
	else if(gPlayerData[playerid][pItem4type] == itemtype && gPlayerData[playerid][pItem4] == itemid)
		itemCanCarryCount += ItemsOnCharacterSlot(itemtype, itemid) - SlotParam6(playerid, 4);
	if(gPlayerData[playerid][pItem5type] == 0)
		itemCanCarryCount += ItemsOnCharacterSlot(itemtype, itemid);
	else if(gPlayerData[playerid][pItem5type] == itemtype && gPlayerData[playerid][pItem5] == itemid)
		itemCanCarryCount += ItemsOnCharacterSlot(itemtype, itemid) - SlotParam6(playerid, 5);
	if(PHaveExpandItem(playerid) || gPlayerData[playerid][pVipItem] > 0)
	{
		if(gPlayerData[playerid][pItem6type] == 0)
			itemCanCarryCount += ItemsOnCharacterSlot(itemtype, itemid);
		else if(gPlayerData[playerid][pItem6type] == itemtype && gPlayerData[playerid][pItem6] == itemid)
			itemCanCarryCount += ItemsOnCharacterSlot(itemtype, itemid) - SlotParam6(playerid, 6);
		if(gPlayerData[playerid][pItem7type] == 0)
			itemCanCarryCount += ItemsOnCharacterSlot(itemtype, itemid);
		else if(gPlayerData[playerid][pItem7type] == itemtype && gPlayerData[playerid][pItem7] == itemid)
			itemCanCarryCount += ItemsOnCharacterSlot(itemtype, itemid) - SlotParam6(playerid, 7);
		if(gPlayerData[playerid][pItem8type] == 0)
			itemCanCarryCount += ItemsOnCharacterSlot(itemtype, itemid);
		else if(gPlayerData[playerid][pItem8type] == itemtype && gPlayerData[playerid][pItem8] == itemid)
			itemCanCarryCount += ItemsOnCharacterSlot(itemtype, itemid) - SlotParam6(playerid, 8);
		if(gPlayerData[playerid][pItem9type] == 0)
			itemCanCarryCount += ItemsOnCharacterSlot(itemtype, itemid);
		else if(gPlayerData[playerid][pItem9type] == itemtype && gPlayerData[playerid][pItem9] == itemid)
			itemCanCarryCount += ItemsOnCharacterSlot(itemtype, itemid) - SlotParam6(playerid, 9);
		if(gPlayerData[playerid][pItem10type] == 0)
			itemCanCarryCount += ItemsOnCharacterSlot(itemtype, itemid);
		else if(gPlayerData[playerid][pItem10type] == itemtype && gPlayerData[playerid][pItem10] == itemid)
			itemCanCarryCount += ItemsOnCharacterSlot(itemtype, itemid) - SlotParam6(playerid, 10);
		if(gPlayerData[playerid][pItem11type] == 0)
			itemCanCarryCount += ItemsOnCharacterSlot(itemtype, itemid);
		else if(gPlayerData[playerid][pItem11type] == itemtype && gPlayerData[playerid][pItem11] == itemid)
			itemCanCarryCount += ItemsOnCharacterSlot(itemtype, itemid) - SlotParam6(playerid, 11);
		if(gPlayerData[playerid][pItem12type] == 0)
			itemCanCarryCount += ItemsOnCharacterSlot(itemtype, itemid);
		else if(gPlayerData[playerid][pItem12type] == itemtype && gPlayerData[playerid][pItem12] == itemid)
			itemCanCarryCount += ItemsOnCharacterSlot(itemtype, itemid) - SlotParam6(playerid, 12);
		if(gPlayerData[playerid][pItem13type] == 0)
			itemCanCarryCount += ItemsOnCharacterSlot(itemtype, itemid);
		else if(gPlayerData[playerid][pItem13type] == itemtype && gPlayerData[playerid][pItem13] == itemid)
			itemCanCarryCount += ItemsOnCharacterSlot(itemtype, itemid) - SlotParam6(playerid, 13);
		if(gPlayerData[playerid][pItem14type] == 0)
			itemCanCarryCount += ItemsOnCharacterSlot(itemtype, itemid);
		else if(gPlayerData[playerid][pItem14type] == itemtype && gPlayerData[playerid][pItem14] == itemid)
			itemCanCarryCount += ItemsOnCharacterSlot(itemtype, itemid) - SlotParam6(playerid, 14);
		if(gPlayerData[playerid][pItem15type] == 0)
			itemCanCarryCount += ItemsOnCharacterSlot(itemtype, itemid);
		else if(gPlayerData[playerid][pItem15type] == itemtype && gPlayerData[playerid][pItem15] == itemid)
			itemCanCarryCount += ItemsOnCharacterSlot(itemtype, itemid) - SlotParam6(playerid, 15);
		if(gPlayerData[playerid][pVipItem] > 0)
		{
			if(gPlayerData[playerid][pItem16type] == 0)
				itemCanCarryCount += ItemsOnCharacterSlot(itemtype, itemid);
			else if(gPlayerData[playerid][pItem16type] == itemtype && gPlayerData[playerid][pItem16] == itemid)
				itemCanCarryCount += ItemsOnCharacterSlot(itemtype, itemid) - SlotParam6(playerid, 16);
			if(gPlayerData[playerid][pItem17type] == 0)
				itemCanCarryCount += ItemsOnCharacterSlot(itemtype, itemid);
			else if(gPlayerData[playerid][pItem17type] == itemtype && gPlayerData[playerid][pItem17] == itemid)
				itemCanCarryCount += ItemsOnCharacterSlot(itemtype, itemid) - SlotParam6(playerid, 17);
			if(gPlayerData[playerid][pItem18type] == 0)
				itemCanCarryCount += ItemsOnCharacterSlot(itemtype, itemid);
			else if(gPlayerData[playerid][pItem18type] == itemtype && gPlayerData[playerid][pItem18] == itemid)
				itemCanCarryCount += ItemsOnCharacterSlot(itemtype, itemid) - SlotParam6(playerid, 18);
			if(gPlayerData[playerid][pItem19type] == 0)
				itemCanCarryCount += ItemsOnCharacterSlot(itemtype, itemid);
			else if(gPlayerData[playerid][pItem19type] == itemtype && gPlayerData[playerid][pItem19] == itemid)
				itemCanCarryCount += ItemsOnCharacterSlot(itemtype, itemid) - SlotParam6(playerid, 19);
			if(gPlayerData[playerid][pItem20type] == 0)
				itemCanCarryCount += ItemsOnCharacterSlot(itemtype, itemid);
			else if(gPlayerData[playerid][pItem20type] == itemtype && gPlayerData[playerid][pItem20] == itemid)
				itemCanCarryCount += ItemsOnCharacterSlot(itemtype, itemid) - SlotParam6(playerid, 20);
			if(gPlayerData[playerid][pItem21type] == 0)
				itemCanCarryCount += ItemsOnCharacterSlot(itemtype, itemid);
			else if(gPlayerData[playerid][pItem21type] == itemtype && gPlayerData[playerid][pItem21] == itemid)
				itemCanCarryCount += ItemsOnCharacterSlot(itemtype, itemid) - SlotParam6(playerid, 21);
			if(gPlayerData[playerid][pItem22type] == 0)
				itemCanCarryCount += ItemsOnCharacterSlot(itemtype, itemid);
			else if(gPlayerData[playerid][pItem22type] == itemtype && gPlayerData[playerid][pItem22] == itemid)
				itemCanCarryCount += ItemsOnCharacterSlot(itemtype, itemid) - SlotParam6(playerid, 22);
			if(gPlayerData[playerid][pItem23type] == 0)
				itemCanCarryCount += ItemsOnCharacterSlot(itemtype, itemid);
			else if(gPlayerData[playerid][pItem23type] == itemtype && gPlayerData[playerid][pItem23] == itemid)
				itemCanCarryCount += ItemsOnCharacterSlot(itemtype, itemid) - SlotParam6(playerid, 23);
			if(gPlayerData[playerid][pItem24type] == 0)
				itemCanCarryCount += ItemsOnCharacterSlot(itemtype, itemid);
			else if(gPlayerData[playerid][pItem24type] == itemtype && gPlayerData[playerid][pItem24] == itemid)
				itemCanCarryCount += ItemsOnCharacterSlot(itemtype, itemid) - SlotParam6(playerid, 24);
			if(gPlayerData[playerid][pItem25type] == 0)
				itemCanCarryCount += ItemsOnCharacterSlot(itemtype, itemid);
			else if(gPlayerData[playerid][pItem25type] == itemtype && gPlayerData[playerid][pItem25] == itemid)
				itemCanCarryCount += ItemsOnCharacterSlot(itemtype, itemid) - SlotParam6(playerid, 25);
		}
	}
	return itemCanCarryCount;
}

stock PlayerFreeSlotCount(playerid)
{
	new slotcount = 0;
	if( gPlayerData[playerid][pItem1type] == 0 )
		slotcount++;
	if( gPlayerData[playerid][pItem2type] == 0 )
		slotcount++;
	if( gPlayerData[playerid][pItem3type] == 0 )
		slotcount++;
	if( gPlayerData[playerid][pItem4type] == 0 )
		slotcount++;
	if( gPlayerData[playerid][pItem5type] == 0 )
		slotcount++;
	if( PHaveExpandItem(playerid) || gPlayerData[playerid][pVipItem] > 0 )
	{
		if( gPlayerData[playerid][pItem6type] == 0 )
			slotcount++;
		if( gPlayerData[playerid][pItem7type] == 0 )
			slotcount++;
		if( gPlayerData[playerid][pItem8type] == 0 )
			slotcount++;
		if( gPlayerData[playerid][pItem9type] == 0 )
			slotcount++;
		if( gPlayerData[playerid][pItem10type] == 0 )
			slotcount++;
		if( gPlayerData[playerid][pItem11type] == 0 )
			slotcount++;
		if( gPlayerData[playerid][pItem12type] == 0 )
			slotcount++;
		if( gPlayerData[playerid][pItem13type] == 0 )
			slotcount++;
		if( gPlayerData[playerid][pItem14type] == 0 )
			slotcount++;
		if( gPlayerData[playerid][pItem15type] == 0 )
			slotcount++;
		if( gPlayerData[playerid][pVipItem] > 0 )
		{
			if( gPlayerData[playerid][pItem16type] == 0 )
				slotcount++;
			if( gPlayerData[playerid][pItem17type] == 0 )
				slotcount++;
			if( gPlayerData[playerid][pItem18type] == 0 )
				slotcount++;
			if( gPlayerData[playerid][pItem19type] == 0 )
				slotcount++;
			if( gPlayerData[playerid][pItem20type] == 0 )
				slotcount++;
			if( gPlayerData[playerid][pItem21type] == 0 )
				slotcount++;
			if( gPlayerData[playerid][pItem22type] == 0 )
				slotcount++;
			if( gPlayerData[playerid][pItem23type] == 0 )
				slotcount++;
			if( gPlayerData[playerid][pItem24type] == 0 )
				slotcount++;
			if( gPlayerData[playerid][pItem25type] == 0 )
				slotcount++;
		}
	}
	return slotcount;
}

stock CountPItems(playerid, itemtype, itemid)
{
	new count;
	if(PSlotItemTypeCompare(playerid, 1, itemtype) && ShowSlotItem(playerid, 1) == itemid)
	{
		if(SlotParam6(playerid, 1) == 0)
			count++;
		else
			count += SlotParam6(playerid, 1);
	}
	if(PSlotItemTypeCompare(playerid, 2, itemtype) && ShowSlotItem(playerid, 2) == itemid)
	{
		if(SlotParam6(playerid, 2) == 0)
			count++;
		else
			count += SlotParam6(playerid, 2);
	}
	if(PSlotItemTypeCompare(playerid, 3, itemtype) && ShowSlotItem(playerid, 3) == itemid)
	{
		if(SlotParam6(playerid, 3) == 0)
			count++;
		else
			count += SlotParam6(playerid, 3);
	}
	if(PSlotItemTypeCompare(playerid, 4, itemtype) && ShowSlotItem(playerid, 4) == itemid)
	{
		if(SlotParam6(playerid, 4) == 0)
			count++;
		else
			count += SlotParam6(playerid, 4);
	}
	if(PSlotItemTypeCompare(playerid, 5, itemtype) && ShowSlotItem(playerid, 5) == itemid)
	{
		if(SlotParam6(playerid, 5) == 0)
			count++;
		else
			count += SlotParam6(playerid, 5);
	}
	if(PHaveExpandItem(playerid) || gPlayerData[playerid][pVipItem] > 0)
	{
		if(PSlotItemTypeCompare(playerid, 6, itemtype) && ShowSlotItem(playerid, 6) == itemid)
		{
			if(SlotParam6(playerid, 6) == 0)
				count++;
			else
				count += SlotParam6(playerid, 6);
		}
		if(PSlotItemTypeCompare(playerid, 7, itemtype) && ShowSlotItem(playerid, 7) == itemid)
		{
			if(SlotParam6(playerid, 7) == 0)
				count++;
			else
				count += SlotParam6(playerid, 7);
		}
		if(PSlotItemTypeCompare(playerid, 8, itemtype) && ShowSlotItem(playerid, 8) == itemid)
		{
			if(SlotParam6(playerid, 8) == 0)
				count++;
			else
				count += SlotParam6(playerid, 8);
		}
		if(PSlotItemTypeCompare(playerid, 9, itemtype) && ShowSlotItem(playerid, 9) == itemid)
		{
			if(SlotParam6(playerid, 9) == 0)
				count++;
			else
				count += SlotParam6(playerid, 9);
		}
		if(PSlotItemTypeCompare(playerid, 10, itemtype) && ShowSlotItem(playerid, 10) == itemid)
		{
			if(SlotParam6(playerid, 10) == 0)
				count++;
			else
				count += SlotParam6(playerid, 10);
		}
		if(PSlotItemTypeCompare(playerid, 11, itemtype) && ShowSlotItem(playerid, 11) == itemid)
		{
			if(SlotParam6(playerid, 11) == 0)
				count++;
			else
				count += SlotParam6(playerid, 11);
		}
		if(PSlotItemTypeCompare(playerid, 12, itemtype) && ShowSlotItem(playerid, 12) == itemid)
		{
			if(SlotParam6(playerid, 12) == 0)
				count++;
			else
				count += SlotParam6(playerid, 12);
		}
		if(PSlotItemTypeCompare(playerid, 13, itemtype) && ShowSlotItem(playerid, 13) == itemid)
		{
			if(SlotParam6(playerid, 13) == 0)
				count++;
			else
				count += SlotParam6(playerid, 13);
		}
		if(PSlotItemTypeCompare(playerid, 14, itemtype) && ShowSlotItem(playerid, 14) == itemid)
		{
			if(SlotParam6(playerid, 14) == 0)
				count++;
			else
				count += SlotParam6(playerid, 14);
		}
		if(PSlotItemTypeCompare(playerid, 15, itemtype) && ShowSlotItem(playerid, 15) == itemid)
		{
			if(SlotParam6(playerid, 15) == 0)
				count++;
			else
				count += SlotParam6(playerid, 15);
		}
		if(gPlayerData[playerid][pVipItem] > 0)
		{
			if(PSlotItemTypeCompare(playerid, 16, itemtype) && ShowSlotItem(playerid, 16) == itemid)
			{
				if(SlotParam6(playerid, 16) == 0)
					count++;
				else
					count += SlotParam6(playerid, 16);
			}
			if(PSlotItemTypeCompare(playerid, 17, itemtype) && ShowSlotItem(playerid, 17) == itemid)
			{
				if(SlotParam6(playerid, 17) == 0)
					count++;
				else
					count += SlotParam6(playerid, 17);
			}
			if(PSlotItemTypeCompare(playerid, 18, itemtype) && ShowSlotItem(playerid, 18) == itemid)
			{
				if(SlotParam6(playerid, 18) == 0)
					count++;
				else
					count += SlotParam6(playerid, 18);
			}
			if(PSlotItemTypeCompare(playerid, 19, itemtype) && ShowSlotItem(playerid, 19) == itemid)
			{
				if(SlotParam6(playerid, 19) == 0)
					count++;
				else
					count += SlotParam6(playerid, 19);
			}
			if(PSlotItemTypeCompare(playerid, 20, itemtype) && ShowSlotItem(playerid, 20) == itemid)
			{
				if(SlotParam6(playerid, 20) == 0)
					count++;
				else
					count += SlotParam6(playerid, 20);
			}
			if(PSlotItemTypeCompare(playerid, 21, itemtype) && ShowSlotItem(playerid, 21) == itemid)
			{
				if(SlotParam6(playerid, 21) == 0)
					count++;
				else
					count += SlotParam6(playerid, 21);
			}
			if(PSlotItemTypeCompare(playerid, 22, itemtype) && ShowSlotItem(playerid, 22) == itemid)
			{
				if(SlotParam6(playerid, 22) == 0)
					count++;
				else
					count += SlotParam6(playerid, 22);
			}
			if(PSlotItemTypeCompare(playerid, 23, itemtype) && ShowSlotItem(playerid, 23) == itemid)
			{
				if(SlotParam6(playerid, 23) == 0)
					count++;
				else
					count += SlotParam6(playerid, 23);
			}
			if(PSlotItemTypeCompare(playerid, 24, itemtype) && ShowSlotItem(playerid, 24) == itemid)
			{
				if(SlotParam6(playerid, 24) == 0)
					count++;
				else
					count += SlotParam6(playerid, 24);
			}
			if(PSlotItemTypeCompare(playerid, 25, itemtype) && ShowSlotItem(playerid, 25) == itemid)
			{
				if(SlotParam6(playerid, 25) == 0)
					count++;
				else
					count += SlotParam6(playerid, 25);
			}
		}
	}
	return count;
}

stock DeactivatePlayerItem(playerid, slot)
{
	if(CountPItems(playerid, PSlotItemType(playerid, slot), ShowSlotItem(playerid, slot)) < 0)
	{
		/* Usuniecie punktow z mapki */
		if(PSlotItemType(playerid, slot) == 1 && ShowSlotItem(playerid, slot) == 105)
		{
			new tmpslot[MAX_PLAYER_ITEM_SLOT], noChange;
			PHaveItemEx(playerid, 3, 12, tmpslot);
			for(new i = 0; i < MAX_PLAYER_ITEM_SLOT; i++)
			{
				if(tmpslot[i] && SlotParam1(playerid, i+1))
					noChange = 1;
			}
			PHaveItemEx(playerid, 1, 105, tmpslot);
			for(new i = 0; i < MAX_PLAYER_ITEM_SLOT; i++)
			{
				if(tmpslot[i])
					noChange = 1;
			}
			if(!noChange)
				RemovePlayerMapIcons(playerid, 0);
		}
		if(PSlotItemType(playerid, slot) == 3 && ShowSlotItem(playerid, slot) == 12 && SlotParam1(playerid, slot))
		{
			new tmpslot[MAX_PLAYER_ITEM_SLOT], noChange, noChange2;
			PHaveItemEx(playerid, 3, 12, tmpslot);
			for(new i = 0; i < MAX_PLAYER_ITEM_SLOT; i++)
			{
				if(tmpslot[i] && SlotParam1(playerid, i+1))
					noChange = 1;
			}
			PHaveItemEx(playerid, 1, 105, tmpslot);
			for(new i = 0; i < MAX_PLAYER_ITEM_SLOT; i++)
			{
				if(tmpslot[i])
					noChange2 = 1;
			}
			if(!noChange)
				RemovePlayerMapIcons(playerid, 1);
			if(!noChange2)
				RemovePlayerMapIcons(playerid, 0);
		}
		if(PSlotItemType(playerid, slot) == 1 && ShowSlotItem(playerid, slot) == 5)
			RemovePlayerAttachedObject(playerid, MAX_PLAYER_ATTACHED_OBJECTS-3);
		if(PSlotItemType(playerid, slot) == 1 && SlotParam1(playerid, slot) && (ShowSlotItem(playerid, slot) == 107 || ShowSlotItem(playerid, slot) == 108 || ShowSlotItem(playerid, slot) == 109 ||
			ShowSlotItem(playerid, slot) == 110 || ShowSlotItem(playerid, slot) == 111 || ShowSlotItem(playerid, slot) == 112 || ShowSlotItem(playerid, slot) == 113 || ShowSlotItem(playerid, slot) == 114 ||
			ShowSlotItem(playerid, slot) == 115 || ShowSlotItem(playerid, slot) == 116 || ShowSlotItem(playerid, slot) == 117 || ShowSlotItem(playerid, slot) == 118 || ShowSlotItem(playerid, slot) == 119 ||
			ShowSlotItem(playerid, slot) == 120 || ShowSlotItem(playerid, slot) == 121))
		{
			RemovePlayerAttachedObject(playerid, MAX_PLAYER_ATTACHED_OBJECTS-4);
		}
	}
}

/*
* Cleans player slot
*/
stock RemovePlayerItemUsed(playerid, slot)
{
	if(slot == 1)
	{
		gPlayerData[playerid][pItem1] = 0;
		gPlayerData[playerid][pItem1type] = 0;
		gPlayerData[playerid][pItem1param] = 0;
		gPlayerData[playerid][pItem1param2] = 0;
		gPlayerData[playerid][pItem1param3] = 0;
		gPlayerData[playerid][pItem1param4] = 0;
		strdel(gPlayerData[playerid][pItem1param5], 0, 64);
		strins(gPlayerData[playerid][pItem1param5], "Puste", 0, 64);
		gPlayerData[playerid][pItem1param6] = 0;

		SavePlayerData(playerid, "Item1a");
	}
	else if (slot == 2)
	{
		gPlayerData[playerid][pItem2] = 0;
		gPlayerData[playerid][pItem2type] = 0;
		gPlayerData[playerid][pItem2param] = 0;
		gPlayerData[playerid][pItem2param2] = 0;
		gPlayerData[playerid][pItem2param3] = 0;
		gPlayerData[playerid][pItem2param4] = 0;
		strdel(gPlayerData[playerid][pItem2param5], 0, 64);
		strins(gPlayerData[playerid][pItem2param5], "Puste", 0, 64);
		gPlayerData[playerid][pItem2param6] = 0;

		SavePlayerData(playerid, "Item2a");
	}
	else if (slot == 3)
	{
		gPlayerData[playerid][pItem3] = 0;
		gPlayerData[playerid][pItem3type] = 0;
		gPlayerData[playerid][pItem3param] = 0;
		gPlayerData[playerid][pItem3param2] = 0;
		gPlayerData[playerid][pItem3param3] = 0;
		gPlayerData[playerid][pItem3param4] = 0;
		strdel(gPlayerData[playerid][pItem3param5], 0, 64);
		strins(gPlayerData[playerid][pItem3param5], "Puste", 0, 64);
		gPlayerData[playerid][pItem3param6] = 0;

		SavePlayerData(playerid, "Item3a");
	}
	else if (slot == 4)
	{
		gPlayerData[playerid][pItem4] = 0;
		gPlayerData[playerid][pItem4type] = 0;
		gPlayerData[playerid][pItem4param] = 0;
		gPlayerData[playerid][pItem4param2] = 0;
		gPlayerData[playerid][pItem4param3] = 0;
		gPlayerData[playerid][pItem4param4] = 0;
		strdel(gPlayerData[playerid][pItem4param5], 0, 64);
		strins(gPlayerData[playerid][pItem4param5], "Puste", 0, 64);
		gPlayerData[playerid][pItem4param6] = 0;

		SavePlayerData(playerid, "Item4a");
	}
	else if (slot == 5)
	{
		gPlayerData[playerid][pItem5] = 0;
		gPlayerData[playerid][pItem5type] = 0;
		gPlayerData[playerid][pItem5param] = 0;
		gPlayerData[playerid][pItem5param2] = 0;
		gPlayerData[playerid][pItem5param3] = 0;
		gPlayerData[playerid][pItem5param4] = 0;
		strdel(gPlayerData[playerid][pItem5param5], 0, 64);
		strins(gPlayerData[playerid][pItem5param5], "Puste", 0, 64);
		gPlayerData[playerid][pItem5param6] = 0;

		SavePlayerData(playerid, "Item5a");
	}
	else if (slot == 6)
	{
		gPlayerData[playerid][pItem6] = 0;
		gPlayerData[playerid][pItem6type] = 0;
		gPlayerData[playerid][pItem6param] = 0;
		gPlayerData[playerid][pItem6param2] = 0;
		gPlayerData[playerid][pItem6param3] = 0;
		gPlayerData[playerid][pItem6param4] = 0;
		strdel(gPlayerData[playerid][pItem6param5], 0, 64);
		strins(gPlayerData[playerid][pItem6param5], "Puste", 0, 64);
		gPlayerData[playerid][pItem6param6] = 0;

		SavePlayerData(playerid, "Item6a");
	}
	else if (slot == 7)
	{
		gPlayerData[playerid][pItem7] = 0;
		gPlayerData[playerid][pItem7type] = 0;
		gPlayerData[playerid][pItem7param] = 0;
		gPlayerData[playerid][pItem7param2] = 0;
		gPlayerData[playerid][pItem7param3] = 0;
		gPlayerData[playerid][pItem7param4] = 0;
		strdel(gPlayerData[playerid][pItem7param5], 0, 64);
		strins(gPlayerData[playerid][pItem7param5], "Puste", 0, 64);
		gPlayerData[playerid][pItem7param6] = 0;

		SavePlayerData(playerid, "Item7a");
	}
	else if (slot == 8)
	{
		gPlayerData[playerid][pItem8] = 0;
		gPlayerData[playerid][pItem8type] = 0;
		gPlayerData[playerid][pItem8param] = 0;
		gPlayerData[playerid][pItem8param2] = 0;
		gPlayerData[playerid][pItem8param3] = 0;
		gPlayerData[playerid][pItem8param4] = 0;
		strdel(gPlayerData[playerid][pItem8param5], 0, 64);
		strins(gPlayerData[playerid][pItem8param5], "Puste", 0, 64);
		gPlayerData[playerid][pItem8param6] = 0;

		SavePlayerData(playerid, "Item8a");
	}
	else if (slot == 9)
	{
		gPlayerData[playerid][pItem9] = 0;
		gPlayerData[playerid][pItem9type] = 0;
		gPlayerData[playerid][pItem9param] = 0;
		gPlayerData[playerid][pItem9param2] = 0;
		gPlayerData[playerid][pItem9param3] = 0;
		gPlayerData[playerid][pItem9param4] = 0;
		strdel(gPlayerData[playerid][pItem9param5], 0, 64);
		strins(gPlayerData[playerid][pItem9param5], "Puste", 0, 64);
		gPlayerData[playerid][pItem9param6] = 0;
		
		SavePlayerData(playerid, "Item9a");
	}
	else if (slot == 10)
	{
		gPlayerData[playerid][pItem10] = 0;
		gPlayerData[playerid][pItem10type] = 0;
		gPlayerData[playerid][pItem10param] = 0;
		gPlayerData[playerid][pItem10param2] = 0;
		gPlayerData[playerid][pItem10param3] = 0;
		gPlayerData[playerid][pItem10param4] = 0;
		strdel(gPlayerData[playerid][pItem10param5], 0, 64);
		strins(gPlayerData[playerid][pItem10param5], "Puste", 0, 64);
		gPlayerData[playerid][pItem10param6] = 0;

		SavePlayerData(playerid, "Item10a");
	}
	else if (slot == 11)
	{
		gPlayerData[playerid][pItem11] = 0;
		gPlayerData[playerid][pItem11type] = 0;
		gPlayerData[playerid][pItem11param] = 0;
		gPlayerData[playerid][pItem11param2] = 0;
		gPlayerData[playerid][pItem11param3] = 0;
		gPlayerData[playerid][pItem11param4] = 0;
		strdel(gPlayerData[playerid][pItem11param5], 0, 64);
		strins(gPlayerData[playerid][pItem11param5], "Puste", 0, 64);
		gPlayerData[playerid][pItem11param6] = 0;

		SavePlayerData(playerid, "Item11a");
	}
	else if (slot == 12)
	{
		gPlayerData[playerid][pItem12] = 0;
		gPlayerData[playerid][pItem12type] = 0;
		gPlayerData[playerid][pItem12param] = 0;
		gPlayerData[playerid][pItem12param2] = 0;
		gPlayerData[playerid][pItem12param3] = 0;
		gPlayerData[playerid][pItem12param4] = 0;
		strdel(gPlayerData[playerid][pItem12param5], 0, 64);
		strins(gPlayerData[playerid][pItem12param5], "Puste", 0, 64);
		gPlayerData[playerid][pItem12param6] = 0;

		SavePlayerData(playerid, "Item12a");
	}
	else if (slot == 13)
	{
		gPlayerData[playerid][pItem13] = 0;
		gPlayerData[playerid][pItem13type] = 0;
		gPlayerData[playerid][pItem13param] = 0;
		gPlayerData[playerid][pItem13param2] = 0;
		gPlayerData[playerid][pItem13param3] = 0;
		gPlayerData[playerid][pItem13param4] = 0;
		strdel(gPlayerData[playerid][pItem13param5], 0, 64);
		strins(gPlayerData[playerid][pItem13param5], "Puste", 0, 64);
		gPlayerData[playerid][pItem13param6] = 0;

		SavePlayerData(playerid, "Item13a");
	}
	else if (slot == 14)
	{
		gPlayerData[playerid][pItem14] = 0;
		gPlayerData[playerid][pItem14type] = 0;
		gPlayerData[playerid][pItem14param] = 0;
		gPlayerData[playerid][pItem14param2] = 0;
		gPlayerData[playerid][pItem14param3] = 0;
		gPlayerData[playerid][pItem14param4] = 0;
		strdel(gPlayerData[playerid][pItem14param5], 0, 64);
		strins(gPlayerData[playerid][pItem14param5], "Puste", 0, 64);
		gPlayerData[playerid][pItem14param6] = 0;

		SavePlayerData(playerid, "Item14a");
	}
	else if (slot == 15)
	{
		gPlayerData[playerid][pItem15] = 0;
		gPlayerData[playerid][pItem15type] = 0;
		gPlayerData[playerid][pItem15param] = 0;
		gPlayerData[playerid][pItem15param2] = 0;
		gPlayerData[playerid][pItem15param3] = 0;
		gPlayerData[playerid][pItem15param4] = 0;
		strdel(gPlayerData[playerid][pItem15param5], 0, 64);
		strins(gPlayerData[playerid][pItem15param5], "Puste", 0, 64);
		gPlayerData[playerid][pItem15param6] = 0;

		SavePlayerData(playerid, "Item15a");
	}
	else if (slot == 16)
	{
		gPlayerData[playerid][pItem16] = 0;
		gPlayerData[playerid][pItem16type] = 0;
		gPlayerData[playerid][pItem16param] = 0;
		gPlayerData[playerid][pItem16param2] = 0;
		gPlayerData[playerid][pItem16param3] = 0;
		gPlayerData[playerid][pItem16param4] = 0;
		strdel(gPlayerData[playerid][pItem16param5], 0, 64);
		strins(gPlayerData[playerid][pItem16param5], "Puste", 0, 64);
		gPlayerData[playerid][pItem16param6] = 0;

		SavePlayerData(playerid, "Item16a");
	}
	else if (slot == 17)
	{
		gPlayerData[playerid][pItem17] = 0;
		gPlayerData[playerid][pItem17type] = 0;
		gPlayerData[playerid][pItem17param] = 0;
		gPlayerData[playerid][pItem17param2] = 0;
		gPlayerData[playerid][pItem17param3] = 0;
		gPlayerData[playerid][pItem17param4] = 0;
		strdel(gPlayerData[playerid][pItem17param5], 0, 64);
		strins(gPlayerData[playerid][pItem17param5], "Puste", 0, 64);
		gPlayerData[playerid][pItem17param6] = 0;

		SavePlayerData(playerid, "Item17a");
	}
	else if (slot == 18)
	{
		gPlayerData[playerid][pItem18] = 0;
		gPlayerData[playerid][pItem18type] = 0;
		gPlayerData[playerid][pItem18param] = 0;
		gPlayerData[playerid][pItem18param2] = 0;
		gPlayerData[playerid][pItem18param3] = 0;
		gPlayerData[playerid][pItem18param4] = 0;
		strdel(gPlayerData[playerid][pItem18param5], 0, 64);
		strins(gPlayerData[playerid][pItem18param5], "Puste", 0, 64);
		gPlayerData[playerid][pItem18param6] = 0;

		SavePlayerData(playerid, "Item18a");
	}
	else if (slot == 19)
	{
		gPlayerData[playerid][pItem19] = 0;
		gPlayerData[playerid][pItem19type] = 0;
		gPlayerData[playerid][pItem19param] = 0;
		gPlayerData[playerid][pItem19param2] = 0;
		gPlayerData[playerid][pItem19param3] = 0;
		gPlayerData[playerid][pItem19param4] = 0;
		strdel(gPlayerData[playerid][pItem19param5], 0, 64);
		strins(gPlayerData[playerid][pItem19param5], "Puste", 0, 64);
		gPlayerData[playerid][pItem19param6] = 0;

		SavePlayerData(playerid, "Item19a");
	}
	else if (slot == 20)
	{
		gPlayerData[playerid][pItem20] = 0;
		gPlayerData[playerid][pItem20type] = 0;
		gPlayerData[playerid][pItem20param] = 0;
		gPlayerData[playerid][pItem20param2] = 0;
		gPlayerData[playerid][pItem20param3] = 0;
		gPlayerData[playerid][pItem20param4] = 0;
		strdel(gPlayerData[playerid][pItem20param5], 0, 64);
		strins(gPlayerData[playerid][pItem20param5], "Puste", 0, 64);
		gPlayerData[playerid][pItem20param6] = 0;

		SavePlayerData(playerid, "Item20a");
	}
	else if (slot == 21)
	{
		gPlayerData[playerid][pItem21] = 0;
		gPlayerData[playerid][pItem21type] = 0;
		gPlayerData[playerid][pItem21param] = 0;
		gPlayerData[playerid][pItem21param2] = 0;
		gPlayerData[playerid][pItem21param3] = 0;
		gPlayerData[playerid][pItem21param4] = 0;
		strdel(gPlayerData[playerid][pItem21param5], 0, 64);
		strins(gPlayerData[playerid][pItem21param5], "Puste", 0, 64);
		gPlayerData[playerid][pItem21param6] = 0;

		SavePlayerData(playerid, "Item21a");
	}
	else if (slot == 22)
	{
		gPlayerData[playerid][pItem22] = 0;
		gPlayerData[playerid][pItem22type] = 0;
		gPlayerData[playerid][pItem22param] = 0;
		gPlayerData[playerid][pItem22param2] = 0;
		gPlayerData[playerid][pItem22param3] = 0;
		gPlayerData[playerid][pItem22param4] = 0;
		strdel(gPlayerData[playerid][pItem22param5], 0, 64);
		strins(gPlayerData[playerid][pItem22param5], "Puste", 0, 64);
		gPlayerData[playerid][pItem22param6] = 0;

		SavePlayerData(playerid, "Item22a");
	}
	else if (slot == 23)
	{
		gPlayerData[playerid][pItem23] = 0;
		gPlayerData[playerid][pItem23type] = 0;
		gPlayerData[playerid][pItem23param] = 0;
		gPlayerData[playerid][pItem23param2] = 0;
		gPlayerData[playerid][pItem23param3] = 0;
		gPlayerData[playerid][pItem23param4] = 0;
		strdel(gPlayerData[playerid][pItem23param5], 0, 64);
		strins(gPlayerData[playerid][pItem23param5], "Puste", 0, 64);
		gPlayerData[playerid][pItem23param6] = 0;

		SavePlayerData(playerid, "Item23a");
	}
	else if (slot == 24)
	{
		gPlayerData[playerid][pItem24] = 0;
		gPlayerData[playerid][pItem24type] = 0;
		gPlayerData[playerid][pItem24param] = 0;
		gPlayerData[playerid][pItem24param2] = 0;
		gPlayerData[playerid][pItem24param3] = 0;
		gPlayerData[playerid][pItem24param4] = 0;
		strdel(gPlayerData[playerid][pItem24param5], 0, 64);
		strins(gPlayerData[playerid][pItem24param5], "Puste", 0, 64);
		gPlayerData[playerid][pItem24param6] = 0;

		SavePlayerData(playerid, "Item24a");
	}
	else if (slot == 25)
	{
		gPlayerData[playerid][pItem25] = 0;
		gPlayerData[playerid][pItem25type] = 0;
		gPlayerData[playerid][pItem25param] = 0;
		gPlayerData[playerid][pItem25param2] = 0;
		gPlayerData[playerid][pItem25param3] = 0;
		gPlayerData[playerid][pItem25param4] = 0;
		strdel(gPlayerData[playerid][pItem25param5], 0, 64);
		strins(gPlayerData[playerid][pItem25param5], "Puste", 0, 64);
		gPlayerData[playerid][pItem25param6] = 0;

		SavePlayerData(playerid, "Item25a");
	}
	return 1;
}

/*
* Remove exact amount of item from slot
*/
stock RemovePlayerItemExUsed(playerid, slot, value = 1)
{
	/* Usuniecie punktow z mapki */
	if(SlotParam6(playerid, slot) <= value)
	{
		DeactivatePlayerItem(playerid, slot);
		RemovePlayerItemUsed(playerid, slot);
	}
	else
	{
		SetPSlotParam6(playerid, slot, SlotParam6(playerid, slot)-value);
	}
	return 1;
}

/*
* Cleans player slot and create pickup
*/
stock RemovePlayerItem(playerid, slot)
{
	InsertPlayerPickupItem(playerid, slot, SlotParam6(playerid, slot) );
	if(slot == 1)
	{
		gPlayerData[playerid][pItem1] = 0;
		gPlayerData[playerid][pItem1type] = 0;
		gPlayerData[playerid][pItem1param] = 0;
		gPlayerData[playerid][pItem1param2] = 0;
		gPlayerData[playerid][pItem1param3] = 0;
		gPlayerData[playerid][pItem1param4] = 0;
		strdel(gPlayerData[playerid][pItem1param5], 0, 64);
		strins(gPlayerData[playerid][pItem1param5], "Puste", 0, 64);
		gPlayerData[playerid][pItem1param6] = 0;

		SavePlayerData(playerid, "Item1a");
	}
	else if (slot == 2)
	{
		gPlayerData[playerid][pItem2] = 0;
		gPlayerData[playerid][pItem2type] = 0;
		gPlayerData[playerid][pItem2param] = 0;
		gPlayerData[playerid][pItem2param2] = 0;
		gPlayerData[playerid][pItem2param3] = 0;
		gPlayerData[playerid][pItem2param4] = 0;
		strdel(gPlayerData[playerid][pItem2param5], 0, 64);
		strins(gPlayerData[playerid][pItem2param5], "Puste", 0, 64);
		gPlayerData[playerid][pItem2param6] = 0;

		SavePlayerData(playerid, "Item2a");
	}
	else if (slot == 3)
	{
		gPlayerData[playerid][pItem3] = 0;
		gPlayerData[playerid][pItem3type] = 0;
		gPlayerData[playerid][pItem3param] = 0;
		gPlayerData[playerid][pItem3param2] = 0;
		gPlayerData[playerid][pItem3param3] = 0;
		gPlayerData[playerid][pItem3param4] = 0;
		strdel(gPlayerData[playerid][pItem3param5], 0, 64);
		strins(gPlayerData[playerid][pItem3param5], "Puste", 0, 64);
		gPlayerData[playerid][pItem3param6] = 0;

		SavePlayerData(playerid, "Item3a");
	}
	else if (slot == 4)
	{
		gPlayerData[playerid][pItem4] = 0;
		gPlayerData[playerid][pItem4type] = 0;
		gPlayerData[playerid][pItem4param] = 0;
		gPlayerData[playerid][pItem4param2] = 0;
		gPlayerData[playerid][pItem4param3] = 0;
		gPlayerData[playerid][pItem4param4] = 0;
		strdel(gPlayerData[playerid][pItem4param5], 0, 64);
		strins(gPlayerData[playerid][pItem4param5], "Puste", 0, 64);
		gPlayerData[playerid][pItem4param6] = 0;

		SavePlayerData(playerid, "Item4a");
	}
	else if (slot == 5)
	{
		gPlayerData[playerid][pItem5] = 0;
		gPlayerData[playerid][pItem5type] = 0;
		gPlayerData[playerid][pItem5param] = 0;
		gPlayerData[playerid][pItem5param2] = 0;
		gPlayerData[playerid][pItem5param3] = 0;
		gPlayerData[playerid][pItem5param4] = 0;
		strdel(gPlayerData[playerid][pItem5param5], 0, 64);
		strins(gPlayerData[playerid][pItem5param5], "Puste", 0, 64);
		gPlayerData[playerid][pItem5param6] = 0;

		SavePlayerData(playerid, "Item5a");
	}
	else if (slot == 6)
	{
		gPlayerData[playerid][pItem6] = 0;
		gPlayerData[playerid][pItem6type] = 0;
		gPlayerData[playerid][pItem6param] = 0;
		gPlayerData[playerid][pItem6param2] = 0;
		gPlayerData[playerid][pItem6param3] = 0;
		gPlayerData[playerid][pItem6param4] = 0;
		strdel(gPlayerData[playerid][pItem6param5], 0, 64);
		strins(gPlayerData[playerid][pItem6param5], "Puste", 0, 64);
		gPlayerData[playerid][pItem6param6] = 0;

		SavePlayerData(playerid, "Item6a");
	}
	else if (slot == 7)
	{
		gPlayerData[playerid][pItem7] = 0;
		gPlayerData[playerid][pItem7type] = 0;
		gPlayerData[playerid][pItem7param] = 0;
		gPlayerData[playerid][pItem7param2] = 0;
		gPlayerData[playerid][pItem7param3] = 0;
		gPlayerData[playerid][pItem7param4] = 0;
		strdel(gPlayerData[playerid][pItem7param5], 0, 64);
		strins(gPlayerData[playerid][pItem7param5], "Puste", 0, 64);
		gPlayerData[playerid][pItem7param6] = 0;

		SavePlayerData(playerid, "Item7a");
	}
	else if (slot == 8)
	{
		gPlayerData[playerid][pItem8] = 0;
		gPlayerData[playerid][pItem8type] = 0;
		gPlayerData[playerid][pItem8param] = 0;
		gPlayerData[playerid][pItem8param2] = 0;
		gPlayerData[playerid][pItem8param3] = 0;
		gPlayerData[playerid][pItem8param4] = 0;
		strdel(gPlayerData[playerid][pItem8param5], 0, 64);
		strins(gPlayerData[playerid][pItem8param5], "Puste", 0, 64);
		gPlayerData[playerid][pItem8param6] = 0;

		SavePlayerData(playerid, "Item8a");
	}
	else if (slot == 9)
	{
		gPlayerData[playerid][pItem9] = 0;
		gPlayerData[playerid][pItem9type] = 0;
		gPlayerData[playerid][pItem9param] = 0;
		gPlayerData[playerid][pItem9param2] = 0;
		gPlayerData[playerid][pItem9param3] = 0;
		gPlayerData[playerid][pItem9param4] = 0;
		strdel(gPlayerData[playerid][pItem9param5], 0, 64);
		strins(gPlayerData[playerid][pItem9param5], "Puste", 0, 64);
		gPlayerData[playerid][pItem9param6] = 0;
		
		SavePlayerData(playerid, "Item9a");
	}
	else if (slot == 10)
	{
		gPlayerData[playerid][pItem10] = 0;
		gPlayerData[playerid][pItem10type] = 0;
		gPlayerData[playerid][pItem10param] = 0;
		gPlayerData[playerid][pItem10param2] = 0;
		gPlayerData[playerid][pItem10param3] = 0;
		gPlayerData[playerid][pItem10param4] = 0;
		strdel(gPlayerData[playerid][pItem10param5], 0, 64);
		strins(gPlayerData[playerid][pItem10param5], "Puste", 0, 64);
		gPlayerData[playerid][pItem10param6] = 0;

		SavePlayerData(playerid, "Item10a");
	}
	else if (slot == 11)
	{
		gPlayerData[playerid][pItem11] = 0;
		gPlayerData[playerid][pItem11type] = 0;
		gPlayerData[playerid][pItem11param] = 0;
		gPlayerData[playerid][pItem11param2] = 0;
		gPlayerData[playerid][pItem11param3] = 0;
		gPlayerData[playerid][pItem11param4] = 0;
		strdel(gPlayerData[playerid][pItem11param5], 0, 64);
		strins(gPlayerData[playerid][pItem11param5], "Puste", 0, 64);
		gPlayerData[playerid][pItem11param6] = 0;

		SavePlayerData(playerid, "Item11a");
	}
	else if (slot == 12)
	{
		gPlayerData[playerid][pItem12] = 0;
		gPlayerData[playerid][pItem12type] = 0;
		gPlayerData[playerid][pItem12param] = 0;
		gPlayerData[playerid][pItem12param2] = 0;
		gPlayerData[playerid][pItem12param3] = 0;
		gPlayerData[playerid][pItem12param4] = 0;
		strdel(gPlayerData[playerid][pItem12param5], 0, 64);
		strins(gPlayerData[playerid][pItem12param5], "Puste", 0, 64);
		gPlayerData[playerid][pItem12param6] = 0;

		SavePlayerData(playerid, "Item12a");
	}
	else if (slot == 13)
	{
		gPlayerData[playerid][pItem13] = 0;
		gPlayerData[playerid][pItem13type] = 0;
		gPlayerData[playerid][pItem13param] = 0;
		gPlayerData[playerid][pItem13param2] = 0;
		gPlayerData[playerid][pItem13param3] = 0;
		gPlayerData[playerid][pItem13param4] = 0;
		strdel(gPlayerData[playerid][pItem13param5], 0, 64);
		strins(gPlayerData[playerid][pItem13param5], "Puste", 0, 64);
		gPlayerData[playerid][pItem13param6] = 0;

		SavePlayerData(playerid, "Item13a");
	}
	else if (slot == 14)
	{
		gPlayerData[playerid][pItem14] = 0;
		gPlayerData[playerid][pItem14type] = 0;
		gPlayerData[playerid][pItem14param] = 0;
		gPlayerData[playerid][pItem14param2] = 0;
		gPlayerData[playerid][pItem14param3] = 0;
		gPlayerData[playerid][pItem14param4] = 0;
		strdel(gPlayerData[playerid][pItem14param5], 0, 64);
		strins(gPlayerData[playerid][pItem14param5], "Puste", 0, 64);
		gPlayerData[playerid][pItem14param6] = 0;

		SavePlayerData(playerid, "Item14a");
	}
	else if (slot == 15)
	{
		gPlayerData[playerid][pItem15] = 0;
		gPlayerData[playerid][pItem15type] = 0;
		gPlayerData[playerid][pItem15param] = 0;
		gPlayerData[playerid][pItem15param2] = 0;
		gPlayerData[playerid][pItem15param3] = 0;
		gPlayerData[playerid][pItem15param4] = 0;
		strdel(gPlayerData[playerid][pItem15param5], 0, 64);
		strins(gPlayerData[playerid][pItem15param5], "Puste", 0, 64);
		gPlayerData[playerid][pItem15param6] = 0;

		SavePlayerData(playerid, "Item15a");
	}
	else if (slot == 16)
	{
		gPlayerData[playerid][pItem16] = 0;
		gPlayerData[playerid][pItem16type] = 0;
		gPlayerData[playerid][pItem16param] = 0;
		gPlayerData[playerid][pItem16param2] = 0;
		gPlayerData[playerid][pItem16param3] = 0;
		gPlayerData[playerid][pItem16param4] = 0;
		strdel(gPlayerData[playerid][pItem16param5], 0, 64);
		strins(gPlayerData[playerid][pItem16param5], "Puste", 0, 64);
		gPlayerData[playerid][pItem16param6] = 0;

		SavePlayerData(playerid, "Item16a");
	}
	else if (slot == 17)
	{
		gPlayerData[playerid][pItem17] = 0;
		gPlayerData[playerid][pItem17type] = 0;
		gPlayerData[playerid][pItem17param] = 0;
		gPlayerData[playerid][pItem17param2] = 0;
		gPlayerData[playerid][pItem17param3] = 0;
		gPlayerData[playerid][pItem17param4] = 0;
		strdel(gPlayerData[playerid][pItem17param5], 0, 64);
		strins(gPlayerData[playerid][pItem17param5], "Puste", 0, 64);
		gPlayerData[playerid][pItem17param6] = 0;

		SavePlayerData(playerid, "Item17a");
	}
	else if (slot == 18)
	{
		gPlayerData[playerid][pItem18] = 0;
		gPlayerData[playerid][pItem18type] = 0;
		gPlayerData[playerid][pItem18param] = 0;
		gPlayerData[playerid][pItem18param2] = 0;
		gPlayerData[playerid][pItem18param3] = 0;
		gPlayerData[playerid][pItem18param4] = 0;
		strdel(gPlayerData[playerid][pItem18param5], 0, 64);
		strins(gPlayerData[playerid][pItem18param5], "Puste", 0, 64);
		gPlayerData[playerid][pItem18param6] = 0;

		SavePlayerData(playerid, "Item18a");
	}
	else if (slot == 19)
	{
		gPlayerData[playerid][pItem19] = 0;
		gPlayerData[playerid][pItem19type] = 0;
		gPlayerData[playerid][pItem19param] = 0;
		gPlayerData[playerid][pItem19param2] = 0;
		gPlayerData[playerid][pItem19param3] = 0;
		gPlayerData[playerid][pItem19param4] = 0;
		strdel(gPlayerData[playerid][pItem19param5], 0, 64);
		strins(gPlayerData[playerid][pItem19param5], "Puste", 0, 64);
		gPlayerData[playerid][pItem19param6] = 0;

		SavePlayerData(playerid, "Item19a");
	}
	else if (slot == 20)
	{
		gPlayerData[playerid][pItem20] = 0;
		gPlayerData[playerid][pItem20type] = 0;
		gPlayerData[playerid][pItem20param] = 0;
		gPlayerData[playerid][pItem20param2] = 0;
		gPlayerData[playerid][pItem20param3] = 0;
		gPlayerData[playerid][pItem20param4] = 0;
		strdel(gPlayerData[playerid][pItem20param5], 0, 64);
		strins(gPlayerData[playerid][pItem20param5], "Puste", 0, 64);
		gPlayerData[playerid][pItem20param6] = 0;

		SavePlayerData(playerid, "Item20a");
	}
	else if (slot == 21)
	{
		gPlayerData[playerid][pItem21] = 0;
		gPlayerData[playerid][pItem21type] = 0;
		gPlayerData[playerid][pItem21param] = 0;
		gPlayerData[playerid][pItem21param2] = 0;
		gPlayerData[playerid][pItem21param3] = 0;
		gPlayerData[playerid][pItem21param4] = 0;
		strdel(gPlayerData[playerid][pItem21param5], 0, 64);
		strins(gPlayerData[playerid][pItem21param5], "Puste", 0, 64);
		gPlayerData[playerid][pItem21param6] = 0;

		SavePlayerData(playerid, "Item21a");
	}
	else if (slot == 22)
	{
		gPlayerData[playerid][pItem22] = 0;
		gPlayerData[playerid][pItem22type] = 0;
		gPlayerData[playerid][pItem22param] = 0;
		gPlayerData[playerid][pItem22param2] = 0;
		gPlayerData[playerid][pItem22param3] = 0;
		gPlayerData[playerid][pItem22param4] = 0;
		strdel(gPlayerData[playerid][pItem22param5], 0, 64);
		strins(gPlayerData[playerid][pItem22param5], "Puste", 0, 64);
		gPlayerData[playerid][pItem22param6] = 0;

		SavePlayerData(playerid, "Item22a");
	}
	else if (slot == 23)
	{
		gPlayerData[playerid][pItem23] = 0;
		gPlayerData[playerid][pItem23type] = 0;
		gPlayerData[playerid][pItem23param] = 0;
		gPlayerData[playerid][pItem23param2] = 0;
		gPlayerData[playerid][pItem23param3] = 0;
		gPlayerData[playerid][pItem23param4] = 0;
		strdel(gPlayerData[playerid][pItem23param5], 0, 64);
		strins(gPlayerData[playerid][pItem23param5], "Puste", 0, 64);
		gPlayerData[playerid][pItem23param6] = 0;

		SavePlayerData(playerid, "Item23a");
	}
	else if (slot == 24)
	{
		gPlayerData[playerid][pItem24] = 0;
		gPlayerData[playerid][pItem24type] = 0;
		gPlayerData[playerid][pItem24param] = 0;
		gPlayerData[playerid][pItem24param2] = 0;
		gPlayerData[playerid][pItem24param3] = 0;
		gPlayerData[playerid][pItem24param4] = 0;
		strdel(gPlayerData[playerid][pItem24param5], 0, 64);
		strins(gPlayerData[playerid][pItem24param5], "Puste", 0, 64);
		gPlayerData[playerid][pItem24param6] = 0;

		SavePlayerData(playerid, "Item24a");
	}
	else if (slot == 25)
	{
		gPlayerData[playerid][pItem25] = 0;
		gPlayerData[playerid][pItem25type] = 0;
		gPlayerData[playerid][pItem25param] = 0;
		gPlayerData[playerid][pItem25param2] = 0;
		gPlayerData[playerid][pItem25param3] = 0;
		gPlayerData[playerid][pItem25param4] = 0;
		strdel(gPlayerData[playerid][pItem25param5], 0, 64);
		strins(gPlayerData[playerid][pItem25param5], "Puste", 0, 64);
		gPlayerData[playerid][pItem25param6] = 0;

		SavePlayerData(playerid, "Item25a");
	}
	return 1;
}

/*
* Removes just one item from slot and creates pickup
*/
stock RemovePlayerItemEx(playerid, slot)
{
	if(SlotParam6(playerid, slot) <= 1)
	{
		DeactivatePlayerItem(playerid, slot);
		RemovePlayerItem(playerid, slot);
	}
	else
	{
		SetPSlotParam6(playerid, slot, SlotParam6(playerid, slot)-1);
		InsertPlayerPickupItem(playerid, slot);
	}
	gJustDropped[playerid] = 2;
	return 1;
}

stock RunActivatedPlayerItems(playerid)
{
	if(PHaveExpandItem(playerid))
	{
		SetPlayerAttachedObject(playerid, MAX_PLAYER_ATTACHED_OBJECTS-3, 371, 1,
			BackPackOffSet[gPlayerData[playerid][pSkin]][0],
			BackPackOffSet[gPlayerData[playerid][pSkin]][1],
			BackPackOffSet[gPlayerData[playerid][pSkin]][2],
			BackPackOffSet[gPlayerData[playerid][pSkin]][3],
			BackPackOffSet[gPlayerData[playerid][pSkin]][4],
			BackPackOffSet[gPlayerData[playerid][pSkin]][5],
			BackPackOffSet[gPlayerData[playerid][pSkin]][6],
			BackPackOffSet[gPlayerData[playerid][pSkin]][7],
			BackPackOffSet[gPlayerData[playerid][pSkin]][8]
		);
	}
	new slot = PHaveItem(playerid, 1, 107);
	if(slot)
	{
		if(SlotParam1(playerid, slot))
		{
			SetPlayerAttachedObject(playerid, MAX_PLAYER_ATTACHED_OBJECTS-4, 19039, 5,
				WatchOffSet[gPlayerData[playerid][pSkin]][0],
				WatchOffSet[gPlayerData[playerid][pSkin]][1],
				WatchOffSet[gPlayerData[playerid][pSkin]][2],
				WatchOffSet[gPlayerData[playerid][pSkin]][3],
				WatchOffSet[gPlayerData[playerid][pSkin]][4],
				WatchOffSet[gPlayerData[playerid][pSkin]][5],
				WatchOffSet[gPlayerData[playerid][pSkin]][6],
				WatchOffSet[gPlayerData[playerid][pSkin]][7],
				WatchOffSet[gPlayerData[playerid][pSkin]][8]
			);
		}
	}
	slot = PHaveItem(playerid, 1, 108);
	if(slot)
	{
		if(SlotParam1(playerid, slot))
		{
			SetPlayerAttachedObject(playerid, MAX_PLAYER_ATTACHED_OBJECTS-4, 19040, 5,
				WatchOffSet[gPlayerData[playerid][pSkin]][0],
				WatchOffSet[gPlayerData[playerid][pSkin]][1],
				WatchOffSet[gPlayerData[playerid][pSkin]][2],
				WatchOffSet[gPlayerData[playerid][pSkin]][3],
				WatchOffSet[gPlayerData[playerid][pSkin]][4],
				WatchOffSet[gPlayerData[playerid][pSkin]][5],
				WatchOffSet[gPlayerData[playerid][pSkin]][6],
				WatchOffSet[gPlayerData[playerid][pSkin]][7],
				WatchOffSet[gPlayerData[playerid][pSkin]][8]
			);
		}
	}
	slot = PHaveItem(playerid, 1, 109);
	if(slot)
	{
		if(SlotParam1(playerid, slot))
		{
			SetPlayerAttachedObject(playerid, MAX_PLAYER_ATTACHED_OBJECTS-4, 19041, 5,
				WatchOffSet[gPlayerData[playerid][pSkin]][0],
				WatchOffSet[gPlayerData[playerid][pSkin]][1],
				WatchOffSet[gPlayerData[playerid][pSkin]][2],
				WatchOffSet[gPlayerData[playerid][pSkin]][3],
				WatchOffSet[gPlayerData[playerid][pSkin]][4],
				WatchOffSet[gPlayerData[playerid][pSkin]][5],
				WatchOffSet[gPlayerData[playerid][pSkin]][6],
				WatchOffSet[gPlayerData[playerid][pSkin]][7],
				WatchOffSet[gPlayerData[playerid][pSkin]][8]
			);
		}
	}
	slot = PHaveItem(playerid, 1, 110);
	if(slot)
	{
		if(SlotParam1(playerid, slot))
		{
			SetPlayerAttachedObject(playerid, MAX_PLAYER_ATTACHED_OBJECTS-4, 19042, 5,
				WatchOffSet[gPlayerData[playerid][pSkin]][0],
				WatchOffSet[gPlayerData[playerid][pSkin]][1],
				WatchOffSet[gPlayerData[playerid][pSkin]][2],
				WatchOffSet[gPlayerData[playerid][pSkin]][3],
				WatchOffSet[gPlayerData[playerid][pSkin]][4],
				WatchOffSet[gPlayerData[playerid][pSkin]][5],
				WatchOffSet[gPlayerData[playerid][pSkin]][6],
				WatchOffSet[gPlayerData[playerid][pSkin]][7],
				WatchOffSet[gPlayerData[playerid][pSkin]][8]
			);
		}
	}
	slot = PHaveItem(playerid, 1, 111);
	if(slot)
	{
		if(SlotParam1(playerid, slot))
		{
			SetPlayerAttachedObject(playerid, MAX_PLAYER_ATTACHED_OBJECTS-4, 19043, 5,
				WatchOffSet[gPlayerData[playerid][pSkin]][0],
				WatchOffSet[gPlayerData[playerid][pSkin]][1],
				WatchOffSet[gPlayerData[playerid][pSkin]][2],
				WatchOffSet[gPlayerData[playerid][pSkin]][3],
				WatchOffSet[gPlayerData[playerid][pSkin]][4],
				WatchOffSet[gPlayerData[playerid][pSkin]][5],
				WatchOffSet[gPlayerData[playerid][pSkin]][6],
				WatchOffSet[gPlayerData[playerid][pSkin]][7],
				WatchOffSet[gPlayerData[playerid][pSkin]][8]
			);
		}
	}
	slot = PHaveItem(playerid, 1, 112);
	if(slot)
	{
		if(SlotParam1(playerid, slot))
		{
			SetPlayerAttachedObject(playerid, MAX_PLAYER_ATTACHED_OBJECTS-4, 19044, 5,
				WatchOffSet[gPlayerData[playerid][pSkin]][0],
				WatchOffSet[gPlayerData[playerid][pSkin]][1],
				WatchOffSet[gPlayerData[playerid][pSkin]][2],
				WatchOffSet[gPlayerData[playerid][pSkin]][3],
				WatchOffSet[gPlayerData[playerid][pSkin]][4],
				WatchOffSet[gPlayerData[playerid][pSkin]][5],
				WatchOffSet[gPlayerData[playerid][pSkin]][6],
				WatchOffSet[gPlayerData[playerid][pSkin]][7],
				WatchOffSet[gPlayerData[playerid][pSkin]][8]
			);
		}
	}
	slot = PHaveItem(playerid, 1, 113);
	if(slot)
	{
		if(SlotParam1(playerid, slot))
		{
			SetPlayerAttachedObject(playerid, MAX_PLAYER_ATTACHED_OBJECTS-4, 19045, 5,
				WatchOffSet[gPlayerData[playerid][pSkin]][0],
				WatchOffSet[gPlayerData[playerid][pSkin]][1],
				WatchOffSet[gPlayerData[playerid][pSkin]][2],
				WatchOffSet[gPlayerData[playerid][pSkin]][3],
				WatchOffSet[gPlayerData[playerid][pSkin]][4],
				WatchOffSet[gPlayerData[playerid][pSkin]][5],
				WatchOffSet[gPlayerData[playerid][pSkin]][6],
				WatchOffSet[gPlayerData[playerid][pSkin]][7],
				WatchOffSet[gPlayerData[playerid][pSkin]][8]
			);
		}
	}
	slot = PHaveItem(playerid, 1, 114);
	if(slot)
	{
		if(SlotParam1(playerid, slot))
		{
			SetPlayerAttachedObject(playerid, MAX_PLAYER_ATTACHED_OBJECTS-4, 19046, 5,
				WatchOffSet[gPlayerData[playerid][pSkin]][0],
				WatchOffSet[gPlayerData[playerid][pSkin]][1],
				WatchOffSet[gPlayerData[playerid][pSkin]][2],
				WatchOffSet[gPlayerData[playerid][pSkin]][3],
				WatchOffSet[gPlayerData[playerid][pSkin]][4],
				WatchOffSet[gPlayerData[playerid][pSkin]][5],
				WatchOffSet[gPlayerData[playerid][pSkin]][6],
				WatchOffSet[gPlayerData[playerid][pSkin]][7],
				WatchOffSet[gPlayerData[playerid][pSkin]][8]
			);
		}
	}
	slot = PHaveItem(playerid, 1, 115);
	if(slot)
	{
		if(SlotParam1(playerid, slot))
		{
			SetPlayerAttachedObject(playerid, MAX_PLAYER_ATTACHED_OBJECTS-4, 19047, 5,
				WatchOffSet[gPlayerData[playerid][pSkin]][0],
				WatchOffSet[gPlayerData[playerid][pSkin]][1],
				WatchOffSet[gPlayerData[playerid][pSkin]][2],
				WatchOffSet[gPlayerData[playerid][pSkin]][3],
				WatchOffSet[gPlayerData[playerid][pSkin]][4],
				WatchOffSet[gPlayerData[playerid][pSkin]][5],
				WatchOffSet[gPlayerData[playerid][pSkin]][6],
				WatchOffSet[gPlayerData[playerid][pSkin]][7],
				WatchOffSet[gPlayerData[playerid][pSkin]][8]
			);
		}
	}
	slot = PHaveItem(playerid, 1, 116);
	if(slot)
	{
		if(SlotParam1(playerid, slot))
		{
			SetPlayerAttachedObject(playerid, MAX_PLAYER_ATTACHED_OBJECTS-4, 19048, 5,
				WatchOffSet[gPlayerData[playerid][pSkin]][0],
				WatchOffSet[gPlayerData[playerid][pSkin]][1],
				WatchOffSet[gPlayerData[playerid][pSkin]][2],
				WatchOffSet[gPlayerData[playerid][pSkin]][3],
				WatchOffSet[gPlayerData[playerid][pSkin]][4],
				WatchOffSet[gPlayerData[playerid][pSkin]][5],
				WatchOffSet[gPlayerData[playerid][pSkin]][6],
				WatchOffSet[gPlayerData[playerid][pSkin]][7],
				WatchOffSet[gPlayerData[playerid][pSkin]][8]
			);
		}
	}
	slot = PHaveItem(playerid, 1, 117);
	if(slot)
	{
		if(SlotParam1(playerid, slot))
		{
			SetPlayerAttachedObject(playerid, MAX_PLAYER_ATTACHED_OBJECTS-4, 19049, 5,
				WatchOffSet[gPlayerData[playerid][pSkin]][0],
				WatchOffSet[gPlayerData[playerid][pSkin]][1],
				WatchOffSet[gPlayerData[playerid][pSkin]][2],
				WatchOffSet[gPlayerData[playerid][pSkin]][3],
				WatchOffSet[gPlayerData[playerid][pSkin]][4],
				WatchOffSet[gPlayerData[playerid][pSkin]][5],
				WatchOffSet[gPlayerData[playerid][pSkin]][6],
				WatchOffSet[gPlayerData[playerid][pSkin]][7],
				WatchOffSet[gPlayerData[playerid][pSkin]][8]
			);
		}
	}
	slot = PHaveItem(playerid, 1, 118);
	if(slot)
	{
		if(SlotParam1(playerid, slot))
		{
			SetPlayerAttachedObject(playerid, MAX_PLAYER_ATTACHED_OBJECTS-4, 19050, 5,
				WatchOffSet[gPlayerData[playerid][pSkin]][0],
				WatchOffSet[gPlayerData[playerid][pSkin]][1],
				WatchOffSet[gPlayerData[playerid][pSkin]][2],
				WatchOffSet[gPlayerData[playerid][pSkin]][3],
				WatchOffSet[gPlayerData[playerid][pSkin]][4],
				WatchOffSet[gPlayerData[playerid][pSkin]][5],
				WatchOffSet[gPlayerData[playerid][pSkin]][6],
				WatchOffSet[gPlayerData[playerid][pSkin]][7],
				WatchOffSet[gPlayerData[playerid][pSkin]][8]
			);
		}
	}
	slot = PHaveItem(playerid, 1, 119);
	if(slot)
	{
		if(SlotParam1(playerid, slot))
		{
			SetPlayerAttachedObject(playerid, MAX_PLAYER_ATTACHED_OBJECTS-4, 19051, 5,
				WatchOffSet[gPlayerData[playerid][pSkin]][0],
				WatchOffSet[gPlayerData[playerid][pSkin]][1],
				WatchOffSet[gPlayerData[playerid][pSkin]][2],
				WatchOffSet[gPlayerData[playerid][pSkin]][3],
				WatchOffSet[gPlayerData[playerid][pSkin]][4],
				WatchOffSet[gPlayerData[playerid][pSkin]][5],
				WatchOffSet[gPlayerData[playerid][pSkin]][6],
				WatchOffSet[gPlayerData[playerid][pSkin]][7],
				WatchOffSet[gPlayerData[playerid][pSkin]][8]
			);
		}
	}
	slot = PHaveItem(playerid, 1, 120);
	if(slot)
	{
		if(SlotParam1(playerid, slot))
		{
			SetPlayerAttachedObject(playerid, MAX_PLAYER_ATTACHED_OBJECTS-4, 19052, 5,
				WatchOffSet[gPlayerData[playerid][pSkin]][0],
				WatchOffSet[gPlayerData[playerid][pSkin]][1],
				WatchOffSet[gPlayerData[playerid][pSkin]][2],
				WatchOffSet[gPlayerData[playerid][pSkin]][3],
				WatchOffSet[gPlayerData[playerid][pSkin]][4],
				WatchOffSet[gPlayerData[playerid][pSkin]][5],
				WatchOffSet[gPlayerData[playerid][pSkin]][6],
				WatchOffSet[gPlayerData[playerid][pSkin]][7],
				WatchOffSet[gPlayerData[playerid][pSkin]][8]
			);
		}
	}
	slot = PHaveItem(playerid, 1, 121);
	if(slot)
	{
		if(SlotParam1(playerid, slot))
		{
			SetPlayerAttachedObject(playerid, MAX_PLAYER_ATTACHED_OBJECTS-4, 19053, 5,
				WatchOffSet[gPlayerData[playerid][pSkin]][0],
				WatchOffSet[gPlayerData[playerid][pSkin]][1],
				WatchOffSet[gPlayerData[playerid][pSkin]][2],
				WatchOffSet[gPlayerData[playerid][pSkin]][3],
				WatchOffSet[gPlayerData[playerid][pSkin]][4],
				WatchOffSet[gPlayerData[playerid][pSkin]][5],
				WatchOffSet[gPlayerData[playerid][pSkin]][6],
				WatchOffSet[gPlayerData[playerid][pSkin]][7],
				WatchOffSet[gPlayerData[playerid][pSkin]][8]
			);
		}
	}
}

stock ActivatePlayerItem(playerid, itemtype, itemid)
{
	if(itemtype == 1 && itemid == 105)
		ShowPlayerMapIcons(playerid, 0);
	else if(itemtype == 1 && itemid == 5)
	{
		SetPlayerAttachedObject(playerid, MAX_PLAYER_ATTACHED_OBJECTS-3, 371, 1,
			BackPackOffSet[gPlayerData[playerid][pSkin]][0],
			BackPackOffSet[gPlayerData[playerid][pSkin]][1],
			BackPackOffSet[gPlayerData[playerid][pSkin]][2],
			BackPackOffSet[gPlayerData[playerid][pSkin]][3],
			BackPackOffSet[gPlayerData[playerid][pSkin]][4],
			BackPackOffSet[gPlayerData[playerid][pSkin]][5],
			BackPackOffSet[gPlayerData[playerid][pSkin]][6],
			BackPackOffSet[gPlayerData[playerid][pSkin]][7],
			BackPackOffSet[gPlayerData[playerid][pSkin]][8]
		);
	}
}

stock InsertPlayerItem(playerid, itemidtype, itemid, itemidparam, itemidparam2)
{
	ActivatePlayerItem(playerid, itemidtype, itemid);	
	if(gPlayerData[playerid][pItem1type] == 0)
	{
		gPlayerData[playerid][pItem1] = itemid;
		gPlayerData[playerid][pItem1type] = itemidtype;
		gPlayerData[playerid][pItem1param] = itemidparam;
		gPlayerData[playerid][pItem1param2] = itemidparam2;
		gPlayerData[playerid][pItem1param6] = 1;

		SavePlayerData(playerid, "Item1a");

		return 1;
	}
	if(gPlayerData[playerid][pItem2type] == 0)
	{
		gPlayerData[playerid][pItem2] = itemid;
		gPlayerData[playerid][pItem2type] = itemidtype;
		gPlayerData[playerid][pItem2param] = itemidparam;
		gPlayerData[playerid][pItem2param2] = itemidparam2;
		gPlayerData[playerid][pItem2param6] = 1;

		SavePlayerData(playerid, "Item2a");

		return 2;
	}
	if(gPlayerData[playerid][pItem3type] == 0)
	{
		gPlayerData[playerid][pItem3] = itemid;
		gPlayerData[playerid][pItem3type] = itemidtype;
		gPlayerData[playerid][pItem3param] = itemidparam;
		gPlayerData[playerid][pItem3param2] = itemidparam2;
		gPlayerData[playerid][pItem3param6] = 1;

		SavePlayerData(playerid, "Item3a");

		return 3;
	}
	if(gPlayerData[playerid][pItem4type] == 0)
	{
		gPlayerData[playerid][pItem4] = itemid;
		gPlayerData[playerid][pItem4type] = itemidtype;
		gPlayerData[playerid][pItem4param] = itemidparam;
		gPlayerData[playerid][pItem4param2] = itemidparam2;
		gPlayerData[playerid][pItem4param6] = 1;

		SavePlayerData(playerid, "Item4a");

		return 4;
	}
	if(gPlayerData[playerid][pItem5type] == 0)
	{
		gPlayerData[playerid][pItem5] = itemid;
		gPlayerData[playerid][pItem5type] = itemidtype;
		gPlayerData[playerid][pItem5param] = itemidparam;
		gPlayerData[playerid][pItem5param2] = itemidparam2;
		gPlayerData[playerid][pItem5param6] = 1;

		SavePlayerData(playerid, "Item5a");

		return 5;
	}
	if(PHaveExpandItem(playerid) || gPlayerData[playerid][pVipItem] > 0)
	{
		if(gPlayerData[playerid][pItem6type] == 0)
		{
			gPlayerData[playerid][pItem6] = itemid;
			gPlayerData[playerid][pItem6type] = itemidtype;
			gPlayerData[playerid][pItem6param] = itemidparam;
			gPlayerData[playerid][pItem6param2] = itemidparam2;
			gPlayerData[playerid][pItem6param6] = 1;

			SavePlayerData(playerid, "Item6a");

			return 6;
		}
		if(gPlayerData[playerid][pItem7type] == 0)
		{
			gPlayerData[playerid][pItem7] = itemid;
			gPlayerData[playerid][pItem7type] = itemidtype;
			gPlayerData[playerid][pItem7param] = itemidparam;
			gPlayerData[playerid][pItem7param2] = itemidparam2;
			gPlayerData[playerid][pItem7param6] = 1;

			SavePlayerData(playerid, "Item7a");

			return 7;
		}
		if(gPlayerData[playerid][pItem8type] == 0)
		{
			gPlayerData[playerid][pItem8] = itemid;
			gPlayerData[playerid][pItem8type] = itemidtype;
			gPlayerData[playerid][pItem8param] = itemidparam;
			gPlayerData[playerid][pItem8param2] = itemidparam2;
			gPlayerData[playerid][pItem8param6] = 1;

			SavePlayerData(playerid, "Item8a");

			return 8;
		}
		if(gPlayerData[playerid][pItem9type] == 0)
		{
			gPlayerData[playerid][pItem9] = itemid;
			gPlayerData[playerid][pItem9type] = itemidtype;
			gPlayerData[playerid][pItem9param] = itemidparam;
			gPlayerData[playerid][pItem9param2] = itemidparam2;
			gPlayerData[playerid][pItem9param6] = 1;

			SavePlayerData(playerid, "Item9a");

			return 9;
		}
		if(gPlayerData[playerid][pItem10type] == 0)
		{
			gPlayerData[playerid][pItem10] = itemid;
			gPlayerData[playerid][pItem10type] = itemidtype;
			gPlayerData[playerid][pItem10param] = itemidparam;
			gPlayerData[playerid][pItem10param2] = itemidparam2;
			gPlayerData[playerid][pItem10param6] = 1;

			SavePlayerData(playerid, "Item10a");

			return 10;
		}
		if(gPlayerData[playerid][pItem11type] == 0)
		{
			gPlayerData[playerid][pItem11] = itemid;
			gPlayerData[playerid][pItem11type] = itemidtype;
			gPlayerData[playerid][pItem11param] = itemidparam;
			gPlayerData[playerid][pItem11param2] = itemidparam2;
			gPlayerData[playerid][pItem11param6] = 1;

			SavePlayerData(playerid, "Item11a");

			return 11;
		}
		if(gPlayerData[playerid][pItem12type] == 0)
		{
			gPlayerData[playerid][pItem12] = itemid;
			gPlayerData[playerid][pItem12type] = itemidtype;
			gPlayerData[playerid][pItem12param] = itemidparam;
			gPlayerData[playerid][pItem12param2] = itemidparam2;
			gPlayerData[playerid][pItem12param6] = 1;

			SavePlayerData(playerid, "Item12a");

			return 12;
		}
		if(gPlayerData[playerid][pItem13type] == 0)
		{
			gPlayerData[playerid][pItem13] = itemid;
			gPlayerData[playerid][pItem13type] = itemidtype;
			gPlayerData[playerid][pItem13param] = itemidparam;
			gPlayerData[playerid][pItem13param2] = itemidparam2;
			gPlayerData[playerid][pItem13param6] = 1;

			SavePlayerData(playerid, "Item13a");

			return 13;
		}
		if(gPlayerData[playerid][pItem14type] == 0)
		{
			gPlayerData[playerid][pItem14] = itemid;
			gPlayerData[playerid][pItem14type] = itemidtype;
			gPlayerData[playerid][pItem14param] = itemidparam;
			gPlayerData[playerid][pItem14param2] = itemidparam2;
			gPlayerData[playerid][pItem14param6] = 1;

			SavePlayerData(playerid, "Item14a");

			return 14;
		}
		if(gPlayerData[playerid][pItem15type] == 0)
		{
			gPlayerData[playerid][pItem15] = itemid;
			gPlayerData[playerid][pItem15type] = itemidtype;
			gPlayerData[playerid][pItem15param] = itemidparam;
			gPlayerData[playerid][pItem15param2] = itemidparam2;
			gPlayerData[playerid][pItem15param6] = 1;

			SavePlayerData(playerid, "Item15a");

			return 15;
		}
		if(gPlayerData[playerid][pVipItem] > 0)
		{
			if(gPlayerData[playerid][pItem16type] == 0)
			{
				gPlayerData[playerid][pItem16] = itemid;
				gPlayerData[playerid][pItem16type] = itemidtype;
				gPlayerData[playerid][pItem16param] = itemidparam;
				gPlayerData[playerid][pItem16param2] = itemidparam2;
				gPlayerData[playerid][pItem16param6] = 1;

				SavePlayerData(playerid, "Item16a");

				return 16;
			}
			if(gPlayerData[playerid][pItem17type] == 0)
			{
				gPlayerData[playerid][pItem17] = itemid;
				gPlayerData[playerid][pItem17type] = itemidtype;
				gPlayerData[playerid][pItem17param] = itemidparam;
				gPlayerData[playerid][pItem17param2] = itemidparam2;
				gPlayerData[playerid][pItem17param6] = 1;

				SavePlayerData(playerid, "Item17a");

				return 17;
			}
			if(gPlayerData[playerid][pItem18type] == 0)
			{
				gPlayerData[playerid][pItem18] = itemid;
				gPlayerData[playerid][pItem18type] = itemidtype;
				gPlayerData[playerid][pItem18param] = itemidparam;
				gPlayerData[playerid][pItem18param2] = itemidparam2;
				gPlayerData[playerid][pItem18param6] = 1;

				SavePlayerData(playerid, "Item18a");

				return 18;
			}
			if(gPlayerData[playerid][pItem19type] == 0)
			{
				gPlayerData[playerid][pItem19] = itemid;
				gPlayerData[playerid][pItem19type] = itemidtype;
				gPlayerData[playerid][pItem19param] = itemidparam;
				gPlayerData[playerid][pItem19param2] = itemidparam2;
				gPlayerData[playerid][pItem19param6] = 1;

				SavePlayerData(playerid, "Item19a");

				return 19;
			}
			if(gPlayerData[playerid][pItem20type] == 0)
			{
				gPlayerData[playerid][pItem20] = itemid;
				gPlayerData[playerid][pItem20type] = itemidtype;
				gPlayerData[playerid][pItem20param] = itemidparam;
				gPlayerData[playerid][pItem20param2] = itemidparam2;
				gPlayerData[playerid][pItem20param6] = 1;

				SavePlayerData(playerid, "Item20a");

				return 20;
			}
			if(gPlayerData[playerid][pItem21type] == 0)
			{
				gPlayerData[playerid][pItem21] = itemid;
				gPlayerData[playerid][pItem21type] = itemidtype;
				gPlayerData[playerid][pItem21param] = itemidparam;
				gPlayerData[playerid][pItem21param2] = itemidparam2;
				gPlayerData[playerid][pItem21param6] = 1;

				SavePlayerData(playerid, "Item21a");

				return 21;
			}
			if(gPlayerData[playerid][pItem22type] == 0)
			{
				gPlayerData[playerid][pItem22] = itemid;
				gPlayerData[playerid][pItem22type] = itemidtype;
				gPlayerData[playerid][pItem22param] = itemidparam;
				gPlayerData[playerid][pItem22param2] = itemidparam2;
				gPlayerData[playerid][pItem22param6] = 1;

				SavePlayerData(playerid, "Item22a");

				return 22;
			}
			if(gPlayerData[playerid][pItem23type] == 0)
			{
				gPlayerData[playerid][pItem23] = itemid;
				gPlayerData[playerid][pItem23type] = itemidtype;
				gPlayerData[playerid][pItem23param] = itemidparam;
				gPlayerData[playerid][pItem23param2] = itemidparam2;
				gPlayerData[playerid][pItem23param6] = 1;

				SavePlayerData(playerid, "Item23a");

				return 23;
			}
			if(gPlayerData[playerid][pItem24type] == 0)
			{
				gPlayerData[playerid][pItem24] = itemid;
				gPlayerData[playerid][pItem24type] = itemidtype;
				gPlayerData[playerid][pItem24param] = itemidparam;
				gPlayerData[playerid][pItem24param2] = itemidparam2;
				gPlayerData[playerid][pItem24param6] = 1;

				SavePlayerData(playerid, "Item24a");

				return 24;
			}
			if(gPlayerData[playerid][pItem25type] == 0)
			{
				gPlayerData[playerid][pItem25] = itemid;
				gPlayerData[playerid][pItem25type] = itemidtype;
				gPlayerData[playerid][pItem25param] = itemidparam;
				gPlayerData[playerid][pItem25param2] = itemidparam2;
				gPlayerData[playerid][pItem25param6] = 1;

				SavePlayerData(playerid, "Item25a");

				return 25;
			}
		}
	}
	return 0;
}

stock InsertPlayerItemEx(playerid, itemidtype, itemid, itemidparam, itemidparam2, itemidparam3 = 0, itemidparam4 = 0, itemidparam5[] = "Puste", itemidparam6 = 1, checkWeight = 0 )
{
	new slot, oldSlot = 0, lastSucceedSlot = 0;
	if(itemidtype == 1)
	{
		// TODO: move ShowPlayerMapIcons to place when the item is already given
		if(itemid == 105)
			ShowPlayerMapIcons( playerid, 0);
		if(itemid == 5)
		{
			SetPlayerAttachedObject(playerid, MAX_PLAYER_ATTACHED_OBJECTS-3, 371, 1,
				BackPackOffSet[gPlayerData[playerid][pSkin]][0],
				BackPackOffSet[gPlayerData[playerid][pSkin]][1],
				BackPackOffSet[gPlayerData[playerid][pSkin]][2],
				BackPackOffSet[gPlayerData[playerid][pSkin]][3],
				BackPackOffSet[gPlayerData[playerid][pSkin]][4],
				BackPackOffSet[gPlayerData[playerid][pSkin]][5],
				BackPackOffSet[gPlayerData[playerid][pSkin]][6],
				BackPackOffSet[gPlayerData[playerid][pSkin]][7],
				BackPackOffSet[gPlayerData[playerid][pSkin]][8]
			);
		}
		while(itemidparam6 > 0 && oldSlot < 25)
		{
			slot = PHaveItem(playerid, itemidtype, itemid, oldSlot+1);
			if(slot > 0)
			{
				lastSucceedSlot = oldSlot = slot;
				if(ItemsOnCharacterSlot(itemidtype, itemid) - itemidparam6 - SlotParam6(playerid, slot) < 0)
				{
					itemidparam6 -= ItemsOnCharacterSlot(itemidtype, itemid) - SlotParam6(playerid, slot);
					SetPSlotParam6(playerid, slot, ItemsOnCharacterSlot(itemidtype, itemid));
				}
				else
				{
					SetPSlotParam6(playerid, slot, SlotParam6(playerid, slot) + itemidparam6);
					return slot;
				}
			}
			else 
				oldSlot++;
		}
		if(itemidparam6 > 0 && PlayerFreeSlotCount(playerid) == 0)
			return lastSucceedSlot;
	}
	if(checkWeight)
	{
		if(PItemWeight(playerid) + ItemWeight(itemidtype, itemid) > gPlayerData[playerid][pMaxWeight])
			return -1;
	}
	slot = 0;
	lastSucceedSlot = 0;
	while(itemidparam6 > 0 && slot < 25)
	{
		slot++;
		if(gPlayerData[playerid][pItem1type] == 0 && slot == 1)
		{
			gPlayerData[playerid][pItem1] = itemid;
			gPlayerData[playerid][pItem1type] = itemidtype;
			gPlayerData[playerid][pItem1param] = itemidparam;
			gPlayerData[playerid][pItem1param2] = itemidparam2;
			gPlayerData[playerid][pItem1param3] = itemidparam3;
			gPlayerData[playerid][pItem1param4] = itemidparam4;
			strdel(gPlayerData[playerid][pItem1param5], 0, 64);
			strins(gPlayerData[playerid][pItem1param5], itemidparam5, 0, 64);
			if(ItemsOnCharacterSlot(itemidtype, itemid) - itemidparam6 > 0)
			{
				gPlayerData[playerid][pItem1param6] = itemidparam6;
				itemidparam6 = 0;
			}
			else
			{
				gPlayerData[playerid][pItem1param6] = ItemsOnCharacterSlot(itemidtype, itemid);
				itemidparam6 -= ItemsOnCharacterSlot(itemidtype, itemid);
			}
			SavePlayerData(playerid, "Item1a");
			
			lastSucceedSlot = 1;
		}
		else if(gPlayerData[playerid][pItem2type] == 0 && slot == 2)
		{
			gPlayerData[playerid][pItem2] = itemid;
			gPlayerData[playerid][pItem2type] = itemidtype;
			gPlayerData[playerid][pItem2param] = itemidparam;
			gPlayerData[playerid][pItem2param2] = itemidparam2;
			gPlayerData[playerid][pItem2param3] = itemidparam3;
			gPlayerData[playerid][pItem2param4] = itemidparam4;
			strdel(gPlayerData[playerid][pItem2param5], 0, 64);
			strins(gPlayerData[playerid][pItem2param5], itemidparam5, 0, 64);
			if(ItemsOnCharacterSlot(itemidtype, itemid) - itemidparam6 > 0)
			{
				gPlayerData[playerid][pItem2param6] = itemidparam6;
				itemidparam6 = 0;
			}
			else
			{
				gPlayerData[playerid][pItem2param6] = ItemsOnCharacterSlot(itemidtype, itemid);
				itemidparam6 -= ItemsOnCharacterSlot(itemidtype, itemid);
			}

			SavePlayerData(playerid, "Item2a");

			lastSucceedSlot = 2;
		}
		else if(gPlayerData[playerid][pItem3type] == 0 && slot == 3)
		{
			gPlayerData[playerid][pItem3] = itemid;
			gPlayerData[playerid][pItem3type] = itemidtype;
			gPlayerData[playerid][pItem3param] = itemidparam;
			gPlayerData[playerid][pItem3param2] = itemidparam2;
			gPlayerData[playerid][pItem3param3] = itemidparam3;
			gPlayerData[playerid][pItem3param4] = itemidparam4;
			strdel(gPlayerData[playerid][pItem3param5], 0, 64);
			strins(gPlayerData[playerid][pItem3param5], itemidparam5, 0, 64);
			if(ItemsOnCharacterSlot(itemidtype, itemid) - itemidparam6 > 0)
			{
				gPlayerData[playerid][pItem3param6] = itemidparam6;
				itemidparam6 = 0;
			}
			else
			{
				gPlayerData[playerid][pItem3param6] = ItemsOnCharacterSlot(itemidtype, itemid);
				itemidparam6 -= ItemsOnCharacterSlot(itemidtype, itemid);
			}

			SavePlayerData(playerid, "Item3a");

			lastSucceedSlot = 3;
		}
		else if(gPlayerData[playerid][pItem4type] == 0 && slot == 4)
		{
			gPlayerData[playerid][pItem4] = itemid;
			gPlayerData[playerid][pItem4type] = itemidtype;
			gPlayerData[playerid][pItem4param] = itemidparam;
			gPlayerData[playerid][pItem4param2] = itemidparam2;
			gPlayerData[playerid][pItem4param3] = itemidparam3;
			gPlayerData[playerid][pItem4param4] = itemidparam4;
			strdel(gPlayerData[playerid][pItem4param5], 0, 64);
			strins(gPlayerData[playerid][pItem4param5], itemidparam5, 0, 64);
			if(ItemsOnCharacterSlot(itemidtype, itemid) - itemidparam6 > 0)
			{
				gPlayerData[playerid][pItem4param6] = itemidparam6;
				itemidparam6 = 0;
			}
			else
			{
				gPlayerData[playerid][pItem4param6] = ItemsOnCharacterSlot(itemidtype, itemid);
				itemidparam6 -= ItemsOnCharacterSlot(itemidtype, itemid);
			}

			SavePlayerData(playerid, "Item4a");

			lastSucceedSlot = 4;
		}
		else if(gPlayerData[playerid][pItem5type] == 0 && slot == 5)
		{
			gPlayerData[playerid][pItem5] = itemid;
			gPlayerData[playerid][pItem5type] = itemidtype;
			gPlayerData[playerid][pItem5param] = itemidparam;
			gPlayerData[playerid][pItem5param2] = itemidparam2;
			gPlayerData[playerid][pItem5param3] = itemidparam3;
			gPlayerData[playerid][pItem5param4] = itemidparam4;
			strdel(gPlayerData[playerid][pItem5param5], 0, 64);
			strins(gPlayerData[playerid][pItem5param5], itemidparam5, 0, 64);
			if(ItemsOnCharacterSlot(itemidtype, itemid) - itemidparam6 > 0)
			{
				gPlayerData[playerid][pItem5param6] = itemidparam6;
				itemidparam6 = 0;
			}
			else
			{
				gPlayerData[playerid][pItem5param6] = ItemsOnCharacterSlot(itemidtype, itemid);
				itemidparam6 -= ItemsOnCharacterSlot(itemidtype, itemid);
			}

			SavePlayerData(playerid, "Item5a");

			lastSucceedSlot = 5;
		}
		if(PHaveExpandItem(playerid) || gPlayerData[playerid][pVipItem] > 0)
		{
			if(gPlayerData[playerid][pItem6type] == 0 && slot == 6)
			{
				gPlayerData[playerid][pItem6] = itemid;
				gPlayerData[playerid][pItem6type] = itemidtype;
				gPlayerData[playerid][pItem6param] = itemidparam;
				gPlayerData[playerid][pItem6param2] = itemidparam2;
				gPlayerData[playerid][pItem6param3] = itemidparam3;
				gPlayerData[playerid][pItem6param4] = itemidparam4;
				strdel(gPlayerData[playerid][pItem6param5], 0, 64);
				strins(gPlayerData[playerid][pItem6param5], itemidparam5, 0, 64);
				if(ItemsOnCharacterSlot(itemidtype, itemid) - itemidparam6 > 0)
				{
					gPlayerData[playerid][pItem6param6] = itemidparam6;
					itemidparam6 = 0;
				}
				else
				{
					gPlayerData[playerid][pItem6param6] = ItemsOnCharacterSlot(itemidtype, itemid);
					itemidparam6 -= ItemsOnCharacterSlot(itemidtype, itemid);
				}

				SavePlayerData(playerid, "Item6a");
				
				lastSucceedSlot = 6;
			}
			else if(gPlayerData[playerid][pItem7type] == 0 && slot == 7)
			{
				gPlayerData[playerid][pItem7] = itemid;
				gPlayerData[playerid][pItem7type] = itemidtype;
				gPlayerData[playerid][pItem7param] = itemidparam;
				gPlayerData[playerid][pItem7param2] = itemidparam2;
				gPlayerData[playerid][pItem7param3] = itemidparam3;
				gPlayerData[playerid][pItem7param4] = itemidparam4;
				strdel(gPlayerData[playerid][pItem7param5], 0, 64);
				strins(gPlayerData[playerid][pItem7param5], itemidparam5, 0, 64);
				if(ItemsOnCharacterSlot(itemidtype, itemid) - itemidparam6 > 0)
				{
					gPlayerData[playerid][pItem7param6] = itemidparam6;
					itemidparam6 = 0;
				}
				else
				{
					gPlayerData[playerid][pItem7param6] = ItemsOnCharacterSlot(itemidtype, itemid);
					itemidparam6 -= ItemsOnCharacterSlot(itemidtype, itemid);
				}

				SavePlayerData(playerid, "Item7a");

				lastSucceedSlot = 7;
			}
			else if(gPlayerData[playerid][pItem8type] == 0 && slot == 8)
			{
				gPlayerData[playerid][pItem8] = itemid;
				gPlayerData[playerid][pItem8type] = itemidtype;
				gPlayerData[playerid][pItem8param] = itemidparam;
				gPlayerData[playerid][pItem8param2] = itemidparam2;
				gPlayerData[playerid][pItem8param3] = itemidparam3;
				gPlayerData[playerid][pItem8param4] = itemidparam4;
				strdel(gPlayerData[playerid][pItem8param5], 0, 64);
				strins(gPlayerData[playerid][pItem8param5], itemidparam5, 0, 64);
				if(ItemsOnCharacterSlot(itemidtype, itemid) - itemidparam6 > 0)
				{
					gPlayerData[playerid][pItem8param6] = itemidparam6;
					itemidparam6 = 0;
				}
				else
				{
					gPlayerData[playerid][pItem8param6] = ItemsOnCharacterSlot(itemidtype, itemid);
					itemidparam6 -= ItemsOnCharacterSlot(itemidtype, itemid);
				}

				SavePlayerData(playerid, "Item8a");

				lastSucceedSlot = 8;
			}
			else if(gPlayerData[playerid][pItem9type] == 0 && slot == 9)
			{
				gPlayerData[playerid][pItem9] = itemid;
				gPlayerData[playerid][pItem9type] = itemidtype;
				gPlayerData[playerid][pItem9param] = itemidparam;
				gPlayerData[playerid][pItem9param2] = itemidparam2;
				gPlayerData[playerid][pItem9param3] = itemidparam3;
				gPlayerData[playerid][pItem9param4] = itemidparam4;
				strdel(gPlayerData[playerid][pItem9param5], 0, 64);
				strins(gPlayerData[playerid][pItem9param5], itemidparam5, 0, 64);
				if(ItemsOnCharacterSlot(itemidtype, itemid) - itemidparam6 > 0)
				{
					gPlayerData[playerid][pItem9param6] = itemidparam6;
					itemidparam6 = 0;
				}
				else
				{
					gPlayerData[playerid][pItem9param6] = ItemsOnCharacterSlot(itemidtype, itemid);
					itemidparam6 -= ItemsOnCharacterSlot(itemidtype, itemid);
				}

				SavePlayerData(playerid, "Item9a");

				lastSucceedSlot = 9;
			}
			else if(gPlayerData[playerid][pItem10type] == 0 && slot == 10)
			{
				gPlayerData[playerid][pItem10] = itemid;
				gPlayerData[playerid][pItem10type] = itemidtype;
				gPlayerData[playerid][pItem10param] = itemidparam;
				gPlayerData[playerid][pItem10param2] = itemidparam2;
				gPlayerData[playerid][pItem10param3] = itemidparam3;
				gPlayerData[playerid][pItem10param4] = itemidparam4;
				strdel(gPlayerData[playerid][pItem10param5], 0, 64);
				strins(gPlayerData[playerid][pItem10param5], itemidparam5, 0, 64);
				if(ItemsOnCharacterSlot(itemidtype, itemid) - itemidparam6 > 0)
				{
					gPlayerData[playerid][pItem10param6] = itemidparam6;
					itemidparam6 = 0;
				}
				else
				{
					gPlayerData[playerid][pItem10param6] = ItemsOnCharacterSlot(itemidtype, itemid);
					itemidparam6 -= ItemsOnCharacterSlot(itemidtype, itemid);
				}

				SavePlayerData(playerid, "Item10a");

				lastSucceedSlot = 10;
			}
			else if(gPlayerData[playerid][pItem11type] == 0 && slot == 11)
			{
				gPlayerData[playerid][pItem11] = itemid;
				gPlayerData[playerid][pItem11type] = itemidtype;
				gPlayerData[playerid][pItem11param] = itemidparam;
				gPlayerData[playerid][pItem11param2] = itemidparam2;
				gPlayerData[playerid][pItem11param3] = itemidparam3;
				gPlayerData[playerid][pItem11param4] = itemidparam4;
				strdel(gPlayerData[playerid][pItem11param5], 0, 64);
				strins(gPlayerData[playerid][pItem11param5], itemidparam5, 0, 64);
				if(ItemsOnCharacterSlot(itemidtype, itemid) - itemidparam6 > 0)
				{
					gPlayerData[playerid][pItem11param6] = itemidparam6;
					itemidparam6 = 0;
				}
				else
				{
					gPlayerData[playerid][pItem11param6] = ItemsOnCharacterSlot(itemidtype, itemid);
					itemidparam6 -= ItemsOnCharacterSlot(itemidtype, itemid);
				}

				SavePlayerData(playerid, "Item11a");

				lastSucceedSlot = 11;
			}
			else if(gPlayerData[playerid][pItem12type] == 0 && slot == 12)
			{
				gPlayerData[playerid][pItem12] = itemid;
				gPlayerData[playerid][pItem12type] = itemidtype;
				gPlayerData[playerid][pItem12param] = itemidparam;
				gPlayerData[playerid][pItem12param2] = itemidparam2;
				gPlayerData[playerid][pItem12param3] = itemidparam3;
				gPlayerData[playerid][pItem12param4] = itemidparam4;
				strdel(gPlayerData[playerid][pItem12param5], 0, 64);
				strins(gPlayerData[playerid][pItem12param5], itemidparam5, 0, 64);
				if(ItemsOnCharacterSlot(itemidtype, itemid) - itemidparam6 > 0)
				{
					gPlayerData[playerid][pItem12param6] = itemidparam6;
					itemidparam6 = 0;
				}
				else
				{
					gPlayerData[playerid][pItem12param6] = ItemsOnCharacterSlot(itemidtype, itemid);
					itemidparam6 -= ItemsOnCharacterSlot(itemidtype, itemid);
				}

				SavePlayerData(playerid, "Item12a");

				lastSucceedSlot = 12;
			}
			else if(gPlayerData[playerid][pItem13type] == 0 && slot == 13)
			{
				gPlayerData[playerid][pItem13] = itemid;
				gPlayerData[playerid][pItem13type] = itemidtype;
				gPlayerData[playerid][pItem13param] = itemidparam;
				gPlayerData[playerid][pItem13param2] = itemidparam2;
				gPlayerData[playerid][pItem13param3] = itemidparam3;
				gPlayerData[playerid][pItem13param4] = itemidparam4;
				strdel(gPlayerData[playerid][pItem13param5], 0, 64);
				strins(gPlayerData[playerid][pItem13param5], itemidparam5, 0, 64);
				if(ItemsOnCharacterSlot(itemidtype, itemid) - itemidparam6 > 0)
				{
					gPlayerData[playerid][pItem13param6] = itemidparam6;
					itemidparam6 = 0;
				}
				else
				{
					gPlayerData[playerid][pItem13param6] = ItemsOnCharacterSlot(itemidtype, itemid);
					itemidparam6 -= ItemsOnCharacterSlot(itemidtype, itemid);
				}

				SavePlayerData(playerid, "Item13a");

				lastSucceedSlot = 13;
			}
			else if(gPlayerData[playerid][pItem14type] == 0 && slot == 14)
			{
				gPlayerData[playerid][pItem14] = itemid;
				gPlayerData[playerid][pItem14type] = itemidtype;
				gPlayerData[playerid][pItem14param] = itemidparam;
				gPlayerData[playerid][pItem14param2] = itemidparam2;
				gPlayerData[playerid][pItem14param3] = itemidparam3;
				gPlayerData[playerid][pItem14param4] = itemidparam4;
				strdel(gPlayerData[playerid][pItem14param5], 0, 64);
				strins(gPlayerData[playerid][pItem14param5], itemidparam5, 0, 64);
				if(ItemsOnCharacterSlot(itemidtype, itemid) - itemidparam6 > 0)
				{
					gPlayerData[playerid][pItem14param6] = itemidparam6;
					itemidparam6 = 0;
				}
				else
				{
					gPlayerData[playerid][pItem14param6] = ItemsOnCharacterSlot(itemidtype, itemid);
					itemidparam6 -= ItemsOnCharacterSlot(itemidtype, itemid);
				}

				SavePlayerData(playerid, "Item14a");

				lastSucceedSlot = 14;
			}
			else if(gPlayerData[playerid][pItem15type] == 0 && slot == 15)
			{
				gPlayerData[playerid][pItem15] = itemid;
				gPlayerData[playerid][pItem15type] = itemidtype;
				gPlayerData[playerid][pItem15param] = itemidparam;
				gPlayerData[playerid][pItem15param2] = itemidparam2;
				gPlayerData[playerid][pItem15param3] = itemidparam3;
				gPlayerData[playerid][pItem15param4] = itemidparam4;
				strdel(gPlayerData[playerid][pItem15param5], 0, 64);
				strins(gPlayerData[playerid][pItem15param5], itemidparam5, 0, 64);
				if(ItemsOnCharacterSlot(itemidtype, itemid) - itemidparam6 > 0)
				{
					gPlayerData[playerid][pItem15param6] = itemidparam6;
					itemidparam6 = 0;
				}
				else
				{
					gPlayerData[playerid][pItem15param6] = ItemsOnCharacterSlot(itemidtype, itemid);
					itemidparam6 -= ItemsOnCharacterSlot(itemidtype, itemid);
				}

				SavePlayerData(playerid, "Item15a");

				lastSucceedSlot = 15;
			}
			if(gPlayerData[playerid][pVipItem] > 0)
			{
				if(gPlayerData[playerid][pItem16type] == 0 && slot == 16)
				{
					gPlayerData[playerid][pItem16] = itemid;
					gPlayerData[playerid][pItem16type] = itemidtype;
					gPlayerData[playerid][pItem16param] = itemidparam;
					gPlayerData[playerid][pItem16param2] = itemidparam2;
					gPlayerData[playerid][pItem16param3] = itemidparam3;
					gPlayerData[playerid][pItem16param4] = itemidparam4;
					strdel(gPlayerData[playerid][pItem16param5], 0, 64);
					strins(gPlayerData[playerid][pItem16param5], itemidparam5, 0, 64);
					if(ItemsOnCharacterSlot(itemidtype, itemid) - itemidparam6 > 0)
					{
						gPlayerData[playerid][pItem16param6] = itemidparam6;
						itemidparam6 = 0;
					}
					else
					{
						gPlayerData[playerid][pItem16param6] = ItemsOnCharacterSlot(itemidtype, itemid);
						itemidparam6 -= ItemsOnCharacterSlot(itemidtype, itemid);
					}

					SavePlayerData(playerid, "Item16a");

					lastSucceedSlot = 16;
				}
				else if(gPlayerData[playerid][pItem17type] == 0 && slot == 17)
				{
					gPlayerData[playerid][pItem17] = itemid;
					gPlayerData[playerid][pItem17type] = itemidtype;
					gPlayerData[playerid][pItem17param] = itemidparam;
					gPlayerData[playerid][pItem17param2] = itemidparam2;
					gPlayerData[playerid][pItem17param3] = itemidparam3;
					gPlayerData[playerid][pItem17param4] = itemidparam4;
					strdel(gPlayerData[playerid][pItem17param5], 0, 64);
					strins(gPlayerData[playerid][pItem17param5], itemidparam5, 0, 64);
					if(ItemsOnCharacterSlot(itemidtype, itemid) - itemidparam6 > 0)
					{
						gPlayerData[playerid][pItem17param6] = itemidparam6;
						itemidparam6 = 0;
					}
					else
					{
						gPlayerData[playerid][pItem17param6] = ItemsOnCharacterSlot(itemidtype, itemid);
						itemidparam6 -= ItemsOnCharacterSlot(itemidtype, itemid);
					}

					SavePlayerData(playerid, "Item17a");

					lastSucceedSlot = 17;
				}
				else if(gPlayerData[playerid][pItem18type] == 0 && slot == 18)
				{
					gPlayerData[playerid][pItem18] = itemid;
					gPlayerData[playerid][pItem18type] = itemidtype;
					gPlayerData[playerid][pItem18param] = itemidparam;
					gPlayerData[playerid][pItem18param2] = itemidparam2;
					gPlayerData[playerid][pItem18param3] = itemidparam3;
					gPlayerData[playerid][pItem18param4] = itemidparam4;
					strdel(gPlayerData[playerid][pItem18param5], 0, 64);
					strins(gPlayerData[playerid][pItem18param5], itemidparam5, 0, 64);
					if(ItemsOnCharacterSlot(itemidtype, itemid) - itemidparam6 > 0)
					{
						gPlayerData[playerid][pItem18param6] = itemidparam6;
						itemidparam6 = 0;
					}
					else
					{
						gPlayerData[playerid][pItem18param6] = ItemsOnCharacterSlot(itemidtype, itemid);
						itemidparam6 -= ItemsOnCharacterSlot(itemidtype, itemid);
					}

					SavePlayerData(playerid, "Item18a");

					lastSucceedSlot = 18;
				}
				else if(gPlayerData[playerid][pItem19type] == 0 && slot == 19)
				{
					gPlayerData[playerid][pItem19] = itemid;
					gPlayerData[playerid][pItem19type] = itemidtype;
					gPlayerData[playerid][pItem19param] = itemidparam;
					gPlayerData[playerid][pItem19param2] = itemidparam2;
					gPlayerData[playerid][pItem19param3] = itemidparam3;
					gPlayerData[playerid][pItem19param4] = itemidparam4;
					strdel(gPlayerData[playerid][pItem19param5], 0, 64);
					strins(gPlayerData[playerid][pItem19param5], itemidparam5, 0, 64);
					if(ItemsOnCharacterSlot(itemidtype, itemid) - itemidparam6 > 0)
					{
						gPlayerData[playerid][pItem19param6] = itemidparam6;
						itemidparam6 = 0;
					}
					else
					{
						gPlayerData[playerid][pItem19param6] = ItemsOnCharacterSlot(itemidtype, itemid);
						itemidparam6 -= ItemsOnCharacterSlot(itemidtype, itemid);
					}

					SavePlayerData(playerid, "Item19a");

					lastSucceedSlot = 19;
				}
				else if(gPlayerData[playerid][pItem20type] == 0 && slot == 20)
				{
					gPlayerData[playerid][pItem20] = itemid;
					gPlayerData[playerid][pItem20type] = itemidtype;
					gPlayerData[playerid][pItem20param] = itemidparam;
					gPlayerData[playerid][pItem20param2] = itemidparam2;
					gPlayerData[playerid][pItem20param3] = itemidparam3;
					gPlayerData[playerid][pItem20param4] = itemidparam4;
					strdel(gPlayerData[playerid][pItem20param5], 0, 64);
					strins(gPlayerData[playerid][pItem20param5], itemidparam5, 0, 64);
					if(ItemsOnCharacterSlot(itemidtype, itemid) - itemidparam6 > 0)
					{
						gPlayerData[playerid][pItem20param6] = itemidparam6;
						itemidparam6 = 0;
					}
					else
					{
						gPlayerData[playerid][pItem20param6] = ItemsOnCharacterSlot(itemidtype, itemid);
						itemidparam6 -= ItemsOnCharacterSlot(itemidtype, itemid);
					}

					SavePlayerData(playerid, "Item20a");

					lastSucceedSlot = 20;
				}
				else if(gPlayerData[playerid][pItem21type] == 0 && slot == 21)
				{
					gPlayerData[playerid][pItem21] = itemid;
					gPlayerData[playerid][pItem21type] = itemidtype;
					gPlayerData[playerid][pItem21param] = itemidparam;
					gPlayerData[playerid][pItem21param2] = itemidparam2;
					gPlayerData[playerid][pItem21param3] = itemidparam3;
					gPlayerData[playerid][pItem21param4] = itemidparam4;
					strdel(gPlayerData[playerid][pItem21param5], 0, 64);
					strins(gPlayerData[playerid][pItem21param5], itemidparam5, 0, 64);
					if(ItemsOnCharacterSlot(itemidtype, itemid) - itemidparam6 > 0)
					{
						gPlayerData[playerid][pItem21param6] = itemidparam6;
						itemidparam6 = 0;
					}
					else
					{
						gPlayerData[playerid][pItem21param6] = ItemsOnCharacterSlot(itemidtype, itemid);
						itemidparam6 -= ItemsOnCharacterSlot(itemidtype, itemid);
					}

					SavePlayerData(playerid, "Item21a");

					lastSucceedSlot = 21;
				}
				else if(gPlayerData[playerid][pItem22type] == 0 && slot == 22)
				{
					gPlayerData[playerid][pItem22] = itemid;
					gPlayerData[playerid][pItem22type] = itemidtype;
					gPlayerData[playerid][pItem22param] = itemidparam;
					gPlayerData[playerid][pItem22param2] = itemidparam2;
					gPlayerData[playerid][pItem22param3] = itemidparam3;
					gPlayerData[playerid][pItem22param4] = itemidparam4;
					strdel(gPlayerData[playerid][pItem22param5], 0, 64);
					strins(gPlayerData[playerid][pItem22param5], itemidparam5, 0, 64);
					if(ItemsOnCharacterSlot(itemidtype, itemid) - itemidparam6 > 0)
					{
						gPlayerData[playerid][pItem22param6] = itemidparam6;
						itemidparam6 = 0;
					}
					else
					{
						gPlayerData[playerid][pItem22param6] = ItemsOnCharacterSlot(itemidtype, itemid);
						itemidparam6 -= ItemsOnCharacterSlot(itemidtype, itemid);
					}

					SavePlayerData(playerid, "Item22a");

					lastSucceedSlot = 22;
				}
				else if(gPlayerData[playerid][pItem23type] == 0 && slot == 23)
				{
					gPlayerData[playerid][pItem23] = itemid;
					gPlayerData[playerid][pItem23type] = itemidtype;
					gPlayerData[playerid][pItem23param] = itemidparam;
					gPlayerData[playerid][pItem23param2] = itemidparam2;
					gPlayerData[playerid][pItem23param3] = itemidparam3;
					gPlayerData[playerid][pItem23param4] = itemidparam4;
					strdel(gPlayerData[playerid][pItem23param5], 0, 64);
					strins(gPlayerData[playerid][pItem23param5], itemidparam5, 0, 64);
					if(ItemsOnCharacterSlot(itemidtype, itemid) - itemidparam6 > 0)
					{
						gPlayerData[playerid][pItem23param6] = itemidparam6;
						itemidparam6 = 0;
					}
					else
					{
						gPlayerData[playerid][pItem23param6] = ItemsOnCharacterSlot(itemidtype, itemid);
						itemidparam6 -= ItemsOnCharacterSlot(itemidtype, itemid);
					}

					SavePlayerData(playerid, "Item23a");

					lastSucceedSlot = 23;
				}
				else if(gPlayerData[playerid][pItem24type] == 0 && slot == 24)
				{
					gPlayerData[playerid][pItem24] = itemid;
					gPlayerData[playerid][pItem24type] = itemidtype;
					gPlayerData[playerid][pItem24param] = itemidparam;
					gPlayerData[playerid][pItem24param2] = itemidparam2;
					gPlayerData[playerid][pItem24param3] = itemidparam3;
					gPlayerData[playerid][pItem24param4] = itemidparam4;
					strdel(gPlayerData[playerid][pItem24param5], 0, 64);
					strins(gPlayerData[playerid][pItem24param5], itemidparam5, 0, 64);
					if(ItemsOnCharacterSlot(itemidtype, itemid) - itemidparam6 > 0)
					{
						gPlayerData[playerid][pItem24param6] = itemidparam6;
						itemidparam6 = 0;
					}
					else
					{
						gPlayerData[playerid][pItem24param6] = ItemsOnCharacterSlot(itemidtype, itemid);
						itemidparam6 -= ItemsOnCharacterSlot(itemidtype, itemid);
					}

					SavePlayerData(playerid, "Item24a");

					lastSucceedSlot = 24;
				}
				else if(gPlayerData[playerid][pItem25type] == 0 && slot == 25)
				{
					gPlayerData[playerid][pItem25] = itemid;
					gPlayerData[playerid][pItem25type] = itemidtype;
					gPlayerData[playerid][pItem25param] = itemidparam;
					gPlayerData[playerid][pItem25param2] = itemidparam2;
					gPlayerData[playerid][pItem25param3] = itemidparam3;
					gPlayerData[playerid][pItem25param4] = itemidparam4;
					strdel(gPlayerData[playerid][pItem25param5], 0, 64);
					strins(gPlayerData[playerid][pItem25param5], itemidparam5, 0, 64);
					if(ItemsOnCharacterSlot(itemidtype, itemid) - itemidparam6 > 0)
					{
						gPlayerData[playerid][pItem25param6] = itemidparam6;
						itemidparam6 = 0;
					}
					else
					{
						gPlayerData[playerid][pItem25param6] = ItemsOnCharacterSlot(itemidtype, itemid);
						itemidparam6 -= ItemsOnCharacterSlot(itemidtype, itemid);
					}

					SavePlayerData(playerid, "Item25a");

					lastSucceedSlot = 25;
				}
			}
		}
	}
	return lastSucceedSlot;
}

stock SetPSlotParam1(playerid, slot, value)
{
	if(slot == 1)
	{
		gPlayerData[playerid][pItem1param] = value;
		SavePlayerData(playerid, "Item1param");
		return 1;
	}
	if(slot == 2)
	{
		gPlayerData[playerid][pItem2param] = value;
		SavePlayerData(playerid, "Item2param");
		return 1;
	}
	if(slot == 3)
	{
		gPlayerData[playerid][pItem3param] = value;
		SavePlayerData(playerid, "Item3param");
		return 1;
	}
	if(slot == 4)
	{
		gPlayerData[playerid][pItem4param] = value;
		SavePlayerData(playerid, "Item4param");
		return 1;
	}
	if(slot == 5)
	{
		gPlayerData[playerid][pItem5param] = value;
		SavePlayerData(playerid, "Item5param");
		return 1;
	}
	if(PHaveExpandItem(playerid) || gPlayerData[playerid][pVipItem] > 0)
	{
		if(slot == 6)
		{
			gPlayerData[playerid][pItem6param] = value;
			SavePlayerData(playerid, "Item6param");
			return 1;
		}
		if(slot == 7)
		{
			gPlayerData[playerid][pItem7param] = value;
			SavePlayerData(playerid, "Item7param");
			return 1;
		}
		if(slot == 8)
		{
			gPlayerData[playerid][pItem8param] = value;
			SavePlayerData(playerid, "Item8param");
			return 1;
		}
		if(slot == 9)
		{
			gPlayerData[playerid][pItem9param] = value;
			SavePlayerData(playerid, "Item9param");
			return 1;
		}
		if(slot == 10)
		{
			gPlayerData[playerid][pItem10param] = value;
			SavePlayerData(playerid, "Item10param");
			return 1;
		}
		if(slot == 11)
		{
			gPlayerData[playerid][pItem11param] = value;
			SavePlayerData(playerid, "Item11param");
			return 1;
		}
		if(slot == 12)
		{
			gPlayerData[playerid][pItem12param] = value;
			SavePlayerData(playerid, "Item12param");
			return 1;
		}
		if(slot == 13)
		{
			gPlayerData[playerid][pItem13param] = value;
			SavePlayerData(playerid, "Item13param");
			return 1;
		}
		if(slot == 14)
		{
			gPlayerData[playerid][pItem14param] = value;
			SavePlayerData(playerid, "Item14param");
			return 1;
		}
		if(slot == 15)
		{
			gPlayerData[playerid][pItem15param] = value;
			SavePlayerData(playerid, "Item15param");
			return 1;
		}
		if(gPlayerData[playerid][pVipItem] > 0)
		{
			if(slot == 16)
			{
				gPlayerData[playerid][pItem16param] = value;
				SavePlayerData(playerid, "Item16param");
				return 1;
			}
			if(slot == 17)
			{
				gPlayerData[playerid][pItem17param] = value;
				SavePlayerData(playerid, "Item17param");
				return 1;
			}
			if(slot == 18)
			{
				gPlayerData[playerid][pItem18param] = value;
				SavePlayerData(playerid, "Item18param");
				return 1;
			}
			if(slot == 19)
			{
				gPlayerData[playerid][pItem19param] = value;
				SavePlayerData(playerid, "Item19param");
				return 1;
			}
			if(slot == 20)
			{
				gPlayerData[playerid][pItem20param] = value;
				SavePlayerData(playerid, "Item20param");
				return 1;
			}
			if(slot == 21)
			{
				gPlayerData[playerid][pItem21param] = value;
				SavePlayerData(playerid, "Item21param");
				return 1;
			}
			if(slot == 22)
			{
				gPlayerData[playerid][pItem22param] = value;
				SavePlayerData(playerid, "Item22param");
				return 1;
			}
			if(slot == 23)
			{
				gPlayerData[playerid][pItem23param] = value;
				SavePlayerData(playerid, "Item23param");
				return 1;
			}
			if(slot == 24)
			{
				gPlayerData[playerid][pItem24param] = value;
				SavePlayerData(playerid, "Item24param");
				return 1;
			}
			if(slot == 25)
			{
				gPlayerData[playerid][pItem25param] = value;
				SavePlayerData(playerid, "Item25param");
				return 1;
			}
		}
	}
	return 0;
}

stock SetPSlotParam2(playerid, slot, value)
{
	if(slot == 1)
	{
		gPlayerData[playerid][pItem1param2] = value;
		SavePlayerData(playerid, "Item1param2");
		return 1;
	}
	if(slot == 2)
	{
		gPlayerData[playerid][pItem2param2] = value;
		SavePlayerData(playerid, "Item2param2");
		return 1;
	}
	if(slot == 3)
	{
		gPlayerData[playerid][pItem3param2] = value;
		SavePlayerData(playerid, "Item3param2");
		return 1;
	}
	if(slot == 4)
	{
		gPlayerData[playerid][pItem4param2] = value;
		SavePlayerData(playerid, "Item4param2");
		return 1;
	}
	if(slot == 5)
	{
		gPlayerData[playerid][pItem5param2] = value;
		SavePlayerData(playerid, "Item5param2");
		return 1;
	}
	if(PHaveExpandItem(playerid) || gPlayerData[playerid][pVipItem] > 0)
	{
		if(slot == 6)
		{
			gPlayerData[playerid][pItem6param2] = value;
			SavePlayerData(playerid, "Item6param2");
			return 1;
		}
		if(slot == 7)
		{
			gPlayerData[playerid][pItem7param2] = value;
			SavePlayerData(playerid, "Item7param2");
			return 1;
		}
		if(slot == 8)
		{
			gPlayerData[playerid][pItem8param2] = value;
			SavePlayerData(playerid, "Item8param2");
			return 1;
		}
		if(slot == 9)
		{
			gPlayerData[playerid][pItem9param2] = value;
			SavePlayerData(playerid, "Item9param2");
			return 1;
		}
		if(slot == 10)
		{
			gPlayerData[playerid][pItem10param2] = value;
			SavePlayerData(playerid, "Item10param2");
			return 1;
		}
		if(slot == 11)
		{
			gPlayerData[playerid][pItem11param2] = value;
			SavePlayerData(playerid, "Item11param2");
			return 1;
		}
		if(slot == 12)
		{
			gPlayerData[playerid][pItem12param2] = value;
			SavePlayerData(playerid, "Item12param2");
			return 1;
		}
		if(slot == 13)
		{
			gPlayerData[playerid][pItem13param2] = value;
			SavePlayerData(playerid, "Item13param2");
			return 1;
		}
		if(slot == 14)
		{
			gPlayerData[playerid][pItem14param2] = value;
			SavePlayerData(playerid, "Item14param2");
			return 1;
		}
		if(slot == 15)
		{
			gPlayerData[playerid][pItem15param2] = value;
			SavePlayerData(playerid, "Item15param2");
			return 1;
		}
		if(gPlayerData[playerid][pVipItem] > 0)
		{
			if(slot == 16)
			{
				gPlayerData[playerid][pItem16param2] = value;
				SavePlayerData(playerid, "Item16param2");
				return 1;
			}
			if(slot == 17)
			{
				gPlayerData[playerid][pItem17param2] = value;
				SavePlayerData(playerid, "Item17param2");
				return 1;
			}
			if(slot == 18)
			{
				gPlayerData[playerid][pItem18param2] = value;
				SavePlayerData(playerid, "Item18param2");
				return 1;
			}
			if(slot == 19)
			{
				gPlayerData[playerid][pItem19param2] = value;
				SavePlayerData(playerid, "Item19param2");
				return 1;
			}
			if(slot == 20)
			{
				gPlayerData[playerid][pItem20param2] = value;
				SavePlayerData(playerid, "Item20param2");
				return 1;
			}
			if(slot == 21)
			{
				gPlayerData[playerid][pItem21param2] = value;
				SavePlayerData(playerid, "Item21param2");
				return 1;
			}
			if(slot == 22)
			{
				gPlayerData[playerid][pItem22param2] = value;
				SavePlayerData(playerid, "Item22param2");
				return 1;
			}
			if(slot == 23)
			{
				gPlayerData[playerid][pItem23param2] = value;
				SavePlayerData(playerid, "Item23param2");
				return 1;
			}
			if(slot == 24)
			{
				gPlayerData[playerid][pItem24param2] = value;
				SavePlayerData(playerid, "Item24param2");
				return 1;
			}
			if(slot == 25)
			{
				gPlayerData[playerid][pItem25param2] = value;
				SavePlayerData(playerid, "Item25param2");
				return 1;
			}
		}
	}
	return 0;
}

stock SetPSlotParam3(playerid, slot, value)
{
	if(slot == 1)
	{
		gPlayerData[playerid][pItem1param3] = value;
		SavePlayerData(playerid, "Item1param3");
		return 1;
	}
	if(slot == 2)
	{
		gPlayerData[playerid][pItem2param3] = value;
		SavePlayerData(playerid, "Item2param3");
		return 1;
	}
	if(slot == 3)
	{
		gPlayerData[playerid][pItem3param3] = value;
		SavePlayerData(playerid, "Item3param3");
		return 1;
	}
	if(slot == 4)
	{
		gPlayerData[playerid][pItem4param3] = value;
		SavePlayerData(playerid, "Item4param3");
		return 1;
	}
	if(slot == 5)
	{
		gPlayerData[playerid][pItem5param3] = value;
		SavePlayerData(playerid, "Item5param3");
		return 1;
	}
	if(PHaveExpandItem(playerid) || gPlayerData[playerid][pVipItem] > 0)
	{
		if(slot == 6)
		{
			gPlayerData[playerid][pItem6param3] = value;
			SavePlayerData(playerid, "Item6param3");
			return 1;
		}
		if(slot == 7)
		{
			gPlayerData[playerid][pItem7param3] = value;
			SavePlayerData(playerid, "Item7param3");
			return 1;
		}
		if(slot == 8)
		{
			gPlayerData[playerid][pItem8param3] = value;
			SavePlayerData(playerid, "Item8param3");
			return 1;
		}
		if(slot == 9)
		{
			gPlayerData[playerid][pItem9param3] = value;
			SavePlayerData(playerid, "Item9param3");
			return 1;
		}
		if(slot == 10)
		{
			gPlayerData[playerid][pItem10param3] = value;
			SavePlayerData(playerid, "Item10param3");
			return 1;
		}
		if(slot == 11)
		{
			gPlayerData[playerid][pItem11param3] = value;
			SavePlayerData(playerid, "Item11param3");
			return 1;
		}
		if(slot == 12)
		{
			gPlayerData[playerid][pItem12param3] = value;
			SavePlayerData(playerid, "Item12param3");
			return 1;
		}
		if(slot == 13)
		{
			gPlayerData[playerid][pItem13param3] = value;
			SavePlayerData(playerid, "Item13param3");
			return 1;
		}
		if(slot == 14)
		{
			gPlayerData[playerid][pItem14param3] = value;
			SavePlayerData(playerid, "Item14param3");
			return 1;
		}
		if(slot == 15)
		{
			gPlayerData[playerid][pItem15param3] = value;
			SavePlayerData(playerid, "Item15param3");
			return 1;
		}
		if(gPlayerData[playerid][pVipItem] > 0)
		{
			if(slot == 16)
			{
				gPlayerData[playerid][pItem16param3] = value;
				SavePlayerData(playerid, "Item16param3");
				return 1;
			}
			if(slot == 17)
			{
				gPlayerData[playerid][pItem17param3] = value;
				SavePlayerData(playerid, "Item17param3");
				return 1;
			}
			if(slot == 18)
			{
				gPlayerData[playerid][pItem18param3] = value;
				SavePlayerData(playerid, "Item18param3");
				return 1;
			}
			if(slot == 19)
			{
				gPlayerData[playerid][pItem19param3] = value;
				SavePlayerData(playerid, "Item19param3");
				return 1;
			}
			if(slot == 20)
			{
				gPlayerData[playerid][pItem20param3] = value;
				SavePlayerData(playerid, "Item20param3");
				return 1;
			}
			if(slot == 21)
			{
				gPlayerData[playerid][pItem21param3] = value;
				SavePlayerData(playerid, "Item21param3");
				return 1;
			}
			if(slot == 22)
			{
				gPlayerData[playerid][pItem22param3] = value;
				SavePlayerData(playerid, "Item22param3");
				return 1;
			}
			if(slot == 23)
			{
				gPlayerData[playerid][pItem23param3] = value;
				SavePlayerData(playerid, "Item23param3");
				return 1;
			}
			if(slot == 24)
			{
				gPlayerData[playerid][pItem24param3] = value;
				SavePlayerData(playerid, "Item24param3");
				return 1;
			}
			if(slot == 25)
			{
				gPlayerData[playerid][pItem25param3] = value;
				SavePlayerData(playerid, "Item25param3");
				return 1;
			}
		}
	}
	return 0;
}

stock SetPSlotParam4(playerid, slot, value)
{
	if(slot == 1)
	{
		gPlayerData[playerid][pItem1param4] = value;
		SavePlayerData(playerid, "Item1param4");
		return 1;
	}
	if(slot == 2)
	{
		gPlayerData[playerid][pItem2param4] = value;
		SavePlayerData(playerid, "Item2param4");
		return 1;
	}
	if(slot == 3)
	{
		gPlayerData[playerid][pItem3param4] = value;
		SavePlayerData(playerid, "Item3param4");
		return 1;
	}
	if(slot == 4)
	{
		gPlayerData[playerid][pItem4param4] = value;
		SavePlayerData(playerid, "Item4param4");
		return 1;
	}
	if(slot == 5)
	{
		gPlayerData[playerid][pItem5param4] = value;
		SavePlayerData(playerid, "Item5param4");
		return 1;
	}
	if(PHaveExpandItem(playerid) || gPlayerData[playerid][pVipItem] > 0)
	{
		if(slot == 6)
		{
			gPlayerData[playerid][pItem6param4] = value;
			SavePlayerData(playerid, "Item6param4");
			return 1;
		}
		if(slot == 7)
		{
			gPlayerData[playerid][pItem7param4] = value;
			SavePlayerData(playerid, "Item7param4");
			return 1;
		}
		if(slot == 8)
		{
			gPlayerData[playerid][pItem8param4] = value;
			SavePlayerData(playerid, "Item8param4");
			return 1;
		}
		if(slot == 9)
		{
			gPlayerData[playerid][pItem9param4] = value;
			SavePlayerData(playerid, "Item9param4");
			return 1;
		}
		if(slot == 10)
		{
			gPlayerData[playerid][pItem10param4] = value;
			SavePlayerData(playerid, "Item10param4");
			return 1;
		}
		if(slot == 11)
		{
			gPlayerData[playerid][pItem11param4] = value;
			SavePlayerData(playerid, "Item11param4");
			return 1;
		}
		if(slot == 12)
		{
			gPlayerData[playerid][pItem12param4] = value;
			SavePlayerData(playerid, "Item12param4");
			return 1;
		}
		if(slot == 13)
		{
			gPlayerData[playerid][pItem13param4] = value;
			SavePlayerData(playerid, "Item13param4");
			return 1;
		}
		if(slot == 14)
		{
			gPlayerData[playerid][pItem14param4] = value;
			SavePlayerData(playerid, "Item14param4");
			return 1;
		}
		if(slot == 15)
		{
			gPlayerData[playerid][pItem15param4] = value;
			SavePlayerData(playerid, "Item15param4");
			return 1;
		}
		if(gPlayerData[playerid][pVipItem] > 0)
		{
			if(slot == 16)
			{
				gPlayerData[playerid][pItem16param4] = value;
				SavePlayerData(playerid, "Item16param4");
				return 1;
			}
			if(slot == 17)
			{
				gPlayerData[playerid][pItem17param4] = value;
				SavePlayerData(playerid, "Item17param4");
				return 1;
			}
			if(slot == 18)
			{
				gPlayerData[playerid][pItem18param4] = value;
				SavePlayerData(playerid, "Item18param4");
				return 1;
			}
			if(slot == 19)
			{
				gPlayerData[playerid][pItem19param4] = value;
				SavePlayerData(playerid, "Item19param4");
				return 1;
			}
			if(slot == 20)
			{
				gPlayerData[playerid][pItem20param4] = value;
				SavePlayerData(playerid, "Item20param4");
				return 1;
			}
			if(slot == 21)
			{
				gPlayerData[playerid][pItem21param4] = value;
				SavePlayerData(playerid, "Item21param4");
				return 1;
			}
			if(slot == 22)
			{
				gPlayerData[playerid][pItem22param4] = value;
				SavePlayerData(playerid, "Item22param4");
				return 1;
			}
			if(slot == 23)
			{
				gPlayerData[playerid][pItem23param4] = value;
				SavePlayerData(playerid, "Item23param4");
				return 1;
			}
			if(slot == 24)
			{
				gPlayerData[playerid][pItem24param4] = value;
				SavePlayerData(playerid, "Item24param4");
				return 1;
			}
			if(slot == 25)
			{
				gPlayerData[playerid][pItem25param4] = value;
				SavePlayerData(playerid, "Item25param4");
				return 1;
			}
		}
	}
	return 0;
}

stock SetPSlotParam6(playerid, slot, value)
{
	if(slot == 1)
	{
		gPlayerData[playerid][pItem1param6] = value;
		SavePlayerData(playerid, "Item1param6");
		return 1;
	}
	if(slot == 2)
	{
		gPlayerData[playerid][pItem2param6] = value;
		SavePlayerData(playerid, "Item2param6");
		return 1;
	}
	if(slot == 3)
	{
		gPlayerData[playerid][pItem3param6] = value;
		SavePlayerData(playerid, "Item3param6");
		return 1;
	}
	if(slot == 4)
	{
		gPlayerData[playerid][pItem4param6] = value;
		SavePlayerData(playerid, "Item4param6");
		return 1;
	}
	if(slot == 5)
	{
		gPlayerData[playerid][pItem5param6] = value;
		SavePlayerData(playerid, "Item5param6");
		return 1;
	}
	if(PHaveExpandItem(playerid) || gPlayerData[playerid][pVipItem] > 0)
	{
		if(slot == 6)
		{
			gPlayerData[playerid][pItem6param6] = value;
			SavePlayerData(playerid, "Item6param6");
			return 1;
		}
		if(slot == 7)
		{
			gPlayerData[playerid][pItem7param6] = value;
			SavePlayerData(playerid, "Item7param6");
			return 1;
		}
		if(slot == 8)
		{
			gPlayerData[playerid][pItem8param6] = value;
			SavePlayerData(playerid, "Item8param6");
			return 1;
		}
		if(slot == 9)
		{
			gPlayerData[playerid][pItem9param6] = value;
			SavePlayerData(playerid, "Item9param6");
			return 1;
		}
		if(slot == 10)
		{
			gPlayerData[playerid][pItem10param6] = value;
			SavePlayerData(playerid, "Item10param6");
			return 1;
		}
		if(slot == 11)
		{
			gPlayerData[playerid][pItem11param6] = value;
			SavePlayerData(playerid, "Item11param6");
			return 1;
		}
		if(slot == 12)
		{
			gPlayerData[playerid][pItem12param6] = value;
			SavePlayerData(playerid, "Item12param6");
			return 1;
		}
		if(slot == 13)
		{
			gPlayerData[playerid][pItem13param6] = value;
			SavePlayerData(playerid, "Item13param6");
			return 1;
		}
		if(slot == 14)
		{
			gPlayerData[playerid][pItem14param6] = value;
			SavePlayerData(playerid, "Item14param6");
			return 1;
		}
		if(slot == 15)
		{
			gPlayerData[playerid][pItem15param6] = value;
			SavePlayerData(playerid, "Item15param6");
			return 1;
		}
		if(gPlayerData[playerid][pVipItem] > 0)
		{
			if(slot == 16)
			{
				gPlayerData[playerid][pItem16param6] = value;
				SavePlayerData(playerid, "Item16param6");
				return 1;
			}
			if(slot == 17)
			{
				gPlayerData[playerid][pItem17param6] = value;
				SavePlayerData(playerid, "Item17param6");
				return 1;
			}
			if(slot == 18)
			{
				gPlayerData[playerid][pItem18param6] = value;
				SavePlayerData(playerid, "Item18param6");
				return 1;
			}
			if(slot == 19)
			{
				gPlayerData[playerid][pItem19param6] = value;
				SavePlayerData(playerid, "Item19param6");
				return 1;
			}
			if(slot == 20)
			{
				gPlayerData[playerid][pItem20param6] = value;
				SavePlayerData(playerid, "Item20param6");
				return 1;
			}
			if(slot == 21)
			{
				gPlayerData[playerid][pItem21param6] = value;
				SavePlayerData(playerid, "Item21param6");
				return 1;
			}
			if(slot == 22)
			{
				gPlayerData[playerid][pItem22param6] = value;
				SavePlayerData(playerid, "Item22param6");
				return 1;
			}
			if(slot == 23)
			{
				gPlayerData[playerid][pItem23param6] = value;
				SavePlayerData(playerid, "Item23param6");
				return 1;
			}
			if(slot == 24)
			{
				gPlayerData[playerid][pItem24param6] = value;
				SavePlayerData(playerid, "Item24param6");
				return 1;
			}
			if(slot == 25)
			{
				gPlayerData[playerid][pItem25param6] = value;
				SavePlayerData(playerid, "Item25param6");
				return 1;
			}
		}
	}
	return 0;
}

stock SlotParam1(playerid, slot)
{
	if(slot == 1)
	{
		return gPlayerData[playerid][pItem1param];
	}
	if(slot == 2)
	{
		return gPlayerData[playerid][pItem2param];
	}
	if(slot == 3)
	{
		return gPlayerData[playerid][pItem3param];
	}
	if(slot == 4)
	{
		return gPlayerData[playerid][pItem4param];
	}
	if(slot == 5)
	{
		return gPlayerData[playerid][pItem5param];
	}
	if(slot == 6)
	{
		return gPlayerData[playerid][pItem6param];
	}
	if(slot == 7)
	{
		return gPlayerData[playerid][pItem7param];
	}
	if(slot == 8)
	{
		return gPlayerData[playerid][pItem8param];
	}
	if(slot == 9)
	{
		return gPlayerData[playerid][pItem9param];
	}
	if(slot == 10)
	{
		return gPlayerData[playerid][pItem10param];
	}
	if(slot == 11)
	{
		return gPlayerData[playerid][pItem11param];
	}
	if(slot == 12)
	{
		return gPlayerData[playerid][pItem12param];
	}
	if(slot == 13)
	{
		return gPlayerData[playerid][pItem13param];
	}
	if(slot == 14)
	{
		return gPlayerData[playerid][pItem14param];
	}
	if(slot == 15)
	{
		return gPlayerData[playerid][pItem15param];
	}
	if(gPlayerData[playerid][pVipItem] > 0)
	{
		if(slot == 16)
		{
			return gPlayerData[playerid][pItem16param];
		}
		if(slot == 17)
		{
			return gPlayerData[playerid][pItem17param];
		}
		if(slot == 18)
		{
			return gPlayerData[playerid][pItem18param];
		}
		if(slot == 19)
		{
			return gPlayerData[playerid][pItem19param];
		}
		if(slot == 20)
		{
			return gPlayerData[playerid][pItem20param];
		}
		if(slot == 21)
		{
			return gPlayerData[playerid][pItem21param];
		}
		if(slot == 22)
		{
			return gPlayerData[playerid][pItem22param];
		}
		if(slot == 23)
		{
			return gPlayerData[playerid][pItem23param];
		}
		if(slot == 24)
		{
			return gPlayerData[playerid][pItem24param];
		}
		if(slot == 25)
		{
			return gPlayerData[playerid][pItem25param];
		}
	}
	return 0;
}

stock SlotParam2(playerid, slot)
{
	if(slot == 1)
	{
		return gPlayerData[playerid][pItem1param2];
	}
	if(slot == 2)
	{
		return gPlayerData[playerid][pItem2param2];
	}
	if(slot == 3)
	{
		return gPlayerData[playerid][pItem3param2];
	}
	if(slot == 4)
	{
		return gPlayerData[playerid][pItem4param2];
	}
	if(slot == 5)
	{
		return gPlayerData[playerid][pItem5param2];
	}
	if(PHaveExpandItem(playerid) || gPlayerData[playerid][pVipItem] > 0)
	{
		if(slot == 6)
		{
			return gPlayerData[playerid][pItem6param2];
		}
		if(slot == 7)
		{
			return gPlayerData[playerid][pItem7param2];
		}
		if(slot == 8)
		{
			return gPlayerData[playerid][pItem8param2];
		}
		if(slot == 9)
		{
			return gPlayerData[playerid][pItem9param2];
		}
		if(slot == 10)
		{
			return gPlayerData[playerid][pItem10param2];
		}
		if(slot == 11)
		{
			return gPlayerData[playerid][pItem11param2];
		}
		if(slot == 12)
		{
			return gPlayerData[playerid][pItem12param2];
		}
		if(slot == 13)
		{
			return gPlayerData[playerid][pItem13param2];
		}
		if(slot == 14)
		{
			return gPlayerData[playerid][pItem14param2];
		}
		if(slot == 15)
		{
			return gPlayerData[playerid][pItem15param2];
		}
		if(gPlayerData[playerid][pVipItem] > 0)
		{
			if(slot == 16)
			{
				return gPlayerData[playerid][pItem16param2];
			}
			if(slot == 17)
			{
				return gPlayerData[playerid][pItem17param2];
			}
			if(slot == 18)
			{
				return gPlayerData[playerid][pItem18param2];
			}
			if(slot == 19)
			{
				return gPlayerData[playerid][pItem19param2];
			}
			if(slot == 20)
			{
				return gPlayerData[playerid][pItem20param2];
			}
			if(slot == 21)
			{
				return gPlayerData[playerid][pItem21param2];
			}
			if(slot == 22)
			{
				return gPlayerData[playerid][pItem22param2];
			}
			if(slot == 23)
			{
				return gPlayerData[playerid][pItem23param2];
			}
			if(slot == 24)
			{
				return gPlayerData[playerid][pItem24param2];
			}
			if(slot == 25)
			{
				return gPlayerData[playerid][pItem25param2];
			}
		}
	}
	return 0;
}

stock SlotParam3(playerid, slot)
{
	if(slot == 1)
	{
		return gPlayerData[playerid][pItem1param3];
	}
	if(slot == 2)
	{
		return gPlayerData[playerid][pItem2param3];
	}
	if(slot == 3)
	{
		return gPlayerData[playerid][pItem3param3];
	}
	if(slot == 4)
	{
		return gPlayerData[playerid][pItem4param3];
	}
	if(slot == 5)
	{
		return gPlayerData[playerid][pItem5param3];
	}
	if(PHaveExpandItem(playerid) || gPlayerData[playerid][pVipItem] > 0)
	{
		if(slot == 6)
		{
			return gPlayerData[playerid][pItem6param3];
		}
		if(slot == 7)
		{
			return gPlayerData[playerid][pItem7param3];
		}
		if(slot == 8)
		{
			return gPlayerData[playerid][pItem8param3];
		}
		if(slot == 9)
		{
			return gPlayerData[playerid][pItem9param3];
		}
		if(slot == 10)
		{
			return gPlayerData[playerid][pItem10param3];
		}
		if(slot == 11)
		{
			return gPlayerData[playerid][pItem11param3];
		}
		if(slot == 12)
		{
			return gPlayerData[playerid][pItem12param3];
		}
		if(slot == 13)
		{
			return gPlayerData[playerid][pItem13param3];
		}
		if(slot == 14)
		{
			return gPlayerData[playerid][pItem14param3];
		}
		if(slot == 15)
		{
			return gPlayerData[playerid][pItem15param3];
		}
		if(gPlayerData[playerid][pVipItem] > 0)
		{
			if(slot == 16)
			{
				return gPlayerData[playerid][pItem16param3];
			}
			if(slot == 17)
			{
				return gPlayerData[playerid][pItem17param3];
			}
			if(slot == 18)
			{
				return gPlayerData[playerid][pItem18param3];
			}
			if(slot == 19)
			{
				return gPlayerData[playerid][pItem19param3];
			}
			if(slot == 20)
			{
				return gPlayerData[playerid][pItem20param3];
			}
			if(slot == 21)
			{
				return gPlayerData[playerid][pItem21param3];
			}
			if(slot == 22)
			{
				return gPlayerData[playerid][pItem22param3];
			}
			if(slot == 23)
			{
				return gPlayerData[playerid][pItem23param3];
			}
			if(slot == 24)
			{
				return gPlayerData[playerid][pItem24param3];
			}
			if(slot == 25)
			{
				return gPlayerData[playerid][pItem25param3];
			}
		}
	}
	return 0;
}

stock SlotParam4(playerid, slot)
{
	if(slot == 1)
	{
		return gPlayerData[playerid][pItem1param4];
	}
	if(slot == 2)
	{
		return gPlayerData[playerid][pItem2param4];
	}
	if(slot == 3)
	{
		return gPlayerData[playerid][pItem3param4];
	}
	if(slot == 4)
	{
		return gPlayerData[playerid][pItem4param4];
	}
	if(slot == 5)
	{
		return gPlayerData[playerid][pItem5param4];
	}
	if(PHaveExpandItem(playerid) || gPlayerData[playerid][pVipItem] > 0)
	{
		if(slot == 6)
		{
			return gPlayerData[playerid][pItem6param4];
		}
		if(slot == 7)
		{
			return gPlayerData[playerid][pItem7param4];
		}
		if(slot == 8)
		{
			return gPlayerData[playerid][pItem8param4];
		}
		if(slot == 9)
		{
			return gPlayerData[playerid][pItem9param4];
		}
		if(slot == 10)
		{
			return gPlayerData[playerid][pItem10param4];
		}
		if(slot == 11)
		{
			return gPlayerData[playerid][pItem11param4];
		}
		if(slot == 12)
		{
			return gPlayerData[playerid][pItem12param4];
		}
		if(slot == 13)
		{
			return gPlayerData[playerid][pItem13param4];
		}
		if(slot == 14)
		{
			return gPlayerData[playerid][pItem14param4];
		}
		if(slot == 15)
		{
			return gPlayerData[playerid][pItem15param4];
		}
		if(gPlayerData[playerid][pVipItem] > 0)
		{
			if(slot == 16)
			{
				return gPlayerData[playerid][pItem16param4];
			}
			if(slot == 17)
			{
				return gPlayerData[playerid][pItem17param4];
			}
			if(slot == 18)
			{
				return gPlayerData[playerid][pItem18param4];
			}
			if(slot == 19)
			{
				return gPlayerData[playerid][pItem19param4];
			}
			if(slot == 20)
			{
				return gPlayerData[playerid][pItem20param4];
			}
			if(slot == 21)
			{
				return gPlayerData[playerid][pItem21param4];
			}
			if(slot == 22)
			{
				return gPlayerData[playerid][pItem22param4];
			}
			if(slot == 23)
			{
				return gPlayerData[playerid][pItem23param4];
			}
			if(slot == 24)
			{
				return gPlayerData[playerid][pItem24param4];
			}
			if(slot == 25)
			{
				return gPlayerData[playerid][pItem25param4];
			}
		}
	}
	return 0;
}

stock SlotParam5(playerid, slot)
{
	if(slot == 1)
	{
		format(gDSelectedItemP5[playerid], 64, gPlayerData[playerid][pItem1param5]);
	}
	else if (slot == 2)
	{
		format(gDSelectedItemP5[playerid], 64, gPlayerData[playerid][pItem2param5]);
	}
	else if (slot == 3)
	{
		format(gDSelectedItemP5[playerid], 64, gPlayerData[playerid][pItem3param5]);
	}
	else if (slot == 4)
	{
		format(gDSelectedItemP5[playerid], 64, gPlayerData[playerid][pItem4param5]);
	}
	else if (slot == 5)
	{
		format(gDSelectedItemP5[playerid], 64, gPlayerData[playerid][pItem5param5]);
	}
	else if (PHaveExpandItem(playerid) || gPlayerData[playerid][pVipItem] > 0)
	{
		if (slot == 6)
		{
			format(gDSelectedItemP5[playerid], 64, gPlayerData[playerid][pItem6param5]);
		}
		else if (slot == 7)
		{
			format(gDSelectedItemP5[playerid], 64, gPlayerData[playerid][pItem7param5]);
		}
		else if (slot == 8)
		{
			format(gDSelectedItemP5[playerid], 64, gPlayerData[playerid][pItem8param5]);
		}
		else if (slot == 9)
		{
			format(gDSelectedItemP5[playerid], 64, gPlayerData[playerid][pItem9param5]);
		}
		else if (slot == 10)
		{
			format(gDSelectedItemP5[playerid], 64, gPlayerData[playerid][pItem10param5]);
		}
		else if (slot == 11)
		{
			format(gDSelectedItemP5[playerid], 64, gPlayerData[playerid][pItem11param5]);
		}
		else if (slot == 12)
		{
			format(gDSelectedItemP5[playerid], 64, gPlayerData[playerid][pItem12param5]);
		}
		else if (slot == 13)
		{
			format(gDSelectedItemP5[playerid], 64, gPlayerData[playerid][pItem13param5]);
		}
		else if (slot == 14)
		{
			format(gDSelectedItemP5[playerid], 64, gPlayerData[playerid][pItem14param5]);
		}
		else if (slot == 15)
		{
			format(gDSelectedItemP5[playerid], 64, gPlayerData[playerid][pItem15param5]);
		}
		else if (gPlayerData[playerid][pVipItem] > 0)
		{
			if (slot == 16)
			{
				format(gDSelectedItemP5[playerid], 64, gPlayerData[playerid][pItem16param5]);
			}
			else if (slot == 17)
			{
				format(gDSelectedItemP5[playerid], 64, gPlayerData[playerid][pItem17param5]);
			}
			else if (slot == 18)
			{
				format(gDSelectedItemP5[playerid], 64, gPlayerData[playerid][pItem18param5]);
			}
			else if (slot == 19)
			{
				format(gDSelectedItemP5[playerid], 64, gPlayerData[playerid][pItem19param5]);
			}
			else if (slot == 20)
			{
				format(gDSelectedItemP5[playerid], 64, gPlayerData[playerid][pItem20param5]);
			}
			else if (slot == 21)
			{
				format(gDSelectedItemP5[playerid], 64, gPlayerData[playerid][pItem21param5]);
			}
			else if (slot == 22)
			{
				format(gDSelectedItemP5[playerid], 64, gPlayerData[playerid][pItem22param5]);
			}
			else if (slot == 23)
			{
				format(gDSelectedItemP5[playerid], 64, gPlayerData[playerid][pItem23param5]);
			}
			else if (slot == 24)
			{
				format(gDSelectedItemP5[playerid], 64, gPlayerData[playerid][pItem24param5]);
			}
			else if (slot == 25)
			{
				format(gDSelectedItemP5[playerid], 64, gPlayerData[playerid][pItem25param5]);
			}
		}
	}
	return 0;
}

stock SlotParam6(playerid, slot)
{
	if(slot == 1)
	{
		return gPlayerData[playerid][pItem1param6];
	}
	if(slot == 2)
	{
		return gPlayerData[playerid][pItem2param6];
	}
	if(slot == 3)
	{
		return gPlayerData[playerid][pItem3param6];
	}
	if(slot == 4)
	{
		return gPlayerData[playerid][pItem4param6];
	}
	if(slot == 5)
	{
		return gPlayerData[playerid][pItem5param6];
	}
	if(PHaveExpandItem(playerid) || gPlayerData[playerid][pVipItem] > 0)
	{
		if(slot == 6)
		{
			return gPlayerData[playerid][pItem6param6];
		}
		if(slot == 7)
		{
			return gPlayerData[playerid][pItem7param6];
		}
		if(slot == 8)
		{
			return gPlayerData[playerid][pItem8param6];
		}
		if(slot == 9)
		{
			return gPlayerData[playerid][pItem9param6];
		}
		if(slot == 10)
		{
			return gPlayerData[playerid][pItem10param6];
		}
		if(slot == 11)
		{
			return gPlayerData[playerid][pItem11param6];
		}
		if(slot == 12)
		{
			return gPlayerData[playerid][pItem12param6];
		}
		if(slot == 13)
		{
			return gPlayerData[playerid][pItem13param6];
		}
		if(slot == 14)
		{
			return gPlayerData[playerid][pItem14param6];
		}
		if(slot == 15)
		{
			return gPlayerData[playerid][pItem15param6];
		}
		if(gPlayerData[playerid][pVipItem] > 0)
		{
			if(slot == 16)
			{
				return gPlayerData[playerid][pItem16param6];
			}
			if(slot == 17)
			{
				return gPlayerData[playerid][pItem17param6];
			}
			if(slot == 18)
			{
				return gPlayerData[playerid][pItem18param6];
			}
			if(slot == 19)
			{
				return gPlayerData[playerid][pItem19param6];
			}
			if(slot == 20)
			{
				return gPlayerData[playerid][pItem20param6];
			}
			if(slot == 21)
			{
				return gPlayerData[playerid][pItem21param6];
			}
			if(slot == 22)
			{
				return gPlayerData[playerid][pItem22param6];
			}
			if(slot == 23)
			{
				return gPlayerData[playerid][pItem23param6];
			}
			if(slot == 24)
			{
				return gPlayerData[playerid][pItem24param6];
			}
			if(slot == 25)
			{
				return gPlayerData[playerid][pItem25param6];
			}
		}
	}
	return 0;
}

/*
* Compare player slot item type with given typedef
*/
stock PSlotItemTypeCompare(playerid, slotid, type)
{
	if(slotid == 1)
	{
		if(gPlayerData[playerid][pItem1type] == type)
			return 1;
		else
			return 0;
	}
	if(slotid == 2)
	{
		if(gPlayerData[playerid][pItem2type] == type)
			return 1;
		else
			return 0;
	}
	if(slotid == 3)
	{
		if(gPlayerData[playerid][pItem3type] == type)
			return 1;
		else
			return 0;
	}
	if(slotid == 4)
	{
		if(gPlayerData[playerid][pItem4type] == type)
			return 1;
		else
			return 0;
	}
	if(slotid == 5)
	{
		if(gPlayerData[playerid][pItem5type] == type)
			return 1;
		else
			return 0;
	}
	if(PHaveExpandItem(playerid) || gPlayerData[playerid][pVipItem] > 0)
	{
		if(slotid == 6)
		{
			if(gPlayerData[playerid][pItem6type] == type)
				return 1;
			else
				return 0;
		}
		if(slotid == 7)
		{
			if(gPlayerData[playerid][pItem7type] == type)
				return 1;
			else
				return 0;
		}
		if(slotid == 8)
		{
			if(gPlayerData[playerid][pItem8type] == type)
				return 1;
			else
				return 0;
		}
		if(slotid == 9)
		{
			if(gPlayerData[playerid][pItem9type] == type)
				return 1;
			else
				return 0;
		}
		if(slotid == 10)
		{
			if(gPlayerData[playerid][pItem10type] == type)
				return 1;
			else
				return 0;
		}
		if(slotid == 11)
		{
			if(gPlayerData[playerid][pItem11type] == type)
				return 1;
			else
				return 0;
		}
		if(slotid == 12)
		{
			if(gPlayerData[playerid][pItem12type] == type)
				return 1;
			else
				return 0;
		}
		if(slotid == 13)
		{
			if(gPlayerData[playerid][pItem13type] == type)
				return 1;
			else
				return 0;
		}
		if(slotid == 14)
		{
			if(gPlayerData[playerid][pItem14type] == type)
				return 1;
			else
				return 0;
		}
		if(slotid == 15)
		{
			if(gPlayerData[playerid][pItem15type] == type)
				return 1;
			else
				return 0;
		}
		if(gPlayerData[playerid][pVipItem] > 0)
		{
			if(slotid == 16)
			{
				if(gPlayerData[playerid][pItem16type] == type)
					return 1;
				else
					return 0;
			}
			if(slotid == 17)
			{
				if(gPlayerData[playerid][pItem17type] == type)
					return 1;
				else
					return 0;
			}
			if(slotid == 18)
			{
				if(gPlayerData[playerid][pItem18type] == type)
					return 1;
				else
					return 0;
			}
			if(slotid == 19)
			{
				if(gPlayerData[playerid][pItem19type] == type)
					return 1;
				else
					return 0;
			}
			if(slotid == 20)
			{
				if(gPlayerData[playerid][pItem20type] == type)
					return 1;
				else
					return 0;
			}
			if(slotid == 21)
			{
				if(gPlayerData[playerid][pItem21type] == type)
					return 1;
				else
					return 0;
			}
			if(slotid == 22)
			{
				if(gPlayerData[playerid][pItem22type] == type)
					return 1;
				else
					return 0;
			}
			if(slotid == 23)
			{
				if(gPlayerData[playerid][pItem23type] == type)
					return 1;
				else
					return 0;
			}
			if(slotid == 24)
			{
				if(gPlayerData[playerid][pItem24type] == type)
					return 1;
				else
					return 0;
			}
			if(slotid == 25)
			{
				if(gPlayerData[playerid][pItem25type] == type)
					return 1;
				else
					return 0;
			}
		}
	}
	return 0;
}

/*
* Returns slot item type
*/
stock PSlotItemType(playerid, slot)
{
	if(slot == 1) { return gPlayerData[playerid][pItem1type]; }
	if(slot == 2) { return gPlayerData[playerid][pItem2type]; }
	if(slot == 3) { return gPlayerData[playerid][pItem3type]; }
	if(slot == 4) { return gPlayerData[playerid][pItem4type]; }
	if(slot == 5) { return gPlayerData[playerid][pItem5type]; }
	if(slot == 6) { return gPlayerData[playerid][pItem6type]; }
	if(slot == 7) { return gPlayerData[playerid][pItem7type]; }
	if(slot == 8) { return gPlayerData[playerid][pItem8type]; }
	if(slot == 9) { return gPlayerData[playerid][pItem9type]; }
	if(slot == 10) { return gPlayerData[playerid][pItem10type]; }
	if(slot == 11) { return gPlayerData[playerid][pItem11type]; }
	if(slot == 12) { return gPlayerData[playerid][pItem12type]; }
	if(slot == 13) { return gPlayerData[playerid][pItem13type]; }
	if(slot == 14) { return gPlayerData[playerid][pItem14type]; }
	if(slot == 15) { return gPlayerData[playerid][pItem15type]; }
	if(slot == 16) { return gPlayerData[playerid][pItem16type]; }
	if(slot == 17) { return gPlayerData[playerid][pItem17type]; }
	if(slot == 18) { return gPlayerData[playerid][pItem18type]; }
	if(slot == 19) { return gPlayerData[playerid][pItem19type]; }
	if(slot == 20) { return gPlayerData[playerid][pItem20type]; }
	if(slot == 21) { return gPlayerData[playerid][pItem21type]; }
	if(slot == 22) { return gPlayerData[playerid][pItem22type]; }
	if(slot == 23) { return gPlayerData[playerid][pItem23type]; }
	if(slot == 24) { return gPlayerData[playerid][pItem24type]; }
	if(slot == 25) { return gPlayerData[playerid][pItem25type]; }
	return 0;
}

/*
* Returns slot item id (value)
*/
stock ShowSlotItem(playerid, slot)
{
	switch(slot)
	{
		case 1: { return gPlayerData[playerid][pItem1]; }
		case 2: { return gPlayerData[playerid][pItem2]; }
		case 3: { return gPlayerData[playerid][pItem3]; }
		case 4: { return gPlayerData[playerid][pItem4]; }
		case 5: { return gPlayerData[playerid][pItem5]; }
		case 6: { return gPlayerData[playerid][pItem6]; }
		case 7: { return gPlayerData[playerid][pItem7]; }
		case 8: { return gPlayerData[playerid][pItem8]; }
		case 9: { return gPlayerData[playerid][pItem9]; }
		case 10: { return gPlayerData[playerid][pItem10]; }
		case 11: { return gPlayerData[playerid][pItem11]; }
		case 12: { return gPlayerData[playerid][pItem12]; }
		case 13: { return gPlayerData[playerid][pItem13]; }
		case 14: { return gPlayerData[playerid][pItem14]; }
		case 15: { return gPlayerData[playerid][pItem15]; }
		case 16: { return gPlayerData[playerid][pItem16]; }
		case 17: { return gPlayerData[playerid][pItem17]; }
		case 18: { return gPlayerData[playerid][pItem18]; }
		case 19: { return gPlayerData[playerid][pItem19]; }
		case 20: { return gPlayerData[playerid][pItem20]; }
		case 21: { return gPlayerData[playerid][pItem21]; }
		case 22: { return gPlayerData[playerid][pItem22]; }
		case 23: { return gPlayerData[playerid][pItem23]; }
		case 24: { return gPlayerData[playerid][pItem24]; }
		case 25: { return gPlayerData[playerid][pItem25]; }
	}
	return -1;
}

/*
* Compare slot item id (value) with given id (value)
*/
stock SlotItem(playerid, slot, item)
{
	if(slot == 1)
	{
		if(gPlayerData[playerid][pItem1] == item)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if(slot == 2)
	{
		if(gPlayerData[playerid][pItem2] == item)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if(slot == 3)
	{
		if(gPlayerData[playerid][pItem3] == item)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if(slot == 4)
	{
		if(gPlayerData[playerid][pItem4] == item)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if(slot == 5)
	{
		if(gPlayerData[playerid][pItem5] == item)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if(PHaveExpandItem(playerid) || gPlayerData[playerid][pVipItem] > 0)
	{
		if(slot == 6)
		{
			if(gPlayerData[playerid][pItem6] == item)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		if(slot == 7)
		{
			if(gPlayerData[playerid][pItem7] == item)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		if(slot == 8)
		{
			if(gPlayerData[playerid][pItem8] == item)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		if(slot == 9)
		{
			if(gPlayerData[playerid][pItem9] == item)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		if(slot == 10)
		{
			if(gPlayerData[playerid][pItem10] == item)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		if(slot == 11)
		{
			if(gPlayerData[playerid][pItem11] == item)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		if(slot == 12)
		{
			if(gPlayerData[playerid][pItem12] == item)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		if(slot == 13)
		{
			if(gPlayerData[playerid][pItem13] == item)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		if(slot == 14)
		{
			if(gPlayerData[playerid][pItem14] == item)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		if(slot == 15)
		{
			if(gPlayerData[playerid][pItem15] == item)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		if(gPlayerData[playerid][pVipItem] > 0)
		{
			if(slot == 16)
			{
				if(gPlayerData[playerid][pItem16] == item)
				{
					return 1;
				}
				else
				{
					return 0;
				}
			}
			if(slot == 17)
			{
				if(gPlayerData[playerid][pItem17] == item)
				{
					return 1;
				}
				else
				{
					return 0;
				}
			}
			if(slot == 18)
			{
				if(gPlayerData[playerid][pItem18] == item)
				{
					return 1;
				}
				else
				{
					return 0;
				}
			}
			if(slot == 19)
			{
				if(gPlayerData[playerid][pItem19] == item)
				{
					return 1;
				}
				else
				{
					return 0;
				}
			}
			if(slot == 20)
			{
				if(gPlayerData[playerid][pItem20] == item)
				{
					return 1;
				}
				else
				{
					return 0;
				}
			}
			if(slot == 21)
			{
				if(gPlayerData[playerid][pItem21] == item)
				{
					return 1;
				}
				else
				{
					return 0;
				}
			}
			if(slot == 22)
			{
				if(gPlayerData[playerid][pItem22] == item)
				{
					return 1;
				}
				else
				{
					return 0;
				}
			}
			if(slot == 23)
			{
				if(gPlayerData[playerid][pItem23] == item)
				{
					return 1;
				}
				else
				{
					return 0;
				}
			}
			if(slot == 24)
			{
				if(gPlayerData[playerid][pItem24] == item)
				{
					return 1;
				}
				else
				{
					return 0;
				}
			}
			if(slot == 25)
			{
				if(gPlayerData[playerid][pItem25] == item)
				{
					return 1;
				}
				else
				{
					return 0;
				}
			}
		}
	}
	return 0;
}

stock PItemSlotStatus(playerid, slot)
{
	if(slot == 1)
	{
		if(gPlayerData[playerid][pItem1type] > 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if(slot == 2)
	{
		if(gPlayerData[playerid][pItem2type] > 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if(slot == 3)
	{
		if(gPlayerData[playerid][pItem3type] > 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if(slot == 4)
	{
		if(gPlayerData[playerid][pItem4type] > 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if(slot == 5)
	{
		if(gPlayerData[playerid][pItem5type] > 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if(slot == 6)
	{
		if(gPlayerData[playerid][pItem6type] > 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if(slot == 7)
	{
		if(gPlayerData[playerid][pItem7type] > 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if(slot == 8)
	{
		if(gPlayerData[playerid][pItem8type] > 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if(slot == 9)
	{
		if(gPlayerData[playerid][pItem9type] > 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if(slot == 10)
	{
		if(gPlayerData[playerid][pItem10type] > 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if(slot == 11)
	{
		if(gPlayerData[playerid][pItem11type] > 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if(slot == 12)
	{
		if(gPlayerData[playerid][pItem12type] > 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if(slot == 13)
	{
		if(gPlayerData[playerid][pItem13type] > 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if(slot == 14)
	{
		if(gPlayerData[playerid][pItem14type] > 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if(slot == 15)
	{
		if(gPlayerData[playerid][pItem15type] > 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if(slot == 16)
	{
		if(gPlayerData[playerid][pItem16type] > 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if(slot == 17)
	{
		if(gPlayerData[playerid][pItem17type] > 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if(slot == 18)
	{
		if(gPlayerData[playerid][pItem18type] > 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if(slot == 19)
	{
		if(gPlayerData[playerid][pItem19type] > 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if(slot == 20)
	{
		if(gPlayerData[playerid][pItem20type] > 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if(slot == 21)
	{
		if(gPlayerData[playerid][pItem21type] > 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if(slot == 22)
	{
		if(gPlayerData[playerid][pItem22type] > 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if(slot == 23)
	{
		if(gPlayerData[playerid][pItem23type] > 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if(slot == 24)
	{
		if(gPlayerData[playerid][pItem24type] > 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if(slot == 25)
	{
		if(gPlayerData[playerid][pItem25type] > 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	return 0;
}

stock PHaveItemType(playerid, itemtype)
{
	if(gPlayerData[playerid][pItem1type] == itemtype)
	{
		return 1;
	}
	if(gPlayerData[playerid][pItem2type] == itemtype)
	{
		return 2;
	}
	if(gPlayerData[playerid][pItem3type] == itemtype)
	{
		return 3;
	}
	if(gPlayerData[playerid][pItem4type] == itemtype)
	{
		return 4;
	}
	if(gPlayerData[playerid][pItem5type] == itemtype)
	{
		return 5;
	}
	if(PHaveExpandItem(playerid) || gPlayerData[playerid][pVipItem] > 0)
	{
		if(gPlayerData[playerid][pItem6type] == itemtype)
		{
			return 6;
		}
		if(gPlayerData[playerid][pItem7type] == itemtype)
		{
			return 7;
		}
		if(gPlayerData[playerid][pItem8type] == itemtype)
		{
			return 8;
		}
		if(gPlayerData[playerid][pItem9type] == itemtype)
		{
			return 9;
		}
		if(gPlayerData[playerid][pItem10type] == itemtype)
		{
			return 10;
		}
		if(gPlayerData[playerid][pItem11type] == itemtype)
		{
			return 11;
		}
		if(gPlayerData[playerid][pItem12type] == itemtype)
		{
			return 12;
		}
		if(gPlayerData[playerid][pItem13type] == itemtype)
		{
			return 13;
		}
		if(gPlayerData[playerid][pItem14type] == itemtype)
		{
			return 14;
		}
		if(gPlayerData[playerid][pItem15type] == itemtype)
		{
			return 15;
		}
		if(gPlayerData[playerid][pVipItem] > 0)
		{
			if(gPlayerData[playerid][pItem16type] == itemtype)
			{
				return 16;
			}
			if(gPlayerData[playerid][pItem17type] == itemtype)
			{
				return 17;
			}
			if(gPlayerData[playerid][pItem18type] == itemtype)
			{
				return 18;
			}
			if(gPlayerData[playerid][pItem19type] == itemtype)
			{
				return 19;
			}
			if(gPlayerData[playerid][pItem20type] == itemtype)
			{
				return 20;
			}
			if(gPlayerData[playerid][pItem21type] == itemtype)
			{
				return 21;
			}
			if(gPlayerData[playerid][pItem22type] == itemtype)
			{
				return 22;
			}
			if(gPlayerData[playerid][pItem23type] == itemtype)
			{
				return 23;
			}
			if(gPlayerData[playerid][pItem24type] == itemtype)
			{
				return 24;
			}
			if(gPlayerData[playerid][pItem25type] == itemtype)
			{
				return 25;
			}
		}
	}
	return 0;
}

stock PHaveItem(playerid, itemtype, itemid, startSlot = 1)
{
	if(startSlot <= 1)
	{
		if(gPlayerData[playerid][pItem1type] == itemtype)
		{
			if(gPlayerData[playerid][pItem1] == itemid || itemid == -1)
			{
				return 1;
			}
		}
	}
	if(startSlot <= 2)
	{
		if(gPlayerData[playerid][pItem2type] == itemtype)
		{
			if(gPlayerData[playerid][pItem2] == itemid || itemid == -1)
			{
				return 2;
			}
		}
	}
	if(startSlot <= 3)
	{
		if(gPlayerData[playerid][pItem3type] == itemtype)
		{
			if(gPlayerData[playerid][pItem3] == itemid || itemid == -1)
			{
				return 3;
			}
		}
	}
	if(startSlot <= 4)
	{
		if(gPlayerData[playerid][pItem4type] == itemtype)
		{
			if(gPlayerData[playerid][pItem4] == itemid || itemid == -1)
			{
				return 4;
			}
		}
	}
	if(startSlot <= 5)
	{
		if(gPlayerData[playerid][pItem5type] == itemtype)
		{
			if(gPlayerData[playerid][pItem5] == itemid || itemid == -1)
			{
				return 5;
			}
		}
	}
	if(PHaveExpandItem(playerid) || gPlayerData[playerid][pVipItem] > 0)
	{
		if(startSlot <= 6)
		{
			if(gPlayerData[playerid][pItem6type] == itemtype)
			{
				if(gPlayerData[playerid][pItem6] == itemid || itemid == -1)
				{
					return 6;
				}
			}
		}
		if(startSlot <= 7)
		{
			if(gPlayerData[playerid][pItem7type] == itemtype)
			{
				if(gPlayerData[playerid][pItem7] == itemid || itemid == -1)
				{
					return 7;
				}
			}
		}
		if(startSlot <= 8)
		{
			if(gPlayerData[playerid][pItem8type] == itemtype)
			{
				if(gPlayerData[playerid][pItem8] == itemid || itemid == -1)
				{
					return 8;
				}
			}
		}
		if(startSlot <= 9)
		{
			if(gPlayerData[playerid][pItem9type] == itemtype)
			{
				if(gPlayerData[playerid][pItem9] == itemid || itemid == -1)
				{
					return 9;
				}
			}
		}
		if(startSlot <= 10)
		{
			if(gPlayerData[playerid][pItem10type] == itemtype)
			{
				if(gPlayerData[playerid][pItem10] == itemid || itemid == -1)
				{
					return 10;
				}
			}
		}
		if(startSlot <= 11)
		{
			if(gPlayerData[playerid][pItem11type] == itemtype)
			{
				if(gPlayerData[playerid][pItem11] == itemid || itemid == -1)
				{
					return 11;
				}
			}
		}
		if(startSlot <= 12)
		{
			if(gPlayerData[playerid][pItem12type] == itemtype)
			{
				if(gPlayerData[playerid][pItem12] == itemid || itemid == -1)
				{
					return 12;
				}
			}
		}
		if(startSlot <= 13)
		{
			if(gPlayerData[playerid][pItem13type] == itemtype)
			{
				if(gPlayerData[playerid][pItem13] == itemid || itemid == -1)
				{
					return 13;
				}
			}
		}
		if(startSlot <= 14)
		{
			if(gPlayerData[playerid][pItem14type] == itemtype)
			{
				if(gPlayerData[playerid][pItem14] == itemid || itemid == -1)
				{
					return 14;
				}
			}
		}
		if(startSlot <= 15)
		{
			if(gPlayerData[playerid][pItem15type] == itemtype)
			{
				if(gPlayerData[playerid][pItem15] == itemid || itemid == -1)
				{
					return 15;
				}
			}
		}
		if(gPlayerData[playerid][pVipItem] > 0)
		{
			if(startSlot <= 16)
			{
				if(gPlayerData[playerid][pItem16type] == itemtype)
				{
					if(gPlayerData[playerid][pItem16] == itemid || itemid == -1)
					{
						return 16;
					}
				}
			}
			if(startSlot <= 17)
			{
				if(gPlayerData[playerid][pItem17type] == itemtype)
				{
					if(gPlayerData[playerid][pItem17] == itemid || itemid == -1)
					{
						return 17;
					}
				}
			}
			if(startSlot <= 18)
			{
				if(gPlayerData[playerid][pItem18type] == itemtype)
				{
					if(gPlayerData[playerid][pItem18] == itemid || itemid == -1)
					{
						return 18;
					}
				}
			}
			if(startSlot <= 19)
			{
				if(gPlayerData[playerid][pItem19type] == itemtype)
				{
					if(gPlayerData[playerid][pItem19] == itemid || itemid == -1)
					{
						return 19;
					}
				}
			}
			if(startSlot <= 20)
			{
				if(gPlayerData[playerid][pItem20type] == itemtype)
				{
					if(gPlayerData[playerid][pItem20] == itemid || itemid == -1)
					{
						return 20;
					}
				}
			}
			if(startSlot <= 21)
			{
				if(gPlayerData[playerid][pItem21type] == itemtype)
				{
					if(gPlayerData[playerid][pItem21] == itemid || itemid == -1)
					{
						return 21;
					}
				}
			}
			if(startSlot <= 22)
			{
				if(gPlayerData[playerid][pItem22type] == itemtype)
				{
					if(gPlayerData[playerid][pItem22] == itemid || itemid == -1)
					{
						return 22;
					}
				}
			}
			if(startSlot <= 23)
			{
				if(gPlayerData[playerid][pItem23type] == itemtype)
				{
					if(gPlayerData[playerid][pItem23] == itemid || itemid == -1)
					{
						return 23;
					}
				}
			}
			if(startSlot <= 24)
			{
				if(gPlayerData[playerid][pItem24type] == itemtype)
				{
					if(gPlayerData[playerid][pItem24] == itemid || itemid == -1)
					{
						return 24;
					}
				}
			}
			if(startSlot <= 25)
			{
				if(gPlayerData[playerid][pItem25type] == itemtype)
				{
					if(gPlayerData[playerid][pItem25] == itemid || itemid == -1)
					{
						return 25;
					}
				}
			}
		}
	}
	return 0;
}

stock PHaveItemParam1Ex(playerid, itemtype, itemid, param1)
{
	new tmpslot[MAX_PLAYER_ITEM_SLOT];
	PHaveItemEx(playerid, itemtype, itemid, tmpslot);
	for(new i = 0; i < MAX_PLAYER_ITEM_SLOT; i++)
	{
		if(tmpslot[i] && SlotParam1(playerid, i+1) == param1)
			return 1;
	}
	return 0;
}

stock PHaveItemParam2Ex(playerid, itemtype, itemid, param2)
{
	new tmpslot[MAX_PLAYER_ITEM_SLOT];
	PHaveItemEx(playerid, itemtype, itemid, tmpslot);
	for(new i = 0; i < MAX_PLAYER_ITEM_SLOT; i++)
	{
		if(tmpslot[i] && SlotParam2(playerid, i+1) == param2)
			return i+1;
	}
	return -1;
}

stock PHaveItemParam5Ex(playerid, itemtype, itemid, param5[])
{
	new tmpslot[MAX_PLAYER_ITEM_SLOT];
	PHaveItemEx(playerid, itemtype, itemid, tmpslot);
	for(new i = 0; i < MAX_PLAYER_ITEM_SLOT; i++)
	{
		SlotParam5(playerid, i+1);
		if(tmpslot[i] && strcmp(gDSelectedItemP5[playerid], param5, false) == 0)
			return i+1;
	}
	return -1;
}

stock PHaveItemEx(playerid, itemtype, itemid, slots[MAX_PLAYER_ITEM_SLOT])
{
	if(gPlayerData[playerid][pItem1type] == itemtype)
	{
		if(gPlayerData[playerid][pItem1] == itemid || itemid == -1)
			slots[0] = 1;
		else
			slots[0] = 0;
	}
	if(gPlayerData[playerid][pItem2type] == itemtype)
	{
		if(gPlayerData[playerid][pItem2] == itemid || itemid == -1)
			slots[1] = 1;
		else
			slots[1] = 0;
	}
	if(gPlayerData[playerid][pItem3type] == itemtype)
	{
		if(gPlayerData[playerid][pItem3] == itemid || itemid == -1)
			slots[2] = 1;
		else
			slots[2] = 0;
	}
	if(gPlayerData[playerid][pItem4type] == itemtype)
	{
		if(gPlayerData[playerid][pItem4] == itemid || itemid == -1)
			slots[3] = 1;
		else
			slots[3] = 0;
	}
	if(gPlayerData[playerid][pItem5type] == itemtype)
	{
		if(gPlayerData[playerid][pItem5] == itemid || itemid == -1)
			slots[4] = 1;
		else
			slots[4] = 0;
	}
	if(PHaveExpandItem(playerid) || gPlayerData[playerid][pVipItem] > 0)
	{
		if(gPlayerData[playerid][pItem6type] == itemtype)
		{
			if(gPlayerData[playerid][pItem6] == itemid || itemid == -1)
				slots[5] = 1;
			else
				slots[5] = 0;
		}
		if(gPlayerData[playerid][pItem7type] == itemtype)
		{
			if(gPlayerData[playerid][pItem7] == itemid || itemid == -1)
				slots[6] = 1;
			else
				slots[6] = 0;
		}
		if(gPlayerData[playerid][pItem8type] == itemtype)
		{
			if(gPlayerData[playerid][pItem8] == itemid || itemid == -1)
				slots[7] = 1;
			else
				slots[7] = 0;
		}
		if(gPlayerData[playerid][pItem9type] == itemtype)
		{
			if(gPlayerData[playerid][pItem9] == itemid || itemid == -1)
				slots[8] = 1;
			else
				slots[8] = 0;
		}
		if(gPlayerData[playerid][pItem10type] == itemtype)
		{
			if(gPlayerData[playerid][pItem10] == itemid || itemid == -1)
				slots[9] = 1;
			else
				slots[9] = 0;
		}
		if(gPlayerData[playerid][pItem11type] == itemtype)
		{
			if(gPlayerData[playerid][pItem11] == itemid || itemid == -1)
				slots[10] = 1;
			else
				slots[10] = 0;
		}
		if(gPlayerData[playerid][pItem12type] == itemtype)
		{
			if(gPlayerData[playerid][pItem12] == itemid || itemid == -1)
				slots[11] = 1;
			else
				slots[11] = 0;
		}
		if(gPlayerData[playerid][pItem13type] == itemtype)
		{
			if(gPlayerData[playerid][pItem13] == itemid || itemid == -1)
				slots[12] = 1;
			else
				slots[12] = 0;
		}
		if(gPlayerData[playerid][pItem14type] == itemtype)
		{
			if(gPlayerData[playerid][pItem14] == itemid || itemid == -1)
				slots[13] = 1;
			else
				slots[13] = 0;
		}
		if(gPlayerData[playerid][pItem15type] == itemtype)
		{
			if(gPlayerData[playerid][pItem15] == itemid || itemid == -1)
				slots[14] = 1;
			else
				slots[14] = 0;
		}
		if(gPlayerData[playerid][pVipItem] > 0)
		{
			if(gPlayerData[playerid][pItem16type] == itemtype)
			{
				if(gPlayerData[playerid][pItem16] == itemid || itemid == -1)
					slots[15] = 1;
				else
					slots[15] = 0;
			}
			if(gPlayerData[playerid][pItem17type] == itemtype)
			{
				if(gPlayerData[playerid][pItem17] == itemid || itemid == -1)
					slots[16] = 1;
				else
					slots[16] = 0;
			}
			if(gPlayerData[playerid][pItem18type] == itemtype)
			{
				if(gPlayerData[playerid][pItem18] == itemid || itemid == -1)
					slots[17] = 1;
				else
					slots[17] = 0;
			}
			if(gPlayerData[playerid][pItem19type] == itemtype)
			{
				if(gPlayerData[playerid][pItem19] == itemid || itemid == -1)
					slots[18] = 1;
				else
					slots[18] = 0;
			}
			if(gPlayerData[playerid][pItem20type] == itemtype)
			{
				if(gPlayerData[playerid][pItem20] == itemid || itemid == -1)
					slots[19] = 1;
				else
					slots[19] = 0;
			}
			if(gPlayerData[playerid][pItem21type] == itemtype)
			{
				if(gPlayerData[playerid][pItem21] == itemid || itemid == -1)
					slots[20] = 1;
				else
					slots[20] = 0;
			}
			if(gPlayerData[playerid][pItem22type] == itemtype)
			{
				if(gPlayerData[playerid][pItem22] == itemid || itemid == -1)
					slots[21] = 1;
				else
					slots[21] = 0;
			}
			if(gPlayerData[playerid][pItem23type] == itemtype)
			{
				if(gPlayerData[playerid][pItem23] == itemid || itemid == -1)
					slots[22] = 1;
				else
					slots[22] = 0;
			}
			if(gPlayerData[playerid][pItem24type] == itemtype)
			{
				if(gPlayerData[playerid][pItem24] == itemid || itemid == -1)
					slots[23] = 1;
				else
					slots[23] = 0;
			}
			if(gPlayerData[playerid][pItem25type] == itemtype)
			{
				if(gPlayerData[playerid][pItem25] == itemid || itemid == -1)
					slots[24] = 1;
				else
					slots[24] = 0;
			}
		}
	}
	return slots;
}

stock PHaveExpandItem(playerid)
{
	if(gPlayerData[playerid][pItem1type] == 1 && gPlayerData[playerid][pItem1] == 5)
		return 1;
		
	if(gPlayerData[playerid][pItem2type] == 1 && gPlayerData[playerid][pItem2] == 5)
		return 1;
		
	if(gPlayerData[playerid][pItem3type] == 1 && gPlayerData[playerid][pItem3] == 5)
		return 1;
		
	if(gPlayerData[playerid][pItem4type] == 1 && gPlayerData[playerid][pItem4] == 5)
		return 1;
		
	if(gPlayerData[playerid][pItem5type] == 1 && gPlayerData[playerid][pItem5] == 5)
		return 1;
		
	return 0;
}

stock PFirstFreeSlot(playerid)
{
	if(gPlayerData[playerid][pItem1type] == 0)
	{
		return 1;
	}
	if(gPlayerData[playerid][pItem2type] == 0)
	{
		return 2;
	}
	if(gPlayerData[playerid][pItem3type] == 0)
	{
		return 3;
	}
	if(gPlayerData[playerid][pItem4type] == 0)
	{
		return 4;
	}
	if(gPlayerData[playerid][pItem5type] == 0)
	{
		return 5;
	}
	if(PHaveExpandItem(playerid) || gPlayerData[playerid][pVipItem] > 0)
	{
		if(gPlayerData[playerid][pItem6type] == 0)
		{
			return 6;
		}
		if(gPlayerData[playerid][pItem7type] == 0)
		{
			return 7;
		}
		if(gPlayerData[playerid][pItem8type] == 0)
		{
			return 8;
		}
		if(gPlayerData[playerid][pItem9type] == 0)
		{
			return 9;
		}
		if(gPlayerData[playerid][pItem10type] == 0)
		{
			return 10;
		}
		if(gPlayerData[playerid][pItem11type] == 0)
		{
			return 11;
		}
		if(gPlayerData[playerid][pItem12type] == 0)
		{
			return 12;
		}
		if(gPlayerData[playerid][pItem13type] == 0)
		{
			return 13;
		}
		if(gPlayerData[playerid][pItem14type] == 0)
		{
			return 14;
		}
		if(gPlayerData[playerid][pItem15type] == 0)
		{
			return 15;
		}
		if(gPlayerData[playerid][pVipItem] > 0)
		{
			if(gPlayerData[playerid][pItem16type] == 0)
			{
				return 16;
			}
			if(gPlayerData[playerid][pItem17type] == 0)
			{
				return 17;
			}
			if(gPlayerData[playerid][pItem18type] == 0)
			{
				return 18;
			}
			if(gPlayerData[playerid][pItem19type] == 0)
			{
				return 19;
			}
			if(gPlayerData[playerid][pItem20type] == 0)
			{
				return 20;
			}
			if(gPlayerData[playerid][pItem21type] == 0)
			{
				return 21;
			}
			if(gPlayerData[playerid][pItem22type] == 0)
			{
				return 22;
			}
			if(gPlayerData[playerid][pItem23type] == 0)
			{
				return 23;
			}
			if(gPlayerData[playerid][pItem24type] == 0)
			{
				return 24;
			}
			if(gPlayerData[playerid][pItem25type] == 0)
			{
				return 25;
			}
		}
	}
	return 0;
}

stock ChangeItem(playerid, slot, value)
{
	if(slot == 1)
	{
		gPlayerData[playerid][pItem1] = value;
		SavePlayerData(playerid, "Item1");
	}
	if(slot == 2)
	{
		gPlayerData[playerid][pItem2] = value;
		SavePlayerData(playerid, "Item2");
	}
	if(slot == 3)
	{
		gPlayerData[playerid][pItem3] = value;
		SavePlayerData(playerid, "Item3");
	}
	if(slot == 4)
	{
		gPlayerData[playerid][pItem4] = value;
		SavePlayerData(playerid, "Item4");
	}
	if(slot == 5)
	{
		gPlayerData[playerid][pItem5] = value;
		SavePlayerData(playerid, "Item5");
	}
	if(slot == 6)
	{
		gPlayerData[playerid][pItem6] = value;
		SavePlayerData(playerid, "Item6");
	}
	if(slot == 7)
	{
		gPlayerData[playerid][pItem7] = value;
		SavePlayerData(playerid, "Item7");
	}
	if(slot == 8)
	{
		gPlayerData[playerid][pItem8] = value;
		SavePlayerData(playerid, "Item8");
	}
	if(slot == 9)
	{
		gPlayerData[playerid][pItem9] = value;
		SavePlayerData(playerid, "Item9");
	}
	if(slot == 10)
	{
		gPlayerData[playerid][pItem10] = value;
		SavePlayerData(playerid, "Item10");
	}
	if(slot == 11)
	{
		gPlayerData[playerid][pItem11] = value;
		SavePlayerData(playerid, "Item11");
	}
	if(slot == 12)
	{
		gPlayerData[playerid][pItem12] = value;
		SavePlayerData(playerid, "Item12");
	}
	if(slot == 13)
	{
		gPlayerData[playerid][pItem13] = value;
		SavePlayerData(playerid, "Item13");
	}
	if(slot == 14)
	{
		gPlayerData[playerid][pItem14] = value;
		SavePlayerData(playerid, "Item14");
	}
	if(slot == 15)
	{
		gPlayerData[playerid][pItem15] = value;
		SavePlayerData(playerid, "Item15");
	}
	if(slot == 16)
	{
		gPlayerData[playerid][pItem16] = value;
		SavePlayerData(playerid, "Item16");
	}
	if(slot == 17)
	{
		gPlayerData[playerid][pItem17] = value;
		SavePlayerData(playerid, "Item17");
	}
	if(slot == 18)
	{
		gPlayerData[playerid][pItem18] = value;
		SavePlayerData(playerid, "Item18");
	}
	if(slot == 19)
	{
		gPlayerData[playerid][pItem19] = value;
		SavePlayerData(playerid, "Item19");
	}
	if(slot == 20)
	{
		gPlayerData[playerid][pItem20] = value;
		SavePlayerData(playerid, "Item20");
	}
	if(slot == 21)
	{
		gPlayerData[playerid][pItem21] = value;
		SavePlayerData(playerid, "Item21");
	}
	if(slot == 22)
	{
		gPlayerData[playerid][pItem22] = value;
		SavePlayerData(playerid, "Item22");
	}
	if(slot == 23)
	{
		gPlayerData[playerid][pItem23] = value;
		SavePlayerData(playerid, "Item23");
	}
	if(slot == 24)
	{
		gPlayerData[playerid][pItem24] = value;
		SavePlayerData(playerid, "Item24");
	}
	if(slot == 25)
	{
		gPlayerData[playerid][pItem25] = value;
		SavePlayerData(playerid, "Item25");
	}
}

stock ShowPItemsHIns(playerid)
{
	new wstring[1536];
	new string2[64];
	if(gPlayerData[playerid][pVipItem] == 0 && !PHaveExpandItem(playerid)) 
	{
		format(wstring, sizeof(wstring), "1. %s [iloœæ: %d] [waga: %d]\n 2. %s [iloœæ: %d] [waga: %d]\n 3. %s [iloœæ: %d] [waga: %d]\n 4. %s [iloœæ: %d] [waga: %d]\n 5. %s [iloœæ: %d] [waga: %d]", 
		ItemName(gPlayerData[playerid][pItem1type], gPlayerData[playerid][pItem1]), SlotParam6(playerid, 1), ItemWeight(gPlayerData[playerid][pItem1type], gPlayerData[playerid][pItem1]),
		ItemName(gPlayerData[playerid][pItem2type], gPlayerData[playerid][pItem2]), SlotParam6(playerid, 2), ItemWeight(gPlayerData[playerid][pItem2type], gPlayerData[playerid][pItem2]),
		ItemName(gPlayerData[playerid][pItem3type], gPlayerData[playerid][pItem3]), SlotParam6(playerid, 3), ItemWeight(gPlayerData[playerid][pItem3type], gPlayerData[playerid][pItem3]),
		ItemName(gPlayerData[playerid][pItem4type], gPlayerData[playerid][pItem4]), SlotParam6(playerid, 4), ItemWeight(gPlayerData[playerid][pItem4type], gPlayerData[playerid][pItem4]),
		ItemName(gPlayerData[playerid][pItem5type], gPlayerData[playerid][pItem5]), SlotParam6(playerid, 5), ItemWeight(gPlayerData[playerid][pItem5type], gPlayerData[playerid][pItem5]) );
		format(string2, sizeof(string2), "Moje itemy - waga ca³kowita %d/%d (kg)", floatround(PItemWeight(playerid)/1000), floatround(gPlayerData[playerid][pMaxWeight]/1000));
		ShowPlayerDialog(playerid,DIALOG_HITEM_INS_1,DIALOG_STYLE_LIST, string2, wstring, "Wybierz", "Zamknij");
	}
	else if(gPlayerData[playerid][pVipItem] == 0 && PHaveExpandItem(playerid))
	{
		format(wstring, sizeof(wstring), "1. %s [iloœæ: %d] [waga: %d]\n2. %s [iloœæ: %d] [waga: %d]\n3. %s [iloœæ: %d] [waga: %d]\n4. %s [iloœæ: %d] [waga: %d]\n5. %s [iloœæ: %d] [waga: %d]\n6. %s [iloœæ: %d] [waga: %d]\n7. %s [iloœæ: %d] [waga: %d]\n8. %s [iloœæ: %d] [waga: %d]\n9. %s [iloœæ: %d] [waga: %d]\n10. %s [iloœæ: %d] [waga: %d]\n11. %s [iloœæ: %d] [waga: %d]\n12. %s [iloœæ: %d] [waga: %d]\n13. %s [iloœæ: %d] [waga: %d]\n14. %s [iloœæ: %d] [waga: %d]\n15. %s [iloœæ: %d] [waga: %d]\n",
		ItemName(gPlayerData[playerid][pItem1type], gPlayerData[playerid][pItem1]), SlotParam6(playerid, 1), ItemWeight(gPlayerData[playerid][pItem1type], gPlayerData[playerid][pItem1]),
		ItemName(gPlayerData[playerid][pItem2type], gPlayerData[playerid][pItem2]), SlotParam6(playerid, 2), ItemWeight(gPlayerData[playerid][pItem2type], gPlayerData[playerid][pItem2]),
		ItemName(gPlayerData[playerid][pItem3type], gPlayerData[playerid][pItem3]), SlotParam6(playerid, 3), ItemWeight(gPlayerData[playerid][pItem3type], gPlayerData[playerid][pItem3]),
		ItemName(gPlayerData[playerid][pItem4type], gPlayerData[playerid][pItem4]), SlotParam6(playerid, 4), ItemWeight(gPlayerData[playerid][pItem4type], gPlayerData[playerid][pItem4]),
		ItemName(gPlayerData[playerid][pItem5type], gPlayerData[playerid][pItem5]), SlotParam6(playerid, 5), ItemWeight(gPlayerData[playerid][pItem5type], gPlayerData[playerid][pItem5]),
		ItemName(gPlayerData[playerid][pItem6type], gPlayerData[playerid][pItem6]), SlotParam6(playerid, 6), ItemWeight(gPlayerData[playerid][pItem6type], gPlayerData[playerid][pItem6]),
		ItemName(gPlayerData[playerid][pItem7type], gPlayerData[playerid][pItem7]), SlotParam6(playerid, 7), ItemWeight(gPlayerData[playerid][pItem7type], gPlayerData[playerid][pItem7]),
		ItemName(gPlayerData[playerid][pItem8type], gPlayerData[playerid][pItem8]), SlotParam6(playerid, 8), ItemWeight(gPlayerData[playerid][pItem8type], gPlayerData[playerid][pItem8]),
		ItemName(gPlayerData[playerid][pItem9type], gPlayerData[playerid][pItem9]), SlotParam6(playerid, 9), ItemWeight(gPlayerData[playerid][pItem9type], gPlayerData[playerid][pItem9]),
		ItemName(gPlayerData[playerid][pItem10type], gPlayerData[playerid][pItem10]), SlotParam6(playerid, 10), ItemWeight(gPlayerData[playerid][pItem10type], gPlayerData[playerid][pItem10]),
		ItemName(gPlayerData[playerid][pItem11type], gPlayerData[playerid][pItem11]), SlotParam6(playerid, 11), ItemWeight(gPlayerData[playerid][pItem11type], gPlayerData[playerid][pItem11]),
		ItemName(gPlayerData[playerid][pItem12type], gPlayerData[playerid][pItem12]), SlotParam6(playerid, 12), ItemWeight(gPlayerData[playerid][pItem12type], gPlayerData[playerid][pItem12]),
		ItemName(gPlayerData[playerid][pItem13type], gPlayerData[playerid][pItem13]), SlotParam6(playerid, 13), ItemWeight(gPlayerData[playerid][pItem13type], gPlayerData[playerid][pItem13]),
		ItemName(gPlayerData[playerid][pItem14type], gPlayerData[playerid][pItem14]), SlotParam6(playerid, 14), ItemWeight(gPlayerData[playerid][pItem14type], gPlayerData[playerid][pItem14]),
		ItemName(gPlayerData[playerid][pItem15type], gPlayerData[playerid][pItem15]), SlotParam6(playerid, 15), ItemWeight(gPlayerData[playerid][pItem15type], gPlayerData[playerid][pItem15]) );
		format(string2, sizeof(string2), "Moje itemy - waga ca³kowita %d/%d (kg)", floatround(PItemWeight(playerid)/1000), floatround(gPlayerData[playerid][pMaxWeight]/1000));
		ShowPlayerDialog(playerid,DIALOG_HITEM_INS_1,DIALOG_STYLE_LIST, string2, wstring, "Wybierz", "Zamknij");
	}
	else if(gPlayerData[playerid][pVipItem] > 0)
	{
		format(wstring, sizeof(wstring), "1. %s [iloœæ: %d] [waga: %d]\n2. %s [iloœæ: %d] [waga: %d]\n3. %s [iloœæ: %d] [waga: %d]\n4. %s [iloœæ: %d] [waga: %d]\n5. %s [iloœæ: %d] [waga: %d]\n6. %s [iloœæ: %d] [waga: %d]\n7. %s [iloœæ: %d] [waga: %d]\n8. %s [iloœæ: %d] [waga: %d]\n9. %s [iloœæ: %d] [waga: %d]\n10. %s [iloœæ: %d] [waga: %d]\n11. %s [iloœæ: %d] [waga: %d]\n12. %s [iloœæ: %d] [waga: %d]\n13. %s [iloœæ: %d] [waga: %d]\n14. %s [iloœæ: %d] [waga: %d]\n15. %s [iloœæ: %d] [waga: %d]\n",
		ItemName(gPlayerData[playerid][pItem1type], gPlayerData[playerid][pItem1]), SlotParam6(playerid, 1), ItemWeight(gPlayerData[playerid][pItem1type], gPlayerData[playerid][pItem1]),
		ItemName(gPlayerData[playerid][pItem2type], gPlayerData[playerid][pItem2]), SlotParam6(playerid, 2), ItemWeight(gPlayerData[playerid][pItem2type], gPlayerData[playerid][pItem2]),
		ItemName(gPlayerData[playerid][pItem3type], gPlayerData[playerid][pItem3]), SlotParam6(playerid, 3), ItemWeight(gPlayerData[playerid][pItem3type], gPlayerData[playerid][pItem3]),
		ItemName(gPlayerData[playerid][pItem4type], gPlayerData[playerid][pItem4]), SlotParam6(playerid, 4), ItemWeight(gPlayerData[playerid][pItem4type], gPlayerData[playerid][pItem4]),
		ItemName(gPlayerData[playerid][pItem5type], gPlayerData[playerid][pItem5]), SlotParam6(playerid, 5), ItemWeight(gPlayerData[playerid][pItem5type], gPlayerData[playerid][pItem5]),
		ItemName(gPlayerData[playerid][pItem6type], gPlayerData[playerid][pItem6]), SlotParam6(playerid, 6), ItemWeight(gPlayerData[playerid][pItem6type], gPlayerData[playerid][pItem6]),
		ItemName(gPlayerData[playerid][pItem7type], gPlayerData[playerid][pItem7]), SlotParam6(playerid, 7), ItemWeight(gPlayerData[playerid][pItem7type], gPlayerData[playerid][pItem7]),
		ItemName(gPlayerData[playerid][pItem8type], gPlayerData[playerid][pItem8]), SlotParam6(playerid, 8), ItemWeight(gPlayerData[playerid][pItem8type], gPlayerData[playerid][pItem8]),
		ItemName(gPlayerData[playerid][pItem9type], gPlayerData[playerid][pItem9]), SlotParam6(playerid, 9), ItemWeight(gPlayerData[playerid][pItem9type], gPlayerData[playerid][pItem9]),
		ItemName(gPlayerData[playerid][pItem10type], gPlayerData[playerid][pItem10]), SlotParam6(playerid, 10), ItemWeight(gPlayerData[playerid][pItem10type], gPlayerData[playerid][pItem10]),
		ItemName(gPlayerData[playerid][pItem11type], gPlayerData[playerid][pItem11]), SlotParam6(playerid, 11), ItemWeight(gPlayerData[playerid][pItem11type], gPlayerData[playerid][pItem11]),
		ItemName(gPlayerData[playerid][pItem12type], gPlayerData[playerid][pItem12]), SlotParam6(playerid, 12), ItemWeight(gPlayerData[playerid][pItem12type], gPlayerData[playerid][pItem12]),
		ItemName(gPlayerData[playerid][pItem13type], gPlayerData[playerid][pItem13]), SlotParam6(playerid, 13), ItemWeight(gPlayerData[playerid][pItem13type], gPlayerData[playerid][pItem13]),
		ItemName(gPlayerData[playerid][pItem14type], gPlayerData[playerid][pItem14]), SlotParam6(playerid, 14), ItemWeight(gPlayerData[playerid][pItem14type], gPlayerData[playerid][pItem14]),
		ItemName(gPlayerData[playerid][pItem15type], gPlayerData[playerid][pItem15]), SlotParam6(playerid, 15), ItemWeight(gPlayerData[playerid][pItem15type], gPlayerData[playerid][pItem15]) );
		format(wstring, sizeof(wstring), "%s16. %s [iloœæ: %d] [waga: %d]\n17. %s [iloœæ: %d] [waga: %d]\n18. %s [iloœæ: %d] [waga: %d]\n19. %s [iloœæ: %d] [waga: %d]\n20. %s [iloœæ: %d] [waga: %d]\n21. %s [iloœæ: %d] [waga: %d]\n22. %s [iloœæ: %d] [waga: %d]\n23. %s [iloœæ: %d] [waga: %d]\n24. %s [iloœæ: %d] [waga: %d]\n25. %s [iloœæ: %d] [waga: %d]",
		wstring,
		ItemName(gPlayerData[playerid][pItem16type], gPlayerData[playerid][pItem16]), SlotParam6(playerid, 16), ItemWeight(gPlayerData[playerid][pItem16type], gPlayerData[playerid][pItem16]),
		ItemName(gPlayerData[playerid][pItem17type], gPlayerData[playerid][pItem17]), SlotParam6(playerid, 17), ItemWeight(gPlayerData[playerid][pItem17type], gPlayerData[playerid][pItem17]),
		ItemName(gPlayerData[playerid][pItem18type], gPlayerData[playerid][pItem18]), SlotParam6(playerid, 18), ItemWeight(gPlayerData[playerid][pItem18type], gPlayerData[playerid][pItem18]),
		ItemName(gPlayerData[playerid][pItem19type], gPlayerData[playerid][pItem19]), SlotParam6(playerid, 19), ItemWeight(gPlayerData[playerid][pItem19type], gPlayerData[playerid][pItem19]),
		ItemName(gPlayerData[playerid][pItem20type], gPlayerData[playerid][pItem20]), SlotParam6(playerid, 20), ItemWeight(gPlayerData[playerid][pItem20type], gPlayerData[playerid][pItem20]),
		ItemName(gPlayerData[playerid][pItem21type], gPlayerData[playerid][pItem21]), SlotParam6(playerid, 21), ItemWeight(gPlayerData[playerid][pItem21type], gPlayerData[playerid][pItem21]),
		ItemName(gPlayerData[playerid][pItem22type], gPlayerData[playerid][pItem22]), SlotParam6(playerid, 22), ItemWeight(gPlayerData[playerid][pItem22type], gPlayerData[playerid][pItem22]),
		ItemName(gPlayerData[playerid][pItem23type], gPlayerData[playerid][pItem23]), SlotParam6(playerid, 23), ItemWeight(gPlayerData[playerid][pItem23type], gPlayerData[playerid][pItem23]),
		ItemName(gPlayerData[playerid][pItem24type], gPlayerData[playerid][pItem24]), SlotParam6(playerid, 24), ItemWeight(gPlayerData[playerid][pItem24type], gPlayerData[playerid][pItem24]),
		ItemName(gPlayerData[playerid][pItem25type], gPlayerData[playerid][pItem25]), SlotParam6(playerid, 25), ItemWeight(gPlayerData[playerid][pItem25type], gPlayerData[playerid][pItem25]) );
		format(string2, sizeof(string2), "Moje itemy - waga ca³kowita %d/%d (kg)", floatround(PItemWeight(playerid)/1000), floatround(gPlayerData[playerid][pMaxWeight]/1000));
		ShowPlayerDialog(playerid,DIALOG_HITEM_INS_1,DIALOG_STYLE_LIST, string2, wstring, "Wybierz", "Zamknij");
	}
	return 1;
}

stock ShowPItemsVIns(playerid)
{
	new wstring[1536];
	new string2[64];
	if(gPlayerData[playerid][pVipItem] == 0 && PHaveExpandItem(playerid))
	{
		format(wstring, sizeof(wstring), "1. %s [iloœæ: %d] [waga: %d]\n2. %s [iloœæ: %d] [waga: %d]\n3. %s [iloœæ: %d] [waga: %d]\n4. %s [iloœæ: %d] [waga: %d]\n5. %s [iloœæ: %d] [waga: %d]\n6. %s [iloœæ: %d] [waga: %d]\n7. %s [iloœæ: %d] [waga: %d]\n8. %s [iloœæ: %d] [waga: %d]\n9. %s [iloœæ: %d] [waga: %d]\n10. %s [iloœæ: %d] [waga: %d]\n11. %s [iloœæ: %d] [waga: %d]\n12. %s [iloœæ: %d] [waga: %d]\n13. %s [iloœæ: %d] [waga: %d]\n14. %s [iloœæ: %d] [waga: %d]\n15. %s [iloœæ: %d] [waga: %d]\n",
		ItemName(gPlayerData[playerid][pItem1type], gPlayerData[playerid][pItem1]), SlotParam6(playerid, 1), ItemWeight(gPlayerData[playerid][pItem1type], gPlayerData[playerid][pItem1]),
		ItemName(gPlayerData[playerid][pItem2type], gPlayerData[playerid][pItem2]), SlotParam6(playerid, 2), ItemWeight(gPlayerData[playerid][pItem2type], gPlayerData[playerid][pItem2]),
		ItemName(gPlayerData[playerid][pItem3type], gPlayerData[playerid][pItem3]), SlotParam6(playerid, 3), ItemWeight(gPlayerData[playerid][pItem3type], gPlayerData[playerid][pItem3]),
		ItemName(gPlayerData[playerid][pItem4type], gPlayerData[playerid][pItem4]), SlotParam6(playerid, 4), ItemWeight(gPlayerData[playerid][pItem4type], gPlayerData[playerid][pItem4]),
		ItemName(gPlayerData[playerid][pItem5type], gPlayerData[playerid][pItem5]), SlotParam6(playerid, 5), ItemWeight(gPlayerData[playerid][pItem5type], gPlayerData[playerid][pItem5]),
		ItemName(gPlayerData[playerid][pItem6type], gPlayerData[playerid][pItem6]), SlotParam6(playerid, 6), ItemWeight(gPlayerData[playerid][pItem6type], gPlayerData[playerid][pItem6]),
		ItemName(gPlayerData[playerid][pItem7type], gPlayerData[playerid][pItem7]), SlotParam6(playerid, 7), ItemWeight(gPlayerData[playerid][pItem7type], gPlayerData[playerid][pItem7]),
		ItemName(gPlayerData[playerid][pItem8type], gPlayerData[playerid][pItem8]), SlotParam6(playerid, 8), ItemWeight(gPlayerData[playerid][pItem8type], gPlayerData[playerid][pItem8]),
		ItemName(gPlayerData[playerid][pItem9type], gPlayerData[playerid][pItem9]), SlotParam6(playerid, 9), ItemWeight(gPlayerData[playerid][pItem9type], gPlayerData[playerid][pItem9]),
		ItemName(gPlayerData[playerid][pItem10type], gPlayerData[playerid][pItem10]), SlotParam6(playerid, 10), ItemWeight(gPlayerData[playerid][pItem10type], gPlayerData[playerid][pItem10]),
		ItemName(gPlayerData[playerid][pItem11type], gPlayerData[playerid][pItem11]), SlotParam6(playerid, 11), ItemWeight(gPlayerData[playerid][pItem11type], gPlayerData[playerid][pItem11]),
		ItemName(gPlayerData[playerid][pItem12type], gPlayerData[playerid][pItem12]), SlotParam6(playerid, 12), ItemWeight(gPlayerData[playerid][pItem12type], gPlayerData[playerid][pItem12]),
		ItemName(gPlayerData[playerid][pItem13type], gPlayerData[playerid][pItem13]), SlotParam6(playerid, 13), ItemWeight(gPlayerData[playerid][pItem13type], gPlayerData[playerid][pItem13]),
		ItemName(gPlayerData[playerid][pItem14type], gPlayerData[playerid][pItem14]), SlotParam6(playerid, 14), ItemWeight(gPlayerData[playerid][pItem14type], gPlayerData[playerid][pItem14]),
		ItemName(gPlayerData[playerid][pItem15type], gPlayerData[playerid][pItem15]), SlotParam6(playerid, 15), ItemWeight(gPlayerData[playerid][pItem15type], gPlayerData[playerid][pItem15]) );
		format(string2, sizeof(string2), "Moje itemy - waga ca³kowita %d/%d (kg)", floatround(PItemWeight(playerid)/1000), floatround(gPlayerData[playerid][pMaxWeight]/1000));
		ShowPlayerDialog(playerid,DIALOG_VITEM_INS_1,DIALOG_STYLE_LIST, string2, wstring, "Wybierz", "Zamknij");
	}
	if(gPlayerData[playerid][pVipItem] == 0 && !PHaveExpandItem(playerid)) 
	{
		format(wstring, sizeof(wstring), "1. %s [iloœæ: %d] [waga: %d]\n 2. %s [iloœæ: %d] [waga: %d]\n 3. %s [iloœæ: %d] [waga: %d]\n 4. %s [iloœæ: %d] [waga: %d]\n 5. %s [iloœæ: %d] [waga: %d]", 
		ItemName(gPlayerData[playerid][pItem1type], gPlayerData[playerid][pItem1]), SlotParam6(playerid, 1), ItemWeight(gPlayerData[playerid][pItem1type], gPlayerData[playerid][pItem1]),
		ItemName(gPlayerData[playerid][pItem2type], gPlayerData[playerid][pItem2]), SlotParam6(playerid, 2), ItemWeight(gPlayerData[playerid][pItem2type], gPlayerData[playerid][pItem2]),
		ItemName(gPlayerData[playerid][pItem3type], gPlayerData[playerid][pItem3]), SlotParam6(playerid, 3), ItemWeight(gPlayerData[playerid][pItem3type], gPlayerData[playerid][pItem3]),
		ItemName(gPlayerData[playerid][pItem4type], gPlayerData[playerid][pItem4]), SlotParam6(playerid, 4), ItemWeight(gPlayerData[playerid][pItem4type], gPlayerData[playerid][pItem4]),
		ItemName(gPlayerData[playerid][pItem5type], gPlayerData[playerid][pItem5]), SlotParam6(playerid, 5), ItemWeight(gPlayerData[playerid][pItem5type], gPlayerData[playerid][pItem5]) );
		format(string2, sizeof(string2), "Moje itemy - waga ca³kowita %d/%d (kg)", floatround(PItemWeight(playerid)/1000), floatround(gPlayerData[playerid][pMaxWeight]/1000));
		ShowPlayerDialog(playerid,DIALOG_VITEM_INS_1,DIALOG_STYLE_LIST, string2, wstring, "Wybierz", "Zamknij");
	}
	if(gPlayerData[playerid][pVipItem] > 0)
	{
		format(wstring, sizeof(wstring), "1. %s [iloœæ: %d] [waga: %d]\n2. %s [iloœæ: %d] [waga: %d]\n3. %s [iloœæ: %d] [waga: %d]\n4. %s [iloœæ: %d] [waga: %d]\n5. %s [iloœæ: %d] [waga: %d]\n6. %s [iloœæ: %d] [waga: %d]\n7. %s [iloœæ: %d] [waga: %d]\n8. %s [iloœæ: %d] [waga: %d]\n9. %s [iloœæ: %d] [waga: %d]\n10. %s [iloœæ: %d] [waga: %d]\n11. %s [iloœæ: %d] [waga: %d]\n12. %s [iloœæ: %d] [waga: %d]\n13. %s [iloœæ: %d] [waga: %d]\n14. %s [iloœæ: %d] [waga: %d]\n15. %s [iloœæ: %d] [waga: %d]\n",
		ItemName(gPlayerData[playerid][pItem1type], gPlayerData[playerid][pItem1]), SlotParam6(playerid, 1), ItemWeight(gPlayerData[playerid][pItem1type], gPlayerData[playerid][pItem1]),
		ItemName(gPlayerData[playerid][pItem2type], gPlayerData[playerid][pItem2]), SlotParam6(playerid, 2), ItemWeight(gPlayerData[playerid][pItem2type], gPlayerData[playerid][pItem2]),
		ItemName(gPlayerData[playerid][pItem3type], gPlayerData[playerid][pItem3]), SlotParam6(playerid, 3), ItemWeight(gPlayerData[playerid][pItem3type], gPlayerData[playerid][pItem3]),
		ItemName(gPlayerData[playerid][pItem4type], gPlayerData[playerid][pItem4]), SlotParam6(playerid, 4), ItemWeight(gPlayerData[playerid][pItem4type], gPlayerData[playerid][pItem4]),
		ItemName(gPlayerData[playerid][pItem5type], gPlayerData[playerid][pItem5]), SlotParam6(playerid, 5), ItemWeight(gPlayerData[playerid][pItem5type], gPlayerData[playerid][pItem5]),
		ItemName(gPlayerData[playerid][pItem6type], gPlayerData[playerid][pItem6]), SlotParam6(playerid, 6), ItemWeight(gPlayerData[playerid][pItem6type], gPlayerData[playerid][pItem6]),
		ItemName(gPlayerData[playerid][pItem7type], gPlayerData[playerid][pItem7]), SlotParam6(playerid, 7), ItemWeight(gPlayerData[playerid][pItem7type], gPlayerData[playerid][pItem7]),
		ItemName(gPlayerData[playerid][pItem8type], gPlayerData[playerid][pItem8]), SlotParam6(playerid, 8), ItemWeight(gPlayerData[playerid][pItem8type], gPlayerData[playerid][pItem8]),
		ItemName(gPlayerData[playerid][pItem9type], gPlayerData[playerid][pItem9]), SlotParam6(playerid, 9), ItemWeight(gPlayerData[playerid][pItem9type], gPlayerData[playerid][pItem9]),
		ItemName(gPlayerData[playerid][pItem10type], gPlayerData[playerid][pItem10]), SlotParam6(playerid, 10), ItemWeight(gPlayerData[playerid][pItem10type], gPlayerData[playerid][pItem10]),
		ItemName(gPlayerData[playerid][pItem11type], gPlayerData[playerid][pItem11]), SlotParam6(playerid, 11), ItemWeight(gPlayerData[playerid][pItem11type], gPlayerData[playerid][pItem11]),
		ItemName(gPlayerData[playerid][pItem12type], gPlayerData[playerid][pItem12]), SlotParam6(playerid, 12), ItemWeight(gPlayerData[playerid][pItem12type], gPlayerData[playerid][pItem12]),
		ItemName(gPlayerData[playerid][pItem13type], gPlayerData[playerid][pItem13]), SlotParam6(playerid, 13), ItemWeight(gPlayerData[playerid][pItem13type], gPlayerData[playerid][pItem13]),
		ItemName(gPlayerData[playerid][pItem14type], gPlayerData[playerid][pItem14]), SlotParam6(playerid, 14), ItemWeight(gPlayerData[playerid][pItem14type], gPlayerData[playerid][pItem14]),
		ItemName(gPlayerData[playerid][pItem15type], gPlayerData[playerid][pItem15]), SlotParam6(playerid, 15), ItemWeight(gPlayerData[playerid][pItem15type], gPlayerData[playerid][pItem15]) );
		format(wstring, sizeof(wstring), "%s16. %s [iloœæ: %d] [waga: %d]\n17. %s [iloœæ: %d] [waga: %d]\n18. %s [iloœæ: %d] [waga: %d]\n19. %s [iloœæ: %d] [waga: %d]\n20. %s [iloœæ: %d] [waga: %d]\n21. %s [iloœæ: %d] [waga: %d]\n22. %s [iloœæ: %d] [waga: %d]\n23. %s [iloœæ: %d] [waga: %d]\n24. %s [iloœæ: %d] [waga: %d]\n25. %s [iloœæ: %d] [waga: %d]",
		wstring,
		ItemName(gPlayerData[playerid][pItem16type], gPlayerData[playerid][pItem16]), SlotParam6(playerid, 16), ItemWeight(gPlayerData[playerid][pItem16type], gPlayerData[playerid][pItem16]),
		ItemName(gPlayerData[playerid][pItem17type], gPlayerData[playerid][pItem17]), SlotParam6(playerid, 17), ItemWeight(gPlayerData[playerid][pItem17type], gPlayerData[playerid][pItem17]),
		ItemName(gPlayerData[playerid][pItem18type], gPlayerData[playerid][pItem18]), SlotParam6(playerid, 18), ItemWeight(gPlayerData[playerid][pItem18type], gPlayerData[playerid][pItem18]),
		ItemName(gPlayerData[playerid][pItem19type], gPlayerData[playerid][pItem19]), SlotParam6(playerid, 19), ItemWeight(gPlayerData[playerid][pItem19type], gPlayerData[playerid][pItem19]),
		ItemName(gPlayerData[playerid][pItem20type], gPlayerData[playerid][pItem20]), SlotParam6(playerid, 20), ItemWeight(gPlayerData[playerid][pItem20type], gPlayerData[playerid][pItem20]),
		ItemName(gPlayerData[playerid][pItem21type], gPlayerData[playerid][pItem21]), SlotParam6(playerid, 21), ItemWeight(gPlayerData[playerid][pItem21type], gPlayerData[playerid][pItem21]),
		ItemName(gPlayerData[playerid][pItem22type], gPlayerData[playerid][pItem22]), SlotParam6(playerid, 22), ItemWeight(gPlayerData[playerid][pItem22type], gPlayerData[playerid][pItem22]),
		ItemName(gPlayerData[playerid][pItem23type], gPlayerData[playerid][pItem23]), SlotParam6(playerid, 23), ItemWeight(gPlayerData[playerid][pItem23type], gPlayerData[playerid][pItem23]),
		ItemName(gPlayerData[playerid][pItem24type], gPlayerData[playerid][pItem24]), SlotParam6(playerid, 24), ItemWeight(gPlayerData[playerid][pItem24type], gPlayerData[playerid][pItem24]),
		ItemName(gPlayerData[playerid][pItem25type], gPlayerData[playerid][pItem25]), SlotParam6(playerid, 25), ItemWeight(gPlayerData[playerid][pItem25type], gPlayerData[playerid][pItem25]) );
		format(string2, sizeof(string2), "Moje itemy - waga ca³kowita %d/%d (kg)", floatround(PItemWeight(playerid)/1000), floatround(gPlayerData[playerid][pMaxWeight]/1000));
		ShowPlayerDialog(playerid,DIALOG_VITEM_INS_1,DIALOG_STYLE_LIST, string2, wstring, "Wybierz", "Zamknij");
	}
	return 1;
}

stock ShowPItems(playerid)
{
	static wstring[2048];	
	strdel(wstring, 0, sizeof(wstring));
	
	if(gPlayerData[playerid][pVipItem] == 0 && PHaveExpandItem(playerid))
	{
		format(wstring, sizeof(wstring), "1. %s [iloœæ: %d] [waga: %d]\n2. %s [iloœæ: %d] [waga: %d]\n3. %s [iloœæ: %d] [waga: %d]\n4. %s [iloœæ: %d] [waga: %d]\n5. %s [iloœæ: %d] [waga: %d]\n6. %s [iloœæ: %d] [waga: %d]\n7. %s [iloœæ: %d] [waga: %d]\n8. %s [iloœæ: %d] [waga: %d]\n9. %s [iloœæ: %d] [waga: %d]\n10. %s [iloœæ: %d] [waga: %d]\n11. %s [iloœæ: %d] [waga: %d]\n12. %s [iloœæ: %d] [waga: %d]\n13. %s [iloœæ: %d] [waga: %d]\n14. %s [iloœæ: %d] [waga: %d]\n15. %s [iloœæ: %d] [waga: %d]\n",
		ItemName(gPlayerData[playerid][pItem1type], gPlayerData[playerid][pItem1]), SlotParam6(playerid, 1), ItemWeight(gPlayerData[playerid][pItem1type], gPlayerData[playerid][pItem1]),
		ItemName(gPlayerData[playerid][pItem2type], gPlayerData[playerid][pItem2]), SlotParam6(playerid, 2), ItemWeight(gPlayerData[playerid][pItem2type], gPlayerData[playerid][pItem2]),
		ItemName(gPlayerData[playerid][pItem3type], gPlayerData[playerid][pItem3]), SlotParam6(playerid, 3), ItemWeight(gPlayerData[playerid][pItem3type], gPlayerData[playerid][pItem3]),
		ItemName(gPlayerData[playerid][pItem4type], gPlayerData[playerid][pItem4]), SlotParam6(playerid, 4), ItemWeight(gPlayerData[playerid][pItem4type], gPlayerData[playerid][pItem4]),
		ItemName(gPlayerData[playerid][pItem5type], gPlayerData[playerid][pItem5]), SlotParam6(playerid, 5), ItemWeight(gPlayerData[playerid][pItem5type], gPlayerData[playerid][pItem5]),
		ItemName(gPlayerData[playerid][pItem6type], gPlayerData[playerid][pItem6]), SlotParam6(playerid, 6), ItemWeight(gPlayerData[playerid][pItem6type], gPlayerData[playerid][pItem6]),
		ItemName(gPlayerData[playerid][pItem7type], gPlayerData[playerid][pItem7]), SlotParam6(playerid, 7), ItemWeight(gPlayerData[playerid][pItem7type], gPlayerData[playerid][pItem7]),
		ItemName(gPlayerData[playerid][pItem8type], gPlayerData[playerid][pItem8]), SlotParam6(playerid, 8), ItemWeight(gPlayerData[playerid][pItem8type], gPlayerData[playerid][pItem8]),
		ItemName(gPlayerData[playerid][pItem9type], gPlayerData[playerid][pItem9]), SlotParam6(playerid, 9), ItemWeight(gPlayerData[playerid][pItem9type], gPlayerData[playerid][pItem9]),
		ItemName(gPlayerData[playerid][pItem10type], gPlayerData[playerid][pItem10]), SlotParam6(playerid, 10), ItemWeight(gPlayerData[playerid][pItem10type], gPlayerData[playerid][pItem10]),
		ItemName(gPlayerData[playerid][pItem11type], gPlayerData[playerid][pItem11]), SlotParam6(playerid, 11), ItemWeight(gPlayerData[playerid][pItem11type], gPlayerData[playerid][pItem11]),
		ItemName(gPlayerData[playerid][pItem12type], gPlayerData[playerid][pItem12]), SlotParam6(playerid, 12), ItemWeight(gPlayerData[playerid][pItem12type], gPlayerData[playerid][pItem12]),
		ItemName(gPlayerData[playerid][pItem13type], gPlayerData[playerid][pItem13]), SlotParam6(playerid, 13), ItemWeight(gPlayerData[playerid][pItem13type], gPlayerData[playerid][pItem13]),
		ItemName(gPlayerData[playerid][pItem14type], gPlayerData[playerid][pItem14]), SlotParam6(playerid, 14), ItemWeight(gPlayerData[playerid][pItem14type], gPlayerData[playerid][pItem14]),
		ItemName(gPlayerData[playerid][pItem15type], gPlayerData[playerid][pItem15]), SlotParam6(playerid, 15), ItemWeight(gPlayerData[playerid][pItem15type], gPlayerData[playerid][pItem15]) );
	}
	else if(gPlayerData[playerid][pVipItem] == 0 && PHaveExpandItem(playerid) == 0) 
	{
		format(wstring, sizeof(wstring), "1. %s [iloœæ: %d] [waga: %d]\n2. %s [iloœæ: %d] [waga: %d]\n3. %s [iloœæ: %d] [waga: %d]\n4. %s [iloœæ: %d] [waga: %d]\n5. %s [iloœæ: %d] [waga: %d]", 
		ItemName(gPlayerData[playerid][pItem1type], gPlayerData[playerid][pItem1]), SlotParam6(playerid, 1), ItemWeight(gPlayerData[playerid][pItem1type], gPlayerData[playerid][pItem1]),
		ItemName(gPlayerData[playerid][pItem2type], gPlayerData[playerid][pItem2]), SlotParam6(playerid, 2), ItemWeight(gPlayerData[playerid][pItem2type], gPlayerData[playerid][pItem2]),
		ItemName(gPlayerData[playerid][pItem3type], gPlayerData[playerid][pItem3]), SlotParam6(playerid, 3), ItemWeight(gPlayerData[playerid][pItem3type], gPlayerData[playerid][pItem3]),
		ItemName(gPlayerData[playerid][pItem4type], gPlayerData[playerid][pItem4]), SlotParam6(playerid, 4), ItemWeight(gPlayerData[playerid][pItem4type], gPlayerData[playerid][pItem4]),
		ItemName(gPlayerData[playerid][pItem5type], gPlayerData[playerid][pItem5]), SlotParam6(playerid, 5), ItemWeight(gPlayerData[playerid][pItem5type], gPlayerData[playerid][pItem5]) );
	}
	else if(gPlayerData[playerid][pVipItem] > 0)
	{
		format(wstring, sizeof(wstring), "1. %s [iloœæ: %d] [waga: %d]\n2. %s [iloœæ: %d] [waga: %d]\n3. %s [iloœæ: %d] [waga: %d]\n4. %s [iloœæ: %d] [waga: %d]\n5. %s [iloœæ: %d] [waga: %d]\n6. %s [iloœæ: %d] [waga: %d]\n7. %s [iloœæ: %d] [waga: %d]\n8. %s [iloœæ: %d] [waga: %d]\n9. %s [iloœæ: %d] [waga: %d]\n10. %s [iloœæ: %d] [waga: %d]\n11. %s [iloœæ: %d] [waga: %d]\n12. %s [iloœæ: %d] [waga: %d]\n13. %s [iloœæ: %d] [waga: %d]\n14. %s [iloœæ: %d] [waga: %d]\n15. %s [iloœæ: %d] [waga: %d]\n",
		ItemName(gPlayerData[playerid][pItem1type], gPlayerData[playerid][pItem1]), SlotParam6(playerid, 1), ItemWeight(gPlayerData[playerid][pItem1type], gPlayerData[playerid][pItem1]),
		ItemName(gPlayerData[playerid][pItem2type], gPlayerData[playerid][pItem2]), SlotParam6(playerid, 2), ItemWeight(gPlayerData[playerid][pItem2type], gPlayerData[playerid][pItem2]),
		ItemName(gPlayerData[playerid][pItem3type], gPlayerData[playerid][pItem3]), SlotParam6(playerid, 3), ItemWeight(gPlayerData[playerid][pItem3type], gPlayerData[playerid][pItem3]),
		ItemName(gPlayerData[playerid][pItem4type], gPlayerData[playerid][pItem4]), SlotParam6(playerid, 4), ItemWeight(gPlayerData[playerid][pItem4type], gPlayerData[playerid][pItem4]),
		ItemName(gPlayerData[playerid][pItem5type], gPlayerData[playerid][pItem5]), SlotParam6(playerid, 5), ItemWeight(gPlayerData[playerid][pItem5type], gPlayerData[playerid][pItem5]),
		ItemName(gPlayerData[playerid][pItem6type], gPlayerData[playerid][pItem6]), SlotParam6(playerid, 6), ItemWeight(gPlayerData[playerid][pItem6type], gPlayerData[playerid][pItem6]),
		ItemName(gPlayerData[playerid][pItem7type], gPlayerData[playerid][pItem7]), SlotParam6(playerid, 7), ItemWeight(gPlayerData[playerid][pItem7type], gPlayerData[playerid][pItem7]),
		ItemName(gPlayerData[playerid][pItem8type], gPlayerData[playerid][pItem8]), SlotParam6(playerid, 8), ItemWeight(gPlayerData[playerid][pItem8type], gPlayerData[playerid][pItem8]),
		ItemName(gPlayerData[playerid][pItem9type], gPlayerData[playerid][pItem9]), SlotParam6(playerid, 9), ItemWeight(gPlayerData[playerid][pItem9type], gPlayerData[playerid][pItem9]),
		ItemName(gPlayerData[playerid][pItem10type], gPlayerData[playerid][pItem10]), SlotParam6(playerid, 10), ItemWeight(gPlayerData[playerid][pItem10type], gPlayerData[playerid][pItem10]),
		ItemName(gPlayerData[playerid][pItem11type], gPlayerData[playerid][pItem11]), SlotParam6(playerid, 11), ItemWeight(gPlayerData[playerid][pItem11type], gPlayerData[playerid][pItem11]),
		ItemName(gPlayerData[playerid][pItem12type], gPlayerData[playerid][pItem12]), SlotParam6(playerid, 12), ItemWeight(gPlayerData[playerid][pItem12type], gPlayerData[playerid][pItem12]),
		ItemName(gPlayerData[playerid][pItem13type], gPlayerData[playerid][pItem13]), SlotParam6(playerid, 13), ItemWeight(gPlayerData[playerid][pItem13type], gPlayerData[playerid][pItem13]),
		ItemName(gPlayerData[playerid][pItem14type], gPlayerData[playerid][pItem14]), SlotParam6(playerid, 14), ItemWeight(gPlayerData[playerid][pItem14type], gPlayerData[playerid][pItem14]),
		ItemName(gPlayerData[playerid][pItem15type], gPlayerData[playerid][pItem15]), SlotParam6(playerid, 15), ItemWeight(gPlayerData[playerid][pItem15type], gPlayerData[playerid][pItem15]) );
		format(wstring, sizeof(wstring), "%s16. %s [iloœæ: %d] [waga: %d]\n17. %s [iloœæ: %d] [waga: %d]\n18. %s [iloœæ: %d] [waga: %d]\n19. %s [iloœæ: %d] [waga: %d]\n20. %s [iloœæ: %d] [waga: %d]\n21. %s [iloœæ: %d] [waga: %d]\n22. %s [iloœæ: %d] [waga: %d]\n23. %s [iloœæ: %d] [waga: %d]\n24. %s [iloœæ: %d] [waga: %d]\n25. %s [iloœæ: %d] [waga: %d]",
		wstring,
		ItemName(gPlayerData[playerid][pItem16type], gPlayerData[playerid][pItem16]), SlotParam6(playerid, 16), ItemWeight(gPlayerData[playerid][pItem16type], gPlayerData[playerid][pItem16]),
		ItemName(gPlayerData[playerid][pItem17type], gPlayerData[playerid][pItem17]), SlotParam6(playerid, 17), ItemWeight(gPlayerData[playerid][pItem17type], gPlayerData[playerid][pItem17]),
		ItemName(gPlayerData[playerid][pItem18type], gPlayerData[playerid][pItem18]), SlotParam6(playerid, 18), ItemWeight(gPlayerData[playerid][pItem18type], gPlayerData[playerid][pItem18]),
		ItemName(gPlayerData[playerid][pItem19type], gPlayerData[playerid][pItem19]), SlotParam6(playerid, 19), ItemWeight(gPlayerData[playerid][pItem19type], gPlayerData[playerid][pItem19]),
		ItemName(gPlayerData[playerid][pItem20type], gPlayerData[playerid][pItem20]), SlotParam6(playerid, 20), ItemWeight(gPlayerData[playerid][pItem20type], gPlayerData[playerid][pItem20]),
		ItemName(gPlayerData[playerid][pItem21type], gPlayerData[playerid][pItem21]), SlotParam6(playerid, 21), ItemWeight(gPlayerData[playerid][pItem21type], gPlayerData[playerid][pItem21]),
		ItemName(gPlayerData[playerid][pItem22type], gPlayerData[playerid][pItem22]), SlotParam6(playerid, 22), ItemWeight(gPlayerData[playerid][pItem22type], gPlayerData[playerid][pItem22]),
		ItemName(gPlayerData[playerid][pItem23type], gPlayerData[playerid][pItem23]), SlotParam6(playerid, 23), ItemWeight(gPlayerData[playerid][pItem23type], gPlayerData[playerid][pItem23]),
		ItemName(gPlayerData[playerid][pItem24type], gPlayerData[playerid][pItem24]), SlotParam6(playerid, 24), ItemWeight(gPlayerData[playerid][pItem24type], gPlayerData[playerid][pItem24]),
		ItemName(gPlayerData[playerid][pItem25type], gPlayerData[playerid][pItem25]), SlotParam6(playerid, 25), ItemWeight(gPlayerData[playerid][pItem25type], gPlayerData[playerid][pItem25]) );
	}
	return wstring;
}

stock ShowPItemsEx(playerid)
{
	static wstring[2048];
	static string2[64];
	
	strdel(wstring, 0, sizeof(wstring));
	strdel(string2, 0, sizeof(string2));
	
	if(gPlayerData[playerid][pVipItem] == 0 && PHaveExpandItem(playerid))
	{
		format(wstring, sizeof(wstring), "1. %s [iloœæ: %d] [waga: %d]\n2. %s [iloœæ: %d] [waga: %d]\n3. %s [iloœæ: %d] [waga: %d]\n4. %s [iloœæ: %d] [waga: %d]\n5. %s [iloœæ: %d] [waga: %d]\n6. %s [iloœæ: %d] [waga: %d]\n7. %s [iloœæ: %d] [waga: %d]\n8. %s [iloœæ: %d] [waga: %d]\n9. %s [iloœæ: %d] [waga: %d]\n10. %s [iloœæ: %d] [waga: %d]\n11. %s [iloœæ: %d] [waga: %d]\n12. %s [iloœæ: %d] [waga: %d]\n13. %s [iloœæ: %d] [waga: %d]\n14. %s [iloœæ: %d] [waga: %d]\n15. %s [iloœæ: %d] [waga: %d]\n",
		ItemName(gPlayerData[playerid][pItem1type], gPlayerData[playerid][pItem1]), SlotParam6(playerid, 1), ItemWeight(gPlayerData[playerid][pItem1type], gPlayerData[playerid][pItem1]),
		ItemName(gPlayerData[playerid][pItem2type], gPlayerData[playerid][pItem2]), SlotParam6(playerid, 2), ItemWeight(gPlayerData[playerid][pItem2type], gPlayerData[playerid][pItem2]),
		ItemName(gPlayerData[playerid][pItem3type], gPlayerData[playerid][pItem3]), SlotParam6(playerid, 3), ItemWeight(gPlayerData[playerid][pItem3type], gPlayerData[playerid][pItem3]),
		ItemName(gPlayerData[playerid][pItem4type], gPlayerData[playerid][pItem4]), SlotParam6(playerid, 4), ItemWeight(gPlayerData[playerid][pItem4type], gPlayerData[playerid][pItem4]),
		ItemName(gPlayerData[playerid][pItem5type], gPlayerData[playerid][pItem5]), SlotParam6(playerid, 5), ItemWeight(gPlayerData[playerid][pItem5type], gPlayerData[playerid][pItem5]),
		ItemName(gPlayerData[playerid][pItem6type], gPlayerData[playerid][pItem6]), SlotParam6(playerid, 6), ItemWeight(gPlayerData[playerid][pItem6type], gPlayerData[playerid][pItem6]),
		ItemName(gPlayerData[playerid][pItem7type], gPlayerData[playerid][pItem7]), SlotParam6(playerid, 7), ItemWeight(gPlayerData[playerid][pItem7type], gPlayerData[playerid][pItem7]),
		ItemName(gPlayerData[playerid][pItem8type], gPlayerData[playerid][pItem8]), SlotParam6(playerid, 8), ItemWeight(gPlayerData[playerid][pItem8type], gPlayerData[playerid][pItem8]),
		ItemName(gPlayerData[playerid][pItem9type], gPlayerData[playerid][pItem9]), SlotParam6(playerid, 9), ItemWeight(gPlayerData[playerid][pItem9type], gPlayerData[playerid][pItem9]),
		ItemName(gPlayerData[playerid][pItem10type], gPlayerData[playerid][pItem10]), SlotParam6(playerid, 10), ItemWeight(gPlayerData[playerid][pItem10type], gPlayerData[playerid][pItem10]),
		ItemName(gPlayerData[playerid][pItem11type], gPlayerData[playerid][pItem11]), SlotParam6(playerid, 11), ItemWeight(gPlayerData[playerid][pItem11type], gPlayerData[playerid][pItem11]),
		ItemName(gPlayerData[playerid][pItem12type], gPlayerData[playerid][pItem12]), SlotParam6(playerid, 12), ItemWeight(gPlayerData[playerid][pItem12type], gPlayerData[playerid][pItem12]),
		ItemName(gPlayerData[playerid][pItem13type], gPlayerData[playerid][pItem13]), SlotParam6(playerid, 13), ItemWeight(gPlayerData[playerid][pItem13type], gPlayerData[playerid][pItem13]),
		ItemName(gPlayerData[playerid][pItem14type], gPlayerData[playerid][pItem14]), SlotParam6(playerid, 14), ItemWeight(gPlayerData[playerid][pItem14type], gPlayerData[playerid][pItem14]),
		ItemName(gPlayerData[playerid][pItem15type], gPlayerData[playerid][pItem15]), SlotParam6(playerid, 15), ItemWeight(gPlayerData[playerid][pItem15type], gPlayerData[playerid][pItem15]) );
		format(string2, sizeof(string2), "Moje itemy - waga ca³kowita %d/%d (kg)", floatround(PItemWeight(playerid)/1000), floatround(gPlayerData[playerid][pMaxWeight]/1000));
		ShowPlayerDialog(playerid,DIALOG_ITEM_1,DIALOG_STYLE_LIST, string2, wstring, "Wybierz", "Zamknij");
	}
	else if(gPlayerData[playerid][pVipItem] == 0 && PHaveExpandItem(playerid) == 0) 
	{
		format(wstring, sizeof(wstring), "1. %s [iloœæ: %d] [waga: %d]\n2. %s [iloœæ: %d] [waga: %d]\n3. %s [iloœæ: %d] [waga: %d]\n4. %s [iloœæ: %d] [waga: %d]\n5. %s [iloœæ: %d] [waga: %d]", 
		ItemName(gPlayerData[playerid][pItem1type], gPlayerData[playerid][pItem1]), SlotParam6(playerid, 1), ItemWeight(gPlayerData[playerid][pItem1type], gPlayerData[playerid][pItem1]),
		ItemName(gPlayerData[playerid][pItem2type], gPlayerData[playerid][pItem2]), SlotParam6(playerid, 2), ItemWeight(gPlayerData[playerid][pItem2type], gPlayerData[playerid][pItem2]),
		ItemName(gPlayerData[playerid][pItem3type], gPlayerData[playerid][pItem3]), SlotParam6(playerid, 3), ItemWeight(gPlayerData[playerid][pItem3type], gPlayerData[playerid][pItem3]),
		ItemName(gPlayerData[playerid][pItem4type], gPlayerData[playerid][pItem4]), SlotParam6(playerid, 4), ItemWeight(gPlayerData[playerid][pItem4type], gPlayerData[playerid][pItem4]),
		ItemName(gPlayerData[playerid][pItem5type], gPlayerData[playerid][pItem5]), SlotParam6(playerid, 5), ItemWeight(gPlayerData[playerid][pItem5type], gPlayerData[playerid][pItem5]) );
		format(string2, sizeof(string2), "Moje itemy - waga ca³kowita %d/%d (kg)", floatround(PItemWeight(playerid)/1000), floatround(gPlayerData[playerid][pMaxWeight]/1000));
		ShowPlayerDialog(playerid,DIALOG_ITEM_1,DIALOG_STYLE_LIST, string2, wstring, "Wybierz", "Zamknij");
	}
	else if(gPlayerData[playerid][pVipItem] > 0)
	{
		format(wstring, sizeof(wstring), "1. %s [iloœæ: %d] [waga: %d]\n2. %s [iloœæ: %d] [waga: %d]\n3. %s [iloœæ: %d] [waga: %d]\n4. %s [iloœæ: %d] [waga: %d]\n5. %s [iloœæ: %d] [waga: %d]\n6. %s [iloœæ: %d] [waga: %d]\n7. %s [iloœæ: %d] [waga: %d]\n8. %s [iloœæ: %d] [waga: %d]\n9. %s [iloœæ: %d] [waga: %d]\n10. %s [iloœæ: %d] [waga: %d]\n11. %s [iloœæ: %d] [waga: %d]\n12. %s [iloœæ: %d] [waga: %d]\n13. %s [iloœæ: %d] [waga: %d]\n14. %s [iloœæ: %d] [waga: %d]\n15. %s [iloœæ: %d] [waga: %d]\n",
		ItemName(gPlayerData[playerid][pItem1type], gPlayerData[playerid][pItem1]), SlotParam6(playerid, 1), ItemWeight(gPlayerData[playerid][pItem1type], gPlayerData[playerid][pItem1]),
		ItemName(gPlayerData[playerid][pItem2type], gPlayerData[playerid][pItem2]), SlotParam6(playerid, 2), ItemWeight(gPlayerData[playerid][pItem2type], gPlayerData[playerid][pItem2]),
		ItemName(gPlayerData[playerid][pItem3type], gPlayerData[playerid][pItem3]), SlotParam6(playerid, 3), ItemWeight(gPlayerData[playerid][pItem3type], gPlayerData[playerid][pItem3]),
		ItemName(gPlayerData[playerid][pItem4type], gPlayerData[playerid][pItem4]), SlotParam6(playerid, 4), ItemWeight(gPlayerData[playerid][pItem4type], gPlayerData[playerid][pItem4]),
		ItemName(gPlayerData[playerid][pItem5type], gPlayerData[playerid][pItem5]), SlotParam6(playerid, 5), ItemWeight(gPlayerData[playerid][pItem5type], gPlayerData[playerid][pItem5]),
		ItemName(gPlayerData[playerid][pItem6type], gPlayerData[playerid][pItem6]), SlotParam6(playerid, 6), ItemWeight(gPlayerData[playerid][pItem6type], gPlayerData[playerid][pItem6]),
		ItemName(gPlayerData[playerid][pItem7type], gPlayerData[playerid][pItem7]), SlotParam6(playerid, 7), ItemWeight(gPlayerData[playerid][pItem7type], gPlayerData[playerid][pItem7]),
		ItemName(gPlayerData[playerid][pItem8type], gPlayerData[playerid][pItem8]), SlotParam6(playerid, 8), ItemWeight(gPlayerData[playerid][pItem8type], gPlayerData[playerid][pItem8]),
		ItemName(gPlayerData[playerid][pItem9type], gPlayerData[playerid][pItem9]), SlotParam6(playerid, 9), ItemWeight(gPlayerData[playerid][pItem9type], gPlayerData[playerid][pItem9]),
		ItemName(gPlayerData[playerid][pItem10type], gPlayerData[playerid][pItem10]), SlotParam6(playerid, 10), ItemWeight(gPlayerData[playerid][pItem10type], gPlayerData[playerid][pItem10]),
		ItemName(gPlayerData[playerid][pItem11type], gPlayerData[playerid][pItem11]), SlotParam6(playerid, 11), ItemWeight(gPlayerData[playerid][pItem11type], gPlayerData[playerid][pItem11]),
		ItemName(gPlayerData[playerid][pItem12type], gPlayerData[playerid][pItem12]), SlotParam6(playerid, 12), ItemWeight(gPlayerData[playerid][pItem12type], gPlayerData[playerid][pItem12]),
		ItemName(gPlayerData[playerid][pItem13type], gPlayerData[playerid][pItem13]), SlotParam6(playerid, 13), ItemWeight(gPlayerData[playerid][pItem13type], gPlayerData[playerid][pItem13]),
		ItemName(gPlayerData[playerid][pItem14type], gPlayerData[playerid][pItem14]), SlotParam6(playerid, 14), ItemWeight(gPlayerData[playerid][pItem14type], gPlayerData[playerid][pItem14]),
		ItemName(gPlayerData[playerid][pItem15type], gPlayerData[playerid][pItem15]), SlotParam6(playerid, 15), ItemWeight(gPlayerData[playerid][pItem15type], gPlayerData[playerid][pItem15]) );
		format(wstring, sizeof(wstring), "%s16. %s [iloœæ: %d] [waga: %d]\n17. %s [iloœæ: %d] [waga: %d]\n18. %s [iloœæ: %d] [waga: %d]\n19. %s [iloœæ: %d] [waga: %d]\n20. %s [iloœæ: %d] [waga: %d]\n21. %s [iloœæ: %d] [waga: %d]\n22. %s [iloœæ: %d] [waga: %d]\n23. %s [iloœæ: %d] [waga: %d]\n24. %s [iloœæ: %d] [waga: %d]\n25. %s [iloœæ: %d] [waga: %d]",
		wstring,
		ItemName(gPlayerData[playerid][pItem16type], gPlayerData[playerid][pItem16]), SlotParam6(playerid, 16), ItemWeight(gPlayerData[playerid][pItem16type], gPlayerData[playerid][pItem16]),
		ItemName(gPlayerData[playerid][pItem17type], gPlayerData[playerid][pItem17]), SlotParam6(playerid, 17), ItemWeight(gPlayerData[playerid][pItem17type], gPlayerData[playerid][pItem17]),
		ItemName(gPlayerData[playerid][pItem18type], gPlayerData[playerid][pItem18]), SlotParam6(playerid, 18), ItemWeight(gPlayerData[playerid][pItem18type], gPlayerData[playerid][pItem18]),
		ItemName(gPlayerData[playerid][pItem19type], gPlayerData[playerid][pItem19]), SlotParam6(playerid, 19), ItemWeight(gPlayerData[playerid][pItem19type], gPlayerData[playerid][pItem19]),
		ItemName(gPlayerData[playerid][pItem20type], gPlayerData[playerid][pItem20]), SlotParam6(playerid, 20), ItemWeight(gPlayerData[playerid][pItem20type], gPlayerData[playerid][pItem20]),
		ItemName(gPlayerData[playerid][pItem21type], gPlayerData[playerid][pItem21]), SlotParam6(playerid, 21), ItemWeight(gPlayerData[playerid][pItem21type], gPlayerData[playerid][pItem21]),
		ItemName(gPlayerData[playerid][pItem22type], gPlayerData[playerid][pItem22]), SlotParam6(playerid, 22), ItemWeight(gPlayerData[playerid][pItem22type], gPlayerData[playerid][pItem22]),
		ItemName(gPlayerData[playerid][pItem23type], gPlayerData[playerid][pItem23]), SlotParam6(playerid, 23), ItemWeight(gPlayerData[playerid][pItem23type], gPlayerData[playerid][pItem23]),
		ItemName(gPlayerData[playerid][pItem24type], gPlayerData[playerid][pItem24]), SlotParam6(playerid, 24), ItemWeight(gPlayerData[playerid][pItem24type], gPlayerData[playerid][pItem24]),
		ItemName(gPlayerData[playerid][pItem25type], gPlayerData[playerid][pItem25]), SlotParam6(playerid, 25), ItemWeight(gPlayerData[playerid][pItem25type], gPlayerData[playerid][pItem25]) );
		format(string2, sizeof(string2), "Moje itemy - waga ca³kowita %d/%d (kg)", floatround(PItemWeight(playerid)/1000), floatround(gPlayerData[playerid][pMaxWeight]/1000));
		ShowPlayerDialog(playerid,DIALOG_ITEM_1,DIALOG_STYLE_LIST, string2, wstring, "Wybierz", "Zamknij");
	}
	gPreviousDialogList[playerid] = -1;
	return 1;
}

EatItem(playerid, type, item)
{
	switch(type)
	{
		case 1:
		{
			switch(item)
			{
				case 9:
				{
					gPlayerData[playerid][pEnergy] += 10.0;
					gPlayerData[playerid][pHunger] -= 30.0;
					gPlayerData[playerid][pThirst] += 0.0;
					gPlayerData[playerid][pPoison] += 2.5;
					gPlayerData[playerid][pFat] += 10.0;
					gPlayerData[playerid][pVitamins] += 0.0;
					gPlayerData[playerid][pStomach] += 25.0;
				}
				case 125:
				{
					gPlayerData[playerid][pEnergy] += 20.0;
					gPlayerData[playerid][pHunger] -= 10.0;
					gPlayerData[playerid][pThirst] -= 50.0;					
					gPlayerData[playerid][pPoison] += 2.5;
					gPlayerData[playerid][pFat] += 5.0;
					gPlayerData[playerid][pVitamins] += 5.0;
					gPlayerData[playerid][pStomach] += 20.0;
				}
				case 126:
				{
					gPlayerData[playerid][pEnergy] += 10.0;
					gPlayerData[playerid][pHunger] -= 10.0;
					gPlayerData[playerid][pThirst] -= 50.0;					
					gPlayerData[playerid][pPoison] += 0.0;
					gPlayerData[playerid][pFat] += 1.0;
					gPlayerData[playerid][pVitamins] += 10.0;
					gPlayerData[playerid][pStomach] += 20.0;
				}
				case 127:
				{
					gPlayerData[playerid][pEnergy] += 10.0;
					gPlayerData[playerid][pHunger] -= 10.0;
					gPlayerData[playerid][pThirst] -= 60.0;					
					gPlayerData[playerid][pPoison] += 0.0;
					gPlayerData[playerid][pFat] += 1.0;
					gPlayerData[playerid][pVitamins] += 5.0;
					gPlayerData[playerid][pStomach] += 20.0;
				}
				case 128:
				{
					gPlayerData[playerid][pEnergy] += 10.0;
					gPlayerData[playerid][pHunger] -= 30.0;
					gPlayerData[playerid][pThirst] += 5.0;					
					gPlayerData[playerid][pPoison] += 2.5;
					gPlayerData[playerid][pFat] += 10.0;
					gPlayerData[playerid][pVitamins] += 0.0;
					gPlayerData[playerid][pStomach] += 25.0;
				}
				case 129:
				{
					gPlayerData[playerid][pEnergy] += 10.0;
					gPlayerData[playerid][pHunger] -= 30.0;
					gPlayerData[playerid][pThirst] += 5.0;					
					gPlayerData[playerid][pPoison] += 2.5;
					gPlayerData[playerid][pFat] += 10.0;
					gPlayerData[playerid][pVitamins] += 0.0;
					gPlayerData[playerid][pStomach] += 25.0;
				}
				case 130:
				{
					gPlayerData[playerid][pEnergy] += 10.0;
					gPlayerData[playerid][pHunger] -= 15.0;
					gPlayerData[playerid][pThirst] -= 40.0;					
					gPlayerData[playerid][pPoison] += 0.0;
					gPlayerData[playerid][pFat] -= 1.0;
					gPlayerData[playerid][pVitamins] += 15.0;
					gPlayerData[playerid][pStomach] += 10.0;
				}
				case 131:
				{
					gPlayerData[playerid][pEnergy] += 10.0;
					gPlayerData[playerid][pHunger] -= 10.0;
					gPlayerData[playerid][pThirst] -= 10.0;					
					gPlayerData[playerid][pPoison] += 0.0;
					gPlayerData[playerid][pFat] -= 0.0;
					gPlayerData[playerid][pVitamins] += 20.0;
					gPlayerData[playerid][pStomach] += 15.0;
				}
				case 132:
				{
					gPlayerData[playerid][pEnergy] += 10.0;
					gPlayerData[playerid][pHunger] -= 10.0;
					gPlayerData[playerid][pThirst] -= 25.0;					
					gPlayerData[playerid][pPoison] += 0.0;
					gPlayerData[playerid][pFat] -= 1.0;
					gPlayerData[playerid][pVitamins] += 25.0;
					gPlayerData[playerid][pStomach] += 10.0;
				}
				case 133:
				{
					gPlayerData[playerid][pEnergy] += 5.0;
					gPlayerData[playerid][pHunger] -= 10.0;
					gPlayerData[playerid][pThirst] -= 40.0;					
					gPlayerData[playerid][pPoison] += 5.0;
					gPlayerData[playerid][pFat] += 10.0;
					gPlayerData[playerid][pVitamins] += 10.0;
					gPlayerData[playerid][pStomach] += 25.0;
				}
				case 134:
				{
					gPlayerData[playerid][pThirst] += 5.0;
					if(gPlayerData[playerid][pDrunk] > 0.0)
					{
						gPlayerData[playerid][pPoison] += 10.0;
						gPlayerData[playerid][pVitamins] -= 20.0;
					}
					gPlayerData[playerid][pPainKiller] += 20;
					SetPlayerDrunkLevel(playerid, 0);	
				}
				case 135:
				{
					gPlayerData[playerid][pThirst] += 20.0;	
					gPlayerData[playerid][pDrunk] -= 15.0;
					gPlayerData[playerid][pPainKiller] += 10;
					SetPlayerDrunkLevel(playerid, 0);
				}
				case 136:
				{
					gPlayerData[playerid][pEnergy] = 100.0;
					gPlayerData[playerid][pHunger] = 0.0;
					gPlayerData[playerid][pThirst] = 0.0;
					gPlayerData[playerid][pVitamins] = 70.0;
					gPlayerData[playerid][pFat] = 50.0;
					gPlayerData[playerid][pStomach] = 9.0;
					gPlayerData[playerid][pDrunk] = 0.0;
					gPlayerData[playerid][pNarcotic] = 0.0;
					gPlayerData[playerid][pPoison] = 0.0;
					SetPlayerDrunkLevel(playerid, 0);
				}
				case 137:
				{
					gPlayerData[playerid][pPoison] -= 20.0;
					gPlayerData[playerid][pStomachDrops] += 60;
					if(gPlayerData[playerid][pStomachDrops] > 120)
						defer PlayerWomit(playerid);
				}
				case 138:
				{
					gPlayerData[playerid][pThirst] += 5.0;
					gPlayerData[playerid][pVitamins] += 10.0;
				}
				case 139:
				{
					gPlayerData[playerid][pThirst] += 30.0;
					gPlayerData[playerid][pFat] -= 10.0;
					gPlayerData[playerid][pSlimming] += 20;
				}
				case 140:
				{
					gPlayerData[playerid][pHunger] += 30.0;
					gPlayerData[playerid][pThirst] += 30.0;
					gPlayerData[playerid][pFat] += 30.0;
				}
				case 141:
				{
					gPlayerData[playerid][pHunger] += 10.0;
					gPlayerData[playerid][pThirst] += 10.0;
					gPlayerData[playerid][pVitamins] -= 10.0;
				}
				case 142:
				{
					gPlayerData[playerid][pEnergy] -= 20.0;
					gPlayerData[playerid][pHunger] += 50.0;
					gPlayerData[playerid][pThirst] += 70.0;
					gPlayerData[playerid][pStomach] -= 60.0;
				}
				case 165:
				{
					gPlayerData[playerid][pNarcotic] += 25.0;
				}
			}
		}
		case 5:
		{
			switch(item)
			{
				case 1:
				{
					gPlayerData[playerid][pEnergy] += 40.0;
					gPlayerData[playerid][pHunger] -= 60.0;
					gPlayerData[playerid][pThirst] += 10.0;					
					gPlayerData[playerid][pPoison] += 2.5;
					gPlayerData[playerid][pFat] += 10.0;
					gPlayerData[playerid][pVitamins] += 5.0;
					gPlayerData[playerid][pStomach] += 40.0;
				}
				case 2:
				{
					gPlayerData[playerid][pEnergy] += 45.0;
					gPlayerData[playerid][pHunger] -= 55.0;
					gPlayerData[playerid][pThirst] += 10.0;					
					gPlayerData[playerid][pPoison] += 2.5;
					gPlayerData[playerid][pFat] += 15.0;
					gPlayerData[playerid][pVitamins] += 5.0;
					gPlayerData[playerid][pStomach] += 45.0;
				}
				case 3:
				{
					gPlayerData[playerid][pEnergy] += 60.0;
					gPlayerData[playerid][pHunger] -= 60.0;
					gPlayerData[playerid][pThirst] += 10.0;					
					gPlayerData[playerid][pPoison] += 7.5;
					gPlayerData[playerid][pFat] += 25.0;
					gPlayerData[playerid][pVitamins] += 5.0;
					gPlayerData[playerid][pStomach] += 55.0;
				}
				case 4:
				{
					gPlayerData[playerid][pEnergy] += 65.0;
					gPlayerData[playerid][pHunger] -= 65.0;
					gPlayerData[playerid][pThirst] += 10.0;					
					gPlayerData[playerid][pPoison] += 12.5;
					gPlayerData[playerid][pFat] += 35.0;
					gPlayerData[playerid][pVitamins] += 5.0;
					gPlayerData[playerid][pStomach] += 60.0;
				}
				case 5:
				{
					gPlayerData[playerid][pEnergy] += 30.0;
					gPlayerData[playerid][pHunger] -= 30.0;
					gPlayerData[playerid][pThirst] += 5.0;					
					gPlayerData[playerid][pPoison] += 0.0;
					gPlayerData[playerid][pFat] += 10.0;
					gPlayerData[playerid][pVitamins] += 5.0;
					gPlayerData[playerid][pStomach] += 30.0;
				}
				case 6:
				{
					gPlayerData[playerid][pEnergy] += 20.0;
					gPlayerData[playerid][pHunger] -= 30.0;
					gPlayerData[playerid][pThirst] -= 15.0;					
					gPlayerData[playerid][pPoison] -= 15.0;
					gPlayerData[playerid][pFat] -= 5.0;
					gPlayerData[playerid][pVitamins] += 10.0;
					gPlayerData[playerid][pStomach] += 45.0;
				}
				case 7:
				{
					gPlayerData[playerid][pEnergy] += 25.0;
					gPlayerData[playerid][pHunger] -= 30.0;
					gPlayerData[playerid][pThirst] += 20.0;					
					gPlayerData[playerid][pPoison] -= 15.0;
					gPlayerData[playerid][pFat] -= 5.0;
					gPlayerData[playerid][pVitamins] += 10.0;
					gPlayerData[playerid][pStomach] += 40.0;
				}
				case 8:
				{
					gPlayerData[playerid][pEnergy] += 50.0;
					gPlayerData[playerid][pHunger] -= 45.0;
					gPlayerData[playerid][pThirst] += 10.0;					
					gPlayerData[playerid][pPoison] += 5.0;
					gPlayerData[playerid][pFat] += 20.0;
					gPlayerData[playerid][pVitamins] -= 10.0;
					gPlayerData[playerid][pStomach] += 50.0;
				}
				case 9:
				{
					gPlayerData[playerid][pEnergy] += 55.0;
					gPlayerData[playerid][pHunger] -= 50.0;
					gPlayerData[playerid][pThirst] += 15.0;					
					gPlayerData[playerid][pPoison] += 7.5;
					gPlayerData[playerid][pFat] += 25.0;
					gPlayerData[playerid][pVitamins] -= 10.0;
					gPlayerData[playerid][pStomach] += 50.0;
				}
				case 10:
				{
					gPlayerData[playerid][pEnergy] += 10.0;
					gPlayerData[playerid][pHunger] -= 10.0;
					gPlayerData[playerid][pThirst] -= 30.0;					
					gPlayerData[playerid][pPoison] += 0.0;
					gPlayerData[playerid][pFat] += 5.0;
					gPlayerData[playerid][pStomach] += 5.0;
					gPlayerData[playerid][pVitamins] += 0.0;
				}
				case 11:
				{
					gPlayerData[playerid][pEnergy] += 55.0;
					gPlayerData[playerid][pHunger] -= 60.0;
					gPlayerData[playerid][pThirst] += 5.0;					
					gPlayerData[playerid][pPoison] += 10.0;
					gPlayerData[playerid][pFat] += 20.0;
					gPlayerData[playerid][pStomach] += 55.0;
					gPlayerData[playerid][pVitamins] += 0.0;
				}
				case 12:
				{
					gPlayerData[playerid][pEnergy] += 30.0;
					gPlayerData[playerid][pHunger] -= 30.0;
					gPlayerData[playerid][pThirst] += 0.0;					
					gPlayerData[playerid][pPoison] += 0.0;
					gPlayerData[playerid][pFat] += 5.0;
					gPlayerData[playerid][pStomach] += 30.0;
					gPlayerData[playerid][pVitamins] += 5.0;
				}
				case 13:
				{
					gPlayerData[playerid][pEnergy] += 50.0;
					gPlayerData[playerid][pHunger] -= 10.0;
					gPlayerData[playerid][pThirst] -= 20.0;					
					gPlayerData[playerid][pPoison] += 7.5;
					gPlayerData[playerid][pFat] -= 0.0;
					gPlayerData[playerid][pStomach] += 10.0;
					gPlayerData[playerid][pVitamins] -= 5.0;
				}
				case 14:
				{
					gPlayerData[playerid][pEnergy] += 45.0;
					gPlayerData[playerid][pHunger] -= 50.0;
					gPlayerData[playerid][pThirst] += 10.0;					
					gPlayerData[playerid][pPoison] += 5.0;
					gPlayerData[playerid][pFat] += 30.0;
					gPlayerData[playerid][pStomach] += 40.0;
					gPlayerData[playerid][pVitamins] -= 5.0;
				}
				case 15:
				{
					gPlayerData[playerid][pEnergy] += 30.0;
					gPlayerData[playerid][pHunger] -= 30.0;
					gPlayerData[playerid][pThirst] += 30.0;					
					gPlayerData[playerid][pPoison] += 2.5;
					gPlayerData[playerid][pFat] += 10.0;
					gPlayerData[playerid][pStomach] += 25.0;
					gPlayerData[playerid][pVitamins] -= 0.0;
				}
				case 16:
				{
					gPlayerData[playerid][pEnergy] += 20.0;
					gPlayerData[playerid][pHunger] -= 20.0;
					gPlayerData[playerid][pThirst] += 0.0;					
					gPlayerData[playerid][pPoison] += 0.0;
					gPlayerData[playerid][pFat] += 10.0;
					gPlayerData[playerid][pStomach] += 10.0;
					gPlayerData[playerid][pVitamins] += 10.0;
				}
				case 17:
				{
					gPlayerData[playerid][pEnergy] += 20.0;
					gPlayerData[playerid][pHunger] -= 30.0;
					gPlayerData[playerid][pThirst] += 5.0;					
					gPlayerData[playerid][pPoison] += 0.0;
					gPlayerData[playerid][pFat] += 15.0;
					gPlayerData[playerid][pStomach] += 25.0;
					gPlayerData[playerid][pVitamins] += 5.0;
				}
				case 18:
				{
					gPlayerData[playerid][pEnergy] += 45.0;
					gPlayerData[playerid][pHunger] -= 45.0;
					gPlayerData[playerid][pThirst] += 20.0;					
					gPlayerData[playerid][pPoison] += 5.0;
					gPlayerData[playerid][pFat] += 20.0;
					gPlayerData[playerid][pStomach] += 40.0;
					gPlayerData[playerid][pVitamins] += 5.0;
				}
				case 19:
				{
					gPlayerData[playerid][pEnergy] += 40.0;
					gPlayerData[playerid][pHunger] -= 50.0;
					gPlayerData[playerid][pThirst] += 15.0;
					gPlayerData[playerid][pPoison] += 2.5;
					gPlayerData[playerid][pFat] += 15.0;
					gPlayerData[playerid][pStomach] += 35.0;
					gPlayerData[playerid][pVitamins] += 0.0;
				}
				case 20:
				{
					gPlayerData[playerid][pEnergy] += 10.0;
					gPlayerData[playerid][pHunger] -= 10.0;
					gPlayerData[playerid][pThirst] -= 50.0;
					gPlayerData[playerid][pPoison] -= 10;
					gPlayerData[playerid][pFat] += 0.0;
					gPlayerData[playerid][pStomach] += 10.0;
					gPlayerData[playerid][pVitamins] += 10.0;
				}
				case 21:
				{
					gPlayerData[playerid][pEnergy] += 10.0;
					gPlayerData[playerid][pHunger] -= 10.0;
					gPlayerData[playerid][pThirst] -= 0.0;
					gPlayerData[playerid][pPoison] -= 13.0;
					gPlayerData[playerid][pFat] -= 10.0;
					gPlayerData[playerid][pStomach] += 10.0;
					gPlayerData[playerid][pVitamins] += 20.0;
				}
				case 22:
				{
					gPlayerData[playerid][pEnergy] += 10.0;
					gPlayerData[playerid][pHunger] -= 10.0;
					gPlayerData[playerid][pThirst] -= 0.0;
					gPlayerData[playerid][pPoison] -= 15.0;
					gPlayerData[playerid][pFat] -= 10.0;
					gPlayerData[playerid][pStomach] += 15.0;
					gPlayerData[playerid][pVitamins] += 20.0;
				}
				case 23:
				{
					gPlayerData[playerid][pEnergy] += 60.0;
					gPlayerData[playerid][pHunger] -= 10.0;
					gPlayerData[playerid][pThirst] -= 20.0;
					gPlayerData[playerid][pPoison] += 7.5;
					gPlayerData[playerid][pFat] -= 0.0;
					gPlayerData[playerid][pStomach] += 10.0;
					gPlayerData[playerid][pVitamins] -= 10.0;
				}
			}
		}
		case 6:
		{
			switch(item)
			{
				case 1:
				{
					gPlayerData[playerid][pEnergy] += 0.0;
					gPlayerData[playerid][pHunger] += 5.0;
					gPlayerData[playerid][pThirst] -= 5.0;					
					gPlayerData[playerid][pPoison] += 0.0;
					gPlayerData[playerid][pFat] += 0.0;
					gPlayerData[playerid][pVitamins] -= 0.0;
					gPlayerData[playerid][pStomach] += 0.0;
					gPlayerData[playerid][pDrunk] += 3.0;
				}
				case 2:
				{
					gPlayerData[playerid][pEnergy] += 0.0;
					gPlayerData[playerid][pHunger] += 5.0;
					gPlayerData[playerid][pThirst] -= 5.0;					
					gPlayerData[playerid][pPoison] += 0.0;
					gPlayerData[playerid][pFat] += 0.0;
					gPlayerData[playerid][pVitamins] -= 0.0;
					gPlayerData[playerid][pStomach] += 0.0;
					gPlayerData[playerid][pDrunk] += 5.0;
				}
				case 3:
				{
					gPlayerData[playerid][pEnergy] += 0.0;
					gPlayerData[playerid][pHunger] += 0.0;
					gPlayerData[playerid][pThirst] -= 0.0;					
					gPlayerData[playerid][pPoison] += 20.0;
					gPlayerData[playerid][pFat] += 0.0;
					gPlayerData[playerid][pVitamins] -= 0.0;
					gPlayerData[playerid][pStomach] += 10.0;
					gPlayerData[playerid][pDrunk] += 25.0;
				}
				case 4:
				{
					gPlayerData[playerid][pEnergy] += 0.0;
					gPlayerData[playerid][pHunger] += 2.0;
					gPlayerData[playerid][pThirst] -= 3.0;					
					gPlayerData[playerid][pPoison] += 0.0;
					gPlayerData[playerid][pFat] += 0.0;
					gPlayerData[playerid][pVitamins] -= 0.0;
					gPlayerData[playerid][pStomach] += 0.0;
					gPlayerData[playerid][pDrunk] += 15.0;
				}
				case 5:
				{
					gPlayerData[playerid][pEnergy] += 0.0;
					gPlayerData[playerid][pHunger] += 1.0;
					gPlayerData[playerid][pThirst] -= 10.0;					
					gPlayerData[playerid][pPoison] += 0.0;
					gPlayerData[playerid][pFat] += 0.0;
					gPlayerData[playerid][pVitamins] -= 0.0;
					gPlayerData[playerid][pStomach] += 0.0;
					gPlayerData[playerid][pDrunk] += 13.0;
				}
				case 6:
				{
					gPlayerData[playerid][pEnergy] += 0.0;
					gPlayerData[playerid][pHunger] += 1.0;
					gPlayerData[playerid][pThirst] -= 5.0;					
					gPlayerData[playerid][pPoison] += 0.0;
					gPlayerData[playerid][pFat] += 0.0;
					gPlayerData[playerid][pVitamins] -= 0.0;
					gPlayerData[playerid][pStomach] += 0.0;
					gPlayerData[playerid][pDrunk] += 11.0;
				}
				case 7:
				{
					gPlayerData[playerid][pEnergy] += 0.0;
					gPlayerData[playerid][pHunger] += 2.0;
					gPlayerData[playerid][pThirst] -= 8.0;					
					gPlayerData[playerid][pPoison] += 0.0;
					gPlayerData[playerid][pFat] += 0.0;
					gPlayerData[playerid][pVitamins] -= 0.0;
					gPlayerData[playerid][pStomach] += 0.0;
					gPlayerData[playerid][pDrunk] += 17.0;
				}
				case 8:
				{
					gPlayerData[playerid][pEnergy] += 0.0;
					gPlayerData[playerid][pHunger] += 2.0;
					gPlayerData[playerid][pThirst] -= 5.0;					
					gPlayerData[playerid][pPoison] += 0.0;
					gPlayerData[playerid][pFat] += 0.0;
					gPlayerData[playerid][pVitamins] -= 0.0;
					gPlayerData[playerid][pStomach] += 0.0;
					gPlayerData[playerid][pDrunk] += 19.0;
				}
			}
		}
	}
	if(IsPlayerVip(playerid))
	{
		if(gPlayerData[playerid][pEnergy] > MAX_ENERGY_VIP)
			gPlayerData[playerid][pEnergy] = MAX_ENERGY_VIP;
		else if(gPlayerData[playerid][pEnergy] < 0.0)
			gPlayerData[playerid][pEnergy] = 0.0;
		if(gPlayerData[playerid][pHunger] > MAX_HUNGER_VIP)
			gPlayerData[playerid][pHunger] = MAX_HUNGER_VIP;
		else if(gPlayerData[playerid][pHunger] < 0.0)
			gPlayerData[playerid][pHunger] = 0.0;
		if(gPlayerData[playerid][pThirst] > MAX_THIRST_VIP)
			gPlayerData[playerid][pThirst] = MAX_THIRST_VIP;
		else if(gPlayerData[playerid][pThirst] < 0.0)
			gPlayerData[playerid][pThirst] = 0.0;
		if(gPlayerData[playerid][pPoison] > MAX_POISON_VIP)
			gPlayerData[playerid][pPoison] = MAX_POISON_VIP;
		else if(gPlayerData[playerid][pPoison] < 0.0)
			gPlayerData[playerid][pPoison] = 0.0;
		if(gPlayerData[playerid][pFat] > MAX_FAT_VIP)
			gPlayerData[playerid][pFat] = MAX_FAT_VIP;
		else if(gPlayerData[playerid][pFat] < 0.0)
			gPlayerData[playerid][pFat] = 0.0;
		if(gPlayerData[playerid][pVitamins] > MAX_VITAMINS_VIP)
			gPlayerData[playerid][pVitamins] = MAX_VITAMINS_VIP;
		else if(gPlayerData[playerid][pVitamins] < 0.0)
			gPlayerData[playerid][pVitamins] = 0.0;
		if(gPlayerData[playerid][pStomach] > MAX_STOMACH_VIP)
			gPlayerData[playerid][pStomach] = MAX_STOMACH_VIP;
		else if(gPlayerData[playerid][pStomach] < 0.0)
			gPlayerData[playerid][pStomach] = 0.0;
	}
	else
	{
		if(gPlayerData[playerid][pEnergy] > MAX_ENERGY)
			gPlayerData[playerid][pEnergy] = MAX_ENERGY;
		else if(gPlayerData[playerid][pEnergy] < 0.0)
			gPlayerData[playerid][pEnergy] = 0.0;
		if(gPlayerData[playerid][pHunger] > MAX_HUNGER)
			gPlayerData[playerid][pHunger] = MAX_HUNGER;
		else if(gPlayerData[playerid][pHunger] < 0.0)
			gPlayerData[playerid][pHunger] = 0.0;
		if(gPlayerData[playerid][pThirst] > MAX_THIRST)
			gPlayerData[playerid][pThirst] = MAX_THIRST;
		else if(gPlayerData[playerid][pThirst] < 0.0)
			gPlayerData[playerid][pThirst] = 0.0;
		if(gPlayerData[playerid][pPoison] > MAX_POISON)
			gPlayerData[playerid][pPoison] = MAX_POISON;
		else if(gPlayerData[playerid][pPoison] < 0.0)
			gPlayerData[playerid][pPoison] = 0.0;
		if(gPlayerData[playerid][pFat] > MAX_FAT)
			gPlayerData[playerid][pFat] = MAX_FAT;
		else if(gPlayerData[playerid][pFat] < 0.0)
			gPlayerData[playerid][pFat] = 0.0;
		if(gPlayerData[playerid][pVitamins] > MAX_VITAMINS)
			gPlayerData[playerid][pVitamins] = MAX_VITAMINS;
		else if(gPlayerData[playerid][pVitamins] < 0.0)
			gPlayerData[playerid][pVitamins] = 0.0;
		if(gPlayerData[playerid][pStomach] > MAX_STOMACH)
			gPlayerData[playerid][pStomach] = MAX_STOMACH;
		else if(gPlayerData[playerid][pStomach] < 0.0)
			gPlayerData[playerid][pStomach] = 0.0;
	}
	SavePlayerData(playerid, "HealthStatus");
	if(gPlayerData[playerid][pShowHealthBars])
	{
		SetProgressBarValue(gPlayerData[playerid][pEnergyProgressBarID], gPlayerData[playerid][pEnergy]);
		UpdateProgressBar(gPlayerData[playerid][pEnergyProgressBarID], playerid);
		SetProgressBarValue(gPlayerData[playerid][pHungerProgressBarID], gPlayerData[playerid][pHunger]);
		UpdateProgressBar(gPlayerData[playerid][pHungerProgressBarID], playerid);
		SetProgressBarValue(gPlayerData[playerid][pThirstProgressBarID], gPlayerData[playerid][pThirst]);
		UpdateProgressBar(gPlayerData[playerid][pThirstProgressBarID], playerid);
		// SetProgressBarValue(gPlayerData[playerid][pPoisonProgressBarID], gPlayerData[playerid][pPoison]);
		// UpdateProgressBar(gPlayerData[playerid][pPoisonProgressBarID], playerid);
		// SetProgressBarValue(gPlayerData[playerid][pFatProgressBarID], gPlayerData[playerid][pFat]);
		// UpdateProgressBar(gPlayerData[playerid][pFatProgressBarID], playerid);
		// SetProgressBarValue(gPlayerData[playerid][pStomachProgressBarID], gPlayerData[playerid][pStomach]);
		// UpdateProgressBar(gPlayerData[playerid][pStomachProgressBarID], playerid);
		// SetProgressBarValue(gPlayerData[playerid][pVitaminsProgressBarID], gPlayerData[playerid][pVitamins]);
		// UpdateProgressBar(gPlayerData[playerid][pVitaminsProgressBarID], playerid);
		// SetProgressBarValue(gPlayerData[playerid][pDrunkProgressBarID], gPlayerData[playerid][pDrunk]);
		// UpdateProgressBar(gPlayerData[playerid][pDrunkProgressBarID], playerid);
		// SetProgressBarValue(gPlayerData[playerid][pNarcoticProgressBarID], gPlayerData[playerid][pNarcotic]);
		// UpdateProgressBar(gPlayerData[playerid][pNarcoticProgressBarID], playerid);
	}
}

stock ShowPVItems(playerid, vehicleid, trunkspace)
{
	new string[1024];
	new string2[128];
	switch(trunkspace)
	{
		case 1:
		{
			format(string, sizeof(string), "1. %s [iloœæ: %d] [waga: %d]",
				ItemName(gVehData[vehicleid-1][VItem1type], gVehData[vehicleid-1][VItem1]), VSlotParam6(vehicleid, 1), ItemWeight(gVehData[vehicleid-1][VItem1type], gVehData[vehicleid-1][VItem1]) );
		}
		case 2:
		{
			format(string, sizeof(string), "1. %s [iloœæ: %d] [waga: %d]\n2. %s [iloœæ: %d] [waga: %d]",
				ItemName(gVehData[vehicleid-1][VItem1type], gVehData[vehicleid-1][VItem1]), VSlotParam6(vehicleid, 1), ItemWeight(gVehData[vehicleid-1][VItem1type], gVehData[vehicleid-1][VItem1]),
				ItemName(gVehData[vehicleid-1][VItem2type], gVehData[vehicleid-1][VItem2]), VSlotParam6(vehicleid, 2), ItemWeight(gVehData[vehicleid-1][VItem2type], gVehData[vehicleid-1][VItem2]) );
		}
		case 3:
		{
			format(string, sizeof(string), "1. %s [iloœæ: %d] [waga: %d]\n2. %s [iloœæ: %d] [waga: %d]\n3. %s [iloœæ: %d] [waga: %d]",
				ItemName(gVehData[vehicleid-1][VItem1type], gVehData[vehicleid-1][VItem1]), VSlotParam6(vehicleid, 1), ItemWeight(gVehData[vehicleid-1][VItem1type], gVehData[vehicleid-1][VItem1]),
				ItemName(gVehData[vehicleid-1][VItem2type], gVehData[vehicleid-1][VItem2]), VSlotParam6(vehicleid, 2), ItemWeight(gVehData[vehicleid-1][VItem2type], gVehData[vehicleid-1][VItem2]),
				ItemName(gVehData[vehicleid-1][VItem3type], gVehData[vehicleid-1][VItem3]), VSlotParam6(vehicleid, 3), ItemWeight(gVehData[vehicleid-1][VItem3type], gVehData[vehicleid-1][VItem3]) );
		}
		case 4:
		{
			format(string, sizeof(string), "1. %s [iloœæ: %d] [waga: %d]\n2. %s [iloœæ: %d] [waga: %d]\n3. %s [iloœæ: %d] [waga: %d]\n4. %s [iloœæ: %d] [waga: %d]",
				ItemName(gVehData[vehicleid-1][VItem1type], gVehData[vehicleid-1][VItem1]), VSlotParam6(vehicleid, 1), ItemWeight(gVehData[vehicleid-1][VItem1type], gVehData[vehicleid-1][VItem1]),
				ItemName(gVehData[vehicleid-1][VItem2type], gVehData[vehicleid-1][VItem2]), VSlotParam6(vehicleid, 2), ItemWeight(gVehData[vehicleid-1][VItem2type], gVehData[vehicleid-1][VItem2]),
				ItemName(gVehData[vehicleid-1][VItem3type], gVehData[vehicleid-1][VItem3]), VSlotParam6(vehicleid, 3), ItemWeight(gVehData[vehicleid-1][VItem3type], gVehData[vehicleid-1][VItem3]),
				ItemName(gVehData[vehicleid-1][VItem4type], gVehData[vehicleid-1][VItem4]), VSlotParam6(vehicleid, 4), ItemWeight(gVehData[vehicleid-1][VItem4type], gVehData[vehicleid-1][VItem4]) );
		}
		case 5:
		{
			format(string, sizeof(string), "1. %s [iloœæ: %d] [waga: %d]\n2. %s [iloœæ: %d] [waga: %d]\n3. %s [iloœæ: %d] [waga: %d]\n4. %s [iloœæ: %d] [waga: %d]\n5. %s [iloœæ: %d] [waga: %d]",
				ItemName(gVehData[vehicleid-1][VItem1type], gVehData[vehicleid-1][VItem1]), VSlotParam6(vehicleid, 1), ItemWeight(gVehData[vehicleid-1][VItem1type], gVehData[vehicleid-1][VItem1]),
				ItemName(gVehData[vehicleid-1][VItem2type], gVehData[vehicleid-1][VItem2]), VSlotParam6(vehicleid, 2), ItemWeight(gVehData[vehicleid-1][VItem2type], gVehData[vehicleid-1][VItem2]),
				ItemName(gVehData[vehicleid-1][VItem3type], gVehData[vehicleid-1][VItem3]), VSlotParam6(vehicleid, 3), ItemWeight(gVehData[vehicleid-1][VItem3type], gVehData[vehicleid-1][VItem3]),
				ItemName(gVehData[vehicleid-1][VItem4type], gVehData[vehicleid-1][VItem4]), VSlotParam6(vehicleid, 4), ItemWeight(gVehData[vehicleid-1][VItem4type], gVehData[vehicleid-1][VItem4]),
				ItemName(gVehData[vehicleid-1][VItem5type], gVehData[vehicleid-1][VItem5]), VSlotParam6(vehicleid, 5), ItemWeight(gVehData[vehicleid-1][VItem5type], gVehData[vehicleid-1][VItem5]) );
		}
		case 6:
		{
			format(string, sizeof(string), "1. %s [iloœæ: %d] [waga: %d]\n2. %s [iloœæ: %d] [waga: %d]\n3. %s [iloœæ: %d] [waga: %d]\n4. %s [iloœæ: %d] [waga: %d]\n5. %s [iloœæ: %d] [waga: %d]\n6. %s [iloœæ: %d] [waga: %d]",
				ItemName(gVehData[vehicleid-1][VItem1type], gVehData[vehicleid-1][VItem1]), VSlotParam6(vehicleid, 1), ItemWeight(gVehData[vehicleid-1][VItem1type], gVehData[vehicleid-1][VItem1]),
				ItemName(gVehData[vehicleid-1][VItem2type], gVehData[vehicleid-1][VItem2]), VSlotParam6(vehicleid, 2), ItemWeight(gVehData[vehicleid-1][VItem2type], gVehData[vehicleid-1][VItem2]),
				ItemName(gVehData[vehicleid-1][VItem3type], gVehData[vehicleid-1][VItem3]), VSlotParam6(vehicleid, 3), ItemWeight(gVehData[vehicleid-1][VItem3type], gVehData[vehicleid-1][VItem3]),
				ItemName(gVehData[vehicleid-1][VItem4type], gVehData[vehicleid-1][VItem4]), VSlotParam6(vehicleid, 4), ItemWeight(gVehData[vehicleid-1][VItem4type], gVehData[vehicleid-1][VItem4]),
				ItemName(gVehData[vehicleid-1][VItem5type], gVehData[vehicleid-1][VItem5]), VSlotParam6(vehicleid, 5), ItemWeight(gVehData[vehicleid-1][VItem5type], gVehData[vehicleid-1][VItem5]),
				ItemName(gVehData[vehicleid-1][VItem6type], gVehData[vehicleid-1][VItem6]), VSlotParam6(vehicleid, 5), ItemWeight(gVehData[vehicleid-1][VItem6type], gVehData[vehicleid-1][VItem6]) );
		}
		case 7:
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
		case 8:
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
		case 9:
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
		case 10:
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
		case 11:
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
		case 12:
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
		case 13:
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
		case 14:
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
		case 15:
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
	}
	format(string2, sizeof(string2), "Moje itemy w schowku - waga ca³kowita %d", VItemWeight(vehicleid));
	ShowPlayerDialog(playerid,DIALOG_VITEM_1,DIALOG_STYLE_LIST,string2,string,"Wybierz","Anuluj");
}

stock BuyDialogItem(playerid, itemType, item)
{
	new slot, tmpValue;
	if(itemType == 3 && item == 15)
	{
		if(PlayerFreeSlotCount(playerid) < 3)
			slot = 0;
		else
		{
			slot = 1;
			tmpValue = random(99999);
			InsertPlayerItemEx(playerid, itemType, item, tmpValue, 0, 0, 0, "Puste", 1);
			InsertPlayerItemEx(playerid, 11, tmpValue, tmpValue, 0, 0, 0, "Puste", 1);
			InsertPlayerItemEx(playerid, 11, tmpValue, tmpValue, 0, 0, 0, "Puste", 1);
		}
	}
	else
		slot = InsertPlayerItemEx(playerid, itemType, item, 0, 0, 0, 0, "Puste", 1);
	if(!slot)
	{
		ShowPlayerDialog(playerid, DIALOG_BUY_2P_MSG, DIALOG_STYLE_MSGBOX, "Niepowodzenie", DIALOG_BUY_4_TXT, "Wróæ", "");
		return 0;
	}
	return 1;
}