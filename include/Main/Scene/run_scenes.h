#pragma once

#include "types.h"
#include "Main/System/backup_net_camera_work.h"

// Never returns: loops SceneLoopExecuteFunction, taking the group from g_SceneOverlayConfig +4. First scene 9 (6 when the
// word at 0x027ffc40 is 2). Body of the NtrMain thread (StartExecuteFunction).
void RunMain(void);
// Runs the scenes of one group (g_SceneOverlayConfig +0, 0 or 1) one after another until the group
// changes: sets the group up (InitRunScenesKind), keeps g_SceneExecutionContext (previous, current, next), runs
// g_SceneFnTable[number] inside a new heap (ExecutionContext_Execute), takes the next number or 9, tears the
// group down. Reloads overlay 3 for g_GlobalP.mConnectionKind == 4.
s32 SceneLoopExecuteFunction(s16 *sceneNumber);
void LoadExecuteOverlay1(void);

u32 GetNextSceneId(void);
int GetCurrentSceneId(void);
void InitRunScenesKind(void);
void InitializeSceneOverlayConfig(void *heap);
s32 UpdateShapeMapObjectCounts(void);
void ResetGlobalAR(void);

extern const u8 g_LangConversionTable[6];
extern s16 g_SceneExecutionContext[3];
extern struct RunScenesState *g_SceneOverlayConfig;

extern struct ShapeMapObjectCountList *g_GlobalAR;
