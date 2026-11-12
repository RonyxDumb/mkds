#pragma once

#include "types.h"
#include "code_02142eac.h" // Unk021425e8
#include "Main/Menu/second_menu_scene.h" // StateCallbacks

typedef struct SceneNumbers SceneNumbers;

void InitMPStateMachine(void);
void ProcessMPChunk(u8 *chunk);
u32 IsAllMPChunksReceived(u32 slot);
// Scene function of gSceneFuncs[10] (scene 'Result' in gSceneNames): copies the callbacks and calls
// RunScene. Returns 0.
s32 RunResultScene(SceneNumbers *sceneNumbers);

void MPChunkPortCallback(Unk021425e8 *event);

extern StateCallbacks gMPStateTable[23];
