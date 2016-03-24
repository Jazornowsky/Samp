////Includes////
#include <a_samp>

////Defines////
#undef MAX_PLAYERS
#define MAX_PLAYERS 16

#define OPTION_TYPE_COMMAND 0
#define OPTION_TYPE_CATEGORY 1
#define ListCommand(%1,%2) gTemp[0]=%2;format(gTempString,sizeof(gTempString),"%s%s%s\n",gTempString,%1,(gTemp[0] == OPTION_TYPE_COMMAND) ? ("") : ("..."))
#define ExecuteCommand OnPlayerExecuteCommand(playerid)
#define InputBox(%1,%2,%3) ShowPlayerDialog(%1,0,DIALOG_STYLE_INPUT,%2,%3,"Ok","Cancel")

#define AMOUNTOFCOMMANDS 5
#define CMD_NONE 0
#define CMD_SET_HEALTH 1
#define CMD_GIVE_GUN 2
#define CMD_GIVE_VEHICLE 3
#define CMD_EXPLODE 4
#define CMD_GOTO 5

#define PARAM_TYPE_NONE 0
#define PARAM_TYPE_AFFIRM 1
#define PARAM_TYPE_PLAYER 2
#define PARAM_TYPE_INPUT 3

/*public OnFilterScriptInit()
{
	//Test
	for(new i; i < 14; i++)
	{
	    new pname[25];
	    format(pname,sizeof(pname),"BotNumber[%d]",i);
	    ConnectNPC(pname,"npctest");
	}
}*/

////Variables////
forward OnPlayerExecuteCommand(playerid);

//Global Temps
new gTempString[512]; //Global Temporary String So That It Doesn't Need To Be Created Again
new gTemp[2];
new Float:gTempFloat[4]; //Same, But A Multi-Celled Array For Convenience (Co-Ordinates)

//Command Structure Variables
new pCommand[MAX_PLAYERS];
new pCmdProc[MAX_PLAYERS];
new pCmdCat[MAX_PLAYERS];
new pCmdParam[MAX_PLAYERS][5];
new pCmdStrParam[MAX_PLAYERS][5][256];
new pPlayerListPage[MAX_PLAYERS];

//Player Information
new pCmdPermissions[MAX_PLAYERS][AMOUNTOFCOMMANDS]; //Player Command Permissions, Used To Restrict Player Abilities Per Command
new pVehicle[MAX_PLAYERS];

////Functions////

//Show Admin Panel
ShowAdminPanel(playerid)
{
	gTempString="";
	ResetParameters(playerid);

	ListCommand("Refill Health",OPTION_TYPE_COMMAND);
	ListCommand("Explode",OPTION_TYPE_COMMAND);
	ListCommand("Go To",OPTION_TYPE_COMMAND);
	ListCommand("Give Gun",OPTION_TYPE_CATEGORY);
	ListCommand("Give Vehicle",OPTION_TYPE_CATEGORY);
	
	//Goes On The End Of All Categories -- I Suggest You Change The Title
	new tmpstring[50];
	pCmdProc[playerid]=PARAM_TYPE_NONE;
	pCommand[playerid]=CMD_NONE;
	GetPlayerName(pCmdParam[playerid][0],tmpstring,sizeof(tmpstring));
	format(tmpstring,sizeof(tmpstring),"Admin Panel -- Player Selected: [%d]%s",pCmdParam[playerid][0],tmpstring);
	ShowPlayerDialog(playerid,0,DIALOG_STYLE_LIST,tmpstring,gTempString,"Select","Close");
}

