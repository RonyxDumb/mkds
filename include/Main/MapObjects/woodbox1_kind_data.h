#pragma once

#include "types.h"
#include "Main/MapObjects/attractor.h" // MapObjectList
#include "Main/MapObjects/map_object_draw_list_flags.h"

typedef struct PushedObject PushedObject;
typedef struct Woodbox1 Woodbox1;
typedef struct Kart Kart;
typedef struct ItemObject ItemObject;

// Initialiser stored into the 0x40-byte object CreateWoodbox1KindData allocates.
typedef struct Woodbox1KindData {
    /* 00 */ u32 (*mCollideKartCallback)(Woodbox1 *woodbox, Kart *kart, u8 *firstResponse, u8 *response);
    /* 04 */ u32 (*mCollideItemObjectCallback)(Woodbox1 *woodbox, ItemObject *itemObject, u8 *firstResponse,
                                               u8 *response);
    /* 08 */ u32 mShapeKind;
    /* 0c */ u32 mExtentX;
    /* 10 */ u32 mExtentY;
    /* 14 */ u32 mExtentZ;
    /* 18 */ u32 mSphereHitTest;
    /* 1c */ u32 mCollidable;
    /* 20 */ u32 mPosStepMode;
    /* 24 */ u32 mSoundId;
    /* 28 */ u32 mCollideItemObjectSoundId;
    /* 2c */ u32 mViewRadius;
    /* 30 */ u32 mDrawDistance;
    /* 34 */ u32 mUseTwoPlaneViewTest;
    /* 38 */ u32 mHeightRangeMax;
    /* 3c */ u32 mHeightRangeMin;
} Woodbox1KindData;

extern const MapObjectList gWoodbox1UpdateListData;
extern const MapObjectDrawList gWoodbox1DrawListData;
extern const Woodbox1KindData gWoodbox1KindData;

void DrawWoodbox1(void *mapObjectList, Woodbox1 *woodbox, void *unused, u32 maxAlpha);
MapObjectList *CreateWoodbox1UpdateList(void);
MapObjectList *CreateWoodbox1DrawList(void);
Woodbox1KindData *CreateWoodbox1KindData(void);
BOOL HitPushedObjectByItemObject(PushedObject *mapObject, void *other, u8 *firstResponse);
BOOL HitPushedObjectByKart(PushedObject *mapObject, void *other, u8 *firstResponse);
