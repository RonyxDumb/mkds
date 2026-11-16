#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject

// Object of pict_update: after the shared part, a halfword at 0xa0, the phase at 0xa4, a counter at 0xa8 and the
// state at 0xac.
typedef struct Picture {
    /* 00 */ MapObject field0;
    /* a0 */ u16 mNsbcaFrameIndex;
    /* a2 */ u8 fieldA2[2];
    /* a4 */ s32 mPictureIndex;
    /* a8 */ s32 mState1Timer;
    /* ac */ s32 mState;
} Picture;

/* kind 0xd objects are MapObject-sized (0xa0) */
void pud_render(void *a, MapObject *b);
void pud_globalPreRender(void *a);
void pud_loadModel(void *a);
void *pict_setupLogicPart(void);
void *pict_setupRenderPart(void);
void pict_update(void *a, Picture *b); /* skipped for objects with mFlags & 4 (parked pool objects) */
void pict_render(void *a, Picture *b);
void pict_loadModels(void *a);
