#include "Main/Graphics/nsbmd_render_obj.h"
#include "Main/System/heap.h"
#include "ITCM/model_draw_and_irq_handler.h"
#include "Main/Scene/run_scenes.h"
#include "texture_required_size.h"
#include "texture_pltt_size_key_release.h"
#include "texture_key_set.h"
#include "model_set_resource_lookup.h"
#include "Main/Kart/kart_palette_stem_tables.h"
#include "Main/Graphics/animation_function_pointers.h"
#include "Main/Kart/kart_effect_param_tables.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"
#include "Main/Kart/kart_name_tags.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/System/backup_net_camera_work.h"
#include "model_texture_bind.h"
#include "texture_vram_load.h"
#include "texture_resource_type.h"
#include "model_draw_state.h"
#include "linked_list_ops.h"
#include "Main/Kart/kart_effects.h"
#include "Main/Graphics/nsbmd_draw.h"
#include "Main/Graphics/res_file_entries_reset.h"
#include "frame_texture_vram_alloc.h"

const Vec3 gKartEffectVec3UnitY = {0, 0x1000, 0};
const Vec3 gKartEffectVec3Zero = {0, 0, 0};

// Appends the entry for file b, uploads the texture of file c, and binds the model set of b to it when there is one.
void AddResFileEntry(ResFileEntry *entry, NNSG3dResFileHeader *modelFile, NNSG3dResFileHeader *textureFile) {
    NNSG3dResMdlSet *modelSet;
    NNSG3dResTex *texture;

    modelSet = NNS_G3dGetMdlSet(modelFile);
    texture = NNS_G3dGetTex(textureFile);
    entry->mTexture = NULL;
    entry->mFile = NULL;
    NNS_FndAppendListObject(&gResFileEntries, entry);
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
    UploadResTexture(texture);
    entry->mTexture = texture;
    if (modelSet->mHeader.mSignature == RES_BLOCK_SIGNATURE_MODEL_SET) {
        NNS_G3dBindMdlSet(modelSet, texture);
    }
}

// Gets VRAM for the texture, 4x4 texture and palette blocks and loads them; 0 if loaded already or a block fails.
u32 UploadResTexture(NNSG3dResTex *texture) {
    u32 tex4x4Value;
    u32 texValue;
    u32 plttValue;
    u32 result = 1;
    u32 texOk = 1;
    u32 tex4x4Ok = 1;
    u32 plttOk = 1;

    if ((texture->mTexInfo.mFlag & 1) != 0 || (texture->mTex4x4Info.mFlag & 1) != 0 ||
        (texture->mPlttInfo.mFlag & 1) != 0) {
        result = 0;
    } else {
        texValue = NNS_G3dTexGetRequiredSize(texture);
        tex4x4Value = NNS_G3dTex4x4GetRequiredSize(texture);
        plttValue = NNS_G3dPlttGetRequiredSize(texture);
        if (texValue != 0) {
            texValue = NNS_GfdDefaultFuncAllocTexVram(texValue, 0, 0);
            if (texValue == 0) {
                texOk = 0;
            }
        } else {
            texValue = 0;
        }
        if (tex4x4Value != 0) {
            tex4x4Value = NNS_GfdDefaultFuncAllocTexVram(tex4x4Value, 1, 0);
            if (tex4x4Value == 0) {
                tex4x4Ok = 0;
            }
        } else {
            tex4x4Value = 0;
        }
        if (plttValue != 0) {
            plttValue =
                NNS_GfdDefaultFuncAllocPlttVram(plttValue, texture->mTex4x4Info.mFlag & TEXTURE_PALETTE_FEW_COLORS, 0);
            if (plttValue == 0) {
                plttOk = 0;
            }
        } else {
            plttValue = 0;
        }
        if (texOk == 0 || tex4x4Ok == 0 || plttOk == 0) {
            NNS_GfdDefaultFuncFreePlttVram(plttValue);
            NNS_GfdDefaultFuncFreeTexVram(tex4x4Value);
            NNS_GfdDefaultFuncFreeTexVram(texValue);
            return 0;
        }
        NNS_G3dTexSetTexKey(texture, texValue, tex4x4Value);
        NNS_G3dPlttSetPlttKey(texture, plttValue);
        NNS_G3dTexLoad(texture, 1);
        NNS_G3dPlttLoad(texture, 1);
    }
    return result;
}

