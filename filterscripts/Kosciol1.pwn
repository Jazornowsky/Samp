// By SultanS 2009-2010.Koœció³:du¿y.Nie kopiuj mojego pomys³u. W razie k³opotów, pisz na forum lub na gg:8033650.
#include <a_samp>
#pragma tabsize 0 // z powodu œcis³ego kodu, nie ¿ebym nie umia³ go u³o¿yæ jak "pr0".
new kosciol,kosciol2,kosciol3,timer;
forward Timer();forward SetPlayerPosWithObjects(playerid,Float:x,Float:y,Float:z);
public OnFilterScriptInit(){  
kosciol = CreateObject(1508, 2275.4558, -1339.408, -45.5229, 0, 0, 0);
kosciol2 = CreateObject(1965, 2273.7576, -1339.3734, -51.6603, 0.8594, 90.2409, 270);
kosciol3 = CreateObject(997, 2273.7747, -1337.755, -51.4828, 0, 0, 270);
CreateObject(14444, 2250.0850, -1349.0112, -51.7378, 0.0000, 0.0000, 0.9369); // obiekt po TP
timer = SetTimer("Timer",1000,1); return 1; }
public OnPlayerCommandText(playerid, cmdtext[]) {
if (strcmp("/kosciol-open", cmdtext) == 0) {MoveObject(kosciol, 2275.4504, -1334.2139, -45.563 ,0.395);
MoveObject(kosciol2, 2273.7612,-1339.3981,-47.2429,0.37);MoveObject(kosciol3, 2273.7266,-1337.7629,-47.1096,0.37);
return 1; }
if (strcmp("/kosciol-close", cmdtext) == 0) {MoveObject(kosciol, 2275.4558, -1339.408, -45.5229 ,0.4);
MoveObject(kosciol2, 2273.7576,-1339.3734,-51.6603,0.37);MoveObject(kosciol3,2273.7747,-1337.755,-51.4828,0.37);
return 1 ; }
if(strcmp(cmdtext,"/kosciol", true)==0){SetPlayerPos(playerid,2274.2478,-1355.2225,-49.9614);return 1;}return 0;}
enum object_info {modelid,Float:ox,Float:oy,Float:oz,Float:orx,Float:ory,Float:orz,Float:viewdist }
new Objects[][object_info] = { // obiekty otrzymane deluxem.
{1491, 2250.8506, -1345.8987, -51.5450, 0.0000, 0.0000, 180.0001, 70.0},
{1491, 2247.8247, -1345.8949, -51.5522, 0.0000, 0.0000, 0.0000, 70.0},
{2576, 2251.9980, -1353.6322, -51.5190, 0.0000, 0.0000, 180.0001, 70.0}};
enum player_info{objid[sizeof(Objects)],bool:view[sizeof(Objects)]}new Player[MAX_PLAYERS][player_info];
bool:IsInReach(Float:x,Float:y,Float:z,Float:x2,Float:y2,Float:z2,Float:dist){
x=(x>x2)?x-x2:x2-x;if(x>dist)return false;y=(y>y2)?y-y2:y2-y;if(y>dist)return false;
z=(z>z2)?z-z2:z2-z;if(z>dist)return false;return true;} // Nie ruszaæ - u³o¿enie: Sultans
public OnFilterScriptExit(){for(new i=0;i<MAX_PLAYERS;i++){for(new o=0;o< sizeof(Objects);o++){if(Player[i][view][o]){
Player[i][view][o]=false;DestroyPlayerObject(i,Player[i][objid][o]);}}}KillTimer(timer);}public OnPlayerConnect(playerid){
for(new i=0;i<sizeof(Objects);i++)Player[playerid][view][i]=false;}public OnPlayerDisconnect(playerid){
for(new i=0;i<sizeof(Objects);i++){if(Player[playerid][view][i]){Player[playerid][view][i]=false;
DestroyPlayerObject(playerid,Player[playerid][objid][i]);}}}public Timer(){for(new i=0;i<MAX_PLAYERS; i++)
if(IsPlayerConnected(i))PlayerObjectUpdate(i);}PlayerObjectUpdate(playerid){new Float:pos[3];
GetPlayerPos(playerid,pos[0],pos[1],pos[2]);for(new i=0;i<sizeof(Objects);i++){if(!Player[playerid][view][i]){
if(IsInReach(pos[0],pos[1],pos[2],Objects[i][ox],Objects[i][oy],Objects[i][oz],Objects[i][viewdist])){Player[playerid][view][i]=true;
Player[playerid][objid][i]=CreatePlayerObject(playerid,Objects[i][modelid],Objects[i][ox],Objects[i][oy],Objects[i][oz],Objects[i][orx],Objects[i][ory],Objects[i][orz]);}
}else if(!IsInReach(pos[0],pos[1],pos[2],Objects[i][ox],Objects[i][oy],Objects[i][oz],Objects[i][viewdist])){Player[playerid][view][i]=false;
DestroyPlayerObject(playerid,Player[playerid][objid][i]);}}}public SetPlayerPosWithObjects(playerid,Float:x,Float:y,Float:z){
for(new i=0;i< sizeof(Objects);i++){if(!Player[playerid][view][i]){if(IsInReach(x,y,z,Objects[i][ox],Objects[i][oy],Objects[i][oz],Objects[i][viewdist])){Player[playerid][view][i]=true;
Player[playerid][objid][i]=CreatePlayerObject(playerid,Objects[i][modelid],Objects[i][ox],Objects[i][oy],Objects[i][oz],Objects[i][orx],Objects[i][ory],Objects[i][orz]);}
}else if(!IsInReach(x,y,z,Objects[i][ox],Objects[i][oy],Objects[i][oz],Objects[i][viewdist])){Player[playerid][view][i]=false;
DestroyPlayerObject(playerid,Player[playerid][objid][i]);}}SetPlayerPos(playerid,Float:x,Float:y,Float:z); } public OnPlayerSpawn(playerid)PlayerObjectUpdate(playerid);
