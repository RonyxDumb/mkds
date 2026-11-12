#pragma once

#include "types.h"

u32 GetLanguageTextFlags(void);
void PrintMessageAndText(u32 text, u32 messageIndex);
void PrintMessage(u32 messageIndex);
void CreateSlideButtonsForMenuPair(u32 variant);
void CreateObjectsForMenuPair(u32 a);
unsigned int LoadFileToVram(void *path, void *loader);
u8 *BuildFilePathWithLanguage(const u8 *path);

extern const u8 gLanguagePathLetters[6];
extern const u16 gPrintMessageRect[4];
extern const u16 gPrintMessageAndTextRect[4];
extern const u8 gLanguageTextFlags[22];
extern const u16 gPrintMessageTextXPositions[12];
extern u8 gLanguagePathBuffer[64];
