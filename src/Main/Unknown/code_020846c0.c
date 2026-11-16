#include "Main/Unknown/code_020846c0.h"
#include "Main/System/Heap.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_0205e090.h"
#include "code_020109ac.h"
#include "code_02010878.h"
#include "code_02010998.h"
#include "res_struct_accessor.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02155000.h"
#include "Main/Unknown/unk_02161000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0200fe74.h"
#include "code_020108bc.h"
#include "code_02010804.h"
#include "code_02010c84.h"
#include "code_020172d0.h"

// Appends the entry for file b, uploads the texture of file c, and binds the model set of b to it when there is one.
void model_resSetNsbmdNsbtx(ResFileEntry *entry, NNSG3dResFileHeader *modelFile, NNSG3dResFileHeader *textureFile) {
    NNSG3dResMdlSet *modelSet;
    NNSG3dResTex *texture;

    modelSet = NNS_G3dGetMdlSet(modelFile);
    texture = NNS_G3dGetTex(textureFile);
    entry->mTexture = NULL;
    entry->mFile = NULL;
    NNS_FndAppendListObject(&sModelResList, entry);
    entry->mFile = modelFile;
    if (texture == NULL) {
        return;
    }
    texture->mTexInfo.mFlag &= ~1;
    texture->mTex4x4Info.mFlag &= ~1;
    texture->mTexInfo.mVramKey = 0;
    texture->mTex4x4Info.mVramKey = 0;
    texture->mPlttInfo.mFlag &= ~1;
    texture->mPlttInfo.mVramKey = 0;
    loadTex(texture);
    entry->mTexture = texture;
    if (modelSet->mHeader.mSignature == 0x304c444d) {
        NNS_G3dBindMdlSet(modelSet, texture);
    }
}

// Gets VRAM for the texture, 4x4 texture and palette blocks and loads them; 0 if loaded already or a block fails.
u32 loadTex(NNSG3dResTex *texture) {
    u32 v1;
    u32 v0;
    u32 v2;
    u32 result = 1;
    u32 texOk = 1;
    u32 tex4x4Ok = 1;
    u32 plttOk = 1;

    if ((texture->mTexInfo.mFlag & 1) != 0 || (texture->mTex4x4Info.mFlag & 1) != 0 ||
        (texture->mPlttInfo.mFlag & 1) != 0) {
        result = 0;
    } else {
        v0 = NNS_G3dTexGetRequiredSize(texture);
        v1 = NNS_G3dTex4x4GetRequiredSize(texture);
        v2 = NNS_G3dPlttGetRequiredSize(texture);
        if (v0 != 0) {
            v0 = NNS_GfdDefaultFuncAllocTexVram(v0, 0, 0);
            if (v0 == 0) {
                texOk = 0;
            }
        } else {
            v0 = 0;
        }
        if (v1 != 0) {
            v1 = NNS_GfdDefaultFuncAllocTexVram(v1, 1, 0);
            if (v1 == 0) {
                tex4x4Ok = 0;
            }
        } else {
            v1 = 0;
        }
        if (v2 != 0) {
            v2 = NNS_GfdDefaultFuncAllocPlttVram(v2, texture->mTex4x4Info.mFlag & 0x8000, 0);
            if (v2 == 0) {
                plttOk = 0;
            }
        } else {
            v2 = 0;
        }
        if (texOk == 0 || tex4x4Ok == 0 || plttOk == 0) {
            NNS_GfdDefaultFuncFreePlttVram((void *) v2);
            NNS_GfdDefaultFuncFreeTexVram((void *) v1);
            NNS_GfdDefaultFuncFreeTexVram((void *) v0);
            return 0;
        }
        NNS_G3dTexSetTexKey(texture, v0, v1);
        NNS_G3dPlttSetPlttKey(texture, v2);
        NNS_G3dTexLoad(texture, 1);
        NNS_G3dPlttLoad(texture, 1);
    }
    return result;
}

// With c non-zero and scene number 2 it swaps cull modes 1 and 2 when byte 0x57 of the game record is set.
void initModel(Nsbmd *nsbmd, NNSG3dResMdl *resMdl, u32 allowCullSwap) {
    u32 i;
    NNSG3dResMdl *objResMdl;

    if (allowCullSwap != 0 && scproc_getCurrentScene() == 2) {
        nsbmd->mCullModesSwapped = gRaceMultiConfig->mMirrorMode;
    } else {
        nsbmd->mCullModesSwapped = 0;
    }
    if (resMdl->mInfo.mNumMat == 1 && resMdl->mInfo.mNumShp == 1) {
        nsbmd->mDrawKind = 1;
    } else {
        nsbmd->mDrawKind = 0;
    }
    NNS_G3dRenderObjInit((NNSG3dRenderObj *) nsbmd, resMdl);
    if (nsbmd->mCullModesSwapped != 0) {
        objResMdl = nsbmd->mResMdl;
        for (i = 0; i < objResMdl->mInfo.mNumMat; i++) {
            if (NNS_G3dMdlGetMdlCullMode(objResMdl, i) == 1) {
                NNS_G3dMdlSetMdlCullMode(objResMdl, i, 2);
            } else if (NNS_G3dMdlGetMdlCullMode(objResMdl, i) == 2) {
                NNS_G3dMdlSetMdlCullMode(objResMdl, i, 1);
            }
        }
    }
}

