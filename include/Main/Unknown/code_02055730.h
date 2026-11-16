#pragma once

#include "types.h"
#include "Main/Unknown/code_020487fc.h" // SceneNumbers

s32 func_02055730(u16 a);
s32 func_0205579c(s32 a, s32 b);
s32 sub_2055808(s32 a);
void sub_20559EC(const void *entryName, s32 entryIndex, s32 keepMask);
// Scene function of scproc_sSceneTable[8] (scene 'Record' in sSceneDefs): copies the callbacks and calls
// scene_runScene. Returns 0.
s32 record_run(SceneNumbers *sceneNumbers);
void dce_2055A94(void);
BOOL dce_2055AFC(void);
BOOL dce_2055B1C(void);
void dce_fadeOutToBlack(u32 frameCount);
void dce_fadeInFromBlack(u32 frameCount);
void dce_stopBlur(void);
void dce_startBlur(u8 blendMin);
void dce_updateVBlank(s32 a);
void dce_updateBlur(s32 a);
void dce_updateDouble3D(void);
void dce_setupGX(void);
void dce_setupDouble3D(void);
void dce_setMode(s32 mode);
u32 dce_uninit(void);
void dce_init(void *heap);
u8 func_02056208(void);
