/***
*
* File: wp_vars_jobs.inc
* Auth: Damian Wojdat
* Date: 15.12.2011
* Desc: Variables related to jobs.
*
*************************************************************************************************************/

enum BusJobInfo
{
	Float:TakeJobX,
	Float:TakeJobY,
	Float:TakeJobZ,
	TakeJobWorld,
	TakeJobInterior,
	Float:TakeJobAngle,
	TakeJobPickupID,
};
new BusJob[BusJobInfo];

enum MzgkJobInfo
{
	Float:TakeJobX,
	Float:TakeJobY,
	Float:TakeJobZ,
	TakeJobWorld,
	TakeJobInterior,
	Float:TakeJobAngle,
	TakeJobPickupID,
	Float:CheckPoint0ax,
	Float:CheckPoint0ay,
	Float:CheckPoint0az,
	Float:CheckPoint1ax,
	Float:CheckPoint1ay,
	Float:CheckPoint1az,
	Float:CheckPoint2ax,
	Float:CheckPoint2ay,
	Float:CheckPoint2az,
	Float:CheckPoint3ax,
	Float:CheckPoint3ay,
	Float:CheckPoint3az,
	Float:CheckPoint4ax,
	Float:CheckPoint4ay,
	Float:CheckPoint4az,
	Float:CheckPoint5ax,
	Float:CheckPoint5ay,
	Float:CheckPoint5az,
	Float:CheckPoint6ax,
	Float:CheckPoint6ay,
	Float:CheckPoint6az,
	Float:CheckPoint7ax,
	Float:CheckPoint7ay,
	Float:CheckPoint7az,
	Float:CheckPoint8ax,
	Float:CheckPoint8ay,
	Float:CheckPoint8az,
	Float:CheckPoint9ax,
	Float:CheckPoint9ay,
	Float:CheckPoint9az,
	Float:CheckPoint10ax,
	Float:CheckPoint10ay,
	Float:CheckPoint10az,
	Float:CheckPoint11ax,
	Float:CheckPoint11ay,
	Float:CheckPoint11az,
	Float:CheckPoint0bx,
	Float:CheckPoint0by,
	Float:CheckPoint0bz,
	Float:CheckPoint1bx,
	Float:CheckPoint1by,
	Float:CheckPoint1bz,
	Float:CheckPoint2bx,
	Float:CheckPoint2by,
	Float:CheckPoint2bz,
	Float:CheckPoint3bx,
	Float:CheckPoint3by,
	Float:CheckPoint3bz,
	Float:CheckPoint4bx,
	Float:CheckPoint4by,
	Float:CheckPoint4bz,
	Float:CheckPoint5bx,
	Float:CheckPoint5by,
	Float:CheckPoint5bz,
	Float:CheckPoint6bx,
	Float:CheckPoint6by,
	Float:CheckPoint6bz,
	Float:CheckPoint7bx,
	Float:CheckPoint7by,
	Float:CheckPoint7bz,
	Float:CheckPoint8bx,
	Float:CheckPoint8by,
	Float:CheckPoint8bz,
	Float:CheckPoint9bx,
	Float:CheckPoint9by,
	Float:CheckPoint9bz,
	Float:CheckPoint10bx,
	Float:CheckPoint10by,
	Float:CheckPoint10bz,
	Float:CheckPoint11bx,
	Float:CheckPoint11by,
	Float:CheckPoint11bz,
};
new MzgkJob[MzgkJobInfo];

