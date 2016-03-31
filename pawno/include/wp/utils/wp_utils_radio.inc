/***
*
* File: wp_utils_radio.inc
* Auth: Damian Wojdat
* Date: 17.04.2012
* Desc: Internal script function related to in game and internet radio.
*
*************************************************************************************************************/

stock PlayCarRadioStation(playerid, stationid, vehicleid)
{
	new adres[256];	

	StopAudioStreamForPlayer(playerid);

	switch(stationid)
	{
		case 1: adres = "http://radioparty.pl/play/glowny_96.m3u";
		case 2: adres = "http://radioparty.pl/play/djmixes_96.m3u";
		case 3: adres = "http://radioparty.pl/play/house_96.m3u";
		case 4: adres = "http://radioparty.pl/play/trance_96.m3u";
		case 5: adres = "http://radioparty.pl/play/vtrance_96.m3u";
		case 6: adres = "http://radioparty.pl/play/energy2000_96.m3u";
		case 7: adres = "http://radioparty.pl/play/ambeat_96.m3u";
		case 8: adres = "http://www.radiohoryzont.pl/listen.m3u";
		case 9: adres = "http://radiozetmp3-07.eurozet.pl:8400/listen.pls";
		case 10: adres = "http://www.miastomuzyki.pl/n/rmfclassic.pls";
		case 11: adres = "http://www.miastomuzyki.pl/n/rmffm.pls";
		case 12: adres = "http://lodz.radio.pionier.net.pl:8000/pl/eskarock.mp3.m3u";
		case 13: adres = "http://poznan5-2.radio.pionier.net.pl:8000/eska-warszawa.mp3.m3u";
		case 14: adres = "http://www.polskastacja.pl/play/discopolohq.pls";
		case 15: adres = "http://listen.technobase.fm/dsl.pls";
		case 16: adres = "http://listen.slotex.pl/7810.pls";
		case 17: adres = "http://www.tuba.fm/stream.pls?radio=7&mp3=1";
		case 18: adres = "http://94.23.89.48:7300/listen.pls";
		default: return 0;
	}
	
	PlayAudioStreamForPlayer(playerid, adres);
	
	gVehData[vehicleid-1][RadioOn] = stationid;
	SaveVehData(vehicleid-1, "RadioOn");
	
	foreach(Player, i )
	{
		if(i == playerid)
		{
			continue;
		}

		if(IsPlayerInVehicle(i, vehicleid))
		{
			StopAudioStreamForPlayer(i);
			
			PlayAudioStreamForPlayer(i, adres);
		}
	}
	
	return 1;
}

stock ResumeCarRadioStation(playerid, stationid)
{
	new adres[256];
	if(CarRadioID[playerid] != 255)
	{
		// Audio_Stop(playerid, CarRadioID[playerid]);
		StopAudioStreamForPlayer(playerid);
	}

	switch(stationid)
	{
		case 1: adres = "http://radioparty.pl/play/glowny_96.m3u";
		case 2: adres = "http://radioparty.pl/play/djmixes_96.m3u";
		case 3: adres = "http://radioparty.pl/play/house_96.m3u";
		case 4: adres = "http://radioparty.pl/play/trance_96.m3u";
		case 5: adres = "http://radioparty.pl/play/vtrance_96.m3u";
		case 6: adres = "http://radioparty.pl/play/energy2000_96.m3u";
		case 7: adres = "http://radioparty.pl/play/ambeat_96.m3u";
		case 8: adres = "http://www.radiohoryzont.pl/listen.m3u";
		case 9: adres = "http://radiozetmp3-07.eurozet.pl:8400/listen.pls";
		case 10: adres = "http://www.miastomuzyki.pl/n/rmfclassic.pls";
		case 11: adres = "http://www.miastomuzyki.pl/n/rmffm.pls";
		case 12: adres = "http://lodz.radio.pionier.net.pl:8000/pl/eskarock.mp3.m3u";
		case 13: adres = "http://poznan5-2.radio.pionier.net.pl:8000/eska-warszawa.mp3.m3u";
		case 14: adres = "http://www.polskastacja.pl/play/discopolohq.pls";
		case 15: adres = "http://listen.technobase.fm/dsl.pls";
		case 16: adres = "http://listen.slotex.pl/7810.pls";
		case 17: adres = "http://www.tuba.fm/stream.pls?radio=7&mp3=1";
		case 18: adres = "http://94.23.89.48:7300/listen.pls";
		default: return 0;
	}
	// CarRadioID[playerid] = Audio_PlayStreamed(playerid, adres, false, true, false);
	CarRadioID[playerid] = PlayAudioStreamForPlayer(playerid, adres);
	// Audio_SetVolume(playerid, CarRadioID[playerid], gVehData[GetPlayerVehicleID(playerid)-1][RadioVol] );
	return 1;
}

