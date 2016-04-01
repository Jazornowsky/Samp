/***
*
* File: wp_utils_sn.inc
* Auth: Damian Wojdat
* Date: 28.08.2012
* Desc: Internal script function related to san news faction.
*
*************************************************************************************************************/

stock RedrawSanNewsBox(playerid)
{
	if(gPlayerVars[playerid][mSanNewsStatus])
		TextDrawDestroy(gPlayerVars[playerid][mSanNewsStatus]);
	if(!gPlayerVars[playerid][mVehicleStatusShow])
		gPlayerVars[playerid][mSanNewsStatus] = TextDrawCreate(0.0, 434.5, " ");
	else
		gPlayerVars[playerid][mSanNewsStatus] = TextDrawCreate(0.0, 427.0, " ");
	TextDrawUseBox(gPlayerVars[playerid][mSanNewsStatus], 1);
	TextDrawBoxColor(gPlayerVars[playerid][mSanNewsStatus], 0x000000AA);
	TextDrawAlignment(gPlayerVars[playerid][mSanNewsStatus], 0);
	TextDrawBackgroundColor(gPlayerVars[playerid][mSanNewsStatus], 0x000000ff);
	TextDrawFont(gPlayerVars[playerid][mSanNewsStatus], 1);
	TextDrawLetterSize(gPlayerVars[playerid][mSanNewsStatus], 0.15, 0.525);
	TextDrawColor(gPlayerVars[playerid][mSanNewsStatus], 0xffffffff);
	TextDrawSetOutline(gPlayerVars[playerid][mSanNewsStatus], 1);
	TextDrawSetProportional(gPlayerVars[playerid][mSanNewsStatus], 1);
	TextDrawSetShadow(gPlayerVars[playerid][mSanNewsStatus], 1);
	if(strlen(gSanNewsMsg[gSanNewsMsgId]))
		TextDrawSetString(gPlayerVars[playerid][mSanNewsStatus], gSanNewsMsg[gSanNewsMsgId]);
	else
		TextDrawSetString(gPlayerVars[playerid][mSanNewsStatus], "SAN NEWS: Brak nowych wiadomosci...");
	gPlayerVars[playerid][mSanNewsStatusShow] = 1;
	TextDrawShowForPlayer(playerid, gPlayerVars[playerid][mSanNewsStatus]);
}