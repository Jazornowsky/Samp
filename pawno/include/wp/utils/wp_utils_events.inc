stock PrepareEvent(eventId)
{
	switch(eventId)
	{
		case 1:
		{
			gEvent1isRunning = 1;
			
			for(new i = 0; i < CUSTOM_MAX_PLAYERS; i++)
			{
				gEvent1players[i] = -1;
			}
			
		}
		case 2:
		{
			gEvent2isRunning = 1;
			
			for(new i = 0; i < CUSTOM_MAX_PLAYERS; i++)
			{
				gEvent2players[i] = -1;
				gEvent2winners[i] = -1;
				gEvent2playersPoints[i] = 0;
			}
		}
	}
}

stock StartEvent(eventId)
{
	switch(eventId)
	{
		case 1:
		{
			new spawnId = 0, rand = random(7);
		
			gEvent1isStarted = 1;
			
			gEvent1objects[0] = CreateDynamicObject(971, 96.70, 1920.10, 20.80, 0.00, 0.00, 269.00, EVENT1WORLD);
			gEvent1objects[1] = CreateDynamicObject(8210, 269.60, 1882.30, 16.10, 270.00, 179.92, 269.67,EVENT1WORLD);
			gEvent1objects[2] = CreateDynamicObject(3055, 213.90, 1875.60, 13.10, 0.00, 0.00, 0.00,EVENT1WORLD);
			gEvent1objects[3] = CreateDynamicObject(1557, 233.73, 1821.37, 6.41, 0.00, 0.00, 90.00,EVENT1WORLD);
			gEvent1objects[4] = CreateDynamicObject(3036, 226.50, 1870.90, 14.50, 0.00, 0.00, 90.00,EVENT1WORLD);
			gEvent1objects[5] = CreateDynamicObject(18769, 238.06, 1795.42, 13.23, 0.00, 90.00, 0.00,EVENT1WORLD);
			gEvent1objects[6] = CreateDynamicObject(1557, 233.75, 1824.34, 6.41, 0.00, 0.00, -90.72,EVENT1WORLD);
			
			gEvent1cp[0] = CreateDynamicCP(225.1409, 1870.8571, 13.7421, 1.0, EVENT1WORLD);
			gEvent1cp[0] = CreateDynamicCP(239.8673, 1801.5189, 7.4141, 1.0, EVENT1WORLD);
			gEvent1cp[0] = CreateDynamicCP(234.1828, 1820.9523, 7.4141, 1.0, EVENT1WORLD);
			
			gEvent1codePickups[0] = CreateDynamicPickup(1277, 19, gEvent1pickupsLvl1[rand][0], gEvent1pickupsLvl1[rand][1], gEvent1pickupsLvl1[rand][2], EVENT1WORLD);
			gEvent1codePickups[1] = CreateDynamicPickup(1277, 19, gEvent1pickupsLvl2[rand][0], gEvent1pickupsLvl2[rand][1], gEvent1pickupsLvl2[rand][2], EVENT1WORLD);
			gEvent1codePickups[2] = CreateDynamicPickup(1277, 19, gEvent1pickupsLvl3[rand][0], gEvent1pickupsLvl3[rand][1], gEvent1pickupsLvl3[rand][2], EVENT1WORLD);

			gEvent1pickup = CreateDynamicPickup(19343, 2, 212.4128,1822.8239,6.4141, EVENT1WORLD);
			
			gEvent1cp[0] = CreateDynamicCP(225.1409, 1870.8571, 13.7421, 1.0, EVENT1WORLD);
			gEvent1cp[1] = CreateDynamicCP(239.8673, 1801.5189, 7.4141 , 1.0, EVENT1WORLD);
			gEvent1cp[2] = CreateDynamicCP(234.1828, 1820.9523, 7.4141 , 1.0, EVENT1WORLD);
			
			for(new i = 0; i < sizeof(gEvent1code); i++)
			{
				gEvent1code[i] = random(3000) + random(3000) + 1111;
			}
			
			for(new i = 0; i < sizeof(gEvent1players); i++)
			{
				if(gEvent1players[i] == -1)
				{
					continue;
				}
				
				if(spawnId == sizeof(gEvent1spawns)-1)
				{
					spawnId = 0;
				}
				else
				{
					spawnId++;
				}
				
				GetPlayerPos(gEvent1players[i], gEventplayerData[i][mPosX], gEventplayerData[i][mPosY], gEventplayerData[i][mPosZ]);
				gEventplayerData[i][mWorld] = GetPlayerVirtualWorld(gEvent1players[i]);
				gEventplayerData[i][mInterior] = GetPlayerInterior(gEvent1players[i]);
				
				SetPlayerToPos(gEvent1players[i], gEvent1spawns[spawnId][0], gEvent1spawns[spawnId][1], gEvent1spawns[spawnId][2]);
				SetPlayerFacingAngle(gEvent1players[i], gEvent1spawns[spawnId][3]);
				SetPlayerInterior(gEvent1players[i], 0);
				SetPlayerVirtualWorld(gEvent1players[i], EVENT1WORLD);
				TogglePlayerControllable(gEvent1players[i], 0);
				SetCameraBehindPlayer(gEvent1players[i]);
				
				ShowPlayerDialog(gEvent1players[i], DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacje o evencie",
					"Celem tego eventu jest dostanie siê do pomieszczenia kontrolnego w strefie 51.\nAby to osi¹gn¹æ nale¿y przedostaæ siê przez zaryglowane drzwi wpisuj¹c w nie kod.\nKody poukrywane s¹ w ró¿nych czêœciach bazy.",
					"Zamknij", "");
			}
			
			gEvent1timeToStart = 20;
			
			return;
		}
		case 2:
		{
			new spawnId = 0;
			
			gEvent2isStarted = 1;
			
			
			SetVehicleToPos(280, gEvent2vehSpawns[0][0], gEvent2vehSpawns[0][1], gEvent2vehSpawns[0][2]);
			LinkVehicleToInterior(280, EVENT2INT);
			SetVehicleVirtualWorld(280, EVENT2WORLD);
			SetVehicleZAngle(280, gEvent2vehSpawns[0][3]);
			
			SetVehicleToPos(281, gEvent2vehSpawns[1][0], gEvent2vehSpawns[1][1], gEvent2vehSpawns[1][2]);
			LinkVehicleToInterior(281, EVENT2INT);
			SetVehicleVirtualWorld(281, EVENT2WORLD);
			SetVehicleZAngle(281, gEvent2vehSpawns[1][3]);
			
			SetVehicleToPos(282, gEvent2vehSpawns[2][0], gEvent2vehSpawns[2][1], gEvent2vehSpawns[2][2]);
			LinkVehicleToInterior(282, EVENT2INT);
			SetVehicleVirtualWorld(282, EVENT2WORLD);
			SetVehicleZAngle(282, gEvent2vehSpawns[2][3]);
			
			SetVehicleToPos(283, gEvent2vehSpawns[3][0], gEvent2vehSpawns[3][1], gEvent2vehSpawns[3][2]);
			LinkVehicleToInterior(283, EVENT2INT);
			SetVehicleVirtualWorld(283, EVENT2WORLD);
			SetVehicleZAngle(283, gEvent2vehSpawns[3][3]);
			
			SetVehicleToPos(284, gEvent2vehSpawns[4][0], gEvent2vehSpawns[4][1], gEvent2vehSpawns[4][2]);
			LinkVehicleToInterior(284, EVENT2INT);
			SetVehicleVirtualWorld(284, EVENT2WORLD);
			SetVehicleZAngle(284, gEvent2vehSpawns[4][3]);
			
			SetVehicleToPos(285, gEvent2vehSpawns[5][0], gEvent2vehSpawns[5][1], gEvent2vehSpawns[5][2]);
			LinkVehicleToInterior(285, EVENT2INT);
			SetVehicleVirtualWorld(285, EVENT2WORLD);
			SetVehicleZAngle(285, gEvent2vehSpawns[5][3]);
			
			SetVehicleToPos(286, gEvent2vehSpawns[6][0], gEvent2vehSpawns[6][1], gEvent2vehSpawns[6][2]);
			LinkVehicleToInterior(286, EVENT2INT);
			SetVehicleVirtualWorld(286, EVENT2WORLD);
			SetVehicleZAngle(286, gEvent2vehSpawns[6][3]);
			
			SetVehicleToPos(287, gEvent2vehSpawns[7][0], gEvent2vehSpawns[7][1], gEvent2vehSpawns[7][2]);
			LinkVehicleToInterior(287, EVENT2INT);
			SetVehicleVirtualWorld(287, EVENT2WORLD);
			
			
			for(new i = 0; i < sizeof(gEvent2players); i++)
			{
				if(gEvent2players[i] == -1)
				{
					continue;
				}
				
				if(spawnId == sizeof(gEvent2spawns)-1)
				{
					spawnId = 0;
				}
				else
				{
					spawnId++;
				}
				
				GetPlayerPos(gEvent2players[i], gEventplayerData[i][mPosX], gEventplayerData[i][mPosY], gEventplayerData[i][mPosZ]);
				gEventplayerData[i][mWorld] = GetPlayerVirtualWorld(gEvent2players[i]);
				gEventplayerData[i][mInterior] = GetPlayerInterior(gEvent2players[i]);
				
				SetPlayerInterior(gEvent2players[i], EVENT2INT);
				SetPlayerToPos(gEvent2players[i], gEvent2spawns[spawnId][0], gEvent2spawns[spawnId][1], gEvent2spawns[spawnId][2]);
				SetPlayerVirtualWorld(gEvent2players[i], EVENT2WORLD);
				SetPlayerFacingAngle(gEvent2players[i], gEvent2spawns[spawnId][3]);
				
				PutPlayerIntoVehicle(gEvent2players[i], 280+spawnId, 0);
				
				TogglePlayerControllable(gEvent2players[i], 0);
				SetCameraBehindPlayer(gEvent2players[i]);
				
				ShowPlayerDialog(gEvent2players[i], DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacje o evencie",
					"U¿ywaj strza³ek na klawiaturze numerycznej.\nStrza³eczka na ekranie z zielon¹ gwiazdk¹ oznacza odpowiedni¹ nute.\nZasady s¹ proste: ruchy w rytm = +1pkt, niepoprawny ruch = -2pkt.",
					"Zamknij", "");
			}
			
			gEvent2timeToStart = 30;
			
			SetVehicleZAngle(280, gEvent2vehSpawns[0][3]);
			SetVehicleZAngle(281, gEvent2vehSpawns[1][3]);
			SetVehicleZAngle(282, gEvent2vehSpawns[2][3]);
			SetVehicleZAngle(283, gEvent2vehSpawns[3][3]);
			SetVehicleZAngle(284, gEvent2vehSpawns[4][3]);
			SetVehicleZAngle(285, gEvent2vehSpawns[5][3]);
			SetVehicleZAngle(286, gEvent2vehSpawns[6][3]);
			SetVehicleZAngle(287, gEvent2vehSpawns[7][3]);
		}
	}
}

