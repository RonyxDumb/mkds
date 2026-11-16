#pragma once

#include "types.h"

typedef struct SceneNumbers SceneNumbers;

// Scene function of scproc_sSceneTable[9] (scene 'Logo' in sSceneDefs): copies the callbacks and calls
// scene_runScene. Returns 0.
s32 logo_run(SceneNumbers *sceneNumbers);
void logodef_render(void *sceneNumbers);
void logodef_vblank(void);
void logodef_finish(void);
void logodef_create(void);
void bgwkr_waitForCompletion(void);
u32 bgwkr_enqueueTask(void (*function)(void));
void bgwkr_threadMain(void *threadArgument);
