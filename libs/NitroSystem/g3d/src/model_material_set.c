#include "model_material_set.h"
#include "texture_resource_type.h"
#include "model_draw_state.h"
#include "model_texture_bind.h"
#include "texture_vram_load.h"
#include "geometry_engine_setup.h"
#include "ITCM/model_draw_and_irq_handler.h"
#include "render_object_resources.h"
#include "texture_pltt_size_key_release.h"
#include "texture_key_set.h"
#include "texture_required_size.h"
#include "model_set_resource_lookup.h"
#include "Main/Graphics/animation_function_pointers.h"
#include "registers.h"
#include "matrix_4x4_basic.h"
#include "frame_texture_vram_alloc.h"

u32 gPrjMapTexImageParamCommand[2] = {0x2a, 0};
u32 gEnvMapTexImageParamCommand[2] = {0x2a, 0};
void (*NNS_G3dFuncSbcMatTable[4])(NNSG3dRS *, u32, void *, u32) = {
    (void (*)(NNSG3dRS *, u32, void *, u32)) NNSi_G3dFuncSbc_MAT_InternalDefault, NULL, NULL, NULL};
void (*NNS_G3dFuncSbcShpTable[4])(NNSG3dRS *, u32, void *, u32) = {
    (void (*)(NNSG3dRS *, u32, void *, u32)) NNSi_G3dFuncSbc_SHP_InternalDefault, NULL, NULL, NULL};
s32 gPrjMapTextureMtx[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x10000, 0, 0, 0, 0, 0x10000};

// Returns the texture block of a model or texture file, or NULL when the file has none.
NNSG3dResTex *Nsbtx_GetTEX0Block(NNSG3dResFileHeader *file) {
    u32 *blocks;

    blocks = OFFSET_PTR(u32, file, file->mHeaderSize);
    if (file->mDataBlocks == 1) {
        if (file->mSigVal == FILE_SIGNATURE_TEXTURE) {
            return OFFSET_PTR(NNSG3dResTex, file, blocks[0]);
        }
        return 0;
    }
    return OFFSET_PTR(NNSG3dResTex, file, blocks[1]);
}

// Sets the diffuse color of one material.
void ModelBlock_SomeTexPltFn_4(NNSG3dResMdl *mdl, u32 matId, u32 color) {
    NNSG3dResMat *mat;
    NNSG3dResDictEntryHeader *entries;
    NNSG3dResMatData *data;

    mat = OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat);
    entries = OFFSET_PTR(NNSG3dResDictEntryHeader, &mat->mDict, mat->mDict.mOfsEntry);
    data = OFFSET_PTR(NNSG3dResMatData, mat, *(u32 *) (entries->mData + entries->mSizeUnit * matId));
    data->mDiffAmb = (data->mDiffAmb & -0x8000) | color;
}

// Sets the ambient color of one material.
void ModelBlock_SomeTexPltFn_5(NNSG3dResMdl *mdl, u32 matId, u32 color) {
    NNSG3dResMat *mat;
    NNSG3dResDictEntryHeader *entries;
    NNSG3dResMatData *data;

    mat = OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat);
    entries = OFFSET_PTR(NNSG3dResDictEntryHeader, &mat->mDict, mat->mDict.mOfsEntry);
    data = OFFSET_PTR(NNSG3dResMatData, mat, *(u32 *) (entries->mData + entries->mSizeUnit * matId));
    data->mDiffAmb = (data->mDiffAmb & 0x8000ffff) | (color << 16);
}

// Sets the specular color of one material.
void ModelBlock_SomeTexPltFn_6(NNSG3dResMdl *mdl, u32 matId, u32 color) {
    NNSG3dResMat *mat;
    NNSG3dResDictEntryHeader *entries;
    NNSG3dResMatData *data;

    mat = OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat);
    entries = OFFSET_PTR(NNSG3dResDictEntryHeader, &mat->mDict, mat->mDict.mOfsEntry);
    data = OFFSET_PTR(NNSG3dResMatData, mat, *(u32 *) (entries->mData + entries->mSizeUnit * matId));
    data->mSpecEmi = (data->mSpecEmi & -0x8000) | color;
}

// Sets the emission color of one material.
void ModelBlock_SomeTexPltFn_7(NNSG3dResMdl *mdl, u32 matId, u32 color) {
    NNSG3dResMat *mat;
    NNSG3dResDictEntryHeader *entries;
    NNSG3dResMatData *data;

    mat = OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat);
    entries = OFFSET_PTR(NNSG3dResDictEntryHeader, &mat->mDict, mat->mDict.mOfsEntry);
    data = OFFSET_PTR(NNSG3dResMatData, mat, *(u32 *) (entries->mData + entries->mSizeUnit * matId));
    data->mSpecEmi = (data->mSpecEmi & 0x8000ffff) | (color << 16);
}