//Categories
Category_Give_Gun(playerid)
{
	gTempString="";
	
	ListCommand("Rifles",OPTION_TYPE_CATEGORY);
	ListCommand("Minigun",OPTION_TYPE_COMMAND);
	ListCommand("Specify Gun ID",OPTION_TYPE_COMMAND);
	
    new tmpstring[50];
    pCmdProc[playerid]=PARAM_TYPE_NONE;
	GetPlayerName(pCmdParam[playerid][0],tmpstring,sizeof(tmpstring));
	format(tmpstring,sizeof(tmpstring),"Give Gun -- Player Selected: [%d]%s",pCmdParam[playerid][0],tmpstring);
	ShowPlayerDialog(playerid,0,DIALOG_STYLE_LIST,tmpstring,gTempString,"Select","Return");
}
Category_GG_Rifles(playerid)
{
	gTempString="";

	ListCommand("M4 Assault Rifle",OPTION_TYPE_COMMAND);
	ListCommand("Kalashnikov",OPTION_TYPE_COMMAND);
	ListCommand("Country Rifle",OPTION_TYPE_COMMAND);
	ListCommand("Sniper Rifle",OPTION_TYPE_COMMAND);
	
    new tmpstring[50];
    pCmdProc[playerid]=PARAM_TYPE_NONE;
	GetPlayerName(pCmdParam[playerid][0],tmpstring,sizeof(tmpstring));
	format(tmpstring,sizeof(tmpstring),"Give Gun -- Rifles -- Player Selected: [%d]%s",pCmdParam[playerid][0],tmpstring);
	ShowPlayerDialog(playerid,0,DIALOG_STYLE_LIST,tmpstring,gTempString,"Select","Return");
}
Category_Give_Vehicle(playerid)
{
	gTempString="";
	
	ListCommand("Specify Model ID",OPTION_TYPE_COMMAND);
	ListCommand("Infernus",OPTION_TYPE_COMMAND);
	ListCommand("NRG-500",OPTION_TYPE_COMMAND);
	ListCommand("Hydra",OPTION_TYPE_COMMAND);

    new tmpstring[50];
    pCmdProc[playerid]=PARAM_TYPE_NONE;
	GetPlayerName(pCmdParam[playerid][0],tmpstring,sizeof(tmpstring));
	format(tmpstring,sizeof(tmpstring),"Give Vehicle -- Player Selected: [%d]%s",pCmdParam[playerid][0],tmpstring);
	ShowPlayerDialog(playerid,0,DIALOG_STYLE_LIST,tmpstring,gTempString,"Select","Return");
}

//Affirm Choice
Affirm_Command(playerid)
{
	gTempString="";
    new pname[25];
    GetPlayerName(pCmdParam[playerid][0],pname,sizeof(pname));
    switch(pCommand[playerid])
    {
    
        case CMD_SET_HEALTH: format(gTempString,sizeof(gTempString),"Set %s's Health To %0f?",pname,floatstr(pCmdStrParam[playerid][0]));
        
        case CMD_GIVE_GUN:
		{
			GetWeaponName(pCmdParam[playerid][1],gTempString,20);
			format(gTempString,sizeof(gTempString),"Give %d Rounds Of %s To %s?",pCmdParam[playerid][2],gTempString,pname);
		}
		case CMD_GIVE_VEHICLE: format(gTempString,sizeof(gTempString),"Give Vehicle Model ID %d To %s?",pCmdParam[playerid][1],pname);
		
		case CMD_EXPLODE: format(gTempString,sizeof(gTempString),"Blow Up %s?",pname);
		
		case CMD_GOTO:
		{
		    new pname2[MAX_PLAYER_NAME];
		    GetPlayerName(pCmdParam[playerid][1],pname2,sizeof(pname2));
			format(gTempString,sizeof(gTempString),"Send %s to %s?",pname,pname2);
		}
	}
	pCmdProc[playerid]=PARAM_TYPE_AFFIRM;
	ShowPlayerDialog(playerid,0,DIALOG_STYLE_MSGBOX,"Are You Sure?",gTempString,"Yes","No");
	return 1;
}


//IsCategory Function
IsCategory(command[])return !strcmp(command[strlen(command)-3],"...",false,3);
//Reset Parameters
ResetParameters(playerid)
{
	for(new i = 1; i<5;i++)
	{
	    pCmdParam[playerid][i]=0;
	    pCmdStrParam[playerid][i]="";
	}
	pCmdStrParam[playerid][0]="";
}
ShowPlayerList(playerid)
{
	gTempString="";
	new pname[45];
	for(new i = pPlayerListPage[playerid]*10;i<(pPlayerListPage[playerid]*10)+10;i++)
	{
	    if(IsPlayerConnected(i)&&!IsPlayerNPC(i))
	    {
		    GetPlayerName(i,pname,sizeof(pname));
		    format(pname,sizeof(pname),"[%d]%s",i,pname);
			ListCommand(pname,OPTION_TYPE_COMMAND);
		}
	}
	
	new tmp;
	for(new o; o < MAX_PLAYERS;o++)
	{
		if(IsPlayerConnected(o)&&!IsPlayerNPC(o))tmp++;
	}

	if(pPlayerListPage[playerid]>0)
	{
		ListCommand("Previous Page",OPTION_TYPE_CATEGORY);
	}
	if(tmp>(pPlayerListPage[playerid]*10)+10)
	{
		ListCommand("Next Page",OPTION_TYPE_CATEGORY);
	}
	pCmdProc[playerid]=PARAM_TYPE_PLAYER;
	ShowPlayerDialog(playerid,0,DIALOG_STYLE_LIST,"Choose A Player",gTempString,"Select","Cancel");
}