stock BeginEvent(eventId)
{
	switch(eventId)
	{
		case 1:
		{
			for(new i = 0; i < sizeof(gEvent1players); i++)
			{
				if(gEvent1players[i] != -1)
				{
					TogglePlayerControllable(gEvent1players[i], 1);
					GameTextForPlayer(gEvent1players[i], "~g~Event rozpoczety !~n~POWODZENIA !", 4000, 6);
				}
			}
		}
		case 2:
		{
			for(new i = 0; i < sizeof(gEvent2players); i++)
			{
				if(gEvent2players[i] != -1)
				{
					gEvent2currentNote = random(4);
					gEvent2noteProgress = 0;
					gEvent2timeToEnd = 240;
					
					TogglePlayerControllable(gEvent2players[i], 1);
					
					GameTextForPlayer(gEvent2players[i], "~g~Event rozpoczety !~n~POWODZENIA !", 1000, 6);
					
					UpdateEventNote();
					
					TextDrawShowForPlayer(gEvent2players[i], gEvent2noteText1);
					PlayerTextDrawShow(gEvent2players[i], gEvent2noteText2[gEvent2players[i]]);
				}
			}
		}
	}
}

stock EndEvent(eventId)
{
	switch(eventId)
	{
		case 1:
		{
			DestroyDynamicPickup(gEvent1pickup);
			
			RemovePlayersFromEvent(eventId);
			
			for(new i = 0; i < sizeof(gEvent1objects); i++)
			{
				DestroyDynamicObject(gEvent1objects[i]);
			}
			
			for(new i = 0; i < sizeof(gEvent1cp); i++)
			{
				DestroyDynamicCP(gEvent1cp[i]);
			}
			
			for(new i = 0; i < sizeof(gEvent1codePickups); i++)
			{
				DestroyDynamicPickup(gEvent1codePickups[i]);
			}
			
			gEvent1isStarted = 0;
			gEvent1isRunning = 0;
			gEvent1timeToJoin = 0;
			gEvent1timeToStart = 0;
		}
		case 2:
		{
			new highestPoints = 0, winners = 0, string[128];
			for(new i = 0; i < CUSTOM_MAX_PLAYERS; i++)
			{
				if(gEvent2players[i] == -1)
				{
					continue;
				}
				
				if(highestPoints < gEvent2playersPoints[i])
				{
					highestPoints = gEvent2playersPoints[i];
				}
			}
			
			if(highestPoints != 0)
			{
				for(new i = 0; i < CUSTOM_MAX_PLAYERS; i++)
				{
					if(gEvent2players[i] == -1)
					{
						continue;
					}
					
					GameTextForPlayer(gEvent2players[i], "Koniec eventu ! Przegrales !", 5000, 6);
					
					if(gEvent2playersPoints[i] == highestPoints)
					{
						gEvent2winners[winners] = gEvent2players[i];
						winners++;
					}
					
				}
				
				for(new i = 0; i < winners; i++)
				{
					if(winners > 1)
					{
						GivePlayerCash(gEvent2winners[i], floatround(gEvent2prize/winners));
						format(string, sizeof(string), "Wygrales $%d !", floatround(gEvent2prize/winners));
					}
					else
					{
						GivePlayerCash(gEvent2winners[i], gEvent2prize);
						format(string, sizeof(string), "Wygrales $%d !", gEvent2prize);
					}
					GameTextForPlayer(gEvent2winners[i], string, 5000, 6);
				}
			}
			
			RemovePlayersFromEvent(eventId);
			
			gEvent2isStarted = 0;
			gEvent2isRunning = 0;
			gEvent2timeToJoin = 0;
			gEvent2timeToStart = 0;
			gEvent2currentNote = 0;
			gEvent2noteProgress = 0;
			gEvent2timeToEnd = 0;
		}
	}
}

