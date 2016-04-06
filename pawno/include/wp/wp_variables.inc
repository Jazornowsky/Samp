/***
*
* File: wp_variables.inc
* Auth: Damian Wojdat
* Date: 15.09.2011
* Desc: Declarations, macros and variables.
*
*************************************************************************************************************/

#if defined _WP_VARIABLES
	#endinput
#endif
#define _WP_VARIABLES

#define DEBUG
#define DEBUG2

#define CUSTOM_MAX_PLAYERS 100						// Manualy set server slot amout for functions, variables, etc.

#include <wp\variables\wp_vars_mysql>
#include <wp\variables\wp_vars_zones>
#include <wp\variables\wp_vars_skins>
#include <wp\variables\wp_vars_objects>
#include <wp\variables\wp_vars_jobs>
#include <wp\variables\wp_vars_veh_lenghts>
#include <wp\variables\wp_vars_gates>
#include <wp\variables\wp_vars_weed>
#include <wp\variables\wp_vars_event1>
#include <wp\variables\wp_vars_veh_names>
#include <wp\variables\wp_vars_event_pickups>


native WP_Hash(buffer[], len, const str[]);

/* Declarations */

forward main();
OnQueryFinish(resultid, extraid, connectionHandle);
wp_mysql_query(query[], resultid = -1, extraid = -1, connectionHandle = 1);
LoadDynamicCarSpawns();
SaveDynamicCarSpawns();
LoadDynamicPlanesSpawns();
SaveDynamicPlanesSpawns();
LoadDynamicBoatsSpawns();
SaveDynamicBoatsSpawns();
ImportVeh(BizKey, modelID, PlayerName[], fueltype, Float:maxHealth);
LoadDynamicTaxes();
SaveDynamicTaxes();
SaveTaxiJob();
LoadTaxiJob();
PlayMusic(playerid);
busCheckpoints(i);
playerNextLvlBusPoints(playerid);
LoadMzgkJobCheckpointA();
LoadMzgkJobCheckpointB();
LoadSweeperJobCheckpointA();
LoadSweeperJobCheckpointB();
LoadMzgkJob();
SaveMzgkJob();
LoadSweeperJob();
SaveSweeperJob();
LoadBusJob();
SaveBusJob();
LoadFarmerJob();
SaveFarmerJob();
LoadFarmerJobCheckpointA();
LoadFarmerJobCheckpointB();
LoadFarmerJobCheckpointC();
LoadMechanicJob();
SaveMechanicJob();
LoadMechanicJob1();
LoadMechanicJob2();
SaveMechanicJob2();
LoadDynamicZones();
LoadHouses(hsource);
NewbieOff(color,const string[]); // WTF ?
SendJobMessage(job, color, string[]); // WTF ?
SafeResetPlayerWeapons(plyid); // WTF ?
SafeGivePlayerGun(plyid, weaponid, ammo); // WTF ?
RemovePlayerWeapon(playerid, weaponid); 
OnPlayerLogin(playerid,password[]);
SendFactionMessage(faction, color, string[]);
SendFactionTypeMessage(factiontype, color, string[]);
SetPlayerToFactionSkin(playerid);
ProxDetector(Float:radi, playerid, string[],col1,col2,col3,col4,col5);
ResetStats(playerid);
LoadDynamicCars();
LoadDynamicFactions();
SaveDynamicFactions();
LoadCivilianSpawn();
SaveCivilianSpawn();
LoadBuildings();
ShowStats(playerid,targetid);
BanPlayer(playerid,bannedby[MAX_PLAYER_NAME],reason[]);
BanPlayerAccount(playerid,bannedby[MAX_PLAYER_NAME],reason[]);
KickPlayer(playerid,kickedby[MAX_PLAYER_NAME],reason[]);
BanLog(string[]);
AccountBanLog(string[]);
KickLog(string[]);
PayLog(string[]);
HackLog(string[]);
PlayerActionLog(string[]);
TalkLog(string[]);
// FactionChatLog(string[]);
SMSLog(string[]);
PMLog(string[]);
VehicleLog(string[]);
DonatorLog(string[]);
OOCLog(string[]);
PayDayLog(string[]);
SendAdminMessage(color, string[]);
SendModMessage(color, string[]);
ABroadCast(color,const string[],level);
BroadCast(color,const string[]);
GovermentLog(string[]);
StateChangeLog(string[]);
PlayerActionMessage(playerid,Float:radius,message[]);
PlayerPlayerActionMessage(playerid,targetid,Float:radius,message[]);
LoadBusinesses();
SaveBusinesses();
LoadDrivingTestPosition();
SaveDrivingTestPosition();
LoadSkillPosition();
SaveSkillPosition();
LoadSkillPositiond();
SaveSkillPositiond();
LoadSkillPositione();
SaveSkillPositione();
LoadSkillPositionb();
SaveSkillPositionb();
LoadSkillPositionc();
SaveSkillPositionc();
LoadPlaneTestPosition();
SavePlaneTestPosition();
LoadBoatTestPosition();
SaveBoatTestPosition();
LoadPoliceComputerPassword();
SavePoliceComputerPassword();
LoadGunJob();
SaveGunJob();
LoadDrugJob();
SaveDrugJob();
public AddsOn();
LoadWeaponLicensePosition();
SaveWeaponLicensePosition();
PhoneAnimation(playerid);
SetPlayerWantedLevelEx(playerid,level);
ResetPlayerWantedLevelEx(playerid);
IsAtBar(playerid);
UndrugEffect(playerid);
LoadDetectiveJob();
SaveDetectiveJob();
LoadLawyerJob();
SaveLawyerJob();
LoadProductsSellerJob();
SaveProductsSellerJob();
LoadCarjackJob();
SaveCarjackJob();
LoadWhoreJob();
SaveWhoreJob();
LoadBodyJob();
SaveBodyJob();
LoadStuntJob();
SaveStuntJob();
LoadBoxerJob();
SaveBoxerJob();
LoadRapistJob();
SaveRapistJob();
LoadDirJob();
SaveDirJob();
LoadScript();
LoadRafinery();
SaveRafinery();
LoadWFactoryLegal();
public RefuelingVehicle(playerid, vehicleid, Float:refillvalue, gasStationID, Float:pPosX, Float:pPosY, Float:pPosZ);
public RefuelingVehicle(playerid, vehicleid, Float:refillvalue, gasStationID, Float:pPosX, Float:pPosY, Float:pPosZ);
public FuelTankerPetrol(playerid, Float:tankerX, Float:tankerY, Float:tankerZ);
public FuelTankerOil(playerid, Float:tankerX, Float:tankerY, Float:tankerZ);
public FuelTankerGas(playerid, Float:tankerX, Float:tankerY, Float:tankerZ);
public FuelTankerFly(playerid, Float:tankerX, Float:tankerY, Float:tankerZ);
public DrainTankerFuel(playerid, Float:tankerX, Float:tankerY, Float:tankerZ);
public RefuelVehicleFly(playerid, Float:refillvalue, Float:pPosX, Float:pPosY, Float:pPosZ, truckId, tlId, planeId);
LoadGasStations();
SaveGasStations();
LoadPayRank();
SavePayRank();
SavePlayerData(playerid, column[], otherid = -1);
UpdatePlayerDataByName(name[], column[], newvalue = 0);
SaveVehData(carid, column[], otherid = -1);
LoadVariables();
VehFTank(vehID);
ASpeed(vehicleID);
SaveBizData(bizid, column[]);
SaveHouseData(houseid, column[]);
SaveFData(fid, column[]);
LoadSellerJob();
SaveSellerJob();
LoadAccountantJob();
SaveAccountantJob();
LoadNewsBoyJob();
SaveNewsBoyJob();
SaveFuleStationData(gasid, column[]);
public RefuelingVehicleCanister(playerid, vehicleid, Float:xpos, Float:ypos, Float:zpos);
public RefuelingCanister(playerid, Float:refillvalue, slot, gasStationID, Float:xpos, Float:ypos, Float:zpos);
public SetRadioAudioPos(playerid, handleid);
IsPlayerInWFCP(playerid);
public TogglePlayerUnControllable( playerid, Float:x, Float:y, Float:z );
LoadCustomObjects();
SaveBusTrack(slot, column[], cp=-1);
SaveTrashTrack(slot, column[], cp=-1);
LoadBusTracks();
LoadTrashTracks();
LoadSweeperTracks();
LoadFarmerTracks();
CreateCustomObject( playerid, model, Float:objX, Float:objY, Float:objZ, Float:rX = 0.0, Float:rY = 0.0, Float:rZ = 0.0 );
RemoveCustomObject( objectID );
MoveCustomObject( objectID, Float:mx, Float:my, Float:mz );
Float:GetXYInFrontOfPlayer(playerid, &Float:x, &Float:y, Float:distance);
Float:VehBatDegradation(itemid);
Float:MaxVehicleHealth(vehId);

/* Default data */
#define VERSION "1.33"										
#define MAX_ZONE_NAME 28
#define MAX_SPAWN_ATTEMPTS 4						// This is the amount of times sometime can try to spawn before finally getting kicked.
#define SMS_COST 15									// Price used in phone sms
#define PHONE_COST 2								// Price used for 1 minute call
#define PRODUCT_PRICE 10							// Price used to buy products by product seller
#define PARTS_PRICE	500								// Price used to buy parts by mechanic
#define REPAIR_TIME_MULTIPLIER 1
#define MAX_PING	600								// Values over MAX_PING are treated as high ping and are couted in every function pass
#define MAX_PING_HIT_LIMIT 5						// Number represents timer (function) pass befor player gets kicked out for high ping
#define IDLE_TIME 300000							// Timer after player gets kicked out for AFK
#define BUS_PENALTY_COST 2000						// Penalty payed by player for reckles driving bus
#define ENGINE_STARTUP_TIME 1500					// Time after engine starts
#define ENGINE_STARTUP_TIME_FAST 100				// Time after engine starts fast (ex. for admin)
#define ENGINE_INFO_TIME 3000						// Time after message can be repeated
#define ENGINE_NO_KEY_TIME 5000						// Time after next engine startup can be done without key
#define FUEL_TANKER_STEP 100						// Default time after 1ltr of fuel is fueled
#define JOB_BUS_TXT_SHOW_TIME 1000					// How long departure message must be shown
#define GAME_TEXT_DEFAULT_TIME 2000					// How long game text will be showed
#define WFACTORY_DESTROY_TIME 60000					// Default time after factory gets burned out
#define WFACTORY_COST 15000							// Default cost of factory build
#define WFACTORY_DES_REW_OFFICER 100				// Default reward value for police officer for destroying factory
#define WFACTORY_DES_REW_FACTION 2000				// Default reward value for police faction for destroying factory
#define FUEL_REFUEL_STEP 2.5 						// How much fuel is refueled after 1 second
#define FUEL_REFUEL_STEP_CNSTR 1.0					// How much fuel is refueled to canister after 1 second
#define MAX_BUILDINGS 200							// How many buildings are setup in array
#define MAX_MAP_ICONS 50							// How many map icons are setup in array
#define MAX_PICKUP_INFOS 50							// How many pickups are setup in array
#define MAX_PUBLIC_ADS 50							// How many public ads are setup in array
#define MAX_REPAIR_POINTS 10						// How many repair points are setup in array
#define MAX_WHEEL_POINTS 8							// How many wheel change points are setup in array
#define MAX_BUSINESSES 1000							// How many businesses are setup in array
#define MAX_HOUSES 1500								// How many houses are setup in array
#define ICONS_BASIC 1								// Which icons should be showed for player
#define ICONS_ADVANCED 2							// Which icons should be showed for player
#define FACTORY_L_REWARD 20							// How much pay for one part/weapon/ammo
#define WARN_COOLDOWN 7								// Payday counts before warn gone
#define BIZ_CPN_ID 19 								// Last ID of CPN biz
#define RESERVED_HOUSES 300							// Houses than can't be moved by government
#define ADVERT_TIMER 60000							// Time after player can again post next advert using /ogloszenie
#define GasMax 100									// Default value of vehicle tanker
#define Speedgun 22 								// The ID of weapon used as speedgun
#define DRIVING_LICENCE_COST 40 					// Cost of making driving licence in government
#define PICKUP_LIFE_TIME 30 						// How long pickup exists ? multiple to 10 min
#define MAX_PLAYER_ITEM_SLOT 25						// How many item slots player could have
#define MAX_VEHICLE_ITEM_SLOT 15					// How many item slots vehicle could have
#define MAX_HOUSE_ITEM_SLOT 15						// How many item slots house could have
#define MAX_PENALTY_POINTS 24						// Max player penalty points for licence
#define PENALTY_POINTS_DECRESE 6					// How many points to reduce after test
#define SHOP_CP_COUNT 75							// How many shops with CP
#define SHOP_CLOTHE_CP_COUNT 64						// How many shops with CP
#define PHONET_FEE 0								// Phone on fee
#define PHONET_CARD 1								// Phone on prepaid
#define DRIVING_INSTRUCTOR_REWARD 40				// how much instructor will receive for examiantion
#define HOUSE_BREAK_COOLDOWN 72						// how much time faction must wait before next house robbery
#define BIZ_BREAK_COOLDOWN 72						// how much time faction must wait before next biz robbery
#define CHAR_STEAL_COOLDOWN 72						// how much time faction must wait before next char robbery
#define BUSINESS_TYPES "1: Restaurant - 2: Phone - 3: 24-7 - 4: Ammunation - 5: Advertising - 6: Clothes Store - 7. Bar/Club"
#define BUSINESS_TYPES2 "8: Record Company - 9: Studio - 10: Salon"
#define BUS_TICKET_VIP_DISCOUNT 0.20
#define HIGH_SCHOOL_POINTS 20 						// how many points player must have to achive high school
#define MAX_GRADE_LVL 4								// how many points player must have to achive high school
#define SCHOOL_COST 25
#define HIGH_SCHOOL_COST 500
#define SCHOOL_COOLDOWN 20
#define EVENT_COUNT 1

#define MAX_RACES	50															// How many races are avaible
#define MAX_RACES_CP	150													// How many races cp are avaible
#define DEFAULT_TIME_BEFORE_RACE_START 600			// Time in seconds
#define DEFAULT_TIME_BEFORE_RACE_END 60				// Time in seconds

/* Character needs */
#define ENERGY					0.4
#define MAX_ENERGY			100.0
#define MAX_ENERGY_VIP	150.0
#define HUNGER					1.0
#define MAX_HUNGER			100.0
#define MAX_HUNGER_VIP	150.0
#define THIRST						1.7
#define MAX_THIRST				100.0
#define MAX_THIRST_VIP		150.0
#define POISON					0.2
#define MAX_POISON			100.0
#define MAX_POISON_VIP		150.0
#define FAT							0.3
#define MAX_FAT					100.0
#define MAX_FAT_VIP			150.0
#define STOMACH					1.5
#define MAX_STOMACH		100.0
#define MAX_STOMACH_VIP	150.0
#define VITAMINS					1.0
#define MAX_VITAMINS			100.0
#define MAX_VITAMINS_VIP	150.0
#define DRUNK						2.0
#define MAX_DRUNK				100.0
#define MAX_DRUNK_VIP		100.0
#define NARCOTIC				0.3
#define MAX_NARCOTIC		100.0
#define MAX_NARCOTIC_VIP	150.0
#define MAX_SUBMEALS 		30 												// How many submeals player can have before stomach probles starts
#define MAX_SUBMEALS_HP_LOSS 20.0					// How much hp vomiting will take

/* Weapons skill costs */
#define PIS_SKILL_COST 1000
#define SIL_SKILL_COST 1000
#define DES_SKILL_COST 2000
#define SHO_SKILL_COST 2000
#define SHA_SKILL_COST 2000
#define SPASS_SKILL_COST 3000
#define UZI_SKILL_COST 2000
#define MP5_SKILL_COST 4000
#define AK_SKILL_COST 5000
#define M4_SKILL_COST 5000
#define SNIPER_SKILL_COST 6000

/* Police msg types for CB fnc */
#define POLICE_MSGT_VEHICLE_BREAK 0
#define POLICE_MSGT_HOUSE_BREAK 1
#define POLICE_MSGT_BIZ_BREAK 2

/* House types */
#define HOUSET_HOUSE 0
#define HOUSET_GARAGE 1
#define HOUSET_GARAGE_BIG 2

/* Race states */
#define RACE_STATE_NONE 0
#define RACE_STATE_JOINING 1
#define RACE_STATE_RACE 2
#define RACE_STATE_COUNTDOWN 3
#define RACE_STATE_FINISHED 4

/* Player race states */
#define PLAYER_RACE_STATE_NONE 0
#define PLAYER_RACE_STATE_CONNECTED 1
#define PLAYER_RACE_STATE_LEFT 2
#define PLAYER_RACE_STATE_FINISHED 3

/* Race CP types */
#define RACE_CP_TYPE_NONE 0
#define RACE_CP_TYPE_START 1
#define RACE_CP_TYPE_CP 2
#define RACE_CP_TYPE_SPLIT 3
#define RACE_CP_TYPE_FINISH 4

/* Job lvl patterns*/
#define FARMER_LVL 60*gPlayerData[i][pFarmerJobLvl]

/* Max job LVLs */
#define MAX_FARMER_LVL 20

/* Objects */
#define O_RADIO_T_1 2226

/* Shop fuel types */
#define FUEL_TYPE_PETROL 0
#define FUEL_TYPE_OIL 1
#define FUEL_TYPE_GAS 2

/* Default faction IDs macros */
#define FACTIONID_POLICE 0
#define FACTIONID_MEDICS 2
#define FACTIONID_SANNEWS 3
#define FACTIONID_TAXI 4
#define FACTIONID_GOVERNMENT 9
#define FACTIONID_RAFINERY 11

/* Default faction types macros */
#define FACTIONT_POLICE 1
#define FACTIONT_GOVERNMENT 2
#define FACTIONT_GANG 3
#define FACTIONT_TAXI 6
#define FACTIONT_RAFINERY 7
#define FACTIONT_COMPANY_PHONE 9
#define FACTIONT_COMPANY_OTHER 10

/* Vehicle types */
#define VEHICLET_TAXI_TP 999

/* Building types */
#define BUILDINGT_NORMAL 0
#define BUILDINGT_GARAGE 1

/* Faction types */
#define F_POLICE 1

/* Business types */
#define BIZT_EATING 1
#define BIZT_PHONE 2
#define BIZT_SHOP 3
#define BIZT_WEAPONS 4
#define BIZT_ADVERT 5
#define BIZT_CLOTHES 6
#define BIZT_BAR 7
#define BIZT_RECORD 8
#define BIZT_STUDIO 9
#define BIZT_VEHICLES 10
#define BIZT_GAS 11

/* Jobs */
#define JOB_BUSDRIVER 13
#define JOB_TRASHDRIVER 14
#define JOB_SWEEPER 15
#define JOB_FARMER 18
#define JOB_PRODUCTSELLER 5
#define JOB_MECHANIC 17

/* Item defines */
#define I_SLOT1 1
#define I_SLOT2 2
#define I_SLOT3 3
#define I_SLOT4 4
#define I_SLOT5 5
#define I_SLOT6 6
#define I_SLOT7 7
#define I_SLOT8 8
#define I_SLOT9 9
#define I_SLOT10 10
#define I_SLOT11 11
#define I_SLOT12 12
#define I_SLOT13 13
#define I_SLOT14 14
#define I_SLOT15 15
#define I_SLOT16 16
#define I_SLOT17 17
#define I_SLOT18 18
#define I_SLOT19 19
#define I_SLOT20 20
#define I_SLOT21 21
#define I_SLOT22 22
#define I_SLOT23 23
#define I_SLOT24 24
#define I_SLOT25 25

/* Factory types */
#define WF_WEAPON 1
#define WF_AMMO 2
#define WF_PART 3

/* Factory weapons own IDs */
#define WF_9MM 1
#define WF_9MMSIL 2
#define WF_DESEAGLE 3
#define WF_MICROSMG 4
#define WF_MP5 5
#define WF_TEC9 6
#define WF_SHOTGUN 7
#define WF_AK47 8
#define WF_M4 9
#define WF_RIFLE 10
#define WF_SRIFLE 11
#define WF_SCHARGE 12

/* Factory assemble part time */
#define WF_LPT 20 // light parts time
// #define WF_LPT 2 // light parts time
#define WF_LSPT 10 // light subparts time
// #define WF_LSPT 1 // light subparts time
#define WF_HPT 30 // heavy parts time
// #define WF_HPT 4 // heavy parts time
#define WF_HSPT 15 // heavy subparts time
// #define WF_HSPT 3 // heavy subparts time

/* Factory ammo own IDs */
#define WF_9MMAMMO 1
#define WF_50AEAMMO 2
#define WF_BUCKSHOT 3
#define WF_762MMAMMO 4
#define WF_127MMAMMO 5
#define WF_KGP66MMAMMO 6
#define WF_NAPALM 7
#define WF_AMMOT 10

/* Factory parts own IDs */
#define WF_PISTOLPART1 1
#define WF_PISTOLPART2 2
#define WF_PISTOLPART3 3
#define WF_PISTOLPART4 4
#define WF_PISTOLPART5 5
#define WF_PISTOLPART6 6
#define WF_RIFLEPART1 7
#define WF_RIFLEPART2 8
#define WF_RIFLEPART3 9
#define WF_RIFLEPART4 10
#define WF_RIFLEPART5 11
#define WF_RIFLEPART6 12
#define WF_RIFLEPART7 13

/* Factory other defs */
#define PMAX_ORDERS 20

/* Gametext styles */
#define GAME_TEXT_STYLE_1 1
#define GAME_TEXT_STYLE_2 2
#define GAME_TEXT_STYLE_3 3
#define GAME_TEXT_STYLE_4 4
#define GAME_TEXT_STYLE_5 5
#define GAME_TEXT_STYLE_6 6

/* Item types */
#define ITEM_TYPE_1 1
#define ITEM_TYPE_2 2
#define ITEM_TYPE_3 3
#define ITEM_TYPE_4 4
#define ITEM_TYPE_5 5
#define ITEM_TYPE_6 6
#define ITEM_TYPE_7 7
#define ITEM_TYPE_8 8
#define ITEM_TYPE_9 9
#define ITEM_TYPE_10 10

/* Tanker macros */
#define MAX_TANKER_RESOURCE_VALUE 700 				// The maximum value of tanker capacity
#define TANKER_TYPE_NONE 0 							// Tanker hasn't been tanked yet
#define TANKER_TYPE_PETROL 1 						// Tanker contain petrol
#define TANKER_TYPE_OIL 2 							// Tanker contain oil
#define TANKER_TYPE_GAS 3 							// Tanker contain gas
#define TANKER_TYPE_FLY 4 							// Tanker contain aviation fuel

/* Some special defines */
#define ADMIN_SPEC_TYPE_NONE 0
#define ADMIN_SPEC_TYPE_PLAYER 1
#define ADMIN_SPEC_TYPE_VEHICLE 2

#define HADM 5 										// Highest admin lvl
#define ALPHA 128
#define SetPlayerHoldingObject(%1,%2,%3,%4,%5,%6,%7,%8,%9) SetPlayerAttachedObject(%1,MAX_PLAYER_ATTACHED_OBJECTS-1,%2,%3,%4,%5,%6,%7,%8,%9)
#define StopPlayerHoldingObject(%1) RemovePlayerAttachedObject(%1,MAX_PLAYER_ATTACHED_OBJECTS-1)
#define IsPlayerHoldingObject(%1) IsPlayerAttachedObjectSlotUsed(%1,MAX_PLAYER_ATTACHED_OBJECTS-1)
#define dcmd(%1,%2,%3) if ((strcmp((%3)[1], #%1, true, (%2)) == 0) && ((((%3)[(%2) + 1] == 0) && (dcmd_%1(playerid, "")))||(((%3)[(%2) + 1] == 32) && (dcmd_%1(playerid, (%3)[(%2) + 2]))))) return 1
#define LIGHT_KEY KEY_SUBMISSION // Turn vehicle lights on/off
#define ResetMoneyBar ResetPlayerMoney
#define UpdateMoneyBar GivePlayerMoney
#define PRESSED(%0) \
	(((newkeys & (%0)) == (%0)) && ((oldkeys & (%0)) != (%0)))

/* Macros of hex colors */
#define COLOR_URZAD 								0xFFFFFFFF
#define COLOR_FACTIONCHAT							0x01FCFFC8
#define COLOR_LSPD 									0x0000FFAA
#define COLOR_NATIONALGUARD 						0x556B2FAA
#define COLOR_CIVILIAN 								0xFFFFFFFF
#define COLOR_ORANGE 								0xFF8000AA
#define COLOR_ADMINCMD 								0xF97804FF
//#define COLOR_ADMINDUTY 							0x007E96F6
#define COLOR_ADMINDUTY 							0xB10000F6
#define COLOR_NOTLOGGED 							0x00000000
#define COLOR_GRAD1 								0xB4B5B7FF
#define COLOR_GRAD2 								0xBFC0C2FF
#define COLOR_GRAD3 								0xCBCCCEFF
#define COLOR_GRAD4 								0xD8D8D8FF
#define COLOR_GRAD5 								0xE3E3E3FF
#define COLOR_GRAD6 								0xF0F0F0FF
#define COLOR_GREY 									0xAFAFAFAA
#define COLOR_GREEN 								0x33AA33AA
#define COLOR_RED									0xA10000AA
#define COLOR_BLACK 								0x000000FF
#define COLOR_DARKRED 								0xCD000000
#define COLOR_LIGHTRED 								0xFF6347AA
#define COLOR_LIGHTBLUE 							0x33CCFFAA
#define COLOR_LIGHTBLUE2 							0x0080FFAA
#define COLOR_LIGHTGREEN 							0x9ACD32AA
#define COLOR_LIGHTORANGE 							0xFF8000FF
#define COLOR_DARKBROWN 							0xB36C42FF
#define COLOR_LIGHTYELLOW 							0xE0E377AA
#define COLOR_LIGHTYELLOW2 							0xE0EA64AA
#define COLOR_DARKPURPLE 							0x5F56F8AA
#define COLOR_YELLOW 								0xFFFF00AA
#define COLOR_YELLOW2 								0xF5DEB3AA
#define COLOR_WHITE 								0xFFFFFFAA
#define COLOR_FADE1 								0xE6E6E6E6
#define COLOR_FADE2 								0xC8C8C8C8
#define COLOR_FADE3 								0xAAAAAAAA
#define COLOR_FADE4 								0x8C8C8C8C
#define COLOR_FADE5 								0x6E6E6E6E
#define COLOR_PURPLE 								0xC2A2DAAA
#define COLOR_DBLUE 								0x2641FEAA
#define COLOR_NEWS 									0xFFA500AA
#define COLOR_OOC 									0xE0FFFFAA

#define COLOR_GANGZONE_ALLY							0x00FF0090
#define COLOR_GANGZONE_ENEMY  						0xFF000090

#define COLOR_TITLE 								"{FFF221}"
#define COLOR_BEGIN 								"{FF0000}"
#define COLOR_BEGIN2 								"{FFF221}"
#define COLOR_DEFAULT 								"{EBEBEB}"
#define COLOR_RED_T									"{A10000}"
#define COLOR_YELLOW_T 								"{FFFF00}"
#define COLOR_GREEN_T								"{33AA33}"

