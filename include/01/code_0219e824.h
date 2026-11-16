#pragma once

#include "types.h"

// Scene function of scproc_sSceneTable[11] (scene 'Nickname' in sSceneDefs): copies the callbacks and
// calls scene_runScene. Returns 0.
int nickname_run(void *a);
void PreRenderFirstTimeStartNicknameScreen(s16 *param_1);
void PostRenderFirstTimeStartNicknameScreen(void);
void EndFirstTimeStartNicknameScreen(void);
void StartFirstTimeStartNicknameScreen(s16 *a);
u8 *GetOptionSecondBuffer(void);
u8 *GetOptionFirstBuffer(void);
// Scene function of scproc_sSceneTable[7] (scene 'Option' in sSceneDefs): copies the callbacks and calls
// scene_runScene. Returns 0.
int option_run(void *a);
void settingsMenu_onDraw(s16 *a);
void settingsMenu_afterDraw(void);
// Slot mRelease: calls the state's undo functions and clears the globals; frees nothing itself (the
// scene heap goes with the scene).
void settingsMenu_onDelete(void);
void settingsMenu_onCreate(s16 *a);
// Scene function of scproc_sSceneTable[15] (scene 'Ending' in sSceneDefs): copies the callbacks and calls
// scene_runScene. Returns 0.
int ending_run(void *a);
