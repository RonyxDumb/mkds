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
#include "Main/Sound/sound_falloffs_ortho_quad_globals.h"
#include "player.h"
#include "sound_archive_load.h"
#include "matrix44_concat.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "fx_mtx33.h"
#include "vector_math.h"
#include "Main/MapObjects/map_objects_get.h"
#include "Main/MapObjects/dram_draw_list_initial.h"

MapObjectList *gDramUpdateList;
MapObjectDrawList *gDramDrawList;
struct Nsbmd *gDram;

const u16 gDramAngleChoiceRows[6][3] = {{0, 1, 2}, {2, 0, 1}, {1, 2, 0}, {0, 2, 1}, {1, 0, 2}, {2, 1, 0}};

MapObjectKindData *CreateDramKindData(void) {
    MapObjectKindData *block;

    block = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(*block));
    {
        MapObjectKindData zeroBlock = {0};

        *block = zeroBlock;
    }
    return block;
}

MapObjectList *CreateDramUpdateList(void) {
    MapObjectList *block;

    block = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(*block));
    gDramUpdateList = block;
    *block = gDramUpdateListInitial;
    SetUpdateListSlot(&gDramUpdateList);
    return gDramUpdateList;
}

MapObjectDrawList *CreateDramDrawList(void) {
    MapObjectDrawList *block;

    block = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(*block));
    gDramDrawList = block;
    *block = gDramDrawListInitial;
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
        if (dram->mMapObject.mStateMachine.mState != DRAM_STATE_IDLE) {
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
        dram->mMapObject.mStateMachine.mNextState = DRAM_STATE_WAIT_DELAY;
        dram->mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

void UpdateDram(u32 unused, Dram *dram) {
    AdvanceStateMachine(&dram->mMapObject.mStateMachine);
}

void DramWaitDelayNop(void *stateObject) {}

void UpdateDramWaitDelay(void *stateObject) {
    Dram *dram = stateObject;
    if (dram->mMapObject.mStateMachine.mStateFrames > dram->mDelayFrameCount) {
        dram->mMapObject.mStateMachine.mNextState = DRAM_STATE_RAMP_UP;
        dram->mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

void EnterDramRampUp(void *stateObject) {
    Dram *dram = stateObject;
    dram->mRamp = 0x0u;
}

void UpdateDramRampUp(void *stateObject) {
    Dram *dram = stateObject;
    dram->mRamp += dram->mRampPerFrame;
    dram->mAngleX += (s16) (MUL_FIXED12_NO_ROUND(dram->mRamp, dram->mAnglePerFrame));
    if (dram->mMapObject.mStateMachine.mStateFrames > dram->mRampFrameCount) {
        dram->mMapObject.mStateMachine.mNextState = DRAM_STATE_STEADY;
        dram->mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

void DramSteadyNop(void *stateObject) {}

void UpdateDramSteady(void *stateObject) {
    Dram *dram = stateObject;
    dram->mAngleX += dram->mAnglePerFrame;
    if (dram->mSteadyFrameCount == 0) {
        return;
    }
    if (dram->mMapObject.mStateMachine.mStateFrames > dram->mSteadyFrameCount) {
        dram->mMapObject.mStateMachine.mNextState = DRAM_STATE_RAMP_DOWN;
        dram->mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

void EnterDramRampDown(void *stateObject) {
    Dram *dram = stateObject;
    dram->mRamp = 0x1000u;
}

void UpdateDramRampDown(void *stateObject) {
    Dram *dram = stateObject;
    s16 angleStep;

    dram->mRamp -= dram->mRampPerFrame;
    angleStep = MUL_FIXED12_NO_ROUND(dram->mRamp, dram->mAnglePerFrame);
    if (angleStep <= DRAM_MIN_ANGLE_STEP) {
        angleStep = DRAM_MIN_ANGLE_STEP;
    }
    dram->mAngleX += angleStep;
    if (dram->mMapObject.mStateMachine.mStateFrames > dram->mRampFrameCount) {
        dram->mMapObject.mStateMachine.mNextState = DRAM_STATE_ALIGN;
        dram->mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

void EnterDramAlign(void *stateObject) {
    Dram *dram = stateObject;
    s32 angle;

    angle = dram->mAngleX;
    dram->mAngleRemaining = DRAM_ALIGN_ANGLE - angle % DRAM_ALIGN_ANGLE;
}

// Asks for Idle once mAngleRemaining has run out.
void UpdateDramAlign(void *stateObject) {
    Dram *dram = stateObject;
    dram->mAngleX += DRAM_MIN_ANGLE_STEP;
    dram->mAngleRemaining -= DRAM_MIN_ANGLE_STEP;
    if (dram->mAngleRemaining >= 0) {
        return;
    }
    dram->mAngleX += dram->mAngleRemaining;
    dram->mMapObject.mStateMachine.mNextState = DRAM_STATE_IDLE;
    dram->mMapObject.mStateMachine.mNextStateRequested = 1;
}

const MapObjectKindDescriptor gDramKindDescriptor = {0,
                                                   {0, 0},
                                                   0xc0,
                                                   InitDram,
                                                   CreateDramKindData,
                                                   (MapObjectList * (*) (void) ) CreateDramDrawList,
                                                   0,
                                                   0,
                                                   CreateDramUpdateList};