stock ResetEventsVariables()
{
	for(new i = 0; i < sizeof(gEvent1players); i++)
	{
		if(gEvent1players[i] != -1)
		{
			gEvent1players[i] = -1;
		}
	}
	for(new i = 0; i < sizeof(gEvent2players); i++)
	{
		if(gEvent2players[i] != -1)
		{
			gEvent2players[i] = -1;
		}
	}
}

stock RemovePlayersFromEvent(eventId)
{
	switch(eventId)
	{
		case 1:
		{
			for(new i = 0; i < sizeof(gEvent1players); i++)
			{
				if(gEvent1players[i] != -1)
				{
					if(gEvent1isStarted)
					{
						SetPlayerToPos(gEvent1players[i], gEventplayerData[i][mPosX], gEventplayerData[i][mPosY], gEventplayerData[i][mPosZ]);
						SetPlayerVirtualWorld(gEvent1players[i], gEventplayerData[i][mWorld]);
						SetPlayerInterior(gEvent1players[i], gEventplayerData[i][mInterior]);
					}
					
					gEvent1players[i] = -1;
				}
			}
		}
		case 2:
		{
			for(new i = 0; i < sizeof(gEvent2players); i++)
			{
				if(gEvent2players[i] != -1)
				{
					if(gEvent2isStarted)
					{
						SetPlayerToPos(gEvent2players[i], gEventplayerData[i][mPosX], gEventplayerData[i][mPosY], gEventplayerData[i][mPosZ]);
						SetPlayerVirtualWorld(gEvent2players[i], gEventplayerData[i][mWorld]);
						SetPlayerInterior(gEvent2players[i], gEventplayerData[i][mInterior]);
						SetCameraBehindPlayer(gEvent2players[i]);
					}
					
					TextDrawHideForPlayer(gEvent2players[i], gEvent2noteText1);
					PlayerTextDrawHide(gEvent2players[i], gEvent2noteText2[gEvent2players[i]]);
					
					gEvent2players[i] = -1;
				}
			}
		}
	}
}

