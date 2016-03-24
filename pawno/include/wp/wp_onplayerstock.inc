public OnPlayerConnect(playerid)
{	
	/* Reset player variables */
	ResetStats(playerid);
	
	/* Check player name for RP rule */
	new plname[MAX_PLAYER_NAME];
	GetPlayerName(playerid, plname, sizeof(plname));
	new namestring = strfind(plname, "_", true);
	if(namestring == -1)
	{
		SendClientMessage(playerid, COLOR_RED, "Twoja nazwa gracza nie jest zgodna z wymogami Role-Play !");
		SendClientMessage(playerid, COLOR_RED, "Spróbuj u¿yæ nazwy w postaci Imie_Nazwisko !");
		Kick(playerid);
		return 1;
	}
	
	/* Some UAC shit */
	// for(new s = 0; s < BadNameCount; s++)
	// {
		// if(!strcmp(BadNames[s],GetName(playerid),true))
		// {
			// SendClientMessage(playerid, COLOR_RED, "[ANTI-CHEAT:] Zosta³eœ wyrzucony poniewa¿ masz niedozwolony nick !");
			// format(string, sizeof(string), "[ANTI-CHEAT:] %s (id:%d) zosta³ wyrzucony z serwera ze wzglêdu na zabroniony nick !", GetName(playerid), playerid);
			// SendClientMessageToAll(COLOR_LIGHTGREEN, string);
			// Kick(playerid);
			// return 1;
		// }
	// }

	/* Dancing login animation */
	gPlayerData[playerid][SpawnDance] = true;
    // ApplyAnimation(playerid,"DANCING","DNCE_M_B",4.0,1,0,0,0,-1); //preventing a bug for the animation not being applied the first time
	
	return 1;
}

public OnPlayerDisconnect(playerid, reason)
{
	// KillTimer( gPlayerData[playerid][SpawnTimer] );

	//===================================[GET PLAYER DATA]=====================================
	new plname[128];
	GetPlayerName(playerid, plname, sizeof(plname));
	new Float:x,Float:y,Float:z;
	GetPlayerPos(playerid,x,y,z);

    if(gPlayerLogged[playerid] && strcmp(plname, gPlayerData[playerid][pName], false) == 0)
	{
		DestroyProgressBar(JobProgress[playerid]);
		DestroyProgressBar(gPlayerData[playerid][pHungerProgressBarID]);
	
		Update3DTextLabelText( gPlayerData[playerid][pCharDescriptionID], COLOR_WHITE, " " );
		
		// DestroyDynamic3DTextLabel(playerAFK[playerid]);
	
		GetPlayerWeaponData(playerid, 0, gPlayerData[playerid][pWSlot0], gPlayerData[playerid][pWSlot0Ammo]);
		SavePlayerData(playerid, "WSlot0");
		SavePlayerData(playerid, "WSlot0Ammo");

		GetPlayerWeaponData(playerid, 1, gPlayerData[playerid][pWSlot1], gPlayerData[playerid][pWSlot1Ammo]);
		SavePlayerData(playerid, "WSlot1");
		SavePlayerData(playerid, "WSlot1Ammo");

		GetPlayerWeaponData(playerid, 2, gPlayerData[playerid][pWSlot2], gPlayerData[playerid][pWSlot2Ammo]);
		SavePlayerData(playerid, "WSlot2");
		SavePlayerData(playerid, "WSlot2Ammo");

		GetPlayerWeaponData(playerid, 3, gPlayerData[playerid][pWSlot3], gPlayerData[playerid][pWSlot3Ammo]);
		SavePlayerData(playerid, "WSlot3");
		SavePlayerData(playerid, "WSlot3Ammo");

		GetPlayerWeaponData(playerid, 4, gPlayerData[playerid][pWSlot4], gPlayerData[playerid][pWSlot4Ammo]);
		SavePlayerData(playerid, "WSlot4");
		SavePlayerData(playerid, "WSlot4Ammo");

		GetPlayerWeaponData(playerid, 5, gPlayerData[playerid][pWSlot5], gPlayerData[playerid][pWSlot5Ammo]);
		SavePlayerData(playerid, "WSlot5");
		SavePlayerData(playerid, "WSlot5Ammo");

		GetPlayerWeaponData(playerid, 6, gPlayerData[playerid][pWSlot6], gPlayerData[playerid][pWSlot6Ammo]);
		SavePlayerData(playerid, "WSlot6");
		SavePlayerData(playerid, "WSlot6Ammo");
		if(Mobile[playerid] != 255)
		{
			if(IsPlayerConnected(Mobile[playerid]) && gPlayerLogged[Mobile[playerid]])
			{
				SendClientMessage(Mobile[playerid], COLOR_LIGHTGREEN, "[TELEFON:] Roz³¹czy³ siê.");
				if(!IsPlayerInAnyVehicle(Mobile[playerid]))
				{
					SetPlayerSpecialAction(Mobile[playerid], SPECIAL_ACTION_STOPUSECELLPHONE);
					RemovePlayerAttachedObject(Mobile[playerid], 4);
				}	
				if(StartedCall[playerid])
				{
					new callcost = random(100);
					GivePlayerCash(playerid,-callcost);
					// TODO: Check if gPlayerData[playerid][pPhoneC] is not deprecated
					Businesses[gPlayerData[playerid][pPhoneC]][Till] += callcost;
					SaveBizData(gPlayerData[playerid][pPhoneC], "Till");
					StartedCall[playerid] = 0;
				}
				else if(StartedCall[Mobile[playerid]])
				{
					new callcost = random(100);
					GivePlayerCash(Mobile[playerid],-callcost);
					Businesses[gPlayerData[Mobile[playerid]][pPhoneC]][Till] += callcost;
					SaveBizData(gPlayerData[Mobile[playerid]][pPhoneC], "Till");
					StartedCall[Mobile[playerid]] = 0;
				}
				if(	Mobile[Mobile[playerid]] == playerid )
					Mobile[Mobile[playerid]] = 255;
			}
		}
		if(x == 0.0 || y == 0.0)
		{
			printf("[WARINING:] OnPlayerDisconnect X: %f, Y: %f, Z: %f, player name: %s", x, y, z, GetPlayerNameEx(playerid));
		}
	    if(reason == 0)
	    {
			gPlayerData[playerid][pCrashed] = 1;
			PlayerLocalMessage(playerid,15.0,"ma problem z po³¹czaniem");
	    }
		else
		{
			new string[128];
			format(string, sizeof(string), "{DF013A}[WParty SERVER:]{FFFFFF}[ID: %d][IC: %s] %s %s opuœci³ gre !", playerid, GetPlayerNameEx(playerid), gPlayerData[playerid][pOOCName]);
			SendClientMessageToAll(0xFFFFFFAA,string);
		}

		//=================================[SAVE PLAYER POS DATA]==================================
		if(GetPlayerVirtualWorld(playerid) == 0 && GetPlayerInterior(playerid) == 0)
		{
			gPlayerData[playerid][pCrashX] = x;
			gPlayerData[playerid][pCrashY] = y;
			gPlayerData[playerid][pCrashZ] = z;
			gPlayerData[playerid][pCrashInt] = 0;
			gPlayerData[playerid][pCrashW] = 0;
			GetPlayerFacingAngle(playerid, gPlayerData[playerid][pCrashAngle]);
			SavePlayerData(playerid, "Crash");
		}

		SavePlayerData(playerid, "Crashed");
		SavePlayerData(playerid, "Cash");

		Spawned[playerid] = 0; 	// UAC
		
		for(new n = 0; n < CUSTOM_MAX_PLAYERS; n++)
		{
			if(gSpectateID[n] == playerid)
				gSpectateID[n] = INVALID_PLAYER_ID;
		}
	}
	return 1;
} // end of OnPlayerDisconnect

public OnPlayerRequestClass(playerid, classid)
{
	//printf("[CALLBACK:] Player [%d] request class", playerid);
	Alive[playerid] = 0;

	if (IsPlayerNPC(playerid))
    {
		SendClientMessageToAll(0x00000000,"A new NPC connected!");
		return 1;
    }
	else
	{
		if(gPlayerLogged[playerid])
		{
			SpawnPlayer(playerid);
			return 1;
		}
		else
		{
			SetPlayerPos(playerid, player_x,player_y,player_z-5);
			SetPlayerFacingAngle(playerid, player_angle);
			SetPlayerCameraPos(playerid, camera_x,camera_y,camera_z);
			SetPlayerCameraLookAt(playerid, player_x,player_y,player_z);
			// ApplyAnimation(playerid,"DANCING","DNCE_M_B",4.0,1,0,0,0,-1); //smooth dancing. It's most fitting to the music
			PlayerPlaySound(playerid, 1097,-119.9460,23.1096,12.2238); //music, duh
			//making sure the timer gets executed only once, so the camera doesn't go to fast

			// if (gPlayerData[playerid][SpawnDance]) gPlayerData[playerid][SpawnTimer] = SetTimerEx("MoveCamera", moving_speed, true, "i", playerid);
			// gPlayerData[playerid][SpawnDance] = false; //preventing the timer to execute again
			// ClearScreen(playerid);//Clearing the users screen from SA-MP messages.
		
			new string[1024];
			strcat( string, "{FFFFFF}Witaj na serwerze WParty !\n\n" );
			strcat( string, "Aby siê zalogowaæ wpisz swoje has³o do postaci.\n\n\n" );
			strcat( string, "{F52222}Jeœli nie posiadasz jeszcze postaci musisz wpierw zarejestrowaæ swoje konto\nna forum wpartyrp.pl a nastêpnei utworzyæ postaæ\npostêpuj¹æ wed³ug podanych tam wskazówek.\n\n" );
			strcat( string, "{FAEC25}Jeœli zapomnia³eœ has³a do postaci mo¿esz je zmieniæ loguj¹c siê na forum\na nastêpnie przechodz¹c do panelu zarz¹dzania postaciami.\n\n\n" );
			strcat( string, "{FFFFFF}Wpisz has³o:" );
			ShowPlayerDialog(playerid, DIALOG_LOGIN, DIALOG_STYLE_PASSWORD, "Logowanie", string, "Zaloguj", "");
	
			return 0;
		}
	}
}

public OnPlayerRequestSpawn(playerid)
{
	//printf("[CALLBACK:] Player [%d] request spawn", playerid);
	if (IsPlayerNPC(playerid))
	{
		return 1;
	}
	else
	{
		if(gPlayerLogged[playerid] == 0)
		{
			if(SpawnAttempts[playerid] >= MAX_SPAWN_ATTEMPTS)
			{
				KickPlayer(playerid,"System","Próba respawnu bez logowania.");
				return 1;
			}
			SendClientMessage(playerid,COLOR_RED,"[INFO:] Musisz siê zalogowaæ zanim do³¹czysz do gry!");
			SpawnAttempts[playerid]++;
			return 0;
		}
		return 1;
	}
}

public OnPlayerSpawn(playerid)
{	
	gPlayerData[playerid][SpawnAngle] = 0.0; //so when you leave and another player comes, the camera will start from start
    gPlayerData[playerid][SpawnDance] = true; //to not execute to much timers
	// KillTimer( gPlayerData[playerid][SpawnTimer] ); //to kill it, since its useless now
	PlayerPlaySound(playerid, 1186, 0.0, 0.0, 0.0); // (blank sound) to shut the music up
    SetCameraBehindPlayer(playerid); //to prevent some bugs
	SetPlayerSpawn(playerid);
	SetPlayerWantedLevelEx(playerid, gPlayerData[playerid][pWantedLvl]);		
	Alive[playerid] = 1;
	CheckDelay[playerid] = 2;
	SpawnedInWorld(playerid); //UAC
	PosHackCheckTime[playerid] = 5;	//UAC
	return 1;
}

public OnPlayerDeath(playerid, killerid, reason)
{
	printf("[CALLBACK:] OnPlayerDeath");
	if( !gPlayerLogged[playerid] )
		return 1;
	new string[128];
	new Float:x,Float:y,Float:z;
	GetPlayerPos( playerid, x, y, z );
	gPlayerData[playerid][pCrashX] = x;
	gPlayerData[playerid][pCrashY] = y;
	gPlayerData[playerid][pCrashZ] = z;
	gPlayerData[playerid][pCrashW] = GetPlayerVirtualWorld(playerid);
	gPlayerData[playerid][pCrashInt] = GetPlayerInterior(playerid);
	SavePlayerData(playerid, "Crash");
	Alive[playerid] = 0;
	JustDied[playerid] = 1;
	Spawned[playerid] = 0; // UAC
	CheckDelay[playerid] = 10;
	gPlayerData[playerid][pSeatBelt] = 0;
	SavePlayerData(playerid, "SeatBelt");
	gPlayerData[playerid][pDeathCount]++;
	SavePlayerData(playerid, "DeathCount");	
	TextDrawHideForPlayer(playerid, Status[playerid]);
	BW(playerid);

	for(new i = 0; i < CUSTOM_MAX_PLAYERS; i++ )
	{
		if(gPlayerData[i][pFaction] == 2 && gPlayerData[i][pGPS] == 1 && gPlayerData[playerid][pAdmin] == 0)
		{
			SetPlayerCheckpoint(i,x+50+random(50),y+50+random(50),z,200.0);

			ClearCheckpointsForPlayer(playerid);

			format(string, sizeof(string),"(( [Radio:] Otrzymaliœmy anonimowe zg³oszenie o potrzebuj¹cej osobie ! Wolna jednostka potrzebna na miejscu ! ))");
			SendFactionMessage(2,COLOR_FACTIONCHAT,string);
		}
	}
	if(IsPlayerConnected(killerid))
	{
	    if(killerid != playerid)
	    {
			if( gGangWar[Enabled] == 1 )
			{
				if( gPlayerData[killerid][pFaction] == gGangWar[FactionStarted] && gPlayerData[playerid][pFaction] == DynamicZones[ gGangWar[AreaID] ][zFaction]  )
					gGangWar[FactionStartedKills]++;
				else if( gPlayerData[playerid][pFaction] == gGangWar[FactionStarted] && gPlayerData[killerid][pFaction] == DynamicZones[ gGangWar[AreaID] ][zFaction] )
					gGangWar[FactionAttackedKills]++;
			}
	     	if( AdminDuty[playerid] && !AdminDuty[killerid] )
		    {
				KickPlayer(killerid,"System","Zabicie administratora na s³u¿bie.");
				format(string, sizeof(string), "[INFO:] Gracz %s zosta³ wyrzucony z serwera za u¿ywanie cheatów.", PlayerName(killerid));
				KickLog(string);
		    }
			if(AdminDuty[killerid])
			{
				gPlayerData[playerid][pDeathCount]--;
				SavePlayerData(playerid, "DeathCount");
			}
			if(gPlayerData[killerid][pFaction] == 0)
			{
				if(gPlayerData[killerid][pDuty] == 1)
				{
					if(gPlayerData[playerid][pWantedLvl] == 0)
					{
						format(string, sizeof(string), "[INFO:] Zabi³eœ niewinnego cz³owieka !");
						SendClientMessage(killerid, COLOR_RED, string);
						for(new i = 0; i < CUSTOM_MAX_PLAYERS; i++ )
						{
							if(gPlayerData[i][pFaction] < sizeof(DynamicFactions))
							{
								if(DynamicFactions[gPlayerData[i][pFaction]][fType] == 1)
									PlayCrimeReportForPlayer(i, killerid, 6); //uzycie broni
							}
						}
					}
				}
				else if(gPlayerData[killerid][pDuty] == 0)
				{
					// format(string, sizeof(string), "[SFPD:] Podejrzany %s zabi³ %s.", PlayerName(killerid), PlayerName(playerid));
					// SendFactionTypeMessage(1,COLOR_LSPD,string);
					// format(string, sizeof(string), "[INFO:] Zabi³eœ niewinnego cz³owieka ! Jesteœ poszukiwany !");
					format(string, sizeof(string), "[INFO:] Zabi³eœ niewinnego cz³owieka !");
					SendClientMessage(playerid, COLOR_RED, string);
					for(new i = 0; i < CUSTOM_MAX_PLAYERS; i++ )
					{
						if(gPlayerData[i][pFaction] < sizeof(DynamicFactions))
						{
							if(DynamicFactions[gPlayerData[i][pFaction]][fType] == 1)
							{
								PlayCrimeReportForPlayer(i, killerid, 3); //inne
							}
						}
					}
				}
			}
			else if(gPlayerData[killerid][pFaction] != 0 && gPlayerData[killerid][pFaction] != 6)
			{
				// format(string, sizeof(string), "[SFPD:] Podejrzany %s zabi³ %s.", PlayerName(killerid), PlayerName(playerid));
				// SendFactionTypeMessage(1,COLOR_LSPD,string);
				format(string, sizeof(string), "[INFO:] Zabi³eœ niewinnego %s !", PlayerName(playerid));
				SendClientMessage(killerid, COLOR_RED, string);
				// SetPlayerWantedLevelEx(killerid,GetPlayerWantedLevelEx(killerid)+1);
				// gPlayerData[killerid][pWantedLvl]++;
				// SavePlayerData(killerid, "WantedLvl");
				for(new i = 0; i < CUSTOM_MAX_PLAYERS; i++ )
				{
					if(gPlayerData[i][pFaction] < sizeof(DynamicFactions))
					{
						if(DynamicFactions[gPlayerData[i][pFaction]][fType] == 1)
						{
							PlayCrimeReportForPlayer(i, killerid, 3); //inne
						}
					}
				}
			}
	    }
	}
	if (gPlayerData[killerid][pAdmin] < 1)
	{
		if(reason == 38)
		{
			new kstring[128];
			new kickname[MAX_PLAYER_NAME];
			if(IsPlayerConnected(killerid))
			{
				GetPlayerName(killerid, kickname, sizeof(kickname));
				format(string, 256, "[ANTY-CHEAT] [%d]%s zabi³ [%d]%s z minigun. Gracz zostaje zbanowany",killerid,kickname,playerid,gPlayerData[playerid][pName]);
				ABroadCast(COLOR_LIGHTRED,string,1);
				printf("%s", kstring);
				gPlayerData[killerid][pBanned] = 1;
				SavePlayerData(killerid, "Banned");
				Ban(killerid);

			}
		}
		else if(reason == 35)
		{
			new kstring[128];
			new kickname[MAX_PLAYER_NAME];
			if(IsPlayerConnected(killerid))
			{
				GetPlayerName(killerid, kickname, sizeof(kickname));
				format(string, 256, "[ADMIN] [%d]%s zabil gracza z flamethrower, %s zostal zbanowany.",killerid,kickname,kickname);
				ABroadCast(COLOR_LIGHTRED,string,1);
				printf("%s", kstring);
				Ban(killerid);
				gPlayerData[killerid][pBanned] = 1 ;
				SavePlayerData(killerid, "Banned");
			}
		}
		else if(reason == 9)
		{
			new kstring[128];
			new kickname[MAX_PLAYER_NAME];
			if(IsPlayerConnected(killerid))
			{
				GetPlayerName(killerid, kickname, sizeof(kickname));
				format(string, 256, "[ADMIN] [%d]%s zabil gracza z chainsaw, %s zostal zbanowany.",killerid,kickname,kickname);
				ABroadCast(COLOR_LIGHTRED,string,1);
				printf("%s", kstring);
				Ban(killerid);
				gPlayerData[killerid][pBanned] = 1;
				SavePlayerData(killerid, "Banned");
			}
		}
		else if(gPlayerData[killerid][pFaction] != 6)
		{
			if(reason == 16)
			{
				new kstring[128];
				new kickname[MAX_PLAYER_NAME];
				if(IsPlayerConnected(killerid))
				{
					GetPlayerName(killerid, kickname, sizeof(kickname));
					format(string, 256, "[ADMIN] [%d]%s zabil gracza z grenades, %s zostal zbanowany.",killerid,kickname,kickname);
					ABroadCast(COLOR_LIGHTRED,string,1);
					printf("%s", kstring);
					Ban(killerid);
					gPlayerData[killerid][pBanned] = 1;
					SavePlayerData(killerid, "Banned");
				}
			}
		}
		else if(reason == 18)
		{
			new kstring[128];
			new kickname[MAX_PLAYER_NAME];
			if(IsPlayerConnected(killerid))
			{
				GetPlayerName(killerid, kickname, sizeof(kickname));
				format(string, 256, "[ADMIN] [%d]%s zabil gracza z molotovs, %s zostal zbanowany.",killerid,kickname,kickname);
				ABroadCast(COLOR_LIGHTRED,string,1);
				printf("%s", kstring);
				Ban(killerid);
				gPlayerData[killerid][pBanned] = 1;
				SavePlayerData(killerid, "Banned");
			}
		}
		else if(reason == 36)
		{
			new kstring[128];
			new kickname[MAX_PLAYER_NAME];
			if(IsPlayerConnected(killerid))
			{
				GetPlayerName(killerid, kickname, sizeof(kickname));
				format(string, 256, "[ADMIN] [%d]%s zabil gracza z Lock On Launcher, %s zostal zbanowany.",killerid,kickname,kickname);
				ABroadCast(COLOR_LIGHTRED,string,1);
				printf("%s", kstring);
				Ban(killerid);
				gPlayerData[killerid][pBanned] = 1;
				SavePlayerData(killerid, "Banned");
			}
		}
	}
	return 1;
} // end of OnPlayerDeath

