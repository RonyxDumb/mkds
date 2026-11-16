#pragma once

#include "types.h"
#include "Main/Scene/run_scene_connection.h" // SceneNumbers
#include "Main/Scene/scene_display_archive_work.h"
#include "Main/System/backup_net_camera_work.h"

// DispCap.mBlendFactor: full blend, and the change per frame while it grows (the weight of the captured frame
// rises) or falls.
#define DISP_CAP_BLEND_FACTOR_FULL TO_FIXED12(1)
#define DISP_CAP_BLEND_FACTOR_RISE_STEP FIXED12_RATIO(1, 10)
#define DISP_CAP_BLEND_FACTOR_FALL_STEP 0x802

// DispCap.mFlags: which VRAM bank pair the capture uses (flipped by ToggleDispCapBanks); the blend factor falls instead
// of rising; a fade started by StartDispCapFadeToFaded or StartDispCapFadeToClear runs (cleared once the brightness
// fades are clear); the fade flag (SetDispCapFadeFlag, not set on a child console; cleared with the run bit; a parent
// sends it to its children).
#define DISP_CAP_FLAG_BANK_SWAPPED 1
#define DISP_CAP_FLAG_BLEND_FALLING 2
#define DISP_CAP_FLAG_FADE_RUNNING 4
#define DISP_CAP_FLAG_FADE_FLAG 8

enum {
    DISP_CAP_MODE_OFF,
    DISP_CAP_MODE_BANK_TOGGLE,
    DISP_CAP_MODE_BLEND,
};

// Results of AdvanceConnectByMultiBoot besides 0 (still running): 1 connected, 2 not connected, 3 the connection ended
// with an error (the callers ignore 3).
#define CONNECT_ADVANCE_CONNECTED 1
#define CONNECT_ADVANCE_NOT_CONNECTED 2
#define CONNECT_ADVANCE_ERROR 3

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