// Sets the light enable mask of one material.
void NNS_G3dMdlSetMdlLightEnableFlag(NNSG3dResMdl *mdl, u32 matId, u32 light) {
    NNSG3dResMat *mat;
    NNSG3dResDictEntryHeader *entries;
    NNSG3dResMatData *data;

    mat = OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat);
    entries = OFFSET_PTR(NNSG3dResDictEntryHeader, &mat->mDict, mat->mDict.mOfsEntry);
    data = OFFSET_PTR(NNSG3dResMatData, mat, *(u32 *) (entries->mData + entries->mSizeUnit * matId));
    data->mPolyAttr = (data->mPolyAttr & ~0xf) | light;
}

// Sets the polygon mode of one material.
void ModelBlock_SomeTexPltFn_8(NNSG3dResMdl *mdl, u32 matId, u32 polyMode) {
    NNSG3dResMat *mat;
    NNSG3dResDictEntryHeader *entries;
    NNSG3dResMatData *data;

    mat = OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat);
    entries = OFFSET_PTR(NNSG3dResDictEntryHeader, &mat->mDict, mat->mDict.mOfsEntry);
    data = OFFSET_PTR(NNSG3dResMatData, mat, *(u32 *) (entries->mData + entries->mSizeUnit * matId));
    data->mPolyAttr = (data->mPolyAttr & ~0x30) | (polyMode << 4);
}

// Sets the cull mode of one material.
void ModelBlock_SomeTexPltFn_1(NNSG3dResMdl *mdl, u32 matId, u32 cullMode) {
    NNSG3dResMat *mat;
    NNSG3dResDictEntryHeader *entries;
    NNSG3dResMatData *data;

    mat = OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat);
    entries = OFFSET_PTR(NNSG3dResDictEntryHeader, &mat->mDict, mat->mDict.mOfsEntry);
    data = OFFSET_PTR(NNSG3dResMatData, mat, *(u32 *) (entries->mData + entries->mSizeUnit * matId));
    data->mPolyAttr = (data->mPolyAttr & ~0xc0) | (cullMode << 6);
}

// Sets the polygon ID of one material.
void ModelBlock_SomeTexPltFn_3(NNSG3dResMdl *mdl, u32 matId, u32 polygonId) {
    NNSG3dResMat *mat;
    NNSG3dResDictEntryHeader *entries;
    NNSG3dResMatData *data;

    mat = OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat);
    entries = OFFSET_PTR(NNSG3dResDictEntryHeader, &mat->mDict, mat->mDict.mOfsEntry);
    data = OFFSET_PTR(NNSG3dResMatData, mat, *(u32 *) (entries->mData + entries->mSizeUnit * matId));
    data->mPolyAttr = (data->mPolyAttr & ~0x3f000000) | (polygonId << 24);
}

// Sets the alpha of one material.
void NNS_G3dMdlSetMdlAlpha(NNSG3dResMdl *mdl, u32 matId, u32 alpha) {
    NNSG3dResMat *mat;
    NNSG3dResDictEntryHeader *entries;
    NNSG3dResMatData *data;

    mat = OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat);
    entries = OFFSET_PTR(NNSG3dResDictEntryHeader, &mat->mDict, mat->mDict.mOfsEntry);
    data = OFFSET_PTR(NNSG3dResMatData, mat, *(u32 *) (entries->mData + entries->mSizeUnit * matId));
    data->mPolyAttr = (data->mPolyAttr & ~0x1f0000) | (alpha << 16);
}

// Turns fog on or off for one material.
void NNS_G3dMdlSetMdlFogEnableFlag(NNSG3dResMdl *mdl, u32 matId, s32 flag) {
    NNSG3dResMat *mat;
    NNSG3dResDictEntryHeader *entries;
    NNSG3dResMatData *data;

    mat = OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat);
    entries = OFFSET_PTR(NNSG3dResDictEntryHeader, &mat->mDict, mat->mDict.mOfsEntry);
    data = OFFSET_PTR(NNSG3dResMatData, mat, *(u32 *) (entries->mData + entries->mSizeUnit * matId));
    if (flag != 0) {
        data->mPolyAttr |= G3D_POLY_ATTR_FOG;
    } else {
        data->mPolyAttr &= ~G3D_POLY_ATTR_FOG;
    }
}

