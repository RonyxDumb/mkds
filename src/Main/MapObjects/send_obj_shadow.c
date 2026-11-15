#include "Main/MapObjects/send_obj_shadow.h"

#include "Main/Sound/sound_data_sdat_path.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "matrix_3x3_basic.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/sound_if_kart_star_or.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/map_object_list.h"
#include "Main/MapObjects/map_object.h"
#include "Main/MapObjects/shadow_model_create.h"
#include "Main/MapObjects/nsbmd_model_draw.h"
#include "ITCM/g3d_draw_and_irq_handler.h"
#include "ITCM/kart_motion.h"
#include "Main/System/result_archive_path.h"
#include "Main/Kart/shadow_model_draw.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"

NNSG3dResShpData *gObjShadowShape;
Nsbmd *gObjShadow;
ShadowModel *gJgShadow;
NNSG3dResMatData *gObjShadowMaterial;

void SendObjShadowMaterial(void) {
    u32 plttBase;
    plttBase = gObjShadowMaterial->mTexPlttBase;
    NNS_G3dGeBufferOP_N(0x2b, &plttBase, 1);
    NNS_G3dGeBufferOP_N(0x2a, &gObjShadowMaterial->mTexImageParam, 1);
    NNS_G3dGeBufferOP_N(0x30, &gObjShadowMaterial->mDiffAmb, 1);
    NNS_G3dGeBufferOP_N(0x31, &gObjShadowMaterial->mSpecEmi, 1);
}

void DrawObjShadowAfterMaterial(ShadowMatrix *shadow, void *wordPointer, u32 unused, u32 alpha) {
    u32 polygonAttributes;
    u32 value;
    u32 threeWords[3];

    value = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &value, 1);
    NNS_G3dGeBufferOP_N(0x19, shadow, 0xc);
    if (wordPointer != NULL) {
        u32 firstWord;
        firstWord = *(u32 *) wordPointer;
        threeWords[0] = firstWord;
        threeWords[1] = firstWord;
        threeWords[2] = firstWord;
        NNS_G3dGeBufferOP_N(0x1b, threeWords, 3);
    }
    polygonAttributes = gObjShadowMaterial->mPolyAttr;
    alpha = alpha < shadow->mAlphaCap ? alpha : shadow->mAlphaCap;
    polygonAttributes = polygonAttributes & ~0x1f0000;
    polygonAttributes = polygonAttributes | (alpha << 16);
    NNS_G3dGeBufferOP_N(0x29, &polygonAttributes, 1);
    NNS_G3dGeSendDL((u8 *) gObjShadowShape + gObjShadowShape->mOfsDL, gObjShadowShape->mSizeDL);
}

void DrawObjShadow(ShadowMatrix *shadow, void *wordPointer, u32 unused, u32 alpha) {
    u32 plttBase;
    u32 polygonAttributes;
    u32 value;
    u32 threeWords[3];

    plttBase = gObjShadowMaterial->mTexPlttBase;
    NNS_G3dGeBufferOP_N(0x2b, &plttBase, 1);
    NNS_G3dGeBufferOP_N(0x2a, &gObjShadowMaterial->mTexImageParam, 1);
    NNS_G3dGeBufferOP_N(0x30, &gObjShadowMaterial->mDiffAmb, 1);
    NNS_G3dGeBufferOP_N(0x31, &gObjShadowMaterial->mSpecEmi, 1);
    value = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &value, 1);
    NNS_G3dGeBufferOP_N(0x19, shadow, 0xc);
    if (wordPointer != NULL) {
        u32 wordCopy;
        wordCopy = *(u32 *) wordPointer;
        threeWords[0] = wordCopy;
        threeWords[1] = wordCopy;
        threeWords[2] = wordCopy;
        NNS_G3dGeBufferOP_N(0x1b, threeWords, 3);
    }
    polygonAttributes = gObjShadowMaterial->mPolyAttr;
    alpha = alpha < shadow->mAlphaCap ? alpha : shadow->mAlphaCap;
    polygonAttributes = polygonAttributes & ~0x1f0000;
    polygonAttributes = polygonAttributes | (alpha << 16);
    NNS_G3dGeBufferOP_N(0x29, &polygonAttributes, 1);
    NNS_G3dGeSendDL((u8 *) gObjShadowShape + gObjShadowShape->mOfsDL, gObjShadowShape->mSizeDL);
}

void DrawJgShadowWithMatrix(Vec3 *scale, MtxFx43 *matrix, u16 alphaCap, u32 maxAlpha) {
    gJgShadow->mAlpha = alphaCap < maxAlpha ? alphaCap : maxAlpha;
    DrawShadowWithMatrix(gJgShadow, matrix, scale);
}

