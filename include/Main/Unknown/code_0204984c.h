#pragma once

#include "types.h"

typedef struct SceneNumbers SceneNumbers;

s32 func_0204984c(SceneNumbers *sceneNumbers, s32 b);
void scene_reportError(s32 kind);
u32 scene_isResetProhibited(void);
BOOL scene_isSleepAllowed(void);
u32 scene_areUpdatesSuspended(void);
void scene_init(void *heap);
void scene_postSleepCallback(void);
void scene_preSleepCallback(void *arg);
void scene_reportErrorIntern(s32 kind);
void scene_displayError(void);
void scene_threadMain(void *arg);
s32 scene_getShouldStopUnloadMusic(s32 scene, s32 nextScene);
s32 scene_getSceneMusicOverride(s32 sceneNumber, s32 *b);
void func_0204a4d8(void);
u32 scene_getFadeOutLength(void);
s16 scene_getFadeInLength(void);
