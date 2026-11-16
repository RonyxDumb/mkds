#pragma once

#include "types.h"
#include "code_02013bdc.h"
#include "Main/Unknown/code_020e43a8.h"
#include "Main/Unknown/code_020e516c.h"
#include "Main/Unknown/code_020e5684.h"

// Second argument of pend_init, read at 0x00..0x2b.
typedef struct Unk020e5e24_2 {
    /* 00 */ Vec3 field0;
    /* 0c */ Vec3 fieldC;
    /* 18 */ u8 field18[0x08];
    /* 20 */ s32 field20;
    /* 24 */ u8 field24[0x04];
    /* 28 */ s16 field28;
    /* 2a */ s16 field2A;
} Unk020e5e24_2;

// Object behind PendulumObject.field98: a word at 0x10.
typedef struct Unk020e5e24_98 {
    /* 00 */ u8 field0[0x10];
    /* 10 */ s32 field10;
} Unk020e5e24_98;

// Object handled by pend_init, pend_collide, pend_update and
// pend_render; at least 0x110 bytes.
typedef struct PendulumObject {
    /* 00 */ u8 field0[0x04];
    /* 04 */ Vec3 field4;
    /* 10 */ Vec3 field10;
    /* 1c */ Vec3 field1C;
    /* 28 */ Unk020e43a8_28 field28;
    /* 4c */ Vec3 field4C;
    /* 58 */ u8 field58[0x04];
    /* 5c */ s32 field5C;
    /* 60 */ u8 field60[0x10];
    /* 70 */ s32 field70;
    /* 74 */ u8 field74[0x04];
    /* 78 */ u32 field78;
    /* 7c */ u8 field7C[0x1c];
    /* 98 */ Unk020e5e24_98 *field98;
    /* 9c */ u8 field9C[0x04];
    /* a0 */ u32 fieldA0[4];
    /* b0 */ Vec3 fieldB0;
    /* bc */ Vec3 fieldBC;
    /* c8 */ Unk020e43a8_28 fieldC8;
    /* ec */ Vec3 fieldEC;
    /* f8 */ s32 fieldF8;
    /* fc */ u16 fieldFC;
    /* fe */ u16 fieldFE;
    /* 100 */ u16 field100;
    /* 102 */ u8 field102[0x02];
    /* 104 */ s32 field104;
    /* 108 */ s32 field108;
    /* 10c */ BOOL field10C;
} PendulumObject;

// Allocated by bbm_createFromNsbmd and it_loadItemBillboardModel, filled in by bbm_initFromModel, 0x2c bytes.
typedef struct NsbmdModel {
    /* 00 */ u8 *field0;
    /* 04 */ u32 field4;
    /* 08 */ u32 field8;
    /* 0c */ s32 fieldC;
    /* 10 */ s32 field10;
    /* 14 */ u32 field14;
    /* 18 */ u16 mFrameIndex;
    /* 1a */ u16 mFrameCount;
    /* 1c */ u32 *field1C;
    /* 20 */ u32 *field20;
    /* 24 */ void *field24;
    /* 28 */ void *field28;
} NsbmdModel;

extern NsbmdModel jg_sCloudModel;

extern NsbmdModel jg_sMainModel;

// Second argument of bbm_initFromModel, allocated as 0x38 bytes by bbm_initFromNsbmd.
typedef struct Unk020e6514 {
    /* 000 */ u8 field0[0x0c];
    /* 00c */ u32 fieldC;
    /* 010 */ u8 field10[0x0a];
    /* 01a */ u16 field1A;
    /* 01c */ NNSG3dAnmObj **field1C;
    /* 020 */ u8 field20[0x18];
} Unk020e6514;

// Work area of bbm_initFromModel on the stack: two words, then the object
// NNSi_G3dAnmCalcNsBtp fills in.
typedef struct Unk020e6514_8 {
    /* 00 */ u32 field0;
    /* 04 */ u32 field4;
    /* 08 */ NNSG3dMatAnmResult field8;
} Unk020e6514_8;

void obpak_globalPreRender(void);
Unk020e59e4 *obpak_setupLogicPart(void);
Unk020e5a40 *obpak_setupRenderPart(void);
Unk020e5a9c *obpak_setupConfig(void);
void pend_init(PendulumObject *pendulum, Unk020e5e24_2 *courseRow);
void pend_loadModels(void);
BOOL pend_collide(PendulumObject *pendulum, Vec3 *sphereCenter, s32 sphereRadius, Vec3 *out);
void pend_update(u32 param_1, PendulumObject *pendulum);
void pend_render(u32 param_1, PendulumObject *pendulum, u32 param_3, u32 alpha);
Unk020e59e4 *pend_setupLogicPart(void);
Unk020e5a40 *pend_setupRenderPart(void);
Unk020e5a9c *pend_setupConfig(void);
void bbm_createFromNsbmd(NsbmdModel **recordSlot, void *nsbmdFile, void *nsbtpFile, u32 param_4);
void bbm_initFromNsbmd(NsbmdModel *record, void *nsbmdFile, void *nsbtpFile, s32 c);
void bbm_initFromModel(Unk020e52bc *model, Unk020e6514 *animation, NsbmdModel *record);
