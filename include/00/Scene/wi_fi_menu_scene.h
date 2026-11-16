#pragma once

#include "types.h"
#include "Main/Graphics/oam_lists.h"

typedef struct SceneNumbers SceneNumbers;

void *GetWiFiMenuSubOamList(void);
void *GetWiFiMenuMainOamList(void);
// Scene function of gSceneFuncs[12] (scene 'WiFiMenu' in gSceneNames): fills a SceneCallbacks with the Wi-Fi menu scene
// functions and calls RunScene. Returns 0.
s32 RunWiFiMenuScene(SceneNumbers *sceneNumbers);
void UpdateWiFiMenuScene(SceneNumbers *sceneNumbers);
void WriteWiFiMenuSceneRegisters(void);
// Releases the Wi-Fi states (calls the current state's release callback if one is set, clears the state callbacks,
// releases the player entry list and the scene text), then sets gWiFiMenuOamLists to NULL.
void ReleaseWiFiMenuScene(void);
void InitWiFiMenuScene(s16 *sceneNumbers);

extern OamEntryList *gWiFiMenuOamLists;