stock RemovePlayerFormEvents(playerid)
{
	for(new i = 0; i < sizeof(gEvent1players); i++)
	{
		if(gEvent1players[i] == playerid)
		{
			if(gEvent1isStarted)
			{
				SetPlayerToPos(playerid, gEventplayerData[i][mPosX], gEventplayerData[i][mPosY], gEventplayerData[i][mPosZ]);
				SetPlayerVirtualWorld(playerid, gEventplayerData[i][mWorld]);
				SetPlayerInterior(playerid, gEventplayerData[i][mInterior]);
			}
			
			gEvent1players[i] = -1;
		}
		if(gEvent2players[i] == playerid)
		{
			if(gEvent2isStarted)
			{
				SetPlayerToPos(playerid, gEventplayerData[i][mPosX], gEventplayerData[i][mPosY], gEventplayerData[i][mPosZ]);
				SetPlayerVirtualWorld(playerid, gEventplayerData[i][mWorld]);
				SetPlayerInterior(playerid, gEventplayerData[i][mInterior]);
			}
			
			TextDrawHideForPlayer(playerid, gEvent2noteText1);
			PlayerTextDrawHide(playerid, gEvent2noteText2[playerid]);
			
			gEvent2players[i] = -1;
		}
	}
}

stock SendMessageToEvent(eventId, color, string[])
{
	switch(eventId)
	{
		case 1:
		{
			for(new i = 0; i < sizeof(gEvent1players); i++)
			{
				if(gEvent1players[i] != -1)
				{
					SendClientMessage(gEvent1players[i], color, string);
				}
			}
		}
	}
}