/* Macros of bus txt */
#define BUS_IN_ROUTE_BEFORE_A "Tras¹ pod¹¿a co najmniej 1 autobus i kieruje siê w strone tego przystanku [1]"
#define BUS_IN_ROUTE_BEFORE_B "Tras¹ pod¹¿a co najmniej 1 autobus i kieruje siê w strone tego przystanku [2]"
#define BUS_IN_ROUTE_BEFORE_C "Tras¹ pod¹¿a co najmniej 1 autobus i kieruje siê w strone tego przystanku [3]"
#define BUS_IN_ROUTE_BEFORE_D "Tras¹ pod¹¿a co najmniej 1 autobus i kieruje siê w strone tego przystanku [4]"
#define BUS_IN_ROUTE_BEFORE_E "Tras¹ pod¹¿a co najmniej 1 autobus i kieruje siê w strone tego przystanku [5]"
#define BUS_IN_ROUTE_AFTER_A "Tras¹ pod¹¿a co najmniej 1 autobus i min¹³ ju¿ ten przystanek [1]"
#define BUS_IN_ROUTE_AFTER_B "Tras¹ pod¹¿a co najmniej 1 autobus i min¹³ ju¿ ten przystanek [2]"
#define BUS_IN_ROUTE_AFTER_C "Tras¹ pod¹¿a co najmniej 1 autobus i min¹³ ju¿ ten przystanek [3]"
#define BUS_IN_ROUTE_AFTER_D "Tras¹ pod¹¿a co najmniej 1 autobus i min¹³ ju¿ ten przystanek [4]"
#define BUS_IN_ROUTE_AFTER_E "Tras¹ pod¹¿a co najmniej 1 autobus i min¹³ ju¿ ten przystanek [5]"
#define NO_BUS_A "Brak aktualnie kursuj¹cego autobusu na tej trasie [1]"
#define NO_BUS_B "Brak aktualnie kursuj¹cego autobusu na tej trasie [2]"
#define NO_BUS_C "Brak aktualnie kursuj¹cego autobusu na tej trasie [3]"
#define NO_BUS_D "Brak aktualnie kursuj¹cego autobusu na tej trasie [4]"
#define NO_BUS_E "Brak aktualnie kursuj¹cego autobusu na tej trasie [5]"

/* Macros of MySql */
#define PLAYER_DATA_LOAD_USER_MYSQL 1
#define PLAYER_DATA_LOAD_JOB_MYSQL 2
#define PLAYER_DATA_LOAD_NOTES_MYSQL 3
// #define FREE 4
#define PLAYER_DATA_LOAD_VIP_MYSQL 5
#define PLAYER_DATA_LOAD_ITEMS_MYSQL 6
#define PLAYER_DATA_LOAD_LIC_MYSQL 7
#define PLAYER_DATA_LOAD_OTHER2_MYSQL 8
#define PLAYER_DATA_CHECK_RESULT1 9
#define PLAYER_DATA_LOAD_OTHER_MYSQL 10
#define PLAYER_DATA_LOAD_KEYS_MYSQL 11
#define LOAD_RAFINERY 12
#define SAVE 13
#define LOAD_GAS_STATIONS 14
#define LOAD_FACTIONS_PAYRANK 15
#define PAYDAY_USERS 16
#define PAYDAY_JOB 17
#define COUNT_PAYDAY 18
#define PAYDAY_OTHER 19
#define PAYDAY_OTHER2 20
#define PAYDAY_VEHICLES 21
#define LOAD_DYNAMIC_CARS 22
#define LOAD_BUS_INFO_A 23
#define LOAD_BUS_INFO_B 24
#define LOAD_BUS_INFO_C 25
#define LOAD_BUS_INFO_D 26
#define SAVE2 27
#define SAVE3 28
#define LOAD_VARIABLES 29
#define PLAYER_DATA_LOAD_OOCNAME_MYSQL 30
#define LOAD_CARSDATA 31
#define LOAD_CARS_CUSTOMIZE 32
#define SHOW_DWANTED_LIST 33
#define SHOW_SWANTED_LIST 34
#define LOAD_HOUSES 35
#define LOAD_DYNAMIC_FACTIONS 36
#define LOAD_DYNAMIC_FACTIONS_WEAPONS 37
#define LOAD_DYNAMIC_FACTIONS_WEAPONS2 38
#define RELOAD_DYNAMIC_FACTIONS 39
#define CHECK_PHONE_FEE 40
#define PLAYER_DATA_LOAD_ITEMS2_MYSQL 41
#define LOAD_HOUSES_ITEMS 42
#define PLAYER_DATA_LOAD_ITEMS3_MYSQL 43
#define LOAD_BUS_INFO_E 44
#define LOAD_WANTED_LIST 45
#define SHOW_WANTED_LIST 46
#define LOAD_WFACTORYLEGAL 47
#define LOAD_WFACTORY 48
#define LOAD_BUILDINGS 49
#define LOAD_BUSINESSES 50
#define PLAYER_DATA_LOAD_FIRST_MYSQL 51
#define PLAYER_LOAD_FUEL 52
#define SAVE4 53
// #define ______FREEEEEEEEE 54
#define LOAD_CARS_CPARTS 55
#define LOAD_CUSTOM_OBJECTS 56
#define LOAD_BUS_TRACKS 57
#define LOAD_BUS_TRACKS_DATA 58
#define LOAD_LUCKY_LOTTERY 59
#define UPDATE_DATA 60
#define LOAD_ITEM_FACTORIES 61
#define LOAD_HOUSES_DATA 62
#define CHECK_PHONE_CARD 63
#define CHECK_PHONE_TYPE_CALL 64
#define CHECK_PHONE_STATUS 65
#define PHONE_LIST_SIM_REPLACE 66
#define PHONE_LIST_FEE_RESIGN 67
#define CHECK_PHONE_TYPE_EXTENSION 68
#define PHONE_SMS_LIST 69
#define SEND_SMS 70
#define CHECK_PHONE_NEW_SMS 71
#define SEND_SMS_TO_ALL 72
#define LOAD_RANDOM_PICKUP_EVENT_1 73
#define LOAD_RANDOM_PICKUP_EVENT_2 74
#define LOAD_RANDOM_PICKUP_EVENT_3 75
#define CHECK_VEHICLE_AVAILABLE 76
#define LOAD_RACES_TRACKS 77
#define LOAD_RACES_TRACKS_DATA 78
#define LOAD_RACER_STATS 79
#define LOAD_TRASH_TRACKS 80
#define LOAD_TRASH_TRACKS_DATA 81
#define LOAD_SWEEPER_TRACKS 82
#define LOAD_SWEEPER_TRACKS_DATA 83
#define LOAD_GANG_ZONES 84
#define LOAD_WEED 85
#define LOAD_FARMER_TRACKS 86
#define LOAD_FARMER_TRACKS_DATA 87
#define LOAD_DRIVER_BOOK_QUESTION 88
#define DEF_FAC_LEADERS 89
#define CHECK_ACCOUNT_STATUS 90
#define SET_FORUM_FACTION 91
#define LOAD_MAP_ICONS 92
#define COMPANY_MEMBERS_DISMISS 93
#define LOAD_PUBLIC_ADS 94
#define DEL_FROM_FORUM_FACTION 95
#define PLAYER_VEHICLE_CASH 96
#define LOAD_ITEMS_FOR_DELETE 97
#define LOAD_ITEMS2_FOR_DELETE 98
#define LOAD_ITEMS3_FOR_DELETE 99
#define FACTION_MEMBERS_RANK 100
#define LOAD_RACER_STATS_BEST 101
#define LOAD_PICKUP_INFOS 102
#define CASH_FOR_EXPORT_VEH 103
#define LOAD_NEWS 104
#define PLAYER_DATA_LOAD_ALL 105
#define PLAYER_DATA_LOAD_ALL_PAYDAY 106
#define CHECK_ACCOUNT_STATUS_PAYDAY 107

/* Macros of dialogs */
#define DIALOG_ITEM_1 1
#define DIALOG_ITEM_2 2
#define DIALOG_ITEM_TRANSFER 3
#define DIALOG_KANISTER 7
#define DIALOG_BUY_SIM 8
#define DIALOG_PHONE 9
#define DIALOG_PHONE2 10
#define DIALOG_PHONE_BOOK 11
#define DIALOG_SMS 13
#define DIALOG_PHONE_ALARMS 14
#define DIALOG_WANTED 15
#define DIALOG_LOGIN 16
#define DIALOG_KANISTER_REFUEL 17
#define DIALOG_HITEM_1 18
#define DIALOG_HITEM_2 19
#define DIALOG_ITEM_REMOVE 20
#define DIALOG_HITEM_INS_1 21
#define DIALOG_HITEM_INS_2 22
#define DIALOG_HITEM_INS_3 23
#define DIALOG_HITEM_3 24
#define DIALOG_GOVERNMENT_1 25
#define DIALOG_GOVERNMENT_INFO 26
#define DIALOG_GOVERNMENT_JOBS 27
#define DIALOG_GOVERNMENT_JOBS_2 28
#define DIALOG_GOVERNMENT_JOBS_3 29
#define DIALOG_BUY_1 30
#define DIALOG_BUY_2P_MSG 31
#define DIALOG_WMENU_1 32
#define DIALOG_WMENU_2_WEAPON 33
#define DIALOG_WMENU_2_PARTS 34
#define DIALOG_WMENU_2_AMMO 35
#define DIALOG_ITEM_TRANSFER_RESPONSE 36
#define DIALOG_WMENU_3_PARTS_MMAKE 37
#define DIALOG_WMENU_3_PARTS_SBUY 38
#define DIALOG_WMENU_4_PARTS_SBUY 39
#define DIALOG_WMENU_4_PARTS_MMAKE 40
#define DIALOG_WMENU_5_PARTS_SBUY 41
#define DIALOG_WMENU_3_WEAPON_MAKE 42
#define DIALOG_WMENU_4_WEAPON_MAKE 43
#define DIALOG_WMENU_NOSPAREPART 44
#define DIALOG_WMENU_5_PARTS_MMAKE 45
#define DIALOG_WMENU_3_AMMO_MAKE 46
#define DIALOG_WMENU_2_RETURN 47
#define DIALOG_RAF_RSC_CP_MAIN 48
#define DIALOG_RAF_RSC_CP_INFO_A 49
#define DIALOG_RAF_RSC_CP_INFO_B 50
#define DIALOG_RAF_RSC_CP_REFUELING 51
#define DIALOG_INFO 52
#define DIALOG_WMENU_3_INFO 53
#define DIALOG_HELP 54
#define DIALOG_WLMENU_1_SELECT 55
#define DIALOG_WLMENU_2_SEL_BUY 56
#define DIALOG_WLMENU_2_SEL_ORD 57
#define DIALOG_WLMENU_2_LIMIT 58
#define DIALOG_WLMENU_2_WEAPON_B 59
#define DIALOG_WLMENU_2_WEAPON_O 60
#define DIALOG_WLMENU_3_WEAPON_B 61
#define DIALOG_WLMENU_3_WEAPON_O 62
#define DIALOG_WLMENU_1_BUY 63
#define DIALOG_WLMENU_2_AMMO_B 64
#define DIALOG_WLMENU_2_AMMO_O 65
#define DIALOG_WLMENU_3_AMMO_O 66
#define DIALOG_WLMENU_3_AMMO_B 67
#define DIALOG_REFUEL_VEH 68
#define DIALOG_BUY_2P 69
#define DIALOG_BUY_2F 70
#define DIALOG_BUYW_1 71
#define DIALOG_BUYW_2W 72
#define DIALOG_BUYW_2A 73
#define DIALOG_BUYW_3W 74
#define DIALOG_BUYW_3A 75
#define DIALOG_BUYW_4W 76
#define DIALOG_BUYW_4A 77
#define DIALOG_HELP_2 78
#define DIALOG_CBUY_1 80
#define DIALOG_CBUY_2 81
#define DIALOG_BUY_3P 82
#define DIALOG_BUY_4P 83
#define DIALOG_HITEM_4 84
#define DIALOG_LAWYER_1 85
#define DIALOG_MAKE_OBJECT 86
#define DIALOG_VITEM_1 87
#define DIALOG_VITEM_2 88
#define DIALOG_VITEM_3 89
#define DIALOG_VITEM_4 90
#define DIALOG_VITEM_INS_1 91
#define DIALOG_VITEM_INS_2 92
#define DIALOG_BUY_5P 93
#define DIALOG_ITEM_FACTORY_1 94
#define DIALOG_ITEM_FACTORY_2 95
#define DIALOG_ITEM_FACTORY_3 96
#define DIALOG_ITEM_FACTORY_4 97
#define DIALOG_ITEM_FACTORY_5 98
#define DIALOG_BUY_6P 99
#define DIALOG_BUY_7P 100
#define DIALOG_BUY_8P 101
#define DIALOG_ITEM_3 102
#define DIALOG_ITEM_4 103
#define DIALOG_DRIVINGTESTQ 104
#define DIALOG_DRIVINGTESTQ_2 105
#define DIALOG_NEW_VERSION 106
#define DIALOG_ONOFF 107
#define DIALOG_ITEM_5 108
#define DIALOG_FBUY_1 109
#define DIALOG_FBUY_2 110
#define DIALOG_FBUY_3 111
#define DIALOG_FBUY_4 112
#define DIALOG_FBUY_5 113
#define DIALOG_FBUY_6 114
#define DIALOG_FBUY_MSG 115
#define DIALOG_ITEM_4B 116
#define DIALOG_FBUY_MSG2 117
#define DIALOG_POLICE_COMPUTER_1 118
#define DIALOG_POLICE_COMPUTER_2A 119
#define DIALOG_POLICE_COMPUTER_2B 120
#define DIALOG_POLICE_COMPUTER_3A 121
#define DIALOG_POLICE_COMPUTER_3B 122
#define DIALOG_POLICE_COMPUTER_4A 123
#define DIALOG_POLICE_COMPUTER_4B 124
#define DIALOG_POLICE_COMPUTER_4C 125
#define DIALOG_POLICE_COMPUTER_4D 126
#define DIALOG_POLICE_COMPUTER_5A 127
#define DIALOG_POLICE_COMPUTER_5B 128
#define DIALOG_POLICE_COMPUTER_5C 129
#define DIALOG_POLICE_COMPUTER_3C 130
#define DIALOG_POLICE_COMPUTER_3D 131
#define DIALOG_HEAL_ASK 132
#define DIALOG_EXAMINE_ASK 133
#define DIALOG_WLMENU_4_WEAPON_B_NFO 134
#define DIALOG_WLMENU_5_WEAPON_B 135
#define DIALOG_WLMENU_4_WEAPON_B 136
#define DIALOG_WLMENU_5_WEAPON_B_F 137
#define DIALOG_WLMENU_5_WEAPON_B_B 138
#define DIALOG_WLMENU_4_AMMO_B_NFO 139
#define DIALOG_WLMENU_5_AMMO_B 140
#define DIALOG_WLMENU_4_AMMO_B 141
#define DIALOG_WLMENU_5_AMMO_B_F 142
#define DIALOG_WLMENU_5_AMMO_B_B 143
#define DIALOG_BUY_SIM_2_FEE 144
#define DIALOG_BUY_SIM_2_CARD 145
#define DIALOG_BUY_SIM_2_RENEW 146
#define DIALOG_BUY_SIM_2_RESIGN 147
#define DIALOG_BUY_SIM_2_EXTENSION 148
#define DIALOG_SELECT_PHONE_COMPANY 149
#define DIALOG_SELECT_PHONE_COMPANY_2 150
#define DIALOG_SELECT_PHONE_COMPANY_3 151
#define DIALOG_BUY_SIM_2_RESIGN_CONTRACT 152
#define DIALOG_NETWORK_COMP_1 153
#define DIALOG_NETWORK_COMP_2 154
#define DIALOG_SMS_2_VIEW 155
#define DIALOG_SMS_3_VIEW 156
#define DIALOG_SMS_4_VIEW_ANSWER 157
#define DIALOG_SMS_4_VIEW_DELETE 158
#define DIALOG_SMS_2_SEND 159
#define DIALOG_SMS_3_SEND_MANU 160
#define DIALOG_SMS_4_SEND_MANU 161
#define DIALOG_SMS_3_SEND_SEL 162
#define DIALOG_SMS_5 163
#define DIALOG_STEAL_FROM_PLAYER 164
#define DIALOG_RACE 165
#define DIALOG_RACE_INFO 166
#define DIALOG_RACE_SELECT 167
#define DIALOG_RACE_STATS 168
#define DIALOG_RACE_MAKE_1 169
#define DIALOG_MAKE_FACTION 170
#define DIALOG_MAKE_FACTION_2 171
#define DIALOG_MAKE_FACTION_3 172
#define DIALOG_RADIO_CHANNELS 173
#define DIALOG_DRIVER_BOOK 174
#define DIALOG_DRIVER_BOOK_2 175
#define DIALOG_REPORT_PROBLEM 176
#define DIALOG_HELP_3 177
#define DIALOG_ITEM_TRANSFER_COUNT 178
#define DIALOG_LOGIN_KP 179
#define DIALOG_GOVERNMENT_LIC 180
#define DIALOG_GOVERNMENT2_1 181
#define DIALOG_BUY_BUS_TICKET 182
#define DIALOG_F_ARMENT_1 183
#define DIALOG_F_ARMENT_2 184
#define DIALOG_F_ARMENT_W_1 185
#define DIALOG_F_ARMENT_W_2 186
#define DIALOG_F_ARMENT_A_1 187
#define DIALOG_F_ARMENT_A_1_MSG 188
#define DIALOG_MEDIC_1 189
#define DIALOG_HEAL_ASK_BOT 190
#define DIALOG_BUY_5P_BAR 191
#define DIALOG_BUY_6P_BAR 192
#define DIALOG_F_PAYMENT_1 193
#define DIALOG_F_PAYMENT_2 194
#define DIALOG_F_PAYMENT_2_MSG 195
#define DIALOG_F2_PAYMENT_1 196
#define DIALOG_F2_PAYMENT_2 197
#define DIALOG_F2_PAYMENT_2_MSG 198
#define DIALOG_COMPANY 199
#define DIALOG_COMPANY_DISMISS 200
#define DIALOG_COMPANY_DISMISS_MSG 201
#define DIALOG_COMPANY_HIRE 202
#define DIALOG_COMPANY_HIRE_MSG 203
#define DIALOG_COMPANY_PAYMENT 204
#define DIALOG_COMPANY_PAYMENT_MSG 205
#define DIALOG_OBJECT_TXT 206
#define DIALOG_OBJECT_TXT_2 207
#define DIALOG_OBJECT_TXT_3 208
#define DIALOG_OBJECT_TXT_4 209
#define DIALOG_OBJECT_TXT_5 210
#define DIALOG_OBJECT_TXT_6 211
#define DIALOG_ENGINE_REPAIR_CONFIRM 212
#define DIALOG_SELECT_WHEEL_TO_FIX 213
#define DIALOG_WHEEL_REPAIR_CONFIRM 214
#define DIALOG_BULB_CHANGE_SELECT 215
#define DIALOG_BULB_CHANGE_CONFIRM 216
#define DIALOG_HOOK_ADD_CONFIRM 217
#define DIALOG_SELECT_BIZ_INT 218
#define DIALOG_LPG_ADD_CONFIRM 219
#define DIALOG_BUY_BUILDING 220
#define DIALOG_POLICELIGHT_ADD_CONFIRM 221
#define DIALOG_TAXILIGHT1_ADD_CONFIRM 222
#define DIALOG_TAXILIGHT2_ADD_CONFIRM 223
#define DIALOG_TAXILIGHT3_ADD_CONFIRM 224
#define DIALOG_TAXILIGHT4_ADD_CONFIRM 225
#define DIALOG_NETWORK_COMP_MSG 226
#define DIALOG_GOVERNMENT_VEH_REG 227
#define DIALOG_EVENT_JOIN 228
#define DIALOG_EVENT_SELECT 229
#define DIALOG_EVENT_SELECT_TIME 230
#define DIALOG_EVENT_SELECT_PRIZE 231
#define DIALOG_EVENT_STOP 232
#define PLAYER_PRIVATE_VEHICLE_CASH 233
#define DIALOG_FACTION 234
#define DIALOG_FACTION_HIRE 235
#define FACTION_MEMBERS_DISMISS 236
#define DIALOG_FACTION_HIRE_MSG 237
#define DIALOG_FACTION_DISMISS_MSG 238
#define DIALOG_FACTION_DISMISS 239
#define DIALOG_FACTION_RANK_SELECT 240
#define DIALOG_FACTION_RANK 241
#define DIALOG_FACTION_RANK_MSG 242
#define DIALOG_FACTION_PAYMENT_MSG 243
#define DIALOG_FACTION_PAYMENT_ENTER 244
#define DIALOG_FACTION_PAYMENT 245
#define DIALOG_FACTION_SKIN_SELECT 246
#define DIALOG_FACTION_SKIN_INPUT 247
#define DIALOG_FACTION_SKIN_MSG 248
#define DIALOG_FACTORY_BUILD 249
#define DIALOG_REPORTS 250
#define DIALOG_TUNING_ADD_CONFIRM 251
#define DIALOG_STOCK_ADD_CONFIRM 252
#define DIALOG_MAP_LOCATIONS 253
#define DIALOG_MAP_LOCATIONS_SET 254
#define DIALOG_RENT_VEH 255
#define DIALOG_GPS_LOCATIONS 256
#define DIALOG_GPS_LOCATIONS_SET 257
#define DIALOG_TELEPORT_TAXI 258
#define DIALOG_HELP_4 259
#define DIALOG_NEW_NEWS 260
#define DIALOG_NEW_NEWS2 261
#define DIALOG_HOUSE 262
#define DIALOG_HOUSE_MONEY 263
#define DIALOG_HOUSE_MONEY_TAKE 264
#define DIALOG_HOUSE_MONEY_PUT 265
#define DIALOG_HOUSE_MONEY_MSG 266
#define DIALOG_HOUSE_RENT 267
#define DIALOG_HOUSE_RENT_PRICE 268
#define DIALOG_HOUSE_RENT_MSG 269
#define DIALOG_HOUSE_ITEMS 270

/* Macros of audio */
#define AUDIO_ITEM_PICKUP 1
#define AUDIO_BUY1 2
#define AUDIO_DOOR_CLOSE 3
#define AUDIO_DOOR_OPEN 4
#define AUDIO_HEART_BEAT 5
#define AUDIO_BREATH 6
#define AUDIO_URBAN_NOISE 7
#define AUDIO_URBAN_NOISE_MORNING 8
#define AUDIO_SUBURB_NOISE 9

/* UAC macros */
#define CONFIG_FILE "UAC/UAC_Config.ini"
#define MAX_WEAPONS		46
#define UAC_MAX_AMMO    50      // Max Number of Ammo, as difference

/* Bodyparts macros */
#define BODY_PART_HEAD 1
#define BODY_PART_TORSO 2
#define BODY_PART_LEGS 3

/* Player spawn on class request for camera rotation/animation */
#define player_x -2706
#define player_y 376
#define player_z 5
#define player_angle 210

/* Camera data fo */
//note: for a better effect, let the camera be a few meters away from the player
#define camera_x -2707
#define camera_y 319
#define camera_z 9
#define moving_speed 50

/* Action ranges */
#define AR_HOUSE_STEALING 30.0
#define AR_BUSINESS_STEALING 30.0

// /* Firework macros */
// #define COLOR_TAN 0xBDB76BAA
// #define RED 		0xE60000FF
// #define WHITE 		0xFFFFFFFF
// #define MAX_LIGHTS 100
// #define MAX_PARTS 13
// #define Sprinkleid 52
// #define RBSprinkleid 20

// /* Firework dialogs */
// #define FWCPM 500
// #define FWCPDD 501
// #define FWCPFC 502
// #define FWCPFR1 503
// #define FWCPFR2 504
// #define FWCPCR 505
// #define FWCPFT1 506
// #define FWCPFT2 507
// #define FWCPFT3 508
// #define FWCPRB 509

