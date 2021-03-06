/***
*
* File: wp_saveloadjobdata.inc
* Auth: Damian Wojdat
* Date: 15.09.2011
* Desc: Loading functions.
* TODO: Transfer this to a better place.
*
*************************************************************************************************************/

LoadDetectiveJob()
{
	new arrCoords[7][64];
	new strFromFile2[256];
	new File: file = fopen("jobs/detectivejob.cfg", io_read);
	if (file)
	{
		fread(file, strFromFile2);
		split2(strFromFile2, arrCoords, '|');
		DetectiveJobPosition[X] = floatstr(arrCoords[0]);
		DetectiveJobPosition[Y] = floatstr(arrCoords[1]);
		DetectiveJobPosition[Z] = floatstr(arrCoords[2]);
		DetectiveJobPosition[World] = strval(arrCoords[3]);
		DetectiveJobPosition[Interior] = strval(arrCoords[4]);
		DetectiveJobPosition[Angle] = floatstr(arrCoords[5]);
		DetectiveJobPosition[PickupID] = strval(arrCoords[6]);
		DetectiveJobPosition[PickupID] = CreateDynamicPickup(1239,1,DetectiveJobPosition[X],DetectiveJobPosition[Y],DetectiveJobPosition[Z]);
		fclose(file);
		#if defined DEBUG
			print("[INFO:] Detective job loaded");
		#endif
	}
	else
		ErrorLog("[ERROR:] Can't load detectivejob.cfg");
	return 1;
}

SaveDetectiveJob()
{
	new File: file2;
	new coordsstring[512];
	format(coordsstring, sizeof(coordsstring), "%f|%f|%f|%d|%d|%f|%d\n",
	DetectiveJobPosition[X],
	DetectiveJobPosition[Y],
	DetectiveJobPosition[Z],
	DetectiveJobPosition[World],
	DetectiveJobPosition[Interior],
	DetectiveJobPosition[Angle],
	DetectiveJobPosition[PickupID]);
	file2 = fopen("jobs/detectivejob.cfg", io_write);
	if(file2)
	{
		fwrite(file2, coordsstring);
		fclose(file2);
	}
	else
		ErrorLog("[ERROR:] Can't save detectivejob.cfg");
	return 1;
}

LoadLawyerJob()
{
	new arrCoords[7][64];
	new strFromFile2[256];
	new File: file = fopen("jobs/lawyerjob.cfg", io_read);
	if (file)
	{
		fread(file, strFromFile2);
		split2(strFromFile2, arrCoords, '|');
		LawyerJobPosition[X] = floatstr(arrCoords[0]);
		LawyerJobPosition[Y] = floatstr(arrCoords[1]);
		LawyerJobPosition[Z] = floatstr(arrCoords[2]);
		LawyerJobPosition[World] = strval(arrCoords[3]);
		LawyerJobPosition[Interior] = strval(arrCoords[4]);
		LawyerJobPosition[Angle] = floatstr(arrCoords[5]);
		LawyerJobPosition[PickupID] = strval(arrCoords[6]);
		fclose(file);
		LawyerJobPosition[PickupID] = CreateDynamicPickup(1239,1,LawyerJobPosition[X],LawyerJobPosition[Y],LawyerJobPosition[Z]);
		#if defined DEBUG
			print("[INFO:] Lawyer job loaded");
		#endif
	}
	else
		ErrorLog("[ERROR:] Can't load lawyerjob.cfg");
	return 1;
}

SaveLawyerJob()
{
	new File: file2;
	new coordsstring[512];
	format(coordsstring, sizeof(coordsstring), "%f|%f|%f|%d|%d|%f|%d\n",
	LawyerJobPosition[X],
	LawyerJobPosition[Y],
	LawyerJobPosition[Z],
	LawyerJobPosition[World],
	LawyerJobPosition[Interior],
	LawyerJobPosition[Angle],
	LawyerJobPosition[PickupID]);
	file2 = fopen("jobs/lawyerjob.cfg", io_write);
	if(file2)
	{
		fwrite(file2, coordsstring);
		fclose(file2);
	}
	else
		ErrorLog("[ERROR:] Can't save lawyerjob.cfg ");
	return 1;
}

LoadBodyJob()
{
	new arrCoords[14][64];
	new strFromFile2[256];
	new File: file = fopen("jobs/bodyjob.cfg", io_read);
	if (file)
	{
		fread(file, strFromFile2);
		split2(strFromFile2, arrCoords, '|');
		BodyJob[TakeJobX] = floatstr(arrCoords[0]);
		BodyJob[TakeJobY] = floatstr(arrCoords[1]);
		BodyJob[TakeJobZ] = floatstr(arrCoords[2]);
		BodyJob[TakeJobWorld] = strval(arrCoords[3]);
		BodyJob[TakeJobInterior] = strval(arrCoords[4]);
		BodyJob[TakeJobAngle] = floatstr(arrCoords[5]);
		BodyJob[TakeJobPickupID] = strval(arrCoords[6]);
        BodyJob[TakeJobPickupID] = CreateDynamicPickup(1239,1,BodyJob[TakeJobX],BodyJob[TakeJobY],BodyJob[TakeJobZ]);
		fclose(file);
		#if defined DEBUG
			print("[INFO:] BoxGuard job loaded");
		#endif
	}
	else
		ErrorLog("[ERROR:] Can't load bodyjob.cfg");
	return 1;
}

SaveBodyJob()
{
	new File: file2;
	new coordsstring[512];
	format(coordsstring, sizeof(coordsstring), "%f|%f|%f|%d|%d|%f|%d|%f|%f|%f|%d|%d|%f|%d\n",
	BodyJob[TakeJobX],
	BodyJob[TakeJobY],
	BodyJob[TakeJobZ],
	BodyJob[TakeJobWorld],
	BodyJob[TakeJobInterior],
	BodyJob[TakeJobAngle],
	BodyJob[TakeJobPickupID]);
	file2 = fopen("jobs/bodyjob.cfg", io_write);
	if(file2)
	{
		fwrite(file2, coordsstring);
		fclose(file2);
	}
	else
		ErrorLog("[ERROR:] Can't save bodyjob.cfg ");
	return 1;
}

LoadRapistJob()
{
	new arrCoords[14][64];
	new strFromFile2[256];
	new File: file = fopen("jobs/rapistjob.cfg", io_read);
	if (file)
	{
		fread(file, strFromFile2);
		split2(strFromFile2, arrCoords, '|');
		RapistJob[TakeJobX] = floatstr(arrCoords[0]);
		RapistJob[TakeJobY] = floatstr(arrCoords[1]);
		RapistJob[TakeJobZ] = floatstr(arrCoords[2]);
		RapistJob[TakeJobWorld] = strval(arrCoords[3]);
		RapistJob[TakeJobInterior] = strval(arrCoords[4]);
		RapistJob[TakeJobAngle] = floatstr(arrCoords[5]);
		RapistJob[TakeJobPickupID] = strval(arrCoords[6]);
        RapistJob[TakeJobPickupID] = CreateDynamicPickup(1239,1,RapistJob[TakeJobX],RapistJob[TakeJobY],RapistJob[TakeJobZ]);
		fclose(file);
		#if defined DEBUG
			print("[INFO:] Rapist job loaded");
		#endif
	}
	else
		ErrorLog("[ERROR:] Can't load rapistjob.cfg");
	return 1;
}

