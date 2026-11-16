#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject
#include "Main/Unknown/code_020de214.h"
#include "Main/Unknown/code_020e5d0c.h"
#include "Main/Unknown/code_020d849c.h"
#include "Main/Unknown/code_020e516c.h"

// Second argument of ibox_init: a Vec3 at 0x00 and halfwords at 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30 and 0x34.
typedef struct Unk020de6a8_1 {
    /* 00 */ Vec3 field0;
    /* 0c */ u8 fieldC[0x1a];
    /* 26 */ s16 field26;
    /* 28 */ s16 field28;
    /* 2a */ s16 field2A;
    /* 2c */ s16 field2C;
    /* 2e */ s16 field2E;
    /* 30 */ u16 field30;
    /* 32 */ u8 field32[2];
    /* 34 */ s16 field34;
} Unk020de6a8_1;

// Object of 0x108 or more bytes handled by ibox_init.
typedef struct ItemBox {
    /* 000 */ MapObject field0;
    /* 0a0 */ u16 mBoxRotationIndex;
    /* 0a2 */ u16 mQuestionRotationIndex;
    /* 0a4 */ u16 mFramesSinceHit;
    /* 0a6 */ u8 fieldA6[2];
    /* 0a8 */ s32 fieldA8;
    /* 0ac */ s32 fieldAC;
    /* 0b0 */ s16 fieldB0;
    /* 0b2 */ u8 fieldB2[2];
    /* 0b4 */ ShadowMatrix fieldB4;
    /* 0e8 */ s32 fieldE8;
    /* 0ec */ s32 fieldEC;
    /* 0f0 */ u16 mPolygonId;
    /* 0f2 */ u16 fieldF2;
    /* 0f4 */ u16 fieldF4;
    /* 0f6 */ u8 fieldF6[2];
    /* 0f8 */ s32 fieldF8;
    /* 0fc */ Vec3 *fieldFC;
    /* 100 */ UnkFunc *field100;
    /* 104 */ void *field104;
    /* 108 */ GroupFollowerWithSpeeds mFollower;
} ItemBox;

void ibox_loadModels(void);
void ibox_init(ItemBox *itemBox, Unk020de6a8_1 *row);
MapObjectKindData *epipe_setupConfig(void);
MapObjectDrawList *epipe_setupRenderPart(void);
MapObjectList *epipe_setupLogicPart(void);
void epipe_applyMaterial(void);