void DrawJgShadow(u32 alphaCap, u32 maxAlpha) {
    gJgShadow->mAlpha = alphaCap < maxAlpha ? alphaCap : maxAlpha;
    DrawShadowModelIfDrawFlag(gJgShadow);
}

#pragma thumb on

void CreateObjShadowAndJgShadow(void) {
    NNSG3dResMdl *resMdl;
    NNSG3dResMat *resMat;
    NNSG3dResShp *resShp;
    NNSG3dResDictEntryHeader *entries;

    CreateNsbmd(&gObjShadow, FindMainRaceOrMainEffectMapObjFile("obj_shadow.nsbmd"), NULL);
    SetNsbmdPolygonIdAll(gObjShadow, 0x3f);
    SetNsbmdLightEnableFlagAll(gObjShadow, 0);
    resMdl = gObjShadow->mResMdl;
    resMat = OFFSET_PTR(NNSG3dResMat, resMdl, resMdl->mOfsMat);
    entries = OFFSET_PTR(NNSG3dResDictEntryHeader, &resMat->mDict, resMat->mDict.mOfsEntry);
    gObjShadowMaterial = OFFSET_PTR(NNSG3dResMatData, resMat, *DICT_ENTRY(u32, entries, 0));
    resMdl = gObjShadow->mResMdl;
    resShp = OFFSET_PTR(NNSG3dResShp, resMdl, resMdl->mOfsShp);
    entries = OFFSET_PTR(NNSG3dResDictEntryHeader, &resShp->mDict, resShp->mDict.mOfsEntry);
    gObjShadowShape = OFFSET_PTR(NNSG3dResShpData, resShp, *DICT_ENTRY(u32, entries, 0));
    if (gRaceSetup->mRaceKind != RACE_KIND_STAFF_ROLL) {
        CreateShadowModel(&gJgShadow, FindSceneFile("jg_shadow.nsbmd"), 0x3f);
    }
}

s32 RefreshShadowMatrix(ShadowMatrix *shadowCopy, Vec3 *position, s32 scale, u32 alphaCap) {
    Quaternion rotation;
    Vec3 direction;
    Vec3 raisedPosition;
    s32 scaleTenth;
    BOOL hit;

    raisedPosition = *position;
    hit = FALSE;
    raisedPosition.y = raisedPosition.y + 0x1999;
    if (CollideSphereWithCourse(&raisedPosition, NULL, 0, 0xa000, 8, -2, NULL, &direction, NULL, NULL, NULL, NULL, NULL,
                                NULL) != 0) {
        hit = TRUE;
        QuaternionFromYAxisToVec3(&direction, &rotation);
        Matrix3x3FromQuaternion(&shadowCopy->mMatrix.mAxes, &rotation);
        scaleTenth = scale / 10;
        shadowCopy->mMatrix.mRows[0].x = MUL_FIXED12_NO_ROUND(shadowCopy->mMatrix.mRows[0].x, scaleTenth);
        shadowCopy->mMatrix.mRows[0].y = MUL_FIXED12_NO_ROUND(shadowCopy->mMatrix.mRows[0].y, scaleTenth);
        shadowCopy->mMatrix.mRows[0].z = MUL_FIXED12_NO_ROUND(shadowCopy->mMatrix.mRows[0].z, scaleTenth);
        shadowCopy->mMatrix.mRows[1].x = MUL_FIXED12_NO_ROUND(shadowCopy->mMatrix.mRows[1].x, scaleTenth);
        shadowCopy->mMatrix.mRows[1].y = MUL_FIXED12_NO_ROUND(shadowCopy->mMatrix.mRows[1].y, scaleTenth);
        shadowCopy->mMatrix.mRows[1].z = MUL_FIXED12_NO_ROUND(shadowCopy->mMatrix.mRows[1].z, scaleTenth);
        shadowCopy->mMatrix.mRows[2].x = MUL_FIXED12_NO_ROUND(shadowCopy->mMatrix.mRows[2].x, scaleTenth);
        shadowCopy->mMatrix.mRows[2].y = MUL_FIXED12_NO_ROUND(shadowCopy->mMatrix.mRows[2].y, scaleTenth);
        shadowCopy->mMatrix.mRows[2].z = MUL_FIXED12_NO_ROUND(shadowCopy->mMatrix.mRows[2].z, scaleTenth);
    } else {
        MTX_Identity33_(&shadowCopy->mMatrix.mAxes);
    }
    shadowCopy->mMatrix.mRows[3].x = raisedPosition.x >> 4;
    shadowCopy->mMatrix.mRows[3].y = raisedPosition.y >> 4;
    shadowCopy->mMatrix.mRows[3].z = raisedPosition.z >> 4;
    shadowCopy->mAlphaCap = alphaCap;
    return hit;
}

#pragma thumb off
