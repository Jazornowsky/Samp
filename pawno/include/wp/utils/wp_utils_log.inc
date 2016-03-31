/***
*
* File: wp_utils_log.inc
* Auth: Damian Wojdat
* Date: 19.11.2011
* Desc: Internal script function related to logs.
*
*************************************************************************************************************/

PayLog(string[])
{
	new Year, Month, Day;
	getdate(Year, Month, Day);
	new Hour, Minute, Second;
	gettime(Hour, Minute, Second);
	new entry[256];
	format(entry, sizeof(entry), "[%d/%d/%d][%d:%d.%d] %s\r\n",Day,Month,Year,Hour,Minute,Second,string);
	new File:hFile;
	hFile = fopen("logs/pay.log", io_append);
	if(hFile)
	{
		fwrite(hFile, entry);
		fclose(hFile);
	}
	else
		ErrorLog("[ERROR:] Can't save pay.log");
}

ErrorLog(string[])
{
	new Year, Month, Day;
	getdate(Year, Month, Day);
	new Hour, Minute, Second;
	gettime(Hour, Minute, Second);
	new entry[256];
	format(entry, sizeof(entry), "[%d/%d/%d][%d:%d.%d] %s\r\n",Day,Month,Year,Hour,Minute,Second,string);
	new File:hFile;
	hFile = fopen("logs/error.log", io_append);
	if(hFile)
	{
		fwrite(hFile, entry);
		fclose(hFile);
	}
	else	
		print("[ERROR:] Can't save error.log");
}

HackLog(string[])
{
	new Year, Month, Day;
	getdate(Year, Month, Day);
	new Hour, Minute, Second;
	gettime(Hour, Minute, Second);
	new entry[256];
	format(entry, sizeof(entry), "[%d/%d/%d][%d:%d.%d] %s\r\n",Day,Month,Year,Hour,Minute,Second,string);
	new File:hFile;
	hFile = fopen("logs/hack.log", io_append);
	if(hFile)
	{
		fwrite(hFile, entry);
		fclose(hFile);
	}
	else
		ErrorLog("[ERROR:] Can't save hack.log");
}

KickLog(string[])
{
	new Year, Month, Day;
	getdate(Year, Month, Day);
	new Hour, Minute, Second;
	gettime(Hour, Minute, Second);
	new entry[256];
	format(entry, sizeof(entry), "[%d/%d/%d][%d:%d.%d] %s\r\n",Day,Month,Year,Hour,Minute,Second,string);
	new File:hFile;
	hFile = fopen("logs/kick.log", io_append);
	if(hFile)
	{
		fwrite(hFile, entry);
		fclose(hFile);
	}
	else
		ErrorLog("[ERROR:] Can't save kick.log");
}

AccountBanLog(string[])
{
	new Year, Month, Day;
	getdate(Year, Month, Day);
	new Hour, Minute, Second;
	gettime(Hour, Minute, Second);
	new entry[256];
	format(entry, sizeof(entry), "[%d/%d/%d][%d:%d.%d] %s\r\n",Day,Month,Year,Hour,Minute,Second,string);
	new File:hFile;
	hFile = fopen("logs/accountban.log", io_append);
	if(hFile)
	{
		fwrite(hFile, entry);
		fclose(hFile);
	}
	else
		ErrorLog("[ERROR:] Can't save accountban.log");
}

BanLog(string[])
{
	new Year, Month, Day;
	getdate(Year, Month, Day);
	new Hour, Minute, Second;
	gettime(Hour, Minute, Second);
	new entry[256];
	format(entry, sizeof(entry), "[%d/%d/%d][%d:%d.%d] %s\r\n",Day,Month,Year,Hour,Minute,Second,string);
	new File:hFile;
	hFile = fopen("logs/ban.log", io_append);
	if(hFile)
	{
		fwrite(hFile, entry);
		fclose(hFile);
	}
	else
		ErrorLog("[ERROR:] Can't save ban.log");
}

PlayerActionLog(string[])
{
	new Year, Month, Day;
	getdate(Year, Month, Day);
	new Hour, Minute, Second;
	gettime(Hour, Minute, Second);
	new entry[256];
	format(entry, sizeof(entry), "[%d/%d/%d][%d:%d.%d] %s\r\n",Day,Month,Year,Hour,Minute,Second,string);
	new File:hFile;
	hFile = fopen("logs/playeraction.log", io_append);
	if(hFile)
	{
		fwrite(hFile, entry);
		fclose(hFile);
	}
	else
		ErrorLog("[ERROR:] Can't save playeraction.log");
}