stock UpdateEventNote()
{
	new string[32];
	
	format(string, sizeof(string), "_");
	
	gEvent2noteProgress++;
	
	if(gEvent2noteProgress == 4)
	{
		gEvent2noteProgress = 0;
		gEvent2currentNote = random(4);
		gEvent2noteProgressStar = random(4);
		
		for(new i = 0; i < sizeof(gEvent2players); i++)
		{
			if(gEvent2players[i] == -1)
			{
				continue;
			}
			
			PlayerPlaySound(gEvent2players[i], 1130, 0.0, 0.0, 10.0);
			
			GetPlayerPos(gEvent2players[i], gPlayerData[gEvent2players[i]][pCrashX], gPlayerData[gEvent2players[i]][pCrashY],gPlayerData[gEvent2players[i]][pCrashZ]);
		
			switch(random(3)) 
			{
				case 0:
				{
				   ApplyAnimation(gEvent2players[i], "LOWRIDER", "lrgirl_l3_loop", 4.0, 1, 0, 0, 0, 0);
				}
				case 1:
				{
					ApplyAnimation(gEvent2players[i], "LOWRIDER", "lrgirl_l4_loop", 4.0, 1, 0, 0, 0, 0);
				}
				case 2:
				{
					ApplyAnimation(gEvent2players[i], "LOWRIDER", "lrgirl_l5_loop", 4.0, 1, 0, 0, 0, 0);
				}
			}
			
			switch(random(6)) 
			{
				case 0: 
				{
					SetPlayerCameraPos(gEvent2players[i], gPlayerData[gEvent2players[i]][pCrashX]+5,gPlayerData[gEvent2players[i]][pCrashY],gPlayerData[gEvent2players[i]][pCrashZ]+1);
					SetPlayerCameraLookAt(gEvent2players[i], gPlayerData[gEvent2players[i]][pCrashX],gPlayerData[gEvent2players[i]][pCrashY],gPlayerData[gEvent2players[i]][pCrashZ]);
				}
				case 1: 
				{
					SetPlayerCameraPos(gEvent2players[i], gPlayerData[gEvent2players[i]][pCrashX]+5,gPlayerData[gEvent2players[i]][pCrashY]+4,gPlayerData[gEvent2players[i]][pCrashZ]+1);
					SetPlayerCameraLookAt(gEvent2players[i], gPlayerData[gEvent2players[i]][pCrashX],gPlayerData[gEvent2players[i]][pCrashY],gPlayerData[gEvent2players[i]][pCrashZ]);
				}
				case 2: 
				{
					SetPlayerCameraPos(gEvent2players[i], gPlayerData[gEvent2players[i]][pCrashX]+3,gPlayerData[gEvent2players[i]][pCrashY],gPlayerData[gEvent2players[i]][pCrashZ]+1);
					SetPlayerCameraLookAt(gEvent2players[i], gPlayerData[gEvent2players[i]][pCrashX],gPlayerData[gEvent2players[i]][pCrashY],gPlayerData[gEvent2players[i]][pCrashZ]);
				}
				case 3: 
				{
					SetPlayerCameraPos(gEvent2players[i], gPlayerData[gEvent2players[i]][pCrashX]+3,gPlayerData[gEvent2players[i]][pCrashY],gPlayerData[gEvent2players[i]][pCrashZ]+2);
					SetPlayerCameraLookAt(gEvent2players[i], gPlayerData[gEvent2players[i]][pCrashX],gPlayerData[gEvent2players[i]][pCrashY],gPlayerData[gEvent2players[i]][pCrashZ]);
				}
				case 4: 
				{
					SetPlayerCameraPos(gEvent2players[i], gPlayerData[gEvent2players[i]][pCrashX],gPlayerData[gEvent2players[i]][pCrashY]+2,gPlayerData[gEvent2players[i]][pCrashZ]+9);
					SetPlayerCameraLookAt(gEvent2players[i], gPlayerData[gEvent2players[i]][pCrashX],gPlayerData[gEvent2players[i]][pCrashY],gPlayerData[gEvent2players[i]][pCrashZ]);
				}
				case 5: 
				{
					SetPlayerCameraPos(gEvent2players[i], gPlayerData[gEvent2players[i]][pCrashX],gPlayerData[gEvent2players[i]][pCrashY]+2,gPlayerData[gEvent2players[i]][pCrashZ]+2);
					SetPlayerCameraLookAt(gEvent2players[i], gPlayerData[gEvent2players[i]][pCrashX],gPlayerData[gEvent2players[i]][pCrashY],gPlayerData[gEvent2players[i]][pCrashZ]);
				}
			}
		}
	}
	
	switch(gEvent2currentNote)
	{
		case 0:
		{
			switch(gEvent2noteProgress)
			{
				case 0:
				{
					format(string, sizeof(string), "~n~~n~            ~u~");
				}
				case 1:
				{
					format(string, sizeof(string), "~n~~n~        ~u~");
				}
				case 2:
				{
					format(string, sizeof(string), "~n~~n~    ~u~");
				}
				case 3:
				{
					format(string, sizeof(string), "~n~~n~~u~");
				}
			}
		}
		case 1:
		{
			switch(gEvent2noteProgress)
			{
				case 0:
				{
					format(string, sizeof(string), "~n~~n~            ~d~");
				}
				case 1:
				{
					format(string, sizeof(string), "~n~~n~        ~d~");
				}
				case 2:
				{
					format(string, sizeof(string), "~n~~n~   ~d~");
				}
				case 3:
				{
					format(string, sizeof(string), "~n~~n~~d~");
				}
			}
		}
		case 2:
		{
			switch(gEvent2noteProgress)
			{
				case 0:
				{
					format(string, sizeof(string), "~n~~n~            ~>~");
				}
				case 1:
				{
					format(string, sizeof(string), "~n~~n~        ~>~");
				}
				case 2:
				{
					format(string, sizeof(string), "~n~~n~    ~>~");
				}
				case 3:
				{
					format(string, sizeof(string), "~n~~n~~>~");
				}
			}
		}
		case 3:
		{
			switch(gEvent2noteProgress)
			{
				case 0:
				{
					format(string, sizeof(string), "~n~~n~            ~<~");
				}
				case 1:
				{
					format(string, sizeof(string), "~n~~n~        ~<~");
				}
				case 2:
				{
					format(string, sizeof(string), "~n~~n~    ~<~");
				}
				case 3:
				{
					format(string, sizeof(string), "~n~~n~~<~");
				}
			}
		}
	}
	
	if(gEvent2noteProgressStar == gEvent2noteProgress)
	{
		strcat(string, "~g~]");
	}
	
	TextDrawSetString(gEvent2noteText1, string);
}