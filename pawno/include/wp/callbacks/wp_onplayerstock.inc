/***
*
* File: wp_onplayerstock.inc
* Auth: Damian Wojdat
* Date: 15.09.2011
* Desc: Player related functions/callbacks.
*
*************************************************************************************************************/

public OnPlayerConnect(playerid)
{	
	#if defined DEBUG
		printf("[DEBUG:] OnPlayerConnect by player id %d", playerid);
	#endif
	/* Reset player variables */
	ResetStats(playerid);
	
	if(!IsPlayerNPC(playerid))
	{
		/* Check player name for RP rule */
		static plname[MAX_PLAYER_NAME];
		GetPlayerName(playerid, plname, sizeof(plname));
		if(strfind(plname, "_", true) == -1)
		{
			SendClientMessage(playerid, COLOR_RED, "Twoja nazwa gracza nie jest zgodna z wymogami Role-Play !");
			SendClientMessage(playerid, COLOR_RED, "Spróbuj u¿yæ nazwy w postaci Imie_Nazwisko !");
			Kick(playerid);
			return 1;
		}		
		SetPlayerHealth(playerid, 100.0);
		SetPlayerColor(playerid, COLOR_BLACK);
	}
	
	// Player status 2
	PlayerStatus[playerid] = CreatePlayerTextDraw(playerid, 0.0, 442.0, " ");
	PlayerTextDrawUseBox(playerid, PlayerStatus[playerid], 1);
	PlayerTextDrawBoxColor(playerid, PlayerStatus[playerid], 0x000000AA);
	PlayerTextDrawAlignment(playerid, PlayerStatus[playerid], 0);
	PlayerTextDrawBackgroundColor(playerid, PlayerStatus[playerid], 0x000000ff);
	PlayerTextDrawFont(playerid, PlayerStatus[playerid], 1);
	PlayerTextDrawLetterSize(playerid, PlayerStatus[playerid], 0.15, 0.525);
	PlayerTextDrawColor(playerid, PlayerStatus[playerid], 0xffffffff);
	PlayerTextDrawSetOutline(playerid, PlayerStatus[playerid], 1);
	PlayerTextDrawSetProportional(playerid, PlayerStatus[playerid], 1);
	PlayerTextDrawSetShadow(playerid, PlayerStatus[playerid], 1);
	
	// event 2 status
	gEvent2noteText2[playerid] = CreatePlayerTextDraw(playerid, 230.000000, 329.000000, "_");
	PlayerTextDrawAlignment(playerid, gEvent2noteText2[playerid], 0);
	PlayerTextDrawBackgroundColor(playerid, gEvent2noteText2[playerid], 0x000000ff);
	PlayerTextDrawFont(playerid, gEvent2noteText2[playerid], 2);
	PlayerTextDrawLetterSize(playerid, gEvent2noteText2[playerid], 0.899999, 2.599999);
	PlayerTextDrawColor(playerid, gEvent2noteText2[playerid], 0xffff00ff);
	PlayerTextDrawSetOutline(playerid, gEvent2noteText2[playerid], 1);
	PlayerTextDrawSetProportional(playerid, gEvent2noteText2[playerid], 1);
	PlayerTextDrawSetShadow(playerid, gEvent2noteText2[playerid], 1);
	
	// wardrobe exit cmd
	gPlayerVars[playerid][mWardrobeExitText] = CreatePlayerTextDraw(playerid, 15.0, 245.0, "Wybor ubrania: strzalki~n~Kupno ubrania: spacja~n~Wyjscie: /opuscprzymierzalnie");
	PlayerTextDrawLetterSize(playerid, gPlayerVars[playerid][mWardrobeExitText], 0.20, 0.7);
	PlayerTextDrawTextSize(playerid, gPlayerVars[playerid][mWardrobeExitText], 132.0, 100.0);
	PlayerTextDrawUseBox(playerid, gPlayerVars[playerid][mWardrobeExitText], 1);
	
	return 1;
}

public OnPlayerDisconnect(playerid, reason)
{
	#if defined DEBUG
		printf("[DEBUG:] OnPlayerDisconnect by player id %d", playerid);
	#endif

	static plname[MAX_PLAYER_NAME], string[256];
	static Float:x, Float:y, Float:z;
	
	GetPlayerName(playerid, plname, sizeof(plname));
	GetPlayerPos(playerid, x, y, z);

    if(gPlayerLogged[playerid] && strcmp(plname, gPlayerData[playerid][pName], false) == 0)
	{
		// Remove player from events
		RemovePlayerFormEvents(playerid);
		
		// Stop player job (buses etc, resets vehicles and more)
		StopJob(playerid);
	
		SavePlayerData(playerid, "Energy");
		SavePlayerData(playerid, "Hunger");
		SavePlayerData(playerid, "Thirst");
		SavePlayerData(playerid, "Poison");
		SavePlayerData(playerid, "Fat");
		SavePlayerData(playerid, "Stomach");
		SavePlayerData(playerid, "Vitamins");
		SavePlayerData(playerid, "Drunk");
	
		gPlayerData[playerid][pIsLogged] = 0;
		// SavePlayerData(playerid, "IsLogged");
		
		GetPlayerIp(playerid, string, sizeof(string));
		format(string, sizeof(string), "%s sign out with $%d in character cash and $%d in bank cash, IP is %s", gPlayerData[playerid][pName], gPlayerData[playerid][pCash], gPlayerData[playerid][pBank], string);
		LogginDataLog(string);
		
		// Custom object descriptions
		HideObjectsDescriptions(playerid);
		
		// Destroy player hunger status
		DestroyProgressBar(gPlayerData[playerid][pEnergyProgressBarID]);
		DestroyProgressBar(gPlayerData[playerid][pHungerProgressBarID]);
		DestroyProgressBar(gPlayerData[playerid][pThirstProgressBarID]);
		// DestroyProgressBar(gPlayerData[playerid][pPoisonProgressBarID]);
		// DestroyProgressBar(gPlayerData[playerid][pFatProgressBarID]);
		// DestroyProgressBar(gPlayerData[playerid][pStomachProgressBarID]);
		// DestroyProgressBar(gPlayerData[playerid][pVitaminsProgressBarID]);
		// DestroyProgressBar(gPlayerData[playerid][pDrunkProgressBarID]);
		// DestroyProgressBar(gPlayerData[playerid][pNarcoticProgressBarID]);
		DestroyProgressBar(JobProgress[playerid]);

		// player descriptions
		Update3DTextLabelText(gPlayerData[playerid][pCharDescriptionID], COLOR_BLACK, " ");
		Update3DTextLabelText(gPlayerData[playerid][pCharNameID], COLOR_BLACK, " ");
		Update3DTextLabelText(playerAFK[playerid], COLOR_BLACK, " ");
	
		// Save player weapons
		GetPlayerWeaponData(playerid, 0, gPlayerData[playerid][pWSlot0], gPlayerData[playerid][pWSlot0Ammo]);
		GetPlayerWeaponData(playerid, 1, gPlayerData[playerid][pWSlot1], gPlayerData[playerid][pWSlot1Ammo]);
		GetPlayerWeaponData(playerid, 2, gPlayerData[playerid][pWSlot2], gPlayerData[playerid][pWSlot2Ammo]);
		GetPlayerWeaponData(playerid, 3, gPlayerData[playerid][pWSlot3], gPlayerData[playerid][pWSlot3Ammo]);
		GetPlayerWeaponData(playerid, 4, gPlayerData[playerid][pWSlot4], gPlayerData[playerid][pWSlot4Ammo]);
		GetPlayerWeaponData(playerid, 5, gPlayerData[playerid][pWSlot5], gPlayerData[playerid][pWSlot5Ammo]);
		GetPlayerWeaponData(playerid, 6, gPlayerData[playerid][pWSlot6], gPlayerData[playerid][pWSlot6Ammo]);
		GetPlayerWeaponData(playerid, 7, gPlayerData[playerid][pWSlot7], gPlayerData[playerid][pWSlot7Ammo]);
		GetPlayerWeaponData(playerid, 8, gPlayerData[playerid][pWSlot8], gPlayerData[playerid][pWSlot8Ammo]);
		GetPlayerWeaponData(playerid, 9, gPlayerData[playerid][pWSlot9], gPlayerData[playerid][pWSlot9Ammo]);
		GetPlayerWeaponData(playerid, 10, gPlayerData[playerid][pWSlot10], gPlayerData[playerid][pWSlot10Ammo]);
		GetPlayerWeaponData(playerid, 11, gPlayerData[playerid][pWSlot11], gPlayerData[playerid][pWSlot11Ammo]);
		GetPlayerWeaponData(playerid, 12, gPlayerData[playerid][pWSlot12], gPlayerData[playerid][pWSlot12Ammo]);
		SavePlayerData(playerid, "WSlot");
		
		// Check player race state
		RemovePlayerFromRace(playerid);
		
		if(DisconnectPhone(playerid))
		{
			SendClientMessage(Mobile[playerid], COLOR_LIGHTYELLOW2, "[INFO:] Roz³¹czy³ siê");
		}

		// Stop new sms text timer
		gPhoneTextReceived[playerid] = 0;
			
		if(x == 0.0 || y == 0.0)
		{
			printf("[WARINING:] OnPlayerDisconnect X: %f, Y: %f, Z: %f, player name: %s", x, y, z, GetPlayerNameEx(playerid));
		}
	 
		if(reason == 0)
	    {
			format(string, sizeof(string), "{DF013A}[WParty SERVER:]{FFFFFF}[ID: %d][IC: %s] %s opuœci³ gre (timeout)!", playerid, GetPlayerNameEx(playerid), gPlayerData[playerid][pOOCName]);
			foreach(Player, i)
			{
				if(gPlayerLogged[i] && i != playerid && gPlayerData[i][pLeaveInfoStatus])
				{
					SendClientMessage(i, 0xFFFFFFAA, string);
				}
			}
	    }
		else
		{
			format(string, sizeof(string), "{DF013A}[WParty SERVER:]{FFFFFF}[ID: %d][IC: %s] %s opuœci³ gre !", playerid, GetPlayerNameEx(playerid), gPlayerData[playerid][pOOCName]);
			foreach(Player, i)
			{
				if(gPlayerLogged[i] && i != playerid && gPlayerData[i][pLeaveInfoStatus])
				{
					SendClientMessage(i, 0xFFFFFFAA, string);
				}
			}
		}

		gPlayerData[playerid][pCrashX] = x;
		gPlayerData[playerid][pCrashY] = y;
		gPlayerData[playerid][pCrashZ] = z;
		GetPlayerFacingAngle(playerid, gPlayerData[playerid][pCrashAngle]);
		gPlayerData[playerid][pCrashW] = GetPlayerVirtualWorld(playerid);
		gPlayerData[playerid][pCrashInt] = GetPlayerInterior(playerid);
		
		SavePlayerData(playerid, "Crash");
		
		Spawned[playerid] = 0; 	// UAC
		
		for(new n = 0; n < CUSTOM_MAX_PLAYERS; n++)
		{
			if(gSpectateID[n] == playerid)
			{
				gSpectateID[n] = INVALID_PLAYER_ID;
			}
		}
	}
	return 1;
} // end of OnPlayerDisconnect

public OnPlayerRequestClass(playerid, classid)
{
	#if defined DEBUG
		printf("[DEBUG:] OnPlayerRequestClass by player id %d", playerid);
	#endif
	static string[512];
	
	strdel(string, 0, sizeof(string));
	
	// UAC
	Alive[playerid] = 0;

	if(IsPlayerNPC(playerid))
    {
		return 1;
    }
		
	SetPlayerTime(playerid, gHour, gMin);
	
	if(gPlayerLogged[playerid])
	{
		SetPlayerPos(playerid, 0.0, 0.0, 0.0);
		SetPlayerSpawn(playerid);
		SpawnPlayer(playerid);
		
		return 0;
	}
	else
	{
		// SetPlayerFacingAngle(playerid, player_angle);
		SetPlayerPos(playerid, 1479.46, -1816.91, 61.0);
		SetPlayerCameraPos(playerid, 1479.46, -1816.91, 69.21);
		SetPlayerCameraLookAt(playerid, 1481.23, -1652.90, 15.93);
		// PlayerPlaySound(playerid, 1097,-119.9460,23.1096,12.2238);
		PlayAudioStreamForPlayer(playerid, "http://www.miastomuzyki.pl/n/rmfclassic.pls");

		// if (gPlayerData[playerid][SpawnDance]) gPlayerData[playerid][SpawnTimer] = SetTimerEx("MoveCamera", moving_speed, true, "i", playerid);
		// gPlayerData[playerid][SpawnDance] = false; //preventing the timer to execute again
		// ClearScreen(playerid);//Clearing the users screen from SA-MP messages.
	
		strcat(string, "{FFFFFF}Witaj na serwerze WParty !\n\n");
		strcat(string, "Aby siê zalogowaæ wpisz swoje has³o do postaci.\n\n\n");
		strcat(string, "{F52222}Jeœli nie posiadasz jeszcze postaci musisz wpierw zarejestrowaæ swoje konto\nna forum WParty.eu a nastêpnie utworzyæ postaæ\npostêpuj¹æ wed³ug podanych tam wskazówek.\n\n");
		strcat(string, "{FAEC25}Jeœli zapomnia³eœ has³a do postaci mo¿esz je zmieniæ loguj¹c siê na forum\na nastêpnie przechodz¹c do panelu zarz¹dzania postaciami.\n\n\n");
		strcat(string, "{FFFFFF}Wpisz has³o:");
		ShowPlayerDialog(playerid, DIALOG_LOGIN, DIALOG_STYLE_PASSWORD, ""#COLOR_TITLE"Logowanie", string, "Zaloguj", "");

		return 0;
	}
}

public OnPlayerRequestSpawn(playerid)
{
	#if defined DEBUG
		printf("[DEBUG:] OnPlayerRequestSpawn by player id %d", playerid);
	#endif
	if(IsPlayerNPC(playerid))
	{
		return 1;
	}
	else
	{
		if(!gPlayerLogged[playerid])
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
	#if defined DEBUG
		printf("[DEBUG:] OnPlayerSpawn by player id %d", playerid);
	#endif
	// gPlayerData[playerid][SpawnAngle] = 0.0; //so when you leave and another player comes, the camera will start from start
    // gPlayerData[playerid][SpawnDance] = true; //to not execute to much timers
	// KillTimer( gPlayerData[playerid][SpawnTimer] ); //to kill it, since its useless now
	if(IsPlayerNPC(playerid)) return 1;
	defer SetPlayerSpawn2(playerid);
	RunActivatedPlayerItems(playerid);

	HideLocationsCp(playerid);
	
	Alive[playerid] = 1;
	Spawned[playerid] = 1;
	CheckDelay[playerid] = 3;
	PosHackCheckTime[playerid] = 5;	//UAC
	return 1;
}

public OnPlayerDeath(playerid, killerid, reason)
{
	#if defined DEBUG
		printf("[CALLBACK:] OnPlayerDeath");
	#endif
	
	if(!gPlayerLogged[playerid])
		return 1;

	static string[128], slot[MAX_PLAYER_ITEM_SLOT], gpsOn;
	
	GetPlayerPos(playerid, gPlayerData[playerid][pCrashX], gPlayerData[playerid][pCrashY], gPlayerData[playerid][pCrashZ]);
	gPlayerData[playerid][pCrashW] = GetPlayerVirtualWorld(playerid);
	gPlayerData[playerid][pCrashInt] = GetPlayerInterior(playerid);
	GetPlayerFacingAngle(playerid, gPlayerData[playerid][pCrashAngle]);
	
	#if defined DEBUG
		printf("[INFO:] Death X: %f, Y: %f, Z: %f", gPlayerData[playerid][pCrashX], gPlayerData[playerid][pCrashY], gPlayerData[playerid][pCrashZ]);
	#endif
	
	Alive[playerid] = 0;
	Spawned[playerid] = 0; // UAC
	gPlayerData[playerid][pSeatBelt] = 0;
	
	TextDrawHideForPlayer(playerid, Status[playerid]);
	
	gPlayerData[playerid][pDeathCount]++;
	SavePlayerData(playerid, "DeathCount");	
	
	
	BW(playerid);
	
	foreach(Player, i)
	{
		if(!gPlayerLogged[i] || i == playerid)
			continue;
		PHaveItemEx(i, 3, 12, slot);
		for(new j = 0; j < MAX_PLAYER_ITEM_SLOT; j++)
		{
			if(slot[j] && SlotParam1(playerid, j+1))
				gpsOn = 1;
		}
		if(gPlayerData[i][pFaction] == 2 && gpsOn && gPlayerData[playerid][pAdmin] == 0)
		{
			SetPlayerCheckpoint(i,gPlayerData[playerid][pCrashX]+50+random(50),gPlayerData[playerid][pCrashY]+50+random(50),gPlayerData[playerid][pCrashZ],200.0);

			defer ClearCheckpointsForPlayer(playerid);

			format(string, sizeof(string),"(( [RADIO:] Otrzymaliœmy anonimowe zg³oszenie o potrzebuj¹cej osobie ! Wolna jednostka potrzebna na miejscu ! ))");
			SendFactionMessage(2,COLOR_FACTIONCHAT,string);
		}
	}
	if(killerid != INVALID_PLAYER_ID)
	{
		if(IsPlayerConnected(killerid))
		{
			if(killerid != playerid)
			{
				if(gGangWar[Enabled] == 1)
				{
					if(gPlayerData[killerid][pFaction] == gGangWar[FactionStarted] && gPlayerData[playerid][pFaction] == DynamicZones[ gGangWar[AreaID] ][mFaction])
						gGangWar[FactionStartedKills]++;
					else if(gPlayerData[playerid][pFaction] == gGangWar[FactionStarted] && gPlayerData[killerid][pFaction] == DynamicZones[ gGangWar[AreaID] ][mFaction])
						gGangWar[FactionAttackedKills]++;
				}
				
				if(AdminDuty[playerid] && !AdminDuty[killerid])
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
				
				if(gPlayerData[killerid][pFaction] != 255)
				{
					if(DynamicFactions[gPlayerData[killerid][pFaction]][fType] == FACTIONT_POLICE)
					{
						if(gPlayerData[killerid][pDuty])
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
						else if(!gPlayerData[killerid][pDuty])
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
					else
					{
						// format(string, sizeof(string), "[SFPD:] Podejrzany %s zabi³ %s.", PlayerName(killerid), PlayerName(playerid));
						// SendFactionTypeMessage(1,COLOR_LSPD,string);
						format(string, sizeof(string), "[INFO:] Zabi³eœ niewinnego %s !", PlayerName(playerid));
						SendClientMessage(killerid, COLOR_RED, string);
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
			if(gPlayerData[killerid][pAdmin] < 1)
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
		}
	}
	
	JustDied[playerid] = 1;	
	CheckDelay[playerid] = 5;
	
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
	static wrong;
	if(!gPlayerLogged[playerid] || gPlayerData[playerid][pMuted])
	{
		return 0;
	}
	
	if(!gPlayerData[playerid][pQuiz])
	{
		wrong = gPlayerVars[playerid][mQuizWrongAnsweres];
		switch(gPlayerVars[playerid][mQuizQuestionNo])
		{
			case 1:
			{
				if(strval(text) != gQuizQuestions[a1])
					gPlayerVars[playerid][mQuizWrongAnsweres]++;
			}
			case 2:
			{
				if(strval(text) != gQuizQuestions[a2])
					gPlayerVars[playerid][mQuizWrongAnsweres]++;
			}
			case 3:
			{
				if(strval(text) != gQuizQuestions[a3])
					gPlayerVars[playerid][mQuizWrongAnsweres]++;
			}
			case 4:
			{
				if(strval(text) != gQuizQuestions[a4])
					gPlayerVars[playerid][mQuizWrongAnsweres]++;
			}
			case 5:
			{
				if(strval(text) != gQuizQuestions[a5])
					gPlayerVars[playerid][mQuizWrongAnsweres]++;
			}
			case 6:
			{
				if(strval(text) != gQuizQuestions[a6])
					gPlayerVars[playerid][mQuizWrongAnsweres]++;
			}
			case 7:
			{
				if(strval(text) != gQuizQuestions[a7])
					gPlayerVars[playerid][mQuizWrongAnsweres]++;
			}
			case 8:
			{
				if(strval(text) != gQuizQuestions[a8])
					gPlayerVars[playerid][mQuizWrongAnsweres]++;
			}
			case 9:
			{
				if(strval(text) != gQuizQuestions[a9])
					gPlayerVars[playerid][mQuizWrongAnsweres]++;
			}
			case 10:
			{
				if(strval(text) != gQuizQuestions[a10])
					gPlayerVars[playerid][mQuizWrongAnsweres]++;
			}
			case 11:
			{
				if(strval(text) != gQuizQuestions[a11])
					gPlayerVars[playerid][mQuizWrongAnsweres]++;
			}
			case 12:
			{
				if(strval(text) != gQuizQuestions[a12])
					gPlayerVars[playerid][mQuizWrongAnsweres]++;
			}
			case 13:
			{
				if(strval(text) != gQuizQuestions[a13])
					gPlayerVars[playerid][mQuizWrongAnsweres]++;
			}
			case 14:
			{
				if(strval(text) != gQuizQuestions[a14])
					gPlayerVars[playerid][mQuizWrongAnsweres]++;
			}
			case 15:
			{
				if(strval(text) != gQuizQuestions[a15])
					gPlayerVars[playerid][mQuizWrongAnsweres]++;
			}
			case 16:
			{
				if(strval(text) != gQuizQuestions[a16])
					gPlayerVars[playerid][mQuizWrongAnsweres]++;
			}
			case 17:
			{
				if(strval(text) != gQuizQuestions[a17])
					gPlayerVars[playerid][mQuizWrongAnsweres]++;
			}
			case 18:
			{
				if(strval(text) != gQuizQuestions[a18])
					gPlayerVars[playerid][mQuizWrongAnsweres]++;
			}
			case 19:
			{
				if(strval(text) != gQuizQuestions[a19])
					gPlayerVars[playerid][mQuizWrongAnsweres]++;
			}
			case 20:
			{
				if(strval(text) != gQuizQuestions[a20])
					gPlayerVars[playerid][mQuizWrongAnsweres]++;
			}
			case 21:
			{
				if(strval(text) != gQuizQuestions[a21])
					gPlayerVars[playerid][mQuizWrongAnsweres]++;
			}
			case 22:
			{
				if(strval(text) != gQuizQuestions[a22])
					gPlayerVars[playerid][mQuizWrongAnsweres]++;
			}
			case 23:
			{
				if(strval(text) != gQuizQuestions[a23])
					gPlayerVars[playerid][mQuizWrongAnsweres]++;
			}
			case 24:
			{
				if(strval(text) != gQuizQuestions[a24])
					gPlayerVars[playerid][mQuizWrongAnsweres]++;
			}
			case 25:
			{
				if(strval(text) != gQuizQuestions[a25])
					gPlayerVars[playerid][mQuizWrongAnsweres]++;
			}
		}
		SavePlayerData(playerid, "QuizWrongAnsweres");
		if(gPlayerVars[playerid][mQuizWrongAnsweres] == 3)
		{
			SendClientMessage(playerid, COLOR_RED, "Pope³ni³eœ 3 b³êdy, nie uda³o ci siê zaliczyæ quizu... Twoja postaæ zostanie usuniêta");
			gPlayerData[playerid][pSetToDelete] = 1;
			SavePlayerData(playerid, "SetToDelete");
			Kick(playerid);
			return 0;
		}
		if(wrong < gPlayerVars[playerid][mQuizWrongAnsweres])
		{
			SendClientMessage(playerid, COLOR_RED, "Poda³eœ b³êdn¹ odpowiedŸ, spróbuj jeszcze raz");
			return 0;
		}
		gPlayerVars[playerid][mQuizQuestionNo]++;
		if(gPlayerVars[playerid][mQuizQuestionNo] == 26)
		{
			SendClientMessage(playerid, COLOR_GREEN, "{DF013A}[WParty SERVER:]{FFFFFF} Odpowiedzia³eœ poprawnie na wszystkie pytania !");
			SendClientMessage(playerid, COLOR_GREEN, "{DF013A}[WParty SERVER:]{FFFFFF} Aby dowiedzieæ siê wiêcej na temat rozgrywki u¿yj komendy {DF013A}/pomoc" );
			SendClientMessage(playerid, COLOR_GREEN, "{DF013A}[WParty SERVER:]{FFFFFF} Proponujemy te¿ na pocz¹tek zapoznanie siê z {DF013A}/komendy" );
			SendClientMessage(playerid, COLOR_GREEN, "{DF013A}[WParty SERVER:]{FFFFFF} W razie jakichkolwiek pytañ pisz na /n. ¯yczymy mi³ej gry ! - {DF013A}Zespó³ WParty" );
			
			// Fill first logged player with default data
			if( gPlayerData[playerid][pRegistered] == 0 )
			{
				gPlayerData[playerid][pCrashX] = gStartSpawnX;
				gPlayerData[playerid][pCrashY] = gStartSpawnY;
				gPlayerData[playerid][pCrashZ] = gStartSpawnZ;
				gPlayerData[playerid][pCash] = gStartMoney;
				gPlayerData[playerid][pBank] = gStartBank;
				gPlayerData[playerid][pRegistered] = 1;
				DynamicFactions[FACTIONID_GOVERNMENT][fBank] -= gStartBank;
				DynamicFactions[FACTIONID_GOVERNMENT][fBank] -= gStartMoney;				
				SaveFData(FACTIONID_GOVERNMENT, "Bank");

				gSavePlayerReady[playerid] = 1; // umo¿liwia zapis w wp_saveplayerdata.inc

				SavePlayerData(playerid, "Registered");
				SetPlayerCash(playerid,gPlayerData[playerid][pCash]);
				gFirstTime[playerid] = 1;
			}
			
			gPlayerData[playerid][pQuiz] = 1;
			SavePlayerData(playerid, "Quiz");
			SpawnPlayerEx(playerid);
		}
		else
		{
			SendClientMessage(playerid, COLOR_GREEN, "OdpowiedŸ poprawna. Nastêpne pytanie:");
			ShowPlayerQuiz(playerid);
		}
		return 0;
	}
	
	static string[256], part1[128], part2[128], plName[32];
	format(plName, sizeof(plName), "%s", GetPlayerNameEx(playerid ));
	PlayerWrittingAnything[playerid] = 1;
	
	UpdateDynamic3DTextLabelText(playerAFK[playerid], COLOR_BLACK, " ");
	
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
			RemovePlayerAttachedObject(playerid, 1);
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
			RemovePlayerAttachedObject(playerid, 1);
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
			RemovePlayerAttachedObject(playerid, 1);
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
			format(string, sizeof(string), "[TEL] mówi: %s", part1);
			ProxDetector(20.0, playerid, string, COLOR_FADE1,COLOR_FADE2,COLOR_FADE3,COLOR_FADE4,COLOR_FADE5);
			TalkLog(string);
			format(string, sizeof(string), "[TEL] mówi: %s", part2);
			ProxDetector(20.0, playerid, string, COLOR_FADE1,COLOR_FADE2,COLOR_FADE3,COLOR_FADE4,COLOR_FADE5);
			TalkLog(string);
		}
		else
		{
			format(string, sizeof(string), "[TEL] mówi: %s", text);
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
						format(string, sizeof(string), "[TEL] mówi: %s", part1);
						SendClientMessage(Mobile[playerid], COLOR_LIGHTGREEN, string);
						format(string, sizeof(string), "[TEL] mówi: %s", part2);
						SendClientMessage(Mobile[playerid], COLOR_LIGHTGREEN,string);
					}
					else
					{
						format(string, sizeof(string), "[TEL] mówi: %s", text);
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
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2,"[INFO:] Nie ma nikogo na linii.");
		}
		return 0;
	}
	if(realchat)
	{
		if(gPlayerData[playerid][pCharacterDying] == 0 || PlayerTazed[playerid])
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
	
	if(!IsPlayerInAnyVehicle(playerid))
	{
		ApplyAnimation(playerid, "PED", "IDLE_CHAT", 4.1, 0, 1, 1, 1, 1, 1);
		
		if(!gPlayerVars[playerid][mIsIdleAnimationTimerActive])
		{
			gPlayerVars[playerid][mIdleAnimationTimer] = defer SetPlayerIdleAnimation(playerid);
			gPlayerVars[playerid][mIsIdleAnimationTimerActive] = true;
		}
	}
	
	return 0;
} // end of OnPlayerText

public OnPlayerClickPlayer(playerid, clickedplayerid, source)
{
	return 1;
}

public OnPlayerUpdate(playerid)
{
	static panels, doors, lights, tires, carid, i;

	
	for(i = 0; i < sizeof(SpikeInfo); i++)
	{
		if(IsPlayerInRangeOfPoint(playerid, 3.0, SpikeInfo[i][sX], SpikeInfo[i][sY], SpikeInfo[i][sZ]))
		{
			if(SpikeInfo[i][sCreated] == 1)
			{
				carid = GetPlayerVehicleID(playerid);
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
    
    // GetPlayerKeys(playerid, s_Keys, s_UpDown, s_LeftRight ); // Get the keys currently being pressed
    
    // if(!gPlayerVars[playerid][mPlayerControllable] && (s_Keys || s_UpDown || s_LeftRight)) // If any keys are pressed, don't sync the update
        // return 0;
	return 1;
}

public OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
	static string[128], Float:posX, Float:posY, Float:posZ;
	
	if(gVehData[vehicleid-1][mVehType] == 999 && !ispassenger && !AdminDuty[playerid])
	{
		GetPlayerPos(playerid, posX, posY, posZ);
		SetPlayerToPos(playerid, posX, posY, posZ);
		return 1;
	}
	
	gPlayerVars[playerid][mJustEnteredVehicle] = 5;
	
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
	if(gVehData[vehicleid-1][mVehType] == 1)
	{
		if(ispassenger == 0)
		{
			if(!TakingDrivingTestA[playerid] && !TakingDrivingTestB[playerid] && !TakingDrivingTestCE[playerid] && gPlayerData[playerid][pTestAreaTimeLeft] == 0 && PHaveItemParam5Ex(playerid, 3, 18, gPlayerData[playerid][pName]) == -1 && !IsPlayerInDynamicArea(playerid, gArea_CarTest))
			{
				new slot = PHaveItem(playerid, 3, 6);
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
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] Ten samochód nale¿y do oœrodka nauki jazdy !");
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] Nie bierzesz udzia³u w teœcie!");
				}
				else if(DynamicFactions[gPlayerData[playerid][pFaction]][fType] != 2 || (slot == 0 || SlotParam2(playerid, slot) <= 0))
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
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] Ten samochód nale¿y do oœrodka nauki jazdy !");
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] Nie bierzesz udzia³u w teœcie!");
				}
			}
		}
	}
	
	// motorowka nalezy do tego no
	if(gVehData[vehicleid-1][mVehType] == 6)
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
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] Ta ³odŸ nale¿y do oœrodka nauki sterowania ³odzi¹ !");
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] Nie bierzesz udzia³u w teœcie!");
			}
		}
	}
	
	// taksowka
	if(gVehData[vehicleid-1][mVehFaction] == 4)
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
				SendClientMessage(playerid,COLOR_WHITE,"[INFO:] Nie jesteœ taksówkarzem");
			}
		}
		if(ispassenger == 1)
		{
			Alive[playerid] = 1;
			gTaxiPassengerDistance[playerid] = 0;
			IsPlayerTaxiPassenger[playerid] = 1;
		}
	}
	
	//bus driver
	if(gVehData[vehicleid-1][mVehType] == 2)
	{
		if(ispassenger == 0)
		{
			if(gPlayerData[playerid][pJob] != JOB_BUSDRIVER)
			{
				gBusDriverIsPassenger[playerid] = 0;
			
				new Float:playerposx, Float:playerposy, Float:playerposz;
				
				GetPlayerPos(playerid, playerposx, playerposy, playerposz);
				
				if(gPlayerData[playerid][pAdmin] == 0 && gPlayerData[playerid][pFaction] != FACTIONID_GOVERNMENT && !AdminDuty[playerid])
				{
					SetPlayerToPos(playerid,playerposx, playerposy, playerposz);
				}
				
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] Nie jesteœ kierowc¹ autobusu !");
			}
		}
		else if(ispassenger != 0)
		{
			gBusDriverIsPassenger[playerid] = 1;
		}
	}
	
	//smieciarka
	if(gVehData[vehicleid-1][mVehType] == 4)
	{
		if(ispassenger == 0)
		{
			if(gPlayerData[playerid][pJob] != 14)
			{
				gTrashDriverIsPassenger[playerid] = 0;
				
				new Float:playerposx, Float:playerposy, Float:playerposz;
				
				GetPlayerPos(playerid, playerposx, playerposy, playerposz);
				
				if(gPlayerData[playerid][pAdmin] == 0 && !AdminDuty[playerid])
				{
					SetPlayerToPos(playerid,playerposx, playerposy, playerposz);
				}
				
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] Nie pracujesz w MZGK !");
			}
		}
		else
		{
			gTrashDriverIsPassenger[playerid] = 1;
		}
	}
	
	//sweeper
	if(gVehData[vehicleid-1][mVehType] == 5)
	{
		if(ispassenger == 0)
		{
			if(gPlayerData[playerid][pJob] != JOB_SWEEPER)
			{
				gSweeperDriverIsPassenger[playerid] = 0;
				
				new Float:playerposx, Float:playerposy, Float:playerposz;
				
				GetPlayerPos(playerid, playerposx, playerposy, playerposz);
				
				if(gPlayerData[playerid][pAdmin] == 0 && !AdminDuty[playerid])
				{
					SetPlayerToPos(playerid,playerposx, playerposy, playerposz);
				}
				
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] Nie pracujesz w MZGK !");
			}
		}
		else
		{
			gSweeperDriverIsPassenger[playerid] = 1;
		}
	}
	
	// farmer
	if(gVehData[vehicleid-1][mVehType] == 11)
	{
		if(ispassenger == 0)
		{
			if(gPlayerData[playerid][pJob] != JOB_FARMER)
			{
				gFarmerDriverIsPassenger[playerid] = 0;
				
				new Float:playerposx, Float:playerposy, Float:playerposz;
				
				GetPlayerPos(playerid, playerposx, playerposy, playerposz);
				
				if(gPlayerData[playerid][pAdmin] == 0 && !AdminDuty[playerid])
				{
					SetPlayerToPos(playerid,playerposx, playerposy, playerposz);
				}
				
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] Nie jesteœ rolnikiem !");
			}
		}
		else
		{
			gFarmerDriverIsPassenger[playerid] = 1;
		}
	}
	
	return 1;
} // end of OnPlayerEnterVehicle

