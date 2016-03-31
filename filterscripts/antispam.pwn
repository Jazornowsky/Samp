#include <a_samp>
#include <foreach>
new msgCount[MAX_PLAYERS];
new cmdCount[MAX_PLAYERS];
#define  COLOR_GREY 0xAFAFAFAA

public OnPlayerText(playerid, text[])
{
	msgCount[playerid]++;
	if(msgCount[playerid] > 2)
	{
		SendClientMessage(playerid, COLOR_GREY, "[INFO:] Przekroczono dopuszczalny limit wiadomoœci na sekunde, polecenie nie zosta³o wykonane");
		return 0;
	}
	else if(msgCount[playerid] > 4)
		return 0;
	return 1;
}	

public OnPlayerCommandText(playerid, cmdtext[])
{
	cmdCount[playerid]++;
	if(cmdCount[playerid] > 2)
	{
		SendClientMessage(playerid, COLOR_GREY, "[INFO:] Przekroczono dopuszczalny limit komend na sekunde, polecenie nie zosta³o wykonane");
		return 0;
	}
	else if(cmdCount[playerid] > 4)
		return 0;
	return 1;
}

public OnPlayerDisconnect(playerid, reason)
{
	msgCount[playerid] = 0;
	cmdCount[playerid] = 0;
}
