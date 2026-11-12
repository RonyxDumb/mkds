#include "01/code_02185b64.h"

#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_0209bef0.h"
#include "01/callees_0219b000.h"
#include "01/code_02185ef4.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Kart/kart_drift.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/MapObjects/bound.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020a100c.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/MapObjects/map_object_create.h"
#include "Main/Unknown/code_020d3000.h"
#include "Main/Item/item_koura_w.h"
#include "Main/Unknown/code_02146000.h"
#include "code_02146cbc.h"
#include "code_02147cd8.h"
#include "ITCM/code_01ff8000.h"

MapObjectModel *gMissionGate;

void InitMissionGate(MissionGateObject *missionGateObject) {
    MtxFx33 mtx;
    s32 sideExtentX;
    s32 sideExtentY;
    s16 saved;

    RefreshMapObjectMatrixFromHitNormal(&missionGateObject->mMapObject);
    missionGateObject->mMapObject.mAngle =
        (missionGateObject->mMapObject.mCourseMapRow->mRotationDegrees.y * 0xB60B60B60BLL + 0x80000000000LL) >> 44;
    MTX_RotY33_(&mtx, FX_SinIdx(missionGateObject->mMapObject.mAngle), FX_CosIdx(missionGateObject->mMapObject.mAngle));
    MTX_Concat33(&mtx, &missionGateObject->mMapObject.mMatrix.mAxes, &missionGateObject->mMapObject.mMatrix.mAxes);
    sideExtentX = MUL_FIXED12_NO_ROUND(0xA000, missionGateObject->mMapObject.mScale.x);
    sideExtentY = MUL_FIXED12_NO_ROUND(0xF000, missionGateObject->mMapObject.mScale.y);
    saved = missionGateObject->mMapObject.mCourseMapRow->mSettings[0];
    missionGateObject->mMapObject.mCourseMapRow->mSettings[0] = 0x12;
    missionGateObject->mNegativeSideObject = CreateMapObjectFromObject(&missionGateObject->mMapObject, 0x66);
    missionGateObject->mPositiveSideObject = CreateMapObjectFromObject(&missionGateObject->mMapObject, 0x66);
    missionGateObject->mMapObject.mCourseMapRow->mSettings[0] = saved;
    VEC_MultAdd(-(missionGateObject->mMapObject.mExtent.x + sideExtentX),
                &missionGateObject->mMapObject.mMatrix.mRows[0], &missionGateObject->mMapObject.mPos,
                &missionGateObject->mNegativeSideObject->mPos);
    VEC_MultAdd(missionGateObject->mMapObject.mExtent.x + sideExtentX, &missionGateObject->mMapObject.mMatrix.mRows[0],
                &missionGateObject->mMapObject.mPos, &missionGateObject->mPositiveSideObject->mPos);
    SetMapObjectExtentX(missionGateObject->mNegativeSideObject, sideExtentX);
    SetMapObjectExtentX(missionGateObject->mPositiveSideObject, sideExtentX);
    SetMapObjectExtentY(missionGateObject->mNegativeSideObject, sideExtentY);
    SetMapObjectExtentY(missionGateObject->mPositiveSideObject, sideExtentY);
}

u32 CollideKartWithMissionGate(MissionGateObject *missionGateObject, Kart *kart, u8 *firstResponsePointer,
                               u8 *responsePointer) {
    u32 firstResponse = *firstResponsePointer;
    u32 response = *responsePointer;

    if ((kart->mDriveFlags & KART_DRIVE_OBJECTS_SKIP) != 0 ||
        (gRaceSetup->mMode == MODE_MISSION_RUN ? IsKartEliminated(kart->mIndex) : 0) != FALSE) {
        return 0;
    }
    if (firstResponse == 1) {
        missionGateObject->mMapObject.mFlags |= gMissionGateMapObjectFlag;
        missionGateObject->mState = 2;
    }
    return response;
}

void LoadMissionGate(void *mapObjectList) {
    gMissionGate = LoadMapObjectModelAnimated(mapObjectList, "MissionGate.nsbmd");
    LoadMapObjectModelNsbtpAnimation(gMissionGate, "MissionGate.nsbtp");
    LoadMapObjectModelNsbmaAnimation(gMissionGate, "MissionGate.nsbma");
    SetMapObjectModelPolygonId(gMissionGate, 0x3f);
    SetMapObjectModelLightEnableFlag(gMissionGate, 2);
    SetNsbmdEmiAll(gMissionGate->mAnimatedModel, 0x294a);
}

void MissionGateNop(void) {}

void DrawMissionGate(void *mapObjectList, MissionGateObject *missionGateObject) {
    s32 buf;

    buf = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &buf, 1);
    missionGateObject->mMapObject.mMatrix.mRows[3].x = missionGateObject->mMapObject.mPos.x >> 4;
    missionGateObject->mMapObject.mMatrix.mRows[3].y = missionGateObject->mMapObject.mPos.y >> 4;
    missionGateObject->mMapObject.mMatrix.mRows[3].z = missionGateObject->mMapObject.mPos.z >> 4;
    NNS_G3dGeBufferOP_N(0x19, &missionGateObject->mMapObject.mMatrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &missionGateObject->mMapObject.mScale, 3);
    SetMapObjectModelNsbtpFrameIndex(gMissionGate, missionGateObject->mMapObject.mCourseMapRow->mSettings[0]);
    SetMapObjectModelNsbmaFrameIndex(gMissionGate, missionGateObject->mNsbmaFrameIndex);
    DrawMapObjectModel(mapObjectList, gMissionGate, missionGateObject);
}

void InitMissionGateObjects(MapObjectList *missionGateList) {
    s32 gateIndex;
    MissionGateObject *missionGateObject;

    if (missionGateList) {
        for (gateIndex = 0; gateIndex < missionGateList->mMapObjectCount &&
                            (missionGateObject = missionGateList->mMapObjects[gateIndex]) != NULL;
             gateIndex++) {
            if (missionGateObject->mMapObject.mCourseMapRow->mSettings[0] != 0) {
                missionGateObject->mMapObject.mFlags |= gMissionGateMapObjectFlag;
                missionGateObject->mState = 0;
            } else {
                missionGateObject->mMapObject.mFlags &= ~1;
                missionGateObject->mState = 1;
            }
        }
    }
}

void UpdateMissionGate(void *unused, MissionGateObject *missionGateObject) {
    s32 count;

    switch (missionGateObject->mState) {
        case 0:
            count = gRaceSetup->mMode == MODE_MISSION_RUN ? GetMissionRunCount() : 0;
            if (count >= missionGateObject->mMapObject.mCourseMapRow->mSettings[0] - 1) {
                missionGateObject->mMapObject.mFlags &= ~1;
                missionGateObject->mState = 1;
            }
            break;
        case 2:
            count = GetMapObjectModelNsbmaFrameCount(gMissionGate);
            missionGateObject->mNsbmaFrameIndex++;
            if (missionGateObject->mNsbmaFrameIndex >= count - 1) {
                missionGateObject->mNsbmaFrameIndex = GetMapObjectModelNsbmaFrameCount(gMissionGate) - 1;
                missionGateObject->mState = 1;
            }
            break;
    }
}

void CreateMissionGateKindData(void) {
    CreateMapObjectKindData(&CollideKartWithMissionGate, NULL, NULL, 0, 1);
}

void CreateMissionGateDrawList(void) {
    CreateMapObjectDrawList1(LoadMissionGate, DrawMissionGate, MissionGateNop);
}

void CreateMissionGateUpdateList(void) {
    CreateMapObjectUpdateList(InitMissionGateObjects, UpdateMissionGate, NULL);
}
