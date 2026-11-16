#include "Main/Unknown/code_020931ac.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020d2000.h"

#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0209bf70.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_020d26f8.h"
#include "Main/Unknown/code_020d275c.h"
#include "Main/Unknown/code_020d3b10.h"
#include "Main/Unknown/code_020d7da8.h"
#include "Main/Unknown/code_020d8918.h"
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/unk_02166000.h"
#include "Main/Unknown/unk_0217b000.h"

void efbnr_init(MapObject *mapObject) {
    MapObject *value0 = mapObject;
    u32 value12;
    mobj_initSoundEmitterForObjectSfxParam2(value0);
}

u8 efbnr_onDriverCollide(MkdEfBurner *mkdEfBurner, Kart *kart, u8 *c, u8 *d) {
    u8 v;

    v = *d;
    if (mkdEfBurner->mKartTimers[kart->mIndex] == 0 && mobj_tryDestroyByDriver(&mkdEfBurner->mUnk_00, kart) != 0) {
        mkdEfBurner->mUnk_00.mDistanceSquaredAndFlags |= data_02156470;
        mkdEfBurner->mKartTimers[kart->mIndex] = 0x1f;
    }
    return v;
}

void efbnr_loadModel(Unk02093708 *p) {
    efbnr_sModel = mobj_loadModel(p, aMkd_ef_burner_);
    mobj_loadNsbtaAnim(efbnr_sModel, aMkd_ef_burne_0);
    mobj_setModelPolygonIdAll(efbnr_sModel, 0x3f);
    p->mUnk_1c = 1;
}

void efbnr_applyMaterial(void *a) {
    mobj_bbModelApplyMaterial(a, efbnr_sModel);
}

void efbnr_render(void *a, MkdEfBurner *mkdEfBurner) {
    s32 s0;
    Vec3 s4;
    Vec3 s10;

    if (mkdEfBurner->mScaleFixed12 <= 0) {
        return;
    }
    mobj_setModelPolygonIdAll(efbnr_sModel, mobj_getCyclicPolygonId());
    s0 = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &s0, 1);
    NNS_G3dGeBufferOP_N(0x19, bbm_getYBillboardAtPos(&mkdEfBurner->mUnk_00.mPos), 0xc);
    s4.y = mkdEfBurner->mUnk_00.mExtent.y >> 4;
    s4.x = 0;
    s4.z = 0;
    NNS_G3dGeBufferOP_N(0x1c, &s4, 3);
    s10.x = mkdEfBurner->mScaleFixed12;
    s10.y = s10.x;
    s10.z = s10.x;
    NNS_G3dGeBufferOP_N(0x1b, &s10, 3);
    NNS_G3dGeBufferOP_N(0x1b, &mkdEfBurner->mUnk_00.mScale, 3);
    mobj_setModelNsbtaFrame(efbnr_sModel, mkdEfBurner->mNsbtaFrameIndex);
    mobj_renderModel(a, efbnr_sModel, mkdEfBurner);
}

void efbnr_globalLogicInit(MapObjectList *mapObjectList) {
    BOOL z;
    s32 i;
    MkdEfBurner *mkdEfBurner;
    u16 f;
    s32 speed;

    if (mapObjectList == NULL) {
        return;
    }
    z = FALSE;
    f = data_0215646c;
    for (i = 0; i < mapObjectList->mMapObjectCount && (mkdEfBurner = mapObjectList->mMapObjects[i]) != NULL; i++) {
        mkdEfBurner->mUnk_00.mPos.y = mkdEfBurner->mUnk_00.mCourseMapRow->mUnk_00.y - mkdEfBurner->mUnk_00.mExtent.y;
        if (mkdEfBurner->mUnk_00.mCourseMapRow->mUnk_26 < 0) {
            mkdEfBurner->mFollower.mGroupIndex = 0xffff;
        } else {
            pw_initFromObject(&mkdEfBurner->mFollower, mkdEfBurner->mUnk_00.mCourseMapRow, z);
            speed = (mkdEfBurner->mUnk_00.mCourseMapRow->mUnk_2e << 12) / 100;
            mkdEfBurner->mFollower.mSpeed = speed;
            mkdEfBurner->mFollower.mProgressStep =
                ((s64) speed * mkdEfBurner->mFollower.mPath->mSegments[mkdEfBurner->mFollower.mSegmentIndex]
                                   .mInverseProgressLength) >>
                12;
        }
        if (mkdEfBurner->mUnk_00.mCourseMapRow->mUnk_28 == 0 && mkdEfBurner->mUnk_00.mCourseMapRow->mUnk_2a == 0 &&
            mkdEfBurner->mUnk_00.mCourseMapRow->mUnk_2c == 0) {
            mkdEfBurner->mScaleFixed12 = 0x1000;
            mkdEfBurner->mState = 4;
            mkdEfBurner->mUnk_00.mFlags &= ~1;
        } else {
            mkdEfBurner->mStateFrames++;
            if (mkdEfBurner->mStateFrames >= mkdEfBurner->mUnk_00.mCourseMapRow->mUnk_2c) {
                mkdEfBurner->mStateFrames = 0;
                mkdEfBurner->mState = 1;
                mkdEfBurner->mUnk_00.mFlags |= f;
                mkdEfBurner->mUnk_00.mExtent.y = 0;
            }
        }
    }
}

