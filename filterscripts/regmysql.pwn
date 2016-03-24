/*
	Example MySQL connect/register/login filterscript (updated for SA:MP 0.3)
	
	This filterscript just works with 1.0.3R2
*/

#include <a_samp>
#include <a_mysql>

//MySQL Configuration
#define SQL_HOST "db4free.net"
#define SQL_DB "wparty_samp"
#define SQL_USER "user"
#define SQL_PASS "qwertyuiop!2#4%6&8(0"

#define TABLENAME "users"

#define CONNECT_THREAD_ID 1
#define REG_THREAD_ID 2
#define LOGIN_THREAD_ID 3

#define GREY 0xAFAFAFAA
#define RED 0xFF0000AA
#define YELLOW 0xFFFF00AA
#define LIGHTBLUE 0x33CCFFAA

#define dcmd(%1,%2,%3) if (!strcmp((%3)[1], #%1, true, (%2)) && ((((%3)[(%2) + 1] == '\0') && (dcmd_%1(playerid, ""))) || (((%3)[(%2) + 1] == ' ') && (dcmd_%1(playerid, (%3)[(%2) + 2]))))) return 1

new
	bool:LoggedIn[MAX_PLAYERS] = { false, ... },
	bool:AccRegistered[MAX_PLAYERS] = { false, ... },
	Wrongattempt[MAX_PLAYERS],
	TimerSet[MAX_PLAYERS],
	pLogtimer[MAX_PLAYERS],
	PlayerMoney[MAX_PLAYERS],
	CONNECT_PLAYER_ID = INVALID_PLAYER_ID,
	LOGIN_PLAYER_ID = INVALID_PLAYER_ID,
	REG_PLAYER_ID = INVALID_PLAYER_ID;
	
public OnFilterScriptInit()
{
	mysql_debug(1);
	new Connection = mysql_connect(SQL_HOST, SQL_USER,SQL_DB, SQL_PASS);
	if(Connection)
	{
		new dest[200];
		mysql_stat(dest);
		printf(dest);
	    printf(">> MySQL Register Script successfully initialized");
	    SetupTable();
	}
}

SetupTable()
{
	return mysql_query("CREATE TABLE IF NOT EXISTS `"TABLENAME"`(`id` int(11) NOT NULL auto_increment PRIMARY KEY,`Username` varchar(30) NOT NULL,`Password` varchar(50) NOT NULL,`Money` int(10) NOT NULL default '0')");
}

public OnQueryFinish(query[],resultid)
{
	new string[128],pName[MAX_PLAYER_NAME+1];
	switch(resultid)
	{
	    case CONNECT_THREAD_ID:
	    {
	        if(IsPlayerConnected(CONNECT_PLAYER_ID))
	        {
		        GetPlayerName(CONNECT_PLAYER_ID,pName,sizeof pName);
	    		mysql_store_result();
				if(mysql_num_rows() > 0)
				{
				    format(string,sizeof(string),">> This account (%s) is registered.Please login by using /login [pass]",pName);
				    SendClientMessage(CONNECT_PLAYER_ID,GREY,string);
				    AccRegistered[CONNECT_PLAYER_ID] = true;
				    pLogtimer[CONNECT_PLAYER_ID] = SetTimerEx("LoginKick",30000,0,"d",CONNECT_PLAYER_ID);
				}
				else
				{
				    format(string,sizeof(string),">> Welcome %s, you can register by using /register [pass]",pName);
				    SendClientMessage(CONNECT_PLAYER_ID,GREY,string);
				    AccRegistered[CONNECT_PLAYER_ID] = false;
				}
				mysql_free_result();
			}
			CONNECT_PLAYER_ID = INVALID_PLAYER_ID;
			return 0;
		}
		case REG_THREAD_ID:
		{
		    if(IsPlayerConnected(REG_PLAYER_ID))
		    {
		        GetPlayerName(REG_PLAYER_ID,pName,sizeof pName);
				format(string,sizeof(string),">> Account %s successfully registered - Remember your password for later use.",pName);
				SendClientMessage(REG_PLAYER_ID,GREY,string);
				SendClientMessage(REG_PLAYER_ID,GREY,"You have been automatically logged in");
				LoggedIn[REG_PLAYER_ID] = true;
				AccRegistered[REG_PLAYER_ID] = true;
			}
			REG_PLAYER_ID = INVALID_PLAYER_ID;
			return 0;
		}
		case LOGIN_THREAD_ID:
		{
		    if(IsPlayerConnected(LOGIN_PLAYER_ID))
			{
				mysql_store_result();
				if(mysql_num_rows() == 1)
				{
					PlayerMoney[LOGIN_PLAYER_ID] = mysql_fetch_int();
					GivePlayerMoney(LOGIN_PLAYER_ID,PlayerMoney[LOGIN_PLAYER_ID]);
					LoggedIn[LOGIN_PLAYER_ID] = true;
					format(string,sizeof(string),">> You have been successfully logged in. (Money: %d)",PlayerMoney[LOGIN_PLAYER_ID]);
					SendClientMessage(LOGIN_PLAYER_ID,GREY,string);
					mysql_free_result();
				}
				else
				{
				    Wrongattempt[LOGIN_PLAYER_ID] += 1;
				    printf("Bad log in attempt by %s (Total attempts: %d)",pName,Wrongattempt[LOGIN_PLAYER_ID]);
					if(Wrongattempt[LOGIN_PLAYER_ID] >= 3)
					{
					    SendClientMessage(LOGIN_PLAYER_ID,RED,">> You have been kicked.( 3 times wrong pass )");
			            mysql_free_result();
						return Kick(LOGIN_PLAYER_ID);
					}
					mysql_free_result();
					SendClientMessage(LOGIN_PLAYER_ID,RED,">> Wrong Password");
				}
			}
			LOGIN_PLAYER_ID = INVALID_PLAYER_ID;
			return 0;
		}
	}
	return 1;
}

