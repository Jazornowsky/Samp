// Menus by CaptainJohn


#define FILTERSCRIPT

#include <a_samp>

#if defined FILTERSCRIPT

#define WEAPONS 2222
#define DIALOGID 2223
#define TELEPORT 2224

#define COLOR_RED 0xAA3333AA

public OnFilterScriptInit()
{
	return 1;
}

public OnFilterScriptExit()
{
	return 1;
}

#else

main()
{
}

#endif

public OnPlayerCommandText(playerid, cmdtext[])
{
	if (strcmp("/weapons", cmdtext, true, 10) == 0)
	{
		ShowPlayerDialog(playerid, 2222, DIALOG_STYLE_LIST, "Weapon Menu By CaptainJohn", "Health (500)\nArmour (500)\n9mm (2500)\nSilence Pistol (2000)\nDesert Eagle (2500)\nShotgun (5000)\nSawn-Off Shotgun (5500)\nCombat Shotgun (6500)\nMicro SMG (3000)\nMP5 (4000)\nTec-9 (5500)\nAK-47 (4500)\nM4 (6000)\nCountry Rifle (6500)\nSniper Rifle (10000)", "Purchase", "Cancel");
		return 1;
	}
	if (strcmp("/style", cmdtext, true, 10) == 0)
	{
		ShowPlayerDialog(playerid, 2223, DIALOG_STYLE_LIST, "Fighting Styles By CaptainJohn", "Fighting Styles", "Select", "Cancel");
		return 1;
	}
	if (strcmp("/teleports", cmdtext, true, 10) == 0)
	{
		ShowPlayerDialog(playerid, 2224, DIALOG_STYLE_LIST, "Teleport Menu By CaptainJohn", "Jefferson Motel DM\nDeagle DM\nM4 DM\nSniper DM\nDryLake", "Select", "Cancel");
		return 1;
	}
	return 0;
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	if(dialogid == 2222)
	{
	    if(response)
	    {
	        if(listitem == 0)
	        {
	            GivePlayerMoney(playerid, -500);
	            SetPlayerHealth(playerid, 100); //Health
			}
			if(listitem == 1)
			{
			    GivePlayerMoney(playerid, -500);
			    SetPlayerArmour(playerid, 100); //Armour
			}
			if(listitem == 2)
			{
			    GivePlayerMoney(playerid, -2500);
			    GivePlayerWeapon(playerid, 22, 1000); //9mm
			}
			if(listitem == 3)
			{
			    GivePlayerMoney(playerid, -200);
			    GivePlayerWeapon(playerid, 23, 1000); //Silence Pistol
			}
			if(listitem == 4)
			{
			    GivePlayerMoney(playerid, -2500);
			    GivePlayerWeapon(playerid, 24, 1000); //Desert Eagle
			}
			if(listitem == 5)
			{
			    GivePlayerMoney(playerid, -5000);
			    GivePlayerWeapon(playerid, 25, 1000); //Shotgun
			}
			if(listitem == 6)
			{
			    GivePlayerMoney(playerid, -5500);
			    GivePlayerWeapon(playerid, 26, 1000); //Sawn-off
			}
			if(listitem == 7)
			{
			    GivePlayerMoney(playerid, -6500);
			    GivePlayerWeapon(playerid, 27, 1000); //Combat Shotgun
			}
			if(listitem == 8)
			{
			    GivePlayerMoney(playerid, -3000);
			    GivePlayerWeapon(playerid, 28, 1000); //Micro SMG
			}
			if(listitem == 9)
			{
			    GivePlayerMoney(playerid, -4000);
			    GivePlayerWeapon(playerid, 29, 1000); //MP5
			}
			if(listitem == 10)
			{
			    GivePlayerMoney(playerid, -5500);
			    GivePlayerWeapon(playerid, 32, 1000); //Tec-9
			}
			if(listitem == 11)
			{
			    GivePlayerMoney(playerid, -4500);
			    GivePlayerWeapon(playerid, 30, 1000); //AK-47
			}
			if(listitem == 12)
			{
			    GivePlayerMoney(playerid, -6000);
			    GivePlayerWeapon(playerid, 31, 1000); //M4
			}
			if(listitem == 13)
			{
			    GivePlayerMoney(playerid, -6500);
			    GivePlayerWeapon(playerid, 33, 1000); //Country Rifle
			}
			if(listitem == 14)
			{
			    GivePlayerMoney(playerid, -10000);
			    GivePlayerWeapon(playerid, 34, 1000); //Sniper Rifle
			}
		}
		return 1;
	}
	if(dialogid == 2223)
	{
  		if(response)
  		{
			if(listitem == 0)
   			{
				ShowPlayerDialog(playerid, DIALOGID+1, DIALOG_STYLE_LIST, "Fighting Styles", "Elbow\nBoxing\nGrabkick\nKneehead\nKung-FU\nNormal", "Select", "Cancel");
			}
  		}
		return 1;
	}
	if(dialogid == 2223)
	{
		if(response)
		{
			if(listitem == 0)
			{
				SetPlayerFightingStyle (playerid, FIGHT_STYLE_ELBOW);
			}
			if(listitem == 1)
			{
				SetPlayerFightingStyle (playerid, FIGHT_STYLE_BOXING);
			}
			if(listitem == 2)
			{
			    SetPlayerFightingStyle (playerid, FIGHT_STYLE_GRABKICK);
			}
			if(listitem == 3)
			{
				SetPlayerFightingStyle (playerid, FIGHT_STYLE_KNEEHEAD);
			}
			if(listitem == 4)
			{
			    SetPlayerFightingStyle (playerid, FIGHT_STYLE_KUNGFU);
			}
			if(listitem == 5)
			{
				SetPlayerFightingStyle (playerid, FIGHT_STYLE_NORMAL);
			}
		}
		return 1;
	}
	if(dialogid == 2224)
	{
	    if(response)
	    {
	        if(listitem == 0)
	        {
      			new var2[24], var4[256];
				GetPlayerName(playerid, var2, 24);
				format(var4, 256, "** %s has joined Jefferson Motel DM, Type /jdm to join", var2);
				SendClientMessageToAll(COLOR_RED, var4);
				new c = random(6);
				if (c == 0) SetPlayerPos(playerid, 2220.8215,-1149.4452,1025.7969);
				else if (c == 1) SetPlayerPos(playerid, 2221.6023,-1139.9663,1027.7969);
				else if (c == 2) SetPlayerPos(playerid, 2227.1799,-1141.6085,1029.7969);
				else if (c == 3) SetPlayerPos(playerid, 2232.9680,-1150.1281,1029.7969);
				else if (c == 3) SetPlayerPos(playerid, 2241.6462,-1192.2533,1029.7969);
				else if (c == 4) SetPlayerPos(playerid, 2236.2317,-1188.6218,1029.8043);
				else if (c == 5) SetPlayerPos(playerid, 2245.2378,-1186.0424,1029.8043);
				SetPlayerInterior(playerid, 15);
				SetPlayerHealth(playerid, 100);
				SetPlayerArmour(playerid, 100);
				ResetPlayerWeapons(playerid);
				GivePlayerWeapon(playerid, 31, 1200);
				GivePlayerWeapon(playerid, 34, 1337);
				GivePlayerWeapon(playerid, 24, 1337);
				GivePlayerWeapon(playerid, 26, 500);
				SetPlayerVirtualWorld(playerid, 0);
			}
			if(listitem == 1)
			{
				new var2[24];
				new var4[256];
				GetPlayerName(playerid, var2, 24);
				format(var4, 256, "** %s has joined the Deagle DM, Type /Deagle to join", var2);
				SendClientMessageToAll(COLOR_RED, var4);
		 	    new c = random(3);
		        if (c == 0){
		        SetPlayerPos(playerid, -329.16,1838.60,42.28);}
		        else if (c == 1){
		        SetPlayerPos(playerid, -300.17,1869.56,42.28);}
		        else if (c == 2){
				SetPlayerPos(playerid, -341.66,1891.66,42.28);}
				SetPlayerInterior(playerid, 0);
				SetPlayerHealth(playerid, 100);
				SetPlayerArmour(playerid, 100);
				ResetPlayerWeapons(playerid);
				GivePlayerWeapon(playerid, 24, 1337);
				SetPlayerVirtualWorld (playerid, 0);
			}
			if(listitem == 2)
			{
				new var2[24];
				new var4[256];
				GetPlayerName(playerid, var2, 24);
				format(var4, 256, "** %s has joined the M4 DM, Type /m4 to join", var2);
				SendClientMessageToAll(COLOR_RED, var4);
		        new c = random(3);
		        if (c == 0){
		        SetPlayerPos(playerid, -1130.4716,1057.5819,1346.4141);}
		        else if (c == 1){
		        SetPlayerPos(playerid, -974.5633,1061.6102,1345.6732);}
		        else if (c == 2){
		        SetPlayerPos(playerid, -1042.8517,1063.2379,1346.3070);}
				SetPlayerInterior(playerid, 10);
				SetPlayerHealth(playerid, 100);
				SetPlayerArmour(playerid, 100);
				ResetPlayerWeapons(playerid);
				GivePlayerWeapon(playerid, 31, 1200);
				SetPlayerVirtualWorld(playerid, 0);
			}
			if(listitem == 3)
			{
				new var2[24];
				new var4[256];
				GetPlayerName(playerid, var2, 24);
				format(var4, 256, "** %s has joined the Sniper DM, Type /sniper to join", var2);
				SendClientMessageToAll(COLOR_RED, var4);
		        new c = random(3);
		        if (c == 0){
		        SetPlayerPos(playerid, 2512.22, 2774.92, 10.82);}
		        else if (c == 1){
		        SetPlayerPos(playerid, 2611.66, 2730.53, 36.53);}
		        else if (c == 2){
		        SetPlayerPos(playerid, 2652.78, 2779.73, 19.32);}
				SetPlayerInterior(playerid, 0);
				SetPlayerHealth(playerid, 100);
				SetPlayerArmour(playerid, 100);
				ResetPlayerWeapons(playerid);
				GivePlayerWeapon(playerid, 34, 1337);
				SetPlayerVirtualWorld(playerid, 0);
			}
			if(listitem == 4)
			{
				new var2[24];
				new var4[256];
				GetPlayerName(playerid, var2, 24);
				format(var4, 256, "** %s has teleported to Drylake, Type /drylake to join", var2);
				SendClientMessageToAll(COLOR_RED, var4);
		        SetPlayerPos(playerid, -12.7000, 1481.7000, 14.00);
		        SetPlayerInterior(playerid,0);
			}
		}
		return 1;
	}
 	return 1;
}
