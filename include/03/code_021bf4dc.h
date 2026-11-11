#pragma once

#include "types.h"

extern u8 gLanguagePathBuffer[];

u32 GetLanguageTextFlags(void);
void PrintMessageAndText(u32 text, u32 messageIndex);
void PrintMessage(u32 messageIndex);
void CreateSlideButtonsForMenuPair(u32 variant);
void CreateObjectsForMenuPair(u32 a);
unsigned int LoadFileToVram(void *path, void *loader);
u8 *BuildFilePathWithLanguage(const u8 *path);
