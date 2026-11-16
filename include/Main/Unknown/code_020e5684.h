#pragma once

#include "types.h"

typedef struct Unk020e43a8 Unk020e43a8;

// Second argument of shand_init: a vector at 0x0c, halfwords from 0x28.
typedef struct Unk020e5684 {
    /* 00 */ u8 field0[0x0c];
    /* 0c */ Vec3 fieldC;
    /* 18 */ u8 field18[0x10];
    /* 28 */ s16 field28;
    /* 2a */ s16 field2A;
    /* 2c */ s16 field2C;
    /* 2e */ s16 field2E;
    /* 30 */ s16 field30;
} Unk020e5684;

void shand_loadModel(void);

typedef struct Unk020e43a8 Unk020e43a8;

// 0x28-byte object shand_setupLogicPart loads from shand_logicPartData.
typedef struct Unk020e59e4 {
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
} Unk020e59e4;

// 0x2c-byte object shand_setupRenderPart loads from shand_renderPartData.
typedef struct Unk020e5a40 {
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
} Unk020e5a40;

// 0x40-byte object shand_setupConfig loads from shand_colData.
typedef struct Unk020e5a9c {
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
} Unk020e5a9c;

void obpak_loadModel(void);

extern Unk020e59e4 *shand_sLogicPart;
extern Unk020e5a40 *shand_sRenderPart;
extern Unk020e59e4 *obpak_sLogicPart;
extern Unk020e5a40 *obpak_sRenderPart;
extern Unk020e59e4 *pend_sLogicPart;
extern Unk020e5a40 *pend_sRenderPart;

void shand_init(Unk020e43a8 *secondHand, Unk020e5684 *courseRow);
void shand_collide(Unk020e43a8 *secondHand, Vec3 *sphereCenter, s32 sphereRadius, Vec3 *overlapOffset);
void shand_update(u32 a, Unk020e43a8 *secondHand);
void shand_render(u32 a, Unk020e43a8 *secondHand, u32 b, u32 alpha);
Unk020e59e4 *shand_setupLogicPart(void);
Unk020e5a40 *shand_setupRenderPart(void);
Unk020e5a9c *shand_setupConfig(void);
void obpak_init(Unk020e43a8 *obPakkunSf);
