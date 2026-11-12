#pragma once

#include "types.h"
#include "Main/Scene/display_settings.h" // DisplaySettings

void SetTitleBlendDone(unsigned int blendDone);
void TitleWriteMainBlendAlpha(u32 plane1, u32 plane2, u32 ev1, u32 ev2);

void ReleaseTitleSceneObject(void);

void CreateTitleScene(void);

void TitleSetLVselIndex6Requested(unsigned int value);
void TitleSetUnfilledNotEliminated(unsigned int value);
void TitleSetMenuEntryKind(unsigned int value);
void TitleSetRaceSetupRequested(unsigned int value);

u32 TitleWriteSubWinEnableBits(u32 arg0);
u32 WriteMainWinEnableBits(u32 arg0);

void TitleWriteSubBlendAlpha(u32 plane1, u32 plane2, u32 ev1, u32 ev2);

void TitleGXS_SetOBJVRamModeChar(u32 bits);
void TitleGX_SetOBJVRamModeChar(u32 bits);
void TitleSetSubBg3RecordParams(DisplaySettings *displaySettings, u32 cntLow2, u32 cntBit6, u32 cntVal14,
                                u32 cntVal7Or13, u32 cntVal8, u32 cntVal2);
void TitleSetMainBg3RecordParams(DisplaySettings *displaySettings, u32 cntLow2, u32 cntBit6, u32 cntVal14,
                                 u32 cntVal7Or13, u32 cntVal8, u32 cntVal2);
void TitleSetMainBg2RecordParams(DisplaySettings *displaySettings, u32 cntLow2, u32 cntBit6, u32 cntVal14,
                                 u32 cntVal7Or13, u32 cntVal8, u32 cntVal2);
void TitleSetMainBg1Record(DisplaySettings *displaySettings, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 cntVal7,
                           u32 cntVal8, u32 cntVal2, u32 cntVal13);

unsigned int GetTitleBlendDone(void);

void *TitleGetCurrentHeap(void);

extern const u16 gTitleDisplaySettingsDesc[20];
