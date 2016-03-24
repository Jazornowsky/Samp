#include <a_samp>
#define MAX_PROPERTIES 250

#define CREATE_PICKUPS

new TmpPickup[MAX_PROPERTIES];
new TotalPickups;

public OnFilterScriptInit()
{
	new File:fhnd;
	if(!fexist("SavedProperties.txt"))
	{
		fhnd=fopen("SavedProperties.txt",io_write);
		fclose(fhnd);
		print("File 'SavedProperties.txt' created succesfully!");
	}
	print("\n--------------------------------------");
	print(" Blank Filterscript by your name here");
	print("--------------------------------------\n");

	return 1;
}

public OnFilterScriptExit()
{
	for(new i; i<TotalPickups; i++)
	{
		DestroyPickup(TmpPickup[i]);
	}
	return 1;
}

public OnPlayerCommandText(playerid, cmdtext[])
{
    new cmd[256],tmp[256];
	new idx;
	cmd = strtok(cmdtext, idx);
	if (strcmp("/addproperty", cmdtext, true, 10) == 0)
	{
	    if(!IsPlayerAdmin(playerid)) return 0;

		new name[64], price, sell, earning;
		new Float:X, Float:Y, Float:Z;
		GetPlayerPos(playerid, X, Y, Z);
		format(name, 64, "%s", strtok(cmdtext,idx));
		tmp = strtok(cmdtext,idx);
		if(!strlen(tmp))
		{
			SendClientMessage(playerid, 0xFFFFFFAA, "Use: /addproperty [name] [price] [sellvalue] [earning]");
			return 1;
		}
		price = strval(tmp);
		tmp = strtok(cmdtext,idx);
		if(!strlen(tmp))
		{
			SendClientMessage(playerid, 0xFFFFFFAA, "Use: /addproperty [name] [price] [sellvalue] [earning]");
			return 1;
		}
		sell = strval(tmp);
		tmp = strtok(cmdtext,idx);
		if(!strlen(tmp))
		{
			SendClientMessage(playerid, 0xFFFFFFAA, "Use: /addproperty [name] [price] [sellvalue] [earning]");
			return 1;
		}
        earning = strval(tmp);
		new entry[128], entry2[128];
		new File:hFile;
		format(entry, 128, "AddProperty(\"%s\", %.2f, %.2f, %.2f, %d, %d, %d);", name, X, Y, Z, price, sell, earning);
		format(entry2, 128, "\r\n%s",entry);
		hFile = fopen("SavedProperties.txt", io_append);
		fwrite(hFile, entry2);
		fclose(hFile);
		#if defined CREATE_PICKUPS
        TmpPickup[TotalPickups] = CreatePickup(1272, 1, X, Y, Z);
        #endif
        TotalPickups++;
		format(entry, sizeof(entry), "Saved Property \"%s\" in SavedProperties.txt!", name);
		SendClientMessage(playerid,0x00FF00AA, entry);
		return 1;
	}
	return 0;
}


strtok(const string[], &index)
{
	new length = strlen(string);
	while ((index < length) && (string[index] <= ' '))
	{
		index++;
	}

	new offset = index;
	new result[20];
	while ((index < length) && (string[index] > ' ') && ((index - offset) < (sizeof(result) - 1)))
	{
		result[index - offset] = string[index];
		index++;
	}
	result[index - offset] = EOS;
	return result;
}

