#include "01/MapObjects/mission_gate.h"

#include "Main/MapObjects/map_object_model_frame.h"
#include "01/MapObjects/map_object_animation.h"
#include "01/MapObjects/mission_run_map_object_flags.h"
#include "Main/Kart/kart_drift.h"
#include "matrix_3x3_basic.h"
#include "Main/Course/course_map_group_entry.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/MapObjects/bound.h"
#include "Main/Race/standings_balloons.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/star_or_killer_hit_sound.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/map_object_list.h"
#include "Main/MapObjects/map_object.h"
#include "Main/MapObjects/map_object_create.h"
#include "Main/Item/item_koura_w.h"
#include "fixed_vector_math.h"
#include "ITCM/model_draw_and_irq_handler.h"

MapObjectKindDescriptor gMissionGateKindDescriptor = {0,
                                                      {0, 0},
                                                      0xcc,
                                                      InitMissionGate,
                                                      CreateMissionGateKindData,
                                                      CreateMissionGateDrawList,
                                                      NULL,
                                                      NULL,
                                                      CreateMissionGateUpdateList,
                                                      NULL,
                                                      {NULL, NULL, NULL, NULL}};
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
    missionGateObject->mMapObject.mCourseMapRow->mSettings[0] = MISSION_GATE_SIDE_OBJECT_SETTING;
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
        missionGateObject->mState = MISSION_GATE_STATE_PLAY_ANIMATION;
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
                missionGateObject->mState = MISSION_GATE_STATE_WAIT_COUNT;
            } else {
                missionGateObject->mMapObject.mFlags &= ~1;
                missionGateObject->mState = MISSION_GATE_STATE_DONE;
            }
        }
    }
}

void UpdateMissionGate(void *unused, MissionGateObject *missionGateObject) {
    s32 count;

    switch (missionGateObject->mState) {
        case MISSION_GATE_STATE_WAIT_COUNT:
            count = gRaceSetup->mMode == MODE_MISSION_RUN ? GetMissionRunCount() : 0;
            if (count >= missionGateObject->mMapObject.mCourseMapRow->mSettings[0] - 1) {
                missionGateObject->mMapObject.mFlags &= ~1;
                missionGateObject->mState = MISSION_GATE_STATE_DONE;
            }
            break;
        case MISSION_GATE_STATE_PLAY_ANIMATION:
            count = GetMapObjectModelNsbmaFrameCount(gMissionGate);
            missionGateObject->mNsbmaFrameIndex++;
            if (missionGateObject->mNsbmaFrameIndex >= count - 1) {
                missionGateObject->mNsbmaFrameIndex = GetMapObjectModelNsbmaFrameCount(gMissionGate) - 1;
                missionGateObject->mState = MISSION_GATE_STATE_DONE;
            }
            break;
    }
}

MapObjectKindData *CreateMissionGateKindData(void) {
    return CreateMapObjectKindData(&CollideKartWithMissionGate, NULL, NULL, 0, 1);
}

MapObjectList *CreateMissionGateDrawList(void) {
    return CreateMapObjectDrawList1(LoadMissionGate, DrawMissionGate, MissionGateNop);
}

MapObjectList *CreateMissionGateUpdateList(void) {
    return CreateMapObjectUpdateList(InitMissionGateObjects, UpdateMissionGate, NULL);
}

const u16 gMissionGateMapObjectFlag = 1;
