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
	fwrite(hFile, entry);
	fclose(hFile);
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
	fwrite(hFile, entry);
	fclose(hFile);
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
	fwrite(hFile, entry);
	fclose(hFile);
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
	fwrite(hFile, entry);
	fclose(hFile);
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
	fwrite(hFile, entry);
	fclose(hFile);
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
	fwrite(hFile, entry);
	fclose(hFile);
}

PlayerLocalLog(string[])
{
	new Year, Month, Day;
	getdate(Year, Month, Day);
	new Hour, Minute, Second;
	gettime(Hour, Minute, Second);
	new entry[256];
	format(entry, sizeof(entry), "[%d/%d/%d][%d:%d.%d] %s\r\n",Day,Month,Year,Hour,Minute,Second,string);
	new File:hFile;
	hFile = fopen("logs/playerlocal.log", io_append);
	fwrite(hFile, entry);
	fclose(hFile);
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
	fwrite(hFile, entry);
	fclose(hFile);
}

FactionChatLog(string[])
{
	new Year, Month, Day;
	getdate(Year, Month, Day);
	new Hour, Minute, Second;
	gettime(Hour, Minute, Second);
	new entry[256];
	format(entry, sizeof(entry), "[%d/%d/%d][%d:%d.%d] %s\r\n",Day,Month,Year,Hour,Minute,Second,string);
	new File:hFile;
	hFile = fopen("logs/factionchat.log", io_append);
	fwrite(hFile, entry);
	fclose(hFile);
}

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
	fwrite(hFile, entry);
	fclose(hFile);
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
	fwrite(hFile, entry);
	fclose(hFile);
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
	fwrite(hFile, entry);
	fclose(hFile);
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
	fwrite(hFile, entry);
	fclose(hFile);
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
	fwrite(hFile, entry);
	fclose(hFile);
}

ResetVehicleLog(string[])
{
	new Year, Month, Day;
	getdate(Year, Month, Day);
	new Hour, Minute, Second;
	gettime(Hour, Minute, Second);
	new entry[256];
	format(entry, sizeof(entry), "[%d/%d/%d][%d:%d.%d] %s\r\n",Day,Month,Year,Hour,Minute,Second,string);
	new File:hFile;
	hFile = fopen("logs/ResetVehicle.log", io_append);
	fwrite(hFile, entry);
	fclose(hFile);
}

DonatorLog(string[])
{
	new entry[256];
	format(entry, sizeof(entry), "%s\r\n",string);
	new File:hFile;
	hFile = fopen("logs/donator.log", io_append);
	fwrite(hFile, entry);
	fclose(hFile);
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
	fwrite(hFile, entry);
	fclose(hFile);
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
	fwrite(hFile, entry);
	fclose(hFile);
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
	fwrite(hFile, entry);
	fclose(hFile);
}
