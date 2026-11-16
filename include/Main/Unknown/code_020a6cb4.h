#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject

// Object of the list mobj_getLogicPartForObjectId(0x6b): the shared MapObject part, then three words.
typedef struct Unk020a6cb4 {
    /* 00 */ MapObject field0;
    /* a0 */ BOOL mHasShine;
    /* a4 */ BOOL fieldA4;
    /* a8 */ s32 mShineStartFrames;
} Unk020a6cb4;

void sub_20A6CB4(s32 a);
void *shinc_setupLogicPart(void);
s32 shinc_setupConfig(void);
void shinc_update(MapObjectList *a, Unk020a6cb4 *b);
void shinc_globalLogicInit(MapObjectList *a);
BOOL shinc_spawnShine(MapObjectList *a);
