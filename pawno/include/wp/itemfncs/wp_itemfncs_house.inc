/***
*
* File: wp_itemfncs_house.inc
* Auth: Damian Wojdat
* Date: 13.05.2012
* Desc: Functions related to houses items.
*
*************************************************************************************************************/

stock HItemWeight(hid)
{
	new weight = 0;
	weight += ItemWeight(Houses[hid][HItem1type], Houses[hid][HItem1]);
	weight += ItemWeight(Houses[hid][HItem2type], Houses[hid][HItem2]);
	weight += ItemWeight(Houses[hid][HItem3type], Houses[hid][HItem3]);
	weight += ItemWeight(Houses[hid][HItem4type], Houses[hid][HItem4]);
	weight += ItemWeight(Houses[hid][HItem5type], Houses[hid][HItem5]);
	return weight;
}

/*
* Cleans selected house slot
*/
stock RemoveHouseItem(houseid, slot)
{
	if (slot == 1)
	{
		Houses[houseid][HItem1] = 0;
		Houses[houseid][HItem1type] = 0;
		Houses[houseid][HItem1param] = 0;
		Houses[houseid][HItem1param2] = 0;
		Houses[houseid][HItem1param3] = 0;
		Houses[houseid][HItem1param4] = 0;
		strdel(Houses[houseid][HItem1param5], 0, 64);
		strins(Houses[houseid][HItem1param5], "Puste", 0, 64);
		Houses[houseid][HItem1param6] = 0;

		SaveHouseData(houseid, "HItem1");
		SaveHouseData(houseid, "HItem1type");
		SaveHouseData(houseid, "HItem1param");
		SaveHouseData(houseid, "HItem1param2");
		SaveHouseData(houseid, "HItem1param3");
		SaveHouseData(houseid, "HItem1param4");
		SaveHouseData(houseid, "HItem1param5");
		SaveHouseData(houseid, "HItem1param6");
	}
	else if (slot == 2)
	{
		Houses[houseid][HItem2] = 0;
		Houses[houseid][HItem2type] = 0;
		Houses[houseid][HItem2param] = 0;
		Houses[houseid][HItem2param2] = 0;
		Houses[houseid][HItem2param3] = 0;
		Houses[houseid][HItem2param4] = 0;
		strdel(Houses[houseid][HItem2param5], 0, 64);
		strins(Houses[houseid][HItem2param5], "Puste", 0, 64);
		Houses[houseid][HItem2param6] = 0;

		SaveHouseData(houseid, "HItem2");
		SaveHouseData(houseid, "HItem2type");
		SaveHouseData(houseid, "HItem2param");
		SaveHouseData(houseid, "HItem2param2");
		SaveHouseData(houseid, "HItem2param3");
		SaveHouseData(houseid, "HItem2param4");
		SaveHouseData(houseid, "HItem2param5");
		SaveHouseData(houseid, "HItem2param6");
	}
	else if (slot == 3)
	{
		Houses[houseid][HItem3] = 0;
		Houses[houseid][HItem3type] = 0;
		Houses[houseid][HItem3param] = 0;
		Houses[houseid][HItem3param2] = 0;
		Houses[houseid][HItem3param3] = 0;
		Houses[houseid][HItem3param4] = 0;
		strdel(Houses[houseid][HItem3param5], 0, 64);
		strins(Houses[houseid][HItem3param5], "Puste", 0, 64);
		Houses[houseid][HItem3param6] = 0;

		SaveHouseData(houseid, "HItem3");
		SaveHouseData(houseid, "HItem3type");
		SaveHouseData(houseid, "HItem3param");
		SaveHouseData(houseid, "HItem3param2");
		SaveHouseData(houseid, "HItem3param3");
		SaveHouseData(houseid, "HItem3param4");
		SaveHouseData(houseid, "HItem3param5");
		SaveHouseData(houseid, "HItem3param6");
	}
	else if (slot == 4)
	{
		Houses[houseid][HItem4] = 0;
		Houses[houseid][HItem4type] = 0;
		Houses[houseid][HItem4param] = 0;
		Houses[houseid][HItem4param2] = 0;
		Houses[houseid][HItem4param3] = 0;
		Houses[houseid][HItem4param4] = 0;
		strdel(Houses[houseid][HItem4param5], 0, 64);
		strins(Houses[houseid][HItem4param5], "Puste", 0, 64);
		Houses[houseid][HItem4param6] = 0;

		SaveHouseData(houseid, "HItem4");
		SaveHouseData(houseid, "HItem4type");
		SaveHouseData(houseid, "HItem4param");
		SaveHouseData(houseid, "HItem4param2");
		SaveHouseData(houseid, "HItem4param3");
		SaveHouseData(houseid, "HItem4param4");
		SaveHouseData(houseid, "HItem4param5");
		SaveHouseData(houseid, "HItem4param6");
	}
	else if (slot == 5)
	{
		Houses[houseid][HItem5] = 0;
		Houses[houseid][HItem5type] = 0;
		Houses[houseid][HItem5param] = 0;
		Houses[houseid][HItem5param2] = 0;
		Houses[houseid][HItem5param3] = 0;
		Houses[houseid][HItem5param4] = 0;
		strdel(Houses[houseid][HItem5param5], 0, 64);
		strins(Houses[houseid][HItem5param5], "Puste", 0, 64);
		Houses[houseid][HItem5param6] = 0;

		SaveHouseData(houseid, "HItem5");
		SaveHouseData(houseid, "HItem5type");
		SaveHouseData(houseid, "HItem5param");
		SaveHouseData(houseid, "HItem5param2");
		SaveHouseData(houseid, "HItem5param3");
		SaveHouseData(houseid, "HItem5param4");
		SaveHouseData(houseid, "HItem5param5");
		SaveHouseData(houseid, "HItem5param6");
	}
}

