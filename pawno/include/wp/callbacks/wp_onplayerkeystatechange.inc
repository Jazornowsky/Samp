/***
*
* File: wp_onplayerkeystatechange.inc
* Auth: Damian Wojdat
* Date: 11.03.2012
* Desc: OnPlayerKeyStateChange function.
*
*************************************************************************************************************/

public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	//new key, ud, lr;
	//GetPlayerKeys(playerid, key, ud, lr);
	//format(tmpstring, sizeof(tmpstring), "Klawisz: %d", key);
	//SendClientMessage(playerid, 0xFFFFFFFF, tmpstring);
	static string[256];
	
	
	// AFK status update
	format(string, sizeof(string), "{33CCFF}");
	
	UpdateDynamic3DTextLabelText(playerAFK[playerid], COLOR_BLACK, string);
	// end fo AFK status update
	
	if(IsPlayerInAnyVehicle(playerid) && GetPlayerState(playerid) == 2)
	{
	   	if(!IsAPlane(GetPlayerVehicleID(playerid)) && !IsABoat(GetPlayerVehicleID(playerid)))
	   	{
	      	new vid = GetPlayerVehicleID(playerid);
	  	 	if(newkeys & ( KEY_LOOK_LEFT ) && newkeys & ( KEY_LOOK_RIGHT ))
			{
		    	if(Indicators_xqz[vid][2] /*|| Indicators_xqz[vid][5]*/) DestroyObject(Indicators_xqz[vid][5]),DestroyObject(Indicators_xqz[vid][2]), DestroyObject(Indicators_xqz[vid][3]),Indicators_xqz[vid][2]=0;
            	else if(Indicators_xqz[vid][0] /*|| Indicators_xqz[vid][4]*/) DestroyObject(Indicators_xqz[vid][4]),DestroyObject(Indicators_xqz[vid][0]), DestroyObject(Indicators_xqz[vid][1]),Indicators_xqz[vid][0]=0;
				else
				SetVehicleIndicator(vid,1,1);
				return 1;
			}
			if(newkeys & KEY_LOOK_RIGHT)
			{
	  		  	if(Indicators_xqz[vid][0] /*|| Indicators_xqz[vid][4]*/) DestroyObject(Indicators_xqz[vid][4]), DestroyObject(Indicators_xqz[vid][0]), DestroyObject(Indicators_xqz[vid][1]),Indicators_xqz[vid][0]=0;
      	      	else if(Indicators_xqz[vid][2]/*|| Indicators_xqz[vid][5]*/) DestroyObject(Indicators_xqz[vid][5]), DestroyObject(Indicators_xqz[vid][2]), DestroyObject(Indicators_xqz[vid][3]),Indicators_xqz[vid][2]=0;
				else
				SetVehicleIndicator(vid,0,1);
			}
			if(newkeys & KEY_LOOK_LEFT)
			{
			    if(Indicators_xqz[vid][2]/*|| Indicators_xqz[vid][5]*/) DestroyObject(Indicators_xqz[vid][5]),DestroyObject(Indicators_xqz[vid][2]), DestroyObject(Indicators_xqz[vid][3]),Indicators_xqz[vid][2]=0;
      	      	else if(Indicators_xqz[vid][0] /*|| Indicators_xqz[vid][4]*/) DestroyObject(Indicators_xqz[vid][4]),DestroyObject(Indicators_xqz[vid][0]), DestroyObject(Indicators_xqz[vid][1]),Indicators_xqz[vid][0]=0;
				else
				SetVehicleIndicator(vid,1,0);
			}
		}
	}
	
	if(gEvent2timeToEnd)
	{
		new inGameId = -1;
		
		for(new i = 0; i < sizeof(gEvent2players); i++)
		{
			if(gEvent2players[i] == playerid)
			{
				inGameId = i;
				break;
			}
		}
		
		if(inGameId != -1)
		{
			if(newkeys & KEY_ANALOG_UP)
			{
				if(gEvent2currentNote != 0 || gEvent2noteProgress != gEvent2noteProgressStar)
				{
					gEvent2playersPoints[inGameId] -= 2;
					GameTextForPlayer(gEvent2players[inGameId], "~r~ZLE!", 2500, 6);
				}
				else
				{
					gEvent2playersPoints[inGameId] += 1;
					GameTextForPlayer(gEvent2players[inGameId], "~g~DOBRZE!", 2500, 6);
				}
			}
			if(newkeys & KEY_ANALOG_DOWN)
			{
				if(gEvent2currentNote != 1 || gEvent2noteProgress != gEvent2noteProgressStar)
				{
					gEvent2playersPoints[inGameId] -= 2;
					GameTextForPlayer(gEvent2players[inGameId], "~r~ZLE!", 2500, 6);
				}
				else
				{
					gEvent2playersPoints[inGameId] += 1;
					GameTextForPlayer(gEvent2players[inGameId], "~g~DOBRZE!", 2500, 6);
				}
			}
			if(newkeys & KEY_ANALOG_RIGHT)
			{
				if(gEvent2currentNote != 2 || gEvent2noteProgress != gEvent2noteProgressStar)
				{
					gEvent2playersPoints[inGameId] -= 2;
					GameTextForPlayer(gEvent2players[inGameId], "~r~ZLE!", 2500, 6);
				}
				else
				{
					gEvent2playersPoints[inGameId] += 1;
					GameTextForPlayer(gEvent2players[inGameId], "~g~DOBRZE!", 2500, 6);
				}
			}
			if(newkeys & KEY_ANALOG_LEFT)
			{
				if(gEvent2currentNote != 3 || gEvent2noteProgress != gEvent2noteProgressStar)
				{
					gEvent2playersPoints[inGameId] -= 2;
					GameTextForPlayer(gEvent2players[inGameId], "~r~ZLE!", 2500, 6);
				}
				else
				{
					gEvent2playersPoints[inGameId] += 1;
					GameTextForPlayer(gEvent2players[inGameId], "~g~DOBRZE!", 2500, 6);
				}
			}
			
			if(gEvent2playersPoints[inGameId] < 0)
			{
				gEvent2playersPoints[inGameId] = 0;
			}
			
			format(string, sizeof(string), "Punkty: %d", gEvent2playersPoints[inGameId]);
			PlayerTextDrawSetString(playerid, gEvent2noteText2[playerid], string);
		}
	}
	
	if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
	{
		if(PRESSED(LIGHT_KEY))
		{
			if(IsPlayerInAnyVehicle(playerid) && GetPlayerVehicleSeat(playerid) == 0)
			{
				new carid = GetPlayerVehicleID(playerid);
				new enginedyn,lights,alarm,bonnet,boot,objective;
				new doors;
				GetVehicleParamsEx(carid, enginedyn, lights, alarm, doors, bonnet, boot, objective);
				if(IsAPlane(carid) || IsAHelicopter(carid))
				{
					SetVehicleParamsEx(carid,enginedyn,0,alarm,doors,bonnet,boot,objective);
					gVehData[carid-1][LightsOn] = 0;
					SaveVehData(carid-1, "LightsOn");
				}
				else
				{
					switch(gVehData[carid-1][LightsOn])
					{
						case -1:
						{
							SetVehicleParamsEx(carid, enginedyn, 0, alarm, doors, bonnet, boot, objective);
							
							gVehData[carid-1][LightsOn] = 0;
							if(gVehData[carid-1][mVehType] == 0)
							{
								SaveVehData(carid-1, "LightsOn");
							}
						}
						case 0:
						{
							SetVehicleParamsEx(carid, enginedyn, 1, alarm, doors, bonnet, boot, objective);
							
							gVehData[carid-1][LightsOn] = 1;
							if(gVehData[carid-1][mVehType] == 0)
							{
								SaveVehData(carid-1, "LightsOn");
							}
						}
						case 1:
						{
							SetVehicleParamsEx(carid,enginedyn,0, alarm, doors, bonnet, boot, objective);
							
							gVehData[carid-1][LightsOn] = 0;
							if(gVehData[carid-1][mVehType] == 0)
							{
								SaveVehData(carid-1, "LightsOn");
							}
						}
					}
				}
			}
		}
		if(newkeys & KEY_SECONDARY_ATTACK)
		{
			if(!IsPlayerInRangeOfPoint(playerid, 100.0, 617.5380, -1.9900, 1000.6829))
			{
				if(!PlayerCuffed[playerid])
				{
					if(gVehData[GetPlayerVehicleID(playerid)-1][EngineOn] == 0 && EngineTurningOn[playerid] == 0)
					{
						RemoveDriverFromVehicle(playerid);
					}
				}
			}
		}
		if(newkeys & KEY_FIRE)
		{
			new vehid = GetPlayerVehicleID(playerid)-1;
			if(vehid != -1)
			{
				if(gVehData[vehid][mVehSirenState])
					DismountSirenFromVehicle(vehid);
				else
				MountSirenToVehicle(vehid);
			}
		}
	}
	else if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
	{
		if((newkeys & KEY_FIRE || newkeys & KEY_JUMP) && gPlayerData[playerid][pDrunk] > 40.0)
			ApplyAnimation(playerid,"PAULNMAC","PnM_Argue1_A",4.1,0,1,1,0,4100);
		if(newkeys & KEY_HANDBRAKE)
		{
			if(GetPlayerWeapon(playerid) == Speedgun && gPlayerData[playerid][pFaction] != 255)
			{
				if(DynamicFactions[gPlayerData[playerid][pFaction]][fType] == 1)
					defer GetPlayerSpeed(playerid);
			}
			if(gIsOnAShip[playerid] != -1)
			{
				new Float:pX, Float:pY, Float:pZ, Float:pA;
				new Float:rOX, Float:rOY, Float:rOZ;
				new pointCorrect;
				GetPlayerCameraFrontVector(playerid, pX, pY, pZ);
				GetPosFromView(playerid, gShipSight[playerid], pX, pY, pZ);
				for(new i = 0; i < sizeof(gAreasWater); i++)
				{
					if(!IsPointInArea(gAreasWater[i][minX], gAreasWater[i][minY], gAreasWater[i][maxX], gAreasWater[i][maxY], pX, pY))
						continue;
					else
					{
						pointCorrect = 1;
						TurnPlayerFaceToPos(playerid, pX, pY);
						GetPlayerFacingAngle(playerid, pA);
						GetObjectRot(gIsOnAShip[playerid], rOX, rOY, rOZ);
						pA = floatabs(pA-rOZ);
						MoveObject(gShips[gIsOnAShip[playerid]][shipObjID], pX, pY, gShips[gIsOnAShip[playerid]][shipZ], 5.8, 0.0, 0.0, pA);
						gShips[gIsOnAShip[playerid]][shipX] = pX;
						gShips[gIsOnAShip[playerid]][shipY] = pY;
					}
				}
				if(!pointCorrect)
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz tam p³yn¹æ !");					
			}
		}
		if(newkeys & KEY_JUMP)
		{
			if(PlayerCuffed[playerid])
			{
				gPlayerVars[playerid][mJumped] = 0;
				ApplyAnimation(playerid,"PED","FLOOR_hit_f",4.0,0,1,1,1,0);
			}
			else
				gPlayerVars[playerid][mJumped] += 2;
		}
		if(newkeys & KEY_FIRE)
		{
			if(GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_SMOKE_CIGGY)
			{
				GetPlayerHealth(playerid, gPlayerData[playerid][pHP]);
				SetPlayerWeatherEx(playerid, 45);
				if(gPlayerData[playerid][pHP] < 145.0)
				{
					gPlayerData[playerid][pHP] += 5.0;
					SavePlayerData(playerid, "HP");
					SetPlayerHealth(playerid, gPlayerData[playerid][pHP]);
				}
			}
		}
		if (!(newkeys & KEY_SPRINT) && oldkeys & KEY_SPRINT)
		{
			if(gPlayerVars[playerid][mAtClotheStore])
			{
				new slot = BizHaveItem(gPlayerVars[playerid][mAtBizID], 3, 24);
				new itemPrice = BizItemSlotPrice(gPlayerVars[playerid][mAtBizID], slot);
				
				if(BizItemSlotCount(gPlayerVars[playerid][mAtBizID], slot) <= 0)
				{
					ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Niestety wszystkie ubrania zosta³y wykupione.", "Zamknij", "");
					return 1;
				}
				
				if(GetPlayerCash(playerid) < itemPrice)
				{
					ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Nie masz wystarczaj¹cej iloœci pieniêdzy.", "Zamknij", "");
					return 1;
				}
				
				new param1;
				
				if(gPlayerData[playerid][pSex] == 1)
				{
					param1 = MaleSkins[gPlayerVars[playerid][mClotheShopSkinId]];
				}
				else
				{
					param1 = FemaleSkins[gPlayerVars[playerid][mClotheShopSkinId]];
				}
				
				new pSlot = InsertPlayerItemEx(playerid, 3, 24, param1, 0, 0, 0, "Puste", 1);
				
				if(pSlot == 0)
				{
					ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Nie masz miejsca na ubranie !", "Zamknij", "");
					return 1;
				}
				
				SetBizItemSlotCount(gPlayerVars[playerid][mAtBizID], slot, BizItemSlotCount(gPlayerVars[playerid][mAtBizID], slot)-1);
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Kupi³eœ ubranie.\nZosta³o ono przeniesione do twojego baga¿u.", "Zamknij", "");
			}
		}
		if(newkeys & KEY_SPRINT)
		{
			if(!gPlayerVars[playerid][mAtClotheStore] && gPlayerData[playerid][pAdmin] == 0)
			{
				if(gPlayerVars[playerid][mSprinting] == 0)
				{
					format(string, sizeof(string), "[INFO:] Gracz: %s [%d] sprintuje", gPlayerData[playerid][pName], playerid);
					ABroadCast(COLOR_YELLOW, string, 1);
				}
				gPlayerVars[playerid][mSprinting] = 3;
			}
		}
		if(newkeys & KEY_YES)
		{
			if(gIsOnAShip[playerid] != -1)
			{
				if(gShipSight[playerid] > 10.0)
					gShipSight[playerid] += 5.0;
				else if(gShipSight[playerid] <= 10.0)
					gShipSight[playerid] += 1.0;
				format(string, sizeof(string), "[INFO:] Zasiêg przemieszczenia zwiêkszony do %fm", gShipSight[playerid]);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			}
			else
			{
				if(gPlayerData[playerid][pFaction] != 255)
				{
					if(DynamicFactions[gPlayerData[playerid][pFaction]][fType] != 1)
						return 1;
					if(!gPlayerData[playerid][pDuty])
						return 1;
					if(IsPlayerInAnyVehicle(playerid))
						return 1;
					new suspect = GetClosestPlayer(playerid);
					if(suspect == -1)
						return 1;
					if(!IsPlayerConnected(suspect))
						return 1;
					if(GetDistanceBetweenPlayers(playerid, suspect) > 4)
						return 1;
					if(IsPlayerInAnyVehicle(suspect))
						return 1;
					PlayerActionMessage(playerid, 15.0, "wyci¹ga z kabury paralizator X26C i u¿ywa go");
					format(string, sizeof(string), "[INFO:] Zosta³eœ sparali¿owany przez %s na 10 sekund.", GetPlayerNameEx(playerid));
					SendClientMessage(suspect, COLOR_RED, string);
					format(string, sizeof(string), "[INFO:] Sparali¿owa³eœ %s na 10 sekund.", GetPlayerNameEx(suspect));
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
					TogglePlayerControllable(suspect, 0);
					PlayerTazed[suspect] = 1;
					defer UntazePlayer(suspect);
					return 1;
				}
			}
		}
		if(newkeys & KEY_NO)
		{
			if(gIsOnAShip[playerid] != -1)
			{
				if(gShipSight[playerid] > 10.0)
					gShipSight[playerid] -= 5.0;
				else if(gShipSight[playerid] <= 10.0 && gShipSight[playerid] > 0.0)
					gShipSight[playerid] -= 1.0;
				format(string, sizeof(string), "[INFO:] Zasiêg przemieszczenia zmniejszony do %fm", gShipSight[playerid]);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			}
		}
		if(newkeys & KEY_SECONDARY_ATTACK)
		{
			for(new i = 0; i < sizeof(Houses); i++)
			{
				if(PlayerToPoint(0.7, playerid, Houses[i][EnterX], Houses[i][EnterY], Houses[i][EnterZ]))
				{
					if(GetPlayerVirtualWorld(playerid) == Houses[i][EnterWorld])
					{
						if( (!Houses[i][Locked] && !Houses[i][HConfiscated]) || AdminDuty[playerid] )
						{
							if( Houses[i][HouseType] == 0 )
							{
								PlayerActionMessage(playerid,15.0,"naciska klamke i wchodzi do budynku");
								Audio_Play(playerid, AUDIO_DOOR_OPEN, false, false, false);
							}
							else
								PlayerActionMessage(playerid, 15.0, "otwiera gara¿ pilotem i wchodzi do gara¿u" );
								
							gPlayerVars[playerid][mAtHouseID] = i;	
								
							if(strcmp(gPlayerData[playerid][pName], Houses[i][Owner], false) == 0 || strcmp(gPlayerData[playerid][pName], Houses[i][HRenter], false) == 0)
								SendClientMessage(playerid, COLOR_GREEN, "[INFO:] Jesteœ teraz w swoim domu, twoja postaæ bêdzie siê powoli regenerowaæ");
							
							SetPlayerInterior(playerid,Houses[i][ExitInterior]);
							SetPlayerToPos(playerid,Houses[i][ExitX],Houses[i][ExitY],Houses[i][ExitZ]);
							SetPlayerVirtualWorld(playerid,i);
							SetPlayerFacingAngle(playerid,Houses[i][ExitAngle]);
							
							if( Houses[i][HRadio1On] && Houses[i][HRadio1Bought] )
								PlayerPHouseRadio( playerid, i );
							
							if(strcmp(gPlayerData[playerid][pName], Houses[i][Owner], true) == 0)
							{
								gPlayerData[playerid][pCrashX] = Houses[i][ExitX];
								gPlayerData[playerid][pCrashY] = Houses[i][ExitY];
								gPlayerData[playerid][pCrashZ] = Houses[i][ExitZ];
								gPlayerData[playerid][pCrashInt] = Houses[i][ExitInterior];
								gPlayerData[playerid][pCrashW] = i;
								gPlayerData[playerid][pCrashAngle] = Houses[i][ExitAngle];
							}
							else
							{
								gPlayerData[playerid][pCrashX] = Houses[i][EnterX];
								gPlayerData[playerid][pCrashY] = Houses[i][EnterY];
								gPlayerData[playerid][pCrashZ] = Houses[i][EnterZ];
								gPlayerData[playerid][pCrashInt] = Houses[i][EnterInterior];
								gPlayerData[playerid][pCrashW] = Houses[i][EnterWorld];
								gPlayerData[playerid][pCrashAngle] = Houses[i][EnterAngle];
							}

							TogglePlayerControllable(playerid, 0);
							defer UnfreezePlayer(playerid);
							return 1;
						}
						else if( Houses[i][HConfiscated] && !AdminDuty[playerid] )
						{
							GameTextForPlayer(playerid, "~r~Posiadlosc skonfiskowana", 5000, 1);
							PlayerActionMessage(playerid, 20.0, "naciska klamke nie uzyskuj¹c rezultatu");
							
							ApplyAnimation(playerid,"PED","CAR_doorlocked_RHS",4.1,0,1,1,0,0);
							return 1;
						}
						else
						{
							GameTextForPlayer(playerid, "~r~Zamkniete", 5000, 1);
							PlayerActionMessage(playerid, 20.0, "naciska klamke nie uzyskuj¹c rezultatu");
							
							ApplyAnimation(playerid,"PED","CAR_doorlocked_RHS",4.1,0,1,1,0,0);
							return 1;
						}
					}
				}
				if(PlayerToPoint(0.7, playerid,Houses[i][ExitX], Houses[i][ExitY], Houses[i][ExitZ]))
				{
					if(GetPlayerVirtualWorld(playerid) == i)
					{
						if(Houses[i][Locked] == 0 || AdminDuty[playerid])
						{
							if( Houses[i][HouseType] == 0 )
							{
								PlayerActionMessage(playerid,15.0,"naciska klamke i wychodzi z budynku");
								Audio_Play(playerid, AUDIO_DOOR_OPEN, false, false, false);
							}
							else
								PlayerActionMessage(playerid, 15.0, "otwiera gara¿ pilotem i wychodzi z gara¿u" );
								
							gPlayerVars[playerid][mAtHouseID] = -1;	
								
							if( Houses[i][HRadio1Bought] && Houses[i][HRadio1On] )
								Audio_Stop( playerid, Houses[i][HRadio1ID][playerid] );
							
							SetPlayerInterior(playerid,Houses[i][EnterInterior]);
							SetPlayerToPos(playerid,Houses[i][EnterX],Houses[i][EnterY],Houses[i][EnterZ]);
							SetPlayerVirtualWorld(playerid,Houses[i][EnterWorld]);
							SetPlayerFacingAngle(playerid,Houses[i][EnterAngle]);

							gPlayerData[playerid][pCrashInt] = Houses[i][EnterInterior];
							gPlayerData[playerid][pCrashX] = Houses[i][EnterX];
							gPlayerData[playerid][pCrashY] = Houses[i][EnterY];
							gPlayerData[playerid][pCrashZ] = Houses[i][EnterZ];
							gPlayerData[playerid][pCrashW] = Houses[i][EnterWorld];
							gPlayerData[playerid][pCrashAngle] = Houses[i][EnterAngle];

							TogglePlayerControllable(playerid, 0);
							defer UnfreezePlayer(playerid);
							return 1;
						}
						else
						{
							GameTextForPlayer(playerid, "~r~Zamkniete", 5000, 1);
							PlayerActionMessage(playerid, 20.0, "naciska klamke nie uzyskuj¹c rezultatu");
							return 1;
						}
					}
				}
			}
			for(new i = 0; i < sizeof(Building); i++)
			{
				if(PlayerToPoint(0.7, playerid,Building[i][EnterX], Building[i][EnterY], Building[i][EnterZ]))
				{
					if(GetPlayerVirtualWorld(playerid) == Building[i][EnterWorld])
					{
						if( gPlayerData[playerid][pJob] != 22 && i == 49 && !AdminDuty[playerid] )
						{
							SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz wejœæ do tego budynku ! Nie jesteœ pracownikiem broni !");
							return 1;
						}
						if((gHour < Building[i][Closed] && gHour >= Building[i][Opened]) || (Building[i][Opened] == Building[i][Closed]) || AdminDuty[playerid])
						{
							if(Building[i][Locked] == 0 || AdminDuty[playerid] >=  1)
							{
								if(GetPlayerCash(playerid) >= Building[i][EntranceFee] || Building[i][EntranceFee] == 0)
								{
									PlayerActionMessage(playerid,15.0,"naciska klamke i wchodzi do budynku");
									Audio_Play(playerid, AUDIO_DOOR_OPEN, false, false, false);

									gPlayerVars[playerid][mAtBuildingId] = i;
									
									SetPlayerInterior(playerid,Building[i][ExitInterior]);
									SetPlayerVirtualWorld(playerid,i);
									SetPlayerToPos(playerid,Building[i][ExitX],Building[i][ExitY],Building[i][ExitZ]);
									SetPlayerFacingAngle(playerid,Building[i][ExitAngle]);
									GivePlayerCash(playerid,-Building[i][EntranceFee]);
									// TODO: Check if only public building can have entrance fee
									// If not then other types of factions should have income from entrance fee to their
									// faction accounts
									DynamicFactions[FACTIONID_GOVERNMENT][fBank] += Building[i][EntranceFee];
									SaveFData(FACTIONID_GOVERNMENT, "Bank");

									gPlayerData[playerid][pCrashInt] = Building[i][ExitInterior];
									gPlayerData[playerid][pCrashX] = Building[i][ExitX];
									gPlayerData[playerid][pCrashY] = Building[i][ExitY];
									gPlayerData[playerid][pCrashZ] = Building[i][ExitZ];
									gPlayerData[playerid][pCrashW] = i;
									gPlayerData[playerid][pCrashAngle] = Building[i][ExitAngle];

									TogglePlayerControllable(playerid, 0);
									defer UnfreezePlayer(playerid);
									return 1;
								}
								else
								{
									GameTextForPlayer(playerid, "~r~Nie masz wystarczajacej ilosci pieniedzy", 5000, 1);
									return 1;
								}
							}
							else
							{
								GameTextForPlayer(playerid, "~r~Zamkniete", 5000, 1);
								PlayerActionMessage(playerid, 20.0, "naciska klamke nie uzyskuj¹c rezultatu");
								
								ApplyAnimation(playerid,"PED","CAR_doorlocked_RHS",4.1,0,1,1,0,0);
								return 1;
							}
						}
						else
						{
							format(string, sizeof(string), "[INFO:] Budynek zamkniêty ! Wróæ miêdzy godzin¹ %d a %d", Building [i][Opened], Building[i][Closed]);
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
							
							ApplyAnimation(playerid,"PED","CAR_doorlocked_RHS",4.1,0,1,1,0,0);
							return 1;
						}
					}
				}
				if(PlayerToPoint(0.7, playerid,Building[i][ExitX], Building[i][ExitY], Building[i][ExitZ]))
				{
					if(GetPlayerVirtualWorld(playerid) == i)
					{
						if( gPlayerData[playerid][pPartType] != 0 && gPlayerData[playerid][pPartItem] != 0 && !AdminDuty[playerid])
						{
							SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz wyjœæ z budynku - musisz zwróciæ wpierw wszystkie czêœci !");
							return 1;
						}
						if(Building[i][Locked] == 0 || AdminDuty[playerid])
						{
							PlayerActionMessage(playerid,15.0,"naciska klamke i wychodzi z budynku");
							Audio_Play(playerid, AUDIO_DOOR_OPEN, false, false, false);

							gPlayerVars[playerid][mAtBuildingId] = -1;
							
							SetPlayerInterior(playerid,Building[i][EnterInterior]);
							SetPlayerVirtualWorld(playerid,Building[i][EnterWorld]);
							SetPlayerToPos(playerid,Building[i][EnterX],Building[i][EnterY],Building[i][EnterZ]);
							SetPlayerFacingAngle(playerid,Building[i][EnterAngle]);

							gPlayerData[playerid][pCrashInt] = Building[i][EnterInterior];
							gPlayerData[playerid][pCrashX] = Building[i][EnterX];
							gPlayerData[playerid][pCrashY] = Building[i][EnterY];
							gPlayerData[playerid][pCrashZ] = Building[i][EnterZ];
							gPlayerData[playerid][pCrashW] = Building[i][EnterWorld];
							gPlayerData[playerid][pCrashAngle] = Building[i][EnterAngle];

							TogglePlayerControllable(playerid, 0);
							defer UnfreezePlayer(playerid);
							return 1;
						}
						else
						{
							GameTextForPlayer(playerid, "~r~Zamkniete", 5000, 1);
							PlayerActionMessage(playerid, 20.0, "naciska klamke nie uzyskuj¹c rezultatu");
							return 1;
						}
					}
				}
			}
			for(new i = 0; i < sizeof(Businesses); i++)
			{
				if(PlayerToPoint(0.7, playerid,Businesses[i][EnterX], Businesses[i][EnterY], Businesses[i][EnterZ]) && GetPlayerVirtualWorld(playerid) == Businesses[i][EnterWorld])
				{
					if(Businesses[i][Locked] && !AdminDuty[playerid])
					{
						GameTextForPlayer(playerid, "~r~Biznes zamkniety.", 5000, 1);
						PlayerActionMessage(playerid, 20.0, "naciska klamke nie uzyskuj¹c rezultatu");
						ApplyAnimation(playerid,"PED","CAR_doorlocked_RHS",4.1,0,1,1,0,0);
						return 1;
					}
					else if( Businesses[i][BConfiscated] && !AdminDuty[playerid] )
					{
						GameTextForPlayer(playerid, "~r~Biznes skonfiskowany", 5000, 1);
						PlayerActionMessage(playerid, 20.0, "naciska klamke nie uzyskuj¹c rezultatu");								
						ApplyAnimation(playerid,"PED","CAR_doorlocked_RHS",4.1,0,1,1,0,0);
						return 1;
					}
					
					if(strcmp(gPlayerData[playerid][pName], Businesses[i][Owner]) != 0 && Businesses[i][EntranceCost] > 0 && Businesses[i][Owned])
					{
						if(gPlayerData[playerid][pCash] < Businesses[i][EntranceCost])
						{
							SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz wejœæ, masz za ma³o pieniêdzy");
							return 1;
						}
						
						GivePlayerCash(playerid,-Businesses[i][EntranceCost]);
						Businesses[i][Till] += Businesses[i][EntranceCost];
						SaveBizData(i, "Till");
						
						Businesses[i][mIncomeEntranceTotal] += Businesses[i][EntranceCost];
						Businesses[i][mIncomeEntranceToday] += Businesses[i][EntranceCost];
						Businesses[i][mIncomeTotal] += Businesses[i][EntranceCost];
						SaveBizData(i, "IncomeEntranceTotal");
						SaveBizData(i, "IncomeEntranceToday");
						SaveBizData(i, "IncomeTotal");
						
						format(string, sizeof(string), "[INFO:] Pobrano op³ate w wysokoœci $%d za wejœcie do %s.", Businesses[i][EntranceCost],Businesses[i][BusinessName]);
						SendClientMessage(playerid,COLOR_LIGHTYELLOW2,string);
					}
					if(gPlayerData[playerid][pJob] == 19)
					{
						if(Businesses[i][Till] <= 0)
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz pracowaæ tutaj jako sprzedawca - brak pieniêdzy w kasie biznesu");
					}															
					// Businesses[i][Products]--;
					// SaveBizData(i, "Products");

					gPlayerVars[playerid][mAtBizID] = i;
					
					PlayerActionMessage(playerid,15.0,"naciska klamke i wchodzi do budynku");
					Audio_Play(playerid, AUDIO_DOOR_OPEN, false, false, false);

					SetPlayerToBiz(playerid, i);

					if( Businesses[i][BRadio1On] && Businesses[i][BRadio1Bought] )
						ResumeBizRadioStation( playerid, i );
					
					gPlayerData[playerid][pCrashX] = Businesses[i][EnterX];
					gPlayerData[playerid][pCrashY] = Businesses[i][EnterY];
					gPlayerData[playerid][pCrashZ] = Businesses[i][EnterZ];
					gPlayerData[playerid][pCrashW] = i;
					gPlayerData[playerid][pCrashAngle] = Businesses[i][ExitAngle];
					gPlayerData[playerid][pCrashInt] = Businesses[i][ExitInterior];

					return 1;
				}
				if (PlayerToPoint(3, playerid,Businesses[i][ExitX], Businesses[i][ExitY], Businesses[i][ExitZ]))
				{
					if(GetPlayerVirtualWorld(playerid) == i)
					{
						if(gPlayerData[playerid][pSellerJobOn])
						{
							gPlayerData[playerid][pSellerJobOn] = 0;
							SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Opuœci³eœ stanowisko pracy ! Nie dostajesz ju¿ wynagrodzenia.");
						}
						if(Businesses[i][Locked] == 0 || AdminDuty[playerid])
						{
							PlayerActionMessage(playerid,15.0,"naciska klamke i wychodzi z budynku");
							Audio_Play(playerid, AUDIO_DOOR_OPEN, false, false, false);

							gPlayerVars[playerid][mAtBizID] = -1;
							
							SetPlayerInterior(playerid,Businesses[i][EnterInterior]);
							SetPlayerVirtualWorld(playerid,Businesses[i][EnterWorld]);
							SetPlayerToPos(playerid,Businesses[i][EnterX],Businesses[i][EnterY],Businesses[i][EnterZ]);
							SetPlayerFacingAngle(playerid,Businesses[i][EnterAngle]);

							gPlayerData[playerid][pCrashInt] = Businesses[i][EnterInterior];
							gPlayerData[playerid][pCrashX] = Businesses[i][EnterX];
							gPlayerData[playerid][pCrashY] = Businesses[i][EnterY];
							gPlayerData[playerid][pCrashZ] = Businesses[i][EnterZ];
							gPlayerData[playerid][pCrashW] = Businesses[i][EnterWorld];
							gPlayerData[playerid][pCrashAngle] = Businesses[i][EnterAngle];

							TogglePlayerControllable(playerid, 0);
							defer UnfreezePlayer(playerid);
							return 1;
						}
						else
						{
							GameTextForPlayer(playerid, "~r~Zamkniete", 5000, 1);
							PlayerActionMessage(playerid, 20.0, "naciska klamke nie uzyskuj¹c rezultatu");
							return 1;
						}
					}
				}
			}
			if(PlayerToPoint(1.0, playerid, gDrivingTestArea[posEntranceX], gDrivingTestArea[posEntranceY], gDrivingTestArea[posEntranceZ]))
			{
				if(gPlayerData[playerid][pTestAreaTimeLeft] == 0 && !TakingDrivingTestA[playerid] && !TakingDrivingTestB[playerid] && !TakingDrivingTestCE[playerid] && PHaveItemParam5Ex(playerid, 3, 18, gPlayerData[playerid][pName]) == -1)
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie masz wykupionych minut aby przebywaæ na placu manewrowym, nie jesteœ w trakcie egzaminu ani nie jesteœ instruktorem");
					return 1;
				}
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Jesteœ teraz na placu manewrowym - wybierz jeden z pojazdów i rozpocznij æwiczenia");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Aby ponownie ustawiæ pacho³ki wpisz komende /ustawpacholki");
				SetPlayerToPos(playerid, gDrivingTestArea[posExitX], gDrivingTestArea[posExitY], gDrivingTestArea[posExitZ]);
				SetPlayerFacingAngle(playerid, gDrivingTestArea[posExitAngle]);
				SetPlayerInterior(playerid, gDrivingTestArea[posExitInterior]);
				SetPlayerVirtualWorld(playerid, gDrivingTestArea[posExitWorld]);
				return 1;
			}
			if(PlayerToPoint(1.0, playerid, gDrivingTestArea[posExitX], gDrivingTestArea[posExitY], gDrivingTestArea[posExitZ]))
			{
				SetPlayerToPos(playerid, gDrivingTestArea[posEntranceX], gDrivingTestArea[posEntranceY], gDrivingTestArea[posEntranceZ]);
				SetPlayerFacingAngle(playerid, gDrivingTestArea[posEntranceAngle]);
				SetPlayerInterior(playerid, gDrivingTestArea[posEntranceInterior]);
				SetPlayerVirtualWorld(playerid, gDrivingTestArea[posEntranceWorld]);
				return 1;
			}
		}
	}
	
	return 1;
} // end of OnPlayerKeyStateChange
