/***
*
* File: wp_utils_phone.inc
* Auth: Damian Wojdat
* Date: 1.04.2012
* Desc: Internal script function related to phone.
*
*************************************************************************************************************/

timer BlinkPhoneCall[1500](playerid)
{
	if(gPhoneCallShowed[playerid])
	{
		TextDrawHideForPlayer(playerid, gPhoneCall);
		gPhoneCallShowed[playerid] = 0;
		if(IncommingCall[playerid])
			defer BlinkPhoneCall(playerid);
	}
	else if(!gPhoneCallShowed[playerid] && IncommingCall[playerid])
	{
		TextDrawShowForPlayer(playerid, gPhoneCall);
		gPhoneCallShowed[playerid] = 1;
		defer BlinkPhoneCall(playerid);
	}
}

timer BlinkPhoneText[1500](playerid)
{
	if(gPhoneTextShowed[playerid])
	{
		TextDrawHideForPlayer(playerid, gPhoneText);
		gPhoneTextShowed[playerid] = 0;
		defer BlinkPhoneText(playerid);
	}
	else if(!gPhoneTextShowed[playerid] && gPhoneTextReceived[playerid])
	{
		TextDrawShowForPlayer(playerid, gPhoneText);
		gPhoneTextShowed[playerid] = 1;
		defer BlinkPhoneText(playerid);
	}
}

timer DisconnectPhone[5000](playerid)
{
	new string[256];
	
	if(!IsPlayerInAnyVehicle(playerid))
	{
		SetPlayerSpecialAction(playerid,SPECIAL_ACTION_STOPUSECELLPHONE);
		RemovePlayerAttachedObject(playerid, 1);
	}
	
	if(Mobile[playerid] == 255)
	{
		return 0;
	}
	
	if(IsPlayerConnected(Mobile[playerid]) && gPlayerLogged[Mobile[playerid]])
	{
		if(Mobile[playerid] != INVALID_PLAYER_ID)
		{
			if(Mobile[playerid] < 255)
			{
				IncommingCall[Mobile[playerid]] = 0;
				IncommingCall[playerid] = 0;
				
				if(!IsPlayerInAnyVehicle(Mobile[playerid]))
				{
					SetPlayerSpecialAction(Mobile[playerid], SPECIAL_ACTION_STOPUSECELLPHONE);
					RemovePlayerAttachedObject(Mobile[playerid], 1);
				}

				if(StartedCall[playerid])
				{
					if(gPlayerVars[playerid][mPhoneType] == PHONET_FEE)
					{
						gPlayerData[playerid][pCost] += gCallCost[playerid];
						format(string, sizeof(string), "UPDATE `samp_phones` SET `FreeMins` = '%d' WHERE `Nr` = '%d' AND `SimID` = '%d'",
							gCallFreeMins[playerid], gPlayerVars[playerid][mPhoneNr], gPlayerVars[playerid][mPhoneSimID]);
						wp_mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
						printf("gCallFreeMins[%d], %d no disconnect", playerid, gCallFreeMins[playerid]);
					}
					else if(gPlayerVars[playerid][mPhoneType] == PHONET_CARD)
					{
						format(string, sizeof(string), "UPDATE `samp_phones` SET `Cash` = '%d' WHERE `Nr` = '%d' AND `SimID` = '%d'",
							gPlayerVars[playerid][mPhoneCash], gPlayerVars[playerid][mPhoneNr], gPlayerVars[playerid][mPhoneSimID]);
					}
					StartedCall[playerid] = 0;
				}
				else if(StartedCall[Mobile[playerid]])
				{
					if(gPlayerVars[Mobile[playerid]][mPhoneType] == PHONET_FEE)
					{
						gPlayerData[Mobile[playerid]][pCost] += gCallCost[Mobile[playerid]];
						format(string, sizeof(string), "UPDATE `samp_phones` SET `FreeMins` = '%d' WHERE `Nr` = '%d' AND `SimID` = '%d'",
							gCallFreeMins[Mobile[playerid]], gPlayerVars[Mobile[playerid]][mPhoneNr], gPlayerVars[Mobile[playerid]][mPhoneSimID]);
						wp_mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
						printf("gCallFreeMins[%d], %d no disconnect", Mobile[playerid], gCallFreeMins[Mobile[playerid]]);
					}
					else if(gPlayerVars[Mobile[playerid]][mPhoneType] == PHONET_CARD)
					{
						format(string, sizeof(string), "UPDATE `samp_phones` SET `Cash` = '%d' WHERE `Nr` = '%d' AND `SimID` = '%d'",
							gPlayerVars[Mobile[playerid]][mPhoneCash], gPlayerVars[Mobile[playerid]][mPhoneNr], gPlayerVars[Mobile[playerid]][mPhoneSimID]);
					}
					StartedCall[Mobile[playerid]] = 0;
				}
				if(Mobile[Mobile[playerid]] == playerid)
					Mobile[Mobile[playerid]] = 255;
				
				Mobile[playerid] = 255;
			}
			return 1;
		}
	}	
	
	return 0;
}

stock SendSmsToAll(playerid, senderNumber, string[256])
{
	gPlayerVars[playerid][mGlobalSmsSenderNumber] = senderNumber;
	format(gPlayerVars[playerid][mGlobalSms], sizeof(string), string);
	format(string, sizeof(string), "SELECT `Nr` FROM `samp_phones`");
	wp_mysql_query(string, SEND_SMS_TO_ALL, playerid, db_con4);
}
