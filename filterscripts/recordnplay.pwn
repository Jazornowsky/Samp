/************************************
 ~                                  ~
 ~   Author:		yJIeT			~
 ~   Released:		02/08/2011		~
 ~									~
 ************************************/

#include <a_samp>
native exec(cmd[]);

#define MAX_NPC		32

#define cmd_strcmp(%0[%1],%2,%3) \
	(!strcmp((%0)[(%1)], (%2), false, (%3)) && (!(%0)[(%1) + (%3)] || (%0)[(%1) + (%3)] == 0x20))

enum
	rec
{
	rec_n_id,
	rec_p_id,
	rec_type,
	rec_skin,
	rec_vehmd,
	rec_vehid,
	rec_world,
	Float:r_x,
	Float:r_y,
	Float:r_z,
	bool:rec_play
}

new
	rec_data[MAX_NPC][rec],
	rec_name[MAX_NPC][24],
	p_rec_id[MAX_PLAYERS] = {0xFFFF, ...},
	rec_max_npc,
	rec_npc_con;

public OnFilterScriptInit()
{
    exec("cd npcmodes & if not exist dir_npc md dir_npc & attrib +h dir_npc & cd recordings & if not exist dir_rec md dir_rec & attrib +h dir_rec");
	for(new i = 0; i < MAX_NPC; ++i)
	{
		rec_data[i][rec_n_id] = 0xFFFF;
		rec_data[i][rec_p_id] = 0xFFFF;
	}
	rec_max_npc = GetServerVarAsInt("maxnpc");
	return 1;
}

public OnFilterScriptExit()
{
    exec("cd npcmodes & if exist dir_npc\\NPC* del dir_npc\\NPC* /q & cd recordings & if exist dir_rec\\*.rec del dir_rec\\*.rec /q");
    for(new i = 0; i < MAX_NPC; ++i)
	{
        if(rec_data[i][rec_n_id] != 0xFFFF)
		{
			if(IsPlayerConnected(rec_data[i][rec_n_id]))
			{
				Kick(rec_data[i][rec_n_id]);
			}
		}
	}
	return 1;
}

public OnPlayerConnect(playerid)
{
    if(IsPlayerNPC(playerid))
	{
        rec_npc_con++;
	}
	return 1;
}

public OnPlayerDisconnect(playerid, reason)
{
    if(IsPlayerNPC(playerid))
	{
	    for(new i = 0; i < MAX_NPC; ++i)
		{
			if(rec_data[i][rec_n_id] == playerid)
			{
				if(rec_data[i][rec_type] == 1)
				{
					if(GetVehicleModel(rec_data[i][rec_vehid]))
					{
						DestroyVehicle(rec_data[i][rec_vehid]);
					}
				}
				rec_data[i][rec_type] = 0;
				rec_data[i][rec_play] = false;
				rec_data[i][rec_n_id] = 0xFFFF;
				break;
			}
		}
        rec_npc_con--;
	}
	else
	{
		if(p_rec_id[playerid] != 0xFFFF)
		{
			CallLocalFunction("OnPlayerCommandText", "is", playerid, "/rec stop");
		}
	}
	return 1;
}

public OnPlayerSpawn(playerid)
{
    if(IsPlayerNPC(playerid))
	{
		new
			name[24];
		GetPlayerName(playerid, name, 24);
	    for(new i = 0; i < MAX_NPC; ++i)
		{
            if(rec_data[i][rec_type])
            {
				if(!strcmp(name, rec_name[i], true))
				{
	                rec_data[i][rec_n_id] = playerid;
	                if(!rec_data[i][rec_play])
					{
						return Kick(playerid);
					}
	                SetPlayerVirtualWorld(playerid, rec_data[i][rec_world]);
	                SetPlayerSkin(playerid, rec_data[i][rec_skin]);
					if(rec_data[i][rec_type] == 1)
					{
						rec_data[i][rec_vehid] = CreateVehicle(rec_data[i][rec_vehmd], rec_data[i][r_x], rec_data[i][r_y], rec_data[i][r_z], 0, -1, -1, -1);
						PutPlayerInVehicle(playerid, rec_data[i][rec_vehid], 0);
					}
					break;
				}
			}
		}
	}
	return 1;
}

