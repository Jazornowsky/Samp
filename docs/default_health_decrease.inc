if(gPlayerData[i][pJailed] == 0 && gPlayerData[i][pCharacterDying] == 0)
			{
				// Health problems
				if((IsPlayerVip(i) && gPlayerData[i][pStomach] >= MAX_STOMACH_VIP) || (!IsPlayerVip(i) && gPlayerData[i][pStomach] >= MAX_STOMACH))
				{
					defer PlayerWomit(i);
					gPlayerData[i][pVitamins] -= 10.0;
					gPlayerData[i][pPoison] += 15.0;
					gPlayerData[i][pEnergy] -= 20.0;
					gPlayerData[i][pStomach] -= 50.0;
					SetPlayerDrunkLevelEx(i, 4000);	
				}
				// Energy
				if(gPlayerData[i][pEnergy] > 0.0)
				{
					format(string, sizeof(string), "EO: %f; HO: %f; TO: %f; PO: %f; FO: %f; SO: %f; VO: %f",
						gPlayerData[i][pEnergy], gPlayerData[i][pHunger], gPlayerData[i][pThirst], gPlayerData[i][pPoison],
						gPlayerData[i][pFat], gPlayerData[i][pStomach], gPlayerData[i][pVitamins]); 
					if(IsPlayerVip(i))
					{
						if(gPlayerVars[i][mAtHouseID] != -1)
						{
							if(strcmp(Houses[gPlayerVars[i][mAtHouseID]][Owner], gPlayerData[i][pName], false) == 0)
							{
								gPlayerData[i][pEnergy] += 0.5;
								if(gPlayerData[i][pEnergy] > MAX_ENERGY_VIP)
									gPlayerData[i][pEnergy] = MAX_ENERGY_VIP;
							}
						}
						else
						{
							// hunger and thirst
							if(gPlayerData[i][pThirst] == MAX_THIRST_VIP && gPlayerData[i][pHunger] < MAX_HUNGER_VIP)
								gPlayerData[i][pEnergy] -= ENERGY*0.75;
							else if(gPlayerData[i][pThirst] == MAX_THIRST_VIP && gPlayerData[i][pHunger] == MAX_HUNGER_VIP)
								gPlayerData[i][pEnergy] -= ENERGY*1.25;
							// poison
							if(gPlayerData[i][pPoison] >= 30.0 && gPlayerData[i][pPoison] < 60.0)
								gPlayerData[i][pEnergy] -= ENERGY*0.1;
							else if(gPlayerData[i][pPoison] >= 60.0 && gPlayerData[i][pPoison] < 90.0)
								gPlayerData[i][pEnergy] -= ENERGY*0.1;
							else if(gPlayerData[i][pPoison] >= 90.0 && gPlayerData[i][pPoison] < 120.0)
								gPlayerData[i][pEnergy] -= ENERGY*0.2;
							else if(gPlayerData[i][pPoison] >= 120.0 && gPlayerData[i][pPoison] <= 150.0)
								gPlayerData[i][pEnergy] -= ENERGY*0.3;
							gPlayerData[i][pEnergy] -= ENERGY;
						}
					}
					else
					{
						if(gPlayerVars[i][mAtHouseID] != -1)
						{
							if(strcmp(Houses[gPlayerVars[i][mAtHouseID]][Owner], gPlayerData[i][pName], false) == 0)
							{
								gPlayerData[i][pEnergy] += 0.5;
								if(gPlayerData[i][pEnergy] > MAX_ENERGY)
									gPlayerData[i][pEnergy] = MAX_ENERGY;
							}
						}
						else
						{
							// hunger and thirst
							if(gPlayerData[i][pThirst] == MAX_THIRST && gPlayerData[i][pHunger] < MAX_HUNGER)
								gPlayerData[i][pEnergy] -= ENERGY*0.75;
							else if(gPlayerData[i][pThirst] == MAX_THIRST && gPlayerData[i][pHunger] == MAX_HUNGER)
								gPlayerData[i][pEnergy] -= ENERGY*1.25;
							// poison
							if(gPlayerData[i][pPoison] >= 20.0 && gPlayerData[i][pPoison] < 40.0)
								gPlayerData[i][pEnergy] -= ENERGY*0.1;
							else if(gPlayerData[i][pPoison] >= 40.0 && gPlayerData[i][pPoison] < 60.0)
								gPlayerData[i][pEnergy] -= ENERGY*0.1;
							else if(gPlayerData[i][pPoison] >= 60.0 && gPlayerData[i][pPoison] < 80.0)
								gPlayerData[i][pEnergy] -= ENERGY*0.2;
							else if(gPlayerData[i][pPoison] >= 80.0 && gPlayerData[i][pPoison] <= 100.0)
								gPlayerData[i][pEnergy] -= ENERGY*0.3;
							// fat
							if(gPlayerData[i][pFat] >= 0.0 && gPlayerData[i][pFat] < 30.0)
								gPlayerData[i][pEnergy] -= ENERGY*0.2;
							else if(gPlayerData[i][pFat] >= 60.0 && gPlayerData[i][pFat] <= 100.0)
								gPlayerData[i][pEnergy] -= ENERGY*0.2;
							// default
							gPlayerData[i][pEnergy] -= ENERGY;
						}
					}
				}
				if(gPlayerData[i][pEnergy] < 0.0)
					gPlayerData[i][pEnergy] = 0.0;
				// Hunger
				if(IsPlayerVip(i))
				{
					if(gPlayerData[i][pHunger] < MAX_HUNGER_VIP)
					{
						// thirst
						if(gPlayerData[i][pThirst] == MAX_THIRST_VIP)
							gPlayerData[i][pHunger] += HUNGER*0.5;
						// poison
						if(gPlayerData[i][pPoison] >= 30 && gPlayerData[i][pPoison] < 60)
							gPlayerData[i][pHunger] += HUNGER*0.1;
						else if(gPlayerData[i][pPoison] >= 60 && gPlayerData[i][pPoison] < 90)
							gPlayerData[i][pHunger] += HUNGER*0.1;
						else if(gPlayerData[i][pPoison] >= 90 && gPlayerData[i][pPoison] < 120)
							gPlayerData[i][pHunger] += HUNGER*0.2;
						else if(gPlayerData[i][pPoison] >= 120 && gPlayerData[i][pPoison] <= 150)
							gPlayerData[i][pHunger] += HUNGER*0.3;
						// vitamins
						if(gPlayerData[i][pVitamins] >= 0.0 && gPlayerData[i][pVitamins] < 50.0)
							gPlayerData[i][pHunger] += HUNGER*0.1;
						else if(gPlayerData[i][pVitamins] >= 120.0 && gPlayerData[i][pVitamins] <= 150.0)
							gPlayerData[i][pHunger] += HUNGER*0.1;
						// fat
						if(gPlayerData[i][pFat] >= 0.0 && gPlayerData[i][pFat] < 45.0)
							gPlayerData[i][pHunger] += HUNGER*0.2;
						else if(gPlayerData[i][pFat] >= 90.0 && gPlayerData[i][pFat] <= 150.0)
							gPlayerData[i][pHunger] += HUNGER*0.2;
						// default
						gPlayerData[i][pHunger] += HUNGER;
					}
					if(gPlayerData[i][pHunger] > MAX_HUNGER_VIP)
						gPlayerData[i][pHunger] = MAX_HUNGER_VIP;					
				}
				else
				{
					if(gPlayerData[i][pHunger] < MAX_HUNGER)
					{
						// thirst
						if(gPlayerData[i][pThirst] == MAX_THIRST)
							gPlayerData[i][pHunger] += HUNGER*0.5;
						// poison
						if(gPlayerData[i][pPoison] >= 20 && gPlayerData[i][pPoison] < 40)
							gPlayerData[i][pHunger] += HUNGER*0.1;
						else if(gPlayerData[i][pPoison] >= 40 && gPlayerData[i][pPoison] < 60)
							gPlayerData[i][pHunger] += HUNGER*0.1;
						else if(gPlayerData[i][pPoison] >= 60 && gPlayerData[i][pPoison] < 80)
							gPlayerData[i][pHunger] += HUNGER*0.2;
						else if(gPlayerData[i][pPoison] >= 80 && gPlayerData[i][pPoison] <= 100)
							gPlayerData[i][pHunger] += HUNGER*0.3;
						// vitamins
						if(gPlayerData[i][pVitamins] >= 0.0 && gPlayerData[i][pVitamins] < 20.0)
							gPlayerData[i][pHunger] += HUNGER*0.1;
						else if(gPlayerData[i][pVitamins] >= 80.0 && gPlayerData[i][pVitamins] <= 100.0)
							gPlayerData[i][pHunger] += HUNGER*0.1;
						// fat
						if(gPlayerData[i][pFat] >= 0.0 && gPlayerData[i][pFat] < 30.0)
							gPlayerData[i][pHunger] += HUNGER*0.2;
						else if(gPlayerData[i][pFat] >= 60.0 && gPlayerData[i][pFat] <= 100.0)
							gPlayerData[i][pHunger] += HUNGER*0.2;
						// default
						gPlayerData[i][pHunger] += HUNGER;
					}
					if(gPlayerData[i][pHunger] > MAX_HUNGER)
						gPlayerData[i][pHunger] = MAX_HUNGER;
				}
				// Thirst
				if(IsPlayerVip(i))
				{
					if(gPlayerData[i][pThirst] < MAX_THIRST_VIP)
					{
						// hunger
						if(gPlayerData[i][pHunger] == MAX_HUNGER_VIP)
							gPlayerData[i][pThirst] += THIRST*0.5;
						// poison
						if(gPlayerData[i][pPoison] >= 30 && gPlayerData[i][pPoison] < 60)
							gPlayerData[i][pThirst] -= THIRST*0.1;
						else if(gPlayerData[i][pPoison] >= 60 && gPlayerData[i][pPoison] < 90)
							gPlayerData[i][pThirst] -= THIRST*0.1;
						else if(gPlayerData[i][pPoison] >= 90 && gPlayerData[i][pPoison] < 120)
							gPlayerData[i][pThirst] -= THIRST*0.2;
						else if(gPlayerData[i][pPoison] >= 120 && gPlayerData[i][pPoison] <= 150)
							gPlayerData[i][pThirst] -= THIRST*0.3;
						// vitamins
						if(gPlayerData[i][pVitamins] >= 0.0 && gPlayerData[i][pVitamins] < 30.0)
							gPlayerData[i][pThirst] -= THIRST*0.1;
						else if(gPlayerData[i][pVitamins] >= 120.0 && gPlayerData[i][pVitamins] <= 150.0)
							gPlayerData[i][pThirst] -= THIRST*0.1;
						// fat
						if(gPlayerData[i][pFat] >= 0.0 && gPlayerData[i][pFat] < 45.0)
							gPlayerData[i][pThirst] -= THIRST*0.2;
						else if(gPlayerData[i][pFat] >= 90.0 && gPlayerData[i][pFat] <= 150.0)
							gPlayerData[i][pThirst] -= THIRST*0.2;
						// default
						gPlayerData[i][pThirst] += THIRST;
					}
					if(gPlayerData[i][pThirst] > MAX_THIRST_VIP)
						gPlayerData[i][pThirst] = MAX_THIRST_VIP;
				}
				else
				{
					if(gPlayerData[i][pThirst] < MAX_THIRST)
					{
						// hunger
						if(gPlayerData[i][pHunger] == MAX_HUNGER)
							gPlayerData[i][pThirst] += THIRST*0.5;
						// poison
						if(gPlayerData[i][pPoison] >= 20 && gPlayerData[i][pPoison] < 40)
							gPlayerData[i][pThirst] -= THIRST*0.1;
						else if(gPlayerData[i][pPoison] >= 40 && gPlayerData[i][pPoison] < 60)
							gPlayerData[i][pThirst] -= THIRST*0.1;
						else if(gPlayerData[i][pPoison] >= 60 && gPlayerData[i][pPoison] < 80)
							gPlayerData[i][pThirst] -= THIRST*0.2;
						else if(gPlayerData[i][pPoison] >= 80 && gPlayerData[i][pPoison] <= 100)
							gPlayerData[i][pThirst] -= THIRST*0.3;
						// vitamins
						if(gPlayerData[i][pVitamins] >= 0.0 && gPlayerData[i][pVitamins] < 20.0)
							gPlayerData[i][pThirst] -= THIRST*0.1;
						else if(gPlayerData[i][pVitamins] >= 80.0 && gPlayerData[i][pVitamins] <= 100.0)
							gPlayerData[i][pThirst] -= THIRST*0.1;
						// fat
						if(gPlayerData[i][pFat] >= 0.0 && gPlayerData[i][pFat] < 30.0)
							gPlayerData[i][pThirst] -= THIRST*0.2;
						else if(gPlayerData[i][pFat] >= 60.0 && gPlayerData[i][pFat] <= 100.0)
							gPlayerData[i][pThirst] -= THIRST*0.2;
						// default
						gPlayerData[i][pThirst] += THIRST;
					}
					if(gPlayerData[i][pThirst] > MAX_THIRST)
						gPlayerData[i][pThirst] = MAX_THIRST;					
				}
				// Poison
				if(gPlayerVars[i][mAtHouseID] != -1)
				{
					if(strcmp(Houses[gPlayerVars[i][mAtHouseID]][Owner], gPlayerData[i][pName], false) == 0)
					{
						gPlayerData[i][pPoison] -= POISON;
						if(gPlayerData[i][pPoison] < 0)
							gPlayerData[i][pPoison] = 0;
					}
				}
				if(IsPlayerVip(i))
				{
					if(gPlayerData[i][pPoison] > 0.0 && gPlayerData[i][pPoison] < 60.0)
					{
						gPlayerData[i][pPoison] -= POISON;
						TextDrawHideForPlayer(i, gTdPoison);
					}
					if(gPlayerData[i][pPoison] >= 60.0 && gPlayerData[i][pPoison] < 90.0)
					{
						if(random(15) == 3)
							SetPlayerDrunkLevelEx(i, 3980);	
						// TextDrawShowForPlayer(i, gTdPoison);
					}
					if(gPlayerData[i][pPoison] >= 90.0 && gPlayerData[i][pPoison] < 120.0)
					{
						if(random(10) == 3)
						{
							SetPlayerDrunkLevelEx(i, 5960);	
							defer PlayerWomit(i);
						}
						// TextDrawShowForPlayer(i, gTdPoison);
					}	
					if(gPlayerData[i][pPoison] >= 120.0)
					{
						if(random(5) == 3)
						{
							SetPlayerDrunkLevelEx(i, 12880);	
							defer PlayerWomit(i);
						}
						// TextDrawShowForPlayer(i, gTdPoison);
					}
				}
				else
				{
					if(gPlayerData[i][pPoison] > 0.0 && gPlayerData[i][pPoison] < 40.0)
					{
						gPlayerData[i][pPoison] -= POISON;
						TextDrawHideForPlayer(i, gTdPoison);
					}
					if(gPlayerData[i][pPoison] >= 40.0 && gPlayerData[i][pPoison] < 60.0)
					{
						if(random(15) == 3)
							SetPlayerDrunkLevelEx(i, 3980);	
						// TextDrawShowForPlayer(i, gTdPoison);
					}
					if(gPlayerData[i][pPoison] >= 60.0 && gPlayerData[i][pPoison] < 80.0)
					{
						if(random(10) == 3)
						{
							SetPlayerDrunkLevelEx(i, 5960);	
							defer PlayerWomit(i);
						}
						// TextDrawShowForPlayer(i, gTdPoison);
					}	
					if(gPlayerData[i][pPoison] >= 80.0)
					{
						if(random(5) == 3)
						{
							SetPlayerDrunkLevelEx(i, 12880);	
							defer PlayerWomit(i);
						}
						// TextDrawShowForPlayer(i, gTdPoison);
					}
				}
				if(gPlayerData[i][pPoison] < 0.0)
				{
					gPlayerData[i][pPoison] = 0.0;
					TextDrawHideForPlayer(i, gTdPoison);
				}
				// Fat
				if(gPlayerData[i][pFat] > 0.0)
					gPlayerData[i][pFat] -= FAT;
				if(gPlayerData[i][pFat] < 0.0)
					gPlayerData[i][pFat] = 0.0;				
				// Stomach
				if(gPlayerData[i][pStomach] > 0.0)
				{
					if(gPlayerData[i][pSlimming] > 0)
						gPlayerData[i][pStomach] -= STOMACH*2.0;
					gPlayerData[i][pStomach] -= STOMACH;
				}
				if(gPlayerData[i][pStomach] < 0.0)
					gPlayerData[i][pStomach] = 0.0;				
				// Vitamins
				if(gPlayerData[i][pVitamins] > 0.0)
				{
					if((IsPlayerVip(i) && gPlayerData[i][pPoison] >= MAX_POISON_VIP) || (!IsPlayerVip(i) && gPlayerData[i][pPoison] >= MAX_POISON))
						gPlayerData[i][pVitamins] -= 10.0;
					gPlayerData[i][pVitamins] -= VITAMINS;
				}
				if(gPlayerData[i][pVitamins] < 0.0)
					gPlayerData[i][pVitamins] = 0.0;				
				// Drunk
				if(IsPlayerVip(i))
				{
					if(gPlayerData[i][pDrunk] > 0.0)
					{
						if(gPlayerData[i][pDrunk] > 30.0 && gPlayerData[i][pDrunk] <= 60.0)
							SetPlayerDrunkLevelEx(i, 3980);	
						else if(gPlayerData[i][pDrunk] > 60.0 && gPlayerData[i][pDrunk] <= 90.0)
							SetPlayerDrunkLevelEx(i, 5960);	
						else if(gPlayerData[i][pDrunk] > 90.0 && gPlayerData[i][pDrunk] <= 150.0)
							SetPlayerDrunkLevelEx(i, 12880);
						gPlayerData[i][pDrunk] -= DRUNK;
					}
				}
				else
				{
					if(gPlayerData[i][pDrunk] > 0.0)
					{
						if(gPlayerData[i][pDrunk] > 20.0 && gPlayerData[i][pDrunk] <= 40.0)
							SetPlayerDrunkLevelEx(i, 3980);	
						else if(gPlayerData[i][pDrunk] > 40.0 && gPlayerData[i][pDrunk] <= 60.0)
							SetPlayerDrunkLevelEx(i, 5960);	
						else if(gPlayerData[i][pDrunk] > 60.0 && gPlayerData[i][pDrunk] <= 100.0)
							SetPlayerDrunkLevelEx(i, 12880);
						gPlayerData[i][pDrunk] -= DRUNK;
					}
				}
				if(gPlayerData[i][pDrunk] < 0.0)
					gPlayerData[i][pDrunk] = 0.0;				
				// Narcotic
				if(gPlayerData[i][pNarcotic] > 0.0)
					gPlayerData[i][pNarcotic] -= NARCOTIC;
				if(gPlayerData[i][pNarcotic] < 0.0)
					gPlayerData[i][pNarcotic] = 0.0;				
				
				SavePlayerData(i, "HealthStatus");
				format(string, sizeof(string), "%s\nEN: %f; HN: %f; TN: %f; PN: %f; FN: %f; SN: %f; VN: %f", string,
					gPlayerData[i][pEnergy], gPlayerData[i][pHunger], gPlayerData[i][pThirst], gPlayerData[i][pPoison],
					gPlayerData[i][pFat], gPlayerData[i][pStomach], gPlayerData[i][pVitamins]); 
				TextDrawSetString(EatText[i], string);
				if(gPlayerData[i][pShowHealthBars])
				{
					// SetProgressBarValue(gPlayerData[i][pEnergyProgressBarID], gPlayerData[i][pEnergy]);
					// UpdateProgressBar(gPlayerData[i][pEnergyProgressBarID], i);
					SetProgressBarValue(gPlayerData[i][pHungerProgressBarID], gPlayerData[i][pHunger]);
					UpdateProgressBar(gPlayerData[i][pHungerProgressBarID], i);
					SetProgressBarValue(gPlayerData[i][pThirstProgressBarID], gPlayerData[i][pThirst]);
					UpdateProgressBar(gPlayerData[i][pThirstProgressBarID], i);
					// SetProgressBarValue(gPlayerData[i][pPoisonProgressBarID], gPlayerData[i][pPoison]);
					// UpdateProgressBar(gPlayerData[i][pPoisonProgressBarID], i);
					// SetProgressBarValue(gPlayerData[i][pFatProgressBarID], gPlayerData[i][pFat]);
					// UpdateProgressBar(gPlayerData[i][pFatProgressBarID], i);
					SetProgressBarValue(gPlayerData[i][pStomachProgressBarID], gPlayerData[i][pStomach]);
					UpdateProgressBar(gPlayerData[i][pStomachProgressBarID], i);
					// SetProgressBarValue(gPlayerData[i][pVitaminsProgressBarID], gPlayerData[i][pVitamins]);
					// UpdateProgressBar(gPlayerData[i][pVitaminsProgressBarID], i);
					SetProgressBarValue(gPlayerData[i][pDrunkProgressBarID], gPlayerData[i][pDrunk]);
					UpdateProgressBar(gPlayerData[i][pDrunkProgressBarID], i);
					SetProgressBarValue(gPlayerData[i][pNarcoticProgressBarID], gPlayerData[i][pNarcotic]);
					UpdateProgressBar(gPlayerData[i][pNarcoticProgressBarID], i);
				}
				if(gPlayerData[i][pEnergy] == 0.0)
				{
					SendClientMessage(i, COLOR_LIGHTYELLOW2, "[INFO:] Jesteœ zmêczony, robi ci siê s³abo !");
					GetPlayerHealth(i, gPlayerData[i][pHP]);
					gPlayerData[i][pHP] -= 4.0;
					if(gPlayerData[i][pHP] < 0.0)
						gPlayerData[i][pHP] = 0.0;
					SetPlayerHealth(i, gPlayerData[i][pHP]);
					// save on exit
					if(LifeDecreaserTmpHP <= 30.0)
						SetPlayerDrunkLevelEx(i, 50000);
				}
				if(gPlayerData[i][pHP] < 30.0)
				{
					// TextDrawShowForPlayer(i, gTdLHealth);
					if(gAHeartBeat == -1)
						gAHeartBeat = Audio_Play(i, AUDIO_HEART_BEAT, false, true, false);
					if(gABreath == -1)
						gABreath = Audio_Play(i, AUDIO_BREATH, false, true, false);
					Audio_SetVolume(i, gAHeartBeat, 50);
					Audio_SetVolume(i, gABreath, 20);
				}
				else
				{
					TextDrawHideForPlayer(i, gTdLHealth);
					Audio_Stop(i, gAHeartBeat);
					Audio_Stop(i, gABreath);
					gAHeartBeat = -1;
					gABreath = -1;
				}
			}
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			/* Character needs */
#define ENERGY					0.8
#define MAX_ENERGY			100.0
#define MAX_ENERGY_VIP	150.0
#define HUNGER					2.0
#define MAX_HUNGER			100.0
#define MAX_HUNGER_VIP	150.0
#define THIRST						4.0
#define MAX_THIRST				100.0
#define MAX_THIRST_VIP		150.0
#define POISON					0.1
#define MAX_POISON			100.0
#define MAX_POISON_VIP		150.0
#define FAT							0.6
#define MAX_FAT					100.0
#define MAX_FAT_VIP			150.0
#define STOMACH					1.9
#define MAX_STOMACH		100.0
#define MAX_STOMACH_VIP	150.0
#define VITAMINS					2.0
#define MAX_VITAMINS			100.0
#define MAX_VITAMINS_VIP	150.0
#define DRUNK						2.0
#define MAX_DRUNK				100.0
#define MAX_DRUNK_VIP		100.0
#define NARCOTIC				2.0
#define MAX_NARCOTIC		100.0
#define MAX_NARCOTIC_VIP	150.0
#define MAX_SUBMEALS 		30 										// How many submeals player can have before stomach probles starts
#define MAX_SUBMEALS_HP_LOSS 20.0							// How much hp vomiting will take
