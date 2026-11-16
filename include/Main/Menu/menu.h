#pragma once

#include "types.h"
#include "Main/Graphics/scene_text_init.h"

void Scene_Menu_InitializeImpl_from_thumb(void);
u16 *GetBootIndicatorPointer_0(void);
BOOL IsDwc_0(void);
BOOL j_IsDwc_0(void);

unsigned int GetB488_B6(void);
unsigned int GetB488_B5(void);
void SetB488_B2(unsigned int requested);
unsigned int GetB488_SinglePlayerMenuTarget(void);

u32 SetDispcntWindows01ObjDisplayFlagsSub(u32 bits);
u32 SetDispcntWindows01ObjDisplayFlagsTop(u32 bits);

typedef struct DisplaySettings DisplaySettings;

s32 GetCurrentMissionLevel_1(void);
s32 GetCurrentMissionStage(void);
void CopyInfoFromCOtoCA_from_thumb(void);
void CopyB43CFunctionTable_from_thumb(void);
void Scene_Menu_VBlankImpl_from_thumb(void);
void DisplayConfig_SetTopEngineBg0Config(DisplaySettings *displaySettings, u32 cntLow2, u32 cntMosaic, u32 cntVal14, u32 cntVal7,
                      u32 cntVal8, u32 cntVal2, u32 cntVal13);
void DisplayConfig_SetTopEngineBg1Config_1(DisplaySettings *displaySettings, u32 cntLow2, u32 cntMosaic, u32 cntVal14, u32 cntVal7,
                      u32 cntVal8, u32 cntVal2, u32 cntVal13);
void DisplayConfig_SetTopEngineBg2Config2(DisplaySettings *displaySettings, u32 cntLow2, u32 cntMosaic, u32 cntVal14, u32 cntVal7Or13,
                            u32 cntVal8, u32 cntVal2);
void DisplayConfig_SetTopEngineBg3Config_0(DisplaySettings *displaySettings, u32 cntLow2, u32 cntMosaic, u32 cntVal14, u32 cntVal7Or13,
                            u32 cntVal8, u32 cntVal2);
void DisplayConfig_SetBottomEngineBg0Config(DisplaySettings *displaySettings, u32 cntLow2, u32 cntMosaic, u32 cntVal14, u32 cntVal7,
                     u32 cntVal8, u32 cntVal2, u32 cntVal13);
void DisplayConfig_SetBottomEngineBg1Config(DisplaySettings *displaySettings, u32 cntLow2, u32 cntMosaic, u32 cntVal14, u32 cntVal7,
                     u32 cntVal8, u32 cntVal2, u32 cntVal13);
void DisplayConfig_SetBottomEngineBg2Config2(DisplaySettings *displaySettings, u32 cntLow2, u32 cntMosaic, u32 cntVal14, u32 cntVal7Or13,
                           u32 cntVal8, u32 cntVal2);
void DisplayConfig_SetBottomEngineBg3Config_1(DisplaySettings *displaySettings, u32 cntLow2, u32 cntMosaic, u32 cntVal14, u32 cntVal7Or13,
                           u32 cntVal8, u32 cntVal2);
void SetTopDispcntTileObjMappingRemoveBoundary(u32 bits);
void SetSubDispcntTileObjMappingRemoveBoundary(u32 bits);

extern const u8 gMenuDisplaySettingsDesc[40];
