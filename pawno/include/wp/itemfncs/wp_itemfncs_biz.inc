/***
*
* File: wp_itemfncs_biz.inc
* Auth: Damian Wojdat
* Date: 13.05.2012
* Desc: Functions related to business items.
*
*************************************************************************************************************/

stock ItemsOnBizSlot(itemtype, itemid)
{
	if(itemtype == 1)
	{
		switch(itemid)
		{
			case 1: return 15;
			case 2: return 100;
			case 3: return 1;
			case 4: return 20;
			case 5: return 20;
			case 6: return 30;
			case 7: return 35;
			case 8: return 20;
			case 9: return 50;
			case 10: return 5;
			case 11: return 10;
			case 12: return 30;
			case 105: return 20;
			case 106: return 10;
			case 107..121: return 30;
			case 122: return 10;
			case 123: return 15;
			case 124: return 15;
			case 125: return 60;
			case 126: return 60;
			case 127: return 60;
			case 128: return 100;
			case 129: return 80;
			case 130: return 150;
			case 131: return 130;
			case 132: return 150;
			case 133: return 60;
			case 134..142: return 40;		
			case 143: return 15;
			case 145..150: return 30;
			case 151: return 15;	
			case 152: return 15;
			case 153: return 30;			
			default: return 1;
		}
	}
	else if(itemtype == 3)
	{
		switch(itemid)
		{
			case 1: return 5;
			case 2: return 30;
			case 3: return 45;
			case 4: return 45;
			case 8: return 8;
			case 12: return 35;
			case 13: return 30;
			case 14: return 50;
			case 15: return 10;
			case 20: return 30;
			default: return 1;
		}
	}
	else if(itemtype == 5)
	{
		switch(itemid)
		{
			case 1: return 80;
			case 2: return 80;
			case 3: return 60;
			case 4: return 60;
			case 5: return 80;
			case 6: return 100;
			case 7: return 100;
			case 8: return 120;
			case 9: return 110;
			case 10: return 110;
			case 11: return 80;
			case 12: return 80;
			case 13: return 110;
			case 14: return 80;
			case 15: return 90;
			case 16: return 100;
			case 17: return 100;
			case 18: return 100;
			case 19: return 100;
			case 20: return 110;
			case 21: return 100;
			case 22: return 110;
			case 23: return 100;
			default: return 100;
		}
	}
	else if(itemtype == 6)
	{
		switch(itemid)
		{
			case 1: return 72;
			case 2: return 72;
			case 3: return 45;
			case 4: return 45;
			case 5: return 48;
			case 6: return 45;
			case 7: return 40;
			case 8: return 45;
			default: return 50;
		}
	}
	else if(itemtype == 7)
	{
		switch(itemid)
		{
			case 1..5: return 20;
			default: return 100;
		}
	}
	else if(itemtype == 8)
	{
		return 10;
	}
	else if(itemtype == 9)
	{
		return 10;
	}
	return 1;
}

stock InsertBizItem(bizid, itemtype, itemid, itemparam6 = 1)
{
	new slot, oldSlot = 0, lastSucceedSlot = 0;
	while(itemparam6 > 0 && oldSlot < 15)
	{
		slot = BizHaveItem(bizid, itemtype, itemid, oldSlot+1);
		if(slot > 0)
		{
			lastSucceedSlot = oldSlot = slot;
			if(ItemsOnBizSlot(itemtype, itemid) - itemparam6 - BizItemSlotCount(bizid, slot) < 0)
			{
				itemparam6 -= ItemsOnBizSlot(itemtype, itemid) - BizItemSlotCount(bizid, slot);
				SetBizItemSlotCount(bizid, slot, ItemsOnBizSlot(itemtype, itemid));
			}
			else
			{
				SetBizItemSlotCount(bizid, slot, BizItemSlotCount(bizid, slot) + itemparam6);
				return slot;
			}
		}
		else 
			oldSlot++;
	}
	return lastSucceedSlot;
}