void efbnr_update(void *a, MkdEfBurner *mkdEfBurner) {
    u16 nsbtaFrameCount;
    s32 i;
    u8 kartCount;

    switch (mkdEfBurner->mState) {
        case 0:
            mkdEfBurner->mStateFrames++;
            if (mkdEfBurner->mStateFrames >= mkdEfBurner->mUnk_00.mCourseMapRow->mUnk_2a) {
                mkdEfBurner->mStateFrames = 0;
                mkdEfBurner->mState = 1;
                mkdEfBurner->mUnk_00.mFlags &= ~1;
            }
            break;
        case 1:
            mkdEfBurner->mScaleFixed12 += 0x7b;
            if (mkdEfBurner->mScaleFixed12 >= 0x1000) {
                mkdEfBurner->mScaleFixed12 = 0x1000;
                mkdEfBurner->mState = 2;
            }
            mkdEfBurner->mUnk_00.mExtent.y =
                ((s64) mkdEfBurner->mUnk_00.mKindData->mUnk_10 * mkdEfBurner->mScaleFixed12) >> 12;
            break;
        case 2:
            mkdEfBurner->mStateFrames++;
            if (mkdEfBurner->mStateFrames >= mkdEfBurner->mUnk_00.mCourseMapRow->mUnk_28) {
                mkdEfBurner->mStateFrames = 0;
                mkdEfBurner->mState = 3;
            }
            mobj_emitSfxFromEmitter(&mkdEfBurner->mUnk_00, 0x170);
            break;
        case 3:
            mkdEfBurner->mScaleFixed12 -= 0x29;
            if (mkdEfBurner->mScaleFixed12 <= 0) {
                mkdEfBurner->mScaleFixed12 = 0;
                mkdEfBurner->mState = 0;
                mkdEfBurner->mUnk_00.mFlags |= data_0215646c;
            }
            mkdEfBurner->mUnk_00.mExtent.y =
                ((s64) mkdEfBurner->mUnk_00.mKindData->mUnk_10 * mkdEfBurner->mScaleFixed12) >> 12;
            break;
        case 4:
            mobj_emitSfxFromEmitter(&mkdEfBurner->mUnk_00, 0x170);
            break;
    }
    nsbtaFrameCount = mobj_getModelNsbtaFrameCount(efbnr_sModel);
    mkdEfBurner->mNsbtaFrameIndex++;
    if (mkdEfBurner->mNsbtaFrameIndex >= nsbtaFrameCount) {
        mkdEfBurner->mNsbtaFrameIndex = 0;
    }
    if (mkdEfBurner->mFollower.mGroupIndex != 0xffff) {
        pw_update(&mkdEfBurner->mFollower);
        pw_calcCurrentPointLinearXYZ(&mkdEfBurner->mFollower, &mkdEfBurner->mUnk_00.mPos);
        mkdEfBurner->mUnk_00.mPos.y = mkdEfBurner->mUnk_00.mPos.y - mkdEfBurner->mUnk_00.mExtent.y;
    } else {
        mkdEfBurner->mUnk_00.mPos.y = mkdEfBurner->mUnk_00.mCourseMapRow->mUnk_00.y - mkdEfBurner->mUnk_00.mExtent.y;
    }
    kartCount = gRaceMultiConfig->mKartCount;
    for (i = 0; i < kartCount; i++) {
        if (mkdEfBurner->mKartTimers[i] > 0) {
            mkdEfBurner->mKartTimers[i]--;
        }
    }
}

void efbnr_setupConfig(void) {
    mobj_createConfigEx(&efbnr_onDriverCollide, NULL, NULL, 2, 0, (0x0000018du));
}

void efbnr_setupRenderPart(void) {
    mobj_createRenderPart3d(&efbnr_loadModel, &efbnr_render, &efbnr_applyMaterial);
}

void efbnr_setupLogicPart(void) {
    mobj_createLogicPart(&efbnr_globalLogicInit, &efbnr_update, NULL);
}

u16 efbnr_getMapIconType(Unk0217b498_00 *a) {
    if (a->mUnk_a8 >= 0x1000) {
        return 3;
    }
    if (a->mUnk_a8 >= 0x99a) {
        return 2;
    }
    return a->mUnk_a8 >= 0x4cd;
}
