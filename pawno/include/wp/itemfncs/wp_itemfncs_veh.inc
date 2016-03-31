/***
*
* File: wp_itemfncs_veh.inc
* Auth: Damian Wojdat
* Date: 13.05.2012
* Desc: Functions related to vehicle items.
*
*************************************************************************************************************/

#include <wp\itemfncs\wp_itemfncs_veh_special>

stock ItemsOnVehicleSlot(itemtype, itemid)
{
	if(itemtype == 1)
	{
		switch(itemid)
		{
			case 1: return 4;
			case 2: return 40;
			case 3: return 1;
			case 4: return 10;
			case 5: return 10;
			case 6: return 20;
			case 7: return 30;
			case 8: return 15;
			case 9: return 40;
			case 10: return 3;
			case 11: return 10;
			case 12: return 25;
			case 13: return 30;
			case 14: return 30;
			case 15: return 15;
			case 16: return 10;
			case 17: return 8;
			case 18: return 10;
			case 19: return 6;
			case 20: return 6;
			case 21: return 6;
			case 22: return 10;
			case 23: return 7;
			case 24: return 5;
			case 25: return 5;
			case 26: return 10;
			case 27: return 5;
			case 28: return 3;
			case 29: return 1;
			case 30: return 1;
			case 31: return 1;
			case 32: return 1;
			case 33: return 15;
			case 34: return 30;
			case 35: return 15;
			case 105: return 15;
			case 106: return 5;
			case 107..121: return 20;
			case 122: return 3;
			case 123..124: return 5;
			case 125: return 18;
			case 126: return 18;
			case 127: return 18;
			case 128: return 45;
			case 129: return 30;
			case 130: return 60;
			case 131: return 54;
			case 132: return 75;
			case 133: return 18;
			case 134..142: return 34;
			case 143: return 10;
			case 144: return 100;
			case 145..150: return 20;
			case 151: return 10;
			case 152: return 10;
			case 153: return 20;
			case 173: return 400;
			case 174: return 5;
			case 175: return 10;
			case 176: return 8;
			case 177: return 4;
			case 178: return 8;
			default: return 100;
		}
	}
	else if(itemtype == 5)
	{
		switch(itemid)
		{
			case 1: return 25;
			case 2: return 25;
			case 3: return 20;
			case 4: return 20;
			case 5: return 25;
			case 6: return 30;
			case 7: return 30;
			case 8: return 40;
			case 9: return 40;
			case 10: return 40;
			case 11: return 25;
			case 12: return 25;
			case 13: return 40;
			case 14: return 25;
			case 15: return 20;
			case 16: return 25;
			case 17: return 25;
			case 18: return 25;
			case 19: return 30;
			case 20: return 40;
			case 21: return 30;
			case 22: return 30;
			case 23: return 40;
			default: return 100;
		}
	}
	else if(itemtype == 6)
	{
		switch(itemid)
		{
			case 1: return 24;
			case 2: return 24;
			case 3: return 15;
			case 4: return 15;
			case 5: return 18;
			case 6: return 15;
			case 7: return 10;
			case 8: return 15;
			default: return 100;
		}
	}
	else if(itemtype == 7)
	{
		switch(itemid)
		{
			case 1..5: return 6;
			default: return 100;
		}
	}
	else if(itemtype == 8)
	{
		switch(itemid)
		{
			case 1..4: return 5;
			case 5..12: return 10;
			case 13..14: return 10;
			case 15..16: return 15;
			case 17..18: return 10;
			case 19..20: return 15;
			case 21..27: return 20;
			case 28..44: return 5;
			case 45: return 4;
			case 46..48: return 5;
			case 49..53: return 5;
			case 54..61: return 10;
			case 62..69: return 10;
			default: return 100;
		}
	}
	else if(itemtype == 9)
	{
		switch(itemid)
		{
			case 1..6: return 10;
			default: return 100;
		}
	}
	return 1;
}	

stock VItemWeight(vid)
{
	new weight = 0;
	weight += ItemWeight(gVehData[vid-1][VItem1type], gVehData[vid-1][VItem1]);
	weight += ItemWeight(gVehData[vid-1][VItem2type], gVehData[vid-1][VItem2]);
	weight += ItemWeight(gVehData[vid-1][VItem3type], gVehData[vid-1][VItem3]);
	weight += ItemWeight(gVehData[vid-1][VItem4type], gVehData[vid-1][VItem4]);
	weight += ItemWeight(gVehData[vid-1][VItem5type], gVehData[vid-1][VItem5]);
	weight += ItemWeight(gVehData[vid-1][VItem6type], gVehData[vid-1][VItem6]);
	weight += ItemWeight(gVehData[vid-1][VItem7type], gVehData[vid-1][VItem7]);
	weight += ItemWeight(gVehData[vid-1][VItem8type], gVehData[vid-1][VItem8]);
	weight += ItemWeight(gVehData[vid-1][VItem9type], gVehData[vid-1][VItem9]);
	weight += ItemWeight(gVehData[vid-1][VItem10type], gVehData[vid-1][VItem10]);
	weight += ItemWeight(gVehData[vid-1][VItem11type], gVehData[vid-1][VItem11]);
	weight += ItemWeight(gVehData[vid-1][VItem12type], gVehData[vid-1][VItem12]);
	weight += ItemWeight(gVehData[vid-1][VItem13type], gVehData[vid-1][VItem13]);
	weight += ItemWeight(gVehData[vid-1][VItem14type], gVehData[vid-1][VItem14]);
	weight += ItemWeight(gVehData[vid-1][VItem15type], gVehData[vid-1][VItem15]);
	return weight;
}

