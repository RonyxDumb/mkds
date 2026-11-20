#pragma once

#include "types.h"

#include "matrix_3x3_basic.h"
#include "Main/MapObjects/attractor.h"
#include "Main/MapObjects/map_object_draw_list_flags.h" // MapObjectDrawList

// Dram state machine states, in the order of gDramStateTable.
#define DRAM_STATE_WAIT_DELAY 0
#define DRAM_STATE_IDLE 1 // waits until every Dram is idle, then PickDramAngleChoices restarts them
#define DRAM_STATE_RAMP_UP 2
#define DRAM_STATE_STEADY 3
#define DRAM_STATE_RAMP_DOWN 4
#define DRAM_STATE_ALIGN 5 // turns on to a multiple of DRAM_ALIGN_ANGLE

#define DRAM_ALIGN_ANGLE 0x1999
#define DRAM_MIN_ANGLE_STEP 0x96
// Dram.mRamp at full turning speed; mRampPerFrame is this divided by mRampFrameCount (0 when that is 0).
#define DRAM_RAMP_FULL 0x1000

// A Dram map object: its ramp, steady and delay frame counts, its turning angle and speed, the speed choices and the
// angle left to align.
typedef struct Dram {
    /* 00 */ MapObject mMapObject;
    /* a0 */ u16 mRampFrameCount;
    /* a2 */ u16 mSteadyFrameCount;
    /* a4 */ u16 mDelayFrameCount;
    /* a6 */ u16 mAngleX;
    /* a8 */ s16 mAnglePerFrame;
    /* aa */ u8 mUnk_aa[2];
    /* ac */ s32 mRamp;
    /* b0 */ s32 mRampPerFrame;
    /* b4 */ s16 mAnglePerFrameChoices[3];
    /* ba */ u8 mUnk_ba[2];
    /* bc */ s32 mAngleRemaining;
} Dram;

void UpdateDramRampDown(void *stateObject);
void EnterDramAlign(void *stateObject);

void UpdateDramAlign(void *stateObject);

typedef struct Dram Dram;

void EnterDramRampDown(void *stateObject);

void UpdateDramSteady(void *stateObject);

void DramSteadyNop(void *stateObject);

void UpdateDramRampUp(void *stateObject);

void EnterDramRampUp(void *stateObject);

void UpdateDramWaitDelay(void *stateObject);

void DramWaitDelayNop(void *stateObject);

void UpdateDram(u32 unused,
                Dram *dram); /* the whole per-object step; the group also has a pre-step, PickDramAngleChoices */

extern MapObjectDrawList *gDramDrawList;

extern MapObjectList *gDramUpdateList;

extern struct Nsbmd *gDram;

MapObjectKindData *CreateDramKindData(void);
MapObjectDrawList *CreateDramDrawList(void);
MapObjectList *CreateDramUpdateList(void);
void DrawDram(void *unusedFirst, Dram *dram, void *unusedThird, s32 maxAlpha);
void PickDramAngleChoices(MapObjectList *list);

extern const u16 gDramAngleChoiceRows[6][3];
