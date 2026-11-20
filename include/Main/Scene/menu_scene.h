#pragma once

#include "types.h"
#include "Main/Scene/scene_display_archive_work.h"

// Fade frames of the staff roll and the award scene (SceneCallbacks.mFadeToClearFrameCount, mFadeToFadedFrameCount).
#define STAFF_ROLL_FADE_TO_FADED_FRAMES 0x78
#define AWARD_FADE_TO_CLEAR_FRAMES 0x3c
#define AWARD_FADE_TO_FADED_FRAMES 0x78

typedef struct SceneNumbers SceneNumbers;
typedef struct NNSiFndHeapHead NNSiFndHeapHead;

u32 CreateFrmHeapsAndAllocSoundBuffer(NNSiFndHeapHead *heap, void **outBackHeap, void **outSoundBuffer,
                                      void **outFirstFrontHeap, void **outSecondFrontHeap, void **outThirdFrontHeap);
// Scene function of gSceneFuncs[1] (scene 'Menu' in gSceneNames): copies the callbacks and calls
// RunScene. Returns 0. Scene 4 (RunSecondMenuScene) also carries the name 'Menu'.
u32 RunMenuScene(SceneNumbers *sceneNumbers);
void UpdateMenuScene(void);
void WriteMenuSceneRegistersCallback(void);
// Slot mRelease: ReleaseMenu (releases the current screen unless its set-up is still pending, clears gMenuScene),
// clears bit 0 of gStartupWork->mDemoEndedByInput and, for a time attack next setup, sets mNextHeader.mRaceKind to
// normal and resets entries 1..7 of mNextEntries (ResetTimeAttackNextEntries).
void ReleaseMenuScene(void);
// Wrapper of InitMenu, which allocates gMenuScene, sets up the display and, unless booted as a multiboot child, loads
// the kart model files and the single_play_select_mode files.
void InitMenuScene(void);
// Scene function of gSceneFuncs[2] (scene 'Race' in gSceneNames): copies the callbacks, calls SetCurrentRaceFromNext,
// then patches the copy (MODE_WIFI sets mSkipWhenSpanned, the award and staff roll kinds set the fade lengths), calls
// LoadSndBanksForCharacters(1) unless booted as multiboot, and calls RunScene. Returns 0.
u32 RunRaceScene(SceneNumbers *sceneNumbers);
void PostSleepRaceScene(void);
void PreSleepRaceScene(void);
// Slot mUpdate of the Race scene: end-of-race and next-scene logic (writes mNextScene 0, 2, 0xa, 0xf; skipped when
// sceneNumbers is NULL in the fade-out loop), UpdateRace (only if ShouldUpdateRace allows: in kind 6 after 0x708
// frames) and UpdateRaceHud (kind 3 RaceStartGp, kind 6 EndingStaffRoll, else the RaceHud elements), both behind
// IsDataSharingIncomplete / IsInputOpenDuringRace, then UpdateRaceHudSubScreen and the choises_s update, then DrawRace
// (not in kind 6 before 0x708 frames, not in mode 5 while IsFrameSpanningVBlank is set) and DrawRaceHud. The
// mPostUpdate slot (AdvanceDispCapAndUploadRaceHud) is the second per-frame step.
void UpdateRaceScene(SceneNumbers *sceneNumbers, u32 sceneFrames);

extern SceneCallbacks gMenuSceneCallbacks;