public OnPlayerExitVehicle(playerid, vehicleid)
{
	new string[128];

	if(gVehData[vehicleid-1][mVehType] == 0)
	{
		GetVehiclePos(vehicleid, gVehData[vehicleid-1][mVehX], gVehData[vehicleid-1][mVehY], gVehData[vehicleid-1][mVehZ]);
		GetVehicleZAngle(vehicleid, gVehData[vehicleid-1][mVehA]);
		GetVehicleHealth(vehicleid, gVehData[vehicleid-1][CarHealth]);
	}

	if(gPlayerData[playerid][pSeatBelt] == 1)
	{
		gPlayerData[playerid][pSeatBelt] = 0;

		format(string, sizeof(string), "*** %s rozpina bardzo szybko swoje pasy.", GetPlayerNameEx(playerid));
		ProxDetector(20.0, playerid, string, 0xC2A2DAAA,0xC2A2DAAA,0xC2A2DAAA,0xC2A2DAAA,0xC2A2DAAA);
		
		return 1;
	}
	
	if(gVehData[vehicleid-1][mVehType] == 0 && gVehData[vehicleid-1][mVehFaction] != 255 && IsPlayerTaxiPassenger[playerid] == 1)
	{
		if(DynamicFactions[gVehData[vehicleid-1][mVehFaction]][fType] == 6)
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
						if( DynamicFactions[ gPlayerData[i][pFaction] ][fType] == 6 && gPlayerData[i][pFaction] == gVehData[vehicleid-1][mVehFaction] )
						{
							DynamicFactions[ gPlayerData[i][pFaction] ][fBank] += ( floatround(gTaxiPassengerDistance[playerid]/1000, floatround_round) * DynamicFactions[ gPlayerData[i][pFaction] ][fTaxiKMCost] + DynamicFactions[ gPlayerData[i][pFaction] ][fTaxiEnterCost] );
							SaveFData(gPlayerData[i][pFaction], "Bank");
							GivePlayerCash(playerid,-(floatround(gTaxiPassengerDistance[playerid]/1000, floatround_round) * DynamicFactions[ gPlayerData[i][pFaction] ][fTaxiKMCost] + DynamicFactions[ gPlayerData[i][pFaction] ][fTaxiEnterCost] ));
							
							format(string, sizeof(string), "Przewóz: $%d", ( floatround(gTaxiPassengerDistance[playerid]/1000, floatround_round) * DynamicFactions[ gPlayerData[i][pFaction] ][fTaxiKMCost] + DynamicFactions[ gPlayerData[i][pFaction] ][fTaxiEnterCost] ) );
							SendClientMessage(i, COLOR_LIGHTYELLOW2, string);

							format(string, sizeof(string), "Zap³aci³eœ $%d za przewóz", ( floatround(gTaxiPassengerDistance[playerid]/1000, floatround_round) * DynamicFactions[ gPlayerData[i][pFaction] ][fTaxiKMCost] + DynamicFactions[ gPlayerData[i][pFaction] ][fTaxiEnterCost] ) );
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
							
							SaveStatsData("taxi-przejazd", gPlayerData[playerid][pName], floatround(gTaxiPassengerDistance[playerid]/1000, floatround_round) * DynamicFactions[ gPlayerData[i][pFaction] ][fTaxiKMCost] + DynamicFactions[ gPlayerData[i][pFaction] ][fTaxiEnterCost], -1, -1);
						}
					}
				}
			}
			gTaxiPassengerDistance[playerid] = 0;
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
	static string[2048];

	if(IsPlayerNPC(playerid))
		return 1;
	
	/*
	* UAC Section
	*/
	if(newstate == PLAYER_STATE_SPECTATING && !(IsPlayerAdmin(playerid) || gPlayerData[playerid][pAdmin] || gPlayerData[playerid][pModerator]) && !IsPlayerNPC(playerid))
	{
		Kick(playerid);
		printf("[ANTI-CHEAT:] %s has been kicked for using Spectate", GetName(playerid));
 	}
	
	if(newstate == PLAYER_STATE_DRIVER && IngVehData[playerid] == 0 && !(IsPlayerAdmin(playerid) || gPlayerData[playerid][pAdmin] || gPlayerData[playerid][pModerator]) && !IsPlayerNPC(playerid))
	{
	    Kick(playerid);
		IngVehData[playerid] = 0;
		printf("[ANTI-CHEAT:] %s has been kicked for using Spectate", GetName(playerid));
	}

	if(newstate == PLAYER_STATE_PASSENGER)
	{
		new vehicleid = GetPlayerVehicleID(playerid);
		ResumeCarRadioStation(playerid, gVehData[vehicleid-1][RadioOn]);
		
		if(gVehData[vehicleid-1][mVehType] == 2)
		{
			// TODO: Uwzglêdniæ sytuacje gdy gracz wszed³ do autobusu ale nie by³o kierowcy a potem kierowca jedzie
			// pewnie ³atwo bêdzie poprostu wywaliæ wszystkich w momencie wejœcia kierowcy
			if(vehicleid == 1998 || vehicleid == 1999)
			{
				gBusDriverIsPassenger[playerid] = 1;
				if(IsPlayerVip(playerid))
				{
					if(vehicleid == 1999)
					{
						format(string, sizeof(string), "Cena biletu: $%d\nCena biletu ze zni¿k¹: %d", gBusTrackTicketCost[0], floatround(gBusTrackTicketCost[0]*BUS_TICKET_VIP_DISCOUNT));
					}
					else
					{
						format(string, sizeof(string), "Cena biletu: $%d\nCena biletu ze zni¿k¹: %d", 20, floatround(20*BUS_TICKET_VIP_DISCOUNT));
					}
					ShowPlayerDialog(playerid, DIALOG_BUY_BUS_TICKET, DIALOG_STYLE_MSGBOX, "Kupno biletu", string, "Kup", "WyjdŸ");
					
				}
				else
				{
					if(vehicleid == 1999)
					{
						format(string, sizeof(string), "Cena biletu: $%d", gBusTrackTicketCost[0]);
					}
					else
					{
						format(string, sizeof(string), "Cena biletu: $%d", 20);
					}
					ShowPlayerDialog(playerid, DIALOG_BUY_BUS_TICKET, DIALOG_STYLE_MSGBOX, "Kupno biletu", string, "Kup", "WyjdŸ");
				}
			}
			else
			{
				new driverId;
				driverId = GetPlayerInVehicleSeat(vehicleid, 0);
				if(driverId != -1)
				{
					if(gBusDriverOnDuty[driverId])
					{
						gBusDriverIsPassenger[playerid] = 1;
						if(IsPlayerVip(playerid))
						{
							format(string, sizeof(string), "Cena biletu: $%d\nCena biletu ze zni¿k¹: %d", gBusTrackTicketCost[gBusDriverSelectedLine[driverId]], floatround(gBusTrackTicketCost[gBusDriverSelectedLine[driverId]]*BUS_TICKET_VIP_DISCOUNT));
							ShowPlayerDialog(playerid, DIALOG_BUY_BUS_TICKET, DIALOG_STYLE_MSGBOX, "Kupno biletu", string, "Kup", "WyjdŸ");
							
						}
						else
						{
							format(string, sizeof(string), "Cena biletu: $%d", gBusTrackTicketCost[gBusDriverSelectedLine[driverId]]);
							ShowPlayerDialog(playerid, DIALOG_BUY_BUS_TICKET, DIALOG_STYLE_MSGBOX, "Kupno biletu", string, "Kup", "WyjdŸ");
						}
					}
				}
			}
		}
		else if(gVehData[vehicleid-1][mVehType] == VEHICLET_TAXI_TP)
		{
			format(string, sizeof(string), "");
			for(new i = 0; i < sizeof(gTaxiLocations); i++)
			{
				format(string, sizeof(string), ""#COLOR_DEFAULT"%s%s\n", string, gTaxiLocations[i][mLocationDescription]);
			}
			ShowPlayerDialog(playerid, DIALOG_TELEPORT_TAXI, DIALOG_STYLE_LIST, ""#COLOR_TITLE"Lista miejsc", string, "Wybierz", "Zamknij");
		}
	}
	else if(newstate == PLAYER_STATE_DRIVER)
	{
		new
			vehicleid = GetPlayerVehicleID(playerid),
			vehicleidd = vehicleid - 1,
			vehiclemodel = GetVehicleModel(vehicleid),
			Float:vehX, Float:vehY, Float:vehZ, Float:vehA,
			enginedyn,lights,alarm,bonnet,boot,objective, doors,
			Float:vhealth;
			
		GetVehiclePos(vehicleid, vehX, vehY, vehZ);
		GetVehicleZAngle(vehicleid, vehA);
		GetVehicleParamsEx(vehicleid, enginedyn, lights, alarm, doors, bonnet, boot, objective);
		
		format(string, sizeof(string), "[VEHICLE:] Player Name: %s, Vehicle ID: %d, Model ID: %d, Type: %d, Player Job: %d, Veh X: %f, Veh Y: %f, Veh Z: %f, Veh Angle: %f",
			gPlayerData[playerid][pName], vehicleid, vehiclemodel, gVehData[vehicleid-1][mVehType], gPlayerData[playerid][pJob], vehX, vehY, vehZ, vehA);
		StateChangeLog(string);
		

		/*
		* Player spectating - change spectate to vehicle
		*/
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
		
		
		/*
		* Admin vehicle protect
		*/
		if(vehicleid == 255 && strcmp("Andy_Brazil", gPlayerData[playerid][pName], false) != 0)
		{
			RemovePlayerFromVehicle(playerid);
			SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Ten pojazd nale¿y do adminsitratora Xtreme. Nie mo¿esz go prowadziæ !");
			return 1;
		}
		
		if(vehicleid == 256 && strcmp("Soin_Noiskin", gPlayerData[playerid][pName], false) != 0)
		{
			RemovePlayerFromVehicle(playerid);
			SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Ten pojazd nale¿y do adminsitratora Xamxe. Nie mo¿esz go prowadziæ !");
			return 1;
		}
		
		
		/*
		* Show radio status and resume radio if it is on
		*/
		if(gVehData[vehicleidd][RadioOn] != 0)
		{
			ResumeCarRadioStation(playerid, gVehData[vehicleidd][RadioOn]);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Radio jest w³¹czone");
		}		
		
		
		/*
		* Show sell info
		*/
		if(gVehData[vehicleidd][ReadyToSell] == 1)
		{
			format(string, sizeof(string), ""#COLOR_DEFAULT"Pojazd jest na sprzeda¿ ! Cena: $%d /kuppojazd", gVehData[vehicleidd][Price]);
			ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, ""#COLOR_TITLE"Informacja", string, "Zamknij", "");
		}
		else if(gVehData[vehicleidd][mVehOwned] == 0 && gVehData[vehicleidd][mVehType] == 0 && gVehData[vehicleidd][mVehFaction] == 255)
		{
			format(string, sizeof(string), ""#COLOR_DEFAULT"Pojazd jest na sprzeda¿ ! Cena: $%d + %d%% VAT /kuppojazd", gVehData[vehicleidd][Price], floatround(DynamicTaxes[VatTaxMax]*100.0));
			ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, ""#COLOR_TITLE"Informacja", string, "Zamknij", "");
		}
		
		
		/*
		* Clean import slots for next vehicles
		*/
		if(IsAPlane(vehicleid) || IsAHelicopter(vehicleid))
		{
			for(new i = 0; i < 20; i++)
			{
				if(SpawnPlacePlanes[i][VehicleID] == vehicleid && strcmp(gPlayerData[playerid][pName], Businesses[gVehData[vehicleid-1][BusinessID]][Owner], false) == 0 && vehicleid != 255)
				{
					SpawnPlacePlanes[i][VehicleID] = 255;
					SpawnPlacePlanes[i][SlotUsed] = 0;
					SaveDynamicPlanesSpawns();
					ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Ten pojazd jest teraz gotowy do sprzeda¿y !", "Ok", "");
					break;
				}
			}
		}
		
		if(IsABoat(vehicleid))
		{
			for(new i = 0; i < 20; i++)
			{
				if(SpawnPlaceBoats[i][VehicleID] == vehicleid && strcmp(gPlayerData[playerid][pName], Businesses[gVehData[vehicleid-1][BusinessID]][Owner], false) == 0 && vehicleid != 255)
				{
					SpawnPlaceBoats[i][VehicleID] = 255;
					SpawnPlaceBoats[i][SlotUsed] = 0;
					SaveDynamicBoatsSpawns();
					ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Ten pojazd jest teraz gotowy do sprzeda¿y !", "Ok", "");
					break;
				}
			}
		}
		
		if(!IsABoat(vehicleid) && !IsAPlane(vehicleid) && !IsAHelicopter(vehicleid))
		{
			for(new i = 0; i < 20; i++)
			{
				if(SpawnPlaceCars[i][VehicleID] == vehicleid && strcmp(gPlayerData[playerid][pName], Businesses[gVehData[vehicleid-1][BusinessID]][Owner], false) == 0 && vehicleid != 255)
				{
					SpawnPlaceCars[i][VehicleID] = 255;
					SpawnPlaceCars[i][SlotUsed] = 0;
					SaveDynamicCarSpawns();
					ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Ten pojazd jest teraz gotowy do sprzeda¿y !", "Ok", "");
					break;
				}
			}
		}	
		
		/*
		* Set engien status, check if is a bike and if it is launch it without commands.
		* Olso show info about vehicle price if not owned.
		*/
		if(gVehData[vehicleidd][mVehType] == 0)
		{		
			if(!IsABike(vehicleid))
			{
				if(!gVehData[vehicleidd][EngineOn])
				{
					SetVehicleParamsEx(vehicleid,0,lights,alarm,doors,bonnet,boot,objective);
				}
				else
				{
					SetVehicleParamsEx(vehicleid,1,lights,alarm,doors,bonnet,boot,objective);
				}
			}
			else
			{
				if(!gVehData[vehicleidd][Closed] || AdminDuty[playerid])
				{
					SetVehicleParamsEx(vehicleid,1,lights,alarm,doors,bonnet,boot,objective);
					gVehData[vehicleid-1][EngineOn] = 1;
				}
				else
				{
					SetVehicleParamsEx(vehicleid,0,lights,alarm,doors,bonnet,boot,objective);
					gVehData[vehicleid-1][EngineOn] = 0;
					
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Rower jest spiêty zapiêciem, nie mo¿esz nim jechaæ");
				}
				SaveVehData(vehicleid-1, "EngineOn");
			}
		}
		
		/*
		* Special interior vehicles to be filled with gas, fixed and running
		*/
		else if(gVehData[vehicleidd][mVehType] != 0)
		{
			RepairVehicle(vehicleid);
			
			SetVehicleHealth(vehicleid, 2000.0);
			
			SetVehicleParamsEx(vehicleid, 1, 1, alarm, doors, bonnet, boot, objective);
			
			gVehData[vehicleid-1][BatteryCapacity] = 25.0;
			gVehData[vehicleid-1][BatteryMaxCapacity] = 25.0;
			gVehData[vehicleid-1][EngineOn] = 1;
			gVehData[vehicleid-1][LightsOn] = 1;
			gVehData[vehicleid-1][CarFuel] = float(VehFTank(vehicleid));
			
			GetVehicleHealth(vehicleid, gVehData[vehicleid-1][CarHealth]);
		}
		
		/*
		* Check if player have apriopriate licence for given type of vehicle
		*/
		new slot[MAX_PLAYER_ITEM_SLOT];
		PHaveItemEx(playerid, 3, 6, slot);
		new licA, licB, licCE;
		for(new i = 0; i < MAX_PLAYER_ITEM_SLOT; i++)
		{
			if(slot[i])
			{
				if(SlotParam1(playerid, i+1))
					licA = 1;
				if(SlotParam2(playerid, i+1))
					licB = 1;
				if(SlotParam3(playerid, i+1))
					licCE = 1;
			}
		}			
		
		if(IsAVehCatAModel(gVehData[vehicleid-1][mVehModel]) && !TakingDrivingTestA[playerid] && !licA)
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Prawo jazdy kat. A jest wymagane aby legalnie prowadziæ ten pojazd !");
		
		else if(IsAVehCatBModel(gVehData[vehicleid-1][mVehModel]) && !TakingDrivingTestB[playerid] && !licB)
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Prawo jazdy kat. B jest wymagane aby legalnie prowadziæ ten pojazd !");
		
		else if(IsAVehCatCEModel(gVehData[vehicleid-1][mVehModel]) && !TakingDrivingTestCE[playerid] && !licCE)
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Prawo jazdy kat. C+E jest wymagane aby legalnie prowadziæ ten pojazd !");			
		
		else if(((IsAPlane(vehicleid) && !gPlayerData[playerid][pPlaneLic]) || (IsAHelicopter(vehicleid) && !gPlayerData[playerid][pHeliLic])) && !AdminDuty[playerid])
		{
			RemovePlayerFromVehicle(playerid);
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz licencji pilota !");
	   	}
		
		
		/*
		* Reset data of special vehicle type
		*/
		// WORD vehicle
		if(gVehData[vehicleidd][mVehType] == 1)
		{
			gVehData[vehicleidd][CarFuel] = float(VehFTank(vehicleid));
			RepairVehicle(vehicleid);
			gVehData[vehicleidd][CarDamaged] = 0;
			gVehData[vehicleidd][CarRepairTimeLeft] = 0;
			gVehData[vehicleidd][CarHealth] = 1000.0;
			
			SaveVehData(vehicleidd, "CarHealth");
			SaveVehData(vehicleidd, "CarDamaged");
			SaveVehData(vehicleidd, "CarRepairTimeLeft");
		}
		
		// Bus vehicle
		else if(gVehData[vehicleidd][mVehType] == 2)
		{
			if(gBusDriverIsPassenger[playerid] == 0)
			{
				if(gBusDriverOnDuty[playerid] == 0 && gPlayerData[playerid][pJob] == JOB_BUSDRIVER)
				{
					if(gVehData[vehicleidd][CarFuel] < 5.0)
					{
						gVehData[vehicleidd][CarFuel] = 5.0;
						SaveVehData( vehicleidd, "CarFuel" );
					}
					
					SetProgressBarValue(JobProgress[playerid], gPlayerData[playerid][pBusJobPoints]);
					UpdateProgressBar(JobProgress[playerid], playerid);
					
					EnteredVehicleID[playerid] = vehicleid;
					
					gBusDriverIsPassenger[playerid] = 0;
					
					GetVehicleHealth(vehicleid, vhealth);
					
					if(vhealth <= 700.0)
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Autobus jest uszkodzony, udaj siê do mechanika");
					}
					else
					{
						if(gVehData[vehicleidd][CarFuel] < 20.0)
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Autobus ma ma³o paliwa, udaj siê na jedn¹ ze stacji benzynowych i zatankuj go");
						}
						else
						{
							if(IsPlayerInDynamicArea(playerid, gASanFierro))
							{
								new rand = random(50);
								new tries = 0;
								
								while(!gBusTrackEnabled[rand] || gBusTrackStartArea[rand] != 0)
								{
									rand = random(50);
									tries++;
									if(tries == 100)
										break;
								}
								
								if(tries == 100)
								{
									SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Centrala jest obecnie obci¹¿ona - nie uda³o siê wybraæ trasy !");
									return 1;
								}
								
								gBusDriverOnDuty[playerid] = 1;
								gBusDriverSelectedLine[playerid] = rand;
								gBusDriverJustStarted[playerid] = 1;
								
								UpdateDynamic3DTextLabelText(BusRoute[vehicleid-1], COLOR_LIGHTYELLOW, gBusTrackDesc[rand]);
								
								format(string, sizeof(string), "[INFO:] Jedziesz tras¹ nr %d", rand);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Udaj siê do pierwszego przystanku zaznaczonego na mapce.");
							}
							else if(IsPlayerInDynamicArea(playerid, gAAngelPine))
							{
								new rand = random(50);
								new tries = 0;
								
								while(!gBusTrackEnabled[rand] || gBusTrackStartArea[rand] != 3)
								{
									rand = random(50);
									tries++;
									if(tries == 100)
										break;
								}
								
								if(tries == 100)
								{
									SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Centrala jest obecnie obci¹¿ona - nie uda³o siê wybraæ trasy !");
									return 1;
								}
								
								gBusDriverOnDuty[playerid] = 1;
								gBusDriverSelectedLine[playerid] = rand;
								gBusDriverJustStarted[playerid] = 1;
								
								UpdateDynamic3DTextLabelText(BusRoute[vehicleid-1], COLOR_LIGHTYELLOW, gBusTrackDesc[rand]);
								
								format(string, sizeof(string), "[INFO:] Jedziesz tras¹ nr %d", rand);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Udaj siê do pierwszego przystanku zaznaczonego na mapce.");
							}
							else if(IsPlayerInDynamicArea(playerid, gALosSantos1))
							{
								new rand = random(50);
								new tries = 0;
								
								while(!gBusTrackEnabled[rand] || gBusTrackStartArea[rand] != 1)
								{
									rand = random(50);
									tries++;
									if(tries == 100)
										break;
								}
								
								if(tries == 100)
								{
									SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Centrala jest obecnie obci¹¿ona - nie uda³o siê wybraæ trasy !");
									return 1;
								}
								
								gBusDriverOnDuty[playerid] = 1;
								gBusDriverSelectedLine[playerid] = rand;
								gBusDriverJustStarted[playerid] = 1;
								
								UpdateDynamic3DTextLabelText(BusRoute[vehicleid-1], COLOR_LIGHTYELLOW, gBusTrackDesc[rand]);
								
								format(string, sizeof(string), "[INFO:] Jedziesz tras¹ nr %d", rand);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Udaj siê do pierwszego przystanku zaznaczonego na mapce.");
							}
							else if(IsPlayerInDynamicArea(playerid, gALosSantos2))
							{
								new rand = random(50);
								new tries = 0;
								
								while(!gBusTrackEnabled[rand] || gBusTrackStartArea[rand] != 2)
								{
									rand = random(50);
									tries++;
									if(tries == 100)
										break;
								}
								
								if(tries == 100)
								{
									SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Centrala jest obecnie obci¹¿ona - nie uda³o siê wybraæ trasy !");
									return 1;
								}
								
								gBusDriverOnDuty[playerid] = 1;
								gBusDriverSelectedLine[playerid] = rand;
								gBusDriverJustStarted[playerid] = 1;
								
								UpdateDynamic3DTextLabelText(BusRoute[vehicleid-1], COLOR_LIGHTYELLOW, gBusTrackDesc[rand]);
								
								format(string, sizeof(string), "[INFO:] Jedziesz tras¹ nr %d", rand);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Udaj siê do pierwszego przystanku zaznaczonego na mapce.");
							}
							else if(IsPlayerInDynamicArea(playerid, gAMontgomery))
							{
								new rand = random(50);
								new tries = 0;
								
								while(!gBusTrackEnabled[rand] || gBusTrackStartArea[rand] != 4)
								{
									rand = random(50);
									tries++;
									if(tries == 100)
										break;
								}
								
								if(tries == 100)
								{
									SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Centrala jest obecnie obci¹¿ona - nie uda³o siê wybraæ trasy !");
									return 1;
								}
								
								gBusDriverOnDuty[playerid] = 1;
								gBusDriverSelectedLine[playerid] = rand;
								gBusDriverJustStarted[playerid] = 1;
								
								UpdateDynamic3DTextLabelText(BusRoute[vehicleid-1], COLOR_LIGHTYELLOW, gBusTrackDesc[rand]);
								
								format(string, sizeof(string), "[INFO:] Jedziesz tras¹ nr %d", rand);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Udaj siê do pierwszego przystanku zaznaczonego na mapce.");
							}
							else if(IsPlayerInDynamicArea(playerid, gAPalominoCreek))
							{
								new rand = random(50);
								new tries = 0;
								
								while(!gBusTrackEnabled[rand] || gBusTrackStartArea[rand] != 5)
								{
									rand = random(50);
									tries++;
									if(tries == 100)
										break;
								}
								
								if(tries == 100)
								{
									SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Centrala jest obecnie obci¹¿ona - nie uda³o siê wybraæ trasy !");
									return 1;
								}
								
								gBusDriverOnDuty[playerid] = 1;
								gBusDriverSelectedLine[playerid] = rand;
								gBusDriverJustStarted[playerid] = 1;
								
								UpdateDynamic3DTextLabelText(BusRoute[vehicleid-1], COLOR_LIGHTYELLOW, gBusTrackDesc[rand]);
								
								format(string, sizeof(string), "[INFO:] Jedziesz tras¹ nr %d", rand);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Udaj siê do pierwszego przystanku zaznaczonego na mapce.");
							}
							else if(IsPlayerInDynamicArea(playerid, gABountyBay))
							{
								new rand = random(50);
								new tries = 0;
								
								while(!gBusTrackEnabled[rand] || gBusTrackStartArea[rand] != 6)
								{
									rand = random(50);
									tries++;
									if(tries == 100)
										break;
								}
								
								if(tries == 100)
								{
									SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Centrala jest obecnie obci¹¿ona - nie uda³o siê wybraæ trasy !");
									return 1;
								}
								
								gBusDriverOnDuty[playerid] = 1;
								gBusDriverSelectedLine[playerid] = rand;
								gBusDriverJustStarted[playerid] = 1;
								
								UpdateDynamic3DTextLabelText(BusRoute[vehicleid-1], COLOR_LIGHTYELLOW, gBusTrackDesc[rand]);
								
								format(string, sizeof(string), "[INFO:] Jedziesz tras¹ nr %d", rand);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Udaj siê do pierwszego przystanku zaznaczonego na mapce.");
							}
							else if(IsPlayerInDynamicArea(playerid, gADilimore))
							{
								new rand = random(50);
								new tries = 0;
								
								while(!gBusTrackEnabled[rand] || gBusTrackStartArea[rand] != 7)
								{
									rand = random(50);
									tries++;
									if(tries == 100)
										break;
								}
								
								if(tries == 100)
								{
									SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Centrala jest obecnie obci¹¿ona - nie uda³o siê wybraæ trasy !");
									return 1;
								}
								
								gBusDriverOnDuty[playerid] = 1;
								gBusDriverSelectedLine[playerid] = rand;
								gBusDriverJustStarted[playerid] = 1;
								
								UpdateDynamic3DTextLabelText(BusRoute[vehicleid-1], COLOR_LIGHTYELLOW, gBusTrackDesc[rand]);
								
								format(string, sizeof(string), "[INFO:] Jedziesz tras¹ nr %d", rand);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Udaj siê do pierwszego przystanku zaznaczonego na mapce.");
							}
							else if(IsPlayerInDynamicArea(playerid, gAFortCarson))
							{
								new rand = random(50);
								new tries = 0;
								
								while(!gBusTrackEnabled[rand] || gBusTrackStartArea[rand] != 8)
								{
									rand = random(50);
									tries++;
									if(tries == 100)
										break;
								}
								
								if(tries == 100)
								{
									SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Centrala jest obecnie obci¹¿ona - nie uda³o siê wybraæ trasy !");
									return 1;
								}
								
								gBusDriverOnDuty[playerid] = 1;
								gBusDriverSelectedLine[playerid] = rand;
								gBusDriverJustStarted[playerid] = 1;
								
								UpdateDynamic3DTextLabelText(BusRoute[vehicleid-1], COLOR_LIGHTYELLOW, gBusTrackDesc[rand]);
								
								format(string, sizeof(string), "[INFO:] Jedziesz tras¹ nr %d", rand);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Udaj siê do pierwszego przystanku zaznaczonego na mapce.");
							}
							else if(IsPlayerInDynamicArea(playerid, gALosSantos3))
							{
								new rand = random(50);
								new tries = 0;
								
								while(!gBusTrackEnabled[rand] || gBusTrackStartArea[rand] != 9)
								{
									rand = random(50);
									tries++;
									if(tries == 100)
										break;
								}
								
								if(tries == 100)
								{
									SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Centrala jest obecnie obci¹¿ona - nie uda³o siê wybraæ trasy !");
									return 1;
								}
								
								gBusDriverOnDuty[playerid] = 1;
								gBusDriverSelectedLine[playerid] = rand;
								gBusDriverJustStarted[playerid] = 1;
								
								UpdateDynamic3DTextLabelText(BusRoute[vehicleid-1], COLOR_LIGHTYELLOW, gBusTrackDesc[rand]);
								
								format(string, sizeof(string), "[INFO:] Jedziesz tras¹ nr %d", rand);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Udaj siê do pierwszego przystanku zaznaczonego na mapce.");
							}
							else if(IsPlayerInDynamicArea(playerid, gALosSantos4))
							{
								new rand = random(50);
								new tries = 0;
								
								while(!gBusTrackEnabled[rand] || gBusTrackStartArea[rand] != 10)
								{
									rand = random(50);
									tries++;
									if(tries == 100)
										break;
								}
								
								if(tries == 100)
								{
									SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Centrala jest obecnie obci¹¿ona - nie uda³o siê wybraæ trasy !");
									return 1;
								}
								
								gBusDriverOnDuty[playerid] = 1;
								gBusDriverSelectedLine[playerid] = rand;
								gBusDriverJustStarted[playerid] = 1;
								
								UpdateDynamic3DTextLabelText(BusRoute[vehicleid-1], COLOR_LIGHTYELLOW, gBusTrackDesc[rand]);
								
								format(string, sizeof(string), "[INFO:] Jedziesz tras¹ nr %d", rand);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Udaj siê do pierwszego przystanku zaznaczonego na mapce.");
							}
							else if(IsPlayerInDynamicArea(playerid, gALosSantos5))
							{
								new rand = random(50);
								new tries = 0;
								
								while(!gBusTrackEnabled[rand] || gBusTrackStartArea[rand] != 11)
								{
									rand = random(50);
									tries++;
									if(tries == 100)
										break;
								}
								
								if(tries == 100)
								{
									SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Centrala jest obecnie obci¹¿ona - nie uda³o siê wybraæ trasy !");
									return 1;
								}
								
								gBusDriverOnDuty[playerid] = 1;
								gBusDriverSelectedLine[playerid] = rand;
								gBusDriverJustStarted[playerid] = 1;
								
								UpdateDynamic3DTextLabelText(BusRoute[vehicleid-1], COLOR_LIGHTYELLOW, gBusTrackDesc[rand]);
								
								format(string, sizeof(string), "[INFO:] Jedziesz tras¹ nr %d", rand);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Udaj siê do pierwszego przystanku zaznaczonego na mapce.");
							}
							else if(IsPlayerInDynamicArea(playerid, gALosSantos6))
							{
								new rand = random(50);
								new tries = 0;
								
								while(!gBusTrackEnabled[rand] || gBusTrackStartArea[rand] != 12)
								{
									rand = random(50);
									tries++;
									if(tries == 100)
										break;
								}
								
								if(tries == 100)
								{
									SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Centrala jest obecnie obci¹¿ona - nie uda³o siê wybraæ trasy !");
									return 1;
								}
								
								gBusDriverOnDuty[playerid] = 1;
								gBusDriverSelectedLine[playerid] = rand;
								gBusDriverJustStarted[playerid] = 1;
								
								UpdateDynamic3DTextLabelText(BusRoute[vehicleid-1], COLOR_LIGHTYELLOW, gBusTrackDesc[rand]);
								
								format(string, sizeof(string), "[INFO:] Jedziesz tras¹ nr %d", rand);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Udaj siê do pierwszego przystanku zaznaczonego na mapce.");
							}
							else if(IsPlayerInDynamicArea(playerid, gALosSantos7))
							{
								new rand = random(50);
								new tries = 0;
								
								while(!gBusTrackEnabled[rand] || gBusTrackStartArea[rand] != 13)
								{
									rand = random(50);
									tries++;
									if(tries == 100)
										break;
								}
								
								if(tries == 100)
								{
									SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Centrala jest obecnie obci¹¿ona - nie uda³o siê wybraæ trasy !");
									return 1;
								}
								
								gBusDriverOnDuty[playerid] = 1;
								gBusDriverSelectedLine[playerid] = rand;
								gBusDriverJustStarted[playerid] = 1;
								
								UpdateDynamic3DTextLabelText(BusRoute[vehicleid-1], COLOR_LIGHTYELLOW, gBusTrackDesc[rand]);
								
								format(string, sizeof(string), "[INFO:] Jedziesz tras¹ nr %d", rand);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Udaj siê do pierwszego przystanku zaznaczonego na mapce.");
							}
							else if(IsPlayerInDynamicArea(playerid, gALosSantos8))
							{
								new rand = random(50);
								new tries = 0;
								
								while(!gBusTrackEnabled[rand] || gBusTrackStartArea[rand] != 15)
								{
									rand = random(50);
									tries++;
									if(tries == 100)
										break;
								}
								
								if(tries == 100)
								{
									SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Centrala jest obecnie obci¹¿ona - nie uda³o siê wybraæ trasy !");
									return 1;
								}
								
								gBusDriverOnDuty[playerid] = 1;
								gBusDriverSelectedLine[playerid] = rand;
								gBusDriverJustStarted[playerid] = 1;
								
								UpdateDynamic3DTextLabelText(BusRoute[vehicleid-1], COLOR_LIGHTYELLOW, gBusTrackDesc[rand]);
								
								format(string, sizeof(string), "[INFO:] Jedziesz tras¹ nr %d", rand);
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
				else if(gBusDriverOnDuty[playerid] && gPlayerData[playerid][pJob] == JOB_BUSDRIVER)
				{
					if(EnteredVehicleID[playerid] != GetPlayerVehicleID(playerid))
					{
						ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Wróæ do pojazdu, w którym zacz¹³eœ prace aby j¹ kontynuuowaæ.", "Zamknij", "");
					}
					else
					{
						gBusDriverResetTime[playerid] = 0;
					
						SetProgressBarValue(JobProgress[playerid], gPlayerData[playerid][pBusJobPoints]);
						UpdateProgressBar(JobProgress[playerid], playerid);
						
						SetPlayerCheckpoint(playerid, gBusTrackCpX[ gBusDriverSelectedLine[playerid] ][ gBusDriverCurrentCheckPoint[playerid] ], gBusTrackCpY[ gBusDriverSelectedLine[playerid] ][ gBusDriverCurrentCheckPoint[playerid] ], gBusTrackCpZ[ gBusDriverSelectedLine[playerid] ][ gBusDriverCurrentCheckPoint[playerid] ], 5.0);
					}
				}
			}
			else
			{
				gBusDriverIsPassenger[playerid] = 1;
				
				GivePlayerCash(playerid, -5);
				
				DynamicFactions[FACTIONID_GOVERNMENT][fBank] += 5;
				SaveFData(FACTIONID_GOVERNMENT, "Bank");
				
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Zap³aci³eœ 5$ za bilet");	
			}
		}
		
		// Trash vehicle
		else if(gVehData[vehicleidd][mVehType] == 4)
		{
			if(gTrashDriverIsPassenger[playerid] == 0 && gPlayerData[playerid][pJob] == JOB_TRASHDRIVER)
			{
				if(gTrashDriverOnDuty[playerid] == 0)
				{
					if(gVehData[vehicleidd][CarFuel] < 5.0)
					{
						gVehData[vehicleidd][CarFuel] = 5.0;
						SaveVehData( vehicleidd, "CarFuel" );
					}
					
					SetProgressBarValue(JobProgress[playerid], gPlayerData[playerid][pMzgkJobPoints]);
					UpdateProgressBar(JobProgress[playerid], playerid);
					
					EnteredVehicleID[playerid] = vehicleid;
					
					GetVehicleHealth(vehicleid, vhealth);
					
					if(vhealth <= 700.0)
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Œmierciarka jest uszkodzona, udaj siê do mechanika lub zadzwon pod 555");
					}
					else
					{
						if(gVehData[vehicleidd][CarFuel] < 20.0)
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Œmierciarka ma ma³o paliwa, udaj siê na jedn¹ ze stacji benzynowych i zatankuj j¹");
						}
						else
						{
							if(IsPlayerInDynamicArea(playerid, gASanFierro))
							{
								new rand = random(50);
								new tries = 0;
								while(!gTrashTrackEnabled[rand] || gTrashTrackStartArea[rand] != 0)
								{
									rand = random(50);
									tries++;
									if( tries == 100 )
										break;
								}
								if(tries == 100)
								{
									SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Centrala jest obecnie obci¹¿ona - nie uda³o siê wybraæ trasy !");
									return 1;
								}
								gTrashDriverOnDuty[playerid] = 1;
								gTrashDriverSelectedLine[playerid] = rand;
								gTrashDriverJustStarted[playerid] = 1;
								printf("trasa 0, %f, %f, %f", gTrashTrackCpX[rand][0], gTrashTrackCpY[rand][0], gTrashTrackCpZ[rand][0]);
								format( string, sizeof(string), "[INFO:] Jedziesz tras¹ nr %d", rand );
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Udaj siê do pierwszego punktu zaznaczonego na mapce");
							}
							else if(IsPlayerInDynamicArea(playerid, gAAngelPine))
							{
								new rand = random(50);
								new tries = 0;
								while(!gTrashTrackEnabled[rand] || gTrashTrackStartArea[rand] != 3)
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
								gTrashDriverOnDuty[playerid] = 1;
								gTrashDriverSelectedLine[playerid] = rand;
								gTrashDriverJustStarted[playerid] = 1;
								format( string, sizeof(string), "[INFO:] Jedziesz tras¹ nr %d", rand );
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Udaj siê do pierwszego przystanku zaznaczonego na mapce.");
							}
							else if(IsPlayerInDynamicArea(playerid, gALosSantos1))
							{
								new rand = random(50);
								new tries = 0;
								while(!gTrashTrackEnabled[rand] || gTrashTrackStartArea[rand] != 1)
								{
									rand = random(50);
									tries++;
									if( tries == 100 )
										break;
								}
								if(tries == 100)
								{
									SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Centrala jest obecnie obci¹¿ona - nie uda³o siê wybraæ trasy !");
									return 1;
								}
								gTrashDriverOnDuty[playerid] = 1;
								gTrashDriverSelectedLine[playerid] = rand;
								gTrashDriverJustStarted[playerid] = 1;
								format(string, sizeof(string), "[INFO:] Jedziesz tras¹ nr %d", rand);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Udaj siê do pierwszego przystanku zaznaczonego na mapce.");
							}
							else if(IsPlayerInDynamicArea(playerid, gALosSantos2))
							{
								new rand = random(50);
								new tries = 0;
								while(!gTrashTrackEnabled[rand] || gTrashTrackStartArea[rand] != 2)
								{
									rand = random(50);
									tries++;
									if( tries == 100 )
										break;
								}
								if(tries == 100)
								{
									SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Centrala jest obecnie obci¹¿ona - nie uda³o siê wybraæ trasy !");
									return 1;
								}
								gTrashDriverOnDuty[playerid] = 1;
								gTrashDriverSelectedLine[playerid] = rand;
								gTrashDriverJustStarted[playerid] = 1;
								format( string, sizeof(string), "[INFO:] Jedziesz tras¹ nr %d", rand );
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Udaj siê do pierwszego przystanku zaznaczonego na mapce.");
							}
							else if(IsPlayerInDynamicArea(playerid, gAMontgomery))
							{
								new rand = random(50);
								new tries = 0;
								while( !gTrashTrackEnabled[rand] || gTrashTrackStartArea[rand] != 4 )
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
								gTrashDriverOnDuty[playerid] = 1;
								gTrashDriverSelectedLine[playerid] = rand;
								gTrashDriverJustStarted[playerid] = 1;
								format( string, sizeof(string), "[INFO:] Jedziesz tras¹ nr %d", rand );
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Udaj siê do pierwszego przystanku zaznaczonego na mapce.");
							}
							else if(IsPlayerInDynamicArea(playerid, gAPalominoCreek))
							{
								new rand = random(50);
								new tries = 0;
								while( !gTrashTrackEnabled[rand] || gTrashTrackStartArea[rand] != 5 )
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
								gTrashDriverOnDuty[playerid] = 1;
								gTrashDriverSelectedLine[playerid] = rand;
								gTrashDriverJustStarted[playerid] = 1;
								format( string, sizeof(string), "[INFO:] Jedziesz tras¹ nr %d", rand );
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Udaj siê do pierwszego przystanku zaznaczonego na mapce.");
							}
							else if(IsPlayerInDynamicArea(playerid, gABountyBay))
							{
								new rand = random(50);
								new tries = 0;
								while(!gTrashTrackEnabled[rand] || gTrashTrackStartArea[rand] != 6)
								{
									rand = random(50);
									tries++;
									if(tries == 100)
										break;
								}
								if(tries == 100)
								{
									SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Centrala jest obecnie obci¹¿ona - nie uda³o siê wybraæ trasy !");
									return 1;
								}
								gTrashDriverOnDuty[playerid] = 1;
								gTrashDriverSelectedLine[playerid] = rand;
								gTrashDriverJustStarted[playerid] = 1;
								format( string, sizeof(string), "[INFO:] Jedziesz tras¹ nr %d", rand );
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Udaj siê do pierwszego przystanku zaznaczonego na mapce.");
							}
							else if( IsPlayerInDynamicArea(playerid, gADilimore) )
							{
								new rand = random(50);
								new tries = 0;
								while( !gTrashTrackEnabled[rand] || gTrashTrackStartArea[rand] != 7 )
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
								gTrashDriverOnDuty[playerid] = 1;
								gTrashDriverSelectedLine[playerid] = rand;
								gTrashDriverJustStarted[playerid] = 1;
								format( string, sizeof(string), "[INFO:] Jedziesz tras¹ nr %d", rand );
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Udaj siê do pierwszego przystanku zaznaczonego na mapce.");
							}
							else if(IsPlayerInDynamicArea(playerid, gAFortCarson))
							{
								new rand = random(50);
								new tries = 0;
								while( !gTrashTrackEnabled[rand] || gTrashTrackStartArea[rand] != 8 )
								{
									rand = random(50);
									tries++;
									if( tries == 100 )
										break;
								}
								if(tries == 100)
								{
									SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Centrala jest obecnie obci¹¿ona - nie uda³o siê wybraæ trasy !");
									return 1;
								}
								gTrashDriverOnDuty[playerid] = 1;
								gTrashDriverSelectedLine[playerid] = rand;
								gTrashDriverJustStarted[playerid] = 1;
								format( string, sizeof(string), "[INFO:] Jedziesz tras¹ nr %d", rand );
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Udaj siê do pierwszego przystanku zaznaczonego na mapce.");
							}
							else if(IsPlayerInDynamicArea(playerid, gALosSantos3))
							{
								new rand = random(50);
								new tries = 0;
								while(!gTrashTrackEnabled[rand] || gTrashTrackStartArea[rand] != 9)
								{
									rand = random(50);
									tries++;
									if( tries == 100 )
										break;
								}
								if(tries == 100)
								{
									SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Centrala jest obecnie obci¹¿ona - nie uda³o siê wybraæ trasy !");
									return 1;
								}
								gTrashDriverOnDuty[playerid] = 1;
								gTrashDriverSelectedLine[playerid] = rand;
								gTrashDriverJustStarted[playerid] = 1;
								format(string, sizeof(string), "[INFO:] Jedziesz tras¹ nr %d", rand);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Udaj siê do pierwszego przystanku zaznaczonego na mapce.");
							}
							else if(IsPlayerInDynamicArea(playerid, gALosSantos4))
							{
								new rand = random(50);
								new tries = 0;
								while(!gTrashTrackEnabled[rand] || gTrashTrackStartArea[rand] != 10)
								{
									rand = random(50);
									tries++;
									if( tries == 100 )
										break;
								}
								if(tries == 100)
								{
									SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Centrala jest obecnie obci¹¿ona - nie uda³o siê wybraæ trasy !");
									return 1;
								}
								gTrashDriverOnDuty[playerid] = 1;
								gTrashDriverSelectedLine[playerid] = rand;
								gTrashDriverJustStarted[playerid] = 1;
								format(string, sizeof(string), "[INFO:] Jedziesz tras¹ nr %d", rand);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Udaj siê do pierwszego przystanku zaznaczonego na mapce.");
							}
							else if(IsPlayerInDynamicArea(playerid, gALosSantos5))
							{
								new rand = random(50);
								new tries = 0;
								while(!gTrashTrackEnabled[rand] || gTrashTrackStartArea[rand] != 11)
								{
									rand = random(50);
									tries++;
									if( tries == 100 )
										break;
								}
								if(tries == 100)
								{
									SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Centrala jest obecnie obci¹¿ona - nie uda³o siê wybraæ trasy !");
									return 1;
								}
								gTrashDriverOnDuty[playerid] = 1;
								gTrashDriverSelectedLine[playerid] = rand;
								gTrashDriverJustStarted[playerid] = 1;
								format(string, sizeof(string), "[INFO:] Jedziesz tras¹ nr %d", rand);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Udaj siê do pierwszego przystanku zaznaczonego na mapce.");
							}
							else if(IsPlayerInDynamicArea(playerid, gALosSantos6))
							{
								new rand = random(50);
								new tries = 0;
								while(!gTrashTrackEnabled[rand] || gTrashTrackStartArea[rand] != 12)
								{
									rand = random(50);
									tries++;
									if( tries == 100 )
										break;
								}
								if(tries == 100)
								{
									SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Centrala jest obecnie obci¹¿ona - nie uda³o siê wybraæ trasy !");
									return 1;
								}
								gTrashDriverOnDuty[playerid] = 1;
								gTrashDriverSelectedLine[playerid] = rand;
								gTrashDriverJustStarted[playerid] = 1;
								format(string, sizeof(string), "[INFO:] Jedziesz tras¹ nr %d", rand);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Udaj siê do pierwszego przystanku zaznaczonego na mapce.");
							}
							else if(IsPlayerInDynamicArea(playerid, gALosSantos7))
							{
								new rand = random(50);
								new tries = 0;
								while(!gTrashTrackEnabled[rand] || gTrashTrackStartArea[rand] != 13)
								{
									rand = random(50);
									tries++;
									if( tries == 100 )
										break;
								}
								if(tries == 100)
								{
									SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Centrala jest obecnie obci¹¿ona - nie uda³o siê wybraæ trasy !");
									return 1;
								}
								gTrashDriverOnDuty[playerid] = 1;
								gTrashDriverSelectedLine[playerid] = rand;
								gTrashDriverJustStarted[playerid] = 1;
								format(string, sizeof(string), "[INFO:] Jedziesz tras¹ nr %d", rand);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Udaj siê do pierwszego przystanku zaznaczonego na mapce.");
							}
							else if(IsPlayerInDynamicArea(playerid, gALosSantos8))
							{
								new rand = random(50);
								new tries = 0;
								while(!gTrashTrackEnabled[rand] || gTrashTrackStartArea[rand] != 15)
								{
									rand = random(50);
									tries++;
									if( tries == 100 )
										break;
								}
								if(tries == 100)
								{
									SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Centrala jest obecnie obci¹¿ona - nie uda³o siê wybraæ trasy !");
									return 1;
								}
								gTrashDriverOnDuty[playerid] = 1;
								gTrashDriverSelectedLine[playerid] = rand;
								gTrashDriverJustStarted[playerid] = 1;
								format(string, sizeof(string), "[INFO:] Jedziesz tras¹ nr %d", rand);
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
				else
				{
					if(EnteredVehicleID[playerid] != GetPlayerVehicleID(playerid))
					{
						ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Wróæ do pojazdu, w którym zacz¹³eœ prace aby j¹ kontynuuowaæ.", "Zamknij", "");
					}
					else
					{
						gTrashDriverResetTime[playerid] = 0;
						
						SetProgressBarValue(JobProgress[playerid], gPlayerData[playerid][pMzgkJobPoints]);
						UpdateProgressBar(JobProgress[playerid], playerid);
						
						SetPlayerCheckpoint(playerid, gTrashTrackCpX[gTrashDriverSelectedLine[playerid]][gTrashDriverCurrentCheckPoint[playerid]], gTrashTrackCpY[gTrashDriverSelectedLine[playerid]][gTrashDriverCurrentCheckPoint[playerid]], gTrashTrackCpZ[gTrashDriverSelectedLine[playerid]][gTrashDriverCurrentCheckPoint[playerid]], 5.0);
					}
				}
			}
		}
		
		// Sweeper vehicle
		else if(gVehData[vehicleidd][mVehType] == 5)
		{
			if(gSweeperDriverIsPassenger[playerid] == 0 && gPlayerData[playerid][pJob] == JOB_SWEEPER)
			{
				if(gSweeperDriverOnDuty[playerid] == 0)
				{
					if(gVehData[vehicleidd][CarFuel] < 5.0)
					{
						gVehData[vehicleidd][CarFuel] = 5.0;
						SaveVehData( vehicleidd, "CarFuel" );
					}
					
					SetProgressBarValue(JobProgress[playerid], gPlayerData[playerid][pSweeperJobPoints]);
					UpdateProgressBar(JobProgress[playerid], playerid);
					
					EnteredVehicleID[playerid] = vehicleid;
					
					GetVehicleHealth(vehicleid, vhealth);
					
					if(vhealth <= 700.0)
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Pojazd jest uszkodzony, udaj siê do mechanika lub zadzwon pod 555");
					}
					else
					{
						if(gVehData[vehicleidd][CarFuel] < 20.0)
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Pojazd ma ma³o paliwa, udaj siê na jedn¹ ze stacji benzynowych i zatankuj go");
						else
						{
							if(IsPlayerInDynamicArea(playerid, gASanFierro))
							{
								new rand = random(50);
								new tries = 0;
								while(!gSweeperTrackEnabled[rand] || gSweeperTrackStartArea[rand] != 0)
								{
									rand = random(50);
									tries++;
									if( tries == 100 )
										break;
								}
								if(tries == 100)
								{
									SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Centrala jest obecnie obci¹¿ona - nie uda³o siê wybraæ trasy !");
									return 1;
								}
								gSweeperDriverOnDuty[playerid] = 1;
								gSweeperDriverSelectedLine[playerid] = rand;
								gSweeperDriverJustStarted[playerid] = 1;
								format( string, sizeof(string), "[INFO:] Jedziesz tras¹ nr %d", rand );
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Udaj siê do pierwszego punktu zaznaczonego na mapce");
							}
							else if(IsPlayerInDynamicArea(playerid, gAAngelPine))
							{
								new rand = random(50);
								new tries = 0;
								while(!gSweeperTrackEnabled[rand] || gSweeperTrackStartArea[rand] != 3)
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
								gSweeperDriverOnDuty[playerid] = 1;
								gSweeperDriverSelectedLine[playerid] = rand;
								gSweeperDriverJustStarted[playerid] = 1;
								format( string, sizeof(string), "[INFO:] Jedziesz tras¹ nr %d", rand );
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Udaj siê do pierwszego przystanku zaznaczonego na mapce.");
							}
							else if(IsPlayerInDynamicArea(playerid, gALosSantos1))
							{
								new rand = random(50);
								new tries = 0;
								while(!gSweeperTrackEnabled[rand] || gSweeperTrackStartArea[rand] != 1)
								{
									rand = random(50);
									tries++;
									if( tries == 100 )
										break;
								}
								if(tries == 100)
								{
									SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Centrala jest obecnie obci¹¿ona - nie uda³o siê wybraæ trasy !");
									return 1;
								}
								gSweeperDriverOnDuty[playerid] = 1;
								gSweeperDriverSelectedLine[playerid] = rand;
								gSweeperDriverJustStarted[playerid] = 1;
								format(string, sizeof(string), "[INFO:] Jedziesz tras¹ nr %d", rand);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Udaj siê do pierwszego przystanku zaznaczonego na mapce.");
							}
							else if(IsPlayerInDynamicArea(playerid, gALosSantos2))
							{
								new rand = random(50);
								new tries = 0;
								while(!gSweeperTrackEnabled[rand] || gSweeperTrackStartArea[rand] != 2)
								{
									rand = random(50);
									tries++;
									if( tries == 100 )
										break;
								}
								if(tries == 100)
								{
									SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Centrala jest obecnie obci¹¿ona - nie uda³o siê wybraæ trasy !");
									return 1;
								}
								gSweeperDriverOnDuty[playerid] = 1;
								gSweeperDriverSelectedLine[playerid] = rand;
								gSweeperDriverJustStarted[playerid] = 1;
								format( string, sizeof(string), "[INFO:] Jedziesz tras¹ nr %d", rand );
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Udaj siê do pierwszego przystanku zaznaczonego na mapce.");
							}
							else if(IsPlayerInDynamicArea(playerid, gAMontgomery))
							{
								new rand = random(50);
								new tries = 0;
								while( !gSweeperTrackEnabled[rand] || gSweeperTrackStartArea[rand] != 4 )
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
								gSweeperDriverOnDuty[playerid] = 1;
								gSweeperDriverSelectedLine[playerid] = rand;
								gSweeperDriverJustStarted[playerid] = 1;
								format( string, sizeof(string), "[INFO:] Jedziesz tras¹ nr %d", rand );
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Udaj siê do pierwszego przystanku zaznaczonego na mapce.");
							}
							else if(IsPlayerInDynamicArea(playerid, gAPalominoCreek))
							{
								new rand = random(50);
								new tries = 0;
								while( !gSweeperTrackEnabled[rand] || gSweeperTrackStartArea[rand] != 5 )
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
								gSweeperDriverOnDuty[playerid] = 1;
								gSweeperDriverSelectedLine[playerid] = rand;
								gSweeperDriverJustStarted[playerid] = 1;
								format( string, sizeof(string), "[INFO:] Jedziesz tras¹ nr %d", rand );
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Udaj siê do pierwszego przystanku zaznaczonego na mapce.");
							}
							else if(IsPlayerInDynamicArea(playerid, gABountyBay))
							{
								new rand = random(50);
								new tries = 0;
								while(!gSweeperTrackEnabled[rand] || gSweeperTrackStartArea[rand] != 6)
								{
									rand = random(50);
									tries++;
									if(tries == 100)
										break;
								}
								if(tries == 100)
								{
									SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Centrala jest obecnie obci¹¿ona - nie uda³o siê wybraæ trasy !");
									return 1;
								}
								gSweeperDriverOnDuty[playerid] = 1;
								gSweeperDriverSelectedLine[playerid] = rand;
								gSweeperDriverJustStarted[playerid] = 1;
								format( string, sizeof(string), "[INFO:] Jedziesz tras¹ nr %d", rand );
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Udaj siê do pierwszego przystanku zaznaczonego na mapce.");
							}
							else if( IsPlayerInDynamicArea(playerid, gADilimore) )
							{
								new rand = random(50);
								new tries = 0;
								while( !gSweeperTrackEnabled[rand] || gSweeperTrackStartArea[rand] != 7 )
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
								gSweeperDriverOnDuty[playerid] = 1;
								gSweeperDriverSelectedLine[playerid] = rand;
								gSweeperDriverJustStarted[playerid] = 1;
								format( string, sizeof(string), "[INFO:] Jedziesz tras¹ nr %d", rand );
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Udaj siê do pierwszego przystanku zaznaczonego na mapce.");
							}
							else if(IsPlayerInDynamicArea(playerid, gAFortCarson))
							{
								new rand = random(50);
								new tries = 0;
								while( !gSweeperTrackEnabled[rand] || gSweeperTrackStartArea[rand] != 8 )
								{
									rand = random(50);
									tries++;
									if( tries == 100 )
										break;
								}
								if(tries == 100)
								{
									SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Centrala jest obecnie obci¹¿ona - nie uda³o siê wybraæ trasy !");
									return 1;
								}
								gSweeperDriverOnDuty[playerid] = 1;
								gSweeperDriverSelectedLine[playerid] = rand;
								gSweeperDriverJustStarted[playerid] = 1;
								format( string, sizeof(string), "[INFO:] Jedziesz tras¹ nr %d", rand );
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Udaj siê do pierwszego przystanku zaznaczonego na mapce.");
							}
							else if(IsPlayerInDynamicArea(playerid, gALosSantos3))
							{
								new rand = random(50);
								new tries = 0;
								while(!gSweeperTrackEnabled[rand] || gSweeperTrackStartArea[rand] != 9)
								{
									rand = random(50);
									tries++;
									if( tries == 100 )
										break;
								}
								if(tries == 100)
								{
									SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Centrala jest obecnie obci¹¿ona - nie uda³o siê wybraæ trasy !");
									return 1;
								}
								gSweeperDriverOnDuty[playerid] = 1;
								gSweeperDriverSelectedLine[playerid] = rand;
								gSweeperDriverJustStarted[playerid] = 1;
								format(string, sizeof(string), "[INFO:] Jedziesz tras¹ nr %d", rand);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Udaj siê do pierwszego przystanku zaznaczonego na mapce.");
							}
							else if(IsPlayerInDynamicArea(playerid, gALosSantos4))
							{
								new rand = random(50);
								new tries = 0;
								while(!gSweeperTrackEnabled[rand] || gSweeperTrackStartArea[rand] != 10)
								{
									rand = random(50);
									tries++;
									if( tries == 100 )
										break;
								}
								if(tries == 100)
								{
									SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Centrala jest obecnie obci¹¿ona - nie uda³o siê wybraæ trasy !");
									return 1;
								}
								gSweeperDriverOnDuty[playerid] = 1;
								gSweeperDriverSelectedLine[playerid] = rand;
								gSweeperDriverJustStarted[playerid] = 1;
								format(string, sizeof(string), "[INFO:] Jedziesz tras¹ nr %d", rand);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Udaj siê do pierwszego przystanku zaznaczonego na mapce.");
							}
							else if(IsPlayerInDynamicArea(playerid, gALosSantos5))
							{
								new rand = random(50);
								new tries = 0;
								while(!gSweeperTrackEnabled[rand] || gSweeperTrackStartArea[rand] != 11)
								{
									rand = random(50);
									tries++;
									if( tries == 100 )
										break;
								}
								if(tries == 100)
								{
									SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Centrala jest obecnie obci¹¿ona - nie uda³o siê wybraæ trasy !");
									return 1;
								}
								gSweeperDriverOnDuty[playerid] = 1;
								gSweeperDriverSelectedLine[playerid] = rand;
								gSweeperDriverJustStarted[playerid] = 1;
								format(string, sizeof(string), "[INFO:] Jedziesz tras¹ nr %d", rand);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Udaj siê do pierwszego przystanku zaznaczonego na mapce.");
							}
							else if(IsPlayerInDynamicArea(playerid, gALosSantos6))
							{
								new rand = random(50);
								new tries = 0;
								while(!gSweeperTrackEnabled[rand] || gSweeperTrackStartArea[rand] != 12)
								{
									rand = random(50);
									tries++;
									if( tries == 100 )
										break;
								}
								if(tries == 100)
								{
									SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Centrala jest obecnie obci¹¿ona - nie uda³o siê wybraæ trasy !");
									return 1;
								}
								gSweeperDriverOnDuty[playerid] = 1;
								gSweeperDriverSelectedLine[playerid] = rand;
								gSweeperDriverJustStarted[playerid] = 1;
								format(string, sizeof(string), "[INFO:] Jedziesz tras¹ nr %d", rand);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Udaj siê do pierwszego przystanku zaznaczonego na mapce.");
							}
							else if(IsPlayerInDynamicArea(playerid, gALosSantos7))
							{
								new rand = random(50);
								new tries = 0;
								while(!gSweeperTrackEnabled[rand] || gSweeperTrackStartArea[rand] != 13)
								{
									rand = random(50);
									tries++;
									if( tries == 100 )
										break;
								}
								if(tries == 100)
								{
									SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Centrala jest obecnie obci¹¿ona - nie uda³o siê wybraæ trasy !");
									return 1;
								}
								gSweeperDriverOnDuty[playerid] = 1;
								gSweeperDriverSelectedLine[playerid] = rand;
								gSweeperDriverJustStarted[playerid] = 1;
								format(string, sizeof(string), "[INFO:] Jedziesz tras¹ nr %d", rand);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Udaj siê do pierwszego przystanku zaznaczonego na mapce.");
							}
							else if(IsPlayerInDynamicArea(playerid, gALosSantos8))
							{
								new rand = random(50);
								new tries = 0;
								while(!gSweeperTrackEnabled[rand] || gSweeperTrackStartArea[rand] != 15)
								{
									rand = random(50);
									tries++;
									if( tries == 100 )
										break;
								}
								if(tries == 100)
								{
									SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Centrala jest obecnie obci¹¿ona - nie uda³o siê wybraæ trasy !");
									return 1;
								}
								gSweeperDriverOnDuty[playerid] = 1;
								gSweeperDriverSelectedLine[playerid] = rand;
								gSweeperDriverJustStarted[playerid] = 1;
								format(string, sizeof(string), "[INFO:] Jedziesz tras¹ nr %d", rand);
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
				else
				{
					if(EnteredVehicleID[playerid] != GetPlayerVehicleID(playerid))
					{
						ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Wróæ do pojazdu, w którym zacz¹³eœ prace aby j¹ kontynuuowaæ.", "Zamknij", "");
					}
					else
					{
						gSweeperDriverResetTime[playerid] = 0;
						
						SetProgressBarValue(JobProgress[playerid], gPlayerData[playerid][pSweeperJobPoints]);
						UpdateProgressBar(JobProgress[playerid], playerid);
						
						SetPlayerCheckpoint(playerid, gSweeperTrackCpX[gSweeperDriverSelectedLine[playerid]][gSweeperDriverCurrentCheckPoint[playerid]], gSweeperTrackCpY[gSweeperDriverSelectedLine[playerid]][gSweeperDriverCurrentCheckPoint[playerid]], gSweeperTrackCpZ[gSweeperDriverSelectedLine[playerid]][gSweeperDriverCurrentCheckPoint[playerid]], 5.0);
					}
				}
			}
		}		
		
		// Farmer vehicle
		else if(gVehData[vehicleidd][mVehType] == 11)
		{
			if(gFarmerDriverIsPassenger[playerid] == 0 && gPlayerData[playerid][pJob] == JOB_FARMER)
			{
				if(gFarmerDriverOnDuty[playerid] == 0)
				{
					if(gVehData[vehicleidd][CarFuel] < 5.0)
					{
						gVehData[vehicleidd][CarFuel] = 5.0;
						SaveVehData( vehicleidd, "CarFuel" );
					}
					
					SetProgressBarValue(JobProgress[playerid], gPlayerData[playerid][pFarmerJobPoints]);
					UpdateProgressBar(JobProgress[playerid], playerid);
					
					EnteredVehicleID[playerid] = vehicleid;
					
					GetVehicleHealth(vehicleid, vhealth);
					
					if(vhealth <= 700.0)
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Pojazd jest uszkodzony, udaj siê do mechanika lub zadzwon pod 555");
					}
					else
					{
						if(gVehData[vehicleidd][CarFuel] < 20.0)
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Pojazd ma ma³o paliwa, udaj siê na jedn¹ ze stacji benzynowych i zatankuj go");
						}
						else
						{
							if(IsPlayerInDynamicArea(playerid, gASanFierro))
							{
								new rand = random(50);
								new tries = 0;
								while(!gFarmerTrackEnabled[rand] || gFarmerTrackStartArea[rand] != 0)
								{
									rand = random(50);
									tries++;
									if( tries == 100 )
										break;
								}
								if(tries == 100)
								{
									SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Centrala jest obecnie obci¹¿ona - nie uda³o siê wybraæ trasy !");
									return 1;
								}
								gFarmerDriverOnDuty[playerid] = 1;
								gFarmerDriverSelectedLine[playerid] = rand;
								gFarmerDriverJustStarted[playerid] = 1;
								format( string, sizeof(string), "[INFO:] Jedziesz tras¹ nr %d", rand );
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Udaj siê do pierwszego punktu zaznaczonego na mapce");
							}
							else if(IsPlayerInDynamicArea(playerid, gAAngelPine))
							{
								new rand = random(50);
								new tries = 0;
								while(!gFarmerTrackEnabled[rand] || gFarmerTrackStartArea[rand] != 3)
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
								gFarmerDriverOnDuty[playerid] = 1;
								gFarmerDriverSelectedLine[playerid] = rand;
								gFarmerDriverJustStarted[playerid] = 1;
								format( string, sizeof(string), "[INFO:] Jedziesz tras¹ nr %d", rand );
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Udaj siê do pierwszego przystanku zaznaczonego na mapce.");
							}
							else if(IsPlayerInDynamicArea(playerid, gALosSantos1))
							{
								new rand = random(50);
								new tries = 0;
								while(!gFarmerTrackEnabled[rand] || gFarmerTrackStartArea[rand] != 1)
								{
									rand = random(50);
									tries++;
									if( tries == 100 )
										break;
								}
								if(tries == 100)
								{
									SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Centrala jest obecnie obci¹¿ona - nie uda³o siê wybraæ trasy !");
									return 1;
								}
								gFarmerDriverOnDuty[playerid] = 1;
								gFarmerDriverSelectedLine[playerid] = rand;
								gFarmerDriverJustStarted[playerid] = 1;
								format(string, sizeof(string), "[INFO:] Jedziesz tras¹ nr %d", rand);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Udaj siê do pierwszego przystanku zaznaczonego na mapce.");
							}
							else if(IsPlayerInDynamicArea(playerid, gALosSantos2))
							{
								new rand = random(50);
								new tries = 0;
								while(!gFarmerTrackEnabled[rand] || gFarmerTrackStartArea[rand] != 2)
								{
									rand = random(50);
									tries++;
									if( tries == 100 )
										break;
								}
								if(tries == 100)
								{
									SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Centrala jest obecnie obci¹¿ona - nie uda³o siê wybraæ trasy !");
									return 1;
								}
								gFarmerDriverOnDuty[playerid] = 1;
								gFarmerDriverSelectedLine[playerid] = rand;
								gFarmerDriverJustStarted[playerid] = 1;
								format( string, sizeof(string), "[INFO:] Jedziesz tras¹ nr %d", rand );
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Udaj siê do pierwszego przystanku zaznaczonego na mapce.");
							}
							else if(IsPlayerInDynamicArea(playerid, gAMontgomery))
							{
								new rand = random(50);
								new tries = 0;
								while( !gFarmerTrackEnabled[rand] || gFarmerTrackStartArea[rand] != 4 )
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
								gFarmerDriverOnDuty[playerid] = 1;
								gFarmerDriverSelectedLine[playerid] = rand;
								gFarmerDriverJustStarted[playerid] = 1;
								format( string, sizeof(string), "[INFO:] Jedziesz tras¹ nr %d", rand );
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Udaj siê do pierwszego przystanku zaznaczonego na mapce.");
							}
							else if(IsPlayerInDynamicArea(playerid, gAPalominoCreek))
							{
								new rand = random(50);
								new tries = 0;
								while( !gFarmerTrackEnabled[rand] || gFarmerTrackStartArea[rand] != 5 )
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
								gFarmerDriverOnDuty[playerid] = 1;
								gFarmerDriverSelectedLine[playerid] = rand;
								gFarmerDriverJustStarted[playerid] = 1;
								format( string, sizeof(string), "[INFO:] Jedziesz tras¹ nr %d", rand );
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Udaj siê do pierwszego przystanku zaznaczonego na mapce.");
							}
							else if(IsPlayerInDynamicArea(playerid, gABountyBay))
							{
								new rand = random(50);
								new tries = 0;
								while(!gFarmerTrackEnabled[rand] || gFarmerTrackStartArea[rand] != 6)
								{
									rand = random(50);
									tries++;
									if(tries == 100)
										break;
								}
								if(tries == 100)
								{
									SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Centrala jest obecnie obci¹¿ona - nie uda³o siê wybraæ trasy !");
									return 1;
								}
								gFarmerDriverOnDuty[playerid] = 1;
								gFarmerDriverSelectedLine[playerid] = rand;
								gFarmerDriverJustStarted[playerid] = 1;
								format( string, sizeof(string), "[INFO:] Jedziesz tras¹ nr %d", rand );
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Udaj siê do pierwszego przystanku zaznaczonego na mapce.");
							}
							else if( IsPlayerInDynamicArea(playerid, gADilimore) )
							{
								new rand = random(50);
								new tries = 0;
								while( !gFarmerTrackEnabled[rand] || gFarmerTrackStartArea[rand] != 7 )
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
								gFarmerDriverOnDuty[playerid] = 1;
								gFarmerDriverSelectedLine[playerid] = rand;
								gFarmerDriverJustStarted[playerid] = 1;
								format( string, sizeof(string), "[INFO:] Jedziesz tras¹ nr %d", rand );
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Udaj siê do pierwszego przystanku zaznaczonego na mapce.");
							}
							else if(IsPlayerInDynamicArea(playerid, gAFortCarson))
							{
								new rand = random(50);
								new tries = 0;
								while( !gFarmerTrackEnabled[rand] || gFarmerTrackStartArea[rand] != 8 )
								{
									rand = random(50);
									tries++;
									if( tries == 100 )
										break;
								}
								if(tries == 100)
								{
									SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Centrala jest obecnie obci¹¿ona - nie uda³o siê wybraæ trasy !");
									return 1;
								}
								gFarmerDriverOnDuty[playerid] = 1;
								gFarmerDriverSelectedLine[playerid] = rand;
								gFarmerDriverJustStarted[playerid] = 1;
								format( string, sizeof(string), "[INFO:] Jedziesz tras¹ nr %d", rand );
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Udaj siê do pierwszego przystanku zaznaczonego na mapce.");
							}
							else if(IsPlayerInDynamicArea(playerid, gABlueBerryFarm))
							{
								new rand = random(50);
								new tries = 0;
								while( !gFarmerTrackEnabled[rand] || gFarmerTrackStartArea[rand] != 14 )
								{
									rand = random(50);
									tries++;
									if( tries == 100 )
										break;
								}
								if(tries == 100)
								{
									SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Centrala jest obecnie obci¹¿ona - nie uda³o siê wybraæ trasy !");
									return 1;
								}
								gFarmerDriverOnDuty[playerid] = 1;
								gFarmerDriverSelectedLine[playerid] = rand;
								gFarmerDriverJustStarted[playerid] = 1;
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
				else
				{
					if(EnteredVehicleID[playerid] != GetPlayerVehicleID(playerid))
					{
						ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Wróæ do pojazdu, w którym zacz¹³eœ prace aby j¹ kontynuuowaæ.", "Zamknij", "");
					}
					else
					{
						gFarmerDriverResetTime[playerid] = 0;
						
						SetProgressBarValue(JobProgress[playerid], gPlayerData[playerid][pFarmerJobPoints]);
						UpdateProgressBar(JobProgress[playerid], playerid);
						
						SetPlayerCheckpoint(playerid, gFarmerTrackCpX[gFarmerDriverSelectedLine[playerid]][gFarmerDriverCurrentCheckPoint[playerid]], gFarmerTrackCpY[gFarmerDriverSelectedLine[playerid]][gFarmerDriverCurrentCheckPoint[playerid]], gFarmerTrackCpZ[gFarmerDriverSelectedLine[playerid]][gFarmerDriverCurrentCheckPoint[playerid]], 5.0);
					}
				}
			}
		}
		
		// Boat
		else if(gVehData[vehicleidd][mVehType] == 6)
		{
			if(TakingBoatTest[playerid])
			{
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] Musisz przejechaæ przez wszystkie zaznaczone punkty nie uszkadzaj¹c ³odzi.");
				if(BoatTestStep[playerid] == 0)
				{
					gVehData[GetPlayerVehicleID(playerid)-1][CarFuel] = float(VehFTank(GetPlayerVehicleID(playerid)));
			 		// SetPlayerCheckpoint(playerid, -3022.5170898438, 643.09497070313, 0.17990136146545, 5.0);
			 		SetPlayerCheckpoint(playerid, 2946.493, -2026.393, -0.338, 5.0);
					BoatTestStep[playerid] = 1;
				}
	   		}
			else if(!TakingBoatTest[playerid] && !AdminDuty[playerid])
			{
				RemoveDriverFromVehicle(playerid);
				TogglePlayerControllable(playerid,1);
			}
		}
	}
	else if(newstate == PLAYER_STATE_ONFOOT)
	{
		/*
		* Change spectate camera when player exits vehicle
		*/
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
		
		/*
		* Check if radio was on if it was set it to stop
		*/
		if(CarRadioID[playerid] != 255)
		{
			// Audio_Stop(playerid, CarRadioID[playerid]);
			StopAudioStreamForPlayer(playerid);
			CarRadioID[playerid] = 255;
		}
		
		
		/*
		* If player was in work vehicle (ex. bus) it showed progress bar of work which is now need to be hide.
		*/
		HideProgressBarForPlayer(playerid, JobProgress[playerid]);
		
		
		/*
		* Set player status after exiting work vehicle (ex. bus) and give him for ex. payment.
		* Reset olso vehicle data if necessary.
		*/
		// Bus vehicle
		if(gBusDriverOnDuty[playerid])
		{
			if(gBusDriverIsPassenger[playerid] == 0)
			{
				DisablePlayerCheckpoint(playerid);
				
				gBusDriverResetTime[playerid] = 2*60;
			}
			else
			{
				gBusDriverIsPassenger[playerid] = 0;
			}
		}
		
		// Trash vehicle
		else if(gTrashDriverOnDuty[playerid])
		{
			if(gTrashDriverIsPassenger[playerid] == 0)
			{
				DisablePlayerCheckpoint(playerid);
			
				gTrashDriverResetTime[playerid] = 2*60;
			}
			else
			{
				gTrashDriverIsPassenger[playerid] = 0;
			}
		}
		
		// Sweeper vehicle
		else if(gSweeperDriverOnDuty[playerid])
		{
			if(gSweeperDriverIsPassenger[playerid] == 0)
			{
				DisablePlayerCheckpoint(playerid);
			
				gSweeperDriverResetTime[playerid] = 2*60;
			}
			else
			{
				gSweeperDriverIsPassenger[playerid] = 0;
			}
		}
		
		// Combine vehicle
		else if(gFarmerDriverOnDuty[playerid])
		{
			if(gFarmerDriverIsPassenger[playerid] == 0)
			{
				DisablePlayerCheckpoint(playerid);
			
				gFarmerDriverResetTime[playerid] = 2*60;
			}
			else
			{
				gFarmerDriverIsPassenger[playerid] = 0;
			}
		}
	}
	
	return 1;
} // end of OnPlayerStateChange

public OnPlayerEnterCheckpoint(playerid)
{
	new updatedvehicleid;
	new Float:health;
	new veh;
	if(IsPlayerInAnyVehicle(playerid))
	{
		updatedvehicleid = GetPlayerVehicleID(playerid) - 1;
		if(gVehData[updatedvehicleid][mVehType] == 6)
		{
			if(TakingBoatTest[playerid] == 1)
			{
				// if(PlayerToPoint(5.0,playerid,-3022.5170898438, 643.09497070313, -1.07990136146545) && BoatTestStep[playerid] == 1)
				// {
					// BoatTestStep[playerid] = 2;
					// SetPlayerCheckpoint(playerid, -2876.5407714844, 1279.0272216797, 0.60156440734863, 5.0);
				// }
				// else if(PlayerToPoint(5.0,playerid,-2876.5407714844, 1279.0272216797, 0.60156440734863) && BoatTestStep[playerid] == 2)
				// {
					// BoatTestStep[playerid] = 3;
					// SetPlayerCheckpoint(playerid, -2026.0700683594, 1354.3315429688, 1, 5.0);
				// }
				// else if(PlayerToPoint(5.0,playerid,-2026.0700683594, 1354.3315429688, 1) && BoatTestStep[playerid] == 3)
				// {
					// BoatTestStep[playerid] = 4;
					// SetPlayerCheckpoint(playerid, -1706.5493164063, 1423.0377197266, 1, 5.0);
				// }
				// else if(PlayerToPoint(5.0,playerid,-1706.5493164063, 1423.0377197266, 1) && BoatTestStep[playerid] == 4)
				// {
					// BoatTestStep[playerid] = 5;
					// SetPlayerCheckpoint(playerid, -1575.3315429688, 1252.4403076172, 1, 5.0);
				// }
				// else if(PlayerToPoint(5.0,playerid,-1575.3315429688, 1252.4403076172, 1) && BoatTestStep[playerid] == 5)
				// {
					// BoatTestStep[playerid] = 6;
					// SetPlayerCheckpoint(playerid, -1491.6618652344, 1046.6130371094, 1, 5.0);
				// }
				// else if(PlayerToPoint(5.0,playerid,-1491.6618652344, 1046.6130371094, 1) && BoatTestStep[playerid] == 6)
				// {
					// BoatTestStep[playerid] = 7;
					// SetPlayerCheckpoint(playerid, -999.33776855469, 945.65710449219, 1, 5.0);
				// }
				// else if(PlayerToPoint(5.0,playerid,-999.33776855469, 945.65710449219, 1) && BoatTestStep[playerid] == 7)
				// {
					// BoatTestStep[playerid] = 8;
					// SetPlayerCheckpoint(playerid, -1068.4488525391, 907.58959960938, 1, 5.0);
				// }
				// else if(PlayerToPoint(5.0,playerid,-1068.4488525391, 907.58959960938, 1) && BoatTestStep[playerid] == 8)
				// {
					// BoatTestStep[playerid] = 9;
					// SetPlayerCheckpoint(playerid, -1250.6879882813, 777.51892089844, 1, 5.0);
				// }
				// else if(PlayerToPoint(5.0,playerid,-1250.6879882813, 777.51892089844, 1) && BoatTestStep[playerid] == 9)
				// {
					// BoatTestStep[playerid] = 10;
					// SetPlayerCheckpoint(playerid, -1476.3942871094, 614.28118896484, 1, 5.0);
				// }
				// else if(PlayerToPoint(5.0,playerid,-1476.3942871094, 614.28118896484, 1) && BoatTestStep[playerid] == 10)
				// {
					// BoatTestStep[playerid] = 11;
					// SetPlayerCheckpoint(playerid, -1513.0865478516, 579.57153320313, 1, 5.0);
				// }
				// else if(PlayerToPoint(5.0,playerid,-1513.0865478516, 579.57153320313, 1) && BoatTestStep[playerid] == 11)
				// {
					// BoatTestStep[playerid] = 12;
					// SetPlayerCheckpoint(playerid, -978.84680175781, 494.06463623047, 1, 5.0);
				// }
				// else if(PlayerToPoint(5.0,playerid,-978.84680175781, 494.06463623047, 1) && BoatTestStep[playerid] == 12)
				// {
					// BoatTestStep[playerid] = 13;
					// SetPlayerCheckpoint(playerid, -987.51208496094, -295.291015625, 0.094693756104, 5.0);
				// }
				// else if(PlayerToPoint(5.0,playerid,-987.51208496094, -295.291015625, 0.094693756104) && BoatTestStep[playerid] == 13)
				// {
					// BoatTestStep[playerid] = 14;
					// SetPlayerCheckpoint(playerid, -78.485473632813, -909.97521972656, 1, 5.0);
				// }
				// else if(PlayerToPoint(5.0,playerid,-78.485473632813, -909.97521972656, 1) && BoatTestStep[playerid] == 14)
				// {
					// BoatTestStep[playerid] = 15;
					// SetPlayerCheckpoint(playerid, 44.898357391357, -1420.24609375, 1, 5.0);
				// }
				// else if(PlayerToPoint(5.0,playerid,44.898357391357, -1420.24609375, 1) && BoatTestStep[playerid] == 15)
				// {
					// BoatTestStep[playerid] = 16;
					// SetPlayerCheckpoint(playerid, -166.63638305664, -1683.7888183594, 1, 5.0);
				// }
				// else if(PlayerToPoint(5.0,playerid,-166.63638305664, -1683.7888183594, 1) && BoatTestStep[playerid] == 16)
				// {
					// BoatTestStep[playerid] = 17;
					// SetPlayerCheckpoint(playerid, -189.36061096191, -2026.7855224609, 0.36227989196777, 5.0);
				// }
				// else if(PlayerToPoint(5.0,playerid,-189.36061096191, -2026.7855224609, 0.36227989196777) && BoatTestStep[playerid] == 17)
				// {
					// BoatTestStep[playerid] = 18;
					// SetPlayerCheckpoint(playerid, 82.837532043457, -2733.0791015625, 4.6377983093262, 5.0);
				// }
				// else if(PlayerToPoint(5.0,playerid,82.837532043457, -2733.0791015625, 4.6377983093262) && BoatTestStep[playerid] == 18)
				// {
					// BoatTestStep[playerid] = 19;
					// SetPlayerCheckpoint(playerid, -590.40893554688, -2863.7443847656, 3.3844101428986, 5.0);
				// }
				// else if(PlayerToPoint(5.0,playerid,-590.40893554688, -2863.7443847656, 3.3844101428986) && BoatTestStep[playerid] == 19)
				// {
					// BoatTestStep[playerid] = 20;
					// SetPlayerCheckpoint(playerid, -1077.9144287109, -2852.6623535156, 0.72500026226044, 5.0);
				// }
				// else if(PlayerToPoint(5.0,playerid,-1077.9144287109, -2852.6623535156, 0.72500026226044) && BoatTestStep[playerid] == 20)
				// {
					// BoatTestStep[playerid] = 21;
					// SetPlayerCheckpoint(playerid, -1240.7104492188, -2498.2866210938, 0.87499970197678, 5.0);
				// }
				// else if(PlayerToPoint(5.0,playerid,-1240.7104492188, -2498.2866210938, 0.87499970197678) && BoatTestStep[playerid] == 21)
				// {
					// BoatTestStep[playerid] = 22;
					// SetPlayerCheckpoint(playerid, -1266.3760986328, -1886.3358154297, 0.91077101230621, 5.0);
				// }
				// else if(PlayerToPoint(5.0,playerid,-1266.3760986328, -1886.3358154297, 0.91077101230621) && BoatTestStep[playerid] == 22)
				// {
					// BoatTestStep[playerid] = 23;
					// SetPlayerCheckpoint(playerid, -2264.5275878906, -1003.3751831055, 0.85000014305115, 5.0);
				// }
				// else if(PlayerToPoint(5.0,playerid,-2264.5275878906, -1003.3751831055, 0.85000014305115) && BoatTestStep[playerid] == 23)
				// {
					// BoatTestStep[playerid] = 24;
					// SetPlayerCheckpoint(playerid, -2870.236328125, -943.46826171875, 0.72499996423721, 5.0);
				// }
				// else if(PlayerToPoint(5.0,playerid,-2870.236328125, -943.46826171875, 0.72499996423721) && BoatTestStep[playerid] == 24)
				// {
					// BoatTestStep[playerid] = 25;
					// SetPlayerCheckpoint(playerid, -2959.7275390625, 44.119316101074, 0.75000017881393, 5.0);
				// }
				// else if(PlayerToPoint(5.0,playerid,-2959.7275390625, 44.119316101074, 0.75000017881393) && BoatTestStep[playerid] == 25)
				// {
					// BoatTestStep[playerid] = 26;
					// SetPlayerCheckpoint(playerid, -2999.0258789063, 425.25250244141, 0.47500047087669, 5.0);
				// }
				// else if(PlayerToPoint(5.0,playerid,-2999.0258789063, 425.25250244141, 0.47500047087669) && BoatTestStep[playerid] == 26)
				// {
					// BoatTestStep[playerid] = 27;
					// SetPlayerCheckpoint(playerid, -2999.8190917969, 538.39569091797, 0.70000034570694, 5.0);
				// }
				// else if(PlayerToPoint(5.0,playerid,-2999.8190917969, 538.39569091797, 0.70000034570694) && BoatTestStep[playerid] == 27)
				// {
					// veh = GetPlayerVehicleID(playerid);
					// GetVehicleHealth(veh, health);
					// if(health >= 800.0)
					// {
						// SendClientMessage(playerid,COLOR_GREEN,"[INFO:] Utrzyma³eœ 80 procent sprawnoœci ³odzi ! Wynik pozytywny !");
						// gPlayerData[playerid][pBoatLic] = 1;
						// SavePlayerData(playerid, "BoatLic");
						// SetVehicleToRespawnEx(veh);
						// TakingBoatTest[playerid] = 0;
						// DisablePlayerCheckpoint(playerid);
					// }
					// else
					// {
						// SendClientMessage(playerid,COLOR_RED,"[INFO:] Obla³eœ test, mo¿e nastêpnym razem pójdzie Ci lepiej.");
						// SetVehicleToRespawnEx(veh);
						// TakingBoatTest[playerid] = 0;
						// DisablePlayerCheckpoint(playerid);
					// }
					// BoatTestStep[playerid] = 0;
				// }
				if(PlayerToPoint(10.0,playerid, 2946.493, -2026.393, -0.338) && BoatTestStep[playerid] == 1)
				{
					BoatTestStep[playerid] = 2;
					SetPlayerCheckpoint(playerid, 2976.889, -1901.246, -1.061, 10.0);
				}
				else if(PlayerToPoint(10.0,playerid, 2976.889, -1901.246, -1.061) && BoatTestStep[playerid] == 2)
				{
					BoatTestStep[playerid] = 3;
					SetPlayerCheckpoint(playerid, 2975.374, -1735.205, -0.757, 10.0);
				}
				else if(PlayerToPoint(10.0,playerid, 2975.374, -1735.205, -0.757) && BoatTestStep[playerid] == 3)
				{
					BoatTestStep[playerid] = 4;
					SetPlayerCheckpoint(playerid, 3012.247, -1665.405, -1.254, 10.0);
				}
				else if(PlayerToPoint(10.0,playerid, 3012.247, -1665.405, -1.254) && BoatTestStep[playerid] == 4)
				{
					BoatTestStep[playerid] = 5;
					SetPlayerCheckpoint(playerid, 3048.541, -1598.687, 0.133, 10.0);
				}
				else if(PlayerToPoint(10.0,playerid,3048.541, -1598.687, 0.133) && BoatTestStep[playerid] == 5)
				{
					BoatTestStep[playerid] = 6;
					SetPlayerCheckpoint(playerid, 3002.354, -1602.506, -0.380, 10.0);
				}
				else if(PlayerToPoint(10.0,playerid, 3002.354, -1602.506, -0.380) && BoatTestStep[playerid] == 6)
				{
					BoatTestStep[playerid] = 7;
					SetPlayerCheckpoint(playerid, 3106.025, -1637.901, -1.090, 10.0);
				}
				else if(PlayerToPoint(10.0,playerid, 3106.025, -1637.901, -1.090) && BoatTestStep[playerid] == 7)
				{
					BoatTestStep[playerid] = 8;
					SetPlayerCheckpoint(playerid, 3148.258, -1698.809, 0.219, 10.0);
				}
				else if(PlayerToPoint(10.0,playerid, 3148.258, -1698.809, 0.219) && BoatTestStep[playerid] == 8)
				{
					BoatTestStep[playerid] = 9;
					SetPlayerCheckpoint(playerid, 3135.347, -1776.297, -0.649, 10.0);
				}
				else if(PlayerToPoint(10.0,playerid, 3135.347, -1776.297, -0.649) && BoatTestStep[playerid] == 9)
				{
					BoatTestStep[playerid] = 10;
					SetPlayerCheckpoint(playerid, 3203.814, -1846.580, 0.059, 10.0);
				}
				else if(PlayerToPoint(10.0,playerid, 3203.814, -1846.580, 0.059) && BoatTestStep[playerid] == 10)
				{
					BoatTestStep[playerid] = 11;
					SetPlayerCheckpoint(playerid, 3232.814, -1955.911, -0.148, 10.0);
				}
				else if(PlayerToPoint(10.0,playerid, 3232.814, -1955.911, -0.148) && BoatTestStep[playerid] == 11)
				{
					BoatTestStep[playerid] = 12;
					SetPlayerCheckpoint(playerid, 3205.520, -2070.724, -1.092, 10.0);
				}
				else if(PlayerToPoint(10.0,playerid, 3205.520, -2070.724, -1.092) && BoatTestStep[playerid] == 12)
				{
					BoatTestStep[playerid] = 13;
					SetPlayerCheckpoint(playerid, 3184.654, -2132.924, -0.528, 10.0);
				}
				else if(PlayerToPoint(10.0,playerid, 3184.654, -2132.924, -0.528) && BoatTestStep[playerid] == 13)
				{
					BoatTestStep[playerid] = 14;
					SetPlayerCheckpoint(playerid, 3082.592, -2228.752, -0.765, 10.0);
				}
				else if(PlayerToPoint(10.0,playerid, 3082.592, -2228.752, -0.765) && BoatTestStep[playerid] == 14)
				{
					BoatTestStep[playerid] = 15;
					SetPlayerCheckpoint(playerid, 3070.606, -2324.769, -0.313, 10.0);
				}
				else if(PlayerToPoint(10.0,playerid, 3070.606, -2324.769, -0.313) && BoatTestStep[playerid] == 15)
				{
					BoatTestStep[playerid] = 16;
					SetPlayerCheckpoint(playerid, 3016.331, -2389.639, -0.507, 10.0);
				}
				else if(PlayerToPoint(10.0,playerid, 3016.331, -2389.639, -0.507) && BoatTestStep[playerid] == 16)
				{
					BoatTestStep[playerid] = 17;
					SetPlayerCheckpoint(playerid, 2975.303, -2341.244, 0.009, 10.0);
				}
				else if(PlayerToPoint(10.0,playerid, 2975.303, -2341.244, 0.009) && BoatTestStep[playerid] == 17)
				{
					BoatTestStep[playerid] = 18;
					SetPlayerCheckpoint(playerid, 2965.416, -2272.544, -0.865, 10.0);
				}
				else if(PlayerToPoint(10.0,playerid, 2965.416, -2272.544, -0.865) && BoatTestStep[playerid] == 18)
				{
					BoatTestStep[playerid] = 19;
					SetPlayerCheckpoint(playerid, 2954.386, -2194.223, -0.711, 10.0);
				}
				else if(PlayerToPoint(10.0,playerid, 2954.386, -2194.223, -0.711) && BoatTestStep[playerid] == 19)
				{
					BoatTestStep[playerid] = 20;
					SetPlayerCheckpoint(playerid, 2946.975, -2053.573, -1.011, 10.0);
				}
				else if(PlayerToPoint(10.0,playerid, 2946.975, -2053.573, -1.011) && BoatTestStep[playerid] == 20)
				{
					veh = GetPlayerVehicleID(playerid);
					GetVehicleHealth(veh, health);
					if(health >= 800.0)
					{
						SendClientMessage(playerid,COLOR_GREEN,"[INFO:] Utrzyma³eœ 80 procent sprawnoœci ³odzi ! Wynik pozytywny !");
						gPlayerData[playerid][pBoatLic] = 1;
						SavePlayerData(playerid, "BoatLic");
						SetVehicleToRespawnEx(veh);
						TakingBoatTest[playerid] = 0;
						DisablePlayerCheckpoint(playerid);
					}
					else
					{
						SendClientMessage(playerid,COLOR_RED,"[INFO:] Obla³eœ test, mo¿e nastêpnym razem pójdzie Ci lepiej.");
						SetVehicleToRespawnEx(veh);
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
		if( IsPlayerInRangeOfPoint(playerid, 5.0, gBusTrackCpX[ gBusDriverSelectedLine[playerid] ][ gBusDriverCurrentCheckPoint[playerid] ], gBusTrackCpY[ gBusDriverSelectedLine[playerid] ][ gBusDriverCurrentCheckPoint[playerid] ], gBusTrackCpZ[ gBusDriverSelectedLine[playerid] ][ gBusDriverCurrentCheckPoint[playerid] ] ) &&
			gBusTrackCpType[ gBusDriverSelectedLine[playerid] ][ gBusDriverCurrentCheckPoint[playerid] ] == 3)
		{
			gBusDriverCurrentCheckPoint[playerid]++;
			gBusDriverCheckpointTime[playerid] = gBusTrackCpTime[ gBusDriverSelectedLine[playerid] ][ gBusDriverCurrentCheckPoint[playerid] ];
			SetPlayerCheckpoint(playerid, gBusTrackCpX[ gBusDriverSelectedLine[playerid] ][ gBusDriverCurrentCheckPoint[playerid] ], gBusTrackCpY[ gBusDriverSelectedLine[playerid] ][ gBusDriverCurrentCheckPoint[playerid] ], gBusTrackCpZ[ gBusDriverSelectedLine[playerid] ][ gBusDriverCurrentCheckPoint[playerid] ], 5.0);
		}
	}
	return 1;
} // end of OnPlayerEnterCheckpoint

public OnPlayerPickUpDynamicPickup(playerid, pickupid)
{
	static string[1024];

	/* Prison yard exit description */
	if(pickupid == gP_PrisonYard)
	{
		GameTextForPlayer(playerid, "WIEZIENIE", 3500, 3);
	}
	
	/* Swimming pool jump enter */
	else if(pickupid == gP_SwimingPool)
	{
		GameTextForPlayer(playerid, "/wejdznaskocznie", 1500, GAME_TEXT_STYLE_4);
	}
	else if(pickupid == gP_Lottery)
	{
		GameTextForPlayer(playerid, "/ostatnielosowanie - /wypelnijkupon - /kumulacja", 1500, GAME_TEXT_STYLE_4);
	}		
	// Nauka
	else if(pickupid == SkillPosition[PickupIDPis])
	{
		GameTextForPlayer(playerid, "~n~~r~pistolet~n~cena: ~g~$1500~n~~w~/podnieslev", 1500, 3);
	}
	else if(pickupid == SkillPosition[PickupIDSil])
	{
		GameTextForPlayer(playerid, "~n~~r~pistolet z tlumikiem~n~cena: ~g~$1500~n~~w~/podnieslev", 1500, 3);
	}
	else if(pickupid == SkillPosition[PickupIDDes])
	{
		GameTextForPlayer(playerid, "~n~~r~Desert Eagle~n~cena: ~g~$2000~n~~w~/podnieslev", 1500, 3);
	}
	else if(pickupid == SkillPosition[PickupIDSho])
	{
		GameTextForPlayer(playerid, "~n~~r~shotgun~n~cena: ~g~$2000~n~~w~/podnieslev", 1500, 3);
	}
	else if(pickupid == SkillPosition[PickupIDSha])
	{
		GameTextForPlayer(playerid, "~n~~r~ogryzek~n~cena: ~g~$2000~n~~w~/podnieslev", 1500, 3);
	}
	else if(pickupid == SkillPosition[PickupIDSpa])
	{
		GameTextForPlayer(playerid, "~n~~r~shotgun bojowy~n~cena: ~g~$3000~n~~w~/podnieslev", 1500, 3);
	}
	else if(pickupid == SkillPosition[PickupIDMic])
	{
		GameTextForPlayer(playerid, "~n~~r~Uzi~n~cena: ~g~$2000~n~~w~/podnieslev", 1500, 3);
	}
	else if(pickupid == SkillPosition[PickupIDMp5])
	{
		GameTextForPlayer(playerid, "~n~~r~MP5~n~cena: ~g~$4000~n~~w~/podnieslev", 1500, 3);
	}
	else if(pickupid == SkillPosition[PickupIDAk])
	{
		GameTextForPlayer(playerid, "~n~~r~Kalashnikov~n~cena: ~g~$5000~n~~w~/podnieslev", 1500, 3);
	}
	else if(pickupid == SkillPosition[PickupIDM4])
	{
		GameTextForPlayer(playerid, "~n~~r~M4~n~cena: ~g~$5000~n~~w~/podnieslev", 1500, 3);
	}
	else if(pickupid == SkillPosition[PickupIDSni])
	{
		GameTextForPlayer(playerid, "~n~~r~snajperka~n~cena: ~g~$6000~n~~w~/podnieslev", 1500, 3);
	}
	else if(pickupid == SkillPosition[PickupIDTech])
	{
		format(string, sizeof(string), "~n~~r~nauki techniczne~n~cena: ~g~$%d~n~~w~/podnieslev", SCHOOL_COST);
		GameTextForPlayer(playerid, string, 1500, 3);
	}
	else if(pickupid == SkillPosition[PickupIDLaw])
	{
		format(string, sizeof(string), "~n~~r~nauki prawnicze~n~cena: ~g~$%d~n~~w~/podnieslev", SCHOOL_COST);
		GameTextForPlayer(playerid, string, 1500, 3);
	}
	else if(pickupid == SkillPosition[PickupIDMat])
	{
		format(string, sizeof(string), "~n~~r~nauki matematyczne~n~cena: ~g~$%d~n~~w~/podnieslev", SCHOOL_COST);
		GameTextForPlayer(playerid, string, 1500, 3);
	}
	else if(pickupid == SkillPosition[PickupIDPol])
	{
		format(string, sizeof(string), "~n~~r~nauki humanistyczne~n~cena: ~g~$%d~n~~w~/podnieslev", SCHOOL_COST);
		GameTextForPlayer(playerid, string, 1500, 3);
	}
	else if(pickupid == SkillPosition[PickupIDHis])
	{
		// TODO: Change to something
		//format(string, sizeof(string), "~n~~r~Historia~n~cena: ~g~$%d~n~~w~/podnieslev", SCHOOL_COST);
		//GameTextForPlayer(playerid, string, 1500, 3);
	}
	else if(pickupid == SkillPosition[PickupIDFiz])
	{
		format(string, sizeof(string), "~n~~r~nauki fizyczne~n~cena: ~g~$%d~n~~w~/podnieslev", SCHOOL_COST);
		GameTextForPlayer(playerid, string, 1500, 3);
	}
	else if(pickupid == SkillPosition[PickupIDBio])
	{
		format(string, sizeof(string), "~n~~r~nauki biologiczne~n~cena: ~g~$%d~n~~w~/podnieslev", SCHOOL_COST);
		GameTextForPlayer(playerid, string, 1500, 3);
	}
	else if(pickupid == SkillPosition[PickupIDHighSchool])
	{
		format(string, sizeof(string), "~n~~r~srednie wykszta³cenie~n~cena: ~g~$%d~n~~w~/podnieslev", HIGH_SCHOOL_COST);
		GameTextForPlayer(playerid, string, 1500, 3);
	}
	
	// Prace
	else if(pickupid == WFWorkerJob[TakeJobPickupID] || pickupid == WFWorkerJob[TakeJobPickupID2] || pickupid == WFWorkerJob[TakeJobPickupID3] || pickupid == WFWorkerJob[TakeJobPickupID4]
		|| pickupid == WFWorkerJob[TakeJobPickupID5] || pickupid == WFWorkerJob[TakeJobPickupID6] || pickupid == WFWorkerJob[TakeJobPickupID7])
	{
		GameTextForPlayer(playerid, "~n~~r~Pracownik fabryki broni~n~~w~/wezprace", 1500, 3);
	}
	else if(pickupid == NewsBoyJob[TakeJobPickupID])
	{
		GameTextForPlayer(playerid, "~n~~r~Roznosiciel gazet~n~~w~/wezprace - /pobierzgazety", 1500, 3);
	}
	else if(pickupid == MechanicJob2[BuyProductsPickupID])
	{
		GameTextForPlayer(playerid, "~n~~r~Czesci samochodowe~n~~w~/kupczesci", 1500, 3);
	}
	else if(pickupid == FarmerJob[TakeJobPickupID])
	{
		GameTextForPlayer(playerid, "~n~~r~Rolnik~n~~w~/wezprace", 1500, 3);
	}
	else if(pickupid == SellerJob[TakeJobPickupID])
	{
		GameTextForPlayer(playerid, "~n~~r~Sprzedawca/kasjer~n~~w~/wezprace", 1500, 3);
	}
	else if(pickupid == AccountantJob[TakeJobPickupID])
	{
		GameTextForPlayer(playerid, "~n~~r~Ksiegowy~n~~w~/wezprace", 1500, 3);
	}
	else if(pickupid == MzgkJob[TakeJobPickupID])
	{
		GameTextForPlayer(playerid, "~n~~r~Kierowca smieciarki~n~~w~/wezprace", 1500, 3);
	}
	else if(pickupid == SweeperJob[TakeJobPickupID])
	{
		GameTextForPlayer(playerid, "~n~~r~Kierowca myjki drogowej~n~~w~/wezprace", 1500, 3);
	}
	else if(pickupid == TaxiJob[TakeJobPickupID])
	{
		GameTextForPlayer(playerid, "~n~~r~Taksowkarz~n~~w~/wezprace", 1500, 3);
	}
	else if(pickupid == MechanicJob[TakeJobPickupID])
	{
		GameTextForPlayer(playerid, "~n~~r~Mechanik~n~~w~/wezprace", 1500, 3);
	}
	else if(pickupid == BodyJob[TakeJobPickupID])
	{
		GameTextForPlayer(playerid, "~n~~r~Ochroniarz ~n~~w~/wezprace", 1500, 3);
	}
	else if(pickupid == DirJob[TakeJobPickupID])
	{
		GameTextForPlayer(playerid, "~n~~r~Rezyser~n~~w~/wezprace", 1500, 3);
	}
	else if(pickupid == ProductsSellerJob[TakeJobPickupID])
	{
		GameTextForPlayer(playerid, "~n~~r~Sprzedawca produktow ~n~~w~/produkty kup", 1500, 3);
	}
	else if(pickupid == BusJob[TakeJobPickupID])
	{
		GameTextForPlayer(playerid, "~n~~r~Kierowca autobusu~n~~w~/wezprace", 1500, 3);
	}
	else if(pickupid == StuntJob[TakeJobPickupID])
	{
		GameTextForPlayer(playerid, "~n~~r~Praca kaskadera ~n~~w~/wezprace", 1500, 3);
	}
	else if(pickupid == CarjackJob[TakeJobPickupID])
	{
		GameTextForPlayer(playerid, "~n~~r~Praca zlodzieja wozow ~n~~w~/wezprace", 1500, 3);
	}
	else if(pickupid == RapistJob[TakeJobPickupID])
	{
		GameTextForPlayer(playerid, "~n~~r~Gwalciciel ~n~~w~/wezprace", 1500, 3);
	}
	else if(pickupid == BoxerJob[TakeJobPickupID])
	{
		GameTextForPlayer(playerid, "~n~~r~Boxer ~n~~w~/wezprace", 1500, 3);
	}
	else if(pickupid == LawyerJobPosition[PickupID])
	{
		GameTextForPlayer(playerid, "~n~~r~Prawnik ~n~~w~/wezprace", 1500, 3);
	}
	else if(pickupid == DetectiveJobPosition[PickupID])
	{
		GameTextForPlayer(playerid, "~n~~r~Detektyw ~n~~w~/wezprace", 1500, 3);
	}
	else if(pickupid == ProductsSellerJob[TakeJobPickupID])
	{
		GameTextForPlayer(playerid, "~n~~r~Sprzedawca produktow ~n~~w~/wezprace", 1500, 3);
	}
	else if(pickupid == WhoreJob[TakeJobPickupID])
	{
		GameTextForPlayer(playerid, "~n~~r~Praca dziwki ~n~~w~/wezprace", 1500, 3);
	}
	else if(pickupid == GunJob[TakeJobPickupID])
	{
		GameTextForPlayer(playerid, "~n~~r~Diler broni ~n~~w~/wezprace", 1500, 3);
	}
	else if(pickupid == GunJob[BuyPackagesPickupID])
	{
		GameTextForPlayer(playerid, "~n~~r~Diler broni ~n~~w~/materialy kup", 1500, 3);
	}
	else if(pickupid == GunJob[DeliverPickupID])
	{
		GameTextForPlayer(playerid, "~n~~r~Diler broni ~n~~w~/materialy zrzuc", 1500, 3);
	}
	else if(pickupid == DrugJob[TakeJobPickupID])
	{
		GameTextForPlayer(playerid, "~n~~r~Diler narkotykow ~n~~w~/wezprace", 1500, 3);
	}
	else if(pickupid == DrugJob[BuyDrugsPickupID])
	{
		GameTextForPlayer(playerid, "~n~~r~Diler narkotykow ~n~~w~/narkotyki kup", 1500, 3);
	}
	else if(pickupid == DrugJob[DeliverPickupID])
	{
		GameTextForPlayer(playerid, "~n~~r~Diler narkotykow ~n~~w~/narkotyki zrzuc", 1500, 3);
	}
	
	// Pozosta³e licencje
	else if(pickupid == WeaponLicensePosition[PickupID])
	{
		GameTextForPlayer(playerid, "~w~Licencja na bron ~n~Cena: ~g~$50000~n~~w~Wpisz /kuplicencjenabron !", 1000, 3);
	}
	else if(pickupid == BoatTestPosition[PickupID])
	{
		GameTextForPlayer(playerid, "~w~Licencja na ³odzie~n~Cena: ~g~$20000~n~~w~Wpisz /kuptest !", 1000, 3);
	}
	else if(pickupid == gPlaneTestPosition[PickupID])
	{
		GameTextForPlayer(playerid, "~w~Licencja pilota~n~Cena: ~g~$20000~n~~w~Wpisz /kuplicencjepilota !", 1000, 3);
	}
	
	// Test na prawko A
	else if(pickupid == gDrivingTestPosition[PickupIDA])
	{
		if(!gPlayerData[playerid][pFirstATest])
		{
			format(string, sizeof(string), "~w~Test na prawko kat. A ~n~Cena: ~g~%d ~n~~w~Wpisz /kuptest !", gDrivingTestPosition[mPriceA]);
			GameTextForPlayer(playerid, string, 1500, 3);
		}
		else
		{
			format(string, sizeof(string), "~w~Test na prawko kat. A ~n~Cena: ~g~%d ~n~~w~Wpisz /kuptest !", gDrivingTestPosition[mPriceLowA]);
			GameTextForPlayer(playerid, string, 1500, 3);
		}
	}
	
	// Test na prawko B
	else if(pickupid == gDrivingTestPosition[PickupIDB])
	{
		if(!gPlayerData[playerid][pFirstBTest])
		{
			format(string, sizeof(string), "~w~Test na prawko kat. B ~n~Cena: ~g~%d ~n~~w~Wpisz /kuptest !", gDrivingTestPosition[mPriceB]);
			GameTextForPlayer(playerid, string, 1500, 3);
		}
		else
		{
			format(string, sizeof(string), "~w~Test na prawko kat. B ~n~Cena: ~g~%d ~n~~w~Wpisz /kuptest !", gDrivingTestPosition[mPriceLowB]);
			GameTextForPlayer(playerid, string, 1500, 3);
		}
	}
	
	// Test na prawko C+E
	else if(pickupid == gDrivingTestPosition[PickupIDCE])
	{
		if(!gPlayerData[playerid][pFirstCETest])
		{
			format(string, sizeof(string), "~w~Test na prawko kat. C+E ~n~Cena: ~g~%d ~n~~w~Wpisz /kuptest !", gDrivingTestPosition[mPriceCE]);
			GameTextForPlayer(playerid, string, 1500, 3);
		}
		else
		{
			format(string, sizeof(string), "~w~Test na prawko kat. C+E ~n~Cena: ~g~%d ~n~~w~Wpisz /kuptest !", gDrivingTestPosition[mPriceLowCE]);
			GameTextForPlayer(playerid, string, 1500, 3);
		}
	}
	
	// Lista urzednikow
	else if(pickupid == gOfficialPickup)
	{
		strdel(string, 0, 256);
		new pointer = 0;
		for(new i = 0; i < CUSTOM_MAX_PLAYERS; i++)
		{
			if(IsPlayerConnected(i) && gPlayerLogged[i])
			{
				if(gPlayerData[i][pFaction] == FACTIONID_GOVERNMENT)
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
	
	else if(pickupid == gDrivingTestAreaBuy[pickupID])
	{
		format(string, sizeof(string), "/wykupdostepdoplacu    l. minut: %d, cena: %d", gDrivingTestAreaBuy[mTime], gDrivingTestAreaBuy[mPrice]);
		GameTextForPlayer(playerid, string, 1500, GAME_TEXT_STYLE_4);
	}
	
	else if(pickupid == gPickupEventPrizeReceive)
	{
		GameTextForPlayer(playerid, "~r~Punkt odbioru nagrod~n~/odbierznagrode", 1500, 3);
	}
	
	for(new i = 0; i < sizeof(BankPosition); i++)
	{
		if(pickupid == BankPosition[i][mPickupId])
		{
			GameTextForPlayer(playerid, "/komendybanku", 1500, GAME_TEXT_STYLE_4);
			return 1;
		}
	}
	
	for(new i = 0; i < sizeof(gPickupInfos); i++)
	{
		if(pickupid == gPickupInfos[i][mPickupId] )
		{
			if(gPickupInfos[i][mInfoTextType] == 1)
			{
				GameTextForPlayer(playerid, gPickupInfos[i][mInfoTextLine1], 5000, 3);
			}
		}
	}
	
	for(new i = 0; i < sizeof(DynamicFactions); i++)
	{
		if(DynamicFactions[i][fCP] == pickupid || DynamicFactions[i][fCP2] == pickupid)
		{
			GameTextForPlayer(playerid, "~r~/sluzba~n~/przebierzsie~n~/gbron", 1000, GAME_TEXT_STYLE_4);
			return 1;
		}
	}	
	
	for(new i = 0; i < sizeof(gAdmissionChambers); i++)
	{
		if(pickupid == gAdmissionChambers[i][mPickupID])
		{
			GameTextForPlayer(playerid, "Sala operacyjna", 1000, GAME_TEXT_STYLE_4);
			return 1;
		}
	}
	
	for(new i = 0; i < sizeof(gPickupItem); i++)
	{
		if(pickupid == gPickupItem[i][pickupID])
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
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Znalaz³eœ item !");
			DestroyDynamicPickup(pickupid);
			gPickupItem[i][pickupLifeTime] = 0;
			gPickupItem[i][pickupID] = -1;
			return 1;
		}
	}
	
	for(new i = 0; i < 10; i++)
	{
		if(pickupid == MechanicJob1[RepairPointPickupID3][i])
		{
			GameTextForPlayer(playerid, "Punkt naprawy pojazdow", 1000, GAME_TEXT_STYLE_4);
			return 1;
		}
	}
	
	for(new i = 0; i < gPickupEventCount; i++)
	{
		if(gPlayerVars[playerid][mPickupEventPickups][i] == pickupid && !gPlayerData[playerid][mPickupEventPickupStatus][i])
		{
			DestroyDynamicPickup(gPlayerVars[playerid][mPickupEventPickups][i]);
			gPlayerData[playerid][mPickupEventPickupStatus][i] = 1;
			switch(i)
			{
				case 0: SavePlayerData(playerid, "PickupEventPickupStatus1");
				case 1: SavePlayerData(playerid, "PickupEventPickupStatus2");
				case 2: SavePlayerData(playerid, "PickupEventPickupStatus3");
				case 3: SavePlayerData(playerid, "PickupEventPickupStatus4");
				case 4: SavePlayerData(playerid, "PickupEventPickupStatus5");
				case 5: SavePlayerData(playerid, "PickupEventPickupStatus6");
				case 6: SavePlayerData(playerid, "PickupEventPickupStatus7");
				case 7: SavePlayerData(playerid, "PickupEventPickupStatus8");
				case 8: SavePlayerData(playerid, "PickupEventPickupStatus9");
				case 9: SavePlayerData(playerid, "PickupEventPickupStatus10");
				case 10: SavePlayerData(playerid, "PickupEventPickupStatus11");
				case 11: SavePlayerData(playerid, "PickupEventPickupStatus12");
				case 12: SavePlayerData(playerid, "PickupEventPickupStatus13");
				case 13: SavePlayerData(playerid, "PickupEventPickupStatus14");
				case 14: SavePlayerData(playerid, "PickupEventPickupStatus15");
				case 15: SavePlayerData(playerid, "PickupEventPickupStatus16");
				case 16: SavePlayerData(playerid, "PickupEventPickupStatus17");
				case 17: SavePlayerData(playerid, "PickupEventPickupStatus18");
				case 18: SavePlayerData(playerid, "PickupEventPickupStatus19");
				case 19: SavePlayerData(playerid, "PickupEventPickupStatus20");
			}
			PlayerPickupEventPickups(playerid);
			return 1;
		}
	}
	
	for(new i = 0; i < MAX_RACES; i++)
	{
		if(pickupid == gRaceTrackInfoPickupId[i])
		{
			GameTextForPlayer(playerid, "~y~WYSCIG~n~/menuwyscigu", 1500, 3);
			return 1;
		}
	}
	
	// Event 1 - Area51
	if(gEvent1codePickups[0] == pickupid)
	{
		format(string, sizeof(string), "Znalaz³eœ sekretny kod ! Zapamiêtaj go ! Kod: %d", gEvent1code[0]);
		SendClientMessage(playerid, COLOR_GREEN, string);
	}
	else if(gEvent1codePickups[1] == pickupid)
	{
		format(string, sizeof(string), "Znalaz³eœ sekretny kod ! Zapamiêtaj go ! Kod: %d", gEvent1code[1]);
		SendClientMessage(playerid, COLOR_GREEN, string);
	}
	else if(gEvent1codePickups[2] == pickupid)
	{
		format(string, sizeof(string), "Znalaz³eœ sekretny kod ! Zapamiêtaj go ! Kod: %d", gEvent1code[2]);
		SendClientMessage(playerid, COLOR_GREEN, string);
	}
	else if(gEvent1pickup == pickupid)
	{
		format(string, sizeof(string), "%s dotar³ do wnêtrza strefy 51 i otrzymuje nagrode w wysokoœci $%d !", GetPlayerNameEx(playerid), gEvent1prize);
		SendMessageToEvent(1, COLOR_LIGHTYELLOW2, string);
		
		GivePlayerCash(playerid, gEvent1prize);
		DynamicFactions[FACTIONID_GOVERNMENT][fBank] -= gEvent1prize;
		SaveFData(FACTIONID_GOVERNMENT, "Bank");
		
		EndEvent(1);
	}
	
	return 1;
}

public OnPlayerEnterDynamicCP(playerid, checkpointid)
{
	static string[1024], string2[256];
	
	if(checkpointid == gRafinery[RafResourceCP])
	{
		if(gPlayerData[playerid][pFaction] != FACTIONID_RAFINERY)
		{
			SendClientMessage(playerid, COLOR_ORANGE, RAF_RSC_CP_INV_PLFAC);
			return 1;
		}
		
		new vehID = GetPlayerVehicleID(playerid);
		
		if(vehID == 0)
		{
			SendClientMessage(playerid, COLOR_ORANGE, RAF_RSC_CP_INV_VEHID);
			return 1;
		}
		
		new trailID = GetVehicleTrailer(vehID);
		
		if(trailID == 0)
		{
			SendClientMessage(playerid, COLOR_ORANGE, RAF_RSC_CP_INV_TLID);
			return 1;
		}
		
		if(IsPlayerInAnyVehicle(playerid))
		{
			if(gVehData[vehID-1][mVehFaction] != FACTIONID_RAFINERY)
			{
				SendClientMessage(playerid, COLOR_ORANGE, RAF_RSC_CP_INV_VEH_FACTION);
				return 1;
			}
			
			if(gVehData[trailID-1][mVehFaction] != FACTIONID_RAFINERY)
			{
				SendClientMessage(playerid, COLOR_ORANGE, RAF_RSC_CP_INV_TL_FACTION);
				return 1;
			}
			
			switch(gVehData[trailID-1][TankerResourceType])
			{
				case TANKER_TYPE_PETROL:
				{
					format(string, sizeof(string), "[INFO:] Cysterna jest nape³niona %dl beznyny", gVehData[trailID-1][TankerResourceValue]);
				}
				case TANKER_TYPE_OIL:
				{
					format(string, sizeof(string), "[INFO:] Cysterna jest nape³niona %dl ropy", gVehData[trailID-1][TankerResourceValue]);
				}
				case TANKER_TYPE_GAS:
				{
					format(string, sizeof(string), "[INFO:] Cysterna jest nape³niona %dl ropy", gVehData[trailID-1][TankerResourceValue]);
				}
				case TANKER_TYPE_FLY:
				{
					format(string, sizeof(string), "[INFO:] Cysterna jest nape³niona %dl paliwa lotniczego", gVehData[trailID-1][TankerResourceValue]);
				}
				default:
				{
					format(string, sizeof(string), "[INFO:] Cysterna jest pusta");
				}
			}
			
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			
			ShowPlayerDialog(playerid, DIALOG_RAF_RSC_CP_MAIN, DIALOG_STYLE_LIST, RAF_RSC_CP_MENU_HEADER, RAF_RSC_CP_MENU_OPTIONS_MAIN, RAF_RSC_CP_MENU_SELECT, RAF_RSC_CP_MENU_EXIT);
			
			return 1;
		}
	}
	
	if(checkpointid == gGovCheckpoint)
	{
		ShowPlayerDialog(playerid,DIALOG_GOVERNMENT_1,DIALOG_STYLE_LIST,""#COLOR_TITLE"Co chcesz zrobiæ ?",DIALOG_GOVERNMENT_1_TXT,"Wybierz","Zamknij");
		return 1;
	}
	
	if(checkpointid == gGovCheckpoint2)
	{
		ShowPlayerDialog(playerid, DIALOG_GOVERNMENT2_1, DIALOG_STYLE_LIST, ""#COLOR_TITLE"Co chcesz zrobiæ ?", DIALOG_GOVERNMENT2_1_TXT, "Wybierz", "Zamknij");
		return 1;
	}
	
	if(gPlayerData[playerid][pFaction] != 255)
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
			else if( checkpointid == DynamicFactions[gPlayerData[playerid][pFaction]][WFactoryCPSafeID] )
			{
				GameTextForPlayer( playerid, "Sejf /swplac - /swyplac - /sstan", GAME_TEXT_DEFAULT_TIME, GAME_TEXT_STYLE_6 );
				return 1;
			}
		}
	}
	
	if(checkpointid == WFactoryLegal[WFactoryCPPartSetup1ID] || checkpointid == WFactoryLegal[WFactoryCPPartSetup2ID] || 
		checkpointid == WFactoryLegal[WFactoryCPPartSetup3ID] || checkpointid == WFactoryLegal[WFactoryCPPartSetup4ID] || 
		checkpointid == WFactoryLegal[WFactoryCPPartSetup5ID] || checkpointid == WFactoryLegal[WFactoryCPPartSetup6ID])
	{
		GameTextForPlayer( playerid, WFACTORY_MOUNT_P_CP, GAME_TEXT_DEFAULT_TIME, GAME_TEXT_STYLE_6 );
		return 1;
	}
	else if(checkpointid == WFactoryLegal[WFactoryCPAmmoSetup1ID] || checkpointid == WFactoryLegal[WFactoryCPAmmoSetup2ID] || 
				checkpointid == WFactoryLegal[WFactoryCPAmmoSetup3ID] || checkpointid == WFactoryLegal[WFactoryCPAmmoSetup4ID] || 
				checkpointid == WFactoryLegal[WFactoryCPAmmoSetup5ID] || checkpointid == WFactoryLegal[WFactoryCPAmmoSetup6ID])
	{
		GameTextForPlayer( playerid, WFACTORY_MOUNT_SP_CP, GAME_TEXT_DEFAULT_TIME, GAME_TEXT_STYLE_6 );
		return 1;
	}
	else if(checkpointid == WFactoryLegal[WFactoryCPPartTakeID])
	{
		GameTextForPlayer( playerid, WFACTORY_TAKE_BUY_CP, GAME_TEXT_DEFAULT_TIME, GAME_TEXT_STYLE_6 );
		return 1;
	}	
	else if(checkpointid == WFactoryLegal[WFactoryCPDocsID] || checkpointid == WFactoryLegal[WFactoryCPDocsID2] || checkpointid == WFactoryLegal[WFactoryCPDocsID3]
		|| checkpointid == WFactoryLegal[WFactoryCPDocsID4] || checkpointid == WFactoryLegal[WFactoryCPDocsID5] || checkpointid == WFactoryLegal[WFactoryCPDocsID6] || checkpointid == WFactoryLegal[WFactoryCPDocsID7])
	{	
		GameTextForPlayer( playerid, WFACTORY_TAKE_ORD_BUY_CP, GAME_TEXT_DEFAULT_TIME, GAME_TEXT_STYLE_6 );
		return 1;
	}
	else if(gHorsesCp[0] == checkpointid || gHorsesCp[1] == checkpointid)
	{
		GameTextForPlayer(playerid, "/komendybuchmacherskie", 3000, GAME_TEXT_STYLE_6);
		return 1;
	}	
	else if(gEvent1cp[0] == checkpointid)
	{
		new Code0[30];
		valstr(Code0, gEvent1code[0]);
		ShowPlayerKeypad(playerid, KEYPAD_DOOR_1, Code0);
	}
	else if(gEvent1cp[1] == checkpointid)
	{
		new Code1[30];
		valstr(Code1, gEvent1code[1]);
		ShowPlayerKeypad(playerid, KEYPAD_DOOR_2, Code1);
	}
	else if(gEvent1cp[2] == checkpointid)
	{
		new Code2[30];
		valstr(Code2, gEvent1code[2]);
		ShowPlayerKeypad(playerid, KEYPAD_DOOR_3, Code2);
	}
	else if(gMainPrisonCp == checkpointid)
	{
		GameTextForPlayer(playerid, "/aresztuj", 3000, GAME_TEXT_STYLE_6);
		return 1;
	}
	
	for(new i = 0; i < sizeof(gPrisonCellsCp); i++)
	{
		if(gPrisonCellsCp[i] == checkpointid)
		{
			GameTextForPlayer(playerid, "/aresztuj", 3000, GAME_TEXT_STYLE_6);
			return 1;
		}
	}
	
	for(new i = 0; i < sizeof(gAtmCp); i++)
	{
		if(gAtmCp[i] == checkpointid)
		{
			GameTextForPlayer(playerid, "/komendybanku", 3000, GAME_TEXT_STYLE_6);
			return 1;
		}
	}
	
	for(new i = 0; i < sizeof(gShopCP); i++)
	{
		if(checkpointid != gShopCP[i])
			continue;
		gBuyBusinessID[playerid] = GetPlayerVirtualWorld(playerid);
		ShowShopMenu(playerid);
		return 1;
	}
	
	for(new i = 0; i < sizeof(gClotheShopCP); i++)
	{
		if(checkpointid != gClotheShopCP[i])
			continue;
		gBuyBusinessID[playerid] = GetPlayerVirtualWorld(playerid);
		new slot = BizHaveItem(gBuyBusinessID[playerid], 3, 24);
		if(slot != 0)
		{
			if(BizItemSlotCount(gBuyBusinessID[playerid], slot) > 0)
			{
				PlayerToClotheStore(playerid);
				SetPlayerClotheStoreSkin(playerid);
				return 1;
			}
		}
		ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "W³aœciciel sklepu nie posiada na sprzeda¿ ¿adnej odzie¿y.", "Zamknij", "");
		return 1;
	}
	
	for(new i = 0; i < sizeof(gMedicCheckpoints); i++)
	{
		if(gMedicCheckpoints[i] != checkpointid)
		{
			continue;
		}
		
		ShowPlayerDialog(playerid, DIALOG_MEDIC_1, DIALOG_STYLE_LIST, ""#COLOR_TITLE"Co chcesz zrobiæ ?", "1. Ulecz", "Dalej", "Zamknij");
		return 1;
	}	
	
	if(IsPlayerInAnyVehicle(playerid))
	{
		gBuyItemFactoryVehID[playerid] = GetPlayerVehicleID(playerid);
		for(new i = 0; i <sizeof(gItemFactories); i++)
		{
			if(checkpointid == gItemFactories[i][fCPID] && gPlayerData[playerid][pJob] == JOB_PRODUCTSELLER)
			{
				gBuyItemFactoryID[playerid] = i;
				format(string, sizeof(string), DIALOG_ITEM_FACTORY_ITEM_LIST,
					ItemName(gItemFactories[i][item1type], gItemFactories[i][item1]),
					gItemFactories[i][item1price],
					gItemFactories[i][item1count],
					ItemName(gItemFactories[i][item2type], gItemFactories[i][item2]),
					gItemFactories[i][item2price],
					gItemFactories[i][item2count],
					ItemName(gItemFactories[i][item3type], gItemFactories[i][item3]),
					gItemFactories[i][item3price],
					gItemFactories[i][item3count],
					ItemName(gItemFactories[i][item4type], gItemFactories[i][item4]),
					gItemFactories[i][item4price],
					gItemFactories[i][item4count],
					ItemName(gItemFactories[i][item5type], gItemFactories[i][item5]),
					gItemFactories[i][item5price],
					gItemFactories[i][item5count],
					ItemName(gItemFactories[i][item6type], gItemFactories[i][item6]),
					gItemFactories[i][item6price],
					gItemFactories[i][item6count],
					ItemName(gItemFactories[i][item7type], gItemFactories[i][item7]),
					gItemFactories[i][item7price],
					gItemFactories[i][item7count],
					ItemName(gItemFactories[i][item8type], gItemFactories[i][item8]),
					gItemFactories[i][item8price],
					gItemFactories[i][item8count],
					ItemName(gItemFactories[i][item9type], gItemFactories[i][item9]),
					gItemFactories[i][item9price],
					gItemFactories[i][item9count],
					ItemName(gItemFactories[i][item10type], gItemFactories[i][item10]),
					gItemFactories[i][item10price],
					gItemFactories[i][item10count]
				);		
				format(string2, sizeof(string2), DIALOG_ITEM_FACTORY_TITLE, gItemFactories[i][fName]);
				ShowPlayerDialog(playerid, DIALOG_ITEM_FACTORY_1, DIALOG_STYLE_LIST, string2, string, "Wybierz", "WyjdŸ");
				return 1;
			}
		}
	}
	
	return 1;
}

public OnPlayerLeaveDynamicCP(playerid, checkpointid)
{
	return 1;
}

public OnPlayerEnterDynamicRaceCP(playerid, checkpointid)
{
	new string[128];
	for(new i = 0; i < MAX_RACES; i++)
	{
		if(gRaceStatus[i][mRaceState] == RACE_STATE_JOINING)
		{
			if((checkpointid == gRaceStatus[i][mRaceEntrant1CpId] && gRaceStatus[i][mRaceEntrant1Id] == playerid) ||
				(checkpointid == gRaceStatus[i][mRaceEntrant2CpId] && gRaceStatus[i][mRaceEntrant2Id] == playerid) ||
				(checkpointid == gRaceStatus[i][mRaceEntrant3CpId] && gRaceStatus[i][mRaceEntrant3Id] == playerid) ||
				(checkpointid == gRaceStatus[i][mRaceEntrant4CpId] && gRaceStatus[i][mRaceEntrant4Id] == playerid) ||
				(checkpointid == gRaceStatus[i][mRaceEntrant5CpId] && gRaceStatus[i][mRaceEntrant5Id] == playerid) ||
				(checkpointid == gRaceStatus[i][mRaceEntrant6CpId] && gRaceStatus[i][mRaceEntrant6Id] == playerid) ||
				(checkpointid == gRaceStatus[i][mRaceEntrant7CpId] && gRaceStatus[i][mRaceEntrant7Id] == playerid) ||
				(checkpointid == gRaceStatus[i][mRaceEntrant8CpId] && gRaceStatus[i][mRaceEntrant8Id] == playerid) ||
				(checkpointid == gRaceStatus[i][mRaceEntrant9CpId] && gRaceStatus[i][mRaceEntrant9Id] == playerid) ||
				(checkpointid == gRaceStatus[i][mRaceEntrant10CpId] && gRaceStatus[i][mRaceEntrant10Id] == playerid))
			{
				if(gRaceStatus[i][mRaceEntrant1Id] == playerid)
					gRaceStatus[i][mRaceEntrant1IsOnStartPos] = 1;
				if(gRaceStatus[i][mRaceEntrant2Id] == playerid)
					gRaceStatus[i][mRaceEntrant2IsOnStartPos] = 1;
				if(gRaceStatus[i][mRaceEntrant3Id] == playerid)
					gRaceStatus[i][mRaceEntrant3IsOnStartPos] = 1;
				if(gRaceStatus[i][mRaceEntrant4Id] == playerid)
					gRaceStatus[i][mRaceEntrant4IsOnStartPos] = 1;
				if(gRaceStatus[i][mRaceEntrant5Id] == playerid)
					gRaceStatus[i][mRaceEntrant5IsOnStartPos] = 1;
				if(gRaceStatus[i][mRaceEntrant6Id] == playerid)
					gRaceStatus[i][mRaceEntrant6IsOnStartPos] = 1;
				if(gRaceStatus[i][mRaceEntrant7Id] == playerid)
					gRaceStatus[i][mRaceEntrant7IsOnStartPos] = 1;
				if(gRaceStatus[i][mRaceEntrant8Id] == playerid)
					gRaceStatus[i][mRaceEntrant8IsOnStartPos] = 1;
				if(gRaceStatus[i][mRaceEntrant9Id] == playerid)
					gRaceStatus[i][mRaceEntrant9IsOnStartPos] = 1;
				if(gRaceStatus[i][mRaceEntrant10Id] == playerid)
					gRaceStatus[i][mRaceEntrant10IsOnStartPos] = 1;
					
				TogglePlayerControllable(playerid, 0);
				defer UnfreezePlayer[1300](playerid);
					
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Zaj¹³eœ pozycje startow¹", "Zamknij", "");
				return 1;
			}
		}
		else if(gRaceStatus[i][mRaceState] == RACE_STATE_RACE)
		{
			if(checkpointid == gRaceStatus[i][mRaceEntrant1CpId] && gRaceStatus[i][mRaceEntrant1Id] == playerid)
			{
				if(gRaceTrackCpType[gRaceStatus[i][mRaceId]][gRaceStatus[i][mRaceEntrant1NextCpId]] == RACE_CP_TYPE_FINISH)
				{
					if(gRaceStatus[i][mRaceLaps] > 1)
					{
						if(gRaceStatus[i][mRaceEntrant1Lap] < gRaceStatus[i][mRaceLaps])
						{
							gRaceStatus[i][mRaceEntrant1Lap]++;
							
							format(string, sizeof(string), "Okrazenie %d/%d", gRaceStatus[i][mRaceEntrant1Lap], gRaceStatus[i][mRaceLaps]);
							TextDrawSetString(gRaceStatus[i][mRaceInfo], string);
							
							gRaceStatus[i][mRaceEntrant1NextCpId] = 0;
							ShowNextRaceCheckpoint(i, 1);
							continue;
						}
					}
					if(gRaceStatus[i][mRaceEntrant1Status] != PLAYER_RACE_STATE_FINISHED)
					{
						gRaceStatus[i][mRaceEntrant1Status] = PLAYER_RACE_STATE_FINISHED;
						TogglePlayerControllable(playerid, 0);
						defer UnfreezePlayer[1000](playerid);
						CalculateRacerTime(i, 1);
						GameTextForRacerFinish(i, 1);
						SaveRacerStats(i, 1);
					}
				}
				else if(gRaceStatus[i][mRaceEntrant1NextCpId]+1 <= MAX_RACES_CP-1)
				{
					gRaceStatus[i][mRaceEntrant1NextCpId]++;
					ShowNextRaceCheckpoint(i, 1);
				}
			}
			if(checkpointid == gRaceStatus[i][mRaceEntrant2CpId] && gRaceStatus[i][mRaceEntrant2Id] == playerid)
			{
				if(gRaceTrackCpType[gRaceStatus[i][mRaceId]][gRaceStatus[i][mRaceEntrant2NextCpId]] == RACE_CP_TYPE_FINISH)
				{
					if(gRaceStatus[i][mRaceLaps] > 1)
					{
						if(gRaceStatus[i][mRaceEntrant2Lap] < gRaceStatus[i][mRaceLaps])
						{
							gRaceStatus[i][mRaceEntrant2Lap]++;
							
							format(string, sizeof(string), "Okrazenie %d/%d", gRaceStatus[i][mRaceEntrant2Lap], gRaceStatus[i][mRaceLaps]);
							TextDrawSetString(gRaceStatus[i][mRaceInfo], string);
							
							gRaceStatus[i][mRaceEntrant2NextCpId] = 0;
							ShowNextRaceCheckpoint(i, 2);
							continue;
						}
					}
					if(gRaceStatus[i][mRaceEntrant2Status] != PLAYER_RACE_STATE_FINISHED)
					{
						gRaceStatus[i][mRaceEntrant2Status] = PLAYER_RACE_STATE_FINISHED;
						TogglePlayerControllable(playerid, 0);
						defer UnfreezePlayer[1000](playerid);
						CalculateRacerTime(i, 2);
						GameTextForRacerFinish(i, 2);
					}
				}
				else if(gRaceStatus[i][mRaceEntrant2NextCpId]+1 <= MAX_RACES_CP-1)
				{
					gRaceStatus[i][mRaceEntrant2NextCpId]++;
					ShowNextRaceCheckpoint(i, 2);
				}
			}
			if(checkpointid == gRaceStatus[i][mRaceEntrant3CpId] && gRaceStatus[i][mRaceEntrant3Id] == playerid)
			{
				if(gRaceTrackCpType[gRaceStatus[i][mRaceId]][gRaceStatus[i][mRaceEntrant3NextCpId]] == RACE_CP_TYPE_FINISH)
				{
					if(gRaceStatus[i][mRaceLaps] > 1)
					{
						if(gRaceStatus[i][mRaceEntrant3Lap] < gRaceStatus[i][mRaceLaps])
						{
							gRaceStatus[i][mRaceEntrant3Lap]++;
							
							format(string, sizeof(string), "Okrazenie %d/%d", gRaceStatus[i][mRaceEntrant3Lap], gRaceStatus[i][mRaceLaps]);
							TextDrawSetString(gRaceStatus[i][mRaceInfo], string);
							
							gRaceStatus[i][mRaceEntrant3NextCpId] = 0;
							ShowNextRaceCheckpoint(i, 3);
							continue;
						}
					}
					if(gRaceStatus[i][mRaceEntrant3Status] != PLAYER_RACE_STATE_FINISHED)
					{
						gRaceStatus[i][mRaceEntrant3Status] = PLAYER_RACE_STATE_FINISHED;
						TogglePlayerControllable(playerid, 0);
						defer UnfreezePlayer[1500](playerid);
						CalculateRacerTime(i, 3);
						GameTextForRacerFinish(i, 3);
					}
				}
				else if(gRaceStatus[i][mRaceEntrant3NextCpId]+1 <= MAX_RACES_CP-1)
				{
					gRaceStatus[i][mRaceEntrant3NextCpId]++;
					ShowNextRaceCheckpoint(i, 3);
				}
			}
			if(checkpointid == gRaceStatus[i][mRaceEntrant4CpId] && gRaceStatus[i][mRaceEntrant4Id] == playerid)
			{
				if(gRaceTrackCpType[gRaceStatus[i][mRaceId]][gRaceStatus[i][mRaceEntrant4NextCpId]] == RACE_CP_TYPE_FINISH)
				{
					if(gRaceStatus[i][mRaceLaps] > 1)
					{
						if(gRaceStatus[i][mRaceEntrant4Lap] < gRaceStatus[i][mRaceLaps])
						{
							gRaceStatus[i][mRaceEntrant4Lap]++;
							
							format(string, sizeof(string), "Okrazenie %d/%d", gRaceStatus[i][mRaceEntrant4Lap], gRaceStatus[i][mRaceLaps]);
							TextDrawSetString(gRaceStatus[i][mRaceInfo], string);
							
							gRaceStatus[i][mRaceEntrant4NextCpId] = 0;
							ShowNextRaceCheckpoint(i, 4);
							continue;
						}
					}
					if(gRaceStatus[i][mRaceEntrant4Status] != PLAYER_RACE_STATE_FINISHED)
					{
						gRaceStatus[i][mRaceEntrant4Status] = PLAYER_RACE_STATE_FINISHED;
						TogglePlayerControllable(playerid, 0);
						defer UnfreezePlayer[1000](playerid);
						CalculateRacerTime(i, 4);
						GameTextForRacerFinish(i, 4);
					}
				}
				else if(gRaceStatus[i][mRaceEntrant4NextCpId]+1 <= MAX_RACES_CP-1)
				{
					gRaceStatus[i][mRaceEntrant4NextCpId]++;
					ShowNextRaceCheckpoint(i, 4);
				}
			}
			if(checkpointid == gRaceStatus[i][mRaceEntrant5CpId] && gRaceStatus[i][mRaceEntrant5Id] == playerid)
			{
				if(gRaceTrackCpType[gRaceStatus[i][mRaceId]][gRaceStatus[i][mRaceEntrant5NextCpId]] == RACE_CP_TYPE_FINISH)
				{
					if(gRaceStatus[i][mRaceLaps] > 1)
					{
						if(gRaceStatus[i][mRaceEntrant5Lap] < gRaceStatus[i][mRaceLaps])
						{
							gRaceStatus[i][mRaceEntrant5Lap]++;
							
							format(string, sizeof(string), "Okrazenie %d/%d", gRaceStatus[i][mRaceEntrant5Lap], gRaceStatus[i][mRaceLaps]);
							TextDrawSetString(gRaceStatus[i][mRaceInfo], string);
							
							gRaceStatus[i][mRaceEntrant5NextCpId] = 0;
							ShowNextRaceCheckpoint(i, 5);
							continue;
						}
					}
					if(gRaceStatus[i][mRaceEntrant5Status] != PLAYER_RACE_STATE_FINISHED)
					{
						gRaceStatus[i][mRaceEntrant5Status] = PLAYER_RACE_STATE_FINISHED;
						TogglePlayerControllable(playerid, 0);
						defer UnfreezePlayer[1000](playerid);
						CalculateRacerTime(i, 5);
						GameTextForRacerFinish(i, 5);
					}
				}
				else if(gRaceStatus[i][mRaceEntrant5NextCpId]+1 <= MAX_RACES_CP-1)
				{
					gRaceStatus[i][mRaceEntrant5NextCpId]++;
					ShowNextRaceCheckpoint(i, 5);
				}
			}
			if(checkpointid == gRaceStatus[i][mRaceEntrant6CpId] && gRaceStatus[i][mRaceEntrant6Id] == playerid)
			{
				if(gRaceTrackCpType[gRaceStatus[i][mRaceId]][gRaceStatus[i][mRaceEntrant6NextCpId]] == RACE_CP_TYPE_FINISH)
				{
					if(gRaceStatus[i][mRaceLaps] > 1)
					{
						if(gRaceStatus[i][mRaceEntrant6Lap] < gRaceStatus[i][mRaceLaps])
						{
							gRaceStatus[i][mRaceEntrant6Lap]++;
							
							format(string, sizeof(string), "Okrazenie %d/%d", gRaceStatus[i][mRaceEntrant6Lap], gRaceStatus[i][mRaceLaps]);
							TextDrawSetString(gRaceStatus[i][mRaceInfo], string);
							
							gRaceStatus[i][mRaceEntrant6NextCpId] = 0;
							ShowNextRaceCheckpoint(i, 6);
							continue;
						}
					}
					if(gRaceStatus[i][mRaceEntrant6Status] != PLAYER_RACE_STATE_FINISHED)
					{
						gRaceStatus[i][mRaceEntrant6Status] = PLAYER_RACE_STATE_FINISHED;
						TogglePlayerControllable(playerid, 0);
						defer UnfreezePlayer[1000](playerid);
						CalculateRacerTime(i, 6);
						GameTextForRacerFinish(i, 6);
					}
				}
				else if(gRaceStatus[i][mRaceEntrant6NextCpId]+1 <= MAX_RACES_CP-1)
				{
					gRaceStatus[i][mRaceEntrant6NextCpId]++;
					ShowNextRaceCheckpoint(i, 6);
				}
			}
			if(checkpointid == gRaceStatus[i][mRaceEntrant7CpId] && gRaceStatus[i][mRaceEntrant7Id] == playerid)
			{
				if(gRaceTrackCpType[gRaceStatus[i][mRaceId]][gRaceStatus[i][mRaceEntrant7NextCpId]] == RACE_CP_TYPE_FINISH)
				{
					if(gRaceStatus[i][mRaceLaps] > 1)
					{
						if(gRaceStatus[i][mRaceEntrant7Lap] < gRaceStatus[i][mRaceLaps])
						{
							gRaceStatus[i][mRaceEntrant7Lap]++;
							
							format(string, sizeof(string), "Okrazenie %d/%d", gRaceStatus[i][mRaceEntrant7Lap], gRaceStatus[i][mRaceLaps]);
							TextDrawSetString(gRaceStatus[i][mRaceInfo], string);
							
							gRaceStatus[i][mRaceEntrant7NextCpId] = 0;
							ShowNextRaceCheckpoint(i, 7);
							continue;
						}
					}
					if(gRaceStatus[i][mRaceEntrant7Status] != PLAYER_RACE_STATE_FINISHED)
					{
						gRaceStatus[i][mRaceEntrant7Status] = PLAYER_RACE_STATE_FINISHED;
						TogglePlayerControllable(playerid, 0);
						defer UnfreezePlayer[1000](playerid);
						CalculateRacerTime(i, 7);
						GameTextForRacerFinish(i, 7);
					}
				}
				else if(gRaceStatus[i][mRaceEntrant7NextCpId]+1 <= MAX_RACES_CP-1)
				{
					gRaceStatus[i][mRaceEntrant7NextCpId]++;
					ShowNextRaceCheckpoint(i, 7);
				}
			}
			if(checkpointid == gRaceStatus[i][mRaceEntrant8CpId] && gRaceStatus[i][mRaceEntrant8Id] == playerid)
			{
				if(gRaceTrackCpType[gRaceStatus[i][mRaceId]][gRaceStatus[i][mRaceEntrant9NextCpId]] == RACE_CP_TYPE_FINISH)
				{
					if(gRaceStatus[i][mRaceLaps] > 1)
					{
						if(gRaceStatus[i][mRaceEntrant8Lap] < gRaceStatus[i][mRaceLaps])
						{
							gRaceStatus[i][mRaceEntrant8Lap]++;
							
							format(string, sizeof(string), "Okrazenie %d/%d", gRaceStatus[i][mRaceEntrant8Lap], gRaceStatus[i][mRaceLaps]);
							TextDrawSetString(gRaceStatus[i][mRaceInfo], string);
							
							gRaceStatus[i][mRaceEntrant8NextCpId] = 0;
							ShowNextRaceCheckpoint(i, 8);
							continue;
						}
					}
					if(gRaceStatus[i][mRaceEntrant8Status] != PLAYER_RACE_STATE_FINISHED)
					{
						gRaceStatus[i][mRaceEntrant8Status] = PLAYER_RACE_STATE_FINISHED;
						TogglePlayerControllable(playerid, 0);
						defer UnfreezePlayer[1000](playerid);
						CalculateRacerTime(i, 8);
						GameTextForRacerFinish(i, 8);
					}
				}
				else if(gRaceStatus[i][mRaceEntrant8NextCpId]+1 <= MAX_RACES_CP-1)
				{
					gRaceStatus[i][mRaceEntrant8NextCpId]++;
					ShowNextRaceCheckpoint(i, 8);
				}
			}
			if(checkpointid == gRaceStatus[i][mRaceEntrant9CpId] && gRaceStatus[i][mRaceEntrant9Id] == playerid)
			{
				if(gRaceTrackCpType[gRaceStatus[i][mRaceId]][gRaceStatus[i][mRaceEntrant9NextCpId]] == RACE_CP_TYPE_FINISH)
				{
					if(gRaceStatus[i][mRaceLaps] > 1)
					{
						if(gRaceStatus[i][mRaceEntrant9Lap] < gRaceStatus[i][mRaceLaps])
						{
							gRaceStatus[i][mRaceEntrant9Lap]++;
							
							format(string, sizeof(string), "Okrazenie %d/%d", gRaceStatus[i][mRaceEntrant9Lap], gRaceStatus[i][mRaceLaps]);
							TextDrawSetString(gRaceStatus[i][mRaceInfo], string);
							
							gRaceStatus[i][mRaceEntrant9NextCpId] = 0;
							ShowNextRaceCheckpoint(i, 9);
							continue;
						}
					}
					if(gRaceStatus[i][mRaceEntrant9Status] != PLAYER_RACE_STATE_FINISHED)
					{
						gRaceStatus[i][mRaceEntrant9Status] = PLAYER_RACE_STATE_FINISHED;
						TogglePlayerControllable(playerid, 0);
						defer UnfreezePlayer[1000](playerid);
						CalculateRacerTime(i, 9);
						GameTextForRacerFinish(i, 9);
					}
				}
				if(gRaceStatus[i][mRaceEntrant9NextCpId]+1 <= MAX_RACES_CP-1)
				{
					gRaceStatus[i][mRaceEntrant9NextCpId]++;
					ShowNextRaceCheckpoint(i, 9);
				}
			}
			if(checkpointid == gRaceStatus[i][mRaceEntrant10CpId] && gRaceStatus[i][mRaceEntrant10Id] == playerid)
			{
				if(gRaceTrackCpType[gRaceStatus[i][mRaceId]][gRaceStatus[i][mRaceEntrant10NextCpId]] == RACE_CP_TYPE_FINISH)
				{
					if(gRaceStatus[i][mRaceLaps] > 1)
					{
						if(gRaceStatus[i][mRaceEntrant10Lap] < gRaceStatus[i][mRaceLaps])
						{
							gRaceStatus[i][mRaceEntrant10Lap]++;
							
							format(string, sizeof(string), "Okrazenie %d/%d", gRaceStatus[i][mRaceEntrant10Lap], gRaceStatus[i][mRaceLaps]);
							TextDrawSetString(gRaceStatus[i][mRaceInfo], string);
							
							gRaceStatus[i][mRaceEntrant10NextCpId] = 0;
							ShowNextRaceCheckpoint(i, 10);
							continue;
						}
					}
					if(gRaceStatus[i][mRaceEntrant10Status] != PLAYER_RACE_STATE_FINISHED)
					{
						gRaceStatus[i][mRaceEntrant10Status] = PLAYER_RACE_STATE_FINISHED;
						TogglePlayerControllable(playerid, 0);
						defer UnfreezePlayer[1000](playerid);
						CalculateRacerTime(i, 10);
						GameTextForRacerFinish(i, 10);
					}
				}
				else if(gRaceStatus[i][mRaceEntrant10NextCpId]+1 <= MAX_RACES_CP-1)
				{
					gRaceStatus[i][mRaceEntrant10NextCpId]++;
					ShowNextRaceCheckpoint(i, 10);
				}
			}
		}		
	}
	return 1;
}

public OnPlayerLeaveDynamicRaceCP(playerid, checkpointid)
{
	for(new i = 0; i < MAX_RACES; i++)
	{
		if(gRaceStatus[i][mRaceState] == RACE_STATE_JOINING)
		{
			if((checkpointid == gRaceStatus[i][mRaceEntrant1CpId] && gRaceStatus[i][mRaceEntrant1Id] == playerid) ||
				(checkpointid == gRaceStatus[i][mRaceEntrant2CpId] && gRaceStatus[i][mRaceEntrant2Id] == playerid) ||
				(checkpointid == gRaceStatus[i][mRaceEntrant3CpId] && gRaceStatus[i][mRaceEntrant3Id] == playerid) ||
				(checkpointid == gRaceStatus[i][mRaceEntrant4CpId] && gRaceStatus[i][mRaceEntrant4Id] == playerid) ||
				(checkpointid == gRaceStatus[i][mRaceEntrant5CpId] && gRaceStatus[i][mRaceEntrant5Id] == playerid) ||
				(checkpointid == gRaceStatus[i][mRaceEntrant6CpId] && gRaceStatus[i][mRaceEntrant6Id] == playerid) ||
				(checkpointid == gRaceStatus[i][mRaceEntrant7CpId] && gRaceStatus[i][mRaceEntrant7Id] == playerid) ||
				(checkpointid == gRaceStatus[i][mRaceEntrant8CpId] && gRaceStatus[i][mRaceEntrant8Id] == playerid) ||
				(checkpointid == gRaceStatus[i][mRaceEntrant9CpId] && gRaceStatus[i][mRaceEntrant9Id] == playerid) ||
				(checkpointid == gRaceStatus[i][mRaceEntrant10CpId] && gRaceStatus[i][mRaceEntrant10Id] == playerid))
			{
				if(gRaceStatus[i][mRaceEntrant1Id] == playerid)
					gRaceStatus[i][mRaceEntrant1IsOnStartPos] = 0;
				if(gRaceStatus[i][mRaceEntrant2Id] == playerid)
					gRaceStatus[i][mRaceEntrant2IsOnStartPos] = 0;
				if(gRaceStatus[i][mRaceEntrant3Id] == playerid)
					gRaceStatus[i][mRaceEntrant3IsOnStartPos] = 0;
				if(gRaceStatus[i][mRaceEntrant4Id] == playerid)
					gRaceStatus[i][mRaceEntrant4IsOnStartPos] = 0;
				if(gRaceStatus[i][mRaceEntrant5Id] == playerid)
					gRaceStatus[i][mRaceEntrant5IsOnStartPos] = 0;
				if(gRaceStatus[i][mRaceEntrant6Id] == playerid)
					gRaceStatus[i][mRaceEntrant6IsOnStartPos] = 0;
				if(gRaceStatus[i][mRaceEntrant7Id] == playerid)
					gRaceStatus[i][mRaceEntrant7IsOnStartPos] = 0;
				if(gRaceStatus[i][mRaceEntrant8Id] == playerid)
					gRaceStatus[i][mRaceEntrant8IsOnStartPos] = 0;
				if(gRaceStatus[i][mRaceEntrant9Id] == playerid)
					gRaceStatus[i][mRaceEntrant9IsOnStartPos] = 0;
				if(gRaceStatus[i][mRaceEntrant10Id] == playerid)
					gRaceStatus[i][mRaceEntrant10IsOnStartPos] = 0;
			}
		}
	}
	return 1;
}

public OnPlayerEnterDynamicArea(playerid, areaid)
{
	if(areaid == gASanFierro || areaid == gALosSantos1 || areaid == gALosSantos2 || areaid == gAAngelPine || areaid == gAPalominoCreek || areaid == gAMontgomery)
	{
		gIsInCityAreaSpeedLimit[playerid] = 1;
		playBackgroundSounds(playerid, areaid, 0);
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
		playBackgroundSounds(playerid, areaid, 1);
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

public OnPlayerGiveDamage(playerid, damagedid, Float:amount, weaponid)
{
	GetPlayerFacingAngle(playerid, gPlayerData[playerid][pCrashAngle]);
	GetPlayerFacingAngle(damagedid, gPlayerData[damagedid][pCrashAngle]);
	if(floatabs(gPlayerData[playerid][pCrashAngle] - gPlayerData[damagedid][pCrashAngle]) < 20.0 && (weaponid == 5 || weaponid == 6) && !AdminDuty[damagedid])
	{
		SetPlayerCameraPos(damagedid, gPlayerData[playerid][pCrashX], gPlayerData[playerid][pCrashY], gPlayerData[playerid][pCrashZ]+5.0);
		SetPlayerCameraLookAt( damagedid, gPlayerData[playerid][pCrashX], gPlayerData[playerid][pCrashY], gPlayerData[playerid][pCrashZ]+10.0 );	
		SetPlayerHealth(damagedid, 99999);
		ApplyAnimation(damagedid,"PED","FLOOR_hit",4.1,0,1,1,1,0);
		ApplyAnimation(damagedid,"PED","FLOOR_hit",4.1,0,1,1,1,0);
		TextDrawHideForPlayer(damagedid, Status[playerid]);
		SendClientMessage(damagedid, COLOR_RED, "[INFO:] Zosta³eœ napadniêty i jesteœ teraz nieprzytomny");
		BW(damagedid, 300);
	}
}

public OnPlayerTakeDamage(playerid, issuerid, Float:amount, weaponid)
{
	if(!gPlayerLogged[playerid])
		return 1;
	new Float:damage, damageType;
	static string[128];
	strdel(string, 0, sizeof(string));
	
    GetPlayerHealth(playerid, gPlayerData[playerid][pHP]);
	
	if(issuerid != INVALID_PLAYER_ID)
	{
		switch(GetPlayerWeapon(issuerid))
		{
			case 0: damage = 5;
			case 1: damage = 8;
			case 2,3,5,6,7: damage = 10;
			case 8: damage = 50;
			case 4: damage = 35;
			case 16: damage = 80;
			case 22: damage = 25;
			case 23: damage = 20;  	
			case 24: damage = 50;
			case 25: damage = 60;
			case 28,32: damage = 20; // Tec9 & Micru-Uzi
			case 29: damage = 30;
			case 30: damage = 30;
			case 31: damage = 27;
			case 33,34: damage = 95;
			case 35: damage = 250;
			case 38: damage = 0;
		}
		switch(GetPlayerWeapon(issuerid))
		{
			case 0..18:
			{
				damageType = 0;
			}
			default:
			{
				damageType = 1;
			}
		}
		if(gPlayerVars[playerid][mBulletProof])
			damage -= floatround(damage*0.25);
	}
	else
		damage = amount;
		
	if(gPlayerData[playerid][pDrunk] > 20.0 && gPlayerData[playerid][pDrunk] < 40.0)
		damage -= floatround(damage * 0.2);
	
	gPlayerData[playerid][pArmour]  -= damage;
	if(gPlayerData[playerid][pArmour] < 0.0)
	{
		RemovePlayerAttachedObject(playerid, MAX_PLAYER_ATTACHED_OBJECTS-5);
		gPlayerData[playerid][pHP] += gPlayerData[playerid][pArmour];
		if(gPlayerData[playerid][pHP] <= 0.0)
		{
			gPlayerData[playerid][pHP] = 0.0;
		}
		else if(gPlayerData[playerid][pHP] < 60.0 && damageType == 1)
		{
			ApplyAnimation(playerid, "SWEET", "Sweet_injuredloop", 4.1, 1, 0, 0, 1, 0, 1);
			defer InjuryEndAnimation(playerid);
		}
		gPlayerData[playerid][pArmour] = 0.0;
	}
	SetPlayerHealth(playerid, gPlayerData[playerid][pHP]);
	SetPlayerArmourEx(playerid, gPlayerData[playerid][pArmour]);
	
	if(gPlayerVars[playerid][mAntiCheatTimer] != -1)
	{
		KillTimer(gPlayerVars[playerid][mAntiCheatTimer]);
		gPlayerVars[playerid][mAntiCheatTimer] = -1;
	}
	gPlayerVars[playerid][mAntiCheatTimer] = SetTimerEx("antiHealthHack", 3000, false, "d", playerid);
	return 1;
}

public OnPlayerClickMap(playerid, Float:fX, Float:fY, Float:fZ)
{
	if(gPlayerData[playerid][pAdmin])
		SetPlayerPosFindZ(playerid, fX, fY, fZ);
	return 1;
}