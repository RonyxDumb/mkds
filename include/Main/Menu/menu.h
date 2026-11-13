#pragma once

#include "types.h"
#include "Main/Graphics/scene_text_init.h"

void InitMenu(void);
u16 *MenuMB_GetMultiBootParam(void);
BOOL MenuMB_IsMultiBootChild(void);
BOOL MenuMB_IsMultiBootChildWrapper(void);

unsigned int GetLVselIndex6Requested(void);
unsigned int GetUnfilledNotEliminated(void);
void SetRaceSetupRequested(unsigned int requested);
unsigned int GetMenuEntryKind(void);

u32 MenuWriteSubWinEnableBits(u32 bits);
u32 MenuWriteMainWinEnableBits(u32 bits);

typedef struct DisplaySettings DisplaySettings;

s32 GetRaceSetupMissionTableRow(void);
s32 GetRaceSetupMissionTableColumn(void);
void CopyCurrentToRaceSetupCopy(void);
void CopyMenuScreenCallbacks(void);
void WriteMenuSceneRegisters(void);
void SetMainBg0Record(DisplaySettings *displaySettings, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 cntVal7,
                      u32 cntVal8, u32 cntVal2, u32 cntVal13);
void SetMainBg1Record(DisplaySettings *displaySettings, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 cntVal7,
                      u32 cntVal8, u32 cntVal2, u32 cntVal13);
void SetMainBg2RecordParams(DisplaySettings *displaySettings, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 cntVal7Or13,
                            u32 cntVal8, u32 cntVal2);
void SetMainBg3RecordParams(DisplaySettings *displaySettings, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 cntVal7Or13,
                            u32 cntVal8, u32 cntVal2);
void SetSubBg0Record(DisplaySettings *displaySettings, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 cntVal7, u32 cntVal8,
                     u32 cntVal2, u32 cntVal13);
void SetSubBg1Record(DisplaySettings *displaySettings, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 cntVal7, u32 cntVal8,
                     u32 cntVal2, u32 cntVal13);
void SetSubBg2RecordParams(DisplaySettings *displaySettings, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 cntVal7Or13,
                           u32 cntVal8, u32 cntVal2);
void SetSubBg3RecordParams(DisplaySettings *displaySettings, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 cntVal7Or13,
                           u32 cntVal8, u32 cntVal2);
void MenuGX_SetOBJVRamModeChar(u32 bits);
void MenuGXS_SetOBJVRamModeChar(u32 bits);

// Objects whose layout isn't known yet.
extern const u8 gMenuDisplaySettingsDesc[40];
