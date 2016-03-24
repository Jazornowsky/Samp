public OnPlayerCommandText(playerid, cmdtext[])
{
	dcmd(loguj,5,cmdtext);
	dcmd(l,1,cmdtext);
	dcmd(rejestruj,9,cmdtext);
	if(gPlayerLogged[playerid])
	{
		// dcmd(specplayer,10,cmdtext);
		dcmd(specoff,7,cmdtext);
		dcmd(noooc,5,cmdtext);
		dcmd(owoj1,5,cmdtext);
		dcmd(owoj2,5,cmdtext);
		dcmd(zwoj2,5,cmdtext);
		dcmd(zslums,6,cmdtext);
		dcmd(oslums,6,cmdtext);
		dcmd(ozomo0,6,cmdtext);
		dcmd(ozomo1,6,cmdtext);
		dcmd(ozomo2,6,cmdtext);
		dcmd(zmost,5,cmdtext);
		dcmd(omost,5,cmdtext);
		dcmd(ohq,4,cmdtext);
		dcmd(ohq2,4,cmdtext);
		dcmd(abizowner,9,cmdtext);
		dcmd(ahouseowner,11,cmdtext);
		dcmd(aplayerbizid,12,cmdtext);
		dcmd(radios,6,cmdtext);
		dcmd(radiosoff,9,cmdtext);
		dcmd(podatki1,8,cmdtext);
		dcmd(podatki2,8,cmdtext);
		dcmd(komendywojska,13,cmdtext);
		dcmd(wlamsiedopojazdu,16,cmdtext);
		dcmd(abizreset,9,cmdtext);
		dcmd(ahousesreset,12,cmdtext);
		dcmd(acarsreset,10,cmdtext);
		dcmd(ahousedata,10,cmdtext);
		dcmd(abizdata,8,cmdtext);
		dcmd(acarmodelprice,14,cmdtext);
		dcmd(acarparkdynamic,15,cmdtext);
		dcmd(arepairallvehicles,18,cmdtext);
		dcmd(ajail,5,cmdtext);
		dcmd(abuildingopent,14,cmdtext);
		dcmd(abuildingcloset,15,cmdtext);
		dcmd(kupczesci,9,cmdtext);
		dcmd(naprawpojazd,12,cmdtext);
		dcmd(amechanicjobpos,15,cmdtext);
		dcmd(amechanicrepairpoint,20,cmdtext);
		dcmd(amechanicrepairpoint2,21,cmdtext);
		dcmd(amechanicpartspoint,19,cmdtext);
		dcmd(fixdamage,9,cmdtext);
		dcmd(resetpracy,10,cmdtext);
		dcmd(przewodnik,10,cmdtext);
		dcmd(staxi,5,cmdtext);
		dcmd(reanimuj,8,cmdtext);
		dcmd(smierc,6,cmdtext);
		dcmd(wyrobkarte,10,cmdtext);
		dcmd(kuppojazdf,10,cmdtext);
		dcmd(zezlomujpojazdf,15,cmdtext);
		dcmd(sprowadzpojazd,14,cmdtext);
		dcmd(statuszamowien,14,cmdtext);
		dcmd(cenapojazdu,11,cmdtext);
		dcmd(aplayercmds,11,cmdtext);
		dcmd(achatcmds,9,cmdtext);
		dcmd(afactioncmds,12,cmdtext);
		dcmd(abuildingcmds,13,cmdtext);
		dcmd(abusinesscmds,13,cmdtext);
		dcmd(ahousecmds,10,cmdtext);
		dcmd(ajobcmds,8,cmdtext);
		dcmd(alocationscmds,14,cmdtext);
		dcmd(avehcmds,8,cmdtext);
		dcmd(umowaoc,7,cmdtext);
		dcmd(umowaac,7,cmdtext);
		dcmd(zrezygnujzoc,12,cmdtext);
		dcmd(zrezygnujzac,12,cmdtext);
		dcmd(wyplacodszkodowanieoc,21,cmdtext);
		dcmd(wyplacodszkodowanieac,21,cmdtext);
		dcmd(przemaluj,9,cmdtext);
		dcmd(acarbiz,7,cmdtext);
		dcmd(abusinessmaxcars,16,cmdtext);
		dcmd(acarint,7,cmdtext);
		dcmd(acarrepairtl,12,cmdtext);
		dcmd(acarresett,10,cmdtext);
		dcmd(acarclosed,10,cmdtext);
		dcmd(abizvehorders,13,cmdtext);
		dcmd(abizvehcount,12,cmdtext);
		dcmd(abizvehspawned,14,cmdtext);
		// dcmd(a3dvehids,9,cmdtext);
		dcmd(sprawdzoc,9,cmdtext);
		dcmd(sprzedajpojazd,14,cmdtext);
		dcmd(anulujsprzedazpojazdu,21,cmdtext);
		dcmd(ulecz,5,cmdtext);
		dcmd(pozszywaj,9,cmdtext);
		dcmd(sprzedajpojazdf,15,cmdtext);
		dcmd(anulujsprzedazpojazduf,22,cmdtext);
		dcmd(statusfrakcji,13,cmdtext);
		dcmd(abusinesstill,13,cmdtext);
		dcmd(abusinessaddtill,16,cmdtext);
		dcmd(afactionmaxvehicles,19,cmdtext);
		dcmd(afactionvehiclescount,21,cmdtext);
		dcmd(statusvip,9,cmdtext);
		dcmd(uzyjnarkotykow,14,cmdtext);
		dcmd(detoksykacja,12,cmdtext);
		dcmd(napelnijzbiorniki,17,cmdtext);
		dcmd(stanstacji,10,cmdtext);
		dcmd(komendyrafinerii,16,cmdtext);
		dcmd(cenazalitrbenzyny,17,cmdtext);
		dcmd(cenazalitrropy,14,cmdtext);
		dcmd(cenazalitrgazu,14,cmdtext);
		dcmd(cenazalitrsbenzyny,18,cmdtext);
		dcmd(cenazalitrsropy,15,cmdtext);
		dcmd(cenazalitrsgazu,15,cmdtext);
		dcmd(wynagrodzenie,13,cmdtext);
		dcmd(uzupelnianiebenzyny,19,cmdtext);
		dcmd(uzupelnianieropy,16,cmdtext);
		dcmd(uzupelnianiegazu,16,cmdtext);		
		dcmd(abizidtogasstation,18,cmdtext);
		dcmd(giveplayerweapon,16,cmdtext);
		dcmd(setrafineryresources,20,cmdtext);
		dcmd(setRafineryResources2,21,cmdtext);
		dcmd(setRafineryResources3,21,cmdtext);
		dcmd(setmaxrafineryresources,23,cmdtext);
		dcmd(rafinerycmds,12,cmdtext);
		dcmd(setrafineryltrcost,18,cmdtext);
		dcmd(setrafineryltrcost2,19,cmdtext);
		dcmd(setrafineryltrcost3,19,cmdtext);
		dcmd(setgasstationresources,22,cmdtext);
		dcmd(setgasstationresources2,23,cmdtext);
		dcmd(setgasstationresources3,23,cmdtext);
		dcmd(setgasstationmaxresources,25,cmdtext);
		dcmd(setgasstationmaxresources2,26,cmdtext);
		dcmd(setgasstationmaxresources3,26,cmdtext);
		dcmd(setgasstationfuelprice,22,cmdtext);
		dcmd(setgasstationfuelprice2,23,cmdtext);
		dcmd(setgasstationfuelprice3,23,cmdtext);
		dcmd(payday,6,cmdtext);
		dcmd(acarreadytosell,15,cmdtext);
		dcmd(acarbusinessid,14,cmdtext);
		dcmd(afillcarstable,14,cmdtext);
		dcmd(savepayrank,11,cmdtext);
		dcmd(nofooc,6,cmdtext);
		dcmd(nopwooc,7,cmdtext);
		dcmd(przekazlidera,13,cmdtext);
		dcmd(azoneowner,10,cmdtext);
		dcmd(acarkm,6,cmdtext);
		dcmd(mojeitemy,9,cmdtext);
		dcmd(mi,2,cmdtext);
		// dcmd(wyrzucitem,10,cmdtext);
		// dcmd(przekazitem,11,cmdtext);
		dcmd(additem,7,cmdtext);
		dcmd(rmplayeritem,12,cmdtext);
		dcmd(vipitem,7,cmdtext);
		dcmd(playeritems,11,cmdtext);
		dcmd(aservercmds,11,cmdtext);
		dcmd(savebiz,7,cmdtext);
		dcmd(afillbiztable,13,cmdtext);
		dcmd(afillhousetable,15,cmdtext);
		dcmd(housesource,11,cmdtext);
		dcmd(savehouses,10,cmdtext);
		dcmd(miwd,4,cmdtext);
		dcmd(wezitemzdomu,12,cmdtext);
		dcmd(wlozitemdodomu,14,cmdtext);
		dcmd(setcarserial,12,cmdtext);
		dcmd(setcarserialtoall,17,cmdtext);
		dcmd(savefactions,12,cmdtext);
		dcmd(afillftable,11,cmdtext);
		dcmd(pktorganizacyjny,16,cmdtext);
		dcmd(przebierzsie,12,cmdtext);
		dcmd(givelev,7,cmdtext);
		dcmd(addlev,6,cmdtext);
		dcmd(addexp,6,cmdtext);
		dcmd(giveexp,7,cmdtext);
		dcmd(rfdata,6,cmdtext);
		dcmd(wl,2,cmdtext);
		dcmd(statuspojazdow,14,cmdtext);
		dcmd(gcash,5,cmdtext);
		dcmd(gbank,5,cmdtext);
		dcmd(ghousecash,10,cmdtext);
		dcmd(gfaccash,8,cmdtext);
		dcmd(gbizcash,8,cmdtext);
		dcmd(pasy,4,cmdtext);
		dcmd(sprawdzpasy,11,cmdtext);
		dcmd(wdgaraz,7,cmdtext);
		dcmd(wzgaraz,7,cmdtext);
		dcmd(panoramaon,10,cmdtext);
		dcmd(panoramaoff,11,cmdtext);
		dcmd(unban,5,cmdtext);
		dcmd(opisdomu,8,cmdtext);
		dcmd(asellerjobpos,13,cmdtext);
		dcmd(aaccountantjobpos,17,cmdtext);
		dcmd(ww,2,cmdtext);
		dcmd(zmienrejestracje,16,cmdtext);
		dcmd(wejdznaskocznie,15,cmdtext);
		dcmd(stanpojazdu,11,cmdtext);
		//dcmd(wezpilke,8,cmdtext);
		dcmd(apjob,5,cmdtext);
		dcmd(przedstawrozliczenie,20,cmdtext);
		dcmd(vehdamage,9,cmdtext);
		dcmd(explodencars,12,cmdtext);
		dcmd(wymianaopon,11,cmdtext);
		dcmd(additemex,9,cmdtext);
		// dcmd(afk,3,cmdtext);
		// dcmd(lightfw,7,cmdtext);
		// dcmd(fwcp,4,cmdtext);
		dcmd(fixwheels,9,cmdtext);
		dcmd(afillhouseitemstable,20,cmdtext);
		dcmd(holuj,5,cmdtext);
		dcmd(acaralarm,9,cmdtext);
		dcmd(otworzmaske,11,cmdtext);
		dcmd(otworzbagaznik,14,cmdtext);
		dcmd(zamknijbagaznik,15,cmdtext);
		dcmd(zamknijmaske,12,cmdtext);
		dcmd(wymienzarowke,13,cmdtext);
		dcmd(kolczatka,9,cmdtext);
		dcmd(zwinkolczatke,13,cmdtext);
		dcmd(zapallampki,11,cmdtext);
		dcmd(zgaslampki,10,cmdtext);
		dcmd(lightdamagevalue,16,cmdtext);
		dcmd(acarenters,10,cmdtext);
		dcmd(acarentersex,12,cmdtext);
		dcmd(zamontujhak,11,cmdtext);
		dcmd(agodmode,8,cmdtext);
		dcmd(acarmodel,9,cmdtext);
		dcmd(acarcolor,9,cmdtext);
		dcmd(acarcolorex,11,cmdtext);
		dcmd(gotoap,6,cmdtext);
		dcmd(gotosf,6,cmdtext);
		dcmd(gotosf2,7,cmdtext);
		dcmd(gotomg,6,cmdtext);
		dcmd(acarcomponentslot,17,cmdtext);
		dcmd(acaraddcomponent,16,cmdtext);
		dcmd(acarcomponentslottype,21,cmdtext);
		dcmd(acarpark,8,cmdtext);
		dcmd(avehfueltype,12,cmdtext);
		dcmd(montazgazu,10,cmdtext);
		dcmd(zamontujalarm,13,cmdtext);
		dcmd(wantedex,8,cmdtext);
		dcmd(pktorganizacyjny2,17,cmdtext);
		dcmd(ignorujooc,10,cmdtext);
		dcmd(afiregov2,9,cmdtext);
		dcmd(pobierzgazety,13,cmdtext);
		dcmd(rzucgazete,10,cmdtext);
		dcmd(anewsboyjobpos,14,cmdtext);
		dcmd(anewsboyjobreward,17,cmdtext);
		dcmd(anewsboyjobpapers,17,cmdtext);
		dcmd(aradio,6,cmdtext);
		dcmd(aradiovol,9,cmdtext);
		dcmd(sprzedajnarkotyki,17,cmdtext);
		dcmd(animacje,8,cmdtext);
		dcmd(gotoxyz,7,cmdtext);
		dcmd(loginonoff,10,cmdtext);
		dcmd(abizproducts,12,cmdtext);
		dcmd(gotopc,6,cmdtext);
		dcmd(gstl1pos,8,cmdtext);
		dcmd(gstl2pos,8,cmdtext);
		dcmd(gspos,5,cmdtext);
		dcmd(cdp,3,cmdtext);
		dcmd(menubroni,9,cmdtext);
		dcmd(savebuildings,13,cmdtext);
		dcmd(fabryka,7,cmdtext);
		dcmd(fillbuildingstable,18,cmdtext);
		dcmd(rfactory,8,cmdtext);
		dcmd(odczepnaczepe,13,cmdtext);
		dcmd(skladaj,7,cmdtext);
		dcmd(radiosv,7,cmdtext);
		dcmd(podpalfab,9,cmdtext);
		dcmd(ugasfab,7,cmdtext);
		dcmd(pobierzczesci,13,cmdtext);
		dcmd(setcameratop,12,cmdtext);
		dcmd(setcameranorm,13,cmdtext);
		dcmd(quat,4,cmdtext);
		dcmd(wlascicielpoj,13,cmdtext);
		dcmd(zamowbron,9,cmdtext);
		dcmd(mp,2,cmdtext);
		dcmd(komendypojazdow,15,cmdtext);
		dcmd(b,1,cmdtext);
		dcmd(o,1,cmdtext);
		dcmd(ja,2,cmdtext);
		dcmd(me,2,cmdtext);
		dcmd(do,2,cmdtext);
		dcmd(factorytakecp,13,cmdtext);
		dcmd(gotofactorytakecp,17,cmdtext);
		dcmd(factorysetup1,13,cmdtext);
		dcmd(factorysetup2,13,cmdtext);
		dcmd(factorysetup3,13,cmdtext);
		dcmd(factorysetup4,13,cmdtext);
		dcmd(factorysetup5,13,cmdtext);
		dcmd(factorysetup6,13,cmdtext);
		dcmd(factoryasetup1,14,cmdtext);
		dcmd(factoryasetup2,14,cmdtext);
		dcmd(factoryasetup3,14,cmdtext);
		dcmd(factoryasetup4,14,cmdtext);
		dcmd(factoryasetup5,14,cmdtext);
		dcmd(factoryasetup6,14,cmdtext);
		dcmd(afactorylegalcmds,17,cmdtext);
		dcmd(fillfactoryparts,16,cmdtext);
		dcmd(proba,5,cmdtext);
		dcmd(afactorycmds,12,cmdtext);
		dcmd(gotofduty,9,cmdtext);
		dcmd(fillfactionweapons,18,cmdtext);
		dcmd(awfworkerjobpos,15,cmdtext);
		dcmd(radiod,6,cmdtext);
		dcmd(radiodv,7,cmdtext);
		// dcmd(ustawradio,10,cmdtext);
		dcmd(radiodoff,9,cmdtext);
		dcmd(gotofactorytakecpi,18,cmdtext);
		dcmd(setstartspawn,13,cmdtext);
		dcmd(setstartmoney,13,cmdtext);
		dcmd(setstartbank,12,cmdtext);
		dcmd(setstartskin,12,cmdtext);
		dcmd(vehtank,7,cmdtext);
		dcmd(fillbtable,10,cmdtext);
		dcmd(reconnect,9,cmdtext);
		dcmd(rp,2,cmdtext);
		dcmd(afillcarscpartstable,20,cmdtext);
		dcmd(avehpj,6,cmdtext);
		dcmd(radiob,6,cmdtext);
		dcmd(radiozabierz,12,cmdtext);
		dcmd(radioboff,9,cmdtext);
		dcmd(radiobv,7,cmdtext);
		dcmd(wjedzdogarazu,13,cmdtext);
		dcmd(wyjedzzgarazu,13,cmdtext);
		dcmd(zwrocczesci,11,cmdtext);
		dcmd(buyfactorycp,12,cmdtext);
		dcmd(gotodm,6,cmdtext);
		dcmd(gotobb,6,cmdtext);
		dcmd(doczepneon,10,cmdtext);
		dcmd(onoffneon,9,cmdtext);
		dcmd(ustawneon,9,cmdtext);
		dcmd(obrocneon,9,cmdtext);
		dcmd(idznaspacerniak,15,cmdtext);
		dcmd(wrocdowiezienia,15,cmdtext);
		dcmd(czesci,6,cmdtext);
		dcmd(ao,2,cmdtext);
		dcmd(ileneonow,9,cmdtext);
		dcmd(uwolnij,7,cmdtext);
		dcmd(descobj,7,cmdtext);
		dcmd(gotocobj,8,cmdtext);
		dcmd(fillobjtable,12,cmdtext);
		dcmd(wnetrzebiz,10,cmdtext);
		dcmd(onofftraseb,11,cmdtext);
		dcmd(ustawcpb,8,cmdtext);
		dcmd(vehtypelist,11,cmdtext);
		dcmd(fillbustracks,13,cmdtext);
		dcmd(trasyon,7,cmdtext);
		dcmd(filltuning,10,cmdtext);
		dcmd(abizprice,9,cmdtext);
		dcmd(podladujakumulator,18,cmdtext);
		dcmd(produkty,8,cmdtext);
		dcmd(fullbatteries,13,cmdtext);
		dcmd(fullbattery,11,cmdtext);
		dcmd(offvehlights,12,cmdtext);
		dcmd(offvehradio,11,cmdtext);
		dcmd(radio,5,cmdtext);
		dcmd(taxi,4,cmdtext);
		dcmd(utworzfrakcje,13,cmdtext);
		dcmd(usunfrakcje,11,cmdtext);
		dcmd(snews,5,cmdtext);
		dcmd(news,4,cmdtext);
		dcmd(spec,4,cmdtext);
		dcmd(fillfactionstable,17,cmdtext);
		dcmd(ustawopis,9,cmdtext);
		dcmd(pokazopis,9,cmdtext);
		dcmd(usunopis,8,cmdtext);
		dcmd(koloropisu,10,cmdtext);
		dcmd(opis,4,cmdtext);
		dcmd(obiekty,7,cmdtext);
		dcmd(prosbaobiznes,13,cmdtext);
		dcmd(wypelnijkupon,13,cmdtext);
		dcmd(ostatnielosowanie,17,cmdtext);
		dcmd(filllotterytable,16,cmdtext);
		dcmd(lotterycash,11,cmdtext);
		dcmd(kumulacja,9,cmdtext);
		dcmd(wyrzucgracza,12,cmdtext);
		dcmd(glosujza,8,cmdtext);
		dcmd(dap,3,cmdtext);
		dcmd(abizconfiscated,15,cmdtext);
		dcmd(abizlock,8,cmdtext);
		dcmd(wlozitemdopojazdu,17,cmdtext);
		dcmd(widp,4,cmdtext);
		dcmd(miwp,4,cmdtext);
		dcmd(przejmijster,12,cmdtext);
		dcmd(opuscster,9,cmdtext);
		dcmd(wheelchangepos,14,cmdtext);
		dcmd(bizplaced,9,cmdtext);
		dcmd(houseplaced,11,cmdtext);
		dcmd(bizintset,9,cmdtext);
		dcmd(houseintset,11,cmdtext);
		dcmd(danebiz,7,cmdtext);
		dcmd(danedomu,8,cmdtext);
		dcmd(itemfactorycmds,15,cmdtext);
		dcmd(itemfactorydata,15,cmdtext);
		dcmd(itemfactoryname,15,cmdtext);
		dcmd(itemfactoryitem,15,cmdtext);
		dcmd(itemfactorypos,14,cmdtext);
		dcmd(itemfactorycount,16,cmdtext);
		dcmd(itemfactoryminbuy,17,cmdtext);
		dcmd(itemfactoryproducecount,23,cmdtext);
		dcmd(itemfactoryprice,16,cmdtext);
				
		// dcmd(fixldrzwi,9,cmdtext);
		// dcmd(setwfactorysetupcp1,19,cmdtext);
		// dcmd(setwfactorytakecp,17,cmdtext);
		// dcmd(ahalogeny,9,cmdtext);
		//dcmd(zwiaz,
		//dcmd(tuning,6,cmdtext);
		//dcmd(zatankujzkanistra,17,cmdtext);
		
		//==================================================[Animations]===============================================
		dcmd(siad,4,cmdtext);
		dcmd(zygaj1,6,cmdtext);
		dcmd(zygaj2,6,cmdtext);
		dcmd(tancz1,6,cmdtext);
		dcmd(tancz2,6,cmdtext);
		dcmd(tancz3,6,cmdtext);
		dcmd(tancz4,6,cmdtext);
		dcmd(tancz5,6,cmdtext);
		dcmd(tancz6,6,cmdtext);
		dcmd(tancz7,6,cmdtext);		
		
		//====================================================[Creates]================================================
		dcmd(c3dtv,5,cmdtext);
		dcmd(d3dt,4,cmdtext);
		dcmd(makeobj,7,cmdtext);
		dcmd(moatv,5,cmdtext);
		dcmd(rvobj,5,cmdtext);
		dcmd(mvvobj,6,cmdtext);
		dcmd(rotvobj,7,cmdtext);
		dcmd(removeobj,9,cmdtext);
		dcmd(aotv,4,cmdtext);
		dcmd(movobj,6,cmdtext);
		dcmd(setobjpos,9,cmdtext);
		dcmd(rotobj,6,cmdtext);
		dcmd(stworzobiekt,12,cmdtext);
		dcmd(daneobiektow,12,cmdtext);
		dcmd(usunobiekt,10,cmdtext);
		dcmd(przesunobiekt,13,cmdtext);
		dcmd(obrocobiekt,11,cmdtext);
		dcmd(ustawobiekt,11,cmdtext);
		dcmd(setcarrserial,13,cmdtext);
		dcmd(setvehhp,8,cmdtext);
		dcmd(svhp,4,cmdtext);
	}

	new string[256];
	new cmd[256];
	new idx;
	cmd = strtok(cmdtext, idx);
	new giveplayer[MAX_PLAYER_NAME];
	new sendername[MAX_PLAYER_NAME];
	new giveplayername[MAX_PLAYER_NAME];
	new idcar = GetPlayerVehicleID(playerid);
	new tmpcar = GetPlayerVehicleID(playerid) - 1;
	new tmp[256];
	new giveplayerid;

	
	if(gPlayerData[playerid][pCharacterDying] == 0 && !PlayerCuffed[playerid] && !IsPlayerInAnyVehicle(playerid))
	{
		// if (strcmp(cmd, "/pijany", true) ==0 )
		// {
			// ApplyAnimation(playerid,"PED","WALK_DRUNK",4.1,1,1,1,1,1);
			// return 1;
		// }
		if(strcmp(cmd, "/recedogory", true) == 0)
		{
			SetPlayerSpecialAction(playerid,SPECIAL_ACTION_HANDSUP);
			return 1;
		}
		if(strcmp(cmd, "/cygaro", true) == 0)
		{
			new slot = PHaveItem(playerid, 1, 12);
			if(slot > 0)
			{
				SetPlayerSpecialAction(playerid,SPECIAL_ACTION_SMOKE_CIGGY);
				RemovePlayerItemExUsed(playerid, slot);
			}
			else
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz cygara");
			}
			return 1;
		}
		// if(strcmp(cmd, "/uzyjkomorki", true) == 0)
		// {
			// SetPlayerSpecialAction(playerid,SPECIAL_ACTION_USECELLPHONE);
			// return 1;
		// }
		if(strcmp(cmd, "/schowajkomorke", true) == 0)
		{
			SetPlayerSpecialAction(playerid,SPECIAL_ACTION_STOPUSECELLPHONE);
			RemovePlayerAttachedObject(playerid, 4);
			return 1;
		}
		if (strcmp(cmd, "/bat", true) ==0 )
		{
			ApplyAnimation(playerid,"CRACK","Bbalbat_Idle_01",4.0,0,1,1,0,0);
			return 1;
		}
		if (strcmp(cmd, "/caluj", true) ==0 )
		{
			ApplyAnimation(playerid,"BD_FIRE","Grlfrd_Kiss_03",4.0,0,1,1,0,0);
			return 1;
		}
		// if (strcmp(cmd, "/blowjob", true) ==0 )
		// {
			// ApplyAnimation(playerid,"benchpress","gym_bp_geton",4.0,1,1,1,0,0);
			// return 1;
		// }
		// if (strcmp(cmd, "/bomba", true) ==0 )
		// {
			// ApplyAnimation(playerid,"BOMBER","BOM_Plant",4.0,0,1,1,0,0);
			// return 1;
		// }
		// if (strcmp(cmd, "/slic", true) ==0 )
		// {
			// ApplyAnimation(playerid,"BSKTBALL","BBALL_walk",4.0,0,1,1,0,0);
			// return 1;
		// }
		// if (strcmp(cmd, "/reload", true) ==0 )
		// {
			// ApplyAnimation(playerid,"COLT45","sawnoff_reload",4.0,0,1,1,0,0);
			// return 1;
		// }
		if (strcmp(cmd, "/padnij2", true) ==0 )
		{
			ApplyAnimation(playerid,"CRACK","crckdeth2",4.0,0,1,1,0,0);
			return 1;
		}
		// if (strcmp(cmd, "/jumpnroll", true) ==0 )
		// {
			// ApplyAnimation(playerid,"DAM_JUMP","Jump_Roll",4.0,0,1,1,1,0);
			// return 1;
		// }
		if (strcmp(cmd, "/stoj", true) ==0 )
		{
			ApplyAnimation(playerid,"DEALER","DEALER_IDLE",4.0,1,0,0,1,1);
			return 1;
		}
		if (strcmp(cmd, "/deal", true) ==0 )
		{
			ApplyAnimation(playerid,"DEALER","DEALER_DEAL",4.0,0,1,1,0,0);
			return 1;
		}
		if (strcmp(cmd, "/gsign", true) ==0 )
		{
			ApplyAnimation(playerid,"GHANDS","gsign1",4.0,0,1,1,0,0);
			return 1;
		}
		if (strcmp(cmd, "/zaloz", true) ==0 )
		{
			ApplyAnimation(playerid,"goggles","goggles_put_on",3.0,0,1,1,0,0);
			return 1;
		}
		if (strcmp(cmd, "/spray", true) ==0 )
		{
			ApplyAnimation(playerid,"GRAFFITI","spraycan_fire",4.0,0,1,1,0,0);
			return 1;
		}
		if (strcmp(cmd, "/throw", true) ==0 )
		{
			ApplyAnimation(playerid,"GRENADE","WEAPON_throw",3.0,0,1,1,0,0);
			return 1;
		}
		if (strcmp(cmd, "/uthrow", true) ==0 )
		{
			ApplyAnimation(playerid,"GRENADE","WEAPON_throwu",3.0,0,1,1,0,0);
			return 1;
		}
		if (strcmp(cmd, "/bthrow", true) ==0 )
		{
			ApplyAnimation(playerid,"GRENADE","WEAPON_start_throw",3.0,0,1,1,0,0);
			return 1;
		}
		if (strcmp(cmd, "/zaplac", true) ==0 )
		{
			ApplyAnimation(playerid,"INT_SHOP","shop_pay",4.0,0,1,1,0,0);
			return 1;
		}
		if (strcmp(cmd, "/machaj", true) ==0 )
		{
			ApplyAnimation(playerid,"ON_LOOKERS","wave_loop",4.0,1,1,1,1,1);
			return 1;
		}
		if (strcmp(cmd, "/chat", true) ==0 )
		{
			ApplyAnimation(playerid,"PED","IDLE_CHAT",4.0,1,0,0,1,1);
			return 1;
		}
		if (strcmp(cmd, "/idz", true) ==0 )
		{
			ApplyAnimation(playerid,"PED","WALK_CIVI",4.1,1,1,1,1,1);
			return 1;
		}
		if (strcmp(cmd, "/fuckyou", true) ==0 )
		{
			ApplyAnimation(playerid,"PED","fucku",4.0,0,1,1,0,0);
			return 1;
		}
		if (strcmp(cmd, "/joga", true) ==0 )
		{
			ApplyAnimation(playerid,"PARK","Tai_Chi_Loop",4.0,1,1,1,1,1);
			return 1;
		}
		if (strcmp(cmd, "/siadz1", true) ==0 )
		{
			ApplyAnimation(playerid,"BEACH","ParkSit_M_loop",4.0,0,1,1,1,0);
			return 1;
		}
		if (strcmp(cmd, "/siadz2", true) ==0 )
		{
			ApplyAnimation(playerid,"PED","SEAT_down",4.0,0,0,0,1,0);
			return 1;
		}
		if (strcmp(cmd, "/wstan1", true) == 0)
		{
			ApplyAnimation(playerid,"PED","SEAT_up",4.0,0,1,1,0,0);
			return 1;
		}
		if (strcmp(cmd, "/wstan2", true) == 0)
		{
			ApplyAnimation(playerid,"PED","getup",4.0,0,1,1,0,0);
			return 1;
		}
		if (strcmp(cmd, "/wstan3", true) == 0)
		{
			ApplyAnimation(playerid,"PED","getup_front",4.0,0,1,1,0,0);
			return 1;
		}
		if (strcmp(cmd, "/padnij1", true) ==0 )
		{
			ApplyAnimation(playerid,"PED","KO_skid_front",4.0,0,1,1,1,0);
			return 1;
		}
		if (strcmp(cmd, "/padnij3", true) ==0 )
		{
			ApplyAnimation(playerid,"PED","FLOOR_hit_f",4.0,0,1,1,1,0);
			return 1;
		}
		if (strcmp(cmd, "/ranny", true) ==0 )
		{
			ApplyAnimation(playerid,"SWEET","Sweet_injuredloop", 4.0,1,0,0,0,0);
			return 1;
		}
		if (strcmp(cmd, "/strip1", true) ==0 )
		{
			ApplyAnimation(playerid,"STRIP","PLY_CASH",4.1,0,1,1,0,0);
			return 1;
		}
		if (strcmp(cmd, "/strip2", true) ==0 )
		{
			ApplyAnimation(playerid,"STRIP","PUN_CASH",4.1,0,1,1,0,0);
			return 1;
		}
		if (strcmp(cmd, "/strip3", true) ==0 )
		{
			ApplyAnimation(playerid,"STRIP","PUN_HOLLER",4.1,0,1,1,0,0);
			return 1;
		}
		if (strcmp(cmd, "/strip4", true) ==0 )
		{
			ApplyAnimation(playerid,"STRIP","strip_A",4.1,1,1,1,0,0);
			return 1;
		}
		if (strcmp(cmd, "/strip5", true) ==0 )
		{
			ApplyAnimation(playerid,"STRIP","strip_B",4.1,1,1,1,0,0);
			return 1;
		}
		if (strcmp(cmd, "/strip6", true) ==0 )
		{
			ApplyAnimation(playerid,"STRIP","strip_C",4.1,1,1,1,0,0);
			return 1;
		}
		if (strcmp(cmd, "/strip7", true) ==0 )
		{
			ApplyAnimation(playerid,"STRIP","strip_D",4.1,1,1,1,0,0);
			return 1;
		}
		if (strcmp(cmd, "/strip8", true) ==0 )
		{
			ApplyAnimation(playerid,"STRIP","strip_E",4.1,0,1,1,0,0);
			return 1;
		}
		if (strcmp(cmd, "/strip9", true) ==0 )
		{
			ApplyAnimation(playerid,"STRIP","strip_F",4.1,1,1,1,0,0);
			return 1;
		}
		if (strcmp(cmd, "/strip10", true) ==0 )
		{
			ApplyAnimation(playerid,"STRIP","strip_G",4.1,1,1,1,0,0);
			return 1;
		}
		if (strcmp(cmd, "/strip11", true) ==0 )
		{
			ApplyAnimation(playerid,"STRIP","STR_A2B",4.1,1,1,1,0,0);
			return 1;
		}
		if (strcmp(cmd, "/strip12", true) ==0 )
		{
			ApplyAnimation(playerid,"STRIP","STR_B2C",4.1,1,1,1,0,0);
			return 1;
		}
		if (strcmp(cmd, "/strip13", true) ==0 )
		{
			ApplyAnimation(playerid,"STRIP","STR_C1",4.1,1,1,1,0,0);
			return 1;
		}
		if (strcmp(cmd, "/strip14", true) ==0 )
		{
			ApplyAnimation(playerid,"STRIP","STR_C2",4.1,1,1,1,0,0);
			return 1;
		}
		if (strcmp(cmd, "/strip15", true) ==0 )
		{
			ApplyAnimation(playerid,"STRIP","STR_Loop_A",4.1,1,1,1,0,0);
			return 1;
		}
		if (strcmp(cmd, "/strip16", true) ==0 )
		{
			ApplyAnimation(playerid,"STRIP","STR_Loop_B",4.1,1,1,1,0,0);
			return 1;
		}
		if (strcmp(cmd, "/strip17", true) ==0 )
		{
			ApplyAnimation(playerid,"STRIP","STR_Loop_C",4.1,1,1,1,0,0);
			return 1;
		}
	}

	if(gPlayerLogged[playerid] == 1)
	{
		if(strcmp(cmd, "/respawnthiscar", true) == 0 || strcmp(cmd, "/rtc", true) == 0) // by LordMan
		{
			if(gPlayerData[playerid][pAdmin] < 1)
				return 0;
			if(IsPlayerInAnyVehicle(playerid))
			{
				format(string, 256, "%s has just respawned vehicle id %d.",gPlayerData[playerid][pName],idcar);
				ABroadCast(COLOR_YELLOW,string,1);
				gVehData[tmpcar][EngineOn] = 0;
				SaveVehData(tmpcar, "EngineOn");
				SetVehicleToRespawn(idcar);
				RemovePlayerFromVehicle(playerid);
				SendClientMessage(playerid, COLOR_GREY, "   Vehicle Respawned !");
			}
			return 1;
		}
		if(strcmp(cmd, "/getip", true) == 0)
		{
			if(gPlayerData[playerid][pModerator] != 2)
				return 0;
			tmp = strtok(cmdtext,idx);
			new playersip[256];
			if(!strlen(tmp))
			{
				SendClientMessage(playerid,COLOR_GRAD1,"[INFO:] /getip [Players ID]");
				return 1;
			}
			giveplayerid = ReturnUser(tmp);
			GetPlayerName(giveplayerid, giveplayer, sizeof(giveplayer));
			GetPlayerIp( giveplayerid,playersip,sizeof(playersip));
			format(string, sizeof(string), "Player: %s IP: %s",giveplayer,playersip);
			SendClientMessage(playerid,COLOR_GRAD2,string);
			return 1;
		}
		if(strcmp(cmd, "/zaciagnij", true) == 0 || strcmp(cmd, "/zac", true) == 0) // by LordMan
		{
			if(gPlayerData[playerid][pFaction] == 255)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie nale¿ysz do ¿adnej frakcji !");
				return 1;
			}
			if(DynamicFactions[gPlayerData[playerid][pFaction]][fType] != 1)
			{
				SendClientMessage(playerid, COLOR_GRAD1, "[INFO:] Nie jesteœ policjantem !");
				return 1;
			}
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_GRAD2, "U¯YCIE: [/zac]iagnij [playerid/PartOName]");
				return 1;
			}
			new playa;
			playa = ReturnUser(tmp);
			if(tmpcar == INVALID_VEHICLE_ID)
			{
				SendClientMessage(playerid, COLOR_GRAD1, "[B£¥D] Nie jesteœ w radiowozie!");
				return 1;
			}
			if(gVehData[tmpcar][FactionCar] != 255)
			{
				if(DynamicFactions[gVehData[tmpcar][FactionCar]][fType] != 1)
				{
					SendClientMessage(playerid, COLOR_GRAD1, "[B£¥D] Nie jesteœ w radiowozie!");
					return 1;
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_GRAD1, "[B£¥D] Nie jesteœ w radiowozie!");
				return 1;
			}
			if(gVehData[tmpcar][CarModel] != 596 &&
				gVehData[tmpcar][CarModel] != 597 &&
				gVehData[tmpcar][CarModel] != 598 &&
				gVehData[tmpcar][CarModel] != 596 &&
				gVehData[tmpcar][CarModel] != 490 &&
				gVehData[tmpcar][CarModel] != 427 &&
				gVehData[tmpcar][CarModel] != 560 &&
				gVehData[tmpcar][CarModel] != 482)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten pojazd nie jest przystosowany do przewo¿enia podejrzanych");
				return 1;
			}
			if(!IsPlayerConnected(playa))
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ten gracz nie jest on-line !");
				return 1;
			}
			new Float:x, Float:y, Float:z;
			GetPlayerPos(playa,x,y,z);
			if(!PlayerToPoint(5, playerid, x, y, z))
			{
				SendClientMessage(playerid, COLOR_GREY, "[B£¥D:] Ta osoba jest za daleko od ciebie.");
			}
			if(PutPlayerIntoVehicle(playa,idcar,2) == 0)
			{
				if(PutPlayerIntoVehicle(playa,idcar,3) == 0)
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie ma miejsca w tym pojeŸdzie !");
					return 1;
				}
			}
			GetPlayerName(playa, giveplayer, sizeof(giveplayer));
			GetPlayerName(playerid, sendername, sizeof(sendername));
			format(string, sizeof(string), "* %s zaci¹gn¹³ %s do swojego pojazdu.", sendername ,giveplayer);
			ProxDetector(25.0, playerid, string, COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE);
			return 1;
		}
		if(strcmp(cmd, "/nonewbie", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 1)
				return 0;
			if(nonewbie)
			{
				nonewbie = 0;
				BroadCast(COLOR_GRAD2, "[INFO:] Chat dla nowych zostal W£¥CZONY !");
			}
			else if(!nonewbie)
			{
				nonewbie = 1;
				BroadCast(COLOR_GRAD2, "[INFO:] Chat dla nowych zostal WY£¥CZONY !");
			}
			else
			{
				SendClientMessage(playerid, COLOR_GRAD1, "   you are not authorized to use that command!");
			}
			return 1;
		}
		if(strcmp(cmd, "/newbie", true) == 0 || strcmp(cmd, "/n", true) == 0)
		{
			if (gPlayerLogged[playerid] != 0)
			{
				if(gPlayerData[playerid][pMuted] == 1)
				{
					SendClientMessage(playerid, COLOR_GREY, "[INFO:] Jestes uciszony, nie mo¿esz u¿ywaæ tego chatu");
					return 1;
				}
				if ( nonewbie && gPlayerData[playerid][pAdmin] == 0 && gPlayerData[playerid][pModerator] < 1)
				{
					SendClientMessage(playerid, COLOR_GRAD2, "[INFO:] Chat dla newbie zostal WY£ACZONY !");
					return 1;
				}
				if(NewbieTime[playerid] == 1 && gPlayerData[playerid][pModerator] == 0 && gPlayerData[playerid][pAdmin] == 0)
				{
					SendClientMessage(playerid, COLOR_GREY, "[INFO:] Musisz odczekaæ 50 sekund zanim bêdziesz mog³ wys³aæ kolejn¹ wiadomoœæ !");
					return 1;
				}
				GetPlayerName(playerid, sendername, sizeof(sendername));
				new length = strlen(cmdtext);
				while ((idx < length) && (cmdtext[idx] <= ' '))
				{
					idx++;
				}
				new offset = idx;
				new result[64];
				while ((idx < length) && ((idx - offset) < (sizeof(result) - 1)))
				{
					result[idx - offset] = cmdtext[idx];
					idx++;
				}
				result[idx - offset] = EOS;
				if(!strlen(result))
				{
					SendClientMessage(playerid, COLOR_GRAD2, "[INFO:] (/n)ewbie [newbie chat]");
					return 1;
				}
				if (gPlayerData[playerid][pModerator] == 1 && gPlayerData[playerid][pAdmin] >= 0 && gPlayerData[playerid][pAdmin] < 5)
				{
					format(string, sizeof(string), "** Administrator %s: %s **", sendername, result);
				}
				if (gPlayerData[playerid][pModerator] == 1 && gPlayerData[playerid][pAdmin] == 0 )
				{
					format(string, sizeof(string), "** Moderator %s: %s **", sendername, result);
				}
				else if (gPlayerData[playerid][pAdmin] >= 5)
				{
					format(string, sizeof(string), "** Head Admin %s: %s **", sendername, result);
				}
				else if (gPlayerData[playerid][pModerator] >= 2 && gPlayerData[playerid][pAdmin] == 0 )
				{
					format(string, sizeof(string), "** SModerator %s: %s **", sendername, result);
				}
				else
				{
					format(string, sizeof(string), "** Newbie %s: %s **", sendername, result);
					NewbieTime[playerid] = 1;
					NewbieTimer(playerid);
				}
				NewbieOff(COLOR_LIGHTGREEN, string);
				printf("%s", string);
			}
			else
			{
				SendClientMessage(playerid, COLOR_GRAD1, "[INFO:] Nie jesteœ zalogowany.");
				return 1;
			}
			return 1;
		}
		if(strcmp(cmd, "/error", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 1)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_GRAD2, "U¯YCIE: /epp [playerid/PartOName]");
				return 1;
			}
			giveplayerid = ReturnUser(tmp);
			if(IsPlayerConnected(giveplayerid))
			{
				if(giveplayerid != INVALID_PLAYER_ID)
				{
					SendClientMessage(giveplayerid, COLOR_RED, "Zosta³eœ wyrzucony ze wzglêdu na b³¹d EPP. Zaloguj siê ponownie.");
					Kick(giveplayerid);
				}
			}
			else
			{
				format(string, sizeof(string), "   %d is not an active player.", giveplayerid);
				SendClientMessage(playerid, COLOR_GRAD1, string);
			}
			return 1;
		}
		if(strcmp(cmd, "/kostka", true) == 0)
		{
			if(IsPlayerConnected(playerid))
			{
				new dice = random(6)+1;
				if (gDice[playerid] == 1)
				{
					GetPlayerName(playerid, sendername, sizeof(sendername));
					format(string, sizeof(string), "*** %s rzuca kostka, upada i wskazuje %d oczek", sendername,dice);
					ProxDetector(10.0, playerid, string, COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE);
				}
				else
				{
					SendClientMessage(playerid, COLOR_GRAD2, "[INFO:] Nie posiadasz kostki");
					return 1;
				}
			}
			return 1;
		}
		if(strcmp(cmd, "/po", true) == 0)
		{
			if(gPlayerData[playerid][pFaction] == 255)
			{
				SendClientMessage(playerid, COLOR_RED, "[INFO:] Niew³aœciwa frakcja !");
				return 1;
			}
			if(DynamicFactions[gPlayerData[playerid][pFaction]][fType] != 1)
			{
				SendClientMessage(playerid, COLOR_RED, "[INFO:] Niew³aœciwa frakcja !");
				return 1;
			}
			if(!IsPlayerInAnyVehicle(playerid))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie jesteœ w pojeŸdzie.");
				return 1;
			}
			if(!gPlayerData[playerid][pDuty])
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie jesteœ na s³u¿bie !");
				return 1;
			}
			if(gVehData[tmpcar][FactionCar] != gPlayerData[playerid][pFaction])
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie jesteœ w pojeŸdzie frakcyjnym.");
				return 1;
			}
			switch( gPlayerData[playerid][pRank] )
			{
				case 1:
				{
					GetPlayerName(playerid, sendername, sizeof(sendername));
					format(string, sizeof(string), "* %s mowi: ZJEDZ NA POBOCZE !", sendername);
					ProxDetector(60.0, playerid, string,COLOR_LSPD,COLOR_LSPD,COLOR_LSPD,COLOR_LSPD,COLOR_LSPD);
					return 1;
				}
				case 2:
				{
					GetPlayerName(playerid, sendername, sizeof(sendername));
					format(string, sizeof(string), "* %s mowi: ZJEDZ NA POBOCZE !", sendername);
					ProxDetector(60.0, playerid, string,COLOR_LSPD,COLOR_LSPD,COLOR_LSPD,COLOR_LSPD,COLOR_LSPD);
					return 1;
				}
				case 3:
				{
					GetPlayerName(playerid, sendername, sizeof(sendername));
					format(string, sizeof(string), "* %s mowi: ZJEDZ NA POBOCZE !", sendername);
					ProxDetector(60.0, playerid, string,COLOR_LSPD,COLOR_LSPD,COLOR_LSPD,COLOR_LSPD,COLOR_LSPD);
					return 1;
				}
				case 4:
				{
					GetPlayerName(playerid, sendername, sizeof(sendername));
					format(string, sizeof(string), "* %s mowi: ZJEDZ NA POBOCZE !", sendername);
					ProxDetector(60.0, playerid, string,COLOR_LSPD,COLOR_LSPD,COLOR_LSPD,COLOR_LSPD,COLOR_LSPD);
					return 1;
				}
				case 5:
				{
					GetPlayerName(playerid, sendername, sizeof(sendername));
					format(string, sizeof(string), "* %s mowi: ZJEDZ NA POBOCZE !", sendername);
					ProxDetector(60.0, playerid, string,COLOR_LSPD,COLOR_LSPD,COLOR_LSPD,COLOR_LSPD,COLOR_LSPD);
					return 1;
				}
				case 6:
				{
					GetPlayerName(playerid, sendername, sizeof(sendername));
					format(string, sizeof(string), "* %s mowi: ZJEDZ NA POBOCZE !", sendername);
					ProxDetector(60.0, playerid, string,COLOR_LSPD,COLOR_LSPD,COLOR_LSPD,COLOR_LSPD,COLOR_LSPD);
					return 1;
				}
				case 7:
				{
					GetPlayerName(playerid, sendername, sizeof(sendername));
					format(string, sizeof(string), "* %s mowi: ZJEDZ NA POBOCZE !", sendername);
					ProxDetector(60.0, playerid, string,COLOR_LSPD,COLOR_LSPD,COLOR_LSPD,COLOR_LSPD,COLOR_LSPD);
					return 1;
				}
				case 8:
				{
					GetPlayerName(playerid, sendername, sizeof(sendername));
					format(string, sizeof(string), "* %s mowi: ZJEDZ NA POBOCZE !", sendername);
					ProxDetector(60.0, playerid, string,COLOR_LSPD,COLOR_LSPD,COLOR_LSPD,COLOR_LSPD,COLOR_LSPD);
					return 1;
				}
				case 9:
				{
					GetPlayerName(playerid, sendername, sizeof(sendername));
					format(string, sizeof(string), "* %s mowi: ZJEDZ NA POBOCZE !", sendername);
					ProxDetector(60.0, playerid, string,COLOR_LSPD,COLOR_LSPD,COLOR_LSPD,COLOR_LSPD,COLOR_LSPD);
					return 1;
				}
				case 10:
				{
					GetPlayerName(playerid, sendername, sizeof(sendername));
					format(string, sizeof(string), "* %s mowi: ZJEDZ NA POBOCZE !", sendername);
					ProxDetector(60.0, playerid, string,COLOR_LSPD,COLOR_LSPD,COLOR_LSPD,COLOR_LSPD,COLOR_LSPD);
					return 1;
				}
				default:	return 1;
			}
		}
		if(strcmp(cmd, "/setint", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 1)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_GRAD2, "U¯YCIE: /setint [playerid/PartOName] [interiorid]");
				return 1;
			}
			new playa;
			playa = ReturnUser(tmp);
			new intid;
			tmp = strtok(cmdtext, idx);
			intid = strvalEx(tmp);
			if(IsPlayerConnected(playa))
			{
				if(playa != INVALID_PLAYER_ID)
				{
					GetPlayerName(playa, giveplayer, sizeof(giveplayer));
					GetPlayerName(playerid, sendername, sizeof(sendername));
					SetPlayerInterior(playa, intid);
					gPlayerData[playa][pInt] = intid;

					SavePlayerData(playa, "CrashInt");

					format(string, sizeof(string), "   You havae set %s interior to %d.", giveplayer, intid);
					SendClientMessage(playerid, COLOR_GRAD1, string);
					format(string, sizeof(string), "   %s has set your interior to %d.", sendername, intid);
					SendClientMessage(playa, COLOR_GRAD1, string);
				}
			}
			return 1;
		}
		if(strcmp(cmd, "/setvw", true) == 0)
		{
			if(gPlayerData[playerid][pModerator] == 0)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_GRAD2, "U¯YCIE: /setvw [playerid/PartOName] [virworldid]");
				return 1;
			}
			new playa;
			playa = ReturnUser(tmp);
			new virid;
			tmp = strtok(cmdtext, idx);
			virid = strvalEx(tmp);
			if(IsPlayerConnected(playa))
			{
				if(playa != INVALID_PLAYER_ID)
				{
					if(gPlayerData[playa][pAdmin] > 0 && (playa != playerid) )
					{
						SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie mo¿esz u¿yæ tej komendy na administratorze !");
						return 1;
					}
					GetPlayerName(playa, giveplayer, sizeof(giveplayer));
					GetPlayerName(playerid, sendername, sizeof(sendername));
					SetPlayerVirtualWorld(playa, virid);
					format(string, sizeof(string), "   You have set %s virtual world to %d.", giveplayer, virid);
					SendClientMessage(playerid, COLOR_GRAD1, string);
					format(string, sizeof(string), "   %s have set your virtual world to %d.", sendername, virid);
					SendClientMessage(playa, COLOR_GRAD1, string);
					gPlayerData[playa][pCrashW] = virid;
					SavePlayerData( playa, "CrashW" );
				}
			}
			return 1;
		}
		if(strcmp(cmd, "/disarm", true) == 0) // Reset the player's weapons
		{
			if(gPlayerData[playerid][pModerator] == 0)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTBLUE, "U¯YCIE: /disarm [playername/id]");
				SendClientMessage(playerid, COLOR_LIGHTBLUE, "FUNKCJA: rozbroi gracza");
				return 1;
			}
			if(giveplayerid != INVALID_PLAYER_ID)
			{
				GetPlayerName(giveplayerid, giveplayername, sizeof(giveplayername));
				//GetPlayerName(playerid, sendername, sizeof(sendername));
				ResetPlayerWeapons(giveplayerid);
				format(string, sizeof(string), "-| Administrator %s rozbroil gracza %s |-",sendername, giveplayername);
				ABroadCast(COLOR_YELLOW,string,1);
			}
			else if(giveplayerid == INVALID_PLAYER_ID)
			{
				format(string, sizeof(string), "%d nie jest on-line.", giveplayerid);
				SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
			}
			return 1;
		}
		if(strcmp(cmd, "/odbierzbron", true) == 0) // Reset the player's weapons
		{
			if (gPlayerData[playerid][pFaction] == 9)
			{
				tmp = strtok(cmdtext, idx);
				if(!strlen(tmp))
				{
					SendClientMessage(playerid, COLOR_LIGHTBLUE, "U¯YCIE: /odbierzbron [id]");
					SendClientMessage(playerid, COLOR_LIGHTBLUE, "FUNKCJA: rozbroi gracza");
					return 1;
				}
				if(giveplayerid != INVALID_PLAYER_ID)
				{
					ResetPlayerWeapons(giveplayerid);
					format(string, sizeof(string), "-| Urzednik %s rozbroil gracza %s |-",gPlayerData[playerid][pName], gPlayerData[giveplayerid][pName]);
					ABroadCast(COLOR_YELLOW,string,1);
					
					format(string, sizeof(string), "[GOVERNMENT:] Player: %s disarmed player: %s", gPlayerData[playerid][pName], gPlayerData[giveplayerid][pName]);
					GovermentLog(string);
				}
				else if(giveplayerid == INVALID_PLAYER_ID)
				{
					format(string, sizeof(string), "%d nie jest on-line.", giveplayerid);
					SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
				}
			}
			else SendClientMessage(playerid, COLOR_LIGHTBLUE, "nie jesteœ urzednikiem.");
			return 1;
		}
		if(strcmp(cmd, "/coin", true) == 0)
		{
			if(IsPlayerConnected(playerid))
			{
				new coin = random(2)+1;
				GetPlayerName(playerid, sendername, sizeof(sendername));
				new coinname[20];
				if(coin == 1) { coinname = "orla"; }
				else { coinname = "reszke"; }
				format(string, sizeof(string), "*** %s rzucil moneta ktora wskazuje %s", sendername,coinname);
				ProxDetector(10.0, playerid, string, COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE);
			}
			return 1;
		}
		if(!strcmp(cmdtext, "/wlozbron", true)) // By LordMan
		{
			if( PlayerFreeSlotCount( playerid ) < 2 )
			{
				SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Jesteœ przeci¹¿ony !");
				return 1;
			}
			gTGunID = GetPlayerWeapon(playerid);
			if(gTGunID >= 22 && gTGunID <= 42 && gTGunID != 40)
			{
				gTGunAmmo = GetPlayerAmmo(playerid);
				RemovePlayerWeapon(playerid, gTGunID);
				printf("[WEAPON:] Player %s put weapon id %d and %d ammo into /mi", GetPlayerNameEx(playerid), gTGunID, gTGunAmmo);
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
						InsertPlayerItemEx(playerid, 1, 38, 0, 0, 0, 0, "Puste", gTGunAmmo);
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
			else
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz schowaæ tej broni !");
			return 1;
		}
		// if(!strcmp(cmdtext, "/inv", true) || !strcmp(cmdtext, "/schowek", true)) // By LordMan
		// {
			// if(IsPlayerConnected(playerid))
			// {
				// if(gPlayerLogged[playerid] == 0)
				// {
					// SendClientMessage(playerid, COLOR_GREY, "   You need to login first ! ");
					// return 1;
				// }
				// new gunname[100];
				// GetWeaponName(gPlayerData[playerid][pInvWeapon], gunname, sizeof(gunname));
				// SendClientMessage(playerid, COLOR_LIGHTBLUE, "__________ Schowek __________");
				// if(gPlayerData[playerid][pInvWeapon] != 0 && gPlayerData[playerid][pInvAmmo] != 0)
				// {
					// format(string, sizeof(string), "Bron: %s, Amunicja: %d", gunname, gPlayerData[playerid][pInvAmmo]);
					// SendClientMessage(playerid, COLOR_WHITE, string);
				// }
				// else
				// {
					// SendClientMessage(playerid, COLOR_WHITE, "Schowek jest pusty.");
				// }
				// SendClientMessage(playerid, COLOR_LIGHTBLUE, "_______________________________");
				// SendClientMessage(playerid, COLOR_WHITE, "PODPOWIEDZ: /wezbron /wlozbron");
			// }
			// return 1;
		// }
		if(!strcmp(cmdtext, "/pokaznotki", true)) // By LordMan
		{
			if(IsPlayerConnected(playerid))
			{
				if(gPlayerLogged[playerid] == 0)
				{
					SendClientMessage(playerid, COLOR_GREY, "[INFO:] Musisz sie najpierw zalogowac !");
					return 1;
				}
				SendClientMessage(playerid, COLOR_LIGHTBLUE, "_____________ Notes _____________");
				format(string, sizeof(string), "1| %s", gPlayerData[playerid][pNote1]);
				SendClientMessage(playerid, COLOR_WHITE, string);
				format(string, sizeof(string), "2| %s", gPlayerData[playerid][pNote2]);
				SendClientMessage(playerid, COLOR_WHITE, string);
				format(string, sizeof(string), "3| %s", gPlayerData[playerid][pNote3]);
				SendClientMessage(playerid, COLOR_WHITE, string);
				format(string, sizeof(string), "4| %s", gPlayerData[playerid][pNote4]);
				SendClientMessage(playerid, COLOR_WHITE, string);
				format(string, sizeof(string), "5| %s", gPlayerData[playerid][pNote5]);
				SendClientMessage(playerid, COLOR_WHITE, string);
				SendClientMessage(playerid, COLOR_LIGHTBLUE, "___________________________________");
				GetPlayerName(playerid, sendername, sizeof(sendername));
				format(string, sizeof(string), "* %s patrzy w swoj notes.", sendername);
				ProxDetector(30.0, playerid, string, COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE);
			}
			return 1;
		}

		if(strcmp(cmd,"/usunnotke",true)==0) // By LordMan
		{
			if(IsPlayerConnected(playerid))
			{
				if(gPlayerLogged[playerid] == 0)
				{
					SendClientMessage(playerid, COLOR_GREY, "[INFO:] Musisz sie najpierw zalogowac !");
					return 1;
				}
				new x_nr[256];
				x_nr = strtok(cmdtext, idx);
				if(!strlen(x_nr))
				{
					SendClientMessage(playerid, COLOR_WHITE, "U¯YCIE: /usunnotke [slot(1-5)]");
					return 1;
				}
				if(strcmp(x_nr,"1",true) == 0)
				{
					if(gPlayerData[playerid][pNote1s] == 1)
					{
						strmid(gPlayerData[playerid][pNote1], "Brak", 0, strlen("Brak"), 255);
						gPlayerData[playerid][pNote1s] = 0;
						SendClientMessage(playerid, COLOR_WHITE, "[INFO:] Notka ze slotu 1 usunieta.");
					}
					else
					{
						SendClientMessage(playerid, COLOR_GREY, "[INFO:] Nie masz notatki w slocie 1 !");
					}
				}
				else if(strcmp(x_nr,"2",true) == 0)
				{
					if(gPlayerData[playerid][pNote2s] == 1)
					{
						strmid(gPlayerData[playerid][pNote2], "Brak", 0, strlen("Brak"), 255);
						gPlayerData[playerid][pNote2s] = 0;
						SendClientMessage(playerid, COLOR_WHITE, "[INFO:] Notka ze slotu 2 usunieta.");
					}
					else
					{
						SendClientMessage(playerid, COLOR_GREY, "[INFO:] Nie masz notatki w slocie 2 !");
					}
				}
				else if(strcmp(x_nr,"3",true) == 0)
				{
					if(gPlayerData[playerid][pNote3s] == 1)
					{
						strmid(gPlayerData[playerid][pNote3], "Brak", 0, strlen("Brak"), 255);
						gPlayerData[playerid][pNote3s] = 0;
						SendClientMessage(playerid, COLOR_WHITE, "[INFO:] Notka ze slotu 3 usunieta.");
					}
					else
					{
						SendClientMessage(playerid, COLOR_GREY, "[INFO:] Nie masz notatki w slocie 3 !");
					}
				}
				else if(strcmp(x_nr,"4",true) == 0)
				{
					if(gPlayerData[playerid][pNote4s] == 1)
					{
						strmid(gPlayerData[playerid][pNote4], "Brak", 0, strlen("Brak"), 255);
						gPlayerData[playerid][pNote4s] = 0;
						SendClientMessage(playerid, COLOR_WHITE, "[INFO:] Notka ze slotu 4 usunieta.");
					}
					else
					{
						SendClientMessage(playerid, COLOR_GREY, "[INFO:] Nie masz notatki w slocie 4 !");
					}
				}
				else if(strcmp(x_nr,"5",true) == 0)
				{
					if(gPlayerData[playerid][pNote5s] == 1)
					{
						strmid(gPlayerData[playerid][pNote5], "Brak", 0, strlen("Brak"), 255);
						gPlayerData[playerid][pNote5s] = 0;
						SendClientMessage(playerid, COLOR_WHITE, "[INFO:] Notka ze slotu 5 usunieta.");
					}
					else
					{
						SendClientMessage(playerid, COLOR_GREY, "[INFO:] Nie masz notatki w slocie 5 !");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_GREY, "[INFO:] Nieprawidlowe ID slotu");
					return 1;
				}
			}
			return 1;
		}
		if(strcmp(cmd,"/zrobnotke",true)==0) // By LordMan
		{
			new length = strlen(cmdtext);
			while ((idx < length) && (cmdtext[idx] <= ' '))
			{
				idx++;
			}
			new offset = idx;
			new result[64];
			while ((idx < length) && ((idx - offset) < (sizeof(result) - 1)))
			{
				result[idx - offset] = cmdtext[idx];
				idx++;
			}
			result[idx - offset] = EOS;
			if(length > 60)
			{
				SendClientMessage(playerid, COLOR_GREY, "[INFO:] Notka jest za dluga");
				return 1;
			}
			if(!strlen(result))
			{
				SendClientMessage(playerid, COLOR_GRAD2, "U¯YCIE: /zrobnotke [text]");
				return 1;
			}
			if(gPlayerData[playerid][pNote1s] == 0)
			{
				strmid(gPlayerData[playerid][pNote1], result, 0, strlen(result), 255);
				gPlayerData[playerid][pNote1s] = 1;
				SendClientMessage(playerid, COLOR_WHITE, "[INFO:] Notka utworzona !");
				return 1;
			}
			else if(gPlayerData[playerid][pNote2s] == 0)
			{
				strmid(gPlayerData[playerid][pNote2], result, 0, strlen(result), 255);
				gPlayerData[playerid][pNote2s] = 1;
				SendClientMessage(playerid, COLOR_WHITE, "[INFO:] Notka utworzona !");
				return 1;
			}
			else if(gPlayerData[playerid][pNote3s] == 0)
			{
				strmid(gPlayerData[playerid][pNote3], result, 0, strlen(result), 255);
				gPlayerData[playerid][pNote3s] = 1;
				SendClientMessage(playerid, COLOR_WHITE, "[INFO:] Notka utworzona !");
				return 1;
			}
			else if(gPlayerData[playerid][pNote4s] == 0)
			{
				strmid(gPlayerData[playerid][pNote4], result, 0, strlen(result), 255);
				gPlayerData[playerid][pNote4s] = 1;
				SendClientMessage(playerid, COLOR_WHITE, "[INFO:] Notka utworzona !");
				return 1;
			}
			else if(gPlayerData[playerid][pNote5s] == 0)
			{
				strmid(gPlayerData[playerid][pNote5], result, 0, strlen(result), 255);
				gPlayerData[playerid][pNote5s] = 1;
				SendClientMessage(playerid, COLOR_WHITE, "[INFO:] Notka utworzona !");
				return 1;
			}
			else
			{
				SendClientMessage(playerid, COLOR_GREY, "[INFO:] Nie masz wiecej miejsca na notatki !");
				return 1;
			}
		}
		if(strcmp(cmd,"/przekaznotke",true)==0) // By LordMan
		{
			if(IsPlayerConnected(playerid))
			{
				if(gPlayerLogged[playerid] == 0)
				{
					SendClientMessage(playerid, COLOR_GREY, "[INFO:] Musisz sie najpierw zalogowac !");
					return 1;
				}
				tmp = strtok(cmdtext, idx);
				if(!strlen(tmp))
				{
					SendClientMessage(playerid, COLOR_WHITE, "U¯YCIE: /przekaznotke [playerid/PartOName] [id notki]");
					return 1;
				}
				giveplayerid = ReturnUser(tmp);
				if(IsPlayerConnected(giveplayerid))
				{
					if(giveplayerid != INVALID_PLAYER_ID)
					{
						new Float:x, Float:y, Float:z;
						GetPlayerPos(giveplayerid,x,y,z);
						if(!PlayerToPoint(5, playerid, x, y, z))
						{
							SendClientMessage(playerid, COLOR_GREY, "[INFO:] Jesteœ za daleko od tej osoby !");
							return 1;
						}
						new x_nr[256];
						x_nr = strtok(cmdtext, idx);
						if(!strlen(x_nr))
						{
							SendClientMessage(playerid, COLOR_WHITE, "U¯YCIE: /przekaznotke [playerid/PartOName] [id notki]");
							return 1;
						}
						if(strcmp(x_nr,"1",true) == 0)
						{
							if(gPlayerData[playerid][pNote1s] == 1)
							{
								if(gPlayerData[giveplayerid][pNote1s] == 0)
								{
									strmid(gPlayerData[giveplayerid][pNote1], gPlayerData[playerid][pNote1], 0, strlen(gPlayerData[playerid][pNote1]), 255);
									gPlayerData[giveplayerid][pNote1s] = 1;
									GetPlayerName(playerid, sendername, sizeof(sendername));
									GetPlayerName(giveplayerid, giveplayer, sizeof(giveplayer));
									format(string, sizeof(string), "Przekazales notke do [ID:%d] %s.", giveplayerid, giveplayer);
									SendClientMessage(playerid, COLOR_WHITE, string);
									format(string, sizeof(string), "Otrzymales notke od [ID:%d] %s.", playerid, sendername);
									SendClientMessage(giveplayerid, COLOR_WHITE, string);
								}
								else if(gPlayerData[giveplayerid][pNote2s] == 0)
								{
									strmid(gPlayerData[giveplayerid][pNote2], gPlayerData[playerid][pNote1], 0, strlen(gPlayerData[playerid][pNote1]), 255);
									gPlayerData[giveplayerid][pNote2s] = 1;
									GetPlayerName(playerid, sendername, sizeof(sendername));
									GetPlayerName(giveplayerid, giveplayer, sizeof(giveplayer));
									format(string, sizeof(string), "Przekazales notke do [ID:%d] %s.", giveplayerid, giveplayer);
									SendClientMessage(playerid, COLOR_WHITE, string);
									format(string, sizeof(string), "Otrzymales notke od [ID:%d] %s.", playerid, sendername);
									SendClientMessage(giveplayerid, COLOR_WHITE, string);
								}
								else if(gPlayerData[giveplayerid][pNote3s] == 0)
								{
									strmid(gPlayerData[giveplayerid][pNote3], gPlayerData[playerid][pNote1], 0, strlen(gPlayerData[playerid][pNote1]), 255);
									gPlayerData[giveplayerid][pNote3s] = 1;
									GetPlayerName(playerid, sendername, sizeof(sendername));
									GetPlayerName(giveplayerid, giveplayer, sizeof(giveplayer));
									format(string, sizeof(string), "Przekazales notke do [ID:%d] %s.", giveplayerid, giveplayer);
									SendClientMessage(playerid, COLOR_WHITE, string);
									format(string, sizeof(string), "Otrzymales notke od [ID:%d] %s.", playerid, sendername);
									SendClientMessage(giveplayerid, COLOR_WHITE, string);
								}
								else if(gPlayerData[giveplayerid][pNote4s] == 0)
								{
									strmid(gPlayerData[giveplayerid][pNote4], gPlayerData[playerid][pNote1], 0, strlen(gPlayerData[playerid][pNote1]), 255);
									gPlayerData[giveplayerid][pNote4s] = 1;
									GetPlayerName(playerid, sendername, sizeof(sendername));
									GetPlayerName(giveplayerid, giveplayer, sizeof(giveplayer));
									format(string, sizeof(string), "Przekazales notke do [ID:%d] %s.", giveplayerid, giveplayer);
									SendClientMessage(playerid, COLOR_WHITE, string);
									format(string, sizeof(string), "Otrzymales notke od [ID:%d] %s.", playerid, sendername);
									SendClientMessage(giveplayerid, COLOR_WHITE, string);
								}
								else if(gPlayerData[giveplayerid][pNote5s] == 0)
								{
									strmid(gPlayerData[giveplayerid][pNote5], gPlayerData[playerid][pNote1], 0, strlen(gPlayerData[playerid][pNote1]), 255);
									gPlayerData[giveplayerid][pNote5s] = 1;
									GetPlayerName(playerid, sendername, sizeof(sendername));
									GetPlayerName(giveplayerid, giveplayer, sizeof(giveplayer));
									format(string, sizeof(string), "Przekazales notke do [ID:%d] %s.", giveplayerid, giveplayer);
									SendClientMessage(playerid, COLOR_WHITE, string);
									format(string, sizeof(string), "Otrzymales notke od [ID:%d] %s.", playerid, sendername);
									SendClientMessage(giveplayerid, COLOR_WHITE, string);
								}
								else
								{
									SendClientMessage(playerid, COLOR_GREY, "[INFO:] Notes tej osoby jest pe³ny !");
									return 1;
								}
							}
							else
							{
								SendClientMessage(playerid, COLOR_GREY, "[INFO:] Nie masz notatki na slocie 1 !");
								return 1;
							}
						}
						else if(strcmp(x_nr,"2",true) == 0)
						{
							if(gPlayerData[playerid][pNote2s] == 1)
							{
								if(gPlayerData[giveplayerid][pNote1s] == 0)
								{
									strmid(gPlayerData[giveplayerid][pNote1], gPlayerData[playerid][pNote2], 0, strlen(gPlayerData[playerid][pNote2]), 255);
									gPlayerData[giveplayerid][pNote1s] = 1;
									GetPlayerName(playerid, sendername, sizeof(sendername));
									GetPlayerName(giveplayerid, giveplayer, sizeof(giveplayer));
									format(string, sizeof(string), "Przekazales notke do [ID:%d] %s.", giveplayerid, giveplayer);
									SendClientMessage(playerid, COLOR_WHITE, string);
									format(string, sizeof(string), "Otrzymales notke od [ID:%d] %s.", playerid, sendername);
									SendClientMessage(giveplayerid, COLOR_WHITE, string);
								}
								else if(gPlayerData[giveplayerid][pNote2s] == 0)
								{
									strmid(gPlayerData[giveplayerid][pNote2], gPlayerData[playerid][pNote2], 0, strlen(gPlayerData[playerid][pNote2]), 255);
									gPlayerData[giveplayerid][pNote2s] = 1;
									GetPlayerName(playerid, sendername, sizeof(sendername));
									GetPlayerName(giveplayerid, giveplayer, sizeof(giveplayer));
									format(string, sizeof(string), "Przekazales notke do [ID:%d] %s.", giveplayerid, giveplayer);
									SendClientMessage(playerid, COLOR_WHITE, string);
									format(string, sizeof(string), "Otrzymales notke od [ID:%d] %s.", playerid, sendername);
									SendClientMessage(giveplayerid, COLOR_WHITE, string);
								}
								else if(gPlayerData[giveplayerid][pNote3s] == 0)
								{
									strmid(gPlayerData[giveplayerid][pNote3], gPlayerData[playerid][pNote2], 0, strlen(gPlayerData[playerid][pNote2]), 255);
									gPlayerData[giveplayerid][pNote3s] = 1;
									GetPlayerName(playerid, sendername, sizeof(sendername));
									GetPlayerName(giveplayerid, giveplayer, sizeof(giveplayer));
									format(string, sizeof(string), "Przekazales notke do [ID:%d] %s.", giveplayerid, giveplayer);
									SendClientMessage(playerid, COLOR_WHITE, string);
									format(string, sizeof(string), "Otrzymales notke od [ID:%d] %s.", playerid, sendername);
									SendClientMessage(giveplayerid, COLOR_WHITE, string);
								}
								else if(gPlayerData[giveplayerid][pNote4s] == 0)
								{
									strmid(gPlayerData[giveplayerid][pNote4], gPlayerData[playerid][pNote2], 0, strlen(gPlayerData[playerid][pNote2]), 255);
									gPlayerData[giveplayerid][pNote4s] = 1;
									GetPlayerName(playerid, sendername, sizeof(sendername));
									GetPlayerName(giveplayerid, giveplayer, sizeof(giveplayer));
									format(string, sizeof(string), "Przekazales notke do [ID:%d] %s.", giveplayerid, giveplayer);
									SendClientMessage(playerid, COLOR_WHITE, string);
									format(string, sizeof(string), "Otrzymales notke od [ID:%d] %s.", playerid, sendername);
									SendClientMessage(giveplayerid, COLOR_WHITE, string);
								}
								else if(gPlayerData[giveplayerid][pNote5s] == 0)
								{
									strmid(gPlayerData[giveplayerid][pNote5], gPlayerData[playerid][pNote2], 0, strlen(gPlayerData[playerid][pNote2]), 255);
									gPlayerData[giveplayerid][pNote5s] = 1;
									GetPlayerName(playerid, sendername, sizeof(sendername));
									GetPlayerName(giveplayerid, giveplayer, sizeof(giveplayer));
									format(string, sizeof(string), "Przekazales notke do [ID:%d] %s.", giveplayerid, giveplayer);
									SendClientMessage(playerid, COLOR_WHITE, string);
									format(string, sizeof(string), "Otrzymales notke od [ID:%d] %s.", playerid, sendername);
									SendClientMessage(giveplayerid, COLOR_WHITE, string);
								}
								else
								{
									SendClientMessage(playerid, COLOR_GREY, "[INFO:] Notes tej osoby jest pe³ny !");
									return 1;
								}
							}
							else
							{
								SendClientMessage(playerid, COLOR_GREY, "[INFO:] Nie masz notatki na slocie 2 !");
								return 1;
							}
						}
						else if(strcmp(x_nr,"3",true) == 0)
						{
							if(gPlayerData[playerid][pNote3s] == 1)
							{
								if(gPlayerData[giveplayerid][pNote1s] == 0)
								{
									strmid(gPlayerData[giveplayerid][pNote1], gPlayerData[playerid][pNote3], 0, strlen(gPlayerData[playerid][pNote3]), 255);
									gPlayerData[giveplayerid][pNote1s] = 1;
									GetPlayerName(playerid, sendername, sizeof(sendername));
									GetPlayerName(giveplayerid, giveplayer, sizeof(giveplayer));
									format(string, sizeof(string), "Przekazales notke do [ID:%d] %s.", giveplayerid, giveplayer);
									SendClientMessage(playerid, COLOR_WHITE, string);
									format(string, sizeof(string), "Otrzymales notke od [ID:%d] %s.", playerid, sendername);
									SendClientMessage(giveplayerid, COLOR_WHITE, string);
								}
								else if(gPlayerData[giveplayerid][pNote2s] == 0)
								{
									strmid(gPlayerData[giveplayerid][pNote2], gPlayerData[playerid][pNote3], 0, strlen(gPlayerData[playerid][pNote3]), 255);
									gPlayerData[giveplayerid][pNote2s] = 1;
									GetPlayerName(playerid, sendername, sizeof(sendername));
									GetPlayerName(giveplayerid, giveplayer, sizeof(giveplayer));
									format(string, sizeof(string), "Przekazales notke do [ID:%d] %s.", giveplayerid, giveplayer);
									SendClientMessage(playerid, COLOR_WHITE, string);
									format(string, sizeof(string), "Otrzymales notke od [ID:%d] %s.", playerid, sendername);
									SendClientMessage(giveplayerid, COLOR_WHITE, string);
								}
								else if(gPlayerData[giveplayerid][pNote3s] == 0)
								{
									strmid(gPlayerData[giveplayerid][pNote3], gPlayerData[playerid][pNote3], 0, strlen(gPlayerData[playerid][pNote3]), 255);
									gPlayerData[giveplayerid][pNote3s] = 1;
									GetPlayerName(playerid, sendername, sizeof(sendername));
									GetPlayerName(giveplayerid, giveplayer, sizeof(giveplayer));
									format(string, sizeof(string), "Przekazales notke do [ID:%d] %s.", giveplayerid, giveplayer);
									SendClientMessage(playerid, COLOR_WHITE, string);
									format(string, sizeof(string), "Otrzymales notke od [ID:%d] %s.", playerid, sendername);
									SendClientMessage(giveplayerid, COLOR_WHITE, string);
								}
								else if(gPlayerData[giveplayerid][pNote4s] == 0)
								{
									strmid(gPlayerData[giveplayerid][pNote4], gPlayerData[playerid][pNote4], 0, strlen(gPlayerData[playerid][pNote4]), 255);
									gPlayerData[giveplayerid][pNote4s] = 1;
									GetPlayerName(playerid, sendername, sizeof(sendername));
									GetPlayerName(giveplayerid, giveplayer, sizeof(giveplayer));
									format(string, sizeof(string), "Przekazales notke do [ID:%d] %s.", giveplayerid, giveplayer);
									SendClientMessage(playerid, COLOR_WHITE, string);
									format(string, sizeof(string), "Otrzymales notke od [ID:%d] %s.", playerid, sendername);
									SendClientMessage(giveplayerid, COLOR_WHITE, string);
								}
								else if(gPlayerData[giveplayerid][pNote5s] == 0)
								{
									strmid(gPlayerData[giveplayerid][pNote5], gPlayerData[playerid][pNote5], 0, strlen(gPlayerData[playerid][pNote5]), 255);
									gPlayerData[giveplayerid][pNote5s] = 1;
									GetPlayerName(playerid, sendername, sizeof(sendername));
									GetPlayerName(giveplayerid, giveplayer, sizeof(giveplayer));
									format(string, sizeof(string), "Przekazales notke do [ID:%d] %s.", giveplayerid, giveplayer);
									SendClientMessage(playerid, COLOR_WHITE, string);
									format(string, sizeof(string), "Otrzymales notke od [ID:%d] %s.", playerid, sendername);
									SendClientMessage(giveplayerid, COLOR_WHITE, string);
								}
								else
								{
									SendClientMessage(playerid, COLOR_GREY, "[INFO:] Notes tej osoby jest pe³ny !");
									return 1;
								}
							}
							else
							{
								SendClientMessage(playerid, COLOR_GREY, "[INFO:] Nie masz notatki na slocie 3 !");
								return 1;
							}
						}
						else if(strcmp(x_nr,"4",true) == 0)
						{
							if(gPlayerData[playerid][pNote4s] == 1)
							{
								if(gPlayerData[giveplayerid][pNote1s] == 0)
								{
									strmid(gPlayerData[giveplayerid][pNote1], gPlayerData[playerid][pNote4], 0, strlen(gPlayerData[playerid][pNote4]), 255);
									gPlayerData[giveplayerid][pNote1s] = 1;
									GetPlayerName(playerid, sendername, sizeof(sendername));
									GetPlayerName(giveplayerid, giveplayer, sizeof(giveplayer));
									format(string, sizeof(string), "Przekazales notke do [ID:%d] %s.", giveplayerid, giveplayer);
									SendClientMessage(playerid, COLOR_WHITE, string);
									format(string, sizeof(string), "Otrzymales notke od [ID:%d] %s.", playerid, sendername);
									SendClientMessage(giveplayerid, COLOR_WHITE, string);
								}
								else if(gPlayerData[giveplayerid][pNote2s] == 0)
								{
									strmid(gPlayerData[giveplayerid][pNote2], gPlayerData[playerid][pNote4], 0, strlen(gPlayerData[playerid][pNote4]), 255);
									gPlayerData[giveplayerid][pNote2s] = 1;
									GetPlayerName(playerid, sendername, sizeof(sendername));
									GetPlayerName(giveplayerid, giveplayer, sizeof(giveplayer));
									format(string, sizeof(string), "Przekazales notke do [ID:%d] %s.", giveplayerid, giveplayer);
									SendClientMessage(playerid, COLOR_WHITE, string);
									format(string, sizeof(string), "Otrzymales notke od [ID:%d] %s.", playerid, sendername);
									SendClientMessage(giveplayerid, COLOR_WHITE, string);
								}
								else if(gPlayerData[giveplayerid][pNote3s] == 0)
								{
									strmid(gPlayerData[giveplayerid][pNote3], gPlayerData[playerid][pNote4], 0, strlen(gPlayerData[playerid][pNote4]), 255);
									gPlayerData[giveplayerid][pNote3s] = 1;
									GetPlayerName(playerid, sendername, sizeof(sendername));
									GetPlayerName(giveplayerid, giveplayer, sizeof(giveplayer));
									format(string, sizeof(string), "Przekazales notke do [ID:%d] %s.", giveplayerid, giveplayer);
									SendClientMessage(playerid, COLOR_WHITE, string);
									format(string, sizeof(string), "Otrzymales notke od [ID:%d] %s.", playerid, sendername);
									SendClientMessage(giveplayerid, COLOR_WHITE, string);
								}
								else if(gPlayerData[giveplayerid][pNote4s] == 0)
								{
									strmid(gPlayerData[giveplayerid][pNote4], gPlayerData[playerid][pNote4], 0, strlen(gPlayerData[playerid][pNote4]), 255);
									gPlayerData[giveplayerid][pNote4s] = 1;
									GetPlayerName(playerid, sendername, sizeof(sendername));
									GetPlayerName(giveplayerid, giveplayer, sizeof(giveplayer));
									format(string, sizeof(string), "Przekazales notke do [ID:%d] %s.", giveplayerid, giveplayer);
									SendClientMessage(playerid, COLOR_WHITE, string);
									format(string, sizeof(string), "Otrzymales notke od [ID:%d] %s.", playerid, sendername);
									SendClientMessage(giveplayerid, COLOR_WHITE, string);
								}
								else if(gPlayerData[giveplayerid][pNote5s] == 0)
								{
									strmid(gPlayerData[giveplayerid][pNote5], gPlayerData[playerid][pNote4], 0, strlen(gPlayerData[playerid][pNote4]), 255);
									gPlayerData[giveplayerid][pNote5s] = 1;
									GetPlayerName(playerid, sendername, sizeof(sendername));
									GetPlayerName(giveplayerid, giveplayer, sizeof(giveplayer));
									format(string, sizeof(string), "Przekazales notke do [ID:%d] %s.", giveplayerid, giveplayer);
									SendClientMessage(playerid, COLOR_WHITE, string);
									format(string, sizeof(string), "Otrzymales notke od [ID:%d] %s.", playerid, sendername);
									SendClientMessage(giveplayerid, COLOR_WHITE, string);
								}
								else
								{
									SendClientMessage(playerid, COLOR_GREY, "[INFO:] Notes tej osoby jest pe³ny !");
									return 1;
								}
							}
							else
							{
								SendClientMessage(playerid, COLOR_GREY, "[INFO:] Nie masz notatki na slocie 4 !");
								return 1;
							}
						}
						else if(strcmp(x_nr,"5",true) == 0)
						{
							if(gPlayerData[playerid][pNote5s] == 1)
							{
								if(gPlayerData[giveplayerid][pNote1s] == 0)
								{
									strmid(gPlayerData[giveplayerid][pNote1], gPlayerData[playerid][pNote5], 0, strlen(gPlayerData[playerid][pNote5]), 255);
									gPlayerData[giveplayerid][pNote1s] = 1;
									GetPlayerName(playerid, sendername, sizeof(sendername));
									GetPlayerName(giveplayerid, giveplayer, sizeof(giveplayer));
									format(string, sizeof(string), "Przekazales notke do [ID:%d] %s.", giveplayerid, giveplayer);
									SendClientMessage(playerid, COLOR_WHITE, string);
									format(string, sizeof(string), "Otrzymales notke od [ID:%d] %s.", playerid, sendername);
									SendClientMessage(giveplayerid, COLOR_WHITE, string);
								}
								else if(gPlayerData[giveplayerid][pNote2s] == 0)
								{
									strmid(gPlayerData[giveplayerid][pNote2], gPlayerData[playerid][pNote5], 0, strlen(gPlayerData[playerid][pNote5]), 255);
									gPlayerData[giveplayerid][pNote2s] = 1;
									GetPlayerName(playerid, sendername, sizeof(sendername));
									GetPlayerName(giveplayerid, giveplayer, sizeof(giveplayer));
									format(string, sizeof(string), "Przekazales notke do [ID:%d] %s.", giveplayerid, giveplayer);
									SendClientMessage(playerid, COLOR_WHITE, string);
									format(string, sizeof(string), "Otrzymales notke od [ID:%d] %s.", playerid, sendername);
									SendClientMessage(giveplayerid, COLOR_WHITE, string);
								}
								else if(gPlayerData[giveplayerid][pNote3s] == 0)
								{
									strmid(gPlayerData[giveplayerid][pNote3], gPlayerData[playerid][pNote5], 0, strlen(gPlayerData[playerid][pNote5]), 255);
									gPlayerData[giveplayerid][pNote3s] = 1;
									GetPlayerName(playerid, sendername, sizeof(sendername));
									GetPlayerName(giveplayerid, giveplayer, sizeof(giveplayer));
									format(string, sizeof(string), "Przekazales notke do [ID:%d] %s.", giveplayerid, giveplayer);
									SendClientMessage(playerid, COLOR_WHITE, string);
									format(string, sizeof(string), "Otrzymales notke od [ID:%d] %s.", playerid, sendername);
									SendClientMessage(giveplayerid, COLOR_WHITE, string);
								}
								else if(gPlayerData[giveplayerid][pNote4s] == 0)
								{
									strmid(gPlayerData[giveplayerid][pNote4], gPlayerData[playerid][pNote5], 0, strlen(gPlayerData[playerid][pNote5]), 255);
									gPlayerData[giveplayerid][pNote4s] = 1;
									GetPlayerName(playerid, sendername, sizeof(sendername));
									GetPlayerName(giveplayerid, giveplayer, sizeof(giveplayer));
									format(string, sizeof(string), "Przekazales notke do [ID:%d] %s.", giveplayerid, giveplayer);
									SendClientMessage(playerid, COLOR_WHITE, string);
									format(string, sizeof(string), "Otrzymales notke od [ID:%d] %s.", playerid, sendername);
									SendClientMessage(giveplayerid, COLOR_WHITE, string);
								}
								else if(gPlayerData[giveplayerid][pNote5s] == 0)
								{
									strmid(gPlayerData[giveplayerid][pNote5], gPlayerData[playerid][pNote5], 0, strlen(gPlayerData[playerid][pNote5]), 255);
									gPlayerData[giveplayerid][pNote5s] = 1;
									GetPlayerName(playerid, sendername, sizeof(sendername));
									GetPlayerName(giveplayerid, giveplayer, sizeof(giveplayer));
									format(string, sizeof(string), "Przekazales notke do [ID:%d] %s.", giveplayerid, giveplayer);
									SendClientMessage(playerid, COLOR_WHITE, string);
									format(string, sizeof(string), "Otrzymales notke od [ID:%d] %s.", playerid, sendername);
									SendClientMessage(giveplayerid, COLOR_WHITE, string);
								}
								else
								{
									SendClientMessage(playerid, COLOR_GREY, "[INFO:] Notes gracza jest pelny !");
									return 1;
								}
							}
							else
							{
								SendClientMessage(playerid, COLOR_GREY, "[INFO:] Nie masz notatki na slocie 5 !");
								return 1;
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_GREY, "[INFO:] Bledne ID notki.");
							return 1;
						}
					}
				}
			}
			return 1;
		}
		if(strcmp(cmd, "/akceptujochroniarza", true) == 0)
		{
			if(GuardOffer[playerid] < 999)
			{
				if(GetPlayerMoney(playerid) > GuardPrice[playerid])
				{
					if(IsPlayerConnected(GuardOffer[playerid]))
					{
						GetPlayerName(GuardOffer[playerid], giveplayer, sizeof(giveplayer));
						GetPlayerName(playerid, sendername, sizeof(sendername));
						format(string, sizeof(string), "* Zaakceptowales protekcje za $%d od %s.",GuardPrice[playerid],giveplayer);
						SendClientMessage(playerid, COLOR_WHITE, string);
						format(string, sizeof(string), "* %s zaakceptowal twoja protekcje i przelal $%d na twoj rachunek.",sendername,GuardPrice[playerid]);
						SendClientMessage(GuardOffer[playerid], COLOR_WHITE, string);
						gPlayerData[GuardOffer[playerid]][pPayCheck] += GuardPrice[playerid] * 5;

						SavePlayerData(GuardOffer[playerid], "PayCheck");

						SafeGivePlayerMoney(playerid, -GuardPrice[playerid]);
						GuardOffer[playerid] = 999;
						GuardPrice[playerid] = 0;
						return 1;
					}
					return 1;
				}
				else
				{
					SendClientMessage(playerid, COLOR_GREY, "[INFO:] Nie mozesz zaoferowac protekcji !");
					return 1;
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_GREY, "[INFO:] Nikt nie zaoferowal Tobie protekcji !");
				return 1;
			}
		}
		if(strcmp(cmd, "/ochroniarz", true) == 0)
		{
			if(IsPlayerConnected(playerid))
			{
				if(gPlayerData[playerid][pJob] != 9)
				{
					SendClientMessage(playerid, COLOR_GREY, "[INFO:] Nie jest ochorniarzem");
					return 1;
				}
				tmp = strtok(cmdtext, idx);
				if(!strlen(tmp))
				{
					SendClientMessage(playerid, COLOR_GRAD2, "U¯YCIE: /guard [playerid/PartOName] [cena]");
					return 1;
				}
				new money;
				giveplayerid = ReturnUser(tmp);
				tmp = strtok(cmdtext, idx);
				if(!strlen(tmp)) { return 1; }
				money = strval(tmp);
				if(money < 1 || money > 99999) { SendClientMessage(playerid, COLOR_GREY, "[INFO:] Nie moze byc nizsza niz 1, i wyzsza niz 99999!"); return 1; }
				if(IsPlayerConnected(giveplayerid))
				{
					if(giveplayerid != INVALID_PLAYER_ID)
					{
						if(ProxDetectorS(8.0, playerid, giveplayerid))
						{
							if(giveplayerid == playerid)
							{
								SendClientMessage(playerid, COLOR_GREY, "[INFO:] Nie mozesz sam sobie zaoferowac protekcji !");
								return 1;
							}
							GetPlayerName(giveplayerid, giveplayer, sizeof(giveplayer));
							GetPlayerName(playerid, sendername, sizeof(sendername));
							format(string, sizeof(string), "* Zaoferowales protekcje %s za $%d.", giveplayer, money);
							SendClientMessage(playerid, COLOR_WHITE, string);
							format(string, sizeof(string), "* Ochroniarz %s chce Cie chronic za $%d, (wpisz /akceptujochroniarza) by go przyjac.", sendername, money);
							SendClientMessage(giveplayerid, COLOR_WHITE, string);
							GuardOffer[giveplayerid] = playerid;
							GuardPrice[giveplayerid] = money;
						}
						else
						{
							SendClientMessage(playerid, COLOR_GREY, "[INFO:] Gracz jest zbyt daleko od Ciebie !");
						}
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_GREY, "[INFO:] Ten gracz jest off-line");
				}
			}
			return 1;
		}
		if(strcmp(cmd, "/checkweapons", true) == 0) // Edited by LordMan, orginally from CW-RP
		{
			if (gPlayerData[playerid][pModerator] == 0)
				return 0;
			tmp = strtok(cmdtext,idx);
			if (!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_GREY, "U¯YCIE: /checkweapons [playerid/partOName]");
				return 1;
			}
			giveplayerid = ReturnUser(tmp);
			if (giveplayerid == INVALID_PLAYER_ID)
			{
				SendClientMessage(playerid, COLOR_GREY, "[INFO:] Ten gracz jest off-line");
				return 1;
			}
			new sweapon, sammo;
			GetPlayerName(giveplayerid, giveplayer, sizeof(giveplayer));
			format(string, sizeof(string), "%s posiada nastepujace bronie:", giveplayer);
			SendClientMessage(playerid, COLOR_GRAD1, string);
			for (new i=0; i<9; i++)
			{
				GetPlayerWeaponData(giveplayerid, i, sweapon, sammo);
				if(sweapon != 0)
				{
					format(string, sizeof(string), "%d: %d (%d)", i, sweapon, sammo);
					SendClientMessage(playerid, COLOR_GRAD1, string);
				}
			}
			return 1;
		}
		if(strcmp(cmd, "/sprawdzbron", true) == 0) // Edited by LordMan, orginally from CW-RP
		{
			if (gPlayerData[playerid][pFaction] != 9)
			{
				SendClientMessage(playerid, COLOR_GREY, "[INFO:] nie jesteœ upowazniony do uzywania tej komendy !");
				return 1;
			}
			tmp = strtok(cmdtext,idx);
			if (!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_GREY, "U¯YCIE: /sprawdzbron [playerid/partOName]");
				return 1;
			}
			giveplayerid = ReturnUser(tmp);
			if (giveplayerid == INVALID_PLAYER_ID)
			{
				SendClientMessage(playerid, COLOR_GREY, "[INFO:] Ten gracz jest off-line");
				return 1;
			}
			new sweapon, sammo;
			format(string, sizeof(string), "%s posiada nastepujace bronie:", gPlayerData[giveplayerid][pName]);
			SendClientMessage(playerid, COLOR_GRAD1, string);
			for (new i=0; i<9; i++)
			{
				GetPlayerWeaponData(giveplayerid, i, sweapon, sammo);
				if(sweapon != 0)
				{
					format(string, sizeof(string), "%d: %d (%d)", i, sweapon, sammo);
					SendClientMessage(playerid, COLOR_GRAD1, string);
				}
			}
			format(string, sizeof(string), "[GOVERNMENT:] Weapon checked by: %s for %s", gPlayerData[playerid][pName], gPlayerData[giveplayerid][pName]);
			GovermentLog(string);
			return 1;
		}
		if(strcmp(cmd, "/prison",true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 1)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_GRAD2, "U¯YCIE: /prison [playerid/PartOName]");
				return 1;
			}
			giveplayerid = ReturnUser(tmp);
			if(IsPlayerConnected(giveplayerid))
			{
				if(giveplayerid != INVALID_PLAYER_ID)
				{
					GetPlayerName(giveplayerid, giveplayer, sizeof(giveplayer));
					GetPlayerName(playerid, sendername, sizeof(sendername));
					format(string, sizeof(string), "* Umiesciles %s w Forcie DeMorgana.", giveplayer);
					SendClientMessage(playerid, COLOR_LIGHTRED, string);
					format(string, sizeof(string), "* Zostales umieszczony Forcie DeMorgana przez Admina %s.", sendername);
					SendClientMessage(giveplayerid, COLOR_LIGHTRED, string);
					GameTextForPlayer(giveplayerid, "~w~Witaj w ~n~~r~Forcie DeMorgana", 5000, 3);
					WantedPoints[giveplayerid] = 0;
					WantedLevel[giveplayerid] = 0;
					gPlayerData[giveplayerid][pJailed] = 2;
					gPlayerData[giveplayerid][pJailTime] = 3600;

					SavePlayerData(giveplayerid, "Jailed");
					SavePlayerData(giveplayerid, "JailTime");

					SetPlayerToPos(giveplayerid, 107.2300,1920.6311,18.5208);
					SetPlayerWorldBounds(giveplayerid, 337.5694,101.5826,1940.9759,1798.7453); //285.3481,96.9720,1940.9755,1799.0811
					SetPlayerInterior(giveplayerid,0);
					gPlayerData[giveplayerid][pInt] = 0;

					SavePlayerData(giveplayerid, "Int");

					format(string, 256, "[SYSTEM]: %s zostal uwieziony przez Admina %s.", giveplayer, sendername);
					ABroadCast(COLOR_YELLOW,string,1);
					format(string, sizeof(string), "[SYSTEM]: %s zostal uwieziony przez %s", giveplayer, sendername);
					printf("%s",string);
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_GREY, "[INFO:] Gracz nie jest on-line !");
				return 1;
			}
		}
		if(strcmp(cmd, "/unprison",true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 1)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_GRAD2, "U¯YCIE: /unprison [playerid/PartOName]");
				return 1;
			}
			giveplayerid = ReturnUser(tmp);
			if(IsPlayerConnected(giveplayerid))
			{
				if(giveplayerid != INVALID_PLAYER_ID)
				{
					GetPlayerName(giveplayerid, giveplayer, sizeof(giveplayer));
					GetPlayerName(playerid, sendername, sizeof(sendername));
					format(string, sizeof(string), "* Zostales puszczony %s.", giveplayer);
					SendClientMessage(playerid, COLOR_LIGHTRED, string);
					format(string, sizeof(string), "* Zostales puszczony przez Admina %s.", sendername);
					SendClientMessage(giveplayerid, COLOR_LIGHTRED, string);
					gPlayerData[giveplayerid][pJailTime] = 0;
					gPlayerData[giveplayerid][pJailed] = 0;

					SavePlayerData(giveplayerid, "Jailed");
					SavePlayerData(giveplayerid, "JailTime");

					SetPlayerWorldBounds(giveplayerid, 20000.0000,-20000.0000,20000.0000,-20000.0000);
					SetPlayerToPos(giveplayerid, 93.4852,1920.6235,18.0450);
					format(string, 256, "[SYSTEM:] %s zostal wypuszczony przez Admina %s.", giveplayer, sendername);
					ABroadCast(COLOR_YELLOW,string,1);
					format(string, 256, "[SYSTEM:] %s zostal wypuszczony przez Admina %s.", giveplayer, sendername);
					ABroadCast(COLOR_YELLOW,string,1);
				}
			}
			return 1;
		}
		if(strcmp(cmd, "/donos", true) == 0 || strcmp(cmd, "/re", true) == 0)
		{
			if( gReportCooldown > 0 )
			{
				SendClientMessage( playerid, COLOR_RED, "[INFO:] Ktoœ ju¿ wys³a³ donos. Musisz chwile poczekaæ przed wys³aniem kolejnego !");
				return 1;
			}
			gReportCooldown = 10;
			GetPlayerName(playerid, sendername, sizeof(sendername));
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_GRAD2, "U¯YCIE: (/re)port [playerid/PartOName] [text]");
				return 1;
			}
			giveplayerid = strval(tmp);
			if(IsPlayerConnected(giveplayerid))
			{
				if(giveplayerid != INVALID_PLAYER_ID)
				{
					new length = strlen(cmdtext);
					while ((idx < length) && (cmdtext[idx] <= ' '))
					{
						idx++;
					}
					new offset = idx;
					new result[64];
					while ((idx < length) && ((idx - offset) < (sizeof(result) - 1)))
					{
						result[idx - offset] = cmdtext[idx];
						idx++;
					}
					result[idx - offset] = EOS;
					if(!strlen(result))
					{
						SendClientMessage(playerid, COLOR_GRAD2, "U¯YCIE: (/re)port [playerid/PartOName] [text]");
						return 1;
					}
					GetPlayerName(giveplayerid, giveplayer, sizeof(giveplayer));
					format(string, sizeof(string), "Donos od: [ID:%d]%s, doniosl na gracza: [ID:%d]%s", playerid, sendername, giveplayerid, giveplayer);
					ABroadCast(0xE19898AA,string,1);
					SendModMessage(0xE19898AA, string);
					format(string, sizeof(string), "Tresc donosu: %s", (result));
					SendModMessage(0xE19898AA, string);
					ABroadCast(0xE19898AA,string,1);
					ABroadCast(0xA04C4CAA,"Wpisz '/akceptujraport [reporter id]' lub '/wyrzucraporty [reporter id]'",1);
					SendModMessage(0xE19898AA, "Wpisz '/akceptujraport [reporter id]' lub '/wyrzucraporty [reporter id]'");
					SendClientMessage(playerid, 0x96C184AA, "[INFO:] Admini przejrza report, dziekujemy za zgloszenie.");
					PlayerNeedsHelp[playerid] = 1;
					SetTimerEx("ReportReset", 120000, false, "i", playerid);
				}
			}
			return 1;
		}
		if(strcmp(cmd, "/akceptujraport", true) == 0) // By LordMan
		{
			if(gPlayerData[playerid][pAdmin] == 0 && gPlayerData[playerid][pModerator] == 0)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_WHITE, "HINT: /akceptujraport [playerid/PartOName]");
				return 1;
			}
			giveplayerid = ReturnUser(tmp);
			if(IsPlayerConnected(giveplayerid))
			{
				if(giveplayerid != INVALID_PLAYER_ID)
				{
					if(PlayerNeedsHelp[giveplayerid] == 1)
					{
						PlayerNeedsHelp[giveplayerid] = 0;
						GetPlayerName(playerid, sendername, sizeof(sendername));
						GetPlayerName(giveplayerid, giveplayer, sizeof(giveplayer));
						format(string, sizeof(string), "[INFO:] %s wlasnie zaakceptowal raport [ID:%d]%s.", sendername, giveplayerid, giveplayer);
						ABroadCast(COLOR_YELLOW, string, 1);
						format(string, sizeof(string), "** Administrator [ID:%d]%s zaakceptowal Twoj raport ! Please be patience.", playerid, sendername);
						SendClientMessage(giveplayerid, 0x4D903DAA, string);
					}
					else
					{
						SendClientMessage(playerid, COLOR_GREY, "[INFO:] Uzytkownik nie wyslal raportu lub raport zaakceptowany !");
						return 1;
					}
				}
			}
			return 1;
		}
		if(strcmp(cmd, "/usunraport", true) == 0) // By LordMan
		{
			if(gPlayerData[playerid][pAdmin] == 0 && gPlayerData[playerid][pModerator] == 0)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_WHITE, "[PODPOWIEDZ:] /usunraport [playerid/PartOName]");
				return 1;
			}
			giveplayerid = ReturnUser(tmp);
			if(IsPlayerConnected(giveplayerid))
			{
				if(giveplayerid != INVALID_PLAYER_ID)
				{
					if(PlayerNeedsHelp[giveplayerid] == 1)
					{
						PlayerNeedsHelp[giveplayerid] = 0;
						GetPlayerName(playerid, sendername, sizeof(sendername));
						GetPlayerName(giveplayerid, giveplayer, sizeof(giveplayer));
						format(string, sizeof(string), "[INFO:] %s wyrzucil wlasnie raport [ID:%d]%s.", sendername, giveplayerid, giveplayer);
						ABroadCast(COLOR_YELLOW, string, 1);
						format(string, sizeof(string), "** Administrator [ID:%d]%s odrzucil Twoj raport !", playerid, sendername);
						SendClientMessage(giveplayerid, 0xB35959AA, string);
					}
					else
					{
						SendClientMessage(playerid, COLOR_GREY, "[INFO:] Uzytkownik nie wyslal raportu lub raport zaakceptowany !");
						return 1;
					}
				}
			}
			return 1;
		}
		/*if(strcmp(cmd, "/zadajpytanie", true) == 0)
		{
			GetPlayerName(playerid, sendername, sizeof(sendername));
			new length = strlen(cmdtext);
			while ((idx < length) && (cmdtext[idx] <= ' '))
			{
				idx++;
			}
			new offset = idx;
			new result[64];
			while ((idx < length) && ((idx - offset) < (sizeof(result) - 1)))
			{
				result[idx - offset] = cmdtext[idx];
				idx++;
			}
			result[idx - offset] = EOS;
			if(!strlen(result))
			{
				SendClientMessage(playerid, COLOR_GRAD2, "[INFO:] /zadajpytanie [text]");
				return 1;
			}
			format(string, sizeof(string), "Pytanie od %s: %s", sendername, (result));
			ABroadCast(COLOR_ASKQ,string,1);
			SendClientMessage(playerid, COLOR_ASKQ, "Pytanie zostalo przekazanie adminom.");
			return 1;
		}*/
		if (strcmp(cmd, "/fly", true) == 0)
		{
			if (gPlayerData[playerid][pAdmin] < 1)
				return 0;
			new Float:px, Float:py, Float:pz, Float:pa;
			GetPlayerFacingAngle(playerid,pa);
			if(pa >= 0.0 && pa <= 22.5) //n1
			{
				GetPlayerPos(playerid, px, py, pz);
				SetPlayerToPos(playerid, px, py+30, pz+5);
			}
			if(pa >= 332.5 && pa < 0.0) //n2
			{
				GetPlayerPos(playerid, px, py, pz);
				SetPlayerToPos(playerid, px, py+30, pz+5);
			}
			if(pa >= 22.5 && pa <= 67.5) //nw
			{
				GetPlayerPos(playerid, px, py, pz);
				SetPlayerToPos(playerid, px-15, py+15, pz+5);
			}
			if(pa >= 67.5 && pa <= 112.5) //w
			{
				GetPlayerPos(playerid, px, py, pz);
				SetPlayerToPos(playerid, px-30, py, pz+5);
			}
			if(pa >= 112.5 && pa <= 157.5) //sw
			{
				GetPlayerPos(playerid, px, py, pz);
				SetPlayerToPos(playerid, px-15, py-15, pz+5);
			}
			if(pa >= 157.5 && pa <= 202.5) //s
			{
				GetPlayerPos(playerid, px, py, pz);
				SetPlayerToPos(playerid, px, py-30, pz+5);
			}
			if(pa >= 202.5 && pa <= 247.5)//se
			{
				GetPlayerPos(playerid, px, py, pz);
				SetPlayerToPos(playerid, px+15, py-15, pz+5);
			}
			if(pa >= 247.5 && pa <= 292.5)//e
			{
				GetPlayerPos(playerid, px, py, pz);
				SetPlayerToPos(playerid, px+30, py, pz+5);
			}
			if(pa >= 292.5 && pa <= 332.5)//e
			{
				GetPlayerPos(playerid, px, py, pz);
				SetPlayerToPos(playerid, px+15, py+15, pz+5);
			}
			return 1;
		}
		if(strcmp(cmd, "/name", true) == 0)
		{
			if (gPlayerData[playerid][pAdmin] != 5)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_GRAD2, "U¯YCIE: /name [playerid/PartOName]");
				return 1;
			}
			giveplayerid = ReturnUser(tmp);
			if(IsPlayerConnected(giveplayerid))
			{
				if(giveplayerid != INVALID_PLAYER_ID)
				{
					GetPlayerName(giveplayerid, giveplayer, sizeof(giveplayer));
					GetPlayerName(playerid, sendername, sizeof(sendername));
					format(string, sizeof(string), "[SERVER:] %s zostal wyrzucony z serwera przez %s za imie niezgodne z formatem Imie_Nazwisko !", giveplayer, sendername);
					SendAdminMessage(COLOR_YELLOW, string);
					format(string, sizeof(string), "[SERVER:] Zostales wyrzucony z serwera przez %s za imie niezgodne z formatem Imie_Nazwisko !", sendername);
					SendClientMessage(giveplayerid, COLOR_LIGHTRED, string);
					Kick(giveplayerid);
				}
			}
			return 1;
		}
		if(strcmp(cmd, "/destroy", true) == 0)
		{
			if (gPlayerData[playerid][pAdmin] < 1)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_GRAD2, "U¯YCIE: /destroy [playerid/PartOName]");
				return 1;
			}
			new playa;
			new Float:shealth;
			new Float:slx, Float:sly, Float:slz;
			playa = ReturnUser(tmp);
			if(IsPlayerConnected(playa))
			{
				if(playa != INVALID_PLAYER_ID)
				{
					GetPlayerName(playa, giveplayer, sizeof(giveplayer));
					GetPlayerName(playerid, sendername, sizeof(sendername));
					GetPlayerHealth(playa, shealth);
					SetPlayerHealth(playa, shealth-5);
					GetPlayerPos(playa, slx, sly, slz);
					SetPlayerToPos(playa, slx, sly, slz+99);
					PlayerPlaySound(playa, 1130, slx, sly, slz+90);
					printf("%s slapped %s",sendername,  giveplayer);
					format(string, sizeof(string), "[INFO:] %s zostal zniszczony przez %s",giveplayer ,sendername);
					ABroadCast(COLOR_YELLOW,string,1);
				}
			}
			return 1;
		}
		if(strcmp(cmd, "/setskin", true) == 0)
		{
			if (gPlayerData[playerid][pAdmin] < 4)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_GRAD2, "U¯YCIE: /setskin [playerid/PartOName] [skin id]");
				return 1;
			}
			new para1;
			new level;
			para1 = ReturnUser(tmp);
			tmp = strtok(cmdtext, idx);
			level = strval(tmp);
			if(level > 299 || level < 1) { SendClientMessage(playerid, COLOR_GREY, "Wrong skin ID!"); return 1; }
			if(IsPlayerConnected(para1))
			{
				if(para1 != INVALID_PLAYER_ID)
				{
					GetPlayerName(para1, giveplayer, sizeof(giveplayer));
					GetPlayerName(playerid, sendername, sizeof(sendername));
					gPlayerData[para1][pSkin] = level;

					SavePlayerData(para1, "Skin");

					format(string, sizeof(string), "Twoj skin zostal zmieniony przez admina %s", sendername);
					SendClientMessage(para1, COLOR_WHITE, string);
					format(string, sizeof(string), "You have given %s skin to %d.", giveplayer,level);
					SendClientMessage(playerid, COLOR_WHITE, string);
					SetPlayerSkin(para1, gPlayerData[para1][pSkin]);
				}
			}//not connected
			return 1;
		}
		if(strcmp(cmd, "/krzycz", true) == 0 || strcmp(cmd, "/k", true) == 0)
		{
			GetPlayerName(playerid, sendername, sizeof(sendername));
			new length = strlen(cmdtext);
			while ((idx < length) && (cmdtext[idx] <= ' '))
			{
				idx++;
			}
			new offset = idx;
			new result[64];
			while ((idx < length) && ((idx - offset) < (sizeof(result) - 1)))
			{
				result[idx - offset] = cmdtext[idx];
				idx++;
			}
			result[idx - offset] = EOS;
			if(!strlen(result))
			{
				SendClientMessage(playerid, COLOR_GRAD2, "[INFO:] (/k)rzycz [tekst]");
				return 1;
			}
			else
			{
				format(string, sizeof(string), "%s Krzyczy: %s!!", sendername, result);
			}
			ProxDetector(30.0, playerid, string,COLOR_WHITE,COLOR_WHITE,COLOR_WHITE,COLOR_FADE1,COLOR_FADE2);
			printf("%s", string);
			return 1;
		}
		if(strcmp(cmd, "/szepcz", true) == 0 || strcmp(cmd, "/s", true) == 0)
		{
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_GRAD2, "U¯YCIE: (/s)zczepcz [id gracza] [tekst]");
				return 1;
			}
			giveplayerid = ReturnUser(tmp);
			if (IsPlayerConnected(giveplayerid))
			{
				if(giveplayerid != INVALID_PLAYER_ID)
				{
					new Float:x, Float:y, Float:z;
					GetPlayerPos(giveplayerid,x,y,z);
					if(PlayerToPoint(5, playerid, x, y, z))
					{
						GetPlayerName(playerid, sendername, sizeof(sendername));
						GetPlayerName(giveplayerid, giveplayer, sizeof(giveplayer));
						if(giveplayerid == playerid)
						{
							format(string, sizeof(string), "* %s cos do siebie szczepcze.", sendername);
							ProxDetector(5.0, playerid, string, COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE);
						}
						else
						{
							format(string, sizeof(string), "* %s szepcze do %s", sendername, giveplayer);
							ProxDetector(15.0, playerid, string, COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE);
						}
						new length = strlen(cmdtext);
						while ((idx < length) && (cmdtext[idx] <= ' '))
						{
							idx++;
						}
						new offset = idx;
						new result[64];
						while ((idx < length) && ((idx - offset) < (sizeof(result) - 1)))
						{
							result[idx - offset] = cmdtext[idx];
							idx++;
						}
						result[idx - offset] = EOS;
						if(!strlen(result))
						{
							SendClientMessage(playerid, COLOR_GRAD2, "U¯YCIE: (/s)zepcz [id gracza] [tekst]");
							return 1;
						}
						format(string, sizeof(string), "%s szepcze: %s", sendername, (result));
						SendClientMessage(giveplayerid, COLOR_YELLOW, string);
						format(string, sizeof(string), "%s szepcze: %s", sendername, (result));
						SendClientMessage(playerid,  COLOR_YELLOW, string);
						return 1;
					}
					else
					{
						SendClientMessage(playerid,  COLOR_GREY, "[INFO:] Gracz jest za daleko od Ciebie !");
						return 1;
					}
				}
			}
			else
			{
				format(string, sizeof(string), "   %d nie jest on-line.", giveplayerid);
				SendClientMessage(playerid, COLOR_GRAD1, string);
			}
			return 1;
		}
		if(strcmp(cmd, "/supervehslap", true) == 0 || strcmp(cmd, "/svs", true) == 0)
		{
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_GRAD2, "SYNTAX: /supervehslap [playerid/PartOName]");
				return 1;
			}
			new playa;
			new Float:shealth;
			giveplayerid = ReturnUser(tmp);
			new Float:slx, Float:sly, Float:slz;
			playa = ReturnUser(tmp);
			if (gPlayerData[playerid][pAdmin] >= 5)
			{
				if(IsPlayerConnected(playa))
				{
					if(playa != INVALID_PLAYER_ID)
					{
						GetPlayerName(playa, giveplayer, sizeof(giveplayer));
						GetPlayerName(playerid, sendername, sizeof(sendername));
						GetPlayerHealth(playa, shealth);
						SetPlayerHealth(playa, shealth-0);
						GetVehiclePos(GetPlayerVehicleID(giveplayerid), slx, sly, slz);
						SetVehicleToPos(GetPlayerVehicleID(giveplayerid), slx, sly, slz+100);
						PlayerPlaySound(playa, 1130, slx, sly, slz+5);
						printf("South-West Admin System: %s vehicle slapped %s",sendername,  giveplayer);
						format(string, sizeof(string), "%s was vehicle slapped slapped by %s",giveplayer ,sendername);
						ABroadCast(COLOR_LIGHTRED,string,1);
					}
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_GRAD1, "** You are not authorized to use that command.");
			}
			return 1;
		}
		if(strcmp(cmd, "/explode", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] != 5)
				return 0;
			GetPlayerName(playerid, sendername, sizeof(sendername));
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_GREY, "/explode [Playerid]");
				return 1;
			}
			giveplayerid = strval(tmp);
			GetPlayerName(giveplayerid, giveplayer, sizeof(giveplayer));
			GetPlayerName(playerid, sendername, sizeof(sendername));
			if(IsPlayerConnected(giveplayerid))
			{
				if(IsPlayerConnected(giveplayerid))
				{
					format(string, sizeof(string), "[SERVER:] %s zostal wyjebany w powietrze przez %s",giveplayer, sendername);
					ABroadCast(COLOR_LIGHTRED,string,1);
					//SendClientMessageToAll(COLOR_DBLUE, string);
					SetPlayerHealth(giveplayerid, 10);
					new Float:boomx, Float:boomy, Float:boomz;
					GetPlayerPos(giveplayerid,boomx, boomy, boomz);
					CreateExplosion(boomx, boomy , boomz, 7, 10);
				}
				else
				{
					format(string, sizeof(string), "%d nie jest on-line.", giveplayerid);
					SendClientMessage(playerid, COLOR_RED, string);
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie takiego gostka !");
			}
			return 1;
		}
		if(strcmp(cmd, "/gwalc", true) == 0) // by LordMan
		{
			if(gPlayerData[playerid][pJob] != 8)
			{
				SendClientMessage(playerid, COLOR_GREY, "[INFO:] Nie jesteœ gwa³cicielem !");
				return 1;
			}
			if(KnockedDown[playerid] == 1)
			{
				SendClientMessage(playerid, COLOR_GREY, "Nie mozesz zgwa³cic kogoœ kto jest ju¿ gwa³cony");
				return 1;
			}
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_WHITE, "[INFO:] /gwalc [id gracza]");
				return 1;
			}
			giveplayerid = ReturnUser(tmp);
			if(IsPlayerConnected(giveplayerid))
			{
				if(giveplayerid != INVALID_PLAYER_ID)
				{
					if (ProxDetectorS(1.0, playerid, giveplayerid))
					{
						if(KnockedDown[giveplayerid] != 1)
						{
							if(giveplayerid == playerid)
							{
								SendClientMessage(playerid, COLOR_GREY, "[INFO:] Nie mozesz sam siebie zgwa³ciæ !");
								return 1;
							}
							if(IsPlayerInAnyVehicle(giveplayerid))
							{
								return 1;
							}
							GetPlayerName(playerid, sendername, sizeof(sendername));
							GetPlayerName(giveplayerid, giveplayername, sizeof(giveplayername));
							new rands = random(2)+1;
							format(string, sizeof(string), "* %s chwyci³ %s i próbuje j¹/jego zgwa³ciæ", sendername, giveplayername);
							ProxDetector(30.0, playerid, string, COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE);
							ApplyAnimation(playerid,"FIGHT_D","FightD_3",4.0,0,1,1,0,0);
							if(rands == 1)
							{
								TogglePlayerControllable(giveplayerid, 0);
								ApplyAnimation(giveplayerid, "CRACK", "crckdeth2", 4.0, 1, 0, 0, 0, 0);
								SetTimerEx("ClearKnock", 20000, false, "i", giveplayerid);
								KnockedDown[giveplayerid] = 1;
								format(string, sizeof(string), "* %s zacza³ gwa³ciæ", sendername);
								ProxDetector(30.0, playerid, string, COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE);
							}
							else
							{
								format(string, sizeof(string), "* %s probowa³ gwa³ciæ j¹/jego bez powodzenia", sendername);
								ProxDetector(30.0, playerid, string, COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE);
							}
							return 1;
						}
						else
						{
							SendClientMessage(playerid, COLOR_GREY, "[INFO:] Ta osoba jest ju¿ gwa³cona");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_GREY, "[INFO:] Gracz jest za daleko !");
					}
				}
			}
			return 1;
		}
		if(strcmp(cmd, "/slap", true) == 0)
		{
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_GRAD2, "[INFO:] /slap [playerid/PartOName]");
				return 1;
			}
			new playa;
			new Float:shealth;
			new Float:slx, Float:sly, Float:slz;
			playa = ReturnUser(tmp);
			if(gPlayerData[playerid][pAdmin] != 5)
			{
				if(IsPlayerConnected(playa))
				{
					GetPlayerName(playa, giveplayer, sizeof(giveplayer));
					GetPlayerName(playerid, sendername, sizeof(sendername));
					GetPlayerHealth(playa, shealth);
					SetPlayerHealth(playa, shealth-5);
					GetPlayerPos(playa, slx, sly, slz);
					SetPlayerToPos(playa, slx, sly, slz+5);
					PlayerPlaySound(playa, 1130, slx, sly, slz+5);
					printf("%s slapped %s",sendername,  giveplayer);
					format(string, sizeof(string), "%s was slapped by %s",giveplayer ,sendername);
					ABroadCast(COLOR_YELLOW,string,1);
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_GRAD1, "   you are not authorized to use that command!");
			}
			return 1;
		}
		// if(strcmp(cmd, "/b", true) == 0)//local ooc
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
				// SendClientMessage(playerid, COLOR_GRAD2, "[INFO:] /b [local ooc chat]");
				// return 1;
			// }
			// else
			// {
				// format(string, sizeof(string), "(( [%i] [%s] mówi: %s ))", playerid, gPlayerData[playerid][pOOCName], result);
			// }
			// ProxDetector(20.0, playerid, string,COLOR_FADE1,COLOR_FADE2,COLOR_FADE3,COLOR_FADE4,COLOR_FADE5);
			// printf("%s", string);
			// new Year, Month, Day;
			// getdate(Year, Month, Day);
			// new Hour, Minute, Second;
			// gettime(Hour, Minute, Second);
			// format(string, sizeof(string), "[LOOC][%02d/%02d/%d][%02d:%02d:%02d] [%s] [%d] : %s", Day, Month, Year, Hour, Minute, Second, gPlayerData[playerid][pOOCName], playerid, result);
			// OOCLog(string);
			// return 1;
		// }
		// if(strcmp(cmd, "/aooc", true) == 0 || strcmp(cmd, "/ao", true) == 0)
		// {
			// if(gPlayerData[playerid][pAdmin] == 0)
				// return 0;
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
				// SendClientMessage(playerid, COLOR_GRAD2, "U¯YCIE: (/ao)oc [aooc chat]");
				// return 1;
			// }
			// format(string, sizeof(string), "[AOOC] [Admin %s] [%d] : %s " , gPlayerData[playerid][pOOCName], playerid, result);
			// printf("%s", string);
			// OOCOff(0x62B382AA,string);
			// new Year, Month, Day;
			// getdate(Year, Month, Day);
			// new Hour, Minute, Second;
			// gettime(Hour, Minute, Second);
			// format(string, sizeof(string), "[AOOC][%02d/%02d/%d][%02d:%02d:%02d] [Admin %s] [%d] : %s", Day, Month, Year, Hour, Minute, Second, gPlayerData[playerid][pOOCName], playerid, result);
			// OOCLog(string);
			// return 1;
		// }
		if(strcmp(cmd, "/asetleader", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] <= 1)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /asetleader [playerid/PartOName] [FactionID]");
				return 1;
			}
			new para1;
			new level;
			para1 = ReturnUser(tmp);
			tmp = strtok(cmdtext, idx);
			level = strval(tmp);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /asetleader [playerid/PartOName] [FactionID]");
				return 1;
			}
			if(IsPlayerConnected(para1))
			{
				if(para1 != INVALID_PLAYER_ID)
				{
					gPlayerData[para1][pFaction] = level;
					gPlayerData[para1][pRank] = 1;

					SavePlayerData(para1, "Faction");
					SavePlayerData(para1, "Rank");

					SetPlayerSpawn(para1);

					format(string, sizeof(string), "[INFO:] You have made %s leader of faction ID: %d (%s).", GetPlayerNameEx(para1),level,DynamicFactions[level][Name]);
					SendClientMessage(playerid, COLOR_LIGHTBLUE, string);

					if(gPlayerData[para1][pFirstLeader])
					{
						format(string, sizeof(string), "[INFO:] Zosta³eœ liderem frakcji %s mianowany przez %s.", DynamicFactions[level][Name],GetPlayerNameEx(playerid));
						SendClientMessage(para1, COLOR_LIGHTBLUE, string);
					}
					else
					{
						format(string, sizeof(string), "[INFO:] Zosta³eœ mianowany na lidera frakcji %s ! Przekazuj¹cy: %s.", DynamicFactions[level][Name],GetPlayerNameEx(playerid));
						SendClientMessage(para1, COLOR_LIGHTBLUE, string);

						AddExpPoint(para1);
						gPlayerData[para1][pFirstLeader] = 1;

						SavePlayerData(para1, "FirstLeader");
					}

					if(DynamicFactions[level][fUseSkins] == 1)
					{
						SetPlayerSkin(para1,DynamicFactions[level][fSkin1]);
					}
					printf("[WARNING:] /asetleader has been used by %s for %s", GetPlayerNameEx(playerid), GetPlayerNameEx(para1));
				}
			}
			return 1;
		}
		if(strcmp(cmd, "/ogloszenie", true) == 0 || strcmp(cmd, "/ad", true) == 0)
		{
			new length = strlen(cmdtext);
			while ((idx < length) && (cmdtext[idx] <= ' '))
			{
				idx++;
			}
			new offset = idx;
			new result[128];
			while ((idx < length) && ((idx - offset) < (sizeof(result) - 1)))
			{
				result[idx - offset] = cmdtext[idx];
				idx++;
			}
			result[idx - offset] = EOS;
			if(!strlen(result))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] (/ad)/ogloszenie [tresc ogloszenia]");
				return 1;
			}
			new payout;
			for(new i = 0; i < sizeof(Businesses); i++)
			{
				if (PlayerToPoint(1.0, playerid,Businesses[i][EnterX], Businesses[i][EnterY], Businesses[i][EnterZ]) || PlayerToPoint(25.0, playerid,Businesses[i][ExitX], Businesses[i][ExitY], Businesses[i][ExitZ]))
				{
					if(GetPlayerVirtualWorld(playerid) == i)
					{
						if(Businesses[i][BizType] == 5)
						{
							if(Businesses[i][Products] != 0)
							{
								if( gAddCooldown[playerid] > 0 && gPlayerData[playerid][pAdmin] == 0 )
								{
									format(string, sizeof(string), "[INFO:] Musisz poczekaæ %d sekund zanim wystawisz nowe og³oszenie",  gAddCooldown[playerid]);
									SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
									return 1;
								}
								payout = idx * 5;
								if(GetPlayerCash(playerid) < payout)
								{
									SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie masz wystarczajacej ilosci pieniedzy.");
									return 1;
								}
								GivePlayerCash(playerid, -payout);
								Businesses[i][Till] += payout;
								Businesses[i][Products]--;
								gAddCooldown[playerid] = 120;
								format(string, sizeof(string), "---------------------------------[Ogloszenie (%s)]---------------------------------",  Businesses[i][BusinessName]);
								SendClientMessageToAll(COLOR_LIGHTGREEN, string);
								format(string, sizeof(string), "[OGLOSZENIE:] %s", result);
								SendClientMessageToAll(COLOR_WHITE, string);
								format(string, sizeof(string), "[OGLOSZENIE:] Nadane przez: %s", gPlayerData[playerid][pName]);
								SendClientMessageToAll(COLOR_WHITE, string);
								SendClientMessageToAll(COLOR_LIGHTGREEN, "-----------------------------------------------------------------------------------------------------------------------");
								format(string, sizeof(string), "[INFO:] Znaki zawarte: %d - Koszt: $%d - Podziekowania od %s", idx,payout,Businesses[i][BusinessName]);
								SendClientMessage(playerid, COLOR_WHITE, string);
								PlayerActionMessage(playerid,15.0,"da³ pracownikowi firmy troche pieniêdzy otrzymuj¹c w zamian wystawione og³oszenie.");

								SaveBizData(i, "Till");
								SaveBizData(i, "Products");
								return 1;
							}
							else
							{
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] W biznesie brakuje poroduktów");
								return 1;
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Ten biznes to nie firma reklamujaca");
							return 1;
						}
					}
				}
				
			}
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie jesteœ w budynku biznesu");
			return 1;
		}
		if(strcmp(cmd, "/agotobiz", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 1)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /agotobiz [id]");
				return 1;
			}
			new id = strval(tmp);
			SetPlayerToPos(playerid,Businesses[id][EnterX],Businesses[id][EnterY],Businesses[id][EnterZ]);
			SetPlayerInterior(playerid,Businesses[id][EnterInterior]);
			SetPlayerVirtualWorld(playerid,Businesses[id][EnterWorld]);
			new form[128];
			format(form, sizeof(form), "[INFO:] You teleported to business ID: %d.", id);
			SendClientMessage(playerid, COLOR_ADMINCMD, form);
			return 1;
		}
		if(strcmp(cmd, "/abiztype", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2,"[BUSINESS TYPES:]");
				SendClientMessage(playerid, COLOR_ADMINCMD,BUSINESS_TYPES);
				SendClientMessage(playerid, COLOR_ADMINCMD,BUSINESS_TYPES2);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /abiztype [businessid] [type]");
				return 1;
			}
			new id;
			new form[128];
			id = strval(tmp);
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2,"[BUSINESS TYPES:]");
				SendClientMessage(playerid, COLOR_ADMINCMD,BUSINESS_TYPES);
				SendClientMessage(playerid, COLOR_ADMINCMD,BUSINESS_TYPES2);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /abiztype [businessid] [type]");
				return 1;
			}
			new id2;
			id2 = strval(tmp);
			new businesstype[128];
			if(Businesses[id][Owned] == 0)
			{
				if(Businesses[id][BizType] != 0)
				{
					if(Businesses[id][BizType] == 1) { businesstype = "Restauracja"; }
					else if(Businesses[id][BizType] == 2) { businesstype = "Siec komorkowa"; }
					else if(Businesses[id][BizType] == 3) { businesstype = "Sklep 24/7"; }
					else if(Businesses[id][BizType] == 4) { businesstype = "Sklep z bronia"; }
					else if(Businesses[id][BizType] == 5) { businesstype = "Studio reklamowe"; }
					else if(Businesses[id][BizType] == 6) { businesstype = "Sklep z ubraniami"; }
					else if(Businesses[id][BizType] == 7) { businesstype = "Bar/Club"; }
					else if(Businesses[id][BizType] == 8) { businesstype = "Studio nagraniowe"; }
					else if(Businesses[id][BizType] == 9) { businesstype = "Studio"; }
					else if(Businesses[id][BizType] == 10) { businesstype = "Salon samochodowy"; }
					else if(Businesses[id][BizType] == 11) { businesstype = "Stacja paliw"; }
				}
				else { businesstype = "Nie ustawione"; }

				format(string, sizeof(string), "Ten biznes jest na sprzeda¿!");
				UpdateDynamic3DTextLabelText(Business3DTextLabelA[id], COLOR_LIGHTBLUE2, string);

				format(string, sizeof(string), "Numer Budynku: %d, Nazwa biznesu: %s, Typ biznesu: %s",id,Businesses[id][BusinessName],businesstype);
				UpdateDynamic3DTextLabelText(Business3DTextLabelB[id], COLOR_LIGHTBLUE2, string);

				format(string, sizeof(string), "Cena: $%d",Businesses[id][BizPrice]);
				UpdateDynamic3DTextLabelText(Business3DTextLabelC[id], COLOR_LIGHTBLUE2, string);
			}
			if(Businesses[id][Owned] == 1)
			{
				if(Businesses[id][BizType] != 0)
				{
					if(Businesses[id][BizType] == 1) { businesstype = "Restauracja"; }
					else if(Businesses[id][BizType] == 2) { businesstype = "Siec komorkowa"; }
					else if(Businesses[id][BizType] == 3) { businesstype = "Sklep 24/7"; }
					else if(Businesses[id][BizType] == 4) { businesstype = "Sklep z bronia"; }
					else if(Businesses[id][BizType] == 5) { businesstype = "Studio reklamowe"; }
					else if(Businesses[id][BizType] == 6) { businesstype = "Sklep z ubraniami"; }
					else if(Businesses[id][BizType] == 7) { businesstype = "Bar/Club"; }
					else if(Businesses[id][BizType] == 8) { businesstype = "Studio nagraniowe"; }
					else if(Businesses[id][BizType] == 9) { businesstype = "Studio"; }
					else if(Businesses[id][BizType] == 10) { businesstype = "Salon samochodowy"; }
					else if(Businesses[id][BizType] == 11) { businesstype = "Stacja paliw"; }
				}
				else { businesstype = "Nie ustawione"; }

				format(string, sizeof(string), "Nazwa biznesu: %s, Typ biznesu: %s",Businesses[id][BusinessName],businesstype);
				UpdateDynamic3DTextLabelText(Business3DTextLabelA[id], COLOR_LIGHTBLUE2, string);

				format(string, sizeof(string), "Numer Budynku: %d, Typ biznesu: %s",id,Businesses[id][Owner]);
				UpdateDynamic3DTextLabelText(Business3DTextLabelB[id], COLOR_LIGHTBLUE2, string);

				format(string, sizeof(string), "Wejœciówka: $%d",Businesses[id][EntranceCost]);
				UpdateDynamic3DTextLabelText(Business3DTextLabelC[id], COLOR_LIGHTBLUE2, string);
			}
			Businesses[id][BizType] = id2;
			format(form, sizeof form, "You've set Businesses ID: %d's type to %d.", id,id2);
			SendClientMessage(playerid, COLOR_ADMINCMD,form);
			SaveBizData(id, "BizType");
			return 1;
		}
		if(strcmp(cmd, "/abizentrance", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 1)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /abizentrance [bizid]");
				return 1;
			}
			new id = strval(tmp);
			new pmodel;
			new Float:x,Float:y,Float:z;
			GetPlayerPos(playerid, x, y, z);
			Businesses[id][EnterX] = x;
			Businesses[id][EnterY] = y;
			Businesses[id][EnterZ] = z;
			Businesses[id][EnterWorld] = GetPlayerVirtualWorld(playerid);
			Businesses[id][EnterInterior] = GetPlayerInterior(playerid);
			new Float:angle;
			GetPlayerFacingAngle(playerid, angle);
			Businesses[id][EnterAngle] = angle;
			switch(Businesses[id][Owned])
			{
				case 0: pmodel = 1272;
				case 1: pmodel = 1239;
			}
			DestroyDynamicPickup(Businesses[id][PickupID]);
			CreateDynamicPickup(pmodel, 1, Businesses[id][EnterX], Businesses[id][EnterY], Businesses[id][EnterZ]);
			DestroyDynamic3DTextLabel(Business3DTextLabelA[id]);
			DestroyDynamic3DTextLabel(Business3DTextLabelB[id]);
			DestroyDynamic3DTextLabel(Business3DTextLabelC[id]);
			new businesstype[128];
			if(Businesses[id][BizType] != 0)
			{
				if(Businesses[id][BizType] == 1) { businesstype = "Restauracja"; }
				else if(Businesses[id][BizType] == 2) { businesstype = "Siec komorkowa"; }
				else if(Businesses[id][BizType] == 3) { businesstype = "Sklep 24/7"; }
				else if(Businesses[id][BizType] == 4) { businesstype = "Sklep z bronia"; }
				else if(Businesses[id][BizType] == 5) { businesstype = "Studio reklamowe"; }
				else if(Businesses[id][BizType] == 6) { businesstype = "Sklep z ubraniami"; }
				else if(Businesses[id][BizType] == 7) { businesstype = "Bar/Club"; }
				else if(Businesses[id][BizType] == 8) { businesstype = "Studio nagraniowe"; }
				else if(Businesses[id][BizType] == 9) { businesstype = "Studio"; }
				else if(Businesses[id][BizType] == 10) { businesstype = "Salon samochodowy"; }
				else if(Businesses[id][BizType] == 11) { businesstype = "Stacja paliw"; }
			}
			else { businesstype = "Nie ustawione"; }
			if(Businesses[id][Owned] == 0)
			{
				format(string, sizeof(string), "Ten biznes jest na sprzeda¿!");
				Business3DTextLabelA[id] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE2, Businesses[id][EnterX], Businesses[id][EnterY], Businesses[id][EnterZ]+1.0, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

				format(string, sizeof(string), "Numer Budynku: %d, Nazwa biznesu: %s, Typ biznesu: %s", id, Businesses[id][BusinessName],businesstype);
				Business3DTextLabelB[id] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE2, Businesses[id][EnterX], Businesses[id][EnterY], Businesses[id][EnterZ]+0.5, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
				
				format(string, sizeof(string), "Cena: $%d",Businesses[id][BizPrice]);
				Business3DTextLabelC[id] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE2, Businesses[id][EnterX], Businesses[id][EnterY], Businesses[id][EnterZ], 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
			}
			else
			{
				format(string, sizeof(string), "Nazwa biznesu: %s, Typ biznesu: %s", Businesses[id][BusinessName], businesstype);
				Business3DTextLabelA[id] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE2, Businesses[id][EnterX], Businesses[id][EnterY], Businesses[id][EnterZ]+1.0, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

				format(string, sizeof(string), "Numer Budynku: %d, W³aœciciel: %s", id, Businesses[id][Owner]);
				Business3DTextLabelB[id] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE2, Businesses[id][EnterX], Businesses[id][EnterY], Businesses[id][EnterZ]+0.5, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

				format(string, sizeof(string), "Wejœciówka: $%d",Businesses[id][EntranceCost]);
				Business3DTextLabelC[id] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE2, Businesses[id][EnterX], Businesses[id][EnterY], Businesses[id][EnterZ], 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
			}
			SaveBizData(id, "EnterX");
			SaveBizData(id, "EnterY");
			SaveBizData(id, "EnterZ");
			SaveBizData(id, "EnterAngle");
			SaveBizData(id, "EnterWorld");
			SaveBizData(id, "EnterInterior");
			new form[128];
			format(form, sizeof(form), "[INFO:] You have set business ID: %d's location.", id);
			SendClientMessage(playerid, COLOR_ADMINCMD, form);
			return 1;
		}
		if(strcmp(cmd, "/cenabiz", true) == 0)
		{
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /cenabiz [businessid] [price]");
				return 1;
			}
			if (gPlayerData[playerid][pFaction] == 9)
			{
				new id;
				id = strval(tmp);
				
				if(Businesses[id][Owned] == 1)
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz zmieniæ ceny biznesu kupionego !");
					return 1;
				}
				tmp = strtok(cmdtext, idx);
				if(!strlen(tmp))
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /cenabiz [businessid] [price]");
					return 1;
				}
				new id2;
				id2 = strval(tmp);

				if(id2 < 0)
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Cena musi byæ wiêksza lub równa zeru");
					return 1;
				}
				
				Businesses[id][BizPrice] = id2;
				new form[128];
				format(form, sizeof form, "Ustawiles cene biznesu ID: %d na %d$", id,id2);
				SendClientMessage(playerid, COLOR_ADMINCMD,form);
				SaveBizData(id, "BizPrice");

				if(Businesses[id][BizPrice] != 0) // Don't create the business icon if the Cena is 0.
				{
					if(Businesses[id][Owned] == 0)
					{
						// Businesses[i][PickupID] = CreateDynamicPickup(1272, 1, Businesses[i][EnterX], Businesses[i][EnterY], Businesses[i][EnterZ]);
						DestroyDynamic3DTextLabel( Business3DTextLabelC[id] );
						format(string, sizeof(string), "Cena: $%d",Businesses[id][BizPrice]);
						Business3DTextLabelC[id] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE2, Businesses[id][EnterX], Businesses[id][EnterY], Businesses[id][EnterZ], 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
					}
				}
				else
				{
					// DestroyDynamicPickup(1272, 1, Businesses[i][EnterX], Businesses[i][EnterY], Businesses[i][EnterZ]);

					format(string, sizeof(string), "");
					Business3DTextLabelA[id] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE2, Businesses[id][EnterX], Businesses[id][EnterY], Businesses[id][EnterZ]+1.0, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

					format(string, sizeof(string), "");
					Business3DTextLabelB[id] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE2, Businesses[id][EnterX], Businesses[id][EnterY], Businesses[id][EnterZ]+0.5, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

					format(string, sizeof(string), "");
					Business3DTextLabelC[id] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE2, Businesses[id][EnterX], Businesses[id][EnterY], Businesses[id][EnterZ], 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
				}
				
				// log
				format(form, sizeof(form), "[GOVERNMENT:] Business id: %d, price set up to %d by %s", id, id2, gPlayerData[playerid][pName]);
				print(form);
				GovermentLog(form);
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ urzednikiem");
			}
			return 1;
		}
		if(strcmp(cmd, "/typbiz", true) == 0)
		{
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2,"[BUSINESS TYPES:]");
				SendClientMessage(playerid, COLOR_ADMINCMD,BUSINESS_TYPES);
				SendClientMessage(playerid, COLOR_ADMINCMD,BUSINESS_TYPES2);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /typbiz [businessid] [type]");
				return 1;
			}
			if (gPlayerData[playerid][pFaction] == 9)
			{
					new id;
					new form[128];
					id = strval(tmp);
					tmp = strtok(cmdtext, idx);
					if(!strlen(tmp))
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2,"[BUSINESS TYPES:]");
						SendClientMessage(playerid, COLOR_ADMINCMD,BUSINESS_TYPES);
						SendClientMessage(playerid, COLOR_ADMINCMD,BUSINESS_TYPES2);
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /typbiz [businessid] [type]");
						return 1;
					}
					new id2;
					id2 = strval(tmp);

					Businesses[id][BizType] = id2;
					format(form, sizeof form, "Ustawiles typ biz ID: %d's type to %d.", id,id2);
					SendClientMessage(playerid, COLOR_ADMINCMD,form);
					SaveBizData(id, "BizType");

					// log
					format(form, sizeof(form), "[GOVERNMENT:] Business id: %d, type set up to: %d  by %s", id, id2, gPlayerData[playerid][pName]);
					print(form);
					GovermentLog(form);
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "nie jesteœ urzednikiem.");
			}
			return 1;
		}
		if(strcmp(cmd, "/ustawbiz", true) == 0)
		{
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /ustawbiz [bizid]");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Raz ustawionego biznesu nie mo¿na przestawiæ !");
				return 1;
			}
			new id = strval(tmp);
			if(gPlayerData[playerid][pFaction] == FACTIONID_GOVERNMENT)
			{
				if(Businesses[id][Owned])
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz skorzystaæ z tego ID poniewa¿ jest ono zajête !");
					return 1;
				}
				if(Businesses[id][BPlaced])
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz u¿yæ tego ID poniewa¿ jest ono zajête, wybierz inne");
					return 1;
				}
				if(!Businesses[id][BIntSet])
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Przed ustawieniem biznesu ustaw jego interior !");
					return 1;
				}
				new pmodel;
				new Float:x,Float:y,Float:z;
				GetPlayerPos(playerid, x, y, z);
				Businesses[id][EnterX] = x;
				Businesses[id][EnterY] = y;
				Businesses[id][EnterZ] = z;
				Businesses[id][EnterWorld] = GetPlayerVirtualWorld(playerid);
				Businesses[id][EnterInterior] = GetPlayerInterior(playerid);
				new Float:angle;
				GetPlayerFacingAngle(playerid, angle);
				Businesses[id][EnterAngle] = angle;
				switch(Businesses[id][Owned])
				{
					case 0: pmodel = 1272;
					case 1: pmodel = 1239;
				}

				Businesses[id][PickupID] = ChangePickupModel(Businesses[id][PickupID], pmodel, Businesses[id][EnterX], Businesses[id][EnterY], Businesses[id][EnterZ]);

				DestroyDynamic3DTextLabel(Business3DTextLabelA[id]);
				DestroyDynamic3DTextLabel(Business3DTextLabelB[id]);
				DestroyDynamic3DTextLabel(Business3DTextLabelC[id]);
				new businesstype[128];
				if(Businesses[id][BizType] != 0)
				{
					if(Businesses[id][BizType] == 1) { businesstype = "Restauracja"; }
					else if(Businesses[id][BizType] == 2) { businesstype = "Siec komorkowa"; }
					else if(Businesses[id][BizType] == 3) { businesstype = "Sklep 24/7"; }
					else if(Businesses[id][BizType] == 4) { businesstype = "Sklep z bronia"; }
					else if(Businesses[id][BizType] == 5) { businesstype = "Studio reklamowe"; }
					else if(Businesses[id][BizType] == 6) { businesstype = "Sklep z ubraniami"; }
					else if(Businesses[id][BizType] == 7) { businesstype = "Bar/Club"; }
					else if(Businesses[id][BizType] == 8) { businesstype = "Studio nagraniowe"; }
					else if(Businesses[id][BizType] == 9) { businesstype = "Studio"; }
					else if(Businesses[id][BizType] == 10) { businesstype = "Salon samochodowy"; }
					else if(Businesses[id][BizType] == 11) { businesstype = "Stacja paliw"; }
				}
				else { businesstype = "Nie ustawione"; }
				if(Businesses[id][Owned] == 0)
				{
					format(string, sizeof(string), "Ten biznes jest na sprzeda¿!");
					Business3DTextLabelA[id] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE2, Businesses[id][EnterX], Businesses[id][EnterY], Businesses[id][EnterZ]+1.0, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

					format(string, sizeof(string), "Numer Budynku: %d, Nazwa biznesu: %s, Typ biznesu: %s",id,Businesses[id][BusinessName],businesstype);
					Business3DTextLabelB[id] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE2, Businesses[id][EnterX], Businesses[id][EnterY], Businesses[id][EnterZ]+0.5, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
					
					format(string, sizeof(string), "Cena: $%d",Businesses[id][BizPrice]);
					Business3DTextLabelC[id] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE2, Businesses[id][EnterX], Businesses[id][EnterY], Businesses[id][EnterZ], 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
				}
				else
				{
					format(string, sizeof(string), "Nazwa biznesu: %s, Typ biznesu: %s",Businesses[id][BusinessName],businesstype);
					Business3DTextLabelA[id] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE2, Businesses[id][EnterX], Businesses[id][EnterY], Businesses[id][EnterZ]+1.0, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

					format(string, sizeof(string), "Numer Budynku: %d, W³aœciciel: %s", id,Businesses[id][Owner]);
					Business3DTextLabelB[id] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE2, Businesses[id][EnterX], Businesses[id][EnterY], Businesses[id][EnterZ]+0.5, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

					format(string, sizeof(string), "Wejœciówka: $%d",Businesses[id][EntranceCost]);
					Business3DTextLabelC[id] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE2, Businesses[id][EnterX], Businesses[id][EnterY], Businesses[id][EnterZ], 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
				}
				SaveBizData(id, "EnterX");
				SaveBizData(id, "EnterY");
				SaveBizData(id, "EnterZ");
				SaveBizData(id, "EnterInterior");
				SaveBizData(id, "EnterWorld");
				SaveBizData(id, "EnterAngle");
				new form[128];
				format(form, sizeof(form), "[INFO:] Postawiles biz ID na : %d's.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD, form);

				format(form, sizeof(form), "[GOVERNMENT:] Business id: %d, set up X: %f, Y: %f, Z: %f by %s", id, x, y, z, gPlayerData[playerid][pName]);
				print(form);
				GovermentLog(form);
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ urzednikiem");
			}
			return 1;
		}
		if(strcmp(cmd, "/abizexit", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 1)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /abizexit [bizid]");
				return 1;
			}
			new id = strval(tmp);
			new Float:x,Float:y,Float:z;
			GetPlayerPos(playerid, x, y, z);
			Businesses[id][ExitX] = x;
			Businesses[id][ExitY] = y;
			Businesses[id][ExitZ] = z;
			Businesses[id][ExitInterior] = GetPlayerInterior(playerid);
			new Float:angle;
			GetPlayerFacingAngle(playerid, angle);
			Businesses[id][ExitAngle] = angle;
			SaveBizData(id, "ExitX");
			SaveBizData(id, "ExitY");
			SaveBizData(id, "ExitZ");
			SaveBizData(id, "ExitInterior");
			SaveBizData(id, "ExitAngle");
			new form[128];
			format(form, sizeof(form), "[INFO:] You have set business ID: %d's exit location.", id);
			SendClientMessage(playerid, COLOR_ADMINCMD, form);
			return 1;
		}
		if(strcmp(cmd, "/agotohouse", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 1)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /agotohouse [id]");
				return 1;
			}
			new id = strval(tmp);
			SetPlayerToPos(playerid,Houses[id][EnterX],Houses[id][EnterY],Houses[id][EnterZ]);
			SetPlayerInterior(playerid,Houses[id][EnterInterior]);
			SetPlayerVirtualWorld(playerid,Houses[id][EnterWorld]);
			new form[128];
			format(form, sizeof(form), "[INFO:] You teleported to house ID: %d.", id);
			SendClientMessage(playerid, COLOR_ADMINCMD, form);
			return 1;
		}
		if(strcmp(cmd, "/ahouseint", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /ahouseint [houseid] [id (1-50)]");
				return 1;
			}
			new id;
			id = strval(tmp);
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /ahouseint [houseid] [id 1-50]");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[1:] - 3 kk; [2:] - 500 k; [3:] - 300 k; [4:] - 3 kk; [5:] - 1,5 kk; [6:] - 150 k; [7:] - 250 k; [8:] - 300 k; [9:] - 3 kk; [10:] - 800 k");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[11:] - 4 kk; [12:] - 110 k; [13:] - 100 k; [14:] - 400 k; [15:] - 300 k; [16:] - 400 k; [17:] - 1 kk; [18:] - 1,5 kk; [19:] - 500 k; [20:] - 850 k");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[21:] - 200 k; [22:] - 1,5 kk; [23:] - 300 k; [24:] - 50 k; [25:] - 70 k; [27:] - 10 k; [28:] - 0 k; [29:] - 0 k; [30:] - 800 k");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[31:] - 1 k; [32:] - 200 k; [33:] - 1 k; [34:] - 1 k; [35:] - 1 k; [36:] - 1 k; [37:] - 1 k; [38:] - 150 k; [39:] - 100 k; [40:] - 600 k");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "{41:] - 300 k; [42:] - 1 k; [43:] - 10-3 k; [44:] - ??; [45:] - ??; [46:] - ??; [47:] - ??; [48:] - ??; [49:] - domek");

				return 1;
			}
			new id2;
			id2 = strval(tmp);
			if(id2 < 1 || id2 > 52) { SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Interior ID's 1-50."); return 1; }
			
			Houses[id][HInterior] = id2;
			SaveHouseData(id, "Interior");
			if(id2 == 1)
			{
				Houses[id][ExitX] = 235.212356;
				Houses[id][ExitY] = 1186.690551;
				Houses[id][ExitZ] = 1080.339966;
				Houses[id][ExitInterior] = 3;
				Houses[id][ExitAngle] = 359.15814;
				format(string, sizeof string, "House ID: %d - Description: Large/2 story/3 bedrooms/clone of House 9.", id,id2);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 2)
			{
				Houses[id][ExitX] = 226.781341;
				Houses[id][ExitY] = 1240.207153;
				Houses[id][ExitZ] = 1082.149902;
				Houses[id][ExitInterior] = 2;
				Houses[id][ExitAngle] = 93.762290;
				format(string, sizeof string, "House ID: %d - Description: Medium/1 story/1 bedroom.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 3)
			{
				Houses[id][ExitX] = 223.180511;
				Houses[id][ExitY] = 1287.081420;
				Houses[id][ExitZ] = 1082.199951;
				Houses[id][ExitInterior] = 1;
				Houses[id][ExitAngle] = 359.134765;
				format(string, sizeof string, "House ID: %d - Description: Small/1 story/1 bedroom.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 4)
			{
				Houses[id][ExitX] = 225.630997;
				Houses[id][ExitY] = 1022.479980;
				Houses[id][ExitZ] = 1084.069946;
				Houses[id][ExitInterior] = 7;
				Houses[id][ExitAngle] = 93.762290;
				format(string, sizeof string, "House ID: %d - Description: VERY Large/2 story/4 bedrooms.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 5)
			{
				Houses[id][ExitX] = 295.138977;
				Houses[id][ExitY] = 1472.259887;
				Houses[id][ExitZ] = 1080.519897;
				Houses[id][ExitInterior] = 15;
				Houses[id][ExitAngle] = 0.701460;
				format(string, sizeof string, "House ID: %d - Description: Small/1 story/2 bedrooms.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 6)
			{
				Houses[id][ExitX] = 327.982147;
				Houses[id][ExitY] = 1477.730102;
				Houses[id][ExitZ] = 1084.449951;
				Houses[id][ExitInterior] = 15;
				Houses[id][ExitAngle] = 357.25476;
				format(string, sizeof string, "House ID: %d - Description: Small/1 story/2 bedrooms.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 7)
			{
				Houses[id][ExitX] = 387.219482;
				Houses[id][ExitY] = 1471.769897;
				Houses[id][ExitZ] = 1080.209961;
				Houses[id][ExitInterior] = 15;
				Houses[id][ExitAngle] = 93.762290;
				format(string, sizeof string, "House ID: %d - Description: Small/1 story/1 bedroom/NO BATHROOM.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 8)
			{
				Houses[id][ExitX] = 375.971985;
				Houses[id][ExitY] = 1417.269897;
				Houses[id][ExitZ] = 1081.409912;
				Houses[id][ExitInterior] = 15;
				format(string, sizeof string, "House ID: %d - Description: Small/1 story/1 bedroom.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 9)
			{
				Houses[id][ExitX] = 491.233459;
				Houses[id][ExitY] = 1398.510131;
				Houses[id][ExitZ] = 1080.339966;
				Houses[id][ExitInterior] = 2;
				Houses[id][ExitAngle] = 0.654741;
				format(string, sizeof string, "House ID: %d - Description: Large/2 story/3 bedrooms.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 10)
			{
				Houses[id][ExitX] = 447.029083;
				Houses[id][ExitY] = 1397.068969;
				Houses[id][ExitZ] = 1084.339966;
				Houses[id][ExitInterior] = 2;
				Houses[id][ExitAngle] = 354.074676;
				format(string, sizeof string, "House ID: %d - Description: Medium/1 story/2 bedrooms.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 11)
			{
				Houses[id][ExitX] = 226.305770;
				Houses[id][ExitY] = 1114.389893;
				Houses[id][ExitZ] = 1081.189941;
				Houses[id][ExitInterior] = 5;
				Houses[id][ExitAngle] = 271.643859;
				format(string, sizeof string, "House ID: %d - Description: Large/2 story/4 bedrooms.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 12)
			{
				Houses[id][ExitX] = 260.834625;
				Houses[id][ExitY] = 1284.303344;
				Houses[id][ExitZ] = 1080.299927;
				Houses[id][ExitInterior] = 4;
				Houses[id][ExitAngle] = 357.011657;
				format(string, sizeof string, "House ID: %d - Description: Small/1 story/1 bedroom.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 13)
			{
				Houses[id][ExitX] = 222.189910;
				Houses[id][ExitY] = 1140.205078;
				Houses[id][ExitZ] = 1082.679932;
				Houses[id][ExitInterior] = 4;
				Houses[id][ExitAngle] = 0.748315;
				format(string, sizeof string, "House ID: %d - Description: Small/1 story/1 bedroom/NO BATHROOM!", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 14)
			{
				Houses[id][ExitX] = 24.124982;
				Houses[id][ExitY] = 1340.169921;
				Houses[id][ExitZ] = 1084.449951;
				Houses[id][ExitInterior] = 10;
				Houses[id][ExitAngle] = 4.195019;
				format(string, sizeof string, "House ID: %d - Description: Medium/2 story/1 bedroom.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 15)
			{
				Houses[id][ExitX] = -260.504791;
				Houses[id][ExitY] = 1456.518676;
				Houses[id][ExitZ] = 1084.449951;
				Houses[id][ExitInterior] = 4;
				Houses[id][ExitAngle] = 87.20574;
				format(string, sizeof string, "House ID: %d - Description: Large/2 story/1 bedroom/NO BATHROOM!", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 16)
			{
				Houses[id][ExitX] = 22.992769;
				Houses[id][ExitY] = 1403.328125;
				Houses[id][ExitZ] = 1084.449951;
				Houses[id][ExitInterior] = 5;
				Houses[id][ExitAngle] = 1.978268;
				format(string, sizeof string, "House ID: %d - Description: Medium/1 story/2 bedrooms/NO BATHROOM or DOORS!", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 17)
			{
				Houses[id][ExitX] = 140.149276;
				Houses[id][ExitY] = 1365.931884;
				Houses[id][ExitZ] = 1083.969971;
				Houses[id][ExitInterior] = 5;
				Houses[id][ExitAngle] = 353.80810;
				format(string, sizeof string, "House ID: %d - Description: Large/2 story/4 bedrooms/NO BATHROOM!", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 18)
			{
				Houses[id][ExitX] = 234.120880;
				Houses[id][ExitY] = 1063.727661;
				Houses[id][ExitZ] = 1084.309937;
				Houses[id][ExitInterior] = 6;
				Houses[id][ExitAngle] = 352.21798;
				format(string, sizeof string, "House ID: %d - Description: Large/2 story/3 bedrooms.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 19)
			{
				Houses[id][ExitX] = -68.594032;
				Houses[id][ExitY] = 1351.203613;
				Houses[id][ExitZ] = 1080.279907;
				Houses[id][ExitInterior] = 6;
				Houses[id][ExitAngle] = 0.051390;
				format(string, sizeof string, "House ID: %d - Description: Small/1 story/NO BEDROOM!", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 20)
			{
				Houses[id][ExitX] = -283.441253;
				Houses[id][ExitY] = 1470.989013;
				Houses[id][ExitZ] = 1084.449951;
				Houses[id][ExitInterior] = 15;
				Houses[id][ExitAngle] = 87.7855;
				format(string, sizeof string, "House ID: %d - Description: 1 bedroom/living room/kitchen/NO BATHROOM", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 21)
			{
				Houses[id][ExitX] = -42.387855;
				Houses[id][ExitY] = 1405.472412;
				Houses[id][ExitZ] = 1084.449951;
				Houses[id][ExitInterior] = 8;
				Houses[id][ExitAngle] = 0.678046;
				format(string, sizeof string, "House ID: %d - Description: Small/1 story/NO BEDROOM!", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 22)
			{
				Houses[id][ExitX] = 83.223770;
				Houses[id][ExitY] = 1322.293945;
				Houses[id][ExitZ] = 1083.889893;
				Houses[id][ExitInterior] = 9;
				Houses[id][ExitAngle] = 354.724609;
				format(string, sizeof string, "House ID: %d - Description: Medium/2 story/2 bedrooms", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 23)
			{
				Houses[id][ExitX] = 260.684356;
				Houses[id][ExitY] = 1237.257202;
				Houses[id][ExitZ] = 1084.259888;
				Houses[id][ExitInterior] = 9;
				Houses[id][ExitAngle] = 357.23129;
				format(string, sizeof string, "House ID: %d - Description: Small/1 story/1 bedroom", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 24)
			{
				Houses[id][ExitX] = 243.723510;
				Houses[id][ExitY] = 305.090698;
				Houses[id][ExitZ] = 999.231995;
				Houses[id][ExitInterior] = 1;
				Houses[id][ExitAngle] = 268.337463;
				format(string, sizeof string, "House ID: %d - Description: Denises Bedroom", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 25)
			{
				Houses[id][ExitX] = 266.500610;
				Houses[id][ExitY] = 304.928924;
				Houses[id][ExitZ] = 999.325989;
				Houses[id][ExitInterior] = 2;
				Houses[id][ExitAngle] = 273.640808;
				format(string, sizeof string, "House ID: %d - Description: Katies Bedroom", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 27)
			{
				Houses[id][ExitX] = 302.181000;
				Houses[id][ExitY] = 300.722992;
				Houses[id][ExitZ] = 999.231995;
				Houses[id][ExitInterior] = 4;
				Houses[id][ExitAngle] = 0;
				format(string, sizeof string, "House ID: %d - Description: Michelles Bedroom.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 28)
			{
				Houses[id][ExitX] = 322.197998;
				Houses[id][ExitY] = 302.497986;
				Houses[id][ExitZ] = 999.231995;
				Houses[id][ExitInterior] = 5;
				Houses[id][ExitAngle] = 0;
				format(string, sizeof string, "House ID: %d - Description: Male wiezienie/posterunek !!!.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 29)
			{
				Houses[id][ExitX] = 343.722045;
				Houses[id][ExitY] = 304.778656;
				Houses[id][ExitZ] = 999.155700;
				Houses[id][ExitInterior] = 6;
				Houses[id][ExitAngle] = 271.980529;
				format(string, sizeof string, "House ID: %d - Description: Pokoj POKUS !!!", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 30)
			{
				Houses[id][ExitX] = 2495.955810;
				Houses[id][ExitY] = -1692.085205;
				Houses[id][ExitZ] = 1014.750000;
				Houses[id][ExitInterior] = 3;
				Houses[id][ExitAngle] = 180.486;
				format(string, sizeof string, "House ID: %d - Description: CJs Moms House.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 31)
			{
				Houses[id][ExitX] = 1260.652709;
				Houses[id][ExitY] = -785.114318;
				Houses[id][ExitZ] = 1091.959961;
				Houses[id][ExitInterior] = 5;
				Houses[id][ExitAngle] = 267.3974;
				format(string, sizeof string, "House ID: %d - Description: Madd Doggs Mansion (West door).", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 32)
			{
				Houses[id][ExitX] = 2468.834960;
				Houses[id][ExitY] = -1698.243286;
				Houses[id][ExitZ] = 1013.509949;
				Houses[id][ExitInterior] = 2;
				Houses[id][ExitAngle] = 90.9890;
				format(string, sizeof string, "House ID: %d - Description: Ryders house.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 33)
			{
				Houses[id][ExitX] = 2526.459961;
				Houses[id][ExitY] = -1679.089966;
				Houses[id][ExitZ] = 1015.500000;
				Houses[id][ExitInterior] = 1;
				Houses[id][ExitAngle] = 0;
				format(string, sizeof string, "House ID: %d - Description: Sweets House SPIERDOLONY INT .", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 34)
			{
				Houses[id][ExitX] = 2541.551757;
				Houses[id][ExitY] = -1303.960449;
				Houses[id][ExitZ] = 1025.069946;
				Houses[id][ExitInterior] = 2;
				Houses[id][ExitAngle] = 263.277;
				format(string, sizeof string, "House ID: %d - Description: Big Smokes Crack Factory (Ground Floor).", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 35)
			{
				Houses[id][ExitX] = 744.426879;
				Houses[id][ExitY] = 1436.35253;
				Houses[id][ExitZ] = 1102.739990;
				Houses[id][ExitInterior] = 6;
				Houses[id][ExitAngle] = 356.62817;
				format(string, sizeof string, "House ID: %d - Description: Fanny Batters Whore House.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 36)
			{
				Houses[id][ExitX] = 964.106995;
				Houses[id][ExitY] = -53.205498;
				Houses[id][ExitZ] = 1001.179993;
				Houses[id][ExitInterior] = 3;
				Houses[id][ExitAngle] = 0;
				format(string, sizeof string, "House ID: %d - Description: Tiger Skin Rug Brothel ZWALONY.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 37)
			{
				Houses[id][ExitX] = 2352.923095;
				Houses[id][ExitY] = -1180.498291;
				Houses[id][ExitZ] = 1028.000000;
				Houses[id][ExitInterior] = 5;
				Houses[id][ExitAngle] = 91.6158;
				format(string, sizeof string, "House ID: %d - Description: Burning Desire Gang House.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 38)
			{
				Houses[id][ExitX] = 2807.423095;
				Houses[id][ExitY] = -1174.750610;
				Houses[id][ExitZ] = 1025.579956;
				Houses[id][ExitInterior] = 8;
				Houses[id][ExitAngle] = 359.494;
				format(string, sizeof string, "House ID: %d - Description: Colonel Furhberger's House.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 39)
			{
				Houses[id][ExitX] = 318.818206;
				Houses[id][ExitY] = 1114.492187;
				Houses[id][ExitZ] = 1083.979980;
				Houses[id][ExitInterior] = 5;
				Houses[id][ExitAngle] = 5.424973;
				format(string, sizeof string, "House ID: %d - Description: Crack Den.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 40)
			{
				Houses[id][ExitX] = 2324.260253;
				Houses[id][ExitY] = -1149.536865;
				Houses[id][ExitZ] = 1050.719971;
				Houses[id][ExitInterior] = 12;
				Houses[id][ExitAngle] = 358.19;
				format(string, sizeof string, "House ID: %d - Description: Unused Safe House.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 41)
			{
				Houses[id][ExitX] = 447.118774;
				Houses[id][ExitY] = 506.322723;
				Houses[id][ExitZ] = 1001.419983;
				Houses[id][ExitInterior] = 12;
				Houses[id][ExitAngle] = 0.991497;
				format(string, sizeof string, "House ID: %d - Description: Budget Inn Motel Room.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 42)
			{
				Houses[id][ExitX] = 2214.388671;
				Houses[id][ExitY] = -1150.523071;
				Houses[id][ExitZ] = 1025.799927;
				Houses[id][ExitInterior] = 15;
				Houses[id][ExitAngle] = 269.4;
				format(string, sizeof string, "House ID: %d - Description: Jefferson Motel. (REALLY EXPENSIVE)", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 43)
			{
				Houses[id][ExitX] = -1924.921875;
				Houses[id][ExitY] = 1198.463623;
				Houses[id][ExitZ] = 56.548995;
				Houses[id][ExitInterior] = 0;
				Houses[id][ExitAngle] = 0;
				format(string, sizeof string, "House ID: %d - Slums", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 44)
			{
				Houses[id][ExitX] = 14.2741;
				Houses[id][ExitY] = 1539.3162;
				Houses[id][ExitZ] = 12.7500;
				Houses[id][ExitInterior] = 0;
				Houses[id][ExitAngle] = 0;
				format(string, sizeof string, "House ID: %d - Nowy dodany int", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 45)
			{
				Houses[id][ExitX] = 1550.7493;
				Houses[id][ExitY] = -1364.8269;
				Houses[id][ExitZ] = 491;
				Houses[id][ExitInterior] = 0;
				Houses[id][ExitAngle] = 0;
				format(string, sizeof string, "House ID: %d - Nowy dodany int 2", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 46)
			{
				Houses[id][ExitX] = 2766.967773;
				Houses[id][ExitY] = -1466.013916;
				Houses[id][ExitZ] = 66.528175;
				Houses[id][ExitInterior] = 0;
				Houses[id][ExitAngle] = 0;
				format(string, sizeof string, "House ID: %d - Nowy dodany int 3", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 47)
			{
				Houses[id][ExitX] = -215.47416687012;
				Houses[id][ExitY] = -169.38523864746;
				Houses[id][ExitZ] = 1598.7647705078;
				Houses[id][ExitInterior] = 0;
				Houses[id][ExitAngle] = 0;
				format(string, sizeof string, "House ID: %d - Nowy dodany int 4", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 48)
			{
				Houses[id][ExitX] = -2666.9397;
				Houses[id][ExitY] = 632.9147;
				Houses[id][ExitZ] = 66.1670;
				Houses[id][ExitInterior] = 0;
				Houses[id][ExitAngle] = 0;
				format(string, sizeof string, "House ID: %d - Nowy dodany int 5", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 49)
			{
				Houses[id][ExitX] = 4534.98;
				Houses[id][ExitY] = -1793.04;
				Houses[id][ExitZ] = 6.17;
				Houses[id][ExitInterior] = 0;
				Houses[id][ExitAngle] = 0;
				format(string, sizeof string, "House ID: %d - Nowy dodany int 6", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			SaveHouseData(id, "ExitX");
			SaveHouseData(id, "ExitY");
			SaveHouseData(id, "ExitZ");
			SaveHouseData(id, "ExitInterior");
			SaveHouseData(id, "ExitAngle");
			SaveHouseData(id, "HousePrice");
			printf("[WARNING:] /ahouseint used by %s, house id: %d, int: %d", gPlayerData[playerid][pName], id, id2);
			return 1;
		}
		if(strcmp(cmd, "/abuildingint", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_WHITE, "[INFO:] /abuildingint [buildingid] [id (1-29)]");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INTS:] 1: Sherman Dam - 2: Planning Department - 3: Ganton Gym - 4: Cobra Gym - 5: Below The Belt Gym");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INTS:] 6: RC Battlefield - 7-9: Police Departments - 10-12: Schools - 13: 8 Track Stadium");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INTS:] 14: Bloodbowl Stadium - 15: Dirtbike Stadium - 16: Kickstart Stadium - 17: Vice Stadium");
				return 1;
			}
			new id;
			id = strval(tmp);
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_WHITE, "[INFO:] /abuildingint [buildingid] [id (1-29)]");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INTS:] 1: Sherman Dam - 2: Planning Department - 3: Ganton Gym - 4: Cobra Gym - 5: Below The Belt Gym");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INTS:] 6: RC Battlefield - 7-9: Police Departments - 10-12: Schools - 13: 8 Track Stadium");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INTS:] 14: Bloodbowl Stadium - 15: Dirtbike Stadium - 16: Kickstart Stadium - 17: Vice Stadium");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INTS:] 19: Halo Taxi - 20: Szpital - 21: Biuro - 22: Bank - 23: Szko³a");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INTS:] 24: Straz Pozarna - 25: Town Library - 26: Court Hall - 27: Realistic Office - 28: Strzelnica - 29: Bank");
				return 1;
			}
			new id2;
			id2 = strval(tmp);
			if(id2 < 1 || id2 > 30) { SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Interior ID's 1-25."); return 1; }
			if(id2 == 1)
			{
				Building[id][ExitX] = -959.873962;
				Building[id][ExitY] = 1952.000000;
				Building[id][ExitZ] = 9.044310;
				Building[id][ExitInterior] = 17;
				format(string, sizeof string, "Building ID: %d - Description: Sherman Dam.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 2)
			{
				Building[id][ExitX] = 388.871979;
				Building[id][ExitY] = 173.804993;
				Building[id][ExitZ] = 1008.389954;
				Building[id][ExitInterior] = 3;
				format(string, sizeof string, "Building ID: %d - Description: Planning Department.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 3)
			{
				Building[id][ExitX] = 772.112000;
				Building[id][ExitY] = -3.898650;
				Building[id][ExitZ] = 1000.687988;
				Building[id][ExitInterior] = 5;
				format(string, sizeof string, "Building ID: %d - Description: Ganton Gym.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 4)
			{
				Building[id][ExitX] = 774.213989;
				Building[id][ExitY] = -48.924297;
				Building[id][ExitZ] = 1000.687988;
				Building[id][ExitInterior] = 6;
				format(string, sizeof string, "Building ID: %d - Description: Cobra Gym.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 5)
			{
				Building[id][ExitX] = 773.579956;
				Building[id][ExitY] = -77.096695;
				Building[id][ExitZ] = 1000.687988;
				Building[id][ExitInterior] = 7;
				format(string, sizeof string, "Building ID: %d - Description: Below The Belt Gym.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 6)
			{
				Building[id][ExitX] = -972.4957;
				Building[id][ExitY] = 1060.983;
				Building[id][ExitZ] = 1345.669;
				Building[id][ExitInterior] = 10;
				format(string, sizeof string, "Building ID: %d - Description: RC Battlefield.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 7)
			{
				Building[id][ExitX] = 246.783997;
				Building[id][ExitY] = 63.900200;
				Building[id][ExitZ] = 1003.639954;
				Building[id][ExitInterior] = 6;
				format(string, sizeof string, "Building ID: %d - Description: LSPD.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 8)
			{
				Building[id][ExitX] = 246.375992;
				Building[id][ExitY] = 109.245995;
				Building[id][ExitZ] = 1003.279968;
				Building[id][ExitInterior] = 10;
				format(string, sizeof string, "Building ID: %d - Description: SFPD.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 9)
			{
				Building[id][ExitX] = 238.661987;
				Building[id][ExitY] = 141.051987;
				Building[id][ExitZ] = 1003.049988;
				Building[id][ExitInterior] = 3;
				format(string, sizeof string, "Building ID: %d - Description: LVPD.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 10)
			{
				Building[id][ExitX] = 1494.429932;
				Building[id][ExitY] = 1305.629883;
				Building[id][ExitZ] = 1093.289917;
				Building[id][ExitInterior] = 3;
				format(string, sizeof string, "Building ID: %d - Description: Bike School.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 11)
			{
				Building[id][ExitX] = -2029.719971;
				Building[id][ExitY] = -115.067993;
				Building[id][ExitZ] = 1035.169922;
				Building[id][ExitInterior] = 3;
				format(string, sizeof string, "Building ID: %d - Description: Driving School.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 12)
			{
				Building[id][ExitX] = 420.484985;
				Building[id][ExitY] = 2535.589844;
				Building[id][ExitZ] = 10.020289;
				Building[id][ExitInterior] = 10;
				format(string, sizeof string, "Building ID: %d - Description: School (None).", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 13)
			{
				Building[id][ExitX] = -1397.782470;
				Building[id][ExitY] = -203.723114;
				Building[id][ExitZ] = 1051.346801;
				Building[id][ExitInterior] = 7;
				format(string, sizeof string, "Building ID: %d - Description: 8 Track Stadium.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 14)
			{
				Building[id][ExitX] = -1398.103515;
				Building[id][ExitY] = 933.445434;
				Building[id][ExitZ] = 1041.531250;
				Building[id][ExitInterior] = 15;
				format(string, sizeof string, "Building ID: %d - Description: Bloodbowl Stadium.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 15)
			{
				Building[id][ExitX] = -1428.809448;
				Building[id][ExitY] = -663.595886;
				Building[id][ExitZ] = 1060.219848;
				Building[id][ExitInterior] = 4;
				format(string, sizeof string, "Building ID: %d - Description: Dirtbike Stadium.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 16)
			{
				Building[id][ExitX] = -1486.861816;
				Building[id][ExitY] = 1642.145996;
				Building[id][ExitZ] = 1060.671875;
				Building[id][ExitInterior] = 14;
				format(string, sizeof string, "Building ID: %d - Description: Kickstart Stadium.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 17)
			{
				Building[id][ExitX] = -1401.830000;
				Building[id][ExitY] = 107.051300;
				Building[id][ExitZ] = 1032.273000;
				Building[id][ExitInterior] = 1;
				format(string, sizeof string, "Building ID: %d - Description: Vice Stadium (Only center is solid).", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 18)
			{
				Building[id][ExitX] = 1935.4089;
				Building[id][ExitY] = -2110.2100;
				Building[id][ExitZ] = -19.3109;
				Building[id][ExitInterior] = 0;
				format(string, sizeof string, "Building ID: %d - Description: Vice Stadium (Only center is solid).", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 19)
			{
				Building[id][ExitX] = 371.8502;
				Building[id][ExitY] = 182.0368;
				Building[id][ExitZ] = 1014.1875;
				Building[id][ExitInterior] = 3;
				format(string, sizeof string, "Building ID: %d - Description: Halo Taxi.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 20)
			{
				Building[id][ExitX] = -2676.3142089844;
				Building[id][ExitY] = 665.36920166016;
				Building[id][ExitZ] = 10.298047065;
				Building[id][ExitInterior] = 0;
				format(string, sizeof string, "Building ID: %d - Description: Szpital.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 21)
			{
				Building[id][ExitX] = 1831.6578369141;
				Building[id][ExitY] = -1292.5003662109;
				Building[id][ExitZ] = 109.20129394531;
				Building[id][ExitInterior] = 0;
				format(string, sizeof string, "Building ID: %d - Description: Biuro.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 22)
			{
				Building[id][ExitX] = -467.1987;
				Building[id][ExitY] = -196.4525;
				Building[id][ExitZ] = 986.3784;
				Building[id][ExitInterior] = 0;
				format(string, sizeof string, "Building ID: %d - Description: Bank.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 23)
			{
				Building[id][ExitX] = 1261;
				Building[id][ExitY] = -785;
				Building[id][ExitZ] = 1093;
				Building[id][ExitInterior] = 0;
				format(string, sizeof string, "Building ID: %d - Description: Szkola.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 24)
			{
				Building[id][ExitX] = 491.3903;
				Building[id][ExitY] = 1398.7488;
				Building[id][ExitZ] = 1081.2582;
				Building[id][ExitInterior] = 0;
				format(string, sizeof string, "Building ID: %d - Description: Straz pozarna.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 25)
			{
				Building[id][ExitX] = 223.085769653325;
				Building[id][ExitY] = 1287.5047607422;
				Building[id][ExitZ] = 1082.1408691406;
				Building[id][ExitInterior] = 0;
				format(string, sizeof string, "Building ID: %d - Description: Town Library.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 26)
			{
				Building[id][ExitX] = 1207.8029785156;
				Building[id][ExitY] = -903.25885009766;
				Building[id][ExitZ] = 1094.6083984375;
				Building[id][ExitInterior] = 0;
				format(string, sizeof string, "Building ID: %d - Description: Court hall.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 27)
			{
				Building[id][ExitX] = -2652.3493652344;
				Building[id][ExitY] = 375.43951416016;
				Building[id][ExitZ] = -0.520361;
				Building[id][ExitInterior] = 0;
				format(string, sizeof string, "Building ID: %d - Description: Realistic Office.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 28)
			{
				Building[id][ExitX] = 304.572479;
				Building[id][ExitY] = -142.094192;
				Building[id][ExitZ] = 1004.062500;
				Building[id][ExitInterior] = 7;
				format(string, sizeof string, "Building ID: %d - Description: Ammunation Shooting Range.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
				else if(id2 == 29)
			{
				Building[id][ExitX] = 325.2;
				Building[id][ExitY] = 113.67;
				Building[id][ExitZ] = 1008;
				Building[id][ExitInterior] = 9;
				format(string, sizeof string, "Building ID: %d - Description: Bank.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			SaveBData(id, "ExitX");
			SaveBData(id, "ExitY");
			SaveBData(id, "ExitZ");
			SaveBData(id, "ExitInterior");
			return 1;
		}
		if(strcmp(cmd, "/wnetrzebudynku", true) == 0)
		{
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_WHITE, "[INFO:] /wnetrzebudynku [buildingid] [id (1-17)]");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INTS:] 1: Sherman Dam - 2: Planning Department - 3: Ganton Gym - 4: Cobra Gym - 5: Below The Belt Gym");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INTS:] 6: RC Battlefield - 7-9: Police Departments - 10-12: Schools - 13: 8 Track Stadium");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INTS:] 14: Bloodbowl Stadium - 15: Dirtbike Stadium - 16: Kickstart Stadium - 17: Vice Stadium");
				return 1;
			}
			if (gPlayerData[playerid][pFaction] == 9)
			{
					new id;
					id = strval(tmp);
					tmp = strtok(cmdtext, idx);
					if(!strlen(tmp))
					{
						SendClientMessage(playerid, COLOR_WHITE, "[INFO:] /wnetrzebudynku [buildingid] [id (1-29)]");
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INTS:] 1: Sherman Dam - 2: Planning Department - 3: Ganton Gym - 4: Cobra Gym - 5: Below The Belt Gym");
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INTS:] 6: RC Battlefield - 7-9: Police Departments - 10-12: Schools - 13: 8 Track Stadium");
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INTS:] 14: Bloodbowl Stadium - 15: Dirtbike Stadium - 16: Kickstart Stadium - 17: Vice Stadium");
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INTS:] 19: Halo Taxi - 20: Szpital - 21: Biuro - 22: Bank - 23: Szko³a");
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INTS:] 24: Straz Pozarna - 25: Town Library - 26: Court Hall - 27: Realistic Office - 28: Strzelnica -29:Bank");
						return 1;
					}
					new id2;
					id2 = strval(tmp);
					if(id2 < 1 || id2 > 30) { SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Wnetrze ID's 1-25."); return 1; }

					format(string, sizeof(string), "[GOVERNMENT:] Business id %d int set to %d by %s", id, id2,gPlayerData[playerid][pName]);
					GovermentLog(string);
					if(id2 == 1)
					{
						Building[id][ExitX] = -959.873962;
						Building[id][ExitY] = 1952.000000;
						Building[id][ExitZ] = 9.044310;
						Building[id][ExitInterior] = 17;
						format(string, sizeof string, "Building ID: %d - Description: Sherman Dam.", id);
						SendClientMessage(playerid, COLOR_ADMINCMD,string);
					}
					else if(id2 == 2)
					{
						Building[id][ExitX] = 388.871979;
						Building[id][ExitY] = 173.804993;
						Building[id][ExitZ] = 1008.389954;
						Building[id][ExitInterior] = 3;
						format(string, sizeof string, "Building ID: %d - Description: Planning Department.", id);
						SendClientMessage(playerid, COLOR_ADMINCMD,string);
					}
					else if(id2 == 3)
					{
						Building[id][ExitX] = 772.112000;
						Building[id][ExitY] = -3.898650;
						Building[id][ExitZ] = 1000.687988;
						Building[id][ExitInterior] = 5;
						format(string, sizeof string, "Building ID: %d - Description: Ganton Gym.", id);
						SendClientMessage(playerid, COLOR_ADMINCMD,string);
					}
					else if(id2 == 4)
					{
						Building[id][ExitX] = 774.213989;
						Building[id][ExitY] = -48.924297;
						Building[id][ExitZ] = 1000.687988;
						Building[id][ExitInterior] = 6;
						format(string, sizeof string, "Building ID: %d - Description: Cobra Gym.", id);
						SendClientMessage(playerid, COLOR_ADMINCMD,string);
					}
					else if(id2 == 5)
					{
						Building[id][ExitX] = 773.579956;
						Building[id][ExitY] = -77.096695;
						Building[id][ExitZ] = 1000.687988;
						Building[id][ExitInterior] = 7;
						format(string, sizeof string, "Building ID: %d - Description: Below The Belt Gym.", id);
						SendClientMessage(playerid, COLOR_ADMINCMD,string);
					}
					else if(id2 == 6)
					{
						Building[id][ExitX] = -972.4957;
						Building[id][ExitY] = 1060.983;
						Building[id][ExitZ] = 1345.669;
						Building[id][ExitInterior] = 10;
						format(string, sizeof string, "Building ID: %d - Description: RC Battlefield.", id);
						SendClientMessage(playerid, COLOR_ADMINCMD,string);
					}
					else if(id2 == 7)
					{
						Building[id][ExitX] = 246.783997;
						Building[id][ExitY] = 63.900200;
						Building[id][ExitZ] = 1003.639954;
						Building[id][ExitInterior] = 6;
						format(string, sizeof string, "Building ID: %d - Description: LSPD.", id);
						SendClientMessage(playerid, COLOR_ADMINCMD,string);
					}
					else if(id2 == 8)
					{
						Building[id][ExitX] = 246.375992;
						Building[id][ExitY] = 109.245995;
						Building[id][ExitZ] = 1003.279968;
						Building[id][ExitInterior] = 10;
						format(string, sizeof string, "Building ID: %d - Description: SFPD.", id);
						SendClientMessage(playerid, COLOR_ADMINCMD,string);
					}
					else if(id2 == 9)
					{
						Building[id][ExitX] = 238.661987;
						Building[id][ExitY] = 141.051987;
						Building[id][ExitZ] = 1003.049988;
						Building[id][ExitInterior] = 3;
						format(string, sizeof string, "Building ID: %d - Description: LVPD.", id);
						SendClientMessage(playerid, COLOR_ADMINCMD,string);
					}
					else if(id2 == 10)
					{
						Building[id][ExitX] = 1494.429932;
						Building[id][ExitY] = 1305.629883;
						Building[id][ExitZ] = 1093.289917;
						Building[id][ExitInterior] = 3;
						format(string, sizeof string, "Building ID: %d - Description: Bike School.", id);
						SendClientMessage(playerid, COLOR_ADMINCMD,string);
					}
					else if(id2 == 11)
					{
						Building[id][ExitX] = -2029.719971;
						Building[id][ExitY] = -115.067993;
						Building[id][ExitZ] = 1035.169922;
						Building[id][ExitInterior] = 3;
						format(string, sizeof string, "Building ID: %d - Description: Driving School.", id);
						SendClientMessage(playerid, COLOR_ADMINCMD,string);
					}
					else if(id2 == 12)
					{
						Building[id][ExitX] = 420.484985;
						Building[id][ExitY] = 2535.589844;
						Building[id][ExitZ] = 10.020289;
						Building[id][ExitInterior] = 10;
						format(string, sizeof string, "Building ID: %d - Description: School (None).", id);
						SendClientMessage(playerid, COLOR_ADMINCMD,string);
					}
					else if(id2 == 13)
					{
						Building[id][ExitX] = -1397.782470;
						Building[id][ExitY] = -203.723114;
						Building[id][ExitZ] = 1051.346801;
						Building[id][ExitInterior] = 7;
						format(string, sizeof string, "Building ID: %d - Description: 8 Track Stadium.", id);
						SendClientMessage(playerid, COLOR_ADMINCMD,string);
					}
					else if(id2 == 14)
					{
						Building[id][ExitX] = -1398.103515;
						Building[id][ExitY] = 933.445434;
						Building[id][ExitZ] = 1041.531250;
						Building[id][ExitInterior] = 15;
						format(string, sizeof string, "Building ID: %d - Description: Bloodbowl Stadium.", id);
						SendClientMessage(playerid, COLOR_ADMINCMD,string);
					}
					else if(id2 == 15)
					{
						Building[id][ExitX] = -1428.809448;
						Building[id][ExitY] = -663.595886;
						Building[id][ExitZ] = 1060.219848;
						Building[id][ExitInterior] = 4;
						format(string, sizeof string, "Building ID: %d - Description: Dirtbike Stadium.", id);
						SendClientMessage(playerid, COLOR_ADMINCMD,string);
					}
					else if(id2 == 16)
					{
						Building[id][ExitX] = -1486.861816;
						Building[id][ExitY] = 1642.145996;
						Building[id][ExitZ] = 1060.671875;
						Building[id][ExitInterior] = 14;
						format(string, sizeof string, "Building ID: %d - Description: Kickstart Stadium.", id);
						SendClientMessage(playerid, COLOR_ADMINCMD,string);
					}
					else if(id2 == 17)
					{
						Building[id][ExitX] = -1401.830000;
						Building[id][ExitY] = 107.051300;
						Building[id][ExitZ] = 1032.273000;
						Building[id][ExitInterior] = 1;
						format(string, sizeof string, "Building ID: %d - Description: Vice Stadium (Only center is solid).", id);
						SendClientMessage(playerid, COLOR_ADMINCMD,string);
					}
					else if(id2 == 18)
					{
						Building[id][ExitX] = 1935.4089;
						Building[id][ExitY] = -2110.2100;
						Building[id][ExitZ] = -19.3109;
						Building[id][ExitInterior] = 0;
						format(string, sizeof string, "Building ID: %d - Description: Vice Stadium (Only center is solid).", id);
						SendClientMessage(playerid, COLOR_ADMINCMD,string);
					}
					else if(id2 == 19)
					{
						Building[id][ExitX] = 371.8502;
						Building[id][ExitY] = 182.0368;
						Building[id][ExitZ] = 1014.1875;
						Building[id][ExitInterior] = 3;
						format(string, sizeof string, "Building ID: %d - Description: Halo Taxi.", id);
						SendClientMessage(playerid, COLOR_ADMINCMD,string);
					}
					else if(id2 == 20)
					{
						Building[id][ExitX] = -2676.3142089844;
						Building[id][ExitY] = 665.36920166016;
						Building[id][ExitZ] = 10.298047065;
						Building[id][ExitInterior] = 0;
						format(string, sizeof string, "Building ID: %d - Description: Szpital.", id);
						SendClientMessage(playerid, COLOR_ADMINCMD,string);
					}
					else if(id2 == 21)
					{
						Building[id][ExitX] = 1831.6578369141;
						Building[id][ExitY] = -1292.5003662109;
						Building[id][ExitZ] = 109.20129394531;
						Building[id][ExitInterior] = 0;
						format(string, sizeof string, "Building ID: %d - Description: Biuro.", id);
						SendClientMessage(playerid, COLOR_ADMINCMD,string);
					}
					else if(id2 == 22)
					{
						Building[id][ExitX] = -467.1987;
						Building[id][ExitY] = -196.4525;
						Building[id][ExitZ] = 986.3784;
						Building[id][ExitInterior] = 0;
						format(string, sizeof string, "Building ID: %d - Description: Bank.", id);
						SendClientMessage(playerid, COLOR_ADMINCMD,string);
					}
					else if(id2 == 23)
					{
						Building[id][ExitX] = 1261;
						Building[id][ExitY] = -785;
						Building[id][ExitZ] = 1093;
						Building[id][ExitInterior] = 0;
						format(string, sizeof string, "Building ID: %d - Description: Szkola.", id);
						SendClientMessage(playerid, COLOR_ADMINCMD,string);
					}
					else if(id2 == 24)
					{
						Building[id][ExitX] = 491.3903;
						Building[id][ExitY] = 1398.7488;
						Building[id][ExitZ] = 1081.2582;
						Building[id][ExitInterior] = 0;
						format(string, sizeof string, "Building ID: %d - Description: Straz pozarna.", id);
						SendClientMessage(playerid, COLOR_ADMINCMD,string);
					}
					else if(id2 == 25)
					{
						Building[id][ExitX] = 223.085769653325;
						Building[id][ExitY] = 1287.5047607422;
						Building[id][ExitZ] = 1082.1408691406;
						Building[id][ExitInterior] = 0;
						format(string, sizeof string, "Building ID: %d - Description: Town Library.", id);
						SendClientMessage(playerid, COLOR_ADMINCMD,string);
					}
					else if(id2 == 26)
					{
						Building[id][ExitX] = 1207.8029785156;
						Building[id][ExitY] = -903.25885009766;
						Building[id][ExitZ] = 1094.6083984375;
						Building[id][ExitInterior] = 0;
						format(string, sizeof string, "Building ID: %d - Description: Court hall.", id);
						SendClientMessage(playerid, COLOR_ADMINCMD,string);
					}
					else if(id2 == 27)
					{
						Building[id][ExitX] = -2652.3493652344;
						Building[id][ExitY] = 375.43951416016;
						Building[id][ExitZ] = -0.520361;
						Building[id][ExitInterior] = 0;
						format(string, sizeof string, "Building ID: %d - Description: Realistic Office.", id);
						SendClientMessage(playerid, COLOR_ADMINCMD,string);
					}
					else if(id2 == 28)
					{
						Building[id][ExitX] = 304.572479;
						Building[id][ExitY] = -142.094192;
						Building[id][ExitZ] = 1004.062500;
						Building[id][ExitInterior] = 7;
						format(string, sizeof string, "Building ID: %d - Description: Ammunation Shooting Range.", id);
						SendClientMessage(playerid, COLOR_ADMINCMD,string);
					}
					else if(id2 == 28)
					{
						Building[id][ExitX] = 325.2;
						Building[id][ExitY] = 113.67;
						Building[id][ExitZ] = 1008;
						Building[id][ExitInterior] = 9;
						format(string, sizeof string, "Building ID: %d - Description: Bank.", id);
						SendClientMessage(playerid, COLOR_ADMINCMD,string);
					}
					SaveBData(id, "ExitX");
					SaveBData(id, "ExitY");
					SaveBData(id, "ExitZ");
					SaveBData(id, "ExitInterior");
					
					format(string, sizeof(string), "[GOVERNMENT:] Building interior changed by: %s, interior id: %d", gPlayerData[playerid][pName], id2);
					GovermentLog(string);
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "nie jesteœ urzednikiem.");
			}
			return 1;
		}
		if(strcmp(cmd, "/abizint", true) == 0)
		{
			if (gPlayerData[playerid][pAdmin] < 4)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /ahouseint [houseid] [id (1-50)]");
				return 1;
			}
			new id;
			id = strval(tmp);
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_WHITE, "[INFO:] /abizint [bizid] [id (1-41)]");
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
			Businesses[id][BInterior] = id2;
			SaveBizData(id, "Interior");
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
			SaveBizData(id, "BizPrice");
			return 1;
		}
		if(strcmp(cmd, "/abizname", true) == 0)
		{
			if (gPlayerData[playerid][pAdmin] < 1)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /abizname [bizid] [name]");
				return 1;
			}
			new id = strval(tmp);
			new length = strlen(cmdtext);
			while ((idx < length) && (cmdtext[idx] <= ' '))
			{
				idx++;
			}
			new offset = idx;
			new result[128];
			while ((idx < length) && ((idx - offset) < (sizeof(result) - 1)))
			{
				result[idx - offset] = cmdtext[idx];
				idx++;
			}
			result[idx - offset] = EOS;
			if(!strlen(result))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /abizname [bizid] [name]");
				return 1;
			}
			if(strfind( result , "|" , true ) == -1)
			{
				strmid(Businesses[id][BusinessName], (result), 0, strlen((result)), 128);

				new businesstype[128];
				if(Businesses[id][BizType] != 0)
				{
					if(Businesses[id][BizType] == 1) { businesstype = "Restauracja"; }
					else if(Businesses[id][BizType] == 2) { businesstype = "Siec komorkowa"; }
					else if(Businesses[id][BizType] == 3) { businesstype = "Sklep 24/7"; }
					else if(Businesses[id][BizType] == 4) { businesstype = "Sklep z bronia"; }
					else if(Businesses[id][BizType] == 5) { businesstype = "Studio reklamowe"; }
					else if(Businesses[id][BizType] == 6) { businesstype = "Sklep z ubraniami"; }
					else if(Businesses[id][BizType] == 7) { businesstype = "Bar/Club"; }
					else if(Businesses[id][BizType] == 8) { businesstype = "Studio nagraniowe"; }
					else if(Businesses[id][BizType] == 9) { businesstype = "Studio"; }
					else if(Businesses[id][BizType] == 10) { businesstype = "Salon samochodowy"; }
					else if(Businesses[id][BizType] == 11) { businesstype = "Stacja paliw"; }
				}
				else { businesstype = "Nie ustawione"; }

				if(Businesses[id][Owned] == 0)
				{
					format(string, sizeof(string), "Numer Budynku: %d, Nazwa biznesu: %s, Typ biznesu: %s",id,Businesses[id][BusinessName],businesstype);
					UpdateDynamic3DTextLabelText(Business3DTextLabelB[id], COLOR_LIGHTBLUE2, string);
				}
				else
				{
					format(string, sizeof(string), "Numer Budynku: %d, Nazwa biznesu: %s, Typ biznesu: %s",id,Businesses[id][BusinessName],businesstype);
					UpdateDynamic3DTextLabelText(Business3DTextLabelA[id], COLOR_LIGHTBLUE2, string);
				}

				format(string, sizeof(string), "[INFO:] You have set Business ID's: %d's name to %s", id,(result));
				SendClientMessage(playerid, COLOR_ADMINCMD, string);
				SaveBizData(id, "BusinessName");
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Invalid Symbol, | is not allowed!");
			}
			return 1;
		}
		if(strcmp(cmd, "/abizsell", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /abizsell [businessid]");
				return 1;
			}
			new id = strval(tmp);
			Businesses[id][Locked] = 1;
			Businesses[id][Owned] = 0;
			strmid(Businesses[id][Owner], "None", 0, strlen("None"), 255);

			Businesses[id][PickupID] = ChangePickupModel(Businesses[id][PickupID], 1272, Businesses[id][EnterX],Businesses[id][EnterY],Businesses[id][EnterZ]);

			/* Clear players business key form given businessid */
			foreach(Player, i)
			{
				if(gPlayerData[i][pBizKey] == id)
				{
					gPlayerData[i][pBizKey] = 255;
					SavePlayerData(i, "BizKey");
				}
			}
			
			/* Clear players business key form given businessid in database */
			format(string, sizeof(string), "UPDATE `samp_users_keys` SET `BizKey` = '255' WHERE `BizKey` = '%d'", id);
			mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
			
			new businesstype[128];
			if(Businesses[id][BizType] != 0)
			{
				if(Businesses[id][BizType] == 1) { businesstype = "Restauracja"; }
				else if(Businesses[id][BizType] == 2) { businesstype = "Siec komorkowa"; }
				else if(Businesses[id][BizType] == 3) { businesstype = "Sklep 24/7"; }
				else if(Businesses[id][BizType] == 4) { businesstype = "Sklep z bronia"; }
				else if(Businesses[id][BizType] == 5) { businesstype = "Studio reklamowe"; }
				else if(Businesses[id][BizType] == 6) { businesstype = "Sklep z ubraniami"; }
				else if(Businesses[id][BizType] == 7) { businesstype = "Bar/Club"; }
				else if(Businesses[id][BizType] == 8) { businesstype = "Studio nagraniowe"; }
				else if(Businesses[id][BizType] == 9) { businesstype = "Studio"; }
				else if(Businesses[id][BizType] == 10) { businesstype = "Salon samochodowy"; }
				else if(Businesses[id][BizType] == 11) { businesstype = "Stacja paliw"; }
			}
			else { businesstype = "Nie ustawione"; }

			format(string, sizeof(string), "Ten biznes jest na sprzeda¿!");
			UpdateDynamic3DTextLabelText(Business3DTextLabelA[id], COLOR_LIGHTBLUE2, string);

			format(string, sizeof(string), "Nazwa biznesu: %s, Typ biznesu: %s",Businesses[id][BusinessName],businesstype);
			UpdateDynamic3DTextLabelText(Business3DTextLabelB[id], COLOR_LIGHTBLUE2, string);

			format(string, sizeof(string), "Cena: $%d",Businesses[id][BizPrice]);
			UpdateDynamic3DTextLabelText(Business3DTextLabelC[id], COLOR_LIGHTBLUE2, string);

			SaveBizData(id, "Locked");
			SaveBizData(id, "Owned");
			SaveBizData(id, "Owner");
			new form[128];
			format(form, sizeof(form), "[INFO:] You have sold business ID: %d.", id);
			SendClientMessage(playerid, COLOR_ADMINCMD, form);
			return 1;
		}
		if(strcmp(cmd, "/sprzedajbiz", true) == 0)
		{
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /sprzedajbiz [id biznesu]");
				return 1;
			}
			new id = strval(tmp);
			if (gPlayerData[playerid][pFaction] == 9)
			{
				format(string, sizeof(string), "[GOVERNMENT:] Business sold by: %s, biz id: %d, price: %d$, owner: %s", gPlayerData[playerid][pName], id, Businesses[id][BizPrice], Businesses[id][Owner]);
				GovermentLog(string);
				
				ResetBizData(id, 1);
				
				printf("[BUSINESSES:] Business id %d sold by %s", id,GetPlayerNameEx(playerid));
				new businesstype[128];
				if(Businesses[id][BizType] != 0)
				{
					if(Businesses[id][BizType] == 1) { businesstype = "Restauracja"; }
					else if(Businesses[id][BizType] == 2) { businesstype = "Siec komorkowa"; }
					else if(Businesses[id][BizType] == 3) { businesstype = "Sklep 24/7"; }
					else if(Businesses[id][BizType] == 4) { businesstype = "Sklep z bronia"; }
					else if(Businesses[id][BizType] == 5) { businesstype = "Studio reklamowe"; }
					else if(Businesses[id][BizType] == 6) { businesstype = "Sklep z ubraniami"; }
					else if(Businesses[id][BizType] == 7) { businesstype = "Bar/Club"; }
					else if(Businesses[id][BizType] == 8) { businesstype = "Studio nagraniowe"; }
					else if(Businesses[id][BizType] == 9) { businesstype = "Studio"; }
					else if(Businesses[id][BizType] == 10) { businesstype = "Salon samochodowy"; }
					else if(Businesses[id][BizType] == 11) { businesstype = "Stacja paliw"; }
				}
				else { businesstype = "Nie ustawione"; }

				format(string, sizeof(string), "Ten biznes jest na sprzeda¿!");
				UpdateDynamic3DTextLabelText(Business3DTextLabelA[id], COLOR_LIGHTBLUE2, string);

				format(string, sizeof(string), "Nazwa biznesu: %s, Typ biznesu: %s",Businesses[id][BusinessName],businesstype);
				UpdateDynamic3DTextLabelText(Business3DTextLabelB[id], COLOR_LIGHTBLUE2, string);

				format(string, sizeof(string), "Cena: $%d",Businesses[id][BizPrice]);
				UpdateDynamic3DTextLabelText(Business3DTextLabelC[id], COLOR_LIGHTBLUE2, string);

				new form[128];
				format(form, sizeof(form), "[INFO:] Sprzeda³eœ biznes od id: %d.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD, form);				
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ urzednikiem");
			}
			return 1;
		}
		if(strcmp(cmd, "/ahouseprice", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /ahouseprice [houseid] [price]");
				return 1;
			}
			new id;
			id = strval(tmp);
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /ahouseprice [houseid] [price]");
				return 1;
			}
			new id2;
			id2 = strval(tmp);
			Houses[id][HousePrice] = id2;
			if(Houses[id][Owned] == 0)
			{
				format(string, sizeof(string), "Opis: %s, Cena: $%d",Houses[id][Description],Houses[id][HousePrice]);
				UpdateDynamic3DTextLabelText(Houses3DTextLabelC[id], COLOR_LIGHTYELLOW2, string);
			}
			new form[128];
			format(form, sizeof form, "[INFO:] You've set House ID: %d's price to %d.", id,id2);
			SendClientMessage(playerid, COLOR_ADMINCMD,form);
			SaveHouseData(id, "HousePrice");
			return 1;
		}
		if(strcmp(cmd, "/ahousesell", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /ahousesell [houseid]");
				return 1;
			}
			new id = strval(tmp);
			ResetHouseData(id, 1);			

			new houselocation[MAX_ZONE_NAME];
			GetCoords2DZone(Houses[id][EnterX],Houses[id][EnterY], houselocation, MAX_ZONE_NAME);

			format(string, sizeof(string), "Ten dom jest na sprzedaz!");
			UpdateDynamic3DTextLabelText(Houses3DTextLabelA[id], COLOR_LIGHTYELLOW2, string);

			format(string, sizeof(string), "Adres: %d %s",id,houselocation);
			UpdateDynamic3DTextLabelText(Houses3DTextLabelB[id], COLOR_LIGHTYELLOW2, string);

			format(string, sizeof(string), "Opis: %s, Cena: $%d",Houses[id][Description],Houses[id][HousePrice]);
			UpdateDynamic3DTextLabelText(Houses3DTextLabelC[id], COLOR_LIGHTYELLOW2, string);

			new form[128];
			format(form, sizeof(form), "[INFO:] You have sold house ID: %d.", id);
			SendClientMessage(playerid, COLOR_ADMINCMD, form);
			return 1;
		}
		if(strcmp(cmd, "/ustawduzygaraz", true) == 0)
		{
			if( gPlayerData[playerid][pVipGarageBig] <= 0 )
			{
				SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie wykupi³eœ du¿ego gara¿u, nie mo¿esz go postawiæ");
				return 1;
			}
			new Float:x, Float:y, Float:z, Float:angle;
			new isclosetohouse, form[256];
			new Hour, Minute, Second;
			new Year, Month, Day;
			new name[MAX_PLAYER_NAME], houselocation[MAX_ZONE_NAME];
			GetPlayerPos(playerid, x, y, z);
			GetPlayerFacingAngle(playerid, angle);
			for( new i = 0; i < sizeof(Houses); i++ )
			{
				if( !PlayerToPoint( 20.0, playerid, Houses[i][EnterX], Houses[i][EnterY], Houses[i][EnterZ] ) )
					continue;
				if( strcmp( Houses[i][Owner], name, false, MAX_PLAYER_NAME ) != 0 || Houses[i][HouseType] != 0)
					continue;
				isclosetohouse = 1;
				break;
			}
			if( isclosetohouse == 0 )
			{
				SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Gara¿ musi znajdowaæ siê w pobli¿u twojego domu !");
				return 1;
			}
			for( new i = 0; i < sizeof(Houses); i++ )
			{
				if(Houses[i][Owned] == 1)
					continue;
				if( InsertPlayerItemEx( playerid, 4, i, 0, 0, 0, 0, "Puste", 1 ) == 0 )
				{
					SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie masz miejsca na klucze do gara¿u !");
					return 1;
				}
				GetPlayerName(playerid, name, sizeof(name));
				GetCoords2DZone(Houses[i][EnterX],Houses[i][EnterY], houselocation, MAX_ZONE_NAME);
				
				strdel( Houses[i][Owner], 0, MAX_PLAYER_NAME );
				strins( Houses[i][Owner], name, 0, MAX_PLAYER_NAME );
				strdel( Houses[i][Description], 0, 128 );
				strins( Houses[i][Description], "Duzy garaz", 0, 128 );
				Houses[i][EnterX] = x;
				Houses[i][EnterY] = y;
				Houses[i][EnterZ] = z;
				Houses[i][EnterWorld] = GetPlayerVirtualWorld(playerid);
				Houses[i][EnterInterior] = GetPlayerInterior(playerid);
				Houses[i][HouseType] = 2;				
				Houses[i][EnterAngle] = angle;
				Houses[i][Owned] = 1;
				Houses[i][ExitX] = 608.0;
				Houses[i][ExitY] = -13.0;
				Houses[i][ExitZ] = 1001.0;
				Houses[i][ExitAngle] = 237.0;
				Houses[i][ExitInterior] = 1;
				Houses[i][HousePrice] = 30000;
				Houses[i][Rentable] = 0;
				
				SaveHouseData(i, "EnterX");
				SaveHouseData(i, "EnterY");
				SaveHouseData(i, "EnterZ");
				SaveHouseData(i, "EnterWorld");
				SaveHouseData(i, "EnterInterior");
				SaveHouseData(i, "EnterAngle");
				SaveHouseData(i, "ExitX");
				SaveHouseData(i, "ExitY");
				SaveHouseData(i, "ExitZ");
				SaveHouseData(i, "ExitInterior");
				SaveHouseData(i, "ExitAngle");				
				SaveHouseData(i, "Owner");
				SaveHouseData(i, "Owned");
				SaveHouseData(i, "Description");
				SaveHouseData(i, "HouseType");
				SaveHouseData(i, "Rentable");
				SaveHouseData(i, "HousePrice");
				
				gPlayerData[playerid][pVipGarageBig]--;
				SavePlayerData( playerid, "VipGarageBig" );
			
				DestroyDynamicPickup(Houses[i][PickupID]);
				Houses[i][PickupID] = CreateDynamicPickup(1239, 1, Houses[i][EnterX], Houses[i][EnterY], Houses[i][EnterZ]);

				DestroyDynamic3DTextLabel(Houses3DTextLabelA[i]);
				DestroyDynamic3DTextLabel(Houses3DTextLabelB[i]);
				DestroyDynamic3DTextLabel(Houses3DTextLabelC[i]);

				format(string, sizeof(string), "Adres: %d %s", i, houselocation);
				Houses3DTextLabelA[i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTYELLOW2, Houses[i][EnterX], Houses[i][EnterY], Houses[i][EnterZ]+1.0, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

				format(string, sizeof(string), "Wlasciciel: %s",Houses[i][Owner]);
				Houses3DTextLabelB[i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTYELLOW2, Houses[i][EnterX], Houses[i][EnterY], Houses[i][EnterZ]+0.5, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

				format(string, sizeof(string), "Opis: %s",Houses[i][Description]);
				Houses3DTextLabelC[i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTYELLOW2, Houses[i][EnterX], Houses[i][EnterY], Houses[i][EnterZ], 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

				format(form, sizeof(form), "[INFO:] Ustawiles du¿y gara¿ ID: %d w dzielnicy .", i);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, form);

				// log
				getdate(Year, Month, Day);				
				gettime(Hour, Minute, Second);

				format(form, sizeof(form), "[GOVERNMENT:] Garage(house) id: %d, set up X: %f, Y: %f, Z: %f by %s", i, x, y, z,gPlayerData[playerid][pName]);
				print(form);
				GovermentLog(form);
				return 1;
			}
			SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Brak wolnych gara¿y ! Powiadom administratora !");
			return 1;
		}
		if(strcmp(cmd, "/ustawgaraz", true) == 0)
		{
			if( gPlayerData[playerid][pVipGarage] <= 0 )
			{
				SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie wykupi³eœ gara¿u, nie mo¿esz go postawiæ");
				return 1;
			}
			new Float:x, Float:y, Float:z, Float:angle;
			new isclosetohouse;
			new name[MAX_PLAYER_NAME], houselocation[MAX_ZONE_NAME];
			new form[256];
			new Hour, Minute, Second;
			new Year, Month, Day;
			GetPlayerPos(playerid, x, y, z);
			GetPlayerFacingAngle(playerid, angle);
			GetPlayerName(playerid, name, sizeof(name));
			for( new i = 0; i < sizeof(Houses); i++ )
			{
				if( !PlayerToPoint( 20.0, playerid, Houses[i][EnterX], Houses[i][EnterY], Houses[i][EnterZ] ) )
					continue;
				if( strcmp( Houses[i][Owner], name, false, MAX_PLAYER_NAME ) != 0 || Houses[i][HouseType] != 0 )
					continue;
				isclosetohouse = 1;
				break;
			}				
			if( isclosetohouse == 0 )
			{
				SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Gara¿ musi znajdowaæ siê w pobli¿u twojego domu !");
				return 1;
			}
			for( new i = 0; i < sizeof(Houses); i++ )
			{
				if(Houses[i][Owned] == 1)
					continue;
				if( InsertPlayerItemEx( playerid, 4, i, 0, 0, 0, 0, "Puste", 1 ) == 0 )
				{
					SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie masz miejsca na klucze do gara¿u !");
					return 1;
				}
				GetCoords2DZone(Houses[i][EnterX],Houses[i][EnterY], houselocation, MAX_ZONE_NAME);
				
				strdel( Houses[i][Owner], 0, MAX_PLAYER_NAME );
				strins( Houses[i][Owner], name, 0, MAX_PLAYER_NAME );
				strdel( Houses[i][Description], 0, 128 );
				strins( Houses[i][Description], "Garaz", 0, 128 );
				Houses[i][EnterX] = x;
				Houses[i][EnterY] = y;
				Houses[i][EnterZ] = z;
				Houses[i][EnterWorld] = GetPlayerVirtualWorld(playerid);
				Houses[i][EnterInterior] = GetPlayerInterior(playerid);
				Houses[i][HouseType] = 1;				
				Houses[i][EnterAngle] = angle;
				Houses[i][Owned] = 1;
				Houses[i][ExitX] = 614.345;
				Houses[i][ExitY] = -126.796;
				Houses[i][ExitZ] = 998.104;
				Houses[i][ExitAngle] = 274.876;
				Houses[i][ExitInterior] = 3;
				Houses[i][HousePrice] = 10000;
				Houses[i][Rentable] = 0;
				
				SaveHouseData(i, "EnterX");
				SaveHouseData(i, "EnterY");
				SaveHouseData(i, "EnterZ");
				SaveHouseData(i, "EnterWorld");
				SaveHouseData(i, "EnterInterior");
				SaveHouseData(i, "EnterAngle");
				SaveHouseData(i, "ExitX");
				SaveHouseData(i, "ExitY");
				SaveHouseData(i, "ExitZ");
				SaveHouseData(i, "ExitInterior");
				SaveHouseData(i, "ExitAngle");				
				SaveHouseData(i, "Owner");
				SaveHouseData(i, "Owned");
				SaveHouseData(i, "Description");
				SaveHouseData(i, "HouseType");
				SaveHouseData(i, "Rentable");
				SaveHouseData(i, "HousePrice");
				
				gPlayerData[playerid][pVipGarage]--;
				SavePlayerData( playerid, "VipGarage" );
			
				DestroyDynamicPickup(Houses[i][PickupID]);
				Houses[i][PickupID] = CreateDynamicPickup(1239, 1, Houses[i][EnterX], Houses[i][EnterY], Houses[i][EnterZ]);

				DestroyDynamic3DTextLabel(Houses3DTextLabelA[i]);
				DestroyDynamic3DTextLabel(Houses3DTextLabelB[i]);
				DestroyDynamic3DTextLabel(Houses3DTextLabelC[i]);

				format(string, sizeof(string), "Adres: %d %s",i, houselocation);
				Houses3DTextLabelA[i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTYELLOW2, Houses[i][EnterX], Houses[i][EnterY], Houses[i][EnterZ]+1.0, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

				format(string, sizeof(string), "Wlasciciel: %s",Houses[i][Owner]);
				Houses3DTextLabelB[i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTYELLOW2, Houses[i][EnterX], Houses[i][EnterY], Houses[i][EnterZ]+0.5, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

				format(string, sizeof(string), "Opis: %s",Houses[i][Description]);
				Houses3DTextLabelC[i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTYELLOW2, Houses[i][EnterX], Houses[i][EnterY], Houses[i][EnterZ], 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
				
				format(form, sizeof(form), "[INFO:] Ustawiles gara¿ ID: %d w dzielnicy .", i);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, form);

				// log
				getdate(Year, Month, Day);
				gettime(Hour, Minute, Second);

				format(form, sizeof(form), "[GOVERNMENT:] Garage(house) id: %d, set up X: %f, Y: %f, Z: %f by %s", i, x, y, z,gPlayerData[playerid][pName]);
				print(form);
				GovermentLog(form);
				return 1;
			}
			SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Brak wolnych gara¿y ! Powiadom administratora !");
			return 1;
		}
		if(strcmp(cmd, "/ustawdom", true) == 0)
		{
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /ustawdom [id domu]");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Raz ustawionego domu nie mo¿na przestawiæ !");
				return 1;
			}
			new id = strval(tmp);
			if (gPlayerData[playerid][pFaction] == FACTIONID_GOVERNMENT)
			{
				if(Houses[id][Owned])
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz skorzystaæ z tego ID poniewa¿ jest ono zajête !");
					return 1;
				}
				if(Houses[id][HPlaced])
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] To ID zosta³o ju¿ wykorzystane, wybierz inne");
					return 1;
				}
				if(!Houses[id][HIntSet])
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Przed ustawieniem domu ustaw jego interior !");
					return 1;
				}
				new pmodel;
				new Float:x,Float:y,Float:z;
				GetPlayerPos(playerid, x, y, z);
				Houses[id][EnterX] = x;
				Houses[id][EnterY] = y;
				Houses[id][EnterZ] = z;
				Houses[id][EnterWorld] = GetPlayerVirtualWorld(playerid);
				Houses[id][EnterInterior] = GetPlayerInterior(playerid);
				new Float:angle;
				GetPlayerFacingAngle(playerid, angle);
				Houses[id][EnterAngle] = angle;
				Houses[id][HPlaced] = 1;

				switch(Houses[id][Owned])
				{
					case 0: pmodel = 1273;
					case 1: pmodel = 1239;
				}
				DestroyDynamicPickup(Houses[id][PickupID]);
				Houses[id][PickupID] = CreateDynamicPickup(pmodel, 1, Houses[id][EnterX], Houses[id][EnterY], Houses[id][EnterZ]);

				DestroyDynamic3DTextLabel(Houses3DTextLabelA[id]);
				DestroyDynamic3DTextLabel(Houses3DTextLabelB[id]);
				DestroyDynamic3DTextLabel(Houses3DTextLabelC[id]);

				if(Houses[id][Owned] == 0)
				{
					new houselocation[MAX_ZONE_NAME];
					GetCoords2DZone(Houses[id][EnterX],Houses[id][EnterY], houselocation, MAX_ZONE_NAME);

					format(string, sizeof(string), "Ten dom jest na sprzedaz!");
					Houses3DTextLabelA[id] = CreateDynamic3DTextLabel(string, COLOR_LIGHTYELLOW2, Houses[id][EnterX], Houses[id][EnterY], Houses[id][EnterZ]+1.0, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

					format(string, sizeof(string), "Adres: %d %s",id,houselocation);
					Houses3DTextLabelB[id] = CreateDynamic3DTextLabel(string, COLOR_LIGHTYELLOW2, Houses[id][EnterX], Houses[id][EnterY], Houses[id][EnterZ]+0.5, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

					format(string, sizeof(string), "Opis: %s, Cena: $%d",Houses[id][Description],Houses[id][HousePrice]);
					Houses3DTextLabelC[id] = CreateDynamic3DTextLabel(string, COLOR_LIGHTYELLOW2, Houses[id][EnterX], Houses[id][EnterY], Houses[id][EnterZ], 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
				}
				else
				{
					if(Houses[id][Rentable] == 1)
					{
						new houselocation[MAX_ZONE_NAME];
						GetCoords2DZone(Houses[id][EnterX],Houses[id][EnterY], houselocation, MAX_ZONE_NAME);

						format(string, sizeof(string), "Adres: %d %s",id,houselocation);
						Houses3DTextLabelA[id] = CreateDynamic3DTextLabel(string, COLOR_LIGHTYELLOW2, Houses[id][EnterX], Houses[id][EnterY], Houses[id][EnterZ]+1.0, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

						format(string, sizeof(string), "Wlasciciel: %s",Houses[id][Owner]);
						Houses3DTextLabelB[id] = CreateDynamic3DTextLabel(string, COLOR_LIGHTYELLOW2, Houses[id][EnterX], Houses[id][EnterY], Houses[id][EnterZ]+0.5, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

						format(string, sizeof(string), "Opis: %s Czynsz: $%d",Houses[id][Description],Houses[id][RentCost]);
						Houses3DTextLabelC[id] = CreateDynamic3DTextLabel(string, COLOR_LIGHTYELLOW2, Houses[id][EnterX], Houses[id][EnterY], Houses[id][EnterZ], 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
					}
					else
					{
						new houselocation[MAX_ZONE_NAME];
						GetCoords2DZone(Houses[id][EnterX],Houses[id][EnterY], houselocation, MAX_ZONE_NAME);

						format(string, sizeof(string), "Adres: %d %s",id,houselocation);
						Houses3DTextLabelA[id] = CreateDynamic3DTextLabel(string, COLOR_LIGHTYELLOW2, Houses[id][EnterX], Houses[id][EnterY], Houses[id][EnterZ]+1.0, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

						format(string, sizeof(string), "Wlasciciel: %s",Houses[id][Owner]);
						Houses3DTextLabelB[id] = CreateDynamic3DTextLabel(string, COLOR_LIGHTYELLOW2, Houses[id][EnterX], Houses[id][EnterY], Houses[id][EnterZ]+0.5, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

						format(string, sizeof(string), "Opis: %s",Houses[id][Description]);
						Houses3DTextLabelC[id] = CreateDynamic3DTextLabel(string, COLOR_LIGHTYELLOW2, Houses[id][EnterX], Houses[id][EnterY], Houses[id][EnterZ], 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
					}
				}
				SaveHouseData(id, "EnterX");
				SaveHouseData(id, "EnterY");
				SaveHouseData(id, "EnterZ");
				SaveHouseData(id, "EnterWorld");
				SaveHouseData(id, "EnterInterior");
				SaveHouseData(id, "EnterAngle");
				SaveHouseData(id, "Placed");
				new form[256];
				format(form, sizeof(form), "[INFO:] Ustawi³eœ dom o ID: %d w dzielnicy", id);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, form);

				// log
				new Year, Month, Day;
				getdate(Year, Month, Day);
				new Hour, Minute, Second;
				gettime(Hour, Minute, Second);

				format(form, sizeof(form), "[GOVERNMENT:] House id: %d, set up X: %f, Y: %f, Z: %f by %s", id, x, y, z,gPlayerData[playerid][pName]);
				print(form);
				GovermentLog(form);
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "nie jesteœ urzednikiem..");
			}
			return 1;
		}
		if(strcmp(cmd, "/wynajmijkomornika", true) == 0)
		{
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /wynajmijkomornika [IdDomu]");
				return 1;
			}
			new id = strval(tmp);
			if (gPlayerData[playerid][pFaction] == 9)
			{
				new Year, Month, Day;
				getdate(Year, Month, Day);
				new Hour, Minute, Second;
				gettime(Hour, Minute, Second);
				new stringTMP[256];
				format(stringTMP, sizeof(stringTMP), "[GOVERNMENT:] Hose sold by broker: %s, ID domu: %d, cena: %d$, wlasciciel: %s", gPlayerData[playerid][pName], id, Houses[id][HousePrice], Houses[id][Owner]);
				GovermentLog(stringTMP);
				
				Houses[id][Locked] = 1;
				Houses[id][Owned] = 0;
				Houses[id][Money] = 0;
				if( Houses[id][HRadio1Bought] )
					DestroyDynamicObject(Businesses[id][BRadio1Obj]);
				Houses[id][HRadio1Bought] = 0;
				strmid(Houses[id][Owner], "None", 0, strlen("None"), 255);

				DestroyDynamicPickup(Houses[id][PickupID]);
				Houses[id][PickupID] = CreateDynamicPickup(1273, 1, Houses[id][EnterX], Houses[id][EnterY], Houses[id][EnterZ]);

				new houselocation[MAX_ZONE_NAME];
				GetCoords2DZone(Houses[id][EnterX],Houses[id][EnterY], houselocation, MAX_ZONE_NAME);

				format(string, sizeof(string), "Ten dom jest na sprzedaz!");
				UpdateDynamic3DTextLabelText(Houses3DTextLabelA[id], COLOR_LIGHTYELLOW2, string);

				format(string, sizeof(string), "Adres: %d %s",id,houselocation);
				UpdateDynamic3DTextLabelText(Houses3DTextLabelB[id], COLOR_LIGHTYELLOW2, string);

				format(string, sizeof(string), "Opis: %s, Cena: $%d",Houses[id][Description],Houses[id][HousePrice]);
				UpdateDynamic3DTextLabelText(Houses3DTextLabelC[id], COLOR_LIGHTYELLOW2, string);

				SaveHouseData(id, "Locked");
				SaveHouseData(id, "Owned");
				SaveHouseData(id, "Owner");
				SaveHouseData(id, "Money");
				SaveHouseData(id, "HRadio1Bought");

				new form[128];
				format(form, sizeof(form), "[INFO:] Sprzedales dom ID: %d.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD, form);
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "nie jesteœ urzednikiem.");
			}
			return 1;
		}
		if(strcmp(cmd, "/cenadomu", true) == 0)
		{
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /cenadomu [id domu] [cena]");
				return 1;
			}
			if (gPlayerData[playerid][pFaction] == 9)
			{
				new id;
				id = strval(tmp);
				tmp = strtok(cmdtext, idx);
				if(!strlen(tmp))
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /cenadomu [id domu] [cena]");
					return 1;
				}
				new id2;
				id2 = strval(tmp);

				if(Houses[id][Owned] == 1)
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz zmieniæ ceny domu kupionego");
					return 1;
				}
				if(id2 < 0)
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Cena musi byæ wiêksza lub równa zeru");
					return 1;
				}
				Houses[id][HousePrice] = id2;
				if(Houses[id][Owned] == 0)
				{
					format(string, sizeof(string), "Opis: %s, Cena: $%d",Houses[id][Description],Houses[id][HousePrice]);
					UpdateDynamic3DTextLabelText(Houses3DTextLabelC[id], COLOR_LIGHTYELLOW2, string);
				}

				new form[128];
				format(form, sizeof form, "[INFO:] Ustawiles cene domu ID: %d's na %d.", id,id2);
				SendClientMessage(playerid, COLOR_ADMINCMD,form);
				SaveHouseData(id, "HousePrice");

				new Year, Month, Day;
				getdate(Year, Month, Day);
				new Hour, Minute, Second;
				gettime(Hour, Minute, Second);

				format(string, sizeof(string), "[GOVERNMENT:] House id: %d, price set up to: %d$ by %s", id, id2, GetPlayerNameEx(playerid));
				print(string);
				GovermentLog(string);
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "nie jesteœ urzednikiem.");
			}
			return 1;
		}
		if(strcmp(cmd, "/wnetrzedomu", true) == 0)
		{
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /wnetrzedomu [id domu] [id 1-50]");
				return 1;
			}
			if (gPlayerData[playerid][pFaction] == FACTIONID_GOVERNMENT)
			{
				new id;
				id = strval(tmp);
				if(Houses[id][HIntSet])
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Wnetrze tego domu zosta³o ju¿ ustawione i nie mo¿na go zmieniæ");
					return 1;
				}
				tmp = strtok(cmdtext, idx);
				if(!strlen(tmp))
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /wnetrzedomu [id domu] [id wnetrza 1-50]");
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Raz ustawionego wnêtrza nie mo¿na zmieniæ !");
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[1:] - 3 kk; [2:] - 500 k; [3:] - 300 k; [4:] - 3 kk; [5:] - 1,5 kk; [6:] - 150 k; [7:] - 250 k; [8:] - 300 k; [9:] - 3 kk; [10:] - 800 k");
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[11:] - 4 kk; [12:] - 110 k; [13:] - 100 k; [14:] - 400 k; [15:] - 300 k; [16:] - 400 k; [17:] - 1 kk; [18:] - 1,5 kk; [19:] - 500 k; [20:] - 850 k");
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[21:] - 200 k; [22:] - 1,5 kk; [23:] - 300 k; [24:] - 50 k; [25:] - 70 k; [27:] - 10 k; [28:] - 0 k; [29:] - 0 k; [30:] - 800 k");
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[31:] - 1 k; [32:] - 200 k; [33:] - 1 k; [34:] - 1 k; [35:] - 1 k; [36:] - 1 k; [37:] - 1 k; [38:] - 150 k; [39:] - 100 k; [40:] - 600 k");
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[41:] - 300 k; [42:] - 1 k; [43:] - 10-3 k; [44:] - ??; [45:] - ??; [46:] - ??; [47:] - ??; [48:] - ??");

					return 1;
				}
				new id2;
				id2 = strval(tmp);
				if(id2 < 1 || id2 > 52) { SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Wnêtrze o ID's 1-52."); return 1; }

				Houses[id][HIntSet] = 1;
				SaveHouseData(id, "IntSet");
				Houses[id][HInterior] = id2;
				SaveHouseData(id, "Interior");
				if(id2 == 1)
				{
					Houses[id][ExitX] = 235.212356;
					Houses[id][ExitY] = 1186.690551;
					Houses[id][ExitZ] = 1080.339966;
					Houses[id][ExitInterior] = 3;
					Houses[id][ExitAngle] = 359.15814;
					format(string, sizeof string, "House ID: %d - Opis: Large/2 story/3 bedrooms/clone of House 9.", id,id2);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 2)
				{
					Houses[id][ExitX] = 226.781341;
					Houses[id][ExitY] = 1240.207153;
					Houses[id][ExitZ] = 1082.149902;
					Houses[id][ExitInterior] = 2;
					Houses[id][ExitAngle] = 93.762290;
					format(string, sizeof string, "House ID: %d - Opis: Medium/1 story/1 bedroom.", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 3)
				{
					Houses[id][ExitX] = 223.180511;
					Houses[id][ExitY] = 1287.081420;
					Houses[id][ExitZ] = 1082.199951;
					Houses[id][ExitInterior] = 1;
					Houses[id][ExitAngle] = 359.134765;
					format(string, sizeof string, "House ID: %d - Opis: Small/1 story/1 bedroom.", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 4)
				{
					Houses[id][ExitX] = 225.630997;
					Houses[id][ExitY] = 1022.479980;
					Houses[id][ExitZ] = 1084.069946;
					Houses[id][ExitInterior] = 7;
					Houses[id][ExitAngle] = 93.762290;
					format(string, sizeof string, "House ID: %d - Opis: VERY Large/2 story/4 bedrooms.", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 5)
				{
					Houses[id][ExitX] = 295.138977;
					Houses[id][ExitY] = 1472.259887;
					Houses[id][ExitZ] = 1080.519897;
					Houses[id][ExitInterior] = 15;
					Houses[id][ExitAngle] = 0.701460;
					format(string, sizeof string, "House ID: %d - Opis: Small/1 story/2 bedrooms.", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 6)
				{
					Houses[id][ExitX] = 327.982147;
					Houses[id][ExitY] = 1477.730102;
					Houses[id][ExitZ] = 1084.449951;
					Houses[id][ExitInterior] = 15;
					Houses[id][ExitAngle] = 357.25476;
					format(string, sizeof string, "House ID: %d - Opis: Small/1 story/2 bedrooms.", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 7)
				{
					Houses[id][ExitX] = 387.219482;
					Houses[id][ExitY] = 1471.769897;
					Houses[id][ExitZ] = 1080.209961;
					Houses[id][ExitInterior] = 15;
					Houses[id][ExitAngle] = 93.762290;
					format(string, sizeof string, "House ID: %d - Opis: Small/1 story/1 bedroom/NO BATHROOM.", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 8)
				{
					Houses[id][ExitX] = 375.971985;
					Houses[id][ExitY] = 1417.269897;
					Houses[id][ExitZ] = 1081.409912;
					Houses[id][ExitInterior] = 15;
					format(string, sizeof string, "House ID: %d - Opis: Small/1 story/1 bedroom.", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 9)
				{
					Houses[id][ExitX] = 491.233459;
					Houses[id][ExitY] = 1398.510131;
					Houses[id][ExitZ] = 1080.339966;
					Houses[id][ExitInterior] = 2;
					Houses[id][ExitAngle] = 0.654741;
					format(string, sizeof string, "House ID: %d - Opis: Large/2 story/3 bedrooms.", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 10)
				{
					Houses[id][ExitX] = 447.029083;
					Houses[id][ExitY] = 1397.068969;
					Houses[id][ExitZ] = 1084.339966;
					Houses[id][ExitInterior] = 2;
					Houses[id][ExitAngle] = 354.074676;
					format(string, sizeof string, "House ID: %d - Opis: Medium/1 story/2 bedrooms.", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 11)
				{
					Houses[id][ExitX] = 226.305770;
					Houses[id][ExitY] = 1114.389893;
					Houses[id][ExitZ] = 1081.189941;
					Houses[id][ExitInterior] = 5;
					Houses[id][ExitAngle] = 271.643859;
					format(string, sizeof string, "House ID: %d - Opis: Large/2 story/4 bedrooms.", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 12)
				{
					Houses[id][ExitX] = 260.834625;
					Houses[id][ExitY] = 1284.303344;
					Houses[id][ExitZ] = 1080.299927;
					Houses[id][ExitInterior] = 4;
					Houses[id][ExitAngle] = 357.011657;
					format(string, sizeof string, "House ID: %d - Opis: Small/1 story/1 bedroom.", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 13)
				{
					Houses[id][ExitX] = 222.189910;
					Houses[id][ExitY] = 1140.205078;
					Houses[id][ExitZ] = 1082.679932;
					Houses[id][ExitInterior] = 4;
					Houses[id][ExitAngle] = 0.748315;
					format(string, sizeof string, "House ID: %d - Opis: Small/1 story/1 bedroom/NO BATHROOM!", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 14)
				{
					Houses[id][ExitX] = 24.124982;
					Houses[id][ExitY] = 1340.169921;
					Houses[id][ExitZ] = 1084.449951;
					Houses[id][ExitInterior] = 10;
					Houses[id][ExitAngle] = 4.195019;
					format(string, sizeof string, "House ID: %d - Opis: Medium/2 story/1 bedroom.", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 15)
				{
					Houses[id][ExitX] = -260.504791;
					Houses[id][ExitY] = 1456.518676;
					Houses[id][ExitZ] = 1084.449951;
					Houses[id][ExitInterior] = 4;
					Houses[id][ExitAngle] = 87.20574;
					format(string, sizeof string, "House ID: %d - Opis: Large/2 story/1 bedroom/NO BATHROOM!", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 16)
				{
					Houses[id][ExitX] = 22.992769;
					Houses[id][ExitY] = 1403.328125;
					Houses[id][ExitZ] = 1084.449951;
					Houses[id][ExitInterior] = 5;
					Houses[id][ExitAngle] = 1.978268;
					format(string, sizeof string, "House ID: %d - Opis: Medium/1 story/2 bedrooms/NO BATHROOM or DOORS!", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 17)
				{
					Houses[id][ExitX] = 140.149276;
					Houses[id][ExitY] = 1365.931884;
					Houses[id][ExitZ] = 1083.969971;
					Houses[id][ExitInterior] = 5;
					Houses[id][ExitAngle] = 353.80810;
					format(string, sizeof string, "House ID: %d - Opis: Large/2 story/4 bedrooms/NO BATHROOM!", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 18)
				{
					Houses[id][ExitX] = 234.120880;
					Houses[id][ExitY] = 1063.727661;
					Houses[id][ExitZ] = 1084.309937;
					Houses[id][ExitInterior] = 6;
					Houses[id][ExitAngle] = 352.21798;
					format(string, sizeof string, "House ID: %d - Opis: Large/2 story/3 bedrooms.", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 19)
				{
					Houses[id][ExitX] = -68.594032;
					Houses[id][ExitY] = 1351.203613;
					Houses[id][ExitZ] = 1080.279907;
					Houses[id][ExitInterior] = 6;
					Houses[id][ExitAngle] = 0.051390;
					format(string, sizeof string, "House ID: %d - Opis: Small/1 story/NO BEDROOM!", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 20)
				{
					Houses[id][ExitX] = -283.441253;
					Houses[id][ExitY] = 1470.989013;
					Houses[id][ExitZ] = 1084.449951;
					Houses[id][ExitInterior] = 15;
					Houses[id][ExitAngle] = 87.7855;
					format(string, sizeof string, "House ID: %d - Opis: 1 bedroom/living room/kitchen/NO BATHROOM", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 21)
				{
					Houses[id][ExitX] = -42.387855;
					Houses[id][ExitY] = 1405.472412;
					Houses[id][ExitZ] = 1084.449951;
					Houses[id][ExitInterior] = 8;
					Houses[id][ExitAngle] = 0.678046;
					format(string, sizeof string, "House ID: %d - Opis: Small/1 story/NO BEDROOM!", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 22)
				{
					Houses[id][ExitX] = 83.223770;
					Houses[id][ExitY] = 1322.293945;
					Houses[id][ExitZ] = 1083.889893;
					Houses[id][ExitInterior] = 9;
					Houses[id][ExitAngle] = 354.724609;
					format(string, sizeof string, "House ID: %d - Opis: Medium/2 story/2 bedrooms", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 23)
				{
					Houses[id][ExitX] = 260.684356;
					Houses[id][ExitY] = 1237.257202;
					Houses[id][ExitZ] = 1084.259888;
					Houses[id][ExitInterior] = 9;
					Houses[id][ExitAngle] = 357.23129;
					format(string, sizeof string, "House ID: %d - Opis: Small/1 story/1 bedroom", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 24)
				{
					Houses[id][ExitX] = 243.723510;
					Houses[id][ExitY] = 305.090698;
					Houses[id][ExitZ] = 999.231995;
					Houses[id][ExitInterior] = 1;
					Houses[id][ExitAngle] = 268.337463;
					format(string, sizeof string, "House ID: %d - Opis: Denises Bedroom", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 25)
				{
					Houses[id][ExitX] = 266.500610;
					Houses[id][ExitY] = 304.928924;
					Houses[id][ExitZ] = 999.325989;
					Houses[id][ExitInterior] = 2;
					Houses[id][ExitAngle] = 273.640808;
					format(string, sizeof string, "House ID: %d - Opis: Katies Bedroom", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 26)
				{
					Houses[id][ExitX] = 293.210845;
					Houses[id][ExitY] = 310.165985;
					Houses[id][ExitZ] = 999.154968;
					Houses[id][ExitInterior] = 3;
					Houses[id][ExitAngle] = 90.652397;
					format(string, sizeof string, "House ID: %d - Opis: Helenas Bedroom (barn) - limited movement. LIPNE !!!", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 27)
				{
					Houses[id][ExitX] = 302.181000;
					Houses[id][ExitY] = 300.722992;
					Houses[id][ExitZ] = 999.231995;
					Houses[id][ExitInterior] = 4;
					Houses[id][ExitAngle] = 0;
					format(string, sizeof string, "House ID: %d - Opis: Michelles Bedroom.", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 28)
				{
					Houses[id][ExitX] = 322.197998;
					Houses[id][ExitY] = 302.497986;
					Houses[id][ExitZ] = 999.231995;
					Houses[id][ExitInterior] = 5;
					Houses[id][ExitAngle] = 0;
					format(string, sizeof string, "House ID: %d - Opis: Male wiezienie/posterunek !!!.", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 29)
				{
					Houses[id][ExitX] = 343.722045;
					Houses[id][ExitY] = 304.778656;
					Houses[id][ExitZ] = 999.155700;
					Houses[id][ExitInterior] = 6;
					Houses[id][ExitAngle] = 271.980529;
					format(string, sizeof string, "House ID: %d - Opis: Pokoj POKUS !!!", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 30)
				{
					Houses[id][ExitX] = 2495.955810;
					Houses[id][ExitY] = -1692.085205;
					Houses[id][ExitZ] = 1014.750000;
					Houses[id][ExitInterior] = 3;
					Houses[id][ExitAngle] = 180.486;
					format(string, sizeof string, "House ID: %d - Opis: CJs Moms House.", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 31)
				{
					Houses[id][ExitX] = 1260.652709;
					Houses[id][ExitY] = -785.114318;
					Houses[id][ExitZ] = 1091.959961;
					Houses[id][ExitInterior] = 5;
					Houses[id][ExitAngle] = 267.3974;
					format(string, sizeof string, "House ID: %d - Opis: Madd Doggs Mansion (West door).", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 32)
				{
					Houses[id][ExitX] = 2468.834960;
					Houses[id][ExitY] = -1698.243286;
					Houses[id][ExitZ] = 1013.509949;
					Houses[id][ExitInterior] = 2;
					Houses[id][ExitAngle] = 90.9890;
					format(string, sizeof string, "House ID: %d - Opis: Ryders house.", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 33)
				{
					Houses[id][ExitX] = 2526.459961;
					Houses[id][ExitY] = -1679.089966;
					Houses[id][ExitZ] = 1015.500000;
					Houses[id][ExitInterior] = 1;
					Houses[id][ExitAngle] = 0;
					format(string, sizeof string, "House ID: %d - Opis: Sweets House SPIERDOLONY INT .", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 34)
				{
					Houses[id][ExitX] = 2541.551757;
					Houses[id][ExitY] = -1303.960449;
					Houses[id][ExitZ] = 1025.069946;
					Houses[id][ExitInterior] = 2;
					Houses[id][ExitAngle] = 263.277;
					format(string, sizeof string, "House ID: %d - Opis: Big Smokes Crack Factory (Ground Floor).", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 35)
				{
					Houses[id][ExitX] = 744.426879;
					Houses[id][ExitY] = 1436.35253;
					Houses[id][ExitZ] = 1102.739990;
					Houses[id][ExitInterior] = 6;
					Houses[id][ExitAngle] = 356.62817;
					format(string, sizeof string, "House ID: %d - Opis: Fanny Batters Whore House.", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 36)
				{
					Houses[id][ExitX] = 964.106995;
					Houses[id][ExitY] = -53.205498;
					Houses[id][ExitZ] = 1001.179993;
					Houses[id][ExitInterior] = 3;
					Houses[id][ExitAngle] = 0;
					format(string, sizeof string, "House ID: %d - Opis: Tiger Skin Rug Brothel ZWALONY.", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 37)
				{
					Houses[id][ExitX] = 2352.923095;
					Houses[id][ExitY] = -1180.498291;
					Houses[id][ExitZ] = 1028.000000;
					Houses[id][ExitInterior] = 5;
					Houses[id][ExitAngle] = 91.6158;
					format(string, sizeof string, "House ID: %d - Opis: Burning Desire Gang House.", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 38)
				{
					Houses[id][ExitX] = 2807.423095;
					Houses[id][ExitY] = -1174.750610;
					Houses[id][ExitZ] = 1025.579956;
					Houses[id][ExitInterior] = 8;
					Houses[id][ExitAngle] = 359.494;
					format(string, sizeof string, "House ID: %d - Opis: Colonel Furhberger's House.", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 39)
				{
					Houses[id][ExitX] = 318.818206;
					Houses[id][ExitY] = 1114.492187;
					Houses[id][ExitZ] = 1083.979980;
					Houses[id][ExitInterior] = 5;
					Houses[id][ExitAngle] = 5.424973;
					format(string, sizeof string, "House ID: %d - Opis: Crack Den.", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 40)
				{
					Houses[id][ExitX] = 2324.260253;
					Houses[id][ExitY] = -1149.536865;
					Houses[id][ExitZ] = 1050.719971;
					Houses[id][ExitInterior] = 12;
					Houses[id][ExitAngle] = 358.19;
					format(string, sizeof string, "House ID: %d - Opis: Unused Safe House.", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 41)
				{
					Houses[id][ExitX] = 447.118774;
					Houses[id][ExitY] = 506.322723;
					Houses[id][ExitZ] = 1001.419983;
					Houses[id][ExitInterior] = 12;
					Houses[id][ExitAngle] = 0.991497;
					format(string, sizeof string, "House ID: %d - Opis: Budget Inn Motel Room.", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 42)
				{
					Houses[id][ExitX] = 2214.388671;
					Houses[id][ExitY] = -1150.523071;
					Houses[id][ExitZ] = 1025.799927;
					Houses[id][ExitInterior] = 15;
					Houses[id][ExitAngle] = 269.4;
					format(string, sizeof string, "House ID: %d - Opis: Jefferson Motel. (REALLY EXPENSIVE)", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 43)
				{
					Houses[id][ExitX] = -1924.921875;
					Houses[id][ExitY] = 1198.463623;
					Houses[id][ExitZ] = 57.2;
					Houses[id][ExitInterior] = 0;
					Houses[id][ExitAngle] = 0;
					format(string, sizeof string, "House ID: %d - Slums", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 44)
				{
					Houses[id][ExitX] = 14.2741;
					Houses[id][ExitY] = 1539.3162;
					Houses[id][ExitZ] = 12.7500;
					Houses[id][ExitInterior] = 0;
					Houses[id][ExitAngle] = 0;
					format(string, sizeof string, "House ID: %d - Nowy dodany int", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 45)
				{
					Houses[id][ExitX] = 1550.7493;
					Houses[id][ExitY] = -1364.8269;
					Houses[id][ExitZ] = 491;
					Houses[id][ExitInterior] = 0;
					Houses[id][ExitAngle] = 0;
					format(string, sizeof string, "House ID: %d - Nowy dodany int 2", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 46)
				{
					Houses[id][ExitX] = 2766.967773;
					Houses[id][ExitY] = -1466.013916;
					Houses[id][ExitZ] = 66.528175;
					Houses[id][ExitInterior] = 0;
					Houses[id][ExitAngle] = 0;
					format(string, sizeof string, "House ID: %d - Nowy dodany int 3", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 47)
				{
					Houses[id][ExitX] = -215.47416687012;
					Houses[id][ExitY] = -169.38523864746;
					Houses[id][ExitZ] = 1598.7647705078;
					Houses[id][ExitInterior] = 0;
					Houses[id][ExitAngle] = 0;
					format(string, sizeof string, "House ID: %d - Nowy dodany int 4", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				else if(id2 == 48)
				{
					Houses[id][ExitX] = -2666.9397;
					Houses[id][ExitY] = 632.9147;
					Houses[id][ExitZ] = 66.1670;
					Houses[id][ExitInterior] = 0;
					Houses[id][ExitAngle] = 0;
					format(string, sizeof string, "House ID: %d - Nowy dodany int 5", id);
					SendClientMessage(playerid, COLOR_ADMINCMD,string);
				}
				new Year, Month, Day;
				getdate(Year, Month, Day);
				new Hour, Minute, Second;
				gettime(Hour, Minute, Second);

				format(string, sizeof(string), "[GOVERNMENT:] House id: %d, interior set up to: %d by %s", id, id2, GetPlayerNameEx(playerid));
				GovermentLog(string);

				SaveHouseData(id, "ExitX");
				SaveHouseData(id, "ExitY");
				SaveHouseData(id, "ExitZ");
				SaveHouseData(id, "ExitInterior");
				SaveHouseData(id, "ExitAngle");
				SaveHouseData(id, "HousePrice");
				}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "nie jesteœ urzednikiem.");
			}
			return 1;
		}
		if(strcmp(cmd, "/ahouseentrance", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 1)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /ahouseentrance [houseid]");
				return 1;
			}
			new id = strval(tmp);
			new pmodel;
			new Float:x,Float:y,Float:z;
			GetPlayerPos(playerid, x, y, z);
			Houses[id][EnterX] = x;
			Houses[id][EnterY] = y;
			Houses[id][EnterZ] = z;
			Houses[id][EnterWorld] = GetPlayerVirtualWorld(playerid);
			Houses[id][EnterInterior] = GetPlayerInterior(playerid);
			new Float:angle;
			GetPlayerFacingAngle(playerid, angle);
			Houses[id][EnterAngle] = angle;

			switch(Houses[id][Owned])
			{
				case 0: pmodel = 1273;
				case 1: pmodel = 1239;
			}
			DestroyDynamicPickup(Houses[id][PickupID]);
			Houses[id][PickupID] = CreateDynamicPickup(pmodel, 1, Houses[id][EnterX], Houses[id][EnterY], Houses[id][EnterZ]);
			DestroyDynamic3DTextLabel(Houses3DTextLabelA[id]);
			DestroyDynamic3DTextLabel(Houses3DTextLabelB[id]);
			DestroyDynamic3DTextLabel(Houses3DTextLabelC[id]);
			if(Houses[id][Owned] == 0)
			{
				new houselocation[MAX_ZONE_NAME];
				GetCoords2DZone(Houses[id][EnterX],Houses[id][EnterY], houselocation, MAX_ZONE_NAME);

				format(string, sizeof(string), "Ten dom jest na sprzedaz!");
				Houses3DTextLabelA[id] = CreateDynamic3DTextLabel(string, COLOR_LIGHTYELLOW2, Houses[id][EnterX], Houses[id][EnterY], Houses[id][EnterZ]+1.0, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

				format(string, sizeof(string), "Adres: %d %s",id,houselocation);
				Houses3DTextLabelB[id] = CreateDynamic3DTextLabel(string, COLOR_LIGHTYELLOW2, Houses[id][EnterX], Houses[id][EnterY], Houses[id][EnterZ]+0.5, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

				format(string, sizeof(string), "Opis: %s, Cena: $%d",Houses[id][Description],Houses[id][HousePrice]);
				Houses3DTextLabelC[id] = CreateDynamic3DTextLabel(string, COLOR_LIGHTYELLOW2, Houses[id][EnterX], Houses[id][EnterY], Houses[id][EnterZ], 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
			}
			else
			{
				if(Houses[id][Rentable] == 1)
				{
					new houselocation[MAX_ZONE_NAME];
					GetCoords2DZone(Houses[id][EnterX],Houses[id][EnterY], houselocation, MAX_ZONE_NAME);

					format(string, sizeof(string), "Adres: %d %s",id,houselocation);
					Houses3DTextLabelA[id] = CreateDynamic3DTextLabel(string, COLOR_LIGHTYELLOW2, Houses[id][EnterX], Houses[id][EnterY], Houses[id][EnterZ]+1.0, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

					format(string, sizeof(string), "Wlasciciel: %s",Houses[id][Owner]);
					Houses3DTextLabelB[id] = CreateDynamic3DTextLabel(string, COLOR_LIGHTYELLOW2, Houses[id][EnterX], Houses[id][EnterY], Houses[id][EnterZ]+0.5, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

					format(string, sizeof(string), "Opis: %s Czynsz: $%d",Houses[id][Description],Houses[id][RentCost]);
					Houses3DTextLabelC[id] = CreateDynamic3DTextLabel(string, COLOR_LIGHTYELLOW2, Houses[id][EnterX], Houses[id][EnterY], Houses[id][EnterZ], 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
				}
				else
				{
					new houselocation[MAX_ZONE_NAME];
					GetCoords2DZone(Houses[id][EnterX],Houses[id][EnterY], houselocation, MAX_ZONE_NAME);

					format(string, sizeof(string), "Adres: %d %s",id,houselocation);
					Houses3DTextLabelA[id] = CreateDynamic3DTextLabel(string, COLOR_LIGHTYELLOW2, Houses[id][EnterX], Houses[id][EnterY], Houses[id][EnterZ]+1.0, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

					format(string, sizeof(string), "Wlasciciel: %s",Houses[id][Owner]);
					Houses3DTextLabelB[id] = CreateDynamic3DTextLabel(string, COLOR_LIGHTYELLOW2, Houses[id][EnterX], Houses[id][EnterY], Houses[id][EnterZ]+0.5, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

					format(string, sizeof(string), "Opis: %s",Houses[id][Description]);
					Houses3DTextLabelC[id] = CreateDynamic3DTextLabel(string, COLOR_LIGHTYELLOW2, Houses[id][EnterX], Houses[id][EnterY], Houses[id][EnterZ], 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
				}
			}
			SaveHouseData(id, "EnterX");
			SaveHouseData(id, "EnterY");
			SaveHouseData(id, "EnterZ");
			SaveHouseData(id, "EnterWorld");
			SaveHouseData(id, "EnterInterior");
			SaveHouseData(id, "EnterAngle");
			new form[128];
			format(form, sizeof(form), "[INFO:] You have set house ID: %d's location.", id);
			SendClientMessage(playerid, COLOR_ADMINCMD, form);
			return 1;
		}
		if(strcmp(cmd, "/ahouseexit", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /ahouseexit [houseid]");
				return 1;
			}
			new id = strval(tmp);
			new Float:x,Float:y,Float:z;
			GetPlayerPos(playerid, x, y, z);
			Houses[id][ExitX] = x;
			Houses[id][ExitY] = y;
			Houses[id][ExitZ] = z;
			Houses[id][ExitInterior] = GetPlayerInterior(playerid);
			new Float:angle;
			GetPlayerFacingAngle(playerid, angle);
			Houses[id][ExitAngle] = angle;
			SaveHouseData(id, "ExitX");
			SaveHouseData(id, "ExitY");
			SaveHouseData(id, "ExitZ");
			SaveHouseData(id, "ExitInterior");
			SaveHouseData(id, "ExitAngle");
			new form[128];
			format(form, sizeof(form), "[INFO:] You have set house ID: %d's exit location.", id);
			SendClientMessage(playerid, COLOR_ADMINCMD, form);
			return 1;
		}
		if(strcmp(cmd, "/ahousedescription", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 1)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /ahousedescription [houseid] [discription]");
				return 1;
			}
			new id = strval(tmp);
			new length = strlen(cmdtext);
			while ((idx < length) && (cmdtext[idx] <= ' '))
			{
				idx++;
			}
			new offset = idx;
			new result[128];
			while ((idx < length) && ((idx - offset) < (sizeof(result) - 1)))
			{
				result[idx - offset] = cmdtext[idx];
				idx++;
			}
			result[idx - offset] = EOS;
			if(!strlen(result))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /ahousedescription [houseid] [discription]");
				return 1;
			}
			if(strfind( result , "|" , true ) == -1)
			{
				strmid(Houses[id][Description], (result), 0, strlen((result)), 128);

				if(Houses[id][Owned] == 0)
				{
					format(string, sizeof(string), "Opis: %s, Cena: $%d",Houses[id][Description],Houses[id][HousePrice]);
					UpdateDynamic3DTextLabelText(Houses3DTextLabelC[id], COLOR_LIGHTYELLOW2, string);
				}
				else
				{
					if(Houses[id][Rentable] == 1)
					{
						format(string, sizeof(string), "Opis: %s Czynsz: $%d",Houses[id][Description],Houses[id][RentCost]);
						UpdateDynamic3DTextLabelText(Houses3DTextLabelC[id], COLOR_LIGHTYELLOW2, string);
					}
					else
					{
						format(string, sizeof(string), "Opis: %s",Houses[id][Description]);
						UpdateDynamic3DTextLabelText(Houses3DTextLabelC[id], COLOR_LIGHTYELLOW2, string);
					}
				}

				format(string, sizeof(string), "[INFO:] You have set house ID: %d's description to %s", id,(result));
				SendClientMessage(playerid, COLOR_ADMINCMD, string);
				SaveHouseData(id, "Description");
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Invalid symbol, | is not allowed!");
			}
			return 1;
		}
		if(strcmp(cmd, "/abuildingentrance", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 1)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /abuildingentrance [buildingid]");
				return 1;
			}
			new id = strval(tmp);
			new Float:x,Float:y,Float:z;
			GetPlayerPos(playerid, x, y, z);
			Building[id][EnterX] = x;
			Building[id][EnterY] = y;
			Building[id][EnterZ] = z;
			Building[id][EnterWorld] = GetPlayerVirtualWorld(playerid);
			Building[id][EnterInterior] = GetPlayerInterior(playerid);
			Building[id][PickupID] = ChangePickupModel(Building[id][PickupID],1239,Building[id][EnterX], Building[id][EnterY], Building[id][EnterZ]);
			new Float:angle;
			GetPlayerFacingAngle(playerid, angle);
			Building[id][EnterAngle] = angle;
			SaveBData(id, "EnterX");
			SaveBData(id, "EnterY");
			SaveBData(id, "EnterZ");
			SaveBData(id, "EnterAngle");
			SaveBData(id, "EnterWorld");
			SaveBData(id, "EnterInterior");
			new form[128];
			format(form, sizeof(form), "[INFO:] You have set building ID: %d's location.", id);
			SendClientMessage(playerid, COLOR_ADMINCMD, form);
			return 1;
		}
		if(strcmp(cmd, "/wejsciebudynku", true) == 0)
		{
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /wejsciebudynku [id budynku]");
				return 1;
			}
			new id = strval(tmp);
			if (gPlayerData[playerid][pFaction] == 9)
			{
				new Float:x,Float:y,Float:z;
				GetPlayerPos(playerid, x, y, z);
				Building[id][EnterX] = x;
				Building[id][EnterY] = y;
				Building[id][EnterZ] = z;
				Building[id][EnterWorld] = GetPlayerVirtualWorld(playerid);
				Building[id][EnterInterior] = GetPlayerInterior(playerid);
				new Float:angle;
				GetPlayerFacingAngle(playerid, angle);
				Building[id][EnterAngle] = angle;
				Building[id][PickupID] = ChangePickupModel(Building[id][PickupID],1239,Building[id][EnterX], Building[id][EnterY], Building[id][EnterZ]);
				SaveBData(id, "EnterX");
				SaveBData(id, "EnterY");
				SaveBData(id, "EnterZ");
				SaveBData(id, "EnterAngle");
				SaveBData(id, "EnterWorld");
				SaveBData(id, "EnterInterior");
				new form[256];
				format(form, sizeof(form), "[INFO:] Ustawiles budynek ID: %d .", id);
				SendClientMessage(playerid, COLOR_ADMINCMD, form);
				
				// log
				format(form, sizeof(form), "[GOVERNMENT:] Building etrance set by %s for building ID %d", gPlayerData[playerid][pName], id);
				print(form);
				GovermentLog(form);	
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ urzednikiem.");
			}
			return 1;
		}
		if(strcmp(cmd, "/ksiazkatel", true) == 0)
		{
			if(PHaveItem(playerid, 1, 4))
			{
				tmp = strtok(cmdtext, idx);
				if(!strlen(tmp))
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /ksiazkatel [playerid/PartOName]");
					return 1;
				}
				giveplayerid = ReturnUser(tmp);
				if(IsPlayerConnected(giveplayerid))
				{
					if(giveplayerid != INVALID_PLAYER_ID)
					{
						if(gPlayerLogged[giveplayerid])
						{
							if(gPlayerData[giveplayerid][pListNumber] == 0)
							{
								SendClientMessage(playerid, COLOR_RED, "[INFO:] Ta osoba zastrzeg³a swoje numery");
								return 1;
							}
							new p1, p2, p3, p4, p5, p6, p7, p8, p9, p10;
							if(gPlayerData[giveplayerid][pItem1type] == 3 && (gPlayerData[giveplayerid][pItem1] == 3 || gPlayerData[giveplayerid][pItem1] == 4)) { p1 = gPlayerData[giveplayerid][pItem1param2]; gPhoneBookNumber[giveplayerid][ln1] = p1; }
							if(gPlayerData[giveplayerid][pItem2type] == 3 && (gPlayerData[giveplayerid][pItem2] == 3 || gPlayerData[giveplayerid][pItem2] == 4)) { p2 = gPlayerData[giveplayerid][pItem2param2]; gPhoneBookNumber[giveplayerid][ln2] = p2; }
							if(gPlayerData[giveplayerid][pItem3type] == 3 && (gPlayerData[giveplayerid][pItem3] == 3 || gPlayerData[giveplayerid][pItem3] == 4)) { p3 = gPlayerData[giveplayerid][pItem3param2]; gPhoneBookNumber[giveplayerid][ln3] = p3; }
							if(gPlayerData[giveplayerid][pItem4type] == 3 && (gPlayerData[giveplayerid][pItem4] == 3 || gPlayerData[giveplayerid][pItem4] == 4)) { p4 = gPlayerData[giveplayerid][pItem4param2]; gPhoneBookNumber[giveplayerid][ln4] = p4; }
							if(gPlayerData[giveplayerid][pItem5type] == 3 && (gPlayerData[giveplayerid][pItem5] == 3 || gPlayerData[giveplayerid][pItem5] == 4)) { p5 = gPlayerData[giveplayerid][pItem5param2]; gPhoneBookNumber[giveplayerid][ln5] = p5; }
							if(gPlayerData[giveplayerid][pItem6type] == 3 && (gPlayerData[giveplayerid][pItem6] == 3 || gPlayerData[giveplayerid][pItem6] == 4)) { p6 = gPlayerData[giveplayerid][pItem6param2]; gPhoneBookNumber[giveplayerid][ln6] = p6; }
							if(gPlayerData[giveplayerid][pItem7type] == 3 && (gPlayerData[giveplayerid][pItem7] == 3 || gPlayerData[giveplayerid][pItem7] == 4)) { p7 = gPlayerData[giveplayerid][pItem7param2]; gPhoneBookNumber[giveplayerid][ln7] = p7; }
							if(gPlayerData[giveplayerid][pItem8type] == 3 && (gPlayerData[giveplayerid][pItem8] == 3 || gPlayerData[giveplayerid][pItem8] == 4)) { p8 = gPlayerData[giveplayerid][pItem8param2]; gPhoneBookNumber[giveplayerid][ln8] = p8; }
							if(gPlayerData[giveplayerid][pItem9type] == 3 && (gPlayerData[giveplayerid][pItem9] == 3 || gPlayerData[giveplayerid][pItem9] == 4)) { p9 = gPlayerData[giveplayerid][pItem9param2]; gPhoneBookNumber[giveplayerid][ln9] = p9; }
							if(gPlayerData[giveplayerid][pItem10type] == 3 && (gPlayerData[giveplayerid][pItem10] == 3 || gPlayerData[giveplayerid][pItem10] == 4)) { p10 = gPlayerData[giveplayerid][pItem10param2]; gPhoneBookNumber[giveplayerid][ln10] = p10; }
							format(string, sizeof(string), "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d", p1, p2, p3, p4, p5, p6, p7, p8, p9, p10);
							ShowPlayerDialog(playerid,10,DIALOG_STYLE_LIST, "Nr telefonów", string,"Po³¹cz","Anuluj");
							PlayerActionMessage(playerid, 15.0, "przegl¹da ksi¹¿ke telefoniczn¹");
						}
						else
						{
							SendClientMessage(playerid, COLOR_LIGHTGREEN, "[B£¥D:] Ten gracz nie jest zalogowany");
							return 1;
						}
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Niew³aœciwe ID/nazwa gracza.");
					return 1;
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie posiadasz ksia¿ki telefonicznej ! Mo¿esz j¹ kupiæ w sklepie 24/7.");
			}
			return 1;
		}
		if(strcmp(cmd, "/agotobuilding", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 1)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /agotobuilding [buildingid]");
				return 1;
			}
			new id = strval(tmp);
			SetPlayerToPos(playerid,Building[id][EnterX],Building[id][EnterY],Building[id][EnterZ]);
			SetPlayerInterior(playerid,Building[id][EnterInterior]);
			SetPlayerVirtualWorld(playerid,Building[id][EnterWorld]);
			new form[128];
			format(form, sizeof(form), "[INFO:] You teleported to building ID: %d.", id);
			SendClientMessage(playerid, COLOR_ADMINCMD, form);
			return 1;
		}
		if(strcmp(cmd, "/abuildinglock", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /abuildinglock [buildingid]");
				return 1;
			}
			new id = strval(tmp);
			new form[128];
			if(Building[id][Locked] == 0)
			{
				Building[id][Locked] = 1;
				format(form, sizeof(form), "[INFO:] You have locked building ID: %d.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD, form);
			}
			else
			{
				Building[id][Locked] = 0;
				format(form, sizeof(form), "[INFO:] You have unlocked building ID: %d.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD, form);
			}
			SaveBData(id, "Locked");
			return 1;
		}
		if(strcmp(cmd, "/abuildingexit", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /abuildingexit [buildingid]");
				return 1;
			}
			new id = strval(tmp);
			new Float:x,Float:y,Float:z;
			GetPlayerPos(playerid, x, y, z);
			Building[id][ExitX] = x;
			Building[id][ExitY] = y;
			Building[id][ExitZ] = z;
			Building[id][ExitInterior] = GetPlayerInterior(playerid);
			new Float:angle;
			GetPlayerFacingAngle(playerid, angle);
			Building[id][ExitAngle] = angle;
			SaveBData(id, "ExitX");
			SaveBData(id, "ExitY");
			SaveBData(id, "ExitZ");
			SaveBData(id, "ExitAngle");
			SaveBData(id, "ExitInterior");
			new form[128];
			format(form, sizeof(form), "[INFO:] You have set building ID: %d's exit location.", id);
			SendClientMessage(playerid, COLOR_ADMINCMD, form);
			return 1;
		}
		if(strcmp(cmd, "/abuildingname", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /abuildingname [buildingid] [name]");
				return 1;
			}
			new id = strval(tmp);
			new length = strlen(cmdtext);
			while ((idx < length) && (cmdtext[idx] <= ' '))
			{
				idx++;
			}
			new offset = idx;
			new result[64];
			while ((idx < length) && ((idx - offset) < (sizeof(result) - 1)))
			{
				result[idx - offset] = cmdtext[idx];
				idx++;
			}
			result[idx - offset] = EOS;
			if(!strlen(result))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /abuildingname [buildingid] [name]");
				return 1;
			}
			if(strfind( result , "|" , true ) == -1)
			{
				strmid(Building[id][BuildingName], (result), 0, strlen((result)), 128);
				format(string, sizeof(string), "[INFO:] You have set Building ID: %d's name to %s", id,(result));
				SendClientMessage(playerid, COLOR_ADMINCMD, string);
				SaveBData(id, "BuildingName");
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Invalid symbol, | is not allowed!");
			}
			return 1;
		}
		if(strcmp(cmd, "/nazwabudynku", true) == 0)
		{
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /nazwabudynku [buildingid] [name]");
				return 1;
			}
			new id = strval(tmp);
			if (gPlayerData[playerid][pFaction] == 9)
			{
				new length = strlen(cmdtext);
				while ((idx < length) && (cmdtext[idx] <= ' '))
				{
					idx++;
				}
				new offset = idx;
				new result[64];
				while ((idx < length) && ((idx - offset) < (sizeof(result) - 1)))
				{
					result[idx - offset] = cmdtext[idx];
					idx++;
				}
				result[idx - offset] = EOS;
				if(!strlen(result))
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /nazwabudynku [buildingid] [name]");
					return 1;
				}
				strmid(Building[id][BuildingName], (result), 0, strlen((result)), 128);
				format(string, sizeof(string), "[INFO:] You have set Building ID: %d's name to %s", id,(result));
				SendClientMessage(playerid, COLOR_ADMINCMD, string);
				SaveBData(id, "BuildingName");
				
				format(string, sizeof(string), "[GOVERNMENT:] Building name change by: %s to %s, building ID: %d", gPlayerData[playerid][pName], result, id);
				GovermentLog(string);
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] nie jesteœ urzednikiem.");
			}
			return 1;
		}
		if(strcmp(cmd, "/abuildingfee", true) == 0)
		{
			if (gPlayerData[playerid][pAdmin] < 4)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /abuildingfee [buildingid] [amount]");
				return 1;
			}
			new id;
			id = strval(tmp);
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /abuildingfee [buildingid] [amount]");
				return 1;
			}
			new id2;
			id2 = strval(tmp);

			Building[id][EntranceFee] = id2;
			new form[128];
			format(form, sizeof form, "You've set Building ID: %d's Entrance Fee to %d.", id,id2);
			SendClientMessage(playerid, COLOR_ADMINCMD,form);
			SaveBData(id, "EntranceFee");
			return 1;
		}
		if(strcmp(cmd, "/agotobank", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 1)
				return 0;
			SetPlayerToPos(playerid,BankPosition[X],BankPosition[Y],BankPosition[Z]);
			SetPlayerInterior(playerid,BankPosition[Interior]);
			SetPlayerVirtualWorld(playerid,BankPosition[World]);
			SetPlayerFacingAngle(playerid,BankPosition[Angle]);
			SendClientMessage(playerid, COLOR_ADMINCMD, "[INFO:] You teleported to the Bank Position.");
			return 1;
		}
		if(strcmp(cmd, "/agotodrivingtestpos", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			SetPlayerToPos(playerid,DrivingTestPosition[X],DrivingTestPosition[Y],DrivingTestPosition[Z]);
			SetPlayerInterior(playerid,DrivingTestPosition[Interior]);
			SetPlayerVirtualWorld(playerid,DrivingTestPosition[World]);
			SetPlayerFacingAngle(playerid,DrivingTestPosition[Angle]);
			SendClientMessage(playerid, COLOR_ADMINCMD, "[INFO:] You teleported to the driving test position.");
			return 1;
		}
		if(strcmp(cmd, "/agotoflyingtestpos", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			SetPlayerToPos(playerid,FlyingTestPosition[X],FlyingTestPosition[Y],FlyingTestPosition[Z]);
			SetPlayerInterior(playerid,FlyingTestPosition[Interior]);
			SetPlayerVirtualWorld(playerid,FlyingTestPosition[World]);
			SetPlayerFacingAngle(playerid,FlyingTestPosition[Angle]);
			SendClientMessage(playerid, COLOR_ADMINCMD, "[INFO:] You teleported to the flying test position.");
			return 1;
		}
		//===============================================[DYNAMIC FACTION MATERIALS & DRUGS STORAGE]=================================
		if(strcmp(cmd, "/agotofmatsstorage", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			SetPlayerToPos(playerid,FactionMaterialsStorage[X],FactionMaterialsStorage[Y],FactionMaterialsStorage[Z]);
			SetPlayerInterior(playerid,FactionMaterialsStorage[Interior]);
			SetPlayerVirtualWorld(playerid,FactionMaterialsStorage[World]);
			SetPlayerFacingAngle(playerid,FactionMaterialsStorage[Angle]);
			SendClientMessage(playerid, COLOR_ADMINCMD, "[INFO:] You teleported to the faction materials storage location.");
			return 1;
		}
		if(strcmp(cmd, "/afactionmatsstorage", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			new Float:x,Float:y,Float:z;
			GetPlayerPos(playerid, x, y, z);
			new Float:angle;
			GetPlayerFacingAngle(playerid, angle);
			FactionMaterialsStorage[X] = x;
			FactionMaterialsStorage[Y] = y;
			FactionMaterialsStorage[Z] = z;
			FactionMaterialsStorage[World] = GetPlayerVirtualWorld(playerid);
			FactionMaterialsStorage[Interior] = GetPlayerInterior(playerid);
			FactionMaterialsStorage[Angle] = angle;
			FactionMaterialsStorage[PickupID] = ChangePickupModel(FactionMaterialsStorage[PickupID],1239,FactionMaterialsStorage[X],FactionMaterialsStorage[Y],FactionMaterialsStorage[Z]);
			SaveFactionMaterialsStorage();
			SendClientMessage(playerid, COLOR_ADMINCMD, "You have successfully set the Faction Materials Storage.");
			return 1;
		}
		if(strcmp(cmd, "/agotofdrugsstorage", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			SetPlayerToPos(playerid,FactionDrugsStorage[X],FactionDrugsStorage[Y],FactionDrugsStorage[Z]);
			SetPlayerInterior(playerid,FactionDrugsStorage[Interior]);
			SetPlayerVirtualWorld(playerid,FactionDrugsStorage[World]);
			SetPlayerFacingAngle(playerid,FactionDrugsStorage[Angle]);
			SendClientMessage(playerid, COLOR_ADMINCMD, "[INFO:] You teleported to the faction drugs storage location.");
			return 1;
		}
		if(strcmp(cmd, "/afactiondrugsstorage", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			new Float:x,Float:y,Float:z;
			GetPlayerPos(playerid, x, y, z);
			new Float:angle;
			GetPlayerFacingAngle(playerid, angle);
			FactionDrugsStorage[X] = x;
			FactionDrugsStorage[Y] = y;
			FactionDrugsStorage[Z] = z;
			FactionDrugsStorage[World] = GetPlayerVirtualWorld(playerid);
			FactionDrugsStorage[Interior] = GetPlayerInterior(playerid);
			FactionDrugsStorage[Angle] = angle;
			FactionDrugsStorage[PickupID] = ChangePickupModel(FactionDrugsStorage[PickupID],1239,FactionDrugsStorage[X],FactionDrugsStorage[Y],FactionDrugsStorage[Z]);
			SaveFactionDrugsStorage();
			SendClientMessage(playerid, COLOR_ADMINCMD, "You have successfully set the Faction Drugs Storage.");
			return 1;
		}
		if(strcmp(cmd, "/abankpos", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			new Float:x,Float:y,Float:z;
			GetPlayerPos(playerid, x, y, z);
			new Float:angle;
			GetPlayerFacingAngle(playerid, angle);
			BankPosition[X] = x;
			BankPosition[Y] = y;
			BankPosition[Z] = z;
			BankPosition[World] = GetPlayerVirtualWorld(playerid);
			BankPosition[Interior] = GetPlayerInterior(playerid);
			BankPosition[Angle] = angle;
			BankPosition[PickupID] = ChangePickupModel(BankPosition[PickupID],1239,BankPosition[X],BankPosition[Y],BankPosition[Z]);
			SaveBankPosition();
			SendClientMessage(playerid, COLOR_ADMINCMD, "You have successfully set the Bank Position.");
			return 1;
		}
		if(strcmp(cmd, "/abankpos2", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			new Float:x,Float:y,Float:z;
			GetPlayerPos(playerid, x, y, z);
			new Float:angle;
			GetPlayerFacingAngle(playerid, angle);
			BankPosition2[X] = x;
			BankPosition2[Y] = y;
			BankPosition2[Z] = z;
			BankPosition2[World] = GetPlayerVirtualWorld(playerid);
			BankPosition2[Interior] = GetPlayerInterior(playerid);
			BankPosition2[Angle] = angle;
			BankPosition2[PickupID] = ChangePickupModel(BankPosition2[PickupID],1239,BankPosition2[X],BankPosition2[Y],BankPosition2[Z]);
			SaveBankPosition2();
			SendClientMessage(playerid, COLOR_ADMINCMD, "You have successfully set the Bank Position.");
			return 1;
		}
		if(strcmp(cmd, "/adetectivejobpos", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			new Float:x,Float:y,Float:z;
			GetPlayerPos(playerid, x, y, z);
			new Float:angle;
			GetPlayerFacingAngle(playerid, angle);
			DetectiveJobPosition[X] = x;
			DetectiveJobPosition[Y] = y;
			DetectiveJobPosition[Z] = z;
			DetectiveJobPosition[World] = GetPlayerVirtualWorld(playerid);
			DetectiveJobPosition[Interior] = GetPlayerInterior(playerid);
			DetectiveJobPosition[Angle] = angle;
			DetectiveJobPosition[PickupID] = ChangePickupModel(DetectiveJobPosition[PickupID],1239,DetectiveJobPosition[X],DetectiveJobPosition[Y],DetectiveJobPosition[Z]);
			SaveDetectiveJob();
			SendClientMessage(playerid, COLOR_ADMINCMD, "You have successfully set the Detective Job.");
			return 1;
		}
		if(strcmp(cmd, "/alawyerjobpos", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			new Float:x,Float:y,Float:z;
			GetPlayerPos(playerid, x, y, z);
			new Float:angle;
			GetPlayerFacingAngle(playerid, angle);
			LawyerJobPosition[X] = x;
			LawyerJobPosition[Y] = y;
			LawyerJobPosition[Z] = z;
			LawyerJobPosition[World] = GetPlayerVirtualWorld(playerid);
			LawyerJobPosition[Interior] = GetPlayerInterior(playerid);
			LawyerJobPosition[Angle] = angle;
			LawyerJobPosition[PickupID] = ChangePickupModel(LawyerJobPosition[PickupID],1239,LawyerJobPosition[X],LawyerJobPosition[Y],LawyerJobPosition[Z]);
			SaveLawyerJob();
			SendClientMessage(playerid, COLOR_ADMINCMD, "You have successfully set the Lawyer Job.");
			return 1;
		}
		if(strcmp(cmd, "/askillpospis", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			new Float:x,Float:y,Float:z;
			GetPlayerPos(playerid, x, y, z);
			SkillPosition[XPis] = x;
			SkillPosition[YPis] = y;
			SkillPosition[ZPis] = z;
			SkillPosition[PickupIDPis] = ChangePickupModel(SkillPosition[PickupIDPis],1239,SkillPosition[XPis],SkillPosition[YPis],SkillPosition[ZPis]);
			SaveSkillPositionb();
			SendClientMessage(playerid, COLOR_ADMINCMD, "You have successfully set the Skill Position Pis.");
			return 1;
		}
		if(strcmp(cmd, "/askillpossil", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			new Float:x,Float:y,Float:z;
			GetPlayerPos(playerid, x, y, z);
			SkillPosition[XSil] = x;
			SkillPosition[YSil] = y;
			SkillPosition[ZSil] = z;
			SkillPosition[PickupIDSil] = ChangePickupModel(SkillPosition[PickupIDSil],1239,SkillPosition[XSil],SkillPosition[YSil],SkillPosition[ZSil]);
			SaveSkillPositionb();
			SendClientMessage(playerid, COLOR_ADMINCMD, "You have successfully set the Skill Position Sil.");
			return 1;
		}
		if(strcmp(cmd, "/askillposDes", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			new Float:x,Float:y,Float:z;
			GetPlayerPos(playerid, x, y, z);
			SkillPosition[XDes] = x;
			SkillPosition[YDes] = y;
			SkillPosition[ZDes] = z;
			SkillPosition[PickupIDDes] = ChangePickupModel(SkillPosition[PickupIDDes],1239,SkillPosition[XDes],SkillPosition[YDes],SkillPosition[ZDes]);
			SaveSkillPositionb();
			SendClientMessage(playerid, COLOR_ADMINCMD, "You have successfully set the Skill Position Des.");
			return 1;
		}
		if(strcmp(cmd, "/askillposSho", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			new Float:x,Float:y,Float:z;
			GetPlayerPos(playerid, x, y, z);
			SkillPosition[XSho] = x;
			SkillPosition[YSho] = y;
			SkillPosition[ZSho] = z;
			SkillPosition[PickupIDSho] = ChangePickupModel(SkillPosition[PickupIDSho],1239, SkillPosition[XSho],SkillPosition[YSho],SkillPosition[ZSho]);
			SaveSkillPositionb();
			SendClientMessage(playerid, COLOR_ADMINCMD, "You have successfully set the Skill Position Sho.");
			return 1;
		}
		if(strcmp(cmd, "/askillposSha", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			new Float:x,Float:y,Float:z;
			GetPlayerPos(playerid, x, y, z);
			SkillPosition[XSha] = x;
			SkillPosition[YSha] = y;
			SkillPosition[ZSha] = z;
			SkillPosition[PickupIDSha] = ChangePickupModel(SkillPosition[PickupIDSha],1239,SkillPosition[XSha],SkillPosition[YSha],SkillPosition[ZSha]);
			SaveSkillPositionc();
			SendClientMessage(playerid, COLOR_ADMINCMD, "You have successfully set the Skill Position Sha.");
			return 1;
		}
		if(strcmp(cmd, "/askillposSpa", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			new Float:x,Float:y,Float:z;
			GetPlayerPos(playerid, x, y, z);
			SkillPosition[XSpa] = x;
			SkillPosition[YSpa] = y;
			SkillPosition[ZSpa] = z;
			SkillPosition[PickupIDSpa] = ChangePickupModel(SkillPosition[PickupIDSpa],1239,SkillPosition[XSpa],SkillPosition[YSpa],SkillPosition[ZSpa]);
			SaveSkillPositionc();
			SendClientMessage(playerid, COLOR_ADMINCMD, "You have successfully set the Skill Position Spa.");
			return 1;
		}
		if(strcmp(cmd, "/askillposMic", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			new Float:x,Float:y,Float:z;
			GetPlayerPos(playerid, x, y, z);
			SkillPosition[XMic] = x;
			SkillPosition[YMic] = y;
			SkillPosition[ZMic] = z;
			SkillPosition[PickupIDMic] = ChangePickupModel(SkillPosition[PickupIDMic],1239,SkillPosition[XMic],SkillPosition[YMic],SkillPosition[ZMic]);
			SaveSkillPosition();
			SendClientMessage(playerid, COLOR_ADMINCMD, "You have successfully set the Skill Position Mic.");
			return 1;
		}
		if(strcmp(cmd, "/askillposMp5", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			new Float:x,Float:y,Float:z;
			GetPlayerPos(playerid, x, y, z);
			SkillPosition[XMp5] = x;
			SkillPosition[YMp5] = y;
			SkillPosition[ZMp5] = z;
			SkillPosition[PickupIDMp5] = ChangePickupModel(SkillPosition[PickupIDMp5],1239,SkillPosition[XMp5],SkillPosition[YMp5],SkillPosition[ZMp5]);
			SaveSkillPosition();
			SendClientMessage(playerid, COLOR_ADMINCMD, "You have successfully set the Skill Position Mp5.");
			return 1;
		}
		if(strcmp(cmd, "/askillposAk", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			new Float:x,Float:y,Float:z;
			GetPlayerPos(playerid, x, y, z);
			SkillPosition[XAk] = x;
			SkillPosition[YAk] = y;
			SkillPosition[ZAk] = z;
			SkillPosition[PickupIDAk] = ChangePickupModel(SkillPosition[PickupIDAk],1239,SkillPosition[XAk],SkillPosition[YAk],SkillPosition[ZAk]);
			SaveSkillPosition();
			SendClientMessage(playerid, COLOR_ADMINCMD, "You have successfully set the Skill Position Ak.");
			return 1;
		}
		if(strcmp(cmd, "/askillposM4", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			new Float:x,Float:y,Float:z;
			GetPlayerPos(playerid, x, y, z);
			SkillPosition[XM4] = x;
			SkillPosition[YM4] = y;
			SkillPosition[ZM4] = z;
			SkillPosition[PickupIDM4] = ChangePickupModel(SkillPosition[PickupIDM4],1239, SkillPosition[XM4],SkillPosition[YM4],SkillPosition[ZM4]);
			SaveSkillPositionc();
			SendClientMessage(playerid, COLOR_ADMINCMD, "You have successfully set the Skill Position M4.");
			return 1;
		}
		if(strcmp(cmd, "/askillposSni", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			new Float:x,Float:y,Float:z;
			GetPlayerPos(playerid, x, y, z);
			SkillPosition[XSni] = x;
			SkillPosition[YSni] = y;
			SkillPosition[ZSni] = z;
			SkillPosition[PickupIDSni] = ChangePickupModel(SkillPosition[PickupIDSni],1239,SkillPosition[XSni],SkillPosition[YSni],SkillPosition[ZSni]);
			SaveSkillPositionc();
			SendClientMessage(playerid, COLOR_ADMINCMD, "You have successfully set the Skill Position Sni.");
			return 1;
		}
		if(strcmp(cmd, "/askillposAng", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			new Float:x,Float:y,Float:z;
			GetPlayerPos(playerid, x, y, z);
			SkillPosition[XAng] = x;
			SkillPosition[YAng] = y;
			SkillPosition[ZAng] = z;
			SkillPosition[PickupIDAng] = ChangePickupModel(SkillPosition[PickupIDAng],1239,SkillPosition[XAng],SkillPosition[YAng],SkillPosition[ZAng]);
			SaveSkillPositiond();
			SendClientMessage(playerid, COLOR_ADMINCMD, "You have successfully set the Skill Position Ang.");
			return 1;
		}
		if(strcmp(cmd, "/askillposWf", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			new Float:x,Float:y,Float:z;
			GetPlayerPos(playerid, x, y, z);
			SkillPosition[XWf] = x;
			SkillPosition[YWf] = y;
			SkillPosition[ZWf] = z;
			SkillPosition[PickupIDWf] = ChangePickupModel(SkillPosition[PickupIDWf],1239,SkillPosition[XWf],SkillPosition[YWf],SkillPosition[ZWf]);
			SaveSkillPositiond();
			SendClientMessage(playerid, COLOR_ADMINCMD, "You have successfully set the Skill Position Wf.");
			return 1;
		}
		if(strcmp(cmd, "/askillposMat", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			new Float:x,Float:y,Float:z;
			GetPlayerPos(playerid, x, y, z);
			SkillPosition[XMat] = x;
			SkillPosition[YMat] = y;
			SkillPosition[ZMat] = z;
			SkillPosition[PickupIDMat] = ChangePickupModel(SkillPosition[PickupIDMat],1239,SkillPosition[XMat],SkillPosition[YMat],SkillPosition[ZMat]);
			SaveSkillPositiond();
			SendClientMessage(playerid, COLOR_ADMINCMD, "You have successfully set the Skill Position Mat.");
			return 1;
		}
		if(strcmp(cmd, "/askillposPol", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			new Float:x,Float:y,Float:z;
			GetPlayerPos(playerid, x, y, z);
			SkillPosition[XPol] = x;
			SkillPosition[YPol] = y;
			SkillPosition[ZPol] = z;
			SkillPosition[PickupIDPol] = ChangePickupModel(SkillPosition[PickupIDPol],1239,SkillPosition[XPol],SkillPosition[YPol],SkillPosition[ZPol]);
			SaveSkillPositiond();
			SendClientMessage(playerid, COLOR_ADMINCMD, "You have successfully set the Skill Position Pol.");
			return 1;
		}
		if(strcmp(cmd, "/askillposHis", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			new Float:x,Float:y,Float:z;
			GetPlayerPos(playerid, x, y, z);
			SkillPosition[XHis] = x;
			SkillPosition[YHis] = y;
			SkillPosition[ZHis] = z;
			SkillPosition[PickupIDHis] = ChangePickupModel(SkillPosition[PickupIDHis],1239,SkillPosition[XHis],SkillPosition[YHis],SkillPosition[ZHis]);
			SaveSkillPosition();
			SendClientMessage(playerid, COLOR_ADMINCMD, "You have successfully set the Skill Position His.");
			return 1;
		}
		if(strcmp(cmd, "/askillposBio", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			new Float:x,Float:y,Float:z;
			GetPlayerPos(playerid, x, y, z);
			SkillPosition[XBio] = x;
			SkillPosition[YBio] = y;
			SkillPosition[ZBio] = z;
			SkillPosition[PickupIDBio] = ChangePickupModel(SkillPosition[PickupIDBio],1239,SkillPosition[XBio],SkillPosition[YBio],SkillPosition[ZBio]);
			SaveSkillPosition();
			SendClientMessage(playerid, COLOR_ADMINCMD, "You have successfully set the Skill Position Bio.");
			return 1;
		}
		if(strcmp(cmd, "/askillposFiz", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			new Float:x,Float:y,Float:z;
			GetPlayerPos(playerid, x, y, z);
			SkillPosition[XFiz] = x;
			SkillPosition[YFiz] = y;
			SkillPosition[ZFiz] = z;
			SkillPosition[PickupIDBio] = ChangePickupModel(SkillPosition[PickupIDFiz],1239,SkillPosition[XFiz],SkillPosition[YFiz],SkillPosition[ZFiz]);
			SaveSkillPosition();
			SendClientMessage(playerid, COLOR_ADMINCMD, "You have successfully set the Skill Position Fiz.");
			return 1;
		}
		if(strcmp(cmd, "/adrugjobpos3", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			new Float:x,Float:y,Float:z;
			GetPlayerPos(playerid, x, y, z);
			new Float:angle;
			GetPlayerFacingAngle(playerid, angle);
			DrugJob[DeliverX] = x;
			DrugJob[DeliverY] = y;
			DrugJob[DeliverZ] = z;
			DrugJob[DeliverWorld] = GetPlayerVirtualWorld(playerid);
			DrugJob[DeliverInterior] = GetPlayerInterior(playerid);
			DrugJob[DeliverAngle] = angle;
			DrugJob[DeliverPickupID] = ChangePickupModel(DrugJob[DeliverPickupID],1239,DrugJob[DeliverX],DrugJob[DeliverY],DrugJob[DeliverZ]);
			SaveDrugJob();
			SendClientMessage(playerid, COLOR_ADMINCMD, "You have successfully set the Drug Job Deliver Position.");
			return 1;
		}
		if(strcmp(cmd, "/aRapistjobpos", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			new Float:x,Float:y,Float:z;
			GetPlayerPos(playerid, x, y, z);
			new Float:angle;
			GetPlayerFacingAngle(playerid, angle);
			RapistJob[TakeJobX] = x;
			RapistJob[TakeJobY] = y;
			RapistJob[TakeJobZ] = z;
			RapistJob[TakeJobWorld] = GetPlayerVirtualWorld(playerid);
			RapistJob[TakeJobInterior] = GetPlayerInterior(playerid);
			RapistJob[TakeJobAngle] = angle;
			RapistJob[TakeJobPickupID] = ChangePickupModel(RapistJob[TakeJobPickupID],1239,RapistJob[TakeJobX],RapistJob[TakeJobY],RapistJob[TakeJobZ]);
			SaveRapistJob();
			SendClientMessage(playerid, COLOR_ADMINCMD, "You have successfully set the Rapist job.");
			return 1;
		}
		if(strcmp(cmd, "/aWhorejobpos", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			new Float:x,Float:y,Float:z;
			GetPlayerPos(playerid, x, y, z);
			new Float:angle;
			GetPlayerFacingAngle(playerid, angle);
			WhoreJob[TakeJobX] = x;
			WhoreJob[TakeJobY] = y;
			WhoreJob[TakeJobZ] = z;
			WhoreJob[TakeJobWorld] = GetPlayerVirtualWorld(playerid);
			WhoreJob[TakeJobInterior] = GetPlayerInterior(playerid);
			WhoreJob[TakeJobAngle] = angle;
			WhoreJob[TakeJobPickupID] = ChangePickupModel(WhoreJob[TakeJobPickupID],1239,WhoreJob[TakeJobX],WhoreJob[TakeJobY],WhoreJob[TakeJobZ]);
			SaveWhoreJob();
			SendClientMessage(playerid, COLOR_ADMINCMD, "You have successfully set the Whore job.");
			return 1;
		}
		if(strcmp(cmd, "/aDirjobpos", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			new Float:x,Float:y,Float:z;
			GetPlayerPos(playerid, x, y, z);
			new Float:angle;
			GetPlayerFacingAngle(playerid, angle);
			DirJob[TakeJobX] = x;
			DirJob[TakeJobY] = y;
			DirJob[TakeJobZ] = z;
			DirJob[TakeJobWorld] = GetPlayerVirtualWorld(playerid);
			DirJob[TakeJobInterior] = GetPlayerInterior(playerid);
			DirJob[TakeJobAngle] = angle;
			DirJob[TakeJobPickupID] = ChangePickupModel(DirJob[TakeJobPickupID],1239,DirJob[TakeJobX],DirJob[TakeJobY],DirJob[TakeJobZ]);
			SaveDirJob();
			return 1;
		}
		if(strcmp(cmd, "/aStuntjobpos", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			new Float:x,Float:y,Float:z;
			GetPlayerPos(playerid, x, y, z);
			new Float:angle;
			GetPlayerFacingAngle(playerid, angle);
			StuntJob[TakeJobX] = x;
			StuntJob[TakeJobY] = y;
			StuntJob[TakeJobZ] = z;
			StuntJob[TakeJobWorld] = GetPlayerVirtualWorld(playerid);
			StuntJob[TakeJobInterior] = GetPlayerInterior(playerid);
			StuntJob[TakeJobAngle] = angle;
			StuntJob[TakeJobPickupID] = ChangePickupModel(StuntJob[TakeJobPickupID],1239,StuntJob[TakeJobX],StuntJob[TakeJobY],StuntJob[TakeJobZ]);
			SaveStuntJob();
			SendClientMessage(playerid, COLOR_ADMINCMD, "You have successfully set the Stunt job.");
			return 1;
		}
		if(strcmp(cmd, "/aCarjackjobpos", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			new Float:x,Float:y,Float:z;
			GetPlayerPos(playerid, x, y, z);
			new Float:angle;
			GetPlayerFacingAngle(playerid, angle);
			CarjackJob[TakeJobX] = x;
			CarjackJob[TakeJobY] = y;
			CarjackJob[TakeJobZ] = z;
			CarjackJob[TakeJobWorld] = GetPlayerVirtualWorld(playerid);
			CarjackJob[TakeJobInterior] = GetPlayerInterior(playerid);
			CarjackJob[TakeJobAngle] = angle;
			StuntJob[TakeJobPickupID] = ChangePickupModel(CarjackJob[TakeJobPickupID],1239,CarjackJob[TakeJobX],CarjackJob[TakeJobY],CarjackJob[TakeJobZ]);
			SaveCarjackJob();
			SendClientMessage(playerid, COLOR_ADMINCMD, "You have successfully set the Carjack job.");
			return 1;
		}
		if(strcmp(cmd, "/aBodyjobpos", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			new Float:x,Float:y,Float:z;
			GetPlayerPos(playerid, x, y, z);
			new Float:angle;
			GetPlayerFacingAngle(playerid, angle);
			BodyJob[TakeJobX] = x;
			BodyJob[TakeJobY] = y;
			BodyJob[TakeJobZ] = z;
			BodyJob[TakeJobWorld] = GetPlayerVirtualWorld(playerid);
			BodyJob[TakeJobInterior] = GetPlayerInterior(playerid);
			BodyJob[TakeJobAngle] = angle;
			BodyJob[TakeJobPickupID] = ChangePickupModel(BodyJob[TakeJobPickupID],1239,BodyJob[TakeJobX],BodyJob[TakeJobY],BodyJob[TakeJobZ]);
			SaveBodyJob();
			SendClientMessage(playerid, COLOR_ADMINCMD, "You have successfully set the Body job.");
			return 1;
		}

		if(strcmp(cmd, "/aBoxerjobpos", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			new Float:x,Float:y,Float:z;
			GetPlayerPos(playerid, x, y, z);
			new Float:angle;
			GetPlayerFacingAngle(playerid, angle);
			BoxerJob[TakeJobX] = x;
			BoxerJob[TakeJobY] = y;
			BoxerJob[TakeJobZ] = z;
			BoxerJob[TakeJobWorld] = GetPlayerVirtualWorld(playerid);
			BoxerJob[TakeJobInterior] = GetPlayerInterior(playerid);
			BoxerJob[TakeJobAngle] = angle;
			BodyJob[TakeJobPickupID] = ChangePickupModel(BoxerJob[TakeJobPickupID],1239,BoxerJob[TakeJobX],BoxerJob[TakeJobY],BoxerJob[TakeJobZ]);
			SaveBoxerJob();
			SendClientMessage(playerid, COLOR_ADMINCMD, "You have successfully set the Boxer job.");
			return 1;
		}
		if(strcmp(cmd, "/aproductjobpos", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			new Float:x,Float:y,Float:z;
			GetPlayerPos(playerid, x, y, z);
			new Float:angle;
			GetPlayerFacingAngle(playerid, angle);
			ProductsSellerJob[TakeJobX] = x;
			ProductsSellerJob[TakeJobY] = y;
			ProductsSellerJob[TakeJobZ] = z;
			ProductsSellerJob[TakeJobWorld] = GetPlayerVirtualWorld(playerid);
			ProductsSellerJob[TakeJobInterior] = GetPlayerInterior(playerid);
			ProductsSellerJob[TakeJobAngle] = angle;
			ProductsSellerJob[TakeJobPickupID] = ChangePickupModel(ProductsSellerJob[TakeJobPickupID],1239,ProductsSellerJob[TakeJobX],ProductsSellerJob[TakeJobY],ProductsSellerJob[TakeJobZ]);
			SaveProductsSellerJob();
			SendClientMessage(playerid, COLOR_ADMINCMD, "You have successfully set the products seller job.");
			return 1;
		}
		if(strcmp(cmd, "/agunjobpos", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			new Float:x,Float:y,Float:z;
			GetPlayerPos(playerid, x, y, z);
			new Float:angle;
			GetPlayerFacingAngle(playerid, angle);
			GunJob[TakeJobX] = x;
			GunJob[TakeJobY] = y;
			GunJob[TakeJobZ] = z;
			GunJob[TakeJobWorld] = GetPlayerVirtualWorld(playerid);
			GunJob[TakeJobInterior] = GetPlayerInterior(playerid);
			GunJob[TakeJobAngle] = angle;
			GunJob[TakeJobPickupID] = ChangePickupModel(GunJob[TakeJobPickupID],1239,GunJob[TakeJobX],GunJob[TakeJobY],GunJob[TakeJobZ]);
			SaveGunJob();
			SendClientMessage(playerid, COLOR_ADMINCMD, "You have successfully set the Gun Job Position.");
			return 1;
		}
		if(strcmp(cmd, "/agunjobpos2", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			new Float:x,Float:y,Float:z;
			GetPlayerPos(playerid, x, y, z);
			new Float:angle;
			GetPlayerFacingAngle(playerid, angle);
			GunJob[BuyPackagesX] = x;
			GunJob[BuyPackagesY] = y;
			GunJob[BuyPackagesZ] = z;
			GunJob[BuyPackagesWorld] = GetPlayerVirtualWorld(playerid);
			GunJob[BuyPackagesInterior] = GetPlayerInterior(playerid);
			GunJob[BuyPackagesAngle] = angle;
			GunJob[BuyPackagesPickupID] = ChangePickupModel(GunJob[BuyPackagesPickupID],1239,GunJob[BuyPackagesX],GunJob[BuyPackagesY],GunJob[BuyPackagesZ]);
			SaveGunJob();
			SendClientMessage(playerid, COLOR_ADMINCMD, "You have successfully set the Gun Job Materials Packages Buy Position.");
			return 1;
		}
		if(strcmp(cmd, "/agunjobpos3", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			new Float:x,Float:y,Float:z;
			GetPlayerPos(playerid, x, y, z);
			new Float:angle;
			GetPlayerFacingAngle(playerid, angle);
			GunJob[DeliverX] = x;
			GunJob[DeliverY] = y;
			GunJob[DeliverZ] = z;
			GunJob[DeliverWorld] = GetPlayerVirtualWorld(playerid);
			GunJob[DeliverInterior] = GetPlayerInterior(playerid);
			GunJob[DeliverAngle] = angle;
			GunJob[DeliverPickupID] = ChangePickupModel(GunJob[DeliverPickupID],1239,GunJob[DeliverX],GunJob[DeliverY],GunJob[DeliverZ]);
			SaveGunJob();
			SendClientMessage(playerid, COLOR_ADMINCMD, "You have successfully set the Gun Job Materials Deliver Position.");
			return 1;
		}
		if(strcmp(cmd, "/abusjobpos", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			new Float:x, Float:y, Float:z;
			GetPlayerPos(playerid, x, y, z);
			new Float:angle;
			GetPlayerFacingAngle(playerid, angle);
			BusJob[TakeJobX] = x;
			BusJob[TakeJobY] = y;
			BusJob[TakeJobZ] = z;
			BusJob[TakeJobWorld]= GetPlayerVirtualWorld(playerid);
			BusJob[TakeJobInterior] = GetPlayerInterior(playerid);
			BusJob[TakeJobAngle] = angle;
			BusJob[TakeJobPickupID] = ChangePickupModel(BusJob[TakeJobPickupID],1239, BusJob[TakeJobX], BusJob[TakeJobY], BusJob[TakeJobZ]);
			SaveBusJob();
			SendClientMessage(playerid, COLOR_ADMINCMD, "You have successfully set the Bus Job Position.");
			return 1;
		}
		if(strcmp(cmd, "/amzgkjobpos", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			new Float:x, Float:y, Float:z;
			GetPlayerPos(playerid, x, y, z);
			new Float:angle;
			GetPlayerFacingAngle(playerid, angle);
			MzgkJob[TakeJobX] = x;
			MzgkJob[TakeJobY] = y;
			MzgkJob[TakeJobZ] = z;
			MzgkJob[TakeJobWorld]= GetPlayerVirtualWorld(playerid);
			MzgkJob[TakeJobInterior] = GetPlayerInterior(playerid);
			MzgkJob[TakeJobAngle] = angle;
			MzgkJob[TakeJobPickupID] = ChangePickupModel(MzgkJob[TakeJobPickupID],1239, MzgkJob[TakeJobX], MzgkJob[TakeJobY], MzgkJob[TakeJobZ]);
			SaveMzgkJob();
			SendClientMessage(playerid, COLOR_ADMINCMD, "You have successfully set the Mzgk Job Position.");
			return 1;
		}
		if(strcmp(cmd, "/asweeperjobpos", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			new Float:x, Float:y, Float:z;
			GetPlayerPos(playerid, x, y, z);
			new Float:angle;
			GetPlayerFacingAngle(playerid, angle);
			SweeperJob[TakeJobX] = x;
			SweeperJob[TakeJobY] = y;
			SweeperJob[TakeJobZ] = z;
			SweeperJob[TakeJobWorld]= GetPlayerVirtualWorld(playerid);
			SweeperJob[TakeJobInterior] = GetPlayerInterior(playerid);
			SweeperJob[TakeJobAngle] = angle;
			SweeperJob[TakeJobPickupID] = ChangePickupModel(SweeperJob[TakeJobPickupID], 1239,SweeperJob[TakeJobX], SweeperJob[TakeJobY], SweeperJob[TakeJobZ]);
			SaveSweeperJob();
			SendClientMessage(playerid, COLOR_ADMINCMD, "You have successfully set the Sweeper Job Position.");
			return 1;
		}
		if(strcmp(cmd, "/afarmerjobpos", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			new Float:x, Float:y, Float:z;
			GetPlayerPos(playerid, x, y, z);
			new Float:angle;
			GetPlayerFacingAngle(playerid, angle);
			FarmerJob[TakeJobX] = x;
			FarmerJob[TakeJobY] = y;
			FarmerJob[TakeJobZ] = z;
			FarmerJob[TakeJobWorld]= GetPlayerVirtualWorld(playerid);
			FarmerJob[TakeJobInterior] = GetPlayerInterior(playerid);
			FarmerJob[TakeJobAngle] = angle;
			FarmerJob[TakeJobPickupID] = ChangePickupModel(FarmerJob[TakeJobPickupID], 1239,FarmerJob[TakeJobX], FarmerJob[TakeJobY], FarmerJob[TakeJobZ]);
			SaveFarmerJob();
			SendClientMessage(playerid, COLOR_ADMINCMD, "You have successfully set the Farmer Job Position.");
			return 1;
		}
		if(strcmp(cmd, "/ataxijobpos", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			new Float:x, Float:y, Float:z;
			GetPlayerPos(playerid, x, y, z);
			new Float:angle;
			GetPlayerFacingAngle(playerid, angle);
			TaxiJob[TakeJobX] = x;
			TaxiJob[TakeJobY] = y;
			TaxiJob[TakeJobZ] = z;
			TaxiJob[TakeJobWorld]= GetPlayerVirtualWorld(playerid);
			TaxiJob[TakeJobInterior] = GetPlayerInterior(playerid);
			TaxiJob[TakeJobAngle] = angle;
			TaxiJob[TakeJobPickupID] = ChangePickupModel(TaxiJob[TakeJobPickupID],1239, TaxiJob[TakeJobX], TaxiJob[TakeJobY], TaxiJob[TakeJobZ]);
			SaveTaxiJob();
			SendClientMessage(playerid, COLOR_ADMINCMD, "You have successfully set the Taxi Job Position.");
			return 1;
		}

		//===============================================[FLYING & DRIVING TEST POS]==========================================================
		if(strcmp(cmd, "/agotoweaponlicpos", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			SetPlayerToPos(playerid,WeaponLicensePosition[X],WeaponLicensePosition[Y],WeaponLicensePosition[Z]);
			SetPlayerInterior(playerid,WeaponLicensePosition[Interior]);
			SetPlayerVirtualWorld(playerid,WeaponLicensePosition[World]);
			SetPlayerFacingAngle(playerid,WeaponLicensePosition[Angle]);
			SendClientMessage(playerid, COLOR_ADMINCMD, "[INFO:] You teleported to the weapon license position.");
			return 1;
		}
		if(strcmp(cmd, "/aweaponlicensepos", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			new Float:x,Float:y,Float:z;
			GetPlayerPos(playerid, x, y, z);
			new Float:angle;
			GetPlayerFacingAngle(playerid, angle);
			WeaponLicensePosition[X] = x;
			WeaponLicensePosition[Y] = y;
			WeaponLicensePosition[Z] = z;
			WeaponLicensePosition[World] = GetPlayerVirtualWorld(playerid);
			WeaponLicensePosition[Interior] = GetPlayerInterior(playerid);
			WeaponLicensePosition[Angle] = angle;
			WeaponLicensePosition[PickupID] = ChangePickupModel(WeaponLicensePosition[PickupID],1239,WeaponLicensePosition[X],WeaponLicensePosition[Y],WeaponLicensePosition[Z]);
			SaveWeaponLicensePosition();
			SendClientMessage(playerid, COLOR_ADMINCMD, "You have successfully set the Weapon License Position.");
			return 1;
		}
		if(strcmp(cmd, "/aflyingtestpos", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			new Float:x,Float:y,Float:z;
			GetPlayerPos(playerid, x, y, z);
			new Float:angle;
			GetPlayerFacingAngle(playerid, angle);
			FlyingTestPosition[X] = x;
			FlyingTestPosition[Y] = y;
			FlyingTestPosition[Z] = z;
			FlyingTestPosition[World] = GetPlayerVirtualWorld(playerid);
			FlyingTestPosition[Interior] = GetPlayerInterior(playerid);
			FlyingTestPosition[Angle] = angle;
			FlyingTestPosition[PickupID] = ChangePickupModel(FlyingTestPosition[PickupID],1239,FlyingTestPosition[X],FlyingTestPosition[Y],FlyingTestPosition[Z]);
			SaveFlyingTestPosition();
			SendClientMessage(playerid, COLOR_ADMINCMD, "You have successfully set the Flying Test Position.");
			return 1;
		}
		if(strcmp(cmd, "/aboattestpos", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			new Float:x,Float:y,Float:z;
			GetPlayerPos(playerid, x, y, z);
			new Float:angle;
			GetPlayerFacingAngle(playerid, angle);
			BoatTestPosition[X] = x;
			BoatTestPosition[Y] = y;
			BoatTestPosition[Z] = z;
			BoatTestPosition[World] = GetPlayerVirtualWorld(playerid);
			BoatTestPosition[Interior] = GetPlayerInterior(playerid);
			BoatTestPosition[Angle] = angle;
			BoatTestPosition[PickupID] = ChangePickupModel(BoatTestPosition[PickupID],1239,BoatTestPosition[X],BoatTestPosition[Y],BoatTestPosition[Z]);
			SaveBoatTestPosition();
			SendClientMessage(playerid, COLOR_ADMINCMD, "You have successfully set the Boat Test Position.");
			return 1;
		}
		if(strcmp(cmd, "/adrivingtestpos", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			new Float:x,Float:y,Float:z;
			GetPlayerPos(playerid, x, y, z);
			new Float:angle;
			GetPlayerFacingAngle(playerid, angle);
			DrivingTestPosition[X] = x;
			DrivingTestPosition[Y] = y;
			DrivingTestPosition[Z] = z;
			DrivingTestPosition[World] = GetPlayerVirtualWorld(playerid);
			DrivingTestPosition[Interior] = GetPlayerInterior(playerid);
			DrivingTestPosition[Angle] = angle;
			DrivingTestPosition[PickupID] = ChangePickupModel(DrivingTestPosition[PickupID],1239,DrivingTestPosition[X],DrivingTestPosition[Y],DrivingTestPosition[Z]);
			SaveDrivingTestPosition();
			SendClientMessage(playerid, COLOR_ADMINCMD, "You have successfully set the Driving Test Position.");
			return 1;
		}
		if(strcmp(cmd, "/acivilianspawn", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			new Float:x,Float:y,Float:z;
			GetPlayerPos(playerid, x, y, z);
			new Float:angle;
			GetPlayerFacingAngle(playerid, angle);
			CivilianSpawn[X] = x;
			CivilianSpawn[Y] = y;
			CivilianSpawn[Z] = z;
			CivilianSpawn[World] = GetPlayerVirtualWorld(playerid);
			CivilianSpawn[Interior] = GetPlayerInterior(playerid);
			CivilianSpawn[Angle] = angle;
			SaveCivilianSpawn();
			SendClientMessage(playerid, COLOR_ADMINCMD, "You have successfully set the Civilian Spawnpoint.");
			return 1;
		}
		//================================================[DYNAMIC FACTION SYSTEM]======================================================
		if(strcmp(cmd, "/afactionspawn", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 1)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /afactionspawn [factionid]");
				return 1;
			}
			new id = strval(tmp);
			new Float:x,Float:y,Float:z;
			GetPlayerPos(playerid, x, y, z);
			DynamicFactions[id][fX] = x;
			DynamicFactions[id][fY] = y;
			DynamicFactions[id][fZ] = z;
			SaveFData(id, "X");
			SaveFData(id, "Y");
			SaveFData(id, "Z");
			format(string, sizeof(string), "[INFO:] You have set faction ID: %d's spawnpoint.", id);
			SendClientMessage(playerid, COLOR_ADMINCMD, string);
			return 1;
		}
		if(strcmp(cmd, "/admin", true) == 0 || strcmp(cmd, "/a", true) == 0)
		{
			if (gPlayerData[playerid][pAdmin] < 1)
				return 0;
			GetPlayerName(playerid, sendername, sizeof(sendername));
			new length = strlen(cmdtext);
			while ((idx < length) && (cmdtext[idx] <= ' '))
			{
				idx++;
			}
			new offset = idx;
			new result[64];
			while ((idx < length) && ((idx - offset) < (sizeof(result) - 1)))
			{
				result[idx - offset] = cmdtext[idx];
				idx++;
			}
			result[idx - offset] = EOS;
			if(!strlen(result))
			{
				SendClientMessage(playerid, COLOR_GRAD2, "[INFO:] (/a)dmin [admin chat]");
				return 1;
			}

			new arank[64];
			switch(gPlayerData[playerid][pAdmin])
			{
				case 1,2,3,4: arank = "Admin";
				case 5: arank = "Head Admin";
				default:
				{
					switch(gPlayerData[playerid][pModerator])
					{
						case 1: arank = "Mod";
						case 2: arank = "SMod";
						default: arank = "";
					}
				}
			}
			format(string, sizeof(string), "*** %s %s *** %s", arank, sendername, result);
			SendAdminMessage(COLOR_YELLOW, string);
			printf("[Admin %s] [%d]: %s", gPlayerData[playerid][pOOCName], playerid, result);
			return 1;
		}
		if(strcmp(cmd, "/Moderator", true) == 0 || strcmp(cmd, "/mo", true) == 0)
		{
			if (gPlayerData[playerid][pModerator] < 1)
				return 0;
			GetPlayerName(playerid, sendername, sizeof(sendername));
			new length = strlen(cmdtext);
			while ((idx < length) && (cmdtext[idx] <= ' '))
			{
				idx++;
			}
			new offset = idx;
			new result[64];
			while ((idx < length) && ((idx - offset) < (sizeof(result) - 1)))
			{
				result[idx - offset] = cmdtext[idx];
				idx++;
			}
			result[idx - offset] = EOS;
			if(!strlen(result))
			{
				SendClientMessage(playerid, COLOR_GRAD2, "U¯YCIE: (/mo)derator [Moderator chat]");
				return 1;
			}

			new mrank[64];
			switch(gPlayerData[playerid][pAdmin])
			{
				case 1,2,3,4: mrank = "Admin";
				case 5: mrank = "Head Admin";
				default:
				{
					switch(gPlayerData[playerid][pModerator])
					{
						case 1: mrank = "Mod";
						case 2: mrank = "SMod";
						default: mrank = "";
					}
				}
			}
			format(string, sizeof(string), "*** %s %s *** %s", mrank, sendername, result);
			SendModMessage(COLOR_GREEN, string);
			printf("Moderator %s: %s", sendername, result);
			return 1;
		}
		if(strcmp(cmd, "/listenchat", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 1)
				return 0;
			if (!BigEar[playerid])
			{
				BigEar[playerid] = 1;
			}
			else if (BigEar[playerid])
			{
				BigEar[playerid] = 0;
			}
			return 1;
		}
		if(strcmp(cmd, "/afactioncolor", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /afactioncolor [factionid] [hex]");
				return 1;
			}
			new id = strval(tmp);
			new length = strlen(cmdtext);
			while ((idx < length) && (cmdtext[idx] <= ' '))
			{
				idx++;
			}
			new offset = idx;
			new result[128];
			while ((idx < length) && ((idx - offset) < (sizeof(result) - 1)))
			{
				result[idx - offset] = cmdtext[idx];
				idx++;
			}
			result[idx - offset] = EOS;
			if(!strlen(result))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /afactioncolour [factionid] [hex]");
				return 1;
			}
			if(strfind( result , "|" , true ) == -1)
			{
				strmid(DynamicFactions[id][fColor], (result), 0, strlen((result)), 128);
				format(string, sizeof(string), "[INFO:] You have set faction ID: %d's colour to %s.", id,(result));
				foreach(Player, i )
				{
					if( gPlayerData[i][pFaction] < sizeof(DynamicFactions) )
					{
						if( DynamicFactions[ gPlayerData[i][pFaction] ][fType] == 3 )
						{
							for( new n = 0; n < sizeof(DynamicZones); n++ )
								GangZoneShowForPlayer(i, n, HexToInt( DynamicFactions[ DynamicZones[n][zFaction] ][fColor]));
						}
					}
				}
				SendClientMessage(playerid, COLOR_ADMINCMD, string);
				SaveFData(id, "Color");
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Invalid Symbol, | is not allowed!");
			}
			return 1;
		}
		if(strcmp(cmd, "/afactionname", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /afactionname [factionid] [name]");
				return 1;
			}
			new id = strval(tmp);
			new length = strlen(cmdtext);
			while ((idx < length) && (cmdtext[idx] <= ' '))
			{
				idx++;
			}
			new offset = idx;
			new result[128];
			while ((idx < length) && ((idx - offset) < (sizeof(result) - 1)))
			{
				result[idx - offset] = cmdtext[idx];
				idx++;
			}
			result[idx - offset] = EOS;
			if(!strlen(result))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /afactionname [factionid] [name]");
				return 1;
			}
			if(strfind( result , "|" , true ) == -1)
			{
				strmid(DynamicFactions[id][Name], (result), 0, strlen((result)), 128);
				format(string, sizeof(string), "[INFO:] You have set faction ID: %d's name to %s", id,(result));
				SendClientMessage(playerid, COLOR_ADMINCMD, string);
				SaveFData(id, "Name");
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Invalid Symbol, | is not allowed!");
			}
			return 1;
		}
		if(strcmp(cmd, "/agotofaction", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 1)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /agotofaction [id]");
				return 1;
			}
			new id = strval(tmp);
			SetPlayerToPos(playerid,DynamicFactions[id][fX],DynamicFactions[id][fY],DynamicFactions[id][fZ]);
			SetPlayerInterior(playerid,0);
			SetPlayerVirtualWorld(playerid,0);
			new form[128];
			format(form, sizeof(form), "[INFO:] You teleported to faction ID: %d.", id);
			SendClientMessage(playerid, COLOR_ADMINCMD, form);
			return 1;
		}
		if(strcmp(cmd, "/afactiontype", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /afactiontype [factionid] [type (Numeric)]");
				return 1;
			}
			new id;
			id = strval(tmp);
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /afactiontype [factionid] [type (Numeric)]");
				return 1;
			}
			new id2;
			id2 = strval(tmp);

			DynamicFactions[id][fType] = id2;
			SaveFData(id, "Type");
			new form[128];
			format(form, sizeof form, "You've set Faction ID: %d's Type to %d.", id,id2);
			SendClientMessage(playerid, COLOR_ADMINCMD,form);
			return 1;
		}
		if(strcmp(cmd, "/afactionjoinrank", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /afactionjoinrank [factionid] [2-10]");
				return 1;
			}
			new id;
			id = strval(tmp);
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /afactionjoinrank [factionid] [2-10]");
				return 1;
			}
			new id2;
			id2 = strval(tmp);
			if(id2 >= 2 && id2 <= 10)
			{
				DynamicFactions[id][fJoinRank] = id2;
				SaveFData(id, "JoinRank");
				new form[128];
				format(form, sizeof form, "You've set Faction ID: %d's JoinRank to %d.", id,id2);
				SendClientMessage(playerid, COLOR_ADMINCMD,form);
			}
			return 1;
		}
		if(strcmp(cmd, "/afactionbank", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /afactionbank [factionid] [amount]");
				return 1;
			}
			new id;
			id = strval(tmp);
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /afactionbank [factionid] [amount]");
				return 1;
			}
			new id2;
			id2 = strval(tmp);

			DynamicFactions[id][fBank] = id2;
			new form[128];
			format(form, sizeof form, "You've set Faction ID: %d's Bank to %d.", id,id2);
			SendClientMessage(playerid, COLOR_ADMINCMD,form);
			SaveFData(id, "Bank");
			return 1;
		}
		if(strcmp(cmd, "/afactiondrugs", true) == 0)
		{
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /afactiondrugs [factionid] [amount]");
				return 1;
			}
			new id;
			id = strval(tmp);
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /afactiondrugs [factionid] [amount]");
				return 1;
			}
			new id2;
			id2 = strval(tmp);

			DynamicFactions[id][fDrugs] = id2;
			SaveFData(id, "Drugs");
			new form[128];
			format(form, sizeof form, "You've set Faction ID: %d's Drugs to %d.", id,id2);
			SendClientMessage(playerid, COLOR_ADMINCMD,form);
			return 1;
		}
		if(strcmp(cmd, "/afactionmats", true) == 0)
		{
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /afactionmats [factionid] [amount]");
				return 1;
			}
			new id;
			id = strval(tmp);
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /afactionmats [factionid] [amount]");
				return 1;
			}
			new id2;
			id2 = strval(tmp);

			DynamicFactions[id][fMaterials] = id2;
			SaveFData(id, "Materials");
			new form[128];
			format(form, sizeof form, "You've set Faction ID: %d's Materials to %d.", id,id2);
			SendClientMessage(playerid, COLOR_ADMINCMD,form);
			return 1;
		}
		if(strcmp(cmd, "/afactionrankamount", true) == 0)
		{
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /afactionrankamount [factionid] [2-10]");
				return 1;
			}
			new id;
			id = strval(tmp);
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /afactionrankamount [factionid] [2-10]");
				return 1;
			}
			new id2;
			id2 = strval(tmp);

			if(id2 >= 2 && id2 <= 10)
			{
				DynamicFactions[id][fRankAmount] = id2;
				SaveFData(id, "RankAmount");
				new form[128];
				format(form, sizeof form, "You've set Faction ID: %d's RankAmount to %d.", id,id2);
				SendClientMessage(playerid, COLOR_ADMINCMD,form);
			}
			return 1;
		}
		if(strcmp(cmd, "/afactionrankname", true) == 0)
		{
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /afactionrankname [factionid] [Rank ID - 1-10] [Name]");
				return 1;
			}
			new id;
			id = strval(tmp);
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /afactionrankname [factionid] [Rank ID - 1-10] [Name]");
				return 1;
			}
			new id2;
			id2 = strval(tmp);

			new length = strlen(cmdtext);
			while ((idx < length) && (cmdtext[idx] <= ' '))
			{
				idx++;
			}
			new offset = idx;
			new result[64];
			while ((idx < length) && ((idx - offset) < (sizeof(result) - 1)))
			{
				result[idx - offset] = cmdtext[idx];
				idx++;
			}
			result[idx - offset] = EOS;
			if(!strlen(result))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /afactionrankname [factionid] [Rank ID - 1-10] [Name]");
				return 1;
			}
			if(strfind( result , "|" , true ) == -1)
			{
				if(id2 == 1)
				{
					strmid(DynamicFactions[id][fRank1], (result), 0, strlen((result)), 128);
					SaveFData(id, "Rank1");
					format(string, sizeof(string), "[INFO:] You have set faction ID: %d's Rank: %d's name to: %s", id,id2,result);
					SendClientMessage(playerid, COLOR_ADMINCMD, string);
				}
				else if(id2 == 2)
				{
					strmid(DynamicFactions[id][fRank2], (result), 0, strlen((result)), 128);
					SaveFData(id, "Rank2");
					format(string, sizeof(string), "[INFO:] You have set faction ID: %d's Rank: %d's name to: %s", id,id2,result);
					SendClientMessage(playerid, COLOR_ADMINCMD, string);
				}
				else if(id2 == 3)
				{
					strmid(DynamicFactions[id][fRank3], (result), 0, strlen((result)), 128);
					SaveFData(id, "Rank3");
					format(string, sizeof(string), "[INFO:] You have set faction ID: %d's Rank: %d's name to: %s", id,id2,result);
					SendClientMessage(playerid, COLOR_ADMINCMD, string);
				}
				else if(id2 == 4)
				{
					strmid(DynamicFactions[id][fRank4], (result), 0, strlen((result)), 128);
					SaveFData(id, "Rank4");
					format(string, sizeof(string), "[INFO:] You have set faction ID: %d's Rank: %d's name to: %s", id,id2,result);
					SendClientMessage(playerid, COLOR_ADMINCMD, string);
				}
				else if(id2 == 5)
				{
					strmid(DynamicFactions[id][fRank5], (result), 0, strlen((result)), 128);
					SaveFData(id, "Rank5");
					format(string, sizeof(string), "[INFO:] You have set faction ID: %d's Rank: %d's name to: %s", id,id2,result);
					SendClientMessage(playerid, COLOR_ADMINCMD, string);
				}
				else if(id2 == 6)
				{
					strmid(DynamicFactions[id][fRank6], (result), 0, strlen((result)), 128);
					SaveFData(id, "Rank6");
					format(string, sizeof(string), "[INFO:] You have set faction ID: %d's Rank: %d's name to: %s", id,id2,result);
					SendClientMessage(playerid, COLOR_ADMINCMD, string);
				}
				else if(id2 == 7)
				{
					strmid(DynamicFactions[id][fRank7], (result), 0, strlen((result)), 128);
					SaveFData(id, "Rank7");
					format(string, sizeof(string), "[INFO:] You have set faction ID: %d's Rank: %d's name to: %s", id,id2,result);
					SendClientMessage(playerid, COLOR_ADMINCMD, string);
				}
				else if(id2 == 8)
				{
					strmid(DynamicFactions[id][fRank8], (result), 0, strlen((result)), 128);
					SaveFData(id, "Rank8");
					format(string, sizeof(string), "[INFO:] You have set faction ID: %d's Rank: %d's name to: %s", id,id2,result);
					SendClientMessage(playerid, COLOR_ADMINCMD, string);
				}
				else if(id2 == 9)
				{
					strmid(DynamicFactions[id][fRank9], (result), 0, strlen((result)), 128);
					SaveFData(id, "Rank9");
					format(string, sizeof(string), "[INFO:] You have set faction ID: %d's Rank: %d's name to: %s", id,id2,result);
					SendClientMessage(playerid, COLOR_ADMINCMD, string);
				}
				else if(id2 == 10)
				{
					strmid(DynamicFactions[id][fRank10], (result), 0, strlen((result)), 128);
					SaveFData(id, "Rank10");
					format(string, sizeof(string), "[INFO:] You have set faction ID: %d's Rank: %d's name to: %s", id,id2,result);
					SendClientMessage(playerid, COLOR_ADMINCMD, string);
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Invalid symbol, | is not allowed!");
			}
			return 1;
		}
		if(strcmp(cmd, "/afactionskin", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /afactionskin [factionid] [Rank ID - 1-10] [Skinid]");
				return 1;
			}
			new id;
			id = strval(tmp);
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /afactionskin [factionid] [Rank ID - 1-10] [Skinid]");
				return 1;
			}
			new id2;
			id2 = strval(tmp);
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /afactionskin [factionid] [Rank ID - 1-10] [Skinid]");
				return 1;
			}
			new id3;
			id3 = strval(tmp);

			if(id2 == 1)
			{
				DynamicFactions[id][fSkin1] = id3;
				SaveFData(id, "Skin1");
				new form[128];
				format(form, sizeof form, "You've set Faction ID: %d's Rank %d Skin to %d.", id,id2,id3);
				SendClientMessage(playerid, COLOR_ADMINCMD,form);
			}
			else if(id2 == 2)
			{
				DynamicFactions[id][fSkin2] = id3;
				SaveFData(id, "Skin2");
				new form[128];
				format(form, sizeof form, "You've set Faction ID: %d's Rank %d Skin to %d.", id,id2,id3);
				SendClientMessage(playerid, COLOR_ADMINCMD,form);
			}
			else if(id2 == 3)
			{
				DynamicFactions[id][fSkin3] = id3;
				SaveFData(id, "Skin3");
				new form[128];
				format(form, sizeof form, "You've set Faction ID: %d's Rank %d Skin to %d.", id,id2,id3);
				SendClientMessage(playerid, COLOR_ADMINCMD,form);
			}
			else if(id2 == 4)
			{
				DynamicFactions[id][fSkin4] = id3;
				SaveFData(id, "Skin4");
				new form[128];
				format(form, sizeof form, "You've set Faction ID: %d's Rank %d Skin to %d.", id,id2,id3);
				SendClientMessage(playerid, COLOR_ADMINCMD,form);
			}
			else if(id2 == 5)
			{
				DynamicFactions[id][fSkin5] = id3;
				SaveFData(id, "Skin5");
				new form[128];
				format(form, sizeof form, "You've set Faction ID: %d's Rank %d Skin to %d.", id,id2,id3);
				SendClientMessage(playerid, COLOR_ADMINCMD,form);
			}
			else if(id2 == 6)
			{
				DynamicFactions[id][fSkin6] = id3;
				SaveFData(id, "Skin6");
				new form[128];
				format(form, sizeof form, "You've set Faction ID: %d's Rank %d Skin to %d.", id,id2,id3);
				SendClientMessage(playerid, COLOR_ADMINCMD,form);
			}
			else if(id2 == 7)
			{
				DynamicFactions[id][fSkin7] = id3;
				SaveFData(id, "Skin7");
				new form[128];
				format(form, sizeof form, "You've set Faction ID: %d's Rank %d Skin to %d.", id,id2,id3);
				SendClientMessage(playerid, COLOR_ADMINCMD,form);
			}
			else if(id2 == 8)
			{
				DynamicFactions[id][fSkin8] = id3;
				SaveFData(id, "Skin8");
				new form[128];
				format(form, sizeof form, "You've set Faction ID: %d's Rank %d Skin to %d.", id,id2,id3);
				SendClientMessage(playerid, COLOR_ADMINCMD,form);
			}
			else if(id2 == 9)
			{
				DynamicFactions[id][fSkin9] = id3;
				SaveFData(id, "Skin9");
				new form[128];
				format(form, sizeof form, "You've set Faction ID: %d's Rank %d Skin to %d.", id,id2,id3);
				SendClientMessage(playerid, COLOR_ADMINCMD,form);
			}
			else if(id2 == 10)
			{
				DynamicFactions[id][fSkin10] = id3;
				SaveFData(id, "Skin10");
				new form[128];
				format(form, sizeof form, "You've set Faction ID: %d's Rank %d Skin to %d.", id,id2,id3);
				SendClientMessage(playerid, COLOR_ADMINCMD,form);
			}
			return 1;
		}
		if(strcmp(cmd, "/afactionusecolor", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /afactionusecolor [factionid]");
				return 1;
			}
			new id;
			id = strval(tmp);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /afactionusecolor [factionid]");
				return 1;
			}
			if(DynamicFactions[id][fUseColor])
			{
				DynamicFactions[id][fUseColor] = 0;
				SaveFData(id, "UseColor");
				new form[128];
				format(form, sizeof form, "[INFO:] Faction ID: %d's color disabled.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,form);
				SendFactionMessage(id, COLOR_FACTIONCHAT, "[FACTION:] Faction color's disabled by an administrator.");

				for(new i=0;i<CUSTOM_MAX_PLAYERS;i++)
				{
					if(IsPlayerConnected(i))
					{
						if(gPlayerData[i][pFaction] == id)
						{
							SetPlayerColor(i,COLOR_CIVILIAN);
						}
					}
				}
			}
			else
			{
				DynamicFactions[id][fUseColor] = 1;
				SaveFData(id, "UseColor");
				new form[128];
				format(form, sizeof form, "[INFO:] Faction ID: %d's color enabled.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,form);
				SendFactionMessage(id, COLOR_FACTIONCHAT, "[FACTION:] Faction color's enabled by an administrator.");

				for(new i=0;i<CUSTOM_MAX_PLAYERS;i++)
				{
					if(IsPlayerConnected(i))
					{
						if(gPlayerData[i][pFaction] == id)
						{
							//SetPlayerToFactionColor(i);
						}
					}
				}
			}
			return 1;
		}
		if(strcmp(cmd, "/afactionuseskins", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /afactionuseskins [factionid]");
				return 1;
			}
			new id;
			id = strval(tmp);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /afactionuseskins [factionid]");
				return 1;
			}
			if(DynamicFactions[id][fUseSkins])
			{
				DynamicFactions[id][fUseSkins] = 0;
				SaveFData(id, "UseSkins");
				new form[128];
				format(form, sizeof form, "[INFO:] Faction ID: %d's skin's disabled.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,form);
				SendFactionMessage(id, COLOR_FACTIONCHAT, "[FACTION:] Faction skin's disabled by an administrator.");

			}
			else
			{
				DynamicFactions[id][fUseSkins] = 1;
				SaveFData(id, "UseSkins");
				new form[128];
				format(form, sizeof form, "[INFO:] Faction ID: %d's skin's enabled.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,form);
				SendFactionMessage(id, COLOR_FACTIONCHAT, "[FACTION:] Faction skin's enabled by an administrator.");
				
				foreach(Player, i )
				{
					if(gPlayerData[i][pFaction] == id)
					{
						SetPlayerToFactionSkin(i);
					}
				}
			}
			return 1;
		}
		//--------------------------------------------------------------------------------------------------------------------------
		//---------------------------------------[NORMAL ADMINISTRATOR COMMANDS]-------------------------------------------
		if(strcmp(cmd, "/banaccount", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 1)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /banaccount [playerid/partoName] [reason]");
				return 1;
			}
			giveplayerid = ReturnUser(tmp);
			if(IsPlayerConnected(giveplayerid))
			{
				if(giveplayerid != INVALID_PLAYER_ID)
				{
					new length = strlen(cmdtext);
					while ((idx < length) && (cmdtext[idx] <= ' '))
					{
						idx++;
					}
					new offset = idx;
					new result[128];
					while ((idx < length) && ((idx - offset) < (sizeof(result) - 1)))
					{
						result[idx - offset] = cmdtext[idx];
						idx++;
					}
					result[idx - offset] = EOS;
					if(!strlen(result))
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /banaccount [playerid/partoName] [reason]");
						return 1;
					}
					BanPlayerAccount(giveplayerid,GetPlayerNameEx(playerid),(result));
					return 1;
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Invalid ID.");
			}
			return 1;
		}
		if(strcmp(cmd, "/mbanaccount", true) == 0)
		{
			if(gPlayerData[playerid][pModerator] != 2)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /banaccount [playerid/partoName] [reason]");
				return 1;
			}
			giveplayerid = ReturnUser(tmp);
			if(IsPlayerConnected(giveplayerid))
			{
				if(giveplayerid != INVALID_PLAYER_ID)
				{
					if(gPlayerData[giveplayerid][pAdmin] > 0)
					{
						SendClientMessage(playerid, COLOR_RED, "[B£¥D:] Nie jesteœ upowa¿niony do u¿ywania tej komendy na adminie !");
						return 1;
					}
					new length = strlen(cmdtext);
					while ((idx < length) && (cmdtext[idx] <= ' '))
					{
						idx++;
					}
					new offset = idx;
					new result[128];
					while ((idx < length) && ((idx - offset) < (sizeof(result) - 1)))
					{
						result[idx - offset] = cmdtext[idx];
						idx++;
					}
					result[idx - offset] = EOS;
					if(!strlen(result))
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /banaccount [playerid/partoName] [reason]");
						return 1;
					}
					BanPlayerAccount(giveplayerid,GetPlayerNameEx(playerid),(result));
					return 1;
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Invalid ID.");
			}
			return 1;
		}
		if(strcmp(cmd, "/ban", true) == 0)
		{
			if(gPlayerData[playerid][pModerator] != 2)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /ban [playerid/partoName] [reason]");
				return 1;
			}
			giveplayerid = ReturnUser(tmp);
			if(IsPlayerConnected(giveplayerid))
			{
				if(giveplayerid != INVALID_PLAYER_ID)
				{
					new length = strlen(cmdtext);
					while ((idx < length) && (cmdtext[idx] <= ' '))
					{
						idx++;
					}
					new offset = idx;
					new result[128];
					while ((idx < length) && ((idx - offset) < (sizeof(result) - 1)))
					{
						result[idx - offset] = cmdtext[idx];
						idx++;
					}
					result[idx - offset] = EOS;
					if(!strlen(result))
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /ban [playerid/partoName] [reason]");
						return 1;
					}
					BanPlayer(giveplayerid,GetPlayerNameEx(playerid),(result));
					return 1;
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Invalid ID.");
			}
			return 1;
		}
		if(strcmp(cmd, "/afactionkick", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 1)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /afactionkick [playerid/partoName] [reason]");
				return 1;
			}
			giveplayerid = ReturnUser(tmp);
			if(IsPlayerConnected(giveplayerid))
			{
				if(giveplayerid != INVALID_PLAYER_ID)
				{
					new length = strlen(cmdtext);
					while ((idx < length) && (cmdtext[idx] <= ' '))
					{
						idx++;
					}
					new offset = idx;
					new result[128];
					while ((idx < length) && ((idx - offset) < (sizeof(result) - 1)))
					{
						result[idx - offset] = cmdtext[idx];
						idx++;
					}
					result[idx - offset] = EOS;
					if(!strlen(result))
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /afactionkick [playerid/partoName] [reason]");
						return 1;
					}
					new form[128];
					format(form,sizeof(form),"%s zosta³ wyrzucony z frakcji %s, Powód: %s ",GetPlayerNameEx(giveplayerid),GetPlayerNameEx(playerid),(result));
					ABroadCast(COLOR_YELLOW,string,1);
					gPlayerData[giveplayerid][pFaction] = 255;

					SavePlayerData(giveplayerid, "Faction");

					SetPlayerSpawn(giveplayerid);
					return 1;
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Invalid ID.");
			}
			return 1;
		}
		if(strcmp(cmd, "/sluzba", true) == 0)
		{
			if(gPlayerData[playerid][pFaction] == 255)
			{
				SendClientMessage(playerid, COLOR_RED, "[INFO:] Niew³aœciwa frakcja !");
				return 1;
			}
			new factionid = gPlayerData[playerid][pFaction];
			if(DynamicFactions[factionid][fType] == 1)
			{
				if((PlayerToPoint(5.0, playerid, DynamicFactions[factionid][fXDuty], DynamicFactions[factionid][fYDuty], DynamicFactions[factionid][fZDuty]) && GetPlayerVirtualWorld(playerid) == DynamicFactions[factionid][fWorldDuty]) ||
				       (PlayerToPoint(5.0, playerid, DynamicFactions[factionid][fXDuty2], DynamicFactions[factionid][fYDuty2], DynamicFactions[factionid][fZDuty2]) && GetPlayerVirtualWorld(playerid) == DynamicFactions[factionid][fWorldDuty2]))
				{
					if(gPlayerData[playerid][pDuty] == 1)
					{
						SetPlayerSkin(playerid,gPlayerData[playerid][pSkin]);
						gPlayerData[playerid][pDuty] = 0;
						SavePlayerData(playerid, "Duty");
						PlayerActionMessage(playerid, 15.0, "odk³ada broñ do magazynu i przebiera siê");
						if(gPlayerData[playerid][pRank] == 1)
						{
							ReturnPlayerAmmoF(playerid, DynamicFactions[factionid][fGun1Rank1], DynamicFactions[factionid][fAmmo1Rank1]);
							ReturnPlayerAmmoF(playerid, DynamicFactions[factionid][fGun2Rank1], DynamicFactions[factionid][fAmmo2Rank1]);
							ReturnPlayerAmmoF(playerid, DynamicFactions[factionid][fGun3Rank1], DynamicFactions[factionid][fAmmo3Rank1]);
						}
						else if(gPlayerData[playerid][pRank] == 2)
						{
							ReturnPlayerAmmoF(playerid, DynamicFactions[factionid][fGun1Rank2], DynamicFactions[factionid][fAmmo1Rank2]);
							ReturnPlayerAmmoF(playerid, DynamicFactions[factionid][fGun2Rank2], DynamicFactions[factionid][fAmmo2Rank2]);
							ReturnPlayerAmmoF(playerid, DynamicFactions[factionid][fGun3Rank2], DynamicFactions[factionid][fAmmo3Rank2]);
						}
						else if(gPlayerData[playerid][pRank] == 3)
						{
							ReturnPlayerAmmoF(playerid, DynamicFactions[factionid][fGun1Rank3], DynamicFactions[factionid][fAmmo1Rank3]);
							ReturnPlayerAmmoF(playerid, DynamicFactions[factionid][fGun2Rank3], DynamicFactions[factionid][fAmmo2Rank3]);
							ReturnPlayerAmmoF(playerid, DynamicFactions[factionid][fGun3Rank3], DynamicFactions[factionid][fAmmo3Rank3]);
						}
						else if(gPlayerData[playerid][pRank] == 4)
						{
							ReturnPlayerAmmoF(playerid, DynamicFactions[factionid][fGun1Rank4], DynamicFactions[factionid][fAmmo1Rank4]);
							ReturnPlayerAmmoF(playerid, DynamicFactions[factionid][fGun2Rank4], DynamicFactions[factionid][fAmmo2Rank4]);
							ReturnPlayerAmmoF(playerid, DynamicFactions[factionid][fGun3Rank4], DynamicFactions[factionid][fAmmo3Rank4]);
						}
						else if(gPlayerData[playerid][pRank] == 5)
						{
							ReturnPlayerAmmoF(playerid, DynamicFactions[factionid][fGun1Rank5], DynamicFactions[factionid][fAmmo1Rank5]);
							ReturnPlayerAmmoF(playerid, DynamicFactions[factionid][fGun2Rank5], DynamicFactions[factionid][fAmmo2Rank5]);
							ReturnPlayerAmmoF(playerid, DynamicFactions[factionid][fGun3Rank5], DynamicFactions[factionid][fAmmo3Rank5]);
						}
						else if(gPlayerData[playerid][pRank] == 6)
						{
							ReturnPlayerAmmoF(playerid, DynamicFactions[factionid][fGun1Rank1], DynamicFactions[factionid][fAmmo1Rank6]);
							ReturnPlayerAmmoF(playerid, DynamicFactions[factionid][fGun2Rank6], DynamicFactions[factionid][fAmmo2Rank6]);
							ReturnPlayerAmmoF(playerid, DynamicFactions[factionid][fGun3Rank6], DynamicFactions[factionid][fAmmo3Rank6]);
						}
						else if(gPlayerData[playerid][pRank] == 7)
						{
							ReturnPlayerAmmoF(playerid, DynamicFactions[factionid][fGun1Rank7], DynamicFactions[factionid][fAmmo1Rank7]);
							ReturnPlayerAmmoF(playerid, DynamicFactions[factionid][fGun2Rank7], DynamicFactions[factionid][fAmmo2Rank7]);
							ReturnPlayerAmmoF(playerid, DynamicFactions[factionid][fGun3Rank7], DynamicFactions[factionid][fAmmo3Rank7]);
						}
						else if(gPlayerData[playerid][pRank] == 8)
						{
							ReturnPlayerAmmoF(playerid, DynamicFactions[factionid][fGun1Rank8], DynamicFactions[factionid][fAmmo1Rank8]);
							ReturnPlayerAmmoF(playerid, DynamicFactions[factionid][fGun2Rank8], DynamicFactions[factionid][fAmmo2Rank8]);
							ReturnPlayerAmmoF(playerid, DynamicFactions[factionid][fGun3Rank8], DynamicFactions[factionid][fAmmo3Rank8]);
						}
						else if(gPlayerData[playerid][pRank] == 9)
						{
							ReturnPlayerAmmoF(playerid, DynamicFactions[factionid][fGun1Rank9], DynamicFactions[factionid][fAmmo1Rank9]);
							ReturnPlayerAmmoF(playerid, DynamicFactions[factionid][fGun2Rank9], DynamicFactions[factionid][fAmmo2Rank9]);
							ReturnPlayerAmmoF(playerid, DynamicFactions[factionid][fGun3Rank9], DynamicFactions[factionid][fAmmo3Rank9]);
						}
						else if(gPlayerData[playerid][pRank] == 10)
						{
							ReturnPlayerAmmoF(playerid, DynamicFactions[factionid][fGun1Rank10], DynamicFactions[factionid][fAmmo1Rank10]);
							ReturnPlayerAmmoF(playerid, DynamicFactions[factionid][fGun2Rank10], DynamicFactions[factionid][fAmmo2Rank10]);
							ReturnPlayerAmmoF(playerid, DynamicFactions[factionid][fGun3Rank10], DynamicFactions[factionid][fAmmo3Rank10]);
						}
						return 1;
					}
					if(gPlayerData[playerid][pDuty] == 0)
					{
						gPlayerData[playerid][pDuty] = 1;
						SavePlayerData(playerid, "Duty");
						SetPlayerToFactionSkin(playerid);
						if(gPlayerData[playerid][pRank] == 1)
						{
							format(string, sizeof(string), "[%s:] %s pobra³ broñ.",DynamicFactions[factionid][Name],GetPlayerNameEx(playerid));
							SendFactionMessage(factionid, COLOR_DARKPURPLE, string);
							
							AddPlayerAmmoF(playerid, DynamicFactions[factionid][fGun1Rank1], DynamicFactions[factionid][fAmmo1Rank1]);
							AddPlayerAmmoF(playerid, DynamicFactions[factionid][fGun2Rank1], DynamicFactions[factionid][fAmmo2Rank1]);
							AddPlayerAmmoF(playerid, DynamicFactions[factionid][fGun3Rank1], DynamicFactions[factionid][fAmmo3Rank1]);

							// if(DynamicFactions[factionid][fGun1Rank1] == 25)	{ DynamicFactions[factionid][fBank] -= 700; }
							// if(DynamicFactions[factionid][fGun1Rank1] == 29)	{ DynamicFactions[factionid][fBank] -= 900; }
							// if(DynamicFactions[factionid][fGun1Rank1] == 28)	{ DynamicFactions[factionid][fBank] -= 800; }
							// if(DynamicFactions[factionid][fGun1Rank1] == 30)	{ DynamicFactions[factionid][fBank] -= 5000; }
							// if(DynamicFactions[factionid][fGun1Rank1] == 31)	{ DynamicFactions[factionid][fBank] -= 5000; }
							// if(DynamicFactions[factionid][fGun1Rank1] == 32)	{ DynamicFactions[factionid][fBank] -= 800; }
							// if(DynamicFactions[factionid][fGun1Rank1] == 33)	{ DynamicFactions[factionid][fBank] -= 1000; }
							// if(DynamicFactions[factionid][fGun1Rank1] == 34)	{ DynamicFactions[factionid][fBank] -= 10000; }

							// if(DynamicFactions[factionid][fGun2Rank1] == 22)	{ DynamicFactions[factionid][fBank] -= 300; }
							// if(DynamicFactions[factionid][fGun2Rank1] == 23)	{ DynamicFactions[factionid][fBank] -= 400; }
							// if(DynamicFactions[factionid][fGun2Rank1] == 24)	{ DynamicFactions[factionid][fBank] -= 1500; }

							if(DynamicFactions[factionid][fGun1Rank1] == 3)	
							{
								GivePlayerGun(playerid, 3, 1);
								DynamicFactions[factionid][fBank] -= 35; 
							}
							if(DynamicFactions[factionid][fGun1Rank1] == 1)	
							{
								GivePlayerGun(playerid, 1, 1);
								DynamicFactions[factionid][fBank] -= 10;
							}
							if(DynamicFactions[factionid][fGun1Rank1] == 5)
							{
								GivePlayerGun(playerid, 5, 1);
								DynamicFactions[factionid][fBank] -= 50;
							}
							if(DynamicFactions[factionid][fGun1Rank1] == 4)
							{
								GivePlayerGun(playerid, 4, 1);
								DynamicFactions[factionid][fBank] -= 100;
							}
							if(DynamicFactions[factionid][fGun2Rank1] == 3)	
							{
								GivePlayerGun(playerid, 3, 1);
								DynamicFactions[factionid][fBank] -= 35; 
							}
							if(DynamicFactions[factionid][fGun2Rank1] == 1)	
							{
								GivePlayerGun(playerid, 1, 1);
								DynamicFactions[factionid][fBank] -= 10;
							}
							if(DynamicFactions[factionid][fGun2Rank1] == 5)
							{
								GivePlayerGun(playerid, 5, 1);
								DynamicFactions[factionid][fBank] -= 50;
							}
							if(DynamicFactions[factionid][fGun2Rank1] == 4)
							{
								GivePlayerGun(playerid, 4, 1);
								DynamicFactions[factionid][fBank] -= 100;
							}
							if(DynamicFactions[factionid][fGun3Rank1] == 3)	
							{
								GivePlayerGun(playerid, 3, 1);
								DynamicFactions[factionid][fBank] -= 35; 
							}
							if(DynamicFactions[factionid][fGun3Rank1] == 1)	
							{
								GivePlayerGun(playerid, 1, 1);
								DynamicFactions[factionid][fBank] -= 10;
							}
							if(DynamicFactions[factionid][fGun3Rank1] == 5)
							{
								GivePlayerGun(playerid, 5, 1);
								DynamicFactions[factionid][fBank] -= 50;
							}
							if(DynamicFactions[factionid][fGun3Rank1] == 4)
							{
								GivePlayerGun(playerid, 4, 1);
								DynamicFactions[factionid][fBank] -= 100;
							}

							// SaveFData(factionid, "Bank");
							// format(string, sizeof(string), "[%s:] Brak piêdzy na koncie w frakcji na pobranie broni",DynamicFactions[factionid][Name],GetPlayerNameEx(playerid));
							// SendFactionMessage(8, COLOR_DARKPURPLE, string);
						}
						if(gPlayerData[playerid][pRank] == 2)
						{
							format(string, sizeof(string), "[%s:] %s pobra³ broñ.",DynamicFactions[factionid][Name],GetPlayerNameEx(playerid));
							SendFactionMessage(factionid, COLOR_DARKPURPLE, string);

							AddPlayerAmmoF(playerid, DynamicFactions[factionid][fGun1Rank2], DynamicFactions[factionid][fAmmo1Rank2]);
							AddPlayerAmmoF(playerid, DynamicFactions[factionid][fGun2Rank2], DynamicFactions[factionid][fAmmo2Rank2]);
							AddPlayerAmmoF(playerid, DynamicFactions[factionid][fGun3Rank2], DynamicFactions[factionid][fAmmo3Rank2]);

							// if(DynamicFactions[factionid][fGun1Rank2] == 25)	{ DynamicFactions[factionid][fBank] -= 700; }
							// if(DynamicFactions[factionid][fGun1Rank2] == 29)	{ DynamicFactions[factionid][fBank] -= 900; }
							// if(DynamicFactions[factionid][fGun1Rank2] == 28)	{ DynamicFactions[factionid][fBank] -= 800; }
							// if(DynamicFactions[factionid][fGun1Rank2] == 30)	{ DynamicFactions[factionid][fBank] -= 5000; }
							// if(DynamicFactions[factionid][fGun1Rank2] == 31)	{ DynamicFactions[factionid][fBank] -= 5000; }
							// if(DynamicFactions[factionid][fGun1Rank2] == 32)	{ DynamicFactions[factionid][fBank] -= 800; }
							// if(DynamicFactions[factionid][fGun1Rank2] == 33)	{ DynamicFactions[factionid][fBank] -= 1000; }
							// if(DynamicFactions[factionid][fGun1Rank2] == 34)	{ DynamicFactions[factionid][fBank] -= 10000; }

							// if(DynamicFactions[factionid][fGun2Rank2] == 22)	{ DynamicFactions[factionid][fBank] -= 300; }
							// if(DynamicFactions[factionid][fGun2Rank2] == 23)	{ DynamicFactions[factionid][fBank] -= 400; }
							// if(DynamicFactions[factionid][fGun2Rank2] == 24)	{ DynamicFactions[factionid][fBank] -= 1500; }

							if(DynamicFactions[factionid][fGun1Rank2] == 3)	
							{
								GivePlayerGun(playerid, 3, 1);
								DynamicFactions[factionid][fBank] -= 35; 
							}
							if(DynamicFactions[factionid][fGun1Rank2] == 1)	
							{
								GivePlayerGun(playerid, 1, 1);
								DynamicFactions[factionid][fBank] -= 10;
							}
							if(DynamicFactions[factionid][fGun1Rank2] == 5)
							{
								GivePlayerGun(playerid, 5, 1);
								DynamicFactions[factionid][fBank] -= 50;
							}
							if(DynamicFactions[factionid][fGun1Rank2] == 4)
							{
								GivePlayerGun(playerid, 4, 1);
								DynamicFactions[factionid][fBank] -= 100;
							}
							if(DynamicFactions[factionid][fGun2Rank2] == 3)	
							{
								GivePlayerGun(playerid, 3, 1);
								DynamicFactions[factionid][fBank] -= 35; 
							}
							if(DynamicFactions[factionid][fGun2Rank2] == 1)	
							{
								GivePlayerGun(playerid, 1, 1);
								DynamicFactions[factionid][fBank] -= 10;
							}
							if(DynamicFactions[factionid][fGun2Rank2] == 5)
							{
								GivePlayerGun(playerid, 5, 1);
								DynamicFactions[factionid][fBank] -= 50;
							}
							if(DynamicFactions[factionid][fGun2Rank2] == 4)
							{
								GivePlayerGun(playerid, 4, 1);
								DynamicFactions[factionid][fBank] -= 100;
							}
							if(DynamicFactions[factionid][fGun3Rank2] == 3)	
							{
								GivePlayerGun(playerid, 3, 1);
								DynamicFactions[factionid][fBank] -= 35; 
							}
							if(DynamicFactions[factionid][fGun3Rank2] == 1)	
							{
								GivePlayerGun(playerid, 1, 1);
								DynamicFactions[factionid][fBank] -= 10;
							}
							if(DynamicFactions[factionid][fGun3Rank2] == 5)
							{
								GivePlayerGun(playerid, 5, 1);
								DynamicFactions[factionid][fBank] -= 50;
							}
							if(DynamicFactions[factionid][fGun3Rank2] == 4)
							{
								GivePlayerGun(playerid, 4, 1);
								DynamicFactions[factionid][fBank] -= 100;
							}
							
							// SaveFData(factionid, "Bank");
							// format(string, sizeof(string), "[%s:] Brak piêdzy na koncie w frakcji na pobranie broni",DynamicFactions[factionid][Name],GetPlayerNameEx(playerid));
							// SendFactionMessage(8, COLOR_DARKPURPLE, string);
						}
						if(gPlayerData[playerid][pRank] == 3)
						{
							format(string, sizeof(string), "[%s:] %s pobra³ broñ.",DynamicFactions[factionid][Name],GetPlayerNameEx(playerid));
							SendFactionMessage(factionid, COLOR_DARKPURPLE, string);

							AddPlayerAmmoF(playerid, DynamicFactions[factionid][fGun1Rank3], DynamicFactions[factionid][fAmmo1Rank3]);
							AddPlayerAmmoF(playerid, DynamicFactions[factionid][fGun2Rank3], DynamicFactions[factionid][fAmmo2Rank3]);
							AddPlayerAmmoF(playerid, DynamicFactions[factionid][fGun3Rank3], DynamicFactions[factionid][fAmmo3Rank3]);

							// if(DynamicFactions[factionid][fGun1Rank3] == 25)	{ DynamicFactions[factionid][fBank] -= 700; }
							// if(DynamicFactions[factionid][fGun1Rank3] == 29)	{ DynamicFactions[factionid][fBank] -= 900; }
							// if(DynamicFactions[factionid][fGun1Rank3] == 28)	{ DynamicFactions[factionid][fBank] -= 800; }
							// if(DynamicFactions[factionid][fGun1Rank3] == 30)	{ DynamicFactions[factionid][fBank] -= 5000; }
							// if(DynamicFactions[factionid][fGun1Rank3] == 31)	{ DynamicFactions[factionid][fBank] -= 5000; }
							// if(DynamicFactions[factionid][fGun1Rank3] == 32)	{ DynamicFactions[factionid][fBank] -= 800; }
							// if(DynamicFactions[factionid][fGun1Rank3] == 33)	{ DynamicFactions[factionid][fBank] -= 1000; }
							// if(DynamicFactions[factionid][fGun1Rank3] == 34)	{ DynamicFactions[factionid][fBank] -= 10000; }

							// if(DynamicFactions[factionid][fGun2Rank3] == 22)	{ DynamicFactions[factionid][fBank] -= 300; }
							// if(DynamicFactions[factionid][fGun2Rank3] == 23)	{ DynamicFactions[factionid][fBank] -= 400; }
							// if(DynamicFactions[factionid][fGun2Rank3] == 24)	{ DynamicFactions[factionid][fBank] -= 1500; }

							if(DynamicFactions[factionid][fGun1Rank3] == 3)	
							{
								GivePlayerGun(playerid, 3, 1);
								DynamicFactions[factionid][fBank] -= 35; 
							}
							if(DynamicFactions[factionid][fGun1Rank3] == 1)	
							{
								GivePlayerGun(playerid, 1, 1);
								DynamicFactions[factionid][fBank] -= 10;
							}
							if(DynamicFactions[factionid][fGun1Rank3] == 5)
							{
								GivePlayerGun(playerid, 5, 1);
								DynamicFactions[factionid][fBank] -= 50;
							}
							if(DynamicFactions[factionid][fGun1Rank3] == 4)
							{
								GivePlayerGun(playerid, 4, 1);
								DynamicFactions[factionid][fBank] -= 100;
							}
							if(DynamicFactions[factionid][fGun2Rank3] == 3)	
							{
								GivePlayerGun(playerid, 3, 1);
								DynamicFactions[factionid][fBank] -= 35; 
							}
							if(DynamicFactions[factionid][fGun2Rank3] == 1)	
							{
								GivePlayerGun(playerid, 1, 1);
								DynamicFactions[factionid][fBank] -= 10;
							}
							if(DynamicFactions[factionid][fGun2Rank3] == 5)
							{
								GivePlayerGun(playerid, 5, 1);
								DynamicFactions[factionid][fBank] -= 50;
							}
							if(DynamicFactions[factionid][fGun2Rank3] == 4)
							{
								GivePlayerGun(playerid, 4, 1);
								DynamicFactions[factionid][fBank] -= 100;
							}
							if(DynamicFactions[factionid][fGun3Rank3] == 3)	
							{
								GivePlayerGun(playerid, 3, 1);
								DynamicFactions[factionid][fBank] -= 35; 
							}
							if(DynamicFactions[factionid][fGun3Rank3] == 1)	
							{
								GivePlayerGun(playerid, 1, 1);
								DynamicFactions[factionid][fBank] -= 10;
							}
							if(DynamicFactions[factionid][fGun3Rank3] == 5)
							{
								GivePlayerGun(playerid, 5, 1);
								DynamicFactions[factionid][fBank] -= 50;
							}
							if(DynamicFactions[factionid][fGun3Rank3] == 4)
							{
								GivePlayerGun(playerid, 4, 1);
								DynamicFactions[factionid][fBank] -= 100;
							}

							// SaveFData(factionid, "Bank");
							// format(string, sizeof(string), "[%s:] Brak piêdzy na koncie w frakcji na pobranie broni",DynamicFactions[factionid][Name],GetPlayerNameEx(playerid));
							// SendFactionMessage(8, COLOR_DARKPURPLE, string);
						}
						if(gPlayerData[playerid][pRank] == 4)
						{
							format(string, sizeof(string), "[%s:] %s pobra³ broñ.",DynamicFactions[factionid][Name],GetPlayerNameEx(playerid));
							SendFactionMessage(factionid, COLOR_DARKPURPLE, string);

							AddPlayerAmmoF(playerid, DynamicFactions[factionid][fGun1Rank4], DynamicFactions[factionid][fAmmo1Rank4]);
							AddPlayerAmmoF(playerid, DynamicFactions[factionid][fGun2Rank4], DynamicFactions[factionid][fAmmo2Rank4]);
							AddPlayerAmmoF(playerid, DynamicFactions[factionid][fGun3Rank4], DynamicFactions[factionid][fAmmo3Rank4]);

							// if(DynamicFactions[factionid][fGun1Rank4] == 25)	{ DynamicFactions[factionid][fBank] -= 700; }
							// if(DynamicFactions[factionid][fGun1Rank4] == 29)	{ DynamicFactions[factionid][fBank] -= 900; }
							// if(DynamicFactions[factionid][fGun1Rank4] == 28)	{ DynamicFactions[factionid][fBank] -= 800; }
							// if(DynamicFactions[factionid][fGun1Rank4] == 30)	{ DynamicFactions[factionid][fBank] -= 5000; }
							// if(DynamicFactions[factionid][fGun1Rank4] == 31)	{ DynamicFactions[factionid][fBank] -= 5000; }
							// if(DynamicFactions[factionid][fGun1Rank4] == 32)	{ DynamicFactions[factionid][fBank] -= 800; }
							// if(DynamicFactions[factionid][fGun1Rank4] == 33)	{ DynamicFactions[factionid][fBank] -= 1000; }
							// if(DynamicFactions[factionid][fGun1Rank4] == 34)	{ DynamicFactions[factionid][fBank] -= 10000; }

							// if(DynamicFactions[factionid][fGun2Rank4] == 22)	{ DynamicFactions[factionid][fBank] -= 300; }
							// if(DynamicFactions[factionid][fGun2Rank4] == 23)	{ DynamicFactions[factionid][fBank] -= 400; }
							// if(DynamicFactions[factionid][fGun2Rank4] == 24)	{ DynamicFactions[factionid][fBank] -= 1500; }

							if(DynamicFactions[factionid][fGun1Rank4] == 3)	
							{
								GivePlayerGun(playerid, 3, 1);
								DynamicFactions[factionid][fBank] -= 35; 
							}
							if(DynamicFactions[factionid][fGun1Rank4] == 1)	
							{
								GivePlayerGun(playerid, 1, 1);
								DynamicFactions[factionid][fBank] -= 10;
							}
							if(DynamicFactions[factionid][fGun1Rank4] == 5)
							{
								GivePlayerGun(playerid, 5, 1);
								DynamicFactions[factionid][fBank] -= 50;
							}
							if(DynamicFactions[factionid][fGun1Rank4] == 4)
							{
								GivePlayerGun(playerid, 4, 1);
								DynamicFactions[factionid][fBank] -= 100;
							}
							if(DynamicFactions[factionid][fGun2Rank4] == 3)	
							{
								GivePlayerGun(playerid, 3, 1);
								DynamicFactions[factionid][fBank] -= 35; 
							}
							if(DynamicFactions[factionid][fGun2Rank4] == 1)	
							{
								GivePlayerGun(playerid, 1, 1);
								DynamicFactions[factionid][fBank] -= 10;
							}
							if(DynamicFactions[factionid][fGun2Rank4] == 5)
							{
								GivePlayerGun(playerid, 5, 1);
								DynamicFactions[factionid][fBank] -= 50;
							}
							if(DynamicFactions[factionid][fGun2Rank4] == 4)
							{
								GivePlayerGun(playerid, 4, 1);
								DynamicFactions[factionid][fBank] -= 100;
							}
							if(DynamicFactions[factionid][fGun3Rank4] == 3)	
							{
								GivePlayerGun(playerid, 3, 1);
								DynamicFactions[factionid][fBank] -= 35; 
							}
							if(DynamicFactions[factionid][fGun3Rank4] == 1)	
							{
								GivePlayerGun(playerid, 1, 1);
								DynamicFactions[factionid][fBank] -= 10;
							}
							if(DynamicFactions[factionid][fGun3Rank4] == 5)
							{
								GivePlayerGun(playerid, 5, 1);
								DynamicFactions[factionid][fBank] -= 50;
							}
							if(DynamicFactions[factionid][fGun3Rank4] == 4)
							{
								GivePlayerGun(playerid, 4, 1);
								DynamicFactions[factionid][fBank] -= 100;
							}

							// SaveFData(factionid, "Bank");
							// format(string, sizeof(string), "[%s:] Brak piêdzy na koncie w frakcji na pobranie broni",DynamicFactions[factionid][Name],GetPlayerNameEx(playerid));
							// SendFactionMessage(8, COLOR_DARKPURPLE, string);
						}
						if(gPlayerData[playerid][pRank] == 5)
						{
							format(string, sizeof(string), "[%s:] %s pobra³ broñ.",DynamicFactions[factionid][Name],GetPlayerNameEx(playerid));
							SendFactionMessage(factionid, COLOR_DARKPURPLE, string);

							AddPlayerAmmoF(playerid, DynamicFactions[factionid][fGun1Rank5], DynamicFactions[factionid][fAmmo1Rank5]);
							AddPlayerAmmoF(playerid, DynamicFactions[factionid][fGun2Rank5], DynamicFactions[factionid][fAmmo2Rank5]);
							AddPlayerAmmoF(playerid, DynamicFactions[factionid][fGun3Rank5], DynamicFactions[factionid][fAmmo3Rank5]);

							// if(DynamicFactions[factionid][fGun1Rank5] == 25)	{ DynamicFactions[factionid][fBank] -= 700; }
							// if(DynamicFactions[factionid][fGun1Rank5] == 29)	{ DynamicFactions[factionid][fBank] -= 900; }
							// if(DynamicFactions[factionid][fGun1Rank5] == 28)	{ DynamicFactions[factionid][fBank] -= 800; }
							// if(DynamicFactions[factionid][fGun1Rank5] == 30)	{ DynamicFactions[factionid][fBank] -= 5000; }
							// if(DynamicFactions[factionid][fGun1Rank5] == 31)	{ DynamicFactions[factionid][fBank] -= 5000; }
							// if(DynamicFactions[factionid][fGun1Rank5] == 32)	{ DynamicFactions[factionid][fBank] -= 800; }
							// if(DynamicFactions[factionid][fGun1Rank5] == 33)	{ DynamicFactions[factionid][fBank] -= 1000; }
							// if(DynamicFactions[factionid][fGun1Rank5] == 34)	{ DynamicFactions[factionid][fBank] -= 10000; }

							// if(DynamicFactions[factionid][fGun2Rank5] == 22)	{ DynamicFactions[factionid][fBank] -= 300; }
							// if(DynamicFactions[factionid][fGun2Rank5] == 23)	{ DynamicFactions[factionid][fBank] -= 400; }
							// if(DynamicFactions[factionid][fGun2Rank5] == 24)	{ DynamicFactions[factionid][fBank] -= 1500; }

							if(DynamicFactions[factionid][fGun1Rank5] == 3)	
							{
								GivePlayerGun(playerid, 3, 1);
								DynamicFactions[factionid][fBank] -= 35; 
							}
							if(DynamicFactions[factionid][fGun1Rank5] == 1)	
							{
								GivePlayerGun(playerid, 1, 1);
								DynamicFactions[factionid][fBank] -= 10;
							}
							if(DynamicFactions[factionid][fGun1Rank5] == 5)
							{
								GivePlayerGun(playerid, 5, 1);
								DynamicFactions[factionid][fBank] -= 50;
							}
							if(DynamicFactions[factionid][fGun1Rank5] == 4)
							{
								GivePlayerGun(playerid, 4, 1);
								DynamicFactions[factionid][fBank] -= 100;
							}
							if(DynamicFactions[factionid][fGun2Rank5] == 3)	
							{
								GivePlayerGun(playerid, 3, 1);
								DynamicFactions[factionid][fBank] -= 35; 
							}
							if(DynamicFactions[factionid][fGun2Rank5] == 1)	
							{
								GivePlayerGun(playerid, 1, 1);
								DynamicFactions[factionid][fBank] -= 10;
							}
							if(DynamicFactions[factionid][fGun2Rank5] == 5)
							{
								GivePlayerGun(playerid, 5, 1);
								DynamicFactions[factionid][fBank] -= 50;
							}
							if(DynamicFactions[factionid][fGun2Rank5] == 4)
							{
								GivePlayerGun(playerid, 4, 1);
								DynamicFactions[factionid][fBank] -= 100;
							}
							if(DynamicFactions[factionid][fGun3Rank5] == 3)	
							{
								GivePlayerGun(playerid, 3, 1);
								DynamicFactions[factionid][fBank] -= 35; 
							}
							if(DynamicFactions[factionid][fGun3Rank5] == 1)	
							{
								GivePlayerGun(playerid, 1, 1);
								DynamicFactions[factionid][fBank] -= 10;
							}
							if(DynamicFactions[factionid][fGun3Rank5] == 5)
							{
								GivePlayerGun(playerid, 5, 1);
								DynamicFactions[factionid][fBank] -= 50;
							}
							if(DynamicFactions[factionid][fGun3Rank5] == 4)
							{
								GivePlayerGun(playerid, 4, 1);
								DynamicFactions[factionid][fBank] -= 100;
							}

							// SaveFData(factionid, "Bank");
							// format(string, sizeof(string), "[%s:] Brak piêdzy na koncie w frakcji na pobranie broni",DynamicFactions[factionid][Name],GetPlayerNameEx(playerid));
							// SendFactionMessage(8, COLOR_DARKPURPLE, string);
						}
						if(gPlayerData[playerid][pRank] == 6)
						{
							format(string, sizeof(string), "[%s:] %s pobra³ broñ.",DynamicFactions[factionid][Name],GetPlayerNameEx(playerid));
							SendFactionMessage(factionid, COLOR_DARKPURPLE, string);

							AddPlayerAmmoF(playerid, DynamicFactions[factionid][fGun1Rank6], DynamicFactions[factionid][fAmmo1Rank6]);
							AddPlayerAmmoF(playerid, DynamicFactions[factionid][fGun2Rank6], DynamicFactions[factionid][fAmmo2Rank6]);
							AddPlayerAmmoF(playerid, DynamicFactions[factionid][fGun3Rank6], DynamicFactions[factionid][fAmmo3Rank6]);

							// if(DynamicFactions[factionid][fGun1Rank6] == 25)	{ DynamicFactions[factionid][fBank] -= 700; }
							// if(DynamicFactions[factionid][fGun1Rank6] == 29)	{ DynamicFactions[factionid][fBank] -= 900; }
							// if(DynamicFactions[factionid][fGun1Rank6] == 28)	{ DynamicFactions[factionid][fBank] -= 800; }
							// if(DynamicFactions[factionid][fGun1Rank6] == 30)	{ DynamicFactions[factionid][fBank] -= 5000; }
							// if(DynamicFactions[factionid][fGun1Rank6] == 31)	{ DynamicFactions[factionid][fBank] -= 5000; }
							// if(DynamicFactions[factionid][fGun1Rank6] == 32)	{ DynamicFactions[factionid][fBank] -= 800; }
							// if(DynamicFactions[factionid][fGun1Rank6] == 33)	{ DynamicFactions[factionid][fBank] -= 1000; }
							// if(DynamicFactions[factionid][fGun1Rank6] == 34)	{ DynamicFactions[factionid][fBank] -= 10000; }

							// if(DynamicFactions[factionid][fGun2Rank6] == 22)	{ DynamicFactions[factionid][fBank] -= 300; }
							// if(DynamicFactions[factionid][fGun2Rank6] == 23)	{ DynamicFactions[factionid][fBank] -= 400; }
							// if(DynamicFactions[factionid][fGun2Rank6] == 24)	{ DynamicFactions[factionid][fBank] -= 1500; }

							if(DynamicFactions[factionid][fGun1Rank6] == 3)	
							{
								GivePlayerGun(playerid, 3, 1);
								DynamicFactions[factionid][fBank] -= 35; 
							}
							if(DynamicFactions[factionid][fGun1Rank6] == 1)	
							{
								GivePlayerGun(playerid, 1, 1);
								DynamicFactions[factionid][fBank] -= 10;
							}
							if(DynamicFactions[factionid][fGun1Rank6] == 5)
							{
								GivePlayerGun(playerid, 5, 1);
								DynamicFactions[factionid][fBank] -= 50;
							}
							if(DynamicFactions[factionid][fGun1Rank6] == 4)
							{
								GivePlayerGun(playerid, 4, 1);
								DynamicFactions[factionid][fBank] -= 100;
							}
							if(DynamicFactions[factionid][fGun2Rank6] == 3)	
							{
								GivePlayerGun(playerid, 3, 1);
								DynamicFactions[factionid][fBank] -= 35; 
							}
							if(DynamicFactions[factionid][fGun2Rank6] == 1)	
							{
								GivePlayerGun(playerid, 1, 1);
								DynamicFactions[factionid][fBank] -= 10;
							}
							if(DynamicFactions[factionid][fGun2Rank6] == 5)
							{
								GivePlayerGun(playerid, 5, 1);
								DynamicFactions[factionid][fBank] -= 50;
							}
							if(DynamicFactions[factionid][fGun2Rank6] == 4)
							{
								GivePlayerGun(playerid, 4, 1);
								DynamicFactions[factionid][fBank] -= 100;
							}
							if(DynamicFactions[factionid][fGun3Rank6] == 3)	
							{
								GivePlayerGun(playerid, 3, 1);
								DynamicFactions[factionid][fBank] -= 35; 
							}
							if(DynamicFactions[factionid][fGun3Rank6] == 1)	
							{
								GivePlayerGun(playerid, 1, 1);
								DynamicFactions[factionid][fBank] -= 10;
							}
							if(DynamicFactions[factionid][fGun3Rank6] == 5)
							{
								GivePlayerGun(playerid, 5, 1);
								DynamicFactions[factionid][fBank] -= 50;
							}
							if(DynamicFactions[factionid][fGun3Rank6] == 4)
							{
								GivePlayerGun(playerid, 4, 1);
								DynamicFactions[factionid][fBank] -= 100;
							}

							// SaveFData(factionid, "Bank");
							// format(string, sizeof(string), "[%s:] Brak piêdzy na koncie w frakcji na pobranie broni",DynamicFactions[factionid][Name],GetPlayerNameEx(playerid));
							// SendFactionMessage(8, COLOR_DARKPURPLE, string);
						}
						if(gPlayerData[playerid][pRank] == 7)
						{
							format(string, sizeof(string), "[%s:] %s pobra³ broñ.",DynamicFactions[factionid][Name],GetPlayerNameEx(playerid));
							SendFactionMessage(factionid, COLOR_DARKPURPLE, string);

							AddPlayerAmmoF(playerid, DynamicFactions[factionid][fGun1Rank7], DynamicFactions[factionid][fAmmo1Rank7]);
							AddPlayerAmmoF(playerid, DynamicFactions[factionid][fGun2Rank7], DynamicFactions[factionid][fAmmo2Rank7]);
							AddPlayerAmmoF(playerid, DynamicFactions[factionid][fGun3Rank7], DynamicFactions[factionid][fAmmo3Rank7]);

							// if(DynamicFactions[factionid][fGun1Rank7] == 25)	{ DynamicFactions[factionid][fBank] -= 700; }
							// if(DynamicFactions[factionid][fGun1Rank7] == 29)	{ DynamicFactions[factionid][fBank] -= 900; }
							// if(DynamicFactions[factionid][fGun1Rank7] == 28)	{ DynamicFactions[factionid][fBank] -= 800; }
							// if(DynamicFactions[factionid][fGun1Rank7] == 30)	{ DynamicFactions[factionid][fBank] -= 5000; }
							// if(DynamicFactions[factionid][fGun1Rank7] == 31)	{ DynamicFactions[factionid][fBank] -= 5000; }
							// if(DynamicFactions[factionid][fGun1Rank7] == 32)	{ DynamicFactions[factionid][fBank] -= 800; }
							// if(DynamicFactions[factionid][fGun1Rank7] == 33)	{ DynamicFactions[factionid][fBank] -= 1000; }
							// if(DynamicFactions[factionid][fGun1Rank7] == 34)	{ DynamicFactions[factionid][fBank] -= 10000; }

							// if(DynamicFactions[factionid][fGun2Rank7] == 22)	{ DynamicFactions[factionid][fBank] -= 300; }
							// if(DynamicFactions[factionid][fGun2Rank7] == 23)	{ DynamicFactions[factionid][fBank] -= 400; }
							// if(DynamicFactions[factionid][fGun2Rank7] == 24)	{ DynamicFactions[factionid][fBank] -= 1500; }

							if(DynamicFactions[factionid][fGun1Rank7] == 3)	
							{
								GivePlayerGun(playerid, 3, 1);
								DynamicFactions[factionid][fBank] -= 35; 
							}
							if(DynamicFactions[factionid][fGun1Rank7] == 1)	
							{
								GivePlayerGun(playerid, 1, 1);
								DynamicFactions[factionid][fBank] -= 10;
							}
							if(DynamicFactions[factionid][fGun1Rank7] == 5)
							{
								GivePlayerGun(playerid, 5, 1);
								DynamicFactions[factionid][fBank] -= 50;
							}
							if(DynamicFactions[factionid][fGun1Rank7] == 4)
							{
								GivePlayerGun(playerid, 4, 1);
								DynamicFactions[factionid][fBank] -= 100;
							}
							if(DynamicFactions[factionid][fGun2Rank7] == 3)	
							{
								GivePlayerGun(playerid, 3, 1);
								DynamicFactions[factionid][fBank] -= 35; 
							}
							if(DynamicFactions[factionid][fGun2Rank7] == 1)	
							{
								GivePlayerGun(playerid, 1, 1);
								DynamicFactions[factionid][fBank] -= 10;
							}
							if(DynamicFactions[factionid][fGun2Rank7] == 5)
							{
								GivePlayerGun(playerid, 5, 1);
								DynamicFactions[factionid][fBank] -= 50;
							}
							if(DynamicFactions[factionid][fGun2Rank7] == 4)
							{
								GivePlayerGun(playerid, 4, 1);
								DynamicFactions[factionid][fBank] -= 100;
							}
							if(DynamicFactions[factionid][fGun3Rank7] == 3)	
							{
								GivePlayerGun(playerid, 3, 1);
								DynamicFactions[factionid][fBank] -= 35; 
							}
							if(DynamicFactions[factionid][fGun3Rank7] == 1)	
							{
								GivePlayerGun(playerid, 1, 1);
								DynamicFactions[factionid][fBank] -= 10;
							}
							if(DynamicFactions[factionid][fGun3Rank7] == 5)
							{
								GivePlayerGun(playerid, 5, 1);
								DynamicFactions[factionid][fBank] -= 50;
							}
							if(DynamicFactions[factionid][fGun3Rank7] == 4)
							{
								GivePlayerGun(playerid, 4, 1);
								DynamicFactions[factionid][fBank] -= 100;
							}

							// SaveFData(factionid, "Bank");
							// format(string, sizeof(string), "[%s:] Brak piêdzy na koncie w frakcji na pobranie broni",DynamicFactions[factionid][Name],GetPlayerNameEx(playerid));
							// SendFactionMessage(8, COLOR_DARKPURPLE, string);
						}
						if(gPlayerData[playerid][pRank] == 8)
						{
							format(string, sizeof(string), "[%s:] %s pobra³ broñ.",DynamicFactions[factionid][Name],GetPlayerNameEx(playerid));
							SendFactionMessage(factionid, COLOR_DARKPURPLE, string);

							AddPlayerAmmoF(playerid, DynamicFactions[factionid][fGun1Rank8], DynamicFactions[factionid][fAmmo1Rank8]);
							AddPlayerAmmoF(playerid, DynamicFactions[factionid][fGun2Rank8], DynamicFactions[factionid][fAmmo2Rank8]);
							AddPlayerAmmoF(playerid, DynamicFactions[factionid][fGun3Rank8], DynamicFactions[factionid][fAmmo3Rank8]);

							// if(DynamicFactions[factionid][fGun1Rank8] == 25)	{ DynamicFactions[factionid][fBank] -= 700; }
							// if(DynamicFactions[factionid][fGun1Rank8] == 29)	{ DynamicFactions[factionid][fBank] -= 900; }
							// if(DynamicFactions[factionid][fGun1Rank8] == 28)	{ DynamicFactions[factionid][fBank] -= 800; }
							// if(DynamicFactions[factionid][fGun1Rank8] == 30)	{ DynamicFactions[factionid][fBank] -= 5000; }
							// if(DynamicFactions[factionid][fGun1Rank8] == 31)	{ DynamicFactions[factionid][fBank] -= 5000; }
							// if(DynamicFactions[factionid][fGun1Rank8] == 32)	{ DynamicFactions[factionid][fBank] -= 800; }
							// if(DynamicFactions[factionid][fGun1Rank8] == 33)	{ DynamicFactions[factionid][fBank] -= 1000; }
							// if(DynamicFactions[factionid][fGun1Rank8] == 34)	{ DynamicFactions[factionid][fBank] -= 10000; }

							// if(DynamicFactions[factionid][fGun2Rank8] == 22)	{ DynamicFactions[factionid][fBank] -= 300; }
							// if(DynamicFactions[factionid][fGun2Rank8] == 23)	{ DynamicFactions[factionid][fBank] -= 400; }
							// if(DynamicFactions[factionid][fGun2Rank8] == 24)	{ DynamicFactions[factionid][fBank] -= 1500; }

							if(DynamicFactions[factionid][fGun1Rank8] == 3)	
							{
								GivePlayerGun(playerid, 3, 1);
								DynamicFactions[factionid][fBank] -= 35; 
							}
							if(DynamicFactions[factionid][fGun1Rank8] == 1)	
							{
								GivePlayerGun(playerid, 1, 1);
								DynamicFactions[factionid][fBank] -= 10;
							}
							if(DynamicFactions[factionid][fGun1Rank8] == 5)
							{
								GivePlayerGun(playerid, 5, 1);
								DynamicFactions[factionid][fBank] -= 50;
							}
							if(DynamicFactions[factionid][fGun1Rank8] == 4)
							{
								GivePlayerGun(playerid, 4, 1);
								DynamicFactions[factionid][fBank] -= 100;
							}
							if(DynamicFactions[factionid][fGun2Rank8] == 3)	
							{
								GivePlayerGun(playerid, 3, 1);
								DynamicFactions[factionid][fBank] -= 35; 
							}
							if(DynamicFactions[factionid][fGun2Rank8] == 1)	
							{
								GivePlayerGun(playerid, 1, 1);
								DynamicFactions[factionid][fBank] -= 10;
							}
							if(DynamicFactions[factionid][fGun2Rank8] == 5)
							{
								GivePlayerGun(playerid, 5, 1);
								DynamicFactions[factionid][fBank] -= 50;
							}
							if(DynamicFactions[factionid][fGun2Rank8] == 4)
							{
								GivePlayerGun(playerid, 4, 1);
								DynamicFactions[factionid][fBank] -= 100;
							}
							if(DynamicFactions[factionid][fGun3Rank8] == 3)	
							{
								GivePlayerGun(playerid, 3, 1);
								DynamicFactions[factionid][fBank] -= 35; 
							}
							if(DynamicFactions[factionid][fGun3Rank8] == 1)	
							{
								GivePlayerGun(playerid, 1, 1);
								DynamicFactions[factionid][fBank] -= 10;
							}
							if(DynamicFactions[factionid][fGun3Rank8] == 5)
							{
								GivePlayerGun(playerid, 5, 1);
								DynamicFactions[factionid][fBank] -= 50;
							}
							if(DynamicFactions[factionid][fGun3Rank8] == 4)
							{
								GivePlayerGun(playerid, 4, 1);
								DynamicFactions[factionid][fBank] -= 100;
							}

							// SaveFData(factionid, "Bank");
							// format(string, sizeof(string), "[%s:] Brak piêdzy na koncie w frakcji na pobranie broni",DynamicFactions[factionid][Name],GetPlayerNameEx(playerid));
							// SendFactionMessage(8, COLOR_DARKPURPLE, string);
						}
						if(gPlayerData[playerid][pRank] == 9)
						{
							format(string, sizeof(string), "[%s:] %s pobra³ broñ.",DynamicFactions[factionid][Name],GetPlayerNameEx(playerid));
							SendFactionMessage(factionid, COLOR_DARKPURPLE, string);

							AddPlayerAmmoF(playerid, DynamicFactions[factionid][fGun1Rank9], DynamicFactions[factionid][fAmmo1Rank9]);
							AddPlayerAmmoF(playerid, DynamicFactions[factionid][fGun2Rank9], DynamicFactions[factionid][fAmmo2Rank9]);
							AddPlayerAmmoF(playerid, DynamicFactions[factionid][fGun3Rank9], DynamicFactions[factionid][fAmmo3Rank9]);

							// if(DynamicFactions[factionid][fGun1Rank9] == 25)	{ DynamicFactions[factionid][fBank] -= 700; }
							// if(DynamicFactions[factionid][fGun1Rank9] == 29)	{ DynamicFactions[factionid][fBank] -= 900; }
							// if(DynamicFactions[factionid][fGun1Rank9] == 28)	{ DynamicFactions[factionid][fBank] -= 800; }
							// if(DynamicFactions[factionid][fGun1Rank9] == 30)	{ DynamicFactions[factionid][fBank] -= 5000; }
							// if(DynamicFactions[factionid][fGun1Rank9] == 31)	{ DynamicFactions[factionid][fBank] -= 5000; }
							// if(DynamicFactions[factionid][fGun1Rank9] == 32)	{ DynamicFactions[factionid][fBank] -= 800; }
							// if(DynamicFactions[factionid][fGun1Rank9] == 33)	{ DynamicFactions[factionid][fBank] -= 1000; }
							// if(DynamicFactions[factionid][fGun1Rank9] == 34)	{ DynamicFactions[factionid][fBank] -= 10000; }

							// if(DynamicFactions[factionid][fGun2Rank9] == 22)	{ DynamicFactions[factionid][fBank] -= 300; }
							// if(DynamicFactions[factionid][fGun2Rank9] == 23)	{ DynamicFactions[factionid][fBank] -= 400; }
							// if(DynamicFactions[factionid][fGun2Rank9] == 24)	{ DynamicFactions[factionid][fBank] -= 1500; }

							if(DynamicFactions[factionid][fGun1Rank9] == 3)	
							{
								GivePlayerGun(playerid, 3, 1);
								DynamicFactions[factionid][fBank] -= 35; 
							}
							if(DynamicFactions[factionid][fGun1Rank9] == 1)	
							{
								GivePlayerGun(playerid, 1, 1);
								DynamicFactions[factionid][fBank] -= 10;
							}
							if(DynamicFactions[factionid][fGun1Rank9] == 5)
							{
								GivePlayerGun(playerid, 5, 1);
								DynamicFactions[factionid][fBank] -= 50;
							}
							if(DynamicFactions[factionid][fGun1Rank9] == 4)
							{
								GivePlayerGun(playerid, 4, 1);
								DynamicFactions[factionid][fBank] -= 100;
							}
							if(DynamicFactions[factionid][fGun2Rank9] == 3)	
							{
								GivePlayerGun(playerid, 3, 1);
								DynamicFactions[factionid][fBank] -= 35; 
							}
							if(DynamicFactions[factionid][fGun2Rank9] == 1)	
							{
								GivePlayerGun(playerid, 1, 1);
								DynamicFactions[factionid][fBank] -= 10;
							}
							if(DynamicFactions[factionid][fGun2Rank9] == 5)
							{
								GivePlayerGun(playerid, 5, 1);
								DynamicFactions[factionid][fBank] -= 50;
							}
							if(DynamicFactions[factionid][fGun2Rank9] == 4)
							{
								GivePlayerGun(playerid, 4, 1);
								DynamicFactions[factionid][fBank] -= 100;
							}
							if(DynamicFactions[factionid][fGun3Rank9] == 3)	
							{
								GivePlayerGun(playerid, 3, 1);
								DynamicFactions[factionid][fBank] -= 35; 
							}
							if(DynamicFactions[factionid][fGun3Rank9] == 1)	
							{
								GivePlayerGun(playerid, 1, 1);
								DynamicFactions[factionid][fBank] -= 10;
							}
							if(DynamicFactions[factionid][fGun3Rank9] == 5)
							{
								GivePlayerGun(playerid, 5, 1);
								DynamicFactions[factionid][fBank] -= 50;
							}
							if(DynamicFactions[factionid][fGun3Rank9] == 4)
							{
								GivePlayerGun(playerid, 4, 1);
								DynamicFactions[factionid][fBank] -= 100;
							}

							// SaveFData(factionid, "Bank");
							// format(string, sizeof(string), "[%s:] Brak piêdzy na koncie w frakcji na pobranie broni",DynamicFactions[factionid][Name],GetPlayerNameEx(playerid));
							// SendFactionMessage(8, COLOR_DARKPURPLE, string);
						}
						if(gPlayerData[playerid][pRank] == 10)
						{
							format(string, sizeof(string), "[%s:] %s pobra³ broñ.",DynamicFactions[factionid][Name],GetPlayerNameEx(playerid));
							SendFactionMessage(factionid, COLOR_DARKPURPLE, string);

							AddPlayerAmmoF(playerid, DynamicFactions[factionid][fGun1Rank10], DynamicFactions[factionid][fAmmo1Rank10]);
							AddPlayerAmmoF(playerid, DynamicFactions[factionid][fGun2Rank10], DynamicFactions[factionid][fAmmo2Rank10]);
							AddPlayerAmmoF(playerid, DynamicFactions[factionid][fGun3Rank10], DynamicFactions[factionid][fAmmo3Rank10]);

							// if(DynamicFactions[factionid][fGun1Rank1] == 25)	{ DynamicFactions[factionid][fBank] -= 700; }
							// if(DynamicFactions[factionid][fGun1Rank1] == 29)	{ DynamicFactions[factionid][fBank] -= 900; }
							// if(DynamicFactions[factionid][fGun1Rank1] == 28)	{ DynamicFactions[factionid][fBank] -= 800; }
							// if(DynamicFactions[factionid][fGun1Rank1] == 30)	{ DynamicFactions[factionid][fBank] -= 5000; }
							// if(DynamicFactions[factionid][fGun1Rank1] == 31)	{ DynamicFactions[factionid][fBank] -= 5000; }
							// if(DynamicFactions[factionid][fGun1Rank1] == 32)	{ DynamicFactions[factionid][fBank] -= 800; }
							// if(DynamicFactions[factionid][fGun1Rank1] == 33)	{ DynamicFactions[factionid][fBank] -= 1000; }
							// if(DynamicFactions[factionid][fGun1Rank1] == 34)	{ DynamicFactions[factionid][fBank] -= 10000; }

							// if(DynamicFactions[factionid][fGun2Rank1] == 22)	{ DynamicFactions[factionid][fBank] -= 300; }
							// if(DynamicFactions[factionid][fGun2Rank1] == 23)	{ DynamicFactions[factionid][fBank] -= 400; }
							// if(DynamicFactions[factionid][fGun2Rank1] == 24)	{ DynamicFactions[factionid][fBank] -= 1500; }

							if(DynamicFactions[factionid][fGun1Rank10] == 3)	
							{
								GivePlayerGun(playerid, 3, 1);
								DynamicFactions[factionid][fBank] -= 35; 
							}
							if(DynamicFactions[factionid][fGun1Rank10] == 1)	
							{
								GivePlayerGun(playerid, 1, 1);
								DynamicFactions[factionid][fBank] -= 10;
							}
							if(DynamicFactions[factionid][fGun1Rank10] == 5)
							{
								GivePlayerGun(playerid, 5, 1);
								DynamicFactions[factionid][fBank] -= 50;
							}
							if(DynamicFactions[factionid][fGun1Rank10] == 4)
							{
								GivePlayerGun(playerid, 4, 1);
								DynamicFactions[factionid][fBank] -= 100;
							}
							if(DynamicFactions[factionid][fGun2Rank10] == 3)	
							{
								GivePlayerGun(playerid, 3, 1);
								DynamicFactions[factionid][fBank] -= 35; 
							}
							if(DynamicFactions[factionid][fGun2Rank10] == 1)	
							{
								GivePlayerGun(playerid, 1, 1);
								DynamicFactions[factionid][fBank] -= 10;
							}
							if(DynamicFactions[factionid][fGun2Rank10] == 5)
							{
								GivePlayerGun(playerid, 5, 1);
								DynamicFactions[factionid][fBank] -= 50;
							}
							if(DynamicFactions[factionid][fGun2Rank10] == 4)
							{
								GivePlayerGun(playerid, 4, 1);
								DynamicFactions[factionid][fBank] -= 100;
							}
							if(DynamicFactions[factionid][fGun3Rank10] == 3)	
							{
								GivePlayerGun(playerid, 3, 1);
								DynamicFactions[factionid][fBank] -= 35; 
							}
							if(DynamicFactions[factionid][fGun3Rank10] == 1)	
							{
								GivePlayerGun(playerid, 1, 1);
								DynamicFactions[factionid][fBank] -= 10;
							}
							if(DynamicFactions[factionid][fGun3Rank10] == 5)
							{
								GivePlayerGun(playerid, 5, 1);
								DynamicFactions[factionid][fBank] -= 50;
							}
							if(DynamicFactions[factionid][fGun3Rank10] == 4)
							{
								GivePlayerGun(playerid, 4, 1);
								DynamicFactions[factionid][fBank] -= 100;
							}

							// SaveFData(factionid, "Bank");
							// format(string, sizeof(string), "[%s:] Brak piêdzy na koncie w frakcji na pobranie broni",DynamicFactions[factionid][Name],GetPlayerNameEx(playerid));
							// SendFactionMessage(8, COLOR_DARKPURPLE, string);
						}
						SaveFData(factionid, "Bank");
						return 1;
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie jesteœ na miejscu zg³oszania na s³u¿be !");
					return 1;
				}
			}
			else
			{
				new tmpstring[256];
				format(tmpstring, sizeof(tmpstring), "Frakcja: %d, Typ: %d",gPlayerData[playerid][pFaction], DynamicFactions[gPlayerData[playerid][pFaction]][fType]);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Niew³aœciwa frakcja/typ.");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, tmpstring);
				return 1;
			}
			return 1;
		}
		if(strcmp(cmd, "/wanted", true) == 0)
		{
			if(gPlayerData[playerid][pFaction] == 255)
			{
				SendClientMessage(playerid, COLOR_RED, "[INFO:] Niew³aœciwa frakcja !");
				return 1;
			}
			if(DynamicFactions[gPlayerData[playerid][pFaction]][fType] != 1)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Niew³aœciwa frakcja !");
				return 1;
			}
			if(!gPlayerData[playerid][pDuty] && gPlayerData[playerid][pAdmin] == 0)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie jesteœ na s³u¿bie !");
				return 1;
			}
			new count = 0;
			SendClientMessage(playerid, COLOR_LIGHTGREEN, "-----------[Poszukiwani]-----------");
			foreach(Player, i )
			{
				if(WantedLevel[i] >= 1)
				{
					format(string, sizeof(string), "[WANTED:] %s (ID:%d) -  Priorytet poszukiwania: %d.",GetPlayerNameEx(i),i,WantedLevel[i]);
					SendClientMessage(playerid,COLOR_WHITE,string);
					count++;
				}
			}
			if(count == 0)
			{
				SendClientMessage(playerid,COLOR_WHITE,"[INFO:] Aktualnie brak zg³oszeñ.");
			}
			SendClientMessage(playerid, COLOR_LIGHTGREEN, "------------------------------------------------");
			return 1;
		}
		if(strcmp(cmd, "/skuj", true) == 0)
		{
			if(IsPlayerInAnyVehicle(playerid))
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz skuæ kogoœ w pojeŸdzie !");
				return 1;
			}
			if(gPlayerData[playerid][pFaction] == 255)
			{
				SendClientMessage(playerid, COLOR_RED, "[INFO:] Niew³aœciwa frakcja !");
				return 1;
			}
			if(DynamicFactions[gPlayerData[playerid][pFaction]][fType] != 1)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Niew³aœciwa frakcja.");
				return 1;
			}
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp)) 
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /skuj [playerid]");
				return 1;
			}
			if(!gPlayerData[playerid][pDuty])
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie jesteœ na s³u¿bie.");
				return 1;
			}
			giveplayerid = ReturnUser(tmp);
			if(!IsPlayerConnected(giveplayerid))
			{
				SendClientMessage(playerid, COLOR_RED, "[B£¥D:] Dany gracz nie jest online !");
				return 1;
			}
			if(PlayerCuffed[giveplayerid] == 1)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Ta osoba jest ju¿ w kajdankach.");
				return 1;
			}
			if (ProxDetectorS(1.5, playerid, giveplayerid))
			{
				if(giveplayerid == playerid) { SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie mo¿esz sam siebie ubezw³asnowolniæ!"); return 1; }
				PlayerActionMessage(playerid,15.0,"wyjmuje kajdanki i skuwa podejrzanego");
				format(string, sizeof(string), "[INFO:] Zosta³eœ ubezw³asnowolniony przez %s.", GetPlayerNameEx(playerid));
				SendClientMessage(giveplayerid, COLOR_RED, string);
				format(string, sizeof(string), "[INFO:] %s zosta³ ubezw³asnowolniony.", GetPlayerNameEx(giveplayerid));
				SendClientMessage(playerid, COLOR_WHITE, string);
				TogglePlayerControllable(giveplayerid, 0);
				PlayerCuffed[giveplayerid] = 1;
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Gracz nie jest wystarczaj¹co blisko Ciebie !");
				return 1;
			}
			return 1;
		}
		if(strcmp(cmd, "/rozkuj", true) == 0)
		{
			if(gPlayerData[playerid][pFaction] == 255)
			{
				SendClientMessage(playerid, COLOR_RED, "[INFO:] Niew³aœciwa frakcja !");
				return 1;
			}
			if(DynamicFactions[gPlayerData[playerid][pFaction]][fType] != 1)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Niew³aœciwa frakcja.");
				return 1;
			}
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp)) 
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /rozkuj [playerid]");
				return 1;
			}
			if(gPlayerData[playerid][pDuty] == 0)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] nie jesteœ na s³u¿bie.");
				return 1;
			}
			giveplayerid = ReturnUser(tmp);
			if(!IsPlayerConnected(giveplayerid))
			{
				SendClientMessage(playerid, COLOR_RED, "[B£¥D:] Dany gracz nie jest online !");
				return 1;
			}
			if(PlayerCuffed[giveplayerid] == 0)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Ta osoba nie jest skuta.");
				return 1;
			}
			if (ProxDetectorS(1.5, playerid, giveplayerid))
			{
				if(giveplayerid == playerid) { SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie mo¿esz sam siebie rozkuæ !"); return 1; }
				format(string, sizeof(string), "[INFO:] Rozkuty przez %s.", GetPlayerNameEx(playerid));
				SendClientMessage(giveplayerid, COLOR_RED, string);
				format(string, sizeof(string), "[INFO:] %s rozkuty.", GetPlayerNameEx(giveplayerid));
				SendClientMessage(playerid, COLOR_WHITE, string);
				TogglePlayerControllable(giveplayerid, 1);
				PlayerCuffed[giveplayerid] = 0;
				return 1;
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Gracz nie jest wystarczaj¹co blisko Ciebie !");
				return 1;
			}
		}
		if(strcmp(cmd,"/rewiduj",true)==0)
		{
			if(IsPlayerConnected(playerid))
			{
				tmp = strtok(cmdtext, idx);
				if(!strlen(tmp))
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /rewiduj [playerid]");
					return 1;
				}
				giveplayerid = ReturnUser(tmp);
				if(gPlayerData[playerid][pFaction] == 255)
				{
					SendClientMessage(playerid, COLOR_RED, "[INFO:] Niew³aœciwa frakcja !");
					return 1;
				}
				if(DynamicFactions[gPlayerData[playerid][pFaction]][fType] != 1)
				{
					SendClientMessage(playerid, COLOR_RED, "[INFO:] Niew³aœciwa frakcja !");
					return 1;
				}
				if(IsPlayerConnected(giveplayerid))
				{
					if(giveplayerid != INVALID_PLAYER_ID)
					{
						if (ProxDetectorS(8.0, playerid, giveplayerid))
						{
							if(giveplayerid == playerid) { SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie mo¿esz sam siebie zrewidowaæ!"); return 1; }
							if(gPlayerData[playerid][pDuty] == 0) { SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie jesteœ na s³u¿bie."); return 1; }
							new text1[128], text2[128];
							if(gPlayerData[giveplayerid][pDrugs] > 0) { text1 = "[REWIZJA:] Znaleziono narkotyki."; } else { text1 = "[REWIZJA:] Brak znalezionych narkotyków."; }
							if(gPlayerData[giveplayerid][pMaterials] > 0) { text2 = "[REWIZJA:] Znaleziono czêœci do broni."; } else { text2 = "[REWIZJA:] Brak czêœci do broni."; }
							format(string, sizeof(string), "-------------------[%s]-------------------", GetPlayerNameEx(giveplayerid));
							SendClientMessage(playerid, COLOR_LIGHTGREEN, string);
							format(string, sizeof(string), "%s", text1);
							SendClientMessage(playerid, COLOR_WHITE, string);
							format(string, sizeof(string), "%s", text2);
							SendClientMessage(playerid, COLOR_WHITE, string);
							new Player_Weapons[13];
							new Player_Ammos[13];
							new i;
							new weaponName[128];
							for(i = 1;i <= 12;i++)
							{
								GetPlayerWeaponData(giveplayerid,i,Player_Weapons[i],Player_Ammos[i]);
								if(Player_Weapons[i] != 0)
								{

									GetWeaponName(Player_Weapons[i],weaponName,255);
									format(string,255,"[FRISK:] Znalezione bronie: %s.",weaponName);
									SendClientMessage(playerid,COLOR_WHITE,string);
								}
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie wystarczaj¹co blisko !");
							return 1;
						}
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Niew³aœciwe ID.");
					return 1;
				}
			}
			return 1;
		}
		if(strcmp(cmd, "/skonfiskuj", true) == 0)
		{
			if(gPlayerData[playerid][pFaction] != 255 && DynamicFactions[gPlayerData[playerid][pFaction]][fType] == 1)
			{
				new x_nr[256];
				x_nr = strtok(cmdtext, idx);
				if(!strlen(x_nr)) {
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /skonfiskuj [rzecz] [playerid]");
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[RZECZ:] prawko, licencjepilota, licencjenabron, narkotyki, materia³y, bron, licencjenalodz");
					return 1;
				}
				if(strcmp(x_nr,"prawko",true) == 0)
				{
					tmp = strtok(cmdtext, idx);
					if(!strlen(tmp)) {
						SendClientMessage(playerid, COLOR_WHITE, "[INFO:] /skonfiskuj prawko [playerid]");
						return 1;
					}
					giveplayerid = ReturnUser(tmp);
					if(IsPlayerConnected(giveplayerid))
					{
						if(giveplayerid != INVALID_PLAYER_ID)
						{
							if (ProxDetectorS(8.0, playerid, giveplayerid))
							{
								format(string, sizeof(string), "[INFO:] Prawo jazdy %s zosta³o skonfiskowane.", GetPlayerNameEx(giveplayerid));
								SendClientMessage(playerid, COLOR_WHITE, string);
								format(string, sizeof(string), "[INFO:] %s odebra³ Tobie prawo jazdy.", GetPlayerNameEx(playerid));
								SendClientMessage(giveplayerid, COLOR_RED, string);
								gPlayerData[giveplayerid][pCarLic] = 0;

								SavePlayerData(giveplayerid, "CarLic");
							}
							else
							{
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Ten gracz nie jest w zasiêgu.");
								return 1;
							}
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Niew³aœciwe ID.");
						return 1;
					}
				}
				else if(strcmp(x_nr,"licencjepilota",true) == 0)
				{
					tmp = strtok(cmdtext, idx);
					if(!strlen(tmp)) {
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /skonfiskuj licencjepilota [playerid]");
						return 1;
					}
					giveplayerid = ReturnUser(tmp);
					if(IsPlayerConnected(giveplayerid))
					{
						if(giveplayerid != INVALID_PLAYER_ID)
						{
							if (ProxDetectorS(8.0, playerid, giveplayerid))
							{
								format(string, sizeof(string), "[INFO:] Licencja pilota %s zosta³a skonfiskowana.", GetPlayerNameEx(giveplayerid));
								SendClientMessage(playerid, COLOR_WHITE, string);
								format(string, sizeof(string), "[INFO:] %s skonfiskowa³ Twoj¹ licencje pilota.", GetPlayerNameEx(playerid));
								SendClientMessage(giveplayerid, COLOR_RED, string);
								gPlayerData[giveplayerid][pFlyLic] = 0;

								SavePlayerData(playerid, "FlyLic");
							}
							else
							{
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Gracz nie jest w zasiêgu.");
								return 1;
							}
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Niew³aœciwe ID.");
						return 1;
					}
				}
				else if(strcmp(x_nr,"licencjenabron",true) == 0)
				{
					tmp = strtok(cmdtext, idx);
					if(!strlen(tmp)) {
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /skonfiskuj licencjenabron [playerid]");
						return 1;
					}
					giveplayerid = ReturnUser(tmp);
					if(IsPlayerConnected(giveplayerid))
					{
						if(giveplayerid != INVALID_PLAYER_ID)
						{
							if (ProxDetectorS(8.0, playerid, giveplayerid))
							{
								format(string, sizeof(string), "[INFO:] Licencja na broñ %s zosta³a skonfiskowana.", GetPlayerNameEx(giveplayerid));
								SendClientMessage(playerid, COLOR_WHITE, string);
								format(string, sizeof(string), "[INFO:] %s skonfiskowa³ Twoj¹ licencje na broñ.", GetPlayerNameEx(playerid));
								SendClientMessage(giveplayerid, COLOR_RED, string);
								gPlayerData[giveplayerid][pWepLic] = 0;

								SavePlayerData(giveplayerid, "WepLic");
							}
							else
							{
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Ten gracz nie jest w zasiêgu.");
								return 1;
							}
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Niew³aœciwe ID.");
						return 1;
					}
				}
				else if(strcmp(x_nr,"licencjenalodz",true) == 0)
				{
					tmp = strtok(cmdtext, idx);
					if(!strlen(tmp)) {
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /skonfiskuj licencjenalodz [playerid]");
						return 1;
					}
					giveplayerid = ReturnUser(tmp);
					if(IsPlayerConnected(giveplayerid))
					{
						if(giveplayerid != INVALID_PLAYER_ID)
						{
							if (ProxDetectorS(8.0, playerid, giveplayerid))
							{
								format(string, sizeof(string), "[INFO:] Licencja na lodzie %s zosta³a skonfiskowana.", GetPlayerNameEx(giveplayerid));
								SendClientMessage(playerid, COLOR_WHITE, string);
								format(string, sizeof(string), "[INFO:] %s skonfiskowa³ Twoj¹ licencje na lodzie.", GetPlayerNameEx(playerid));
								SendClientMessage(giveplayerid, COLOR_RED, string);
								gPlayerData[giveplayerid][pBoatLic] = 0;

								SavePlayerData(giveplayerid, "BoatLic");
							}
							else
							{
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Ten gracz nie jest w zasiêgu.");
								return 1;
							}
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Niew³aœciwe ID.");
						return 1;
					}
				}
				else if(strcmp(x_nr,"narkotyki",true) == 0)
				{
					tmp = strtok(cmdtext, idx);
					if(!strlen(tmp)) {
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /skonfiskuj narkotyki [playerid]");
						return 1;
					}
					giveplayerid = ReturnUser(tmp);
					if(IsPlayerConnected(giveplayerid))
					{
						if(giveplayerid != INVALID_PLAYER_ID)
						{
							if (ProxDetectorS(8.0, playerid, giveplayerid))
							{
								format(string, sizeof(string), "[INFO:] Narkotyki %s zosta³y skonfiskowane", GetPlayerNameEx(giveplayerid));
								SendClientMessage(playerid, COLOR_WHITE, string);
								format(string, sizeof(string), "[INFO:] %s skonfiskowa³ Twoje narkotyki.", GetPlayerNameEx(playerid));
								SendClientMessage(giveplayerid, COLOR_RED, string);
								gPlayerData[giveplayerid][pDrugs] = 0;

								SavePlayerData(giveplayerid, "Drugs");
							}
							else
							{
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Ten gracz nie jest w zasiêgu.");
								return 1;
							}
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Niew³aœciwe ID.");
						return 1;
					}
				}
				else if(strcmp(x_nr,"materialy",true) == 0)
				{
					tmp = strtok(cmdtext, idx);
					if(!strlen(tmp)) {
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /skonfiskuj materialy [playerid]");
						return 1;
					}
					giveplayerid = ReturnUser(tmp);
					if(IsPlayerConnected(giveplayerid))
					{
						if(giveplayerid != INVALID_PLAYER_ID)
						{
							if (ProxDetectorS(8.0, playerid, giveplayerid))
							{
								format(string, sizeof(string), "[INFO:] Materia³y %s zosta³y skonfiskowane.", GetPlayerNameEx(giveplayerid));
								SendClientMessage(playerid, COLOR_WHITE, string);
								format(string, sizeof(string), "[INFO:] %s skonfiskowa³ Twoje materia³y.", GetPlayerNameEx(playerid));
								SendClientMessage(giveplayerid, COLOR_RED, string);
								gPlayerData[giveplayerid][pMaterials] = 0;

								SavePlayerData(giveplayerid, "Materials");
							}
							else
							{
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Gracz nie jest w zasiêgu.");
								return 1;
							}
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Niew³aœciwe ID.");
						return 1;
					}
				}
				else if(strcmp(x_nr,"bron",true) == 0)
				{
					tmp = strtok(cmdtext, idx);
					if(!strlen(tmp)) {
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /skonfiskuj bron [playerid]");
						return 1;
					}
					giveplayerid = ReturnUser(tmp);
					if(IsPlayerConnected(giveplayerid))
					{
						if(giveplayerid != INVALID_PLAYER_ID)
						{
							if (ProxDetectorS(8.0, playerid, giveplayerid))
							{
								format(string, sizeof(string), "[INFO:] Broñ %s zosta³a skonfiskowana.", GetPlayerNameEx(giveplayerid));
								SendClientMessage(playerid, COLOR_WHITE, string);
								format(string, sizeof(string), "[INFO:] %s skonfiskowa³ Twoj¹ broñ.", GetPlayerNameEx(playerid));
								SendClientMessage(giveplayerid, COLOR_RED, string);
								ResetPlayerWeapons(giveplayerid);
							}
							else
							{
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Ten gracz nie jest w zasiêgu.");
								return 1;
							}
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Niew³aœciwe ID.");
						return 1;
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Niew³aœciwa nazwa.");
					return 1;
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Niew³aœciwa frakcja.");
				return 1;
			}
			return 1;
		}
		if(strcmp(cmd, "/gbron", true) == 0)
		{
			if(gPlayerData[playerid][pFaction] == 255)
			{
				SendClientMessage(playerid, COLOR_RED, "[INFO:] Niew³aœciwa frakcja !");
				return 1;
			}
			new factionid = gPlayerData[playerid][pFaction];
			if(DynamicFactions[factionid][fType] != 3)
			{
				new tmpstring[256];
				format(tmpstring, sizeof(tmpstring), "Frakcja: %d, Typ: %d",gPlayerData[playerid][pFaction], DynamicFactions[gPlayerData[playerid][pFaction]][fType]);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Niew³aœciwa frakcja/typ.");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, tmpstring);
				return 1;
			}
			if((!PlayerToPoint(5.0, playerid, DynamicFactions[factionid][fXDuty], DynamicFactions[factionid][fYDuty], DynamicFactions[factionid][fZDuty]) || GetPlayerVirtualWorld(playerid) != DynamicFactions[factionid][fWorldDuty]) &&
				   (!PlayerToPoint(5.0, playerid, DynamicFactions[factionid][fXDuty2], DynamicFactions[factionid][fYDuty2], DynamicFactions[factionid][fZDuty2]) || GetPlayerVirtualWorld(playerid) != DynamicFactions[factionid][fWorldDuty2]))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie jesteœ na miejscu pobrania broni !");
				return 1;
			}		
			if(gPlayerData[playerid][pDuty] == 1)
			{
				SetPlayerSkin(playerid,gPlayerData[playerid][pSkin]);
				gPlayerData[playerid][pDuty] = 0;
				SavePlayerData(playerid, "Duty");
				PlayerActionMessage(playerid, 15.0, "odk³ada broñ do magazynu i przebiera siê");
				if(gPlayerData[playerid][pRank] == 1)
				{
					ReturnPlayerAmmoF(playerid, DynamicFactions[factionid][fGun1Rank1], DynamicFactions[factionid][fAmmo1Rank1]);
					ReturnPlayerAmmoF(playerid, DynamicFactions[factionid][fGun2Rank1], DynamicFactions[factionid][fAmmo2Rank1]);
					ReturnPlayerAmmoF(playerid, DynamicFactions[factionid][fGun3Rank1], DynamicFactions[factionid][fAmmo3Rank1]);
				}
				else if(gPlayerData[playerid][pRank] == 2)
				{
					ReturnPlayerAmmoF(playerid, DynamicFactions[factionid][fGun1Rank2], DynamicFactions[factionid][fAmmo1Rank2]);
					ReturnPlayerAmmoF(playerid, DynamicFactions[factionid][fGun2Rank2], DynamicFactions[factionid][fAmmo2Rank2]);
					ReturnPlayerAmmoF(playerid, DynamicFactions[factionid][fGun3Rank2], DynamicFactions[factionid][fAmmo3Rank2]);
				}
				else if(gPlayerData[playerid][pRank] == 3)
				{
					ReturnPlayerAmmoF(playerid, DynamicFactions[factionid][fGun1Rank3], DynamicFactions[factionid][fAmmo1Rank3]);
					ReturnPlayerAmmoF(playerid, DynamicFactions[factionid][fGun2Rank3], DynamicFactions[factionid][fAmmo2Rank3]);
					ReturnPlayerAmmoF(playerid, DynamicFactions[factionid][fGun3Rank3], DynamicFactions[factionid][fAmmo3Rank3]);
				}
				else if(gPlayerData[playerid][pRank] == 4)
				{
					ReturnPlayerAmmoF(playerid, DynamicFactions[factionid][fGun1Rank4], DynamicFactions[factionid][fAmmo1Rank4]);
					ReturnPlayerAmmoF(playerid, DynamicFactions[factionid][fGun2Rank4], DynamicFactions[factionid][fAmmo2Rank4]);
					ReturnPlayerAmmoF(playerid, DynamicFactions[factionid][fGun3Rank4], DynamicFactions[factionid][fAmmo3Rank4]);
				}
				else if(gPlayerData[playerid][pRank] == 5)
				{
					ReturnPlayerAmmoF(playerid, DynamicFactions[factionid][fGun1Rank5], DynamicFactions[factionid][fAmmo1Rank5]);
					ReturnPlayerAmmoF(playerid, DynamicFactions[factionid][fGun2Rank5], DynamicFactions[factionid][fAmmo2Rank5]);
					ReturnPlayerAmmoF(playerid, DynamicFactions[factionid][fGun3Rank5], DynamicFactions[factionid][fAmmo3Rank5]);
				}
				else if(gPlayerData[playerid][pRank] == 6)
				{
					ReturnPlayerAmmoF(playerid, DynamicFactions[factionid][fGun1Rank1], DynamicFactions[factionid][fAmmo1Rank6]);
					ReturnPlayerAmmoF(playerid, DynamicFactions[factionid][fGun2Rank6], DynamicFactions[factionid][fAmmo2Rank6]);
					ReturnPlayerAmmoF(playerid, DynamicFactions[factionid][fGun3Rank6], DynamicFactions[factionid][fAmmo3Rank6]);
				}
				else if(gPlayerData[playerid][pRank] == 7)
				{
					ReturnPlayerAmmoF(playerid, DynamicFactions[factionid][fGun1Rank7], DynamicFactions[factionid][fAmmo1Rank7]);
					ReturnPlayerAmmoF(playerid, DynamicFactions[factionid][fGun2Rank7], DynamicFactions[factionid][fAmmo2Rank7]);
					ReturnPlayerAmmoF(playerid, DynamicFactions[factionid][fGun3Rank7], DynamicFactions[factionid][fAmmo3Rank7]);
				}
				else if(gPlayerData[playerid][pRank] == 8)
				{
					ReturnPlayerAmmoF(playerid, DynamicFactions[factionid][fGun1Rank8], DynamicFactions[factionid][fAmmo1Rank8]);
					ReturnPlayerAmmoF(playerid, DynamicFactions[factionid][fGun2Rank8], DynamicFactions[factionid][fAmmo2Rank8]);
					ReturnPlayerAmmoF(playerid, DynamicFactions[factionid][fGun3Rank8], DynamicFactions[factionid][fAmmo3Rank8]);
				}
				else if(gPlayerData[playerid][pRank] == 9)
				{
					ReturnPlayerAmmoF(playerid, DynamicFactions[factionid][fGun1Rank9], DynamicFactions[factionid][fAmmo1Rank9]);
					ReturnPlayerAmmoF(playerid, DynamicFactions[factionid][fGun2Rank9], DynamicFactions[factionid][fAmmo2Rank9]);
					ReturnPlayerAmmoF(playerid, DynamicFactions[factionid][fGun3Rank9], DynamicFactions[factionid][fAmmo3Rank9]);
				}
				else if(gPlayerData[playerid][pRank] == 10)
				{
					ReturnPlayerAmmoF(playerid, DynamicFactions[factionid][fGun1Rank10], DynamicFactions[factionid][fAmmo1Rank10]);
					ReturnPlayerAmmoF(playerid, DynamicFactions[factionid][fGun2Rank10], DynamicFactions[factionid][fAmmo2Rank10]);
					ReturnPlayerAmmoF(playerid, DynamicFactions[factionid][fGun3Rank10], DynamicFactions[factionid][fAmmo3Rank10]);
				}
				return 1;
			}
			else if(gPlayerData[playerid][pDuty] == 0)
			{
				gPlayerData[playerid][pDuty] = 1;
				SavePlayerData(playerid, "Duty");
				SetPlayerToFactionSkin(playerid);
				if(gPlayerData[playerid][pRank] == 1)
				{
					format(string, sizeof(string), "[%s:] %s pobra³ broñ.",DynamicFactions[factionid][Name],GetPlayerNameEx(playerid));
					SendFactionMessage(factionid, COLOR_DARKPURPLE, string);
					
					AddPlayerAmmoF(playerid, DynamicFactions[factionid][fGun1Rank1], DynamicFactions[factionid][fAmmo1Rank1]);
					AddPlayerAmmoF(playerid, DynamicFactions[factionid][fGun2Rank1], DynamicFactions[factionid][fAmmo2Rank1]);
					AddPlayerAmmoF(playerid, DynamicFactions[factionid][fGun3Rank1], DynamicFactions[factionid][fAmmo3Rank1]);

					// if(DynamicFactions[factionid][fGun1Rank1] == 25)	{ DynamicFactions[factionid][fBank] -= 700; }
					// if(DynamicFactions[factionid][fGun1Rank1] == 29)	{ DynamicFactions[factionid][fBank] -= 900; }
					// if(DynamicFactions[factionid][fGun1Rank1] == 28)	{ DynamicFactions[factionid][fBank] -= 800; }
					// if(DynamicFactions[factionid][fGun1Rank1] == 30)	{ DynamicFactions[factionid][fBank] -= 5000; }
					// if(DynamicFactions[factionid][fGun1Rank1] == 31)	{ DynamicFactions[factionid][fBank] -= 5000; }
					// if(DynamicFactions[factionid][fGun1Rank1] == 32)	{ DynamicFactions[factionid][fBank] -= 800; }
					// if(DynamicFactions[factionid][fGun1Rank1] == 33)	{ DynamicFactions[factionid][fBank] -= 1000; }
					// if(DynamicFactions[factionid][fGun1Rank1] == 34)	{ DynamicFactions[factionid][fBank] -= 10000; }

					// if(DynamicFactions[factionid][fGun2Rank1] == 22)	{ DynamicFactions[factionid][fBank] -= 300; }
					// if(DynamicFactions[factionid][fGun2Rank1] == 23)	{ DynamicFactions[factionid][fBank] -= 400; }
					// if(DynamicFactions[factionid][fGun2Rank1] == 24)	{ DynamicFactions[factionid][fBank] -= 1500; }

					if(DynamicFactions[factionid][fGun3Rank1] == 3)	
					{
						GivePlayerGun(playerid, 3, 1);
						DynamicFactions[factionid][fBank] -= 35; 
					}
					if(DynamicFactions[factionid][fGun3Rank1] == 1)	
					{
						GivePlayerGun(playerid, 1, 1);
						DynamicFactions[factionid][fBank] -= 10;
					}
					if(DynamicFactions[factionid][fGun3Rank1] == 5)
					{
						GivePlayerGun(playerid, 5, 1);
						DynamicFactions[factionid][fBank] -= 50;
					}
					if(DynamicFactions[factionid][fGun3Rank1] == 4)
					{
						GivePlayerGun(playerid, 4, 1);
						DynamicFactions[factionid][fBank] -= 100;
					}

					// SaveFData(factionid, "Bank");
					// format(string, sizeof(string), "[%s:] Brak piêdzy na koncie w frakcji na pobranie broni",DynamicFactions[factionid][Name],GetPlayerNameEx(playerid));
					// SendFactionMessage(8, COLOR_DARKPURPLE, string);
				}
				if(gPlayerData[playerid][pRank] == 2)
				{
					format(string, sizeof(string), "[%s:] %s pobra³ broñ.",DynamicFactions[factionid][Name],GetPlayerNameEx(playerid));
					SendFactionMessage(factionid, COLOR_DARKPURPLE, string);

					AddPlayerAmmoF(playerid, DynamicFactions[factionid][fGun1Rank2], DynamicFactions[factionid][fAmmo1Rank2]);
					AddPlayerAmmoF(playerid, DynamicFactions[factionid][fGun2Rank2], DynamicFactions[factionid][fAmmo2Rank2]);
					AddPlayerAmmoF(playerid, DynamicFactions[factionid][fGun3Rank2], DynamicFactions[factionid][fAmmo3Rank2]);

					// if(DynamicFactions[factionid][fGun1Rank2] == 25)	{ DynamicFactions[factionid][fBank] -= 700; }
					// if(DynamicFactions[factionid][fGun1Rank2] == 29)	{ DynamicFactions[factionid][fBank] -= 900; }
					// if(DynamicFactions[factionid][fGun1Rank2] == 28)	{ DynamicFactions[factionid][fBank] -= 800; }
					// if(DynamicFactions[factionid][fGun1Rank2] == 30)	{ DynamicFactions[factionid][fBank] -= 5000; }
					// if(DynamicFactions[factionid][fGun1Rank2] == 31)	{ DynamicFactions[factionid][fBank] -= 5000; }
					// if(DynamicFactions[factionid][fGun1Rank2] == 32)	{ DynamicFactions[factionid][fBank] -= 800; }
					// if(DynamicFactions[factionid][fGun1Rank2] == 33)	{ DynamicFactions[factionid][fBank] -= 1000; }
					// if(DynamicFactions[factionid][fGun1Rank2] == 34)	{ DynamicFactions[factionid][fBank] -= 10000; }

					// if(DynamicFactions[factionid][fGun2Rank2] == 22)	{ DynamicFactions[factionid][fBank] -= 300; }
					// if(DynamicFactions[factionid][fGun2Rank2] == 23)	{ DynamicFactions[factionid][fBank] -= 400; }
					// if(DynamicFactions[factionid][fGun2Rank2] == 24)	{ DynamicFactions[factionid][fBank] -= 1500; }

					if(DynamicFactions[factionid][fGun3Rank2] == 3)	
					{
						GivePlayerGun(playerid, 3, 1);
						DynamicFactions[factionid][fBank] -= 35; 
					}
					if(DynamicFactions[factionid][fGun3Rank2] == 1)	
					{
						GivePlayerGun(playerid, 1, 1);
						DynamicFactions[factionid][fBank] -= 10;
					}
					if(DynamicFactions[factionid][fGun3Rank2] == 5)
					{
						GivePlayerGun(playerid, 5, 1);
						DynamicFactions[factionid][fBank] -= 50;
					}
					if(DynamicFactions[factionid][fGun3Rank2] == 4)
					{
						GivePlayerGun(playerid, 4, 1);
						DynamicFactions[factionid][fBank] -= 100;
					}
					
					// SaveFData(factionid, "Bank");
					// format(string, sizeof(string), "[%s:] Brak piêdzy na koncie w frakcji na pobranie broni",DynamicFactions[factionid][Name],GetPlayerNameEx(playerid));
					// SendFactionMessage(8, COLOR_DARKPURPLE, string);
				}
				if(gPlayerData[playerid][pRank] == 3)
				{
					format(string, sizeof(string), "[%s:] %s pobra³ broñ.",DynamicFactions[factionid][Name],GetPlayerNameEx(playerid));
					SendFactionMessage(factionid, COLOR_DARKPURPLE, string);

					AddPlayerAmmoF(playerid, DynamicFactions[factionid][fGun1Rank3], DynamicFactions[factionid][fAmmo1Rank3]);
					AddPlayerAmmoF(playerid, DynamicFactions[factionid][fGun2Rank3], DynamicFactions[factionid][fAmmo2Rank3]);
					AddPlayerAmmoF(playerid, DynamicFactions[factionid][fGun3Rank3], DynamicFactions[factionid][fAmmo3Rank3]);

					// if(DynamicFactions[factionid][fGun1Rank3] == 25)	{ DynamicFactions[factionid][fBank] -= 700; }
					// if(DynamicFactions[factionid][fGun1Rank3] == 29)	{ DynamicFactions[factionid][fBank] -= 900; }
					// if(DynamicFactions[factionid][fGun1Rank3] == 28)	{ DynamicFactions[factionid][fBank] -= 800; }
					// if(DynamicFactions[factionid][fGun1Rank3] == 30)	{ DynamicFactions[factionid][fBank] -= 5000; }
					// if(DynamicFactions[factionid][fGun1Rank3] == 31)	{ DynamicFactions[factionid][fBank] -= 5000; }
					// if(DynamicFactions[factionid][fGun1Rank3] == 32)	{ DynamicFactions[factionid][fBank] -= 800; }
					// if(DynamicFactions[factionid][fGun1Rank3] == 33)	{ DynamicFactions[factionid][fBank] -= 1000; }
					// if(DynamicFactions[factionid][fGun1Rank3] == 34)	{ DynamicFactions[factionid][fBank] -= 10000; }

					// if(DynamicFactions[factionid][fGun2Rank3] == 22)	{ DynamicFactions[factionid][fBank] -= 300; }
					// if(DynamicFactions[factionid][fGun2Rank3] == 23)	{ DynamicFactions[factionid][fBank] -= 400; }
					// if(DynamicFactions[factionid][fGun2Rank3] == 24)	{ DynamicFactions[factionid][fBank] -= 1500; }

					if(DynamicFactions[factionid][fGun3Rank3] == 3)	
					{
						GivePlayerGun(playerid, 3, 1);
						DynamicFactions[factionid][fBank] -= 35; 
					}
					if(DynamicFactions[factionid][fGun3Rank3] == 1)	
					{
						GivePlayerGun(playerid, 1, 1);
						DynamicFactions[factionid][fBank] -= 10;
					}
					if(DynamicFactions[factionid][fGun3Rank3] == 5)
					{
						GivePlayerGun(playerid, 5, 1);
						DynamicFactions[factionid][fBank] -= 50;
					}
					if(DynamicFactions[factionid][fGun3Rank3] == 4)
					{
						GivePlayerGun(playerid, 4, 1);
						DynamicFactions[factionid][fBank] -= 100;
					}

					// SaveFData(factionid, "Bank");
					// format(string, sizeof(string), "[%s:] Brak piêdzy na koncie w frakcji na pobranie broni",DynamicFactions[factionid][Name],GetPlayerNameEx(playerid));
					// SendFactionMessage(8, COLOR_DARKPURPLE, string);
				}
				if(gPlayerData[playerid][pRank] == 4)
				{
					format(string, sizeof(string), "[%s:] %s pobra³ broñ.",DynamicFactions[factionid][Name],GetPlayerNameEx(playerid));
					SendFactionMessage(factionid, COLOR_DARKPURPLE, string);

					AddPlayerAmmoF(playerid, DynamicFactions[factionid][fGun1Rank4], DynamicFactions[factionid][fAmmo1Rank4]);
					AddPlayerAmmoF(playerid, DynamicFactions[factionid][fGun2Rank4], DynamicFactions[factionid][fAmmo2Rank4]);
					AddPlayerAmmoF(playerid, DynamicFactions[factionid][fGun3Rank4], DynamicFactions[factionid][fAmmo3Rank4]);

					// if(DynamicFactions[factionid][fGun1Rank4] == 25)	{ DynamicFactions[factionid][fBank] -= 700; }
					// if(DynamicFactions[factionid][fGun1Rank4] == 29)	{ DynamicFactions[factionid][fBank] -= 900; }
					// if(DynamicFactions[factionid][fGun1Rank4] == 28)	{ DynamicFactions[factionid][fBank] -= 800; }
					// if(DynamicFactions[factionid][fGun1Rank4] == 30)	{ DynamicFactions[factionid][fBank] -= 5000; }
					// if(DynamicFactions[factionid][fGun1Rank4] == 31)	{ DynamicFactions[factionid][fBank] -= 5000; }
					// if(DynamicFactions[factionid][fGun1Rank4] == 32)	{ DynamicFactions[factionid][fBank] -= 800; }
					// if(DynamicFactions[factionid][fGun1Rank4] == 33)	{ DynamicFactions[factionid][fBank] -= 1000; }
					// if(DynamicFactions[factionid][fGun1Rank4] == 34)	{ DynamicFactions[factionid][fBank] -= 10000; }

					// if(DynamicFactions[factionid][fGun2Rank4] == 22)	{ DynamicFactions[factionid][fBank] -= 300; }
					// if(DynamicFactions[factionid][fGun2Rank4] == 23)	{ DynamicFactions[factionid][fBank] -= 400; }
					// if(DynamicFactions[factionid][fGun2Rank4] == 24)	{ DynamicFactions[factionid][fBank] -= 1500; }

					if(DynamicFactions[factionid][fGun3Rank4] == 3)	
					{
						GivePlayerGun(playerid, 3, 1);
						DynamicFactions[factionid][fBank] -= 35; 
					}
					if(DynamicFactions[factionid][fGun3Rank4] == 1)	
					{
						GivePlayerGun(playerid, 1, 1);
						DynamicFactions[factionid][fBank] -= 10;
					}
					if(DynamicFactions[factionid][fGun3Rank4] == 5)
					{
						GivePlayerGun(playerid, 5, 1);
						DynamicFactions[factionid][fBank] -= 50;
					}
					if(DynamicFactions[factionid][fGun3Rank4] == 4)
					{
						GivePlayerGun(playerid, 4, 1);
						DynamicFactions[factionid][fBank] -= 100;
					}
					// SaveFData(factionid, "Bank");
					// format(string, sizeof(string), "[%s:] Brak piêdzy na koncie w frakcji na pobranie broni",DynamicFactions[factionid][Name],GetPlayerNameEx(playerid));
					// SendFactionMessage(8, COLOR_DARKPURPLE, string);
				}
				if(gPlayerData[playerid][pRank] == 5)
				{
					format(string, sizeof(string), "[%s:] %s pobra³ broñ.",DynamicFactions[factionid][Name],GetPlayerNameEx(playerid));
					SendFactionMessage(factionid, COLOR_DARKPURPLE, string);

					AddPlayerAmmoF(playerid, DynamicFactions[factionid][fGun1Rank5], DynamicFactions[factionid][fAmmo1Rank5]);
					AddPlayerAmmoF(playerid, DynamicFactions[factionid][fGun2Rank5], DynamicFactions[factionid][fAmmo2Rank5]);
					AddPlayerAmmoF(playerid, DynamicFactions[factionid][fGun3Rank5], DynamicFactions[factionid][fAmmo3Rank5]);

					// if(DynamicFactions[factionid][fGun1Rank5] == 25)	{ DynamicFactions[factionid][fBank] -= 700; }
					// if(DynamicFactions[factionid][fGun1Rank5] == 29)	{ DynamicFactions[factionid][fBank] -= 900; }
					// if(DynamicFactions[factionid][fGun1Rank5] == 28)	{ DynamicFactions[factionid][fBank] -= 800; }
					// if(DynamicFactions[factionid][fGun1Rank5] == 30)	{ DynamicFactions[factionid][fBank] -= 5000; }
					// if(DynamicFactions[factionid][fGun1Rank5] == 31)	{ DynamicFactions[factionid][fBank] -= 5000; }
					// if(DynamicFactions[factionid][fGun1Rank5] == 32)	{ DynamicFactions[factionid][fBank] -= 800; }
					// if(DynamicFactions[factionid][fGun1Rank5] == 33)	{ DynamicFactions[factionid][fBank] -= 1000; }
					// if(DynamicFactions[factionid][fGun1Rank5] == 34)	{ DynamicFactions[factionid][fBank] -= 10000; }

					// if(DynamicFactions[factionid][fGun2Rank5] == 22)	{ DynamicFactions[factionid][fBank] -= 300; }
					// if(DynamicFactions[factionid][fGun2Rank5] == 23)	{ DynamicFactions[factionid][fBank] -= 400; }
					// if(DynamicFactions[factionid][fGun2Rank5] == 24)	{ DynamicFactions[factionid][fBank] -= 1500; }

					if(DynamicFactions[factionid][fGun3Rank5] == 3)	
					{
						GivePlayerGun(playerid, 3, 1);
						DynamicFactions[factionid][fBank] -= 35; 
					}
					if(DynamicFactions[factionid][fGun3Rank5] == 1)	
					{
						GivePlayerGun(playerid, 1, 1);
						DynamicFactions[factionid][fBank] -= 10;
					}
					if(DynamicFactions[factionid][fGun3Rank5] == 5)
					{
						GivePlayerGun(playerid, 5, 1);
						DynamicFactions[factionid][fBank] -= 50;
					}
					if(DynamicFactions[factionid][fGun3Rank5] == 4)
					{
						GivePlayerGun(playerid, 4, 1);
						DynamicFactions[factionid][fBank] -= 100;
					}

					// SaveFData(factionid, "Bank");
					// format(string, sizeof(string), "[%s:] Brak piêdzy na koncie w frakcji na pobranie broni",DynamicFactions[factionid][Name],GetPlayerNameEx(playerid));
					// SendFactionMessage(8, COLOR_DARKPURPLE, string);
				}
				if(gPlayerData[playerid][pRank] == 6)
				{
					format(string, sizeof(string), "[%s:] %s pobra³ broñ.",DynamicFactions[factionid][Name],GetPlayerNameEx(playerid));
					SendFactionMessage(factionid, COLOR_DARKPURPLE, string);

					AddPlayerAmmoF(playerid, DynamicFactions[factionid][fGun1Rank6], DynamicFactions[factionid][fAmmo1Rank6]);
					AddPlayerAmmoF(playerid, DynamicFactions[factionid][fGun2Rank6], DynamicFactions[factionid][fAmmo2Rank6]);
					AddPlayerAmmoF(playerid, DynamicFactions[factionid][fGun3Rank6], DynamicFactions[factionid][fAmmo3Rank6]);

					// if(DynamicFactions[factionid][fGun1Rank6] == 25)	{ DynamicFactions[factionid][fBank] -= 700; }
					// if(DynamicFactions[factionid][fGun1Rank6] == 29)	{ DynamicFactions[factionid][fBank] -= 900; }
					// if(DynamicFactions[factionid][fGun1Rank6] == 28)	{ DynamicFactions[factionid][fBank] -= 800; }
					// if(DynamicFactions[factionid][fGun1Rank6] == 30)	{ DynamicFactions[factionid][fBank] -= 5000; }
					// if(DynamicFactions[factionid][fGun1Rank6] == 31)	{ DynamicFactions[factionid][fBank] -= 5000; }
					// if(DynamicFactions[factionid][fGun1Rank6] == 32)	{ DynamicFactions[factionid][fBank] -= 800; }
					// if(DynamicFactions[factionid][fGun1Rank6] == 33)	{ DynamicFactions[factionid][fBank] -= 1000; }
					// if(DynamicFactions[factionid][fGun1Rank6] == 34)	{ DynamicFactions[factionid][fBank] -= 10000; }

					// if(DynamicFactions[factionid][fGun2Rank6] == 22)	{ DynamicFactions[factionid][fBank] -= 300; }
					// if(DynamicFactions[factionid][fGun2Rank6] == 23)	{ DynamicFactions[factionid][fBank] -= 400; }
					// if(DynamicFactions[factionid][fGun2Rank6] == 24)	{ DynamicFactions[factionid][fBank] -= 1500; }

					if(DynamicFactions[factionid][fGun3Rank6] == 3)	
					{
						GivePlayerGun(playerid, 3, 1);
						DynamicFactions[factionid][fBank] -= 35; 
					}
					if(DynamicFactions[factionid][fGun3Rank6] == 1)	
					{
						GivePlayerGun(playerid, 1, 1);
						DynamicFactions[factionid][fBank] -= 10;
					}
					if(DynamicFactions[factionid][fGun3Rank6] == 5)
					{
						GivePlayerGun(playerid, 5, 1);
						DynamicFactions[factionid][fBank] -= 50;
					}
					if(DynamicFactions[factionid][fGun3Rank6] == 4)
					{
						GivePlayerGun(playerid, 4, 1);
						DynamicFactions[factionid][fBank] -= 100;
					}

					// SaveFData(factionid, "Bank");
					// format(string, sizeof(string), "[%s:] Brak piêdzy na koncie w frakcji na pobranie broni",DynamicFactions[factionid][Name],GetPlayerNameEx(playerid));
					// SendFactionMessage(8, COLOR_DARKPURPLE, string);
				}
				if(gPlayerData[playerid][pRank] == 7)
				{
					format(string, sizeof(string), "[%s:] %s pobra³ broñ.",DynamicFactions[factionid][Name],GetPlayerNameEx(playerid));
					SendFactionMessage(factionid, COLOR_DARKPURPLE, string);

					AddPlayerAmmoF(playerid, DynamicFactions[factionid][fGun1Rank7], DynamicFactions[factionid][fAmmo1Rank7]);
					AddPlayerAmmoF(playerid, DynamicFactions[factionid][fGun2Rank7], DynamicFactions[factionid][fAmmo2Rank7]);
					AddPlayerAmmoF(playerid, DynamicFactions[factionid][fGun3Rank7], DynamicFactions[factionid][fAmmo3Rank7]);

					// if(DynamicFactions[factionid][fGun1Rank7] == 25)	{ DynamicFactions[factionid][fBank] -= 700; }
					// if(DynamicFactions[factionid][fGun1Rank7] == 29)	{ DynamicFactions[factionid][fBank] -= 900; }
					// if(DynamicFactions[factionid][fGun1Rank7] == 28)	{ DynamicFactions[factionid][fBank] -= 800; }
					// if(DynamicFactions[factionid][fGun1Rank7] == 30)	{ DynamicFactions[factionid][fBank] -= 5000; }
					// if(DynamicFactions[factionid][fGun1Rank7] == 31)	{ DynamicFactions[factionid][fBank] -= 5000; }
					// if(DynamicFactions[factionid][fGun1Rank7] == 32)	{ DynamicFactions[factionid][fBank] -= 800; }
					// if(DynamicFactions[factionid][fGun1Rank7] == 33)	{ DynamicFactions[factionid][fBank] -= 1000; }
					// if(DynamicFactions[factionid][fGun1Rank7] == 34)	{ DynamicFactions[factionid][fBank] -= 10000; }

					// if(DynamicFactions[factionid][fGun2Rank7] == 22)	{ DynamicFactions[factionid][fBank] -= 300; }
					// if(DynamicFactions[factionid][fGun2Rank7] == 23)	{ DynamicFactions[factionid][fBank] -= 400; }
					// if(DynamicFactions[factionid][fGun2Rank7] == 24)	{ DynamicFactions[factionid][fBank] -= 1500; }

					if(DynamicFactions[factionid][fGun3Rank7] == 3)	
					{
						GivePlayerGun(playerid, 3, 1);
						DynamicFactions[factionid][fBank] -= 35; 
					}
					if(DynamicFactions[factionid][fGun3Rank7] == 1)	
					{
						GivePlayerGun(playerid, 1, 1);
						DynamicFactions[factionid][fBank] -= 10;
					}
					if(DynamicFactions[factionid][fGun3Rank7] == 5)
					{
						GivePlayerGun(playerid, 5, 1);
						DynamicFactions[factionid][fBank] -= 50;
					}
					if(DynamicFactions[factionid][fGun3Rank7] == 4)
					{
						GivePlayerGun(playerid, 4, 1);
						DynamicFactions[factionid][fBank] -= 100;
					}

					// SaveFData(factionid, "Bank");
					// format(string, sizeof(string), "[%s:] Brak piêdzy na koncie w frakcji na pobranie broni",DynamicFactions[factionid][Name],GetPlayerNameEx(playerid));
					// SendFactionMessage(8, COLOR_DARKPURPLE, string);
				}
				if(gPlayerData[playerid][pRank] == 8)
				{
					format(string, sizeof(string), "[%s:] %s pobra³ broñ.",DynamicFactions[factionid][Name],GetPlayerNameEx(playerid));
					SendFactionMessage(factionid, COLOR_DARKPURPLE, string);

					AddPlayerAmmoF(playerid, DynamicFactions[factionid][fGun1Rank8], DynamicFactions[factionid][fAmmo1Rank8]);
					AddPlayerAmmoF(playerid, DynamicFactions[factionid][fGun2Rank8], DynamicFactions[factionid][fAmmo2Rank8]);
					AddPlayerAmmoF(playerid, DynamicFactions[factionid][fGun3Rank8], DynamicFactions[factionid][fAmmo3Rank8]);

					// if(DynamicFactions[factionid][fGun1Rank8] == 25)	{ DynamicFactions[factionid][fBank] -= 700; }
					// if(DynamicFactions[factionid][fGun1Rank8] == 29)	{ DynamicFactions[factionid][fBank] -= 900; }
					// if(DynamicFactions[factionid][fGun1Rank8] == 28)	{ DynamicFactions[factionid][fBank] -= 800; }
					// if(DynamicFactions[factionid][fGun1Rank8] == 30)	{ DynamicFactions[factionid][fBank] -= 5000; }
					// if(DynamicFactions[factionid][fGun1Rank8] == 31)	{ DynamicFactions[factionid][fBank] -= 5000; }
					// if(DynamicFactions[factionid][fGun1Rank8] == 32)	{ DynamicFactions[factionid][fBank] -= 800; }
					// if(DynamicFactions[factionid][fGun1Rank8] == 33)	{ DynamicFactions[factionid][fBank] -= 1000; }
					// if(DynamicFactions[factionid][fGun1Rank8] == 34)	{ DynamicFactions[factionid][fBank] -= 10000; }

					// if(DynamicFactions[factionid][fGun2Rank8] == 22)	{ DynamicFactions[factionid][fBank] -= 300; }
					// if(DynamicFactions[factionid][fGun2Rank8] == 23)	{ DynamicFactions[factionid][fBank] -= 400; }
					// if(DynamicFactions[factionid][fGun2Rank8] == 24)	{ DynamicFactions[factionid][fBank] -= 1500; }

					if(DynamicFactions[factionid][fGun3Rank8] == 3)	
					{
						GivePlayerGun(playerid, 3, 1);
						DynamicFactions[factionid][fBank] -= 35; 
					}
					if(DynamicFactions[factionid][fGun3Rank8] == 1)	
					{
						GivePlayerGun(playerid, 1, 1);
						DynamicFactions[factionid][fBank] -= 10;
					}
					if(DynamicFactions[factionid][fGun3Rank8] == 5)
					{
						GivePlayerGun(playerid, 5, 1);
						DynamicFactions[factionid][fBank] -= 50;
					}
					if(DynamicFactions[factionid][fGun3Rank8] == 4)
					{
						GivePlayerGun(playerid, 4, 1);
						DynamicFactions[factionid][fBank] -= 100;
					}

					// SaveFData(factionid, "Bank");
					// format(string, sizeof(string), "[%s:] Brak piêdzy na koncie w frakcji na pobranie broni",DynamicFactions[factionid][Name],GetPlayerNameEx(playerid));
					// SendFactionMessage(8, COLOR_DARKPURPLE, string);
				}
				if(gPlayerData[playerid][pRank] == 9)
				{
					format(string, sizeof(string), "[%s:] %s pobra³ broñ.",DynamicFactions[factionid][Name],GetPlayerNameEx(playerid));
					SendFactionMessage(factionid, COLOR_DARKPURPLE, string);

					AddPlayerAmmoF(playerid, DynamicFactions[factionid][fGun1Rank9], DynamicFactions[factionid][fAmmo1Rank9]);
					AddPlayerAmmoF(playerid, DynamicFactions[factionid][fGun2Rank9], DynamicFactions[factionid][fAmmo2Rank9]);
					AddPlayerAmmoF(playerid, DynamicFactions[factionid][fGun3Rank9], DynamicFactions[factionid][fAmmo3Rank9]);

					// if(DynamicFactions[factionid][fGun1Rank9] == 25)	{ DynamicFactions[factionid][fBank] -= 700; }
					// if(DynamicFactions[factionid][fGun1Rank9] == 29)	{ DynamicFactions[factionid][fBank] -= 900; }
					// if(DynamicFactions[factionid][fGun1Rank9] == 28)	{ DynamicFactions[factionid][fBank] -= 800; }
					// if(DynamicFactions[factionid][fGun1Rank9] == 30)	{ DynamicFactions[factionid][fBank] -= 5000; }
					// if(DynamicFactions[factionid][fGun1Rank9] == 31)	{ DynamicFactions[factionid][fBank] -= 5000; }
					// if(DynamicFactions[factionid][fGun1Rank9] == 32)	{ DynamicFactions[factionid][fBank] -= 800; }
					// if(DynamicFactions[factionid][fGun1Rank9] == 33)	{ DynamicFactions[factionid][fBank] -= 1000; }
					// if(DynamicFactions[factionid][fGun1Rank9] == 34)	{ DynamicFactions[factionid][fBank] -= 10000; }

					// if(DynamicFactions[factionid][fGun2Rank9] == 22)	{ DynamicFactions[factionid][fBank] -= 300; }
					// if(DynamicFactions[factionid][fGun2Rank9] == 23)	{ DynamicFactions[factionid][fBank] -= 400; }
					// if(DynamicFactions[factionid][fGun2Rank9] == 24)	{ DynamicFactions[factionid][fBank] -= 1500; }

					if(DynamicFactions[factionid][fGun3Rank9] == 3)	
					{
						GivePlayerGun(playerid, 3, 1);
						DynamicFactions[factionid][fBank] -= 35; 
					}
					if(DynamicFactions[factionid][fGun3Rank9] == 1)	
					{
						GivePlayerGun(playerid, 1, 1);
						DynamicFactions[factionid][fBank] -= 10;
					}
					if(DynamicFactions[factionid][fGun3Rank9] == 5)
					{
						GivePlayerGun(playerid, 5, 1);
						DynamicFactions[factionid][fBank] -= 50;
					}
					if(DynamicFactions[factionid][fGun3Rank9] == 4)
					{
						GivePlayerGun(playerid, 4, 1);
						DynamicFactions[factionid][fBank] -= 100;
					}

					// SaveFData(factionid, "Bank");
					// format(string, sizeof(string), "[%s:] Brak piêdzy na koncie w frakcji na pobranie broni",DynamicFactions[factionid][Name],GetPlayerNameEx(playerid));
					// SendFactionMessage(8, COLOR_DARKPURPLE, string);
				}
				if(gPlayerData[playerid][pRank] == 10)
				{
					format(string, sizeof(string), "[%s:] %s pobra³ broñ.",DynamicFactions[factionid][Name],GetPlayerNameEx(playerid));
					SendFactionMessage(factionid, COLOR_DARKPURPLE, string);

					AddPlayerAmmoF(playerid, DynamicFactions[factionid][fGun1Rank10], DynamicFactions[factionid][fAmmo1Rank10]);
					AddPlayerAmmoF(playerid, DynamicFactions[factionid][fGun2Rank10], DynamicFactions[factionid][fAmmo2Rank10]);
					AddPlayerAmmoF(playerid, DynamicFactions[factionid][fGun3Rank10], DynamicFactions[factionid][fAmmo3Rank10]);

					// if(DynamicFactions[factionid][fGun1Rank1] == 25)	{ DynamicFactions[factionid][fBank] -= 700; }
					// if(DynamicFactions[factionid][fGun1Rank1] == 29)	{ DynamicFactions[factionid][fBank] -= 900; }
					// if(DynamicFactions[factionid][fGun1Rank1] == 28)	{ DynamicFactions[factionid][fBank] -= 800; }
					// if(DynamicFactions[factionid][fGun1Rank1] == 30)	{ DynamicFactions[factionid][fBank] -= 5000; }
					// if(DynamicFactions[factionid][fGun1Rank1] == 31)	{ DynamicFactions[factionid][fBank] -= 5000; }
					// if(DynamicFactions[factionid][fGun1Rank1] == 32)	{ DynamicFactions[factionid][fBank] -= 800; }
					// if(DynamicFactions[factionid][fGun1Rank1] == 33)	{ DynamicFactions[factionid][fBank] -= 1000; }
					// if(DynamicFactions[factionid][fGun1Rank1] == 34)	{ DynamicFactions[factionid][fBank] -= 10000; }

					// if(DynamicFactions[factionid][fGun2Rank1] == 22)	{ DynamicFactions[factionid][fBank] -= 300; }
					// if(DynamicFactions[factionid][fGun2Rank1] == 23)	{ DynamicFactions[factionid][fBank] -= 400; }
					// if(DynamicFactions[factionid][fGun2Rank1] == 24)	{ DynamicFactions[factionid][fBank] -= 1500; }

					if(DynamicFactions[factionid][fGun3Rank10] == 3)	
					{
						GivePlayerGun(playerid, 3, 1);
						DynamicFactions[factionid][fBank] -= 35; 
					}
					if(DynamicFactions[factionid][fGun3Rank10] == 1)	
					{
						GivePlayerGun(playerid, 1, 1);
						DynamicFactions[factionid][fBank] -= 10;
					}
					if(DynamicFactions[factionid][fGun3Rank10] == 5)
					{
						GivePlayerGun(playerid, 5, 1);
						DynamicFactions[factionid][fBank] -= 50;
					}
					if(DynamicFactions[factionid][fGun3Rank10] == 4)
					{
						GivePlayerGun(playerid, 4, 1);
						DynamicFactions[factionid][fBank] -= 100;
					}

					// SaveFData(factionid, "Bank");
					// format(string, sizeof(string), "[%s:] Brak piêdzy na koncie w frakcji na pobranie broni",DynamicFactions[factionid][Name],GetPlayerNameEx(playerid));
					// SendFactionMessage(8, COLOR_DARKPURPLE, string);
				}
				return 1;
			}
			return 1;
		}
		if (strcmp(cmd, "/resetskin", true) ==0 )
		{
			if(gPlayerData[playerid][pModerator] < 1)
				return 0;
			SetPlayerSkin(playerid,4);
			return 1;
		}
		if(strcmp(cmd, "/paralizuj", true) == 0 || strcmp(cmd, "/pa", true) == 0)
		{
			if(IsPlayerConnected(playerid))
			{
				if(gPlayerData[playerid][pFaction] != 255 && DynamicFactions[gPlayerData[playerid][pFaction]][fType] == 1)
				{
					if(gPlayerData[playerid][pDuty] == 0)
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie jesteœ na s³u¿bie !");
						return 1;
					}
					if(IsPlayerInAnyVehicle(playerid))
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie mo¿esz u¿yæ paralizatora siedz¹c w samochodzie !");
						return 1;
					}
					new suspect = GetClosestPlayer(playerid);
					if(IsPlayerConnected(suspect))
					{
						if(PlayerCuffed[suspect] == 1)
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Ta osoba jest skuta !");
							return 1;
						}
						if(GetDistanceBetweenPlayers(playerid,suspect) <= 5)
						{
							if(IsPlayerInAnyVehicle(suspect))
							{
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Wydostañ podejrzanego z wozu !");
								return 1;
							}
							PlayerActionMessage(playerid, 15.0, "wyci¹ga z kabury paralizator Taser X26C i u¿ywa go");
							format(string, sizeof(string), "[INFO:] Zosta³eœ sparali¿owany przez %s na 10 sekund.", GetPlayerNameEx(playerid));
							SendClientMessage(suspect, COLOR_RED, string);
							format(string, sizeof(string), "[INFO:] Sparali¿owa³eœ %s na 10 sekund.", GetPlayerNameEx(suspect));
							SendClientMessage(playerid, COLOR_WHITE, string);
							TogglePlayerControllable(suspect, 0);
							PlayerTazed[suspect] = 1;
							UntazePlayer(suspect);
						}
						else
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie ma nikogo w zasiêgu.");
							return 1;
						}
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Niew³aœciwa frakcja.");
				}
			}//not connected
			return 1;
		}
		if(strcmp(cmd, "/mandat", true) == 0)
		{
			if(IsPlayerInAnyVehicle(playerid))
			{
				new Float:x, Float:y, Float:z;
				GetVehicleVelocity( GetPlayerVehicleID(playerid), x, y, z );
				if( x > 0 || y > 0 || z > 0 )
				{
					SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Przed wypisaniem mandatu zatrzymaj pojazd !");
					return 1;
				}
			}
			if(gPlayerData[playerid][pFaction] != 255 && DynamicFactions[gPlayerData[playerid][pFaction]][fType] == 1)
			{
				if(gPlayerData[playerid][pDuty] == 0)
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie jesteœ na s³u¿bie !");
					return 1;
				}
				tmp = strtok(cmdtext, idx);
				if(!strlen(tmp))
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /mandat [playerid] [wysokoœæ] [powód]");
					return 1;
				}
				giveplayerid = ReturnUser(tmp);
				tmp = strtok(cmdtext, idx);
				if(!strlen(tmp))
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /mandat [playerid] [wysokoœæ] [powód]");
					return 1;
				}
				new moneys;
				moneys = strval(tmp);
				if(moneys < 1 || moneys > 99999) { SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Niew³aœciwa wysokoœæ mandatu."); return 1; }
				if(IsPlayerConnected(giveplayerid))
				{
					if(giveplayerid != INVALID_PLAYER_ID)
					{
						if (ProxDetectorS(8.0, playerid, giveplayerid))
						{
							new length = strlen(cmdtext);
							while ((idx < length) && (cmdtext[idx] <= ' '))
							{
								idx++;
							}
							new offset = idx;
							new result[128];
							while ((idx < length) && ((idx - offset) < (sizeof(result) - 1)))
							{
								result[idx - offset] = cmdtext[idx];
								idx++;
							}
							result[idx - offset] = EOS;
							if(!strlen(result))
							{
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /mandat [playerid] [wysokoœæ] [powód]");
								return 1;
							}
							format(string, sizeof(string), "[INFO:] Da³eœ mandat %s o wysokoœci $%d - Powód: %s.", GetPlayerNameEx(giveplayerid), moneys, (result));
							SendClientMessage(playerid, COLOR_WHITE, string);
							format(string, sizeof(string), "[INFO:] %s da³ Tobie mandat w wysokoœci $%d - Powód: %s.", GetPlayerNameEx(playerid), moneys, (result));
							SendClientMessage(giveplayerid, COLOR_RED, string);
							TicketOffer[giveplayerid] = playerid;
							TicketMoney[giveplayerid] = moneys;
							gPlayerData[giveplayerid][pTicket] += moneys;

							SavePlayerData(giveplayerid, "Ticket");

							return 1;
						}
						else
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie jesteœ wystarczaj¹co blisko tej osoby !");
							return 1;
						}
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Niew³aœciwe ID");
					return 1;
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Invalid Faction");
			}
			return 1;
		}
		if(strcmp(cmd, "/aresztuj", true) == 0 || strcmp(cmd, "/ar", true) == 0)
		{
			if(IsPlayerInAnyVehicle(playerid))
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz aresztowaæ bêd¹c w pojeŸdzie !");
				return 1;
			}
			if(gPlayerData[playerid][pFaction] == 255)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Niew³aœciwa frakcja.");
				return 1;
			}
			if(DynamicFactions[gPlayerData[playerid][pFaction]][fType] != 1)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Niew³aœciwa frakcja.");
				return 1;
			}
			if(!gPlayerData[playerid][pDuty])
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie jesteœ na s³u¿bie !");
				return 1;
			}
			if(!PlayerToPoint(30.0, playerid, -303.0, 1533.0, 75.0) && !PlayerToPoint(8.0, playerid, 268.0, 77.0, 1001.0))
			{
				SendClientMessage(playerid, COLOR_GREY, "[INFO:] Nie jesteœ ko³o wiezienia. Nie mo¿esz nikogo zaaresztowaæ !");
				return 1;
			}
			tmp = strtok(cmdtext, idx);
			new time = strval(tmp);
			if( PlayerToPoint(8.0, playerid, 268.0, 77.0, 1001.0) )
			{
				if(time < 1 || time > 60)
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Czas aresztowania nie mo¿e byæ d³u¿szy ni¿ 60 minut i krótszy ni¿ 1 minuta!");
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Jeœli chcesz aresztowaæ podej¿anego na d³u¿ej udaj siê do g³ównego wiêzienia");
					return 1; 
				}
			}		
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /aresztuj [czas]");
				return 1;
			}
			new suspect = GetClosestPlayer(playerid);
			if(!IsPlayerConnected(suspect))
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Gracz nie jest po³¹czony !");
				return 1;
			}
			if(!gPlayerLogged[playerid])
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Gracz nie jest zalogowany !");
				return 1;
			}
			if(GetDistanceBetweenPlayers(playerid,suspect) > 3)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Jesteœ zbyt daleko od tej osoby ");
				return 1;
			}
			if(WantedLevel[suspect] < 1)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Ten gracz nie jest poszukiwany !");
				return 1;
			}
			if(AdminDuty[suspect] == 1)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie mo¿esz aresztowaæ administratora bêd¹cego na s³u¿bie !");
				return 1;
			}
			if(gPlayerData[playerid][pCharacterDying] > 0)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie mo¿esz aresztowaæ osoby umieraj¹cej !");
				return 1;
			}
			if(!PlayerCuffed[suspect])
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Przed aresztowanie podejrzany musi mieæ za³o¿one kajdanki");
				return 1;
			}
			PlayerCuffed[suspect] = 0;
			if( !gPlayerData[suspect][pFirstJail] )
			{
				gPlayerData[suspect][pFirstJail] = 1;
				SavePlayerData( suspect, "FirstJail" );
				AddExpPoint(playerid);
				SendClientMessage( playerid, COLOR_GREEN, "[INFO:] Jesteœ poraz pierwszy w wiêzieniu !" );
			}
			format(string, sizeof(string), "[INFO:] %s zosta³ aresztowany.", GetPlayerNameEx(suspect));
			SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
			ResetPlayerWeapons(suspect);		
			SetPlayerSkin( suspect, 96 );
			if(!PlayerToPoint(8.0, playerid, 268.0, 77.0, 1001.0))
			{
				DBVariables[2][varDValue]++;
				SetPlayerInterior(suspect, 0);
				SetPlayerVirtualWorld(suspect,21); //BUILDING ID 2, MAKE SURE PD IS ID 2
				switch(DBVariables[2][varDValue])
				{
					case 0: SetPlayerToPos(suspect, 1778.6060791016,-1581.3503417969,1738.7172851563);
					case 1: SetPlayerToPos(suspect, 1778.60546875,-1581.349609375,1734.9417724609);
					case 2: SetPlayerToPos(suspect, 1774.3107910156,-1580.8834228516,1734.9429931641);
					case 3: SetPlayerToPos(suspect, 1770.0396728516,-1580.9715576172,1734.9429931641);
					case 4: SetPlayerToPos(suspect, 1765.6442871094,-1581.0885009766,1734.9429931641);
					case 5: SetPlayerToPos(suspect, 1761.5192871094,-1580.9661865234,1734.9429931641);
					case 6: SetPlayerToPos(suspect, 1757.1713867188,-1581.1558837891,1734.9429931641);
					case 7: SetPlayerToPos(suspect, 1757.3331298828,-1565.4664306641,1734.9429931641);
					case 8: SetPlayerToPos(suspect, 1761.7298583984,-1565.6207275391,1734.9429931641);
					case 9: SetPlayerToPos(suspect, 1765.9074707031,-1565.1364746094,1734.9429931641);
					case 10: SetPlayerToPos(suspect, 1770.2448730469,-1565.3743896484,1734.9429931641);
					case 11: SetPlayerToPos(suspect, 1774.5153808594,-1565.1875,1734.9429931641);
					case 12: SetPlayerToPos(suspect, 1778.6448974609,-1565.0377197266,1734.9429931641);
					case 13: SetPlayerToPos(suspect, 1774.236328125,-1580.9116210938,1738.7172851563);
					case 14: SetPlayerToPos(suspect, 1770.1110839844,-1580.9205322266,1738.7172851563);
					case 15: SetPlayerToPos(suspect, 1765.7939453125,-1581.2406005859,1738.7172851563);
					case 16: SetPlayerToPos(suspect, 1761.4822998047,-1581.0185546875,1738.7172851563);
					case 17: SetPlayerToPos(suspect, 1757.3651123047,-1581.0830078125,1738.7172851563);
					case 18: SetPlayerToPos(suspect, 1757.3023681641,-1565.8057861328,1738.6934814453);
					case 19: SetPlayerToPos(suspect, 1761.7540283203,-1565.4591064453,1738.6934814453);
					case 20: SetPlayerToPos(suspect, 1765.8216552734,-1565.5594482422,1738.6934814453);
					case 21: SetPlayerToPos(suspect, 1770.0919189453,-1565.4733886719,1738.6934814453);
					case 22: SetPlayerToPos(suspect, 1774.4881591797,-1565.1726074219,1738.6934814453);
					case 23: SetPlayerToPos(suspect, 1778.5562744141,-1565.2510986328,1738.6937255859);
				}
				GetPlayerPos(suspect, gPlayerData[suspect][pCrashX],gPlayerData[suspect][pCrashY],gPlayerData[suspect][pCrashZ]);
				gPlayerData[suspect][pCrashInt] = 0;
				gPlayerData[suspect][pCrashW] = 21;
				if(DBVariables[2][varDValue] == 23)
					DBVariables[2][varDValue] = 0;
			}
			else
			{
				SetPlayerInterior(suspect, Building[GetPlayerVirtualWorld(playerid)][ExitInterior]);
				SetPlayerToPos(suspect, 266.0,77.0,1001.0);
				gPlayerData[suspect][pCrashX] = 266.0;
				gPlayerData[suspect][pCrashY] = 77.0;
				gPlayerData[suspect][pCrashZ] = 1001.0;
				gPlayerData[suspect][pCrashInt] = Building[GetPlayerVirtualWorld(playerid)][ExitInterior];
				gPlayerData[suspect][pCrashW] = GetPlayerVirtualWorld(playerid);
			}
			SavePlayerData(suspect, "Crash");
			
			format(string, sizeof(string), "UPDATE `samp_wanted` SET `Punished` = '1' WHERE `PlayerName` = '%s'", gPlayerData[suspect][pName]);
			mysql_query(string, SAVE, playerid, db_con2);
			
			TogglePlayerControllable(suspect, 0);
			unfreezeTPPlayer(suspect);

			//SetPlayerToPos(suspect,1775.0,-1563.0,1739.0);
			gPlayerData[suspect][pJailTime] = time * 60;

			SavePlayerData(suspect, "JailTime");

			format(string, sizeof(string), "[INFO:] Aresztowany! - Czas odsiadki: %d sekund.", gPlayerData[suspect][pJailTime]);
			SendClientMessage(suspect, COLOR_LIGHTYELLOW2, string);
			format(string, sizeof(string), "[SFPD:] %s aresztowa³ %s.",GetPlayerNameEx(playerid), GetPlayerNameEx(suspect));
			SendFactionTypeMessage(1, COLOR_LSPD, string);
			gPlayerData[suspect][pJailed] = 1;

			SavePlayerData(suspect, "Jailed");

			WantedPoints[suspect] = 0;
			ResetPlayerWantedLevelEx(suspect);
			gPlayerData[suspect][pWantedLvl] = 0;

			SavePlayerData(suspect, "WantedLvl");

			PlayerCuffed[suspect] = 0;
			new faction = gPlayerData[playerid][pFaction];
			DynamicFactions[faction][fBank] -= gPlayerData[suspect][pJailTime];
			SaveFData(faction, "Bank");

			SavePlayerData(playerid, "Jailed");
			SavePlayerData(playerid, "JailTime");
			return 1;
		}
		// if(strcmp(cmd, "/wiezienie", true) == 0)
		// {
			// if(gPlayerData[playerid][pFaction] == 255) 
			// {
				// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Niew³aœciwa frakcja.");
				// return 1;
			// }
			// if(DynamicFactions[gPlayerData[playerid][pFaction]][fType] != 1)
			// {
				// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Niew³aœciwa frakcja.");
				// return 1;
			// }
			// if(!gPlayerData[playerid][pDuty])
			// {
				// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie jesteœ na s³u¿bie !");
				// return 1;
			// }
			// tmp = strtok(cmdtext, idx);
			// new time = strval(tmp);
			// if(time < 1440 || time > 14400) { SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Czas uwiêzienia musi byæ d³u¿szy b¹dŸ równy 24h."); return 1; }
			// if(!strlen(tmp))
			// {
				// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /wiezienie [czas]");
				// return 1;
			// }
			// new suspect = GetClosestPlayer(playerid);
			// if(!IsPlayerConnected(suspect))
			// {
				// SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Dany gracz nie jest online");
				// return 1;
			// }
			// if(!gPlayerLogged[suspect])
			// {
				// SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Dany gracz nie jest zalogowany !");
				// return 1;
			// }
			// if(GetDistanceBetweenPlayers(playerid,suspect) > 5)
			// {
				// SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ta osoba jest za daleko od ciebie !");
				// return 1;
			// }
			// if(WantedLevel[suspect] < 1)
			// {
				// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Gracz nie jest poszukiwany.");
				// return 1;
			// }
			// format(string, sizeof(string), "[INFO:] %s uwiêziony.", GetPlayerNameEx(suspect));
			// SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
			// ResetPlayerWeapons(suspect);
			// gPlayerData[suspect][pJailTime] = time * 60;

			// SavePlayerData(suspect, "JailTime");

			// format(string, sizeof(string), "[INFO:] UWIÊZIONY!! - Czas zatrzymania: %d sekund.", gPlayerData[suspect][pJailTime]);
			// SendClientMessage(suspect, COLOR_LIGHTYELLOW2, string);
			// format(string, sizeof(string), "[SFPD:] %s uwiêzi³ przestêpce %s.",GetPlayerNameEx(playerid), GetPlayerNameEx(suspect));
			// SendFactionTypeMessage(1, COLOR_LSPD, string);
			// gPlayerData[suspect][pJailed] = 1;

			// SetPlayerVirtualWorld(suspect,1); //BUILDING ID 2, MAKE SURE PD IS ID 2
			// SetPlayerInterior(suspect, 0);

			// DBVariables[2][varDValue]++;
			// switch(DBVariables[2][varDValue])
			// {
				// case 0: SetPlayerToPos(suspect, 1778.6060791016,-1581.3503417969,1738.7172851563);
				// case 1: SetPlayerToPos(suspect, 1778.60546875,-1581.349609375,1734.9417724609);
				// case 2: SetPlayerToPos(suspect, 1774.3107910156,-1580.8834228516,1734.9429931641);
				// case 3: SetPlayerToPos(suspect, 1770.0396728516,-1580.9715576172,1734.9429931641);
				// case 4: SetPlayerToPos(suspect, 1765.6442871094,-1581.0885009766,1734.9429931641);
				// case 5: SetPlayerToPos(suspect, 1761.5192871094,-1580.9661865234,1734.9429931641);
				// case 6: SetPlayerToPos(suspect, 1757.1713867188,-1581.1558837891,1734.9429931641);
				// case 7: SetPlayerToPos(suspect, 1757.3331298828,-1565.4664306641,1734.9429931641);
				// case 8: SetPlayerToPos(suspect, 1761.7298583984,-1565.6207275391,1734.9429931641);
				// case 9: SetPlayerToPos(suspect, 1765.9074707031,-1565.1364746094,1734.9429931641);
				// case 10: SetPlayerToPos(suspect, 1770.2448730469,-1565.3743896484,1734.9429931641);
				// case 11: SetPlayerToPos(suspect, 1774.5153808594,-1565.1875,1734.9429931641);
				// case 12: SetPlayerToPos(suspect, 1778.6448974609,-1565.0377197266,1734.9429931641);
				// case 13: SetPlayerToPos(suspect, 1774.236328125,-1580.9116210938,1738.7172851563);
				// case 14: SetPlayerToPos(suspect, 1770.1110839844,-1580.9205322266,1738.7172851563);
				// case 15: SetPlayerToPos(suspect, 1765.7939453125,-1581.2406005859,1738.7172851563);
				// case 16: SetPlayerToPos(suspect, 1761.4822998047,-1581.0185546875,1738.7172851563);
				// case 17: SetPlayerToPos(suspect, 1757.3651123047,-1581.0830078125,1738.7172851563);
				// case 18: SetPlayerToPos(suspect, 1757.3023681641,-1565.8057861328,1738.6934814453);
				// case 19: SetPlayerToPos(suspect, 1761.7540283203,-1565.4591064453,1738.6934814453);
				// case 20: SetPlayerToPos(suspect, 1765.8216552734,-1565.5594482422,1738.6934814453);
				// case 21: SetPlayerToPos(suspect, 1770.0919189453,-1565.4733886719,1738.6934814453);
				// case 22: SetPlayerToPos(suspect, 1774.4881591797,-1565.1726074219,1738.6934814453);
				// case 23: SetPlayerToPos(suspect, 1778.5562744141,-1565.2510986328,1738.6937255859);
			// }
			// if(DBVariables[2][varDValue] == 23)
			// {
				// DBVariables[2][varDValue] = 0;
			// }
			// TogglePlayerControllable(suspect, 0);
			// unfreezeTPPlayer(suspect);

			// SavePlayerData(suspect, "Jailed");

			// WantedPoints[suspect] = 0;
			// ResetPlayerWantedLevelEx(suspect);
			// new faction = gPlayerData[playerid][pFaction];
			// DynamicFactions[faction][fBank] += gPlayerData[suspect][pJailTime];
			// SaveFData(faction, "Bank");
			// return 1;
		// }
		/*if(strcmp(cmd, "/megafon", true) == 0 || strcmp(cmd, "/m", true) == 0)
		{
			if(IsPlayerConnected(playerid))
			{
				new length = strlen(cmdtext);
				while ((idx < length) && (cmdtext[idx] <= ' '))
				{
					idx++;
				}
				new offset = idx;
				new result[128];
				while ((idx < length) && ((idx - offset) < (sizeof(result) - 1)))
				{
					result[idx - offset] = cmdtext[idx];
					idx++;
				}
				result[idx - offset] = EOS;
				if(!strlen(result))
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "U¯YCIE: [/m]egafon [wiadomosc]");
					return 1;
				}
				if(gPlayerData[playerid][pFaction] != 255 && DynamicFactions[gPlayerData[playerid][pFaction]][fType] == 1)
				{
					if(!IsPlayerInAnyVehicle(playerid))
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie jesteœ w samochodzie.");
						return 1;
					}
					if(!CopOnDuty[playerid] || !FBIOnDuty[playerid])
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie jesteœ na s³u¿bie!");
						return 1;
					}
					if(gVehData[tmpcar][FactionCar] != gPlayerData[playerid][pFaction])
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie jesteœ w s³u¿bowym wozie.");
						return 1;
					}
					new rank = gPlayerData[playerid][pRank];
					if(rank == 1)
					{
						format(string, sizeof(string), "[MEGAFON:] %s %s: %s!!", DynamicFactions[gPlayerData[playerid][pFaction]][fRank1],GetPlayerNameEx(playerid), result);
						ProxDetector(60.0, playerid, string,COLOR_LSPD,COLOR_LSPD,COLOR_LSPD,COLOR_LSPD,COLOR_LSPD);
						return 1;
					}
					else if(rank == 2)
					{
						format(string, sizeof(string), "[MEGAFON:] %s %s: %s!!", DynamicFactions[gPlayerData[playerid][pFaction]][fRank2],GetPlayerNameEx(playerid), result);
						ProxDetector(60.0, playerid, string,COLOR_LSPD,COLOR_LSPD,COLOR_LSPD,COLOR_LSPD,COLOR_LSPD);
						return 1;
					}
					else if(rank == 3)
					{
						format(string, sizeof(string), "[MEGAFON:] %s %s: %s!!", DynamicFactions[gPlayerData[playerid][pFaction]][fRank3],GetPlayerNameEx(playerid), result);
						ProxDetector(60.0, playerid, string,COLOR_LSPD,COLOR_LSPD,COLOR_LSPD,COLOR_LSPD,COLOR_LSPD);
						return 1;
					}
					else if(rank == 4)
					{
						format(string, sizeof(string), "[MEGAFON:] %s %s: %s!!", DynamicFactions[gPlayerData[playerid][pFaction]][fRank4],GetPlayerNameEx(playerid), result);
						ProxDetector(60.0, playerid, string,COLOR_LSPD,COLOR_LSPD,COLOR_LSPD,COLOR_LSPD,COLOR_LSPD);
						return 1;
					}
					else if(rank == 5)
					{
						format(string, sizeof(string), "[MEGAFON:] %s %s: %s!!", DynamicFactions[gPlayerData[playerid][pFaction]][fRank5],GetPlayerNameEx(playerid), result);
						ProxDetector(60.0, playerid, string,COLOR_LSPD,COLOR_LSPD,COLOR_LSPD,COLOR_LSPD,COLOR_LSPD);
						return 1;
					}
					else if(rank == 6)
					{
						format(string, sizeof(string), "[MEGAFON:] %s %s: %s!!", DynamicFactions[gPlayerData[playerid][pFaction]][fRank6],GetPlayerNameEx(playerid), result);
						ProxDetector(60.0, playerid, string,COLOR_LSPD,COLOR_LSPD,COLOR_LSPD,COLOR_LSPD,COLOR_LSPD);
						return 1;
					}
					else if(rank == 7)
					{
						format(string, sizeof(string), "[MEGAFON:] %s %s: %s!!", DynamicFactions[gPlayerData[playerid][pFaction]][fRank7],GetPlayerNameEx(playerid), result);
						ProxDetector(60.0, playerid, string,COLOR_LSPD,COLOR_LSPD,COLOR_LSPD,COLOR_LSPD,COLOR_LSPD);
						return 1;
					}
					else if(rank == 8)
					{
						format(string, sizeof(string), "[MEGAFON:] %s %s: %s!!", DynamicFactions[gPlayerData[playerid][pFaction]][fRank8],GetPlayerNameEx(playerid), result);
						ProxDetector(60.0, playerid, string,COLOR_LSPD,COLOR_LSPD,COLOR_LSPD,COLOR_LSPD,COLOR_LSPD);
						return 1;
					}
					else if(rank == 9)
					{
						format(string, sizeof(string), "[MEGAFON:] %s %s: %s!!", DynamicFactions[gPlayerData[playerid][pFaction]][fRank9],GetPlayerNameEx(playerid), result);
						ProxDetector(60.0, playerid, string,COLOR_LSPD,COLOR_LSPD,COLOR_LSPD,COLOR_LSPD,COLOR_LSPD);
						return 1;
					}
					else if(rank == 10)
					{
						format(string, sizeof(string), "[MEGAFON:] %s %s: %s!!", DynamicFactions[gPlayerData[playerid][pFaction]][fRank10],GetPlayerNameEx(playerid), result);
						ProxDetector(60.0, playerid, string,COLOR_LSPD,COLOR_LSPD,COLOR_LSPD,COLOR_LSPD,COLOR_LSPD);
						return 1;
					}
					return 1;
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Niew³aœciwa frakcja.");
					return 1;
				}
			}
			return 1;
		}*/
		//=================================================[FACTION SYSTEM COMMANDS]================================================
		/*if(strcmp(cmd, "/radio", true) == 0 || strcmp(cmd, "/r", true) == 0)
		{
			if(IsPlayerConnected(playerid))
			{
				new wstring[128];
				new faction = gPlayerData[playerid][pFaction];
				new rank = gPlayerData[playerid][pRank];
				new length = strlen(cmdtext);
				while ((idx < length) && (cmdtext[idx] <= ' '))
				{
					idx++;
				}
				new offset = idx;
				new result[128];
				while ((idx < length) && ((idx - offset) < (sizeof(result) - 1)))
				{
					result[idx - offset] = cmdtext[idx];
					idx++;
				}
				result[idx - offset] = EOS;
				if(!strlen(result))
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] (/r)adio");
					return 1;
				}
				if(Muted[playerid])
				{
					SendClientMessage(playerid, COLOR_RED, "[B£¥D:] Nie mo¿esz u¿ywaæ radia, jesteœ zag³uszony.");
					return 1;
				}
				if(gPlayerData[playerid][pFaction] != 255 && DynamicFactions[gPlayerData[playerid][pFaction]][fType] == 1)
				{
						if(CopOnDuty[playerid])
						{
							if(rank == 1)
							{
								format(wstring, sizeof(wstring), "[RADIO:] %s %s: %s, over.",DynamicFactions[faction][fRank1],GetPlayerNameEx(playerid),result);
								SendFactionTypeMessage(1, COLOR_LSPD, wstring);
								FactionChatLog(wstring);
							}
							else if(rank == 2)
							{
								format(wstring, sizeof(wstring), "[RADIO:] %s %s: %s, over.",DynamicFactions[faction][fRank2],GetPlayerNameEx(playerid),result);
								SendFactionTypeMessage(1, COLOR_LSPD, wstring);
								FactionChatLog(wstring);
							}
							else if(rank == 3)
							{
								format(wstring, sizeof(wstring), "[RADIO:] %s %s: %s, over.",DynamicFactions[faction][fRank3],GetPlayerNameEx(playerid),result);
								SendFactionTypeMessage(1, COLOR_LSPD, wstring);
								FactionChatLog(wstring);
							}
							else if(rank == 4)
							{
								format(wstring, sizeof(wstring), "[RADIO:] %s %s: %s, over.",DynamicFactions[faction][fRank4],GetPlayerNameEx(playerid),result);
								SendFactionTypeMessage(1, COLOR_LSPD, wstring);
								FactionChatLog(wstring);
							}
							else if(rank == 5)
							{
								format(wstring, sizeof(wstring), "[RADIO:] %s %s: %s, over.",DynamicFactions[faction][fRank5],GetPlayerNameEx(playerid),result);
								SendFactionTypeMessage(1, COLOR_LSPD, wstring);
								FactionChatLog(wstring);
							}
							else if(rank == 6)
							{
								format(wstring, sizeof(wstring), "[RADIO:] %s %s: %s, over.",DynamicFactions[faction][fRank6],GetPlayerNameEx(playerid),result);
								SendFactionTypeMessage(1, COLOR_LSPD, wstring);
								FactionChatLog(wstring);
							}
							else if(rank == 7)
							{
								format(wstring, sizeof(wstring), "[RADIO:] %s %s: %s, over.",DynamicFactions[faction][fRank7],GetPlayerNameEx(playerid),result);
								SendFactionTypeMessage(1, COLOR_LSPD, wstring);
								FactionChatLog(wstring);
							}
							else if(rank == 8)
							{
								format(wstring, sizeof(wstring), "[RADIO:] %s %s: %s, over.",DynamicFactions[faction][fRank8],GetPlayerNameEx(playerid),result);
								SendFactionTypeMessage(1, COLOR_LSPD, wstring);
								FactionChatLog(wstring);
							}
							else if(rank == 9)
							{
								format(wstring, sizeof(wstring), "[RADIO:] %s %s: %s, over.",DynamicFactions[faction][fRank9],GetPlayerNameEx(playerid),result);
								SendFactionTypeMessage(1, COLOR_LSPD, wstring);
								FactionChatLog(wstring);
							}
							else if(rank == 10)
							{
								format(wstring, sizeof(wstring), "[RADIO:] %s %s: %s, over.",DynamicFactions[faction][fRank10],GetPlayerNameEx(playerid),result);
								SendFactionTypeMessage(1, COLOR_LSPD, wstring);
								FactionChatLog(wstring);
							}
						}
						else
						{
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[B£¥D:] Nie jesteœ na s³u¿bie !");
						}
				}
				else
				{
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[B£¥D:] Nie jesteœ cz³onkiem wymaganej frakcji/typu.");
				}
			}
			return 1;
		}*/
		if(strcmp(cmd, "/frakcja", true) == 0 || strcmp(cmd, "/f", true) == 0)
		{
			if(gPlayerData[playerid][pCharacterDying] == 0)
			{
				new wstring[128];
				new faction = gPlayerData[playerid][pFaction];
				new rank = gPlayerData[playerid][pRank];
				new length = strlen(cmdtext);
				while ((idx < length) && (cmdtext[idx] <= ' '))
				{
					idx++;
				}
				new offset = idx;
				new result[128];
				while ((idx < length) && ((idx - offset) < (sizeof(result) - 1)))
				{
					result[idx - offset] = cmdtext[idx];
					idx++;
				}
				result[idx - offset] = EOS;
				if(!strlen(result))
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] (/f)rakcja");
					return 1;
				}
				if ((nofooc) && gPlayerData[playerid][pAdmin] < 1)
				{
					SendClientMessage(playerid, COLOR_GRAD2, "[INFO:] Chat frakcyjny zosta³ wy³¹czony przez administratora !");
					return 1;
				}
				if(Muted[playerid])
				{
					SendClientMessage(playerid, COLOR_RED, "[B£¥D:] Jesteœ uciszony, nie mo¿e u¿ywaæ tego chatu !");
					return 1;
				}
				if(gPlayerData[playerid][pFaction] != 255)
				{
					if(IsPlayerInAnyVehicle(playerid) || PHaveItem(playerid, 3, 2))
					{
						new vehicleID = GetPlayerVehicleID(playerid);
						if(vehicleID != INVALID_VEHICLE_ID && PHaveItem(playerid, 3, 2) == 0)
						{
							if(gVehData[vehicleID-1][FactionCar] != 255)
							{
								if(gVehData[vehicleID-1][FactionCar] != gPlayerData[playerid][pFaction] && PHaveItem(playerid, 3, 2) == 0)
								{
									SendClientMessage(playerid, COLOR_LIGHTYELLOW2,  "[INFO:] Nie jesteœ w pojeŸdzie frakcyjnym ani nie posiadasz radia !");
									return 1;
								}
							}
						}
						if(rank == 1)
						{
							format(wstring, sizeof(wstring), "(( [Radio:] %s %s: %s ))",DynamicFactions[faction][fRank1],GetPlayerNameEx(playerid),result);
							SendFactionMessage(gPlayerData[playerid][pFaction], COLOR_FACTIONCHAT, wstring);
							FactionChatLog(wstring);
						}
						else if(rank == 2)
						{
							format(wstring, sizeof(wstring), "(( [Radio:] %s %s: %s ))",DynamicFactions[faction][fRank2],GetPlayerNameEx(playerid),result);
							SendFactionMessage(gPlayerData[playerid][pFaction], COLOR_FACTIONCHAT, wstring);
							FactionChatLog(wstring);
						}
						else if(rank == 3)
						{
							format(wstring, sizeof(wstring), "(( [Radio:] %s %s: %s ))",DynamicFactions[faction][fRank3],GetPlayerNameEx(playerid),result);
							SendFactionMessage(gPlayerData[playerid][pFaction], COLOR_FACTIONCHAT, wstring);
							FactionChatLog(wstring);
						}
						else if(rank == 4)
						{
							format(wstring, sizeof(wstring), "(( [Radio:] %s %s: %s ))",DynamicFactions[faction][fRank4],GetPlayerNameEx(playerid),result);
							SendFactionMessage(gPlayerData[playerid][pFaction], COLOR_FACTIONCHAT, wstring);
							FactionChatLog(wstring);
						}
						else if(rank == 5)
						{
							format(wstring, sizeof(wstring), "(( [Radio:] %s %s: %s ))",DynamicFactions[faction][fRank5],GetPlayerNameEx(playerid),result);
							SendFactionMessage(gPlayerData[playerid][pFaction], COLOR_FACTIONCHAT, wstring);
							FactionChatLog(wstring);
						}
						else if(rank == 6)
						{
							format(wstring, sizeof(wstring), "(( [Radio:] %s %s: %s ))",DynamicFactions[faction][fRank6],GetPlayerNameEx(playerid),result);
							SendFactionMessage(gPlayerData[playerid][pFaction], COLOR_FACTIONCHAT, wstring);
							FactionChatLog(wstring);
						}
						else if(rank == 7)
						{
							format(wstring, sizeof(wstring), "(( [Radio:] %s %s: %s ))",DynamicFactions[faction][fRank7],GetPlayerNameEx(playerid),result);
							SendFactionMessage(gPlayerData[playerid][pFaction], COLOR_FACTIONCHAT, wstring);
							FactionChatLog(wstring);
						}
						else if(rank == 8)
						{
							format(wstring, sizeof(wstring), "(( [Radio:] %s %s: %s ))",DynamicFactions[faction][fRank8],GetPlayerNameEx(playerid),result);
							SendFactionMessage(gPlayerData[playerid][pFaction], COLOR_FACTIONCHAT, wstring);
							FactionChatLog(wstring);
						}
						else if(rank == 9)
						{
							format(wstring, sizeof(wstring), "(( [Radio:] %s %s: %s ))",DynamicFactions[faction][fRank9],GetPlayerNameEx(playerid),result);
							SendFactionMessage(gPlayerData[playerid][pFaction], COLOR_FACTIONCHAT, wstring);
							FactionChatLog(wstring);
						}
						else if(rank == 10)
						{
							format(wstring, sizeof(wstring), "(( [Radio:] %s %s: %s ))",DynamicFactions[faction][fRank10],GetPlayerNameEx(playerid),result);
							SendFactionMessage(gPlayerData[playerid][pFaction], COLOR_FACTIONCHAT, wstring);
							FactionChatLog(wstring);
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie znajdujesz siê w pojeŸdzie frakcyjnym");
						return 1;
					}
				}
				else
				{
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[B£¥D:] Nie jesteœ cz³onkiem frakcji !");
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_RED, "[INFO:] Twoja postaæ jest nieprzytomna, nie mo¿e mówiæ");
			}
			return 1;
		}
		if(strcmp(cmd, "/zapros", true) == 0)
		{
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /zapros [id gracza]");
				return 1;
			}
			giveplayerid = ReturnUser(tmp);
			if (gPlayerData[playerid][pRank] == 1 && gPlayerData[playerid][pFaction] != 255)
			{
				if(gPlayerData[giveplayerid][pFaction] == 255)
				{
					if(IsPlayerConnected(giveplayerid))
					{
						if(giveplayerid != INVALID_PLAYER_ID)
						{
							new form[128];
							new faction = gPlayerData[playerid][pFaction];
							if(gPlayerLogged[giveplayerid])
							{
								if(DynamicFactions[faction][fJoinRank] == 0)
								{
									SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] Ustal rangi swojej frakcji zanim zaprosisz graczy !");
								}
								else
								{
									FactionRequest[giveplayerid] = faction;
									format(form,sizeof(form),"Zosta³eœ zaproszony do %s przez %s. (wpisz /akceptuj frakcje) aby do³¹czyæ. ",DynamicFactions[faction][Name],GetPlayerNameEx(playerid));
									SendClientMessage(giveplayerid,COLOR_LIGHTBLUE,form);
									format(form,sizeof(form),"Zaprosi³eœ %s do do³¹czenia do frakcji %s. ",GetPlayerNameEx(giveplayerid),DynamicFactions[faction][Name]);
									SendClientMessage(playerid,COLOR_LIGHTBLUE,form);
								}
								return 1;
							}
							else
							{
								SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] Ten gracz nie jest on-line!");
							}
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Niew³aœciwe ID.");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Osobê któr¹ próbujesz zaprosiæ jest ju¿ we frakcji.");
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie jesteœ liderem !");
			}
			return 1;
		}
		if(strcmp(cmd, "/wypros", true) == 0)
		{
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /wypros [id gracza]");
				return 1;
			}
			giveplayerid = ReturnUser(tmp);
			if (gPlayerData[playerid][pRank] == 1 && gPlayerData[playerid][pFaction] != 255)
			{
				if(gPlayerData[giveplayerid][pFaction] == gPlayerData[playerid][pFaction])
				{
					if(IsPlayerConnected(giveplayerid))
					{
						if(gPlayerLogged[giveplayerid])
						{
							if(giveplayerid != INVALID_PLAYER_ID)
							{
								new form[128];
								new faction = gPlayerData[playerid][pFaction];
								format(form,sizeof(form),"Zosta³eœ wyproszony z %s przez %s.",DynamicFactions[faction][Name],GetPlayerNameEx(playerid));
								SendClientMessage(giveplayerid,COLOR_LIGHTBLUE,form);
								format(form,sizeof(form),"Wyprosi³eœ %s z %s.",GetPlayerNameEx(giveplayerid),DynamicFactions[faction][Name]);
								SendClientMessage(playerid,COLOR_LIGHTBLUE,form);
								gPlayerData[giveplayerid][pFaction] = 255;
								gPlayerData[giveplayerid][pRank] = 0;

								SavePlayerData(giveplayerid, "Faction");
								SavePlayerData(giveplayerid, "Rank");

								SetPlayerSpawn(giveplayerid);
								format(form, sizeof(form), "[FRAKCJA:] %s zosta³ wyproszony z frakcji przez %s.",GetPlayerNameEx(giveplayerid),GetPlayerNameEx(playerid));
								SendFactionMessage(gPlayerData[playerid][pFaction], COLOR_FACTIONCHAT, form);
								return 1;
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Gracz nie jest on-line.");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Niew³aœciwe ID.");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Próbowa³eœ wyprosiæ kogoœ kto nie jest w Twojej frakcji.");
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie jesteœ liderem!");
			}
			return 1;
		}
		if(strcmp(cmd, "/ustawrange", true) == 0)
		{
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /ustawrange [playerid/partoName] [nowa_ranga]");
				return 1;
			}
			new para1;
			new level;
			para1 = ReturnUser(tmp);
			tmp = strtok(cmdtext, idx);
			level = strval(tmp);
			if(gPlayerData[playerid][pRank] == 1 && gPlayerData[playerid][pFaction] != 255)
			{
				if(gPlayerData[para1][pFaction] == gPlayerData[playerid][pFaction])
				{
					new faction = gPlayerData[playerid][pFaction];
					if (level)
					{
						if(level > 1 && level <= DynamicFactions[faction][fRankAmount])
						{
							if(IsPlayerConnected(para1) && gPlayerLogged[para1] && para1 != INVALID_PLAYER_ID)
							{
								gPlayerData[para1][pRank] = level;
								SavePlayerData(para1, "Rank");

								format(string, sizeof(string), "[INFO:] Twoja ranga zosta³a zmieniona przez %s, teraz masz range: %d.", GetPlayerNameEx(playerid),level);
								SendClientMessage(para1, COLOR_LIGHTBLUE, string);
								format(string, sizeof(string), "[INFO:] Zmieni³eœ range %s na: %d.", GetPlayerNameEx(para1),level);
								SendClientMessage(playerid, COLOR_YELLOW, string);
								
								SetPlayerToFactionSkin(para1);

								if(gPlayerData[para1][pSex] == 1)
								{
									format(string, sizeof(string), "[FRAKCJA:] Ranga %s zosta³a zmieniona na: %d.",GetPlayerNameEx(para1), level);
									SendFactionMessage(gPlayerData[playerid][pFaction], COLOR_FACTIONCHAT, string);
								}
								else
								{
									format(string, sizeof(string), "[FRAKCJA:] Ranga %s zosta³a zmieniona na: %d.",GetPlayerNameEx(para1), level);
									SendFactionMessage(gPlayerData[playerid][pFaction], COLOR_FACTIONCHAT, string);
								}
							}
							else
							{
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Niew³aœciwe ID/Gracz nie jest on-line.");
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Ranga musi miec ID mniejsze b¹dŸ równe od iloœci rang frakcji..");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Msusisz wpisaæ iloœæ !");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Osoba której próbujesz zmieniæ range nie jest w Twojej frakcji.");
				}
			}
			else
			{

				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie jesteœ liderem.");
			}
			return 1;
		}
		//==========================================================================================================================
		if(strcmp(cmd, "/kick", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 1)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /kick [playerid/partoName] [powód]");
				return 1;
			}
			giveplayerid = ReturnUser(tmp);
			if(IsPlayerConnected(giveplayerid))
			{
				if(giveplayerid != INVALID_PLAYER_ID)
				{
					new length = strlen(cmdtext);
					while ((idx < length) && (cmdtext[idx] <= ' '))
					{
						idx++;
					}
					new offset = idx;
					new result[128];
					while ((idx < length) && ((idx - offset) < (sizeof(result) - 1)))
					{
						result[idx - offset] = cmdtext[idx];
						idx++;
					}
					result[idx - offset] = EOS;
					if(!strlen(result))
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /kick [playerid/partoName] [powód]");
						return 1;
					}
					KickPlayer(giveplayerid,GetPlayerNameEx(playerid),(result));
					return 1;
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Invalid ID.");
			}
			return 1;
		}
		if(strcmp(cmd, "/mkick", true) == 0)
		{
			if(gPlayerData[playerid][pModerator] < 1)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /kick [playerid/partoName] [powód]");
				return 1;
			}
			giveplayerid = ReturnUser(tmp);
			if(IsPlayerConnected(giveplayerid))
			{
				if(giveplayerid != INVALID_PLAYER_ID)
				{
					if(gPlayerData[giveplayerid][pAdmin] > 0)
					{
						SendClientMessage(playerid, COLOR_RED, "[B£¥D:] Nie jesteœ upowa¿niony do kickowania admina !");
						return 1;
					}
					new length = strlen(cmdtext);
					while ((idx < length) && (cmdtext[idx] <= ' '))
					{
						idx++;
					}
					new offset = idx;
					new result[128];
					while ((idx < length) && ((idx - offset) < (sizeof(result) - 1)))
					{
						result[idx - offset] = cmdtext[idx];
						idx++;
					}
					result[idx - offset] = EOS;
					if(!strlen(result))
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /kick [playerid/partoName] [powód]");
						return 1;
					}
					KickPlayer(giveplayerid,GetPlayerNameEx(playerid),(result));
					return 1;
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Invalid ID.");
			}
			return 1;
		}
		if(strcmp(cmdtext,"/aserverinfo",true)==0)
		{
			if (gPlayerData[playerid][pAdmin] != 5)
				return 0;
			new form[128];
			SendClientMessage(playerid, COLOR_WHITE,"Server Statistics:");
			format(form, sizeof form, "[INFO:] Total Objects: %d.", GetObjectCount());
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2,form);
			format(form, sizeof form, "[INFO:] Total Vehicles: %d.", GetVehicleCount());
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2,form);
			format(form, sizeof form, "[INFO:] Total Pickups: %d.", CountDynamicPickups());
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2,form);
			return 1;
		}
		if(strcmp(cmdtext,"/asuicide",true)==0)
		{
			if(gPlayerData[playerid][pAdmin] < 1)
				return 0;
			SetPlayerHealth(playerid,-1);
			return 1;
		}
		if(strcmp(cmd, "/alistfaction", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 1)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /alistfaction [id]");
				return 1;
			}
			new text = strval(tmp);
			new wstring[128];
			format(wstring, sizeof(wstring), "[ID:%d] Faction Name: %s - Materials: %d - Drugs: %d - Money: $%d - Join Rank: %d - Use Skins: %d - Type: %d",text, DynamicFactions[text][Name],DynamicFactions[text][fMaterials],DynamicFactions[text][fDrugs],DynamicFactions[text][fBank],DynamicFactions[text][fJoinRank],DynamicFactions[text][fUseSkins],DynamicFactions[text][fType]);
			SendClientMessage(playerid,COLOR_ADMINCMD, wstring);
			format(wstring, sizeof(wstring), "[ID:%d] Skins: %d|%d|%d|%d|%d|%d|%d|%d|%d|%d - Rank Amount: %d - Use Color: %d", text,DynamicFactions[text][fSkin1],DynamicFactions[text][fSkin2],DynamicFactions[text][fSkin3],DynamicFactions[text][fSkin4],DynamicFactions[text][fSkin5],DynamicFactions[text][fSkin6],DynamicFactions[text][fSkin7],DynamicFactions[text][fSkin8],DynamicFactions[text][fSkin9],DynamicFactions[text][fSkin10],DynamicFactions[text][fRankAmount],DynamicFactions[text][fUseColor]);
			SendClientMessage(playerid,COLOR_ADMINCMD, wstring);
			return 1;
		}
		if(strcmp(cmd, "/respawnvehicles", true) == 0)
		{
			if (gPlayerData[playerid][pAdmin] < 4)
				return 0;
			for(new i = 0; i < sizeof(gVehData); i++)
			{
				if(IsVehicleOccupied(i) == 0)
				{
					SetVehicleToRespawn(i);
				}
			}
			format(string, sizeof(string), "[INFO:] Pustes samochody zosta³y zrespawnowane przez %s.", GetPlayerNameEx(playerid));
			ABroadCast(COLOR_YELLOW,string,1);
			return 1;
		}
		if(strcmp(cmd, "/acarenter", true) == 0)
		{
			if (gPlayerData[playerid][pAdmin] < 1)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /acarenter [carid]");
				return 1;
			}
			new id = strval(tmp);
			if(id != INVALID_VEHICLE_ID)
				PutPlayerIntoVehicle(playerid,id,0);
			else
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Invalid Vehicle ID.");
			return 1;
		}
		if(strcmp(cmd, "/acarenterex", true) == 0)
		{
			if (gPlayerData[playerid][pAdmin] < 1)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /acarenterex [carid]");
				return 1;
			}
			new id = strval(tmp);
			if(id != INVALID_VEHICLE_ID)
			{
				SetPlayerVirtualWorld(playerid, gVehData[id-1][CarVW]);
				SetPlayerInterior(playerid, gVehData[id-1][CarInterior]);
				PutPlayerIntoVehicle(playerid,id,0);
			}
			else
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Invalid Vehicle ID.");
			return 1;
		}
		if(strcmp(cmd, "/acarrandmodel", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] != 5)
				return 0;
			if(IsPlayerInAnyVehicle(playerid))
			{
				new rand = random(sizeof(gRandomStableModels));
				new Float:x,Float:y,Float:z,Float:a;
				GetPlayerPos(playerid,x,y,z);
				GetVehicleZAngle(idcar,a);
				gVehData[tmpcar][CarModel] = gRandomStableModels[rand][0];
				DestroyVehicle(idcar);
				CreateVehicle(gVehData[tmpcar][CarModel],x,y,z,a,gVehData[tmpcar][CarColor1],gVehData[tmpcar][CarColor2], -1);
				PutPlayerIntoVehicle(playerid,idcar,0);

				SaveVehData(tmpcar, "CarModel");

				new wstring[128];
				format(wstring, sizeof(wstring), "You have set Vehicle ID: %d to a random model.", idcar);
				SendClientMessage(playerid,COLOR_ADMINCMD, wstring);
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "Your not in a vehicle!");
			}
			return 1;
		}
		if(strcmp(cmd, "/aFactionCar", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "U¯YCIE: /aFactionCar [faction]");
				return 1;
			}
			new thecar = strval(tmp);
			if(IsPlayerInAnyVehicle(playerid))
			{
				if(thecar < 11 || 255)
				{
					gVehData[tmpcar][FactionCar] = thecar;
					new wstring[128];
					format(wstring, sizeof(wstring), "You've set Vehicle ID %d's faction to: %d.", idcar,thecar);
					SendClientMessage(playerid,COLOR_ADMINCMD, wstring);

					SaveVehData(tmpcar, "FactionCar");
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "Incorrect Faction ID, Correct Faction ID's: 1-10.");
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "Your not in a vehicle!");
			}
			return 1;
		}
		if(strcmp(cmd, "/acartype", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "U¯YCIE: /acartype [type]");
				return 1;
			}
			new thecar = strval(tmp);
			if(IsPlayerInAnyVehicle(playerid))
			{
				gVehData[tmpcar][CarType] = thecar;
				new wstring[128];
				format(wstring, sizeof(wstring), "You've set Vehicle ID %d's type to: %d.", idcar,thecar);
				SendClientMessage(playerid,COLOR_ADMINCMD, wstring);

				SaveVehData(tmpcar, "CarType");
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "Your not in a vehicle!");
			}
			return 1;
		}
		if(strcmp(cmd,"/onoff",true)==0)
		{
			new x_info[256];
			x_info = strtok(cmdtext, idx);

			if(!strlen(x_info)) {
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Wy³¹cza lub w³¹cza: wiadomoœci prywatne, status paliwa lub telefon.");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Parametry: pw - ooc - statuspojazdu - gps - status");
				return 1;
			}
			if(strcmp(x_info,"gps",true) == 0)
			{
				if(gPlayerData[playerid][pGPS] == 1)
				{
					if(gpsOn[playerid] == 0) //gps wylaczony
					{
						gpsOn[playerid] = 1;
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "GPS w³¹czony");
						PlayerActionMessage(playerid,15.0,"w³¹czy³ GPS");
						GPSText[playerid] = TextDrawCreate(10.0, 325.0, " ");
					}
					else if(gpsOn[playerid] == 1) //gps wlaczony
					{
						gpsOn[playerid] = 0;
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "GPS wy³aczony");
						PlayerActionMessage(playerid,15.0,"wy³¹czy³ GPS");
						TextDrawDestroy(GPSText[playerid]);
					}
					
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "Nie posiadasz urz¹dzenia GPS !");
				}
			}
			if(strcmp(x_info,"paliwo",true) == 0)
			{
				if(ShowFuel[playerid] == 1)
				{
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] Wy³¹czy³eœ wyœwietlanie statusu paliwa.");
					ShowFuel[playerid] = 0;
				}
				else
				{
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] W³¹czy³eœ wyœwietlanie statusu paliwa.");
					ShowFuel[playerid] = 1;
				}
			}
			else if(strcmp(x_info,"pw",true) == 0)
			{
				if(gPlayerData[playerid][pPWStatus])
				{
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] Nie bêdziesz ju¿ otrzymywa³ wiadomoœci prywatnych");
					gPlayerData[playerid][pPWStatus] = 0;
				}
				else
				{
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] W³¹czy³eœ otrzymywanie wiadomoœci prywatnych");
					gPlayerData[playerid][pPWStatus] = 1;	
				}
				SavePlayerData(playerid, "PWStatus");
			}
			else if(strcmp(x_info,"ooc",true) == 0)
			{
				if(gPlayerData[playerid][pOOCStatus])
				{
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] Nie bêdziesz ju¿ otrzymywa³ wiadomoœci OOC");
					gPlayerData[playerid][pOOCStatus] = 0;
				}
				else
				{
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] W³¹czy³eœ otrzymywanie wiadomoœci OOC");
					gPlayerData[playerid][pOOCStatus] = 1;	
				}
				SavePlayerData(playerid, "OOCStatus");
			}			
			else if(strcmp(x_info,"status",true) == 0)
			{
				if(PlayerStatusShowed[playerid])
				{
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] Wy³¹czy³eœ pasek statusu gracza");
					PlayerStatusShowed[playerid] = 0;
					TextDrawHideForPlayer(playerid,PlayerStatus[playerid]);
				}
				else
				{
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] W³¹czy³eœ pasek statusu gracza");
					PlayerStatusShowed[playerid] = 1;
					TextDrawShowForPlayer(playerid,PlayerStatus[playerid]);
				}
			}
			return 1;
		}
		if(strcmp(cmd,"/akceptuj",true)==0)
		{
			new x_info[256];
			x_info = strtok(cmdtext, idx);
			new wstring[128];

			if(!strlen(x_info)) {
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /akceptuj [uzycia]");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[UZYCIA:] frakcje - produkty - umoweoc - umoweac - kosztorys - kupnobiznesu");
				return 1;
			}
			if(strcmp(x_info,"kupnobiznesu",true) == 0)
			{
				if( gBizBoughtApprovalSendBy[playerid] == -1 || !IsPlayerConnected( gBizBoughtApprovalSendBy[playerid] ))
				{
					gBizBoughtApprovalSendBy[playerid] = -1;
					SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz ¿adnego zg³oszenia do rozpatrzenia" );
					return 1;
				}
				new Float:x, Float:y, Float:z;
				GetPlayerPos( gBizBoughtApprovalSendBy[playerid], x, y, z );
				if( !IsPlayerInRangeOfPoint( playerid, 5.0, x, y, z ) )
				{
					SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Jesteœ zbyt daleko od tej osoby !" );
					return 1;
				}
				gBizBoughtApproved[ gBizBoughtApprovalSendBy[playerid] ] = gBizBoughtApprovalID[ gBizBoughtApprovalSendBy[playerid] ];
				SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] Wyda³eœ pozwolenie na kupno biznesu !");
				SendClientMessage( gBizBoughtApprovalSendBy[playerid], COLOR_GREEN, "[INFO:] Otrzyma³eœ pozwolenie na kupno biznesu !" );
				gBizBoughtApprovalSendBy[playerid] = -1;
				return 1;
			}			
			if(strcmp(x_info,"frakcje",true) == 0)
			{
				new faction = FactionRequest[playerid];
				if (FactionRequest[playerid] != 255)
				{
					if(gPlayerData[playerid][pFaction] == 255)
					{
						format(wstring, sizeof(wstring), "[INFO:] Gratulacje ! Jesteœ teraz cz³onkiem frakcji: %s.",DynamicFactions[faction][Name]);
						SendClientMessage(playerid,COLOR_LIGHTBLUE, wstring);
						gPlayerData[playerid][pFaction] = FactionRequest[playerid];
						gPlayerData[playerid][pRank] = DynamicFactions[faction][fJoinRank];
						gPlayerData[playerid][pJoinedFaction] = gettime();

						SavePlayerData(playerid, "Faction");
						SavePlayerData(playerid, "Rank");
						SavePlayerData(playerid, "JoinedFaction");

						FactionRequest[playerid] = 255;
						format(wstring, sizeof(wstring), "[FRAKCJA:] %s w³¹œnie do³¹czy³ do frakcji.",GetPlayerNameEx(playerid));
						SendFactionMessage(gPlayerData[playerid][pFaction], COLOR_FACTIONCHAT, wstring);
					}
					else
					{
						SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] Jesteœ ju¿ we frakcji, musisz najpierw opuœciæ obecn¹ !");
					}
				}
				else
				{
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] Dosta³eœ oferte do³¹czenia do frakcji !");
				}
			}
			if(strcmp(x_info,"kosztorys", true) == 0)
			{
				if(AccountantOffer[playerid] < 999)
				{
					if(IsPlayerConnected(AccountantOffer[playerid]))
					{
						if(ProxDetectorS(5.0, playerid, AccountantOffer[playerid]))
						{
							if(GetPlayerCash(playerid) >= AccountantCost[playerid])
							{
								new cars, houses, businesses, phones, richest, tickets, radio, ensurance, other;
								tickets = gPlayerData[playerid][pTicket];
								
								if(gPlayerData[playerid][pFaction] != 255 || gPlayerData[playerid][pJob] != 0)
								{
									if(gPlayerData[playerid][pItem1type] == 2) { cars += floatround((cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem1]))-400]* DBVariables[0][varFValue]) * DynamicTaxes[CarTax],floatround_round); }
									if(gPlayerData[playerid][pItem2type] == 2) { cars += floatround((cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem2]))-400]* DBVariables[0][varFValue]) * DynamicTaxes[CarTax],floatround_round); }
									if(gPlayerData[playerid][pItem3type] == 2) { cars += floatround((cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem3]))-400]* DBVariables[0][varFValue]) * DynamicTaxes[CarTax],floatround_round); }
									if(gPlayerData[playerid][pItem4type] == 2) { cars += floatround((cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem4]))-400]* DBVariables[0][varFValue]) * DynamicTaxes[CarTax],floatround_round); }
									if(gPlayerData[playerid][pItem5type] == 2) { cars += floatround((cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem5]))-400]* DBVariables[0][varFValue]) * DynamicTaxes[CarTax],floatround_round); }
									if(gPlayerData[playerid][pItem6type] == 2) { cars += floatround((cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem6]))-400]* DBVariables[0][varFValue]) * DynamicTaxes[CarTax],floatround_round); }
									if(gPlayerData[playerid][pItem7type] == 2) { cars += floatround((cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem7]))-400]* DBVariables[0][varFValue]) * DynamicTaxes[CarTax],floatround_round); }
									if(gPlayerData[playerid][pItem8type] == 2) { cars += floatround((cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem8]))-400]* DBVariables[0][varFValue]) * DynamicTaxes[CarTax],floatround_round); }
									if(gPlayerData[playerid][pItem9type] == 2) { cars += floatround((cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem9]))-400]* DBVariables[0][varFValue]) * DynamicTaxes[CarTax],floatround_round); }
									if(gPlayerData[playerid][pItem10type] == 2) { cars += floatround((cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem10]))-400]* DBVariables[0][varFValue]) * DynamicTaxes[CarTax],floatround_round); }
									if(gPlayerData[playerid][pBizKey] != 255) { businesses += floatround(Businesses[gPlayerData[playerid][pBizKey]][BizPrice] * DynamicTaxes[BusinessTax],floatround_round); }
								
									radio += DynamicTaxes[RadioTax];
									if(gPlayerData[playerid][pCash] + gPlayerData[playerid][pBank] >= DynamicTaxes[TheRich]) { richest += floatround(((gPlayerData[playerid][pCash] + gPlayerData[playerid][pBank]) * 0.01),floatround_round); }
								}
								
								new occost;
								
								if(gPlayerData[playerid][pItem1type] == 2)
								{
									if(gPlayerData[playerid][pItem1param] != 0 && gPlayerData[playerid][pItem1param] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem1]))-400]) * 0.1, floatround_round))
									{
										occost += 200;
									}
									if(gPlayerData[playerid][pItem1param] != 0 && gPlayerData[playerid][pItem1param] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem1]))-400]) * 0.2, floatround_round))
									{
										occost += 400;
									}
									if(gPlayerData[playerid][pItem1param] != 0 && gPlayerData[playerid][pItem1param] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem1]))-400]) * 0.5, floatround_round))
									{
										occost += 1000;
									}
								}
								if(gPlayerData[playerid][pItem2type] == 2)
								{
									if(gPlayerData[playerid][pItem2param] != 0 && gPlayerData[playerid][pItem2param] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem2]))-400]) * 0.1, floatround_round))
									{
										occost += 200;
									}
									if(gPlayerData[playerid][pItem2param] != 0 && gPlayerData[playerid][pItem2param] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem2]))-400]) * 0.2, floatround_round))
									{
										occost += 400;
									}
									if(gPlayerData[playerid][pItem2param] != 0 && gPlayerData[playerid][pItem2param] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem2]))-400]) * 0.5, floatround_round))
									{
										occost += 1000;
									}
								}
								if(gPlayerData[playerid][pItem3type] == 2)
								{
									if(gPlayerData[playerid][pItem3param] != 0 && gPlayerData[playerid][pItem3param] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem3]))-400]) * 0.1, floatround_round))
									{
										occost += 200;
									}
									if(gPlayerData[playerid][pItem3param] != 0 && gPlayerData[playerid][pItem3param] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem3]))-400]) * 0.2, floatround_round))
									{
										occost += 400;
									}
									if(gPlayerData[playerid][pItem3param] != 0 && gPlayerData[playerid][pItem3param] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem3]))-400]) * 0.5, floatround_round))
									{
										occost += 1000;
									}
								}
								if(gPlayerData[playerid][pItem4type] == 2)
								{
									if(gPlayerData[playerid][pItem4param] != 0 && gPlayerData[playerid][pItem4param] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem4]))-400]) * 0.1, floatround_round))
									{
										occost += 200;
									}
									if(gPlayerData[playerid][pItem4param] != 0 && gPlayerData[playerid][pItem4param] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem4]))-400]) * 0.2, floatround_round))
									{
										occost += 400;
									}
									if(gPlayerData[playerid][pItem4param] != 0 && gPlayerData[playerid][pItem4param] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem4]))-400]) * 0.5, floatround_round))
									{
										occost += 1000;
									}
								}
								if(gPlayerData[playerid][pItem5type] == 2)
								{
									if(gPlayerData[playerid][pItem5param] != 0 && gPlayerData[playerid][pItem5param] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem5]))-400]) * 0.1, floatround_round))
									{
										occost += 200;
									}
									if(gPlayerData[playerid][pItem5param] != 0 && gPlayerData[playerid][pItem5param] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem5]))-400]) * 0.2, floatround_round))
									{
										occost += 400;
									}
									if(gPlayerData[playerid][pItem5param] != 0 && gPlayerData[playerid][pItem5param] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem5]))-400]) * 0.5, floatround_round))
									{
										occost += 1000;
									}
								}
								if(gPlayerData[playerid][pItem6type] == 2)
								{
									if(gPlayerData[playerid][pItem6param] != 0 && gPlayerData[playerid][pItem6param] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem6]))-400]) * 0.1, floatround_round))
									{
										occost += 200;
									}
									if(gPlayerData[playerid][pItem6param] != 0 && gPlayerData[playerid][pItem6param] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem6]))-400]) * 0.2, floatround_round))
									{
										occost += 400;
									}
									if(gPlayerData[playerid][pItem6param] != 0 && gPlayerData[playerid][pItem6param] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem6]))-400]) * 0.5, floatround_round))
									{
										occost += 1000;
									}
								}
								if(gPlayerData[playerid][pItem7type] == 2)
								{
									if(gPlayerData[playerid][pItem7param] != 0 && gPlayerData[playerid][pItem7param] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem7]))-400]) * 0.1, floatround_round))
									{
										occost += 200;
									}
									if(gPlayerData[playerid][pItem7param] != 0 && gPlayerData[playerid][pItem7param] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem7]))-400]) * 0.2, floatround_round))
									{
										occost += 400;
									}
									if(gPlayerData[playerid][pItem7param] != 0 && gPlayerData[playerid][pItem7param] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem7]))-400]) * 0.5, floatround_round))
									{
										occost += 1000;
									}
								}
								if(gPlayerData[playerid][pItem8type] == 2)
								{
									if(gPlayerData[playerid][pItem8param] != 0 && gPlayerData[playerid][pItem8param] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem8]))-400]) * 0.1, floatround_round))
									{
										occost += 200;
									}
									if(gPlayerData[playerid][pItem8param] != 0 && gPlayerData[playerid][pItem8param] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem8]))-400]) * 0.2, floatround_round))
									{
										occost += 400;
									}
									if(gPlayerData[playerid][pItem8param] != 0 && gPlayerData[playerid][pItem8param] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem8]))-400]) * 0.5, floatround_round))
									{
										occost += 1000;
									}
								}
								if(gPlayerData[playerid][pItem9type] == 2)
								{
									if(gPlayerData[playerid][pItem9param] != 0 && gPlayerData[playerid][pItem9param] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem9]))-400]) * 0.1, floatround_round))
									{
										occost += 200;
									}
									if(gPlayerData[playerid][pItem9param] != 0 && gPlayerData[playerid][pItem9param] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem9]))-400]) * 0.2, floatround_round))
									{
										occost += 400;
									}
									if(gPlayerData[playerid][pItem9param] != 0 && gPlayerData[playerid][pItem9param] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem9]))-400]) * 0.5, floatround_round))
									{
										occost += 1000;
									}
								}
								if(gPlayerData[playerid][pItem10type] == 2)
								{
									if(gPlayerData[playerid][pItem10param] != 0 && gPlayerData[playerid][pItem10param] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem10]))-400]) * 0.1, floatround_round))
									{
										occost += 200;
									}
									if(gPlayerData[playerid][pItem10param] != 0 && gPlayerData[playerid][pItem10param] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem10]))-400]) * 0.2, floatround_round))
									{
										occost += 400;
									}
									if(gPlayerData[playerid][pItem10param] != 0 && gPlayerData[playerid][pItem10param] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem10]))-400]) * 0.5, floatround_round))
									{
										occost += 1000;
									}
								}
								
								new accost = 0;
								
								if(gPlayerData[playerid][pItem1type] == 2)
								{
									if(gPlayerData[playerid][pItem1param2] != 0 && gPlayerData[playerid][pItem1param2] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem1]))-400]) * 0.15, floatround_round))
									{
										accost += 200;
									}
									if(gPlayerData[playerid][pItem1param2] != 0 && gPlayerData[playerid][pItem1param2] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem1]))-400]) * 0.3, floatround_round))
									{
										accost += 400;
									}
									if(gPlayerData[playerid][pItem1param2] != 0 && gPlayerData[playerid][pItem1param2] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem1]))-400]) * 0.5, floatround_round))
									{
										accost += 1000;
									}
								}
								if(gPlayerData[playerid][pItem2type] == 2)
								{
									if(gPlayerData[playerid][pItem2param2] != 0 && gPlayerData[playerid][pItem2param2] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem2]))-400]) * 0.15, floatround_round))
									{
										accost += 200;
									}
									if(gPlayerData[playerid][pItem2param2] != 0 && gPlayerData[playerid][pItem2param2] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem2]))-400]) * 0.3, floatround_round))
									{
										accost += 400;
									}
									if(gPlayerData[playerid][pItem2param2] != 0 && gPlayerData[playerid][pItem2param2] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem2]))-400]) * 0.5, floatround_round))
									{
										accost += 1000;
									}
								}
								if(gPlayerData[playerid][pItem3type] == 2)
								{
									if(gPlayerData[playerid][pItem3param2] != 0 && gPlayerData[playerid][pItem3param2] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem3]))-400]) * 0.15, floatround_round))
									{
										accost += 200;
									}
									if(gPlayerData[playerid][pItem3param2] != 0 && gPlayerData[playerid][pItem3param2] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem3]))-400]) * 0.3, floatround_round))
									{
										accost += 400;
									}
									if(gPlayerData[playerid][pItem3param2] != 0 && gPlayerData[playerid][pItem3param2] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem3]))-400]) * 0.5, floatround_round))
									{
										accost += 1000;
									}
								}
								if(gPlayerData[playerid][pItem4type] == 2)
								{
									if(gPlayerData[playerid][pItem4param2] != 0 && gPlayerData[playerid][pItem4param2] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem4]))-400]) * 0.15, floatround_round))
									{
										accost += 200;
									}
									if(gPlayerData[playerid][pItem4param2] != 0 && gPlayerData[playerid][pItem4param2] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem4]))-400]) * 0.3, floatround_round))
									{
										accost += 400;
									}
									if(gPlayerData[playerid][pItem4param2] != 0 && gPlayerData[playerid][pItem4param2] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem4]))-400]) * 0.5, floatround_round))
									{
										accost += 1000;
									}
								}
								if(gPlayerData[playerid][pItem5type] == 2)
								{
									if(gPlayerData[playerid][pItem5param2] != 0 && gPlayerData[playerid][pItem5param2] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem5]))-400]) * 0.15, floatround_round))
									{
										accost += 200;
									}
									if(gPlayerData[playerid][pItem5param2] != 0 && gPlayerData[playerid][pItem5param2] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem5]))-400]) * 0.3, floatround_round))
									{
										accost += 400;
									}
									if(gPlayerData[playerid][pItem5param2] != 0 && gPlayerData[playerid][pItem5param2] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem5]))-400]) * 0.5, floatround_round))
									{
										accost += 1000;
									}
								}
								if(gPlayerData[playerid][pItem6type] == 2)
								{
									if(gPlayerData[playerid][pItem6param2] != 0 && gPlayerData[playerid][pItem6param2] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem6]))-400]) * 0.15, floatround_round))
									{
										accost += 200;
									}
									if(gPlayerData[playerid][pItem6param2] != 0 && gPlayerData[playerid][pItem6param2] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem6]))-400]) * 0.3, floatround_round))
									{
										accost += 400;
									}
									if(gPlayerData[playerid][pItem6param2] != 0 && gPlayerData[playerid][pItem6param2] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem6]))-400]) * 0.5, floatround_round))
									{
										accost += 1000;
									}
								}
								if(gPlayerData[playerid][pItem7type] == 2)
								{
									if(gPlayerData[playerid][pItem7param2] != 0 && gPlayerData[playerid][pItem7param2] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem7]))-400]) * 0.15, floatround_round))
									{
										accost += 200;
									}
									if(gPlayerData[playerid][pItem7param2] != 0 && gPlayerData[playerid][pItem7param2] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem7]))-400]) * 0.3, floatround_round))
									{
										accost += 400;
									}
									if(gPlayerData[playerid][pItem7param2] != 0 && gPlayerData[playerid][pItem7param2] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem7]))-400]) * 0.5, floatround_round))
									{
										accost += 1000;
									}
								}
								if(gPlayerData[playerid][pItem8type] == 2)
								{
									if(gPlayerData[playerid][pItem8param2] != 0 && gPlayerData[playerid][pItem1param2] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem8]))-400]) * 0.15, floatround_round))
									{
										accost += 200;
									}
									if(gPlayerData[playerid][pItem8param2] != 0 && gPlayerData[playerid][pItem8param2] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem8]))-400]) * 0.3, floatround_round))
									{
										accost += 400;
									}
									if(gPlayerData[playerid][pItem8param2] != 0 && gPlayerData[playerid][pItem8param2] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem8]))-400]) * 0.5, floatround_round))
									{
										accost += 1000;
									}
								}
								if(gPlayerData[playerid][pItem9type] == 2)
								{
									if(gPlayerData[playerid][pItem9param2] != 0 && gPlayerData[playerid][pItem9param2] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem9]))-400]) * 0.15, floatround_round))
									{
										accost += 200;
									}
									if(gPlayerData[playerid][pItem9param2] != 0 && gPlayerData[playerid][pItem9param2] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem9]))-400]) * 0.3, floatround_round))
									{
										accost += 400;
									}
									if(gPlayerData[playerid][pItem9param2] != 0 && gPlayerData[playerid][pItem9param2] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem9]))-400]) * 0.5, floatround_round))
									{
										accost += 1000;
									}
								}
								if(gPlayerData[playerid][pItem10type] == 2)
								{
									if(gPlayerData[playerid][pItem10param2] != 0 && gPlayerData[playerid][pItem10param2] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem10]))-400]) * 0.15, floatround_round))
									{
										accost += 200;
									}
									if(gPlayerData[playerid][pItem10param2] != 0 && gPlayerData[playerid][pItem10param2] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem10]))-400]) * 0.3, floatround_round))
									{
										accost += 400;
									}
									if(gPlayerData[playerid][pItem10param2] != 0 && gPlayerData[playerid][pItem10param2] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem10]))-400]) * 0.5, floatround_round))
									{
										accost += 1000;
									}
								}
								
								ensurance = accost + occost;
								
								GivePlayerCash(AccountantOffer[playerid],AccountantCost[playerid]);
								GivePlayerCash(playerid,AccountantCost[playerid]);
								AccountantOffer[playerid] = 999;
								AccountantCost[playerid] = 0;
								
								format(string, sizeof(string), "[PODATKI:] Pojazdy: %d$, Domy: %d$, Biznesy: %d$, Telefon: %d$, Radio: %d$, Od bogatych: %d$", cars, houses, businesses, phones, radio, richest);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								format(string, sizeof(string), "[KOSZTY:] Mandaty: %d$, Ubezpieczenie: %d$, Inne koszta: %d$", tickets, ensurance, other);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								format(string, sizeof(string), "[KOSZTY:] Suma: %d$",cars+houses+businesses+phones,radio+richest+tickets+ensurance+other);
								SendClientMessage(playerid, COLOR_RED, string);
							}
							else
							{
								SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie masz wystarczaj¹co du¿o pieniêdzy");
								return 1;
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Jesteœ za daleko od osoby oferuj¹cej kosztorys !");
							return 1;
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_RED, "[INFO:] Gracz opuœci³ serwer");
						return 1;
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_RED, "[INFO:] Nikt nie zaoferowa³ tobie ¿adnego kosztorysu !");
					return 1;
				}
				return 1;
			}
			if(strcmp(x_info,"produkty",true) == 0)
			{
				if(ProductsOffer[playerid] < 999)
				{
					if(IsPlayerConnected(ProductsOffer[playerid]))
					{
						if (ProxDetectorS(5.0, playerid, ProductsOffer[playerid]))
						{
							if(GetPlayerCash(playerid) >= ProductsCost[playerid])
							{
								if(gPlayerData[playerid][pBizKey] != 255)
								{
									if( ( ProductsOffer[playerid] + Businesses[gPlayerData[playerid][pBizKey]][Products] ) > 200)
									{
										SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Mo¿esz przechowywaæ jedynie 200 produktów w swoim biznesie !");
										return 1;
									}
									format(string, sizeof(string), "[INFO:] Produkty kupione - koszt: $%d.", ProductsCost[playerid]);
									SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
									format(string, sizeof(string), "[INFO:] %s kupi³ od Ciebie produkty - koszt: $%d.", GetPlayerNameEx(playerid), ProductsCost[playerid]);
									SendClientMessage(ProductsOffer[playerid], COLOR_LIGHTYELLOW2, string);
									new bizkey = gPlayerData[playerid][pBizKey];
									Businesses[bizkey][Products] += ProductsAmount[playerid];
									GivePlayerCash(playerid, -ProductsCost[playerid]);
									GivePlayerCash(ProductsOffer[playerid], ProductsCost[playerid]);

									SavePlayerData(ProductsOffer[playerid], "Products");

									SaveStatsData("produkty", gPlayerData[playerid][pName], ProductsCost[playerid], -1, -1);
									
									ProductsOffer[playerid] = 999;
									ProductsCost[playerid] = 0;
									ProductsAmount[playerid] = 0;
									SaveBizData(bizkey, "Products");

									return 1;
								}
								else
								{
									SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz biznesu !");
									return 1;
								}
							}
							else
							{
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie masz wystarczaj¹cej iloœci pieniêdzy !");
								return 1;
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie jesteœ wystarczaj¹co blisko osoby która oferuje produkty !");
							return 1;
						}
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nikt nie zaoferowa³ Tobie produktów !");
					return 1;
				}
			}
			if(strcmp(x_info,"umoweoc",true) == 0)
			{
				new vehid = CheckPlayerCarSerial(playerid, EnsuranceOC[playerid][vehicleNr]);
				if(EnsuranceOC[playerid][Level] == 0)
				{
					SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie posiadasz umowy OC do podpisania !");
					return 1;
				}
				if(gPlayerData[playerid][pCash] < 2000)
				{
					SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie masz wystarczaj¹cej iloœc pieniêdzy (2000$) by podpisaæ umowe !");
					return 1;
				}
				DynamicFactions[FACTIONID_GOVERNMENT][fBank] += 2000;
				SaveFData(FACTIONID_GOVERNMENT, "Bank");
				GivePlayerCash(playerid, -2000);
				if(EnsuranceOC[playerid][Level] == 1)
				{
					SetPSlotParam1(playerid, EnsuranceOC[playerid][vehicleNr], floatround(float(cenyPojazdow[gVehData[vehid][CarModel]-400]) * 0.1, floatround_round));
					SendClientMessage(playerid, COLOR_GREEN, "[INFO:] Ubezpieczenie OC zosta³o aktywowane !");
				}
				if(EnsuranceOC[playerid][Level] == 2)
				{
					SetPSlotParam1(playerid, EnsuranceOC[playerid][vehicleNr], floatround(float(cenyPojazdow[gVehData[vehid][CarModel]-400]) * 0.2, floatround_round));
					SendClientMessage(playerid, COLOR_GREEN, "[INFO:] Ubezpieczenie OC zosta³o aktywowane !");
				}
				if(EnsuranceOC[playerid][Level] == 3)
				{
					SetPSlotParam1(playerid, EnsuranceOC[playerid][vehicleNr], floatround(float(cenyPojazdow[gVehData[vehid][CarModel]-400]) * 0.5, floatround_round));
					SendClientMessage(playerid, COLOR_GREEN, "[INFO:] Ubezpieczenie OC zosta³o aktywowane !");
				}
				EnsuranceOC[playerid][Level] = 0;
			}
			if(strcmp(x_info,"umoweac",true) == 0)
			{
				new vehid = CheckPlayerCarSerial(playerid, EnsuranceAC[playerid][vehicleNr]);
				if(EnsuranceAC[playerid][Level] == 0)
				{
					SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie posiadasz umowy AC do podpisania !");
					return 1;
				}
				if(gPlayerData[playerid][pCash] < 2000)
				{
					SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie masz wystarczaj¹cej iloœc pieniêdzy (2000$) by podpisaæ umowe !");
					return 1;
				}
				DynamicFactions[FACTIONID_GOVERNMENT][fBank] += 2000;
				SaveFData(FACTIONID_GOVERNMENT, "Bank");
				GivePlayerCash(playerid, -2000);
				if(EnsuranceAC[playerid][Level] == 1)
				{
					SetPSlotParam2(playerid, EnsuranceOC[playerid][vehicleNr], floatround(float(cenyPojazdow[gVehData[vehid][CarModel]-400]) * 0.15, floatround_round));
					SendClientMessage(playerid, COLOR_GREEN, "[INFO:] Ubezpieczenie AC zosta³o aktywowane !");
				}
				if(EnsuranceAC[playerid][Level] == 2)
				{
					SetPSlotParam2(playerid, EnsuranceOC[playerid][vehicleNr], floatround(float(cenyPojazdow[gVehData[vehid][CarModel]-400]) * 0.3, floatround_round));
					SendClientMessage(playerid, COLOR_GREEN, "[INFO:] Ubezpieczenie AC zosta³o aktywowane !");
				}
				if(EnsuranceAC[playerid][Level] == 3)
				{
					SetPSlotParam2(playerid, EnsuranceOC[playerid][vehicleNr], floatround(float(cenyPojazdow[gVehData[vehid][CarModel]-400]) * 0.5, floatround_round));
					SendClientMessage(playerid, COLOR_GREEN, "[INFO:] Ubezpieczenie AC zosta³o aktywowane !");
				}
				EnsuranceAC[playerid][Level] = 0;
			}
			return 1;
		}
		//========================================[HELP & INFORMATION COMMANDS]===================================================
		if(strcmp(cmd, "/fwyplac", true) == 0)
		{
			if(gPlayerData[playerid][pFaction] != 255)
			{
				tmp = strtok(cmdtext, idx);
				if(!strlen(tmp))
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /fwyplac [kwota]");
					return 1;
				}
				new cashdeposit = strval(tmp);
				if(!strlen(tmp))
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /fwyplac [kwota]");
					return 1;
				}
				if(cashdeposit <= 0)
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Wartoœæ przelewu musi byæ wiêksza od 0 !");
					return 1;
				}
				new inPosition = 0;
				if( !PlayerToPoint( 5.0,playerid,BankPosition[X],BankPosition[Y],BankPosition[Z] ) 
				&& !PlayerToPoint( 2.0, playerid, BankPosition2[X], BankPosition2[Y], BankPosition2[Z] ) )
				{
					for( new i = 0; i < 4; i++ )
					{
						if( !PlayerToPoint( 1.0, playerid, gATM[i][0], gATM[i][1], gATM[i][2] ) )
							continue;
						inPosition = 2;
					}
				}
				else
					inPosition = 1;
				if( inPosition == 0 )
				{
					SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Aby wyp³aciæ pieni¹dze musisz znajdowaæ siê w banku lub przy automacie" );
					return 1;
				}
				if(gPlayerData[playerid][pRank] == 1)
				{
					if(DynamicFactions[gPlayerData[playerid][pFaction]][fBank] >= cashdeposit + 3)
					{
						GivePlayerCash(playerid,cashdeposit);
						DynamicFactions[gPlayerData[playerid][pFaction]][fBank]=DynamicFactions[gPlayerData[playerid][pFaction]][fBank]-cashdeposit - 3;
						format(string, sizeof(string), "[INFO:] Wyp³aci³eœ $%d z konta frakcji, nowy stan konta: $%d", cashdeposit,DynamicFactions[gPlayerData[playerid][pFaction]][fBank]);
						SendClientMessage(playerid, COLOR_WHITE, string);
						if( inPosition == 2 )
							SendClientMessage( playerid, COLOR_WHITE, "[INFO:] Pobrano op³ate w wysokoœci 3$ za skorzystanie z automatu" );
						format(string, sizeof(string), "[FACTION:] %s wyp³aci³ $%d z konta frakcji.",gPlayerData[playerid][pName],cashdeposit);
						SendFactionMessage(gPlayerData[playerid][pFaction], COLOR_FACTIONCHAT, string);
						SaveFData(gPlayerData[playerid][pFaction], "Bank");
						format(string, sizeof(string), "[CASH:] Player: %s, withdraw: %d$, from faction id: %d", gPlayerData[playerid][pName], cashdeposit, gPlayerData[playerid][pFaction]);
						PayLog(string);
						return 1;
					}
					else
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie masz tyle pieniêdzy na koncie frakcji !");
						return 1;
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie jesteœ liderem frakcji !");
					return 1;
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Niew³aœciwa frakcja.");
			}
			return 1;
		}
		if(strcmp(cmd, "/wyplaczbiznesu", true) == 0)
		{
			if(IsPlayerConnected(playerid))
			{
				new playername[MAX_PLAYER_NAME];
				GetPlayerName(playerid, playername, sizeof(playername));
				new bouse = gPlayerData[playerid][pBizKey];
				if(bouse != 255 && strcmp(playername, Businesses[bouse][Owner], true) == 0)
				{
					tmp = strtok(cmdtext, idx);
					if(!strlen(tmp))
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /wyplaczbiznesu [kwota]");
						return 1;
					}
					new cashdeposit = strval(tmp);
					if(!strlen(tmp))
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /wyplaczbiznesu [kwota]");
						return 1;
					}
					if(cashdeposit <= 0)
					{
						SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Wyp³acana wartoœæ musi byæ wiêksza od 0");
						return 1;
					}
					if (PlayerToPoint(20.0, playerid,Businesses[bouse][ExitX],Businesses[bouse][ExitY],Businesses[bouse][ExitZ]))
					{
						if(Businesses[bouse][Till] >= cashdeposit)
						{
							if(GetPlayerVirtualWorld(playerid) == bouse)
							{
								GivePlayerCash(playerid,cashdeposit);
								Businesses[bouse][Till]=Businesses[bouse][Till]-cashdeposit;
								format(string, sizeof(string), "[INFO:] Wyp³aci³eœ $%d ze swojej kasy w biznesie, Nowy stan: $%d ", cashdeposit,Businesses[bouse][Till]);
								SendClientMessage(playerid, COLOR_WHITE, string);
								SaveBizData(bouse, "Till");
								format(string, sizeof(string), "[CASH:] Player: %s, donate: %d$, from business id: %d", gPlayerData[playerid][pName], cashdeposit, bouse);
								PayLog(string);
								return 1;
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie masz tyle w swojej kasie !");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie jesteœ w swoim biznesie !");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie kupi³eœ ¿adnego biznesu !");
				}
			}
			return 1;
		}
		if(strcmp(cmd, "/wplacdobiznesu", true) == 0)
		{
			if(IsPlayerConnected(playerid))
			{
				new bizkey = gPlayerData[playerid][pBizKey];
				new playername[MAX_PLAYER_NAME];
				GetPlayerName(playerid,playername,sizeof(playername));
				if(bizkey != 255 && strcmp(playername, Businesses[bizkey][Owner], true) == 0)
				{
					tmp = strtok(cmdtext, idx);
					if(!strlen(tmp))
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /wplacdobiznesu [kwota]");
						return 1;
					}
					new cashdeposit = strval(tmp);
					if(!strlen(tmp))
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /wplacdobiznesu [kwota]");
						return 1;
					}
					if(cashdeposit <= 0)
					{
						SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Wp³acana wartoœæ musi byæ wiêksza od 0");
						return 1;
					}
					if(PlayerToPoint(5.0,playerid,Businesses[bizkey][ExitX],Businesses[bizkey][ExitY],Businesses[bizkey][ExitZ]) && GetPlayerVirtualWorld(playerid) == bizkey)
					{
							if(GetPlayerCash(playerid) >= cashdeposit)
							{
								//if(Businesses[bizkey][Till] < 500000)
								//{
									//if(cashdeposit < 500001)
									//{
										GivePlayerCash(playerid,-cashdeposit);
										Businesses[bizkey][Till]=cashdeposit+Businesses[bizkey][Till];
										format(string, sizeof(string), "[INFO:] W³o¿y³eœ do kasy $%d, nowy stan: $%d", cashdeposit,Businesses[bizkey][Till]);
										SendClientMessage(playerid, COLOR_WHITE, string);
										SaveBizData(bizkey, "Till");
										format(string, sizeof(string), "[CASH:] Player: %s, donate: %d$, for biz id: %d", gPlayerData[playerid][pName], cashdeposit, bizkey);
										PayLog(string);
										return 1;
									//}
									//else
									//{
										//SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie mo¿esz wp³aciæ wiêcej ni¿ $500,000.");
									//}
								//}
								//else
								//{
								//	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Kwota któr¹ wpisa³eœ przekracza $500,000 limit.");
								//}
							}
							else
							{
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie masz tyle pieniêdzy !");
							}
					}
					else
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie jesteœ w swoim biznesie !");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie kupi³eœ ¿adnego biznesu !");
				}
			}
			return 1;
		}
		if(strcmp(cmd, "/fwplac", true) == 0)
		{
			if(IsPlayerConnected(playerid))
			{
				if(gPlayerData[playerid][pFaction] != 255)
				{
					tmp = strtok(cmdtext, idx);
					if(!strlen(tmp))
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /fwplac [kwota]");
						return 1;
					}
					new cashdeposit = strval(tmp);
					if(!strlen(tmp))
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /fwplac [kwota]");
						return 1;
					}
					if(cashdeposit <= 0)
					{
						SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Wartoœæ przelewu musi byæ wiêksza od 0 !");
						return 1;
					}
					if(PlayerToPoint(5.0,playerid,BankPosition[X],BankPosition[Y],BankPosition[Z]) || PlayerToPoint(2.0, playerid, BankPosition2[X], BankPosition2[Y], BankPosition2[Z]))
					{
						if(GetPlayerCash(playerid) >= cashdeposit)
						{
							GivePlayerCash(playerid,-cashdeposit);
							DynamicFactions[gPlayerData[playerid][pFaction]][fBank]=cashdeposit+DynamicFactions[gPlayerData[playerid][pFaction]][fBank];
							format(string, sizeof(string), "[INFO:] Wp³aci³eœ $%d na konto frakcji, nowy stan: $%d", cashdeposit,DynamicFactions[gPlayerData[playerid][pFaction]][fBank]);
							SendClientMessage(playerid, COLOR_WHITE, string);
							format(string, sizeof(string), "[FACTION:] %s wp³aci³ $%d na konto frakcji.",gPlayerData[playerid][pName],cashdeposit);
							SendFactionMessage(gPlayerData[playerid][pFaction], COLOR_FACTIONCHAT, string);
							SaveFData(gPlayerData[playerid][pFaction], "Bank");
							format(string, sizeof(string), "[CASH:] Player: %s, donate: %d$, to faction id: %d", gPlayerData[playerid][pName], cashdeposit, gPlayerData[playerid][pFaction]);
							PayLog(string);
							return 1;
						}
						else
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie masz tyle pieniêdzy !");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie jesteœ w banku !");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie jesteœ we frakcji !");
				}
			}
			return 1;
		}
		if(strcmp(cmd, "/wplac", true) == 0)
		{
			if(PlayerToPoint(5.0,playerid,BankPosition[X],BankPosition[Y],BankPosition[Z]) || PlayerToPoint(2.0, playerid, BankPosition2[X], BankPosition2[Y], BankPosition2[Z]))
			{
				tmp = strtok(cmdtext, idx);
				if(!strlen(tmp))
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /wplac [kwota]");
					return 1;
				}
				new cashdeposit = strval(tmp);
				if(!strlen(tmp))
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /wplac [kwota]");
					return 1;
				}
				if(cashdeposit <= 0)
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Wartoœæ musi byæ wiêksza od 0 !");
					return 1;
				}
				if(GetPlayerCash(playerid) >= cashdeposit)
				{
					if( !gPlayerData[playerid][pFirstBankUse] )
					{
						gPlayerData[playerid][pFirstBankUse] = 1;
						SavePlayerData( playerid, "FirstBankUse" );
						AddExpPoint(playerid);
						SendClientMessage( playerid, COLOR_GREEN, "[INFO:] Poraz pierwszy korzystasz z us³ug banku !" );
					}
					GivePlayerCash(playerid,-cashdeposit);
					gPlayerData[playerid][pBank] = cashdeposit + gPlayerData[playerid][pBank];

					SavePlayerData(playerid, "Bank");

					format(string, sizeof(string), "[INFO:] Wp³aci³eœ $%d na Twoje konto w banku, nowy stan: $%d", cashdeposit,gPlayerData[playerid][pBank]);
					SendClientMessage(playerid, COLOR_WHITE, string);
					SavePlayerData(playerid, "Bank");
					
					format(string, sizeof(string), "[CASH:] Player: %s, donate: %d$, to bank", gPlayerData[playerid][pName], cashdeposit);
					PayLog(string);
					return 1;
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie masz tyle pieniêdzy !");
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie jesteœ w banku !");
			}
			return 1;
		}
		if(strcmp(cmd, "/wyplac", true) == 0)
		{
			new inPosition = 0;
			if( !PlayerToPoint( 5.0, playerid, BankPosition[X], BankPosition[Y], BankPosition[Z] )
				&& !PlayerToPoint( 2.0, playerid, BankPosition2[X], BankPosition2[Y], BankPosition2[Z] ) )
			{
				for( new i = 0; i < 4; i++ )
				{
					if( !PlayerToPoint( 1.0, playerid, gATM[i][0], gATM[i][1], gATM[i][2] ) )
						continue;
					inPosition = 2;
				}
			}
			else
				inPosition = 1;
			if( inPosition == 0 )
			{
				SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] ¯eby wyp³aciæ pieni¹dze musisz znajdowaæ siê w banku lub przy automacie" );
				return 1;
			}
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /wyplac [kwota]");
				return 1;
			}
			new cashdeposit = strval(tmp);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /wyplac [kwota]");
				return 1;
			}
			if(cashdeposit <= 0)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Wartoœæ musi byæ wiêksza od 0 !");
				return 1;
			}
			if(gPlayerData[playerid][pBank] >= cashdeposit)
			{
				if( !gPlayerData[playerid][pFirstBankUse] )
				{
					gPlayerData[playerid][pFirstBankUse] = 1;
					SavePlayerData( playerid, "FirstBankUse" );
					AddExpPoint(playerid);
					SendClientMessage( playerid, COLOR_GREEN, "[INFO:] Poraz pierwszy korzystasz z us³ug banku !" );
					return 1;
				}
				GivePlayerCash(playerid,cashdeposit);
				gPlayerData[playerid][pBank] -= cashdeposit ;
				if( inPosition == 2 )
				{
					gPlayerData[playerid][pBank] -= 3;
					SendClientMessage( playerid, COLOR_WHITE, "[INFO:] Pobrano op³ate w wysokoœci 3$ za skorzystanie z automatu" );
					format(string, sizeof(string), "[INFO:] Wyp³aci³eœ $%d, nowy stan: $%d (uwzglêdniono 3$)", cashdeposit,gPlayerData[playerid][pBank]);
				}
				else
					format(string, sizeof(string), "[INFO:] Wyp³aci³eœ $%d, nowy stan: $%d", cashdeposit,gPlayerData[playerid][pBank]);
				SendClientMessage(playerid, COLOR_WHITE, string);
				SavePlayerData(playerid, "Bank");
				format(string, sizeof(string), "[CASH:] Player: %s, withdraw: %d$, to bank", gPlayerData[playerid][pName], cashdeposit);
				PayLog(string);
				return 1;
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie masz tyle pieniêdzy w banku !");
			}
			return 1;
		}
		if(strcmp(cmd, "/przelew", true) == 0)
		{
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /przelew [playerid/PartOName] [kwota]");
				return 1;
			}
			giveplayerid = ReturnUser(tmp);
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /przelew [playerid/PartOName] [ktwota]");
				return 1;
			}
			if(PlayerToPoint(5.0,playerid,BankPosition[X],BankPosition[Y],BankPosition[Z]) || PlayerToPoint(2.0, playerid, BankPosition2[X], BankPosition2[Y], BankPosition2[Z]))
			{
				new moneys = strval(tmp);
				if (IsPlayerConnected(giveplayerid))
				{
					if(giveplayerid != INVALID_PLAYER_ID)
					{
						new playermoney = gPlayerData[playerid][pBank] ;
						if (moneys > 0 && playermoney >= moneys)
						{
							if(giveplayerid != playerid)
							{
								if( !gPlayerData[playerid][pFirstBankUse] )
								{
									gPlayerData[playerid][pFirstBankUse] = 1;
									SavePlayerData( playerid, "FirstBankUse" );
									AddExpPoint(playerid);
									SendClientMessage( playerid, COLOR_GREEN, "[INFO:] Poraz pierwszy korzystasz z us³ug banku !" );
									return 1;
								}
								gPlayerData[playerid][pBank] -= moneys;
								gPlayerData[giveplayerid][pBank] += moneys;
								format(string, sizeof(string), "[INFO:] Przela³eœ $%d na konto %s.", moneys, GetPlayerNameEx(giveplayerid),giveplayerid);
								SendClientMessage(playerid, COLOR_WHITE, string);
								format(string, sizeof(string), "[INFO:]Dosta³eœ przelew o wartoœci $%d od %s.", moneys, GetPlayerNameEx(playerid), playerid);
								SendClientMessage(giveplayerid, COLOR_YELLOW, string);

								SavePlayerData(playerid, "Bank");
								SavePlayerData(giveplayerid, "Bank");
								
								format(string, sizeof(string), "[CASH:] %s transfered cash value of %d$ to %s", gPlayerData[playerid][pName], moneys, gPlayerData[giveplayerid][pName]);
								PayLog(string);
							}
							else
							{
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie mo¿esz sam sobie przelaæ pieniêdzy !");
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Niew³aœciwa kwota.");
						}
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Niew³aœciwe ID.");
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie jesteœ w banku !");
			}
			return 1;
		}
		if(strcmp(cmd, "/stankonta", true) == 0)
		{
			new inPosition = 0;
			if( !PlayerToPoint( 5.0, playerid, BankPosition[X], BankPosition[Y], BankPosition[Z] )
				&& !PlayerToPoint( 2.0, playerid, BankPosition2[X], BankPosition2[Y], BankPosition2[Z] ) )
			{
				for( new i = 0; i < 4; i++ )
				{
					if( !PlayerToPoint( 1.0, playerid, gATM[i][0], gATM[i][1], gATM[i][2] ) )
						continue;
					inPosition = 2;
				}
			}
			else
				inPosition = 1;
			if( inPosition == 0 )
			{
				SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] ¯eby sprawdziæ stan konta musisz znajdowaæ siê w banku lub przy automacie" );
				return 1;
			}
			format(string, sizeof(string), "[INFO:] Stan konta: $%d.", gPlayerData[playerid][pBank]);
			if( !gPlayerData[playerid][pFirstBankUse] )
			{
				gPlayerData[playerid][pFirstBankUse] = 1;
				SavePlayerData( playerid, "FirstBankUse" );
				AddExpPoint(playerid);
				SendClientMessage( playerid, COLOR_GREEN, "[INFO:] Poraz pierwszy korzystasz z us³ug banku !" );
				return 1;
			}
			SendClientMessage(playerid, COLOR_WHITE, string);
			return 1;
		}
		if(strcmp(cmd, "/fstankonta", true) == 0)
		{
			if( gPlayerData[playerid][pFaction] == 255 )
			{
				SendClientMessage(playerid, COLOR_RED, "[B£¥D:] Niew³aœciwa frakcja !");
				return 1;
			}
			if( gPlayerData[playerid][pRank] != 1 )
			{
				SendClientMessage(playerid, COLOR_RED, "[B£¥D:] Niew³aœciwa frakcja !");
				return 1;
			}
			new inPosition = 0;
			if( !PlayerToPoint( 5.0, playerid, BankPosition[X], BankPosition[Y], BankPosition[Z] )
				&& !PlayerToPoint( 2.0, playerid, BankPosition2[X], BankPosition2[Y], BankPosition2[Z] ) )
			{
				for( new i = 0; i < 4; i++ )
				{
					if( !PlayerToPoint( 1.0, playerid, gATM[i][0], gATM[i][1], gATM[i][2] ) )
						continue;
					inPosition = 2;
				}
			}
			else
				inPosition = 1;
			if( inPosition == 0 )
			{
				SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] ¯eby sprawdziæ stan konta musisz znajdowaæ siê w banku lub przy automacie" );
				return 1;
			}
			format(string, sizeof(string), "[INFO:] Stan konta frakcji: $%d.", DynamicFactions[gPlayerData[playerid][pFaction]][fBank]);
			SendClientMessage(playerid, COLOR_WHITE, string);
			return 1;
		}
		if(strcmp(cmd, "/fmatsy", true) == 0)
		{
			if(gPlayerData[playerid][pFaction] != 255 && DynamicFactions[gPlayerData[playerid][pFaction]][fType] != 1)
			{
				if(PlayerToPoint(5.0,playerid,FactionMaterialsStorage[X],FactionMaterialsStorage[Y],FactionMaterialsStorage[Z]))
				{
					format(string, sizeof(string), "[INFO:] Iloœæ materia³ów: %d.", DynamicFactions[gPlayerData[playerid][pFaction]][fMaterials]);
					SendClientMessage(playerid, COLOR_WHITE, string);
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie jesteœ we frakcyjnym sk³adzie materia³ów !");
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Niew³aœciwa frakcja.");
			}
			return 1;
		}
		if(strcmp(cmd, "/fnarkotyki", true) == 0)
		{
			if(gPlayerData[playerid][pFaction] != 255 && DynamicFactions[gPlayerData[playerid][pFaction]][fType] != 1)
			{
				if(PlayerToPoint(5.0,playerid,FactionDrugsStorage[X],FactionDrugsStorage[Y],FactionDrugsStorage[Z]))
				{
					format(string, sizeof(string), "[INFO:] Iloœæ narkotyków: %d.", DynamicFactions[gPlayerData[playerid][pFaction]][fDrugs]);
					SendClientMessage(playerid, COLOR_WHITE, string);
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie jesteœ we frakcyjnym sk³adzie narkotyków!");
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Niew³¹œciwe ID.");
			}
			return 1;
		}
		if(strcmp(cmd, "/wyplaczdomu", true) == 0)
		{
			for(new i = 0; i < sizeof(Houses); i++)
			{
				if(PlayerToPoint(15.0, playerid,Houses[i][ExitX], Houses[i][ExitY], Houses[i][ExitZ]) && i == GetPlayerVirtualWorld(playerid))
				{
					tmp = strtok(cmdtext, idx);
					if(!strlen(tmp))
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /wyplaczdomu [kwota]");
						return 1;
					}
					new cashdeposit = strval(tmp);
					if(!strlen(tmp))
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /wyplaczdomu [kwota]");
						return 1;
					}
					if(cashdeposit <= 0)
					{
						SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Wyp³acana wartoœæ musi byæ wiêksza od 0");
						return 1;
					}
					if(Houses[i][Money] >= cashdeposit)
					{
						if(GetPlayerVirtualWorld(playerid) == i)
						{
							GivePlayerCash(playerid,cashdeposit);
							Houses[i][Money] -= cashdeposit;
							format(string, sizeof(string), "[INFO:] Wyp³aci³eœ $%d ze swojego sejfu, nowy stan: $%d ", cashdeposit,Houses[i][Money]);
							SendClientMessage(playerid, COLOR_WHITE, string);
							SaveHouseData(i, "Money");
							format(string, sizeof(string), "[CASH:] Player: %s, withdraw: %d$, form house id: %d", gPlayerData[playerid][pName], cashdeposit, i);
							PayLog(string);
							return 1;
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie posiadasz tyle piniêdzy w swoim sejfie !");
					}
				}
			}
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Musisz znajdowaæ siê w domu aby wzi¹œæ pieni¹dze");

			return 1;
		}
		if(strcmp(cmd, "/wplacdodomu", true) == 0)
		{
			for(new i = 0; i < sizeof(Houses); i++)
			{
				if(PlayerToPoint(15.0, playerid,Houses[i][ExitX], Houses[i][ExitY], Houses[i][ExitZ]) && i == GetPlayerVirtualWorld(playerid))
				{
					tmp = strtok(cmdtext, idx);
					if(!strlen(tmp))
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /wplacdodomu [kwota]");
						return 1;
					}
					new cashdeposit = strval(tmp);
					if(!strlen(tmp))
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /wplacdodomu [kwota]");
						return 1;
					}
					if(cashdeposit <= 0)
					{
						SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Wp³acana wartoœæ musi byæ wiêksza od 0");
						return 1;
					}
					if(GetPlayerCash(playerid) >= cashdeposit)
					{
						if(GetPlayerVirtualWorld(playerid) == i)
						{
							if(Houses[i][Money] < 150000)
							{
								if(cashdeposit < 150001)
								{
									GivePlayerCash(playerid,-cashdeposit);

									Houses[i][Money] += cashdeposit;

									format(string, sizeof(string), "[INFO:] Wp³aci³eœ $%d do swojego sejfu, nowy stan: $%d ", cashdeposit,Houses[i][Money]);
									SendClientMessage(playerid, COLOR_WHITE, string);
									
									format(string, sizeof(string), "[CASH:] Player: %s, donate: %d$, form house id: %d", gPlayerData[playerid][pName], cashdeposit, i);
									PayLog(string);

									SaveHouseData(i, "Money");
								}
								else
								{
									SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie mo¿esz wp³aciæ wiêcej ni¿ $150000.");
								}
							}
							else
							{
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Osi¹gn¹³eœ limit iloœci piniêdzy w sejfie ($150,000)");
							}
							return 1;
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie masz tyle pieniêdzy !");
					}
				}
			}
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Musisz znajdowaæ siê w domu aby schowaæ pieni¹dze");

			return 1;
		}
		if(strcmp(cmd, "/weznarkotyki", true) == 0)
		{
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /weznarkotyki [gram]");
				return 1;
			}
			new materialsdeposit = strval(tmp);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /weznarkotyki [gram]");
				return 1;
			}
			for(new i = 0; i < sizeof(Houses); i++)
			{
				if(!PlayerToPoint(15.0, playerid,Houses[i][ExitX], Houses[i][ExitY], Houses[i][ExitZ]) || i != GetPlayerVirtualWorld(playerid))
					continue;
				if(GetPlayerVirtualWorld(playerid) != i)
					continue;
				if(materialsdeposit < 0)
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Wartoœæ nie mo¿e byæ ujemna !");
					return 1;
				}
				if(Houses[i][Drugs] < materialsdeposit)
				{
					format(string, sizeof(string), "[INFO:] Nie posiadasz tylu narkotyków w domu ! Obecna iloœæ w gramach to %d", Houses[i][Drugs]);
					SendClientMessage(playerid, COLOR_ORANGE, string);
					return 1;
				}				
				gPlayerData[playerid][pDrugs] += materialsdeposit;
				SavePlayerData(playerid, "Drugs");
				Houses[i][Drugs] -= materialsdeposit;
				SaveHouseData(i, "Drugs");
				format(string, sizeof(string), "[INFO:] Wzi¹³eœ %d narkotyków ze swojego sejfu, nowa iloœæ: %d ", materialsdeposit,Houses[i][Drugs]);
				SendClientMessage(playerid, COLOR_WHITE, string);
				PlayerActionMessage(playerid, 15.0, "wyjmuje narkotyki");
				return 1;
			}
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Musisz znajdowaæ siê w domu aby pobraæ narkotyki");
			return 1;
		}
		if(strcmp(cmd, "/schowajnarkotyki", true) == 0)
		{
			for(new i = 0; i < sizeof(Houses); i++)
			{
				if(PlayerToPoint(15.0, playerid,Houses[i][ExitX], Houses[i][ExitY], Houses[i][ExitZ]) && i == GetPlayerVirtualWorld(playerid))
				{
					tmp = strtok(cmdtext, idx);
					if(!strlen(tmp))
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /schowajnarkotyki [iloœæ]");
						return 1;
					}
					new materialsdeposit = strval(tmp);
					if(!strlen(tmp))
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /schowajnarkotyki [iloœæ]");
						return 1;
					}
					if(gPlayerData[playerid][pDrugs] >= materialsdeposit)
					{
						if(GetPlayerVirtualWorld(playerid) == i)
						{
							if(Houses[i][Drugs] < 500)
							{
								if(materialsdeposit < 501)
								{
									gPlayerData[playerid][pDrugs] -= materialsdeposit;

									SavePlayerData(playerid, "Drugs");

									Houses[i][Drugs] += materialsdeposit;

									format(string, sizeof(string), "[INFO:] Schowa³eœ %d narkotyków w swoim sejfie, nowa iloœæ: %d ", materialsdeposit,Houses[i][Materials]);
									SendClientMessage(playerid, COLOR_WHITE, string);

									PlayerActionMessage(playerid, 15.0, "chowa narkotyki");
									
									SaveHouseData(i, "Drugs");
								}
								else
								{
									SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie mo¿esz schowaæ wiêcej ni¿ 500 narkotyków !");
								}
							}
							else
							{
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Osi¹gn¹³eœ limit schowanych narkotyków w domu. (500)");
							}
							return 1;
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie posiadasz tyle narkotyków !");
					}
				}
			}
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Musisz znajdowaæ siê w domu aby schowaæ narkotyki");

			return 1;
		}
		if(strcmp(cmd, "/schowajmaterialy", true) == 0)
		{
			for(new i = 0; i < sizeof(Houses); i++)
			{
				if(PlayerToPoint(15.0, playerid,Houses[i][ExitX], Houses[i][ExitY], Houses[i][ExitZ]) && i == GetPlayerVirtualWorld(playerid))
				{
					tmp = strtok(cmdtext, idx);
					if(!strlen(tmp))
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /schowajmaterialy [iloœæ]");
						return 1;
					}
					new materialsdeposit = strval(tmp);
					if(!strlen(tmp))
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /schowajmaterialy [iloœæ]");
						return 1;
					}
					if(gPlayerData[playerid][pMaterials] >= materialsdeposit)
					{
						if(GetPlayerVirtualWorld(playerid) == i)
						{
							if(Houses[i][Materials] < 6000)
							{
								if(materialsdeposit < 6001)
								{
									gPlayerData[playerid][pMaterials] -= materialsdeposit;

									SavePlayerData(playerid, "Materials");

									Houses[i][Materials] += materialsdeposit;

									format(string, sizeof(string), "[INFO:] Schowa³eœ %d materia³ów w swoim sejfie, nowa iloœæ: %d ", materialsdeposit,Houses[i][Materials]);
									SendClientMessage(playerid, COLOR_WHITE, string);
									PlayerActionMessage(playerid, 15.0, "chowa materia³y");
									SaveHouseData(i, "Materials");
								}
								else
								{
									SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie mo¿esz schowaæ wiêcej ni¿ 6000 materia³ów!");
								}
							}
							else
							{
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Osi¹gn¹³eœ limit iloœci materia³ów w domu. (6000)");
							}
							return 1;
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie posiadasz tylu materia³ów !");
					}
				}
			}
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Musisz znajdowaæ siê w domu aby schowaæ materia³y");

			return 1;
		}
		if(strcmp(cmd, "/wezmaterialy", true) == 0)
		{
			for(new i = 0; i < sizeof(Houses); i++)
			{
				if(PlayerToPoint(15.0, playerid,Houses[i][ExitX], Houses[i][ExitY], Houses[i][ExitZ]) && i == GetPlayerVirtualWorld(playerid))
				{
					tmp = strtok(cmdtext, idx);
					if(!strlen(tmp))
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /wezmaterialy [iloœæ]");
						return 1;
					}
					new materialsdeposit = strval(tmp);
					if(!strlen(tmp))
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /wezmaterialy [iloœæ]");
						return 1;
					}
					if(Houses[i][Materials] >= materialsdeposit)
					{
						gPlayerData[playerid][pMaterials] -= materialsdeposit;

						SavePlayerData(playerid, "Materials");

						Houses[i][Materials]=Houses[i][Materials]-materialsdeposit;
						format(string, sizeof(string), "[INFO:] Wzi¹³eœ %d materia³ów ze swojego sejfu, nowa iloœæ: %d ", materialsdeposit,Houses[i][Materials]);
						SendClientMessage(playerid, COLOR_WHITE, string);
						PlayerActionMessage(playerid, 15.0, "wyjmuje materia³y");
						SaveHouseData(i, "Materials");
						return 1;
					}
					else
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie masz tyle materia³ów w swoim sejfie !");
					}
				}
			}
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Musisz znajdowaæ siê w domu aby pobraæ materia³y");

			return 1;
		}
		if(strcmp(cmd, "/engine", true) == 0 || strcmp(cmd, "/e", true) == 0)
		{
			if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
			{
				new enginedyn,lights,alarm,bonnet,boot,objective, doors;
				GetVehicleParamsEx(idcar, enginedyn, lights, alarm, doors, bonnet, boot, objective);
				
				if(AdminDuty[playerid])
				{
					if(gVehData[idcar-1][EngineOn] == 0)
					{
						StartEngine( playerid );
						return 1;
					}
					else
					{
						SetVehicleParamsEx(idcar,0,lights,alarm,doors,bonnet,boot,objective);
						gVehData[idcar-1][EngineOn] = 0;
						SaveVehData(tmpcar, "EngineOn");
						PlayerActionMessage(playerid,15.0, "zgasi³ silnik");
						return 1;
					}
				}
				if(gVehData[tmpcar][EngineOn] == 0)
				{
					if(EngineTurningOn[playerid] == 0)
					{
						if(gVehData[tmpcar][CarDamaged] == 0)
						{
							if(gVehData[tmpcar][CarRepairTimeLeft] == 0)
							{
								if( gVehData[tmpcar][EngineTemp] == 10 )
								{
									new Float:vehiclehp;
									GetVehicleHealth(tmpcar+1,vehiclehp);
									if( vehiclehp < 500.0 )
									{
										EngineTurningOn[playerid] = 1;
										PlayerActionMessage(playerid, 15.0, "uruchamia silnik");
										SendClientMessage( playerid, COLOR_ORANGE, "[STATUS:] Silnik jest przegrzany, nie mo¿esz go uruchomiæ" );
										EngineInfo(playerid);
										return 1;
									}
								}
								if( gVehData[tmpcar][BatteryCapacity] < 2.0 )
								{
									EngineTurningOn[playerid] = 1;
									PlayerActionMessage(playerid, 15.0, "uruchamia silnik");
									SendClientMessage( playerid, COLOR_ORANGE, "[STATUS:] S³aby akumulator, nie uda³o siê uruchomiæ silnika !" );
									EngineInfo(playerid);
									return 1;
								}
								if( PHaveItem(playerid, 2, gVehData[tmpcar][CarSerial]) > 0 )
								{
									StartEngine( playerid );
									return 1;
								}
								if( gPlayerData[playerid][pBizKey] == gVehData[tmpcar][BusinessID] && gVehData[tmpcar][Owned] == 0 )
								{
									StartEngine( playerid );
									return 1;
								}
								if(gVehData[tmpcar][FactionCar] == 255 )
								{
									if(gVehData[tmpcar][CarType] == 1 || gVehData[tmpcar][CarType] == 4 || gVehData[tmpcar][CarType] == 5 || gVehData[tmpcar][CarType] == 6 || gVehData[tmpcar][CarType] == 7|| gVehData[tmpcar][CarType] == 11)
									{
										StartEngine( playerid );
										return 1;
									}
									if(gVehData[tmpcar][CarType] == 2)
									{
										if(gPlayerData[playerid][pJob] == 13)
										{
											StartEngine( playerid );
											return 1;
										}
									}
									if(gVehData[tmpcar][CarType] == 3)
									{
										if(gPlayerData[playerid][pFaction] == 4)
										{
											StartEngine( playerid );
											return 1;
										}
									}
								}
								if(gVehData[tmpcar][FactionCar] != 255 )
								{
									if(gPlayerData[playerid][pFaction] == gVehData[tmpcar][FactionCar])
									{
										if( gVehData[tmpcar][CarType] == 0 )
										{
											if(gPlayerData[playerid][pDuty] == 0)
											{
												if(DynamicFactions[gVehData[tmpcar][FactionCar]][fType] == 1)
													SendClientMessage(playerid,COLOR_RED,"[INFO:] Nie jesteœ na s³u¿bie - nie posiadasz kluczy.");
												else
													SendClientMessage(playerid,COLOR_RED,"[INFO:] Nie posiadasz kluczy - mo¿esz je wzi¹œæ z przebieralni.");
												EngineTurningOn[playerid] = 1;
												EngineInfo(playerid);
												return 1;
											}
											if( gPlayerData[playerid][pDuty] )
											{
												if(gPlayerData[playerid][pRank] <= DynamicFactions[gPlayerData[playerid][pFaction]][fCarsRank])
												{
													EngineTurningOn[playerid] = 1;
													EngineInfo(playerid);
													SendClientMessage(playerid,COLOR_RED,"[INFO:] Musisz mieæ wy¿sz¹ range aby kierowaæ pojazdami policyjnymi.");
													return 1;
												}
												else
												{
													StartEngine( playerid );
													return 1;
												}												
											}
										}
									}
								}
								if(gPlayerData[playerid][pJob] == 10)
								{
									EngineTurningOn[playerid] = 1;
									SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[STATUS:] Brak kluczy - próba odpalenia silnika...");
									PlayerActionMessage(playerid, 15.0, "próbuje odpaliæ silnik");
									EngineNoKey(playerid);
									return 1;
								}
								else
								{
									SendClientMessage(playerid, COLOR_RED,"[STATUS:] Nie posiadasz kluczy do tego pojazdu.");
									EngineTurningOn[playerid] = 1;
									EngineInfo(playerid);
									return 1;
								}
							}
							else
							{
								EngineTurningOn[playerid] = 1;
								EngineInfo(playerid);
								SendClientMessage(playerid, COLOR_RED, "[INFO:] Pojazd jest naprawiany, nie mo¿esz go uruchomiæ");
								return 1;
							}
						}
						else
						{
							EngineTurningOn[playerid] = 1;
							EngineInfo(playerid);
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] Pojazd uszkodzony lub w trakcie napraw/wymiany opon, wezwij mechanika !");
							return 1;
						}
					}
					else
						print("BLAH12");
				}
				else if( gVehData[idcar-1][EngineOn] )
				{
					if(EngineTurningOn[playerid] == 0)
					{
						SetVehicleParamsEx(idcar,0,lights,alarm,doors,bonnet,boot,objective);
						gVehData[tmpcar][EngineOn] = 0;
						SaveVehData(tmpcar, "EngineOn");
						PlayerActionMessage(playerid,15.0, "zgasi³ silnik");
						return 1;
					}
				}
			}
			else
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] Nie jesteœ w samochodzie !");
			return 1;
		}
		if(strcmp(cmd, "/przekaz", true) == 0)
		{
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /przekaz [playerid/PartOName] [kwota]");
				return 1;
			}
			//giveplayerid = strval(tmp);
			giveplayerid = ReturnUser(tmp);
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /przekaz [playerid/PartOName] [kwota]");
				return 1;
			}
			new moneys,playermoney;
			moneys = strval(tmp);
			if(gTransferCoolDown[playerid] > 0)
			{
				format(string, sizeof(string), "[INFO:] Musisz jeszcze odczekaæ %d sekund przed kolejnym przekazem !", gTransferCoolDown[playerid]);
				SendClientMessage(playerid, COLOR_ORANGE, string);
				return 1;
			}
			if(gPlayerData[playerid][pAdmin] < 1)
			{
				if(moneys > 1000 && gPlayerData[playerid][pLevel] < 5)
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Wymagany jest 5 poziom aby dokonywaæ przekazów wiêkszych ni¿ $1000");
					return 1;
				}
			}
			if(moneys < 1 || moneys > 99999)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Niew³aœciwa kwota");
				return 1;
			}
			if (IsPlayerConnected(giveplayerid))
			{
				if(giveplayerid != INVALID_PLAYER_ID)
				{
					if(gPlayerData[playerid][pAdmin] < 1)
					{
						if(moneys > 1000 && gPlayerData[giveplayerid][pLevel] < 5)
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Wymagany jest przynajmniej 5 poziom gracza, któremu przekazujesz kase aby dokonywaæ przekazów wiêkszych ni¿ $1000");
							return 1;
						}
					}
					if (ProxDetectorS(5.0, playerid, giveplayerid))
					{
						if(giveplayerid != playerid)
						{
							playermoney = GetPlayerCash(playerid);
							if (moneys > 0 && playermoney >= moneys)
							{
								gTransferCoolDown[playerid] = 60;
								GivePlayerCash(playerid, - moneys);
								GivePlayerCash(giveplayerid, moneys);
								format(string, sizeof(string), "[INFO:] %d$ przekazane %s [%d]", moneys, GetPlayerNameEx(giveplayerid), giveplayerid);
								PlayerPlaySound(playerid, 1052, 0.0, 0.0, 0.0);
								SendClientMessage(playerid, COLOR_WHITE, string);
								format(string, sizeof(string), "[INFO:] %s (ID:%d) przekaza³ Tobie $%d.",GetPlayerNameEx(playerid), playerid, moneys);
								SendClientMessage(giveplayerid, COLOR_WHITE, string);
								format(string, sizeof(string), "[CASH:] %s transfered cash value of %d$ to %s", gPlayerData[playerid][pName], moneys, gPlayerData[giveplayerid][pName]);
								PayLog(string);
								format(string, sizeof(string), "[INFO:] Gracz %s [%d] przekaza³ kase graczowi %s [%d], kwota: %d$",
								gPlayerData[playerid][pName], playerid, gPlayerData[giveplayerid][pName], giveplayerid, moneys);
								ABroadCast(COLOR_YELLOW, string, 1);
								PlayerPlaySound(giveplayerid, 1052, 0.0, 0.0, 0.0);
							}
							else
							{
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Niew³aœciwa kwota.");
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie mo¿esz sam sobie przekazaæ pieniêdzy !");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Jesteœ za daleko od tej osoby.");
					}
				}//invalid id
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Niew³aœciwe ID.");
			}
			return 1;
		}
		if(strcmp(cmd,"/licencje",true)==0)
		{
			if(IsPlayerConnected(playerid))
			{
				new text1[20];
				new text2[20];
				new text3[20];
				new text4[20];
				if(gPlayerData[playerid][pCarLic]) { text1 = "Tak"; } else { text1 = "Nie"; }
				if(gPlayerData[playerid][pFlyLic]) { text2 = "Tak"; } else { text2 = "Nie"; }
				if(gPlayerData[playerid][pWepLic]) { text3 = "Tak"; } else { text3 = "Nie"; }
				if(gPlayerData[playerid][pBoatLic]) { text4 = "Tak"; } else { text4 = "Nie"; }

				SendClientMessage(playerid, COLOR_LIGHTGREEN, "----------------------[LICENCJE:]----------------------");
				format(string, sizeof(string), "** Prawo jazdy: %s - Licencja na ³odzie: %s - Licencja pilota: %s - Licencja na broñ: %s.", text1,text4,text2,text3);
				SendClientMessage(playerid, COLOR_WHITE, string);
				SendClientMessage(playerid, COLOR_LIGHTGREEN, "---------------------------------------------------------");
				PlayerActionMessage(playerid, 15.0, "wyjmuje dokumenty i sprawdza swoje dokumenty");
			}
			return 1;
		}
		if(strcmp(cmd,"/skile",true)==0)
		{
			if(IsPlayerConnected(playerid))
			{
			//new string[128];
			new Pis = gPlayerData[playerid][pSkillLevPis];
			new Sil = gPlayerData[playerid][pSkillLevSil];
			new Des = gPlayerData[playerid][pSkillLevDes];
			new Sho = gPlayerData[playerid][pSkillLevSho];
			new Sha = gPlayerData[playerid][pSkillLevSha];
			new Spa = gPlayerData[playerid][pSkillLevSpa];
			new Mic = gPlayerData[playerid][pSkillLevMic];
			new Mp5 = gPlayerData[playerid][pSkillLevMp5];
			new Ak = gPlayerData[playerid][pSkillLevAk];
			new M4 = gPlayerData[playerid][pSkillLevM4];
			new Sni = gPlayerData[playerid][pSkillLevSni];
			new pPis = gPlayerData[playerid][pSkillPointsPis];
			new pSil = gPlayerData[playerid][pSkillPointsSil];
			new pDes = gPlayerData[playerid][pSkillPointsDes];
			new pSho = gPlayerData[playerid][pSkillPointsSho];
			new pSha = gPlayerData[playerid][pSkillPointsSha];
			new pSpa = gPlayerData[playerid][pSkillPointsSpa];
			new pMic = gPlayerData[playerid][pSkillPointsMic];
			new pMp5 = gPlayerData[playerid][pSkillPointsMp5];
			new pAk = gPlayerData[playerid][pSkillPointsAk];
			new pM4 = gPlayerData[playerid][pSkillPointsM4];
			new pSni = gPlayerData[playerid][pSkillPointsSni];
			new Ang = gPlayerData[playerid][pAng];
			new Wf = gPlayerData[playerid][pWf];
			new Mat = gPlayerData[playerid][pMat];
			new Pol = gPlayerData[playerid][pPol];
			new His = gPlayerData[playerid][pHis];
			new Fiz = gPlayerData[playerid][pFiz];
			new Bio = gPlayerData[playerid][pBio];
			new ppAng = gPlayerData[playerid][pPktAng];
			new ppWf = gPlayerData[playerid][pPktWf];
			new ppMat = gPlayerData[playerid][pPktMat];
			new ppPol = gPlayerData[playerid][pPktPol];
			new ppHis = gPlayerData[playerid][pPktHis];
			new ppFiz = gPlayerData[playerid][pPktFiz];
			new ppBio = gPlayerData[playerid][pPktBio];
			SendClientMessage(playerid, COLOR_LIGHTGREEN, "----------------------[Umiejetnosci:]----------------------");
			format(string, sizeof(string), "[Poziomy:] Pis: %d - Sil: %d - Des: %d - Sho: %d - Sha: %d - Spa: %d",Pis,Sil,Des,Sho,Sha,Spa);
			SendClientMessage(playerid,COLOR_LIGHTORANGE, string);
			format(string, sizeof(string), "[Punkty:] Pis: %d - Sil: %d - Des: %d - Sho: %d - Sha: %d - Spa: %d",pPis,pSil,pDes,pSho,pSha,pSpa);
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2, string);
			format(string, sizeof(string), "[Poziomy:] Mic: %d - Mp5: %d - Ak: %d - M4: %d - Sni: %d",Mic,Mp5,Ak,M4,Sni);
			SendClientMessage(playerid,COLOR_LIGHTORANGE, string);
			format(string, sizeof(string), "[Punkty:] Mic: %d - Mp5: %d - Ak: %d - M4: %d - Sni: %d",pMic,pMp5,pAk,pM4,pSni);
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2, string);
			format(string, sizeof(string), "[Poziomy:] Ang: %d - WF: %d - Mat: %d - Pol: %d - His: %d - Fiz: %d - Bio: %d",Ang,Wf,Mat,Pol,His,Fiz,Bio);
			SendClientMessage(playerid,COLOR_LIGHTORANGE, string);
			format(string, sizeof(string), "[Punkty:] Ang: %d - WF: %d - Mat: %d - Pol: %d - His: %d - Fiz: %d - Bio: %d",ppAng,ppWf,ppMat,ppPol,ppHis,ppFiz,ppBio);
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2, string);
			SendClientMessage(playerid, COLOR_LIGHTGREEN, "-----------------------------------------------------------");
			}
			return 1;
		}
		if(strcmp(cmd,"/pokazid",true)==0)
		{
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /pokazid [playerid/PartOName]");
				return 1;
			}
			giveplayerid = ReturnUser(tmp);
			
			if(IsPlayerConnected(giveplayerid))
			{
				new slotid = PHaveItem(playerid, 3, 5);
				if(slotid > 0)
				{
					new name[64];
					strins(name, gPlayerData[playerid][pName], 0, 64);
					if(strcmp(name, gPlayerData[playerid][pName], false) != 0)
					{
						SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] To nie jest twój dowód ! Nie mo¿esz siê nim pos³ugiwaæ");
						return 1;
					}
					if(giveplayerid != INVALID_PLAYER_ID)
					{
						if (ProxDetectorS(8.0, playerid, giveplayerid))
						{
							new text1[20];
							new text2[20];
							new text3[20];
							new text4[20];
							if(gPlayerData[playerid][pCarLic]) { text1 = "Tak"; } else { text1 = "Nie"; }
							if(gPlayerData[playerid][pFlyLic]) { text2 = "Tak"; } else { text2 = "Nie"; }
							if(gPlayerData[playerid][pWepLic]) { text3 = "Tak"; } else { text3 = "Nie"; }
							if(gPlayerData[playerid][pBoatLic]) { text4 = "Tak"; } else { text4 = "Nie"; }
							SendClientMessage(giveplayerid,COLOR_LIGHTGREEN,"-----------[SAN ANDREAS ID:]---------");
							format(string, sizeof(string), "Nick: %s.", GetPlayerNameEx(playerid));
							SendClientMessage(giveplayerid, COLOR_WHITE, string);
							format(string, sizeof(string), "Wiek: %d.  P³eæ: %d", gPlayerData[playerid][pAge], gPlayerData[playerid][pSex]);
							SendClientMessage(giveplayerid, COLOR_WHITE, string);
							if(gPlayerData[playerid][pBizKey] != 255 && strcmp(PlayerName(playerid), Businesses[gPlayerData[playerid][pBizKey]][Owner], true) == 0)
							{
								format(string, sizeof(string), "Biznes: %s.", Businesses[gPlayerData[playerid][pBizKey]][BusinessName]);
								SendClientMessage(giveplayerid, COLOR_WHITE, string);
							}
							else
							{
								SendClientMessage(giveplayerid, COLOR_WHITE, "Biznes: brak.");
							}
							format(string, sizeof(string), "** Prawo jazdy: %s - Licencja na ³odzie: %s - Licencja pilota: %s - Licencja na broñ: %s.", text1,text4,text2,text3);
							SendClientMessage(giveplayerid, COLOR_WHITE, string);
							SendClientMessage(giveplayerid, COLOR_LIGHTGREEN, "--------------------------------------------");
							format(string, sizeof(string), "[INFO:] Pokaza³eœ swoje dane: %s.", GetPlayerNameEx(giveplayerid));
							SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
							return 1;
						}
						else
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Ten gracz nie jest wystarczaj¹co blisko!");
							return 1;
						}
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "Nie posiadasz dowodu osobistego");
					return 1;
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Niew³aœciwe ID.");
				return 1;
			}
		}
		if(strcmp(cmd, "/oocstatus", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 1)
				return 0;
			if(OOCStatus)
			{
				OOCStatus = 0;
				format(string, sizeof(string), "[GLOBALNE OOC:] Wy³¹czony przez %s.", GetPlayerNameEx(playerid));
				SendClientMessageToAll(COLOR_ADMINCMD, string);
			}
			if(gPlayerData[playerid][pMuted] == 1)
			{
			SendClientMessage(playerid, COLOR_GREY, "[INFO:] Jesteœ zbanowany z tego chatu.");
			return 1;
			}
			else
			{
				OOCStatus = 1;
				format(string, sizeof(string), "[GLOBALNE OOC:] W³¹czony przez %s.", GetPlayerNameEx(playerid));
				SendClientMessageToAll(COLOR_ADMINCMD, string);
			}
			return 1;
		}
		if(strcmp(cmd, "/wyrobdowod", true) == 0)
		{
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /wyrobdowod [playerid]");
				return 1;
			}
			new playa;
			playa = ReturnUser(tmp);
			tmp = strtok(cmdtext, idx);
			if(gPlayerData[playerid][pFaction] == 9 || AdminDuty[playerid])
			{
				if(!IsPlayerConnected(playa) && !gPlayerLogged[playa])
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Gracz nie jest on-line");
					return 1;
				}
				if(InsertPlayerItemEx(playa, 3, 5, 0, 0, 0, 0, gPlayerData[playerid][pName]) > 0)
				{
					format(string, sizeof(string), "[INFO:] Dowód zosta³ wyrobiony przez %s !", gPlayerData[playerid][pName]);

					SendClientMessage(playerid, COLOR_LIGHTYELLOW2,string);
					SendClientMessage(playa, COLOR_GREEN, "[INFO:] Otrzyma³eœ dowód osobisty");
				}
				else
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ta osoba nie ma miejsca na dowód");
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_RED, "[B£¥D:] Nie jesteœ urzêdnikiem.");
			}
			
			format(string, sizeof(string), "[GOVERNMENT:] Identity maked by: %s for %s", gPlayerData[playerid][pName], gPlayerData[playa][pName]);
			return 1;
		}
		if(strcmp(cmd, "/id", true) == 0)
		{
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /id [playerid/PartOName]");
				return 1;
			}
			new target;
			target = ReturnUser(tmp);
			new sstring[256];
			if(IsPlayerConnected(target))
			{
				if(target != INVALID_PLAYER_ID)
				{
					format(sstring, sizeof(sstring), "[INFO:] Nick: %s (ID: %d).",GetPlayerNameEx(target),target);
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, sstring);
				}
			}
			return 1;
		}
		if(strcmp(cmd, "/zamknij", true) == 0)
		{
			if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
			{
				if((PHaveItem(playerid, 2, gVehData[tmpcar][CarSerial]) != 0 && gVehData[tmpcar][FactionCar] == 255) || (gVehData[tmpcar][FactionCar] == gPlayerData[playerid][pFaction]) && gPlayerData[playerid][pDuty])
				{
					if(gVehData[tmpcar][Closed] == 0)
					{
						if(!IsABike(idcar) && !IsAMotorBike(idcar))
						{
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] Zamkn¹³eœ swój pojazd.");
							PlayerActionMessage(playerid,15.0, "wyjmuje kluczyki i zamyka pojazd");

							gVehData[tmpcar][Closed] = 1;
							new enginedyn,lights,alarm,doors,bonnet,boot,objective;
							GetVehicleParamsEx(idcar,enginedyn,lights,alarm,doors,bonnet,boot,objective);
							SetVehicleParamsEx(idcar,enginedyn,lights,alarm,1,bonnet,boot,objective);
						}
						if(IsABike(idcar))
						{
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] Zapi¹³eœ swój rower.");
							PlayerActionMessage(playerid,15.0, "wyjmuje kluczyki i zapina zapiêcie");

							gVehData[tmpcar][Closed] = 1;
							/*new enginedyn,lights,alarm,doors,bonnet,boot,objective;
							GetVehicleParamsEx(idcar,enginedyn,lights,alarm,doors,bonnet,boot,objective);
							SetVehicleParamsEx(idcar,enginedyn,lights,alarm,1,bonnet,boot,objective);*/
						}

						SaveVehData(tmpcar, "Closed");
						return 1;
					}
				}
				else if(gVehData[tmpcar][FactionCar] != 255)
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten pojazd nale¿y do frakcji. Nie mo¿esz go zamkn¹æ.");
					return 1;
				}
				else if(PHaveItem(playerid, 2, gVehData[tmpcar][CarSerial]) == 0  && gVehData[tmpcar][FactionCar] == 255)
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie posiadasz kluczy do tego pojazdu, nie mo¿esz go zamkn¹æ.");
					return 1;
				}
				return 1;
			}
			else if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
			{
				new Float:x,Float:y,Float:z;
				for(new i = 0; i < sizeof(gVehData); i++)
				{
					if(gVehData[i][Closed] == 1)
					{
						GetVehiclePos(i+1, x, y, z);
						if(PlayerToPoint(5.0,playerid,x,y,z))
						{
							if(PHaveItem(playerid, 2, gVehData[i][CarSerial]) || gVehData[i][FactionCar] == gPlayerData[playerid][pFaction] && gPlayerData[playerid][pDuty])
							{
								if(!IsABike(i+1) && !IsAMotorBike(i+1))
								{
									SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] Pojazd zosta³ otworzony.");
									PlayerActionMessage(playerid,15.0, "wyjmuje kluczyki i otwiera pojazd");
									new enginedyn,lights,alarm,doors,bonnet,boot,objective;
									GetVehicleParamsEx(i+1,enginedyn,lights,alarm,doors,bonnet,boot,objective);
									SetVehicleParamsEx(i+1,enginedyn,lights,alarm,0,bonnet,boot,objective);
								}
								if(IsABike(i+1))
								{
									SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] Zapiêcie rozpiête.");
									PlayerActionMessage(playerid,15.0, "wyjmuje kluczyki i rozpina zapiêcie");
								}

								gVehData[i][Closed] = 0;

								SaveVehData(i, "Closed");
								
								
								return 1;
							}
						}
					}
				}
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] Nie jesteœ w pobli¿u swojego wozu !");

				return 1;
			}
			return 1;
		}
		if(strcmp(cmd,"/resetanimacji",true)==0)
		{
			if(gPlayerData[playerid][pCharacterDying] == 0)
			{
				ClearAnimations(playerid);
			}
			else
			{
				SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie mo¿esz u¿yæ tej komendy w przypadku umieraj¹cej postaci !");
			}
			return 1;
		}
		/*if(strcmp(cmd, "/low", true) == 0)
		{
			if(IsPlayerConnected(playerid))
			{
				new length = strlen(cmdtext);
				while ((idx < length) && (cmdtext[idx] <= ' '))
				{
					idx++;
				}
				new offset = idx;
				new result[128];
				while ((idx < length) && ((idx - offset) < (sizeof(result) - 1)))
				{
					result[idx - offset] = cmdtext[idx];
					idx++;
				}
				result[idx - offset] = EOS;
				if(!strlen(result))
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /low [message]");
					return 1;
				}
				format(string, sizeof(string), "[LOW:] %s says: %s", GetPlayerNameEx(playerid), result);
				ProxDetector(3.0, playerid, string,COLOR_FADE1,COLOR_FADE2,COLOR_FADE3,COLOR_FADE4,COLOR_FADE5);
			}
			return 1;
		}
		if(strcmp(cmd, "/local", true) == 0)
		{
			if(IsPlayerConnected(playerid))
			{
				new length = strlen(cmdtext);
				while ((idx < length) && (cmdtext[idx] <= ' '))
				{
					idx++;
				}
				new offset = idx;
				new result[128];
				while ((idx < length) && ((idx - offset) < (sizeof(result) - 1)))
				{
					result[idx - offset] = cmdtext[idx];
					idx++;
				}
				result[idx - offset] = EOS;
				if(!strlen(result))
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /local [message]");
					return 1;
				}
				format(string, sizeof(string), "%s says: %s", GetPlayerNameEx(playerid), result);
				ProxDetector(3.0, playerid, string,COLOR_FADE1,COLOR_FADE2,COLOR_FADE3,COLOR_FADE4,COLOR_FADE5);
			}
			return 1;
		}
		if(strcmp(cmd, "/shout", true) == 0)
		{
			if(IsPlayerConnected(playerid))
			{
				new length = strlen(cmdtext);
				while ((idx < length) && (cmdtext[idx] <= ' '))
				{
					idx++;
				}
				new offset = idx;
				new result[128];
				while ((idx < length) && ((idx - offset) < (sizeof(result) - 1)))
				{
					result[idx - offset] = cmdtext[idx];
					idx++;
				}
				result[idx - offset] = EOS;
				if(!strlen(result))
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /shout [message]");
					return 1;
				}
				format(string, sizeof(string), "%s shouts: %s!!!", GetPlayerNameEx(playerid), result);
				ProxDetector(3.0, playerid, string,COLOR_FADE1,COLOR_FADE2,COLOR_FADE3,COLOR_FADE4,COLOR_FADE5);
			}
			return 1;
		}
		if(strcmp(cmd, "/whisper", true) == 0)
		{
			if(IsPlayerConnected(playerid))
			{
				tmp = strtok(cmdtext, idx);
				if(!strlen(tmp))
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /whisper [playerid] [message]");
					return 1;
				}
				giveplayerid = ReturnUser(tmp);
				if (IsPlayerConnected(giveplayerid))
				{
					if(giveplayerid != INVALID_PLAYER_ID)
					{
						new length = strlen(cmdtext);
						while ((idx < length) && (cmdtext[idx] <= ' '))
						{
							idx++;
						}
						new offset = idx;
						new result[128];
						while ((idx < length) && ((idx - offset) < (sizeof(result) - 1)))
						{
							result[idx - offset] = cmdtext[idx];
							idx++;
						}
						result[idx - offset] = EOS;
						if(!strlen(result))
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /whisper [playerid] [message]");
							return 1;
						}
						if (ProxDetectorS(3.0, playerid, giveplayerid))
						{
							if(giveplayerid != playerid)
							{
								format(string, sizeof(string), "%s whispers: %s", GetPlayerNameEx(playerid), result);
								SendClientMessage(giveplayerid, COLOR_YELLOW, string);
								SendClientMessage(playerid, COLOR_YELLOW, string);
								PlayerActionMessage(playerid,5.0,"whispers something.");
							}
							else
							{
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] You cant whisper yourself.");
							}

						}
						else
						{
								SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] You are not close enough.");
						}
						return 1;
					}
				}
				else
				{
						format(string, sizeof(string), "[B£¥D:] No player with the ID %d is connected.", strval(tmp));
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
				}
			}
			return 1;
		}*/
		if(strcmp(cmd, "/sledz", true) == 0)
		{
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /sledz [playerid]");
				return 1;
			}
			if(TrackingPlayer[playerid] == 1)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Ju¿ kogoœ œledzisz.");
				return 1;
			}
			new id = strval(tmp);
			if( !PHaveItem( id, 3, 3 ) )
			{
				SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Ta osoba nie posiada telefonu który móg³byœ wyœledziæ" );
				return 1;
			}
			if( SlotParam1( id, PHaveItem( id, 3, 3 ) ) == 0 )
			{
				SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Ta osoba ma wy³¹czony telefon !" );
				return 1;
			}
			if (gPlayerData[playerid][pJob] == 3)
			{
				if(IsPlayerConnected(id))
				{
					if(playerid != id)
					{
						if(id != INVALID_PLAYER_ID)
						{
							format(string, sizeof(string), "[INFO:] Œledzisz %s, punkt zostanie usuniêty w ci¹gu 60 sekund.", GetPlayerNameEx(id));
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
							new Float:x,Float:y,Float:z;
							GetPlayerPos(id,x,y,z);
							SetPlayerCheckpoint(playerid,x+float(random(400)-200),y+float(random(400)-200),z,10.0);
							ClearCheckpointsForPlayer(playerid);
							TrackingPlayer[playerid] = 1;
						}
					}
					else
					{
						SendClientMessage(id, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie mo¿esz œledziæ samego siebie.");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Niew³aœciwe ID.");
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie jesteœ detektywem !");
			}
			return 1;
		}
		if(strcmp(cmd, "/sledzpojazd", true) == 0)
		{
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /sledzpojazd [nr rejestracyjny]");
				return 1;
			}
			if(TrackingCar[playerid] == 1)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Ju¿ œledzisz inny pojazd.");
				return 1;
			}
			new id;
			new serial = strval(tmp);
			id = CarSerialToID(serial);
			if (gPlayerData[playerid][pJob] == 3)
			{
				if(id < sizeof(gVehData) && id != -1)
				{
					format(string, sizeof(string), "[INFO:] Œledzisz pojazd o rejestracji: %d, punkt zostanie usuniêty w ci¹gu 60 sekund.", serial);
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
					new Float:x,Float:y,Float:z;
					GetVehiclePos(id+1,x,y,z);
					SetPlayerCheckpoint(playerid,x+float(random(320)-160),y+float(random(320)-160),z,100.0);
					ClearCheckpointsForPlayer(playerid);
					TrackingCar[playerid] = 1;
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie znaleziono pojazdu o takiej rejestracji");
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie jesteœ detektywem !");
			}
			return 1;
		}
		if(strcmp(cmd, "/adonator", true) == 0)
		{
			if(IsPlayerConnected(playerid))
			{
				tmp = strtok(cmdtext, idx);
				if(!strlen(tmp))
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /adonator [playerid]");
					return 1;
				}
				new id = strval(tmp);
				if (gPlayerData[playerid][pAdmin] >= 5)
				{
					if(IsPlayerConnected(id))
					{
						if(id != INVALID_PLAYER_ID)
						{
							if(gPlayerData[id][pDonator] == 1)
							{
								format(string, sizeof(string), "[INFO:] Twój status sponsora zosta³ odebrany przez: %s.", GetPlayerNameEx(playerid));
								SendClientMessage(id, COLOR_ADMINCMD, string);
								DonatorLog(string);
								format(string, sizeof(string), "[INFO:] Usunê³eœ status sponsora %s.", GetPlayerNameEx(id));
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								gPlayerData[id][pDonator] = 0;

								SavePlayerData(id, "Donator");
							}
							else
							{
								format(string, sizeof(string), "[INFO:] Zosta³eœ mianowany na sponsora przez: %s.", GetPlayerNameEx(playerid));
								SendClientMessage(id, COLOR_ADMINCMD, string);
								DonatorLog(string);
								format(string, sizeof(string), "[INFO:] Mianowa³eœ sponsora %s.", GetPlayerNameEx(id));
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								gPlayerData[id][pDonator] = 1;

								SavePlayerData(id, "Donator");
							}
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Niew³aœæiwe ID.");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "Nie jesteœ administratorem.");
				}
			}
			return 1;
		}
		if(strcmp(cmd, "/donatorcmds", true) == 0)
		{
			if(gPlayerData[playerid][pDonator] == 1)
			{
				SendClientMessage(playerid,COLOR_YELLOW,"____________________________________________________");
				SendClientMessage(playerid,COLOR_WHITE,"[Donator:] /onoff pw - /onoff telefon - ");
				SendClientMessage(playerid,COLOR_YELLOW,"____________________________________________________");
			}
			else
			{
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] Nie jesteœ sponsorem !");
			}
			return 1;
		}
		if(strcmp(cmd, "/podejrzany", true) == 0 || strcmp(cmd, "/p", true) == 0)
		{
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /podejrzany [playerid] [zbrodnia]");
				return 1;
			}
			giveplayerid = ReturnUser(tmp);
			if (gPlayerData[playerid][pFaction] != 255 && DynamicFactions[gPlayerData[playerid][pFaction]][fType] == 1)
			{
				if(IsPlayerConnected(giveplayerid))
				{
					if(giveplayerid != INVALID_PLAYER_ID)
					{
						new length = strlen(cmdtext);
						while ((idx < length) && (cmdtext[idx] <= ' '))
						{
							idx++;
						}
						new offset = idx;
						new result[128];
						while ((idx < length) && ((idx - offset) < (sizeof(result) - 1)))
						{
							result[idx - offset] = cmdtext[idx];
							idx++;
						}
						result[idx - offset] = EOS;
						if(!strlen(result))
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /podejrzany [playerid] [zbrodnia]");
							return 1;
						}
						if(gPlayerData[playerid][pDuty])
						{
							if(giveplayerid != playerid)
							{
								SetPlayerWantedLevelEx(giveplayerid,GetPlayerWantedLevel(giveplayerid)+1);
								gPlayerData[giveplayerid][pWantedLvl]++;
								SavePlayerData(giveplayerid, "WantedLvl");
								foreach(Player, i )
								{
									if(!BigEar[i])
									{
										if(gPlayerData[i][pFaction] < sizeof(DynamicFactions))
										{
											if(DynamicFactions[gPlayerData[i][pFaction]][fType] == 1)
											{
												PlayCrimeReportForPlayer(i, giveplayerid, 4);
											}
										}
									}
									else
									{
										PlayCrimeReportForPlayer(i, giveplayerid, 4);
									}
								}
								new Year, Month, Day;
								getdate(Year, Month, Day);
								format(string, sizeof(string), "INSERT INTO `samp_wanted` (`PlayerName` , `Description` , `CommitedDay` , `CommitedMonth` , `CommitedYear`) VALUES ('%s' , '%s' , '%d' , '%d' , '%d')", gPlayerData[giveplayerid][pName], result, Day, Month, Year);
								mysql_query(string, SAVE, giveplayerid, db_con2);
								
								format(string, sizeof(string), "[INFO:] Zosta³eœ uznany za poszukiwanego %s, Powód: %s.", GetPlayerNameEx(playerid),result);
								SendClientMessage(giveplayerid, COLOR_RED, string);
								format(string, sizeof(string), "[INFO:] Uzna³eœ %s za podejrzanego, Powód: %s.", GetPlayerNameEx(giveplayerid),result);
								SendClientMessage(playerid, COLOR_WHITE, string);
								format(string, sizeof(string), "[SFPD:] %s uzna³ za podejrzanego %s, Powód: %s.", GetPlayerNameEx(playerid),GetPlayerNameEx(giveplayerid),result);
								SendFactionTypeMessage(1,COLOR_LSPD,string);
								new location[MAX_ZONE_NAME];
								GetPlayer2DZone(giveplayerid, location, MAX_ZONE_NAME);
								format(string, sizeof(string), "[SFPD:] Do wszystkich jednostek, nowy poszukiwany %s - widziany ostatnio: %s.", GetPlayerNameEx(giveplayerid),location);
								SendFactionTypeMessage(1,COLOR_LSPD,string);
							}
							else
							{
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie mo¿esz u¿yæ tej funkcji na sobie !");
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie jesteœ na s³u¿bie !");
						}
						return 1;
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] B³êdne ID");
					return 1;
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Niew³aœciwa frakcja.");
				return 1;
			}
			return 1;
		}
		/*if(strcmp(cmd, "/wi", true) == 0)
		{
			if(IsPlayerInAnyVehicle(playerid))
			{
				if(IsABike(GetPlayeridcar(playerid)))
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Bikes don't have windows.");
					return 1;
				}
				if(CarWindowStatus[GetPlayeridcar(playerid)] == 1)
				{
					if(gPlayerData[playerid][pSex] == 1)
					{
						PlayerActionMessage(playerid,15.0,"has just rolled the windows down in his vehicle.");
					}
					else
					{
						PlayerActionMessage(playerid,15.0,"has just rolled the windows down in her vehicle.");
					}
					CarWindowStatus[GetPlayeridcar(playerid)] = 0;
				}
				else if(CarWindowStatus[GetPlayeridcar(playerid)] == 0)
				{
					if(gPlayerData[playerid][pSex] == 1)
					{
						PlayerActionMessage(playerid,15.0,"has just rolled up the windows in his vehicle.");
					}
					else
					{
						PlayerActionMessage(playerid,15.0,"has just rolled up the windows in her vehicle.");
					}
					CarWindowStatus[GetPlayeridcar(playerid)] = 1;
				}
			}
			else
			{
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] Your not in a vehicle!");
			}
			return 1;
		}*/
		if(strcmp(cmd, "/admincmds1", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] > 0)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2,"================================================================================================================================");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "==[ADMIN:] /aplayercmds - /achatcmds - /afactioncmds - /avehcmds - /abuildingcmds - /ahousecmds - /abusinesscmds - /agotocmds");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "==[ADMIN:] /afactorylegalcmds - /afactorycmds - /ajobscmds - /rafinerycmds - /aservercmds  - /aothercmds - /itemfactorycmds");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2,"[ADMIN:] /snews - /respawnthiscar(/rtc) - /update - /setstartspawn - /setstartmoney - /setstartbank - /setstartskin");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2,"[Admin:] /setint - /acceptreport - /abankpos - /aweaponlicensepos - /aflyingtestpos - /adrivingtestpos");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2,"[Admin:] /usunraport - /fly - /name - /supervehslap - /lotterycash - /wheelchangepos");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2,"[Admin:] /asetleader - /agotobiz - /abusinessprudcts - /abizprice");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2,"================================================================================================================================");
			}
			return 1;
		}
		if(strcmp(cmd, "/admincmds2", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] > 0)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2,"================================================================================================================================");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2,"[Admin:] /abuildingopent - /abuildingcloset - /amechanicrepairpoint - /amechanicjobpos - /arepairallvehicles - / - /");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2,"[Admin:] /acarparkdefault - /acarparkdynamic - /acarsreset - /ahousesreset - /abizreset - /acarmodelprice - /");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2,"[Admin:] /fixdamage - /resetpracy - / - / - / - / - /");
    			SendClientMessage(playerid, COLOR_LIGHTYELLOW2,"[Admin:] / - / - / - / - / - / - /");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2,"================================================================================================================================");
			}
			return 1;
		}
		if(strcmp(cmd, "/komendypolicji", true) == 0)
		{
			if(gPlayerData[playerid][pFaction] != 255 && DynamicFactions[gPlayerData[playerid][pFaction]][fType] == 1)
			{
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"(/f)rakcja - /sluzba - (/p)odejrzany - (/r)adio - (/m)egafon - /aresztuj - /wanted(ex) - /skuj - /rozkuj - /rewiduj");
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"/paralizuj - /skonfiskuj - /mandat - /kody - /zaciagnij - /ww (wezwij wsparcie) - /sprawdzpasy");
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"/ozomo0 - /ozomo1 - /ozomo2 - /sprawdznumer - /kolczatka - /zwinkolczatke - /wlascicielpoj");

			}
			else
			{
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] Niew³aœciwa frakcja.");
			}
			return 1;
		}
		if(strcmp(cmd, "/komendyurzedu", true) == 0)
		{
			if(gPlayerData[playerid][pFaction] == FACTIONID_GOVERNMENT)
			{
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"/ustawdom - /wnetrzedomu - /sprzedajdom - /cenadomu - /opisdomu");
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"/wnetrzebudynku - /wejsciebudynku - /nazwabudynku - /cenazalitr");
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"/ustawbiz - /cenabiz - /typbiz - /wnetrzebiz - /sprzedajbiz");
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"/resetpktbroni - /dajpozwolenie - /dajbron - /odbierzbron - /sprawdzbron");				
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"/umowaoc - /umowaac - /wyplacodszkodowanieoc - /wyplacodszkodowanieac");
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"/news - /wyrobdowod - /podatki1 - /podatki2 - /wynajmijkomornika - /zmost - /omost - /zslums - /oslums");
			}
			else
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] Niew³aœciwa frakcja.");
			return 1;
		}
		if(strcmp(cmd, "/komendymedykow", true) == 0)
		{
			if(gPlayerData[playerid][pFaction] != 255 && gPlayerData[playerid][pFaction] == 2)
			{
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"/ulecz - /pozszywaj - /reanimuj - /detoksykacja - / - / ");
			}
			else
			{
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] Niew³aœciwa frakcja.");
			}
			return 1;
		}
		if(strcmp(cmd, "/wezprace", true) == 0)
		{
			if(gPlayerData[playerid][pJob] == 0)
			{
				if(PlayerToPoint(1.0, playerid,GunJob[TakeJobX],GunJob[TakeJobY],GunJob[TakeJobZ]))
				{
					if(GetPlayerVirtualWorld(playerid) == GunJob[TakeJobWorld])
					{
						SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[SUKCES:] Jesteœ teraz dilerem broni, wpisz /komendypracy.");
						gPlayerData[playerid][pJob] = 1; //Gun Job

						SavePlayerData(playerid, "Job");
					}
				}
				else if(PlayerToPoint(1.0, playerid,DrugJob[TakeJobX],DrugJob[TakeJobY],DrugJob[TakeJobZ]))
				{
					if(GetPlayerVirtualWorld(playerid) == DrugJob[TakeJobWorld])
					{
						SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[SUKCES:] Jesteœ teraz dilerem narkotyków, wpisz /komendypracy.");
						gPlayerData[playerid][pJob] = 2; //Drug Job

						SavePlayerData(playerid, "Job");
					}
				}
				else if(PlayerToPoint(1.0, playerid,DetectiveJobPosition[X],DetectiveJobPosition[Y],DetectiveJobPosition[Z]))
				{
					// if(GetPlayerVirtualWorld(playerid) == DetectiveJobPosition[World])
					// {
						if(gPlayerData[playerid][pWf] < 2 || gPlayerData[playerid][pMat] < 4)
						{
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] Do tej pracy wymagany jest przynajmniej 2 poziom WFu oraz 4 poziom matematyki");
						}
						else
						{
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[SUKCES:] Jesteœ teraz detektywem, wpisz /komendypracy.");
							gPlayerData[playerid][pJob] = 3; //Detective Job

							SavePlayerData(playerid, "Job");
						}
					// }
				}
				else if(PlayerToPoint(1.0, playerid,LawyerJobPosition[X],LawyerJobPosition[Y],LawyerJobPosition[Z]))
				{
					// if(GetPlayerVirtualWorld(playerid) == LawyerJobPosition[World])
					// {
						if(gPlayerData[playerid][pMat] < 5)
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Musisz mieæ co najmniej 5 poziom matematyki aby zdobyæ t¹ prace");
						}
						else
						{
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[SUKCES:] Jesteœ teraz prawnikiem, wpisz /komendypracy.");
							gPlayerData[playerid][pJob] = 4; //Lawyer Job

							SavePlayerData(playerid, "Job");
						}
					// }
				}
				else if(PlayerToPoint(1.0, playerid,WhoreJob[TakeJobX],WhoreJob[TakeJobY],WhoreJob[TakeJobZ]))
				{
					if(GetPlayerVirtualWorld(playerid) == WhoreJob[TakeJobWorld])
					{
						SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[SUKCES:] Jesteœ teraz dziwk¹, wpisz /komendypracy.");
						gPlayerData[playerid][pJob] = 6; //Whore Job

						SavePlayerData(playerid, "Job");
					}
				}
				else if(PlayerToPoint(1.0, playerid,RapistJob[TakeJobX],RapistJob[TakeJobY],RapistJob[TakeJobZ]))
				{
					if(GetPlayerVirtualWorld(playerid) == RapistJob[TakeJobWorld])
					{
						SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[SUKCES:]] Jesteœ teraz gwa³cicielem, wpisz /komendypracy.");
						gPlayerData[playerid][pJob] = 8; //Rapist Job

						SavePlayerData(playerid, "Job");
					}
				}
				else if(PlayerToPoint(1.0, playerid,BodyJob[TakeJobX],BodyJob[TakeJobY],BodyJob[TakeJobZ]))
				{
					// if(GetPlayerVirtualWorld(playerid) == BodyJob[TakeJobWorld])
					// {
						if(gPlayerData[playerid][pWf] < 3)
						{
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] Musisz mieæ przynamniej 3 poziom WFu aby zdobyæ t¹ prace");
						}
						else
						{
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[SUKCES:] Jesteœ teraz ochroniarzem, wpisz /komendypracy.");
							gPlayerData[playerid][pJob] = 9; //Body Job

							SavePlayerData(playerid, "Job");
						}
					// }
				}
				else if(PlayerToPoint(1.0, playerid,BoxerJob[TakeJobX],BoxerJob[TakeJobY],BoxerJob[TakeJobZ]))
				{
					if(GetPlayerVirtualWorld(playerid) == BoxerJob[TakeJobWorld])
					{
						SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[SUKCES:] Jesteœ teraz boxerem, wpisz /komendypracy.");
						gPlayerData[playerid][pJob] = 7; //Boxer Job

						SavePlayerData(playerid, "Job");
					}
				}
				else if(PlayerToPoint(1.0, playerid,CarjackJob[TakeJobX],CarjackJob[TakeJobY],CarjackJob[TakeJobZ]))
				{
					if(gPlayerData[playerid][pFaction ] == 255)
					{
						SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie nale¿ysz do ¿adnej frakcji");
						return 1;
					}
					if(DynamicFactions[gPlayerData[playerid][pFaction]][fType] != 1)
					{
						SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Niew³aœciwy typ frakcji");
						return 1;
					}
					if(GetPlayerVirtualWorld(playerid) == CarjackJob[TakeJobWorld])
					{
						SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[SUKCES:] Jesteœ teraz z³odziejem samochodów, wpisz /komendypracy.");
						gPlayerData[playerid][pJob] = 10; //Carjack Job

						SavePlayerData(playerid, "Job");
					}
				}
				else if(PlayerToPoint(1.0, playerid,StuntJob[TakeJobX],StuntJob[TakeJobY],StuntJob[TakeJobZ]))
				{
					if(GetPlayerVirtualWorld(playerid) == StuntJob[TakeJobWorld])
					{
						SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[SUKCES:] Jesteœ teraz kaskaderem, wpisz /komendypracy.");
						gPlayerData[playerid][pJob] = 11; //Stunt Job

						SavePlayerData(playerid, "Job");
					}
				}
				else if(PlayerToPoint(1.0, playerid,DirJob[TakeJobX],DirJob[TakeJobY],DirJob[TakeJobZ]))
				{
					if(GetPlayerVirtualWorld(playerid) == DirJob[TakeJobWorld])
					{
						SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[SUKCES:] Jesteœ teraz re¿yserem filmowym, wpisz /komendypracy.");
						gPlayerData[playerid][pJob] = 12; //Director Job

						SavePlayerData(playerid, "Job");
					}
				}
				else if(PlayerToPoint(1.0, playerid,ProductsSellerJob[TakeJobX],ProductsSellerJob[TakeJobY],ProductsSellerJob[TakeJobZ]))
				{
					// if(GetPlayerVirtualWorld(playerid) == ProductsSellerJob[TakeJobWorld])
					// {
						SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[SUKCES:] Jesteœ teraz sprzedawc¹ produktów, wpisz /komendypracy.");
						gPlayerData[playerid][pJob] = 5; //Products Seller Job

						SavePlayerData(playerid, "Job");
					// }
				}
				else if(PlayerToPoint(1.0, playerid,BusJob[TakeJobX],BusJob[TakeJobY],BusJob[TakeJobZ]))
				{
					// if(GetPlayerVirtualWorld(playerid) == BusJob[TakeJobWorld])
					// {
						if(gPlayerData[playerid][pCarLic] == 0)
						{
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] Prawo jazdy jest wymagane do tej pracy !");
						}
						else
						{
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[SUKCES:] Jesteœ teraz kierowc¹ autobusu, wpisz /komendypracy.");
							gPlayerData[playerid][pJob] = 13; //Bus Driver
							SetProgressBarMaxValue(JobProgress[playerid], float(11 + (gPlayerData[playerid][pJobLvl]*5) ) );
							
							SavePlayerData(playerid, "Job");
						}
					// }
				}
				else if(PlayerToPoint(1.0, playerid,MzgkJob[TakeJobX],MzgkJob[TakeJobY],MzgkJob[TakeJobZ]))
				{
					if(GetPlayerVirtualWorld(playerid) == MzgkJob[TakeJobWorld])
					{
						if(gPlayerData[playerid][pCarLic] == 0)
						{
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] Prawo jazdy jest wymagane do tej pracy !");
						}
						else
						{
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[SUKCES:] Jesteœ teraz kierowc¹ œmieciarki wpisz /komendypracy.");
							gPlayerData[playerid][pJob] = 14; //Mzgk Driver
							SetProgressBarMaxValue(JobProgress[playerid], float(11 + (gPlayerData[playerid][pMzgkJobLvl]*5) ) );

							SavePlayerData(playerid, "Job");
						}
					}
				}
				else if(PlayerToPoint(1.0, playerid,SweeperJob[TakeJobX],SweeperJob[TakeJobY],SweeperJob[TakeJobZ]))
				{
					if(GetPlayerVirtualWorld(playerid) == SweeperJob[TakeJobWorld])
					{
						if(gPlayerData[playerid][pCarLic] == 0)
						{
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] Prawo jazdy jest wymagane do tej pracy !");
						}
						else
						{
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[SUKCES:] Jesteœ teraz kierowc¹ myjki samochodowej, wpisz /komendypracy.");
							gPlayerData[playerid][pJob] = 15; //Sweeper Driver
							SetProgressBarMaxValue(JobProgress[playerid], float(11 + (gPlayerData[playerid][pSweeperJobLvl]*5) ) );
							
							SavePlayerData(playerid, "Job");
						}
					}
				}
				else if(PlayerToPoint(1.0, playerid,TaxiJob[TakeJobX],TaxiJob[TakeJobY],TaxiJob[TakeJobZ]))
				{
					if(GetPlayerVirtualWorld(playerid) == TaxiJob[TakeJobWorld])
					{
						if(gPlayerData[playerid][pCarLic] == 0)
						{
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] Prawo jazdy jest wymagane do tej pracy !");
						}
						else
						{
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[SUKCES:] Jesteœ teraz taksówkarzem, wpisz /komendypracy.");
							gPlayerData[playerid][pJob] = 16; // Taxi driver

							SavePlayerData(playerid, "Job");
						}
					}
				}
				else if(PlayerToPoint(1.0, playerid,MechanicJob[TakeJobX],MechanicJob[TakeJobY],MechanicJob[TakeJobZ]))
				{
					// if(GetPlayerVirtualWorld(playerid) == MechanicJob[TakeJobWorld])
					// {
						if(gPlayerData[playerid][pWf] < 1 || gPlayerData[playerid][pMat] < 1)
						{
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] Musisz mieæ co najmniej 1 poziom WFu i 1 poziom matematyki ¿eby zdobyæ t¹ prace");
						}
						else
						{
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[SUKCES:] Jesteœ teraz mechanikiem, wpisz /komendypracy.");
							gPlayerData[playerid][pJob] = 17; // Mechanik

							SavePlayerData(playerid, "Job");
						}
					// }
				}
				else if(PlayerToPoint(1.0, playerid,FarmerJob[TakeJobX],FarmerJob[TakeJobY],FarmerJob[TakeJobZ]))
				{
					if(GetPlayerVirtualWorld(playerid) == FarmerJob[TakeJobWorld])
					{
						SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[SUKCES:] Jesteœ teraz Farmerem, wpisz /komendypracy.");
						gPlayerData[playerid][pJob] = 18; //Farmer Driver
						SetProgressBarMaxValue(JobProgress[playerid], float(15 + (gPlayerData[playerid][pFarmerJobLvl]*5) ) );

						SavePlayerData(playerid, "Job");
					}
				}
				else if(PlayerToPoint(1.0, playerid,SellerJob[TakeJobX],SellerJob[TakeJobY],SellerJob[TakeJobZ]))
				{
					// if(GetPlayerVirtualWorld(playerid) == SellerJob[TakeJobWorld])
					// {
						SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[SUKCES:] Jesteœ teraz sprzedawc¹/ekspedientem, wpisz /komendypracy.");
						gPlayerData[playerid][pJob] = 19; //Seller

						SavePlayerData(playerid, "Job");
					// }
				}
				else if(PlayerToPoint(1.0, playerid,AccountantJob[TakeJobX],AccountantJob[TakeJobY],AccountantJob[TakeJobZ]))
				{
					// if(GetPlayerVirtualWorld(playerid) == SellerJob[TakeJobWorld])
					// {
						if(gPlayerData[playerid][pMagister] == 0)
						{
							SendClientMessage(playerid, COLOR_RED, "[INFO:] Musisz posiadaæ tytu³ magistra aby zdobyæ t¹ prace !");
							return 1;
						}
						else
						{
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[SUKCES:] Jesteœ teraz ksiêgowym, wpisz /komendypracy.");
							gPlayerData[playerid][pJob] = 20; //Accountant

							SavePlayerData(playerid, "Job");
						}
					// }
				}
				else if(PlayerToPoint(1.0, playerid,NewsBoyJob[TakeJobX],NewsBoyJob[TakeJobY],NewsBoyJob[TakeJobZ]))
				{
					// if(GetPlayerVirtualWorld(playerid) == SellerJob[TakeJobWorld])
					// {
						SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[SUKCES:] Jesteœ teraz roznosicielem gazet, wpisz /komendypracy.");
						gPlayerData[playerid][pJob] = 21; //NewsBoy

						SavePlayerData(playerid, "Job");
					// }
				}
				else if(PlayerToPoint(1.0, playerid, WFWorkerJob[TakeJobX],WFWorkerJob[TakeJobY],WFWorkerJob[TakeJobZ]))
				{
					if( gPlayerData[playerid][pFaction] != 255 )
					{
						if( DynamicFactions[ gPlayerData[playerid][pFaction] ][fType] == 3 )
						{
							SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz posiadaæ tej pracy bêd¹c jednoczeœnie w gangu !");
							return 1;
						}
					}
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[SUKCES:] Jesteœ teraz pracownikiem fabryki broni, wpisz /komendypracy.");
					gPlayerData[playerid][pJob] = 22;
					SavePlayerData(playerid, "Job");
				}
				gPlayerData[playerid][pJobTimeChange] = 6;
				SavePlayerData(playerid, "JobTimeChange");
			}
			else
			{
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] Masz ju¿ prace !");
			}
			return 1;
		}
		if(strcmp(cmd, "/zrezygnujzpracy", true) == 0)
		{
			// if(gPlayerData[playerid][pJob] != 0)
			// {
				// if(gPlayerData[playerid][pJobTimeChange] == 0)
				// {
					// if(gBusDriverOnDuty[playerid] == 1)
					// {
						// gBusDriverOnDuty[playerid] = 0;
					// }
					// gPlayerData[playerid][pJob] = 0;

					// SavePlayerData(playerid, "Job");

					// SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] Zrezygnowa³eœ ze swojej pracy.");
				// }
				// else
				// {
					// format(string, sizeof(string), "[B£¥D:] Nie mo¿esz jeszcze zrezygnowaæ ze swoje pracy. Musisz przepracowaæ jeszcze %d pkt poziomu postaci", gPlayerData[playerid][pJobTimeChange]);
					// SendClientMessage(playerid,COLOR_RED, string);
				// }
			// }
			// else
			// {
				// SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] Nie masz aktualnie pracy !");
			// }
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Aby zwolniæ siê z pracy musisz udaæ siê do urzêdu w Twoim mieœcie");
			return 1;
		}
		if(strcmp(cmd, "/komendypracy", true) == 0)
		{
			if(gPlayerData[playerid][pJob] != 0)
			{
				if (gPlayerData[playerid][pJob] == 1)
				{
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[ZAWÓD:] - [Diler broni] - jeœli jesteœ cz³onkiem gangu mo¿esz sk³adaæ broñ dla gangu w fabryce (jeœli jest ona dostêpna)");
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[ZAWÓD:] - [Diler broni] - jeœli nie jesteœ cz³onkiem gangu mo¿esz pracowaæ w legalnej fabryce broni");
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[ZAWÓD:] - [Diler broni] - komendy: /pobierzczesci - /skladaj");
				}
				else if(gPlayerData[playerid][pJob] == 2)
				{
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[ZAWÓD:] - [Diler narkotyków] - /narkotyki - /sprzedajnarkotyki");
				}
				else if(gPlayerData[playerid][pJob] == 3)
				{
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[ZAWÓD:] - [Detektyw] - /sledz - /sledzpojazd");
				}
				else if(gPlayerData[playerid][pJob] == 4)
				{
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[ZAWÓD:] - [Prawnik] - /uwolnij");
				}
				else if(gPlayerData[playerid][pJob] == 5)
				{
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[ZAWÓD:] - [Sprzedawca produktów] - /produkty");
				}
				else if(gPlayerData[playerid][pJob] == 6)
				{
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[ZAWÓD:] - [Dziwka] - Musisz poprostu uprawiaæ stosunek z innymi graczami /animlist");
				}
				else if(gPlayerData[playerid][pJob] == 7)
				{
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[ZAWÓD:] - [Boxer] - /walcz");
				}
				else if(gPlayerData[playerid][pJob] == 8)
				{
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[ZAWÓD:] - [Gwa³ciciel] - /gwalc");
				}
				else if(gPlayerData[playerid][pJob] == 9)
				{
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[ZAWÓD:] - [Ochroniarz] - /ochroniarz");
				}
				else if(gPlayerData[playerid][pJob] == 10)
				{
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[ZAWÓD:] - [Z³odziej samochodów] - /wlamsiedopojazdu");
				}
				else if(gPlayerData[playerid][pJob] == 11)
				{
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[ZAWÓD:] - [Kaskader] - /rozpocznijpokaz - /zakonczpokaz");
				}
				else if(gPlayerData[playerid][pJob] == 12)
				{
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[ZAWÓD:] - [Re¿yser] - Not a Quite interesting job =/ but...");
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[ZAWÓD:] - [Re¿yser] - Simply Start a Business and hire Filmers");
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[ZAWÓD:] - [Re¿yser] - and actors and Start Recording");
				}
				else if(gPlayerData[playerid][pJob] == 13)
				{
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[ZAWÓD:] - [Kierowca Autobusu] - Brak komend. Wsiadasz do autobusu i jedziesz linia autobusowa");
				}
				else if(gPlayerData[playerid][pJob] == 14)
				{
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[ZAWÓD:] - [Kierowca Smieciarki] - Brak komend. Wsiadasz do smieciarki i zaczynasz jechac do koszy na smieci");
				}
				else if(gPlayerData[playerid][pJob] == 15)
				{
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[ZAWÓD:] - [Kierowca Myjki samochodowej] - Brak komend. Wsiadasz do sweepera i zaczynasz czyscic ulice");
				}
				else if(gPlayerData[playerid][pJob] == 17)
				{
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[ZAWÓD:] - [Mechanik SF] - Jako mechanik masz za zadanie naprawiaæ/holowaæ pojazdy w przypadku gdy poprosi Ciê o to gracz.");
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[ZAWÓD:] - [Mechanik SF] - Sam ustalasz cene naprawy pojazdu jednak musisz o niej powiadomiæ klienta jeszcze przez napraw¹.");
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[ZAWÓD:] - [Mechanik SF] - Punkt skupu czêœci znajdziesz w Bayside, w pó³nocym mieœcie.");
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[ZAWÓD:] - [Mechanik SF] - Komendy : /kupczesci - /naprawpojazd - /przemaluj - /stanpojazdu - /wymianaopon - /czesci");
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[ZAWÓD:] - [Mechanik SF] - Komendy : /wymienzarowke - /zamontujhak - /montazgazu - /zamontujalarm - /podladujakumulator");
				}
				else if(gPlayerData[playerid][pJob] == 18)
				{
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[ZAWÓD:] - [Farmer] - Pamietaj o stosowaniu /ja oraz /do przy zsypie zbo¿a. Za nie przestrzeganie grozi kara");
				}
				else if(gPlayerData[playerid][pJob] == 19)
				{
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[ZAWÓD:] - [Sprzedawca/ekspedient] - Jak zacz¹æ prace ? - Udajesz siê do najbli¿szego biznesu. W jego wnêtrzu obs³ugujesz klientów");
				}
				else if(gPlayerData[playerid][pJob] == 20)
				{
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[ZAWÓD:] - [Ksiêgowy] /przedstawrozliczenie - pokazuje danej osobie jego wydatki oraz kwote odprowadzan¹ na podatki");
				}
				else if(gPlayerData[playerid][pJob] == 21)
				{
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[ZAWÓD:] - [Roznosiciel gazet] /rzucgazete - /pobierzgazety");
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[ZAWÓD:] - Aby rzuciæ gazete udaj siê pod jakikolwiek dom i uzyj komendy /rzucgazete.");
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[ZAWÓD:] - Nowe gazety mo¿esz pobieraæ zawsze w tym samym miejscu gdzie znalaz³eœ t¹ prace komend¹ /pobierzgazety.");
				}
				else if(gPlayerData[playerid][pJob] == 22)
				{
					SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[ZAWÓD:] - [Pracownik fabryki broni] /pobierzczesci - /skladaj");
					SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[ZAWÓD:] - Aby rozpoczac prace nale¿y w punkcie poboru czêœci fabryki wpisaæ komendê /pobierzczesci");
					SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[ZAWÓD:] - a nastêpnie przejœæ do jednego z punktów monta¿owych i komedn¹ /skladaj sk³adaæ poszczególne czêœci");
				}
			}
			else
			{
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] Nie posiadasz ¿adnej pracy !");
			}
			return 1;
		}
		if(strcmp(cmd, "/rozpocznijpokaz", true) == 0)
		{
			if(gPlayerData[playerid][pJob] != 11)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie jesteœ kaskaderem !");
				return 1;
			}
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "Rozpoczê³eœ pokazy!");
			EnableStuntBonusForPlayer(playerid, 1);
			return 1;
		}
		if(strcmp(cmd, "/zakonczpokaz", true) == 0)
		{
			if(gPlayerData[playerid][pJob] != 11)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie jesteœ kaskaderem !");
				return 1;
			}
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "Zakoñczy³eœ pokazy");
			EnableStuntBonusForPlayer(playerid, 0);
			return 1;
		}
		// if(strcmp(cmd,"/sprzedajbron",true)==0)
		// {
			// if (gPlayerData[playerid][pJob] != 1)
			// {
				// SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] Nie jesteœ diler broni.");
				// return 1;
			// }
			// new x_weapon[256],weapon[CUSTOM_MAX_PLAYERS],ammo[CUSTOM_MAX_PLAYERS],price[CUSTOM_MAX_PLAYERS];
			// tmp = strtok(cmdtext, idx);
			// if(!strlen(tmp))
			// {
				// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /sprzedajbron [playerid] [weapon]");
				// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[Bronie:] knife[50] - 9mm[300] - silenced[325] - eagle[350] - SMG[2400] - mp5[2500] shotgun[2000] - ak47[6000] m4[6000] - rifle [6000]");
				// return 1;
			// }
			// giveplayerid = ReturnUser(tmp);
			// if (IsPlayerConnected(giveplayerid) || giveplayerid == INVALID_PLAYER_ID)
			// {
				// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nieprawid³owe ID.");
				// return 1;
			// }
			// x_weapon = strtok(cmdtext, idx);
			// if(!strlen(x_weapon))
			// {
				// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /sprzedajbron [playerid] [weapon]");
				// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[Broniea:] knife[50] - silenced[150] - eagle[150] - mp5[200] shotgun[200] - ak47[600] m4[600] - rifle [600] - bazooka [800]");
				// return 1;
			// }
			// if(strcmp(x_weapon,"knife",true) == 0) { if(gPlayerData[playerid][pMaterials] > 49) { weapon[playerid] = 4; price[playerid] = 50; ammo[playerid] = 1; } else { SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] Masz za ma³o materia³ów !"); return 1; } }
			// else if(strcmp(x_weapon,"silenced",true) == 0) { if(gPlayerData[playerid][pMaterials] > 149) { weapon[playerid] = 23; price[playerid] = 325; ammo[playerid] = 50; } else { SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] Masz za ma³o materia³ów !"); return 1; } }
			// else if(strcmp(x_weapon,"eagle",true) == 0) { if(gPlayerData[playerid][pMaterials] > 449) { weapon[playerid] = 24; price[playerid] = 450; ammo[playerid] = 50; } else { SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] Masz za ma³o materia³ów !"); return 1; } }
			// else if(strcmp(x_weapon,"mp5",true) == 0) {	if(gPlayerData[playerid][pMaterials] > 2499) { weapon[playerid] = 29; price[playerid] = 2500; ammo[playerid] = 60; } else { SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] Masz za ma³o materia³ów !"); return 1; } }
			// else if(strcmp(x_weapon,"shotgun",true) == 0) {	if(gPlayerData[playerid][pMaterials] > 1999) { weapon[playerid] = 25; price[playerid] = 2000; ammo[playerid] = 25; } else { SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] Masz za ma³o materia³ów !"); return 1; } }
			// else if(strcmp(x_weapon,"ak47",true) == 0) { if(gPlayerData[playerid][pMaterials] > 5999) { weapon[playerid] = 30; price[playerid] = 6000; ammo[playerid] = 60; } else { SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] Masz za ma³o materia³ów !"); return 1; } }
			// else if(strcmp(x_weapon,"m4",true) == 0) { if(gPlayerData[playerid][pMaterials] > 5999) { weapon[playerid] = 31; price[playerid] = 6000; ammo[playerid] = 60; } else { SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] Masz za ma³o materia³ów !"); return 1; } }
			// else if(strcmp(x_weapon,"rifle",true) == 0) { if(gPlayerData[playerid][pMaterials] > 5999) { weapon[playerid] = 33; price[playerid] = 6000; ammo[playerid] = 7; } else { SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] Masz za ma³o materia³ów !"); return 1; } }
			// else if(strcmp(x_weapon,"9mm",true) == 0) { if(gPlayerData[playerid][pMaterials] > 299) { weapon[playerid] = 22; price[playerid] = 300; ammo[playerid] = 8; } else { SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] Masz za ma³o materia³ów !"); return 1; } }
			// else if(strcmp(x_weapon,"SMG",true) == 0) { if(gPlayerData[playerid][pMaterials] > 2399) { weapon[playerid] = 29; price[playerid] = 2400; ammo[playerid] = 60; } else { SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] Masz za ma³o materia³ów !"); return 1; } }
			// else { SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] Invalid weapon name."); return 1; }
			// if (ProxDetectorS(5.0, playerid, giveplayerid))
			// {
				// format(string, sizeof(string), "[INFO:] Przekaza³aeœ %s, %s z %d nabojami, za %d materia³ów.", GetPlayerNameEx(giveplayerid),x_weapon, ammo[playerid], price[playerid]);
				// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
				// format(string, sizeof(string), "[INFO:] Otrzyma³eœ %s - Amunicja: %d - Od %s.", x_weapon, ammo[playerid], GetPlayerNameEx(playerid));
				// SendClientMessage(giveplayerid, COLOR_LIGHTYELLOW2, string);
				// GivePlayerGun(giveplayerid,weapon[playerid],ammo[playerid]);
				// gPlayerData[playerid][pMaterials] -= price[playerid];

				// SavePlayerData(playerid, "Materials");

				// log
				// new Year, Month, Day;
				// getdate(Year, Month, Day);
				// new Hour, Minute, Second;
				// gettime(Hour, Minute, Second);
				// new form[256];

				// format(form, sizeof(form), "[GOVERNMENT:] %02d/%02d/%d, %02d:%02d:%02d, Weapon %s, ammo: %d, sold to: %s by %s", Day, Month, Year, Hour, Minute, Second, x_weapon, ammo[playerid], GetPlayerNameEx(giveplayerid), GetPlayerNameEx(playerid));
				// print(form);
				// GovermentLog(form);
			// }
			// else
			// {
				// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie jesteœ wystarczaj¹co blisko !");
				// return 1;
			// }
			// return 1;
		// }
		if(strcmp(cmd,"/narkotyki",true)==0)
		{
			if(IsPlayerConnected(playerid))
			{
				if (gPlayerData[playerid][pJob] != 2)
				{
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] nie jesteœ dilerem narkotyków!");
					return 1;
				}
				new x_nr[256];
				x_nr = strtok(cmdtext, idx);
				if(!strlen(x_nr))
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /narkotyki [u¿ycie]");
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] kup, zrzuc.");
					return 1;
				}
				if(strcmp(x_nr,"kup",true) == 0)
				{
					if(PlayerToPoint(3.0,playerid,DrugJob[BuyDrugsX],DrugJob[BuyDrugsY],DrugJob[BuyDrugsZ]))
					{
						if(DrugsHolding[playerid] >= 50)
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie mo¿esz przenosiæ wiêcej paczek.");
							return 1;
						}
						tmp = strtok(cmdtext, idx);
						if(!strlen(tmp)) {
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /narkotyki [kup][iloœæ]");
							return 1;
						}
						new moneys;
						moneys = strval(tmp);
						if(moneys < 1 || moneys > 50) { SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Maksymalna iloœæ paczek to 50."); return 1; }
						new price = moneys * 100;
						if(GetPlayerCash(playerid) > price)
						{
							format(string, sizeof(string), "[INFO:] Kupi³eœ %d paczek - koszt: $%d.", moneys, price);

							SendClientMessage(playerid, COLOR_WHITE, string);
							SendClientMessage(playerid, COLOR_WHITE, "[INFO:] Musisz teraz dostarczyæ paczki.");

							// TODO: Cash goes nowhere, fix this
							GivePlayerCash(playerid, -price);
							SavePlayerData(playerid, "cash");

							DrugsHolding[playerid] = moneys;
						}
						else
						{
							format(string, sizeof(string), "[B£¥D:] Nie masz $%d.", price);
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie jesteœ w miejscu skupu narkotyków!");
						return 1;
					}
				}
				else if(strcmp(x_nr,"zrzuc",true) == 0)
				{
					if(PlayerToPoint(3.0,playerid,DrugJob[DeliverX],DrugJob[DeliverY],DrugJob[DeliverZ]))
					{
						if(DrugsHolding[playerid] > 0)
						{
							new payout = DrugsHolding[playerid];

							format(string, sizeof(string), "{INFO:] Dostarczy³eœ %d narkotyków, s¹ one teraz sprzedawalne.", payout);
							SendClientMessage(playerid, COLOR_WHITE, string);

							gPlayerData[playerid][pDrugs] += payout;

							SavePlayerData(playerid, "Drugs");

							DrugsHolding[playerid] = 0;
						}
						else
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie masz ¿adnych narkotyków !");
							return 1;
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie znajdujesz siê w punkcie zrzutu.");
						return 1;
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Niew³aœciwe u¿ycie.");
					return 1;
				}
			}
			return 1;
		}
		// if(strcmp(cmd,"/materialy",true)==0)
		// {
			// if(IsPlayerConnected(playerid))
			// {
				// if (gPlayerData[playerid][pJob] != 1)
				// {
					// SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] Nie jesteœ dilerem broni!");
					// return 1;
				// }
				// new x_nr[256];
				// x_nr = strtok(cmdtext, idx);
				// if(!strlen(x_nr)) {
					// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /materialy [u¿ycie]");
					// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] kup, zrzuc.");
					// return 1;
				// }
				// if(strcmp(x_nr, "kup",true) == 0)
				// {
					// if(PlayerToPoint(3.0,playerid,GunJob[BuyPackagesX],GunJob[BuyPackagesY],GunJob[BuyPackagesZ]))
					// {
						// if(MatsHolding[playerid] >= 10)
						// {
							// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie mo¿esz przenosiæ wiêcej materia³ów.");
							// return 1;
						// }
						// tmp = strtok(cmdtext, idx);
						// if(!strlen(tmp))
						// {
							// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /materialy [kup] [ilosc]");
							// return 1;
						// }
						// new moneys;
						// moneys = strval(tmp);
						// if(moneys < 1 || moneys > 10) { SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Maksymalna liczba materia³ów to 10."); return 1; }
						// new price = moneys * 1000;
						// if(GetPlayerCash(playerid) > price)
						// {
							// format(string, sizeof(string), "[INFO:] Masz %d paczek materia³ów - Koszt: $%d.", moneys, price);
							// SendClientMessage(playerid, COLOR_WHITE, string);
							// SendClientMessage(playerid, COLOR_WHITE, "[INFO:] Musisz teraz dostarczyæ paczki.");
							// SendFactionTypeMessage(1, COLOR_LSPD, "[WYWIAD:] Ktoœ odebra³ nielegalne czêœci do budowy broni.");

							// GivePlayerCash(playerid, - price);

							// SavePlayerData(playerid, "cash");

							// MatsHolding[playerid] = moneys;
						// }
						// else
						// {
							// format(string, sizeof(string), "[B£¥D:] Nie masz $%d.", price);
							// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
						// }
					// }
					// else
					// {
						// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie znajdujesz siê na skupie materia³ów!");
						// return 1;
					// }
				// }
				// else if(strcmp(x_nr,"zrzuc",true) == 0)
				// {
					// if(PlayerToPoint(3.0,playerid,GunJob[DeliverX],GunJob[DeliverY],GunJob[DeliverZ]))
					// {
						// if(MatsHolding[playerid] > 0)
						// {
							// new payout = (40)*(MatsHolding[playerid]);
							// format(string, sizeof(string), "[INFO:] Paczki dostarczone, dostajesz %d materia³ów.", payout);

							// SendClientMessage(playerid, COLOR_WHITE, string);
							// SendFactionTypeMessage(1, COLOR_LSPD, "[WYWIAD:] Ktoœ odebra³ nielegaln¹ broñ.");

							// gPlayerData[playerid][pMaterials] += payout;

							// SavePlayerData(playerid, "Materials");

							// MatsHolding[playerid] = 0;
						// }
						// else
						// {
							// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie posiadasz ¿adnych paczek!");
							// return 1;
						// }
					// }
					// else
					// {
						// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie jesteœ na miejscu zrzutu paczek!");
						// return 1;
					// }
				// }
				// else
				// {
					// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nieprawid³owe u¿ycie.");
					// return 1;
				// }
			// }
			// return 1;
		// }
		if (strcmp(cmd, "/admini", true) == 0)
		{
			new count = 0;
			SendClientMessage(playerid, COLOR_LIGHTGREEN, "----------[ADMINISTRATORZY NA S£U¯BIE]----------");
			foreach(Player, i )
			{
				if(gPlayerData[i][pAdmin] >= 1 && AdminDuty[i] == 1)
				{
					format(string, 256, "Administrator: %s - [Lvl Administratora: %d]", GetPlayerNameEx(i),gPlayerData[i][pAdmin]);
					SendClientMessage(playerid, COLOR_WHITE, string);
					count++;
				}
			}
			if(count == 0)
			{
				SendClientMessage(playerid,COLOR_WHITE,"[INFO:] Brak administratorów na s³u¿bie.");
			}
			SendClientMessage(playerid, COLOR_LIGHTGREEN, "----------------------------------------------------------");
			return 1;
		}
		if(strcmp(cmd, "/faq", true) == 0)
		{
			SendClientMessage(playerid,COLOR_YELLOW,"______________________FAQ!!!______________________");
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[Jak zmieniæ wygl¹d ?] - Na terenie Palomino Creek i Montgomery znajduje siê kilka sklepów z ubraniami. WejdŸ do niego i u¿yj komendy /kupubranie [ID Skinu].");
			SendClientMessage(playerid,COLOR_LIGHTORANGE,"[Jak dostaæ prace ?] - Wystarczy wejœæ w czerwony marker umieszczony przy ladzie w budynku urzêdu i wybradŸ odpowiadaj¹c¹ Ci z listy dostêpnych.");
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[Jak do³¹czyæ do frakcji ?] - ZnajdŸ najbardziej odpowiadaj¹c¹ Ci i z³ó¿ podanie na forum. W najbli¿szym czasie lider zadecyduje o przyjêciu.");
			SendClientMessage(playerid,COLOR_LIGHTORANGE,"[Dlaczego nikt mi nie odpisuje ?] - Je¿eli nikt nie jest w twojej okolicy nie zauwa¿y tego co piszesz. U¿yj komendy /pw [ID] je¿eli to sprawa OOC...");
			SendClientMessage(playerid,COLOR_LIGHTORANGE,"...lub telefonu w celu rozmowy IC. Telefon oraz ksi¹¿kê telefoniczn¹ mo¿na nabyæ w sklepie.");
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[Widze cheatera, co mam zrobiæ ?] - U¿yj komendy /donos [ID Oszusta] [Powód], a administrator go ukara.");
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"Je¿eli chcesz zobaczyæ dalszy ci¹g u¿yj komendy /faq2");
			return 1;
		}
		if(strcmp(cmd, "/faq2", true) == 0)
		{
			SendClientMessage(playerid,COLOR_YELLOW,"______________________FAQ!!!______________________");
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[Jak zdobyæ prawko, licencje ?] - Zacznij od znalezienia pracy dziêki której zapracujesz na odpowiedni¹ licencje.");
			SendClientMessage(playerid,COLOR_LIGHTORANGE,"[Jak zarobiæ pieni¹dze ?] - Wybierz jedn¹ z dostêpnych w urzêdzie prac lub do³¹cz do jednej z kilku frakcji.");
			SendClientMessage(playerid,COLOR_LIGHTORANGE,"Pamiêtaj jednak ¿e frakcje oraz prace dziel¹ siê na Legalne oraz Nielegalne. Za sprawowanie us³ug...");
			SendClientMessage(playerid,COLOR_LIGHTORANGE,"...tej drugiej kategorii mo¿esz zostaæ aresztowany przez policje.");
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[Czy moge byæ policjantem ?] - Mo¿esz osi¹gn¹æ wszystko - zale¿y to g³ównie od Ciebie.");
			SendClientMessage(playerid,COLOR_LIGHTORANGE,"Je¿eli chcesz zobaczyæ dalszy ci¹g u¿yj komendy /faq3.");
			return 1;
		}
		if(strcmp(cmd, "/faq3", true) == 0)
		{
		SendClientMessage(playerid,COLOR_YELLOW,"______________________FAQ!!!______________________");
		SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[Gdzie mogê kupiæ samochód ?] - Je¿eli uzbierasz odpowiedni¹ iloœæ gotówki udaj siê do salonu...");
		SendClientMessage(playerid,COLOR_LIGHTORANGE,"...lub skontakuj siê z dilerem pojazdów w celu jego zamówienia.");
		SendClientMessage(playerid,COLOR_LIGHTORANGE,"[Jak rozpoznaæ administratora ?] - Je¿eli jest on na s³u¿bie bêdzie on mia³...");
		SendClientMessage(playerid,COLOR_LIGHTORANGE,"...kolor nicku na liœcie, je¿eli nie - zapytaj kogoœ na czacie OOC.");
		SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[Czemu gramy w dwóch miastach ?] - Poniewa¿ w jednym - Palomino Creek znajduj¹....");
		SendClientMessage(playerid,COLOR_LIGHTORANGE,"...siê domy i biznesy, a w drugim - Montgomery budynki frakcji.");
		return 1;
		}
		if(strcmp(cmd, "/zasady", true) == 0)
		{
		SendClientMessage(playerid,COLOR_YELLOW,"______________________Zasady______________________");
		SendClientMessage(playerid, COLOR_GREY, "1.Na serwerze obowi¹zuj¹ podstawowe zasady kultury.");
		SendClientMessage(playerid, COLOR_GREY, "2.Podobnie jak na ka¿dym Role Play'u obowi¹zuje gra IC.");
		SendClientMessage(playerid, COLOR_GREY, "3.Proœby do administracji o podniesienie rangi OOC...");
		SendClientMessage(playerid, COLOR_GREY, "...do Moderatora lub Administratora bêdzie skutecznie zwalczane.");
		SendClientMessage(playerid, COLOR_GREY, "4.U¿ywanie programów wspomagaj¹cych grê zawsze koñczy siê banem.");
		SendClientMessage(playerid, COLOR_GREY, "Aby zobaczyæ ci¹g dalszy u¿yj komendy /zasady2.");
		return 1;
		}
		if(strcmp(cmd, "/zasady2", true) == 0)
		{
		SendClientMessage(playerid,COLOR_YELLOW,"______________________Zasady______________________");
		SendClientMessage(playerid, COLOR_GREY, "5.Proszenie innych graczy o datki materialne jest zabronione.");
		SendClientMessage(playerid, COLOR_GREY, "6.Rozdawanie pieniêdzy (Feedowanie) jest zabronione.");
		SendClientMessage(playerid, COLOR_GREY, "7.U¿ywanie wszelkich noobowskich s³ów jak na przyk³ad...");
		SendClientMessage(playerid, COLOR_GREY, "...¿al, lol, wtf zarówno na czacie IC jak i OOC jest zakazane.");
		SendClientMessage(playerid, COLOR_GREY, "8.Reklamowanie innych serwerów jest ca³kowicie zakazane.");
		SendClientMessage(playerid, COLOR_GREY, "Aby zobaczyæ ci¹g dalszy u¿yj komendy /zasady3.");
		return 1;
		}
		if(strcmp(cmd, "/zasady3", true) == 0)
		{
		SendClientMessage(playerid,COLOR_YELLOW,"______________________Zasady______________________");
		SendClientMessage(playerid, COLOR_GREY, "9.Zabranie siê u¿ywania samochodu do zabijania graczy (CK2).");
		SendClientMessage(playerid, COLOR_GREY, "10.Banem zakoñczyæ mo¿e siê zabijanie ludzi bez powodu.");
		SendClientMessage(playerid, COLOR_GREY, "11.Drive By czyli strzelanie z okna samochodu jest zakazane.");
		SendClientMessage(playerid, COLOR_GREY, "12.Zabijanie osób za pomoc¹ helikopterów jest zakazane.");
		SendClientMessage(playerid, COLOR_GREY, "13.Nick gracza musi byæ IC czyli Imiê_Nazwisko.");
		SendClientMessage(playerid, COLOR_GREY, "Aby zobaczyæ ostatni¹ czêœæ u¿yj komendy /zasady4.");
		}
		if(strcmp(cmd, "/zasady4", true) == 0)
		{
		SendClientMessage(playerid,COLOR_YELLOW,"______________________Zasady______________________");
		SendClientMessage(playerid, COLOR_GREY, "Na zakoñczenie chcielibyœmy ¿yczyæ Ci mi³ej rozgrywki...");
		SendClientMessage(playerid, COLOR_GREY, "...na WParty i abyœ d³ugo zosta³ w naszej spo³ecznoœci.");
		SendClientMessage(playerid, COLOR_GREY, "Pamiêtaj równie¿ ¿e gdy bêdziesz stosowa³ siê do...");
		SendClientMessage(playerid, COLOR_GREY, "...powy¿szych zasad zostaniesz doceniony przez innych...");
		SendClientMessage(playerid, COLOR_GREY, "...i rozgrywka stanie siê bardziej przyjemna.");
		SendClientMessage(playerid, COLOR_GREY, "Mi³ej gry na WParty ¿yczy Administracja !");
		}
		if(strcmp(cmd, "/kody", true) == 0)
		{
			SendClientMessage(playerid,COLOR_YELLOW,"______________________Kody policyjne______________________");
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"10-4 = Wiadomoœæ odebrana");
			SendClientMessage(playerid,COLOR_LIGHTORANGE,"10-8 = Potrzebne wsparcie (LOKACJA)");
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"10-10 = W zatrzymaniu");
			SendClientMessage(playerid,COLOR_LIGHTORANGE,"10-22 = Funkcjonariusz w poœcigu");
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"10-30 = Œledzony przez podejrzany wóz (LOKACJA)");
			SendClientMessage(playerid,COLOR_LIGHTORANGE,"10-40 = Funkcjonariusz jest œcigany (LOKACJA)");
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"10-44 = Podejrzany aresztowany");
			SendClientMessage(playerid,COLOR_LIGHTORANGE,"10-66 = Funkcjonariusz na s³u¿bie");
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"22-10 = Potrzebne wszystkie jednostki (LOKACJA)");
			return 1;
		}
		// if(strcmp(cmd, "/pomoc", true) == 0)
		// {
			// if(IsPlayerConnected(playerid))
			// {
				// new x_nr[256];
				// x_nr = strtok(cmdtext, idx);
				// if(!strlen(x_nr))
				// {
					// SendClientMessage(playerid,COLOR_YELLOW,"______________________Pomoc______________________");
					// SendClientMessage(playerid, COLOR_RED, "Aby skorzystaæ ze szczegó³owej pomocy wpisz /pomoc oraz dany podrozdzia³ np.: '/pomoc WPARTY'");
					// SendClientMessage(playerid, COLOR_GREY, "Zasady - Zasady gry;");
					// SendClientMessage(playerid, COLOR_GREY, "Prace	- Informacje i lokacje;	  | Schowek - Pomoc dot. schowka;");
					// SendClientMessage(playerid, COLOR_GREY, "Poziomy - Zdobywanie leveli;	  | Posesje - Dom i jego funkcje;");
					// SendClientMessage(playerid, COLOR_GREY, "Frakcje - Opis frakcji/gangów;");
					// SendClientMessage(playerid, COLOR_GREY, "Samochód - pomoc dot. samochodu; | Biznesy - Biznes i zarobki;");
					// return 1;
				// }
				// else if(strcmp(x_nr,"Zasady",true) == 0)
				// {
					// SendClientMessage(playerid, COLOR_WHITE, "___________________WParty - Zasady______________");
					// SendClientMessage(playerid, COLOR_GREY, "1: Nie spamuj - korzystaj z FAQ !");
					// SendClientMessage(playerid, COLOR_GREY, "2: Nie proœ siê o bycie adminem bo uprosisz siê o bana.");
					// SendClientMessage(playerid, COLOR_GREY, "3: Jeœli chcesz nale¿eæ do którejœ z grup porozmawiaj z liderem.");
					// SendClientMessage(playerid, COLOR_GREY, "4: Nie proœ o pieni¹dze, i tak ¿adnych nie dostaniesz.");
					// SendClientMessage(playerid, COLOR_GREY, "6: Nie u¿ywaj cheatów, hacków ani modów które mog³by by wp³yn¹æ na rozgrywke innych.");
					// return 1;
				// }
				// else if(strcmp(x_nr,"Samochod",true) == 0)
				// {
					// SendClientMessage(playerid, COLOR_WHITE, "___________________WParty - Samochód______________");
					// SendClientMessage(playerid, COLOR_GREY, "W wirtualny ¿yciu WParty RP mo¿esz posiadaæ 2 pojazdy, 1 helikopter i 1 samolot.");
					// SendClientMessage(playerid, COLOR_GREY, "Samochody i motory mo¿na znaleŸæ w kilku salonach znajduj¹cych siê w San Fierro.");
					// SendClientMessage(playerid, COLOR_GREY, "Raz kupiony pojazd pozostaje we w³adaniu w³aœciciela przez ca³y czas.");
					// SendClientMessage(playerid, COLOR_GREY, "W³aœciciel pojazdu mo¿e go stuningowaæ i zaparkowaæ go w dowolnym miejscu.");
					// SendClientMessage(playerid, COLOR_GREY, "Aby zamkn¹æ/otworzyæ u¿yj /zamknij.");
					// SendClientMessage(playerid, COLOR_GREY, "Przy sprzeda¿y pojazdu mo¿na uzykaæ ponad 80 procent jego ceny.");
					// return 1;
				// }
				// else if(strcmp(x_nr,"Prace",true) == 0)
				// {
					// SendClientMessage(playerid, COLOR_WHITE, "___________________WParty - Prace______________");
					// SendClientMessage(playerid, COLOR_GREY, "Na serwerze dostêpnych jest wiele rodzajów prac.");
					// SendClientMessage(playerid, COLOR_GREY, "Jedne mog¹ przynieœæ zysk, drugie mog¹ pomóc we frakcji.");
					// SendClientMessage(playerid, COLOR_GREY, "Wszystkie prace mo¿na znaleŸæ pod urzêdem pracy.");
					// SendClientMessage(playerid, COLOR_GREY, "Ka¿dy gracz co 20 minut dostaje wyp³¹te o losowej wysokoœci");
					// SendClientMessage(playerid, COLOR_GREY, "od $500 do $1500.");
					// return 1;
				// }
				// else if(strcmp(x_nr,"Itemy",true) == 0)
				// {
					// SendClientMessage(playerid, COLOR_WHITE, "___________________WParty - Schowek______________");
					// SendClientMessage(playerid, COLOR_GREY, "Mo¿esz przetrzymywaæ jedn¹ broñ w schowku u¿ywaj¹c komendy /schowek lub /inv.");
					// return 1;
				// }
				// else if(strcmp(x_nr,"Poziomy",true) == 0)
				// {
					// SendClientMessage(playerid, COLOR_WHITE, "___________________WParty - Poziomy______________");
					// SendClientMessage(playerid, COLOR_GREY, "W grze mo¿na zdobyæ nieskoñczon¹ liczbe poziomów.");
					// SendClientMessage(playerid, COLOR_GREY, "Zale¿nie od poziomu bêdziesz móg³ ubiegaæ siê o dostêp do frakcji");
					// SendClientMessage(playerid, COLOR_GREY, "lub gangu. Im wy¿szy poziom tym wiêksza szansa akceptacji");
					// SendClientMessage(playerid, COLOR_GREY, "twojego zg³oszenia.");
					// return 1;
				// }
				// else if(strcmp(x_nr,"Posesje",true) == 0)
				// {
					// SendClientMessage(playerid, COLOR_WHITE, "___________________WParty - Posesje______________");
					// SendClientMessage(playerid, COLOR_GREY, "Aby kupiæ dom ZNAJDŸ GO, STAN NA ZIELONYM DOMKU(IKONCE) i wpisz /kupdom");
					// SendClientMessage(playerid, COLOR_GREY, "Domy maj¹ losowe ceny oraz losowe wnêtrza.");
					// SendClientMessage(playerid, COLOR_GREY, "Opis ka¿dego domu pozwoli dokonaæ ci wyboru kupna.");
					// SendClientMessage(playerid, COLOR_GREY, "W ka¿dym domu mo¿na przechowywaæ pieni¹dze, narkotyki");
					// SendClientMessage(playerid, COLOR_GREY, "oraz czêœci do budowy broni. Dom to tak¿e œwietna kryjówka.");
					// return 1;
				// }
				// else if(strcmp(x_nr,"Frakcje",true) == 0)
				// {
					// SendClientMessage(playerid, COLOR_WHITE, "___________________WParty - Frakcje______________");
					// SendClientMessage(playerid, COLOR_GREY, "Na serwerze s¹ 4 dzia³aj¹ce frakcje + 2 gangi.");
					// SendClientMessage(playerid, COLOR_GREY, "Zale¿nie od poziomu mo¿esz ubiegaæ siê o do³¹czenie");
					// SendClientMessage(playerid, COLOR_GREY, "do frakcji lub gangu. Propozycje najlepiej sk³adaæ na forum.");
					// SendClientMessage(playerid, COLOR_GREY, "Frakcje: Policja, HALO Taxi, Wojsko i Medycy.");
					// SendClientMessage(playerid, COLOR_GREY, "Gangi: =SLU= CZANG, CZA KING.");
					// return 1;
				// }
				// else if(strcmp(x_nr,"Biznesy",true) == 0)
				// {
					// SendClientMessage(playerid, COLOR_WHITE, "___________________WParty - Biznesy______________");
					// SendClientMessage(playerid, COLOR_GREY, "Aby kupiæ biznes ZNAJDŸ GO, STAN NA NIEBIESKIM DOMKU(IKONCE) i wpisz /kupbiznes.");
					// SendClientMessage(playerid, COLOR_GREY, "Po zakupie za kupione towary przez graczy bêdziesz otrzymywa³ kase.");
					// SendClientMessage(playerid, COLOR_GREY, "Biznesy 24/7, Ammunation i sklepy z po¿ywieniem maj¹ ograniczon¹");
					// SendClientMessage(playerid, COLOR_GREY, "liczbe produktów. Produkty mo¿na dokupiæ u osoby sprzedaj¹cej produkty.");
					// SendClientMessage(playerid, COLOR_GREY, "Sprzedaj¹cy ustala cene sprzedawanych produktów.");
					// return 1;
				// }
			// }
		// }
		if (strcmp("/pomoc", cmdtext, true, 10) == 0)
		{
			ShowPlayerDialog(playerid, DIALOG_HELP, DIALOG_STYLE_LIST, "WParty - Pomoc", DIALOG_HELP_MAIN_TXT, "Wybierz", "WyjdŸ");
			return 1;
		}
		if(strcmp(cmd, "/czolowka", true) == 0)
		{
			SendClientMessage(playerid,COLOR_LIGHTBLUE,"WlanParty RP Server");
			SendClientMessage(playerid,COLOR_LIGHTBLUE,"Xtreme - skrypter, head admin");
			SendClientMessage(playerid,COLOR_LIGHTBLUE,"Xamxe - support, skrypter, second admin");
			return 1;
		}
		if(strcmp(cmd, "/prawko", true) == 0)
		{
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"Aby zdaæ prawko musisz udaæ siê do WORD który znajduje siê ko³o stra¿y po¿arnej (ikonka samochodu na mapce)");
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"Nale¿y wejœæ do bundynku i stan¹æ miêdzy kanap¹ a TV, tam wpisaæ pokazana komende.");
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"Postêpowaæ zgodnie z ukazanymi komunikatami.");
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"Po zakoñczonym teœcie otrzymasz rezultat.");
			return 1;
		}
		if(strcmp(cmd, "/notatki", true) == 0)
		{
			if(IsPlayerConnected(playerid))
			{
				SendClientMessage(playerid, COLOR_GREEN,"_______________________________________");
				SendClientMessage(playerid, COLOR_GRAD3,"*** NOTKI *** /pokaznotki /usunnotke /zrobnotke /przekaznotke");
			}
			return 1;
		}
		if(strcmp(cmd, "/wyscig", true) == 0)
		{
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"/dolaczdowyscigu - /rozpocznijwyscig - /zrezygnujzwyscigu - /komendyorganizatora");
			return 1;
		}
		if(strcmp(cmd, "/komendy", true) == 0 || strcmp(cmd, "/cmds", true) == 0)
		{
			SendClientMessage(playerid,COLOR_YELLOW,"____________________________________________________");
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"/faq - /pomoc - /statystyki - /komendytel - /komendypojazdow - /komendydomu - /komendybiznesu - /komendypracy - /komendypolicji");
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"/admini - /stankonta - /wyplac - /wplac - /wezprace - /zrezygnujzpracy - /animacje - /jedz - /kupdrink - /ogloszenie - /pokazid");
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"/akceptuj - /donos - /wywal - /resetanimacji - /wyscig - /onoff - /licencje - /uzyjnarkotykow - /kostka - /proba - /podpalfab");
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"/notatki - /walczoterytorium - /komendylidera - /wyrobkarte - (/k)rzycz - (/s)zepcz - /ja - /do - /czolowka - /wyjedzzgarazu");
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"/wjedzdogarazu - /otworzgaraz - /zamknijgaraz - /opis - /obiekty - /wyrzucgracza - /glosujza");

			if(gPlayerData[playerid][pAdmin] > 0)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2,"/admincmds[1/2/3]");
			}
			
			SendClientMessage(playerid,COLOR_YELLOW,"____________________________________________________");
			return 1;
		}
		if(strcmp(cmd, "/odbierz", true) == 0 || strcmp(cmd, "/odb", true) == 0)
		{
			if(Mobile[playerid] != 255)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Jesteœ ju¿ po³¹czony ! (/rozlacz).");
				return 1;
			}
			if(gPlayerData[playerid][pCharacterDying] != 0)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Twoja postaæ jest nieprzytomna nie mo¿esz odebraæ telefonu !");
				return 1;
			}
			foreach(Player, i )
			{
				if(Mobile[i] == playerid)
				{
					Mobile[playerid] = i;
					IncommingCall[playerid] = 0;

					SendClientMessage(i, COLOR_LIGHTBLUE, "[INFO:] Gracz odebra³ telefon.");

					if(!IsPlayerInAnyVehicle(playerid))
					{
						SetPlayerSpecialAction(playerid,SPECIAL_ACTION_USECELLPHONE);
						SetPlayerAttachedObject(playerid, 4, 330, 6);
					}
				}
			}
			return 1;
		}
		if(strcmp(cmd, "/rozlacz", true) == 0 )
		{
			new caller = Mobile[playerid];
			if(caller == 255)
			{
				SendClientMessage(playerid,  COLOR_LIGHTYELLOW2, "[B£¥D:] Nie jesteœ po³aczony !");
				return 1;
			}
			if(IsPlayerConnected(caller) && gPlayerLogged[caller])
			{
				if(caller != INVALID_PLAYER_ID)
				{
					if(caller < 255)
					{
						SendClientMessage(caller,  COLOR_LIGHTGREEN, "[TELEFON:] Roz³¹czy³ siê.");
						SendClientMessage(playerid,  COLOR_LIGHTGREEN, "[TELEFON:] Roz³¹czy³eœ siê.");

						if(!IsPlayerInAnyVehicle(caller))
						{
							SetPlayerSpecialAction(caller, SPECIAL_ACTION_STOPUSECELLPHONE);
							RemovePlayerAttachedObject(caller, 4);
						}
						if(!IsPlayerInAnyVehicle(playerid))
						{
							SetPlayerSpecialAction(playerid,SPECIAL_ACTION_STOPUSECELLPHONE);
							RemovePlayerAttachedObject(playerid, 4);
						}

						Mobile[playerid] = 255;
						if( Mobile[caller] == playerid )
							Mobile[caller] = 255;

						if(StartedCall[playerid])
						{
							GivePlayerCash(playerid,-gCallCost[playerid]);
							if(gCalledCompany[playerid] != 255)
							{
								Businesses[gCalledCompany[playerid]][Till] += gCallCost[playerid];
								SaveBizData(gCalledCompany[playerid], "Till");
							}
							StartedCall[playerid] = 0;
						}
						else if(StartedCall[caller])
						{
							GivePlayerCash(caller,-gCallCost[caller]);
							if(gCalledCompany[caller] != 255)
							{
								Businesses[gCalledCompany[caller]][Till] += gCallCost[caller];
								SaveBizData(gCalledCompany[caller], "Till");
							}
							StartedCall[caller] = 0;
						}
					}
					return 1;
				}
			}
			SendClientMessage(playerid,  COLOR_LIGHTYELLOW2, "[B£¥D:] Nie jesteœ po³aczony !");
			return 1;
		}
		if(strcmp(cmd,"/kup",true)==0)
		{
			new x_info[256];
			new wstring[128];
			new slot;
			for(new i = 0; i < sizeof(Businesses); i++)
			{
				if (PlayerToPoint(25.0, playerid,Businesses[i][ExitX], Businesses[i][ExitY], Businesses[i][ExitZ]))
				{
					if(GetPlayerVirtualWorld(playerid) == i)
					{
						if(Businesses[i][BizType] == 1) //restauracje etc.
						{
							if(Businesses[i][Products] == 0)
							{
								SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Brak produktów !");
								return 1;
							}
							x_info = strtok(cmdtext, idx);

							if(!strlen(x_info))
							{
								format(wstring, sizeof(wstring), "[------------------------[%s]------------------------]", Businesses[i][BusinessName]);
								SendClientMessage(playerid, COLOR_LIGHTGREEN, wstring);
								SendClientMessage(playerid, COLOR_RED, "(Wpisz nazwe, bez spacji. Np.: {A10000} /kup baton)");
								SendClientMessage(playerid, COLOR_WHITE, "* Baton WParty - Cena: $2. {A10000} (baton)");
								return 1;
							}
							if(strcmp(x_info,"baton",true) == 0)
							{
								if(GetPlayerCash(playerid) >= 2)
								{						
									GivePlayerCash(playerid, -2);
									
									slot = PHaveItem(playerid, 1, 9);
									if(slot > 0)
									{
										SetPSlotParam6(playerid, slot, SlotParam6(playerid,slot)+1);
									}
									else 
									{
										if(InsertPlayerItemEx(playerid, 1, 9, 0, 0, 0, 0, "Puste", 1) == 0)
										{
											SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie masz miejsca na batona !");
											return 1;
										}
									}
									SendClientMessage(playerid, COLOR_GREEN, "[SUKCES:] Kupi³eœ baton");
									
									Businesses[i][Products]--;
									Businesses[i][Till] += 2;
									
									SaveBizData(i, "Products");
									SaveBizData(i, "Till");
									SaveStatsData("baton", gPlayerData[playerid][pName], 2, i, Businesses[i][BizType]);

									return 1;
								}
								else
								{
									SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie masz wystarczaj¹cej iloœci pieniêdzy !");
								}
							}
						}
						if(Businesses[i][BizType] == 3) //24-7
						{
							SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Aby kupiæ coœ w sklepie wejdŸ w czerwone kólko obok kasy");
							return 1;
						}
							// if(Businesses[i][Products] == 0)
							// {
								// SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Brak produktów !");
								// return 1;
							// }
							// gBuyBusiness[playerid] = i;
							// ShowPlayerDialog(playerid,DIALOG_BUY_1,DIALOG_STYLE_LIST,"Co chcesz kupiæ ?",
							// "1. Pa³ka bejsbolowa  [8$]\n2. Kanister [190$]\n3. £opata [10$]\n4. Plecak [59$]\n5. Kij bilardowy [5$]\n6. Rakieta [8$]\n7. Ksi¹¿ka telefoniczna [2$]\n8. Aparat fotograficzny [400$]\n9. Kwiaty [2$]\n10. ¯arówka H7 [60$]\n11. Kostka do gry [1$]\n12. Cygaro [8$]\n13. £om [10$]\n14. Hak holowniczny [120$]\n15. GPS [820$]\n16. Linka holownicza [50$]\n17. Krótkofallówka [120$]\n18. Alarm samochodowy [130$]",
							// "Kup","WyjdŸ");
							
							// x_info = strtok(cmdtext, idx);

							// if(!strlen(x_info))
							// {
								// format(wstring, sizeof(wstring), "[------------------------[%s]------------------------]", Businesses[i][BusinessName]);
								// SendClientMessage(playerid, COLOR_LIGHTGREEN, wstring);
								// SendClientMessage(playerid, COLOR_RED, "(Wpisz nazwe, bez spacji. Np.: {A10000} /kup palka)");
								// SendClientMessage(playerid, COLOR_WHITE, "* Pa³ka bejsbolowa - Cena: $8. {A10000} (palka) {FFFFFF}    |     * Kanister 25ltr - Cena: $190 {A10000} (kanister)");
								// SendClientMessage(playerid, COLOR_WHITE, "* £opata - Cena: $10. {A10000} (lopata)			{FFFFFF}					|			 * Plecak - Cena: $59 {A10000} (plecak)");
								// SendClientMessage(playerid, COLOR_WHITE, "* Kij bilardowy - Cena: $5. {A10000} (kijbilardowy) {FFFFFF}	|			 * Rakieta - Cena: $8 {A10000} (rakieta)");
								// SendClientMessage(playerid, COLOR_WHITE, "* Ksi¹¿ka telefoniczna - Cena: $2. {A10000} (ksiazkatel) {FFFFFF} | * Aparat fotograficzny - Cena: $400 {A10000} (aparat)");
								// SendClientMessage(playerid, COLOR_WHITE, "* Kwiaty - Cena: $2. {A10000} (kwiaty)		{FFFFFF}					| * ¯arówka H7 - Cena: $60 {A10000} (zarowka)");
								// SendClientMessage(playerid, COLOR_WHITE, "* Kostka do gry - Cena: $1. {A10000} (kostka)  {FFFFFF}  | * Fajerwerki - Cena: $100 {A10000} (fajerwerki)");
								// SendClientMessage(playerid, COLOR_WHITE, "* Kostka do gry - Cena: $1. {A10000} (kostka)  {FFFFFF} | * Cygaro - Cena: $8 {A10000} (cygaro)");
								// SendClientMessage(playerid, COLOR_WHITE, "* £om - Cena: $10. {A10000} (lom)						{FFFFFF}			| * Hak holowniczy - Cena: $120 {A10000} (hak)");
								// SendClientMessage(playerid, COLOR_WHITE, "* GPS - Cena: $820. {A10000} (gps)					{FFFFFF}			| * Linka holownicza - Cena: $50 {A10000} (linka)");
								// SendClientMessage(playerid, COLOR_WHITE, "* Krótkofalówka - Cena: 120$ {A10000} (krotkofalowka) {FFFFFF}| * Alarm samochodwy - Cena: $130 {A10000} (alarm)");
								// return 1;
							// }
							// if(strcmp(x_info,"cygaro",true) == 0)
							// {
								// if(GetPlayerCash(playerid) >= 8)
								// {					
									// if(ItemWeight(1, 12) + PItemWeight(playerid) > gPlayerData[playerid][pMaxWeight])
									// {
										// SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Jesteœ przeci¹¿ony ! Wyrzuæ jeden lub wiêcej itemów aby odci¹¿yæ Twoj¹ postaæ");
										// return 1;
									// }
									// slot = PHaveItem(playerid, 1, 12);
									// if(slot > 0)
									// {
										// SetPSlotParam6(playerid, slot, SlotParam6(playerid,slot)+1);
									// }
									// else 
									// {
										// if(InsertPlayerItemEx(playerid, 1, 12, 0, 0, 0, 0, "Puste", 1) == 0)
										// {
											// SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie masz miejsca na cygaro !");
											// return 1;
										// }
									// }
									// GivePlayerCash(playerid, -8);
									// SendClientMessage(playerid, COLOR_GREEN, "[SUKCES:] Kupi³eœ cygaro");
									
									// Businesses[i][Products]--;
									// Businesses[i][Till] += 8;
									
									// SaveBizData(i, "Products");
									// SaveBizData(i, "Till");
									// SaveStatsData("alarm", gPlayerData[playerid][pName], 8, i, Businesses[i][BizType]);

									// return 1;
								// }
								// else
								// {
									// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie masz wystarczaj¹cej iloœci pieniêdzy !");
								// }
							// }
							// if(strcmp(x_info,"alarm",true) == 0)
							// {
								// if(GetPlayerCash(playerid) >= 130)
								// {
									// if(ItemWeight(1, 11) + PItemWeight(playerid) > gPlayerData[playerid][pMaxWeight])
									// {
										// SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Jesteœ przeci¹¿ony ! Wyrzuæ jeden lub wiêcej itemów aby odci¹¿yæ Twoj¹ postaæ");
										// return 1;
									// }
									// slot = PHaveItem(playerid, 1, 11);
									// if(slot > 0)
									// {
										// SetPSlotParam6(playerid, slot, SlotParam6(playerid,slot)+1);
									// }
									// else 
									// {
										// if(InsertPlayerItemEx(playerid, 1, 11, 0, 0, 0, 0, "Puste", 1) == 0)
										// {
											// SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie masz miejsca na alarm samochodowy !");
											// return 1;
										// }
									// }
									// GivePlayerCash(playerid, -130);
									// SendClientMessage(playerid, COLOR_GREEN, "[SUKCES:] Kupi³eœ alarm samochodowy");
									
									// Businesses[i][Products]--;
									// Businesses[i][Till] += 130;
									
									// SaveBizData(i, "Products");
									// SaveBizData(i, "Till");
									// SaveStatsData("alarm", gPlayerData[playerid][pName], 130, i, Businesses[i][BizType]);

									// return 1;
								// }
								// else
								// {
									// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie masz wystarczaj¹cej iloœci pieniêdzy !");
								// }
							// }
							// if(strcmp(x_info,"linka",true) == 0)
							// {
								// if(GetPlayerCash(playerid) >= 50)
								// {	
									// if(ItemWeight(3, 8) + PItemWeight(playerid) > gPlayerData[playerid][pMaxWeight])
									// {
										// SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Jesteœ przeci¹¿ony ! Wyrzuæ jeden lub wiêcej itemów aby odci¹¿yæ Twoj¹ postaæ");
										// return 1;
									// }
									// if(InsertPlayerItem(playerid, 3, 8, 20, 0) == 0)
									// {
										// SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie masz miejsca na linke holownicz¹ !");
										// return 1;
									// }
									// GivePlayerCash(playerid, -50);
									// SendClientMessage(playerid, COLOR_GREEN, "[SUKCES:] Kupi³eœ linke holownicz¹");
									
									// Businesses[i][Products]--;
									// Businesses[i][Till] += 50;
									
									// SaveBizData(i, "Products");
									// SaveBizData(i, "Till");
									// SaveStatsData("linka", gPlayerData[playerid][pName], 50, i, Businesses[i][BizType]);

									// return 1;
								// }
								// else
								// {
									// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie masz wystarczaj¹cej iloœci pieniêdzy !");
								// }
							// }
							// if(strcmp(x_info,"hak",true) == 0)
							// {
								// if(GetPlayerCash(playerid) >= 120)
								// {
									// if(ItemWeight(1, 10) + PItemWeight(playerid) > gPlayerData[playerid][pMaxWeight])
									// {
										// SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Jesteœ przeci¹¿ony ! Wyrzuæ jeden lub wiêcej itemów aby odci¹¿yæ Twoj¹ postaæ");
										// return 1;
									// }
									// slot = PHaveItem(playerid, 1, 10);
									// if(slot > 0)
									// {
										// SetPSlotParam6(playerid, slot, SlotParam6(playerid,slot)+1);
									// }
									// else 
									// {
										// if(InsertPlayerItemEx(playerid, 1, 10, 0, 0, 0, 0, "Puste", 1) == 0)
										// {
											// SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie masz miejsca na hak holowniczy !");
											// return 1;
										// }
									// }
									// GivePlayerCash(playerid, -120);
									// SendClientMessage(playerid, COLOR_GREEN, "[SUKCES:] Kupi³eœ hak holowniczy");
									
									// Businesses[i][Products]--;
									// Businesses[i][Till] += 120;
									
									// SaveBizData(i, "Products");
									// SaveBizData(i, "Till");
									// SaveStatsData("hak", gPlayerData[playerid][pName], 120, i, Businesses[i][BizType]);

									// return 1;
								// }
								// else
								// {
									// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie masz wystarczaj¹cej iloœci pieniêdzy !");
								// }
							// }
							// if(strcmp(x_info,"zarowka",true) == 0)
							// {
								// if(GetPlayerCash(playerid) >= 60)
								// {			
									// if(ItemWeight(1, 7) + PItemWeight(playerid) > gPlayerData[playerid][pMaxWeight])
									// {
										// SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Jesteœ przeci¹¿ony ! Wyrzuæ jeden lub wiêcej itemów aby odci¹¿yæ Twoj¹ postaæ");
										// return 1;
									// }
									// slot = PHaveItem(playerid, 1, 7);
									// if(slot > 0)
									// {
										// SetPSlotParam6(playerid, slot, SlotParam6(playerid,slot)+1);
									// }
									// else 
									// {
										// if(InsertPlayerItemEx(playerid, 1, 7, 0, 0, 0, 0, "Puste", 1) == 0)
										// {
											// SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie masz miejsca na hak holowniczy !");
											// return 1;
										// }
									// }
									// GivePlayerCash(playerid, -60);
									// SendClientMessage(playerid, COLOR_GREEN, "[SUKCES:] Kupi³eœ ¿arówke");
									
									// Businesses[i][Products]--;
									// Businesses[i][Till] += 60;
									
									// SaveBizData(i, "Products");
									// SaveBizData(i, "Till");
									// SaveStatsData("zarowka", gPlayerData[playerid][pName],60, i, Businesses[i][BizType]);

									// return 1;
								// }
								// else
								// {
									// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie masz wystarczaj¹cej iloœci pieniêdzy !");
								// }
							// }
							// if(strcmp(x_info,"aparat",true) == 0)
							// {
								// if(GetPlayerCash(playerid) >= 400)
								// {										
									// GivePlayerCash(playerid, -400);
									
									// GivePlayerGun(playerid, 43, 299);
									
									// SendClientMessage(playerid, COLOR_GREEN, "[SUKCES:] Kupi³eœ aparat fotograficzny");
									
									// Businesses[i][Products]--;
									// Businesses[i][Till] += 400;
									
									// SaveBizData(i, "Products");
									// SaveBizData(i, "Till");
									// SaveStatsData("aparat", gPlayerData[playerid][pName], 400, i, Businesses[i][BizType]);

									// return 1;
								// }
								// else
								// {
									// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie masz wystarczaj¹cej iloœci pieniêdzy !");
								// }
							// }
							// if(strcmp(x_info,"plecak",true) == 0)
							// {
								// if(ItemWeight(1, 5) + PItemWeight(playerid) > gPlayerData[playerid][pMaxWeight])
									// {
										// SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Jesteœ przeci¹¿ony ! Wyrzuæ jeden lub wiêcej itemów aby odci¹¿yæ Twoj¹ postaæ");
										// return 1;
									// }
								// if(GetPlayerCash(playerid) >= 59)
								// {
									// slot = PHaveItem(playerid, 1, 5);
									// if(slot > 0)
									// {
										// SetPSlotParam6(playerid, slot, SlotParam6(playerid,slot)+1);
									// }
									// else 
									// {
										// if(InsertPlayerItemEx(playerid, 1, 5, 0, 0, 0, 0, "Puste", 1) == 0)
										// {
											// SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie masz miejsca na plecak !");
											// return 1;
										// }
									// }
									// GivePlayerCash(playerid, -59);
									// SendClientMessage(playerid, COLOR_GREEN, "[SUKCES:] Kupi³eœ plecak");
									// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Pamiêtaj, ¿e plecak jest przydatny tylko na pierwszych piêciu slotach !");
									
									// Businesses[i][Products]--;
									// Businesses[i][Till] += 59;
									
									// SaveBizData(i, "Products");
									// SaveBizData(i, "Till");
									// SaveStatsData("plecak", gPlayerData[playerid][pName], 59, i, Businesses[i][BizType]);

									// return 1;
								// }
								// else
								// {
									// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie masz wystarczaj¹cej iloœci pieniêdzy !");
								// }
							// }
							// if(strcmp(x_info,"fajerwerki",true) == 0)
							// {
								// if(GetPlayerCash(playerid) >= 100)
								// {
									// if(InsertPlayerItem(playerid, 1, 8, 0, 0) == 0)
									// {
										// SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie masz miejsca na zestaw fajerwerków !");
										// return 1;
									// }
									// GivePlayerCash(playerid, -100);
									
									// SendClientMessage(playerid, COLOR_GREEN, "[SUKCES:] Kupi³eœ zestaw fajerwerków");
									
									
									// Businesses[i][Products]--;
									// Businesses[i][Till] += 100;
									
									// SaveBizData(i, "Products");
									// SaveBizData(i, "Till");

									// return 1;
								// }
								// else
								// {
									// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie masz wystarczaj¹cej iloœci pieniêdzy !");
								// }
							// }
							// if(strcmp(x_info,"rakieta",true) == 0)
							// {
								// if(ItemWeight(1, 6) + PItemWeight(playerid) > gPlayerData[playerid][pMaxWeight])
									// {
										// SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Jesteœ przeci¹¿ony ! Wyrzuæ jeden lub wiêcej itemów aby odci¹¿yæ Twoj¹ postaæ");
										// return 1;
									// }
								// if(GetPlayerCash(playerid) >= 8)
								// {
									// slot = PHaveItem(playerid, 1, 6);
									// if(slot > 0)
									// {
										// SetPSlotParam6(playerid, slot, SlotParam6(playerid,slot)+1);
									// }
									// else 
									// {
										// if(InsertPlayerItemEx(playerid, 1, 6, 0, 0, 0, 0, "Puste", 1) == 0)
										// {
											// SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie masz miejsca na rakiete !");
											// return 1;
										// }
									// }
									// GivePlayerCash(playerid, -8);
									// SendClientMessage(playerid, COLOR_GREEN, "[SUKCES:] Kupi³eœ rakiete");
									
									// Businesses[i][Products]--;
									// Businesses[i][Till] += 8;
									
									// SaveBizData(i, "Products");
									// SaveBizData(i, "Till");
									// SaveStatsData("rakieta", gPlayerData[playerid][pName], 8, i, Businesses[i][BizType]);

									// return 1;
								// }
								// else
								// {
									// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie masz wystarczaj¹cej iloœci pieniêdzy !");
								// }
							// }
							// if(strcmp(x_info,"kanister",true) == 0)
							// {
								// if(ItemWeight(3, 1) + PItemWeight(playerid) > gPlayerData[playerid][pMaxWeight])
								// {
									// SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Jesteœ przeci¹¿ony ! Wyrzuæ jeden lub wiêcej itemów aby odci¹¿yæ Twoj¹ postaæ");
									// return 1;
								// }
								// if(GetPlayerCash(playerid) >= 190)
								// {
									// if(InsertPlayerItem(playerid, 3, 1, 0, 0) == 0)
									// {
										// SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie masz miejsca na kanister !");
										// return 1;
									// }
									// GivePlayerCash(playerid, -190);
									// SendClientMessage(playerid, COLOR_GREEN, "[SUKCES:] Kupi³eœ kanister");
									
									// Businesses[i][Products]--;
									// Businesses[i][Till] += 190;
									
									// SaveBizData(i, "Products");
									// SaveBizData(i, "Till");
									// SaveStatsData("kanister", gPlayerData[playerid][pName], 190, i, Businesses[i][BizType]);

									// return 1;
								// }
								// else
								// {
									// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie masz wystarczaj¹cej iloœci pieniêdzy !");
								// }
							// }
							// if(strcmp(x_info,"krotkofalowka",true) == 0)
							// {
								// if(ItemWeight(3, 2) + PItemWeight(playerid) > gPlayerData[playerid][pMaxWeight])
								// {
									// SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Jesteœ przeci¹¿ony ! Wyrzuæ jeden lub wiêcej itemów aby odci¹¿yæ Twoj¹ postaæ");
									// return 1;
								// }
								// if(GetPlayerCash(playerid) >= 120)
								// {
									// if(PHaveItem(playerid, 3, 2) == 0)
									// {
										// if(InsertPlayerItem(playerid, 3, 2, 0, 0) == 0)
										// {
											// SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie masz miejsca na krótkofalówke !");
											// return 1;
										// }
										// GivePlayerCash(playerid, -120);
										// SendClientMessage(playerid, COLOR_GREEN, "[SUKCES:] Kupi³eœ krótkofalówke");

										// Businesses[i][Products]--;
										// Businesses[i][Till]+= 120;

										// SaveBizData(i, "Products");
										// SaveBizData(i, "Till");
										// SaveStatsData("krotkofalowka", gPlayerData[playerid][pName], 120, i, Businesses[i][BizType]);

										// return 1;
									// }
									// else
									// {
										// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Posiadasz ju¿ krótkofalówke !");
										// return 1;
									// }
								// }
								// else
								// {
									// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie masz wystarczaj¹cej iloœci pieniêdzy !");
								// }
							// }
							// if(strcmp(x_info,"palka",true) == 0)
							// {
								// if(GetPlayerCash(playerid) >= 2)
								// {
									// GivePlayerGun(playerid,5,1);
									// GivePlayerCash(playerid,-8);

									// SendClientMessage(playerid, COLOR_GREEN, "[SUKCES:] Kupi³eœ pa³ke");

									// Businesses[i][Products]--;
									// Businesses[i][Till] += 8;

									// SaveBizData(i, "Products");
									// SaveBizData(i, "Till");
									// SaveStatsData("palka", gPlayerData[playerid][pName], 8, i, Businesses[i][BizType]);

									// return 1;
								// }
								// else
								// {
									// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie masz wystarczaj¹cej iloœci pieniêdzy !");
								// }
							// }
							// else if(strcmp(x_info,"lom",true) == 0)
							// {
								// if(ItemWeight(1, 1) + PItemWeight(playerid) > gPlayerData[playerid][pMaxWeight])
								// {
									// SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Jesteœ przeci¹¿ony ! Wyrzuæ jeden lub wiêcej itemów aby odci¹¿yæ Twoj¹ postaæ");
									// return 1;
								// }
								// if(GetPlayerCash(playerid) >= 10)
								// {
									// if(PHaveItem(playerid, 1, 1) == 0)
									// {
										// if(InsertPlayerItem(playerid, 1, 1, 0, 0) == 0)
										// {
											// SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie masz miejsca na ³om !");
											// return 1;
										// }
										// gPlayerData[playerid][JemmyUses] = 5;

										// GivePlayerCash(playerid,-15);

										// SendClientMessage(playerid, COLOR_GREEN, "[SUKCES:] Kupi³eœ ³om");

										// Businesses[i][Products]--;
										// Businesses[i][Till]+= 15;

										// SaveBizData(i, "Products");
										// SaveBizData(i, "Till");
										// SaveStatsData("lom", gPlayerData[playerid][pName], 15, i, Businesses[i][BizType]);

										// SavePlayerData(playerid, "JemmyUses");
										// return 1;
									// }
									// else
									// {
										// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Posiadasz ju¿ ³om");
										// return 1;
									// }
								// }
								// else
								// {
									// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie masz wystarczaj¹cej iloœci pieniêdzy !");
								// }
							// }
							// else if(strcmp(x_info,"lopata",true) == 0)
							// {
								// if(GetPlayerCash(playerid) >= 2)
								// {
									// GivePlayerGun(playerid,6,1);
									// GivePlayerCash(playerid,-10);
									// SendClientMessage(playerid, COLOR_GREEN, "[SUKCES:] Kupi³eœ ³opate");
									// Businesses[i][Products]--;
									// Businesses[i][Till] += 10;
									// SaveBizData(i, "Products");
									// SaveBizData(i, "Till");
									// SaveStatsData("lopata", gPlayerData[playerid][pName], 10, i, Businesses[i][BizType]);
									// return 1;
								// }
								// else
								// {
									// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie masz wystarczaj¹cej iloœci pieniêdzy !");
								// }
							// }
							// else if(strcmp(x_info,"kijbilardowy",true) == 0)
							// {
								// if(GetPlayerCash(playerid) >= 5)
								// {
									// GivePlayerGun(playerid,7,1);
									// GivePlayerCash(playerid,-5);
									// SendClientMessage(playerid, COLOR_GREEN, "[SUKCES:] Kupi³eœ kij bilardowy");
									// Businesses[i][Products]--;
									// Businesses[i][Till] += 5;
									// SaveBizData(i, "Products");
									// SaveBizData(i, "Till");
									// SaveStatsData("kijbilardowy", gPlayerData[playerid][pName], 5, i, Businesses[i][BizType]);
									// return 1;
								// }
								// else
								// {
									// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie masz wystarczaj¹cej iloœci pieniêdzy !");
								// }
							// }
							// else if(strcmp(x_info,"ksiazkatel",true) == 0)
							// {
								// if(ItemWeight(1, 4) + PItemWeight(playerid) > gPlayerData[playerid][pMaxWeight])
								// {
									// SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Jesteœ przeci¹¿ony ! Wyrzuæ jeden lub wiêcej itemów aby odci¹¿yæ Twoj¹ postaæ");
									// return 1;
								// }
								// if(GetPlayerCash(playerid) >= 25)
								// {
									// slot = PHaveItem(playerid, 1, 4);
									// if(slot > 0)
									// {
										// SetPSlotParam6(playerid, slot, SlotParam6(playerid,slot)+1);
									// }
									// else 
									// {
										// if(InsertPlayerItemEx(playerid, 1, 4, 0, 0, 0, 0, "Puste", 1) == 0)
										// {
											// SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie masz miejsca na rakiete !");
											// return 1;
										// }
									// }
									// GivePlayerCash(playerid,-25);
									// SendClientMessage(playerid, COLOR_GREEN, "[SUKCES:] Kupi³eœ ksi¹¿ke telefoniczn¹ (/ksiazkatel)");
									// Businesses[i][Products]--;
									// Businesses[i][Till] += 25;

									// SaveBizData(i, "Products");
									// SaveBizData(i, "Till");
									// SaveStatsData("ksiazkatel", gPlayerData[playerid][pName], 25, i, Businesses[i][BizType]);
									// return 1;
								// }
								// else
								// {
									// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie masz wystarczaj¹cej iloœci pieniêdzy !");
								// }
							// }
							// else if(strcmp(x_info,"kostka",true) == 0)
							// {
								// if(GetPlayerCash(playerid) >= 1)
								// {
									// GivePlayerCash(playerid,-1);
									// SendClientMessage(playerid, COLOR_GREEN, "[SUKCES:] Kupi³eœ kostke (/kostka)");
									// Businesses[i][Products]--;
									// Businesses[i][Till] += 1;
									// gDice[playerid] = 1;
									// SaveBizData(i, "Products");
									// SaveBizData(i, "Till");
									// SaveStatsData("kostka", gPlayerData[playerid][pName], 1, i, Businesses[i][BizType]);
									// return 1;
								// }
								// else
								// {
									// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie masz wystarczaj¹cej iloœci pieniêdzy !");
								// }
							// }
							// else if(strcmp(x_info,"kwiaty",true) == 0)
							// {
								// if(GetPlayerCash(playerid) >= 2)
								// {
									// GivePlayerGun(playerid,14,1);
									// GivePlayerCash(playerid,-2);
									// SendClientMessage(playerid, COLOR_GREEN, "[SUKCES:] Kupi³eœ kwiaty");
									// Businesses[i][Products]--;
									// Businesses[i][Till] += 2;
									// SaveBizData(i, "Products");
									// SaveBizData(i, "Till");
									// SaveStatsData("kwiaty", gPlayerData[playerid][pName], 2, i, Businesses[i][BizType]);
									// return 1;
								// }
								// else
								// {
									// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie masz wystarczaj¹cej iloœci pieniêdzy !");
								// }
							// }
							// else if(strcmp(x_info,"gps",true) == 0)
							// {
								// if(GetPlayerCash(playerid) >= 820)
								// {
									// gPlayerData[playerid][pGPS] = 1;

									// SavePlayerData(playerid, "GPS");

									// GivePlayerCash(playerid, -820);
									// SendClientMessage(playerid, COLOR_GREEN, "[SUKCES:] Kupi³eœ GPS /onoff gps");
									// Businesses[i][Products]--;
									// Businesses[i][Till] += 820;
									// SaveBizData(i, "Products");
									// SaveBizData(i, "Till");
									// SavePlayerData(playerid, "GPS");
									// SaveStatsData("gps", gPlayerData[playerid][pName], 820, i, Businesses[i][BizType]);
									// return 1;
								// }
								// else
								// {
									// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie masz wystarczaj¹cej iloœci pieniêdzy !");
								// }
							// }
					}
				}
			}
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Musisz znajdowaæ siê w sklepie aby u¿yæ tej komendy !");
			return 1;
		}
		// if(strcmp(cmd, "/kupubranie", true) == 0)
		// {
			// tmp = strtok(cmdtext, idx);
			// if(!strlen(tmp))
			// {
				// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /kupubranie [skinid]");
				// return 1;
			// }
			// new id = strval(tmp);
			// for(new i = 0; i < sizeof(Businesses); i++)
			// {
				// if (PlayerToPoint(25.0, playerid,Businesses[i][ExitX], Businesses[i][ExitY], Businesses[i][ExitZ]))
				// {
					// if(GetPlayerVirtualWorld(playerid) == i)
					// {
						// if(Businesses[i][BizType] == 6)
						// {
							// if(Businesses[i][Products] != 0)
							// {
								// if(GetPlayerCash(playerid) >= 80)
								// {
									// if(IsACopSkin(id) == 0)
									// {
										// if(IsValidSkin(id))
										// {
											// SetPlayerSkin(playerid,id);
											// GivePlayerCash(playerid,-80);
											// gPlayerData[playerid][pSkin] = id;
											// Businesses[i][Products]--;
											// Businesses[i][Till]+=80;
											// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ubranie kupione, $-80.");
											// SaveBizData(i, "Products");
											// SaveBizData(i, "Till");
											// SavePlayerData(playerid, "Skin");
											// SaveStatsData("ubranie", gPlayerData[playerid][pName], 80, i, Businesses[i][BizType]);
											// return 1;
										// }
									// }
									// else
									// {
										// SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz zakupiæ stroju mundurowego");
										// return 1;
									// }
								// }
								// else
								// {
									// SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie masz wystarczaj¹co du¿o pieniêdzy na ubranie" );
									// return 1;
								// }
							// }
						// }
					// }
				// }
			// }
			// SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Aby kupiæ ubranie musisz udaæ siê do sklepu !");
			// return 1;
		// }
		if(strcmp(cmd, "/kuptel", true) == 0)
		{
			for(new i = 0; i < sizeof(Businesses); i++)
			{
				if (PlayerToPoint(25.0, playerid,Businesses[i][ExitX], Businesses[i][ExitY], Businesses[i][ExitZ]))
				{
					if(GetPlayerVirtualWorld(playerid) == i)
					{
						if(Businesses[i][BizType] == 2)
						{
							if(Businesses[i][Products] > 0)
							{
								ShowPlayerDialog(playerid,8,DIALOG_STYLE_LIST,"Telefony","1. Telefon bez radia (650$)","Kup","Anuluj");
								return 1;
							}
							else
							{
								SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Brak telefonów na stanie !");
								return 1;
							}
						}
					}
				}
			}
			return 1;
		}
		if(strcmp(cmd,"/kupdrink",true)==0)
		{
			new x_info[256];
			new Float:HP;
			for(new i = 0; i < sizeof(Businesses); i++)
			{
				if (PlayerToPoint(200.0, playerid,Businesses[i][ExitX], Businesses[i][ExitY], Businesses[i][ExitZ]))
				{
					if(GetPlayerVirtualWorld(playerid) == i)
					{
						if(Businesses[i][BizType] == 7)
						{
							x_info = strtok(cmdtext, idx);

							// TODO: Add posibility to change prices and fix giving/taking prices
							if(!strlen(x_info)) {
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /kupdrink [item]");
								SendClientMessage(playerid, COLOR_WHITE, "[ITEM:] Piwo - Cena: $7.");
								SendClientMessage(playerid, COLOR_WHITE, "[ITEM:] Vodka - Cena: $10.");
								SendClientMessage(playerid, COLOR_WHITE, "[ITEM:] Cola - Cena: $3.");
								SendClientMessage(playerid, COLOR_WHITE, "[ITEM:] Woda - Cena: $3.");
								SendClientMessage(playerid, COLOR_WHITE, "[ITEM:] Whiskey - Cena: $10.");
								SendClientMessage(playerid, COLOR_WHITE, "[ITEM:] Brandy - Cena: $15.");
								SendClientMessage(playerid, COLOR_WHITE, "[ITEM:] Soda - Cena: $3.");
								return 1;
							}
							if(Businesses[i][Products] != 0)
							{
								GetPlayerHealth(playerid,HP);
								if(strcmp(x_info,"piwo",true) == 0)
								{
									if(GetPlayerCash(playerid) >= 7)
									{
										GivePlayerCash(playerid,-7);
										Businesses[i][Till] += 11;
										Businesses[i][Products]--;
										if(HP <= 100)
										{
											SetPlayerHealth(playerid,HP+15.0);
										}
										SetPlayerSpecialAction(playerid,SPECIAL_ACTION_DRINK_BEER);
										SaveBizData(i, "Products");
										SaveBizData(i, "Till");
										return 1;
									}
									else
									{
										SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie masz wystarczaj¹cej iloœci pieniêdzy.");
										return 1;
									}
								}
								if(strcmp(x_info,"vodka",true) == 0)
								{
									if(GetPlayerCash(playerid) >= 10)
									{
										GivePlayerCash(playerid,-10);
										Businesses[i][Till] += 15;
										Businesses[i][Products]--;
										if(HP <= 100)
										{
											SetPlayerHealth(playerid,HP+20.0);
										}
										SetPlayerSpecialAction(playerid,SPECIAL_ACTION_DRINK_WINE);
										SaveBizData(i, "Products");
										SaveBizData(i, "Till");
										return 1;
									}
									else
									{
										SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie masz wystarczaj¹cej iloœci pieniêdzy.");
										return 1;
									}
								}
								if(strcmp(x_info,"cola",true) == 0)
								{
									if(GetPlayerCash(playerid) >= 3)
									{
										GivePlayerCash(playerid,-3);
										Businesses[i][Till] += 5;
										Businesses[i][Products]--;
										if(HP <= 100)
										{
											SetPlayerHealth(playerid,HP+2.0);
										}
										SetPlayerSpecialAction(playerid,SPECIAL_ACTION_DRINK_SPRUNK);
										SaveBizData(i, "Products");
										SaveBizData(i, "Till");
										return 1;
									}
									else
									{
										SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie masz wystarczaj¹cej iloœci pieniêdzy.");
										return 1;
									}
								}
								if(strcmp(x_info,"woda",true) == 0)
								{
									if(GetPlayerCash(playerid) >= 1)
									{
										GivePlayerCash(playerid,-1);
										Businesses[i][Till] += 2;
										Businesses[i][Products]--;
										if(HP < 100)
										{
											SetPlayerHealth(playerid,HP+1.0);
										}
										SetPlayerSpecialAction(playerid,SPECIAL_ACTION_DRINK_SPRUNK);
										SaveBizData(i, "Products");
										SaveBizData(i, "Till");
										return 1;
									}
									else
									{
										SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie masz wystarczaj¹cej iloœci pieniêdzy.");
										return 1;
									}
								}
								if(strcmp(x_info,"whiskey",true) == 0)
								{
									if(GetPlayerCash(playerid) >= 10)
									{
										GivePlayerCash(playerid,-10);
										Businesses[i][Till] += 15;
										Businesses[i][Products]--;
										if(HP <= 100)
										{
											SetPlayerHealth(playerid,HP+20.0);
										}
										SaveBizData(i, "Products");
										SaveBizData(i, "Till");
										SetPlayerSpecialAction(playerid,SPECIAL_ACTION_DRINK_WINE);
										return 1;
									}
									else
									{
										SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie masz wystarczaj¹cej iloœci pieniêdzy.");
										return 1;
									}
								}
								if(strcmp(x_info,"brandy",true) == 0)
								{
									if(GetPlayerCash(playerid) >= 15)
									{
										GivePlayerCash(playerid,-15);
										Businesses[i][Till] += 23;
										Businesses[i][Products]--;
										if(HP <= 100)
										{
											SetPlayerHealth(playerid,HP+25.0);
										}
										SetPlayerSpecialAction(playerid,SPECIAL_ACTION_DRINK_WINE);
										SaveBizData(i, "Products");
										SaveBizData(i, "Till");
										return 1;
									}
									else
									{
										SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie masz wystarczaj¹cej iloœci pieniêdzy.");
										return 1;
									}
								}
								if(strcmp(x_info,"soda",true) == 0)
								{
									if(GetPlayerCash(playerid) >= 3)
									{
										GivePlayerCash(playerid,-3);
										Businesses[i][Till] += 5;
										Businesses[i][Products]--;
										if(HP < 100)
										{
											SetPlayerHealth(playerid,HP+2.0);
										}
										SetPlayerSpecialAction(playerid,SPECIAL_ACTION_DRINK_SPRUNK);
										SaveBizData(i, "Products");
										SaveBizData(i, "Till");
										return 1;
									}
									else
									{
										SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie masz wystarczaj¹cej iloœci pieniêdzy.");
										return 1;
									}
								}
							}
							else
							{
								SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Niestety nie posiadamy ju¿ drinków !");
								return 1;
							}
						}
					}
				}
			}
			return 1;
		}
		if(strcmp(cmd, "/jedz", true) == 0)
		{
			for(new i = 0; i < sizeof(Businesses); i++)
			{
				if(PlayerToPoint(25.0, playerid,Businesses[i][ExitX], Businesses[i][ExitY], Businesses[i][ExitZ]))
				{
					if(GetPlayerVirtualWorld(playerid) == i)
					{
						if(Businesses[i][BizType] == 1)
						{
							if(Businesses[i][Products] != 0)
							{
								if(GetPlayerCash(playerid) >= 15)
								{
									if( IsPlayerInDynamicCP( playerid, gEatCP2 ) || IsPlayerInDynamicCP( playerid, gEatCP3 ) ) //Burger Shot
									{
										SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"____________________________________________________");
										SendClientMessage(playerid,COLOR_WHITE,"[INFO:] Zjad³eœ hamburgera z frytkami. -$15");

										GivePlayerCash(playerid,-15);

										Businesses[i][Till] += 15;
										Businesses[i][Products]--;

										ApplyAnimation(playerid,"FOOD","EAT_Burger",2.0,0,1,1,0,0);
										
										gPlayerData[playerid][pSubMealEaten] = 0;
										SavePlayerData( playerid, "SubMealEaten" );
										
										gPlayerData[playerid][pHunger] += 35.0;
										if( gPlayerData[playerid][pVipAFK] == 1 || gPlayerData[playerid][pVipAFKT] > 0 && gPlayerData[playerid][pHunger] > 150.0 )
											gPlayerData[playerid][pHunger] = 150.0;
										else if( gPlayerData[playerid][pVipAFK] != 1 && gPlayerData[playerid][pVipAFKT] <= 0 && gPlayerData[playerid][pHunger] > 100.0 )
											gPlayerData[playerid][pHunger] = 100.0;
										SavePlayerData( playerid, "Hunger" );
										SetProgressBarValue( gPlayerData[playerid][pHungerProgressBarID], gPlayerData[playerid][pHunger] );
										UpdateProgressBar( gPlayerData[playerid][pHungerProgressBarID], playerid );
										
										SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"____________________________________________________");

										SaveBizData(i, "Products");
										SaveBizData(i, "Till");
										SaveStatsData("hamburger i frytki", gPlayerData[playerid][pName], 15, i, Businesses[i][BizType]);
										return 1;
									}
									else if( IsPlayerInDynamicCP( playerid, gEatCP4 ) || IsPlayerInDynamicCP( playerid, gEatCP5 ) )//Cluckin Bell
									{
										SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"____________________________________________________");
										SendClientMessage(playerid,COLOR_WHITE,"[INFO:] Zjad³eœ chickenburgera z frytkami. -$15");

										GivePlayerCash(playerid,-15);

										Businesses[i][Till] += 15;
										Businesses[i][Products]--;
										
										ApplyAnimation(playerid,"FOOD","EAT_Chicken",2.0,0,1,1,0,0);

										gPlayerData[playerid][pSubMealEaten] = 0;
										SavePlayerData( playerid, "SubMealEaten" );
										
										gPlayerData[playerid][pHunger] += 35.0;
										if( gPlayerData[playerid][pVipAFK] == 1 || gPlayerData[playerid][pVipAFKT] > 0 && gPlayerData[playerid][pHunger] > 150.0 )
											gPlayerData[playerid][pHunger] = 150.0;
										else if( gPlayerData[playerid][pVipAFK] != 1 && gPlayerData[playerid][pVipAFKT] <= 0 && gPlayerData[playerid][pHunger] > 100.0 )
											gPlayerData[playerid][pHunger] = 100.0;
										SavePlayerData( playerid, "Hunger" );
										SetProgressBarValue( gPlayerData[playerid][pHungerProgressBarID], gPlayerData[playerid][pHunger] );
										UpdateProgressBar( gPlayerData[playerid][pHungerProgressBarID], playerid );

										SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"____________________________________________________");

										SaveBizData(i, "Products");
										SaveBizData(i, "Till");
										SaveStatsData("chickenburger i frytki", gPlayerData[playerid][pName], 15, i, Businesses[i][BizType]);
										return 1;
									}
									else if( IsPlayerInDynamicCP( playerid, gEatCP6 ) || IsPlayerInDynamicCP( playerid, gEatCP7 ) || IsPlayerInDynamicCP( playerid, gEatCP8 ) )//Well Stacked Pizza
									{
										SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"____________________________________________________");
										SendClientMessage(playerid,COLOR_WHITE,"[INFO:] Zjad³eœ pizze i wypi³eœ du¿¹ Cole. -$25");

										GivePlayerCash(playerid,-25);

										Businesses[i][Till] += 25;
										Businesses[i][Products]--;
										
										ApplyAnimation(playerid,"FOOD","EAT_Pizza",2.0,0,1,1,0,0);

										gPlayerData[playerid][pSubMealEaten] = 0;
										SavePlayerData( playerid, "SubMealEaten" );
										
										gPlayerData[playerid][pHunger] += 45.0;
										if( gPlayerData[playerid][pVipAFK] == 1 || gPlayerData[playerid][pVipAFKT] > 0 && gPlayerData[playerid][pHunger] > 150.0 )
											gPlayerData[playerid][pHunger] = 150.0;
										else if( gPlayerData[playerid][pVipAFK] != 1 && gPlayerData[playerid][pVipAFKT] <= 0 && gPlayerData[playerid][pHunger] > 100.0 )
											gPlayerData[playerid][pHunger] = 100.0;
										SavePlayerData( playerid, "Hunger" );
										SetProgressBarValue( gPlayerData[playerid][pHungerProgressBarID], gPlayerData[playerid][pHunger] );
										UpdateProgressBar( gPlayerData[playerid][pHungerProgressBarID], playerid );

										SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"____________________________________________________");

										SaveBizData(i, "Products");
										SaveBizData(i, "Till");
										SaveStatsData("pizza i cola", gPlayerData[playerid][pName], 25, i, Businesses[i][BizType]);
										return 1;
									}
									else if( IsPlayerInDynamicCP( playerid, gEatCP9 ) )//Rusty Browns Dohnuts
									{
										SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"____________________________________________________");
										SendClientMessage(playerid,COLOR_WHITE,"[INFO:] Zjad³eœ dwa p¹czki i wypi³eœ du¿ego drinka. -$15");

										GivePlayerCash(playerid,-15);

										Businesses[i][Till] += 15;
										Businesses[i][Products]--;
										
										ApplyAnimation(playerid,"FOOD","EAT_Burger",2.0,0,1,1,0,0);

										gPlayerData[playerid][pSubMealEaten] = 0;
										SavePlayerData( playerid, "SubMealEaten" );
										
										gPlayerData[playerid][pHunger] += 35.0;
										if( gPlayerData[playerid][pVipAFK] == 1 || gPlayerData[playerid][pVipAFKT] > 0 && gPlayerData[playerid][pHunger] > 150.0 )
											gPlayerData[playerid][pHunger] = 150.0;
										else if( gPlayerData[playerid][pVipAFK] != 1 && gPlayerData[playerid][pVipAFKT] <= 0 && gPlayerData[playerid][pHunger] > 100.0 )
											gPlayerData[playerid][pHunger] = 100.0;
										SavePlayerData( playerid, "Hunger" );
										SetProgressBarValue( gPlayerData[playerid][pHungerProgressBarID], gPlayerData[playerid][pHunger] );
										UpdateProgressBar( gPlayerData[playerid][pHungerProgressBarID], playerid );

										SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"____________________________________________________");

										SaveBizData(i, "Products");
										SaveBizData(i, "Till");
										return 1;
									}
									else if( IsPlayerInDynamicCP( playerid, gEatCP1 ) )
									{
										SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"____________________________________________________");
										SendClientMessage(playerid,COLOR_WHITE,"[INFO:] Przek¹si³eœ coœ. -$10");

										GivePlayerCash(playerid,-10);

										Businesses[i][Till] += 10;
										Businesses[i][Products]--;
										
										ApplyAnimation(playerid,"FOOD","EAT_Burger",2.0,0,1,1,0,0);

										gPlayerData[playerid][pSubMealEaten] = 0;
										SavePlayerData( playerid, "SubMealEaten" );
										
										gPlayerData[playerid][pHunger] += 10.0;
										if( gPlayerData[playerid][pVipAFK] == 1 || gPlayerData[playerid][pVipAFKT] > 0 && gPlayerData[playerid][pHunger] > 150.0 )
											gPlayerData[playerid][pHunger] = 150.0;
										else if( gPlayerData[playerid][pVipAFK] != 1 && gPlayerData[playerid][pVipAFKT] <= 0 && gPlayerData[playerid][pHunger] > 100.0 )
											gPlayerData[playerid][pHunger] = 100.0;
										SavePlayerData( playerid, "Hunger" );
										SetProgressBarValue( gPlayerData[playerid][pHungerProgressBarID], gPlayerData[playerid][pHunger] );
										UpdateProgressBar( gPlayerData[playerid][pHungerProgressBarID], playerid );
										
										SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"____________________________________________________");

										SaveBizData(i, "Products");
										SaveBizData(i, "Till");
										return 1;
									}
								}
							}
							else
							{
								SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Brak produktów !");
								return 1;
							}
						}
					}
				}	
			}
			new slot = PHaveItem(playerid, 1, 9);
			if(slot == 0)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Aby coœ zjeœæ musisz udaæ siê do jednej z restauracja/pubu");
			}
			else
			{
				RemovePlayerItemExUsed(playerid, slot);
		
				if( gPlayerData[playerid][pSubMealEaten] > MAX_SUBMEALS )
				{
					ApplyAnimation(playerid, "FOOD", "EAT_Vomit_P", 4.1, 0, 1, 1, 0, 0);
					gPlayerData[playerid][pHP] -= MAX_SUBMEALS_HP_LOSS;
					SavePlayerData( playerid, "HP" );
					SetPlayerHealth( playerid, gPlayerData[playerid][pHP] );
					SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz ¿ywiæ siê wy³¹cznie przek¹skami ! Odczuwasz ból ¿o³¹dka..." );
				}
				gPlayerData[playerid][pSubMealEaten] += 10;
				SavePlayerData( playerid, "SubMealEaten" );
				gPlayerData[playerid][pHunger] += 8.0;
				if( ( gPlayerData[playerid][pVipAFK] == 1 || gPlayerData[playerid][pVipAFKT] > 0 ) && gPlayerData[playerid][pHunger] > 150.0 )
					gPlayerData[playerid][pHunger] = 150.0;
				else if( ( gPlayerData[playerid][pVipAFK] != 1 && gPlayerData[playerid][pVipAFKT] <= 0 ) && gPlayerData[playerid][pHunger] > 100.0 )
					gPlayerData[playerid][pHunger] = 100.0;
				SavePlayerData( playerid, "Hunger" );
				SetProgressBarValue( gPlayerData[playerid][pHungerProgressBarID], gPlayerData[playerid][pHunger] );
				UpdateProgressBar( gPlayerData[playerid][pHungerProgressBarID], playerid );
				
				PlayerActionMessage(playerid,15.0,"zjada batona");
			}
			return 1;
		}
		if(strcmp(cmd, "/fweznarkotyki", true) == 0)
		{
			if(IsPlayerConnected(playerid))
			{
				new playername[MAX_PLAYER_NAME];
				GetPlayerName(playerid, playername, sizeof(playername));
				new bouse = gPlayerData[playerid][pFaction];
				if(gPlayerData[playerid][pFaction] != 255 && DynamicFactions[gPlayerData[playerid][pFaction]][fType] != 1)
				{
					tmp = strtok(cmdtext, idx);
					if(!strlen(tmp))
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /fweznarkotyki [iloœæ]");
						return 1;
					}
					new materialsdeposit = strval(tmp);
					if(!strlen(tmp))
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /fweznarkotyki [iloœæ]");
						return 1;
					}
					if(gPlayerData[playerid][pRank] == 1)
					{
						if (PlayerToPoint(1.0, playerid,FactionDrugsStorage[X],FactionDrugsStorage[Y],FactionDrugsStorage[Z]))
						{
							if(DynamicFactions[bouse][fDrugs] >= materialsdeposit)
							{
								gPlayerData[playerid][pDrugs] += materialsdeposit;
								DynamicFactions[bouse][fDrugs]=DynamicFactions[bouse][fDrugs]-materialsdeposit;
								format(string, sizeof(string), "[INFO:] Wzi¹³eœ %d narkotyków z magazynu, nowa iloœæ: %d ", materialsdeposit,DynamicFactions[bouse][fDrugs]);
								SendClientMessage(playerid, COLOR_WHITE, string);
								PlayerActionMessage(playerid,15.0,"zabra³ narkotyki z magazynu");
								format(string, sizeof(string), "[FRAKCJA:] %s wzi¹³ %d wzi¹³ narkotyki z magazynu.",GetPlayerNameEx(playerid),materialsdeposit);
								SendFactionMessage(gPlayerData[playerid][pFaction], COLOR_FACTIONCHAT, string);
								SaveFData(bouse, "Drugs");
								return 1;
							}
							else
							{
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie ma tylu narkotyków w magazynie !");
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie jesteœ w magazynie frakcji !");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie jesteœ liderem frakcji !");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie nale¿ysz do frakcji !");
				}
			}
			return 1;
		}
		if(strcmp(cmd, "/fodloznarkotyki", true) == 0)
		{
			if(IsPlayerConnected(playerid))
			{
				new playername[MAX_PLAYER_NAME];
				GetPlayerName(playerid, playername, sizeof(playername));
				new bouse = gPlayerData[playerid][pFaction];
				if(gPlayerData[playerid][pFaction] != 255 && DynamicFactions[gPlayerData[playerid][pFaction]][fType] != 1)
				{
					tmp = strtok(cmdtext, idx);
					if(!strlen(tmp))
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /fodloznarkotyki [iloœæ]");
						return 1;
					}
					new materialsdeposit = strval(tmp);
					if(!strlen(tmp))
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /fodloznarkotyki [iloœæ]");
						return 1;
					}
					if (PlayerToPoint(1.0, playerid,FactionDrugsStorage[X],FactionDrugsStorage[Y],FactionDrugsStorage[Z]))
					{
						if(gPlayerData[playerid][pDrugs] >= materialsdeposit)
						{
							gPlayerData[playerid][pDrugs] -= materialsdeposit;

							SavePlayerData(playerid, "Drugs");

							DynamicFactions[bouse][fDrugs]=DynamicFactions[bouse][fDrugs]+materialsdeposit;
							format(string, sizeof(string), "[INFO:] Od³o¿y³eœ %d narkotyków do magazynu frakcji, nowy stan: %d ", materialsdeposit,DynamicFactions[bouse][fDrugs]);
							SendClientMessage(playerid, COLOR_WHITE, string);
							format(string, sizeof(string), "[FACTION:] %s od³o¿y³ %d narkotyków do magazynu frakcji.",GetPlayerNameEx(playerid),materialsdeposit);
							SendFactionMessage(gPlayerData[playerid][pFaction], COLOR_FACTIONCHAT, string);
							SaveFData(bouse, "Drugs");
							return 1;
						}
						else
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie posiadasz tylu narkotyków !");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie jesteœ w magazynie frakcji!");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Niew³aœciwa frakcja.");
				}
			}
			return 1;
		}
		if(strcmp(cmd, "/fwezmaterialy", true) == 0)
		{
			if(IsPlayerConnected(playerid))
			{
				new playername[MAX_PLAYER_NAME];
				GetPlayerName(playerid, playername, sizeof(playername));
				new bouse = gPlayerData[playerid][pFaction];
				if(gPlayerData[playerid][pFaction] != 255 && DynamicFactions[gPlayerData[playerid][pFaction]][fType] != 1)
				{
					tmp = strtok(cmdtext, idx);
					if(!strlen(tmp))
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /fwezmaterialy [iloœæ]");
						return 1;
					}
					new materialsdeposit = strval(tmp);
					if(!strlen(tmp))
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /fwezmaterialy [iloœæ]");
						return 1;
					}
					if(gPlayerData[playerid][pRank] == 1)
					{
						if (PlayerToPoint(1.0, playerid,FactionMaterialsStorage[X],FactionMaterialsStorage[Y],FactionMaterialsStorage[Z]))
						{
							if(DynamicFactions[bouse][fMaterials] >= materialsdeposit)
							{
								gPlayerData[playerid][pMaterials] += materialsdeposit;

								SavePlayerData(playerid, "Materials");

								DynamicFactions[bouse][fMaterials]=DynamicFactions[bouse][fMaterials]-materialsdeposit;
								format(string, sizeof(string), "[INFO:] Wzi¹³eœ %d materia³ów z magazynu frakcji, nowy stan: %d ", materialsdeposit,DynamicFactions[bouse][fMaterials]);
								SendClientMessage(playerid, COLOR_WHITE, string);
								format(string, sizeof(string), "[FACTION:] %s wzi¹³ %d materia³ów z magazynu frakcji.",GetPlayerNameEx(playerid),materialsdeposit);
								SendFactionMessage(gPlayerData[playerid][pFaction], COLOR_FACTIONCHAT, string);
								SaveFData(bouse, "Materials");
								return 1;
							}
							else
							{
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie ma tyle materia³ów w magazynie !");
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie jesteœ w magazynie frakcji !");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie jesteœ liderem frakcji !");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie nale¿ysz do frakcji !");
				}
			}
			return 1;
		}
		if(strcmp(cmd, "/fodlozmaterialy", true) == 0)
		{
			if(IsPlayerConnected(playerid))
			{
				new playername[MAX_PLAYER_NAME];
				GetPlayerName(playerid, playername, sizeof(playername));
				new bouse = gPlayerData[playerid][pFaction];
				if(gPlayerData[playerid][pFaction] != 255 && DynamicFactions[gPlayerData[playerid][pFaction]][fType] != 1)
				{
					tmp = strtok(cmdtext, idx);
					if(!strlen(tmp))
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /fodlozmaterialy [iloœæ]");
						return 1;
					}
					new materialsdeposit = strval(tmp);
					if(!strlen(tmp))
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /fodlozmaterialy [iloœæ]");
						return 1;
					}
					if (PlayerToPoint(1.0, playerid,FactionMaterialsStorage[X],FactionMaterialsStorage[Y],FactionMaterialsStorage[Z]))
					{
						if(gPlayerData[playerid][pMaterials] >= materialsdeposit)
						{
							gPlayerData[playerid][pMaterials] -= materialsdeposit;

							SavePlayerData(playerid, "Materials");

							DynamicFactions[bouse][fMaterials]=DynamicFactions[bouse][fMaterials]+materialsdeposit;
							format(string, sizeof(string), "[INFO:] Od³o¿y³eœ %d materia³ów do magazynu frakcji, iloœæ materia³ów: %d ", materialsdeposit,DynamicFactions[bouse][fMaterials]);
							SendClientMessage(playerid, COLOR_WHITE, string);
							format(string, sizeof(string), "[FACTION:] %s od³o¿y³ %d materia³ów do magazynu frakcji.",GetPlayerNameEx(playerid),materialsdeposit);
							SendFactionMessage(gPlayerData[playerid][pFaction], COLOR_FACTIONCHAT, string);
							SaveFData(bouse, "Materials");
							return 1;
						}
						else
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie masz tyle materia³ów !");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie jesteœ w magazynie frakcji !");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Niew³aœciwa frakcja.");
				}
			}
			return 1;
		}
		if(strcmp(cmd, "/sprzedajdom", true) == 0)
		{
			new slot;
			new playername[128];
			GetPlayerName(playerid, playername, sizeof(playername));
			for(new i = 0; i < sizeof(Houses); i++)
			{
				if(!PlayerToPoint(3.0, playerid,Houses[i][EnterX], Houses[i][EnterY], Houses[i][EnterZ]))
				{
					continue;
				}
				slot = PHaveItem(playerid, 4, i);
				if(slot == 0)
				{
					SendClientMessage(playerid,COLOR_RED,"[INFO:] Nie posiadasz kluczy do tego domu !");
					return 1;
				}					
				if(strcmp(gPlayerData[playerid][pName], Houses[i][Owner], false) != 0)
				{
					SendClientMessage(playerid, COLOR_RED, "[INFO:] Ten dom nie jest twoj¹ w³asnoœci¹, nie mo¿esz go sprzedaæ !");
					return 1;
				}
				
				ResetHouseData(i, 1);
				
				GivePlayerCash(playerid,Houses[i][HousePrice]);

				PlayerPlaySound(playerid, 1052, 0.0, 0.0, 0.0);

				format(string, sizeof(string), "[INFO:] Sprzeda³eœ dom za $%d.", Houses[i][HousePrice]);
				SendClientMessage(playerid, COLOR_LIGHTBLUE, string);

				Houses[i][PickupID] = ChangePickupModel(Houses[i][PickupID], 1273, Houses[i][EnterX], Houses[i][EnterY], Houses[i][EnterZ]);

				new houselocation[MAX_ZONE_NAME];
				GetCoords2DZone(Houses[i][EnterX],Houses[i][EnterY], houselocation, MAX_ZONE_NAME);

				format(string, sizeof(string), "Ten dom jest na sprzedaz!");
				UpdateDynamic3DTextLabelText(Houses3DTextLabelA[i], COLOR_LIGHTYELLOW2, string);

				format(string, sizeof(string), "Adres: %d %s",i,houselocation);
				UpdateDynamic3DTextLabelText(Houses3DTextLabelB[i], COLOR_LIGHTYELLOW2, string);

				format(string, sizeof(string), "Opis: %s, Cena: $%d",Houses[i][Description],Houses[i][HousePrice]);
				UpdateDynamic3DTextLabelText(Houses3DTextLabelC[i], COLOR_LIGHTYELLOW2, string);

				format(string, sizeof(string), "[GOVERNMENT:] House id: %d, sold for: %d$, by %s", i, Houses[i][HousePrice], GetPlayerNameEx(playerid));
				print(string);
				GovermentLog(string);

				RemovePlayerItemExUsed(playerid, slot);

				return 1;
			}
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Musisz byæ przed wejœciem do domu aby go sprzedaæ !");
			return 1;
		}
		if(strcmp(cmd, "/otworzdom", true) == 0 || strcmp(cmd, "/otworzgaraz") == 0)
		{
			for(new i = 0; i < sizeof(Houses); i++)
			{
				if (PlayerToPoint(3.0, playerid,Houses[i][EnterX], Houses[i][EnterY], Houses[i][EnterZ]) && GetPlayerVirtualWorld(playerid) == 0 || (PlayerToPoint(3.0, playerid,Houses[i][ExitX], Houses[i][ExitY], Houses[i][ExitZ]) && GetPlayerVirtualWorld(playerid) == i))
				{
					if(PHaveItem(playerid, 4, i) > 0)
					{
						if(Houses[i][Locked] == 1)
						{
							Houses[i][Locked] = 0;
							if( Houses[i][HouseType] == 0 )
							{
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2,"[INFO:] Drzwi otwarte.");
								PlayerActionMessage(playerid, 20.0, "wyjmuje klucz i wk³ada go do drzwi, przekrêca raz a nastêpnie go wyjmuje");
							}
							else
							{
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2,"[INFO:] Gara¿ otwarty.");
								PlayerActionMessage(playerid, 20.0, "wciska pilot od drzwi gara¿owych");
							}

							SaveHouseData(i, "Locked");

							return 1;
						}
						if(Houses[i][Locked] == 0)
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2,"[INFO:] Gara¿ jest ju¿ otwarty !");
							PlayerActionMessage(playerid, 20.0, "wciska pilot od drzwi gara¿owych");

							return 1;
						}
					}
					else
					{
						if( Houses[i][HouseType] == 0 )
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2,"[B£¥D:] Nie masz kluczy do tego domu !");
						else
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2,"[B£¥D:] Nie masz kluczy do tego gara¿u !");
						PlayerActionMessage(playerid, 20.0, "przeszukuje kieszenie");

						return 1;
					}
				}
			}
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2,"[B£¥D:] Nie jesteœ ko³o drzwi !");
			PlayerActionMessage(playerid, 20.0, "rozgl¹da siê");
			return 1;
		}
		if(strcmp(cmd, "/zamknijdom", true) == 0 || strcmp(cmd, "/zamknijgaraz") == 0)
		{
			for(new i = 0; i < sizeof(Houses); i++)
			{
				if (PlayerToPoint(3.0, playerid,Houses[i][EnterX], Houses[i][EnterY], Houses[i][EnterZ]) && GetPlayerVirtualWorld(playerid) == 0 || (PlayerToPoint(3.0, playerid,Houses[i][ExitX], Houses[i][ExitY], Houses[i][ExitZ]) && i == GetPlayerVirtualWorld(playerid)))
				{
					if(PHaveItem(playerid, 4, i) > 0)
					{
						if(Houses[i][Locked] == 1)
						{
							if( Houses[i][HouseType] == 0 )
							{
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Drzwi s¹ ju¿ zamkniête !");
								PlayerActionMessage(playerid, 20.0, "wyjmuje klucz i wk³ada go do drzwi, próbuje przekrêciæ nastêpnie go wyjmuje");
							}
							else
							{
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Gara¿ jest ju¿ zamkniêty !");
								PlayerActionMessage(playerid, 20.0, "wciska pilot od drzwi gara¿owych");
							}
							return 1;
						}
						else
						{
							Houses[i][Locked] = 1;
							
							if( Houses[i][HouseType] == 0 )
							{
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Drzwi zosta³y zamkniête.");
								PlayerActionMessage(playerid, 20.0, "wyjmuje klucz i wk³ada go do drzwi, przekrêca raz a nastêpnie go wyjmuje");
							}
							else
							{
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Gara¿ zosta³ zamkniêty");
								PlayerActionMessage(playerid, 20.0, "wciska pilot od drzwi gara¿owych");
							}

							SaveHouseData(i, "Locked");

							return 1;
						}
					}
					else
					{
						if( Houses[i][HouseType] == 0 )
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2,"[B£¥D:] Nie masz kluczy do tego domu !");
						else
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie masz kluczy od tego gara¿u !");
						PlayerActionMessage(playerid, 20.0, "przeszukuje kieszenie");

						return 1;
					}
				}
			}
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2,"[B£¥D:] Nie jesteœ ko³o drzwi !");
			PlayerActionMessage(playerid, 20.0, "rozgl¹da siê");
			return 1;
		}
		if(strcmp(cmd, "/otworzbiznes", true) == 0)
		{
			for(new i = 0; i < sizeof(Businesses); i++)
			{
				if (PlayerToPoint(3.0, playerid,Businesses[i][EnterX], Businesses[i][EnterY], Businesses[i][EnterZ]) && GetPlayerVirtualWorld(playerid) == 0 || PlayerToPoint(3.0, playerid,Businesses[i][ExitX], Businesses[i][ExitY], Businesses[i][ExitZ]) && GetPlayerVirtualWorld(playerid) == i)
				{
					if(gPlayerData[playerid][pBizKey] == i)
					{
						if(Businesses[i][Locked] == 1)
						{
							Businesses[i][Locked] = 0;

							SendClientMessage(playerid, COLOR_LIGHTYELLOW2,"[INFO:] Drzwi otwarte.");
							PlayerActionMessage(playerid, 20.0, "wyjmuje klucz i wk³ada go do drzwi, przekrêca raz a nastêpnie go wyjmuje");

							SaveBizData(i, "Locked");

							return 1;
						}
						if(Businesses[i][Locked] == 0)
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2,"[INFO:] Drzwi s¹ ju¿ otwarte !");
							PlayerActionMessage(playerid, 20.0, "wyjmuje klucz i wk³ada go do drzwi, próbuje przekrêciæ nastêpnie go wyjmuje");

							return 1;
						}
					}
					else
					{
						if(AdminDuty[playerid])
						{
							format(string, sizeof(string), "[INFO:] Biznes id %d", i);
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
						}
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2,"[B£¥D:] Nie masz kluczy do tego biznesu !");
						PlayerActionMessage(playerid, 20.0, "przeszukuje kieszenie");
						return 1;
					}
				}
			}
			return 1;
		}
		if(strcmp(cmd, "/zamknijbiznes", true) == 0)
		{
			if(IsPlayerConnected(playerid))
			{
				for(new i = 0; i < sizeof(Businesses); i++)
				{
					if (PlayerToPoint(3.0, playerid,Businesses[i][EnterX], Businesses[i][EnterY], Businesses[i][EnterZ]) && GetPlayerVirtualWorld(playerid) == 0 || (PlayerToPoint(3.0, playerid,Businesses[i][ExitX], Businesses[i][ExitY], Businesses[i][ExitZ]) && i == GetPlayerVirtualWorld(playerid)))
					{
						if(gPlayerData[playerid][pBizKey] == i)
						{
							if(Businesses[i][Locked] == 1)
							{
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2,"[INFO:] Drzwi s¹ ju¿ zamkniête !");
								PlayerActionMessage(playerid, 20.0, "wyjmuje klucz i wk³ada go do drzwi, próbuje przekrêciæ nastêpnie go wyjmuje");

								return 1;
							}
							if(Businesses[i][Locked] == 0)
							{
								Businesses[i][Locked] = 1;

								SendClientMessage(playerid, COLOR_LIGHTYELLOW2,"[INFO:] Drzwi zamkniête");
								PlayerActionMessage(playerid, 20.0, "wyjmuje klucz i wk³ada go do drzwi, przekrêca raz a nastêpnie go wyjmuje");

								SaveHouseData(i, "Locked");

								return 1;
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2,"[B£¥D:] Nie masz kluczy do tego biznesu !");
							PlayerActionMessage(playerid, 20.0, "przeszukuje kieszenie");

							return 1;
						}
					}
				}
			}
			return 1;
		}
		if(strcmp(cmd, "/wynajmijdom", true) == 0)
		{
			new Float:oldposx, Float:oldposy, Float:oldposz;
			new playername[MAX_PLAYER_NAME];
			new slot;
			GetPlayerName(playerid, playername, sizeof(playername));
			GetPlayerPos(playerid, oldposx, oldposy, oldposz);
			for(new h = 0; h < sizeof(Houses); h++)
			{
				if(PlayerToPoint(2.0, playerid, Houses[h][EnterX], Houses[h][EnterY], Houses[h][EnterZ]) && Houses[h][Owned] == 1 &&  Houses[h][Rentable] == 1)
				{
					slot = PHaveItem(playerid, 4, h);
					if(slot > 0)
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Posiadasz ju¿ klucze do tego domu !");
						return 1;
					}
					if(strcmp(gPlayerData[playerid][pName], Houses[h][Owner], false) == 0)
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie mo¿esz wynajmowaæ w³asnego domu !");
						return 1;
					}
					// TODO: House renting should be changed
					// Rent cost should be taken every payday and a renter name should be saved in another column
					// Also shoud be possibility to rent house to 2 or more people and block further players from renting it if there is no space
					if(GetPlayerCash(playerid) >= Houses[h][RentCost])
					{
						if(InsertPlayerItem(playerid, 4, h, 0, 0) == 0)
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie masz miejsca aby schowaæ kluczyki do domu !");
							return 1;
						}

						GivePlayerCash(playerid, -Houses[h][RentCost]);
						Houses[h][Money] += Houses[h][RentCost];

						SetPlayerInterior(playerid,Houses[h][ExitInterior]);
						SetPlayerToPos(playerid,Houses[h][ExitX],Houses[h][ExitY],Houses[h][ExitZ]);
						SetPlayerVirtualWorld(playerid,h);

						SendClientMessage(playerid, COLOR_GREEN, "[INFO:] Dom zosta³ wynajêty, op³ata jest jednorazowa.");
						return 1;
					}
					else
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie staæ Ciê na wynajem tego domu !");
						return 1;
					}
				}
			}
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Musisz znajdowaæ siê przed drzwiami do domu aby móc go wynaj¹æ !");

			return 1;
		}
		if(strcmp(cmd, "/czynsz", true) == 0)
		{
			new slot;
			new playername[128];
			GetPlayerName(playerid, playername, sizeof(playername));
			for(new i = 0; i < sizeof(Houses); i++)
			{
				if(PlayerToPoint(6.0, playerid,Houses[i][ExitX], Houses[i][ExitY], Houses[i][ExitZ]) && i == GetPlayerVirtualWorld(playerid))
				{
					slot = PHaveItem(playerid, 4, i);
					if(slot > 0)
					{
						if(slot == 1)
						{
							if(strcmp(playername, Houses[gPlayerData[playerid][pItem1]][Owner], true) == 0)
							{
								tmp = strtok(cmdtext, idx);
								if(!strlen(tmp))
								{
									SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /czynsz [kwota]");
									return 1;
								}
								if(strval(tmp) < 1 || strval(tmp) > 99999)
								{
									SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Wpisz kwote miêdzy $1-99999.");
									return 1;
								}
								Houses[gPlayerData[playerid][pItem1]][RentCost] = strval(tmp);

								new houselocation[MAX_ZONE_NAME];
								GetCoords2DZone(Houses[gPlayerData[playerid][pItem1]][EnterX],Houses[gPlayerData[playerid][pItem1]][EnterY], houselocation, MAX_ZONE_NAME);

								format(string, sizeof(string), "Opis: %s Czynsz: $%d",Houses[gPlayerData[playerid][pItem1]][Description],Houses[gPlayerData[playerid][pItem1]][RentCost]);
								UpdateDynamic3DTextLabelText(Houses3DTextLabelC[gPlayerData[playerid][pItem1]], COLOR_LIGHTYELLOW2, string);

								SaveHouseData(gPlayerData[playerid][pItem1], "RentCost");
								format(string, sizeof(string), "[INFO:] Ustawi³eœ cene wynajmu na: $%d", Houses[gPlayerData[playerid][pItem1]][RentCost]);
								SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
								return 1;
							}
						}
						if(slot == 2)
						{
							if(strcmp(playername, Houses[gPlayerData[playerid][pItem2]][Owner], true) == 0)
							{
								tmp = strtok(cmdtext, idx);
								if(!strlen(tmp))
								{
									SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /czynsz [kwota]");
									return 1;
								}
								if(strval(tmp) < 1 || strval(tmp) > 99999)
								{
									SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Wpisz kwote miêdzy $1-99999.");
									return 1;
								}
								Houses[gPlayerData[playerid][pItem2]][RentCost] = strval(tmp);

								new houselocation[MAX_ZONE_NAME];
								GetCoords2DZone(Houses[gPlayerData[playerid][pItem2]][EnterX],Houses[gPlayerData[playerid][pItem2]][EnterY], houselocation, MAX_ZONE_NAME);

								format(string, sizeof(string), "Opis: %s Czynsz: $%d",Houses[gPlayerData[playerid][pItem2]][Description],Houses[gPlayerData[playerid][pItem2]][RentCost]);
								UpdateDynamic3DTextLabelText(Houses3DTextLabelC[gPlayerData[playerid][pItem2]], COLOR_LIGHTYELLOW2, string);

								SaveHouseData(gPlayerData[playerid][pItem2], "RentCost");
								format(string, sizeof(string), "[INFO:] Ustawi³eœ cene wynajmu na: $%d", Houses[gPlayerData[playerid][pItem2]][RentCost]);
								SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
								return 1;
							}
						}
						if(slot == 3)
						{
							if(strcmp(playername, Houses[gPlayerData[playerid][pItem3]][Owner], true) == 0)
							{
								tmp = strtok(cmdtext, idx);
								if(!strlen(tmp))
								{
									SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /czynsz [kwota]");
									return 1;
								}
								if(strval(tmp) < 1 || strval(tmp) > 99999)
								{
									SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Wpisz kwote miêdzy $1-99999.");
									return 1;
								}
								Houses[gPlayerData[playerid][pItem3]][RentCost] = strval(tmp);

								new houselocation[MAX_ZONE_NAME];
								GetCoords2DZone(Houses[gPlayerData[playerid][pItem3]][EnterX],Houses[gPlayerData[playerid][pItem3]][EnterY], houselocation, MAX_ZONE_NAME);

								format(string, sizeof(string), "Opis: %s Czynsz: $%d",Houses[gPlayerData[playerid][pItem3]][Description],Houses[gPlayerData[playerid][pItem3]][RentCost]);
								UpdateDynamic3DTextLabelText(Houses3DTextLabelC[gPlayerData[playerid][pItem3]], COLOR_LIGHTYELLOW2, string);

								SaveHouseData(gPlayerData[playerid][pItem3], "RentCost");
								format(string, sizeof(string), "[INFO:] Ustawi³eœ cene wynajmu na: $%d", Houses[gPlayerData[playerid][pItem3]][RentCost]);
								SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
								return 1;
							}
						}
						if(slot == 4)
						{
							if(strcmp(playername, Houses[gPlayerData[playerid][pItem4]][Owner], true) == 0)
							{
								tmp = strtok(cmdtext, idx);
								if(!strlen(tmp))
								{
									SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /czynsz [kwota]");
									return 1;
								}
								if(strval(tmp) < 1 || strval(tmp) > 99999)
								{
									SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Wpisz kwote miêdzy $1-99999.");
									return 1;
								}
								Houses[gPlayerData[playerid][pItem4]][RentCost] = strval(tmp);

								new houselocation[MAX_ZONE_NAME];
								GetCoords2DZone(Houses[gPlayerData[playerid][pItem4]][EnterX],Houses[gPlayerData[playerid][pItem4]][EnterY], houselocation, MAX_ZONE_NAME);

								format(string, sizeof(string), "Opis: %s Czynsz: $%d",Houses[gPlayerData[playerid][pItem4]][Description],Houses[gPlayerData[playerid][pItem4]][RentCost]);
								UpdateDynamic3DTextLabelText(Houses3DTextLabelC[gPlayerData[playerid][pItem4]], COLOR_LIGHTYELLOW2, string);

								SaveHouseData(gPlayerData[playerid][pItem4], "RentCost");
								format(string, sizeof(string), "[INFO:] Ustawi³eœ cene wynajmu na: $%d", Houses[gPlayerData[playerid][pItem4]][RentCost]);
								SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
								return 1;
							}
						}
						if(slot == 5)
						{
							if(strcmp(playername, Houses[gPlayerData[playerid][pItem5]][Owner], true) == 0)
							{
								tmp = strtok(cmdtext, idx);
								if(!strlen(tmp))
								{
									SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /czynsz [kwota]");
									return 1;
								}
								if(strval(tmp) < 1 || strval(tmp) > 99999)
								{
									SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Wpisz kwote miêdzy $1-99999.");
									return 1;
								}
								Houses[gPlayerData[playerid][pItem5]][RentCost] = strval(tmp);

								new houselocation[MAX_ZONE_NAME];
								GetCoords2DZone(Houses[gPlayerData[playerid][pItem5]][EnterX],Houses[gPlayerData[playerid][pItem5]][EnterY], houselocation, MAX_ZONE_NAME);

								format(string, sizeof(string), "Opis: %s Czynsz: $%d",Houses[gPlayerData[playerid][pItem5]][Description],Houses[gPlayerData[playerid][pItem5]][RentCost]);
								UpdateDynamic3DTextLabelText(Houses3DTextLabelC[gPlayerData[playerid][pItem5]], COLOR_LIGHTYELLOW2, string);

								SaveHouseData(gPlayerData[playerid][pItem5], "RentCost");
								format(string, sizeof(string), "[INFO:] Ustawi³eœ cene wynajmu na: $%d", Houses[gPlayerData[playerid][pItem5]][RentCost]);
								SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
								return 1;
							}
						}
						if(gPlayerData[playerid][pVipItem] > 0)
						{
							if(slot == 6)
							{
								if(strcmp(playername, Houses[gPlayerData[playerid][pItem6]][Owner], true) == 0)
								{
									tmp = strtok(cmdtext, idx);
									if(!strlen(tmp))
									{
										SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /czynsz [kwota]");
										return 1;
									}
									if(strval(tmp) < 1 || strval(tmp) > 99999)
									{
										SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Wpisz kwote miêdzy $1-99999.");
										return 1;
									}
									Houses[gPlayerData[playerid][pItem6]][RentCost] = strval(tmp);

									new houselocation[MAX_ZONE_NAME];
									GetCoords2DZone(Houses[gPlayerData[playerid][pItem6]][EnterX],Houses[gPlayerData[playerid][pItem6]][EnterY], houselocation, MAX_ZONE_NAME);

									format(string, sizeof(string), "Opis: %s Czynsz: $%d",Houses[gPlayerData[playerid][pItem6]][Description],Houses[gPlayerData[playerid][pItem6]][RentCost]);
									UpdateDynamic3DTextLabelText(Houses3DTextLabelC[gPlayerData[playerid][pItem6]], COLOR_LIGHTYELLOW2, string);

									SaveHouseData(gPlayerData[playerid][pItem6], "RentCost");
									format(string, sizeof(string), "[INFO:] Ustawi³eœ cene wynajmu na: $%d", Houses[gPlayerData[playerid][pItem6]][RentCost]);
									SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
									return 1;
								}
							}
							if(slot == 7)
							{
								if(strcmp(playername, Houses[gPlayerData[playerid][pItem7]][Owner], true) == 0)
								{
									tmp = strtok(cmdtext, idx);
									if(!strlen(tmp))
									{
										SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /czynsz [kwota]");
										return 1;
									}
									if(strval(tmp) < 1 || strval(tmp) > 99999)
									{
										SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Wpisz kwote miêdzy $1-99999.");
										return 1;
									}
									Houses[gPlayerData[playerid][pItem7]][RentCost] = strval(tmp);

									new houselocation[MAX_ZONE_NAME];
									GetCoords2DZone(Houses[gPlayerData[playerid][pItem7]][EnterX],Houses[gPlayerData[playerid][pItem7]][EnterY], houselocation, MAX_ZONE_NAME);

									format(string, sizeof(string), "Opis: %s Czynsz: $%d",Houses[gPlayerData[playerid][pItem7]][Description],Houses[gPlayerData[playerid][pItem7]][RentCost]);
									UpdateDynamic3DTextLabelText(Houses3DTextLabelC[gPlayerData[playerid][pItem7]], COLOR_LIGHTYELLOW2, string);

									SaveHouseData(gPlayerData[playerid][pItem7], "RentCost");
									format(string, sizeof(string), "[INFO:] Ustawi³eœ cene wynajmu na: $%d", Houses[gPlayerData[playerid][pItem7]][RentCost]);
									SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
									return 1;
								}
							}
							if(slot == 8)
							{
								if(strcmp(playername, Houses[gPlayerData[playerid][pItem8]][Owner], true) == 0)
								{
									tmp = strtok(cmdtext, idx);
									if(!strlen(tmp))
									{
										SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /czynsz [kwota]");
										return 1;
									}
									if(strval(tmp) < 1 || strval(tmp) > 99999)
									{
										SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Wpisz kwote miêdzy $1-99999.");
										return 1;
									}
									Houses[gPlayerData[playerid][pItem8]][RentCost] = strval(tmp);

									new houselocation[MAX_ZONE_NAME];
									GetCoords2DZone(Houses[gPlayerData[playerid][pItem8]][EnterX],Houses[gPlayerData[playerid][pItem8]][EnterY], houselocation, MAX_ZONE_NAME);

									format(string, sizeof(string), "Opis: %s Czynsz: $%d",Houses[gPlayerData[playerid][pItem8]][Description],Houses[gPlayerData[playerid][pItem8]][RentCost]);
									UpdateDynamic3DTextLabelText(Houses3DTextLabelC[gPlayerData[playerid][pItem8]], COLOR_LIGHTYELLOW2, string);

									SaveHouseData(gPlayerData[playerid][pItem8], "RentCost");
									format(string, sizeof(string), "[INFO:] Ustawi³eœ cene wynajmu na: $%d", Houses[gPlayerData[playerid][pItem8]][RentCost]);
									SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
									return 1;
								}
							}
							if(slot == 9)
							{
								if(strcmp(playername, Houses[gPlayerData[playerid][pItem9]][Owner], true) == 0)
								{
									tmp = strtok(cmdtext, idx);
									if(!strlen(tmp))
									{
										SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /czynsz [kwota]");
										return 1;
									}
									if(strval(tmp) < 1 || strval(tmp) > 99999)
									{
										SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Wpisz kwote miêdzy $1-99999.");
										return 1;
									}
									Houses[gPlayerData[playerid][pItem9]][RentCost] = strval(tmp);

									new houselocation[MAX_ZONE_NAME];
									GetCoords2DZone(Houses[gPlayerData[playerid][pItem9]][EnterX],Houses[gPlayerData[playerid][pItem9]][EnterY], houselocation, MAX_ZONE_NAME);

									format(string, sizeof(string), "Opis: %s Czynsz: $%d",Houses[gPlayerData[playerid][pItem9]][Description],Houses[gPlayerData[playerid][pItem9]][RentCost]);
									UpdateDynamic3DTextLabelText(Houses3DTextLabelC[gPlayerData[playerid][pItem9]], COLOR_LIGHTYELLOW2, string);

									SaveHouseData(gPlayerData[playerid][pItem9], "RentCost");
									format(string, sizeof(string), "[INFO:] Ustawi³eœ cene wynajmu na: $%d", Houses[gPlayerData[playerid][pItem9]][RentCost]);
									SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
									return 1;
								}
							}
							if(slot == 10)
							{
								if(strcmp(playername, Houses[gPlayerData[playerid][pItem10]][Owner], true) == 0)
								{
									tmp = strtok(cmdtext, idx);
									if(!strlen(tmp))
									{
										SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /czynsz [kwota]");
										return 1;
									}
									if(strval(tmp) < 1 || strval(tmp) > 99999)
									{
										SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Wpisz kwote miêdzy $1-99999.");
										return 1;
									}
									Houses[gPlayerData[playerid][pItem10]][RentCost] = strval(tmp);

									new houselocation[MAX_ZONE_NAME];
									GetCoords2DZone(Houses[gPlayerData[playerid][pItem10]][EnterX],Houses[gPlayerData[playerid][pItem10]][EnterY], houselocation, MAX_ZONE_NAME);

									format(string, sizeof(string), "Opis: %s Czynsz: $%d",Houses[gPlayerData[playerid][pItem10]][Description],Houses[gPlayerData[playerid][pItem10]][RentCost]);
									UpdateDynamic3DTextLabelText(Houses3DTextLabelC[gPlayerData[playerid][pItem10]], COLOR_LIGHTYELLOW2, string);

									SaveHouseData(gPlayerData[playerid][pItem10], "RentCost");
									format(string, sizeof(string), "[INFO:] Ustawi³eœ cene wynajmu na: $%d", Houses[gPlayerData[playerid][pItem10]][RentCost]);
									SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
									return 1;
								}
							}
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2,"[B£¥D:] Nie masz kluczy do tego domu !");
						PlayerActionMessage(playerid, 20.0, "przeszukuje kieszenie");

						return 1;
					}
				}
			}
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Musisz byæ w domu by zarz¹dzaæ jego wynajmem");

			return 1;
		}
		if(strcmp(cmd, "/zmienczynsz", true) == 0)
		{
			for(new i = 0; i < sizeof(Houses); i++)
			{
				if(PlayerToPoint(6.0, playerid,Houses[i][ExitX], Houses[i][ExitY], Houses[i][ExitZ]) && i == GetPlayerVirtualWorld(playerid))
				{
					if(strcmp(gPlayerData[playerid][pName], Houses[i][Owner], true) == 0)
					{
						if(Houses[i][Rentable] == 0)
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Wynajem uaktywniony.");
							Houses[i][Rentable] = 1;
							SaveHouseData(i, "Rentable");
						}
						else if(Houses[i][Rentable] == 1)
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Wynajem dezaktywowany.");
							Houses[i][Rentable] = 0;
							SaveHouseData(i, "Rentable");
						}
						return 1;
					}
					else
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ w³aœcicielem tego domu !");
						return 1;
					}
				}
			}
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Musisz byæ w domu by zarz¹dzaæ jego wynajmem");

			return 1;
		}
		if(strcmp(cmd, "/kupdom", true) == 0)
		{
			new Float:oldposx, Float:oldposy, Float:oldposz;
			new playername[MAX_PLAYER_NAME];
			new houselocation[MAX_ZONE_NAME];
			new slot;
			GetPlayerName(playerid, playername, sizeof(playername));
			GetPlayerPos(playerid, oldposx, oldposy, oldposz);
			if( gPlayerData[playerid][pIsDeptor] )
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Znajdujesz siê w rejestrze d³u¿ników. Nie mo¿esz kupiæ ¿adnego domu !");
				return 1;
			}
			for(new h = 0; h < sizeof(Houses); h++)
			{
				if(PlayerToPoint(2.0, playerid, Houses[h][EnterX], Houses[h][EnterY], Houses[h][EnterZ]) && Houses[h][Owned] == 0)
				{
					if(Houses[h][HousePrice] == 0)
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie ma ustalonej kwoty za ten dom, prawodpodobnie nie jest na sprzeda¿.");
						return 1;
					}
					if(GetPlayerCash(playerid) > Houses[h][HousePrice])
					{
						slot = PHaveItem(playerid, 4, h);
						if(slot != 0)
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Posiadasz ju¿ klucze do tego domu !");
							return 1;
						}
						if(InsertPlayerItem(playerid, 4, h, 0, 0) == 0)
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie masz miejsca na kluczyki, nie mo¿esz kupiæ domu !");
							return 1;
						}
						if( !gPlayerData[playerid][pFirstHouse] )
						{
							gPlayerData[playerid][pFirstHouse] = 1;
							SavePlayerData( playerid, "FirstHouse" );
							AddExpPoint(playerid);
							SendClientMessage( playerid, COLOR_GREEN, "[INFO:] Kupi³eœ swój pierwszy dom !" );
						}
						Houses[h][Owned] = 1;
						strmid(Houses[h][Owner], playername, 0, strlen(playername), 255);
						GivePlayerCash(playerid,-Houses[h][HousePrice]);
						SetPlayerInterior(playerid,Houses[h][ExitInterior]);
						SetPlayerToPos(playerid,Houses[h][ExitX],Houses[h][ExitY],Houses[h][ExitZ]);
						SetPlayerVirtualWorld(playerid,h);
						SetPlayerFacingAngle(playerid,Houses[h][ExitAngle]);
						
						gPlayerData[playerid][pCrashX] = Houses[h][ExitX];
						gPlayerData[playerid][pCrashY] = Houses[h][ExitY];
						gPlayerData[playerid][pCrashZ] = Houses[h][ExitZ];
						gPlayerData[playerid][pCrashInt] = Houses[h][ExitInterior];
						gPlayerData[playerid][pCrashW] = h;
						gPlayerData[playerid][pCrashAngle] = Houses[h][ExitAngle];

						SavePlayerData(playerid, "Crash");
						
						TogglePlayerControllable(playerid, 0);
						unfreezeTPPlayer(playerid);
						
						DestroyDynamicPickup(Houses[h][PickupID]);
						Houses[h][PickupID] = CreateDynamicPickup(1239, 1, Houses[h][EnterX],Houses[h][EnterY],Houses[h][EnterZ]);
						
						Houses[h][Rentable] = 0;
						Houses[h][RentCost] = 0;
						Houses[h][Materials] = 0;
						Houses[h][Drugs] = 0;
						Houses[h][Money] = 0;
						Houses[h][Locked] = 0;
						Houses[h][HItem1] = 0;
						Houses[h][HItem2] = 0;
						Houses[h][HItem3] = 0;
						Houses[h][HItem4] = 0;
						Houses[h][HItem5] = 0;
						Houses[h][HItem1type] = 0;
						Houses[h][HItem2type] = 0;
						Houses[h][HItem3type] = 0;
						Houses[h][HItem4type] = 0;
						Houses[h][HItem5type] = 0;
						Houses[h][HRadio1Bought] = 0;
						Houses[h][HRadio1On] = 0;
						Houses[h][HRadio1Obj] = 0;
						Houses[h][HouseType] = 0;
						Houses[h][HConfiscated] = 0;
						
						GetCoords2DZone(Houses[h][EnterX],Houses[h][EnterY], houselocation, MAX_ZONE_NAME);
						format(string, sizeof(string), "Adres: %d %s",h,houselocation);
						UpdateDynamic3DTextLabelText(Houses3DTextLabelA[h], COLOR_LIGHTYELLOW2, string);
						format(string, sizeof(string), "Wlasciciel: %s",Houses[h][Owner]);
						UpdateDynamic3DTextLabelText(Houses3DTextLabelB[h], COLOR_LIGHTYELLOW2, string);
						format(string, sizeof(string), "Opis: %s",Houses[h][Description]);
						UpdateDynamic3DTextLabelText(Houses3DTextLabelC[h], COLOR_LIGHTYELLOW2, string);

						SendClientMessage(playerid, COLOR_WHITE, "[INFO:] Kupi³eœ posiad³oœæ !");
						PlayerPlaySound(playerid, 1149, 0, 0, 0);
						
						SaveHouseData(h, "Owned");
						SaveHouseData(h, "Owner");
						SaveHouseData(h, "Rentable");
						SaveHouseData(h, "RentCost");
						SaveHouseData(h, "Materials");
						SaveHouseData(h, "Drugs");
						SaveHouseData(h, "Money");
						SaveHouseData(h, "Locked");
						SaveHouseData(h, "HItem1");
						SaveHouseData(h, "HItem2");
						SaveHouseData(h, "HItem3");
						SaveHouseData(h, "HItem4");
						SaveHouseData(h, "HItem5");
						SaveHouseData(h, "HItem1type");
						SaveHouseData(h, "HItem2type");
						SaveHouseData(h, "HItem3type");
						SaveHouseData(h, "HItem4type");
						SaveHouseData(h, "HItem5type");
						SaveHouseData(h, "Confiscated");
						
						format(string, sizeof(string), "[GOVERNMENT:] House bought by %s for %d", gPlayerData[playerid][pName], Houses[h][HousePrice]);
						print(string);
						GovermentLog(string);
						
						return 1;
					}
					else
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie masz wystarczaj¹co du¿o pieniêdzy !");
						return 1;
					}
				}
			}
			return 1;
		}
		if(strcmp(cmd, "/wejsciowka", true) == 0)
		{
			new bouse = gPlayerData[playerid][pBizKey];
			new playername[MAX_PLAYER_NAME];
			GetPlayerName(playerid,playername,sizeof(playername));
			if (bouse != 255 && strcmp(playername, Businesses[gPlayerData[playerid][pBizKey]][Owner], true) == 0)
			{
				tmp = strtok(cmdtext, idx);
				if(!strlen(tmp))
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /wejsciowka [kwota]");
				}
				if(strval(tmp) < 0 || strval(tmp) > 999)
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Minimalna kwota wejœciówki to $0, maksymalna: $999.");
					return 1;
				}
				Businesses[bouse][EntranceCost] = strval(tmp);
				format(string, sizeof(string), "Wejœciówka: $%d",Businesses[bouse][EntranceCost]);
				UpdateDynamic3DTextLabelText(Business3DTextLabelC[bouse], COLOR_LIGHTBLUE2, string);
				format(string, sizeof(string), "[INFO:] Ustawi³eœ wejœciówke na $%d.", Businesses[bouse][EntranceCost]);
				SendClientMessage(playerid, COLOR_WHITE, string);
				
				PlayerActionMessage(playerid,15.0,"nakleja kartke na drzwi");
				
				SaveBizData(bouse, "EntranceCost");
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie posiadasz biznesu !");
			}
			return 1;
		}
		if(strcmp(cmd, "/nazwabiznesu", true) == 0)
		{
			if(IsPlayerConnected(playerid))
			{
				new bouse = gPlayerData[playerid][pBizKey];
				new playername[MAX_PLAYER_NAME];
				GetPlayerName(playerid,playername,sizeof(playername));
				if (bouse != 255 && strcmp(playername, Businesses[gPlayerData[playerid][pBizKey]][Owner], true) == 0)
				{
					new length = strlen(cmdtext);
					while ((idx < length) && (cmdtext[idx] <= ' '))
					{
						idx++;
					}
					new offset = idx;
					new result[64];
					while ((idx < length) && ((idx - offset) < (sizeof(result) - 1)))
					{
						result[idx - offset] = cmdtext[idx];
						idx++;
					}
					result[idx - offset] = EOS;
					if(!strlen(result))
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /nazwabiznesu [nazwa]");
					}
					if(PlayerToPoint(1.0,playerid,Businesses[bouse][EnterX],Businesses[bouse][EnterY],Businesses[bouse][EnterZ]) || PlayerToPoint(25.0,playerid,Businesses[bouse][ExitX],Businesses[bouse][ExitY],Businesses[bouse][ExitZ]))
					{
						if(strlen(result) < 3)
						{
							SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nazwa musi zawieraæ co najmniej 3 znaki !");
							return 1;
						}
						if(strfind( result , "|" , true ) == -1)
						{
							strmid(Businesses[bouse][BusinessName], result, 0, 64, 255);
							new businesstype[128];
							if(Businesses[bouse][BizType] != 0)
							{
								if(Businesses[bouse][BizType] == 1) { businesstype = "Restauracja"; }
								else if(Businesses[bouse][BizType] == 2) { businesstype = "Siec komorkowa"; }
								else if(Businesses[bouse][BizType] == 3) { businesstype = "Sklep 24/7"; }
								else if(Businesses[bouse][BizType] == 4) { businesstype = "Sklep z bronia"; }
								else if(Businesses[bouse][BizType] == 5) { businesstype = "Studio reklamowe"; }
								else if(Businesses[bouse][BizType] == 6) { businesstype = "Sklep z ubraniami"; }
								else if(Businesses[bouse][BizType] == 7) { businesstype = "Bar/Club"; }
								else if(Businesses[bouse][BizType] == 8) { businesstype = "Studio nagraniowe"; }
								else if(Businesses[bouse][BizType] == 9) { businesstype = "Studio"; }
								else if(Businesses[bouse][BizType] == 10) { businesstype = "Salon samochodowy"; }
								else if(Businesses[bouse][BizType] == 11) { businesstype = "Stacja paliw"; }
							}
							else { businesstype = "Nie ustawione"; }

							if(Businesses[bouse][Owned] == 0)
							{
								format(string, sizeof(string), "Nazwa biznesu: %, Typ biznesu: %s",Businesses[bouse][BusinessName],businesstype);
								UpdateDynamic3DTextLabelText(Business3DTextLabelB[bouse], COLOR_LIGHTBLUE2, string);
							}
							else
							{
								format(string, sizeof(string), "Nazwa biznesu: %s, Typ biznesu: %s",Businesses[bouse][BusinessName],businesstype);
								UpdateDynamic3DTextLabelText(Business3DTextLabelA[bouse], COLOR_LIGHTBLUE2, string);
							}
							format(string, sizeof(string), "[INFO:] Ustawi³eœ nazwe swojego biznesu na: %s.",Businesses[bouse][BusinessName]);
							SendClientMessage(playerid, COLOR_WHITE, string);
							
							PlayerActionMessage(playerid,15.0,"montuje nowy szyld");
							
							SaveBizData(bouse, "BusinessName");
						}
						else
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nieprawid³owy symbol: | nie jest dozwolony.");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Musisz byæ przed lub w biznesie ¿eby zmieniæ jego nazwe!");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie posiadasz biznesu !");
				}
			}
			return 1;
		}
		if (strcmp(cmd, "/infobiznesu", true) == 0)
		{
			if(IsPlayerConnected(playerid))
			{
				new bouse = gPlayerData[playerid][pBizKey];
				new playername[MAX_PLAYER_NAME];
				GetPlayerName(playerid,playername,sizeof(playername));
				if(bouse != 255)
				{
					if(PlayerToPoint(1.0,playerid,Businesses[bouse][EnterX],Businesses[bouse][EnterY],Businesses[bouse][EnterZ]) || PlayerToPoint(20.0,playerid,Businesses[bouse][ExitX],Businesses[bouse][ExitY],Businesses[bouse][ExitZ]))
					{
						if(Businesses[bouse][BizType] == 10)
						{
							format(string, sizeof(string), "[INFO:] Nazwa biznesu: %s - Kasa: $%d - Zamek: %d - Limit pojazdów: %d", Businesses[bouse][BusinessName],Businesses[bouse][Till],Businesses[bouse][Locked],Businesses[bouse][MaxVehicles]);
							SendClientMessage(playerid, COLOR_WHITE, string);
							format(string, sizeof(string), "[INFO:] Posiadanych pojazdów: %d - Liczba zamówieñ: %d - Pojazdy oczekuj¹ce(0/1): %d - Wejœciówka: $%d", Businesses[bouse][VehicleCount],Businesses[bouse][VehicleOrderCount],Businesses[bouse][VehicleSpawned],Businesses[bouse][EntranceCost]);
							SendClientMessage(playerid, COLOR_WHITE, string);
							format(string, sizeof(string), "[INFO:] Wycena biznesu: %d$", Businesses[bouse][BizPrice]);
							SendClientMessage(playerid, COLOR_WHITE, string);
							
							PlayerActionMessage(playerid, 15.0, "przegl¹da dokumentacje biznesu");
							
							return 1;
						}
						format(string, sizeof(string), "[INFO:] Nazwa biznesu: %s - Kasa: $%d - Zamek: %d - Produkty: %d - Wejœciówka: $%d.", Businesses[bouse][BusinessName],Businesses[bouse][Till],Businesses[bouse][Locked],Businesses[bouse][Products],Businesses[bouse][EntranceCost]);
						SendClientMessage(playerid, COLOR_WHITE, string);
						format(string, sizeof(string), "[INFO:] Wycena biznesu: %d$", Businesses[bouse][BizPrice]);
						SendClientMessage(playerid, COLOR_WHITE, string);
						return 1;
					}
					else
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie jesteœ w swoim biznesie!");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie posiadasz biznesu !");
				}
			}
			return 1;
		}
		if(strcmp(cmd, "/sprzedajbiznes", true) == 0)
		{
			new playername[MAX_PLAYER_NAME];
			GetPlayerName(playerid, playername, sizeof(playername));
			if(gPlayerData[playerid][pBizKey] != 255 && strcmp(playername, Businesses[gPlayerData[playerid][pBizKey]][Owner], true) == 0)
			{
				new biz = gPlayerData[playerid][pBizKey];
				if(PlayerToPoint(1.0,playerid,Businesses[biz][EnterX],Businesses[biz][EnterY],Businesses[biz][EnterZ]))
				{					
					/* Clear players business key form given businessid */
					foreach(Player, i)
					{
						if(gPlayerData[i][pBizKey] == biz)
						{
							gPlayerData[i][pBizKey] = 255;
							SavePlayerData(i, "BizKey");
						}
					}
					
					/* Clear players business key form given businessid in database */
					format(string, sizeof(string), "UPDATE `samp_users_keys` SET `BizKey` = '255' WHERE `BizKey` = '%d'", biz);
					mysql_query(string, SAVE, INVALID_PLAYER_ID, db_con2);
					
					if(Businesses[biz][BizType] == 10)
					{
						new cost;
						for(new i = 0; i < sizeof(gVehData); i++)
						{
							if(gVehData[i][BusinessID] == biz)
							{
								cost += cenyPojazdow[gVehData[i][CarModel]-400];
							}
						}
						GivePlayerCash(playerid,(Businesses[biz][BizPrice]+cost));
						format(string, sizeof(string), "[INFO:] Sprzeda³eœ swój biznes za $%d.", Businesses[biz][BizPrice]+cost);
					}
					else
					{
						GivePlayerCash(playerid,Businesses[biz][BizPrice]);
						format(string, sizeof(string), "[INFO:] Sprzeda³eœ swój biznes za $%d.", Businesses[biz][BizPrice]);
					}
					SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
					
					gPlayerData[playerid][pBizKey] = 255;
					SavePlayerData(playerid, "BizKey");

					ResetBizData(biz, 1);
					
					new businesstype[128];
					if(Businesses[biz][BizType] != 0)
					{
						if(Businesses[biz][BizType] == 1) { businesstype = "Restauracja"; }
						else if(Businesses[biz][BizType] == 2) { businesstype = "Siec komorkowa"; }
						else if(Businesses[biz][BizType] == 3) { businesstype = "Sklep 24/7"; }
						else if(Businesses[biz][BizType] == 4) { businesstype = "Sklep z bronia"; }
						else if(Businesses[biz][BizType] == 5) { businesstype = "Studio reklamowe"; }
						else if(Businesses[biz][BizType] == 6) { businesstype = "Sklep z ubraniami"; }
						else if(Businesses[biz][BizType] == 7) { businesstype = "Bar/Club"; }
						else if(Businesses[biz][BizType] == 8) { businesstype = "Studio nagraniowe"; }
						else if(Businesses[biz][BizType] == 9) { businesstype = "Studio"; }
						else if(Businesses[biz][BizType] == 10) { businesstype = "Salon samochodowy"; }
						else if(Businesses[biz][BizType] == 11) { businesstype = "Stacja paliw"; }
					}
					else { businesstype = "Nie ustawione"; }

					format(string, sizeof(string), "Ten biznes jest na sprzeda¿!");
					UpdateDynamic3DTextLabelText(Business3DTextLabelA[biz], COLOR_LIGHTBLUE2, string);

					format(string, sizeof(string), "Numer Budynku: %d, Nazwa biznesu: %s, Typ biznesu: %s",biz,Businesses[biz][BusinessName],businesstype);
					UpdateDynamic3DTextLabelText(Business3DTextLabelB[biz], COLOR_LIGHTBLUE2, string);

					format(string, sizeof(string), "Cena: $%d",Businesses[biz][BizPrice]);
					UpdateDynamic3DTextLabelText(Business3DTextLabelC[biz], COLOR_LIGHTBLUE2, string);

					return 1;
				}
				else
				{
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] Musisz byæ przed wejœciem do biznesu ¿eby go sprzedaæ !");
				}
			}
			else if(gPlayerData[playerid][pBizKey] != 255 && strcmp(playername, Businesses[gPlayerData[playerid][pBizKey]][Owner], true) != 0)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Posiadasz klucze do biznesu jednak zosta³ on prawnie przejêty przez kogoœ innego lub sprzedany !");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Wrazie w¹tpliwoœci udaj siê po informacje do Urzêdu Miasta");
				return 1;
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie posiadasz ¿adnego biznesu !");
			}
			return 1;
		}
		if(strcmp(cmd, "/kupbiznes", true) == 0)
		{
			new Float:oldposx, Float:oldposy, Float:oldposz;
			new playername[MAX_PLAYER_NAME];
			GetPlayerName(playerid, playername, sizeof(playername));
			GetPlayerPos(playerid, oldposx, oldposy, oldposz);
			new cost;
			if( gPlayerData[playerid][pIsDeptor] )
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Znajdujesz siê w rejestrze d³u¿ników. Nie mo¿esz kupiæ ¿adnego biznesu !");
				return 1;
			}
			for(new h = 0; h < sizeof(Businesses); h++)
			{
				if(PlayerToPoint(2.0, playerid, Businesses[h][EnterX], Businesses[h][EnterY], Businesses[h][EnterZ]) && Businesses[h][Owned] == 0)
				{
					if(Businesses[h][BizPrice] == 0)
					{
						SendClientMessage(playerid, COLOR_RED, "[B£¥D:] Nie ma ustalonej ceny za ten biznes, prawdopodobnie nie jest on na sprzeda¿.");
						return 1;
					}
					if(gPlayerData[playerid][pBizKey] != 255 && strcmp(playername, Businesses[gPlayerData[playerid][pBizKey]][Owner], true) == 0)
					{
						SendClientMessage(playerid, COLOR_RED, "[INFO:] Mo¿esz posiadaæ tylko jeden biznes, sprzedaj poprzedni zanim kupisz nowy !");
						return 1;
					}
					if( gPlayerData[playerid][pFaction] != 255 && Businesses[h][BizType] == BIZT_WEAPONS )
					{
						if( gPlayerData[playerid][pRank] == 1 && DynamicFactions[ gPlayerData[playerid][pFaction] ][fType] == F_POLICE )
						{
							SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz jednoczeœnie byæ liderem tej frakcji i posiadaæ sklepu z broni¹ !");
							return 1;
						}
					}
					if( gBizBoughtApproved[playerid] != h && gPlayerData[playerid][pAdmin] == 0)
					{
						SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz pozwolenia na kupno tego biznesu !" );
						SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Aby uzyskaæ pozwolenie udaj siê do urzêdnia i wpisz komende /prosbaobiznes [id urzednika] [id biznesu]" );
						return 1;
					}
					if(GetPlayerCash(playerid) >= Businesses[h][BizPrice])
					{
						if(Businesses[h][BizType] == 10)
						{
							for(new i = 0; i < sizeof(gVehData); i++)
							{
								if(gVehData[i][BusinessID] == h)
								{
									cost += cenyPojazdow[gVehData[i][CarModel]-400];
								}
							}
							if(GetPlayerCash(playerid) >= Businesses[h][BizPrice] + cost)
							{
								gPlayerData[playerid][pBizKey] = h;
								SavePlayerData(playerid, "BizKey");

								Businesses[h][Till] = 0;
								Businesses[h][Owned] = 1;
								Businesses[h][Products] = 0;
								strmid(Businesses[h][Owner], gPlayerData[playerid][pName], 0, MAX_PLAYER_NAME );

								GivePlayerCash(playerid,-(Businesses[h][BizPrice]+cost));

								SetPlayerInterior(playerid,Businesses[h][ExitInterior]);
								SetPlayerVirtualWorld(playerid,h);
								SetPlayerToPos(playerid,Businesses[h][ExitX],Businesses[h][ExitY],Businesses[h][ExitZ]);

								SendClientMessage(playerid, COLOR_WHITE, "[INFO:] Kupi³eœ biznes !");
								PlayerPlaySound(playerid, 1149, 0, 0, 0);

								DestroyDynamicPickup(Businesses[h][PickupID]);
								Businesses[h][PickupID] = CreateDynamicPickup(1239, 1, Businesses[h][EnterX],Businesses[h][EnterY],Businesses[h][EnterZ]);
							}
						}
						else
						{
							gPlayerData[playerid][pBizKey] = h;
							SavePlayerData(playerid, "BizKey");

							GetPlayerName(playerid, playername, sizeof(playername));
							Businesses[h][Till] = 0;
							Businesses[h][Owned] = 1;
							Businesses[h][Products] = 0;
							strmid(Businesses[h][Owner], playername, 0, strlen(playername), 255);

							GivePlayerCash(playerid,-Businesses[h][BizPrice]);

							SetPlayerInterior(playerid,Businesses[h][ExitInterior]);
							SetPlayerVirtualWorld(playerid,h);
							SetPlayerToPos(playerid,Businesses[h][ExitX],Businesses[h][ExitY],Businesses[h][ExitZ]);

							SendClientMessage(playerid, COLOR_WHITE, "[INFO:] Kupi³eœ biznes !");
							PlayerPlaySound(playerid, 1149, 0, 0, 0);

							DestroyDynamicPickup(Businesses[h][PickupID]);
							CreateDynamicPickup(1239, 1, Businesses[h][EnterX], Businesses[h][EnterY], Businesses[h][EnterZ]);
						}

						new businesstype[128];
						if(Businesses[h][BizType] != 0)
						{
							if(Businesses[h][BizType] == 1) { businesstype = "Restauracja"; }
							else if(Businesses[h][BizType] == 2) { businesstype = "Siec komorkowa"; }
							else if(Businesses[h][BizType] == 3) { businesstype = "Sklep 24/7"; }
							else if(Businesses[h][BizType] == 4) { businesstype = "Sklep z bronia"; }
							else if(Businesses[h][BizType] == 5) { businesstype = "Studio reklamowe"; }
							else if(Businesses[h][BizType] == 6) { businesstype = "Sklep z ubraniami"; }
							else if(Businesses[h][BizType] == 7) { businesstype = "Bar/Club"; }
							else if(Businesses[h][BizType] == 8) { businesstype = "Studio nagraniowe"; }
							else if(Businesses[h][BizType] == 9) { businesstype = "Studio"; }
							else if(Businesses[h][BizType] == 10) { businesstype = "Salon samochodowy"; }
							else if(Businesses[h][BizType] == 11) { businesstype = "Stacja paliw"; }
						}
						else { businesstype = "Nie ustawione"; }

						Businesses[h][Locked] = 0;
						Businesses[h][VehicleOrderCount] = 0;
						Businesses[h][VehicleCount] = 0;
						Businesses[h][VehicleSpawned] = 0;
						Businesses[h][EntranceCost] = 0;
						Businesses[h][MaxVehicles] = 5;						
						Businesses[h][BRadio1Bought] = 0;
						Businesses[h][BRadio1On] = 0;
						Businesses[h][BRadio1Obj] = 0;
						Businesses[h][W9MM] = 0;
						Businesses[h][W9MMSil] = 0;
						Businesses[h][WDesEagle] = 0;
						Businesses[h][WMicroSMG] = 0;
						Businesses[h][WMP5] = 0;
						Businesses[h][WTec9] = 0;
						Businesses[h][WShotgun] = 0;
						Businesses[h][WAK47] = 0;
						Businesses[h][WM4] = 0;
						Businesses[h][WRifle] = 0;
						Businesses[h][WSRifle] = 0;
						Businesses[h][W9MMAmmo] = 0;
						Businesses[h][W50AEAmmo] = 0;
						Businesses[h][WBuckshot] = 0;
						Businesses[h][W762MMAmmo] = 0;
						Businesses[h][W127MMAmmo] = 0;
						
						format(string, sizeof(string), "Nazwa biznesu: %s, Typ biznesu: %s",Businesses[h][BusinessName],businesstype);
						UpdateDynamic3DTextLabelText(Business3DTextLabelA[h], COLOR_LIGHTBLUE2, string);

						format(string, sizeof(string), "Numer Budynku: %d, W³aœciciel: %s",h,Businesses[h][Owner]);
						UpdateDynamic3DTextLabelText(Business3DTextLabelB[h], COLOR_LIGHTBLUE2, string);

						format(string, sizeof(string), "Wejœciówka: $%d",Businesses[h][EntranceCost]);
						UpdateDynamic3DTextLabelText(Business3DTextLabelC[h], COLOR_LIGHTBLUE2, string);
						
						SaveBizData(h, "Owned");
						SaveBizData(h, "Owner");
						SaveBizData(h, "Products");
						SaveBizData(h, "Till");
						SaveBizData(h, "Locked");
						SaveBizData(h, "VehicleOrderCount");
						SaveBizData(h, "VehicleCount");
						SaveBizData(h, "VehicleSpawned");
						SaveBizData(h, "EntranceCost");
						SaveBizData(h, "MaxVehicles");
						SaveBizData(h, "BRadio1Bought");
						SaveBizData(h, "BRadio1On");
						SaveBizData(h, "BRadio1Obj");
						SaveBizData(h, "W9MM");
						SaveBizData(h, "W9MMSil");
						SaveBizData(h, "WDesEagle");
						SaveBizData(h, "WMicroSMG");
						SaveBizData(h, "WMP5");
						SaveBizData(h, "WTec9");
						SaveBizData(h, "WShotgun");
						SaveBizData(h, "WAK47");
						SaveBizData(h, "WRifle");
						SaveBizData(h, "WSRifle");
						SaveBizData(h, "W9MMAmmo");
						SaveBizData(h, "W50AEAmmo");
						SaveBizData(h, "WBuckshot");
						SaveBizData(h, "W762MMAmmo");
						SaveBizData(h, "W127MMAmmo");
						
						SavePlayerData(playerid, "BizKey");
						return 1;
					}
					else
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie masz wystarczaj¹cej iloœci pieniêdzy !");
						return 1;
					}
				}
			}
			return 1;
		}
		if(strcmp(cmd, "/kuptest", true) == 0)
		{
			if( gPlayerData[playerid][pLevel] < 2 )
			{
				SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Musisz mieæ 2 poziom postaci aby wykupiæ test ");
				return 1;
			}
			if(PlayerToPoint(1.0,playerid,DrivingTestPosition[X],DrivingTestPosition[Y],DrivingTestPosition[Z]))
			{
				if(gPlayerData[playerid][pCarLic] == 0)
				{
					if(GetPlayerCash(playerid) >= 1500 && !gPlayerData[playerid][pFirstCarTest])
					{
						GivePlayerCash(playerid,-1500);
						DynamicFactions[FACTIONID_GOVERNMENT][fBank] += 1500;
						SaveFData(FACTIONID_GOVERNMENT, "Bank");
						SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] Rozpocz¹³ siê Twój test!");
						SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] Musisz wsi¹œæ teraz do jednego z czerwonych pojadzdów stoj¹cych na parkingu.");
						SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] Je¿eli w danym momencie nie ma ¿adnego wolnego, musisz poczekaæ. Pamiêtaj o ograniczeniu prêdkoœci ! (70km/h)");
						TakingDrivingTest[playerid] = 1;
						gPlayerData[playerid][pFirstCarTest] = 1;
						SavePlayerData(playerid, "FirstCarTest");
					}
					else if(GetPlayerCash(playerid) >= 200 && gPlayerData[playerid][pFirstCarTest])
					{
						GivePlayerCash(playerid,-200);
						DynamicFactions[FACTIONID_GOVERNMENT][fBank] += 200;
						SaveFData(FACTIONID_GOVERNMENT, "Bank");
						SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] Rozpocz¹³ siê Twój test!");
						SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] Musisz wsi¹œæ teraz do jednego z czerwonych pojadzdów stoj¹cych na parkingu.");
						SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] Je¿eli w danym momencie nie ma ¿adnego wolnego, musisz poczekaæ.");
						TakingDrivingTest[playerid] = 1;
					}
					else
					{
						SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] Nie masz wystarczaj¹co du¿o pieniêdzy !");
					}
				}
				else
				{
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] Ju¿ posiadasz prawo jazdy !");
				}
			}
			if(PlayerToPoint(1.0,playerid,BoatTestPosition[X],BoatTestPosition[Y],BoatTestPosition[Z]))
			{
				if(gPlayerData[playerid][pBoatLic] == 0)
				{
					if(GetPlayerCash(playerid) >= 20000)
					{
						GivePlayerCash(playerid,-20000);
						DynamicFactions[FACTIONID_GOVERNMENT][fBank] += 20000;
						SaveFData(FACTIONID_GOVERNMENT, "Bank");
						SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] Rozpocz¹³ siê Twój test!");
						SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] Wybierz jedn¹ z kilku ³ódek szkoleniowych.");
						SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] Je¿eli w danym momencie nie ma ¿adnej wolnej, musisz poczekaæ.");
						TakingBoatTest[playerid] = 1;
					}
					else
					{
						SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] Nie masz wystarczaj¹co pieniêdzy!");
					}
				}
				else
				{
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] Ju¿ posiadasz prawo jazdy!");
				}
			}
			if(PlayerToPoint(1.0,playerid,BoatTestPosition[X],BoatTestPosition[Y],BoatTestPosition[Z]) == 0 && PlayerToPoint(1.0,playerid,DrivingTestPosition[X],DrivingTestPosition[Y],DrivingTestPosition[Z]) == 0)
			{
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] Nie jesteœ w punkcie szkoleniowym !");
			}
			return 1;
		}
		if(strcmp(cmd, "/kuplicencjepilota", true) == 0)
		{
			if(PlayerToPoint(1.0,playerid,FlyingTestPosition[X],FlyingTestPosition[Y],FlyingTestPosition[Z]))
			{
				if(GetPlayerVirtualWorld(playerid) == FlyingTestPosition[World])
				{
					if(gPlayerData[playerid][pFlyLic] == 0)
					{
						if(GetPlayerCash(playerid) >= 20000)
						{
							GivePlayerCash(playerid,-20000);
							DynamicFactions[FACTIONID_GOVERNMENT][fBank] += 20000;
							SaveFData(FACTIONID_GOVERNMENT, "Bank");
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] Mo¿esz teraz lataæ samolotami!");
							gPlayerData[playerid][pFlyLic] = 1;
							SavePlayerData(playerid, "FlyLic");
						}
						else
						{
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] Nie masz wystarczaj¹co pieniêdzy!");
						}
					}
					else
					{
						SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] Ju¿ posiadasz licencje pilota!");
					}
				}
			}
			else
			{
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] Nie jesteœ w oœrodku szkolenia pilotów!");
			}
			return 1;
		}
		if(strcmp(cmd, "/kuplicencjenabron", true) == 0)
		{
			if(PlayerToPoint(1.0,playerid,WeaponLicensePosition[X],WeaponLicensePosition[Y],WeaponLicensePosition[Z]))
			{
				if(GetPlayerVirtualWorld(playerid) == WeaponLicensePosition[World])
				{
					if(gPlayerData[playerid][pWepLic] == 0)
					{
						if(GetPlayerCash(playerid) >= 50000)
						{
							GivePlayerCash(playerid,-50000);
							DynamicFactions[FACTIONID_GOVERNMENT][fBank] += 50000;
							SaveFData(FACTIONID_GOVERNMENT, "Bank");
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] Mo¿esz posiadaæ i u¿ywaæ broni, w obronie w³asnej oczywiœcie.");
							gPlayerData[playerid][pWepLic] = 1;
							SavePlayerData(playerid, "WepLic");
						}
						else
						{
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] Nie masz wystarczaj¹co pieniêdzy!");
						}
					}
					else
					{
						SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] Ju¿ posiadasz licencje na broñ!");
					}
				}
			}
			else
			{
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] Nie znajdujesz siê w miejscu zakupu licencji!");
			}
			return 1;
		}
		if(strcmp(cmd, "/zatankuj", true) == 0)
		{
			if(IsABike(idcar))
			{
				SendClientMessage(playerid, COLOR_LIGHTBLUE, "[INFO:] Nie mo¿esz zatankowaæ roweru !");

				PlayerActionMessage(playerid,15.0, "spogl¹da w niebo");

				return 1;
			}
			if(gVehData[tmpcar][EngineOn])
			{
				new tmpstring[128];
				format(tmpstring, sizeof(tmpstring), "[INFO:] Wy³¹cz silnik zanim zatankujesz!");
				SendClientMessage(playerid, COLOR_LIGHTBLUE, tmpstring);
				return 1;
			}
			else
			{
				new Float:posX,Float:posY,Float:posZ;
				for(new i = 0; i < sizeof(GasStations); i++)
				{
					// printf(" GasStation[%d][GSposX] = %f, GasStation[%d][GSposY] = %f, GasStation[%d][GSposZ] = %f", i,  GasStations[i][GSposX], i, GasStations[i][GSposY], i, GasStations[i][GSposZ] );
					if( PlayerToPoint(10.0, playerid, GasStations[i][GSposX], GasStations[i][GSposY], GasStations[i][GSposZ]) )
					{
						if(gVehData[tmpcar][Fuel] == 0)
						{
							if(GasStations[i][PetrolResourceValue] <= 0)
							{
								SendClientMessage(playerid, COLOR_RED, "[INFO:] Brak benzyny na stacji !");
								return 1;
							}
						}
						if(gVehData[tmpcar][Fuel] == 1)
						{
							if(GasStations[i][OilResourceValue] <= 0)
							{
								SendClientMessage(playerid, COLOR_RED, "[INFO:] Brak ropy na stacji !");
								return 1;
							}
						}
						if(gVehData[tmpcar][Fuel] == 2)
						{
							if(GasStations[i][GasResourceValue] <= 0)
							{
								SendClientMessage(playerid, COLOR_RED, "[INFO:] Brak gazu na stacji !");
								return 1;
							}
						}
						GetPlayerPos(playerid, posX, posY, posZ);
						if(gVehData[tmpcar][CarFuel] < float(VehFTank(idcar)) && !gVehData[tmpcar][IsRefueling])
						{
							SetTimerEx("RefuelingVehicle", 1000, false, "ddfdfff", playerid, idcar, 0, i, posX, posY, posZ);
							new tmpstring[512];
							strcat( tmpstring, "Rozpoczêto tankowanie.\nAby przerwaæ tankowanie w danym momencie uruchom silnik i zaparkuj pojazd tak\n " );
							strcat( tmpstring, "aby zwolniæ miejsce do tankowania a nastêpnie udaj siê do kasy znajduj¹cej siê w stacji aby op³aciæ zatankowane paliwo." );
							ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Stacja paliw", tmpstring, "Zamknij", "" );
							gVehData[tmpcar][IsRefueling] = 1;
						}
						else if( gVehData[tmpcar][IsRefueling] )
							ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Stacja paliw", "Pojazd jest ju¿ tankowany !", "Zamknij", "" );
						else
							ShowPlayerDialog( playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Stacja paliw", "Masz ju¿ pe³ny bak !", "Zamknij", "" );
						return 1;
					}
				}
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] Nie jesteœ na stacji benzynowej!");
				return 1;
			}
		}
		if(strcmp(cmd, "/statystyki", true) == 0)
		{
			if( !gPlayerData[playerid][pFirstStats] )
			{
				gPlayerData[playerid][pFirstStats] = 1;
				SavePlayerData( playerid, "FirstStats" );
				AddExpPoint(playerid);
				SendClientMessage( playerid, COLOR_GREEN, "[INFO:] Poraz pierwszy wyœwietli³eœ swoje statystyki !" );
			}
			ShowStats(playerid,playerid);
			return 1;
		}
		if(strcmp(cmd, "/ajobcmds", true) == 0)
		{
			if (gPlayerData[playerid][pAdmin] < 1)
				return 0;
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[GUN JOB:] /agunjobpos (/wezprace) - /agunjobpos2 (/materials buy) - /agunjobpos3 (/materials dropoff)");
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[DRUG JOB:] /adrugjobpos (/wezprace) - /adrugjobpos2 (/drugs buy) - /agunjobpos3 (/drugs dropoff)");
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[DETECTIVE JOB:] /adetectivejobpos (/wezprace)");
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[LAWYER JOB:] /alawyerjobpos (/wezprace");
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[PRODUCTS SELLER JOB:] /aproductjobpos (/wezprace) - /aproductjobpos2 (/products buy)");
			return 1;
		}
		if(strcmp(cmd, "/komendydomu", true) == 0)
		{
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"/wejdz - /wyjdz - /kupdom - /sprzedajdom - /zmienczynsz - /czynsz - /wynajmijdom - /otworzdom - /wyplaczdomu - /wplacdodomu");
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"/schowajmaterialy - /wezmaterialy - /schowajnarkotyki - /weznarkotyki - /zamknijdom - /mojeitemywdomu - /wezitemzdomu");
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"/wlozitemdodomu - /radiod - /radiodv - /radiodoff - /radiozabierz");
			return 1;
		}
		if(strcmp(cmd, "/komendyfrakcji", true) == 0)
		{
			if(gPlayerData[playerid][pFaction] != 255)
			{
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"/opuscfrakcje - /f(ra) - /fmatsy - /fnarkotyki - /fodlozmaterialy - /fwezmaterialy - /fodloznarkotyki - /fweznarkotyki");
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"/fwyplac - /fwplac - /fstankonta - /statusfrakcji - /kuppojazdf - /sprzedajpojazdf - /zezlomujpojazdf");
			}
			else
			{
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] Nie nale¿ysz do ¿adnej frakcji.");
			}
			return 1;
		}
		if(strcmp(cmd, "/komendylidera", true) == 0)
		{
			if(gPlayerData[playerid][pFaction] != 255 && gPlayerData[playerid][pRank] == 1)
			{
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[Lider:] /zapros - /wypros - /ustawrange - /kuppojazdf - /sprzedajpojazdf - /zezlomujpojazdf");
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[Lider:] /pktorganizacyjny - /pktorganizacyjny2 - /fabryka");
			}
			else
			{
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] Nie jesteœ liderem !");
			}
			return 1;
		}
		if(strcmp(cmd, "/komendytel", true) == 0)
		{
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[Tel:] /kuptel - /odbierz - /rozlacz - /glosnik - /txt - /ksiazkatel - /onoff tel");
			return 1;
		}
		if(strcmp(cmd, "/komendybiznesu", true) == 0)
		{
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[Biznes:] /kupbiznes - /sprzedajbiznes - /infobiznesu - /wejsciowka - /nazwabiznesu - /otworzbiznes - /zamknijbiznes");
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[Biznes:] /wplacdobiznesu - /wyplaczbiznesu - /statuszamowien - /sprowadzpojazd - /cenapojazdu - /uzupelnianiebenzyny");
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[Biznes:] /uzupelnianieropy - /uzupelnianiegazu - /cenazalitrsbenzyny - /cenazalitrsropy - /cenazalitrsgazu");
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[Biznes:] /radiob - /radiobv - /radioboff - /radiozabierz - /stanstacji" );
			return 1;
		}
		if(strcmp(cmd, "/acarcmds", true) == 0)
		{
			if (gPlayerData[playerid][pAdmin] < 1)
				return 0;
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[Level 5:] - /acarpark - /acarmodel - /acarcolor - /aFactionCar - /acarenter - /acartype - /acarsetpos - /acardata");
			return 1;
		}
		if(strcmp(cmd, "/acarcreate", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] != 5)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /acarcreate [idcar]");
				return 1;
			}
			new car;
			new vehicleID;
			new Float:x, Float:y, Float:z;

			car = strval(tmp);
			//if(car < 400 || car > 611) { SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] 400-611."); return 1; }
			if(car < 400 || car > 701 && car != 537 && car != 538) { SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] 400-611."); return 1; }
			GetPlayerPos(playerid, x, y, z);
			vehicleID = CreateVehicle(car, x, y, z, 0, -1, -1, -1);

			gVehData[vehicleID-1][CarModel] = car;
			gVehData[vehicleID-1][CarX] = x;
			gVehData[vehicleID-1][CarY] = y;
			gVehData[vehicleID-1][CarZ] = z;
			gVehData[vehicleID-1][CarAngle] = 0;
			gVehData[vehicleID-1][CarColor1] = -1;
			gVehData[vehicleID-1][CarColor2] = -1;
			gVehData[vehicleID-1][FactionCar] = 255;
			gVehData[vehicleID-1][CarType] = 0;
			gVehData[vehicleID-1][Owned] = 0;
			strmid(gVehData[vehicleID-1][Owner], "None", 0, 4, 128);
			gVehData[vehicleID-1][Price] = cenyPojazdow[car-400];
			gVehData[vehicleID-1][Closed] = 0;
			gVehData[vehicleID-1][CarResetT] = 0;
			gVehData[vehicleID-1][CarDamaged] = 0;
			gVehData[vehicleID-1][CarRepairTimeLeft] = 0;
			gVehData[vehicleID-1][BusinessID] = 255;
			gVehData[vehicleID-1][CarFuel] = float(VehFTank(vehicleID));
			gVehData[vehicleID-1][CarHealth] = 1000.0;

			SaveVehData(vehicleID-1, "CarModel");
			SaveVehData(vehicleID-1, "CarPos");
			SaveVehData(vehicleID-1, "CarColor1");
			SaveVehData(vehicleID-1, "CarColor2");
			SaveVehData(vehicleID-1, "FactionCar");
			SaveVehData(vehicleID-1, "CarType");
			SaveVehData(vehicleID-1, "Owned");
			SaveVehData(vehicleID-1, "Owner");
			SaveVehData(vehicleID-1, "Price");
			SaveVehData(vehicleID-1, "Closed");
			SaveVehData(vehicleID-1, "CarResetT");
			SaveVehData(vehicleID-1, "CarDamaged");
			SaveVehData(vehicleID-1, "CarRepairTimeLeft");
			SaveVehData(vehicleID-1, "BusinessID");
			SaveVehData(vehicleID-1, "CarFuel");
			SaveVehData(vehicleID-1, "CarHealth");

			printf("[WARNING:] Vehicle id %d has been createb by %s", vehicleID, GetPlayerNameEx(playerid));
			return 1;
		}
		if(strcmp(cmd, "/ahousecmds", true) == 0)
		{
			if (gPlayerData[playerid][pAdmin] < 1)
				return 0;
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[Level 7:] - /ahouseentrance - /ahouseexit - /ahousedescription - /agotohouse - /ahouseprice - /ahousesell - /ahouseint");
			return 1;
		}
		if(strcmp(cmd, "/apositioncmds", true) == 0)
		{
			if (gPlayerData[playerid][pAdmin] < 1)
				return 0;
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[Level 1:] - [TELEPORTS] /agotobuilding - /agotohouse - /agotobiz - /agotofmatsstorage - /agotofdrugsstorage");
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[Level 1:] - [TELEPORTS] /agotodrivingtestpos - /agotoflyingtestpos - /agotobank - /agotoweaponlicpos - /agotopolicearrestpos");
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[Level 1:] - [TELEPORTS] /agotopolicedutypos");
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[Level 10:] - adrivingtestpos - /aflyingtestpos - /abankpos - /aweaponlicensepos - /apolicearrestpos - /apolicedutypos");
			return 1;
		}
		if(strcmp(cmd, "/wywal", true) == 0)
		{
			if(IsPlayerConnected(playerid))
			{
				new State;
				if(IsPlayerInAnyVehicle(playerid))
				{
					State=GetPlayerState(playerid);
					if(State!=PLAYER_STATE_DRIVER)
					{
						SendClientMessage(playerid,COLOR_GREY,"[B£¥D:] Mo¿esz wyrzuæ kogoœ tylko jeœli jesteœ kierowc¹ !");
						return 1;
					}
					tmp = strtok(cmdtext, idx);
					if(!strlen(tmp))
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /wywal [playerid/PartOName]");
						return 1;
					}
					new playa;
					playa = ReturnUser(tmp);
					if(IsPlayerConnected(playa))
					{
						if(playa != INVALID_PLAYER_ID)
						{
							if(playa == playerid) { SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie mo¿esz wywaliæ sam siebie !"); return 1; }
							if(IsPlayerInVehicle(playa,idcar))
							{
								format(string, sizeof(string), "[INFO:] Wyrzuci³eœ z samochodu: %s.", GetPlayerNameEx(playa));
								SendClientMessage(playerid, COLOR_WHITE, string);
								format(string, sizeof(string), "[INFO:] Zosta³eœ wyrzucony z samochodu przez: %s.", GetPlayerNameEx(playerid));
								SendClientMessage(playa, COLOR_WHITE, string);
								RemovePlayerFromVehicle(playa);
							}
							else
							{
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Ten gracz nie jest u Ciebie w samochodzie!");
								return 1;
							}
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Niew³aœciwy ID.");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie jesteœ w samochodzie !");
				}
			}
			return 1;
		}
		if(strcmp(cmd, "/adminduty", true) == 0)
		{
			if (gPlayerData[playerid][pAdmin] < 1)
				return 0;
			new faction = gPlayerData[playerid][pFaction];
			if(AdminDuty[playerid] == 1)
			{
				format(string, sizeof(string), "[ADMIN:] %s (ID:%d) nie jest ju¿ na s³u¿bie.", GetPlayerNameEx(playerid),playerid);
				ABroadCast(COLOR_YELLOW,string,1);
				AdminDuty[playerid] = 0;
				SavePlayerData(playerid, "AdminDuty");
				SetPlayerHealth(playerid,100);
				SetPlayerArmour(playerid,0);
				printf("[WARNING:] %s used goes OFF admin DUTY", gPlayerData[playerid][pName]);

				if(gPlayerData[playerid][pFaction] != 255)
				{
					if(DynamicFactions[faction][fUseColor])
					{
						//SetPlayerToFactionColor(playerid);//Setting the players color.
					}
					else
					{
						SetPlayerColor(playerid,COLOR_CIVILIAN);
					}
				}
				else
				{
					SetPlayerColor(playerid,COLOR_CIVILIAN);
				}
			}
			else
			{
				format(string, sizeof(string), "[ADMIN:] %s (ID:%d) jest teraz na s³u¿bie.", GetPlayerNameEx(playerid),playerid);
				ABroadCast(COLOR_YELLOW,string,1);
				AdminDuty[playerid] = 1;
				SavePlayerData(playerid, "AdminDuty");
				printf("[WARNING:] %s used goes ON admin DUTY", gPlayerData[playerid][pName]);
				SetPlayerColor(playerid,COLOR_ADMINDUTY);
				SetPlayerHealth(playerid,99999);
				SetPlayerArmour(playerid,99999);
			}
			return 1;
		}
		if (strcmp(cmd, "/check", true) == 0)
		{
			if (gPlayerData[playerid][pModerator] < 1)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /check [playerid]");
				return 1;
			}
			giveplayerid = ReturnUser(tmp);
			if(IsPlayerConnected(giveplayerid))
			{
				if(giveplayerid != INVALID_PLAYER_ID)
				{
					ShowStats(playerid,giveplayerid);
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Invalid ID.");
			}
			return 1;
		}
		// TODO: could be sponsoring government faction or police etc, for now - disabled
		// if(strcmp(cmd, "/sponsoruj", true) == 0)
		// {
			// if(IsPlayerConnected(playerid))
			// {
				// tmp = strtok(cmdtext, idx);
				// if(!strlen(tmp))
				// {
					// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /sponsoruj [kwota]");
					// return 1;
				// }
				// new moneys;
				// moneys = strval(tmp);
				// if(moneys < 0)
				// {
					// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nieprawid³owa cena.");
					// return 1;
				// }
				// if(GetPlayerCash(playerid) < moneys)
				// {
					// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie masz tyle !");
					// return 1;
				// }
				// GivePlayerCash(playerid, -moneys);
				// format(string, sizeof(string), "[INFO:] %s zasponsorowal $%d.",GetPlayerNameEx(playerid), moneys);
				// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
				// PayLog(string);
			// }
			// return 1;
		// }
		if(strcmp(cmd, "/up", true) == 0)
		{
			if (gPlayerData[playerid][pAdmin] < 1)
				return 0;
			new Float:slx, Float:sly, Float:slz;
			GetPlayerPos(playerid, slx, sly, slz);
			SetPlayerToPos(playerid, slx, sly, slz+2);
			return 1;
		}
		if(strcmp(cmd, "/mute", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 1)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_GRAD2, "U¯YCIE: /mute [playerid/PartOName]");
				return 1;
			}
			new playa;
			playa = ReturnUser(tmp);
			if(IsPlayerConnected(playa))
			{
				if(playa != INVALID_PLAYER_ID)
				{
					GetPlayerName(playa, giveplayer, sizeof(giveplayer));
					GetPlayerName(playerid, sendername, sizeof(sendername));
					if(gPlayerData[playa][pMuted] == 0)
					{
						gPlayerData[playa][pMuted] = 1;

						printf("[SERVER:] %s wyciszy³ %s",sendername,  giveplayer);
						format(string, sizeof(string), "[SERVER:] %s zosta³ uciszony przez %s",giveplayer ,sendername);
						ABroadCast(COLOR_LIGHTRED,string,1);
					}
					else
					{
						gPlayerData[playa][pMuted] = 0;

						printf("[SERVER:] %s odciszy³ %s",sendername,  giveplayer);
						format(string, sizeof(string), "[SERVER:] %s zosta³ odciszony przez %s",giveplayer ,sendername);
						ABroadCast(COLOR_LIGHTRED,string,1);
					}
				}
			}
			return 1;
		}
		if(strcmp(cmd, "/mmute", true) == 0)
		{
			if(gPlayerData[playerid][pModerator] < 1)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_GRAD2, "U¯YCIE: /mute [playerid/PartOName]");
				return 1;
			}
			new playa;
			playa = ReturnUser(tmp);
			if(IsPlayerConnected(playa))
			{
				if(playa != INVALID_PLAYER_ID)
				{
					GetPlayerName(playa, giveplayer, sizeof(giveplayer));
					GetPlayerName(playerid, sendername, sizeof(sendername));
					if(gPlayerData[playa][pMuted] == 0)
					{
						gPlayerData[playa][pMuted] = 1;

						printf("[SERVER:] %s wyciszy³ %s",sendername,  giveplayer);
						format(string, sizeof(string), "[SERVER:] %s zosta³ uciszony przez %s",giveplayer ,sendername);
						ABroadCast(COLOR_LIGHTRED,string,1);
					}
					else
					{
						gPlayerData[playa][pMuted] = 0;

						printf("[SERVER:] %s odciszy³ %s",sendername,  giveplayer);
						format(string, sizeof(string), "[SERVER:] %s zosta³ odciszony przez %s",giveplayer ,sendername);
						ABroadCast(COLOR_LIGHTRED,string,1);
					}
				}
			}
			return 1;
		}
		if(strcmp(cmd, "/warn", true) == 0)
		{
			if(gPlayerData[playerid][pModerator] < 1)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /warn [playerid] [reason]");
				return 1;
			}
			giveplayerid = ReturnUser(tmp);
			if(IsPlayerConnected(giveplayerid))
			{
				if(giveplayerid != INVALID_PLAYER_ID)
				{
					new length = strlen(cmdtext);
					while ((idx < length) && (cmdtext[idx] <= ' '))
					{
						idx++;
					}
					new offset = idx;
					new result[128];
					while ((idx < length) && ((idx - offset) < (sizeof(result) - 1)))
					{
						result[idx - offset] = cmdtext[idx];
						idx++;
					}
					result[idx - offset] = EOS;
					if(!strlen(result))
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /warn [playerid] [reason]");
						return 1;
					}
					gPlayerData[giveplayerid][pWarnings] += 1;
					SavePlayerData(giveplayerid, "Warnings");
					gPlayerData[giveplayerid][pWarnCooldown] = WARN_COOLDOWN;
					SavePlayerData(giveplayerid, "WarnCooldown");

					if(gPlayerData[giveplayerid][pWarnings] >= 5)
					{
						format(string, sizeof(string), "[BAN:] %s zosta³ zbanowany za ponad 5 ostrze¿eñ.", GetPlayerNameEx(giveplayerid));
						BanLog(string);
						BanPlayerAccount(giveplayerid,GetPlayerNameEx(playerid),(result));
						return 1;
					}
					format(string, sizeof(string), "[INFO:] Da³eœ ostrze¿enie %s, powód: %s.", GetPlayerNameEx(giveplayerid), (result));
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
					format(string, sizeof(string), "[INFO:] Zosta³eœ ostrze¿ony przez %s, powód: %s.", GetPlayerNameEx(playerid), (result));
					SendClientMessage(giveplayerid, COLOR_LIGHTYELLOW2, string);
					return 1;
				}
			}//not connected
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Invalid ID.");
			}
			return 1;
		}
		if(strcmp(cmd, "/goto", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 1)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /goto [playerid]");
				return 1;
			}
			new Float:plocx,Float:plocy,Float:plocz;
			new plo;
			plo = ReturnUser(tmp);
			if (IsPlayerConnected(plo))
			{
				if(plo != INVALID_PLAYER_ID)
				{
					GetPlayerPos(plo, plocx, plocy, plocz);
					new interior = GetPlayerInterior(plo);
					new world = GetPlayerVirtualWorld(plo);

					if (GetPlayerState(playerid) == 2)
					{
						SetVehicleToPos(idcar, plocx, plocy+4, plocz);
						SetPlayerVirtualWorld(playerid,world);
						SetPlayerInterior(playerid,interior);
					}
					else
					{
						SetPlayerToPos(playerid,plocx,plocy+2, plocz);
						SetPlayerVirtualWorld(playerid,world);
						SetPlayerInterior(playerid,interior);
					}
					format(string, sizeof(string), "[INFO:] You teleported to %s.", GetPlayerNameEx(plo));
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_GRAD1, "[B£¥D:] Invalid ID.");
			}
			return 1;
		}
		if(strcmp(cmd, "/mgoto", true) == 0)
		{
			if(gPlayerData[playerid][pModerator] != 2)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /goto [playerid]");
				return 1;
			}
			new Float:plocx,Float:plocy,Float:plocz;
			new plo;
			plo = ReturnUser(tmp);
			if (IsPlayerConnected(plo))
			{
				if(plo != INVALID_PLAYER_ID)
				{
					GetPlayerPos(plo, plocx, plocy, plocz);
					new interior = GetPlayerInterior(plo);
					new world = GetPlayerVirtualWorld(plo);

					if (GetPlayerState(playerid) == 2)
					{
						SetVehicleToPos(idcar, plocx, plocy+4, plocz);
						SetPlayerVirtualWorld(playerid,world);
						SetPlayerInterior(playerid,interior);
					}
					else
					{
						SetPlayerToPos(playerid,plocx,plocy+2, plocz);
						SetPlayerVirtualWorld(playerid,world);
						SetPlayerInterior(playerid,interior);
					}
					format(string, sizeof(string), "[INFO:] You teleported to %s.", GetPlayerNameEx(plo));
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);

					printf("[MODERATOR:] %s used TP to X: %f, Y: %f, Z: %f", GetPlayerNameEx(playerid), plocx, plocy+2, plocz);
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_GRAD1, "[B£¥D:] Invalid ID.");
			}
			return 1;
		}
		if(strcmp(cmd, "/gotols", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 1)
				return 0;
			if (GetPlayerState(playerid) == 2)
			{
				SetVehicleToPos(idcar, 1529.6,-1691.2,13.3);
			}
			else
			{
				SetPlayerToPos(playerid, 1529.6,-1691.2,13.3);
			}
			SetPlayerInterior(playerid,0);
			SetPlayerVirtualWorld(playerid,0);
			return 1;
		}
		if(strcmp(cmd, "/gotohosp", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 1)
				return 0;
			if (GetPlayerState(playerid) == 2)
			{
				SetVehicleToPos(idcar, 1180.310059, -1358.306396, 571.764954);
			}
			else
			{
				SetPlayerToPos(playerid, 1180.310059, -1358.306396, 571.764954);
			}
			SetPlayerInterior(playerid,0);
			SetPlayerVirtualWorld(playerid,0);
			return 1;
		}
		if(strcmp(cmd, "/gotolv", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 1)
				return 0;
			if (GetPlayerState(playerid) == 2)
			{
				SetVehicleToPos(idcar, 1699.2, 1435.1, 10.7);
			}
			else
			{
				SetPlayerToPos(playerid, 1699.2,1435.1, 10.7);
			}
			SetPlayerInterior(playerid,0);
			SetPlayerVirtualWorld(playerid,0);
			return 1;
		}
		if(strcmp(cmd, "/gotoprison", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 1)
				return 0;
			if (GetPlayerState(playerid) == 2)
			{
				SetVehicleToPos(idcar, 2907.836426, -1963.764160, 9.668781);
			}
			else
			{
				SetPlayerToPos(playerid, 2907.836426, -1963.764160, 9.668781);
			}
			SetPlayerInterior(playerid,0);
			SetPlayerVirtualWorld(playerid,0);
			return 1;
		}
		if(strcmp(cmd, "/gethere", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 1)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /gethere [playerid]");
				return 1;
			}
			new Float:plocx,Float:plocy,Float:plocz;
			new plo;
			plo = ReturnUser(tmp);
			if (IsPlayerConnected(plo))
			{
				if(plo != INVALID_PLAYER_ID)
				{
					GetPlayerPos(playerid, plocx, plocy, plocz);
					new interior = GetPlayerInterior(playerid);
					new world = GetPlayerVirtualWorld(playerid);

					if (GetPlayerState(playerid) == 2)
					{
						new tmpcar2 = GetPlayerVehicleID(plo);
						SetVehicleToPos(tmpcar2, plocx, plocy+4, plocz);
						SetPlayerVirtualWorld(plo,world);
						SetPlayerInterior(plo,interior);
					}
					else
					{
						SetPlayerToPos(plo,plocx,plocy+2, plocz);
						SetPlayerVirtualWorld(plo,world);
						SetPlayerInterior(plo,interior);
					}
					format(string, sizeof(string), "[INFO:] You teleported %s to you.", GetPlayerNameEx(plo));
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
				}
			}
			else
			{
				format(string, sizeof(string), "   %d is not an active player.", plo);
				SendClientMessage(playerid, COLOR_GRAD1, string);
			}
			return 1;
		}
		if(strcmp(cmd, "/mgethere", true) == 0)
		{
			if(gPlayerData[playerid][pModerator] < 1)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /mgethere [playerid]");
				return 1;
			}
			new Float:plocx,Float:plocy,Float:plocz;
			new plo;
			plo = ReturnUser(tmp);
			if (IsPlayerConnected(plo))
			{
				if(plo != INVALID_PLAYER_ID)
				{
					GetPlayerPos(playerid, plocx, plocy, plocz);
					new interior = GetPlayerInterior(playerid);
					new world = GetPlayerVirtualWorld(playerid);

					if (GetPlayerState(playerid) == 2)
					{
						new tmpcar2 = GetPlayerVehicleID(plo);
						SetVehicleToPos(tmpcar2, plocx, plocy+4, plocz);
						SetPlayerVirtualWorld(plo,world);
						SetPlayerInterior(plo,interior);
					}
					else
					{
						SetPlayerToPos(plo,plocx,plocy+2, plocz);
						SetPlayerVirtualWorld(plo,world);
						SetPlayerInterior(plo,interior);
					}
					format(string, sizeof(string), "[INFO:] You teleported %s to you.", GetPlayerNameEx(plo));
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);

					printf("[MODERATOR:] %s used TP to for player %s, X: %f, Y: %f, Z: %f", GetPlayerNameEx(playerid), GetPlayerNameEx(plo), plocx, plocy+2, plocz);
				}
			}
			else
			{
				format(string, sizeof(string), "   %d is not an active player.", plo);
				SendClientMessage(playerid, COLOR_GRAD1, string);
			}
			return 1;
		}
		if(strcmp(cmd, "/freeze", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 1)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /freeze [playerid]");
				return 1;
			}
			new playa;
			playa = ReturnUser(tmp);
			if(IsPlayerConnected(playa))
			{
				if(playa != INVALID_PLAYER_ID)
				{
					TogglePlayerControllable(playa, 0);
					format(string, sizeof(string), "[INFO:] You where froze by %s.",GetPlayerNameEx(playerid));
					SendClientMessage(playa,COLOR_LIGHTYELLOW2,string);
					format(string, sizeof(string), "[INFO:] You froze %s.",GetPlayerNameEx(playa));
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2,string);
					printf("[WARNING:] /freeze used by %s", gPlayerData[playerid][pName]);
				}
			}
			return 1;
		}

		if(strcmp(cmd, "/unfreeze", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 1)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /unfreeze [playerid]");
				return 1;
			}
			new playa;
			playa = ReturnUser(tmp);
			if(IsPlayerConnected(playa))
			{
				if(playa != INVALID_PLAYER_ID)
				{
					TogglePlayerControllable(playa, 1);
					format(string, sizeof(string), "[INFO:] You where unfroze by %s.",GetPlayerNameEx(playerid));
					SendClientMessage(playa,COLOR_LIGHTYELLOW2,string);
					format(string, sizeof(string), "[INFO:] You unfroze %s.",GetPlayerNameEx(playa));
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2,string);
					printf("[WARNING:] /unfreeze used by %s", gPlayerData[playerid][pName]);
				}
			}
			return 1;
		}
		if(strcmp(cmd, "/mfreeze", true) == 0)
		{
			if(gPlayerData[playerid][pModerator] < 1)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /mfreeze [playerid]");
				return 1;
			}
			new playa;
			playa = ReturnUser(tmp);
			if(IsPlayerConnected(playa))
			{
				if(playa != INVALID_PLAYER_ID)
				{
					if(gPlayerData[playa][pAdmin] > 0)
					{
						SendClientMessage(playerid, COLOR_RED, "[B£¥D:] Nie jesteœ upowa¿niony do u¿ywania tej komendy na adminie !");
						return 1;
					}
					TogglePlayerControllable(playa, 0);
					format(string, sizeof(string), "[INFO:] You where froze by %s.",GetPlayerNameEx(playerid));
					SendClientMessage(playa,COLOR_LIGHTYELLOW2,string);
					format(string, sizeof(string), "[INFO:] You froze %s.",GetPlayerNameEx(playa));
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2,string);
					printf("[WARNING:] /mfreeze used by %s", gPlayerData[playerid][pName]);
				}
			}
			return 1;
		}
		if(strcmp(cmd, "/munfreeze", true) == 0)
		{
			if(gPlayerData[playerid][pModerator] < 1)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /munfreeze [playerid]");
				return 1;
			}
			new playa;
			playa = ReturnUser(tmp);
			if(IsPlayerConnected(playa))
			{
				if(playa != INVALID_PLAYER_ID)
				{
					TogglePlayerControllable(playa, 1);
					format(string, sizeof(string), "[INFO:] You where unfroze by %s.",GetPlayerNameEx(playerid));
					SendClientMessage(playa,COLOR_LIGHTYELLOW2,string);
					format(string, sizeof(string), "[INFO:] You unfroze %s.",GetPlayerNameEx(playa));
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2,string);
					printf("[WARNING:] /munfreeze used by %s", gPlayerData[playerid][pName]);
				}
			}
			return 1;
		}
		if(strcmp(cmd, "/gametext", true) == 0)
		{
			if (gPlayerData[playerid][pAdmin] < 1)
				return 0;
			new length = strlen(cmdtext);
			while ((idx < length) && (cmdtext[idx] <= ' '))
			{
				idx++;
			}
			new offset = idx;
			new result[64];
			while ((idx < length) && ((idx - offset) < (sizeof(result) - 1)))
			{
				result[idx - offset] = cmdtext[idx];
				idx++;
			}
			result[idx - offset] = EOS;
			if(!strlen(result))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /gametext [textformat ~n~=Newline ~r~=Red ~g~=Green ~b~=Blue ~w~=White ~y~=Yellow]");
				return 1;
			}
			format(string, sizeof(string), "~b~%s: ~w~%s",GetPlayerNameEx(playerid),result);
			foreach(Player, i )
			{
				GameTextForPlayer(i, string, 5000, 6);
			}
			return 1;
		}
		/*if(strcmp(cmd, "/ajail", true) == 0)
		{
			if(IsPlayerConnected(playerid))
			{
				tmp = strtok(cmdtext, idx);
				if(!strlen(tmp))
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /ajail [playerid] [minutes] [powód]");
					return 1;
				}
				new playa;
				new money;
				playa = ReturnUser(tmp);
				tmp = strtok(cmdtext, idx);
				money = strval(tmp);
				if (gPlayerData[playerid][pAdmin] >= 2)
				{
					if(IsPlayerConnected(playa))
					{
						if(playa != INVALID_PLAYER_ID)
						{
							format(string, sizeof(string), "[INFO:] Uwiêzi³eœ %s na %d munut.", GetPlayerNameEx(playa), money);
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
							format(string, sizeof(string), "[INFO:] Zosta³eœ uwiêziony %s na %d minut.", GetPlayerNameEx(playerid),money);
							SendClientMessage(playa, COLOR_LIGHTYELLOW2, string);
							format(string, sizeof(string), "[ADMIN:] %s zosta³ uwiêziony przez %s na %d minut", GetPlayerNameEx(playerid), GetPlayerNameEx(playa), money);
							SendAdminMessage(COLOR_YELLOW, string);
							ResetPlayerWeapons(playa);
							//WantedPoints[playa] = 0;
							gPlayerData[playa][pJailed] = 1;
							gPlayerData[playa][pJailTime] = money*60;
							SetPlayerInterior(playa, 6);
							SetPlayerToPos(playa, 264.6288,77.5742,1001.0391);
							SetPlayerVirtualWorld(playa,2);
						}
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie jesteœ administratorem.");
				}
			}
			return 1;
		}*/
		if(strcmp(cmd, "/unknowngametext", true) == 0)
		{
			if (gPlayerData[playerid][pAdmin] < 1)
				return 0;
			tmp = strtok(cmdtext, idx);
			new txtid;
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /unknowngametext ");
				return 1;
			}
			txtid = strval(tmp);
			if(txtid == 2)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:]");
				return 1;
			}
			new length = strlen(cmdtext);
			while ((idx < length) && (cmdtext[idx] <= ' '))
			{
				idx++;
			}
			new offset = idx;
			new result[128];
			while ((idx < length) && ((idx - offset) < (sizeof(result) - 1)))
			{
				result[idx - offset] = cmdtext[idx];
				idx++;
			}
			result[idx - offset] = EOS;
			if(!strlen(result))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /unknowngametext <type> [cnnc textformat ~n~=Newline ~r~=Red ~g~=Green ~b~=Blue ~w~=White ~y~=Yellow]");
				return 1;
			}
			format(string, sizeof(string), "~w~%s",result);
			foreach(Player, i )
			{
				GameTextForPlayer(i, string, 5000, txtid);
			}
			return 1;
		}
		if(strcmp(cmd, "/fixveh2", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			if(IsPlayerInAnyVehicle(playerid))
			{
				SetVehicleHealth(idcar, 1000.0);
			}
			return 1;
		}
		if(strcmp(cmd, "/fixveh", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			if(IsPlayerInAnyVehicle(playerid))
			{
				RepairVehicle(idcar);
				gVehData[tmpcar][CarDamaged] = 0;
				gVehData[tmpcar][CarRepairTimeLeft] = 0;
				gVehData[tmpcar][CarHealth] = 1000.0;
				
				SaveVehData( tmpcar, "CarHealth" );
				SaveVehData( tmpcar, "CarDamaged" );
				SaveVehData( tmpcar, "CarRepairTimeLeft" );
			}
			return 1;
		}
		if(strcmp(cmd, "/money", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] != 5)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /money [playerid] [money]");
				return 1;
			}
			new playa;
			new money;
			playa = ReturnUser(tmp);
			tmp = strtok(cmdtext, idx);
			money = strval(tmp);
			if(IsPlayerConnected(playa))
			{
				if(playa != INVALID_PLAYER_ID)
				{
					SetPlayerCash(playa, money);
				}
			}
			return 1;
		}
	/*	if (strcmp(cmd, "/register", true) ==0 )
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] We Dont Use That Command! Just Type Your Password");
		}
		if (strcmp(cmd, "/loguj", true) ==0 || strcmp(cmd, "/l", true) ==0)
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] We Dont Use That Command! Just Type Your Password");
		}*/
		if(strcmp(cmd, "/agivemats", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] != 5)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /agivemats [playerid] [mats]");
				return 1;
			}
			new playa;
			new money;
			playa = ReturnUser(tmp);
			tmp = strtok(cmdtext, idx);
			money = strval(tmp);
			if(IsPlayerConnected(playa))
			{
				if(playa != INVALID_PLAYER_ID)
				{
					gPlayerData[playerid][pMaterials] += money;

					SavePlayerData(playerid, "Materials");
				}
			}
			return 1;
		}
		if(strcmp(cmd, "/asetmats", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] != 5)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /asetmats [playerid] [mats]");
				return 1;
			}
			new playa;
			new money;
			playa = ReturnUser(tmp);
			tmp = strtok(cmdtext, idx);
			money = strval(tmp);
			if(IsPlayerConnected(playa))
			{
				if(playa != INVALID_PLAYER_ID)
				{
					gPlayerData[playerid][pMaterials] = money;

					SavePlayerData(playerid, "Materials");
				}
			}
			return 1;
		}
		if(strcmp(cmd, "/asetdrugs", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] != 5)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /asetdrugs [playerid] [drugs]");
				return 1;
			}
			new playa;
			new money;
			playa = ReturnUser(tmp);
			tmp = strtok(cmdtext, idx);
			money = strval(tmp);
			if(IsPlayerConnected(playa))
			{
				if(playa != INVALID_PLAYER_ID)
				{
					gPlayerData[playerid][pDrugs] = money;

					SavePlayerData(playerid, "Drugs");
				}
			}
			return 1;
		}
		if(strcmp(cmd, "/agivedrugs", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] != 5)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /agivedrugs [playerid] [drugs]");
				return 1;
			}
			new playa;
			new money;
			playa = ReturnUser(tmp);
			tmp = strtok(cmdtext, idx);
			money = strval(tmp);
			if(IsPlayerConnected(playa))
			{
				if(playa != INVALID_PLAYER_ID)
				{
					gPlayerData[playerid][pDrugs] += money;

					SavePlayerData(playerid, "Materials");
				}
			}
			return 1;
		}
		if(strcmp(cmd, "/givemoney", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 5)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /givemoney [playerid] [money]");
				return 1;
			}
			new playa;
			new money;
			playa = ReturnUser(tmp);
			tmp = strtok(cmdtext, idx);
			money = strval(tmp);
			if(IsPlayerConnected(playa))
			{
				if(playa != INVALID_PLAYER_ID)
				{
					GivePlayerCash(playa, money);
				}
			}
			return 1;
		}
		if(strcmp(cmd, "/weatherall", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] != 5)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /weatherall [weatherid]");
				return 1;
			}
			new weather;
			weather = strval(tmp);
			if(weather < 0||weather > 45) { SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] 0-45."); return 1; }
			SetWeather(weather);
			return 1;
		}
		if(strcmp(cmd, "/sethp", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /sethp [playerid] [health]");
				return 1;
			}
			new playa;
			new health;
			playa = ReturnUser(tmp);
			tmp = strtok(cmdtext, idx);
			health = strval(tmp);
			if(IsPlayerConnected(playa))
			{
				if(playa != INVALID_PLAYER_ID)
				{
					SetPlayerHealth(playa, health);
					gPlayerData[playa][pHP] = float(health);

					SavePlayerData(playerid, "HP");
				}
			}
			return 1;
		}
		if(strcmp(cmd, "/setarmour", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] != 5)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /setarmour [playerid] [armour]");
				return 1;
			}
			new playa;
			new health;
			playa = ReturnUser(tmp);
			tmp = strtok(cmdtext, idx);
			health = strval(tmp);
			if(IsPlayerConnected(playa))
			{
				if(playa != INVALID_PLAYER_ID)
				{
					SetPlayerArmour(playa, health);
				}
			}
			return 1;
		}
		if(strcmp(cmd, "/givegun", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] != 5)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /givegun [playerid/PartOName] [weaponid] [ammo]");
				return 1;
			}
			new playa;
			new gun;
			new ammo;
			playa = ReturnUser(tmp);
			tmp = strtok(cmdtext, idx);
			gun = strval(tmp);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /givegun [playerid/PartOName] [weaponid] [ammo]");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "3(Club) 4(knife) 5(bat) 6(Shovel) 7(Cue) 8(Katana) 10-13(Dildo) 14(Flowers) 16(Grenades) 18(Molotovs) 22(Pistol) 23(SPistol)");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "24(Eagle) 25(shotgun) 29(MP5) 30(AK47) 31(M4) 33(Rifle) 34(Sniper) 37(Flamethrower) 41(spray) 42(exting) 43(Camera) 46(Parachute)");
				return 1;
			}
			if(gun > 1||gun < 47)
			{
				tmp = strtok(cmdtext, idx);
				ammo = strval(tmp);
				if(ammo < 1 || ammo > 999)
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Ammo must be , 1-999.");
					return 1;
				}
				if(IsPlayerConnected(playa))
				{
					if(playa != INVALID_PLAYER_ID)
					{
						GivePlayerGun(playa, gun, ammo);
					}
				}
			}
			return 1;
		}
		if(strcmp(cmd, "/dajbron", true) == 0)
		{
			if(IsPlayerConnected(playerid))
			{
				tmp = strtok(cmdtext, idx);
				if(!strlen(tmp))
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /dajbron [playerid/PartOName] [weaponid] [ammo]");
					return 1;
				}
				new playa;
				new gun;
				new ammo;
				playa = ReturnUser(tmp);
				tmp = strtok(cmdtext, idx);
				gun = strval(tmp);
				if(!strlen(tmp))
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /givegun [playerid/PartOName] [weaponid] [ammo]");
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "3(Club) 4(knife) 5(bat) 6(Shovel) 7(Cue) 8(Katana) 10-13(Dildo) 14(Flowers) 16(Grenades) 18(Molotovs) 22(Pistol) 23(SPistol)");
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "24(Eagle) 25(shotgun) 29(MP5) 30(AK47) 31(M4) 33(Rifle) 34(Sniper)");
					return 1;
				}
				if(gun >= 1 && gun <= 34)
				{
					tmp = strtok(cmdtext, idx);
					ammo = strval(tmp);
					if(ammo < 1 || ammo > 30)
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Amunicji mozesz dac tylko : 1-30.");
						return 1;
					}
					if(gunGiven[playa] == 1)
					{
						SendClientMessage(playerid, COLOR_RED, "[INFO:] Musisz odczekaæ 2 minuty zanim bêdziesz móg³ znów przekazaæ graczowi broñ !");
						return 1;
					}
					if (gPlayerData[playerid][pFaction] == 9)
					{
						if(IsPlayerConnected(playa))
						{
							if(playa != INVALID_PLAYER_ID)
							{
								gunGiven[playa] = 1;
								GiveGunTimer(playa);
								GivePlayerGun(playa, gun, ammo);
								format(string, sizeof(string), "[INFO:] Da³eœ broñ %d %s na zwiêkszenie poziomu skili !", gun, playa);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2,string);
								format(string, sizeof(string), "[INFO:] Otrzyma³eœ od %s broñ %d", GetPlayerNameEx(playerid), gun);
								SendClientMessage(playa, COLOR_LIGHTYELLOW2,string);
								new stringTMP[256];
								format(stringTMP, sizeof(stringTMP), "[GOVERNMENT:] Bron, wydana przez: %s dla %s, ID broni: %d, ammo: %d", gPlayerData[playerid][pName], gPlayerData[playa][pName], gun, ammo);
								GovermentLog(stringTMP);
							}
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie jesteœ urzednikiem.");
					}
				}
			}
			return 1;
		}
		if(strcmp(cmd, "/fuelcars", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] != 5)
				return 0;
			for(new c = 0; c < sizeof(gVehData); c++)
			{
				gVehData[c][CarFuel] = float(VehFTank(c+1));

				SaveVehData(c, "CarFuel");
			}
			SendClientMessageToAll(COLOR_ADMINCMD, "[INFO:] Wszystkie samochody zosta³y zatankowane przez Adminstratora.");
			return 1;
		}
		if(strcmp(cmd, "/unlockcars", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] != 5)
				return 0;
			for(new c = 0; c < sizeof(gVehData); c++)
			{
				gVehData[c][Closed] = 0;

				SaveVehData(c, "Closed");
			}
			foreach(Player, i )
			{
				VehicleLockedPlayer[i] = 999;
			}
			SendClientMessageToAll(COLOR_ADMINCMD, "[INFO:] Wszystkie samochody zosta³y otwarte przez administratora.");
			return 1;
		}
		if(strcmp(cmd, "/setadmin", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] != 5)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /setadmin [playerid] [adminlevel]");
				return 1;
			}
			new para1;
			new level;
			para1 = ReturnUser(tmp);
			tmp = strtok(cmdtext, idx);
			level = strval(tmp);
			if(IsPlayerConnected(para1))
			{
				if(para1 != INVALID_PLAYER_ID)
				{
					gPlayerData[para1][pAdmin] = level;

					SavePlayerData(para1, "Admin");

					format(string, sizeof(string), "[INFO:] %s mianowa³ Ciê na administratora lvlu: %d.", GetPlayerNameEx(playerid),level);
					SendClientMessage(para1, COLOR_WHITE, string);
					format(string, sizeof(string), "[INFO:] You have made %s an administrator - Level: %d.", GetPlayerNameEx(para1),level);
					SendClientMessage(playerid, COLOR_WHITE, string);
					printf("[WARNING:] /setadmin has been used by %s for %s", GetPlayerNameEx(playerid), GetPlayerNameEx(para1));
				}
			}
			return 1;
		}
		if(strcmp(cmd, "/makemod", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] != 5)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /makemod [playerid] ");
				return 1;
			}
			new para1;
			para1 = ReturnUser(tmp);
			tmp = strtok(cmdtext, idx);
			if(IsPlayerConnected(para1))
			{
				if(para1 != INVALID_PLAYER_ID)
				{
					gPlayerData[para1][pModerator] = 1;

					SavePlayerData(para1, "Moderator");

					format(string, sizeof(string), "[INFO:] %s mianowa³ Cie moderatorem !", GetPlayerNameEx(playerid));
					SendClientMessage(para1, COLOR_WHITE, string);
					format(string, sizeof(string), "[INFO:] You have made %s an Moderator.", GetPlayerNameEx(para1));
					SendClientMessage(playerid, COLOR_WHITE, string);

					printf("[WARNING:] /makemod has been used by %s for %s", GetPlayerNameEx(para1), GetPlayerNameEx(playerid));
				}
			}
			return 1;
		}
		if(strcmp(cmd, "/unmakemod", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /unmakemod [playerid] ");
				return 1;
			}
			new para1;
			para1 = ReturnUser(tmp);
			tmp = strtok(cmdtext, idx);
			if(IsPlayerConnected(para1))
			{
				if(para1 != INVALID_PLAYER_ID)
				{
					gPlayerData[para1][pModerator] = 0;

					SavePlayerData(playerid, "Moderator");

					format(string, sizeof(string), "[INFO:] %s pozbawi³ Cie funkcji moderatora !", GetPlayerNameEx(playerid));
					SendClientMessage(para1, COLOR_WHITE, string);
					format(string, sizeof(string), "[INFO:] You have dismade %s an Moderator.", GetPlayerNameEx(para1));
					SendClientMessage(playerid, COLOR_WHITE, string);
				}
			}
			return 1;
		}
		if(strcmp(cmd, "/podnieslev", true) == 0)
		{
			if( !gPlayerData[playerid][pFirstStudy] )
			{
				gPlayerData[playerid][pFirstStudy] = 1;
				SavePlayerData( playerid, "FirstStudy" );
				AddExpPoint(playerid);
				SendClientMessage( playerid, COLOR_GREEN, "[INFO:] Pierwszy raz podnios³eœ swoje umiejêtnoœci !" );
			}
			if(PlayerToPoint(1.0,playerid,SkillPosition[XPis],SkillPosition[YPis],SkillPosition[ZPis]))
			{
				if(gPlayerData[playerid][pPozwolenie] >= 1)
				{
					GivePlayerCash(playerid,-1000);
					DynamicFactions[FACTIONID_GOVERNMENT][fBank] += 1000;
					SaveFData(FACTIONID_GOVERNMENT, "Bank");
					
					gPlayerData[playerid][pSkillPointsPis]++;
					SavePlayerData(playerid, "SkillPointsPis");

					format(string, sizeof(string), "[INFO:] Podnios³eœ doœwiadczenie pistoletu do %d!", gPlayerData[playerid][pSkillPointsPis]);
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
					
					gPlayerData[playerid][pPozwolenie] --;
					SavePlayerData(playerid, "Pozwolenie");

					if(gPlayerData[playerid][pSkillPointsPis] == (4 + (gPlayerData[playerid][pSkillLevPis]*3)))
					{
						gPlayerData[playerid][pSkillLevPis]++;
						SavePlayerData(playerid, "SkillLevPis");
						SetPlayerSkillLevel(playerid, 0, gPlayerData[playerid][pSkillLevPis] * 100);

						format(string, sizeof(string), "[INFO:] Osi¹gn¹³eœ %d poziom poslugiwaniu sie pistoletem !", gPlayerData[playerid][pSkillLevPis]);
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie otrzyma³eœ pozwolenia na podniesienie umiejêtnoœci");
				}
			}
			if(PlayerToPoint(1.0,playerid,SkillPosition[XSil],SkillPosition[YSil],SkillPosition[ZSil]))
			{
				if(gPlayerData[playerid][pPozwolenie] >= 1)
				{
					GivePlayerCash(playerid,-1000);
					DynamicFactions[FACTIONID_GOVERNMENT][fBank] += 1000;
					SaveFData(FACTIONID_GOVERNMENT, "Bank");
					
					gPlayerData[playerid][pSkillPointsSil]++;
					SavePlayerData(playerid, "SkillPointsSil");					

					format(string, sizeof(string), "[INFO:] Podnios³eœ doœwiadczenie pistoletu z tlumnikiem do %d!", gPlayerData[playerid][pSkillPointsSil]);
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
					
					gPlayerData[playerid][pPozwolenie] --;
					SavePlayerData(playerid, "Pozwolenie");

					if(gPlayerData[playerid][pSkillPointsSil] == (4 + (gPlayerData[playerid][pSkillLevSil]*3)))
					{
						gPlayerData[playerid][pSkillLevSil]++;
						SavePlayerData(playerid, "SkillLevSil");
						SetPlayerSkillLevel(playerid, 1, gPlayerData[playerid][pSkillLevSil] * 100);

						format(string, sizeof(string), "[INFO:] Osi¹gn¹³eœ %d poziom poslugiwaniu sie pistoletem z t³umnikiem !", gPlayerData[playerid][pSkillLevPis]);
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie otrzyma³eœ pozwolenia na podniesienie umiejêtnoœci");
				}
			}
			if(PlayerToPoint(1.0,playerid,SkillPosition[XDes],SkillPosition[YDes],SkillPosition[ZDes]))
			{
				if(gPlayerData[playerid][pPozwolenie] >= 1)
				{
					GivePlayerCash(playerid,-2000);
					DynamicFactions[FACTIONID_GOVERNMENT][fBank] += 2000;
					SaveFData(FACTIONID_GOVERNMENT, "Bank");
					
					gPlayerData[playerid][pSkillPointsDes]++;
					SavePlayerData(playerid, "SkillPointsDes");

					format(string, sizeof(string), "[INFO:] Podnios³eœ doœwiadczenie deserta eagla do %d!", gPlayerData[playerid][pSkillPointsDes]);
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
					
					gPlayerData[playerid][pPozwolenie] --;
					SavePlayerData(playerid, "Pozwolenie");

					if(gPlayerData[playerid][pSkillPointsDes] == (4 + (gPlayerData[playerid][pSkillLevDes]*3)))
					{
						gPlayerData[playerid][pSkillLevDes]++;
						SavePlayerData(playerid, "SkillLevDes");
						SetPlayerSkillLevel(playerid, 2, gPlayerData[playerid][pSkillLevDes] * 100);

						format(string, sizeof(string), "[INFO:] Osi¹gn¹³eœ %d poziom poslugiwaniu sie desertem eaglem !", gPlayerData[playerid][pSkillLevDes]);
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie otrzyma³eœ pozwolenia na podniesienie umiejêtnoœci");
				}
			}
			if(PlayerToPoint(1.0,playerid,SkillPosition[XSho],SkillPosition[YSho],SkillPosition[ZSho]))
			{
				if(gPlayerData[playerid][pPozwolenie] >= 1)
				{
					GivePlayerCash(playerid,-2000);
					DynamicFactions[FACTIONID_GOVERNMENT][fBank] += 2000;
					SaveFData(FACTIONID_GOVERNMENT, "Bank");
					
					gPlayerData[playerid][pSkillPointsSho]++;
					SavePlayerData(playerid, "SkillPointsSho");

					format(string, sizeof(string), "[INFO:] Podnios³eœ doœwiadczenie shotganem do %d!", gPlayerData[playerid][pSkillPointsSho]);
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
					
					gPlayerData[playerid][pPozwolenie]--;
					SavePlayerData(playerid, "Pozwolenie");

					if(gPlayerData[playerid][pSkillPointsSho] == (4 + (gPlayerData[playerid][pSkillLevSho]*3)))
					{
						gPlayerData[playerid][pSkillLevSho]++;
						SavePlayerData(playerid, "SkillLevSho");
						SetPlayerSkillLevel(playerid, 4, gPlayerData[playerid][pSkillLevSho] * 100);

						format(string, sizeof(string), "[INFO:] Osi¹gn¹³eœ %d poziom poslugiwaniu sie shotganem !", gPlayerData[playerid][pSkillLevSho]);
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie otrzyma³eœ pozwolenia na podniesienie umiejêtnoœci");
				}
			}
			if(PlayerToPoint(1.0,playerid,SkillPosition[XSha],SkillPosition[YSha],SkillPosition[ZSha]))
			{
				if(gPlayerData[playerid][pPozwolenie] >= 1)
				{
					GivePlayerCash(playerid,-2000);
					DynamicFactions[FACTIONID_GOVERNMENT][fBank] += 2000;
					SaveFData(FACTIONID_GOVERNMENT, "Bank");
					
					gPlayerData[playerid][pSkillPointsSha]++;
					SavePlayerData(playerid, "SkillPointsSha");

					format(string, sizeof(string), "[INFO:] Podnios³eœ doœwiadczenie ogryska do %d!", gPlayerData[playerid][pSkillPointsSha]);
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
					
					gPlayerData[playerid][pPozwolenie]--;
					SavePlayerData(playerid, "Pozwolenie");

					if(gPlayerData[playerid][pSkillPointsSha] == (4 + (gPlayerData[playerid][pSkillLevSha]*3)))
					{
						gPlayerData[playerid][pSkillLevSha]++;
						SavePlayerData(playerid, "SkillLevSha");
						SetPlayerSkillLevel(playerid, 3, gPlayerData[playerid][pSkillLevSha] * 100);

						format(string, sizeof(string), "[INFO:] Osi¹gn¹³eœ %d poziom poslugiwaniu sie ogryskiem !", gPlayerData[playerid][pSkillLevSha]);
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie otrzyma³eœ pozwolenia na podniesienie umiejêtnoœci");
				}
			}
			if(PlayerToPoint(1.0,playerid,SkillPosition[XSpa],SkillPosition[YSpa],SkillPosition[ZSpa]))
			{
				if(gPlayerData[playerid][pPozwolenie] >= 1)
				{
					GivePlayerCash(playerid,-3000);
					DynamicFactions[FACTIONID_GOVERNMENT][fBank] += 3000;
					SaveFData(FACTIONID_GOVERNMENT, "Bank");
					
					gPlayerData[playerid][pSkillPointsSpa]++;
					SavePlayerData(playerid, "SkillPointsSpa");
					
					format(string, sizeof(string), "[INFO:] Podnios³eœ doœwiadczenie shotgana bojowego do %d!", gPlayerData[playerid][pSkillPointsSpa]);
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
					
					gPlayerData[playerid][pPozwolenie] --;
					SavePlayerData(playerid, "Pozwolenie");

					if(gPlayerData[playerid][pSkillPointsSpa] == (4 + (gPlayerData[playerid][pSkillLevSpa]*3)))
					{
						gPlayerData[playerid][pSkillLevSpa]++;
						SavePlayerData(playerid, "SkillLevSpa");
						SetPlayerSkillLevel(playerid, 5, gPlayerData[playerid][pSkillLevSpa] * 100);

						format(string, sizeof(string), "[INFO:] Osi¹gn¹³eœ %d poziom poslugiwaniu sie shotganem bojowym !", gPlayerData[playerid][pSkillLevSpa]);
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie otrzyma³eœ pozwolenia na podniesienie umiejêtnoœci");
				}
			}
			if(PlayerToPoint(1.0,playerid,SkillPosition[XMic],SkillPosition[YMic],SkillPosition[ZMic]))
			{
				if(gPlayerData[playerid][pPozwolenie] >= 1)
				{
					GivePlayerCash(playerid,-2000);
					DynamicFactions[FACTIONID_GOVERNMENT][fBank] += 2000;
					SaveFData(FACTIONID_GOVERNMENT, "Bank");
					
					gPlayerData[playerid][pSkillPointsMic]++;
					SavePlayerData(playerid, "SkillPointsMic");

					format(string, sizeof(string), "[INFO:] Podnios³eœ doœwiadczenie uzi do %d!", gPlayerData[playerid][pSkillPointsMic]);
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
					
					gPlayerData[playerid][pPozwolenie] --;
					SavePlayerData(playerid, "Pozwolenie");

					if(gPlayerData[playerid][pSkillPointsMic] == (4 + (gPlayerData[playerid][pSkillLevMic]*3)))
					{
						gPlayerData[playerid][pSkillLevMic]++;
						SavePlayerData(playerid, "SkillLevMic");
						SetPlayerSkillLevel(playerid, 6, gPlayerData[playerid][pSkillLevMic] * 100);

						format(string, sizeof(string), "[INFO:] Osi¹gn¹³eœ %d poziom poslugiwaniu sie uzi !", gPlayerData[playerid][pSkillLevMic]);
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie otrzyma³eœ pozwolenia na podniesienie umiejêtnoœci");
				}
			}
			if(PlayerToPoint(1.0,playerid,SkillPosition[XMp5],SkillPosition[YMp5],SkillPosition[ZMp5]))
			{
				if(gPlayerData[playerid][pPozwolenie] >= 1)
				{
					GivePlayerCash(playerid,-4000);
					DynamicFactions[FACTIONID_GOVERNMENT][fBank] += 4000;
					SaveFData(FACTIONID_GOVERNMENT, "Bank");
					
					gPlayerData[playerid][pSkillPointsMp5]++;
					SavePlayerData(playerid, "SkillPointsMp5");

					format(string, sizeof(string), "[INFO:] Podnios³eœ doœwiadczenie Mp5 do %d!", gPlayerData[playerid][pSkillPointsMp5]);
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
					
					gPlayerData[playerid][pPozwolenie] --;
					SavePlayerData(playerid, "Pozwolenie");

					if(gPlayerData[playerid][pSkillPointsMp5] == (4 + (gPlayerData[playerid][pSkillLevMp5]*3)))
					{
						gPlayerData[playerid][pSkillLevMp5]++;
						SavePlayerData(playerid, "SkillLevMp5");
						SetPlayerSkillLevel(playerid, 7, gPlayerData[playerid][pSkillLevMp5] * 100);

						format(string, sizeof(string), "[INFO:] Osi¹gn¹³eœ %d poziom poslugiwaniu sie Mp5 !", gPlayerData[playerid][pSkillLevMp5]);
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie otrzyma³eœ pozwolenia na podniesienie umiejêtnoœci");
				}
			}
			if(PlayerToPoint(1.0,playerid,SkillPosition[XAk],SkillPosition[YAk],SkillPosition[ZAk]))
			{
				if(gPlayerData[playerid][pPozwolenie] >= 1)
				{
					GivePlayerCash(playerid,-5000);
					DynamicFactions[FACTIONID_GOVERNMENT][fBank] += 5000;
					SaveFData(FACTIONID_GOVERNMENT, "Bank");
					
					gPlayerData[playerid][pSkillPointsAk]++;
					SavePlayerData(playerid, "SkillPointsAk");

					format(string, sizeof(string), "[INFO:] Podnios³eœ doœwiadczenie Ak do %d!", gPlayerData[playerid][pSkillPointsAk]);
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
					
					gPlayerData[playerid][pPozwolenie] --;
					SavePlayerData(playerid, "Pozwolenie");

					if(gPlayerData[playerid][pSkillPointsAk] == (4 + (gPlayerData[playerid][pSkillLevAk]*3)))
					{
						gPlayerData[playerid][pSkillLevAk]++;
						SavePlayerData(playerid, "SkillLevAk");
						SetPlayerSkillLevel(playerid, 8, gPlayerData[playerid][pSkillLevAk] * 100);

						format(string, sizeof(string), "[INFO:] Osi¹gn¹³eœ %d poziom poslugiwaniu sie ka³asznikowym !", gPlayerData[playerid][pSkillLevAk]);
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie otrzyma³eœ pozwolenia na podniesienie umiejêtnoœci");
				}
			}
			if(PlayerToPoint(1.0,playerid,SkillPosition[XM4],SkillPosition[YM4],SkillPosition[ZM4]))
			{
				if(gPlayerData[playerid][pPozwolenie] >= 1)
				{
					GivePlayerCash(playerid,-5000);
					DynamicFactions[FACTIONID_GOVERNMENT][fBank] += 5000;
					SaveFData(FACTIONID_GOVERNMENT, "Bank");
					
					gPlayerData[playerid][pSkillPointsM4]++;
					SavePlayerData(playerid, "SkillPointsM4");

					format(string, sizeof(string), "[INFO:] Podnios³eœ doœwiadczenie M4 do %d!", gPlayerData[playerid][pSkillPointsM4]);
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
					
					gPlayerData[playerid][pPozwolenie] --;
					SavePlayerData(playerid, "Pozwolenie");

					if(gPlayerData[playerid][pSkillPointsM4] == (4 + (gPlayerData[playerid][pSkillLevM4]*3)))
					{
						gPlayerData[playerid][pSkillLevM4]++;
						SavePlayerData(playerid, "SkillLevM4");
						SetPlayerSkillLevel(playerid, 9, gPlayerData[playerid][pSkillLevM4] * 100);

						format(string, sizeof(string), "[INFO:] Osi¹gn¹³eœ %d poziom poslugiwaniu sie M4 !", gPlayerData[playerid][pSkillLevM4]);
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie otrzyma³eœ pozwolenia na podniesienie umiejêtnoœci");
				}
			}
			if(PlayerToPoint(1.0,playerid,SkillPosition[XSni],SkillPosition[YSni],SkillPosition[ZSni]))
			{
				if(gPlayerData[playerid][pPozwolenie] >= 1)
				{
					GivePlayerCash(playerid,-6000);
					DynamicFactions[FACTIONID_GOVERNMENT][fBank] += 6000;
					SaveFData(FACTIONID_GOVERNMENT, "Bank");
					
					gPlayerData[playerid][pSkillPointsSni]++;
					SavePlayerData(playerid, "SkillPointsSni");

					format(string, sizeof(string), "[INFO:] Podnios³eœ doœwiadczenie Snajperki do %d!", gPlayerData[playerid][pSkillPointsSni]);
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
					
					gPlayerData[playerid][pPozwolenie] --;
					SavePlayerData(playerid, "Pozwolenie");

					if(gPlayerData[playerid][pSkillPointsSni] == (4 + (gPlayerData[playerid][pSkillLevSni]*3)))
					{
						gPlayerData[playerid][pSkillLevSni]++;
						SavePlayerData(playerid, "SkillLevSni");
						SetPlayerSkillLevel(playerid, 10, gPlayerData[playerid][pSkillLevSni] * 100);

						format(string, sizeof(string), "[INFO:] Osi¹gn¹³eœ %d poziom poslugiwaniu sie snajperka !", gPlayerData[playerid][pSkillLevSni]);
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie otrzyma³eœ pozwolenia na podniesienie umiejêtnoœci");
				}
			}
			if(PlayerToPoint(1.0,playerid,SkillPosition[XAng],SkillPosition[YAng],SkillPosition[ZAng]))
			{
				if(gPlayerData[playerid][pPozwolenie] >= 1)
				{
					GivePlayerCash(playerid,-400);
					DynamicFactions[FACTIONID_GOVERNMENT][fBank] += 400;
					SaveFData(FACTIONID_GOVERNMENT, "Bank");
					
					gPlayerData[playerid][pPktAng]++;
					SavePlayerData(playerid, "PktAng");

					format(string, sizeof(string), "[INFO:] Podnios³eœ doœwiadczenie angielskiego do %d!", gPlayerData[playerid][pPktAng]);
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
					
					gPlayerData[playerid][pPozwolenie] --;
					SavePlayerData(playerid, "Pozwolenie");

					if(gPlayerData[playerid][pPktAng] == (4 + (gPlayerData[playerid][pAng]*2)))
					{
						gPlayerData[playerid][pAng]++;
						SavePlayerData(playerid, "Ang");

						format(string, sizeof(string), "[INFO:] Osi¹gn¹³eœ %d poziom Angielskiego !", gPlayerData[playerid][pAng]);
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie otrzyma³eœ pozwolenia na podniesienie umiejêtnoœci");
				}
			}
			if(PlayerToPoint(1.0,playerid,SkillPosition[XWf],SkillPosition[YWf],SkillPosition[ZWf]))
			{
				if(gPlayerData[playerid][pPozwolenie] >= 1)
				{
					GivePlayerCash(playerid,-500);
					DynamicFactions[FACTIONID_GOVERNMENT][fBank] += 500;
					SaveFData(FACTIONID_GOVERNMENT, "Bank");
					
					gPlayerData[playerid][pPktWf]++;
					SavePlayerData(playerid, "PktWf");

					format(string, sizeof(string), "[INFO:] Podnios³eœ doœwiadczenie WF-u do %d!", gPlayerData[playerid][pPktWf]);
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
					
					gPlayerData[playerid][pPozwolenie] --;
					SavePlayerData(playerid, "Pozwolenie");

					if(gPlayerData[playerid][pPktWf] == (4 + (gPlayerData[playerid][pWf]*2)))
					{
						gPlayerData[playerid][pWf]++;
						SavePlayerData(playerid, "Wf");

						format(string, sizeof(string), "[INFO:] Osi¹gn¹³eœ %d poziom WF-u !", gPlayerData[playerid][pWf]);
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie otrzyma³eœ pozwolenia na podniesienie umiejêtnoœci");
				}
			}
			if(PlayerToPoint(1.0,playerid,SkillPosition[XMat],SkillPosition[YMat],SkillPosition[ZMat]))
			{
				if(gPlayerData[playerid][pPozwolenie] >= 1)
				{
					GivePlayerCash(playerid,-500);
					DynamicFactions[FACTIONID_GOVERNMENT][fBank] += 500;
					SaveFData(FACTIONID_GOVERNMENT, "Bank");
					
					gPlayerData[playerid][pPktMat]++;
					SavePlayerData(playerid, "PktMat");

					format(string, sizeof(string), "[INFO:] Podnios³eœ doœwiadczenie Matematyki do %d!", gPlayerData[playerid][pPktMat]);
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
					
					gPlayerData[playerid][pPozwolenie] --;
					SavePlayerData(playerid, "Pozwolenie");

					if(gPlayerData[playerid][pPktMat] == (4 + (gPlayerData[playerid][pMat]*2)))
					{
						gPlayerData[playerid][pMat]++;
						SavePlayerData(playerid, "Mat");

						format(string, sizeof(string), "[INFO:] Osi¹gn¹³eœ %d poziom Matematyki !", gPlayerData[playerid][pMat]);
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie otrzyma³eœ pozwolenia na podniesienie umiejêtnoœci");
				}
			}
			if(PlayerToPoint(1.0,playerid,SkillPosition[XPol],SkillPosition[YPol],SkillPosition[ZPol]))
			{
				if(gPlayerData[playerid][pPozwolenie] >= 1)
				{
					GivePlayerCash(playerid,-500);
					DynamicFactions[FACTIONID_GOVERNMENT][fBank] += 500;
					SaveFData(FACTIONID_GOVERNMENT, "Bank");
					
					gPlayerData[playerid][pPktPol]++;
					SavePlayerData(playerid, "PktPol");

					format(string, sizeof(string), "[INFO:] Podnios³eœ doœwiadczenie Polskiego do %d!", gPlayerData[playerid][pPktPol]);
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
					
					gPlayerData[playerid][pPozwolenie] --;
					SavePlayerData(playerid, "Pozwolenie");

					if(gPlayerData[playerid][pPktPol] == (4 + (gPlayerData[playerid][pPol]*2)))
					{
						gPlayerData[playerid][pPol]++;
						SavePlayerData(playerid, "Pol");

						format(string, sizeof(string), "[INFO:] Osi¹gn¹³eœ %d poziom Polskiego !", gPlayerData[playerid][pPol]);
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie otrzyma³eœ pozwolenia na podniesienie umiejêtnoœci");
				}
			}
			if(PlayerToPoint(1.0,playerid,SkillPosition[XHis],SkillPosition[YHis],SkillPosition[ZHis]))
			{
				if(gPlayerData[playerid][pPozwolenie] >= 1)
				{
					GivePlayerCash(playerid,-500);
					DynamicFactions[FACTIONID_GOVERNMENT][fBank] += 500;
					SaveFData(FACTIONID_GOVERNMENT, "Bank");
					
					gPlayerData[playerid][pPktHis]++;
					SavePlayerData(playerid, "PktHis");

					format(string, sizeof(string), "[INFO:] Podnios³eœ doœwiadczenie Historii do %d!", gPlayerData[playerid][pPktHis]);
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
					
					gPlayerData[playerid][pPozwolenie] --;
					SavePlayerData(playerid, "Pozwolenie");

					if(gPlayerData[playerid][pPktHis] == (4 + (gPlayerData[playerid][pHis]*2)))
					{
						gPlayerData[playerid][pHis]++;
						SavePlayerData(playerid, "His");

						format(string, sizeof(string), "[INFO:] Osi¹gn¹³eœ %d poziom Historii !", gPlayerData[playerid][pHis]);
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie otrzyma³eœ pozwolenia na podniesienie umiejêtnoœci");
				}
			}
			if(PlayerToPoint(1.0,playerid,SkillPosition[XFiz],SkillPosition[YFiz],SkillPosition[ZFiz]))
			{
				if(gPlayerData[playerid][pPozwolenie] >= 1)
				{
					GivePlayerCash(playerid,-500);
					DynamicFactions[FACTIONID_GOVERNMENT][fBank] += 500;
					SaveFData(FACTIONID_GOVERNMENT, "Bank");

					gPlayerData[playerid][pPktFiz]++;
					SavePlayerData(playerid, "PktFiz");

					format(string, sizeof(string), "[INFO:] Podnios³eœ doœwiadczenie Fizyki do %d!", gPlayerData[playerid][pPktFiz]);
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
					
					gPlayerData[playerid][pPozwolenie] --;
					SavePlayerData(playerid, "Pozwolenie");

					if(gPlayerData[playerid][pPktFiz] == (4 + (gPlayerData[playerid][pFiz]*2)))
					{
						gPlayerData[playerid][pFiz]++;
						SavePlayerData(playerid, "Fiz");

						format(string, sizeof(string), "[INFO:] Osi¹gn¹³eœ %d poziom Fizyki !", gPlayerData[playerid][pFiz]);
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie otrzyma³eœ pozwolenia na podniesienie umiejêtnoœci");
				}
			}
			if(PlayerToPoint(1.0,playerid,SkillPosition[XBio],SkillPosition[YBio],SkillPosition[ZBio]))
			{
				if(gPlayerData[playerid][pPozwolenie] >= 1)
				{
					GivePlayerCash(playerid,-500);
					DynamicFactions[FACTIONID_GOVERNMENT][fBank] += 500;
					SaveFData(FACTIONID_GOVERNMENT, "Bank");
					
					gPlayerData[playerid][pPktBio]++;
					SavePlayerData(playerid, "PktBio");

					format(string, sizeof(string), "[INFO:] Podnios³eœ doœwiadczenie Biologii do %d!", gPlayerData[playerid][pPktBio]);
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
					
					gPlayerData[playerid][pPozwolenie] --;
					SavePlayerData(playerid, "Pozwolenie");

					if(gPlayerData[playerid][pPktBio] == (4 + (gPlayerData[playerid][pBio]*2)))
					{
						gPlayerData[playerid][pBio]++;
						SavePlayerData(playerid, "Bio");

						format(string, sizeof(string), "[INFO:] Osi¹gn¹³eœ %d poziom Biologii !", gPlayerData[playerid][pBio]);
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie otrzyma³eœ pozwolenia na podniesienie umiejêtnoœci");
				}
			}

			return 1;
		}
		if(strcmp(cmd, "/dajpozwolenie", true) == 0)
		{
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /dajpozwolenie [playerid]");
				return 1;
			}
			new playa;
			playa = ReturnUser(tmp);
			tmp = strtok(cmdtext, idx);
			if(gPlayerData[playerid][pFaction] == 9)
			{
				if(IsPlayerConnected(playa))
				{
					if(playa == playerid)
					{
						SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie mo¿esz sam sobie wydaæ pozwolenia !");
						return 1;
					}
					gPlayerData[playa][pPozwolenie]++;

					SavePlayerData(playa, "Pozwolenie");

					format(string, sizeof(string), "[INFO:] Da³eœ pozwolenie %s na zwiêkszenie poziomu skili !", playa);
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2,string);
					format(string, sizeof(string), "[INFO:] Otrzyma³eœ od %s pozwolenie na zwiêkszenie poziomu skilli", GetPlayerNameEx(playerid));
					SendClientMessage(playa, COLOR_LIGHTYELLOW2,string);
					new stringTMP[256];
					format(stringTMP, sizeof(stringTMP), "[GOVERNMENT:] Pozwolenie, wydane przez: %s dla %s", gPlayerData[playerid][pName], gPlayerData[playa][pName]);
					GovermentLog(stringTMP);
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie jesteœ urzêdnikiem.");
			}
			return 1 ;
		}
		if(strcmp(cmd, "/dajdoktora", true) == 0)
		{
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /dajdoktora [playerid]");
				return 1;
			}
			new playa;
			playa = ReturnUser(tmp);
			tmp = strtok(cmdtext, idx);
			if (gPlayerData[playerid][pFaction] == 9 && gPlayerData[playerid][pRank] == 1 )
			{
				if(IsPlayerConnected(playa))
				{
					if(playa != INVALID_PLAYER_ID)
					{
						gPlayerData[playa][pDoktor] = 1;

						SavePlayerData(playa, "Doktor");

						format(string, sizeof(string), "[INFO:] Otrzymales tytul Doktora!", playerid);
						SendClientMessage(playa, COLOR_LIGHTYELLOW2,string);
					}
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] nie jesteœ urzednikiem.");
			}
			return 1 ;
		}
		if(strcmp(cmd, "/dajmagistra", true) == 0)
		{
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /dajmagistra [playerid]");
				return 1;
			}
			new playa;
			playa = ReturnUser(tmp);
			tmp = strtok(cmdtext, idx);
			if (gPlayerData[playerid][pFaction] == 9 && gPlayerData[playerid][pRank] == 1 )
			{
				if(IsPlayerConnected(playa))
				{
					if(playa != INVALID_PLAYER_ID)
					{
						gPlayerData[playa][pMagister] = 1;

						SavePlayerData(playa, "Magister");

						format(string, sizeof(string), "[INFO:] Otrzymales tytul Magistra!", playa);
						SendClientMessage(playa, COLOR_LIGHTYELLOW2,string);
					}
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] nie jesteœ urzednikiem.");
			}
			return 1 ;
		}
		if(strcmp(cmd, "/dajinz", true) == 0)
		{
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /dajinz [playerid]");
				return 1;
			}
			new playa;
			playa = ReturnUser(tmp);
			tmp = strtok(cmdtext, idx);
			if (gPlayerData[playerid][pFaction] == 9 && gPlayerData[playerid][pRank] == 1 )
			{
				if(IsPlayerConnected(playa))
				{
					if(playa != INVALID_PLAYER_ID)
					{
						gPlayerData[playa][pInz] = 1;

						SavePlayerData(playa, "Inz");

						format(string, sizeof(string), "[INFO:] Otrzymales tytul Inz!", playa);
						SendClientMessage(playa, COLOR_LIGHTYELLOW2,string);
					}
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] nie jesteœ urzednikiem.");
			}
			return 1 ;
		}
		if(strcmp(cmd, "/resettytulow", true) == 0)
		{
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /resettytulow [playerid]");
				return 1;
			}
			new playa;
			playa = ReturnUser(tmp);
			tmp = strtok(cmdtext, idx);
			if (gPlayerData[playerid][pFaction] == 9 && gPlayerData[playerid][pRank] == 1 )
			{
				if(IsPlayerConnected(playa))
				{
					if(playa != INVALID_PLAYER_ID)
					{
						gPlayerData[playa][pDoktor] = 0;
						gPlayerData[playa][pMagister] = 0;
						gPlayerData[playa][pInz] = 0;

						SavePlayerData(playa, "Doktor");
						SavePlayerData(playa, "Magister");
						SavePlayerData(playa, "Inz");

						format(string, sizeof(string), "[INFO:] Odebrano ci tytu³y!", playa);
						SendClientMessage(playa, COLOR_LIGHTYELLOW2,string);
					}
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie jesteœ urzêdnikiem.");
			}
			return 1 ;
		}
		if(strcmp(cmd, "/resetpktbroni", true) == 0)
		{
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /resetpktbroni [playerid]");
				return 1;
			}
			new playa;
			playa = ReturnUser(tmp);
			tmp = strtok(cmdtext, idx);
			if (gPlayerData[playerid][pFaction] == 9)
			{
				if(IsPlayerConnected(playa))
				{
					if(playa != INVALID_PLAYER_ID)
					{
						gPlayerData[playa][pSkillPointsPis] = 0;
						gPlayerData[playa][pSkillPointsSil] = 0;
						gPlayerData[playa][pSkillPointsDes] = 0;
						gPlayerData[playa][pSkillPointsSho] = 0;
						gPlayerData[playa][pSkillPointsSha] = 0;
						gPlayerData[playa][pSkillPointsSpa] = 0;
						gPlayerData[playa][pSkillPointsMic] = 0;
						gPlayerData[playa][pSkillPointsMp5] = 0;
						gPlayerData[playa][pSkillPointsAk] = 0;
						gPlayerData[playa][pSkillPointsM4] = 0;
						gPlayerData[playa][pSkillPointsSni] = 0;

						SavePlayerData(playa, "SkillPointsPis");
						SavePlayerData(playa, "SkillPointsSil");
						SavePlayerData(playa, "SkillPointsDes");
						SavePlayerData(playa, "SkillPointsSho");
						SavePlayerData(playa, "SkillPointsSha");
						SavePlayerData(playa, "SkillPointsSpa");
						SavePlayerData(playa, "SkillPointsMic");
						SavePlayerData(playa, "SkillPointsMp5");
						SavePlayerData(playa, "SkillPointsAk");
						SavePlayerData(playa, "SkillPointsM4");
						SavePlayerData(playa, "SkillPointsSni");

						format(string, sizeof(string), "[INFO:] Zresetowa³eœ punktt broni dla %d !",gPlayerData[playa][pName]);
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2,string);
						SendClientMessage(playa, COLOR_LIGHTYELLOW2, "[INFO:] Otrzyma³eœ reset pkt broni z powodu opuszczenia treningu/nie zaliczenia æwiczeñ");
					
						format(string, sizeof(string), "[GOVERNMENT:] Weapons reset done by: %s for %s", gPlayerData[playerid][pName], gPlayerData[playa][pName]);
						GovermentLog(string);
					}
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie jesteœ urzednikiem.");
			}
			return 1 ;
		}
		if(strcmp(cmd, "/tod", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] != 5)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /tod [timeofday] (0-23)");
				return 1;
			}
			new hour;
			hour = strval(tmp);
			SetWorldTime(hour);
			return 1;
		}
		if(strcmp(cmd, "/scommands", true) == 0 || strcmp(cmd, "/scmds", true) == 0)
		{
			if (gPlayerData[playerid][pModerator] >= 1)
			{
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[Moderator]: /mgoto - /mmute - /mkick - /mbanaccount - /moderator - /mspec - /mspecoff - /mjail");
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[Moderator]: /mfreeze - /munfreeze - /mgetip - / - / - / - /- /");
			}
			if (gPlayerData[playerid][pAdmin] >= 1)
			{
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[Level 1:] - (/a)dmin - /goto - /gethere - /warn - /mute - /check - /adminduty - /kick - /asuicide - /up");
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[Level 1:] - /setint - /setvw - /disarm - /error - /spec - /specoff - /cheatstats - /retake");
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[Level 1:] - /freeze - /unfreeze - /gametext - /gotolv - /gotosf - /gotols - /fixveh - /setskin -/fly - /checkweapons");
			}
			if (gPlayerData[playerid][pAdmin] >= 2)
			{
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[Level 2:] /ban - /banaccount - /oocstatus - /listenchat - /ajail - /Prison - /update");
			}
			if (gPlayerData[playerid][pAdmin] >= 3)
			{
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[Level 3:] /alistfaction - /getip - /unban");
			}
			if (gPlayerData[playerid][pAdmin] >= 4)
			{
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[Level 4:] /sethp - /setarmour - /fuelcars - /agivedrugs - /asetdrugs - /agivemats - /asetmats - /agiveproducts - /asetproducts");
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[Level 4:]/explode - /supervehslap - /vehslap");
			}
			if (gPlayerData[playerid][pAdmin] >= 5)
			{
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[Level 5:] /adonator - /acarcmds - /money - /givemoney - /givegun - /respawnvehicles - /rtc");
			}
			if (gPlayerData[playerid][pAdmin] >= 6)
			{
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[Level 6:] ");
			}
			if (gPlayerData[playerid][pAdmin] >= 7)
			{
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[Level 7:] - /unlockcars");
			}
			if (gPlayerData[playerid][pAdmin] >= 8)
			{
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[Level 8:] ");
			}
			if (gPlayerData[playerid][pAdmin] >= 9)
			{
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[Level 9:] ");
			}
			if (gPlayerData[playerid][pAdmin] >= 10)
			{
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[Level 10:] - /logoutall - /unknowngametext /makemod - /snews");
			}
			if (gPlayerData[playerid][pAdmin] >= 20)
			{
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[Owner:] - /gmx - /setadmin - /asetleader - /aresetfaction - /ajobcmds - /weatherall - /tod");
			}
			return 1;
		}
	//==========================================[NORMAL COMMANDS]=========================================================
		if(strcmp(cmd, "/wejdz", true) == 0)
		{
			for(new i = 0; i < sizeof(Houses); i++)
			{
				if (PlayerToPoint(1.0, playerid,Houses[i][EnterX], Houses[i][EnterY], Houses[i][EnterZ]))
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

							SavePlayerData(playerid, "Crash");

							TogglePlayerControllable(playerid, 0);
							unfreezeTPPlayer(playerid);
						}
						else if( Houses[i][HConfiscated] && !AdminDuty[playerid] )
						{
							GameTextForPlayer(playerid, "~r~Posiadlosc skonfiskowana", 5000, 1);
							PlayerActionMessage(playerid, 20.0, "naciska klamke nie uzyskuj¹c rezultatu");
							
							ApplyAnimation(playerid,"PED","CAR_doorlocked_RHS",4.1,0,1,1,0,0);
						}
						else
						{
							GameTextForPlayer(playerid, "~r~Zamkniete", 5000, 1);
							PlayerActionMessage(playerid, 20.0, "naciska klamke nie uzyskuj¹c rezultatu");
							
							ApplyAnimation(playerid,"PED","CAR_doorlocked_RHS",4.1,0,1,1,0,0);
						}
					}
				}
			}
			new Hour, Minute, Second;
			for(new i = 0; i < sizeof(Building); i++)
			{
				if (PlayerToPoint(1.0, playerid,Building[i][EnterX], Building[i][EnterY], Building[i][EnterZ]))
				{
					if(GetPlayerVirtualWorld(playerid) == Building[i][EnterWorld])
					{
						if( gPlayerData[playerid][pJob] != 22 && i == 49 && !AdminDuty[playerid] )
						{
							SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz wejœæ do tego budynku ! Nie jesteœ pracownikiem broni !");
							return 1;
						}
						gettime(Hour, Minute, Second);
						if((Hour < Building[i][Closed] && Hour >= Building[i][Opened]) || (Building[i][Opened] == Building[i][Closed]) || AdminDuty[playerid] == 1)
						{
							if(Building[i][Locked] == 0 || AdminDuty[playerid] >=  1)
							{
								if(GetPlayerCash(playerid) >= Building[i][EntranceFee] || Building[i][EntranceFee] == 0)
								{
									PlayerActionMessage(playerid,15.0,"naciska klamke i wchodzi do budynku");
									Audio_Play(playerid, AUDIO_DOOR_OPEN, false, false, false);

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

									SavePlayerData(playerid, "Crash");

									TogglePlayerControllable(playerid, 0);
									unfreezeTPPlayer(playerid);
								}
								else
								{
									GameTextForPlayer(playerid, "~r~Nie masz wystarczajacej ilosci pieniedzy", 5000, 1);
								}
							}
							else
							{
								GameTextForPlayer(playerid, "~r~Zamkniete", 5000, 1);
								PlayerActionMessage(playerid, 20.0, "naciska klamke nie uzyskuj¹c rezultatu");
								
								ApplyAnimation(playerid,"PED","CAR_doorlocked_RHS",4.1,0,1,1,0,0);
							}
						}
						else
						{
							format(string, sizeof(string), "[INFO:] Budynek zamkniêty ! Wróæ miêdzy godzin¹ %d a %d", Building [i][Opened], Building[i][Closed]);
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
							
							ApplyAnimation(playerid,"PED","CAR_doorlocked_RHS",4.1,0,1,1,0,0);
						}
					}
				}
			}
			for(new i = 0; i < sizeof(Businesses); i++)
			{
				if (PlayerToPoint(1.0, playerid,Businesses[i][EnterX], Businesses[i][EnterY], Businesses[i][EnterZ]))
				{
					if(GetPlayerVirtualWorld(playerid) == Businesses[i][EnterWorld])
					{
						if(gPlayerData[playerid][pBizKey] == i || GetPlayerCash(playerid) >= Businesses[i][EntranceCost] || Businesses[i][EntranceCost] == 0)
						{
							if(Businesses[i][Locked] && !AdminDuty[playerid])
							{
								GameTextForPlayer(playerid, "~r~Biznes zamkniety.", 5000, 1);
								PlayerActionMessage(playerid, 20.0, "naciska klamke nie uzyskuj¹c rezultatu");
								ApplyAnimation(playerid,"PED","CAR_doorlocked_RHS",4.1,0,1,1,0,0);
								return 1;
							}
							else if( Houses[i][HConfiscated] && !AdminDuty[playerid] )
							{
								GameTextForPlayer(playerid, "~r~Biznes skonfiskowany", 5000, 1);
								PlayerActionMessage(playerid, 20.0, "naciska klamke nie uzyskuj¹c rezultatu");								
								ApplyAnimation(playerid,"PED","CAR_doorlocked_RHS",4.1,0,1,1,0,0);
								return 1;
							}
							if(gPlayerData[playerid][pBizKey] != i && Businesses[i][EntranceCost] > 0)
							{
								GivePlayerCash(playerid,-Businesses[i][EntranceCost]);
								Businesses[i][Till] += Businesses[i][EntranceCost];
								SaveBizData(i, "Till");
								format(string, sizeof(string), "[INFO:] Pobrano op³ate w wysokoœci $%d za wejœcie do %s.", Businesses[i][EntranceCost],Businesses[i][BusinessName]);
								SendClientMessage(playerid,COLOR_LIGHTYELLOW2,string);
							}
							if(gPlayerData[playerid][pJob] == 19)
							{
								if(Businesses[i][Till] <= 0)
									SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz pracowaæ tutaj jako sprzedawca - brak pieniêdzy w kasie biznesu");
								else if(Businesses[i][Products] <= 0)
									SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz pracowaæ tutaj jako sprzedawca - brak produktów");
								else
									SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Aby rozpocz¹æ prace wpisz /rp - za ka¿de 5 minut spêdzone w pracy dostajesz 12$");
							}															
							// Businesses[i][Products]--;
							// SaveBizData(i, "Products");

							PlayerActionMessage(playerid,15.0,"naciska klamke i wchodzi do budynku");
							Audio_Play(playerid, AUDIO_DOOR_OPEN, false, false, false);

							SetPlayerInterior(playerid,Businesses[i][ExitInterior]);
							SetPlayerToPos(playerid,Businesses[i][ExitX],Businesses[i][ExitY],Businesses[i][ExitZ]);
							SetPlayerVirtualWorld(playerid,i);
							SetPlayerFacingAngle(playerid,Businesses[i][ExitAngle]);

							if( Businesses[i][BRadio1On] && Businesses[i][BRadio1Bought] )
								ResumeBizRadioStation( playerid, i );
							
							if(strcmp(gPlayerData[playerid][pName], Businesses[i][Owner], true) == 0)
							{
								gPlayerData[playerid][pCrashX] = Businesses[i][ExitX];
								gPlayerData[playerid][pCrashY] = Businesses[i][ExitY];
								gPlayerData[playerid][pCrashZ] = Businesses[i][ExitZ];
								gPlayerData[playerid][pCrashW] = i;
								gPlayerData[playerid][pCrashAngle] = Businesses[i][ExitAngle];
								gPlayerData[playerid][pCrashInt] = Businesses[i][ExitInterior];
							}
							else
							{
								gPlayerData[playerid][pCrashInt] = Businesses[i][EnterInterior];
								gPlayerData[playerid][pCrashX] = Businesses[i][EnterX];
								gPlayerData[playerid][pCrashY] = Businesses[i][EnterY];
								gPlayerData[playerid][pCrashZ] = Businesses[i][EnterZ];
								gPlayerData[playerid][pCrashW] = Businesses[i][EnterWorld];
								gPlayerData[playerid][pCrashAngle] = Businesses[i][EnterAngle];
							}

							SavePlayerData(playerid, "Crash");
							SavePlayerData(playerid, "Cash");

							TogglePlayerControllable(playerid, 0);
							unfreezeTPPlayer(playerid);
						}
						else
						{
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] Nie masz wystarczaj¹cej iloœci pieniêdzy !");
						}
					}
				}
			}
			return 1;
		}
		if(strcmp(cmd, "/wyjdz", true) == 0)
		{
			for(new i = 0; i < sizeof(Houses); i++)
			{
				if (PlayerToPoint(3.0, playerid,Houses[i][ExitX], Houses[i][ExitY], Houses[i][ExitZ]))
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

							SavePlayerData(playerid, "Crash");

							TogglePlayerControllable(playerid, 0);
							unfreezeTPPlayer(playerid);
						}
						else
						{
							GameTextForPlayer(playerid, "~r~Zamkniete", 5000, 1);
							PlayerActionMessage(playerid, 20.0, "naciska klamke nie uzyskuj¹c rezultatu");
						}
					}
				}
			}
			for(new i = 0; i < sizeof(Building); i++)
			{
				if (PlayerToPoint(3, playerid,Building[i][ExitX], Building[i][ExitY], Building[i][ExitZ]))
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

							SavePlayerData(playerid, "Crash");

							TogglePlayerControllable(playerid, 0);
							unfreezeTPPlayer(playerid);
						}
						else
						{
							GameTextForPlayer(playerid, "~r~Zamkniete", 5000, 1);
							PlayerActionMessage(playerid, 20.0, "naciska klamke nie uzyskuj¹c rezultatu");
						}
					}
				}
			}
			for(new i = 0; i < sizeof(Businesses); i++)
			{
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

							SavePlayerData(playerid, "Crash");

							TogglePlayerControllable(playerid, 0);
							unfreezeTPPlayer(playerid);
						}
						else
						{
							GameTextForPlayer(playerid, "~r~Zamkniete", 5000, 1);
							PlayerActionMessage(playerid, 20.0, "naciska klamke nie uzyskuj¹c rezultatu");
						}
					}
				}
			}
			return 1;
		}
		if(strcmp(cmd, "/asetcarhp", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			if(!IsPlayerInAnyVehicle(playerid))
				return 1;
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /asetcarhp [hp]");
				return 1;
			}
			new Float:tmpcarhp;
			new form[128];
			new veh;
			new Float:carhp = strval(tmp);
			SetVehicleHealth(veh, carhp);
			GetVehicleHealth(veh, tmpcarhp);
			format(form, sizeof(form), "[INFO:] Ustawi³eœ HP wozu na: %f", tmpcarhp);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, form);
			return 1;
		}
		if(strcmp(cmd, "/kuppojazd", true) == 0)
		{
			if( gPlayerData[playerid][pIsDeptor] )
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Znajdujesz siê w rejestrze d³u¿ników. Nie mo¿esz kupiæ ¿adnego pojazdu !");
				return 1;
			}
			// warunki zalezne od ktorych pojazd jest na sprzedaz
			if( gVehData[tmpcar][ReadyToSell] == 0 && ( gVehData[tmpcar][Owned] == 1 || gVehData[tmpcar][FactionCar] != 255 ) )
			{
				SendClientMessage(playerid, COLOR_RED, "[INFO:] Ten pojazd nie jest na sprzeda¿ !");
				return 1;
			}
			// limity modeli pojazdow
			if(gVehData[tmpcar][CarModel] == 416 || gVehData[tmpcar][CarModel] == 433 || gVehData[tmpcar][CarModel] == 431
			|| gVehData[tmpcar][CarModel] == 438 || gVehData[tmpcar][CarModel] == 437 || gVehData[tmpcar][CarModel] == 523
			|| gVehData[tmpcar][CarModel] == 427 || gVehData[tmpcar][CarModel] == 490 || gVehData[tmpcar][CarModel] == 528
			|| gVehData[tmpcar][CarModel] == 407 || gVehData[tmpcar][CarModel] == 544 || gVehData[tmpcar][CarModel] == 596
			|| gVehData[tmpcar][CarModel] == 598 || gVehData[tmpcar][CarModel] == 597 || gVehData[tmpcar][CarModel] == 599
			|| gVehData[tmpcar][CarModel] == 601 || gVehData[tmpcar][CarModel] == 420 || gVehData[tmpcar][CarModel] == 425
			|| gVehData[tmpcar][CarModel] == 497 || gVehData[tmpcar][CarModel] == 430 || gVehData[tmpcar][CarModel] == 472)
			{
				SendClientMessage(playerid, COLOR_RED, "[INFO:] Ten pojazd nie jest na sprzeda¿ !");
				return 1;
			}
			// sprawdzenie slotow pojazdow sprowadzonych
			for(new i = 0; i < sizeof(SpawnPlaceCars); i++)
			{
				// jesli pojazd wciaz jest w slocie to znaczy ze nie zostal jeszcze odebrany przez wlasciciela salonu
				if(SpawnPlaceCars[i][VehicleID] == idcar || SpawnPlacePlanes[i][VehicleID] == idcar || SpawnPlaceBoats[i][VehicleID] == idcar)
				{
					SendClientMessage(playerid, COLOR_RED, "[INFO:] Ten pojazd nie jest na sprzeda¿ !");
					return 1;
				}
			}
			if( gVehData[tmpcar][Price] <= 0 )
			{
				SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz kupiæ tego pojazdu ! - brak ustalonej ceny" );
				return 1;
			}
		
			new slot;
			// pojazd nowy - salonowy
			if(gVehData[tmpcar][Owned] == 0 && gVehData[tmpcar][CarType] == 0 && gVehData[tmpcar][FactionCar] == 255)
			{
				// sprawdzenie czy kupujacy posiada wystarczajaca ilosc pieniedzy na koncie frakcji
				if(gPlayerData[playerid][pCash] <(gVehData[tmpcar][Price] + floatround(float(gVehData[tmpcar][Price]) * DynamicTaxes[VatTaxMax],floatround_round)))
				{
					SendClientMessage(playerid, COLOR_WHITE, "[INFO:] Nie masz wystarczaj¹co du¿o pieniêdzy aby zakupiæ ten pojazd.");
					return 1;
				}
				// dane zalezne od typu pojazdu
				if(IsABoat(idcar))
				{
					// sprawdzenie czy gracz posiada odpowiedni level do kupna lodzi
					if(gPlayerData[playerid][pLevel] < BoatKeyLVL)
					{
						format(string, sizeof(string),"[INFO:] Musisz mieæ conajmniej %d poziom aby kupiæ ³ódŸ.",BoatKeyLVL);
						SendClientMessage(playerid, COLOR_WHITE, string);
						return 1;
					}

					// sprawdzenie czy gracz posiada wolny slot
					// if(PHaveItem(playerid, 2, gVehData[tmpcar][CarSerial]) > 0)
					// {
						// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Posiadasz ju¿ klucze do tego pojazdu");
						// return 1;
					// }
					if(PFirstFreeSlot(playerid) == 0)
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie masz miejsca na kolejny item !");
						return 1;
					}
					newVehSerial(tmpcar);
					PutPlayerInVehicle(playerid,tmpcar+1,0);
					slot = InsertPlayerItem(playerid, 2, gVehData[tmpcar][CarSerial], 0, 0);
					if(slot == 0)
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie masz miejsca na kolejny item !");
						return 1;
					}
					else
					{
						gVehData[tmpcar][LastDriverWKey] = gPlayerData[playerid][pName];
					}

					new plname[128];
					GetPlayerName(playerid, plname, sizeof(plname));

					// modyfikacja danych pojazdu
					gVehData[tmpcar][Owned] = 1;
					strmid(gVehData[tmpcar][Owner], plname, 0, strlen(plname), 128);

					SaveVehData(tmpcar, "Owned");
					SaveVehData(tmpcar, "Owner");

					// zmniejszenie ilosci pieniedzy gracza
					GivePlayerCash(playerid,-gVehData[tmpcar][Price]-floatround(gVehData[tmpcar][Price] * DynamicTaxes[VatTaxMax],floatround_round));

					// podatki
					DynamicFactions[FACTIONID_GOVERNMENT][fBank] += floatround(gVehData[tmpcar][Price] * DynamicTaxes[VatTaxMax],floatround_round);

					// zwolnienie slotu wlasciciela biznesu
					Businesses[gVehData[tmpcar][BusinessID]][VehicleCount]--;

					// zysk dla wlasciciela biznesu/salonu
					Businesses[gVehData[tmpcar][BusinessID]][Till] += gVehData[tmpcar][Price];

					// informacja dla kupujacego
					SendClientMessage(playerid, COLOR_WHITE, "[INFO:] Kupi³eœ ³ódŸ !");
					SendClientMessage(playerid, COLOR_WHITE, "[INFO:] Skorzystaj z komendy '/pomoc samochod'");

					// zapis
					SavePlayerData(playerid, "Cash");
					SaveBizData(gVehData[tmpcar][BusinessID], "Till");
					SaveBizData(gVehData[tmpcar][BusinessID], "VehicleCount");
					SaveFData(FACTIONID_GOVERNMENT, "Bank");

					// log
					new Year, Month, Day;
					getdate(Year, Month, Day);
					printf("[%d-%d-%d] [VEHICLE:] Vehicle id: %d has been bought by %s for %d$", Year, Month, Day, idcar, GetPlayerNameEx(playerid), gVehData[tmpcar][Price]);

					return 1;
				}
				if(IsAHelicopter(idcar))
				{
					// sprawdzenie czy gracz posiada odpowiedni level do kupna helikoptera
					if(gPlayerData[playerid][pLevel] < AirKeyLVL)
					{
						format(string, sizeof(string),"[INFO:] Musisz mieæ conajmniej %d poziom aby kupiæ helikopter.",AirKeyLVL);
						SendClientMessage(playerid, COLOR_WHITE, string);
						return 1;
					}

					new plname[128];
					GetPlayerName(playerid, plname, sizeof(plname));

					// sprawdzenie czy gracz posiada wolny slot
					if(PHaveItem(playerid, 2, gVehData[tmpcar][CarSerial]) > 0)
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Posiadasz ju¿ klucze do tego pojazdu");
						return 1;
					}
					slot = InsertPlayerItem(playerid, 2, gVehData[tmpcar][CarSerial], 0, 0);
					if(slot == 0)
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie masz miejsca na kolejny item !");
						return 1;
					}
					else
					{
						gVehData[tmpcar][LastDriverWKey] = gPlayerData[playerid][pName];
					}

					// modyfikacja danych pojazdu
					gVehData[tmpcar][Owned] = 1;
					strmid(gVehData[tmpcar][Owner], plname, 0, strlen(plname), 128);

					SaveVehData(tmpcar, "Owned");
					SaveVehData(tmpcar, "Owner");

					// zmniejszenie ilosci pieniedzy gracza
					GivePlayerCash(playerid,-gVehData[tmpcar][Price] - floatround(gVehData[tmpcar][Price] * DynamicTaxes[VatTaxMax],floatround_round));

					// podatki
					DynamicFactions[FACTIONID_GOVERNMENT][fBank] += floatround(gVehData[tmpcar][Price] * DynamicTaxes[VatTaxMax],floatround_round);

					// zwolnienie slotu wlasciciela biznesu
					Businesses[gVehData[tmpcar][BusinessID]][VehicleCount]--;

					// zysk dla wlasciciela biznesu/salonu
					Businesses[gVehData[tmpcar][BusinessID]][Till] += gVehData[tmpcar][Price];

					// informacja dla kupujacego
					SendClientMessage(playerid, COLOR_WHITE, "[INFO:] Kupi³eœ helikopter !");
					SendClientMessage(playerid, COLOR_WHITE, "[INFO:] Skorzystaj z komendy '/pomoc samochod'");

					// zapis
					SavePlayerData(playerid, "Cash");
					SaveBizData(gVehData[tmpcar][BusinessID], "Till");
					SaveBizData(gVehData[tmpcar][BusinessID], "VehicleCount");
					SaveFData(FACTIONID_GOVERNMENT, "Bank");

					// log
					new Year, Month, Day;
					getdate(Year, Month, Day);
					printf("[%d-%d-%d] [VEHICLE:] Vehicle id: %d has been bought by %s for %d$", Year, Month, Day, idcar, GetPlayerNameEx(playerid), gVehData[tmpcar][Price]);

					return 1;
				}
				if(IsAPlane(idcar))
				{
					// sprawdzenie czy gracz posiada odpowiedni level do kupna samolotu
					if(gPlayerData[playerid][pLevel] < AirKeyLVL)
					{
						format(string, sizeof(string),"[INFO:] Musisz mieæ conajmniej %d poziom aby kupiæ samolot.",AirKeyLVL);
						SendClientMessage(playerid, COLOR_WHITE, string);
						return 1;
					}

					// sprawdzenie czy gracz posiada wolny slot
					if(PHaveItem(playerid, 2, gVehData[tmpcar][CarSerial]) > 0)
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Posiadasz ju¿ klucze do tego pojazdu");
						return 1;
					}
					slot = InsertPlayerItem(playerid, 2, gVehData[tmpcar][CarSerial], 0, 0);
					if(slot == 0)
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie masz miejsca na kolejny item !");
						return 1;
					}
					else
					{
						gVehData[tmpcar][LastDriverWKey] = gPlayerData[playerid][pName];
					}

					new plname[128];
					GetPlayerName(playerid, plname, sizeof(plname));

					// modyfikacja danych pojazdu
					gVehData[tmpcar][Owned] = 1;
					strmid(gVehData[tmpcar][Owner], plname, 0, strlen(plname), 128);

					SaveVehData(tmpcar, "Owned");
					SaveVehData(tmpcar, "Owner");

					// zmniejszenie ilosci pieniedzy gracza
					GivePlayerCash(playerid, -gVehData[tmpcar][Price] - floatround(gVehData[tmpcar][Price] * DynamicTaxes[VatTaxMax],floatround_round));

					// podatki
					DynamicFactions[FACTIONID_GOVERNMENT][fBank] += floatround(gVehData[tmpcar][Price] * DynamicTaxes[VatTaxMax],floatround_round);

					// zwolnienie slotu wlasciciela biznesu
					Businesses[gVehData[tmpcar][BusinessID]][VehicleCount]--;

					// zysk dla wlasciciela biznesu/salonu
					Businesses[gVehData[tmpcar][BusinessID]][Till] += gVehData[tmpcar][Price];

					// informacja dla kupujacego
					SendClientMessage(playerid, COLOR_WHITE, "[INFO:] Kupi³eœ samolot !");
					SendClientMessage(playerid, COLOR_WHITE, "[INFO:] Skorzystaj z komendy '/pomoc samochod'");

					// zapis
					SavePlayerData(playerid, "Cash");
					SaveBizData(gVehData[tmpcar][BusinessID], "Till");
					SaveBizData(gVehData[tmpcar][BusinessID], "VehicleCount");
					SaveFData(FACTIONID_GOVERNMENT, "Bank");

					// log
					new Year, Month, Day;
					getdate(Year, Month, Day);
					printf("[%d-%d-%d] [VEHICLE:] Vehicle id: %d has been bought by %s for %d$", Year, Month, Day, idcar, GetPlayerNameEx(playerid), gVehData[tmpcar][Price]);

					return 1;
				}
				if(IsAPlane(idcar) == 0 && IsAHelicopter(idcar) == 0 && IsABoat(idcar) == 0)
				{
					// gracz ma za niski lvl
					if(gPlayerData[playerid][pLevel] < CarKey1LVL)
					{
						format(string, sizeof(string),"[INFO:] Musisz mieæ conajmniej %d poziom aby kupiæ pierwszy samochód.",CarKey1LVL);
						SendClientMessage(playerid, COLOR_WHITE, string);

						return 1;
					}
					// kupno pierwszego pojazdu
					if(gPlayerData[playerid][pLevel] >= CarKey1LVL)
					{
						// sprawdzenie czy gracz posiada wolny slot
						if(PHaveItem(playerid, 2, gVehData[tmpcar][CarSerial]) > 0)
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Posiadasz ju¿ klucze do tego pojazdu");
							return 1;
						}
						if(PFirstFreeSlot(playerid) == 0)
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie masz miejsca na kolejny item !");
							return 1;
						}
						newVehSerial(tmpcar);
						slot = InsertPlayerItem(playerid, 2, gVehData[tmpcar][CarSerial], 0, 0);
						if(slot == 0)
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie masz miejsca na kolejny item !");
							return 1;
						}
						else
						{
							gVehData[tmpcar][LastDriverWKey] = gPlayerData[playerid][pName];
						}

						new plname[128];
						GetPlayerName(playerid, plname, sizeof(plname));

						// modyfikacja danych pojazdu
						gVehData[tmpcar][Owned] = 1;
						strmid(gVehData[tmpcar][Owner], plname, 0, strlen(plname), 128);

						SaveVehData(tmpcar, "Owned");
						SaveVehData(tmpcar, "Owner");

						// zmniejszenie ilosci pieniedzy gracza
						GivePlayerCash(playerid, -gVehData[tmpcar][Price]-floatround(gVehData[tmpcar][Price] * DynamicTaxes[VatTaxMax],floatround_round));

						// podatki
						DynamicFactions[FACTIONID_GOVERNMENT][fBank] += floatround(gVehData[tmpcar][Price] * DynamicTaxes[VatTaxMax],floatround_round);

						// zwolnienie slotu wlasciciela biznesu
						Businesses[gVehData[tmpcar][BusinessID]][VehicleCount]--;

						// zysk dla wlasciciela biznesu/salonu
						Businesses[gVehData[tmpcar][BusinessID]][Till] += gVehData[tmpcar][Price];

						// informacja dla kupujacego
						if(gPlayerData[playerid][pFirstCar])
						{
							SendClientMessage(playerid, COLOR_WHITE, "[INFO:] Kupi³eœ pojazd !");
							SendClientMessage(playerid, COLOR_WHITE, "[INFO:] Skorzystaj z komendy '/pomoc samochod'");
						}
						else
						{
							SendClientMessage(playerid, COLOR_WHITE, "[INFO:] Kupi³eœ swój pierwszy samochód !");
							SendClientMessage(playerid, COLOR_WHITE, "[INFO:] Skorzystaj z komendy '/pomoc samochod'");

							AddExpPoint(playerid);

							gPlayerData[playerid][pFirstCar] = 1;

							SavePlayerData(playerid, "FirstCar");
						}

						// zapis
						SavePlayerData(playerid, "Cash");
						SaveBizData(gVehData[tmpcar][BusinessID], "Till");
						SaveBizData(gVehData[tmpcar][BusinessID], "VehicleCount");
						SaveFData(FACTIONID_GOVERNMENT, "Bank");

						// log
						new Year, Month, Day;
						getdate(Year, Month, Day);
						printf("[%d-%d-%d] [VEHICLE:] Vehicle id: %d has been bought by %s for %d$", Year, Month, Day, idcar, GetPlayerNameEx(playerid), gVehData[tmpcar][Price]);

						return 1;
					}
				}
			}
			// pojazd uzywany
			if(gVehData[tmpcar][ReadyToSell] == 1)
			{
				// sprawdzenie ilosci pieniedzy kupujacego
				if(gPlayerData[playerid][pCash] < gVehData[tmpcar][Price])
				{
					SendClientMessage(playerid, COLOR_WHITE, "[INFO:] Nie masz wystarczaj¹co du¿o pieniêdzy aby zakupiæ ten pojazd.");
					return 1;
				}
				new tmpplname[128];
				new sellerID = 999;
				new sellerslot;
				// pojazd uzywany - prywatny
				if(gVehData[tmpcar][Owned] == 1 && gVehData[tmpcar][FactionCar] == 255)
				{
					foreach(Player, i )
					{
						if(gPlayerLogged[i])
						{
							GetPlayerName(i, tmpplname, sizeof(tmpplname));
							if(IsABoat(idcar))
							{
								// sprawdzenie czy gracz posiada odpowiedni level do kupna lodzi
								if(gPlayerData[playerid][pLevel] < BoatKeyLVL)
								{
									format(string, sizeof(string),"[INFO:] Musisz mieæ conajmniej %d poziom aby kupiæ ³ódŸ.",BoatKeyLVL);
									SendClientMessage(playerid, COLOR_WHITE, string);
									return 1;
								}
								sellerslot = PHaveItem(i, 2, gVehData[tmpcar][CarSerial]);
								if(sellerslot > 0)
								{
									// porownanie id gracza kupujacego i sprzedajacego
									if(playerid == i)
									{
										SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie mo¿esz kupiæ w³asnego pojazdu !");
										return 1;
									}
									// sprawdzenie czy gracz posiada wolny slot
									if(PHaveItem(playerid, 2, gVehData[tmpcar][CarSerial]) > 0)
									{
										SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Posiadasz ju¿ klucze do tego pojazdu");
										return 1;
									}
									if(PFirstFreeSlot(playerid) == 0)
									{
										SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie masz miejsca na kolejny item !");
										return 1;
									}
									newVehSerial(tmpcar);
									slot = InsertPlayerItem(playerid, 2, gVehData[tmpcar][CarSerial], 0, 0);
									if(slot == 0)
									{
										SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie masz miejsca na kolejny item !");
										return 1;
									}
									else
									{
										gVehData[tmpcar][LastDriverWKey] = gPlayerData[playerid][pName];
									}

									// przypisanie zmiennej id sprzedajacego
									sellerID = i;

									// zwolnienie slotu gracza sprzedajacego
									RemovePlayerItemExUsed(i, sellerslot);

									// informacja dla kupujacego
									SendClientMessage(playerid, COLOR_WHITE, "[INFO:] Kupi³eœ ³ódŸ !");
									SendClientMessage(playerid, COLOR_WHITE, "[INFO:] Skorzystaj z komendy '/pomoc samochod'");

									// informacja dla sprzedajacego
									format(string, sizeof(string), "[INFO:] Gracz %s [%d] kupi³ od Ciebie pojazd !", GetPlayerNameEx(playerid), playerid);
									SendClientMessage(i, COLOR_LIGHTYELLOW2, string);

									break;
								}
							}
							if(IsAHelicopter(idcar))
							{
								// sprawdzenie czy gracz posiada odpowiedni level do kupna helikoptera
								if(gPlayerData[playerid][pLevel] < AirKeyLVL)
								{
									format(string, sizeof(string),"[INFO:] Musisz mieæ conajmniej %d poziom aby kupiæ helikopter.",AirKeyLVL);
									SendClientMessage(playerid, COLOR_WHITE, string);

									return 1;
								}
								// porownanie id pojazdu zapisanym w statystykach sprzedajacego do id pojazdu
								sellerslot = PHaveItem(i, 2, gVehData[tmpcar][CarSerial]);
								if(sellerslot > 0)
								{
									// porownanie id gracza kupujacego i sprzedajacego
									if(playerid == i)
									{
										SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie mo¿esz kupiæ w³asnego pojazdu !");
										return 1;
									}
									// sprawdzenie czy gracz posiada wolny slot
									if(PHaveItem(playerid, 2, gVehData[tmpcar][CarSerial]) > 0)
									{
										SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Posiadasz ju¿ klucze do tego pojazdu");
										return 1;
									}
									if(PFirstFreeSlot(playerid) == 0)
									{
										SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie masz miejsca na kolejny item !");
										return 1;
									}
									newVehSerial(tmpcar);
									slot = InsertPlayerItem(playerid, 2, gVehData[tmpcar][CarSerial], 0, 0);
									if(slot == 0)
									{
										SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie masz miejsca na kolejny item !");
										return 1;
									}
									else
									{
										gVehData[tmpcar][LastDriverWKey] = gPlayerData[playerid][pName];
									}

									// przypisanie zmiennej id sprzedajacego
									sellerID = i;

									// zwolnienie slotu gracza sprzedajacego
									RemovePlayerItemExUsed(i, sellerslot);

									// informacja dla kupujacego
									SendClientMessage(playerid, COLOR_WHITE, "[INFO:] Kupi³eœ helikopter !");
									SendClientMessage(playerid, COLOR_WHITE, "[INFO:] Skorzystaj z komendy '/pomoc samochod'");

									// informacja dla sprzedajacego
									format(string, sizeof(string), "[INFO:] Gracz %s [%d] kupi³ od Ciebie pojazd !", GetPlayerNameEx(playerid), playerid);
									SendClientMessage(i, COLOR_LIGHTYELLOW2, string);

									break;
								}
							}
							if(IsAPlane(idcar))
							{
								// sprawdzenie czy gracz posiada odpowiedni level do kupna samolotu
								if(gPlayerData[playerid][pLevel] < AirKeyLVL)
								{
									format(string, sizeof(string),"[INFO:] Musisz mieæ conajmniej %d poziom aby kupiæ samolot.",AirKeyLVL);
									SendClientMessage(playerid, COLOR_WHITE, string);
									return 1;
								}
								// porownanie id pojazdu zapisanym w statystykach sprzedajacego do id pojazdu
								sellerslot = PHaveItem(i, 2, gVehData[tmpcar][CarSerial]);
								if(sellerslot > 0)
								{
									// porownanie id gracza kupujacego i sprzedajacego
									if(playerid == i)
									{
										SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie mo¿esz kupiæ w³asnego pojazdu !");
										return 1;
									}
									// sprawdzenie czy gracz posiada wolny slot
									if(PHaveItem(playerid, 2, gVehData[tmpcar][CarSerial]) > 0)
									{
										SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Posiadasz ju¿ klucze do tego pojazdu");
										return 1;
									}
									if(PFirstFreeSlot(playerid) == 0)
									{
										SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie masz miejsca na kolejny item !");
										return 1;
									}
									newVehSerial(tmpcar);
									slot = InsertPlayerItem(playerid, 2, gVehData[tmpcar][CarSerial], 0, 0);
									if(slot == 0)
									{
										SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie masz miejsca na kolejny item !");
										return 1;
									}
									else
									{
										gVehData[tmpcar][LastDriverWKey] = gPlayerData[playerid][pName];
									}

									// przypisanie zmiennej id sprzedajacego
									sellerID = i;

									// zwolnienie slotu gracza sprzedajacego
									RemovePlayerItemExUsed(i, sellerslot);

									// informacja dla kupujacego
									SendClientMessage(playerid, COLOR_WHITE, "[INFO:] Kupi³eœ samolot !");
									SendClientMessage(playerid, COLOR_WHITE, "[INFO:] Skorzystaj z komendy '/pomoc samochod'");

									// informacja dla sprzedajacego
									format(string, sizeof(string), "[INFO:] Gracz %s [%d] kupi³ od Ciebie pojazd !", GetPlayerNameEx(playerid), playerid);
									SendClientMessage(i, COLOR_LIGHTYELLOW2, string);

									break;
								}
							}
							if(IsAPlane(idcar) == 0 && IsAHelicopter(idcar) == 0 && IsABoat(idcar) == 0)
							{
								// gracz ma za niski lvl
								if(gPlayerData[playerid][pLevel] < CarKey1LVL)
								{
									format(string, sizeof(string),"[INFO:] Musisz mieæ conajmniej %d poziom aby kupiæ pierwszy samochód.",CarKey1LVL);
									SendClientMessage(playerid, COLOR_WHITE, string);
									return 1;
								}
								// kupno pierwszego pojazdu
								if(gPlayerData[playerid][pLevel] >= CarKey1LVL)
								{
									// sprawdzenie czy pojazd nalezy do sprzedajacego
									sellerslot = PHaveItem(i, 2, gVehData[tmpcar][CarSerial]);
									if(sellerslot > 0)
									{
										// sprawdzenie czy gracz posiada wolny slot
										if(PHaveItem(playerid, 2, gVehData[tmpcar][CarSerial]) > 0)
										{
											SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Posiadasz ju¿ klucze do tego pojazdu");
											return 1;
										}
										if(PFirstFreeSlot(playerid) == 0)
										{
											SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie masz miejsca na kolejny item !");
											return 1;
										}
										newVehSerial(tmpcar);
										slot = InsertPlayerItem(playerid, 2, gVehData[tmpcar][CarSerial], 0, 0);
										if(slot == 0)
										{
											SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie masz miejsca na kolejny item !");
											return 1;
										}
										else
										{
											gVehData[tmpcar][LastDriverWKey] = gPlayerData[playerid][pName];
										}

										// przypisanie zmiennej id sprzedajacego
										sellerID = i;

										// zwolnienie slotu gracza sprzedajacego
										RemovePlayerItemExUsed(i, sellerslot);

										// informacja dla kupujacego
										SendClientMessage(playerid, COLOR_WHITE, "[INFO:] Kupi³eœ pojazd !");
										SendClientMessage(playerid, COLOR_WHITE, "[INFO:] Skorzystaj z komendy '/pomoc samochod'");

										// informacja dla sprzedajacego
										format(string, sizeof(string), "[INFO:] Gracz %s [%d] kupi³ od Ciebie pojazd !", GetPlayerNameEx(playerid), playerid);
										SendClientMessage(i, COLOR_LIGHTYELLOW2, string);

										break;
									}
								}
							}
						}
					}
					if(sellerID != 999)
					{
						new plname[128];
						GetPlayerName(playerid, plname, sizeof(plname));

						// modyfikacja danych pojazdu
						gVehData[tmpcar][Owned] = 1;
						strmid(gVehData[tmpcar][Owner], plname, 0, strlen(plname), 128);

						// zmniejszenie ilosci pieniedzy gracza kupujacego
						GivePlayerCash(playerid, -gVehData[tmpcar][Price]);

						// zwiekszenie ilosci pieniedzy gracza sprzedajacego
						GivePlayerCash(sellerID, gVehData[tmpcar][Price]);

						// zresetowanie sprzedazy pojazdu
						gVehData[tmpcar][ReadyToSell] = 0;

						// usuniecie informacji sprzedazy z nad pojazdu
						DestroyDynamic3DTextLabel( gVehData[tmpcar][Veh3DSell] );

						// zapis
						SavePlayerData(playerid, "Cash");
						SavePlayerData(sellerID, "Cash");

						SaveVehData(tmpcar, "ReadyToSell");
						SaveVehData(tmpcar, "Owned");
						SaveVehData(tmpcar, "Owner");

						// log
						new Year, Month, Day;
						getdate(Year, Month, Day);
						printf("[%d-%d-%d] [VEHICLE:] Vehicle id: %d has been bought by %s from %s for %d$", Year, Month, Day, idcar, GetPlayerNameEx(playerid), GetPlayerNameEx(sellerID), gVehData[tmpcar][Price]);

						return 1;
					}
					else
					{
						SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Sprzedawcy nie ma obecnie na serwerze, nie mo¿esz kupiæ tego pojazdu w tej chwili");
						return 1;
					}
				}
				// pojazd uzywany - frakcyjny
				if(gVehData[tmpcar][Owned] == 0 && gVehData[tmpcar][FactionCar] != 255)
				{
					if(IsAHelicopter(idcar))
					{
						// sprawdzenie czy gracz posiada odpowiedni level do kupna helikoptera
						if(gPlayerData[playerid][pLevel] < AirKeyLVL)
						{
							format(string, sizeof(string),"[INFO:] Musisz mieæ conajmniej %d poziom aby kupiæ helikopter.",AirKeyLVL);
							SendClientMessage(playerid, COLOR_WHITE, string);

							return 1;
						}

						// sprawdzenie czy gracz posiada wolny slot
						if(PHaveItem(playerid, 2, gVehData[tmpcar][CarSerial]) > 0)
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Posiadasz ju¿ klucze do tego pojazdu");
							return 1;
						}
						slot = InsertPlayerItem(playerid, 2, gVehData[tmpcar][CarSerial], 0, 0);
						if(slot == 0)
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie masz miejsca na kolejny item !");
							return 1;
						}
						else
						{
							gVehData[tmpcar][LastDriverWKey] = gPlayerData[playerid][pName];
						}

						// wiadomosc dla kupujacego
						SendClientMessage(playerid, COLOR_WHITE, "[INFO:] Kupi³eœ helikopter !");
						SendClientMessage(playerid, COLOR_WHITE, "[INFO:] Skorzystaj z komendy '/pomoc samochod'");
					}

					if(IsAPlane(idcar))
					{
						// sprawdzenie czy gracz posiada odpowiedni level do kupna samolotu
						if(gPlayerData[playerid][pLevel] < AirKeyLVL)
						{
							format(string, sizeof(string),"[INFO:] Musisz mieæ conajmniej %d poziom aby kupiæ samolot.",AirKeyLVL);
							SendClientMessage(playerid, COLOR_WHITE, string);
							return 1;
						}

						// sprawdzenie czy gracz posiada wolny slot
						if(PHaveItem(playerid, 2, gVehData[tmpcar][CarSerial]) > 0)
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Posiadasz ju¿ klucze do tego pojazdu");
							return 1;
						}
						slot = InsertPlayerItem(playerid, 2, gVehData[tmpcar][CarSerial], 0, 0);
						if(slot == 0)
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie masz miejsca na kolejny item !");
							return 1;
						}
						else
						{
							gVehData[tmpcar][LastDriverWKey] = gPlayerData[playerid][pName];
						}

						// wiadomosc dla kupujacego
						SendClientMessage(playerid, COLOR_WHITE, "[INFO:] Kupi³eœ samolot !");
						SendClientMessage(playerid, COLOR_WHITE, "[INFO:] Skorzystaj z komendy '/pomoc samochod'");
					}

					if(IsAPlane(idcar) == 0 && IsAHelicopter(idcar) == 0 && IsABoat(idcar) == 0)
					{
						// gracz ma za niski lvl
						if(gPlayerData[playerid][pLevel] < CarKey1LVL)
						{
							format(string, sizeof(string),"[INFO:] Musisz mieæ conajmniej %d poziom aby kupiæ pierwszy samochód.",CarKey1LVL);
							SendClientMessage(playerid, COLOR_WHITE, string);

							return 1;
						}

						new plname[128];
						GetPlayerName(playerid, plname, sizeof(plname));

						// sprawdzenie czy gracz posiada wolny slot
						if(PHaveItem(playerid, 2, gVehData[tmpcar][CarSerial]) > 0)
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Posiadasz ju¿ klucze do tego pojazdu");
							return 1;
						}
						slot = InsertPlayerItem(playerid, 2, gVehData[tmpcar][CarSerial], 0, 0);
						if(slot == 0)
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie masz miejsca na kolejny item !");
							return 1;
						}
						else
						{
							gVehData[tmpcar][LastDriverWKey] = gPlayerData[playerid][pName];
						}

						// wiadomosc dla kupujacego
						SendClientMessage(playerid, COLOR_WHITE, "[INFO:] Kupi³eœ samochód !");
						SendClientMessage(playerid, COLOR_WHITE, "[INFO:] Skorzystaj z komendy '/pomoc samochod'");
					}

					new plname[128];
					GetPlayerName(playerid, plname, sizeof(plname));

					// sprawdzenie stanu licznika pojazdow frakcji
					if(DynamicFactions[gVehData[tmpcar][FactionCar]][fCarsCount] > 0)
					{
						// zmniejszenie licznika pojazdow frakcji
						DynamicFactions[gVehData[tmpcar][FactionCar]][fCarsCount]--;

						SaveFData(gVehData[tmpcar][FactionCar], "CarsCount");
					}

					// zysk dla frakcji
					DynamicFactions[gVehData[tmpcar][FactionCar]][fBank] += gVehData[tmpcar][Price];

					SaveFData(gVehData[tmpcar][FactionCar], "Bank");

					if( DynamicFactions[ gVehData[tmpcar][FactionCar] ][fType] == 6 )
					{
						DestroyDynamic3DTextLabel( gVehData[tmpcar][Veh3DTaxiNfo] );
						DestroyDynamic3DTextLabel( gVehData[tmpcar][Veh3DTaxiNfo2] );
					}
					
					// modyfikacja danych pojazdu
					gVehData[tmpcar][CarType] = 0;
					gVehData[tmpcar][Owned] = 1;
					strmid(gVehData[tmpcar][Owner], plname, 0, strlen(plname), 128);
					gVehData[tmpcar][FactionCar] = 255;
					gVehData[tmpcar][ReadyToSell] = 0;

					SaveVehData(tmpcar, "CarType");
					SaveVehData(tmpcar, "Owned");
					SaveVehData(tmpcar, "Owner");
					SaveVehData(tmpcar, "FactionCar");
					SaveVehData(tmpcar, "ReadyToSell");

					// usuniecie informacja sprzedazy z nad pojazdu
					DestroyDynamic3DTextLabel( gVehData[tmpcar][Veh3DSell] );

					// log
					new Year, Month, Day;
					getdate(Year, Month, Day);
					printf("[%d-%d-%d] [VEHICLE:] Vehicle id: %d has been bought by %s from faction ID: %d for %d$", Year, Month, Day, idcar, GetPlayerNameEx(playerid), gVehData[tmpcar][FactionCar], gVehData[tmpcar][Price]);

					return 1;
				}
				if(gVehData[tmpcar][Owned] == 1 && gVehData[tmpcar][FactionCar] != 255)
				{
					SendClientMessage(playerid, COLOR_RED, "[INFO:] Wyst¹pi³ problem z tym pojazdem. Skontaktuj siê z administratorem. Lista administratorów: /admini");
					return 1;
				}
			}
			return 1;
		}
		if(strcmp(cmd, "/zezlomujpojazd", true) == 0 || strcmp(cmd, "/dsveh", true) == 0)
		{
			if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
			{
				new slot = PHaveItem(playerid, 2, gVehData[tmpcar][CarSerial]);
				if(slot == 0)
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie posiadasz kluczyków do tego pojazdu !");
					return 1;
				}
				// Cena za samochod
				if(gPlayerData[playerid][pAdmin] >= 2)
				{
					DestroyVehicle(playerid);
					ResetVehicleData(idcar,1);
					format(string, sizeof(string), "[INFO:] Zez³omowa³eœ pojazd w piŸdziet !");
					TogglePlayerControllable(playerid, 1);
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
				}
				else if(gPlayerData[playerid][pAdmin] <= 2)
				{
					if(floatround(gVehData[tmpcar][Price] * 0.20, floatround_round) < gPlayerData[playerid][pCash])
					{
						if(IsABoat(idcar) == 0 && IsAPlane(idcar) == 0 && IsAHelicopter(idcar) == 0)
						{
							if(gVehData[tmpcar][Owned] == 1 && strcmp(gPlayerData[playerid][pName], gVehData[tmpcar][Owner], false) == 0)
							{
								if(PlayerToPoint(50.0, playerid, -1854.0, -1679.0, 22.0))
								{
									RemovePlayerItemExUsed(playerid, slot);
									DestroyVehicle(idcar);
									ResetVehicleData(idcar,1);
									format(string, sizeof(string), "[INFO:] Zez³omowa³eœ swój samochód");
									SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
									format(string, sizeof(string), "[INFO:] Koszt z³omowania %d$", floatround(float(gVehData[tmpcar][Price]) * 0.20, floatround_round));
									SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
									DynamicFactions[FACTIONID_GOVERNMENT][fBank] += floatround(gVehData[tmpcar][Price] * 0.20, floatround_round);
									SaveFData(FACTIONID_GOVERNMENT, "Bank");
									GivePlayerCash(playerid,-(floatround(gVehData[tmpcar][Price] * 0.20, floatround_round)));
									TogglePlayerControllable(playerid, 1);
									return 1;
								}
								else
								{
									SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ w punkcie z³omowania pojazdów !");
									return 1;
								}
							}
							else
							{
								format(string, sizeof(string), "[INFO:] Nie jesteœ w³aœcicielem tego pojazdu !");
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								return 1;
							}
						}
						// £ÓD
						if(IsABoat(idcar))
						{
							if(gVehData[tmpcar][Owned] == 1 && strcmp(gPlayerData[playerid][pName], gVehData[tmpcar][Owner], false) == 0)
							{
								if(PlayerToPoint(8.0, playerid, 2505.0, -2715.0, 0.0))
								{
									RemovePlayerItemExUsed(playerid, slot);
									DestroyVehicle(idcar);
									ResetVehicleData(idcar,1);
									format(string, sizeof(string), "[INFO:] Zez³omowa³eœ swoj¹ ³ódŸ");
									SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
									format(string, sizeof(string), "[INFO:] Koszt z³omowania %d$", floatround(gVehData[tmpcar][Price] * 0.20, floatround_round));
									SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
									DynamicFactions[FACTIONID_GOVERNMENT][fBank] += floatround(gVehData[tmpcar][Price] * 0.20, floatround_round);
									SaveFData(FACTIONID_GOVERNMENT, "Bank");
									GivePlayerCash(playerid,-(floatround(gVehData[tmpcar][Price] * 0.20, floatround_round)));
									TogglePlayerControllable(playerid, 1);
									SavePlayerData(playerid, "Cash");
									return 1;
								}
								else
								{
									SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ w punkcie z³omowania ³odzi !");
									return 1;
								}
							}
							else
							{
								format(string, sizeof(string), "[INFO:] Nie jesteœ w³aœcicielem tego pojazdu !");
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								return 1;
							}
						}
						// HELIKOPTER
						if(IsAHelicopter(idcar))
						{
							if(gVehData[tmpcar][Owned] == 1 && strcmp(gPlayerData[playerid][pName], gVehData[tmpcar][Owner], false) == 0)
							{
								if(PlayerToPoint(50.0, playerid, 365.0, 2537.0, 17.0))
								{
									RemovePlayerItemExUsed(playerid, slot);
									DestroyVehicle(idcar);
									ResetVehicleData(idcar,1);
									format(string, sizeof(string), "[INFO:] Zez³omowa³eœ swój helikopter");
									SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
									format(string, sizeof(string), "[INFO:] Koszt z³omowania %d$", floatround(gVehData[tmpcar][Price] * 0.20, floatround_round));
									SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
									DynamicFactions[FACTIONID_GOVERNMENT][fBank] += floatround(gVehData[tmpcar][Price] * 0.20, floatround_round);
									SaveFData(FACTIONID_GOVERNMENT, "Bank");
									GivePlayerCash(playerid,-(floatround(gVehData[tmpcar][Price] * 0.20, floatround_round)));
									TogglePlayerControllable(playerid, 1);
									return 1;
								}
								else
								{
									SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ w punkcie z³omowania helikopterów !");
									return 1;
								}
							}
							else
							{
								format(string, sizeof(string), "[INFO:] Nie jesteœ w³aœcicielem tego pojazdu !");
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								return 1;
							}
						}
						// SAMOLOT
						if(IsAPlane(idcar))
						{
							if(gVehData[tmpcar][Owned] == 1 && strcmp(gPlayerData[playerid][pName], gVehData[tmpcar][Owner], false) == 0)
							{
								if(PlayerToPoint(50.0, playerid, 365.0, 2537.0, 17.0))
								{
									RemovePlayerItemExUsed(playerid, slot);
									DestroyVehicle(idcar);
									ResetVehicleData(idcar,1);
									format(string, sizeof(string), "[INFO:] Zez³omowa³eœ swój samolot");
									SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
									format(string, sizeof(string), "[INFO:] Koszt z³omowania %d$", floatround(float(gVehData[tmpcar][Price]) * 0.20, floatround_round));
									SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
									DynamicFactions[FACTIONID_GOVERNMENT][fBank] += floatround(float(gVehData[tmpcar][Price]) * 0.20, floatround_round);
									SaveFData(FACTIONID_GOVERNMENT, "Bank");
									GivePlayerCash(playerid,-(floatround(float(gVehData[tmpcar][Price]) * 0.20, floatround_round)));
									TogglePlayerControllable(playerid, 1);
									return 1;
								}
								else
								{
									SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ w punkcie z³omowania samolotów !");
									return 1;
								}
							}
							else
							{
								format(string, sizeof(string), "[INFO:] Nie jesteœ w³aœcicielem tego pojazdu !");
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								return 1;
							}
						}
					}
					else
					{
						format(string, sizeof(string), "[INFO:] Nie masz wystarczaj¹cej iloœci pieniêdzy aby zez³omowaæ pojazd (%d$) !", floatround(gVehData[tmpcar][Price] * 0.20, floatround_round));
						SendClientMessage(playerid, COLOR_RED, string);
						return 1;
					}
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Musisz byæ w pojeŸdzie aby u¿yæ tej komendy !");
			}
			return 1;
		}
		if(strcmp(cmd, "/zaparkuj", true) == 0)
		{
			if(IsPlayerConnected(playerid))
			{
				new plname[MAX_PLAYER_NAME];
				GetPlayerName(playerid, plname, sizeof(plname));
				if(IsPlayerInAnyVehicle(playerid))
				{
					if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
					{
						if(gPlayerData[playerid][pFaction] == 9)
						{
							if(gVehData[tmpcar][CarModel] == 431 || gVehData[tmpcar][CarModel] == 437 || gVehData[tmpcar][CarModel] == 507 || gVehData[tmpcar][CarModel] == 408 || gVehData[tmpcar][CarModel] == 574)
							{
								new Float:vehHealth;
								new Float:x,Float:y,Float:z;
								new Float:a;
								GetVehiclePos(idcar, x, y, z);
								GetVehicleZAngle(idcar, a);
								GetVehicleHealth(idcar, vehHealth);
								gVehData[tmpcar][CarX] = x;
								gVehData[tmpcar][CarY] = y;
								gVehData[tmpcar][CarZ] = z;
								gVehData[tmpcar][CarAngle] = a;

								SaveVehData(tmpcar, "CarPos");

								DestroyVehicle(idcar);
								CreateVehicle(gVehData[tmpcar][CarModel],gVehData[tmpcar][CarX],gVehData[tmpcar][CarY],gVehData[tmpcar][CarZ],gVehData[tmpcar][CarAngle],gVehData[tmpcar][CarColor1],gVehData[tmpcar][CarColor2], -1);
								PutPlayerIntoVehicle(playerid,idcar,0);
								SetVehicleHealth(idcar, vehHealth);
								//SetVehicleToPos(idcar, x, y, z);
								//SetVehicleZAngle(idcar, a);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Zaparkowa³eœ pojazd s³u¿b publicznych !");
							}
						}
					}
				}
			}
			return 1;
		}
		if(strcmp(cmd, "/acarprice", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 2)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /acarprice [price]");
				return 1;
			}
			new price;
			price = strval(tmp);
			new tmpstring[128];
			gVehData[tmpcar][Price] = price;
			format(tmpstring, sizeof(tmpstring), "[INFO:] Zmieni³eœ cene samochodu o ID: %d, Nowa cena: %d", idcar, gVehData[tmpcar][Price]);
			SendClientMessage(playerid, COLOR_YELLOW, tmpstring);
			SaveVehData(tmpcar, "Price");
			return 1;
		}
		if(strcmp(cmd, "/acarowner", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 2)
				return 0;
			new Float:x,Float:y,Float:z;
			new Float:a;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /acarowner [player_name]");
				return 1;
			}
			if(strcmp(tmp, "None", true) == 0)
			{
				ResetVehicleData(tmpcar-1,1);
				TogglePlayerControllable(playerid,1);
				format(string, sizeof(string), "[INFO:] Zresetowa³eœ w³aœciciela samochodu ID %d na %s", tmpcar+1,gVehData[tmpcar][Owner]);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			}
			else
			{
				strdel(gVehData[tmpcar][Owner], 0, 128);
				strins(gVehData[tmpcar][Owner], tmp, 0, 128);

				gVehData[tmpcar][Owned] = 1;
				gVehData[tmpcar][Closed] = 0;

				GetVehiclePos(idcar, x, y, z);
				GetVehicleZAngle(idcar, a);

				gVehData[tmpcar][CarX] = x;
				gVehData[tmpcar][CarY] = y;
				gVehData[tmpcar][CarZ] = z;
				gVehData[tmpcar][CarAngle] = a;

				PutPlayerIntoVehicle(playerid,idcar,0);

				SaveVehData(tmpcar, "Owned");
				SaveVehData(tmpcar, "CarPos");
				SaveVehData(tmpcar, "Owner");
				SaveVehData(tmpcar, "Closed");

				printf("[WARNING:] Vehicle id %d set to: %s by %s", idcar, gVehData[tmpcar][Owner], GetPlayerNameEx(playerid));

				format(string, sizeof(string), "[INFO:] Zmieni³eœ w³aœciciela samochodu ID %d na %s", tmpcar+1,gVehData[tmpcar][Owner]);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
				
				printf("[WARNING:] /acarowner used by %s, veh id: %d, owner changed to %s", gPlayerData[playerid][pName], tmpcar+1, gVehData[tmpcar][Owner]);
			}
			return 1;
		}
		if(strcmp(cmd, "/aplayerfaction", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 2)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /aplayerfaction [playerid]");
				return 1;
			}
			new playeridx;
			playeridx = strval(tmp);
			new tmpstring[128];
			format(tmpstring, sizeof(tmpstring), "[INFO:] Nr frakcji gracza to: %d, Typ frakcji: %d", gPlayerData[playeridx][pFaction], DynamicFactions[gPlayerData[playeridx][pFaction]][fType]);
			SendClientMessage(playerid, COLOR_YELLOW, tmpstring);
			return 1;
		}
		if(strcmp(cmd, "/asetplayerfaction", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 2)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /asetplayerfaction [playerid] [frakcja] [ranga]");
				return 1;
			}
			new fraction;
			new rank;
			giveplayerid = ReturnUser(tmp);
			if(!IsPlayerConnected(giveplayerid))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Gracz nie jest on-line !");
				return 1;
			}
			tmp = strtok(cmdtext, idx);
			fraction = strval(tmp);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /asetplayerfaction [playerid] [frakcja] [ranga]");
				format(string, sizeof(string), "0(%s), 1(%s), 2(%s), 3(%s), 4(%s), 5(%)",DynamicFactions[0][Name],DynamicFactions[1][Name],DynamicFactions[2][Name],DynamicFactions[3][Name],DynamicFactions[4][Name]);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
				format(string, sizeof(string), "6(%s), 7(%s), 8(%s), 9(%s), 10(%s)",DynamicFactions[6][Name],DynamicFactions[7][Name],DynamicFactions[8][Name],DynamicFactions[9][Name],DynamicFactions[10][Name]);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
				return 1;
			}
			if((fraction >= 0 && fraction <= 20) || fraction == 255)
			{
				tmp = strtok(cmdtext, idx);
				rank = strval(tmp);
				if(rank >= 1 && rank <= 10)
				{
					gPlayerData[giveplayerid][pFaction] = fraction;
					gPlayerData[giveplayerid][pRank] = rank;
					format(string, sizeof(string), "[INFO:] Frakcja gracza %d zosta³a zmieniona na: %d, ranga: %d, przez %s", giveplayerid, fraction, rank, GetPlayerNameEx(playerid));
					SendAdminMessage(COLOR_YELLOW, string);
					gPlayerData[playerid][pJoinedFaction] = gettime();
					SavePlayerData(giveplayerid, "Faction");
					SavePlayerData(giveplayerid, "Rank");
					SavePlayerData(giveplayerid, "JoinedFaction");
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /asetplayerfaction [playerid] [frakcja] [ranga]");
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "Ranga musi byæ z zakresu od 1 do 10 lub 0 dla frakcji 255");
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /asetplayerfaction [playerid] [frakcja] [ranga]");
				format(string, sizeof(string), "0(%s), 1(%s), 2(%s), 3(%s), 4(%s), 5(%)",DynamicFactions[0][Name],DynamicFactions[1][Name],DynamicFactions[2][Name],DynamicFactions[3][Name],DynamicFactions[4][Name]);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
				format(string, sizeof(string), "6(%s), 7(%s), 8(%s), 9(%s), 10(%s)",DynamicFactions[6][Name],DynamicFactions[7][Name],DynamicFactions[8][Name],DynamicFactions[FACTIONID_GOVERNMENT][Name],DynamicFactions[10][Name]);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			}
			return 1;
		}
		if(strcmp(cmd, "/opuscfrakcje", true) == 0)
		{
			if( gPlayerData[playerid][pFaction] == 255 )
			{
				SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie nale¿ysz do ¿adnej frakcji !" );
				return 1;
			}
			if( gPlayerData[playerid][pRank] == 1 )
			{
				SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz opuœciæ frakcji bêd¹c jej liderem !" );
				SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Musisz usun¹æ frakcje lub przekaæ lidera aby opuœciæ frakcje" );
				return 1;
			}
			gPlayerData[playerid][pFaction] = 255;
			gPlayerData[playerid][pRank] = 1;
			SavePlayerData(playerid, "Faction");
			SavePlayerData(playerid, "Rank");
			SendClientMessage( playerid, COLOR_LIGHTYELLOW2, "[INFO:] Gratulacje, odeszles z frakcji" );
			return 1;
		}
		if(strcmp(cmd, "/asetlicenceplate", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] != 5)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /asetlicenceplate [text]");
				return 1;
			}
			SetVehicleNumberPlate(idcar, tmp);
			SetVehicleToRespawn(idcar);
			new tmpstring[128];
			format(tmpstring, sizeof(tmpstring), "[INFO:] Ustawi³eœ rejestracje samochodu na: %s", tmp);
			SendClientMessage(playerid, COLOR_YELLOW, tmpstring);
			return 1;
		}
		if(strcmp(cmd, "/explosion", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 1)
				return 0;
			new Float:x, Float:y, Float:z;
			GetPlayerPos(playerid, x, y, z);
			CreateExplosion( x+10, y, z, 7, 10.0);
			return 1;
		}
		if(strcmp(cmd, "/przyczepnaczepe", true) == 0)
		{
			if(IsPlayerConnected(playerid))
			{
				new Float:vehx, Float:vehy, Float:vehz;

				for(new i = 1; i < sizeof(gVehData); i++)
				{
					GetVehiclePos(i, vehx, vehy, vehz);
					if(GetVehicleModel(idcar) == IsASemiTrailer(idcar))
					{
						if(IsPlayerInRangeOfPoint(playerid, 6.5, vehx, vehy, vehz))
						{
							if(gVehData[GetPlayerVehicleID(playerid)-1][CarModel] == IsATruck(idcar))
							{
								AttachTrailerToVehicle(i, idcar);
							}
							else
							{
								SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] Nie mo¿esz holowaæ tym pojazdem");
							}
						}
					}
				}
				return 1;
			}
			return 1;
		}
		if(strcmp(cmd, "/przyczepprzyczepe", true) == 0)
		{
			if(IsPlayerConnected(playerid))
			{
				new Float:vehx, Float:vehy, Float:vehz;

				for(new i = 1; i < sizeof(gVehData); i++)
				{
					GetVehiclePos(i, vehx, vehy, vehz);
					if(GetVehicleModel(idcar) == IsATrailer(idcar))
					{
						if(IsPlayerInRangeOfPoint(playerid, 6.5, vehx, vehy, vehz))
						{
							if(gVehData[GetPlayerVehicleID(playerid)-1][CarModel] == IsALorry(idcar))
							{
								AttachTrailerToVehicle(i, idcar);
							}
							else
							{
								SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] Nie mo¿esz holowaæ tym pojazdem");
							}
						}
					}
				}
				return 1;
			}
			return 1;
		}
		/*if(strcmp(cmd, "/doczepprzyczepe", true) == 0)
		{
			if(IsPlayerConnected(playerid))
			{
				new Float:vehx, Float:vehy, Float:vehz;
				for(new i = 0; i < sizeof(gVehData); i++)
				{
					if(IsASemiTrailer(GetVehicleModel(i)))
					{
						if(GetVehicleModel(idcar) == IsATrailer(idcar))
						{
							GetVehiclePos(i, vehx, vehy, vehz);
							if(IsPlayerInRangeOfPoint(playerid, 10.5, vehx, vehy, vehz))
							{
								if(gVehData[GetPlayerVehicleID(playerid)-1][CarModel] == IsATruck(idcar))
								{
									AttachTrailerToVehicle(idcar, idcar2);
								}
								else
								{
									SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[INFO:] Nie mo¿esz holowaæ tym pojazdem");
								}
							}
						}
					}
				}
				return 1;
			}
			return 1;
		}*/
		if(strcmp(cmd, "/acardata", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 1)
				return 0;
			if(!IsPlayerInVehicle(playerid, idcar))
				return 1;
			new Float:emmision;
			VehCo2Emmision(idcar, emmision);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "___________________________________________________");
			format(string, sizeof(string), "ID: %d, Model: %d, Faction: %d, Type: %d, BizID: %d, CarSerial: %d", idcar, GetVehicleModel(idcar), gVehData[tmpcar][FactionCar], gVehData[tmpcar][CarType], gVehData[tmpcar][BusinessID], gVehData[tmpcar][CarSerial]);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			format(string, sizeof(string), "Bought: %d, Owner: %s, Price: %d, ReadyToSell: %d, Alarm: %d", gVehData[tmpcar][Owned], gVehData[tmpcar][Owner], gVehData[tmpcar][Price], gVehData[tmpcar][ReadyToSell], gVehData[tmpcar][CarSerial], gVehData[tmpcar][Alarm]);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			format(string, sizeof(string), "Hook: %d, Damaged: %d, Repair Time Left: %d min, CarResetT: %d, Fuel Type: %d, Battery: %f, Confiscated: %d", gVehData[tmpcar][Hook], gVehData[tmpcar][CarDamaged], gVehData[tmpcar][CarRepairTimeLeft]*10, gVehData[tmpcar][CarResetT], gVehData[tmpcar][Fuel], gVehData[tmpcar][BatteryCapacity], gVehData[tmpcar][VConfiscated]);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			format(string, sizeof(string), "Co2 emmision: %f", emmision); 
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "___________________________________________________");
			return 1;
		}
		if(strcmp(cmd, "/sprawdznumer", true) == 0)
		{
			if(gPlayerData[playerid][pFaction] != 0)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ z policji !");
				return 1;
			}
			if(IsPlayerInVehicle(playerid, idcar))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "___________________________________________________");
				format(string, sizeof(string), "ID pojazdu: %d",idcar);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "___________________________________________________");
			}
			return 1;
		}
		if(strcmp(cmd, "/camera1", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] != 5)
				return 0;
			if(Camera1On[playerid] == 0) //gps wylaczony
			{
				Camera1On[playerid] = 1;
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "Camera Pos w³¹czony");
				CameraPos[playerid] = TextDrawCreate(32.0, 345.0, " ");
			}
			else if(Camera1On[playerid] == 1) //gps wlaczony
			{
				Camera1On[playerid] = 0;
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "Camera Pos wy³aczony");
				TextDrawDestroy(CameraPos[playerid]);
			}
			return 1;
		}
		if(strcmp(cmd, "/angle", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] != 5)
				return 0;
			if(AngleOn[playerid] == 0) //gps wylaczony
			{
				AngleOn[playerid] = 1;
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "AngleOn w³¹czony");
				Angle2[playerid] = TextDrawCreate(32.0, 385.0, " ");
			}
			else if(AngleOn[playerid] == 1) //gps wlaczony
			{
				AngleOn[playerid] = 0;
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "AngleOn wy³aczony");
				TextDrawDestroy(Angle2[playerid]);
			}
			return 1;
		}
		if(strcmp(cmd, "/camera2", true) == 0)
		{
			if(IsPlayerConnected(playerid) && gPlayerLogged[playerid] == 1)
			{

					if(Camera2On[playerid] == 0) //gps wylaczony
					{
						Camera2On[playerid] = 1;
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "Camera Front w³¹czony");
						CameraFront[playerid] = TextDrawCreate(32.0, 365.0, " ");
					}
					else if(Camera2On[playerid] == 1) //gps wlaczony
					{
						Camera2On[playerid] = 0;
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "Camera Front wy³aczony");
						TextDrawDestroy(CameraFront[playerid]);
					}

			}
			return 1;
		}
		if(strcmp(cmd, "/walczoterytorium", true) == 0)
		{
			if(gPlayerData[playerid][pFaction] == 255)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Niew³aœciwa frakcja !");
				return 1;
			}
			if(DynamicFactions[gPlayerData[playerid][pFaction]][fType] != 3)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie jesteœ liderem gangu !");
				return 1;
			}
			if(gPlayerData[playerid][pRank] > 1)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie jesteœ liderem !");
				return 1;
			}
			for(new i = 0; i < sizeof(DynamicZones); i++)
			{
				if(IsPlayerInArea(playerid, DynamicZones[i][zMax_X], DynamicZones[i][zMin_X], DynamicZones[i][zMax_Y], DynamicZones[i][zMin_Y]))
				{
					if( DynamicZones[i][zFaction] == gPlayerData[playerid][pFaction] )
					{
						SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz walczyæ o w³asne terytorium !");
						return 1;
					}
					if( gGangWar[Enabled] == 1)
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ju¿ trwa jedna wojna gangów o terytorium.");
					else
					{
						gGangWar[Enabled] = 1;
						gGangWar[TimeLeft] = 30; // 1 = 1minuta
						gGangWar[FactionStartedKills] = 0;
						gGangWar[FactionAttackedKills] = 0;
						gGangWar[FactionStarted] = gPlayerData[playerid][pFaction];
						gGangWar[FactionAttacked] = DynamicZones[i][zFaction];						
						gGangWar[AreaID] = i;
						foreach(Player, n)
							GangZoneFlashForPlayer(n, i, DynamicFactions[ DynamicZones[i][zFaction] ][fColor] );
						SendClientMessageToAll(COLOR_LIGHTYELLOW2, "[INFO:] Walka o terytorium rozpoczêta !");
					}
					return 1;
				}
			}
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie znajdujesz sie na ¿adnym terytorium !");
			return 1;			
		}
		if(strcmp(cmd, "/rozpocznijwyscig", true) == 0)
		{
			if(!IsAnyRaceStarted)
			{
				for(new i = 0; i <= 20; i++)
				{
					if(IsPlayerInRangeOfPoint(playerid, 1.0, DynamicRaces[i][TakeRaceX],DynamicRaces[i][TakeRaceY],DynamicRaces[i][TakeRaceZ]))
					{
						if(gPlayerData[playerid][pLevel] > 4)
						{
							if(gPlayerData[playerid][pCash] >= DynamicRaces[i][StartPrice])
							{
								GetPlayerName(playerid, giveplayername, sizeof(giveplayername));
								DynamicRaces[i][Started] = 1;
								IsAnyRaceStarted = 1;
								RaceOrganizator = giveplayername;
								RaceDriversCount = 1;
								RaceID = i;
								RaceCountDownTime = 300;
								StartRaceCountDown = 1;
								RaceDrivers[0] = RaceOrganizator;
								RaceDriversID[0] = playerid;
								RacePrize = DynamicRaces[i][EnterPrice];
								GivePlayerCash(playerid, -DynamicRaces[i][StartPrice]);

								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /komendyorganizatora");
								return 1;
							}
							else
							{
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie masz wystarczaj¹co du¿o pieniêdzy by zorganizowaæ wyœcig");
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Musisz mieæ przynajmniej 5 poziom postaci aby zostaæ organizatorem wyœcigu");
							return 1;
						}
					}
				}
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie znajdujesz siê w punkcie informacji o wyœcigu");
			}
			return 1;
		}
		if(strcmp(cmd, "/dolaczdowyscigu", true) == 0)
		{
			if(IsAnyRaceStarted)
			{
				for(new i = 0; i <= 20; i++)
				{
					if(IsPlayerInRangeOfPoint(playerid, 1.0, DynamicRaces[i][TakeRaceX],DynamicRaces[i][TakeRaceY],DynamicRaces[i][TakeRaceZ]))
					{
						if(DynamicRaces[i][Started] == 1)
						{
							if(RaceDriversCount < DynamicRaces[i][MaxDrivers])
							{
								if(gPlayerData[playerid][pCash] >= DynamicRaces[i][EnterPrice])
								{
									if(RaceStarted != 1)
									{
										GetPlayerName(playerid, giveplayername, sizeof(giveplayername));
										//if(gPlayerData[playerid][pCarKey1] != 255 || gPlayerData[playerid][pCarKey2] != 255 || gPlayerData[playerid][pCarKey3] != 255)
										//{
										for(new n = 0; n <= DynamicRaces[i][MaxDrivers]; n++)
										{
											if(strlen(RaceDrivers[n]) != 0)
											{
												if(strcmp(RaceOrganizator, giveplayername, true) == 0)
												{
													SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Jesteœ organizatorem tego wyœcigu, nie mo¿esz do niego do³¹czyæ.");
													return 1;
												}
												if(strcmp(RaceDrivers[n], giveplayername, true) == 0)
												{
													printf("RaceDrivers[n] = %s, giveplayername = %s, n: %d", RaceDrivers[n], giveplayername, n);
													SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ju¿ do³¹czy³eœ do tego wyœcigu.");
													return 1;
												}
											}
										}
										/*}
										else
										{
											SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie posiadasz ¿adnego samochodu, nie mo¿esz do³¹czyæ do wyœcigu");
											return 1;
										}*/
										for(new j = 1; j <= DynamicRaces[i][MaxDrivers]; j++)
										{
											if(strlen(RaceDrivers[j]) == 0)
											{
												strmid(RaceDrivers[j], giveplayername, 0, strlen(giveplayername), MAX_PLAYER_NAME);
												GivePlayerCash(playerid, -DynamicRaces[i][EnterPrice]);

												RacePrize += DynamicRaces[i][EnterPrice];
												RaceDriversCount++;
												RaceDriversID[j] = playerid;
												SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Do³¹czy³eœ do wyœcigu");
												return 1;
											}
										}
									}
									else
									{
										SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Wyœcig ju¿ siê rozpocz¹³, nie mo¿esz do niego do³¹czyæ.");
										return 1;
									}
								}
								else
								{
									SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie masz wystarczaj¹cej iloœci pieniêdzy by do³¹czyæ do wyœcigu.");
									return 1;
								}
							}
							else
							{
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz do³¹czyæ do tego wyœcigu, maksymalna liczba uczestników osi¹gniêta.");
								return 1;
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten wyœcig nie jest obecnie aktywny");
							return 1;
						}
					}
				}
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie znajdujesz siê w punkcie informacji o wyœcigu.");
				return 1;
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Aktualnie nie odbywa siê ¿aden wyœcig.");
			}
			return 1;
		}
		if(strcmp(cmd, "/komendyorganizatora", true) == 0)
		{
			GetPlayerName(playerid, giveplayername, sizeof(giveplayername));
			if(strcmp(giveplayername, RaceOrganizator, true) == 0)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /listazawodnikow - /usunzawodnika - /rozpocznijwyscig - /zakonczwyscig - /rozpocznijodliczanie");
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ organizatorem wyœcigu");
			}
			return 1;
		}
		if(strcmp(cmd, "/listazawodnikow", true) == 0)
		{
			GetPlayerName(playerid, giveplayername, sizeof(giveplayername));
			if(strcmp(giveplayername, RaceOrganizator, true) == 0)
			{
				if(IsAnyRaceStarted)
				{
					for(new i = 0; i <= 20; i++)
					{
						if(IsPlayerInRangeOfPoint(playerid, 1.0, DynamicRaces[i][TakeRaceX],DynamicRaces[i][TakeRaceY],DynamicRaces[i][TakeRaceZ]))
						{
							if(DynamicRaces[i][Started] == 1)
							{
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Lista zawodników:");
								for(new n = 0; n <= DynamicRaces[i][MaxDrivers]; n++)
								{
									if(strlen(RaceDrivers[n]) != 0)
									{
										format(string, sizeof(string), "%s", RaceDrivers[n]);
										SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
									}
								}
								return 1;
							}
							else
							{
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten wyœcig nie jest obecnie aktywny");
								return 1;
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie znajdujesz siê w punkcie informacji o wyœcigu.");
							return 1;
						}
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Aktualnie nie odbywa siê ¿aden wyœcig.");
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ organizatorem wyœcigu");
			}
			return 1;
		}
		if(strcmp(cmd, "/rozpocznijodliczanie", true) == 0)
		{
			GetPlayerName(playerid, giveplayername, sizeof(giveplayername));
			if(strcmp(giveplayername, RaceOrganizator, true) == 0)
			{
				if(IsAnyRaceStarted)
				{
					for(new i = 0; i <= 20; i++)
					{
						if(IsPlayerInRangeOfPoint(playerid, 1.0, DynamicRaces[i][TakeRaceX],DynamicRaces[i][TakeRaceY],DynamicRaces[i][TakeRaceZ]))
						{
							if(DynamicRaces[i][Started] == 1)
							{
								StartRaceCountDown = 1;
								RaceID = i;
								RaceCountDownTime = 15;
								printf("RaceID: %d", RaceID);
								return 1;
							}
							else
							{
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten wyœcig nie jest obecnie aktywny");
								return 1;
							}
						}
					}
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie znajdujesz siê w punkcie informacji o wyœcigu.");
					return 1;
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Aktualnie nie odbywa siê ¿aden wyœcig.");
					return 1;
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ organizatorem wyœcigu");
			}
			return 1;
		}
		if(strcmp(cmd, "/zakonczwyscig", true) == 0)
		{
			GetPlayerName(playerid, giveplayername, sizeof(giveplayername));
			if(strcmp(giveplayername, RaceOrganizator, true) == 0)
			{
				if(IsAnyRaceStarted)
				{
					new tmpname[MAX_PLAYER_NAME];
					for(new i = 0; i <= 20; i++)
					{
						if(IsPlayerInRangeOfPoint(playerid, 1.0, DynamicRaces[i][TakeRaceX],DynamicRaces[i][TakeRaceY],DynamicRaces[i][TakeRaceZ]))
						{
							for(new j = 0; j <= DynamicRaces[RaceID][MaxDrivers]; j++)
							{
								GetPlayerName(RaceDriversID[j], tmpname, sizeof(tmpname));
								DisablePlayerRaceCheckpoint(RaceDriversID[j]);
								if(strlen(RaceDrivers[j]) != 0)
								{
									if(strcmp(tmpname, RaceDrivers[j], true, strlen(tmpname)) == 0)
									{
										SendClientMessage(RaceDriversID[j], COLOR_LIGHTYELLOW2, "[INFO:] Wyœcig zosta³ przerwany przez organizatora. Pieni¹dze zosta³y zwrócone.");
										GivePlayerCash(RaceDriversID[j], DynamicRaces[RaceID][EnterPrice]);

										SavePlayerData(playerid, "Cash");
									}
								}
								RaceDriversID[j] = 255;
								RaceTimeM[j] = 0;
								RaceTimeS[j] = 0;
								strdel(RaceDrivers[j], 0, MAX_PLAYER_NAME);
							}
							DynamicRaces[RaceID][Started] = 0;
							IsAnyRaceStarted = 0;
							strdel(RaceOrganizator, 0, MAX_PLAYER_NAME);
							RacePlace = 0;
							RaceStarted = 0;
							RaceDriversCount = 0;
							RaceID = 255;
							SaveDynamicRaces();
						}

					}
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie znajdujesz siê w punkcie informacji o wyœcigu.");
					return 1;
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Aktualnie nie odbywa siê ¿aden wyœcig.");
					return 1;
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ organizatorem wyœcigu");
			}
			return 1;
		}
		if(strcmp(cmd, "/usunzawodnika", true) == 0)
		{
			GetPlayerName(playerid, giveplayername, sizeof(giveplayername));
			if(strcmp(giveplayername, RaceOrganizator, true) == 0)
			{
				if(IsAnyRaceStarted)
				{
					new driver;
					for(new i = 0; i <= 20; i++)
					{
						if(IsPlayerInRangeOfPoint(playerid, 1.0, DynamicRaces[i][TakeRaceX],DynamicRaces[i][TakeRaceY],DynamicRaces[i][TakeRaceZ]))
						{
							tmp = strtok(cmdtext, idx);
							if(!strlen(tmp))
							{
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /usunzawodnika [playerid]");
								return 1;
							}
							driver = strval(tmp);
							if(driver != 0)
							{
								DisablePlayerRaceCheckpoint(RaceDriversID[driver]);
								strdel(RaceDrivers[driver], 0, MAX_PLAYER_NAME);
								SendClientMessage(RaceDriversID[driver], COLOR_LIGHTYELLOW2, "[INFO:] Zosta³eœ wyrzucony z wyœcigu przez organizatora");
							}
							else
							{
								SendClientMessage(RaceDriversID[driver], COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz sam siebie wyrzuciæ z wyœcigu");
							}
						}
					}
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie znajdujesz siê w punkcie informacji o wyœcigu.");
					return 1;
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Aktualnie nie odbywa siê ¿aden wyœcig.");
					return 1;
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ organizatorem wyœcigu");
			}
			return 1;
		}
		if(strcmp(cmd, "/araceend", true) == 0)
		{
			if (gPlayerData[playerid][pAdmin] != 5)
				return 0;
			if(IsAnyRaceStarted)
			{
				new tmpname[MAX_PLAYER_NAME];
				for(new j = 0; j <= DynamicRaces[RaceID][MaxDrivers]; j++)
				{
					GetPlayerName(RaceDriversID[j], tmpname, sizeof(tmpname));
					DisablePlayerRaceCheckpoint(RaceDriversID[j]);
					if(strlen(RaceDrivers[j]) != 0)
					{
						if(strcmp(tmpname, RaceDrivers[j], true, strlen(tmpname)) == 0)
						{
							SendClientMessage(RaceDriversID[j], COLOR_LIGHTYELLOW2, "[INFO:] Wyœcig zosta³ przerwany przez administratora. Pieni¹dze zosta³y zwrócone.");
							GivePlayerCash(RaceDriversID[j], DynamicRaces[RaceID][EnterPrice]);

							SavePlayerData(playerid, "Cash");
						}
					}
					RaceDriversID[j] = 255;
					RaceTimeM[j] = 0;
					RaceTimeS[j] = 0;
					strdel(RaceDrivers[j], 0, MAX_PLAYER_NAME);
				}
				DynamicRaces[RaceID][Started] = 0;
				IsAnyRaceStarted = 0;
				strdel(RaceOrganizator, 0, MAX_PLAYER_NAME);
				RacePlace = 0;
				RaceStarted = 0;
				RaceDriversCount = 0;
				RaceID = 255;
				format(string, sizeof(string), "[INFO:] Race edned by %s", GetPlayerNameEx(playerid));
				SendAdminMessage(COLOR_YELLOW, string);
				SaveDynamicRaces();
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] There are no active races now");
			}
			return 1;
		}
		if(strcmp(cmd, "/awartimeleft", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			format(string, sizeof(string), "[INFO:] WarTimeCountdown: %d", WarTimeCountdown);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			return 1;
		}
		if(strcmp(cmd, "/awartimestart", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] != 5)
				return 0;
			WarTime = 1;
			WarTimeCountdown = 300;
			format(string, sizeof(string), "[INFO:] WarTime started by %s", GetPlayerNameEx(playerid));
			SendAdminMessage(COLOR_YELLOW, string);
			SendClientMessageToAll(COLOR_LIGHTYELLOW2, "[INFO:] Ze wzglêdu na panuj¹cy chaos w mieœcie zostaje wprowadzony Stan Wojenny !");
			SendClientMessageToAll(COLOR_LIGHTYELLOW2, "[INFO:] Wszystkim mieszkañcom radzimy pozostaæ w domach.");
			return 1;
		}
		if(strcmp(cmd, "/agetcar", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 1)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /agetcar [carid]");
				return 1;
			}
			new carID;
			new Float:playerAngle;
			new Float:playerX;
			new Float:playerY;
			new Float:playerZ;
			GetPlayerPos(playerid, playerX, playerY, playerZ);
			GetPlayerFacingAngle(playerid, playerAngle);

			carID = strval(tmp);
			if(playerAngle > 315.0 && playerAngle < 360.0)
				SetVehicleToPos(carID, playerX, playerY + 5, playerZ);
			else if(playerAngle > 45.0 && playerAngle < 135.0)
				SetVehicleToPos(carID, playerX - 5, playerY, playerZ);
			else if(playerAngle > 135.0 && playerAngle < 225.0)
				SetVehicleToPos(carID, playerX, playerY - 5, playerZ);
			else if(playerAngle > 225.0 && playerAngle < 315)
				SetVehicleToPos(carID, playerX + 5, playerY, playerZ);
			else
				SetVehicleToPos( carID, playerX, playerY, playerZ );
			LinkVehicleToInterior( carID, GetPlayerInterior(playerid) );
			SetVehicleVirtualWorld( carID, GetPlayerVirtualWorld(playerid) );
			gVehData[carID-1][CarVW] = GetPlayerVirtualWorld(playerid);
			gVehData[carID-1][CarInterior] = GetPlayerInterior(playerid);
			SaveVehData( carID-1, "CarVW" );
			SaveVehData( carID-1, "CarInterior" );
			return 1;
		}
		if(strcmp(cmd, "/agetcars", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 1)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /agetcar [carserial]");
				return 1;
			}
			new carID;
			new Float:playerAngle;
			new Float:playerX;
			new Float:playerY;
			new Float:playerZ;
			GetPlayerPos(playerid, playerX, playerY, playerZ);
			GetPlayerFacingAngle(playerid, playerAngle);
			new serial = strval(tmp);
			for(new i = 0; i < sizeof(gVehData); i++)
			{
				if(gVehData[i][CarSerial] == serial)
				{
					carID = i;
					if(playerAngle > 315.0 && playerAngle < 360.0)
					{
						SetVehicleToPos(carID+1, playerX, playerY + 5, playerZ);
					}
					else if(playerAngle > 45.0 && playerAngle < 135.0)
					{
						SetVehicleToPos(carID+1, playerX - 5, playerY, playerZ);
					}
					else if(playerAngle > 135.0 && playerAngle < 225.0)
					{
						SetVehicleToPos(carID+1, playerX, playerY - 5, playerZ);
					}
					else if(playerAngle > 225.0 && playerAngle < 315)
					{
						SetVehicleToPos(carID+1, playerX + 5, playerY, playerZ);
					}
					else
					{
						SetVehicleToPos( carID+1, playerX, playerY, playerZ );
						LinkVehicleToInterior( carID+1, GetPlayerInterior(playerid) );
						SetVehicleVirtualWorld( carID+1, GetPlayerVirtualWorld(playerid) );
						gVehData[carID-1][CarVW] = GetPlayerVirtualWorld(playerid);
						gVehData[carID-1][CarInterior] = GetPlayerInterior(playerid);
						SaveVehData( carID-1, "CarVW" );
						SaveVehData( carID-1, "CarInterior" );
					}
					return 1;
				}
			}
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] No such car with that serial");
			return 1;
		}
		// if(strcmp(cmd, "/asetplayervipcar", true) == 0)
		// {
			// if(gPlayerData[playerid][pAdmin] < 20)
			// {
				// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Nie jesteœ administratorem.");
				// return 1;
			// }
			// tmp = strtok(cmdtext, idx);
			// if(!strlen(tmp))
			// {
				// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /asetplayervipcar [playerid]");
				// return 1;
			// }
			// giveplayerid = ReturnUser(tmp);
			// if(IsPlayerConnected(giveplayerid))
			// {
				// tmp = strtok(cmdtext, idx);
				// if(!strlen(tmp))
				// {
					// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /asetplayervipcar [playerid] [0-1]");
					// return 1;
				// }
				// new playervipcar;
				// playervipcar = strval(tmp);
				// if(playervipcar < 0 || playervipcar > 1) { SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] 0-1."); return 1; }
				// gPlayerData[giveplayerid][pVipCar] = playervipcar;
				// format(string, sizeof(string), "[INFO:] VipCar status for player: %d was set to: %d by %s", giveplayerid, playervipcar, GetPlayerNameEx(playerid));
				// SendAdminMessage(COLOR_YELLOW, string);
				// SavePlayerData(giveplayerid, "VipCar");
				// printf("[WARNING:] %s used /asetplayervipcar", gPlayerData[playerid][pName]);
				// return 1;
			// }
			// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Gracz od danym ID nie jest ON-LINE");
			// return 1;
		// }
		if(strcmp(cmd, "/asetplayervipafk", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] != 5)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /asetplayervipafk [playerid]");
				return 1;
			}
			giveplayerid = ReturnUser(tmp);
			if(IsPlayerConnected(giveplayerid))
			{
				tmp = strtok(cmdtext, idx);
				if(!strlen(tmp))
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /asetplayervipafk [playerid] [0-1]");
					return 1;
				}
				new playervipafk;
				playervipafk = strval(tmp);
				if(playervipafk < 0 || playervipafk > 1) { SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] 0-1."); return 1; }
				gPlayerData[giveplayerid][pVipAFK] = playervipafk;
				format(string, sizeof(string), "[INFO:] VipAFK status for player: %d was set to: %d by %s", giveplayerid, playervipafk, GetPlayerNameEx(playerid));
				SendAdminMessage(COLOR_YELLOW, string);
				SavePlayerData(playervipafk, "VipAFK");
				printf("[WARNING:] %s used /asetplayervipafk", gPlayerData[playerid][pName]);
				return 1;
			}
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Gracz od danym ID nie jest ON-LINE");
			return 1;
		}
		if(strcmp(cmd, "/afuelcar", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] != 5)
				return 0;
			gVehData[tmpcar][CarFuel] = float(VehFTank(tmpcar+1));
			printf("[WARNING:] %s used /afuelcar", gPlayerData[playerid][pName]);
			return 1;
		}
		if(strcmp(cmd, "/asetplayerdrunk", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] != 5)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /asetplayerdrunk [playerid]");
				return 1;
			}
			giveplayerid = ReturnUser(tmp);
			SetPlayerDrunkLevel(giveplayerid, 50000);
			return 1;
		}
		if(strcmp(cmd, "/aplay", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] != 5)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /aplay [musiid] [handleid]");
				return 1;
			}
			new idtmp;
			idtmp = strval(tmp);
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /aplay [musiid] [handleid]");
				return 1;
			}
			new handleid;
			handleid = strval(tmp);
			foreach(Player, i )
			{
				Audio_Play(playerid, idtmp, false, false, false);
				Audio_Set3DPosition(i, handleid, -1281.046,-2113.415,26.866, 150);
			}
			printf("idtmp %d, handleid %d", idtmp, handleid);
			return 1;
		}
		/*
		if(strcmp(cmdtext, "/oparklev1", true)==0)
		{
			if(gPlayerData[playerid][pFaction] == 9)
			{
				MoveDynamicObject (parkgate1a, -3072.5986328125, 422.125, -2.3701224327087, 5);
				MoveDynamicObject (parkgate1b, -3073.4033203125, 428.125, -2.3951225280762, 5.0);
				SendClientMessageToAll(COLOR_URZAD,"[URZ¥D SF:] Parking lev 1 Otwarty");
				return 1;
				}
				else
				{
				new tmpstring[256];
				format(tmpstring, sizeof(tmpstring), "Frakcja: %d, Typ: %d",gPlayerData[playerid][pFaction], DynamicFactions[gPlayerData[playerid][pFaction]][fType]);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Niew³aœciwa frakcja/typ.");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, tmpstring);
				return 1;
			}
		}
		if(strcmp(cmdtext, "/zparklev1", true)==0)
		{
			if(gPlayerData[playerid][pFaction] == 9)
			{
				MoveDynamicObject (parkgate1a, -3072.5986328125, 422.12594604492, 1.2798770666122, 5);
				MoveDynamicObject (parkgate1b, -3073.4038085938, 428.12539672852, 1.2798770666122, 5.0);
				SendClientMessageToAll(COLOR_URZAD,"[URZ¥D SF:] Parking lev 1 Zamkniety");
				return 1;
				}
				else
				{
				new tmpstring[256];
				format(tmpstring, sizeof(tmpstring), "Frakcja: %d, Typ: %d",gPlayerData[playerid][pFaction], DynamicFactions[gPlayerData[playerid][pFaction]][fType]);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Niew³aœciwa frakcja/typ.");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, tmpstring);
				return 1;
			}
		}
		if(strcmp(cmdtext, "/oparklev2", true)==0)
		{
			if(gPlayerData[playerid][pFaction] == 9)
			{
				MoveDynamicObject (parkgate2, -3083.8598632813, 400.09176635742, 11.477691650391, 5);
				MoveDynamicObject (parkgate2a, -3100.1625976563, 398.29797363281, 16.896947860718, 5);
				SendClientMessageToAll(COLOR_URZAD,"[URZ¥D SF:] Parking lev 2 Otwarty");
				return 1;
				}
				else
				{
				new tmpstring[256];
				format(tmpstring, sizeof(tmpstring), "Frakcja: %d, Typ: %d",gPlayerData[playerid][pFaction], DynamicFactions[gPlayerData[playerid][pFaction]][fType]);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Niew³aœciwa frakcja/typ.");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, tmpstring);
				return 1;
			}
		}
		if(strcmp(cmdtext, "/zparklev2", true)==0)
		{
			if(gPlayerData[playerid][pFaction] == 9)
			{
				MoveDynamicObject (parkgate2, -3074.2590332031, 400.93130493164, 11.477691650391, 5);
				MoveDynamicObject (parkgate2a, -3110.4201660156, 396.79696655273, 16.896947860718, 5);
				SendClientMessageToAll(COLOR_URZAD,"[URZ¥D SF:] Parking lev 2 Zamkniety");
				return 1;
				}
				else
				{
				new tmpstring[256];
				format(tmpstring, sizeof(tmpstring), "Frakcja: %d, Typ: %d",gPlayerData[playerid][pFaction], DynamicFactions[gPlayerData[playerid][pFaction]][fType]);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Niew³aœciwa frakcja/typ.");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, tmpstring);
				return 1;
			}
		}
		if(strcmp(cmdtext, "/oparklev3", true)==0)
		{
			if(gPlayerData[playerid][pFaction] == 9)
			{
				MoveDynamicObject (parkgate3, -3083.7998046875, 400.5234375, 16.802698135376, 5);
				SendClientMessageToAll(COLOR_URZAD,"[URZ¥D SF:] Parking lev 3 Otwarty");
				return 1;
				}
				else
				{
				new tmpstring[256];
				format(tmpstring, sizeof(tmpstring), "Frakcja: %d, Typ: %d",gPlayerData[playerid][pFaction], DynamicFactions[gPlayerData[playerid][pFaction]][fType]);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Niew³aœciwa frakcja/typ.");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, tmpstring);
				return 1;
			}
		}
		if(strcmp(cmdtext, "/zparklev3", true)==0)
		{
			if(gPlayerData[playerid][pFaction] == 9)
				{
				MoveDynamicObject (parkgate3, -3074.3471679688, 401.5930480957, 16.802698135376, 5);
				SendClientMessageToAll(COLOR_URZAD,"[URZ¥D SF:] Parking lev 3 Zamkniety");
				return 1;
				}
				else
				{
				new tmpstring[256];
				format(tmpstring, sizeof(tmpstring), "Frakcja: %d, Typ: %d",gPlayerData[playerid][pFaction], DynamicFactions[gPlayerData[playerid][pFaction]][fType]);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Niew³aœciwa frakcja/typ.");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, tmpstring);
				return 1;
			}
		}
		*/
		if(strcmp(cmd, "/asetplayervipexp", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] != 5)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /asetplayervipexp [playerid]");
				return 1;
			}
			giveplayerid = ReturnUser(tmp);
			if(IsPlayerConnected(giveplayerid))
			{
				tmp = strtok(cmdtext, idx);
				if(!strlen(tmp))
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /asetplayervipexp [playerid] [0-1]");
					return 1;
				}
				new playervipexp;
				playervipexp = strval(tmp);
				if(playervipexp < 0 || playervipexp > 1) { SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] 0-1."); return 1; }
				gPlayerData[giveplayerid][pVipExp] = playervipexp;
				format(string, sizeof(string), "[INFO:] VipExp status for player: %d was set to: %d by %s", giveplayerid, playervipexp, GetPlayerNameEx(playerid));
				SendAdminMessage(COLOR_YELLOW, string);
				SavePlayerData(playervipexp, "VipExp");
				return 1;
			}
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Gracz od danym ID nie jest ON-LINE");
			return 1;
		}if(strcmp(cmd, "/asetplayervipafk", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] != 5)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /asetplayervipafk [playerid]");
				return 1;
			}
			giveplayerid = ReturnUser(tmp);
			if(IsPlayerConnected(giveplayerid))
			{
				tmp = strtok(cmdtext, idx);
				if(!strlen(tmp))
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /asetplayervipafk [playerid] [0-1]");
					return 1;
				}
				new playervipafk;
				playervipafk = strval(tmp);
				if(playervipafk < 0 || playervipafk > 1) { SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] 0-1."); return 1; }
				gPlayerData[giveplayerid][pVipAFK] = playervipafk;
				format(string, sizeof(string), "[INFO:] VipAFK status for player: %d was set to: %d by %s", giveplayerid, playervipafk, GetPlayerNameEx(playerid));
				SendAdminMessage(COLOR_YELLOW, string);
				SavePlayerData(playerid, "VipAFK");
				return 1;
			}
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Gracz od danym ID nie jest ON-LINE");
			return 1;
		}/*
		if(strcmp(cmdtext, "/ogarvla", true)==0)
		{
			if(gPlayerData[playerid][pFaction] == 10)
			{
				MoveDynamicObject (vlagarage, -1863.931640625, -172.60931396484, 11.719511032104, 5);
				SendFactionMessage(10, COLOR_ORANGE,"[Varios Los Aztecas:] Garaz zostal Otwarty");
				return 1;
			}
			else
			{
				new tmpstring[256];
				format(tmpstring, sizeof(tmpstring), "Frakcja: %d, Typ: %d",gPlayerData[playerid][pFaction], DynamicFactions[gPlayerData[playerid][pFaction]][fType]);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Niew³aœciwa frakcja/typ.");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, tmpstring);
				return 1;
			}
		}
		if(strcmp(cmdtext, "/zgarvla", true)==0)
		{
			if(gPlayerData[playerid][pFaction] == 10)
			{
				MoveDynamicObject (vlagarage, -1863.7481689453, -179.64143371582, 11.819509506226, 5);
				SendFactionMessage(10, COLOR_ORANGE,"[Varios Los Aztecas:] Garaz zostal Zamkniety");
				return 1;
			}
			else
			{
				new tmpstring[256];
				format(tmpstring, sizeof(tmpstring), "Frakcja: %d, Typ: %d",gPlayerData[playerid][pFaction], DynamicFactions[gPlayerData[playerid][pFaction]][fType]);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Niew³aœciwa frakcja/typ.");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, tmpstring);
				return 1;
			}
		}
		if(strcmp(cmdtext, "/ogarcza", true)==0)
		{
			if(gPlayerData[playerid][pFaction] == 8)
			{
				MoveDynamicObject (czagarage, -2691.48046875, 1398.8544921875, 5.9124183654785, 5);
				SendFactionMessage(8, COLOR_DARKPURPLE,"[Cza King:] Garaz zostal Otwarty");
				return 1;
			}
			else
			{
				new tmpstring[256];
				format(tmpstring, sizeof(tmpstring), "Frakcja: %d, Typ: %d",gPlayerData[playerid][pFaction], DynamicFactions[gPlayerData[playerid][pFaction]][fType]);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Niew³aœciwa frakcja/typ.");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, tmpstring);
				return 1;
			}
		}
		if(strcmp(cmdtext, "/zgarcza", true)==0)
		{
			if(gPlayerData[playerid][pFaction] == 8)
			{
				MoveDynamicObject (czagarage, -2691.4807128906, 1398.8544921875, 12.812417984009, 5);
				SendFactionMessage(8, COLOR_DARKPURPLE,"[Cza King:] Garaz zostal Zamkniety");
				return 1;
			}
			else
			{
				new tmpstring[256];
				format(tmpstring, sizeof(tmpstring), "Frakcja: %d, Typ: %d",gPlayerData[playerid][pFaction], DynamicFactions[gPlayerData[playerid][pFaction]][fType]);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Niew³aœciwa frakcja/typ.");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, tmpstring);
				return 1;
			}
		} */
		/*if(strcmp(cmdtext, "/oparkmost", true)==0)
		{
			if(gPlayerData[playerid][pFaction] == 9)
			{
				MoveDynamicObject (parkmost, -2990.7666015625, 431.8955078125, 6.5404720306396, 5);
				SendClientMessageToAll(COLOR_URZAD,"[Urzad:] Most zostal Otwarty");
				return 1;
				}
				else
				{
				new tmpstring[256];
				format(tmpstring, sizeof(tmpstring), "Frakcja: %d, Typ: %d",gPlayerData[playerid][pFaction], DynamicFactions[gPlayerData[playerid][pFaction]][fType]);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Niew³aœciwa frakcja/typ.");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, tmpstring);
				return 1;
			}
		}
		if(strcmp(cmdtext, "/zparkmost", true)==0)
		{
			if(gPlayerData[playerid][pFaction] == 9)
			{
				MoveDynamicObject (parkmost, -2990.7666015625, 431.8955078125, -9.1095333099365, 5);
				SendClientMessageToAll(COLOR_URZAD,"[Urzad:] Most zostal Zamkniety");
				return 1;
				}
				else
				{
				new tmpstring[256];
				format(tmpstring, sizeof(tmpstring), "Frakcja: %d, Typ: %d",gPlayerData[playerid][pFaction], DynamicFactions[gPlayerData[playerid][pFaction]][fType]);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] Niew³aœciwa frakcja/typ.");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, tmpstring);
				return 1;
			}
		}
		*/

		if(strcmp(cmd, "/asetplayervipafkt", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] != 5)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /asetplayervipafkt [playerid]");
				return 1;
			}
			giveplayerid = ReturnUser(tmp);
			if(IsPlayerConnected(giveplayerid))
			{
				tmp = strtok(cmdtext, idx);
				if(!strlen(tmp))
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /asetplayervipafkt [playerid] [0-1]");
					return 1;
				}
				new playervipafkt;
				playervipafkt = strval(tmp);
				if(playervipafkt < 0 || playervipafkt > 1) { SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] 0-1."); return 1; }
				if(playervipafkt == 1)
				{
					if(getdate() < 335)
					{
						gPlayerData[giveplayerid][pVipAFKT] = getdate() + 30;

						SavePlayerData(giveplayerid, "VipAFKT");
					}
					if(getdate() >= 335)
					{
						gPlayerData[giveplayerid][pVipAFKT] = 30 - 365 - getdate();

						SavePlayerData(giveplayerid, "VipAFKT");
					}
				}
				if(playervipafkt == 0)
				{
					gPlayerData[giveplayerid][pVipAFKT] = 0;

					SavePlayerData(giveplayerid, "VipAFKT");
				}
				printf("[WARNING:] %s used /asetplayervipafkt", gPlayerData[playerid][pName]);
				format(string, sizeof(string), "[INFO:] VipAFKT status for player: %d was set to: %d by %s", giveplayerid, playervipafkt, GetPlayerNameEx(playerid));
				SendAdminMessage(COLOR_YELLOW, string);
				format(string, sizeof(string), "[INFO:] Day of end: %d", gPlayerData[giveplayerid][pVipAFKT]);
				SendAdminMessage(COLOR_YELLOW, string);
				SavePlayerData(giveplayerid, "VipAFKT");
				return 1;
			}
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Gracz od danym ID nie jest ON-LINE");
			return 1;
		}
		if(strcmp(cmd, "/mechanicy", true) == 0)
		{
			new count = 0;
			// CreateDynamicPickup(1239,2,-1855,127,15,0,-1,-1,50.0); // biuro mechaników
			if(!PlayerToPoint(3.0,playerid,-1855.0,127.0,15.0) && !PlayerToPoint(3.0,playerid,613.0,4.0,1001.0))
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Musisz znajdowaæ siê w biurze mechaników !");
				return 1;
			}
			SendClientMessage(playerid, COLOR_LIGHTGREEN, "----------[MECHANICY]----------");
			foreach(Player, i )
			{
				if(gPlayerData[i][pJob] == 17 )
				{
					format(string, 128, "* %s ", GetPlayerNameEx(i));
					SendClientMessage(playerid, COLOR_WHITE, string);
					count++;
				}
			}
			if(count == 0)
			{
				SendClientMessage(playerid,COLOR_WHITE,"[INFO:] Aktualnie brak mechaników bêd¹cych w pracy");
			}
			SendClientMessage(playerid, COLOR_LIGHTGREEN, "----------------------------------------------------------");
			return 1;
		}
		if(strcmp(cmd, "/pw", true) == 0)
		{
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /pw [playerid] [treœæ]");
				return 1;
			}
			if ((nopwooc) && gPlayerData[playerid][pAdmin] < 1)
			{
				SendClientMessage(playerid, COLOR_GRAD2, "[INFO:] Chat PWOOC zosta³ wy³¹czony przez administratora !");
				return 1;
			}
			giveplayerid = ReturnUser(tmp);
			if(IsPlayerConnected(giveplayerid) && gPlayerLogged[giveplayerid] && gPlayerData[playerid][pTutorial])
			{
				if(giveplayerid != INVALID_PLAYER_ID)
				{
					new length = strlen(cmdtext);
					while ((idx < length) && (cmdtext[idx] <= ' '))
					{
						idx++;
					}
					new offset = idx;
					new result[128];
					while ((idx < length) && ((idx - offset) < (sizeof(result) - 1)))
					{
						result[idx - offset] = cmdtext[idx];
						idx++;
					}
					result[idx - offset] = EOS;
					if(!strlen(result))
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /pw [playerid] [treœæ]");
						return 1;
					}
					if(giveplayerid != playerid)
					{
						if(gPlayerData[giveplayerid][pPWStatus] == 0)
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Gracz wy³¹czy³ otrzymywanie wiadomoœci PW.");
							return 1;
						}
						format(string, sizeof(string), "[%s] [%d] PW: %s", gPlayerData[playerid][pOOCName], playerid, result);
						foreach(Player, i )
						{
							if(BigEar[i])
							{
								SendClientMessage(i, COLOR_DARKBROWN, string);
							}
						}
						SendClientMessage(giveplayerid, COLOR_DARKBROWN, string);
						SendClientMessage(playerid, COLOR_DARKBROWN, string);
						// if(!(gPlayerData[playerid][pAdmin] > 0) && GetPlayerState(playerid) != 9)
						// {
							// PlayerActionMessage(playerid,5.0,"pisze PW.");
						// }

						new Year, Month, Day;
						getdate(Year, Month, Day);
						new Hour, Minute, Second;
						gettime(Hour, Minute, Second);

						format(string, sizeof(string), "%02d/%02d/%d, %02d:%02d:%02d, %s [%d] PW: %s", Day, Month, Year, Hour, Minute, Second, GetPlayerNameEx(playerid), playerid, result);
						PMLog(string);
					}
					else
					{
						SendClientMessage(playerid,COLOR_LIGHTYELLOW2,"[B£¥D:] Nie mo¿esz pisaæ sam do siebie.");
					}
					return 1;
				}
			}
			else
			{
				format(string, sizeof(string), "[B£¥D:] Gracz o id %d nie jest po³¹czony.", strval(tmp));
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			}
			return 1;
		}
		if(strcmp(cmd, "/asetplayervipexpt", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] != 5)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /asetplayervipexpt [playerid]");
				return 1;
			}
			giveplayerid = ReturnUser(tmp);
			if(IsPlayerConnected(giveplayerid))
			{
				tmp = strtok(cmdtext, idx);
				if(!strlen(tmp))
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /asetplayervipexpt [playerid] [0-1]");
					return 1;
				}
				new playervipexpt;
				playervipexpt = strval(tmp);
				if(playervipexpt < 0 || playervipexpt > 1) { SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[B£¥D:] 0-1."); return 1; }
				if(playervipexpt == 1)
				{
					if(getdate() < 335)
					{
						gPlayerData[giveplayerid][pVipExpT] = getdate() + 30;
					}
					if(getdate() >= 335)
					{
						gPlayerData[giveplayerid][pVipExpT] = 365 - 30 - getdate();
					}
				}
				if(playervipexpt == 0)
				{
					gPlayerData[giveplayerid][pVipExpT] = 0;
				}
				printf("[WARNING:] %s used /asetplayervipexpt", gPlayerData[playerid][pName]);
				format(string, sizeof(string), "[INFO:] VipExpT status for player: %d was set to: %d by %s", giveplayerid, playervipexpt, GetPlayerNameEx(playerid));
				SendAdminMessage(COLOR_YELLOW, string);
				format(string, sizeof(string), "[INFO:] Day of end: %d", gPlayerData[giveplayerid][pVipAFKT]);
				SendAdminMessage(COLOR_YELLOW, string);
				SavePlayerData(giveplayerid, "VipExpT");
				return 1;
			}
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Gracz od danym ID nie jest ON-LINE");
			return 1;
		}
		if(strcmp(cmd, "/pojazdy", true) == 0)
		{
			SendClientMessage(playerid, COLOR_YELLOW,"______________________Pojazdy______________________");
			SendClientMessage(playerid, COLOR_RED, "Aby wyœwietliæ listê pojazdów u¿yj komendy odpowiadaj¹cej za kategorie pojazdu.");
			SendClientMessage(playerid, COLOR_RED, "Lista pojazdów wykonana na podstawie cennika by Xavier.");
			SendClientMessage(playerid, COLOR_GREY, "/samochody1-14 - Lista samochodów.");
			SendClientMessage(playerid, COLOR_GREY, "/motory1 - Lista motorów");
			SendClientMessage(playerid, COLOR_GREY, "/rowery - Lista rowerów");
			SendClientMessage(playerid, COLOR_GREY, "/helikoptery - Lista helikopterów");
			SendClientMessage(playerid, COLOR_GREY, "/samoloty - Lista samolotów");
			SendClientMessage(playerid, COLOR_GREY, "/lodzie - Lista ³odzi");
			return 1;
		}
		if(strcmp(cmd, "/samochody1", true) == 0)
		{
			SendClientMessage(playerid, COLOR_YELLOW,"______________________Samochody___________________");
			SendClientMessage(playerid, COLOR_RED, "Pierwsza czêœæ spisu samochodów.");
			SendClientMessage(playerid, COLOR_GREY, "Admiral - 445 - 30.000$");
			SendClientMessage(playerid, COLOR_GREY, "Alpha - 602 - 430.000$");
			SendClientMessage(playerid, COLOR_GREY, "Ambulance - 416 - 140.000$");
			SendClientMessage(playerid, COLOR_GREY, "Baggage - 485 - 10.500$");
			SendClientMessage(playerid, COLOR_GREY, "Bandito - 568 - 80.000$");
			SendClientMessage(playerid, COLOR_GREY, "Banshee - 429 - 790.000$");
			SendClientMessage(playerid, COLOR_GREY, "Barracks - 433 - 640.000$");
			SendClientMessage(playerid, COLOR_GREY, "Benson - 499 - 60.000$");
			SendClientMessage(playerid, COLOR_GREY, "Bfinject - 424 - 760.000$");
			SendClientMessage(playerid, COLOR_GREY, "Blade - 536) - 31.000$");
			return 1;
		}
		if(strcmp(cmd, "/samochody2", true) == 0)
		{
			SendClientMessage(playerid ,COLOR_YELLOW,"______________________Samochody___________________");
			SendClientMessage(playerid, COLOR_RED, "Druga czêœæ spisu samochodów.");
			SendClientMessage(playerid, COLOR_GREY, "Blistac - 496 - 41.000$");
			SendClientMessage(playerid, COLOR_GREY, "Bloodra - 504 - 900.000$");
			SendClientMessage(playerid, COLOR_GREY, "Bobcat - 422 - 33.000$");
			SendClientMessage(playerid, COLOR_GREY, "Boxburg - 609 - 66.000$");
			SendClientMessage(playerid, COLOR_GREY, "Boxville - 498 - 50.000$");
			SendClientMessage(playerid, COLOR_GREY, "Bravura - 401 - 15.000$");
			SendClientMessage(playerid, COLOR_GREY, "Broadway - 575 - 15.000$");
			SendClientMessage(playerid, COLOR_GREY, "Buccanee - 518 - 19.500$");
			SendClientMessage(playerid, COLOR_GREY, "Buffalo - 402 - 540.000$");
			SendClientMessage(playerid, COLOR_GREY, "Bullet - 541 - 800.000$");
			return 1;
		}
		if(strcmp(cmd, "/samochody3", true) == 0)
		{	
			SendClientMessage(playerid, COLOR_YELLOW,"______________________Samochody___________________");
			SendClientMessage(playerid, COLOR_RED, "Trzecia czêœæ spisu samochodów.");
			SendClientMessage(playerid, COLOR_GREY, "Burrito - 482 - 55.000$");
			SendClientMessage(playerid, COLOR_GREY, "Bus - 431 - 660.000$");
			SendClientMessage(playerid, COLOR_GREY, "Cabbie - 438 - 43.000$");
			SendClientMessage(playerid, COLOR_GREY, "Caddy - 457 - 5.000$");
			SendClientMessage(playerid, COLOR_GREY, "Cadrona - 527 - 25.000$");
			SendClientMessage(playerid, COLOR_GREY, "Camper - 483 - 70.000$");
			SendClientMessage(playerid, COLOR_GREY, "Cement - 524 - 620.000$");
			SendClientMessage(playerid, COLOR_GREY, "Cheetah - 415 - 850.000$");
			SendClientMessage(playerid, COLOR_GREY, "Clover - 542 - 33.000$");
			SendClientMessage(playerid, COLOR_GREY, "Club - 589 - 130.000$");
			return 1;
		}
		if(strcmp(cmd, "/samochody4", true) == 0)
		{
			SendClientMessage(playerid, COLOR_YELLOW,"______________________Samochody___________________");
			SendClientMessage(playerid, COLOR_RED, "Czwarta czêœæ spisu samochodów.");
			SendClientMessage(playerid, COLOR_GREY, "Coach - 437 - 680.000$");
			SendClientMessage(playerid, COLOR_GREY, "Combine - 532 - 215.000$");
			SendClientMessage(playerid, COLOR_GREY, "Comet - 480 - 690.000$");
			SendClientMessage(playerid, COLOR_GREY, "CopCarla - 596 - 100.000$");
			SendClientMessage(playerid, COLOR_GREY, "CopCarru - 599 - 150.000$");
			SendClientMessage(playerid, COLOR_GREY, "CopCarsf - 597 - 100.000$");
			SendClientMessage(playerid, COLOR_GREY, "CopCarlv - 598 - 100.000$");
			SendClientMessage(playerid, COLOR_GREY, "Cft30 - 578 - 160.000$");
			SendClientMessage(playerid, COLOR_GREY, "Dumper - 406 - 2.000.000$");
			SendClientMessage(playerid, COLOR_GREY, "Duneride - 573 - 250.000$");
			return 1;
		}
		if(strcmp(cmd, "/samochody5", true) == 0)
		{
			SendClientMessage(playerid, COLOR_YELLOW,"______________________Samochody___________________");
			SendClientMessage(playerid, COLOR_RED, "Pi¹ta czêœæ spisu samochodów.");
			SendClientMessage(playerid, COLOR_GREY, "Elegant - 507 - 34.000$");
			SendClientMessage(playerid, COLOR_GREY, "Elegy - 562 - 430.000$");
			SendClientMessage(playerid, COLOR_GREY, "Emperor - 585 - 22.000$");
			SendClientMessage(playerid, COLOR_GREY, "Enforcer - 427 - 440.000$");
			SendClientMessage(playerid, COLOR_GREY, "Esperant - 419 - 32.000$");
			SendClientMessage(playerid, COLOR_GREY, "Euros - 587 - 620.000$");
			SendClientMessage(playerid, COLOR_GREY, "FBIRancher - 490 - 200.000$");
			SendClientMessage(playerid, COLOR_GREY, "FbiTruck - 528 - 600.000$");
			SendClientMessage(playerid, COLOR_GREY, "Felze - 533 - 52.000$");
			SendClientMessage(playerid, COLOR_GREY, "Firela - 544 - 740.000$");
			return 1;
		}
		if(strcmp(cmd, "/samochody6", true) == 0)
		{
			SendClientMessage(playerid, COLOR_YELLOW,"______________________Samochody___________________");
			SendClientMessage(playerid, COLOR_RED, "Szósta czêœæ spisu samochodów.");
			SendClientMessage(playerid, COLOR_GREY, "Firetruck - 407 - 1.300.000$");
			SendClientMessage(playerid, COLOR_GREY, "Flash - 565 - 150.000$");
			SendClientMessage(playerid, COLOR_GREY, "Flatbed - 455 - 380.000$");
			SendClientMessage(playerid, COLOR_GREY, "Forklift - 530 - 5.000$");
			SendClientMessage(playerid, COLOR_GREY, "Fortune - 526 - 28.000$");
			SendClientMessage(playerid, COLOR_GREY, "Glendale - 466 - 25.000$");
			SendClientMessage(playerid, COLOR_GREY, "Greenwood - 492 - 24.000$");
			SendClientMessage(playerid, COLOR_GREY, "Hermes - 474 - 21.000$");
			SendClientMessage(playerid, COLOR_GREY, "HotDog - 588 - 55.000$");
			SendClientMessage(playerid, COLOR_GREY, "Hotknife - 434 - 71.000$");
			return 1;
		}
		if(strcmp(cmd, "/samochody7", true) == 0)
		{
			SendClientMessage(playerid, COLOR_YELLOW,"______________________Samochody___________________");
			SendClientMessage(playerid, COLOR_RED, "Siódma czêœæ spisu samochodów.");
			SendClientMessage(playerid, COLOR_GREY, "Hotrina - 502 - 1.000.000$");
			SendClientMessage(playerid, COLOR_GREY, "Hotrinb - 503 - 1.000.000$");
			SendClientMessage(playerid, COLOR_GREY, "Hotring - 494 - 900.000$");
			SendClientMessage(playerid, COLOR_GREY, "Huntley - 579 - 89.000$");
			SendClientMessage(playerid, COLOR_GREY, "Hustler - 545 - 200.000$");
			SendClientMessage(playerid, COLOR_GREY, "Infernus - 411 - 720.000$");
			SendClientMessage(playerid, COLOR_GREY, "Intruder - 546 - 22.200$");
			SendClientMessage(playerid, COLOR_GREY, "Jester - 559 - 620.000$");
			SendClientMessage(playerid, COLOR_GREY, "Journey - 508 - 200.000$");
			SendClientMessage(playerid, COLOR_GREY, "Kart - 571 - 55.000$");
			return 1;
		}
		if(strcmp(cmd, "/samochody8", true) == 0)
		{
			SendClientMessage(playerid ,COLOR_YELLOW,"______________________Samochody___________________");
			SendClientMessage(playerid, COLOR_RED, "Ósma czêœæ spisu samochodów.");
			SendClientMessage(playerid, COLOR_GREY, "Landstal - 400 - 85.000$");
			SendClientMessage(playerid, COLOR_GREY, "Linerunner - 403 - 1.500.000$");
			SendClientMessage(playerid, COLOR_GREY, "Majestic - 517 - 20.500$");
			SendClientMessage(playerid, COLOR_GREY, "Manana - 410 - 20.000$");
			SendClientMessage(playerid, COLOR_GREY, "Merit - 551 - 32.000$");
			SendClientMessage(playerid, COLOR_GREY, "Mesa - 500 - 70.000$");
			SendClientMessage(playerid, COLOR_GREY, "Moonbeam - 418 - 50.000$");
			SendClientMessage(playerid, COLOR_GREY, "Mowerr - 572 - 10.000$");
			SendClientMessage(playerid, COLOR_GREY, "MrWhoop - 423 - 70.000$");
			SendClientMessage(playerid, COLOR_GREY, "Monster - 444 - 420.000$");
			return 1;
		}
		if(strcmp(cmd, "/samochody9", true) == 0)
		{
			SendClientMessage(playerid, COLOR_YELLOW,"______________________Samochody___________________");
			SendClientMessage(playerid, COLOR_RED, "Dziewi¹ta czêœæ spisu samochodów.");
			SendClientMessage(playerid, COLOR_GREY, "MonsterA - 556 - 500.000$");
			SendClientMessage(playerid, COLOR_GREY, "MonsterB - 557 - 500.000$");
			SendClientMessage(playerid, COLOR_GREY, "Mule - 414 - 65.000$");
			SendClientMessage(playerid, COLOR_GREY, "Nebula - 516 - 35.000$");
			SendClientMessage(playerid, COLOR_GREY, "NewsVan - 582 - 90.000$");
			SendClientMessage(playerid, COLOR_GREY, "Oceanic - 467 - 30.000$");
			SendClientMessage(playerid, COLOR_GREY, "Packer - 443 - 250.000$");
			SendClientMessage(playerid, COLOR_GREY, "Patriot - 470 - 800.000$");
			SendClientMessage(playerid, COLOR_GREY, "Peren - 404 - 11.000$");
			SendClientMessage(playerid, COLOR_GREY, "Petro - 514 - 280.000$");
			return 1;
		}
		if(strcmp(cmd, "/samochody10", true) == 0)
		{
			SendClientMessage(playerid, COLOR_YELLOW,"______________________Samochody___________________");
			SendClientMessage(playerid, COLOR_RED, "Dziesi¹ta czêœæ spisu samochodów.");
			SendClientMessage(playerid, COLOR_GREY, "Phoenix - 603 - 710.000$");
			SendClientMessage(playerid, COLOR_GREY, "Picador - 600 - 30.000$");
			SendClientMessage(playerid, COLOR_GREY, "Pony - 413 - 50.000$");
			SendClientMessage(playerid, COLOR_GREY, "Premier - 426 - 25.000$");
			SendClientMessage(playerid, COLOR_GREY, "Previon - 436 - 19.000$");
			SendClientMessage(playerid, COLOR_GREY, "Primo - 547 - 10.200$");
			SendClientMessage(playerid, COLOR_GREY, "Rancher - 489 - 77.000$");
			SendClientMessage(playerid, COLOR_GREY, "RdTrain - 515 - 350.000$");
			SendClientMessage(playerid, COLOR_GREY, "Regina - 479 - 45.000$");
			SendClientMessage(playerid, COLOR_GREY, "Remington - 534 - 32.000$");
			return 1;
		}
		if(strcmp(cmd, "/samochody11", true) == 0)
		{
			SendClientMessage(playerid, COLOR_YELLOW,"______________________Samochody___________________");
			SendClientMessage(playerid, COLOR_RED, "Jedenasta czêœæ spisu samochodów.");
			SendClientMessage(playerid, COLOR_GREY, "Rhino - 432 - 10.000.000$");
			SendClientMessage(playerid, COLOR_GREY, "Romero - 442 - 150.000$");
			SendClientMessage(playerid, COLOR_GREY, "Rumpo - 440 - 55.000$");
			SendClientMessage(playerid, COLOR_GREY, "Sabre - 475 - 44.000$");
			SendClientMessage(playerid, COLOR_GREY, "Sedler - 543 - 80.000$");
			SendClientMessage(playerid, COLOR_GREY, "Sandking - 495 - 200.000$");
			SendClientMessage(playerid, COLOR_GREY, "Savanna - 567 - 30.000$");
			SendClientMessage(playerid, COLOR_GREY, "Securica - 428 - 400.000$");
			SendClientMessage(playerid, COLOR_GREY, "Sentinel - 405 - 30.000$");
			SendClientMessage(playerid, COLOR_GREY, "Slamvan - 535 - 30.000$");
			return 1;
		}
		if(strcmp(cmd, "/samochody12", true) == 0)
		{
			SendClientMessage(playerid, COLOR_YELLOW,"______________________Samochody___________________");
			SendClientMessage(playerid, COLOR_RED, "Dwunasta czêœæ spisu samochodów.");
			SendClientMessage(playerid, COLOR_GREY, "Solair - 458 - 28.000$");
			SendClientMessage(playerid, COLOR_GREY, "Stafford - 580 - 20.000$");
			SendClientMessage(playerid, COLOR_GREY, "Stallion - 439 - 65.000$");
			SendClientMessage(playerid, COLOR_GREY, "Stratum - 561 - 44.000$");
			SendClientMessage(playerid, COLOR_GREY, "Strech - 409 - 560.000$");
			SendClientMessage(playerid, COLOR_GREY, "Sultan - 560 - 600.000$");
			SendClientMessage(playerid, COLOR_GREY, "Sunrise - 550 - 24.100$");
			SendClientMessage(playerid, COLOR_GREY, "Super-GT - 506 - 780.000$");
			SendClientMessage(playerid, COLOR_GREY, "SwatVan - 601 - 500.000$");
			SendClientMessage(playerid, COLOR_GREY, "Sweeper - 574 - 20.400$");
			return 1;
		}
		if(strcmp(cmd, "/samochody13", true) == 0)
		{
			SendClientMessage(playerid, COLOR_YELLOW,"______________________Samochody___________________");
			SendClientMessage(playerid, COLOR_RED, "Trzynasta czêœæ spisu samochodów.");
			SendClientMessage(playerid, COLOR_GREY, "Tahoma - 566 - 34.000$");
			SendClientMessage(playerid, COLOR_GREY, "Tampa - 549 - 30.000$");
			SendClientMessage(playerid, COLOR_GREY, "Taxi - 420 - 43.000$");
			SendClientMessage(playerid, COLOR_GREY, "Topfun - 559 - 620.000$");
			SendClientMessage(playerid, COLOR_GREY, "Tornado - 576 - 18.000$");
			SendClientMessage(playerid, COLOR_GREY, "Towtruck - 525 - 140.000$");
			SendClientMessage(playerid, COLOR_GREY, "Tractor - 531 - 30.000$");
			SendClientMessage(playerid, COLOR_GREY, "Trash - 408 - 430.000$");
			SendClientMessage(playerid, COLOR_GREY, "Tug - 583 - 14.000$");
			SendClientMessage(playerid, COLOR_GREY, "Turismo - 451 - 820.000$");
			return 1;
		}
		if(strcmp(cmd, "/samochody14", true) == 0)
		{
			SendClientMessage(playerid, COLOR_YELLOW,"______________________Samochody___________________");
			SendClientMessage(playerid, COLOR_RED, "Czternasta czêœæ spisu samochodów.");
			SendClientMessage(playerid, COLOR_GREY, "Uranus - 558 - 500.000$");
			SendClientMessage(playerid, COLOR_GREY, "Utility - 552 - 32.000$");
			SendClientMessage(playerid, COLOR_GREY, "Vincent - 540 - 21.000$");
			SendClientMessage(playerid, COLOR_GREY, "Voodoo - 412 - 24.000$");
			SendClientMessage(playerid, COLOR_GREY, "Vortex - 539 - 130.000$");
			SendClientMessage(playerid, COLOR_GREY, "Washington - 421 - 33.000$");
			SendClientMessage(playerid, COLOR_GREY, "Willard - 529 - 23.200$");
			SendClientMessage(playerid, COLOR_GREY, "Windsor - 555 - 300.000$");
			SendClientMessage(playerid, COLOR_GREY, "Yankee - 456 - 100.000$");
			SendClientMessage(playerid, COLOR_GREY, "Yosemite - 554 - 78.000$");
			return 1;
		}
		if(strcmp(cmd, "/motory", true) == 0)
		{
			SendClientMessage(playerid, COLOR_YELLOW,"______________________Motory___________________");
			SendClientMessage(playerid, COLOR_RED, "Pierwsza czêœæ spisu motorów.");
			SendClientMessage(playerid, COLOR_GREY, "NRG-500 - 522 - 91.000$");
			SendClientMessage(playerid, COLOR_GREY, "Faggio - 462 - 3.000$");
			SendClientMessage(playerid, COLOR_GREY, "FCR-900 - 521 - 80.000$");
			SendClientMessage(playerid, COLOR_GREY, "PCJ-600 - 461 - 15.000$");
			SendClientMessage(playerid, COLOR_GREY, "Freeway - 463 - 20.000$");
			SendClientMessage(playerid, COLOR_GREY, "BF-400 - 581 - 70.000$");
			SendClientMessage(playerid, COLOR_GREY, "Pizzaboy - 448 - 3.000$");
			SendClientMessage(playerid, COLOR_GREY, "Wayfarer - 586 - 45.000$");
			SendClientMessage(playerid, COLOR_GREY, "CopBike - 523 - 82.000$");
			SendClientMessage(playerid, COLOR_GREY, "Sanchez - 468 - 11.000$");
			SendClientMessage(playerid, COLOR_GREY, "Quad - 471 - 22.000$");
			return 1;
		}
		if(strcmp(cmd, "/rowery", true) == 0)
		{
			SendClientMessage(playerid ,COLOR_YELLOW,"______________________Rowery___________________");
			SendClientMessage(playerid, COLOR_RED, "Pierwsza czêœæ spisu rowerów.");
			SendClientMessage(playerid, COLOR_GREY, "Bike - 509 - 700$");
			SendClientMessage(playerid, COLOR_GREY, "BMX - 481 - 900$");
			SendClientMessage(playerid, COLOR_GREY, "Mountian Bike - 510 - 1.200$");
			return 1;
		}
		if(strcmp(cmd, "/helikoptery", true) == 0)
		{
			SendClientMessage(playerid, COLOR_YELLOW,"______________________Helikoptery___________________");
			SendClientMessage(playerid, COLOR_RED, "Pierwsza czêœæ spisu helikopterów.");
			SendClientMessage(playerid, COLOR_GREY, "Cargobob - 548 - 1.000.000$");
			SendClientMessage(playerid, COLOR_GREY, "Hunter - 425 - 50.000.000$");
			SendClientMessage(playerid, COLOR_GREY, "Leviathan - 417 - 1.200.000$");
			SendClientMessage(playerid, COLOR_GREY, "Maverick - 487 - 820.000$");
			SendClientMessage(playerid, COLOR_GREY, "Police Maverick - 497 - 400.000$");
			SendClientMessage(playerid, COLOR_GREY, "Raindance - 563 - 1.000.000$");
			SendClientMessage(playerid, COLOR_GREY, "Sparrow - 469 - 200.000$");
			SendClientMessage(playerid, COLOR_GREY, "VcMaverick - 488 - 720.000$");
			return 1;
		}
		if(strcmp(cmd, "/samoloty", true) == 0)
		{
			SendClientMessage(playerid, COLOR_YELLOW,"______________________Samoloty___________________");
			SendClientMessage(playerid, COLOR_RED, "Pierwsza czêœæ spisu samolotów.");
			SendClientMessage(playerid, COLOR_GREY, "Hydra - 520 - 8.000.000$");
			SendClientMessage(playerid, COLOR_GREY, "Rustler - 476 - 1.350.000$");
			SendClientMessage(playerid, COLOR_GREY, "Dodo - 593 - 890.000$");
			SendClientMessage(playerid, COLOR_GREY, "Nevada - 553 - 600.000$");
			SendClientMessage(playerid, COLOR_GREY, "Stuntplane - 513 - 990.000$");
			SendClientMessage(playerid, COLOR_GREY, "Cropdust - 512 - 300.000$");
			SendClientMessage(playerid, COLOR_GREY, "Andromeda - 592 - 1.000.000$");
			SendClientMessage(playerid, COLOR_GREY, "Beagle - 511 - 400.000$");
			SendClientMessage(playerid, COLOR_GREY, "Skimmer - 460 - 900.000$");
			SendClientMessage(playerid, COLOR_GREY, "Shamal - 519 - 1.800.000$");
			return 1;
		}
		if(strcmp(cmd, "/lodzie", true) == 0)
		{
			SendClientMessage(playerid, COLOR_YELLOW,"______________________Samochody___________________");
			SendClientMessage(playerid, COLOR_RED, "Pierwsza czêœæ spisu ³odzi.");
			SendClientMessage(playerid, COLOR_GREY, "CoastGuard - 472 - 100.000$");
			SendClientMessage(playerid, COLOR_GREY, "Dinghy - 473 - 60.000$");
			SendClientMessage(playerid, COLOR_GREY, "Jetmax - 493 - 1.350.000$");
			SendClientMessage(playerid, COLOR_GREY, "Launch - 595 - 590.000$");
			SendClientMessage(playerid, COLOR_GREY, "Marquis - 484 - 1.220.000$");
			SendClientMessage(playerid, COLOR_GREY, "Predator - 430 - 120.000$");
			SendClientMessage(playerid, COLOR_GREY, "Reefer - 453 - 820.000$");
			SendClientMessage(playerid, COLOR_GREY, "Speeder - 452 - 600.000$");
			SendClientMessage(playerid, COLOR_GREY, "Squalo - 446 - 1.200.000$");
			SendClientMessage(playerid, COLOR_GREY, "Tropic - 454 - 1.100.000$");
			return 1;
		}
	}
 	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "Niew³aœciwa komenda, spróbuj /pomoc");
	return 1;
} // end of OnPlayerCommandText