SaveRapistJob()
{
	new File: file2;
	new coordsstring[512];
	format(coordsstring, sizeof(coordsstring), "%f|%f|%f|%d|%d|%f|%d|%f|%f|%f|%d|%d|%f|%d\n",
	RapistJob[TakeJobX],
	RapistJob[TakeJobY],
	RapistJob[TakeJobZ],
	RapistJob[TakeJobWorld],
	RapistJob[TakeJobInterior],
	RapistJob[TakeJobAngle],
	RapistJob[TakeJobPickupID]);
	file2 = fopen("jobs/rapistjob.cfg", io_write);
	if(file2)
	{
		fwrite(file2, coordsstring);
		fclose(file2);
	}
	else
		ErrorLog("[ERROR:] Can't save rapistjob.cfg ");
	return 1;
}

LoadBoxerJob()
{
	new arrCoords[14][64];
	new strFromFile2[256];
	new File: file = fopen("jobs/boxerjob.cfg", io_read);
	if (file)
	{
		fread(file, strFromFile2);
		split2(strFromFile2, arrCoords, '|');
		BoxerJob[TakeJobX] = floatstr(arrCoords[0]);
		BoxerJob[TakeJobY] = floatstr(arrCoords[1]);
		BoxerJob[TakeJobZ] = floatstr(arrCoords[2]);
		BoxerJob[TakeJobWorld] = strval(arrCoords[3]);
		BoxerJob[TakeJobInterior] = strval(arrCoords[4]);
		BoxerJob[TakeJobAngle] = floatstr(arrCoords[5]);
		BoxerJob[TakeJobPickupID] = strval(arrCoords[6]);
        BoxerJob[TakeJobPickupID] = CreateDynamicPickup(1239,1,BoxerJob[TakeJobX],BoxerJob[TakeJobY],BoxerJob[TakeJobZ]);
		fclose(file);
		#if defined DEBUG
			print("[INFO:] Boxer job loaded");
		#endif
	}
	else
		ErrorLog("[ERROR:] Can't load boxerjob.cfg");
	return 1;
}

SaveBoxerJob()
{
	new File: file2;
	new coordsstring[512];
	format(coordsstring, sizeof(coordsstring), "%f|%f|%f|%d|%d|%f|%d|%f|%f|%f|%d|%d|%f|%d\n",
	BoxerJob[TakeJobX],
	BoxerJob[TakeJobY],
	BoxerJob[TakeJobZ],
	BoxerJob[TakeJobWorld],
	BoxerJob[TakeJobInterior],
	BoxerJob[TakeJobAngle],
	BoxerJob[TakeJobPickupID]);
	file2 = fopen("jobs/boxerjob.cfg", io_write);
	if(file2)
	{
		fwrite(file2, coordsstring);
		fclose(file2);
	}
	else
		ErrorLog("[ERROR:] Can't save boxerjob.cfg ");
	return 1;
}

LoadDirJob()
{
	new arrCoords[14][64];
	new strFromFile2[256];
	new File: file = fopen("jobs/dirjob.cfg", io_read);
	if (file)
	{
		fread(file, strFromFile2);
		split2(strFromFile2, arrCoords, '|');
		DirJob[TakeJobX] = floatstr(arrCoords[0]);
		DirJob[TakeJobY] = floatstr(arrCoords[1]);
		DirJob[TakeJobZ] = floatstr(arrCoords[2]);
		DirJob[TakeJobWorld] = strval(arrCoords[3]);
		DirJob[TakeJobInterior] = strval(arrCoords[4]);
		DirJob[TakeJobAngle] = floatstr(arrCoords[5]);
		DirJob[TakeJobPickupID] = strval(arrCoords[6]);
        DirJob[TakeJobPickupID] = CreateDynamicPickup(1239,1,DirJob[TakeJobX],DirJob[TakeJobY],DirJob[TakeJobZ]);
		fclose(file);
		#if defined DEBUG
			print("[INFO:] Dir job loaded");
		#endif
	}
	else
		ErrorLog("[ERROR:] Can't load dirjob.cfg");
	return 1;
}

SaveDirJob()
{
	new File: file2;
	new coordsstring[512];
	format(coordsstring, sizeof(coordsstring), "%f|%f|%f|%d|%d|%f|%d|%f|%f|%f|%d|%d|%f|%d\n",
	DirJob[TakeJobX],
	DirJob[TakeJobY],
	DirJob[TakeJobZ],
	DirJob[TakeJobWorld],
	DirJob[TakeJobInterior],
	DirJob[TakeJobAngle],
	DirJob[TakeJobPickupID]);
	file2 = fopen("jobs/dirjob.cfg", io_write);
	if(file2)
	{
		fwrite(file2, coordsstring);
		fclose(file2);
	}
	else
		ErrorLog("[ERROR:] Can't save dirjob.cfg ");
	return 1;
}

LoadWhoreJob()
{
	new arrCoords[14][64];
	new strFromFile2[256];
	new File: file = fopen("jobs/whorejob.cfg", io_read);
	if (file)
	{
		fread(file, strFromFile2);
		split2(strFromFile2, arrCoords, '|');
		WhoreJob[TakeJobX] = floatstr(arrCoords[0]);
		WhoreJob[TakeJobY] = floatstr(arrCoords[1]);
		WhoreJob[TakeJobZ] = floatstr(arrCoords[2]);
		WhoreJob[TakeJobWorld] = strval(arrCoords[3]);
		WhoreJob[TakeJobInterior] = strval(arrCoords[4]);
		WhoreJob[TakeJobAngle] = floatstr(arrCoords[5]);
		WhoreJob[TakeJobPickupID] = strval(arrCoords[6]);
        WhoreJob[TakeJobPickupID] = CreateDynamicPickup(1239,1,WhoreJob[TakeJobX],WhoreJob[TakeJobY],WhoreJob[TakeJobZ]);
		fclose(file);
		#if defined DEBUG
			print("[INFO:] Whore job loaded");
		#endif
	}
	else
		ErrorLog("[ERROR:] Can't load whirejob.cfg");
	return 1;
}

SaveWhoreJob()
{
	new File: file2;
	new coordsstring[512];
	format(coordsstring, sizeof(coordsstring), "%f|%f|%f|%d|%d|%f|%d|%f|%f|%f|%d|%d|%f|%d\n",
	WhoreJob[TakeJobX],
	WhoreJob[TakeJobY],
	WhoreJob[TakeJobZ],
	WhoreJob[TakeJobWorld],
	WhoreJob[TakeJobInterior],
	WhoreJob[TakeJobAngle],
	WhoreJob[TakeJobPickupID]);
	file2 = fopen("jobs/whorejob.cfg", io_write);
	if(file2)
	{
		fwrite(file2, coordsstring);
		fclose(file2);
	}
	else
		ErrorLog("[ERROR:] Can't save whorejob.cfg ");
	return 1;
}