/*
* Count how many items in all slot of given type vehicle can carry
*/
stock VehicleCountMaxItemCarry(vehid, itemtype, itemid)
{
	new itemCanCarryCount = 0;
	for(new i = 0; i < sizeof(CarsLenghts); i++)
	{
		if(CarsLenghts[i][lenghtModel] == gVehData[vehid][mVehModel])
		{
			if(CarsLenghts[i][trunkSpace] >= 1)
			{
				if(gVehData[vehid][VItem1type] == 0)
					itemCanCarryCount += ItemsOnVehicleSlot(itemtype, itemid);
				else if(gVehData[vehid][VItem1type] == itemtype)
					itemCanCarryCount += ItemsOnVehicleSlot(itemtype, itemid) - VSlotParam6(vehid+1, 1);
			}
			else
				return itemCanCarryCount;
			if(CarsLenghts[i][trunkSpace] >= 2)
			{
				if(gVehData[vehid][VItem2type] == 0)
					itemCanCarryCount += ItemsOnVehicleSlot(itemtype, itemid);
				else if(gVehData[vehid][VItem2type] == itemtype)
					itemCanCarryCount += ItemsOnVehicleSlot(itemtype, itemid) - VSlotParam6(vehid+1, 2);
			}
			else
				return itemCanCarryCount;
			if(CarsLenghts[i][trunkSpace] >= 3)
			{
				if(gVehData[vehid][VItem3type] == 0)
					itemCanCarryCount += ItemsOnVehicleSlot(itemtype, itemid);
				else if(gVehData[vehid][VItem3type] == itemtype)
					itemCanCarryCount += ItemsOnVehicleSlot(itemtype, itemid) - VSlotParam6(vehid+1, 3);
			}
			else
				return itemCanCarryCount;
			if(CarsLenghts[i][trunkSpace] >= 4)
			{
				if(gVehData[vehid][VItem4type] == 0)
					itemCanCarryCount += ItemsOnVehicleSlot(itemtype, itemid);
				else if(gVehData[vehid][VItem4type] == itemtype)
					itemCanCarryCount += ItemsOnVehicleSlot(itemtype, itemid) - VSlotParam6(vehid+1, 4);
			}
			else
				return itemCanCarryCount;
			if(CarsLenghts[i][trunkSpace] >= 5)
			{
				if(gVehData[vehid][VItem5type] == 0)
					itemCanCarryCount += ItemsOnVehicleSlot(itemtype, itemid);
				else if(gVehData[vehid][VItem5type] == itemtype)
					itemCanCarryCount += ItemsOnVehicleSlot(itemtype, itemid) - VSlotParam6(vehid+1, 5);
			}
			else
				return itemCanCarryCount;
			if(CarsLenghts[i][trunkSpace] >= 6)
			{
				if(gVehData[vehid][VItem6type] == 0)
					itemCanCarryCount += ItemsOnVehicleSlot(itemtype, itemid);
				else if(gVehData[vehid][VItem6type] == itemtype)
					itemCanCarryCount += ItemsOnVehicleSlot(itemtype, itemid) - VSlotParam6(vehid+1, 6);
			}
			else
				return itemCanCarryCount;
			if(CarsLenghts[i][trunkSpace] >= 7)
			{
				if(gVehData[vehid][VItem7type] == 0)
					itemCanCarryCount += ItemsOnVehicleSlot(itemtype, itemid);
				else if(gVehData[vehid][VItem7type] == itemtype)
					itemCanCarryCount += ItemsOnVehicleSlot(itemtype, itemid) - VSlotParam6(vehid+1, 7);
			}
			else
				return itemCanCarryCount;
			if(CarsLenghts[i][trunkSpace] >= 8)
			{
				if(gVehData[vehid][VItem8type] == 0)
					itemCanCarryCount += ItemsOnVehicleSlot(itemtype, itemid);
				else if(gVehData[vehid][VItem8type] == itemtype)
					itemCanCarryCount += ItemsOnVehicleSlot(itemtype, itemid) - VSlotParam6(vehid+1, 8);
			}
			else
				return itemCanCarryCount;
			if(CarsLenghts[i][trunkSpace] >= 9)
			{
				if(gVehData[vehid][VItem9type] == 0)
					itemCanCarryCount += ItemsOnVehicleSlot(itemtype, itemid);
				else if(gVehData[vehid][VItem9type] == itemtype)
					itemCanCarryCount += ItemsOnVehicleSlot(itemtype, itemid) - VSlotParam6(vehid+1, 9);
			}
			else
				return itemCanCarryCount;
			if(CarsLenghts[i][trunkSpace] >= 10)
			{
				if(gVehData[vehid][VItem10type] == 0)
					itemCanCarryCount += ItemsOnVehicleSlot(itemtype, itemid);
				else if(gVehData[vehid][VItem10type] == itemtype)
					itemCanCarryCount += ItemsOnVehicleSlot(itemtype, itemid) - VSlotParam6(vehid+1, 10);
			}
			else
				return itemCanCarryCount;
			if(CarsLenghts[i][trunkSpace] >= 11)
			{
				if(gVehData[vehid][VItem11type] == 0)
					itemCanCarryCount += ItemsOnVehicleSlot(itemtype, itemid);
				else if(gVehData[vehid][VItem11type] == itemtype)
					itemCanCarryCount += ItemsOnVehicleSlot(itemtype, itemid) - VSlotParam6(vehid+1, 11);
			}
			else
				return itemCanCarryCount;
			if(CarsLenghts[i][trunkSpace] >= 12)
			{
				if(gVehData[vehid][VItem12type] == 0)
					itemCanCarryCount += ItemsOnVehicleSlot(itemtype, itemid);
				else if(gVehData[vehid][VItem12type] == itemtype)
					itemCanCarryCount += ItemsOnVehicleSlot(itemtype, itemid) - VSlotParam6(vehid+1, 12);
			}
			else
				return itemCanCarryCount;
			if(CarsLenghts[i][trunkSpace] >= 13)
			{
				if(gVehData[vehid][VItem13type] == 0)
					itemCanCarryCount += ItemsOnVehicleSlot(itemtype, itemid);
				else if(gVehData[vehid][VItem13type] == itemtype)
					itemCanCarryCount += ItemsOnVehicleSlot(itemtype, itemid) - VSlotParam6(vehid+1, 13);
			}
			else
				return itemCanCarryCount;
			if(CarsLenghts[i][trunkSpace] >= 14)
			{
				if(gVehData[vehid][VItem14type] == 0)
					itemCanCarryCount += ItemsOnVehicleSlot(itemtype, itemid);
				else if(gVehData[vehid][VItem14type] == itemtype)
					itemCanCarryCount += ItemsOnVehicleSlot(itemtype, itemid) - VSlotParam6(vehid+1, 14);
			}
			else
				return itemCanCarryCount;
			if(CarsLenghts[i][trunkSpace] >= 15)
			{
				if(gVehData[vehid][VItem15type] == 0)
					itemCanCarryCount += ItemsOnVehicleSlot(itemtype, itemid);
				else if(gVehData[vehid][VItem15type] == itemtype)
					itemCanCarryCount += ItemsOnVehicleSlot(itemtype, itemid) - VSlotParam6(vehid+1, 15);
			}
			else
				return itemCanCarryCount;
		}
	}
	return itemCanCarryCount;
}

stock VehicleFreeSlotCount(vehid)
{
	new slotcount = 0;
	for(new i = 0; i < sizeof(CarsLenghts); i++)
	{
		if(CarsLenghts[i][lenghtModel] == gVehData[vehid-1][mVehModel])
		{
			if(CarsLenghts[i][trunkSpace] >= 1)
			{
				if(gVehData[vehid-1][VItem1type] == 0)
					slotcount++;
			}
			else
				return slotcount;
			if(CarsLenghts[i][trunkSpace] >= 2)
			{
				if(gVehData[vehid-1][VItem2type] == 0)
					slotcount++;
			}
			else
				return slotcount;
			if(CarsLenghts[i][trunkSpace] >= 3)
			{
				if(gVehData[vehid-1][VItem3type] == 0)
					slotcount++;
			}
			else
				return slotcount;
			if(CarsLenghts[i][trunkSpace] >= 4)
			{
				if(gVehData[vehid-1][VItem4type] == 0)
					slotcount++;
			}
			else
				return slotcount;
			if(CarsLenghts[i][trunkSpace] >= 5)
			{
				if(gVehData[vehid-1][VItem5type] == 0)
					slotcount++;
			}
			else
				return slotcount;
			if(CarsLenghts[i][trunkSpace] >= 6)
			{
				if(gVehData[vehid-1][VItem6type] == 0)
					slotcount++;
			}
			else
				return slotcount;
			if(CarsLenghts[i][trunkSpace] >= 7)
			{
				if(gVehData[vehid-1][VItem7type] == 0)
					slotcount++;
			}
			else
				return slotcount;
			if(CarsLenghts[i][trunkSpace] >= 8)
			{
				if(gVehData[vehid-1][VItem8type] == 0)
					slotcount++;
			}
			else
				return slotcount;
			if(CarsLenghts[i][trunkSpace] >= 9)
			{
				if(gVehData[vehid-1][VItem9type] == 0)
					slotcount++;
			}
			else
				return slotcount;
			if(CarsLenghts[i][trunkSpace] >= 10)
			{
				if(gVehData[vehid-1][VItem10type] == 0)
					slotcount++;
			}
			else
				return slotcount;
			if(CarsLenghts[i][trunkSpace] >= 11)
			{
				if(gVehData[vehid-1][VItem11type] == 0)
					slotcount++;
			}
			else
				return slotcount;
			if(CarsLenghts[i][trunkSpace] >= 12)
			{
				if(gVehData[vehid-1][VItem12type] == 0)
					slotcount++;
			}
			else
				return slotcount;
			if(CarsLenghts[i][trunkSpace] >= 13)
			{
				if(gVehData[vehid-1][VItem13type] == 0)
					slotcount++;
			}
			else
				return slotcount;
			if(CarsLenghts[i][trunkSpace] >= 14)
			{
				if(gVehData[vehid-1][VItem14type] == 0)
					slotcount++;
			}
			else
				return slotcount;
			if(CarsLenghts[i][trunkSpace] >= 15)
			{
				if(gVehData[vehid-1][VItem15type] == 0)
					slotcount++;
			}
			else
				return slotcount;
		}
	}
	return slotcount;
}

