#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h" // Kart
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject

// Object of the list mobj_getLogicPartForObjectId(0x70): the shared MapObject part, then the words and the pointer
// sblln_spawn sets.
typedef struct ShineBalloonObject {
    /* 00 */ MapObject field0;
    /* a0 */ s32 fieldA0;
    /* a4 */ s32 fieldA4;
    /* a8 */ s32 mTimer;
    /* ac */ Kart *fieldAC;
    /* b0 */ s32 mState;
} ShineBalloonObject;

void *FindParkedMapObject(s32 a);
void mobj_createSubObjects(u32 a, s32 b, void *c);
void sblln_spawn(Kart *a);
void *sblln_setupLogicPart(void);
void *sblln_setupRenderPart(void);
