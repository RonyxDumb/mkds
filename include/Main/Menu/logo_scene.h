#pragma once

#include "types.h"
#include "Main/Scene/menu_scene.h" // SceneNumbers

typedef struct Bg1Files Bg1Files;

extern const char gLogoMainBgPaletteFileName[];
extern const char gLogoMainBgCharsFileName[];
extern const char gLogoMainBgScreenMapFileName[];
extern const char gLogoSubBgPaletteFileName[];
extern const char gLogoSubBgCharsFileName[];
extern const char gLogoSubBgScreenMapFileName[];
extern const char gLogoSceneCommonBmgFileName[];

void Logo_StateHandler_ReadSaveData_Second(void *stateObject);
void Logo_StateHandler_ReadSaveData_First(void *stateObject);
void Scene_Logo_UpdateImpl(SceneNumbers *sceneNumbers);
void Scene_Logo_VBlankImpl(void);
void Scene_Logo_FinalizeImpl(void);
void InitializeLogoContext(void *heap);
void LoadLogoScreenGraphics(Bg1Files *files, s32 mainScreen, const char *paletteFileName, const char *charsFileName,
                           const char *screenMapFileName);

