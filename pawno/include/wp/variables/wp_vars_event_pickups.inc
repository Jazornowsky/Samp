/***
*
* File: wp_vars_event_pickups.inc
* Auth: Damian Wojdat
* Date: 19.08.2013
* Desc: Declarations, macros and variables.
*
*************************************************************************************************************/

enum pickupEventDataInfo
{
	Float:mPosX,
	Float:mPosY,
	Float:mPosZ,
	mPickupModel,
	mPickupID
};

new gPickupEventData[150][pickupEventDataInfo],
	gPickupEventCount,
	gPickupEventTime,
	gPickupEventCashPrize,
	gPickupEventMessage[256],
	gPickupEventNumber,
	Float:gPickupEventCenterPosX,
	Float:gPickupEventCenterPosY,
	Float:gPickupEventCenterPosZ,
	gPickupEventMapIcon,
	gPickupEventMapIconID = -1,
	gPickupEventPrizeType,
	gPickupEventItemType,
	gPickupEventItem,
	gPickupEventItemCount,
	gPickupEventPrizeReceive,
	gPickupEventID;