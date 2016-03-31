#include <a_samp>
#include <zcmd>
#include <sscanf2>

#define COLOR_GREY              0xAFAFAFAA

CMD:setdoors(playerid,params[])
{
    new string[128],copyparams[48],count,decimal,vehid;
    vehid = GetPlayerVehicleID(playerid);
    for(new i = 0; i < strlen(params);i++)
    {
        if(params[i] == ' ')
        {
            continue;
        }
        copyparams[count] = params[i];
        count++;
    }
    unformat(copyparams,"b",decimal);
    new panels,doors,lights,tires;
    GetVehicleDamageStatus(vehid,panels,doors,lights,tires);
    UpdateVehicleDamageStatus(vehid,panels,decimal,lights,tires);
    format(string,sizeof(string),"doors: %s decimal: %d",params,decimal);
    SendClientMessage(playerid,COLOR_GREY,string);
    return 1;
}
CMD:setpanels(playerid,params[])
{
    new string[128],copyparams[48],count,decimal,vehid;
    vehid = GetPlayerVehicleID(playerid);
    for(new i = 0; i < strlen(params); i++)
    {
        if(params[i] == ' ')
        {
            continue;
        }
        copyparams[count] = params[i];
        count++;
    }
    unformat(copyparams,"b",decimal);
    new panels,doors,lights,tires;
    GetVehicleDamageStatus(vehid,panels,doors,lights,tires);
    UpdateVehicleDamageStatus(vehid,decimal,doors,lights,tires);
    format(string,sizeof(string),"panels: %s decimal: %d",params,decimal);
    SendClientMessage(playerid,COLOR_GREY,string);
    return 1;
}
CMD:getdoors(playerid,params[])
{
    new string[128],binary[48],vehid,exponent = 1;
    new panels,doors,tires,lights;
    vehid = GetPlayerVehicleID(playerid);
    GetVehicleDamageStatus(vehid,panels,doors,lights,tires);
    for(new i = 0; i <= 31;i++)
    {
        if(doors & exponent)
        {
            strins(binary,"1",0,sizeof(binary));
        } else {
            strins(binary,"0",0,sizeof(binary));
        }
        exponent = (2 * exponent);
        switch(i)
        {
            case 7,15,23: strins(binary," ",0,sizeof(binary));
        }
    }
    format(string,sizeof(string),"doors: %s decimal: %d",binary,doors);
    SendClientMessage(playerid,COLOR_GREY,string);
    return 1;
}
CMD:getpanels(playerid,params[])
{
    new string[128],binary[48],vehid,exponent = 1;
    new panels,doors,tires,lights;
    vehid = GetPlayerVehicleID(playerid);
    GetVehicleDamageStatus(vehid,panels,doors,lights,tires);
    for(new i = 0; i <= 31;i++)
    {
        if(panels & exponent)
        {
            strins(binary,"1",0,sizeof(binary));
        } else {
            strins(binary,"0",0,sizeof(binary));
        }
        exponent = (2 * exponent);
        switch(i)
        {
            case 7,15,23: strins(binary," ",0,sizeof(binary));
        }
    }
    format(string,sizeof(string),"panels: %s decimal: %d",binary,panels);
    SendClientMessage(playerid,COLOR_GREY,string);
    return 1;
}