/*
* Cleans selected vehicle slot
*/
stock RemoveVehItem(vehid, slot)
{
	switch(slot)
	{
		case 1:
		{
			gVehData[vehid-1][VItem1] = 0;
			gVehData[vehid-1][VItem1type] = 0;
			gVehData[vehid-1][VItem1param] = 0;
			gVehData[vehid-1][VItem1param2] = 0;
			gVehData[vehid-1][VItem1param3] = 0;
			gVehData[vehid-1][VItem1param4] = 0;
			strdel(gVehData[vehid-1][VItem1param5], 0, 64);
			strins(gVehData[vehid-1][VItem1param5], "Puste", 0, 64);
			gVehData[vehid-1][VItem1param6] = 0;
			
			SaveVehData(vehid-1, "Item1a");
		}
		case 2:
		{
			gVehData[vehid-1][VItem2] = 0;
			gVehData[vehid-1][VItem2type] = 0;
			gVehData[vehid-1][VItem2param] = 0;
			gVehData[vehid-1][VItem2param2] = 0;
			gVehData[vehid-1][VItem2param3] = 0;
			gVehData[vehid-1][VItem2param4] = 0;
			strdel(gVehData[vehid-1][VItem2param5], 0, 64);
			strins(gVehData[vehid-1][VItem2param5], "Puste", 0, 64);
			gVehData[vehid-1][VItem2param6] = 0;
			
			SaveVehData(vehid-1, "Item2a");
		}
		case 3:
		{
			gVehData[vehid-1][VItem3] = 0;
			gVehData[vehid-1][VItem3type] = 0;
			gVehData[vehid-1][VItem3param] = 0;
			gVehData[vehid-1][VItem3param2] = 0;
			gVehData[vehid-1][VItem3param3] = 0;
			gVehData[vehid-1][VItem3param4] = 0;
			strdel(gVehData[vehid-1][VItem3param5], 0, 64);
			strins(gVehData[vehid-1][VItem3param5], "Puste", 0, 64);
			gVehData[vehid-1][VItem3param6] = 0;
			
			SaveVehData(vehid-1, "Item3a");
		}
		case 4:
		{
			gVehData[vehid-1][VItem4] = 0;
			gVehData[vehid-1][VItem4type] = 0;
			gVehData[vehid-1][VItem4param] = 0;
			gVehData[vehid-1][VItem4param2] = 0;
			gVehData[vehid-1][VItem4param3] = 0;
			gVehData[vehid-1][VItem4param4] = 0;
			strdel(gVehData[vehid-1][VItem4param5], 0, 64);
			strins(gVehData[vehid-1][VItem4param5], "Puste", 0, 64);
			gVehData[vehid-1][VItem4param6] = 0;
			
			SaveVehData(vehid-1, "Item4a");
		}
		case 5:
		{
			gVehData[vehid-1][VItem5] = 0;
			gVehData[vehid-1][VItem5type] = 0;
			gVehData[vehid-1][VItem5param] = 0;
			gVehData[vehid-1][VItem5param2] = 0;
			gVehData[vehid-1][VItem5param3] = 0;
			gVehData[vehid-1][VItem5param4] = 0;
			strdel(gVehData[vehid-1][VItem5param5], 0, 64);
			strins(gVehData[vehid-1][VItem5param5], "Puste", 0, 64);
			gVehData[vehid-1][VItem5param6] = 0;
			
			SaveVehData(vehid-1, "Item5a");
		}
		case 6:
		{
			gVehData[vehid-1][VItem6] = 0;
			gVehData[vehid-1][VItem6type] = 0;
			gVehData[vehid-1][VItem6param] = 0;
			gVehData[vehid-1][VItem6param2] = 0;
			gVehData[vehid-1][VItem6param3] = 0;
			gVehData[vehid-1][VItem6param4] = 0;
			strdel(gVehData[vehid-1][VItem6param5], 0, 64);
			strins(gVehData[vehid-1][VItem6param5], "Puste", 0, 64);
			gVehData[vehid-1][VItem6param6] = 0;
			
			SaveVehData(vehid-1, "Item6a");
		}
		case 7:
		{
			gVehData[vehid-1][VItem7] = 0;
			gVehData[vehid-1][VItem7type] = 0;
			gVehData[vehid-1][VItem7param] = 0;
			gVehData[vehid-1][VItem7param2] = 0;
			gVehData[vehid-1][VItem7param3] = 0;
			gVehData[vehid-1][VItem7param4] = 0;
			strdel(gVehData[vehid-1][VItem7param5], 0, 64);
			strins(gVehData[vehid-1][VItem7param5], "Puste", 0, 64);
			gVehData[vehid-1][VItem7param6] = 0;
			
			SaveVehData(vehid-1, "Item7a");
		}
		case 8:
		{
			gVehData[vehid-1][VItem8] = 0;
			gVehData[vehid-1][VItem8type] = 0;
			gVehData[vehid-1][VItem8param] = 0;
			gVehData[vehid-1][VItem8param2] = 0;
			gVehData[vehid-1][VItem8param3] = 0;
			gVehData[vehid-1][VItem8param4] = 0;
			strdel(gVehData[vehid-1][VItem8param5], 0, 64);
			strins(gVehData[vehid-1][VItem8param5], "Puste", 0, 64);
			gVehData[vehid-1][VItem8param6] = 0;
			
			SaveVehData(vehid-1, "Item8a");
		}
		case 9:
		{
			gVehData[vehid-1][VItem9] = 0;
			gVehData[vehid-1][VItem9type] = 0;
			gVehData[vehid-1][VItem9param] = 0;
			gVehData[vehid-1][VItem9param2] = 0;
			gVehData[vehid-1][VItem9param3] = 0;
			gVehData[vehid-1][VItem9param4] = 0;
			strdel(gVehData[vehid-1][VItem9param5], 0, 64);
			strins(gVehData[vehid-1][VItem9param5], "Puste", 0, 64);
			gVehData[vehid-1][VItem9param6] = 0;
			
			SaveVehData(vehid-1, "Item9a");
		}
		case 10:
		{
			gVehData[vehid-1][VItem10] = 0;
			gVehData[vehid-1][VItem10type] = 0;
			gVehData[vehid-1][VItem10param] = 0;
			gVehData[vehid-1][VItem10param2] = 0;
			gVehData[vehid-1][VItem10param3] = 0;
			gVehData[vehid-1][VItem10param4] = 0;
			strdel(gVehData[vehid-1][VItem10param5], 0, 64);
			strins(gVehData[vehid-1][VItem10param5], "Puste", 0, 64);
			gVehData[vehid-1][VItem10param6] = 0;
			
			SaveVehData(vehid-1, "Item10a");
		}
		case 11:
		{
			gVehData[vehid-1][VItem11] = 0;
			gVehData[vehid-1][VItem11type] = 0;
			gVehData[vehid-1][VItem11param] = 0;
			gVehData[vehid-1][VItem11param2] = 0;
			gVehData[vehid-1][VItem11param3] = 0;
			gVehData[vehid-1][VItem11param4] = 0;
			strdel(gVehData[vehid-1][VItem11param5], 0, 64);
			strins(gVehData[vehid-1][VItem11param5], "Puste", 0, 64);
			gVehData[vehid-1][VItem11param6] = 0;
			
			SaveVehData(vehid-1, "Item11a");
		}
		case 12:
		{
			gVehData[vehid-1][VItem12] = 0;
			gVehData[vehid-1][VItem12type] = 0;
			gVehData[vehid-1][VItem12param] = 0;
			gVehData[vehid-1][VItem12param2] = 0;
			gVehData[vehid-1][VItem12param3] = 0;
			gVehData[vehid-1][VItem12param4] = 0;
			strdel(gVehData[vehid-1][VItem12param5], 0, 64);
			strins(gVehData[vehid-1][VItem12param5], "Puste", 0, 64);
			gVehData[vehid-1][VItem12param6] = 0;
			
			SaveVehData(vehid-1, "Item12a");
		}
		case 13:
		{
			gVehData[vehid-1][VItem13] = 0;
			gVehData[vehid-1][VItem13type] = 0;
			gVehData[vehid-1][VItem13param] = 0;
			gVehData[vehid-1][VItem13param2] = 0;
			gVehData[vehid-1][VItem13param3] = 0;
			gVehData[vehid-1][VItem13param4] = 0;
			strdel(gVehData[vehid-1][VItem13param5], 0, 64);
			strins(gVehData[vehid-1][VItem13param5], "Puste", 0, 64);
			gVehData[vehid-1][VItem13param6] = 0;
			
			SaveVehData(vehid-1, "Item13a");
		}
		case 14:
		{
			gVehData[vehid-1][VItem14] = 0;
			gVehData[vehid-1][VItem14type] = 0;
			gVehData[vehid-1][VItem14param] = 0;
			gVehData[vehid-1][VItem14param2] = 0;
			gVehData[vehid-1][VItem14param3] = 0;
			gVehData[vehid-1][VItem14param4] = 0;
			strdel(gVehData[vehid-1][VItem14param5], 0, 64);
			strins(gVehData[vehid-1][VItem14param5], "Puste", 0, 64);
			gVehData[vehid-1][VItem14param6] = 0;
			
			SaveVehData(vehid-1, "Item14a");
		}
		case 15:
		{
			gVehData[vehid-1][VItem15] = 0;
			gVehData[vehid-1][VItem15type] = 0;
			gVehData[vehid-1][VItem15param] = 0;
			gVehData[vehid-1][VItem15param2] = 0;
			gVehData[vehid-1][VItem15param3] = 0;
			gVehData[vehid-1][VItem15param4] = 0;
			strdel(gVehData[vehid-1][VItem15param5], 0, 64);
			strins(gVehData[vehid-1][VItem15param5], "Puste", 0, 64);
			gVehData[vehid-1][VItem15param6] = 0;
			
			SaveVehData(vehid-1, "Item15a");
		}
	}
}

