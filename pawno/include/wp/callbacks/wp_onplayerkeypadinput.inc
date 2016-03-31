public OnPlayerKeypadInput(playerid, keypadID, type, key)
{
    for(new i=0; i < CUSTOM_MAX_PLAYERS; i++)
	{
		if(gEvent1players[i] == -1)
		{
			continue;
		}
		
		if(GetPlayerKeypad(i) == GetPlayerKeypad(playerid))
		{
			HideKeypad(i);
		}
	}
	
	if(type == KEYPAD_INPUT_BAD)
	{
		GameTextForPlayer(playerid, "~R~access denied", 3000, 3);
	}
	
	if(type == KEYPAD_INPUT_GOOD)
	{
		GameTextForPlayer(playerid, "~G~access granted", 3000, 3);
		
		if(keypadID == KEYPAD_DOOR_1)
		{
			MoveDynamicObject(gEvent1objects[4], 226.40,1873.50,14.50, 3.0);
		}
		
		if(keypadID == KEYPAD_DOOR_2)
		{
			MoveDynamicObject(gEvent1objects[5], 238.06, 1795.42, 18.78, 3.0);
		}
		
		if(keypadID == KEYPAD_DOOR_3)
		{
			MoveDynamicObject(gEvent1objects[6], 233.74, 1825.54, 6.41, 1.0);
		}
	}
	
	return 1;
}

//