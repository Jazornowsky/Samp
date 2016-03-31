/***
*
* File: wp_sounds.inc
* Auth: Damian Wojdat
* Date: 15.09.2011
* Desc: Included sound handle.
*
*************************************************************************************************************/

timer playBackgroundSounds[5000](playerid, areaid, leave)
{
	if(!gPlayerData[playerid][pBackgroundSoundStatus])
		return 0;
	static hour, minute, second;
	gettime(hour, minute, second);
	if(areaid == gASanFierro || areaid == gALosSantos1 || areaid == gALosSantos2 || areaid == gAAngelPine || areaid == gAPalominoCreek || areaid == gAMontgomery)
	{
		if(!leave)
		{
			if(hour > 9 && (hour <= 23 && minute <= 59))
			{
				if(gBackgroundAudio1[playerid] != -1)
				{
					Audio_Stop(playerid, gBackgroundAudio1[playerid]);
					gBackgroundAudio1[playerid] = -1;
				}
				gBackgroundAudio1[playerid] = Audio_Play(playerid, AUDIO_URBAN_NOISE, false, true, false);
				Audio_SetVolume(playerid, gBackgroundAudio1[playerid], 60);
				Audio_SetPosition(playerid, gBackgroundAudio1[playerid], random(230));
			}
			else if(hour >= 4 && hour <= 9)
			{
				if(gBackgroundAudio1[playerid] != -1)
				{
					Audio_Stop(playerid, gBackgroundAudio1[playerid]);
					gBackgroundAudio1[playerid] = -1;
				}
				gBackgroundAudio1[playerid] = Audio_Play(playerid, AUDIO_URBAN_NOISE_MORNING, false, true, false);
				Audio_SetVolume(playerid, gBackgroundAudio1[playerid], 100);
				Audio_SetPosition(playerid, gBackgroundAudio1[playerid], random(70));
			}
		}
		else
		{
			if(gBackgroundAudio1[playerid] != -1)
			{
				Audio_Stop(playerid, gBackgroundAudio1[playerid]);
				gBackgroundAudio1[playerid] = -1;
			}
			gBackgroundAudio1[playerid] = Audio_Play(playerid, AUDIO_SUBURB_NOISE, false, true, false);
			Audio_SetVolume(playerid, gBackgroundAudio1[playerid], 100);
			Audio_SetPosition(playerid, gBackgroundAudio1[playerid], random(230));
		}
	}
	return 0;
}		