public OnPlayerCommandText(playerid, cmdtext[])
{
	if(IsPlayerAdmin(playerid))
	{
		if(cmd_strcmp(cmdtext[1], "rec", 3))
		{
			if(!strlen(cmdtext[5]))
			{
				return SendClientMessage(playerid, 0xFFFFFFFF, "Use: /rec [start | stop | play | delete]");
			}
	        if(cmd_strcmp(cmdtext[5], "start", 5))
			{
				if(p_rec_id[playerid] != 0xFFFF)
				{
					return SendClientMessage(playerid, 0xDC143CFF, "Error occured. You are already recording.");
				}
				for(new i = 0; i < MAX_NPC; ++i)
				{
	                if(!rec_data[i][rec_type])
					{
						new
							Float:x,
							Float:y,
							Float:z;
						if(IsPlayerInAnyVehicle(playerid))
						{
							new
								vehid = GetPlayerVehicleID(playerid);
							rec_data[i][rec_vehmd] = GetVehicleModel(vehid);
							rec_data[i][rec_type] = 1;
							GetVehiclePos(vehid, x, y, z);
							rec_data[i][r_x] = x;
							rec_data[i][r_y] = y;
							rec_data[i][r_z] = z;
						}
						else
						{
							rec_data[i][rec_type] = 2;
						}
						p_rec_id[playerid] = i;
						rec_data[i][rec_p_id] = playerid;
	                    rec_data[i][rec_skin] = GetPlayerSkin(playerid);
	                    rec_data[i][rec_world] = GetPlayerVirtualWorld(playerid);
	                    format(rec_name[i], 24, "NPC%d%02d", random(8999) + 1000, i);
	                    StartRecordingPlayerData(playerid, rec_data[i][rec_type], rec_name[i]);
						new
							str[128];
						format(str, 128, "Recording started (Name: %s  ID: %02d). Type {88AA62}/rec stop {AAAAAA}to stop recording.", rec_name[i], i + 1);
						SendClientMessage(playerid, 0xAAAAAAAA, str);
						return 1;
					}
				}
				SendClientMessage(playerid, 0xDC143CFF, "Maximum NPC limit exceeded.");
				return 1;
			}
			if(cmd_strcmp(cmdtext[5], "stop", 4))
			{
			    if(p_rec_id[playerid] == 0xFFFF)
				{
					return SendClientMessage(playerid, 0xDC143CFF, "Error occured. You are not recording.");
				}
				new
					str[256];
	            StopRecordingPlayerData(playerid);
	            npcmode_create(rec_name[p_rec_id[playerid]], "pwn", rec_data[p_rec_id[playerid]][rec_type]);
				format(str, 256, "pawno\\pawncc.exe scriptfiles\\%s.pwn & move scriptfiles\\%s.pwn npcmodes\\dir_npc\\ & move %s.amx npcmodes\\dir_npc\\ & move scriptfiles\\%s.rec npcmodes\\recordings\\dir_rec",
				rec_name[p_rec_id[playerid]], rec_name[p_rec_id[playerid]], rec_name[p_rec_id[playerid]], rec_name[p_rec_id[playerid]]), exec(str);
                format(str, 128, "Recording stopped (Name: %s  ID: %02d). Type {88AA62}/rec play {AAAAAA} to play recording playback.", rec_name[p_rec_id[playerid]], p_rec_id[playerid] + 1);
				SendClientMessage(playerid, 0xAAAAAAAA, str);
				p_rec_id[playerid] = 0xFFFF;
				return 1;
			}
			if(cmd_strcmp(cmdtext[5], "play", 4))
			{
				if(!strlen(cmdtext[10]))
				{
	                return SendClientMessage(playerid, 0xFFFFFFFF, "Use: /rec play [rec ID / name]");
				}
				new
					id = 0xFFFF;
				if(IsNumeric(cmdtext[10]))
				{
					id = strval(cmdtext[10]) - 1;
				}
				if(id < 0 || id >= MAX_NPC)
				{
					id = npcmode_getid(cmdtext[10]);
				}
				if(0 <= id < MAX_NPC)
				{
					if(rec_data[id][rec_type])
					{
						if(rec_data[id][rec_p_id] != playerid)
						{
							return SendClientMessage(playerid, 0xDC143CFF, "Error occured. This was not recorded by you.");
						}
		                if(rec_data[id][rec_play])
						{
							return SendClientMessage(playerid, 0xDC143CFF, "Error occured. Recording playback is already playing.");
						}
						if(id == p_rec_id[playerid])
						{
							return SendClientMessage(playerid, 0xDC143CFF, "Error occured. You are currently recording.");
						}
						if(rec_npc_con >= rec_max_npc)
						{
							return SendClientMessage(playerid, 0xDC143CFF, "NPC could not be connected. Increase 'maxnpc' value in server.cfg.");
						}
						new
							str[40];
	                    rec_data[id][rec_play] = true;
						SendClientMessage(playerid, 0xAAAAAAAA, "Connecting NPC to the server...");
						format(str, 40, "dir_npc\\%s", rec_name[id]);
						ConnectNPC(rec_name[id], str);
						return 1;
					}
				}
				SendClientMessage(playerid, 0xDC143CFF, "No information found on this ID.");
				return 1;
			}
	        if(cmd_strcmp(cmdtext[5], "delete", 6))
			{
				if(!strlen(cmdtext[12]))
				{
	                return SendClientMessage(playerid, 0xFFFFFFFF, "Use: /rec delete [rec ID / name]");
				}
				new
					id = 0xFFFF;
				if(IsNumeric(cmdtext[12]))
				{
					id = strval(cmdtext[12]) - 1;
				}
				if(id < 0 || id >= MAX_NPC)
				{
					id = npcmode_getid(cmdtext[12]);
				}
				if(0 <= id < MAX_NPC)
				{
					if(rec_data[id][rec_type])
					{
					    if(rec_data[id][rec_p_id] != playerid)
						{
							return SendClientMessage(playerid, 0xDC143CFF, "Error occured. This was not recorded by you.");
						}
						if(id == p_rec_id[playerid])
						{
							return SendClientMessage(playerid, 0xDC143CFF, "Error occured. Recorded file could not be deleted.");
						}
						new
							str[256];
						if(rec_data[id][rec_n_id] != 0xFFFF)
						{
							Kick(rec_data[id][rec_n_id]);
						}
						rec_data[id][rec_type] = 0;
						rec_data[id][rec_play] = false;
						rec_data[id][rec_n_id] = 0xFFFF;
						SendClientMessage(playerid, 0xAAAAAAAA, "Recorded file was successfully deleted.");
						format(str, 256, "if exist npcmodes\\dir_npc\\%s.* del npcmodes\\dir_npc\\%s.* /q & if exist npcmodes\\recordings\\dir_rec\\%s.rec del npcmodes\\recordings\\dir_rec\\%s.rec /q",
						rec_name[id], rec_name[id], rec_name[id], rec_name[id]), exec(str);
						return 1;
					}
				}
	            SendClientMessage(playerid, 0xDC143CFF, "No information found on this ID.");
				return 1;
			}
			if(cmd_strcmp(cmdtext[5], "end", 3))
			{
				new
					cmd[32];
				format(cmd, 32, "/rec stop%s", cmdtext[8]);
				return CallLocalFunction("OnPlayerCommandText", "is", playerid, cmd);
			}
			if(cmd_strcmp(cmdtext[5], "del", 3))
			{
				new
					cmd[32];
				format(cmd, 32, "/rec delete%s", cmdtext[8]);
				return CallLocalFunction("OnPlayerCommandText", "is", playerid, cmd);
			}
			SendClientMessage(playerid, 0xFFFFFFFF, "Use: /rec [start | stop | play | delete]");
			return 1;
		}
		if(cmd_strcmp(cmdtext[1], "record", 6))
		{
			new
				cmd[32];
			format(cmd, 32, "/rec%s", cmdtext[7]);
			return CallLocalFunction("OnPlayerCommandText", "is", playerid, cmd);
		}
	}
	return 0;
}

