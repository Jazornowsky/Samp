/*
 *	Simple Animation List
 *      Simple list of animation libraries.
 *      Each library contains all it's animations.
 *      Save animations with current settings.
 *
 *	~Southclaw
 *      Do what you want with it, but keep my name on it :)
 */


#include <a_samp>   // If you don't have this file, give up... just, give up.
#include <zcmd>     // If you don't have ZCMD, get it, don't go asking me to make a strcmp version!


#define DIALOG_INDEX		(9000)  // Default dialog index to start dialog IDs from

#undef MAX_PLAYERS
#define MAX_PLAYERS			(16)

#define MAX_ANIMS			(1812)  // Total amount of animations
#define MAX_LIBRARY			(132)   // Total amount of libraries
#define MAX_LIBANIMS    	(294)   // Largest library
#define MAX_LIBNAME     	(32)
#define MAX_ANIMNAME    	(32)    // Same as LIBNAME but just for completion!

#define ANIM_SAVE_FILE  "SavedAnimations.txt"

#define PreloadAnimLib(%1,%2) ApplyAnimation(%1,%2,"null",0.0,0,0,0,0,0)


enum
{
	D_ANIM_LIBRARIES = DIALOG_INDEX,
	D_ANIM_LIST,
	D_ANIM_SETTINGS,
	D_ANIM_SPEED,
	D_ANIM_TIME
}
enum E_ANIM_SETTINGS
{
	Float:anm_Speed,
	anm_Loop,
	anm_LockX,
	anm_LockY,
	anm_Freeze,
	anm_Time
}


new
	gAnimTotal[MAX_LIBRARY],

	gLibList[MAX_LIBRARY * (MAX_LIBNAME+1)],
	gAnimList[MAX_LIBRARY][MAX_LIBANIMS * (MAX_ANIMNAME+1)],

	gCurrentLib[MAX_PLAYERS][MAX_LIBNAME],
	gCurrentAnim[MAX_PLAYERS][MAX_ANIMNAME],

	gAnimSettings[MAX_PLAYERS][E_ANIM_SETTINGS];

public OnFilterScriptInit()
{
	new
	    lib[32],
	    anim[32],
		tmplib[32] = "NULL",
		curlib = -1;

	for(new i = 1;i<MAX_ANIMS;i++)
	{
	    GetAnimationName(i, lib, 32, anim, 32);
	    
	    if(strcmp(lib, tmplib))
	    {
	        strcat(gLibList, lib);
	        strcat(gLibList, "\n");
	        tmplib = lib;
	        curlib++;
	    }
	    
	    strcat(gAnimList[curlib], anim);
	    strcat(gAnimList[curlib], "\n");

	    gAnimTotal[ curlib ]++;
	}
	
	for(new i;i<MAX_PLAYERS;i++)
	{
	    // Default animations to avoid crashes if a user uses
	    // /animsettings before /animations.
	    gCurrentLib[i] = "RUNNINGMAN";
	    gCurrentAnim[i] = "DANCE_LOOP";
	    
		// Default speed so the user can use /animations
		// before needing to edit the speed in /animsettings
		gAnimSettings[i][anm_Speed] = 4.0;
	}
}

CMD:animations(playerid, params[])
{
    PreloadPlayerAnims(playerid);
	ShowPlayerDialog(playerid, D_ANIM_LIBRARIES, DIALOG_STYLE_LIST, "Choose an animation library", gLibList, "Open...", "Cancel");
	return 1;
}
CMD:animsettings(playerid, params[])
{
	FormatAnimSettingsMenu(playerid);
	return 1;
}
CMD:saveanim(playerid, params[])
{
	if(strlen(params)<1)SendClientMessage(playerid, -1, "Usage: /saveanimation [comment]");
	else SaveCurrentAnimation(playerid, params);
	return 1;
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	if(dialogid == D_ANIM_LIBRARIES && response)
	{
	    // Blank the string because strcat is used.
	    gCurrentLib[playerid][0] = EOS;
	    // Fortunately, inputtext will return the text of the line,
	    // So this can just be saved as the player's current library.
	    strcat(gCurrentLib[playerid], inputtext);
	    // Show the right list of animations from the chosen library.
		ShowPlayerDialog(playerid, D_ANIM_LIST, DIALOG_STYLE_LIST, "Choose an animation", gAnimList[listitem], "Play", "Back");
		// Preload the animations for that library
		PreloadAnimLib(playerid, inputtext);
	}
	if(dialogid == D_ANIM_LIST)
	{
	    if(response)
	    {
		    // Blank the string because strcat is used
		    gCurrentAnim[playerid][0] = EOS;
		    // Save the animation name to the variable (For saving)
		    strcat(gCurrentAnim[playerid], inputtext);

			PlayCurrentAnimation(playerid);
		}
		else ShowPlayerDialog(playerid, D_ANIM_LIBRARIES, DIALOG_STYLE_LIST, "Choose an animation library", gLibList, "Open...", "Cancel");
	}
	if(dialogid == D_ANIM_SETTINGS && response)
	{
		if(listitem == 0)ShowPlayerDialog(playerid, D_ANIM_SPEED, DIALOG_STYLE_INPUT, "Animation Speed", "Change the speed of the animation below:", "Accept", "Back");
		else if(listitem == 5)ShowPlayerDialog(playerid, D_ANIM_TIME, DIALOG_STYLE_INPUT, "Animation Time", "Change the time of the animation below:", "Accept", "Back");
		else
		{
		    gAnimSettings[playerid][E_ANIM_SETTINGS:listitem] = !gAnimSettings[playerid][E_ANIM_SETTINGS:listitem];
		    PlayCurrentAnimation(playerid);
			FormatAnimSettingsMenu(playerid);
		}
	}
	if(dialogid == D_ANIM_SPEED)
	{
	    if(response)
		{
			gAnimSettings[playerid][anm_Speed] = floatstr(inputtext);
	    	PlayCurrentAnimation(playerid);
	    }
		FormatAnimSettingsMenu(playerid);
	}
	if(dialogid == D_ANIM_TIME)
	{
	    if(response)
		{
			gAnimSettings[playerid][anm_Time] = strval(inputtext);
	    	PlayCurrentAnimation(playerid);
	    }
		FormatAnimSettingsMenu(playerid);
	}
}

