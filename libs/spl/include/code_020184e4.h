#pragma once

#include "types.h"
#include "code_0201c528.h"
#include "code_0201c4e8.h"

// An emitter's mPlaneY with no override of the plane height of the behavior.
#define SPL_UNSET_PLANE 0x80000000

// Mask of one 5-bit channel of a 15-bit color, and the largest value of the 5-bit animation alpha.
#define SPL_COLOR_CHANNEL_MASK 0x1f
#define SPL_ALPHA_MAX 0x1f

// Time scale of a particle: this value divided by the length in frames, so that the time reaches it at the end.
#define SPL_TIME_SCALE_END 0xffff

// Indexed by the rotate kind of an emitter's header.
extern void (*gSplRotateFunctions[2])(s32 sinValue, s32 cosValue, MtxFx43 *mtx);
// Indexed by the plane kind of an emitter's header.
extern Vec3s16 gSplEmitterUpAxis;
extern void (*gSplPlaneDrawFunctions[2])(u32 texCoordU, u32 texCoordV, s32 centerA, s32 centerB);

// ParticleTextureParam.mFormat values the code tells apart: the four-color palette format loads its palette at half the
// address step, and the block-compressed format is allocated in the special texture memory.
enum {
    PARTICLE_TEXTURE_FORMAT_FOUR_COLOR = 2,
    PARTICLE_TEXTURE_FORMAT_COMPRESSED = 5
};

// Word at ParticleTexture 0x0c and ParticleTextureHeader 0x04.
typedef struct ParticleTextureParam {
    /* 00 */ u32 mFormat : 4;
    /* 00 */ u32 mSizeS : 4;
    /* 00 */ u32 mSizeT : 4;
    /* 00 */ u32 mWrapS : 2;
    /* 00 */ u32 mWrapT : 2;
    /* 00 */ u32 mColor0Transparent : 1;
    /* 00 */ u32 mSharesTexture : 1;
    /* 00 */ u32 mSharedTextureIndex : 8;
    /* 00 */ u32 mUnk_00_26 : 6;
} ParticleTextureParam;

// Header of an entry of the table at SPLManager 0x2c.
typedef struct ParticleTextureHeader {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ ParticleTextureParam mImageParam;
    /* 08 */ s32 mTextureSize;
    /* 0c */ s32 mPaletteOffset;
    /* 10 */ s32 mPaletteSize;
    /* 14 */ u8 mUnk_14[8];
    /* 1c */ s32 mBlockSize;
    /* 20 */ u8 mTextureData[1];
} ParticleTextureHeader;

// Entries of the table at SPLManager 0x2c (0x14 bytes each, count at 0x32).
typedef struct ParticleTexture {
    /* 00 */ ParticleTextureHeader *mHeader;
    /* 04 */ u32 mTextureVramAddr;
    /* 08 */ u32 mPaletteVramAddr;
    /* 0c */ ParticleTextureParam mParam;
    /* 10 */ u16 mWidth;
    /* 12 */ u16 mHeight;
} ParticleTexture;

// First bytes of the data SPLManager_LoadResources reads.
typedef struct ParticleFileHeader {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ u16 mResCount;
    /* 0a */ u16 mTexCount;
} ParticleFileHeader;

typedef struct SPLManager {
    /* 00 */ void *(*mAlloc)(u32 size);
    /* 04 */ ParticleList mLists[3];
    /* 28 */ ParticleResource *mResources;
    /* 2c */ ParticleTexture *mTextures;
    /* 30 */ u16 mResCount;
    /* 32 */ u16 mTexCount;
    /* 34 */ s16 mMaxEmitters;
    /* 36 */ s16 mMaxParticles;
    /* 38 */ u32 mPolygonIDMin : 6;
    /* 38 */ u32 mPolygonIDMax : 6;
    /* 38 */ u32 mPolygonIDCurrent : 6;
    /* 38 */ u32 mPolygonIDFix : 6;
    /* 38 */ u32 mPolygonIDDrawOrder : 1;
    /* 38 */ u32 mUnk_38_25 : 7;
    /* 3c */ u32 mMiscPolygonAttr;
    /* 40 */ ParticleEmitter *mRenderStateEmitter;
    /* 44 */ MtxFx43 *mRenderStateViewMatrix;
    /* 48 */ u16 mCurrentCycle;
} SPLManager;

// Entries of the two local call tables of SPLEmitter_Update.
typedef struct ParticleAnimEntry {
    /* 00 */ void (*mAnimate)(ParticleInstance *particle, ParticleResource *resource, s32 lifeRate);
    /* 04 */ u32 mTimeIndex;
} ParticleAnimEntry;

void SPLManager_DeleteEmitter(SPLManager *mgr, ParticleEmitter *emtr);
ParticleEmitter *SPLManager_CreateEmitterWithCallbackEx(SPLManager *mgr, s32 resourceId, Vec3 *pos, s32 param,
                                                   void (*initCallback)(ParticleEmitter *emtr, s32 param));
ParticleEmitter *SPLManager_CreateEmitter(SPLManager *mgr, s32 resourceId, Vec3 *pos);
void SPLManager_Draw(SPLManager *mgr, MtxFx43 *viewMatrix);
void SPLManager_Update(SPLManager *mgr);
s32 SPLManager_UploadPalettes(SPLManager *mgr);
s32 SPLManager_UploadTextures(SPLManager *mgr);
s32 SPLManager_UploadPalettesEx(SPLManager *mgr, u32 (*vramAlloc)(s32 size, s32 isSpecial));
s32 SPLManager_UploadTexturesEx(SPLManager *mgr, u32 (*vramAlloc)(s32 size, s32 isSpecial));
void SPLManager_LoadResources(SPLManager *mgr, ParticleFileHeader *data);
SPLManager *SPLManager_New(void *(*alloc)(u32 size), u16 maxEmitters, u16 maxParticles, s32 fixPolyId, u16 minPolyId,
                           u16 maxPolyId);
u32 SPLUtil_AllocPaletteVRAM(s32 size, s32 is4Pltt);
u32 SPLUtil_AllocTextureVRAM(s32 size, s32 is4x4);
void SPLUtil_SetCylinderEmitterDir(ParticleEmitter *emtr, Vec3 *pointA, Vec3 *pointB);
void SPLManager_DoDraw(SPLManager *mgr);
void SPLManager_DrawChildParticles(SPLManager *mgr);
void SPLManager_DrawParticles(SPLManager *mgr);
void SPLEmitter_Update(SPLManager *mgr, ParticleEmitter *emtr);
void SPLEmitter_Init(ParticleEmitter *emtr, ParticleResource *res, Vec3 *pos);
void SPLUtil_SetTexture_Stub(ParticleTexture *tex);
void SPLUtil_SetTexture(ParticleTexture *tex);
void SPLDraw_Child_DirectionalPolygon(SPLManager *mgr, ParticleInstance *ptcl);
void SPLDraw_DirectionalPolygon(SPLManager *mgr, ParticleInstance *ptcl);
void SPLDraw_Child_Polygon(SPLManager *mgr, ParticleInstance *ptcl);
void SPLDraw_Polygon(SPLManager *mgr, ParticleInstance *ptcl);
void SPLDraw_Child_DirectionalBillboard(SPLManager *mgr, ParticleInstance *ptcl);
void SPLDraw_DirectionalBillboard(SPLManager *mgr, ParticleInstance *ptcl);
void SPLDraw_Child_Billboard(SPLManager *mgr, ParticleInstance *ptcl);
void SPLDraw_Billboard(SPLManager *mgr, ParticleInstance *ptcl);
