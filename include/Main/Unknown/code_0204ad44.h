#pragma once

#include "types.h"

typedef struct SceneNumbers SceneNumbers;

void sysdat_initSystemData(void);
void sysdat_init(void *heap);
// Scene function of scproc_sSceneTable[6] (scene 'WLMenu' in sSceneDefs): copies the callbacks and calls
// scene_runScene. Returns 0.
s32 wlmenu_run(SceneNumbers *sceneNumbers);
void wlmenu_update(void *sceneNumbers);
void wlmenu_vblank(void);
void wlmenu_finalize(void);
