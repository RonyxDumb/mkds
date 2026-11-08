#pragma once

#include "types.h"

typedef struct Unk020e43a8 Unk020e43a8;
typedef struct MapObjectKindData MapObjectKindData;

// 0x28-byte object built from a table.
typedef struct PukupukuUpdateList {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mMapObjectCount;
    /* 08 */ u32 mInit;
    /* 0c */ u32 mBeforeObjects;
    /* 10 */ u32 mForEachObject;
    /* 14 */ u32 mAfterObjects;
    /* 18 */ u32 mUnk_18;
    /* 1c */ u32 mUnk_1c;
    /* 20 */ u32 mUnk_20;
    /* 24 */ u32 mListSlot;
} PukupukuUpdateList;

extern PukupukuUpdateList *gPukupukuUpdateList;

// 0x2c-byte object built from a table.
typedef struct PukupukuShadowDrawList {
    /* 00 */ u32 mMapObjects;
    /* 04 */ u32 mMapObjectCount;
    /* 08 */ u32 mInit;
    /* 0c */ u32 mBeforeObjects;
    /* 10 */ u32 mForEachObject;
    /* 14 */ u32 mAfterObjects;
    /* 18 */ u32 mDrawPass;
    /* 1c */ u32 mUnk_1c;
    /* 20 */ u32 mUnk_20;
    /* 24 */ u32 mDrawObjects;
    /* 28 */ u32 mListSlot;
} PukupukuShadowDrawList;

extern PukupukuShadowDrawList *gPukupukuShadowDrawList;

// 0x2c-byte object built from a table.
typedef struct PukupukuDrawList {
    /* 00 */ u32 mMapObjects;
    /* 04 */ u32 mMapObjectCount;
    /* 08 */ u32 mInit;
    /* 0c */ u32 mBeforeObjects;
    /* 10 */ u32 mForEachObject;
    /* 14 */ u32 mAfterObjects;
    /* 18 */ u32 mDrawPass;
    /* 1c */ u32 mUnk_1c;
    /* 20 */ u32 mUnk_20;
    /* 24 */ u32 mDrawObjects;
    /* 28 */ u32 mListSlot;
} PukupukuDrawList;

extern PukupukuDrawList *gPukupukuDrawList;

MapObjectKindData *CreatePukupukuKindData(void);
PukupukuDrawList *CreatePukupukuDrawList(void);
PukupukuShadowDrawList *CreatePukupukuShadowDrawList(void);
PukupukuUpdateList *CreatePukupukuUpdateList(void);
void SetupDrawPukupuku(void);
void DrawPukupuku(u32 a, Unk020e43a8 *pukupuku, u32 b, u16 alpha);
