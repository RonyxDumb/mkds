#pragma once

#include "types.h"
#include "Main/MapObjects/attractor.h" // MapObjectList, MapObjectKindData

// A draw list of map objects: the shared list and one more word.
typedef struct MapObjectDrawList {
    /* 00 */ MapObjectList mList;
    /* 28 */ u32 mUnk_28;
} MapObjectDrawList;

// The update list of the Koopa block bubbles: the shared list and the angle scale.
typedef struct MkdEfBubbleUpdateList {
    /* 00 */ MapObjectList mList;
    /* 28 */ s32 mAngleScale;
} MkdEfBubbleUpdateList;

extern const u32 gMkdEfBubbleHitFlag;

// Objects whose layout isn't known yet.
extern const u16 gKuriboFlag;
extern const u16 gRotaryFlag;
