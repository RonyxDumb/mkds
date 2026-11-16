#pragma once

#include "types.h"
#include "Main/Unknown/code_021052fc.h"
#include "Main/Item/ItemInUse.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h"
#include "Main/Unknown/code_020f36d8.h"

// 0x2bc bytes.
typedef struct MapObjects {
    /* 000 */ MapObject **mMapObjects;
    // Pinned at 0xff when the 0x100-pointer array is full.
    /* 004 */ vu16 mMapObjectCount;
    /* 006 */ u8 field6[2];
    /* 008 */ MapObjectList *mDrawLists[24];
    /* 068 */ MapObjectList *field68[24];
    /* 0c8 */ MapObjectList *fieldC8[24];
    /* 128 */ u16 mDrawListCount;
    /* 12a */ u16 field12A;
    /* 12c */ u16 field12C;
    /* 12e */ u8 field12E[2];
    /* 130 */ BOOL field130;
    /* 134 */ MapObjectList *mUpdateLists[16];
    /* 174 */ u16 mUpdateListCount;
    /* 176 */ u8 field176[2];
    /* 178 */ BOOL field178;
    /* 17c */ s32 mHasKoopaBlock;
    /* 180 */ s32 field180;
    /* 184 */ s32 field184;
    /* 188 */ s32 field188;
    /* 18c */ ItemObject field18C;
    /* 2b8 */ s32 mRunUpdateLists;
} MapObjects;

// Declared here until the code that defines them is decompiled.
#include "Main/Unknown/code_020d2090.h"
#include "Main/Unknown/code_020d275c.h"
#include "Main/Unknown/code_020d26e0.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d26f8.h"
#include "Main/Unknown/code_020d278c.h"
#include "Main/Unknown/code_020d2c2c.h"
#include "Main/Unknown/code_020d24d8.h"
