#include <a_npc>

main() {}

public OnRecordingPlaybackEnd()
{
	StartPlayback();
}

public OnNPCEnterVehicle(vehicleid, seatid)
{
	StartPlayback();
}

public OnNPCExitVehicle()
{
	StopRecordingPlayback();
}

StartPlayback()
{
	StartRecordingPlayback(1, "dir_rec\\NPC422300");
}