/*
* Remove exact amount of item from slot
*/
stock RemoveHouseItemEx(houseid, slot, howMuch = 1)
{
	if(HSlotParam6(houseid, slot) <= howMuch)
		RemoveHouseItem(houseid, slot);
	else
		SetHSlotParam6(houseid, slot, HSlotParam6(houseid, slot)-howMuch);
	return 1;
}

stock InsertHouseItem(houseid, itemtype, itemid, itemparam, itemparam2, itemparam3, itemparam4, itemparam5[] = "Puste", itemparam6 = 1)
{
	if(Houses[houseid][HItem1type] == 0)
	{
		Houses[houseid][HItem1] = itemid;
		Houses[houseid][HItem1type] = itemtype;
		Houses[houseid][HItem1param] = itemparam;
		Houses[houseid][HItem1param2] = itemparam2;
		Houses[houseid][HItem1param3] = itemparam3;
		Houses[houseid][HItem1param4] = itemparam4;
		strdel(Houses[houseid][HItem1param5], 0, 64);
		strins(Houses[houseid][HItem1param5], itemparam5, 0, 64);
		Houses[houseid][HItem1param6] = itemparam6;

		SaveHouseData(houseid, "HItem1");
		SaveHouseData(houseid, "HItem1type");
		SaveHouseData(houseid, "HItem1param");
		SaveHouseData(houseid, "HItem1param2");
		SaveHouseData(houseid, "HItem1param3");
		SaveHouseData(houseid, "HItem1param4");
		SaveHouseData(houseid, "HItem1param5");
		SaveHouseData(houseid, "HItem1param6");

		return 1;
	}
	if(Houses[houseid][HItem2type] == 0)
	{
		Houses[houseid][HItem2] = itemid;
		Houses[houseid][HItem2type] = itemtype;
		Houses[houseid][HItem2param] = itemparam;
		Houses[houseid][HItem2param2] = itemparam2;
		Houses[houseid][HItem2param3] = itemparam3;
		Houses[houseid][HItem2param4] = itemparam4;
		strdel(Houses[houseid][HItem2param5], 0, 64);
		strins(Houses[houseid][HItem2param5], itemparam5, 0, 64);
		Houses[houseid][HItem2param6] = itemparam6;

		SaveHouseData(houseid, "HItem2");
		SaveHouseData(houseid, "HItem2type");
		SaveHouseData(houseid, "HItem2param");
		SaveHouseData(houseid, "HItem2param2");
		SaveHouseData(houseid, "HItem2param3");
		SaveHouseData(houseid, "HItem2param4");
		SaveHouseData(houseid, "HItem2param5");
		SaveHouseData(houseid, "HItem2param6");

		return 2;
	}
	if(Houses[houseid][HItem3type] == 0)
	{
		Houses[houseid][HItem3] = itemid;
		Houses[houseid][HItem3type] = itemtype;
		Houses[houseid][HItem3param] = itemparam;
		Houses[houseid][HItem3param2] = itemparam2;
		Houses[houseid][HItem3param3] = itemparam3;
		Houses[houseid][HItem3param4] = itemparam4;
		strdel(Houses[houseid][HItem3param5], 0, 64);
		strins(Houses[houseid][HItem3param5], itemparam5, 0, 64);
		Houses[houseid][HItem3param6] = itemparam6;
		
		SaveHouseData(houseid, "HItem3");
		SaveHouseData(houseid, "HItem3type");
		SaveHouseData(houseid, "HItem3param");
		SaveHouseData(houseid, "HItem3param2");
		SaveHouseData(houseid, "HItem3param3");
		SaveHouseData(houseid, "HItem3param4");
		SaveHouseData(houseid, "HItem3param5");
		SaveHouseData(houseid, "HItem3param6");

		return 3;
	}
	if(Houses[houseid][HItem4type] == 0)
	{
		Houses[houseid][HItem4] = itemid;
		Houses[houseid][HItem4type] = itemtype;
		Houses[houseid][HItem4param] = itemparam;
		Houses[houseid][HItem4param2] = itemparam2;
		Houses[houseid][HItem4param3] = itemparam3;
		Houses[houseid][HItem4param4] = itemparam4;
		strdel(Houses[houseid][HItem4param5], 0, 64);
		strins(Houses[houseid][HItem4param5], itemparam5, 0, 64);
		Houses[houseid][HItem4param6] = itemparam6;

		SaveHouseData(houseid, "HItem4");
		SaveHouseData(houseid, "HItem4type");
		SaveHouseData(houseid, "HItem4param");
		SaveHouseData(houseid, "HItem4param2");
		SaveHouseData(houseid, "HItem4param3");
		SaveHouseData(houseid, "HItem4param4");
		SaveHouseData(houseid, "HItem4param5");
		SaveHouseData(houseid, "HItem4param6");

		return 4;
	}
	if(Houses[houseid][HItem5type] == 0)
	{
		Houses[houseid][HItem5] = itemid;
		Houses[houseid][HItem5type] = itemtype;
		Houses[houseid][HItem5param] = itemparam;
		Houses[houseid][HItem5param2] = itemparam2;
		Houses[houseid][HItem5param3] = itemparam3;
		Houses[houseid][HItem5param4] = itemparam4;
		strdel(Houses[houseid][HItem5param5], 0, 64);
		strins(Houses[houseid][HItem5param5], itemparam5, 0, 64);
		Houses[houseid][HItem5param6] = itemparam6;

		SaveHouseData(houseid, "HItem5");
		SaveHouseData(houseid, "HItem5type");
		SaveHouseData(houseid, "HItem5param");
		SaveHouseData(houseid, "HItem5param2");
		SaveHouseData(houseid, "HItem5param3");
		SaveHouseData(houseid, "HItem5param4");
		SaveHouseData(houseid, "HItem5param5");
		SaveHouseData(houseid, "HItem5param6");

		return 5;
	}
	return 0;
}