stock StopCarRadioStation(vehicleid)
{
	if(gVehData[vehicleid-1][RadioOn] != 0)
	{
		gVehData[vehicleid-1][RadioOn] = 0;
		SaveVehData(vehicleid-1, "RadioOn");
	}
	foreach(Player, i )
	{
		if(!IsPlayerInVehicle(i, vehicleid))
			continue;

		// Audio_Stop(i, CarRadioID[i]);
		StopAudioStreamForPlayer(i);
		CarRadioID[i] = 255;
	}
	return 1;
}

stock ChangeCarRadioVolume( vehicleid, volume )
{
	gVehData[vehicleid-1][RadioVol] = volume;
	foreach(Player, i )
	{
		if(IsPlayerInVehicle(i, vehicleid))
			Audio_SetVolume(i, CarRadioID[i], volume);
	}
	return 1;
}

stock PlayBizRadio( hid, stationid, vw )
{
	new adres[256];
	switch(stationid)
	{
		case 1: adres = "http://radioparty.pl/play/glowny_96.m3u";
		case 2: adres = "http://radioparty.pl/play/djmixes_96.m3u";
		case 3: adres = "http://radioparty.pl/play/house_96.m3u";
		case 4: adres = "http://radioparty.pl/play/trance_96.m3u";
		case 5: adres = "http://radioparty.pl/play/vtrance_96.m3u";
		case 6: adres = "http://radioparty.pl/play/energy2000_96.m3u";
		case 7: adres = "http://radioparty.pl/play/ambeat_96.m3u";
		case 8: adres = "http://www.radiohoryzont.pl/listen.m3u";
		case 9: adres = "http://radiozetmp3-07.eurozet.pl:8400/listen.pls";
		case 10: adres = "http://www.miastomuzyki.pl/n/rmfclassic.pls";
		case 11: adres = "http://www.miastomuzyki.pl/n/rmffm.pls";
		case 12: adres = "http://lodz.radio.pionier.net.pl:8000/pl/eskarock.mp3.m3u";
		case 13: adres = "http://poznan5-2.radio.pionier.net.pl:8000/eska-warszawa.mp3.m3u";
		case 14: adres = "http://www.polskastacja.pl/play/discopolohq.pls";
		case 15: adres = "http://listen.technobase.fm/dsl.pls";
		case 16: adres = "http://listen.slotex.pl/7810.pls";
		case 17: adres = "http://www.tuba.fm/stream.pls?radio=7&mp3=1";
		case 18: adres = "http://94.23.89.48:7300/listen.pls";
		default: return 0;
	}
	foreach(Player, i )
	{
		if( GetPlayerVirtualWorld(i) == vw )
		{
			if(Businesses[hid][BRadio1ID][i] != 255)
				Audio_Stop(i, Businesses[hid][BRadio1ID][i] );
			Businesses[hid][BRadio1ID][i] = Audio_PlayStreamed(i, adres, false, true, true);
			Audio_SetVolume(i, Businesses[hid][BRadio1ID][i], Businesses[hid][BRadio1Vol]);
			// Audio_Set3DPosition(i,  Businesses[hid][BRadio1ID][i],  Businesses[hid][BRadio1X], Businesses[hid][BRadio1Y], Businesses[hid][BRadio1Z], 100.0);
		}
	}
	return 1;
}

stock ResumeBizRadioStation(playerid, hid)
{
	new adres[256];
	switch( Businesses[hid][BRadio1Ch] )
	{
		case 1: adres = "http://radioparty.pl/play/glowny_96.m3u";
		case 2: adres = "http://radioparty.pl/play/djmixes_96.m3u";
		case 3: adres = "http://radioparty.pl/play/house_96.m3u";
		case 4: adres = "http://radioparty.pl/play/trance_96.m3u";
		case 5: adres = "http://radioparty.pl/play/vtrance_96.m3u";
		case 6: adres = "http://radioparty.pl/play/energy2000_96.m3u";
		case 7: adres = "http://radioparty.pl/play/ambeat_96.m3u";
		case 8: adres = "http://www.radiohoryzont.pl/listen.m3u";
		case 9: adres = "http://radiozetmp3-07.eurozet.pl:8400/listen.pls";
		case 10: adres = "http://www.miastomuzyki.pl/n/rmfclassic.pls";
		case 11: adres = "http://www.miastomuzyki.pl/n/rmffm.pls";
		case 12: adres = "http://lodz.radio.pionier.net.pl:8000/pl/eskarock.mp3.m3u";
		case 13: adres = "http://poznan5-2.radio.pionier.net.pl:8000/eska-warszawa.mp3.m3u";
		case 14: adres = "http://www.polskastacja.pl/play/discopolohq.pls";
		case 15: adres = "http://listen.technobase.fm/dsl.pls";
		case 16: adres = "http://listen.slotex.pl/7810.pls";
		case 17: adres = "http://www.tuba.fm/stream.pls?radio=7&mp3=1";
		case 18: adres = "http://94.23.89.48:7300/listen.pls";
		default: return 0;
	}
	if( GetPlayerVirtualWorld(playerid) == hid )
	{
		if(Businesses[hid][BRadio1ID][playerid] != 255)
			Audio_Stop(playerid, Businesses[hid][BRadio1ID][playerid] );
		Businesses[hid][BRadio1ID][playerid] = Audio_PlayStreamed(playerid, adres, false, true, true);
		Audio_SetVolume(playerid, Businesses[hid][BRadio1ID][playerid], Businesses[hid][BRadio1Vol]);
		// Audio_Set3DPosition(playerid, Businesses[hid][BRadio1ID][playerid], Businesses[hid][BRadio1X], Businesses[hid][BRadio1Y], Businesses[hid][BRadio1Z], 100.0);
	}
	return 1;
}

