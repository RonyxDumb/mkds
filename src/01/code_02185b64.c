#include "01/code_02185b64.h"

#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_0209bef0.h"
#include "01/callees_0219b000.h"
#include "01/code_02185ef4.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0209bf70.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020a100c.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020d2dec.h"
#include "Main/Unknown/code_020d3000.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_02146000.h"
#include "code_02146cbc.h"
#include "code_02147cd8.h"
#include "ITCM/code_01ff8000.h"

const u16 data_ov001_021a6580 = 1;

Unk0219b250 *gMissionGate;

void mgat_init(MissionGateObject *missionGateObject) {
    s32 mtx[9];
    s32 sideExtentX;
    s32 sideExtentY;
    s16 saved;

    mobj_setDirectionFromFloor(missionGateObject);
    missionGateObject->mMapObject.mAngle =
        (missionGateObject->mMapObject.mCourseMapRow->mUnk_0c.y * 0xB60B60B60BLL + 0x80000000000LL) >> 44;
    MTX_RotY33_(mtx, FX_SinCosTable_[(missionGateObject->mMapObject.mAngle >> 4) * 2],
                FX_SinCosTable_[(missionGateObject->mMapObject.mAngle >> 4) * 2 + 1]);
    MTX_Concat33(mtx, &missionGateObject->mMapObject.mMatrix.mUnk_00[0].x,
                 &missionGateObject->mMapObject.mMatrix.mUnk_00[0].x);
    sideExtentX = (missionGateObject->mMapObject.mScale.x * 0xA000LL) >> 12;
    sideExtentY = (missionGateObject->mMapObject.mScale.y * 0xF000LL) >> 12;
    saved = missionGateObject->mMapObject.mCourseMapRow->mUnk_28;
    missionGateObject->mMapObject.mCourseMapRow->mUnk_28 = 0x12;
    missionGateObject->mNegativeSideObject = mobj_createSubObject(&missionGateObject->mMapObject, 0x66);
    missionGateObject->mPositiveSideObject = mobj_createSubObject(&missionGateObject->mMapObject, 0x66);
    missionGateObject->mMapObject.mCourseMapRow->mUnk_28 = saved;
    VEC_MultAdd(-(missionGateObject->mMapObject.mExtent.x + sideExtentX),
                &missionGateObject->mMapObject.mMatrix.mUnk_00[0], &missionGateObject->mMapObject.mPos,
                &missionGateObject->mNegativeSideObject->mPos);
    VEC_MultAdd(missionGateObject->mMapObject.mExtent.x + sideExtentX,
                &missionGateObject->mMapObject.mMatrix.mUnk_00[0], &missionGateObject->mMapObject.mPos,
                &missionGateObject->mPositiveSideObject->mPos);
    mobj_setSizeX(missionGateObject->mNegativeSideObject, sideExtentX);
    mobj_setSizeX(missionGateObject->mPositiveSideObject, sideExtentX);
    mobj_setSizeY(missionGateObject->mNegativeSideObject, sideExtentY);
    mobj_setSizeY(missionGateObject->mPositiveSideObject, sideExtentY);
}

u32 mgat_onDriverCollide(MissionGateObject *missionGateObject, Kart *kart, u8 *e, u8 *f) {
    u32 a = *e;
    u32 b = *f;

    if ((kart->mUnk_48 & 0x200) != 0 ||
        (gRaceMultiConfig->mMode == MODE_MISSION_RUN ? mgcnt_isDriverDead(kart->mIndex) : 0) != FALSE) {
        return 0;
    }
    if (a == 1) {
        missionGateObject->mMapObject.mFlags |= data_ov001_021a6580;
        missionGateObject->mState = 2;
    }
    return b;
}

void mgat_loadModel(void *a) {
    gMissionGate = LoadMapObjectModelAnimated(a, "MissionGate.nsbmd");
    LoadMapObjectModelNsbtpAnimation(gMissionGate, "MissionGate.nsbtp");
    LoadMapObjectModelNsbmaAnimation(gMissionGate, "MissionGate.nsbma");
    mobj_setModelPolygonIdAll(gMissionGate, 0x3f);
    mobj_setModelLightMask(gMissionGate, 2);
    model_setEmi(gMissionGate->mAnimatedModel, 0x294a);
}

void mgat_globalPreRender(void) {}

void mgat_render(void *mapObjectList, MissionGateObject *missionGateObject) {
    s32 buf;

    buf = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &buf, 1);
    missionGateObject->mMapObject.mMatrix.mUnk_00[3].x = missionGateObject->mMapObject.mPos.x >> 4;
    missionGateObject->mMapObject.mMatrix.mUnk_00[3].y = missionGateObject->mMapObject.mPos.y >> 4;
    missionGateObject->mMapObject.mMatrix.mUnk_00[3].z = missionGateObject->mMapObject.mPos.z >> 4;
    NNS_G3dGeBufferOP_N(0x19, &missionGateObject->mMapObject.mMatrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &missionGateObject->mMapObject.mScale, 3);
    mobj_setModelNsbtpFrame(gMissionGate, missionGateObject->mMapObject.mCourseMapRow->mUnk_28);
    mobj_setModelNsbmaFrame(gMissionGate, missionGateObject->mNsbmaFrameIndex);
    mobj_renderModel(mapObjectList, gMissionGate, missionGateObject);
}

void mgat_globalInitLogic(MissionGateList *missionGateList) {
    s32 i;
    MissionGateObject *missionGateObject;

    if (missionGateList) {
        for (i = 0; i < missionGateList->mObjectCount && (missionGateObject = missionGateList->mObjects[i]) != NULL;
             i++) {
            if (missionGateObject->mMapObject.mCourseMapRow->mUnk_28 != 0) {
                missionGateObject->mMapObject.mFlags |= data_ov001_021a6580;
                missionGateObject->mState = 0;
            } else {
                missionGateObject->mMapObject.mFlags &= ~1;
                missionGateObject->mState = 1;
            }
        }
    }
}

void mgat_update(void *a, MissionGateObject *missionGateObject) {
    s32 count;

    switch (missionGateObject->mState) {
        case 0:
            count = gRaceMultiConfig->mMode == MODE_MISSION_RUN ? mrcnt_getCurrentValue() : 0;
            if (count >= missionGateObject->mMapObject.mCourseMapRow->mUnk_28 - 1) {
                missionGateObject->mMapObject.mFlags &= ~1;
                missionGateObject->mState = 1;
            }
            break;
        case 2:
            count = mobj_getModelNsbmaFrameCount(gMissionGate);
            missionGateObject->mNsbmaFrameIndex++;
            if (missionGateObject->mNsbmaFrameIndex >= count - 1) {
                missionGateObject->mNsbmaFrameIndex = mobj_getModelNsbmaFrameCount(gMissionGate) - 1;
                missionGateObject->mState = 1;
            }
            break;
    }
}

void mgat_setupCollision(void) {
    mobj_createConfig(&mgat_onDriverCollide, NULL, NULL, 0, 1);
}

void mgat_setupRenderPart(void) {
    mobj_createRenderPart3d(mgat_loadModel, mgat_render, mgat_globalPreRender);
}

void mgat_setupLogicPart(void) {
    mobj_createLogicPart(mgat_globalInitLogic, mgat_update, NULL);
}
