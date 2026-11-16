#pragma once

#include "types.h"

// Never returns: loops scproc_sceneProcMain, taking the group from scproc_sSceneProc +4. First scene 9 (6 when the
// word at 0x027ffc40 is 2). Body of the NitroMain thread (mproc_main).
void scproc_run(void);
// Runs the scenes of one group (scproc_sSceneProc +0, 0 or 1) one after another until the group
// changes: sets the group up (scproc_overlay_205E0B0), keeps scproc_sSceneManager (previous, current, next), runs
// scproc_sSceneTable[number] inside a new heap (proc_run), takes the next number or 9, tears the
// group down. Reloads overlay 3 for gSystemData->mUnk_20 == 4.
s32 scproc_sceneProcMain(s16 *sceneNumber);
void scproc_runWifiUtil(void);