public OnFilterScriptExit()
{
	print("MySQL Register / Login Script has been unloaded");
	if(mysql_ping()) mysql_close();
}

MySQLCheck()
{
	if(mysql_ping() == -1)
	{
		mysql_connect(SQL_HOST, SQL_USER,SQL_DB, SQL_PASS);
	}
	return 1;
}

RegisterAccount(playerid,pass[])
{
    MySQLCheck();
    new
		pName[MAX_PLAYER_NAME],
		query[256];
		
	GetPlayerName(playerid,pName,sizeof(pName));
	mysql_real_escape_string(pName,pName);
	mysql_real_escape_string(pass,pass);
	format(query,sizeof(query),"INSERT INTO `"TABLENAME"` (Username,Password) VALUES ('%s',md5('%s'))",pName,pass);
	mysql_query(query,REG_THREAD_ID);
	REG_PLAYER_ID = playerid;
	return 1;
}

LoginPlayer(playerid,pass[])
{
    new
		pName[MAX_PLAYER_NAME],
		query[256];

	GetPlayerName(playerid,pName,sizeof(pName));
	MySQLCheck();
	
	mysql_real_escape_string(pName,pName);
	mysql_real_escape_string(pass,pass);
	format(query,sizeof(query),"SELECT Money FROM `"TABLENAME"` WHERE Username = '%s' AND Password = md5('%s') LIMIT 1",pName,pass);
	mysql_query(query,LOGIN_THREAD_ID);
	LOGIN_PLAYER_ID = playerid;
	return 1;
}

public OnPlayerDisconnect(playerid,reason)
{
	if(pLogtimer[playerid] != 0) KillTimer(pLogtimer[playerid]);
	new
		query[300],
		pName[MAX_PLAYER_NAME];
		
	GetPlayerName(playerid,pName,sizeof(pName));
		
	if(LoggedIn[playerid])
	{
	    new Float:arm;
	    GetPlayerArmour(playerid,arm);
		format(query,sizeof(query),"UPDATE `"TABLENAME"` SET `Money`='%d' WHERE (`Username` = '%s')",GetPlayerMoney(playerid),pName);
		mysql_query(query);
	}
	return 1;
}

public OnPlayerConnect(playerid)
{
    new
		query[256],
		pname[MAX_PLAYER_NAME];
	Wrongattempt[playerid] = 0;
	LoggedIn[playerid] = false;
	TimerSet[playerid] = 0;
	
	GetPlayerName(playerid,pname,sizeof(pname));
	MySQLCheck();
	format(query,sizeof(query),"SELECT * FROM `"TABLENAME"` WHERE Username = '%s'",pname);
	mysql_query(query,CONNECT_THREAD_ID);
	CONNECT_PLAYER_ID = playerid;
	SetupTable();
	return 1;
}

forward LoginKick(playerid);
public LoginKick(playerid)
{
	if(!LoggedIn[playerid]) KickEx(playerid,"Not logged in");
	else
	{
	    KillTimer(pLogtimer[playerid]);
	    pLogtimer[playerid] = 0;
	}
	return 1;
}

public OnPlayerCommandText(playerid, cmdtext[])
{
	dcmd(register,8,cmdtext);
	dcmd(login,5,cmdtext);
	return 0;
}

dcmd_login(playerid, params[])
{
	if(LoggedIn[playerid])
	{
     	return SendClientMessage(playerid,RED,">> You are already logged in");
	}
	if(!AccRegistered[playerid])
	{
     	return SendClientMessage(playerid,RED,">> This Account is not registered. ( Use /register [pass] )");
	}
	if(!strlen(params))
	{
	    return SendClientMessage(playerid,RED,"SYNTAX: /login [password]");
	}
	LoginPlayer(playerid,params);
	return true;
}

dcmd_register(playerid, params[])
{
	new pName[MAX_PLAYER_NAME];
	GetPlayerName(playerid,pName,sizeof(pName));
	if(AccRegistered[playerid])
	{
	    return SendClientMessage(playerid,RED,">> This account is already registered. ( /login [pass] )");
	}
	if(LoggedIn[playerid])
	{
	    return SendClientMessage(playerid,RED,">> You are already logged in");
	}
	if(!strlen(params))
	{
	    return SendClientMessage(playerid,RED,"SYNTAX: /register [password]");
	}
	if(strlen(params) < 6)
	{
	    return SendClientMessage(playerid,RED,">> The password should contain 6 characters at least.");
	}
	RegisterAccount(playerid,params);
	return 1;
}

stock KickEx(playerid,reason[])
{
	new
		string[1000],
		MsgAll[128],
		pName[MAX_PLAYER_NAME];
	GetPlayerName(playerid,pName,sizeof(pName));
	format(string,sizeof(string),"You have been kicked: ");
	strcat(string,reason,sizeof(string));
	SendClientMessage(playerid,RED,string);
	Kick(playerid);
	format(MsgAll,sizeof(MsgAll),">> %s has been kicked.(Reason: %s)",pName,reason);
	SendClientMessageToAll(GREY,MsgAll);
	return 1;
}
