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

void UpdateLogoReadBackup(void *stateObject);
void EnterLogoReadBackup(void *stateObject);
void UpdateLogoScene(SceneNumbers *sceneNumbers);
void WriteLogoSceneRegisters(void);
void ApplySavedSoundMode(void);
void InitLogoScene(void *heap);
void LoadBg1FromSceneFiles(Bg1Files *files, s32 mainScreen, const char *paletteFileName, const char *charsFileName,
                           const char *screenMapFileName);

