/***
*
* File: wp_vars_weed.inc
* Auth: Damian Wojdat
* Date: 25.05.2012
* Desc: Variables related to weed mechanism.
*
*************************************************************************************************************/

enum weedInfo
{
	Float:mPosX,
	Float:mPosY,
	Float:mPosZ,
	mType,
	mPhase,
	mNextPhaseTimeLeft,
	mObjId
}
new gWeed[200][weedInfo];