/* Variable with text */
new DIALOG_ITEM_FACTORY_TITLE[150] = "Fabryka itemów - %s";
new DIALOG_ITEM_FACTORY_ITEM_LIST[] = "1. %s [$%d][%d]\n2. %s [$%d][%d]\n3. %s [$%d][%d]\n4. %s [$%d][%d]\n5. %s [$%d][%d]\n6. %s [$%d][%d]\n7. %s [$%d][%d]\n8. %s [$%d][%d]\n9. %s [$%d][%d]\n10. %s [$%d][%d]\n";
new DIALOG_ITEM_FACTORY_HOW_MUCH[63 char] = !"Wpisz wartoœæ odpowiadaj¹c¹ iloœci itemów które chcesz zakupiæ";
new DIALOG_ITEM_FACTORY_WRONG_VALUE[49 char] = !"Poda³eœ niepoprawn¹ wartoœæ, spróbuj jeszcze raz";
new DIALOG_ITEM_FACTORY_NO_SPACE[27 char] = !"Nie masz miejsca w schowku";
new DIALOG_ITEM_FACTORY_NO_ITEM[114 char] = !"Niestety nie ma teraz tego itemu na stanie lub jego iloœæ jest za ma³a w stosunku do minimalnego mo¿liwego zakupu";
new DIALOG_ITEM_FACTORY_NO_CASH[21 char] = !"Masz za ma³o gotówki";
new DIALOG_ITEM_FACTORY_B_CONFIRM[] = "Czy potwierdzasz zakup %d itemów za kwote $%d ?";
new DIALOG_ITEM_FACTORY_MIN_BUY[] = "Musisz kupiæ co najmniej %d tych itemów !";
new DIALOG_ITEM_FACTORY_B_SUCCESS[15 char] = !"Kupi³eœ itemy !";
new DIALOG_INFO_HEADER[11 char] = !"Informacja";
new DIALOG_INFO_EXIT[] = "Zamknij";
new DIALOG_GOVERNMENT_1_TXT[] = "ZnaleŸæ prace\nPrzejrzeæ aktualne podatki\nWyrobiæ dowód\nWyrobiæ prawo jazdy\nWyrobiæ dowód rejestracyjny pojazdu";
new DIALOG_GOVERNMENT2_1_TXT[] = "Przejrzeæ frakcje nie posiadaj¹ce lidera";
new DIALOG_GOV_APPLY_TXT[] = "WeŸ prace";
new DIALOG_BUY_1_TXT[33 char] = !"Transakcja zakoñczona sukcesem !";
new DIALOG_BUY_2_TXT[46 char] = !"Nie posiadasz wystarczaj¹cej iloœci pieniêdzy";
new DIALOG_BUY_3_TXT[78 char] = !"Jesteœ przeci¹¿ony !\nWyrzuæ jeden lub wiêcej itemów aby odci¹¿yæ swoj¹ postaæ";
new DIALOG_BUY_4_TXT[] = "Nie masz wiêcej miejsca !";
// new DIALOG_BUY_5_TXT[] = "Posiadasz ju¿ ten item";
new DIALOG_BUY_6_TXT[36 char] = !"Ten produkt nie ma ustalonej ceny !";
new DIALOG_BUY_7_TXT[32 char] = !"Nie wybra³eœ ¿adnego produktu !";
new DIALOG_BUY_8_TXT[15 char] = !"Brak produktu !";
new DIALOG_BUY_9_TXT[49 char] = !"Aby kupiæ ubranie udaj siê do przymierzalni obok";
new DIALOG_WMENU_TITLE_TXT[] = "Menu skupu broni oraz amunicji";
new DIALOG_WMENU_NOSPAREPART_TXT[] = "Brak wymaganych czêœci !";
new DIALOG_WMENU_NOCASH_TXT[] = "Niewystarczaj¹ca iloœc pieniêdzy w kasie frakcji !";
new DIALOG_WMENU_GOTO1_TXT[] = "[INFO:] Udaj siê teraz do jednego ze stanowisk";
new DIALOG_WMENU_GOTO2_TXT[] = "[INFO:] Aby rozpocz¹æ prace wpisz /skladaj";
new DIALOG_WMENU_BOUGHT_PART_TXT[] = "Kupi³eœ czêœæ !\nJest ona teraz dostêpna w magazynie frakcji";
new DIALOG_WMENU_BUY_CHECKOUT_TXT[] = "Nazwa: %s\nDostêpna iloœæ w magazynie frakcji: %d\nCena: $%d\nZasoby frakcji: $%d";
new DIALOG_WMENU_BUY_CHECKOUT2_TXT[] = "Nazwa: %s\nDostêpna iloœæ w magazynie frakcji: %d\n";
new DIALOG_WMENU_MAIN_TXT[] = "1. Bronie\n2. Czêœci\n3. Amunicja\n4. Zwróæ czêœci";
new DIALOG_WMENU_SEL_TXT[] = "1. Broñ\n2. Amunicja";
new DIALOG_WMENU_SEL_OB_TXT[] = "1. Zamów\n2. Kup";
new DIALOG_WMENU_3_WEAPON_INFO_TXT[] = "Wybra³eœ ju¿ broñ lub czêœæ któr¹ chcesz zmontowaæ.\nAby wybraæ now¹ rzecz zwróc posiadane czêœci przechodz¹c do odpowiedniego menu w \"Menu broni\"";
new DIALOG_WMENU_3_NO_SPACE_TXT[] = "Jesteœ przeci¹¿ony !";
new DIALOG_WMENU_LIM_TXT[] = "Osi¹gn¹³eœ limit zamówieñ !\nWróæ jutro.";
new DIALOG_WMENU_B_OUT_TXT[] = "Brak broni w magazynie lub iloœæ na zamówieniu przekracza jej aktualny stan !";
new DIALOG_WMENU_W_LIST_TXT[] = "1. Pistolet 9mm [%d]\n2. Pistolet 9mm z t³umikiem [%d]\n3. Pistolet Desert Eagle [%d]\n4. Pistolet maszynowy micro SMG [%d]\n5. Pistolet maszynowy MP5 [%d]\n6. Tec9 [%d]\n7. Shotgun [%d]\n8. Karabinek AK-47 [%d]\n9. Karabinek M4 [%d]\n10. Karabin [%d]\n11. Karabin snajperski [%d]\n12. Kastet [20$]\n13. £om [15$]\n14. Wytrych [5$]\n15. Pancerz";
new DIALOG_WMENU_PASS_WL_TXT[] = "Zakoñczo etap %d z %d";
new DIALOG_BUYW_TXT[] = "1. Pistolet 9mm [%d][$%d]\n2. Pistolet 9mm z t³umikiem [%d][$%d]\n3. Pistolet Desert Eagle [%d][$%d]\n4. Pistolet maszynowy micro SMG [%d][$%d]\n5. Pistolet maszynowy MP5 [%d][$%d]\n6. Tec9 [%d][$%d]\n7. Shotgun [%d][$%d]\n8. Karabinek AK-47 [%d][$%d]\n9. Karabinek M4 [%d][$%d]\n10. Karabin [%d][$%d]\n11. Karabin snajperski [%d][$%d]";
new DIALOG_BUYA_TXT[] = "1. Nabój 9mm [%d][$%d]\n2. Nabój .50 AE [%d][$%d]\n3. Œrut [%d][$%d]\n4. Nabój 7.62mm [%d][$%d]\n5. Nabój 12.7mm [%d][$%d]";
new WFACTORY_MOUNT_P_CP[] = "Punkt montowania broni/czesci~n~/menubroni";
new WFACTORY_MOUNT_SP_CP[] = "Punkt montowania amunicji~n~/menubroni";
new WFACTORY_TAKE_BUY_CP[] = "Punkt poboru/kupna czesci/podczesci~n~/menubroni";
new WFACTORY_TAKE_ORD_BUY_CP[] = "Punkt zamowien oraz skupu";
// new WFACTORY_RETURN_CP[] = "Punkt skladowania broni";
new WF_ASSEMBLE_T_LEFT[] = "Skladanie czesci    - pozostalo %d sekund";
new WF_ASSEMBLE_F_WEAPON[] = "Zmontowa³eœ broñ !";
new WF_ASSEMBLE_F_PART[] = "Zmontowa³eœ czêœæ !";
new WF_ASSEMBLE_F_AMMO[] = "Zmontowa³eœ amunicje !";
new WF_ASSEMBLE_NOT_SLCTED[] = "Nie wybra³eœ elementu do montowania.\nWybierz odpowiedni element w menu broni.";
new WF_ASSEMBLE_NOT_WCP[] = "Nie jesteœ w punkcie sk³adania broni/czêœci !";
new WF_ASSEMBLE_NOT_ACP[] = "Nie jesteœ w punkcie skladania amunicji !";
new WF_ASSEMBLE_ALREADY[] = "Poczekaj na zakoñczenie montowania obecnej czêœci.";
new SHOP_PRODUCT_LIST[] = "1. %s [$%d][%d]\n2. %s [$%d][%d]\n3. %s [$%d][%d]\n4. %s [$%d][%d]\n5. %s [$%d][%d]\n6. %s [$%d][%d]\n7. %s [$%d][%d]\n8. %s [$%d][%d]\n9. %s [$%d][%d]\n10. %s [$%d][%d]";
new FOOD_PRODUCT_LIST[] = "1. %s [$%d][%d]\n2. %s [$%d][%d]\n3. %s [$%d][%d]\n4. %s [$%d][%d]\n5. %s [$%d][%d]";
new DIALOG_HELP_MAIN_TXT[] = "Regulamin\nJak zacz¹æ\nFAQ\nLicencje\nAnimacje\nPojazdy\nPrace\nPaski zdrowia - opis\nPaski zdrowia\nCzaty\nIkony na mapie\nProblemy i bugi\nNarkotyki\nHurtownie\nWyœcigi\nWORD\nDomy\nBiznesy";
new RADIO_CHANNELS[] = "[1:] Radioparty.pl g³ówny [2:] DJ Mixes [3:] House [4:] Trance [5:] Vocal Trance [6:] DnB [7:] Hardstyle [8:] Chillout";
new RADIO_CHANNELS2[] =  "[9:] Radio Zet [10:] RMF Classic [11:] RMF FM [12:] Eska rock [13:] Eska Bydgoszcz 94,4 FM [14:] RadioDiscoPoloFM";
new RADIO_CHANNELS3[] = "[15:] Technobase.FM [16:] Roots Reggae SKY.FM [17:] RMF Hip Hop [18:] Antyradio Warszawa";
new RADIO_CHANNELS_DIALOG[] = "1. Radioparty.pl - kana³ g³ówny\n2. Radioparty.pl - DJ Mixes\n3. Radioparty.pl - House\n4. Radioparty.pl - Trances\n5. Radioparty.pl - Vocal Trance\n6. Radioparty.pl - Energy 2000\n7. Radioparty.pl - Ambeat\n8. Radio Horyzont\n9. Radio Zet\n10. RMF Classic\n11. RMF FM\n12. Eska Rock\n13. Eska Warszawa\n14. Polska Stacja - Disco Polo\n15. Technobase.FM\n16. Rastastacja\n17. Kiss The Flow\n18. Antyradio Warszawa";
new DIALOG_KANISTER_TXT[] = "1. Przeka¿ item\n2. Wyrzuæ item\n3. Zatankuj pojazd\n4. Zawartoœæ\n5. Zatankuj kanister";
new DIALOG_DRIVINGTESTQ_TITLE[] = "Test teoretyczny na prawo jazdy";

/* Bus job const */
new JOB_BUS_DEP_TIME_LEFT[] = "Odjazd za: %d sek.";

/* Legal factory weapon menu */
new DIALOG_WMENU_BUY_W_TXT[] = "Nazwa: %s\nDostêpna iloœæ w magazynie: %d\nCena za sztuke: $%d";
new DIALOG_WMENU_ORD_W_TXT[] = "Nazwa: %s\nDostêpna iloœæ w magazynie: %d\nAktualnie zamówionych: %d\nCena sztuke: $%d";
new DIALOG_WMENU_BUY_A_TXT[] = "Nazwa: %s\nDostêpna iloœæw magazyne: %d\nCena za komplet: $%d";
new DIALOG_WMENU_ORD_A_TXT[] = "Nazwa: %s\nDostêpna iloœæ w magazynie: %d\nAktualnie zamówionych: %d\nCena za komplet: $%d";

/* Rafinery const */
new RAF_RSC_CP_MENU_HEADER[] = "Menu punktu tankowania cystern";
new RAF_RSC_CP_MENU_OPTIONS_MAIN[] = "1. Zatankuj benzyne \n2. Zatankuj rope\n3. Nape³nij gazem\n4. Nape³nij paliwem lotniczym\n5. Opró¿nij zawartoœæ cysterny do magazynu rafinerii";
new RAF_RSC_CP_MENU_SELECT[] = "Wybierz";
new RAF_RSC_CP_MENU_EXIT[] = "Zamknij";
new RAF_RSC_CP_MENU_BACK[] = "Wróæ";
new RAF_RSC_CP_MENU_INV_VEHID[] = "Nie znajdujesz siê w pojeŸdzie.\nNie mo¿na zatankowaæ cysterny";
new RAF_RSC_CP_MENU_INV_VEHFAC[] = "Ten pojazd nie nale¿y do rafinerii.\nNie mo¿na zatankowaæ cysterny";
new RAF_RSC_CP_MENU_INV_TLID[] = "Pod pojazd nie jest podczepiona cysterna.\nNie mo¿na rozpocz¹æ tankowania";
new RAF_RSC_CP_MENU_INV_TLFAC[] = "Cysterna nie nale¿y do rafinerii.\nNie mo¿na rozpocz¹æ tankowania";
new RAF_RSC_CP_MENU_INV_TYPE[] = "Cysterna zawiera ju¿ paliwo innego typu.\nOpró¿nij cysterne przed jej nape³nieniem";
new RAF_RSC_CP_MENU_NO_TYPE[] = "Cysterna nie zawiera paliwa ¿adnego typu";
new RAF_RSC_CP_MENU_REFUELING[] = "Cysterna jest tankowana, prosze czekaæ...\n\nPo zatankowaniu poka¿e siê okienko z komunikatem o rezultacie tankowania\nW tym czasie nie nale¿y wychodziæ z ciê¿arówki ani jej przemiszczaæ";
new RAF_RSC_CP_MENU_DRAINING[] = "Odpompowywanie paliwa z cysterny, prosze czekaæ...\n\nPo odpompowaniu poka¿e siê okienko z komunikatem o rezultacie odpompowania\nW tym czasie nie nale¿y wychodziæ z cie¿arówki ani jej przemieszczaæ";
new RAF_RSC_CP_MENU_DRAINED_A[] = "Odpompowywanie zakoñczone !";
new RAF_RSC_CP_MENU_DRAINED_B[] = "Odpompowywanie przerwane - nast¹pi³o przemieszczenie cysterny lub opuœci³eœ pojazd";
new RAF_RSC_CP_MENU_REFUELED_A[] = "Cysterna zosta³a zatankowana !";
new RAF_RSC_CP_MENU_REFUELED_B[] = "Cysterna nie zosta³a zatankowana do pe³na - brak zasobów w rafinerii";
new RAF_RSC_CP_MENU_REFUELED_C[] = "Cysterna nie zosta³a zatankowana - nast¹pi³o przemieszczenie cysterny lub opuœci³eœ pojazd";
new RAF_RSC_CP_MENU_AREFUELING[] = "Cysterna jest ju¿ tankowana !";
new RAF_RSC_CP_MENU_AMAX[] = "Cysterna jest ju¿ pe³na !";
new RAF_RSC_CP_MENU_EMPTY[] = "Cysterna jest pusta !";
new RAF_RSC_CP_INV_PLFAC[] = "[INFO:] Nie jesteœ pracownikiem rafinerii !";
new RAF_RSC_CP_INV_VEHID[] = "[INFO:] Nie znajdujesz siê w pojeŸdzie, nie mo¿na rozpocz¹æ tankowania";
new RAF_RSC_CP_INV_VEH_FACTION[] = "[INFO:] Ten pojazd nie nale¿y do rafinerii i nie mo¿na go tutaj zatankowaæ";
new RAF_RSC_CP_INV_TLID[] = "[INFO:] Pod pojazd nie jest podczepiona cysterna, nie mo¿na rozpocz¹æ tankowania";
new RAF_RSC_CP_INV_TL_FACTION[] = "[INFO:] Ta cysterna nie nale¿y do rafinerii i nie mo¿na jej tutaj zatankowaæ";
new RAF_GS_NO_REFUEL[] = "Ta stacja aktualnie nie przyjmuje nowych zasobów od rafinerii";
new RAF_GS_INV_VEHID[] = "Nie znajdujesz siê w pojeŸdzie.\nNie mo¿na zatankowaæ cysterny";
new RAF_GS_INV_TLID[] = "Pod pojazd nie jest podczepiona cysterna.\nNie mo¿na rozpocz¹æ tankowania";
new RAF_GS_NO_TYPE[] = "Cysterna nie zawiera paliwa ¿adnego typu";
new RAF_GS_NO_TILL[] = "Stacja nie posiada funduszy na zatankowanie zbiorników";
new RAF_GS_FULL_PETROL[] = "Stacja ma pe³ny zbiornik benzyny !";
new RAF_GS_FULL_OIL[] = "Stacja ma pe³ny zbiornik ropy !";
new RAF_GS_FULL_GAS[] = "Stacja ma pe³ny zbiornik gazu !";
new RAF_GS_AREFUELING[] = "Cysterna ju¿ nape³nia jedne zbiorniki";
new RAF_GS_REFUELED_A[] = "Zbiorniki zosta³y nape³nione. Otrzyma³eœ tak¿e zap³ate za to tankowanie.";
new RAF_GS_REFUELED_B[] = "Zbiorniki nie zosta³y nape³nione - nast¹pi³o przemieszczenie cysterny lub opuœci³eœ pojazd";
new RAF_GS_REFUELED_C[] = "Zbiorniki nie zosta³y nape³nione - zabrak³o paliwa w cysternie. Otrzyma³eœ po³owe wynagrodzenia.";
new RAF_GS_REFUELED_D[] = "Zbiorniki nie zosta³y nape³nione - brak funduszy na stacji na dalsze tankowanie. Otrzyma³eœ zap³ate za to tankowanie.";

enum Winfo
{
	Weapon[13]
}
new Ammo[CUSTOM_MAX_PLAYERS][MAX_WEAPONS];
new Gun[CUSTOM_MAX_PLAYERS][Winfo];
new Spawned[CUSTOM_MAX_PLAYERS];
new IngVehData[CUSTOM_MAX_PLAYERS];
new Float:NewPos[CUSTOM_MAX_PLAYERS][3];
new PosHackCheckTime[CUSTOM_MAX_PLAYERS];
// new BadNames[100][100], BadNameCount = 0;

/* World time */
new gHour = 6, gMin = 0, gSec = 0;

/* Used in WarTimer */
new gSuspectPlayersCount;
new gAllPlayersCount;

/* Job variables */
new gPapers[CUSTOM_MAX_PLAYERS]; // praca roznosiciela gazet - ilosc przenoszonych gazet


/**
* Bus tracks variables
*/
new gBusTrackEnabled[50];
new gBusTrackStartArea[50];
new gBusTrackDesc[50][64];
new gBusTrackTicketCost[50];
new Float:gBusTrackCpX[50][50];
new Float:gBusTrackCpY[50][50];
new Float:gBusTrackCpZ[50][50];
new gBusTrackCpReward[50][50];
new gBusTrackCpType[50][50];
new gBusTrackCpTime[50][50];

/**
* Trash tracks variables
*/
new gTrashTrackEnabled[50];
new gTrashTrackStartArea[50];
new Float:gTrashTrackCpX[50][50];
new Float:gTrashTrackCpY[50][50];
new Float:gTrashTrackCpZ[50][50];
new gTrashTrackCpReward[50][50];
new gTrashTrackCpType[50][50];
new gTrashTrackCpTime[50][50];
new gTrashTrackCpTrashEnabled[50][50];
new gTrashTrackCpTrashId[50][50];

/**
* Sweeper tracks variables
*/
new gSweeperTrackEnabled[50];
new gSweeperTrackStartArea[50];
new Float:gSweeperTrackCpX[50][50];
new Float:gSweeperTrackCpY[50][50];
new Float:gSweeperTrackCpZ[50][50];
new gSweeperTrackCpReward[50][50];
new gSweeperTrackCpType[50][50];
new gSweeperTrackCpTime[50][50];
new gSweeperTrackCpTrashEnabled[50][50];
new gSweeperTrackCpTrashId[50][50];

/**
* Farmer tracks variables
*/
new gFarmerTrackEnabled[50];
new gFarmerTrackStartArea[50];
new Float:gFarmerTrackCpX[50][50];
new Float:gFarmerTrackCpY[50][50];
new Float:gFarmerTrackCpZ[50][50];
new gFarmerTrackCpReward[50][50];
new gFarmerTrackCpType[50][50];
new gFarmerTrackCpTime[50][50];
new gFarmerTrackCpTrashEnabled[50][50];
new gFarmerTrackCpTrashId[50][50];

/**
* Race tracks variables
*/
new gRaceTrackEnabled[50];
new Float:gRaceTrackInfoCpX[50];
new Float:gRaceTrackInfoCpY[50];
new Float:gRaceTrackInfoCpZ[50];
new gRaceTrackInfoPickupId[50];
new gRaceTrackStartPosCount[50];
new Float:gRaceTrackCpX[50][150];
new Float:gRaceTrackCpY[50][150];
new Float:gRaceTrackCpZ[50][150];
new gRaceTrackCpType[50][150];
new Float:gRaceTrackStart1CpX[50];
new Float:gRaceTrackStart1CpY[50];
new Float:gRaceTrackStart1CpZ[50];
new Float:gRaceTrackStart2CpX[50];
new Float:gRaceTrackStart2CpY[50];
new Float:gRaceTrackStart2CpZ[50];
new Float:gRaceTrackStart3CpX[50];
new Float:gRaceTrackStart3CpY[50];
new Float:gRaceTrackStart3CpZ[50];
new Float:gRaceTrackStart4CpX[50];
new Float:gRaceTrackStart4CpY[50];
new Float:gRaceTrackStart4CpZ[50];
new Float:gRaceTrackStart5CpX[50];
new Float:gRaceTrackStart5CpY[50];
new Float:gRaceTrackStart5CpZ[50];
new Float:gRaceTrackStart6CpX[50];
new Float:gRaceTrackStart6CpY[50];
new Float:gRaceTrackStart6CpZ[50];
new Float:gRaceTrackStart7CpX[50];
new Float:gRaceTrackStart7CpY[50];
new Float:gRaceTrackStart7CpZ[50];
new Float:gRaceTrackStart8CpX[50];
new Float:gRaceTrackStart8CpY[50];
new Float:gRaceTrackStart8CpZ[50];
new Float:gRaceTrackStart9CpX[50];
new Float:gRaceTrackStart9CpY[50];
new Float:gRaceTrackStart9CpZ[50];
new Float:gRaceTrackStart10CpX[50];
new Float:gRaceTrackStart10CpY[50];
new Float:gRaceTrackStart10CpZ[50];

enum raceStatus
{
	mRaceId,
	mRaceState,
	Text:mRaceInfo,
	mRaceTimeToStart,
	mRaceTimeToEnd,
	mRaceStartHour,
	mRaceStartMin,
	mRaceStartSec,
	mRaceLaps,
	mRaceRacersCount,
	mRaceEntrant1[MAX_PLAYER_NAME],
	mRaceEntrant1Id,
	mRaceEntrant1Status,
	mRaceEntrant1Place,
	mRaceEntrant1CpId,
	mRaceEntrant1NextCpId,
	mRaceEntrant1IsOnStartPos,
	mRaceEntrant1Hour,
	mRaceEntrant1Min,
	mRaceEntrant1Sec,
	mRaceEntrant1Lap,
	Float:mRaceEntrant1DistanceLeft,
	mRaceEntrant2[MAX_PLAYER_NAME],
	mRaceEntrant2Id,
	mRaceEntrant2Status,
	mRaceEntrant2Place,
	mRaceEntrant2CpId,
	mRaceEntrant2NextCpId,
	mRaceEntrant2IsOnStartPos,
	mRaceEntrant2Hour,
	mRaceEntrant2Min,
	mRaceEntrant2Sec,
	mRaceEntrant2Lap,
	Float:mRaceEntrant2DistanceLeft,
	mRaceEntrant3[MAX_PLAYER_NAME],
	mRaceEntrant3Id,
	mRaceEntrant3Status,
	mRaceEntrant3Place,
	mRaceEntrant3CpId,
	mRaceEntrant3NextCpId,
	mRaceEntrant3IsOnStartPos,
	mRaceEntrant3Hour,
	mRaceEntrant3Min,
	mRaceEntrant3Sec,
	mRaceEntrant3Lap,
	Float:mRaceEntrant3DistanceLeft,
	mRaceEntrant4[MAX_PLAYER_NAME],
	mRaceEntrant4Id,
	mRaceEntrant4Status,
	mRaceEntrant4Place,
	mRaceEntrant4CpId,
	mRaceEntrant4NextCpId,
	mRaceEntrant4IsOnStartPos,
	mRaceEntrant4Hour,
	mRaceEntrant4Min,
	mRaceEntrant4Sec,
	mRaceEntrant4Lap,
	Float:mRaceEntrant4DistanceLeft,
	mRaceEntrant5[MAX_PLAYER_NAME],
	mRaceEntrant5Id,
	mRaceEntrant5Status,
	mRaceEntrant5Place,
	mRaceEntrant5CpId,
	mRaceEntrant5NextCpId,
	mRaceEntrant5IsOnStartPos,
	mRaceEntrant5Hour,
	mRaceEntrant5Min,
	mRaceEntrant5Sec,
	mRaceEntrant5Lap,
	Float:mRaceEntrant5DistanceLeft,
	mRaceEntrant6[MAX_PLAYER_NAME],
	mRaceEntrant6Id,
	mRaceEntrant6Status,
	mRaceEntrant6Place,
	mRaceEntrant6CpId,
	mRaceEntrant6NextCpId,
	mRaceEntrant6IsOnStartPos,
	mRaceEntrant6Hour,
	mRaceEntrant6Min,
	mRaceEntrant6Sec,
	mRaceEntrant6Lap,
	Float:mRaceEntrant6DistanceLeft,
	mRaceEntrant7[MAX_PLAYER_NAME],
	mRaceEntrant7Id,
	mRaceEntrant7Status,
	mRaceEntrant7Place,
	mRaceEntrant7CpId,
	mRaceEntrant7NextCpId,
	mRaceEntrant7IsOnStartPos,
	mRaceEntrant7Hour,
	mRaceEntrant7Min,
	mRaceEntrant7Sec,
	mRaceEntrant7Lap,
	Float:mRaceEntrant7DistanceLeft,
	mRaceEntrant8[MAX_PLAYER_NAME],
	mRaceEntrant8Id,
	mRaceEntrant8Status,
	mRaceEntrant8Place,
	mRaceEntrant8CpId,
	mRaceEntrant8NextCpId,
	mRaceEntrant8IsOnStartPos,
	mRaceEntrant8Hour,
	mRaceEntrant8Min,
	mRaceEntrant8Sec,
	mRaceEntrant8Lap,
	Float:mRaceEntrant8DistanceLeft,
	mRaceEntrant9[MAX_PLAYER_NAME],
	mRaceEntrant9Id,
	mRaceEntrant9Status,
	mRaceEntrant9Place,
	mRaceEntrant9CpId,
	mRaceEntrant9NextCpId,
	mRaceEntrant9IsOnStartPos,
	mRaceEntrant9Hour,
	mRaceEntrant9Min,
	mRaceEntrant9Sec,
	mRaceEntrant9Lap,
	Float:mRaceEntrant9DistanceLeft,
	mRaceEntrant10[MAX_PLAYER_NAME],
	mRaceEntrant10Id,
	mRaceEntrant10Status,
	mRaceEntrant10Place,
	mRaceEntrant10CpId,
	mRaceEntrant10NextCpId,
	mRaceEntrant10IsOnStartPos,
	mRaceEntrant10Hour,
	mRaceEntrant10Min,
	mRaceEntrant10Sec,
	mRaceEntrant10Lap,
	Float:mRaceEntrant10DistanceLeft
}
new gRaceStatus[100][raceStatus];

/**
* Player bus, mzgk, sweeper, farmer job variables
*/
new gBusDriverCurrentCheckPoint[CUSTOM_MAX_PLAYERS];
new gBusDriverSelectedLine[CUSTOM_MAX_PLAYERS];
new gBusDriverIsPassenger[CUSTOM_MAX_PLAYERS];
new gBusDriverPaymentCount[CUSTOM_MAX_PLAYERS];
new gBusDriverPenaltyInformed[CUSTOM_MAX_PLAYERS];
new gBusDriverCheckpointTime[CUSTOM_MAX_PLAYERS];
new gBusDriverJustStarted[CUSTOM_MAX_PLAYERS];
new gBusDriverOnDuty[CUSTOM_MAX_PLAYERS];
new gBusDriverResetTime[CUSTOM_MAX_PLAYERS];

new gTrashDriverCurrentCheckPoint[CUSTOM_MAX_PLAYERS];
new gTrashDriverSelectedLine[CUSTOM_MAX_PLAYERS];
new gTrashDriverIsPassenger[CUSTOM_MAX_PLAYERS];
new gTrashDriverPaymentCount[CUSTOM_MAX_PLAYERS];
new gTrashDriverPenaltyInformed[CUSTOM_MAX_PLAYERS];
new gTrashDriverCheckpointTime[CUSTOM_MAX_PLAYERS];
new gTrashDriverJustStarted[CUSTOM_MAX_PLAYERS];
new gTrashDriverOnDuty[CUSTOM_MAX_PLAYERS];
new gTrashDriverResetTime[CUSTOM_MAX_PLAYERS];

new gSweeperDriverCurrentCheckPoint[CUSTOM_MAX_PLAYERS];
new gSweeperDriverSelectedLine[CUSTOM_MAX_PLAYERS];
new gSweeperDriverIsPassenger[CUSTOM_MAX_PLAYERS];
new gSweeperDriverPaymentCount[CUSTOM_MAX_PLAYERS];
new gSweeperDriverPenaltyInformed[CUSTOM_MAX_PLAYERS];
new gSweeperDriverCheckpointTime[CUSTOM_MAX_PLAYERS];
new gSweeperDriverJustStarted[CUSTOM_MAX_PLAYERS];
new gSweeperDriverOnDuty[CUSTOM_MAX_PLAYERS];
new gSweeperDriverResetTime[CUSTOM_MAX_PLAYERS];

new gFarmerDriverCurrentCheckPoint[CUSTOM_MAX_PLAYERS];
new gFarmerDriverSelectedLine[CUSTOM_MAX_PLAYERS];
new gFarmerDriverIsPassenger[CUSTOM_MAX_PLAYERS];
new gFarmerDriverPaymentCount[CUSTOM_MAX_PLAYERS];
new gFarmerDriverPenaltyInformed[CUSTOM_MAX_PLAYERS];
new gFarmerDriverCheckpointTime[CUSTOM_MAX_PLAYERS];
new gFarmerDriverJustStarted[CUSTOM_MAX_PLAYERS];
new gFarmerDriverOnDuty[CUSTOM_MAX_PLAYERS];
new gFarmerDriverResetTime[CUSTOM_MAX_PLAYERS];

/* Checkpoint variables */
new gGovCheckpoint;
new gGovCheckpoint2;
new gMedicCheckpoints[3];
new gShopCP[SHOP_CP_COUNT];
new gClotheShopCP[SHOP_CLOTHE_CP_COUNT];
new gHorsesCp[2];

/* Weather variables */
new gMW_warszawa, gMW_lasvegas, gMW_sanfrancisco, gMW_losangeles;

/* Speed limited areas */
new gASanFierro, gALosSantos1, gALosSantos2, gAAngelPine, gAPalominoCreek, gAMontgomery, gABountyBay, gADilimore, gAFortCarson, gABlueBerryFarm;
new gALosSantos3, gALosSantos4, gALosSantos5, gALosSantos6, gALosSantos7, gALosSantos8;
new gIsInCityAreaSpeedLimit[CUSTOM_MAX_PLAYERS] = 0;

/* Other areas */
new gArea_Molo, gArea_Pool;
new gArea_MW_SanFierro, gArea_MW_LosSantos, gArea_MW_LasVenturas;
new gArea_Prison1;
new gArea_CarTest;

