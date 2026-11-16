#pragma once

#include "types.h"

typedef struct SceneNumbers SceneNumbers;
typedef struct NNSiFndHeapHead NNSiFndHeapHead;

// Object whose halfword at 0x04 racesc_update and race_handleMenuOption write.
typedef struct Unk0203a0dc {
    /* 00 */ u8 field0[0x4];
    /* 04 */ u16 mNextScene;
} Unk0203a0dc;

u32 func_02039e08(NNSiFndHeapHead *heap, void **outBackHeap, void **outSoundBuffer, void **outFirstFrontHeap,
                  void **outSecondFrontHeap, void **outThirdFrontHeap);
// Scene function of scproc_sSceneTable[1] (scene 'Menu' in sSceneDefs): copies the callbacks and calls
// scene_runScene. Returns 0. Scene 4 (menu2_run) also carries the name 'Menu'.
u32 menu_run(SceneNumbers *sceneNumbers);
void menudef_render(void);
void menudef_vblank(void);
// Slot mRelease: releases the current screen (ReleaseMenu, clears gMenuSceneState), clears bit 0 of
// gSystemData->field50 and, in mode 1, resets the CPU entries 1..7 of mNextEntries
// (ResetTimeAttackNextEntries).
void menudef_finish(void);
// Wrapper of menu_create, which allocates gMenuSceneState and loads the single_play_select_mode
// files.
void menudef_create(void);
// Scene function of scproc_sSceneTable[2] (scene 'Race' in sSceneDefs): copies the callbacks and calls
// scene_runScene. Returns 0. First calls rconf_setupNext and rconf_loadCharacterSounds(1), then patches the copy: mode
// 5 sets flag 0x1c, kinds 5 / 6 set the fade lengths.
u32 race_run(SceneNumbers *sceneNumbers);
void racesc_postSleep(void);
void racesc_preSleep(void);
// Slot mUpdate of the Race scene: end-of-race and next-scene logic (writes mNextScene 0, 2, 0xa,
// 0xf), race_update (only if race_getShouldUpdate allows: in kind 6 after 0x708 frames) and the step
// race_update2d of the screen objects (kind 3 RaceStartGp, kind 6 EndingStaffRoll, else the RaceHud elements), both
// behind scene_areUpdatesSuspended / input_getFlagsBit0, then race_render (own gate: not in kind 6
// before 0x708 frames, not in mode 5 while dc_getFlagsBit1 is set) and the matching draw r2d_render. With a == NULL
// (fade-out loop) only the draw and the upload part run. Slot 0x0c (racesc_vblank) is the second
// per-frame step.
void racesc_update(Unk0203a0dc *sceneNumbers, u32 sceneFrames);
