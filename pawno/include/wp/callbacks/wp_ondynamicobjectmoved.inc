/***
*
* File: wp_ondynamicobjectmoved.inc
* Auth: Damian Wojdat
* Date: 16.08.2013
* Desc: OnDynamicObjectMoved function.
*
*************************************************************************************************************/

public OnDynamicObjectMoved(objectid)
{
	if(objectid == gEvent1objects[4])
	{
		MoveDynamicObject(gEvent1objects[4], 226.50, 1870.90, 14.50, 3.0);
	}
	else if(objectid == gEvent1objects[5])
	{
		MoveDynamicObject(gEvent1objects[5], 238.06, 1795.42, 13.23, 3.0);
	}
	else if(objectid == gEvent1objects[6])
	{
		MoveDynamicObject(gEvent1objects[6], 233.75, 1824.34, 6.41, 3.0);
	}
	
	return 1;
}