/* Pickup variables */
new gOfficialPickup; // official status
new gP_PrisonYard; // prison yard description
new gP_SwimingPool; // swimming pool ramp enter
new gP_Lottery; // lottery pickup

/* Fireworks variables */
// new Float:FRX[MAX_PLAYERS], Float:FRY[MAX_PLAYERS], Float:FRZ[MAX_PLAYERS];
// new Float:FTX[MAX_PLAYERS], Float:FTY[MAX_PLAYERS], Float:FTZ[MAX_PLAYERS];
// new Float:RBX[MAX_PLAYERS], Float:RBY[MAX_PLAYERS], Float:RBZ[MAX_PLAYERS];
// new firecrackertime[MAX_PLAYERS];
// new firerockettime[MAX_PLAYERS];
// new explosionrocket[MAX_PLAYERS];
// new Firecracker[MAX_PLAYERS];
// new Firerocket[MAX_PLAYERS];
// new rocketsmoke[MAX_PLAYERS];
// new FireCrackerRoll[MAX_PLAYERS];
// new firecrackerroll[MAX_PLAYERS];
// new CrackerRollSmoke[MAX_PLAYERS];
// new Float:RollStartX[MAX_PLAYERS], Float:RollStartY[MAX_PLAYERS], Float:RollStartZ[MAX_PLAYERS];

// new RocketBoxTime[MAX_PLAYERS];
// new RocketBox[MAX_PLAYERS];
// new RocketBoxSmoke[MAX_PLAYERS];

// new FountainSmoke[MAX_PLAYERS];
// new Fountain[MAX_PLAYERS];

// new Light[MAX_LIGHTS][MAX_PLAYERS];
// new RollParts[MAX_PLAYERS][MAX_PARTS];
// new FountainSprinkle[Sprinkleid][MAX_PLAYERS];

// new RocketBoxSprinkle[RBSprinkleid][MAX_PLAYERS];
// new RBLight[MAX_LIGHTS][MAX_PLAYERS];

// new Fountain1Time[MAX_PLAYERS];
// new Fountain2Time[MAX_PLAYERS];
// new Fountain3Time[MAX_PLAYERS];
// new DestroySprinkleID[MAX_PLAYERS];

/* Company panel variables */
new gCompanyMembersToFire[CUSTOM_MAX_PLAYERS][100][MAX_PLAYER_NAME];
new gCompanyMembersCount[CUSTOM_MAX_PLAYERS];

/* Factio panel variables */
new gFactionMembersToFire[CUSTOM_MAX_PLAYERS][100][MAX_PLAYER_NAME];
new gFactionMembersCount[CUSTOM_MAX_PLAYERS];

/* Zone creator */
new Float:gZone1X, Float:gZone1Y, Float:gZone2X, Float:gZone2Y;

/* San News Messages */
enum gSanNewsMsgsInfo
{
	mId,
	mTimeLeft,
	mContent[255],
	mUsed
};
new gSanNewsMsgs[20][gSanNewsMsgsInfo];
new gSanNewsCurrentMsg;
new gSanNewsTimeLeft;

stock SendSanNewsMessage(message[])
{
	for(new i = 0; i < sizeof(gSanNewsMsgs); i++)
	{
		if(gSanNewsMsgs[i][mUsed])
		{
			continue;
		}
		
		format(gSanNewsMsgs, 255, message);
		
		return 1;
	}
	return 0;
}

/* Other variables */
new gPoliceComputerPassword[64];
new gBackgroundAudio1[CUSTOM_MAX_PLAYERS] = -1;
new gBackgroundAudio2[CUSTOM_MAX_PLAYERS] = -1;
new gIsPlayerFrozen[CUSTOM_MAX_PLAYERS];
new gWalkingDrunk[CUSTOM_MAX_PLAYERS];
new gIsOnAShip[CUSTOM_MAX_PLAYERS] = { -1, ... };
new gKickVoteStartCooldown[CUSTOM_MAX_PLAYERS] = { 0, ... }; // how long player must wait befor he can start next kick vote
new gKickVotePlayerVote[CUSTOM_MAX_PLAYERS] = { 0, ... }; // vote of the players 0 - NO, 1 - YES
new gKickVotePlayerToKick = INVALID_PLAYER_ID; // the player which will be kicked
new gKickVoteTimeLeft = 0; // time in which vote take place
new gBizBoughtApproved[CUSTOM_MAX_PLAYERS] = { 0, ... };
new gBizBoughtApprovalSendBy[CUSTOM_MAX_PLAYERS] = { -1, ... }; // who did send approval request
new gBizBoughtApprovalID[CUSTOM_MAX_PLAYERS] = { -1, ... }; // the ID of business which will be bought by player
new gFirstTime[CUSTOM_MAX_PLAYERS];
new gVehPosCheckCooldown[CUSTOM_MAX_PLAYERS];
new gReportCooldown; // cooldown before next report
new gVipReduceOn = 1; // if equals 1 will reduce vip time left for player in payday
new Float:gStartSpawnX, Float:gStartSpawnY, Float:gStartSpawnZ, gStartMoney, gStartBank, gStartSkin;
new gPasswd[CUSTOM_MAX_PLAYERS][145]; // onplayerlogin passwords
new gWFactoryGunCreating[CUSTOM_MAX_PLAYERS] = 0; // id itema broni/czesci jaka gracz bedzie montowal
new gTGunIDLastCD[CUSTOM_MAX_PLAYERS] = 0; // cool down
new gTGunIDLast[CUSTOM_MAX_PLAYERS] = 0;
new gTGunID = 0; // do zapisu broni w OnPlayerUpdate
new gTGunAmmo = 0; // do zapisu broni w OnPlayerUpdate
new gJustDropped[CUSTOM_MAX_PLAYERS]; // przed chwila wyrzucil item ze schowka
new gBuyBusinessID[CUSTOM_MAX_PLAYERS]; // z ktorego biznesu poszla komenda /kup
new gBuyBusinessItemListID[CUSTOM_MAX_PLAYERS]; // ktora lista itemow zostala wybrana
new gBuyBusinessItemSellCount[CUSTOM_MAX_PLAYERS]; // ile itemow na sprzedaz
new gBuyItemFactoryID[CUSTOM_MAX_PLAYERS]; // z ktorej fabryki gracz kupuje itemy
new gBuyItemFactoryVehID[CUSTOM_MAX_PLAYERS]; // z jakiego pojazdu gracz kupuje itemy
new gBuyItemFactoryItemCount[CUSTOM_MAX_PLAYERS]; // ile itemów ma zamiar kupiæ
new gLoginOn = 1;
// new Float:gWeight; // waga danego itemu
new gCalledCompany[CUSTOM_MAX_PLAYERS] = 255; // biznes obslugujacy polaczenie
new gCallCost[CUSTOM_MAX_PLAYERS]; // koszt polaczenia telefonicznego
new gCallFreeMins[CUSTOM_MAX_PLAYERS]; // ilosc pozostalych darmowych minut z konkretnego polaczenia
new gCallDataReceived[CUSTOM_MAX_PLAYERS] = {1, ...}; // czy uzyskano dane z bazy - ma zapobiec desynchronizacji
new gTransferCoolDown[CUSTOM_MAX_PLAYERS]; // cool down do /przekaz
// new gAdminAudio[CUSTOM_MAX_PLAYERS][5];
new gDSelectedHItemHouse[CUSTOM_MAX_PLAYERS]; // id domu z itemami
new gDSelectedVItemVID[CUSTOM_MAX_PLAYERS]; // id pojazdu z itemami
new gDSelectedVItemVTSpace[CUSTOM_MAX_PLAYERS]; // sloty baga¿nika pojazdu z itemami
new gDSelectedVItemSlot[CUSTOM_MAX_PLAYERS]; // id slotu
new gDSelectedHItem[CUSTOM_MAX_PLAYERS]; // slot wybrany przez dialog - itemy domowe
new gSendingPlayer[CUSTOM_MAX_PLAYERS]; // player offering player to receive item
new gSendingCount[CUSTOM_MAX_PLAYERS]; // how much items to transfer
new gOverSpeed[CUSTOM_MAX_PLAYERS]; // ile razy w czasie testu na prawko przekroczyl predkosc
new gTryCoolDown[CUSTOM_MAX_PLAYERS]; // cooldownd komendy /proba
new gAdminGodMode[CUSTOM_MAX_PLAYERS];
new gHatWearingModel[CUSTOM_MAX_PLAYERS] = 255;
new gGlassesWearingModel[CUSTOM_MAX_PLAYERS];
new lampki[51];
new gSendingSMS[CUSTOM_MAX_PLAYERS];
new gSelectedNumberID[CUSTOM_MAX_PLAYERS];
new gSelectedNumber[CUSTOM_MAX_PLAYERS];
new gSelectedSlot[CUSTOM_MAX_PLAYERS];
new gPreviousDialogList[CUSTOM_MAX_PLAYERS] = { -1 };
new gIsAntiBH = 1;
new Text3D:playerAFK[CUSTOM_MAX_PLAYERS];

/*
* Used to switch betweene dialogs maintaning selected option and containing some data
*/
new gListItem[CUSTOM_MAX_PLAYERS];
new gListOverItem[CUSTOM_MAX_PLAYERS] = -1;
new gDialogValue[CUSTOM_MAX_PLAYERS] = 0;

new gRandNumber[CUSTOM_MAX_PLAYERS];
new gRandSimNumber[CUSTOM_MAX_PLAYERS];
new gPhoneC[CUSTOM_MAX_PLAYERS];
new AccountantCost[CUSTOM_MAX_PLAYERS];
new AccountantOffer[CUSTOM_MAX_PLAYERS] = 999;
new Float:gVehHealthOnPlayerEnter[CUSTOM_MAX_PLAYERS] = 1000.0;
new Float:gJobProfit[CUSTOM_MAX_PLAYERS] = 0.0;
new gPingHitLimit[CUSTOM_MAX_PLAYERS] = 0;
new gSavePlayerReady[CUSTOM_MAX_PLAYERS] = 0;
new gSaveReady = 0;
new houseSource = 1; // 0 - deprecated (file), 1 (database)
new gPayDayLoop = 0; // actual round of payday check
new gPayDayCount = 0; // how many player payday will pass
new Text:gPayDayText = Text:INVALID_TEXT_DRAW;
new Text:gPhoneCall = Text:INVALID_TEXT_DRAW;
new Text:gPhoneText = Text:INVALID_TEXT_DRAW;
new Text:gHealthTextEnergy = Text:INVALID_TEXT_DRAW;
new Text:gTextTime = Text:INVALID_TEXT_DRAW;
// new Text:gTextDate = Text:INVALID_TEXT_DRAW;
new gPhoneCallShowed[CUSTOM_MAX_PLAYERS] = 0;
new gPhoneTextShowed[CUSTOM_MAX_PLAYERS] = 0;
new gPhoneTextBlinking[CUSTOM_MAX_PLAYERS] = 0;
new gPhoneTextReceived[CUSTOM_MAX_PLAYERS] = 0;
new Text:EatText[CUSTOM_MAX_PLAYERS] = {Text:INVALID_TEXT_DRAW,...};
new Text:GangWar[CUSTOM_MAX_PLAYERS];
new Text:GangWarTime[CUSTOM_MAX_PLAYERS];
new Text:CameraFront[CUSTOM_MAX_PLAYERS];
new Text:CameraPos[CUSTOM_MAX_PLAYERS];
new Text:Angle2[CUSTOM_MAX_PLAYERS];
new Float:pDrugsUsedStartHP[CUSTOM_MAX_PLAYERS]; // zycie gracza przed uzyciem narkotykow
new Float:pDrugsUsedStartArmour[CUSTOM_MAX_PLAYERS]; // pancerz gracza przed uzyciem narkotykow
new PlayerWrittingAnything[CUSTOM_MAX_PLAYERS];
new Bar:JobProgress[CUSTOM_MAX_PLAYERS];
new KilledWithWeapon[CUSTOM_MAX_PLAYERS];
new IncommingCall[CUSTOM_MAX_PLAYERS];
new ZonesCreated[CUSTOM_MAX_PLAYERS];
new ReadyToSave = 0;
new gDSelectedItemP5[CUSTOM_MAX_PLAYERS+1][64];
new CarKey1LVL = 2;
new AirKeyLVL = 15;
new BoatKeyLVL = 15;
new LastDrug[CUSTOM_MAX_PLAYERS];
new DyingPlayerKillTime[CUSTOM_MAX_PLAYERS];
new EnteredVehicleID[CUSTOM_MAX_PLAYERS];
new IsCarJackerOpening[CUSTOM_MAX_PLAYERS];
new MoloSequence[CUSTOM_MAX_PLAYERS] = 255;
new PoolSequence[CUSTOM_MAX_PLAYERS] = 255;
new AudioReady[CUSTOM_MAX_PLAYERS] = 0;
new CarRadioOn[CUSTOM_MAX_PLAYERS] = 0;
new CarRadioLeftOn[CUSTOM_MAX_PLAYERS] = 0;
new CarRadioID[CUSTOM_MAX_PLAYERS] = 255;
new Zasilek = 100;
new MusicHandle[CUSTOM_MAX_PLAYERS][2];
new IsMusicPlaying[CUSTOM_MAX_PLAYERS];
new TrackingCar[CUSTOM_MAX_PLAYERS];
new BoatTestStep[CUSTOM_MAX_PLAYERS];
new TakingBoatTest[CUSTOM_MAX_PLAYERS];
new OpenGateTaxi[CUSTOM_MAX_PLAYERS];
new VipAFKActive[CUSTOM_MAX_PLAYERS];
new Float:LifeDecreaserTmpHP;
new CurrentInformationTmp;
new CurrentInformation;
new gAHeartBeat;
new gABreath;
new PlayerStatusCreated[CUSTOM_MAX_PLAYERS];
new PlayerStatusShowed[CUSTOM_MAX_PLAYERS] = 1;
new PlayerText:PlayerStatus[CUSTOM_MAX_PLAYERS]; // dolny pasek statusu gracza
new gangZoneLoaded[CUSTOM_MAX_PLAYERS];
new AngleOn[CUSTOM_MAX_PLAYERS];
new Camera1On[CUSTOM_MAX_PLAYERS];
new Camera2On[CUSTOM_MAX_PLAYERS];
new IsPlayerTaxiPassenger[CUSTOM_MAX_PLAYERS];
new gTaxiPassengerDistance[CUSTOM_MAX_PLAYERS];
new CheckDelay[CUSTOM_MAX_PLAYERS];
new Alive[CUSTOM_MAX_PLAYERS];
new Text:Status[CUSTOM_MAX_PLAYERS];
new WarTime = 0; // stan wojenny
new WarTimeCountdown; // odliczanie do konca stanu wojennego
new EngineTurningOn[CUSTOM_MAX_PLAYERS];
new noooc = 0;
new nofooc = 0;
new nopwooc = 0;
new gMainGateZomo[2];
new gSpectateID[CUSTOM_MAX_PLAYERS] = { INVALID_PLAYER_ID, ... };
new gSpectateType[CUSTOM_MAX_PLAYERS];
new NewbieTime[CUSTOM_MAX_PLAYERS];
new nonewbie = 0;
new gDice[CUSTOM_MAX_PLAYERS];
new ReduceTime[CUSTOM_MAX_PLAYERS];
new GuardOffer[CUSTOM_MAX_PLAYERS];
new GuardPrice[CUSTOM_MAX_PLAYERS];
new Float:PlayerPos[CUSTOM_MAX_PLAYERS][6];
new JustDied[CUSTOM_MAX_PLAYERS];
new gOOC[CUSTOM_MAX_PLAYERS] = 1;
new gPlayerLogged[CUSTOM_MAX_PLAYERS];
new realchat = 1;
new BigEar[CUSTOM_MAX_PLAYERS];
new RegistrationStep[CUSTOM_MAX_PLAYERS];
new TakingDrivingTestA[CUSTOM_MAX_PLAYERS];
new TakingDrivingTestB[CUSTOM_MAX_PLAYERS];
new TakingDrivingTestCE[CUSTOM_MAX_PLAYERS];
new DrivingTestStep[CUSTOM_MAX_PLAYERS];
new SpawnAttempts[CUSTOM_MAX_PLAYERS];
new FactionRequest[CUSTOM_MAX_PLAYERS];//Where information will be stored regarding faction invites.
new CompanyRequest[CUSTOM_MAX_PLAYERS];
new ShowFuel[CUSTOM_MAX_PLAYERS];
new Mobile[CUSTOM_MAX_PLAYERS] = {255, ...}; //Mobile Phone information will be stored here.
new Muted[CUSTOM_MAX_PLAYERS];
new StartedCall[CUSTOM_MAX_PLAYERS];
new SpeakerPhone[CUSTOM_MAX_PLAYERS];
new gAddCooldown[CUSTOM_MAX_PLAYERS];
new OOCStatus = 0;
new AdminDuty[CUSTOM_MAX_PLAYERS];
new CarWindowStatus[MAX_VEHICLES] = 1;
new WantedLevel[CUSTOM_MAX_PLAYERS];
new PlayerCuffed[CUSTOM_MAX_PLAYERS];
new PlayerTazed[CUSTOM_MAX_PLAYERS];
new DrugsHolding[CUSTOM_MAX_PLAYERS];
new DrugsIntake[CUSTOM_MAX_PLAYERS];
new TrackingPlayer[CUSTOM_MAX_PLAYERS];
new ProductsOffer[CUSTOM_MAX_PLAYERS];
new ProductsAmount[CUSTOM_MAX_PLAYERS];
new ProductsCost[CUSTOM_MAX_PLAYERS];
new gActiveEventList[CUSTOM_MAX_PLAYERS][10];
new gPaydayLaunched = 0;

new cenyPojazdow[212] = {
75000,//400 - Landstalker
15000,//401 - Bravura
207000,//402 - Buffalo
105000,//403 Linerunner
7000,//404 - Perenniel
35000,//405 - Sentinel
200000,//406 - Dumper
130000,//407 - Firetruck
430000,//408 - Trashmaster
560000,//409 - Stretch
12000,//410 - Manana
320000,//411 - Infernus
24000,//412 - Voodoo
50005,//413 - Pony
81500,//414 - Mule
850001,//415 - Cheetah
140000,//416 - Ambulance
1200000,//417 -Leviathan
40000,//418 - Moonbeam
29500,//419 - Esperanto
33000,//420 - Taxi
33000,//421 - Washington
39990,//422 - Bobcat
70000,//423 - Mr Whoopee
76000,//424 - BF Injection
0,//425 - Hunter
22000,//426 - Premier
440000,//427 - Enforcer
400000,//428 - Securicar
790000,//429 - Banshee
120000,//430 - Predator
660000,//431 - Bus
0,//432 - Rhino
640000,//433 - Barracks
71000,//434 - Hotknife
50000,//435 - Article Trailer
18000,//436 - Previon
680000,//437 - Coach
33000,//438 - Cabbie
45000,//439 - Stallion
55000,//440 - Rumpo
0,//441 - RC Bandit
150000,//442 - Romero
250000,//443 - Packer
420000,//444 - Monster
200000,//445 - Admiral
120000,//446 - Squallo
0,//447 - Seasparrow
1000,//448 - Pizzaboy
0,//449 - Tram
0,//450 - Article Trailer 2
820000, //451 Turismo
600000, //452 Speeder
900000, //453 Reefer
1100000, //454 Tropic
250900, //455 tran 15 slot
80050, //456 tran 15 slot
5000, //457
28000, //458
45000, //459 trans 13 slotow
900000, //460
10000, //461
1000, //462
15000, //463
0, //464
0, //465
25000, //466
30000, //467
11000, //468
200000, //469
800000, //470
12000, //471
100000, //472
60000, //473
21000, //474
44000, //475
1350000, //476
730000, //477
4500, //478
20000, //479
690000, //480
250, //481
55000, //482 tran 13 slot
70000, //483
122000, //484
10500, //485
0, //486
820000, //487
720000, //488
77050, //489
200000, //490
21000, //491
24000, //492
350000, //493
350000, //494
200000, //495
40999, //496
400000, //497
41000, //498 tran 12 slot
75000, //499 tran 15 slot
65000, //500
0, //501
350000, //502
350000, //503
350000, //504
74999, //505
780000, //506
34000, //507
200000, //508
250, //509
350, //510
400000, //511
300000, //512
990000, //513
150000, //514 tir 4 slot
140000, //515 tir 4 slot
35000, //516
20500, //517
19500, //518
1800000, //519
0, //520
30000, //521 FCR 900
45000, //522 NRG
60500, //523
620000, //524
101500, //525
23000, //526
19000, //527
600000, //528
23200, //529
5000, //530
1000, //531
215001, //532
52000, //533
32000, //534
30000, //535
31000, //536
0, //537
0, //538
130000, //539
19000, //540
800000, //541
12000, //542
18000, //543 tran 7 slot
740000, //544
200000, //545
14000, //546
10199, //547
1000000, //548
8500, //549
22500, //550
25000, //551
29000, //552
600000, //553
41999, //554 tran 13 slot
300000, //555
500000, //556
500000, //557
500000, //558
620000, //559
600000, //560
44000, //561
430000, //562
1000000, //563
0, //564
150000, //565
27000, //566
30000, //567
55000, //568
0, //569
0, //570
55000, //571
10000, //572
250000, //573
20400, //574
15000, //575
18000, //576
0, //577
160000, //578
71999, //579
20000, //580
25000, //581 BF-400
90000, //582
5000, //583
150000, //584
22000, //585
45000, //586
620000, //587
55000, //588
130000, //589
0, //590
0, //591
1000000, //592
890000, //593
0, //594
590000, //595
90000, //596
90000, //597
90000, //598
85000, //599
16000, //600
500000, //601
690000, //602
710000, //603
1000, //604
1000, //605
0, //606
0, //607
0, //608
55555, //609 tran 13 slot
0, //610
0 //611
};