/*
* Remove exact amount of item from slot
*/
stock RemoveVehItemEx(vehid, slot, howMuch = 1)
{
	if(VSlotParam6(vehid, slot) <= howMuch)
		RemoveVehItem(vehid, slot);
	else
		SetVSlotParam6(vehid, slot, VSlotParam6(vehid, slot)-howMuch);
	return 1;
}

stock InsertVehItem(vehid, itemtype, itemid, itemparam, itemparam2, itemparam3, itemparam4, itemparam5[] = "Puste", itemparam6 = 1)
{
	new id = -1;
	for(new i = 0; i < sizeof(CarsLenghts); i++)
	{
		if(gVehData[vehid-1][mVehModel] == CarsLenghts[i][lenghtModel])
			id = i;
	}
	if(id == -1)
		return 0;
	new slot, oldSlot = 0, lastSucceedSlot = 0;
	if(itemtype != 3)
	{
		while(itemparam6 > 0 && oldSlot < 15)
		{
			slot = VHaveItem(vehid, itemtype, itemid, oldSlot+1);
			if(slot > 0)
			{
				lastSucceedSlot = oldSlot = slot;
				if(ItemsOnVehicleSlot(itemtype, itemid) - itemparam6 - VSlotParam6(vehid, slot) < 0)
				{
					itemparam6 -= ItemsOnVehicleSlot(itemtype, itemid) - VSlotParam6(vehid, slot);
					SetVSlotParam6(vehid, slot, ItemsOnVehicleSlot(itemtype, itemid));
				}
				else
				{
					SetVSlotParam6(vehid, slot, VSlotParam6(vehid, slot) + itemparam6);
					return slot;
				}
			}
			else 
				oldSlot++;
		}
		if(itemparam6 > 0 && VehicleFreeSlotCount(vehid) == 0)
			return lastSucceedSlot;
	}
	slot = 0;
	lastSucceedSlot = 0;
	while(itemparam6 > 0 && slot < 15)
	{
		slot++;
		if(gVehData[vehid-1][VItem1type] == 0 && CarsLenghts[id][trunkSpace] > 0 && slot == 1)
		{
			gVehData[vehid-1][VItem1] = itemid;
			gVehData[vehid-1][VItem1type] = itemtype;
			gVehData[vehid-1][VItem1param] = itemparam;
			gVehData[vehid-1][VItem1param2] = itemparam2;
			gVehData[vehid-1][VItem1param3] = itemparam3;
			gVehData[vehid-1][VItem1param4] = itemparam4;
			strdel(gVehData[vehid-1][VItem1param5], 0, 64);
			strins(gVehData[vehid-1][VItem1param5], itemparam5, 0, 64);
			if(ItemsOnVehicleSlot(itemtype, itemid) - itemparam6 > 0)
			{
				gVehData[vehid-1][VItem1param6] = itemparam6;
				itemparam6 = 0;
			}
			else
			{
				gVehData[vehid-1][VItem1param6] = ItemsOnVehicleSlot(itemtype, itemid);
				itemparam6 -= ItemsOnVehicleSlot(itemtype, itemid);
			}
			
			SaveVehData(vehid-1, "Item1a");
			
			lastSucceedSlot = 1;
		}
		if(gVehData[vehid-1][VItem2type] == 0 && CarsLenghts[id][trunkSpace] > 1 && slot == 2)
		{
			gVehData[vehid-1][VItem2] = itemid;
			gVehData[vehid-1][VItem2type] = itemtype;
			gVehData[vehid-1][VItem2param] = itemparam;
			gVehData[vehid-1][VItem2param2] = itemparam2;
			gVehData[vehid-1][VItem2param3] = itemparam3;
			gVehData[vehid-1][VItem2param4] = itemparam4;
			strdel(gVehData[vehid-1][VItem2param5], 0, 64);
			strins(gVehData[vehid-1][VItem2param5], itemparam5, 0, 64);
			if(ItemsOnVehicleSlot(itemtype, itemid) - itemparam6 > 0)
			{
				gVehData[vehid-1][VItem2param6] = itemparam6;
				itemparam6 = 0;
			}
			else
			{
				gVehData[vehid-1][VItem2param6] = ItemsOnVehicleSlot(itemtype, itemid);
				itemparam6 -= ItemsOnVehicleSlot(itemtype, itemid);
			}
			
			SaveVehData(vehid-1, "Item2a");
			
			lastSucceedSlot = 2;
		}
		if(gVehData[vehid-1][VItem3type] == 0 && CarsLenghts[id][trunkSpace] > 2 && slot == 3)
		{
			gVehData[vehid-1][VItem3] = itemid;
			gVehData[vehid-1][VItem3type] = itemtype;
			gVehData[vehid-1][VItem3param] = itemparam;
			gVehData[vehid-1][VItem3param2] = itemparam2;
			gVehData[vehid-1][VItem3param3] = itemparam3;
			gVehData[vehid-1][VItem3param4] = itemparam4;
			strdel(gVehData[vehid-1][VItem3param5], 0, 64);
			strins(gVehData[vehid-1][VItem3param5], itemparam5, 0, 64);
			if(ItemsOnVehicleSlot(itemtype, itemid) - itemparam6 > 0)
			{
				gVehData[vehid-1][VItem3param6] = itemparam6;
				itemparam6 = 0;
			}
			else
			{
				gVehData[vehid-1][VItem3param6] = ItemsOnVehicleSlot(itemtype, itemid);
				itemparam6 -= ItemsOnVehicleSlot(itemtype, itemid);
			}
			
			SaveVehData(vehid-1, "Item3a");
			
			lastSucceedSlot = 3;
		}
		if(gVehData[vehid-1][VItem4type] == 0 && CarsLenghts[id][trunkSpace] > 3 && slot == 4)
		{
			gVehData[vehid-1][VItem4] = itemid;
			gVehData[vehid-1][VItem4type] = itemtype;
			gVehData[vehid-1][VItem4param] = itemparam;
			gVehData[vehid-1][VItem4param2] = itemparam2;
			gVehData[vehid-1][VItem4param3] = itemparam3;
			gVehData[vehid-1][VItem4param4] = itemparam4;
			strdel(gVehData[vehid-1][VItem4param5], 0, 64);
			strins(gVehData[vehid-1][VItem4param5], itemparam5, 0, 64);
			if(ItemsOnVehicleSlot(itemtype, itemid) - itemparam6 > 0)
			{
				gVehData[vehid-1][VItem4param6] = itemparam6;
				itemparam6 = 0;
			}
			else
			{
				gVehData[vehid-1][VItem4param6] = ItemsOnVehicleSlot(itemtype, itemid);
				itemparam6 -= ItemsOnVehicleSlot(itemtype, itemid);
			}
			
			SaveVehData(vehid-1, "Item4a");
			
			lastSucceedSlot = 4;
		}
		if(gVehData[vehid-1][VItem5type] == 0 && CarsLenghts[id][trunkSpace] > 4 && slot == 5)
		{
			gVehData[vehid-1][VItem5] = itemid;
			gVehData[vehid-1][VItem5type] = itemtype;
			gVehData[vehid-1][VItem5param] = itemparam;
			gVehData[vehid-1][VItem5param2] = itemparam2;
			gVehData[vehid-1][VItem5param3] = itemparam3;
			gVehData[vehid-1][VItem5param4] = itemparam4;
			strdel(gVehData[vehid-1][VItem5param5], 0, 64);
			strins(gVehData[vehid-1][VItem5param5], itemparam5, 0, 64);
			if(ItemsOnVehicleSlot(itemtype, itemid) - itemparam6 > 0)
			{
				gVehData[vehid-1][VItem5param6] = itemparam6;
				itemparam6 = 0;
			}
			else
			{
				gVehData[vehid-1][VItem5param6] = ItemsOnVehicleSlot(itemtype, itemid);
				itemparam6 -= ItemsOnVehicleSlot(itemtype, itemid);
			}
			
			SaveVehData(vehid-1, "Item5a");
			
			lastSucceedSlot = 5;
		}
		if(gVehData[vehid-1][VItem6type] == 0 && CarsLenghts[id][trunkSpace] > 5 && slot == 6)
		{
			gVehData[vehid-1][VItem6] = itemid;
			gVehData[vehid-1][VItem6type] = itemtype;
			gVehData[vehid-1][VItem6param] = itemparam;
			gVehData[vehid-1][VItem6param2] = itemparam2;
			gVehData[vehid-1][VItem6param3] = itemparam3;
			gVehData[vehid-1][VItem6param4] = itemparam4;
			strdel(gVehData[vehid-1][VItem6param5], 0, 64);
			strins(gVehData[vehid-1][VItem6param5], itemparam5, 0, 64);
			if(ItemsOnVehicleSlot(itemtype, itemid) - itemparam6 > 0)
			{
				gVehData[vehid-1][VItem6param6] = itemparam6;
				itemparam6 = 0;
			}
			else
			{
				gVehData[vehid-1][VItem6param6] = ItemsOnVehicleSlot(itemtype, itemid);
				itemparam6 -= ItemsOnVehicleSlot(itemtype, itemid);
			}
			
			SaveVehData(vehid-1, "Item6a");
			
			lastSucceedSlot = 6;
		}
		if(gVehData[vehid-1][VItem7type] == 0 && CarsLenghts[id][trunkSpace] > 6 && slot == 7)
		{
			gVehData[vehid-1][VItem7] = itemid;
			gVehData[vehid-1][VItem7type] = itemtype;
			gVehData[vehid-1][VItem7param] = itemparam;
			gVehData[vehid-1][VItem7param2] = itemparam2;
			gVehData[vehid-1][VItem7param3] = itemparam3;
			gVehData[vehid-1][VItem7param4] = itemparam4;
			strdel(gVehData[vehid-1][VItem7param5], 0, 64);
			strins(gVehData[vehid-1][VItem7param5], itemparam5, 0, 64);
			if(ItemsOnVehicleSlot(itemtype, itemid) - itemparam6 > 0)
			{
				gVehData[vehid-1][VItem7param6] = itemparam6;
				itemparam6 = 0;
			}
			else
			{
				gVehData[vehid-1][VItem7param6] = ItemsOnVehicleSlot(itemtype, itemid);
				itemparam6 -= ItemsOnVehicleSlot(itemtype, itemid);
			}
			
			SaveVehData(vehid-1, "Item7a");
			
			lastSucceedSlot = 7;
		}
		if(gVehData[vehid-1][VItem8type] == 0 && CarsLenghts[id][trunkSpace] > 7 && slot == 8)
		{
			gVehData[vehid-1][VItem8] = itemid;
			gVehData[vehid-1][VItem8type] = itemtype;
			gVehData[vehid-1][VItem8param] = itemparam;
			gVehData[vehid-1][VItem8param2] = itemparam2;
			gVehData[vehid-1][VItem8param3] = itemparam3;
			gVehData[vehid-1][VItem8param4] = itemparam4;
			strdel(gVehData[vehid-1][VItem8param5], 0, 64);
			strins(gVehData[vehid-1][VItem8param5], itemparam5, 0, 64);
			if(ItemsOnVehicleSlot(itemtype, itemid) - itemparam6 > 0)
			{
				gVehData[vehid-1][VItem8param6] = itemparam6;
				itemparam6 = 0;
			}
			else
			{
				gVehData[vehid-1][VItem8param6] = ItemsOnVehicleSlot(itemtype, itemid);
				itemparam6 -= ItemsOnVehicleSlot(itemtype, itemid);
			}
			
			SaveVehData(vehid-1, "Item8a");
			
			lastSucceedSlot = 8;
		}
		if(gVehData[vehid-1][VItem9type] == 0 && CarsLenghts[id][trunkSpace] > 8 && slot == 9)
		{
			gVehData[vehid-1][VItem9] = itemid;
			gVehData[vehid-1][VItem9type] = itemtype;
			gVehData[vehid-1][VItem9param] = itemparam;
			gVehData[vehid-1][VItem9param2] = itemparam2;
			gVehData[vehid-1][VItem9param3] = itemparam3;
			gVehData[vehid-1][VItem9param4] = itemparam4;
			strdel(gVehData[vehid-1][VItem9param5], 0, 64);
			strins(gVehData[vehid-1][VItem9param5], itemparam5, 0, 64);
			if(ItemsOnVehicleSlot(itemtype, itemid) - itemparam6 > 0)
			{
				gVehData[vehid-1][VItem9param6] = itemparam6;
				itemparam6 = 0;
			}
			else
			{
				gVehData[vehid-1][VItem9param6] = ItemsOnVehicleSlot(itemtype, itemid);
				itemparam6 -= ItemsOnVehicleSlot(itemtype, itemid);
			}
			
			SaveVehData(vehid-1, "Item9a");
			
			lastSucceedSlot = 9;
		}
		if(gVehData[vehid-1][VItem10type] == 0 && CarsLenghts[id][trunkSpace] > 9 && slot == 10)
		{
			gVehData[vehid-1][VItem10] = itemid;
			gVehData[vehid-1][VItem10type] = itemtype;
			gVehData[vehid-1][VItem10param] = itemparam;
			gVehData[vehid-1][VItem10param2] = itemparam2;
			gVehData[vehid-1][VItem10param3] = itemparam3;
			gVehData[vehid-1][VItem10param4] = itemparam4;
			strdel(gVehData[vehid-1][VItem10param5], 0, 64);
			strins(gVehData[vehid-1][VItem10param5], itemparam5, 0, 64);
			if(ItemsOnVehicleSlot(itemtype, itemid) - itemparam6 > 0)
			{
				gVehData[vehid-1][VItem10param6] = itemparam6;
				itemparam6 = 0;
			}
			else
			{
				gVehData[vehid-1][VItem10param6] = ItemsOnVehicleSlot(itemtype, itemid);
				itemparam6 -= ItemsOnVehicleSlot(itemtype, itemid);
			}
			
			SaveVehData(vehid-1, "Item10a");
			
			lastSucceedSlot = 10;
		}
		if(gVehData[vehid-1][VItem11type] == 0 && CarsLenghts[id][trunkSpace] > 10 && slot == 11)
		{
			gVehData[vehid-1][VItem11] = itemid;
			gVehData[vehid-1][VItem11type] = itemtype;
			gVehData[vehid-1][VItem11param] = itemparam;
			gVehData[vehid-1][VItem11param2] = itemparam2;
			gVehData[vehid-1][VItem11param3] = itemparam3;
			gVehData[vehid-1][VItem11param4] = itemparam4;
			strdel(gVehData[vehid-1][VItem11param5], 0, 64);
			strins(gVehData[vehid-1][VItem11param5], itemparam5, 0, 64);
			if(ItemsOnVehicleSlot(itemtype, itemid) - itemparam6 > 0)
			{
				gVehData[vehid-1][VItem11param6] = itemparam6;
				itemparam6 = 0;
			}
			else
			{
				gVehData[vehid-1][VItem11param6] = ItemsOnVehicleSlot(itemtype, itemid);
				itemparam6 -= ItemsOnVehicleSlot(itemtype, itemid);
			}
			
			SaveVehData(vehid-1, "Item11a");
			
			lastSucceedSlot = 11;
		}
		if(gVehData[vehid-1][VItem12type] == 0 && CarsLenghts[id][trunkSpace] > 11 && slot == 12)
		{
			gVehData[vehid-1][VItem12] = itemid;
			gVehData[vehid-1][VItem12type] = itemtype;
			gVehData[vehid-1][VItem12param] = itemparam;
			gVehData[vehid-1][VItem12param2] = itemparam2;
			gVehData[vehid-1][VItem12param3] = itemparam3;
			gVehData[vehid-1][VItem12param4] = itemparam4;
			strdel(gVehData[vehid-1][VItem12param5], 0, 64);
			strins(gVehData[vehid-1][VItem12param5], itemparam5, 0, 64);
			if(ItemsOnVehicleSlot(itemtype, itemid) - itemparam6 > 0)
			{
				gVehData[vehid-1][VItem12param6] = itemparam6;
				itemparam6 = 0;
			}
			else
			{
				gVehData[vehid-1][VItem12param6] = ItemsOnVehicleSlot(itemtype, itemid);
				itemparam6 -= ItemsOnVehicleSlot(itemtype, itemid);
			}
			
			SaveVehData(vehid-1, "Item12a");
			
			lastSucceedSlot = 12;
		}
		if(gVehData[vehid-1][VItem13type] == 0 && CarsLenghts[id][trunkSpace] > 12 && slot == 13)
		{
			gVehData[vehid-1][VItem13] = itemid;
			gVehData[vehid-1][VItem13type] = itemtype;
			gVehData[vehid-1][VItem13param] = itemparam;
			gVehData[vehid-1][VItem13param2] = itemparam2;
			gVehData[vehid-1][VItem13param3] = itemparam3;
			gVehData[vehid-1][VItem13param4] = itemparam4;
			strdel(gVehData[vehid-1][VItem13param5], 0, 64);
			strins(gVehData[vehid-1][VItem13param5], itemparam5, 0, 64);
			if(ItemsOnVehicleSlot(itemtype, itemid) - itemparam6 > 0)
			{
				gVehData[vehid-1][VItem13param6] = itemparam6;
				itemparam6 = 0;
			}
			else
			{
				gVehData[vehid-1][VItem13param6] = ItemsOnVehicleSlot(itemtype, itemid);
				itemparam6 -= ItemsOnVehicleSlot(itemtype, itemid);
			}
			
			SaveVehData(vehid-1, "Item13a");
			
			lastSucceedSlot = 13;
		}
		if(gVehData[vehid-1][VItem14type] == 0 && CarsLenghts[id][trunkSpace] > 13 && slot == 14)
		{
			gVehData[vehid-1][VItem14] = itemid;
			gVehData[vehid-1][VItem14type] = itemtype;
			gVehData[vehid-1][VItem14param] = itemparam;
			gVehData[vehid-1][VItem14param2] = itemparam2;
			gVehData[vehid-1][VItem14param3] = itemparam3;
			gVehData[vehid-1][VItem14param4] = itemparam4;
			strdel(gVehData[vehid-1][VItem14param5], 0, 64);
			strins(gVehData[vehid-1][VItem14param5], itemparam5, 0, 64);
			if(ItemsOnVehicleSlot(itemtype, itemid) - itemparam6 > 0)
			{
				gVehData[vehid-1][VItem14param6] = itemparam6;
				itemparam6 = 0;
			}
			else
			{
				gVehData[vehid-1][VItem14param6] = ItemsOnVehicleSlot(itemtype, itemid);
				itemparam6 -= ItemsOnVehicleSlot(itemtype, itemid);
			}
			
			SaveVehData(vehid-1, "Item14a");
			
			lastSucceedSlot = 14;
		}
		if(gVehData[vehid-1][VItem15type] == 0 && CarsLenghts[id][trunkSpace] > 14 && slot == 15)
		{
			gVehData[vehid-1][VItem15] = itemid;
			gVehData[vehid-1][VItem15type] = itemtype;
			gVehData[vehid-1][VItem15param] = itemparam;
			gVehData[vehid-1][VItem15param2] = itemparam2;
			gVehData[vehid-1][VItem15param3] = itemparam3;
			gVehData[vehid-1][VItem15param4] = itemparam4;
			strdel(gVehData[vehid-1][VItem15param5], 0, 64);
			strins(gVehData[vehid-1][VItem15param5], itemparam5, 0, 64);
			if(ItemsOnVehicleSlot(itemtype, itemid) - itemparam6 > 0)
			{
				gVehData[vehid-1][VItem15param6] = itemparam6;
				itemparam6 = 0;
			}
			else
			{
				gVehData[vehid-1][VItem15param6] = ItemsOnVehicleSlot(itemtype, itemid);
				itemparam6 -= ItemsOnVehicleSlot(itemtype, itemid);
			}
			
			SaveVehData(vehid-1, "Item15a");
			
			lastSucceedSlot = 15;
		}
	}
	return lastSucceedSlot;
}

