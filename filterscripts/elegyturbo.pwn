/*
                          Ronaldo_raul™ Productions Presents-
________________________________________________________________________________
                                   Elegy Turbo's!
//==============================================================================
-->Do Not Re-Release This Script Without My Permission.
-->DO Not Claim This Script As Your Own.
-->Do Not Sell This Script.
-->Suggestion,Bugs........PM ME ! Or Post Them On The Release Thread.

                      This FilterScript is made by Ronaldo_raul™


                                  Copyright © 2012-2013
                  *******Keep All credits in the filterscript.*******

//==============================================================================*/
//==============================================================================
//                          Defines And Include
//==============================================================================
#define FILTERSCRIPT

#include < a_samp >
#include < zcmd >


#define INFO    0x0080FFFF
#define WHITE   "{FFFFFF}"
#define RED "{FF0000}"
#define GREEN   "{80FF00}"

new HaveTurbo [ MAX_PLAYERS ] ;
new Fire [ 14 ] ;
new Ex [ 7 ] ;
//==============================================================================
//==============================================================================
public OnFilterScriptInit()
{
    print("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
    print(" Turbo Fire - FS By Ronaldo_raul\n Loaded.");
    print("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    return 1;
}

public OnPlayerConnect(playerid)
{
    HaveTurbo [ playerid ] = 0 ;
    return 1;
}

public OnPlayerDisconnect(playerid, reason)
{
    HaveTurbo [ playerid ] = 0 ;
    return 1;
}

public OnPlayerExitVehicle(playerid, vehicleid)
{
    if ( HaveTurbo [ playerid ] == 1 )
    {
        DestroyObject ( Ex [ 0 ] ) ;
        DestroyObject ( Ex [ 1 ] ) ;
        DestroyObject ( Ex [ 2 ] ) ;
        DestroyObject ( Ex [ 3 ] ) ;
        DestroyObject ( Ex [ 4 ] ) ;
        DestroyObject ( Ex [ 5 ] ) ;
        DestroyObject ( Ex [ 6 ] ) ;
        HaveTurbo [ playerid ] = 0 ;
    }
    return 1;
}

CMD:turbo ( playerid , params [] )
{
    if ( HaveTurbo [ playerid ] == 1 ) return SendClientMessage ( playerid , INFO , "(INFO) "#WHITE"You already have "#RED"turbo's "#GREEN"installed." ) ;
    if ( IsPlayerInAnyVehicle ( playerid ) && GetVehicleModel ( GetPlayerVehicleID ( playerid ) ) == 562 )
    {
        Ex [ 0 ] = CreateObject(1018,0,0,-1000,0,0,0,100);
        AttachObjectToVehicle(Ex [ 0 ], GetPlayerVehicleID(playerid), 0.089999,1.275000,-0.505000,-123.119987,-1.620000,-270.719848);
        Ex [ 1 ] = CreateObject(1018,0,0,-1000,0,0,0,100);
        AttachObjectToVehicle(Ex [ 1 ], GetPlayerVehicleID(playerid), 0.089999,1.564999,-0.505000,-123.119987,-1.620000,-270.719848);
        Ex [ 2 ] = CreateObject(1018,0,0,-1000,0,0,0,100);
        AttachObjectToVehicle(Ex [ 2 ], GetPlayerVehicleID(playerid), 0.059999,1.854999,-0.505000,-123.119987,-1.620000,-270.719848);
        Ex [ 3 ] = CreateObject(1018,0,0,-1000,0,0,0,100);
        AttachObjectToVehicle(Ex [ 3 ], GetPlayerVehicleID(playerid), 0.059999,1.854999,-0.505000,-123.119987,-1.620000,-270.719848);
        Ex [ 4 ] = CreateObject(1018,0,0,-1000,0,0,0,100);
        AttachObjectToVehicle(Ex [ 4 ], GetPlayerVehicleID(playerid), -0.045000,1.854999,-0.505000,-123.119987,3.779998,-88.020568);
        Ex [ 5 ] = CreateObject(1018,0,0,-1000,0,0,0,100);
        AttachObjectToVehicle(Ex [ 5 ], GetPlayerVehicleID(playerid), -0.075000,1.529999,-0.505000,-123.119987,9.540000,-83.700561);
        Ex [ 6 ] = CreateObject(1018,0,0,-1000,0,0,0,100);
        AttachObjectToVehicle(Ex [ 6 ], GetPlayerVehicleID(playerid), -0.095000,1.275000,-0.505000,-123.119987,-1.620000,-451.260925);
        HaveTurbo [ playerid ] = 1 ;
    }
    else SendClientMessage ( playerid , INFO , "(INFO) "#WHITE"You need to be in an "#RED"elegy "#WHITE"to use this "#GREEN"command." ) ;
    return 1 ;
}


public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if( GetPlayerState ( playerid ) != PLAYER_STATE_DRIVER || GetVehicleModel ( GetPlayerVehicleID ( playerid ) ) == 562 )
    {
        if ( ( ( ( newkeys & ( 4 ) ) == ( 4 ) ) && ( ( oldkeys & ( 4 ) ) != ( 4 ) ) ) )
        {
        Fire [ 0 ] = CreateObject(18693,0,0,-1000,0,0,0,100);
        AttachObjectToVehicle(Fire [ 0 ], GetPlayerVehicleID(playerid), -0.520000,1.205000,-1.174999,0.000000,0.000000,0.000000);
        Fire [ 1 ] = CreateObject(18693,0,0,-1000,0,0,0,100);
        AttachObjectToVehicle(Fire [ 1 ], GetPlayerVehicleID(playerid), -0.520000,1.365000,-1.174999,0.000000,0.000000,0.000000);
        Fire [ 2 ] = CreateObject(18693,0,0,-1000,0,0,0,100);
        AttachObjectToVehicle(Fire [ 2 ], GetPlayerVehicleID(playerid), -0.520000,1.505000,-1.174999,0.000000,0.000000,0.000000);
        Fire [ 3 ] = CreateObject(18693,0,0,-1000,0,0,0,100);
        AttachObjectToVehicle(Fire [ 3 ], GetPlayerVehicleID(playerid), -0.520000,1.665000,-1.174999,0.000000,0.000000,0.000000);
        Fire [ 4 ] = CreateObject(18693,0,0,-1000,0,0,0,100);
        AttachObjectToVehicle(Fire [ 4 ], GetPlayerVehicleID(playerid), -0.520000,1.205000,-1.174999,0.000000,0.000000,0.000000);
        Fire [ 5 ] = CreateObject(18693,0,0,-1000,0,0,0,100);
        AttachObjectToVehicle(Fire [ 5 ], GetPlayerVehicleID(playerid), -0.599999,1.800000,-1.174999,0.000000,0.000000,0.000000);
        Fire [ 6 ] = CreateObject(18693,0,0,-1000,0,0,0,100);
        AttachObjectToVehicle(Fire [ 6 ], GetPlayerVehicleID(playerid), -0.599999,1.950000,-1.174999,0.000000,0.000000,0.000000);
        Fire [ 7 ] = CreateObject(18693,0,0,-1000,0,0,0,100);
        AttachObjectToVehicle(Fire [ 7 ], GetPlayerVehicleID(playerid), 0.559999,1.950000,-1.174999,0.000000,0.000000,0.000000);
        Fire [ 8 ] = CreateObject(18693,0,0,-1000,0,0,0,100);
        AttachObjectToVehicle(Fire [ 8 ], GetPlayerVehicleID(playerid), 0.559999,1.790000,-1.174999,0.000000,0.000000,0.000000);
        Fire [ 9 ] = CreateObject(18693,0,0,-1000,0,0,0,100);
        AttachObjectToVehicle(Fire [ 9 ], GetPlayerVehicleID(playerid), 0.539999,1.660000,-1.174999,0.000000,0.000000,0.000000);
        Fire [ 10 ] = CreateObject(18693,0,0,-1000,0,0,0,100);
        AttachObjectToVehicle(Fire [ 10 ], GetPlayerVehicleID(playerid), 0.539999,1.490000,-1.174999,0.000000,0.000000,0.000000);
        Fire [ 11 ] = CreateObject(18693,0,0,-1000,0,0,0,100);
        AttachObjectToVehicle(Fire [ 11 ], GetPlayerVehicleID(playerid), 0.539999,1.330000,-1.174999,0.000000,0.000000,0.000000);
        Fire [ 12 ] = CreateObject(18693,0,0,-1000,0,0,0,100);
        AttachObjectToVehicle(Fire [ 12 ], GetPlayerVehicleID(playerid), 0.539999,1.160001,-1.174999,0.000000,0.000000,0.000000);
        }
        else if ( ( ( ( newkeys & ( 4 ) ) != ( 4 ) ) && ( ( oldkeys & ( 4 ) ) == ( 4 ) ) ) )
        {
        DestroyObject ( Fire [ 0 ] ) ;
        DestroyObject ( Fire [ 1 ] ) ;
        DestroyObject ( Fire [ 2 ] ) ;
        DestroyObject ( Fire [ 3 ] ) ;
        DestroyObject ( Fire [ 4 ] ) ;
        DestroyObject ( Fire [ 5 ] ) ;
        DestroyObject ( Fire [ 6 ] ) ;
        DestroyObject ( Fire [ 7 ] ) ;
        DestroyObject ( Fire [ 8 ] ) ;
        DestroyObject ( Fire [ 9 ] ) ;
        DestroyObject ( Fire [ 10 ] ) ;
        DestroyObject ( Fire [ 11 ] ) ;
        DestroyObject ( Fire [ 12 ] ) ;
        }
    }
    return 1;
}

public OnFilterScriptExit()
{
    print("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
    print(" Turbo Fire - FS By Ronaldo_raul\n UnLoaded.");
    print("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    DestroyObject ( Fire [ 0 ] ) ;
    DestroyObject ( Fire [ 1 ] ) ;
    DestroyObject ( Fire [ 2 ] ) ;
    DestroyObject ( Fire [ 3 ] ) ;
    DestroyObject ( Fire [ 4 ] ) ;
    DestroyObject ( Fire [ 5 ] ) ;
    DestroyObject ( Fire [ 6 ] ) ;
    DestroyObject ( Fire [ 7 ] ) ;
    DestroyObject ( Fire [ 8 ] ) ;
    DestroyObject ( Fire [ 9 ] ) ;
    DestroyObject ( Fire [ 10 ] ) ;
    DestroyObject ( Fire [ 11 ] ) ;
    DestroyObject ( Fire [ 12 ] ) ;
    DestroyObject ( Ex [ 0 ] ) ;
    DestroyObject ( Ex [ 1 ] ) ;
    DestroyObject ( Ex [ 2 ] ) ;
    DestroyObject ( Ex [ 3 ] ) ;
    DestroyObject ( Ex [ 4 ] ) ;
    DestroyObject ( Ex [ 5 ] ) ;
    DestroyObject ( Ex [ 6 ] ) ;
    return 1;
}



// Ronaldo_raul™ Productions
// Copyright © 2012-2013
//Do Not REMOVE ANY CREDITS!