#include "Main/MapObjects/dram.h"
#include "Main/MapObjects/map_object_kind_update_list.h"
#include "Main/Item/dram_box.h"
#include "Main/System/heap.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/MapObjects/woodbox.h"

#include "Main/MapObjects/map_object_park.h"
#include "Main/System/heap_call.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/update_list_slot.h"
#include "Main/MapObjects/data_0217c000.h"
#include "player.h"
#include "code_0212d214.h"
#include "code_021479b4.h"
#include "Main/Item/code_021035ac.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/Item/data_0215a000.h"
#include "fx_mtx33.h"
#include "code_02147cd8.h"

const u16 gDramAngleChoiceRows[6][3] = {{0, 1, 2}, {2, 0, 1}, {1, 2, 0}, {0, 2, 1}, {1, 0, 2}, {2, 1, 0}};

MapObjectKindData *CreateDramKindData(void) {
    MapObjectKindData *block;

    block = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);
    {
        MapObjectKindData zeroBlock = {0};

        *block = zeroBlock;
    }
    return block;
}

MapObjectList *CreateDramUpdateList(void) {
    MapObjectList *block;

    block = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x28);
    gDramUpdateList = block;
    *block = data_0215a12c;
    SetUpdateListSlot(&gDramUpdateList);
    return gDramUpdateList;
}

MapObjectDrawList *CreateDramDrawList(void) {
    MapObjectDrawList *block;

    block = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
    gDramDrawList = block;
    *block = data_0215a100;
    SetDrawListSlot(&gDramDrawList);
    return gDramDrawList;
}

void DrawDram(void *unusedFirst, Dram *dram, void *unusedThird, s32 maxAlpha) {
    MtxFx43 *matrix;
    s32 angle;

    matrix = &dram->mMapObject.mMatrix;
    angle = (u16) (-(s32) dram->mAngleX);
    MTX_RotX33_(&matrix->mAxes, SIN_OF_ANGLE(angle), COS_OF_ANGLE(angle));
    matrix->mRows[3].x = dram->mMapObject.mPos.x >> 4;
    matrix->mRows[3].y = dram->mMapObject.mPos.y >> 4;
    matrix->mRows[3].z = dram->mMapObject.mPos.z >> 4;
    DrawNsbmdWithMatrixAndMaxAlpha(gDram, matrix, &dram->mMapObject.mScale, maxAlpha);
}

void PickDramAngleChoices(MapObjectList *list) {
    RandomState64 *random;
    void **dramObjects;
    Dram *dram;
    const u16 *row;
    s32 count, index;
    u16 rowIndex;

    count = list->mMapObjectCount;
    dramObjects = list->mMapObjects;
    for (index = 0; index < count; index++) {
        dram = dramObjects[index];
        if (dram->mMapObject.mStateMachine.mState != 1) {
            return;
        }
    }
    random = GetMapObjectRandom();
    random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
    rowIndex = ((u64) (u32) (random->mValue >> 32) * 6) >> 32;
    for (index = 0; index < count; index++) {
        dram = dramObjects[index];
        row = gDramAngleChoiceRows[rowIndex];
        dram->mAnglePerFrame = dram->mAnglePerFrameChoices[row[index]];
        dram->mMapObject.mStateMachine.mNextState = 0;
        dram->mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

void UpdateDram(u32 unused, Dram *dram) {
    AdvanceStateMachine(&dram->mMapObject.mStateMachine);
}

u32 DramState0ReturnArgument(u32 value) {
    return value;
}

void UpdateDramState0(Dram *dram) {
    if (dram->mMapObject.mStateMachine.mStateFrames > dram->mDelayFrameCount) {
        dram->mMapObject.mStateMachine.mNextState = 2;
        dram->mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

void EnterDramState2(Dram *dram) {
    dram->mRamp = 0x0u;
}

void UpdateDramState2(Dram *dram) {
    dram->mRamp += dram->mRampPerFrame;
    dram->mAngleX += (s16) (MUL_FIXED12_NO_ROUND(dram->mRamp, dram->mAnglePerFrame));
    if (dram->mMapObject.mStateMachine.mStateFrames > dram->mRampFrameCount) {
        dram->mMapObject.mStateMachine.mNextState = 3;
        dram->mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

u32 DramState3ReturnArgument(u32 value) {
    return value;
}

void UpdateDramState3(Dram *dram) {
    dram->mAngleX += dram->mAnglePerFrame;
    if (dram->mSteadyFrameCount == 0) {
        return;
    }
    if (dram->mMapObject.mStateMachine.mStateFrames > dram->mSteadyFrameCount) {
        dram->mMapObject.mStateMachine.mNextState = 4;
        dram->mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

void EnterDramState4(Dram *dram) {
    dram->mRamp = 0x1000u;
}

void UpdateDramState4(Dram *dram) {
    s16 angleStep;

    dram->mRamp -= dram->mRampPerFrame;
    angleStep = MUL_FIXED12_NO_ROUND(dram->mRamp, dram->mAnglePerFrame);
    if (angleStep <= 0x96) {
        angleStep = 0x96;
    }
    dram->mAngleX += angleStep;
    if (dram->mMapObject.mStateMachine.mStateFrames > dram->mRampFrameCount) {
        dram->mMapObject.mStateMachine.mNextState = 5;
        dram->mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

void EnterDramState5(Dram *dram) {
    s32 angle;

    angle = dram->mAngleX;
    dram->mAngleRemaining = 0x1999 - angle % 0x1999;
}

// Asks for state 1 once mAngleRemaining has run out.
void UpdateDramState5(Dram *dram) {
    dram->mAngleX += 0x96;
    dram->mAngleRemaining -= 0x96;
    if (dram->mAngleRemaining >= 0) {
        return;
    }
    dram->mAngleX += dram->mAngleRemaining;
    dram->mMapObject.mStateMachine.mNextState = 1;
    dram->mMapObject.mStateMachine.mNextStateRequested = 1;
}

const MapObjectKindDescriptor gDramKindDescriptor = {0,
                                                   {0, 0},
                                                   0xc0,
                                                   (void (*)(void *, CourseMapRow *, void *)) InitDram,
                                                   CreateDramKindData,
                                                   (MapObjectList * (*) (void) ) CreateDramDrawList,
                                                   0,
                                                   0,
                                                   CreateDramUpdateList};
