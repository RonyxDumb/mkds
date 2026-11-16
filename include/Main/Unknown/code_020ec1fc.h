#pragma once

#include "types.h"

typedef struct Unk020e43a8 Unk020e43a8;

// Initialiser stored into the 0x28-byte object wbox_setupLogicPart allocates.
typedef struct Unk021594e4 {
    /* 00 */ u32 field0;
    /* 04 */ u32 field4;
    /* 08 */ u32 field8;
    /* 0c */ u32 fieldC;
    /* 10 */ u32 field10;
    /* 14 */ u32 field14;
    /* 18 */ u32 field18;
    /* 1c */ u32 field1C;
    /* 20 */ u32 field20;
    /* 24 */ u32 field24;
} Unk021594e4;

extern Unk021594e4 *wbox_sLogicPart;

// Initialiser stored into the 0x2c-byte object wbox_setupRenderPart allocates.
typedef struct Woodbox1DrawList {
    /* 00 */ u32 field0;
    /* 04 */ u32 field4;
    /* 08 */ u32 field8;
    /* 0c */ u32 fieldC;
    /* 10 */ u32 field10;
    /* 14 */ u32 field14;
    /* 18 */ u32 field18;
    /* 1c */ u32 field1C;
    /* 20 */ u32 field20;
    /* 24 */ u32 field24;
    /* 28 */ u32 field28;
} Woodbox1DrawList;

extern Woodbox1DrawList *data_0217bbec;

// Initialiser stored into the 0x40-byte object wbox_setupCollision allocates.
typedef struct Unk02159538 {
    /* 00 */ u32 field0;
    /* 04 */ u32 field4;
    /* 08 */ u32 field8;
    /* 0c */ u32 fieldC;
    /* 10 */ u32 field10;
    /* 14 */ u32 field14;
    /* 18 */ u32 field18;
    /* 1c */ u32 field1C;
    /* 20 */ u32 field20;
    /* 24 */ u32 field24;
    /* 28 */ u32 field28;
    /* 2c */ u32 field2C;
    /* 30 */ u32 field30;
    /* 34 */ u32 field34;
    /* 38 */ u32 field38;
    /* 3c */ u32 field3C;
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