void model_setCullFront(Nsbmd *nsbmd) {
    u32 i;
    NNSG3dResMdl *resMdl;

    resMdl = nsbmd->mResMdl;
    for (i = 0; i < resMdl->mInfo.mNumMat; i++) {
        NNS_G3dMdlSetMdlCullMode(resMdl, i, 1);
    }
}

void model_setCullBack(Nsbmd *nsbmd) {
    u32 i;
    NNSG3dResMdl *resMdl;

    resMdl = nsbmd->mResMdl;
    for (i = 0; i < resMdl->mInfo.mNumMat; i++) {
        NNS_G3dMdlSetMdlCullMode(resMdl, i, 2);
    }
}

void model_initFromResMdl(Nsbmd *nsbmd, NNSG3dResMdl *resMdl) {
    initModel(nsbmd, resMdl, 1);
}

NNSG3dResMdl *model_initFromNsbmd(void *object, NNSG3dResFileHeader *file) {
    Nsbmd *nsbmd = object;

    NNSG3dResMdlSet *modelSet;
    NNSG3dResTex *texture;
    u8 *modelSetBytes;

    modelSet = NNS_G3dGetMdlSet(file);
    texture = NNS_G3dGetTex(file);
    nsbmd->mResFileEntry.mTexture = NULL;
    nsbmd->mResFileEntry.mFile = NULL;
    NNS_FndAppendListObject(&sModelResList, &nsbmd->mResFileEntry);
    nsbmd->mResFileEntry.mFile = file;
    if (texture != NULL) {
        texture->mTexInfo.mFlag &= ~1;
        texture->mTex4x4Info.mFlag &= ~1;
        texture->mTexInfo.mVramKey = 0;
        texture->mTex4x4Info.mVramKey = 0;
        texture->mPlttInfo.mFlag &= ~1;
        texture->mPlttInfo.mVramKey = 0;
        loadTex(texture);
        nsbmd->mResFileEntry.mTexture = texture;
        if (modelSet->mHeader.mSignature == 0x304c444d) {
            NNS_G3dBindMdlSet(modelSet, texture);
        }
    }
    modelSetBytes = (u8 *) NNS_G3dGetMdlSet(file);
    initModel(
        nsbmd, (NNSG3dResMdl *) (modelSetBytes + *(u32 *) (modelSetBytes + *(u16 *) (modelSetBytes + 14) + 12)), 1);
    return nsbmd->mResMdl;
}

NNSG3dResMdl *model_initFromNsbmdNsbtx(Nsbmd *nsbmd, NNSG3dResFileHeader *modelFile, NNSG3dResFileHeader *textureFile) {
    Nsbmd *o = nsbmd;

    NNSG3dResMdlSet *modelSet;
    NNSG3dResTex *texture;
    u8 *modelSetBytes;

    modelSet = NNS_G3dGetMdlSet(modelFile);
    texture = NNS_G3dGetTex(textureFile);
    o->mResFileEntry.mTexture = NULL;
    o->mResFileEntry.mFile = NULL;
    NNS_FndAppendListObject(&sModelResList, &o->mResFileEntry);
    o->mResFileEntry.mFile = modelFile;
    if (texture != NULL) {
        texture->mTexInfo.mFlag &= ~1;
        texture->mTex4x4Info.mFlag &= ~1;
        texture->mTexInfo.mVramKey = 0;
        texture->mTex4x4Info.mVramKey = 0;
        texture->mPlttInfo.mFlag &= ~1;
        texture->mPlttInfo.mVramKey = 0;
        loadTex(texture);
        o->mResFileEntry.mTexture = texture;
        if (modelSet->mHeader.mSignature == 0x304c444d) {
            NNS_G3dBindMdlSet(modelSet, texture);
        }
    }
    modelSetBytes = (u8 *) NNS_G3dGetMdlSet(modelFile);
    initModel(
        o, (NNSG3dResMdl *) (modelSetBytes + *(u32 *) (modelSetBytes + *(u16 *) (modelSetBytes + 14) + 12)), 1);
    return o->mResMdl;
}

