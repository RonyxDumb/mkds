#pragma once

#include "types.h"

// Never returns: loops RunScenes, taking the group from gRunScenesState +4. First scene 9 (6 when the
// word at 0x027ffc40 is 2). Body of the main thread (InitAndRunScenesForever).
void RunScenesForever(void);
// Runs the scenes of one group (gRunScenesState +0, 0 or 1) one after another until the group
// changes: sets the group up (InitRunScenesKind), keeps gSceneNumbers (previous, current, next), runs
// gSceneFuncs[number] inside a new heap (RunHeapCall), takes the next number or 9, tears the
// group down. Reloads overlay 3 for data_021759d0->mUnk_20 == 4.
s32 RunScenes(s16 *sceneNumber);
void RunDWCUtility(void);