////Call Backs////
public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	gTempString="";
	//If Player Hits Cancel or Back
	if(!response)
	{
	    ResetParameters(playerid);
	    switch(pCommand[playerid])
	    {
	        case CMD_SET_HEALTH:
	        {
	            ShowAdminPanel(playerid);
	            return 1;
	        }
	        case CMD_EXPLODE:
	        {
	            ShowAdminPanel(playerid);
	            return 1;
	        }
	        case CMD_GIVE_GUN:
	        {
				if((pCmdProc[playerid]==PARAM_TYPE_INPUT)||(pCmdProc[playerid]==PARAM_TYPE_AFFIRM))
				{
				    pCmdProc[playerid]=PARAM_TYPE_NONE;
					if(!pCmdCat[playerid])Category_Give_Gun(playerid);
					else Category_GG_Rifles(playerid);
					return 1;
				}
				if(pCmdCat[playerid]){pCmdCat[playerid]=0;Category_Give_Gun(playerid);}
				else ShowAdminPanel(playerid);
				return 1;
	        }
	        case CMD_GIVE_VEHICLE:
	        {
	            if((pCmdProc[playerid]==PARAM_TYPE_INPUT)||(pCmdProc[playerid]==PARAM_TYPE_AFFIRM))
				{
					pCmdProc[playerid]=PARAM_TYPE_NONE;
					Category_Give_Vehicle(playerid);
				}
				else ShowAdminPanel(playerid);
				return 1;
	        }
	        case CMD_GOTO:
	        {
				pCmdProc[playerid]=PARAM_TYPE_NONE;
				ShowAdminPanel(playerid);
				return 1;
	        }
	        default:
	        {
	            return 1;
	        }
	    }
	}


	//If The Player Has Typed In Using The Input Box
	if(pCmdProc[playerid]==PARAM_TYPE_INPUT)
	{
	    switch(pCommand[playerid])
	    {
	        case CMD_GIVE_GUN:
	        {
	            if(!pCmdParam[playerid][1])
	            {
					pCmdParam[playerid][1]=strval(inputtext);
	                new wname[20];
	                GetPlayerName(pCmdParam[playerid][0],gTempString,sizeof(gTempString));
	                GetWeaponName(pCmdParam[playerid][1],wname,20);
	                format(gTempString,sizeof(gTempString),"Give %s To %s",wname,gTempString);
	                InputBox(playerid,"Ammo Amount",gTempString);
	                return 1;
	            }
	            pCmdParam[playerid][2]=strval(inputtext);
	            Affirm_Command(playerid);
	            return 1;
	        }
	        case CMD_GIVE_VEHICLE:
	        {
				if((strval(inputtext)<400)||(strval(inputtext)>611))
				{
				    new pname[MAX_PLAYER_NAME];
				    GetPlayerName(pCmdParam[playerid][0],pname,sizeof(pname));
				    format(gTempString,sizeof(gTempString),"Give Vehicle To %s",pname);
					InputBox(playerid,"Invalid Model ID! 400-611",gTempString);
					return 1;
				}
				pCmdParam[playerid][1]=strval(inputtext);
				Affirm_Command(playerid);
				return 1;
	        }
	    }
	}
	
	//Player Has Made An Input Via Player Table
	if(pCmdProc[playerid]==PARAM_TYPE_PLAYER)
	{
	    switch(pCommand[playerid])
	    {
	        case CMD_GOTO:
	        {
	            if(IsCategory(inputtext))
	            {
	                if(!strcmp("Next Page",inputtext,false, 9))
	                {
	                    pPlayerListPage[playerid]++;
	                    ShowPlayerList(playerid);
	                    return 1;
	                }
	                if(!strcmp("Previous Page",inputtext,false, 13))
	                {
	                    pPlayerListPage[playerid]--;
	                    ShowPlayerList(playerid);
	                    return 1;
	                }
	            }
	            pCmdParam[playerid][1]=strval(inputtext[1]);
	            Affirm_Command(playerid);
	            return 1;
	        }
	    }
	}
	
	//Player Has Affirmed Something
	if(pCmdProc[playerid]==PARAM_TYPE_AFFIRM)
	{
	    ExecuteCommand;
	    return 1;
	}
	
	
	//Player Has Selected Something
	//This Is Where You Choose Where Player Gets The Parameters
	gTempString="";//Resetting global temp
	switch(pCommand[playerid])
	{
	    //These Commands Are On The Main Page
	    case CMD_NONE:
	    {
	        //If It's A Category
			if(IsCategory(inputtext))
			{
			    if(!strcmp("Give Gun",inputtext,false,8))
			    {
			        pCommand[playerid]=CMD_GIVE_GUN;
					Category_Give_Gun(playerid);
					return 1;
			    }
			    if(!strcmp("Give Vehicle",inputtext,false,12))
			    {
			        pCommand[playerid]=CMD_GIVE_VEHICLE;
					Category_Give_Vehicle(playerid);
					return 1;
			    }
			}
			//If It's NOT A Category
			if(!strcmp("Refill Health",inputtext,false,13))
			{
				pCmdStrParam[playerid][0]="100.0";
				pCommand[playerid]=CMD_SET_HEALTH;
				Affirm_Command(playerid);
				return 1;
			}
			if(!strcmp("Explode",inputtext,false,7))
			{
				pCommand[playerid]=CMD_EXPLODE;
				Affirm_Command(playerid);
				return 1;
			}
			if(!strcmp("Go To",inputtext,false,5))
			{
				pCommand[playerid]=CMD_GOTO;
				ShowPlayerList(playerid);
				return 1;
			}
	    }
	    //These Commands Are In The Give Gun Category

	    case CMD_GIVE_GUN:
	    {
	        if(IsCategory(inputtext))
			{
			    if(!strcmp("Rifles",inputtext,false,6))
			    {
					pCmdCat[playerid]=1;
					Category_GG_Rifles(playerid);
					return 1;
			    }
			}

			if(!strcmp("Minigun",inputtext,false,7))
			{
			    pCmdParam[playerid][1]=38;
			    pCmdProc[playerid]=PARAM_TYPE_INPUT;
			    new pname[MAX_PLAYER_NAME];
			    GetPlayerName(pCmdParam[playerid][0],pname,sizeof(pname));
			    format(gTempString,sizeof(gTempString),"Give Minigun To %s",pname);
				InputBox(playerid,"Ammo Amount",gTempString);
				return 1;
			}
			if(!strcmp("Specify Gun ID",inputtext,false,14))
			{
			    pCmdProc[playerid]=PARAM_TYPE_INPUT;
			    new pname[MAX_PLAYER_NAME];
			    GetPlayerName(pCmdParam[playerid][0],pname,sizeof(pname));
			    format(gTempString,sizeof(gTempString),"Give To %s",pname);
				InputBox(playerid,"Weapon ID",gTempString);
				return 1;
			}
			//If The Categorty Isn't 0 (CMD_GIVE_GUN + pCmdCat of 1 = Rifle Selections)
			if(pCmdCat[playerid])
			{

				if(!strcmp("M4 Assault Rifle",inputtext,false,16))
				{
				    pCmdParam[playerid][1]=31;
				    pCmdProc[playerid]=PARAM_TYPE_INPUT;
				    new pname[MAX_PLAYER_NAME];
				    GetPlayerName(pCmdParam[playerid][0],pname,sizeof(pname));
				    format(gTempString,sizeof(gTempString),"Give M4 Assault Rifle To %s",pname);
					InputBox(playerid,"Ammo Amount",gTempString);
					return 1;
				}
				if(!strcmp("Kalashnikov",inputtext,false,6))
				{
				    pCmdParam[playerid][1]=30;
				    pCmdProc[playerid]=PARAM_TYPE_INPUT;
				    new pname[MAX_PLAYER_NAME];
				    GetPlayerName(pCmdParam[playerid][0],pname,sizeof(pname));
				    format(gTempString,sizeof(gTempString),"Give Kalashnikov To %s",pname);
					InputBox(playerid,"Ammo Amount",gTempString);
					return 1;
				}
				if(!strcmp("Country Rifle",inputtext,false,16))
				{
				    pCmdParam[playerid][1]=33;
				    pCmdProc[playerid]=PARAM_TYPE_INPUT;
				    new pname[MAX_PLAYER_NAME];
				    GetPlayerName(pCmdParam[playerid][0],pname,sizeof(pname));
				    format(gTempString,sizeof(gTempString),"Give Country Rifle To %s",pname);
					InputBox(playerid,"Ammo Amount",gTempString);
					return 1;
				}
				if(!strcmp("Sniper Rifle",inputtext,false,16))
				{
				    pCmdParam[playerid][1]=34;
				    pCmdProc[playerid]=PARAM_TYPE_INPUT;
				    new pname[MAX_PLAYER_NAME];
				    GetPlayerName(pCmdParam[playerid][0],pname,sizeof(pname));
				    format(gTempString,sizeof(gTempString),"Give Sniper Rifle To %s",pname);
					InputBox(playerid,"Ammo Amount",gTempString);
					return 1;
				}
			}
	    }
	    //These Commands Are In The Give Vehicle Category
		case CMD_GIVE_VEHICLE:
		{
			if(!strcmp("Specify Model ID",inputtext,false,16))
			{
			    pCmdProc[playerid]=PARAM_TYPE_INPUT;
			    new pname[MAX_PLAYER_NAME];
			    GetPlayerName(pCmdParam[playerid][0],pname,sizeof(pname));
			    format(gTempString,sizeof(gTempString),"Give Vehicle To %s",pname);
				InputBox(playerid,"Vehicle Model ID",gTempString);
				return 1;
			}
			if(!strcmp("Infernus",inputtext,false,8))
			{
			    pCmdParam[playerid][1]=411;
			    Affirm_Command(playerid);
			    return 1;
			}
			if(!strcmp("NRG-500",inputtext,false,7))
			{
			    pCmdParam[playerid][1]=522;
			    Affirm_Command(playerid);
			    return 1;
			}
			if(!strcmp("Hydra",inputtext,false,5))
			{
			    pCmdParam[playerid][1]=520;
			    Affirm_Command(playerid);
			    return 1;
			}
		}
	}

	return 0;
}