NNSG3dResMdl *model_initFromNsbmdNoCullFix(Nsbmd *nsbmd, NNSG3dResFileHeader *file) {
    NNSG3dResMdlSet *modelSet;
    NNSG3dResTex *texture;
    u8 *modelSetBytes;

    modelSet = NNS_G3dGetMdlSet(file);
    texture = NNS_G3dGetTex(file);
    nsbmd->mResFileEntry.mTexture = NULL;
    nsbmd->mResFileEntry.mFile = NULL;
    NNS_FndAppendListObject(&sModelResList, &nsbmd->mResFileEntry);
    nsbmd->mResFileEntry.mFile = file;
    if (texture != NULL) {
        texture->mTexInfo.mFlag &= ~1;
        texture->mTex4x4Info.mFlag &= ~1;
        texture->mTexInfo.mVramKey = 0;
        texture->mTex4x4Info.mVramKey = 0;
        texture->mPlttInfo.mFlag &= ~1;
        texture->mPlttInfo.mVramKey = 0;
        loadTex(texture);
        nsbmd->mResFileEntry.mTexture = texture;
        if (modelSet->mHeader.mSignature == 0x304c444d) {
            NNS_G3dBindMdlSet(modelSet, texture);
        }
    }
    modelSetBytes = (u8 *) NNS_G3dGetMdlSet(file);
    initModel(
        nsbmd, (NNSG3dResMdl *) (modelSetBytes + *(u32 *) (modelSetBytes + *(u16 *) (modelSetBytes + 14) + 12)), 0);
    return nsbmd->mResMdl;
}

// Fills the object from model file c and texture file d, then keeps a heap copy of the texture block's header part.
NNSG3dResMdl *model_initFromNsbmdNsbtxMetaCopy(void *heap, Nsbmd *nsbmd, NNSG3dResFileHeader *modelFile,
                                           NNSG3dResFileHeader *textureFile) {
    NNSG3dResMdlSet *modelSet;
    NNSG3dResTex *texture;
    u8 *modelSetBytes;
    NNSG3dResTex *loadedTexture;
    u32 headerSize;
    ResFileEntry *entry;
    NNSG3dResMdl *resMdl;

    modelSet = NNS_G3dGetMdlSet(modelFile);
    texture = NNS_G3dGetTex(textureFile);
    nsbmd->mResFileEntry.mTexture = NULL;
    nsbmd->mResFileEntry.mFile = NULL;
    NNS_FndAppendListObject(&sModelResList, &nsbmd->mResFileEntry);
    nsbmd->mResFileEntry.mFile = modelFile;
    if (texture != NULL) {
        texture->mTexInfo.mFlag &= ~1;
        texture->mTex4x4Info.mFlag &= ~1;
        texture->mTexInfo.mVramKey = 0;
        texture->mTex4x4Info.mVramKey = 0;
        texture->mPlttInfo.mFlag &= ~1;
        texture->mPlttInfo.mVramKey = 0;
        loadTex(texture);
        nsbmd->mResFileEntry.mTexture = texture;
        if (modelSet->mHeader.mSignature == 0x304c444d) {
            NNS_G3dBindMdlSet(modelSet, texture);
        }
    }
    modelSetBytes = (u8 *) NNS_G3dGetMdlSet(modelFile);
    initModel(
        nsbmd, (NNSG3dResMdl *) (modelSetBytes + *(u32 *) (modelSetBytes + *(u16 *) (modelSetBytes + 14) + 12)), 1);
    entry = &nsbmd->mResFileEntry;
    loadedTexture = entry->mTexture;
    resMdl = nsbmd->mResMdl;
    if (loadedTexture != NULL) {
        headerSize = loadedTexture->mTexInfo.mOfsTex;
        entry->mTexture = heap_alloc(heap, headerSize);
        MI_CpuCopy8(loadedTexture, entry->mTexture, headerSize);
    }
    return resMdl;
}

void model_configShadowPass1(void *object, u8 alpha) {
    Nsbmd *nsbmd = object;

    NNSG3dResMdl *resMdl = nsbmd->mResMdl;
    u32 cullMode;

    if (nsbmd->mCullModesSwapped != 0) {
        cullMode = 2;
    } else {
        cullMode = 1;
    }
    NNS_G3dMdlSetMdlPolygonID(resMdl, 0, 0);
    NNS_G3dMdlSetMdlCullMode(resMdl, 0, cullMode);
    NNS_G3dMdlSetMdlAlpha(resMdl, 0, alpha);
}

void model_configShadowPass2(void *object, u8 alpha, u8 polygonId) {
    Nsbmd *nsbmd = object;

    NNSG3dResMdl *resMdl = nsbmd->mResMdl;
    u32 cullMode;

    if (nsbmd->mCullModesSwapped != 0) {
        cullMode = 1;
    } else {
        cullMode = 2;
    }
    NNS_G3dMdlSetMdlPolygonID(resMdl, 0, polygonId);
    NNS_G3dMdlSetMdlCullMode(resMdl, 0, cullMode);
    NNS_G3dMdlSetMdlAlpha(resMdl, 0, alpha);
}

