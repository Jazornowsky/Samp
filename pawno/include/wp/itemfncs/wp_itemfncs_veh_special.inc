/***
*
* File: wp_itemfncs_biz.inc
* Auth: Damian Wojdat
* Date: 11.03.2012
* Desc: Functions related to vehicle items (addon).
*
*************************************************************************************************************/

Float:VehBatDegradation(itemid)
{
	switch(itemid)
	{
		case 0: return 0.0016;
		case 1: return 0.01;
		case 2: return 0.003;
		case 3: return 0.003;
		case 4: return 0.0013;
		case 5: return 0.005;
		case 6: return 0.003;
		default: return 0.0016;
	}
	return 0.0;
}

MountVehicleStockItem(itemid, tveh)
{
	new
        binaryDoors[33], // 33 because 32 bits + EOS
        binaryPanels[sizeof binaryDoors],
		decimal
    ;
    GetVehicleDamageStatus((tveh + 1),
        gVehData[tveh][CarPanels],
        gVehData[tveh][CarDoors],
        gVehData[tveh][CarLights],
        gVehData[tveh][CarTires]
    );
    format(binaryDoors, sizeof binaryDoors, "%032b", gVehData[tveh][CarDoors]);
    format(binaryPanels, sizeof binaryPanels, "%032b", gVehData[tveh][CarPanels]);
	switch(itemid)
	{
		case 1:
		{
			for(new i = sizeof(binaryDoors)-2; i >= sizeof(binaryDoors)-4; i--)
			{
				binaryDoors[i] = 48;
			}
			unformat(binaryDoors, "b", decimal);
			gVehData[tveh][CarDoors] = decimal;
			UpdateVehicleDamageStatus(tveh+1, 0, 0, 0, 0);
			UpdateVehicleDamageStatus(tveh+1, gVehData[tveh][CarPanels], gVehData[tveh][CarDoors], gVehData[tveh][CarLights], gVehData[tveh][CarTires]);
			return 1;
		}
		case 2:
		{
			for(new i = sizeof(binaryDoors)-10; i >= sizeof(binaryDoors)-12; i--)
			{
				binaryDoors[i] = 48;
			}
			unformat(binaryDoors, "b", decimal);
			gVehData[tveh][CarDoors] = decimal;
			UpdateVehicleDamageStatus(tveh+1, 0, 0, 0, 0);
			UpdateVehicleDamageStatus(tveh+1, gVehData[tveh][CarPanels], gVehData[tveh][CarDoors], gVehData[tveh][CarLights], gVehData[tveh][CarTires]);
			return 1;
		}
		case 3:
		{
			for(new i = (sizeof(binaryDoors)-18); i >= (sizeof(binaryDoors)-21); i--)
			{
				binaryDoors[i] = 48;
			}
			unformat(binaryDoors, "b", decimal);
			gVehData[tveh][CarDoors] = decimal;
			UpdateVehicleDamageStatus(tveh+1, 0, 0, 0, 0);
			UpdateVehicleDamageStatus(tveh+1, gVehData[tveh][CarPanels], gVehData[tveh][CarDoors], gVehData[tveh][CarLights], gVehData[tveh][CarTires]);
			return 1;
		}
		case 4:
		{
			for(new i = sizeof(binaryDoors)-26; i >= sizeof(binaryDoors)-29; i--)
			{
				binaryDoors[i] = 48;
			}
			unformat(binaryDoors, "b", decimal);
			gVehData[tveh][CarDoors] = decimal;
			UpdateVehicleDamageStatus(tveh+1, 0, 0, 0, 0);
			UpdateVehicleDamageStatus(tveh+1, gVehData[tveh][CarPanels], gVehData[tveh][CarDoors], gVehData[tveh][CarLights], gVehData[tveh][CarTires]);
			return 1;
		}
		case 5:
		{
			for(new i = sizeof(binaryPanels)-22; i >= sizeof(binaryPanels)-24; i--)
			{
				binaryPanels[i] = 48;
			}
			unformat(binaryPanels, "b", decimal);
			gVehData[tveh][CarPanels] = decimal;
			UpdateVehicleDamageStatus(tveh+1, 0, 0, 0, 0);
			UpdateVehicleDamageStatus(tveh+1, gVehData[tveh][CarPanels], gVehData[tveh][CarDoors], gVehData[tveh][CarLights], gVehData[tveh][CarTires]);
			return 1;
		}
		case 6:
		{
			for(new i = sizeof(binaryPanels)-26; i >= sizeof(binaryPanels)-28; i--)
			{
				binaryPanels[i] = 48;
			}
			unformat(binaryPanels, "b", decimal);
			gVehData[tveh][CarPanels] = decimal;
			UpdateVehicleDamageStatus(tveh+1, 0, 0, 0, 0);
			UpdateVehicleDamageStatus(tveh+1, gVehData[tveh][CarPanels], gVehData[tveh][CarDoors], gVehData[tveh][CarLights], gVehData[tveh][CarTires]);
			return 1;
		}
	}
	return 0;
}