stock SetHSlotParam6(hid, slot, value)
{
	if(slot == 1)
	{
		Houses[hid][HItem1param6] = value;
		SaveHouseData(hid, "HItem1param6");
		return 1;
	}
	if(slot == 2)
	{
		Houses[hid][HItem2param6] = value;
		SaveHouseData(hid, "HItem2param6");
		return 1;
	}
	if(slot == 3)
	{
		Houses[hid][HItem3param6] = value;
		SaveHouseData(hid, "HItem3param6");
		return 1;
	}
	if(slot == 4)
	{
		Houses[hid][HItem4param6] = value;
		SaveHouseData(hid, "HItem4param6");
		return 1;
	}
	if(slot == 5)
	{
		Houses[hid][HItem5param6] = value;
		SaveHouseData(hid, "HItem5param6");
		return 1;
	}
	return 0;
}

stock HSlotParam1(hid, slot)
{
	switch(slot)
	{
		case 1: return Houses[hid][HItem1param];
		case 2: return Houses[hid][HItem2param];
		case 3: return Houses[hid][HItem3param];
		case 4: return Houses[hid][HItem4param];
		case 5: return Houses[hid][HItem5param];
	}
	return 0;
}

stock HSlotParam2(hid, slot)
{
	switch(slot)
	{
		case 1: return Houses[hid][HItem1param2];
		case 2: return Houses[hid][HItem2param2];
		case 3: return Houses[hid][HItem3param2];
		case 4: return Houses[hid][HItem4param2];
		case 5: return Houses[hid][HItem5param2];
	}
	return 0;
}

stock HSlotParam3(hid, slot)
{
	switch(slot)
	{
		case 1: return Houses[hid][HItem1param3];
		case 2: return Houses[hid][HItem2param3];
		case 3: return Houses[hid][HItem3param3];
		case 4: return Houses[hid][HItem4param3];
		case 5: return Houses[hid][HItem5param3];
	}
	return 0;
}