stock StopBizRadioStation(hid)
{
	Businesses[hid][BRadio1On] = 0;
	SaveBizData( hid, "BRadio1On" );
	foreach(Player, i )
	{
		if( Businesses[hid][BRadio1ID][i] != 255 )
			Audio_Stop( i, Businesses[hid][BRadio1ID][i] );
		Businesses[hid][BRadio1ID][i] = 255;
	}
	return 1;
}

stock ChangeBizRadioVolume( hid, volume )
{
	foreach(Player, i )
	{
		Audio_SetVolume(i, Businesses[hid][BRadio1ID][i], volume);
		Businesses[hid][BRadio1Vol] = volume;
		SaveHouseData( hid, "BRadio1Vol" );
	}
	return 1;
}

stock PlayHouseRadio( hid, stationid, vw )
{
	new adres[256];
	switch(stationid)
	{
		case 1: adres = "http://radioparty.pl/play/glowny_96.m3u";
		case 2: adres = "http://radioparty.pl/play/djmixes_96.m3u";
		case 3: adres = "http://radioparty.pl/play/house_96.m3u";
		case 4: adres = "http://radioparty.pl/play/trance_96.m3u";
		case 5: adres = "http://radioparty.pl/play/vtrance_96.m3u";
		case 6: adres = "http://radioparty.pl/play/energy2000_96.m3u";
		case 7: adres = "http://radioparty.pl/play/ambeat_96.m3u";
		case 8: adres = "http://www.radiohoryzont.pl/listen.m3u";
		case 9: adres = "http://radiozetmp3-07.eurozet.pl:8400/listen.pls";
		case 10: adres = "http://www.miastomuzyki.pl/n/rmfclassic.pls";
		case 11: adres = "http://www.miastomuzyki.pl/n/rmffm.pls";
		case 12: adres = "http://lodz.radio.pionier.net.pl:8000/pl/eskarock.mp3.m3u";
		case 13: adres = "http://poznan5-2.radio.pionier.net.pl:8000/eska-warszawa.mp3.m3u";
		case 14: adres = "http://www.polskastacja.pl/play/discopolohq.pls";
		case 15: adres = "http://listen.technobase.fm/dsl.pls";
		case 16: adres = "http://listen.slotex.pl/7810.pls";
		case 17: adres = "http://www.tuba.fm/stream.pls?radio=7&mp3=1";
		case 18: adres = "http://94.23.89.48:7300/listen.pls";
		default: return 0;
	}
	foreach(Player, i )
	{
		if( GetPlayerVirtualWorld(i) == vw )
		{
			if(Houses[hid][HRadio1ID][i] != 255)
				Audio_Stop(i, Houses[hid][HRadio1ID][i] );
			Houses[hid][HRadio1ID][i] = Audio_PlayStreamed(i, adres, false, true, true);
			Audio_SetVolume(i, Houses[hid][HRadio1ID][i], Houses[hid][HRadio1Vol]);
			Audio_Set3DPosition(i,  Houses[hid][HRadio1ID][i],  Houses[hid][HRadio1X], Houses[hid][HRadio1Y], Houses[hid][HRadio1Z], 30.0);
		}
	}
	return 1;
}