stock SetVSlotParam6(vehid, slot, value)
{
	switch(slot)
	{
		case 1:
		{
			gVehData[vehid-1][VItem1param6] = value;
			SaveVehData(vehid-1, "Item1param6");
			return 1;
		}
		case 2:
		{
			gVehData[vehid-1][VItem2param6] = value;
			SaveVehData(vehid-1, "Item2param6");
			return 1;
		}
		case 3:
		{
			gVehData[vehid-1][VItem3param6] = value;
			SaveVehData(vehid-1, "Item3param6");
			return 1;
		}
		case 4:
		{
			gVehData[vehid-1][VItem4param6] = value;
			SaveVehData(vehid-1, "Item4param6");
			return 1;
		}
		case 5:
		{
			gVehData[vehid-1][VItem5param6] = value;
			SaveVehData(vehid-1, "Item5param6");
			return 1;
		}
		case 6:
		{
			gVehData[vehid-1][VItem6param6] = value;
			SaveVehData(vehid-1, "Item6param6");
			return 1;
		}
		case 7:
		{
			gVehData[vehid-1][VItem7param6] = value;
			SaveVehData(vehid-1, "Item7param6");
			return 1;
		}
		case 8:
		{
			gVehData[vehid-1][VItem8param6] = value;
			SaveVehData(vehid-1, "Item8param6");
			return 1;
		}
		case 9:
		{
			gVehData[vehid-1][VItem9param6] = value;
			SaveVehData(vehid-1, "Item9param6");
			return 1;
		}
		case 10:
		{
			gVehData[vehid-1][VItem10param6] = value;
			SaveVehData(vehid-1, "Item10param6");
			return 1;
		}
		case 11:
		{
			gVehData[vehid-1][VItem11param6] = value;
			SaveVehData(vehid-1, "Item11param6");
			return 1;
		}
		case 12:
		{
			gVehData[vehid-1][VItem12param6] = value;
			SaveVehData(vehid-1, "Item12param6");
			return 1;
		}
		case 13:
		{
			gVehData[vehid-1][VItem13param6] = value;
			SaveVehData(vehid-1, "Item13param6");
			return 1;
		}
		case 14:
		{
			gVehData[vehid-1][VItem14param6] = value;
			SaveVehData(vehid-1, "Item14param6");
			return 1;
		}
		case 15:
		{
			gVehData[vehid-1][VItem15param6] = value;
			SaveVehData(vehid-1, "Item15param6");
			return 1;
		}
	}
	return 0;
}

