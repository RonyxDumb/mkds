#pragma once

#include "types.h"
#include "Main/Graphics/oam_lists.h"

typedef struct SceneNumbers SceneNumbers;

void *GetWiFiMenuSubOamList(void);
void *GetWiFiMenuMainOamList(void);
// Scene function of g_SceneFnTable[12] (scene 'WiFiMenu' in g_SceneArchiveNameTable): copies the callbacks and
// calls OnSceneLoop. Returns 0.
s32 RunWiFiMenuScene(SceneNumbers *sceneNumbers);
void UpdateWiFiMenuScene(SceneNumbers *sceneNumbers);
void WriteWiFiMenuSceneRegisters(void);
// Calls the current state's release callback, clears the state callbacks, destroys the heap of
// ReleasePlayerEntryList and clears gWiFiStates and the list block.
void ReleaseWiFiMenuScene(void);
void InitWiFiMenuScene(s16 *sceneNumbers);

extern OamEntryList *gWiFiMenuOamLists;