// Turns the depth update of translucent polygons on or off for one material.
void ModelBlock_SomeTexPltFn(NNSG3dResMdl *mdl, u32 matId, s32 flag) {
    NNSG3dResMat *mat;
    NNSG3dResDictEntryHeader *entries;
    NNSG3dResMatData *data;

    mat = OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat);
    entries = OFFSET_PTR(NNSG3dResDictEntryHeader, &mat->mDict, mat->mDict.mOfsEntry);
    data = OFFSET_PTR(NNSG3dResMatData, mat, *(u32 *) (entries->mData + entries->mSizeUnit * matId));
    if (flag != 0) {
        data->mPolyAttr |= G3D_POLY_ATTR_XL_DEPTH_UPDATE;
    } else {
        data->mPolyAttr &= ~G3D_POLY_ATTR_XL_DEPTH_UPDATE;
    }
}

// Returns the cull mode of one material.
u32 ModelBlock_SomeTexPltFn_0(NNSG3dResMdl *mdl, u32 matId) {
    NNSG3dResMat *mat;
    NNSG3dResDictEntryHeader *entries;
    NNSG3dResMatData *data;

    mat = OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat);
    entries = OFFSET_PTR(NNSG3dResDictEntryHeader, &mat->mDict, mat->mDict.mOfsEntry);
    data = OFFSET_PTR(NNSG3dResMatData, mat, *(u32 *) (entries->mData + entries->mSizeUnit * matId));
    return (data->mPolyAttr & G3D_POLY_ATTR_CULL_MODE_MASK) >> 6;
}

// Returns the polygon ID of one material.
u32 NNS_G3dMdlGetMdlPolygonID(NNSG3dResMdl *mdl, u32 matId) {
    NNSG3dResMat *mat;
    NNSG3dResDictEntryHeader *entries;
    NNSG3dResMatData *data;

    mat = OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat);
    entries = OFFSET_PTR(NNSG3dResDictEntryHeader, &mat->mDict, mat->mDict.mOfsEntry);
    data = OFFSET_PTR(NNSG3dResMatData, mat, *(u32 *) (entries->mData + entries->mSizeUnit * matId));
    return (data->mPolyAttr & G3D_POLY_ATTR_POLYGON_ID_MASK) >> 24;
}

// Returns the alpha of one material.
u32 NNS_G3dMdlGetMdlAlpha(NNSG3dResMdl *mdl, u32 matId) {
    NNSG3dResMat *mat;
    NNSG3dResDictEntryHeader *entries;
    NNSG3dResMatData *data;

    mat = OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat);
    entries = OFFSET_PTR(NNSG3dResDictEntryHeader, &mat->mDict, mat->mDict.mOfsEntry);
    data = OFFSET_PTR(NNSG3dResMatData, mat, *(u32 *) (entries->mData + entries->mSizeUnit * matId));
    return (data->mPolyAttr & G3D_POLY_ATTR_ALPHA_MASK) >> 16;
}

// Returns whether fog is on for one material.
u32 NNS_G3dMdlGetMdlFogEnableFlag(NNSG3dResMdl *mdl, u32 matId) {
    NNSG3dResMat *mat;
    NNSG3dResDictEntryHeader *entries;
    NNSG3dResMatData *data;

    mat = OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat);
    entries = OFFSET_PTR(NNSG3dResDictEntryHeader, &mat->mDict, mat->mDict.mOfsEntry);
    data = OFFSET_PTR(NNSG3dResMatData, mat, *(u32 *) (entries->mData + entries->mSizeUnit * matId));
    return data->mPolyAttr & G3D_POLY_ATTR_FOG;
}

// Sets the diffuse color of every material.
void ModelBlock_SomeMatFn_0(NNSG3dResMdl *mdl, u32 color) {
    u32 matIndex;

    for (matIndex = 0; matIndex < mdl->mInfo.mNumMat; matIndex++) {
        ModelBlock_SomeTexPltFn_4(mdl, matIndex, color);
    }
}

// Sets the ambient color of every material.
void ModelBlock_SomeMatFn_1(NNSG3dResMdl *mdl, u32 color) {
    u32 matIndex;

    for (matIndex = 0; matIndex < mdl->mInfo.mNumMat; matIndex++) {
        ModelBlock_SomeTexPltFn_5(mdl, matIndex, color);
    }
}

// Sets the specular color of every material.
void ModelBlock_SomeMatFn_2(NNSG3dResMdl *mdl, u32 color) {
    u32 matIndex;

    for (matIndex = 0; matIndex < mdl->mInfo.mNumMat; matIndex++) {
        ModelBlock_SomeTexPltFn_6(mdl, matIndex, color);
    }
}

