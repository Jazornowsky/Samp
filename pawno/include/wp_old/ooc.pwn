// if(strcmp(cmd, "/ooc", true) == 0 || strcmp(cmd, "/o", true) == 0)
		// {
			// if(IsPlayerConnected(playerid))
			// {
				// if(gPlayerLogged[playerid] == 0)
				// {
					// SendClientMessage(playerid, COLOR_GREY, "[INFO:] Nie jesteœ zalogowany !");
					// return 1;
				// }
				// if ((noooc) && PlayerInfo[playerid][pAdmin] < 1)
				// {
					// SendClientMessage(playerid, COLOR_GRAD2, "[INFO:] Chat OOC zosta³ wy³¹czony przez administratora !");
					// return 1;
				// }
				// if(PlayerInfo[playerid][pMuted] == 1)
				// {
					// SendClientMessage(playerid, COLOR_LIGHTRED, "[INFO:] Nie mo¿esz u¿ywaæ tego chatu kiedy jesteœ uciszony !");
					// return 1;
				// }
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
					// SendClientMessage(playerid, COLOR_GRAD2, "[U¯YCIE:] (/o)oc [ooc chat]");
					// return 1;
				// }
				// format(string, sizeof(string), "[OOC] [%s] [%d]: %s " , PlayerInfo[playerid][pOOCName], playerid, result);
				// OOCOff(COLOR_OOC,string);
				// printf("%s", string);
				// new Year, Month, Day;
				// getdate(Year, Month, Day);
				// new Hour, Minute, Second;
				// gettime(Hour, Minute, Second);
				// format(string, sizeof(string), "[OOC][%02d/%02d/%d][%02d:%02d:%02d] [%s] [%d] : %s", Day, Month, Year, Hour, Minute, Second, PlayerInfo[playerid][pOOCName], playerid, result);
				// OOCLog(string);
			// }
			// return 1;
		// }