// if(strcmp(cmd, "/do", true) == 0)
		// {
			// GetPlayerName(playerid, sendername, sizeof(sendername));
			// new length = strlen(cmdtext);
			// while ((idx < length) && (cmdtext[idx] <= ' '))
			// {
				// idx++;
			// }
			// new offset = idx;
			// new result[64];
			// while ((idx < length) && ((idx - offset) < (sizeof(result) - 1)))
			// {
				// result[idx - offset] = cmdtext[idx];
				// idx++;
			// }
			// result[idx - offset] = EOS;
			// if(!strlen(result))
			// {
				// SendClientMessage(playerid, COLOR_GRAD2, "[U¯YCIE:] /do [akcja]");
				// return 1;
			// }
			// else
			// {
				// format(string, sizeof(string), "* %s (( %s ))", result, sendername);
			// }
			// new Year, Month, Day;
			// getdate(Year, Month, Day);
			// new Hour, Minute, Second;
			// gettime(Hour, Minute, Second);
			// ProxDetector(30.0, playerid, string, COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE);
			// format(string, sizeof(string), "[%d/%d/%d][%d:%d.%d]* %s (( %s ))", Day, Month, Year, Hour, Minute,Second,result,sendername);
			// PlayerActionLog(string);
			// PlayerInfo[playerid][pRPCount]++;
			// SavePlayerData(playerid, "RPCount");
			// return 1;
		// }