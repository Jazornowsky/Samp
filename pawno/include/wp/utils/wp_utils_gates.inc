/***
*
* File: wp_utils_gates.inc
* Auth: Damian Wojdat
* Date: 11.03.2012
* Desc: Hardcoded gate timers.
*
*************************************************************************************************************/

timer GateClose2[2000]()
{
	MoveDynamicObject(gGateSfParking1a,-1990.5186767578, 543.30401611328, 36.789016723633, 3.5);
    return 0;
}

timer GateClose3[2000]()
{
	MoveDynamicObject(gGateSfParking1b,-2061.861328125, 434.58581542969, 25.348533630371, 3.5);
    return 0;
}

timer ArmyGate1Close[5000]()
{
	SetDynamicObjectRot(gGateSfMilitary1a,0.000000, 270.49006347656, 359.99487304688);
    return 0;
}

timer PoliceGate1Close[10000]()
{
	MoveDynamicObject(gGateSfPd2a, -1572.1822, 658.74, 6.75, 0.01, 0.0, 90.0, 90.0);
    return 0;
}

timer PoliceGate2Close[10000]()
{
	MoveDynamicObject(gGateSfPd3a, -1701.430664, 687.677, 24.65, 0.01, 0.0, 270.0, 90.0);
    return 0;
}
