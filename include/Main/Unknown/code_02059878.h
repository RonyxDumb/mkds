#pragma once

#include "types.h"

typedef struct SceneNumbers SceneNumbers;

void InitMPStateMachine(void);
void ProcessMPChunk(u8 *chunk);
u32 IsAllMPChunksReceived(u32 slot);
// Scene function of gSceneFuncs[10] (scene 'Result' in gSceneNames): copies the callbacks and calls
// RunScene. Returns 0.
s32 RunResultScene(SceneNumbers *sceneNumbers);