enum pInfo
{
	pIsNPC,
	pLoading,
	pKey[128],
	pName[64],
	pLevel,
	pAdmin,
	pVipCar,
	pVipAFK,
	pVipAFKT,
	pVipExp,
	pVipExpT,
	pVipItem,
	pDonateRank,
	pRegistered,
	pSex,
	pAge,
	pExp,
	pCash,
	pBank,
	pBankOld,
	pBankNew,
	pBankIncome,
	pBankLoose,
	pPayDayMessage,
	pSkin,
	pDrugs,
	pDrugsEffect,
	pDrugsTaken,
	pDrugsAddicted,
	pJob,
	pJobTimeChange,
	pSeatBelt,
	pSkillLevPis,
	pSkillLevSil,
	pSkillLevDes,
	pSkillLevSho,
	pSkillLevSha,
	pSkillLevSpa,
	pSkillLevMic,
	pSkillLevMp5,
	pSkillLevAk,
	pSkillLevM4,
	pSkillLevSni,
	pSkillPointsPis,
	pSkillPointsSil,
	pSkillPointsDes,
	pSkillPointsSho,
	pSkillPointsSha,
	pSkillPointsSpa,
	pSkillPointsMic,
	pSkillPointsMp5,
	pSkillPointsAk,
	pSkillPointsM4,
	pSkillPointsSni,
	pPozwolenie,
	pTech,
	pLaw,
	pMat,
	pPol,
	pHis,
	pFiz,
	pBio,
	pDoktor,
	pMagister,
	pInz,
	pDowod,
	pPktTech,
	pPktLaw,
	pPktMat,
	pPktPol,
	pPktHis,
	pPktFiz,
	pPktBio,
	pJobLvl, 	 	 	 	 	 	 
	pMzgkJobLvl,
	pSweeperJobLvl,
	pCarJackerJobLvl,
	pMechanicJobLvl,
	pFarmerJobLvl,
	pBusJobPoints,
	pMzgkJobPoints,
	pSweeperJobPoints,
	pCarJackerJobPoints,
	pMechanicJobPoints,
	pFarmerJobPoints,
	pPlayingHours,
	pHourAssist,
	pAllowedPayday,
	pPayCheck,
	pFaction,
	pFaction2,
	pRank,
	pRank2,
	pBizKey,
	pBanned,
	pWarnings,
	pBoatLic,
	pPlaneLic,
	pHeliLic,
	pWepLic,
	pTestAreaTimeLeft, // How much bought time left (minutes) player have in test driving area
	pPenaltyPointsA,
	pPenaltyPointsB,
	pPenaltyPointsCE,
	pPhoneC,//Phone Company (Business ID)
	pPhoneBook,
	pListNumber,
	pDonator,
	pJailed,
	pJailTime,
	pParts,
	Float:pCrashX,
	Float:pCrashY,
	Float:pCrashZ,
	pCrashInt,
	pBoxSkill,
 	pInt,
	pCrashW,
	pCrashed,
	pLoses,
	pWins,
	pMuted,
	pNote1[128],
	pNote1s,
	pNote2[128],
	pNote2s,
	pNote3[128],
	pNote3s,
	pNote4[128],
	pNote4s,
	pNote5[128],
	pNote5s,
	pInvWeapon,
	pInvAmmo,
	pModerator,
	pQuiz,
	pSetToDelete,
	pIsOnVacation,
	pGoggles,
	pCost,
	pTicket,
	pWantedLvl,
	pItem1,
	pItem2,
	pItem3,
	pItem4,
	pItem5,
	pItem1type,
	pItem2type,
	pItem3type,
	pItem4type,
	pItem5type,
	pItem1param,
	pItem2param,
	pItem3param,
	pItem4param,
	pItem5param,
	pItem1param2,
	pItem2param2,
	pItem3param2,
	pItem4param2,
	pItem5param2,
	pItem1param3,
	pItem2param3,
	pItem3param3,
	pItem4param3,
	pItem5param3,
	pItem1param4,
	pItem2param4,
	pItem3param4,
	pItem4param4,
	pItem5param4,
	pItem1param5[64],
	pItem2param5[64],
	pItem3param5[64],
	pItem4param5[64],
	pItem5param5[64],
	pItem1param6,
	pItem2param6,
	pItem3param6,
	pItem4param6,
	pItem5param6,
	pItem6,
	pItem7,
	pItem8,
	pItem9,
	pItem10,
	pItem6type,
	pItem7type,
	pItem8type,
	pItem9type,
	pItem10type,
	pItem6param,
	pItem7param,
	pItem8param,
	pItem9param,
	pItem10param,
	pItem6param2,
	pItem7param2,
	pItem8param2,
	pItem9param2,
	pItem10param2,
	pItem6param3,
	pItem7param3,
	pItem8param3,
	pItem9param3,
	pItem10param3,
	pItem6param4,
	pItem7param4,
	pItem8param4,
	pItem9param4,
	pItem10param4,
	pItem6param5[64],
	pItem7param5[64],
	pItem8param5[64],
	pItem9param5[64],
	pItem10param5[64],
	pItem6param6,
	pItem7param6,
	pItem8param6,
	pItem9param6,
	pItem10param6,
	pItem11,
	pItem12,
	pItem13,
	pItem14,
	pItem15,
	pItem11type,
	pItem12type,
	pItem13type,
	pItem14type,
	pItem15type,
	pItem11param,
	pItem12param,
	pItem13param,
	pItem14param,
	pItem15param,
	pItem11param2,
	pItem12param2,
	pItem13param2,
	pItem14param2,
	pItem15param2,
	pItem11param3,
	pItem12param3,
	pItem13param3,
	pItem14param3,
	pItem15param3,
	pItem11param4,
	pItem12param4,
	pItem13param4,
	pItem14param4,
	pItem15param4,
	pItem11param5[64],
	pItem12param5[64],
	pItem13param5[64],
	pItem14param5[64],
	pItem15param5[64],
	pItem11param6,
	pItem12param6,
	pItem13param6,
	pItem14param6,
	pItem15param6,
	pItem16,
	pItem17,
	pItem18,
	pItem19,
	pItem20,
	pItem16type,
	pItem17type,
	pItem18type,
	pItem19type,
	pItem20type,
	pItem16param,
	pItem17param,
	pItem18param,
	pItem19param,
	pItem20param,
	pItem16param2,
	pItem17param2,
	pItem18param2,
	pItem19param2,
	pItem20param2,
	pItem16param3,
	pItem17param3,
	pItem18param3,
	pItem19param3,
	pItem20param3,
	pItem16param4,
	pItem17param4,
	pItem18param4,
	pItem19param4,
	pItem20param4,
	pItem16param5[64],
	pItem17param5[64],
	pItem18param5[64],
	pItem19param5[64],
	pItem20param5[64],
	pItem16param6,
	pItem17param6,
	pItem18param6,
	pItem19param6,
	pItem20param6,
	pItem21,
	pItem22,
	pItem23,
	pItem24,
	pItem25,
	pItem21type,
	pItem22type,
	pItem23type,
	pItem24type,
	pItem25type,
	pItem21param,
	pItem22param,
	pItem23param,
	pItem24param,
	pItem25param,
	pItem21param2,
	pItem22param2,
	pItem23param2,
	pItem24param2,
	pItem25param2,
	pItem21param3,
	pItem22param3,
	pItem23param3,
	pItem24param3,
	pItem25param3,
	pItem21param4,
	pItem22param4,
	pItem23param4,
	pItem24param4,
	pItem25param4,
	pItem21param5[64],
	pItem22param5[64],
	pItem23param5[64],
	pItem24param5[64],
	pItem25param5[64],
	pItem21param6,
	pItem22param6,
	pItem23param6,
	pItem24param6,
	pItem25param6,
	pCharacterDeath,
	pCharacterDying,
	Float:pHP,
	Float:pArmour,
	bool:SpawnDance,
	Float:SpawnAngle,
	SpawnTimer,
	pHead,
	pLegs,
	pTorso,
	pUzaleznienie,
	pDetoks,
	pAccountOwnerID,
	pOOCName[255],
	pFirstCar,
	pFirstReanimation,
	pFirstPhone,
	pFirstLeader,
	pFirstJob,
	pFirstID,
	pFirstBuy,
	pFirstHouse,
	pFirstDescription,
	pFirstAction,
	pFirstBankUse,
	pFirstStats,	
	pFirstJail,
	pFirstStudy,
	pAchieveTickets,
	pAchieveArrests,
	pAchieveDistance,
	Float:pCrashAngle,
	pDuty,
	pWSlot0,
	pWSlot0Ammo,
	pWSlot1,
	pWSlot1Ammo,
	pWSlot2,
	pWSlot2Ammo,
	pWSlot3,
	pWSlot3Ammo,
	pWSlot4,
	pWSlot4Ammo,
	pWSlot5,
	pWSlot5Ammo,
	pWSlot6,
	pWSlot6Ammo,
	pWSlot7,
	pWSlot7Ammo,
	pWSlot8,
	pWSlot8Ammo,
	pWSlot9,
	pWSlot9Ammo,
	pWSlot10,
	pWSlot10Ammo,
	pWSlot11,
	pWSlot11Ammo,
	pWSlot12,
	pWSlot12Ammo,
	pJoinedFaction,
	pHoursOnDutyHelper,
	pHoursOnDuty,
	pRPCount,
	pDeathCount,
	pScore,
	pMechanicCoolDown,
	pFirstATest,
	pFirstBTest,
	pFirstCETest,
	pMaxWeight, // used or not ?
	pPartType, // what player will made from parts ( 0 - null, 1 - weapon, 2 - main part, 3 - ammo )
	pPartItem, // id of what player will made
	pMountsLeft, // how many command enter left befor weapon, part or ammo will be released
	pMountsPasses, // recurence, how many times function should pass itself (and degreade this value till 0 )
	pWFOrderedCount, // how many weapons player ordered in legal factory
	pSpeedGunOn, // status of speed gun
	Float:pGasStationRefPetrol[MAX_BUSINESSES], // how much petrol is refueled
	Float:pGasStationRefOil[MAX_BUSINESSES], // how much oil is refueled
	Float:pGasStationRefGas[MAX_BUSINESSES], // how much gas is refueled
	pSName[32], // player name on starting login used for check player correct
	pSellerJobOn, // is player on job duty and generate reward
	pMountingW, // is player mounting sth in weapon factory
	pVipGarage, // how many garages player car place
	pVipGarageBig, // how many big garages player car place
	pLoggedToday, // did player logged after last payday
	// pPenaltyRP, // how much RP points player 
	pVipRedNeon, // count of neons to attach to veh
	pVipBlueNeon,
	pVipGreenNeon,
	pVipYellowNeon,
	pVipPinkNeon,
	pVipWhiteNeon,
	pVipHalogenLight,
	pVipWhitePointLight,
	pVipRedPointLight,
	pVipGreenPointLight,
	pVipBluePointLight,
	pPWStatus, // is PW for player ON
	pOOCStatus, // is OOC for player ON
	pJoinInfoStatus, // is info for player when other player join server ON
	pLeaveInfoStatus, // is info for player when other player leave server ON
	pTipsStatus, // is tips for player ON
	pBackgroundSoundStatus, // is backgroud sound for player ON
	pWarnCooldown, // paydays before warn gone
	pSpeedLimiter,
	pLawyerLvl,
	pLawyerPts,
	Float:pHunger, // 0 -100
	Float:pThirst, // 0 -100
	Float:pPoison, // 0 -100
	Float:pFat, // 0 -100
	Float:pStomach, // 0 -100
	Float:pVitamins, // 0 -100	
	Float:pEnergy, // 0 -100
	Float:pDrunk, // 0 -100
	Float:pNarcotic, // 0 -100
	Bar:pHungerProgressBarID,
	Bar:pThirstProgressBarID,
	Bar:pPoisonProgressBarID,
	Bar:pFatProgressBarID,
	Bar:pStomachProgressBarID,
	Bar:pVitaminsProgressBarID,
	Bar:pEnergyProgressBarID,
	Bar:pDrunkProgressBarID,
	Bar:pNarcoticProgressBarID,
	pShowHealthBars,
	pVipCustomObjects, // how much objects slot player can use
	Text3D:pCharDescriptionID, // 3D Text label of player character description
	Text3D:pCharNameID, // 3D Text label of player character name
	pCharDescription[64], // character description displaying above character
	pCharDescriptionColor[32],  // color of text
	pSubMealEaten, // how many snacks, candys, etc. player eated betweene main meal
	pIsDeptor, // is player in debt ?
	pLastLogged, // is player logged after last payday ?
	pOOCChanell, // in what chanel player is - 0 is main/default
	pNewVersion, // if new version is uploaded player will be informed about new changes
	pPainKiller, // is pain killer activated and how much time is left (min)
	pSlimming, // is slimming tab active and how much time is left (min)
	pStomachDrops, // is stomach drops used, how many times, decrease after 1 hour
	pMapIcons[MAX_BUSINESSES+MAX_BUILDINGS], // ids of icons
	mPickupEventPickupStatus[sizeof(gPickupEventData)],
	mPickupEventID,
	mPickupEventRewardReceived,
	mCreditRepayment,
	mCreditValue,
	mCreditPayed,
	robbingHouseStage,
	pHighSchool,
	pSchoolCooldown,
	mBroadCastMessages,
	pIsLogged
};
new gPlayerData[CUSTOM_MAX_PLAYERS+1][pInfo];

enum playerVars
{
	lPoliceComputerPID,
	lPoliceComputerPCat,
	lPoliceComputerPName[MAX_PLAYER_NAME],
	mHealID,
	mExamineID,
	mAntiCheatTimer,
	mPlayerControllable,
	mAtHouseID,
	mAtBuildingId,
	mAtBizID,
	mAtCamperId,
	mPhoneSimID,																// sim ID
	mPhoneDataReceived, 												// czy uzyskano dane z bazy - ma zapobiec desynchronizacji
	mPhoneDataTimeout, 													// czy uzyskano dane z bazy - ma zapobiec desynchronizacji
	mPhoneType, 																	// sim type - prepaid or fee
	mPhoneFaction,
	mPhoneCash,																	// prepaid cash left
	mPhoneRenewalTime,													// prepaid time left
	mPhoneNr,
	mGlobalSms[256],															// used to contain sms for all players
	mGlobalSmsSenderNumber,
	mPickupEventPickups[sizeof(gPickupEventData)],					// id of event pickups
	mQuizQuestionNo,
	mQuizQuestionSet,
	mQuizWrongAnsweres,
	mFuelType,																		// used for ImportVeh function
	Float:mVehMaxHealth,														// used for ImportVeh function
	Text:mVehicleStatus, 														// dolny pasek statusu pojazdu
	mVehicleStatusShow,															// status dolnego pasku statusu pojazdu
	mVehicleStatusShowChanged,
	PlayerText:mSanNewsTextDrawId,														// dolny pasek informacyjny san news
	mSanNewsTextDrawCreated,														// dolny pasek informacyjny san news
	mSanNewsStatus,														// status dolneg pasku informacyjnego san news
	mJumped,																			// how many times player jumped while walking
	mSprinting,
	mSelectedRace,																// race dialog id
	mSelectedRaceList[MAX_RACES],								// id of avaiable races
	Text:mRacePlace1Info,
	Text:mRacePlace2Info,
	Text:mRacePlace3Info,
	Text:mRacePlace4Info,
	Text:mRacePlace5Info,
	Text:mRacePlace6Info,
	Text:mRacePlace7Info,
	Text:mRacePlace8Info,
	Text:mRacePlace9Info,
	Text:mRacePlace10Info,
	mIsPlayerHouseJacking,
	mIsPlayerBizJacking,
	mPassTries,
	mBulletProof,
	mBugInfoCoolDown,
	mNewbieCoolDown,
	mRobbingHouseStage,
	mRobbingBusinessStage,
	mJustEnteredVehicle,
	mBusTicketBuyTime,
	mClotheShopSkinId,
	mAtClotheStore,
	mEditRank,							// which rank leader is edditing
	mEditObj,
	mMaterialId,
	mObjText[128],
	mRepairProgress,				// player vehicle repair progress
	mRepairingItemId,				// default type always is one
	mRepairingItemType,				// default type always is one
	mBulbToChange,
	mWheelToChange,
	mBizIdIntEdit,
	mBuildingBuyId,
	mIsReanimate,
	Float:measurePointX,
	Float:measurePointY,
	Float:measurePointZ,
	Float:tempPosX,
	Float:tempPosY,
	Float:tempPosZ,
	tempInterior,
	tempWorld,
	tempVehId,
	tempVehSeat,
	mIsInTaxiTeleportId,
	PlayerText:mWardrobeExitText,
	mTaxiTeleportTimeLeft,
	Timer:mIdleAnimationTimer,
	bool:mIsIdleAnimationTimerActive
};
new gPlayerVars[CUSTOM_MAX_PLAYERS+1][playerVars];

timer ReturnPlayerFromTempPos[5000](playerid)
{
	gPlayerData[playerid][pCrashX] = gPlayerVars[playerid][tempPosX];
	gPlayerData[playerid][pCrashY] = gPlayerVars[playerid][tempPosY];
	gPlayerData[playerid][pCrashZ] = gPlayerVars[playerid][tempPosZ];
	gPlayerData[playerid][pCrashInt] = gPlayerVars[playerid][tempInterior];
	gPlayerData[playerid][pCrashW] = gPlayerVars[playerid][tempWorld];
	
	SetPlayerToPos(playerid, gPlayerData[playerid][pCrashX], gPlayerData[playerid][pCrashY], gPlayerData[playerid][pCrashZ]);
	SetPlayerVirtualWorld(playerid, gPlayerData[playerid][pCrashW]);
	SetPlayerInterior(playerid, gPlayerData[playerid][pCrashInt]);

	if(gPlayerVars[playerid][tempVehId] != 0)
	{
		PutPlayerInVehicle(playerid, gPlayerVars[playerid][tempVehId], gPlayerVars[playerid][tempVehSeat]);
	}
}

enum Cars
{
	mVehModel,
	Float:mVehX,
	Float:mVehY,
	Float:mVehZ,
	Float:mVehA,
	mVehInt,
	mVehVW,
	mVehColor1,
	mVehColor2,
	mVehPaintJob,
	mVehFaction,
	mVehVinNo,
	mVehType,
	mVehOwned,
	Owner[128],
	Price,
	mRenter[MAX_PLAYER_NAME],
	mRentPrice,
	mRentPenalty,
	Closed,
	CarResetT,
	CarDamaged,
	CarRepairTimeLeft,
	BusinessID,
	Float:CarFuel,
	Float:CarHealth,
	ReadyToSell,
	CarCounter,
	CarCounterPrev, // previous traveled distance to get difference and count combustion of car based on combustion ltr/km
	Fuel,
	CarPanels,
	CarDoors,
	CarLights,
	CarTires,
	LastDriverWKey[128],
	CarSerial,
	PaintStep,
	WheelStep,
	EngineOn,
	LightsOn,
	BonnetUp,
	BootUp,
	RadioOn, // Status of radio (on/off)
	Hook, // Status of hook (mouted/unmouted)
	Alarm, // Status of alarm (mouted/umouted)
	GasStep, // Step of mouting gas installation
	TankerResourceType, // Type of tanker resource type (ex. oil)
	TankerResourceValue, // The amount of given type resource
	TankerIsRefueling, // Status of tanker refueling (on/off)
	EngineTemp, // If temp equals 10 points and car is damaged in 50% then it must cool down to 5 to launch it
	CustomObj1ID,
	CustomObj1Model,
	CustomObj1On,
	Float:CustomObj1[6], // custom object ex. neons
	CustomObj2ID,
	CustomObj2Model,
	CustomObj2On,
	Float:CustomObj2[6],
	CustomObj3ID,
	CustomObj3Model,
	CustomObj3On,
	Float:CustomObj3[6],
	CustomObj4ID,
	CustomObj4Model,
	CustomObj4On,
	Float:CustomObj4[6],
	CustomObj5ID,
	CustomObj5Model,
	CustomObj5On,
	Float:CustomObj5[6],
	CustomObj6ID,
	CustomObj6Model,
	CustomObj6On,
	Float:CustomObj6[6],
	CustomObj7ID,
	CustomObj7Model,
	CustomObj7On,
	Float:CustomObj7[6],
	RadioVol,
	Float:BatteryCapacity, // vehicle battery for launching engine or 
	Float:BatteryMaxCapacity,
	BatteryID,									// Default 0, higher values means new mouted battery (replacement) and ItemName is used
	Text3D:Veh3DSell,
	Veh3DSellCreated,
	Text3D:Veh3DSerial,
	Text3D:Veh3DTaxiNfo,
	Text3D:Veh3DTaxiNfo2,
	IsRefueling, // is veh refueling
	VConfiscated, // is veh confiscated ?
	VPoliceComputer, // has veh police computer ?
	VCBRadio, // has veh cb radio ?
	VCBRadioChanel, // has veh cb radio ?
	VCBRadioStatus, // has veh cb radio ?
	VItem1,
	VItem2,
	VItem3,
	VItem4,
	VItem5,
	VItem6,
	VItem7,
	VItem8,
	VItem9,
	VItem10,
	VItem11,
	VItem12,
	VItem13,
	VItem14,
	VItem15,
	VItem1type,
	VItem2type,
	VItem3type,
	VItem4type,
	VItem5type,
	VItem6type,
	VItem7type,
	VItem8type,
	VItem9type,
	VItem10type,
	VItem11type,
	VItem12type,
	VItem13type,
	VItem14type,
	VItem15type,
	VItem1param,
	VItem2param,
	VItem3param,
	VItem4param,
	VItem5param,
	VItem6param,
	VItem7param,
	VItem8param,
	VItem9param,
	VItem10param,
	VItem11param,
	VItem12param,
	VItem13param,
	VItem14param,
	VItem15param,
	VItem1param2,
	VItem2param2,
	VItem3param2,
	VItem4param2,
	VItem5param2,
	VItem6param2,
	VItem7param2,
	VItem8param2,
	VItem9param2,
	VItem10param2,
	VItem11param2,
	VItem12param2,
	VItem13param2,
	VItem14param2,
	VItem15param2,
	VItem1param3,
	VItem2param3,
	VItem3param3,
	VItem4param3,
	VItem5param3,
	VItem6param3,
	VItem7param3,
	VItem8param3,
	VItem9param3,
	VItem10param3,
	VItem11param3,
	VItem12param3,
	VItem13param3,
	VItem14param3,
	VItem15param3,
	VItem1param4,
	VItem2param4,
	VItem3param4,
	VItem4param4,
	VItem5param4,
	VItem6param4,
	VItem7param4,
	VItem8param4,
	VItem9param4,
	VItem10param4,
	VItem11param4,
	VItem12param4,
	VItem13param4,
	VItem14param4,
	VItem15param4,
	VItem1param5[64],
	VItem2param5[64],
	VItem3param5[64],
	VItem4param5[64],
	VItem5param5[64],
	VItem6param5[64],
	VItem7param5[64],
	VItem8param5[64],
	VItem9param5[64],
	VItem10param5[64],
	VItem11param5[64],
	VItem12param5[64],
	VItem13param5[64],
	VItem14param5[64],
	VItem15param5[64],
	VItem1param6,
	VItem2param6,
	VItem3param6,
	VItem4param6,
	VItem5param6,
	VItem6param6,
	VItem7param6,
	VItem8param6,
	VItem9param6,
	VItem10param6,
	VItem11param6,
	VItem12param6,
	VItem13param6,
	VItem14param6,
	VItem15param6,
	mVehSpoiler,
	mVehHood,
	mVehRoof,
	mVehSideskirt,
	mVehLamps,
	mVehNitro,
	mVehExhaust,
	mVehWheels,
	mVehStereo,
	mVehHydraulics,
	mVehFrontBumper,
	mVehRearBumper,
	mVehVentLeft,
	mVehVentRight,
	mVehTransportSlot1,
	mVehTransportSlot2,
	mVehTransportSlot3,
	mVehTransportSlot4,
	mVehIgnitionHacked,
	mVehIgnitionDamaged,
	mVehSirenObjId,
	mVehSirenObjModel,
	mVehSirenState,
	mVehSetToTp
};
new gVehData[2000][Cars];
new gVSelectedItemP5[sizeof(gVehData)];
new Float:VehNewPos[sizeof(gVehData)][3];
new VehJustRespawned[sizeof(gVehData)];
new isPainting[sizeof(gVehData)];
new isWheelChanging[sizeof(gVehData)];
new isGasMounting[sizeof(gVehData)];
new Text3D:BusRoute[sizeof(gVehData)];

enum Factions
{
	Name[50],
	mCompanyName[64],
	IsEnabled, // Is faction enabled ? 
	Float:m_fX,
	Float:m_fY,
	Float:m_fZ,
	fBank,
	fRank1[35],
	fRank2[35],
	fRank3[35],
	fRank4[35],
	fRank5[35],
	fRank6[35],
	fRank7[35],
	fRank8[35],
	fRank9[35],
	fRank10[35],
	fRank2TillCheck,
	fRank2FactionStatus,
	fRank2VehBuy,
	fRank2VehSell,
	fRank2VehSalvage,
	fRank2VehDrive,
	fRank2TerritoryWar,
	fRank2BurnFactory,
	fRank3TillCheck,
	fRank3FactionStatus,
	fRank3VehBuy,
	fRank3VehSell,
	fRank3VehSalvage,
	fRank3VehDrive,
	fRank3TerritoryWar,
	fRank3BurnFactory,
	fRank4TillCheck,
	fRank4FactionStatus,
	fRank4VehBuy,
	fRank4VehSell,
	fRank4VehSalvage,
	fRank4VehDrive,
	fRank4TerritoryWar,
	fRank4BurnFactory,
	fRank5TillCheck,
	fRank5FactionStatus,
	fRank5VehBuy,
	fRank5VehSell,
	fRank5VehSalvage,
	fRank5VehDrive,
	fRank5TerritoryWar,
	fRank5BurnFactory,
	fRank6TillCheck,
	fRank6FactionStatus,
	fRank6VehBuy,
	fRank6VehSell,
	fRank6VehSalvage,
	fRank6VehDrive,
	fRank6TerritoryWar,
	fRank6BurnFactory,
	fRank7TillCheck,
	fRank7FactionStatus,
	fRank7VehBuy,
	fRank7VehSell,
	fRank7VehSalvage,
	fRank7VehDrive,
	fRank7TerritoryWar,
	fRank7BurnFactory,
	fRank8TillCheck,
	fRank8FactionStatus,
	fRank8VehBuy,
	fRank8VehSell,
	fRank8VehSalvage,
	fRank8VehDrive,
	fRank8TerritoryWar,
	fRank8BurnFactory,
	fRank9TillCheck,
	fRank9FactionStatus,
	fRank9VehBuy,
	fRank9VehSell,
	fRank9VehSalvage,
	fRank9VehDrive,
	fRank9TerritoryWar,
	fRank9BurnFactory,
	fRank10TillCheck,
	fRank10FactionStatus,
	fRank10VehBuy,
	fRank10VehSell,
	fRank10VehSalvage,
	fRank10VehDrive,
	fRank10TerritoryWar,
	fRank10BurnFactory,
	fSkin1,
	fSkin2,
	fSkin3,
	fSkin4,
	fSkin5,
	fSkin6,
	fSkin7,
	fSkin8,
	fSkin9,
	fSkin10,
	fJoinRank,
	fUseSkins,
	fType,//For Government factions etc
	fRankAmount,
	fCP, // checkpoint
	fCP2,
	fColor[128],
	fUseColor,
	fMaxCars,
	fCarsCount,
	fTerritoryWarWins,
	fTerritoryWarLooses,
	Float:fXDuty,
	Float:fYDuty,
	Float:fZDuty,
	fWorldDuty,
	fInteriorDuty,
	Float:fXDuty2,
	Float:fYDuty2,
	Float:fZDuty2,
	fWorldDuty2,
	fInteriorDuty2,
	fCarsRank, // From which rank player can enter vehicle
	fTaxiKMCost, // price for 1km  passenger drive
	fTaxiEnterCost, // price for entrance a taxi
	fHealCost, // basics cost for medicaments etc set by admin
	fHealPrice, // how much player must pay for medical attention
	fExamineCost, // basics cost for medicaments etc set by admin
	fExaminePrice, // how much player must pay for medicat attention
	mSimActivationCost,
	mSimDailyFee,
	mSimFreeMins,
	mSimFreeSms,
	mCallCostFee,
	mSmsCostFee,
	mCallCostCard,
	mSmsCostCard,
	mCardValidity,
	mCardRenewCost1,
	mCardRenewTime1,
	mCardRenewCost2,
	mCardRenewTime2,
	mCardRenewCost3,
	mCardRenewTime3,
	mCardRenewCost4,
	mCardRenewTime4,
	mVehicleStealExportTimeLeft,
	mVehicleStealExportCpId,
	Float:mBizConIncome,
	Float:mBizOfferIncome,
	mBizJoinCash, // how much does company offer for new business when it join to company
	mBizJoinTime, // how long biz must represent company if it doesnt want to pay penalty
	mBizPenaltyValue, // how much penalty cost
	mPayOffGranted,
	mMechanicJobsDone, // TODO: dodac obsluge
	fNotification1,	
	fNotification2,
	fNotification3,
	fNotification4,
	fNotification5,
	fNotification1ID,
	fNotification2ID,
	fNotification3ID,
	fNotification4ID,
	fNotification5ID,
	fGun1Rank1,
	fGun1Rank2,
	fGun1Rank3,
	fGun1Rank4,
	fGun1Rank5,
	fGun1Rank6,
	fGun1Rank7,
	fGun1Rank8,
	fGun1Rank9,
	fGun1Rank10,
	fGun2Rank1,
	fGun2Rank2,
	fGun2Rank3,
	fGun2Rank4,
	fGun2Rank5,
	fGun2Rank6,
	fGun2Rank7,
	fGun2Rank8,
	fGun2Rank9,
	fGun2Rank10,
	fGun3Rank1,
	fGun3Rank2,
	fGun3Rank3,
	fGun3Rank4,
	fGun3Rank5,
	fGun3Rank6,
	fGun3Rank7,
	fGun3Rank8,
	fGun3Rank9,
	fGun3Rank10,
	fAmmo1Rank1,
	fAmmo1Rank2,
	fAmmo1Rank3,
	fAmmo1Rank4,
	fAmmo1Rank5,
	fAmmo1Rank6,
	fAmmo1Rank7,
	fAmmo1Rank8,
	fAmmo1Rank9,
	fAmmo1Rank10,
	fAmmo2Rank1,
	fAmmo2Rank2,
	fAmmo2Rank3,
	fAmmo2Rank4,
	fAmmo2Rank5,
	fAmmo2Rank6,
	fAmmo2Rank7,
	fAmmo2Rank8,
	fAmmo2Rank9,
	fAmmo2Rank10,
	fAmmo3Rank1,
	fAmmo3Rank2,
	fAmmo3Rank3,
	fAmmo3Rank4,
	fAmmo3Rank5,
	fAmmo3Rank6,
	fAmmo3Rank7,
	fAmmo3Rank8,
	fAmmo3Rank9,
	fAmmo3Rank10,
	WFactoryBuildingID,
	WFactoryObjects[32], // factory objects ids
	WFactoryDObjects[115], // destroyed factory objects ids
	WFactoryEnabled, // Is factory working (not intercepted by ex. police)
	WFactoryBurning, // Is factory burning
	WFactoryJustBought, // Factory has just been ordered by leader of faction
	WFactoryCPPartTakeID,
	WFactoryCPSafeID,
	Float:WFactoryCentrePosX, // relative centre of building X
	Float:WFactoryCentrePosY, // relative centre of building Y
	Float:WFactoryCentrePosZ, // relative centre of building Z
	WFactoryCPPartSetup1ID,
	WFactoryCPPartSetup2ID,
	WFactoryCPPartSetup3ID,
	WFactoryCPPartSetup4ID,
	WFactoryCPPartSetup5ID,
	WFactoryCPPartSetup6ID,
	WFactoryCPPartSetup7ID,
	WFactoryCPPartSetup8ID,
	WFactoryCPAmmoPartSetup1ID,
	WFactoryCPAmmoPartSetup2ID,
	WFactoryCPSubPartSetup3ID,
	WFactoryCPSubPartSetup4ID,
	WFactoryCPSubPartSetup5ID,
	WFactoryCPSubPartSetup6ID,
	WFactory9MM,
	WFactory9MMSil,
	WFactoryDesEagle,
	WFactoryMicroSMG,
	WFactoryMP5,
	WFactoryTec9,
	WFactoryShotgun,
	WFactoryAK47,
	WFactoryM4,
	WFactoryRifle,
	WFactorySRifle,
	WFactorySCharge,
	WFactory9MMAmmo,
	WFactory50AEAmmo,
	WFactoryBuckshot,
	WFactory762MMAmmo,
	WFactory127MMAmmo,
	WFactoryKGP66MMAmmo,
	WFactoryNapalm,
	WFactoryPistolPart1, // id 48
	WFactoryPistolS1Part1, // id 61
	WFactoryPistolS1Part2, // id 62
	WFactoryPistolS1Part3, // id 63
	WFactoryPistolPart2, // id 49
	WFactoryPistolS2Part1, // id 64
	WFactoryPistolS2Part2, // id 65
	WFactoryPistolS2Part3, // id 66
	WFactoryPistolPart3, // id 50
	WFactoryPistolS3Part1, // id 67
	WFactoryPistolS3Part2, // id 68
	WFactoryPistolS3Part3, // id 69
	WFactoryPistolS3Part4, // id 70
	WFactoryPistolPart4, // id 51
	WFactoryPistolPart5, // id 52
	WFactoryPistolPart6, // id 59 tlumik jako ostatni
	WFactoryRiflePart1, // id 53
	WFactoryRifleS1Part1, // id 71
	WFactoryRifleS1Part2, // id 72
	WFactoryRiflePart2, // id 54
	WFactoryRifleS2Part1, // id 73
	WFactoryRifleS2Part2, // id 74
	WFactoryRifleS2Part3, // id 75
	WFactoryRiflePart3, // id 55
	WFactoryRifleS3Part1, // id 76
	WFactoryRifleS3Part2, // id 77
	WFactoryRifleS3Part3, // id 78
	WFactoryRifleS3Part4, // id 79
	WFactoryRiflePart4, // id 56
	WFactoryRiflePart5, // id 57
	WFactoryRiflePart6, // id 58
	WFactoryRiflePart7, // id 60
	WFactoryRifleS6Part1, // id 80
	WFactoryRifleS6Part2, // id 81	
	WFactoryAmmoPart1a, // id 43
	WFactoryAmmoPart2a, // id 44
	WFactoryAmmoPart3a, // id 45
	WFactoryAmmoPart4a, // id 46
	WFactoryAmmoPart1b, // id 47
	WFactoryAmmoPart2b, // id 90
	WFactoryAmmoPart3b, // id 91
	WFactoryAmmoPart4b, // id 92
	WFactoryAmmoPart1c, // id 93
	WFactoryAmmoPart2c, // id 94
	WFactoryAmmoPart3c, // id 95
	WFactoryAmmoPart4c, // id 96
	WFactoryAmmoPart1d, // id 97
	WFactoryAmmoPart2d, // id 98
	WFactoryAmmoPart3d, // id 99
	WFactoryAmmoPart4d, // id 100
	WFactoryAmmoPart1e, // id 101
	WFactoryAmmoPart2e, // id 102
	WFactoryAmmoPart3e, // id 103
	WFactoryAmmoPart4e, // id 104
	WFactoryTec9Part, // id 82
	WFactoryMP5Part, // id 83
	WFactoryAK47Part, // id 84
	WFactoryM4Part, // id 85
	WFactoryShotPart, // id 86
	WFactoryDesEaglePart, // id 87
	WFactoryRiflePart, // 88
	WFactorySniperPart // id 89
};
new DynamicFactions[500][Factions];

