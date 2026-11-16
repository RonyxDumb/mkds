#include "Main/Unknown/code_02062ed8.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_0203be88.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/code_0205e000.h"
#include "Main/Unknown/code_020649ec.h"
#include "Main/Unknown/code_0206d020.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_0206d000.h"
#include "Main/Unknown/code_02064000.h"
#include "Main/Unknown/code_02065000.h"
#include "Main/Unknown/code_0207a870.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_02036bec.h"
#include "code_02010c84.h"
#include "code_02012b30.h"
#include "code_02013740.h"
#include "Main/Unknown/code_02087cfc.h"
#include "Main/Unknown/code_02087d0c.h"
#include "Main/Unknown/code_020846c0.h"
#include "Main/Unknown/code_02147000.h"
#include "code_021471bc.h"

static inline void func_0206331c_inline(u32 animationKind, u8 *animation, Nsbmd *nsbmd, void *heap,
                                        const char *modelFile, const char *animationFile, u16 *animationCount) {
    if (animationFile == NULL) {
        *animationCount = 0;
    } else {
        anim_initManager(animationKind, animation, nsbmd, 1, heap, modelFile);
        anim_registerAllAnims(animation, animationFile, heap);
        anim_setLoop(animation, 0, 1);
        anim_setAnim(animation, 0);
    }
}

void func_02063880(Kart *kart) {
    AdvanceKartCollision(kart);
    if ((gStruct217AA14->field75C & 2) != 0) {
        func_020636f8(kart);
    }
    func_020641f0(kart);
}

void func_02063830(Kart *kart) {
    if (driver_getCheckMissionEndArea() != 0) {
        rstat_handleMissionEndAreas(&kart->mPos, kart->mIndex);
    }
    if ((kart->field4C & 0x1000) != 0) {
        func_0206d138(kart);
    }
    kart->field4C = kart->field4C & ~0x1000;
    driver_1FFCC50(kart);
}

void func_020637e0(Kart *kart) {
    if (driver_getCheckMissionEndArea() != 0) {
        rstat_handleMissionEndAreas(&kart->mPos, kart->mIndex);
    }
    if ((kart->field4C & 0x1000) != 0) {
        func_0206d138(kart);
    }
    kart->field4C = kart->field4C & ~0x1000;
    func_020651fc(kart);
}

void func_020637c4(Kart *kart) {
    func_02064f50(kart);
    func_020641f0(kart);
}

void func_020636f8(Kart *kart) {
    ParticipantKartRecordState *b;
    Unk0217aa14_754_04 *recordBase;
    Unk020636f8_B *record;

    recordBase = &gStruct217AA14->field754->field4;
    record = OFFSET_PTR(Unk020636f8_B, recordBase, 8);
    b = kart->field514;
    record->field0 = kart->mPos.x >> 10;
    record->field2 = (kart->mPos.y - kart->mHopHeight) >> 10;
    record->field4 = kart->mPos.z >> 10;
    record->field6 = kart->mForwardSpeed >> 2;
    record->fieldA = kart->mHeadingAngle;
    record->field10 = kart->field44;
    record->field10 =
        record->field10 | (((b->mPushDirection.x >> 6) & 0xff) << 24 | ((b->mPushDirection.y >> 6) & 0xff) << 16 |
                           ((b->mPushDirection.z >> 6) & 0xff) << 8);
    record->field14 = kart->field48;
    record->fieldC = b->field2C;
    record->field8 = kart->mTurnAngle;
}