// With c non-zero and scene number 2 it swaps cull modes 1 and 2 when byte 0x57 of the game record is set.
void InitNsbmdRenderObj(Nsbmd *nsbmd, NNSG3dResMdl *resMdl, u32 allowCullSwap) {
    u32 materialIndex;
    NNSG3dResMdl *objResMdl;

    if (allowCullSwap != 0 && GetCurrentSceneNumber() == 2) {
        nsbmd->mCullModesSwapped = gRaceSetup->mMirrorMode;
    } else {
        nsbmd->mCullModesSwapped = 0;
    }
    if (resMdl->mInfo.mNumMat == 1 && resMdl->mInfo.mNumShp == 1) {
        nsbmd->mDrawKind = 1;
    } else {
        nsbmd->mDrawKind = 0;
    }
    NNS_G3dRenderObjInit(&nsbmd->mRenderObj, resMdl);
    if (nsbmd->mCullModesSwapped != 0) {
        objResMdl = nsbmd->mResMdl;
        for (materialIndex = 0; materialIndex < objResMdl->mInfo.mNumMat; materialIndex++) {
            if (NNS_G3dMdlGetMdlCullMode(objResMdl, materialIndex) == 1) {
                NNS_G3dMdlSetMdlCullMode(objResMdl, materialIndex, 2);
            } else if (NNS_G3dMdlGetMdlCullMode(objResMdl, materialIndex) == 2) {
                NNS_G3dMdlSetMdlCullMode(objResMdl, materialIndex, 1);
            }
        }
    }
}

void SetNsbmdCullModeMirrored(Nsbmd *nsbmd) {
    u32 materialIndex;
    NNSG3dResMdl *resMdl;

    resMdl = nsbmd->mResMdl;
    for (materialIndex = 0; materialIndex < resMdl->mInfo.mNumMat; materialIndex++) {
        NNS_G3dMdlSetMdlCullMode(resMdl, materialIndex, 1);
    }
}

void SetNsbmdCullModeUnmirrored(Nsbmd *nsbmd) {
    u32 materialIndex;
    NNSG3dResMdl *resMdl;

    resMdl = nsbmd->mResMdl;
    for (materialIndex = 0; materialIndex < resMdl->mInfo.mNumMat; materialIndex++) {
        NNS_G3dMdlSetMdlCullMode(resMdl, materialIndex, 2);
    }
}

void InitNsbmdRenderObjWrapper(Nsbmd *nsbmd, NNSG3dResMdl *resMdl) {
    InitNsbmdRenderObj(nsbmd, resMdl, 1);
}

NNSG3dResMdl *InitNsbmd(Nsbmd *nsbmd, NNSG3dResFileHeader *file) {

    NNSG3dResMdlSet *modelSet;
    NNSG3dResTex *texture;
    NNSG3dResDictEntryHeader *entries;

    modelSet = NNS_G3dGetMdlSet(file);
    texture = NNS_G3dGetTex(file);
    nsbmd->mResFileEntry.mTexture = NULL;
    nsbmd->mResFileEntry.mFile = NULL;
    NNS_FndAppendListObject(&gResFileEntries, &nsbmd->mResFileEntry);
    nsbmd->mResFileEntry.mFile = file;
    if (texture != NULL) {
        texture->mTexInfo.mFlag &= ~1;
        texture->mTex4x4Info.mFlag &= ~1;
        texture->mTexInfo.mVramKey = 0;
        texture->mTex4x4Info.mVramKey = 0;
        texture->mPlttInfo.mFlag &= ~1;
        texture->mPlttInfo.mVramKey = 0;
        UploadResTexture(texture);
        nsbmd->mResFileEntry.mTexture = texture;
        if (modelSet->mHeader.mSignature == RES_BLOCK_SIGNATURE_MODEL_SET) {
            NNS_G3dBindMdlSet(modelSet, texture);
        }
    }
    modelSet = NNS_G3dGetMdlSet(file);
    entries = OFFSET_PTR(NNSG3dResDictEntryHeader, &modelSet->mDict, modelSet->mDict.mOfsEntry);
    InitNsbmdRenderObj(nsbmd, OFFSET_PTR(NNSG3dResMdl, modelSet, *DICT_ENTRY(u32, entries, 0)), 1);
    return nsbmd->mResMdl;
}