stock VSlotParam1(vehid, slot)
{
	switch(slot)
	{
		case 1: return gVehData[vehid-1][VItem1param];
		case 2: return gVehData[vehid-1][VItem2param];
		case 3: return gVehData[vehid-1][VItem3param];
		case 4: return gVehData[vehid-1][VItem4param];
		case 5: return gVehData[vehid-1][VItem5param];
		case 6: return gVehData[vehid-1][VItem6param];
		case 7: return gVehData[vehid-1][VItem7param];
		case 8: return gVehData[vehid-1][VItem8param];
		case 9: return gVehData[vehid-1][VItem9param];
		case 10: return gVehData[vehid-1][VItem10param];
		case 11: return gVehData[vehid-1][VItem11param];
		case 12: return gVehData[vehid-1][VItem12param];
		case 13: return gVehData[vehid-1][VItem13param];
		case 14: return gVehData[vehid-1][VItem14param];
		case 15: return gVehData[vehid-1][VItem15param];
	}
	return 0;
}

stock VSlotParam2(vehid, slot)
{
	switch(slot)
	{
		case 1: return gVehData[vehid-1][VItem1param2];
		case 2: return gVehData[vehid-1][VItem2param2];
		case 3: return gVehData[vehid-1][VItem3param2];
		case 4: return gVehData[vehid-1][VItem4param2];
		case 5: return gVehData[vehid-1][VItem5param2];
		case 6: return gVehData[vehid-1][VItem6param2];
		case 7: return gVehData[vehid-1][VItem7param2];
		case 8: return gVehData[vehid-1][VItem8param2];
		case 9: return gVehData[vehid-1][VItem9param2];
		case 10: return gVehData[vehid-1][VItem10param2];
		case 11: return gVehData[vehid-1][VItem11param2];
		case 12: return gVehData[vehid-1][VItem12param2];
		case 13: return gVehData[vehid-1][VItem13param2];
		case 14: return gVehData[vehid-1][VItem14param2];
		case 15: return gVehData[vehid-1][VItem15param2];
	}
	return 0;
}