stock BizRemoveItemFromSlot(bizid, slot, count = 1)
{
	switch(slot)
	{
		case 1:
		{
			Businesses[bizid][Product1count] -= count;
			SaveBizData(bizid, "Product1count");
		}
		case 2:
		{
			Businesses[bizid][Product2count] -= count;
			SaveBizData(bizid, "Product2count");
		}
		case 3:
		{
			Businesses[bizid][Product3count] -= count;
			SaveBizData(bizid, "Product3count");
		}
		case 4:
		{
			Businesses[bizid][Product4count] -= count;
			SaveBizData(bizid, "Product4count");
		}
		case 5:
		{
			Businesses[bizid][Product5count] -= count;
			SaveBizData(bizid, "Product5count");
		}
		case 6:
		{
			Businesses[bizid][Product6count] -= count;
			SaveBizData(bizid, "Product6count");
		}
		case 7:
		{
			Businesses[bizid][Product7count] -= count;
			SaveBizData(bizid, "Product7count");
		}
		case 8:
		{
			Businesses[bizid][Product8count] -= count;
			SaveBizData(bizid, "Product8count");
		}
		case 9:
		{
			Businesses[bizid][Product9count] -= count;
			SaveBizData(bizid, "Product9count");
		}
		case 10:
		{
			Businesses[bizid][Product10count] -= count;
			SaveBizData(bizid, "Product10count");
		}
	}
}

stock BizHaveItem(bizid, itemtype, itemid, startSlot = 1)
{
	if(startSlot == 1)
	{
		if(Businesses[bizid][Product1type] == itemtype)
		{
			if(Businesses[bizid][Product1] == itemid)
			{
				return 1;
			}
		}
	}
	if(startSlot == 2)
	{
		if(Businesses[bizid][Product2type] == itemtype)
		{
			if(Businesses[bizid][Product2] == itemid)
			{
				return 2;
			}
		}
	}
	if(startSlot == 3)
	{
		if(Businesses[bizid][Product3type] == itemtype)
		{
			if(Businesses[bizid][Product3] == itemid)
			{
				return 3;
			}
		}
	}
	if(startSlot == 4)
	{
		if(Businesses[bizid][Product4type] == itemtype)
		{
			if(Businesses[bizid][Product4] == itemid)
			{
				return 4;
			}
		}
	}
	if(startSlot == 5)
	{
		if(Businesses[bizid][Product5type] == itemtype)
		{
			if(Businesses[bizid][Product5] == itemid)
			{
				return 5;
			}
		}
	}
	if(startSlot == 6)
	{
		if(Businesses[bizid][Product6type] == itemtype)
		{
			if(Businesses[bizid][Product6] == itemid)
			{
				return 6;
			}
		}
	}
	if(startSlot == 7)
	{
		if(Businesses[bizid][Product7type] == itemtype)
		{
			if(Businesses[bizid][Product7] == itemid)
			{
				return 7;
			}
		}
	}
	if(startSlot == 8)
	{
		if(Businesses[bizid][Product8type] == itemtype)
		{
			if(Businesses[bizid][Product8] == itemid)
			{
				return 8;
			}
		}
	}
	if(startSlot == 9)
	{
		if(Businesses[bizid][Product9type] == itemtype)
		{
			if(Businesses[bizid][Product9] == itemid)
			{
				return 9;
			}
		}
	}
	if(startSlot == 10)
	{
		if(Businesses[bizid][Product10type] == itemtype)
		{
			if(Businesses[bizid][Product10] == itemid)
			{
				return 10;
			}
		}
	}
	return 0;
}

stock BizHaveItemType(bizid, itemtype, itemid)
{
	if(Businesses[bizid][Product1type] == itemtype && Businesses[bizid][Product1] == itemid)
		return 1;
	if(Businesses[bizid][Product2type] == itemtype && Businesses[bizid][Product2] == itemid)
		return 2;
	if(Businesses[bizid][Product3type] == itemtype && Businesses[bizid][Product3] == itemid)
		return 3;
	if(Businesses[bizid][Product4type] == itemtype && Businesses[bizid][Product4] == itemid)
		return 4;
	if(Businesses[bizid][Product5type] == itemtype && Businesses[bizid][Product5] == itemid)
		return 5;
	if(Businesses[bizid][Product6type] == itemtype && Businesses[bizid][Product6] == itemid)
		return 6;
	if(Businesses[bizid][Product7type] == itemtype && Businesses[bizid][Product7] == itemid)
		return 7;
	if(Businesses[bizid][Product8type] == itemtype && Businesses[bizid][Product8] == itemid)
		return 8;
	if(Businesses[bizid][Product9type] == itemtype && Businesses[bizid][Product9] == itemid)
		return 9;
	if(Businesses[bizid][Product10type] == itemtype && Businesses[bizid][Product10] == itemid)
		return 10;
	return 0;
}	