PlayCurrentAnimation(playerid)
{
    ApplyAnimation(playerid,
		gCurrentLib[playerid],
		gCurrentAnim[playerid],
		gAnimSettings[playerid][anm_Speed],
		gAnimSettings[playerid][anm_Loop],
		gAnimSettings[playerid][anm_LockX],
		gAnimSettings[playerid][anm_LockY],
		gAnimSettings[playerid][anm_Freeze],
		gAnimSettings[playerid][anm_Time],
		1);
}

FormatAnimSettingsMenu(playerid)
{
	new
	    list[128];

	format(list, 128,
	    "Speed:\t\t%f\n\
		Loop:\t\t%d\n\
		Lock X:\t\t%d\n\
		Lock Y:\t\t%d\n\
		Freeze:\t\t%d\n\
		Time:\t\t%d",
		gAnimSettings[playerid][anm_Speed],
		gAnimSettings[playerid][anm_Loop],
		gAnimSettings[playerid][anm_LockX],
		gAnimSettings[playerid][anm_LockY],
		gAnimSettings[playerid][anm_Freeze],
		gAnimSettings[playerid][anm_Time]);

	ShowPlayerDialog(playerid, D_ANIM_SETTINGS, DIALOG_STYLE_LIST, "Animation Settings", list, "Change", "Exit");
}

SaveCurrentAnimation(playerid, comment[])
{
	new
		File:file,
		line[128];

	if(!fexist(ANIM_SAVE_FILE))fopen(ANIM_SAVE_FILE, io_write);
	else fopen(ANIM_SAVE_FILE, io_read);
	
	format(line, 128, "ApplyAnimation(playerid, %s, %s, %f, %d, %d, %d, %d, %d); // %s\r\n",
		gCurrentLib[playerid],
		gCurrentAnim[playerid],
		gAnimSettings[playerid][anm_Speed],
		gAnimSettings[playerid][anm_Loop],
		gAnimSettings[playerid][anm_LockX],
		gAnimSettings[playerid][anm_LockY],
		gAnimSettings[playerid][anm_Freeze],
		gAnimSettings[playerid][anm_Time],
		comment);

	fwrite(file, line);
	fclose(file);
}


PreloadPlayerAnims(playerid)
{
   	PreloadAnimLib(playerid,"BOMBER");
   	PreloadAnimLib(playerid,"RAPPING");
   	PreloadAnimLib(playerid,"SHOP");
	PreloadAnimLib(playerid,"BEACH");
	PreloadAnimLib(playerid,"SMOKING");
   	PreloadAnimLib(playerid,"FOOD");
   	PreloadAnimLib(playerid,"ON_LOOKERS");
   	PreloadAnimLib(playerid,"DEALER");
	PreloadAnimLib(playerid,"CRACK");
	PreloadAnimLib(playerid,"CARRY");
	PreloadAnimLib(playerid,"COP_AMBIENT");
	PreloadAnimLib(playerid,"PARK");
	PreloadAnimLib(playerid,"INT_HOUSE");
	PreloadAnimLib(playerid,"FOOD");
	PreloadAnimLib(playerid,"PED");
}

#endinput

// The code I used to get the max values

public OnFilterScriptInit()
{
	new
	    lib[32],
	    anim[32],
		tmplib[32] = "NULL",
		libtotal,
		animtotal,
		largest;

	for(new i;i<MAX_ANIMS;i++)
	{
	    GetAnimationName(i, lib, 32, anim, 32);
	    animtotal++;
	    if(strcmp(lib, tmplib))
	    {
	        printf("Found library: '%s' anims: %d", lib, animtotal);
	        libtotal++;

	        if(animtotal > largest) largest = animtotal;
	        animtotal = 0;

	        tmplib = lib;
	    }
	}
	printf("Total Libraries: %d Largest Libaray: %d", libtotal, largest);
}