#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject

// Object with the MapObject base: two halfwords at 0xa0 and 0xa2, then two words (rstar_update, rstar_render,
// chnd_update, chnd_globalInitLogic).
typedef struct Unk0209f1c8 {
    /* 00 */ MapObject mUnk_00;
    /* a0 */ u16 mUnk_a0;
    /* a2 */ u16 mUnk_a2;
    /* a4 */ s32 mUnk_a4;
    /* a8 */ s32 mUnk_a8;
} Unk0209f1c8;

// Array of object pointers: pointer to the array and the number of entries (chnd_globalInitLogic).
typedef struct Unk0209f514 {
    /* 00 */ Unk0209f1c8 **mUnk_00;
    /* 04 */ u16 mUnk_04;
} Unk0209f514;

extern char aRainstar_nsbmd[];
extern char aRainstar_nsbta[];

void *rstar_setupLogicPart(void);
void *rstar_setupRenderPart(void);
void rstar_update(void *a, Unk0209f1c8 *b); /* skipped for objects with mFlags & 4 (parked pool objects) */
void rstar_render(void *a, Unk0209f1c8 *b);
void rstar_loadModel(void *a);
void *chnd_setupLogicPart(void);
void *chnd_setupRenderPart(void);
void chnd_update(void *a, Unk0209f1c8 *b); /* skipped for objects with mFlags & 4 (parked pool objects) */
void chnd_globalInitLogic(Unk0209f514 *a);
