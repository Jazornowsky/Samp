#include <a_samp>
#include <dini>
#include <wp_variables>

//Settings--------------------
#define COLOR 0x06BD12FF //the color of lottery text
#define LOTTERY_INTERVAL 60000 //interval of lottery being drawn; 1800000 = 30 minutes
#define JACKPOT_MULTIPLYER 2 //leave blank if you dont want it to multiply the jackpot ammount by the number you put in
new LOTTERY_PRICE=100; // the price of a ticket
new TICKETS_BUYABLE=2; //ammounts of lottery tickets one person can buy
new EnableAdminCommands=1; //0 = no, 1 = yes; allows rcon admins to be able to change settings ingame
new EnableLotteryText=1; //0 = no, 1 = yes; shows a textdraw on how much money is in the jackpot

//----------------------------


new Pool=0, Interval, People=0, Text: Textdraw99;

forward LotteryDraw();
forward IsPlayerNameOnline(name[]);
forward GetIDFromName(name[]);

public OnFilterScriptInit()
{
        print("-------------Advanced Lottery System-------------");
        dini_Create("lottery.ini");
        dini_IntSet("lottery.ini", "money", 0);
        Interval = SetTimer("Lottery", LOTTERY_INTERVAL, true);


        Textdraw99 = TextDrawCreate(498.000000, 9.000000, "~r~Lottery Jackpot:");
        TextDrawBackgroundColor( Textdraw99, 255);
        TextDrawFont(Textdraw99, 1);
        TextDrawLetterSize( Textdraw99, 0.240000, 1.000000);
        TextDrawColor( Textdraw99, -1);
        TextDrawSetOutline( Textdraw99, 0);
        TextDrawSetProportional( Textdraw99, 1);
        TextDrawSetShadow( Textdraw99, 1);
        TextDrawSetShadow( Textdraw99, 1);
        if(EnableLotteryText==1) TextDrawShowForAll( Textdraw99);
        return 1;
}

public OnFilterScriptExit()
{
        dini_Remove("lottery.ini");
        KillTimer(Interval);
        TextDrawDestroy( Textdraw99);
        return 1;
}

public LotteryDraw()
{
        new rand = random(People);
        new string[128];
        format(string, sizeof(string), "%d", rand);
        if(dini_Isset("lottery.ini", string))
        {
                if(IsPlayerNameOnline(dini_Get("lottery.info", string)))
                {
                    new cash = dini_Int("lottery.ini", "money");
                    #if JACKPOT_MULTIPLYER != 0
                    cash = cash * JACKPOT_MULTIPLYER;
                    #endif
                    new string2[128];
                    format(string2, sizeof(string2), "LOTTERY: [ID:%d]%s has won the lottery and gained %d ammount of cash!", GetIDFromName(dini_Get("lottery.info", string)), dini_Get("lottery.info", string), cash);
                    SendClientMessage(GetIDFromName(dini_Get("lottery.info", string)), COLOR, string2);
                    GivePlayerMoney(GetIDFromName(dini_Get("lottery.info", string)), Pool);
                dini_Remove("lottery.ini");
                        KillTimer(Interval);
                        dini_Create("lottery.ini");
                        dini_IntSet("lottery.ini", "money", 0);
                        Interval = SetTimer("Lottery", LOTTERY_INTERVAL, true);
                        Pool=0;
                        People=0;
                        if(EnableLotteryText==1)
                        {
                            new text[128];
                            format(text, sizeof(text), "~r~Lottery Jackpot: ~g~$%d", Pool);
                            TextDrawSetString( Textdraw99, text);
                            TextDrawHideForAll( Textdraw99);
                            TextDrawShowForAll( Textdraw99);
                        }
                        print("-------------Advanced Lottery System Restarted-------------");
                }
                else
                {
                    LotteryDraw();
                }
        }
        else
        {
            LotteryDraw();
        }
        return 1;
}

public IsPlayerNameOnline(name[])
{
        for(new i=0; i < MAX_PLAYERS; i++)
        {
                new PlayerName[MAX_PLAYER_NAME];
                GetPlayerName(i, PlayerName, sizeof(PlayerName));
            if(strcmp(PlayerName, name, true) == 0)
            {
                return true;
            }
            else
            {
                        return false;
                }
        }
        return true;
}