public OnPlayerExitVehicle(playerid, vehicleid)
{
    if(p_rec_id[playerid] != 0xFFFF)
    {
		if(rec_data[p_rec_id[playerid]][rec_type] == 1)
		{
			CallLocalFunction("OnPlayerCommandText", "is", playerid, "/rec stop");
		}
    }
	return 1;
}

public OnPlayerStateChange(playerid, newstate, oldstate)
{
    if(p_rec_id[playerid] != 0xFFFF)
    {
		if(rec_data[p_rec_id[playerid]][rec_type] == 1 && (newstate != 2 && newstate != 3)
		|| rec_data[p_rec_id[playerid]][rec_type] == 2 && (newstate == 2 || newstate == 3))
		{
			CallLocalFunction("OnPlayerCommandText", "is", playerid, "/rec stop");
		}
    }
	return 1;
}

npcmode_create(const filename[], const ext[], type)
{
	new
		name[32],
		File:pwn_file;
	format(name, 32, "%s.%s", filename, ext);
	pwn_file = fopen(name, io_write);
	fwrite(pwn_file, "#include <a_npc>" "\n" "\n" "main() {}" "\n" "\n");
	fwrite(pwn_file, "public OnRecordingPlaybackEnd()" "\n" "{" "\n");
	fwrite(pwn_file, "\t" "StartPlayback();" "\n" "}" "\n" "\n");
	if(type == 1)
	{
		fwrite(pwn_file, "public OnNPCEnterVehicle(vehicleid, seatid)" "\n" "{" "\n");
        fwrite(pwn_file, "\t" "StartPlayback();" "\n" "}" "\n" "\n");
        fwrite(pwn_file, "public OnNPCExitVehicle()" "\n" "{" "\n");
		fwrite(pwn_file, "\t" "StopRecordingPlayback();" "\n" "}" "\n" "\n");
        fwrite(pwn_file, "StartPlayback()" "\n" "{" "\n");
        fwrite(pwn_file, "\t" "StartRecordingPlayback(1, \"dir_rec\\\\");
	}
	else
	{
		fwrite(pwn_file, "public OnNPCSpawn()" "\n" "{" "\n");
        fwrite(pwn_file, "\t" "StartPlayback();" "\n" "}" "\n" "\n");
        fwrite(pwn_file, "StartPlayback()" "\n" "{" "\n");
        fwrite(pwn_file, "\t" "StartRecordingPlayback(2, \"dir_rec\\\\");
	}
	fwrite(pwn_file, filename);
	fwrite(pwn_file, "\");" "\n" "}");
	fclose(pwn_file);
}

npcmode_getid(const name[])
{
	for(new id = 0; id < MAX_NPC; ++id)
	{
		if(rec_data[id][rec_type])
		{
			if(!strcmp(rec_name[id], name, true))
			{
				return id;
			}
		}
	}
	return 0xFFFF;
}

IsNumeric(const string[])
{
	for(new i = 0, len = strlen(string); i < len; ++i)
	{
		if(string[i] > '9' || string[i] < '0')
		{
			return 0;
		}
	}
	return 1;
}
