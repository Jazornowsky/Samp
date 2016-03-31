/***
*
* File: wp_areas.inc
* Auth: Damian Wojdat
* Date: 15.09.2011
* Desc: Declarations, macros and variables.
*
*************************************************************************************************************/

stock LoadCustomAreas()
{	
	gASanFierro = CreateDynamicRectangle(-2951.0, -854.0, -1472.0, 1434.0);
	//gALosSantos1 = CreateDynamicRectangle(58.0, -2706.0, 1564.0, -887);
	//gALosSantos2 = CreateDynamicRectangle(1695.0, -2734.0, 2818.0, -957);
	gALosSantos3 = CreateDynamicRectangle(-1488.0, -1736.0, 1657.0, -1583.0);
	gALosSantos4 = CreateDynamicRectangle(680.0, -1415.0, 834.0, -1301.0);
	gALosSantos5 = CreateDynamicRectangle(2734.0, -1645.0, 2860.0, -1505.0);
	gALosSantos6 = CreateDynamicRectangle(2107.0, -2255.0, 2359.0, -2059.0);
	gALosSantos7 = CreateDynamicRectangle(1740.0, -1980.0, 1850.0, -1870.0);
	gALosSantos8 = CreateDynamicRectangle(1604, -2004, 1884, -1794);
	gAAngelPine = CreateDynamicRectangle(-2277.0, -2546.0, -2058.0, -2212.0);
	gArea_Molo = CreateDynamicRectangle(-3054.0, 465.0, -2923.0, 604.0);
	gArea_Pool = CreateDynamicRectangle(557.0, -2205.0, 600.0, -2148.0);
	gAMontgomery = CreateDynamicRectangle(1143.0,124.0,1464.0,367.0);
	gAPalominoCreek = CreateDynamicRectangle(2125.0,-132.0,2562.0,155.0);
	gABountyBay = CreateDynamicRectangle(64.0, -384.0, 384.0, 64.0);
	gADilimore = CreateDynamicRectangle(558.0, -693.0, 852.0, -391.0);
	gAFortCarson = CreateDynamicRectangle(-528.0, 1382.0, 209.0, 775.0);
	gABlueBerryFarm = CreateDynamicRectangle(-293.0, 245.0, 126.0, -202.0);
	gArea_MW_LasVenturas = CreateDynamicRectangle(859.0,-379.0,3225.0,3360.0);
	gArea_MW_SanFierro = CreateDynamicRectangle(-3420.0,-1140.0,-1005.0,1800.0);
	gArea_MW_LosSantos = CreateDynamicRectangle(-255.0,-2910.0,3405.0,-585.0);
	gArea_Prison1 = CreateDynamicCircle(-328.2, 1558.7, 160.0, 0);
	gArea_CarTest = CreateDynamicCube(-2095.32, -280.05, 30.0, -2012.25, -104.17, 40.0);
	// TODO: transfer this somwehere more apropriate...
	gShips[0][shipObjID] = CreateObject(8493, gShips[0][shipX], gShips[0][shipY], gShips[0][shipZ], 0.0, 0.0, gShips[0][shipRZ]);
}