public GetIDFromName(name[])
{
        for(new i=0; i < MAX_PLAYERS; i++)
        {
                new PlayerName[MAX_PLAYER_NAME];
                GetPlayerName(i, PlayerName, sizeof(PlayerName));
            if(strcmp(PlayerName, name, true) == 0)
            {
                return i;
            }
            else
            {
                        return false;
                }
        }
        return true;
}


public OnPlayerCommandText(playerid, cmdtext[])
{
        if(strcmp("/buylottery", cmdtext, true, 15) == 0)
        {
                new PlayerName[MAX_PLAYER_NAME];
                GetPlayerName(playerid, PlayerName, sizeof(PlayerName));
            new Repeat;
            for(new i=0; i < People; i++)
            {
                        new string[128];
                        format(string, sizeof(string), "%d", i);
                if(strcmp(dini_Get("lottery.ini", string), PlayerName, true) == 0) Repeat++;//if(dini_Get("lottery.ini", i) == PlayerName) Repeat++; //use strcmp
                if(Repeat >= TICKETS_BUYABLE)
                {
                    SendClientMessage(playerid, COLOR, "LOTTERY: You have reached the maximum tickets purchaseable");
                    return 0;
                         }
                }
                if(GetPlayerMoney(playerid) >= LOTTERY_PRICE)
                {
                People++;
                        Pool+=LOTTERY_PRICE;
                        dini_IntSet("lottery.ini", "money", Pool);
                        GivePlayerMoney(playerid, -LOTTERY_PRICE);
                        new string[128];
                        format(string, sizeof(string), "%d", People);
                        dini_Set("lottery.ini", string, PlayerName);
                        if(EnableLotteryText==1)
                        {
                            new text[128];
                            format(text, sizeof(text), "~r~Lottery Jackpot: ~g~$%d", Pool);
                            TextDrawSetString( Textdraw99, text);
                            TextDrawHideForAll( Textdraw99);
                            TextDrawShowForAll( Textdraw99);
                        }
                }
                else
                {
                    new string[128];
                    format(string, sizeof(string), "LOTTERY: You cannot buy a lottery ticket because you dont have enough money! A ticket cost $%d.", LOTTERY_PRICE);
                    SendClientMessage(playerid, COLOR, string);
                    return 0;
                }
                return 1;
        }

        if(strcmp("/lottodraw", cmdtext, true, 15) == 0) //draws the lotto at the time he does the command
        {
            if(EnableAdminCommands==1)
            {
                        if (PlayerInfo[playerid][pAdmin] >= 20)
                    {
                                LotteryDraw();
                        }
                        else
                        {
                                SendClientMessage(playerid, COLOR, "LOTTERY: You are not allowed to use lottery admin commands!");
                        }
                }
                else
                {
                    SendClientMessage(playerid, COLOR, "LOTTERY: Lottery admin commands are not enabled!");
                }
                return 1;
        }

        if(strcmp("/lottoprice", cmdtext, true, 15) == 0)
        {
            if(EnableAdminCommands==1)
            {
                if (PlayerInfo[playerid][pAdmin] >= 20)
                {
                        new price;
                        if(sscanf(cmdtext, "d", price)) SendClientMessage(playerid, COLOR, "LOTTERY: You must enter a price for the ticket! USAGE: /lottoprice [ammount]");
                        else
                        {
                                        SendClientMessage(playerid, COLOR, "LOTTERY: The price of the lottery ticket has changed!");
                                        LOTTERY_PRICE=price;
                        }
                }
                else
                {
                    SendClientMessage(playerid, COLOR, "LOTTERY: You are not allowed to use lottery admin commands!");
                }
            }
            else
            {
                SendClientMessage(playerid, COLOR, "LOTTERY: Lottery admin commands are not enabled!");
            }
            return 1;
        }

        if(strcmp("/lottotickets", cmdtext, true, 15) == 0)
        {
            if(EnableAdminCommands==1)
            {
                if (PlayerInfo[playerid][pAdmin] >= 20)
                {
                        new tickets;
                        if(sscanf(cmdtext, "d", tickets)) SendClientMessage(playerid, COLOR, "LOTTERY: You must enter a price for the ticket! USAGE: /lottotickets [ammount]");
                        else
                        {
                                        SendClientMessage(playerid, COLOR, "LOTTERY: The ammount of the lottery tickets buyable has changed!");
                                        TICKETS_BUYABLE=tickets;
                        }
                }
                else
                {
                    SendClientMessage(playerid, COLOR, "LOTTERY: You are not allowed to use lottery admin commands!");
                }
            }
            else
            {
                SendClientMessage(playerid, COLOR, "LOTTERY: Lottery admin commands are not enabled!");
            }
            return 1;
        }

        if(strcmp("/lottotext", cmdtext, true, 15) == 0)
        {
           if(EnableAdminCommands==1)
            {
                if (PlayerInfo[playerid][pAdmin] >= 20)
                {
                                if(EnableLotteryText == 0)
                        {
                                        SendClientMessage(playerid, COLOR, "LOTTERY: The lottery text has been enabled!");
                                        new text[128];
                                format(text, sizeof(text), "~r~Lottery Jackpot: ~g~$%d", Pool);
                                TextDrawSetString( Textdraw99, text);
                                        TextDrawShowForAll( Textdraw99);
                                        EnableLotteryText=1;
                                }
                                if(EnableLotteryText == 1)
                        {
                                        SendClientMessage(playerid, COLOR, "LOTTERY: The lottery text has been disabled!");
                                        TextDrawHideForAll( Textdraw99);
                                        EnableLotteryText=0;
                                }
                }
                else
                {
                    SendClientMessage(playerid, COLOR, "LOTTERY: You are not allowed to use lottery admin commands!");
                }
            }
            else
            {
                SendClientMessage(playerid, COLOR, "LOTTERY: Lottery admin commands are not enabled!");
            }
            return 1;
        }
        return 0;
}