stock VSlotParam3(vehid, slot)
{
	switch(slot)
	{
		case 1: return gVehData[vehid-1][VItem1param3];
		case 2: return gVehData[vehid-1][VItem2param3];
		case 3: return gVehData[vehid-1][VItem3param3];
		case 4: return gVehData[vehid-1][VItem4param3];
		case 5: return gVehData[vehid-1][VItem5param3];
		case 6: return gVehData[vehid-1][VItem6param3];
		case 7: return gVehData[vehid-1][VItem7param3];
		case 8: return gVehData[vehid-1][VItem8param3];
		case 9: return gVehData[vehid-1][VItem9param3];
		case 10: return gVehData[vehid-1][VItem10param3];
		case 11: return gVehData[vehid-1][VItem11param3];
		case 12: return gVehData[vehid-1][VItem12param3];
		case 13: return gVehData[vehid-1][VItem13param3];
		case 14: return gVehData[vehid-1][VItem14param3];
		case 15: return gVehData[vehid-1][VItem15param3];
	}
	return 0;
}

stock VSlotParam4(vehid, slot)
{
	switch(slot)
	{
		case 1: return gVehData[vehid-1][VItem1param4];
		case 2: return gVehData[vehid-1][VItem2param4];
		case 3: return gVehData[vehid-1][VItem3param4];
		case 4: return gVehData[vehid-1][VItem4param4];
		case 5: return gVehData[vehid-1][VItem5param4];
		case 6: return gVehData[vehid-1][VItem6param4];
		case 7: return gVehData[vehid-1][VItem7param4];
		case 8: return gVehData[vehid-1][VItem8param4];
		case 9: return gVehData[vehid-1][VItem9param4];
		case 10: return gVehData[vehid-1][VItem10param4];
		case 11: return gVehData[vehid-1][VItem11param4];
		case 12: return gVehData[vehid-1][VItem12param4];
		case 13: return gVehData[vehid-1][VItem13param4];
		case 14: return gVehData[vehid-1][VItem14param4];
		case 15: return gVehData[vehid-1][VItem15param4];
	}
	return 0;
}

stock VSlotParam5(vehid, slot)
{
	switch(slot)
	{
		case 1:
		{
			format(gVSelectedItemP5[vehid], 64, gVehData[vehid][VItem1param5]);
		}
		case 2:
		{
			format(gVSelectedItemP5[vehid], 64, gVehData[vehid][VItem2param5]);
		}
		case 3:
		{
			format(gVSelectedItemP5[vehid], 64, gVehData[vehid][VItem3param5]);
		}
		case 4:
		{
			format(gVSelectedItemP5[vehid], 64, gVehData[vehid][VItem4param5]);
		}
		case 5:
		{
			format(gVSelectedItemP5[vehid], 64, gVehData[vehid][VItem5param5]);
		}
	}
	format(gVSelectedItemP5[vehid], 64, "");
}

stock VSlotParam6(vehid, slot)
{
	switch(slot)
	{
		case 1: return gVehData[vehid-1][VItem1param6];
		case 2: return gVehData[vehid-1][VItem2param6];
		case 3: return gVehData[vehid-1][VItem3param6];
		case 4: return gVehData[vehid-1][VItem4param6];
		case 5: return gVehData[vehid-1][VItem5param6];
		case 6: return gVehData[vehid-1][VItem6param6];
		case 7: return gVehData[vehid-1][VItem7param6];
		case 8: return gVehData[vehid-1][VItem8param6];
		case 9: return gVehData[vehid-1][VItem9param6];
		case 10: return gVehData[vehid-1][VItem10param6];
		case 11: return gVehData[vehid-1][VItem11param6];
		case 12: return gVehData[vehid-1][VItem12param6];
		case 13: return gVehData[vehid-1][VItem13param6];
		case 14: return gVehData[vehid-1][VItem14param6];
		case 15: return gVehData[vehid-1][VItem15param6];
	}
	return 0;
}

/*
* Compare vehicle slot item type with given typedef
*/
stock VSlotItemTypeCompare(vehid, slotid, type)
{
	switch(slotid)
	{
		case 1:
		{
			if(gVehData[vehid-1][VItem1type] == type)
				return 1;
			else
				return 0;
		}
		case 2:
		{
			if(gVehData[vehid-1][VItem2type] == type)
				return 1;
			else
				return 0;
		}
		case 3:
		{
			if(gVehData[vehid-1][VItem3type] == type)
				return 1;
			else
				return 0;
		}
		case 4:
		{
			if(gVehData[vehid-1][VItem4type] == type)
				return 1;
			else
				return 0;
		}
		case 5:
		{
			if(gVehData[vehid-1][VItem5type] == type)
				return 1;
			else
				return 0;
		}
		case 6:
		{
			if(gVehData[vehid-1][VItem6type] == type)
				return 1;
			else
				return 0;
		}
		case 7:
		{
			if(gVehData[vehid-1][VItem7type] == type)
				return 1;
			else
				return 0;
		}
		case 8:
		{
			if(gVehData[vehid-1][VItem8type] == type)
				return 1;
			else
				return 0;
		}
		case 9:
		{
			if(gVehData[vehid-1][VItem9type] == type)
				return 1;
			else
				return 0;
		}
		case 10:
		{
			if(gVehData[vehid-1][VItem10type] == type)
				return 1;
			else
				return 0;
		}
		case 11:
		{
			if(gVehData[vehid-1][VItem11type] == type)
				return 1;
			else
				return 0;
		}
		case 12:
		{
			if(gVehData[vehid-1][VItem12type] == type)
				return 1;
			else
				return 0;
		}
		case 13:
		{
			if(gVehData[vehid-1][VItem13type] == type)
				return 1;
			else
				return 0;
		}
		case 14:
		{
			if(gVehData[vehid-1][VItem14type] == type)
				return 1;
			else
				return 0;
		}
		case 15:
		{
			if(gVehData[vehid-1][VItem15type] == type)
				return 1;
			else
				return 0;
		}
	}
	return 0;
}	

