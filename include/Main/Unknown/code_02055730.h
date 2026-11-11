#pragma once

#include "types.h"
#include "Main/Unknown/code_020487fc.h" // SceneNumbers

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
