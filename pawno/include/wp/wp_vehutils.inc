// const object_undamaged = 0;
// const door_swinging = 1;
// const door_damaged = 2;
// const door_damaged_swinging = 3;
// const door_fell_off = 4;
    
// const windshield_crackedA = 1;
// const windshield_crackedB = 2;
// const windshielddestroyed = 3;

// encode_lights(light1, light2, light3, light4)
// {
    // return light1 | (light2 << 1) | (light3 << 2) | (light4 << 3);
// }

// encode_tires(tire1, tire2, tire3, tire4)
// {
    // return tire1 | (tire2 << 1) | (tire3 << 2) | (tire4 << 3);
// }

encode_tires_bike(rear, front) 
{    
    return rear | (front << 1);
}

#pragma unused encode_tires_bike

// encode_doors(bonnet, boot, driver_door, passenger_door, behind_driver_door, behind_passenger_door) {
    // #pragma unused behind_driver_door
    // #pragma unused behind_passenger_door
        
    // will be modified once again, when rear doors are synced.
    // return bonnet | (boot << 8) | (driver_door << 16) | (passenger_door << 24);
    
// }

// encode_panels(flp, frp, rlp, rrp, windshield, front_bumper, rear_bumper) {
    
    // return flp | (frp << 4) | (rlp << 8) | (rrp << 12) | (windshield << 16) | (front_bumper << 20) | (rear_bumper << 24);
    
// }