enum SweeperJobInfo
{
	Float:TakeJobX,
	Float:TakeJobY,
	Float:TakeJobZ,
	TakeJobWorld,
	TakeJobInterior,
	Float:TakeJobAngle,
	TakeJobPickupID,
	Float:CheckPoint0ax,
	Float:CheckPoint0ay,
	Float:CheckPoint0az,
	Float:CheckPoint1ax,
	Float:CheckPoint1ay,
	Float:CheckPoint1az,
	Float:CheckPoint2ax,
	Float:CheckPoint2ay,
	Float:CheckPoint2az,
	Float:CheckPoint3ax,
	Float:CheckPoint3ay,
	Float:CheckPoint3az,
	Float:CheckPoint4ax,
	Float:CheckPoint4ay,
	Float:CheckPoint4az,
	Float:CheckPoint5ax,
	Float:CheckPoint5ay,
	Float:CheckPoint5az,
	Float:CheckPoint6ax,
	Float:CheckPoint6ay,
	Float:CheckPoint6az,
	Float:CheckPoint7ax,
	Float:CheckPoint7ay,
	Float:CheckPoint7az,
	Float:CheckPoint8ax,
	Float:CheckPoint8ay,
	Float:CheckPoint8az,
	Float:CheckPoint9ax,
	Float:CheckPoint9ay,
	Float:CheckPoint9az,
	Float:CheckPoint10ax,
	Float:CheckPoint10ay,
	Float:CheckPoint10az,
	Float:CheckPoint11ax,
	Float:CheckPoint11ay,
	Float:CheckPoint11az,
	Float:CheckPoint0bx,
	Float:CheckPoint0by,
	Float:CheckPoint0bz,
	Float:CheckPoint1bx,
	Float:CheckPoint1by,
	Float:CheckPoint1bz,
	Float:CheckPoint2bx,
	Float:CheckPoint2by,
	Float:CheckPoint2bz,
	Float:CheckPoint3bx,
	Float:CheckPoint3by,
	Float:CheckPoint3bz,
	Float:CheckPoint4bx,
	Float:CheckPoint4by,
	Float:CheckPoint4bz,
	Float:CheckPoint5bx,
	Float:CheckPoint5by,
	Float:CheckPoint5bz,
	Float:CheckPoint6bx,
	Float:CheckPoint6by,
	Float:CheckPoint6bz,
	Float:CheckPoint7bx,
	Float:CheckPoint7by,
	Float:CheckPoint7bz,
	Float:CheckPoint8bx,
	Float:CheckPoint8by,
	Float:CheckPoint8bz,
	Float:CheckPoint9bx,
	Float:CheckPoint9by,
	Float:CheckPoint9bz,
	Float:CheckPoint10bx,
	Float:CheckPoint10by,
	Float:CheckPoint10bz,
	Float:CheckPoint11bx,
	Float:CheckPoint11by,
	Float:CheckPoint11bz,
};
new SweeperJob[SweeperJobInfo];

enum FarmerJobInfo
{
	Float:TakeJobX,
	Float:TakeJobY,
	Float:TakeJobZ,
	TakeJobWorld,
	TakeJobInterior,
	Float:TakeJobAngle,
	TakeJobPickupID,
	Float:CheckPoint0ax,
	Float:CheckPoint0ay,
	Float:CheckPoint0az,
	Float:CheckPoint1ax,
	Float:CheckPoint1ay,
	Float:CheckPoint1az,
	Float:CheckPoint2ax,
	Float:CheckPoint2ay,
	Float:CheckPoint2az,
	Float:CheckPoint3ax,
	Float:CheckPoint3ay,
	Float:CheckPoint3az,
	Float:CheckPoint4ax,
	Float:CheckPoint4ay,
	Float:CheckPoint4az,
	Float:CheckPoint0bx,
	Float:CheckPoint0by,
	Float:CheckPoint0bz,
	Float:CheckPoint1bx,
	Float:CheckPoint1by,
	Float:CheckPoint1bz,
	Float:CheckPoint2bx,
	Float:CheckPoint2by,
	Float:CheckPoint2bz,
	Float:CheckPoint3bx,
	Float:CheckPoint3by,
	Float:CheckPoint3bz,
	Float:CheckPoint4bx,
	Float:CheckPoint4by,
	Float:CheckPoint4bz,
	Float:CheckPoint5bx,
	Float:CheckPoint5by,
	Float:CheckPoint5bz,
	Float:CheckPoint6bx,
	Float:CheckPoint6by,
	Float:CheckPoint6bz,
	Float:CheckPoint7bx,
	Float:CheckPoint7by,
	Float:CheckPoint7bz,
	Float:CheckPoint8bx,
	Float:CheckPoint8by,
	Float:CheckPoint8bz,
	Float:CheckPoint9bx,
	Float:CheckPoint9by,
	Float:CheckPoint9bz,
	Float:CheckPoint10bx,
	Float:CheckPoint10by,
	Float:CheckPoint10bz,
	Float:CheckPoint11bx,
	Float:CheckPoint11by,
	Float:CheckPoint11bz,
	Float:CheckPoint12bx,
	Float:CheckPoint12by,
	Float:CheckPoint12bz,
	Float:CheckPoint13cx,
	Float:CheckPoint13cy,
	Float:CheckPoint13cz,
	Float:CheckPoint14cx,
	Float:CheckPoint14cy,
	Float:CheckPoint14cz,
	Float:CheckPoint15cx,
	Float:CheckPoint15cy,
	Float:CheckPoint15cz,
	Float:CheckPoint16cx,
	Float:CheckPoint16cy,
	Float:CheckPoint16cz,
	Float:CheckPoint17cx,
	Float:CheckPoint17cy,
	Float:CheckPoint17cz
};
new FarmerJob[FarmerJobInfo];	

