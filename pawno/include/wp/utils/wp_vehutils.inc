stock CarSerialToID(serial)
{
	for(new i = 0; i < sizeof(gVehData); i++)
	{
		if(gVehData[i][CarSerial] == serial) { return i; }
	}
	return -1;
}

stock GetClosestVehicle(playerid, &Float:dis = (Float:0x7F800000))
{
  dis = (Float:0x7F800000);
  new Float:ClX, Float:ClY, Float:ClZ;
  if(GetPlayerPos(playerid, ClX, ClY, ClZ)) {
    new vehicleid = INVALID_VEHICLE_ID;
    for(new v, Float:temp, Float:VClX, Float:VClY, Float:VClZ; v != MAX_VEHICLES; v++) {
      if(GetVehiclePos(v, VClX, VClY, VClZ)) {
        VClX -= ClX, VClY -= ClY, VClZ -= ClZ;
        temp = VClX * VClX + VClY * VClY + VClZ * VClZ;
        if(temp < dis) dis = temp, vehicleid = v;
      }
    }
    dis = floatpower(dis, 0.5);
    return vehicleid;
  }
  return INVALID_VEHICLE_ID;
}

stock newVehSerial(tmpcar)
{
	gVehData[tmpcar][CarSerial] = random(2000);
	for(new i = 0; i < sizeof(gVehData); i++)
	{
		if(i != tmpcar)
		{
			if(gVehData[tmpcar][CarSerial] == gVehData[i][CarSerial])
			{
				i = 0;
				gVehData[tmpcar][CarSerial] = random(2000);
			}
		}
	}
	
	GetVehiclePos(tmpcar+1,gVehData[tmpcar][CarX],gVehData[tmpcar][CarY],gVehData[tmpcar][CarZ]);
	GetVehicleZAngle(tmpcar+1,gVehData[tmpcar][CarAngle]);
	SaveVehData(tmpcar, "CarPos");	
	SaveVehData(tmpcar, "CarSerial");
	DestroyVehicle(tmpcar+1);
	CreateVehicle(gVehData[tmpcar][CarModel],gVehData[tmpcar][CarX],gVehData[tmpcar][CarY],gVehData[tmpcar][CarZ],gVehData[tmpcar][CarAngle],gVehData[tmpcar][CarColor1],gVehData[tmpcar][CarColor2], -1);
	
	DestroyDynamic3DTextLabel( gVehData[tmpcar][Veh3DSerial] );
	
	SetVehLicensePlate(tmpcar+1);
	SetVehicleToRespawn(tmpcar+1);
	return 1;
}

stock GetDistanceToCar(playerid,carid)
{
	new Float:x1,Float:y1,Float:z1,Float:x2,Float:y2,Float:z2,Float:dis;
	if (!IsPlayerConnected(playerid))return -1;
	GetPlayerPos(playerid,x1,y1,z1);GetVehiclePos(carid,x2,y2,z2);
	dis = floatsqroot(floatpower(floatabs(floatsub(x2,x1)),2)+floatpower(floatabs(floatsub(y2,y1)),2)+floatpower(floatabs(floatsub(z2,z1)),2));
	return floatround(dis);
}

ASpeed(vehicleID)
{
	new
		Float:dist,
		Float:posX,
		Float:posY,
		Float:posZ;

	GetVehicleVelocity(vehicleID, posX, posY, posZ);
	dist = floatsqroot(floatpower(posX, 2) + floatpower(posY, 2) + floatpower(posZ, 2)) * 175;

	return floatround(dist, floatround_round);
}

stock GetVehicleCount()
{
	new count;
	for(new v = 1; v < MAX_VEHICLES; v++)
	{
		if (IsVehicleSpawned(v)) count++;
	}
	return count;
}

stock IsVehicleSpawned(vehicleid)
{
	new Float:VX,Float:VY,Float:VZ;
	GetVehiclePos(vehicleid,VX,VY,VZ);
	if (VX == 0.0 && VY == 0.0 && VZ == 0.0) return 0;
	return 1;
}

stock IsVehicleOccupied(vehicleid)
{
	for(new i=0;i<CUSTOM_MAX_PLAYERS;i++)
	{
		if(IsPlayerInVehicle(i,vehicleid)) return 1;
	}
	return 0;
}

stock IsAPlane(vehicleid)
{   
	new model = GetVehicleModel(vehicleid);
	if(model == 592 || model == 577 || model == 511 || model == 512 || model == 593 || model == 520 || model == 553 || model == 476 || model == 519 || model == 460 || model == 513)
	{
		return 1;
	}
	return 0;
}

stock IsAPlaneModel(model)
{
	if(model == 592 || model == 577 || model == 511 || model == 512 || model == 593 || model == 520 || model == 553 || model == 476 || model == 519 || model == 460 || model == 513)
	{
		return 1;
	}
	return 0;
}

