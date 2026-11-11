#pragma once

#include "types.h"

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
