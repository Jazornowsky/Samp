/***
*
* File: wp_utils_public_ads.inc
* Auth: Damian Wojdat
* Date: 02.08.2013
* Desc: Internal script function related to public ads.
*
*************************************************************************************************************/

timer RefreshPublicAd[2000](adId)
{
	new string[690];
	format(string, sizeof(string), "");
	
	format(string, sizeof(string), "\n\n%s", gPublicAds[adId][mAdLine1Content]);	
	if(strlen(gPublicAds[adId][mAdLine2Content]) > 0)
		format(string, sizeof(string), "%s\n\n%s", string, gPublicAds[adId][mAdLine2Content]);
	if(strlen(gPublicAds[adId][mAdLine3Content]) > 0)
		format(string, sizeof(string), "%s\n\n%s", string, gPublicAds[adId][mAdLine3Content]);
	if(strlen(gPublicAds[adId][mAdLine4Content]) > 0)	
		format(string, sizeof(string), "%s\n\n%s", string, gPublicAds[adId][mAdLine4Content]);
	if(strlen(gPublicAds[adId][mAdLine5Content]) > 0)	
		format(string, sizeof(string), "%s\n\n%s", string, gPublicAds[adId][mAdLine5Content]);
	if(strlen(gPublicAds[adId][mAdLine6Content]) > 0)	
		format(string, sizeof(string), "%s\n\n%s", string, gPublicAds[adId][mAdLine6Content]);
	if(strlen(gPublicAds[adId][mAdLine7Content]) > 0)	
		format(string, sizeof(string), "%s\n\n%s", string, gPublicAds[adId][mAdLine7Content]);
	if(strlen(gPublicAds[adId][mAdLine8Content]) > 0)	
		format(string, sizeof(string), "%s\n\n%s", string, gPublicAds[adId][mAdLine8Content]);
	if(strlen(gPublicAds[adId][mAdLine9Content]) > 0)	
		format(string, sizeof(string), "%s\n\n%s", string, gPublicAds[adId][mAdLine9Content]);
	if(strlen(gPublicAds[adId][mAdLine10Content]) > 0)	
		format(string, sizeof(string), "%s\n\n%s", string, gPublicAds[adId][mAdLine10Content]);
	
	SetDynamicObjectMaterialText(gPublicAds[adId][mObjId], 2, string, OBJECT_MATERIAL_SIZE_512x512, "Arial", 20, 0, 0xFFFFFFFF, 1, 1);
}