public OnPlayerInteriorChange(playerid, newinteriorid, oldinteriorid)
{
	PosHackCheckTime[playerid] = 5;
	for(new n = 0; n < CUSTOM_MAX_PLAYERS; n++)
	{
		if(GetPlayerState(n) == PLAYER_STATE_SPECTATING)
		{
			if(gSpectateID[n] == playerid)
			{
				SetPlayerInterior(n,GetPlayerInterior(gSpectateID[n]));
				TogglePlayerSpectating(n, 1);
				PlayerSpectatePlayer(n, playerid);
			}
		}
	}
}

public OnPlayerText(playerid, text[])
{
	if( !gPlayerLogged[playerid] )
		return 0;
	if( gPlayerData[playerid][pMuted] )
		return 0;
	new string[256], part1[128], part2[128];
	new plName[32];
	strins( plName, GetPlayerNameEx( playerid ), 0 );
	PlayerWrittingAnything[playerid] = 1;
	// UpdateDynamic3DTextLabelText(playerAFK[playerid], COLOR_LIGHTBLUE, " ");
	// if(gPlayerData[playerid][pTutorial] == 1)
	// {
		// if(RegistrationStep[playerid] == 1)
		// {
			// new age = strval(text);
			// if (age >= 18 && age <= 100)
			// {
				// new wstring[128];
				// format(wstring, sizeof(wstring), "[INFO:] Ustawi³eœ swój wiek na: %d.", age);
				// SendClientMessage(playerid,COLOR_LIGHTYELLOW2, wstring);
				// gPlayerData[playerid][pAge] = age;
				// RegistrationStep[playerid] = 2;
				// SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] Podaj p³eæ: wpisz facet lub kobieta.");
			// }
			// else
			// {
				// SendClientMessage(playerid,COLOR_RED,"[INFO:] Nieprawid³owy wiek, poprawne wartoœci to: 10-100.");
			// }
			// return 0;
		// }
		// if(RegistrationStep[playerid] == 2)
		// {
			// new idx2;
			// tmp = strtok(text, idx2);
			// if((strcmp("facet", tmp, true, strlen(tmp)) == 0) && (strlen(tmp) == strlen("facet")))
			// {
				// gPlayerData[playerid][pSex] = 1;
				// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ustawi³eœ swoj¹ p³eæ na pe³nokrwistego samca.");
				// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Prosze zapoznaj siê z /zasady /faq /komendy /prawko /pomoc.");
				// RegistrationStep[playerid] = 0;
				// TogglePlayerControllable(playerid,1);
				// gPlayerData[playerid][pRegistered] = 1;
				// SetSpawnInfo(playerid, 0, gPlayerData[playerid][pSkin],CivilianSpawn[X],CivilianSpawn[Y],CivilianSpawn[Z],0,0,0,0,0,0,0);
				// gPlayerData[playerid][pCrashX] = -1951.84;
				// gPlayerData[playerid][pCrashY] = 137.79;
				// gPlayerData[playerid][pCrashZ] = 26.2812;
				// SpawnPlayer(playerid);
				// SetCameraBehindPlayer(playerid);
				// return 0;
			// }
			// else if((strcmp("kobieta", tmp, true, strlen(tmp)) == 0) && (strlen(tmp) == strlen("kobieta")))
			// {
				// gPlayerData[playerid][pSex] = 2;
				// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ustawi³aœ swoj¹ p³eæ na babe.");
				// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Prosze zapoznaj siê z /zasady /faq /komendy /prawko /pomoc.");
				// RegistrationStep[playerid] = 0;
				// TogglePlayerControllable(playerid,1);
				// gPlayerData[playerid][pRegistered] = 1;
				// SetSpawnInfo(playerid, 0, gPlayerData[playerid][pSkin],0,0,0,0,0,0,0,0,0,0);
				// SpawnPlayer(playerid);
				// SetCameraBehindPlayer(playerid);
				// return 0;
			// }
			// else
			// {
				// SendClientMessage(playerid, COLOR_RED, "[INFO:] Niew³aœciwa p³eæ: wpisz facet lub kobieta.");
			// }
			// return 0;
		// }
	// }
	if(Mobile[playerid] == 997)
	{
		if( strlen(text) > 56 )
		{
			strdel( part1, 0, sizeof(part1) );
			strdel( part2, 0, sizeof(part1) );
			strmid( part1, text, 0, 55 );
			strmid( part2, text, 55, 110 );
			format( string, sizeof(string), "[997 TEL:] [%d] %s mówi: %s", plName, playerid, part1 );
			SendFactionTypeMessage( 1, COLOR_LSPD, string );
			format( string, sizeof(string), "[997 TEL:] [%d] %s mówi: %s", plName, playerid, part2 );
			SendFactionTypeMessage( 1, COLOR_LSPD, string );
			strdel( part1, 0, sizeof(part1) );
			strdel( part2, 0, sizeof(part1) );
			strmid( part1, text, 0, 82 );
			strmid( part2, text, 82, 165 );
			format(string, sizeof(string), "[TEL] %s mówi: %s", plName, part1);
			ProxDetector(20.0, playerid, string, COLOR_FADE1,COLOR_FADE2,COLOR_FADE3,COLOR_FADE4,COLOR_FADE5);
			TalkLog(string);
			format(string, sizeof(string), "[TEL] %s mówi: %s", plName, part2);
			ProxDetector(20.0, playerid, string, COLOR_FADE1,COLOR_FADE2,COLOR_FADE3,COLOR_FADE4,COLOR_FADE5);
			TalkLog(string);
		}
		else
		{
			format(string, sizeof(string), "[997 TEL:] [%d] %s mówi: %s",plName, playerid, text);
			SendFactionTypeMessage(1, COLOR_LSPD, string);
			format(string, sizeof(string), "[TEL] %s mówi: %s", plName, text);
			ProxDetector(20.0, playerid, string, COLOR_FADE1,COLOR_FADE2,COLOR_FADE3,COLOR_FADE4,COLOR_FADE5);
			TalkLog(string);
		}
		SendClientMessage(playerid,COLOR_WHITE,"[Operator:] Twoja rozmowa zosta³a nagrana, prosze czekaæ.");
		Mobile[playerid] = 255;
		if(!IsPlayerInAnyVehicle(playerid))
		{
			SetPlayerSpecialAction(playerid,SPECIAL_ACTION_STOPUSECELLPHONE);
			RemovePlayerAttachedObject(playerid, 4);
		}
		return 0;
	}
	if(Mobile[playerid] == 999)
	{
		if( strlen(text) > 56 )
		{
			strdel( part1, 0, sizeof(part1) );
			strdel( part2, 0, sizeof(part1) );
			strmid( part1, text, 0, 55 );
			strmid( part2, text, 55, 110 );
			format( string, sizeof(string), "[999 TEL:] [%d] %s mówi: %s", plName, playerid, part1 );
			SendFactionTypeMessage( 1, COLOR_RED, string );
			format( string, sizeof(string), "[999 TEL:] [%d] %s mówi: %s", plName, playerid, part2 );
			SendFactionTypeMessage( 1, COLOR_RED, string );
			strdel( part1, 0, sizeof(part1) );
			strdel( part2, 0, sizeof(part1) );
			strmid( part1, text, 0, 82 );
			strmid( part2, text, 82, 165 );
			format(string, sizeof(string), "[TEL] %s mówi: %s", plName, part1);
			ProxDetector(20.0, playerid, string, COLOR_FADE1,COLOR_FADE2,COLOR_FADE3,COLOR_FADE4,COLOR_FADE5);
			TalkLog(string);
			format(string, sizeof(string), "[TEL] %s mówi: %s", plName, part2);
			ProxDetector(20.0, playerid, string, COLOR_FADE1,COLOR_FADE2,COLOR_FADE3,COLOR_FADE4,COLOR_FADE5);
			TalkLog(string);
		}
		else
		{
			format(string, sizeof(string), "[999 TEL:] [%d] %s mówi: %s",plName, playerid, text);
			SendFactionTypeMessage(1, COLOR_RED, string);
			format(string, sizeof(string), "[TEL] %s mówi: %s", plName, text);
			ProxDetector(20.0, playerid, string, COLOR_FADE1,COLOR_FADE2,COLOR_FADE3,COLOR_FADE4,COLOR_FADE5);
			TalkLog(string);
		}
		SendClientMessage(playerid,COLOR_WHITE,"[Operator:] Twoja rozmowa zosta³a nagrana, prosze czekaæ.");
		Mobile[playerid] = 255;
		if(!IsPlayerInAnyVehicle(playerid))
		{
			SetPlayerSpecialAction(playerid,SPECIAL_ACTION_STOPUSECELLPHONE);
			RemovePlayerAttachedObject(playerid, 4);
		}
		TalkLog(string);
		return 0;
	}
	if(Mobile[playerid] == 411)
	{
		if( strlen(text) > 55 )
		{
			strdel( part1, 0, sizeof(part1) );
			strdel( part2, 0, sizeof(part1) );
			strmid( part1, text, 0, 54 );
			strmid( part2, text, 54, 109 );
			format( string, sizeof(string), "[TAXI TEL:] [%d] %s mówi: %s", plName, playerid, part1 );
			SendFactionTypeMessage( 1, COLOR_LIGHTRED, string );
			format( string, sizeof(string), "[TAXI TEL:] [%d] %s mówi: %s", plName, playerid, part2 );
			SendFactionTypeMessage( 1, COLOR_LIGHTRED, string );
			strdel( part1, 0, sizeof(part1) );
			strdel( part2, 0, sizeof(part1) );
			strmid( part1, text, 0, 82 );
			strmid( part2, text, 82, 165 );
			format(string, sizeof(string), "[TEL] %s mówi: %s", plName, part1);
			ProxDetector(20.0, playerid, string, COLOR_FADE1,COLOR_FADE2,COLOR_FADE3,COLOR_FADE4,COLOR_FADE5);
			TalkLog(string);
			format(string, sizeof(string), "[TEL] %s mówi: %s", plName, part2);
			ProxDetector(20.0, playerid, string, COLOR_FADE1,COLOR_FADE2,COLOR_FADE3,COLOR_FADE4,COLOR_FADE5);
			TalkLog(string);
		}
		else
		{
			format(string, sizeof(string), "[TAXI TEL:] [%d] %s mówi: %s",plName, playerid, text);
			SendFactionTypeMessage(1, COLOR_LIGHTRED, string);
			format(string, sizeof(string), "[TEL] %s mówi: %s", plName, text);
			ProxDetector(20.0, playerid, string, COLOR_FADE1,COLOR_FADE2,COLOR_FADE3,COLOR_FADE4,COLOR_FADE5);
			TalkLog(string);
		}
		Mobile[playerid] = 255;
		if(!IsPlayerInAnyVehicle(playerid))
		{
			SetPlayerSpecialAction(playerid,SPECIAL_ACTION_STOPUSECELLPHONE);
			RemovePlayerAttachedObject(playerid, 4);
		}
		TalkLog(string);
		return 0;
	}
	if(Mobile[playerid] != 255)
	{
		if( strlen(text) > 83 )
		{
			strdel( part1, 0, sizeof(part1) );
			strdel( part2, 0, sizeof(part1) );
			strmid( part1, text, 0, 82 );
			strmid( part2, text, 82, 165 );
			format(string, sizeof(string), "[TEL] %s mówi: %s", plName, part1);
			ProxDetector(20.0, playerid, string, COLOR_FADE1,COLOR_FADE2,COLOR_FADE3,COLOR_FADE4,COLOR_FADE5);
			TalkLog(string);
			format(string, sizeof(string), "[TEL] %s mówi: %s", plName, part2);
			ProxDetector(20.0, playerid, string, COLOR_FADE1,COLOR_FADE2,COLOR_FADE3,COLOR_FADE4,COLOR_FADE5);
			TalkLog(string);
		}
		else
		{
			format(string, sizeof(string), "[TEL] %s mówi: %s", plName, text);
			ProxDetector(20.0, playerid, string, COLOR_FADE1,COLOR_FADE2,COLOR_FADE3,COLOR_FADE4,COLOR_FADE5);
			TalkLog(string);
		}
		if(IsPlayerConnected(Mobile[playerid]))
		{
			if(Mobile[Mobile[playerid]] == playerid)
			{
				new Float:SpeakerX,Float:SpeakerY,Float:SpeakerZ;
				GetPlayerPos(playerid,SpeakerX,SpeakerY,SpeakerZ);
				if(!PlayerToPoint(20.0,Mobile[playerid],SpeakerX,SpeakerY,SpeakerZ))
				{
					if( strlen(text) > 83 )
					{
						format(string, sizeof(string), "[TEL] %s mówi: %s", plName, part1);
						SendClientMessage(Mobile[playerid], COLOR_LIGHTGREEN, string);
						format(string, sizeof(string), "[TEL] %s mówi: %s", plName, part2);
						SendClientMessage(Mobile[playerid], COLOR_LIGHTGREEN,string);
					}
					else
					{
						format(string, sizeof(string), "[TEL] %s mówi: %s", plName, text);
						SendClientMessage(Mobile[playerid], COLOR_LIGHTGREEN,string);
					}
					// SendClientMessage(playerid, COLOR_LIGHTGREEN,string);
				}
				if(SpeakerPhone[Mobile[playerid]])
				{
					if( strlen(text) > 79 )
					{
						strdel( part1, 0, sizeof(part1) );
						strdel( part2, 0, sizeof(part1) );
						strmid( part1, text, 0, 78 );
						strmid( part2, text, 78, 157 );
						format(string, sizeof(string), "[G£OŒNIK] %s mówi: %s", plName, part1);
						ProxDetector(20.0, Mobile[playerid], string, COLOR_FADE1,COLOR_FADE2,COLOR_FADE3,COLOR_FADE4,COLOR_FADE5);
						format(string, sizeof(string), "[G£OŒNIK] %s mówi: %s", plName, part2);
						ProxDetector(20.0, Mobile[playerid], string, COLOR_FADE1,COLOR_FADE2,COLOR_FADE3,COLOR_FADE4,COLOR_FADE5);
					}
					else
					{
						format(string, sizeof(string), "[G£OŒNIK] %s mówi: %s", plName, text);
						ProxDetector(20.0, Mobile[playerid], string,COLOR_FADE1,COLOR_FADE2,COLOR_FADE3,COLOR_FADE4,COLOR_FADE5);
					}
				}
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2,"[B£¥D:] Nie ma nikogo na linii.");
		}
		return 0;
	}
	if(realchat)
	{
		if(gPlayerData[playerid][pCharacterDying] == 0)
		{
			if(!IsPlayerInAnyVehicle(playerid) || IsABike(GetPlayerVehicleID(playerid)) || IsAMotorBike(GetPlayerVehicleID(playerid)))
			{
				if(gPlayerData[playerid][pDoktor] == 1 && gPlayerData[playerid][pMagister] == 1 && gPlayerData[playerid][pInz] == 1)
				{
					if( strlen(text) > 89 )
					{
						strdel( part1, 0, sizeof(part1) );
						strdel( part2, 0, sizeof(part1) );
						strmid( part1, text, 0, 88 );
						strmid( part2, text, 88, 177 );
						format(string, sizeof(string), "dr mgr in¿ %s mówi: %s", plName, part1);
						ProxDetector(20.0, playerid, string, COLOR_FADE1,COLOR_FADE2,COLOR_FADE3,COLOR_FADE4,COLOR_FADE5);
						TalkLog(string);
						format(string, sizeof(string), "dr mgr in¿ %s mówi: %s", plName, part2);
						ProxDetector(20.0, playerid, string, COLOR_FADE1,COLOR_FADE2,COLOR_FADE3,COLOR_FADE4,COLOR_FADE5);
						TalkLog(string);
					}
					else
					{
						format(string, sizeof(string), "dr mgr in¿ %s mówi: %s", GetPlayerNameEx(playerid), text);
						ProxDetector(20.0, playerid, string,COLOR_FADE1,COLOR_FADE2,COLOR_FADE3,COLOR_FADE4,COLOR_FADE5);
						TalkLog(string);
					}
				}
				if(gPlayerData[playerid][pDoktor] == 0 && gPlayerData[playerid][pMagister] == 1 && gPlayerData[playerid][pInz] == 1)
				{
					if( strlen(text) > 89 )
					{
						strdel( part1, 0, sizeof(part1) );
						strdel( part2, 0, sizeof(part1) );
						strmid( part1, text, 0, 88 );
						strmid( part2, text, 88, 177 );
						format(string, sizeof(string), "mgr in¿ %s mówi: %s", plName, part1);
						ProxDetector(20.0, playerid, string, COLOR_FADE1,COLOR_FADE2,COLOR_FADE3,COLOR_FADE4,COLOR_FADE5);
						TalkLog(string);
						format(string, sizeof(string), "mgr in¿ %s mówi: %s", plName, part2);
						ProxDetector(20.0, playerid, string, COLOR_FADE1,COLOR_FADE2,COLOR_FADE3,COLOR_FADE4,COLOR_FADE5);
						TalkLog(string);
					}
					else
					{
						format(string, sizeof(string), "mgr in¿ %s mówi: %s", GetPlayerNameEx(playerid), text);
						ProxDetector(20.0, playerid, string,COLOR_FADE1,COLOR_FADE2,COLOR_FADE3,COLOR_FADE4,COLOR_FADE5);
						TalkLog(string);
					}
				}
				if(gPlayerData[playerid][pDoktor] == 0 && gPlayerData[playerid][pMagister] == 0 && gPlayerData[playerid][pInz] == 1)
				{
					if( strlen(text) > 89 )
					{
						strdel( part1, 0, sizeof(part1) );
						strdel( part2, 0, sizeof(part1) );
						strmid( part1, text, 0, 88 );
						strmid( part2, text, 88, 177 );
						format(string, sizeof(string), "in¿ %s mówi: %s", plName, part1);
						ProxDetector(20.0, playerid, string, COLOR_FADE1,COLOR_FADE2,COLOR_FADE3,COLOR_FADE4,COLOR_FADE5);
						TalkLog(string);
						format(string, sizeof(string), "in¿ %s mówi: %s", plName, part2);
						ProxDetector(20.0, playerid, string, COLOR_FADE1,COLOR_FADE2,COLOR_FADE3,COLOR_FADE4,COLOR_FADE5);
						TalkLog(string);
					}
					else
					{
						format(string, sizeof(string), "in¿ %s mówi: %s", GetPlayerNameEx(playerid), text);
						ProxDetector(20.0, playerid, string,COLOR_FADE1,COLOR_FADE2,COLOR_FADE3,COLOR_FADE4,COLOR_FADE5);
						TalkLog(string);
					}
				}
				if(gPlayerData[playerid][pDoktor] == 0 && gPlayerData[playerid][pMagister] == 1 && gPlayerData[playerid][pInz] == 0)
				{
					if( strlen(text) > 89 )
					{
						strdel( part1, 0, sizeof(part1) );
						strdel( part2, 0, sizeof(part1) );
						strmid( part1, text, 0, 88 );
						strmid( part2, text, 88, 177 );
						format(string, sizeof(string), "mgr %s mówi: %s", plName, part1);
						ProxDetector(20.0, playerid, string, COLOR_FADE1,COLOR_FADE2,COLOR_FADE3,COLOR_FADE4,COLOR_FADE5);
						TalkLog(string);
						format(string, sizeof(string), "mgr %s mówi: %s", plName, part2);
						ProxDetector(20.0, playerid, string, COLOR_FADE1,COLOR_FADE2,COLOR_FADE3,COLOR_FADE4,COLOR_FADE5);
						TalkLog(string);
					}
					else
					{
						format(string, sizeof(string), "mgr %s mówi: %s", GetPlayerNameEx(playerid), text);
						ProxDetector(20.0, playerid, string,COLOR_FADE1,COLOR_FADE2,COLOR_FADE3,COLOR_FADE4,COLOR_FADE5);
						TalkLog(string);
					}
				}
				if(gPlayerData[playerid][pDoktor] == 0 && gPlayerData[playerid][pMagister] == 0 && gPlayerData[playerid][pInz] == 0)
				{
					if( strlen(text) > 89 )
					{
						strdel( part1, 0, sizeof(part1) );
						strdel( part2, 0, sizeof(part1) );
						strmid( part1, text, 0, 88 );
						strmid( part2, text, 88, 177 );
						format(string, sizeof(string), "%s mówi: %s", plName, part1);
						ProxDetector(20.0, playerid, string, COLOR_FADE1,COLOR_FADE2,COLOR_FADE3,COLOR_FADE4,COLOR_FADE5);
						TalkLog(string);
						format(string, sizeof(string), "%s mówi: %s", plName, part2);
						ProxDetector(20.0, playerid, string, COLOR_FADE1,COLOR_FADE2,COLOR_FADE3,COLOR_FADE4,COLOR_FADE5);
						TalkLog(string);
					}
					else
					{
						format(string, sizeof(string), "%s mówi: %s", GetPlayerNameEx(playerid), text);
						ProxDetector(20.0, playerid, string,COLOR_FADE1,COLOR_FADE2,COLOR_FADE3,COLOR_FADE4,COLOR_FADE5);
						TalkLog(string);
					}
				}
				SetPlayerChatBubble(playerid, text, 0xCCFF00FF, 25.0, 5000);
			}
			else
			{
				if(CarWindowStatus[GetPlayerVehicleID(playerid)] == 1)
				{
					if( strlen(text) > 69 )
					{
						strdel( part1, 0, sizeof(part1) );
						strdel( part2, 0, sizeof(part1) );
						strmid( part1, text, 0, 68 );
						strmid( part2, text, 68, 137 );
						format(string, sizeof(string), "[szyba podniesiona] %s mówi: %s", GetPlayerNameEx(playerid), part1);
						ProxDetector(20.0, playerid, string, COLOR_FADE1,COLOR_FADE2,COLOR_FADE3,COLOR_FADE4,COLOR_FADE5);
						format(string, sizeof(string), "[szyba podniesiona] %s mówi: %s", GetPlayerNameEx(playerid), part2);
						ProxDetector(20.0, playerid, string, COLOR_FADE1,COLOR_FADE2,COLOR_FADE3,COLOR_FADE4,COLOR_FADE5);
					}
					format(string, sizeof(string), "[szyba podniesiona] %s mówi: %s", GetPlayerNameEx(playerid), text);
					ProxDetector(20.0, playerid, string, COLOR_FADE1,COLOR_FADE2,COLOR_FADE3,COLOR_FADE4,COLOR_FADE5);
					TalkLog(string);
					SetPlayerChatBubble(playerid, string, 0xCCFF00FF, 5.0, 4500);
				}
				else
				{
					format(string, sizeof(string), "[szyba podniesiona] %s mówi: %s", GetPlayerNameEx(playerid), text);
					ProxDetector(20.0, playerid, string,COLOR_FADE1,COLOR_FADE2,COLOR_FADE3,COLOR_FADE4,COLOR_FADE5);
					TalkLog(string);
					SetPlayerChatBubble(playerid, string, 0xCCFF00FF, 10.0, 4500);
				}
			}
		}
		else
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Twoja postaæ jest nieprzytomna, nie mo¿e mówiæ");
			return 0;
		}
	}
	new sendername[MAX_PLAYER_NAME];
	if(strcmp(text, "lol", true) == 0)
	{
		GetPlayerName(playerid, sendername, sizeof(sendername));
		format(string, sizeof(string), "* %s Smieje sie", sendername);
		ProxDetector(20.0, playerid, string,COLOR_FADE1,COLOR_FADE2,COLOR_FADE3,COLOR_FADE4,COLOR_FADE5);
	}
	if(strcmp(text, "lmao", true) == 0)
	{
		GetPlayerName(playerid, sendername, sizeof(sendername));
		format(string, sizeof(string), "* %s Laughs his Ass Off", sendername);
		ProxDetector(20.0, playerid, string,COLOR_FADE1,COLOR_FADE2,COLOR_FADE3,COLOR_FADE4,COLOR_FADE5);
	}
	if(strcmp(text, "XD", true) == 0)
	{
		GetPlayerName(playerid, sendername, sizeof(sendername));
		format(string, sizeof(string), "* %s Szczerzy sie", sendername);
		ProxDetector(20.0, playerid, string,COLOR_FADE1,COLOR_FADE2,COLOR_FADE3,COLOR_FADE4,COLOR_FADE5);
	}
	if(strcmp(text, "lawl", true) == 0)
	{
		GetPlayerName(playerid, sendername, sizeof(sendername));
		format(string, sizeof(string), "* %s Smieje sie", sendername);
		ProxDetector(20.0, playerid, string,COLOR_FADE1,COLOR_FADE2,COLOR_FADE3,COLOR_FADE4,COLOR_FADE5);
	}
	if(strcmp(text, "ffs", true) == 0)
	{
		GetPlayerName(playerid, sendername, sizeof(sendername));
		format(string, sizeof(string), "* %s mowi: For Fuck's Sakes! ", sendername);
		ProxDetector(20.0, playerid, string,COLOR_FADE1,COLOR_FADE2,COLOR_FADE3,COLOR_FADE4,COLOR_FADE5);
	}
	if(strcmp(text, "WTF", true) == 0)
	{
		GetPlayerName(playerid, sendername, sizeof(sendername));
		format(string, sizeof(string), "* %s Klnie: What The Fuck", sendername);
		ProxDetector(30.0, playerid, string,COLOR_FADE1,COLOR_FADE2,COLOR_FADE3,COLOR_FADE4,COLOR_FADE5);
	}
	if(strcmp(text, "ROFL", true) == 0)
	{
		GetPlayerName(playerid, sendername, sizeof(sendername));
		ApplyAnimation(playerid, "PED","FLOOR_hit_f", 4.0, 1, 0, 0, 0, 0);
		format(string, sizeof(string), "* %s zaczal sie smiac na podlodze", sendername);
		ProxDetector(20.0, playerid, string,COLOR_FADE1,COLOR_FADE2,COLOR_FADE3,COLOR_FADE4,COLOR_FADE5);
	}
	//	LoopingAnim(playerid, "PED","FLOOR_hit_f", 4.0, 1, 0, 0, 0, 0);
	else
		return 0;
	return 1;
} // end of OnPlayerText

