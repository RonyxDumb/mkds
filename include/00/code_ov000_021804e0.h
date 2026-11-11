#pragma once

#include "types.h"

typedef struct SceneNumbers SceneNumbers;

extern u8 *gWiFiMenuOamLists;

void *GetWiFiMenuSubOamList(void);
void *GetWiFiMenuMainOamList(void);
// Scene function of gSceneFuncs[12] (scene 'WiFiMenu' in gSceneNames): copies the callbacks and
// calls RunScene. Returns 0.
s32 RunWiFiMenuScene(SceneNumbers *sceneNumbers);
void UpdateWiFiMenuScene(SceneNumbers *sceneNumbers);
void WriteWiFiMenuSceneRegisters(void);
// Calls the current state's release callback, clears the state callbacks, destroys the heap of
// ReleasePlayerEntryList and clears gWiFiStates and the list block.
void ReleaseWiFiMenuScene(void);
void InitWiFiMenuScene(s16 *sceneNumbers);
