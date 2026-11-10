#pragma once

#include "types.h"

typedef struct SceneNumbers SceneNumbers;

unsigned int RaceSceneGetCurrentCourseId(void);
void SetNextRaceKind(unsigned int raceKind);
u32 RaceSceneIsSlotPairNew(u32 slotIndex);
unsigned int IsCameraChainEnded(void);
u32 RaceSceneSlotHasPairOrLost(u32 slotIndex);
u32 StartRaceSceneSound(u32 index);
u16 GetDownBits(u32 slotIndex, u32 mask);
unsigned int GetRaceSceneInputSlot(void);
void SetDemoEndedByInput(u32 endedByInput);
unsigned int GetCurrentRaceKind(void);
void SetNextSceneFromPickedValue(SceneNumbers *sceneNumbers, u32 pickedValue);
void SetPickedValue(unsigned int pickedValue);
unsigned int RaceSceneGetCurrentMode(void);
u32 ShouldEndStaffRoll(u32 sceneFrames);
u32 ShouldEndAwardRace(u32 sceneFrames);
void AdvanceDispCapAndUploadRaceHud(void);
void ReleaseRaceScene(void);
// Slot mInit of the Race scene; not the whole preparation (RunRaceScene and RunScene's prologue run
// before it). Calls in order: CreateOverlayExpHeap (creates the heap that FreeOverlayExpHeap destroys),
// StopWvrAndWait (kinds 3 and 5) or ClearLcdcBankAndStartWvrAndWait + func_02053e74, Init3dEngine, InitDispCap,
// SetupRaceDisplay (screen layout), func_020431e4, InitRace, InitChoisesS, InitRaceHud,
// SetupRaceHudScreens (not kind 3), SetLeftRightKeysSwapped, and the mode 5 net state / mode 2 StartMicInput
// extras. Does not allocate gRace: InitRace does.
void InitRaceScene(void);
void SetupRaceDisplay(void *heap);
u32 ShouldUpdateRace(u32 sceneFrames);
BOOL TryFormatGhostPath(u32 courseId, void *buffer, u32 size);