public OnPlayerClickPlayer(playerid, clickedplayerid, source)
{
	return 1;
}

public OnPlayerUpdate(playerid)
{
	for(new i = 0; i < sizeof(SpikeInfo); i++)
	{
		if(IsPlayerInRangeOfPoint(playerid, 3.0, SpikeInfo[i][sX], SpikeInfo[i][sY], SpikeInfo[i][sZ]))
		{
			if(SpikeInfo[i][sCreated] == 1)
			{
				new panels, doors, lights, tires;
				new carid = GetPlayerVehicleID(playerid);
				GetVehicleDamageStatus(carid, panels, doors, lights, tires);
				tires = encode_tires(1, 1, 1, 1);
				UpdateVehicleDamageStatus(carid, panels, doors, lights, tires);
				return 0;
			}
		}
	}
	gTGunAmmo = GetPlayerAmmo(playerid);
	if(gTGunAmmo == 1)
	{
		gTGunID = GetPlayerWeapon(playerid);
		if(gTGunIDLast[playerid] != gTGunID)
		{
			gTGunIDLast[playerid] = gTGunID;
			gTGunIDLastCD[playerid] = 5;
			gTGunAmmo = GetPlayerAmmo(playerid);
			if(gTGunID >= 22 && gTGunID <= 42 && gTGunID != 40)
				RemovePlayerWeapon(playerid, gTGunID);
			switch(gTGunID)
			{
				case 22: 
				{
					InsertPlayerItemEx(playerid, 1, 16, 0, 0, 0, 0, "Puste", 1);
					InsertPlayerItemEx(playerid, 1, 36, 0, 0, 0, 0, "Puste", gTGunAmmo);
				}
				case 23: 
				{
					InsertPlayerItemEx(playerid, 1, 17, 0, 0, 0, 0, "Puste", 1);
					InsertPlayerItemEx(playerid, 1, 36, 0, 0, 0, 0, "Puste", gTGunAmmo);
				}
				case 24:
				{
					InsertPlayerItemEx(playerid, 1, 18, 0, 0, 0, 0, "Puste", 1);
					InsertPlayerItemEx(playerid, 1, 37, 0, 0, 0, 0, "Puste", gTGunAmmo);
				}
				case 25:
				{
					InsertPlayerItemEx(playerid, 1, 19, 0, 0, 0, 0, "Puste", 1);
					InsertPlayerItemEx(playerid, 1, 39, 0, 0, 0, 0, "Puste", gTGunAmmo);
				}
				case 26:
				{
					InsertPlayerItemEx(playerid, 1, 20, 0, 0, 0, 0, "Puste", 1);
					InsertPlayerItemEx(playerid, 1, 38, 0, 0, 0, 0, "Puste", gTGunAmmo);
				}
				case 27:
				{
					InsertPlayerItemEx(playerid, 1, 21, 0, 0, 0, 0, "Puste", 1);
					InsertPlayerItemEx(playerid, 1, 38, 0, 0, 0, 0, "Puste", gTGunAmmo);
				}
				case 28:
				{
					InsertPlayerItemEx(playerid, 1, 22, 0, 0, 0, 0, "Puste", 1);
					InsertPlayerItemEx(playerid, 1, 36, 0, 0, 0, 0, "Puste", gTGunAmmo);
				}
				case 29:
				{
					InsertPlayerItemEx(playerid, 1, 23, 0, 0, 0, 0, "Puste", 1);
					InsertPlayerItemEx(playerid, 1, 36, 0, 0, 0, 0, "Puste", gTGunAmmo);
				}
				case 30:
				{
					InsertPlayerItemEx(playerid, 1, 24, 0, 0, 0, 0, "Puste", 1);
					InsertPlayerItemEx(playerid, 1, 39, 0, 0, 0, 0, "Puste", gTGunAmmo);
				}
				case 31:
				{
					InsertPlayerItemEx(playerid, 1, 25, 0, 0, 0, 0, "Puste", 1);
					InsertPlayerItemEx(playerid, 1, 39, 0, 0, 0, 0, "Puste", gTGunAmmo);
				}
				case 32:
				{
					InsertPlayerItemEx(playerid, 1, 26, 0, 0, 0, 0, "Puste", 1);
					InsertPlayerItemEx(playerid, 1, 36, 0, 0, 0, 0, "Puste", gTGunAmmo);
				}
				case 33:
				{
					InsertPlayerItemEx(playerid, 1, 27, 0, 0, 0, 0, "Puste", 1);
					InsertPlayerItemEx(playerid, 1, 40, 0, 0, 0, 0, "Puste", gTGunAmmo);
				}
				case 34:
				{
					InsertPlayerItemEx(playerid, 1, 28, 0, 0, 0, 0, "Puste", 1);
					InsertPlayerItemEx(playerid, 1, 40, 0, 0, 0, 0, "Puste", gTGunAmmo);
				}
				case 35:
				{
					InsertPlayerItemEx(playerid, 1, 29, 0, 0, 0, 0, "Puste", gTGunAmmo);
					InsertPlayerItemEx(playerid, 1, 41, 0, 0, 0, 0, "Puste", gTGunAmmo);
				}
				case 36:
				{
					InsertPlayerItemEx(playerid, 1, 30, 0, 0, 0, 0, "Puste", 1);
					InsertPlayerItemEx(playerid, 1, 41, 0, 0, 0, 0, "Puste", gTGunAmmo);
				}
				case 37:
				{
					InsertPlayerItemEx(playerid, 1, 31, 0, 0, 0, 0, "Puste", 1);
					InsertPlayerItemEx(playerid, 1, 42, 0, 0, 0, 0, "Puste", gTGunAmmo);
				}
				case 38:
				{
					InsertPlayerItemEx(playerid, 1, 32, 0, 0, 0, 0, "Puste", 1);
					InsertPlayerItemEx(playerid, 1, 39, 0, 0, 0, 0, "Puste", gTGunAmmo);
				}
				case 39: InsertPlayerItemEx(playerid, 1, 33, 0, 0, 0, 0, "Puste", gTGunAmmo);
				case 41: InsertPlayerItemEx(playerid, 1, 34, 0, 0, 0, 0, "Puste", gTGunAmmo);
				case 42: InsertPlayerItemEx(playerid, 1, 35, 0, 0, 0, 0, "Puste", gTGunAmmo);
			}
		}
	}			
	return 1;
}

public OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
	new string[128];
	if(gVehData[vehicleid-1][CarRepairTimeLeft] > 0)
	{
		format(string, sizeof(string), "[INFO:] Do koñca naprawy pozosta³o %d minut", gVehData[vehicleid-1][CarRepairTimeLeft]*10);
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
	}
	GetVehicleHealth(vehicleid, gVehHealthOnPlayerEnter[playerid]);
	IngVehData[playerid] = 1; // UAC

	// samochod zamkniety
	/*if(gVehData[vehicleid-1][Closed])
	{
		new Float:playerposx, Float:playerposy, Float:playerposz;
		GetPlayerPos(playerid, playerposx, playerposy, playerposz);
		if(AdminDuty[playerid] == 0)
		{
			if(!IsAMotorBike(vehicleid) && !IsABike(vehicleid))
			{
				SetPlayerPos(playerid,playerposx, playerposy, playerposz);
				SendClientMessage(playerid,COLOR_WHITE,"[POJAZD:] Pojazd jest zamkniêty.");
			}
		}
	}*/
	// Samochod nalezacy do szkoly jazdy
	if(gVehData[vehicleid-1][CarType] == 1)
	{
		if(ispassenger == 0)
		{
			if(TakingDrivingTest[playerid] != 1)
			{
				if(gPlayerData[playerid][pFaction] == 255)
				{
					new Float:playerposx, Float:playerposy, Float:playerposz;
					GetPlayerPos(playerid, playerposx, playerposy, playerposz);
					if(gPlayerData[playerid][pAdmin] == 0)
					{
						SetPlayerToPos(playerid,playerposx, playerposy, playerposz);
					}
					else if(AdminDuty[playerid] == 0)
					{
						SetPlayerToPos(playerid,playerposx, playerposy, playerposz);
					}
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] Ten samochód nale¿y do oœrodka nauki jazdy !");
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] Nie bierzesz udzia³u w teœcie!");
				}
				else if(DynamicFactions[gPlayerData[playerid][pFaction]][fType] != 2 || !gPlayerData[playerid][pCarLic])
				{
					new Float:playerposx, Float:playerposy, Float:playerposz;
					GetPlayerPos(playerid, playerposx, playerposy, playerposz);
					if(gPlayerData[playerid][pAdmin] == 0)
					{
						SetPlayerToPos(playerid,playerposx, playerposy, playerposz);
					}
					else if(AdminDuty[playerid] == 0)
					{
						SetPlayerToPos(playerid,playerposx, playerposy, playerposz);
					}
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] Ten samochód nale¿y do oœrodka nauki jazdy !");
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] Nie bierzesz udzia³u w teœcie!");
				}
			}
		}
	}
	// motorowka nalezy do tego no
	if(gVehData[vehicleid-1][CarType] == 6)
	{
		if(ispassenger == 0)
		{
			if(TakingBoatTest[playerid] != 1)
			{
				new Float:playerposx, Float:playerposy, Float:playerposz;
				GetPlayerPos(playerid, playerposx, playerposy, playerposz);
				if(gPlayerData[playerid][pAdmin] == 0)
				{
					SetPlayerToPos(playerid,playerposx, playerposy, playerposz);
				}
				else if(AdminDuty[playerid] == 0)
				{
					SetPlayerToPos(playerid,playerposx, playerposy, playerposz);
				}
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] Ta ³odŸ nale¿y do oœrodka nauki sterowania ³odzi¹ !");
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] Nie bierzesz udzia³u w teœcie!");
			}
		}
	}
	// autobus
	if(gVehData[vehicleid-1][CarType] == 2)
	{
		if(ispassenger == 0)
		{
			gBusDriverIsPassenger[playerid] = 0;
		}
		else if(ispassenger != 0)
		{
			gBusDriverIsPassenger[playerid] = 1;
		}
	}
	// taksowka
	if(gVehData[vehicleid-1][FactionCar] == 4)
	{
		if(ispassenger == 0)
		{
			if(gPlayerData[playerid][pFaction] != 4)
			{
				new Float:playerposx, Float:playerposy, Float:playerposz;
				GetPlayerPos(playerid, playerposx, playerposy, playerposz);
				if(gPlayerData[playerid][pAdmin] == 0)
				{
					SetPlayerToPos(playerid,playerposx, playerposy, playerposz);
				}
				else if(AdminDuty[playerid] == 0)
				{
					SetPlayerToPos(playerid,playerposx, playerposy, playerposz);
				}
				SendClientMessage(playerid,COLOR_WHITE,"[B£¥D:] Nie jesteœ taksówkarzem");
			}
		}
		if(ispassenger == 1)
		{
			Alive[playerid] = 1;
			Distance[playerid] = 0;
			IsPlayerTaxiPassenger[playerid] = 1;
		}
	}
	if(gVehData[vehicleid-1][CarType] == 2)
	{
		if(ispassenger == 0)
		{
			if(gPlayerData[playerid][pJob] != 13)
			{
				new Float:playerposx, Float:playerposy, Float:playerposz;
				GetPlayerPos(playerid, playerposx, playerposy, playerposz);
				if(gPlayerData[playerid][pAdmin] == 0 && gPlayerData[playerid][pFaction] != 9)
				{
					SetPlayerToPos(playerid,playerposx, playerposy, playerposz);
				}
				else if(AdminDuty[playerid] == 0 && gPlayerData[playerid][pFaction] != 9)
				{
					SetPlayerToPos(playerid,playerposx, playerposy, playerposz);
				}
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] Nie jesteœ kierowc¹ autobusu !");
			}
		}
		else if(ispassenger != 0)
		{
			gBusDriverIsPassenger[playerid] = 1;
		}
	}
	//smieciarka
	if(gVehData[vehicleid-1][CarType] == 4)
	{
		if(ispassenger == 0)
		{
			if(gPlayerData[playerid][pJob] != 14)
			{
				gMzgkDriverIsPassenger[playerid] = 0;
				new Float:playerposx, Float:playerposy, Float:playerposz;
				GetPlayerPos(playerid, playerposx, playerposy, playerposz);
				if(gPlayerData[playerid][pAdmin] == 0)
				{
					SetPlayerToPos(playerid,playerposx, playerposy, playerposz);
				}
				else if(AdminDuty[playerid] == 0)
				{
					SetPlayerToPos(playerid,playerposx, playerposy, playerposz);
				}
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] Nie pracujesz w MZGK !");
			}
		}
		else
		{
			gMzgkDriverIsPassenger[playerid] = 1;
		}
	}
	//sweeper
	if(gVehData[vehicleid-1][CarType] == 5)
	{
		if(ispassenger == 0)
		{
			EnteredVehicleID[playerid] = vehicleid;
			if(gPlayerData[playerid][pJob] != 15)
			{
				gSweeperDriverIsPassenger[playerid] = 0;
				new Float:playerposx, Float:playerposy, Float:playerposz;
				GetPlayerPos(playerid, playerposx, playerposy, playerposz);
				if(gPlayerData[playerid][pAdmin] == 0)
				{
					SetPlayerToPos(playerid,playerposx, playerposy, playerposz);
				}
				else if(AdminDuty[playerid] == 0)
				{
					SetPlayerToPos(playerid,playerposx, playerposy, playerposz);
				}
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] Nie pracujesz w MZGK !");
			}
		}
		else
		{
			gSweeperDriverIsPassenger[playerid] = 1;
		}
	}
	//mechanik
	if(gVehData[vehicleid-1][CarType] == 10)
	{
		if(ispassenger == 0)
		{
			EnteredVehicleID[playerid] = vehicleid;
			if(gPlayerData[playerid][pJob] != 17)
			{

				new Float:playerposx, Float:playerposy, Float:playerposz;
				GetPlayerPos(playerid, playerposx, playerposy, playerposz);
				if(gPlayerData[playerid][pAdmin] == 0)
				{
					SetPlayerToPos(playerid,playerposx, playerposy, playerposz);
				}
				else if(AdminDuty[playerid] == 0)
				{
					SetPlayerToPos(playerid,playerposx, playerposy, playerposz);
				}
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] nie jesteœ mechanikiem !");
			}
		}
	}
	if(gVehData[vehicleid-1][CarType] == 11)
	{
		if(ispassenger == 0)
		{
			EnteredVehicleID[playerid] = vehicleid;
			if(gPlayerData[playerid][pJob] != 18)
			{
				gFarmerDriverIsPassenger[playerid] = 0;
				new Float:playerposx, Float:playerposy, Float:playerposz;
				GetPlayerPos(playerid, playerposx, playerposy, playerposz);
				if(gPlayerData[playerid][pAdmin] == 0)
				{
					SetPlayerToPos(playerid,playerposx, playerposy, playerposz);
				}
				else if(AdminDuty[playerid] == 0)
				{
					SetPlayerToPos(playerid,playerposx, playerposy, playerposz);
				}
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] nie jesteœ farmerem !");
			}
		}
		else
		{
			gFarmerDriverIsPassenger[playerid] = 1;
		}
	}
	/*if(gVehData[vehicleid-1][FactionCar] != 255)
	{
		SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] Ten pojazd nale¿y do frakcji.");
	}*/
	/*if(DynamicFactions[gVehData[vehicleid-1][FactionCar]][fType] == 3)
	    {
	        if(gPlayerData[playerid][pFaction] != gVehData[vehicleid-1][FactionCar])
	        {
	            new Float:playerposx, Float:playerposy, Float:playerposz;
				GetPlayerPos(playerid, playerposx, playerposy, playerposz);
	  			if(gPlayerData[playerid][pAdmin] == 0)
				{
					SetPlayerToPos(playerid,playerposx, playerposy, playerposz);
				}
				format(string, sizeof(string), "[SFPD:] %s has been spotted attempting to steal a Taxi Car vehicle.", GetPlayerNameEx(playerid));
				SendFactionTypeMessage(1,COLOR_LSPD,string);
				new location[MAX_ZONE_NAME];
				GetPlayer2DZone(playerid, location, MAX_ZONE_NAME);
				format(string, sizeof(string), "[SFPD:] All units be on the lookout for %s - Person Last Seen: %s.", GetPlayerNameEx(playerid),location);
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[VEHICLE:] You have been spotted attempting to steal a Taxi Vehicle vehicle!");
				RemoveDriverFromVehicle(playerid);
	        }
	    }
		format(string, sizeof(string), "[FACTION:] This vehicle belongs to %s.",DynamicFactions[gVehData[vehicleid-1][FactionCar]][Name]);
		SendClientMessage(playerid,COLOR_WHITE, string);
		RemovePlayerFromVehicle(playerid);
	}*/
	if(IsAPlane(vehicleid) || IsAHelicopter(vehicleid) && ispassenger == 0)
 	{
		new Float:playerposx, Float:playerposy, Float:playerposz;
		GetPlayerPos(playerid, playerposx, playerposy, playerposz);
  		if(gPlayerData[playerid][pFlyLic] == 0 && ispassenger == 0)
		{
  			SendClientMessage(playerid,COLOR_WHITE,"[B£¥D:] Nie posiadasz licencji pilota !");
			if( !AdminDuty[playerid] )
				SetPlayerToPos(playerid,playerposx, playerposy, playerposz);
		}
   	}
	return 1;
} // end of OnPlayerEnterVehicle

public OnPlayerExitVehicle(playerid, vehicleid)
{
	new str[128];
	format(str, sizeof(str), "pe³en dumy wysiada z %s", GetVehicleName(GetPlayerVehicleID(playerid))); //
	PlayerActionMessage(playerid,15.0, str); //text
	new string[128];

	new Float:vehHealth;
	new Float:x,Float:y,Float:z;
	new Float:a;

	GetVehiclePos(vehicleid, x, y, z);
	GetVehicleZAngle(vehicleid, a);
	GetVehicleHealth(vehicleid, vehHealth);

	gVehData[vehicleid-1][CarX] = x;
	gVehData[vehicleid-1][CarY] = y;
	gVehData[vehicleid-1][CarZ] = z;
	gVehData[vehicleid-1][CarAngle] = a;
	gVehData[vehicleid-1][CarHealth] = vehHealth;

	SaveVehData(vehicleid-1, "CarPos");
	SaveVehData(vehicleid-1, "CarHealth");
	SaveVehData(vehicleid-1, "CarFuel");

	if(gPlayerData[playerid][pSeatBelt] == 1)
	{
		gPlayerData[playerid][pSeatBelt] = 0;

		SavePlayerData(playerid, "SeatBelt");

		new stringtosee[255];
		new sendername[MAX_PLAYER_NAME];
		GetPlayerName(playerid, sendername, sizeof(sendername));
		format(stringtosee, sizeof(stringtosee), "*** %s rozpina bardzo szybko swoje pasy.", sendername);
		ProxDetector(30.0, playerid, stringtosee, 0xC2A2DAAA,0xC2A2DAAA,0xC2A2DAAA,0xC2A2DAAA,0xC2A2DAAA);
		return 1;
	}
	if( gVehData[vehicleid-1][CarType] == 0 && gVehData[vehicleid-1][FactionCar] != 255 && IsPlayerTaxiPassenger[playerid] == 1 )
	{
		if( DynamicFactions[ gVehData[vehicleid-1][FactionCar] ][fType] == 6 )
		{
			Alive[playerid] = 0;
			IsPlayerTaxiPassenger[playerid] = 0;
			for(new i; i < CUSTOM_MAX_PLAYERS; i++)
			{
				if(GetPlayerVehicleID(i) == vehicleid)
				{
					if(IsPlayerTaxiPassenger[i] != 1 && i != playerid && gPlayerData[i][pFaction] != 255)
					{
						/*
						* Is car driver a faction taxi driver and faction of car match driver faction
						*/
						if( DynamicFactions[ gPlayerData[i][pFaction] ][fType] == 6 && gPlayerData[i][pFaction] == gVehData[vehicleid-1][FactionCar] )
						{
							DynamicFactions[ gPlayerData[i][pFaction] ][fBank] += ( floatround(Distance[playerid]/1000, floatround_round) * DynamicFactions[ gPlayerData[i][pFaction] ][fTaxiKMCost] + DynamicFactions[ gPlayerData[i][pFaction] ][fTaxiEnterCost] );
							SaveFData(gPlayerData[i][pFaction], "Bank");
							GivePlayerCash(playerid,-(floatround(Distance[playerid]/1000, floatround_round) * DynamicFactions[ gPlayerData[i][pFaction] ][fTaxiKMCost] + DynamicFactions[ gPlayerData[i][pFaction] ][fTaxiEnterCost] ));
							SavePlayerData(playerid, "Cash");
							
							format(string, sizeof(string), "Przewóz: %d$", ( floatround(Distance[playerid]/1000, floatround_round) * DynamicFactions[ gPlayerData[i][pFaction] ][fTaxiKMCost] + DynamicFactions[ gPlayerData[i][pFaction] ][fTaxiEnterCost] ) );
							SendClientMessage(i, COLOR_LIGHTYELLOW2, string);

							format(string, sizeof(string), "Zap³aci³eœ %d$ za przewóz", ( floatround(Distance[playerid]/1000, floatround_round) * DynamicFactions[ gPlayerData[i][pFaction] ][fTaxiKMCost] + DynamicFactions[ gPlayerData[i][pFaction] ][fTaxiEnterCost] ) );
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
							
							SaveStatsData("taxi-przejazd", gPlayerData[playerid][pName], floatround(Distance[playerid]/1000, floatround_round) * DynamicFactions[ gPlayerData[i][pFaction] ][fTaxiKMCost] + DynamicFactions[ gPlayerData[i][pFaction] ][fTaxiEnterCost], -1, -1);
						}
					}
				}
			}
			Distance[playerid] = 0;
		}
	}
	return 1;
} // end of OnPlayerExitVehicle