stock MountVehicleItem(itemid, tveh)
{
	switch(itemid)
	{
		case 1:
		{
			if(gVehData[tveh][mVehModel] == 560)
			{
				AddVehicleComponent(tveh+1, 1028);
				gVehData[tveh][mVehExhaust] = 1028;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 562)
			{
				AddVehicleComponent(tveh+1, 1034);
				gVehData[tveh][mVehExhaust] = 1034;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 565)
			{
				AddVehicleComponent(tveh+1, 1046);
				gVehData[tveh][mVehExhaust] = 1046;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 561)
			{
				AddVehicleComponent(tveh+1, 1064);
				gVehData[tveh][mVehExhaust] = 1064;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 559)
			{
				AddVehicleComponent(tveh+1, 1065);
				gVehData[tveh][mVehExhaust] = 1065;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 558)
			{
				AddVehicleComponent(tveh+1, 1092);
				gVehData[tveh][mVehExhaust] = 1092;
				return 1;
			}			
		}
		case 2:
		{
			if(gVehData[tveh][mVehModel] == 560)
			{
				AddVehicleComponent(tveh+1, 1029);
				gVehData[tveh][mVehExhaust] = 1029;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 562)
			{
				AddVehicleComponent(tveh+1, 1037);
				gVehData[tveh][mVehExhaust] = 1037;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 565)
			{
				AddVehicleComponent(tveh+1, 1045);
				gVehData[tveh][mVehExhaust] = 1045;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 561)
			{
				AddVehicleComponent(tveh+1, 1059);
				gVehData[tveh][mVehExhaust] = 1059;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 559)
			{
				AddVehicleComponent(tveh+1, 1066);
				gVehData[tveh][mVehExhaust] = 1066;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 558)
			{
				AddVehicleComponent(tveh+1, 1089);
				gVehData[tveh][mVehExhaust] = 1089;
				return 1;
			}			
		}
		case 3:
		{
			if(gVehData[tveh][mVehModel] == 575)
			{
				AddVehicleComponent(tveh+1, 1044);
				gVehData[tveh][mVehExhaust] = 1044;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 536)
			{
				AddVehicleComponent(tveh+1, 1104);
				gVehData[tveh][mVehExhaust] = 1104;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 535)
			{
				AddVehicleComponent(tveh+1, 1113);
				gVehData[tveh][mVehExhaust] = 1113;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 534)
			{
				AddVehicleComponent(tveh+1, 1126);
				gVehData[tveh][mVehExhaust] = 1126;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 567)
			{
				AddVehicleComponent(tveh+1, 1129);
				gVehData[tveh][mVehExhaust] = 1129;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 576)
			{
				AddVehicleComponent(tveh+1, 1136);
				gVehData[tveh][mVehExhaust] = 1136;
				return 1;
			}
		}
		case 4:
		{
			if(gVehData[tveh][mVehModel] == 575)
			{
				AddVehicleComponent(tveh+1, 1043);
				gVehData[tveh][mVehExhaust] = 1043;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 536)
			{
				AddVehicleComponent(tveh+1, 1105);
				gVehData[tveh][mVehExhaust] = 1105;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 535)
			{
				AddVehicleComponent(tveh+1, 1114);
				gVehData[tveh][mVehExhaust] = 1114;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 534)
			{
				AddVehicleComponent(tveh+1, 1127);
				gVehData[tveh][mVehExhaust] = 1127;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 567)
			{
				AddVehicleComponent(tveh+1, 1132);
				gVehData[tveh][mVehExhaust] = 1132;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 576)
			{
				AddVehicleComponent(tveh+1, 1135);
				gVehData[tveh][mVehExhaust] = 1135;
				return 1;
			}
		}
		case 5:
		{
			if(gVehData[tveh][mVehModel] == 560)
			{
				AddVehicleComponent(tveh+1, 1169);
				gVehData[tveh][mVehFrontBumper] = 1169;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 565)
			{
				AddVehicleComponent(tveh+1, 1153);
				gVehData[tveh][mVehFrontBumper] = 1153;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 561)
			{
				AddVehicleComponent(tveh+1, 1155);
				gVehData[tveh][mVehFrontBumper] = 1155;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 558)
			{
				AddVehicleComponent(tveh+1, 1166);
				gVehData[tveh][mVehFrontBumper] = 1166;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 562)
			{
				AddVehicleComponent(tveh+1, 1171);
				gVehData[tveh][mVehFrontBumper] = 1171;
				return 1;
			}
		}
		case 6:
		{
			if(gVehData[tveh][mVehModel] == 560)
			{
				AddVehicleComponent(tveh+1, 1170);
				gVehData[tveh][mVehFrontBumper] = 1170;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 565)
			{
				AddVehicleComponent(tveh+1, 1152);
				gVehData[tveh][mVehFrontBumper] = 1152;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 561)
			{
				AddVehicleComponent(tveh+1, 1157);
				gVehData[tveh][mVehFrontBumper] = 1157;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 558)
			{
				AddVehicleComponent(tveh+1, 1165);
				gVehData[tveh][mVehFrontBumper] = 1165;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 562)
			{
				AddVehicleComponent(tveh+1, 1172);
				gVehData[tveh][mVehFrontBumper] = 1172;
				return 1;
			}
		}
		case 7:
		{
			if(gVehData[tveh][mVehModel] == 535)
			{
				AddVehicleComponent(tveh+1, 1116);
				gVehData[tveh][mVehFrontBumper] = 1116;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 534)
			{
				AddVehicleComponent(tveh+1, 1179);
				gVehData[tveh][mVehFrontBumper] = 1179;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 536)
			{
				AddVehicleComponent(tveh+1, 1182);
				gVehData[tveh][mVehFrontBumper] = 1182;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 567)
			{
				AddVehicleComponent(tveh+1, 1189);
				gVehData[tveh][mVehFrontBumper] = 1189;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 576)
			{
				AddVehicleComponent(tveh+1, 1191);
				gVehData[tveh][mVehFrontBumper] = 1191;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 575)
			{
				AddVehicleComponent(tveh+1, 1174);
				gVehData[tveh][mVehFrontBumper] = 1174;
				return 1;
			}
		}
		case 8:
		{
			if(gVehData[tveh][mVehModel] == 534)
			{
				AddVehicleComponent(tveh+1, 1185);
				gVehData[tveh][mVehFrontBumper] = 1185;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 536)
			{
				AddVehicleComponent(tveh+1, 1181);
				gVehData[tveh][mVehFrontBumper] = 1181;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 567)
			{
				AddVehicleComponent(tveh+1, 1188);
				gVehData[tveh][mVehFrontBumper] = 1188;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 576)
			{
				AddVehicleComponent(tveh+1, 1190);
				gVehData[tveh][mVehFrontBumper] = 1190;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 575)
			{
				AddVehicleComponent(tveh+1, 1175);
				gVehData[tveh][mVehFrontBumper] = 1175;
				return 1;
			}
		}
		case 9:
		{
			if(gVehData[tveh][mVehModel] == 560)
			{
				AddVehicleComponent(tveh+1, 1141);
				gVehData[tveh][mVehRearBumper] = 1141;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 565)
			{
				AddVehicleComponent(tveh+1, 1150);
				gVehData[tveh][mVehRearBumper] = 1150;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 561)
			{
				AddVehicleComponent(tveh+1, 1154);
				gVehData[tveh][mVehRearBumper] = 1154;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 558)
			{
				AddVehicleComponent(tveh+1, 1168);
				gVehData[tveh][mVehRearBumper] = 1168;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 562)
			{
				AddVehicleComponent(tveh+1, 1149);
				gVehData[tveh][mVehRearBumper] = 1149;
				return 1;
			}
		}
		case 10:
		{
			if(gVehData[tveh][mVehModel] == 560)
			{
				AddVehicleComponent(tveh+1, 1140);
				gVehData[tveh][mVehRearBumper] = 1140;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 565)
			{
				AddVehicleComponent(tveh+1, 1151);
				gVehData[tveh][mVehRearBumper] = 1151;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 561)
			{
				AddVehicleComponent(tveh+1, 1156);
				gVehData[tveh][mVehRearBumper] = 1156;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 558)
			{
				AddVehicleComponent(tveh+1, 1167);
				gVehData[tveh][mVehRearBumper] = 1167;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 562)
			{
				AddVehicleComponent(tveh+1, 1148);
				gVehData[tveh][mVehRearBumper] = 1148;
				return 1;
			}
		}
		case 11:
		{
			if(gVehData[tveh][mVehModel] == 534)
			{
				AddVehicleComponent(tveh+1, 1180);
				gVehData[tveh][mVehRearBumper] = 1180;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 536)
			{
				AddVehicleComponent(tveh+1, 1184);
				gVehData[tveh][mVehRearBumper] = 1184;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 567)
			{
				AddVehicleComponent(tveh+1, 1187);
				gVehData[tveh][mVehRearBumper] = 1187;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 576)
			{
				AddVehicleComponent(tveh+1, 1192);
				gVehData[tveh][mVehRearBumper] = 1192;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 575)
			{
				AddVehicleComponent(tveh+1, 1176);
				gVehData[tveh][mVehRearBumper] = 1176;
				return 1;
			}
		}
		case 12:
		{
			if(gVehData[tveh][mVehModel] == 534)
			{
				AddVehicleComponent(tveh+1, 1178);
				gVehData[tveh][mVehRearBumper] = 1178;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 536)
			{
				AddVehicleComponent(tveh+1, 1183);
				gVehData[tveh][mVehRearBumper] = 1183;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 567)
			{
				AddVehicleComponent(tveh+1, 1186);
				gVehData[tveh][mVehRearBumper] = 1186;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 576)
			{
				AddVehicleComponent(tveh+1, 1193);
				gVehData[tveh][mVehRearBumper] = 1193;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 575)
			{
				AddVehicleComponent(tveh+1, 1177);
				gVehData[tveh][mVehRearBumper] = 1177;
				return 1;
			}
		}
		case 13:
		{
			if(gVehData[tveh][mVehModel] == 560)
			{
				AddVehicleComponent(tveh+1, 1033);
				gVehData[tveh][mVehRoof] = 1033;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 562)
			{
				AddVehicleComponent(tveh+1, 1035);
				gVehData[tveh][mVehRoof] = 1035;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 565)
			{
				AddVehicleComponent(tveh+1, 1053);
				gVehData[tveh][mVehRoof] = 1053;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 561)
			{
				AddVehicleComponent(tveh+1, 1061);
				gVehData[tveh][mVehRoof] = 1061;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 559)
			{
				AddVehicleComponent(tveh+1, 1068);
				gVehData[tveh][mVehRoof] = 1068;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 558)
			{
				AddVehicleComponent(tveh+1, 1091);
				gVehData[tveh][mVehRoof] = 1091;
				return 1;
			}
		}
		case 14:
		{
			if(gVehData[tveh][mVehModel] == 560)
			{
				AddVehicleComponent(tveh+1, 1032);
				gVehData[tveh][mVehRoof] = 1032;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 562)
			{
				AddVehicleComponent(tveh+1, 1038);
				gVehData[tveh][mVehRoof] = 1038;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 565)
			{
				AddVehicleComponent(tveh+1, 1054);
				gVehData[tveh][mVehRoof] = 1054;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 561)
			{
				AddVehicleComponent(tveh+1, 1054);
				gVehData[tveh][mVehRoof] = 1054;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 559)
			{
				AddVehicleComponent(tveh+1, 1067);
				gVehData[tveh][mVehRoof] = 1067;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 558)
			{
				AddVehicleComponent(tveh+1, 1088);
				gVehData[tveh][mVehRoof] = 1088;
				return 1;
			}
		}
		case 15:
		{
			if(gVehData[tveh][mVehModel] == 536)
			{
				AddVehicleComponent(tveh+1, 1128);
				gVehData[tveh][mVehRoof] = 1128;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 567)
			{
				AddVehicleComponent(tveh+1, 1130);
				gVehData[tveh][mVehRoof] = 1130;
				return 1;
			}
		}
		case 16:
		{
			if(gVehData[tveh][mVehModel] == 567)
			{
				AddVehicleComponent(tveh+1, 1131);
				gVehData[tveh][mVehRoof] = 1131;
				return 1;
			}
		}
		case 17:
		{
			if(gVehData[tveh][mVehModel] == 565)
			{
				AddVehicleComponent(tveh+1, 1049);
				gVehData[tveh][mVehSpoiler] = 1049;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 561)
			{
				AddVehicleComponent(tveh+1, 1058);
				gVehData[tveh][mVehSpoiler] = 1058;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 560)
			{
				AddVehicleComponent(tveh+1, 1138);
				gVehData[tveh][mVehSpoiler] = 1138;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 562)
			{
				AddVehicleComponent(tveh+1, 1147);
				gVehData[tveh][mVehSpoiler] = 1147;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 559)
			{
				AddVehicleComponent(tveh+1, 1162);
				gVehData[tveh][mVehSpoiler] = 1162;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 558)
			{
				AddVehicleComponent(tveh+1, 1164);
				gVehData[tveh][mVehSpoiler] = 1164;
				return 1;
			}
		}
		case 18:
		{
			if(gVehData[tveh][mVehModel] == 565)
			{
				AddVehicleComponent(tveh+1, 1050);
				gVehData[tveh][mVehSpoiler] = 1050;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 561)
			{
				AddVehicleComponent(tveh+1, 1060);
				gVehData[tveh][mVehSpoiler] = 1060;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 560)
			{
				AddVehicleComponent(tveh+1, 1139);
				gVehData[tveh][mVehSpoiler] = 1139;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 562)
			{
				AddVehicleComponent(tveh+1, 1146);
				gVehData[tveh][mVehSpoiler] = 1146;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 559)
			{
				AddVehicleComponent(tveh+1, 1158);
				gVehData[tveh][mVehSpoiler] = 1158;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 558)
			{
				AddVehicleComponent(tveh+1, 1163);
				gVehData[tveh][mVehSpoiler] = 1163;
				return 1;
			}
		}
		case 19:
		{
			if(gVehData[tveh][mVehModel] == 560)
			{
				AddVehicleComponent(tveh+1, 1026);
				gVehData[tveh][mVehSideskirt] = 1026;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 562)
			{
				AddVehicleComponent(tveh+1, 1036);
				gVehData[tveh][mVehSideskirt] = 1036;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 565)
			{
				AddVehicleComponent(tveh+1, 1047);
				gVehData[tveh][mVehSideskirt] = 1047;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 561)
			{
				AddVehicleComponent(tveh+1, 1056);
				gVehData[tveh][mVehSideskirt] = 1056;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 559)
			{
				AddVehicleComponent(tveh+1, 1069);
				gVehData[tveh][mVehSideskirt] = 1069;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 558)
			{
				AddVehicleComponent(tveh+1, 1090);
				gVehData[tveh][mVehSideskirt] = 1090;
				return 1;
			}
		}
		case 20:
		{
			if(gVehData[tveh][mVehModel] == 560)
			{
				AddVehicleComponent(tveh+1, 1031);
				gVehData[tveh][mVehSideskirt] = 1031;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 562)
			{
				AddVehicleComponent(tveh+1, 1041);
				gVehData[tveh][mVehSideskirt] = 1041;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 565)
			{
				AddVehicleComponent(tveh+1, 1048);
				gVehData[tveh][mVehSideskirt] = 1048;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 561)
			{
				AddVehicleComponent(tveh+1, 1057);
				AddVehicleComponent(tveh+1, 1063);
				gVehData[tveh][mVehSideskirt] = 1057;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 559)
			{
				AddVehicleComponent(tveh+1, 1070);
				gVehData[tveh][mVehSideskirt] = 1070;
				return 1;
			}
			else if(gVehData[tveh][mVehModel] == 558)
			{
				AddVehicleComponent(tveh+1, 1093);
				gVehData[tveh][mVehSideskirt] = 1093;
				return 1;
			}
		}
		case 21:
		{
			if(gVehData[tveh][mVehModel] == 534)
			{
				AddVehicleComponent(tveh+1, 1122);
				gVehData[tveh][mVehSideskirt] = 1122;
				return 1;
			}
		}
		case 22:
		{
			if(gVehData[tveh][mVehModel] == 534)
			{
				AddVehicleComponent(tveh+1, 1106);
				gVehData[tveh][mVehSideskirt] = 1106;
				return 1;
			}
		}
		case 23:
		{
			if(gVehData[tveh][mVehModel] == 535)
			{
				AddVehicleComponent(tveh+1, 1118);
				gVehData[tveh][mVehSideskirt] = 1118;
				return 1;
			}
		}
		case 24:
		{
			if(gVehData[tveh][mVehModel] == 535)
			{
				AddVehicleComponent(tveh+1, 1119);
				// AddVehicleComponent(tveh+1, 1121);
				gVehData[tveh][mVehSideskirt] = 1119;
				return 1;
			}
		}
		case 25:
		{
			if(gVehData[tveh][mVehModel] == 534)
			{
				AddVehicleComponent(tveh+1, 1100);
				gVehData[tveh][mVehLamps] = 1100;
				return 1;
			}
		}
		case 26:
		{
			if(gVehData[tveh][mVehModel] == 534)
			{
				AddVehicleComponent(tveh+1, 1123);
				gVehData[tveh][mVehLamps] = 1123;
				return 1;
			}
		}
		case 27:
		{
			if(gVehData[tveh][mVehModel] == 534)
			{
				AddVehicleComponent(tveh+1, 1125);
				gVehData[tveh][mVehLamps] = 1125;
				return 1;
			}
		}
		case 28:
		{
			if(!IsAHelicopter(tveh+1) && !IsAPlane(tveh+1) && !IsAMotorBike(tveh+1) && !IsABike(tveh+1))
			{
				AddVehicleComponent(tveh+1, 1025);
				gVehData[tveh][mVehWheels] = 1025;
				return 1;
			}
		}
		case 29:
		{
			if(!IsAHelicopter(tveh+1) && !IsAPlane(tveh+1) && !IsAMotorBike(tveh+1) && !IsABike(tveh+1))
			{
				AddVehicleComponent(tveh+1, 1074);
				gVehData[tveh][mVehWheels] = 1074;
				return 1;
			}
		}
		case 30:
		{
			if(!IsAHelicopter(tveh+1) && !IsAPlane(tveh+1) && !IsAMotorBike(tveh+1) && !IsABike(tveh+1))
			{
				AddVehicleComponent(tveh+1, 1076);
				gVehData[tveh][mVehWheels] = 1076;
				return 1;
			}
		}
		case 31:
		{
			if(!IsAHelicopter(tveh+1) && !IsAPlane(tveh+1) && !IsAMotorBike(tveh+1) && !IsABike(tveh+1))
			{
				AddVehicleComponent(tveh+1, 1078);
				gVehData[tveh][mVehWheels] = 1078;
				return 1;
			}
		}
		case 32:
		{
			if(!IsAHelicopter(tveh+1) && !IsAPlane(tveh+1) && !IsAMotorBike(tveh+1) && !IsABike(tveh+1))
			{
				AddVehicleComponent(tveh+1, 1081);
				gVehData[tveh][mVehWheels] = 1081;
				return 1;
			}
		}
		case 33:
		{
			if(!IsAHelicopter(tveh+1) && !IsAPlane(tveh+1) && !IsAMotorBike(tveh+1) && !IsABike(tveh+1))
			{
				AddVehicleComponent(tveh+1, 1082);
				gVehData[tveh][mVehWheels] = 1082;
				return 1;
			}
		}
		case 34:
		{
			if(!IsAHelicopter(tveh+1) && !IsAPlane(tveh+1) && !IsAMotorBike(tveh+1) && !IsABike(tveh+1))
			{
				AddVehicleComponent(tveh+1, 1085);
				gVehData[tveh][mVehWheels] = 1085;
				return 1;
			}
		}
		case 35:
		{
			if(!IsAHelicopter(tveh+1) && !IsAPlane(tveh+1) && !IsAMotorBike(tveh+1) && !IsABike(tveh+1))
			{
				AddVehicleComponent(tveh+1, 1096);
				gVehData[tveh][mVehWheels] = 1096;
				return 1;
			}
		}
		case 36:
		{
			if(!IsAHelicopter(tveh+1) && !IsAPlane(tveh+1) && !IsAMotorBike(tveh+1) && !IsABike(tveh+1))
			{
				AddVehicleComponent(tveh+1, 1097);
				gVehData[tveh][mVehWheels] = 1097;
				return 1;
			}
		}
		case 37:
		{
			if(!IsAHelicopter(tveh+1) && !IsAPlane(tveh+1) && !IsAMotorBike(tveh+1) && !IsABike(tveh+1))
			{
				AddVehicleComponent(tveh+1, 1098);
				gVehData[tveh][mVehWheels] = 1098;
				return 1;
			}
		}
		case 38:
		{
			if(!IsAHelicopter(tveh+1) && !IsAPlane(tveh+1) && !IsAMotorBike(tveh+1) && !IsABike(tveh+1))
			{
				AddVehicleComponent(tveh+1, 1084);
				gVehData[tveh][mVehWheels] = 1084;
				return 1;
			}
		}
		case 39:
		{
			if(!IsAHelicopter(tveh+1) && !IsAPlane(tveh+1) && !IsAMotorBike(tveh+1) && !IsABike(tveh+1))
			{
				AddVehicleComponent(tveh+1, 1073);
				gVehData[tveh][mVehWheels] = 1073;
				return 1;
			}
		}
		case 40:
		{
			if(!IsAHelicopter(tveh+1) && !IsAPlane(tveh+1) && !IsAMotorBike(tveh+1) && !IsABike(tveh+1))
			{
				AddVehicleComponent(tveh+1, 1075);
				gVehData[tveh][mVehWheels] = 1075;
				return 1;
			}
		}
		case 41:
		{
			if(!IsAHelicopter(tveh+1) && !IsAPlane(tveh+1) && !IsAMotorBike(tveh+1) && !IsABike(tveh+1))
			{
				AddVehicleComponent(tveh+1, 1077);
				gVehData[tveh][mVehWheels] = 1077;
				return 1;
			}
		}
		case 42:
		{
			if(!IsAHelicopter(tveh+1) && !IsAPlane(tveh+1) && !IsAMotorBike(tveh+1) && !IsABike(tveh+1))
			{
				AddVehicleComponent(tveh+1, 1079);
				gVehData[tveh][mVehWheels] = 1079;
				return 1;
			}
		}
		case 43:
		{
			if(!IsAHelicopter(tveh+1) && !IsAPlane(tveh+1) && !IsAMotorBike(tveh+1) && !IsABike(tveh+1))
			{
				AddVehicleComponent(tveh+1, 1080);
				gVehData[tveh][mVehWheels] = 1080;
				return 1;
			}
		}
		case 44:
		{
			if(!IsAHelicopter(tveh+1) && !IsAPlane(tveh+1) && !IsAMotorBike(tveh+1) && !IsABike(tveh+1))
			{
				AddVehicleComponent(tveh+1, 1083);
				gVehData[tveh][mVehWheels] = 1083;
				return 1;
			}
		}
		case 45:
		{
			if(!IsAHelicopter(tveh+1) && !IsAPlane(tveh+1) && !IsAMotorBike(tveh+1) && !IsABike(tveh+1))
			{
				AddVehicleComponent(tveh+1, 1087);
				gVehData[tveh][mVehHydraulics] = 1087;
				return 1;
			}
		}
		case 46:
		{
			AddVehicleComponent(tveh+1, 1009);
			gVehData[tveh][mVehNitro] = 1009;
			return 1;
		}
		case 47:
		{
			AddVehicleComponent(tveh+1, 1008);
			gVehData[tveh][mVehNitro] = 1008;
			return 1;
		}
		case 48:
		{
			AddVehicleComponent(tveh+1, 1010);
			gVehData[tveh][mVehNitro] = 1010;
			return 1;
		}
		case 49:
		{
			if(IsATransfender(tveh+1))
			{
				AddVehicleComponent(tveh+1, 1018);
				gVehData[tveh][mVehExhaust] = 1018;
				return 1;
			}
		}
		case 50:
		{
			if(IsATransfender(tveh+1))
			{
				AddVehicleComponent(tveh+1, 1019);
				gVehData[tveh][mVehExhaust] = 1019;
				return 1;
			}
		}
		case 51:
		{
			if(IsATransfender(tveh+1))
			{
				AddVehicleComponent(tveh+1, 1020);
				gVehData[tveh][mVehExhaust] = 1020;
				return 1;
			}
		}
		case 52:
		{
			if(IsATransfender(tveh+1))
			{
				AddVehicleComponent(tveh+1, 1021);
				gVehData[tveh][mVehExhaust] = 1021;
				return 1;
			}
		}
		case 53:
		{
			if(IsATransfender(tveh+1))
			{
				AddVehicleComponent(tveh+1, 1022);
				gVehData[tveh][mVehExhaust] = 1022;
				return 1;
			}
		}
		case 54:
		{
			if((IsATransfender(tveh+1) && gVehData[tveh][mVehModel] != 400 && gVehData[tveh][mVehModel] != 409 && gVehData[tveh][mVehModel] != 422) || gVehData[tveh][mVehModel] == 560)
			{
				AddVehicleComponent(tveh+1, 1000);
				gVehData[tveh][mVehSpoiler] = 1000;
				return 1;
			}
		}
		case 55:
		{
			if((IsATransfender(tveh+1) && gVehData[tveh][mVehModel] != 400 && gVehData[tveh][mVehModel] != 409 && gVehData[tveh][mVehModel] != 422) || gVehData[tveh][mVehModel] == 560)
			{
				AddVehicleComponent(tveh+1, 1001);
				gVehData[tveh][mVehSpoiler] = 1001;
				return 1;
			}
		}
		case 56:
		{
			if((IsATransfender(tveh+1) && gVehData[tveh][mVehModel] != 400 && gVehData[tveh][mVehModel] != 409 && gVehData[tveh][mVehModel] != 422) || gVehData[tveh][mVehModel] == 560)
			{
				AddVehicleComponent(tveh+1, 1002);
				gVehData[tveh][mVehSpoiler] = 1002;
				return 1;
			}
		}
		case 57:
		{
			if((IsATransfender(tveh+1) && gVehData[tveh][mVehModel] != 400 && gVehData[tveh][mVehModel] != 409 && gVehData[tveh][mVehModel] != 422) || gVehData[tveh][mVehModel] == 560)
			{
				AddVehicleComponent(tveh+1, 1003);
				gVehData[tveh][mVehSpoiler] = 1003;
				return 1;
			}
		}
		case 58:
		{
			if((IsATransfender(tveh+1) && gVehData[tveh][mVehModel] != 400 && gVehData[tveh][mVehModel] != 409 && gVehData[tveh][mVehModel] != 422) || gVehData[tveh][mVehModel] == 560)
			{
				AddVehicleComponent(tveh+1, 1014);
				gVehData[tveh][mVehSpoiler] = 1014;
				return 1;
			}
		}
		case 59:
		{
			if((IsATransfender(tveh+1) && gVehData[tveh][mVehModel] != 400 && gVehData[tveh][mVehModel] != 409 && gVehData[tveh][mVehModel] != 422) || gVehData[tveh][mVehModel] == 560)
			{
				AddVehicleComponent(tveh+1, 1015);
				gVehData[tveh][mVehSpoiler] = 1015;
				return 1;
			}
		}
		case 60:
		{
			if((IsATransfender(tveh+1) && gVehData[tveh][mVehModel] != 400 && gVehData[tveh][mVehModel] != 409 && gVehData[tveh][mVehModel] != 422) || gVehData[tveh][mVehModel] == 560)
			{
				AddVehicleComponent(tveh+1, 1016);
				gVehData[tveh][mVehSpoiler] = 1016;
				return 1;
			}
		}
		case 61:
		{
			if((IsATransfender(tveh+1) && gVehData[tveh][mVehModel] != 400 && gVehData[tveh][mVehModel] != 409 && gVehData[tveh][mVehModel] != 422) || gVehData[tveh][mVehModel] == 560)
			{
				AddVehicleComponent(tveh+1, 1023);
				gVehData[tveh][mVehSpoiler] = 1023;
				return 1;
			}
		}
		case 62:
		{
			if(VehVentModel(tveh+1))
			{
				AddVehicleComponent(tveh+1, 1142);
				gVehData[tveh][mVehVentLeft] = 1142;
				return 1;
			}
		}
		case 63:
		{
			if(VehVentModel(tveh+1))
			{
				AddVehicleComponent(tveh+1, 1143);
				gVehData[tveh][mVehVentRight] = 1143;
				return 1;
			}
		}
		case 64:
		{
			if(VehVentModel(tveh+1))
			{
				AddVehicleComponent(tveh+1, 1144);
				gVehData[tveh][mVehVentLeft] = 1144;
				return 1;
			}
		}
		case 65:
		{
			if(VehVentModel(tveh+1))
			{
				AddVehicleComponent(tveh+1, 1145);
				gVehData[tveh][mVehVentRight] = 1145;
				return 1;
			}
		}
		case 66:
		{
			if(VehLampModel(tveh+1))
			{
				AddVehicleComponent(tveh+1, 1013);
				gVehData[tveh][mVehLamps] = 1013;
				return 1;
			}
		}
		case 67:
		{
			if(VehLampModel(tveh+1))
			{
				AddVehicleComponent(tveh+1, 1024);
				gVehData[tveh][mVehLamps] = 1024;
				return 1;
			}
		}
		case 68:
		{
			if(VehHoodModel(tveh+1))
			{
				AddVehicleComponent(tveh+1, 1011);
				gVehData[tveh][mVehHood] = 1011;
				return 1;
			}
		}
		case 69:
		{
			if(VehHoodModel(tveh+1))
			{
				AddVehicleComponent(tveh+1, 1012);
				gVehData[tveh][mVehHood] = 1012;
				return 1;
			}
		}
	}
	return 0;
}