stock IsAHelicopter(vehicleid)
{   
	new model = GetVehicleModel(vehicleid);
	if(model == 548 || model == 417 || model == 487 || model == 488 || model == 497 || model == 563 || model == 447 || model == 469)
	{
		return 1;
	}
	return 0;
}

stock IsAHelicopterModel(model)
{
	if(model == 548 || model == 417 || model == 487 || model == 488 || model == 497 || model == 563 || model == 447 || model == 469)
	{
		return 1;
	}
	return 0;
}

stock IsABike(vehicleid)
{   
	new model = GetVehicleModel(vehicleid);
	if(model == 509 || model == 481 || model == 510)
	{
		return 1;
	}
	return 0;
}

stock IsAMotorBike(vehicleid)
{
	new model = GetVehicleModel(vehicleid);
	if(model == 581 || model == 462 ||  model == 521 || model == 463 || model == 522 || model == 461 || model == 448 || model == 471 || model == 468 || model == 586)
	{
		return 1;
	}
	return 0;
}

stock IsABoat(vehicleid)
{
	new model = GetVehicleModel(vehicleid);
	if(model == 472 || model == 473 || model == 493 || model == 595 || model == 484 || model == 430 || model == 453 || model == 452 || model == 446 || model == 454)
	{
		return 1;
	}
	return 0;
}

stock IsABoatModel(model)
{
	if(model == 472 || model == 473 || model == 493 || model == 595 || model == 484 || model == 430 || model == 453 || model == 452 || model == 446 || model == 454)
	{
		return 1;
	}
	return 0;
}

stock IsAOffroadCar(vehicleid)
{
	new model = GetVehicleModel(vehicleid);
	if(model == 579 || model == 400 || model == 500 || model == 444 || model == 556 || model == 470 || model == 489 || model == 505 || model == 495 || model == 599 || model == 490)
	{
		return 1;
	}
	return 0;
}

stock IsASportsCar(vehicleid)
{
	new model = GetVehicleModel(vehicleid);
	if(model == 480 || model == 555 || model == 562 || model == 560 || model == 602 || model == 429 || model == 402 || model == 541 || model == 415 || model == 587 ||
		model == 494 || model == 502 || model == 411 || model == 559 || model == 603 || model == 506 || model == 451 || model == 558 || model == 477 )
	{
		return 1;
	}
	return 0;
}

stock IsAHardTruck(vehicleid)
{
	new model = GetVehicleModel(vehicleid);
	if(model == 499 || model == 433 || model == 431 || model == 437 || model == 427 || model == 407 || model == 544 || model == 432 || model == 601 || model == 406 || model == 443 ||
		model == 443 || model == 514 || model == 515 || model == 440 || model == 543 || model == 605 || model == 459 || model == 408 || model == 552 || model == 478 || model == 456 || model == 554 ||
		model == 416 || model == 422 || model == 482 || model == 498 || model == 609 || model == 524 || model == 578 || model == 455 || model == 403 || model == 414 || model == 582 )
	{
		return 1;
	}
	return 0;
}

stock IsATruck(vehicleid)
{
	new model = GetVehicleModel(vehicleid);
	if(model == 403 || model == 514 || model == 515 )
	{
		return 1;
	}
	return 0;
}

stock IsASemiTrailer(vehicleid)
{
	new model = GetVehicleModel(vehicleid);
	if(model == 435 || model == 450 || model == 584 || model == 591 || model == 578)
	{
		return 1;
	}
	return 0;
}

stock IsALorry(vehicleid)
{
	new model = GetVehicleModel(vehicleid);
	if(model == 531 || model == 578 || model == 499 || model == 498 || model == 609 || model == 414 || model == 456)
	{
		return 1;
	}
	return 0;
}

stock IsATrailer(vehicleid)
{
	new model = GetVehicleModel(vehicleid);
	if( model == 435 || model == 450 || model == 584 || model == 591 || model == 606 || model == 607 || model == 608 || model == 611)
	{
		return 1;
	}
	return 0;
}

stock IsATankerTrailer(vehicleid)
{
	new model = GetVehicleModel(vehicleid);
	if( model == 584 )
	{
		return 1;
	}
	return 0;
}

stock HaveOpenableTrunk(vehicleid)
{
	new model = GetVehicleModel(vehicleid);
	if(model == 403 || model == 406 || model == 407 || model == 408 ||
		model == 423 || model == 424 || model == 427 || model == 431 ||
		model == 524 || model == 525 || model == 530 || model == 531 ||
		model == 532 || model == 535 || model == 536 || model == 537 ||
		model == 538 || model == 539 || model == 541 || model == 544 ||
		model == 552 || model == 556 || model == 564 || model == 568 ||
		model == 569 || model == 570 || model == 571 || model == 572 ||
		model == 573 || model == 574 || model == 578 || model == 582 ||
		model == 583 || model == 590 || model == 594 || model == 601 )
	{
			return 0;
	}
	return 1;
}

