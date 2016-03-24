// if(strcmp(cmd, "/ja", true) == 0)
		// {
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
				// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[U¯YCIE:] /ja [action]");
				// return 1;
			// }
			// new form[128];
			// format(form, sizeof(form), "%s",result);
			// PlayerActionMessage(playerid,15.0,form);
			// PlayerInfo[playerid][pRPCount]++;
			// SavePlayerData(playerid, "RPCount");
			// return 1;
		// }