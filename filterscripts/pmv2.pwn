#include <a_samp>
new player[MAX_PLAYERS], bool: tog[MAX_PLAYERS];
public OnFilterScriptInit()	return print("\n\nClick PM By: Epsilon\n\n"),1;
public OnPlayerCommandText(playerid,cmdtext[]) { if(!strcmp(cmdtext,"/togpm",true)) if(tog[playerid]) return tog[playerid] = false, SendClientMessage(player[playerid], 0x33AA33AA, "Incoming pms disabled!"); else return tog[playerid] = true, SendClientMessage(player[playerid], 0x33AA33AA, "Incoming pms enabled!"); return 0; }
public OnPlayerConnect(playerid) return player[playerid] = INVALID_PLAYER_ID,1;
public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    if(dialogid == 2 && response)
    {
		new estr[128], ename[MAX_PLAYER_NAME];
		GetPlayerName(playerid,ename,sizeof(ename));
		format(estr,128,"%s's private message: %s", ename,inputtext);
		SendClientMessage(player[playerid], 0x33AA33AA, estr);
		format(estr,128,"Your private message: %s", inputtext);
		SendClientMessage(playerid, 0x33AA33AA, estr);
		player[playerid] = INVALID_PLAYER_ID;
		return 1;
	}
	return 0;
}
public OnPlayerClickPlayer(playerid, clickedplayerid, source)
{
	if(playerid == clickedplayerid) return 0; else if(tog[clickedplayerid]) return SendClientMessage(player[playerid], 0x33AA33AA, "That player disabled the pms!");
    ShowPlayerDialog(playerid,2,DIALOG_STYLE_INPUT,"Your message","Write down your message, what you want to send!!","Send","Clear");
    player[playerid] = clickedplayerid;
	return 1;
}
