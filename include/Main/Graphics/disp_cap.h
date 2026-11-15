#pragma once

#include "types.h"
#include "Main/Scene/run_scene_connection.h" // SceneNumbers
#include "Main/Menu/data_02175000.h"
#include "Main/MapObjects/data_0217a000.h"

// DispCap.mBlendFactor: full blend, and the change per frame while it grows (the weight of the captured frame
// rises) or falls.
#define DISP_CAP_BLEND_FACTOR_FULL TO_FIXED12(1)
#define DISP_CAP_BLEND_FACTOR_RISE_STEP FIXED12_RATIO(1, 10)
#define DISP_CAP_BLEND_FACTOR_FALL_STEP 0x802

enum {
    DISP_CAP_MODE_OFF,
    DISP_CAP_MODE_BANK_TOGGLE,
    DISP_CAP_MODE_BLEND,
};

// Results of AdvanceConnectByMultiBoot besides 0 (still running): connected, connecting to the entry failed.
#define CONNECT_ADVANCE_CONNECTED 1
#define CONNECT_ADVANCE_CONNECT_FAILED 2

s32 AdvanceConnectByMultiBoot(u16 entryIndex);
s32 AdvanceSetupByMultiBoot(s32 isParent, s32 isMultiBoot);
s32 AdvanceNonMultiBootSetup(s32 isParent);
void StoreReceivedPlayerName(const void *entryName, s32 entryIndex, s32 keepMask);
// Scene function of gSceneFuncs[8] (scene 'Record' in gSceneNames): copies the callbacks and calls
// RunScene. Returns 0.
s32 RunRecordScene(SceneNumbers *sceneNumbers);
void SetDispCapFadeFlag(void);
BOOL IsDispCapFadeFlagSet(void);
BOOL IsSharedDispCapFadeFlagSet(void);
void StartDispCapFadeToClear(u32 frameCount);
void StartDispCapFadeToFaded(u32 frameCount);
void StopDispCapBlend(void);
void StartDispCapBlend(u8 blendMin);
void AdvanceDispCap(s32 prevMenuOpen);
void AdvanceDispCapBlend(s32 prevMenuOpen);
void ToggleDispCapBanks(void);
void SetupDispCap(void);
void SetupDispCapMode1(void);
void SetDispCapMode(s32 mode);
void ClearDispCapPointer(void);
void InitDispCap(void *heap);
u8 GetLowestGrandPrixRecordValue(void);

extern SceneCallbacks gRecordSceneCallbacks;
extern struct DispCap *gDispCap;
