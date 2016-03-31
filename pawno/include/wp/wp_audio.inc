/***
*
* File: wp_audio.inc
* Auth: Damian Wojdat
* Date: 15.09.2011
* Desc: Sample audio stuff.
* TODO: Cleanup.
*
*************************************************************************************************************/

/*
* Purpose: 
*				Loads audio pack and plays predefined audio sources.
*
* Note:
*				Function customized from audio.inc
*/
public Audio_OnClientConnect(playerid)
{
	Audio_TransferPack(playerid);
	// PlayMusic(playerid);
	return 1;
}

/*
* Purpose: 
*				Plays predefined audio sources.
*/
// PlayMusic(playerid)
// {
	// new adres[256] = "http://94.23.6.162:8888"; // radio party 48kbps
	// MoloSequence[playerid] = Audio_PlayStreamed(playerid, adres, false, false, false);
	// new adres2[256] = "http://91.121.157.213:8050"; // radio zet
	// PoolSequence[playerid] = Audio_PlayStreamed(playerid, adres2, false, false, false);
	// adres2 = "http://91.121.18.185:7552"; // polska stacja kanal koledy
	// ChurchSequence[playerid] = Audio_PlayStreamed(playerid, adres2, false, false, false);
	
	// for(new i = 0; i < sizeof(gRadioSet); i++)
	// {
		// gRadioID[i][playerid] = Audio_PlayStreamed(playerid, gRadio[i][StationID], false, false, false);
	// }	
	// return 1;
// }

/*
* Purpose: 
*				Sets audio 3D position by id of audio.
*
* Note:
*				Function customized from audio.inc
*/
public Audio_OnPlay(playerid, handleid)
{
	if(handleid == MoloSequence[playerid])
	{
		Audio_Set3DPosition(playerid, MoloSequence[playerid],-2983.0,600.0,3.0,100.0);
	}
	if(handleid == PoolSequence[playerid])
	{
		Audio_Set3DPosition(playerid, PoolSequence[playerid],598.0,-2201,2.0,70.0);
	}
	// if(handleid == ChurchSequence[playerid])
	// {
		// Audio_Set3DPosition(playerid, ChurchSequence[playerid],2254.0,-1361.0,-51.0, 70.0);
	// }
	// if(handleid == ChurchSequence2[playerid])
	// {
		// Audio_Set3DPosition(playerid, ChurchSequence2[playerid],2254.0,-1347.0,-51.0, 70.0);
	// }
	// SetTimerEx("SetRadioAudioPos", 30000, 0, "dd", playerid, handleid);
	return 1;
}

/*
* Function customized from audio.inc
*
* Callback function represents status change of audio file transfer.
*/
public Audio_OnTransferFile(playerid, file[], current, total, result)
{
	if(current == total)
	{
		if(result == 0 || result == 1)
			SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Zakoñczono ³adowanie plików dŸwiêkowych");
		AudioReady[playerid] = 1;
		// PlayMusic(playerid);
	}
	return 1;
}

/*
* Purpose: 
*				Not clear, probably not finished.
* 				Seems to change audio position, theoretical radio source.
*
* Note:
*				Function name changed 17-06-2011
*				From: PlayCustomMusic
*				To: SetRadioAudioPos
*/
public SetRadioAudioPos(playerid, handleid)
{
	for(new i = 0; i < sizeof(gRadioSet); i++)
	{
		if(handleid == gRadioID[i][playerid])
		{
			Audio_Set3DPosition(playerid, gRadioID[i][playerid], gRadioSet[i][AudioX], gRadioSet[i][AudioY], gRadioSet[i][AudioZ], 80.0);
		}
	}
	return 1;
}

/*
* Purpose:
*				Plays some sound whe audio is stopped.
*/
stock StopMusic(playerid)
{
	PlayerPlaySound(playerid, 1069, 0.0, 0.0, 0.0);
}