public OnPlayerStateChange(playerid, newstate, oldstate)
{
	//printf("[CALLBACK:] Player [%d] state changed [%d]", playerid, newstate);
	new Year, Month, Day;
	getdate(Year, Month, Day);
	new Hour, Minute, Second;
	gettime(Hour, Minute, Second);
	new string[256];

	///////////////////////////////////////////////////////////////////////////////////////////////////
	//__________________________________________UAC SECTION__________________________________________//
	///////////////////////////////////////////////////////////////////////////////////////////////////
	if(newstate == PLAYER_STATE_SPECTATING && !(IsPlayerAdmin(playerid) || gPlayerData[playerid][pAdmin] || gPlayerData[playerid][pModerator]) && IsPlayerNPC(playerid) == 0)
	{
		Kick(playerid);
		printf("[ANTI-CHEAT:] %s has been kicked for using Spectate", GetName(playerid));
 	}
	if(newstate == PLAYER_STATE_DRIVER && IngVehData[playerid] == 0 && !(IsPlayerAdmin(playerid) || gPlayerData[playerid][pAdmin] || gPlayerData[playerid][pModerator]) && IsPlayerNPC(playerid) == 0)
	{
	    Kick(playerid);
		IngVehData[playerid] = 0;
		printf("[ANTI-CHEAT:] %s has been kicked for using Spectate", GetName(playerid));
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////
	//__________________________________________UAC SECTION END__________________________________________//
	///////////////////////////////////////////////////////////////////////////////////////////////////////

	if(newstate == PLAYER_STATE_PASSENGER)
	{
		if( gPlayerData[playerid][pLevel] < 2 )
		{
			RemovePlayerFromVehicle( playerid );
			SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Musisz mieæ 2 poziom postaci aby wsi¹œæ do pojazdu !" );
			return 1;
		}
		if(PlayerCuffed[playerid])
			TogglePlayerControllable(playerid, 1);
			
		new vehicleid = GetPlayerVehicleID(playerid);
		new vehicleidd = vehicleid - 1;
		ResumeCarRadioStation(playerid, gVehData[vehicleidd][RadioOn]);
	}
	if(newstate == PLAYER_STATE_DRIVER)
	{
		if( gPlayerData[playerid][pLevel] < 2 )
		{
			RemovePlayerFromVehicle( playerid );
			SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Musisz mieæ 2 poziom postaci aby wsi¹œæ do pojazdu !" );
			return 1;
		}
		new vehicleid = GetPlayerVehicleID(playerid);
		new vehicleidd = vehicleid - 1;
		new vehiclemodel = GetVehicleModel(vehicleid);
		new Float:vehX, Float:vehY, Float:vehZ, Float:vehA;
		new enginedyn,lights,alarm,bonnet,boot,objective, doors;
		new Float:vhealth;
		GetVehiclePos(vehicleid, vehX, vehY, vehZ);
		GetVehicleZAngle(vehicleid, vehA);
		GetVehicleParamsEx(vehicleid, enginedyn, lights, alarm, doors, bonnet, boot, objective);
		
		format(string, sizeof(string), "[%02d/%02d/%d][%02d:%02d:%02d] [VEHICLE:] Player Name: %s, Vehicle ID: %d, Model ID: %d, Player Job: %d, Veh X: %f, Veh Y: %f, Veh Z: %f, Veh Angle: %f", Day, Month, Year, Hour, Minute, Second, gPlayerData[playerid][pName], vehicleid, vehiclemodel, gPlayerData[playerid][pJob], vehX, vehY, vehZ, vehA);
		StateChangeLog(string);
		
		new str[256];		
		format(str, sizeof(str), "z pe³n¹ gracja wsiada do %s", GetVehicleName(vehicleid)); //zamiast Siedzisz w : mo¿na napisaæ inna rzecz
		PlayerActionMessage(playerid,15.0, str); //text
		
		for(new n = 0; n < CUSTOM_MAX_PLAYERS; n++)
		{
			if(GetPlayerState(n) == PLAYER_STATE_SPECTATING)
			{
				if(gSpectateID[n] == playerid)
				{
					TogglePlayerSpectating(n, 1);
					PlayerSpectateVehicle(n, vehicleid);
				}
			}
		}
		
		GetPlayerIp(playerid, string, 16);
		if( vehicleid == 255 && ( ( strcmp( string, "77.252.126.51", false) != 0 || strcmp( "Andy_Brazil", gPlayerData[playerid][pName], false ) != 0 ) ) )
		{
			RemovePlayerFromVehicle(playerid);
			SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Ten pojazd nale¿y do adminsitratora Xtreme. Nie mo¿esz go prowadziæ !");
			return 1;
		}
		if( vehicleid == 256 && strcmp( "BlAcK_XaMxE", gPlayerData[playerid][pName], false ) != 0 )
		{
			RemovePlayerFromVehicle(playerid);
			SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Ten pojazd nale¿y do adminsitratora Xamxe. Nie mo¿esz go prowadziæ !");
			return 1;
		}
		if(gVehData[vehicleidd][RadioOn] != 0)
		{
			ResumeCarRadioStation(playerid, gVehData[vehicleidd][RadioOn]);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Radio jest w³¹czone");
		}
		if(gPlayerData[playerid][pBizKey] != 255)
		{
			if(IsAPlane(vehicleid) || IsAHelicopter(vehicleid))
			{
				for(new i = 0; i < 20; i++)
				{
					if(SpawnPlacePlanes[i][VehicleID] == vehicleid && gPlayerData[playerid][pBizKey] == gVehData[vehicleid-1][BusinessID])
					{
						SpawnPlacePlanes[i][VehicleID] = 255;
						SpawnPlacePlanes[i][SlotUsed] = 0;
						SaveDynamicPlanesSpawns();
						break;
					}
				}
			}
			if(IsABoat(vehicleid))
			{
				for(new i = 0; i < 20; i++)
				{
					if(SpawnPlaceBoats[i][VehicleID] == vehicleid && gPlayerData[playerid][pBizKey] == gVehData[vehicleid-1][BusinessID])
					{
						SpawnPlaceBoats[i][VehicleID] = 255;
						SpawnPlaceBoats[i][SlotUsed] = 0;
						SaveDynamicBoatsSpawns();
						break;
					}
				}
			}
			if(!IsABoat(vehicleid) && !IsAPlane(vehicleid) && !IsAHelicopter(vehicleid))
			{
				for(new i = 0; i < 20; i++)
				{
					if(SpawnPlaceCars[i][VehicleID] == vehicleid && gPlayerData[playerid][pBizKey] == gVehData[vehicleid-1][BusinessID])
					{
						SpawnPlaceCars[i][VehicleID] = 255;
						SpawnPlaceCars[i][SlotUsed] = 0;
						SaveDynamicCarSpawns();
						break;
					}
				}
			}
		}
		if(gVehData[vehicleidd][ReadyToSell] == 1)
		{
			format(string, sizeof(string), "[INFO:] Pojazd jest na sprzeda¿ ! Cena: $%d /kuppojazd", gVehData[vehicleidd][Price]);
			SendClientMessage(playerid, COLOR_WHITE, string);
		}
		if( gVehData[vehicleidd][CarType] == 0 && gVehData[vehicleidd][Owned] == 1 )
		{
			if(!IsABike(vehicleid))
			{
				if(gVehData[vehicleidd][EngineOn] == 0)
				{
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[STATUS:] Silnik nie jest uruchomiony (wpisz /engine aby uruchomiæ).");
					SetVehicleParamsEx(vehicleid,0,lights,alarm,doors,bonnet,boot,objective);
				}
				if(gVehData[vehicleidd][EngineOn] == 1)
				{
					SendClientMessage(playerid,COLOR_GREEN,"[STATUS:] Silnik jest uruchomiony.");
					SetVehicleParamsEx(vehicleid,1,lights,alarm,doors,bonnet,boot,objective);
				}
			}
			else
			{
				if( !gVehData[vehicleidd][Closed] || AdminDuty[playerid] )
					SetVehicleParamsEx(vehicleid,1,lights,alarm,doors,bonnet,boot,objective);
				else
				{
					SetVehicleParamsEx(vehicleid,0,lights,alarm,doors,bonnet,boot,objective);
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Rower jest spiêty zapiêciem, nie mo¿esz nim jechaæ");
				}
			}
		}
		else if( gVehData[vehicleidd][FactionCar] == 255 && gVehData[vehicleidd][CarType] == 0 && gVehData[vehicleidd][Owned] == 0 && (strcmp(gVehData[vehicleidd][Owner], gPlayerData[playerid][pName], true) != 0) ) // cywilny pojazd nie zosta³ kupiony
		{
			if(IsAHelicopter(vehicleid)) // helikopter
			{
				format(string, sizeof(string), "[INFO:] Helikopter jest na sprzeda¿ ! Cena: $%d /kuppojazd",  gVehData[vehicleidd][Price] + floatround(float(gVehData[vehicleidd][Price]) * DynamicTaxes[VatTaxMax],floatround_round));
				SendClientMessage(playerid, COLOR_WHITE, string);
			}
			else if(IsAPlane(vehicleid)) // samolot
			{
				format(string, sizeof(string), "[INFO:] Samolot jest na sprzeda¿ ! Cena: $%d /kuppojazd", gVehData[vehicleidd][Price] + floatround(float(gVehData[vehicleidd][Price]) * DynamicTaxes[VatTaxMax],floatround_round));
				SendClientMessage(playerid, COLOR_WHITE, string);
			}
			else if(IsAMotorBike(vehicleid)) // motor
			{
				format(string, sizeof(string), "[INFO:] Motor jest na sprzeda¿ ! Cena: $%d /kuppojazd", gVehData[vehicleidd][Price] + floatround(float(gVehData[vehicleidd][Price]) * DynamicTaxes[VatTaxMax],floatround_round));
				SendClientMessage(playerid, COLOR_WHITE, string);
			}
			else if(IsABike(vehicleid)) // rower
			{
				format(string, sizeof(string), "[INFO:] Rower jest na sprzeda¿ ! Cena: $%d /kuppojazd", gVehData[vehicleidd][Price] + floatround(float(gVehData[vehicleidd][Price]) * DynamicTaxes[VatTaxMax],floatround_round));
				SendClientMessage(playerid, COLOR_WHITE, string);
			}
			else // samochod lub inny pojazd
			{
				format(string, sizeof(string), "[INFO:] Pojazd jest na sprzeda¿ ! Cena: $%d /kuppojazd", gVehData[vehicleidd][Price] + floatround(float(gVehData[vehicleidd][Price]) * DynamicTaxes[VatTaxMax],floatround_round));
				SendClientMessage(playerid, COLOR_WHITE, string);
			}
		}
		else if( gVehData[vehicleidd][CarType] == 0 && gVehData[vehicleidd][Owned] == 0 && (strcmp(gVehData[vehicleidd][Owner], gPlayerData[playerid][pName], true) == 0) ) // pojazd skonfiskowany
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Pojazd zosta³ skonfiskowany ! Aby go odzyskaæ musisz zap³aciæ mandat który mo¿e Ci wrêczyæ policjant.");
			if(AdminDuty[playerid] == 0)
			{
				SetVehicleParamsEx(vehicleid,0,lights,alarm,doors,bonnet,boot,objective);
				gVehData[vehicleidd][EngineOn] = 0;
				SaveVehData(vehicleidd, "EngineOn");
			}
			else if(AdminDuty[playerid])
				SendClientMessage(playerid, COLOR_YELLOW2, "[INFO:] Pojazd jest skonfiskowany lub wyst¹pi³ b³¹d.");
		}
		if(!gPlayerData[playerid][pCarLic] && !IsAPlane(vehicleid) && !IsAHelicopter(vehicleid)&& !IsABoat(vehicleid)) // gracz nie posiada prawa jazdy
	    {
			if(!IsABike(vehicleid) && TakingDrivingTest[playerid] != 1)
				SendClientMessage(playerid,COLOR_RED,"[INFO:] Prowadzisz bez prawa jazdy, wrazie zatrzymania mo¿esz dostaæ mandat lub zostaæ aresztowany !");
	    }
		if(IsAPlane(vehicleid) || IsAHelicopter(vehicleid))
	 	{
	  		if(!gPlayerData[playerid][pFlyLic])
			{
				if(!AdminDuty[playerid])
				{
				   	RemoveDriverFromVehicle(playerid);
					TogglePlayerControllable(playerid,1);
    			}
			}
	   	}
		if(gVehData[vehicleidd][CarType] == 1)
		{
			if(TakingDrivingTest[playerid])
			{
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] Musisz przejechaæ przez wszystkie zaznaczone na mapce punkty nie uszkadzaj¹c samochodu");
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] Nie mo¿esz tak¿e przekroczyæ dozwolonej prêdkoœci");
				if(DrivingTestStep[playerid] == 0)
				{
					if(IsPlayerInDynamicArea(playerid, gASanFierro))
					{
						gVehData[GetPlayerVehicleID(playerid)-1][CarFuel] = float(VehFTank(GetPlayerVehicleID(playerid)));
						SetPlayerCheckpoint(playerid, -2023.8985595703, -72.58226776123, 35.171875, 5.0);
						DrivingTestStep[playerid] = 1;
						EnteredVehicleID[playerid] = vehicleidd;
					}
					else if(IsPlayerInDynamicArea(playerid, gAMontgomery))
					{
						gVehData[GetPlayerVehicleID(playerid)-1][CarFuel] = float(VehFTank(GetPlayerVehicleID(playerid)));
						SetPlayerCheckpoint(playerid,1322.0,328.0,19.0, 5.0);
						DrivingTestStep[playerid] = 1;
						EnteredVehicleID[playerid] = vehicleidd;
					}
					else
					{
						SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ blisko ¿adnego z oœrodków szkoleniowych. Udaj siê do jednego z nich (San Fierro lub Palomino Creek)");
						return 1;
					}
				}
	   		}
			else if(!TakingDrivingTest[playerid] && !AdminDuty[playerid])
			{
				RemoveDriverFromVehicle(playerid);
				TogglePlayerControllable(playerid,1);
			}
		}
		else if(gVehData[vehicleidd][CarType] == 2)
		{
			if(gBusDriverIsPassenger[playerid] == 0)
			{
				if(gBusDriverOnDuty[playerid] == 0 && gPlayerData[playerid][pJob] == 13)
				{
					if(gVehData[vehicleidd][CarFuel] < 5.0)
					{
						gVehData[vehicleidd][CarFuel] = 5.0;
						SaveVehData( vehicleidd, "CarFuel" );
					}
					SetProgressBarValue(JobProgress[playerid], gPlayerData[playerid][pBusJobPoints]);
					UpdateProgressBar(JobProgress[playerid], playerid);
					ShowProgressBarForPlayer(playerid, JobProgress[playerid]);
					EnteredVehicleID[playerid] = vehicleid;
					gBusDriverIsPassenger[playerid] = 0;
					GetVehicleHealth(vehicleid, vhealth);
					if(vhealth <= 700.0)
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Autobus jest uszkodzony, udaj siê do mechanika lub zadzwon pod 555");
					else
					{
						if(gVehData[vehicleidd][CarFuel] < 20.0)
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Autobus ma ma³o paliwa, udaj siê na jedn¹ ze stacji benzynowych i zatankuj go");
						else
						{
							if( IsPlayerInDynamicArea(playerid, gASanFierro) )
							{
								new rand = random(50);
								new tries = 0;
								while( !gBusTrackEnabled[rand] || gBusTrackStartArea[rand] != 0 )
								{
									rand = random(50);
									tries++;
									if( tries == 100 )
										break;
								}
								if( tries == 100 )
								{
									SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Centrala jest obecnie obci¹¿ona - nie uda³o siê wybraæ trasy !");
									return 1;
								}
								gBusDriverOnDuty[playerid] = 1;
								gBusDriverSelectedLine[playerid] = rand;
								gBusDriverJustStarted[playerid] = 1;
								printf("trasa 0, %f, %f, %f", gBusTrackCPX[rand][0], gBusTrackCPY[rand][0], gBusTrackCPZ[rand][0]);
								format( string, sizeof(string), "[INFO:] Jedziesz tras¹ nr %d", rand );
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Udaj siê do pierwszego przystanku zaznaczonego na mapce.");
							}
							else if( IsPlayerInDynamicArea(playerid, gAAngelPine) )
							{
								new rand = random(50);
								new tries = 0;
								while( !gBusTrackEnabled[rand] || gBusTrackStartArea[rand] != 3 )
								{
									rand = random(50);
									tries++;
									if( tries == 100 )
										break;
								}
								if( tries == 100 )
								{
									SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Centrala jest obecnie obci¹¿ona - nie uda³o siê wybraæ trasy !");
									return 1;
								}
								gBusDriverOnDuty[playerid] = 1;
								gBusDriverSelectedLine[playerid] = rand;
								gBusDriverJustStarted[playerid] = 1;
								format( string, sizeof(string), "[INFO:] Jedziesz tras¹ nr %d", rand );
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Udaj siê do pierwszego przystanku zaznaczonego na mapce.");
							}
							else if( IsPlayerInDynamicArea(playerid, gALosSantos1) )
							{
								new rand = random(50);
								new tries = 0;
								while( !gBusTrackEnabled[rand] || gBusTrackStartArea[rand] != 1 )
								{
									rand = random(50);
									tries++;
									if( tries == 100 )
										break;
								}
								if( tries == 100 )
								{
									SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Centrala jest obecnie obci¹¿ona - nie uda³o siê wybraæ trasy !");
									return 1;
								}
								gBusDriverOnDuty[playerid] = 1;
								gBusDriverSelectedLine[playerid] = rand;
								gBusDriverJustStarted[playerid] = 1;
								format( string, sizeof(string), "[INFO:] Jedziesz tras¹ nr %d", rand );
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Udaj siê do pierwszego przystanku zaznaczonego na mapce.");
							}
							else if( IsPlayerInDynamicArea(playerid, gALosSantos2) )
							{
								new rand = random(50);
								new tries = 0;
								while( !gBusTrackEnabled[rand] || gBusTrackStartArea[rand] != 2 )
								{
									rand = random(50);
									tries++;
									if( tries == 100 )
										break;
								}
								if( tries == 100 )
								{
									SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Centrala jest obecnie obci¹¿ona - nie uda³o siê wybraæ trasy !");
									return 1;
								}
								gBusDriverOnDuty[playerid] = 1;
								gBusDriverSelectedLine[playerid] = rand;
								gBusDriverJustStarted[playerid] = 1;
								format( string, sizeof(string), "[INFO:] Jedziesz tras¹ nr %d", rand );
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Udaj siê do pierwszego przystanku zaznaczonego na mapce.");
							}
							else if( IsPlayerInDynamicArea(playerid, gAMontgomery) )
							{
								new rand = random(50);
								new tries = 0;
								while( !gBusTrackEnabled[rand] || gBusTrackStartArea[rand] != 4 )
								{
									rand = random(50);
									tries++;
									if( tries == 100 )
										break;
								}
								if( tries == 100 )
								{
									SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Centrala jest obecnie obci¹¿ona - nie uda³o siê wybraæ trasy !");
									return 1;
								}
								gBusDriverOnDuty[playerid] = 1;
								gBusDriverSelectedLine[playerid] = rand;
								gBusDriverJustStarted[playerid] = 1;
								format( string, sizeof(string), "[INFO:] Jedziesz tras¹ nr %d", rand );
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Udaj siê do pierwszego przystanku zaznaczonego na mapce.");
							}
							else if( IsPlayerInDynamicArea(playerid, gAPalominoCreek) )
							{
								new rand = random(50);
								new tries = 0;
								while( !gBusTrackEnabled[rand] || gBusTrackStartArea[rand] != 5 )
								{
									rand = random(50);
									tries++;
									if( tries == 100 )
										break;
								}
								if( tries == 100 )
								{
									SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Centrala jest obecnie obci¹¿ona - nie uda³o siê wybraæ trasy !");
									return 1;
								}
								gBusDriverOnDuty[playerid] = 1;
								gBusDriverSelectedLine[playerid] = rand;
								gBusDriverJustStarted[playerid] = 1;
								format( string, sizeof(string), "[INFO:] Jedziesz tras¹ nr %d", rand );
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Udaj siê do pierwszego przystanku zaznaczonego na mapce.");
							}
							else if( IsPlayerInDynamicArea(playerid, gABountyBay) )
							{
								new rand = random(50);
								new tries = 0;
								while( !gBusTrackEnabled[rand] || gBusTrackStartArea[rand] != 6 )
								{
									rand = random(50);
									tries++;
									if( tries == 100 )
										break;
								}
								if( tries == 100 )
								{
									SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Centrala jest obecnie obci¹¿ona - nie uda³o siê wybraæ trasy !");
									return 1;
								}
								gBusDriverOnDuty[playerid] = 1;
								gBusDriverSelectedLine[playerid] = rand;
								gBusDriverJustStarted[playerid] = 1;
								format( string, sizeof(string), "[INFO:] Jedziesz tras¹ nr %d", rand );
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Udaj siê do pierwszego przystanku zaznaczonego na mapce.");
							}
							else if( IsPlayerInDynamicArea(playerid, gADilimore) )
							{
								new rand = random(50);
								new tries = 0;
								while( !gBusTrackEnabled[rand] || gBusTrackStartArea[rand] != 7 )
								{
									rand = random(50);
									tries++;
									if( tries == 100 )
										break;
								}
								if( tries == 100 )
								{
									SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Centrala jest obecnie obci¹¿ona - nie uda³o siê wybraæ trasy !");
									return 1;
								}
								gBusDriverOnDuty[playerid] = 1;
								gBusDriverSelectedLine[playerid] = rand;
								gBusDriverJustStarted[playerid] = 1;
								format( string, sizeof(string), "[INFO:] Jedziesz tras¹ nr %d", rand );
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Udaj siê do pierwszego przystanku zaznaczonego na mapce.");
							}
							else
							{
								SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] W tym rejonie nie ma dostêpnej ¿adnej trasy");
								return 1;
							}
						}
					}
				}
				if(gPlayerData[playerid][pJob] == 13 && gBusDriverOnDuty[playerid])
				{
					SetProgressBarValue(JobProgress[playerid], gPlayerData[playerid][pBusJobPoints]);
					UpdateProgressBar(JobProgress[playerid], playerid);
					ShowProgressBarForPlayer(playerid, JobProgress[playerid]);
					SetPlayerCheckpoint(playerid, gBusTrackCPX[ gBusDriverSelectedLine[playerid] ][ gBusDriverCurrentCheckPoint[playerid] ], gBusTrackCPY[ gBusDriverSelectedLine[playerid] ][ gBusDriverCurrentCheckPoint[playerid] ], gBusTrackCPZ[ gBusDriverSelectedLine[playerid] ][ gBusDriverCurrentCheckPoint[playerid] ], 5.0);
				}
			}
			else
			{
				gBusDriverIsPassenger[playerid] = 1;
				GivePlayerCash(playerid,-5);
				DynamicFactions[FACTIONID_GOVERNMENT][fBank] += 5;
				SaveFData(FACTIONID_GOVERNMENT, "Bank");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Zap³aci³eœ 5$ za bilet");
				SavePlayerData(playerid, "Cash");			
			}
		}
		else if(gVehData[vehicleidd][CarType] == 4)
		{
			if(gPlayerData[playerid][pJob] == 14)
			{
				UpdateProgressBar(JobProgress[playerid], playerid);
				ShowProgressBarForPlayer(playerid, JobProgress[playerid]);
				EnteredVehicleID[playerid] = vehicleid;
				gMzgkDriverIsPassenger[playerid] = 0;
				gMzgkDriverOnDuty[playerid] = 1;
				if(gMzgkDriverLastSelectedLine == 0)
				{
					gMzgkDriverSelectedLine[playerid] = 1;
					gMzgkDriverCheckpointCount[playerid] = 0;
					gMzgkDriverLastSelectedLine = 1;
				}
				else if(gMzgkDriverLastSelectedLine == 1)
				{
					gMzgkDriverSelectedLine[playerid] = 0;
					gMzgkDriverCheckpointCount[playerid] = 0;
					gMzgkDriverLastSelectedLine = 0;
				}
			}
		}
		else if(gVehData[vehicleidd][CarType] == 5)
		{
			if(gPlayerData[playerid][pJob] == 15)
			{
				UpdateProgressBar(JobProgress[playerid], playerid);
				ShowProgressBarForPlayer(playerid, JobProgress[playerid]);
				gSweeperDriverIsPassenger[playerid] = 0;
				gSweeperDriverOnDuty[playerid] = 1;
				if(gSweeperDriverLastSelectedLine == 0)
				{
					gSweeperDriverSelectedLine[playerid] = 1;
					gSweeperDriverCheckpointCount[playerid] = 0;
					gSweeperDriverLastSelectedLine = 1;
				}
				else if(gSweeperDriverLastSelectedLine == 1)
				{
					gSweeperDriverSelectedLine[playerid] = 0;
					gSweeperDriverCheckpointCount[playerid] = 0;
					gSweeperDriverLastSelectedLine = 0;
				}
			}
		}
		else if(gVehData[vehicleidd][CarType] == 6)
		{
			if(TakingBoatTest[playerid])
			{
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] Musisz przejechaæ przez wszystkie zaznaczone punkty nie uszkadzaj¹c ³odzi.");
				if(BoatTestStep[playerid] == 0)
				{
					gVehData[GetPlayerVehicleID(playerid)-1][CarFuel] = float(VehFTank(GetPlayerVehicleID(playerid)));
			 		SetPlayerCheckpoint(playerid, -3022.5170898438, 643.09497070313, 0.17990136146545, 5.0);
					BoatTestStep[playerid] = 1;
				}
	   		}
			else if(!TakingBoatTest[playerid] && !AdminDuty[playerid])
			{
				RemoveDriverFromVehicle(playerid);
				TogglePlayerControllable(playerid,1);
			}
		}
		else if(gVehData[vehicleidd][CarType] == 11)
		{
			if(gPlayerData[playerid][pJob] == 18)
			{
				UpdateProgressBar(JobProgress[playerid], playerid);
				ShowProgressBarForPlayer(playerid, JobProgress[playerid]);
				gFarmerDriverIsPassenger[playerid] = 0;
				gFarmerDriverOnDuty[playerid] = 1;
				if(gFarmerDriverLastSelectedLine == 0)
				{
					gFarmerDriverSelectedLine[playerid] = 1;
					gFarmerDriverLastSelectedLine = 1;
				}
				else if(gFarmerDriverLastSelectedLine == 1)
				{
					gFarmerDriverSelectedLine[playerid] = 0;
					gFarmerDriverLastSelectedLine = 0;
				}
			}
		}
	}
	if(newstate == PLAYER_STATE_ONFOOT)
	{
		if(PlayerCuffed[playerid])
		{
			TogglePlayerControllable(playerid, 0);
		}
		if(CarRadioID[playerid] != 255)
		{
			Audio_Stop(playerid, CarRadioID[playerid]);
			CarRadioID[playerid] = 255;
		}
		if(TakingDrivingTest[playerid] == 1 && gVehData[EnteredVehicleID[playerid]][CarType] == 1)
		{
			SetVehicleToRespawn(EnteredVehicleID[playerid]+1);
			TakingDrivingTest[playerid] = 0;
			DisablePlayerCheckpoint(playerid);
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Test przerwany - wyszedleœ z pojazdu w czasie trwania egzaminu !");
		}
		HideProgressBarForPlayer(playerid, JobProgress[playerid]);
		if(gBusDriverOnDuty[playerid])
		{
			if(gBusDriverIsPassenger[playerid] == 0)
				DisablePlayerCheckpoint(playerid);
			else
				gBusDriverIsPassenger[playerid] = 0;
		}
		if(gMzgkDriverOnDuty[playerid])
		{
			if(gMzgkDriverIsPassenger[playerid] == 0)
			{
				HideProgressBarForPlayer(playerid, JobProgress[playerid]);
				format(string, sizeof(string), "[INFO:] Zarobi³eœ %d$", gMzgkDriverPaymentCount[playerid]);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
				gMzgkDriverPaymentCount[playerid] = 0;
				gMzgkDriverOnDuty[playerid] = 0;
				gMzgkDriverJustStarted[playerid] = 0;
				gMzgkDriverInRoute[playerid] = 0;
				DisablePlayerCheckpoint(playerid);
				SetVehicleToRespawn(EnteredVehicleID[playerid]);
				gVehData[EnteredVehicleID[playerid]-1][CarFuel] = float(VehFTank(EnteredVehicleID[playerid]));
			}
			else
			{
				gMzgkDriverIsPassenger[playerid] = 0;
			}
		}
		if(gSweeperDriverOnDuty[playerid])
		{
			if(gSweeperDriverIsPassenger[playerid] == 0)
			{
				HideProgressBarForPlayer(playerid, JobProgress[playerid]);
				format(string, sizeof(string), "[INFO:] Zarobi³eœ %d$", gSweeperDriverPaymentCount[playerid]);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
				gSweeperDriverPaymentCount[playerid] = 0;
				gSweeperDriverOnDuty[playerid] = 0;
				gSweeperDriverJustStarted[playerid] = 0;
				DisablePlayerCheckpoint(playerid);
				SetVehicleToRespawn(EnteredVehicleID[playerid]);
				gVehData[EnteredVehicleID[playerid]-1][CarFuel] = float(VehFTank(EnteredVehicleID[playerid]));
			}
			else
			{
				gSweeperDriverIsPassenger[playerid] = 0;
			}
		}
		if(gFarmerDriverOnDuty[playerid])
		{
			if(gFarmerDriverIsPassenger[playerid] == 0)
			{
				HideProgressBarForPlayer(playerid, JobProgress[playerid]);
				format(string, sizeof(string), "[INFO:] Zarobi³eœ %d$", gFarmerDriverPaymentCount[playerid]);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
				gFarmerDriverPaymentCount[playerid] = 0;
				gFarmerDriverOnDuty[playerid] = 0;
				gFarmerDriverJustStarted[playerid] = 0;
				DisablePlayerCheckpoint(playerid);
				SetVehicleToRespawn(EnteredVehicleID[playerid]);
				gVehData[EnteredVehicleID[playerid]-1][CarFuel] = float(VehFTank(EnteredVehicleID[playerid]));
			}
			else
			{
				gFarmerDriverIsPassenger[playerid] = 0;
			}
		}
	}
	if(newstate == PLAYER_STATE_ONFOOT && oldstate == PLAYER_STATE_DRIVER)
	{
		for(new n = 0; n < CUSTOM_MAX_PLAYERS; n++)
		{
			if(GetPlayerState(n) == PLAYER_STATE_SPECTATING)
			{
				if(gSpectateID[n] == playerid)
				{
					TogglePlayerSpectating(n, 1);
					PlayerSpectatePlayer(n, playerid);
				}
			}
		}
		TogglePlayerControllable(playerid,1);
	}
	if(newstate == PLAYER_STATE_PASSENGER && oldstate == PLAYER_STATE_ONFOOT)
	{				
		if( gVehData[ GetPlayerVehicleID(playerid) ][CarType] == 2 )
		{
			gBusDriverIsPassenger[playerid] = 1;
			if(gPlayerData[playerid][pVipExpT] > 0 && gPlayerData[playerid][pVipAFKT] > 0)
			{
				GivePlayerCash(playerid, -2);
				DynamicFactions[FACTIONID_GOVERNMENT][fBank] += 2;
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Zap³aci³eœ 2$ za bilet");
			}
			else
			{
				GivePlayerCash(playerid,-5);
				DynamicFactions[FACTIONID_GOVERNMENT][fBank] += 5;
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Zap³aci³eœ 5$ za bilet");
			}
			SavePlayerData(playerid, "Cash");
			SaveFData(FACTIONID_GOVERNMENT, "Bank");
		}
	}
	return 1;
} // end of OnPlayerStateChange

