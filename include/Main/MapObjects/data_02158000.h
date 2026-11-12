#pragma once

#include "types.h"
#include "Main/MapObjects/attractor.h" // MapObjectList, MapObjectKindData

// Object of 0x2c bytes made by CreateWanwanChainDrawList and the other factories that copy a template from 0x02158xxx.
typedef struct MapObjectDrawList {
    /* 00 */ MapObjectList mList;
    /* 28 */ u32 mUnk_28;
} MapObjectDrawList;

// Object of 0x2c bytes made by CreateMkdEfBubbleUpdateList; a word at 0x28.
typedef struct MkdEfBubbleUpdateList {
    /* 00 */ MapObjectList mList;
    /* 28 */ s32 mAngleScale;
} MkdEfBubbleUpdateList;

extern u16 gItemBoxTriangleFlag2Flag;
extern u32 gItemBoxInitDistanceFlag;
extern const u32 gMkdEfBubbleHitFlag;
extern u16 gKoopaBlockFlag;

// Objects whose layout isn't known yet.
extern const u16 gKuriboFlag;
extern const u16 data_02158b7c;
extern const u16 gRotaryFlag;