LoadStuntJob()
{
	new arrCoords[14][64];
	new strFromFile2[256];
	new File: file = fopen("jobs/stuntjob.cfg", io_read);
	if (file)
	{
		fread(file, strFromFile2);
		split2(strFromFile2, arrCoords, '|');
		StuntJob[TakeJobX] = floatstr(arrCoords[0]);
		StuntJob[TakeJobY] = floatstr(arrCoords[1]);
		StuntJob[TakeJobZ] = floatstr(arrCoords[2]);
		StuntJob[TakeJobWorld] = strval(arrCoords[3]);
		StuntJob[TakeJobInterior] = strval(arrCoords[4]);
		StuntJob[TakeJobAngle] = floatstr(arrCoords[5]);
		StuntJob[TakeJobPickupID] = strval(arrCoords[6]);
        StuntJob[TakeJobPickupID] = CreateDynamicPickup(1239,1,StuntJob[TakeJobX],StuntJob[TakeJobY],StuntJob[TakeJobZ]);
		fclose(file);
		#if defined DEBUG
			print("[INFO:] Stunt job loaded");
		#endif
	}
	else
		ErrorLog("[ERROR:] Can't load stuntjob.cfg");
	return 1;
}

SaveStuntJob()
{
	new File: file2;
	new coordsstring[512];
	format(coordsstring, sizeof(coordsstring), "%f|%f|%f|%d|%d|%f|%d|%f|%f|%f|%d|%d|%f|%d\n",
	StuntJob[TakeJobX],
	StuntJob[TakeJobY],
	StuntJob[TakeJobZ],
	StuntJob[TakeJobWorld],
	StuntJob[TakeJobInterior],
	StuntJob[TakeJobAngle],
	StuntJob[TakeJobPickupID]);
	file2 = fopen("jobs/stuntjob.cfg", io_write);
	if(file2)
	{
		fwrite(file2, coordsstring);
		fclose(file2);
	}
	else
		ErrorLog("[ERROR:] Can't save stuntjob.cfg");
	return 1;
}

LoadCarjackJob()
{
	new arrCoords[14][64];
	new strFromFile2[256];
	new File: file = fopen("jobs/carjackjob.cfg", io_read);
	if (file)
	{
		fread(file, strFromFile2);
		split2(strFromFile2, arrCoords, '|');
		CarjackJob[TakeJobX] = floatstr(arrCoords[0]);
		CarjackJob[TakeJobY] = floatstr(arrCoords[1]);
		CarjackJob[TakeJobZ] = floatstr(arrCoords[2]);
		CarjackJob[TakeJobWorld] = strval(arrCoords[3]);
		CarjackJob[TakeJobInterior] = strval(arrCoords[4]);
		CarjackJob[TakeJobAngle] = floatstr(arrCoords[5]);
		CarjackJob[TakeJobPickupID] = strval(arrCoords[6]);
        CarjackJob[TakeJobPickupID] = CreateDynamicPickup(1239,1,CarjackJob[TakeJobX],CarjackJob[TakeJobY],CarjackJob[TakeJobZ]);
		fclose(file);
		#if defined DEBUG
			print("[INFO:] Carjack job loaded");
		#endif
	}
	else
		ErrorLog("[ERROR:] Can't load carjackjob.cfg");
	return 1;
}

SaveCarjackJob()
{
	new File: file2;
	new coordsstring[512];
	format(coordsstring, sizeof(coordsstring), "%f|%f|%f|%d|%d|%f|%d|%f|%f|%f|%d|%d|%f|%d\n",
	CarjackJob[TakeJobX],
	CarjackJob[TakeJobY],
	CarjackJob[TakeJobZ],
	CarjackJob[TakeJobWorld],
	CarjackJob[TakeJobInterior],
	CarjackJob[TakeJobAngle],
	CarjackJob[TakeJobPickupID]);
	file2 = fopen("jobs/carjackjob.cfg", io_write);
	if(file2)
	{
		fwrite(file2, coordsstring);
		fclose(file2);
	}
	else
		ErrorLog("[ERROR:] Can't save carjackjob.cfg");
	return 1;
}

LoadProductsSellerJob()
{
	new arrCoords[14][64];
	new strFromFile2[256];
	new File: file = fopen("jobs/productsellersjob.cfg", io_read);
	if (file)
	{
		fread(file, strFromFile2);
		split2(strFromFile2, arrCoords, '|');
		ProductsSellerJob[TakeJobX] = floatstr(arrCoords[0]);
		ProductsSellerJob[TakeJobY] = floatstr(arrCoords[1]);
		ProductsSellerJob[TakeJobZ] = floatstr(arrCoords[2]);
		ProductsSellerJob[TakeJobWorld] = strval(arrCoords[3]);
		ProductsSellerJob[TakeJobInterior] = strval(arrCoords[4]);
		ProductsSellerJob[TakeJobAngle] = floatstr(arrCoords[5]);
        ProductsSellerJob[TakeJobPickupID] = CreateDynamicPickup(1239,1,ProductsSellerJob[TakeJobX],ProductsSellerJob[TakeJobY],ProductsSellerJob[TakeJobZ]);
		fclose(file);
		#if defined DEBUG
			print("[INFO:] Products seller job loaded");
		#endif
	}
	else
		ErrorLog("[ERROR:] Can't load productsellersjob.cfg");
	return 1;
}

SaveProductsSellerJob()
{
	new File: file2;
	new coordsstring[512];
	format(coordsstring, sizeof(coordsstring), "%f|%f|%f|%d|%d|%f|\n",
	ProductsSellerJob[TakeJobX],
	ProductsSellerJob[TakeJobY],
	ProductsSellerJob[TakeJobZ],
	ProductsSellerJob[TakeJobWorld],
	ProductsSellerJob[TakeJobInterior],
	ProductsSellerJob[TakeJobAngle]);

	file2 = fopen("jobs/productsellersjob.cfg", io_write);
	if(file2)
	{
		fwrite(file2, coordsstring);
		fclose(file2);
	}
	else
		ErrorLog("[ERROR:] Can't save productsellersjob.cfg");
	return 1;
}

LoadMechanicJob()
{
	new arrCoords[14][64];
	new strFromFile2[256];
	new File: file = fopen("jobs/mechanicjob.cfg", io_read);
	if (file)
	{
		fread(file, strFromFile2);
		split2(strFromFile2, arrCoords, '|');
		MechanicJob[TakeJobX] = floatstr(arrCoords[0]);
		MechanicJob[TakeJobY] = floatstr(arrCoords[1]);
		MechanicJob[TakeJobZ] = floatstr(arrCoords[2]);
		MechanicJob[TakeJobWorld] = strval(arrCoords[3]);
		MechanicJob[TakeJobInterior] = strval(arrCoords[4]);
		MechanicJob[TakeJobAngle] = floatstr(arrCoords[5]);
		MechanicJob[TakeJobPickupID] = strval(arrCoords[6]);
        MechanicJob[TakeJobPickupID] = CreateDynamicPickup(1239,1,MechanicJob[TakeJobX],MechanicJob[TakeJobY],MechanicJob[TakeJobZ]);
		fclose(file);
		#if defined DEBUG
			print("[INFO:] Mechanic job loaded");
		#endif
	}
	else
		ErrorLog("[ERROR:] Can't load mechanicjob.cfg");
	return 1;
}

SaveMechanicJob()
{
	new File: file2;
	new coordsstring[512];
	format(coordsstring, sizeof(coordsstring), "%f|%f|%f|%d|%d|%f|%d\n",
	MechanicJob[TakeJobX],
	MechanicJob[TakeJobY],
	MechanicJob[TakeJobZ],
	MechanicJob[TakeJobWorld],
	MechanicJob[TakeJobInterior],
	MechanicJob[TakeJobAngle],
	MechanicJob[TakeJobPickupID]);

	file2 = fopen("jobs/mechanicjob.cfg", io_write);
	if(file2)
	{
		fwrite(file2, coordsstring);
		fclose(file2);
	}
	else
		ErrorLog("[ERROR:] Can't save mechanicjob.cfg");
	return 1;
}