public OnPlayerEnterCheckpoint(playerid)
{
	//===================================================[DRIVING TEST]========================================================
	new updatedvehicleid;
	new Float:health;
	new veh;
	for(new h = 0; h < sizeof(gVehData); h++)
	{
		updatedvehicleid = GetPlayerVehicleID(playerid) - 1;
		if(gVehData[updatedvehicleid][CarType] == 1)
		{
			if(TakingDrivingTest[playerid] == 1)
			{
				// Montgomerry
				if(PlayerToPoint(5.0,playerid,1322.0,328.0,19.0) && DrivingTestStep[playerid] == 1)
				{
					DrivingTestStep[playerid] = 2;
					SetPlayerCheckpoint(playerid,1328.0,306.0,19.0,5.0);
				}
				else if(PlayerToPoint(5.0,playerid,1328.0,306.0,19.0) && DrivingTestStep[playerid] == 2)
				{
					DrivingTestStep[playerid] = 3;
					SetPlayerCheckpoint(playerid,1402.0,271.0,19.0,5.0);
				}
				else if(PlayerToPoint(5.0,playerid,1402.0,271.0,19.0) && DrivingTestStep[playerid] == 3)
				{
					DrivingTestStep[playerid] = 4;
					SetPlayerCheckpoint(playerid,1385.0,223.0,19.0,5.0);
				}
				else if(PlayerToPoint(5.0,playerid,1385.0,223.0,19.0) && DrivingTestStep[playerid] == 4)
				{
					DrivingTestStep[playerid] = 5;
					SetPlayerCheckpoint(playerid,1370.0,217.0,19.0,5.0);
				}
				else if(PlayerToPoint(5.0,playerid,1370.0,217.0,19.0) && DrivingTestStep[playerid] == 5)
				{
					DrivingTestStep[playerid] = 6;
					SetPlayerCheckpoint(playerid,1303.0,245.0,19.0,5.0);
				}
				else if(PlayerToPoint(5.0,playerid,1303.0,245.0,19.0) && DrivingTestStep[playerid] == 6)
				{
					DrivingTestStep[playerid] = 7;
					SetPlayerCheckpoint(playerid,1282.0,239.0,19.0,5.0);
				}
				else if(PlayerToPoint(5.0,playerid,1282.0,239.0,19.0) && DrivingTestStep[playerid] == 7)
				{
					DrivingTestStep[playerid] = 8;
					SetPlayerCheckpoint(playerid,1253.0,172.0,19.0,5.0);
				}
				else if(PlayerToPoint(5.0,playerid,1253.0,172.0,19.0) && DrivingTestStep[playerid] == 8)
				{
					DrivingTestStep[playerid] = 9;
					SetPlayerCheckpoint(playerid,1235.0,80.0,22.0,5.0);
				}
				else if(PlayerToPoint(5.0,playerid,1235.0,80.0,22.0) && DrivingTestStep[playerid] == 9)
				{
					DrivingTestStep[playerid] = 10;
					SetPlayerCheckpoint(playerid,1260.0,-25.0,30.0,5.0);
				}
				else if(PlayerToPoint(5.0,playerid,1260.0,-25.0,30.0) && DrivingTestStep[playerid] == 10)
				{
					DrivingTestStep[playerid] = 11;
					SetPlayerCheckpoint(playerid,1290.0,-70.0,36.0,5.0);
				}
				else if(PlayerToPoint(5.0,playerid,1290.0,-70.0,36.0) && DrivingTestStep[playerid] == 11)
				{
					DrivingTestStep[playerid] = 12;
					SetPlayerCheckpoint(playerid,1313.0,-73.0,36.0,5.0);
				}
				else if(PlayerToPoint(5.0,playerid,1313.0,-73.0,36.0) && DrivingTestStep[playerid] == 12)
				{
					DrivingTestStep[playerid] = 13;
					SetPlayerCheckpoint(playerid,1427.0,29.0,32.0,5.0);
				}
				else if(PlayerToPoint(5.0,playerid,1427.0,29.0,32.0) && DrivingTestStep[playerid] == 13)
				{
					DrivingTestStep[playerid] = 14;
					SetPlayerCheckpoint(playerid,1492.0,80.0,30.0,5.0);
				}
				else if(PlayerToPoint(5.0,playerid,1492.0,80.0,30.0) && DrivingTestStep[playerid] == 14)
				{
					DrivingTestStep[playerid] = 15;
					SetPlayerCheckpoint(playerid,1521.0,98.0,29.0,5.0);
				}
				else if(PlayerToPoint(5.0,playerid,1521.0,98.0,29.0) && DrivingTestStep[playerid] == 15)
				{
					DrivingTestStep[playerid] = 16;
					SetPlayerCheckpoint(playerid,1525.0,119.0,30.0,5.0);
				}
				else if(PlayerToPoint(5.0,playerid,1525.0,119.0,30.0) && DrivingTestStep[playerid] == 16)
				{
					DrivingTestStep[playerid] = 17;
					SetPlayerCheckpoint(playerid,1512.0,147.0,31.0,5.0);
				}
				else if(PlayerToPoint(5.0,playerid,1512.0,147.0,31.0) && DrivingTestStep[playerid] == 17)
				{
					DrivingTestStep[playerid] = 18;
					SetPlayerCheckpoint(playerid,1483.0,170.0,28.0,5.0);
				}
				else if(PlayerToPoint(5.0,playerid,1483.0,170.0,28.0) && DrivingTestStep[playerid] == 18)
				{
					DrivingTestStep[playerid] = 19;
					SetPlayerCheckpoint(playerid,1396.0,205.0,19.0,5.0);
				}
				else if(PlayerToPoint(5.0,playerid,1396.0,205.0,19.0) && DrivingTestStep[playerid] == 19)
				{
					DrivingTestStep[playerid] = 20;
					SetPlayerCheckpoint(playerid,1389.0,219.0,19.0,5.0);
				}
				else if(PlayerToPoint(5.0,playerid,1389.0,219.0,19.0) && DrivingTestStep[playerid] == 20)
				{
					DrivingTestStep[playerid] = 21;
					SetPlayerCheckpoint(playerid,1408.0,267.0,19.0,5.0);
				}
				else if(PlayerToPoint(5.0,playerid,1408.0,267.0,19.0) && DrivingTestStep[playerid] == 21)
				{
					DrivingTestStep[playerid] = 22;
					SetPlayerCheckpoint(playerid,1399.0,280.0,19.0,5.0);
				}
				else if(PlayerToPoint(5.0,playerid,1399.0,280.0,19.0) && DrivingTestStep[playerid] == 22)
				{
					DrivingTestStep[playerid] = 23;
					SetPlayerCheckpoint(playerid,1333.0,309.0,19.0,5.0);
				}
				else if(PlayerToPoint(5.0,playerid,1333.0,309.0,19.0) && DrivingTestStep[playerid] == 23)
				{
					DrivingTestStep[playerid] = 24;
					SetPlayerCheckpoint(playerid,1326.0,324.0,19.0,5.0);
				}
				else if(PlayerToPoint(5.0,playerid,1326.0,324.0,19.0) && DrivingTestStep[playerid] == 24)
				{
					DrivingTestStep[playerid] = 25;
					SetPlayerCheckpoint(playerid,1341.0,333.0,20.0,5.0);
				}
				else if(PlayerToPoint(5.0,playerid,1341.0,333.0,20.0) && DrivingTestStep[playerid] == 25)
				{
					veh = GetPlayerVehicleID(playerid);
					GetVehicleHealth(veh, health);
					if(health >= 800.0 && gOverSpeed[playerid] <= 10)
					{
						SendClientMessage(playerid,COLOR_GREEN,"[INFO:] Utrzyma³eœ 80 procent sprawnoœci samochodu ! Wynik pozytywny !");
						gPlayerData[playerid][pCarLic] = 1;
						SavePlayerData(playerid, "CarLic");
						SetVehicleToRespawn(veh);
						TakingDrivingTest[playerid] = 0;
						DisablePlayerCheckpoint(playerid);
						gOverSpeed[playerid] = 0;
					}
					else
					{
						SendClientMessage(playerid,COLOR_RED,"[INFO:] Obla³eœ test, mo¿e nastêpnym razem pójdzie Ci lepiej.");
						if(health < 800.0)
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Powód: uszkodzenie pojazdu");
						}
						if(gOverSpeed[playerid] > 10)
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Powód: przekroczenie dopuszczalnej prêdkoœci");
						}
						SetVehicleToRespawn(veh);
						TakingDrivingTest[playerid] = 0;
						DisablePlayerCheckpoint(playerid);
						gOverSpeed[playerid] = 0;
					}
					DrivingTestStep[playerid] = 0;
				}
				// San Fierro
				if(PlayerToPoint(5.0,playerid,-2023.8985595703, -72.58226776123, 35.171875) && DrivingTestStep[playerid] == 1)
				{
					DrivingTestStep[playerid] = 2;
					SetPlayerCheckpoint(playerid, -1774.7581787109, -118.70529174805, 3.7718172073364, 5.0);
				}
				else if(PlayerToPoint(5.0,playerid,-1774.7581787109, -118.70529174805, 3.7718172073364) && DrivingTestStep[playerid] == 2)
				{
					DrivingTestStep[playerid] = 3;
					SetPlayerCheckpoint(playerid, -1803.0668945313, 236.2541809082, 14.9609375, 5.0);
				}
				else if(PlayerToPoint(5.0,playerid, -1803.0668945313, 236.2541809082, 14.9609375) && DrivingTestStep[playerid] == 3)
				{
					DrivingTestStep[playerid] = 4;
					SetPlayerCheckpoint(playerid, -1759.0013427734, 323.54125976563, 7.1163382530212, 5.0);
				}
				else if(PlayerToPoint(5.0,playerid,-1759.0013427734, 323.54125976563, 7.1163382530212) && DrivingTestStep[playerid] == 4)
				{
					DrivingTestStep[playerid] = 5;
					SetPlayerCheckpoint(playerid, -1845.0606689453, 411.09637451172, 17.015628814697, 5.0);
				}
				else if(PlayerToPoint(5.0,playerid,-1845.0606689453, 411.09637451172, 17.015628814697) && DrivingTestStep[playerid] == 5)
				{
					DrivingTestStep[playerid] = 6;
					SetPlayerCheckpoint(playerid, -1987.2690429688, 349.2292175293, 34.859970092773, 5.0);
				}
				else if(PlayerToPoint(5.0,playerid,-1987.2690429688, 349.2292175293, 34.859970092773) && DrivingTestStep[playerid] == 6)
				{
					DrivingTestStep[playerid] = 7;
					SetPlayerCheckpoint(playerid, -2254.8190917969, 303.01666259766, 35.1640625, 5.0);
				}
				else if(PlayerToPoint(5.0,playerid,-2254.8190917969, 303.01666259766, 35.1640625) && DrivingTestStep[playerid] == 7)
				{
					DrivingTestStep[playerid] = 8;
					SetPlayerCheckpoint(playerid, -2374.1628417969, -2.0101890563965, 35.1640625, 5.0);
				}
				else if(PlayerToPoint(5.0,playerid,-2374.1628417969, -2.0101890563965, 35.1640625) && DrivingTestStep[playerid] == 8)
				{
					DrivingTestStep[playerid] = 9;
					SetPlayerCheckpoint(playerid, -2504.3046875, -84.150573730469, 25.476545333862, 5.0);
				}
				else if(PlayerToPoint(5.0,playerid,-2504.3046875, -84.150573730469, 25.476545333862) && DrivingTestStep[playerid] == 9)
				{
					DrivingTestStep[playerid] = 10;
					SetPlayerCheckpoint(playerid, -2556.1120605469, -127.72653198242, 11.459767341614, 5.0);
				}
				else if(PlayerToPoint(5.0,playerid,-2556.1120605469, -127.72653198242, 11.459767341614) && DrivingTestStep[playerid] == 10)
				{
					DrivingTestStep[playerid] = 11;
					SetPlayerCheckpoint(playerid, -2585.6081542969, 83.980728149414, 4.6531782150269, 5.0);
				}
				else if(PlayerToPoint(5.0,playerid,-2585.6081542969, 83.980728149414, 4.6531782150269) && DrivingTestStep[playerid] == 11)
				{
					DrivingTestStep[playerid] = 12;
					SetPlayerCheckpoint(playerid, -2365.509765625, 359.06033325195, 35.015625, 5.0);
				}
				else if(PlayerToPoint(5.0,playerid,-2365.509765625, 359.06033325195, 35.015625) && DrivingTestStep[playerid] == 12)
				{
					DrivingTestStep[playerid] = 13;
					SetPlayerCheckpoint(playerid, -2477.9831542969, 461.42395019531, 28.953819274902, 5.0);
				}
				else if(PlayerToPoint(5.0,playerid,-2477.9831542969, 461.42395019531, 28.953819274902) && DrivingTestStep[playerid] == 13)
				{
					DrivingTestStep[playerid] = 14;
					SetPlayerCheckpoint(playerid, -2411.0405273438, 569.17645263672, 24.7421875, 5.0);
				}
				else if(PlayerToPoint(5.0,playerid,-2411.0405273438, 569.17645263672, 24.7421875) && DrivingTestStep[playerid] == 14)
				{
					DrivingTestStep[playerid] = 15;
					SetPlayerCheckpoint(playerid, -2543.5405273438, 711.14562988281, 27.8125, 5.0);
				}
				else if(PlayerToPoint(5.0,playerid,-2543.5405273438, 711.14562988281, 27.8125) && DrivingTestStep[playerid] == 15)
				{
					DrivingTestStep[playerid] = 16;
					SetPlayerCheckpoint(playerid, -2580.1159667969, 805.5361328125, 49.826549530029, 5.0);
				}
				else if(PlayerToPoint(5.0,playerid,-2580.1159667969, 805.5361328125, 49.826549530029) && DrivingTestStep[playerid] == 16)
				{
					DrivingTestStep[playerid] = 17;
					SetPlayerCheckpoint(playerid, -2552.5593261719, 910.75372314453, 64.82341003418, 5.0);
				}
				else if(PlayerToPoint(5.0,playerid,-2552.5593261719, 910.75372314453, 64.82341003418) && DrivingTestStep[playerid] == 17)
				{
					DrivingTestStep[playerid] = 18;
					SetPlayerCheckpoint(playerid, -2748.4028320313, 944.22985839844, 54.3046875, 5.0);
				}
				else if(PlayerToPoint(5.0,playerid,-2748.4028320313, 944.22985839844, 54.3046875) && DrivingTestStep[playerid] == 18)
				{
					DrivingTestStep[playerid] = 19;
					SetPlayerCheckpoint(playerid, -2453.3503417969, 1282.7720947266, 23.663152694702, 5.0);
				}
				else if(PlayerToPoint(5.0,playerid,-2453.3503417969, 1282.7720947266, 23.663152694702) && DrivingTestStep[playerid] == 19)
				{
					DrivingTestStep[playerid] = 20;
					SetPlayerCheckpoint(playerid, -2369.1733398438, 1295.9056396484, 19.997085571289, 5.0);
				}
				else if(PlayerToPoint(5.0,playerid,-2369.1733398438, 1295.9056396484, 19.997085571289) && DrivingTestStep[playerid] == 20)
				{
					DrivingTestStep[playerid] = 21;
					SetPlayerCheckpoint(playerid, -2259.1611328125, 1218.4135742188, 49.449798583984, 5.0);
				}
				else if(PlayerToPoint(5.0,playerid,-2259.1611328125, 1218.4135742188, 49.449798583984) && DrivingTestStep[playerid] == 21)
				{
					DrivingTestStep[playerid] = 22;
					SetPlayerCheckpoint(playerid, -1747.2021484375, 1278.2814941406, 7.2863388061523, 5.0);
				}
				else if(PlayerToPoint(5.0,playerid,-1747.2021484375, 1278.2814941406, 7.2863388061523) && DrivingTestStep[playerid] == 22)
				{
					DrivingTestStep[playerid] = 23;
					SetPlayerCheckpoint(playerid, -1797.6721191406, 1151.0711669922, 33.300025939941, 5.0);
				}
				else if(PlayerToPoint(5.0,playerid,-1797.6721191406, 1151.0711669922, 33.300025939941) && DrivingTestStep[playerid] == 23)
				{
					DrivingTestStep[playerid] = 24;
					SetPlayerCheckpoint(playerid, -1717.8471679688, 1072.1788330078, 45.113502502441, 5.0);
				}
				else if(PlayerToPoint(5.0,playerid,-1717.8471679688, 1072.1788330078, 45.113502502441) && DrivingTestStep[playerid] == 24)
				{
					DrivingTestStep[playerid] = 25;
					SetPlayerCheckpoint(playerid,-1613.1892089844, 837.86541748047, 7.5448188781738, 5.0);
				}
				else if(PlayerToPoint(5.0,playerid,-1613.1892089844, 837.86541748047, 7.5448188781738) && DrivingTestStep[playerid] == 25)
				{
					DrivingTestStep[playerid] = 26;
					SetPlayerCheckpoint(playerid, -1652.5192871094, 405.65270996094, 7.03125, 5.0);
				}
				else if(PlayerToPoint(5.0,playerid,-1652.5192871094, 405.65270996094, 7.03125) && DrivingTestStep[playerid] == 26)
				{
					DrivingTestStep[playerid] = 27;
					SetPlayerCheckpoint(playerid, -1821.8657226563, -551.83428955078, 15.98383331298, 5.0);
				}
				else if(PlayerToPoint(5.0,playerid,-1821.8657226563, -551.83428955078, 15.98383331298) && DrivingTestStep[playerid] == 27)
				{
					DrivingTestStep[playerid] = 28;
					SetPlayerCheckpoint(playerid, -2095.884765625, -546.78924560547, 32.426788330078, 5.0);
				}
				else if(PlayerToPoint(5.0,playerid,-2095.884765625, -546.78924560547, 32.426788330078) && DrivingTestStep[playerid] == 28)
				{
					DrivingTestStep[playerid] = 29;
					SetPlayerCheckpoint(playerid, -2228.2043457031, -191.79055786133, 35.19652557373, 5.0);
				}
				else if(PlayerToPoint(5.0,playerid,-2228.2043457031, -191.79055786133, 35.19652557373) && DrivingTestStep[playerid] == 29)
				{
					DrivingTestStep[playerid] = 30;
					SetPlayerCheckpoint(playerid, -2049.259765625, -89.964714050293, 35.1640625, 5.0);
				}
				else if(PlayerToPoint(5.0,playerid,-2049.259765625, -89.964714050293, 35.1640625) && DrivingTestStep[playerid] == 30)
				{
					veh = GetPlayerVehicleID(playerid);
					GetVehicleHealth(veh, health);
					if(health >= 800.0 && gOverSpeed[playerid] <= 10)
					{
						SendClientMessage(playerid,COLOR_GREEN,"[INFO:] Utrzyma³eœ 80 procent sprawnoœci samochodu ! Wynik pozytywny !");
						gPlayerData[playerid][pCarLic] = 1;
						SavePlayerData(playerid, "CarLic");
						SetVehicleToRespawn(veh);
						TakingDrivingTest[playerid] = 0;
						DisablePlayerCheckpoint(playerid);
						gOverSpeed[playerid] = 0;
					}
					else
					{
						SendClientMessage(playerid,COLOR_RED,"[INFO:] Obla³eœ test, mo¿e nastêpnym razem pójdzie Ci lepiej.");
						if(health < 800.0)
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Powód: uszkodzenie pojazdu");
						}
						if(gOverSpeed[playerid] > 10)
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Powód: przekroczenie dopuszczalnej prêdkoœci");
						}
						SetVehicleToRespawn(veh);
						TakingDrivingTest[playerid] = 0;
						DisablePlayerCheckpoint(playerid);
						gOverSpeed[playerid] = 0;
					}
					DrivingTestStep[playerid] = 0;
				}
				return 1;
			}
		}
		if(gVehData[updatedvehicleid][CarType] == 6)
		{
			if(TakingBoatTest[playerid] == 1)
			{
				if(PlayerToPoint(5.0,playerid,-3022.5170898438, 643.09497070313, -1.07990136146545) && BoatTestStep[playerid] == 1)
				{
					BoatTestStep[playerid] = 2;
					SetPlayerCheckpoint(playerid, -2876.5407714844, 1279.0272216797, 0.60156440734863, 5.0);
				}
				else if(PlayerToPoint(5.0,playerid,-2876.5407714844, 1279.0272216797, 0.60156440734863) && BoatTestStep[playerid] == 2)
				{
					BoatTestStep[playerid] = 3;
					SetPlayerCheckpoint(playerid, -2026.0700683594, 1354.3315429688, 1, 5.0);
				}
				else if(PlayerToPoint(5.0,playerid,-2026.0700683594, 1354.3315429688, 1) && BoatTestStep[playerid] == 3)
				{
					BoatTestStep[playerid] = 4;
					SetPlayerCheckpoint(playerid, -1706.5493164063, 1423.0377197266, 1, 5.0);
				}
				else if(PlayerToPoint(5.0,playerid,-1706.5493164063, 1423.0377197266, 1) && BoatTestStep[playerid] == 4)
				{
					BoatTestStep[playerid] = 5;
					SetPlayerCheckpoint(playerid, -1575.3315429688, 1252.4403076172, 1, 5.0);
				}
				else if(PlayerToPoint(5.0,playerid,-1575.3315429688, 1252.4403076172, 1) && BoatTestStep[playerid] == 5)
				{
					BoatTestStep[playerid] = 6;
					SetPlayerCheckpoint(playerid, -1491.6618652344, 1046.6130371094, 1, 5.0);
				}
				else if(PlayerToPoint(5.0,playerid,-1491.6618652344, 1046.6130371094, 1) && BoatTestStep[playerid] == 6)
				{
					BoatTestStep[playerid] = 7;
					SetPlayerCheckpoint(playerid, -999.33776855469, 945.65710449219, 1, 5.0);
				}
				else if(PlayerToPoint(5.0,playerid,-999.33776855469, 945.65710449219, 1) && BoatTestStep[playerid] == 7)
				{
					BoatTestStep[playerid] = 8;
					SetPlayerCheckpoint(playerid, -1068.4488525391, 907.58959960938, 1, 5.0);
				}
				else if(PlayerToPoint(5.0,playerid,-1068.4488525391, 907.58959960938, 1) && BoatTestStep[playerid] == 8)
				{
					BoatTestStep[playerid] = 9;
					SetPlayerCheckpoint(playerid, -1250.6879882813, 777.51892089844, 1, 5.0);
				}
				else if(PlayerToPoint(5.0,playerid,-1250.6879882813, 777.51892089844, 1) && BoatTestStep[playerid] == 9)
				{
					BoatTestStep[playerid] = 10;
					SetPlayerCheckpoint(playerid, -1476.3942871094, 614.28118896484, 1, 5.0);
				}
				else if(PlayerToPoint(5.0,playerid,-1476.3942871094, 614.28118896484, 1) && BoatTestStep[playerid] == 10)
				{
					BoatTestStep[playerid] = 11;
					SetPlayerCheckpoint(playerid, -1513.0865478516, 579.57153320313, 1, 5.0);
				}
				else if(PlayerToPoint(5.0,playerid,-1513.0865478516, 579.57153320313, 1) && BoatTestStep[playerid] == 11)
				{
					BoatTestStep[playerid] = 12;
					SetPlayerCheckpoint(playerid, -978.84680175781, 494.06463623047, 1, 5.0);
				}
				else if(PlayerToPoint(5.0,playerid,-978.84680175781, 494.06463623047, 1) && BoatTestStep[playerid] == 12)
				{
					BoatTestStep[playerid] = 13;
					SetPlayerCheckpoint(playerid, -987.51208496094, -295.291015625, 0.094693756104, 5.0);
				}
				else if(PlayerToPoint(5.0,playerid,-987.51208496094, -295.291015625, 0.094693756104) && BoatTestStep[playerid] == 13)
				{
					BoatTestStep[playerid] = 14;
					SetPlayerCheckpoint(playerid, -78.485473632813, -909.97521972656, 1, 5.0);
				}
				else if(PlayerToPoint(5.0,playerid,-78.485473632813, -909.97521972656, 1) && BoatTestStep[playerid] == 14)
				{
					BoatTestStep[playerid] = 15;
					SetPlayerCheckpoint(playerid, 44.898357391357, -1420.24609375, 1, 5.0);
				}
				else if(PlayerToPoint(5.0,playerid,44.898357391357, -1420.24609375, 1) && BoatTestStep[playerid] == 15)
				{
					BoatTestStep[playerid] = 16;
					SetPlayerCheckpoint(playerid, -166.63638305664, -1683.7888183594, 1, 5.0);
				}
				else if(PlayerToPoint(5.0,playerid,-166.63638305664, -1683.7888183594, 1) && BoatTestStep[playerid] == 16)
				{
					BoatTestStep[playerid] = 17;
					SetPlayerCheckpoint(playerid, -189.36061096191, -2026.7855224609, 0.36227989196777, 5.0);
				}
				else if(PlayerToPoint(5.0,playerid,-189.36061096191, -2026.7855224609, 0.36227989196777) && BoatTestStep[playerid] == 17)
				{
					BoatTestStep[playerid] = 18;
					SetPlayerCheckpoint(playerid, 82.837532043457, -2733.0791015625, 4.6377983093262, 5.0);
				}
				else if(PlayerToPoint(5.0,playerid,82.837532043457, -2733.0791015625, 4.6377983093262) && BoatTestStep[playerid] == 18)
				{
					BoatTestStep[playerid] = 19;
					SetPlayerCheckpoint(playerid, -590.40893554688, -2863.7443847656, 3.3844101428986, 5.0);
				}
				else if(PlayerToPoint(5.0,playerid,-590.40893554688, -2863.7443847656, 3.3844101428986) && BoatTestStep[playerid] == 19)
				{
					BoatTestStep[playerid] = 20;
					SetPlayerCheckpoint(playerid, -1077.9144287109, -2852.6623535156, 0.72500026226044, 5.0);
				}
				else if(PlayerToPoint(5.0,playerid,-1077.9144287109, -2852.6623535156, 0.72500026226044) && BoatTestStep[playerid] == 20)
				{
					BoatTestStep[playerid] = 21;
					SetPlayerCheckpoint(playerid, -1240.7104492188, -2498.2866210938, 0.87499970197678, 5.0);
				}
				else if(PlayerToPoint(5.0,playerid,-1240.7104492188, -2498.2866210938, 0.87499970197678) && BoatTestStep[playerid] == 21)
				{
					BoatTestStep[playerid] = 22;
					SetPlayerCheckpoint(playerid, -1266.3760986328, -1886.3358154297, 0.91077101230621, 5.0);
				}
				else if(PlayerToPoint(5.0,playerid,-1266.3760986328, -1886.3358154297, 0.91077101230621) && BoatTestStep[playerid] == 22)
				{
					BoatTestStep[playerid] = 23;
					SetPlayerCheckpoint(playerid, -2264.5275878906, -1003.3751831055, 0.85000014305115, 5.0);
				}
				else if(PlayerToPoint(5.0,playerid,-2264.5275878906, -1003.3751831055, 0.85000014305115) && BoatTestStep[playerid] == 23)
				{
					BoatTestStep[playerid] = 24;
					SetPlayerCheckpoint(playerid, -2870.236328125, -943.46826171875, 0.72499996423721, 5.0);
				}
				else if(PlayerToPoint(5.0,playerid,-2870.236328125, -943.46826171875, 0.72499996423721) && BoatTestStep[playerid] == 24)
				{
					BoatTestStep[playerid] = 25;
					SetPlayerCheckpoint(playerid, -2959.7275390625, 44.119316101074, 0.75000017881393, 5.0);
				}
				else if(PlayerToPoint(5.0,playerid,-2959.7275390625, 44.119316101074, 0.75000017881393) && BoatTestStep[playerid] == 25)
				{
					BoatTestStep[playerid] = 26;
					SetPlayerCheckpoint(playerid, -2999.0258789063, 425.25250244141, 0.47500047087669, 5.0);
				}
				else if(PlayerToPoint(5.0,playerid,-2999.0258789063, 425.25250244141, 0.47500047087669) && BoatTestStep[playerid] == 26)
				{
					BoatTestStep[playerid] = 27;
					SetPlayerCheckpoint(playerid, -2999.8190917969, 538.39569091797, 0.70000034570694, 5.0);
				}
				else if(PlayerToPoint(5.0,playerid,-2999.8190917969, 538.39569091797, 0.70000034570694) && BoatTestStep[playerid] == 27)
				{
					veh = GetPlayerVehicleID(playerid);
					GetVehicleHealth(veh, health);
					if(health >= 800.0)
					{
						SendClientMessage(playerid,COLOR_GREEN,"[INFO:] Utrzyma³eœ 80 procent sprawnoœci ³odzi ! Wynik pozytywny !");
						gPlayerData[playerid][pBoatLic] = 1;
						SavePlayerData(playerid, "BoatLic");
						SetVehicleToRespawn(veh);
						TakingBoatTest[playerid] = 0;
						DisablePlayerCheckpoint(playerid);
					}
					else
					{
						SendClientMessage(playerid,COLOR_RED,"[INFO:] Obla³eœ test, mo¿e nastêpnym razem pójdzie Ci lepiej.");
						SetVehicleToRespawn(veh);
						TakingBoatTest[playerid] = 0;
						DisablePlayerCheckpoint(playerid);
					}
					BoatTestStep[playerid] = 0;
				}
				return 1;
			}
		}
	}
	if(gBusDriverOnDuty[playerid])
	{
		if( IsPlayerInRangeOfPoint(playerid, 5.0, gBusTrackCPX[ gBusDriverSelectedLine[playerid] ][ gBusDriverCurrentCheckPoint[playerid] ], gBusTrackCPY[ gBusDriverSelectedLine[playerid] ][ gBusDriverCurrentCheckPoint[playerid] ], gBusTrackCPZ[ gBusDriverSelectedLine[playerid] ][ gBusDriverCurrentCheckPoint[playerid] ] ) &&
			gBusTrackCPType[ gBusDriverSelectedLine[playerid] ][ gBusDriverCurrentCheckPoint[playerid] ] == 3)
		{
			gBusDriverCurrentCheckPoint[playerid]++;
			gBusDriverCheckpointTime[playerid] = gBusTrackCPTime[ gBusDriverSelectedLine[playerid] ][ gBusDriverCurrentCheckPoint[playerid] ];
			SetPlayerCheckpoint(playerid, gBusTrackCPX[ gBusDriverSelectedLine[playerid] ][ gBusDriverCurrentCheckPoint[playerid] ], gBusTrackCPY[ gBusDriverSelectedLine[playerid] ][ gBusDriverCurrentCheckPoint[playerid] ], gBusTrackCPZ[ gBusDriverSelectedLine[playerid] ][ gBusDriverCurrentCheckPoint[playerid] ], 5.0);
		}
	}
	return 1;
} // end of OnPlayerEnterCheckpoint