stock HSlotParam4(hid, slot)
{
	switch(slot)
	{
		case 1: return Houses[hid][HItem1param4];
		case 2: return Houses[hid][HItem2param4];
		case 3: return Houses[hid][HItem3param4];
		case 4: return Houses[hid][HItem4param4];
		case 5: return Houses[hid][HItem5param4];
	}
	return 0;
}

stock HSlotParam5(hid, slot)
{
	switch(slot)
	{
		case 1:
		{
			format(gHSelectedItemP5[hid], 64, Houses[hid][HItem1param5]);
		}
		case 2:
		{
			format(gHSelectedItemP5[hid], 64, Houses[hid][HItem2param5]);
		}
		case 3:
		{
			format(gHSelectedItemP5[hid], 64, Houses[hid][HItem3param5]);
		}
		case 4:
		{
			format(gHSelectedItemP5[hid], 64, Houses[hid][HItem4param5]);
		}
		case 5:
		{
			format(gHSelectedItemP5[hid], 64, Houses[hid][HItem5param5]);
		}
	}
	format(gHSelectedItemP5[hid], 64, "");
}

stock HSlotParam6(hid, slot)
{
	switch(slot)
	{
		case 1: return Houses[hid][HItem1param6];
		case 2: return Houses[hid][HItem2param6];
		case 3: return Houses[hid][HItem3param6];
		case 4: return Houses[hid][HItem4param6];
		case 5: return Houses[hid][HItem5param6];
	}
	return 0;
}

/*
* Compare house slot item type with given typedef
*/
stock HSlotItemTypeCompare(hid, slotid, type)
{
	switch(slotid)
	{
		case 1:
		{
			if(Houses[hid][HItem1type] == type)
				return 1;
			else
				return 0;
		}
		case 2:
		{
			if(Houses[hid][HItem2type] == type)
				return 1;
			else
				return 0;
		}
		case 3:
		{
			if(Houses[hid][HItem3type] == type)
				return 1;
			else
				return 0;
		}
		case 4:
		{
			if(Houses[hid][HItem4type] == type)
				return 1;
			else
				return 0;
		}
		case 5:
		{
			if(Houses[hid][HItem5type] == type)
				return 1;
			else
				return 0;
		}
	}
	return 0;
}			

stock HItemSlotStatus(houseid, slot)
{
	if(slot == 1)
	{
		if(Houses[houseid][HItem1type] > 0)
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
		if(Houses[houseid][HItem2type] > 0)
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
		if(Houses[houseid][HItem3type] > 0)
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
		if(Houses[houseid][HItem4type] > 0)
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
		if(Houses[houseid][HItem5type] > 0)
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

stock HHaveItem(hid, itemtype, itemid)
{
	if(Houses[hid][HItem1type] == itemtype)
	{
		if(Houses[hid][HItem1] == itemid)
		{
			return 1;
		}
	}
	if(Houses[hid][HItem2type] == itemtype)
	{
		if(Houses[hid][HItem2] == itemid)
		{
			return 2;
		}
	}
	if(Houses[hid][HItem3type] == itemtype)
	{
		if(Houses[hid][HItem3] == itemid)
		{
			return 3;
		}
	}
	if(Houses[hid][HItem4type] == itemtype)
	{
		if(Houses[hid][HItem4] == itemid)
		{
			return 4;
		}
	}
	if(Houses[hid][HItem5type] == itemtype)
	{
		if(Houses[hid][HItem5] == itemid)
		{
			return 5;
		}
	}
	return 0;
}

stock HHaveItemEx(hid, itemtype, itemid, slots[MAX_HOUSE_ITEM_SLOT])
{
	if(Houses[hid][HItem1type] == itemtype)
	{
		if(Houses[hid][HItem1] == itemid || itemid == -1)
			slots[0] = 1;
		else
			slots[0] = 0;
	}
	if(Houses[hid][HItem2type] == itemtype)
	{
		if(Houses[hid][HItem2] == itemid || itemid == -1)
			slots[1] = 1;
		else
			slots[1] = 0;
	}
	if(Houses[hid][HItem3type] == itemtype)
	{
		if(Houses[hid][HItem3] == itemid || itemid == -1)
			slots[2] = 1;
		else
			slots[2] = 0;
	}
	if(Houses[hid][HItem4type] == itemtype)
	{
		if(Houses[hid][HItem4] == itemid || itemid == -1)
			slots[3] = 1;
		else
			slots[3] = 0;
	}
	if(Houses[hid][HItem5type] == itemtype)
	{
		if(Houses[hid][HItem5] == itemid || itemid == -1)
			slots[4] = 1;
		else
			slots[4] = 0;
	}
	return slots;
}