enum SellerJobInfo
{
	Float:TakeJobX,
	Float:TakeJobY,
	Float:TakeJobZ,
	TakeJobWorld,
	TakeJobInterior,
	Float:TakeJobAngle,
	TakeJobPickupID
}
new SellerJob[SellerJobInfo];

enum AccountantJobInfo
{
	Float:TakeJobX,
	Float:TakeJobY,
	Float:TakeJobZ,
	TakeJobWorld,
	TakeJobInterior,
	Float:TakeJobAngle,
	TakeJobPickupID
}
new AccountantJob[SellerJobInfo];

enum  NewsBoyJobInfo 
{
	Float:TakeJobX,
	Float:TakeJobY,
	Float:TakeJobZ,
	Float:TakeJobAngle,
	TakeJobWorld,
	TakeJobInterior,
	TakeJobPickupID,
	TakeJobPapersCount,
	TakeJobReward
}
new NewsBoyJob[NewsBoyJobInfo];	

enum TaxiJobInfo
{
	Float:TakeJobX,
	Float:TakeJobY,
	Float:TakeJobZ,
	TakeJobWorld,
	TakeJobInterior,
	Float:TakeJobAngle,
	TakeJobPickupID
};
new TaxiJob[TaxiJobInfo];

enum WFWorkerJobInfo
{
	Float:TakeJobX,
	Float:TakeJobY,
	Float:TakeJobZ,
	TakeJobWorld,
	TakeJobInterior,
	Float:TakeJobAngle,
	TakeJobPickupID,
	TakeJobPickupID2,
	TakeJobPickupID3,
	TakeJobPickupID4,
	TakeJobPickupID5,
	TakeJobPickupID6,
	TakeJobPickupID7
};
new WFWorkerJob[WFWorkerJobInfo];

enum MechanicJobInfo
{
	Float:TakeJobX,
	Float:TakeJobY,
	Float:TakeJobZ,
	TakeJobWorld,
	TakeJobInterior,
	Float:TakeJobAngle,
	TakeJobPickupID,
};
new MechanicJob[MechanicJobInfo];

enum MechanicJobInfo1
{
	Float:RepairPointX,
	Float:RepairPointY,
	Float:RepairPointZ,
	Float:RepairPointX2,
	Float:RepairPointY2,
	Float:RepairPointZ2,
	Float:RepairPointX3[10],
	Float:RepairPointY3[10],
	Float:RepairPointZ3[10],
	RepairPointPickupID,
	RepairPointPickupID2,
	RepairPointPickupID3[10],
};
new MechanicJob1[MechanicJobInfo1];

enum MechanicJobInfo2
{
	Float:BuyProductsX,
	Float:BuyProductsY,
	Float:BuyProductsZ,
	BuyProductsWorld,
	BuyProductsInterior,
	Float:BuyProductsAngle,
	BuyProductsPickupID,
};
new MechanicJob2[MechanicJobInfo2];
	
enum ProductsSellerJobInfo
{
	Float:TakeJobX,
	Float:TakeJobY,
	Float:TakeJobZ,
	TakeJobWorld,
	TakeJobInterior,
	Float:TakeJobAngle,
	TakeJobPickupID,
 	Float:BuyProductsX,
	Float:BuyProductsY,
	Float:BuyProductsZ,
	BuyProductsWorld,
	BuyProductsInterior,
	Float:BuyProductsAngle,
	BuyProductsPickupID,
};
new ProductsSellerJob[ProductsSellerJobInfo];