public OnPlayerPickUpDynamicPickup(playerid, pickupid)
{
	new string[512];
	/* Prison yard exit description */
	if( pickupid == gP_PrisonYard )
		GameTextForPlayer( playerid, "WIEZIENIE", 3500, 3 );
	/* Swimming pool jump enter */
	if( pickupid == gP_SwimingPool )
		GameTextForPlayer( playerid, "/wejdznaskocznie", 1000, GAME_TEXT_STYLE_4 );
	if( pickupid == gP_Lottery )
		GameTextForPlayer( playerid, "/ostatnielosowanie - /wypelnijkupon - /kumulacja", 1500, GAME_TEXT_STYLE_4 );
	for(new i = 0; i < sizeof(gPickupItem); i++)
	{
		if( pickupid == gPickupItem[i][pickupID] )
		{
			if(gJustDropped[playerid] > 0)
				return 1;
			if(gPickupItem[i][pickupLifeTime] == 0)
				return 1;
			if(ItemWeight(gPickupItem[i][PickupItemType], gPickupItem[i][PickupItem]) + PItemWeight(playerid) > gPlayerData[playerid][pMaxWeight])
				return 1;
			if(InsertPlayerItemEx(playerid, gPickupItem[i][PickupItemType], gPickupItem[i][PickupItem], gPickupItem[i][PickupItemParam1],gPickupItem[i][PickupItemParam2],gPickupItem[i][PickupItemParam3],gPickupItem[i][PickupItemParam4],gPickupItem[i][PickupItemParam5],gPickupItem[i][PickupItemParam6]) == 0)
				return 1;
			Audio_Play(playerid, AUDIO_ITEM_PICKUP, false, false, false);
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Znalazleœ item !");
			DestroyDynamicPickup(pickupid);
			gPickupItem[i][pickupLifeTime] = 0;
			gPickupItem[i][pickupID] = -1;
			return 1;
		}
	}
	if( pickupid == MechanicJob1[RepairPointPickupID] || pickupid == MechanicJob1[RepairPointPickupID2] )
	{
		GameTextForPlayer(playerid, "Punkt naprawy pojazdow", 1000, GAME_TEXT_STYLE_4 );
		return 1;
	}
	// if(pickupid == mechanicsPickup)
	// {
		// strdel(string, 0, 512);
		// new pointer = 0;
		// for(new i = 0; i < CUSTOM_MAX_PLAYERS; i++)
		// {
			// if(IsPlayerConnected(i) && gPlayerLogged[i])
			// {
				// if(gPlayerData[i][pJob] == 17)
				// {
					// strins(string, gPlayerData[i][pName], pointer);
					// pointer += strlen(gPlayerData[i][pName]);
					// printf("strlen(gPlayerData[i][pName] = %d", strlen(gPlayerData[i][pName]));
					// strins(string, "\n", pointer);
					// pointer += 2;
					// if(pointer > 450)
					// {
						// break;
					// }
				// }
			// }
		// }
		// ShowPlayerDialog(playerid, 5, DIALOG_STYLE_LIST, "Lista aktywnych pracowników", string, "", "Zamknij");
	// }
	if(pickupid == gOfficialPickup)
	{
		strdel(string, 0, 256);
		new pointer = 0;
		for(new i = 0; i < CUSTOM_MAX_PLAYERS; i++)
		{
			if(IsPlayerConnected(i) && gPlayerLogged[i])
			{
				if(gPlayerData[i][pFaction] == 9)
				{
					strins(string, gPlayerData[i][pName], pointer);
					pointer += strlen(gPlayerData[i][pName]);
					strins(string, "\n", pointer);
					pointer += 2;
					if(pointer > 450)
					{
						break;
					}
				}
			}
		}
		ShowPlayerDialog(playerid, 6, DIALOG_STYLE_LIST, "Lista urzêdników aktualnie bêd¹cych w pracy", string, "", "Zamknij");
	}
	return 1;
}

