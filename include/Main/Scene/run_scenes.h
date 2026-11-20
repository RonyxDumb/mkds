#pragma once

#include "types.h"
#include "Main/System/backup_net_camera_work.h"

// Never returns: loops RunScenes, taking the kind from gRunScenesState->mNextKind. First scene SCENE_LOGO, or
// SCENE_WL_MENU (with CONNECTION_KIND_WL_MENU) when booted as multiboot. Called by InitAndRunScenesForever.
void RunScenesForever(void);
// Runs the scenes of one kind (gRunScenesState->mKind: RUN_SCENES_KIND_CONNECTION or RUN_SCENES_KIND_WIFI_SESSION) one
// after another until mNextKind names another kind: sets the kind up (InitRunScenesKind), keeps gSceneNumbers
// (previous, current, next), runs gSceneFuncs[number] inside a new heap (RunHeapCall), takes the next number or
// SCENE_LOGO, tears the kind down. For CONNECTION_KIND_WIFI_TOP_MENU it runs RunDWCUtility (overlay 3) and continues
// with CONNECTION_KIND_WIFI_MENU.
s32 RunScenes(s16 *sceneNumber);
void RunDWCUtility(void);

u32 GetNextSceneNumber(void);
int GetCurrentSceneNumber(void);
void InitRunScenesKind(void);
void CreateRunScenesState(void *heap);
s32 UpdateShapeMapObjectCounts(void);
void ClearShapeMapObjectCountListPointer(void);

extern const u8 gDWCUtilityLanguageTable[6];
extern s16 gSceneNumbers[3];
extern struct RunScenesState *gRunScenesState;

extern struct ShapeMapObjectCountList *gShapeMapObjectCountList;
