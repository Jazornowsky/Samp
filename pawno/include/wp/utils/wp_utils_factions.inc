/***
*
* File: wp_utils_factions.inc
* Auth: Damian Wojdat
* Date: 28.05.2012
* Desc: Internal script function related to factions.
*
*************************************************************************************************************/

stock CheckRankPrivilidges(fId, rank, command[])
{
	if(strcmp(command, "fstankonta") == 0)
	{
		switch(rank)
		{
			case 1: return 1;
			case 2: return DynamicFactions[fId][fRank2TillCheck];
			case 3: return DynamicFactions[fId][fRank3TillCheck];
			case 4: return DynamicFactions[fId][fRank4TillCheck];
			case 5: return DynamicFactions[fId][fRank5TillCheck];
			case 6: return DynamicFactions[fId][fRank6TillCheck];
			case 7: return DynamicFactions[fId][fRank7TillCheck];
			case 8: return DynamicFactions[fId][fRank8TillCheck];
			case 9: return DynamicFactions[fId][fRank9TillCheck];
			case 10: return DynamicFactions[fId][fRank10TillCheck];
		}
	}
	else if(strcmp(command, "statusfrakcji") == 0)
	{
		switch(rank)
		{
			case 1: return 1;
			case 2: return DynamicFactions[fId][fRank2FactionStatus];
			case 3: return DynamicFactions[fId][fRank3FactionStatus];
			case 4: return DynamicFactions[fId][fRank4FactionStatus];
			case 5: return DynamicFactions[fId][fRank5FactionStatus];
			case 6: return DynamicFactions[fId][fRank6FactionStatus];
			case 7: return DynamicFactions[fId][fRank7FactionStatus];
			case 8: return DynamicFactions[fId][fRank8FactionStatus];
			case 9: return DynamicFactions[fId][fRank9FactionStatus];
			case 10: return DynamicFactions[fId][fRank10FactionStatus];
		}
	}
	else if(strcmp(command, "kuppojazdf") == 0)
	{
		switch(rank)
		{
			case 1: return 1;
			case 2: return DynamicFactions[fId][fRank2VehBuy];
			case 3: return DynamicFactions[fId][fRank3VehBuy];
			case 4: return DynamicFactions[fId][fRank4VehBuy];
			case 5: return DynamicFactions[fId][fRank5VehBuy];
			case 6: return DynamicFactions[fId][fRank6VehBuy];
			case 7: return DynamicFactions[fId][fRank7VehBuy];
			case 8: return DynamicFactions[fId][fRank8VehBuy];
			case 9: return DynamicFactions[fId][fRank9VehBuy];
			case 10: return DynamicFactions[fId][fRank10VehBuy];
		}
	}
	else if(strcmp(command, "sprzedajpojazdf") == 0)
	{
		switch(rank)
		{
			case 1: return 1;
			case 2: return DynamicFactions[fId][fRank2VehSell];
			case 3: return DynamicFactions[fId][fRank3VehSell];
			case 4: return DynamicFactions[fId][fRank4VehSell];
			case 5: return DynamicFactions[fId][fRank5VehSell];
			case 6: return DynamicFactions[fId][fRank6VehSell];
			case 7: return DynamicFactions[fId][fRank7VehSell];
			case 8: return DynamicFactions[fId][fRank8VehSell];
			case 9: return DynamicFactions[fId][fRank9VehSell];
			case 10: return DynamicFactions[fId][fRank10VehSell];
		}
	}
	else if(strcmp(command, "zezlomujpojazdf") == 0)
	{
		switch(rank)
		{
			case 1: return 1;
			case 2: return DynamicFactions[fId][fRank2VehSalvage];
			case 3: return DynamicFactions[fId][fRank3VehSalvage];
			case 4: return DynamicFactions[fId][fRank4VehSalvage];
			case 5: return DynamicFactions[fId][fRank5VehSalvage];
			case 6: return DynamicFactions[fId][fRank6VehSalvage];
			case 7: return DynamicFactions[fId][fRank7VehSalvage];
			case 8: return DynamicFactions[fId][fRank8VehSalvage];
			case 9: return DynamicFactions[fId][fRank9VehSalvage];
			case 10: return DynamicFactions[fId][fRank10VehSalvage];
		}
	}
	else if(strcmp(command, "vehdrive") == 0)
	{
		switch(rank)
		{
			case 1: return 1;
			case 2: return DynamicFactions[fId][fRank2VehDrive];
			case 3: return DynamicFactions[fId][fRank3VehDrive];
			case 4: return DynamicFactions[fId][fRank4VehDrive];
			case 5: return DynamicFactions[fId][fRank5VehDrive];
			case 6: return DynamicFactions[fId][fRank6VehDrive];
			case 7: return DynamicFactions[fId][fRank7VehDrive];
			case 8: return DynamicFactions[fId][fRank8VehDrive];
			case 9: return DynamicFactions[fId][fRank9VehDrive];
			case 10: return DynamicFactions[fId][fRank10VehDrive];
		}
	}
	else if(strcmp(command, "walczoterytorium") == 0)
	{
		switch(rank)
		{
			case 1: return 1;
			case 2: return DynamicFactions[fId][fRank2TerritoryWar];
			case 3: return DynamicFactions[fId][fRank3TerritoryWar];
			case 4: return DynamicFactions[fId][fRank4TerritoryWar];
			case 5: return DynamicFactions[fId][fRank5TerritoryWar];
			case 6: return DynamicFactions[fId][fRank6TerritoryWar];
			case 7: return DynamicFactions[fId][fRank7TerritoryWar];
			case 8: return DynamicFactions[fId][fRank8TerritoryWar];
			case 9: return DynamicFactions[fId][fRank9TerritoryWar];
			case 10: return DynamicFactions[fId][fRank10TerritoryWar];
		}
	}
	else if(strcmp(command, "podpalfab") == 0)
	{
		switch(rank)
		{
			case 1: return 1;
			case 2: return DynamicFactions[fId][fRank2BurnFactory];
			case 3: return DynamicFactions[fId][fRank3BurnFactory];
			case 4: return DynamicFactions[fId][fRank4BurnFactory];
			case 5: return DynamicFactions[fId][fRank5BurnFactory];
			case 6: return DynamicFactions[fId][fRank6BurnFactory];
			case 7: return DynamicFactions[fId][fRank7BurnFactory];
			case 8: return DynamicFactions[fId][fRank8BurnFactory];
			case 9: return DynamicFactions[fId][fRank9BurnFactory];
			case 10: return DynamicFactions[fId][fRank10BurnFactory];
		}
	}
	return 0;
}