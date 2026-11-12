#pragma once

#include "types.h"

typedef struct SceneNumbers SceneNumbers;

void FillStartupWork(void);
void InitStartupWork(void *heap);
// Scene function of gSceneFuncs[6] (scene 'WLMenu' in gSceneNames): copies the callbacks and calls
// RunScene. Returns 0.
s32 RunWLMenuScene(SceneNumbers *sceneNumbers);
void UpdateWLMenuSceneCallback(void *sceneNumbers);
void WriteWLMenuSceneRegistersCallback(void);
void ReleaseWLMenuSceneCallback(void);