TalkLog(string[])
{
	new Year, Month, Day;
	getdate(Year, Month, Day);
	new Hour, Minute, Second;
	gettime(Hour, Minute, Second);
	new entry[256];
	format(entry, sizeof(entry), "[%d/%d/%d][%d:%d.%d] %s\r\n",Day,Month,Year,Hour,Minute,Second,string);
	new File:hFile;
	hFile = fopen("logs/talk.log", io_append);
	if(hFile)
	{
		fwrite(hFile, entry);
		fclose(hFile);
	}
	else
		ErrorLog("[ERROR:] Can't save talk.log");
}

// FactionChatLog(string[])
// {
	// new Year, Month, Day;
	// getdate(Year, Month, Day);
	// new Hour, Minute, Second;
	// gettime(Hour, Minute, Second);
	// new entry[256];
	// format(entry, sizeof(entry), "[%d/%d/%d][%d:%d.%d] %s\r\n",Day,Month,Year,Hour,Minute,Second,string);
	// new File:hFile;
	// hFile = fopen("logs/factionchat.log", io_append);
	// fwrite(hFile, entry);
	// fclose(hFile);
// }

SMSLog(string[])
{
	new Year, Month, Day;
	getdate(Year, Month, Day);
	new Hour, Minute, Second;
	gettime(Hour, Minute, Second);
	new entry[256];
	format(entry, sizeof(entry), "[%d/%d/%d][%d:%d.%d] %s\r\n",Day,Month,Year,Hour,Minute,Second,string);
	new File:hFile;
	hFile = fopen("logs/sms.log", io_append);
	if(hFile)
	{
		fwrite(hFile, entry);
		fclose(hFile);
	}
	else
		ErrorLog("[ERROR:] Can't save sms.log");
}

PMLog(string[])
{
	new Year, Month, Day;
	getdate(Year, Month, Day);
	new Hour, Minute, Second;
	gettime(Hour, Minute, Second);
	new entry[256];
	format(entry, sizeof(entry), "[%d/%d/%d][%d:%d.%d] %s\r\n",Day,Month,Year,Hour,Minute,Second,string);
	new File:hFile;
	hFile = fopen("logs/pm.log", io_append);
	if(hFile)
	{
		fwrite(hFile, entry);
		fclose(hFile);
	}
	else
		ErrorLog("[ERROR:] Can't save pm.log");
}

DutyLog(string[])
{
	new Year, Month, Day;
	getdate(Year, Month, Day);
	new Hour, Minute, Second;
	gettime(Hour, Minute, Second);
	new entry[256];
	format(entry, sizeof(entry), "[%d/%d/%d][%d:%d.%d] %s\r\n",Day,Month,Year,Hour,Minute,Second,string);
	new File:hFile;
	hFile = fopen("logs/duty.log", io_append);
	if(hFile)
	{
		fwrite(hFile, entry);
		fclose(hFile);
	}
	else
		ErrorLog("[ERROR:] Can't save duty.log");
}

WFactoryLog(string[])
{
	new Year, Month, Day;
	getdate(Year, Month, Day);
	new Hour, Minute, Second;
	gettime(Hour, Minute, Second);
	new entry[256];
	format(entry, sizeof(entry), "[%d/%d/%d][%d:%d.%d] %s\r\n",Day,Month,Year,Hour,Minute,Second,string);
	new File:hFile;
	hFile = fopen("logs/wfactory.log", io_append);
	if(hFile)
	{
		fwrite(hFile, entry);
		fclose(hFile);
	}	
	else
		ErrorLog("[ERROR:] Can't save wfactory.log");
}

OOCLog(string[])
{
	new Year, Month, Day;
	getdate(Year, Month, Day);
	new Hour, Minute, Second;
	gettime(Hour, Minute, Second);
	new entry[256];
	format(entry, sizeof(entry), "[%d/%d/%d][%d:%d.%d] %s\r\n",Day,Month,Year,Hour,Minute,Second,string);
	new File:hFile;
	hFile = fopen("logs/ooc.log", io_append);
	if(hFile)
	{
		fwrite(hFile, entry);
		fclose(hFile);
	}
	else
		ErrorLog("[ERROR:] Can't save ooc.log");
}

