#include "SA2ModLoader.h"

extern "C"
{
	void fixSwitchRings();
	void objectsPyramidCave();
	void objectsGrindRace();
	void objectsPyramidRace();
	void objectsWildCanyon();
	void objectsDeathChamber();
	void objectsHiddenBase2P();
	void objectsEggGolem();
	void objectsDryLagoon();
	void objectsCityEscape();
	void objectsIronGate();
	void objectsCosmicWall();
	void objectsMetalHarbor();
	void objectsMisc();
	void butt();
	__declspec(dllexport) ModInfo SA2ModInfo = { ModLoaderVer };
	__declspec(dllexport) void _cdecl Init(const char* path, const HelperFunctions& helperFunctions)
	{
		//Allow Big to spawn in 2P Mode.
		WriteData((short*)0x4F6201, (short)0x04EB);
		WriteData<4>((BYTE*)0x4F6203, (BYTE)0x90);

		//Make the perfect ring tally count Switch-activated Rings.
		fixSwitchRings();
		
		/*The following fixes are for pointers in object lists that point
		to Rings or Nothing but should be different objects.*/

		objectsPyramidCave();
		objectsGrindRace();
		objectsPyramidRace();
		objectsWildCanyon();
		objectsDeathChamber();
		objectsHiddenBase2P();
		objectsEggGolem();
		objectsDryLagoon();
		objectsCityEscape();
		objectsIronGate();
		objectsMetalHarbor();
		objectsCosmicWall();
		objectsMisc();
	}

	void objectsMisc() {
		//Fixes for stages that only need one object fixed
		//BIG THE CAT in Sand Ocean 2P
		WriteData((BYTE*)0x141537A, (BYTE)4);
		WriteData((float*)0x141537C, 1000000.0f);
		WriteData((int*)0x1415380, 0x4F61E0);
		WriteData((int*)0x1415384, 0x8BAA8C);

		//PSKULL in Sky Rail
		WriteData((int*)0x11782D0, 0x6D4890);

		//MINIMAL in Lost Colony 2P
		WriteData((int*)0xC500F0, 0x48ADE0);
	}

	void fixSwitchRings() {
		//White Jungle
		WriteData((BYTE*)0xE99AB2, (BYTE)0x20);
		WriteData((BYTE*)0xE99AC2, (BYTE)0x20);

		//City Escape
		WriteData((BYTE*)0x109EC62, (BYTE)0x20);
		WriteData((BYTE*)0x109EC72, (BYTE)0x20);
		
		//Downtown Race
		WriteData((BYTE*)0x1407E0A, (BYTE)0x20);
		WriteData((BYTE*)0x1407E1A, (BYTE)0x20);

		//Green Forest
		WriteData((BYTE*)0x1086182, (BYTE)0x20);
		WriteData((BYTE*)0x1086192, (BYTE)0x20);
		
		//Grind Race
		WriteData((BYTE*)0x141C30A, (BYTE)0x20);
		WriteData((BYTE*)0x141C31A, (BYTE)0x20);

		//Crazy Gadget
		WriteData((BYTE*)0x9BB462, (BYTE)0x20);
		WriteData((BYTE*)0x9BB472, (BYTE)0x20);

		//Cannon's Core
		WriteData((BYTE*)0x164A962, (BYTE)0x20);
		WriteData((BYTE*)0x164A972, (BYTE)0x20);
	}

	void objectsCityEscape() {
		//LIGHT SW (Will fix shaded areas)
		WriteData((int*)0x109EBD8, 0x6C9910);

		//Same but for Downtown Race
		WriteData((int*)0x1407D80, 0x6C9910);
	}

	void objectsMetalHarbor() {
		//2P
		//MINIMAL (Commented out due to animals spawning in the stage)
		// WriteData((int*)0xDBB510, 0x48ADE0);

		//E PATH
		WriteData((int*)0xDBB6A0, 0x505C20);
	}

	void objectsIronGate() {
		//2P
		//MINIMAL
		WriteData((int*)0x1369118, 0x48ADE0);

		//E PATH
		WriteData((int*)0x1369438, 0x505C20);
	}

	void objectsCosmicWall() {
		//E CHAOS
		WriteData((int*)0xEDD538, 0x50A850);

		//E PATH
		WriteData((int*)0xEDD548, 0x505C20);

		//MINIMAL
		WriteData((int*)0xEDD3A8, 0x48ADE0);
	}

	void objectsGrindRace() {
		//15 EMERALD
		WriteData((BYTE*)0x141C00A, (BYTE)4);
		WriteData((int*)0x141C010, 0x6D00C0);
		WriteData((int*)0x141C014, 0x8BB198);

		//17 ORI
		WriteData((BYTE*)0x141C02A, (BYTE)0);
		WriteData((int*)0x141C030, 0x6D29F0);
		WriteData((int*)0x141C034, 0x8BB1C8);

		//18 DYNAMITE
		WriteData((BYTE*)0x141C03A, (BYTE)0);
		WriteData((int*)0x141C040, 0x6DA720);
		WriteData((int*)0x141C044, 0x8BB18C);

		//21 ROCKET
		WriteData((BYTE*)0x141C068, (BYTE)6);
		WriteData((BYTE*)0x141C06A, (BYTE)0);
		WriteData((int*)0x141C070, 0x6D4EA0);
		WriteData((int*)0x141C074, 0x8BC264);

		//22 ROCKETMISSILE
		WriteData((BYTE*)0x141C078, (BYTE)6);
		WriteData((BYTE*)0x141C07A, (BYTE)0);
		WriteData((int*)0x141C080, 0x6CE4C0);
		WriteData((int*)0x141C084, 0x8BC254);
		
		//23 SCHBOX
		WriteData((BYTE*)0x141C08A, (BYTE)0);
		WriteData((int*)0x141C090, 0x6E7F60);
		WriteData((int*)0x141C094, 0x8BC24C);

		//24 HINTBOX
		WriteData((BYTE*)0x141C09A, (BYTE)0);
		WriteData((int*)0x141C0A0, 0x6E2700);
		WriteData((int*)0x141C0A4, 0x8BC244);

		//26 SSS
		WriteData((BYTE*)0x141C0B8, (BYTE)3);
		WriteData((BYTE*)0x141C0BA, (BYTE)0);
		WriteData((int*)0x141C0C0, 0x6DE130);
		WriteData((int*)0x141C0C4, 0x8BC238);

		//33 MINIMAL
		WriteData((BYTE*)0x141C12A, (BYTE)0);
		WriteData((int*)0x141C130, 0x48ADE0);
		WriteData((int*)0x141C134, 0x8BC21C);

		//34 WSMMLS
		WriteData((BYTE*)0x141C13A, (BYTE)0);
		WriteData((int*)0x141C140, 0x6EA1E0);
		WriteData((int*)0x141C144, 0x8BC214);

		//34 STOPLSD
		WriteData((BYTE*)0x141C152, (BYTE)0);
		WriteData((int*)0x141C160, 0x6DE270);
		WriteData((int*)0x141C164, 0x8BB128);
		
		//37 KNUDAI
		WriteData((BYTE*)0x141C168, (BYTE)6);
		WriteData((BYTE*)0x141C16A, (BYTE)1);
		WriteData((float*)0x141C16C, 1000000.0f);
		WriteData((int*)0x141C170, 0x6E7480);
		WriteData((int*)0x141C174, 0x8BC200);
		
		//38 KDASIBA
		WriteData((BYTE*)0x141C178, (BYTE)6);
		WriteData((BYTE*)0x141C17A, (BYTE)0);
		WriteData((int*)0x141C180, 0x6E6680);
		WriteData((int*)0x141C184, 0x8BC1F8);
		
		//39 KDWARPHOLE
		WriteData((BYTE*)0x141C18A, (BYTE)4);
		WriteData((int*)0x141C190, 0x6E2F00);
		WriteData((int*)0x141C194, 0x8BC1EC);
		
		//40 KDDOOR (This still doesn't work and I don't know why, this data is correct.)
		WriteData((BYTE*)0x141C198, (BYTE)6);
		WriteData((BYTE*)0x141C19A, (BYTE)0);
		WriteData((int*)0x141C1A0, 0x6E3F80);
		WriteData((int*)0x141C1A4, 0x8BC1E4);
		
		//41 KDITEMBOX
		WriteData((BYTE*)0x141C1AA, (BYTE)0x30);
		WriteData((int*)0x141C1B0, 0x6E9350);
		WriteData((int*)0x141C1B4, 0x8BC1D8);

		//51 MODMOD
		WriteData((BYTE*)0x141C24A, (BYTE)0);
		WriteData((int*)0x141C250, 0x5F5580);
		WriteData((int*)0x141C254, 0x8BC180);
		
		//52 EFFOBJ0
		WriteData((BYTE*)0x141C25A, (BYTE)0);
		WriteData((int*)0x141C260, 0x6C5570);
		WriteData((int*)0x141C264, 0x8BAAA4);
		
		//53 EFFLENSF0
		WriteData((BYTE*)0x141C26A, (BYTE)2);
		WriteData((int*)0x141C270, 0x6C75C0);
		WriteData((int*)0x141C274, 0x8BAA98);

		//59 EPATH
		WriteData((int*)0x141C2D0, 0x505C20);

		//61 BIG THE CAT
		WriteData((BYTE*)0x141C2EA, (BYTE)4);
		WriteData((float*)0x141C2EC, 1000000.0f);
		WriteData((int*)0x141C2F0, 0x4F61E0);
		WriteData((int*)0x141C2F4, 0x8BAA8C);
	}

	void objectsPyramidCave() {
		//Change collision for CHIMNEY from capsule to cylinder
		//to make a spring possible to hit again:
		WriteData((BYTE*)0xACC5A5, (BYTE)1);

		//Emerald
		WriteData((BYTE*)0xAB6172, (BYTE)4);
		WriteData((int*)0xAB6178, 0x6D00C0);
		WriteData((int*)0xAB617C, 0x8BB198);

		//DYNAMITE
		WriteData((BYTE*)0xAB61A2, (BYTE)0);
		WriteData((int*)0xAB61A8, 0x6DA720);
		WriteData((int*)0xAB61AC, 0x8BB18C);

		//SCHBOX
		WriteData((BYTE*)0xAB61F2, (BYTE)0);
		WriteData((int*)0xAB61F8, 0x6E7F60);
		WriteData((int*)0xAB61FC, 0x8BC24C);

		//HINTBOX
		WriteData((BYTE*)0xAB6202, (BYTE)0);
		WriteData((int*)0xAB6208, 0x6E2700);
		WriteData((int*)0xAB620C, 0x8BC244);

		//SSS
		WriteData((BYTE*)0xAB6220, (BYTE)3);
		WriteData((BYTE*)0xAB6222, (BYTE)0);
		WriteData((int*)0xAB6228, 0x6DE130);
		WriteData((int*)0xAB622C, 0x8BC238);

		//EPATH, label is already correct just needed to point to the correct function.
		WriteData((int*)0xAB6438, 0x505C20);
	}

	void objectsPyramidRace() {
		//33 MINIMAL
		WriteData((BYTE*)0x15A7332, (BYTE)0);
		WriteData((int*)0x15A7338, 0x48ADE0);
		WriteData((int*)0x15A733C, 0x8BC21C);

		//34 WSMMLS
		WriteData((BYTE*)0x15A7340, (BYTE)0);
		WriteData((int*)0x15A7348, 0x6EA1E0);
		WriteData((int*)0x15A734C, 0x8BC214);

		//82 BIG THE CAT
		WriteData((BYTE*)0x15A7672, (BYTE)4);
		WriteData((float*)0x15A7674, 1000000.0f);
		WriteData((int*)0x15A7678, 0x4F61E0);
		WriteData((int*)0x15A767C, 0x8BAA8C);
	}

	void objectsWildCanyon() {
		//1P
		//BIG THE CAT
		WriteData((BYTE*)0xBD7962, (BYTE)4);
		WriteData((float*)0xBD7964, 1000000.0f);
		WriteData((int*)0xBD7968, 0x4F61E0);
		WriteData((int*)0xBD796C, 0x8BAA8C);

		//2P
		//33 MINIMAL
		WriteData((BYTE*)0x1672952, (BYTE)0);
		WriteData((int*)0x1672958, 0x48ADE0);
		WriteData((int*)0x167295C, 0x8BC21C);

		//34 WSMMLS
		WriteData((BYTE*)0x1672960, (BYTE)0);
		WriteData((int*)0x1672968, 0x6EA1E0);
		WriteData((int*)0x167296C, 0x8BC214);

		//82 BIG THE CAT
		WriteData((BYTE*)0x1672C62, (BYTE)4);
		WriteData((float*)0x1672C64, 1000000.0f);
		WriteData((int*)0x1672C68, 0x4F61E0);
		WriteData((int*)0x1672C6C, 0x8BAA8C);
	}

	void objectsHiddenBase2P() {
		//33 MINIMAL
		WriteData((BYTE*)0xD026F2, (BYTE)0);
		WriteData((int*)0xD026F8, 0x48ADE0);
		WriteData((int*)0xD026FC, 0x8BC21C);

		//34 WSMMLS
		WriteData((BYTE*)0xD02702, (BYTE)0);
		WriteData((int*)0xD02708, 0x6EA1E0);
		WriteData((int*)0xD0270C, 0x8BC214);
		
		//57 E UNI
		WriteData((BYTE*)0xD02872, (BYTE)4);
		WriteData((int*)0xD02878, 0x50F150);
		WriteData((int*)0xD0287C, 0x8BFAB8);

		//58 E SARU
		WriteData((BYTE*)0xD02882, (BYTE)4);
		WriteData((int*)0xD02888, 0x50E4D0);
		WriteData((int*)0xD0288C, 0x8BD81C);

		//59 E 1000
		WriteData((BYTE*)0xD02892, (BYTE)4);
		WriteData((int*)0xD02898, 0x50D790);
		WriteData((int*)0xD0289C, 0x8BD814);

		//60 E SHOUKO
		WriteData((BYTE*)0xD028A2, (BYTE)5);
		WriteData((float*)0xD028A4, 4000000.0f);
		WriteData((int*)0xD028A8, 0x4F9F00);
		WriteData((int*)0xD028AC, 0x8BB14C);

		//61 E SW SHOUKO
		WriteData((BYTE*)0xD028B2, (BYTE)0);
		WriteData((int*)0xD028B8, 0x4FA070);
		WriteData((int*)0xD028BC, 0x8BB140);

		//77 E KYOKO
		WriteData((BYTE*)0xD029B2, (BYTE)4);
		WriteData((int*)0xD029B8, 0x4FA070);
		WriteData((int*)0xD029BC, 0x8BB140);
		
		//78 E PATH
		WriteData((BYTE*)0xD029C2, (BYTE)4);
		WriteData((int*)0xD029C8, 0x505C20);
		WriteData((int*)0xD029CC, 0x8BC168);

		//85 BIG THE CAT
		WriteData((BYTE*)0xD02A32, (BYTE)4);
		WriteData((float*)0xD02A34, 1000000.0f);
		WriteData((int*)0xD02A38, 0x4F61E0);
		WriteData((int*)0xD02A3C, 0x8BAA8C);


	}

	void objectsDeathChamber() {
		//5D G LIGHT SW
		WriteData((BYTE*)0xBA5702, (BYTE)1);
		WriteData((float*)0xBA5704, 1000000.0f);
		WriteData((int*)0xBA5708, 0x4CA9B0);
		WriteData((int*)0xBA570C, 0x8BCB4C);
		
		//2P
		//93 G LIGHT SW
		WriteData((BYTE*)0xDBE6FA, (BYTE)1);
		WriteData((float*)0xDBE6FC, 1000000.0f);
		WriteData((int*)0xDBE700, 0x4CA9B0);
		WriteData((int*)0xDBE704, 0x8BCB4C);

		//94 BIG THE CAT
		WriteData((BYTE*)0xDBE70A, (BYTE)4);
		WriteData((float*)0xDBE70C, 1000000.0f);
		WriteData((int*)0xDBE700, 0x4F61E0);
		WriteData((int*)0xDBE704, 0x8BAA8C);
	}

	void objectsEggGolem() {
		//E KUMI
		WriteData((BYTE*)0x165E57A, (BYTE)4);
		WriteData((int*)0x165E580, 0x501530);
		WriteData((int*)0x165E584, 0x8BB178);

		//E EMI
		WriteData((BYTE*)0x165E58A, (BYTE)4);
		WriteData((int*)0x165E590, 0x4FDD00);
		WriteData((int*)0x165E594, 0x8BB170);

		//E AI
		WriteData((BYTE*)0x165E59A, (BYTE)4);
		WriteData((int*)0x165E5A0, 0x4FF990);
		WriteData((int*)0x165E5A4, 0x8BB168);

		//E KYOKO
		WriteData((BYTE*)0x165E5AA, (BYTE)4);
		WriteData((int*)0x165E5B0, 0x4FC700);
		WriteData((int*)0x165E5B4, 0x8BB160);

		//E NAMIE
		WriteData((BYTE*)0x165E5BA, (BYTE)4);
		WriteData((int*)0x165E5C0, 0x4F8F90);
		WriteData((int*)0x165E5C4, 0x8BB158);
		
		//E SHOUKO
		WriteData((BYTE*)0x165E5CA, (BYTE)1);
		WriteData((float*)0x165E5CC, 4000000.0f);
		WriteData((int*)0x165E5D0, 0x4F9F00);
		WriteData((int*)0x165E5D4, 0x8BB14C);
		
		//E SW SHOUKO
		WriteData((BYTE*)0x165E5DA, (BYTE)0);
		WriteData((int*)0x165E5E0, 0x4FA070);
		WriteData((int*)0x165E5E4, 0x8BB140);
		
		//E GHOST
		WriteData((BYTE*)0x165E5EA, (BYTE)4);
		WriteData((int*)0x165E5F0, 0x503140);
		WriteData((int*)0x165E5F4, 0x8BB138);
	}

	void objectsDryLagoon() {
		/*
		//1P, cut because these objects were removed and the game crashes trying to load the stage with them in the list.
		//64 BOARD
		WriteData((BYTE*)0xDEB95A, (BYTE)1);
		WriteData((float*)0xDEB95C, 360000.0f);
		WriteData((int*)0xDEB960, 0x6A7980);
		WriteData((int*)0xDEB964, 0x8BCBCC);

		//89 STONEHEAD
		WriteData((BYTE*)0xDEBA4A, (BYTE)0);
		WriteData((float*)0xDEBA4C, 0.0f);
		WriteData((int*)0xDEBA40, 0x6A3630);
		WriteData((int*)0xDEBA44, 0x8BCBBC);*/

		//2P
		//25 OMOCHAO
		WriteData((BYTE*)0x1564900, (BYTE)3);
		WriteData((BYTE*)0x1564902, (BYTE)0);
		WriteData((int*)0x1564908, 0x6C0780);
		WriteData((int*)0x156490C, 0x8BC23C);

		//33 MINIMAL
		WriteData((BYTE*)0x1564982, (BYTE)0);
		WriteData((int*)0x1564988, 0x48ADE0);
		WriteData((int*)0x156498C, 0x8BC21C);

		//34 WSMMLS
		WriteData((BYTE*)0x1564992, (BYTE)0);
		WriteData((int*)0x1564998, 0x6EA1E0);
		WriteData((int*)0x156499C, 0x8BC214);

		//53 EFFLENSF0
		WriteData((BYTE*)0x1564AC2, (BYTE)2);
		WriteData((int*)0x1564AC8, 0x6C75C0);
		WriteData((int*)0x1564ACC, 0x8BAA98);

		//60 BIG THE CAT
		WriteData((BYTE*)0x1564B32, (BYTE)4);
		WriteData((float*)0x1564B34, 1000000.0f);
		WriteData((int*)0x1564B38, 0x4F61E0);
		WriteData((int*)0x1564B3C, 0x8BAA8C);

		//61 KAME
		WriteData((BYTE*)0x1564B49, (BYTE)6);
		WriteData((BYTE*)0x1564B42, (BYTE)2);
		WriteData((float*)0x1564B44, 4000000.0f);
		WriteData((int*)0x1564B48, 0x6416C0);
		WriteData((int*)0x1564B4C, 0x8C9BBC);

		//63 SIDEWIND
		WriteData((BYTE*)0x1564B62, (BYTE)0);
		WriteData((int*)0x1564B68, 0x648270);
		WriteData((int*)0x1564B6C, 0x8C9BB0);

		/*Crash
		//76 CHIN2
		WriteData((BYTE*)0x1564C32, (BYTE)0);
		WriteData((int*)0x1564C38, 0x648010);
		WriteData((int*)0x1564C3C, 0x8C9BA8);

		//77 CHIN3
		WriteData((BYTE*)0x1564C42, (BYTE)0);
		WriteData((int*)0x1564C48, 0x647DB0);
		WriteData((int*)0x1564C4C, 0x8C9BA0);*/
	}
}