stock ResumeHouseRadioStation(playerid, hid, stationid)
{
	new adres[256];
	if( Houses[hid][HRadio1On] )
		Audio_Stop(playerid, CarRadioID[playerid]);

	switch(stationid)
	{
		case 1: adres = "http://radioparty.pl/play/glowny_96.m3u";
		case 2: adres = "http://radioparty.pl/play/djmixes_96.m3u";
		case 3: adres = "http://radioparty.pl/play/house_96.m3u";
		case 4: adres = "http://radioparty.pl/play/trance_96.m3u";
		case 5: adres = "http://radioparty.pl/play/vtrance_96.m3u";
		case 6: adres = "http://radioparty.pl/play/energy2000_96.m3u";
		case 7: adres = "http://radioparty.pl/play/ambeat_96.m3u";
		case 8: adres = "http://www.radiohoryzont.pl/listen.m3u";
		case 9: adres = "http://radiozetmp3-07.eurozet.pl:8400/listen.pls";
		case 10: adres = "http://www.miastomuzyki.pl/n/rmfclassic.pls";
		case 11: adres = "http://www.miastomuzyki.pl/n/rmffm.pls";
		case 12: adres = "http://lodz.radio.pionier.net.pl:8000/pl/eskarock.mp3.m3u";
		case 13: adres = "http://poznan5-2.radio.pionier.net.pl:8000/eska-warszawa.mp3.m3u";
		case 14: adres = "http://www.polskastacja.pl/play/discopolohq.pls";
		case 15: adres = "http://listen.technobase.fm/dsl.pls";
		case 16: adres = "http://listen.slotex.pl/7810.pls";
		case 17: adres = "http://www.tuba.fm/stream.pls?radio=7&mp3=1";
		case 18: adres = "http://94.23.89.48:7300/listen.pls";
		default: return 0;
	}
	Houses[hid][HRadio1ID][playerid] = Audio_PlayStreamed(playerid, adres, false, true, false);
	Audio_Set3DPosition(playerid,  Houses[hid][HRadio1ID][playerid],  Houses[hid][HRadio1X], Houses[hid][HRadio1Y], Houses[hid][HRadio1Z], 30.0);
	return 1;
}

stock PlayerPHouseRadio( playerid, hid )
{
	new adres[256];
	switch( Houses[hid][HRadio1Ch] )
	{
		case 1: adres = "http://radioparty.pl/play/glowny_96.m3u";
		case 2: adres = "http://radioparty.pl/play/djmixes_96.m3u";
		case 3: adres = "http://radioparty.pl/play/house_96.m3u";
		case 4: adres = "http://radioparty.pl/play/trance_96.m3u";
		case 5: adres = "http://radioparty.pl/play/vtrance_96.m3u";
		case 6: adres = "http://radioparty.pl/play/energy2000_96.m3u";
		case 7: adres = "http://radioparty.pl/play/ambeat_96.m3u";
		case 8: adres = "http://www.radiohoryzont.pl/listen.m3u";
		case 9: adres = "http://radiozetmp3-07.eurozet.pl:8400/listen.pls";
		case 10: adres = "http://www.miastomuzyki.pl/n/rmfclassic.pls";
		case 11: adres = "http://www.miastomuzyki.pl/n/rmffm.pls";
		case 12: adres = "http://lodz.radio.pionier.net.pl:8000/pl/eskarock.mp3.m3u";
		case 13: adres = "http://poznan5-2.radio.pionier.net.pl:8000/eska-warszawa.mp3.m3u";
		case 14: adres = "http://www.polskastacja.pl/play/discopolohq.pls";
		case 15: adres = "http://listen.technobase.fm/dsl.pls";
		case 16: adres = "http://listen.slotex.pl/7810.pls";
		case 17: adres = "http://www.tuba.fm/stream.pls?radio=7&mp3=1";
		case 18: adres = "http://94.23.89.48:7300/listen.pls";
		default: return 0;
	}
	if( GetPlayerVirtualWorld(playerid) == hid )
	{
		if(Houses[hid][HRadio1ID][playerid] != 255)
			Audio_Stop(playerid, Houses[hid][HRadio1ID][playerid] );
		Houses[hid][HRadio1ID][playerid] = Audio_PlayStreamed(playerid, adres, false, true, true);
		Audio_SetVolume(playerid, Houses[hid][HRadio1ID][playerid], Houses[hid][HRadio1Vol]);
		Audio_Set3DPosition(playerid, Houses[hid][HRadio1ID][playerid], Houses[hid][HRadio1X], Houses[hid][HRadio1Y], Houses[hid][HRadio1Z], 30.0);
	}
	return 1;
}

stock StopHouseRadioStation(hid)
{
	Houses[hid][HRadio1On] = 0;
	SaveHouseData( hid, "HRadio1On" );
	foreach(Player, i )
	{
		if( Houses[hid][HRadio1ID][i] != 255 )
			Audio_Stop( i, Houses[hid][HRadio1ID][i] );
		Houses[hid][HRadio1ID][i] = 255;
	}
	return 1;
}

stock ChangeHouseRadioVolume( hid, volume )
{
	foreach(Player, i )
	{
		Audio_SetVolume(i, Houses[hid][HRadio1ID][i], volume);
		Houses[hid][HRadio1Vol] = volume;
		SaveHouseData( hid, "HRadio1Vol" );
	}
	return 1;
}