stock GetVehicleName(vehicleid)
{
	new rmp = GetVehicleModel(vehicleid) - 400;
	return nazwypojazdow[rmp];
}

stock SetVehicleToPos(vehicleid,Float:x,Float:y,Float:z)
{
	SetVehiclePos(vehicleid, x, y, z);
	for(new i=0;i<CUSTOM_MAX_PLAYERS;i++)
	{
		if(IsPlayerConnected(i) && GetPlayerVehicleID(i) == vehicleid)
		{
			NewPos[i][0] = x;
			NewPos[i][1] = y;
			NewPos[i][2] = z;
			PosHackCheckTime[i] = 5;
		}
		return 1;
	}
	return 0;
}

StartEngine( playerid )
{
	if( !IsPlayerInAnyVehicle( playerid ) )
		return 1;
	if( AdminDuty[playerid] )
	{
		EngineTurningOn[playerid] = 1;
		PlayerActionMessage(playerid, 15.0, "uruchamia silnik");
		SendClientMessage(playerid, COLOR_GREEN,"[STATUS:] Uruchamianie silnika...");
		delay:Engine[ENGINE_STARTUP_TIME_FAST](playerid);
		return 1;
	}
	else
	{
		EngineTurningOn[playerid] = 1;
		PlayerActionMessage(playerid, 15.0, "uruchamia silnik");
		SendClientMessage(playerid, COLOR_GREEN,"[STATUS:] Uruchamianie silnika...");
		delay:Engine[ENGINE_STARTUP_TIME](playerid);
		return 1;
	}
}

SetVehLicensePlate( vehID )
{
	new tmpcar = vehID-1;
	new string[128];
	if(gVehData[tmpcar][CarSerial] < 10)
		format(string, sizeof(string), "SF-000%d", gVehData[tmpcar][CarSerial]);
	if(gVehData[tmpcar][CarSerial] > 10 && gVehData[tmpcar][CarSerial] < 100)
		format(string, sizeof(string), "SF-00%d", gVehData[tmpcar][CarSerial]);
	if(gVehData[tmpcar][CarSerial] > 100 && gVehData[tmpcar][CarSerial] < 1000)
		format(string, sizeof(string), "SF-0%d", gVehData[tmpcar][CarSerial]);
	if(gVehData[tmpcar][CarSerial] > 1000)
		format(string, sizeof(string), "SF-%d", gVehData[tmpcar][CarSerial]);
	
	if(IsAMotorBike(tmpcar+1) && gVehData[tmpcar][CarModel] != 522 && gVehData[tmpcar][CarModel] != 471 && gVehData[tmpcar][CarModel] != 468)
	{
		SetVehicleNumberPlate(tmpcar+1, string);
		// veh3dserial[tmpcar] = CreateDynamic3DTextLabel(string, COLOR_WHITE, 0.0, -1.0, 0.3, 20.0, INVALID_PLAYER_ID, tmpcar+1, 0);
	}
	else if(gVehData[tmpcar][CarModel] == 522 || gVehData[tmpcar][CarModel] == 471 || gVehData[tmpcar][CarModel] == 468)
	{
		gVehData[tmpcar][Veh3DSerial] = CreateDynamic3DTextLabel(string, COLOR_WHITE, 0.0, -1.0, 0.3, 20.0, INVALID_PLAYER_ID, tmpcar+1, 0);
	}
	else if(IsABoat(tmpcar+1))
	{
		gVehData[tmpcar][Veh3DSerial] = CreateDynamic3DTextLabel(string, COLOR_WHITE, 0.0, 1.0, 0.2, 25.0, INVALID_PLAYER_ID, tmpcar+1, 0);
	}
	else if(IsAPlane(tmpcar+1))
	{
		gVehData[tmpcar][Veh3DSerial] = CreateDynamic3DTextLabel(string, COLOR_WHITE, 0.0, 1.0, 0.2, 25.0, INVALID_PLAYER_ID, tmpcar+1, 0);
	}
	else if(IsAHelicopter(tmpcar+1))
	{
		gVehData[tmpcar][Veh3DSerial] = CreateDynamic3DTextLabel(string, COLOR_WHITE, 0.0, -2.5, 0.9, 25.0, INVALID_PLAYER_ID, tmpcar+1, 0);
	}
	else if(IsABoat(tmpcar+1) == 0 && IsABike(tmpcar+1) == 0 && IsAPlane(tmpcar+1) == 0 && IsAHelicopter(tmpcar+1) == 0 && IsAMotorBike(tmpcar+1) == 0)
	{
		SetVehicleNumberPlate(tmpcar+1, string);
		// veh3dserial[tmpcar] = CreateDynamic3DTextLabel(string, COLOR_WHITE, 0.0, -2.5, -0.5, 20.0, INVALID_PLAYER_ID, tmpcar+1, 0);
	}
}
