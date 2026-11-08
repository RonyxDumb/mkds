#include "Main/Unknown/code_020da414.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/code_0205e000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_020d4970.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_02084000.h"
#include "code_02013740.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/code_020a02c8.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/unk_02158000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0216b000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_020d7da8.h"
#include "Main/Unknown/code_020d8b88.h"

// Object not known yet; it only sets the order of the tables below
const u8 data_020da414_pad[1] = {1};

#pragma thumb on

void InitKuribo(Kuribo *kuribo, CourseMapRow *row) {
    CourseMapGroupEntry *startEntry;
    Vec3 *zeroedVector;
    Unk020e005c_080 *stateMachine;
    kuribo->mModelAlpha = 0x1f;
    if (row != NULL) {
        InitGroupFollower(&kuribo->mFollower, row, (row->mUnk_28 << 11) / 100);
        startEntry = GetCourseMapGroupEntry(row->mUnk_26, row->mUnk_2e);
        kuribo->mStartY = startEntry->mPos.y;
        kuribo->mOrientationBlendAmount = row->mUnk_28 * 0xb4 / 100;
        kuribo->mUnk_fc = row->mUnk_2a == 0;
        InitStateMachine(&kuribo->mMapObject.mStateMachine, data_0216be68, 6, kuribo);
        SetupGroupFollowerAtEntry(&kuribo->mFollower, kuribo->mMapObject.mCourseMapRow->mUnk_2e, 1);
        GetGroupFollowerCurveXz(&kuribo->mFollower, &kuribo->mMapObject.mPos);
        kuribo->mMapObject.mPos.y = kuribo->mStartY;
        zeroedVector = &kuribo->mMapObject.mUnk_10;
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
        kuribo->mUnk_fc = 0;
        InitStateMachine(&kuribo->mMapObject.mStateMachine, data_0216be68, 6, kuribo);
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
        kuribo->mMapObject.mUnk_10.x = 0;
        kuribo->mMapObject.mUnk_10.y = 0;
        kuribo->mMapObject.mUnk_10.z = 0;
    }
}

#pragma thumb off

Unk020da414 *func_020da414(void) {
    Unk020da414 *object;
    object = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);
    {
        Unk020da414 zeros = {0};
        *object = zeros;
    }
    return object;
}
