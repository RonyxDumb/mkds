#pragma once

#include "types.h"

typedef struct SceneNumbers SceneNumbers;

unsigned int GetCurrentInternalCourseId(void);
void SetNextRaceDisplayMode(unsigned int raceKind);
u32 AnotherHasTouchPressed(u32 slotIndex);
unsigned int IsRaceIntroInFadeOut(void);
u32 HasTouchPressed(u32 slotIndex);
u32 MaybePlaySseqFromSarc0(u32 index);
u16 TestInputKeys(u32 slotIndex, u32 mask);
unsigned int GetSomeCYId_8(void);
void SetGlobalP_BFlagBit1(u32 endedByInput);
unsigned int GetDisplayMode(void);
void SetNextSceneFromPickedValue(SceneNumbers *sceneNumbers, u32 pickedValue);
void SetPickedValue(unsigned int pickedValue);
unsigned int GetCurrentRaceMode_1(void);
u32 CheckIsEnding(u32 sceneFrames);
u32 ShouldEndAwardRace(u32 sceneFrames);
void Scene_Race_VBlank(void);
void Scene_Race_Finalize(void);
// Slot mInit of the Race scene; not the whole preparation (SceneFn_Race and OnSceneLoop's prologue run
// before it). Calls in order: CreateRegionHeapHandleForOverlay1 (creates the heap that DisposeOverlayManagerHeap destroys),
// MaybeInitializeSomeWirelessShit (kinds 3 and 5) or SomeVramConfig + InitRaceConnection, Init3dEngine, InitializeGlobalAA04,
// SetGlobalDisplayConfigForDisplayMode (screen layout), ResetInputSlotsFromRaceSetup, InitializeGlobalTD, LoadRaceOptionMenus_from_thumb, InitRaceHud,
// SetupRaceHudScreens (not kind 3), SetLeftRightKeysSwapped, and the mode 5 net state / mode 2 CreateGlobal59C4Sub
// extras. Does not allocate g_GlobalTD: InitializeGlobalTD does.
void Scene_Race_Initialize(void);
void SetGlobalDisplayConfigForDisplayMode(void *heap);
u32 ShouldUpdateRace(u32 sceneFrames);
BOOL FindFormatGhostBinPath(u32 courseId, void *buffer, u32 size);
