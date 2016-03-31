#define EVENT1WORLD 9999 
#define EVENT2WORLD 9998 
#define EVENT2INT 15 
#define KEYPAD_DOOR_1 1
#define KEYPAD_DOOR_2 2
#define KEYPAD_DOOR_3 3


new gEvent2players[CUSTOM_MAX_PLAYERS],
	gEvent2playersPoints[CUSTOM_MAX_PLAYERS],
	gEvent2winners[CUSTOM_MAX_PLAYERS],
	gEvent2timeToJoin,
	gEvent2timeToStart,
	gEvent2prize,
	gEvent2isRunning,
	gEvent2isStarted,
	Text:gEvent2noteText1,
	PlayerText:gEvent2noteText2[CUSTOM_MAX_PLAYERS],
	gEvent2currentNote,
	gEvent2noteProgress,
	gEvent2noteProgressStar,
	gEvent2timeToEnd;
	
new Float:gEvent2spawns[8][4] =
{
	{-1390.81, 1001.89, 1024.2, 135.0} ,{-1398.67, 1004.63, 1024.2, 180.0} ,{-1406.17, 1001.33, 1024.2, 235.0} ,
	{-1409.31, 994.11, 1024.2, 275.0} ,{-1405.91, 986.31, 1024.2, 315.0} ,{-1398.36, 982.72, 1024.2, 0.0} ,
	{-1390.91, 986.3, 1024.2, 45.0} ,{-1388.13, 994.0, 1024.2, 90.0}
};

new Float:gEvent2vehSpawns[8][4] =
{
	{-1413.13, 993.964, 1024.88, 270.0} ,{-1398.66, 1008.32, 1024.8, 180.0} ,{-1384.19, 994.091, 1024.83, 90.0} ,
	{-1388.12, 983.829, 1024.88, 45.0} ,{-1408.77, 1004.23, 1024.84, 225.0} ,{-1387.75, 1005.02, 1024.83, 135.0} ,
	{-1408.58, 983.773, 1024.81, 315.0} ,{-1398.27, 978.668, 1024.83, 0.0}
};


new	gEvent1players[CUSTOM_MAX_PLAYERS],
	gEvent1timeToJoin,
	gEvent1timeToStart,
	gEvent1prize,
	gEvent1isRunning,
	gEvent1isStarted,
	gEvent1objects[7],
	gEvent1cp[3],
	gEvent1pickup,
	gEvent1codePickups[3],
	gEvent1code[3];								// Win code to open gate
	
	
new Float:gEvent1spawns[9][4] =
{
	{101.2032,1930.9553,18.3300,266.4993} ,{101.4914,1928.5717,18.3334,266.4993} ,{101.7253,1925.9855,18.3341,266.4993} ,
	{102.0164,1923.3114,18.3367,266.4993} ,{102.3168,1920.8043,18.3375,266.4993} ,{102.6351,1918.8785,18.3526,266.4993} ,
	{102.9418,1916.7843,18.3511,266.4993} ,{103.2301,1914.4163,18.3762,266.4993} ,{103.4854,1912.1718,18.4395,266.4993}
};

enum playerBasicInfo
{
	Float:mPosX,
	Float:mPosY,
	Float:mPosZ,
	mWorld,
	mInterior
};

new gEventplayerData[CUSTOM_MAX_PLAYERS][playerBasicInfo];

new Float:gEvent1pickupsLvl1[7][3] =
{                             
	{211.5464,1812.2909,21.8594} ,{172.0143,1834.8248,17.6406} ,{117.8953,1871.2706,17.8359} ,
	{103.91,1901.35,25.49} ,{282.4868,1829.9612,17.6481} ,{154.74,1903.43,18.73} ,
	{192.4710,1940.0167,17.6406}
};

new Float:gEvent1pickupsLvl2[7][3] =
{
	{244.0067,1878.0615,8.7578} ,{238.9237,1862.4539,8.7578} ,{265.6482,1839.5363,6.4104} ,
	{332.0314,1837.6624,7.8281} ,{280.1072,1837.7607,11.5348} ,{276.0665,1870.2676,8.7578} ,
	{266.0165,1852.6895,8.7578}
};

new Float:gEvent1pickupsLvl3[7][3] =
{
	{328.2001,1846.7675,7.7266} ,{280.8895,1853.5070,8.7649} ,{262.1155,1886.6445,-30.3906} ,
	{262.1157,1886.6431,-30.3906} ,{268.2729,1891.6575,-12.8621} ,{265.8628,1840.6222,6.7261} ,
	{255.5310,1878.0601,8.7578}
};