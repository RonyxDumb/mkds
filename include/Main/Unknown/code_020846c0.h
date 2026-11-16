#pragma once

#include "types.h"
#include "code_02010804.h"
#include "code_02012b30.h" // NNSG3dResFileHeader, NNSG3dResMdl
#include "code_0212d214.h"

typedef struct MtxFx43 MtxFx43;

// A registered resource file and its texture; the entries form the list sModelResList (links at 0x00 and 0x04).
typedef struct ResFileEntry {
    /* 00 */ void *field0;
    /* 04 */ void *field4;
    /* 08 */ NNSG3dResFileHeader *mFile;
    /* 0c */ NNSG3dResTex *mTexture;
} ResFileEntry;

// 0x6c-byte model object: a render object up to 0x53, then mCullModesSwapped, mDrawKind and the file entry.
typedef struct Nsbmd {
    /* 00 */ u8 field0[4];
    /* 04 */ NNSG3dResMdl *mResMdl;
    /* 08 */ u8 field8[0x4c];
    /* 54 */ s32 mCullModesSwapped;
    /* 58 */ s32 mDrawKind;
    /* 5c */ ResFileEntry mResFileEntry;
} Nsbmd;

void rptc_init(void *heap);
void model_releaseAll(void);
void model_setCullMode(void *object, u32 cullMode);
void model_setPolyIdLightFlagsEmi(void *object, u32 polygonId, u32 light, u32 color);
void model_setEmi(void *object, u32 color);
void model_setLightEnableFlag(void *object, u32 light);
void model_setPolygonId(void *object, u32 polygonId);
void model_render(void *object);
void model_drawTransformed(void *object, MtxFx43 *matrix, u32 *scale);
void model_configShadowPass2(void *object, u8 alpha, u8 polygonId);
void model_configShadowPass1(void *object, u8 alpha);
NNSG3dResMdl *model_initFromNsbmdNsbtxMetaCopy(void *heap, Nsbmd *nsbmd, NNSG3dResFileHeader *modelFile,
                                           NNSG3dResFileHeader *textureFile);
NNSG3dResMdl *model_initFromNsbmdNoCullFix(Nsbmd *nsbmd, NNSG3dResFileHeader *file);
NNSG3dResMdl *model_initFromNsbmdNsbtx(Nsbmd *nsbmd, NNSG3dResFileHeader *modelFile, NNSG3dResFileHeader *textureFile);
NNSG3dResMdl *model_initFromNsbmd(void *object, NNSG3dResFileHeader *file);
void model_initFromResMdl(Nsbmd *nsbmd, NNSG3dResMdl *resMdl);
void model_setCullBack(Nsbmd *nsbmd);
void model_setCullFront(Nsbmd *nsbmd);
void initModel(Nsbmd *nsbmd, NNSG3dResMdl *resMdl, u32 allowCullSwap);
u32 loadTex(NNSG3dResTex *texture);
void model_resSetNsbmdNsbtx(ResFileEntry *entry, NNSG3dResFileHeader *modelFile, NNSG3dResFileHeader *textureFile);
