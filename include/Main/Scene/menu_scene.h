#pragma once

#include "types.h"
#include "Main/Scene/scene_display_archive_work.h"

// Fade frames of the staff roll and the award scene (SceneCallbacks.mFadeToClearFrameCount, mFadeToFadedFrameCount).
#define STAFF_ROLL_FADE_TO_FADED_FRAMES 0x78
#define AWARD_FADE_TO_CLEAR_FRAMES 0x3c
#define AWARD_FADE_TO_FADED_FRAMES 0x78

typedef struct SceneNumbers SceneNumbers;
typedef struct NNSiFndHeapHead NNSiFndHeapHead;

u32 AllocateHeapsAndBuffers(NNSiFndHeapHead *heap, void **outBackHeap, void **outSoundBuffer,
                                      void **outFirstFrontHeap, void **outSecondFrontHeap, void **outThirdFrontHeap);
// Scene function of g_SceneFnTable[1] (scene 'Menu' in g_SceneArchiveNameTable): copies the callbacks and calls
// OnSceneLoop. Returns 0. Scene 4 (SceneFn_Menu2) also carries the name 'Menu'.
u32 SceneFn_Menu(SceneNumbers *sceneNumbers);
void Scene_Menu_Update(void);
void Scene_Menu_VBlank(void);
// Slot mRelease: releases the current screen (ReleaseMenu, clears g_GlobalB43C), clears bit 0 of
// g_GlobalP.mDemoEndedByInput and, in mode 1, resets the CPU entries 1..7 of mNextEntries
// (ResetRacersForTimeTrial).
void Scene_Menu_Finalize(void);
// Wrapper of Scene_Menu_InitializeImpl_from_thumb, which allocates g_GlobalB43C and loads the single_play_select_mode
// files.
void Scene_Menu_Initialize(void);
// Scene function of g_SceneFnTable[2] (scene 'Race' in g_SceneArchiveNameTable): copies the callbacks and calls
// OnSceneLoop. Returns 0. First calls PrepareRace and MaybeReloadRacersSfx(1), then patches the copy: mode
// 5 sets flag 0x1c, kinds 5 / 6 set the fade lengths.
u32 SceneFn_Race(SceneNumbers *sceneNumbers);
void Scene_Race_PostSleep(void);
void Scene_Race_PreSleep(void);
// Slot mUpdate of the Race scene: end-of-race and next-scene logic (writes mNextScene 0, 2, 0xa,
// 0xf), UpdateRace (only if ShouldUpdateRace allows: in kind 6 after 0x708 frames) and the step
// SomeUpdateFn of the screen objects (kind 3 RaceStartGp, kind 6 EndingStaffRoll, else the RaceHud elements), both
// behind IsDataSharingIncomplete / Struct5624_HasXflag1, then RaceRenderingFogRelated (own gate: not in kind 6
// before 0x708 frames, not in mode 5 while IsFrameSpanningVBlank is set) and the matching draw DrawRaceHud. With a ==
// NULL (fade-out loop) only the draw and the upload part run. Slot 0x0c (Scene_Race_VBlank) is the second
// per-frame step.
void Scene_Race_Update(SceneNumbers *sceneNumbers, u32 sceneFrames);

extern SceneCallbacks g_Scene_Menu;
