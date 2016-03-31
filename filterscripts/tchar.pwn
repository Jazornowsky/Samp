/*
	SA-MP Voice Chat Filterscript (0.3d)
	Copyright © 2011 RyDeR`
*/

#include <a_samp>

#define MAX_VOICE_RANGE (100.0)

new
	g_aLangData[][][] =
	{
		{ "<!> Disable", "" },
		{ "English", "en" },
		{ "Turkish", "tr" },
		{ "Croatian", "hr" },
		{ "African", "af" },
		{ "Albanian", "sq" },
		{ "Armenian", "hy" },
		{ "Azerbaijani", "az" },
		{ "Catalonian", "ca" },
		{ "Traditional Chinese", "zh-TW" },
		{ "Simplified Chinese", "zh-CN" },
		{ "Danish", "da" },
		{ "German", "de" },
		{ "Finnish", "fi" },
		{ "French", "fr" },
		{ "Greek", "el" },
		{ "Haitian Creole", "ht" },
		{ "Hindu", "hi" },
		{ "Hungarian", "hu" },
		{ "Icelandic", "is" },
		{ "Indonesian", "id" },
		{ "Italian", "it" },
		{ "Latvian", "lv" },
		{ "Macedonian", "mk" },
		{ "Dutch", "nl" },
		{ "Norwegian", "no" },
		{ "Polish", "pl" },
		{ "Portuguese", "pt" },
		{ "Romanian", "ro" },
		{ "Russian", "ru" },
		{ "Serbian", "sr" },
		{ "Slovak", "sk" },
		{ "Spannish", "es" },
		{ "Swahili", "sw" },
		{ "Czech", "cs" },
		{ "Vietnamese", "vi" },
		{ "Welsh", "cy" },
		{ "Swedisch", "sv" }
	},
	g_szLangList[768]
;

public OnFilterScriptInit()
{
	for(new i; i < sizeof(g_aLangData); ++i)
	{
		strcat(g_szLangList, g_aLangData[i][0]);
		strcat(g_szLangList, "\n");
	}
	
	printf("\n » SA:MP [0.3d] Voice Chat Filterscript (by RyDeR`) has been loaded! \n");	
	return 1;
}

public OnPlayerText(playerid, text[])
{
	SendVoiceMessage(playerid, text, g_aLangData[GetPVarInt(playerid, "iLangIdx")][1]);
	return 1;
}

public OnPlayerCommandText(playerid, cmdtext[])
{
	if(!strcmp(cmdtext, "/language", true))
	{
		ShowPlayerDialog(playerid, 1024, DIALOG_STYLE_LIST, "Choose your language", g_szLangList, "Select", "");
	    return 1;
	}
	return 0;
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	if(response)
	{
	    switch(dialogid)
	    {
	        case 1024:
	        {
				if(0 <= listitem < sizeof(g_aLangData))
				{
					SetPVarInt(playerid, "iLangIdx", listitem);
					
					static
						szStr[128]
					;
					if(!listitem)
						SendClientMessage(playerid, 0xFF0000FF, "[INFO] Voice chat has been disabled!");
					else
						format(szStr, sizeof(szStr), "[INFO] Voice chat language has been set to %s", g_aLangData[listitem][0]),
						SendClientMessage(playerid, 0xFFFFFFFF, szStr);
				}
	        }
	    }
	}
	return 1;
}

stock SendVoiceMessage(playerid, szMsg[], const szLang[])
{
	new
		Float: fPos[3]
	;
	if(GetPlayerPos(playerid, fPos[0], fPos[1], fPos[2]) && szLang[0] != EOS)
	{
		static
			szUrl[60 + 128]
		;
		format(szUrl, sizeof(szUrl), "http://translate.google.com/translate_tts?tl=%s&q=%s", szLang, szMsg);
		
		for(new i, j = GetMaxPlayers(); i < j; ++i)
		{
			if(PlayAudioStreamForPlayer(i, szUrl, fPos[0], fPos[1], fPos[2], MAX_VOICE_RANGE, true))
			{
				continue;
			}
		}
		return 1;
	}
	return 0;
}