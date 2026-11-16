#pragma once

#include "types.h"
#include "code_0201c528.h"

// Word at Unk020184e4_2c 0x0c and Unk020184e4_2c_00 0x04.
typedef struct Unk020184e4_2c_0c {
    /* 00 */ u32 field0_0 : 4;
    /* 00 */ u32 field0_4 : 4;
    /* 00 */ u32 field0_8 : 4;
    /* 00 */ u32 field0_12 : 2;
    /* 00 */ u32 field0_14 : 2;
    /* 00 */ u32 field0_16 : 1;
    /* 00 */ u32 field0_17 : 1;
    /* 00 */ u32 field0_18 : 8;
    /* 00 */ u32 field0_26 : 6;
} Unk020184e4_2c_0c;

// Header of an entry of the table at SPLManager 0x2c.
typedef struct Unk020184e4_2c_00 {
    /* 00 */ u8 field0[4];
    /* 04 */ Unk020184e4_2c_0c field4;
    /* 08 */ s32 field8;
    /* 0c */ s32 fieldC;
    /* 10 */ s32 field10;
    /* 14 */ u8 field14[8];
    /* 1c */ s32 field1C;
} Unk020184e4_2c_00;

// Entries of the table at SPLManager 0x2c (0x14 bytes each, count at 0x32).
typedef struct Unk020184e4_2c {
    /* 00 */ Unk020184e4_2c_00 *field0;
    /* 04 */ u32 field4;
    /* 08 */ u32 field8;
    /* 0c */ Unk020184e4_2c_0c fieldC;
    /* 10 */ u16 field10;
    /* 12 */ u16 field12;
} Unk020184e4_2c;

// First bytes of the data SPLManager_LoadResources reads.
typedef struct Unk02018a1c {
    /* 00 */ u8 field0[8];
    /* 08 */ u16 field8;
    /* 0a */ u16 fieldA;
} Unk02018a1c;

typedef struct SPLManager {
    /* 00 */ void *(*mAlloc)(u32 a);
    /* 04 */ Unk0201e494 field4[3];
    /* 28 */ Unk0201ca6c_20 *mResources;
    /* 2c */ Unk020184e4_2c *mTextures;
    /* 30 */ u16 mResCount;
    /* 32 */ u16 mTexCount;
    /* 34 */ s16 mMaxEmitters;
    /* 36 */ s16 mMaxParticles;
    /* 38 */ u32 mPolygonIDMin : 6;
    /* 38 */ u32 mPolygonIDMax : 6;
    /* 38 */ u32 mPolygonIDCurrent : 6;
    /* 38 */ u32 mPolygonIDFix : 6;
    /* 38 */ u32 mPolygonIDDrawOrder : 1;
    /* 38 */ u32 field38_25 : 7;
    /* 3c */ u32 mMiscPolygonAttr;
    /* 40 */ Unk0201ca6c *mRenderStateEmitter;
    /* 44 */ MtxFx43 *mRenderStateViewMatrix;
    /* 48 */ u16 mCurrentCycle;
} SPLManager;

// Entries of the two local call tables of SPLEmitter_Update.
typedef struct Unk020192e0_28 {
    /* 00 */ void (*field0)(Unk0201e3c8 *p, Unk0201ca6c_20 *q, s32 v);
    /* 04 */ u32 field4;
} Unk020192e0_28;

void SPLManager_DeleteEmitter(SPLManager *mgr, Unk0201ca6c *emtr);
Unk0201ca6c *SPLManager_CreateEmitterWithCallbackEx(SPLManager *mgr, s32 resourceId, Vec3 *pos, s32 param,
                                                    void (*initCallback)(Unk0201ca6c *emtr, s32 param));
Unk0201ca6c *SPLManager_CreateEmitter(SPLManager *mgr, s32 resourceId, Vec3 *pos);
void SPLManager_Draw(SPLManager *mgr, MtxFx43 *viewMatrix);
void SPLManager_Update(SPLManager *mgr);
s32 SPLManager_UploadPalettes(SPLManager *mgr);
s32 SPLManager_UploadTextures(SPLManager *mgr);
s32 SPLManager_UploadPalettesEx(SPLManager *mgr, u32 (*vramAlloc)(s32 size, s32 isSpecial));
s32 SPLManager_UploadTexturesEx(SPLManager *mgr, u32 (*vramAlloc)(s32 size, s32 isSpecial));
void SPLManager_LoadResources(SPLManager *mgr, Unk02018a1c *data);
SPLManager *SPLManager_New(void *(*alloc)(u32 size), u16 maxEmitters, u16 maxParticles, s32 fixPolyId, u16 minPolyId,
                           u16 maxPolyId);
u32 SPLUtil_AllocPaletteVRAM(s32 size, s32 is4Pltt);
u32 SPLUtil_AllocTextureVRAM(s32 size, s32 is4x4);
void SPLUtil_SetCylinderEmitterDir(Unk0201ca6c *emtr, Vec3 *p1, Vec3 *p2);
void SPLManager_DoDraw(SPLManager *mgr);
void SPLManager_DrawChildParticles(SPLManager *mgr);
void SPLManager_DrawParticles(SPLManager *mgr);
void SPLEmitter_Update(SPLManager *mgr, Unk0201ca6c *b);
void SPLEmitter_Init(Unk0201ca6c *emtr, Unk0201ca6c_20 *res, Vec3 *pos);
void SPLUtil_SetTexture_Stub(Unk020184e4_2c *tex);
void SPLUtil_SetTexture(Unk020184e4_2c *tex);
void SPLDraw_Child_DirectionalPolygon(SPLManager *mgr, Unk0201e3c8 *ptcl);
void SPLDraw_DirectionalPolygon(SPLManager *mgr, Unk0201e3c8 *ptcl);
void SPLDraw_Child_Polygon(SPLManager *mgr, Unk0201e3c8 *ptcl);
void SPLDraw_Polygon(SPLManager *mgr, Unk0201e3c8 *ptcl);
void SPLDraw_Child_DirectionalBillboard(SPLManager *mgr, Unk0201e3c8 *ptcl);
void SPLDraw_DirectionalBillboard(SPLManager *mgr, Unk0201e3c8 *ptcl);
void SPLDraw_Child_Billboard(SPLManager *mgr, Unk0201e3c8 *ptcl);
void SPLDraw_Billboard(SPLManager *mgr, Unk0201e3c8 *ptcl);