/*
* Count how many items in all slot of given type business can carry
*/
stock BizCountMaxItemCarry(bizid, itemtype, itemid)
{
	new itemCanCarryCount = 0;
	if(Businesses[bizid][Product1type] == itemtype && Businesses[bizid][Product1] == itemid)
		itemCanCarryCount += ItemsOnBizSlot(itemtype, itemid) - BizItemSlotCount(bizid, 1);
	if(Businesses[bizid][Product2type] == itemtype && Businesses[bizid][Product2] == itemid)
		itemCanCarryCount += ItemsOnBizSlot(itemtype, itemid) - BizItemSlotCount(bizid, 2);
	if(Businesses[bizid][Product3type] == itemtype && Businesses[bizid][Product3] == itemid)
		itemCanCarryCount += ItemsOnBizSlot(itemtype, itemid) - BizItemSlotCount(bizid, 3);
	if(Businesses[bizid][Product4type] == itemtype && Businesses[bizid][Product4] == itemid)
		itemCanCarryCount += ItemsOnBizSlot(itemtype, itemid) - BizItemSlotCount(bizid, 4);
	if(Businesses[bizid][Product5type] == itemtype && Businesses[bizid][Product5] == itemid)
		itemCanCarryCount += ItemsOnBizSlot(itemtype, itemid) - BizItemSlotCount(bizid, 5);
	if(Businesses[bizid][Product6type] == itemtype && Businesses[bizid][Product6] == itemid)
		itemCanCarryCount += ItemsOnBizSlot(itemtype, itemid) - BizItemSlotCount(bizid, 6);
	if(Businesses[bizid][Product7type] == itemtype && Businesses[bizid][Product7] == itemid)
		itemCanCarryCount += ItemsOnBizSlot(itemtype, itemid) - BizItemSlotCount(bizid, 7);
	if(Businesses[bizid][Product8type] == itemtype && Businesses[bizid][Product8] == itemid)
		itemCanCarryCount += ItemsOnBizSlot(itemtype, itemid) - BizItemSlotCount(bizid, 8);
	if(Businesses[bizid][Product9type] == itemtype && Businesses[bizid][Product9] == itemid)
		itemCanCarryCount += ItemsOnBizSlot(itemtype, itemid) - BizItemSlotCount(bizid, 9);
	if(Businesses[bizid][Product10type] == itemtype && Businesses[bizid][Product10] == itemid)
		itemCanCarryCount += ItemsOnBizSlot(itemtype, itemid) - BizItemSlotCount(bizid, 10);	
	return itemCanCarryCount;
}