enum CivilianSpawns
{
	Float:X,
	Float:Y,
	Float:Z,
	World,
	Interior,
	Float:Angle
};
new CivilianSpawn[CivilianSpawns];

enum DrivingTestLocation
{
	Float:mPosXA,
	Float:mPosYA,
	Float:mPosZA,
	mPosWorldA,
	mPosInteriorA,
	Float:mPosXB,
	Float:mPosYB,
	Float:mPosZB,
	mPosWorldB,
	mPosInteriorB,
	Float:mPosXCE,
	Float:mPosYCE,
	Float:mPosZCE,
	mPosWorldCE,
	mPosInteriorCE,
	mPriceA,
	mPriceB,
	mPriceCE,
	mPriceLowA,
	mPriceLowB,
	mPriceLowCE,
	PickupIDA,
	PickupIDB,
	PickupIDCE
};
new gDrivingTestPosition[DrivingTestLocation];

enum BoatTestLocation
{
	Float:X,
	Float:Y,
	Float:Z,
	World,
	Interior,
	Float:Angle,
	PickupID
};
new BoatTestPosition[BoatTestLocation];

enum BankLocation
{
	Float:X,
	Float:Y,
	Float:Z,
	World,
	Interior,
	Float:Angle,
	mPickupId
};
new BankPosition[14][BankLocation] = 
{
	{ 1322.546630, 120.573074, 1003.219360 },
	{ -470.957550, -199.424087, 985.378356 },
	{ 1442.93, -994.01, 26.82 },
	{ 1444.84, -996.32, 26.82 },
	{ 1448.49, -997.13, 26.82 },
	{ 331.16, 129.57, 1007.96 },
	{ 327.65, 130.92, 1007.96 },
	{ 324.42, 132.02, 1007.96 },
	{ 1318.51, 120.56, 1003.21 },
	{ 1322.53, 120.56, 1003.21 },
	{ 1327.04, 120.56, 1003.21 },
	{ 304.85, 1854.31, 1613.36 },
	{ 599.26, -1512.62, 15.42 },
	{ 599.26, -1518.64, 15.42 }
};



enum SkillPositionInfo
{
	Float:XPis,
	Float:YPis, 
	Float:ZPis, 
	Float:XSil,
	Float:YSil, 
	Float:ZSil,
	Float:XDes,
	Float:YDes, 
	Float:ZDes,
	Float:XSho,
	Float:YSho, 
	Float:ZSho,
	Float:XSha,
	Float:YSha, 
	Float:ZSha,
	Float:XSpa,
	Float:YSpa, 
	Float:ZSpa,
	Float:XMic,
	Float:YMic, 
	Float:ZMic,
	Float:XMp5,
	Float:YMp5, 
	Float:ZMp5,
	Float:XAk,
	Float:YAk, 
	Float:ZAk,
	Float:XM4,
	Float:YM4, 
	Float:ZM4,
	Float:XSni,
	Float:YSni, 
	Float:ZSni,
	Float:XTech,
	Float:YTech, 
	Float:ZTech,
	Float:XLaw,
	Float:YLaw, 
	Float:ZLaw,
	Float:XMat,
	Float:YMat, 
	Float:ZMat,
	Float:XPol,
	Float:YPol, 
	Float:ZPol,
	Float:XHis,
	Float:YHis, 
	Float:ZHis,
	Float:XFiz,
	Float:YFiz, 
	Float:ZFiz,
	Float:XBio,
	Float:YBio, 
	Float:ZBio,
	Float:XHighSchool,
	Float:YHighSchool, 
	Float:ZHighSchool,
	PickupIDPis,
	PickupIDSil,
	PickupIDDes,
	PickupIDSho,
	PickupIDSha,
	PickupIDSpa,
	PickupIDMic,
	PickupIDMp5,
	PickupIDAk,
	PickupIDM4,
	PickupIDSni,
	PickupIDTech,
	PickupIDLaw,
	PickupIDMat,
	PickupIDPol,
	PickupIDHis,
	PickupIDFiz,
	PickupIDBio,
	PickupIDHighSchool
};
new SkillPosition[SkillPositionInfo];

enum FlyingTestLocation
{
	Float:mPosX,
	Float:mPosY,
	Float:mPosZ,
	mPosW,
	mPosInt,
	Float:mPosA,
	PickupID
};
new gPlaneTestPosition[FlyingTestLocation];

enum WeaponLicenseLocation
{
	Float:X,
	Float:Y,
	Float:Z,
	World,
	Interior,
	Float:Angle,
	PickupID
};
new WeaponLicensePosition[WeaponLicenseLocation];

enum BuildingSystem
{
	BuildingName[128],
	FactionOwnerId,
	Cash,
	Price,
	StreetNo,
	ForSale,
	Float:EnterX,
	Float:EnterY,
	Float:EnterZ,
	EntranceFee,
	EnterWorld,
	EnterInterior,
	Float:EnterAngle,
	Float:ExitX,
	Float:ExitY,
	Float:ExitZ,
	ExitInterior,
	Float:ExitAngle,
	Locked,
	EnterPickupId,
	ExitPickupId,
	Opened,
	Closed,
	ObjectID,
	BuildingType,
	ShowIcon,
	IconType,
	mBuildingPlaced
};
new Building[MAX_BUILDINGS][BuildingSystem];
new Text3D:Buildings3DTextLabelA[sizeof(Building)];
new Text3D:Buildings3DTextLabelB[sizeof(Building)];
new Text3D:Buildings3DTextLabelC[sizeof(Building)];

enum BusinessSystem
{
	BusinessName[128],
	BUID,
	Owner[MAX_PLAYER_NAME],
	mFaction,
	mFactionTimeLeft, // how long to end of company contract
	StreetNo,
	Float:EnterX,
	Float:EnterY,
	Float:EnterZ,
	EnterWorld,
	EnterInterior,
	Float:EnterAngle,
	Float:ExitX,
	Float:ExitY,
	Float:ExitZ,
	ExitInterior,
	Float:ExitAngle,
	Owned,
	Enterable,
	BizPrice,
	EntranceCost,
	Till,
	Locked,
	BizType,
	PickupID,
	ExitPickupId,
	Products,
	VehicleSpawned,
	VehicleCount,
	MaxVehicles,
	VehicleOrderCount,
	SalesJob,
	W9MM,
	mW9MMIncomeTotal,
	mW9MMIncomeToday,
	W9MMSil,
	mW9MMSilIncomeTotal,
	mW9MMSilIncomeToday,
	WDesEagle,
	mWDesEagleIncomeTotal,
	mWDesEagleIncomeToday,
	WMicroSMG,
	mWMicroSMGIncomeTotal,
	mWMicroSMGIncomeToday,
	WMP5,
	mWMP5IncomeTotal,
	mWMP5IncomeToday,
	WTec9,
	mWTec9IncomeTotal,
	mWTec9IncomeToday,
	WShotgun,
	mWShotgunIncomeTotal,
	mWShotgunIncomeToday,
	WAK47,
	mWAK47IncomeTotal,
	mWAK47IncomeToday,
	WM4,
	mWM4IncomeTotal,
	mWM4IncomeToday,
	WRifle,
	mWRifleIncomeTotal,
	mWRifleIncomeToday,
	WSRifle,
	mWSRifleIncomeTotal,
	mWSRifleIncomeToday,
	W9MMAmmo,
	mW9MMAmmoIncomeTotal,
	mW9MMAmmoIncomeToday,
	W50AEAmmo,
	mW50AEAmmoIncomeTotal,
	mW50AEAmmoIncomeToday,
	WBuckshot,
	mWBuckshotIncomeTotal,
	mWBuckshotIncomeToday,
	W762MMAmmo,
	mW762MMAmmoIncomeTotal,
	mW762MMAmmoIncomeToday,
	W127MMAmmo,
	mW127MMAmmoIncomeTotal,
	mW127MMAmmoIncomeToday,
	BRadio1Bought, // Is radio bought
	BRadio1On, // Is radio ON
	BRadio1Ch, // Radio channell
	BRadio1Obj, // Radio object id
	BRadio1Vol, // Volume of radio
	BRadio1ID[CUSTOM_MAX_PLAYERS], // Audio radio id
	Float:BRadio1X, // radio x pos 
	Float:BRadio1Y, // radio y pos
	Float:BRadio1Z, // radio z pos
	Float:BRadio1Angle,
	Product1,
	Product1type,
	Product1price,
	Product1count,
	Product1buy,
	Product1incomeTotal,
	Product1incomeToday,
	Product2,
	Product2type,
	Product2price,
	Product2count,
	Product2buy,
	Product2incomeTotal,
	Product2incomeToday,
	Product3,
	Product3type,
	Product3price,
	Product3count,
	Product3buy,
	Product3incomeTotal,
	Product3incomeToday,
	Product4,
	Product4type,
	Product4price,
	Product4count,
	Product4buy,
	Product4incomeTotal,
	Product4incomeToday,
	Product5,
	Product5type,
	Product5price,
	Product5count,
	Product5buy,
	Product5incomeTotal,
	Product5incomeToday,
	Product6,
	Product6type,
	Product6price,
	Product6count,
	Product6buy,
	Product6incomeTotal,
	Product6incomeToday,
	Product7,
	Product7type,
	Product7price,
	Product7count,
	Product7buy,
	Product7incomeTotal,
	Product7incomeToday,
	Product8,
	Product8type,
	Product8price,
	Product8count,
	Product8buy,
	Product8incomeTotal,
	Product8incomeToday,
	Product9,
	Product9type,
	Product9price,
	Product9count,
	Product9buy,
	Product9incomeTotal,
	Product9incomeToday,
	Product10,
	Product10type,
	Product10price,
	Product10count,
	Product10buy,
	Product10incomeTotal,
	Product10incomeToday,
	Product11Price,
	Product12Price,
	Product13Price,
	Product14Price,
	Product15Price,
	Product16Price,
	Product17Price,
	Product18Price,
	Product19Price,
	Product20Price,
	Product21Price,
	Product22Price,
	Product23Price,
	Product24Price,
	Product25Price,
	Product26Price,
	Product27Price,
	Product28Price,
	Product29Price,
	Product30Price,
	BConfiscated,
	BPlaced,
	BIntSet,
	BInterior,
	BGov,
	BShowIcon,
	mIncomeTotal,
	mIncomePhoneTotal,
	mIncomePhoneToday,
	mIncomeFuelPetrolToday,
	mIncomeFuelPetrolTotal,
	mIncomeFuelOilToday,
	mIncomeFuelOilTotal,
	mIncomeFuelGasToday,
	mIncomeFuelGasTotal,
	mIncomeVehicleTotal,
	mIncomeVehicleToday,
	mIncomeEntranceTotal,
	mIncomeEntranceToday,
	mAlarm
}
new Businesses[MAX_BUSINESSES][BusinessSystem];
new Text3D:Business3DTextLabelA[sizeof(Businesses)];
new Text3D:Business3DTextLabelB[sizeof(Businesses)];
new Text3D:Business3DTextLabelC[sizeof(Businesses)];

enum HouseSystem
{
	Description[128],
	Owner[MAX_PLAYER_NAME],
	HUID,
	StreetNo,
	HRenter[MAX_PLAYER_NAME],
	Float:EnterX,
	Float:EnterY,
	Float:EnterZ,
	EnterWorld,
	EnterInterior,
	Float:EnterAngle,
	Float:ExitX,
	Float:ExitY,
	Float:ExitZ,
	ExitInterior,
	Float:ExitAngle,
	Owned,
	Rentable,
	RentCost,
	HousePrice,
	Money,
	Locked,
	PickupID,
	ExitPickupId,
	HItem1,
	HItem2,
	HItem3,
	HItem4,
	HItem5,
	HItem1type,
	HItem2type,
	HItem3type,
	HItem4type,
	HItem5type,
	HItem1param,
	HItem2param,
	HItem3param,
	HItem4param,
	HItem5param,
	HItem1param2,
	HItem2param2,
	HItem3param2,
	HItem4param2,
	HItem5param2,
	HItem1param3,
	HItem2param3,
	HItem3param3,
	HItem4param3,
	HItem5param3,
	HItem1param4,
	HItem2param4,
	HItem3param4,
	HItem4param4,
	HItem5param4,
	HItem1param5[64],
	HItem2param5[64],
	HItem3param5[64],
	HItem4param5[64],
	HItem5param5[64],
	HItem1param6,
	HItem2param6,
	HItem3param6,
	HItem4param6,
	HItem5param6,
	HRadio1Bought, // Is radio bought
	HRadio1On, // Is radio ON
	HRadio1Ch, // Radio channell
	HRadio1Obj, // Radio object id
	HRadio1Vol, // Volume of radio
	HRadio1ID[CUSTOM_MAX_PLAYERS], // Audio radio id
	Float:HRadio1X, // radio x pos 
	Float:HRadio1Y, // radio y pos
	Float:HRadio1Z, // radio z pos
	Float:HRadio1Angle, // radio angle
	HouseType, // garage or house (0, 1, 2)
	HConfiscated, // is house confiscated ?
	HPlaced,
	HIntSet,
	HInterior,
	HAlarm,
	HRobbed
};
new Houses[MAX_HOUSES][HouseSystem];
new Text3D:Houses3DTextLabelA[MAX_HOUSES];
new Text3D:Houses3DTextLabelB[MAX_HOUSES];
new Text3D:Houses3DTextLabelC[MAX_HOUSES];
new gLastHVisit[CUSTOM_MAX_PLAYERS][MAX_HOUSES]; // cooldown dla pracy gazeciarza
new gLastBVisit[CUSTOM_MAX_PLAYERS][sizeof(Businesses)]; // cooldown dla pracy gazeciarza
new gHSelectedItemP5[MAX_HOUSES];

enum HousesDataInfo
{
	mDescription[64],
	mSize,
	Float:mExitX,
	Float:mExitY,
	Float:mExitZ,
	Float:mExitA,
	mExitInt
};
new HousesData[105][HousesDataInfo];

enum Taxes
{
	Float:CarTax,
	Float:HeliTax,
	Float:PlaneTax,
	Float:BoatTax,
	Float:HouseTax,
	Float:BusinessTax,
	RadioTax,
	TelTax,
	Float:RichTax,
	Float:EkoTax,
	Float:VatTaxMax,
	Float:VatTaxMin,
	TheRich
};
new DynamicTaxes[Taxes];

enum SpawnPlaceInfo {
	Float:X,
	Float:Y,
	Float:Z,
	Float:Angle,
	SlotUsed,
	VehicleID
};
new SpawnPlaceCars[20][SpawnPlaceInfo];
new SpawnPlacePlanes[20][SpawnPlaceInfo];
new SpawnPlaceBoats[20][SpawnPlaceInfo];

enum EnsuranceInfo {
	Level,
	vehicleNr
};
new EnsuranceOC[CUSTOM_MAX_PLAYERS][EnsuranceInfo];
new EnsuranceAC[CUSTOM_MAX_PLAYERS][EnsuranceInfo];

enum GasStationInfo	{
	BusinessID, // Assigned business ID
	Float:PetrolResourceValue, // Actual value of contained PETROL
	Float:OilResourceValue, // Actual value of contained OIL
	Float:GasResourceValue, // Actual value of contained GAS
	Float:MaxPetrolResourceValue, // Max value of PETROL resource contain
	Float:MaxOilResourceValue, // Max value of OIL resource contain
	Float:MaxGasResourceValue, // Max value of GAS resource contain
	RefuelPetrolResources, // Refule PETROL resources ? (on/off)
	RefuelOilResources, // Refuel OIL resources ? (on/off)
	RefuelGasResources, // Refuel GAS resources ? (on/off)
	PetrolPrice, // Price for 1 ltr of fuel
	OilPrice, // Price for 1 ltr of fuel
	GasPrice, // Price for 1 ltr of fuel
	Float:GSposX,
	Float:GSposY,
	Float:GSposZ,
	Float:Pos3dTextX,
	Float:Pos3dTextY,
	Float:Pos3dTextZ,
	Float:Pos3dTextX2,
	Float:Pos3dTextY2,
	Float:Pos3dTextZ2,
	Float:Pos3dTextX3,
	Float:Pos3dTextY3,
	Float:Pos3dTextZ3,
	Float:Pos3dTextX4,
	Float:Pos3dTextY4,
	Float:Pos3dTextZ4,
	Text3D:GS3dTextLabel,
	Text3D:GS3dTextLabel2,
	Text3D:GS3dTextLabel3,
	Text3D:GS3dTextLabel4
};
new GasStations[20][GasStationInfo];

enum PayRankInfo {
	FactionID,
	Rank1,
	Rank2,
	Rank3,
	Rank4,
	Rank5,
	Rank6,
	Rank7,
	Rank8,
	Rank9,
	Rank10
};
new PayRank[sizeof(DynamicFactions)][PayRankInfo];

enum CarsDataInfo {
	Model,
	Bak,
	Paliwo,
	Spalanie,
	ToGas,
	Float:Co2Emmision,
	MaxHealth
};
new CarsData[400][CarsDataInfo];

enum DBVariablesInfo {
	varName[128],
	varType[1],
	varDValue,
	Float:varFValue,
	varSValue[128]
};

new DBVariables[64][DBVariablesInfo];

enum PhoneBookNumberInfo {
	ln1,
	ln2,
	ln3,
	ln4,
	ln5,
	ln6,
	ln7,
	ln8,
	ln9,
	ln10
};
new gPhoneBookNumber[CUSTOM_MAX_PLAYERS][PhoneBookNumberInfo];

enum WantedListInfo {
	WantedName[64],
	WantedDescription[64],
	WantedCommitedDay,
	WantedCommitedMonth,
	WantedCommitedYear,
	WantedPunished,
	WantedID
};
new WantedList[50][WantedListInfo];

enum PhoneListInfo
{
	mPhoneID,
	mPhoneOwner[MAX_PLAYER_NAME],
	mPhoneNr,
	mPhoneFaction,
	mPhoneFreeMins,
	mPhoneFreeSms,
	mPhoneRenewalTime,
	mPhoneCash,
	mPhoneSimID
};
new gPhoneList[50][PhoneListInfo];

enum SmsListInfo
{
	mSmsId,
	mSmsSenderSimId,
	mSmsSenderNumber,
	mSmsSenderName[MAX_PLAYER_NAME],
	mSmsReceiverSimId,
	mSmsReceiverNumber,
	mSmsReceiverName[MAX_PLAYER_NAME],
	mSmsContent[256]
};
new gSmsList[50][SmsListInfo];

// new DrawDistanceWord[][32] =
// {
	// {"Low"},
	// {"Medium"},
	// {"High"}
// };
// new UsageFW[][32] =
// {
	// {"All"},
	// {"Rcon Only"}
// };

// enum FWN
// {
    // FireCracker,
    // Firerocket1,
    // Firerocket2,
    // Crackerroll,
    // Fountain1,
    // Fountain2,
    // Fountain3,
    // RocketB,
    // FWNDrawDistance,
// };
// new AllowedFirework[FWN];


/* Status of pickup item */
enum LItemsNfo
{
	pickupID,
	pickupLifeTime, // How long till pickup disappear
	Float:pickupX,
	Float:pickupY,
	Float:pickupZ,
	PickupItem,
	PickupItemType,
	PickupItemParam1,
	PickupItemParam2,
	PickupItemParam3,
	PickupItemParam4,
	PickupItemParam5[64],
	PickupItemParam6
};
new gPickupItem[200][LItemsNfo]; 

/* Rafinery data */
enum RafineryNfo
{
	RafResourcePetrol, // Actual resource value of PETROL
	RafResourceOil, // Actual resource value of OIL
	RafResourceGas, // Actual resource value of GAS
	RafResourceFly, // Actual resource value of GAS
	RafPetrolLtrCost, // How much costs 1 ltr of PETROL
	RafOilLtrCost, // How much costs 1 ltr of OIL
	RafGasLtrCost, // How much costs 1 ltr of GAS
	RafFlyLtrCost, // How much costs 1 ltr of AVIATION FUEL
	RafRefuelReward, // Employe reward for refuel station, TODO: need to mod to multiplier
	RafMaxResources, // Max value of rafinery resources
	RafResourceCP // Rafinery resource checkpoint
};
new gRafinery[RafineryNfo];

enum gangWarNfo
{
	Enabled,
	FactionStarted,
	FactionAttacked,
	FactionStartedKills,
	FactionAttackedKills,
	TimeLeft,
	TimeAlone, // how much time player is alone on territory
	AreaID
}
new gGangWar[gangWarNfo];

enum lawyerOfferNfo
{
	playerOffering,
	offerCost,
	govCost
}
new gLawyerOffer[CUSTOM_MAX_PLAYERS][lawyerOfferNfo];

enum customObjNfo
{
	Text3D:cstText3dID,
	Text3D:cstText3dID2,
	Text3D:cstText3dID3,
	Text3D:cstText3dID4,
	cstObjID,
	bool:cstSlotUsed,
	cstObjModel,
	cstObjVW,
	cstObjInt,
	cstDscShow,
	cstObjOwner[MAX_PLAYER_NAME]
}
new gCustomObj[5000][customObjNfo];
new gCustomObjShow[CUSTOM_MAX_PLAYERS];
new gCustomObjShowed[CUSTOM_MAX_PLAYERS][5000];
new Text3D:gCustomObjTextID1[CUSTOM_MAX_PLAYERS][5000];
new Text3D:gCustomObjTextID2[CUSTOM_MAX_PLAYERS][5000];
new Text3D:gCustomObjTextID3[CUSTOM_MAX_PLAYERS][5000];
new Text3D:gCustomObjTextID4[CUSTOM_MAX_PLAYERS][5000];

enum WFactoryLegalInfo // General factory info
{
	WFactoryID,
	WFactoryBuildingID,
	WFactoryReward,
	WFactoryCPPartTakeID,
	WFactoryCPPartTakeWV,
	WFactoryCPPartTakeInt,
	Float:WFactoryCPPartTakeX,
	Float:WFactoryCPPartTakeY,
	Float:WFactoryCPPartTakeZ,
	WFactoryCPPartSetup1ID,
	WFactoryCPPartSetup2ID,
	WFactoryCPPartSetup3ID,
	WFactoryCPPartSetup4ID,
	WFactoryCPPartSetup5ID,
	WFactoryCPPartSetup6ID,
	Float:WFactoryCPPartSetup1X,
	Float:WFactoryCPPartSetup1Y,
	Float:WFactoryCPPartSetup1Z,
	Float:WFactoryCPPartSetup2X,
	Float:WFactoryCPPartSetup2Y,
	Float:WFactoryCPPartSetup2Z,
	Float:WFactoryCPPartSetup3X,
	Float:WFactoryCPPartSetup3Y,
	Float:WFactoryCPPartSetup3Z,
	Float:WFactoryCPPartSetup4X,
	Float:WFactoryCPPartSetup4Y,
	Float:WFactoryCPPartSetup4Z,
	Float:WFactoryCPPartSetup5X,
	Float:WFactoryCPPartSetup5Y,
	Float:WFactoryCPPartSetup5Z,
	Float:WFactoryCPPartSetup6X,
	Float:WFactoryCPPartSetup6Y,
	Float:WFactoryCPPartSetup6Z,
	WFactoryCPAmmoSetup1ID,
	WFactoryCPAmmoSetup2ID,
	WFactoryCPAmmoSetup3ID,
	WFactoryCPAmmoSetup4ID,
	WFactoryCPAmmoSetup5ID,
	WFactoryCPAmmoSetup6ID,
	Float:WFactoryCPAmmoSetup1X,
	Float:WFactoryCPAmmoSetup1Y,
	Float:WFactoryCPAmmoSetup1Z,
	Float:WFactoryCPAmmoSetup2X,
	Float:WFactoryCPAmmoSetup2Y,
	Float:WFactoryCPAmmoSetup2Z,
	Float:WFactoryCPAmmoSetup3X,
	Float:WFactoryCPAmmoSetup3Y,
	Float:WFactoryCPAmmoSetup3Z,
	Float:WFactoryCPAmmoSetup4X,
	Float:WFactoryCPAmmoSetup4Y,
	Float:WFactoryCPAmmoSetup4Z,
	Float:WFactoryCPAmmoSetup5X,
	Float:WFactoryCPAmmoSetup5Y,
	Float:WFactoryCPAmmoSetup5Z,
	Float:WFactoryCPAmmoSetup6X,
	Float:WFactoryCPAmmoSetup6Y,
	Float:WFactoryCPAmmoSetup6Z,
	Float:WFactoryCPDocsX,
	Float:WFactoryCPDocsY,
	Float:WFactoryCPDocsZ,
	WFactoryCPDocsID,
	WFactoryCPDocsID2,
	WFactoryCPDocsID3,
	WFactoryCPDocsID4,
	WFactoryCPDocsID5,
	WFactoryCPDocsID6,
	WFactoryCPDocsID7,
	Float:WFactoryCPBuyX,
	Float:WFactoryCPBuyY,
	Float:WFactoryCPBuyZ
}
new WFactoryLegal[WFactoryLegalInfo];

