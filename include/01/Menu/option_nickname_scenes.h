#pragma once

#include "types.h"
#include "Main/Graphics/oam_lists.h"

// Scene function of g_SceneFnTable[11] (scene 'Nickname' in g_SceneArchiveNameTable): copies the callbacks and
// calls OnSceneLoop. Returns 0.
int RunNicknameScene(void *sceneNumbers);
void UpdateNicknameScene(s16 *sceneNumbers);
void WriteNicknameSceneRegisters(void);
void ReleaseNicknameScene(void);
void InitNicknameScene(s16 *sceneNumbers);
OamEntryList *GetOptionSecondBuffer(void);
OamEntryList *GetOptionFirstBuffer(void);
// Scene function of g_SceneFnTable[7] (scene 'Option' in g_SceneArchiveNameTable): copies the callbacks and calls
// OnSceneLoop. Returns 0.
int RunOptionScene(void *sceneNumbers);
void UpdateOptionScene(s16 *sceneNumbers);
void WriteOptionSceneRegisters(void);
// Slot mRelease: calls the state's undo functions and clears the globals; frees nothing itself (the
// scene heap goes with the scene).
void ReleaseOptionScene(void);
void InitOptionScene(s16 *sceneNumbers);
// Scene function of g_SceneFnTable[15] (scene 'Ending' in g_SceneArchiveNameTable): copies the callbacks and calls
// OnSceneLoop. Returns 0.
int RunEndingScene(void *sceneNumbers);
