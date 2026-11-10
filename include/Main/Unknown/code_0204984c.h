#pragma once

#include "types.h"

typedef struct SceneNumbers SceneNumbers;

s32 RunMessageScreenOnDisconnect(SceneNumbers *sceneNumbers, s32 b);
void RunMessageScreenOfKindWrapper(s32 kind);
u32 func_0204998c(void);
BOOL ShouldGoSleepMode(void);
u32 func_02049b6c(void);
void InitSceneRunState(void *heap);
void ScenePostSleepCallback(void);
void ScenePreSleepCallback(void *arg);
void RunMessageScreenOfKind(s32 kind);
void RunMessageScreen(void);
void RunMessageScreenThread(void *unused);
s32 ShouldEndSceneSoundSet(s32 scene, s32 nextScene);
s32 TryGetSceneSoundSetSeqId(s32 sceneNumber, s32 *seqId);
void AdvanceWiFiSessionOnIrqWrapper(void);
u32 GetSceneFadeToFadedFrameCount(void);
s16 GetSceneFadeToClearFrameCount(void);
