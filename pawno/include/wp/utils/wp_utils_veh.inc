/***
*
* File: wp_utils_veh.inc
* Auth: Damian Wojdat
* Date: 19.11.2011
* Desc: Internal script function related to vehicles.
*
*************************************************************************************************************/

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
  new vehid = GetPlayerVehicleID(playerid);
  if(GetPlayerPos(playerid, ClX, ClY, ClZ)) {
    new vehicleid = INVALID_VEHICLE_ID;
    for(new v, Float:temp, Float:VClX, Float:VClY, Float:VClZ; v != MAX_VEHICLES; v++)
	{
		if(GetVehiclePos(v, VClX, VClY, VClZ) && vehid != v)
		{
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
	
	GetVehiclePos(tmpcar+1,gVehData[tmpcar][mVehX],gVehData[tmpcar][mVehY],gVehData[tmpcar][mVehZ]);
	GetVehicleZAngle(tmpcar+1,gVehData[tmpcar][mVehA]);
	SaveVehData(tmpcar, "VehPos");	
	SaveVehData(tmpcar, "CarSerial");
	DestroyVehicle(tmpcar+1);
	CreateVehicle(gVehData[tmpcar][mVehModel],gVehData[tmpcar][mVehX],gVehData[tmpcar][mVehY],gVehData[tmpcar][mVehZ],gVehData[tmpcar][mVehA],gVehData[tmpcar][mVehColor1],gVehData[tmpcar][mVehColor2], -1);
	
	DestroyDynamic3DTextLabel( gVehData[tmpcar][Veh3DSerial] );
	
	SetVehLicensePlate(tmpcar+1);
	SetVehicleToRespawnEx(tmpcar+1);
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
	// dist = floatsqroot(floatpower(posX, 2) + floatpower(posY, 2) + floatpower(posZ, 2)) * 175;
	dist = floatsqroot(floatpower(posX, 2) + floatpower(posY, 2) + floatpower(posZ, 2)) * 197.5;

	return floatround(dist, floatround_round);
}

stock GetVehicleCount()
{
	new count;
	for(new v = 0; v < MAX_VEHICLES; v++)
	{
		if(IsVehicleSpawned(v))
			count++;
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

stock IsABikeModel(model)
{
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

stock IsATransfender(vehicleid)
{
	new model = GetVehicleModel(vehicleid);
	if(model == 400 || model == 401 || model == 402 || model == 404 || model == 405 || model == 408 || model == 409 || model == 410 ||
		model == 411 || model == 415 || model == 418 || model == 419 || model == 420 || model == 421 || model == 422 || model == 424 ||
		model == 426 || model == 429 || model == 436 || model == 438 || model == 439 || model == 442 || model == 445 || model == 451 ||
		model == 458 || model == 466 || model == 467 || model == 474 || model == 475 || model == 477 || model == 478 || model == 479 ||
		model == 480 || model == 489 || model == 491 || model == 492 || model == 496 || model == 500 || model == 505 || model == 506 ||
		model == 507 || model == 516 || model == 517 || model == 518 || model == 526 || model == 527 || model == 529 || model == 533 ||
		model == 540 || model == 541 || model == 542 || model == 545 || model == 546 || model == 547 || model == 549 || model == 550 ||
		model == 551 || model == 555 || model == 575 || model == 579 || model == 580 || model == 585 || model == 587 || model == 589 ||
		model == 600 || model == 602 || model == 603)
	{
		return 1;
	}
	return 0;
}

stock IsAVehCatAModel(model)
{
	if(model == 463 || model == 468 || model == 471 || model == 461 ||
		model == 522 || model == 521 || model == 523 || model == 571 ||
		model == 581 || model == 587)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

stock IsAVehCatBModel(model)
{
	if(model == 400 || model == 401 || model == 402 || model == 404 ||
		model == 405 || model == 409 || model == 410 || model == 411 ||
		model == 412 || model == 413 || model == 414 || model == 415 ||
		model == 416 || model == 418 || model == 419 || model == 420 ||
		model == 420 || model == 421 || model == 422 || model == 423 ||
		model == 424 || model == 426 || model == 427 || model == 428 ||
		model == 429 || model == 434 || model == 436 || model == 438 ||
		model == 439 || model == 440 || model == 442 || model == 444 ||
		model == 445 || model == 451 || model == 458 || model == 459 ||
		model == 466 || model == 467 || model == 470 || model == 474 ||
		model == 475 || model == 477 || model == 478 || model == 479 ||
		model == 480 || model == 482 || model == 483 || model == 489 ||
		model == 490 || model == 491 || model == 492 || model == 494 ||
		model == 495 || model == 496 || model == 498 || model == 500 ||
		model == 502 || model == 503 || model == 504 || model == 505 ||
		model == 506 || model == 507 || model == 516 || model == 517 ||
		model == 518 || model == 525 || model == 526 || model == 527 ||
		model == 528 || model == 529 || model == 533 || model == 534 ||
		model == 535 || model == 536 || model == 540 || model == 541 ||
		model == 542 || model == 543 || model == 545 || model == 546 ||
		model == 547 || model == 549 || model == 550 || model == 551 ||
		model == 552 || model == 554 || model == 555 || model == 556 ||
		model == 557 || model == 558 || model == 559 || model == 560 ||
		model == 561 || model == 562 || model == 565 || model == 566 ||
		model == 576 || model == 579 || model == 580 || model == 582 ||
		model == 583 || model == 585 || model == 587 || model == 588 ||
		model == 589 || model == 596 || model == 597 || model == 598 ||
		model == 599 || model == 600 || model == 601 || model == 602 ||
		model == 603 || model == 604 || model == 605 || model == 609)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

stock IsAVehCatCEModel(model)
{
	if(model == 406 || model == 486 || model == 403 || model == 407 ||
		model == 433 || model == 443 || model == 455 || model == 456 ||
		model == 499 || model == 508 || model == 514 || model == 515 ||
		model == 524 || model == 544 || model == 573 || model == 578 ||
		model == 532 || model == 408 || model == 431 || model == 437)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

stock VehVentModel(vehid)
{
	new model = gVehData[vehid-1][mVehModel];
	if(model == 401 || model == 439 || model == 458 || model == 491 || model == 517 || model == 518 || model == 540 ||
		model == 542 || model == 546 || model == 547 || model == 549 || model == 550 || model == 585 || model == 589 ||
		model == 603)
		return 1;
	return 0;
}

stock VehLampModel(vehid)
{
	new model = gVehData[vehid-1][mVehModel];
	if(model == 400 || model == 401 || model == 404 || model == 410 || model == 422 || model == 436 || model == 439 || model == 458
		|| model == 489 || model == 496 || model == 500 || model == 505 || model == 518 || model == 540 || model == 546 || model == 549
		|| model == 550 || model == 585 || model == 589 || model == 600 || model == 603)
		return 1;
	return 0;
}

stock VehHoodModel(vehid)
{
	new model = gVehData[vehid-1][mVehModel];
	if(model == 401 || model == 410 || model == 436 || model == 489 || model == 496 || model == 505 || model == 518 || model == 540
		|| model == 550 || model == 585 || model == 589 || model == 600 || model == 603)
		return 1;
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
	VehNewPos[vehicleid-1][0] = x;
	VehNewPos[vehicleid-1][1] = y;
	VehNewPos[vehicleid-1][2] = z;
	gVehData[vehicleid-1][mVehX] = x;
	gVehData[vehicleid-1][mVehY] = y;
	gVehData[vehicleid-1][mVehZ] = z;
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

stock StartEngine(playerid, vehID = INVALID_VEHICLE_ID)
{
	if(AdminDuty[playerid])
	{
		EngineTurningOn[playerid] = 1;
		// PlayerActionMessage(playerid, 15.0, "uruchamia silnik");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Uruchamianie silnika...");
		defer Engine[ENGINE_STARTUP_TIME_FAST](playerid);
		return 1;
	}
	else
	{
		new Float:vehHp;
		GetVehicleHealth(vehID+1, vehHp);
		if(gVehData[vehID][EngineTemp] > 10 && vehHp < 700.0)
		{
			EngineTurningOn[playerid] = 1;
			// PlayerActionMessage(playerid, 15.0, "uruchamia silnik");
			SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] Silnik jest przegrzany, nie mo¿esz go uruchomiæ" );
			EngineInfo(playerid);
			return 1;
		}
		else if(gVehData[vehID][BatteryCapacity] < 2.0)
		{
			EngineTurningOn[playerid] = 1;
			// PlayerActionMessage(playerid, 15.0, "uruchamia silnik");
			SendClientMessage( playerid, COLOR_ORANGE, "[INFO:] S³aby akumulator, nie uda³o siê uruchomiæ silnika !" );
			EngineInfo(playerid);
			return 1;
		}
		EngineTurningOn[playerid] = 1;
		// PlayerActionMessage(playerid, 15.0, "uruchamia silnik");
		SendClientMessage(playerid, COLOR_LIGHTYELLOW2, "[INFO:] Uruchamianie silnika...");
		defer Engine[ENGINE_STARTUP_TIME](playerid);
		return 1;
	}
}

SetVehLicensePlate( vehID )
{
	new tmpcar = vehID-1;
	new string[128];
	if(gVehData[tmpcar][CarSerial] < 10)
		format(string, sizeof(string), "SA-000%d", gVehData[tmpcar][CarSerial]);
	if(gVehData[tmpcar][CarSerial] > 10 && gVehData[tmpcar][CarSerial] < 100)
		format(string, sizeof(string), "SA-00%d", gVehData[tmpcar][CarSerial]);
	if(gVehData[tmpcar][CarSerial] > 100 && gVehData[tmpcar][CarSerial] < 1000)
		format(string, sizeof(string), "SA-0%d", gVehData[tmpcar][CarSerial]);
	if(gVehData[tmpcar][CarSerial] > 1000)
		format(string, sizeof(string), "SA-%d", gVehData[tmpcar][CarSerial]);
	
	if(IsAMotorBike(tmpcar+1) && gVehData[tmpcar][mVehModel] != 522 && gVehData[tmpcar][mVehModel] != 471 && gVehData[tmpcar][mVehModel] != 468)
	{
		SetVehicleNumberPlate(tmpcar+1, string);
		// veh3dserial[tmpcar] = CreateDynamic3DTextLabel(string, COLOR_WHITE, 0.0, -1.0, 0.3, 20.0, INVALID_PLAYER_ID, tmpcar+1, 0);
	}
	else if(gVehData[tmpcar][mVehModel] == 522 || gVehData[tmpcar][mVehModel] == 471 || gVehData[tmpcar][mVehModel] == 468)
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

SetVehicleToRespawnEx(vehicleid)
{
	SetVehicleToRespawn(vehicleid);
	VehJustRespawned[vehicleid-1] = 5;
}

stock UnmodVehicle(vehicleId)
{
	gVehData[vehicleId-1][mVehSpoiler] = 0;
	gVehData[vehicleId-1][mVehHood] = 0;
	gVehData[vehicleId-1][mVehRoof] = 0;
	gVehData[vehicleId-1][mVehSideskirt] = 0;
	gVehData[vehicleId-1][mVehLamps] = 0;
	gVehData[vehicleId-1][mVehNitro] = 0;
	gVehData[vehicleId-1][mVehExhaust] = 0;
	gVehData[vehicleId-1][mVehWheels] = 0;
	gVehData[vehicleId-1][mVehStereo] = 0;
	gVehData[vehicleId-1][mVehHydraulics] = 0;
	gVehData[vehicleId-1][mVehFrontBumper] = 0;
	gVehData[vehicleId-1][mVehRearBumper] = 0;
	gVehData[vehicleId-1][mVehVentLeft] = 0;
	gVehData[vehicleId-1][mVehVentRight] = 0;
	SaveVehData(vehicleId-1, "VehSaveTune");
	GetVehiclePos(vehicleId, gVehData[vehicleId-1][mVehX], gVehData[vehicleId-1][mVehY], gVehData[vehicleId-1][mVehZ]);
	GetVehicleZAngle(vehicleId, gVehData[vehicleId-1][mVehA]);
	SetVehicleToRespawnEx(vehicleId);
	SetVehicleToPos(vehicleId, gVehData[vehicleId-1][mVehX], gVehData[vehicleId-1][mVehY], gVehData[vehicleId-1][mVehZ]);
}

stock SetVehicleOutOfTransport(vehicleid)
{
	new vehicleTransport = GetVehicleVirtualWorld(vehicleid);
	new Float:vehicleTransportAngle;
	GetVehiclePos(vehicleTransport, gVehData[vehicleTransport-1][mVehX], gVehData[vehicleTransport-1][mVehY], gVehData[vehicleTransport-1][mVehZ]);
	GetVehicleZAngle(vehicleTransport, gVehData[vehicleTransport-1][mVehA]);
	vehicleTransportAngle = gVehData[vehicleTransport-1][mVehA];	
	if(vehicleTransportAngle-180 < 0)
		vehicleTransportAngle += 180;
	else
		vehicleTransportAngle -= 180;
	LinkVehicleToInterior(vehicleid, 0);
	SetVehicleVirtualWorld(vehicleid, 0);
	
	printf("Outer pos: %f, %f, %f, %f", gVehData[vehicleTransport-1][mVehX]+floatsin(vehicleTransportAngle, degrees)*9.0, gVehData[vehicleTransport-1][mVehY]+ floatcos(vehicleTransportAngle, degrees)*9.0, gVehData[vehicleTransport-1][mVehZ], gVehData[vehicleTransport-1][mVehA]);
	
	SetVehicleToPos(vehicleid, gVehData[vehicleTransport-1][mVehX]+floatsin(vehicleTransportAngle, degrees)*9.0, gVehData[vehicleTransport-1][mVehY]+ floatcos(vehicleTransportAngle, degrees)*9.0, gVehData[vehicleTransport-1][mVehZ]);	
	SetVehicleZAngle(vehicleid, gVehData[vehicleTransport-1][mVehA]);
	
	if(gVehData[vehicleid-1][mVehTransportSlot1])
	{
		gVehData[vehicleid-1][mVehTransportSlot1] = 0;
		gVehData[vehicleTransport-1][mVehTransportSlot1] = 0;
		SaveVehData(vehicleTransport-1, "VehTransportSlot1");
		SaveVehData(vehicleid-1, "VehTransportSlot4");
	}
	else if(gVehData[vehicleid-1][mVehTransportSlot2])
	{
		gVehData[vehicleid-1][mVehTransportSlot2] = 0;
		gVehData[vehicleTransport-1][mVehTransportSlot2] = 0;
		SaveVehData(vehicleTransport-1, "VehTransportSlot2");
		SaveVehData(vehicleid-1, "VehTransportSlot2");
	}
	else if(gVehData[vehicleid-1][mVehTransportSlot3])
	{
		gVehData[vehicleid-1][mVehTransportSlot3] = 0;
		gVehData[vehicleTransport-1][mVehTransportSlot3] = 0;
		SaveVehData(vehicleTransport-1, "VehTransportSlot3");
		SaveVehData(vehicleid-1, "VehTransportSlot3");
	}
	else if(gVehData[vehicleid-1][mVehTransportSlot4])
	{
		gVehData[vehicleid-1][mVehTransportSlot4] = 0;
		gVehData[vehicleTransport-1][mVehTransportSlot4] = 0;
		SaveVehData(vehicleTransport-1, "VehTransportSlot4");
		SaveVehData(vehicleid-1, "VehTransportSlot4");
	}
	return 1;
}

stock SetVehicleIntoTransport(vehicleid, transportVeh)
{
	if(transportVeh == INVALID_VEHICLE_ID)
		return -1;
	if(gVehData[transportVeh-1][mVehModel] != 435)
		return -1;
	if(gVehData[transportVeh-1][mVehTransportSlot1] == 0)
	{
		gVehData[transportVeh-1][mVehTransportSlot1] = vehicleid;
		gVehData[vehicleid-1][mVehTransportSlot3] = 1;
		SaveVehData(transportVeh-1, "VehTransportSlot1");
		SaveVehData(vehicleid-1, "VehTransportSlot1");
		LinkVehicleToInterior(vehicleid, gVehTransport[mPosInterior]);
		SetVehicleVirtualWorld(vehicleid, transportVeh);
		GetVehicleZAngle(transportVeh, gVehData[transportVeh-1][mVehA]);
		SetVehicleToPos(vehicleid, gVehTransport[mPosX1], gVehTransport[mPosY1], gVehTransport[mPosZ1]);
		SetVehicleZAngle(vehicleid, gVehTransport[mPosAngle]);
		SetVehicleParamsEx(vehicleid, 0, gVehData[vehicleid-1][LightsOn], 0, gVehData[vehicleid-1][Closed], gVehData[vehicleid-1][BonnetUp], gVehData[vehicleid-1][BootUp], 0);
		gVehData[vehicleid-1][EngineOn] = 0;		
		return 1;
	}
	if(gVehData[transportVeh-1][mVehTransportSlot2] == 0)
	{
		gVehData[transportVeh-1][mVehTransportSlot2] = vehicleid;
		gVehData[vehicleid-1][mVehTransportSlot3] = 1;
		SaveVehData(transportVeh-1, "VehTransportSlot2");
		SaveVehData(vehicleid-1, "VehTransportSlot2");
		LinkVehicleToInterior(vehicleid, gVehTransport[mPosInterior]);
		SetVehicleVirtualWorld(vehicleid, transportVeh);
		SetVehicleToPos(vehicleid, gVehTransport[mPosX2], gVehTransport[mPosY2], gVehTransport[mPosZ2]);
		SetVehicleZAngle(vehicleid, gVehTransport[mPosAngle]);
		SetVehicleParamsEx(vehicleid, 0, gVehData[vehicleid-1][LightsOn], 0, gVehData[vehicleid-1][Closed], gVehData[vehicleid-1][BonnetUp], gVehData[vehicleid-1][BootUp], 0);
		gVehData[vehicleid-1][EngineOn] = 0;
		return 2;
	}
	if(gVehData[transportVeh-1][mVehTransportSlot3] == 0)
	{
		gVehData[transportVeh-1][mVehTransportSlot3] = vehicleid;
		gVehData[vehicleid-1][mVehTransportSlot3] = 1;
		SaveVehData(transportVeh-1, "VehTransportSlot3");
		SaveVehData(vehicleid-1, "VehTransportSlot3");
		LinkVehicleToInterior(vehicleid, gVehTransport[mPosInterior]);
		SetVehicleVirtualWorld(vehicleid, transportVeh);
		SetVehicleToPos(vehicleid, gVehTransport[mPosX3], gVehTransport[mPosY3], gVehTransport[mPosZ3]);
		SetVehicleZAngle(vehicleid, gVehTransport[mPosAngle]);
		SetVehicleParamsEx(vehicleid, 0, gVehData[vehicleid-1][LightsOn], 0, gVehData[vehicleid-1][Closed], gVehData[vehicleid-1][BonnetUp], gVehData[vehicleid-1][BootUp], 0);
		gVehData[vehicleid-1][EngineOn] = 0;
		return 3;
	}
	if(gVehData[transportVeh-1][mVehTransportSlot4] == 0)
	{
		gVehData[transportVeh-1][mVehTransportSlot4] = vehicleid;
		gVehData[vehicleid-1][mVehTransportSlot3] = 1;
		SaveVehData(transportVeh-1, "VehTransportSlot4");
		SaveVehData(vehicleid-1, "VehTransportSlot4");
		LinkVehicleToInterior(vehicleid, gVehTransport[mPosInterior]);
		SetVehicleVirtualWorld(vehicleid, transportVeh);
		SetVehicleToPos(vehicleid, gVehTransport[mPosX4], gVehTransport[mPosY4], gVehTransport[mPosZ4]);
		SetVehicleZAngle(vehicleid, gVehTransport[mPosAngle]);
		SetVehicleParamsEx(vehicleid, 0, gVehData[vehicleid-1][LightsOn], 0, gVehData[vehicleid-1][Closed], gVehData[vehicleid-1][BonnetUp], gVehData[vehicleid-1][BootUp], 0);
		gVehData[vehicleid-1][EngineOn] = 0;
		return 4;
	}
	return 0;
}

stock MountSirenToVehicle(vehid)
{
	if(gVehData[vehid][mVehSirenState])
		return 0;
	if(!gVehData[vehid][mVehSirenObjModel])
		return 1;
	switch(gVehData[vehid][mVehModel])
	{
		case 560:
		{
			DestroyDynamicObject(gVehData[vehid][mVehSirenObjId]);
			if(gVehData[vehid][mVehSirenObjModel] == 19420 || gVehData[vehid][mVehSirenObjModel] == 19419)
			{
				gVehData[vehid][mVehSirenObjId] = CreateDynamicObject(19419, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
				AttachDynamicObjectToVehicle(gVehData[vehid][mVehSirenObjId], vehid+1, 0.0, -0.25, 0.835, 0.0, 0.0, 0.0);
			}
			else if(gVehData[vehid][mVehSirenObjModel] == 18646)
			{
				gVehData[vehid][mVehSirenObjId] = CreateDynamicObject(18646, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
				AttachDynamicObjectToVehicle(gVehData[vehid][mVehSirenObjId], vehid+1, -0.54, 0.2, 0.875, 0.0, 0.0, 0.0);
			}
			gVehData[vehid][mVehSirenState] = 1;
			return 2;
		}
		case 602:
		{
			DestroyDynamicObject(gVehData[vehid][mVehSirenObjId]);
			if(gVehData[vehid][mVehSirenObjModel] == 19420 || gVehData[vehid][mVehSirenObjModel] == 19419)
			{
				gVehData[vehid][mVehSirenObjId] = CreateDynamicObject(19419, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
				AttachDynamicObjectToVehicle(gVehData[vehid][mVehSirenObjId], vehid+1, 0.0, -0.25, 0.68, 0.0, 0.0, 0.0);
			}
			else if(gVehData[vehid][mVehSirenObjModel] == 18646)
			{
				gVehData[vehid][mVehSirenObjId] = CreateDynamicObject(18646, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
				AttachDynamicObjectToVehicle(gVehData[vehid][mVehSirenObjId], vehid+1, -0.25, 0.0, 0.68, 0.0, 0.0, 0.0);
			}
			gVehData[vehid][mVehSirenState] = 1;
			return 2;
		}
		default:
			return 3;
	}
	return 3;
}

stock DismountSirenFromVehicle(vehid)
{
	if(gVehData[vehid][mVehSirenObjId] == -1)
		return 0;
	if(!gVehData[vehid][mVehSirenObjModel])
		return 1;
	switch(gVehData[vehid][mVehModel])
	{
		case 560:
		{
			DestroyDynamicObject(gVehData[vehid][mVehSirenObjId]);
			if(gVehData[vehid][mVehSirenObjModel] == 19420 || gVehData[vehid][mVehSirenObjModel] == 19419)
			{
				gVehData[vehid][mVehSirenObjId] = CreateDynamicObject(19420, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
				AttachDynamicObjectToVehicle(gVehData[vehid][mVehSirenObjId], vehid+1, 0.0, -0.25, 0.835, 0.0, 0.0, 0.0);
			}
			gVehData[vehid][mVehSirenState] = 0;
			return 2;
		}
		case 602:
		{
			DestroyDynamicObject(gVehData[vehid][mVehSirenObjId]);
			if(gVehData[vehid][mVehSirenObjModel] == 19420 || gVehData[vehid][mVehSirenObjModel] == 19419)
			{
				gVehData[vehid][mVehSirenObjId] = CreateDynamicObject(19420, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
				AttachDynamicObjectToVehicle(gVehData[vehid][mVehSirenObjId], vehid+1, 0.0, -0.25, 0.68, 0.0, 0.0, 0.0);
			}
			gVehData[vehid][mVehSirenState] = 0;
			return 2;
		}
		default:
			return 3;
	}
	return 3;
}

stock AttachObjectToVehicleSlot(vehid, model)
{
	if(gVehData[vehid-1][CustomObj1Model] == 0)
	{
		gVehData[vehid-1][CustomObj1Model] = model;
		gVehData[vehid-1][CustomObj1On] = 1;
		gVehData[vehid-1][CustomObj1][0] = 0.0;
		gVehData[vehid-1][CustomObj1][1] = 0.0;
		gVehData[vehid-1][CustomObj1][2] = 1.0;
		gVehData[vehid-1][CustomObj1][3] = 0.0;
		gVehData[vehid-1][CustomObj1][4] = 0.0;
		gVehData[vehid-1][CustomObj1][5] = 0.0;
		gVehData[vehid-1][CustomObj1ID] = CreateDynamicObject(
			gVehData[vehid-1][CustomObj1Model],
			gVehData[vehid-1][CustomObj1][0],
			gVehData[vehid-1][CustomObj1][1],
			gVehData[vehid-1][CustomObj1][2],
			gVehData[vehid-1][CustomObj1][3],
			gVehData[vehid-1][CustomObj1][4],
			gVehData[vehid-1][CustomObj1][5]);
		AttachDynamicObjectToVehicle(gVehData[vehid-1][CustomObj1ID], vehid, gVehData[vehid-1][CustomObj1][0], gVehData[vehid-1][CustomObj1][1], gVehData[vehid-1][CustomObj1][2], gVehData[vehid-1][CustomObj1][3], gVehData[vehid-1][CustomObj1][4], gVehData[vehid-1][CustomObj1][5]);
		SaveVehData(vehid-1, "CustomObj1Model" );
		SaveVehData(vehid-1, "CustomObj1", 0 );
		SaveVehData(vehid-1, "CustomObj1", 1 );
		SaveVehData(vehid-1, "CustomObj1", 2 );
		SaveVehData(vehid-1, "CustomObj1", 3 );
		SaveVehData(vehid-1, "CustomObj1", 4 );
		SaveVehData(vehid-1, "CustomObj1", 5 );
		SaveVehData(vehid-1, "CustomObj1On" );
		return 0;
	}
	if(gVehData[vehid-1][CustomObj2Model] == 0)
	{
		gVehData[vehid-1][CustomObj2Model] = model;
		gVehData[vehid-1][CustomObj2On] = 1;
		gVehData[vehid-1][CustomObj2][0] = 0.0;
		gVehData[vehid-1][CustomObj2][1] = 0.0;
		gVehData[vehid-1][CustomObj2][2] = 1.0;
		gVehData[vehid-1][CustomObj2][3] = 0.0;
		gVehData[vehid-1][CustomObj2][4] = 0.0;
		gVehData[vehid-1][CustomObj2][5] = 0.0;
		gVehData[vehid-1][CustomObj2ID] = CreateDynamicObject(
			gVehData[vehid-1][CustomObj2Model],
			gVehData[vehid-1][CustomObj2][0],
			gVehData[vehid-1][CustomObj2][1],
			gVehData[vehid-1][CustomObj2][2],
			gVehData[vehid-1][CustomObj2][3],
			gVehData[vehid-1][CustomObj2][4],
			gVehData[vehid-1][CustomObj2][5]);
		AttachDynamicObjectToVehicle(gVehData[vehid-1][CustomObj2ID], vehid, gVehData[vehid-1][CustomObj2][0], gVehData[vehid-1][CustomObj2][1], gVehData[vehid-1][CustomObj2][2], gVehData[vehid-1][CustomObj2][3], gVehData[vehid-1][CustomObj2][4], gVehData[vehid-1][CustomObj2][5]);
		SaveVehData(vehid-1, "CustomObj2Model" );
		SaveVehData(vehid-1, "CustomObj2", 0 );
		SaveVehData(vehid-1, "CustomObj2", 1 );
		SaveVehData(vehid-1, "CustomObj2", 2 );
		SaveVehData(vehid-1, "CustomObj2", 3 );
		SaveVehData(vehid-1, "CustomObj2", 4 );
		SaveVehData(vehid-1, "CustomObj2", 5 );
		SaveVehData(vehid-1, "CustomObj2On" );
		return 1;
	}
	if(gVehData[vehid-1][CustomObj3Model] == 0)
	{
		gVehData[vehid-1][CustomObj3Model] = model;
		gVehData[vehid-1][CustomObj3On] = 1;
		gVehData[vehid-1][CustomObj3][0] = 0.0;
		gVehData[vehid-1][CustomObj3][1] = 0.0;
		gVehData[vehid-1][CustomObj3][2] = 1.0;
		gVehData[vehid-1][CustomObj3][3] = 0.0;
		gVehData[vehid-1][CustomObj3][4] = 0.0;
		gVehData[vehid-1][CustomObj3][5] = 0.0;
		gVehData[vehid-1][CustomObj3ID] = CreateDynamicObject(
			gVehData[vehid-1][CustomObj3Model],
			gVehData[vehid-1][CustomObj3][0],
			gVehData[vehid-1][CustomObj3][1],
			gVehData[vehid-1][CustomObj3][2],
			gVehData[vehid-1][CustomObj3][3],
			gVehData[vehid-1][CustomObj3][4],
			gVehData[vehid-1][CustomObj3][5]);
		AttachDynamicObjectToVehicle(gVehData[vehid-1][CustomObj3ID], vehid, gVehData[vehid-1][CustomObj3][0], gVehData[vehid-1][CustomObj3][1], gVehData[vehid-1][CustomObj3][2], gVehData[vehid-1][CustomObj3][3], gVehData[vehid-1][CustomObj3][4], gVehData[vehid-1][CustomObj3][5]);
		SaveVehData(vehid-1, "CustomObj3Model" );
		SaveVehData(vehid-1, "CustomObj3", 0 );
		SaveVehData(vehid-1, "CustomObj3", 1 );
		SaveVehData(vehid-1, "CustomObj3", 2 );
		SaveVehData(vehid-1, "CustomObj3", 3 );
		SaveVehData(vehid-1, "CustomObj3", 4 );
		SaveVehData(vehid-1, "CustomObj3", 5 );
		SaveVehData(vehid-1, "CustomObj3On" );
		return 2;
	}
	if(gVehData[vehid-1][CustomObj4Model] == 0)
	{
		gVehData[vehid-1][CustomObj4Model] = model;
		gVehData[vehid-1][CustomObj4On] = 1;
		gVehData[vehid-1][CustomObj4][0] = 0.0;
		gVehData[vehid-1][CustomObj4][1] = 0.0;
		gVehData[vehid-1][CustomObj4][2] = 1.0;
		gVehData[vehid-1][CustomObj4][3] = 0.0;
		gVehData[vehid-1][CustomObj4][4] = 0.0;
		gVehData[vehid-1][CustomObj4][5] = 0.0;
		gVehData[vehid-1][CustomObj4ID] = CreateDynamicObject(
			gVehData[vehid-1][CustomObj4Model],
			gVehData[vehid-1][CustomObj4][0],
			gVehData[vehid-1][CustomObj4][1],
			gVehData[vehid-1][CustomObj4][2],
			gVehData[vehid-1][CustomObj4][3],
			gVehData[vehid-1][CustomObj4][4],
			gVehData[vehid-1][CustomObj4][5]);
		AttachDynamicObjectToVehicle(gVehData[vehid-1][CustomObj4ID], vehid, gVehData[vehid-1][CustomObj4][0], gVehData[vehid-1][CustomObj4][1], gVehData[vehid-1][CustomObj4][2], gVehData[vehid-1][CustomObj4][3], gVehData[vehid-1][CustomObj4][4], gVehData[vehid-1][CustomObj4][5]);
		SaveVehData(vehid-1, "CustomObj4Model" );
		SaveVehData(vehid-1, "CustomObj4", 0 );
		SaveVehData(vehid-1, "CustomObj4", 1 );
		SaveVehData(vehid-1, "CustomObj4", 2 );
		SaveVehData(vehid-1, "CustomObj4", 3 );
		SaveVehData(vehid-1, "CustomObj4", 4 );
		SaveVehData(vehid-1, "CustomObj4", 5 );
		SaveVehData(vehid-1, "CustomObj4On" );
		return 3;
	}
	if(gVehData[vehid-1][CustomObj5Model] == 0)
	{
		gVehData[vehid-1][CustomObj5Model] = model;
		gVehData[vehid-1][CustomObj5On] = 1;
		gVehData[vehid-1][CustomObj5][0] = 0.0;
		gVehData[vehid-1][CustomObj5][1] = 0.0;
		gVehData[vehid-1][CustomObj5][2] = 1.0;
		gVehData[vehid-1][CustomObj5][3] = 0.0;
		gVehData[vehid-1][CustomObj5][4] = 0.0;
		gVehData[vehid-1][CustomObj5][5] = 0.0;
		gVehData[vehid-1][CustomObj5ID] = CreateDynamicObject(
			gVehData[vehid-1][CustomObj5Model],
			gVehData[vehid-1][CustomObj5][0],
			gVehData[vehid-1][CustomObj5][1],
			gVehData[vehid-1][CustomObj5][2],
			gVehData[vehid-1][CustomObj5][3],
			gVehData[vehid-1][CustomObj5][4],
			gVehData[vehid-1][CustomObj5][5]);
		AttachDynamicObjectToVehicle(gVehData[vehid-1][CustomObj5ID], vehid, gVehData[vehid-1][CustomObj5][0], gVehData[vehid-1][CustomObj5][1], gVehData[vehid-1][CustomObj5][2], gVehData[vehid-1][CustomObj5][3], gVehData[vehid-1][CustomObj5][4], gVehData[vehid-1][CustomObj5][5]);
		SaveVehData(vehid-1, "CustomObj5Model" );
		SaveVehData(vehid-1, "CustomObj5", 0 );
		SaveVehData(vehid-1, "CustomObj5", 1 );
		SaveVehData(vehid-1, "CustomObj5", 2 );
		SaveVehData(vehid-1, "CustomObj5", 3 );
		SaveVehData(vehid-1, "CustomObj5", 4 );
		SaveVehData(vehid-1, "CustomObj5", 5 );
		SaveVehData(vehid-1, "CustomObj5On" );
		return 4;
	}
	if(gVehData[vehid-1][CustomObj6Model] == 0)
	{
		gVehData[vehid-1][CustomObj6Model] = model;
		gVehData[vehid-1][CustomObj6On] = 1;
		gVehData[vehid-1][CustomObj6][0] = 0.0;
		gVehData[vehid-1][CustomObj6][1] = 0.0;
		gVehData[vehid-1][CustomObj6][2] = 1.0;
		gVehData[vehid-1][CustomObj6][3] = 0.0;
		gVehData[vehid-1][CustomObj6][4] = 0.0;
		gVehData[vehid-1][CustomObj6][5] = 0.0;
		gVehData[vehid-1][CustomObj6ID] = CreateDynamicObject(
			gVehData[vehid-1][CustomObj6Model],
			gVehData[vehid-1][CustomObj6][0],
			gVehData[vehid-1][CustomObj6][1],
			gVehData[vehid-1][CustomObj6][2],
			gVehData[vehid-1][CustomObj6][3],
			gVehData[vehid-1][CustomObj6][4],
			gVehData[vehid-1][CustomObj6][5]);
		AttachDynamicObjectToVehicle(gVehData[vehid-1][CustomObj6ID], vehid, gVehData[vehid-1][CustomObj6][0], gVehData[vehid-1][CustomObj6][1], gVehData[vehid-1][CustomObj6][2], gVehData[vehid-1][CustomObj6][3], gVehData[vehid-1][CustomObj6][4], gVehData[vehid-1][CustomObj6][5]);
		SaveVehData(vehid-1, "CustomObj6Model" );
		SaveVehData(vehid-1, "CustomObj6", 0 );
		SaveVehData(vehid-1, "CustomObj6", 1 );
		SaveVehData(vehid-1, "CustomObj6", 2 );
		SaveVehData(vehid-1, "CustomObj6", 3 );
		SaveVehData(vehid-1, "CustomObj6", 4 );
		SaveVehData(vehid-1, "CustomObj6", 5 );
		SaveVehData(vehid-1, "CustomObj6On" );
		return 5;
	}
	if(gVehData[vehid-1][CustomObj7Model] == 0)
	{
		gVehData[vehid-1][CustomObj7Model] = model;
		gVehData[vehid-1][CustomObj7On] = 1;
		gVehData[vehid-1][CustomObj7][0] = 0.0;
		gVehData[vehid-1][CustomObj7][1] = 0.0;
		gVehData[vehid-1][CustomObj7][2] = 1.0;
		gVehData[vehid-1][CustomObj7][3] = 0.0;
		gVehData[vehid-1][CustomObj7][4] = 0.0;
		gVehData[vehid-1][CustomObj7][5] = 0.0;
		gVehData[vehid-1][CustomObj7ID] = CreateDynamicObject(
			gVehData[vehid-1][CustomObj7Model],
			gVehData[vehid-1][CustomObj7][0],
			gVehData[vehid-1][CustomObj7][1],
			gVehData[vehid-1][CustomObj7][2],
			gVehData[vehid-1][CustomObj7][3],
			gVehData[vehid-1][CustomObj7][4],
			gVehData[vehid-1][CustomObj7][5]);
		AttachDynamicObjectToVehicle(gVehData[vehid-1][CustomObj7ID], vehid, gVehData[vehid-1][CustomObj7][0], gVehData[vehid-1][CustomObj7][1], gVehData[vehid-1][CustomObj7][2], gVehData[vehid-1][CustomObj7][3], gVehData[vehid-1][CustomObj7][4], gVehData[vehid-1][CustomObj7][5]);
		SaveVehData(vehid-1, "CustomObj7Model" );
		SaveVehData(vehid-1, "CustomObj7", 0 );
		SaveVehData(vehid-1, "CustomObj7", 1 );
		SaveVehData(vehid-1, "CustomObj7", 2 );
		SaveVehData(vehid-1, "CustomObj7", 3 );
		SaveVehData(vehid-1, "CustomObj7", 4 );
		SaveVehData(vehid-1, "CustomObj7", 5 );
		SaveVehData(vehid-1, "CustomObj7On" );
		return 6;
	}
	return -1;
}

timer SetVehicleLastPos[600](vehicleid)
{
	gVehData[vehicleid-1][mVehSetToTp] = 0;
	if(IsVehicleOccupied(vehicleid))
		return;
	SetVehicleToPos(vehicleid, gVehData[vehicleid-1][mVehX], gVehData[vehicleid-1][mVehY], gVehData[vehicleid-1][mVehZ]);
}