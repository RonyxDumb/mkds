#include "Main/Unknown/code_020da414.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_020d8cac.h"
#include "Main/System/Heap.h"
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

// placeholder: an object of the original file that is not known yet; it only sets the order of the tables below
const u8 data_020da414_pad[1] = {1};

#pragma thumb on

void kuribo_init(Kuribo *kuribo, CourseMapRow *row) {
    CourseMapGroupEntry *startEntry;
    Vec3 *zeroedVector;
    Unk020e005c_080 *stateMachine;
    kuribo->field100 = 0x1f;
    if (row != NULL) {
        pw_initFromObject(&kuribo->fieldCC, row, (row->field28 << 11) / 100);
        startEntry = mdat_getPathPoint(row->field26, row->field2E);
        kuribo->fieldA0 = startEntry->mPos.y;
        kuribo->fieldF8 = row->field28 * 0xb4 / 100;
        kuribo->fieldFC = row->field2A == 0;
        sm_init(&kuribo->field0.mStateMachine, kuribo_sStates, 6, kuribo);
        pw_init(&kuribo->fieldCC, kuribo->field0.mCourseMapRow->field2E, 1);
        pw_calcCurrentPointXZ(&kuribo->fieldCC, &kuribo->field0.mPos);
        kuribo->field0.mPos.y = kuribo->fieldA0;
        zeroedVector = &kuribo->field0.field10;
        zeroedVector->x = 0;
        zeroedVector->y = 0;
        zeroedVector->z = 0;
        {
            Quaternion identityA = {0, 0, 0, 0x1000};
            kuribo->fieldA4 = identityA;
        }
        {
            Quaternion identityB = {0, 0, 0, 0x1000};
            kuribo->fieldB4 = identityB;
        }
        kuribo->fieldF0 = 0;
        kuribo->fieldF4 = 0;
        stateMachine = &kuribo->field0.mStateMachine;
        stateMachine->mNextState = 0;
        stateMachine->mNextStateRequested = 1;
    } else {
        kuribo->fieldCC.mGroupIndex = 0xffff;
        kuribo->fieldA0 = 0;
        kuribo->fieldFC = 0;
        sm_init(&kuribo->field0.mStateMachine, kuribo_sStates, 6, kuribo);
        kuribo->fieldF8 = 0x1000;
        {
            Quaternion identityA = {0, 0, 0, 0x1000};
            kuribo->fieldA4 = identityA;
        }
        {
            Quaternion identityB = {0, 0, 0, 0x1000};
            kuribo->fieldB4 = identityB;
        }
        sm_gotoState(&kuribo->field0.mStateMachine, 1);
        kuribo->field0.field10.x = 0;
        kuribo->field0.field10.y = 0;
        kuribo->field0.field10.z = 0;
    }
}

#pragma thumb off

Unk020da414 *water_setupWaterCollision(void) {
    Unk020da414 *object;
    object = heap_alloc(proc_getHeap(proc_getCurrent()), 0x40);
    {
        Unk020da414 zeros = {0};
        *object = zeros;
    }
    return object;
}