LoadMechanicJob1()
{
	new arrCoords[36][64];
	new strFromFile2[256];
	new File: file = fopen("jobs/mechanicjob1.cfg", io_read);
	if (file)
	{
		fread(file, strFromFile2);
		split2(strFromFile2, arrCoords, '|');
		MechanicJob1[RepairPointX] = floatstr(arrCoords[0]);
		MechanicJob1[RepairPointY] = floatstr(arrCoords[1]);
		MechanicJob1[RepairPointZ] = floatstr(arrCoords[2]);
		MechanicJob1[RepairPointX2] = floatstr(arrCoords[3]);
		MechanicJob1[RepairPointY2] = floatstr(arrCoords[4]);
		MechanicJob1[RepairPointZ2] = floatstr(arrCoords[5]);
		MechanicJob1[RepairPointX3][0] = floatstr(arrCoords[6]);
		MechanicJob1[RepairPointY3][0] = floatstr(arrCoords[7]);
		MechanicJob1[RepairPointZ3][0] = floatstr(arrCoords[8]);
		MechanicJob1[RepairPointX3][1] = floatstr(arrCoords[9]);
		MechanicJob1[RepairPointY3][1] = floatstr(arrCoords[10]);
		MechanicJob1[RepairPointZ3][1] = floatstr(arrCoords[11]);
		MechanicJob1[RepairPointX3][2] = floatstr(arrCoords[12]);
		MechanicJob1[RepairPointY3][2] = floatstr(arrCoords[13]);
		MechanicJob1[RepairPointZ3][2] = floatstr(arrCoords[14]);
		MechanicJob1[RepairPointX3][3] = floatstr(arrCoords[15]);
		MechanicJob1[RepairPointY3][3] = floatstr(arrCoords[16]);
		MechanicJob1[RepairPointZ3][3] = floatstr(arrCoords[17]);
		MechanicJob1[RepairPointX3][4] = floatstr(arrCoords[18]);
		MechanicJob1[RepairPointY3][4] = floatstr(arrCoords[19]);
		MechanicJob1[RepairPointZ3][4] = floatstr(arrCoords[20]);
		MechanicJob1[RepairPointX3][5] = floatstr(arrCoords[21]);
		MechanicJob1[RepairPointY3][5] = floatstr(arrCoords[23]);
		MechanicJob1[RepairPointZ3][5] = floatstr(arrCoords[23]);
		MechanicJob1[RepairPointX3][6] = floatstr(arrCoords[24]);
		MechanicJob1[RepairPointY3][6] = floatstr(arrCoords[25]);
		MechanicJob1[RepairPointZ3][6] = floatstr(arrCoords[26]);
		MechanicJob1[RepairPointX3][7] = floatstr(arrCoords[27]);
		MechanicJob1[RepairPointY3][7] = floatstr(arrCoords[28]);
		MechanicJob1[RepairPointZ3][7] = floatstr(arrCoords[29]);
		MechanicJob1[RepairPointX3][8] = floatstr(arrCoords[30]);
		MechanicJob1[RepairPointY3][8] = floatstr(arrCoords[31]);
		MechanicJob1[RepairPointZ3][8] = floatstr(arrCoords[33]);
		MechanicJob1[RepairPointX3][9] = floatstr(arrCoords[33]);
		MechanicJob1[RepairPointY3][9] = floatstr(arrCoords[34]);
		MechanicJob1[RepairPointZ3][9] = floatstr(arrCoords[35]);
		MechanicJob1[RepairPointPickupID] = CreateDynamicPickup(1239,1,MechanicJob1[RepairPointX],MechanicJob1[RepairPointY],MechanicJob1[RepairPointZ]);
		MechanicJob1[RepairPointPickupID2] = CreateDynamicPickup(1239,1,MechanicJob1[RepairPointX2],MechanicJob1[RepairPointY2],MechanicJob1[RepairPointZ2]);
		MechanicJob1[RepairPointPickupID3][0] = CreateDynamicPickup(1239,1,MechanicJob1[RepairPointX3][0],MechanicJob1[RepairPointY3][0],MechanicJob1[RepairPointZ3][0]);
		MechanicJob1[RepairPointPickupID3][1] = CreateDynamicPickup(1239,1,MechanicJob1[RepairPointX3][1],MechanicJob1[RepairPointY3][1],MechanicJob1[RepairPointZ3][1]);
		MechanicJob1[RepairPointPickupID3][2] = CreateDynamicPickup(1239,1,MechanicJob1[RepairPointX3][2],MechanicJob1[RepairPointY3][2],MechanicJob1[RepairPointZ3][2]);
		MechanicJob1[RepairPointPickupID3][3] = CreateDynamicPickup(1239,1,MechanicJob1[RepairPointX3][3],MechanicJob1[RepairPointY3][3],MechanicJob1[RepairPointZ3][3]);
		MechanicJob1[RepairPointPickupID3][4] = CreateDynamicPickup(1239,1,MechanicJob1[RepairPointX3][4],MechanicJob1[RepairPointY3][4],MechanicJob1[RepairPointZ3][4]);
		MechanicJob1[RepairPointPickupID3][5] = CreateDynamicPickup(1239,1,MechanicJob1[RepairPointX3][5],MechanicJob1[RepairPointY3][5],MechanicJob1[RepairPointZ3][5]);
		MechanicJob1[RepairPointPickupID3][6] = CreateDynamicPickup(1239,1,MechanicJob1[RepairPointX3][6],MechanicJob1[RepairPointY3][6],MechanicJob1[RepairPointZ3][6]);
		MechanicJob1[RepairPointPickupID3][7] = CreateDynamicPickup(1239,1,MechanicJob1[RepairPointX3][7],MechanicJob1[RepairPointY3][7],MechanicJob1[RepairPointZ3][7]);
		MechanicJob1[RepairPointPickupID3][8] = CreateDynamicPickup(1239,1,MechanicJob1[RepairPointX3][8],MechanicJob1[RepairPointY3][8],MechanicJob1[RepairPointZ3][8]);
		MechanicJob1[RepairPointPickupID3][9] = CreateDynamicPickup(1239,1,MechanicJob1[RepairPointX3][9],MechanicJob1[RepairPointY3][9],MechanicJob1[RepairPointZ3][9]);
		fclose(file);
		#if defined DEBUG
			print("[INFO:] Mechanic job point 1 to 10 loaded");
		#endif
	}
	else
		ErrorLog("[ERROR:] Can't load mechanicjob1.cfg");
	return 1;
}

