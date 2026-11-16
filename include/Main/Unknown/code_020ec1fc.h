#pragma once

#include "types.h"

typedef struct Unk020e43a8 Unk020e43a8;

// Initialiser stored into the 0x28-byte object wbox_setupLogicPart allocates.
typedef struct Unk021594e4 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ u32 mUnk_18;
    /* 1c */ u32 mUnk_1c;
    /* 20 */ u32 mUnk_20;
    /* 24 */ u32 mUnk_24;
} Unk021594e4;

extern Unk021594e4 *wbox_sLogicPart;

// Initialiser stored into the 0x2c-byte object wbox_setupRenderPart allocates.
typedef struct Woodbox1DrawList {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ u32 mUnk_18;
    /* 1c */ u32 mUnk_1c;
    /* 20 */ u32 mUnk_20;
    /* 24 */ u32 mUnk_24;
    /* 28 */ u32 mUnk_28;
} Woodbox1DrawList;

extern Woodbox1DrawList *data_0217bbec;

// Initialiser stored into the 0x40-byte object wbox_setupCollision allocates.
typedef struct Unk02159538 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ u32 mUnk_18;
    /* 1c */ u32 mUnk_1c;
    /* 20 */ u32 mUnk_20;
    /* 24 */ u32 mUnk_24;
    /* 28 */ u32 mUnk_28;
    /* 2c */ u32 mUnk_2c;
    /* 30 */ u32 mUnk_30;
    /* 34 */ u32 mUnk_34;
    /* 38 */ u32 mUnk_38;
    /* 3c */ u32 mUnk_3c;
} Unk02159538;

extern const Unk021594e4 data_021594e4;
extern const Woodbox1DrawList data_0215950c;
extern const Unk02159538 wbox_sCollisionInfo;

void wbox_render(void *a, Unk020e43a8 *woodbox, void *c, u32 maxAlpha);
Unk021594e4 *wbox_setupLogicPart(void);
Woodbox1DrawList *wbox_setupRenderPart(void);
Unk02159538 *wbox_setupCollision(void);
BOOL rdmo_onItemCollide(Unk020e43a8 *mapObject, void *other, u8 *firstResponse);
BOOL rdmo_onDriverCollide(Unk020e43a8 *mapObject, void *other, u8 *firstResponse);
