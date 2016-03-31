							 //////////////////////////////
							//Fighting Styles by Sayaron//
			   	           //////////////////////////////

#include <a_samp>

#define FILTERSCRIPT

#define DIALOGID 5009

public OnFilterScriptInit()
{
    print("===========================");
	print("=Sayaron's Fighting Styles=");
	print("===========================");
	return 1;
}

public OnPlayerCommandText(playerid, cmdtext[])
{
	if (strcmp("/styles", cmdtext, true, 10) == 0)
	{
		ShowPlayerDialog(playerid, DIALOGID, DIALOG_STYLE_LIST, "Fighting Styles by Sayaron", "Fighting Styles", "Select", "Cancel");
		return 1;
	}
	return 0;
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
 	if(dialogid == DIALOGID)
	{
  		if(response)
  		{
			if(listitem == 0)
   			{
				ShowPlayerDialog(playerid, DIALOGID+1, DIALOG_STYLE_LIST, "Fighting Styles", "Elbow\nBoxing\nGrabkick\nKneehead\nKungfu\nNormal", "Select", "Cancel");
			}
  		}
		return 1;
	}
	if(dialogid == DIALOGID+1)
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
	return 0;
 }