stock SaveMechanicJob1()
{
	new File: file2;
	new coordsstring[512];
	format(coordsstring, sizeof(coordsstring), "%f|%f|%f|%f|%f|%f|%f|%f|%f|%f|%f|%f|%f|%f|%f|%f|%f|%f|%f|%f|%f|%f|%f|%f|%f|%f|%f|%f|%f|%f|%f|%f|%f|%f|%f|%f\n",
	MechanicJob1[RepairPointX],
	MechanicJob1[RepairPointY],
	MechanicJob1[RepairPointZ],
	MechanicJob1[RepairPointX2],
	MechanicJob1[RepairPointY2],
	MechanicJob1[RepairPointZ2],
	MechanicJob1[RepairPointX3][0],
	MechanicJob1[RepairPointY3][0],
	MechanicJob1[RepairPointZ3][0],
	MechanicJob1[RepairPointX3][1],
	MechanicJob1[RepairPointY3][1],
	MechanicJob1[RepairPointZ3][1],
	MechanicJob1[RepairPointX3][2],
	MechanicJob1[RepairPointY3][2],
	MechanicJob1[RepairPointZ3][2],
	MechanicJob1[RepairPointX3][3],
	MechanicJob1[RepairPointY3][3],
	MechanicJob1[RepairPointZ3][3],
	MechanicJob1[RepairPointX3][4],
	MechanicJob1[RepairPointY3][4],
	MechanicJob1[RepairPointZ3][4],
	MechanicJob1[RepairPointX3][5],
	MechanicJob1[RepairPointY3][5],
	MechanicJob1[RepairPointZ3][5],
	MechanicJob1[RepairPointX3][6],
	MechanicJob1[RepairPointY3][6],
	MechanicJob1[RepairPointZ3][6],
	MechanicJob1[RepairPointX3][7],
	MechanicJob1[RepairPointY3][7],
	MechanicJob1[RepairPointZ3][7],
	MechanicJob1[RepairPointX3][8],
	MechanicJob1[RepairPointY3][8],
	MechanicJob1[RepairPointZ3][8],
	MechanicJob1[RepairPointX3][9],
	MechanicJob1[RepairPointY3][9],
	MechanicJob1[RepairPointZ3][9]);
	file2 = fopen("jobs/mechanicjob1.cfg", io_write);
	if(file2)
	{
		fwrite(file2, coordsstring);
		fclose(file2);
	}
	else
		ErrorLog("[ERROR:] Can't save mechanicjob1.cfg");
	return 1;
}
LoadMechanicJob2()
{
	new arrCoords[7][64];
	new strFromFile2[128];
	new File: file = fopen("jobs/mechanicjob2.cfg", io_read);
	if (file)
	{
		fread(file, strFromFile2);
		split2(strFromFile2, arrCoords, '|');
		MechanicJob2[BuyProductsX] = floatstr(arrCoords[0]);
		MechanicJob2[BuyProductsY] = floatstr(arrCoords[1]);
		MechanicJob2[BuyProductsZ] = floatstr(arrCoords[2]);
		MechanicJob2[BuyProductsWorld] = strval(arrCoords[3]);
		MechanicJob2[BuyProductsInterior] = strval(arrCoords[4]);
		MechanicJob2[BuyProductsAngle] = floatstr(arrCoords[5]);
		MechanicJob2[BuyProductsPickupID] = strval(arrCoords[6]);
        MechanicJob2[BuyProductsPickupID] = CreateDynamicPickup(1239,1,MechanicJob2[BuyProductsX],MechanicJob2[BuyProductsY],MechanicJob2[BuyProductsZ]);
		fclose(file);
		#if defined DEBUG
			print("[INFO:] Mechanic job point 2 loaded");
		#endif
	}
	else
		ErrorLog("[ERROR:] Can't load mechanicjob2.cfg");
	return 1;
}

SaveMechanicJob2()
{
	new File: file2;
	new coordsstring[512];
	format(coordsstring, sizeof(coordsstring), "%f|%f|%f|%d|%d|%f|%d\n",
	MechanicJob2[BuyProductsX],
	MechanicJob2[BuyProductsY],
	MechanicJob2[BuyProductsZ],
	MechanicJob2[BuyProductsWorld],
	MechanicJob2[BuyProductsInterior],
	MechanicJob2[BuyProductsAngle],
	MechanicJob2[BuyProductsPickupID]);

	file2 = fopen("jobs/mechanicjob2.cfg", io_write);
	if(file2)
	{
		fwrite(file2, coordsstring);
		fclose(file2);
	}
	else
		ErrorLog("[ERROR:] Can't save mechanicjob2.cfg");
	return 1;
}

LoadGunJob()
{
	new arrCoords[21][64];
	new strFromFile2[256];
	new File: file = fopen("jobs/gunjob.cfg", io_read);
	if (file)
	{
		fread(file, strFromFile2);
		split2(strFromFile2, arrCoords, '|');
		GunJob[TakeJobX] = floatstr(arrCoords[0]);
		GunJob[TakeJobY] = floatstr(arrCoords[1]);
		GunJob[TakeJobZ] = floatstr(arrCoords[2]);
		GunJob[TakeJobWorld] = strval(arrCoords[3]);
		GunJob[TakeJobInterior] = strval(arrCoords[4]);
		GunJob[TakeJobAngle] = floatstr(arrCoords[5]);
		GunJob[TakeJobPickupID] = strval(arrCoords[6]);
        GunJob[TakeJobPickupID] = CreateDynamicPickup(1239,1,GunJob[TakeJobX],GunJob[TakeJobY],GunJob[TakeJobZ]);
		GunJob[BuyPackagesX] = floatstr(arrCoords[7]);
		GunJob[BuyPackagesY] = floatstr(arrCoords[8]);
		GunJob[BuyPackagesZ] = floatstr(arrCoords[9]);
		GunJob[BuyPackagesWorld] = strval(arrCoords[10]);
		GunJob[BuyPackagesInterior] = strval(arrCoords[11]);
		GunJob[BuyPackagesAngle] = floatstr(arrCoords[12]);
		GunJob[BuyPackagesPickupID] = strval(arrCoords[13]);
        GunJob[BuyPackagesPickupID] = CreateDynamicPickup(1239,1,GunJob[BuyPackagesX],GunJob[BuyPackagesY],GunJob[BuyPackagesZ]);
        GunJob[DeliverX] = floatstr(arrCoords[14]);
		GunJob[DeliverY] = floatstr(arrCoords[15]);
		GunJob[DeliverZ] = floatstr(arrCoords[16]);
		GunJob[DeliverWorld] = strval(arrCoords[17]);
		GunJob[DeliverInterior] = strval(arrCoords[18]);
		GunJob[DeliverAngle] = floatstr(arrCoords[19]);
		GunJob[DeliverPickupID] = strval(arrCoords[20]);
        GunJob[DeliverPickupID] = CreateDynamicPickup(1239,1,GunJob[DeliverX],GunJob[DeliverY],GunJob[DeliverZ]);
		fclose(file);
		#if defined DEBUG
			print("[INFO:] Gun job loaded");
		#endif
	}
	else
		ErrorLog("[ERROR:] Can't load gunjob.cfg");
	return 1;
}

