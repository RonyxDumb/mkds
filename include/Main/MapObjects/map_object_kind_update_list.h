#pragma once

#include "types.h"

typedef struct MapObjectKindData MapObjectKindData;
typedef struct MapObject MapObject;
typedef struct MapObjectList MapObjectList;
typedef struct CourseMapRow CourseMapRow;

struct MapObjectKindDescriptor;
typedef struct RotaryKindInfo RotaryKindInfo;

// Row of the table searched by FindMapObjectKindDrawList0 and FindMapObjectKindUpdateList.
typedef struct MapObjectKindRow {
    /* 00 */ u32 mKind;
    /* 04 */ struct MapObjectKindDescriptor *mDescriptor;
    /* 08 */ void *mInitData;
} MapObjectKindRow;

extern MapObjectKindRow gMapObjectKindRows[];

// Kind numbers (the mKind member of MapObjectKindRow) of rows whose class the tree names: the Init function in the
// row's descriptor (CreateCream and CreateBerry, the model loaders, for the last two rows) carries the class name; for
// RainStar, Rock, Rock2, ObPakkunSf and Pendulum it is a function of the lists the row builds. Other rows stay
// literals. CarA, BusA and TruckA share one Init: their CreateKindData function carries the class name.
// The class ItemBox also has kind 0xc9 (own Init and update list), which stays a literal.
#define MAP_OBJECT_KIND_ITEM_BOX 0x65
#define MAP_OBJECT_KIND_WOODBOX1 0x67
#define MAP_OBJECT_KIND_SHINE16 0x6a
#define MAP_OBJECT_KIND_BALLOON 0x6c
#define MAP_OBJECT_KIND_MISSION_GATE 0x6e
#define MAP_OBJECT_KIND_SHINE_BALLOON 0x70
#define MAP_OBJECT_KIND_KOOPA_BLOCK 0xca
#define MAP_OBJECT_KIND_ROTARY_GEAR 0xcb
#define MAP_OBJECT_KIND_BRIDGE 0xcc
#define MAP_OBJECT_KIND_SECOND_HAND 0xcd
#define MAP_OBJECT_KIND_PENDULUM 0xcf
#define MAP_OBJECT_KIND_EARTHEN_PIPE 0x12f
#define MAP_OBJECT_KIND_TERESA 0x13b
#define MAP_OBJECT_KIND_RAIN_STAR 0x154
#define MAP_OBJECT_KIND_STOP_SIGN 0x159
#define MAP_OBJECT_KIND_KURIBO 0x191
#define MAP_OBJECT_KIND_ROCK 0x192
#define MAP_OBJECT_KIND_DOSSUN 0x193
#define MAP_OBJECT_KIND_BUS_A 0x195
#define MAP_OBJECT_KIND_MKD_EF_BUBBLE 0x198
#define MAP_OBJECT_KIND_CAR_A 0x19a
#define MAP_OBJECT_KIND_CHOROPU 0x199
#define MAP_OBJECT_KIND_PUKUPUKU 0x19b
#define MAP_OBJECT_KIND_TRUCK_A 0x19c
#define MAP_OBJECT_KIND_SMAN 0x19d
#define MAP_OBJECT_KIND_BASABASA 0x19f
#define MAP_OBJECT_KIND_NS_KILLER2 0x1a2
#define MAP_OBJECT_KIND_MOVE_TREE 0x1a3
#define MAP_OBJECT_KIND_MKD_EF_BURNER 0x1a4
#define MAP_OBJECT_KIND_OB_PAKKUN_SF 0x1a6
#define MAP_OBJECT_KIND_COVER_POO_HOLE 0x1a7
#define MAP_OBJECT_KIND_BOUND 0x1a8
#define MAP_OBJECT_KIND_FLIPPER 0x1a9
#define MAP_OBJECT_KIND_CRAB 0x1ac
// InitSun creates 30 objects of the pool kind MAP_OBJECT_KIND_SUN_FIREBALL.
#define MAP_OBJECT_KIND_SUN 0x1ad
// Pool kind of the SunFireball objects (StartSunFireball unparks them).
#define MAP_OBJECT_KIND_SUN_FIREBALL 0x1ae
#define MAP_OBJECT_KIND_FIREBALL2 0x1af
// The class IronBall also has kind 0x1b3 (Init and Draw only), which stays a literal.
#define MAP_OBJECT_KIND_IRON_BALL 0x1b0
#define MAP_OBJECT_KIND_ROCK2 0x1b1
#define MAP_OBJECT_KIND_SANBO 0x1b2
#define MAP_OBJECT_KIND_CREAM 0x1b4
// Mission Run boss kind: Boss Donketu.
#define MAP_OBJECT_KIND_BOSS_DONKETU 0x1f5
// Mission Run boss kind: King Ice Donketu.
#define MAP_OBJECT_KIND_KING_ICE_DONKETU 0x1f6
#define MAP_OBJECT_KIND_BOMB_KING 0x1f8
#define MAP_OBJECT_KIND_HANACHAN 0x1fc
#define MAP_OBJECT_KIND_IWANTE 0x1fb
#define MAP_OBJECT_KIND_KURIKING 0x1f7
#define MAP_OBJECT_KIND_BERRY 0x1b5

