#pragma once

#include "types.h"

typedef struct ModeAndFlags {
    /* 00 */ u32 mMode : 4;
} ModeAndFlags;

extern void (*gUpdateFunction)(void);

#include "03/unk_021da000.h"

extern ModeAndFlags gModeAndFlags;
extern s32 gMenuPairs[4];

void SetQuitFlag(void);
BOOL HasModeFlag(u32 mask);
u32 GetMode(void);
u8 GetLanguageIndex(void);
void GetSecondaryMenuPair(s32 *first, s32 *second);
void SetSecondaryMenuPair(u32 third, u32 fourth);
void GetPrimaryMenuPair(s32 *first, s32 *second);
void SetPrimaryMenuPair(u32 first, u32 second);
void SetUpdateFunction(void (*callback)(void));
void ReleaseApplication(void);
void InitGraphics(void);
void InitApplication(void);
BOOL InitLanguageAndMode(s32 languageIndex, u32 modeAndFlags);
s32 RunMainLoop(void *memoryBlock, s32 languageIndex, u32 modeAndFlags);
