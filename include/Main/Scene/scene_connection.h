#pragma once

#include "types.h"

typedef struct SceneNumbers SceneNumbers;

s32 RunMessageScreenOnDisconnect(SceneNumbers *sceneNumbers, s32 flag);
void j_NotifyError(s32 kind);
u32 MaybeIfExpectsReturnToTitleScene(void);
BOOL ShouldGoSleepMode(void);
u32 IsDataSharingIncomplete(void);
void InitializeGlobalZM(void *heap);
void ZM_SomeFn2(void);
void ZM_SomeFn(void *arg);
void NotifyError(s32 kind);
void RunMessageScreen(void);
void ZM_ThreadEntry(void *unused);
s32 ShouldPauseBgmInSceneChange(s32 scene, s32 nextScene);
s32 TryGetSceneSpecialBgmSseqId(s32 sceneNumber, s32 *seqId);
void DisplayConfig_VblankFn(void);
u32 GetSceneFadeToFadedFrameCount(void);
s16 GetSceneFadeToClearFrameCount(void);
