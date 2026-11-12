#pragma once

#include "types.h"
#include "Main/MapObjects/attractor.h" // MapObjectList

typedef struct Pukupuku Pukupuku;
typedef struct MapObjectKindData MapObjectKindData;

extern MapObjectList *gPukupukuUpdateList;

// 0x2c-byte object built from a table: a MapObjectList followed by the slot.
typedef struct PukupukuShadowDrawList {
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
} PukupukuShadowDrawList;

extern PukupukuShadowDrawList *gPukupukuShadowDrawList;

// 0x2c-byte object built from a table: a MapObjectList followed by the slot.
typedef struct PukupukuDrawList {
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
} PukupukuDrawList;

extern PukupukuDrawList *gPukupukuDrawList;

MapObjectKindData *CreatePukupukuKindData(void);
PukupukuDrawList *CreatePukupukuDrawList(void);
PukupukuShadowDrawList *CreatePukupukuShadowDrawList(void);
MapObjectList *CreatePukupukuUpdateList(void);
void SetupDrawPukupuku(void);
void DrawPukupuku(u32 unused, Pukupuku *pukupuku, u32 unusedArg, u16 alpha);