stock sscanf(string[], format[], {Float,_}:...)
{
        #if defined isnull
                if (isnull(string))
        #else
                if (string[0] == 0 || (string[0] == 1 && string[1] == 0))
        #endif
                {
                        return format[0];
                }
        #pragma tabsize 4
        new
                formatPos = 0,
                stringPos = 0,
                paramPos = 2,
                paramCount = numargs(),
                delim = ' ';
        while (string[stringPos] && string[stringPos] <= ' ')
        {
                stringPos++;
        }
        while (paramPos < paramCount && string[stringPos])
        {
                switch (format[formatPos++])
                {
                        case '\0':
                        {
                                return 0;
                        }
                        case 'i', 'd':
                        {
                                new
                                        neg = 1,
                                        num = 0,
                                        ch = string[stringPos];
                                if (ch == '-')
                                {
                                        neg = -1;
                                        ch = string[++stringPos];
                                }
                                do
                                {
                                        stringPos++;
                                        if ('0' <= ch <= '9')
                                        {
                                                num = (num * 10) + (ch - '0');
                                        }
                                        else
                                        {
                                                return -1;
                                        }
                                }
                                while ((ch = string[stringPos]) > ' ' && ch != delim);
                                setarg(paramPos, 0, num * neg);
                        }
                        case 'h', 'x':
                        {
                                new
                                        num = 0,
                                        ch = string[stringPos];
                                do
                                {
                                        stringPos++;
                                        switch (ch)
                                        {
                                                case 'x', 'X':
                                                {
                                                        num = 0;
                                                        continue;
                                                }
                                                case '0' .. '9':
                                                {
                                                        num = (num << 4) | (ch - '0');
                                                }
                                                case 'a' .. 'f':
                                                {
                                                        num = (num << 4) | (ch - ('a' - 10));
                                                }
                                                case 'A' .. 'F':
                                                {
                                                        num = (num << 4) | (ch - ('A' - 10));
                                                }
                                                default:
                                                {
                                                        return -1;
                                                }
                                        }
                                }
                                while ((ch = string[stringPos]) > ' ' && ch != delim);
                                setarg(paramPos, 0, num);
                        }
                        case 'c':
                        {
                                setarg(paramPos, 0, string[stringPos++]);
                        }
                        case 'f':
                        {

                                new changestr[16], changepos = 0, strpos = stringPos;
                                while(changepos < 16 && string[strpos] && string[strpos] != delim)
                                {
                                        changestr[changepos++] = string[strpos++];
                                }
                                changestr[changepos] = '\0';
                                setarg(paramPos,0,_:floatstr(changestr));
                        }
                        case 'p':
                        {
                                delim = format[formatPos++];
                                continue;
                        }
                        case '\'':
                        {
                                new
                                        end = formatPos - 1,
                                        ch;
                                while ((ch = format[++end]) && ch != '\'') {}
                                if (!ch)
                                {
                                        return -1;
                                }
                                format[end] = '\0';
                                if ((ch = strfind(string, format[formatPos], false, stringPos)) == -1)
                                {
                                        if (format[end + 1])
                                        {
                                                return -1;
                                        }
                                        return 0;
                                }
                                format[end] = '\'';
                                stringPos = ch + (end - formatPos);
                                formatPos = end + 1;
                        }
                        case 'u':
                        {
                                new
                                        end = stringPos - 1,
                                        id = 0,
                                        bool:num = true,
                                        ch;
                                while ((ch = string[++end]) && ch != delim)
                                {
                                        if (num)
                                        {
                                                if ('0' <= ch <= '9')
                                                {
                                                        id = (id * 10) + (ch - '0');
                                                }
                                                else
                                                {
                                                        num = false;
                                                }
                                        }
                                }
                                if (num && IsPlayerConnected(id))
                                {
                                        setarg(paramPos, 0, id);
                                }
                                else
                                {
                                        #if !defined foreach
                                                #define foreach(%1,%2) for (new %2 = 0; %2 < MAX_PLAYERS; %2++) if (IsPlayerConnected(%2))
                                                #define __SSCANF_FOREACH__
                                        #endif
                                        string[end] = '\0';
                                        num = false;
                                        new
                                                name[MAX_PLAYER_NAME];
                                        id = end - stringPos;
                                        foreach (Player, playerid)
                                        {
                                                GetPlayerName(playerid, name, sizeof (name));
                                                if (!strcmp(name, string[stringPos], true, id))
                                                {
                                                        setarg(paramPos, 0, playerid);
                                                        num = true;
                                                        break;
                                                }
                                        }
                                        if (!num)
                                        {
                                                setarg(paramPos, 0, INVALID_PLAYER_ID);
                                        }
                                        string[end] = ch;
                                        #if defined __SSCANF_FOREACH__
                                                #undef foreach
                                                #undef __SSCANF_FOREACH__
                                        #endif
                                }
                                stringPos = end;
                        }
                        case 's', 'z':
                        {
                                new
                                        i = 0,
                                        ch;
                                if (format[formatPos])
                                {
                                        while ((ch = string[stringPos++]) && ch != delim)
                                        {
                                                setarg(paramPos, i++, ch);
                                        }
                                        if (!i)
                                        {
                                                return -1;
                                        }
                                }
                                else
                                {
                                        while ((ch = string[stringPos++]))
                                        {
                                                setarg(paramPos, i++, ch);
                                        }
                                }
                                stringPos--;
                                setarg(paramPos, i, '\0');
                        }
                        default:
                        {
                                continue;
                        }
                }
                while (string[stringPos] && string[stringPos] != delim && string[stringPos] > ' ')
                {
                        stringPos++;
                }
                while (string[stringPos] && (string[stringPos] == delim || string[stringPos] <= ' '))
                {
                        stringPos++;
                }
                paramPos++;
        }
        do
        {
                if ((delim = format[formatPos++]) > ' ')
                {
                        if (delim == '\'')
                        {
                                while ((delim = format[formatPos++]) && delim != '\'') {}
                        }
                        else if (delim != 'z')
                        {
                                return delim;
                        }
                }
        }
        while (delim > ' ');
        return 0;
}
