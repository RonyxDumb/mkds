#include "Main/MapObjects/kuribo_init.h"
#include "Main/Item/item_koura_w.h"
#include "Main/MapObjects/segment_curve.h"
#include "Main/System/heap.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/System/heap_call.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/code_0205e000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/System/result_archive_path.h"
#include "Main/Unknown/code_020d4970.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_02084000.h"
#include "code_02013740.h"
#include "Main/Sound/sound_handle_pool.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Sound/distance_sound_volume.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/unk_02158000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0216b000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/System/state_machine_init.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/MapObjects/group_follower_init.h"
#include "Main/Unknown/code_020d8b88.h"

// Object not known yet; it only sets the order of the tables below
const u8 data_020da414_pad[1] = {1};

#pragma thumb on

void InitKuribo(Kuribo *kuribo, CourseMapRow *row) {
    CourseMapGroupEntry *startEntry;
    Vec3 *zeroedVector;
    StateMachine *stateMachine;
    kuribo->mModelAlpha = 0x1f;
    if (row != NULL) {
        InitGroupFollower(&kuribo->mFollower, row, (row->mSettings[0] << 11) / 100);
        startEntry = GetCourseMapGroupEntry(row->mGroupIndex, row->mSettings[3]);
        kuribo->mStartY = startEntry->mPos.y;
        kuribo->mOrientationBlendAmount = row->mSettings[0] * 0xb4 / 100;
        kuribo->mReturnsAfterWait = row->mSettings[1] == 0;
        InitStateMachine(&kuribo->mMapObject.mStateMachine, gKuriboStateTable, 6, kuribo);
        SetupGroupFollowerAtEntry(&kuribo->mFollower, kuribo->mMapObject.mCourseMapRow->mSettings[3], 1);
        GetGroupFollowerCurveXz(&kuribo->mFollower, &kuribo->mMapObject.mPos);
        kuribo->mMapObject.mPos.y = kuribo->mStartY;
        zeroedVector = &kuribo->mMapObject.mPosStep;
        zeroedVector->x = 0;
        zeroedVector->y = 0;
        zeroedVector->z = 0;
        {
            Quaternion identityA = {0, 0, 0, 0x1000};
            kuribo->mOrientation = identityA;
        }
        {
            Quaternion identityB = {0, 0, 0, 0x1000};
            kuribo->mTargetOrientation = identityB;
        }
        kuribo->mFrameIndex = 0;
        kuribo->mFrameRandomized = 0;
        stateMachine = &kuribo->mMapObject.mStateMachine;
        stateMachine->mNextState = 0;
        stateMachine->mNextStateRequested = 1;
    } else {
        kuribo->mFollower.mGroupIndex = 0xffff;
        kuribo->mStartY = 0;
        kuribo->mReturnsAfterWait = 0;
        InitStateMachine(&kuribo->mMapObject.mStateMachine, gKuriboStateTable, 6, kuribo);
        kuribo->mOrientationBlendAmount = 0x1000;
        {
            Quaternion identityA = {0, 0, 0, 0x1000};
            kuribo->mOrientation = identityA;
        }
        {
            Quaternion identityB = {0, 0, 0, 0x1000};
            kuribo->mTargetOrientation = identityB;
        }
        SetStateMachineState(&kuribo->mMapObject.mStateMachine, 1);
        kuribo->mMapObject.mPosStep.x = 0;
        kuribo->mMapObject.mPosStep.y = 0;
        kuribo->mMapObject.mPosStep.z = 0;
    }
}

#pragma thumb off

MapObjectKindData *CreateWaterKindData(void) {
    MapObjectKindData *object;
    object = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);
    {
        MapObjectKindData zeros = {0};
        *object = zeros;
    }
    return object;
}
