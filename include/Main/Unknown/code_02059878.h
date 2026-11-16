#pragma once

#include "types.h"

typedef struct SceneNumbers SceneNumbers;

void func_02059878(void);
void ProcessMPChunk(u8 *chunk);
u32 IsAllMPChunksReceived(u32 slot);
// Scene function of scproc_sSceneTable[10] (scene 'Result' in sSceneDefs): copies the callbacks and calls
// scene_runScene. Returns 0.
s32 ressc_run(SceneNumbers *sceneNumbers);