// Also sets the matrix and the per-course flags (CreateCourseModels would be the verb for just finding and building).
void crsmdl_init(void *heap) {
    const char *nsbmdFile;
    const char *nsbtxFile;
    const char *animationFile;
    NNSG3dResMdl *resMdl;
    s32 materialIndex;
    s32 shdwOffMaterialIndices[6];
    s32 i;

    nsbmdFile = arc_getCourseArcFile(aCourse_model_n);
    nsbtxFile = arc_getCourseArcFile(aCourse_model_0);
    crsmdl_sState.mNsbmd = heap_alloc(heap, 0x6c);
    resMdl = model_initFromNsbmdNsbtxMetaCopy(heap, crsmdl_sState.mNsbmd, (NNSG3dResFileHeader *) nsbmdFile,
                                          (NNSG3dResFileHeader *) nsbtxFile);
    animationFile = arc_getCourseArcFile(aCourse_model_1);
    func_0206331c_inline(2, data_0217ab24, crsmdl_sState.mNsbmd, heap, nsbmdFile, animationFile,
                         &crsmdl_sState.mNsbtpAnmObjCount);
    animationFile = arc_getCourseArcFile(aCourse_model_2);
    func_0206331c_inline(1, data_0217ab5c, crsmdl_sState.mNsbmd, heap, nsbmdFile, animationFile,
                         &crsmdl_sState.mNsbtaAnmObjCount);
    model_setPolygonId(crsmdl_sState.mNsbmd, 8);
    NNS_G3dMdlSetMdlXLDepthUpdateAll(resMdl, 1);
    switch (gRaceMultiConfig->mCourseId) {
        case COURSE_ID_OLD_KOOPA_AGB:
            materialIndex = NNS_G3dGetResDictIdxByName((u8 *) resMdl + resMdl->mOfsMat + 4, crsmdl_sYoganMat);
            if (materialIndex >= 0) {
                NNS_G3dMdlSetMdlAlpha(resMdl, materialIndex, 0x1e);
                NNS_G3dMdlSetMdlXLDepthUpdate(resMdl, materialIndex, 0);
            }
            break;
        case COURSE_ID_BANK:
            materialIndex = NNS_G3dGetResDictIdxByName((u8 *) resMdl + resMdl->mOfsMat + 4, crsmdl_sFalls01Mat);
            if (materialIndex >= 0) {
                NNS_G3dMdlSetMdlXLDepthUpdate(resMdl, materialIndex, 0);
            }
            materialIndex = NNS_G3dGetResDictIdxByName((u8 *) resMdl + resMdl->mOfsMat + 4, crsmdl_sFalls02Mat);
            if (materialIndex >= 0) {
                NNS_G3dMdlSetMdlXLDepthUpdate(resMdl, materialIndex, 0);
            }
            break;
    }
    crsmdl_sState.mVNsbmd = NULL;
    nsbmdFile = arc_getCourseArcFile(aCourse_model_v);
    nsbtxFile = arc_getCourseArcFile(aCourse_model_5);
    if (nsbmdFile != NULL) {
        crsmdl_sState.mVNsbmd = heap_alloc(heap, 0x6c);
        model_initFromNsbmdNsbtxMetaCopy(heap, crsmdl_sState.mVNsbmd, (NNSG3dResFileHeader *) nsbmdFile,
                                     (NNSG3dResFileHeader *) nsbtxFile);
        model_setPolygonId(crsmdl_sState.mVNsbmd, 8);
        animationFile = arc_getCourseArcFile(aCourse_model_3);
        func_0206331c_inline(1, data_0217ab94, crsmdl_sState.mVNsbmd, heap, nsbmdFile, animationFile,
                             &crsmdl_sState.mVNsbtaAnmObjCount);
    }
    shdwOffMaterialIndices[0] = NNS_G3dGetResDictIdxByName((u8 *) resMdl + resMdl->mOfsMat + 4, crsmdl_sShdwOffMat);
    shdwOffMaterialIndices[1] = NNS_G3dGetResDictIdxByName((u8 *) resMdl + resMdl->mOfsMat + 4, crsmdl_sShdwOff1Mat);
    shdwOffMaterialIndices[2] = NNS_G3dGetResDictIdxByName((u8 *) resMdl + resMdl->mOfsMat + 4, crsmdl_sShdwOff2Mat);
    shdwOffMaterialIndices[3] = NNS_G3dGetResDictIdxByName((u8 *) resMdl + resMdl->mOfsMat + 4, crsmdl_sShdwOff3Mat);
    shdwOffMaterialIndices[4] = NNS_G3dGetResDictIdxByName((u8 *) resMdl + resMdl->mOfsMat + 4, crsmdl_sShdwOff4Mat);
    shdwOffMaterialIndices[5] = NNS_G3dGetResDictIdxByName((u8 *) resMdl + resMdl->mOfsMat + 4, crsmdl_sShdwOff5Mat);
    for (i = 0; i < 6; i++) {
        if (shdwOffMaterialIndices[i] >= 0) {
            NNS_G3dMdlSetMdlPolygonID(resMdl, shdwOffMaterialIndices[i], 7);
        }
    }
    MTX_Identity43_(&data_0217abcc);
    crsmdl_setupFog();
}

void crsmdl_update(void) {
    if (crsmdl_sState.mNsbtpAnmObjCount != 0) {
        anim_update(data_0217ab24);
    }
    if (crsmdl_sState.mNsbtaAnmObjCount != 0) {
        anim_update(data_0217ab5c);
    }
    if (crsmdl_sState.mVNsbmd != NULL && crsmdl_sState.mVNsbtaAnmObjCount != 0) {
        anim_update(data_0217ab94);
    }
}