SaveGunJob()
{
	new File: file2;
	new coordsstring[512];
	format(coordsstring, sizeof(coordsstring), "%f|%f|%f|%d|%d|%f|%d|%f|%f|%f|%d|%d|%f|%d|%f|%f|%f|%d|%d|%f|%d\n",
	GunJob[TakeJobX],
	GunJob[TakeJobY],
	GunJob[TakeJobZ],
	GunJob[TakeJobWorld],
	GunJob[TakeJobInterior],
	GunJob[TakeJobAngle],
	GunJob[TakeJobPickupID],
	GunJob[BuyPackagesX],
	GunJob[BuyPackagesY],
	GunJob[BuyPackagesZ],
	GunJob[BuyPackagesWorld],
	GunJob[BuyPackagesInterior],
	GunJob[BuyPackagesAngle],
	GunJob[BuyPackagesPickupID],
	GunJob[DeliverX],
	GunJob[DeliverY],
	GunJob[DeliverZ],
	GunJob[DeliverWorld],
	GunJob[DeliverInterior],
	GunJob[DeliverAngle],
	GunJob[DeliverPickupID]);

	file2 = fopen("jobs/gunjob.cfg", io_write);
	if(file2)
	{
		fwrite(file2, coordsstring);
		fclose(file2);
	}
	else
		ErrorLog("[ERROR:] Can't save gunjob.cfg");
	return 1;
}

LoadDrugJob()
{
	new arrCoords[21][64];
	new strFromFile2[256];
	new File: file = fopen("jobs/drugjob.cfg", io_read);
	if (file)
	{
		fread(file, strFromFile2);
		split2(strFromFile2, arrCoords, '|');
		DrugJob[TakeJobX] = floatstr(arrCoords[0]);
		DrugJob[TakeJobY] = floatstr(arrCoords[1]);
		DrugJob[TakeJobZ] = floatstr(arrCoords[2]);
		DrugJob[TakeJobWorld] = strval(arrCoords[3]);
		DrugJob[TakeJobInterior] = strval(arrCoords[4]);
		DrugJob[TakeJobAngle] = floatstr(arrCoords[5]);
		DrugJob[TakeJobPickupID] = strval(arrCoords[6]);
        DrugJob[TakeJobPickupID] = CreateDynamicPickup(1239,1,DrugJob[TakeJobX],DrugJob[TakeJobY],DrugJob[TakeJobZ]);
		DrugJob[BuyDrugsX] = floatstr(arrCoords[7]);
		DrugJob[BuyDrugsY] = floatstr(arrCoords[8]);
		DrugJob[BuyDrugsZ] = floatstr(arrCoords[9]);
		DrugJob[BuyDrugsWorld] = strval(arrCoords[10]);
		DrugJob[BuyDrugsInterior] = strval(arrCoords[11]);
		DrugJob[BuyDrugsAngle] = floatstr(arrCoords[12]);
		DrugJob[BuyDrugsPickupID] = strval(arrCoords[13]);
        DrugJob[BuyDrugsPickupID] = CreateDynamicPickup(1239,1,DrugJob[BuyDrugsX],DrugJob[BuyDrugsY],DrugJob[BuyDrugsZ]);
        DrugJob[DeliverX] = floatstr(arrCoords[14]);
		DrugJob[DeliverY] = floatstr(arrCoords[15]);
		DrugJob[DeliverZ] = floatstr(arrCoords[16]);
		DrugJob[DeliverWorld] = strval(arrCoords[17]);
		DrugJob[DeliverInterior] = strval(arrCoords[18]);
		DrugJob[DeliverAngle] = floatstr(arrCoords[19]);
		DrugJob[DeliverPickupID] = strval(arrCoords[20]);
        DrugJob[DeliverPickupID] = CreateDynamicPickup(1239,1,DrugJob[DeliverX],DrugJob[DeliverY],DrugJob[DeliverZ]);
		fclose(file);
		#if defined DEBUG
			print("[INFO:] Drug job loaded");
		#endif
	}
	else
		ErrorLog("[ERROR:] Can't load drugjob.cfg");
	return 1;
}

SaveDrugJob()
{
	new File: file2;
	new coordsstring[512];
	format(coordsstring, sizeof(coordsstring), "%f|%f|%f|%d|%d|%f|%d|%f|%f|%f|%d|%d|%f|%d|%f|%f|%f|%d|%d|%f|%d\n",
	DrugJob[TakeJobX],
	DrugJob[TakeJobY],
	DrugJob[TakeJobZ],
	DrugJob[TakeJobWorld],
	DrugJob[TakeJobInterior],
	DrugJob[TakeJobAngle],
	DrugJob[TakeJobPickupID],
	DrugJob[BuyDrugsX],
	DrugJob[BuyDrugsY],
	DrugJob[BuyDrugsZ],
	DrugJob[BuyDrugsWorld],
	DrugJob[BuyDrugsInterior],
	DrugJob[BuyDrugsAngle],
	DrugJob[BuyDrugsPickupID],
	DrugJob[DeliverX],
	DrugJob[DeliverY],
	DrugJob[DeliverZ],
	DrugJob[DeliverWorld],
	DrugJob[DeliverInterior],
	DrugJob[DeliverAngle],
	DrugJob[DeliverPickupID]);

	file2 = fopen("jobs/drugjob.cfg", io_write);
	if(file2)
	{
		fwrite(file2, coordsstring);
		fclose(file2);	
	}
	else
		ErrorLog("[ERROR:] Can't save drugjob.cfg");
	return 1;
}

LoadMzgkJob()
{
	new arrCoords[7][64];
	new strFromFile2[256];
	new File: file = fopen("jobs/mzgkJob.cfg", io_read);
	if (file)
	{
		fread(file, strFromFile2);
		split2(strFromFile2, arrCoords, '|');
		MzgkJob[TakeJobX] = floatstr(arrCoords[0]);
		MzgkJob[TakeJobY] = floatstr(arrCoords[1]);
		MzgkJob[TakeJobZ] = floatstr(arrCoords[2]);
		MzgkJob[TakeJobWorld] = strval(arrCoords[3]);
		MzgkJob[TakeJobInterior] = strval(arrCoords[4]);
		MzgkJob[TakeJobAngle] = floatstr(arrCoords[5]);
		MzgkJob[TakeJobPickupID] = strval(arrCoords[6]);
		fclose(file);
        MzgkJob[TakeJobPickupID] = CreateDynamicPickup(1239,1,MzgkJob[TakeJobX],MzgkJob[TakeJobY],MzgkJob[TakeJobZ]);
		#if defined DEBUG
			print("[INFO:] Mzgk job loaded");
		#endif
	}
	else
		ErrorLog("[ERROR:] Can't load mzgkjob.cfg");
	return 1;
}

SaveMzgkJob()
{
	new File: file2;
	new coordsstring[512];
	format(coordsstring, sizeof(coordsstring), "%f|%f|%f|%d|%d|%f|%d\n",
	MzgkJob[TakeJobX],
	MzgkJob[TakeJobY],
	MzgkJob[TakeJobZ],
	MzgkJob[TakeJobWorld],
	MzgkJob[TakeJobInterior],
	MzgkJob[TakeJobAngle],
	MzgkJob[TakeJobPickupID]);
	
	file2 = fopen("jobs/mzgkJob.cfg", io_write);
	if(file2)
	{
		fwrite(file2, coordsstring);
		fclose(file2);
	}
	else
		ErrorLog("[ERROR:] Can't save mzgkjob.cfg");
	return 1;
}