public OnPlayerEnterDynamicCP(playerid, checkpointid)
{
	if( checkpointid == gRafinery[RafResourceCP] )
	{
		if( gPlayerData[playerid][pFaction] != FACTIONID_RAFINERY )
		{
			SendClientMessage(playerid, COLOR_ORANGE, RAF_RSC_CP_INV_PLFAC);
			return 1;
		}
		new vehID = GetPlayerVehicleID(playerid);
		if( vehID == INVALID_VEHICLE_ID )
		{
			SendClientMessage(playerid, COLOR_ORANGE, RAF_RSC_CP_INV_VEHID);
			return 1;
		}
		new trailID = GetVehicleTrailer(vehID);
		if( trailID == 0 )
		{
			SendClientMessage(playerid, COLOR_ORANGE, RAF_RSC_CP_INV_TLID);
			return 1;
		}
		if( gVehData[vehID-1][FactionCar] != FACTIONID_RAFINERY )
		{
			SendClientMessage(playerid, COLOR_ORANGE, RAF_RSC_CP_INV_VEH_FACTION);
			return 1;
		}
		if( gVehData[trailID-1][FactionCar] != FACTIONID_RAFINERY )
		{
			SendClientMessage(playerid, COLOR_ORANGE, RAF_RSC_CP_INV_TL_FACTION);
			return 1;
		}
		new string[128];
		switch( gVehData[trailID-1][TankerResourceType] )
		{
			case TANKER_TYPE_PETROL:
				format(string, sizeof(string), "[INFO:] Cysterna jest nape³niona %dl beznyny", gVehData[trailID-1][TankerResourceValue]);
			case TANKER_TYPE_OIL:
				format(string, sizeof(string), "[INFO:] Cysterna jest nape³niona %dl ropy", gVehData[trailID-1][TankerResourceValue]);
			case TANKER_TYPE_GAS:
				format(string, sizeof(string), "[INFO:] Cysterna jest nape³niona %dl ropy", gVehData[trailID-1][TankerResourceValue]);
			default:
				format(string, sizeof(string), "[INFO:] Cysterna jest pusta");
		}			
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
		ShowPlayerDialog(playerid, 
										DIALOG_RAF_RSC_CP_MAIN, 
										DIALOG_STYLE_LIST, 
										RAF_RSC_CP_MENU_HEADER, 
										RAF_RSC_CP_MENU_OPTIONS_MAIN, 
										RAF_RSC_CP_MENU_SELECT, 
										RAF_RSC_CP_MENU_EXIT);
		return 1;
	}
	if( checkpointid == gGovCheckpoint )
	{
		ShowPlayerDialog(playerid,DIALOG_GOVERNMENT_1,DIALOG_STYLE_LIST,"Co chcesz zrobiæ ?",DIALOG_GOVERNMENT_1_TXT,"Wybierz","Zamknij");
		return 1;
	}
	if( gPlayerData[playerid][pFaction] != 255 )
	{
		if( DynamicFactions[gPlayerData[playerid][pFaction]][fType] == 3 &&
			DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryEnabled] == 1 )
		{
			if( checkpointid == DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryCPPartSetup1ID] || checkpointid == DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryCPPartSetup2ID]  )
			{
				GameTextForPlayer( playerid, WFACTORY_MOUNT_P_CP, GAME_TEXT_DEFAULT_TIME, GAME_TEXT_STYLE_6 );
				return 1;
			}
			else if( checkpointid == DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryCPAmmoPartSetup1ID] || checkpointid == DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryCPAmmoPartSetup2ID] )
			{
				GameTextForPlayer( playerid, WFACTORY_MOUNT_SP_CP, GAME_TEXT_DEFAULT_TIME, GAME_TEXT_STYLE_6 );
				return 1;
			}
			else if( checkpointid == DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryCPPartTakeID] )
			{
				GameTextForPlayer( playerid, WFACTORY_TAKE_BUY_CP, GAME_TEXT_DEFAULT_TIME, GAME_TEXT_STYLE_6 );
				return 1;
			}
		}
	}	
	if( checkpointid == WFactoryLegal[WFactoryCPPartSetup1ID] || checkpointid == WFactoryLegal[WFactoryCPPartSetup2ID] || 
		checkpointid == WFactoryLegal[WFactoryCPPartSetup3ID] || checkpointid == WFactoryLegal[WFactoryCPPartSetup4ID] || 
		checkpointid == WFactoryLegal[WFactoryCPPartSetup5ID] || checkpointid == WFactoryLegal[WFactoryCPPartSetup6ID] )
	{
		GameTextForPlayer( playerid, WFACTORY_MOUNT_P_CP, GAME_TEXT_DEFAULT_TIME, GAME_TEXT_STYLE_6 );
		return 1;
	}
	else if( checkpointid == WFactoryLegal[WFactoryCPAmmoSetup1ID] || checkpointid == WFactoryLegal[WFactoryCPAmmoSetup2ID] || 
				checkpointid == WFactoryLegal[WFactoryCPAmmoSetup3ID] || checkpointid == WFactoryLegal[WFactoryCPAmmoSetup4ID] || 
				checkpointid == WFactoryLegal[WFactoryCPAmmoSetup5ID] || checkpointid == WFactoryLegal[WFactoryCPAmmoSetup6ID] )
	{
		GameTextForPlayer( playerid, WFACTORY_MOUNT_SP_CP, GAME_TEXT_DEFAULT_TIME, GAME_TEXT_STYLE_6 );
		return 1;
	}
	else if( checkpointid == WFactoryLegal[WFactoryCPPartTakeID] )
	{
		GameTextForPlayer( playerid, WFACTORY_TAKE_BUY_CP, GAME_TEXT_DEFAULT_TIME, GAME_TEXT_STYLE_6 );
		return 1;
	}	
	else if( checkpointid == WFactoryLegal[WFactoryCPDocsID])
	{	
		GameTextForPlayer( playerid, WFACTORY_TAKE_ORD_BUY_CP, GAME_TEXT_DEFAULT_TIME, GAME_TEXT_STYLE_6 );
		return 1;
	}	
	if(checkpointid == gCShopCP1 || checkpointid == gCShopCP2 || checkpointid == gCShopCP3 || checkpointid == gCShopCP4 || checkpointid == gCShopCP5 || checkpointid == gCShopCP6)
	{
		gBuyBusiness[playerid] = GetPlayerVirtualWorld(playerid);
		new string[128];
		format( string, sizeof( string), "1.Ubrania\n2. Okulary\n3. Czapki" );
		ShowPlayerDialog( playerid, DIALOG_CBUY_1, DIALOG_STYLE_LIST, "Sklep z ubraniami", string, "Wybierz", "WyjdŸ" );
	}
	if(checkpointid == gShopCP1 || checkpointid == gShopCP2 || checkpointid == gShopCP3 || checkpointid == gShopCP4 || checkpointid == gShopCP5 || checkpointid == gShopCP6)
	{
		gBuyBusiness[playerid] = GetPlayerVirtualWorld(playerid);
		new string[512];		
		if( Businesses[ gBuyBusiness[playerid] ][BizType] == BIZT_GAS )
		{
			format( string, sizeof( string ), "1. Produkty\n2. Zap³aæ za paliwo" );
			ShowPlayerDialog(playerid,DIALOG_BUY_1,DIALOG_STYLE_LIST,"Stacja paliw",
			string,
			"Kup","WyjdŸ");
		}
		else
		{
			format( string, sizeof( string ), "1. Produkty" );
			ShowPlayerDialog(playerid,DIALOG_BUY_1,DIALOG_STYLE_LIST,"Sklep 24/7",
			string,
			"Kup","WyjdŸ");
		}
	}
	if( checkpointid == gAmmoCP1 || checkpointid == gAmmoCP2 || checkpointid == gAmmoCP3 || checkpointid == gAmmoCP4 )
	{
		gBuyBusiness[playerid] = GetPlayerVirtualWorld( playerid );
		new string[512];
		format( string, sizeof(string), "1.Broñ\n2.Amunicja" );
		ShowPlayerDialog( playerid, DIALOG_BUYW_1, DIALOG_STYLE_LIST, "Sklep z broni¹",
		string,
		"Wybierz","WyjdŸ");
	}
	return 1;
}

public OnPlayerLeaveDynamicCP(playerid, checkpointid)
{
	return 1;
}

public OnPlayerEnterDynamicRaceCP(playerid, checkpointid)
{
	return 1;
}

public OnPlayerLeaveDynamicRaceCP(playerid, checkpointid)
{
	return 1;
}

public OnPlayerEnterDynamicArea(playerid, areaid)
{
	if(areaid == gASanFierro || areaid == gALosSantos1 || areaid == gALosSantos2 || areaid == gAAngelPine || areaid == gAPalominoCreek || areaid == gAMontgomery)
	{
		gIsInCityAreaSpeedLimit[playerid] = 1;
	}
	new adres[256];
	if(areaid == gArea_Molo)
	{
		adres  = "http://94.23.6.162:8888"; // radio party 48kbps
		MoloSequence[playerid] = Audio_PlayStreamed(playerid, adres, false, false, false);
	}
	if(areaid == gArea_Pool)
	{
		adres = "http://91.121.157.213:8050"; // radio zet
		PoolSequence[playerid] = Audio_PlayStreamed(playerid, adres, false, false, false);
	}
	for(new i = 0; i < sizeof(gRadioSet); i++)
	{
		if(areaid == gRadioSet[i][AreaID])
		{
			Audio_Stop(playerid,gRadioID[i][playerid]);
			gRadioID[i][playerid] = Audio_PlayStreamed(playerid, gRadio[gRadioSet[i][StationID]], false, false, false);
			Audio_SetVolume(i, gRadioID[i][playerid], gRadio[i][Volume]);
		}
	}
	if(areaid == gArea_MW_SanFierro) { SetPlayerRealWeatherEx(playerid, gMW_sanfrancisco); }
	if(areaid == gArea_MW_LasVenturas ) { SetPlayerRealWeatherEx(playerid, gMW_lasvegas); }
	if(areaid == gArea_MW_LosSantos) { SetPlayerRealWeatherEx(playerid, gMW_losangeles); }
	return 1;
}

public OnPlayerLeaveDynamicArea(playerid, areaid)
{
	if(areaid == gASanFierro || areaid == gALosSantos1 || areaid == gALosSantos2|| areaid == gAAngelPine || areaid == gAPalominoCreek || areaid == gAMontgomery)
	{
		gIsInCityAreaSpeedLimit[playerid] = 0;
	}
	if(areaid == gArea_Molo)
	{
		Audio_Stop(playerid, MoloSequence[playerid]);
	}
	if(areaid == gArea_Pool)
	{
		Audio_Stop(playerid, PoolSequence[playerid]);
	}
	for(new i = 0; i < sizeof(gRadioSet); i++)
	{
		if(areaid == gRadioSet[i][AreaID])
		{
			Audio_Stop(playerid,gRadioID[i][playerid]);
		}
	}
	SetPlayerRealWeatherEx(playerid, gMW_warszawa);
	return 1;
}

public OnPlayerLeaveCheckpoint(playerid)
{
	return 1;
}

public OnPlayerEnterRaceCheckpoint(playerid)
{
	return 1;
}

public OnPlayerLeaveRaceCheckpoint(playerid)
{
	return 1;
}

public OnPlayerObjectMoved(playerid, objectid)
{
	return 1;
}

public OnPlayerPickUpPickup(playerid, pickupid)
{
	return 1;
}

public OnPlayerExitedMenu(playerid)
{
	return 1;
}

public OnPlayerTakeDamage(playerid, issuerid, Float:amount, weaponid)
{
	new Float:health, Float:armour;
    GetPlayerHealth(playerid,health);
    GetPlayerArmour(playerid,armour);
    new Damage;
    switch(GetPlayerWeapon(issuerid))
    {
		case 0: Damage = 10;
		case 1: Damage = 13;
		case 2,3,5,6,7: Damage = 22;
		case 8: Damage = 50;
		case 4: Damage = 35;
		case 16: Damage = 80;
		case 22: Damage = 25;
  		case 23: Damage = 20;  	
	    case 24: Damage = 50;
		case 25: Damage = 60;
        case 28,32: Damage = 20;//Tec9 & Micru-Uzi
        case 29: Damage = 30;
  		case 30: Damage = 30;
		case 31: Damage = 27;
  		case 33,34: Damage = 95;
		case 35: Damage = 250;
		case 38: Damage = 0;		
   	}
    
    armour = armour - Damage;
    if(armour < 0.0)
    {
        health += armour;//Health will decrease because armour is negative. (a + (-b) = a - b)
        if(health <= 0.0)
        {
            health = 0.0;
        }
        armour = 0.0;
    }
    SetPlayerHealth(playerid, health);
    SetPlayerArmour(playerid, armour);
	return 1;
}
