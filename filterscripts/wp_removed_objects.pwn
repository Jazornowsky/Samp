#include <a_samp>

#define FILTERSCRIPT

public OnPlayerConnect(playerid)
{
	/* Police office modified */	
	RemoveBuildingForPlayer(playerid, 14883, 320.8672, 314.2109, 1000.1484, 0.25);


	/* Removed default ring */
	RemoveBuildingForPlayer(playerid, 14791, 766.6250, -68.3281, 1001.6953, 0.25);
	RemoveBuildingForPlayer(playerid, 14841, 766.6250, -68.3281, 1001.6953, 0.25);
	
	
	/* Some PC building for replacement */
	RemoveBuildingForPlayer(playerid, 13251, 2271.4219, 74.1875, 25.4766, 0.25);
	RemoveBuildingForPlayer(playerid, 13461, 2373.2344, 29.1719, 30.3438, 0.25);
	RemoveBuildingForPlayer(playerid, 1440, 2234.6250, 69.9453, 25.9844, 0.25);
	RemoveBuildingForPlayer(playerid, 1687, 2241.7031, 73.8281, 29.2578, 0.25);
	RemoveBuildingForPlayer(playerid, 1688, 2240.3750, 56.8828, 32.4688, 0.25);
	RemoveBuildingForPlayer(playerid, 1688, 2254.5391, 60.2188, 29.4922, 0.25);
	RemoveBuildingForPlayer(playerid, 1691, 2247.8047, 71.7266, 28.8281, 0.25);
	RemoveBuildingForPlayer(playerid, 1438, 2257.7656, 77.5313, 25.3906, 0.25);
	RemoveBuildingForPlayer(playerid, 1687, 2270.6016, 54.6250, 29.7656, 0.25);
	RemoveBuildingForPlayer(playerid, 1690, 2277.7422, 56.2109, 30.1641, 0.25);
	RemoveBuildingForPlayer(playerid, 12964, 2271.4219, 74.1875, 25.4766, 0.25);
	RemoveBuildingForPlayer(playerid, 1688, 2270.5391, 70.2422, 31.9609, 0.25);
	RemoveBuildingForPlayer(playerid, 1691, 2264.5156, 77.5000, 34.3828, 0.25);
	RemoveBuildingForPlayer(playerid, 1440, 2272.2266, 65.2344, 25.9844, 0.25);
	RemoveBuildingForPlayer(playerid, 1438, 2269.8438, 64.8516, 25.3906, 0.25);


    // automaty
	RemoveBuildingForPlayer(playerid, 955, 0, 0, 0, 3000);
	RemoveBuildingForPlayer(playerid, 956, 0, 0, 0, 3000);
	RemoveBuildingForPlayer(playerid, 1302, 0, 0, 0, 3000);
	
	
	/*
	* Fort Carson
	*/
	// CPn
	RemoveBuildingForPlayer(playerid, 16478, 55.5625, 1220.6797, 17.9219, 0.25);
	RemoveBuildingForPlayer(playerid, 16477, 55.5625, 1220.6797, 17.9219, 0.25);
	RemoveBuildingForPlayer(playerid, 1413, 66.7969, 1207.1563, 18.9922, 0.25);
	RemoveBuildingForPlayer(playerid, 1413, 72.0859, 1206.8828, 18.9922, 0.25);
	RemoveBuildingForPlayer(playerid, 1413, 73.0938, 1228.0391, 19.0781, 0.25);
	RemoveBuildingForPlayer(playerid, 1413, 77.3594, 1206.8828, 18.9922, 0.25);
	RemoveBuildingForPlayer(playerid, 1413, 78.2578, 1226.8516, 19.3672, 0.25);
	RemoveBuildingForPlayer(playerid, 1413, 83.2813, 1225.2656, 19.8203, 0.25);

	RemoveBuildingForPlayer(playerid, 1294, -199.6719, 1123.5547, 23.2031, 0.25);
	RemoveBuildingForPlayer(playerid, 1294, -186.4609, 1123.3984, 23.2031, 0.25);
	
	// 29.04.2012 01:22
	RemoveBuildingForPlayer(playerid, 16478, 55.5625, 1220.6797, 17.9219, 0.25);
	RemoveBuildingForPlayer(playerid, 16477, 55.5625, 1220.6797, 17.9219, 0.25);
	RemoveBuildingForPlayer(playerid, 16479, 86.2422, 1214.0391, 17.7422, 0.25);
	
	// 29.04.2012 01:39
	RemoveBuildingForPlayer(playerid, 16479, 86.2422, 1214.0391, 17.7422, 0.25); // liny fc
	
	
	// Country 0 0 0
	RemoveBuildingForPlayer(playerid, 1412, 160.4609, -61.7656, 1.7891, 0.25);
	RemoveBuildingForPlayer(playerid, 1412, 165.7422, -61.7656, 1.7891, 0.25);
	
	
	// Palomino Creek fences
	RemoveBuildingForPlayer(playerid, 1407, 0.0, 0.0, 0.0, 3000.0);
	RemoveBuildingForPlayer(playerid, 1408, 0.0, 0.0, 0.0, 3000.0);
	RemoveBuildingForPlayer(playerid, 1410, 0.0, 0.0, 0.0, 3000.0);
	RemoveBuildingForPlayer(playerid, 1418, 0.0, 0.0, 0.0, 3000.0);
	RemoveBuildingForPlayer(playerid, 1419, 0.0, 0.0, 0.0, 3000.0);
	RemoveBuildingForPlayer(playerid, 1446, 0.0, 0.0, 0.0, 3000.0);
	RemoveBuildingForPlayer(playerid, 1468, 0.0, 0.0, 0.0, 3000.0);
	// RemoveBuildingForPlayer(playerid, 1410, 2213.7813, 62.1484, 26.1328, 0.25);
	// RemoveBuildingForPlayer(playerid, 1410, 2213.7813, 66.9453, 26.1328, 0.25);
	// RemoveBuildingForPlayer(playerid, 1410, 2213.7813, 74.1953, 26.1328, 0.25);
	// RemoveBuildingForPlayer(playerid, 1410, 2211.4844, 76.5313, 26.4688, 0.25);
	// RemoveBuildingForPlayer(playerid, 1410, 2206.7578, 76.5313, 26.9531, 0.25);
	// RemoveBuildingForPlayer(playerid, 1419, 2213.9063, 93.7969, 26.0078, 0.25);
	// RemoveBuildingForPlayer(playerid, 1419, 2213.9063, 97.8828, 26.0078, 0.25);
	// RemoveBuildingForPlayer(playerid, 1419, 2207.6875, 91.7656, 26.6172, 0.25);
	// RemoveBuildingForPlayer(playerid, 1419, 2211.7734, 91.7656, 26.1953, 0.25);
	// RemoveBuildingForPlayer(playerid, 1419, 2213.9063, 101.9688, 26.0078, 0.25);
	// RemoveBuildingForPlayer(playerid, 1419, 2213.9063, 106.3906, 26.0078, 0.25);
	// RemoveBuildingForPlayer(playerid, 1418, 2235.7266, 101.9063, 26.2422, 0.25);
	// RemoveBuildingForPlayer(playerid, 1418, 2239.2344, 101.9063, 26.2422, 0.25);
	// RemoveBuildingForPlayer(playerid, 1418, 2242.7422, 101.9063, 26.2422, 0.25);
	// RemoveBuildingForPlayer(playerid, 1418, 2246.2578, 101.9063, 26.2422, 0.25);
	// RemoveBuildingForPlayer(playerid, 1418, 2249.7656, 101.9063, 26.2422, 0.25);
	// RemoveBuildingForPlayer(playerid, 1418, 2257.2422, 101.9063, 26.2422, 0.25);
	// RemoveBuildingForPlayer(playerid, 1419, 2207.7422, 108.4844, 27.0000, 0.25);
	// RemoveBuildingForPlayer(playerid, 1419, 2211.7891, 108.4844, 26.3359, 0.25);
	// RemoveBuildingForPlayer(playerid, 1419, 2211.5859, 116.5156, 26.3672, 0.25);
	// RemoveBuildingForPlayer(playerid, 1419, 2207.5313, 116.5156, 27.0000, 0.25);
	// RemoveBuildingForPlayer(playerid, 1419, 2283.7734, 16.8906, 27.9609, 0.25);
	// RemoveBuildingForPlayer(playerid, 1419, 2283.7734, 12.8125, 27.9609, 0.25);
	// RemoveBuildingForPlayer(playerid, 1419, 2283.7734, 8.7266, 27.9609, 0.25);
	// RemoveBuildingForPlayer(playerid, 1419, 2283.7734, 4.6484, 27.9609, 0.25);
	// RemoveBuildingForPlayer(playerid, 1419, 2283.7734, 0.5625, 27.9609, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2269.7656, 101.9297, 26.0469, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2275.2656, 101.9297, 26.0469, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2280.8672, 101.9297, 26.0469, 0.25);
	// RemoveBuildingForPlayer(playerid, 1418, 2258.9219, 103.7188, 26.5156, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2283.7734, 104.7266, 26.3281, 0.25);
	// RemoveBuildingForPlayer(playerid, 1418, 2258.9219, 107.1797, 27.0625, 0.25);
	// RemoveBuildingForPlayer(playerid, 1418, 2333.8438, 103.4453, 26.2422, 0.25);
	// RemoveBuildingForPlayer(playerid, 1418, 2333.8438, 106.9531, 26.2422, 0.25);
	// RemoveBuildingForPlayer(playerid, 1418, 2333.8438, 110.4609, 26.2422, 0.25);
	// RemoveBuildingForPlayer(playerid, 1418, 2333.8438, 113.9766, 26.2422, 0.25);
	// RemoveBuildingForPlayer(playerid, 1418, 2333.8438, 117.4844, 26.2422, 0.25);
	// RemoveBuildingForPlayer(playerid, 1418, 2328.3594, 101.7734, 26.7969, 0.25);
	// RemoveBuildingForPlayer(playerid, 1418, 2331.8438, 101.7734, 26.3906, 0.25);
	// RemoveBuildingForPlayer(playerid, 1419, 2354.1094, 116.5938, 26.0078, 0.25);
	// RemoveBuildingForPlayer(playerid, 1419, 2354.1094, 112.5000, 26.0078, 0.25);
	// RemoveBuildingForPlayer(playerid, 1419, 2354.1094, 108.4063, 26.0078, 0.25);
	// RemoveBuildingForPlayer(playerid, 1419, 2354.1094, 104.3203, 26.0078, 0.25);
	// RemoveBuildingForPlayer(playerid, 1419, 2356.1172, 101.9609, 26.2109, 0.25);
	// RemoveBuildingForPlayer(playerid, 1419, 2360.2109, 101.9609, 26.6172, 0.25);
	// RemoveBuildingForPlayer(playerid, 1468, 2225.2188, 151.8516, 26.6953, 0.25);
	// RemoveBuildingForPlayer(playerid, 1468, 2242.9219, 151.8516, 26.6953, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2264.1094, 151.8359, 26.0391, 0.25);
	// RemoveBuildingForPlayer(playerid, 1468, 2227.9688, 154.4063, 26.9453, 0.25);
	// RemoveBuildingForPlayer(playerid, 1468, 2240.0078, 154.4141, 26.8750, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2256.6250, 154.3828, 26.2344, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2261.3516, 154.4141, 26.2344, 0.25);
	// RemoveBuildingForPlayer(playerid, 1468, 2227.9688, 159.7031, 27.3281, 0.25);
	// RemoveBuildingForPlayer(playerid, 1468, 2240.0078, 159.7109, 27.2578, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2256.6250, 159.8672, 26.6719, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2261.3516, 159.8984, 26.6719, 0.25);
	// RemoveBuildingForPlayer(playerid, 1468, 2227.9688, 165.0000, 27.5859, 0.25);
	// RemoveBuildingForPlayer(playerid, 1468, 2240.0078, 165.0000, 27.5078, 0.25);
	// RemoveBuildingForPlayer(playerid, 1418, 2328.5000, 126.7109, 27.1016, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2274.3281, 151.8125, 26.0156, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2279.8594, 151.8125, 26.0156, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2285.3984, 151.8125, 26.0156, 0.25);
	// RemoveBuildingForPlayer(playerid, 1468, 2326.0781, 151.2969, 27.5156, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2296.2656, 156.9844, 26.8672, 0.25);
	// RemoveBuildingForPlayer(playerid, 1418, 2333.8438, 128.4844, 26.2422, 0.25);
	// RemoveBuildingForPlayer(playerid, 1418, 2331.9609, 126.7109, 26.5078, 0.25);
	// RemoveBuildingForPlayer(playerid, 1468, 2333.8594, 141.1016, 26.7344, 0.25);
	// RemoveBuildingForPlayer(playerid, 1468, 2333.8594, 146.3984, 26.7344, 0.25);
	// RemoveBuildingForPlayer(playerid, 1468, 2331.3516, 151.2969, 26.9844, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2333.7969, 162.3047, 26.0469, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2333.7969, 167.8047, 26.0469, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2333.7969, 173.3047, 26.0469, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2333.7969, 178.8047, 26.0469, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2333.7969, 184.3047, 26.0469, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2333.7969, 190.6719, 26.0469, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2331.0000, 176.6953, 26.2969, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2331.0000, 193.5781, 26.5078, 0.25);
	// RemoveBuildingForPlayer(playerid, 1410, 2354.1016, 189.9219, 26.2188, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2354.0938, 165.9766, 26.0469, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2354.0938, 160.5078, 26.0469, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2354.0938, 155.0313, 26.0469, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2356.8203, 152.3047, 26.3750, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2354.1016, 137.1953, 26.0469, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2354.1016, 131.7266, 26.0469, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2359.5547, 126.9063, 26.5703, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2333.9688, 221.7109, 26.0156, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2333.9688, 227.1797, 26.0156, 0.25);
	// RemoveBuildingForPlayer(playerid, 1410, 2354.1016, 199.3594, 26.2188, 0.25);
	// RemoveBuildingForPlayer(playerid, 1410, 2354.1016, 194.6406, 26.2188, 0.25);
	// RemoveBuildingForPlayer(playerid, 1419, 2383.9063, 42.9688, 26.0078, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2383.7500, 1.7266, 26.0391, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2383.7500, 7.2656, 26.0391, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2383.7500, 16.0078, 26.0391, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2383.7500, 21.5469, 26.0391, 0.25);
	// RemoveBuildingForPlayer(playerid, 1468, 2404.0156, 21.8281, 26.7188, 0.25);
	// RemoveBuildingForPlayer(playerid, 1468, 2404.0156, 27.1250, 26.7188, 0.25);
	// RemoveBuildingForPlayer(playerid, 1468, 2404.0156, 6.6641, 26.7188, 0.25);
	// RemoveBuildingForPlayer(playerid, 1468, 2406.7344, 6.6641, 26.7188, 0.25);
	// RemoveBuildingForPlayer(playerid, 1468, 2412.0547, 6.6641, 26.7188, 0.25);
	// RemoveBuildingForPlayer(playerid, 1468, 2453.8203, 17.7500, 26.7188, 0.25);
	// RemoveBuildingForPlayer(playerid, 1468, 2453.8203, 23.0469, 26.7188, 0.25);
	// RemoveBuildingForPlayer(playerid, 1468, 2451.2266, 14.9688, 26.7422, 0.25);
	// RemoveBuildingForPlayer(playerid, 1468, 2451.2344, 26.1875, 26.8047, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2482.3438, 1.8594, 26.0000, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2476.8125, 1.8594, 26.0000, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2487.8750, 1.8594, 26.0000, 0.25);
	// RemoveBuildingForPlayer(playerid, 1419, 2383.9063, 59.3359, 26.0078, 0.25);
	// RemoveBuildingForPlayer(playerid, 1419, 2383.9063, 63.4297, 26.0078, 0.25);
	// RemoveBuildingForPlayer(playerid, 1419, 2383.9063, 47.0625, 26.0078, 0.25);
	// RemoveBuildingForPlayer(playerid, 1419, 2383.9063, 55.2422, 26.0078, 0.25);
	// RemoveBuildingForPlayer(playerid, 1419, 2383.9063, 51.1563, 26.0078, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2431.7109, 51.8125, 26.0000, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2437.2656, 51.8125, 26.0000, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2429.0469, 54.6641, 26.3281, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2426.1797, 51.8125, 26.0000, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2420.6484, 51.8125, 26.0000, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2442.8125, 51.8125, 26.0000, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2445.7500, 54.4609, 26.4297, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2453.7578, 57.0078, 26.8203, 0.25);
	// RemoveBuildingForPlayer(playerid, 1446, 2474.0781, 59.5469, 26.2734, 0.25);
	// RemoveBuildingForPlayer(playerid, 1446, 2476.4297, 57.0234, 26.2266, 0.25);
	// RemoveBuildingForPlayer(playerid, 1446, 2481.1641, 57.0234, 26.2266, 0.25);
	// RemoveBuildingForPlayer(playerid, 1446, 2491.6094, 57.0234, 26.2266, 0.25);
	// RemoveBuildingForPlayer(playerid, 1419, 2383.9063, 71.6094, 26.0078, 0.25);
	// RemoveBuildingForPlayer(playerid, 1419, 2383.9063, 67.5234, 26.0078, 0.25);
	// RemoveBuildingForPlayer(playerid, 1446, 2474.0781, 67.0000, 26.2734, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2474.1797, 87.1875, 26.9844, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2474.1797, 80.0781, 26.9844, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2498.8906, 92.6094, 26.0156, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2474.1797, 92.7500, 26.9844, 0.25);
	// RemoveBuildingForPlayer(playerid, 1446, 2453.7891, 94.8125, 26.2734, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2509.7031, 1.8047, 26.0000, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2515.2500, 1.7969, 26.0000, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2520.7578, 1.7891, 26.0000, 0.25);
	// RemoveBuildingForPlayer(playerid, 1446, 2523.8125, 57.6406, 26.2734, 0.25);
	// RemoveBuildingForPlayer(playerid, 1446, 2523.8125, 62.3516, 26.2734, 0.25);
	// RemoveBuildingForPlayer(playerid, 1446, 2544.0781, 55.9844, 26.1797, 0.25);
	// RemoveBuildingForPlayer(playerid, 1446, 2544.0781, 60.6563, 26.1797, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2554.0625, 76.6797, 26.0156, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2547.9844, 76.6797, 26.0156, 0.25);
	// RemoveBuildingForPlayer(playerid, 1446, 2544.0781, 76.7500, 26.1797, 0.25);
	// RemoveBuildingForPlayer(playerid, 1446, 2544.0781, 91.2109, 26.1797, 0.25);
	// RemoveBuildingForPlayer(playerid, 1446, 2544.0781, 95.9219, 26.1797, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2392.3672, 101.9219, 26.0469, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2386.8984, 101.9219, 26.0469, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2397.9063, 101.9219, 26.0469, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2410.7813, 101.7188, 26.0234, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2416.3125, 101.5781, 26.0234, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2421.8125, 101.4375, 26.0234, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2408.4766, 104.5625, 26.4688, 0.25);
	// RemoveBuildingForPlayer(playerid, 1446, 2453.7891, 99.5469, 26.2734, 0.25);
	// RemoveBuildingForPlayer(playerid, 1446, 2453.7891, 104.2813, 26.2734, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2498.8906, 101.4219, 26.0156, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2498.8906, 98.5313, 26.0156, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2474.1797, 98.9063, 26.9844, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2474.1328, 131.2344, 27.0156, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2474.1328, 124.6953, 27.0156, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2480.5313, 121.7813, 26.0391, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2486.0391, 121.7813, 26.0391, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2474.1328, 142.6797, 27.0156, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2474.1328, 137.1719, 27.0156, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2513.6563, 101.4219, 26.0156, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2519.1641, 101.4219, 26.0156, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2519.3047, 121.8125, 26.0313, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2513.7969, 121.8125, 26.0313, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2539.8281, 121.8125, 26.0313, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2534.3203, 121.8125, 26.0313, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2523.6875, 124.5000, 27.0156, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2523.6875, 130.0078, 27.0156, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2523.6875, 135.9531, 27.0156, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2523.6875, 142.4844, 27.0156, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2205.6641, -83.3438, 26.4219, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2200.0313, -83.3438, 26.7188, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2213.7422, -98.1172, 26.0547, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2213.7422, -92.7109, 26.0547, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2211.2031, -83.3438, 26.1406, 0.25);
	// RemoveBuildingForPlayer(playerid, 1419, 2236.2500, -108.3594, 25.9766, 0.25);
	// RemoveBuildingForPlayer(playerid, 1419, 2242.0313, -108.3594, 25.9766, 0.25);
	// RemoveBuildingForPlayer(playerid, 1419, 2244.1172, -110.4531, 26.1875, 0.25);
	// RemoveBuildingForPlayer(playerid, 1419, 2244.1172, -114.5469, 26.5938, 0.25);
	// RemoveBuildingForPlayer(playerid, 1446, 2283.8750, -143.4453, 28.1797, 0.25);
	// RemoveBuildingForPlayer(playerid, 1446, 2283.8750, -138.7109, 28.1797, 0.25);
	// RemoveBuildingForPlayer(playerid, 1446, 2283.8750, -133.9766, 28.1797, 0.25);
	// RemoveBuildingForPlayer(playerid, 1446, 2283.8750, -129.2500, 28.1797, 0.25);
	// RemoveBuildingForPlayer(playerid, 1446, 2283.8750, -124.5078, 28.0000, 0.25);
	// RemoveBuildingForPlayer(playerid, 1446, 2283.8750, -119.7813, 27.7578, 0.25);
	// RemoveBuildingForPlayer(playerid, 1446, 2283.8750, -115.0781, 27.5234, 0.25);
	// RemoveBuildingForPlayer(playerid, 1446, 2283.8750, -110.8125, 27.3125, 0.25);
	// RemoveBuildingForPlayer(playerid, 1407, 2311.6875, -108.4219, 26.2109, 0.25);
	// RemoveBuildingForPlayer(playerid, 1407, 2306.2344, -108.4219, 26.2109, 0.25);
	// RemoveBuildingForPlayer(playerid, 1407, 2316.4297, -108.4219, 26.2109, 0.25);
	// RemoveBuildingForPlayer(playerid, 1446, 2354.1250, -68.5859, 28.2500, 0.25);
	// RemoveBuildingForPlayer(playerid, 1446, 2354.1250, -73.3203, 28.2500, 0.25);
	// RemoveBuildingForPlayer(playerid, 1446, 2356.5234, -75.6719, 28.2500, 0.25);
	// RemoveBuildingForPlayer(playerid, 1446, 2361.2969, -75.6719, 28.2500, 0.25);
	// RemoveBuildingForPlayer(playerid, 1446, 2366.0625, -75.6719, 28.2500, 0.25);
	// RemoveBuildingForPlayer(playerid, 1446, 2370.8359, -75.6719, 28.2500, 0.25);
	// RemoveBuildingForPlayer(playerid, 1446, 2375.6016, -75.6719, 28.2500, 0.25);
	// RemoveBuildingForPlayer(playerid, 1446, 2179.3672, -50.7500, 28.1797, 0.25);
	// RemoveBuildingForPlayer(playerid, 1446, 2184.1016, -50.7500, 28.1797, 0.25);
	// RemoveBuildingForPlayer(playerid, 1446, 2188.8281, -50.7500, 28.1797, 0.25);
	// RemoveBuildingForPlayer(playerid, 1446, 2207.7344, -50.7500, 27.5234, 0.25);
	// RemoveBuildingForPlayer(playerid, 1446, 2203.0313, -50.7500, 27.7578, 0.25);
	// RemoveBuildingForPlayer(playerid, 1446, 2193.5625, -50.7500, 28.1797, 0.25);
	// RemoveBuildingForPlayer(playerid, 1446, 2212.0000, -50.7500, 27.3125, 0.25);
	// RemoveBuildingForPlayer(playerid, 1446, 2198.3047, -50.7500, 28.0000, 0.25);
	// RemoveBuildingForPlayer(playerid, 1446, 2195.7266, -53.3203, 28.2266, 0.25);
	// RemoveBuildingForPlayer(playerid, 1446, 2354.1250, -40.6875, 27.3828, 0.25);
	// RemoveBuildingForPlayer(playerid, 1446, 2354.1250, -44.9531, 27.5938, 0.25);
	// RemoveBuildingForPlayer(playerid, 1446, 2354.1250, -49.6563, 27.8281, 0.25);
	// RemoveBuildingForPlayer(playerid, 1446, 2354.1250, -54.3828, 28.0703, 0.25);
	// RemoveBuildingForPlayer(playerid, 1446, 2354.1250, -59.1250, 28.2500, 0.25);
	// RemoveBuildingForPlayer(playerid, 1446, 2354.1250, -63.8516, 28.2500, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2213.7422, -34.4219, 26.0391, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2213.7422, -29.0156, 26.0391, 0.25);
	// RemoveBuildingForPlayer(playerid, 1418, 2253.1563, -18.2656, 26.2188, 0.25);
	// RemoveBuildingForPlayer(playerid, 1418, 2256.7188, -18.2656, 26.2188, 0.25);
	// RemoveBuildingForPlayer(playerid, 1418, 2264.6016, -18.2656, 26.2188, 0.25);
	// RemoveBuildingForPlayer(playerid, 1418, 2261.0391, -18.2656, 26.2188, 0.25);
	// RemoveBuildingForPlayer(playerid, 1418, 2275.0156, -18.2656, 26.2188, 0.25);
	// RemoveBuildingForPlayer(playerid, 1418, 2268.1172, -18.2656, 26.2188, 0.25);
	// RemoveBuildingForPlayer(playerid, 1419, 2283.7734, -15.7891, 27.1641, 0.25);
	// RemoveBuildingForPlayer(playerid, 1419, 2283.7734, -11.7031, 27.3750, 0.25);
	// RemoveBuildingForPlayer(playerid, 1419, 2283.7734, -3.5156, 27.8047, 0.25);
	// RemoveBuildingForPlayer(playerid, 1419, 2283.7734, -7.6094, 27.5938, 0.25);
	// RemoveBuildingForPlayer(playerid, 1407, 2431.6563, -38.5078, 26.1797, 0.25);
	// RemoveBuildingForPlayer(playerid, 1407, 2451.1797, -38.5078, 26.2266, 0.25);
	// RemoveBuildingForPlayer(playerid, 1468, 2406.6250, -18.1484, 27.7031, 0.25);
	// RemoveBuildingForPlayer(playerid, 1468, 2411.9297, -18.1484, 27.7031, 0.25);
	// RemoveBuildingForPlayer(playerid, 1468, 2417.2344, -18.1484, 27.7031, 0.25);
	// RemoveBuildingForPlayer(playerid, 1468, 2449.0859, -18.2344, 26.7188, 0.25);
	// RemoveBuildingForPlayer(playerid, 1468, 2443.7891, -18.2344, 26.7188, 0.25);
	// RemoveBuildingForPlayer(playerid, 1468, 2422.5391, -18.1484, 27.7031, 0.25);
	// RemoveBuildingForPlayer(playerid, 1468, 2427.8516, -18.1484, 27.7031, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2490.9219, -18.4453, 26.0000, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2485.4063, -18.4453, 26.0000, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2512.9766, -18.4453, 26.0000, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2507.4609, -18.4453, 26.0000, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2501.9531, -18.4453, 26.0000, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2496.4375, -18.4453, 26.0000, 0.25);
	// RemoveBuildingForPlayer(playerid, 1468, 2404.0156, -10.5078, 26.7188, 0.25);
	// RemoveBuildingForPlayer(playerid, 1468, 2404.0156, -5.2109, 26.7188, 0.25);
	// RemoveBuildingForPlayer(playerid, 1408, 2383.7500, -3.7422, 26.0391, 0.25);
	
	
	// Palomino Creek traffic lights
	RemoveBuildingForPlayer(playerid, 1351, 2218.4453, 52.2734, 25.4375, 0.25);
	RemoveBuildingForPlayer(playerid, 1351, 2234.1328, 97.2188, 25.4375, 0.25);
	RemoveBuildingForPlayer(playerid, 1351, 2283.5625, 36.0313, 25.4375, 0.25);
	RemoveBuildingForPlayer(playerid, 1351, 2283.5625, 36.0313, 25.4375, 0.25);
	RemoveBuildingForPlayer(playerid, 1351, 2283.5625, 86.3594, 25.4375, 0.25);
	RemoveBuildingForPlayer(playerid, 1351, 2304.3438, 97.0781, 25.4375, 0.25);
	RemoveBuildingForPlayer(playerid, 1351, 2469.3516, 31.4609, 25.4375, 0.25);
	RemoveBuildingForPlayer(playerid, 1351, 2404.2109, 47.0078, 25.4375, 0.25);
	RemoveBuildingForPlayer(playerid, 1351, 2458.6797, 51.9063, 25.4375, 0.25);
	RemoveBuildingForPlayer(playerid, 1351, 2539.2188, 31.4609, 25.4375, 0.25);
	RemoveBuildingForPlayer(playerid, 1351, 2528.5469, 51.9063, 25.4375, 0.25);
	RemoveBuildingForPlayer(playerid, 1351, 2288.5078, -88.1016, 25.4375, 0.25);
	RemoveBuildingForPlayer(playerid, 1351, 2349.3047, -38.5703, 25.4375, 0.25);
	RemoveBuildingForPlayer(playerid, 1351, 2283.5625, -34.1641, 25.4375, 0.25);
	RemoveBuildingForPlayer(playerid, 1351, 2304.3438, -22.7344, 25.4375, 0.25);
	RemoveBuildingForPlayer(playerid, 1351, 2338.4297, -17.8516, 25.4375, 0.25);
	RemoveBuildingForPlayer(playerid, 1351, 2388.1328, -17.8516, 25.4375, 0.25);
	RemoveBuildingForPlayer(playerid, 1351, 2474.4453, -2.9922, 25.4375, 0.25);
	
	
	// Palomino Creek telegraphs
	RemoveBuildingForPlayer(playerid, 3339, 1297.2813, 173.5781, 19.4609, 0.25);
	RemoveBuildingForPlayer(playerid, 3340, 1308.3984, 168.1406, 19.4063, 0.25);
	RemoveBuildingForPlayer(playerid, 3341, 1281.2266, 158.0938, 19.3438, 0.25);
	RemoveBuildingForPlayer(playerid, 3343, 1295.9844, 158.7422, 19.3828, 0.25);
	RemoveBuildingForPlayer(playerid, 3343, 1305.0391, 184.9141, 19.3438, 0.25);
	RemoveBuildingForPlayer(playerid, 3345, 1298.6094, 194.2656, 19.3281, 0.25);
	RemoveBuildingForPlayer(playerid, 3345, 1305.2656, 152.7734, 19.2969, 0.25);
	RemoveBuildingForPlayer(playerid, 3344, 1299.7109, 138.7344, 19.3438, 0.25);
	RemoveBuildingForPlayer(playerid, 3344, 1313.9688, 179.8438, 19.3594, 0.25);
	RemoveBuildingForPlayer(playerid, 3170, 1281.2266, 158.0938, 19.3438, 0.25);
	RemoveBuildingForPlayer(playerid, 3168, 1295.9844, 158.7422, 19.3828, 0.25);
	RemoveBuildingForPlayer(playerid, 3171, 1299.7109, 138.7344, 19.3438, 0.25);
	RemoveBuildingForPlayer(playerid, 3172, 1305.2656, 152.7734, 19.2969, 0.25);
	RemoveBuildingForPlayer(playerid, 3168, 1305.0391, 184.9141, 19.3438, 0.25);
	RemoveBuildingForPlayer(playerid, 3169, 1297.2813, 173.5781, 19.4609, 0.25);
	RemoveBuildingForPlayer(playerid, 3171, 1313.9688, 179.8438, 19.3594, 0.25);
	RemoveBuildingForPlayer(playerid, 3167, 1308.3984, 168.1406, 19.4063, 0.25);
	RemoveBuildingForPlayer(playerid, 3172, 1298.6094, 194.2656, 19.3281, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 2176.3438, 51.3203, 25.6406, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 2214.0625, 51.5938, 25.6797, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 2223.8984, 31.7109, 25.6406, 0.25);
	RemoveBuildingForPlayer(playerid, 13374, 2241.4063, 21.4609, 33.1719, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 2233.8906, 81.7891, 25.6797, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 2233.7578, 110.2656, 25.6797, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 2284.0469, 19.2656, 25.6797, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 2262.1953, 51.4844, 25.6797, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 2303.2266, 44.2266, 25.6797, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 2303.7422, 1.0703, 25.6797, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 2284.0703, 81.7578, 25.6797, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 2259.3984, 101.5469, 25.6797, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 2303.8906, 101.5391, 25.6797, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 2334.3438, 68.5234, 25.6797, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 2353.8438, 81.7656, 25.6797, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 2214.1484, 130.7188, 25.6797, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 2245.9063, 151.4922, 25.6797, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 2284.1563, 130.7734, 25.6797, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 2271.3203, 151.4063, 25.6797, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 2334.1875, 126.3047, 25.6797, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 2353.8047, 151.6719, 25.6797, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 2333.9219, 203.7109, 25.6797, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 2384.3203, 32.0313, 25.6797, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 2418.2969, 31.8750, 25.6797, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 2454.1484, 6.6250, 25.6797, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 2473.7891, 31.7813, 25.6797, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 2499.3594, 1.4844, 25.6797, 0.25);
	RemoveBuildingForPlayer(playerid, 13375, 2436.8594, 63.8047, 32.8203, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 2454.0781, 51.4688, 25.6797, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 2499.1953, 51.4766, 25.6797, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 2403.8359, 65.6563, 25.6797, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 2473.8438, 74.4609, 25.6797, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 2524.1016, 31.7813, 25.6797, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 2569.1016, 31.8750, 25.6797, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 2556.5078, 51.5000, 25.6797, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 2524.1797, 76.6641, 25.6797, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 2384.0078, 101.5156, 25.6797, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 2453.8984, 106.8906, 25.6797, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 2499.4609, 121.3594, 25.6797, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 2542.2500, 109.2031, 25.6797, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 2220.0156, -102.2656, 25.6797, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 2246.6016, -88.4531, 25.6797, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 2283.9531, -108.0938, 25.6797, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 2283.5469, -75.5781, 25.6797, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 2303.4531, -88.5547, 25.6797, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 2333.7891, -108.1172, 25.6797, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 2353.8125, -75.7188, 25.6797, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 2214.2031, -50.8438, 25.6797, 0.25);
	RemoveBuildingForPlayer(playerid, 669, 2248.6250, -65.6797, 25.8125, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 2284.4609, -45.0547, 25.6797, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 2246.4453, -38.1484, 25.6797, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 2315.7578, -37.8281, 25.6797, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 2379.0703, -38.2188, 25.6797, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 2284.0703, -18.4922, 25.6797, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 2353.9141, -18.4375, 25.6797, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 2453.8281, -38.1172, 25.6797, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 2403.8594, -18.4297, 25.6797, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 2473.9063, -18.2109, 25.6797, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 2538.0547, -12.4531, 25.6797, 0.25);

	
	// Montgomery camping trailers
	RemoveBuildingForPlayer(playerid, 3339, 1297.2813, 173.5781, 19.4609, 0.25);
	RemoveBuildingForPlayer(playerid, 3340, 1308.3984, 168.1406, 19.4063, 0.25);
	RemoveBuildingForPlayer(playerid, 3341, 1281.2266, 158.0938, 19.3438, 0.25);
	RemoveBuildingForPlayer(playerid, 3343, 1295.9844, 158.7422, 19.3828, 0.25);
	RemoveBuildingForPlayer(playerid, 3343, 1305.0391, 184.9141, 19.3438, 0.25);
	RemoveBuildingForPlayer(playerid, 3345, 1298.6094, 194.2656, 19.3281, 0.25);
	RemoveBuildingForPlayer(playerid, 3345, 1305.2656, 152.7734, 19.2969, 0.25);
	RemoveBuildingForPlayer(playerid, 3344, 1299.7109, 138.7344, 19.3438, 0.25);
	RemoveBuildingForPlayer(playerid, 3344, 1313.9688, 179.8438, 19.3594, 0.25);
	RemoveBuildingForPlayer(playerid, 3170, 1281.2266, 158.0938, 19.3438, 0.25);
	RemoveBuildingForPlayer(playerid, 3168, 1295.9844, 158.7422, 19.3828, 0.25);
	RemoveBuildingForPlayer(playerid, 3171, 1299.7109, 138.7344, 19.3438, 0.25);
	RemoveBuildingForPlayer(playerid, 3172, 1305.2656, 152.7734, 19.2969, 0.25);
	RemoveBuildingForPlayer(playerid, 3168, 1305.0391, 184.9141, 19.3438, 0.25);
	RemoveBuildingForPlayer(playerid, 3169, 1297.2813, 173.5781, 19.4609, 0.25);
	RemoveBuildingForPlayer(playerid, 3171, 1313.9688, 179.8438, 19.3594, 0.25);
	RemoveBuildingForPlayer(playerid, 3167, 1308.3984, 168.1406, 19.4063, 0.25);
	RemoveBuildingForPlayer(playerid, 3172, 1298.6094, 194.2656, 19.3281, 0.25);

	
	// Montgomery - street lights, some boxes, sprunk at top of the building
	RemoveBuildingForPlayer(playerid, 1294, 1321.9141, 343.2344, 23.0234, 0.25);
	RemoveBuildingForPlayer(playerid, 1294, 1351.5859, 410.1172, 23.0234, 0.25);
	RemoveBuildingForPlayer(playerid, 785, 1460.7813, 444.3906, 18.0078, 0.25);
	RemoveBuildingForPlayer(playerid, 785, 1322.0078, 437.5938, 17.3984, 0.25);
	RemoveBuildingForPlayer(playerid, 3594, 1265.5703, 153.3828, 19.4609, 0.25);
	RemoveBuildingForPlayer(playerid, 3594, 1280.9297, 147.3125, 20.0078, 0.25);
	RemoveBuildingForPlayer(playerid, 1440, 1207.8594, 177.5234, 19.9453, 0.25);
	RemoveBuildingForPlayer(playerid, 1440, 1201.8438, 179.5703, 19.9453, 0.25);
	RemoveBuildingForPlayer(playerid, 3594, 1271.3125, 163.3906, 19.4375, 0.25);
	RemoveBuildingForPlayer(playerid, 1351, 1248.7969, 184.3203, 18.4766, 0.25);
	RemoveBuildingForPlayer(playerid, 1438, 1276.1172, 190.2266, 18.6094, 0.25);
	RemoveBuildingForPlayer(playerid, 1440, 1369.2500, 200.9141, 19.0469, 0.25);
	RemoveBuildingForPlayer(playerid, 1351, 1244.6875, 257.5156, 18.4766, 0.25);
	RemoveBuildingForPlayer(playerid, 1351, 1277.5000, 248.2031, 18.4766, 0.25);
	RemoveBuildingForPlayer(playerid, 1351, 1288.2500, 261.0078, 18.4766, 0.25);
	RemoveBuildingForPlayer(playerid, 1351, 1290.3125, 237.1953, 18.4766, 0.25);
	RemoveBuildingForPlayer(playerid, 1351, 1301.3516, 250.4688, 18.4766, 0.25);
	RemoveBuildingForPlayer(playerid, 13562, 1308.4609, 255.0234, 27.8047, 0.25);
	RemoveBuildingForPlayer(playerid, 1351, 1318.7344, 301.2656, 18.4766, 0.25);
	RemoveBuildingForPlayer(playerid, 1351, 1305.9297, 312.2656, 18.4766, 0.25);
	RemoveBuildingForPlayer(playerid, 1351, 1316.6719, 325.0703, 18.4766, 0.25);
	RemoveBuildingForPlayer(playerid, 1351, 1334.1484, 240.6797, 18.4766, 0.25);
	RemoveBuildingForPlayer(playerid, 1351, 1329.7734, 314.5391, 18.4766, 0.25);
	RemoveBuildingForPlayer(playerid, 1351, 1380.2266, 220.3125, 18.4766, 0.25);
	RemoveBuildingForPlayer(playerid, 1351, 1364.4609, 281.1328, 18.4766, 0.25);
	RemoveBuildingForPlayer(playerid, 1351, 1227.1719, 341.6094, 18.4766, 0.25);
	RemoveBuildingForPlayer(playerid, 1351, 1270.9063, 345.2344, 18.4766, 0.25);
	RemoveBuildingForPlayer(playerid, 1440, 1294.8828, 346.4453, 19.0547, 0.25);
	RemoveBuildingForPlayer(playerid, 955, 1277.8359, 372.5156, 18.9531, 0.25);
	RemoveBuildingForPlayer(playerid, 769, 1288.9063, 392.2969, 18.2422, 0.25);
	RemoveBuildingForPlayer(playerid, 1440, 1289.5938, 389.1328, 19.0469, 0.25);
	RemoveBuildingForPlayer(playerid, 1440, 1314.1719, 357.4766, 19.0156, 0.25);
	RemoveBuildingForPlayer(playerid, 1351, 1325.9297, 358.0781, 18.4766, 0.25);
	RemoveBuildingForPlayer(playerid, 1438, 1303.8125, 400.1953, 18.5313, 0.25);
	RemoveBuildingForPlayer(playerid, 1438, 1314.8359, 395.1563, 18.5313, 0.25);
	RemoveBuildingForPlayer(playerid, 1438, 1343.1406, 399.0625, 18.5234, 0.25);
	RemoveBuildingForPlayer(playerid, 766, 1345.7109, 403.3359, 18.0547, 0.25);
	RemoveBuildingForPlayer(playerid, 1440, 1487.5859, 355.0078, 18.7109, 0.25);
	RemoveBuildingForPlayer(playerid, 766, 1351.4219, 421.4609, 18.0547, 0.25);
	RemoveBuildingForPlayer(playerid, 791, 1322.0078, 437.5938, 17.3984, 0.25);
	RemoveBuildingForPlayer(playerid, 766, 1359.9844, 437.2344, 18.0547, 0.25);
	RemoveBuildingForPlayer(playerid, 1351, 1376.7734, 432.8047, 18.4766, 0.25);
	RemoveBuildingForPlayer(playerid, 1410, 1380.0391, 453.6797, 19.6328, 0.25);
	RemoveBuildingForPlayer(playerid, 1407, 1384.3359, 451.7188, 19.6406, 0.25);
	RemoveBuildingForPlayer(playerid, 1410, 1388.6406, 449.7578, 19.6328, 0.25);
	RemoveBuildingForPlayer(playerid, 782, 1384.4297, 434.1797, 18.7969, 0.25);
	RemoveBuildingForPlayer(playerid, 1407, 1392.7969, 447.5234, 19.6406, 0.25);
	RemoveBuildingForPlayer(playerid, 1407, 1396.7734, 445.0156, 19.6406, 0.25);
	RemoveBuildingForPlayer(playerid, 782, 1404.4141, 424.7422, 18.7969, 0.25);
	RemoveBuildingForPlayer(playerid, 780, 1395.9297, 444.8438, 18.9297, 0.25);
	RemoveBuildingForPlayer(playerid, 1407, 1411.7578, 438.7578, 19.8594, 0.25);
	RemoveBuildingForPlayer(playerid, 1407, 1412.9844, 443.2813, 19.8594, 0.25);
	RemoveBuildingForPlayer(playerid, 1449, 1412.8047, 450.0000, 19.6641, 0.25);
	RemoveBuildingForPlayer(playerid, 1345, 1413.4141, 451.1172, 19.7344, 0.25);
	RemoveBuildingForPlayer(playerid, 1410, 1414.2109, 447.8359, 19.8516, 0.25);
	RemoveBuildingForPlayer(playerid, 1407, 1415.6094, 454.3594, 19.9609, 0.25);
	RemoveBuildingForPlayer(playerid, 782, 1414.2734, 437.9219, 19.0156, 0.25);
	RemoveBuildingForPlayer(playerid, 780, 1423.7188, 414.1797, 18.6719, 0.25);
	RemoveBuildingForPlayer(playerid, 791, 1460.7813, 444.3906, 18.0078, 0.25);
	RemoveBuildingForPlayer(playerid, 1410, 1346.1250, 471.2266, 19.8984, 0.25);
	RemoveBuildingForPlayer(playerid, 1410, 1369.9609, 458.2734, 19.6328, 0.25);
	RemoveBuildingForPlayer(playerid, 1410, 1361.3281, 462.1172, 19.6328, 0.25);
	RemoveBuildingForPlayer(playerid, 1407, 1365.6641, 460.2266, 19.6406, 0.25);
	RemoveBuildingForPlayer(playerid, 782, 1359.1250, 462.1875, 18.8906, 0.25);
	RemoveBuildingForPlayer(playerid, 1407, 1375.7422, 455.6328, 19.6406, 0.25);
	RemoveBuildingForPlayer(playerid, 1407, 1409.6250, 467.4844, 19.8750, 0.25);
	RemoveBuildingForPlayer(playerid, 1407, 1405.6172, 469.8984, 19.8750, 0.25);
	RemoveBuildingForPlayer(playerid, 1410, 1413.6719, 465.0469, 19.8750, 0.25);
	RemoveBuildingForPlayer(playerid, 1410, 1415.9766, 459.0703, 19.9531, 0.25);
	RemoveBuildingForPlayer(playerid, 1410, 1350.0469, 479.8359, 19.8984, 0.25);
	RemoveBuildingForPlayer(playerid, 1407, 1348.0781, 475.5391, 19.9063, 0.25);
	RemoveBuildingForPlayer(playerid, 1407, 1386.1328, 478.3438, 19.9219, 0.25);
	RemoveBuildingForPlayer(playerid, 1410, 1399.1484, 472.7188, 19.9141, 0.25);
	RemoveBuildingForPlayer(playerid, 1407, 1381.8359, 480.1953, 19.9219, 0.25);
	RemoveBuildingForPlayer(playerid, 1407, 1370.3750, 484.5078, 19.9219, 0.25);
	RemoveBuildingForPlayer(playerid, 1410, 1374.7656, 482.7500, 19.9141, 0.25);
	RemoveBuildingForPlayer(playerid, 1345, 1368.6250, 484.1406, 19.7344, 0.25);
	RemoveBuildingForPlayer(playerid, 1407, 1353.9375, 488.3984, 19.9063, 0.25);
	RemoveBuildingForPlayer(playerid, 1410, 1365.9844, 486.2656, 19.9141, 0.25);
	RemoveBuildingForPlayer(playerid, 1407, 1357.2500, 489.7500, 19.9219, 0.25);
	
	
	// Clear Area51
	RemoveBuildingForPlayer(playerid, 3337, -92.0469, 2072.0313, 16.6719, 0.25);
	RemoveBuildingForPlayer(playerid, 3279, 262.0938, 1807.6719, 16.8203, 0.25);
	RemoveBuildingForPlayer(playerid, 1411, 347.1953, 1799.2656, 18.7578, 0.25);
	RemoveBuildingForPlayer(playerid, 1411, 342.9375, 1796.2891, 18.7578, 0.25);
	RemoveBuildingForPlayer(playerid, 16670, 330.7891, 1813.2188, 17.8281, 0.25);
	RemoveBuildingForPlayer(playerid, 3279, 113.3828, 1814.4531, 16.8203, 0.25);
	RemoveBuildingForPlayer(playerid, 3279, 165.9531, 1849.9922, 16.8203, 0.25);
	RemoveBuildingForPlayer(playerid, 1697, 220.3828, 1835.3438, 23.2344, 0.25);
	RemoveBuildingForPlayer(playerid, 1697, 228.7969, 1835.3438, 23.2344, 0.25);
	RemoveBuildingForPlayer(playerid, 1697, 236.9922, 1835.3438, 23.2344, 0.25);
	RemoveBuildingForPlayer(playerid, 16095, 279.1328, 1829.7813, 16.6328, 0.25);
	RemoveBuildingForPlayer(playerid, 16094, 191.1406, 1870.0391, 21.4766, 0.25);
	RemoveBuildingForPlayer(playerid, 16660, 215.9219, 1865.1797, 13.0234, 0.25);
	RemoveBuildingForPlayer(playerid, 16096, 120.5078, 1934.0313, 19.8281, 0.25);
	RemoveBuildingForPlayer(playerid, 3279, 161.9063, 1933.0938, 16.8203, 0.25);
	RemoveBuildingForPlayer(playerid, 16671, 193.9531, 2051.7969, 20.1797, 0.25);
	RemoveBuildingForPlayer(playerid, 3279, 233.4297, 1934.8438, 16.8203, 0.25);
	RemoveBuildingForPlayer(playerid, 3279, 267.0625, 1895.2969, 16.8203, 0.25);
	RemoveBuildingForPlayer(playerid, 16668, 357.9375, 2049.4219, 16.8438, 0.25);
	RemoveBuildingForPlayer(playerid, 16669, 380.2578, 1914.9609, 17.4297, 0.25);
	
	
	// MG sprunk factory
	RemoveBuildingForPlayer(playerid, 13224, 1320.8438, 266.6875, 22.8516, 0.25);
	RemoveBuildingForPlayer(playerid, 764, 1329.0000, 246.4141, 18.9375, 0.25);
	RemoveBuildingForPlayer(playerid, 12847, 1320.8438, 266.6875, 22.8516, 0.25);
	RemoveBuildingForPlayer(playerid, 12848, 1333.3516, 271.0078, 19.5547, 0.25);
	RemoveBuildingForPlayer(playerid, 1687, 1326.6563, 264.0625, 24.8594, 0.25);
	RemoveBuildingForPlayer(playerid, 764, 1333.0625, 255.7891, 17.4922, 0.25);
	RemoveBuildingForPlayer(playerid, 764, 1337.1250, 265.1563, 18.9375, 0.25);
	RemoveBuildingForPlayer(playerid, 764, 1341.1797, 274.5313, 17.8438, 0.25);
	
	
	// MG tree
	RemoveBuildingForPlayer(playerid, 690, 1427.2344, 160.7344, 18.9609, 0.25);
	
	// MG burned building (texture)
	RemoveBuildingForPlayer(playerid, 13009, 1331.1797, 375.7109, 22.9766, 0.25);
	
	
	// MG CPn
	RemoveBuildingForPlayer(playerid, 11279, -2038.7500, 150.7109, 31.1953, 0.25);
	RemoveBuildingForPlayer(playerid, 11387, -2038.7500, 150.7109, 31.1953, 0.25);
	RemoveBuildingForPlayer(playerid, 13299, 1383.6328, 465.1875, 22.3672, 0.25);
	RemoveBuildingForPlayer(playerid, 13485, 1304.3047, 330.1563, 23.7031, 0.25);
	RemoveBuildingForPlayer(playerid, 13440, 1282.2422, 369.1406, 28.7578, 0.25);
	RemoveBuildingForPlayer(playerid, 1370, 1373.4531, 469.9688, 19.6953, 0.25);
	RemoveBuildingForPlayer(playerid, 13296, 1383.6328, 465.1875, 22.3672, 0.25);
	RemoveBuildingForPlayer(playerid, 1688, 1382.6406, 469.3281, 23.8672, 0.25);
	RemoveBuildingForPlayer(playerid, 1346, 1380.2500, 466.5156, 20.4844, 0.25);
	RemoveBuildingForPlayer(playerid, 1368, 1376.5078, 468.4844, 19.8594, 0.25);
	RemoveBuildingForPlayer(playerid, 1348, 1384.9453, 464.6797, 19.8359, 0.25);
	RemoveBuildingForPlayer(playerid, 1686, 1378.9609, 461.0391, 19.3281, 0.25);
	RemoveBuildingForPlayer(playerid, 1686, 1380.6328, 460.2734, 19.3281, 0.25);
	RemoveBuildingForPlayer(playerid, 1686, 1385.0781, 458.2969, 19.3281, 0.25);
	RemoveBuildingForPlayer(playerid, 1686, 1383.3984, 459.0703, 19.3281, 0.25);
	RemoveBuildingForPlayer(playerid, 1691, 1389.6172, 467.3750, 23.2344, 0.25);
	RemoveBuildingForPlayer(playerid, 1348, 1399.7344, 459.7422, 19.8359, 0.25);
	RemoveBuildingForPlayer(playerid, 1450, 1394.0391, 462.2266, 19.7578, 0.25);
	RemoveBuildingForPlayer(playerid, 1482, 1401.9063, 461.3594, 20.5781, 0.25);
	RemoveBuildingForPlayer(playerid, 1370, 1373.1719, 471.1016, 19.6953, 0.25);
	RemoveBuildingForPlayer(playerid, 1482, 1390.5078, 472.3984, 20.3516, 0.25);
	RemoveBuildingForPlayer(playerid, 1448, 1357.7188, 481.7031, 19.2734, 0.25);
	RemoveBuildingForPlayer(playerid, 1370, 1358.4844, 483.6563, 19.6953, 0.25);
	RemoveBuildingForPlayer(playerid, 1450, 1355.8516, 483.3906, 19.7734, 0.25);
	RemoveBuildingForPlayer(playerid, 1358, 1356.3750, 485.1875, 20.3750, 0.25);
	
	
	// MG telegraphs
	RemoveBuildingForPlayer(playerid, 1308, 1229.3750, 286.6094, 18.8203, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 1248.1875, 109.9531, 19.7266, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 1256.0781, 144.9531, 18.8203, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 1301.2578, 147.3828, 18.8203, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 1243.0938, 174.6328, 19.4531, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 1281.5156, 165.5313, 18.8203, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 1308.2656, 174.2891, 18.8203, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 1274.1875, 191.4609, 18.8203, 0.25);
	RemoveBuildingForPlayer(playerid, 13441, 1338.0625, 198.7344, 30.0234, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 1376.7188, 199.3203, 18.8203, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 1210.2500, 203.0547, 18.8203, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 1230.3125, 264.4922, 18.8203, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 1233.8281, 221.8281, 18.8203, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 1260.5391, 251.4922, 18.8203, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 1198.0938, 314.1172, 18.8203, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 1272.3359, 322.4297, 18.8203, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 1229.6797, 336.6328, 18.8203, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 1284.4844, 262.1172, 18.8203, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 1290.4922, 226.5703, 18.8203, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 1316.3906, 247.8672, 18.8203, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 1290.5547, 336.1406, 18.8203, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 1312.1797, 326.4766, 18.8203, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 1322.8672, 300.0313, 18.8203, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 1347.6875, 212.3984, 18.8203, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 1362.2188, 303.9531, 18.8203, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 1378.9766, 226.2891, 18.8203, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 1368.6641, 279.5703, 18.8203, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 1411.1797, 252.5859, 18.8203, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 1410.6484, 281.1172, 18.8203, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 1229.9688, 362.8281, 18.8203, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 1272.9141, 360.0781, 18.8203, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 1180.0547, 366.4219, 20.1484, 0.25);
	RemoveBuildingForPlayer(playerid, 13440, 1282.2422, 369.1406, 28.7578, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 1296.2656, 388.3750, 18.8203, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 1324.8594, 353.7422, 18.8203, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 1359.1016, 382.1172, 18.8203, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 1415.1328, 363.4141, 18.0156, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 1427.2578, 338.9609, 18.0156, 0.25);
	RemoveBuildingForPlayer(playerid, 617, 1450.8438, 344.3516, 17.5234, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 1443.0625, 385.1250, 18.0156, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 1447.4844, 403.2734, 19.1406, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 1460.1875, 354.8203, 18.0156, 0.25);
	RemoveBuildingForPlayer(playerid, 13442, 1478.2656, 380.7891, 25.3594, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 1496.8828, 364.2500, 18.0156, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 1376.2891, 420.4219, 18.8203, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 1414.6406, 434.4766, 19.1406, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 1334.4531, 474.0938, 19.2344, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 1280.1719, 485.9531, 19.2422, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 1370.5156, 457.4766, 19.1406, 0.25);

	
	// MG boxes
	RemoveBuildingForPlayer(playerid, 1438, 1274.8750, 307.0469, 18.5313, 0.25);
	RemoveBuildingForPlayer(playerid, 1438, 1276.4766, 285.8516, 18.5313, 0.25);
	RemoveBuildingForPlayer(playerid, 1440, 1297.0703, 179.2266, 19.9453, 0.25);
	RemoveBuildingForPlayer(playerid, 1440, 1293.5547, 163.8828, 19.9453, 0.25);
	RemoveBuildingForPlayer(playerid, 1440, 1313.3203, 167.0313, 19.9453, 0.25);
	RemoveBuildingForPlayer(playerid, 1440, 1318.3828, 196.0547, 19.6094, 0.25);
	RemoveBuildingForPlayer(playerid, 1410, 1345.1172, 201.3672, 19.2188, 0.25);
	RemoveBuildingForPlayer(playerid, 1345, 1353.1016, 201.7578, 19.2656, 0.25);
	RemoveBuildingForPlayer(playerid, 1345, 1353.5781, 204.2266, 19.2656, 0.25);
	RemoveBuildingForPlayer(playerid, 1438, 1184.9844, 230.6719, 18.5313, 0.25);
	RemoveBuildingForPlayer(playerid, 1438, 1205.1406, 256.0547, 18.5313, 0.25);
	RemoveBuildingForPlayer(playerid, 1440, 1245.2500, 245.2344, 19.0469, 0.25);
	RemoveBuildingForPlayer(playerid, 1440, 1247.0391, 245.0234, 19.0469, 0.25);
	RemoveBuildingForPlayer(playerid, 1440, 1259.5000, 250.2031, 19.0469, 0.25);
	RemoveBuildingForPlayer(playerid, 1440, 1203.5859, 275.5313, 19.0469, 0.25);
	RemoveBuildingForPlayer(playerid, 1345, 1300.4531, 221.5078, 19.2656, 0.25);
	RemoveBuildingForPlayer(playerid, 1440, 1300.8750, 215.1406, 19.0313, 0.25);
	RemoveBuildingForPlayer(playerid, 1438, 1339.8516, 315.9375, 19.5156, 0.25);
	RemoveBuildingForPlayer(playerid, 1410, 1360.6563, 228.7344, 19.2188, 0.25);
	RemoveBuildingForPlayer(playerid, 1345, 1362.0391, 232.6094, 19.2656, 0.25);
	RemoveBuildingForPlayer(playerid, 1410, 1365.0000, 226.7813, 19.2188, 0.25);
	RemoveBuildingForPlayer(playerid, 1345, 1364.2891, 231.4844, 19.2656, 0.25);
	RemoveBuildingForPlayer(playerid, 1410, 1373.6875, 222.8906, 19.2188, 0.25);
	RemoveBuildingForPlayer(playerid, 1410, 1369.3438, 224.8359, 19.2188, 0.25);
	RemoveBuildingForPlayer(playerid, 1357, 1373.0391, 228.0469, 18.8203, 0.25);
	RemoveBuildingForPlayer(playerid, 1357, 1374.1953, 227.3203, 18.8125, 0.25);
	RemoveBuildingForPlayer(playerid, 1410, 1391.1719, 256.9688, 19.1797, 0.25);
	RemoveBuildingForPlayer(playerid, 1410, 1393.0313, 261.2813, 19.1797, 0.25);
	RemoveBuildingForPlayer(playerid, 1410, 1394.9453, 265.5625, 19.1797, 0.25);
	RemoveBuildingForPlayer(playerid, 1438, 1390.2266, 301.5469, 18.5078, 0.25);
	RemoveBuildingForPlayer(playerid, 1440, 1418.4531, 270.6094, 19.0234, 0.25);
	RemoveBuildingForPlayer(playerid, 1438, 1429.6484, 277.3906, 18.5313, 0.25);
	RemoveBuildingForPlayer(playerid, 1438, 1412.8672, 297.0938, 18.5078, 0.25);
	RemoveBuildingForPlayer(playerid, 1440, 1271.9922, 359.8750, 19.0469, 0.25);
	RemoveBuildingForPlayer(playerid, 1438, 1253.4375, 365.0547, 18.5313, 0.25);
	RemoveBuildingForPlayer(playerid, 1438, 1262.4609, 365.8359, 18.5313, 0.25);
	RemoveBuildingForPlayer(playerid, 1440, 1361.9219, 365.8438, 20.0469, 0.25);
	RemoveBuildingForPlayer(playerid, 1438, 1373.8281, 365.7344, 19.5156, 0.25);
	
	
	// More clear MG buildings
	RemoveBuildingForPlayer(playerid, 3299, 1446.8906, 380.4922, 18.5391, 0.25);
	RemoveBuildingForPlayer(playerid, 3299, 1404.5313, 351.6172, 18.3906, 0.25);
	RemoveBuildingForPlayer(playerid, 3301, 1416.0313, 388.1016, 20.1094, 0.25);
	RemoveBuildingForPlayer(playerid, 3301, 1433.5781, 338.3594, 19.7266, 0.25);
	RemoveBuildingForPlayer(playerid, 3301, 1492.1719, 359.8281, 20.0625, 0.25);
	RemoveBuildingForPlayer(playerid, 3300, 1410.1484, 367.8359, 20.0625, 0.25);
	RemoveBuildingForPlayer(playerid, 3300, 1442.7109, 358.7578, 19.7031, 0.25);
	RemoveBuildingForPlayer(playerid, 3300, 1461.1016, 361.1172, 19.9688, 0.25);
	RemoveBuildingForPlayer(playerid, 3300, 1475.1875, 350.7500, 19.6484, 0.25);
	RemoveBuildingForPlayer(playerid, 3297, 1427.4609, 360.1094, 19.6641, 0.25);
	RemoveBuildingForPlayer(playerid, 3297, 1404.5938, 337.4141, 19.6953, 0.25);
	RemoveBuildingForPlayer(playerid, 3297, 1457.7891, 344.2891, 19.7422, 0.25);
	RemoveBuildingForPlayer(playerid, 3297, 1476.6641, 369.1875, 20.4453, 0.25);
	RemoveBuildingForPlayer(playerid, 3298, 1417.2188, 327.6484, 18.2969, 0.25);
	RemoveBuildingForPlayer(playerid, 785, 1490.0469, 312.3828, 18.2891, 0.25);
	RemoveBuildingForPlayer(playerid, 785, 1460.7813, 444.3906, 18.0078, 0.25);
	RemoveBuildingForPlayer(playerid, 785, 1322.0078, 437.5938, 17.3984, 0.25);
	RemoveBuildingForPlayer(playerid, 780, 1414.6484, 303.6875, 18.1953, 0.25);
	RemoveBuildingForPlayer(playerid, 791, 1490.0469, 312.3828, 18.2891, 0.25);
	RemoveBuildingForPlayer(playerid, 3241, 1417.2188, 327.6484, 18.2969, 0.25);
	RemoveBuildingForPlayer(playerid, 1410, 1436.3281, 329.1484, 18.5234, 0.25);
	RemoveBuildingForPlayer(playerid, 673, 1404.0000, 329.9922, 17.3672, 0.25);
	RemoveBuildingForPlayer(playerid, 1440, 1421.8359, 321.8594, 18.3203, 0.25);
	RemoveBuildingForPlayer(playerid, 3284, 1433.5781, 338.3594, 19.7266, 0.25);
	RemoveBuildingForPlayer(playerid, 3242, 1404.5938, 337.4141, 19.6953, 0.25);
	RemoveBuildingForPlayer(playerid, 1410, 1451.1563, 335.2656, 18.5234, 0.25);
	RemoveBuildingForPlayer(playerid, 1410, 1455.6484, 337.1016, 18.5234, 0.25);
	RemoveBuildingForPlayer(playerid, 1410, 1439.3047, 332.2969, 18.5469, 0.25);
	RemoveBuildingForPlayer(playerid, 769, 1288.9063, 392.2969, 18.2422, 0.25);
	RemoveBuildingForPlayer(playerid, 766, 1345.7109, 403.3359, 18.0547, 0.25);
	RemoveBuildingForPlayer(playerid, 1410, 1396.5703, 356.4531, 19.0781, 0.25);
	RemoveBuildingForPlayer(playerid, 1410, 1395.9688, 350.9766, 18.9922, 0.25);
	RemoveBuildingForPlayer(playerid, 673, 1398.3750, 357.0469, 17.9063, 0.25);
	RemoveBuildingForPlayer(playerid, 766, 1389.4688, 360.5078, 18.2578, 0.25);
	RemoveBuildingForPlayer(playerid, 3242, 1427.4609, 360.1094, 19.6641, 0.25);
	RemoveBuildingForPlayer(playerid, 3283, 1404.5313, 351.6172, 18.3906, 0.25);
	RemoveBuildingForPlayer(playerid, 617, 1409.6406, 341.8516, 17.5938, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 1415.1328, 363.4141, 18.0156, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 1427.2578, 338.9609, 18.0156, 0.25);
	RemoveBuildingForPlayer(playerid, 1370, 1399.9219, 341.4766, 18.4844, 0.25);
	RemoveBuildingForPlayer(playerid, 3242, 1457.7891, 344.2891, 19.7422, 0.25);
	RemoveBuildingForPlayer(playerid, 3285, 1442.7109, 358.7578, 19.7031, 0.25);
	RemoveBuildingForPlayer(playerid, 617, 1450.8438, 344.3516, 17.5234, 0.25);
	RemoveBuildingForPlayer(playerid, 766, 1440.0469, 349.3359, 17.6016, 0.25);
	RemoveBuildingForPlayer(playerid, 766, 1434.7734, 362.5781, 17.3359, 0.25);
	RemoveBuildingForPlayer(playerid, 3283, 1446.8906, 380.4922, 18.5391, 0.25);
	RemoveBuildingForPlayer(playerid, 3285, 1410.1484, 367.8359, 20.0625, 0.25);
	RemoveBuildingForPlayer(playerid, 1410, 1400.1484, 368.3125, 19.3516, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 1443.0625, 385.1250, 18.0156, 0.25);
	RemoveBuildingForPlayer(playerid, 1440, 1409.3906, 384.9453, 19.0391, 0.25);
	RemoveBuildingForPlayer(playerid, 3284, 1416.0313, 388.1016, 20.1094, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 1447.4844, 403.2734, 19.1406, 0.25);
	RemoveBuildingForPlayer(playerid, 780, 1418.3750, 403.8750, 18.3828, 0.25);
	RemoveBuildingForPlayer(playerid, 3242, 1476.6641, 369.1875, 20.4453, 0.25);
	RemoveBuildingForPlayer(playerid, 3285, 1461.1016, 361.1172, 19.9688, 0.25);
	RemoveBuildingForPlayer(playerid, 3285, 1475.1875, 350.7500, 19.6484, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 1460.1875, 354.8203, 18.0156, 0.25);
	RemoveBuildingForPlayer(playerid, 1370, 1472.0938, 345.3672, 18.3438, 0.25);
	RemoveBuildingForPlayer(playerid, 3276, 1479.2422, 390.3672, 20.0625, 0.25);
	RemoveBuildingForPlayer(playerid, 673, 1470.3672, 375.9453, 18.1563, 0.25);
	RemoveBuildingForPlayer(playerid, 3276, 1460.2578, 397.4766, 20.0625, 0.25);
	RemoveBuildingForPlayer(playerid, 782, 1466.0703, 387.6016, 18.4922, 0.25);
	RemoveBuildingForPlayer(playerid, 13442, 1478.2656, 380.7891, 25.3594, 0.25);
	RemoveBuildingForPlayer(playerid, 3284, 1492.1719, 359.8281, 20.0625, 0.25);
	RemoveBuildingForPlayer(playerid, 3276, 1490.5000, 387.0000, 20.0625, 0.25);
	RemoveBuildingForPlayer(playerid, 1407, 1495.4531, 368.5000, 19.2969, 0.25);
	RemoveBuildingForPlayer(playerid, 1410, 1491.1953, 352.5703, 18.8438, 0.25);
	RemoveBuildingForPlayer(playerid, 1410, 1495.5547, 354.7109, 18.8438, 0.25);
	RemoveBuildingForPlayer(playerid, 673, 1493.8438, 368.2344, 18.1563, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 1489.1172, 387.6875, 19.1406, 0.25);
	RemoveBuildingForPlayer(playerid, 782, 1488.0000, 351.6719, 17.9219, 0.25);
	RemoveBuildingForPlayer(playerid, 1440, 1487.5859, 355.0078, 18.7109, 0.25);
	RemoveBuildingForPlayer(playerid, 3276, 1502.1797, 384.2422, 20.0625, 0.25);
	RemoveBuildingForPlayer(playerid, 1407, 1502.7422, 366.6641, 19.0547, 0.25);
	RemoveBuildingForPlayer(playerid, 1410, 1503.0547, 358.3203, 18.8438, 0.25);
	RemoveBuildingForPlayer(playerid, 673, 1502.5938, 364.5391, 18.1563, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 1496.8828, 364.2500, 18.0156, 0.25);
	RemoveBuildingForPlayer(playerid, 1410, 1511.9219, 364.2500, 18.8359, 0.25);
	RemoveBuildingForPlayer(playerid, 1410, 1507.3672, 365.5156, 18.9297, 0.25);
	RemoveBuildingForPlayer(playerid, 1410, 1507.4844, 360.4922, 18.7891, 0.25);
	RemoveBuildingForPlayer(playerid, 1407, 1511.6641, 362.5000, 18.7891, 0.25);
	RemoveBuildingForPlayer(playerid, 3276, 1570.2891, 375.3125, 20.0625, 0.25);
	RemoveBuildingForPlayer(playerid, 3276, 1594.8281, 374.3438, 20.0625, 0.25);
	RemoveBuildingForPlayer(playerid, 3276, 1558.2969, 376.2656, 20.0625, 0.25);
	RemoveBuildingForPlayer(playerid, 3276, 1540.1094, 378.2031, 20.0625, 0.25);
	RemoveBuildingForPlayer(playerid, 3276, 1528.2500, 379.7266, 20.0625, 0.25);
	RemoveBuildingForPlayer(playerid, 1308, 1552.9063, 377.1875, 19.1406, 0.25);
	RemoveBuildingForPlayer(playerid, 780, 1509.2500, 376.3203, 18.5469, 0.25);
	RemoveBuildingForPlayer(playerid, 3276, 1606.8594, 374.0156, 20.0625, 0.25);
	RemoveBuildingForPlayer(playerid, 766, 1351.4219, 421.4609, 18.0547, 0.25);
	RemoveBuildingForPlayer(playerid, 791, 1322.0078, 437.5938, 17.3984, 0.25);
	RemoveBuildingForPlayer(playerid, 766, 1359.9844, 437.2344, 18.0547, 0.25);
	RemoveBuildingForPlayer(playerid, 1440, 1413.2109, 413.6250, 19.2500, 0.25);
	RemoveBuildingForPlayer(playerid, 1440, 1412.1875, 411.6641, 19.2500, 0.25);
	RemoveBuildingForPlayer(playerid, 3276, 1427.2500, 411.7656, 19.8359, 0.25);
	RemoveBuildingForPlayer(playerid, 780, 1423.7188, 414.1797, 18.6719, 0.25);
	RemoveBuildingForPlayer(playerid, 3276, 1438.2422, 406.7188, 20.0625, 0.25);
	RemoveBuildingForPlayer(playerid, 690, 1512.9609, 408.7813, 16.6172, 0.25);
	RemoveBuildingForPlayer(playerid, 791, 1460.7813, 444.3906, 18.0078, 0.25);
	RemoveBuildingForPlayer(playerid, 690, 1285.0313, 459.9844, 16.6172, 0.25);
	RemoveBuildingForPlayer(playerid, 766, 1343.4219, 471.8203, 18.9453, 0.25);
	RemoveBuildingForPlayer(playerid, 690, 1330.8672, 493.7656, 16.9297, 0.25);

	// MG Lamp posts
	RemoveBuildingForPlayer(playerid, 1294, 1244.1953, 84.0078, 25.2422, 0.25);
	RemoveBuildingForPlayer(playerid, 1294, 1232.3828, 125.7109, 23.7188, 0.25);
	RemoveBuildingForPlayer(playerid, 1294, 1264.5469, 172.2188, 23.0078, 0.25);
	RemoveBuildingForPlayer(playerid, 1294, 1256.5078, 197.1172, 23.0078, 0.25);
	RemoveBuildingForPlayer(playerid, 1294, 1426.9219, 194.4063, 24.4453, 0.25);
	RemoveBuildingForPlayer(playerid, 1294, 1386.7031, 197.6641, 23.0078, 0.25);
	RemoveBuildingForPlayer(playerid, 1294, 1225.7188, 238.8594, 23.2344, 0.25);
	RemoveBuildingForPlayer(playerid, 1294, 1221.7109, 270.0391, 23.0078, 0.25);
	RemoveBuildingForPlayer(playerid, 1294, 1227.2344, 209.8047, 23.0078, 0.25);
	RemoveBuildingForPlayer(playerid, 1294, 1248.1484, 257.5000, 23.0078, 0.25);
	RemoveBuildingForPlayer(playerid, 1294, 1278.2031, 244.4766, 23.0078, 0.25);
	RemoveBuildingForPlayer(playerid, 1294, 1209.9766, 294.0547, 23.0078, 0.25);
	RemoveBuildingForPlayer(playerid, 1294, 1274.6094, 323.1875, 23.0078, 0.25);
	RemoveBuildingForPlayer(playerid, 1294, 1204.4297, 325.0000, 23.0078, 0.25);
	RemoveBuildingForPlayer(playerid, 1294, 1282.8906, 213.5156, 23.0078, 0.25);
	RemoveBuildingForPlayer(playerid, 1294, 1301.0781, 253.9297, 23.0078, 0.25);
	RemoveBuildingForPlayer(playerid, 1294, 1311.3359, 277.7734, 23.0234, 0.25);
	RemoveBuildingForPlayer(playerid, 1294, 1306.1641, 308.9063, 23.0078, 0.25);
	RemoveBuildingForPlayer(playerid, 1294, 1330.6328, 240.5781, 23.0078, 0.25);
	RemoveBuildingForPlayer(playerid, 1294, 1329.4297, 317.6094, 23.0078, 0.25);
	RemoveBuildingForPlayer(playerid, 1294, 1354.6563, 211.0859, 23.0078, 0.25);
	RemoveBuildingForPlayer(playerid, 1294, 1351.8281, 288.3828, 23.0078, 0.25);
	RemoveBuildingForPlayer(playerid, 1294, 1386.4063, 238.8984, 23.0078, 0.25);
	RemoveBuildingForPlayer(playerid, 1294, 1387.5156, 291.5156, 23.0078, 0.25);
	RemoveBuildingForPlayer(playerid, 1294, 1397.4375, 268.0625, 23.0078, 0.25);
	RemoveBuildingForPlayer(playerid, 1294, 1219.0078, 362.5938, 23.0078, 0.25);
	RemoveBuildingForPlayer(playerid, 1294, 1230.8516, 341.9219, 23.0078, 0.25);
	RemoveBuildingForPlayer(playerid, 1294, 1267.7891, 344.8438, 23.0078, 0.25);
	RemoveBuildingForPlayer(playerid, 1294, 1296.8047, 367.4063, 23.0234, 0.25);
	RemoveBuildingForPlayer(playerid, 1294, 1333.5625, 370.5234, 23.0234, 0.25);
	RemoveBuildingForPlayer(playerid, 1294, 1354.7422, 375.8984, 23.0234, 0.25);
	RemoveBuildingForPlayer(playerid, 1294, 1504.5000, 385.6328, 23.4922, 0.25);
	RemoveBuildingForPlayer(playerid, 1294, 1582.3125, 389.9219, 23.5469, 0.25);
	RemoveBuildingForPlayer(playerid, 1294, 1128.5781, 424.0313, 30.7031, 0.25);
	RemoveBuildingForPlayer(playerid, 1294, 1351.5859, 410.1172, 23.0234, 0.25);
	RemoveBuildingForPlayer(playerid, 1294, 1379.5859, 432.0469, 23.0234, 0.25);
	RemoveBuildingForPlayer(playerid, 1294, 1378.8047, 452.4141, 23.2813, 0.25);
	RemoveBuildingForPlayer(playerid, 1294, 1417.0547, 421.0703, 23.3047, 0.25);
	RemoveBuildingForPlayer(playerid, 1294, 1462.8359, 410.5313, 23.5469, 0.25);
	RemoveBuildingForPlayer(playerid, 1294, 1316.6250, 481.9453, 23.6641, 0.25);
	RemoveBuildingForPlayer(playerid, 1294, 1339.1094, 457.8594, 23.6641, 0.25);
	
	// LS - kontenery pod MZGK
	RemoveBuildingForPlayer(playerid, 3744, 2241.2969, -2183.9766, 15.1016, 0.25);
	RemoveBuildingForPlayer(playerid, 3744, 2226.3203, -2168.9922, 15.1016, 0.25);
	RemoveBuildingForPlayer(playerid, 3574, 2226.3203, -2168.9922, 15.1016, 0.25);
	RemoveBuildingForPlayer(playerid, 3574, 2241.2969, -2183.9766, 15.1016, 0.25);
	
	// LS - center, removed big trees
	RemoveBuildingForPlayer(playerid, 713, 1304.7734, -1753.5859, 12.4375, 0.25);
	RemoveBuildingForPlayer(playerid, 713, 1304.7734, -1729.9375, 12.4375, 0.25);
	RemoveBuildingForPlayer(playerid, 713, 1304.7734, -1780.1094, 12.4375, 0.25);
	RemoveBuildingForPlayer(playerid, 713, 1304.7734, -1808.4922, 12.4375, 0.25);
	RemoveBuildingForPlayer(playerid, 713, 1304.7734, -1839.8672, 12.4375, 0.25);
	RemoveBuildingForPlayer(playerid, 713, 1407.1953, -1749.3125, 13.0938, 0.25);
	RemoveBuildingForPlayer(playerid, 713, 1457.9375, -1620.6953, 13.4531, 0.25);
	RemoveBuildingForPlayer(playerid, 713, 1496.8672, -1707.8203, 13.4063, 0.25);
	
	// From Matril objects Los Santos LS
	RemoveBuildingForPlayer(playerid, 4024, 1479.8672, -1790.3984, 56.0234, 0.25);
	RemoveBuildingForPlayer(playerid, 4044, 1481.1875, -1785.0703, 22.3828, 0.25);
	RemoveBuildingForPlayer(playerid, 1527, 1448.2344, -1755.8984, 14.5234, 0.25);
	RemoveBuildingForPlayer(playerid, 700, 1447.1016, -1832.5000, 12.9141, 0.25);
	RemoveBuildingForPlayer(playerid, 4174, 1435.7656, -1823.6641, 15.1797, 0.25);
	RemoveBuildingForPlayer(playerid, 620, 1456.3984, -1832.5313, 11.9844, 0.25);
	RemoveBuildingForPlayer(playerid, 673, 1464.0938, -1831.8828, 12.3984, 0.25);
	RemoveBuildingForPlayer(playerid, 620, 1504.8438, -1832.5313, 11.9844, 0.25);
	RemoveBuildingForPlayer(playerid, 673, 1499.0469, -1832.2734, 12.8828, 0.25);
	RemoveBuildingForPlayer(playerid, 700, 1512.9453, -1832.3516, 13.4688, 0.25);
	RemoveBuildingForPlayer(playerid, 4002, 1479.8672, -1790.3984, 56.0234, 0.25);
	RemoveBuildingForPlayer(playerid, 3980, 1481.1875, -1785.0703, 22.3828, 0.25);
	RemoveBuildingForPlayer(playerid, 4003, 1481.0781, -1747.0313, 33.5234, 0.25);
	RemoveBuildingForPlayer(playerid, 4175, 1524.4141, -1823.8516, 15.1797, 0.25);
	RemoveBuildingForPlayer(playerid, 700, 1554.8203, -1816.1563, 13.4766, 0.25);
	
	// BIBIOLOTEKA
	RemoveBuildingForPlayer(playerid, 673, 1307.0781, -904.7266, 37.8438, 0.25);
	RemoveBuildingForPlayer(playerid, 673, 1324.1563, -904.7266, 37.8438, 0.25);
	RemoveBuildingForPlayer(playerid, 673, 1329.5781, -904.7266, 37.8438, 0.25);
	RemoveBuildingForPlayer(playerid, 673, 1329.5781, -904.7266, 37.8438, 0.25);
	RemoveBuildingForPlayer(playerid, 5762, 1315.3672, -887.4688, 41.7031, 0.25);
	RemoveBuildingForPlayer(playerid, 5852, 1315.3672, -887.4688, 41.7031, 0.25);
	RemoveBuildingForPlayer(playerid, 1522, 1314.7266, -897.2656, 38.4688, 0.25);

	// PARK
	RemoveBuildingForPlayer(playerid, 4025, 1777.8359, -1773.9063, 12.5234, 0.25);
	RemoveBuildingForPlayer(playerid, 4070, 1719.7422, -1770.7813, 23.4297, 0.25);
	RemoveBuildingForPlayer(playerid, 1531, 1724.7344, -1741.5000, 14.1016, 0.25);
	RemoveBuildingForPlayer(playerid, 4215, 1777.5547, -1775.0391, 36.7500, 0.25);
	RemoveBuildingForPlayer(playerid, 620, 1700.8516, -1778.3984, 12.4922, 0.25);
	RemoveBuildingForPlayer(playerid, 620, 1701.3047, -1794.4297, 12.5469, 0.25);
	RemoveBuildingForPlayer(playerid, 620, 1701.1484, -1753.2266, 12.3516, 0.25);
	RemoveBuildingForPlayer(playerid, 620, 1701.2578, -1764.4844, 12.4375, 0.25);
	RemoveBuildingForPlayer(playerid, 620, 1700.8984, -1743.9844, 12.4531, 0.25);
	RemoveBuildingForPlayer(playerid, 3986, 1719.7422, -1770.7813, 23.4297, 0.25);
	RemoveBuildingForPlayer(playerid, 1294, 1738.8594, -1813.2500, 16.9063, 0.25);
	RemoveBuildingForPlayer(playerid, 647, 1791.1797, -1816.6328, 14.6250, 0.25);
	RemoveBuildingForPlayer(playerid, 647, 1796.9609, -1817.3906, 14.6250, 0.25);
	RemoveBuildingForPlayer(playerid, 4019, 1777.8359, -1773.9063, 12.5234, 0.25);

	//bar
	RemoveBuildingForPlayer(playerid, 5231, 2085.2813, -1909.7109, 23.0000, 0.25);
	RemoveBuildingForPlayer(playerid, 1307, 2071.8828, -1879.5625, 12.6875, 0.25);
	
	RemoveBuildingForPlayer(playerid, 3374, -50.0156, 3.1797, 3.4766, 0.25);
	RemoveBuildingForPlayer(playerid, 3276, -94.5234, 31.6172, 2.8828, 0.25);
	RemoveBuildingForPlayer(playerid, 3276, -90.5313, 42.1484, 2.8828, 0.25);
	RemoveBuildingForPlayer(playerid, 3276, -81.8984, 56.8516, 2.8828, 0.25);
	RemoveBuildingForPlayer(playerid, 3374, -92.8672, 58.3438, 3.5703, 0.25);
	RemoveBuildingForPlayer(playerid, 3374, -91.9453, 47.8125, 3.5703, 0.25);
	
	return 1;
}

public OnFilterScriptInit()
{
	new a[][] =
	{
		"Unarmed (Fist)",
		"Brass K"
	};
	#pragma unused a
	
	return 1;
}

public OnFilterScriptExit()
{
	return 1;
}
