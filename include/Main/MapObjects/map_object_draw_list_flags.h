#pragma once

#include "types.h"
#include "Main/MapObjects/attractor.h" // MapObjectList, MapObjectKindData

// A draw list of map objects: the shared list and the slot that holds it (SetDrawListSlot stores it).
typedef struct MapObjectDrawList {
    /* 00 */ MapObjectList mList;
    /* 28 */ u32 mUnk_28;
} MapObjectDrawList;

// The update list of the MkdEfBubble objects: the shared list and mAngleScale, the factor that turns the vertical step
// into mAngleZ.
typedef struct MkdEfBubbleUpdateList {
    /* 00 */ MapObjectList mList;
    /* 28 */ s32 mAngleScale;
} MkdEfBubbleUpdateList;

extern const u32 gMkdEfBubbleHitFlag;

extern const u16 gKuriboFlag;
extern const u16 gRotaryFlag;