public OnPlayerExecuteCommand(playerid)
{
	switch(pCommand[playerid])
	{
	    case CMD_EXPLODE:
	    {
	        GetPlayerPos(pCmdParam[playerid][0],gTempFloat[0],gTempFloat[1],gTempFloat[2]);
	        CreateExplosion(gTempFloat[0],gTempFloat[1],gTempFloat[2],12,5);
	        return 1;
	    }
	    case CMD_GOTO:
	    {
	        GetPlayerPos(pCmdParam[playerid][1],gTempFloat[0],gTempFloat[1],gTempFloat[2]);
			if(IsPlayerInAnyVehicle(pCmdParam[playerid][0]))SetVehiclePos(GetPlayerVehicleID(pCmdParam[playerid][0]),gTempFloat[0],gTempFloat[1]+1,gTempFloat[2]);
	        else SetPlayerPos(pCmdParam[playerid][0],gTempFloat[0],gTempFloat[1]+1,gTempFloat[2]);
	        return 1;
	    }
	    case CMD_SET_HEALTH:
	    {
	        SetPlayerHealth(pCmdParam[playerid][0],floatstr(pCmdStrParam[playerid][0]));
	        return 1;
	    }
	    case CMD_GIVE_GUN:
	    {
	        GivePlayerWeapon(pCmdParam[playerid][0],pCmdParam[playerid][1],pCmdParam[playerid][2]);
	        return 1;
	    }
	    case CMD_GIVE_VEHICLE:
	    {
            GetPlayerPos(pCmdParam[playerid][0],gTempFloat[0],gTempFloat[1],gTempFloat[2]);
			GetPlayerFacingAngle(pCmdParam[playerid][0],gTempFloat[3]);
            if(IsPlayerInAnyVehicle(pCmdParam[playerid][0]))SetPlayerPos(pCmdParam[playerid][0],gTempFloat[0],gTempFloat[1],gTempFloat[2]);
			DestroyVehicle(pVehicle[pCmdParam[playerid][0]]);
			pVehicle[pCmdParam[playerid][0]]=CreateVehicle(pCmdParam[playerid][1],gTempFloat[0],gTempFloat[1],gTempFloat[2],gTempFloat[3],-1,-1,60000);
			PutPlayerInVehicle(pCmdParam[playerid][0],pVehicle[pCmdParam[playerid][0]],0);
			return 1;
	    }
	}
	return 0;
}

public OnPlayerClickPlayer(playerid, clickedplayerid, source)
{
	pCmdParam[playerid][0]=clickedplayerid;
	ShowAdminPanel(playerid);
}