void crsmdl_renderCourse(void) {
    model_drawTransformed(crsmdl_sState.mNsbmd, &data_0217abcc, crsmdl_sModelScale);
}

void crsmdl_renderSky(void) {
    if (crsmdl_sState.mVNsbmd == NULL) {
        return;
    }
    model_drawTransformed(crsmdl_sState.mVNsbmd, &data_0217abcc, crsmdl_sModelScale);
}

void crsmdl_setupLights(void) {
    Vec3s16 lightVector;

    if (gRaceMultiConfig->mCourseId != COURSE_ID_KOOPA) {
        return;
    }
    lightVector = crsmdl_sKoopaCrsLight2Dir;
    NNS_G3dGlbLightVector(2, lightVector.x, lightVector.y, lightVector.z);
    NNS_G3dGlbLightColor(2, 0x7fff);
}

void crsmdl_setupFog(void) {
    u32 i;
    NNSG3dResMdl *courseResMdl;
    u32 j;
    NNSG3dResMdl *vResMdl;

    crsmdl_sState.mRestoreFogEnableFlags = FALSE;
    crsmdl_sState.mSavedFogEnableFlags = 0;
    crsmdl_sState.mRestoreVFogEnableFlags = FALSE;
    crsmdl_sState.mSavedVFogEnableFlags = 0;
    switch (gRaceMultiConfig->mCourseId) {
        case COURSE_ID_MANSION:
        case COURSE_ID_DESERT:
        case COURSE_ID_MINI_STAGE2:
            crsmdl_sState.mRestoreFogEnableFlags = TRUE;
            break;
        case COURSE_ID_RAINBOW:
            crsmdl_sState.mRestoreVFogEnableFlags = TRUE;
            break;
    }
    if (crsmdl_sState.mRestoreFogEnableFlags != FALSE) {
        courseResMdl = crsmdl_sState.mNsbmd->mResMdl;
        for (i = 0; i < courseResMdl->mInfo.mNumMat; i++) {
            if (NNS_G3dMdlGetMdlFogEnableFlag(courseResMdl, i) != 0) {
                crsmdl_sState.mSavedFogEnableFlags |= (s64) (1 << i);
            }
        }
    } else {
        NNS_G3dMdlSetMdlFogEnableFlagAll(crsmdl_sState.mNsbmd->mResMdl, 1);
    }
    if (crsmdl_sState.mVNsbmd == NULL) {
        return;
    }
    if (crsmdl_sState.mRestoreVFogEnableFlags == FALSE) {
        return;
    }
    vResMdl = crsmdl_sState.mVNsbmd->mResMdl;
    for (j = 0; j < vResMdl->mInfo.mNumMat; j++) {
        if (NNS_G3dMdlGetMdlFogEnableFlag(vResMdl, j) != 0) {
            crsmdl_sState.mSavedVFogEnableFlags |= 1 << j;
        }
    }
}

void crsmdl_setFogFlags(u32 flag) {
    u32 i;
    NNSG3dResMdl *resMdl;
    u32 j;

    if (crsmdl_sState.mVNsbmd != NULL) {
        if (crsmdl_sState.mRestoreVFogEnableFlags != FALSE && flag == 0) {
            resMdl = crsmdl_sState.mVNsbmd->mResMdl;
            for (i = 0; i < resMdl->mInfo.mNumMat; i++) {
                NNS_G3dMdlSetMdlFogEnableFlag(resMdl, i, (crsmdl_sState.mSavedVFogEnableFlags & (1 << i)) != 0 ? 1 : 0);
            }
        } else {
            NNS_G3dMdlSetMdlFogEnableFlagAll(crsmdl_sState.mVNsbmd->mResMdl, flag);
        }
    }
    if (crsmdl_sState.mRestoreFogEnableFlags == FALSE) {
        return;
    }
    if (flag != 0) {
        NNS_G3dMdlSetMdlFogEnableFlagAll(crsmdl_sState.mNsbmd->mResMdl, 1);
        return;
    }
    resMdl = crsmdl_sState.mNsbmd->mResMdl;
    for (j = 0; j < resMdl->mInfo.mNumMat; j++) {
        if ((crsmdl_sState.mSavedFogEnableFlags & (s64) (1 << j)) == 0) {
            NNS_G3dMdlSetMdlFogEnableFlag(resMdl, j, 0);
        }
    }
}

s32 crsmdl_getNsbtpProgress(void) {
    if (crsmdl_sState.mNsbtpAnmObjCount != 0) {
        return crsmdl_sState.mNsbtpFrameIndex >> 12;
    }
    return -1;
}