stock BizFreeSlotCount(vehid)
{
	new slotcount = 0;
	for(new i = 0; i < sizeof(CarsLenghts); i++)
	{
		if(CarsLenghts[i][lenghtModel] == gVehData[vehid][mVehModel])
		{
			if(CarsLenghts[i][trunkSpace] >= 1)
			{
				if(gVehData[vehid][VItem1type] == 0)
					slotcount++;
			}
			else
				return slotcount;
			if(CarsLenghts[i][trunkSpace] >= 2)
			{
				if(gVehData[vehid][VItem2type] == 0)
					slotcount++;
			}
			else
				return slotcount;
			if(CarsLenghts[i][trunkSpace] >= 3)
			{
				if(gVehData[vehid][VItem3type] == 0)
					slotcount++;
			}
			else
				return slotcount;
			if(CarsLenghts[i][trunkSpace] >= 4)
			{
				if(gVehData[vehid][VItem4type] == 0)
					slotcount++;
			}
			else
				return slotcount;
			if(CarsLenghts[i][trunkSpace] >= 5)
			{
				if(gVehData[vehid][VItem5type] == 0)
					slotcount++;
			}
			else
				return slotcount;
			if(CarsLenghts[i][trunkSpace] >= 6)
			{
				if(gVehData[vehid][VItem6type] == 0)
					slotcount++;
			}
			else
				return slotcount;
			if(CarsLenghts[i][trunkSpace] >= 7)
			{
				if(gVehData[vehid][VItem7type] == 0)
					slotcount++;
			}
			else
				return slotcount;
			if(CarsLenghts[i][trunkSpace] >= 8)
			{
				if(gVehData[vehid][VItem8type] == 0)
					slotcount++;
			}
			else
				return slotcount;
			if(CarsLenghts[i][trunkSpace] >= 9)
			{
				if(gVehData[vehid][VItem9type] == 0)
					slotcount++;
			}
			else
				return slotcount;
			if(CarsLenghts[i][trunkSpace] >= 10)
			{
				if(gVehData[vehid][VItem10type] == 0)
					slotcount++;
			}
			else
				return slotcount;
			if(CarsLenghts[i][trunkSpace] >= 11)
			{
				if(gVehData[vehid][VItem11type] == 0)
					slotcount++;
			}
			else
				return slotcount;
			if(CarsLenghts[i][trunkSpace] >= 12)
			{
				if(gVehData[vehid][VItem12type] == 0)
					slotcount++;
			}
			else
				return slotcount;
			if(CarsLenghts[i][trunkSpace] >= 13)
			{
				if(gVehData[vehid][VItem13type] == 0)
					slotcount++;
			}
			else
				return slotcount;
			if(CarsLenghts[i][trunkSpace] >= 14)
			{
				if(gVehData[vehid][VItem14type] == 0)
					slotcount++;
			}
			else
				return slotcount;
			if(CarsLenghts[i][trunkSpace] >= 15)
			{
				if(gVehData[vehid][VItem15type] == 0)
					slotcount++;
			}
			else
				return slotcount;
		}
	}
	return slotcount;
}

stock BizItemSlotPrice(bizid, slot)
{
	switch(slot)
	{
		case 1: return Businesses[bizid][Product1price];
		case 2: return Businesses[bizid][Product2price];
		case 3: return Businesses[bizid][Product3price];
		case 4: return Businesses[bizid][Product4price];
		case 5: return Businesses[bizid][Product5price];
		case 6: return Businesses[bizid][Product6price];
		case 7: return Businesses[bizid][Product7price];
		case 8: return Businesses[bizid][Product8price];
		case 9: return Businesses[bizid][Product9price];
		case 10: return Businesses[bizid][Product10price];
	}
	return 0;
}

stock BizItemSlotSetPrice(bizid, slot, price)
{
	switch(slot)
	{
		case 1:
		{
			Businesses[bizid][Product1price] = price;
			SaveBizData(bizid, "Product1price");
		}
		case 2:
		{
			Businesses[bizid][Product2price] = price;
			SaveBizData(bizid, "Product2price");
		}
		case 3:
		{
			Businesses[bizid][Product3price] = price;
			SaveBizData(bizid, "Product3price");
		}
		case 4:
		{
			Businesses[bizid][Product4price] = price;
			SaveBizData(bizid, "Product4price");
		}
		case 5:
		{
			Businesses[bizid][Product5price] = price;
			SaveBizData(bizid, "Product5price");
		}
		case 6:
		{
			Businesses[bizid][Product6price] = price;
			SaveBizData(bizid, "Product6price");
		}
		case 7:
		{
			Businesses[bizid][Product7price] = price;
			SaveBizData(bizid, "Product7price");
		}
		case 8:
		{
			Businesses[bizid][Product8price] = price;
			SaveBizData(bizid, "Product8price");
		}
		case 9:
		{
			Businesses[bizid][Product9price] = price;
			SaveBizData(bizid, "Product9price");
		}
		case 10:
		{
			Businesses[bizid][Product10price] = price;
			SaveBizData(bizid, "Product10price");
		}
	}
}

stock BizItemSlotBuy(bizid, slot)
{
	switch(slot)
	{
		case 1: return Businesses[bizid][Product1buy];
		case 2: return Businesses[bizid][Product2buy];
		case 3: return Businesses[bizid][Product3buy];
		case 4: return Businesses[bizid][Product4buy];
		case 5: return Businesses[bizid][Product5buy];
		case 6: return Businesses[bizid][Product6buy];
		case 7: return Businesses[bizid][Product7buy];
		case 8: return Businesses[bizid][Product8buy];
		case 9: return Businesses[bizid][Product9buy];
		case 10: return Businesses[bizid][Product10buy];
	}
	return 0;
}

