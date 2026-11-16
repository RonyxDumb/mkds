#pragma once

#include "types.h"

typedef struct Unk0203a0dc Unk0203a0dc;

unsigned int race_race_getCurrentCourse(void);
void race_race_setNextDisplayMode(unsigned int raceKind);
u32 AnotherHasTouchPressed(u32 slotIndex);
unsigned int IsCameraChainEnded(void);
u32 HasTouchPressed(u32 slotIndex);
u32 MaybePlaySseqFromSarc0(u32 index);
u16 GetDownBits(u32 slotIndex, u32 mask);
unsigned int race_input_getDefaultInputId(void);
void race_sysdat_setDemoRaceWasCanceled(u32 a);
unsigned int race_race_getCurrentDisplayMode(void);
void race_handleMenuOption(Unk0203a0dc *sceneNumbers, u32 pickedValue);
void race_sysdat_setActivatedRaceMenuOption(unsigned int pickedValue);
unsigned int race_race_getCurrentRaceMode(void);
u32 japdiff_203A908(u32 sceneFrames);
u32 ShouldEndAwardRace(u32 sceneFrames);
void racesc_vblank(void);
void racesc_finalize(void);
// Slot mInit of the Race scene; not the whole preparation (race_run and scene_runScene's prologue run
// before it). Calls in order: overlay_createExpHeap (creates the heap that overlay_destroyExpHeap destroys),
// vram_terminateWifiVram (kinds 3 and 5) or vram_startUpWifiVram + sub_2053E74, race_initG3d, dce_init,
// race_initDisplayConfig (screen layout), input_20431E4, race_init, rchoi_init, r2d_init,
// sub_20AF99C (not kind 3), input_setMirrorMode, and the mode 5 net state / mode 2 spi_startMicAutoSampling
// extras. Does not allocate race_sState: race_init does.
void racesc_init(void);
void race_initDisplayConfig(void *heap);
u32 race_getShouldUpdate(u32 sceneFrames);
BOOL race_getGhostFileNameForCourse(u32 courseId, void *buffer, u32 size);
