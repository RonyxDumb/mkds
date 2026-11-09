#pragma once

#include "types.h"

#include "Main/Unknown/code_020e6fd4.h" // MapObject

typedef struct MapObjectList MapObjectList;

// Object of 0xb0 bytes: the MapObject it starts with, then a halfword and three words.
typedef struct Unk02092b5c {
    /* 00 */ MapObject mUnk_00;
    /* a0 */ u16 mUnk_a0;
    /* a2 */ u8 mUnk_a2[2];
    /* a4 */ s32 mTimer;
    /* a8 */ s32 mUnk_a8;
    /* ac */ s32 mState;
} Unk02092b5c;

void func_02092b3c(void);
void func_02092b5c(void *a, Unk02092b5c *p);
s16 func_02093080(s32 angle);
s32 func_020930a0(s32 a, s32 b);
s16 func_020930b0(s32 angle);
void func_020930c8(MapObjectList *mapObjectList);
void func_02093190(u32 arg0);
