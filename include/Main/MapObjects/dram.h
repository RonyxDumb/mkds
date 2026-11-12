#pragma once

#include "types.h"

#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h"
#include "Main/MapObjects/data_02158000.h" // MapObjectDrawList

// Object of kind 0xd2 (Dram) and the functions of this file: 0xc0 bytes.
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

void UpdateDramState4(Dram *dram);
void EnterDramState5(Dram *dram);

void UpdateDramState5(Dram *dram);

typedef struct Dram Dram;

void EnterDramState4(Dram *dram);

void UpdateDramState3(Dram *dram);

unsigned int DramState3ReturnArgument(unsigned int value);

void UpdateDramState2(Dram *dram);

void EnterDramState2(Dram *dram);

void UpdateDramState0(Dram *dram);

unsigned int DramState0ReturnArgument(unsigned int value);

void UpdateDram(u32 unused,
                Dram *dram); /* the whole per-object step; the group also has a pre-step, PickDramAngleChoices */

extern MapObjectDrawList *gDramDrawList;

extern MapObjectDrawList data_0215a100;

extern MapObjectList *gDramUpdateList;

extern struct Nsbmd *gDram;

MapObjectKindData *CreateDramKindData(void);
MapObjectDrawList *CreateDramDrawList(void);
MapObjectList *CreateDramUpdateList(void);
void DrawDram(void *unusedFirst, Dram *dram, void *unusedThird, s32 maxAlpha);
void PickDramAngleChoices(MapObjectList *list);

extern const u16 gDramAngleChoiceRows[6][3];
