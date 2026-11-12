#pragma once

#include "types.h"
#include "Main/Scene/menu_scene.h" // SceneNumbers

typedef struct Bg1Files Bg1Files;

extern const char data_usa_ov001_021a768c[];
extern const char data_usa_ov001_021a76a8[];
extern const char data_usa_ov001_021a76c4[];
extern const char data_usa_ov001_021a76dc[];
extern const char data_usa_ov001_021a76f4[];
extern const char data_usa_ov001_021a770c[];
extern const char data_usa_ov001_021a7720[];

void UpdateLogoState0(void);
void EnterLogoState0(void);
void UpdateLogoScene(SceneNumbers *sceneNumbers);
void WriteLogoSceneRegisters(void);
void ApplySavedSoundMode(void);
void InitLogoScene(void *heap);
void LoadBg1FromSceneFiles(Bg1Files *files, s32 mainScreen, const char *paletteFileName, const char *charsFileName,
                           const char *screenMapFileName);
