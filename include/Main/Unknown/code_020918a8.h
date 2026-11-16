#pragma once

#include "types.h"
#include "Main/Unknown/code_020d22c0.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h"

// Object of 0xb0 bytes: the MapObject it starts with, then a halfword and three words.
typedef struct Unk020919e8 {
    /* 00 */ MapObject mUnk_00;
    /* a0 */ u16 mUnk_a0;
    /* a2 */ u8 mUnk_a2[2];
    /* a4 */ s32 mUnk_a4;
    /* a8 */ s32 mUnk_a8;
    /* ac */ s32 mUnk_ac;
} Unk020919e8;

void cow_setupRenderPart(void);
void cow_render(void *a, Unk020919e8 *b);
void cow_globalPreRender(void *a);
void cow_loadModel(void *a);
void kan64_setupLogicPart(void);
void kan64_setupRenderPart(void);
void kan64_update(void *a, Unk020919e8 *p); /* Unk020919e8 is shared with Cow and kind 0x1a0 */
s16 kan64_FX_CosIdx(s32 angle);
s32 kan64_FX_TRUNC_MUL(s32 a, s32 b);
s16 kan64_FX_SinIdx(s32 angle);
u32 kan64_mobj_getRandom32(RandomState64 *randomState64, u32 limit);
void kan64_globalInitLogic(MapObjectList *mapObjectList);
void kan64_render(void *a, Unk020919e8 *p);
void kan64_loadModel(void *a);