// Object behind MapObjectKindRow.mUnk_04.
typedef struct MapObjectKindDescriptor {
    /* 00 */ u16 mObjectCount;
    /* 02 */ u8 mUnk_02[2];
    /* 04 */ s32 mObjectSize;
    /* 08 */ void (*mInitObject)(void *a, CourseMapRow *b, void *c);
    /* 0c */ MapObjectKindData *(*mCreateKindData)(void);
    /* 10 */ MapObjectList *(*mCreateDrawList0)(void);
    /* 14 */ MapObjectList *(*mCreateDrawList1)(void);
    /* 18 */ MapObjectList *(*mCreateDrawList2)(void);
    /* 1c */ MapObjectList *(*mCreateUpdateList)(void);
    /* 20 */ MapObjectKindData *mKindData;
    /* 24 */ MapObjectList *mLists[4];
} MapObjectKindDescriptor;

MapObjectList *FindMapObjectKindUpdateList(u32 kind);
void *FindMapObjectKindDrawList0(u32 kind);

// Kind descriptors that gMapObjectKindRows[].mDescriptor points at.
extern const MapObjectKindDescriptor data_usa_02156474;
extern const MapObjectKindDescriptor data_usa_021582cc;
extern const MapObjectKindDescriptor data_usa_02158300;
extern const MapObjectKindDescriptor data_usa_021583d8;
extern const MapObjectKindDescriptor gItemBoxKindDescriptor;
extern const MapObjectKindDescriptor gGroupItemBoxKindDescriptor;
extern const MapObjectKindDescriptor gMkdEfBubbleKindDescriptor;
extern const MapObjectKindDescriptor gKoopaBlockKindDescriptor;
extern const MapObjectKindDescriptor data_usa_0215890c;
extern const MapObjectKindDescriptor data_usa_02158940;
extern const MapObjectKindDescriptor data_usa_02158974;
extern const MapObjectKindDescriptor data_usa_02158b80;
extern const MapObjectKindDescriptor data_usa_02158c8c;
extern const MapObjectKindDescriptor data_usa_02158fb0;
extern const MapObjectKindDescriptor gSecondHandKindDescriptor;
extern const MapObjectKindDescriptor gObPakkunSfKindDescriptor;
extern const MapObjectKindDescriptor gPendulumKindDescriptor;
extern const MapObjectKindDescriptor data_usa_021594a0;
extern const MapObjectKindDescriptor data_usa_0215a034;
extern MapObjectKindDescriptor data_usa_02167690;
extern MapObjectKindDescriptor data_usa_02167940;
extern MapObjectKindDescriptor data_usa_02167de0;
extern u8 data_usa_02158a18[];
extern u8 data_usa_021589a8[];
extern u8 data_usa_021589e0[];
extern const MapObjectKindDescriptor gKuriboKindDescriptor;
extern const MapObjectKindDescriptor gAttractorKindDescriptor;
extern const MapObjectKindDescriptor gWaterKindDescriptor;
extern const MapObjectKindDescriptor gWaterEfctKindDescriptor;
extern const MapObjectKindDescriptor gRotaryGearBlackKindDescriptor;
extern const MapObjectKindDescriptor gRotaryTestCylinderKindDescriptor;
extern const MapObjectKindDescriptor gRotaryRoomKindDescriptor;
extern const MapObjectKindDescriptor gRotaryBridgeKindDescriptor;
extern const MapObjectKindDescriptor gDramKindDescriptor;
extern MapObjectKindDescriptor gSmanKindDescriptor;
extern MapObjectKindDescriptor gCowKindDescriptor;
extern MapObjectKindDescriptor gKanoke64KindDescriptor;
extern MapObjectKindDescriptor gBasabasaKindDescriptor;
extern MapObjectKindDescriptor gBasabasaBurstKindDescriptor;
extern MapObjectKindDescriptor gMkdEfBurnerKindDescriptor;
extern MapObjectKindDescriptor gNsKiller1KindDescriptor;
extern MapObjectKindDescriptor gMoveTreeKindDescriptor;
extern MapObjectKindDescriptor gTeresaKindDescriptor;
extern MapObjectKindDescriptor gTeresaSpawnerKindDescriptor;
extern MapObjectKindDescriptor gBakubakuKindDescriptor;
extern MapObjectKindDescriptor gCoverPooHoleKindDescriptor;
extern MapObjectKindDescriptor gPakkunSpitKindDescriptor;
extern MapObjectKindDescriptor gCrabKindDescriptor;
extern MapObjectKindDescriptor gBoundKindDescriptor;
extern MapObjectKindDescriptor gSunKindDescriptor;
extern MapObjectKindDescriptor gSunFireballKindDescriptor;
extern MapObjectKindDescriptor gFireball2KindDescriptor;
extern MapObjectKindDescriptor gPuddleKindDescriptor;
extern MapObjectKindDescriptor gPicture1KindDescriptor;
extern MapObjectKindDescriptor gPicture2KindDescriptor;
extern MapObjectKindDescriptor gRainStarKindDescriptor;
extern MapObjectKindDescriptor gChandelierKindDescriptor;
extern MapObjectKindDescriptor gTownMonteKindDescriptor;
extern MapObjectKindDescriptor gCourseMapRowKindDescriptor;
extern MapObjectKindDescriptor gShine16KindDescriptor;
extern MapObjectKindDescriptor gAirshipKindDescriptor;
extern MapObjectKindDescriptor gBalloonKindDescriptor;
extern MapObjectKindDescriptor gSanboKindDescriptor;
extern MapObjectKindDescriptor gIronBallKindDescriptor;
extern MapObjectKindDescriptor gIronBallDrawOnlyKindDescriptor;
extern MapObjectKindDescriptor gCreamKindDescriptor;
extern MapObjectKindDescriptor gBerryKindDescriptor;
extern MapObjectKindDescriptor gMissionGateKindDescriptor;
extern MapObjectKindDescriptor gStopSignKindDescriptor;
extern MapObjectKindDescriptor gBombKingKindDescriptor;
extern MapObjectKindDescriptor gKingTeresaKindDescriptor;
extern MapObjectKindDescriptor gCoinKindDescriptor;
extern MapObjectKindDescriptor gBossDonketuKindDescriptor;
extern MapObjectKindDescriptor gKingIceDonketuKindDescriptor;
extern MapObjectKindDescriptor gKurikingKindDescriptor;
extern MapObjectKindDescriptor gHanachanKindDescriptor;
extern MapObjectKindDescriptor gHanachanFollowerKindDescriptor;
extern MapObjectKindDescriptor gIwanteKindDescriptor;
extern MapObjectKindDescriptor gEmptyMapObjectKindDescriptor;
extern MapObjectKindDescriptor gCameraEffectKindDescriptor;
extern MapObjectKindDescriptor gPeriodicEffectKindDescriptor;
extern MapObjectKindDescriptor gIwanteHandsKindDescriptor;
extern const MapObjectKindDescriptor gPooledItemBoxKindDescriptor;
extern const MapObjectKindDescriptor gRockKindDescriptor;
extern const MapObjectKindDescriptor gRock2KindDescriptor;
extern MapObjectKindDescriptor gFlipperKindDescriptor;
extern MapObjectKindDescriptor gPakkunKindDescriptor;
extern MapObjectKindDescriptor gBeachTree1KindDescriptor;
extern MapObjectKindDescriptor gBeachTree1SecondKindDescriptor;
extern MapObjectKindDescriptor gOpaTree1KindDescriptor;
extern MapObjectKindDescriptor gOlgMush1KindDescriptor;
extern MapObjectKindDescriptor gOlgPipe1KindDescriptor;
extern MapObjectKindDescriptor gOf6yoshi1KindDescriptor;
extern MapObjectKindDescriptor gNsCannon1KindDescriptor;
extern MapObjectKindDescriptor gCrossTree1KindDescriptor;
extern MapObjectKindDescriptor gBankTree1KindDescriptor;
extern MapObjectKindDescriptor gGardenTree1KindDescriptor;
extern MapObjectKindDescriptor gGardenTree1SecondKindDescriptor;
extern MapObjectKindDescriptor gTownTree1KindDescriptor;
extern MapObjectKindDescriptor gTownTree1SecondKindDescriptor;
extern MapObjectKindDescriptor gMarioTree3KindDescriptor;
extern MapObjectKindDescriptor gSnowTree1KindDescriptor;
extern MapObjectKindDescriptor gSnowTree1SecondKindDescriptor;
extern MapObjectKindDescriptor gDeTree1KindDescriptor;
extern MapObjectKindDescriptor gDeTree1SecondKindDescriptor;
extern MapObjectKindDescriptor gOlaTree1cKindDescriptor;
extern MapObjectKindDescriptor gOsaTree1cKindDescriptor;
extern MapObjectKindDescriptor gKinoHouse1KindDescriptor;
extern MapObjectKindDescriptor gKinoHouse2KindDescriptor;
extern MapObjectKindDescriptor gKinoMount1KindDescriptor;
extern MapObjectKindDescriptor gKinoMount2KindDescriptor;
extern MapObjectKindDescriptor gOm6Tree1KindDescriptor;
extern MapObjectKindDescriptor gOf6Tree1KindDescriptor;
extern MapObjectKindDescriptor gOf6Tree1SecondKindDescriptor;
extern MapObjectKindDescriptor gBankEgg1KindDescriptor;
extern MapObjectKindDescriptor gMiniDokanKindDescriptor;
extern const RotaryKindInfo gRotaryGearBlackKindInfo;
extern const RotaryKindInfo gRotaryTestCylinderKindInfo;
extern const RotaryKindInfo gRotaryRoomKindInfo;
extern const RotaryKindInfo gRotaryBridgeKindInfo;