NNSG3dResMdl *InitNsbmdWithTextureFile(Nsbmd *nsbmd, NNSG3dResFileHeader *modelFile, NNSG3dResFileHeader *textureFile) {
    Nsbmd *nsbmdAlias = nsbmd;

    NNSG3dResMdlSet *modelSet;
    NNSG3dResTex *texture;
    NNSG3dResDictEntryHeader *entries;

    modelSet = NNS_G3dGetMdlSet(modelFile);
    texture = NNS_G3dGetTex(textureFile);
    nsbmdAlias->mResFileEntry.mTexture = NULL;
    nsbmdAlias->mResFileEntry.mFile = NULL;
    NNS_FndAppendListObject(&gResFileEntries, &nsbmdAlias->mResFileEntry);
    nsbmdAlias->mResFileEntry.mFile = modelFile;
    if (texture != NULL) {
        texture->mTexInfo.mFlag &= ~1;
        texture->mTex4x4Info.mFlag &= ~1;
        texture->mTexInfo.mVramKey = 0;
        texture->mTex4x4Info.mVramKey = 0;
        texture->mPlttInfo.mFlag &= ~1;
        texture->mPlttInfo.mVramKey = 0;
        UploadResTexture(texture);
        nsbmdAlias->mResFileEntry.mTexture = texture;
        if (modelSet->mHeader.mSignature == RES_BLOCK_SIGNATURE_MODEL_SET) {
            NNS_G3dBindMdlSet(modelSet, texture);
        }
    }
    modelSet = NNS_G3dGetMdlSet(modelFile);
    entries = OFFSET_PTR(NNSG3dResDictEntryHeader, &modelSet->mDict, modelSet->mDict.mOfsEntry);
    InitNsbmdRenderObj(nsbmdAlias, OFFSET_PTR(NNSG3dResMdl, modelSet, *DICT_ENTRY(u32, entries, 0)), 1);
    return nsbmdAlias->mResMdl;
}

NNSG3dResMdl *InitNsbmdWithoutCullSwap(Nsbmd *nsbmd, NNSG3dResFileHeader *file) {
    NNSG3dResMdlSet *modelSet;
    NNSG3dResTex *texture;
    NNSG3dResDictEntryHeader *entries;

    modelSet = NNS_G3dGetMdlSet(file);
    texture = NNS_G3dGetTex(file);
    nsbmd->mResFileEntry.mTexture = NULL;
    nsbmd->mResFileEntry.mFile = NULL;
    NNS_FndAppendListObject(&gResFileEntries, &nsbmd->mResFileEntry);
    nsbmd->mResFileEntry.mFile = file;
    if (texture != NULL) {
        texture->mTexInfo.mFlag &= ~1;
        texture->mTex4x4Info.mFlag &= ~1;
        texture->mTexInfo.mVramKey = 0;
        texture->mTex4x4Info.mVramKey = 0;
        texture->mPlttInfo.mFlag &= ~1;
        texture->mPlttInfo.mVramKey = 0;
        UploadResTexture(texture);
        nsbmd->mResFileEntry.mTexture = texture;
        if (modelSet->mHeader.mSignature == RES_BLOCK_SIGNATURE_MODEL_SET) {
            NNS_G3dBindMdlSet(modelSet, texture);
        }
    }
    modelSet = NNS_G3dGetMdlSet(file);
    entries = OFFSET_PTR(NNSG3dResDictEntryHeader, &modelSet->mDict, modelSet->mDict.mOfsEntry);
    InitNsbmdRenderObj(nsbmd, OFFSET_PTR(NNSG3dResMdl, modelSet, *DICT_ENTRY(u32, entries, 0)), 0);
    return nsbmd->mResMdl;
}

