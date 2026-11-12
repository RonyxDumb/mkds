#pragma once

#include "types.h"
#include "Main/MapObjects/attractor.h" // MapObjectList, MapObjectKindData

extern Vec3 data_021581f8;
extern MapObjectList data_02158238;
extern struct DossunDrawList data_02158260;
extern MapObjectKindData data_0215828c;
// Object of 0x2c bytes made by CreateWanwanChainDrawList and the other factories that copy a template from 0x02158xxx.
typedef struct MapObjectDrawList {
    /* 00 */ MapObjectList mList;
    /* 28 */ u32 mUnk_28;
} MapObjectDrawList;

// Object of 0x2c bytes made by CreateMkdEfBubbleUpdateList; a word at 0x28.
typedef struct MkdEfBubbleUpdateList {
    /* 00 */ u32 mUnk_00[10];
    /* 28 */ s32 mAngleScale;
} MkdEfBubbleUpdateList;

extern MapObjectList data_021584d4;
extern MapObjectDrawList data_021584fc;
extern MapObjectKindData data_02158528;
extern u16 data_02158568;
extern u32 data_0215856c;
extern u16 data_021585a4;
extern MapObjectList data_021585a8;
extern MapObjectDrawList data_021585d0;
extern MapObjectDrawList data_021585fc;
extern MapObjectDrawList data_02158628;
extern MapObjectKindData data_02158654;
extern Vec3 data_02158694;
extern u16 data_02158740;
extern u32 data_02158778;
extern MkdEfBubbleUpdateList data_02158784;
extern MapObjectDrawList data_021587b0;
extern MapObjectKindData data_021587dc;
extern u16 data_0215881c;

// Objects whose layout isn't known yet.
extern u16 data_02158160;
extern u16 data_0215877c;
extern u16 data_02158780;
extern s32 data_02158908;
extern u16 data_02158c88;
extern u16 data_021588e8;
extern u16 data_021588ec;
extern Vec3 data_021588f0;
extern Vec3 data_021588fc;
extern const u16 data_02158b7c;
extern const u16 gRotaryFlag;
