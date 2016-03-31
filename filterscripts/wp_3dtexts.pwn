#include <a_samp>
#include <streamer>

#define FILTERSCRIPT

public OnFilterScriptInit()
{
	new a[][] =
	{
		"Unarmed (Fist)",
		"Brass K"
	};
	#pragma unused a	
	
	CreateDynamic3DTextLabel("Urz¹d pracuje czynnie w godzinach 11:00-12:00", 0x0066FFFF, 1530.29, -1765.18, 38.0, 34.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 1);
	CreateDynamic3DTextLabel("Od godziny 8:00 do 19:00 mo¿liwe jest za³atwianie spraw telefonicznie", 0x0066FFFF, 1530.29, -1765.18, 37.5, 33.5, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 1);
	CreateDynamic3DTextLabel("Lista pracowników znajduje siê na naszej stronie internetowej", 0x0066FFFF, 1530.29, -1765.18, 37.0, 37.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 1);
	
	CreateDynamic3DTextLabel("Tablica Og³oszeniowa", 0x0066FFFF, 1465.71, -1749.90, 19.0, 34.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0);
	CreateDynamic3DTextLabel("Prace Dorywcze", 0x0066FFFF, 1465.71, -1749.90, 18.5, 33.5, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0);
	
	CreateDynamic3DTextLabel("Punkt poboru gazet", 0x0066FFFF, 1507.23, -1750.05, 19.0, 34.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0);
	
	return 1;
}

public OnFilterScriptExit()
{
	return 1;
}