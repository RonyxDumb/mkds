#pragma once

#include "types.h"
#include "Main/Scene/scene_display_archive_work.h"

typedef struct SceneNumbers SceneNumbers;

// Scene function of g_SceneFnTable[9] (scene 'Logo' in g_SceneArchiveNameTable): copies the callbacks and calls
// OnSceneLoop. Returns 0.
s32 SceneFn_Logo(SceneNumbers *sceneNumbers);
void Scene_Logo_Update(void *sceneNumbers);
void Scene_Logo_VBlank(void);
void Scene_Logo_Finalize(void);
void Scene_Logo_Initialize(void);
void WaitForWorkerTask(void);
u32 WorkerInsertTask(void (*function)(void));
void WorkerThread_Main(void *threadArgument);

extern SceneCallbacks g_Scene_Logo;