// Fills the object from model file c and texture file d, then keeps a heap copy of the texture block's header part.
NNSG3dResMdl *InitNsbmdWithTextureInfoCopy(void *heap, Nsbmd *nsbmd, NNSG3dResFileHeader *modelFile,
                                           NNSG3dResFileHeader *textureFile) {
    NNSG3dResMdlSet *modelSet;
    NNSG3dResTex *texture;
    NNSG3dResDictEntryHeader *entries;
    NNSG3dResTex *loadedTexture;
    u32 headerSize;
    ResFileEntry *entry;
    NNSG3dResMdl *resMdl;

    modelSet = NNS_G3dGetMdlSet(modelFile);
    texture = NNS_G3dGetTex(textureFile);
    nsbmd->mResFileEntry.mTexture = NULL;
    nsbmd->mResFileEntry.mFile = NULL;
    NNS_FndAppendListObject(&gResFileEntries, &nsbmd->mResFileEntry);
    nsbmd->mResFileEntry.mFile = modelFile;
    if (texture != NULL) {
        texture->mTexInfo.mFlag &= ~1;
        texture->mTex4x4Info.mFlag &= ~1;
        texture->mTexInfo.mVramKey = 0;
        texture->mTex4x4Info.mVramKey = 0;
        texture->mPlttInfo.mFlag &= ~1;
        texture->mPlttInfo.mVramKey = 0;
        UploadResTexture(texture);
        nsbmd->mResFileEntry.mTexture = texture;
        if (modelSet->mHeader.mSignature == RES_BLOCK_SIGNATURE_MODEL_SET) {
            NNS_G3dBindMdlSet(modelSet, texture);
        }
    }
    modelSet = NNS_G3dGetMdlSet(modelFile);
    entries = OFFSET_PTR(NNSG3dResDictEntryHeader, &modelSet->mDict, modelSet->mDict.mOfsEntry);
    InitNsbmdRenderObj(nsbmd, OFFSET_PTR(NNSG3dResMdl, modelSet, *DICT_ENTRY(u32, entries, 0)), 1);
    entry = &nsbmd->mResFileEntry;
    loadedTexture = entry->mTexture;
    resMdl = nsbmd->mResMdl;
    if (loadedTexture != NULL) {
        headerSize = loadedTexture->mTexInfo.mOfsTex;
        entry->mTexture = HeapAlloc(heap, headerSize);
        MI_CpuCopy8(loadedTexture, entry->mTexture, headerSize);
    }
    return resMdl;
}