VehicleLog(string[])
{
	new Year, Month, Day;
	getdate(Year, Month, Day);
	new Hour, Minute, Second;
	gettime(Hour, Minute, Second);
	new entry[256];
	format(entry, sizeof(entry), "[%d/%d/%d][%d:%d.%d] %s\r\n",Day,Month,Year,Hour,Minute,Second,string);
	new File:hFile;
	hFile = fopen("logs/vehicle.log", io_append);
	if(hFile)
	{
		fwrite(hFile, entry);
		fclose(hFile);
	}
	else
		ErrorLog("[ERROR:] Can't save vehicle.log");
}

DonatorLog(string[])
{
	new entry[256];
	format(entry, sizeof(entry), "%s\r\n",string);
	new File:hFile;
	hFile = fopen("logs/donator.log", io_append);
	if(hFile)
	{
		fwrite(hFile, entry);
		fclose(hFile);
	}
	else
		ErrorLog("[ERROR:] Can't save donator.log");
}

StateChangeLog(string[])
{
	new Year, Month, Day;
	getdate(Year, Month, Day);
	new Hour, Minute, Second;
	gettime(Hour, Minute, Second);
	new entry[256];
	format(entry, sizeof(entry), "[%d/%d/%d][%d:%d.%d] %s\r\n",Day,Month,Year,Hour,Minute,Second,string);
	new File:hFile;
	hFile = fopen("logs/statechange.log", io_append);
	if(hFile)
	{
		fwrite(hFile, entry);
		fclose(hFile);
	}
	else
		ErrorLog("[ERROR:] Can't save statechange.log");
}

GovermentLog(string[])
{
	new Year, Month, Day;
	getdate(Year, Month, Day);
	new Hour, Minute, Second;
	gettime(Hour, Minute, Second);
	new entry[256];
	format(entry, sizeof(entry), "[%d/%d/%d][%d:%d.%d] %s\r\n",Day,Month,Year,Hour,Minute,Second,string);
	new File:hFile;
	hFile = fopen("logs/urzednicy.log", io_append);
	if(hFile)
	{
		fwrite(hFile, entry);
		fclose(hFile);
	}
	else
		ErrorLog("[ERROR:] Can't save governmentlog.log");
}

PayDayLog(string[])
{
	new Year, Month, Day;
	getdate(Year, Month, Day);
	new Hour, Minute, Second;
	gettime(Hour, Minute, Second);
	new entry[256];
	format(entry, sizeof(entry), "[%d/%d/%d][%d:%d.%d] %s\r\n",Day,Month,Year,Hour,Minute,Second,string);
	new File:hFile;
	hFile = fopen("logs/payday.log", io_append);
	if(hFile)
	{
		fwrite(hFile, entry);
		fclose(hFile);
	}
	else
		ErrorLog("[ERROR:] Can't save payday.log");
}

ExportVehLog(string[])
{
	new Year, Month, Day;
	getdate(Year, Month, Day);
	new Hour, Minute, Second;
	gettime(Hour, Minute, Second);
	new entry[256];
	format(entry, sizeof(entry), "[%d/%d/%d][%d:%d.%d] %s\r\n",Day,Month,Year,Hour,Minute,Second,string);
	new File:hFile;
	hFile = fopen("logs/export.log", io_append);
	if(hFile)
	{
		fwrite(hFile, entry);
		fclose(hFile);
	}
	else
		ErrorLog("[ERROR:] Can't save export.log");
}

LogginDataLog(string[])
{
	new Year, Month, Day;
	getdate(Year, Month, Day);
	new Hour, Minute, Second;
	gettime(Hour, Minute, Second);
	new entry[256];
	format(entry, sizeof(entry), "[%d/%d/%d][%d:%d.%d] %s\r\n",Day,Month,Year,Hour,Minute,Second,string);
	new File:hFile;
	hFile = fopen("logs/loggindata.log", io_append);
	if(hFile)
	{
		fwrite(hFile, entry);
		fclose(hFile);
	}
	else
		ErrorLog("[ERROR:] Can't save loggindata.log");
}
