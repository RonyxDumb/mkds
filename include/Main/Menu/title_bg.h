#pragma once

#include "types.h"
#include "Main/Scene/display_settings.h" // DisplaySettings

void SetB488TitleMenuSkipIntro(unsigned int blendDone);
void EnableAlphaSetTopBldcntBldalpha(u32 plane1, u32 plane2, u32 ev1, u32 ev2);

void Scene_Title_FinalizeImpl_from_thumb(void);

void LoadTitleFiles_from_thumb(void);

void SetB488_b6(unsigned int value);
void SetB488_b5(unsigned int value);
void SetB488SinglePlayerMenuTarget(unsigned int value);
void SetB488_b2(unsigned int value);

u32 SetSubDispcntWindow0Window1ObjDisplayFlag(u32 bits);
u32 SetTopDispcntWindow0Window1ObjDisplayFlag(u32 bits);

void EnableAlphaSetSubBldcntBldalpha(u32 plane1, u32 plane2, u32 ev1, u32 ev2);

void SetDispcntSubDisplayFrameSelect(u32 bits);
void SetDispcntTopDisplayFrameSelect(u32 bits);
void DisplayConfig_SetBottomEngineBg3Config(DisplaySettings *displaySettings, u32 cntLow2, u32 cntMosaic, u32 cntVal14,
                                u32 cntVal7Or13, u32 cntVal8, u32 cntVal2);
void DisplayConfig_SetTopEngineBg3Config(DisplaySettings *displaySettings, u32 cntLow2, u32 cntMosaic, u32 cntVal14,
                                 u32 cntVal7Or13, u32 cntVal8, u32 cntVal2);
void DisplayConfig_SetTopEngineBg2Config(DisplaySettings *displaySettings, u32 cntLow2, u32 cntMosaic, u32 cntVal14,
                                 u32 cntVal7Or13, u32 cntVal8, u32 cntVal2);
void DisplayConfig_SetTopEngineBg1Config(DisplaySettings *displaySettings, u32 cntLow2, u32 cntMosaic, u32 cntVal14, u32 cntVal7,
                           u32 cntVal8, u32 cntVal2, u32 cntVal13);

unsigned int GetB488TitleMenuSkipIntro(void);

void *GetActiveExecutionContextHeapHandle_4(void);

extern const u16 gTitleDisplaySettingsDesc[20];
