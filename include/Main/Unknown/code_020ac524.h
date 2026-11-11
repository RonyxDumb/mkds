#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h" // Kart
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject

// Object of the list FindMapObjectKindUpdateList(0x70): the shared MapObject part, then the words and the pointer
// StartShineBalloon sets.
typedef struct ShineBalloonObject {
    /* 00 */ MapObject mMapObject;
    /* a0 */ s32 mUnk_a0;
    /* a4 */ s32 mUnk_a4;
    /* a8 */ s32 mTimer;
    /* ac */ Kart *mUnk_ac;
    /* b0 */ s32 mState;
} ShineBalloonObject;

void *FindParkedMapObject(s32 kind);
void CreateParkedMapObjects(u32 kind, s32 count, void *object);
void StartShineBalloon(Kart *kart);
void *CreateShineBalloonUpdateList(void);
void *CreateShineBalloonDrawList(void);