stock BizItemSlotSetBuy(bizid, slot, buy)
{
	switch(slot)
	{
		case 1:
		{
			Businesses[bizid][Product1buy] = buy;
			SaveBizData(bizid, "Product1buy");
		}
		case 2:
		{
			Businesses[bizid][Product2buy] = buy;
			SaveBizData(bizid, "Product2buy");
		}
		case 3:
		{
			Businesses[bizid][Product3buy] = buy;
			SaveBizData(bizid, "Product3buy");
		}
		case 4:
		{
			Businesses[bizid][Product4buy] = buy;
			SaveBizData(bizid, "Product4buy");
		}
		case 5:
		{
			Businesses[bizid][Product5buy] = buy;
			SaveBizData(bizid, "Product5buy");
		}
		case 6:
		{
			Businesses[bizid][Product6buy] = buy;
			SaveBizData(bizid, "Product6buy");
		}
		case 7:
		{
			Businesses[bizid][Product7buy] = buy;
			SaveBizData(bizid, "Product7buy");
		}
		case 8:
		{
			Businesses[bizid][Product8buy] = buy;
			SaveBizData(bizid, "Product8buy");
		}
		case 9:
		{
			Businesses[bizid][Product9buy] = buy;
			SaveBizData(bizid, "Product9buy");
		}
		case 10:
		{
			Businesses[bizid][Product10buy] = buy;
			SaveBizData(bizid, "Product10buy");
		}
	}
}

stock BizItemSlotCount(bizid, slot)
{
	switch(slot)
	{
		case 1:	return Businesses[bizid][Product1count];
		case 2:	return Businesses[bizid][Product2count];
		case 3:	return Businesses[bizid][Product3count];
		case 4:	return Businesses[bizid][Product4count];
		case 5:	return Businesses[bizid][Product5count];
		case 6:	return Businesses[bizid][Product6count];
		case 7:	return Businesses[bizid][Product7count];
		case 8:	return Businesses[bizid][Product8count];
		case 9:	return Businesses[bizid][Product9count];
		case 10: return Businesses[bizid][Product10count];
	}
	return 0;
}

stock BizItemSlotStatus(bizid, slot)
{
	switch(slot)
	{
		case 1:
		{
			if(!Businesses[bizid][Product1type])
				return 0;
			else
				return 1;
		}
		case 2:
		{
			if(!Businesses[bizid][Product2type])
				return 0;
			else
				return 1;
		}
		case 3:
		{
			if(!Businesses[bizid][Product3type])
				return 0;
			else
				return 1;
		}
		case 4:
		{
			if(!Businesses[bizid][Product4type])
				return 0;
			else
				return 1;
		}
		case 5:
		{
			if(!Businesses[bizid][Product5type])
				return 0;
			else
				return 1;
		}
		case 6:
		{
			if(!Businesses[bizid][Product6type])
				return 0;
			else
				return 1;
		}
		case 7:
		{
			if(!Businesses[bizid][Product7type])
				return 0;
			else
				return 1;
		}
		case 8:
		{
			if(!Businesses[bizid][Product8type])
				return 0;
			else
				return 1;
		}
		case 9:
		{
			if(!Businesses[bizid][Product9type])
				return 0;
			else
				return 1;
		}
		case 10:
		{
			if(!Businesses[bizid][Product10type])
				return 0;
			else
				return 1;
		}
	}
	return 0;
}

stock BizSlotItem(bizid, slot)
{
	switch(slot)
	{
		case 1: return Businesses[bizid][Product1];
		case 2: return Businesses[bizid][Product2];
		case 3: return Businesses[bizid][Product3];
		case 4: return Businesses[bizid][Product4];
		case 5: return Businesses[bizid][Product5];
		case 6: return Businesses[bizid][Product6];
		case 7: return Businesses[bizid][Product7];
		case 8: return Businesses[bizid][Product8];
		case 9: return Businesses[bizid][Product9];
		case 10: return Businesses[bizid][Product10];
	}
	return 0;
}

