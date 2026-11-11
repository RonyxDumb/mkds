#pragma once

#include "types.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObjectList

typedef struct PushedObject PushedObject;
typedef struct Woodbox1 Woodbox1;
typedef struct Kart Kart;
typedef struct ItemObject ItemObject;

extern MapObjectList *data_0217bbf4;

// Initialiser stored into the 0x2c-byte object CreateWoodbox1DrawList allocates: a MapObjectList followed by the slot.
typedef struct Woodbox1DrawList {
    /* 00 */ void **mMapObjects;
    /* 04 */ u16 mMapObjectCount;
    /* 06 */ u8 mUnk_06[2];
    /* 08 */ void (*mInit)(struct MapObjectList *p);
    /* 0c */ void (*mBeforeObjects)(struct MapObjectList *p);
    /* 10 */ UnkFunc *mForEachObject;
    /* 14 */ void (*mAfterObjects)(struct MapObjectList *p);
    /* 18 */ u32 mDrawPass;
    /* 1c */ u32 mUnk_1c;
    /* 20 */ u32 mUnk_20;
    /* 24 */ void **mDrawObjects;
    /* 28 */ u32 mListSlot;
} Woodbox1DrawList;

extern Woodbox1DrawList *data_0217bbec;

// Initialiser stored into the 0x40-byte object CreateWoodbox1KindData allocates.
typedef struct Unk02159538 {
    /* 00 */ u32 (*mUnk_00)(Woodbox1 *woodbox, Kart *kart, u8 *firstResponse, u8 *response);
    /* 04 */ u32 (*mUnk_04)(Woodbox1 *woodbox, ItemObject *itemObject, u8 *firstResponse, u8 *response);
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ u32 mUnk_18;
    /* 1c */ u32 mUnk_1c;
    /* 20 */ u32 mUnk_20;
    /* 24 */ u32 mUnk_24;
    /* 28 */ u32 mUnk_28;
    /* 2c */ u32 mUnk_2c;
    /* 30 */ u32 mUnk_30;
    /* 34 */ u32 mUnk_34;
    /* 38 */ u32 mUnk_38;
    /* 3c */ u32 mUnk_3c;
} Unk02159538;

extern const MapObjectList data_021594e4;
extern const Woodbox1DrawList data_0215950c;
extern const Unk02159538 data_02159538;

void DrawWoodbox1(void *mapObjectList, Woodbox1 *woodbox, void *unused, u32 maxAlpha);
MapObjectList *CreateWoodbox1UpdateList(void);
Woodbox1DrawList *CreateWoodbox1DrawList(void);
Unk02159538 *CreateWoodbox1KindData(void);
BOOL HitPushedObjectByItemObject(PushedObject *mapObject, void *other, u8 *firstResponse);
BOOL HitPushedObjectByKart(PushedObject *mapObject, void *other, u8 *firstResponse);
