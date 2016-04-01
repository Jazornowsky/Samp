/***
*
* File: wp_onplayercommandtext.inc
* Auth: Damian Wojdat
* Date: 15.09.2011
* Desc: Player commands.
*
*************************************************************************************************************/

public OnPlayerCommandText(playerid, cmdtext[])
{
	#if defined DEBUG
		printf("[CMD:] %s", cmdtext);
	#endif
	
	new 
		idx,
		idcar,
		tmpcar,
		giveplayerid,
		animationplayed
	;
	static
		string[256],
		string2[1024],
		cmd[256],
		tmp[256],
		giveplayer[MAX_PLAYER_NAME],
		sendername[MAX_PLAYER_NAME],
		giveplayername[MAX_PLAYER_NAME]
	;
	strdel(string, 0, sizeof(string));
	strdel(cmd, 0, sizeof(cmd));
	strdel(tmp, 0, sizeof(tmp));
	strdel(giveplayer, 0, MAX_PLAYER_NAME);
	strdel(sendername, 0, MAX_PLAYER_NAME);
	strdel(giveplayername, 0, MAX_PLAYER_NAME);
	cmd = strtok(cmdtext, idx);
	idcar = GetPlayerVehicleID(playerid);
	tmpcar = GetPlayerVehicleID(playerid) - 1;
	
	if(strcmp(cmd, "/", true) == 0)
		return 1;
	
	dcmd(loguj,5,cmdtext);
	dcmd(l,1,cmdtext);
	dcmd(rejestruj,9,cmdtext);
	if(gPlayerLogged[playerid])
	{		
		// For anti AFK purpose
		PlayerWrittingAnything[playerid] = 1;
		
		dcmd(specoff,7,cmdtext);
		dcmd(noooc,5,cmdtext);
		dcmd(owoj1,5,cmdtext);
		dcmd(owoj2,5,cmdtext);
		dcmd(zwoj2,5,cmdtext);
		dcmd(zslums,6,cmdtext);
		dcmd(oslums,6,cmdtext);
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
		dcmd(amechanicrepairpoint3,21,cmdtext);
		dcmd(amechanicpartspoint,19,cmdtext);
		dcmd(fixdamage,9,cmdtext);
		dcmd(resetpracy,10,cmdtext);
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
		dcmd(abizcmds,8,cmdtext);
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
		dcmd(sprawdzoc,9,cmdtext);
		dcmd(sprzedajpojazd,14,cmdtext);
		dcmd(anulujsprzedazpojazdu,21,cmdtext);
		dcmd(ulecz,5,cmdtext);
		dcmd(pozszywaj,9,cmdtext);
		dcmd(sprzedajpojazdf,15,cmdtext);
		dcmd(anulujsprzedazpojazduf,22,cmdtext);
		dcmd(statusfrakcji,13,cmdtext);
		dcmd(abizaddtill,11,cmdtext);
		dcmd(abiztill,8,cmdtext);
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
		dcmd(additem,7,cmdtext);
		dcmd(rmplayeritem,12,cmdtext);
		dcmd(vipitem,7,cmdtext);
		dcmd(playeritems,11,cmdtext);
		dcmd(aservercmds,11,cmdtext);
		dcmd(savebiz,7,cmdtext);
		dcmd(afillbiztable,13,cmdtext);
		dcmd(afillhousetable,15,cmdtext);
		dcmd(housesource,11,cmdtext);
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
		dcmd(unban,5,cmdtext);
		dcmd(opisdomu,8,cmdtext);
		dcmd(asellerjobpos,13,cmdtext);
		dcmd(aaccountantjobpos,17,cmdtext);
		dcmd(ww,2,cmdtext);
		dcmd(zmienrejestracje,16,cmdtext);
		dcmd(wejdznaskocznie,15,cmdtext);
		dcmd(stanpojazdu,11,cmdtext);
		dcmd(apjob,5,cmdtext);
		dcmd(przedstawrozliczenie,20,cmdtext);
		dcmd(vehdamage,9,cmdtext);
		dcmd(explodencars,12,cmdtext);
		dcmd(wymianaopon,11,cmdtext);
		dcmd(additemex,9,cmdtext);
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
		dcmd(vehfueltype,11,cmdtext);
		dcmd(montazgazu,10,cmdtext);
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
		dcmd(animacje2,9,cmdtext);
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
		dcmd(resetcamera,11,cmdtext);
		dcmd(setcamerapos,12,cmdtext);
		dcmd(setcameralookat,15,cmdtext);
		dcmd(quat,4,cmdtext);
		dcmd(danepojazdu,11,cmdtext);
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
		dcmd(doczepobiekt,12,cmdtext);
		dcmd(onoffobiektpoj,14,cmdtext);
		dcmd(ustawobiektpoj,14,cmdtext);
		dcmd(obrocobiektpoj,14,cmdtext);
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
		dcmd(onofftraset,11,cmdtext);
		dcmd(onofftrases,11,cmdtext);
		dcmd(onofftrasef,11,cmdtext);
		dcmd(ustawcpb,8,cmdtext);
		dcmd(ustawcpt,8,cmdtext);
		dcmd(ustawcps,8,cmdtext);
		dcmd(ustawcpf,8,cmdtext);		
		dcmd(fillbustracks,13,cmdtext);
		dcmd(filltrashtracks,15,cmdtext);
		dcmd(fillsweepertracks,17,cmdtext);
		dcmd(fillfarmertracks,16,cmdtext);
		dcmd(trasybon,8,cmdtext);
		dcmd(trasyton,8,cmdtext);
		dcmd(trasyson,8,cmdtext);
		dcmd(trasyfon,8,cmdtext);
		dcmd(vehtypelist,11,cmdtext);
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
		dcmd(mojeitemywpojezdzie,19,cmdtext);
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
		dcmd(itemfactoryreproducecount,25,cmdtext);
		dcmd(itemfactoryprice,16,cmdtext);
		dcmd(fly,3,cmdtext);
		dcmd(rtc,3,cmdtext);
		dcmd(getip,5,cmdtext);
		dcmd(krzycz,6,cmdtext);
		dcmd(k,1,cmdtext);
		dcmd(testdriveareaentrancepos,24,cmdtext);
		dcmd(testdriveareaexitpos,20,cmdtext);
		dcmd(testdriveareabuypos,19,cmdtext);
		dcmd(testdriveprice,14,cmdtext);
		dcmd(rozpocznijtest,14,cmdtext);
		dcmd(showq,5,cmdtext);
		dcmd(testdrivebuypos,15,cmdtext);
		dcmd(egzaminnaprawko,15,cmdtext);
		dcmd(ustawpacholki,13,cmdtext);
		dcmd(testdrivelowprice,17,cmdtext);
		dcmd(kanalooc,8,cmdtext);
		dcmd(wykupdostepdoplacu,18,cmdtext);
		dcmd(testdriveareabuyprice,21,cmdtext);
		dcmd(testdriveareabuytime,20,cmdtext);
		dcmd(wyrobdowod,10,cmdtext);
		dcmd(wyrobprawojazdy,15,cmdtext);
		dcmd(punktykarne,11,cmdtext);
		dcmd(cb,2,cmdtext);
		dcmd(cbv,3,cmdtext);
		dcmd(kanalcb,7,cmdtext);
		dcmd(onoffcb,7,cmdtext);
		dcmd(wymontujcb,10,cmdtext);
		dcmd(onoff,5,cmdtext);
		dcmd(panelgracza,11,cmdtext);
		dcmd(hstatus,7,cmdtext);
		dcmd(setplayerdrunk,14,cmdtext);
		dcmd(admissionchamberpos,19,cmdtext);
		dcmd(przebadajpacjenta,17,cmdtext);
		dcmd(govbiz,6,cmdtext);
		dcmd(wplacdobiznesu,14,cmdtext);
		dcmd(ahouseconfiscated,17,cmdtext);
		dcmd(wyposazeniepojazdu,18,cmdtext);
		dcmd(kp,2,cmdtext);
		dcmd(komputerpolicyjny,17,cmdtext);
		dcmd(afillcarsctable,15,cmdtext);
		dcmd(unmodcar,8,cmdtext);
		dcmd(savetune,8,cmdtext);
		dcmd(checkhp,7,cmdtext);
		dcmd(setpneon,8,cmdtext);
		dcmd(setpgarage,10,cmdtext);
		dcmd(gotoffactory,12,cmdtext);
		dcmd(paralizuj,9,cmdtext);
		dcmd(pa,2,cmdtext);
		dcmd(vehcb,5,cmdtext);
		dcmd(vehhook,7,cmdtext);
		dcmd(vehalarm,8,cmdtext);
		dcmd(osiagniecia,11,cmdtext);
		dcmd(osiagniecia2,12,cmdtext);
		dcmd(wyplata,7,cmdtext);
		dcmd(abizentrancefee,15,cmdtext);
		dcmd(abuildingicon,13,cmdtext);
		dcmd(abuildingiconshow,17,cmdtext);
		dcmd(sethealcost,11,cmdtext);
		dcmd(cenazaleczenie,14,cmdtext);
		dcmd(setexaminecost,14,cmdtext);
		dcmd(cenazabadanie,13,cmdtext);
		dcmd(zone1,5,cmdtext);
		dcmd(zone2,5,cmdtext);
		dcmd(zone,4,cmdtext);
		dcmd(dekonfiskata,12,cmdtext);
		dcmd(genbuid,7,cmdtext);
		dcmd(genhuid,7,cmdtext);
		dcmd(ktowynajmuje,12,cmdtext);
		dcmd(statystykibiznesu,17,cmdtext);
		dcmd(ahouseintex,11,cmdtext);
		dcmd(listawnetrz,11,cmdtext);
		dcmd(zgloszenia,10,cmdtext);
		dcmd(wnetrzedomu,11,cmdtext);
		dcmd(sieckomorkowa,13,cmdtext);
		dcmd(usunfirme,9,cmdtext);
		dcmd(globalsms,9,cmdtext);
		dcmd(odbierznagrode,14,cmdtext);
		dcmd(quiz,4,cmdtext);
		dcmd(resetallvehicles,16,cmdtext);
		dcmd(resetallhouses,14,cmdtext);
		dcmd(resetallbusinesses,18,cmdtext);
		dcmd(showterritories,15,cmdtext);
		dcmd(hideterritories,18,cmdtext);
		dcmd(terytoria,9,cmdtext);
		dcmd(wjedzdonaczepy,14,cmdtext);
		dcmd(wyjedzznaczepy,14,cmdtext);
		dcmd(gotofc,6,cmdtext);
		dcmd(okradnij,8,cmdtext);
		dcmd(okradnijzkasy,13,cmdtext);
		dcmd(wyrobdowodrejestracyjny,23,cmdtext);
		dcmd(wejdzdonaczepy,14,cmdtext);
		dcmd(wyjdzznaczepy,13,cmdtext);
		dcmd(pokazpunkteksportu,18,cmdtext);
		dcmd(ukryjpunkteksportu,18,cmdtext);
		dcmd(eksportujpojazd,15,cmdtext);
		dcmd(naprawstacyjke,14,cmdtext);
		dcmd(zdemontuj,9,cmdtext);
		dcmd(przeszukaj,10,cmdtext);
		dcmd(zamknij,7,cmdtext);
		dcmd(debugtextdraw,13,cmdtext);
		dcmd(afillracestable,15,cmdtext);
		dcmd(racestartpos,12,cmdtext);
		dcmd(raceinfopos,11,cmdtext);
		dcmd(racestartposcount,17,cmdtext);
		dcmd(racecppos,9,cmdtext);
		dcmd(racecmds,8,cmdtext);
		dcmd(racestatus,10,cmdtext);
		dcmd(menuwyscigu,11,cmdtext);
		dcmd(przerwijwyscig,14,cmdtext);
		dcmd(rozpocznijwyscig,16,cmdtext);
		dcmd(edytujobiekt,12,cmdtext);
		dcmd(wlamsiedodomu,13,cmdtext);
		dcmd(napisobj,8,cmdtext);
		dcmd(wlamsiedobiznesu,16,cmdtext);
		dcmd(okradnijbiznes,14,cmdtext);
		dcmd(okradnijdom,11,cmdtext);
		dcmd(zdemontujobiektzpoj,19,cmdtext);
		dcmd(objmaterial,11,cmdtext);
		dcmd(pilotpd,7,cmdtext);
		dcmd(showracecp,10,cmdtext);
		dcmd(pozycjaobiektupoj,17,cmdtext);
		dcmd(zbierzplony,11,cmdtext);
		dcmd(afillweedtable,14,cmdtext);
		dcmd(eventpos,8,cmdtext);
		dcmd(getplayerweather,16,cmdtext);
		dcmd(uprawnieniarangi,16,cmdtext);
		dcmd(zmienuprawnieniarangi,21,cmdtext);
		dcmd(oddajterytorium,15,cmdtext);
		dcmd(wyrzuczwyscigu,14,cmdtext);
		dcmd(wejdzdokampera,14,cmdtext);
		dcmd(wyjdzzkampera,13,cmdtext);
		dcmd(tod,3,cmdtext);
		dcmd(ogladaj,7,cmdtext);
		dcmd(przerwijogladanie,17,cmdtext);
		dcmd(komendybuchmacherskie,21,cmdtext);
		dcmd(obstawiaj,9,cmdtext);
		dcmd(mojezaklady,11,cmdtext);
		dcmd(zdejmijpancerz,14,cmdtext);
		dcmd(cenypaliw,9,cmdtext);
		dcmd(wezkredyt,9,cmdtext);
		dcmd(stankredytu,11,cmdtext);
		dcmd(splackredyt,11,cmdtext);
		dcmd(payoffgrant,11,cmdtext);
		dcmd(zglosproblem,12,cmdtext);
		dcmd(haslokp,7,cmdtext);
		dcmd(zac,3,cmdtext);
		dcmd(zaciagnij,9,cmdtext);
		dcmd(nonewbie,8,cmdtext);
		dcmd(n,1,cmdtext);
		dcmd(newbie,6,cmdtext);
		dcmd(setvehpos,9,cmdtext);
		dcmd(ustawwiadomosc,14,cmdtext);
		dcmd(wyczyscwiadomosc,16,cmdtext);
		
		// dcmd(a3dvehids,9,cmdtext);
		// dcmd(wyrzucitem,10,cmdtext);
		// dcmd(przekazitem,11,cmdtext);
		//dcmd(wezpilke,8,cmdtext);
		// dcmd(afk,3,cmdtext);
		// dcmd(lightfw,7,cmdtext);
		// dcmd(fwcp,4,cmdtext);
		// dcmd(ustawradio,10,cmdtext);
		// dcmd(nadajpunktykarne,16,cmdtext);
		// dcmd(wantedex,8,cmdtext);
		// dcmd(faq,3,cmdtext);	
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
		// dcmd(c3dtv,5,cmdtext);
		// dcmd(d3dt,4,cmdtext);
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
			RemovePlayerAttachedObject(playerid, 1);
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
		if(strcmp(cmd, "/schowajkomorke", true) == 0)
		{
			SetPlayerSpecialAction(playerid,SPECIAL_ACTION_STOPUSECELLPHONE);
			RemovePlayerAttachedObject(playerid, 1);
			return 1;
		}
		
		if(strcmp(cmd, "/animbar", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animbar [1-12]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 12) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animbar [1-12]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"BAR","Barcustom_get",4.1,0,1,1,1,1);
		} else if(animationplayed == 2) {
		ApplyAnimation(playerid,"BAR","Barcustom_loop",4.1,0,1,1,1,1);
		} else if(animationplayed == 3) {
		ApplyAnimation(playerid,"BAR","Barcustom_order",4.1,0,1,1,1,1);
		} else if(animationplayed == 4) {
		ApplyAnimation(playerid,"BAR","Barserve_bottle",4.1,0,1,1,1,1);
		} else if(animationplayed == 5) {
		ApplyAnimation(playerid,"BAR","Barserve_give",4.1,0,1,1,1,1);
		} else if(animationplayed == 6) {
		ApplyAnimation(playerid,"BAR","Barserve_glass",4.1,0,1,1,1,1);
		} else if(animationplayed == 7) {
		ApplyAnimation(playerid,"BAR","Barserve_in",4.1,0,1,1,1,1);
		} else if(animationplayed == 8) {
		ApplyAnimation(playerid,"BAR","Barserve_loop",4.1,0,1,1,1,1);
		} else if(animationplayed == 9) {
		ApplyAnimation(playerid,"BAR","Barserve_order",4.1,0,1,1,1,1);
		} else if(animationplayed == 10) {
		ApplyAnimation(playerid,"BAR","dnk_stndF_loop",4.1,0,1,1,1,1);
		} else if(animationplayed == 11) {
		ApplyAnimation(playerid,"BAR","dnk_stndM_loop",4.1,0,1,1,1,1);
		} else if(animationplayed == 12) {
		ApplyAnimation(playerid,"BAR","BARman_idle",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animball", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animball [1-11]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 11) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animball [1-11]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"BASEBALL","Bat_1",4.1,0,1,1,1,1);
		} else if(animationplayed == 2) {
		ApplyAnimation(playerid,"BASEBALL","Bat_2",4.1,0,1,1,1,1);
		} else if(animationplayed == 3) {
		ApplyAnimation(playerid,"BASEBALL","Bat_2",4.1,0,1,1,1,1);
		} else if(animationplayed == 4) {
		ApplyAnimation(playerid,"BASEBALL","Bat_4",4.1,0,1,1,1,1);
		} else if(animationplayed == 5) {
		ApplyAnimation(playerid,"BASEBALL","Bat_block",4.1,0,1,1,1,1);
		} else if(animationplayed == 6) {
		ApplyAnimation(playerid,"BASEBALL","Bat_Hit_1",4.1,0,1,1,1,1);
		} else if(animationplayed == 7) {
		ApplyAnimation(playerid,"BASEBALL","Bat_Hit_2",4.1,0,1,1,1,1);
		} else if(animationplayed == 8) {
		ApplyAnimation(playerid,"BASEBALL","Bat_Hit_3",4.1,0,1,1,1,1);
		} else if(animationplayed == 9) {
		ApplyAnimation(playerid,"BASEBALL","Bat_IDLE",4.1,0,1,1,1,1);
		} else if(animationplayed == 10) {
		ApplyAnimation(playerid,"BASEBALL","Bat_M",4.1,0,1,1,1,1);
		} else if(animationplayed == 11) {
		ApplyAnimation(playerid,"BASEBALL","BAT_PART",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animfire", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animfire [1-13]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 13) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animfire [1-13]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"BD_FIRE","BD_Fire1",4.1,0,1,1,1,1);
		} else if(animationplayed == 2) {
		ApplyAnimation(playerid,"BD_FIRE","BD_Fire2",4.1,0,1,1,1,1);
		} else if(animationplayed == 3) {
		ApplyAnimation(playerid,"BD_FIRE","BD_Fire3",4.1,0,1,1,1,1);
		} else if(animationplayed == 4) {
		ApplyAnimation(playerid,"BD_FIRE","BD_GF_Wave",4.1,0,1,1,1,1);
		} else if(animationplayed == 5) {
		ApplyAnimation(playerid,"BD_FIRE","BD_Panic_01",4.1,0,1,1,1,1);
		} else if(animationplayed == 6) {
		ApplyAnimation(playerid,"BD_FIRE","BD_Panic_02",4.1,0,1,1,1,1);
		} else if(animationplayed == 7) {
		ApplyAnimation(playerid,"BD_FIRE","BD_Panic_03",4.1,0,1,1,1,1);
		} else if(animationplayed == 8) {
		ApplyAnimation(playerid,"BD_FIRE","BD_Panic_04",4.1,0,1,1,1,1);
		} else if(animationplayed == 9) {
		ApplyAnimation(playerid,"BD_FIRE","BD_Panic_Loop",4.1,0,1,1,1,1);
		} else if(animationplayed == 10) {
		ApplyAnimation(playerid,"BD_FIRE","M_smklean_loop",4.1,0,1,1,1,1);
		} else if(animationplayed == 11) {
		ApplyAnimation(playerid,"BD_FIRE","M_smklean_loop",4.1,0,1,1,1,1);
		} else if(animationplayed == 12) {
		ApplyAnimation(playerid,"BD_FIRE","Playa_Kiss_03",4.1,0,1,1,1,1);
		} else if(animationplayed == 13) {
		ApplyAnimation(playerid,"BD_FIRE","wash_up",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animbeach", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animbeach [1-5]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 5) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animbeach [1-5]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"BEACH","bather",4.1,0,1,1,1,1);
		} else if(animationplayed == 2) {
		ApplyAnimation(playerid,"BEACH","Lay_Bac_Loop",4.1,0,1,1,1,1);
		} else if(animationplayed == 3) {
		ApplyAnimation(playerid,"BEACH","BD_Fire3",4.1,0,1,1,1,1);
		} else if(animationplayed == 4) {
		ApplyAnimation(playerid,"BEACH","ParkSit_W_loop",4.1,0,1,1,1,1);
		} else if(animationplayed == 5) {
		ApplyAnimation(playerid,"BEACH","SitnWait_loop_W",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animinf", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animinf [1-4]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 4) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animinf [1-4]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"BF_injection","BF_getin_LHS",4.1,0,1,1,1,1);
		} else if(animationplayed == 2) {
		ApplyAnimation(playerid,"BF_injection","BF_getin_RHS",4.1,0,1,1,1,1);
		} else if(animationplayed == 3) {
		ApplyAnimation(playerid,"BF_injection","BF_getout_LHS",4.1,0,1,1,1,1);
		} else if(animationplayed == 4) {
		ApplyAnimation(playerid,"BF_injection","BF_getout_RHS",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animbiked", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animbiked [1-18]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 18) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animbiked [1-18]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"BIKED","BIKEd_Back",4.1,0,1,1,1,1);
		}else if(animationplayed == 1) {
		ApplyAnimation(playerid,"BIKED","BIKEd_drivebyFT",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"BIKED","BIKEd_drivebyLHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"BIKED","BIKEd_drivebyRHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"BIKED","BIKEd_Fwd",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"BIKED","BIKEd_getoffBACK",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"BIKED","BIKEd_getoffLHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"BIKED","BIKEd_getoffRHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 8) {
		ApplyAnimation(playerid,"BIKED","BIKEd_hit",4.1,0,1,1,1,1);
		}else if(animationplayed == 9) {
		ApplyAnimation(playerid,"BIKED","BIKEd_jumponL",4.1,0,1,1,1,1);
		}else if(animationplayed == 10) {
		ApplyAnimation(playerid,"BIKED","BIKEd_jumponR",4.1,0,1,1,1,1);
		}else if(animationplayed == 11) {
		ApplyAnimation(playerid,"BIKED","BIKEd_kick",4.1,0,1,1,1,1);
		}else if(animationplayed == 12) {
		ApplyAnimation(playerid,"BIKED","BIKEd_Left",4.1,0,1,1,1,1);
		}else if(animationplayed == 13) {
		ApplyAnimation(playerid,"BIKED","BIKEd_passenger",4.1,0,1,1,1,1);
		}else if(animationplayed == 14) {
		ApplyAnimation(playerid,"BIKED","BIKEd_pushes",4.1,0,1,1,1,1);
		}else if(animationplayed == 15) {
		ApplyAnimation(playerid,"BIKED","BIKEd_Ride",4.1,0,1,1,1,1);
		}else if(animationplayed == 16) {
		ApplyAnimation(playerid,"BIKED","BIKEd_Right",4.1,0,1,1,1,1);
		}else if(animationplayed == 17) {
		ApplyAnimation(playerid,"BIKED","BIKEd_shuffle",4.1,0,1,1,1,1);
		}else if(animationplayed == 18) {
		ApplyAnimation(playerid,"BIKED","BIKEd_Still",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animbp", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animbp [1-7]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 7) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animbp [1-7]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"benchpress","gym_bp_celebrate",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"benchpress","gym_bp_down",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"benchpress","gym_bp_getoff",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"benchpress","gym_bp_geton",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"benchpress","gym_bp_up_A",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"benchpress","gym_bp_up_B",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"benchpress","gym_bp_up_smooth",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animbh", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animbh [1-18]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 18) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animbh [1-18]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"BIKEH","BIKEh_Back",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"BIKEH","BIKEh_drivebyFT",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"BIKEH","BIKEh_drivebyLHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"BIKEH","BIKEh_drivebyRHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"BIKEH","BIKEh_Fwd",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"BIKEH","BIKEh_getoffBACK",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"BIKEH","BIKEh_getoffLHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 8) {
		ApplyAnimation(playerid,"BIKEH","BIKEh_getoffRHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 9) {
		ApplyAnimation(playerid,"BIKEH","BIKEh_hit",4.1,0,1,1,1,1);
		}else if(animationplayed == 10) {
		ApplyAnimation(playerid,"BIKEH","BIKEh_jumponL",4.1,0,1,1,1,1);
		}else if(animationplayed == 11) {
		ApplyAnimation(playerid,"BIKEH","BIKEh_jumponR",4.1,0,1,1,1,1);
		}else if(animationplayed == 12) {
		ApplyAnimation(playerid,"BIKEH","BIKEh_kick",4.1,0,1,1,1,1);
		}else if(animationplayed == 13) {
		ApplyAnimation(playerid,"BIKEH","BIKEh_Left",4.1,0,1,1,1,1);
		}else if(animationplayed == 14) {
		ApplyAnimation(playerid,"BIKEH","BIKEh_passenger",4.1,0,1,1,1,1);
		}else if(animationplayed == 15) {
		ApplyAnimation(playerid,"BIKEH","BIKEh_pushes",4.1,0,1,1,1,1);
		}else if(animationplayed == 16) {
		ApplyAnimation(playerid,"BIKEH","BIKEh_Ride",4.1,0,1,1,1,1);
		}else if(animationplayed == 17) {
		ApplyAnimation(playerid,"BIKEH","BIKEh_Right",4.1,0,1,1,1,1);
		}else if(animationplayed == 18) {
		ApplyAnimation(playerid,"BIKEH","BIKEh_Still",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animms", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animms [1-8]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 8) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animms [1-8]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"BIKEH","BIKEh_Back",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"BIKEH","BIKEh_drivebyFT",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"BIKEH","BIKEh_drivebyLHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"BIKEH","BIKEh_drivebyRHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"BIKEH","BIKEh_Fwd",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"BIKEH","BIKEh_getoffBACK",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"BIKEH","BIKEh_getoffLHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 8) {
		ApplyAnimation(playerid,"BIKEH","BIKEh_getoffRHS",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animfood", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animfood [1-33]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 33) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animfood [1-33]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"FOOD","EAT_Burger",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"FOOD","EAT_Chicken",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"FOOD","EAT_Pizza",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"FOOD","EAT_Vomit_P",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"FOOD","EAT_Vomit_SK",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"FOOD","FF_Dam_Bkw",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"FOOD","FF_Dam_Fwd",4.1,0,1,1,1,1);
		}else if(animationplayed == 8) {
		ApplyAnimation(playerid,"FOOD","FF_Dam_Left",4.1,0,1,1,1,1);
		}else if(animationplayed == 9) {
		ApplyAnimation(playerid,"FOOD","FF_Dam_Right",4.1,0,1,1,1,1);
		}else if(animationplayed == 10) {
		ApplyAnimation(playerid,"FOOD","FF_Die_Bkw",4.1,0,1,1,1,1);
		}else if(animationplayed == 11) {
		ApplyAnimation(playerid,"FOOD","FF_Die_Fwd",4.1,0,1,1,1,1);
		}else if(animationplayed == 12) {
		ApplyAnimation(playerid,"FOOD","FF_Die_Left",4.1,0,1,1,1,1);
		}else if(animationplayed == 13) {
		ApplyAnimation(playerid,"FOOD","FF_Die_Right",4.1,0,1,1,1,1);
		}else if(animationplayed == 14) {
		ApplyAnimation(playerid,"FOOD","FF_Sit_Eat1",4.1,0,1,1,1,1);
		}else if(animationplayed == 15) {
		ApplyAnimation(playerid,"FOOD","FF_Sit_Eat2",4.1,0,1,1,1,1);
		}else if(animationplayed == 16) {
		ApplyAnimation(playerid,"FOOD","FF_Sit_Eat3",4.1,0,1,1,1,1);
		}else if(animationplayed == 17) {
		ApplyAnimation(playerid,"FOOD","FF_Sit_In",4.1,0,1,1,1,1);
		}else if(animationplayed == 18) {
		ApplyAnimation(playerid,"FOOD","FF_Sit_In_L",4.1,0,1,1,1,1);
		}else if(animationplayed == 19) {
		ApplyAnimation(playerid,"FOOD","FF_Sit_In_R",4.1,0,1,1,1,1);
		}else if(animationplayed == 20) {
		ApplyAnimation(playerid,"FOOD","FF_Sit_Look",4.1,0,1,1,1,1);
		}else if(animationplayed == 21) {
		ApplyAnimation(playerid,"FOOD","FF_Sit_Loop",4.1,0,1,1,1,1);
		}else if(animationplayed == 22) {
		ApplyAnimation(playerid,"FOOD","FF_Sit_Out_180",4.1,0,1,1,1,1);
		}else if(animationplayed == 23) {
		ApplyAnimation(playerid,"FOOD","FF_Sit_Out_L_180",4.1,0,1,1,1,1);
		}else if(animationplayed == 24) {
		ApplyAnimation(playerid,"FOOD","FF_Sit_Out_R_180",4.1,0,1,1,1,1);
		}else if(animationplayed == 25) {
		ApplyAnimation(playerid,"FOOD","SHP_Thank",4.1,0,1,1,1,1);
		}else if(animationplayed == 26) {
		ApplyAnimation(playerid,"FOOD","SHP_Tray_In",4.1,0,1,1,1,1);
		}else if(animationplayed == 27) {
		ApplyAnimation(playerid,"FOOD","SHP_Tray_Lift",4.1,0,1,1,1,1);
		}else if(animationplayed == 28) {
		ApplyAnimation(playerid,"FOOD","SHP_Tray_Lift_In",4.1,0,1,1,1,1);
		}else if(animationplayed == 29) {
		ApplyAnimation(playerid,"FOOD","SHP_Tray_Lift_Loop",4.1,0,1,1,1,1);
		}else if(animationplayed == 30) {
		ApplyAnimation(playerid,"FOOD","SHP_Tray_Lift_Out",4.1,0,1,1,1,1);
		}else if(animationplayed == 31) {
		ApplyAnimation(playerid,"FOOD","SHP_Tray_Out",4.1,0,1,1,1,1);
		}else if(animationplayed == 32) {
		ApplyAnimation(playerid,"FOOD","SHP_Tray_Pose",4.1,0,1,1,1,1);
		}else if(animationplayed == 33) {
		ApplyAnimation(playerid,"FOOD","SHP_Tray_Return",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animms", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animms [1-41]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 41) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animms [1-41]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"MISC","bitchslap",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"MISC","BMX_celebrate",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"MISC","BMX_comeon",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"MISC","bmx_idleloop_01",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"MISC","bmx_idleloop_02",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"MISC","bmx_talkleft_in",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"MISC","bmx_talkleft_loop",4.1,0,1,1,1,1);
		}else if(animationplayed == 8) {
		ApplyAnimation(playerid,"MISC","bmx_talkleft_out",4.1,0,1,1,1,1);
		}else if(animationplayed == 9) {
		ApplyAnimation(playerid,"MISC","bmx_talkright_in",4.1,0,1,1,1,1);
		}else if(animationplayed == 10) {
		ApplyAnimation(playerid,"MISC","bmx_talkright_loop",4.1,0,1,1,1,1);
		}else if(animationplayed == 11) {
		ApplyAnimation(playerid,"MISC","bmx_talkright_out",4.1,0,1,1,1,1);
		}else if(animationplayed == 12) {
		ApplyAnimation(playerid,"MISC","bng_wndw",4.1,0,1,1,1,1);
		}else if(animationplayed == 13) {
		ApplyAnimation(playerid,"MISC","bng_wndw_02",4.1,0,1,1,1,1);
		}else if(animationplayed == 14) {
		ApplyAnimation(playerid,"MISC","Case_pickup",4.1,0,1,1,1,1);
		}else if(animationplayed == 15) {
		ApplyAnimation(playerid,"MISC","door_jet",4.1,0,1,1,1,1);
		}else if(animationplayed == 16) {
		ApplyAnimation(playerid,"MISC","GRAB_L",4.1,0,1,1,1,1);
		}else if(animationplayed == 17) {
		ApplyAnimation(playerid,"MISC","GRAB_R",4.1,0,1,1,1,1);
		}else if(animationplayed == 18) {
		ApplyAnimation(playerid,"MISC","Hiker_Pose",4.1,0,1,1,1,1);
		}else if(animationplayed == 19) {
		ApplyAnimation(playerid,"MISC","Hiker_Pose_L",4.1,0,1,1,1,1);
		}else if(animationplayed == 20) {
		ApplyAnimation(playerid,"MISC","Idle_Chat_02",4.1,0,1,1,1,1);
		}else if(animationplayed == 21) {
		ApplyAnimation(playerid,"MISC","KAT_Throw_K",4.1,0,1,1,1,1);
		}else if(animationplayed == 22) {
		ApplyAnimation(playerid,"MISC","KAT_Throw_O",4.1,0,1,1,1,1);
		}else if(animationplayed == 23) {
		ApplyAnimation(playerid,"MISC","KAT_Throw_P",4.1,0,1,1,1,1);
		}else if(animationplayed == 24) {
		ApplyAnimation(playerid,"MISC","PASS_Rifle_O",4.1,0,1,1,1,1);
		}else if(animationplayed == 25) {
		ApplyAnimation(playerid,"MISC","PASS_Rifle_Ped",4.1,0,1,1,1,1);
		}else if(animationplayed == 26) {
		ApplyAnimation(playerid,"MISC","PASS_Rifle_Ply",4.1,0,1,1,1,1);
		}else if(animationplayed == 27) {
		ApplyAnimation(playerid,"MISC","pickup_box",4.1,0,1,1,1,1);
		}else if(animationplayed == 28) {
		ApplyAnimation(playerid,"MISC","Plane_door",4.1,0,1,1,1,1);
		}else if(animationplayed == 29) {
		ApplyAnimation(playerid,"MISC","Plane_exit",4.1,0,1,1,1,1);
		}else if(animationplayed == 30) {
		ApplyAnimation(playerid,"MISC","Plane_hijack",4.1,0,1,1,1,1);
		}else if(animationplayed == 31) {
		ApplyAnimation(playerid,"MISC","Plunger_01",4.1,0,1,1,1,1);
		}else if(animationplayed == 32) {
		ApplyAnimation(playerid,"MISC","Plyrlean_loop",4.1,0,1,1,1,1);
		}else if(animationplayed == 33) {
		ApplyAnimation(playerid,"MISC","plyr_shkhead",4.1,0,1,1,1,1);
		}else if(animationplayed == 34) {
		ApplyAnimation(playerid,"MISC","Run_Dive",4.1,0,1,1,1,1);
		}else if(animationplayed == 35) {
		ApplyAnimation(playerid,"MISC","Scratchballs_01",4.1,0,1,1,1,1);
		}else if(animationplayed == 36) {
		ApplyAnimation(playerid,"MISC","SEAT_LR",4.1,0,1,1,1,1);
		}else if(animationplayed == 37) {
		ApplyAnimation(playerid,"MISC","Seat_talk_01",4.1,0,1,1,1,1);
		}else if(animationplayed == 38) {
		ApplyAnimation(playerid,"MISC","Seat_talk_02",4.1,0,1,1,1,1);
		}else if(animationplayed == 39) {
		ApplyAnimation(playerid,"MISC","SEAT_watch",4.1,0,1,1,1,1);
		}else if(animationplayed == 40) {
		ApplyAnimation(playerid,"MISC","smalplane_door",4.1,0,1,1,1,1);
		}else if(animationplayed == 41) {
		ApplyAnimation(playerid,"MISC","smlplane_door",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animbikelp", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animbikelp [1-9]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 9) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animbikelp [1-9]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"BIKELEAP","bk_blnce_in",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"BIKELEAP","bk_blnce_out",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"BIKELEAP","bk_jmp",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"BIKELEAP","bk_rdy_in",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"BIKELEAP","bk_rdy_out",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"BIKELEAP","struggle_cesar",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"BIKELEAP","struggle_driver",4.1,0,1,1,1,1);
		}else if(animationplayed == 8) {
		ApplyAnimation(playerid,"BIKELEAP","truck_driver",4.1,0,1,1,1,1);
		}else if(animationplayed == 9) {
		ApplyAnimation(playerid,"BIKELEAP","truck_getin",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animbikes", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animbikes [1-18]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 18) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animbikes [1-18]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"BIKES","BIKEs_Back",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"BIKES","BIKEs_drivebyFT",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"BIKES","BIKEs_drivebyLHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"BIKES","BIKEs_drivebyRHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"BIKES","BIKEs_Fwd",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"BIKES","BIKEs_getoffBACK",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"BIKES","BIKEs_getoffLHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 8) {
		ApplyAnimation(playerid,"BIKES","BIKEs_getoffRHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 9) {
		ApplyAnimation(playerid,"BIKES","BIKEs_hit",4.1,0,1,1,1,1);
		}else if(animationplayed == 10) {
		ApplyAnimation(playerid,"BIKES","BIKEs_jumponL",4.1,0,1,1,1,1);
		}else if(animationplayed == 11) {
		ApplyAnimation(playerid,"BIKES","BIKEs_jumponR",4.1,0,1,1,1,1);
		}else if(animationplayed == 12) {
		ApplyAnimation(playerid,"BIKES","BIKEs_kick",4.1,0,1,1,1,1);
		}else if(animationplayed == 13) {
		ApplyAnimation(playerid,"BIKES","BIKEs_Left",4.1,0,1,1,1,1);
		}else if(animationplayed == 14) {
		ApplyAnimation(playerid,"BIKES","BIKEs_passenger",4.1,0,1,1,1,1);
		}else if(animationplayed == 15) {
		ApplyAnimation(playerid,"BIKES","BIKEs_pushes",4.1,0,1,1,1,1);
		}else if(animationplayed == 16) {
		ApplyAnimation(playerid,"BIKES","BIKEs_Ride",4.1,0,1,1,1,1);
		}else if(animationplayed == 17) {
		ApplyAnimation(playerid,"BIKES","BIKEs_Right",4.1,0,1,1,1,1);
		}else if(animationplayed == 18) {
		ApplyAnimation(playerid,"BIKES","BIKEs_Still",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animbikev", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animbikev [1-18]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 18) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animbikev [1-18]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"BIKEV","BIKEv_Back",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"BIKEV","BIKEv_drivebyFT",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"BIKEV","BIKEv_drivebyLHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"BIKEV","BIKEv_drivebyRHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"BIKEV","BIKEv_Fwd",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"BIKEV","BIKEv_getoffBACK",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"BIKEV","BIKEv_getoffLHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 8) {
		ApplyAnimation(playerid,"BIKEV","BIKEv_getoffRHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 9) {
		ApplyAnimation(playerid,"BIKEV","BIKEv_hit",4.1,0,1,1,1,1);
		}else if(animationplayed == 10) {
		ApplyAnimation(playerid,"BIKEV","BIKEv_jumponL",4.1,0,1,1,1,1);
		}else if(animationplayed == 11) {
		ApplyAnimation(playerid,"BIKEV","BIKEv_jumponR",4.1,0,1,1,1,1);
		}else if(animationplayed == 12) {
		ApplyAnimation(playerid,"BIKEV","BIKEv_kick",4.1,0,1,1,1,1);
		}else if(animationplayed == 13) {
		ApplyAnimation(playerid,"BIKEV","BIKEv_Left",4.1,0,1,1,1,1);
		}else if(animationplayed == 14) {
		ApplyAnimation(playerid,"BIKEV","BIKEv_passenger",4.1,0,1,1,1,1);
		}else if(animationplayed == 15) {
		ApplyAnimation(playerid,"BIKEV","BIKEv_pushes",4.1,0,1,1,1,1);
		}else if(animationplayed == 16) {
		ApplyAnimation(playerid,"BIKEV","BIKEv_Ride",4.1,0,1,1,1,1);
		}else if(animationplayed == 17) {
		ApplyAnimation(playerid,"BIKEV","BIKEv_Right",4.1,0,1,1,1,1);
		}else if(animationplayed == 18) {
		ApplyAnimation(playerid,"BIKEV","BIKEv_Still",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animbmx", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animbmx [1-18]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 18) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animbmx [1-18]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"BMX","BMX_back",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"BMX","BMX_bunnyhop",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"BMX","BMX_drivebyFT",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"BMX","BMX_driveby_LHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"BMX","BMX_driveby_RHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"BMX","BMX_fwd",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"BMX","BMX_getoffBACK",4.1,0,1,1,1,1);
		}else if(animationplayed == 8) {
		ApplyAnimation(playerid,"BMX","BMX_pushes",4.1,0,1,1,1,1);
		}else if(animationplayed == 9) {
		ApplyAnimation(playerid,"BMX","BMX_getoffLHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 10) {
		ApplyAnimation(playerid,"BMX","BMX_getoffRHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 11) {
		ApplyAnimation(playerid,"BMX","BMX_jumponL",4.1,0,1,1,1,1);
		}else if(animationplayed == 12) {
		ApplyAnimation(playerid,"BMX","BMX_jumponR",4.1,0,1,1,1,1);
		}else if(animationplayed == 13) {
		ApplyAnimation(playerid,"BMX","BMX_Left",4.1,0,1,1,1,1);
		}else if(animationplayed == 14) {
		ApplyAnimation(playerid,"BMX","BMX_pedal",4.1,0,1,1,1,1);
		}else if(animationplayed == 15) {
		ApplyAnimation(playerid,"BMX","BMX_Ride",4.1,0,1,1,1,1);
		}else if(animationplayed == 16) {
		ApplyAnimation(playerid,"BMX","BMX_Right",4.1,0,1,1,1,1);
		}else if(animationplayed == 17) {
		ApplyAnimation(playerid,"BMX","BMX_sprint",4.1,0,1,1,1,1);
		}else if(animationplayed == 18) {
		ApplyAnimation(playerid,"BMX","BMX_still",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animbikedbz", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animbikedbz [1-4]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 4) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animbikedbz [1-4]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"BIKE_DBZ","Pass_Driveby_BWD",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"BIKE_DBZ","Pass_Driveby_FWD",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"BIKE_DBZ","Pass_Driveby_LHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"BIKE_DBZ","Pass_Driveby_RHS",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animchase", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animchase [1-25]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 25) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animchase [1-25]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"MD_CHASE","Carhit_Hangon",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"MD_CHASE","Carhit_Tumble",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"MD_CHASE","donutdrop",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"MD_CHASE","Fen_Choppa_L1",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"MD_CHASE","Fen_Choppa_L2",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"MD_CHASE","Fen_Choppa_L3",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"MD_CHASE","Fen_Choppa_R1",4.1,0,1,1,1,1);
		}else if(animationplayed == 8) {
		ApplyAnimation(playerid,"MD_CHASE","Fen_Choppa_R2",4.1,0,1,1,1,1);
		}else if(animationplayed == 9) {
		ApplyAnimation(playerid,"MD_CHASE","Fen_Choppa_R3",4.1,0,1,1,1,1);
		}else if(animationplayed == 10) {
		ApplyAnimation(playerid,"MD_CHASE","Hangon_Stun_loop",4.1,0,1,1,1,1);
		}else if(animationplayed == 11) {
		ApplyAnimation(playerid,"MD_CHASE","Hangon_Stun_Turn",4.1,0,1,1,1,1);
		}else if(animationplayed == 12) {
		ApplyAnimation(playerid,"MD_CHASE","MD_BIKE_2_HANG",4.1,0,1,1,1,1);
		}else if(animationplayed == 13) {
		ApplyAnimation(playerid,"MD_CHASE","MD_BIKE_Jmp_BL",4.1,0,1,1,1,1);
		}else if(animationplayed == 14) {
		ApplyAnimation(playerid,"MD_CHASE","MD_BIKE_Jmp_F",4.1,0,1,1,1,1);
		}else if(animationplayed == 15) {
		ApplyAnimation(playerid,"MD_CHASE","MD_BIKE_Lnd_BL",4.1,0,1,1,1,1);
		}else if(animationplayed == 16) {
		ApplyAnimation(playerid,"MD_CHASE","MD_BIKE_Lnd_Die_BL",4.1,0,1,1,1,1);
		}else if(animationplayed == 17) {
		ApplyAnimation(playerid,"MD_CHASE","MD_BIKE_Lnd_Die_F",4.1,0,1,1,1,1);
		}else if(animationplayed == 18) {
		ApplyAnimation(playerid,"MD_CHASE","MD_BIKE_Lnd_F",4.1,0,1,1,1,1);
		}else if(animationplayed == 19) {
		ApplyAnimation(playerid,"MD_CHASE","MD_BIKE_Lnd_Roll",4.1,0,1,1,1,1);
		}else if(animationplayed == 20) {
		ApplyAnimation(playerid,"MD_CHASE","MD_BIKE_Lnd_Roll_F",4.1,0,1,1,1,1);
		}else if(animationplayed == 21) {
		ApplyAnimation(playerid,"MD_CHASE","MD_BIKE_Punch",4.1,0,1,1,1,1);
		}else if(animationplayed == 22) {
		ApplyAnimation(playerid,"MD_CHASE","MD_BIKE_Punch_F",4.1,0,1,1,1,1);
		}else if(animationplayed == 23) {
		ApplyAnimation(playerid,"MD_CHASE","MD_BIKE_Shot_F",4.1,0,1,1,1,1);
		}else if(animationplayed == 24) {
		ApplyAnimation(playerid,"MD_CHASE","MD_HANG_Lnd_Roll",4.1,0,1,1,1,1);
		}else if(animationplayed == 25) {
		ApplyAnimation(playerid,"MD_CHASE","MD_HANG_Loop",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animbox", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animbox [1-10]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 10) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animbox [1-10]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"BOX","boxhipin",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"BOX","boxhipup",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"BOX","boxshdwn",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"BOX","boxshup",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"BOX","bxhipwlk",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"BOX","bxhwlki",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"BOX","bxshwlk",4.1,0,1,1,1,1);
		}else if(animationplayed == 8) {
		ApplyAnimation(playerid,"BOX","bxshwlki",4.1,0,1,1,1,1);
		}else if(animationplayed == 9) {
		ApplyAnimation(playerid,"BOX","bxwlko",4.1,0,1,1,1,1);
		}else if(animationplayed == 10) {
		ApplyAnimation(playerid,"BOX","catch_box",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animbomber", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animbomber [1-6]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 6) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animbomber [1-6]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"BOMBER","BOM_Plant",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"BOMBER","BOM_Plant_2Idle",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"BOMBER","BOM_Plant_Crouch_In",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"BOMBER","BOM_Plant_Crouch_Out",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"BOMBER","BOM_Plant_In",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"BOMBER","BOM_Plant_Loop",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animbsp", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animbsp [1-41]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 41) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animbsp [1-41]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"BSKTBALL","BBALL_def_jump_shot",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"BSKTBALL","BBALL_def_loop",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"BSKTBALL","BBALL_def_stepL",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"BSKTBALL","BBALL_def_stepR",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"BSKTBALL","BBALL_Dnk",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"BSKTBALL","BBALL_Dnk_Gli",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"BSKTBALL","BBALL_Dnk_Gli_O",4.1,0,1,1,1,1);
		}else if(animationplayed == 8) {
		ApplyAnimation(playerid,"BSKTBALL","BBALL_Dnk_Lnch",4.1,0,1,1,1,1);
		}else if(animationplayed == 9) {
		ApplyAnimation(playerid,"BSKTBALL","BBALL_Dnk_Lnch_O",4.1,0,1,1,1,1);
		}else if(animationplayed == 10) {
		ApplyAnimation(playerid,"BSKTBALL","BBALL_Dnk_Lnd",4.1,0,1,1,1,1);
		}else if(animationplayed == 11) {
		ApplyAnimation(playerid,"BSKTBALL","BBALL_Dnk_O",4.1,0,1,1,1,1);
		}else if(animationplayed == 12) {
		ApplyAnimation(playerid,"BSKTBALL","BBALL_idle",4.1,0,1,1,1,1);
		}else if(animationplayed == 13) {
		ApplyAnimation(playerid,"BSKTBALL","BBALL_idle2",4.1,0,1,1,1,1);
		}else if(animationplayed == 14) {
		ApplyAnimation(playerid,"BSKTBALL","BBALL_idle2_O",4.1,0,1,1,1,1);
		}else if(animationplayed == 15) {
		ApplyAnimation(playerid,"BSKTBALL","BBALL_idleloop",4.1,0,1,1,1,1);
		}else if(animationplayed == 16) {
		ApplyAnimation(playerid,"BSKTBALL","BBALL_idleloop_O",4.1,0,1,1,1,1);
		}else if(animationplayed == 17) {
		ApplyAnimation(playerid,"BSKTBALL","BBALL_idle_O",4.1,0,1,1,1,1);
		}else if(animationplayed == 18) {
		ApplyAnimation(playerid,"BSKTBALL","BBALL_Jump_Cancel",4.1,0,1,1,1,1);
		}else if(animationplayed == 19) {
		ApplyAnimation(playerid,"BSKTBALL","BBALL_Jump_Cancel_0",4.1,0,1,1,1,1);
		}else if(animationplayed == 20) {
		ApplyAnimation(playerid,"BSKTBALL","BBALL_Jump_End",4.1,0,1,1,1,1);
		}else if(animationplayed == 21) {
		ApplyAnimation(playerid,"BSKTBALL","BBALL_Jump_Shot",4.1,0,1,1,1,1);
		}else if(animationplayed == 22) {
		ApplyAnimation(playerid,"BSKTBALL","BBALL_Jump_Shot_O",4.1,0,1,1,1,1);
		}else if(animationplayed == 23) {
		ApplyAnimation(playerid,"BSKTBALL","BBALL_Net_Dnk_O",4.1,0,1,1,1,1);
		}else if(animationplayed == 24) {
		ApplyAnimation(playerid,"BSKTBALL","BBALL_pickup",4.1,0,1,1,1,1);
		}else if(animationplayed == 25) {
		ApplyAnimation(playerid,"BSKTBALL","BBALL_pickup_O",4.1,0,1,1,1,1);
		}else if(animationplayed == 26) {
		ApplyAnimation(playerid,"BSKTBALL","BBALL_react_miss",4.1,0,1,1,1,1);
		}else if(animationplayed == 27) {
		ApplyAnimation(playerid,"BSKTBALL","BBALL_react_score",4.1,0,1,1,1,1);
		}else if(animationplayed == 28) {
		ApplyAnimation(playerid,"BSKTBALL","BBALL_run",4.1,0,1,1,1,1);
		}else if(animationplayed == 29) {
		ApplyAnimation(playerid,"BSKTBALL","BBALL_run_O",4.1,0,1,1,1,1);
		}else if(animationplayed == 30) {
		ApplyAnimation(playerid,"BSKTBALL","BBALL_SkidStop_L",4.1,0,1,1,1,1);
		}else if(animationplayed == 31) {
		ApplyAnimation(playerid,"BSKTBALL","BBALL_SkidStop_L_O",4.1,0,1,1,1,1);
		}else if(animationplayed == 32) {
		ApplyAnimation(playerid,"BSKTBALL","BBALL_SkidStop_R",4.1,0,1,1,1,1);
		}else if(animationplayed == 33) {
		ApplyAnimation(playerid,"BSKTBALL","BBALL_SkidStop_R_O",4.1,0,1,1,1,1);
		}else if(animationplayed == 34) {
		ApplyAnimation(playerid,"BSKTBALL","BBALL_walk",4.1,0,1,1,1,1);
		}else if(animationplayed == 35) {
		ApplyAnimation(playerid,"BSKTBALL","BBALL_WalkStop_L",4.1,0,1,1,1,1);
		}else if(animationplayed == 36) {
		ApplyAnimation(playerid,"BSKTBALL","BBALL_WalkStop_L_O",4.1,0,1,1,1,1);
		}else if(animationplayed == 37) {
		ApplyAnimation(playerid,"BSKTBALL","BBALL_WalkStop_R",4.1,0,1,1,1,1);
		}else if(animationplayed == 38) {
		ApplyAnimation(playerid,"BSKTBALL","BBALL_WalkStop_R_O",4.1,0,1,1,1,1);
		}else if(animationplayed == 39) {
		ApplyAnimation(playerid,"BSKTBALL","BBALL_walk_O",4.1,0,1,1,1,1);
		}else if(animationplayed == 40) {
		ApplyAnimation(playerid,"BSKTBALL","BBALL_walk_start",4.1,0,1,1,1,1);
		}else if(animationplayed == 41) {
		ApplyAnimation(playerid,"BSKTBALL","BBALL_walk_start_O",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animcamera", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animcamera [1-14]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 14) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animcamera [1-14]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"CAMERA","camcrch_cmon",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"CAMERA","camcrch_idleloop",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"CAMERA","camcrch_stay",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"CAMERA","camcrch_to_camstnd",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"CAMERA","camstnd_cmon",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"CAMERA","camstnd_idleloop",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"CAMERA","camstnd_lkabt",4.1,0,1,1,1,1);
		}else if(animationplayed == 8) {
		ApplyAnimation(playerid,"CAMERA","camstnd_to_camcrch",4.1,0,1,1,1,1);
		}else if(animationplayed == 9) {
		ApplyAnimation(playerid,"CAMERA","piccrch_in",4.1,0,1,1,1,1);
		}else if(animationplayed == 10) {
		ApplyAnimation(playerid,"CAMERA","piccrch_out",4.1,0,1,1,1,1);
		}else if(animationplayed == 11) {
		ApplyAnimation(playerid,"CAMERA","piccrch_take",4.1,0,1,1,1,1);
		}else if(animationplayed == 12) {
		ApplyAnimation(playerid,"CAMERA","picstnd_in",4.1,0,1,1,1,1);
		}else if(animationplayed == 13) {
		ApplyAnimation(playerid,"CAMERA","picstnd_out",4.1,0,1,1,1,1);
		}else if(animationplayed == 14) {
		ApplyAnimation(playerid,"CAMERA","picstnd_take",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animgym", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animgym [1-24]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 24) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animgym [1-24]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"GYMNASIUM","GYMshadowbox",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"GYMNASIUM","gym_bike_celebrate",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"GYMNASIUM","gym_bike_fast",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"GYMNASIUM","gym_bike_faster",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"GYMNASIUM","gym_bike_getoff",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"GYMNASIUM","gym_bike_geton",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"GYMNASIUM","gym_bike_pedal",4.1,0,1,1,1,1);
		}else if(animationplayed == 8) {
		ApplyAnimation(playerid,"GYMNASIUM","gym_bike_slow",4.1,0,1,1,1,1);
		}else if(animationplayed == 9) {
		ApplyAnimation(playerid,"GYMNASIUM","gym_bike_still",4.1,0,1,1,1,1);
		}else if(animationplayed == 10) {
		ApplyAnimation(playerid,"GYMNASIUM","gym_jog_falloff",4.1,0,1,1,1,1);
		}else if(animationplayed == 11) {
		ApplyAnimation(playerid,"GYMNASIUM","gym_shadowbox",4.1,0,1,1,1,1);
		}else if(animationplayed == 12) {
		ApplyAnimation(playerid,"GYMNASIUM","gym_tread_celebrate",4.1,0,1,1,1,1);
		}else if(animationplayed == 13) {
		ApplyAnimation(playerid,"GYMNASIUM","gym_tread_falloff",4.1,0,1,1,1,1);
		}else if(animationplayed == 14) {
		ApplyAnimation(playerid,"GYMNASIUM","gym_tread_getoff",4.1,0,1,1,1,1);
		}else if(animationplayed == 15) {
		ApplyAnimation(playerid,"GYMNASIUM","gym_tread_geton",4.1,0,1,1,1,1);
		}else if(animationplayed == 16) {
		ApplyAnimation(playerid,"GYMNASIUM","gym_tread_jog",4.1,0,1,1,1,1);
		}else if(animationplayed == 17) {
		ApplyAnimation(playerid,"GYMNASIUM","gym_tread_sprint",4.1,0,1,1,1,1);
		}else if(animationplayed == 18) {
		ApplyAnimation(playerid,"GYMNASIUM","gym_tread_tired",4.1,0,1,1,1,1);
		}else if(animationplayed == 19) {
		ApplyAnimation(playerid,"GYMNASIUM","gym_tread_walk",4.1,0,1,1,1,1);
		}else if(animationplayed == 20) {
		ApplyAnimation(playerid,"GYMNASIUM","gym_walk_falloff",4.1,0,1,1,1,1);
		}else if(animationplayed == 21) {
		ApplyAnimation(playerid,"GYMNASIUM","Pedals_fast",4.1,0,1,1,1,1);
		}else if(animationplayed == 22) {
		ApplyAnimation(playerid,"GYMNASIUM","Pedals_med",4.1,0,1,1,1,1);
		}else if(animationplayed == 23) {
		ApplyAnimation(playerid,"GYMNASIUM","Pedals_slow",4.1,0,1,1,1,1);
		}else if(animationplayed == 24) {
		ApplyAnimation(playerid,"GYMNASIUM","Pedals_still",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animpara", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animpara [1-22]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 22) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animpara [1-22]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"PARACHUTE","FALL_skyDive",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"PARACHUTE","FALL_SkyDive_Accel",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"PARACHUTE","FALL_skyDive_DIE",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"PARACHUTE","FALL_SkyDive_L",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"PARACHUTE","FALL_SkyDive_R",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"PARACHUTE","PARA_decel",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"PARACHUTE","PARA_decel_O",4.1,0,1,1,1,1);
		}else if(animationplayed == 8) {
		ApplyAnimation(playerid,"PARACHUTE","PARA_float",4.1,0,1,1,1,1);
		}else if(animationplayed == 9) {
		ApplyAnimation(playerid,"PARACHUTE","PARA_float_O",4.1,0,1,1,1,1);
		}else if(animationplayed == 10) {
		ApplyAnimation(playerid,"PARACHUTE","PARA_Land",4.1,0,1,1,1,1);
		}else if(animationplayed == 11) {
		ApplyAnimation(playerid,"PARACHUTE","PARA_Land_O",4.1,0,1,1,1,1);
		}else if(animationplayed == 12) {
		ApplyAnimation(playerid,"PARACHUTE","PARA_Land_Water",4.1,0,1,1,1,1);
		}else if(animationplayed == 13) {
		ApplyAnimation(playerid,"PARACHUTE","PARA_Land_Water_O",4.1,0,1,1,1,1);
		}else if(animationplayed == 14) {
		ApplyAnimation(playerid,"PARACHUTE","PARA_open",4.1,0,1,1,1,1);
		}else if(animationplayed == 15) {
		ApplyAnimation(playerid,"PARACHUTE","PARA_open_O",4.1,0,1,1,1,1);
		}else if(animationplayed == 16) {
		ApplyAnimation(playerid,"PARACHUTE","PARA_Rip_Land_O",4.1,0,1,1,1,1);
		}else if(animationplayed == 17) {
		ApplyAnimation(playerid,"PARACHUTE","PARA_Rip_Loop_O",4.1,0,1,1,1,1);
		}else if(animationplayed == 18) {
		ApplyAnimation(playerid,"PARACHUTE","PARA_Rip_O",4.1,0,1,1,1,1);
		}else if(animationplayed == 19) {
		ApplyAnimation(playerid,"PARACHUTE","PARA_steerL",4.1,0,1,1,1,1);
		}else if(animationplayed == 20) {
		ApplyAnimation(playerid,"PARACHUTE","PARA_steerL_O",4.1,0,1,1,1,1);
		}else if(animationplayed == 21) {
		ApplyAnimation(playerid,"PARACHUTE","PARA_steerR",4.1,0,1,1,1,1);
		}else if(animationplayed == 22) {
		ApplyAnimation(playerid,"PARACHUTE","PARA_steerR_O",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animgangs", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animgangs [1-22]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 22) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animgangs [1-22]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"GANGS","DEALER_DEAL",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"GANGS","DEALER_IDLE",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"GANGS","drnkbr_prtl",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"GANGS","drnkbr_prtl_F",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"GANGS","DRUGS_BUY",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"GANGS","hndshkaa",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"GANGS","hndshkba",4.1,0,1,1,1,1);
		}else if(animationplayed == 8) {
		ApplyAnimation(playerid,"GANGS","hndshkca",4.1,0,1,1,1,1);
		}else if(animationplayed == 9) {
		ApplyAnimation(playerid,"GANGS","hndshkcb",4.1,0,1,1,1,1);
		}else if(animationplayed == 10) {
		ApplyAnimation(playerid,"GANGS","hndshkda",4.1,0,1,1,1,1);
		}else if(animationplayed == 11) {
		ApplyAnimation(playerid,"GANGS","hndshkea",4.1,0,1,1,1,1);
		}else if(animationplayed == 12) {
		ApplyAnimation(playerid,"GANGS","hndshkfa",4.1,0,1,1,1,1);
		}else if(animationplayed == 13) {
		ApplyAnimation(playerid,"GANGS","hndshkfa_swt",4.1,0,1,1,1,1);
		}else if(animationplayed == 14) {
		ApplyAnimation(playerid,"GANGS","Invite_No",4.1,0,1,1,1,1);
		}else if(animationplayed == 15) {
		ApplyAnimation(playerid,"GANGS","Invite_Yes",4.1,0,1,1,1,1);
		}else if(animationplayed == 16) {
		ApplyAnimation(playerid,"GANGS","leanIDLE",4.1,0,1,1,1,1);
		}else if(animationplayed == 17) {
		ApplyAnimation(playerid,"GANGS","leanIN",4.1,0,1,1,1,1);
		}else if(animationplayed == 18) {
		ApplyAnimation(playerid,"GANGS","leanOUT",4.1,0,1,1,1,1);
		}else if(animationplayed == 19) {
		ApplyAnimation(playerid,"GANGS","prtial_gngtlkA",4.1,0,1,1,1,1);
		}else if(animationplayed == 20) {
		ApplyAnimation(playerid,"GANGS","prtial_gngtlkB",4.1,0,1,1,1,1);
		}else if(animationplayed == 21) {
		ApplyAnimation(playerid,"GANGS","prtial_gngtlkCt",4.1,0,1,1,1,1);
		}else if(animationplayed == 22) {
		ApplyAnimation(playerid,"GANGS","prtial_gngtlkD",4.1,0,1,1,1,1);
		}else if(animationplayed == 23) {
		ApplyAnimation(playerid,"GANGS","prtial_gngtlkE",4.1,0,1,1,1,1);
		}else if(animationplayed == 24) {
		ApplyAnimation(playerid,"GANGS","prtial_gngtlkF",4.1,0,1,1,1,1);
		}else if(animationplayed == 25) {
		ApplyAnimation(playerid,"GANGS","prtial_gngtlkG",4.1,0,1,1,1,1);
		}else if(animationplayed == 26) {
		ApplyAnimation(playerid,"GANGS","prtial_gngtlkH",4.1,0,1,1,1,1);
		}else if(animationplayed == 27) {
		ApplyAnimation(playerid,"GANGS","prtial_hndshk_01",4.1,0,1,1,1,1);
		}else if(animationplayed == 28) {
		ApplyAnimation(playerid,"GANGS","prtial_hndshk_biz_01",4.1,0,1,1,1,1);
		}else if(animationplayed == 29) {
		ApplyAnimation(playerid,"GANGS","shake_cara",4.1,0,1,1,1,1);
		}else if(animationplayed == 30) {
		ApplyAnimation(playerid,"GANGS","shake_carK",4.1,0,1,1,1,1);
		}else if(animationplayed == 31) {
		ApplyAnimation(playerid,"GANGS","shake_carSH",4.1,0,1,1,1,1);
		}else if(animationplayed == 32) {
		ApplyAnimation(playerid,"GANGS","smkcig_prtl",4.1,0,1,1,1,1);
		}else if(animationplayed == 33) {
		ApplyAnimation(playerid,"GANGS","smkcig_prtl_F",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animlowrider", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animlowrider [1-39]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 39) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animlowrider [1-39]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"LOWRIDER","F_smklean_loop",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"LOWRIDER","lrgirl_bdbnce",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"LOWRIDER","lrgirl_hair",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"LOWRIDER","lrgirl_hurry",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"LOWRIDER","lrgirl_idleloop",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"LOWRIDER","lrgirl_idle_to_l0",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"LOWRIDER","lrgirl_l0_bnce",4.1,0,1,1,1,1);
		}else if(animationplayed == 8) {
		ApplyAnimation(playerid,"LOWRIDER","lrgirl_l0_loop",4.1,0,1,1,1,1);
		}else if(animationplayed == 9) {
		ApplyAnimation(playerid,"LOWRIDER","lrgirl_l0_to_l1",4.1,0,1,1,1,1);
		}else if(animationplayed == 10) {
		ApplyAnimation(playerid,"LOWRIDER","lrgirl_l12_to_l0",4.1,0,1,1,1,1);
		}else if(animationplayed == 11) {
		ApplyAnimation(playerid,"LOWRIDER","lrgirl_l1_bnce",4.1,0,1,1,1,1);
		}else if(animationplayed == 12) {
		ApplyAnimation(playerid,"LOWRIDER","lrgirl_l1_loop",4.1,0,1,1,1,1);
		}else if(animationplayed == 13) {
		ApplyAnimation(playerid,"LOWRIDER","lrgirl_l1_to_l2",4.1,0,1,1,1,1);
		}else if(animationplayed == 14) {
		ApplyAnimation(playerid,"LOWRIDER","lrgirl_l2_bnce",4.1,0,1,1,1,1);
		}else if(animationplayed == 15) {
		ApplyAnimation(playerid,"LOWRIDER","lrgirl_l2_loop",4.1,0,1,1,1,1);
		}else if(animationplayed == 16) {
		ApplyAnimation(playerid,"LOWRIDER","lrgirl_l2_to_l3",4.1,0,1,1,1,1);
		}else if(animationplayed == 17) {
		ApplyAnimation(playerid,"LOWRIDER","lrgirl_l345_to_l1",4.1,0,1,1,1,1);
		}else if(animationplayed == 18) {
		ApplyAnimation(playerid,"LOWRIDER","lrgirl_l3_bnce",4.1,0,1,1,1,1);
		}else if(animationplayed == 19) {
		ApplyAnimation(playerid,"LOWRIDER","lrgirl_l3_loop",4.1,0,1,1,1,1);
		}else if(animationplayed == 20) {
		ApplyAnimation(playerid,"LOWRIDER","lrgirl_l3_to_l4",4.1,0,1,1,1,1);
		}else if(animationplayed == 21) {
		ApplyAnimation(playerid,"LOWRIDER","lrgirl_l4_bnce",4.1,0,1,1,1,1);
		}else if(animationplayed == 22) {
		ApplyAnimation(playerid,"LOWRIDER","lrgirl_l4_loop",4.1,0,1,1,1,1);
		}else if(animationplayed == 23) {
		ApplyAnimation(playerid,"LOWRIDER","lrgirl_l4_to_l5",4.1,0,1,1,1,1);
		}else if(animationplayed == 24) {
		ApplyAnimation(playerid,"LOWRIDER","lrgirl_l5_bnce",4.1,0,1,1,1,1);
		}else if(animationplayed == 25) {
		ApplyAnimation(playerid,"LOWRIDER","lrgirl_l5_loop",4.1,0,1,1,1,1);
		}else if(animationplayed == 26) {
		ApplyAnimation(playerid,"LOWRIDER","M_smklean_loop",4.1,0,1,1,1,1);
		}else if(animationplayed == 27) {
		ApplyAnimation(playerid,"LOWRIDER","M_smkstnd_loop",4.1,0,1,1,1,1);
		}else if(animationplayed == 28) {
		ApplyAnimation(playerid,"LOWRIDER","prtial_gngtlkB",4.1,0,1,1,1,1);
		}else if(animationplayed == 29) {
		ApplyAnimation(playerid,"LOWRIDER","prtial_gngtlkC",4.1,0,1,1,1,1);
		}else if(animationplayed == 30) {
		ApplyAnimation(playerid,"LOWRIDER","prtial_gngtlkD",4.1,0,1,1,1,1);
		}else if(animationplayed == 31) {
		ApplyAnimation(playerid,"LOWRIDER","prtial_gngtlkE",4.1,0,1,1,1,1);
		}else if(animationplayed == 32) {
		ApplyAnimation(playerid,"LOWRIDER","prtial_gngtlkF",4.1,0,1,1,1,1);
		}else if(animationplayed == 33) {
		ApplyAnimation(playerid,"LOWRIDER","prtial_gngtlkG",4.1,0,1,1,1,1);
		}else if(animationplayed == 34) {
		ApplyAnimation(playerid,"LOWRIDER","prtial_gngtlkH",4.1,0,1,1,1,1);
		}else if(animationplayed == 35) {
		ApplyAnimation(playerid,"LOWRIDER","RAP_A_Loop",4.1,0,1,1,1,1);
		}else if(animationplayed == 36) {
		ApplyAnimation(playerid,"LOWRIDER","RAP_B_Loop",4.1,0,1,1,1,1);
		}else if(animationplayed == 37) {
		ApplyAnimation(playerid,"LOWRIDER","RAP_C_Loop",4.1,0,1,1,1,1);
		}else if(animationplayed == 38) {
		ApplyAnimation(playerid,"LOWRIDER","Sit_relaxed",4.1,0,1,1,1,1);
		}else if(animationplayed == 39) {
		ApplyAnimation(playerid,"LOWRIDER","Tap_hand",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animlookers", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animlookers [1-25]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 25) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animlookers [1-25]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"ON_LOOKERS","lkaround_in",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"ON_LOOKERS","lkaround_loop",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"ON_LOOKERS","lkaround_out",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"ON_LOOKERS","lkup_in",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"ON_LOOKERS","lkup_loop",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"ON_LOOKERS","lkup_out",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"ON_LOOKERS","lkup_point",4.1,0,1,1,1,1);
		}else if(animationplayed == 8) {
		ApplyAnimation(playerid,"ON_LOOKERS","panic_cower",4.1,0,1,1,1,1);
		}else if(animationplayed == 9) {
		ApplyAnimation(playerid,"ON_LOOKERS","panic_hide",4.1,0,1,1,1,1);
		}else if(animationplayed == 10) {
		ApplyAnimation(playerid,"ON_LOOKERS","panic_in",4.1,0,1,1,1,1);
		}else if(animationplayed == 11) {
		ApplyAnimation(playerid,"ON_LOOKERS","panic_loop",4.1,0,1,1,1,1);
		}else if(animationplayed == 12) {
		ApplyAnimation(playerid,"ON_LOOKERS","panic_out",4.1,0,1,1,1,1);
		}else if(animationplayed == 13) {
		ApplyAnimation(playerid,"ON_LOOKERS","panic_point",4.1,0,1,1,1,1);
		}else if(animationplayed == 14) {
		ApplyAnimation(playerid,"ON_LOOKERS","panic_shout",4.1,0,1,1,1,1);
		}else if(animationplayed == 15) {
		ApplyAnimation(playerid,"ON_LOOKERS","Pointup_in",4.1,0,1,1,1,1);
		}else if(animationplayed == 16) {
		ApplyAnimation(playerid,"ON_LOOKERS","Pointup_loop",4.1,0,1,1,1,1);
		}else if(animationplayed == 17) {
		ApplyAnimation(playerid,"ON_LOOKERS","Pointup_out",4.1,0,1,1,1,1);
		}else if(animationplayed == 18) {
		ApplyAnimation(playerid,"ON_LOOKERS","Pointup_shout",4.1,0,1,1,1,1);
		}else if(animationplayed == 19) {
		ApplyAnimation(playerid,"ON_LOOKERS","point_in",4.1,0,1,1,1,1);
		}else if(animationplayed == 20) {
		ApplyAnimation(playerid,"ON_LOOKERS","point_loop",4.1,0,1,1,1,1);
		}else if(animationplayed == 21) {
		ApplyAnimation(playerid,"ON_LOOKERS","point_out",4.1,0,1,1,1,1);
		}else if(animationplayed == 22) {
		ApplyAnimation(playerid,"ON_LOOKERS","shout_01",4.1,0,1,1,1,1);
		}else if(animationplayed == 23) {
		ApplyAnimation(playerid,"ON_LOOKERS","shout_02",4.1,0,1,1,1,1);
		}else if(animationplayed == 24) {
		ApplyAnimation(playerid,"ON_LOOKERS","shout_in",4.1,0,1,1,1,1);
		}else if(animationplayed == 25) {
		ApplyAnimation(playerid,"ON_LOOKERS","shout_loop",4.1,0,1,1,1,1);
		}else if(animationplayed == 26) {
		ApplyAnimation(playerid,"ON_LOOKERS","shout_out",4.1,0,1,1,1,1);
		}else if(animationplayed == 27) {
		ApplyAnimation(playerid,"ON_LOOKERS","wave_in",4.1,0,1,1,1,1);
		}else if(animationplayed == 28) {
		ApplyAnimation(playerid,"ON_LOOKERS","wave_loop",4.1,0,1,1,1,1);
		}else if(animationplayed == 25) {
		ApplyAnimation(playerid,"ON_LOOKERS","wave_out",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animcarchat", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animcarchat [1-20]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 20) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animcarchat [1-20]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"CAR_CHAT","carfone_in",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"CAR_CHAT","carfone_loopA",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"CAR_CHAT","carfone_loopA_to_B",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"CAR_CHAT","carfone_loopB",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"CAR_CHAT","carfone_loopB_to_A",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"CAR_CHAT","carfone_out",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"CAR_CHAT","CAR_Sc1_BR",4.1,0,1,1,1,1);
		}else if(animationplayed == 8) {
		ApplyAnimation(playerid,"CAR_CHAT","CAR_Sc1_FL",4.1,0,1,1,1,1);
		}else if(animationplayed == 9) {
		ApplyAnimation(playerid,"CAR_CHAT","CAR_Sc1_FR",4.1,0,1,1,1,1);
		}else if(animationplayed == 10) {
		ApplyAnimation(playerid,"CAR_CHAT","CAR_Sc2_FL",4.1,0,1,1,1,1);
		}else if(animationplayed == 11) {
		ApplyAnimation(playerid,"CAR_CHAT","CAR_Sc3_BR",4.1,0,1,1,1,1);
		}else if(animationplayed == 12) {
		ApplyAnimation(playerid,"CAR_CHAT","CAR_Sc3_FL",4.1,0,1,1,1,1);
		}else if(animationplayed == 13) {
		ApplyAnimation(playerid,"CAR_CHAT","CAR_Sc3_FR",4.1,0,1,1,1,1);
		}else if(animationplayed == 14) {
		ApplyAnimation(playerid,"CAR_CHAT","CAR_Sc4_BL",4.1,0,1,1,1,1);
		}else if(animationplayed == 15) {
		ApplyAnimation(playerid,"CAR_CHAT","CAR_Sc4_BR",4.1,0,1,1,1,1);
		}else if(animationplayed == 16) {
		ApplyAnimation(playerid,"CAR_CHAT","CAR_Sc4_FL",4.1,0,1,1,1,1);
		}else if(animationplayed == 17) {
		ApplyAnimation(playerid,"CAR_CHAT","CAR_Sc4_FR",4.1,0,1,1,1,1);
		}else if(animationplayed == 18) {
		ApplyAnimation(playerid,"CAR_CHAT","car_talkm_in",4.1,0,1,1,1,1);
		}else if(animationplayed == 19) {
		ApplyAnimation(playerid,"CAR_CHAT","car_talkm_loop",4.1,0,1,1,1,1);
		}else if(animationplayed == 20) {
		ApplyAnimation(playerid,"CAR_CHAT","car_talkm_out",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animcasino", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animcasino [1-23]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 23) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animcasino [1-23]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"CASINO","cards_in",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"CASINO","cards_loop",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"CASINO","cards_lose",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"CASINO","cards_out",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"CASINO","cards_pick_01",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"CASINO","cards_pick_02",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"CASINO","cards_raise",4.1,0,1,1,1,1);
		}else if(animationplayed == 8) {
		ApplyAnimation(playerid,"CASINO","cards_win",4.1,0,1,1,1,1);
		}else if(animationplayed == 9) {
		ApplyAnimation(playerid,"CASINO","manwinb",4.1,0,1,1,1,1);
		}else if(animationplayed == 10) {
		ApplyAnimation(playerid,"CASINO","manwind",4.1,0,1,1,1,1);
		}else if(animationplayed == 11) {
		ApplyAnimation(playerid,"CASINO","Roulette_bet",4.1,0,1,1,1,1);
		}else if(animationplayed == 12) {
		ApplyAnimation(playerid,"CASINO","Roulette_in",4.1,0,1,1,1,1);
		}else if(animationplayed == 13) {
		ApplyAnimation(playerid,"CASINO","Roulette_loop",4.1,0,1,1,1,1);
		}else if(animationplayed == 14) {
		ApplyAnimation(playerid,"CASINO","Roulette_lose",4.1,0,1,1,1,1);
		}else if(animationplayed == 15) {
		ApplyAnimation(playerid,"CASINO","Roulette_out",4.1,0,1,1,1,1);
		}else if(animationplayed == 16) {
		ApplyAnimation(playerid,"CASINO","Roulette_win",4.1,0,1,1,1,1);
		}else if(animationplayed == 17) {
		ApplyAnimation(playerid,"CASINO","Slot_bet_02",4.1,0,1,1,1,1);
		}else if(animationplayed == 18) {
		ApplyAnimation(playerid,"CASINO","Slot_in",4.1,0,1,1,1,1);
		}else if(animationplayed == 19) {
		ApplyAnimation(playerid,"CASINO","Slot_lose_out",4.1,0,1,1,1,1);
		}else if(animationplayed == 20) {
		ApplyAnimation(playerid,"CASINO","Slot_Plyr",4.1,0,1,1,1,1);
		}else if(animationplayed == 21) {
		ApplyAnimation(playerid,"CASINO","Slot_wait",4.1,0,1,1,1,1);
		}else if(animationplayed == 22) {
		ApplyAnimation(playerid,"CASINO","Slot_win_out",4.1,0,1,1,1,1);
		}else if(animationplayed == 23) {
		ApplyAnimation(playerid,"CASINO","wof",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animbuddy", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animbuddy [1-5]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 5) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animbuddy [1-5]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"BUDDY","buddy_crouchfire",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"BUDDY","buddy_crouchreload",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"BUDDY","buddy_fire",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"BUDDY","buddy_fire_poor",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"BUDDY","buddy_reload",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animbus", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animbus [1-9]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 9) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animbus [1-9]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"BUS","BUS_close",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"BUS","BUS_getin_LHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"BUS","BUS_getin_RHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"BUS","BUS_getout_LHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"BUS","BUS_getout_RHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"BUS","BUS_jacked_LHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"BUS","BUS_open",4.1,0,1,1,1,1);
		}else if(animationplayed == 8) {
		ApplyAnimation(playerid,"BUS","BUS_open_RHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 9) {
		ApplyAnimation(playerid,"BUS","BUS_pullout_LHS",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animcar", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animcar [1-11]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 11) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animcar [1-11]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"CAR","Fixn_Car_Loop",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"CAR","Fixn_Car_Out",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"CAR","flag_drop",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"CAR","Sit_relaxed",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"CAR","Tap_hand",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"CAR","Tyd2car_bump",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"CAR","Tyd2car_high",4.1,0,1,1,1,1);
		}else if(animationplayed == 8) {
		ApplyAnimation(playerid,"CAR","Tyd2car_low",4.1,0,1,1,1,1);
		}else if(animationplayed == 9) {
		ApplyAnimation(playerid,"CAR","Tyd2car_med",4.1,0,1,1,1,1);
		}else if(animationplayed == 10) {
		ApplyAnimation(playerid,"CAR","Tyd2car_TurnL",4.1,0,1,1,1,1);
		}else if(animationplayed == 11) {
		ApplyAnimation(playerid,"CAR","Tyd2car_TurnR",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animcarry", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animcarry [1-7]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 7) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animcarry [1-7]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"CARRY","crry_prtial",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"CARRY","liftup",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"CARRY","liftup05",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"CARRY","liftup105",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"CARRY","putdwn",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"CARRY","putdwn05",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"CARRY","putdwn105",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animintshop", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animintshop [1-8]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 8) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animintshop [1-8]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"INT_SHOP","shop_cashier",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"INT_SHOP","shop_in",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"INT_SHOP","shop_lookA",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"INT_SHOP","shop_lookB",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"INT_SHOP","shop_loop",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"INT_SHOP","shop_out",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"INT_SHOP","shop_pay",4.1,0,1,1,1,1);
		}else if(animationplayed == 8) {
		ApplyAnimation(playerid,"INT_SHOP","shop_shelf",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animjst", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animjst [1-4]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 4) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animjst [1-4]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"JST_BUISNESS","girl_01",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"JST_BUISNESS","girl_02",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"JST_BUISNESS","player_01",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"JST_BUISNESS","smoke_01",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animkart", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animkart [1-4]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 4) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animkart [1-4]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"KART","KART_getin_LHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"KART","KART_getin_RHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"KART","KART_getout_LHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"KART","KART_getout_RHS",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animkissing", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animkissing [1-14]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 14) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animkissing [1-14]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"KISSING","BD_GF_Wave",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"KISSING","gfwave2",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"KISSING","GF_CarArgue_01",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"KISSING","GF_CarArgue_02",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"KISSING","GF_CarSpot",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"KISSING","GF_StreetArgue_01",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"KISSING","GF_StreetArgue_02",4.1,0,1,1,1,1);
		}else if(animationplayed == 8) {
		ApplyAnimation(playerid,"KISSING","gift_give",4.1,0,1,1,1,1);
		}else if(animationplayed == 9) {
		ApplyAnimation(playerid,"KISSING","Grlfrd_Kiss_01",4.1,0,1,1,1,1);
		}else if(animationplayed == 10) {
		ApplyAnimation(playerid,"KISSING","Grlfrd_Kiss_02",4.1,0,1,1,1,1);
		}else if(animationplayed == 11) {
		ApplyAnimation(playerid,"KISSING","Grlfrd_Kiss_03",4.1,0,1,1,1,1);
		}else if(animationplayed == 12) {
		ApplyAnimation(playerid,"KISSING","Playa_Kiss_01",4.1,0,1,1,1,1);
		}else if(animationplayed == 13) {
		ApplyAnimation(playerid,"KISSING","Playa_Kiss_02",4.1,0,1,1,1,1);
		}else if(animationplayed == 14) {
		ApplyAnimation(playerid,"KISSING","Playa_Kiss_03",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animknife", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animknife [1-14]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 14) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animknife [1-14]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"KNIFE","KILL_Knife_Ped_Damage",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"KNIFE","KILL_Knife_Ped_Die",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"KNIFE","KILL_Knife_Player",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"KNIFE","KILL_Partial",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"KNIFE","knife_2",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"KNIFE","knife_3",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"KNIFE","knife_4",4.1,0,1,1,1,1);
		}else if(animationplayed == 8) {
		ApplyAnimation(playerid,"KNIFE","Knife_G",4.1,0,1,1,1,1);
		}else if(animationplayed == 9) {
		ApplyAnimation(playerid,"KNIFE","knife_hit_1",4.1,0,1,1,1,1);
		}else if(animationplayed == 10) {
		ApplyAnimation(playerid,"KNIFE","knife_hit_2",4.1,0,1,1,1,1);
		}else if(animationplayed == 11) {
		ApplyAnimation(playerid,"KNIFE","knife_IDLE",4.1,0,1,1,1,1);
		}else if(animationplayed == 12) {
		ApplyAnimation(playerid,"KNIFE","knife_hit_3",4.1,0,1,1,1,1);
		}else if(animationplayed == 13) {
		ApplyAnimation(playerid,"KNIFE","knife_part",4.1,0,1,1,1,1);
		}else if(animationplayed == 14) {
		ApplyAnimation(playerid,"KNIFE","WEAPON_knifeidle",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animlapdan", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animlapdan [1-6]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 6) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animlapdan [1-6]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"LAPDAN1","LAPDAN_D",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"LAPDAN1","LAPDAN_P",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"LAPDAN2","LAPDAN_D",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"LAPDAN2","LAPDAN_P",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"LAPDAN3","LAPDAN_D",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"LAPDAN3","LAPDAN_P",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animdend", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animdend [1-8]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 8) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animdend [1-8]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"MD_END","END_SC1_PLY",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"MD_END","END_SC1_RYD",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"MD_END","END_SC1_SMO",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"MD_END","END_SC1_SWE",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"MD_END","END_SC2_PLY",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"MD_END","END_SC2_RYD",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"MD_END","END_SC2_SMO",4.1,0,1,1,1,1);
		}else if(animationplayed == 8) {
		ApplyAnimation(playerid,"MD_END","END_SC2_SWE",4.1,0,1,1,1,1);
		}
		return 1;
		}

		if(strcmp(cmd, "/animmedic", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animmedic [1]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 1) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animmedic [1]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"MEDIC","CPR",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animmtb", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animmtb [1-18]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 18) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animmtb [1-18]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"MTB","MTB_back",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"MTB","MTB_bunnyhop",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"MTB","MTB_drivebyFT",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"MTB","MTB_driveby_LHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"MTB","MTB_driveby_RHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"MTB","MTB_fwd",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"MTB","MTB_getoffBACK",4.1,0,1,1,1,1);
		}else if(animationplayed == 8) {
		ApplyAnimation(playerid,"MTB","MTB_pushes",4.1,0,1,1,1,1);
		}else if(animationplayed == 9) {
		ApplyAnimation(playerid,"MTB","MTB_getoffLHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 10) {
		ApplyAnimation(playerid,"MTB","MTB_getoffRHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 11) {
		ApplyAnimation(playerid,"MTB","MTB_jumponL",4.1,0,1,1,1,1);
		}else if(animationplayed == 12) {
		ApplyAnimation(playerid,"MTB","MTB_jumponR",4.1,0,1,1,1,1);
		}else if(animationplayed == 13) {
		ApplyAnimation(playerid,"MTB","MTB_Left",4.1,0,1,1,1,1);
		}else if(animationplayed == 14) {
		ApplyAnimation(playerid,"MTB","MTB_pedal",4.1,0,1,1,1,1);
		}else if(animationplayed == 15) {
		ApplyAnimation(playerid,"MTB","MTB_Ride",4.1,0,1,1,1,1);
		}else if(animationplayed == 16) {
		ApplyAnimation(playerid,"MTB","MTB_Right",4.1,0,1,1,1,1);
		}else if(animationplayed == 17) {
		ApplyAnimation(playerid,"MTB","MTB_sprint",4.1,0,1,1,1,1);
		}else if(animationplayed == 18) {
		ApplyAnimation(playerid,"MTB","MTB_still",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animmusc", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animmusc [1-17]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 17) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animmusc [1-17]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"MUSCULAR","MscleWalkst_armed",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"MUSCULAR","MscleWalkst_Csaw",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"MUSCULAR","Mscle_rckt_run",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"MUSCULAR","Mscle_rckt_walkst",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"MUSCULAR","Mscle_run_Csaw",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"MUSCULAR","MuscleIdle",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"MUSCULAR","MuscleIdle_armed",4.1,0,1,1,1,1);
		}else if(animationplayed == 8) {
		ApplyAnimation(playerid,"MUSCULAR","MuscleIdle_Csaw",4.1,0,1,1,1,1);
		}else if(animationplayed == 9) {
		ApplyAnimation(playerid,"MUSCULAR","MuscleIdle_rocket",4.1,0,1,1,1,1);
		}else if(animationplayed == 10) {
		ApplyAnimation(playerid,"MUSCULAR","MuscleRun",4.1,0,1,1,1,1);
		}else if(animationplayed == 11) {
		ApplyAnimation(playerid,"MUSCULAR","MuscleRun_armed",4.1,0,1,1,1,1);
		}else if(animationplayed == 12) {
		ApplyAnimation(playerid,"MUSCULAR","MuscleSprint",4.1,0,1,1,1,1);
		}else if(animationplayed == 13) {
		ApplyAnimation(playerid,"MUSCULAR","MuscleWalk",4.1,0,1,1,1,1);
		}else if(animationplayed == 14) {
		ApplyAnimation(playerid,"MUSCULAR","MuscleWalkstart",4.1,0,1,1,1,1);
		}else if(animationplayed == 15) {
		ApplyAnimation(playerid,"MUSCULAR","MuscleWalk_armed",4.1,0,1,1,1,1);
		}else if(animationplayed == 16) {
		ApplyAnimation(playerid,"MUSCULAR","Musclewalk_Csaw",4.1,0,1,1,1,1);
		}else if(animationplayed == 17) {
		ApplyAnimation(playerid,"MUSCULAR","Musclewalk_rocket",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animotb", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animotb [1-11]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 11) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animotb [1-11]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"OTB","betslp_in",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"OTB","betslp_lkabt",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"OTB","betslp_loop",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"OTB","betslp_out",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"OTB","betslp_tnk",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"OTB","wtchrace_cmon",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"OTB","wtchrace_in",4.1,0,1,1,1,1);
		}else if(animationplayed == 8) {
		ApplyAnimation(playerid,"OTB","wtchrace_loop",4.1,0,1,1,1,1);
		}else if(animationplayed == 9) {
		ApplyAnimation(playerid,"OTB","wtchrace_lose",4.1,0,1,1,1,1);
		}else if(animationplayed == 10) {
		ApplyAnimation(playerid,"OTB","wtchrace_out",4.1,0,1,1,1,1);
		}else if(animationplayed == 11) {
		ApplyAnimation(playerid,"OTB","wtchrace_win",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animnevada", true) == 0) {
		if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animnevada [1-2]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 2) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animnevada [1-2]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"NEVADA","NEVADA_getin",4.1,0,1,1,1,1);
		} else if(animationplayed == 2) {
		ApplyAnimation(playerid,"NEVADA","NEVADA_getout",4.1,0,1,1,1,1);
		}
		return 1;
		}
		}
		if(strcmp(cmd, "/animpark", true) == 0) {
		if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animpark [1-3]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 3) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animpark [1-3]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"PARK","Tai_Chi_in",4.1,0,1,1,1,1);
		} else if(animationplayed == 2) {
		ApplyAnimation(playerid,"PARK","Tai_Chi_Loop",4.1,0,1,1,1,1);
		} else if(animationplayed == 3) {
		ApplyAnimation(playerid,"PARK","Tai_Chi_Out",4.1,0,1,1,1,1);
		}
		return 1;
		}
		}
		if(strcmp(cmd, "/animpaul", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animpaul [1-12]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 12) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animpaul [1-12]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"PAULNMAC","Piss_in",4.1,0,1,1,1,1);
		} else if(animationplayed == 2) {
		ApplyAnimation(playerid,"PAULNMAC","Piss_loop",4.1,0,1,1,1,1);
		} else if(animationplayed == 3) {
		ApplyAnimation(playerid,"PAULNMAC","Piss_out",4.1,0,1,1,1,1);
		} else if(animationplayed == 4) {
		ApplyAnimation(playerid,"PAULNMAC","PnM_Argue1_A",4.1,0,1,1,1,1);
		} else if(animationplayed == 5) {
		ApplyAnimation(playerid,"PAULNMAC","PnM_Argue1_B",4.1,0,1,1,1,1);
		} else if(animationplayed == 6) {
		ApplyAnimation(playerid,"PAULNMAC","PnM_Argue2_A",4.1,0,1,1,1,1);
		} else if(animationplayed == 7) {
		ApplyAnimation(playerid,"PAULNMAC","PnM_Argue2_B",4.1,0,1,1,1,1);
		} else if(animationplayed == 8) {
		ApplyAnimation(playerid,"PAULNMAC","PnM_Loop_A",4.1,0,1,1,1,1);
		} else if(animationplayed == 9) {
		ApplyAnimation(playerid,"PAULNMAC","PnM_Loop_B",4.1,0,1,1,1,1);
		} else if(animationplayed == 10) {
		ApplyAnimation(playerid,"PAULNMAC","wank_in",4.1,0,1,1,1,1);
		} else if(animationplayed == 11) {
		ApplyAnimation(playerid,"PAULNMAC","wank_loop",4.1,0,1,1,1,1);
		} else if(animationplayed == 12) {
		ApplyAnimation(playerid,"PAULNMAC","wank_out",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animsaw", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animsaw [1-10]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 12) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animsaw [1-10]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"CHAINSAW","CSAW_1",4.1,0,1,1,1,1);
		} else if(animationplayed == 2) {
		ApplyAnimation(playerid,"CHAINSAW","CSAW_2",4.1,0,1,1,1,1);
		} else if(animationplayed == 3) {
		ApplyAnimation(playerid,"CHAINSAW","CSAW_3",4.1,0,1,1,1,1);
		} else if(animationplayed == 4) {
		ApplyAnimation(playerid,"CHAINSAW","CSAW_G",4.1,0,1,1,1,1);
		} else if(animationplayed == 5) {
		ApplyAnimation(playerid,"CHAINSAW","CSAW_Hit_1",4.1,0,1,1,1,1);
		} else if(animationplayed == 6) {
		ApplyAnimation(playerid,"CHAINSAW","CSAW_Hit_2",4.1,0,1,1,1,1);
		} else if(animationplayed == 7) {
		ApplyAnimation(playerid,"CHAINSAW","CSAW_Hit_3",4.1,0,1,1,1,1);
		} else if(animationplayed == 8) {
		ApplyAnimation(playerid,"CHAINSAW","IDLE_csaw",4.1,0,1,1,1,1);
		} else if(animationplayed == 9) {
		ApplyAnimation(playerid,"CHAINSAW","WEAPON_csaw",4.1,0,1,1,1,1);
		} else if(animationplayed == 10) {
		ApplyAnimation(playerid,"CHAINSAW","WEAPON_csawlo",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animchoppa", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animchoppa [1-18]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 18) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animchoppa [1-18]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"CHOPPA","CHOPPA_back",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"CHOPPA","CHOPPA_bunnyhop",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"CHOPPA","CHOPPA_drivebyFT",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"CHOPPA","CHOPPA_driveby_LHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"CHOPPA","CHOPPA_driveby_RHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"CHOPPA","CHOPPA_fwd",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"CHOPPA","CHOPPA_getoffBACK",4.1,0,1,1,1,1);
		}else if(animationplayed == 8) {
		ApplyAnimation(playerid,"CHOPPA","CHOPPA_getoffLHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 9) {
		ApplyAnimation(playerid,"CHOPPA","CHOPPA_getoffRHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 10) {
		ApplyAnimation(playerid,"CHOPPA","CHOPPA_jumponL",4.1,0,1,1,1,1);
		}else if(animationplayed == 11) {
		ApplyAnimation(playerid,"CHOPPA","CHOPPA_jumponR",4.1,0,1,1,1,1);
		}else if(animationplayed == 12) {
		ApplyAnimation(playerid,"CHOPPA","CHOPPA_Left",4.1,0,1,1,1,1);
		}else if(animationplayed == 13) {
		ApplyAnimation(playerid,"CHOPPA","CHOPPA_pedal",4.1,0,1,1,1,1);
		}else if(animationplayed == 14) {
		ApplyAnimation(playerid,"CHOPPA","CHOPPA_Pushes",4.1,0,1,1,1,1);
		}else if(animationplayed == 15) {
		ApplyAnimation(playerid,"CHOPPA","CHOPPA_ride",4.1,0,1,1,1,1);
		}else if(animationplayed == 16) {
		ApplyAnimation(playerid,"CHOPPA","CHOPPA_Right",4.1,0,1,1,1,1);
		}else if(animationplayed == 17) {
		ApplyAnimation(playerid,"CHOPPA","CHOPPA_sprint",4.1,0,1,1,1,1);
		}else if(animationplayed == 18) {
		ApplyAnimation(playerid,"CHOPPA","CHOPPA_Still",4.1,0,1,1,1,1);
		}
		return 1;
		}

		if(strcmp(cmd, "/animclothes", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animclothes [1-13]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 13) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animclothes [1-13]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"CLOTHES","CLO_Buy",4.1,0,1,1,1,1);
		} else if(animationplayed == 2) {
		ApplyAnimation(playerid,"CLOTHES","CLO_In",4.1,0,1,1,1,1);
		} else if(animationplayed == 3) {
		ApplyAnimation(playerid,"CLOTHES","CLO_Out",4.1,0,1,1,1,1);
		} else if(animationplayed == 4) {
		ApplyAnimation(playerid,"CLOTHES","CLO_Pose_Hat",4.1,0,1,1,1,1);
		} else if(animationplayed == 5) {
		ApplyAnimation(playerid,"CLOTHES","CLO_Pose_In",4.1,0,1,1,1,1);
		} else if(animationplayed == 6) {
		ApplyAnimation(playerid,"CLOTHES","CLO_Pose_In_O",4.1,0,1,1,1,1);
		} else if(animationplayed == 7) {
		ApplyAnimation(playerid,"CLOTHES","CLO_Pose_Legs",4.1,0,1,1,1,1);
		} else if(animationplayed == 8) {
		ApplyAnimation(playerid,"CLOTHES","CLO_Pose_Loop",4.1,0,1,1,1,1);
		} else if(animationplayed == 9) {
		ApplyAnimation(playerid,"CLOTHES","CLO_Pose_Out",4.1,0,1,1,1,1);
		} else if(animationplayed == 10) {
		ApplyAnimation(playerid,"CLOTHES","CLO_Pose_Out_O",4.1,0,1,1,1,1);
		} else if(animationplayed == 11) {
		ApplyAnimation(playerid,"CLOTHES","CLO_Pose_Shoes",4.1,0,1,1,1,1);
		} else if(animationplayed == 12) {
		ApplyAnimation(playerid,"CLOTHES","CLO_Pose_Torso",4.1,0,1,1,1,1);
		} else if(animationplayed == 13) {
		ApplyAnimation(playerid,"CLOTHES","CLO_Pose_Watch",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animcoach", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animcoach [1-6]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 6) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animcoach [1-6]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"COACH","COACH_inL",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"COACH","COACH_inR",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"COACH","COACH_opnL",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"COACH","COACH_opnR",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"COACH","COACH_outL",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"COACH","COACH_outR",4.1,0,1,1,1,1);
		}
		return 1;
		}

		if(strcmp(cmd, "/animcolt", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animcolt [1-7]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 7) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animcolt [1-7]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"COLT45","2guns_crouchfire",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"COLT45","colt45_crouchfire",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"COLT45","colt45_crouchreload",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"COLT45","colt45_fire",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"COLT45","colt45_fire_2hands",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"COLT45","colt45_reload",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"COLT45","sawnoff_reload",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animcopa", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animcopa [1-12]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 12) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animcopa[1-12]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"COP_AMBIENT","Copbrowse_in",4.1,0,1,1,1,1);
		} else if(animationplayed == 2) {
		ApplyAnimation(playerid,"COP_AMBIENT","Copbrowse_loop",4.1,0,1,1,1,1);
		} else if(animationplayed == 3) {
		ApplyAnimation(playerid,"COP_AMBIENT","Copbrowse_nod",4.1,0,1,1,1,1);
		} else if(animationplayed == 4) {
		ApplyAnimation(playerid,"COP_AMBIENT","Copbrowse_out",4.1,0,1,1,1,1);
		} else if(animationplayed == 5) {
		ApplyAnimation(playerid,"COP_AMBIENT","Copbrowse_shake",4.1,0,1,1,1,1);
		} else if(animationplayed == 6) {
		ApplyAnimation(playerid,"COP_AMBIENT","Coplook_in",4.1,0,1,1,1,1);
		} else if(animationplayed == 7) {
		ApplyAnimation(playerid,"COP_AMBIENT","Coplook_loop",4.1,0,1,1,1,1);
		} else if(animationplayed == 8) {
		ApplyAnimation(playerid,"COP_AMBIENT","Coplook_nod",4.1,0,1,1,1,1);
		} else if(animationplayed == 9) {
		ApplyAnimation(playerid,"COP_AMBIENT","Coplook_out",4.1,0,1,1,1,1);
		} else if(animationplayed == 10) {
		ApplyAnimation(playerid,"COP_AMBIENT","Coplook_shake",4.1,0,1,1,1,1);
		} else if(animationplayed == 11) {
		ApplyAnimation(playerid,"COP_AMBIENT","Coplook_think",4.1,0,1,1,1,1);
		} else if(animationplayed == 12) {
		ApplyAnimation(playerid,"COP_AMBIENT","Coplook_watch",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animcod", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animcod [1-4]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 4) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animcod [1-4]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"COP_DVBYZ","COP_Dvby_B",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"COP_DVBYZ","COP_Dvby_FT",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"COP_DVBYZ","COP_Dvby_L",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"COP_DVBYZ","COP_Dvby_R",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animcrack", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animcrack[1-9]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 9) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animcrack [1-9]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"CRACK","Bbalbat_Idle_01",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"CRACK","Bbalbat_Idle_02",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"CRACK","crckdeth1",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"CRACK","crckdeth2",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"CRACK","crckdeth3",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"CRACK","crckdeth4",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"CRACK","crckidle1",4.1,0,1,1,1,1);
		}else if(animationplayed == 8) {
		ApplyAnimation(playerid,"CRACK","crckidle2",4.1,0,1,1,1,1);
		}else if(animationplayed == 9) {
		ApplyAnimation(playerid,"CRACK","crckidle3",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animcrib", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animcrib [1-5]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 5) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animcrib [1-5]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"CRIB","CRIB_Console_Loop",4.1,0,1,1,1,1);
		} else if(animationplayed == 2) {
		ApplyAnimation(playerid,"CRIB","CRIB_Use_Switch",4.1,0,1,1,1,1);
		} else if(animationplayed == 3) {
		ApplyAnimation(playerid,"CRIB","PED_Console_Loop",4.1,0,1,1,1,1);
		} else if(animationplayed == 4) {
		ApplyAnimation(playerid,"CRIB","PED_Console_Loose",4.1,0,1,1,1,1);
		} else if(animationplayed == 5) {
		ApplyAnimation(playerid,"CRIB","PED_Console_Win",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animjump", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animjump [1-5]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 5) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animjump [1-5]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"DAM_JUMP","DAM_Dive_Loop",4.1,0,1,1,1,1);
		} else if(animationplayed == 2) {
		ApplyAnimation(playerid,"DAM_JUMP","DAM_Land",4.1,0,1,1,1,1);
		} else if(animationplayed == 3) {
		ApplyAnimation(playerid,"DAM_JUMP","DAM_Launch",4.1,0,1,1,1,1);
		} else if(animationplayed == 4) {
		ApplyAnimation(playerid,"DAM_JUMP","Jump_Roll",4.1,0,1,1,1,1);
		} else if(animationplayed == 5) {
		ApplyAnimation(playerid,"DAM_JUMP","SF_JumpWall",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animdance", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animdance [1-13]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 13) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animdance [1-13]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"DANCING","bd_clap",4.1,0,1,1,1,1);
		} else if(animationplayed == 2) {
		ApplyAnimation(playerid,"DANCING","bd_clap1",4.1,0,1,1,1,1);
		} else if(animationplayed == 3) {
		ApplyAnimation(playerid,"DANCING","dance_loop",4.1,0,1,1,1,1);
		} else if(animationplayed == 4) {
		ApplyAnimation(playerid,"DANCING","DAN_Down_A",4.1,0,1,1,1,1);
		} else if(animationplayed == 5) {
		ApplyAnimation(playerid,"DANCING","DAN_Left_A",4.1,0,1,1,1,1);
		} else if(animationplayed == 6) {
		ApplyAnimation(playerid,"DANCING","DAN_Loop_A",4.1,0,1,1,1,1);
		} else if(animationplayed == 7) {
		ApplyAnimation(playerid,"DANCING","DAN_Right_A",4.1,0,1,1,1,1);
		} else if(animationplayed == 8) {
		ApplyAnimation(playerid,"DANCING","DAN_Up_A",4.1,0,1,1,1,1);
		} else if(animationplayed == 9) {
		ApplyAnimation(playerid,"DANCING","dnce_M_a",4.1,0,1,1,1,1);
		} else if(animationplayed == 10) {
		ApplyAnimation(playerid,"DANCING","dnce_M_b",4.1,0,1,1,1,1);
		} else if(animationplayed == 11) {
		ApplyAnimation(playerid,"DANCING","dnce_M_c",4.1,0,1,1,1,1);
		} else if(animationplayed == 12) {
		ApplyAnimation(playerid,"DANCING","dnce_M_d",4.1,0,1,1,1,1);
		} else if(animationplayed == 13) {
		ApplyAnimation(playerid,"DANCING","dnce_M_e",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animdealer", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animdealer [1-7]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 7) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animdealer [1-7]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"DEALER","DEALER_DEAL",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"DEALER","DEALER_IDLE",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"DEALER","DEALER_IDLE_01",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"DEALER","DEALER_IDLE_02",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"DEALER","DEALER_IDLE_03",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"DEALER","DRUGS_BUY",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"DEALER","shop_pay",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animdildo", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animdildo [1-9]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 9) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animdildo [1-9]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"DILDO","DILDO_1",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"DILDO","DILDO_2",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"DILDO","DILDO_3",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"DILDO","DILDO_block",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"DILDO","DILDO_G",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"DILDO","DILDO_Hit_1",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"DILDO","DILDO_Hit_2",4.1,0,1,1,1,1);
		}else if(animationplayed == 8) {
		ApplyAnimation(playerid,"DILDO","DILDO_Hit_3",4.1,0,1,1,1,1);
		}else if(animationplayed == 9) {
		ApplyAnimation(playerid,"DILDO","DILDO_IDLE",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animdodge", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animdodge [1-4]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 4) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animdodge [1-4]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"DODGE","Cover_Dive_01",4.1,0,1,1,1,1);
		} else if(animationplayed == 2) {
		ApplyAnimation(playerid,"DODGE","Cover_Dive_02",4.1,0,1,1,1,1);
		} else if(animationplayed == 3) {
		ApplyAnimation(playerid,"DODGE","Crushed",4.1,0,1,1,1,1);
		} else if(animationplayed == 4) {
		ApplyAnimation(playerid,"DODGE","Crush_Jump",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animdozer", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animdozer [1-9]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 9) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animdozer [1-9]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"DOZER","DOZER_Align_LHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"DOZER","DOZER_Align_RHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"DOZER","DOZER_getin_LHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"DOZER","DOZER_getin_RHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"DOZER","DOZER_getout_LHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"DOZER","DOZER_getout_RHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"DOZER","DOZER_Jacked_LHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 8) {
		ApplyAnimation(playerid,"DOZER","DOZER_Jacked_RHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 9) {
		ApplyAnimation(playerid,"DOZER","DOZER_pullout_LHS",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animdrivebys", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animdrivebys [1-8]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 8) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animdrivebys [1-8]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"DRIVEBYS","Gang_DrivebyLHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"DRIVEBYS","Gang_DrivebyLHS_Bwd",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"DRIVEBYS","Gang_DrivebyLHS_Fwd",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"DRIVEBYS","Gang_DrivebyRHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"DRIVEBYS","Gang_DrivebyRHS_Bwd",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"DRIVEBYS","Gang_DrivebyRHS_Fwd",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"DRIVEBYS","Gang_DrivebyTop_LHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 8) {
		ApplyAnimation(playerid,"DRIVEBYS","Gang_DrivebyTop_RHS",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animfat", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animfat [1-17]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 17) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animfat [1-17]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"FAT","FatIdle",4.1,0,1,1,1,1);
		}else if(animationplayed == 1) {
		ApplyAnimation(playerid,"FAT","FatIdle_armed",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"FAT","FatIdle_Csaw",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"FAT","FatIdle_Rocket",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"FAT","FatRun",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"FAT","FatRun_armed",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"FAT","FatRun_Csaw",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"FAT","FatRun_Rocket",4.1,0,1,1,1,1);
		}else if(animationplayed == 8) {
		ApplyAnimation(playerid,"FAT","FatSprint",4.1,0,1,1,1,1);
		}else if(animationplayed == 9) {
		ApplyAnimation(playerid,"FAT","FatWalk",4.1,0,1,1,1,1);
		}else if(animationplayed == 10) {
		ApplyAnimation(playerid,"FAT","FatWalkstart",4.1,0,1,1,1,1);
		}else if(animationplayed == 11) {
		ApplyAnimation(playerid,"FAT","FatWalkstart_Csaw",4.1,0,1,1,1,1);
		}else if(animationplayed == 12) {
		ApplyAnimation(playerid,"FAT","FatWalkSt_armed",4.1,0,1,1,1,1);
		}else if(animationplayed == 13) {
		ApplyAnimation(playerid,"FAT","FatWalkSt_Rocket",4.1,0,1,1,1,1);
		}else if(animationplayed == 14) {
		ApplyAnimation(playerid,"FAT","FatWalk_armed",4.1,0,1,1,1,1);
		}else if(animationplayed == 15) {
		ApplyAnimation(playerid,"FAT","FatWalk_Csaw",4.1,0,1,1,1,1);
		}else if(animationplayed == 16) {
		ApplyAnimation(playerid,"FAT","FatWalk_Rocket",4.1,0,1,1,1,1);
		}else if(animationplayed == 17) {
		ApplyAnimation(playerid,"FAT","IDLE_tired",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animfightb", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animfightb [1-10]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 10) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animfightb [1-10]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"FIGHT_B","FightB_1",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"FIGHT_B","FightB_2",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"FIGHT_B","FightB_3",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"FIGHT_B","FightB_block",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"FIGHT_B","FightB_G",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"FIGHT_B","FightB_IDLE",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"FIGHT_B","FightB_M",4.1,0,1,1,1,1);
		}else if(animationplayed == 8) {
		ApplyAnimation(playerid,"FIGHT_B","HitB_1",4.1,0,1,1,1,1);
		}else if(animationplayed == 9) {
		ApplyAnimation(playerid,"FIGHT_B","HitB_2",4.1,0,1,1,1,1);
		}else if(animationplayed == 10) {
		ApplyAnimation(playerid,"FIGHT_B","HitB_3",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animfightc", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animfightc [1-12]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 12) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animfightc [1-12]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"FIGHT_C","FightC_1",4.1,0,1,1,1,1);
		} else if(animationplayed == 2) {
		ApplyAnimation(playerid,"FIGHT_C","FightC_2",4.1,0,1,1,1,1);
		} else if(animationplayed == 3) {
		ApplyAnimation(playerid,"FIGHT_C","FightC_3",4.1,0,1,1,1,1);
		} else if(animationplayed == 4) {
		ApplyAnimation(playerid,"FIGHT_C","FightC_block",4.1,0,1,1,1,1);
		} else if(animationplayed == 5) {
		ApplyAnimation(playerid,"FIGHT_C","FightC_blocking",4.1,0,1,1,1,1);
		} else if(animationplayed == 6) {
		ApplyAnimation(playerid,"FIGHT_C","FightC_G",4.1,0,1,1,1,1);
		} else if(animationplayed == 7) {
		ApplyAnimation(playerid,"FIGHT_C","FightC_IDLE",4.1,0,1,1,1,1);
		} else if(animationplayed == 8) {
		ApplyAnimation(playerid,"FIGHT_C","FightC_M",4.1,0,1,1,1,1);
		} else if(animationplayed == 9) {
		ApplyAnimation(playerid,"FIGHT_C","FightC_Spar",4.1,0,1,1,1,1);
		} else if(animationplayed == 10) {
		ApplyAnimation(playerid,"FIGHT_C","HitC_1",4.1,0,1,1,1,1);
		} else if(animationplayed == 11) {
		ApplyAnimation(playerid,"FIGHT_C","HitC_2",4.1,0,1,1,1,1);
		} else if(animationplayed == 12) {
		ApplyAnimation(playerid,"FIGHT_C","HitC_3",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animfightd", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animfightd [1-10]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 10) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animfightd [1-10]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"FIGHT_D","FightD_1",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"FIGHT_D","FightD_2",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"FIGHT_D","FightD_3",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"FIGHT_D","FightD_block",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"FIGHT_D","FightD_G",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"FIGHT_D","FightD_IDLE",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"FIGHT_D","FightD_M",4.1,0,1,1,1,1);
		}else if(animationplayed == 8) {
		ApplyAnimation(playerid,"FIGHT_D","HitD_1",4.1,0,1,1,1,1);
		}else if(animationplayed == 9) {
		ApplyAnimation(playerid,"FIGHT_D","HitD_2",4.1,0,1,1,1,1);
		}else if(animationplayed == 10) {
		ApplyAnimation(playerid,"FIGHT_D","HitD_3",4.1,0,1,1,1,1);
		}
		return 1;
		}

		if(strcmp(cmd, "/animfighte", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animfighte [1-4]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 4) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animfighte [1-4]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"FIGHT_E","FightKick",4.1,0,1,1,1,1);
		} else if(animationplayed == 2) {
		ApplyAnimation(playerid,"FIGHT_E","FightKick_B",4.1,0,1,1,1,1);
		} else if(animationplayed == 3) {
		ApplyAnimation(playerid,"FIGHT_E","Hit_fightkick",4.1,0,1,1,1,1);
		} else if(animationplayed == 4) {
		ApplyAnimation(playerid,"FIGHT_E","Hit_fightkick_B",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animfinale", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animfinale [1-15]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 15) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animfinale [1-15]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"FINALE","FIN_Climb_In",4.1,0,1,1,1,1);
		}else if(animationplayed == 1) {
		ApplyAnimation(playerid,"FINALE","FIN_Cop1_ClimbOut2",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"FINALE","FIN_Cop1_Loop",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"FINALE","FIN_Cop1_Stomp",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"FINALE","FIN_Hang_L",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"FINALE","FIN_Hang_Loop",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"FINALE","FIN_Hang_R",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"FINALE","FIN_Hang_L",4.1,0,1,1,1,1);
		}else if(animationplayed == 8) {
		ApplyAnimation(playerid,"FINALE","FIN_Jump_On",4.1,0,1,1,1,1);
		}else if(animationplayed == 9) {
		ApplyAnimation(playerid,"FINALE","FIN_Land_Car",4.1,0,1,1,1,1);
		}else if(animationplayed == 10) {
		ApplyAnimation(playerid,"FINALE","FIN_Land_Die",4.1,0,1,1,1,1);
		}else if(animationplayed == 11) {
		ApplyAnimation(playerid,"FINALE","FIN_LegsUp",4.1,0,1,1,1,1);
		}else if(animationplayed == 12) {
		ApplyAnimation(playerid,"FINALE","FIN_LegsUp_L",4.1,0,1,1,1,1);
		}else if(animationplayed == 13) {
		ApplyAnimation(playerid,"FINALE","FIN_LegsUp_Loop",4.1,0,1,1,1,1);
		}else if(animationplayed == 14) {
		ApplyAnimation(playerid,"FINALE","FIN_LegsUp_R",4.1,0,1,1,1,1);
		}else if(animationplayed == 15) {
		ApplyAnimation(playerid,"FINALE","FIN_Let_Go",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animfinale2", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animfinale2 [1-8]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 8) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animfinale2 [1-8]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"FINALE2","FIN_Cop1_ClimbOut",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"FINALE2","FIN_Cop1_Fall",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"FINALE2","FIN_Cop1_Loop",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"FINALE2","FIN_Cop1_Shot",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"FINALE2","FIN_Cop1_Swing",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"FINALE2","FIN_Cop2_ClimbOut",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"FINALE2","FIN_Switch_P",4.1,0,1,1,1,1);
		}else if(animationplayed == 8) {
		ApplyAnimation(playerid,"FINALE2","FIN_Switch_S",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animflamef", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animflamef [1-1]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 1) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animflamef [1-1]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"FLAME","FLAME_fire",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animflowers", true) == 0) {
		if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animflowers [1-3]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 3) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animflowers [1-3]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"Flowers","Flower_attack",4.1,0,1,1,1,1);
		} else if(animationplayed == 2) {
		ApplyAnimation(playerid,"Flowers","Flower_attack_M",4.1,0,1,1,1,1);
		} else if(animationplayed == 3) {
		ApplyAnimation(playerid,"Flowers","Flower_Hit",4.1,0,1,1,1,1);
		}
		return 1;
		}
		}
		if(strcmp(cmd, "/animghands", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animghands [1-20]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 20) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animghands [1-20]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"GHANDS","gsign1",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"GHANDS","gsign1LH",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"GHANDS","gsign2",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"GHANDS","gsign2LH",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"GHANDS","gsign3",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"GHANDS","gsign3LH",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"GHANDS","gsign4",4.1,0,1,1,1,1);
		}else if(animationplayed == 8) {
		ApplyAnimation(playerid,"GHANDS","gsign4LH",4.1,0,1,1,1,1);
		}else if(animationplayed == 9) {
		ApplyAnimation(playerid,"GHANDS","gsign5",4.1,0,1,1,1,1);
		}else if(animationplayed == 10) {
		ApplyAnimation(playerid,"GHANDS","gsign5LH",4.1,0,1,1,1,1);
		}else if(animationplayed == 11) {
		ApplyAnimation(playerid,"GHANDS","LHGsign1",4.1,0,1,1,1,1);
		}else if(animationplayed == 12) {
		ApplyAnimation(playerid,"GHANDS","LHGsign2",4.1,0,1,1,1,1);
		}else if(animationplayed == 13) {
		ApplyAnimation(playerid,"GHANDS","LHGsign3",4.1,0,1,1,1,1);
		}else if(animationplayed == 14) {
		ApplyAnimation(playerid,"GHANDS","LHGsign4",4.1,0,1,1,1,1);
		}else if(animationplayed == 15) {
		ApplyAnimation(playerid,"GHANDS","LHGsign5",4.1,0,1,1,1,1);
		}else if(animationplayed == 16) {
		ApplyAnimation(playerid,"GHANDS","RHGsign1",4.1,0,1,1,1,1);
		}else if(animationplayed == 17) {
		ApplyAnimation(playerid,"GHANDS","RHGsign2",4.1,0,1,1,1,1);
		}else if(animationplayed == 18) {
		ApplyAnimation(playerid,"GHANDS","RHGsign3",4.1,0,1,1,1,1);
		}else if(animationplayed == 19) {
		ApplyAnimation(playerid,"GHANDS","RHGsign4",4.1,0,1,1,1,1);
		}else if(animationplayed == 20) {
		ApplyAnimation(playerid,"GHANDS","RHGsign5",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animfw", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animfw [1-9]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 9) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animfw [1-9]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"Freeweights","gym_barbell",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"Freeweights","gym_free_A",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"Freeweights","gym_free_B",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"Freeweights","gym_free_celebrate",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"Freeweights","gym_free_down",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"Freeweights","gym_free_loop",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"Freeweights","gym_free_pickup",4.1,0,1,1,1,1);
		}else if(animationplayed == 8) {
		ApplyAnimation(playerid,"Freeweights","gym_free_putdown",4.1,0,1,1,1,1);
		}else if(animationplayed == 9) {
		ApplyAnimation(playerid,"Freeweights","gym_free_up_smooth",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animghetto", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animghetto [1-7]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 7) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animghetto [1-7]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"GHETTO_DB","GDB_Car2_PLY",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"GHETTO_DB","GDB_Car2_SMO",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"GHETTO_DB","GDB_Car2_SWE",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"GHETTO_DB","GDB_Car_PLY",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"GHETTO_DB","GDB_Car_RYD",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"GHETTO_DB","GDB_Car_SMO",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"GHETTO_DB","GDB_Car_SWE",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animgog", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animgog [1-1]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 1) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animgog [1-1]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"goggles","goggles_put_on",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animgraffity", true) == 0) {
		if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animgraffity [1-2]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 2) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animgraffity [1-2]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"GRAFFITI","graffiti_Chkout",4.1,0,1,1,1,1);
		} else if(animationplayed == 2) {
		ApplyAnimation(playerid,"GRAFFITI","spraycan_fire",4.1,0,1,1,1,1);
		}
		return 1;
		}
		}
		if(strcmp(cmd, "/animgreya", true) == 0) {
		if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animgreya [1-3]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 3) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animgreya [1-3]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"GRAVEYARD","mrnF_loop",4.1,0,1,1,1,1);
		} else if(animationplayed == 2) {
		ApplyAnimation(playerid,"GRAVEYARD","mrnM_loop",4.1,0,1,1,1,1);
		} else if(animationplayed == 3) {
		ApplyAnimation(playerid,"GRAVEYARD","prst_loopa",4.1,0,1,1,1,1);
		}
		return 1;
		}
		}
		if(strcmp(cmd, "/animgren", true) == 0) {
		if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animgren [1-3]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 3) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animgren [1-3]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"GRENADE","WEAPON_start_throw",4.1,0,1,1,1,1);
		} else if(animationplayed == 2) {
		ApplyAnimation(playerid,"GRENADE","WEAPON_throw",4.1,0,1,1,1,1);
		} else if(animationplayed == 3) {
		ApplyAnimation(playerid,"GRENADE","WEAPON_throwu",4.1,0,1,1,1,1);
		}
		return 1;
		}
		}
		if(strcmp(cmd, "/animhaircut", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animhaircut [1-13]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 13) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animhaircut [1-13]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"HAIRCUTS","BRB_Beard_01",4.1,0,1,1,1,1);
		} else if(animationplayed == 2) {
		ApplyAnimation(playerid,"HAIRCUTS","BRB_Buy",4.1,0,1,1,1,1);
		} else if(animationplayed == 3) {
		ApplyAnimation(playerid,"HAIRCUTS","BRB_Cut",4.1,0,1,1,1,1);
		} else if(animationplayed == 4) {
		ApplyAnimation(playerid,"HAIRCUTS","BRB_Cut_In",4.1,0,1,1,1,1);
		} else if(animationplayed == 5) {
		ApplyAnimation(playerid,"HAIRCUTS","BRB_Cut_Out",4.1,0,1,1,1,1);
		} else if(animationplayed == 6) {
		ApplyAnimation(playerid,"HAIRCUTS","BRB_Hair_01",4.1,0,1,1,1,1);
		} else if(animationplayed == 7) {
		ApplyAnimation(playerid,"HAIRCUTS","BRB_Hair_02",4.1,0,1,1,1,1);
		} else if(animationplayed == 8) {
		ApplyAnimation(playerid,"HAIRCUTS","BRB_In",4.1,0,1,1,1,1);
		} else if(animationplayed == 9) {
		ApplyAnimation(playerid,"HAIRCUTS","BRB_Out",4.1,0,1,1,1,1);
		} else if(animationplayed == 10) {
		ApplyAnimation(playerid,"HAIRCUTS","BRB_Loop",4.1,0,1,1,1,1);
		} else if(animationplayed == 11) {
		ApplyAnimation(playerid,"HAIRCUTS","BRB_Sit_In",4.1,0,1,1,1,1);
		} else if(animationplayed == 12) {
		ApplyAnimation(playerid,"HAIRCUTS","BRB_Sit_Loop",4.1,0,1,1,1,1);
		} else if(animationplayed == 13) {
		ApplyAnimation(playerid,"HAIRCUTS","BRB_Sit_Out",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animheist", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animheist [1-10]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 10) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animheist [1-10]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"HEIST9","CAS_G2_GasKO",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"HEIST9","swt_wllpk_L",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"HEIST9","swt_wllpk_L_back",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"HEIST9","swt_wllpk_R",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"HEIST9","swt_wllpk_R_back",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"HEIST9","swt_wllshoot_in_L",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"HEIST9","swt_wllshoot_in_R",4.1,0,1,1,1,1);
		}else if(animationplayed == 8) {
		ApplyAnimation(playerid,"HEIST9","swt_wllshoot_out_L",4.1,0,1,1,1,1);
		}else if(animationplayed == 9) {
		ApplyAnimation(playerid,"HEIST9","swt_wllshoot_out_R",4.1,0,1,1,1,1);
		}else if(animationplayed == 10) {
		ApplyAnimation(playerid,"HEIST9","Use_SwipeCard",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animinthouse", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animinthouse [1-10]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 10) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animinthouse [1-10]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"INT_HOUSE","BED_In_L",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"INT_HOUSE","BED_In_R",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"INT_HOUSE","BED_Loop_L",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"INT_HOUSE","BED_Loop_R",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"INT_HOUSE","BED_Out_L",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"INT_HOUSE","BED_Out_R",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"INT_HOUSE","LOU_In",4.1,0,1,1,1,1);
		}else if(animationplayed == 8) {
		ApplyAnimation(playerid,"INT_HOUSE","LOU_Loop",4.1,0,1,1,1,1);
		}else if(animationplayed == 9) {
		ApplyAnimation(playerid,"INT_HOUSE","LOU_Out",4.1,0,1,1,1,1);
		}else if(animationplayed == 10) {
		ApplyAnimation(playerid,"INT_HOUSE","wash_up",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animintoffice", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animintoffice [1-10]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 10) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animintoffice [1-10]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"INT_OFFICE","FF_Dam_Fwd",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"INT_OFFICE","OFF_Sit_2Idle_180",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"INT_OFFICE","OFF_Sit_Bored_Loop",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"INT_OFFICE","OFF_Sit_Crash",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"INT_OFFICE","OFF_Sit_Drink",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"INT_OFFICE","OFF_Sit_Idle_Loop",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"INT_OFFICE","OFF_Sit_In",4.1,0,1,1,1,1);
		}else if(animationplayed == 8) {
		ApplyAnimation(playerid,"INT_OFFICE","OFF_Sit_Read",4.1,0,1,1,1,1);
		}else if(animationplayed == 9) {
		ApplyAnimation(playerid,"INT_OFFICE","OFF_Sit_Type_Loop",4.1,0,1,1,1,1);
		}else if(animationplayed == 10) {
		ApplyAnimation(playerid,"INT_OFFICE","OFF_Sit_Watch",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animplayerdbf", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animplayerdbf [1-4]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 4) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animplayerdbf [1-4]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"PLAYER_DVBYS","Plyr_DrivebyBwd",4.1,0,1,1,1,1);
		} else if(animationplayed == 2) {
		ApplyAnimation(playerid,"PLAYER_DVBYS","Plyr_DrivebyFwd",4.1,0,1,1,1,1);
		} else if(animationplayed == 3) {
		ApplyAnimation(playerid,"PLAYER_DVBYS","Plyr_DrivebyLHS",4.1,0,1,1,1,1);
		} else if(animationplayed == 4) {
		ApplyAnimation(playerid,"PLAYER_DVBYS","Plyr_DrivebyRHS",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animplayidles", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animplayidles [1-5]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 5) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animplayidles [1-5]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"PLAYIDLES","shift",4.1,0,1,1,1,1);
		} else if(animationplayed == 2) {
		ApplyAnimation(playerid,"PLAYIDLES","shldr",4.1,0,1,1,1,1);
		} else if(animationplayed == 3) {
		ApplyAnimation(playerid,"PLAYIDLES","stretch",4.1,0,1,1,1,1);
		} else if(animationplayed == 4) {
		ApplyAnimation(playerid,"PLAYIDLES","strleg",4.1,0,1,1,1,1);
		} else if(animationplayed == 5) {
		ApplyAnimation(playerid,"PLAYIDLES","time",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animpolice", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animpolice [1-10]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 10) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animpolice [1-10]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"POLICE","CopTraf_Away",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"POLICE","CopTraf_Come",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"POLICE","CopTraf_Left",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"POLICE","CopTraf_Stop",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"POLICE","COP_getoutcar_LHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"POLICE","Cop_move_FWD",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"POLICE","crm_drgbst_01",4.1,0,1,1,1,1);
		}else if(animationplayed == 8) {
		ApplyAnimation(playerid,"POLICE","Door_Kick",4.1,0,1,1,1,1);
		}else if(animationplayed == 9) {
		ApplyAnimation(playerid,"POLICE","plc_drgbst_01",4.1,0,1,1,1,1);
		}else if(animationplayed == 10) {
		ApplyAnimation(playerid,"POLICE","plc_drgbst_02",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animpool", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animpool [1-21]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 21) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animpool [1-21]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"POOL","POOL_ChalkCue",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"POOL","POOL_Idle_Stance",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"POOL","POOL_Long_Shot",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"POOL","POOL_Long_Shot_O",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"POOL","POOL_Long_Start",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"POOL","POOL_Long_Start_O",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"POOL","POOL_Med_Shot",4.1,0,1,1,1,1);
		}else if(animationplayed == 8) {
		ApplyAnimation(playerid,"POOL","POOL_Med_Shot_O",4.1,0,1,1,1,1);
		}else if(animationplayed == 9) {
		ApplyAnimation(playerid,"POOL","POOL_Med_Start",4.1,0,1,1,1,1);
		}else if(animationplayed == 10) {
		ApplyAnimation(playerid,"POOL","POOL_Med_Start_O",4.1,0,1,1,1,1);
		}else if(animationplayed == 11) {
		ApplyAnimation(playerid,"POOL","POOL_Place_White",4.1,0,1,1,1,1);
		}else if(animationplayed == 12) {
		ApplyAnimation(playerid,"POOL","POOL_Short_Shot",4.1,0,1,1,1,1);
		}else if(animationplayed == 13) {
		ApplyAnimation(playerid,"POOL","POOL_Short_Shot_O",4.1,0,1,1,1,1);
		}else if(animationplayed == 14) {
		ApplyAnimation(playerid,"POOL","POOL_Short_Start",4.1,0,1,1,1,1);
		}else if(animationplayed == 15) {
		ApplyAnimation(playerid,"POOL","POOL_Short_Start_O",4.1,0,1,1,1,1);
		}else if(animationplayed == 16) {
		ApplyAnimation(playerid,"POOL","POOL_Walk",4.1,0,1,1,1,1);
		}else if(animationplayed == 17) {
		ApplyAnimation(playerid,"POOL","POOL_Walk_Start",4.1,0,1,1,1,1);
		}else if(animationplayed == 18) {
		ApplyAnimation(playerid,"POOL","POOL_XLong_Shot",4.1,0,1,1,1,1);
		}else if(animationplayed == 19) {
		ApplyAnimation(playerid,"POOL","POOL_XLong_Shot_O",4.1,0,1,1,1,1);
		}else if(animationplayed == 20) {
		ApplyAnimation(playerid,"POOL","POOL_XLong_Start",4.1,0,1,1,1,1);
		}else if(animationplayed == 21) {
		ApplyAnimation(playerid,"POOL","POOL_XLong_Start_O",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animpoor", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animpoor [1-2]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 2) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animpoor [1-2]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"POOR","WINWASH_Start",4.1,0,1,1,1,1);
		}else if(animationplayed == 1) {
		ApplyAnimation(playerid,"POOR","WINWASH_Wash2Beg",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animpython", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animpython [1-5]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 5) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animpython [1-5]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"PYTHON","python_crouchfire",4.1,0,1,1,1,1);
		} else if(animationplayed == 2) {
		ApplyAnimation(playerid,"PYTHON","python_crouchreload",4.1,0,1,1,1,1);
		} else if(animationplayed == 3) {
		ApplyAnimation(playerid,"PYTHON","python_fire",4.1,0,1,1,1,1);
		} else if(animationplayed == 4) {
		ApplyAnimation(playerid,"PYTHON","python_fire_poor",4.1,0,1,1,1,1);
		} else if(animationplayed == 5) {
		ApplyAnimation(playerid,"PYTHON","python_reload",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animquad", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animquad [1-17]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 17) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animquad [1-17]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"QUAD","QUAD_back",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"QUAD","QUAD_driveby_FT",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"QUAD","QUAD_driveby_LHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"QUAD","QUAD_driveby_RHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"QUAD","QUAD_FWD",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"QUAD","QUAD_getoff_B",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"QUAD","QUAD_getoff_LHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 8) {
		ApplyAnimation(playerid,"QUAD","QUAD_getoff_RHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 9) {
		ApplyAnimation(playerid,"QUAD","QUAD_geton_LHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 10) {
		ApplyAnimation(playerid,"QUAD","QUAD_geton_RHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 11) {
		ApplyAnimation(playerid,"QUAD","QUAD_hit",4.1,0,1,1,1,1);
		}else if(animationplayed == 12) {
		ApplyAnimation(playerid,"QUAD","QUAD_kick",4.1,0,1,1,1,1);
		}else if(animationplayed == 13) {
		ApplyAnimation(playerid,"QUAD","QUAD_Left",4.1,0,1,1,1,1);
		}else if(animationplayed == 14) {
		ApplyAnimation(playerid,"QUAD","QUAD_passenger",4.1,0,1,1,1,1);
		}else if(animationplayed == 15) {
		ApplyAnimation(playerid,"QUAD","QUAD_reverse",4.1,0,1,1,1,1);
		}else if(animationplayed == 16) {
		ApplyAnimation(playerid,"QUAD","QUAD_ride",4.1,0,1,1,1,1);
		}else if(animationplayed == 17) {
		ApplyAnimation(playerid,"QUAD","QUAD_Right",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animquadbz", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animquadbz [1-4]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 4) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animquadbz [1-4]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"QUAD_DBZ","Pass_Driveby_BWD",4.1,0,1,1,1,1);
		} else if(animationplayed == 2) {
		ApplyAnimation(playerid,"QUAD_DBZ","Pass_Driveby_FWD",4.1,0,1,1,1,1);
		} else if(animationplayed == 3) {
		ApplyAnimation(playerid,"QUAD_DBZ","Pass_Driveby_LHS",4.1,0,1,1,1,1);
		} else if(animationplayed == 4) {
		ApplyAnimation(playerid,"QUAD_DBZ","Pass_Driveby_RHS",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animrapping", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animrapping [1-8]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 8) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animrapping [1-8]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"RAPPING","Laugh_01",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"RAPPING","RAP_A_IN",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"RAPPING","RAP_A_Loop",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"RAPPING","RAP_A_OUT",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"RAPPING","RAP_B_IN",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"RAPPING","RAP_B_Loop",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"RAPPING","RAP_B_OUT",4.1,0,1,1,1,1);
		}else if(animationplayed == 8) {
		ApplyAnimation(playerid,"RAPPING","RAP_C_Loop",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animrifle", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animrifle [1-5]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 5) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animrifle [1-5]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"RIFLE","RIFLE_crouchfire",4.1,0,1,1,1,1);
		} else if(animationplayed == 2) {
		ApplyAnimation(playerid,"RIFLE","RIFLE_crouchload",4.1,0,1,1,1,1);
		} else if(animationplayed == 3) {
		ApplyAnimation(playerid,"RIFLE","RIFLE_fire",4.1,0,1,1,1,1);
		} else if(animationplayed == 4) {
		ApplyAnimation(playerid,"RIFLE","RIFLE_fire_poor",4.1,0,1,1,1,1);
		} else if(animationplayed == 5) {
		ApplyAnimation(playerid,"RIFLE","RIFLE_load",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animriot", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animriot [1-7]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 7) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animriot [1-7]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"RIOT","RIOT_ANGRY",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"RIOT","RIOT_ANGRY_B",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"RIOT","RIOT_challenge",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"RIOT","RIOT_CHANT",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"RIOT","RIOT_FUKU",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"RIOT","RIOT_PUNCHES",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"RIOT","RIOT_shout",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animrobbank", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animrobbank [1-5]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 5) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animrobbank [1-5]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"ROB_BANK","CAT_Safe_End",4.1,0,1,1,1,1);
		} else if(animationplayed == 2) {
		ApplyAnimation(playerid,"ROB_BANK","CAT_Safe_Open",4.1,0,1,1,1,1);
		} else if(animationplayed == 3) {
		ApplyAnimation(playerid,"ROB_BANK","CAT_Safe_Open_O",4.1,0,1,1,1,1);
		} else if(animationplayed == 4) {
		ApplyAnimation(playerid,"ROB_BANK","CAT_Safe_Rob",4.1,0,1,1,1,1);
		} else if(animationplayed == 5) {
		ApplyAnimation(playerid,"ROB_BANK","SHP_HandsUp_Scr",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animrocket", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animrocket [1-5]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 5) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animrocket [1-5]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"ROCKET","idle_rocket",4.1,0,1,1,1,1);
		} else if(animationplayed == 2) {
		ApplyAnimation(playerid,"ROCKET","RocketFire",4.1,0,1,1,1,1);
		} else if(animationplayed == 3) {
		ApplyAnimation(playerid,"ROCKET","run_rocket",4.1,0,1,1,1,1);
		} else if(animationplayed == 4) {
		ApplyAnimation(playerid,"ROCKET","walk_rocket",4.1,0,1,1,1,1);
		} else if(animationplayed == 5) {
		ApplyAnimation(playerid,"ROCKET","WALK_start_rocket",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animrustler", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animrustler [1-5]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 5) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animrustler [1-5]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"RUSTLER","Plane_align_LHS",4.1,0,1,1,1,1);
		} else if(animationplayed == 2) {
		ApplyAnimation(playerid,"RUSTLER","Plane_close",4.1,0,1,1,1,1);
		} else if(animationplayed == 3) {
		ApplyAnimation(playerid,"RUSTLER","Plane_getin",4.1,0,1,1,1,1);
		} else if(animationplayed == 4) {
		ApplyAnimation(playerid,"RUSTLER","Plane_getout",4.1,0,1,1,1,1);
		} else if(animationplayed == 5) {
		ApplyAnimation(playerid,"RUSTLER","Plane_open",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animbiked", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animbiked [1-18]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 18) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animbiked [1-18]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"BIKED","BIKEd_Back",4.1,0,1,1,1,1);
		}else if(animationplayed == 1) {
		ApplyAnimation(playerid,"BIKED","BIKEd_drivebyFT",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"BIKED","BIKEd_drivebyLHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"BIKED","BIKEd_drivebyRHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"BIKED","BIKEd_Fwd",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"BIKED","BIKEd_getoffBACK",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"BIKED","BIKEd_getoffLHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"BIKED","BIKEd_getoffRHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 8) {
		ApplyAnimation(playerid,"BIKED","BIKEd_hit",4.1,0,1,1,1,1);
		}else if(animationplayed == 9) {
		ApplyAnimation(playerid,"BIKED","BIKEd_jumponL",4.1,0,1,1,1,1);
		}else if(animationplayed == 10) {
		ApplyAnimation(playerid,"BIKED","BIKEd_jumponR",4.1,0,1,1,1,1);
		}else if(animationplayed == 11) {
		ApplyAnimation(playerid,"BIKED","BIKEd_kick",4.1,0,1,1,1,1);
		}else if(animationplayed == 12) {
		ApplyAnimation(playerid,"BIKED","BIKEd_Left",4.1,0,1,1,1,1);
		}else if(animationplayed == 13) {
		ApplyAnimation(playerid,"BIKED","BIKEd_passenger",4.1,0,1,1,1,1);
		}else if(animationplayed == 14) {
		ApplyAnimation(playerid,"BIKED","BIKEd_pushes",4.1,0,1,1,1,1);
		}else if(animationplayed == 15) {
		ApplyAnimation(playerid,"BIKED","BIKEd_Ride",4.1,0,1,1,1,1);
		}else if(animationplayed == 16) {
		ApplyAnimation(playerid,"BIKED","BIKEd_Right",4.1,0,1,1,1,1);
		}else if(animationplayed == 17) {
		ApplyAnimation(playerid,"BIKED","BIKEd_shuffle",4.1,0,1,1,1,1);
		}else if(animationplayed == 18) {
		ApplyAnimation(playerid,"BIKED","BIKEd_Still",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animryder", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animryder [1-14]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 14) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animryder [1-14]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"RYDER","RYD_Beckon_01",4.1,0,1,1,1,1);
		}else if(animationplayed == 1) {
		ApplyAnimation(playerid,"RYDER","RYD_Beckon_02",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"RYDER","RYD_Beckon_03",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"RYDER","RYD_Die_PT1",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"RYDER","RYD_Die_PT2",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"RYDER","Van_Crate_L",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"RYDER","Van_Crate_R",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"RYDER","Van_Fall_L",4.1,0,1,1,1,1);
		}else if(animationplayed == 8) {
		ApplyAnimation(playerid,"RYDER","Van_Fall_R",4.1,0,1,1,1,1);
		}else if(animationplayed == 9) {
		ApplyAnimation(playerid,"RYDER","Van_Lean_L",4.1,0,1,1,1,1);
		}else if(animationplayed == 10) {
		ApplyAnimation(playerid,"RYDER","Van_Lean_R",4.1,0,1,1,1,1);
		}else if(animationplayed == 11) {
		ApplyAnimation(playerid,"RYDER","VAN_PickUp_S",4.1,0,1,1,1,1);
		}else if(animationplayed == 12) {
		ApplyAnimation(playerid,"RYDER","Van_Stand",4.1,0,1,1,1,1);
		}else if(animationplayed == 13) {
		ApplyAnimation(playerid,"RYDER","Van_Stand_Crate",4.1,0,1,1,1,1);
		}else if(animationplayed == 14) {
		ApplyAnimation(playerid,"RYDER","Van_Throw",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animscrat", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animscrat [1-12]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 12) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animscrat [1-12]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"SCRATCHING","scdldlp",4.1,0,1,1,1,1);
		} else if(animationplayed == 2) {
		ApplyAnimation(playerid,"SCRATCHING","scdlulp",4.1,0,1,1,1,1);
		} else if(animationplayed == 3) {
		ApplyAnimation(playerid,"SCRATCHING","scdrdlp",4.1,0,1,1,1,1);
		} else if(animationplayed == 4) {
		ApplyAnimation(playerid,"SCRATCHING","scdrulp",4.1,0,1,1,1,1);
		} else if(animationplayed == 5) {
		ApplyAnimation(playerid,"SCRATCHING","sclng_l",4.1,0,1,1,1,1);
		} else if(animationplayed == 6) {
		ApplyAnimation(playerid,"SCRATCHING","sclng_r",4.1,0,1,1,1,1);
		} else if(animationplayed == 7) {
		ApplyAnimation(playerid,"SCRATCHING","scmid_l",4.1,0,1,1,1,1);
		} else if(animationplayed == 8) {
		ApplyAnimation(playerid,"SCRATCHING","scmid_r",4.1,0,1,1,1,1);
		} else if(animationplayed == 9) {
		ApplyAnimation(playerid,"SCRATCHING","scshrtl",4.1,0,1,1,1,1);
		} else if(animationplayed == 10) {
		ApplyAnimation(playerid,"SCRATCHING","scshrtr",4.1,0,1,1,1,1);
		} else if(animationplayed == 11) {
		ApplyAnimation(playerid,"SCRATCHING","sc_ltor",4.1,0,1,1,1,1);
		} else if(animationplayed == 12) {
		ApplyAnimation(playerid,"SCRATCHING","sc_rtol",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animshamal", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animshamal [1-4]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 4) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animshamal [1-4]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"SHAMAL","SHAMAL_align",4.1,0,1,1,1,1);
		} else if(animationplayed == 2) {
		ApplyAnimation(playerid,"SHAMAL","SHAMAL_getin_LHS",4.1,0,1,1,1,1);
		} else if(animationplayed == 3) {
		ApplyAnimation(playerid,"SHAMAL","SHAMAL_getout_LHS",4.1,0,1,1,1,1);
		} else if(animationplayed == 4) {
		ApplyAnimation(playerid,"SHAMAL","SHAMAL_open",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animshop", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animshop [1-24]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 24) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animshop [1-24]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"SHOP","ROB_2Idle",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"SHOP","ROB_Loop",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"SHOP","donutdrop",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"SHOP","ROB_Loop_Threat",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"SHOP","ROB_Shifty",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"SHOP","ROB_StickUp_In",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"SHOP","SHP_Duck_Fire",4.1,0,1,1,1,1);
		}else if(animationplayed == 8) {
		ApplyAnimation(playerid,"SHOP","SHP_Gun_Aim",4.1,0,1,1,1,1);
		}else if(animationplayed == 9) {
		ApplyAnimation(playerid,"SHOP","SHP_Gun_Duck",4.1,0,1,1,1,1);
		}else if(animationplayed == 10) {
		ApplyAnimation(playerid,"SHOP","SHP_Gun_Fire",4.1,0,1,1,1,1);
		}else if(animationplayed == 11) {
		ApplyAnimation(playerid,"SHOP","SHP_Gun_Grab",4.1,0,1,1,1,1);
		}else if(animationplayed == 12) {
		ApplyAnimation(playerid,"SHOP","SHP_Gun_Threat",4.1,0,1,1,1,1);
		}else if(animationplayed == 13) {
		ApplyAnimation(playerid,"SHOP","SHP_HandsUp_Scr",4.1,0,1,1,1,1);
		}else if(animationplayed == 14) {
		ApplyAnimation(playerid,"SHOP","SHP_Jump_Glide",4.1,0,1,1,1,1);
		}else if(animationplayed == 15) {
		ApplyAnimation(playerid,"SHOP","SHP_Jump_Land",4.1,0,1,1,1,1);
		}else if(animationplayed == 16) {
		ApplyAnimation(playerid,"SHOP","SHP_Jump_Launch",4.1,0,1,1,1,1);
		}else if(animationplayed == 17) {
		ApplyAnimation(playerid,"SHOP","SHP_Rob_GiveCash",4.1,0,1,1,1,1);
		}else if(animationplayed == 18) {
		ApplyAnimation(playerid,"SHOP","SHP_Rob_HandsUp",4.1,0,1,1,1,1);
		}else if(animationplayed == 19) {
		ApplyAnimation(playerid,"SHOP","SHP_Rob_React",4.1,0,1,1,1,1);
		}else if(animationplayed == 20) {
		ApplyAnimation(playerid,"SHOP","SHP_Serve_End",4.1,0,1,1,1,1);
		}else if(animationplayed == 21) {
		ApplyAnimation(playerid,"SHOP","SHP_Serve_Idle",4.1,0,1,1,1,1);
		}else if(animationplayed == 22) {
		ApplyAnimation(playerid,"SHOP","SHP_Serve_Loop",4.1,0,1,1,1,1);
		}else if(animationplayed == 23) {
		ApplyAnimation(playerid,"SHOP","SHP_Serve_Start",4.1,0,1,1,1,1);
		}else if(animationplayed == 24) {
		ApplyAnimation(playerid,"SHOP","Smoke_RYD",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animshotgun", true) == 0) {
		if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animshotgun [1-3]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 3) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animshotgun [1-3]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"SHOTGUN","shotgun_crouchfire",4.1,0,1,1,1,1);
		} else if(animationplayed == 2) {
		ApplyAnimation(playerid,"SHOTGUN","shotgun_fire",4.1,0,1,1,1,1);
		} else if(animationplayed == 3) {
		ApplyAnimation(playerid,"SHOTGUN","shotgun_fire_poor",4.1,0,1,1,1,1);
		}
		return 1;
		}
		}
		if(strcmp(cmd, "/animskate", true) == 0) {
		if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animskate [1-3]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 3) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animskate [1-3]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"SKATE","skate_idle",4.1,0,1,1,1,1);
		} else if(animationplayed == 2) {
		ApplyAnimation(playerid,"SKATE","skate_run",4.1,0,1,1,1,1);
		} else if(animationplayed == 3) {
		ApplyAnimation(playerid,"SKATE","skate_sprint",4.1,0,1,1,1,1);
		}
		return 1;
		}
		}
		if(strcmp(cmd, "/animvortex", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animvortex [1-4]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 4) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animvortex [1-4]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"VORTEX","CAR_jumpin_LHS",4.1,0,1,1,1,1);
		} else if(animationplayed == 2) {
		ApplyAnimation(playerid,"VORTEX","CAR_jumpin_RHS",4.1,0,1,1,1,1);
		} else if(animationplayed == 3) {
		ApplyAnimation(playerid,"VORTEX","vortex_getout_LHS",4.1,0,1,1,1,1);
		} else if(animationplayed == 4) {
		ApplyAnimation(playerid,"VORTEX","vortex_getout_RHS",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animtec", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animtec [1-4]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 4) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animtec [1-4]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"TEC","TEC_crouchfire",4.1,0,1,1,1,1);
		} else if(animationplayed == 2) {
		ApplyAnimation(playerid,"TEC","TEC_crouchreload",4.1,0,1,1,1,1);
		} else if(animationplayed == 3) {
		ApplyAnimation(playerid,"TEC","TEC_fire",4.1,0,1,1,1,1);
		} else if(animationplayed == 4) {
		ApplyAnimation(playerid,"TEC","TEC_reload",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animtrain", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animtrain [1-4]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 4) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animtrain [1-4]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"TRAIN","tran_gtup",4.1,0,1,1,1,1);
		} else if(animationplayed == 2) {
		ApplyAnimation(playerid,"TRAIN","tran_hng",4.1,0,1,1,1,1);
		} else if(animationplayed == 3) {
		ApplyAnimation(playerid,"TRAIN","tran_ouch",4.1,0,1,1,1,1);
		} else if(animationplayed == 4) {
		ApplyAnimation(playerid,"TRAIN","tran_stmb",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animsil", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animsil [1-4]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 4) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animsil [1-4]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"SILENCED","CrouchReload",4.1,0,1,1,1,1);
		} else if(animationplayed == 2) {
		ApplyAnimation(playerid,"SILENCED","SilenceCrouchfire",4.1,0,1,1,1,1);
		} else if(animationplayed == 3) {
		ApplyAnimation(playerid,"SILENCED","Silence_fire",4.1,0,1,1,1,1);
		} else if(animationplayed == 4) {
		ApplyAnimation(playerid,"SILENCED","Silence_reload",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animtattoo", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animtattoo [1-56]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 56) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animtattoo [1-56]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"TATTOOS","TAT_ArmL_In_O",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"TATTOOS","TAT_ArmL_In_P",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"TATTOOS","TAT_ArmL_In_T",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"TATTOOS","TAT_ArmL_Out_O",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"TATTOOS","TA_ArmL_Out_P",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"TATTOOS","TAT_ArmL_Out_T",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"TATTOOS","TAT_ArmL_Pose_O",4.1,0,1,1,1,1);
		}else if(animationplayed == 8) {
		ApplyAnimation(playerid,"TATTOOS","TAT_ArmL_Pose_P",4.1,0,1,1,1,1);
		}else if(animationplayed == 9) {
		ApplyAnimation(playerid,"TATTOOS","TAT_ArmL_Pose_T",4.1,0,1,1,1,1);
		}else if(animationplayed == 10) {
		ApplyAnimation(playerid,"TATTOOS","TAT_ArmR_In_O",4.1,0,1,1,1,1);
		}else if(animationplayed == 11) {
		ApplyAnimation(playerid,"TATTOOS","TAT_ArmR_In_P",4.1,0,1,1,1,1);
		}else if(animationplayed == 12) {
		ApplyAnimation(playerid,"TATTOOS","TAT_ArmR_In_T",4.1,0,1,1,1,1);
		}else if(animationplayed == 13) {
		ApplyAnimation(playerid,"TATTOOS","TAT_ArmR_Out_O",4.1,0,1,1,1,1);
		}else if(animationplayed == 14) {
		ApplyAnimation(playerid,"TATTOOS","TAT_ArmR_Out_P",4.1,0,1,1,1,1);
		}else if(animationplayed == 15) {
		ApplyAnimation(playerid,"TATTOOS","TAT_ArmR_Out_T",4.1,0,1,1,1,1);
		}else if(animationplayed == 16) {
		ApplyAnimation(playerid,"TATTOOS","TAT_ArmR_Pose_O",4.1,0,1,1,1,1);
		}else if(animationplayed == 17) {
		ApplyAnimation(playerid,"TATTOOS","TAT_ArmR_Pose_P",4.1,0,1,1,1,1);
		}else if(animationplayed == 18) {
		ApplyAnimation(playerid,"TATTOOS","TAT_ArmR_Pose_T",4.1,0,1,1,1,1);
		}else if(animationplayed == 19) {
		ApplyAnimation(playerid,"TATTOOS","TAT_Back_In_O",4.1,0,1,1,1,1);
		}else if(animationplayed == 20) {
		ApplyAnimation(playerid,"TATTOOS","TAT_Back_In_P",4.1,0,1,1,1,1);
		}else if(animationplayed == 21) {
		ApplyAnimation(playerid,"TATTOOS","TAT_Back_In_T",4.1,0,1,1,1,1);
		}else if(animationplayed == 22) {
		ApplyAnimation(playerid,"TATTOOS","TAT_Back_Out_O",4.1,0,1,1,1,1);
		}else if(animationplayed == 23) {
		ApplyAnimation(playerid,"TATTOOS","TAT_Back_Out_P",4.1,0,1,1,1,1);
		}else if(animationplayed == 24) {
		ApplyAnimation(playerid,"TATTOOS","TAT_Back_Out_T",4.1,0,1,1,1,1);
		}else if(animationplayed == 25) {
		ApplyAnimation(playerid,"TATTOOS","TAT_Back_Pose_O",4.1,0,1,1,1,1);
		}else if(animationplayed == 26) {
		ApplyAnimation(playerid,"TATTOOS","TAT_Back_Pose_P",4.1,0,1,1,1,1);
		}else if(animationplayed == 27) {
		ApplyAnimation(playerid,"TATTOOS","TAT_Back_Pose_T",4.1,0,1,1,1,1);
		}else if(animationplayed == 28) {
		ApplyAnimation(playerid,"TATTOOS","TAT_Back_Sit_In_P",4.1,0,1,1,1,1);
		}else if(animationplayed == 29) {
		ApplyAnimation(playerid,"TATTOOS","TAT_Back_Sit_Loop_P",4.1,0,1,1,1,1);
		}else if(animationplayed == 30) {
		ApplyAnimation(playerid,"TATTOOS","TAT_Back_Sit_Out_P",4.1,0,1,1,1,1);
		}else if(animationplayed == 31) {
		ApplyAnimation(playerid,"TATTOOS","TAT_Bel_In_O",4.1,0,1,1,1,1);
		}else if(animationplayed == 32) {
		ApplyAnimation(playerid,"TATTOOS","TAT_Bel_In_T",4.1,0,1,1,1,1);
		}else if(animationplayed == 33) {
		ApplyAnimation(playerid,"TATTOOS","TAT_Bel_Out_O",4.1,0,1,1,1,1);
		}else if(animationplayed == 34) {
		ApplyAnimation(playerid,"TATTOOS","TAT_Bel_Out_T",4.1,0,1,1,1,1);
		}else if(animationplayed == 35) {
		ApplyAnimation(playerid,"TATTOOS","TAT_Bel_Pose_O",4.1,0,1,1,1,1);
		}else if(animationplayed == 36) {
		ApplyAnimation(playerid,"TATTOOS","TAT_Bel_Pose_T",4.1,0,1,1,1,1);
		}else if(animationplayed == 37) {
		ApplyAnimation(playerid,"TATTOOS","TAT_Che_In_O",4.1,0,1,1,1,1);
		}else if(animationplayed == 38) {
		ApplyAnimation(playerid,"TATTOOS","Sit_relaxed",4.1,0,1,1,1,1);
		}else if(animationplayed == 39) {
		ApplyAnimation(playerid,"TATTOOS","TAT_Che_In_P",4.1,0,1,1,1,1);
		}else if(animationplayed == 40) {
		ApplyAnimation(playerid,"TATTOOS","TAT_Che_In_T",4.1,0,1,1,1,1);
		}else if(animationplayed == 41) {
		ApplyAnimation(playerid,"TATTOOS","TAT_Che_Out_O",4.1,0,1,1,1,1);
		}else if(animationplayed == 41) {
		ApplyAnimation(playerid,"TATTOOS","TAT_Che_Out_P",4.1,0,1,1,1,1);
		}else if(animationplayed == 42) {
		ApplyAnimation(playerid,"TATTOOS","TAT_Che_Out_T",4.1,0,1,1,1,1);
		}else if(animationplayed == 43) {
		ApplyAnimation(playerid,"TATTOOS","TAT_Che_Pose_O",4.1,0,1,1,1,1);
		}else if(animationplayed == 44) {
		ApplyAnimation(playerid,"TATTOOS","TAT_Che_Pose_P",4.1,0,1,1,1,1);
		}else if(animationplayed == 45) {
		ApplyAnimation(playerid,"TATTOOS","TAT_Che_Pose_T",4.1,0,1,1,1,1);
		}else if(animationplayed == 46) {
		ApplyAnimation(playerid,"TATTOOS","TAT_Idle_Loop_O",4.1,0,1,1,1,1);
		}else if(animationplayed == 47) {
		ApplyAnimation(playerid,"TATTOOS","TAT_Idle_Loop_T",4.1,0,1,1,1,1);
		}else if(animationplayed == 48) {
		ApplyAnimation(playerid,"TATTOOS","TAT_Sit_In_O",4.1,0,1,1,1,1);
		}else if(animationplayed == 49) {
		ApplyAnimation(playerid,"TATTOOS","TAT_Sit_In_P",4.1,0,1,1,1,1);
		}else if(animationplayed == 50) {
		ApplyAnimation(playerid,"TATTOOS","TAT_Sit_In_T",4.1,0,1,1,1,1);
		}else if(animationplayed == 51) {
		ApplyAnimation(playerid,"TATTOOS","TAT_Sit_Loop_O",4.1,0,1,1,1,1);
		}else if(animationplayed == 52) {
		ApplyAnimation(playerid,"TATTOOS","TAT_Sit_Loop_P",4.1,0,1,1,1,1);
		}else if(animationplayed == 53) {
		ApplyAnimation(playerid,"TATTOOS","TAT_Sit_Loop_T",4.1,0,1,1,1,1);
		}else if(animationplayed == 54) {
		ApplyAnimation(playerid,"TATTOOS","TAT_Sit_Out_O",4.1,0,1,1,1,1);
		}else if(animationplayed == 55) {
		ApplyAnimation(playerid,"TATTOOS","TAT_Sit_Out_P",4.1,0,1,1,1,1);
		}else if(animationplayed == 56) {
		ApplyAnimation(playerid,"TATTOOS","TAT_Sit_Out_T",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animsmoking", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animsmoking [1-8]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 8) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animsmoking [1-8]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"SMOKING","F_smklean_loop",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"SMOKING","M_smklean_loop",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"SMOKING","M_smkstnd_loop",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"SMOKING","M_smk_drag",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"SMOKING","M_smk_in",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"SMOKING","M_smk_loop",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"SMOKING","M_smk_out",4.1,0,1,1,1,1);
		}else if(animationplayed == 8) {
		ApplyAnimation(playerid,"SMOKING","M_smk_tap",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animsniper", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animsniper [1-1]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 1) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animsniper [1-1]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"SNIPER","WEAPON_sniper",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animspray", true) == 0) {
		if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animspray [1-2]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 2) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animspray [1-2]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"SPRAYCAN","spraycan_fire",4.1,0,1,1,1,1);
		} else if(animationplayed == 2) {
		ApplyAnimation(playerid,"SPRAYCAN","spraycan_full",4.1,0,1,1,1,1);
		}
		return 1;
		}
		}
		if(strcmp(cmd, "/animstrip", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animstrip [1-20]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 20) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animstrip [1-20]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"STRIP","PLY_CASH",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"STRIP","PUN_CASH",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"STRIP","PUN_HOLLER",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"STRIP","PUN_LOOP",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"STRIP","strip_A",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"STRIP","strip_B",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"STRIP","strip_C",4.1,0,1,1,1,1);
		}else if(animationplayed == 8) {
		ApplyAnimation(playerid,"STRIP","strip_D",4.1,0,1,1,1,1);
		}else if(animationplayed == 9) {
		ApplyAnimation(playerid,"STRIP","strip_E",4.1,0,1,1,1,1);
		}else if(animationplayed == 10) {
		ApplyAnimation(playerid,"STRIP","strip_F",4.1,0,1,1,1,1);
		}else if(animationplayed == 11) {
		ApplyAnimation(playerid,"STRIP","strip_G",4.1,0,1,1,1,1);
		}else if(animationplayed == 12) {
		ApplyAnimation(playerid,"STRIP","STR_A2B",4.1,0,1,1,1,1);
		}else if(animationplayed == 13) {
		ApplyAnimation(playerid,"STRIP","STR_B2A",4.1,0,1,1,1,1);
		}else if(animationplayed == 14) {
		ApplyAnimation(playerid,"STRIP","STR_B2C",4.1,0,1,1,1,1);
		}else if(animationplayed == 15) {
		ApplyAnimation(playerid,"STRIP","STR_C1",4.1,0,1,1,1,1);
		}else if(animationplayed == 16) {
		ApplyAnimation(playerid,"STRIP","STR_C2",4.1,0,1,1,1,1);
		}else if(animationplayed == 17) {
		ApplyAnimation(playerid,"STRIP","STR_C2B",4.1,0,1,1,1,1);
		}else if(animationplayed == 18) {
		ApplyAnimation(playerid,"STRIP","STR_Loop_A",4.1,0,1,1,1,1);
		}else if(animationplayed == 19) {
		ApplyAnimation(playerid,"STRIP","STR_Loop_B",4.1,0,1,1,1,1);
		}else if(animationplayed == 20) {
		ApplyAnimation(playerid,"STRIP","STR_Loop_C",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animbath", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animbath [1-17]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 18) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animbath [1-17]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"SUNBATHE","batherdown",4.1,0,1,1,1,1);
		}else if(animationplayed == 1) {
		ApplyAnimation(playerid,"SUNBATHE","batherup",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"SUNBATHE","Lay_Bac_in",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"SUNBATHE","Lay_Bac_out",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"SUNBATHE","ParkSit_M_IdleA",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"SUNBATHE","ParkSit_M_IdleB",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"SUNBATHE","ParkSit_M_IdleC",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"SUNBATHE","ParkSit_M_in",4.1,0,1,1,1,1);
		}else if(animationplayed == 8) {
		ApplyAnimation(playerid,"SUNBATHE","ParkSit_M_out",4.1,0,1,1,1,1);
		}else if(animationplayed == 9) {
		ApplyAnimation(playerid,"SUNBATHE","ParkSit_W_idleA",4.1,0,1,1,1,1);
		}else if(animationplayed == 10) {
		ApplyAnimation(playerid,"SUNBATHE","ParkSit_W_idleB",4.1,0,1,1,1,1);
		}else if(animationplayed == 11) {
		ApplyAnimation(playerid,"SUNBATHE","ParkSit_W_idleC",4.1,0,1,1,1,1);
		}else if(animationplayed == 12) {
		ApplyAnimation(playerid,"SUNBATHE","ParkSit_W_in",4.1,0,1,1,1,1);
		}else if(animationplayed == 13) {
		ApplyAnimation(playerid,"SUNBATHE","ParkSit_W_out",4.1,0,1,1,1,1);
		}else if(animationplayed == 14) {
		ApplyAnimation(playerid,"SUNBATHE","SBATHE_F_LieB2Sit",4.1,0,1,1,1,1);
		}else if(animationplayed == 15) {
		ApplyAnimation(playerid,"SUNBATHE","SBATHE_F_Out",4.1,0,1,1,1,1);
		}else if(animationplayed == 16) {
		ApplyAnimation(playerid,"SUNBATHE","SitnWait_in_W",4.1,0,1,1,1,1);
		}else if(animationplayed == 17) {
		ApplyAnimation(playerid,"SUNBATHE","SitnWait_out_W",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animswat", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animswat [1-24]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 24) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animswat [1-24]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"SWAT","gnstwall_injurd",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"SWAT","JMP_Wall1m_180",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"SWAT","Rail_fall",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"SWAT","Rail_fall_crawl",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"SWAT","swt_breach_01",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"SWAT","cards_pick_02",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"SWAT","swt_breach_02",4.1,0,1,1,1,1);
		}else if(animationplayed == 8) {
		ApplyAnimation(playerid,"SWAT","swt_breach_03",4.1,0,1,1,1,1);
		}else if(animationplayed == 9) {
		ApplyAnimation(playerid,"SWAT","swt_go",4.1,0,1,1,1,1);
		}else if(animationplayed == 10) {
		ApplyAnimation(playerid,"SWAT","swt_lkt",4.1,0,1,1,1,1);
		}else if(animationplayed == 11) {
		ApplyAnimation(playerid,"SWAT","swt_sty",4.1,0,1,1,1,1);
		}else if(animationplayed == 12) {
		ApplyAnimation(playerid,"SWAT","swt_vent_01",4.1,0,1,1,1,1);
		}else if(animationplayed == 13) {
		ApplyAnimation(playerid,"SWAT","swt_vent_02",4.1,0,1,1,1,1);
		}else if(animationplayed == 14) {
		ApplyAnimation(playerid,"SWAT","swt_vnt_sht_die",4.1,0,1,1,1,1);
		}else if(animationplayed == 15) {
		ApplyAnimation(playerid,"SWAT","swt_vnt_sht_in",4.1,0,1,1,1,1);
		}else if(animationplayed == 16) {
		ApplyAnimation(playerid,"SWAT","swt_vnt_sht_loop",4.1,0,1,1,1,1);
		}else if(animationplayed == 17) {
		ApplyAnimation(playerid,"SWAT","swt_wllpk_L",4.1,0,1,1,1,1);
		}else if(animationplayed == 18) {
		ApplyAnimation(playerid,"SWAT","swt_wllpk_L_back",4.1,0,1,1,1,1);
		}else if(animationplayed == 19) {
		ApplyAnimation(playerid,"SWAT","swt_wllpk_R",4.1,0,1,1,1,1);
		}else if(animationplayed == 20) {
		ApplyAnimation(playerid,"SWAT","swt_wllpk_R_back",4.1,0,1,1,1,1);
		}else if(animationplayed == 21) {
		ApplyAnimation(playerid,"SWAT","swt_wllshoot_in_L",4.1,0,1,1,1,1);
		}else if(animationplayed == 22) {
		ApplyAnimation(playerid,"SWAT","swt_wllshoot_in_R",4.1,0,1,1,1,1);
		}else if(animationplayed == 23) {
		ApplyAnimation(playerid,"SWAT","swt_wllshoot_out_L",4.1,0,1,1,1,1);
		}else if(animationplayed == 24) {
		ApplyAnimation(playerid,"SWAT","swt_wllshoot_out_R",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animsweet", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animsweet [1-7]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 7) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animsweet [1-7]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"SWEET","ho_ass_slapped",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"SWEET","LaFin_Player",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"SWEET","LaFin_Sweet",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"SWEET","plyr_hndshldr_01",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"SWEET","sweet_ass_slap",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"SWEET","sweet_hndshldr_01",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"SWEET","Sweet_injuredloop",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animswim", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animswim [1-7]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 7) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animswim [1-7]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"SWIM","Swim_Breast",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"SWIM","SWIM_crawl",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"SWIM","Swim_Dive_Under",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"SWIM","Swim_Glide",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"SWIM","Swim_jumpout",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"SWIM","Swim_Tread",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"SWIM","Swim_Under",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animsword", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animsword [1-10]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 10) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animsword [1-10]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"SWORD","sword_1",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"SWORD","sword_2",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"SWORD","sword_3",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"SWORD","sword_4",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"SWORD","sword_block",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"SWORD","Sword_Hit_1",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"SWORD","Sword_Hit_2",4.1,0,1,1,1,1);
		}else if(animationplayed == 8) {
		ApplyAnimation(playerid,"SWORD","Sword_Hit_3",4.1,0,1,1,1,1);
		}else if(animationplayed == 9) {
		ApplyAnimation(playerid,"SWORD","sword_IDLE",4.1,0,1,1,1,1);
		}else if(animationplayed == 10) {
		ApplyAnimation(playerid,"SWORD","sword_part",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animtank", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animtank [1-6]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 6) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animtank [1-6]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"TANK","TANK_align_LHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"TANK","TANK_close_LHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"TANK","TANK_doorlocked",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"TANK","TANK_getin_LHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"TANK","TANK_getout_LHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"TANK","TANK_open_LHS",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animtruck", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animtruck [1-17]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 17) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animtruck [1-17]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"TRUCK","TRUCK_ALIGN_LHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"TRUCK","TRUCK_ALIGN_RHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"TRUCK","TRUCK_closedoor_LHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"TRUCK","TRUCK_closedoor_RHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"TRUCK","TRUCK_close_LHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"TRUCK","TRUCK_close_RHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"TRUCK","TRUCK_getin_LHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 8) {
		ApplyAnimation(playerid,"TRUCK","TRUCK_getin_RHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 9) {
		ApplyAnimation(playerid,"TRUCK","TRUCK_getout_LHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 10) {
		ApplyAnimation(playerid,"TRUCK","TRUCK_getout_RHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 11) {
		ApplyAnimation(playerid,"TRUCK","TRUCK_jackedLHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 12) {
		ApplyAnimation(playerid,"TRUCK","TRUCK_jackedRHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 13) {
		ApplyAnimation(playerid,"TRUCK","TRUCK_open_LHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 14) {
		ApplyAnimation(playerid,"TRUCK","TRUCK_open_RHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 15) {
		ApplyAnimation(playerid,"TRUCK","TRUCK_pullout_LHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 16) {
		ApplyAnimation(playerid,"TRUCK","TRUCK_pullout_RHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 17) {
		ApplyAnimation(playerid,"TRUCK","TRUCK_Shuffle",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animuzi", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animuzi [1-5]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 5) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animuzi [1-5]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"UZI","UZI_crouchfire",4.1,0,1,1,1,1);
		} else if(animationplayed == 2) {
		ApplyAnimation(playerid,"UZI","UZI_crouchreload",4.1,0,1,1,1,1);
		} else if(animationplayed == 3) {
		ApplyAnimation(playerid,"UZI","UZI_fire",4.1,0,1,1,1,1);
		} else if(animationplayed == 4) {
		ApplyAnimation(playerid,"UZI","UZI_fire_poor",4.1,0,1,1,1,1);
		} else if(animationplayed == 5) {
		ApplyAnimation(playerid,"UZI","UZI_reload",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animvan", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animvan [1-8]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 8) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animvan [1-8]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"VAN","VAN_close_back_LHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"VAN","VAN_close_back_RHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"VAN","VAN_getin_Back_LHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"VAN","VAN_getin_Back_RHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"VAN","VAN_getout_back_LHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"VAN","VAN_getout_back_RHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"VAN","VAN_open_back_LHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 8) {
		ApplyAnimation(playerid,"VAN","VAN_open_back_RHS",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animvending", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animvending [1-6]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 6) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animvending [1-6]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"VENDING","VEND_Drink2_P",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"VENDING","VEND_Drink_P",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"VENDING","vend_eat1_P",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"VENDING","VEND_Eat_P",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"VENDING","VEND_Use",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"VENDING","VEND_Use_pt2",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animway", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animway [1-17]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 17) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animway [1-17]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"WAYFARER","WF_Back",4.1,0,1,1,1,1);
		}else if(animationplayed == 1) {
		ApplyAnimation(playerid,"WAYFARER","WF_drivebyFT",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"WAYFARER","WF_drivebyLHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"WAYFARER","WF_drivebyRHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"WAYFARER","WF_Fwd",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"WAYFARER","WF_getoffBACK",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"WAYFARER","WF_getoffLHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"WAYFARER","WF_getoffRHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 8) {
		ApplyAnimation(playerid,"WAYFARER","WF_hit",4.1,0,1,1,1,1);
		}else if(animationplayed == 9) {
		ApplyAnimation(playerid,"WAYFARER","WF_jumponL",4.1,0,1,1,1,1);
		}else if(animationplayed == 10) {
		ApplyAnimation(playerid,"WAYFARER","WF_jumponR",4.1,0,1,1,1,1);
		}else if(animationplayed == 11) {
		ApplyAnimation(playerid,"WAYFARER","WF_kick",4.1,0,1,1,1,1);
		}else if(animationplayed == 12) {
		ApplyAnimation(playerid,"WAYFARER","WF_Left",4.1,0,1,1,1,1);
		}else if(animationplayed == 13) {
		ApplyAnimation(playerid,"WAYFARER","WF_passenger",4.1,0,1,1,1,1);
		}else if(animationplayed == 14) {
		ApplyAnimation(playerid,"WAYFARER","WF_pushes",4.1,0,1,1,1,1);
		}else if(animationplayed == 15) {
		ApplyAnimation(playerid,"WAYFARER","WF_Ride",4.1,0,1,1,1,1);
		}else if(animationplayed == 16) {
		ApplyAnimation(playerid,"WAYFARER","WF_Right",4.1,0,1,1,1,1);
		}else if(animationplayed == 17) {
		ApplyAnimation(playerid,"WAYFARER","WF_Still",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animweap", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animweap [1-17]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 17) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animweap [1-17]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"WEAPONS","SHP_1H_Lift",4.1,0,1,1,1,1);
		}else if(animationplayed == 2) {
		ApplyAnimation(playerid,"WEAPONS","SHP_1H_Lift_End",4.1,0,1,1,1,1);
		}else if(animationplayed == 3) {
		ApplyAnimation(playerid,"WEAPONS","SHP_1H_Ret",4.1,0,1,1,1,1);
		}else if(animationplayed == 4) {
		ApplyAnimation(playerid,"WEAPONS","SHP_1H_Ret_S",4.1,0,1,1,1,1);
		}else if(animationplayed == 5) {
		ApplyAnimation(playerid,"WEAPONS","SHP_2H_Lift",4.1,0,1,1,1,1);
		}else if(animationplayed == 6) {
		ApplyAnimation(playerid,"WEAPONS","SHP_2H_Lift_End",4.1,0,1,1,1,1);
		}else if(animationplayed == 7) {
		ApplyAnimation(playerid,"WEAPONS","SHP_2H_Ret",4.1,0,1,1,1,1);
		}else if(animationplayed == 8) {
		ApplyAnimation(playerid,"WEAPONS","SHP_2H_Ret_S",4.1,0,1,1,1,1);
		}else if(animationplayed == 9) {
		ApplyAnimation(playerid,"WEAPONS","SHP_Ar_Lift",4.1,0,1,1,1,1);
		}else if(animationplayed == 10) {
		ApplyAnimation(playerid,"WEAPONS","SHP_Ar_Lift_End",4.1,0,1,1,1,1);
		}else if(animationplayed == 11) {
		ApplyAnimation(playerid,"WEAPONS","SHP_Ar_Ret",4.1,0,1,1,1,1);
		}else if(animationplayed == 12) {
		ApplyAnimation(playerid,"WEAPONS","SHP_Ar_Ret_S",4.1,0,1,1,1,1);
		}else if(animationplayed == 13) {
		ApplyAnimation(playerid,"WEAPONS","SHP_G_Lift_In",4.1,0,1,1,1,1);
		}else if(animationplayed == 14) {
		ApplyAnimation(playerid,"WEAPONS","SHP_G_Lift_Out",4.1,0,1,1,1,1);
		}else if(animationplayed == 15) {
		ApplyAnimation(playerid,"WEAPONS","SHP_Tray_In",4.1,0,1,1,1,1);
		}else if(animationplayed == 16) {
		ApplyAnimation(playerid,"WEAPONS","SHP_Tray_Out",4.1,0,1,1,1,1);
		}else if(animationplayed == 17) {
		ApplyAnimation(playerid,"WEAPONS","SHP_Tray_Pose",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animwuzi", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animwuzi [1-12]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 12) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animwuzi [1-12]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"WUZI","CS_Dead_Guy",4.1,0,1,1,1,1);
		} else if(animationplayed == 2) {
		ApplyAnimation(playerid,"WUZI","CS_Plyr_pt1",4.1,0,1,1,1,1);
		} else if(animationplayed == 3) {
		ApplyAnimation(playerid,"WUZI","CS_Plyr_pt2",4.1,0,1,1,1,1);
		} else if(animationplayed == 4) {
		ApplyAnimation(playerid,"WUZI","CS_Wuzi_pt1",4.1,0,1,1,1,1);
		} else if(animationplayed == 5) {
		ApplyAnimation(playerid,"WUZI","CS_Wuzi_pt2",4.1,0,1,1,1,1);
		} else if(animationplayed == 6) {
		ApplyAnimation(playerid,"WUZI","Walkstart_Idle_01",4.1,0,1,1,1,1);
		} else if(animationplayed == 7) {
		ApplyAnimation(playerid,"WUZI","Wuzi_follow",4.1,0,1,1,1,1);
		} else if(animationplayed == 8) {
		ApplyAnimation(playerid,"WUZI","Wuzi_Greet_Plyr",4.1,0,1,1,1,1);
		} else if(animationplayed == 9) {
		ApplyAnimation(playerid,"WUZI","Wuzi_Greet_Wuzi",4.1,0,1,1,1,1);
		} else if(animationplayed == 10) {
		ApplyAnimation(playerid,"WUZI","Wuzi_grnd_chk",4.1,0,1,1,1,1);
		} else if(animationplayed == 11) {
		ApplyAnimation(playerid,"WUZI","Wuzi_stand_loop",4.1,0,1,1,1,1);
		} else if(animationplayed == 12) {
		ApplyAnimation(playerid,"WUZI","Wuzi_Walk",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/animat", true) == 0) {
		if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animat [1-3]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 3) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animat [1-3]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"Attractors","Stepsit_in",4.1,0,1,1,1,1);
		} else if(animationplayed == 2) {
		ApplyAnimation(playerid,"Attractors","Stepsit_loop",4.1,0,1,1,1,1);
		} else if(animationplayed == 3) {
		ApplyAnimation(playerid,"Attractors","Stepsit_out",4.1,0,1,1,1,1);
		}
		return 1;
		}
		}
		if(strcmp(cmd, "/animairport", true) == 0) {
		if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animairport [1]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 1) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animairport [1]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"AIRPORT","thrw_barl_thrw",4.1,0,1,1,1,1);
		}
		return 1;
		}
		}
		if(strcmp(cmd, "/animped", true) == 0) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animped [1-295]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 295) {
		SendClientMessage(playerid,0xFF0000FF,">Write /animped [1-295]");
		return 1;
		}
		if(animationplayed == 1) {
		ApplyAnimation(playerid,"PED","IDLE_CHAT",4.1,0,1,1,1,1);
		} else if(animationplayed == 2) {
		ApplyAnimation(playerid,"PED","WALK_DRUNK",4.1,0,1,1,1,1);
		} else if(animationplayed == 3) {
		ApplyAnimation(playerid,"PED","abseil",4.1,0,1,1,1,1);
		} else if(animationplayed == 4) {
		ApplyAnimation(playerid,"PED","ARRESTgun",4.1,0,1,1,1,1);
		} else if(animationplayed == 5) {
		ApplyAnimation(playerid,"PED","ATM",4.1,0,1,1,1,1);
		} else if(animationplayed == 6) {
		ApplyAnimation(playerid,"PED","BIKE_elbowL",4.1,0,1,1,1,1);
		} else if(animationplayed == 7) {
		ApplyAnimation(playerid,"PED","BIKE_fallR",4.1,0,1,1,1,1);
		} else if(animationplayed == 8) {
		ApplyAnimation(playerid,"PED","BIKE_fall_off",4.1,0,1,1,1,1);
		} else if(animationplayed == 9) {
		ApplyAnimation(playerid,"PED","BIKE_pickupL",4.1,0,1,1,1,1);
		} else if(animationplayed == 10) {
		ApplyAnimation(playerid,"PED","BIKE_pickupR",4.1,0,1,1,1,1);
		} else if(animationplayed == 11) {
		ApplyAnimation(playerid,"PED","BIKE_pullupL",4.1,0,1,1,1,1);
		} else if(animationplayed == 12) {
		ApplyAnimation(playerid,"PED","BIKE_pullupR",4.1,0,1,1,1,1);
		} else if(animationplayed == 13) {
		ApplyAnimation(playerid,"PED","bomber",4.1,0,1,1,1,1);
		} else if(animationplayed == 14) {
		ApplyAnimation(playerid,"PED","CAR_alignHI_LHS",4.1,0,1,1,1,1);
		} else if(animationplayed == 15) {
		ApplyAnimation(playerid,"PED","CAR_alignHI_RHS",4.1,0,1,1,1,1);
		} else if(animationplayed == 16) {
		ApplyAnimation(playerid,"PED","CAR_align_LHS",4.1,0,1,1,1,1);
		} else if(animationplayed == 17) {
		ApplyAnimation(playerid,"PED","CAR_align_RHS",4.1,0,1,1,1,1);
		} else if(animationplayed == 18) {
		ApplyAnimation(playerid,"PED","CAR_closedoorL_LHS",4.1,0,1,1,1,1);
		} else if(animationplayed == 19) {
		ApplyAnimation(playerid,"PED","CAR_closedoorL_RHS",4.1,0,1,1,1,1);
		} else if(animationplayed == 20) {
		ApplyAnimation(playerid,"PED","CAR_closedoor_LHS",4.1,0,1,1,1,1);
		} else if(animationplayed == 21) {
		ApplyAnimation(playerid,"PED","CAR_closedoor_RHS",4.1,0,1,1,1,1);
		} else if(animationplayed == 22) {
		ApplyAnimation(playerid,"PED","CAR_close_LHS",4.1,0,1,1,1,1);
		} else if(animationplayed == 23) {
		ApplyAnimation(playerid,"PED","CAR_crawloutRHS",4.1,0,1,1,1,1);
		} else if(animationplayed == 24) {
		ApplyAnimation(playerid,"PED","CAR_dead_LHS",4.1,0,1,1,1,1);
		} else if(animationplayed == 25) {
		ApplyAnimation(playerid,"PED","CAR_dead_RHS",4.1,0,1,1,1,1);
		} else if(animationplayed == 26) {
		ApplyAnimation(playerid,"PED","CAR_doorlocked_LHS",4.1,0,1,1,1,1);
		} else if(animationplayed == 27) {
		ApplyAnimation(playerid,"PED","CAR_fallout_LHS",4.1,0,1,1,1,1);
		} else if(animationplayed == 28) {
		ApplyAnimation(playerid,"PED","CAR_fallout_RHS",4.1,0,1,1,1,1);
		} else if(animationplayed == 29) {
		ApplyAnimation(playerid,"PED","CAR_getinL_LHS",4.1,0,1,1,1,1);
		} else if(animationplayed == 30) {
		ApplyAnimation(playerid,"PED","CAR_getinL_RHS",4.1,0,1,1,1,1);
		} else if(animationplayed == 31) {
		ApplyAnimation(playerid,"PED","CAR_getin_LHS",4.1,0,1,1,1,1);
		} else if(animationplayed == 32) {
		ApplyAnimation(playerid,"PED","CAR_getin_RHS",4.1,0,1,1,1,1);
		} else if(animationplayed == 33) {
		ApplyAnimation(playerid,"PED","CAR_getoutL_LHS",4.1,0,1,1,1,1);
		} else if(animationplayed == 34) {
		ApplyAnimation(playerid,"PED","CAR_getout_LHS",4.1,0,1,1,1,1);
		} else if(animationplayed == 35) {
		ApplyAnimation(playerid,"PED","CAR_getout_RHS",4.1,0,1,1,1,1);
		} else if(animationplayed == 36) {
		ApplyAnimation(playerid,"PED","car_hookertalk",4.1,0,1,1,1,1);
		} else if(animationplayed == 37) {
		ApplyAnimation(playerid,"PED","CAR_jackedLHS",4.1,0,1,1,1,1);
		} else if(animationplayed == 38) {
		ApplyAnimation(playerid,"PED","CAR_jackedRHS",4.1,0,1,1,1,1);
		} else if(animationplayed == 39) {
		ApplyAnimation(playerid,"PED","CAR_jumpin_LHS",4.1,0,1,1,1,1);
		} else if(animationplayed == 40) {
		ApplyAnimation(playerid,"PED","CAR_LB",4.1,0,1,1,1,1);
		} else if(animationplayed == 41) {
		ApplyAnimation(playerid,"PED","CAR_LB_pro",4.1,0,1,1,1,1);
		} else if(animationplayed == 42) {
		ApplyAnimation(playerid,"PED","CAR_LB_weak",4.1,0,1,1,1,1);
		} else if(animationplayed == 43) {
		ApplyAnimation(playerid,"PED","CAR_LjackedLHS",4.1,0,1,1,1,1);
		} else if(animationplayed == 44) {
		ApplyAnimation(playerid,"PED","CAR_Lshuffle_RHS",4.1,0,1,1,1,1);
		} else if(animationplayed == 45) {
		ApplyAnimation(playerid,"PED","CAR_Lsit",4.1,0,1,1,1,1);
		} else if(animationplayed == 46) {
		ApplyAnimation(playerid,"PED","CAR_open_LHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 47) {
		ApplyAnimation(playerid,"PED","CAR_open_RHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 49) {
		ApplyAnimation(playerid,"PED","CAR_pulloutL_LHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 50) {
		ApplyAnimation(playerid,"PED","CAR_pulloutL_RHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 51) {
		ApplyAnimation(playerid,"PED","CAR_pullout_LHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 52) {
		ApplyAnimation(playerid,"PED","CAR_pullout_RHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 53) {
		ApplyAnimation(playerid,"PED","CAR_Qjacked",4.1,0,1,1,1,1);
		}else if(animationplayed == 54) {
		ApplyAnimation(playerid,"PED","CAR_rolldoor",4.1,0,1,1,1,1);
		}else if(animationplayed == 55) {
		ApplyAnimation(playerid,"PED","CAR_rolldoorLO",4.1,0,1,1,1,1);
		}else if(animationplayed == 56) {
		ApplyAnimation(playerid,"PED","CAR_rollout_LHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 57) {
		ApplyAnimation(playerid,"PED","CAR_rollout_RHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 58) {
		ApplyAnimation(playerid,"PED","CAR_shuffle_RHS",4.1,0,1,1,1,1);
		}else if(animationplayed == 59) {
		ApplyAnimation(playerid,"PED","CAR_sit",4.1,0,1,1,1,1);
		}else if(animationplayed == 60) {
		ApplyAnimation(playerid,"PED","CAR_sitp",4.1,0,1,1,1,1);
		}else if(animationplayed == 61) {
		ApplyAnimation(playerid,"PED","CAR_sitpLO",4.1,0,1,1,1,1);
		}else if(animationplayed == 62) {
		ApplyAnimation(playerid,"PED","CAR_sit_pro",4.1,0,1,1,1,1);
		}else if(animationplayed == 63) {
		ApplyAnimation(playerid,"PED","CAR_sit_weak",4.1,0,1,1,1,1);
		}else if(animationplayed == 64) {
		ApplyAnimation(playerid,"PED","CAR_tune_radio",4.1,0,1,1,1,1);
		}else if(animationplayed == 65) {
		ApplyAnimation(playerid,"PED","CLIMB_idle",4.1,0,1,1,1,1);
		}else if(animationplayed == 66) {
		ApplyAnimation(playerid,"PED","CLIMB_jump",4.1,0,1,1,1,1);
		}else if(animationplayed == 67) {
		ApplyAnimation(playerid,"PED","CLIMB_jump2fall",4.1,0,1,1,1,1);
		}else if(animationplayed == 68) {
		ApplyAnimation(playerid,"PED","CLIMB_jump_B",4.1,0,1,1,1,1);
		}else if(animationplayed == 69) {
		ApplyAnimation(playerid,"PED","CLIMB_Pull",4.1,0,1,1,1,1);
		}else if(animationplayed == 70) {
		ApplyAnimation(playerid,"PED","CLIMB_Stand",4.1,0,1,1,1,1);
		}else if(animationplayed == 71) {
		ApplyAnimation(playerid,"PED","CLIMB_Stand_finish",4.1,0,1,1,1,1);
		}else if(animationplayed == 72) {
		ApplyAnimation(playerid,"PED","cower",4.1,0,1,1,1,1);
		}else if(animationplayed == 73) {
		ApplyAnimation(playerid,"PED","Crouch_Roll_L",4.1,0,1,1,1,1);
		}else if(animationplayed == 74) {
		ApplyAnimation(playerid,"PED","Crouch_Roll_R",4.1,0,1,1,1,1);
		}else if(animationplayed == 75) {
		ApplyAnimation(playerid,"PED","DAM_armL_frmBK",4.1,0,1,1,1,1);
		}else if(animationplayed == 76) {
		ApplyAnimation(playerid,"PED","DAM_armL_frmFT",4.1,0,1,1,1,1);
		}else if(animationplayed == 77) {
		ApplyAnimation(playerid,"PED","DAM_armL_frmLT",4.1,0,1,1,1,1);
		}else if(animationplayed == 78) {
		ApplyAnimation(playerid,"PED","DAM_armR_frmBK",4.1,0,1,1,1,1);
		}else if(animationplayed == 79) {
		ApplyAnimation(playerid,"PED","DAM_armR_frmFT",4.1,0,1,1,1,1);
		}else if(animationplayed == 80) {
		ApplyAnimation(playerid,"PED","DAM_armR_frmRT",4.1,0,1,1,1,1);
		}else if(animationplayed == 81) {
		ApplyAnimation(playerid,"PED","DAM_LegL_frmBK",4.1,0,1,1,1,1);
		}else if(animationplayed == 82) {
		ApplyAnimation(playerid,"PED","DAM_LegL_frmFT",4.1,0,1,1,1,1);
		}else if(animationplayed == 83) {
		ApplyAnimation(playerid,"PED","DAM_LegL_frmLT",4.1,0,1,1,1,1);
		}else if(animationplayed == 84) {
		ApplyAnimation(playerid,"PED","DAM_LegR_frmBK",4.1,0,1,1,1,1);
		}else if(animationplayed == 85) {
		ApplyAnimation(playerid,"PED","DAM_LegR_frmFT",4.1,0,1,1,1,1);
		}else if(animationplayed == 86) {
		ApplyAnimation(playerid,"PED","DAM_LegR_frmRT",4.1,0,1,1,1,1);
		}else if(animationplayed == 87) {
		ApplyAnimation(playerid,"PED","DAM_stomach_frmBK",4.1,0,1,1,1,1);
		}else if(animationplayed == 88) {
		ApplyAnimation(playerid,"PED","DAM_stomach_frmFT",4.1,0,1,1,1,1);
		}else if(animationplayed == 89) {
		ApplyAnimation(playerid,"PED","DAM_stomach_frmLT",4.1,0,1,1,1,1);
		}else if(animationplayed == 90) {
		ApplyAnimation(playerid,"PED","DAM_stomach_frmRT",4.1,0,1,1,1,1);
		}else if(animationplayed == 91) {
		ApplyAnimation(playerid,"PED","DOOR_LHinge_O",4.1,0,1,1,1,1);
		}else if(animationplayed == 92) {
		ApplyAnimation(playerid,"PED","DOOR_RHinge_O",4.1,0,1,1,1,1);
		}else if(animationplayed == 93) {
		ApplyAnimation(playerid,"PED","DrivebyL_L",4.1,0,1,1,1,1);
		}else if(animationplayed == 94) {
		ApplyAnimation(playerid,"PED","DrivebyL_R",4.1,0,1,1,1,1);
		}else if(animationplayed == 95) {
		ApplyAnimation(playerid,"PED","Driveby_L",4.1,0,1,1,1,1);
		}else if(animationplayed == 96) {
		ApplyAnimation(playerid,"PED","Driveby_R",4.1,0,1,1,1,1);
		}else if(animationplayed == 97) {
		ApplyAnimation(playerid,"PED","DRIVE_BOAT",4.1,0,1,1,1,1);
		}else if(animationplayed == 98) {
		ApplyAnimation(playerid,"PED","DRIVE_BOAT_back",4.1,0,1,1,1,1);
		}else if(animationplayed == 99) {
		ApplyAnimation(playerid,"PED","DRIVE_BOAT_L",4.1,0,1,1,1,1);
		}else if(animationplayed == 100) {
		ApplyAnimation(playerid,"PED","DRIVE_BOAT_R",4.1,0,1,1,1,1);
		}else if(animationplayed == 101) {
		ApplyAnimation(playerid,"PED","Drive_L",4.1,0,1,1,1,1);
		}else if(animationplayed == 102) {
		ApplyAnimation(playerid,"PED","Drive_LO_l",4.1,0,1,1,1,1);
		}else if(animationplayed == 103) {
		ApplyAnimation(playerid,"PED","Drive_LO_R",4.1,0,1,1,1,1);
		}else if(animationplayed == 104) {
		ApplyAnimation(playerid,"PED","Drive_L_pro",4.1,0,1,1,1,1);
		}else if(animationplayed == 105) {
		ApplyAnimation(playerid,"PED","Drive_L_pro_slow",4.1,0,1,1,1,1);
		}else if(animationplayed == 106) {
		ApplyAnimation(playerid,"PED","Drive_L_slow",4.1,0,1,1,1,1);
		}else if(animationplayed == 107) {
		ApplyAnimation(playerid,"PED","Drive_L_weak",4.1,0,1,1,1,1);
		}else if(animationplayed == 108) {
		ApplyAnimation(playerid,"PED","Drive_L_weak_slow",4.1,0,1,1,1,1);
		}else if(animationplayed == 109) {
		ApplyAnimation(playerid,"PED","Drive_R",4.1,0,1,1,1,1);
		}else if(animationplayed == 110) {
		ApplyAnimation(playerid,"PED","Drive_R_pro",4.1,0,1,1,1,1);
		}else if(animationplayed == 111) {
		ApplyAnimation(playerid,"PED","Drive_R_pro_slow",4.1,0,1,1,1,1);
		}else if(animationplayed == 112) {
		ApplyAnimation(playerid,"PED","Drive_R_slow",4.1,0,1,1,1,1);
		}else if(animationplayed == 113) {
		ApplyAnimation(playerid,"PED","Drive_R_weak",4.1,0,1,1,1,1);
		}else if(animationplayed == 114) {
		ApplyAnimation(playerid,"PED","Drive_R_weak_slow",4.1,0,1,1,1,1);
		}else if(animationplayed == 115) {
		ApplyAnimation(playerid,"PED","Drive_truck",4.1,0,1,1,1,1);
		}else if(animationplayed == 116) {
		ApplyAnimation(playerid,"PED","DRIVE_truck_back",4.1,0,1,1,1,1);
		}else if(animationplayed == 117) {
		ApplyAnimation(playerid,"PED","DRIVE_truck_L",4.1,0,1,1,1,1);
		}else if(animationplayed == 118) {
		ApplyAnimation(playerid,"PED","DRIVE_truck_R",4.1,0,1,1,1,1);
		}else if(animationplayed == 119) {
		ApplyAnimation(playerid,"PED","Drown",4.1,0,1,1,1,1);
		}else if(animationplayed == 120) {
		ApplyAnimation(playerid,"PED","DUCK_cower",4.1,0,1,1,1,1);
		}else if(animationplayed == 121) {
		ApplyAnimation(playerid,"PED","endchat_01",4.1,0,1,1,1,1);
		}else if(animationplayed == 122) {
		ApplyAnimation(playerid,"PED","endchat_02",4.1,0,1,1,1,1);
		}else if(animationplayed == 123) {
		ApplyAnimation(playerid,"PED","endchat_03",4.1,0,1,1,1,1);
		}else if(animationplayed == 124) {
		ApplyAnimation(playerid,"PED","DRIVE_truck_back",4.1,0,1,1,1,1);
		}else if(animationplayed == 125) {
		ApplyAnimation(playerid,"PED","DRIVE_truck_back",4.1,0,1,1,1,1);
		}else if(animationplayed == 126) {
		ApplyAnimation(playerid,"PED","EV_dive",4.1,0,1,1,1,1);
		}else if(animationplayed == 127) {
		ApplyAnimation(playerid,"PED","EV_step",4.1,0,1,1,1,1);
		}else if(animationplayed == 128) {
		ApplyAnimation(playerid,"PED","facanger",4.1,0,1,1,1,1);
		}else if(animationplayed == 129) {
		ApplyAnimation(playerid,"PED","facanger",4.1,0,1,1,1,1);
		}else if(animationplayed == 130) {
		ApplyAnimation(playerid,"PED","facgum",4.1,0,1,1,1,1);
		}else if(animationplayed == 131) {
		ApplyAnimation(playerid,"PED","facsurp",4.1,0,1,1,1,1);
		}else if(animationplayed == 132) {
		ApplyAnimation(playerid,"PED","facsurpm",4.1,0,1,1,1,1);
		}else if(animationplayed == 133) {
		ApplyAnimation(playerid,"PED","factalk",4.1,0,1,1,1,1);
		}else if(animationplayed == 134) {
		ApplyAnimation(playerid,"PED","facurios",4.1,0,1,1,1,1);
		}else if(animationplayed == 135) {
		ApplyAnimation(playerid,"PED","FALL_back",4.1,0,1,1,1,1);
		}else if(animationplayed == 136) {
		ApplyAnimation(playerid,"PED","FALL_collapse",4.1,0,1,1,1,1);
		}else if(animationplayed == 137) {
		ApplyAnimation(playerid,"PED","FALL_fall",4.1,0,1,1,1,1);
		}else if(animationplayed == 138) {
		ApplyAnimation(playerid,"PED","FALL_front",4.1,0,1,1,1,1);
		}else if(animationplayed == 139) {
		ApplyAnimation(playerid,"PED","FALL_glide",4.1,0,1,1,1,1);
		}else if(animationplayed == 140) {
		ApplyAnimation(playerid,"PED","FALL_land",4.1,0,1,1,1,1);
		}else if(animationplayed == 141) {
		ApplyAnimation(playerid,"PED","FALL_skyDive",4.1,0,1,1,1,1);
		}else if(animationplayed == 142) {
		ApplyAnimation(playerid,"PED","Fight2Idle",4.1,0,1,1,1,1);
		}else if(animationplayed == 143) {
		ApplyAnimation(playerid,"PED","FightA_1",4.1,0,1,1,1,1);
		}else if(animationplayed == 144) {
		ApplyAnimation(playerid,"PED","FightA_2",4.1,0,1,1,1,1);
		}else if(animationplayed == 145) {
		ApplyAnimation(playerid,"PED","FightA_3",4.1,0,1,1,1,1);
		}else if(animationplayed == 146) {
		ApplyAnimation(playerid,"PED","FightA_block",4.1,0,1,1,1,1);
		}else if(animationplayed == 147) {
		ApplyAnimation(playerid,"PED","FightA_G",4.1,0,1,1,1,1);
		}else if(animationplayed == 148) {
		ApplyAnimation(playerid,"PED","FightA_M",4.1,0,1,1,1,1);
		}else if(animationplayed == 149) {
		ApplyAnimation(playerid,"PED","FIGHTIDLE",4.1,0,1,1,1,1);
		}else if(animationplayed == 150) {
		ApplyAnimation(playerid,"PED","FightShB",4.1,0,1,1,1,1);
		}else if(animationplayed == 151) {
		ApplyAnimation(playerid,"PED","FightShF",4.1,0,1,1,1,1);
		}else if(animationplayed == 152) {
		ApplyAnimation(playerid,"PED","FightSh_BWD",4.1,0,1,1,1,1);
		}else if(animationplayed == 153) {
		ApplyAnimation(playerid,"PED","FightSh_FWD",4.1,0,1,1,1,1);
		}else if(animationplayed == 154) {
		ApplyAnimation(playerid,"PED","FightSh_Left",4.1,0,1,1,1,1);
		}else if(animationplayed == 155) {
		ApplyAnimation(playerid,"PED","FightSh_Right",4.1,0,1,1,1,1);
		}else if(animationplayed == 156) {
		ApplyAnimation(playerid,"PED","flee_lkaround_01",4.1,0,1,1,1,1);
		}else if(animationplayed == 157) {
		ApplyAnimation(playerid,"PED","FLOOR_hit",4.1,0,1,1,1,1);
		}else if(animationplayed == 158) {
		ApplyAnimation(playerid,"PED","FLOOR_hit_f",4.1,0,1,1,1,1);
		}else if(animationplayed == 159) {
		ApplyAnimation(playerid,"PED","fucku",4.1,0,1,1,1,1);
		}else if(animationplayed == 160) {
		ApplyAnimation(playerid,"PED","gang_gunstand",4.1,0,1,1,1,1);
		}else if(animationplayed == 161) {
		ApplyAnimation(playerid,"PED","gas_cwr",4.1,0,1,1,1,1);
		}else if(animationplayed == 162) {
		ApplyAnimation(playerid,"PED","getup",4.1,0,1,1,1,1);
		}else if(animationplayed == 163) {
		ApplyAnimation(playerid,"PED","getup_front",4.1,0,1,1,1,1);
		}else if(animationplayed == 164) {
		ApplyAnimation(playerid,"PED","gum_eat",4.1,0,1,1,1,1);
		}else if(animationplayed == 165) {
		ApplyAnimation(playerid,"PED","GunCrouchBwd",4.1,0,1,1,1,1);
		}else if(animationplayed == 166) {
		ApplyAnimation(playerid,"PED","GunCrouchFwd",4.1,0,1,1,1,1);
		}else if(animationplayed == 167) {
		ApplyAnimation(playerid,"PED","GunMove_BWD",4.1,0,1,1,1,1);
		}else if(animationplayed == 168) {
		ApplyAnimation(playerid,"PED","GunMove_FWD",4.1,0,1,1,1,1);
		}else if(animationplayed == 169) {
		ApplyAnimation(playerid,"PED","GunMove_L",4.1,0,1,1,1,1);
		}else if(animationplayed == 170) {
		ApplyAnimation(playerid,"PED","GunMove_R",4.1,0,1,1,1,1);
		}else if(animationplayed == 171) {
		ApplyAnimation(playerid,"PED","Gun_2_IDLE",4.1,0,1,1,1,1);
		}else if(animationplayed == 172) {
		ApplyAnimation(playerid,"PED","GUN_BUTT",4.1,0,1,1,1,1);
		}else if(animationplayed == 173) {
		ApplyAnimation(playerid,"PED","GUN_BUTT_crouch",4.1,0,1,1,1,1);
		}else if(animationplayed == 174) {
		ApplyAnimation(playerid,"PED","Gun_stand",4.1,0,1,1,1,1);
		}else if(animationplayed == 175) {
		ApplyAnimation(playerid,"PED","handscower",4.1,0,1,1,1,1);
		}else if(animationplayed == 176) {
		ApplyAnimation(playerid,"PED","handsup",4.1,0,1,1,1,1);
		}else if(animationplayed == 177) {
		ApplyAnimation(playerid,"PED","HitA_1",4.1,0,1,1,1,1);
		}else if(animationplayed == 178) {
		ApplyAnimation(playerid,"PED","HitA_2",4.1,0,1,1,1,1);
		}else if(animationplayed == 179) {
		ApplyAnimation(playerid,"PED","HitA_3",4.1,0,1,1,1,1);
		}else if(animationplayed == 180) {
		ApplyAnimation(playerid,"PED","HIT_back",4.1,0,1,1,1,1);
		}else if(animationplayed == 181) {
		ApplyAnimation(playerid,"PED","HIT_behind",4.1,0,1,1,1,1);
		}else if(animationplayed == 182) {
		ApplyAnimation(playerid,"PED","HIT_front",4.1,0,1,1,1,1);
		}else if(animationplayed == 183) {
		ApplyAnimation(playerid,"PED","HIT_GUN_BUTT",4.1,0,1,1,1,1);
		}else if(animationplayed == 184) {
		ApplyAnimation(playerid,"PED","HIT_L",4.1,0,1,1,1,1);
		}else if(animationplayed == 185) {
		ApplyAnimation(playerid,"PED","HIT_R",4.1,0,1,1,1,1);
		}else if(animationplayed == 186) {
		ApplyAnimation(playerid,"PED","HIT_walk",4.1,0,1,1,1,1);
		}else if(animationplayed == 187) {
		ApplyAnimation(playerid,"PED","HIT_wall",4.1,0,1,1,1,1);
		}else if(animationplayed == 188) {
		ApplyAnimation(playerid,"PED","Idlestance_fat",4.1,0,1,1,1,1);
		}else if(animationplayed == 189) {
		ApplyAnimation(playerid,"PED","idlestance_old",4.1,0,1,1,1,1);
		}else if(animationplayed == 190) {
		ApplyAnimation(playerid,"PED","IDLE_armed",4.1,0,1,1,1,1);
		}else if(animationplayed == 191) {
		ApplyAnimation(playerid,"PED","IDLE_chat",4.1,0,1,1,1,1);
		}else if(animationplayed == 192) {
		ApplyAnimation(playerid,"PED","IDLE_csaw",4.1,0,1,1,1,1);
		}else if(animationplayed == 193) {
		ApplyAnimation(playerid,"PED","Idle_Gang1",4.1,0,1,1,1,1);
		}else if(animationplayed == 194) {
		ApplyAnimation(playerid,"PED","IDLE_HBHB",4.1,0,1,1,1,1);
		}else if(animationplayed == 195) {
		ApplyAnimation(playerid,"PED","IDLE_ROCKET",4.1,0,1,1,1,1);
		}else if(animationplayed == 196) {
		ApplyAnimation(playerid,"PED","IDLE_stance",4.1,0,1,1,1,1);
		}else if(animationplayed == 197) {
		ApplyAnimation(playerid,"PED","IDLE_taxi",4.1,0,1,1,1,1);
		}else if(animationplayed == 198) {
		ApplyAnimation(playerid,"PED","IDLE_tired",4.1,0,1,1,1,1);
		}else if(animationplayed == 199) {
		ApplyAnimation(playerid,"PED","Jetpack_Idle",4.1,0,1,1,1,1);
		}else if(animationplayed == 200) {
		ApplyAnimation(playerid,"PED","JOG_femaleA",4.1,0,1,1,1,1);
		}else if(animationplayed == 201) {
		ApplyAnimation(playerid,"PED","JOG_maleA",4.1,0,1,1,1,1);
		}else if(animationplayed == 202) {
		ApplyAnimation(playerid,"PED","JUMP_glide",4.1,0,1,1,1,1);
		}else if(animationplayed == 203) {
		ApplyAnimation(playerid,"PED","JUMP_land",4.1,0,1,1,1,1);
		}else if(animationplayed == 204) {
		ApplyAnimation(playerid,"PED","JUMP_launch",4.1,0,1,1,1,1);
		}else if(animationplayed == 205) {
		ApplyAnimation(playerid,"PED","JUMP_launch_R",4.1,0,1,1,1,1);
		}else if(animationplayed == 206) {
		ApplyAnimation(playerid,"PED","KART_drive",4.1,0,1,1,1,1);
		}else if(animationplayed == 207) {
		ApplyAnimation(playerid,"PED","KART_L",4.1,0,1,1,1,1);
		}else if(animationplayed == 208) {
		ApplyAnimation(playerid,"PED","KART_LB",4.1,0,1,1,1,1);
		}else if(animationplayed == 209) {
		ApplyAnimation(playerid,"PED","KART_R",4.1,0,1,1,1,1);
		}else if(animationplayed == 210) {
		ApplyAnimation(playerid,"PED","KD_left",4.1,0,1,1,1,1);
		}else if(animationplayed == 211) {
		ApplyAnimation(playerid,"PED","KD_right",4.1,0,1,1,1,1);
		}else if(animationplayed == 212) {
		ApplyAnimation(playerid,"PED","KO_shot_face",4.1,0,1,1,1,1);
		}else if(animationplayed == 213) {
		ApplyAnimation(playerid,"PED","KO_shot_front",4.1,0,1,1,1,1);
		}else if(animationplayed == 214) {
		ApplyAnimation(playerid,"PED","KO_shot_stom",4.1,0,1,1,1,1);
		}else if(animationplayed == 215) {
		ApplyAnimation(playerid,"PED","KO_skid_back",4.1,0,1,1,1,1);
		}else if(animationplayed == 216) {
		ApplyAnimation(playerid,"PED","KO_skid_front",4.1,0,1,1,1,1);
		}else if(animationplayed == 217) {
		ApplyAnimation(playerid,"PED","KO_spin_L",4.1,0,1,1,1,1);
		}else if(animationplayed == 218) {
		ApplyAnimation(playerid,"PED","KO_spin_R",4.1,0,1,1,1,1);
		}else if(animationplayed == 219) {
		ApplyAnimation(playerid,"PED","pass_Smoke_in_car",4.1,0,1,1,1,1);
		}else if(animationplayed == 220) {
		ApplyAnimation(playerid,"PED","phone_in",4.1,0,1,1,1,1);
		}else if(animationplayed == 221) {
		ApplyAnimation(playerid,"PED","phone_out",4.1,0,1,1,1,1);
		}else if(animationplayed == 222) {
		ApplyAnimation(playerid,"PED","phone_talk",4.1,0,1,1,1,1);
		}else if(animationplayed == 223) {
		ApplyAnimation(playerid,"PED","Player_Sneak",4.1,0,1,1,1,1);
		}else if(animationplayed == 224) {
		ApplyAnimation(playerid,"PED","Player_Sneak_walkstart",4.1,0,1,1,1,1);
		}else if(animationplayed == 225) {
		ApplyAnimation(playerid,"PED","roadcross",4.1,0,1,1,1,1);
		}else if(animationplayed == 226) {
		ApplyAnimation(playerid,"PED","roadcross_female",4.1,0,1,1,1,1);
		}else if(animationplayed == 227) {
		ApplyAnimation(playerid,"PED","roadcross_gang",4.1,0,1,1,1,1);
		}else if(animationplayed == 228) {
		ApplyAnimation(playerid,"PED","roadcross_old",4.1,0,1,1,1,1);
		}else if(animationplayed == 229) {
		ApplyAnimation(playerid,"PED","run_1armed",4.1,0,1,1,1,1);
		}else if(animationplayed == 230) {
		ApplyAnimation(playerid,"PED","run_armed",4.1,0,1,1,1,1);
		}else if(animationplayed == 231) {
		ApplyAnimation(playerid,"PED","run_civi",4.1,0,1,1,1,1);
		}else if(animationplayed == 232) {
		ApplyAnimation(playerid,"PED","run_csaw",4.1,0,1,1,1,1);
		}else if(animationplayed == 233) {
		ApplyAnimation(playerid,"PED","run_fat",4.1,0,1,1,1,1);
		}else if(animationplayed == 234) {
		ApplyAnimation(playerid,"PED","run_fatold",4.1,0,1,1,1,1);
		}else if(animationplayed == 235) {
		ApplyAnimation(playerid,"PED","run_gang1",4.1,0,1,1,1,1);
		}else if(animationplayed == 236) {
		ApplyAnimation(playerid,"PED","run_left",4.1,0,1,1,1,1);
		}else if(animationplayed == 237) {
		ApplyAnimation(playerid,"PED","run_old",4.1,0,1,1,1,1);
		}else if(animationplayed == 238) {
		ApplyAnimation(playerid,"PED","run_player",4.1,0,1,1,1,1);
		}else if(animationplayed == 239) {
		ApplyAnimation(playerid,"PED","run_right",4.1,0,1,1,1,1);
		}else if(animationplayed == 240) {
		ApplyAnimation(playerid,"PED","run_rocket",4.1,0,1,1,1,1);
		}else if(animationplayed == 241) {
		ApplyAnimation(playerid,"PED","Run_stop",4.1,0,1,1,1,1);
		}else if(animationplayed == 242) {
		ApplyAnimation(playerid,"PED","Run_stopR",4.1,0,1,1,1,1);
		}else if(animationplayed == 243) {
		ApplyAnimation(playerid,"PED","Run_Wuzi",4.1,0,1,1,1,1);
		}else if(animationplayed == 244) {
		ApplyAnimation(playerid,"PED","SEAT_down",4.1,0,1,1,1,1);
		}else if(animationplayed == 245) {
		ApplyAnimation(playerid,"PED","SEAT_idle",4.1,0,1,1,1,1);
		}else if(animationplayed == 246) {
		ApplyAnimation(playerid,"PED","SEAT_up",4.1,0,1,1,1,1);
		}else if(animationplayed == 247) {
		ApplyAnimation(playerid,"PED","SHOT_leftP",4.1,0,1,1,1,1);
		}else if(animationplayed == 248) {
		ApplyAnimation(playerid,"PED","SHOT_partial",4.1,0,1,1,1,1);
		}else if(animationplayed == 249) {
		ApplyAnimation(playerid,"PED","SHOT_partial_B",4.1,0,1,1,1,1);
		}else if(animationplayed == 250) {
		ApplyAnimation(playerid,"PED","SHOT_rightP",4.1,0,1,1,1,1);
		}else if(animationplayed == 251) {
		ApplyAnimation(playerid,"PED","Shove_Partial",4.1,0,1,1,1,1);
		}else if(animationplayed == 252) {
		ApplyAnimation(playerid,"PED","Smoke_in_car",4.1,0,1,1,1,1);
		}else if(animationplayed == 253) {
		ApplyAnimation(playerid,"PED","sprint_civi",4.1,0,1,1,1,1);
		}else if(animationplayed == 254) {
		ApplyAnimation(playerid,"PED","sprint_panic",4.1,0,1,1,1,1);
		}else if(animationplayed == 255) {
		ApplyAnimation(playerid,"PED","Sprint_Wuzi",4.1,0,1,1,1,1);
		}else if(animationplayed == 256) {
		ApplyAnimation(playerid,"PED","swat_run",4.1,0,1,1,1,1);
		}else if(animationplayed == 257) {
		ApplyAnimation(playerid,"PED","Swim_Tread",4.1,0,1,1,1,1);
		}else if(animationplayed == 258) {
		ApplyAnimation(playerid,"PED","Tap_hand",4.1,0,1,1,1,1);
		}else if(animationplayed == 259) {
		ApplyAnimation(playerid,"PED","Tap_handP",4.1,0,1,1,1,1);
		}else if(animationplayed == 260) {
		ApplyAnimation(playerid,"PED","turn_180",4.1,0,1,1,1,1);
		}else if(animationplayed == 261) {
		ApplyAnimation(playerid,"PED","Turn_L",4.1,0,1,1,1,1);
		}else if(animationplayed == 262) {
		ApplyAnimation(playerid,"PED","Turn_R",4.1,0,1,1,1,1);
		}else if(animationplayed == 263) {
		ApplyAnimation(playerid,"PED","WALK_armed",4.1,0,1,1,1,1);
		}else if(animationplayed == 264) {
		ApplyAnimation(playerid,"PED","WALK_civi",4.1,0,1,1,1,1);
		}else if(animationplayed == 265) {
		ApplyAnimation(playerid,"PED","WALK_csaw",4.1,0,1,1,1,1);
		}else if(animationplayed == 266) {
		ApplyAnimation(playerid,"PED","Walk_DoorPartial",4.1,0,1,1,1,1);
		}else if(animationplayed == 267) {
		ApplyAnimation(playerid,"PED","WALK_drunk",4.1,0,1,1,1,1);
		}else if(animationplayed == 268) {
		ApplyAnimation(playerid,"PED","WALK_fat",4.1,0,1,1,1,1);
		}else if(animationplayed == 269) {
		ApplyAnimation(playerid,"PED","WALK_fatold",4.1,0,1,1,1,1);
		}else if(animationplayed == 270) {
		ApplyAnimation(playerid,"PED","WALK_gang1",4.1,0,1,1,1,1);
		}else if(animationplayed == 271) {
		ApplyAnimation(playerid,"PED","WALK_gang2",4.1,0,1,1,1,1);
		}else if(animationplayed == 272) {
		ApplyAnimation(playerid,"PED","WALK_old",4.1,0,1,1,1,1);
		}else if(animationplayed == 273) {
		ApplyAnimation(playerid,"PED","WALK_player",4.1,0,1,1,1,1);
		}else if(animationplayed == 274) {
		ApplyAnimation(playerid,"PED","WALK_rocket",4.1,0,1,1,1,1);
		}else if(animationplayed == 275) {
		ApplyAnimation(playerid,"PED","WALK_shuffle",4.1,0,1,1,1,1);
		}else if(animationplayed == 276) {
		ApplyAnimation(playerid,"PED","WALK_start",4.1,0,1,1,1,1);
		}else if(animationplayed == 277) {
		ApplyAnimation(playerid,"PED","WALK_start_armed",4.1,0,1,1,1,1);
		}else if(animationplayed == 278) {
		ApplyAnimation(playerid,"PED","WALK_start_csaw",4.1,0,1,1,1,1);
		}else if(animationplayed == 279) {
		ApplyAnimation(playerid,"PED","WALK_start_rocket",4.1,0,1,1,1,1);
		}else if(animationplayed == 280) {
		ApplyAnimation(playerid,"PED","Walk_Wuzi",4.1,0,1,1,1,1);
		}else if(animationplayed == 281) {
		ApplyAnimation(playerid,"PED","WEAPON_crouch",4.1,0,1,1,1,1);
		}else if(animationplayed == 282) {
		ApplyAnimation(playerid,"PED","woman_idlestance",4.1,0,1,1,1,1);
		}else if(animationplayed == 283) {
		ApplyAnimation(playerid,"PED","woman_run",4.1,0,1,1,1,1);
		}else if(animationplayed == 284) {
		ApplyAnimation(playerid,"PED","WOMAN_runbusy",4.1,0,1,1,1,1);
		}else if(animationplayed == 285) {
		ApplyAnimation(playerid,"PED","WOMAN_runfatold",4.1,0,1,1,1,1);
		}else if(animationplayed == 286) {
		ApplyAnimation(playerid,"PED","woman_runpanic",4.1,0,1,1,1,1);
		}else if(animationplayed == 287) {
		ApplyAnimation(playerid,"PED","WOMAN_runsexy",4.1,0,1,1,1,1);
		}else if(animationplayed == 288) {
		ApplyAnimation(playerid,"PED","WOMAN_walkbusy",4.1,0,1,1,1,1);
		}else if(animationplayed == 289) {
		ApplyAnimation(playerid,"PED","WOMAN_walkfatold",4.1,0,1,1,1,1);
		}else if(animationplayed == 290) {
		ApplyAnimation(playerid,"PED","WOMAN_walknorm",4.1,0,1,1,1,1);
		}else if(animationplayed == 291) {
		ApplyAnimation(playerid,"PED","WOMAN_walkold",4.1,0,1,1,1,1);
		}else if(animationplayed == 292) {
		ApplyAnimation(playerid,"PED","WOMAN_walkpro",4.1,0,1,1,1,1);
		}else if(animationplayed == 293) {
		ApplyAnimation(playerid,"PED","WOMAN_walksexy",4.1,0,1,1,1,1);
		}else if(animationplayed == 294) {
		ApplyAnimation(playerid,"PED","WOMAN_walkshop",4.1,0,1,1,1,1);
		}else if(animationplayed == 295) {
		ApplyAnimation(playerid,"PED","XPRESSscratch",4.1,0,1,1,1,1);
		}
		return 1;
		}
		if(strcmp(cmd, "/dance", true) == 0) {
		if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT) {
		tmp = strtok(cmdtext, idx);
		if(!strlen(tmp)) {
		SendClientMessage(playerid,0xFF0000FF,">Write /dance [1-3]");
		return 1;
		}
		animationplayed = strval(tmp);
		if(animationplayed < 1 || animationplayed > 3) {
		SendClientMessage(playerid,0xFF0000FF,">Write /dance [1-3]");
		return 1;
		}
		if(animationplayed == 1) {
		SetPlayerSpecialAction(playerid,SPECIAL_ACTION_DANCE1);
		} else if(animationplayed == 2) {
		SetPlayerSpecialAction(playerid,SPECIAL_ACTION_DANCE2);
		} else if(animationplayed == 3) {
		SetPlayerSpecialAction(playerid,SPECIAL_ACTION_DANCE3);
		}
		return 1;
		}
		}

	}

	if(gPlayerLogged[playerid])
	{
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
		else if(strcmp(cmd, "/kostka", true) == 0)
		{
			if(IsPlayerConnected(playerid))
			{
				new dice = random(6)+1;
				if(gDice[playerid] == 1)
				{
					format(string, sizeof(string), "*** %s rzuca kostka, upada i wskazuje %d oczek", GetPlayerNameEx(playerid), dice);
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
		else if(strcmp(cmd, "/po", true) == 0)
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
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ w pojeŸdzie.");
				return 1;
			}
			if(!gPlayerData[playerid][pDuty])
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ na s³u¿bie !");
				return 1;
			}
			if(gVehData[tmpcar][mVehFaction] != gPlayerData[playerid][pFaction])
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ w pojeŸdzie frakcyjnym.");
				return 1;
			}
			format(string, sizeof(string), "* %s mowi: ZJED NA POBOCZE !", GetPlayerNameEx(playerid));
			ProxDetector(60.0, playerid, string,COLOR_LSPD,COLOR_LSPD,COLOR_LSPD,COLOR_LSPD,COLOR_LSPD);
			return 1;
		}
		else if(strcmp(cmd, "/setint", true) == 0)
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
					SetPlayerInterior(playa, intid);
					gPlayerData[playa][pInt] = intid;

					format(string, sizeof(string), "[INFO:] You havae set %s interior to %d.", GetPlayerNameEx(playa), intid);
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
				}
			}
			return 1;
		}
		else if(strcmp(cmd, "/setvw", true) == 0)
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
					if(gPlayerData[playa][pAdmin] > 0 && (playa != playerid))
					{
						SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie mo¿esz u¿yæ tej komendy na administratorze !");
						return 1;
					}
					SetPlayerVirtualWorld(playa, virid);
					format(string, sizeof(string), "[INFO:] You have set %s virtual world to %d.", GetPlayerNameEx(playa), virid);
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
					gPlayerData[playa][pCrashW] = virid;
				}
			}
			return 1;
		}
		else if(strcmp(cmd, "/disarm", true) == 0) // Reset the player's weapons
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
				ResetPlayerWeapons(giveplayerid);
				format(string, sizeof(string), "-| Administrator %s rozbroil gracza %s |-", GetPlayerNameEx(playerid), GetPlayerNameEx(giveplayerid));
				ABroadCast(COLOR_YELLOW,string,1);
			}
			else if(giveplayerid == INVALID_PLAYER_ID)
			{
				format(string, sizeof(string), "%d nie jest on-line.", giveplayerid);
				SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
			}
			return 1;
		}
		else if(strcmp(cmd, "/odbierzbron", true) == 0) // Reset the player's weapons
		{
			if(gPlayerData[playerid][pFaction] == 9)
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
		else if(strcmp(cmd, "/coin", true) == 0)
		{
			if(IsPlayerConnected(playerid))
			{
				new coin = random(2)+1;
				new coinname[20];
				if(coin == 1) { coinname = "orla"; }
				else { coinname = "reszke"; }
				format(string, sizeof(string), "*** %s rzucil moneta ktora wskazuje %s", GetPlayerNameEx(playerid), coinname);
				ProxDetector(10.0, playerid, string, COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE);
			}
			return 1;
		}
		else if(strcmp(cmd, "/wlozbron", true) == 0) // By LordMan
		{
			if(PlayerFreeSlotCount(playerid) < 2)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Jesteœ przeci¹¿ony !");
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
					case 5: InsertPlayerItemEx(playerid, 1, 145, 0, 0, 0, 0, "Puste", gTGunAmmo);
					case 7: InsertPlayerItemEx(playerid, 1, 146, 0, 0, 0, 0, "Puste", gTGunAmmo);
					case 1: InsertPlayerItemEx(playerid, 1, 147, 0, 0, 0, 0, "Puste", gTGunAmmo);
					case 4: InsertPlayerItemEx(playerid, 1, 148, 0, 0, 0, 0, "Puste", gTGunAmmo);
					case 6: InsertPlayerItemEx(playerid, 1, 149, 0, 0, 0, 0, "Puste", gTGunAmmo);
					case 15: InsertPlayerItemEx(playerid, 1, 150, 0, 0, 0, 0, "Puste", gTGunAmmo);
				}
			}
			else
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz schowaæ tej broni !");
			return 1;
		}
		else if(strcmp(cmd, "/pokaznotki", true) == 0) // By LordMan
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
				format(string, sizeof(string), "* %s patrzy w swoj notes.", GetPlayerNameEx(playerid));
				ProxDetector(30.0, playerid, string, COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE);
			}
			return 1;
		}
		else if(strcmp(cmd, "/usunnotke",true) == 0) // By LordMan
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
				if(strcmp(x_nr, "1",true) == 0)
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
				else if(strcmp(x_nr, "2",true) == 0)
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
				else if(strcmp(x_nr, "3",true) == 0)
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
				else if(strcmp(x_nr, "4",true) == 0)
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
				else if(strcmp(x_nr, "5",true) == 0)
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
		else if(strcmp(cmd, "/zrobnotke",true) == 0) // By LordMan
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
				SavePlayerData(playerid, "Note1");
				return 1;
			}
			else if(gPlayerData[playerid][pNote2s] == 0)
			{
				strmid(gPlayerData[playerid][pNote2], result, 0, strlen(result), 255);
				gPlayerData[playerid][pNote2s] = 1;
				SendClientMessage(playerid, COLOR_WHITE, "[INFO:] Notka utworzona !");
				SavePlayerData(playerid, "Note2");
				return 1;
			}
			else if(gPlayerData[playerid][pNote3s] == 0)
			{
				strmid(gPlayerData[playerid][pNote3], result, 0, strlen(result), 255);
				gPlayerData[playerid][pNote3s] = 1;
				SendClientMessage(playerid, COLOR_WHITE, "[INFO:] Notka utworzona !");
				SavePlayerData(playerid, "Note3");
				return 1;
			}
			else if(gPlayerData[playerid][pNote4s] == 0)
			{
				strmid(gPlayerData[playerid][pNote4], result, 0, strlen(result), 255);
				gPlayerData[playerid][pNote4s] = 1;
				SendClientMessage(playerid, COLOR_WHITE, "[INFO:] Notka utworzona !");
				SavePlayerData(playerid, "Note4");
				return 1;
			}
			else if(gPlayerData[playerid][pNote5s] == 0)
			{
				strmid(gPlayerData[playerid][pNote5], result, 0, strlen(result), 255);
				gPlayerData[playerid][pNote5s] = 1;
				SendClientMessage(playerid, COLOR_WHITE, "[INFO:] Notka utworzona !");
				SavePlayerData(playerid, "Note5");
				return 1;
			}
			else
			{
				SendClientMessage(playerid, COLOR_GREY, "[INFO:] Nie masz wiecej miejsca na notatki !");
				return 1;
			}
		}
		else if(strcmp(cmd, "/przekaznotke",true) == 0) // By LordMan
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
						if(strcmp(x_nr, "1",true) == 0)
						{
							if(gPlayerData[playerid][pNote1s] == 1)
							{
								if(gPlayerData[giveplayerid][pNote1s] == 0)
								{
									strmid(gPlayerData[giveplayerid][pNote1], gPlayerData[playerid][pNote1], 0, strlen(gPlayerData[playerid][pNote1]), 255);
									gPlayerData[giveplayerid][pNote1s] = 1;
									format(string, sizeof(string), "[INFO:] Przekaza³eœ notke do %s [%d]", GetPlayerNameEx(giveplayerid), giveplayerid);
									SendClientMessage(playerid, COLOR_WHITE, string);
									format(string, sizeof(string), "[INFO:] Otrzymales notke od %s [%d]", GetPlayerNameEx(playerid), playerid);
									SendClientMessage(giveplayerid, COLOR_WHITE, string);
									SavePlayerData(giveplayerid, "Note1");
								}
								else if(gPlayerData[giveplayerid][pNote2s] == 0)
								{
									strmid(gPlayerData[giveplayerid][pNote2], gPlayerData[playerid][pNote1], 0, strlen(gPlayerData[playerid][pNote1]), 255);
									gPlayerData[giveplayerid][pNote2s] = 1;
									format(string, sizeof(string), "[INFO:] Przekaza³eœ notke do %s [%d]", GetPlayerNameEx(giveplayerid), giveplayerid);
									SendClientMessage(playerid, COLOR_WHITE, string);
									format(string, sizeof(string), "[INFO:] Otrzymales notke od %s [%d]", GetPlayerNameEx(playerid), playerid);
									SendClientMessage(giveplayerid, COLOR_WHITE, string);
									SavePlayerData(giveplayerid, "Note2");
								}
								else if(gPlayerData[giveplayerid][pNote3s] == 0)
								{
									strmid(gPlayerData[giveplayerid][pNote3], gPlayerData[playerid][pNote1], 0, strlen(gPlayerData[playerid][pNote1]), 255);
									gPlayerData[giveplayerid][pNote3s] = 1;
									format(string, sizeof(string), "[INFO:] Przekaza³eœ notke do %s [%d]", GetPlayerNameEx(giveplayerid), giveplayerid);
									SendClientMessage(playerid, COLOR_WHITE, string);
									format(string, sizeof(string), "[INFO:] Otrzymales notke od %s [%d]", GetPlayerNameEx(playerid), playerid);
									SendClientMessage(giveplayerid, COLOR_WHITE, string);
									SavePlayerData(giveplayerid, "Note3");
								}
								else if(gPlayerData[giveplayerid][pNote4s] == 0)
								{
									strmid(gPlayerData[giveplayerid][pNote4], gPlayerData[playerid][pNote1], 0, strlen(gPlayerData[playerid][pNote1]), 255);
									gPlayerData[giveplayerid][pNote4s] = 1;
									format(string, sizeof(string), "[INFO:] Przekaza³eœ notke do %s [%d]", GetPlayerNameEx(giveplayerid), giveplayerid);
									SendClientMessage(playerid, COLOR_WHITE, string);
									format(string, sizeof(string), "[INFO:] Otrzymales notke od %s [%d]", GetPlayerNameEx(playerid), playerid);
									SendClientMessage(giveplayerid, COLOR_WHITE, string);
									SavePlayerData(giveplayerid, "Note4");
								}
								else if(gPlayerData[giveplayerid][pNote5s] == 0)
								{
									strmid(gPlayerData[giveplayerid][pNote5], gPlayerData[playerid][pNote1], 0, strlen(gPlayerData[playerid][pNote1]), 255);
									gPlayerData[giveplayerid][pNote5s] = 1;
									format(string, sizeof(string), "[INFO:] Przekaza³eœ notke do %s [%d]", GetPlayerNameEx(giveplayerid), giveplayerid);
									SendClientMessage(playerid, COLOR_WHITE, string);
									format(string, sizeof(string), "[INFO:] Otrzymales notke od %s [%d]", GetPlayerNameEx(playerid), playerid);
									SendClientMessage(giveplayerid, COLOR_WHITE, string);
									SavePlayerData(giveplayerid, "Note5");
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
						else if(strcmp(x_nr, "2",true) == 0)
						{
							if(gPlayerData[playerid][pNote2s] == 1)
							{
								if(gPlayerData[giveplayerid][pNote1s] == 0)
								{
									strmid(gPlayerData[giveplayerid][pNote1], gPlayerData[playerid][pNote2], 0, strlen(gPlayerData[playerid][pNote2]), 255);
									gPlayerData[giveplayerid][pNote1s] = 1;
									format(string, sizeof(string), "[INFO:] Przekaza³eœ notke do %s [%d]", GetPlayerNameEx(giveplayerid), giveplayerid);
									SendClientMessage(playerid, COLOR_WHITE, string);
									format(string, sizeof(string), "[INFO:] Otrzymales notke od %s [%d]", GetPlayerNameEx(playerid), playerid);
									SendClientMessage(giveplayerid, COLOR_WHITE, string);
									SavePlayerData(giveplayerid, "Note1");
								}
								else if(gPlayerData[giveplayerid][pNote2s] == 0)
								{
									strmid(gPlayerData[giveplayerid][pNote2], gPlayerData[playerid][pNote2], 0, strlen(gPlayerData[playerid][pNote2]), 255);
									gPlayerData[giveplayerid][pNote2s] = 1;
									format(string, sizeof(string), "[INFO:] Przekaza³eœ notke do %s [%d]", GetPlayerNameEx(giveplayerid), giveplayerid);
									SendClientMessage(playerid, COLOR_WHITE, string);
									format(string, sizeof(string), "[INFO:] Otrzymales notke od %s [%d]", GetPlayerNameEx(playerid), playerid);
									SendClientMessage(giveplayerid, COLOR_WHITE, string);
									SavePlayerData(giveplayerid, "Note2");
								}
								else if(gPlayerData[giveplayerid][pNote3s] == 0)
								{
									strmid(gPlayerData[giveplayerid][pNote3], gPlayerData[playerid][pNote2], 0, strlen(gPlayerData[playerid][pNote2]), 255);
									gPlayerData[giveplayerid][pNote3s] = 1;
									format(string, sizeof(string), "[INFO:] Przekaza³eœ notke do %s [%d]", GetPlayerNameEx(giveplayerid), giveplayerid);
									SendClientMessage(playerid, COLOR_WHITE, string);
									format(string, sizeof(string), "[INFO:] Otrzymales notke od %s [%d]", GetPlayerNameEx(playerid), playerid);
									SendClientMessage(giveplayerid, COLOR_WHITE, string);
									SavePlayerData(giveplayerid, "Note3");
								}
								else if(gPlayerData[giveplayerid][pNote4s] == 0)
								{
									strmid(gPlayerData[giveplayerid][pNote4], gPlayerData[playerid][pNote2], 0, strlen(gPlayerData[playerid][pNote2]), 255);
									gPlayerData[giveplayerid][pNote4s] = 1;
									format(string, sizeof(string), "[INFO:] Przekaza³eœ notke do %s [%d]", GetPlayerNameEx(giveplayerid), giveplayerid);
									SendClientMessage(playerid, COLOR_WHITE, string);
									format(string, sizeof(string), "[INFO:] Otrzymales notke od %s [%d]", GetPlayerNameEx(playerid), playerid);
									SendClientMessage(giveplayerid, COLOR_WHITE, string);
									SavePlayerData(giveplayerid, "Note4");
								}
								else if(gPlayerData[giveplayerid][pNote5s] == 0)
								{
									strmid(gPlayerData[giveplayerid][pNote5], gPlayerData[playerid][pNote2], 0, strlen(gPlayerData[playerid][pNote2]), 255);
									gPlayerData[giveplayerid][pNote5s] = 1;
									format(string, sizeof(string), "[INFO:] Przekaza³eœ notke do %s [%d]", GetPlayerNameEx(giveplayerid), giveplayerid);
									SendClientMessage(playerid, COLOR_WHITE, string);
									format(string, sizeof(string), "[INFO:] Otrzymales notke od %s [%d]", GetPlayerNameEx(playerid), playerid);
									SendClientMessage(giveplayerid, COLOR_WHITE, string);
									SavePlayerData(giveplayerid, "Note5");
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
						else if(strcmp(x_nr, "3",true) == 0)
						{
							if(gPlayerData[playerid][pNote3s] == 1)
							{
								if(gPlayerData[giveplayerid][pNote1s] == 0)
								{
									strmid(gPlayerData[giveplayerid][pNote1], gPlayerData[playerid][pNote3], 0, strlen(gPlayerData[playerid][pNote3]), 255);
									gPlayerData[giveplayerid][pNote1s] = 1;
									format(string, sizeof(string), "[INFO:] Przekaza³eœ notke do %s [%d]", GetPlayerNameEx(giveplayerid), giveplayerid);
									SendClientMessage(playerid, COLOR_WHITE, string);
									format(string, sizeof(string), "[INFO:] Otrzymales notke od %s [%d]", GetPlayerNameEx(playerid), playerid);
									SendClientMessage(giveplayerid, COLOR_WHITE, string);
									SavePlayerData(giveplayerid, "Note1");
								}
								else if(gPlayerData[giveplayerid][pNote2s] == 0)
								{
									strmid(gPlayerData[giveplayerid][pNote2], gPlayerData[playerid][pNote3], 0, strlen(gPlayerData[playerid][pNote3]), 255);
									gPlayerData[giveplayerid][pNote2s] = 1;
									format(string, sizeof(string), "[INFO:] Przekaza³eœ notke do %s [%d]", GetPlayerNameEx(giveplayerid), giveplayerid);
									SendClientMessage(playerid, COLOR_WHITE, string);
									format(string, sizeof(string), "[INFO:] Otrzymales notke od %s [%d]", GetPlayerNameEx(playerid), playerid);
									SendClientMessage(giveplayerid, COLOR_WHITE, string);
									SavePlayerData(giveplayerid, "Note2");
								}
								else if(gPlayerData[giveplayerid][pNote3s] == 0)
								{
									strmid(gPlayerData[giveplayerid][pNote3], gPlayerData[playerid][pNote3], 0, strlen(gPlayerData[playerid][pNote3]), 255);
									gPlayerData[giveplayerid][pNote3s] = 1;
									format(string, sizeof(string), "[INFO:] Przekaza³eœ notke do %s [%d]", GetPlayerNameEx(giveplayerid), giveplayerid);
									SendClientMessage(playerid, COLOR_WHITE, string);
									format(string, sizeof(string), "[INFO:] Otrzymales notke od %s [%d]", GetPlayerNameEx(playerid), playerid);
									SendClientMessage(giveplayerid, COLOR_WHITE, string);
									SavePlayerData(giveplayerid, "Note3");
								}
								else if(gPlayerData[giveplayerid][pNote4s] == 0)
								{
									strmid(gPlayerData[giveplayerid][pNote4], gPlayerData[playerid][pNote4], 0, strlen(gPlayerData[playerid][pNote4]), 255);
									gPlayerData[giveplayerid][pNote4s] = 1;
									format(string, sizeof(string), "[INFO:] Przekaza³eœ notke do %s [%d]", GetPlayerNameEx(giveplayerid), giveplayerid);
									SendClientMessage(playerid, COLOR_WHITE, string);
									format(string, sizeof(string), "[INFO:] Otrzymales notke od %s [%d]", GetPlayerNameEx(playerid), playerid);
									SendClientMessage(giveplayerid, COLOR_WHITE, string);
									SavePlayerData(giveplayerid, "Note4");
								}
								else if(gPlayerData[giveplayerid][pNote5s] == 0)
								{
									strmid(gPlayerData[giveplayerid][pNote5], gPlayerData[playerid][pNote5], 0, strlen(gPlayerData[playerid][pNote5]), 255);
									gPlayerData[giveplayerid][pNote5s] = 1;
									format(string, sizeof(string), "[INFO:] Przekaza³eœ notke do %s [%d]", GetPlayerNameEx(giveplayerid), giveplayerid);
									SendClientMessage(playerid, COLOR_WHITE, string);
									format(string, sizeof(string), "[INFO:] Otrzymales notke od %s [%d]", GetPlayerNameEx(playerid), playerid);
									SendClientMessage(giveplayerid, COLOR_WHITE, string);
									SavePlayerData(giveplayerid, "Note5");
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
						else if(strcmp(x_nr, "4",true) == 0)
						{
							if(gPlayerData[playerid][pNote4s] == 1)
							{
								if(gPlayerData[giveplayerid][pNote1s] == 0)
								{
									strmid(gPlayerData[giveplayerid][pNote1], gPlayerData[playerid][pNote4], 0, strlen(gPlayerData[playerid][pNote4]), 255);
									gPlayerData[giveplayerid][pNote1s] = 1;
									format(string, sizeof(string), "[INFO:] Przekaza³eœ notke do %s [%d]", GetPlayerNameEx(giveplayerid), giveplayerid);
									SendClientMessage(playerid, COLOR_WHITE, string);
									format(string, sizeof(string), "[INFO:] Otrzymales notke od %s [%d]", GetPlayerNameEx(playerid), playerid);
									SendClientMessage(giveplayerid, COLOR_WHITE, string);
									SavePlayerData(giveplayerid, "Note1");
								}
								else if(gPlayerData[giveplayerid][pNote2s] == 0)
								{
									strmid(gPlayerData[giveplayerid][pNote2], gPlayerData[playerid][pNote4], 0, strlen(gPlayerData[playerid][pNote4]), 255);
									gPlayerData[giveplayerid][pNote2s] = 1;
									format(string, sizeof(string), "[INFO:] Przekaza³eœ notke do %s [%d]", GetPlayerNameEx(giveplayerid), giveplayerid);
									SendClientMessage(playerid, COLOR_WHITE, string);
									format(string, sizeof(string), "[INFO:] Otrzymales notke od %s [%d]", GetPlayerNameEx(playerid), playerid);
									SendClientMessage(giveplayerid, COLOR_WHITE, string);
									SavePlayerData(giveplayerid, "Note2");
								}
								else if(gPlayerData[giveplayerid][pNote3s] == 0)
								{
									strmid(gPlayerData[giveplayerid][pNote3], gPlayerData[playerid][pNote4], 0, strlen(gPlayerData[playerid][pNote4]), 255);
									gPlayerData[giveplayerid][pNote3s] = 1;
									format(string, sizeof(string), "[INFO:] Przekaza³eœ notke do %s [%d]", GetPlayerNameEx(giveplayerid), giveplayerid);
									SendClientMessage(playerid, COLOR_WHITE, string);
									format(string, sizeof(string), "[INFO:] Otrzymales notke od %s [%d]", GetPlayerNameEx(playerid), playerid);
									SendClientMessage(giveplayerid, COLOR_WHITE, string);
									SavePlayerData(giveplayerid, "Note3");
								}
								else if(gPlayerData[giveplayerid][pNote4s] == 0)
								{
									strmid(gPlayerData[giveplayerid][pNote4], gPlayerData[playerid][pNote4], 0, strlen(gPlayerData[playerid][pNote4]), 255);
									gPlayerData[giveplayerid][pNote4s] = 1;
									format(string, sizeof(string), "[INFO:] Przekaza³eœ notke do %s [%d]", GetPlayerNameEx(giveplayerid), giveplayerid);
									SendClientMessage(playerid, COLOR_WHITE, string);
									format(string, sizeof(string), "[INFO:] Otrzymales notke od %s [%d]", GetPlayerNameEx(playerid), playerid);
									SendClientMessage(giveplayerid, COLOR_WHITE, string);
									SavePlayerData(giveplayerid, "Note4");
								}
								else if(gPlayerData[giveplayerid][pNote5s] == 0)
								{
									strmid(gPlayerData[giveplayerid][pNote5], gPlayerData[playerid][pNote4], 0, strlen(gPlayerData[playerid][pNote4]), 255);
									gPlayerData[giveplayerid][pNote5s] = 1;
									format(string, sizeof(string), "[INFO:] Przekaza³eœ notke do %s [%d]", GetPlayerNameEx(giveplayerid), giveplayerid);
									SendClientMessage(playerid, COLOR_WHITE, string);
									format(string, sizeof(string), "[INFO:] Otrzymales notke od %s [%d]", GetPlayerNameEx(playerid), playerid);
									SendClientMessage(giveplayerid, COLOR_WHITE, string);
									SavePlayerData(giveplayerid, "Note5");
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
						else if(strcmp(x_nr, "5",true) == 0)
						{
							if(gPlayerData[playerid][pNote5s] == 1)
							{
								if(gPlayerData[giveplayerid][pNote1s] == 0)
								{
									strmid(gPlayerData[giveplayerid][pNote1], gPlayerData[playerid][pNote5], 0, strlen(gPlayerData[playerid][pNote5]), 255);
									gPlayerData[giveplayerid][pNote1s] = 1;
									format(string, sizeof(string), "[INFO:] Przekaza³eœ notke do %s [%d]", GetPlayerNameEx(giveplayerid), giveplayerid);
									SendClientMessage(playerid, COLOR_WHITE, string);
									format(string, sizeof(string), "[INFO:] Otrzymales notke od %s [%d]", GetPlayerNameEx(playerid), playerid);
									SendClientMessage(giveplayerid, COLOR_WHITE, string);
									SavePlayerData(giveplayerid, "Note1");
								}
								else if(gPlayerData[giveplayerid][pNote2s] == 0)
								{
									strmid(gPlayerData[giveplayerid][pNote2], gPlayerData[playerid][pNote5], 0, strlen(gPlayerData[playerid][pNote5]), 255);
									gPlayerData[giveplayerid][pNote2s] = 1;
									format(string, sizeof(string), "[INFO:] Przekaza³eœ notke do %s [%d]", GetPlayerNameEx(giveplayerid), giveplayerid);
									SendClientMessage(playerid, COLOR_WHITE, string);
									format(string, sizeof(string), "[INFO:] Otrzymales notke od %s [%d]", GetPlayerNameEx(playerid), playerid);
									SendClientMessage(giveplayerid, COLOR_WHITE, string);
									SavePlayerData(giveplayerid, "Note2");
								}
								else if(gPlayerData[giveplayerid][pNote3s] == 0)
								{
									strmid(gPlayerData[giveplayerid][pNote3], gPlayerData[playerid][pNote5], 0, strlen(gPlayerData[playerid][pNote5]), 255);
									gPlayerData[giveplayerid][pNote3s] = 1;
									format(string, sizeof(string), "[INFO:] Przekaza³eœ notke do %s [%d]", GetPlayerNameEx(giveplayerid), giveplayerid);
									SendClientMessage(playerid, COLOR_WHITE, string);
									format(string, sizeof(string), "[INFO:] Otrzymales notke od %s [%d]", GetPlayerNameEx(playerid), playerid);
									SendClientMessage(giveplayerid, COLOR_WHITE, string);
									SavePlayerData(giveplayerid, "Note3");
								}
								else if(gPlayerData[giveplayerid][pNote4s] == 0)
								{
									strmid(gPlayerData[giveplayerid][pNote4], gPlayerData[playerid][pNote5], 0, strlen(gPlayerData[playerid][pNote5]), 255);
									gPlayerData[giveplayerid][pNote4s] = 1;
									format(string, sizeof(string), "[INFO:] Przekaza³eœ notke do %s [%d]", GetPlayerNameEx(giveplayerid), giveplayerid);
									SendClientMessage(playerid, COLOR_WHITE, string);
									format(string, sizeof(string), "[INFO:] Otrzymales notke od %s [%d]", GetPlayerNameEx(playerid), playerid);
									SendClientMessage(giveplayerid, COLOR_WHITE, string);
									SavePlayerData(giveplayerid, "Note4");
								}
								else if(gPlayerData[giveplayerid][pNote5s] == 0)
								{
									strmid(gPlayerData[giveplayerid][pNote5], gPlayerData[playerid][pNote5], 0, strlen(gPlayerData[playerid][pNote5]), 255);
									gPlayerData[giveplayerid][pNote5s] = 1;
									format(string, sizeof(string), "[INFO:] Przekaza³eœ notke do %s [%d]", GetPlayerNameEx(giveplayerid), giveplayerid);
									SendClientMessage(playerid, COLOR_WHITE, string);
									format(string, sizeof(string), "[INFO:] Otrzymales notke od %s [%d]", GetPlayerNameEx(playerid), playerid);
									SendClientMessage(giveplayerid, COLOR_WHITE, string);
									SavePlayerData(giveplayerid, "Note5");
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
		else if(strcmp(cmd, "/akceptujochroniarza", true) == 0)
		{
			if(GuardOffer[playerid] < 999)
			{
				if(GetPlayerMoney(playerid) > GuardPrice[playerid])
				{
					if(IsPlayerConnected(GuardOffer[playerid]))
					{
						format(string, sizeof(string), "* Zaakceptowales protekcje za %d$ od %s.",GuardPrice[playerid], GetPlayerNameEx(GuardOffer[playerid]));
						SendClientMessage(playerid, COLOR_WHITE, string);
						format(string, sizeof(string), "* %s zaakceptowal twoja protekcje i przelal %d$ na twoj rachunek.",GetPlayerNameEx(playerid), GuardPrice[playerid]);
						SendClientMessage(GuardOffer[playerid], COLOR_WHITE, string);
						gPlayerData[GuardOffer[playerid]][pPayCheck] += GuardPrice[playerid] * 5;

						SavePlayerData(GuardOffer[playerid], "PayCheck");

						GivePlayerCash(playerid, -GuardPrice[playerid]);
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
		else if(strcmp(cmd, "/ochroniarz", true) == 0)
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
							format(string, sizeof(string), "* Zaoferowales protekcje %s za %d$.", GetPlayerNameEx(giveplayerid), money);
							SendClientMessage(playerid, COLOR_WHITE, string);
							format(string, sizeof(string), "* Ochroniarz %s chce Cie chronic za %d$, (wpisz /akceptujochroniarza) by go przyjac.", GetPlayerNameEx(playerid), money);
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
		else if(strcmp(cmd, "/checkweapons", true) == 0) // Edited by LordMan, orginally from CW-RP
		{
			if(gPlayerData[playerid][pModerator] == 0)
				return 0;
			tmp = strtok(cmdtext,idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_GREY, "U¯YCIE: /checkweapons [playerid/partOName]");
				return 1;
			}
			giveplayerid = ReturnUser(tmp);
			if(giveplayerid == INVALID_PLAYER_ID)
			{
				SendClientMessage(playerid, COLOR_GREY, "[INFO:] Ten gracz jest off-line");
				return 1;
			}
			new sweapon, sammo;
			format(string, sizeof(string), "%s posiada nastepujace bronie:", GetPlayerNameEx(giveplayerid));
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
		else if(strcmp(cmd, "/sprawdzbron", true) == 0) // Edited by LordMan, orginally from CW-RP
		{
			if(gPlayerData[playerid][pFaction] != 9)
			{
				SendClientMessage(playerid, COLOR_GREY, "[INFO:] nie jesteœ upowazniony do uzywania tej komendy !");
				return 1;
			}
			tmp = strtok(cmdtext,idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_GREY, "U¯YCIE: /sprawdzbron [playerid/partOName]");
				return 1;
			}
			giveplayerid = ReturnUser(tmp);
			if(giveplayerid == INVALID_PLAYER_ID)
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
		else if(strcmp(cmd, "/prison",true) == 0)
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
					format(string, sizeof(string), "* Umiesciles %s w Forcie DeMorgana.", GetPlayerNameEx(giveplayerid));
					SendClientMessage(playerid, COLOR_LIGHTRED, string);
					format(string, sizeof(string), "* Zostales umieszczony Forcie DeMorgana przez Admina %s.", GetPlayerNameEx(playerid));
					SendClientMessage(giveplayerid, COLOR_LIGHTRED, string);
					GameTextForPlayer(giveplayerid, "~w~Witaj w ~n~~r~Forcie DeMorgana", 5000, 3);
					WantedLevel[giveplayerid] = 0;
					gPlayerData[giveplayerid][pJailed] = 2;
					gPlayerData[giveplayerid][pJailTime] = 3600;

					SavePlayerData(giveplayerid, "Jailed");
					SavePlayerData(giveplayerid, "JailTime");

					SetPlayerToPos(giveplayerid, 107.2300,1920.6311,18.5208);
					SetPlayerWorldBounds(giveplayerid, 337.5694,101.5826,1940.9759,1798.7453); //285.3481,96.9720,1940.9755,1799.0811
					SetPlayerInterior(giveplayerid,0);
					gPlayerData[giveplayerid][pInt] = 0;

					SavePlayerData(giveplayerid, "CrashInt");

					format(string, 256, "[SYSTEM]: %s zostal uwieziony przez Admina %s.", GetPlayerNameEx(giveplayerid), GetPlayerNameEx(playerid));
					ABroadCast(COLOR_YELLOW,string,1);
					format(string, sizeof(string), "[SYSTEM]: %s zostal uwieziony przez %s", GetPlayerNameEx(giveplayerid), GetPlayerNameEx(playerid));
					printf("%s",string);
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_GREY, "[INFO:] Gracz nie jest on-line !");
				return 1;
			}
		}
		else if(strcmp(cmd, "/unprison",true) == 0)
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
					format(string, sizeof(string), "* Zostales puszczony %s.", GetPlayerNameEx(giveplayerid));
					SendClientMessage(playerid, COLOR_LIGHTRED, string);
					format(string, sizeof(string), "* Zostales puszczony przez Admina %s.", GetPlayerNameEx(playerid));
					SendClientMessage(giveplayerid, COLOR_LIGHTRED, string);
					gPlayerData[giveplayerid][pJailTime] = 0;
					gPlayerData[giveplayerid][pJailed] = 0;

					SavePlayerData(giveplayerid, "Jailed");
					SavePlayerData(giveplayerid, "JailTime");

					SetPlayerWorldBounds(giveplayerid, 20000.0000,-20000.0000,20000.0000,-20000.0000);
					SetPlayerToPos(giveplayerid, 93.4852,1920.6235,18.0450);
					format(string, 256, "[SYSTEM:] %s zostal wypuszczony przez Admina %s.", GetPlayerNameEx(giveplayerid), GetPlayerNameEx(playerid));
					ABroadCast(COLOR_YELLOW,string,1);
					format(string, 256, "[SYSTEM:] %s zostal wypuszczony przez Admina %s.", GetPlayerNameEx(giveplayerid), GetPlayerNameEx(playerid));
					ABroadCast(COLOR_YELLOW,string,1);
				}
			}
			return 1;
		}
		else if(strcmp(cmd, "/donos", true) == 0 || strcmp(cmd, "/re", true) == 0)
		{
			if(gReportCooldown > 0)
			{
				SendClientMessage(playerid, COLOR_RED, "[INFO:] Ktoœ ju¿ wys³a³ donos. Musisz chwile poczekaæ przed wys³aniem kolejnego !");
				return 1;
			}
			gReportCooldown = 10;
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
					format(string, sizeof(string), "Donos od: [ID:%d]%s, doniosl na gracza: [ID:%d]%s", playerid, GetPlayerNameEx(playerid), GetPlayerNameEx(giveplayerid), giveplayerid);
					ABroadCast(0xE19898AA,string,1);
					SendModMessage(0xE19898AA, string);
					format(string, sizeof(string), "Tresc donosu: %s", (result));
					SendModMessage(0xE19898AA, string);
					ABroadCast(0xE19898AA,string,1);
					ABroadCast(0xA04C4CAA, "Wpisz '/akceptujraport [reporter id]' lub '/wyrzucraporty [reporter id]'",1);
					SendModMessage(0xE19898AA, "Wpisz '/akceptujraport [reporter id]' lub '/wyrzucraporty [reporter id]'");
					SendClientMessage(playerid, 0x96C184AA, "[INFO:] Admini przejrza report, dziekujemy za zgloszenie.");
					PlayerNeedsHelp[playerid] = 1;
					SetTimerEx("ReportReset", 120000, false, "i", playerid);
				}
			}
			return 1;
		}
		else if(strcmp(cmd, "/akceptujraport", true) == 0) // By LordMan
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
						format(string, sizeof(string), "[INFO:] %s wlasnie zaakceptowal raport [ID:%d]%s.", GetPlayerNameEx(playerid), GetPlayerNameEx(giveplayerid), giveplayerid);
						ABroadCast(COLOR_YELLOW, string, 1);
						format(string, sizeof(string), "** Administrator [ID:%d]%s zaakceptowal Twoj raport ! Please be patience.", playerid, GetPlayerNameEx(playerid));
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
		else if(strcmp(cmd, "/usunraport", true) == 0) // By LordMan
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
						format(string, sizeof(string), "[INFO:] %s wyrzucil wlasnie raport [%d] %s.", GetPlayerNameEx(playerid), GetPlayerNameEx(giveplayerid), giveplayerid);
						ABroadCast(COLOR_YELLOW, string, 1);
						format(string, sizeof(string), "** Administrator [%d] %s odrzucil Twoj raport !", playerid, GetPlayerNameEx(playerid));
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
		else if(strcmp(cmd, "/destroy", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 1)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_GRAD2, "U¯YCIE: /destroy [playerid/PartOName]");
				return 1;
			}
			giveplayerid = ReturnUser(tmp);
			if(IsPlayerConnected(giveplayerid))
			{
				if(giveplayerid != INVALID_PLAYER_ID)
				{
					GetPlayerHealth(giveplayerid, gPlayerData[giveplayerid][pHP]);
					SetPlayerHealth(giveplayerid, gPlayerData[giveplayerid][pHP]-5.0);
					GetPlayerPos(giveplayerid, gPlayerData[giveplayerid][pCrashX], gPlayerData[giveplayerid][pCrashY], gPlayerData[giveplayerid][pCrashZ]);
					SetPlayerToPos(giveplayerid, gPlayerData[giveplayerid][pCrashX], gPlayerData[giveplayerid][pCrashY], gPlayerData[giveplayerid][pCrashZ]+99);
					PlayerPlaySound(giveplayerid, 1130, gPlayerData[giveplayerid][pCrashX], gPlayerData[giveplayerid][pCrashY], gPlayerData[giveplayerid][pCrashZ]+90);
					printf("%s slapped %s", GetPlayerNameEx(playerid),  GetPlayerNameEx(giveplayerid));
					format(string, sizeof(string), "[INFO:] %s zostal zniszczony przez %s", GetPlayerNameEx(giveplayerid), GetPlayerNameEx(playerid));
					ABroadCast(COLOR_YELLOW,string,1);
				}
			}
			return 1;
		}
		else if(strcmp(cmd, "/setskin", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
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
					gPlayerData[para1][pSkin] = level;

					SavePlayerData(para1, "Skin");

					format(string, sizeof(string), "Twoj skin zostal zmieniony przez admina %s", GetPlayerNameEx(playerid));
					SendClientMessage(para1, COLOR_WHITE, string);
					format(string, sizeof(string), "You have given %s skin to %d.", GetPlayerNameEx(giveplayerid), level);
					SendClientMessage(playerid, COLOR_WHITE, string);
					SetPlayerSkin(para1, gPlayerData[para1][pSkin]);
				}
			}//not connected
			return 1;
		}
		else if(strcmp(cmd, "/szepcz", true) == 0 || strcmp(cmd, "/s", true) == 0)
		{
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_GRAD2, "U¯YCIE: (/s)zczepcz [id gracza] [tekst]");
				return 1;
			}
			giveplayerid = ReturnUser(tmp);
			if(IsPlayerConnected(giveplayerid))
			{
				if(giveplayerid != INVALID_PLAYER_ID)
				{
					new Float:x, Float:y, Float:z;
					GetPlayerPos(giveplayerid,x,y,z);
					if(PlayerToPoint(5, playerid, x, y, z))
					{
						if(giveplayerid == playerid)
						{
							format(string, sizeof(string), "* %s cos do siebie szczepcze.", GetPlayerNameEx(playerid));
							ProxDetector(5.0, playerid, string, COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE,COLOR_PURPLE);
						}
						else
						{
							format(string, sizeof(string), "* %s szepcze do %s", GetPlayerNameEx(playerid), GetPlayerNameEx(giveplayerid));
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
						format(string, sizeof(string), "%s szepcze: %s", GetPlayerNameEx(giveplayerid), (result));
						SendClientMessage(giveplayerid, COLOR_YELLOW, string);
						format(string, sizeof(string), "%s szepcze: %s", GetPlayerNameEx(giveplayerid), (result));
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
		else if(strcmp(cmd, "/supervehslap", true) == 0 || strcmp(cmd, "/svs", true) == 0)
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
			if(gPlayerData[playerid][pAdmin] >= 5)
			{
				if(IsPlayerConnected(playa))
				{
					if(playa != INVALID_PLAYER_ID)
					{
						GetPlayerHealth(playa, shealth);
						SetPlayerHealth(playa, shealth-0);
						GetVehiclePos(GetPlayerVehicleID(giveplayerid), slx, sly, slz);
						SetVehicleToPos(GetPlayerVehicleID(giveplayerid), slx, sly, slz+100);
						PlayerPlaySound(playa, 1130, slx, sly, slz+5);
						printf("South-West Admin System: %s vehicle slapped %s", GetPlayerNameEx(playerid), GetPlayerNameEx(giveplayerid));
						format(string, sizeof(string), "%s was vehicle slapped slapped by %s", GetPlayerNameEx(giveplayerid), GetPlayerNameEx(playerid));
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
		else if(strcmp(cmd, "/explode", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] != 5)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_GREY, "/explode [Playerid]");
				return 1;
			}
			giveplayerid = strval(tmp);
			if(IsPlayerConnected(giveplayerid))
			{
				if(IsPlayerConnected(giveplayerid))
				{
					format(string, sizeof(string), "[SERVER:] %s zostal wyjebany w powietrze przez %s", GetPlayerNameEx(giveplayerid), GetPlayerNameEx(playerid));
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
		else if(strcmp(cmd, "/slap", true) == 0)
		{
			if(!gPlayerData[playerid][pModerator])
				return 0;
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
			
			if(IsPlayerConnected(playa))
			{
				GetPlayerName(playa, giveplayer, sizeof(giveplayer));
				GetPlayerName(playerid, sendername, sizeof(sendername));
				GetPlayerHealth(playa, shealth);
				SetPlayerHealth(playa, shealth-1);
				GetPlayerPos(playa, slx, sly, slz);
				SetPlayerToPos(playa, slx, sly, slz+6);
				PlayerPlaySound(playa, 1130, slx, sly, slz+6);
				format(string, sizeof(string), "%s was slapped by %s",giveplayer ,sendername);
				ABroadCast(COLOR_YELLOW,string,1);
			}
			return 1;
		}
		else if(strcmp(cmd, "/asetleader", true) == 0)
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

						// AddExpPoint(para1);
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
		else if(strcmp(cmd, "/ogloszenie", true) == 0 || strcmp(cmd, "/ad", true) == 0)
		{
			new length = strlen(cmdtext);
			while ((idx < length) && (cmdtext[idx] <= ' '))
			{
				idx++;
			}
			new offset = idx;
			new result[256];
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
				if(PlayerToPoint(1.0, playerid,Businesses[i][EnterX], Businesses[i][EnterY], Businesses[i][EnterZ]) || PlayerToPoint(25.0, playerid,Businesses[i][ExitX], Businesses[i][ExitY], Businesses[i][ExitZ]))
				{
					if(GetPlayerVirtualWorld(playerid) == i)
					{
						if(Businesses[i][BizType] == 5)
						{
							if(Businesses[i][Products] != 0)
							{
								if(gAddCooldown[playerid] > 0 && gPlayerData[playerid][pAdmin] == 0)
								{
									format(string, sizeof(string), "[INFO:] Musisz poczekaæ %d sekund zanim wystawisz nowe og³oszenie",  gAddCooldown[playerid]);
									SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
									return 1;
								}
								payout = idx * 5;
								if(GetPlayerCash(playerid) < payout)
								{
									SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie masz wystarczajacej ilosci pieniedzy.");
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
								format(string, sizeof(string), "[INFO:] Znaki zawarte: %d - Koszt: %d$ - Podziekowania od %s", idx,payout,Businesses[i][BusinessName]);
								SendClientMessage(playerid, COLOR_WHITE, string);
								
								SendSmsToAll(playerid, 7100, result);
								
								PlayerActionMessage(playerid,15.0, "da³ pracownikowi firmy troche pieniêdzy otrzymuj¹c w zamian wystawione og³oszenie plus SMS");

								SaveBizData(i, "Till");
								SaveBizData(i, "Products");
								return 1;
							}
							else
							{
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] W biznesie brakuje poroduktów");
								return 1;
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten biznes to nie firma reklamujaca");
							return 1;
						}
					}
				}
				
			}
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ w budynku biznesu");
			return 1;
		}
		else if(strcmp(cmd, "/agotobiz", true) == 0)
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
		else if(strcmp(cmd, "/abiztype", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[BUSINESS TYPES:]");
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
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[BUSINESS TYPES:]");
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

				format(string, sizeof(string), "Cena: %d$",Businesses[id][BizPrice]);
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

				format(string, sizeof(string), "Wejœciówka: %d$",Businesses[id][EntranceCost]);
				UpdateDynamic3DTextLabelText(Business3DTextLabelC[id], COLOR_LIGHTBLUE2, string);
			}
			Businesses[id][BizType] = id2;
			format(form, sizeof form, "You've set Businesses ID: %d's type to %d.", id,id2);
			SendClientMessage(playerid, COLOR_ADMINCMD,form);
			SaveBizData(id, "BizType");
			return 1;
		}
		else if(strcmp(cmd, "/abizentrance", true) == 0)
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
			Businesses[id][PickupID] = CreateDynamicPickup(pmodel, 1, Businesses[id][EnterX], Businesses[id][EnterY], Businesses[id][EnterZ]);
			
			ReloadBizText(id);
			
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
		else if(strcmp(cmd, "/cenabiz", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] != 5)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ta komenda zosta³a zablokowana !");
				return 1;
			}
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /cenabiz [businessid] [price]");
				return 1;
			}
			if(gPlayerData[playerid][pFaction] == 9)
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
						DestroyDynamic3DTextLabel(Business3DTextLabelC[id]);
						format(string, sizeof(string), "Cena: %d$",Businesses[id][BizPrice]);
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
				GovermentLog(form);
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ urzednikiem");
			}
			return 1;
		}
		else if(strcmp(cmd, "/typbiz", true) == 0)
		{
			SendClientMessage(playerid, COLOR_RED, "[INFO:] Ta komenda zosta³a zablokowana");
			return 1;
			// tmp = strtok(cmdtext, idx);
			// if(!strlen(tmp))
			// {
				// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[BUSINESS TYPES:]");
				// SendClientMessage(playerid, COLOR_ADMINCMD,BUSINESS_TYPES);
				// SendClientMessage(playerid, COLOR_ADMINCMD,BUSINESS_TYPES2);
				// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /typbiz [businessid] [type]");
				// return 1;
			// }
			// if(gPlayerData[playerid][pFaction] == 9)
			// {
					// new id;
					// new form[128];
					// id = strval(tmp);
					// tmp = strtok(cmdtext, idx);
					// if(!strlen(tmp))
					// {
						// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[BUSINESS TYPES:]");
						// SendClientMessage(playerid, COLOR_ADMINCMD,BUSINESS_TYPES);
						// SendClientMessage(playerid, COLOR_ADMINCMD,BUSINESS_TYPES2);
						// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /typbiz [businessid] [type]");
						// return 1;
					// }
					// new id2;
					// id2 = strval(tmp);

					// Businesses[id][BizType] = id2;
					// format(form, sizeof form, "Ustawiles typ biz ID: %d's type to %d.", id,id2);
					// SendClientMessage(playerid, COLOR_ADMINCMD,form);
					// SaveBizData(id, "BizType");

					// log
					// format(form, sizeof(form), "[GOVERNMENT:] Business id: %d, type set up to: %d  by %s", id, id2, gPlayerData[playerid][pName]);
					// GovermentLog(form);
			// }
			// else
			// {
				// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "nie jesteœ urzednikiem.");
			// }
			// return 1;
		}
		else if(strcmp(cmd, "/ustawbiz", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] != 5)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ta komenda zosta³a zablokowana !");
				return 1;
			}
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
					
					format(string, sizeof(string), "Cena: %d$",Businesses[id][BizPrice]);
					Business3DTextLabelC[id] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE2, Businesses[id][EnterX], Businesses[id][EnterY], Businesses[id][EnterZ], 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
				}
				else
				{
					format(string, sizeof(string), "Nazwa biznesu: %s, Typ biznesu: %s",Businesses[id][BusinessName],businesstype);
					Business3DTextLabelA[id] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE2, Businesses[id][EnterX], Businesses[id][EnterY], Businesses[id][EnterZ]+1.0, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

					format(string, sizeof(string), "Numer Budynku: %d, W³aœciciel: %s", id,GetRealName(Businesses[id][Owner]));
					Business3DTextLabelB[id] = CreateDynamic3DTextLabel(string, COLOR_LIGHTBLUE2, Businesses[id][EnterX], Businesses[id][EnterY], Businesses[id][EnterZ]+0.5, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

					format(string, sizeof(string), "Wejœciówka: %d$",Businesses[id][EntranceCost]);
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
				GovermentLog(form);
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ urzednikiem");
			}
			return 1;
		}
		else if(strcmp(cmd, "/abizexit", true) == 0)
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
		else if(strcmp(cmd, "/agotohouse", true) == 0)
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
		else if(strcmp(cmd, "/ahouseint", true) == 0)
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
			if(id2 < 1 || id2 > 52) { SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Interior ID's 1-50."); return 1; }
			
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
		else if(strcmp(cmd, "/abuildingint", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_WHITE, "[INFO:] /abuildingint [buildingid] [id (1-38)]");
				return 1;
			}
			new id;
			id = strval(tmp);
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_WHITE, "[INFO:] /abuildingint [buildingid] [id (1-38)]");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "1: Sherman Dam - 2: Planning Department - 3: Ganton Gym - 4: Cobra Gym - 5: Below The Belt Gym - 6: RC Battlefield");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "7-9: Police Departments - 10-12: Schools - 13: 8 Track Stadium - 14: Bloodbowl Stadium - 15: Dirtbike Stadium");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "6: Kickstart Stadium - 17: Vice Stadium - 19: Halo Taxi - 20: Szpital - 21: Biuro - 22: Bank - 23: Szko³a - 24: Straz Pozarna");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "25: Town Library - 26: Court Hall - 27: Realistic Office - 28: Strzelnica - 29: Bank - 30: Office - 31: Basen - 32: Szpital");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "33: Bank - 34-35: Small Office - 36: Big office - 37: Stadion narodowy - 38: NASCAR");
				return 1;
			}
			new id2;
			id2 = strval(tmp);
			if(id2 < 1 || id2 > 38) { SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Interior ID's 1-38."); return 1; }
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
			else if(id2 == 30)
			{
				Building[id][ExitX] = 1200.32;
				Building[id][ExitY] = -1465.77;
				Building[id][ExitZ] = -22.94;
				Building[id][ExitInterior] = 1;
				format(string, sizeof string, "Building ID: %d - Description: Office.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 31)
			{
				Building[id][ExitX] = 559.56;
				Building[id][ExitY] = -2095.57;
				Building[id][ExitZ] = 2.62;
				Building[id][ExitInterior] = 1;
				format(string, sizeof string, "Building ID: %d - Description: Office.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 32)
			{
				Building[id][ExitX] = 1144.46;
				Building[id][ExitY] = -2510.87;
				Building[id][ExitZ] = 113.82;
				Building[id][ExitInterior] = 1;
				format(string, sizeof string, "Building ID: %d - Description: Szpital.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 33)
			{
				Building[id][ExitX] = 1440.0;
				Building[id][ExitY] = -1008.0;
				Building[id][ExitZ] = 27.0;
				Building[id][ExitInterior] = 1;
				format(string, sizeof string, "Building ID: %d - Description: Bank.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 34)
			{
				Building[id][ExitX] = 1303.8715;
				Building[id][ExitY] = -994.8543;
				Building[id][ExitZ] = 6644.9927;
				Building[id][ExitInterior] = 1;
				format(string, sizeof string, "Building ID: %d - Description: Small Office.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 35)
			{
				Building[id][ExitX] = 243.79;
				Building[id][ExitY] = 314.04;
				Building[id][ExitZ] = 999.15;
				Building[id][ExitInterior] = 1;
				format(string, sizeof string, "Building ID: %d - Description: Small Office.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 36)
			{
				Building[id][ExitX] = 1303.26;
				Building[id][ExitY] = -995.82;
				Building[id][ExitZ] = 6645.73;
				Building[id][ExitInterior] = 1;
				format(string, sizeof string, "Building ID: %d - Description: Small Office.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 37)
			{
				Building[id][ExitX] = 270.77;
				Building[id][ExitY] = -241.31;
				Building[id][ExitZ] = 1010.08;
				Building[id][ExitInterior] = 1;
				format(string, sizeof string, "Building ID: %d - Description: Stadio narodowy.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			else if(id2 == 38)
			{
				Building[id][ExitX] = 1942.54;
				Building[id][ExitY] = -6591.49;
				Building[id][ExitZ] = 21.24;
				Building[id][ExitInterior] = 1;
				format(string, sizeof string, "Building ID: %d - Description: Stadio narodowy.", id);
				SendClientMessage(playerid, COLOR_ADMINCMD,string);
			}
			SaveBData(id, "ExitX");
			SaveBData(id, "ExitY");
			SaveBData(id, "ExitZ");
			SaveBData(id, "ExitInterior");
			return 1;
		}
		else if(strcmp(cmd, "/wnetrzebudynku", true) == 0)
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
			if(gPlayerData[playerid][pFaction] == 9)
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
					if(id2 < 1 || id2 > 30) { SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Wnetrze ID's 1-25."); return 1; }

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
		else if(strcmp(cmd, "/abizint", true) == 0)
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
				SendClientMessage(playerid, COLOR_WHITE, "[INFO:] /abizint [bizid] [id (1-41)]");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INTS:] [1:] Marcos Bistro (Eat) - [2:] Big Spread Ranch (Bar) - [3:] Burger Shot (Eat) - [4:] Cluckin Bell (Eat)");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INTS:] [5:] Well Stacked Pizza (Eat) - [6:] Rusty Browns Dohnuts (Eat) - [7:] Jays Diner (Eat) - [8:] Pump Truck Stop Diner (Eat)");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INTS:] [9:] Alhambra (Drink) - [10:] Mistys (Drink) - [11:] Lil' Probe Inn (Drink) - [12:] Exclusive (Clothes) - [13:] Binco (Clothes)");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INTS:] [14:] ProLaps (Clothes) - [15:] SubUrban (Clothes) - [16:] Victim (Clothes) - [17:] Zip (Clothes) - [18:] Redsands Casino");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INTS:] [19:] Off Track Betting - [20:] Sex Shop - [21:] Zero's RC Shop - [22-26:] Ammunations");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INTS:] [27:] Jizzys (Drink) - [27-33:] 24-7's (Buy) - [35:] Kibelek - [36:] Wiejskie Disco (Drink) - [37:] Disco (Drink) - [38:] Shop Elex ");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INTS:] [39:] Restauracja (Eat/Drink) - [40:] Restauracja (Eat/Drink) - [41:] Computer Shop (Buy)");

				/*SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "1 - 5 kk  ; 2 - 3 kk  ; 3 - 2 kk  ; 4 - 1,5 kk  ; 5 - 1,8 kk  ; 6 - 1,5 kk  ; 7 - 2 kk  ; 8 - 0 k  ; 9 - 4 kk  ; 10 - 1,4 kk ;");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "11 - 1,3 kk ; 12 - 2 kk ; 13 - 1,8 kk ; 14 - 2,2 kk ; 15 - 1,8 kk ; 16 - 2,2 kk ; 17 - 1,9 kk ; 18 - 5 kk ; 19 - 5 kk ; 20 - 1 kk ;");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "21 - 1,2 kk ; 22 - 1,2 kk ; 23 - 1,8 kk ; 24 - 6,5 kk ; 25 - 6,5 kk ; 26 - 6,3 kk ; 27 - 10 kk ; 28 - 4 kk ; 29 - 5 kk ; 30 - 4,5 kk ;");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "31 - 4,5 kk ; 32 - 4 kk ; 33 - 3 kk ; 34 - 1 k ; 35 - 3 kk ;");
				*/
				return 1;
			}
			new id2;
			id2 = strval(tmp);
			if(id2 < 1 || id2 > 41) { SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Interior ID's 1-41."); return 1; }
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
				Businesses[id][ExitX] = 2247.9302;
				Businesses[id][ExitY] = 1595.4698;
				Businesses[id][ExitZ] = 1018.8124;
				Businesses[id][ExitInterior] = 10;
				Businesses[id][ExitAngle] = 0.0;
				format(string, sizeof string, "Business ID: %d - Description: Sklep komputerowy", id);
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
		else if(strcmp(cmd, "/abizname", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 1)
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
			if(strfind(result , "|" , true) == -1)
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
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Invalid Symbol, | is not allowed!");
			}
			return 1;
		}
		else if(strcmp(cmd, "/abizsell", true) == 0)
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

			SaveBizData(id, "Locked");
			SaveBizData(id, "Owned");
			SaveBizData(id, "Owner");
			new form[128];
			format(form, sizeof(form), "[INFO:] You have sold business ID: %d.", id);
			SendClientMessage(playerid, COLOR_ADMINCMD, form);
			return 1;
		}
		else if(strcmp(cmd, "/sprzedajbiz", true) == 0)
		{
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /sprzedajbiz [id biznesu]");
				return 1;
			}
			new id = strval(tmp);
			if(gPlayerData[playerid][pFaction] == 9)
			{
				format(string, sizeof(string), "[GOVERNMENT:] Business sold by: %s, biz id: %d, price: %d$, owner: %s", gPlayerData[playerid][pName], id, Businesses[id][BizPrice], Businesses[id][Owner]);
				GovermentLog(string);
				
				ResetBizData(id, 1);
				
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
		else if(strcmp(cmd, "/ahouseprice", true) == 0)
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
				format(string, sizeof(string), "Opis: %s, Cena: %d$",Houses[id][Description],Houses[id][HousePrice]);
				UpdateDynamic3DTextLabelText(Houses3DTextLabelC[id], COLOR_LIGHTYELLOW2, string);
			}
			new form[128];
			format(form, sizeof form, "[INFO:] You've set House ID: %d's price to %d.", id,id2);
			SendClientMessage(playerid, COLOR_ADMINCMD,form);
			SaveHouseData(id, "HousePrice");
			return 1;
		}
		else if(strcmp(cmd, "/ahousesell", true) == 0)
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

			format(string, sizeof(string), "Opis: %s, Cena: %d$",Houses[id][Description],Houses[id][HousePrice]);
			UpdateDynamic3DTextLabelText(Houses3DTextLabelC[id], COLOR_LIGHTYELLOW2, string);

			new form[128];
			format(form, sizeof(form), "[INFO:] You have sold house ID: %d.", id);
			SendClientMessage(playerid, COLOR_ADMINCMD, form);
			return 1;
		}
		else if(strcmp(cmd, "/ustawduzygaraz", true) == 0)
		{
			if(gPlayerData[playerid][pVipGarageBig] <= 0)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie wykupi³eœ du¿ego gara¿u, nie mo¿esz go postawiæ");
				return 1;
			}
			new Float:x, Float:y, Float:z, Float:angle;
			new isclosetohouse, form[256];
			new Hour, Minute, Second;
			new Year, Month, Day;
			new name[MAX_PLAYER_NAME], houselocation[MAX_ZONE_NAME];
			GetPlayerPos(playerid, x, y, z);
			GetPlayerFacingAngle(playerid, angle);
			for(new i = 0; i < sizeof(Houses); i++)
			{
				if(!PlayerToPoint(20.0, playerid, Houses[i][EnterX], Houses[i][EnterY], Houses[i][EnterZ]))
					continue;
				if(strcmp(Houses[i][Owner], name, false, MAX_PLAYER_NAME) != 0 || Houses[i][HouseType] != 0)
					continue;
				isclosetohouse = 1;
				break;
			}
			if(isclosetohouse == 0)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Gara¿ musi znajdowaæ siê w pobli¿u twojego domu !");
				return 1;
			}
			for(new i = 0; i < sizeof(Houses); i++)
			{
				if(Houses[i][Owned] == 1)
					continue;
				if(InsertPlayerItemEx(playerid, 4, i, 0, 0, 0, 0, "Puste", 1) == 0)
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie masz miejsca na klucze do gara¿u !");
					return 1;
				}
				GetPlayerName(playerid, name, sizeof(name));
				GetCoords2DZone(Houses[i][EnterX],Houses[i][EnterY], houselocation, MAX_ZONE_NAME);
				
				strdel(Houses[i][Owner], 0, MAX_PLAYER_NAME);
				strins(Houses[i][Owner], name, 0, MAX_PLAYER_NAME);
				strdel(Houses[i][Description], 0, 128);
				strins(Houses[i][Description], "Duzy garaz", 0, 128);
				Houses[i][EnterX] = x;
				Houses[i][EnterY] = y;
				Houses[i][EnterZ] = z;
				Houses[i][EnterWorld] = GetPlayerVirtualWorld(playerid);
				Houses[i][EnterInterior] = GetPlayerInterior(playerid);
				Houses[i][HouseType] = HOUSET_GARAGE_BIG;				
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
				SavePlayerData(playerid, "VipGarageBig");
			
				DestroyDynamicPickup(Houses[i][PickupID]);
				Houses[i][PickupID] = CreateDynamicPickup(1239, 1, Houses[i][EnterX], Houses[i][EnterY], Houses[i][EnterZ]);

				DestroyDynamic3DTextLabel(Houses3DTextLabelA[i]);
				DestroyDynamic3DTextLabel(Houses3DTextLabelB[i]);
				DestroyDynamic3DTextLabel(Houses3DTextLabelC[i]);

				format(string, sizeof(string), "Adres: %d %s", i, houselocation);
				Houses3DTextLabelA[i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTYELLOW2, Houses[i][EnterX], Houses[i][EnterY], Houses[i][EnterZ]+1.0, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

				// format(string, sizeof(string), "Wlasciciel: %s",Houses[i][Owner]);
				format(string, sizeof(string), " ",Houses[i][Owner]);
				Houses3DTextLabelB[i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTYELLOW2, Houses[i][EnterX], Houses[i][EnterY], Houses[i][EnterZ]+0.5, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

				format(string, sizeof(string), "Opis: %s",Houses[i][Description]);
				Houses3DTextLabelC[i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTYELLOW2, Houses[i][EnterX], Houses[i][EnterY], Houses[i][EnterZ], 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

				format(form, sizeof(form), "[INFO:] Ustawiles du¿y gara¿ ID: %d w dzielnicy .", i);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, form);

				// log
				getdate(Year, Month, Day);				
				gettime(Hour, Minute, Second);

				format(form, sizeof(form), "[GOVERNMENT:] Garage(house) id: %d, set up X: %f, Y: %f, Z: %f by %s", i, x, y, z,gPlayerData[playerid][pName]);
				GovermentLog(form);
				return 1;
			}
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Brak wolnych gara¿y ! Powiadom administratora !");
			return 1;
		}
		else if(strcmp(cmd, "/ustawgaraz", true) == 0)
		{
			if(gPlayerData[playerid][pVipGarage] <= 0)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie wykupi³eœ gara¿u, nie mo¿esz go postawiæ");
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
			for(new i = 0; i < sizeof(Houses); i++)
			{
				if(!PlayerToPoint(20.0, playerid, Houses[i][EnterX], Houses[i][EnterY], Houses[i][EnterZ]))
					continue;
				if(strcmp(Houses[i][Owner], name, false, MAX_PLAYER_NAME) != 0 || Houses[i][HouseType] != 0)
					continue;
				isclosetohouse = 1;
				break;
			}				
			if(isclosetohouse == 0)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Gara¿ musi znajdowaæ siê w pobli¿u twojego domu !");
				return 1;
			}
			for(new i = 0; i < sizeof(Houses); i++)
			{
				if(Houses[i][Owned] == 1)
					continue;
				if(InsertPlayerItemEx(playerid, 4, i, 0, 0, 0, 0, "Puste", 1) == 0)
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie masz miejsca na klucze do gara¿u !");
					return 1;
				}
				GetCoords2DZone(Houses[i][EnterX],Houses[i][EnterY], houselocation, MAX_ZONE_NAME);
				
				strdel(Houses[i][Owner], 0, MAX_PLAYER_NAME);
				strins(Houses[i][Owner], name, 0, MAX_PLAYER_NAME);
				strdel(Houses[i][Description], 0, 128);
				strins(Houses[i][Description], "Garaz", 0, 128);
				Houses[i][EnterX] = x;
				Houses[i][EnterY] = y;
				Houses[i][EnterZ] = z;
				Houses[i][EnterWorld] = GetPlayerVirtualWorld(playerid);
				Houses[i][EnterInterior] = GetPlayerInterior(playerid);
				Houses[i][HouseType] = HOUSET_GARAGE;				
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
				SavePlayerData(playerid, "VipGarage");
			
				DestroyDynamicPickup(Houses[i][PickupID]);
				Houses[i][PickupID] = CreateDynamicPickup(1239, 1, Houses[i][EnterX], Houses[i][EnterY], Houses[i][EnterZ]);

				DestroyDynamic3DTextLabel(Houses3DTextLabelA[i]);
				DestroyDynamic3DTextLabel(Houses3DTextLabelB[i]);
				DestroyDynamic3DTextLabel(Houses3DTextLabelC[i]);

				format(string, sizeof(string), "Adres: %d %s",i, houselocation);
				Houses3DTextLabelA[i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTYELLOW2, Houses[i][EnterX], Houses[i][EnterY], Houses[i][EnterZ]+1.0, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

				// format(string, sizeof(string), "Wlasciciel: %s",Houses[i][Owner]);
				format(string, sizeof(string), " ",Houses[i][Owner]);
				Houses3DTextLabelB[i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTYELLOW2, Houses[i][EnterX], Houses[i][EnterY], Houses[i][EnterZ]+0.5, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

				format(string, sizeof(string), "Opis: %s",Houses[i][Description]);
				Houses3DTextLabelC[i] = CreateDynamic3DTextLabel(string, COLOR_LIGHTYELLOW2, Houses[i][EnterX], Houses[i][EnterY], Houses[i][EnterZ], 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
				
				format(form, sizeof(form), "[INFO:] Ustawiles gara¿ ID: %d w dzielnicy .", i);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, form);

				// log
				getdate(Year, Month, Day);
				gettime(Hour, Minute, Second);

				format(form, sizeof(form), "[GOVERNMENT:] Garage(house) id: %d, set up X: %f, Y: %f, Z: %f by %s", i, x, y, z,gPlayerData[playerid][pName]);
				GovermentLog(form);
				return 1;
			}
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Brak wolnych gara¿y ! Powiadom administratora !");
			return 1;
		}
		else if(strcmp(cmd, "/ustawdom", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] != 5)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ta komenda zosta³a zablokowana !");
				return 1;
			}
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /ustawdom [id domu]");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Raz ustawionego domu nie mo¿na przestawiæ !");
				return 1;
			}
			new id = strval(tmp);
			if(gPlayerData[playerid][pFaction] == FACTIONID_GOVERNMENT)
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
				Houses[id][HouseType] = HOUSET_HOUSE;
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

					format(string, sizeof(string), "Opis: %s, Cena: %d$",Houses[id][Description],Houses[id][HousePrice]);
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

						// format(string, sizeof(string), "Wlasciciel: %s",Houses[id][Owner]);
						format(string, sizeof(string), " ",Houses[id][Owner]);
						Houses3DTextLabelB[id] = CreateDynamic3DTextLabel(string, COLOR_LIGHTYELLOW2, Houses[id][EnterX], Houses[id][EnterY], Houses[id][EnterZ]+0.5, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

						format(string, sizeof(string), "Opis: %s Czynsz: %d$ (/wynajmijdom)",Houses[id][Description],Houses[id][RentCost]);
						Houses3DTextLabelC[id] = CreateDynamic3DTextLabel(string, COLOR_LIGHTYELLOW2, Houses[id][EnterX], Houses[id][EnterY], Houses[id][EnterZ], 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
					}
					else
					{
						new houselocation[MAX_ZONE_NAME];
						GetCoords2DZone(Houses[id][EnterX],Houses[id][EnterY], houselocation, MAX_ZONE_NAME);

						format(string, sizeof(string), "Adres: %d %s",id,houselocation);
						Houses3DTextLabelA[id] = CreateDynamic3DTextLabel(string, COLOR_LIGHTYELLOW2, Houses[id][EnterX], Houses[id][EnterY], Houses[id][EnterZ]+1.0, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

						// format(string, sizeof(string), "Wlasciciel: %s",Houses[id][Owner]);
						format(string, sizeof(string), " ",Houses[id][Owner]);
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
				GovermentLog(form);
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "nie jesteœ urzednikiem..");
			}
			return 1;
		}
		else if(strcmp(cmd, "/wynajmijkomornika", true) == 0)
		{
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /wynajmijkomornika [IdDomu]");
				return 1;
			}
			new id = strval(tmp);
			if(gPlayerData[playerid][pFaction] == 9)
			{
				new Year, Month, Day;
				getdate(Year, Month, Day);
				new Hour, Minute, Second;
				gettime(Hour, Minute, Second);
				format(string, sizeof(string), "[GOVERNMENT:] Hose sold by broker: %s, ID domu: %d, cena: %d$, wlasciciel: %s", gPlayerData[playerid][pName], id, Houses[id][HousePrice], Houses[id][Owner]);
				GovermentLog(string);
				
				Houses[id][Locked] = 1;
				Houses[id][Owned] = 0;
				Houses[id][Money] = 0;
				if(Houses[id][HRadio1Bought])
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

				format(string, sizeof(string), "Opis: %s, Cena: %d$",Houses[id][Description],Houses[id][HousePrice]);
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
		else if(strcmp(cmd, "/cenadomu", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] != 5)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ta komenda zosta³a zablokowana !");
				return 1;
			}
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /cenadomu [id domu] [cena]");
				return 1;
			}
			if(gPlayerData[playerid][pFaction] == 9)
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
					format(string, sizeof(string), "Opis: %s, Cena: %d$",Houses[id][Description],Houses[id][HousePrice]);
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
				GovermentLog(string);
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "nie jesteœ urzednikiem.");
			}
			return 1;
		}
		else if(strcmp(cmd, "/ahouseentrance", true) == 0)
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

				format(string, sizeof(string), "Opis: %s, Cena: %d$",Houses[id][Description],Houses[id][HousePrice]);
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
					format(string, sizeof(string), " ",Houses[id][Owner]);
					Houses3DTextLabelB[id] = CreateDynamic3DTextLabel(string, COLOR_LIGHTYELLOW2, Houses[id][EnterX], Houses[id][EnterY], Houses[id][EnterZ]+0.5, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

					format(string, sizeof(string), "Opis: %s Czynsz: %d$ (/wynajmijdom)",Houses[id][Description],Houses[id][RentCost]);
					Houses3DTextLabelC[id] = CreateDynamic3DTextLabel(string, COLOR_LIGHTYELLOW2, Houses[id][EnterX], Houses[id][EnterY], Houses[id][EnterZ], 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);
				}
				else
				{
					new houselocation[MAX_ZONE_NAME];
					GetCoords2DZone(Houses[id][EnterX],Houses[id][EnterY], houselocation, MAX_ZONE_NAME);

					format(string, sizeof(string), "Adres: %d %s",id,houselocation);
					Houses3DTextLabelA[id] = CreateDynamic3DTextLabel(string, COLOR_LIGHTYELLOW2, Houses[id][EnterX], Houses[id][EnterY], Houses[id][EnterZ]+1.0, 25.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);

					format(string, sizeof(string), " ",Houses[id][Owner]);
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
		else if(strcmp(cmd, "/ahouseexit", true) == 0)
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
		else if(strcmp(cmd, "/ahousedescription", true) == 0)
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
			if(strfind(result , "|" , true) == -1)
			{
				strmid(Houses[id][Description], (result), 0, strlen((result)), 128);

				if(Houses[id][Owned] == 0)
				{
					format(string, sizeof(string), "Opis: %s, Cena: %d$",Houses[id][Description],Houses[id][HousePrice]);
					UpdateDynamic3DTextLabelText(Houses3DTextLabelC[id], COLOR_LIGHTYELLOW2, string);
				}
				else
				{
					if(Houses[id][Rentable] == 1)
					{
						format(string, sizeof(string), "Opis: %s Czynsz: %d$ (/wynajmijdom)",Houses[id][Description],Houses[id][RentCost]);
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
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Invalid symbol, | is not allowed!");
			}
			return 1;
		}
		else if(strcmp(cmd, "/abuildingentrance", true) == 0)
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
		else if(strcmp(cmd, "/wejsciebudynku", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] != 5)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ta komenda zosta³a zablokowana !");
				return 1;
			}
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /wejsciebudynku [id budynku]");
				return 1;
			}
			new id = strval(tmp);
			if(gPlayerData[playerid][pFaction] == 9)
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
				GovermentLog(form);	
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ urzednikiem.");
			}
			return 1;
		}
		else if(strcmp(cmd, "/ksiazkatel", true) == 0)
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
							ShowPlayerDialog(playerid,10,DIALOG_STYLE_LIST, "Nr telefonów", string, "Po³¹cz", "Anuluj");
							PlayerActionMessage(playerid, 15.0, "przegl¹da ksi¹¿ke telefoniczn¹");
						}
						else
						{
							SendClientMessage(playerid, COLOR_LIGHTGREEN, "[INFO:] Ten gracz nie jest zalogowany");
							return 1;
						}
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Niew³aœciwe ID/nazwa gracza.");
					return 1;
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie posiadasz ksia¿ki telefonicznej ! Mo¿esz j¹ kupiæ w sklepie 24/7.");
			}
			return 1;
		}
		else if(strcmp(cmd, "/agotobuilding", true) == 0)
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
		else if(strcmp(cmd, "/abuildinglock", true) == 0)
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
		else if(strcmp(cmd, "/abuildingexit", true) == 0)
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
		else if(strcmp(cmd, "/abuildingname", true) == 0)
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
			if(strfind(result , "|" , true) == -1)
			{
				strmid(Building[id][BuildingName], (result), 0, strlen((result)), 128);
				format(string, sizeof(string), "[INFO:] You have set Building ID: %d's name to %s", id,(result));
				SendClientMessage(playerid, COLOR_ADMINCMD, string);
				SaveBData(id, "BuildingName");
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Invalid symbol, | is not allowed!");
			}
			return 1;
		}
		else if(strcmp(cmd, "/nazwabudynku", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] != 5)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ta komenda zosta³a zablokowana !");
				return 1;
			}
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /nazwabudynku [buildingid] [name]");
				return 1;
			}
			new id = strval(tmp);
			if(gPlayerData[playerid][pFaction] == 9)
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
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] nie jesteœ urzednikiem.");
			}
			return 1;
		}
		else if(strcmp(cmd, "/abuildingfee", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] != 5)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ta komenda zosta³a zablokowana !");
				return 1;
			}
			if(gPlayerData[playerid][pAdmin] < 4)
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
		else if(strcmp(cmd, "/agotobank", true) == 0)
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
		else if(strcmp(cmd, "/agotoflyingtestpos", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			SetPlayerToPos(playerid,gPlaneTestPosition[mPosX],gPlaneTestPosition[mPosY],gPlaneTestPosition[mPosZ]);
			SetPlayerInterior(playerid,gPlaneTestPosition[mPosInt]);
			SetPlayerVirtualWorld(playerid,gPlaneTestPosition[mPosW]);
			SetPlayerFacingAngle(playerid,gPlaneTestPosition[mPosA]);
			SendClientMessage(playerid, COLOR_ADMINCMD, "[INFO:] You teleported to the flying test position.");
			return 1;
		}
		else if(strcmp(cmd, "/abankpos", true) == 0)
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
		else if(strcmp(cmd, "/abankpos2", true) == 0)
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
		else if(strcmp(cmd, "/adetectivejobpos", true) == 0)
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
		else if(strcmp(cmd, "/alawyerjobpos", true) == 0)
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
		else if(strcmp(cmd, "/askillpospis", true) == 0)
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
		else if(strcmp(cmd, "/askillpossil", true) == 0)
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
		else if(strcmp(cmd, "/askillposDes", true) == 0)
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
		else if(strcmp(cmd, "/askillposSho", true) == 0)
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
		else if(strcmp(cmd, "/askillposSha", true) == 0)
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
		else if(strcmp(cmd, "/askillposSpa", true) == 0)
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
		else if(strcmp(cmd, "/askillposMic", true) == 0)
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
		else if(strcmp(cmd, "/askillposMp5", true) == 0)
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
		else if(strcmp(cmd, "/askillposAk", true) == 0)
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
		else if(strcmp(cmd, "/askillposM4", true) == 0)
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
		else if(strcmp(cmd, "/askillposSni", true) == 0)
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
		else if(strcmp(cmd, "/askillposAng", true) == 0)
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
		else if(strcmp(cmd, "/askillposWf", true) == 0)
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
		else if(strcmp(cmd, "/askillposMat", true) == 0)
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
		else if(strcmp(cmd, "/askillposPol", true) == 0)
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
		else if(strcmp(cmd, "/askillposHis", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			new Float:x,Float:y,Float:z;
			GetPlayerPos(playerid, x, y, z);
			SkillPosition[XHis] = x;
			SkillPosition[YHis] = y;
			SkillPosition[ZHis] = z;
			SkillPosition[PickupIDHis] = ChangePickupModel(SkillPosition[PickupIDHis],1239,SkillPosition[XHis],SkillPosition[YHis],SkillPosition[ZHis]);
			SaveSkillPositione();
			SendClientMessage(playerid, COLOR_ADMINCMD, "You have successfully set the Skill Position His.");
			return 1;
		}
		else if(strcmp(cmd, "/askillposBio", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			new Float:x,Float:y,Float:z;
			GetPlayerPos(playerid, x, y, z);
			SkillPosition[XBio] = x;
			SkillPosition[YBio] = y;
			SkillPosition[ZBio] = z;
			SkillPosition[PickupIDBio] = ChangePickupModel(SkillPosition[PickupIDBio],1239,SkillPosition[XBio],SkillPosition[YBio],SkillPosition[ZBio]);
			SaveSkillPositione();
			SendClientMessage(playerid, COLOR_ADMINCMD, "You have successfully set the Skill Position Bio.");
			return 1;
		}
		else if(strcmp(cmd, "/askillposFiz", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			new Float:x,Float:y,Float:z;
			GetPlayerPos(playerid, x, y, z);
			SkillPosition[XFiz] = x;
			SkillPosition[YFiz] = y;
			SkillPosition[ZFiz] = z;
			SkillPosition[PickupIDBio] = ChangePickupModel(SkillPosition[PickupIDFiz],1239,SkillPosition[XFiz],SkillPosition[YFiz],SkillPosition[ZFiz]);
			SaveSkillPositione();
			SendClientMessage(playerid, COLOR_ADMINCMD, "You have successfully set the Skill Position Fiz.");
			return 1;
		}
		else if(strcmp(cmd, "/adrugjobpos3", true) == 0)
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
		else if(strcmp(cmd, "/aRapistjobpos", true) == 0)
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
		else if(strcmp(cmd, "/aWhorejobpos", true) == 0)
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
		else if(strcmp(cmd, "/aDirjobpos", true) == 0)
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
		else if(strcmp(cmd, "/aStuntjobpos", true) == 0)
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
		else if(strcmp(cmd, "/aCarjackjobpos", true) == 0)
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
		else if(strcmp(cmd, "/aBodyjobpos", true) == 0)
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

		else if(strcmp(cmd, "/aBoxerjobpos", true) == 0)
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
		else if(strcmp(cmd, "/aproductjobpos", true) == 0)
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
		else if(strcmp(cmd, "/agunjobpos", true) == 0)
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
		else if(strcmp(cmd, "/agunjobpos2", true) == 0)
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
		else if(strcmp(cmd, "/agunjobpos3", true) == 0)
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
		else if(strcmp(cmd, "/abusjobpos", true) == 0)
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
		else if(strcmp(cmd, "/amzgkjobpos", true) == 0)
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
		else if(strcmp(cmd, "/asweeperjobpos", true) == 0)
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
		else if(strcmp(cmd, "/afarmerjobpos", true) == 0)
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
		else if(strcmp(cmd, "/ataxijobpos", true) == 0)
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
		else if(strcmp(cmd, "/agotoweaponlicpos", true) == 0)
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
		else if(strcmp(cmd, "/aweaponlicensepos", true) == 0)
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
		else if(strcmp(cmd, "/aflyingtestpos", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			new Float:x,Float:y,Float:z;
			GetPlayerPos(playerid, x, y, z);
			new Float:angle;
			GetPlayerFacingAngle(playerid, angle);
			gPlaneTestPosition[mPosX] = x;
			gPlaneTestPosition[mPosY] = y;
			gPlaneTestPosition[mPosZ] = z;
			gPlaneTestPosition[mPosW] = GetPlayerVirtualWorld(playerid);
			gPlaneTestPosition[mPosInt] = GetPlayerInterior(playerid);
			gPlaneTestPosition[mPosA] = angle;
			gPlaneTestPosition[PickupID] = ChangePickupModel(gPlaneTestPosition[PickupID],1239,gPlaneTestPosition[mPosX],gPlaneTestPosition[mPosY],gPlaneTestPosition[mPosZ]);
			SavePlaneTestPosition();
			SendClientMessage(playerid, COLOR_ADMINCMD, "You have successfully set the Flying Test Position.");
			return 1;
		}
		else if(strcmp(cmd, "/aboattestpos", true) == 0)
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
		else if(strcmp(cmd, "/acivilianspawn", true) == 0)
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
		else if(strcmp(cmd, "/afactionspawn", true) == 0)
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
			DynamicFactions[id][m_fX] = x;
			DynamicFactions[id][m_fY] = y;
			DynamicFactions[id][m_fZ] = z;
			SaveFData(id, "X");
			SaveFData(id, "Y");
			SaveFData(id, "Z");
			format(string, sizeof(string), "[INFO:] You have set faction ID: %d's spawnpoint.", id);
			SendClientMessage(playerid, COLOR_ADMINCMD, string);
			return 1;
		}
		else if(strcmp(cmd, "/admin", true) == 0 || strcmp(cmd, "/a", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 1)
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
			
			format(string, sizeof(string), "[AC][%d][LVL: %d][%s]: %s", playerid, gPlayerData[playerid][pAdmin], gPlayerData[playerid][pOOCName], result);
			SendAdminMessage(COLOR_YELLOW, string);
			return 1;
		}
		else if(strcmp(cmd, "/supporter", true) == 0 || strcmp(cmd, "/su", true) == 0)
		{
			if(gPlayerData[playerid][pModerator] < 1)
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
				SendClientMessage(playerid, COLOR_GRAD2, "U¯YCIE: (/su)pporter [Supporter chat]");
				return 1;
			}

			if(gPlayerData[playerid][pAdmin] > 0)
				format(string, sizeof(string), "[MC][%d][Admin LVL: %d][%s]: %s", playerid, gPlayerData[playerid][pAdmin], gPlayerData[playerid][pOOCName], result);
			else if(gPlayerData[playerid][pModerator] == 1)
				format(string, sizeof(string), "[MC][%d][Mod][%s]: %s", playerid, gPlayerData[playerid][pOOCName], result);
			else if(gPlayerData[playerid][pModerator] == 2)
				format(string, sizeof(string), "[MC][%d][SMod][%s]: %s", playerid, gPlayerData[playerid][pOOCName], result);
			SendModMessage(COLOR_GREEN, string);
			printf("Supporter %s: %s", sendername, result);
			return 1;
		}
		else if(strcmp(cmd, "/listenchat", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 1)
				return 0;
			if(!BigEar[playerid])
			{
				BigEar[playerid] = 1;
			}
			else if(BigEar[playerid])
			{
				BigEar[playerid] = 0;
			}
			return 1;
		}
		else if(strcmp(cmd, "/afactioncolor", true) == 0)
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
			if(strfind(result , "|" , true) == -1)
			{
				strmid(DynamicFactions[id][fColor], (result), 0, strlen((result)), 128);
				format(string, sizeof(string), "[INFO:] You have set faction ID: %d's colour to %s.", id,(result));
				foreach(Player, i)
				{
					if(!gPlayerLogged[i])
						continue;
					if(gPlayerData[i][pFaction] < sizeof(DynamicFactions))
					{
						if(DynamicFactions[ gPlayerData[i][pFaction] ][fType] == 3)
						{
							for(new n = 0; n < sizeof(DynamicZones); n++)
								GangZoneShowForPlayer(i, n, HexToInt(DynamicFactions[ DynamicZones[n][mFaction] ][fColor]));
						}
					}
				}
				SendClientMessage(playerid, COLOR_ADMINCMD, string);
				SaveFData(id, "Color");
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Invalid Symbol, | is not allowed!");
			}
			return 1;
		}
		else if(strcmp(cmd, "/afactionname", true) == 0)
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
			if(strfind(result , "|" , true) == -1)
			{
				strmid(DynamicFactions[id][Name], (result), 0, strlen((result)), 128);
				format(string, sizeof(string), "[INFO:] You have set faction ID: %d's name to %s", id,(result));
				SendClientMessage(playerid, COLOR_ADMINCMD, string);
				SaveFData(id, "Name");
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Invalid Symbol, | is not allowed!");
			}
			return 1;
		}
		else if(strcmp(cmd, "/agotofaction", true) == 0)
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
			SetPlayerToPos(playerid,DynamicFactions[id][m_fX],DynamicFactions[id][m_fY],DynamicFactions[id][m_fZ]);
			SetPlayerInterior(playerid,0);
			SetPlayerVirtualWorld(playerid,0);
			new form[128];
			format(form, sizeof(form), "[INFO:] You teleported to faction ID: %d.", id);
			SendClientMessage(playerid, COLOR_ADMINCMD, form);
			return 1;
		}
		else if(strcmp(cmd, "/afactiontype", true) == 0)
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
		else if(strcmp(cmd, "/afactionjoinrank", true) == 0)
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
		else if(strcmp(cmd, "/afactionbank", true) == 0)
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
		else if(strcmp(cmd, "/afactiondrugs", true) == 0)
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
		else if(strcmp(cmd, "/afactionmats", true) == 0)
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
		else if(strcmp(cmd, "/afactionrankamount", true) == 0)
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
		else if(strcmp(cmd, "/afactionrankname", true) == 0)
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
			if(strfind(result , "|" , true) == -1)
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
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Invalid symbol, | is not allowed!");
			}
			return 1;
		}
		else if(strcmp(cmd, "/afactionskin", true) == 0)
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
		else if(strcmp(cmd, "/afactionusecolor", true) == 0)
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
		else if(strcmp(cmd, "/afactionuseskins", true) == 0)
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
				
				foreach(Player, i)
				{
					if(!gPlayerLogged[i])
						continue;
					if(gPlayerData[i][pFaction] == id)
					{
						SetPlayerToFactionSkin(i);
					}
				}
			}
			return 1;
		}
		else if(strcmp(cmd, "/banaccount", true) == 0)
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
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Invalid ID.");
			}
			return 1;
		}
		else if(strcmp(cmd, "/mbanaccount", true) == 0)
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
						SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie jesteœ upowa¿niony do u¿ywania tej komendy na adminie !");
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
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Invalid ID.");
			}
			return 1;
		}
		else if(strcmp(cmd, "/ban", true) == 0)
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
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Invalid ID.");
			}
			return 1;
		}
		else if(strcmp(cmd, "/afactionkick", true) == 0)
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
					format(form,sizeof(form), "%s zosta³ wyrzucony z frakcji %s, Powód: %s ",GetPlayerNameEx(giveplayerid),GetPlayerNameEx(playerid),(result));
					ABroadCast(COLOR_YELLOW,string,1);
					gPlayerData[giveplayerid][pFaction] = 255;

					SavePlayerData(giveplayerid, "Faction");
					return 1;
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Invalid ID.");
			}
			return 1;
		}
		else if(strcmp(cmd, "/sluzba", true) == 0)
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
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ na miejscu zg³oszania na s³u¿be !");
					return 1;
				}
			}
			else
			{
				new tmpstring[256];
				format(tmpstring, sizeof(tmpstring), "Frakcja: %d, Typ: %d",gPlayerData[playerid][pFaction], DynamicFactions[gPlayerData[playerid][pFaction]][fType]);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Niew³aœciwa frakcja/typ.");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, tmpstring);
				return 1;
			}
			return 1;
		}
		else if(strcmp(cmd, "/wanted", true) == 0)
		{
			if(gPlayerData[playerid][pFaction] == 255)
			{
				SendClientMessage(playerid, COLOR_RED, "[INFO:] Niew³aœciwa frakcja !");
				return 1;
			}
			if(DynamicFactions[gPlayerData[playerid][pFaction]][fType] != 1)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Niew³aœciwa frakcja !");
				return 1;
			}
			if(!gPlayerData[playerid][pDuty] && gPlayerData[playerid][pAdmin] == 0)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ na s³u¿bie !");
				return 1;
			}
			new vehid = GetPlayerVehicleID(playerid);
			if(vehid == INVALID_VEHICLE_ID && !AdminDuty[playerid])
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w radiowozie !");
				return 1;
			}
			new count = 0;
			SendClientMessage(playerid, COLOR_LIGHTGREEN, "-----------[Poszukiwani]-----------");
			foreach(Player, i)
			{
				if(!gPlayerLogged[i])
					continue;
				if(WantedLevel[i] >= 1)
				{
					format(string, sizeof(string), "[WANTED:] %s (ID:%d) -  Priorytet poszukiwania: %d.",GetPlayerNameEx(i),i,WantedLevel[i]);
					SendClientMessage(playerid,COLOR_WHITE,string);
					count++;
				}
			}
			if(count == 0)
			{
				SendClientMessage(playerid,COLOR_WHITE, "[INFO:] Aktualnie brak zg³oszeñ.");
			}
			SendClientMessage(playerid, COLOR_LIGHTGREEN, "------------------------------------------------");
			return 1;
		}
		else if(strcmp(cmd, "/skuj", true) == 0)
		{
			if(IsPlayerInAnyVehicle(playerid))
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz skuæ kogoœ bêd¹c w pojeŸdzie !");
				return 1;
			}
			if(gPlayerData[playerid][pFaction] == 255)
			{
				SendClientMessage(playerid, COLOR_RED, "[INFO:] Niew³aœciwa frakcja !");
				return 1;
			}
			if(DynamicFactions[gPlayerData[playerid][pFaction]][fType] != 1)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Niew³aœciwa frakcja");
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
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ na s³u¿bie");
				return 1;
			}
			giveplayerid = ReturnUser(tmp);
			if(!IsPlayerConnected(giveplayerid))
			{
				SendClientMessage(playerid, COLOR_RED, "[INFO:] Dany gracz nie jest online !");
				return 1;
			}
			if(PlayerCuffed[giveplayerid] == 1)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ta osoba jest ju¿ w kajdankach");
				return 1;
			}
			if(ProxDetectorS(1.5, playerid, giveplayerid))
			{
				if(giveplayerid == playerid) { SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz sam siebie ubezw³asnowolniæ !"); return 1; }
				PlayerActionMessage(playerid,15.0, "wyjmuje kajdanki i skuwa podejrzanego");
				format(string, sizeof(string), "[INFO:] Zosta³eœ ubezw³asnowolniony przez %s.", GetPlayerNameEx(playerid));
				SendClientMessage(giveplayerid, COLOR_RED, string);
				format(string, sizeof(string), "[INFO:] %s zosta³ ubezw³asnowolniony.", GetPlayerNameEx(giveplayerid));
				SendClientMessage(playerid, COLOR_WHITE, string);
				SetPlayerSpecialAction(giveplayerid, SPECIAL_ACTION_CUFFED);
				PlayerCuffed[giveplayerid] = 1;
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Gracz nie jest wystarczaj¹co blisko Ciebie !");
				return 1;
			}
			return 1;
		}
		else if(strcmp(cmd, "/rozkuj", true) == 0)
		{
			if(gPlayerData[playerid][pFaction] == 255)
			{
				SendClientMessage(playerid, COLOR_RED, "[INFO:] Niew³aœciwa frakcja !");
				return 1;
			}
			if(DynamicFactions[gPlayerData[playerid][pFaction]][fType] != 1)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Niew³aœciwa frakcja.");
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
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] nie jesteœ na s³u¿bie.");
				return 1;
			}
			giveplayerid = ReturnUser(tmp);
			if(!IsPlayerConnected(giveplayerid))
			{
				SendClientMessage(playerid, COLOR_RED, "[INFO:] Dany gracz nie jest online !");
				return 1;
			}
			if(PlayerCuffed[giveplayerid] == 0)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ta osoba nie jest skuta.");
				return 1;
			}
			if(ProxDetectorS(1.5, playerid, giveplayerid))
			{
				if(giveplayerid == playerid) { SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz sam siebie rozkuæ !"); return 1; }
				format(string, sizeof(string), "[INFO:] Rozkuty przez %s.", GetPlayerNameEx(playerid));
				SendClientMessage(giveplayerid, COLOR_RED, string);
				format(string, sizeof(string), "[INFO:] %s rozkuty.", GetPlayerNameEx(giveplayerid));
				SendClientMessage(playerid, COLOR_WHITE, string);
				SetPlayerSpecialAction(giveplayerid, SPECIAL_ACTION_NONE);
				PlayerCuffed[giveplayerid] = 0;
				return 1;
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Gracz nie jest wystarczaj¹co blisko Ciebie !");
				return 1;
			}
		}
		else if(strcmp(cmd, "/rewiduj",true)==0)
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
						if(ProxDetectorS(8.0, playerid, giveplayerid))
						{
							if(giveplayerid == playerid) { SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz sam siebie zrewidowaæ!"); return 1; }
							if(gPlayerData[playerid][pDuty] == 0) { SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ na s³u¿bie."); return 1; }
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
									format(string,255, "[FRISK:] Znalezione bronie: %s.",weaponName);
									SendClientMessage(playerid,COLOR_WHITE,string);
								}
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie wystarczaj¹co blisko !");
							return 1;
						}
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Niew³aœciwe ID.");
					return 1;
				}
			}
			return 1;
		}
		else if(strcmp(cmd, "/skonfiskuj", true) == 0)
		{
			if((gPlayerData[playerid][pFaction] != 255 && DynamicFactions[gPlayerData[playerid][pFaction]][fType] == 1) || AdminDuty[playerid])
			{
				new x_nr[256];
				x_nr = strtok(cmdtext, idx);
				if(!strlen(x_nr)) {
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /skonfiskuj [rzecz] [playerid]");
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[RZECZ:] prawko, licencjepilotasamolotu, licencjepilotahelikoptera, licencjenabron, narkotyki, materia³y, bron, licencjenalodz");
					return 1;
				}
				if(strcmp(x_nr, "prawko",true) == 0)
				{
					tmp = strtok(cmdtext, idx);
					if(!strlen(tmp)) {
						SendClientMessage(playerid, COLOR_WHITE, "[INFO:] /skonfiskuj prawko [playerid]");
						return 1;
					}
					giveplayerid = ReturnUser(tmp);
					if(!IsPlayerConnected(giveplayerid))
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Niew³aœciwe ID.");
						return 1;
					}
					if(GetDistanceBetweenPlayers(playerid, giveplayerid) > 5.0)
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten gracz nie jest w zasiêgu.");
						return 1;
					}
					new slot = PHaveItem(giveplayerid, 3, 6);
					if(slot <= 0)
					{
						SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ta osoba nie ma prawa jazdy !");
						return 1;
					}
					while(slot)
					{
						RemovePlayerItemExUsed(giveplayerid, slot);
						slot = PHaveItem(giveplayerid, 3, 6);
					}
					format(string, sizeof(string), "przekazuje dokument dla %s", GetPlayerNameEx(playerid));
					PlayerActionMessage(giveplayerid, 15.0, string);
					format(string, sizeof(string), "odbiera dokument od %s", GetPlayerNameEx(giveplayerid));						
					PlayerActionMessage(giveplayerid, 15.0, string);
					format(string, sizeof(string), "[INFO:] Prawo jazdy %s zosta³o skonfiskowane", GetPlayerNameEx(giveplayerid));
					SendClientMessage(playerid, COLOR_WHITE, string);
					format(string, sizeof(string), "[INFO:] %s skonfiskowa³ Twoje prawo jazdy", GetPlayerNameEx(playerid));
					SendClientMessage(giveplayerid, COLOR_RED, string);						
				}
				else if(strcmp(x_nr, "licencjepilotasamolotu",true) == 0)
				{
					tmp = strtok(cmdtext, idx);
					if(!strlen(tmp)) {
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /skonfiskuj licencjepilotasamolotu [playerid]");
						return 1;
					}
					giveplayerid = ReturnUser(tmp);
					if(IsPlayerConnected(giveplayerid))
					{
						if(giveplayerid != INVALID_PLAYER_ID)
						{
							if(ProxDetectorS(8.0, playerid, giveplayerid))
							{
								format(string, sizeof(string), "[INFO:] Licencja pilota %s zosta³a skonfiskowana.", GetPlayerNameEx(giveplayerid));
								SendClientMessage(playerid, COLOR_WHITE, string);
								format(string, sizeof(string), "[INFO:] %s skonfiskowa³ Twoj¹ licencje pilota.", GetPlayerNameEx(playerid));
								SendClientMessage(giveplayerid, COLOR_RED, string);
								gPlayerData[giveplayerid][pPlaneLic] = 0;

								SavePlayerData(playerid, "PlaneLic");
							}
							else
							{
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Gracz nie jest w zasiêgu.");
								return 1;
							}
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Niew³aœciwe ID.");
						return 1;
					}
				}
				else if(strcmp(x_nr, "licencjepilotahelikoptera", true) == 0)
				{
					tmp = strtok(cmdtext, idx);
					if(!strlen(tmp)) {
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /skonfiskuj licencjepilotahelikoptera [playerid]");
						return 1;
					}
					giveplayerid = ReturnUser(tmp);
					if(IsPlayerConnected(giveplayerid))
					{
						if(giveplayerid != INVALID_PLAYER_ID)
						{
							if(ProxDetectorS(8.0, playerid, giveplayerid))
							{
								format(string, sizeof(string), "[INFO:] Licencja pilota %s zosta³a skonfiskowana.", GetPlayerNameEx(giveplayerid));
								SendClientMessage(playerid, COLOR_WHITE, string);
								format(string, sizeof(string), "[INFO:] %s skonfiskowa³ Twoj¹ licencje pilota.", GetPlayerNameEx(playerid));
								SendClientMessage(giveplayerid, COLOR_RED, string);
								gPlayerData[giveplayerid][pHeliLic] = 0;

								SavePlayerData(playerid, "HeliLic");
							}
							else
							{
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Gracz nie jest w zasiêgu.");
								return 1;
							}
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Niew³aœciwe ID.");
						return 1;
					}
				}
				else if(strcmp(x_nr, "licencjenabron",true) == 0)
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
							if(ProxDetectorS(8.0, playerid, giveplayerid))
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
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten gracz nie jest w zasiêgu.");
								return 1;
							}
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Niew³aœciwe ID.");
						return 1;
					}
				}
				else if(strcmp(x_nr, "licencjenalodz",true) == 0)
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
							if(ProxDetectorS(8.0, playerid, giveplayerid))
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
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten gracz nie jest w zasiêgu.");
								return 1;
							}
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Niew³aœciwe ID.");
						return 1;
					}
				}
				else if(strcmp(x_nr, "narkotyki",true) == 0)
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
							if(ProxDetectorS(8.0, playerid, giveplayerid))
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
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten gracz nie jest w zasiêgu.");
								return 1;
							}
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Niew³aœciwe ID.");
						return 1;
					}
				}
				else if(strcmp(x_nr, "materialy",true) == 0)
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
							if(ProxDetectorS(8.0, playerid, giveplayerid))
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
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Gracz nie jest w zasiêgu.");
								return 1;
							}
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Niew³aœciwe ID.");
						return 1;
					}
				}
				else if(strcmp(x_nr, "bron",true) == 0)
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
							if(ProxDetectorS(8.0, playerid, giveplayerid))
							{
								format(string, sizeof(string), "[INFO:] Broñ %s zosta³a skonfiskowana.", GetPlayerNameEx(giveplayerid));
								SendClientMessage(playerid, COLOR_WHITE, string);
								format(string, sizeof(string), "[INFO:] %s skonfiskowa³ Twoj¹ broñ.", GetPlayerNameEx(playerid));
								SendClientMessage(giveplayerid, COLOR_RED, string);
								ResetPlayerWeapons(giveplayerid);
							}
							else
							{
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten gracz nie jest w zasiêgu.");
								return 1;
							}
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Niew³aœciwe ID.");
						return 1;
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Niew³aœciwa nazwa.");
					return 1;
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Niew³aœciwa frakcja.");
				return 1;
			}
			return 1;
		}
		else if(strcmp(cmd, "/gbron", true) == 0)
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
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Niew³aœciwa frakcja/typ.");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, tmpstring);
				return 1;
			}
			if((!PlayerToPoint(5.0, playerid, DynamicFactions[factionid][fXDuty], DynamicFactions[factionid][fYDuty], DynamicFactions[factionid][fZDuty]) || GetPlayerVirtualWorld(playerid) != DynamicFactions[factionid][fWorldDuty]) &&
				   (!PlayerToPoint(5.0, playerid, DynamicFactions[factionid][fXDuty2], DynamicFactions[factionid][fYDuty2], DynamicFactions[factionid][fZDuty2]) || GetPlayerVirtualWorld(playerid) != DynamicFactions[factionid][fWorldDuty2]))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ na miejscu pobrania broni !");
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
		else if(strcmp(cmd, "/mandat", true) == 0)
		{
			if(IsPlayerInAnyVehicle(playerid))
			{
				new Float:x, Float:y, Float:z;
				GetVehicleVelocity(GetPlayerVehicleID(playerid), x, y, z);
				if(x > 0 || y > 0 || z > 0)
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Przed wypisaniem mandatu zatrzymaj pojazd !");
					return 1;
				}
			}
			if(gPlayerData[playerid][pFaction] != 255 && DynamicFactions[gPlayerData[playerid][pFaction]][fType] == 1)
			{
				if(gPlayerData[playerid][pDuty] == 0)
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ na s³u¿bie !");
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
				if(moneys < 1 || moneys > 99999) { SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Niew³aœciwa wysokoœæ mandatu."); return 1; }
				if(IsPlayerConnected(giveplayerid))
				{
					if(giveplayerid != INVALID_PLAYER_ID)
					{
						if(ProxDetectorS(8.0, playerid, giveplayerid))
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
							
							new Year, Month, Day;
							getdate(Year, Month, Day);
							format(string, sizeof(string), "INSERT INTO `samp_wanted` (`PlayerName` , `Description` , `CommitedDay` , `CommitedMonth` , `CommitedYear`) VALUES ('%s' , 'Otrzyma³ mandat za: %s' , '%d' , '%d' , '%d')", gPlayerData[giveplayerid][pName], result, Day, Month, Year);
							mysql_query(string, SAVE, giveplayerid, db_con2);
							
							gPlayerData[playerid][pAchieveTickets]++;
							SavePlayerData(playerid, "AchieveTickets");
							
							format(string, sizeof(string), "[INFO:] Da³eœ mandat %s o wysokoœci %d$ - Powód: %s.", GetPlayerNameEx(giveplayerid), moneys, (result));
							SendClientMessage(playerid, COLOR_WHITE, string);
							format(string, sizeof(string), "[INFO:] %s da³ Tobie mandat w wysokoœci %d$ - Powód: %s.", GetPlayerNameEx(playerid), moneys, (result));
							SendClientMessage(giveplayerid, COLOR_RED, string);
							gPlayerData[giveplayerid][pTicket] += moneys;
							SavePlayerData(giveplayerid, "Ticket");

							return 1;
						}
						else
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ wystarczaj¹co blisko tej osoby !");
							return 1;
						}
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Niew³aœciwe ID");
					return 1;
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Invalid Faction");
			}
			return 1;
		}
		else if(strcmp(cmd, "/aresztuj", true) == 0 || strcmp(cmd, "/ar", true) == 0)
		{
			if(IsPlayerInAnyVehicle(playerid))
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz aresztowaæ bêd¹c w pojeŸdzie !");
				return 1;
			}
			if(gPlayerData[playerid][pFaction] == 255)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Niew³aœciwa frakcja.");
				return 1;
			}
			if(DynamicFactions[gPlayerData[playerid][pFaction]][fType] != 1)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Niew³aœciwa frakcja.");
				return 1;
			}
			if(!gPlayerData[playerid][pDuty])
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ na s³u¿bie !");
				return 1;
			}
			if(!PlayerToPoint(30.0, playerid, -303.0, 1533.0, 75.0) && !PlayerToPoint(8.0, playerid, 268.0, 77.0, 1001.0) && !PlayerToPoint(8.0, playerid, 319.76, 312.17, 999.14) && !PlayerToPoint(8.0, playerid, 319.76, 316.07, 999.14))
			{
				SendClientMessage(playerid, COLOR_GREY, "[INFO:] Nie jesteœ ko³o wiezienia. Nie mo¿esz nikogo zaaresztowaæ !");
				return 1;
			}
			tmp = strtok(cmdtext, idx);
			new time = strval(tmp);
			if(PlayerToPoint(8.0, playerid, 268.0, 77.0, 1001.0))
			{
				if(time < 1 || time > 60)
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Czas aresztowania nie mo¿e byæ d³u¿szy ni¿ 60 minut i krótszy ni¿ 1 minuta!");
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Jeœli chcesz aresztowaæ podejrzanego na d³u¿ej udaj siê do g³ównego wiêzienia");
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
			if(AdminDuty[suspect] == 1)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz aresztowaæ administratora bêd¹cego na s³u¿bie !");
				return 1;
			}
			if(gPlayerData[playerid][pCharacterDying] > 0)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz aresztowaæ osoby umieraj¹cej !");
				return 1;
			}
			if(!PlayerCuffed[suspect])
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Przed aresztowanie podejrzany musi mieæ za³o¿one kajdanki");
				return 1;
			}
			
			gPlayerData[playerid][pAchieveArrests]++;
			SavePlayerData(playerid, "AchieveArrests");
			
			PlayerCuffed[suspect] = 0;
			if(!gPlayerData[suspect][pFirstJail])
			{
				gPlayerData[suspect][pFirstJail] = 1;
				SavePlayerData(suspect, "FirstJail");
				// AddExpPoint(playerid);
				SendClientMessage(playerid, COLOR_GREEN, "[INFO:] Jesteœ poraz pierwszy w wiêzieniu !");
			}
			format(string, sizeof(string), "[INFO:] %s zosta³ aresztowany.", GetPlayerNameEx(suspect));
			SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
			ResetPlayerWeapons(suspect);		
			SetPlayerSkin(suspect, 96);
			if(!PlayerToPoint(8.0, playerid, 268.0, 77.0, 1001.0))
			{
				DBVariables[2][varDValue]++;
				SetPlayerInterior(suspect, 0);
				SetPlayerVirtualWorld(suspect,21);
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
				SetPlayerToPos(suspect, 266.0,77.0,1001.0);
				gPlayerData[suspect][pCrashX] = 266.0;
				gPlayerData[suspect][pCrashY] = 77.0;
				gPlayerData[suspect][pCrashZ] = 1001.0;
			}
			
			format(string, sizeof(string), "UPDATE `samp_wanted` SET `Punished` = '1' WHERE `PlayerName` = '%s'", gPlayerData[suspect][pName]);
			mysql_query(string, SAVE, playerid, db_con2);
			
			TogglePlayerControllable(suspect, 0);
			defer UnfreezePlayer(suspect);

			//SetPlayerToPos(suspect,1775.0,-1563.0,1739.0);
			gPlayerData[suspect][pJailTime] = time * 60;

			SavePlayerData(suspect, "JailTime");

			format(string, sizeof(string), "[INFO:] Aresztowany! - Czas odsiadki: %d sekund", gPlayerData[suspect][pJailTime]);
			SendClientMessage(suspect, COLOR_LIGHTYELLOW2, string);
			format(string, sizeof(string), "[INFO:] Jeœli chcesz wyjœæ na zewn¹trz wpisz /idznaspacerniak", gPlayerData[suspect][pJailTime]);
			SendClientMessage(suspect, COLOR_LIGHTYELLOW2, string);
			format(string, sizeof(string), "[SFPD:] %s aresztowa³ %s.",GetPlayerNameEx(playerid), GetPlayerNameEx(suspect));
			SendFactionTypeMessage(1, COLOR_LSPD, string);
			gPlayerData[suspect][pJailed] = 1;

			SavePlayerData(suspect, "Jailed");

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
		else if(strcmp(cmd, "/frakcja", true) == 0 || strcmp(cmd, "/f", true) == 0)
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ta komenda nie jest ju¿ aktywna");
			// if(gPlayerData[playerid][pCharacterDying] == 0)
			// {
				// new wstring[128];
				// new faction = gPlayerData[playerid][pFaction];
				// new rank = gPlayerData[playerid][pRank];
				// new length = strlen(cmdtext);
				// while ((idx < length) && (cmdtext[idx] <= ' '))
				// {
					// idx++;
				// }
				// new offset = idx;
				// new result[128];
				// while ((idx < length) && ((idx - offset) < (sizeof(result) - 1)))
				// {
					// result[idx - offset] = cmdtext[idx];
					// idx++;
				// }
				// result[idx - offset] = EOS;
				// if(!strlen(result))
				// {
					// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] (/f)rakcja");
					// return 1;
				// }
				// if((nofooc) && gPlayerData[playerid][pAdmin] < 1)
				// {
					// SendClientMessage(playerid, COLOR_GRAD2, "[INFO:] Chat frakcyjny zosta³ wy³¹czony przez administratora !");
					// return 1;
				// }
				// if(Muted[playerid])
				// {
					// SendClientMessage(playerid, COLOR_RED, "[INFO:] Jesteœ uciszony, nie mo¿e u¿ywaæ tego chatu !");
					// return 1;
				// }
				// if(gPlayerData[playerid][pFaction] != 255)
				// {
					// if(IsPlayerInAnyVehicle(playerid) || PHaveItem(playerid, 3, 2))
					// {
						// new vehicleID = GetPlayerVehicleID(playerid);
						// if(vehicleID != INVALID_VEHICLE_ID && PHaveItem(playerid, 3, 2) == 0)
						// {
							// if(gVehData[vehicleID-1][mVehFaction] != 255)
							// {
								// if(gVehData[vehicleID-1][mVehFaction] != gPlayerData[playerid][pFaction] && PHaveItem(playerid, 3, 2) == 0)
								// {
									// SendClientMessage(playerid, COLOR_LIGHTYELLOW2,  "[INFO:] Nie jesteœ w pojeŸdzie frakcyjnym ani nie posiadasz radia !");
									// return 1;
								// }
							// }
						// }
						// if(rank == 1)
						// {
							// format(wstring, sizeof(wstring), "(([Radio:] %s %s: %s))",DynamicFactions[faction][fRank1],GetPlayerNameEx(playerid),result);
							// SendFactionMessage(gPlayerData[playerid][pFaction], COLOR_FACTIONCHAT, wstring);
							// FactionChatLog(wstring);
						// }
						// else if(rank == 2)
						// {
							// format(wstring, sizeof(wstring), "(([Radio:] %s %s: %s))",DynamicFactions[faction][fRank2],GetPlayerNameEx(playerid),result);
							// SendFactionMessage(gPlayerData[playerid][pFaction], COLOR_FACTIONCHAT, wstring);
							// FactionChatLog(wstring);
						// }
						// else if(rank == 3)
						// {
							// format(wstring, sizeof(wstring), "(([Radio:] %s %s: %s))",DynamicFactions[faction][fRank3],GetPlayerNameEx(playerid),result);
							// SendFactionMessage(gPlayerData[playerid][pFaction], COLOR_FACTIONCHAT, wstring);
							// FactionChatLog(wstring);
						// }
						// else if(rank == 4)
						// {
							// format(wstring, sizeof(wstring), "(([Radio:] %s %s: %s))",DynamicFactions[faction][fRank4],GetPlayerNameEx(playerid),result);
							// SendFactionMessage(gPlayerData[playerid][pFaction], COLOR_FACTIONCHAT, wstring);
							// FactionChatLog(wstring);
						// }
						// else if(rank == 5)
						// {
							// format(wstring, sizeof(wstring), "(([Radio:] %s %s: %s))",DynamicFactions[faction][fRank5],GetPlayerNameEx(playerid),result);
							// SendFactionMessage(gPlayerData[playerid][pFaction], COLOR_FACTIONCHAT, wstring);
							// FactionChatLog(wstring);
						// }
						// else if(rank == 6)
						// {
							// format(wstring, sizeof(wstring), "(([Radio:] %s %s: %s))",DynamicFactions[faction][fRank6],GetPlayerNameEx(playerid),result);
							// SendFactionMessage(gPlayerData[playerid][pFaction], COLOR_FACTIONCHAT, wstring);
							// FactionChatLog(wstring);
						// }
						// else if(rank == 7)
						// {
							// format(wstring, sizeof(wstring), "(([Radio:] %s %s: %s))",DynamicFactions[faction][fRank7],GetPlayerNameEx(playerid),result);
							// SendFactionMessage(gPlayerData[playerid][pFaction], COLOR_FACTIONCHAT, wstring);
							// FactionChatLog(wstring);
						// }
						// else if(rank == 8)
						// {
							// format(wstring, sizeof(wstring), "(([Radio:] %s %s: %s))",DynamicFactions[faction][fRank8],GetPlayerNameEx(playerid),result);
							// SendFactionMessage(gPlayerData[playerid][pFaction], COLOR_FACTIONCHAT, wstring);
							// FactionChatLog(wstring);
						// }
						// else if(rank == 9)
						// {
							// format(wstring, sizeof(wstring), "(([Radio:] %s %s: %s))",DynamicFactions[faction][fRank9],GetPlayerNameEx(playerid),result);
							// SendFactionMessage(gPlayerData[playerid][pFaction], COLOR_FACTIONCHAT, wstring);
							// FactionChatLog(wstring);
						// }
						// else if(rank == 10)
						// {
							// format(wstring, sizeof(wstring), "(([Radio:] %s %s: %s))",DynamicFactions[faction][fRank10],GetPlayerNameEx(playerid),result);
							// SendFactionMessage(gPlayerData[playerid][pFaction], COLOR_FACTIONCHAT, wstring);
							// FactionChatLog(wstring);
						// }
					// }
					// else
					// {
						// SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie znajdujesz siê w pojeŸdzie frakcyjnym");
						// return 1;
					// }
				// }
				// else
				// {
					// SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ cz³onkiem frakcji !");
				// }
			// }
			// else
			// {
				// SendClientMessage(playerid, COLOR_RED, "[INFO:] Twoja postaæ jest nieprzytomna, nie mo¿e mówiæ");
			// }
			return 1;
		}
		else if(strcmp(cmd, "/zapros", true) == 0)
		{
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /zapros [id gracza]");
				return 1;
			}
			giveplayerid = ReturnUser(tmp);
			if(gPlayerData[playerid][pRank] == 1 && gPlayerData[playerid][pFaction] != 255)
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
									SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] Ustal rangi swojej frakcji zanim zaprosisz graczy !");
								}
								else
								{
									FactionRequest[giveplayerid] = faction;
									format(form,sizeof(form), "Zosta³eœ zaproszony do %s przez %s. (wpisz /akceptuj frakcje) aby do³¹czyæ. ",DynamicFactions[faction][Name],GetPlayerNameEx(playerid));
									SendClientMessage(giveplayerid,COLOR_LIGHTBLUE,form);
									format(form,sizeof(form), "Zaprosi³eœ %s do do³¹czenia do frakcji %s. ",GetPlayerNameEx(giveplayerid),DynamicFactions[faction][Name]);
									SendClientMessage(playerid,COLOR_LIGHTBLUE,form);
								}
								return 1;
							}
							else
							{
								SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] Ten gracz nie jest on-line!");
							}
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Niew³aœciwe ID.");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Osobê któr¹ próbujesz zaprosiæ jest ju¿ we frakcji.");
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ liderem !");
			}
			return 1;
		}
		else if(strcmp(cmd, "/wypros", true) == 0)
		{
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /wypros [id gracza]");
				return 1;
			}
			giveplayerid = ReturnUser(tmp);
			if(gPlayerData[playerid][pRank] == 1 && gPlayerData[playerid][pFaction] != 255)
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
								format(form,sizeof(form), "Zosta³eœ wyproszony z %s przez %s.",DynamicFactions[faction][Name],GetPlayerNameEx(playerid));
								SendClientMessage(giveplayerid,COLOR_LIGHTBLUE,form);
								format(form,sizeof(form), "Wyprosi³eœ %s z %s.",GetPlayerNameEx(giveplayerid),DynamicFactions[faction][Name]);
								SendClientMessage(playerid,COLOR_LIGHTBLUE,form);
								gPlayerData[giveplayerid][pFaction] = 255;
								gPlayerData[giveplayerid][pRank] = 0;

								SavePlayerData(giveplayerid, "Faction");
								SavePlayerData(giveplayerid, "Rank");

								format(form, sizeof(form), "[FRAKCJA:] %s zosta³ wyproszony z frakcji przez %s.",GetPlayerNameEx(giveplayerid),GetPlayerNameEx(playerid));
								SendFactionMessage(gPlayerData[playerid][pFaction], COLOR_FACTIONCHAT, form);
								return 1;
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Gracz nie jest on-line.");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Niew³aœciwe ID.");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Próbowa³eœ wyprosiæ kogoœ kto nie jest w Twojej frakcji.");
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ liderem!");
			}
			return 1;
		}
		else if(strcmp(cmd, "/kick", true) == 0)
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
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Invalid ID.");
			}
			return 1;
		}
		else if(strcmp(cmd, "/mkick", true) == 0)
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
						SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie jesteœ upowa¿niony do kickowania admina !");
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
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Invalid ID.");
			}
			return 1;
		}
		else if(strcmp(cmd, "/aserverinfo",true)==0)
		{
			if(gPlayerData[playerid][pAdmin] != 5)
				return 0;
			new form[128];
			SendClientMessage(playerid, COLOR_WHITE, "Server Statistics:");
			format(form, sizeof form, "[INFO:] Total Objects: %d.", GetObjectCount());
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2,form);
			format(form, sizeof form, "[INFO:] Total Vehicles: %d.", GetVehicleCount());
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2,form);
			format(form, sizeof form, "[INFO:] Total Pickups: %d.", CountDynamicPickups());
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2,form);
			return 1;
		}
		else if(strcmp(cmd, "/asuicide",true)==0)
		{
			if(gPlayerData[playerid][pAdmin] < 1)
				return 0;
			SetPlayerHealth(playerid, 0);
			return 1;
		}
		else if(strcmp(cmd, "/alistfaction", true) == 0)
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
			format(wstring, sizeof(wstring), "[ID:%d] Faction Name: %s - Materials: %d - Drugs: %d - Money: %d$ - Join Rank: %d - Use Skins: %d - Type: %d",text, DynamicFactions[text][Name],DynamicFactions[text][fMaterials],DynamicFactions[text][fDrugs],DynamicFactions[text][fBank],DynamicFactions[text][fJoinRank],DynamicFactions[text][fUseSkins],DynamicFactions[text][fType]);
			SendClientMessage(playerid,COLOR_ADMINCMD, wstring);
			format(wstring, sizeof(wstring), "[ID:%d] Skins: %d|%d|%d|%d|%d|%d|%d|%d|%d|%d - Rank Amount: %d - Use Color: %d", text,DynamicFactions[text][fSkin1],DynamicFactions[text][fSkin2],DynamicFactions[text][fSkin3],DynamicFactions[text][fSkin4],DynamicFactions[text][fSkin5],DynamicFactions[text][fSkin6],DynamicFactions[text][fSkin7],DynamicFactions[text][fSkin8],DynamicFactions[text][fSkin9],DynamicFactions[text][fSkin10],DynamicFactions[text][fRankAmount],DynamicFactions[text][fUseColor]);
			SendClientMessage(playerid,COLOR_ADMINCMD, wstring);
			return 1;
		}
		else if(strcmp(cmd, "/respawnvehicles", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			for(new i = 0; i < sizeof(gVehData); i++)
			{
				if(IsVehicleOccupied(i) == 0)
				{
					SetVehicleToRespawnEx(i);
				}
			}
			format(string, sizeof(string), "[INFO:] Pustes samochody zosta³y zrespawnowane przez %s.", GetPlayerNameEx(playerid));
			ABroadCast(COLOR_YELLOW,string,1);
			return 1;
		}
		else if(strcmp(cmd, "/acarenter", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 1)
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
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Invalid Vehicle ID.");
			return 1;
		}
		else if(strcmp(cmd, "/acarenterex", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 1)
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
				SetPlayerVirtualWorld(playerid, gVehData[id-1][mVehVW]);
				SetPlayerInterior(playerid, gVehData[id-1][mVehInt]);
				PutPlayerIntoVehicle(playerid,id,0);
			}
			else
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Invalid Vehicle ID.");
			return 1;
		}
		else if(strcmp(cmd, "/acarrandmodel", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] != 5)
				return 0;
			if(IsPlayerInAnyVehicle(playerid))
			{
				new rand = random(sizeof(gRandomStableModels));
				new Float:x,Float:y,Float:z,Float:a;
				GetPlayerPos(playerid,x,y,z);
				GetVehicleZAngle(idcar,a);
				gVehData[tmpcar][mVehModel] = gRandomStableModels[rand][0];
				DestroyVehicle(idcar);
				CreateVehicle(gVehData[tmpcar][mVehModel],x,y,z,a,gVehData[tmpcar][mVehColor1],gVehData[tmpcar][mVehColor2], -1);
				PutPlayerIntoVehicle(playerid,idcar,0);

				SaveVehData(tmpcar, "VehModel");

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
		else if(strcmp(cmd, "/aFactionCar", true) == 0)
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
					gVehData[tmpcar][mVehFaction] = thecar;
					new wstring[128];
					format(wstring, sizeof(wstring), "You've set Vehicle ID %d's faction to: %d.", idcar,thecar);
					SendClientMessage(playerid,COLOR_ADMINCMD, wstring);

					SaveVehData(tmpcar, "VehFaction");
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
		else if(strcmp(cmd, "/acartype", true) == 0)
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
				gVehData[tmpcar][mVehType] = thecar;
				new wstring[128];
				format(wstring, sizeof(wstring), "You've set Vehicle ID %d's type to: %d.", idcar,thecar);
				SendClientMessage(playerid,COLOR_ADMINCMD, wstring);

				SaveVehData(tmpcar, "VehType");
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "Your not in a vehicle!");
			}
			return 1;
		}
		else if(strcmp(cmd, "/akceptuj",true)==0)
		{
			new x_info[256];
			x_info = strtok(cmdtext, idx);
			new wstring[128];

			if(!strlen(x_info)) {
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /akceptuj [uzycia]");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[UZYCIA:] frakcje - produkty - umoweoc - umoweac - kosztorys - kupnobiznesu");
				return 1;
			}
			if(strcmp(x_info, "kupnobiznesu",true) == 0)
			{
				if(gBizBoughtApprovalSendBy[playerid] == -1 || !IsPlayerConnected(gBizBoughtApprovalSendBy[playerid]))
				{
					gBizBoughtApprovalSendBy[playerid] = -1;
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz ¿adnego zg³oszenia do rozpatrzenia");
					return 1;
				}
				new Float:x, Float:y, Float:z;
				GetPlayerPos(gBizBoughtApprovalSendBy[playerid], x, y, z);
				if(!IsPlayerInRangeOfPoint(playerid, 5.0, x, y, z))
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Jesteœ zbyt daleko od tej osoby !");
					return 1;
				}
				gBizBoughtApproved[gBizBoughtApprovalSendBy[playerid]] = gBizBoughtApprovalID[gBizBoughtApprovalSendBy[playerid]];
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Wyda³eœ pozwolenie na kupno biznesu !");
				SendClientMessage(gBizBoughtApprovalSendBy[playerid], COLOR_GREEN, "[INFO:] Otrzyma³eœ pozwolenie na kupno biznesu !");
				gBizBoughtApprovalSendBy[playerid] = -1;
				return 1;
			}			
			if(strcmp(x_info, "frakcje",true) == 0)
			{
				new faction = FactionRequest[playerid];
				if(FactionRequest[playerid] != 255)
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
						SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] Jesteœ ju¿ we frakcji, musisz najpierw opuœciæ obecn¹ !");
					}
				}
				else
				{
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] Dosta³eœ oferte do³¹czenia do frakcji !");
				}
			}
			if(strcmp(x_info, "kosztorys", true) == 0)
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
									// if(gPlayerData[playerid][pItem1type] == 2) { cars += floatround((cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem1]))-400]* DBVariables[0][varFValue]) * DynamicTaxes[CarTax],floatround_round); }
									// if(gPlayerData[playerid][pItem2type] == 2) { cars += floatround((cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem2]))-400]* DBVariables[0][varFValue]) * DynamicTaxes[CarTax],floatround_round); }
									// if(gPlayerData[playerid][pItem3type] == 2) { cars += floatround((cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem3]))-400]* DBVariables[0][varFValue]) * DynamicTaxes[CarTax],floatround_round); }
									// if(gPlayerData[playerid][pItem4type] == 2) { cars += floatround((cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem4]))-400]* DBVariables[0][varFValue]) * DynamicTaxes[CarTax],floatround_round); }
									// if(gPlayerData[playerid][pItem5type] == 2) { cars += floatround((cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem5]))-400]* DBVariables[0][varFValue]) * DynamicTaxes[CarTax],floatround_round); }
									// if(gPlayerData[playerid][pItem6type] == 2) { cars += floatround((cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem6]))-400]* DBVariables[0][varFValue]) * DynamicTaxes[CarTax],floatround_round); }
									// if(gPlayerData[playerid][pItem7type] == 2) { cars += floatround((cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem7]))-400]* DBVariables[0][varFValue]) * DynamicTaxes[CarTax],floatround_round); }
									// if(gPlayerData[playerid][pItem8type] == 2) { cars += floatround((cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem8]))-400]* DBVariables[0][varFValue]) * DynamicTaxes[CarTax],floatround_round); }
									// if(gPlayerData[playerid][pItem9type] == 2) { cars += floatround((cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem9]))-400]* DBVariables[0][varFValue]) * DynamicTaxes[CarTax],floatround_round); }
									// if(gPlayerData[playerid][pItem10type] == 2) { cars += floatround((cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem10]))-400]* DBVariables[0][varFValue]) * DynamicTaxes[CarTax],floatround_round); }
									// TODO: Include business tax
								
									radio += DynamicTaxes[RadioTax];
									if(gPlayerData[playerid][pCash] + gPlayerData[playerid][pBank] >= DynamicTaxes[TheRich]) { richest += floatround(((gPlayerData[playerid][pCash] + gPlayerData[playerid][pBank]) * 0.01),floatround_round); }
								}
								
								// new occost;
								
								// if(gPlayerData[playerid][pItem1type] == 2)
								// {
									// if(gPlayerData[playerid][pItem1param] != 0 && gPlayerData[playerid][pItem1param] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem1]))-400]) * 0.1, floatround_round))
									// {
										// occost += 200;
									// }
									// if(gPlayerData[playerid][pItem1param] != 0 && gPlayerData[playerid][pItem1param] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem1]))-400]) * 0.2, floatround_round))
									// {
										// occost += 400;
									// }
									// if(gPlayerData[playerid][pItem1param] != 0 && gPlayerData[playerid][pItem1param] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem1]))-400]) * 0.5, floatround_round))
									// {
										// occost += 1000;
									// }
								// }
								// if(gPlayerData[playerid][pItem2type] == 2)
								// {
									// if(gPlayerData[playerid][pItem2param] != 0 && gPlayerData[playerid][pItem2param] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem2]))-400]) * 0.1, floatround_round))
									// {
										// occost += 200;
									// }
									// if(gPlayerData[playerid][pItem2param] != 0 && gPlayerData[playerid][pItem2param] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem2]))-400]) * 0.2, floatround_round))
									// {
										// occost += 400;
									// }
									// if(gPlayerData[playerid][pItem2param] != 0 && gPlayerData[playerid][pItem2param] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem2]))-400]) * 0.5, floatround_round))
									// {
										// occost += 1000;
									// }
								// }
								// if(gPlayerData[playerid][pItem3type] == 2)
								// {
									// if(gPlayerData[playerid][pItem3param] != 0 && gPlayerData[playerid][pItem3param] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem3]))-400]) * 0.1, floatround_round))
									// {
										// occost += 200;
									// }
									// if(gPlayerData[playerid][pItem3param] != 0 && gPlayerData[playerid][pItem3param] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem3]))-400]) * 0.2, floatround_round))
									// {
										// occost += 400;
									// }
									// if(gPlayerData[playerid][pItem3param] != 0 && gPlayerData[playerid][pItem3param] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem3]))-400]) * 0.5, floatround_round))
									// {
										// occost += 1000;
									// }
								// }
								// if(gPlayerData[playerid][pItem4type] == 2)
								// {
									// if(gPlayerData[playerid][pItem4param] != 0 && gPlayerData[playerid][pItem4param] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem4]))-400]) * 0.1, floatround_round))
									// {
										// occost += 200;
									// }
									// if(gPlayerData[playerid][pItem4param] != 0 && gPlayerData[playerid][pItem4param] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem4]))-400]) * 0.2, floatround_round))
									// {
										// occost += 400;
									// }
									// if(gPlayerData[playerid][pItem4param] != 0 && gPlayerData[playerid][pItem4param] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem4]))-400]) * 0.5, floatround_round))
									// {
										// occost += 1000;
									// }
								// }
								// if(gPlayerData[playerid][pItem5type] == 2)
								// {
									// if(gPlayerData[playerid][pItem5param] != 0 && gPlayerData[playerid][pItem5param] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem5]))-400]) * 0.1, floatround_round))
									// {
										// occost += 200;
									// }
									// if(gPlayerData[playerid][pItem5param] != 0 && gPlayerData[playerid][pItem5param] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem5]))-400]) * 0.2, floatround_round))
									// {
										// occost += 400;
									// }
									// if(gPlayerData[playerid][pItem5param] != 0 && gPlayerData[playerid][pItem5param] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem5]))-400]) * 0.5, floatround_round))
									// {
										// occost += 1000;
									// }
								// }
								// if(gPlayerData[playerid][pItem6type] == 2)
								// {
									// if(gPlayerData[playerid][pItem6param] != 0 && gPlayerData[playerid][pItem6param] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem6]))-400]) * 0.1, floatround_round))
									// {
										// occost += 200;
									// }
									// if(gPlayerData[playerid][pItem6param] != 0 && gPlayerData[playerid][pItem6param] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem6]))-400]) * 0.2, floatround_round))
									// {
										// occost += 400;
									// }
									// if(gPlayerData[playerid][pItem6param] != 0 && gPlayerData[playerid][pItem6param] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem6]))-400]) * 0.5, floatround_round))
									// {
										// occost += 1000;
									// }
								// }
								// if(gPlayerData[playerid][pItem7type] == 2)
								// {
									// if(gPlayerData[playerid][pItem7param] != 0 && gPlayerData[playerid][pItem7param] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem7]))-400]) * 0.1, floatround_round))
									// {
										// occost += 200;
									// }
									// if(gPlayerData[playerid][pItem7param] != 0 && gPlayerData[playerid][pItem7param] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem7]))-400]) * 0.2, floatround_round))
									// {
										// occost += 400;
									// }
									// if(gPlayerData[playerid][pItem7param] != 0 && gPlayerData[playerid][pItem7param] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem7]))-400]) * 0.5, floatround_round))
									// {
										// occost += 1000;
									// }
								// }
								// if(gPlayerData[playerid][pItem8type] == 2)
								// {
									// if(gPlayerData[playerid][pItem8param] != 0 && gPlayerData[playerid][pItem8param] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem8]))-400]) * 0.1, floatround_round))
									// {
										// occost += 200;
									// }
									// if(gPlayerData[playerid][pItem8param] != 0 && gPlayerData[playerid][pItem8param] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem8]))-400]) * 0.2, floatround_round))
									// {
										// occost += 400;
									// }
									// if(gPlayerData[playerid][pItem8param] != 0 && gPlayerData[playerid][pItem8param] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem8]))-400]) * 0.5, floatround_round))
									// {
										// occost += 1000;
									// }
								// }
								// if(gPlayerData[playerid][pItem9type] == 2)
								// {
									// if(gPlayerData[playerid][pItem9param] != 0 && gPlayerData[playerid][pItem9param] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem9]))-400]) * 0.1, floatround_round))
									// {
										// occost += 200;
									// }
									// if(gPlayerData[playerid][pItem9param] != 0 && gPlayerData[playerid][pItem9param] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem9]))-400]) * 0.2, floatround_round))
									// {
										// occost += 400;
									// }
									// if(gPlayerData[playerid][pItem9param] != 0 && gPlayerData[playerid][pItem9param] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem9]))-400]) * 0.5, floatround_round))
									// {
										// occost += 1000;
									// }
								// }
								// if(gPlayerData[playerid][pItem10type] == 2)
								// {
									// if(gPlayerData[playerid][pItem10param] != 0 && gPlayerData[playerid][pItem10param] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem10]))-400]) * 0.1, floatround_round))
									// {
										// occost += 200;
									// }
									// if(gPlayerData[playerid][pItem10param] != 0 && gPlayerData[playerid][pItem10param] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem10]))-400]) * 0.2, floatround_round))
									// {
										// occost += 400;
									// }
									// if(gPlayerData[playerid][pItem10param] != 0 && gPlayerData[playerid][pItem10param] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem10]))-400]) * 0.5, floatround_round))
									// {
										// occost += 1000;
									// }
								// }
								
								// new accost = 0;
								
								// if(gPlayerData[playerid][pItem1type] == 2)
								// {
									// if(gPlayerData[playerid][pItem1param2] != 0 && gPlayerData[playerid][pItem1param2] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem1]))-400]) * 0.15, floatround_round))
									// {
										// accost += 200;
									// }
									// if(gPlayerData[playerid][pItem1param2] != 0 && gPlayerData[playerid][pItem1param2] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem1]))-400]) * 0.3, floatround_round))
									// {
										// accost += 400;
									// }
									// if(gPlayerData[playerid][pItem1param2] != 0 && gPlayerData[playerid][pItem1param2] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem1]))-400]) * 0.5, floatround_round))
									// {
										// accost += 1000;
									// }
								// }
								// if(gPlayerData[playerid][pItem2type] == 2)
								// {
									// if(gPlayerData[playerid][pItem2param2] != 0 && gPlayerData[playerid][pItem2param2] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem2]))-400]) * 0.15, floatround_round))
									// {
										// accost += 200;
									// }
									// if(gPlayerData[playerid][pItem2param2] != 0 && gPlayerData[playerid][pItem2param2] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem2]))-400]) * 0.3, floatround_round))
									// {
										// accost += 400;
									// }
									// if(gPlayerData[playerid][pItem2param2] != 0 && gPlayerData[playerid][pItem2param2] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem2]))-400]) * 0.5, floatround_round))
									// {
										// accost += 1000;
									// }
								// }
								// if(gPlayerData[playerid][pItem3type] == 2)
								// {
									// if(gPlayerData[playerid][pItem3param2] != 0 && gPlayerData[playerid][pItem3param2] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem3]))-400]) * 0.15, floatround_round))
									// {
										// accost += 200;
									// }
									// if(gPlayerData[playerid][pItem3param2] != 0 && gPlayerData[playerid][pItem3param2] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem3]))-400]) * 0.3, floatround_round))
									// {
										// accost += 400;
									// }
									// if(gPlayerData[playerid][pItem3param2] != 0 && gPlayerData[playerid][pItem3param2] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem3]))-400]) * 0.5, floatround_round))
									// {
										// accost += 1000;
									// }
								// }
								// if(gPlayerData[playerid][pItem4type] == 2)
								// {
									// if(gPlayerData[playerid][pItem4param2] != 0 && gPlayerData[playerid][pItem4param2] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem4]))-400]) * 0.15, floatround_round))
									// {
										// accost += 200;
									// }
									// if(gPlayerData[playerid][pItem4param2] != 0 && gPlayerData[playerid][pItem4param2] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem4]))-400]) * 0.3, floatround_round))
									// {
										// accost += 400;
									// }
									// if(gPlayerData[playerid][pItem4param2] != 0 && gPlayerData[playerid][pItem4param2] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem4]))-400]) * 0.5, floatround_round))
									// {
										// accost += 1000;
									// }
								// }
								// if(gPlayerData[playerid][pItem5type] == 2)
								// {
									// if(gPlayerData[playerid][pItem5param2] != 0 && gPlayerData[playerid][pItem5param2] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem5]))-400]) * 0.15, floatround_round))
									// {
										// accost += 200;
									// }
									// if(gPlayerData[playerid][pItem5param2] != 0 && gPlayerData[playerid][pItem5param2] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem5]))-400]) * 0.3, floatround_round))
									// {
										// accost += 400;
									// }
									// if(gPlayerData[playerid][pItem5param2] != 0 && gPlayerData[playerid][pItem5param2] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem5]))-400]) * 0.5, floatround_round))
									// {
										// accost += 1000;
									// }
								// }
								// if(gPlayerData[playerid][pItem6type] == 2)
								// {
									// if(gPlayerData[playerid][pItem6param2] != 0 && gPlayerData[playerid][pItem6param2] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem6]))-400]) * 0.15, floatround_round))
									// {
										// accost += 200;
									// }
									// if(gPlayerData[playerid][pItem6param2] != 0 && gPlayerData[playerid][pItem6param2] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem6]))-400]) * 0.3, floatround_round))
									// {
										// accost += 400;
									// }
									// if(gPlayerData[playerid][pItem6param2] != 0 && gPlayerData[playerid][pItem6param2] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem6]))-400]) * 0.5, floatround_round))
									// {
										// accost += 1000;
									// }
								// }
								// if(gPlayerData[playerid][pItem7type] == 2)
								// {
									// if(gPlayerData[playerid][pItem7param2] != 0 && gPlayerData[playerid][pItem7param2] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem7]))-400]) * 0.15, floatround_round))
									// {
										// accost += 200;
									// }
									// if(gPlayerData[playerid][pItem7param2] != 0 && gPlayerData[playerid][pItem7param2] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem7]))-400]) * 0.3, floatround_round))
									// {
										// accost += 400;
									// }
									// if(gPlayerData[playerid][pItem7param2] != 0 && gPlayerData[playerid][pItem7param2] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem7]))-400]) * 0.5, floatround_round))
									// {
										// accost += 1000;
									// }
								// }
								// if(gPlayerData[playerid][pItem8type] == 2)
								// {
									// if(gPlayerData[playerid][pItem8param2] != 0 && gPlayerData[playerid][pItem1param2] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem8]))-400]) * 0.15, floatround_round))
									// {
										// accost += 200;
									// }
									// if(gPlayerData[playerid][pItem8param2] != 0 && gPlayerData[playerid][pItem8param2] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem8]))-400]) * 0.3, floatround_round))
									// {
										// accost += 400;
									// }
									// if(gPlayerData[playerid][pItem8param2] != 0 && gPlayerData[playerid][pItem8param2] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem8]))-400]) * 0.5, floatround_round))
									// {
										// accost += 1000;
									// }
								// }
								// if(gPlayerData[playerid][pItem9type] == 2)
								// {
									// if(gPlayerData[playerid][pItem9param2] != 0 && gPlayerData[playerid][pItem9param2] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem9]))-400]) * 0.15, floatround_round))
									// {
										// accost += 200;
									// }
									// if(gPlayerData[playerid][pItem9param2] != 0 && gPlayerData[playerid][pItem9param2] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem9]))-400]) * 0.3, floatround_round))
									// {
										// accost += 400;
									// }
									// if(gPlayerData[playerid][pItem9param2] != 0 && gPlayerData[playerid][pItem9param2] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem9]))-400]) * 0.5, floatround_round))
									// {
										// accost += 1000;
									// }
								// }
								// if(gPlayerData[playerid][pItem10type] == 2)
								// {
									// if(gPlayerData[playerid][pItem10param2] != 0 && gPlayerData[playerid][pItem10param2] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem10]))-400]) * 0.15, floatround_round))
									// {
										// accost += 200;
									// }
									// if(gPlayerData[playerid][pItem10param2] != 0 && gPlayerData[playerid][pItem10param2] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem10]))-400]) * 0.3, floatround_round))
									// {
										// accost += 400;
									// }
									// if(gPlayerData[playerid][pItem10param2] != 0 && gPlayerData[playerid][pItem10param2] == floatround(float(cenyPojazdow[GetVehicleModel(CarSerialToID(gPlayerData[playerid][pItem10]))-400]) * 0.5, floatround_round))
									// {
										// accost += 1000;
									// }
								// }
								
								// ensurance = accost + occost;
								
								GivePlayerCash(AccountantOffer[playerid], AccountantCost[playerid]);
								GivePlayerCash(playerid, -AccountantCost[playerid]);
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
			// if(strcmp(x_info, "produkty",true) == 0)
			// {
				// if(ProductsOffer[playerid] < 999)
				// {
					// if(IsPlayerConnected(ProductsOffer[playerid]))
					// {
						// if(ProxDetectorS(5.0, playerid, ProductsOffer[playerid]))
						// {
							// if(GetPlayerCash(playerid) >= ProductsCost[playerid])
							// {
								// if(gPlayerData[playerid][pBizKey] != 255)
								// {
									// if((ProductsOffer[playerid] + Businesses[gPlayerData[playerid][pBizKey]][Products]) > 200)
									// {
										// SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Mo¿esz przechowywaæ jedynie 200 produktów w swoim biznesie !");
										// return 1;
									// }
									// format(string, sizeof(string), "[INFO:] Produkty kupione - koszt: %d$.", ProductsCost[playerid]);
									// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
									// format(string, sizeof(string), "[INFO:] %s kupi³ od Ciebie produkty - koszt: %d$.", GetPlayerNameEx(playerid), ProductsCost[playerid]);
									// SendClientMessage(ProductsOffer[playerid], COLOR_LIGHTYELLOW2, string);
									// new bizkey = gPlayerData[playerid][pBizKey];
									// Businesses[bizkey][Products] += ProductsAmount[playerid];
									// GivePlayerCash(playerid, -ProductsCost[playerid]);
									// GivePlayerCash(ProductsOffer[playerid], ProductsCost[playerid]);

									// SavePlayerData(ProductsOffer[playerid], "Products");

									// SaveStatsData("produkty", gPlayerData[playerid][pName], ProductsCost[playerid], -1, -1);
									
									// ProductsOffer[playerid] = 999;
									// ProductsCost[playerid] = 0;
									// ProductsAmount[playerid] = 0;
									// SaveBizData(bizkey, "Products");

									// return 1;
								// }
								// else
								// {
									// SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz biznesu !");
									// return 1;
								// }
							// }
							// else
							// {
								// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie masz wystarczaj¹cej iloœci pieniêdzy !");
								// return 1;
							// }
						// }
						// else
						// {
							// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ wystarczaj¹co blisko osoby która oferuje produkty !");
							// return 1;
						// }
					// }
				// }
				// else
				// {
					// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nikt nie zaoferowa³ Tobie produktów !");
					// return 1;
				// }
			// }
			if(strcmp(x_info, "umoweoc",true) == 0)
			{
				if(EnsuranceOC[playerid][Level] == 0)
				{
					SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie posiadasz umowy OC do podpisania !");
					return 1;
				}
				if(gPlayerData[playerid][pCash] < 150)
				{
					SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie masz wystarczaj¹cej iloœc pieniêdzy (2000$) by podpisaæ umowe !");
					return 1;
				}
				DynamicFactions[FACTIONID_GOVERNMENT][fBank] += 150;
				SaveFData(FACTIONID_GOVERNMENT, "Bank");
				GivePlayerCash(playerid, -150);
				new vehid = CarSerialToID(SlotParam1(playerid, EnsuranceOC[playerid][vehicleNr]));
				SetPSlotParam3(playerid, EnsuranceOC[playerid][vehicleNr], floatround(float(cenyPojazdow[gVehData[vehid][mVehModel]-400]) * 0.3, floatround_round));
				SendClientMessage(playerid, COLOR_GREEN, "[INFO:] Ubezpieczenie OC zosta³o aktywowane !");
				EnsuranceOC[playerid][Level] = 0;
			}
			if(strcmp(x_info, "umoweac",true) == 0)
			{
				if(EnsuranceAC[playerid][Level] == 0)
				{
					SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie posiadasz umowy AC do podpisania !");
					return 1;
				}
				if(gPlayerData[playerid][pCash] < 450)
				{
					SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie masz wystarczaj¹cej iloœc pieniêdzy (2000$) by podpisaæ umowe !");
					return 1;
				}
				DynamicFactions[FACTIONID_GOVERNMENT][fBank] += 450;
				SaveFData(FACTIONID_GOVERNMENT, "Bank");
				GivePlayerCash(playerid, -450);
				new vehid = CarSerialToID(SlotParam1(playerid, EnsuranceOC[playerid][vehicleNr]));
				SetPSlotParam4(playerid, EnsuranceOC[playerid][vehicleNr], floatround(float(cenyPojazdow[gVehData[vehid][mVehModel]-400]) * 0.3, floatround_round));
				SendClientMessage(playerid, COLOR_GREEN, "[INFO:] Ubezpieczenie AC zosta³o aktywowane !");
				EnsuranceAC[playerid][Level] = 0;
			}
			return 1;
		}
		else if(strcmp(cmd, "/fwyplac", true) == 0)
		{
			if(gPlayerData[playerid][pFaction] != 255)
			{
				if((gPlayerData[playerid][pFaction] == FACTIONID_POLICE || gPlayerData[playerid][pFaction] == FACTIONID_MEDICS || gPlayerData[playerid][pFaction] == FACTIONID_RAFINERY
					|| gPlayerData[playerid][pFaction] == FACTIONID_GOVERNMENT || gPlayerData[playerid][pFaction] == FACTIONID_SANNEWS || gPlayerData[playerid][pFaction] == FACTIONID_TAXI) 
					&& !DynamicFactions[gPlayerData[playerid][pFaction]][mPayOffGranted])
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Musisz poprosiæ administratora 5 lvl o zgode na wyp³ate pieniêdzy");
					return 1;
				}
				
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
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Wartoœæ wyp³aty musi byæ wiêksza od 0 !");
					return 1;
				}
				new inPosition = 0;
				if(!IsAtBank(playerid))
				{
					for(new i = 0; i < 4; i++)
					{
						if(!PlayerToPoint(1.0, playerid, gATM[i][0], gATM[i][1], gATM[i][2]))
							continue;
						inPosition = 2;
					}
				}
				else
					inPosition = 1;
				if(inPosition == 0)
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Aby wyp³aciæ pieni¹dze musisz znajdowaæ siê w banku lub przy automacie");
					return 1;
				}
				if(gPlayerData[playerid][pRank] == 1)
				{
					if(DynamicFactions[gPlayerData[playerid][pFaction]][fBank] >= cashdeposit + 3)
					{
						if(DynamicFactions[gPlayerData[playerid][pFaction]][mPayOffGranted])
							DynamicFactions[gPlayerData[playerid][pFaction]][mPayOffGranted] = 0;
						GivePlayerCash(playerid,cashdeposit);
						DynamicFactions[gPlayerData[playerid][pFaction]][fBank]=DynamicFactions[gPlayerData[playerid][pFaction]][fBank]-cashdeposit - 3;
						format(string, sizeof(string), "[INFO:] Wyp³aci³eœ %d$ z konta frakcji, nowy stan konta: %d$", cashdeposit,DynamicFactions[gPlayerData[playerid][pFaction]][fBank]);
						SendClientMessage(playerid, COLOR_WHITE, string);
						if(inPosition == 2)
							SendClientMessage(playerid, COLOR_WHITE, "[INFO:] Pobrano op³ate w wysokoœci 3$ za skorzystanie z automatu");
						format(string, sizeof(string), "[FACTION:] %s wyp³aci³ %d$ z konta frakcji.",gPlayerData[playerid][pName],cashdeposit);
						ABroadCast(COLOR_YELLOW, string, 5);
						SaveFData(gPlayerData[playerid][pFaction], "Bank");
						format(string, sizeof(string), "[CASH:] Player: %s, withdraw: %d$, from faction id: %d", gPlayerData[playerid][pName], cashdeposit, gPlayerData[playerid][pFaction]);
						PayLog(string);
						return 1;
					}
					else
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie masz tyle pieniêdzy na koncie frakcji !");
						return 1;
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ liderem frakcji !");
					return 1;
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Niew³aœciwa frakcja.");
			}
			return 1;
		}
		else if(strcmp(cmd, "/firmawyplac", true) == 0)
		{
			if(gPlayerData[playerid][pFaction2] != 255)
			{
				tmp = strtok(cmdtext, idx);
				if(!strlen(tmp))
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /firmawyplac [kwota]");
					return 1;
				}
				new cashdeposit = strval(tmp);
				if(!strlen(tmp))
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /firmawyplac [kwota]");
					return 1;
				}
				if(cashdeposit <= 0)
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Wartoœæ przelewu musi byæ wiêksza od 0 !");
					return 1;
				}
				new inPosition = 0;
				if(!PlayerToPoint(5.0,playerid,BankPosition[X],BankPosition[Y],BankPosition[Z]) 
				&& !PlayerToPoint(2.0, playerid, BankPosition2[X], BankPosition2[Y], BankPosition2[Z]))
				{
					for(new i = 0; i < 4; i++)
					{
						if(!PlayerToPoint(1.0, playerid, gATM[i][0], gATM[i][1], gATM[i][2]))
							continue;
						inPosition = 2;
					}
				}
				else
					inPosition = 1;
				if(inPosition == 0)
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Aby wyp³aciæ pieni¹dze musisz znajdowaæ siê w banku lub przy automacie");
					return 1;
				}
				if(gPlayerData[playerid][pRank2] == 1)
				{
					if(DynamicFactions[gPlayerData[playerid][pFaction2]][fBank] >= cashdeposit + 3)
					{
						GivePlayerCash(playerid,cashdeposit);
						DynamicFactions[gPlayerData[playerid][pFaction2]][fBank]=DynamicFactions[gPlayerData[playerid][pFaction2]][fBank]-cashdeposit - 3;
						format(string, sizeof(string), "[INFO:] Wyp³aci³eœ %d$ z konta firmy, nowy stan konta: %d$", cashdeposit,DynamicFactions[gPlayerData[playerid][pFaction2]][fBank]);
						SendClientMessage(playerid, COLOR_WHITE, string);
						if(inPosition == 2)
							SendClientMessage(playerid, COLOR_WHITE, "[INFO:] Pobrano op³ate w wysokoœci 3$ za skorzystanie z automatu");
						format(string, sizeof(string), "[FACTION:] %s wyp³aci³ %d$ z konta firmy.",gPlayerData[playerid][pName],cashdeposit);
						SendFactionMessage(gPlayerData[playerid][pFaction2], COLOR_FACTIONCHAT, string);
						SaveFData(gPlayerData[playerid][pFaction2], "Bank");
						format(string, sizeof(string), "[CASH:] Player: %s, withdraw: %d$, from faction id: %d", gPlayerData[playerid][pName], cashdeposit, gPlayerData[playerid][pFaction2]);
						PayLog(string);
						return 1;
					}
					else
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie masz tyle pieniêdzy na koncie firmy !");
						return 1;
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ za³o¿ycielem !");
					return 1;
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie posiadasz firmy");
			}
			return 1;
		}
		else if(strcmp(cmd, "/wyplaczbiznesu", true) == 0)
		{
			for(new i = 0; i < sizeof(Businesses); i++)
			{
				if(!PlayerToPoint(100.0, playerid, Businesses[i][ExitX], Businesses[i][ExitY], Businesses[i][ExitZ]) || GetPlayerVirtualWorld(playerid) != i)
					continue;
				if(strcmp(gPlayerData[playerid][pName], Businesses[i][Owner], false) != 0)
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w³aœcicielem tego biznesu !");
					return 1;
				}
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
				if(cashdeposit > Businesses[i][Till])
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie masz tyle pieniêdzy w tym biznesie");
					return 1;
				}
				GivePlayerCash(playerid,cashdeposit);
				Businesses[i][Till] -= cashdeposit;
				format(string, sizeof(string), "[INFO:] Wyp³aci³eœ %d$ ze swojej kasy w biznesie, nowy stan: %d$ ", cashdeposit,Businesses[i][Till]);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
				SaveBizData(i, "Till");
				format(string, sizeof(string), "[CASH:] Player: %s, withdraw: %d$, from business id: %d", gPlayerData[playerid][pName], cashdeposit, i);
				PayLog(string);
				return 1;
			}
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Musisz znajdowaæ siê w biznesie aby wyp³aciæ pieni¹dze");
			return 1;
		}
		else if(strcmp(cmd, "/fwplac", true) == 0)
		{
			if(!PlayerToPoint(5.0, playerid, BankPosition[X], BankPosition[Y], BankPosition[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition2[X], BankPosition2[Y], BankPosition2[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition3[X], BankPosition3[Y], BankPosition3[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition4[X], BankPosition4[Y], BankPosition4[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition5[X], BankPosition5[Y], BankPosition5[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition6[X], BankPosition6[Y], BankPosition6[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition7[X], BankPosition7[Y], BankPosition7[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition8[X], BankPosition8[Y], BankPosition8[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition9[X], BankPosition9[Y], BankPosition9[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition10[X], BankPosition10[Y], BankPosition10[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition11[X], BankPosition11[Y], BankPosition11[Z]))
			{				
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ w banku !");
				return 1;
			}
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
				if(GetPlayerCash(playerid) >= cashdeposit)
				{
					GivePlayerCash(playerid,-cashdeposit);
					DynamicFactions[gPlayerData[playerid][pFaction]][fBank] += cashdeposit;
					
					SaveFData(gPlayerData[playerid][pFaction], "Bank");
					format(string, sizeof(string), "[CASH:] Player: %s, donate: %d$, to faction id: %d", gPlayerData[playerid][pName], cashdeposit, gPlayerData[playerid][pFaction]);
					PayLog(string);
					
					format(string, sizeof(string), "[INFO:] Wp³aci³eœ %d$ na konto frakcji, nowy stan: %d$", cashdeposit,DynamicFactions[gPlayerData[playerid][pFaction]][fBank]);
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
					
					return 1;
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie masz tyle pieniêdzy !");
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ we frakcji !");
			}
			return 1;
		}
		else if(strcmp(cmd, "/firmawplac", true) == 0)
		{
			if(!PlayerToPoint(5.0, playerid, BankPosition[X], BankPosition[Y], BankPosition[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition2[X], BankPosition2[Y], BankPosition2[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition3[X], BankPosition3[Y], BankPosition3[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition4[X], BankPosition4[Y], BankPosition4[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition5[X], BankPosition5[Y], BankPosition5[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition6[X], BankPosition6[Y], BankPosition6[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition7[X], BankPosition7[Y], BankPosition7[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition8[X], BankPosition8[Y], BankPosition8[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition9[X], BankPosition9[Y], BankPosition9[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition10[X], BankPosition10[Y], BankPosition10[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition11[X], BankPosition11[Y], BankPosition11[Z]))
			{				
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ w banku !");
				return 1;
			}
			if(gPlayerData[playerid][pFaction2] != 255)
			{
				tmp = strtok(cmdtext, idx);
				if(!strlen(tmp))
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /firmawplac [kwota]");
					return 1;
				}
				new cashdeposit = strval(tmp);
				if(!strlen(tmp))
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /firmawplac [kwota]");
					return 1;
				}
				if(cashdeposit <= 0)
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Wartoœæ przelewu musi byæ wiêksza od 0 !");
					return 1;
				}
				if(GetPlayerCash(playerid) >= cashdeposit)
				{
					GivePlayerCash(playerid,-cashdeposit);
					DynamicFactions[gPlayerData[playerid][pFaction2]][fBank] += cashdeposit;
					
					SaveFData(gPlayerData[playerid][pFaction2], "Bank");
					format(string, sizeof(string), "[CASH:] Player: %s, donate: %d$, to faction id: %d", gPlayerData[playerid][pName], cashdeposit, gPlayerData[playerid][pFaction2]);
					PayLog(string);
					
					format(string, sizeof(string), "[INFO:] Wp³aci³eœ %d$ na konto firmy, nowy stan: %d$", cashdeposit,DynamicFactions[gPlayerData[playerid][pFaction2]][fBank]);
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
					
					return 1;
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie masz tyle pieniêdzy !");
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie posiadasz firmy !");
			}
			return 1;
		}
		else if(strcmp(cmd, "/wplac", true) == 0)
		{
			if(!PlayerToPoint(5.0, playerid, BankPosition[X], BankPosition[Y], BankPosition[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition2[X], BankPosition2[Y], BankPosition2[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition3[X], BankPosition3[Y], BankPosition3[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition4[X], BankPosition4[Y], BankPosition4[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition5[X], BankPosition5[Y], BankPosition5[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition6[X], BankPosition6[Y], BankPosition6[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition7[X], BankPosition7[Y], BankPosition7[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition8[X], BankPosition8[Y], BankPosition8[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition9[X], BankPosition9[Y], BankPosition9[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition10[X], BankPosition10[Y], BankPosition10[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition11[X], BankPosition11[Y], BankPosition11[Z]))
			{				
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ w banku !");
				return 1;
			}
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
				if(!gPlayerData[playerid][pFirstBankUse])
				{
					gPlayerData[playerid][pFirstBankUse] = 1;
					SavePlayerData(playerid, "FirstBankUse");
					// AddExpPoint(playerid);
					SendClientMessage(playerid, COLOR_GREEN, "[INFO:] Poraz pierwszy korzystasz z us³ug banku !");
				}
				GivePlayerCash(playerid,-cashdeposit);
				gPlayerData[playerid][pBank] = cashdeposit + gPlayerData[playerid][pBank];

				format(string, sizeof(string), "[INFO:] Wp³aci³eœ %d$ na Twoje konto w banku, nowy stan: %d$", cashdeposit,gPlayerData[playerid][pBank]);
				SendClientMessage(playerid, COLOR_WHITE, string);
				
				format(string, sizeof(string), "[CASH:] Player: %s, donate: %d$, to bank", gPlayerData[playerid][pName], cashdeposit);
				PayLog(string);
				return 1;
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie masz tyle pieniêdzy !");
			}
			return 1;
		}
		else if(strcmp(cmd, "/wyplac", true) == 0)
		{
			new inPosition = 0;
			if(!PlayerToPoint(5.0, playerid, BankPosition[X], BankPosition[Y], BankPosition[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition2[X], BankPosition2[Y], BankPosition2[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition3[X], BankPosition3[Y], BankPosition3[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition4[X], BankPosition4[Y], BankPosition4[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition5[X], BankPosition5[Y], BankPosition5[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition6[X], BankPosition6[Y], BankPosition6[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition7[X], BankPosition7[Y], BankPosition7[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition8[X], BankPosition8[Y], BankPosition8[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition9[X], BankPosition9[Y], BankPosition9[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition10[X], BankPosition10[Y], BankPosition10[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition11[X], BankPosition11[Y], BankPosition11[Z]))
			{
				for(new i = 0; i < sizeof(gATM); i++)
				{
					if(!PlayerToPoint(1.0, playerid, gATM[i][0], gATM[i][1], gATM[i][2]))
						continue;
					inPosition = 2;
				}
			}
			else
				inPosition = 1;
			if(inPosition == 0)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] ¯eby wyp³aciæ pieni¹dze musisz znajdowaæ siê w banku lub przy automacie");
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
				if(!gPlayerData[playerid][pFirstBankUse])
				{
					gPlayerData[playerid][pFirstBankUse] = 1;
					SavePlayerData(playerid, "FirstBankUse");
					// AddExpPoint(playerid);
					SendClientMessage(playerid, COLOR_GREEN, "[INFO:] Poraz pierwszy korzystasz z us³ug banku !");
					return 1;
				}
				GivePlayerCash(playerid,cashdeposit);
				gPlayerData[playerid][pBank] -= cashdeposit ;
				if(inPosition == 2)
				{
					gPlayerData[playerid][pBank] -= 3;
					SendClientMessage(playerid, COLOR_WHITE, "[INFO:] Pobrano op³ate w wysokoœci 3$ za skorzystanie z automatu");
					format(string, sizeof(string), "[INFO:] Wyp³aci³eœ %d$, nowy stan: %d$ (uwzglêdniono 3$)", cashdeposit,gPlayerData[playerid][pBank]);
				}
				else
					format(string, sizeof(string), "[INFO:] Wyp³aci³eœ %d$, nowy stan: %d$", cashdeposit,gPlayerData[playerid][pBank]);
				SendClientMessage(playerid, COLOR_WHITE, string);
				format(string, sizeof(string), "[CASH:] Player: %s, withdraw: %d$, to bank", gPlayerData[playerid][pName], cashdeposit);
				PayLog(string);
				return 1;
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie masz tyle pieniêdzy w banku !");
			}
			return 1;
		}
		else if(strcmp(cmd, "/przelew", true) == 0)
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
			if(!PlayerToPoint(5.0, playerid, BankPosition[X], BankPosition[Y], BankPosition[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition2[X], BankPosition2[Y], BankPosition2[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition3[X], BankPosition3[Y], BankPosition3[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition4[X], BankPosition4[Y], BankPosition4[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition5[X], BankPosition5[Y], BankPosition5[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition6[X], BankPosition6[Y], BankPosition6[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition7[X], BankPosition7[Y], BankPosition7[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition8[X], BankPosition8[Y], BankPosition8[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition9[X], BankPosition9[Y], BankPosition9[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition10[X], BankPosition10[Y], BankPosition10[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition11[X], BankPosition11[Y], BankPosition11[Z]))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ w banku !");
				return 1;
			}
			if(gPlayerData[playerid][pPlayingHours] < 3 && !gPlayerData[playerid][pAdmin])
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Musisz przegraæ co najmniej 3 godziny aby móc robiæ przelewy");
				return 1;
			}
			new moneys = strval(tmp);
			if(moneys > 1000 && gPlayerData[playerid][pPlayingHours] < 5 && !gPlayerData[playerid][pAdmin])
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Musisz przegraæ co najmniej 5 godzin aby móc robiæ przelewy w kwocie powy¿ej 1 000 $");
				return 1;
			}
			if(!IsPlayerConnected(giveplayerid))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Niew³aœciwe ID");
				return 1;
			}
			if(giveplayerid != INVALID_PLAYER_ID)
			{
				new playermoney = gPlayerData[playerid][pBank] ;
				if(moneys > 0 && playermoney >= moneys)
				{
					if(giveplayerid != playerid)
					{
						if(!gPlayerData[playerid][pFirstBankUse])
						{
							gPlayerData[playerid][pFirstBankUse] = 1;
							SavePlayerData(playerid, "FirstBankUse");
							SendClientMessage(playerid, COLOR_GREEN, "[INFO:] Poraz pierwszy korzystasz z us³ug banku !");
							return 1;
						}
						gPlayerData[playerid][pBank] -= moneys;
						gPlayerData[giveplayerid][pBank] += moneys;
						format(string, sizeof(string), "[INFO:] Przela³eœ %d$ na konto %s", moneys, GetPlayerNameEx(giveplayerid),giveplayerid);
						SendClientMessage(playerid, COLOR_WHITE, string);
						format(string, sizeof(string), "[INFO:]Dosta³eœ przelew o wartoœci %d$ od %s", moneys, GetPlayerNameEx(playerid), playerid);
						SendClientMessage(giveplayerid, COLOR_YELLOW, string);
						
						format(string, sizeof(string), "[CASH:] %s transfered cash value of %d$ to %s", gPlayerData[playerid][pName], moneys, gPlayerData[giveplayerid][pName]);
						PayLog(string);
					}
					else
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz sam sobie przelaæ pieniêdzy !");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Niew³aœciwa kwota.");
				}
			}
			return 1;
		}
		else if(strcmp(cmd, "/stankonta", true) == 0)
		{
			new inPosition = 0;
			if(!PlayerToPoint(5.0, playerid, BankPosition[X], BankPosition[Y], BankPosition[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition2[X], BankPosition2[Y], BankPosition2[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition3[X], BankPosition3[Y], BankPosition3[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition4[X], BankPosition4[Y], BankPosition4[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition5[X], BankPosition5[Y], BankPosition5[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition6[X], BankPosition6[Y], BankPosition6[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition7[X], BankPosition7[Y], BankPosition7[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition8[X], BankPosition8[Y], BankPosition8[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition9[X], BankPosition9[Y], BankPosition9[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition10[X], BankPosition10[Y], BankPosition10[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition11[X], BankPosition11[Y], BankPosition11[Z]))
			{
				for(new i = 0; i < 4; i++)
				{
					if(!PlayerToPoint(1.0, playerid, gATM[i][0], gATM[i][1], gATM[i][2]))
						continue;
					inPosition = 2;
				}
			}
			else
				inPosition = 1;
			if(inPosition == 0)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] ¯eby sprawdziæ stan konta musisz znajdowaæ siê w banku lub przy automacie");
				return 1;
			}
			format(string, sizeof(string), "[INFO:] Stan konta: %d$.", gPlayerData[playerid][pBank]);
			if(!gPlayerData[playerid][pFirstBankUse])
			{
				gPlayerData[playerid][pFirstBankUse] = 1;
				SavePlayerData(playerid, "FirstBankUse");
				// AddExpPoint(playerid);
				SendClientMessage(playerid, COLOR_GREEN, "[INFO:] Poraz pierwszy korzystasz z us³ug banku !");
			}
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			return 1;
		}
		else if(strcmp(cmd, "/fstankonta", true) == 0)
		{
			if(gPlayerData[playerid][pFaction] == 255)
			{
				SendClientMessage(playerid, COLOR_RED, "[INFO:] Niew³aœciwa frakcja !");
				return 1;
			}
			if(!CheckRankPrivilidges(gPlayerData[playerid][pFaction], gPlayerData[playerid][pRank], "fstankonta"))
			{
				SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie posiadasz uprawnieñ do sprawdzenie stanu konta frakcji !");
				return 1;
			}
			new inPosition = 0;
			if(!PlayerToPoint(5.0, playerid, BankPosition[X], BankPosition[Y], BankPosition[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition2[X], BankPosition2[Y], BankPosition2[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition3[X], BankPosition3[Y], BankPosition3[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition4[X], BankPosition4[Y], BankPosition4[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition5[X], BankPosition5[Y], BankPosition5[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition6[X], BankPosition6[Y], BankPosition6[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition7[X], BankPosition7[Y], BankPosition7[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition8[X], BankPosition8[Y], BankPosition8[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition9[X], BankPosition9[Y], BankPosition9[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition10[X], BankPosition10[Y], BankPosition10[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition11[X], BankPosition11[Y], BankPosition11[Z]))
			{
				for(new i = 0; i < 4; i++)
				{
					if(!PlayerToPoint(1.0, playerid, gATM[i][0], gATM[i][1], gATM[i][2]))
						continue;
					inPosition = 2;
				}
			}
			else
				inPosition = 1;
			if(inPosition == 0)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] ¯eby sprawdziæ stan konta musisz znajdowaæ siê w banku lub przy automacie");
				return 1;
			}
			format(string, sizeof(string), "[INFO:] Stan konta frakcji: %d$.", DynamicFactions[gPlayerData[playerid][pFaction]][fBank]);
			SendClientMessage(playerid, COLOR_WHITE, string);
			return 1;
		}
		else if(strcmp(cmd, "/firmastankonta", true) == 0)
		{
			if(gPlayerData[playerid][pFaction2] == 255)
			{
				SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie posiadasz firmy");
				return 1;
			}
			if(gPlayerData[playerid][pRank2] != 1)
			{
				SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie jesteœ za³o¿ycielem tej firmy");
				return 1;
			}
			new inPosition = 0;
			if(!PlayerToPoint(5.0, playerid, BankPosition[X], BankPosition[Y], BankPosition[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition2[X], BankPosition2[Y], BankPosition2[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition3[X], BankPosition3[Y], BankPosition3[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition4[X], BankPosition4[Y], BankPosition4[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition5[X], BankPosition5[Y], BankPosition5[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition6[X], BankPosition6[Y], BankPosition6[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition7[X], BankPosition7[Y], BankPosition7[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition8[X], BankPosition8[Y], BankPosition8[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition9[X], BankPosition9[Y], BankPosition9[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition10[X], BankPosition10[Y], BankPosition10[Z])
				&& !PlayerToPoint(2.0, playerid, BankPosition11[X], BankPosition11[Y], BankPosition11[Z]))
			{
				for(new i = 0; i < 4; i++)
				{
					if(!PlayerToPoint(1.0, playerid, gATM[i][0], gATM[i][1], gATM[i][2]))
						continue;
					inPosition = 2;
				}
			}
			else
				inPosition = 1;
			if(inPosition == 0)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] ¯eby sprawdziæ stan konta musisz znajdowaæ siê w banku lub przy automacie");
				return 1;
			}
			format(string, sizeof(string), "[INFO:] Stan konta firmy: %d$.", DynamicFactions[gPlayerData[playerid][pFaction2]][fBank]);
			SendClientMessage(playerid, COLOR_WHITE, string);
			return 1;
		}
		else if(strcmp(cmd, "/fmatsy", true) == 0)
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
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ we frakcyjnym sk³adzie materia³ów !");
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Niew³aœciwa frakcja.");
			}
			return 1;
		}
		else if(strcmp(cmd, "/fnarkotyki", true) == 0)
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
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ we frakcyjnym sk³adzie narkotyków!");
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Niew³¹œciwe ID.");
			}
			return 1;
		}
		else if(strcmp(cmd, "/wyplaczdomu", true) == 0)
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
							format(string, sizeof(string), "[INFO:] Wyp³aci³eœ %d$ ze swojego sejfu, nowy stan: %d$ ", cashdeposit,Houses[i][Money]);
							SendClientMessage(playerid, COLOR_WHITE, string);
							SaveHouseData(i, "Money");
							format(string, sizeof(string), "[CASH:] Player: %s, withdraw: %d$, from house id: %d", gPlayerData[playerid][pName], cashdeposit, i);
							PayLog(string);
							return 1;
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie posiadasz tyle piniêdzy w swoim sejfie !");
					}
				}
			}
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Musisz znajdowaæ siê w domu aby wzi¹œæ pieni¹dze");

			return 1;
		}
		else if(strcmp(cmd, "/wplacdodomu", true) == 0)
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

									format(string, sizeof(string), "[INFO:] Wp³aci³eœ %d$ do swojego sejfu, nowy stan: %d$ ", cashdeposit,Houses[i][Money]);
									SendClientMessage(playerid, COLOR_WHITE, string);
									
									format(string, sizeof(string), "[CASH:] Player: %s, donate: %d$, to house id: %d", gPlayerData[playerid][pName], cashdeposit, i);
									PayLog(string);

									SaveHouseData(i, "Money");
								}
								else
								{
									SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz wp³aciæ wiêcej ni¿ $150000.");
								}
							}
							else
							{
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Osi¹gn¹³eœ limit iloœci piniêdzy w sejfie ($150,000)");
							}
							return 1;
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie masz tyle pieniêdzy !");
					}
				}
			}
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Musisz znajdowaæ siê w domu aby schowaæ pieni¹dze");

			return 1;
		}
		else if(strcmp(cmd, "/engine", true) == 0 || strcmp(cmd, "/e", true) == 0)
		{
			if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
			{
				new enginedyn, lights, alarm, bonnet, boot, objective, doors;
				GetVehicleParamsEx(idcar, enginedyn, lights, alarm, doors, bonnet, boot, objective);
				
				if(AdminDuty[playerid])
				{
					if(gVehData[idcar-1][EngineOn] == 0)
					{
						StartEngine(playerid, tmpcar);
						return 1;
					}
					else
					{
						SetVehicleParamsEx(idcar,0,lights,alarm,doors,bonnet,boot,objective);
						gVehData[idcar-1][EngineOn] = 0;
						SaveVehData(tmpcar, "EngineOn");
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
								if(gVehData[tmpcar][mVehIgnitionDamaged])
								{
									SendClientMessage(playerid, COLOR_RED, "[INFO:] Stacyjka pojazdu jest uszkodzona, nie mo¿na uruchomiæ silnika");
									return 1;
								}
								if(gVehData[tmpcar][mVehIgnitionHacked] || PHaveItem(playerid, 2, gVehData[tmpcar][CarSerial]) > 0 || gVehData[tmpcar][mVehType] == 3
									|| strcmp(gPlayerData[playerid][pName], Businesses[gVehData[tmpcar][BusinessID]][Owner], false) == 0 && !gVehData[tmpcar][mVehOwned])
								{
									StartEngine(playerid, tmpcar);
									return 1;
								}
								if(gVehData[tmpcar][mVehFaction] == 255)
								{
									if(gVehData[tmpcar][mVehType] == 1 || gVehData[tmpcar][mVehType] == 4 || gVehData[tmpcar][mVehType] == 5 || gVehData[tmpcar][mVehType] == 6 || gVehData[tmpcar][mVehType] == 7|| gVehData[tmpcar][mVehType] == 11)
									{
										StartEngine(playerid, tmpcar);
										return 1;
									}
									if(gVehData[tmpcar][mVehType] == 2 && gPlayerData[playerid][pJob] == 13)
									{
										StartEngine(playerid, tmpcar);
										return 1;
									}
								}
								if(gVehData[tmpcar][mVehFaction] != 255)
								{
									if(gPlayerData[playerid][pFaction] == gVehData[tmpcar][mVehFaction])
									{
										if(gVehData[tmpcar][mVehType] == 0)
										{
											if(gPlayerData[playerid][pDuty] == 0)
											{
												if(DynamicFactions[gVehData[tmpcar][mVehFaction]][fType] == 1)
													SendClientMessage(playerid,COLOR_RED, "[INFO:] Nie jesteœ na s³u¿bie - nie posiadasz kluczy.");
												else
													SendClientMessage(playerid,COLOR_RED, "[INFO:] Nie posiadasz kluczy - mo¿esz je wzi¹œæ z przebieralni.");
												EngineTurningOn[playerid] = 1;
												EngineInfo(playerid);
												return 1;
											}
											if(gPlayerData[playerid][pDuty])
											{
												if(!CheckRankPrivilidges(gPlayerData[playerid][pFaction], gPlayerData[playerid][pRank], "vehdrive"))
												{
													SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie posiadasz uprawnieñ do prowadzenia pojazdów frakcyjnych !");
													return 1;
												}
												else
												{
													StartEngine(playerid, tmpcar);
													return 1;
												}												
											}
										}
									}
								}
								if(DynamicFactions[gPlayerData[playerid][pFaction]][fType] == FACTIONT_GANG)
								{
									if(VehInZoneStealTimeLeft(idcar) > 0)
									{
										format(string, sizeof(string), "[INFO:] Musisz odczekaæ jeszcze %d godzin zanim bêdziesz móg³ w³amaæ siê do tego pojazdu", VehInZoneStealTimeLeft(idcar));
										SendClientMessage(playerid, COLOR_ORANGE, string);
										return 1;
									}
									else if(VehInZoneStealTimeLeft(idcar) == -1)
									{
										SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Pojazd nie znajduje siê na ¿adnym terytorium - nie mo¿esz siê do niego w³amaæ");
										return 1;
									}
									EngineTurningOn[playerid] = 1;
									SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[STATUS:] Brak kluczy - próba odpalenia silnika...");
									PlayerActionMessage(playerid, 15.0, "próbuje odpaliæ silnik");
									defer EngineNoKey(playerid);
									return 1;
								}
								else
								{
									SendClientMessage(playerid, COLOR_RED, "[STATUS:] Nie posiadasz kluczy do tego pojazdu.");
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
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] Pojazd uszkodzony lub w trakcie napraw/wymiany opon, wezwij mechanika !");
							return 1;
						}
					}
				}
				else if(gVehData[idcar-1][EngineOn])
				{
					if(EngineTurningOn[playerid] == 0)
					{
						if(gVehData[tmpcar][mVehType] == 7)
							return 1;
						SetVehicleParamsEx(idcar,0,lights,alarm,doors,bonnet,boot,objective);
						gVehData[tmpcar][EngineOn] = 0;
						SaveVehData(tmpcar, "EngineOn");
						return 1;
					}
				}
			}
			else
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w pojeŸdzie lub nie jesteœ kierowc¹ !");
			return 1;
		}
		else if(strcmp(cmd, "/przekaz", true) == 0)
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
			if(!gPlayerData[playerid][pAdmin])
			{
				if(gPlayerData[playerid][pPlayingHours] < 3)
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Musisz przegraæ co najmniej 3 godziny aby móc przekazywaæ pieni¹dze");
					return 1;
				}
				if(moneys > 1000 && gPlayerData[playerid][pPlayingHours] < 5)
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Musisz przegraæ co najmniej 5 godzin aby dokonywaæ przekazów wiêkszych ni¿ 1000$");
					return 1;
				}
			}
			if(moneys < 1 || moneys > 10000)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Niew³aœciwa kwota - mo¿na przekazywaæ kworty nie wiêksze ni¿ 10 000$");
				return 1;
			}
			if(IsPlayerConnected(giveplayerid))
			{
				if(giveplayerid != INVALID_PLAYER_ID)
				{
					if(gPlayerData[playerid][pAdmin] < 1)
					{
						if(gPlayerData[giveplayerid][pPlayingHours] < 3)
						{
							SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Aby przekazaæ graczowi pieni¹dze musi on przegraæ co najmniej 3 godziny");
							return 1;
						}
						if(moneys > 1000 && gPlayerData[giveplayerid][pPlayingHours] < 5)
						{
							SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Aby przekazaæ graczowi kwote wiêksz¹ ni¿ 1000$ musi on mieæ przegrane co najmniej 5 godzin");
							return 1;
						}
					}
					if(ProxDetectorS(5.0, playerid, giveplayerid))
					{
						if(giveplayerid != playerid)
						{
							playermoney = GetPlayerCash(playerid);
							if(moneys > 0 && playermoney >= moneys)
							{
								gTransferCoolDown[playerid] = 60;
								GivePlayerCash(playerid, - moneys);
								GivePlayerCash(giveplayerid, moneys);
								format(string, sizeof(string), "[INFO:] %d$ przekazane %s [%d]", moneys, GetPlayerNameEx(giveplayerid), giveplayerid);
								PlayerPlaySound(playerid, 1052, 0.0, 0.0, 0.0);
								SendClientMessage(playerid, COLOR_WHITE, string);
								format(string, sizeof(string), "[INFO:] %s (ID:%d) przekaza³ Tobie %d$.",GetPlayerNameEx(playerid), playerid, moneys);
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
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Niew³aœciwa kwota.");
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz sam sobie przekazaæ pieniêdzy !");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Jesteœ za daleko od tej osoby.");
					}
				}//invalid id
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Niew³aœciwe ID.");
			}
			return 1;
		}
		else if(strcmp(cmd, "/licencje",true)==0)
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ta komenda nie jest ju¿ aktywna ! Status licencji mo¿esz sprawdziæ przez /mi w itemie prawo jazdy");
			return 1;
		}
		else if(strcmp(cmd, "/skile",true)==0)
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
		else if(strcmp(cmd, "/pokazid",true)==0)
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
						if(ProxDetectorS(8.0, playerid, giveplayerid))
						{
							new text1[5];
							new text2[5];
							new text3[5];					
							new text4[5];					
							
							SendClientMessage(giveplayerid,COLOR_LIGHTGREEN, "-----------[SAN ANDREAS ID:]---------");
							format(string, sizeof(string), "Nick: %s.", GetPlayerNameEx(playerid));
							SendClientMessage(giveplayerid, COLOR_WHITE, string);
							format(string, sizeof(string), "Wiek: %d.  P³eæ: %d", gPlayerData[playerid][pAge], gPlayerData[playerid][pSex]);
							SendClientMessage(giveplayerid, COLOR_WHITE, string);
							if(gPlayerData[playerid][pBoatLic]) { text1 = "Tak"; } else { text1 = "Nie"; }
							if(gPlayerData[playerid][pPlaneLic]) { text2 = "Tak"; } else { text2 = "Nie"; }
							if(gPlayerData[playerid][pHeliLic]) { text3 = "Tak"; } else { text3 = "Nie"; }
							if(gPlayerData[playerid][pWepLic]) { text4 = "Tak"; } else { text4 = "Nie"; }
							format(string, sizeof(string), "Licencja na ³odzie: %s - Licencja pilota samolotu: %s - Licencja pilota œmig³owca: %s - Licencja na broñ: %s", text1, text2, text3, text4);			
							SendClientMessage(giveplayerid, COLOR_WHITE, string);
							SendClientMessage(giveplayerid, COLOR_LIGHTGREEN, "--------------------------------------------");
							format(string, sizeof(string), "[INFO:] Pokaza³eœ swoje dane: %s.", GetPlayerNameEx(giveplayerid));
							SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
							return 1;
						}
						else
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten gracz nie jest wystarczaj¹co blisko!");
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
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Niew³aœciwe ID.");
				return 1;
			}
		}
		else if(strcmp(cmd, "/oocstatus", true) == 0)
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
		else if(strcmp(cmd, "/id", true) == 0)
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ta komenda nie jest ju¿ aktywna !");
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Aby pokazaæ dokument wejdŸ do /mi i kliknij na dowód nastêpnie wybierz poka¿ dokument osobie");
			// tmp = strtok(cmdtext, idx);
			// if(!strlen(tmp))
			// {
				// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /id [playerid/PartOName]");
				// return 1;
			// }
			// new target;
			// target = ReturnUser(tmp);
			// new sstring[256];
			// if(IsPlayerConnected(target))
			// {
				// if(target != INVALID_PLAYER_ID)
				// {
					// format(sstring, sizeof(sstring), "[INFO:] Nick: %s (ID: %d).",GetPlayerNameEx(target),target);
					// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, sstring);
				// }
			// }
			return 1;
		}
		else if(strcmp(cmd, "/resetanimacji",true)==0)
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
		else if(strcmp(cmd, "/sledz", true) == 0)
		{
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /sledz [playerid]");
				return 1;
			}
			if(TrackingPlayer[playerid] == 1)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ju¿ kogoœ œledzisz.");
				return 1;
			}
			new id = strval(tmp);
			if(!PHaveItem(id, 3, 3))
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ta osoba nie posiada telefonu który móg³byœ wyœledziæ");
				return 1;
			}
			if(SlotParam1(id, PHaveItem(id, 3, 3)) == 0)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ta osoba ma wy³¹czony telefon !");
				return 1;
			}
			if(gPlayerData[playerid][pJob] == 3)
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
						SendClientMessage(id, COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz œledziæ samego siebie.");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Niew³aœciwe ID.");
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ detektywem !");
			}
			return 1;
		}
		else if(strcmp(cmd, "/sledzpojazd", true) == 0)
		{
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /sledzpojazd [nr rejestracyjny]");
				return 1;
			}
			if(TrackingCar[playerid] == 1)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ju¿ œledzisz inny pojazd.");
				return 1;
			}
			new id;
			new serial = strval(tmp);
			id = CarSerialToID(serial);
			if(gPlayerData[playerid][pJob] == 3)
			{
				if(id < sizeof(gVehData) && id != -1)
				{
					format(string, sizeof(string), "[INFO:] Œledzisz pojazd o rejestracji: %d, punkt zostanie usuniêty w ci¹gu 60 sekund.", serial);
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
					new Float:x,Float:y,Float:z;
					GetVehiclePos(id+1,x,y,z);
					SetPlayerCheckpoint(playerid,x+float(random(320)-160),y+float(random(320)-160),z,100.0);
					defer ClearCheckpointsForPlayer(playerid);
					TrackingCar[playerid] = 1;
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie znaleziono pojazdu o takiej rejestracji");
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ detektywem !");
			}
			return 1;
		}
		else if(strcmp(cmd, "/adonator", true) == 0)
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
				if(gPlayerData[playerid][pAdmin] >= 5)
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
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Niew³aœæiwe ID.");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "Nie jesteœ administratorem.");
				}
			}
			return 1;
		}
		else if(strcmp(cmd, "/donatorcmds", true) == 0)
		{
			if(gPlayerData[playerid][pDonator] == 1)
			{
				SendClientMessage(playerid,COLOR_YELLOW, "____________________________________________________");
				SendClientMessage(playerid,COLOR_WHITE, "[Donator:] /onoff pw - /onoff telefon - ");
				SendClientMessage(playerid,COLOR_YELLOW, "____________________________________________________");
			}
			else
			{
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ sponsorem !");
			}
			return 1;
		}
		else if(strcmp(cmd, "/podejrzany", true) == 0 || strcmp(cmd, "/p", true) == 0)
		{
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /podejrzany [playerid] [zbrodnia]");
				return 1;
			}
			giveplayerid = ReturnUser(tmp);
			if(gPlayerData[playerid][pFaction] != 255 && DynamicFactions[gPlayerData[playerid][pFaction]][fType] == 1)
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
								foreach(Player, i)
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
								
								format(string, sizeof(string), "[INFO:] Uzna³eœ %s za podejrzanego, Powód: %s.", GetPlayerNameEx(giveplayerid),result);
								SendClientMessage(playerid, COLOR_WHITE, string);
								format(string, sizeof(string), "[SFPD:] %s uzna³ za podejrzanego %s, Powód: %s.", GetPlayerNameEx(playerid),GetPlayerNameEx(giveplayerid),result);
								SendFactionTypeMessage(1,COLOR_LSPD,string);
								new location[MAX_ZONE_NAME];
								GetPlayer2DZone(giveplayerid, location, MAX_ZONE_NAME);
								format(string, sizeof(string), "[SFPD:] Do wszystkich jednostek, nowy poszukiwany %s - widziany ostatnio: %s.", GetPlayerNameEx(giveplayerid), location);
								SendFactionTypeMessage(1,COLOR_LSPD,string);
							}
							else
							{
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz u¿yæ tej funkcji na sobie !");
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ na s³u¿bie !");
						}
						return 1;
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] B³êdne ID");
					return 1;
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Niew³aœciwa frakcja.");
				return 1;
			}
			return 1;
		}
		else if(strcmp(cmd, "/apomoc1", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] > 0)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "================================================================================================================================");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[GROUP:] /aplayercmds - /achatcmds - /afactioncmds - /avehcmds - /abuildingcmds - /ahousecmds - /abizcmds - /agotocmds");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[GROUP:] /afactorylegalcmds - /afactorycmds - /ajobscmds - /rafinerycmds - /aservercmds  - /aothercmds - /itemfactorycmds");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[GROUP:] /racecmds");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "/setint - /acceptreport - /abankpos - /aweaponlicensepos - /aflyingtestpos - /adrivingtestpos - /admissionchamberpos");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "/usunraport - /fly - /name - /supervehslap - /lotterycash - /wheelchangepos - /nadajegzaminatora - /testdrivebuypos - /testdriveprice");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "/testdriveareaentrancepos - /testdriveareaexitpos - /testdriverareabuypos - /testdriveareabuytime - /testdriveareabuyprice");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "================================================================================================================================");
			}
			return 1;
		}
		else if(strcmp(cmd, "/apomoc2", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] > 0)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "================================================================================================================================");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "/abuildingopent(2,3) - /abuildingcloset - /amechanicrepairpoint(2,3) - /amechanicjobpos - /arepairallvehicles - /genbuid - /genhuid");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "/acarparkdefault - /acarsreset - /ahousesreset - /abizreset - /acarmodelprice - /resetcamera - /setcamerapos - /setcameralookat");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "/fixdamage - /resetpracy - /unmodcar - /savetune - /checkhp - /setpneon - /setpgarage - /sethealcost - /setexaminecost - /globalsms");
    			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "/snews - /respawnthiscar(/rtc) - /update - /setstartspawn - /setstartmoney - /setstartbank - /setstartskin - /asetleader - /objmaterial");
    			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "/payoffgrant");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "================================================================================================================================");
			}
			return 1;
		}
		else if(strcmp(cmd, "/komendypolicji", true) == 0)
		{
			if(gPlayerData[playerid][pFaction] != 255 && DynamicFactions[gPlayerData[playerid][pFaction]][fType] == 1)
			{
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "(/f)rakcja - /sluzba - (/p)odejrzany - (/r)adio - (/m)egafon - /aresztuj - /wanted - /skuj - /rozkuj - /rewiduj - /zgloszenia");
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "/paralizuj - /skonfiskuj - /mandat - /kody - /zaciagnij - /ww (wezwij wsparcie) - /sprawdzpasy - /punktykarne");
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "/pilotpd - /sprawdznumer - /kolczatka - /zwinkolczatke - /komputerpolicyjny (/kp) - /przeszukaj - /haslokp - /podpalfab");

			}
			else
			{
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] Niew³aœciwa frakcja.");
			}
			return 1;
		}
		else if(strcmp(cmd, "/komendyurzedu", true) == 0)
		{
			if(gPlayerData[playerid][pFaction] == FACTIONID_GOVERNMENT)
			{
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "/ustawdom - /wnetrzedomu - /sprzedajdom - /cenadomu");
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "/wnetrzebudynku - /wejsciebudynku - /nazwabudynku - /cenazalitr");
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "/ustawbiz - /cenabiz - /typbiz - /sprzedajbiz");
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "/resetpktbroni - /dajpozwolenie - /dajbron - /odbierzbron - /sprawdzbron - /komendyurzedu2");
			}
			else
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] Niew³aœciwa frakcja.");
			return 1;
		}
		else if(strcmp(cmd, "/komendyurzedu2", true) == 0)
		{
			if(gPlayerData[playerid][pFaction] == FACTIONID_GOVERNMENT)
			{		
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "/umowaoc - /umowaac - /wyplacodszkodowanieoc - /wyplacodszkodowanieac");
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "/news - /wyrobdowod - /wyrobprawojazdy - /podatki1 - /podatki2 - /wynajmijkomornika - /zmost - /omost - /zslums - /oslums");
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "/dekonfiskata - /wyrobdowodrejestracyjny");
			}
			else
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] Niew³aœciwa frakcja.");
			return 1;
		}
		else if(strcmp(cmd, "/komendymedykow", true) == 0)
		{
			if(gPlayerData[playerid][pFaction] != 255 && gPlayerData[playerid][pFaction] == 2)
			{
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "/ulecz - /pozszywaj - /reanimuj - /detoksykacja - /przebadajpacjenta - /cenazaleczenie - /cenazabadanie");
			}
			else
			{
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] Niew³aœciwa frakcja.");
			}
			return 1;
		}
		else if(strcmp(cmd, "/wezprace", true) == 0)
		{
			if(gPlayerData[playerid][pJob] == 0)
			{
				if(PlayerToPoint(1.0, playerid,GunJob[TakeJobX],GunJob[TakeJobY],GunJob[TakeJobZ]))
				{
					if(GetPlayerVirtualWorld(playerid) == GunJob[TakeJobWorld])
					{
						SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[SUKCES:] Jesteœ teraz dilerem broni, wpisz /komendypracy.");
						gPlayerData[playerid][pJob] = 1; //Gun Job

						SavePlayerData(playerid, "Job");
					}
				}
				else if(PlayerToPoint(1.0, playerid,DrugJob[TakeJobX],DrugJob[TakeJobY],DrugJob[TakeJobZ]))
				{
					if(GetPlayerVirtualWorld(playerid) == DrugJob[TakeJobWorld])
					{
						SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[SUKCES:] Jesteœ teraz dilerem narkotyków, wpisz /komendypracy.");
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
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] Do tej pracy wymagany jest przynajmniej 2 poziom WFu oraz 4 poziom matematyki");
						}
						else
						{
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[SUKCES:] Jesteœ teraz detektywem, wpisz /komendypracy.");
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
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Musisz mieæ co najmniej 5 poziom matematyki aby zdobyæ t¹ prace");
						}
						else
						{
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[SUKCES:] Jesteœ teraz prawnikiem, wpisz /komendypracy.");
							gPlayerData[playerid][pJob] = 4; //Lawyer Job

							SavePlayerData(playerid, "Job");
						}
					// }
				}
				else if(PlayerToPoint(1.0, playerid,WhoreJob[TakeJobX],WhoreJob[TakeJobY],WhoreJob[TakeJobZ]))
				{
					if(GetPlayerVirtualWorld(playerid) == WhoreJob[TakeJobWorld])
					{
						SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[SUKCES:] Jesteœ teraz dziwk¹, wpisz /komendypracy.");
						gPlayerData[playerid][pJob] = 6; //Whore Job

						SavePlayerData(playerid, "Job");
					}
				}
				else if(PlayerToPoint(1.0, playerid,RapistJob[TakeJobX],RapistJob[TakeJobY],RapistJob[TakeJobZ]))
				{
					if(GetPlayerVirtualWorld(playerid) == RapistJob[TakeJobWorld])
					{
						SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[SUKCES:]] Jesteœ teraz gwa³cicielem, wpisz /komendypracy.");
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
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] Musisz mieæ przynamniej 3 poziom WFu aby zdobyæ t¹ prace");
						}
						else
						{
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[SUKCES:] Jesteœ teraz ochroniarzem, wpisz /komendypracy.");
							gPlayerData[playerid][pJob] = 9; //Body Job

							SavePlayerData(playerid, "Job");
						}
					// }
				}
				else if(PlayerToPoint(1.0, playerid,BoxerJob[TakeJobX],BoxerJob[TakeJobY],BoxerJob[TakeJobZ]))
				{
					if(GetPlayerVirtualWorld(playerid) == BoxerJob[TakeJobWorld])
					{
						SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[SUKCES:] Jesteœ teraz boxerem, wpisz /komendypracy.");
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
						SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[SUKCES:] Jesteœ teraz z³odziejem samochodów, wpisz /komendypracy.");
						gPlayerData[playerid][pJob] = 10; //Carjack Job

						SavePlayerData(playerid, "Job");
					}
				}
				else if(PlayerToPoint(1.0, playerid,StuntJob[TakeJobX],StuntJob[TakeJobY],StuntJob[TakeJobZ]))
				{
					if(GetPlayerVirtualWorld(playerid) == StuntJob[TakeJobWorld])
					{
						SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[SUKCES:] Jesteœ teraz kaskaderem, wpisz /komendypracy.");
						gPlayerData[playerid][pJob] = 11; //Stunt Job

						SavePlayerData(playerid, "Job");
					}
				}
				else if(PlayerToPoint(1.0, playerid,DirJob[TakeJobX],DirJob[TakeJobY],DirJob[TakeJobZ]))
				{
					if(GetPlayerVirtualWorld(playerid) == DirJob[TakeJobWorld])
					{
						SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[SUKCES:] Jesteœ teraz re¿yserem filmowym, wpisz /komendypracy.");
						gPlayerData[playerid][pJob] = 12; //Director Job

						SavePlayerData(playerid, "Job");
					}
				}
				else if(PlayerToPoint(1.0, playerid,ProductsSellerJob[TakeJobX],ProductsSellerJob[TakeJobY],ProductsSellerJob[TakeJobZ]))
				{
					if(PHaveItemParam5Ex(playerid, 3, 6, gPlayerData[playerid][pName]) != -1)
					{
						SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[SUKCES:] Jesteœ teraz sprzedawc¹ produktów, wpisz /komendypracy.");
						gPlayerData[playerid][pJob] = 5; //Products Seller Job

						SavePlayerData(playerid, "Job");
					}
					else
					{
						SendClientMessage(playerid, COLOR_RED, "[INFO:] Do tej pracy wymagane jest prawo jazdy");
						return 1;
					}
				}
				else if(PlayerToPoint(1.0, playerid,BusJob[TakeJobX],BusJob[TakeJobY],BusJob[TakeJobZ]))
				{
					// NOTE: Brak prawa jazdy kat. D
					new slot = PHaveItem(playerid, 3, 6);
					if(slot == 0 || SlotParam3(playerid, slot) <= 0)
						SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] Prawo jazdy jest wymagane do tej pracy !");
					else
					{
						SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[SUKCES:] Jesteœ teraz kierowc¹ autobusu, wpisz /komendypracy.");
						gPlayerData[playerid][pJob] = 13; //Bus Driver
						SetProgressBarMaxValue(JobProgress[playerid], float(11 + (gPlayerData[playerid][pJobLvl]*5)));
						
						SavePlayerData(playerid, "Job");
					}
				}
				else if(PlayerToPoint(1.0, playerid,MzgkJob[TakeJobX],MzgkJob[TakeJobY],MzgkJob[TakeJobZ]))
				{
					if(GetPlayerVirtualWorld(playerid) == MzgkJob[TakeJobWorld])
					{
						new slot = PHaveItem(playerid, 3, 6);
						if(slot == 0 || SlotParam3(playerid, slot) <= 0)
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] Prawo jazdy jest wymagane do tej pracy !");
						else
						{
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[SUKCES:] Jesteœ teraz kierowc¹ œmieciarki wpisz /komendypracy.");
							gPlayerData[playerid][pJob] = 14; //Mzgk Driver
							SetProgressBarMaxValue(JobProgress[playerid], float(11 + (gPlayerData[playerid][pMzgkJobLvl]*5)));

							SavePlayerData(playerid, "Job");
						}
					}
				}
				else if(PlayerToPoint(1.0, playerid,SweeperJob[TakeJobX],SweeperJob[TakeJobY],SweeperJob[TakeJobZ]))
				{
					if(GetPlayerVirtualWorld(playerid) == SweeperJob[TakeJobWorld])
					{
						new slot = PHaveItemParam5Ex(playerid, 3, 5, gPlayerData[playerid][pName]);
						if(slot == -1)
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] Dowód jest wymagany do tej pracy !");
						else
						{
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[SUKCES:] Jesteœ teraz kierowc¹ myjki samochodowej, wpisz /komendypracy.");
							gPlayerData[playerid][pJob] = 15; //Sweeper Driver
							SetProgressBarMaxValue(JobProgress[playerid], float(11 + (gPlayerData[playerid][pSweeperJobLvl]*5)));
							
							SavePlayerData(playerid, "Job");
						}
					}
				}
				else if(PlayerToPoint(1.0, playerid,TaxiJob[TakeJobX],TaxiJob[TakeJobY],TaxiJob[TakeJobZ]))
				{
					if(GetPlayerVirtualWorld(playerid) == TaxiJob[TakeJobWorld])
					{
						new slot = PHaveItem(playerid, 3, 6);
						if(slot == 0 || SlotParam2(playerid, slot) <= 0)
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] Prawo jazdy jest wymagane do tej pracy !");
						else
						{
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[SUKCES:] Jesteœ teraz taksówkarzem, wpisz /komendypracy.");
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
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] Musisz mieæ co najmniej 1 poziom WFu i 1 poziom matematyki ¿eby zdobyæ t¹ prace");
						}
						else
						{
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[SUKCES:] Jesteœ teraz mechanikiem, wpisz /komendypracy.");
							gPlayerData[playerid][pJob] = 17; // Mechanik

							SavePlayerData(playerid, "Job");
						}
					// }
				}
				else if(PlayerToPoint(1.0, playerid,FarmerJob[TakeJobX],FarmerJob[TakeJobY],FarmerJob[TakeJobZ]))
				{
					if(GetPlayerVirtualWorld(playerid) == FarmerJob[TakeJobWorld])
					{
						SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[SUKCES:] Jesteœ teraz Farmerem, wpisz /komendypracy.");
						gPlayerData[playerid][pJob] = 18; //Farmer Driver
						SetProgressBarMaxValue(JobProgress[playerid], float(15 + (gPlayerData[playerid][pFarmerJobLvl]*5)));

						SavePlayerData(playerid, "Job");
					}
				}
				else if(PlayerToPoint(1.0, playerid,SellerJob[TakeJobX],SellerJob[TakeJobY],SellerJob[TakeJobZ]))
				{
					// if(GetPlayerVirtualWorld(playerid) == SellerJob[TakeJobWorld])
					// {
						SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[SUKCES:] Jesteœ teraz sprzedawc¹/ekspedientem, wpisz /komendypracy.");
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
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[SUKCES:] Jesteœ teraz ksiêgowym, wpisz /komendypracy.");
							gPlayerData[playerid][pJob] = 20; //Accountant

							SavePlayerData(playerid, "Job");
						}
					// }
				}
				else if(PlayerToPoint(1.0, playerid,NewsBoyJob[TakeJobX],NewsBoyJob[TakeJobY],NewsBoyJob[TakeJobZ]))
				{
					// if(GetPlayerVirtualWorld(playerid) == SellerJob[TakeJobWorld])
					// {
						format(string2, sizeof(string2), "Jesteœ teraz roznosicielem gazet\nKomendy :\n/wezprace /zrezygnujzpracy /komendypracy\n/pobierzgazety /rzucgazete\nGazety pobiera siê w punkcie poboru pracy roznosiciela gazet i wpisaniu komendy /pobierzgazety\n\n");
						strcat(string2, "Roznoszenie gazet odbywa sie poprzez podejscie pod dom i wpisaniu /rzucgazete\n\n Pobierasz 15 gazet\nNIE SPRINTUJ (NON RP)\nStawka : 4$/gazeta\n\nPowodzenia");
						ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", string2, "Zamknij", "");
						gPlayerData[playerid][pJob] = 21; //NewsBoy

						SavePlayerData(playerid, "Job");
					// }
				}
				else if(PlayerToPoint(1.0, playerid, WFWorkerJob[TakeJobX],WFWorkerJob[TakeJobY],WFWorkerJob[TakeJobZ]))
				{
					if(gPlayerData[playerid][pFaction] != 255)
					{
						if(DynamicFactions[ gPlayerData[playerid][pFaction] ][fType] == 3)
						{
							SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz posiadaæ tej pracy bêd¹c jednoczeœnie w gangu !");
							return 1;
						}
					}
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[SUKCES:] Jesteœ teraz pracownikiem fabryki broni, wpisz /komendypracy.");
					gPlayerData[playerid][pJob] = 22;
					SavePlayerData(playerid, "Job");
				}
				gPlayerData[playerid][pJobTimeChange] = 300;
				SavePlayerData(playerid, "JobTimeChange");
			}
			else
			{
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] Masz ju¿ prace !");
			}
			return 1;
		}
		else if(strcmp(cmd, "/zrezygnujzpracy", true) == 0)
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

					// SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] Zrezygnowa³eœ ze swojej pracy.");
				// }
				// else
				// {
					// format(string, sizeof(string), "[INFO:] Nie mo¿esz jeszcze zrezygnowaæ ze swoje pracy. Musisz przepracowaæ jeszcze %d pkt poziomu postaci", gPlayerData[playerid][pJobTimeChange]);
					// SendClientMessage(playerid,COLOR_RED, string);
				// }
			// }
			// else
			// {
				// SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] Nie masz aktualnie pracy !");
			// }
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Aby zwolniæ siê z pracy musisz udaæ siê do urzêdu w Twoim mieœcie");
			return 1;
		}
		else if(strcmp(cmd, "/komendypracy", true) == 0)
		{
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "/wezprace - /zrezygnujzpracy");
			if(gPlayerData[playerid][pJob] != 0)
			{
				if(gPlayerData[playerid][pJob] == 1)
				{			
					format(string2, sizeof(string2), "Gratulacje zosta³eœ dilerem broni\n Komendy :\n /wezprace /zrezygnujzpracy /komendypracy\n /menubroni /skladaj\n \n");
					strcat(string2, "Do pracy wymagany jest PLECAK. \n Pamiêtaj aby mieæ 6-7 slotów wolnych w /mi \n Fabrykê broni gangu znajdziesz tylko za informacja lidera gangu, jest ona œcis³e chroniona.\n ");
					strcat(string2, "W fabryce s¹ 3 rodzaje cheakpointow : \n - poboru czêœci za pomoc¹ /menubroni \n - sk³adania czêœci broni oraz broni za pomoc¹ /skladaj \n - sk³adania amunicji równie¿ cmd /skladaj \n ");
					strcat(string2, "Cheakpointy bez problemów znajdziesz w fabryce, rozejrzyj siê i poczytaj opisy danych cp\n ");
					strcat(string2, "Czas sk³adania : \n W zale¿noœci co siê sk³ada czas sk³adania bêdzie miedzy 10-30 sec za ka¿de z³o¿eniem czêœci, np 9mm sk³ada siê z 5 czêœci ka¿da po 20 sec, czyli 9mm z³o¿ymy po 100 sec. ");
					strcat(string2, "Zrobiona broñ nale¿y pobraæ w pkt poboru broni , ¿eby móc j¹ sprzedaæ !!! Sprzedaje sie za pomoc¹ rozmowy miedzy 2 graczami, przekazaniu pieniêdzy oraz przekazaniu towaru przez /mi ");
					strcat(string2, "Stawka : Brak\n\n Znalezione bugi prosimy zg³aszaæ na forum \n\n Powodzenia");
					ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", string2, "Zamknij", "");
				}
				else if(gPlayerData[playerid][pJob] == 2)
				{
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[ZAWÓD:] - [Diler narkotyków] - /narkotyki - /sprzedajnarkotyki");
				}
				else if(gPlayerData[playerid][pJob] == 3)
				{
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[ZAWÓD:] - [Detektyw] - /sledz - /sledzpojazd");
				}
				else if(gPlayerData[playerid][pJob] == 4)
				{
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[ZAWÓD:] - [Prawnik] - /uwolnij");
				}
				else if(gPlayerData[playerid][pJob] == 5)
				{
					format(string2, sizeof(string2), "Gratulacje zosta³eœ sprzedawc¹ produktów\n Komendy :\n /wezprace /zrezygnujzpracy /komendypracy\n \n \n");				
					strcat(string2, "Do pracy wymagany jest PLECAK, SAMOCHOD, ZNAJOMOŒÆ PRODUKTÓW i BIZNESÓW. \n Pamiêtaj aby mieæ 6-7 slotów wolnych w /mi oraz w samochodzie \n Polecane samochody : transportowe z max iloœci¹ slotów w baga¿niku\n ");					
					strcat(string2, "Zadaniem sprzedawcy jest dostarczenie produktów z hurtowni do biznesów. Hurtownie znajdziesz za pomoc¹ ikonki samochodu ciê¿arowego na mapie. Dostêpne s¹ 2 hurtownie, jedna w lv kolejna w flint country(zachodni wyjazd z ls)");					
					strcat(string2, "Doje¿d¿amy do hurtowni, szukamy produktu który nas interesuje w cp wokó³ hurtowni, kazdy cp posiada do 10 produktów w ró¿nej cenie oraz iloœci.\n ");
					strcat(string2, "Pobrany towar znajduje siê w baga¿niku. Aby go pobraæ nale¿y wpisaæ /otworzbaga¿nik nastêpnie /miwp ");					
					strcat(string2, "Nastêpnie udajemy siê do wnêtrza biznesu, wybieramy który produkt chcemy sprzedaæ poprzez /mi . Pokazuje nam siê informacja ile dostaniemy za produkt i ostatecznie albo siê zgadzamy albo nie.");
					strcat(string2, "Sprzedawaæ produkty mo¿emy równie¿ bezpoœrednio graczom, wystarczy pogadaæ z graczem, ustaliæ cenê i sprzedaæ");					
					strcat(string2, "Stawka : Ile sprzeda¿ tyle bêdziesz mia³\n\n Nie daj siê oszukaæ Zawsze szukaj sklepu w którym zyskasz. Nie sprzedawaj za darmo.\n\n Znalezione bugi prosimy zg³aszaæ na forum \n\n Powodzenia");
					ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", string2, "Zamknij", "");
				}
				else if(gPlayerData[playerid][pJob] == 6)
				{
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[ZAWÓD:] - [Dziwka] - Musisz poprostu uprawiaæ stosunek z innymi graczami /animlist");
				}
				else if(gPlayerData[playerid][pJob] == 7)
				{
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[ZAWÓD:] - [Boxer] - /walcz");
				}
				else if(gPlayerData[playerid][pJob] == 8)
				{
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[ZAWÓD:] - [Gwa³ciciel] - /gwalc");
				}
				else if(gPlayerData[playerid][pJob] == 9)
				{
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[ZAWÓD:] - [Ochroniarz] - /ochroniarz");
				}
				else if(gPlayerData[playerid][pJob] == 10)
				{
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[ZAWÓD:] - [Z³odziej samochodów] - /wlamsiedopojazdu");
				}
				else if(gPlayerData[playerid][pJob] == 11)
				{
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[ZAWÓD:] - [Kaskader] - /rozpocznijpokaz - /zakonczpokaz");
				}
				else if(gPlayerData[playerid][pJob] == 12)
				{
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[ZAWÓD:] - [Re¿yser] - Not a Quite interesting job =/ but...");
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[ZAWÓD:] - [Re¿yser] - Simply Start a Business and hire Filmers");
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[ZAWÓD:] - [Re¿yser] - and actors and Start Recording");
				}
				else if(gPlayerData[playerid][pJob] == 13)
				{
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[ZAWÓD:] - [Kierowca Autobusu] - Brak komend. Wsiadasz do autobusu i jedziesz linia autobusowa");
				}
				else if(gPlayerData[playerid][pJob] == 14)
				{
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[ZAWÓD:] - [Kierowca Smieciarki] - Brak komend. Wsiadasz do smieciarki i zaczynasz jechac do koszy na smieci");
				}
				else if(gPlayerData[playerid][pJob] == 15)
				{
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[ZAWÓD:] - [Kierowca Myjki samochodowej] - Brak komend. Wsiadasz do sweepera i zaczynasz czyscic ulice");
				}
				else if(gPlayerData[playerid][pJob] == 17)
				{					
					format(string2, sizeof(string2), "Gratulacje zosta³eœ mechanikiem samochodowym\n Komendy :\n /wezprace /zrezygnujzpracy /komendypracy\n /kupczesci - /naprawpojazd - /przemaluj - /stanpojazdu \n");				
					strcat(string2, "/wymianaopon - /czesci - /wymontujcb /wymienzarowke - /zamontujhak - /montazgazu - /zamontujalarm - /podladujakumulator - /zdemontuj  - /naprawstacyjke\n\n");					
					strcat(string2, "Jako mechanik masz za zadanie naprawiaæ/holowaæ pojazdy w przypadku gdy poprosi Ciê o to gracz. Punkty naprawy znajdziesz na mapce pod ikon¹ klucza ");			
					strcat(string2, "Sam ustalasz cenê naprawy pojazdu jednak musisz o niej powiadomiæ klienta jeszcze przez napraw¹.\n");
					strcat(string2, "Punkt skupu czêœci znajdziesz w Bayside, w pó³nocnym mieœcie. \n");
					strcat(string2, "Mechanicy posiadaj¹ 2-3 wspólne holowniki, dbaj o niego, naprawiaj, uzupe³niaj paliwo. Zniszczenie holownika grozi odpowiedzialnoœci¹ karna do 10 000$ oraz 1 dzieñ w wiêzieniu \n");
					strcat(string2, "Stawka : Zale¿y od negocjacji z klientami\n\n Znalezione bugi prosimy zg³aszac na forum \n\n Powodzenia");
					ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", string2, "Zamknij", "");
				}
				else if(gPlayerData[playerid][pJob] == 18)
				{
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[ZAWÓD:] - [Farmer] - Pamietaj o stosowaniu /ja oraz /do przy zsypie zbo¿a. Za nie przestrzeganie grozi kara");
				}
				else if(gPlayerData[playerid][pJob] == 19)
				{
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[ZAWÓD:] - [Sprzedawca/ekspedient] - Jak zacz¹æ prace ? - Udajesz siê do najbli¿szego biznesu. W jego wnêtrzu obs³ugujesz klientów");
				}
				else if(gPlayerData[playerid][pJob] == 20)
				{
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[ZAWÓD:] - [Ksiêgowy] /przedstawrozliczenie - pokazuje danej osobie jego wydatki oraz kwote odprowadzan¹ na podatki");
				}
				else if(gPlayerData[playerid][pJob] == 21)
				{
					format(string, sizeof(string), "Jesteœ teraz roznosicielem gazet\n Komendy :\n /wezprace /zrezygnujzpracy /komendypracy\n /pobierzgazety /rzucgazete\n Gazety pobiera siê w punkcie poboru pracy roznosiciela gazet i wpisaniu komendy /pobierzgazety\n\n");
					format(string, sizeof(string), "%sRoznoszenie gazet odbywa sie poprzez podejœcie pod dom i wpisaniu /rzucgazete\n\n Pobierasz 15 gazet\n NIE SPRINTUJ (NON RP)\n Stawka : %d$/gazeta\n\n Znalezione bugi prosimy zg³aszaæ na forum \n\nPowodzenia", string, NewsBoyJob[TakeJobReward]);
					ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", string, "Zamknij", "");
				}
				else if(gPlayerData[playerid][pJob] == 22)
				{
					format(string2, sizeof(string2), "Gratulacje zosta³eœ pracownikiem fabryki broni\n Komendy :\n /wezprace /zrezygnujzpracy /komendypracy\n /pobierzczesci /skladaj\n \n");
					strcat(string2, "Do pracy wymagany jest PLECAK. \n Pamiêtaj aby mieæ 6-7 slotów wolnych w /mi \n Fabrykê broni znajdziesz za pomoc¹ Mapy - ikonka broni.\n ");
					strcat(string2, "W fabryce s¹ 3 rodzaje cheakpointow : \n - poboru czêœci za pomoc¹ /pobierzczesci \n - sk³adania czêœci broni oraz broni za pomoca /skladaj \n - sk³adania amunicji równie¿ cmd /skladaj \n ");
					strcat(string2, "Checkpointy bez problemów znajdziesz w fabryce, rozejrzyj siê i poczytaj opisy danych cp\n"); 
					strcat(string2, "Czas sk³adania : \n W zale¿noœci co siê sk³ada czas sk³adania bêdzie miedzy 10-30 sec za ka¿de z³o¿enie czêœci, np 9mm sk³ada siê z 5 czêœci ka¿da po 20 sec, czyli 9mm z³o¿ymy po 100 sec. ");
					format(string2, sizeof(string2), "%sStawka : %d$/z³o¿enie ca³ej czêœci\n\n Znalezione bugi prosimy zg³aszaæ na forum \n\n Powodzenia ", string2, FACTORY_L_REWARD);
					ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", string2, "Zamknij", "");
				}
			}
			return 1;
		}
		else if(strcmp(cmd, "/rozpocznijpokaz", true) == 0)
		{
			if(gPlayerData[playerid][pJob] != 11)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ kaskaderem !");
				return 1;
			}
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "Rozpoczê³eœ pokazy!");
			EnableStuntBonusForPlayer(playerid, 1);
			return 1;
		}
		else if(strcmp(cmd, "/zakonczpokaz", true) == 0)
		{
			if(gPlayerData[playerid][pJob] != 11)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ kaskaderem !");
				return 1;
			}
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "Zakoñczy³eœ pokazy");
			EnableStuntBonusForPlayer(playerid, 0);
			return 1;
		}
		else if(strcmp(cmd, "/narkotyki",true)==0)
		{
			if(IsPlayerConnected(playerid))
			{
				if(gPlayerData[playerid][pJob] != 2)
				{
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] nie jesteœ dilerem narkotyków!");
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
				if(strcmp(x_nr, "kup",true) == 0)
				{
					if(PlayerToPoint(3.0,playerid,DrugJob[BuyDrugsX],DrugJob[BuyDrugsY],DrugJob[BuyDrugsZ]))
					{
						if(DrugsHolding[playerid] >= 50)
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz przenosiæ wiêcej paczek.");
							return 1;
						}
						tmp = strtok(cmdtext, idx);
						if(!strlen(tmp)) {
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /narkotyki [kup][iloœæ]");
							return 1;
						}
						new moneys;
						moneys = strval(tmp);
						if(moneys < 1 || moneys > 50) { SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Maksymalna iloœæ paczek to 50."); return 1; }
						new price = moneys * 100;
						if(GetPlayerCash(playerid) > price)
						{
							format(string, sizeof(string), "[INFO:] Kupi³eœ %d paczek - koszt: %d$.", moneys, price);

							SendClientMessage(playerid, COLOR_WHITE, string);
							SendClientMessage(playerid, COLOR_WHITE, "[INFO:] Musisz teraz dostarczyæ paczki.");

							// TODO: Cash goes nowhere, fix this
							GivePlayerCash(playerid, -price);
							SavePlayerData(playerid, "cash");

							DrugsHolding[playerid] = moneys;
						}
						else
						{
							format(string, sizeof(string), "[INFO:] Nie masz %d$.", price);
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ w miejscu skupu narkotyków!");
						return 1;
					}
				}
				else if(strcmp(x_nr, "zrzuc",true) == 0)
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
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie masz ¿adnych narkotyków !");
							return 1;
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie znajdujesz siê w punkcie zrzutu.");
						return 1;
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Niew³aœciwe u¿ycie.");
					return 1;
				}
			}
			return 1;
		}
		else if(strcmp(cmd, "/admini", true) == 0)
		{
			new count = 0;
			SendClientMessage(playerid, COLOR_LIGHTGREEN, "----------[ADMINISTRATORZY NA S£U¯BIE]----------");
			foreach(Player, i)
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
				SendClientMessage(playerid,COLOR_WHITE, "[INFO:] Brak administratorów na s³u¿bie.");
			}
			SendClientMessage(playerid, COLOR_LIGHTGREEN, "----------------------------------------------------------");
			return 1;
		}
		else if(strcmp(cmd, "/zasady", true) == 0)
		{
		SendClientMessage(playerid,COLOR_YELLOW, "______________________Zasady______________________");
		SendClientMessage(playerid, COLOR_GREY, "1.Na serwerze obowi¹zuj¹ podstawowe zasady kultury.");
		SendClientMessage(playerid, COLOR_GREY, "2.Podobnie jak na ka¿dym Role Play'u obowi¹zuje gra IC.");
		SendClientMessage(playerid, COLOR_GREY, "3.Proœby do administracji o podniesienie rangi OOC...");
		SendClientMessage(playerid, COLOR_GREY, "...do Supportera lub Administratora bêdzie skutecznie zwalczane.");
		SendClientMessage(playerid, COLOR_GREY, "4.U¿ywanie programów wspomagaj¹cych grê zawsze koñczy siê banem.");
		SendClientMessage(playerid, COLOR_GREY, "Aby zobaczyæ ci¹g dalszy u¿yj komendy /zasady2.");
		return 1;
		}
		else if(strcmp(cmd, "/zasady2", true) == 0)
		{
		SendClientMessage(playerid,COLOR_YELLOW, "______________________Zasady______________________");
		SendClientMessage(playerid, COLOR_GREY, "5.Proszenie innych graczy o datki materialne jest zabronione.");
		SendClientMessage(playerid, COLOR_GREY, "6.Rozdawanie pieniêdzy (Feedowanie) jest zabronione.");
		SendClientMessage(playerid, COLOR_GREY, "7.U¿ywanie wszelkich noobowskich s³ów jak na przyk³ad...");
		SendClientMessage(playerid, COLOR_GREY, "...¿al, lol, wtf zarówno na czacie IC jak i OOC jest zakazane.");
		SendClientMessage(playerid, COLOR_GREY, "8.Reklamowanie innych serwerów jest ca³kowicie zakazane.");
		SendClientMessage(playerid, COLOR_GREY, "Aby zobaczyæ ci¹g dalszy u¿yj komendy /zasady3.");
		return 1;
		}
		else if(strcmp(cmd, "/zasady3", true) == 0)
		{
		SendClientMessage(playerid,COLOR_YELLOW, "______________________Zasady______________________");
		SendClientMessage(playerid, COLOR_GREY, "9.Zabranie siê u¿ywania samochodu do zabijania graczy (CK2).");
		SendClientMessage(playerid, COLOR_GREY, "10.Banem zakoñczyæ mo¿e siê zabijanie ludzi bez powodu.");
		SendClientMessage(playerid, COLOR_GREY, "11.Drive By czyli strzelanie z okna samochodu jest zakazane.");
		SendClientMessage(playerid, COLOR_GREY, "12.Zabijanie osób za pomoc¹ helikopterów jest zakazane.");
		SendClientMessage(playerid, COLOR_GREY, "13.Nick gracza musi byæ IC czyli Imiê_Nazwisko.");
		SendClientMessage(playerid, COLOR_GREY, "Aby zobaczyæ ostatni¹ czêœæ u¿yj komendy /zasady4.");
		}
		else if(strcmp(cmd, "/zasady4", true) == 0)
		{
		SendClientMessage(playerid,COLOR_YELLOW, "______________________Zasady______________________");
		SendClientMessage(playerid, COLOR_GREY, "Na zakoñczenie chcielibyœmy ¿yczyæ Ci mi³ej rozgrywki...");
		SendClientMessage(playerid, COLOR_GREY, "...na WParty i abyœ d³ugo zosta³ w naszej spo³ecznoœci.");
		SendClientMessage(playerid, COLOR_GREY, "Pamiêtaj równie¿ ¿e gdy bêdziesz stosowa³ siê do...");
		SendClientMessage(playerid, COLOR_GREY, "...powy¿szych zasad zostaniesz doceniony przez innych...");
		SendClientMessage(playerid, COLOR_GREY, "...i rozgrywka stanie siê bardziej przyjemna.");
		SendClientMessage(playerid, COLOR_GREY, "Mi³ej gry na WParty ¿yczy Administracja !");
		}
		else if(strcmp(cmd, "/kody", true) == 0)
		{
			SendClientMessage(playerid,COLOR_YELLOW, "______________________Kody policyjne______________________");
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "10-4 = Wiadomoœæ odebrana");
			SendClientMessage(playerid,COLOR_LIGHTORANGE, "10-8 = Potrzebne wsparcie (LOKACJA)");
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "10-10 = W zatrzymaniu");
			SendClientMessage(playerid,COLOR_LIGHTORANGE, "10-22 = Funkcjonariusz w poœcigu");
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "10-30 = Œledzony przez podejrzany wóz (LOKACJA)");
			SendClientMessage(playerid,COLOR_LIGHTORANGE, "10-40 = Funkcjonariusz jest œcigany (LOKACJA)");
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "10-44 = Podejrzany aresztowany");
			SendClientMessage(playerid,COLOR_LIGHTORANGE, "10-66 = Funkcjonariusz na s³u¿bie");
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "22-10 = Potrzebne wszystkie jednostki (LOKACJA)");
			return 1;
		}
		else if(strcmp(cmd, "/pomoc", true, 10) == 0)
		{
			ShowPlayerDialog(playerid, DIALOG_HELP, DIALOG_STYLE_LIST, "Pomoc", DIALOG_HELP_MAIN_TXT, "Wybierz", "WyjdŸ");
			return 1;
		}
		else if(strcmp(cmd, "/czolowka", true) == 0)
		{
			SendClientMessage(playerid,COLOR_LIGHTBLUE, "WlanParty RP Server");
			SendClientMessage(playerid,COLOR_LIGHTBLUE, "Xtreme - skrypter, head admin");
			SendClientMessage(playerid,COLOR_LIGHTBLUE, "Xamxe - support, skrypter, second admin");
			return 1;
		}
		else if(strcmp(cmd, "/prawko", true) == 0)
		{
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "Prawo jazdy zdaje siê w Mongomery. Na mapce literka S. Zdawaæ mo¿na jedynie pod obecnoœci¹ EGZAMINATORA. ");
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "Egzamin sk³ada siê z 2 czêœci : teoretycznej i praktycznej. Teoria sk³ada siê z kilku pytañ, natomiast praktyczny z trzech czêœci : obs³uga samochodu, plac manewrowy, miasto.");
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "Aby zaliczyæ egzamin nale¿y powy¿sze warunki spe³niæ na dana kategorie");
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "Wiecej informacji o Word znajdziecie na forum WParty.pl");

			return 1;
		}
		else if(strcmp(cmd, "/notatki", true) == 0)
		{
			if(IsPlayerConnected(playerid))
			{
				SendClientMessage(playerid, COLOR_GREEN, "_______________________________________");
				SendClientMessage(playerid, COLOR_GRAD3, "*** NOTKI *** /pokaznotki /usunnotke /zrobnotke /przekaznotke");
			}
			return 1;
		}
		else if(strcmp(cmd, "/wyscig", true) == 0)
		{
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "/dolaczdowyscigu - /rozpocznijwyscig - /zrezygnujzwyscigu - /komendyorganizatora");
			return 1;
		}
		else if(strcmp(cmd, "/czaty", true) == 0)
		{
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "/b - /o(oc) - /pw - (/k)rzycz - (/s)zepcz - /ja - /do - /kanalooc");
			return 1;
		}
		else if(strcmp(cmd, "/komendybanku", true) == 0)
		{
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "/stankonta - /wyplac - /wplac - /wyrobkarte - /wezkredyt - /stankredytu - /splackredyt");
			return 1;
		}
		else if(strcmp(cmd, "/komendygarazu", true) == 0)
		{
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "/wjedzdogarazu - /wyjedzzgarazu - /otworzgaraz - /zamknijgaraz");
			return 1;
		}
		else if(strcmp(cmd, "/komendy", true) == 0 || strcmp(cmd, "/cmds", true) == 0)
		{
			SendClientMessage(playerid,COLOR_YELLOW, "____________________________________________________");
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "/pomoc - /zglosproblem - /statystyki - /osiagniecia - /mojeitemy(/mi) - /opis - /komendypracy - /komendybanku - /komendypojazdow");
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "/komendydomu - /komendybiznesu - /komendygarazu - /czaty - /animacje(2) - /panelgracza - /admini - /kupdrink - /proba");
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "/donos - /wyrzucgracza - /glosujza - /kostka - /ogloszenie - /notatki - /obiekty - /zdejmijpancerz");
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "/czolowka");
			
			if(gPlayerData[playerid][pFaction] != 255)
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "/komendypolicji - /komendylidera - /komendyfrakcji");

			if(gPlayerData[playerid][pAdmin] > 0)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "/apomoc[1/2]");
			}
			
			SendClientMessage(playerid,COLOR_YELLOW, "____________________________________________________");
			return 1;
		}
		else if(strcmp(cmd, "/odbierz", true) == 0 || strcmp(cmd, "/odb", true) == 0)
		{
			if(Mobile[playerid] != 255)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Jesteœ ju¿ po³¹czony ! (/rozlacz).");
				return 1;
			}
			if(gPlayerData[playerid][pCharacterDying] != 0)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Twoja postaæ jest nieprzytomna nie mo¿esz odebraæ telefonu !");
				return 1;
			}
			foreach(Player, i)
			{
				if(!gPlayerLogged[i])
					continue;
				if(Mobile[i] == playerid)
				{
					Mobile[playerid] = i;
					IncommingCall[playerid] = 0;
					gPhoneCallShowed[playerid] = 0;

					SendClientMessage(i, COLOR_LIGHTBLUE, "[INFO:] Gracz odebra³ telefon.");

					if(!IsPlayerInAnyVehicle(playerid))
					{
						SetPlayerSpecialAction(playerid,SPECIAL_ACTION_USECELLPHONE);
						SetPlayerAttachedObject(playerid, 1, 330, 6);
					}
					return 1;
				}
			}
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nikt do ciebie nie dzwoni");
			return 1;
		}
		else if(strcmp(cmd, "/rozlacz", true) == 0)
		{
			if(!DisconnectPhone(playerid))
				SendClientMessage(playerid,  COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ po³aczony !");
			else
			{
				SendClientMessage(playerid,  COLOR_LIGHTYELLOW2, "[INFO:] Roz³¹czy³eœ siê");
				SendClientMessage(Mobile[playerid],  COLOR_LIGHTYELLOW2, "[TELEFON:] Roz³¹czy³ siê");
			}
			return 1;
		}
		else if(strcmp(cmd, "/kup",true)==0)
		{
			new x_info[256];
			new wstring[128];
			new slot;
			for(new i = 0; i < sizeof(Businesses); i++)
			{
				if(PlayerToPoint(25.0, playerid,Businesses[i][ExitX], Businesses[i][ExitY], Businesses[i][ExitZ]))
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
							if(strcmp(x_info, "baton",true) == 0)
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
									SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie masz wystarczaj¹cej iloœci pieniêdzy !");
								}
							}
						}
						if(Businesses[i][BizType] == 3) //24-7
						{
							SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Aby kupiæ coœ w sklepie wejdŸ w czerwone kólko obok kasy");
							return 1;
						}
					}
				}
			}
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Musisz znajdowaæ siê w sklepie aby u¿yæ tej komendy !");
			return 1;
		}
		else if(strcmp(cmd, "/kupdrink",true)==0)
		{
			new x_info[256];
			new Float:HP;
			for(new i = 0; i < sizeof(Businesses); i++)
			{
				if(PlayerToPoint(200.0, playerid,Businesses[i][ExitX], Businesses[i][ExitY], Businesses[i][ExitZ]))
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
								if(strcmp(x_info, "piwo",true) == 0)
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
										SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie masz wystarczaj¹cej iloœci pieniêdzy.");
										return 1;
									}
								}
								if(strcmp(x_info, "vodka",true) == 0)
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
										SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie masz wystarczaj¹cej iloœci pieniêdzy.");
										return 1;
									}
								}
								if(strcmp(x_info, "cola",true) == 0)
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
										SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie masz wystarczaj¹cej iloœci pieniêdzy.");
										return 1;
									}
								}
								if(strcmp(x_info, "woda",true) == 0)
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
										SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie masz wystarczaj¹cej iloœci pieniêdzy.");
										return 1;
									}
								}
								if(strcmp(x_info, "whiskey",true) == 0)
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
										SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie masz wystarczaj¹cej iloœci pieniêdzy.");
										return 1;
									}
								}
								if(strcmp(x_info, "brandy",true) == 0)
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
										SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie masz wystarczaj¹cej iloœci pieniêdzy.");
										return 1;
									}
								}
								if(strcmp(x_info, "soda",true) == 0)
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
										SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie masz wystarczaj¹cej iloœci pieniêdzy.");
										return 1;
									}
								}
							}
							else
							{
								SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Niestety nie posiadamy ju¿ drinków !");
								return 1;
							}
						}
					}
				}
			}
			return 1;
		}
		else if(strcmp(cmd, "/jedz", true) == 0)
		{
			for(new i = 0; i < sizeof(Businesses); i++)
			{
				if(PlayerToPoint(25.0, playerid,Businesses[i][ExitX], Businesses[i][ExitY], Businesses[i][ExitZ]))
				{
					if(GetPlayerVirtualWorld(playerid) == i)
					{
						if(Businesses[i][BizType] == 1)
						{
							// TODO: make this working :) 
						}
					}
				}	
			}
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Aby coœ zjeœæ musisz udaæ siê do jednej z restauracja/pubu");
			return 1;
		}
		else if(strcmp(cmd, "/fweznarkotyki", true) == 0)
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
						if(PlayerToPoint(1.0, playerid,FactionDrugsStorage[X],FactionDrugsStorage[Y],FactionDrugsStorage[Z]))
						{
							if(DynamicFactions[bouse][fDrugs] >= materialsdeposit)
							{
								gPlayerData[playerid][pDrugs] += materialsdeposit;
								DynamicFactions[bouse][fDrugs]=DynamicFactions[bouse][fDrugs]-materialsdeposit;
								format(string, sizeof(string), "[INFO:] Wzi¹³eœ %d narkotyków z magazynu, nowa iloœæ: %d ", materialsdeposit,DynamicFactions[bouse][fDrugs]);
								SendClientMessage(playerid, COLOR_WHITE, string);
								PlayerActionMessage(playerid,15.0, "zabra³ narkotyki z magazynu");
								format(string, sizeof(string), "[FRAKCJA:] %s wzi¹³ %d wzi¹³ narkotyki z magazynu.",GetPlayerNameEx(playerid),materialsdeposit);
								SendFactionMessage(gPlayerData[playerid][pFaction], COLOR_FACTIONCHAT, string);
								SaveFData(bouse, "Drugs");
								return 1;
							}
							else
							{
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie ma tylu narkotyków w magazynie !");
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ w magazynie frakcji !");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ liderem frakcji !");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie nale¿ysz do frakcji !");
				}
			}
			return 1;
		}
		else if(strcmp(cmd, "/fodloznarkotyki", true) == 0)
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
					if(PlayerToPoint(1.0, playerid,FactionDrugsStorage[X],FactionDrugsStorage[Y],FactionDrugsStorage[Z]))
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
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie posiadasz tylu narkotyków !");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ w magazynie frakcji!");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Niew³aœciwa frakcja.");
				}
			}
			return 1;
		}
		else if(strcmp(cmd, "/fwezmaterialy", true) == 0)
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
						if(PlayerToPoint(1.0, playerid,FactionMaterialsStorage[X],FactionMaterialsStorage[Y],FactionMaterialsStorage[Z]))
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
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie ma tyle materia³ów w magazynie !");
							}
						}
						else
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ w magazynie frakcji !");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ liderem frakcji !");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie nale¿ysz do frakcji !");
				}
			}
			return 1;
		}
		else if(strcmp(cmd, "/fodlozmaterialy", true) == 0)
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
					if(PlayerToPoint(1.0, playerid,FactionMaterialsStorage[X],FactionMaterialsStorage[Y],FactionMaterialsStorage[Z]))
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
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie masz tyle materia³ów !");
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ w magazynie frakcji !");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Niew³aœciwa frakcja.");
				}
			}
			return 1;
		}
		else if(strcmp(cmd, "/sprzedajdom", true) == 0)
		{
			new slot;
			for(new i = 0; i < sizeof(Houses); i++)
			{
				if(!PlayerToPoint(3.0, playerid,Houses[i][EnterX], Houses[i][EnterY], Houses[i][EnterZ]))
					continue;			
				if(strcmp(gPlayerData[playerid][pName], Houses[i][Owner], false) != 0)
				{
					SendClientMessage(playerid, COLOR_RED, "[INFO:] Ten dom nie jest twoj¹ w³asnoœci¹, nie mo¿esz go sprzedaæ !");
					return 1;
				}
				
				ResetHouseData(i, 1);
				
				GivePlayerCash(playerid,Houses[i][HousePrice]);

				PlayerPlaySound(playerid, 1052, 0.0, 0.0, 0.0);

				format(string, sizeof(string), "[INFO:] Sprzeda³eœ dom za %d$", Houses[i][HousePrice]);
				SendClientMessage(playerid, COLOR_LIGHTBLUE, string);

				Houses[i][PickupID] = ChangePickupModel(Houses[i][PickupID], 1273, Houses[i][EnterX], Houses[i][EnterY], Houses[i][EnterZ]);

				new houselocation[MAX_ZONE_NAME];
				GetCoords2DZone(Houses[i][EnterX],Houses[i][EnterY], houselocation, MAX_ZONE_NAME);

				format(string, sizeof(string), "Ten dom jest na sprzeda¿!");
				UpdateDynamic3DTextLabelText(Houses3DTextLabelA[i], COLOR_LIGHTYELLOW2, string);

				format(string, sizeof(string), "Adres: %d %s",i,houselocation);
				UpdateDynamic3DTextLabelText(Houses3DTextLabelB[i], COLOR_LIGHTYELLOW2, string);

				format(string, sizeof(string), "Opis: %s, Cena: %d$",Houses[i][Description],Houses[i][HousePrice]);
				UpdateDynamic3DTextLabelText(Houses3DTextLabelC[i], COLOR_LIGHTYELLOW2, string);

				format(string, sizeof(string), "[GOVERNMENT:] House id: %d, sold for: %d$, by %s", i, Houses[i][HousePrice], GetPlayerNameEx(playerid));
				GovermentLog(string);

				RemovePlayerItemExUsed(playerid, slot);

				return 1;
			}
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Musisz byæ przed wejœciem do domu aby go sprzedaæ !");
			return 1;
		}
		else if(strcmp(cmd, "/otworzdom", true) == 0 || strcmp(cmd, "/otworzgaraz") == 0)
		{
			for(new i = 0; i < sizeof(Houses); i++)
			{
				if(PlayerToPoint(1.0, playerid,Houses[i][EnterX], Houses[i][EnterY], Houses[i][EnterZ]) && GetPlayerVirtualWorld(playerid) == 0 || (PlayerToPoint(3.0, playerid,Houses[i][ExitX], Houses[i][ExitY], Houses[i][ExitZ]) && GetPlayerVirtualWorld(playerid) == i))
				{
					if(PHaveItemParam1Ex(playerid, 2, -1, Houses[i][HUID]) || PHaveItemParam1Ex(playerid, 4, -1, Houses[i][HUID]) || PHaveItemParam1Ex(playerid, 10, -1, Houses[i][HUID]) ||
						PHaveItemParam1Ex(playerid, 11, -1, Houses[i][HUID]))
					{
						if(Houses[i][Locked] == 1)
						{
							Houses[i][Locked] = 0;
							if(Houses[i][HouseType] == 0)
							{
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Drzwi otwarte.");
								PlayerActionMessage(playerid, 20.0, "wyjmuje klucz i wk³ada go do drzwi, przekrêca raz a nastêpnie go wyjmuje");
							}
							else
							{
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Gara¿ otwarty.");
								PlayerActionMessage(playerid, 20.0, "wciska pilot od drzwi gara¿owych");
							}

							SaveHouseData(i, "Locked");

							return 1;
						}
						if(Houses[i][Locked] == 0)
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Gara¿ jest ju¿ otwarty !");
							PlayerActionMessage(playerid, 20.0, "wciska pilot od drzwi gara¿owych");

							return 1;
						}
					}
					else
					{
						if(Houses[i][HouseType] == 0)
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie posiadasz kluczy do tego domu lub nie pasuj¹ one do tego zamka !");
						else
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie posiadasz kluczy do tego gara¿u lub nie pasuj¹ one do tego zamka !");
						PlayerActionMessage(playerid, 20.0, "przeszukuje kieszenie");

						return 1;
					}
				}
			}
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ ko³o drzwi !");
			PlayerActionMessage(playerid, 20.0, "rozgl¹da siê");
			return 1;
		}
		else if(strcmp(cmd, "/zamknijdom", true) == 0 || strcmp(cmd, "/zamknijgaraz") == 0)
		{
			for(new i = 0; i < sizeof(Houses); i++)
			{
				if(PlayerToPoint(1.0, playerid,Houses[i][EnterX], Houses[i][EnterY], Houses[i][EnterZ]) && GetPlayerVirtualWorld(playerid) == 0 || (PlayerToPoint(3.0, playerid,Houses[i][ExitX], Houses[i][ExitY], Houses[i][ExitZ]) && i == GetPlayerVirtualWorld(playerid)))
				{
					if(PHaveItemParam1Ex(playerid, 2, -1, Houses[i][HUID]) || PHaveItemParam1Ex(playerid, 4, -1, Houses[i][HUID]) || PHaveItemParam1Ex(playerid, 10, -1, Houses[i][HUID]) ||
						PHaveItemParam1Ex(playerid, 11, -1, Houses[i][HUID]))
					{
						if(Houses[i][Locked] == 1)
						{
							if(Houses[i][HouseType] == 0)
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
							
							if(Houses[i][HouseType] == 0)
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
						if(Houses[i][HouseType] == 0)
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie posiadasz kluczy do tego domu lub nie pasuj¹ one do tego zamka !");
						else
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie posiadasz kluczy do tego gara¿u lub nie pasuj¹ one do tego zamka !");
						PlayerActionMessage(playerid, 20.0, "przeszukuje kieszenie");

						return 1;
					}
				}
			}
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ ko³o drzwi !");
			PlayerActionMessage(playerid, 20.0, "rozgl¹da siê");
			return 1;
		}
		else if(strcmp(cmd, "/otworzbiznes", true) == 0)
		{
			for(new i = 0; i < sizeof(Businesses); i++)
			{
				if(PlayerToPoint(3.0, playerid,Businesses[i][EnterX], Businesses[i][EnterY], Businesses[i][EnterZ]) && GetPlayerVirtualWorld(playerid) == 0 || PlayerToPoint(3.0, playerid,Businesses[i][ExitX], Businesses[i][ExitY], Businesses[i][ExitZ]) && GetPlayerVirtualWorld(playerid) == i)
				{
					if(PHaveItemParam1Ex(playerid, 2, -1, Businesses[i][BUID]) || PHaveItemParam1Ex(playerid, 4, -1, Businesses[i][BUID]) || PHaveItemParam1Ex(playerid, 10, -1, Businesses[i][BUID]) ||
						PHaveItemParam1Ex(playerid, 11, -1, Businesses[i][BUID]))
					{
						if(Businesses[i][Locked] == 1)
						{
							Businesses[i][Locked] = 0;

							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Drzwi otwarte.");
							PlayerActionMessage(playerid, 20.0, "wyjmuje klucz i wk³ada go do drzwi, przekrêca raz a nastêpnie go wyjmuje");

							SaveBizData(i, "Locked");

							return 1;
						}
						if(Businesses[i][Locked] == 0)
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Drzwi s¹ ju¿ otwarte !");
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
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie posiadasz kluczy do tego biznesu lub nie pasuj¹ one do tego zamka !");
						PlayerActionMessage(playerid, 20.0, "przeszukuje kieszenie");
						return 1;
					}
				}
			}
			return 1;
		}
		else if(strcmp(cmd, "/zamknijbiznes", true) == 0)
		{
			for(new i = 0; i < sizeof(Businesses); i++)
			{
				if(PlayerToPoint(3.0, playerid,Businesses[i][EnterX], Businesses[i][EnterY], Businesses[i][EnterZ]) && GetPlayerVirtualWorld(playerid) == 0 || (PlayerToPoint(3.0, playerid,Businesses[i][ExitX], Businesses[i][ExitY], Businesses[i][ExitZ]) && i == GetPlayerVirtualWorld(playerid)))
				{
					if(PHaveItemParam1Ex(playerid, 2, -1, Businesses[i][BUID]) || PHaveItemParam1Ex(playerid, 4, -1, Businesses[i][BUID]) || PHaveItemParam1Ex(playerid, 10, -1, Businesses[i][BUID]) ||
						PHaveItemParam1Ex(playerid, 11, -1, Businesses[i][BUID]))
					{
						if(Businesses[i][Locked] == 1)
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Drzwi s¹ ju¿ zamkniête !");
							PlayerActionMessage(playerid, 20.0, "wyjmuje klucz i wk³ada go do drzwi, próbuje przekrêciæ nastêpnie go wyjmuje");

							return 1;
						}
						if(Businesses[i][Locked] == 0)
						{
							Businesses[i][Locked] = 1;

							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Drzwi zamkniête");
							PlayerActionMessage(playerid, 20.0, "wyjmuje klucz i wk³ada go do drzwi, przekrêca raz a nastêpnie go wyjmuje");

							SaveHouseData(i, "Locked");

							return 1;
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie posiadasz kluczy do tego biznesu lub nie pasuj¹ one do tego zamka !");
						PlayerActionMessage(playerid, 20.0, "przeszukuje kieszenie");

						return 1;
					}
				}
			}
			return 1;
		}
		else if(strcmp(cmd, "/wynajmijdom", true) == 0)
		{
			for(new h = 0; h < sizeof(Houses); h++)
			{
				if(!PlayerToPoint(1.0, playerid, Houses[h][EnterX], Houses[h][EnterY], Houses[h][EnterZ]))
					continue;
				if(!Houses[h][Owned])
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ten dom nie zosta³ kupiony i nie mo¿e zostaæ wynajêty");
					return 1;
				}
				if(!Houses[h][Rentable])
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ten dom nie jest przeznaczony na wynajem");
					return 1;
				}
				if(strcmp(gPlayerData[playerid][pName], Houses[h][Owner], false) == 0)
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz wynajmowaæ w³asnego domu !");
					return 1;
				}
				if(strcmp(Houses[h][HRenter], "Brak", true) != 0 && strcmp(Houses[h][HRenter], "None", true) != 0)
				{
					SendClientMessage(playerid, COLOR_RED, "[INFO:] Ten dom jest ju¿ przez kogoœ wynajmowany !");
					return 1;
				}
				if(!PlayerFreeSlotCount(playerid))
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie masz miejsca na klucze !");
					return 1;
				}
				if(PHaveItemParam1Ex(playerid, 4, h, Houses[h][HUID]))
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Posiadasz ju¿ klucze do tego domu");
					return 1;
				}
				InsertPlayerItem(playerid, 4, h, Houses[h][HUID], 1);
				strmid(Houses[h][HRenter], gPlayerData[playerid][pName], 0, MAX_PLAYER_NAME, 255);
				SaveHouseData(h, "Renter");
				SendClientMessage(playerid, COLOR_GREEN, "[INFO:] Dom zosta³ wynajêty, op³ata bêdzie pobierana rano ka¿dego dnia nastêpnego");
				SendClientMessage(playerid, COLOR_GREEN, "[INFO:] Jeœli chcesz zrezygnowaæ z wynajmu tego domu wpisz /zrezygnujzwynajmu");
				return 1;
			}
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Musisz znajdowaæ siê przed drzwiami do domu aby móc go wynaj¹æ !");
			return 1;
		}
		else if(strcmp(cmd, "/zrezygnujzwynajmu", true) == 0)
		{
			new slot;
			for(new h = 0; h < sizeof(Houses); h++)
			{
				if(!PlayerToPoint(1.0, playerid, Houses[h][EnterX], Houses[h][EnterY], Houses[h][EnterZ]))
					continue;
				if(!Houses[h][Owned])
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ten dom nie zosta³ kupiony i nie mo¿e zostaæ wynajêty");
					return 1;
				}
				if(strcmp(gPlayerData[playerid][pName], Houses[h][HRenter], false) != 0)
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie wynajmujesz tego domu !");
					return 1;
				}
				if(!PHaveItemParam1Ex(playerid, 4, -1, Houses[h][HUID]))
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Aby zrezygnowaæ z wynajmu musisz posiadaæ przy sobie klucz do tego domu");
					return 1;
				}
				slot = PHaveItemParam2Ex(playerid, 4, -1, 1);
				if(!slot)
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Aby zrezygnowaæ z wynajmu musisz posiadaæ przy sobie klucz do tego domu");
					return 1;
				}
				RemovePlayerItemExUsed(playerid, slot);
				strdel(Houses[h][HRenter], 0, MAX_PLAYER_NAME);
				format(Houses[h][HRenter], MAX_PLAYER_NAME, "Brak", 255);
				SaveHouseData(h, "Renter");
				
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Zrezygnowa³eœ z wynajmu tego domu");
				return 1;
			}
		}
		else if(strcmp(cmd, "/czynsz", true) == 0)
		{
			for(new i = 0; i < sizeof(Houses); i++)
			{
				if(!PlayerToPoint(100.0, playerid,Houses[i][ExitX], Houses[i][ExitY], Houses[i][ExitZ]) || i != GetPlayerVirtualWorld(playerid))
					continue;
				if(strcmp(gPlayerData[playerid][pName], Houses[i][Owner], false) == 0)
				{
					tmp = strtok(cmdtext, idx);
					if(!strlen(tmp))
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /czynsz [kwota]");
						return 1;
					}
					if(strval(tmp) < 1 || strval(tmp) > 999)
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Wpisz kwote miêdzy 1-999 $");
						return 1;
					}
					Houses[i][RentCost] = strval(tmp);
					SaveHouseData(i, "RentCost");
					
					new houselocation[MAX_ZONE_NAME];
					GetCoords2DZone(Houses[i][EnterX], Houses[i][EnterY], houselocation, MAX_ZONE_NAME);

					format(string, sizeof(string), "Opis: %s Czynsz: %d$ (/wynajmijdom)", Houses[i][Description], Houses[i][RentCost]);
					UpdateDynamic3DTextLabelText(Houses3DTextLabelC[i], COLOR_LIGHTYELLOW2, string);					
					
					format(string, sizeof(string), "[INFO:] Ustawi³eœ cene wynajmu na: %d$", Houses[i][RentCost]);
					SendClientMessage(playerid, COLOR_LIGHTBLUE, string);
					return 1;
				}
			}
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Musisz byæ w domu by zarz¹dzaæ jego wynajmem");

			return 1;
		}
		else if(strcmp(cmd, "/zmienczynsz", true) == 0)
		{
			for(new i = 0; i < sizeof(Houses); i++)
			{
				if(!PlayerToPoint(100.0, playerid,Houses[i][ExitX], Houses[i][ExitY], Houses[i][ExitZ]) || i != GetPlayerVirtualWorld(playerid))
					continue;
				if(strcmp(gPlayerData[playerid][pName], Houses[i][Owner], false) != 0)
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w³aœcicielem tego domu");
					return 1;
				}
				if(!Houses[i][Rentable])
				{
					Houses[i][Rentable] = 1;
					SaveHouseData(i, "Rentable");
					
					format(string, sizeof(string), "Opis: %s Czynsz: %d$ (/wynajmijdom)", Houses[i][Description], Houses[i][RentCost]);
					UpdateDynamic3DTextLabelText(Houses3DTextLabelC[i], COLOR_LIGHTYELLOW2, string);	
					
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Wynajem uaktywniony");
				}
				else
				{
					Houses[i][Rentable] = 0;
					SaveHouseData(i, "Rentable");
					
					format(string, sizeof(string), "Opis: %s", Houses[i][Description]);
					UpdateDynamic3DTextLabelText(Houses3DTextLabelC[i], COLOR_LIGHTYELLOW2, string);
					
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Wynajem dezaktywowany");
				}
				return 1;
			}
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Musisz byæ w domu by zarz¹dzaæ jego wynajmem");
			return 1;
		}
		else if(strcmp(cmd, "/kupdom", true) == 0)
		{
			new houselocation[MAX_ZONE_NAME];
			if(gPlayerData[playerid][pIsDeptor])
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
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie ma ustalonej kwoty za ten dom, prawodpodobnie nie jest na sprzeda¿.");
						return 1;
					}
					if(!PlayerFreeSlotCount(playerid))
					{
						SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Przed kupnem domu zwolnij miejsce na kluczyki");
						return 1;
					}
					if(GetPlayerCash(playerid) > Houses[h][HousePrice])
					{
						Houses[h][HUID] = random(99999);
						if(InsertPlayerItem(playerid, 4, h, Houses[h][HUID], 0) == 0)
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie masz miejsca na kluczyki, nie mo¿esz kupiæ domu !");
							return 1;
						}
						if(!gPlayerData[playerid][pFirstHouse])
						{
							gPlayerData[playerid][pFirstHouse] = 1;
							SavePlayerData(playerid, "FirstHouse");
							// AddExpPoint(playerid);
							SendClientMessage(playerid, COLOR_GREEN, "[INFO:] Kupi³eœ swój pierwszy dom !");
						}
						Houses[h][Owned] = 1;
						strmid(Houses[h][Owner], gPlayerData[playerid][pName], 0, MAX_PLAYER_NAME, 255);
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
						
						TogglePlayerControllable(playerid, 0);
						defer UnfreezePlayer(playerid);
						
						DestroyDynamicPickup(Houses[h][PickupID]);
						Houses[h][PickupID] = CreateDynamicPickup(1239, 1, Houses[h][EnterX],Houses[h][EnterY],Houses[h][EnterZ]);
						
						Houses[h][Rentable] = 0;
						Houses[h][RentCost] = 0;
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
						// format(string, sizeof(string), "Wlasciciel: %s",Houses[h][Owner]);
						format(string, sizeof(string), " ",Houses[h][Owner]);
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
						SaveHouseData(h, "UID");
						
						format(string, sizeof(string), "[GOVERNMENT:] House %d bought by %s for %d", h, gPlayerData[playerid][pName], Houses[h][HousePrice]);
						GovermentLog(string);
						
						return 1;
					}
					else
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie masz wystarczaj¹co du¿o pieniêdzy !");
						return 1;
					}
				}
			}
			return 1;
		}
		else if(strcmp(cmd, "/wejsciowka", true) == 0)
		{
			for(new i = 0; i < sizeof(Businesses); i++)
			{
				if(!PlayerToPoint(5.0, playerid, Businesses[i][EnterX], Businesses[i][EnterY], Businesses[i][EnterZ]))
					continue;
				if(strcmp(gPlayerData[playerid][pName], Businesses[i][Owner], false) != 0 && (!Businesses[i][BGov] || gPlayerData[playerid][pFaction] != FACTIONID_GOVERNMENT))
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w³aœcicielem tego biznesu !");
					return 1;
				}
				tmp = strtok(cmdtext, idx);
				if(!strlen(tmp))
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /wejsciowka [kwota]");
				}
				if(strval(tmp) < 0 || strval(tmp) > 999)
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Minimalna kwota wejœciówki to $0, maksymalna: $999");
					return 1;
				}
				Businesses[i][EntranceCost] = strval(tmp);
				format(string, sizeof(string), "Wejœciówka: %d$",Businesses[i][EntranceCost]);
				UpdateDynamic3DTextLabelText(Business3DTextLabelC[i], COLOR_LIGHTBLUE2, string);
				format(string, sizeof(string), "[INFO:] Ustawi³eœ wejœciówke biznesu na %d$", Businesses[i][EntranceCost]);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
				
				PlayerActionMessage(playerid,15.0, "nakleja kartke na drzwi");
				
				SaveBizData(i, "EntranceCost");
				return 1;
			}
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Musisz znajdowaæ siê przed wejœciem do biznesu !");
			return 1;
		}
		else if(strcmp(cmd, "/nazwabiznesu", true) == 0)
		{
			for(new i = 0; i < sizeof(Businesses); i++)
			{
				if(!PlayerToPoint(5.0, playerid, Businesses[i][EnterX], Businesses[i][EnterY], Businesses[i][EnterZ]))
					continue;
				if(strcmp(gPlayerData[playerid][pName], Businesses[i][Owner], false) != 0 && (!Businesses[i][BGov] || gPlayerData[playerid][pFaction] != FACTIONID_GOVERNMENT))
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w³aœcicielem tego biznesu !");
					return 1;
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
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /nazwabiznesu [nazwa]");
				if(strlen(result) < 3)
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nazwa musi zawieraæ co najmniej 3 znaki !");
					return 1;
				}
				if(strfind(result , "|" , true) == -1)
				{
					strmid(Businesses[i][BusinessName], result, 0, 64, 255);
					new businesstype[128];
					if(Businesses[i][BizType] != 0)
					{
						if(Businesses[i][BizType] == 1) { businesstype = "Restauracja"; }
						else if(Businesses[i][BizType] == 2) { businesstype = "Siec komorkowa"; }
						else if(Businesses[i][BizType] == 3) { businesstype = "Sklep 24/7"; }
						else if(Businesses[i][BizType] == 4) { businesstype = "Sklep z bronia"; }
						else if(Businesses[i][BizType] == 5) { businesstype = "Studio reklamowe"; }
						else if(Businesses[i][BizType] == 6) { businesstype = "Sklep z ubraniami"; }
						else if(Businesses[i][BizType] == 7) { businesstype = "Bar/Club"; }
						else if(Businesses[i][BizType] == 8) { businesstype = "Studio nagraniowe"; }
						else if(Businesses[i][BizType] == 9) { businesstype = "Studio"; }
						else if(Businesses[i][BizType] == 10) { businesstype = "Salon samochodowy"; }
						else if(Businesses[i][BizType] == 11) { businesstype = "Stacja paliw"; }
					}
					else { businesstype = "Nie ustawione"; }

					format(string, sizeof(string), "Nazwa biznesu: %s, Typ biznesu: %s",Businesses[i][BusinessName],businesstype);
					UpdateDynamic3DTextLabelText(Business3DTextLabelA[i], COLOR_LIGHTBLUE2, string);
					format(string, sizeof(string), "[INFO:] Ustawi³eœ nazwe swojego biznesu na: %s",Businesses[i][BusinessName]);
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
					
					PlayerActionMessage(playerid,15.0, "montuje nowy szyld");
					
					SaveBizData(i, "BusinessName");
					return 1;
				}
				else
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nieprawid³owy symbol: | nie jest dozwolony");
					return 1;
				}
			}
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Musisz znajdowaæ siê przed wejœciem do biznesu !");
			return 1;
		}
		else if(strcmp(cmd, "/infobiznesu", true) == 0)
		{
			for(new i = 0; i < sizeof(Businesses); i++)
			{
				if(!PlayerToPoint(100.0, playerid, Businesses[i][ExitX], Businesses[i][ExitY], Businesses[i][ExitZ]) || GetPlayerVirtualWorld(playerid) != i)
					continue;
				if(strcmp(gPlayerData[playerid][pName], Businesses[i][Owner], false) != 0 && (!Businesses[i][BGov] || gPlayerData[playerid][pFaction] != FACTIONID_GOVERNMENT))
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w³aœcicielem tego biznesu !");
					return 1;
				}
				
				
				format(string, sizeof(string), "Nazwa biznesu: %s\nPieni¹dze w kasie: %d$\nWejœciówka: %d$\nWycena biznesu: %d$", Businesses[i][BusinessName], Businesses[i][Till], Businesses[i][EntranceCost], Businesses[i][BizPrice]);
				if(Businesses[i][BizType] == BIZT_VEHICLES)
					format(string, sizeof(string), "%sPosiadanych pojazdów: %d/%d\nLiczba zamówieñ: %d\nPojazdy oczekuj¹ce(0/1): %d\n", string, Businesses[i][VehicleCount], Businesses[i][MaxVehicles], Businesses[i][VehicleOrderCount], Businesses[i][VehicleSpawned]);
				
				
				ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Biznes", string, "Zamknij", "");
				PlayerActionMessage(playerid, 15.0, "przegl¹da dokumentacje biznesu");
				return 1;
			}
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Musisz znajdowaæ siê wewn¹trz biznesu !");
			return 1;
		}
		else if(strcmp(cmd, "/sprzedajbiznes", true) == 0)
		{
			for(new i = 0; i < sizeof(Businesses); i++)
			{
				if(!PlayerToPoint(1.0, playerid, Businesses[i][EnterX], Businesses[i][EnterY], Businesses[i][EnterZ]))
					continue;
				if(strcmp(gPlayerData[playerid][pName], Businesses[i][Owner], true) != 0)
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Ten biznes nie nale¿y do ciebie, nie mo¿esz go sprzedaæ !");
					return 1;
				}
				if(Businesses[i][BizType] == 10)
				{
					new cost;
					for(new j = 0; j < sizeof(gVehData); j++)
					{
						if(gVehData[j][BusinessID] == i)
							cost += cenyPojazdow[gVehData[j][mVehModel]-400];
					}
					GivePlayerCash(playerid,(Businesses[i][BizPrice]+cost));
					format(string, sizeof(string), "[INFO:] Sprzeda³eœ swój biznes za %d$.", Businesses[i][BizPrice]+cost);
				}
				else
				{
					GivePlayerCash(playerid,Businesses[i][BizPrice]);
					format(string, sizeof(string), "[INFO:] Sprzeda³eœ swój biznes za %d$.", Businesses[i][BizPrice]);
				}
				SendClientMessage(playerid, COLOR_LIGHTBLUE, string);

				ResetBizData(i, 1);
				RefreshBizDescription(i);
				
				return 1;
			}
			return 1;
		}
		else if(strcmp(cmd, "/kupbiznes", true) == 0)
		{
			new cost;
			if(gPlayerData[playerid][pIsDeptor])
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Znajdujesz siê w rejestrze d³u¿ników. Nie mo¿esz kupiæ ¿adnego biznesu !");
				return 1;
			}
			new countBizTel, countBizOther;
			for(new h = 0; h < sizeof(Businesses); h++)
			{
				if(strcmp(Businesses[h][Owner], gPlayerData[playerid][pName], false) == 0)
				{
					if(Businesses[h][BizType] == BIZT_PHONE)
						countBizTel++;
					else
						countBizOther++;
				}
			}
			for(new h = 0; h < sizeof(Businesses); h++)
			{
				if(PlayerToPoint(2.0, playerid, Businesses[h][EnterX], Businesses[h][EnterY], Businesses[h][EnterZ]))
				{
					if(Businesses[h][BizType] == BIZT_PHONE)
					{
						if(countBizTel)
						{
							if(gPlayerData[playerid][pFaction2] == 255)
							{
								ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Mo¿esz posiadaæ tylko jeden biznes tego typu nie posiadaj¹c firmy telekomunikacyjnej", "Zamknij", "");
								return 1;
							}
							else if(DynamicFactions[gPlayerData[playerid][pFaction2]][fType] != FACTIONT_COMPANY_PHONE)
							{
								ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Mo¿esz posiadaæ tylko jeden biznes tego typu nie posiadaj¹c firmy telekomunikacyjnej", "Zamknij", "");
								return 1;
							}
						}
					}
					else
					{
						if(countBizOther)
						{
							if(gPlayerData[playerid][pFaction2] == 255)
							{
								ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Mo¿esz posiadaæ tylko jeden biznes tego typu nie posiadaj¹c firmy sieci us³ugowej", "Zamknij", "");
								return 1;
							}
							else if(DynamicFactions[gPlayerData[playerid][pFaction2]][fType] != FACTIONT_COMPANY_OTHER)
							{
								ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", "Mo¿esz posiadaæ tylko jeden biznes tego typu nie posiadaj¹c firmy sieci us³ugowej", "Zamknij", "");
								return 1;
							}
						}
					}
					if(Businesses[h][Owned] && !Businesses[h][BGov])
					{
						SendClientMessage(playerid, COLOR_RED, "[INFO:] Ten biznes nie jest na sprzeda¿");
						return 1;
					}
					if(!Businesses[h][BizPrice])
					{
						SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie ma ustalonej ceny za ten biznes, prawdopodobnie nie jest on na sprzeda¿");
						return 1;
					}
					if(gPlayerData[playerid][pFaction] != 255 && Businesses[h][BizType] == BIZT_WEAPONS)
					{
						if(gPlayerData[playerid][pRank] == 1 && DynamicFactions[ gPlayerData[playerid][pFaction] ][fType] == F_POLICE)
						{
							SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz jednoczeœnie byæ liderem tej frakcji i posiadaæ sklepu z broni¹ !");
							return 1;
						}
					}
					if(gBizBoughtApproved[playerid] != h && !AdminDuty[playerid])
					{
						SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz pozwolenia na kupno tego biznesu !");
						SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Aby uzyskaæ pozwolenie udaj siê do urzêdnia i wpisz komende /prosbaobiznes [id urzednika] [id biznesu]");
						return 1;
					}
					if(!PlayerFreeSlotCount(playerid))
					{
						SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz kupiæ tego biznesu - nie masz miejsca na kluczyki");
						return 1;
					}
					if(GetPlayerCash(playerid) >= Businesses[h][BizPrice])
					{
						// ResetBizData(h, 1);
						if(Businesses[h][BizType] == 10)
						{
							for(new i = 0; i < sizeof(gVehData); i++)
							{
								if(gVehData[i][BusinessID] == h)
								{
									cost += cenyPojazdow[gVehData[i][mVehModel]-400];
								}
							}
							if(GetPlayerCash(playerid) >= Businesses[h][BizPrice] + cost)
							{
								Businesses[h][Till] = 0;
								Businesses[h][Owned] = 1;
								Businesses[h][Products] = 0;
								strmid(Businesses[h][Owner], gPlayerData[playerid][pName], 0, MAX_PLAYER_NAME);
								SaveBizData(h, "Till");
								SaveBizData(h, "Owned");
								SaveBizData(h, "Owner");
								SaveBizData(h, "Products");

								GivePlayerCash(playerid, -(Businesses[h][BizPrice]+cost));

								SetPlayerInterior(playerid, Businesses[h][ExitInterior]);
								SetPlayerVirtualWorld(playerid, h);
								SetPlayerToPos(playerid, Businesses[h][ExitX], Businesses[h][ExitY], Businesses[h][ExitZ]);

								SendClientMessage(playerid, COLOR_WHITE, "[INFO:] Kupi³eœ biznes !");
								PlayerPlaySound(playerid, 1149, 0, 0, 0);

								DestroyDynamicPickup(Businesses[h][PickupID]);
								Businesses[h][PickupID] = CreateDynamicPickup(1239, 1, Businesses[h][EnterX],Businesses[h][EnterY],Businesses[h][EnterZ]);
							}
						}
						else
						{
							Businesses[h][Till] = 0;
							Businesses[h][Owned] = 1;
							Businesses[h][Products] = 0;
							strmid(Businesses[h][Owner], gPlayerData[playerid][pName], 0, MAX_PLAYER_NAME, 255);
							SaveBizData(h, "Till");
							SaveBizData(h, "Owned");
							SaveBizData(h, "Owner");
							SaveBizData(h, "Products");

							GivePlayerCash(playerid,-Businesses[h][BizPrice]);

							SetPlayerInterior(playerid,Businesses[h][ExitInterior]);
							SetPlayerVirtualWorld(playerid,h);
							SetPlayerToPos(playerid,Businesses[h][ExitX],Businesses[h][ExitY],Businesses[h][ExitZ]);

							SendClientMessage(playerid, COLOR_WHITE, "[INFO:] Kupi³eœ biznes !");
							PlayerPlaySound(playerid, 1149, 0, 0, 0);

							DestroyDynamicPickup(Businesses[h][PickupID]);
							CreateDynamicPickup(1239, 1, Businesses[h][EnterX], Businesses[h][EnterY], Businesses[h][EnterZ]);
						}
						
						Businesses[h][BUID] = random(999999);						
						
						InsertPlayerItem(playerid, 10, h, Businesses[h][BUID], 0);
						
						RefreshBizDescription(h);
						
						return 1;
					}
					else
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie masz wystarczaj¹cej iloœci pieniêdzy !");
						return 1;
					}
				}
			}
			return 1;
		}
		else if(strcmp(cmd, "/kuptest", true) == 0)
		{
			new isInstructor, slot2;
			if(PlayerToPoint(1.0, playerid, gDrivingTestPosition[mPosXA], gDrivingTestPosition[mPosYA], gDrivingTestPosition[mPosZA]))
			{
				new slot =  PHaveItem(playerid, 3, 6);				
				if(slot == 0 || SlotParam1(playerid, slot) <= 0)
				{
					foreach(Player, i)
					{
						if(gPlayerLogged[i])
						{
							slot2 = PHaveItemParam5Ex(i, 3, 18, gPlayerData[i][pName]);
							if(slot2 != -1)
							{
								if(SlotParam3(i, slot2))
									isInstructor = 1;
							}
						}
					}
					if(!isInstructor)
					{
						SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz rozpocz¹æ testu, nie ma tutaj ¿adnego egzaminatora !");
						return 1;
					}
					if(!TakingDrivingTestA[playerid] && !TakingDrivingTestB[playerid] && !TakingDrivingTestCE[playerid])
					{
						if(GetPlayerCash(playerid) >= gDrivingTestPosition[mPriceA] && !gPlayerData[playerid][pFirstATest])
						{
							GivePlayerCash(playerid, -gDrivingTestPosition[mPriceA]);
							DynamicFactions[FACTIONID_GOVERNMENT][fBank] += gDrivingTestPosition[mPriceA];
							SaveFData(FACTIONID_GOVERNMENT, "Bank");
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] Wykupi³eœ test ! Aby rozpocz¹æ egzamin teoretyczny wpisz /rozpocznijtest");
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] Pamiêtaj aby nie rozpoczynaæ testu jeœli w pobli¿u nie ma egzaminatora poniewa¿ taki test bêdzie niewa¿ny !");
							TakingDrivingTestA[playerid] = 1;
							gPlayerData[playerid][pFirstATest] = 1;
							SavePlayerData(playerid, "FirstATest");
						}
						else if(GetPlayerCash(playerid) >= gDrivingTestPosition[mPriceLowA] && gPlayerData[playerid][pFirstATest])
						{
							GivePlayerCash(playerid, -gDrivingTestPosition[mPriceLowA]);
							DynamicFactions[FACTIONID_GOVERNMENT][fBank] += gDrivingTestPosition[mPriceLowA];
							SaveFData(FACTIONID_GOVERNMENT, "Bank");
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] Wykupi³eœ test ! Aby rozpocz¹æ egzamin teoretyczny wpisz /rozpocznijtest");
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] Pamiêtaj aby nie rozpoczynaæ testu jeœli w pobli¿u nie ma egzaminatora poniewa¿ taki test bêdzie niewa¿ny !");
							TakingDrivingTestA[playerid] = 1;
						}
						else
						{
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] Nie masz wystarczaj¹co du¿o pieniêdzy !");
						}
					}
					else if(!TakingDrivingTestA[playerid] && (TakingDrivingTestB[playerid] || TakingDrivingTestCE[playerid]))
					{
						SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Mo¿esz wykupiæ tylko jeden test na raz");
					}
					else if(TakingDrivingTestA[playerid])
					{
						SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Wykupi³eœ ju¿ ten test");
					}
				}
				else
				{
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] Ju¿ posiadasz prawo jazdy !");
				}
				return 1;
			}
			if(PlayerToPoint(1.0, playerid, gDrivingTestPosition[mPosXB], gDrivingTestPosition[mPosYB], gDrivingTestPosition[mPosZB]))
			{
				new slot = PHaveItem(playerid, 3, 6);				
				if(slot == 0 || SlotParam2(playerid, slot) <= 0)
				{
					foreach(Player, i)
					{
						if(gPlayerLogged[i])
						{
							slot2 = PHaveItemParam5Ex(i, 3, 18, gPlayerData[i][pName]);
							if(slot2 != -1)
							{
								if(SlotParam3(i, slot2))
									isInstructor = 1;
							}
						}
					}
					if(!isInstructor)
					{
						SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz rozpocz¹æ testu, nie ma tutaj ¿adnego egzaminatora !");
						return 1;
					}
					if(!TakingDrivingTestB[playerid] && !TakingDrivingTestA[playerid] && !TakingDrivingTestCE[playerid])
					{
						if(GetPlayerCash(playerid) >= gDrivingTestPosition[mPriceB] && !gPlayerData[playerid][pFirstBTest])
						{
							GivePlayerCash(playerid, -gDrivingTestPosition[mPriceB]);
							DynamicFactions[FACTIONID_GOVERNMENT][fBank] += gDrivingTestPosition[mPriceB];
							SaveFData(FACTIONID_GOVERNMENT, "Bank");
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] Wykupi³eœ test ! Aby rozpocz¹æ egzamin teoretyczny wpisz /rozpocznijtest");
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] Pamiêtaj aby nie rozpoczynaæ testu jeœli w pobli¿u nie ma egzaminatora poniewa¿ taki test bêdzie niewa¿ny !");
							TakingDrivingTestB[playerid] = 1;
							gPlayerData[playerid][pFirstBTest] = 1;
							SavePlayerData(playerid, "FirstBTest");
						}
						else if(GetPlayerCash(playerid) >= gDrivingTestPosition[mPriceLowB] && gPlayerData[playerid][pFirstBTest])
						{
							GivePlayerCash(playerid, -gDrivingTestPosition[mPriceLowB]);
							DynamicFactions[FACTIONID_GOVERNMENT][fBank] += gDrivingTestPosition[mPriceLowB];
							SaveFData(FACTIONID_GOVERNMENT, "Bank");
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] Wykupi³eœ test ! Aby rozpocz¹æ egzamin teoretyczny wpisz /rozpocznijtest");
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] Pamiêtaj aby nie rozpoczynaæ testu jeœli w pobli¿u nie ma egzaminatora poniewa¿ taki test bêdzie niewa¿ny !");
							TakingDrivingTestB[playerid] = 1;
						}
						else
						{
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] Nie masz wystarczaj¹co du¿o pieniêdzy !");
						}
					}
					else if(!TakingDrivingTestB[playerid] && (TakingDrivingTestA[playerid] || TakingDrivingTestCE[playerid]))
					{
						SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Mo¿esz wykupiæ tylko jeden test na raz");
					}
					else if(TakingDrivingTestB[playerid])
					{
						SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Wykupi³eœ ju¿ ten test");
					}
				}
				else
				{
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] Ju¿ posiadasz prawo jazdy !");
				}
				return 1;
			}
			if(PlayerToPoint(1.0, playerid, gDrivingTestPosition[mPosXCE], gDrivingTestPosition[mPosYCE], gDrivingTestPosition[mPosZCE]))
			{
				new slot = PHaveItem(playerid, 3, 6);				
				if(slot == 0 || SlotParam3(playerid, slot) <= 0)
				{
					foreach(Player, i)
					{
						if(gPlayerLogged[i])
						{
							slot2 = PHaveItemParam5Ex(i, 3, 18, gPlayerData[i][pName]);
							if(slot2 != 1)
							{
								if(SlotParam3(i, slot2))
									isInstructor = 1;
							}
						}
					}
					if(!isInstructor)
					{
						SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz rozpocz¹æ testu, nie ma tutaj ¿adnego egzaminatora !");
						return 1;
					}
					if(!TakingDrivingTestCE[playerid] && !TakingDrivingTestA[playerid] && !TakingDrivingTestB[playerid])
					{
						if(GetPlayerCash(playerid) >= gDrivingTestPosition[mPriceCE] && !gPlayerData[playerid][pFirstCETest])
						{
							GivePlayerCash(playerid, -gDrivingTestPosition[mPriceCE]);
							DynamicFactions[FACTIONID_GOVERNMENT][fBank] += gDrivingTestPosition[mPriceCE];
							SaveFData(FACTIONID_GOVERNMENT, "Bank");
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] Wykupi³eœ test ! Aby rozpocz¹æ egzamin teoretyczny wpisz /rozpocznijtest");
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] Pamiêtaj aby nie rozpoczynaæ testu jeœli w pobli¿u nie ma egzaminatora poniewa¿ taki test bêdzie niewa¿ny !");
							TakingDrivingTestCE[playerid] = 1;
							gPlayerData[playerid][pFirstCETest] = 1;
							SavePlayerData(playerid, "FirstCETest");
						}
						else if(GetPlayerCash(playerid) >= gDrivingTestPosition[mPriceLowCE] && gPlayerData[playerid][pFirstCETest])
						{
							GivePlayerCash(playerid, -gDrivingTestPosition[mPriceLowCE]);
							DynamicFactions[FACTIONID_GOVERNMENT][fBank] += gDrivingTestPosition[mPriceLowCE];
							SaveFData(FACTIONID_GOVERNMENT, "Bank");
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] Wykupi³eœ test ! Aby rozpocz¹æ egzamin teoretyczny wpisz /rozpocznijtest");
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] Pamiêtaj aby nie rozpoczynaæ testu jeœli w pobli¿u nie ma egzaminatora poniewa¿ taki test bêdzie niewa¿ny !");
							TakingDrivingTestCE[playerid] = 1;
						}
						else
						{
							SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] Nie masz wystarczaj¹co du¿o pieniêdzy !");
						}
					}
					else if(!TakingDrivingTestCE[playerid] && (TakingDrivingTestA[playerid] || TakingDrivingTestB[playerid]))
					{
						SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Mo¿esz wykupiæ tylko jeden test na raz");
					}
					else if(TakingDrivingTestCE[playerid])
					{
						SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Wykupi³eœ ju¿ ten test");
					}
				}
				else
				{
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] Ju¿ posiadasz prawo jazdy !");
				}
				return 1;
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
						SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] Rozpocz¹³ siê Twój test!");
						SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] Wybierz jedn¹ z kilku ³ódek szkoleniowych.");
						SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] Je¿eli w danym momencie nie ma ¿adnej wolnej, musisz poczekaæ.");
						TakingBoatTest[playerid] = 1;
					}
					else
					{
						SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] Nie masz wystarczaj¹co pieniêdzy!");
					}
				}
				else
				{
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] Ju¿ posiadasz prawo jazdy!");
				}
			}
			SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie znajdujesz siê w ¿adnym punkcie kupna !");
			return 1;
		}
		// TODO: add new licence point for heli
		else if(strcmp(cmd, "/kuplicencjepilota", true) == 0)
		{
			if(PlayerToPoint(1.0,playerid,gPlaneTestPosition[mPosX],gPlaneTestPosition[mPosY],gPlaneTestPosition[mPosZ]))
			{
				if(!gPlayerData[playerid][pPlaneLic])
				{
					if(GetPlayerCash(playerid) >= 20000)
					{
						GivePlayerCash(playerid,-20000);
						DynamicFactions[FACTIONID_GOVERNMENT][fBank] += 20000;
						SaveFData(FACTIONID_GOVERNMENT, "Bank");
						SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] Mo¿esz teraz lataæ samolotami!");
						gPlayerData[playerid][pPlaneLic] = 1;
						SavePlayerData(playerid, "FlyLic");
					}
					else
					{
						SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] Nie masz wystarczaj¹co pieniêdzy!");
					}
				}
				else
				{
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] Ju¿ posiadasz licencje pilota!");
				}
			}
			else
			{
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ w oœrodku szkolenia pilotów!");
			}
			return 1;
		}
		else if(strcmp(cmd, "/kuplicencjeheli", true) == 0)
		{
			if(PlayerToPoint(1.0,playerid,gPlaneTestPosition[mPosX],gPlaneTestPosition[mPosY],gPlaneTestPosition[mPosZ]))
			{
				if(!gPlayerData[playerid][pHeliLic])
				{
					if(GetPlayerCash(playerid) >= 20000)
					{
						GivePlayerCash(playerid,-20000);
						DynamicFactions[FACTIONID_GOVERNMENT][fBank] += 20000;
						SaveFData(FACTIONID_GOVERNMENT, "Bank");
						SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] Mo¿esz teraz lataæ œmig³owcami!");
						gPlayerData[playerid][pHeliLic] = 1;
						SavePlayerData(playerid, "HeliLic");
					}
					else
					{
						SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] Nie masz wystarczaj¹co pieniêdzy!");
					}
				}
				else
				{
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] Ju¿ posiadasz licencje pilota!");
				}
			}
			else
			{
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ w oœrodku szkolenia pilotów!");
			}
			return 1;
		}
		else if(strcmp(cmd, "/kuplicencjenabron", true) == 0)
		{
			if(PlayerToPoint(1.0,playerid,WeaponLicensePosition[X],WeaponLicensePosition[Y],WeaponLicensePosition[Z]))
			{
				if(!gPlayerData[playerid][pWepLic])
				{
					if(GetPlayerCash(playerid) >= 50000)
					{
						GivePlayerCash(playerid,-50000);
						DynamicFactions[FACTIONID_GOVERNMENT][fBank] += 50000;
						SaveFData(FACTIONID_GOVERNMENT, "Bank");
						SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] Mo¿esz posiadaæ i u¿ywaæ broni, w obronie w³asnej oczywiœcie.");
						gPlayerData[playerid][pWepLic] = 1;
						SavePlayerData(playerid, "WepLic");
					}
					else
					{
						SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] Nie masz wystarczaj¹co pieniêdzy!");
					}
				}
				else
				{
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] Ju¿ posiadasz licencje na broñ!");
				}
			}
			else
			{
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] Nie znajdujesz siê w miejscu zakupu licencji!");
			}
			return 1;
		}
		else if(strcmp(cmd, "/zatankuj", true) == 0)
		{
			if(IsABike(idcar))
			{
				SendClientMessage(playerid, COLOR_LIGHTBLUE, "[INFO:] Nie mo¿esz zatankowaæ roweru !");

				PlayerActionMessage(playerid,15.0, "spogl¹da w niebo");

				return 1;
			}
			for(new i = 0; i < sizeof(Businesses); i++)
			{
				if(gPlayerData[playerid][pGasStationRefPetrol][i] != 0.0 || gPlayerData[playerid][pGasStationRefOil][i] != 0 || gPlayerData[playerid][pGasStationRefGas][i] != 0)
				{
					format(string, sizeof(string), "Nie mo¿esz zatankowaæ paliwa, posiadasz d³ug na jednej ze stacji ! (biznes nr %d)", i);
					ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Informacja", string, "Zamknij", "");
					return 1;
				}
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
					// printf(" GasStation[%d][GSposX] = %f, GasStation[%d][GSposY] = %f, GasStation[%d][GSposZ] = %f", i,  GasStations[i][GSposX], i, GasStations[i][GSposY], i, GasStations[i][GSposZ]);
					if(PlayerToPoint(10.0, playerid, GasStations[i][GSposX], GasStations[i][GSposY], GasStations[i][GSposZ]))
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
							strcat(tmpstring, "Rozpoczêto tankowanie.\nAby przerwaæ tankowanie w danym momencie uruchom silnik i zaparkuj pojazd tak\n ");
							strcat(tmpstring, "aby zwolniæ miejsce do tankowania a nastêpnie udaj siê do kasy znajduj¹cej siê w stacji aby op³aciæ zatankowane paliwo.");
							ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Stacja paliw", tmpstring, "Zamknij", "");
							gVehData[tmpcar][IsRefueling] = 1;
						}
						else if(gVehData[tmpcar][IsRefueling])
							ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Stacja paliw", "Pojazd jest ju¿ tankowany !", "Zamknij", "");
						else
							ShowPlayerDialog(playerid, DIALOG_INFO, DIALOG_STYLE_MSGBOX, "Stacja paliw", "Masz ju¿ pe³ny bak !", "Zamknij", "");
						return 1;
					}
				}
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ na stacji benzynowej!");
				return 1;
			}
		}
		else if(strcmp(cmd, "/statystyki", true) == 0)
		{
			if(!gPlayerData[playerid][pFirstStats])
			{
				gPlayerData[playerid][pFirstStats] = 1;
				SavePlayerData(playerid, "FirstStats");
				// AddExpPoint(playerid);
				SendClientMessage(playerid, COLOR_GREEN, "[INFO:] Poraz pierwszy wyœwietli³eœ swoje statystyki !");
			}
			ShowStats(playerid,playerid);
			return 1;
		}
		else if(strcmp(cmd, "/komendydomu", true) == 0)
		{
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "/wejdz - /wyjdz - /kupdom - /sprzedajdom - /zmienczynsz - /czynsz  - /otworzdom - /wyplaczdomu - /wplacdodomu");
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "/wynajmijdom - /zrezygnujzwynajmu - /zamknijdom - /mojeitemywdomu - /wezitemzdomu");
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "/wlozitemdodomu - /radiod - /radiodv - /radiodoff - /radiozabierz - /ktowynajmuje");
			return 1;
		}
		else if(strcmp(cmd, "/komendyfirmy", true) == 0)
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "/sieckomorkowa - /firmawplac - /firmawyplac");
			return 1;
		}
		else if(strcmp(cmd, "/komendyfrakcji", true) == 0)
		{
			if(gPlayerData[playerid][pFaction] != 255)
			{
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "/opuscfrakcje - /f - /fwyplac - /fwplac - /fstankonta - /statusfrakcji - /przekazlidera - /uprawnieniarangi");
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "/zmienuprawnieniarangi - /kuppojazdf - /sprzedajpojazdf - /zezlomujpojazdf");
				if(gPlayerData[playerid][pFaction] == FACTIONID_GOVERNMENT)
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "/komendyurzedu - /komendyurzedu2");
				if(gPlayerData[playerid][pFaction] == FACTIONID_SANNEWS)
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "/cenypaliw - /ustawwiadomosc");
				if(gPlayerData[playerid][pFaction] == FACTIONID_POLICE)
					SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "/ustawwiadomosc - /wyczyscwiadomosc");
				if(DynamicFactions[gPlayerData[playerid][pFaction]][fType] == FACTIONT_GANG)
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "/terytoria - /walczoterytorium - /okradnij - /okradnijzkasy - /wlamsiedopojazdu - /wlamsiedodomu - /wlamsiedobiznesu");
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "/okradnijdom - /okradnijbiznes - /pokazpunkteksportu - /ukryjpunkteksportu - /eksportujpojazd - /oddajterytorium");
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "/zbierzplony - /podpalfab");
				}
				else if(DynamicFactions[gPlayerData[playerid][pFaction]][fType] == FACTIONT_TAXI)
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "/taxi");
			}
			else
			{
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] Nie nale¿ysz do ¿adnej frakcji.");
			}
			return 1;
		}
		else if(strcmp(cmd, "/komendylidera", true) == 0)
		{
			if(gPlayerData[playerid][pFaction] != 255 && gPlayerData[playerid][pRank] == 1)
			{
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[Lider:] /zapros - /wypros - /kuppojazdf - /sprzedajpojazdf - /zezlomujpojazdf");
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[Lider:] /pktorganizacyjny - /pktorganizacyjny2 - /fabryka");
			}
			else
			{
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ liderem !");
			}
			return 1;
		}
		else if(strcmp(cmd, "/komendytel", true) == 0)
		{
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "/odbierz - /rozlacz - /glosnik - /txt - /ksiazkatel - /onoff tel");
			return 1;
		}
		else if(strcmp(cmd, "/komendybiznesu", true) == 0)
		{
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "/kupbiznes - /sprzedajbiznes - /statystykibiznesu - /infobiznesu - /wejsciowka - /nazwabiznesu - /otworzbiznes - /zamknijbiznes");
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "/wplacdobiznesu - /wyplaczbiznesu - /radiob - /radiobv - /radioboff - /radiozabierz");
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "/salon - /stacjapaliw");
			return 1;
		}
		else if(strcmp(cmd, "/stacjapaliw", true) == 0)
		{
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "/stanstacji - /uzupelnianiebenzyny - /uzupelnianieropy - /uzupelnianiegazu - /cenazalitrsbenzyny - /cenazalitrsropy - /cenazalitrsgazu");
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "/cenazalitrsgazu");
			return 1;
		}
		else if(strcmp(cmd, "/salon", true) == 0)
		{
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "/statuszamowien - /sprowadzpojazd - /cenapojazdu ");
			return 1;
		}
		else if(strcmp(cmd, "/acarcmds", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 1)
				return 0;
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[Level 5:] - /acarpark - /acarmodel - /acarcolor - /aFactionCar - /acarenter - /acartype - /acarsetpos - /acardata");
			return 1;
		}
		else if(strcmp(cmd, "/acarcreate", true) == 0)
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
			//if(car < 400 || car > 611) { SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] 400-611."); return 1; }
			if(car < 400 || car > 701 && car != 537 && car != 538) { SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] 400-611."); return 1; }
			GetPlayerPos(playerid, x, y, z);
			vehicleID = CreateVehicle(car, x, y, z, 0, -1, -1, -1);

			gVehData[vehicleID-1][mVehModel] = car;
			gVehData[vehicleID-1][mVehX] = x;
			gVehData[vehicleID-1][mVehY] = y;
			gVehData[vehicleID-1][mVehZ] = z;
			gVehData[vehicleID-1][mVehA] = 0;
			gVehData[vehicleID-1][mVehColor1] = -1;
			gVehData[vehicleID-1][mVehColor2] = -1;
			gVehData[vehicleID-1][mVehFaction] = 255;
			gVehData[vehicleID-1][mVehType] = 0;
			gVehData[vehicleID-1][mVehOwned] = 0;
			strmid(gVehData[vehicleID-1][Owner], "None", 0, 4, 128);
			gVehData[vehicleID-1][Price] = cenyPojazdow[car-400];
			gVehData[vehicleID-1][Closed] = 0;
			gVehData[vehicleID-1][CarResetT] = 0;
			gVehData[vehicleID-1][CarDamaged] = 0;
			gVehData[vehicleID-1][CarRepairTimeLeft] = 0;
			gVehData[vehicleID-1][BusinessID] = 255;
			gVehData[vehicleID-1][CarFuel] = float(VehFTank(vehicleID));
			gVehData[vehicleID-1][CarHealth] = 1000.0;

			SaveVehData(vehicleID-1, "VehModel");
			SaveVehData(vehicleID-1, "VehPos");
			SaveVehData(vehicleID-1, "VehColor1");
			SaveVehData(vehicleID-1, "VehColor2");
			SaveVehData(vehicleID-1, "VehFaction");
			SaveVehData(vehicleID-1, "VehType");
			SaveVehData(vehicleID-1, "VehOwned");
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
		else if(strcmp(cmd, "/ahousecmds", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 1)
				return 0;
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[Level 7:] - /ahouseentrance - /ahouseexit - /ahousedescription - /agotohouse - /ahouseprice - /ahousesell - /ahouseint");
			return 1;
		}
		else if(strcmp(cmd, "/apositioncmds", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 1)
				return 0;
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[Level 1:] - [TELEPORTS] /agotobuilding - /agotohouse - /agotobiz - /agotofmatsstorage - /agotofdrugsstorage");
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[Level 1:] - [TELEPORTS] /agotodrivingtestpos - /agotoflyingtestpos - /agotobank - /agotoweaponlicpos - /agotopolicearrestpos");
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[Level 1:] - [TELEPORTS] /agotopolicedutypos");
			SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[Level 10:] - adrivingtestpos - /aflyingtestpos - /abankpos - /aweaponlicensepos - /apolicearrestpos - /apolicedutypos");
			return 1;
		}
		else if(strcmp(cmd, "/wywal", true) == 0)
		{
			if(IsPlayerConnected(playerid))
			{
				new State;
				if(IsPlayerInAnyVehicle(playerid))
				{
					State=GetPlayerState(playerid);
					if(State!=PLAYER_STATE_DRIVER)
					{
						SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœkierowc¹ !");
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
							if(playa == playerid) { SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz wywaliæ sam siebie !"); return 1; }
							if(IsPlayerInVehicle(playa,idcar))
							{
								format(string, sizeof(string), "[INFO:] Wyrzuci³eœ z samochodu: %s.", GetPlayerNameEx(playa));
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
								format(string, sizeof(string), "[INFO:] Zosta³eœ wyrzucony z samochodu przez %s", GetPlayerNameEx(playerid));
								SendClientMessage(playa, COLOR_LIGHTYELLOW2, string);
								RemovePlayerFromVehicle(playa);
							}
							else
							{
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ten gracz nie jest u Ciebie w samochodzie!");
								return 1;
							}
						}
					}
					else
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Niew³aœciwe ID");
					}
				}
				else
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie jesteœ w pojeŸdzie lub nie jesteœ kierowc¹ !");
				}
			}
			return 1;
		}
		else if(strcmp(cmd, "/adminduty", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 1)
				return 0;
			new faction = gPlayerData[playerid][pFaction];
			if(AdminDuty[playerid] == 1)
			{
				format(string, sizeof(string), "[ADMIN:] %s [%d] nie jest ju¿ na s³u¿bie.", GetPlayerNameEx(playerid),playerid);
				ABroadCast(COLOR_YELLOW, string, 1);
				AdminDuty[playerid] = 0;
				SavePlayerData(playerid, "AdminDuty");
				SetPlayerHealth(playerid,100);
				SetPlayerArmourEx(playerid,0);
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
				format(string, sizeof(string), "[ADMIN:] %s [%d] jest teraz na s³u¿bie.", GetPlayerNameEx(playerid),playerid);
				ABroadCast(COLOR_YELLOW,string,1);
				AdminDuty[playerid] = 1;
				SavePlayerData(playerid, "AdminDuty");
				printf("[WARNING:] %s used goes ON admin DUTY", gPlayerData[playerid][pName]);
				SetPlayerColor(playerid,COLOR_ADMINDUTY);
				SetPlayerHealth(playerid,99999);
				SetPlayerArmourEx(playerid,99999);
			}
			return 1;
		}
		else if(strcmp(cmd, "/check", true) == 0)
		{
			if(gPlayerData[playerid][pModerator] < 1)
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
					new rankPay;
					if(gPlayerData[giveplayerid][pFaction] != 255)
					{
						switch(gPlayerData[giveplayerid][pRank])
						{
							case 1: rankPay = PayRank[gPlayerData[giveplayerid][pFaction]][Rank1];
							case 2: rankPay = PayRank[gPlayerData[giveplayerid][pFaction]][Rank2];
							case 3: rankPay = PayRank[gPlayerData[giveplayerid][pFaction]][Rank3];
							case 4: rankPay = PayRank[gPlayerData[giveplayerid][pFaction]][Rank4];
							case 5: rankPay = PayRank[gPlayerData[giveplayerid][pFaction]][Rank5];
							case 6: rankPay = PayRank[gPlayerData[giveplayerid][pFaction]][Rank6];
							case 7: rankPay = PayRank[gPlayerData[giveplayerid][pFaction]][Rank7];
							case 8: rankPay = PayRank[gPlayerData[giveplayerid][pFaction]][Rank8];
							case 9: rankPay = PayRank[gPlayerData[giveplayerid][pFaction]][Rank9];
							case 10: rankPay = PayRank[gPlayerData[giveplayerid][pFaction]][Rank10];
						}
					}
					format(string, sizeof(string), "[INFO:] Kasa przy postaci: %d$, kasa w banku: %d$, wyp³ata: %d$",
						gPlayerData[giveplayerid][pCash],
						gPlayerData[giveplayerid][pBank],
						rankPay
					);
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
					ShowStats(playerid,giveplayerid);
				}
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Invalid ID.");
			}
			return 1;
		}
		// TODO: could be sponsoring government faction or police etc, for now - disabled
		// else if(strcmp(cmd, "/sponsoruj", true) == 0)
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
					// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nieprawid³owa cena.");
					// return 1;
				// }
				// if(GetPlayerCash(playerid) < moneys)
				// {
					// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie masz tyle !");
					// return 1;
				// }
				// GivePlayerCash(playerid, -moneys);
				// format(string, sizeof(string), "[INFO:] %s zasponsorowal %d$.",GetPlayerNameEx(playerid), moneys);
				// SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
				// PayLog(string);
			// }
			// return 1;
		// }
		else if(strcmp(cmd, "/up", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 1)
				return 0;
			new Float:slx, Float:sly, Float:slz;
			GetPlayerPos(playerid, slx, sly, slz);
			SetPlayerToPos(playerid, slx, sly, slz+4);
			return 1;
		}
		else if(strcmp(cmd, "/mute", true) == 0)
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
		else if(strcmp(cmd, "/mmute", true) == 0)
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
		else if(strcmp(cmd, "/warn", true) == 0)
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
					
					format(string, sizeof(string), "[INFO:] %s [%d] ostrze¿ony przez %s [%d], powód: %s.", gPlayerData[giveplayerid][pName], giveplayerid, gPlayerData[playerid][pName], playerid, result);
					ABroadCast(COLOR_YELLOW, string, 1);
					format(string, sizeof(string), "[INFO:] Zosta³eœ ostrze¿ony przez %s, powód: %s.", GetPlayerNameEx(playerid), (result));
					SendClientMessage(giveplayerid, COLOR_LIGHTYELLOW2, string);
					if(gPlayerData[giveplayerid][pWarnings] >= 5)
					{
						format(string, sizeof(string), "[BAN:] %s zosta³ zbanowany za ponad 5 ostrze¿eñ.", GetPlayerNameEx(giveplayerid));
						BanLog(string);
						BanPlayerAccount(giveplayerid,GetPlayerNameEx(playerid),(result));
						return 1;
					}					
					return 1;
				}
			}//not connected
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Invalid ID.");
			}
			return 1;
		}
		else if(strcmp(cmd, "/goto", true) == 0)
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
			if(IsPlayerConnected(plo))
			{
				if(plo != INVALID_PLAYER_ID)
				{
					GetPlayerPos(plo, plocx, plocy, plocz);
					new interior = GetPlayerInterior(plo);
					new world = GetPlayerVirtualWorld(plo);

					if(GetPlayerState(playerid) == 2)
					{
						SetVehicleToPos(idcar, plocx, plocy+4, plocz);
						gVehData[idcar-1][mVehX] = plocx;
						gVehData[idcar-1][mVehY] = plocy+4;
						gVehData[idcar-1][mVehZ] = plocz;						
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
				SendClientMessage(playerid, COLOR_GRAD1, "[INFO:] Invalid ID.");
			}
			return 1;
		}
		else if(strcmp(cmd, "/mgoto", true) == 0)
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
			if(IsPlayerConnected(plo))
			{
				if(plo != INVALID_PLAYER_ID)
				{
					GetPlayerPos(plo, plocx, plocy, plocz);
					new interior = GetPlayerInterior(plo);
					new world = GetPlayerVirtualWorld(plo);

					if(GetPlayerState(playerid) == 2)
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
				SendClientMessage(playerid, COLOR_GRAD1, "[INFO:] Invalid ID.");
			}
			return 1;
		}
		else if(strcmp(cmd, "/gotols", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 1)
				return 0;
			if(GetPlayerState(playerid) == 2)
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
		else if(strcmp(cmd, "/gotohosp", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 1)
				return 0;
			if(GetPlayerState(playerid) == 2)
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
		else if(strcmp(cmd, "/gotolv", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 1)
				return 0;
			if(GetPlayerState(playerid) == 2)
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
		else if(strcmp(cmd, "/gotoprison", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 1)
				return 0;
			if(GetPlayerState(playerid) == 2)
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
		else if(strcmp(cmd, "/gethere", true) == 0)
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
			if(IsPlayerConnected(plo))
			{
				if(plo != INVALID_PLAYER_ID)
				{
					GetPlayerPos(playerid, plocx, plocy, plocz);
					new interior = GetPlayerInterior(playerid);
					new world = GetPlayerVirtualWorld(playerid);

					if(GetPlayerState(plo) == 2)
					{
						new tmpcar2 = GetPlayerVehicleID(plo);
						gPlayerData[plo][pCrashX] = plocx;
						gPlayerData[plo][pCrashY] = plocy;
						gPlayerData[plo][pCrashZ] = plocz;
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
		else if(strcmp(cmd, "/mgethere", true) == 0)
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
			if(IsPlayerConnected(plo))
			{
				if(plo != INVALID_PLAYER_ID)
				{
					GetPlayerPos(playerid, plocx, plocy, plocz);
					new interior = GetPlayerInterior(playerid);
					new world = GetPlayerVirtualWorld(playerid);

					if(GetPlayerState(playerid) == 2)
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
					format(string, sizeof(string), "[INFO:] You teleported %s to you", GetPlayerNameEx(plo));
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
		else if(strcmp(cmd, "/freeze", true) == 0)
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
		else if(strcmp(cmd, "/unfreeze", true) == 0)
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
		else if(strcmp(cmd, "/mfreeze", true) == 0)
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
						SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie jesteœ upowa¿niony do u¿ywania tej komendy na adminie !");
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
		else if(strcmp(cmd, "/munfreeze", true) == 0)
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
		else if(strcmp(cmd, "/gametext", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 1)
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
			foreach(Player, i)
			{
				if(!gPlayerLogged[i])
					continue;
				GameTextForPlayer(i, string, 5000, 6);
			}
			return 1;
		}
		else if(strcmp(cmd, "/unknowngametext", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 1)
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
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:]");
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
			foreach(Player, i)
			{
				GameTextForPlayer(i, string, 5000, txtid);
			}
			return 1;
		}
		else if(strcmp(cmd, "/fixveh2", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			if(IsPlayerInAnyVehicle(playerid))
			{
				SetVehicleHealth(idcar, 1000.0);
			}
			return 1;
		}
		else if(strcmp(cmd, "/fixveh", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			if(IsPlayerInAnyVehicle(playerid))
			{
				RepairVehicle(idcar);
				gVehData[tmpcar][CarDamaged] = 0;
				gVehData[tmpcar][CarRepairTimeLeft] = 0;
				gVehData[tmpcar][CarHealth] = 1000.0;
				
				SaveVehData(tmpcar, "CarHealth");
				SaveVehData(tmpcar, "CarDamaged");
				SaveVehData(tmpcar, "CarRepairTimeLeft");
			}
			return 1;
		}
		else if(strcmp(cmd, "/money", true) == 0)
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
		else if(strcmp(cmd, "/givemoney", true) == 0)
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
		else if(strcmp(cmd, "/weatherall", true) == 0)
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
			if(weather < 0||weather > 45) { SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] 0-45."); return 1; }
			SetPlayerWeatherEx(playerid, weather);
			return 1;
		}
		else if(strcmp(cmd, "/sethp", true) == 0)
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

					// save on exit
				}
			}
			return 1;
		}
		else if(strcmp(cmd, "/setarmour", true) == 0)
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
					SetPlayerArmourEx(playa, health);
				}
			}
			return 1;
		}
		else if(strcmp(cmd, "/givegun", true) == 0)
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
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ammo must be , 1-999.");
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
		else if(strcmp(cmd, "/dajbron", true) == 0)
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
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Amunicji mozesz dac tylko : 1-30.");
						return 1;
					}
					if(gunGiven[playa] == 1)
					{
						SendClientMessage(playerid, COLOR_RED, "[INFO:] Musisz odczekaæ 2 minuty zanim bêdziesz móg³ znów przekazaæ graczowi broñ !");
						return 1;
					}
					if(gPlayerData[playerid][pFaction] == 9)
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
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ urzednikiem.");
					}
				}
			}
			return 1;
		}
		else if(strcmp(cmd, "/fuelcars", true) == 0)
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
		else if(strcmp(cmd, "/unlockcars", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] != 5)
				return 0;
			for(new c = 0; c < sizeof(gVehData); c++)
			{
				gVehData[c][Closed] = 0;

				SaveVehData(c, "Closed");
			}
			SendClientMessageToAll(COLOR_ADMINCMD, "[INFO:] Wszystkie samochody zosta³y otwarte przez administratora.");
			return 1;
		}
		else if(strcmp(cmd, "/setadmin", true) == 0)
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

					format(string, sizeof(string), "[INFO:] %s mianowa³ Ciê na administratora lvlu: %d.", GetPlayerNameEx(playerid), level);
					SendClientMessage(para1, COLOR_LIGHTYELLOW2, string);
					format(string, sizeof(string), "[INFO:] You have made %s an administrator - Level: %d.", GetPlayerNameEx(para1), level);
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
					format(string, sizeof(string), "[WARNING:] /setadmin has been used by %s for %s", GetPlayerNameEx(playerid), GetPlayerNameEx(para1));
					ABroadCast(COLOR_YELLOW, string, 5);
				}
			}
			return 1;
		}
		else if(strcmp(cmd, "/makemod", true) == 0)
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

					format(string, sizeof(string), "[INFO:] %s mianowa³ Cie Supporterem !", GetPlayerNameEx(playerid));
					SendClientMessage(para1, COLOR_WHITE, string);
					format(string, sizeof(string), "[INFO:] You have made %s an Moderator.", GetPlayerNameEx(para1));
					SendClientMessage(playerid, COLOR_WHITE, string);

					printf("[WARNING:] /makemod has been used by %s for %s", GetPlayerNameEx(para1), GetPlayerNameEx(playerid));
				}
			}
			return 1;
		}
		else if(strcmp(cmd, "/unmakemod", true) == 0)
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
					SavePlayerData(para1, "Moderator");

					format(string, sizeof(string), "[INFO:] %s pozbawi³ Cie funkcji Supportera !", GetPlayerNameEx(playerid));
					SendClientMessage(para1, COLOR_WHITE, string);
					format(string, sizeof(string), "[INFO:] You have dismade %s an Moderator.", GetPlayerNameEx(para1));
					SendClientMessage(playerid, COLOR_WHITE, string);
				}
			}
			return 1;
		}
		else if(strcmp(cmd, "/podnieslev", true) == 0)
		{
			if(!gPlayerData[playerid][pFirstStudy])
			{
				gPlayerData[playerid][pFirstStudy] = 1;
				SavePlayerData(playerid, "FirstStudy");
				// AddExpPoint(playerid);
				SendClientMessage(playerid, COLOR_GREEN, "[INFO:] Pierwszy raz podnios³eœ swoje umiejêtnoœci !");
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
		else if(strcmp(cmd, "/dajpozwolenie", true) == 0)
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
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ urzêdnikiem.");
			}
			return 1 ;
		}
		else if(strcmp(cmd, "/dajdoktora", true) == 0)
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
			if(gPlayerData[playerid][pFaction] == 9 && gPlayerData[playerid][pRank] == 1)
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
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] nie jesteœ urzednikiem.");
			}
			return 1 ;
		}
		else if(strcmp(cmd, "/dajmagistra", true) == 0)
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
			if(gPlayerData[playerid][pFaction] == 9 && gPlayerData[playerid][pRank] == 1)
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
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] nie jesteœ urzednikiem.");
			}
			return 1 ;
		}
		else if(strcmp(cmd, "/dajinz", true) == 0)
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
			if(gPlayerData[playerid][pFaction] == 9 && gPlayerData[playerid][pRank] == 1)
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
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] nie jesteœ urzednikiem.");
			}
			return 1 ;
		}
		else if(strcmp(cmd, "/resettytulow", true) == 0)
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
			if(gPlayerData[playerid][pFaction] == 9 && gPlayerData[playerid][pRank] == 1)
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
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ urzêdnikiem.");
			}
			return 1 ;
		}
		else if(strcmp(cmd, "/resetpktbroni", true) == 0)
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
			if(gPlayerData[playerid][pFaction] == 9)
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
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ urzednikiem.");
			}
			return 1 ;
		}
		else if(strcmp(cmd, "/scommands", true) == 0 || strcmp(cmd, "/scmds", true) == 0)
		{
			if(gPlayerData[playerid][pModerator] >= 1)
			{
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[Supporter]: /mgoto - /mmute - /mkick - /mbanaccount - /(su)pporter - /mspec - /mspecoff - /mjail");
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[Supporter]: /mfreeze - /munfreeze - /mgetip - / - / - / - /- /");
			}
			if(gPlayerData[playerid][pAdmin] >= 1)
			{
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[Level 1:] - (/a)dmin - /goto - /gethere - /warn - /mute - /check - /adminduty - /kick - /asuicide - /up");
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[Level 1:] - /setint - /setvw - /disarm - /error - /spec - /specoff - /cheatstats - /retake");
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[Level 1:] - /freeze - /unfreeze - /gametext - /gotolv - /gotosf - /gotols - /fixveh - /setskin -/fly - /checkweapons");
			}
			if(gPlayerData[playerid][pAdmin] >= 2)
			{
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[Level 2:] /ban - /banaccount - /oocstatus - /listenchat - /ajail - /Prison - /update");
			}
			if(gPlayerData[playerid][pAdmin] >= 3)
			{
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[Level 3:] /alistfaction - /getip - /unban");
			}
			if(gPlayerData[playerid][pAdmin] >= 4)
			{
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[Level 4:] /sethp - /setarmour - /fuelcars - /agivedrugs - /asetdrugs - /agivemats - /asetmats - /agiveproducts - /asetproducts");
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[Level 4:]/explode - /supervehslap - /vehslap");
			}
			if(gPlayerData[playerid][pAdmin] >= 5)
			{
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[Level 5:] /adonator - /acarcmds - /money - /givemoney - /givegun - /respawnvehicles - /rtc");
			}
			if(gPlayerData[playerid][pAdmin] >= 6)
			{
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[Level 6:] ");
			}
			if(gPlayerData[playerid][pAdmin] >= 7)
			{
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[Level 7:] - /unlockcars");
			}
			if(gPlayerData[playerid][pAdmin] >= 8)
			{
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[Level 8:] ");
			}
			if(gPlayerData[playerid][pAdmin] >= 9)
			{
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[Level 9:] ");
			}
			if(gPlayerData[playerid][pAdmin] >= 10)
			{
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[Level 10:] - /logoutall - /unknowngametext /makemod - /snews");
			}
			if(gPlayerData[playerid][pAdmin] >= 20)
			{
				SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[Owner:] - /gmx - /setadmin - /asetleader - /aresetfaction - /ajobcmds - /weatherall - /tod");
			}
			return 1;
		}
		else if(strcmp(cmd, "/wejdz", true) == 0)
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Teraz aby wchodziæ oraz wychodziæ z pomieszczeñ mo¿esz u¿ywaæ klawisza \"F\"");
			for(new i = 0; i < sizeof(Houses); i++)
			{
				if(PlayerToPoint(1.0, playerid,Houses[i][EnterX], Houses[i][EnterY], Houses[i][EnterZ]))
				{
					if(GetPlayerVirtualWorld(playerid) == Houses[i][EnterWorld])
					{
						if((!Houses[i][Locked] && !Houses[i][HConfiscated]) || AdminDuty[playerid])
						{
							if(Houses[i][HouseType] == 0)
							{
								PlayerActionMessage(playerid,15.0, "naciska klamke i wchodzi do budynku");
								Audio_Play(playerid, AUDIO_DOOR_OPEN, false, false, false);
							}
							else
								PlayerActionMessage(playerid, 15.0, "otwiera gara¿ pilotem i wchodzi do gara¿u");
								
							gPlayerVars[playerid][mAtHouseID] = i;	
								
							if(strcmp(gPlayerData[playerid][pName], Houses[i][Owner], false) == 0 || strcmp(gPlayerData[playerid][pName], Houses[i][HRenter], false) == 0)
								SendClientMessage(playerid, COLOR_GREEN, "[INFO:] Jesteœ teraz w swoim domu, twoja postaæ bêdzie siê powoli regenerowaæ");
							
							SetPlayerInterior(playerid,Houses[i][ExitInterior]);
							SetPlayerToPos(playerid,Houses[i][ExitX],Houses[i][ExitY],Houses[i][ExitZ]);
							SetPlayerVirtualWorld(playerid,i);
							SetPlayerFacingAngle(playerid,Houses[i][ExitAngle]);
							
							if(Houses[i][HRadio1On] && Houses[i][HRadio1Bought])
								PlayerPHouseRadio(playerid, i);
							
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
						}
						else if(Houses[i][HConfiscated] && !AdminDuty[playerid])
						{
							GameTextForPlayer(playerid, "~r~Posiadlosc skonfiskowana", 5000, 1);
							PlayerActionMessage(playerid, 20.0, "naciska klamke nie uzyskuj¹c rezultatu");
							
							ApplyAnimation(playerid, "PED", "CAR_doorlocked_RHS",4.1,0,1,1,0,0);
						}
						else
						{
							GameTextForPlayer(playerid, "~r~Zamkniete", 5000, 1);
							PlayerActionMessage(playerid, 20.0, "naciska klamke nie uzyskuj¹c rezultatu");
							
							ApplyAnimation(playerid, "PED", "CAR_doorlocked_RHS",4.1,0,1,1,0,0);
						}
					}
				}
			}
			for(new i = 0; i < sizeof(Building); i++)
			{
				if(PlayerToPoint(1.0, playerid,Building[i][EnterX], Building[i][EnterY], Building[i][EnterZ]))
				{
					if(GetPlayerVirtualWorld(playerid) == Building[i][EnterWorld])
					{
						if(gPlayerData[playerid][pJob] != 22 && i == 49 && !AdminDuty[playerid])
						{
							SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz wejœæ do tego budynku ! Nie jesteœ pracownikiem broni !");
							return 1;
						}
						if((gHour < Building[i][Closed] && gHour >= Building[i][Opened]) || (Building[i][Opened] == Building[i][Closed]) || AdminDuty[playerid] == 1)
						{
							if(Building[i][Locked] == 0 || AdminDuty[playerid] >=  1)
							{
								if(GetPlayerCash(playerid) >= Building[i][EntranceFee] || Building[i][EntranceFee] == 0)
								{
									PlayerActionMessage(playerid,15.0, "naciska klamke i wchodzi do budynku");
									Audio_Play(playerid, AUDIO_DOOR_OPEN, false, false, false);

									gPlayerVars[playerid][mAtBuildingID] = i;
									
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
								
								ApplyAnimation(playerid, "PED", "CAR_doorlocked_RHS",4.1,0,1,1,0,0);
							}
						}
						else
						{
							format(string, sizeof(string), "[INFO:] Budynek zamkniêty ! Wróæ miêdzy godzin¹ %d a %d", Building [i][Opened], Building[i][Closed]);
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
							
							ApplyAnimation(playerid, "PED", "CAR_doorlocked_RHS",4.1,0,1,1,0,0);
						}
					}
				}
			}
			for(new i = 0; i < sizeof(Businesses); i++)
			{
				if(PlayerToPoint(1.0, playerid,Businesses[i][EnterX], Businesses[i][EnterY], Businesses[i][EnterZ]) && GetPlayerVirtualWorld(playerid) == Businesses[i][EnterWorld])
				{
					if(Businesses[i][Locked] && !AdminDuty[playerid])
					{
						GameTextForPlayer(playerid, "~r~Biznes zamkniety.", 5000, 1);
						PlayerActionMessage(playerid, 20.0, "naciska klamke nie uzyskuj¹c rezultatu");
						ApplyAnimation(playerid, "PED", "CAR_doorlocked_RHS",4.1,0,1,1,0,0);
						return 1;
					}
					else if(Businesses[i][BConfiscated] && !AdminDuty[playerid])
					{
						GameTextForPlayer(playerid, "~r~Biznes skonfiskowany", 5000, 1);
						PlayerActionMessage(playerid, 20.0, "naciska klamke nie uzyskuj¹c rezultatu");								
						ApplyAnimation(playerid, "PED", "CAR_doorlocked_RHS",4.1,0,1,1,0,0);
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
						
						format(string, sizeof(string), "[INFO:] Pobrano op³ate w wysokoœci %d$ za wejœcie do %s.", Businesses[i][EntranceCost],Businesses[i][BusinessName]);
						SendClientMessage(playerid,COLOR_LIGHTYELLOW2,string);
					}
					if(gPlayerData[playerid][pJob] == 19)
					{
						if(Businesses[i][Till] <= 0)
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz pracowaæ tutaj jako sprzedawca - brak pieniêdzy w kasie biznesu");
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Aby rozpocz¹æ prace wpisz /rp - za ka¿de 5 minut spêdzone w pracy dostajesz 12$");
					}															
					// Businesses[i][Products]--;
					// SaveBizData(i, "Products");

					gPlayerVars[playerid][mAtBizID] = i;
					
					PlayerActionMessage(playerid,15.0, "naciska klamke i wchodzi do budynku");
					Audio_Play(playerid, AUDIO_DOOR_OPEN, false, false, false);

					SetPlayerInterior(playerid,Businesses[i][ExitInterior]);
					SetPlayerToPos(playerid,Businesses[i][ExitX],Businesses[i][ExitY],Businesses[i][ExitZ]);
					SetPlayerVirtualWorld(playerid,i);
					SetPlayerFacingAngle(playerid,Businesses[i][ExitAngle]);

					if(Businesses[i][BRadio1On] && Businesses[i][BRadio1Bought])
						ResumeBizRadioStation(playerid, i);
					
					gPlayerData[playerid][pCrashX] = Businesses[i][ExitX];
					gPlayerData[playerid][pCrashY] = Businesses[i][ExitY];
					gPlayerData[playerid][pCrashZ] = Businesses[i][ExitZ];
					gPlayerData[playerid][pCrashW] = i;
					gPlayerData[playerid][pCrashAngle] = Businesses[i][ExitAngle];
					gPlayerData[playerid][pCrashInt] = Businesses[i][ExitInterior];
					
					TogglePlayerControllable(playerid, 0);
					defer UnfreezePlayer(playerid);
				}
			}
			if(PlayerToPoint(2.0, playerid, gDrivingTestArea[posEntranceX], gDrivingTestArea[posEntranceY], gDrivingTestArea[posEntranceZ]))
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
			}
			return 1;
		}
		else if(strcmp(cmd, "/wyjdz", true) == 0)
		{
			for(new i = 0; i < sizeof(Houses); i++)
			{
				if(PlayerToPoint(3.0, playerid,Houses[i][ExitX], Houses[i][ExitY], Houses[i][ExitZ]))
				{
					if(GetPlayerVirtualWorld(playerid) == i)
					{
						if(Houses[i][Locked] == 0 || AdminDuty[playerid])
						{
							if(Houses[i][HouseType] == 0)
							{
								PlayerActionMessage(playerid,15.0, "naciska klamke i wychodzi z budynku");
								Audio_Play(playerid, AUDIO_DOOR_OPEN, false, false, false);
							}
							else
								PlayerActionMessage(playerid, 15.0, "otwiera gara¿ pilotem i wychodzi z gara¿u");
								
							gPlayerVars[playerid][mAtHouseID] = -1;	
								
							if(Houses[i][HRadio1Bought] && Houses[i][HRadio1On])
								Audio_Stop(playerid, Houses[i][HRadio1ID][playerid]);
							
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
				if(PlayerToPoint(3, playerid,Building[i][ExitX], Building[i][ExitY], Building[i][ExitZ]))
				{
					if(GetPlayerVirtualWorld(playerid) == i)
					{
						if(gPlayerData[playerid][pPartType] != 0 && gPlayerData[playerid][pPartItem] != 0 && !AdminDuty[playerid])
						{
							SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz wyjœæ z budynku - musisz zwróciæ wpierw wszystkie czêœci !");
							return 1;
						}
						if(Building[i][Locked] == 0 || AdminDuty[playerid])
						{
							PlayerActionMessage(playerid,15.0, "naciska klamke i wychodzi z budynku");
							Audio_Play(playerid, AUDIO_DOOR_OPEN, false, false, false);

							gPlayerVars[playerid][mAtBuildingID] = -1;
							
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
				if(PlayerToPoint(3, playerid,Businesses[i][ExitX], Businesses[i][ExitY], Businesses[i][ExitZ]))
				{
					if(GetPlayerVirtualWorld(playerid) == i)
					{
						if(gPlayerData[playerid][pSellerJobOn])
						{
							gPlayerData[playerid][pSellerJobOn] = 0;
							SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Opuœci³eœ stanowisko pracy ! Nie dostajesz ju¿ wynagrodzenia.");
						}
						if(Businesses[i][Locked] == 0 || AdminDuty[playerid])
						{
							PlayerActionMessage(playerid,15.0, "naciska klamke i wychodzi z budynku");
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
						}
						else
						{
							GameTextForPlayer(playerid, "~r~Zamkniete", 5000, 1);
							PlayerActionMessage(playerid, 20.0, "naciska klamke nie uzyskuj¹c rezultatu");
						}
					}
				}
			}
			if(PlayerToPoint(2.0, playerid, gDrivingTestArea[posExitX], gDrivingTestArea[posExitY], gDrivingTestArea[posExitZ]))
			{
				SetPlayerToPos(playerid, gDrivingTestArea[posEntranceX], gDrivingTestArea[posEntranceY], gDrivingTestArea[posEntranceZ]);
				SetPlayerFacingAngle(playerid, gDrivingTestArea[posEntranceAngle]);
				SetPlayerInterior(playerid, gDrivingTestArea[posEntranceInterior]);
				SetPlayerVirtualWorld(playerid, gDrivingTestArea[posEntranceWorld]);
			}
			return 1;
		}
		else if(strcmp(cmd, "/asetcarhp", true) == 0)
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
			new veh;
			new Float:carhp = strval(tmp);
			SetVehicleHealth(veh, carhp);
			format(string, sizeof(string), "[INFO:] Ustawi³eœ HP wozu na: %f", carhp);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			return 1;
		}
		else if(strcmp(cmd, "/kuppojazd", true) == 0)
		{
			if(gPlayerData[playerid][pIsDeptor])
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Znajdujesz siê w rejestrze d³u¿ników. Nie mo¿esz kupiæ ¿adnego pojazdu !");
				return 1;
			}
			
			
			// warunki zalezne od ktorych pojazd jest na sprzedaz
			if(gVehData[tmpcar][ReadyToSell] == 0 && (gVehData[tmpcar][mVehOwned] == 1 || gVehData[tmpcar][mVehFaction] != 255))
			{
				SendClientMessage(playerid, COLOR_RED, "[INFO:] Ten pojazd nie jest na sprzeda¿ !");
				return 1;
			}
			
			
			// limity modeli pojazdow
			if(gVehData[tmpcar][mVehModel] == 416 || gVehData[tmpcar][mVehModel] == 433 || gVehData[tmpcar][mVehModel] == 431
			|| gVehData[tmpcar][mVehModel] == 438 || gVehData[tmpcar][mVehModel] == 437 || gVehData[tmpcar][mVehModel] == 523
			|| gVehData[tmpcar][mVehModel] == 427 || gVehData[tmpcar][mVehModel] == 490 || gVehData[tmpcar][mVehModel] == 528
			|| gVehData[tmpcar][mVehModel] == 407 || gVehData[tmpcar][mVehModel] == 544 || gVehData[tmpcar][mVehModel] == 596
			|| gVehData[tmpcar][mVehModel] == 598 || gVehData[tmpcar][mVehModel] == 597 || gVehData[tmpcar][mVehModel] == 599
			|| gVehData[tmpcar][mVehModel] == 601 || gVehData[tmpcar][mVehModel] == 420 || gVehData[tmpcar][mVehModel] == 425
			|| gVehData[tmpcar][mVehModel] == 497 || gVehData[tmpcar][mVehModel] == 430 || gVehData[tmpcar][mVehModel] == 472)
			{
				SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie mo¿esz kupiæ tego pojazdu !");
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
			if(gVehData[tmpcar][Price] <= 0)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz kupiæ tego pojazdu ! - brak ustalonej ceny");
				return 1;
			}
		
		
			// pojazd nowy - salonowy
			new slot;			
			if(gVehData[tmpcar][mVehOwned] == 0 && gVehData[tmpcar][mVehType] == 0 && gVehData[tmpcar][mVehFaction] == 255)
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
					if(gPlayerData[playerid][pPlayingHours] < BoatKeyLVL)
					{
						format(string, sizeof(string), "[INFO:] Musisz mieæ przegrane conajmniej %d godzin aby kupiæ ³ódŸ",BoatKeyLVL);
						SendClientMessage(playerid, COLOR_WHITE, string);
						return 1;
					}

					// sprawdzenie czy gracz posiada wolny slot
					if(!PlayerFreeSlotCount(playerid))
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie masz miejsca na kolejny item !");
						return 1;
					}
					newVehSerial(tmpcar);
					PutPlayerInVehicle(playerid, tmpcar+1, 0);
					slot = InsertPlayerItem(playerid, 2, gVehData[tmpcar][CarSerial], 0, 0);
					gVehData[tmpcar][LastDriverWKey] = gPlayerData[playerid][pName];
					
					// modyfikacja danych pojazdu
					gVehData[tmpcar][mVehOwned] = 1;
					strmid(gVehData[tmpcar][Owner], gPlayerData[playerid][pName], 0, MAX_PLAYER_NAME, 128);

					SaveVehData(tmpcar, "VehOwned");
					SaveVehData(tmpcar, "Owner");

					// zmniejszenie ilosci pieniedzy gracza
					GivePlayerCash(playerid,-gVehData[tmpcar][Price]-floatround(gVehData[tmpcar][Price] * DynamicTaxes[VatTaxMax],floatround_round));

					// podatki
					DynamicFactions[FACTIONID_GOVERNMENT][fBank] += floatround(gVehData[tmpcar][Price] * DynamicTaxes[VatTaxMax],floatround_round);

					// zwolnienie slotu wlasciciela biznesu
					Businesses[gVehData[tmpcar][BusinessID]][VehicleCount]--;

					// zysk dla wlasciciela biznesu/salonu
					Businesses[gVehData[tmpcar][BusinessID]][Till] += gVehData[tmpcar][Price];
					SaveBizData(gVehData[tmpcar][BusinessID], "Till");
					
					Businesses[gVehData[tmpcar][BusinessID]][mIncomeVehicleTotal] += gVehData[tmpcar][Price];
					Businesses[gVehData[tmpcar][BusinessID]][mIncomeVehicleToday] += gVehData[tmpcar][Price];
					Businesses[gVehData[tmpcar][BusinessID]][mIncomeTotal] += gVehData[tmpcar][Price];
					SaveBizData(gVehData[tmpcar][BusinessID], "IncomeVehicleTotal");
					SaveBizData(gVehData[tmpcar][BusinessID], "IncomeVehicleToday");
					SaveBizData(gVehData[tmpcar][BusinessID], "IncomeTotal");

					// informacja dla kupujacego
					SendClientMessage(playerid, COLOR_WHITE, "[INFO:] Kupi³eœ ³ódŸ !");
					SendClientMessage(playerid, COLOR_WHITE, "[INFO:] Skorzystaj z komendy '/pomoc samochod'");

					// zapis
					SaveBizData(gVehData[tmpcar][BusinessID], "VehicleCount");
					SaveFData(FACTIONID_GOVERNMENT, "Bank");

					// log
					format(string, sizeof(string), "Vehicle id [%d] has been bought by %s for %d$", idcar, GetPlayerNameEx(playerid), gVehData[tmpcar][Price]);
					VehicleLog(string);

					return 1;
				}
				if(IsAHelicopter(idcar))
				{
					// sprawdzenie czy gracz posiada odpowiedni level do kupna helikoptera
					if(gPlayerData[playerid][pPlayingHours] < AirKeyLVL)
					{
						format(string, sizeof(string), "[INFO:] Musisz mieæ przegrane co najmniej %d godzin aby kupiæ helikopter",AirKeyLVL);
						SendClientMessage(playerid, COLOR_WHITE, string);
						return 1;
					}

					// sprawdzenie czy gracz posiada wolny slot
					if(!PlayerFreeSlotCount(playerid))
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie masz miejsca na kolejny item !");
						return 1;
					}
					newVehSerial(tmpcar);
					PutPlayerInVehicle(playerid, tmpcar+1, 0);
					slot = InsertPlayerItem(playerid, 2, gVehData[tmpcar][CarSerial], 0, 0);
					gVehData[tmpcar][LastDriverWKey] = gPlayerData[playerid][pName];

					// modyfikacja danych pojazdu
					gVehData[tmpcar][mVehOwned] = 1;
					strmid(gVehData[tmpcar][Owner], gPlayerData[playerid][pName], 0, MAX_PLAYER_NAME, 128);

					SaveVehData(tmpcar, "VehOwned");
					SaveVehData(tmpcar, "Owner");

					// zmniejszenie ilosci pieniedzy gracza
					GivePlayerCash(playerid,-gVehData[tmpcar][Price] - floatround(gVehData[tmpcar][Price] * DynamicTaxes[VatTaxMax],floatround_round));

					// podatki
					DynamicFactions[FACTIONID_GOVERNMENT][fBank] += floatround(gVehData[tmpcar][Price] * DynamicTaxes[VatTaxMax],floatround_round);

					// zwolnienie slotu wlasciciela biznesu
					Businesses[gVehData[tmpcar][BusinessID]][VehicleCount]--;

					// zysk dla wlasciciela biznesu/salonu
					Businesses[gVehData[tmpcar][BusinessID]][Till] += gVehData[tmpcar][Price];
					
					Businesses[gVehData[tmpcar][BusinessID]][mIncomeVehicleTotal] += gVehData[tmpcar][Price];
					Businesses[gVehData[tmpcar][BusinessID]][mIncomeVehicleToday] += gVehData[tmpcar][Price];
					Businesses[gVehData[tmpcar][BusinessID]][mIncomeTotal] += gVehData[tmpcar][Price];
					SaveBizData(gVehData[tmpcar][BusinessID], "IncomeVehicleTotal");
					SaveBizData(gVehData[tmpcar][BusinessID], "IncomeVehicleToday");
					SaveBizData(gVehData[tmpcar][BusinessID], "IncomeTotal");

					// informacja dla kupujacego
					SendClientMessage(playerid, COLOR_WHITE, "[INFO:] Kupi³eœ helikopter !");
					SendClientMessage(playerid, COLOR_WHITE, "[INFO:] Skorzystaj z komendy '/pomoc samochod'");

					// zapis
					SaveBizData(gVehData[tmpcar][BusinessID], "Till");
					SaveBizData(gVehData[tmpcar][BusinessID], "VehicleCount");
					SaveFData(FACTIONID_GOVERNMENT, "Bank");

					// log
					format(string, sizeof(string), "Vehicle id [%d] has been bought by %s for %d$", idcar, GetPlayerNameEx(playerid), gVehData[tmpcar][Price]);
					VehicleLog(string);

					return 1;
				}
				if(IsAPlane(idcar))
				{
					// sprawdzenie czy gracz posiada odpowiedni level do kupna samolotu
					if(gPlayerData[playerid][pPlayingHours] < AirKeyLVL)
					{
						format(string, sizeof(string), "[INFO:] Musisz mieæ przegrane co najmniej %d godzin aby kupiæ samolot",AirKeyLVL);
						SendClientMessage(playerid, COLOR_WHITE, string);
						return 1;
					}

					// sprawdzenie czy gracz posiada wolny slot
					if(!PlayerFreeSlotCount(playerid))
					{
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie masz miejsca na kolejny item !");
						return 1;
					}
					newVehSerial(tmpcar);
					PutPlayerInVehicle(playerid, tmpcar+1, 0);
					slot = InsertPlayerItem(playerid, 2, gVehData[tmpcar][CarSerial], 0, 0);
					gVehData[tmpcar][LastDriverWKey] = gPlayerData[playerid][pName];

					// modyfikacja danych pojazdu
					gVehData[tmpcar][mVehOwned] = 1;
					strmid(gVehData[tmpcar][Owner], gPlayerData[playerid][pName], 0, MAX_PLAYER_NAME, 128);

					SaveVehData(tmpcar, "VehOwned");
					SaveVehData(tmpcar, "Owner");

					// zmniejszenie ilosci pieniedzy gracza
					GivePlayerCash(playerid, -gVehData[tmpcar][Price] - floatround(gVehData[tmpcar][Price] * DynamicTaxes[VatTaxMax],floatround_round));

					// podatki
					DynamicFactions[FACTIONID_GOVERNMENT][fBank] += floatround(gVehData[tmpcar][Price] * DynamicTaxes[VatTaxMax],floatround_round);

					// zwolnienie slotu wlasciciela biznesu
					Businesses[gVehData[tmpcar][BusinessID]][VehicleCount]--;

					// zysk dla wlasciciela biznesu/salonu
					Businesses[gVehData[tmpcar][BusinessID]][Till] += gVehData[tmpcar][Price];
					
					Businesses[gVehData[tmpcar][BusinessID]][mIncomeVehicleTotal] += gVehData[tmpcar][Price];
					Businesses[gVehData[tmpcar][BusinessID]][mIncomeVehicleToday] += gVehData[tmpcar][Price];
					Businesses[gVehData[tmpcar][BusinessID]][mIncomeTotal] += gVehData[tmpcar][Price];
					SaveBizData(gVehData[tmpcar][BusinessID], "IncomeVehicleTotal");
					SaveBizData(gVehData[tmpcar][BusinessID], "IncomeVehicleToday");
					SaveBizData(gVehData[tmpcar][BusinessID], "IncomeTotal");

					// informacja dla kupujacego
					SendClientMessage(playerid, COLOR_WHITE, "[INFO:] Kupi³eœ samolot !");
					SendClientMessage(playerid, COLOR_WHITE, "[INFO:] Skorzystaj z komendy '/pomoc samochod'");

					// zapis
					SaveBizData(gVehData[tmpcar][BusinessID], "Till");
					SaveBizData(gVehData[tmpcar][BusinessID], "VehicleCount");
					SaveFData(FACTIONID_GOVERNMENT, "Bank");

					// log
					format(string, sizeof(string), "Vehicle id [%d] has been bought by %s for %d$", idcar, GetPlayerNameEx(playerid), gVehData[tmpcar][Price]);
					VehicleLog(string);

					return 1;
				}
				if(IsAPlane(idcar) == 0 && IsAHelicopter(idcar) == 0 && IsABoat(idcar) == 0)
				{
					// gracz ma za niski lvl
					if(gPlayerData[playerid][pPlayingHours] < CarKey1LVL)
					{
						format(string, sizeof(string), "[INFO:] Musisz mieæ przegrane co najmneij %d godzin aby kupiæ pierwszy samochód.",CarKey1LVL);
						SendClientMessage(playerid, COLOR_WHITE, string);

						return 1;
					}
					// kupno pierwszego pojazdu
					if(gPlayerData[playerid][pPlayingHours] >= CarKey1LVL)
					{
						// sprawdzenie czy gracz posiada wolny slot
						if(!PlayerFreeSlotCount(playerid))
						{
							SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie masz miejsca na kolejny item !");
							return 1;
						}
						newVehSerial(tmpcar);
						PutPlayerInVehicle(playerid, tmpcar+1, 0);
						newVehSerial(tmpcar);
						slot = InsertPlayerItem(playerid, 2, gVehData[tmpcar][CarSerial], 0, 0);
						gVehData[tmpcar][LastDriverWKey] = gPlayerData[playerid][pName];
						
						// modyfikacja danych pojazdu
						gVehData[tmpcar][mVehOwned] = 1;
						strmid(gVehData[tmpcar][Owner], gPlayerData[playerid][pName], 0, gPlayerData[playerid][pName], 128);

						SaveVehData(tmpcar, "VehOwned");
						SaveVehData(tmpcar, "Owner");

						// zmniejszenie ilosci pieniedzy gracza
						GivePlayerCash(playerid, -gVehData[tmpcar][Price]-floatround(gVehData[tmpcar][Price] * DynamicTaxes[VatTaxMax],floatround_round));

						// podatki
						DynamicFactions[FACTIONID_GOVERNMENT][fBank] += floatround(gVehData[tmpcar][Price] * DynamicTaxes[VatTaxMax],floatround_round);

						// zwolnienie slotu wlasciciela biznesu
						Businesses[gVehData[tmpcar][BusinessID]][VehicleCount]--;

						// zysk dla wlasciciela biznesu/salonu
						Businesses[gVehData[tmpcar][BusinessID]][Till] += gVehData[tmpcar][Price];
						
						Businesses[gVehData[tmpcar][BusinessID]][mIncomeVehicleTotal] += gVehData[tmpcar][Price];
						Businesses[gVehData[tmpcar][BusinessID]][mIncomeVehicleToday] += gVehData[tmpcar][Price];
						Businesses[gVehData[tmpcar][BusinessID]][mIncomeTotal] += gVehData[tmpcar][Price];
						SaveBizData(gVehData[tmpcar][BusinessID], "IncomeVehicleTotal");
						SaveBizData(gVehData[tmpcar][BusinessID], "IncomeVehicleToday");
						SaveBizData(gVehData[tmpcar][BusinessID], "IncomeTotal");

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

							// AddExpPoint(playerid);

							gPlayerData[playerid][pFirstCar] = 1;

							SavePlayerData(playerid, "FirstCar");
						}

						// zapis
						SaveBizData(gVehData[tmpcar][BusinessID], "Till");
						SaveBizData(gVehData[tmpcar][BusinessID], "VehicleCount");
						SaveFData(FACTIONID_GOVERNMENT, "Bank");

						// log
						format(string, sizeof(string), "Vehicle id [%d] has been bought by %s for %d$", idcar, GetPlayerNameEx(playerid), gVehData[tmpcar][Price]);
						VehicleLog(string);

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
				if(gVehData[tmpcar][mVehOwned] == 1 && gVehData[tmpcar][mVehFaction] == 255)
				{
					foreach(Player, i)
					{
						if(gPlayerLogged[i])
						{
							// sprawdzenie czy pojazd nalezy do sprzedajacego
							sellerslot = PHaveItem(i, 2, gVehData[tmpcar][CarSerial]);
							if(sellerslot == 0)
								continue;

							GetPlayerName(i, tmpplname, sizeof(tmpplname));
							if(IsABoat(idcar))
							{		
								// sprawdzenie czy gracz posiada odpowiedni level do kupna lodzi
								if(gPlayerData[playerid][pPlayingHours] < BoatKeyLVL)
								{
									format(string, sizeof(string), "[INFO:] Musisz mieæ przegrane co najmniej %d godzin aby kupiæ ³ódŸ", BoatKeyLVL);
									SendClientMessage(playerid, COLOR_WHITE, string);
									return 1;
								}
								// sprawdzenie czy gracz posiada wolny slot
								if(!PlayerFreeSlotCount(playerid))
								{
									SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie masz miejsca na kolejny item !");
									return 1;
								}
								newVehSerial(tmpcar);
								PutPlayerInVehicle(playerid, tmpcar+1, 0);
								slot = InsertPlayerItem(playerid, 2, gVehData[tmpcar][CarSerial], 0, 0);
								gVehData[tmpcar][LastDriverWKey] = gPlayerData[playerid][pName];
							
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
							if(IsAHelicopter(idcar))
							{
								// sprawdzenie czy gracz posiada odpowiedni level do kupna helikoptera
								if(gPlayerData[playerid][pPlayingHours] < AirKeyLVL)
								{
									format(string, sizeof(string), "[INFO:] Musisz mieæ przegrane co najmniej %d gdzoin aby kupiæ helikopter",AirKeyLVL);
									SendClientMessage(playerid, COLOR_WHITE, string);

									return 1;
								}
								
								// porownanie id gracza kupujacego i sprzedajacego
								if(playerid == i)
								{
									SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie mo¿esz kupiæ w³asnego pojazdu !");
									return 1;
								}
								
								// sprawdzenie czy gracz posiada wolny slot
								if(!PlayerFreeSlotCount(playerid))
								{
									SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie masz miejsca na kolejny item !");
									return 1;
								}
								newVehSerial(tmpcar);
								PutPlayerInVehicle(playerid, tmpcar+1, 0);
								slot = InsertPlayerItem(playerid, 2, gVehData[tmpcar][CarSerial], 0, 0);
								gVehData[tmpcar][LastDriverWKey] = gPlayerData[playerid][pName];

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
							if(IsAPlane(idcar))
							{
								// sprawdzenie czy gracz posiada odpowiedni level do kupna samolotu
								if(gPlayerData[playerid][pPlayingHours] < AirKeyLVL)
								{
									format(string, sizeof(string), "[INFO:] Musisz mieæ przegrane co najmneij %d godzin aby kupiæ samolot",AirKeyLVL);
									SendClientMessage(playerid, COLOR_WHITE, string);
									return 1;
								}
								// porownanie id gracza kupujacego i sprzedajacego
								if(playerid == i)
								{
									SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie mo¿esz kupiæ w³asnego pojazdu !");
									return 1;
								}
								// sprawdzenie czy gracz posiada wolny slot
								if(!PlayerFreeSlotCount(playerid))
								{
									SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie masz miejsca na kolejny item !");
									return 1;
								}
								newVehSerial(tmpcar);
								PutPlayerInVehicle(playerid, tmpcar+1, 0);
								slot = InsertPlayerItem(playerid, 2, gVehData[tmpcar][CarSerial], 0, 0);
								gVehData[tmpcar][LastDriverWKey] = gPlayerData[playerid][pName];

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
							if(IsAPlane(idcar) == 0 && IsAHelicopter(idcar) == 0 && IsABoat(idcar) == 0)
							{
								// gracz ma za niski lvl
								if(gPlayerData[playerid][pPlayingHours] < CarKey1LVL)
								{
									format(string, sizeof(string), "[INFO:] Musisz mieæ przegrane co najmniej %d godzin aby kupiæ pierwszy samochód",CarKey1LVL);
									SendClientMessage(playerid, COLOR_WHITE, string);
									return 1;
								}
								// sprawdzenie czy gracz posiada wolny slot
								if(!PlayerFreeSlotCount(playerid))
								{
									SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie masz miejsca na kolejny item !");
									return 1;
								}
								newVehSerial(tmpcar);
								PutPlayerInVehicle(playerid, tmpcar+1, 0);
								slot = InsertPlayerItem(playerid, 2, gVehData[tmpcar][CarSerial], 0, 0);
								gVehData[tmpcar][LastDriverWKey] = gPlayerData[playerid][pName];

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
					if(sellerID != 999)
					{
						// modyfikacja danych pojazdu
						gVehData[tmpcar][mVehOwned] = 1;
						strmid(gVehData[tmpcar][Owner], gPlayerData[playerid][pName], 0, MAX_PLAYER_NAME, 128);

						// zmniejszenie ilosci pieniedzy gracza kupujacego
						GivePlayerCash(playerid, -gVehData[tmpcar][Price]);

						// zwiekszenie ilosci pieniedzy gracza sprzedajacego
						GivePlayerCash(sellerID, gVehData[tmpcar][Price]);

						// zresetowanie sprzedazy pojazdu
						gVehData[tmpcar][ReadyToSell] = 0;

						// usuniecie informacji sprzedazy z nad pojazdu
						DestroyDynamic3DTextLabel(gVehData[tmpcar][Veh3DSell]);

						// zapis
						SaveVehData(tmpcar, "ReadyToSell");
						SaveVehData(tmpcar, "VehOwned");
						SaveVehData(tmpcar, "Owner");

						// log
						format(string, sizeof(string), "Vehicle id [%d] has been bought by %s for %d$ from %s", idcar, GetPlayerNameEx(playerid), gVehData[tmpcar][Price], GetPlayerNameEx(sellerID));
						VehicleLog(string);

						return 1;
					}
					else
					{
						SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Sprzedawcy nie ma obecnie na serwerze, nie mo¿esz kupiæ tego pojazdu w tej chwili");
						return 1;
					}
				}
				// pojazd uzywany - frakcyjny
				if(gVehData[tmpcar][mVehOwned] == 0 && gVehData[tmpcar][mVehFaction] != 255)
				{
					if(IsAHelicopter(idcar))
					{
						// sprawdzenie czy gracz posiada odpowiedni level do kupna helikoptera
						if(gPlayerData[playerid][pPlayingHours] < AirKeyLVL)
						{
							format(string, sizeof(string), "[INFO:] Musisz mieæ przegrane co najmniej %d godzin aby kupiæ helikopter",AirKeyLVL);
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
						if(gPlayerData[playerid][pPlayingHours] < AirKeyLVL)
						{
							format(string, sizeof(string), "[INFO:] Musisz mieæ przegrane co najmniej %d godzin aby kupiæ samolot",AirKeyLVL);
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
						if(gPlayerData[playerid][pPlayingHours] < CarKey1LVL)
						{
							format(string, sizeof(string), "[INFO:] Musisz mieæ przegrane co najmniej %d godzin aby kupiæ pierwszy samochód",CarKey1LVL);
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
					if(DynamicFactions[gVehData[tmpcar][mVehFaction]][fCarsCount] > 0)
					{
						// zmniejszenie licznika pojazdow frakcji
						DynamicFactions[gVehData[tmpcar][mVehFaction]][fCarsCount]--;

						SaveFData(gVehData[tmpcar][mVehFaction], "CarsCount");
					}

					// zysk dla frakcji
					DynamicFactions[gVehData[tmpcar][mVehFaction]][fBank] += gVehData[tmpcar][Price];

					SaveFData(gVehData[tmpcar][mVehFaction], "Bank");

					if(DynamicFactions[ gVehData[tmpcar][mVehFaction] ][fType] == 6)
					{
						DestroyDynamic3DTextLabel(gVehData[tmpcar][Veh3DTaxiNfo]);
						DestroyDynamic3DTextLabel(gVehData[tmpcar][Veh3DTaxiNfo2]);
					}
					
					// modyfikacja danych pojazdu
					gVehData[tmpcar][mVehType] = 0;
					gVehData[tmpcar][mVehOwned] = 1;
					strmid(gVehData[tmpcar][Owner], plname, 0, strlen(plname), 128);
					gVehData[tmpcar][mVehFaction] = 255;
					gVehData[tmpcar][ReadyToSell] = 0;

					SaveVehData(tmpcar, "VehType");
					SaveVehData(tmpcar, "VehOwned");
					SaveVehData(tmpcar, "Owner");
					SaveVehData(tmpcar, "VehFaction");
					SaveVehData(tmpcar, "ReadyToSell");

					// usuniecie informacja sprzedazy z nad pojazdu
					DestroyDynamic3DTextLabel(gVehData[tmpcar][Veh3DSell]);

					// log
					new Year, Month, Day;
					getdate(Year, Month, Day);
					printf("[%d-%d-%d] [VEHICLE:] Vehicle id [%d] has been bought by %s from faction ID: %d for %d$", Year, Month, Day, idcar, GetPlayerNameEx(playerid), gVehData[tmpcar][mVehFaction], gVehData[tmpcar][Price]);

					return 1;
				}
				if(gVehData[tmpcar][mVehOwned] == 1 && gVehData[tmpcar][mVehFaction] != 255)
				{
					SendClientMessage(playerid, COLOR_RED, "[INFO:] Wyst¹pi³ problem z tym pojazdem. Skontaktuj siê z administratorem. Lista administratorów: /admini");
					return 1;
				}
			}
			return 1;
		}
		else if(strcmp(cmd, "/zezlomujpojazd", true) == 0 || strcmp(cmd, "/dsveh", true) == 0)
		{
			if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
			{
				new slot[MAX_PLAYER_ITEM_SLOT], match;
				if(PHaveItemParam5Ex(playerid, 3, 19, gPlayerData[playerid][pName]) == -1)
				{
					SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie posiadasz dowodu rejestracyjnego tego pojazdu");
					return 1;
				}
				for(new i = 0; i < MAX_PLAYER_ITEM_SLOT; i++)
				{
					if(slot[i])
					{
						match = i+1;
						break;
					}
				}
				if(!match)
				{
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie posiadasz kluczyków do tego pojazdu !");
					return 1;
				}
				// Cena za samochod
				if(gPlayerData[playerid][pAdmin] >= 2)
				{
					DestroyVehicle(idcar);
					defer ResetVehicleData(idcar,1);
					format(string, sizeof(string), "[INFO:] Zez³omowa³eœ pojazd !");
					TogglePlayerControllable(playerid, 1);
					SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
				}
				else if(gPlayerData[playerid][pAdmin] <= 2)
				{
					if(floatround(gVehData[tmpcar][Price] * 0.20, floatround_round) < gPlayerData[playerid][pCash])
					{
						if(IsABoat(idcar) == 0 && IsAPlane(idcar) == 0 && IsAHelicopter(idcar) == 0)
						{
							if(gVehData[tmpcar][mVehOwned] == 1 && strcmp(gPlayerData[playerid][pName], gVehData[tmpcar][Owner], false) == 0)
							{
								if(PlayerToPoint(50.0, playerid, -1854.0, -1679.0, 22.0))
								{
									DestroyVehicle(idcar);
									defer ResetVehicleData(idcar,1);
									format(string, sizeof(string), "[INFO:] Zez³omowa³eœ swój samochód");
									SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
									format(string, sizeof(string), "[INFO:] Koszt z³omowania %d$", floatround(float(gVehData[tmpcar][Price]) * 0.20, floatround_round));
									SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
									DynamicFactions[FACTIONID_GOVERNMENT][fBank] += floatround(gVehData[tmpcar][Price] * 0.20, floatround_round);
									SaveFData(FACTIONID_GOVERNMENT, "Bank");
									GivePlayerCash(playerid,-(floatround(gVehData[tmpcar][Price] * 0.20, floatround_round)));
									TogglePlayerControllable(playerid, 1);
									RemovePlayerItemExUsed(playerid, match);
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
							if(gVehData[tmpcar][mVehOwned] == 1 && strcmp(gPlayerData[playerid][pName], gVehData[tmpcar][Owner], false) == 0)
							{
								if(PlayerToPoint(8.0, playerid, 2505.0, -2715.0, 0.0))
								{
									DestroyVehicle(idcar);
									defer ResetVehicleData(idcar,1);
									format(string, sizeof(string), "[INFO:] Zez³omowa³eœ swoj¹ ³ódŸ");
									SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
									format(string, sizeof(string), "[INFO:] Koszt z³omowania %d$", floatround(gVehData[tmpcar][Price] * 0.20, floatround_round));
									SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
									DynamicFactions[FACTIONID_GOVERNMENT][fBank] += floatround(gVehData[tmpcar][Price] * 0.20, floatround_round);
									SaveFData(FACTIONID_GOVERNMENT, "Bank");
									GivePlayerCash(playerid,-(floatround(gVehData[tmpcar][Price] * 0.20, floatround_round)));
									TogglePlayerControllable(playerid, 1);
									RemovePlayerItemExUsed(playerid, match);
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
							if(gVehData[tmpcar][mVehOwned] == 1 && strcmp(gPlayerData[playerid][pName], gVehData[tmpcar][Owner], false) == 0)
							{
								if(PlayerToPoint(50.0, playerid, 365.0, 2537.0, 17.0))
								{
									DestroyVehicle(idcar);
									defer ResetVehicleData(idcar,1);
									format(string, sizeof(string), "[INFO:] Zez³omowa³eœ swój helikopter");
									SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
									format(string, sizeof(string), "[INFO:] Koszt z³omowania %d$", floatround(gVehData[tmpcar][Price] * 0.20, floatround_round));
									SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
									DynamicFactions[FACTIONID_GOVERNMENT][fBank] += floatround(gVehData[tmpcar][Price] * 0.20, floatround_round);
									SaveFData(FACTIONID_GOVERNMENT, "Bank");
									GivePlayerCash(playerid,-(floatround(gVehData[tmpcar][Price] * 0.20, floatround_round)));
									TogglePlayerControllable(playerid, 1);
									RemovePlayerItemExUsed(playerid, match);
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
							if(gVehData[tmpcar][mVehOwned] == 1 && strcmp(gPlayerData[playerid][pName], gVehData[tmpcar][Owner], false) == 0)
							{
								if(PlayerToPoint(50.0, playerid, 365.0, 2537.0, 17.0))
								{
									DestroyVehicle(idcar);
									defer ResetVehicleData(idcar,1);
									format(string, sizeof(string), "[INFO:] Zez³omowa³eœ swój samolot");
									SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
									format(string, sizeof(string), "[INFO:] Koszt z³omowania %d$", floatround(float(gVehData[tmpcar][Price]) * 0.20, floatround_round));
									SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
									DynamicFactions[FACTIONID_GOVERNMENT][fBank] += floatround(float(gVehData[tmpcar][Price]) * 0.20, floatround_round);
									SaveFData(FACTIONID_GOVERNMENT, "Bank");
									GivePlayerCash(playerid,-(floatround(float(gVehData[tmpcar][Price]) * 0.20, floatround_round)));
									TogglePlayerControllable(playerid, 1);
									RemovePlayerItemExUsed(playerid, match);
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
		else if(strcmp(cmd, "/zaparkuj", true) == 0)
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
							if(gVehData[tmpcar][mVehModel] == 431 || gVehData[tmpcar][mVehModel] == 437 || gVehData[tmpcar][mVehModel] == 507 || gVehData[tmpcar][mVehModel] == 408 || gVehData[tmpcar][mVehModel] == 574)
							{
								GetVehiclePos(idcar, gVehData[tmpcar][mVehX], gVehData[tmpcar][mVehY], gVehData[tmpcar][mVehZ]);
								GetVehicleZAngle(idcar, gVehData[tmpcar][mVehX]);
								GetVehicleHealth(idcar, gVehData[tmpcar][CarHealth]);

								SaveVehData(tmpcar, "VehPos");

								DestroyVehicle(idcar);
								CreateVehicle(gVehData[tmpcar][mVehModel], gVehData[tmpcar][mVehX], gVehData[tmpcar][mVehY], gVehData[tmpcar][mVehZ], gVehData[tmpcar][mVehA], gVehData[tmpcar][mVehColor1], gVehData[tmpcar][mVehColor2], -1);
								PutPlayerIntoVehicle(playerid, idcar, 0);
								SetVehicleHealth(idcar, gVehData[tmpcar][CarHealth]);
								SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Zaparkowa³eœ pojazd s³u¿b publicznych !");
							}
						}
					}
				}
			}
			return 1;
		}
		else if(strcmp(cmd, "/acarprice", true) == 0)
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
		else if(strcmp(cmd, "/acarowner", true) == 0)
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
				defer ResetVehicleData(tmpcar+1,1);
				TogglePlayerControllable(playerid,1);
				format(string, sizeof(string), "[INFO:] Zresetowa³eœ w³aœciciela samochodu ID %d na %s", tmpcar+1,gVehData[tmpcar][Owner]);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			}
			else
			{
				strdel(gVehData[tmpcar][Owner], 0, 128);
				strins(gVehData[tmpcar][Owner], tmp, 0, 128);

				gVehData[tmpcar][mVehOwned] = 1;
				gVehData[tmpcar][Closed] = 0;

				GetVehiclePos(idcar, x, y, z);
				GetVehicleZAngle(idcar, a);

				gVehData[tmpcar][mVehX] = x;
				gVehData[tmpcar][mVehY] = y;
				gVehData[tmpcar][mVehZ] = z;
				gVehData[tmpcar][mVehA] = a;

				PutPlayerIntoVehicle(playerid,idcar,0);

				SaveVehData(tmpcar, "VehOwned");
				SaveVehData(tmpcar, "VehPos");
				SaveVehData(tmpcar, "Owner");
				SaveVehData(tmpcar, "Closed");

				printf("[WARNING:] Vehicle id %d set to: %s by %s", idcar, gVehData[tmpcar][Owner], GetPlayerNameEx(playerid));

				format(string, sizeof(string), "[INFO:] Zmieni³eœ w³aœciciela samochodu ID %d na %s", tmpcar+1,gVehData[tmpcar][Owner]);
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
				
				printf("[WARNING:] /acarowner used by %s, veh id: %d, owner changed to %s", gPlayerData[playerid][pName], tmpcar+1, gVehData[tmpcar][Owner]);
			}
			return 1;
		}
		else if(strcmp(cmd, "/aplayerfaction", true) == 0)
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
		else if(strcmp(cmd, "/asetplayerfaction", true) == 0)
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
			return 1;
		}
		else if(strcmp(cmd, "/asetplayerfaction2", true) == 0)
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
			tmp = strtok(cmdtext, idx);
			rank = strval(tmp);
			if(rank >= 1 && rank <= 10)
			{
				gPlayerData[giveplayerid][pFaction2] = fraction;
				gPlayerData[giveplayerid][pRank2] = rank;
				format(string, sizeof(string), "[INFO:] Frakcja gracza %d zosta³a zmieniona na: %d, ranga: %d, przez %s", giveplayerid, fraction, rank, GetPlayerNameEx(playerid));
				SendAdminMessage(COLOR_YELLOW, string);
				gPlayerData[playerid][pJoinedFaction] = gettime();
				SavePlayerData(giveplayerid, "Faction2");
				SavePlayerData(giveplayerid, "Rank2");
				SavePlayerData(giveplayerid, "JoinedFaction");
			}
			else
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /asetplayerfaction [playerid] [frakcja] [ranga]");
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "Ranga musi byæ z zakresu od 1 do 10 lub 0 dla frakcji 255");
			}
			return 1;
		}
		else if(strcmp(cmd, "/opuscfrakcje", true) == 0)
		{
			if(gPlayerData[playerid][pFaction] == 255)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie nale¿ysz do ¿adnej frakcji !");
				return 1;
			}
			if(gPlayerData[playerid][pRank] == 1)
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz opuœciæ frakcji bêd¹c jej liderem !");
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Musisz usun¹æ frakcje lub przekaæ lidera aby opuœciæ frakcje");
				return 1;
			}
			gPlayerData[playerid][pFaction] = 255;
			gPlayerData[playerid][pRank] = 1;
			SavePlayerData(playerid, "Faction");
			SavePlayerData(playerid, "Rank");
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Gratulacje, odeszles z frakcji");
			return 1;
		}
		else if(strcmp(cmd, "/asetlicenceplate", true) == 0)
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
			SetVehicleToRespawnEx(idcar);
			new tmpstring[128];
			format(tmpstring, sizeof(tmpstring), "[INFO:] Ustawi³eœ rejestracje samochodu na: %s", tmp);
			SendClientMessage(playerid, COLOR_YELLOW, tmpstring);
			return 1;
		}
		else if(strcmp(cmd, "/explosion", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 1)
				return 0;
			new Float:x, Float:y, Float:z;
			GetPlayerPos(playerid, x, y, z);
			CreateExplosion(x+10, y, z, 7, 10.0);
			return 1;
		}
		else if(strcmp(cmd, "/przyczepnaczepe", true) == 0)
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
							if(gVehData[GetPlayerVehicleID(playerid)-1][mVehModel] == IsATruck(idcar))
							{
								AttachTrailerToVehicle(i, idcar);
							}
							else
							{
								SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz holowaæ tym pojazdem");
							}
						}
					}
				}
				return 1;
			}
			return 1;
		}
		else if(strcmp(cmd, "/przyczepprzyczepe", true) == 0)
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
							if(gVehData[GetPlayerVehicleID(playerid)-1][mVehModel] == IsALorry(idcar))
							{
								AttachTrailerToVehicle(i, idcar);
							}
							else
							{
								SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz holowaæ tym pojazdem");
							}
						}
					}
				}
				return 1;
			}
			return 1;
		}
		else if(strcmp(cmd, "/acardata", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 1)
				return 0;
			if(!IsPlayerInVehicle(playerid, idcar))
				return 1;
			new Float:emmision;
			VehCo2Emmision(idcar, emmision);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "___________________________________________________");
			format(string, sizeof(string), "ID: %d, Model: %d, Faction: %d, Type: %d, BizID: %d, CarSerial: %d", idcar, GetVehicleModel(idcar), gVehData[tmpcar][mVehFaction], gVehData[tmpcar][mVehType], gVehData[tmpcar][BusinessID], gVehData[tmpcar][CarSerial]);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			format(string, sizeof(string), "Bought: %d, Owner: %s, Price: %d, ReadyToSell: %d, Alarm: %d", gVehData[tmpcar][mVehOwned], gVehData[tmpcar][Owner], gVehData[tmpcar][Price], gVehData[tmpcar][ReadyToSell], gVehData[tmpcar][Alarm]);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			format(string, sizeof(string), "Hook: %d, Damaged: %d, Repair Time Left: %d min, CarResetT: %d, Fuel Type: %d, Battery: %f, Confiscated: %d", gVehData[tmpcar][Hook], gVehData[tmpcar][CarDamaged], gVehData[tmpcar][CarRepairTimeLeft]*10, gVehData[tmpcar][CarResetT], gVehData[tmpcar][Fuel], gVehData[tmpcar][BatteryCapacity], gVehData[tmpcar][VConfiscated]);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			format(string, sizeof(string), "Co2 emmision: %f, VIN: %d", emmision, gVehData[tmpcar][mVehVinNo]); 
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "___________________________________________________");
			return 1;
		}
		else if(strcmp(cmd, "/sprawdznumer", true) == 0)
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
		else if(strcmp(cmd, "/camera1", true) == 0)
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
		else if(strcmp(cmd, "/angle", true) == 0)
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
		else if(strcmp(cmd, "/camera2", true) == 0)
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
		else if(strcmp(cmd, "/walczoterytorium", true) == 0)
		{
			if(gPlayerData[playerid][pFaction] == 255)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Niew³aœciwa frakcja !");
				return 1;
			}
			if(DynamicFactions[gPlayerData[playerid][pFaction]][fType] != 3)
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie jesteœ liderem gangu !");
				return 1;
			}
			if(!CheckRankPrivilidges(gPlayerData[playerid][pFaction], gPlayerData[playerid][pRank], "walczoterytorium"))
			{
				SendClientMessage(playerid, COLOR_RED, "[INFO:] Nie posiadasz uprawnieñ do rozpoczynania wojny o terytorium !");
				return 1;
			}
			for(new i = 0; i < sizeof(DynamicZones); i++)
			{
				if(IsPlayerInArea(playerid, DynamicZones[i][mPosMaxX], DynamicZones[i][mPosMinX], DynamicZones[i][mPosMaxY], DynamicZones[i][mPosMinY]))
				{
					if(DynamicZones[i][mFaction] == gPlayerData[playerid][pFaction])
					{
						SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Nie mo¿esz walczyæ o w³asne terytorium !");
						return 1;
					}
					if(gGangWar[Enabled] == 1)
						SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Ju¿ trwa jedna wojna gangów o terytorium.");
					else
					{
						gGangWar[Enabled] = 1;
						gGangWar[TimeLeft] = 30; // 1 = 1minuta
						gGangWar[FactionStartedKills] = 0;
						gGangWar[FactionAttackedKills] = 0;
						gGangWar[FactionStarted] = gPlayerData[playerid][pFaction];
						gGangWar[FactionAttacked] = DynamicZones[i][mFaction];						
						gGangWar[AreaID] = i;
						foreach(Player, n)
							GangZoneFlashForPlayer(n, i, DynamicFactions[ DynamicZones[i][mFaction] ][fColor]);
						SendClientMessageToAll(COLOR_LIGHTYELLOW2, "[INFO:] Walka o terytorium rozpoczêta !");
					}
					return 1;
				}
			}
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Nie znajdujesz sie na ¿adnym terytorium !");
			return 1;			
		}
		else if(strcmp(cmd, "/awartimeleft", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] < 4)
				return 0;
			format(string, sizeof(string), "[INFO:] WarTimeCountdown: %d", WarTimeCountdown);
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			return 1;
		}
		else if(strcmp(cmd, "/awartimestart", true) == 0)
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
		else if(strcmp(cmd, "/agetcar", true) == 0)
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
				SetVehicleToPos(carID, playerX, playerY, playerZ);
			LinkVehicleToInterior(carID, GetPlayerInterior(playerid));
			SetVehicleVirtualWorld(carID, GetPlayerVirtualWorld(playerid));
			gVehData[carID-1][mVehVW] = GetPlayerVirtualWorld(playerid);
			gVehData[carID-1][mVehInt] = GetPlayerInterior(playerid);
			SaveVehData(carID-1, "VehVW");
			SaveVehData(carID-1, "VehInt");
			return 1;
		}
		else if(strcmp(cmd, "/agetcar2", true) == 0)
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
				SetVehiclePos(carID, playerX, playerY + 5, playerZ);
			else if(playerAngle > 45.0 && playerAngle < 135.0)
				SetVehiclePos(carID, playerX - 5, playerY, playerZ);
			else if(playerAngle > 135.0 && playerAngle < 225.0)
				SetVehiclePos(carID, playerX, playerY - 5, playerZ);
			else if(playerAngle > 225.0 && playerAngle < 315)
				SetVehiclePos(carID, playerX + 5, playerY, playerZ);
			else
				SetVehiclePos(carID, playerX, playerY, playerZ);
			LinkVehicleToInterior(carID, GetPlayerInterior(playerid));
			SetVehicleVirtualWorld(carID, GetPlayerVirtualWorld(playerid));
			gVehData[carID-1][mVehVW] = GetPlayerVirtualWorld(playerid);
			gVehData[carID-1][mVehInt] = GetPlayerInterior(playerid);
			SaveVehData(carID-1, "VehVW");
			SaveVehData(carID-1, "VehInt");
			return 1;
		}
		else if(strcmp(cmd, "/agetcars", true) == 0)
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
						SetVehicleToPos(carID+1, playerX, playerY, playerZ);
						LinkVehicleToInterior(carID+1, GetPlayerInterior(playerid));
						SetVehicleVirtualWorld(carID+1, GetPlayerVirtualWorld(playerid));
						gVehData[carID-1][mVehVW] = GetPlayerVirtualWorld(playerid);
						gVehData[carID-1][mVehInt] = GetPlayerInterior(playerid);
						SaveVehData(carID-1, "VehVW");
						SaveVehData(carID-1, "VehInt");
					}
					return 1;
				}
			}
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] No such car with that serial");
			return 1;
		}
		else if(strcmp(cmd, "/asetplayervipafk", true) == 0)
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
				if(playervipafk < 0 || playervipafk > 1) { SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] 0-1."); return 1; }
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
		else if(strcmp(cmd, "/afuelcar", true) == 0)
		{
			if(gPlayerData[playerid][pAdmin] != 5)
				return 0;
			gVehData[tmpcar][CarFuel] = float(VehFTank(tmpcar+1));
			printf("[WARNING:] %s used /afuelcar", gPlayerData[playerid][pName]);
			return 1;
		}
		else if(strcmp(cmd, "/aplay", true) == 0)
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
			foreach(Player, i)
			{
				Audio_Play(playerid, idtmp, false, false, false);
				Audio_Set3DPosition(i, handleid, -1281.046,-2113.415,26.866, 150);
			}
			printf("idtmp %d, handleid %d", idtmp, handleid);
			return 1;
		}
		else if(strcmp(cmd, "/asetplayervipexp", true) == 0)
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
				if(playervipexp < 0 || playervipexp > 1) { SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] 0-1."); return 1; }
				gPlayerData[giveplayerid][pVipExp] = playervipexp;
				format(string, sizeof(string), "[INFO:] VipExp status for player: %d was set to: %d by %s", giveplayerid, playervipexp, GetPlayerNameEx(playerid));
				SendAdminMessage(COLOR_YELLOW, string);
				SavePlayerData(playervipexp, "VipExp");
				return 1;
			}
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Gracz od danym ID nie jest ON-LINE");
			return 1;
		}
		else if(strcmp(cmd, "/asetplayervipafk", true) == 0)
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
				if(playervipafk < 0 || playervipafk > 1) { SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] 0-1."); return 1; }
				gPlayerData[giveplayerid][pVipAFK] = playervipafk;
				format(string, sizeof(string), "[INFO:] VipAFK status for player: %d was set to: %d by %s", giveplayerid, playervipafk, GetPlayerNameEx(playerid));
				SendAdminMessage(COLOR_YELLOW, string);
				SavePlayerData(playerid, "VipAFK");
				return 1;
			}
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Gracz od danym ID nie jest ON-LINE");
			return 1;
		}
		else if(strcmp(cmd, "/asetplayervipafkt", true) == 0)
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
				if(playervipafkt < 0 || playervipafkt > 1) { SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] 0-1."); return 1; }
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
		else if(strcmp(cmd, "/mechanicy", true) == 0)
		{
			new count = 0;
			// CreateDynamicPickup(1239,2,-1855,127,15,0,-1,-1,50.0); // biuro mechaników
			if(!PlayerToPoint(3.0,playerid,-1855.0,127.0,15.0) && !PlayerToPoint(3.0,playerid,613.0,4.0,1001.0))
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] Musisz znajdowaæ siê w biurze mechaników !");
				return 1;
			}
			SendClientMessage(playerid, COLOR_LIGHTGREEN, "----------[MECHANICY]----------");
			foreach(Player, i)
			{
				if(!gPlayerLogged[i])
					continue;
				if(gPlayerData[i][pJob] == 17)
				{
					format(string, 128, "* %s ", GetPlayerNameEx(i));
					SendClientMessage(playerid, COLOR_WHITE, string);
					count++;
				}
			}
			if(count == 0)
			{
				SendClientMessage(playerid,COLOR_WHITE, "[INFO:] Aktualnie brak mechaników bêd¹cych w pracy");
			}
			SendClientMessage(playerid, COLOR_LIGHTGREEN, "----------------------------------------------------------");
			return 1;
		}
		else if(strcmp(cmd, "/pw", true) == 0)
		{
			tmp = strtok(cmdtext, idx);
			if(!strlen(tmp))
			{
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] /pw [playerid] [treœæ]");
				return 1;
			}
			if((nopwooc) && gPlayerData[playerid][pAdmin] < 1)
			{
				SendClientMessage(playerid, COLOR_GRAD2, "[INFO:] Chat PWOOC zosta³ wy³¹czony przez administratora !");
				return 1;
			}
			if(!gPlayerData[playerid][pPWStatus])
			{
				SendClientMessage(playerid, COLOR_ORANGE, "[INFO:] W³¹cz PW przed wys³aniem wiadomoœci");
				return 1;
			}
			giveplayerid = ReturnUser(tmp);
			if(IsPlayerConnected(giveplayerid) && gPlayerLogged[giveplayerid])
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
						format(string, sizeof(string), "[PW][%d][F: %s]: %s", playerid, gPlayerData[playerid][pOOCName], result);
						foreach(Player, i)
						{
							if(!gPlayerLogged[i])
								continue;
							if(BigEar[i])
							{
								SendClientMessage(i, COLOR_DARKBROWN, string);
							}
						}
						SendClientMessage(giveplayerid, COLOR_DARKBROWN, string);
						SendClientMessage(playerid, COLOR_DARKBROWN, string);
						// if(!(gPlayerData[playerid][pAdmin] > 0) && GetPlayerState(playerid) != 9)
						// {
							// PlayerActionMessage(playerid,5.0, "pisze PW.");
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
						SendClientMessage(playerid,COLOR_LIGHTYELLOW2, "[INFO:] Nie mo¿esz pisaæ sam do siebie.");
					}
					return 1;
				}
			}
			else
			{
				format(string, sizeof(string), "[INFO:] Gracz o id %d nie jest po³¹czony.", strval(tmp));
				SendClientMessage(playerid, COLOR_LIGHTYELLOW2, string);
			}
			return 1;
		}
		else if(strcmp(cmd, "/asetplayervipexpt", true) == 0)
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
				if(playervipexpt < 0 || playervipexpt > 1) { SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] 0-1."); return 1; }
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
		else if(strcmp(cmd, "/pojazdy", true) == 0)
		{
			SendClientMessage(playerid, COLOR_YELLOW, "______________________Pojazdy______________________");
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
		else if(strcmp(cmd, "/samochody1", true) == 0)
		{
			SendClientMessage(playerid, COLOR_YELLOW, "______________________Samochody___________________");
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
		else if(strcmp(cmd, "/samochody2", true) == 0)
		{
			SendClientMessage(playerid ,COLOR_YELLOW, "______________________Samochody___________________");
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
		else if(strcmp(cmd, "/samochody3", true) == 0)
		{	
			SendClientMessage(playerid, COLOR_YELLOW, "______________________Samochody___________________");
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
		else if(strcmp(cmd, "/samochody4", true) == 0)
		{
			SendClientMessage(playerid, COLOR_YELLOW, "______________________Samochody___________________");
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
		else if(strcmp(cmd, "/samochody5", true) == 0)
		{
			SendClientMessage(playerid, COLOR_YELLOW, "______________________Samochody___________________");
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
		else if(strcmp(cmd, "/samochody6", true) == 0)
		{
			SendClientMessage(playerid, COLOR_YELLOW, "______________________Samochody___________________");
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
		else if(strcmp(cmd, "/samochody7", true) == 0)
		{
			SendClientMessage(playerid, COLOR_YELLOW, "______________________Samochody___________________");
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
		else if(strcmp(cmd, "/samochody8", true) == 0)
		{
			SendClientMessage(playerid ,COLOR_YELLOW, "______________________Samochody___________________");
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
		else if(strcmp(cmd, "/samochody9", true) == 0)
		{
			SendClientMessage(playerid, COLOR_YELLOW, "______________________Samochody___________________");
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
		else if(strcmp(cmd, "/samochody10", true) == 0)
		{
			SendClientMessage(playerid, COLOR_YELLOW, "______________________Samochody___________________");
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
		else if(strcmp(cmd, "/samochody11", true) == 0)
		{
			SendClientMessage(playerid, COLOR_YELLOW, "______________________Samochody___________________");
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
		else if(strcmp(cmd, "/samochody12", true) == 0)
		{
			SendClientMessage(playerid, COLOR_YELLOW, "______________________Samochody___________________");
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
		else if(strcmp(cmd, "/samochody13", true) == 0)
		{
			SendClientMessage(playerid, COLOR_YELLOW, "______________________Samochody___________________");
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
		else if(strcmp(cmd, "/samochody14", true) == 0)
		{
			SendClientMessage(playerid, COLOR_YELLOW, "______________________Samochody___________________");
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
		else if(strcmp(cmd, "/motory", true) == 0)
		{
			SendClientMessage(playerid, COLOR_YELLOW, "______________________Motory___________________");
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
		else if(strcmp(cmd, "/rowery", true) == 0)
		{
			SendClientMessage(playerid ,COLOR_YELLOW, "______________________Rowery___________________");
			SendClientMessage(playerid, COLOR_RED, "Pierwsza czêœæ spisu rowerów.");
			SendClientMessage(playerid, COLOR_GREY, "Bike - 509 - 700$");
			SendClientMessage(playerid, COLOR_GREY, "BMX - 481 - 900$");
			SendClientMessage(playerid, COLOR_GREY, "Mountian Bike - 510 - 1.200$");
			return 1;
		}
		else if(strcmp(cmd, "/helikoptery", true) == 0)
		{
			SendClientMessage(playerid, COLOR_YELLOW, "______________________Helikoptery___________________");
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
		else if(strcmp(cmd, "/samoloty", true) == 0)
		{
			SendClientMessage(playerid, COLOR_YELLOW, "______________________Samoloty___________________");
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
		else if(strcmp(cmd, "/lodzie", true) == 0)
		{
			SendClientMessage(playerid, COLOR_YELLOW, "______________________Samochody___________________");
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
		else
		{
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Niew³aœciwa komenda, spróbuj /komendy");
			return 1;
		}
		return 1;
	}
 	SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Jesteœ nie zalogowany - u¿yj /loguj aby sie zalogowaæ");
	return 1;
} // end of OnPlayerCommandText