stock VItemSlotStatus(vehid, slot)
{
	if(slot == 1)
	{
		if(gVehData[vehid-1][VItem1type] > 0)
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
		if(gVehData[vehid-1][VItem2type] > 0)
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
		if(gVehData[vehid-1][VItem3type] > 0)
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
		if(gVehData[vehid-1][VItem4type] > 0)
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
		if(gVehData[vehid-1][VItem5type] > 0)
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
		if(gVehData[vehid-1][VItem6type] > 0)
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
		if(gVehData[vehid-1][VItem7type] > 0)
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
		if(gVehData[vehid-1][VItem8type] > 0)
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
		if(gVehData[vehid-1][VItem9type] > 0)
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
		if(gVehData[vehid-1][VItem10type] > 0)
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
		if(gVehData[vehid-1][VItem11type] > 0)
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
		if(gVehData[vehid-1][VItem12type] > 0)
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
		if(gVehData[vehid-1][VItem13type] > 0)
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
		if(gVehData[vehid-1][VItem14type] > 0)
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
		if(gVehData[vehid-1][VItem15type] > 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	return 1;
}

stock VHaveItem(vehid, itemtype, itemid, startSlot = 1)
{
	new id = -1;
	for(new i = 0; i < sizeof(CarsLenghts); i++)
	{
		if( gVehData[vehid-1][mVehModel] == CarsLenghts[i][lenghtModel] )
			id = i;
	}
	if( id == -1 )
		return 0;
	if(startSlot == 1)
	{
		if(gVehData[vehid-1][VItem1type] == itemtype && CarsLenghts[id][trunkSpace] > 0)
		{
			if(gVehData[vehid-1][VItem1] == itemid)
			{
				return 1;
			}
		}
	}
	if(startSlot <= 2)
	{
		if(gVehData[vehid-1][VItem2type] == itemtype && CarsLenghts[id][trunkSpace] > 1)
		{
			if(gVehData[vehid-1][VItem2] == itemid)
			{
				return 2;
			}
		}
	}
	if(startSlot <= 3)
	{
		if(gVehData[vehid-1][VItem3type] == itemtype && CarsLenghts[id][trunkSpace] > 2)
		{
			if(gVehData[vehid-1][VItem3] == itemid)
			{
				return 3;
			}
		}
	}
	if(startSlot <= 4)
	{
		if(gVehData[vehid-1][VItem4type] == itemtype && CarsLenghts[id][trunkSpace] > 3)
		{
			if(gVehData[vehid-1][VItem4] == itemid)
			{
				return 4;
			}
		}
	}
	if(startSlot <= 5)
	{
		if(gVehData[vehid-1][VItem5type] == itemtype && CarsLenghts[id][trunkSpace] > 4)
		{
			if(gVehData[vehid-1][VItem5] == itemid)
			{
				return 5;
			}
		}
	}
	if(startSlot <= 6)
	{
		if(gVehData[vehid-1][VItem6type] == itemtype && CarsLenghts[id][trunkSpace] > 5)
		{
			if(gVehData[vehid-1][VItem6] == itemid)
			{
				return 6;
			}
		}
	}
	if(startSlot <= 7)
	{
		if(gVehData[vehid-1][VItem7type] == itemtype && CarsLenghts[id][trunkSpace] > 6)
		{
			if(gVehData[vehid-1][VItem7] == itemid)
			{
				return 7;
			}
		}
	}
	if(startSlot <= 8)
	{
		if(gVehData[vehid-1][VItem8type] == itemtype && CarsLenghts[id][trunkSpace] > 7)
		{
			if(gVehData[vehid-1][VItem8] == itemid)
			{
				return 8;
			}
		}
	}
	if(startSlot <= 9)
	{
		if(gVehData[vehid-1][VItem9type] == itemtype && CarsLenghts[id][trunkSpace] > 8)
		{
			if(gVehData[vehid-1][VItem9] == itemid)
			{
				return 9;
			}
		}
	}
	if(startSlot <= 10)
	{
		if(gVehData[vehid-1][VItem10type] == itemtype && CarsLenghts[id][trunkSpace] > 9)
		{
			if(gVehData[vehid-1][VItem10] == itemid)
			{
				return 10;
			}
		}
	}
	if(startSlot <= 11)
	{
		if(gVehData[vehid-1][VItem11type] == itemtype && CarsLenghts[id][trunkSpace] > 10)
		{
			if(gVehData[vehid-1][VItem11] == itemid)
			{
				return 11;
			}
		}
	}
	if(startSlot <= 12)
	{
		if(gVehData[vehid-1][VItem12type] == itemtype && CarsLenghts[id][trunkSpace] > 11)
		{
			if(gVehData[vehid-1][VItem12] == itemid)
			{
				return 12;
			}
		}
	}
	if(startSlot <= 13)
	{
		if(gVehData[vehid-1][VItem13type] == itemtype && CarsLenghts[id][trunkSpace] > 12)
		{
			if(gVehData[vehid-1][VItem13] == itemid)
			{
				return 13;
			}
		}
	}
	if(startSlot <= 14)
	{
		if(gVehData[vehid-1][VItem14type] == itemtype && CarsLenghts[id][trunkSpace] > 13)
		{
			if(gVehData[vehid-1][VItem14] == itemid)
			{
				return 14;
			}
		}
	}
	if(startSlot <= 15)
	{
		if(gVehData[vehid-1][VItem15type] == itemtype && CarsLenghts[id][trunkSpace] > 14)
		{
			if(gVehData[vehid-1][VItem15] == itemid)
			{
				return 15;
			}
		}
	}
	return 0;
}

stock VHaveItemEx(vehid, itemtype, itemid, slots[MAX_VEHICLE_ITEM_SLOT])
{
	if(gVehData[vehid][VItem1type] == itemtype)
	{
		if(gVehData[vehid][VItem1] == itemid || itemid == -1)
			slots[0] = 1;
		else
			slots[0] = 0;
	}
	if(gVehData[vehid][VItem2type] == itemtype)
	{
		if(gVehData[vehid][VItem2] == itemid || itemid == -1)
			slots[1] = 1;
		else
			slots[1] = 0;
	}
	if(gVehData[vehid][VItem3type] == itemtype)
	{
		if(gVehData[vehid][VItem3] == itemid || itemid == -1)
			slots[2] = 1;
		else
			slots[2] = 0;
	}
	if(gVehData[vehid][VItem4type] == itemtype)
	{
		if(gVehData[vehid][VItem4] == itemid || itemid == -1)
			slots[3] = 1;
		else
			slots[3] = 0;
	}
	if(gVehData[vehid][VItem5type] == itemtype)
	{
		if(gVehData[vehid][VItem5] == itemid || itemid == -1)
			slots[4] = 1;
		else
			slots[4] = 0;
	}
	if(gVehData[vehid][VItem6type] == itemtype)
	{
		if(gVehData[vehid][VItem6] == itemid || itemid == -1)
			slots[5] = 1;
		else
			slots[5] = 0;
	}
	if(gVehData[vehid][VItem7type] == itemtype)
	{
		if(gVehData[vehid][VItem7] == itemid || itemid == -1)
			slots[6] = 1;
		else
			slots[6] = 0;
	}
	if(gVehData[vehid][VItem8type] == itemtype)
	{
		if(gVehData[vehid][VItem8] == itemid || itemid == -1)
			slots[7] = 1;
		else
			slots[7] = 0;
	}
	if(gVehData[vehid][VItem9type] == itemtype)
	{
		if(gVehData[vehid][VItem9] == itemid || itemid == -1)
			slots[8] = 1;
		else
			slots[8] = 0;
	}
	if(gVehData[vehid][VItem10type] == itemtype)
	{
		if(gVehData[vehid][VItem10] == itemid || itemid == -1)
			slots[9] = 1;
		else
			slots[9] = 0;
	}
	if(gVehData[vehid][VItem11type] == itemtype)
	{
		if(gVehData[vehid][VItem11] == itemid || itemid == -1)
			slots[10] = 1;
		else
			slots[10] = 0;
	}
	if(gVehData[vehid][VItem12type] == itemtype)
	{
		if(gVehData[vehid][VItem12] == itemid || itemid == -1)
			slots[11] = 1;
		else
			slots[11] = 0;
	}
	if(gVehData[vehid][VItem13type] == itemtype)
	{
		if(gVehData[vehid][VItem13] == itemid || itemid == -1)
			slots[12] = 1;
		else
			slots[12] = 0;
	}
	if(gVehData[vehid][VItem14type] == itemtype)
	{
		if(gVehData[vehid][VItem14] == itemid || itemid == -1)
			slots[13] = 1;
		else
			slots[13] = 0;
	}
	if(gVehData[vehid][VItem15type] == itemtype)
	{
		if(gVehData[vehid][VItem15] == itemid || itemid == -1)
			slots[14] = 1;
		else
			slots[14] = 0;
	}
	return slots;
}