void SetNsbmdFirstDrawMaterial(Nsbmd *nsbmd, u8 alpha) {

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

void SetNsbmdSecondDrawMaterial(Nsbmd *nsbmd, u8 alpha, u8 polygonId) {

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
void DrawNsbmdWithMatrix(Nsbmd *object, MtxFx43 *matrix, const Vec3 *scale) {
    s32 commandParam = 30;
    u32 scaleCopy[3];

    NNS_G3dGeBufferOP_N(20, &commandParam, 1);
    NNS_G3dGeBufferOP_N(25, matrix, 12);
    if (scale != NULL) {
        u32 scaleZ = scale->z;
        u32 scaleY = scale->y;
        u32 scaleX = scale->x;
        scaleCopy[0] = scaleX;
        scaleCopy[1] = scaleY;
        scaleCopy[2] = scaleZ;
        NNS_G3dGeBufferOP_N(27, &scaleCopy, 3);
    }
    gNsbmdDrawFunctions[object->mDrawKind](object);
}

void DrawNsbmd(Nsbmd *nsbmd) {

    gNsbmdDrawFunctions[nsbmd->mDrawKind](nsbmd);
}

void SetNsbmdPolygonIdAll(Nsbmd *nsbmd, u32 polygonId) {

    NNS_G3dMdlSetMdlPolygonIDAll(nsbmd->mResMdl, polygonId);
}

void SetNsbmdLightEnableFlagAll(Nsbmd *nsbmd, u32 light) {

    NNS_G3dMdlSetMdlLightEnableFlagAll(nsbmd->mResMdl, light);
}

void SetNsbmdEmiAll(Nsbmd *nsbmd, u32 color) {

    NNS_G3dMdlSetMdlEmiAll(nsbmd->mResMdl, color);
}

void SetNsbmdPolygonIdLightEmiAll(Nsbmd *nsbmd, u32 polygonId, u32 light, u32 color) {

    NNS_G3dMdlSetMdlPolygonIDAll(nsbmd->mResMdl, polygonId);
    NNS_G3dMdlSetMdlLightEnableFlagAll(nsbmd->mResMdl, light);
    NNS_G3dMdlSetMdlEmiAll(nsbmd->mResMdl, color);
}

void SetNsbmdCullModeAll(Nsbmd *nsbmd, u32 cullMode) {

    NNS_G3dMdlSetMdlCullModeAll(nsbmd->mResMdl, cullMode);
}

// Frees the texture and palette memory of the file of every entry of gResFileEntries; the entries stay in the list.
void ReleaseAllResFiles(void) {
    ResFileEntry *entry;

    for (entry = NNS_FndGetNextListObject(&gResFileEntries, NULL); entry != NULL;
         entry = NNS_FndGetNextListObject(&gResFileEntries, entry)) {
        if (entry->mFile != NULL) {
            NNS_G3dResDefaultRelease(entry->mFile);
        }
    }
}

void InitKartEffectTables(void *heap) {
    u32 kartCount;
    u16 kartIndex;
    u16 effectIndex;

    kartCount = gRaceSetup->mKartCount;
    gKartEffectIdSetIndex = HeapAlloc(heap, kartCount * 2);
    gKartStarEffects = HeapAlloc(heap, kartCount * 12);
    gKartAheadEffects = HeapAlloc(heap, kartCount * 4);
    gKartNearRankEffects = HeapAlloc(heap, kartCount * 4);
    for (kartIndex = 0; kartIndex < kartCount; kartIndex++) {
        for (effectIndex = 0; effectIndex < 3; effectIndex++) {
            gKartStarEffects[kartIndex].mEffects[effectIndex] = NULL;
        }
        gKartAheadEffects[kartIndex] = NULL;
        gKartNearRankEffects[kartIndex] = NULL;
        if (kartIndex == gRaceSetup->mEntryIndex) {
            gKartEffectIdSetIndex[kartIndex] = 0;
        } else {
            gKartEffectIdSetIndex[kartIndex] = 1;
        }
    }
    gKartEffectColor = 0x7fff;
    switch (gRaceSetup->mCourseId) {
        case COURSE_ID_MANSION:
        case COURSE_ID_KOOPA:
            gKartEffectColor = 0x1667;
            break;
        case COURSE_ID_TOWN:
            gKartEffectColor = 0x2ff;
            break;
        case COURSE_ID_GARDEN:
            gKartEffectColor = 0x3e67;
            break;
    }
    gOtherKartFullPairCount = (gRaceSetup->mKartCount - 1) / 2;
    gOtherKartOddCount = (gRaceSetup->mKartCount - 1) % 2;
    gStarEffectEngineScale = 0x1000;
    switch (gRaceSetup->mEngineIndex) {
        case ENGINE_CLASS_SLOW:
            gStarEffectEngineScale = 0xb33;
            break;
        case ENGINE_CLASS_MEDIUM:
            gStarEffectEngineScale = 0xd9a;
            break;
    }
}