LoadSweeperJob()
{
	new arrCoords[7][64];
	new strFromFile2[256];
	new File: file = fopen("jobs/SweeperJob.cfg", io_read);
	if (file)
	{
		fread(file, strFromFile2);
		split2(strFromFile2, arrCoords, '|');
		SweeperJob[TakeJobX] = floatstr(arrCoords[0]);
		SweeperJob[TakeJobY] = floatstr(arrCoords[1]);
		SweeperJob[TakeJobZ] = floatstr(arrCoords[2]);
		SweeperJob[TakeJobWorld] = strval(arrCoords[3]);
		SweeperJob[TakeJobInterior] = strval(arrCoords[4]);
		SweeperJob[TakeJobAngle] = floatstr(arrCoords[5]);
		SweeperJob[TakeJobPickupID] = strval(arrCoords[6]);
        SweeperJob[TakeJobPickupID] = CreateDynamicPickup(1239,1,SweeperJob[TakeJobX],SweeperJob[TakeJobY],SweeperJob[TakeJobZ]);
		fclose(file);
		#if defined DEBUG
			print("[INFO:] Sweeper job loaded");
		#endif
	}
	else
		ErrorLog("[ERROR:] Can't load sweeperjob.cfg");
	return 1;
}

SaveSweeperJob()
{
	new File: file2;
	new coordsstring[512];
	format(coordsstring, sizeof(coordsstring), "%f|%f|%f|%d|%d|%f|%d\n",
	SweeperJob[TakeJobX],
	SweeperJob[TakeJobY],
	SweeperJob[TakeJobZ],
	SweeperJob[TakeJobWorld],
	SweeperJob[TakeJobInterior],
	SweeperJob[TakeJobAngle],
	SweeperJob[TakeJobPickupID]);
	
	file2 = fopen("jobs/SweeperJob.cfg", io_write);
	if(file2)
	{
		fwrite(file2, coordsstring);
		fclose(file2);
	}
	else
		ErrorLog("[ERROR:] Can't save sweeperjob.cfg");
	return 1;
}

LoadBusJob()
{
	new arrCoords[7][64];
	new strFromFile2[256];
	new File: file = fopen("jobs/busjob.cfg", io_read);
	if (file)
	{
		fread(file, strFromFile2);
		split2(strFromFile2, arrCoords, '|');
		BusJob[TakeJobX] = floatstr(arrCoords[0]);
		BusJob[TakeJobY] = floatstr(arrCoords[1]);
		BusJob[TakeJobZ] = floatstr(arrCoords[2]);
		BusJob[TakeJobWorld] = strval(arrCoords[3]);
		BusJob[TakeJobInterior] = strval(arrCoords[4]);
		BusJob[TakeJobAngle] = floatstr(arrCoords[5]);
		BusJob[TakeJobPickupID] = strval(arrCoords[6]);
        BusJob[TakeJobPickupID] = CreateDynamicPickup(1239,1,BusJob[TakeJobX],BusJob[TakeJobY],BusJob[TakeJobZ]);
		fclose(file);
		#if defined DEBUG
			print("[INFO:] Bus job loaded");
		#endif
	}
	else
		ErrorLog("[ERROR:] Can't load busjob.cfg");
	return 1;
}

SaveBusJob()
{
	new File: file2;
	new coordsstring[512];
	format(coordsstring, sizeof(coordsstring), "%f|%f|%f|%d|%d|%f|%d\n",
	BusJob[TakeJobX],
	BusJob[TakeJobY],
	BusJob[TakeJobZ],
	BusJob[TakeJobWorld],
	BusJob[TakeJobInterior],
	BusJob[TakeJobAngle],
	BusJob[TakeJobPickupID]);
	
	file2 = fopen("jobs/busjob.cfg", io_write);
	if(file2)
	{
		fwrite(file2, coordsstring);
		fclose(file2);
	}
	else
		ErrorLog("[ERROR:] Can't save busjob.cfg");
	return 1;
}

LoadSellerJob()
{
	new arrCoords[7][64];
	new strFromFile2[256];
	new File: file = fopen("jobs/sellerjob.cfg", io_read);
	if(file)
	{
		fread(file, strFromFile2);
		split2(strFromFile2, arrCoords, '|');
		SellerJob[TakeJobX] = floatstr(arrCoords[0]);
		SellerJob[TakeJobY] = floatstr(arrCoords[1]);
		SellerJob[TakeJobZ] = floatstr(arrCoords[2]);
		SellerJob[TakeJobWorld] = strval(arrCoords[3]);
		SellerJob[TakeJobInterior] = strval(arrCoords[4]);
		SellerJob[TakeJobAngle] = floatstr(arrCoords[5]);
		SellerJob[TakeJobPickupID] = strval(arrCoords[6]);
        SellerJob[TakeJobPickupID] = CreateDynamicPickup(1239,1,SellerJob[TakeJobX],SellerJob[TakeJobY],SellerJob[TakeJobZ]);
		fclose(file);
		#if defined DEBUG
			print("[INFO:] Seller job loaded");
		#endif
	}
	else
		ErrorLog("[ERROR:] Can't load sellerjob.cfg");
	return 1;
}

SaveSellerJob()
{
	new File: file2;
	new coordsstring[512];
	format(coordsstring, sizeof(coordsstring), "%f|%f|%f|%d|%d|%f|%d\n",
	SellerJob[TakeJobX],
	SellerJob[TakeJobY],
	SellerJob[TakeJobZ],
	SellerJob[TakeJobWorld],
	SellerJob[TakeJobInterior],
	SellerJob[TakeJobAngle],
	SellerJob[TakeJobPickupID]);
	
	file2 = fopen("jobs/sellerjob.cfg", io_write);
	if(file2)
	{
		fwrite(file2, coordsstring);
		fclose(file2);	
	}
	else
		ErrorLog("[ERROR:] Can't save sellerjob.cfg");
	return 1;
}

LoadAccountantJob()
{
	new arrCoords[7][64];
	new strFromFile2[256];
	new File: file = fopen("jobs/accountantjob.cfg", io_read);
	if(file)
	{
		fread(file, strFromFile2);
		split2(strFromFile2, arrCoords, '|');
		AccountantJob[TakeJobX] = floatstr(arrCoords[0]);
		AccountantJob[TakeJobY] = floatstr(arrCoords[1]);
		AccountantJob[TakeJobZ] = floatstr(arrCoords[2]);
		AccountantJob[TakeJobWorld] = strval(arrCoords[3]);
		AccountantJob[TakeJobInterior] = strval(arrCoords[4]);
		AccountantJob[TakeJobAngle] = floatstr(arrCoords[5]);
		AccountantJob[TakeJobPickupID] = strval(arrCoords[6]);
        AccountantJob[TakeJobPickupID] = CreateDynamicPickup(1239,1,AccountantJob[TakeJobX],AccountantJob[TakeJobY],AccountantJob[TakeJobZ]);
		fclose(file);
		#if defined DEBUG
			print("[INFO:] Accountant job loaded");
		#endif
	}
	else
		ErrorLog("[ERROR:] Can't load accountantjob.cfg");
	return 1;
}

SaveAccountantJob()
{
	new File: file2;
	new coordsstring[512];
	format(coordsstring, sizeof(coordsstring), "%f|%f|%f|%d|%d|%f|%d\n",
	AccountantJob[TakeJobX],
	AccountantJob[TakeJobY],
	AccountantJob[TakeJobZ],
	AccountantJob[TakeJobWorld],
	AccountantJob[TakeJobInterior],
	AccountantJob[TakeJobAngle],
	AccountantJob[TakeJobPickupID]);
	
	file2 = fopen("jobs/accountantjob.cfg", io_write);
	if(file2)
	{
		fwrite(file2, coordsstring);
		fclose(file2);	
	}
	else
		ErrorLog("[ERROR:] Can't save accountantjob.cfg");
	return 1;
}

