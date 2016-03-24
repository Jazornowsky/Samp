if(strcmp(cmd, "/wnetrzebiz", true) == 0)
		{
			if (PlayerInfo[playerid][pFaction] == 9)
			{
				new id;
				id = strval(tmp);
				tmp = strtok(cmdtext, idx);
				if(!strlen(tmp))
				{
					SendClientMessage(playerid, COLOR_WHITE, "[U¯YCIE:] /wnetrzebiz [id biznesu] [id wnetrza 1-41]");
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INTS:] [1:] Marcos Bistro (Eat) - [2:] Big Spread Ranch (Bar) - [3:] Burger Shot (Eat) - [4:] Cluckin Bell (EAT)");
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INTS:] [5:] Well Stacked Pizza (Eat) - [6:] Rusty Browns Dohnuts (Eat) - [7:] Jays Diner (Eat) - [8:] Pump Truck Stop Diner (Eat)");
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INTS:] [9:] Alhambra (Drink) - [10:] Mistys (Drink) - [11:] Lil' Probe Inn (Drink) - [12:] Exclusive (Clothes) - [13:] Binco (Clothes)");
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INTS:] [14:] ProLaps (Clothes) - [15:] SubUrban (Clothes) - 16: Victim (Clothes) - [17:] Zip (Clothes) - [18:] Redsands Casino");
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INTS:] [27:] Jizzys (Drink) - [27-33:] 24-7's (Buy) - [35:] Kibelek - [36:] Wiejskie Disco - [37:] Disco - [38:] Shop Elex ");
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INTS:] [39:] Restauracja - [40:] Restauracja ");

					/*SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "1 - 5 kk  ; 2 - 3 kk  ; 3 - 2 kk  ; 4 - 1,5 kk  ; 5 - 1,8 kk  ; 6 - 1,5 kk  ; 7 - 2 kk  ; 8 - 0 k  ; 9 - 4 kk  ; 10 - 1,4 kk ;");
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "11 - 1,3 kk ; 12 - 2 kk ; 13 - 1,8 kk ; 14 - 2,2 kk ; 15 - 1,8 kk ; 16 - 2,2 kk ; 17 - 1,9 kk ; 18 - 5 kk ; 19 - 5 kk ; 20 - 1 kk ;");
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "21 - 1,2 kk ; 22 - 1,2 kk ; 23 - 1,8 kk ; 24 - 6,5 kk ; 25 - 6,5 kk ; 26 - 6,3 kk ; 27 - 10 kk ; 28 - 4 kk ; 29 - 5 kk ; 30 - 4,5 kk ;");
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "31 - 4,5 kk ; 32 - 4 kk ; 33 - 3 kk ; 34 - 1 k ; 35 - 3 kk ;");
					*/
					return 1;
				}
				new id2;
				id2 = strval(tmp);
				if(id2 < 1 || id2 > 41) { SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Interior ID's 1-41."); return 1; }

				if(id2 == 1)
				{
					Businesses[id][ExitX] = -794.806396;
					Businesses[id][ExitY] = 489.284973;
					Businesses[id][ExitZ] = 1376.195;
					Businesses[id][ExitInterior] = 1;
					Businesses[id][ExitAngle] = 0.458332;
					format(string, sizeof string, "Business ID: %d - Description: Marcos Bistro.", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 2)
				{
					Businesses[id][ExitX] = 1212.265625;
					Businesses[id][ExitY] = -25.877540;
					Businesses[id][ExitZ] = 1001.089966;
					Businesses[id][ExitInterior] = 3;
					Businesses[id][ExitAngle] = 181.8332;
					format(string, sizeof string, "Business ID: %d - Description: Big Spread Ranch Strip Club.", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 3)
				{
					Businesses[id][ExitX] = 362.909484;
					Businesses[id][ExitY] = -75.193481;
					Businesses[id][ExitZ] = 1001.507812;
					Businesses[id][ExitInterior] = 10;
					Businesses[id][ExitAngle] = 311.5311;
					format(string, sizeof string, "Business ID: %d - Description: Burger Shot.", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 4)
				{
					Businesses[id][ExitX] = 365.672974;
					Businesses[id][ExitY] = -10.713200;
					Businesses[id][ExitZ] = 1001.869995;
					Businesses[id][ExitInterior] = 9;
					Businesses[id][ExitAngle] = 0.458332;
					format(string, sizeof string, "Business ID: %d - Description: Cluckin Bell.", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 5)
				{
					Businesses[id][ExitX] = 372.579650;
					Businesses[id][ExitY] = -133.515899;
					Businesses[id][ExitZ] = 1001.449951;
					Businesses[id][ExitInterior] = 5;
					Businesses[id][ExitAngle] = 3.834877;
					format(string, sizeof string, "Business ID: %d - Description: Well Stacked Pizza.", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 6)
				{
					Businesses[id][ExitX] = 377.098999;
					Businesses[id][ExitY] = -192.439987;
					Businesses[id][ExitZ] = 1000.643982;
					Businesses[id][ExitInterior] = 17;
					Businesses[id][ExitAngle] = 0.458332;
					format(string, sizeof string, "Business ID: %d - Description: Rusty Brown Dohnuts.", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 7)
				{
					Businesses[id][ExitX] = 460.099976;
					Businesses[id][ExitY] = -88.428497;
					Businesses[id][ExitZ] = 999.621948;
					Businesses[id][ExitInterior] = 4;
					Businesses[id][ExitAngle] = 0.458332;
					format(string, sizeof string, "Business ID: %d - Description: Jays Diner.", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 8)
				{
					Businesses[id][ExitX] = 681.474976;
					Businesses[id][ExitY] = -451.150970;
					Businesses[id][ExitZ] = -25.616798;
					Businesses[id][ExitInterior] = 1;
					Businesses[id][ExitAngle] = 0.458332;
					format(string, sizeof string, "Business ID: %d - Description: Pump Truck Stop Diner DZIURA W PODLODZE.", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 9)
				{
					Businesses[id][ExitX] = 493.484588;
					Businesses[id][ExitY] = -24.906007;
					Businesses[id][ExitZ] = 1000.671875;
					Businesses[id][ExitInterior] = 17;
					Businesses[id][ExitAngle] = 356.2913;
					format(string, sizeof string, "Business ID: %d - Description: Alhambra.", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 10)
				{
					Businesses[id][ExitX] = 502.039733;
					Businesses[id][ExitY] = -67.637390;
					Businesses[id][ExitZ] = 998.834961;
					Businesses[id][ExitInterior] = 11;
					Businesses[id][ExitAngle] = 191.93478;
					format(string, sizeof string, "Business ID: %d - Description: Mistys.", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 11)
				{
					Businesses[id][ExitX] = -229.289276;
					Businesses[id][ExitY] = 1401.314331;
					Businesses[id][ExitZ] = 27.769798;
					Businesses[id][ExitInterior] = 18;
					Businesses[id][ExitAngle] = 270.3904;
					format(string, sizeof string, "Business ID: %d - Description: Lil' Probe Inn.", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 12)
				{
					Businesses[id][ExitX] = 204.608230;
					Businesses[id][ExitY] = -168.851776;
					Businesses[id][ExitZ] = 1000.578979;
					Businesses[id][ExitInterior] = 14;
					Businesses[id][ExitAngle] = 6.87463;
					format(string, sizeof string, "Business ID: %d - Description: EXcLusive.", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 13)
				{
					Businesses[id][ExitX] = 207.801361;
					Businesses[id][ExitY] = -111.258720;
					Businesses[id][ExitZ] = 1005.269958;
					Businesses[id][ExitInterior] = 15;
					Businesses[id][ExitAngle] = 358.414;
					format(string, sizeof string, "Business ID: %d - Description: Binco.", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 14)
				{
					Businesses[id][ExitX] = 207.054993;
					Businesses[id][ExitY] = -138.804993;
					Businesses[id][ExitZ] = 1003.519958;
					Businesses[id][ExitInterior] = 3;
					Businesses[id][ExitAngle] = 0.458332;
					format(string, sizeof string, "Business ID: %d - Description: ProLaps.", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 15)
				{
					Businesses[id][ExitX] = 203.568298;
					Businesses[id][ExitY] = -50.662452;
					Businesses[id][ExitZ] = 1001.799988;
					Businesses[id][ExitInterior] = 1;
					Businesses[id][ExitAngle] = 356.82446;
					format(string, sizeof string, "Business ID: %d - Description: SubUrban.", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 16)
				{
					Businesses[id][ExitX] = 227.542633;
					Businesses[id][ExitY] = -8.100092;
					Businesses[id][ExitZ] = 1002.259949;
					Businesses[id][ExitInterior] = 5;
					Businesses[id][ExitAngle] = 88.921981;
					format(string, sizeof string, "Business ID: %d - Description: Victim.", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 17)
				{
					Businesses[id][ExitX] = 161.205780;
					Businesses[id][ExitY] = -97.102127;
					Businesses[id][ExitZ] = 1001.804687;
					Businesses[id][ExitInterior] = 18;
					Businesses[id][ExitAngle] = 356.4877;
					format(string, sizeof string, "Business ID: %d - Description: Zip.", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 18)
				{
					Businesses[id][ExitX] = 1133.523559;
					Businesses[id][ExitY] = -15.807713;
					Businesses[id][ExitZ] = 1000.750000;
					Businesses[id][ExitInterior] = 12;
					Businesses[id][ExitAngle] = 0.22441;
					format(string, sizeof string, "Business ID: %d - Description: Small Casino in Redsands West.", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 19)
				{
					Businesses[id][ExitX] = 834.660888;
					Businesses[id][ExitY] = 7.240708;
					Businesses[id][ExitZ] = 1004.179993;
					Businesses[id][ExitInterior] = 3;
					Businesses[id][ExitAngle] = 92.031906;
					format(string, sizeof string, "Business ID: %d - Description: Off Track Betting.", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 20)
				{
					Businesses[id][ExitX] = -100.083061;
					Businesses[id][ExitY] = -25.029542;
					Businesses[id][ExitZ] = 1000.741943;
					Businesses[id][ExitInterior] = 3;
					Businesses[id][ExitAngle] = 0.224439;
					format(string, sizeof string, "Business ID: %d - Description: Sex Shop.", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 21)
				{
					Businesses[id][ExitX] = -2240.955322;
					Businesses[id][ExitY] = 128.451400;
					Businesses[id][ExitZ] = 1035.419922;
					Businesses[id][ExitInterior] = 6;
					Businesses[id][ExitAngle] = 268.416;
					format(string, sizeof string, "Business ID: %d - Description: Zero's RC Shop.", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 22)
				{
					Businesses[id][ExitX] = 285.404602;
					Businesses[id][ExitY] = -41.745178;
					Businesses[id][ExitZ] = 1001.569946;
					Businesses[id][ExitInterior] = 1;
					Businesses[id][ExitAngle] =357.69436;
					format(string, sizeof string, "Business ID: %d - Description: Ammunation 1.", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 23)
				{
					Businesses[id][ExitX] = 285.780487;
					Businesses[id][ExitY] = -86.71318;
					Businesses[id][ExitZ] = 1001.539978;
					Businesses[id][ExitInterior] = 4;
					Businesses[id][ExitAngle] = 351.74093;
					format(string, sizeof string, "Business ID: %d - Description: Ammunation 2.", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 24)
				{
					Businesses[id][ExitX] = 296.711975;
					Businesses[id][ExitY] = -112.048240;
					Businesses[id][ExitZ] = 1001.569946;
					Businesses[id][ExitInterior] = 6;
					Businesses[id][ExitAngle] = 358.6343;
					format(string, sizeof string, "Business ID: %d - Description: Ammunation 3.", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 25)
				{
					Businesses[id][ExitX] = 316.569549;
					Businesses[id][ExitY] = -170.279464;
					Businesses[id][ExitZ] = 999.661987;
					Businesses[id][ExitInterior] = 6;
					Businesses[id][ExitAngle] = 2.081076;
					format(string, sizeof string, "Business ID: %d - Description: Ammunation 4.", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 26)
				{
					Businesses[id][ExitX] = 304.572479;
					Businesses[id][ExitY] = -142.094192;
					Businesses[id][ExitZ] = 1004.062500;
					Businesses[id][ExitInterior] = 7;
					Businesses[id][ExitAngle] = 94.17852;
					format(string, sizeof string, "Business ID: %d - Description: Ammunation Shooting Range.", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 27)
				{
					Businesses[id][ExitX] = -2636.974121;
					Businesses[id][ExitY] = 1402.319213;
					Businesses[id][ExitZ] = 906.457947;
					Businesses[id][ExitInterior] = 3;
					Businesses[id][ExitAngle] = 8.61428;
					format(string, sizeof string, "Business ID: %d - Description: Jizzys.", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 28)
				{
					Businesses[id][ExitX] = -25.819719;
					Businesses[id][ExitY] = -188.238037;
					Businesses[id][ExitZ] = 1003.549988;
					Businesses[id][ExitInterior] = 17;
					Businesses[id][ExitAngle] = 1.72090;
					format(string, sizeof string, "Business ID: %d - Description: 24-7 1.", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 29)
				{
					Businesses[id][ExitX] = 5.933865;
					Businesses[id][ExitY] = -31.750873;
					Businesses[id][ExitZ] = 1003.549988;
					Businesses[id][ExitInterior] = 10;
					Businesses[id][ExitAngle] = 359.527526;
					format(string, sizeof string, "Business ID: %d - Description: 24-7 2.", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 30)
				{
					Businesses[id][ExitX] = -30.683946;
					Businesses[id][ExitY] = -92.002952;
					Businesses[id][ExitZ] = 1003.549988;
					Businesses[id][ExitInterior] = 18;
					Businesses[id][ExitAngle] = 2.660877;
					format(string, sizeof string, "Business ID: %d - Description: 24-7 3.", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 31)
				{
					Businesses[id][ExitX] = -25.878168;
					Businesses[id][ExitY] = -141.549636;
					Businesses[id][ExitZ] = 1003.549988;
					Businesses[id][ExitInterior] = 16;
					Businesses[id][ExitAngle] = 352.320;
					format(string, sizeof string, "Business ID: %d - Description: 24-7 4.", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 32)
				{
					Businesses[id][ExitX] = -27.321363;
					Businesses[id][ExitY] = -31.754938;
					Businesses[id][ExitZ] = 1003.549988;
					Businesses[id][ExitInterior] = 4;
					Businesses[id][ExitAngle] = 356.70745;
					format(string, sizeof string, "Business ID: %d - Description: 24-7 5.", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 33)
				{
					Businesses[id][ExitX] = -27.389696;
					Businesses[id][ExitY] = -58.260951;
					Businesses[id][ExitZ] = 1003.549988;
					Businesses[id][ExitInterior] = 6;
					Businesses[id][ExitAngle] = 358.27413;
					Businesses[id][BizPrice] = 4000000;
					format(string, sizeof string, "Business ID: %d - Description: 24-7 6.", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 35)
				{
					Businesses[id][ExitX] = -2213.684814;
					Businesses[id][ExitY] = 1143.244140;
					Businesses[id][ExitZ] = 173.895568;
					Businesses[id][ExitInterior] = 0;
					Businesses[id][ExitAngle] = 0.0;
					format(string, sizeof string, "Business ID: %d - Description: Kibelek", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 36)
				{
					Businesses[id][ExitX] = -461.70;
					Businesses[id][ExitY] = -2016.68;
					Businesses[id][ExitZ] = 24.97;
					Businesses[id][ExitInterior] = 1;
					Businesses[id][ExitAngle] = 0.0;
					format(string, sizeof string, "Business ID: %d - Description: Wiejskie Disco", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 37)
				{
					Businesses[id][ExitX] = 1285.54;
					Businesses[id][ExitY] = -1652.21;
					Businesses[id][ExitZ] = 13.74;
					Businesses[id][ExitInterior] = 0;
					Businesses[id][ExitAngle] = 0.458332;
					format(string, sizeof string, "Business ID: %d - Description: Disco", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 38)
				{
					Businesses[id][ExitX] = 1003.77;
					Businesses[id][ExitY] = 52.20;
					Businesses[id][ExitZ] = 55.42;
					Businesses[id][ExitInterior] = 3;
					Businesses[id][ExitAngle] = 0.458332;
					format(string, sizeof string, "Business ID: %d - Description: Sklep Elektrolux", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 39)
				{
					Businesses[id][ExitX] = 1513.09;
					Businesses[id][ExitY] = -1576.66;
					Businesses[id][ExitZ] = 24.55;
					Businesses[id][ExitInterior] = 0;
					Businesses[id][ExitAngle] = 0.458332;
					format(string, sizeof string, "Business ID: %d - Description: Restauracja", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 40)
				{
					Businesses[id][ExitX] = 370.46;
					Businesses[id][ExitY] = -1720.76;
					Businesses[id][ExitZ] = 17.1;
					Businesses[id][ExitInterior] = 0;
					Businesses[id][ExitAngle] = 0.458332;
					format(string, sizeof string, "Business ID: %d - Description: Restauracja", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 41)
				{
					Businesses[id][ExitX] = Businesses[id][EnterX];
					Businesses[id][ExitY] = Businesses[id][EnterY];
					Businesses[id][ExitZ] = Businesses[id][EnterZ];
					Businesses[id][ExitInterior] = 0;
					Businesses[id][ExitAngle] = 0.0;
					format(string, sizeof string, "Business ID: %d - Description: Kibelek", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				SaveBizData(id, "ExitX");
				SaveBizData(id, "ExitY");
				SaveBizData(id, "ExitZ");
				SaveBizData(id, "ExitInterior");
				SaveBizData(id, "ExitAngle");
				
				format(string, sizeof(string), "[GOVERNMENT:] Business interior change by: %s, biz id: %d, interior id: %d", PlayerInfo[playerid][pName], id, id2);
				GovermentLog(string);
			}
			else
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "nie jesteœ urzednikiem.");
			return 1;
		}