/*
* Variables with O letter at ends represents how many
* weapons have been ordered.
*/
enum WFactoryLegalLightInfo // Lightweight weapon info
{
	WFactory9MM,
	WFactory9MMO,
	WFactory9MMSil,
	WFactory9MMSilO,
	WFactoryDesEagle,
	WFactoryDesEagleO,
	WFactoryMicroSMG,
	WFactoryMicroSMGO,
	WFactoryMP5,
	WFactoryMP5O,
	WFactoryTec9,
	WFactoryTec9O,
	WFactory9MMAmmo,
	WFactory9MMAmmoO,
	WFactory50AEAmmo,
	WFactory50AEAmmoO,
	WFactoryPistolPart1,
	WFactoryPistolS1Part1,
	WFactoryPistolS1Part2,
	WFactoryPistolS1Part3,
	WFactoryPistolPart2,
	WFactoryPistolS2Part1,
	WFactoryPistolS2Part2,
	WFactoryPistolS2Part3,
	WFactoryPistolPart3,
	WFactoryPistolS3Part1,
	WFactoryPistolS3Part2,
	WFactoryPistolS3Part3,
	WFactoryPistolS3Part4,
	WFactoryPistolPart4,
	WFactoryPistolPart5,
	WFactoryPistolPart6,
	WFactoryAmmoPart1a, // id 43
	WFactoryAmmoPart2a, // id 44
	WFactoryAmmoPart3a, // id 45
	WFactoryAmmoPart4a, // id 46
	WFactoryAmmoPart1b, // id 47
	WFactoryAmmoPart2b, // id 90
	WFactoryAmmoPart3b, // id 91
	WFactoryAmmoPart4b, // id 92
	WFactoryAmmoPart1c, // id 93
	WFactoryAmmoPart2c, // id 94
	WFactoryAmmoPart3c, // id 95
	WFactoryAmmoPart4c, // id 96
	WFactoryAmmoPart1d, // id 97
	WFactoryAmmoPart2d, // id 98
	WFactoryAmmoPart3d, // id 99
	WFactoryAmmoPart4d, // id 100
	WFactoryAmmoPart1e, // id 101
	WFactoryAmmoPart2e, // id 102
	WFactoryAmmoPart3e, // id 103
	WFactoryAmmoPart4e, // id 104
	WFactoryTec9Part,
	WFactoryDesEaglePart
}
new WFactoryLegalLight[WFactoryLegalLightInfo];

enum WFactoryLegalHeavyInfo // Heavyweight weapon info
{
	WFactoryShotgun,
	WFactoryShotgunO,
	WFactoryAK47,
	WFactoryAK47O,
	WFactoryM4,
	WFactoryM4O,
	WFactoryRifle,
	WFactoryRifleO,
	WFactorySRifle,
	WFactorySRifleO,
	WFactorySCharge,
	WFactorySChargeO,
	WFactoryBuckshot,
	WFactoryBuckshotO,
	WFactory762MMAmmo,
	WFactory762MMAmmoO,
	WFactory127MMAmmo,
	WFactory127MMAmmoO,
	WFactoryKGP66MMAmmo,
	WFactoryKGP66MMAmmoO,
	WFactoryNapalm,
	WFactoryNapalmO,
	WFactoryRiflePart1,
	WFactoryRifleS1Part1,
	WFactoryRifleS1Part2,
	WFactoryRiflePart2,
	WFactoryRifleS2Part1,
	WFactoryRifleS2Part2,
	WFactoryRifleS2Part3,
	WFactoryRiflePart3,
	WFactoryRifleS3Part1,
	WFactoryRifleS3Part2,
	WFactoryRifleS3Part3,
	WFactoryRifleS3Part4,
	WFactoryRiflePart4,
	WFactoryRiflePart5,
	WFactoryRiflePart6,
	WFactoryRifleS6Part1,
	WFactoryRifleS6Part2,
	WFactoryRiflePart7,
	WFactoryAK47Part,
	WFactoryM4Part,
	WFactoryRiflePart,
	WFactorySniperPart,
	WFactoryMP5Part,
	WFactoryShotPart
}
new WFactoryLegalHeavy[WFactoryLegalHeavyInfo];

enum radioInfo
{
	StationID,
	Volume,
	Float:AudioX,
	Float:AudioY,
	Float:AudioZ,
	AreaID
}
new gRadioSet[5][radioInfo];
new gRadioID[5][CUSTOM_MAX_PLAYERS];
new gRadio[17][128];

enum luckyLotteryNfo
{
	LuckyID, // lottery ID
	LuckyPlayerName[MAX_PLAYER_NAME], // player name which select numbers
	LuckyRewardTaken, // player taken the reward
	LuckyNumbers[4] // numbers which player checked	
}
new gLuckyLottery[5000][luckyLotteryNfo];
new gLuckyLotteryID = 0; // the unique id of lottery, auto increament
new gLuckyLotteryCash = 0; // how much cash is in lottery bank
new gLuckyLotteryLastLottery = 0; // days count when last lottery was launched
new gLuckyLotteryWinnersCount = 0; // this is need for reward split
new gLuckyLotteryNumbers[4] = { -1, ... }; // the numbers which been randomly choosen by the system

new Float:gShipSight[CUSTOM_MAX_PLAYERS] = { 10.0, ... };
enum shipsInfo
{
	shipObjID,
	Float:shipX,
	Float:shipY,
	Float:shipZ,
	Float:shipRZ
}
new gShips[1][shipsInfo] = 
{
{  0, 1615.2, 582.0, 15.0, 190.0 }
};

enum areasWaterInfo
{
	Float:minX,
	Float:minY,
	Float:maxX,
	Float:maxY
};
new gAreasWater[6][areasWaterInfo] = 
{
{ 1488.85, 484.24, 1744.45, 590.45 },
{ 1313.70, 562.34, 1483.65, 610.49 },
{ 960.480, 586.48, 1287.60, 635.95 },
{ 885.580, 532.34, 1030.75, 650.60 },
{ 470.300, 417.18, 767.771, 595.28 },
{ -93.230, 239.70, 400.727, 540.62 }
};

enum itemFactoryInfo
{
	fName[128],
	Float:fPosX,
	Float:fPosY,
	Float:fPosZ,
	fCPID,
	item1,
	item1type,
	item1count,
	item1minBuy,
	item1reproduceCount,
	item1price,
	item2,
	item2type,
	item2count,
	item2minBuy,
	item2reproduceCount,
	item2price,
	item3,
	item3type,
	item3count,
	item3minBuy,
	item3reproduceCount,
	item3price,
	item4,
	item4type,
	item4count,
	item4minBuy,
	item4reproduceCount,
	item4price,
	item5,
	item5type,
	item5count,
	item5minBuy,
	item5reproduceCount,
	item5price,
	item6,
	item6type,
	item6count,
	item6minBuy,
	item6reproduceCount,
	item6price,
	item7,
	item7type,
	item7count,
	item7minBuy,
	item7reproduceCount,
	item7price,
	item8,
	item8type,
	item8count,
	item8minBuy,
	item8reproduceCount,
	item8price,
	item9,
	item9type,
	item9count,
	item9minBuy,
	item9reproduceCount,
	item9price,
	item10,
	item10type,
	item10count,
	item10minBuy,
	item10reproduceCount,
	item10price
}
new gItemFactories[50][itemFactoryInfo];

/*
* Where the driving time in test area can be bought
*/
enum drivingTestAreaBuyInfo
{
	Float:mPosX,
	Float:mPosY,
	Float:mPosZ,
	mPosWorld,
	mPosInterior,
	mPrice,
	mTime,
	pickupID
};
new gDrivingTestAreaBuy[drivingTestAreaBuyInfo];

enum drivingTestAreaInfo
{
	Float:posEntranceX,
	Float:posEntranceY,
	Float:posEntranceZ,
	Float:posEntranceAngle,
	posEntranceWorld,
	posEntranceInterior,
	Float:posExitX,
	Float:posExitY,
	Float:posExitZ,
	Float:posExitAngle,
	posExitWorld,
	posExitInterior,
	mPriceA,
	mPriceB,
	mPriceCE,
	pickupID1,
	pickupID2
};
new gDrivingTestArea[drivingTestAreaInfo];

enum admissionChambersInfo
{
	Float:mPosX,
	Float:mPosY,
	Float:mPosZ,
	mWorld,
	mInt,
	mPickupID
}
new gAdmissionChambers[30][admissionChambersInfo];
	
new gRandomStableModels[][2] = { //Total 87 Models
{400},//Landstalker
{401},//Bravura
{402},//Buffalo
{404},//Perenniel
{405},//Sentinel
{410},//Manana
{411},//Infernus
{412},//Voodoo
{413},//Pony
{415},//Cheetah
{418},//Moobream
{419},//Esperanto
{421},//Washington
{422},//Bobcat
{424},//BF Injection
{426},//Premier
{429},//Banshee
{436},//Previon
{439},//Stallion
{445},//Admiral
{451},//Turismo
{458},//Solair
{461},//PCJ-600
{462},//Faggio
{463},//Freeway
{466},//Glendale
{467},//Oceanic
{468},//Sanchez
{471},//Quad
{474},//Hermes
{475},//Sabre
{477},//ZR-350
{479},//Regina
{480},//Comet
{482},//Burrito
{483},//Camper
{491},//Virgo
{492},//Greenwood
{496},//Blista
{500},//Mesa
{506},//Super GT
{507},//Elegant
{516},//Nebula
{517},//Majestic
{518},//Buccaneer
{521},//FCR-900
{522},//NRG-500
{526},//Fortune
{527},//Cadrona
{529},//Willard
{533},//Feltzer
{534},//Remington
{535},//Slamvan
{536},//Blade
{540},//Vincent
{541},//Bullet
{542},//Clover
{543},//Sadler
{546},//Intruder
{547},//Primo
{549},//Tampa
{550},//Sunrise
{551},//Merit
{554},//Yosemite
{555},//Window
{558},//Uranus
{559},//Jester
{560},//Sultan
{561},//Stratum
{562},//Elegy
{565},//Flash
{566},//Tahoma
{567},//Savanna
{575},//Broadway
{576},//Tornado
{579},//Huntley
{580},//Stafford
{581},//BF-400
{585},//Emporer
{586},//Wayfarer
{587},//Euros
{589},//Club
{600},//Picador
{602},//Alpha
{604},//Glendale Shit
{603},//Phoenix
{605}//Sadler Shit
};

enum quizQuestionsInfo
{
	q1[128],
	a1a[128],
	a1b[128],
	a1c[128],
	a1d[128],
	a1e[128],
	a1,
	q2[128],
	a2a[128],
	a2b[128],
	a2c[128],
	a2d[128],
	a2e[128],
	a2,
	q3[128],
	a3a[128],
	a3b[128],
	a3c[128],
	a3d[128],
	a3e[128],
	a3,
	q4[128],
	a4a[128],
	a4b[128],
	a4c[128],
	a4d[128],
	a4e[128],
	a4,
	q5[128],
	a5a[128],
	a5b[128],
	a5c[128],
	a5d[128],
	a5e[128],
	a5,
	q6[128],
	a6a[128],
	a6b[128],
	a6c[128],
	a6d[128],
	a6e[128],
	a6,
	q7[128],
	a7a[128],
	a7b[128],
	a7c[128],
	a7d[128],
	a7e[128],
	a7,
	q8[128],
	a8a[128],
	a8b[128],
	a8c[128],
	a8d[128],
	a8e[128],
	a8,
	q9[128],
	a9a[128],
	a9b[128],
	a9c[128],
	a9d[128],
	a9e[128],
	a9,
	q10[128],
	a10a[128],
	a10b[128],
	a10c[128],
	a10d[128],
	a10e[128],
	a10,
	q11[128],
	a11a[128],
	a11b[128],
	a11c[128],
	a11d[128],
	a11e[128],
	a11,
	q12[128],
	a12a[128],
	a12b[128],
	a12c[128],
	a12d[128],
	a12e[128],
	a12,
	q13[128],
	a13a[128],
	a13b[128],
	a13c[128],
	a13d[128],
	a13e[128],
	a13,
	q14[128],
	a14a[128],
	a14b[128],
	a14c[128],
	a14d[128],
	a14e[128],
	a14,
	q15[128],
	a15a[128],
	a15b[128],
	a15c[128],
	a15d[128],
	a15e[128],
	a15,
	q16[128],
	a16a[128],
	a16b[128],
	a16c[128],
	a16d[128],
	a16e[128],
	a16,
	q17[128],
	a17a[128],
	a17b[128],
	a17c[128],
	a17d[128],
	a17e[128],
	a17,
	q18[128],
	a18a[128],
	a18b[128],
	a18c[128],
	a18d[128],
	a18e[128],
	a18,
	q19[128],
	a19a[128],
	a19b[128],
	a19c[128],
	a19d[128],
	a19e[128],
	a19,
	q20[128],
	a20a[128],
	a20b[128],
	a20c[128],
	a20d[128],
	a20e[128],
	a20,
	q21[128],
	a21a[128],
	a21b[128],
	a21c[128],
	a21d[128],
	a21e[128],
	a21,
	q22[128],
	a22a[128],
	a22b[128],
	a22c[128],
	a22d[128],
	a22e[128],
	a22,
	q23[128],
	a23a[128],
	a23b[128],
	a23c[128],
	a23d[128],
	a23e[128],
	a23,
	q24[128],
	a24a[128],
	a24b[128],
	a24c[128],
	a24d[128],
	a24e[128],
	a24,
	q25[128],
	a25a[128],
	a25b[128],
	a25c[128],
	a25d[128],
	a25e[128],
	a25
};
new gQuizQuestions[quizQuestionsInfo] =
{
	"1.Co rozumiesz pod pojêciem Role Play?",
	"1.To inaczej Stunt.",
	"2.Naœladowanie s³awnych osób.",
	"3.Naœladowanie realnego ¿ycia.",
	"4.Inaczej krêcimy filmy.",
	"5.To inaczej Deatmatch.",
	3,
	"2.Co oznacza pojêcie Metagaming?",
	"1.Kradzie¿ pojazdu w sposób NON-RP.",
	"2.U¿ywanie informacji z OOC w IC. ",
	"3.Wulgarne odzywki na czacie OOC. ",
	"4.Zak³adanie multikont. ",
	"5.Inaczej zabijanie bez powodu. ",
	2,
	"3.Co zrobisz jak bêdziesz na odludziu?",
	"1.Zadzwoniê po taxi albo do kumpla. ",
	"2.Zabijê siê. ",
	"3.Bêde spamowa³ na /pw do admina o teleport.",
	"4.Zacznê sprintowaæ do miasta. ",
	"5.Odpalê cheaty i siê teleportujê. ",
	1, 
	"4.W jaki sposób poszukasz pracy (w frakcji)?",
	"1.Zapytam lidera na /pw.", 
	"2.Jak zobaczê kogoœ z frakcji to napiszê mu na /pw. ",
	"3.Zaspamujê gg/skype lidera by mnie przyj¹³. ",
	"4.Przypnê og³oszenie na forum i poczekam na odpowiedŸ. ",
	"5.Gdy spotkam lidera wyœlê mu kilka dolców i mnie przyjmie. ",
	4,
	"5.Co znaczy Bunny Hopping?",
	 "1.Strzelanie z miejsca pasa¿era. ",
	 "2.Jazda w sposób NON-RP. ",
	 "3.Skakanie, aby szybciej dotrzeæ do celu. ",
	 "4.Odbijanie siê od œcian. ",
	 "5.Skakanie samochodem. ",
	 3,
	"6. Jak poprawnie zaholujesz pojazd ?",
	 "1. Zaczne pchaæ. ",
	 "2. Wezwe mechanika.", 
	 "3. U¿yje cheata.",
	 "4. Poprosze admina. ",
	 "5. Zaczne spamowac na chacie. ",
	2, 
	"7.Co znaczy Celebrity Name?",
	 "1.Posiadanie nicku z GTA 4. ",
	 "2.To nazwa baru. ",
	 "3.Nicki wszystkich graczy. ",
	 "4.Wesele. ",
	 "5.Posiadanie nicku s³awnej osoby. ",
	5,
	"8.Co zrobisz jak zobaczysz policjantów na s³u¿bie?",
	"1.Podbiegnê do nich, œci¹gnê spodnie i wypnê im dupsko.", 
	"2.Przejdê obojêtnie. ",
	"3.Bêde ich prowokowa³. ",
	"4.Wpiszê komendê /q. ",
	"5.Wyjmê kij/pistolet i zacznê w nich ³adowaæ. ",
	2,
	"9.Co znaczy Character Kill?",
	"1.Nale¿enie do tajnej organizacji. ",
	"2.Œmieræ postaci, poprzez blokadê konta. ",
	"3.Z³y charakter. ",
	"4.Zabijanie bez powodu. ",
	"5.Zabijanie liderów frakcji. ",
	2,
	"10.Co to Power Gaming?",
	"1.Wymuszanie na kimœ akcji RP. ",
	"2.Granie w sposób NON-RP. ",
	"3.Dziesiona. ",
	"4.Odpalanie cheatów. ",
	"5.Gra na maksa. ",
	1,
	"11.Co to DeathMatch?",
	"1.Zrobienie komuœ CK. ",
	"2.Nawalanie ka¿dego bez powodu. ",
	"3.Strzelanie na statku. ",
	"4.Uciekanie przed policj¹. ",
	"5.Skakanie po œcianach. ",
	2,
	"12.Co to Revenge Kill?",
	"1.Zabicie s³awnej osoby. ",
	"2.Jazda po pijaku ",
	"3.Zabijanie z zemsty. ",
	"4.Wyzywanie na czacie IC. ",
	"5.Wyzywanie na czacie OOC. ",
	3,
	"13.Jakie jest standardowe poruszanie siê po ulicach??",
	"1.Skakanie",
	"2.W - Bieg",
	"3.Spacja + W - Sprint",
	"4.ALT + W - Spacer",
	"5.Uzywajac cheata ",
	4,
	"14.Jak mogê ukraœæ samochód?",
	"1.Wyrzuciæ kierowcê i odjechaæ. ",
	"2.Udaæ siê do jakiegoœ pustego auta. ",
	"3.Ukraœæ auto przez /ja i /do. ",
	"4.Nie mo¿emy. ",
	"5.Ka¿dy auto jest moje. ",
	3,
	"15.Do czego s³u¿y komenda /ja i /do?",
	"1.Do tañczenia. ",
	"2.Wtedy siê lepiej biega. ",
	"3.Do tego ¿eby siê admini odczepili. ",
	"4.Do pisania OOC. ",
	"5.Do opisywania akcji RP. ",
	5,
	"16.Co zrobisz jak zobaczysz kogoœ z gangu?",
	"1.Zapytam siê czy mogê do³¹czyæ. ",
	"2.Dowalê mu. ",
	"3.Wypnê do niego ty³ek. ",
	"4.Poka¿ê mu œrodkowy palec. ",
	"5.Ominê go, z nimi lepiej nie zadzieraæ. ",
	5,
	"17.Jak bêdziesz porusza³ siê pojazdem?",
	"1.Bêdê stuntowa³ i driftowa³, przysiêgam. ",
	"2.Bêde jeŸdzi³ zgodnie z przepisami. ",
	"3.Wszystkie s³upy s¹ moje. ",
	"4.Tak jak na DM-ie. ",
	"5.Jestem królem ulic, wszystko mi wolno. ",
	2,
	"18.Gdzie i jak bêdziesz móg³ wyci¹gnaæ pistolet?",
	"1.W cichym miejscu z komend¹ /ja i /do. ",
	"2.Na komendzie policji. ",
	"3.W domu gangu. ",
	"4.W WORDzie. ",
	"5.W taksówce. ",
	1,
	"19.Jak bêdziesz u¿ywa³ komendy /donos?",
	"1.Bêde u¿ywa³ kiedy bêde chcia³. ",
	"2.Bêde na tej komendzie spamowaæ. ",
	"3.Napiszê jeden i poczekam na odpowiedŸ. ",
	"4.Nie wiem jeszcze. ",
	"5.Nie u¿ywam jej, bo po co. ",
	3,
	"20.Co zrobisz jak zobaczysz Cheatera?",
	"1.Spytam siê czy wyœle mi na pw cheata. ",
	"2.Zacznê uciekaæ. ",
	"3.Napisze szybko /donos. ",
	"4.Zacznê z nim walczyæ. ",
	"5.Ja równie¿ odpalê cheata. ",
	3,
	"21.Zabicie kogoœ przez przejechanie samochodem to ??",
	"1.Car Kill",
	"2.DM",
	"3.Drive-by",
	"4.MetaGaming",
	"5.RK",
	1,
	"22.Co to NON-RP?",
	"1.Skakanie na rowerze. ",
	"2.Jazda po pijaku. ",
	"3.Zachowanie wbrew zasadom RP. ",
	"4.Wchodzenie na komendê policji. ",
	"5.P³ywanie statkiem. ",
	3,
	"23.Co oznacza Ninja Jacking?",
	"1.Posiadanie miecza ninji. ",
	"2.Kradzie¿ pojazdu w, którym jest ju¿ kierowca. ",
	"3.Nale¿enie do tajnej organizacji. ",
	"4.Mafia japoñska. ",
	"5.Skorumpowani policjanci. ",
	2,
	"24.Co oznacza IC?",
	"1.Granie na zw³okê. ",
	"2.Og³oszenie rz¹dowe. ",
	"3.Temat tabu. ",
	"4.Wszystko co dotyczy gry. ",
	"5.Nazwa piwa. ",
	4,
	"25.Co oznacza OOC?",
	"1.Wszystko co dotyczy twojej postaci. ",
	"2.Kupowanie broni od dilera. ",
	"3.Nazwy dragów. ",
	"4.Wszystko co nie dotyczy gry. ",
	"5.Udawanie ciemnego charakteru.",
	4
};

enum testQuestionsInfo
{
	q1[256],
	a1a[256],
	a1b[256],
	a1c[256],
	a1,
	q2[256],
	a2a[256],
	a2b[256],
	a2c[256],
	a2,
	q3[256],
	a3a[256],
	a3b[256],
	a3c[256],
	a3,
	q4[256],
	a4a[256],
	a4b[256],
	a4c[256],
	a4,
	q5[256],
	a5a[256],
	a5b[256],
	a5c[256],
	a5
};
new gTestQuestions[9][testQuestionsInfo] =
{
	// zestaw nr 1
	{
		"Za nieprzepisowe parkowanie nie mo¿na zostaæ ukaranym:", // pytanie
        "Mandatem", // odp 1
        "Pouczeniem", // odp 2
        "Wiêzieniem", // odp 3
        3, // nr prawidlowej odp od 1 do 3
        "Pieszy wszed³ na przejœcie dla pieszych. W tej sytuacji kieruj¹cy pojazdem:", // kolejne pytanie....
        "Mo¿e wjechaæ na przejœcie",
        "Mo¿e siê nie zatrzymaæ",
        "Powinien zatrzymaæ siê oraz zachowaæ czujnoœæ",
        3,
        "Znak poziomy: linia ci¹g³a pojedyñcza",
        "Zezwala na wyprzedzanie pojazdu",
        "Rozdziela pasy o tym samym kierunku",
        "Rozdziela pasy o przeciwnym kierunku",
        2,
        "Sygnalizator œwietlny. Zapalone œwiat³a czerwone i ¿ó³te. Jakie nastêpne œwiat³o siê zapali ?",
        "Czerwone",
        "¯ó³te i zielone",
        "Zielone",
        3,
        "Maksymalna prêdkoœæ pojazdu do 3.5 ton w terenie zabudowanym to:",
        "60 km/h miêdzy 23:00-05:00",
        "50 km/h miêdzy 23:00-05:00",
        "Brak ograniczenia",
        1
	},	
	// zestaw nr 2
	{
		"Motocyklista powinien :", // pytanie
        "Zak³adaæ kask podczas jazdy", // odp 1
        "Zak³adaæ odpowiednie obuwie oraz odzie¿ ochronna", // odp 2
        "Wszystkie powy¿ej ", // odp 3
        3, // nr prawid³owej odp od 1 do 3
        "Badania techniczne przeprowadza siê :", // kolejne pytanie....
        "Raz do roku",
        "Przed up³ywem terminu okreœlonego w dowodzie rejestracyjnym ",
        "W ogóle siê nie przeprowadza",
        2,
        "Widzisz pojazd jad¹cy na sygnale, co robisz: ",
        "Zatrzymujê siê na œrodku ulicy i czekam, a¿ mnie ominie",
        "Zje¿d¿am na poboczê i czekam, a¿ przejedzie",
        "Jadê szybciej, aby pojazd mnie nie dogoni³",
        2,
        "Do silnika Diesla wlejesz :",
        "Ropê",
        "Gaz",
        "Olej napêdowy",
        1,
        "Kiedy u¿ywamy œwiate³ mijania: ",
        "Wieczorami",
        "Wrzez ca³y rok ",
        "W czasie mg³y",
        2
	},
	// zestaw nr 3
	{
		 "Umieszczone na jezdni punktowe elementy odblaskowe barwy czerwonej wyznaczaj¹:",
        "Praw¹ krawêdŸ jezdni",
        "Lew¹ krawêdŸ jezdni",
        "Pasy ruchu",
        1, // nr prawid³owej odp od 1 do 3
        "Dokonywanie regularnych przegl¹dów technicznych motocykla : ", // kolejne pytanie....
        "Pozwala utrzymaæ motocykl we w³aœciwej sprawnoœci ",
        "Nie jest koniecznie",
        "Jest nie op³acalne ze wzglêdów pienieznych",
        1,
        "Stosunek uciœniêæ mostka do iloœci sztucznych oddechów u poszkodowanych wynosi:",
        "30:2 ",
        "2:30",
        "1:5",
        1,
        "W jaki sposób zabezpieczysz miejsce wypadku samochodowego?:",
        "wy³¹czê stacyjkê samochodu, który mia³ wypadek.",
        "zostawiæ samochód na ceg³ach",
        "podleje benzyn¹, po¿ar bêdzie widoczny z wiêkszej odleg³oœci",
        1,
        "W WParty jeŸdzi siê … ulicy :",
        "œrodkiem",
        "po lewej stronie",
        "po prawej stronie ",
        3
	},	
	// zestaw nr 4
	{
		 "W sytuacji kieruj¹cy pojazdem widz¹c pijanego na drodze pieszego powinien:",
        "byæ przygotowany do zatrzymania pojazdu,",
        "przyspieszyæ pojazdem",
        "podaæ pieszemu kolejna butelkê piwa",
        1,
        "Podwójna linia ci¹g³a oznacza :", // kolejne pytanie....
        "Mo¿na wyprzedzaæ",
        "Mo¿na zawracaæ",
        "Zakaz przeje¿d¿ania przez ta linie",
        3,
        "Predkosc max po za terenem zabudowanym wynosi :",
        "90 km/h",
        "120 km/h",
        "50 km/h",
        1,
        "W jaki sposób sprawdzisz przytomnoœæ u poszkodowanego (doros³ego)?:",
        "Chwycê poszkodowanego za barki i lekko potrz¹saj¹c zapytam np. Co siê sta³o?",
        "Poklepiê go po twarzy",
        "Polejê kwasem",
        1,
        "Na zakrêcie pozwala siê na : ",
        "wyprzedzanie",
        "zatrzymanie pojazdu",
        "¯adna odpowiedz",
        3
	},	
	// zestaw nr 5
	{
		 "Przed rozpoczêciem jazdy kieruj¹cy samochodem osobowym powinien sprawdziæ:",
        "czy okno jest zamkniête w samochodzie",
        "zabranie pieniêdzy na ³apówki",
        "ustawienie fotela, lusterek, zapiêcia pasów przez pasa¿erów",
        3,
        "Obowi¹zek udzielania pierwszej pomocy ofiarom wypadku ma:", // kolejne pytanie....
        "Wszyscy wokó³ mnie tylko nie ja",
        "Wy³¹cznie lekarze",
        "Wszyscy w³¹cznie z mn¹",
        3,
        "Ekonomiczna jazda samochodem osobowym to:",
        "Jazda na mo¿liwie najwy¿szym biegu bez przeci¹¿ania silnika",
        "Gwa³townie hamowaæ oraz przyspieszaæ",
        "Utrzymywanie za wszelk¹ cenê sta³ej prêdkoœci przy jeŸdzie pod górê,",
        1,
        "Prawid³owe trzymanie kierownicy podczas jazdy na wprost : ",
        "jedna rêka na kierownicy na godzenie 12 a druga na skrzyni biegów",
        "jedna rêka na godzinie 10 druga na 2 h ",
        "jedna rêka zimny ³okieæ druga trzyma kierownice na godzinie 6 przy kolanach",
        2,
        "Umieszczone na jezdni punktowe elementy odblaskowe barwy czerwonej wyznaczaj¹:",
        "Praw¹ krawêdŸ jezdni",
        "Lew¹ krawêdŸ jezdni",
        "Pasy ruchu",
        1
	},
	// zestaw nr 6
	{
		"W razie uczestniczenia w wypadku drogowym, kieruj¹cy pojazdem powinien podaæ na ¿¹danie osób w nim uczestnicz¹cych:", // pytanie
        "Dane techniczne swojego samochodu", // odp 1
        "Dane swoich rodziców i OC", // odp 2
        "Dane osobiste, samochodu i OC", // odp 3
        3, // nr prawid³owej odp od 1 do 3
        "W razie uczestniczenia w wypadku drogowym, w którym nie ma ofiar, kieruj¹cy pojazdem powinien:", // kolejne pytanie....
        "Zatrzymaæ pojazd, nie powoduj¹c przy tym zagro¿enia bezpieczeñstwa ruchu.",
        "Przejechaæ obok",
        "Dobiæ ofiary wypadku, aby nie cierpia³y wiêcej",
        1,
        "W razie uczestniczenia w wypadku drogowym, w którym s¹ ofiary, kieruj¹cy pojazdem powinien:",
        "Modliæ siê",
        "Wezwaæ zespó³ ratownictwa medycznego i policje",
        "Wezwaæ prezydenta",
        2,
        "W sytuacji kieruj¹cy pojazdem widz¹c pijanego na drodze pieszego powinien:",
        "byæ przygotowany do zatrzymania pojazdu,",
        "przyspieszyæ pojazdem",
        "podaæ pieszemu kolejna butelkê piwa",
        1,
        "Jad¹c za pojazdem uprzywilejowanym, kierowca :",
        "tr¹bimy aby szybciej jechali",
        "Gaz do dechy - wyprzedzamy nie patrzymy siê",
        "nie mo¿e wyprzedziæ pojazdu uprzywilejowanego - na obszarze zabudowanym,",
        3
	},
	// zestaw nr 7
	{
		"W okresie dostatecznej widocznoœci, kieruj¹cy pojazdem holuj¹cym:", // pytanie
		"w³o¿yæ kask ochronny", // odp 1
		"powinien mieæ w³¹czone œwiat³a mijania,", // odp 2
		"w³¹czyæ radio na full bass", // odp 3
		2, // nr prawid³owej odp od 1 do 3
		"Na autostradzie dopuszcza siê holowanie:", // kolejne pytanie....
		"nie mo¿na holowaæ - nale¿y zostawiæ samochód",
		"tylko pojazdem przeznaczonym do tego celu,",
		"ka¿dym samochodem",
		2,
		"W jaki sposób zabezpieczysz miejsce wypadku samochodowego?:",
		"wy³¹czê stacyjkê samochodu, który mia³ wypadek.",
		"zostawiæ samochód na ceg³ach",
		"podleje benzyn¹, po¿ar bêdzie widoczny z wiêkszej odleg³oœci",
		1,
		"W okresie docierania samochodu osobowego nie nale¿y:",
		"korzystaæ z samochodu",
		"wrzucaæ 4tego biegu",
		"jeŸdziæ z prêdkoœci¹ zbli¿on¹ do maksymalnej,",
		3,
		"Dokonywanie regularnych przegl¹dów technicznych pojazdu:",
		"pogarsza stan pojazdu",
		"jest konieczne, gdy¿ pozwala utrzymaæ pojazd we w³aœciwej sprawnoœci,",
		"mordêga - za ka¿dym razem musimy odmontowaæ  nasz tuning samochodowy",
		2
	},	
	// zestaw nr 8
	{
		"Przed rozpoczêciem d³u¿szej jazdy nale¿y sprawdziæ:", // pytanie
        "stan lakieru", // odp 1
        "stan zderzaka", // odp 2
        "dzia³anie uk³adu hamulcowego i kierowniczego,", // odp 3
        3, // nr prawid³owej odp od 1 do 3
        "Lampki kontrolne informuj¹ce w czasie jazdy kierowcê o wa¿nym problemie technicznym s¹ barwy:", // kolejne pytanie....
        "czerwonej.",
        "zielonej",
        "¿ó³tej",
        1,
        "Kontrola hydraulicznego hamulca roboczego polega na:",
        "oddanie samochodu do mechanika",
        "sprawdzeniu poziomu p³ynu do spryskiwaczy",
        "sprawdzeniu poziomu p³ynu hamulcowego w zbiorniku.",
        3,
        "Ubytek oleju w silniku uzupe³nia siê:",
        "rop¹",
        "olejem polecanym przez producenta",
        "benzyn¹",
        2,
        "Przed rozpoczêciem jazdy kieruj¹cy samochodem osobowym powinien sprawdziæ:",
        "czy okno jest zamkniête w samochodzie",
        "zabranie pieniêdzy na ³apówki",
        "ustawienie fotela, lusterek, zapiêcia pasów przez pasa¿erów",
        3
	},
	// zestaw nr 9
	{
		"Na prostym odcinku drogi wielopasowej zaleca siê jechaæ", // pytanie
        "Jak najd³u¿ej jednym i tym samym pasem ruchu i prawym pasem", // odp 1
        "Lewym pasem ruchu", // odp 2
        "Slalom miêdzy pasami", // odp 3
        1, // nr prawid³owej odp od 1 do 3
        "Ekonomiczna jazda samochodem osobowym to:", // kolejne pytanie....
        "Gaz do dechy",
        "Unikanie gwa³townych przyspieszeñ i hamowañ,",
        "Zmieniamy biegi/hamujemy jak w F1",
        2,
        "Droga hamowania samochodu osobowego na mokrej jezdni, jest:",
        "D³u¿sza od drogi hamowania na jezdni suchej i krótsza na jezdni oblodzonej",
        "Bardzo i to bardzo krótka",
        "W ogóle nie nale¿y na takiej powierzchni hamowaæ",
        1,
        "Kieruj¹cy samochodem osobowym powinien mieæ przy sobie:",
        "Dowód osobisty, prawo jazdy, OC",
        "Zdjêcie ¿ony i dziecka",
        "Pieni¹dze na ³apówkê",
        1,
        "Opuszczaj¹c pojazd, kieruj¹cy:",
        "w ka¿dym przypadku, mo¿e pozostawiæ drzwi otwarte",
        "mo¿e zaleciæ pasa¿erom wyjœcie tylko od strony ulicy",
        "powinien upewniæ siê, czy nie utrudni ruchu innym pojazdom,",
        3
	}
};
new gSelectedTest[CUSTOM_MAX_PLAYERS];
new gSelectedTestQ[CUSTOM_MAX_PLAYERS];
new gTestQuestionsA[CUSTOM_MAX_PLAYERS][5];
new gTestResult[CUSTOM_MAX_PLAYERS];

