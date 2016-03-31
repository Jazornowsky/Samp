/***
*
* File: wp_utils_sn.inc
* Auth: Damian Wojdat
* Date: 28.08.2012
* Desc: Internal script function related to san news faction.
*
*************************************************************************************************************/

stock RefreshSanNewsMsgForAll()
{
	foreach(Player, i)
	{
		if(!gPlayerLogged[i])
		{
			continue;
		}
		
		RefreshSanNewsMsg(i);
	}
}

stock RefreshSanNewsMsg(playerid)
{
	static string[255];

	if(!gSanNewsMsgs[gSanNewsCurrentMsg][mUsed])
	{
		format(string, sizeof(string), "SAN NEWS: Brak wiadomosci...");
		PlayerTextDrawSetString(playerid, gPlayerVars[playerid][mSanNewsTextDrawId], string);
	}
	else
	{
		format(string, sizeof(string), "SAN NEWS: %s", gSanNewsMsgs[gSanNewsCurrentMsg][mContent]);
		PlayerTextDrawSetString(playerid, gPlayerVars[playerid][mSanNewsTextDrawId], string);
	}
}

stock CreateSanNewsBox(playerid)
{
	if(!gPlayerVars[playerid][mVehicleStatusShow])
	{
		gPlayerVars[playerid][mSanNewsTextDrawId] = CreatePlayerTextDraw(playerid, 0.0, 434.5, " ");
	}
	else
	{
		gPlayerVars[playerid][mSanNewsTextDrawId] = CreatePlayerTextDraw(playerid, 0.0, 427.0, " ");
	}
	
	PlayerTextDrawUseBox(playerid, gPlayerVars[playerid][mSanNewsTextDrawId], 1);
	PlayerTextDrawBoxColor(playerid, gPlayerVars[playerid][mSanNewsTextDrawId], 0x000000AA);
	PlayerTextDrawAlignment(playerid, gPlayerVars[playerid][mSanNewsTextDrawId], 0);
	PlayerTextDrawBackgroundColor(playerid, gPlayerVars[playerid][mSanNewsTextDrawId], 0x000000ff);
	PlayerTextDrawFont(playerid, gPlayerVars[playerid][mSanNewsTextDrawId], 1);
	PlayerTextDrawLetterSize(playerid, gPlayerVars[playerid][mSanNewsTextDrawId], 0.15, 0.525);
	PlayerTextDrawColor(playerid, gPlayerVars[playerid][mSanNewsTextDrawId], 0xffffffff);
	PlayerTextDrawSetOutline(playerid, gPlayerVars[playerid][mSanNewsTextDrawId], 1);
	PlayerTextDrawSetProportional(playerid, gPlayerVars[playerid][mSanNewsTextDrawId], 1);
	PlayerTextDrawSetShadow(playerid, gPlayerVars[playerid][mSanNewsTextDrawId], 1);
	
	PlayerTextDrawShow(playerid, gPlayerVars[playerid][mSanNewsTextDrawId]);
	
	RefreshSanNewsMsg(playerid);
}

stock RedrawSanNewsBox(playerid)
{
	static string[255];
	
	new route;

	if(!gPlayerVars[playerid][mSanNewsStatus])
	{
		PlayerTextDrawHide(playerid, gPlayerVars[playerid][mSanNewsTextDrawId]);
		return;
	}
	
	if(!gPlayerVars[playerid][mSanNewsTextDrawCreated])
	{
		gPlayerVars[playerid][mSanNewsTextDrawCreated] = 1;
		CreateSanNewsBox(playerid);
	}
	
	if(gPlayerVars[playerid][mVehicleStatusShowChanged])
	{
		PlayerTextDrawDestroy(playerid, gPlayerVars[playerid][mSanNewsTextDrawId]);
		CreateSanNewsBox(playerid);
	}
	
	if(gSanNewsTimeLeft > 0)
	{
		gSanNewsTimeLeft--;
	}
	
	if(gSanNewsTimeLeft == 0)
	{
		gSanNewsTimeLeft = 50;
		
		do
		{
			gSanNewsCurrentMsg++;
			route++;
			
			if(route == sizeof(gSanNewsMsgs))
			{
				format(string, sizeof(string), "SAN NEWS: Brak wiadomosci...");
				PlayerTextDrawSetString(playerid, gPlayerVars[playerid][mSanNewsTextDrawId], string);
				
				return;
			}
			
			if(gSanNewsCurrentMsg >= sizeof(gSanNewsMsgs))
			{
				gSanNewsCurrentMsg = 0;
			}
		}
		while(!gSanNewsMsgs[gSanNewsCurrentMsg][mUsed]);
		
		format(string, sizeof(string), "SAN NEWS: %s", gSanNewsMsgs[gSanNewsCurrentMsg][mContent]);
		PlayerTextDrawSetString(playerid, gPlayerVars[playerid][mSanNewsTextDrawId], string);
	}
}