// Sets the emission color of every material.
void ModelBlock_SomeMatFn_3(NNSG3dResMdl *mdl, u32 color) {
    u32 matIndex;

    for (matIndex = 0; matIndex < mdl->mInfo.mNumMat; matIndex++) {
        ModelBlock_SomeTexPltFn_7(mdl, matIndex, color);
    }
}

// Sets the light enable mask of every material.
void NNS_G3dMdlSetMdlLightEnableFlagAll(NNSG3dResMdl *mdl, u32 light) {
    u32 matIndex;

    for (matIndex = 0; matIndex < mdl->mInfo.mNumMat; matIndex++) {
        NNS_G3dMdlSetMdlLightEnableFlag(mdl, matIndex, light);
    }
}

// Sets the polygon mode of every material.
void ModelBlock_SomeMatFn_4(NNSG3dResMdl *mdl, u32 polyMode) {
    u32 matIndex;

    for (matIndex = 0; matIndex < mdl->mInfo.mNumMat; matIndex++) {
        ModelBlock_SomeTexPltFn_8(mdl, matIndex, polyMode);
    }
}

// Sets the cull mode of every material.
void ModelBlock_SomeTexPltFn_2(NNSG3dResMdl *mdl, u32 cullMode) {
    u32 matIndex;

    for (matIndex = 0; matIndex < mdl->mInfo.mNumMat; matIndex++) {
        ModelBlock_SomeTexPltFn_1(mdl, matIndex, cullMode);
    }
}

// Sets the polygon ID of every material.
void ModelBlock_SomeFn(NNSG3dResMdl *mdl, u32 polygonId) {
    u32 matIndex;

    for (matIndex = 0; matIndex < mdl->mInfo.mNumMat; matIndex++) {
        ModelBlock_SomeTexPltFn_3(mdl, matIndex, polygonId);
    }
}

// Sets the alpha of every material.
void NNS_G3dMdlSetMdlAlphaAll(NNSG3dResMdl *mdl, u32 alpha) {
    u32 matIndex;

    for (matIndex = 0; matIndex < mdl->mInfo.mNumMat; matIndex++) {
        NNS_G3dMdlSetMdlAlpha(mdl, matIndex, alpha);
    }
}

// Sets the fog flag of every material.
void NNS_G3dMdlSetMdlFogEnableFlagAll(NNSG3dResMdl *mdl, u32 flag) {
    u32 matIndex;

    for (matIndex = 0; matIndex < mdl->mInfo.mNumMat; matIndex++) {
        NNS_G3dMdlSetMdlFogEnableFlag(mdl, matIndex, flag);
    }
}

// Sets the translucent depth update flag of every material.
void ModelBlock_SetSomethingToAllMaterials(NNSG3dResMdl *mdl, u32 flag) {
    u32 matIndex;

    for (matIndex = 0; matIndex < mdl->mInfo.mNumMat; matIndex++) {
        ModelBlock_SomeTexPltFn(mdl, matIndex, flag);
    }
}

// Reads the current position and vector matrices back from the geometry engine; either pointer may be NULL.
void NNS_G3dGetCurrentMtx(MtxFx43 *pos, void *vec) {
    MtxFx44 clipMtx;

    NNS_G3dGeFlushBuffer();
    reg_G3_MTX_MODE = 0;
    reg_G3_MTX_PUSH = 0;
    reg_G3_MTX_IDENTITY = 0;
    if (pos != 0) {
        while (G3X_GetClipMtx(&clipMtx) != 0) {
        }
        MTX_Copy44To43_(&clipMtx, pos);
    }
    if (vec != 0) {
        while (G3X_GetVectorMtx(vec) != 0) {
        }
    }
    reg_G3_MTX_POP = 1;
    reg_G3_MTX_MODE = 2;
}

// Initializes the geometry engine and the global state.
void NNS_G3dInit(void) {
    G3X_Initialize();
    NNS_G3dGlbInit();
    reg_G3X_GXSTAT = (reg_G3X_GXSTAT & ~0xc0000000) | 0x80000000;
}