LoadTaxiJob()
{
	new arrCoords[7][64];
	new strFromFile2[256];
	new File: file = fopen("jobs/taxijob.cfg", io_read);
	if(file)
	{
		fread(file, strFromFile2);
		split2(strFromFile2, arrCoords, '|');
		TaxiJob[TakeJobX] = floatstr(arrCoords[0]);
		TaxiJob[TakeJobY] = floatstr(arrCoords[1]);
		TaxiJob[TakeJobZ] = floatstr(arrCoords[2]);
		TaxiJob[TakeJobWorld] = strval(arrCoords[3]);
		TaxiJob[TakeJobInterior] = strval(arrCoords[4]);
		TaxiJob[TakeJobAngle] = floatstr(arrCoords[5]);
		TaxiJob[TakeJobPickupID] = strval(arrCoords[6]);
        TaxiJob[TakeJobPickupID] = CreateDynamicPickup(1239,1,TaxiJob[TakeJobX],TaxiJob[TakeJobY],TaxiJob[TakeJobZ]);
		fclose(file);
		#if defined DEBUG
			print("[INFO:] Taxi job loaded");
		#endif
	}
	else
		ErrorLog("[ERROR:] Can't load taxijob.cfg");
	return 1;
}

LoadWFWorkerJob()
{
	new arrCoords[7][64];
	new strFromFile2[256];
	new File: file = fopen("jobs/wfworkerjob.cfg", io_read);
	if(file)
	{
		fread(file, strFromFile2);
		split2(strFromFile2, arrCoords, '|');
		WFWorkerJob[TakeJobX] = floatstr(arrCoords[0]);
		WFWorkerJob[TakeJobY] = floatstr(arrCoords[1]);
		WFWorkerJob[TakeJobZ] = floatstr(arrCoords[2]);
		WFWorkerJob[TakeJobWorld] = strval(arrCoords[3]);
		WFWorkerJob[TakeJobInterior] = strval(arrCoords[4]);
		WFWorkerJob[TakeJobAngle] = floatstr(arrCoords[5]);
		WFWorkerJob[TakeJobPickupID] = CreateDynamicPickup(1239,1,WFWorkerJob[TakeJobX],WFWorkerJob[TakeJobY],WFWorkerJob[TakeJobZ]);
		WFWorkerJob[TakeJobPickupID2] = CreateDynamicPickup(1239,1,203.94,-63.99,15.7);
		WFWorkerJob[TakeJobPickupID3] = CreateDynamicPickup(1239,1,-2072.56,8.33,35.32);
		WFWorkerJob[TakeJobPickupID4] = CreateDynamicPickup(1239,1,2463.55, -2119.38,13.55);
		WFWorkerJob[TakeJobPickupID5] = CreateDynamicPickup(1239,1,2817.54, 972.72, 10.75);
		WFWorkerJob[TakeJobPickupID6] = CreateDynamicPickup(1239,1,-2116.61, -2290.94, 30.63);
		WFWorkerJob[TakeJobPickupID7] = CreateDynamicPickup(1239,1,-1534.55, 2609.32, 55.83);
		fclose(file);
		#if defined DEBUG
			print("[INFO:] WFWorker job loaded");
		#endif
	}
	else
		ErrorLog("[ERROR:] Can't load wfworkerjob.cfg");
	return 1;
}

SaveWFactoryJob()
{
	new File: file2;
	new coordsstring[512];
	format(coordsstring, sizeof(coordsstring), "%f|%f|%f|%d|%d|%f\n",
	WFWorkerJob[TakeJobX],
	WFWorkerJob[TakeJobY],
	WFWorkerJob[TakeJobZ],
	WFWorkerJob[TakeJobWorld],
	WFWorkerJob[TakeJobInterior],
	WFWorkerJob[TakeJobAngle]);
	
	file2 = fopen("jobs/wfworkerjob.cfg", io_write);
	if(file2)
	{
		fwrite(file2, coordsstring);
		fclose(file2);
	}
	else
		ErrorLog("[ERROR:] Can't save wfworkerjob.cfg");
	return 1;
}

LoadNewsBoyJob()
{
	new arrCoords[9][64];
	new strFromFile2[256];
	new File: file = fopen("jobs/newsboyjob.cfg", io_read);
	if(file)
	{
		fread(file, strFromFile2);
		split2(strFromFile2, arrCoords, '|');
		NewsBoyJob[TakeJobX] = floatstr(arrCoords[0]);
		NewsBoyJob[TakeJobY] = floatstr(arrCoords[1]);
		NewsBoyJob[TakeJobZ] = floatstr(arrCoords[2]);
		NewsBoyJob[TakeJobWorld] = strval(arrCoords[3]);
		NewsBoyJob[TakeJobInterior] = strval(arrCoords[4]);
		NewsBoyJob[TakeJobAngle] = floatstr(arrCoords[5]);
        NewsBoyJob[TakeJobPickupID] = CreateDynamicPickup(1239,1,NewsBoyJob[TakeJobX],NewsBoyJob[TakeJobY],NewsBoyJob[TakeJobZ]);
		NewsBoyJob[TakeJobPapersCount] = strval(arrCoords[7]);
		NewsBoyJob[TakeJobReward] = strval(arrCoords[8]);
		fclose(file);
		#if defined DEBUG
			print("[INFO:] NewsBoy job loaded");
		#endif
	}
	else
		ErrorLog("[ERROR:] Can't load newsboyjob.cfg");
	return 1;
}

SaveNewsBoyJob()
{
	new File: file2;
	new coordsstring[512];
	format(coordsstring, sizeof(coordsstring), "%f|%f|%f|%d|%d|%f|%d|%d|%d\n",
	NewsBoyJob[TakeJobX],
	NewsBoyJob[TakeJobY],
	NewsBoyJob[TakeJobZ],
	NewsBoyJob[TakeJobWorld],
	NewsBoyJob[TakeJobInterior],
	NewsBoyJob[TakeJobAngle],
	NewsBoyJob[TakeJobPickupID],
	NewsBoyJob[TakeJobPapersCount],
	NewsBoyJob[TakeJobReward]);
	
	file2 = fopen("jobs/newsboyjob.cfg", io_write);
	if(file2)
	{
		fwrite(file2, coordsstring);
		fclose(file2);
	}
	else
		ErrorLog("[ERROR:] Can't save newsboyjob.cfg");
	return 1;
}

SaveTaxiJob()
{
	new File: file2;
	new coordsstring[512];
	format(coordsstring, sizeof(coordsstring), "%f|%f|%f|%d|%d|%f|%d\n",
	TaxiJob[TakeJobX],
	TaxiJob[TakeJobY],
	TaxiJob[TakeJobZ],
	TaxiJob[TakeJobWorld],
	TaxiJob[TakeJobInterior],
	TaxiJob[TakeJobAngle],
	TaxiJob[TakeJobPickupID]);
	
	file2 = fopen("jobs/taxijob.cfg", io_write);
	if(file2)
	{
		fwrite(file2, coordsstring);
		fclose(file2);
	}
	else
		ErrorLog("[ERROR:] Can't save taxijob.cfg");
	return 1;
}