// Draws with matrix b; when c is not NULL its three words (a scale, 0x1000 = 1.0) are sent first.
void model_drawTransformed(void *object, MtxFx43 *matrix, u32 *scale) {
    s32 commandParam = 30;
    u32 scaleCopy[3];

    NNS_G3dGeBufferOP_N(20, &commandParam, 1);
    NNS_G3dGeBufferOP_N(25, matrix, 12);
    if (scale != NULL) {
        u32 z = scale[2];
        u32 y = scale[1];
        u32 x = scale[0];
        scaleCopy[0] = x;
        scaleCopy[1] = y;
        scaleCopy[2] = z;
        NNS_G3dGeBufferOP_N(27, &scaleCopy, 3);
    }
    gModelRenderFuncs[((Nsbmd *) object)->mDrawKind](object);
}

void model_render(void *object) {
    Nsbmd *nsbmd = object;

    gModelRenderFuncs[nsbmd->mDrawKind](nsbmd);
}

void model_setPolygonId(void *object, u32 polygonId) {
    Nsbmd *nsbmd = object;

    NNS_G3dMdlSetMdlPolygonIDAll(nsbmd->mResMdl, polygonId);
}

void model_setLightEnableFlag(void *object, u32 light) {
    Nsbmd *nsbmd = object;

    NNS_G3dMdlSetMdlLightEnableFlagAll(nsbmd->mResMdl, light);
}

void model_setEmi(void *object, u32 color) {
    Nsbmd *nsbmd = object;

    NNS_G3dMdlSetMdlEmiAll(nsbmd->mResMdl, color);
}

void model_setPolyIdLightFlagsEmi(void *object, u32 polygonId, u32 light, u32 color) {
    Nsbmd *nsbmd = object;

    NNS_G3dMdlSetMdlPolygonIDAll(nsbmd->mResMdl, polygonId);
    NNS_G3dMdlSetMdlLightEnableFlagAll(nsbmd->mResMdl, light);
    NNS_G3dMdlSetMdlEmiAll(nsbmd->mResMdl, color);
}

void model_setCullMode(void *object, u32 cullMode) {
    Nsbmd *nsbmd = object;

    NNS_G3dMdlSetMdlCullModeAll(nsbmd->mResMdl, cullMode);
}

// Frees the texture and palette memory of the file of every entry of sModelResList; the entries stay in the list.
void model_releaseAll(void) {
    ResFileEntry *entry;

    for (entry = NNS_FndGetNextListObject(&sModelResList, NULL); entry != NULL;
         entry = NNS_FndGetNextListObject(&sModelResList, entry)) {
        if (entry->mFile != NULL) {
            NNS_G3dResDefaultRelease(entry->mFile);
        }
    }
}

void rptc_init(void *heap) {
    u32 kartCount;
    u16 i;
    u16 j;

    kartCount = gRaceMultiConfig->mKartCount;
    rptc_sDriverEffectVariantTable = heap_alloc(heap, kartCount * 2);
    rptc_sRainbowEffectEmitters = heap_alloc(heap, kartCount * 12);
    rptc_sDriverSlipstreamBeginEmitters = heap_alloc(heap, kartCount * 4);
    rptc_sDriverSlipstreamEmitters = heap_alloc(heap, kartCount * 4);
    for (i = 0; i < kartCount; i++) {
        for (j = 0; j < 3; j++) {
            rptc_sRainbowEffectEmitters[i].mEffects[j] = NULL;
        }
        rptc_sDriverSlipstreamBeginEmitters[i] = NULL;
        rptc_sDriverSlipstreamEmitters[i] = NULL;
        if (i == gRaceMultiConfig->mEntryIndex) {
            rptc_sDriverEffectVariantTable[i] = 0;
        } else {
            rptc_sDriverEffectVariantTable[i] = 1;
        }
    }
    rptc_sEffectColor = 0x7fff;
    switch (gRaceMultiConfig->mCourseId) {
        case COURSE_ID_MANSION:
        case COURSE_ID_KOOPA:
            rptc_sEffectColor = 0x1667;
            break;
        case COURSE_ID_TOWN:
            rptc_sEffectColor = 0x2ff;
            break;
        case COURSE_ID_GARDEN:
            rptc_sEffectColor = 0x3e67;
            break;
    }
    gOtherKartFullPairCount = (gRaceMultiConfig->mKartCount - 1) / 2;
    gOtherKartOddCount = (gRaceMultiConfig->mKartCount - 1) % 2;
    data_02165948 = 0x1000;
    switch (gRaceMultiConfig->mEngineIndex) {
        case 0:
            data_02165948 = 0xb33;
            break;
        case 1:
            data_02165948 = 0xd9a;
            break;
    }
}