stock BizSlotSetItem(bizid, slot, type, item)
{
	switch(slot)
	{
		case 1:
		{
			Businesses[bizid][Product1type] = type;
			Businesses[bizid][Product1] = item;
			SaveBizData(bizid, "Product1type");
			SaveBizData(bizid, "Product1");
		}
		case 2:
		{
			Businesses[bizid][Product2type] = type;
			Businesses[bizid][Product2] = item;
			SaveBizData(bizid, "Product2type");
			SaveBizData(bizid, "Product2");
		}
		case 3:
		{
			Businesses[bizid][Product3type] = type;
			Businesses[bizid][Product3] = item;
			SaveBizData(bizid, "Product3type");
			SaveBizData(bizid, "Product3");
		}
		case 4:
		{
			Businesses[bizid][Product4type] = type;
			Businesses[bizid][Product4] = item;
			SaveBizData(bizid, "Product4type");
			SaveBizData(bizid, "Product4");
		}
		case 5:
		{
			Businesses[bizid][Product5type] = type;
			Businesses[bizid][Product5] = item;
			SaveBizData(bizid, "Product5type");
			SaveBizData(bizid, "Product5");
		}
		case 6:
		{
			Businesses[bizid][Product6type] = type;
			Businesses[bizid][Product6] = item;
			SaveBizData(bizid, "Product6type");
			SaveBizData(bizid, "Product6");
		}
		case 7:
		{
			Businesses[bizid][Product7type] = type;
			Businesses[bizid][Product7] = item;
			SaveBizData(bizid, "Product7type");
			SaveBizData(bizid, "Product7");
		}
		case 8:
		{
			Businesses[bizid][Product8type] = type;
			Businesses[bizid][Product8] = item;
			SaveBizData(bizid, "Product8type");
			SaveBizData(bizid, "Product8");
		}
		case 9:
		{
			Businesses[bizid][Product9type] = type;
			Businesses[bizid][Product9] = item;
			SaveBizData(bizid, "Product9type");
			SaveBizData(bizid, "Product9");
		}
		case 10:
		{
			Businesses[bizid][Product10type] = type;
			Businesses[bizid][Product10] = item;
			SaveBizData(bizid, "Product10type");
			SaveBizData(bizid, "Product10");
		}
	}
}

stock BizSlotType(bizid, slot)
{
	switch(slot)
	{
		case 1: return Businesses[bizid][Product1type];
		case 2: return Businesses[bizid][Product2type];
		case 3: return Businesses[bizid][Product3type];
		case 4: return Businesses[bizid][Product4type];
		case 5: return Businesses[bizid][Product5type];
		case 6: return Businesses[bizid][Product6type];
		case 7: return Businesses[bizid][Product7type];
		case 8: return Businesses[bizid][Product8type];
		case 9: return Businesses[bizid][Product9type];
		case 10: return Businesses[bizid][Product10type];
	}
	return 0;
}

stock SetBizItemSlotCount(bizid, slot, value)
{
	switch(slot)
	{
		case 1:
		{
			Businesses[bizid][Product1count] = value;
			SaveBizData(bizid, "Product1count");
			return 1;
		}
		case 2:
		{
			Businesses[bizid][Product2count] = value;
			SaveBizData(bizid, "Product2count");
			return 1;
		}
		case 3:
		{
			Businesses[bizid][Product3count] = value;
			SaveBizData(bizid, "Product3count");
			return 1;
		}
		case 4:
		{
			Businesses[bizid][Product4count] = value;
			SaveBizData(bizid, "Product4count");
			return 1;
		}
		case 5:
		{
			Businesses[bizid][Product5count] = value;
			SaveBizData(bizid, "Product5count");
			return 1;
		}
		case 6:
		{
			Businesses[bizid][Product6count] = value;
			SaveBizData(bizid, "Product6count");
			return 1;
		}
		case 7:
		{
			Businesses[bizid][Product7count] = value;
			SaveBizData(bizid, "Product7count");
			return 1;
		}
		case 8:
		{
			Businesses[bizid][Product8count] = value;
			SaveBizData(bizid, "Product8count");
			return 1;
		}
		case 9:
		{
			Businesses[bizid][Product9count] = value;
			SaveBizData(bizid, "Product9count");
			return 1;
		}
		case 10:
		{
			Businesses[bizid][Product10count] = value;
			SaveBizData(bizid, "Product10count");
			return 1;
		}
	}
	return 0;
}