// Allocates texture and palette memory for a model or texture file, loads them and binds them to the models. The key
// variables first hold the required size.
s32 NNS_G3dResDefaultSetup(NNSG3dResFileHeader *file) {
    s32 texOk;
    NNSG3dResTex *tex;
    u32 texKey;
    u32 tex4x4Key;
    u32 plttKey;
    s32 tex4x4Ok;
    s32 plttOk;
    NNSG3dResMdlSet *modelSet;

    switch (file->mSigVal) {
        case FILE_SIGNATURE_MODEL:
        case FILE_SIGNATURE_TEXTURE:
            texOk = 1;
            tex4x4Ok = 1;
            plttOk = 1;
            tex = Nsbtx_GetTEX0Block(file);
            if (tex != 0) {
                texKey = Tex0Block_GetTextureDataSize(tex);
                tex4x4Key = Tex0Block_GetCompressedTextureDataSize(tex);
                plttKey = Tex0Block_GetPaletteDataSize(tex);
                if (texKey != 0) {
                    texKey = NNS_GfdDefaultFuncAllocTexVram(texKey, 0, 0);
                    if (texKey == 0) {
                        texOk = 0;
                    }
                } else {
                    texKey = 0;
                }
                if (tex4x4Key != 0) {
                    tex4x4Key = NNS_GfdDefaultFuncAllocTexVram(tex4x4Key, 1, 0);
                    if (tex4x4Key == 0) {
                        tex4x4Ok = 0;
                    }
                } else {
                    tex4x4Key = 0;
                }
                if (plttKey != 0) {
                    plttKey = NNS_GfdDefaultFuncAllocPlttVram(plttKey,
                                                              tex->mTex4x4Info.mFlag & G3D_TEX_4X4_FLAG_PLTT_4COLOR, 0);
                    if (plttKey == 0) {
                        plttOk = 0;
                    }
                } else {
                    plttKey = 0;
                }
                if (texOk == 0 || tex4x4Ok == 0 || plttOk == 0) {
                    NNS_GfdDefaultFuncFreePlttVram(plttKey);
                    NNS_GfdDefaultFuncFreeTexVram(tex4x4Key);
                    NNS_GfdDefaultFuncFreeTexVram(texKey);
                    return 0;
                }
                Tex0Block_SetTexturesVramKeys(tex, texKey, tex4x4Key);
                Tex0Block_SetPaletteVramKey(tex, plttKey);
                Tex0Block_MaybeCopyTexturesToMem(tex, 1);
                Tex0Block_MaybeCopyPaletteToMem(tex, 1);
            }
            if (file->mSigVal == FILE_SIGNATURE_MODEL) {
                modelSet = Nsbmd_GetMDL0Block(file);
                if (tex != 0) {
                    NNS_G3dBindMdlSet(modelSet, tex);
                }
            }
            return 1;
        case FILE_SIGNATURE_VISIBILITY_ANIM:
        case FILE_SIGNATURE_MATERIAL_COLOR_ANIM:
        case FILE_SIGNATURE_JOINT_ANIM:
        case FILE_SIGNATURE_TEXTURE_SRT_ANIM:
        case FILE_SIGNATURE_TEXTURE_PATTERN_ANIM:
            return 1;
        default:
            return 0;
    }
}

// Frees the texture and palette memory of a model or texture file and releases the models bound to it.
void MaybeDisposeCommonHeaderFileData(NNSG3dResFileHeader *file) {
    NNSG3dResMdlSet *modelSet;
    NNSG3dResTex *tex;
    NNSG3dTexKey textureKey;
    NNSG3dTexKey tex4x4Key;
    u32 paletteKey;

    switch (file->mSigVal) {
        case FILE_SIGNATURE_VISIBILITY_ANIM:
        case FILE_SIGNATURE_MATERIAL_COLOR_ANIM:
        case FILE_SIGNATURE_JOINT_ANIM:
        case FILE_SIGNATURE_TEXTURE_SRT_ANIM:
        case FILE_SIGNATURE_TEXTURE_PATTERN_ANIM:
            return;
        case FILE_SIGNATURE_MODEL:
            modelSet = Nsbmd_GetMDL0Block(file);
            if (Nsbtx_GetTEX0Block(file) != 0) {
                NNS_G3dReleaseMdlSet(modelSet);
            }
            break;
        case FILE_SIGNATURE_TEXTURE:
            break;
        default:
            return;
    }
    tex = Nsbtx_GetTEX0Block(file);
    if (tex == 0) {
        return;
    }
    paletteKey = NNS_G3dPlttReleasePlttKey(tex);
    Tex0_CleanGetKeys(tex, &textureKey, &tex4x4Key);
    if (paletteKey != 0) {
        NNS_GfdDefaultFuncFreePlttVram(paletteKey);
    }
    if (tex4x4Key != 0) {
        NNS_GfdDefaultFuncFreeTexVram(tex4x4Key);
    }
    if (textureKey != 0) {
        NNS_GfdDefaultFuncFreeTexVram(textureKey);
    }
}
