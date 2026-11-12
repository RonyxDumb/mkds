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

extern u16 gItemBoxTriangleFlag2Flag;
extern u32 gItemBoxInitDistanceFlag;
extern Vec3 gItemBoxDefaultScale;
extern u16 gMkdEfBubbleInitFlag;
extern const u32 gMkdEfBubbleHitFlag;
extern MkdEfBubbleUpdateList gMkdEfBubbleUpdateListData;
extern MapObjectDrawList gMkdEfBubbleDrawListData;
extern MapObjectKindData gMkdEfBubbleKindData;
extern u16 gKoopaBlockFlag;

// Objects whose layout isn't known yet.
extern const u16 gKuriboFlag;
extern u16 gMkdEfBubbleState1Flag;
extern u16 gMkdEfBubbleState1SecondFlag;
extern s32 gGroupFollowerSpeed;
extern u16 data_02158c88;
extern u16 data_021588e8;
extern u16 data_021588ec;
extern Vec3 data_021588f0;
extern Vec3 data_021588fc;
extern const u16 data_02158b7c;
extern const u16 gRotaryFlag;