enum WhoreJobInfo
{
	Float:TakeJobX,
	Float:TakeJobY,
	Float:TakeJobZ,
	TakeJobWorld,
	TakeJobInterior,
	Float:TakeJobAngle,
	TakeJobPickupID,
};
new WhoreJob[WhoreJobInfo];

enum DirJobInfo
{
	Float:TakeJobX,
	Float:TakeJobY,
	Float:TakeJobZ,
	TakeJobWorld,
	TakeJobInterior,
	Float:TakeJobAngle,
	TakeJobPickupID,
};
new DirJob[DirJobInfo];

enum StuntJobInfo
{
	Float:TakeJobX,
	Float:TakeJobY,
	Float:TakeJobZ,
	TakeJobWorld,
	TakeJobInterior,
	Float:TakeJobAngle,
	TakeJobPickupID,
};
new StuntJob[StuntJobInfo];

enum CarjackJobInfo
{
	Float:TakeJobX,
	Float:TakeJobY,
	Float:TakeJobZ,
	TakeJobWorld,
	TakeJobInterior,
	Float:TakeJobAngle,
	TakeJobPickupID,
};
new CarjackJob[CarjackJobInfo];

enum BodyJobInfo
{
	Float:TakeJobX,
	Float:TakeJobY,
	Float:TakeJobZ,
	TakeJobWorld,
	TakeJobInterior,
	Float:TakeJobAngle,
	TakeJobPickupID,
};
new BodyJob[BodyJobInfo];

enum RapistJobInfo
{
	Float:TakeJobX,
	Float:TakeJobY,
	Float:TakeJobZ,
	TakeJobWorld,
	TakeJobInterior,
	Float:TakeJobAngle,
	TakeJobPickupID,
};
new RapistJob[RapistJobInfo];

enum BoxerJobInfo
{
	Float:TakeJobX,
	Float:TakeJobY,
	Float:TakeJobZ,
	TakeJobWorld,
	TakeJobInterior,
	Float:TakeJobAngle,
	TakeJobPickupID,
};
new BoxerJob[BoxerJobInfo];

enum GunJobInfo
{
	Float:TakeJobX,
	Float:TakeJobY,
	Float:TakeJobZ,
	TakeJobWorld,
	TakeJobInterior,
	Float:TakeJobAngle,
	TakeJobPickupID,
 	Float:BuyPackagesX,
	Float:BuyPackagesY,
	Float:BuyPackagesZ,
	BuyPackagesWorld,
	BuyPackagesInterior,
	Float:BuyPackagesAngle,
	BuyPackagesPickupID,
  	Float:DeliverX,
	Float:DeliverY,
	Float:DeliverZ,
	DeliverWorld,
	DeliverInterior,
	Float:DeliverAngle,
	DeliverPickupID,
};
new GunJob[GunJobInfo];

enum DrugJobInfo
{
	Float:TakeJobX,
	Float:TakeJobY,
	Float:TakeJobZ,
	TakeJobWorld,
	TakeJobInterior,
	Float:TakeJobAngle,
	TakeJobPickupID,
 	Float:BuyDrugsX,
	Float:BuyDrugsY,
	Float:BuyDrugsZ,
	BuyDrugsWorld,
	BuyDrugsInterior,
	Float:BuyDrugsAngle,
	BuyDrugsPickupID,
  	Float:DeliverX,
	Float:DeliverY,
	Float:DeliverZ,
	DeliverWorld,
	DeliverInterior,
	Float:DeliverAngle,
	DeliverPickupID,
};
new DrugJob[DrugJobInfo];

enum DetectiveJobLocation
{
	Float:X,
	Float:Y,
	Float:Z,
	World,
	Interior,
	Float:Angle,
	PickupID,
};
new DetectiveJobPosition[DetectiveJobLocation];

enum LawyerJobLocation
{
	Float:X,
	Float:Y,
	Float:Z,
	World,
	Interior,
	Float:Angle,
	PickupID,
};
new LawyerJobPosition[LawyerJobLocation];

