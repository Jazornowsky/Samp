#include <a_samp>
#include <core>
#include <float>

new gGatePdDm1, gGatePdDm2;

public OnPlayerCommandText(playerid, cmdtext[])
{
	static
		string[256],
		cmd[256];
	strdel(string, 0, sizeof(string));
	cmd = strtok(cmdtext, idx);
	
	return 0;
}

public OnFilterScriptInit()
{
	
	return 1;
}