/* Relative position of weapon factory building (illegal) objects, etc. without main building */
new Float:WFObj[31][6] = {
/*2061*/ { 4.6550841331482, -0.78501975536346, 0.37005430459976, 0.0, 0.0, 102.0 },
/*1212*/ { 4.3871564865112, -1.7937351465225, 1.0469108819962, 0.0, 0.0, 0.0 },
/*1550*/ { 98.190940856934, -17.195056915283, -6.4743485450745, 0.0, 0.0, 0.0 },
/*1550*/ { -4.3936009407043, -4.8286213874817, 0.47146689891815, 0.0, 0.0, 0.0 },
/*1650*/ { -3.310498714447, -6.5096039772034, 0.38478800654411, 0.0, 0.0, 0.0 },
/*2035*/ { 3.0848381519318, -6.0902943611145, 0.99892324209213, 0.0, 0.0, 253.50001525879 },
/*2036*/ { 1.7577524185181, -5.4056868553162, 0.63705110549927, 357.93090820313, 260.21423339844, 91.822845458984 },
/*2037*/ { 4.5575466156006, -2.5281393527985, 1.1192708015442, 0.0, 0.0, 0.0 },
/*2044*/ { -3.5545017719269, -5.8903951644897, 0.98065781593323, 0.0, 0.0, 147.75 },
/*2057*/ { 4.25141954422, -3.2465581893921, 1.2173645496368, 0.0, 0.0, 0.0 },
/*2059*/ { 4.3409323692322, -2.53218126297, 1.0547102689743, 0.0, 0.0, 256.0 },
/*3387*/ { 0.072891861200333, -6.2323522567749, 0.07812488079071, 0.0, 0.0, 269.5 },
/*3389*/ { 0.85146683454514, 8.649808883667, 0.12984383106232, 0.0, 0.0, 0.0 },
/*3391*/ { -2.8265869617462, -6.1748013496399, 0.078125, 0.0, 0.0, 270.25 },
/*3396*/ { 2.8590433597565, -6.123131275177, 0.078125, 0.0, 0.0, 272.0 },
/*3787*/ { -2.0172448158264, 8.40087890625, 0.64435839653015, 0.0, 0.0, 0.0 },
/*1222*/ { 3.9659109115601, 8.3201589584351, 0.55419254302979, 0.0, 0.0, 0.0 },
/*939  */ { -3.677339553833, -0.73406970500946, 2.5213513374329, 0.0, 0.0, 271.25 },
/*2333*/ { 3.1884579658508, -2.0022537708282, 0.078125, 0.0, 0.0, 270.75012207031 },
/*1212*/ { 4.4909286499023, -2.0283234119415, 1.0469108819962, 0.0, 0.0, 0.0 },
/*1212*/ { 4.4893941879272, -2.2783184051514, 1.0469108819962, 0.0, 0.0, 0.0 },
/*1212*/ { 4.2046632766724, -2.1563868522644, 1.0469108819962, 0.0, 0.0, 0.0 },
/*2186*/ { 2.1457922458649, 7.6967134475708, 0.092187494039536, 0.0, 0.0, 88.0 },
/*1829*/ { -3.8157234191895, 3.1636726856232, 0.5426539182663, 0.0, 0.0, 90.0 },
/*1728*/ { 3.8882455825806, 5.5468425750732, 0.078125, 0.0, 0.0, 273.25 },
/*2037*/ { 4.490936756134, -2.7439827919006, 1.1192708015442, 0.0, 0.0, 0.0 },
/*2037*/ { 4.4568681716919, -2.9464633464813, 1.1192708015442, 0.0, 0.0, 0.0 },
/*2037*/ { 4.3484787940979, -2.4579989910126, 1.1192708015442, 0.0, 0.0, 0.0 },
/*2044*/ { -2.3471467494965, -5.9107604026794, 0.98065781593323, 0.0, 0.0, 234.49963378906 },
/*18725*/{ -3.6810629367828, -0.7649707794189, 3.5040847587585, 0.0, 0.0, 0.0 },
/*18693*/{ 4.0167889595032, 8.4001379013062, -0.24687500298023, 0.0, 0.0, 0.0 }
};

new Float:WFCP[6][3] = {
/*Make weapon parts*/ { 3.4828429222107, -2.5014038085938, 1.078125 },
/*Make weapon parts*/ { 2.8650646209717, -4.8278775215149, 1.078125 },
/*Make weapon subparts*/ { -2.0474841594696,  -4.7468156814575, 1.078125 },
/*Take/buy ammo/weapon (sub) parts*/ { -1.471581697464, -0.76670616865158, 1.078125 },
/*Make weapon subparts*/ { -1.8708779811859, 6.9664425849915, 1.078125 },
/*Safe*/ { -3.54, 3.22, 1.07 }
};

enum vehTransportInfo
{
	Float:mPosX1,
	Float:mPosY1,
	Float:mPosZ1,
	Float:mPosX2,
	Float:mPosY2,
	Float:mPosZ2,
	Float:mPosX3,
	Float:mPosY3,
	Float:mPosZ3,
	Float:mPosX4,
	Float:mPosY4,
	Float:mPosZ4,
	mPosInterior,
	mPosAngle
};
new gVehTransport[vehTransportInfo] = 
{
	351.81,
	174.06,
	1014.95,
	357.27,
	174.06,
	1013.89,
	356.8,
	170.82,
	1013.96,
	351.52,
	170.82,
	1013.96,
	3,
	90
};


enum vehExportInfo
{
	Float:mPosX1,
	Float:mPosY1,
	Float:mPosZ1,
	Float:mPosX2,
	Float:mPosY2,
	Float:mPosZ2,
	Float:mPosX3,
	Float:mPosY3,
	Float:mPosZ3,
	Float:mPosX4,
	Float:mPosY4,
	Float:mPosZ4,
	Float:mPosX5,
	Float:mPosY5,
	Float:mPosZ5,
	Float:mPosX6,
	Float:mPosY6,
	Float:mPosZ6,
	Float:mPosX7,
	Float:mPosY7,
	Float:mPosZ7,
	mCpId1,
	mCpId2,
	mCpId3,
	mCpId4,
	mCpId5,
	mCpId6,
	mCpId7,
	mTimeBeforeExport,
	mTimeBeforeNextSteal
};
new gVehExport[vehExportInfo] =
{
	1610.22,
	-1492.2,
	13.55,
	2790.76,
	-2455.8,
	13.33,
	2790.76,
	2823.19,
	10.52,
	1349.09,
	1761.23,
	10.52,
	-2287.19,
	2285.06,
	4.97,
	-1703.76,
	14.97,
	3.55,
	-1275.6,
	-631.94,
	13.85,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	6,
	24
};

new gAtmCp[12];
new Float:gATM[12][3] = 
{
	{ 1238.11 , 328.388 , 19.4655 },
	{ 200.729 , -62.2478 , 1.47812 },
	{ 1367.99 , 393.505 , 19.43 },
	{ 661.348 , -555.223 , 15.9359 },
	{ -95.52 , 1083.22, 19.38 },
	{ -310.63 , 1052.44, 19.99 },
	{ 316.93, 1864.14, 1613.36 },
	{ 319.66, 1864.36, 1613.36 },
	{ 1103.09, -1428.22, 15.79 },
	{ 1123.76, -1528.68, 15.60 },
	{ 2209.87, -1149.79, 13.52 },
	{ 1147.44, -1771.95, 16.59 }
};

#define HorseTimerTextDrawLocX 547
#define HorseTimerTextDrawLocY 2
#define TimeOfHorseRaceHours 1
#define TimeOfHorseRaceMinutes 20
#define HorseCashLowerBounds 100
#define HorseCashHigherBounds 50000

enum mapIconInfo
{
	mIconId,
	Float:mPosX,
	Float:mPosY,
	Float:mPosZ,
	mType,
	mColor,
	mWorld,
	mInterior,
	mStreamDistance
};

new gMapIcon[MAX_MAP_ICONS][mapIconInfo];

enum publicAdsInfo
{
	mObjId,
	mOwner[MAX_PLAYER_NAME],
	Float:mObjPosX,
	Float:mObjPosY,
	Float:mObjPosZ,
	Float:mObjRotX,
	Float:mObjRotY,
	Float:mObjRotZ,
	mObjWorld,
	mCpId,
	Float:mCpPosX,
	Float:mCpPosY,
	Float:mCpPosZ,
	mCpWorld,
	mAdLine1Content[65],
	mAdLine1TimeLeft,
	mAdLine1Owner[MAX_PLAYER_NAME],
	mAdLine2Content[65],
	mAdLine2TimeLeft,
	mAdLine2Owner[MAX_PLAYER_NAME],
	mAdLine3Content[65],
	mAdLine3TimeLeft,
	mAdLine3Owner[MAX_PLAYER_NAME],
	mAdLine4Content[65],
	mAdLine4TimeLeft,
	mAdLine4Owner[MAX_PLAYER_NAME],
	mAdLine5Content[65],
	mAdLine5TimeLeft,
	mAdLine5Owner[MAX_PLAYER_NAME],
	mAdLine6Content[65],
	mAdLine6TimeLeft,
	mAdLine6Owner[MAX_PLAYER_NAME],
	mAdLine7Content[65],
	mAdLine7TimeLeft,
	mAdLine7Owner[MAX_PLAYER_NAME],
	mAdLine8Content[65],
	mAdLine8TimeLeft,
	mAdLine8Owner[MAX_PLAYER_NAME],
	mAdLine9Content[65],
	mAdLine9TimeLeft,
	mAdLine9Owner[MAX_PLAYER_NAME],
	mAdLine10Content[65],
	mAdLine10TimeLeft,
	mAdLine10Owner[MAX_PLAYER_NAME]
};
new gPublicAds[MAX_PUBLIC_ADS][publicAdsInfo];

enum pickupInfosInfo
{
	Float:mPosX,
	Float:mPosY,
	Float:mPosZ,
	mWorld,
	mInterior,
	mPickupModel,
	mPickupType,
	mInfoTextLine1[128],
	mInfoTextLine2[128],
	mInfoTextLine3[128],
	mInfoTextType,
	mPickupId,
	Text3D:m3dText1Id,
	Text3D:m3dText2Id,
	Text3D:m3dText3Id
};
new gPickupInfos[50][pickupInfosInfo];

new gSearchItemType;
new gSearchItemId;
new gSearchItemParam1 = -999;
new gSearchItemParam2 = -999;
new gSearchItemParam3 = -999;
new gSearchItemParam4 = -999;
new gSearchItemParam5[64];

enum playerReportsInfo
{
	mReportUsed,
	mReportTimeLeft,
	mReportContent[128],
	mReporter[MAX_PLAYER_NAME],
	mReported[MAX_PLAYER_NAME]
};
new gPlayersReports[30][playerReportsInfo];

enum lsLocationsInfo
{
	mLocationDescription[64],
	Float:mLocationPosCamX,
	Float:mLocationPosCamY,
	Float:mLocationPosCamZ,
	Float:mLocationPosCamLookX,
	Float:mLocationPosCamLookY,
	Float:mLocationPosCamLookZ,
	Float:mLocationPosX,
	Float:mLocationPosY,
	Float:mLocationPosZ,
	mLocationPosCp
};
new gLsLocations[21][lsLocationsInfo] = 
{
	{ "Urz¹d LS", 1502.14, -1742.16, 44.11, 1500.07, -1746.71, 42.00, 1479.72, -1793.05, 15.35 },
	{ "Policja LS", 1513.59, -1662.93, 33.83, 1518.37, -1664.37, 31.55, 1554.82, -1675.49, 16.19 },
	{ "Bank LS", 1506.96, -1616.02, 38.19, 1505.82, -1611.15, 35.18, 1498.46, -1581.63, 13.84 },
	{ "Biblioteka LS", 1306.01, -923.89, 50.60, 1307.96, -919.29, 49.02, 1316.61, -899.67, 39.57 },
	{ "MZGK przy policji", 1629.28, -1643.89, 25.34, 1624.40, -1644.98, 21.97, 1607.99, -1640.29, 13.54 },
	{ "MZGK przy dokach", 2209.15, -2179.58, 24.11, 2213.61, -2177.32, 21.57, 2226.15, -2177.99, 13.54 },
	{ "MZGK przy stadionie", 2800.40, -1606.34, 26.35, 2796.37, -1607.14, 23.51, 2785.66, -1611.90, 10.92 },
	{ "MZGK przy San News", 778.63, -1378.73, 22.42, 774.43, -1376.03, 19.86, 775.34, -1369.25, 13.52 },
	{ "Szpital przy centrum handlowym", 1206.33, -1314.47, 26.62, 1202.09, -1316.46, 24.86, 1172.78, -1323.76, 15.40 },
	{ "Szpital Jefferson", 2006.39, -1454.51, 39.99, 2009.10, -1450.30, 38.26, 2033.36, -1403.84, 17.27 },
	{ "Pêtla autobusowa", 1815.92, -1883.63, 27.43, 1812.23, -1887.01, 25.35, 1794.97, -1914.96, 13.39 },
	{ "WORD", 1151.44, -1746.38, 26.71, 1151.86, -1751.36, 24.35, 1153.83, -1771.47, 16.59 },
	{ "Fabryka broni", 2457.03, -2085.14, 20.43, 2457.42, -2090.12, 18.99, 2460.77, -2119.65, 13.55 },
	{ "Centrum handlowe", 1127.92, -1414.19, 47.32, 1128.01, -1419.19, 44.65, 1126.93, -1413.62, 25.89 },
	{ "Motel Jefferson", 2192.39, -1108.54, 48.58, 2194.20, -1112.77, 46.63, 2233.08, -1159.39, 25.89 },
	{ "Motel Idlewood", 2192.27, -1776.37, 30.30, 2189.24, -1780.35, 28.37, 2173.27, -1798.78, 13.36 },
	{ "Salon Samochodowy - Urzêdowy", 2127.61, -1123.50, 35.76, 2128.26, -1127.84, 33.35, 2131.73, -1152.57, 24.14 },
	{ "Hurtownia produktów - Flint Country", -98.99, -1128.31, 24.25, -103.66, -1126.53, 21.46, -130.51, -1118.26, 3.7 },
	{ "Hurtownia produktów - Blue Berry", 90.31, -205.67, 37.53, 90.55, -210.67, 35.38, 93.63, -271.4, 1.57 },
	{ "Hurtownia produktów - LVA Freight Depot", 1652.18, 917.51, 49.75, 1653.26, 922.39, 46.89, 1668.12, 948.23, 10.67 },
	{ "Wiêzienie", 1843.16, -1596.83, 41.58, 1838.99, -1594.06, 39.73, 1806.22, -1575.43, 13.44 }
};

enum taxiLocationsInfo
{
	mLocationDescription[64],
	Float:mPosX,
	Float:mPosY,
	Float:mPosZ,
	Float:mPosCamX,
	Float:mPosCamY,
	Float:mPosCamZ,
	Float:mPosCamLookX,
	Float:mPosCamLookY,
	Float:mPosCamLookZ
};
new gTaxiLocations[7][taxiLocationsInfo] = 
{
	{ "Urz¹d LS", 1480.226, -1739.641, 13.546, 1468.92, -1739.48, 18.77, 1473.86, -1738.68, 17.53 },
	{ "Policja LS", 1536.805, -1651.242, 13.546, 1517.25, -1661.67, 19.31, 1520.40, -1657.79, 18.20 },
	{ "WORD", 1166.669, -1767.476, 13.570, 1173.79, -1754.66, 19.28, 1173.45, -1759.65, 18.55 },
	{ "Centrum handlowe", 1136.792, -1413.789, 13.641, 1121.10, -1388.63, 23.71, 1125.27, -1391.39, 21.86 },
	{ "Motel Jefferson", 2239.412, -1146.886, 25.796, 2310.47, -1130.00, 50.97, 2306.12, -1132.47, 49.39 },
	{ "Motel Idlewood", 2193.372, -1800.218, 13.546, 2182.88, -1822.44, 25.20, 2183.50, -1817.48, 23.08 },
	{ "Lotnisko", 1718.722, -2328.082, -2.679, 1700.31, -2306.18, 5.70, 1705.07, -2307.72, 4.79}
};

enum prisonCellsInfo
{
	Float:mPosXCellEntrance,
	Float:mPosYCellEntrance,
	Float:mPosZCellEntrance,
	Float:mPosXInCell,
	Float:mPosYInCell,
	Float:mPosZInCell
}
new gPrisonCells[10][prisonCellsInfo] = 
{
	{ 189.373, 158.0, 1002.943, 189.373, 162.086, 1002.943 },
	{ 194.170, 158.0, 1002.909, 194.170, 162.151, 1002.909 },
	{ 198.251, 158.0, 1003.029, 198.251, 161.843, 1003.029 },
	{ 268.0, 77.528, 1001.039, 263.889, 77.528, 1001.039 },
	{ 215.657, 144.5, 999.015, 215.657, 110.859, 999.015 },
	{ 219.478, 144.5, 999.015, 219.478, 110.934, 999.015 },
	{ 223.612, 144.5, 999.015, 223.612, 110.776, 999.015 },
	{ 227.589, 144.5, 999.015, 227.589, 110.700, 999.015 },
	{ 322.0, 312.5, 999.14, 320.0, 312.5, 999.14 },
	{ 322.0, 316.5, 999.14, 320.0, 316.5, 999.14 }
};
new gPrisonCellsCp[10];

new Float:gMainPrisonPos[3] = { 1799.0, -1578.07, 14.07 };
new gMainPrisonCp;

new Indicators_xqz[MAX_VEHICLES][6];

new 
	Text:gHorse1, 
	Text:gHorse2,
	Text:gHorse3, 
	Text:gHorse4,
	Text:gHorseBG1,
	Text:gHorseBG2, 
	Text:gHorseStart, 
	Text:gHorseFinish,
	Text:gHorseStart2,
	Text:gHorseFinish2,
	gHorseCD,
	Text:gHorseCDTextDraw,
	Text:gHorseNum1,
	Text:gHorseNum2,
	Text:gHorseNum3,
	Text:gHorseNum4,
	gHorseAnimCount,
	Float:gHorsePosX1,
	Float:gHorsePosX2,
	Float:gHorsePosX3,
	Float:gHorsePosX4,
	gHorseStop,
	gHorseMoneyBet[CUSTOM_MAX_PLAYERS],
	gHorseBetOnHorse[CUSTOM_MAX_PLAYERS],
	gHorseRaceStarted,
	gHorseWatching[CUSTOM_MAX_PLAYERS],
	gHorsePrepared;

new MaleSkins[] =
{
	1, 2, 3, 4, 5, 6, 7, 8, 14, 15, 16, 17, 18, 19, 20, 21,
	22, 23, 24, 25, 26, 27, 28, 29, 30, 32, 33, 34, 35, 36,
	37, 38, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 57,
	58, 59, 60, 61, 62, 66, 67, 68, 70, 71, 72, 73, 78, 79,
	80, 81, 82, 83, 84, 86, 94, 95, 96, 97, 98, 99, 100, 101,
	102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113,
	114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125,
	126, 127, 128, 132, 133, 134, 135, 136, 137, 142, 143, 144,
	146, 147, 153, 154, 155, 156, 158, 159, 160, 161, 162, 163,
	164, 165, 166, 167, 168, 170, 171, 172, 173, 174, 175, 176,
	177, 179, 180, 181, 182, 183, 184, 185, 186, 187, 189, 200,
	202, 203, 204, 206, 208, 209, 210, 212, 213, 217, 220, 221,
	222, 223, 227, 228, 229, 230, 234, 235, 236, 239, 240, 241,
	242, 247, 248, 249, 250, 252, 253, 254, 255, 258, 259, 260,
	261, 262, 264, 268, 269, 270, 271, 272, 273, 289, 290, 291,
	292, 293, 294, 295, 296, 297, 299
};

new FemaleSkins[] = 
{
	9, 10, 11, 12, 13, 31, 39, 40, 41, 53, 54, 55, 56, 63, 64,
	65, 69, 75, 76, 77, 85, 87, 88, 89, 90, 91, 92, 93, 129, 130,
	131, 138, 139, 140, 141, 145, 148, 150, 152, 157, 169, 172,
	178, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 201,
	205, 207, 211, 214, 215, 216, 218, 219, 224, 225, 226, 231,
	232, 233, 237, 238, 243, 244, 245, 246, 251, 256, 257, 263,
	298
};
/*	
new Skins[] =
{
	0, 1, 2, 7, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
	20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33,
	34, 35, 36, 37, 38, 39, 40, 41, 43, 44, 45, 46, 47, 48,
	49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62,
	63, 64, 66, 67, 68, 69, 70, 71, 72, 73, 75, 76, 77, 78,
	79, 80, 81, 82, 83, 84, 85, 87, 88, 89, 90, 91, 92, 93,
	94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105,
	106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116,
	117, 118, 120, 121, 122, 123, 124, 125, 126, 127, 128,
	129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139,
	140, 141, 142, 143, 144, 145, 146, 147, 148, 150, 151,
	152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162,
	163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173,
	174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184,
	185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195,
	196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206,
	207, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218,
	219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229,
	230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240,
	241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251,
	252, 253, 254, 255, 256, 257, 258, 259, 260, 261, 262,
	263, 264, 265, 266, 267, 268, 269, 270, 271, 272, 274,
	275, 276, 277, 278, 279, 280, 281, 282, 283, 284, 285,
	286, 287, 288, 290, 291, 292, 293, 294, 295, 296, 297,
	298, 299
};*/