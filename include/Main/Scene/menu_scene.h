#pragma once

#include "types.h"
#include "Main/Menu/data_02175000.h"

typedef struct SceneNumbers SceneNumbers;
typedef struct NNSiFndHeapHead NNSiFndHeapHead;

u32 CreateFrmHeapsAndAllocSoundBuffer(NNSiFndHeapHead *heap, void **outBackHeap, void **outSoundBuffer,
                                      void **outFirstFrontHeap, void **outSecondFrontHeap, void **outThirdFrontHeap);
// Scene function of gSceneFuncs[1] (scene 'Menu' in gSceneNames): copies the callbacks and calls
// RunScene. Returns 0. Scene 4 (RunSecondMenuScene) also carries the name 'Menu'.
u32 RunMenuScene(SceneNumbers *sceneNumbers);
void UpdateMenuScene(void);
void WriteMenuSceneRegistersCallback(void);
// Slot mRelease: releases the current screen (ReleaseMenu, clears gMenuScene), clears bit 0 of
// gStartupWork.mDemoEndedByInput and, in mode 1, resets the CPU entries 1..7 of mNextEntries
// (ResetTimeAttackNextEntries).
void ReleaseMenuScene(void);
// Wrapper of InitMenu, which allocates gMenuScene and loads the single_play_select_mode
// files.
void InitMenuScene(void);
// Scene function of gSceneFuncs[2] (scene 'Race' in gSceneNames): copies the callbacks and calls
// RunScene. Returns 0. First calls SetCurrentRaceFromNext and LoadSndBanksForCharacters(1), then patches the copy: mode
// 5 sets flag 0x1c, kinds 5 / 6 set the fade lengths.
u32 RunRaceScene(SceneNumbers *sceneNumbers);
void PostSleepRaceScene(void);
void PreSleepRaceScene(void);
// Slot mUpdate of the Race scene: end-of-race and next-scene logic (writes mNextScene 0, 2, 0xa,
// 0xf), UpdateRace (only if ShouldUpdateRace allows: in kind 6 after 0x708 frames) and the step
// UpdateRaceHud of the screen objects (kind 3 RaceStartGp, kind 6 EndingStaffRoll, else the RaceHud elements), both
// behind IsDataSharingIncomplete / IsInputOpenDuringRace, then DrawRace (own gate: not in kind 6
// before 0x708 frames, not in mode 5 while IsFrameSpanningVBlank is set) and the matching draw DrawRaceHud. With a ==
// NULL (fade-out loop) only the draw and the upload part run. Slot 0x0c (AdvanceDispCapAndUploadRaceHud) is the second
// per-frame step.
void UpdateRaceScene(SceneNumbers *sceneNumbers, u32 sceneFrames);

extern SceneCallbacks gMenuSceneCallbacks;
