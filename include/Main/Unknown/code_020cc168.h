#pragma once

#include "types.h"

typedef struct DisplaySettings DisplaySettings;

s32 GetRaceSetupMissionTableRow(void);
s32 GetRaceSetupMissionTableColumn(void);
void CopyCurrentToRaceSetupCopy(void);
void CopyMenuScreenCallbacks(void);
void func_020cc36c(void);
void SetMainBg0Record(DisplaySettings *displaySettings, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
void func_020cc2f4(DisplaySettings *displaySettings, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
void func_020cc2c0(DisplaySettings *displaySettings, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
void func_020cc28c(DisplaySettings *displaySettings, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
void SetSubBg0Record(DisplaySettings *displaySettings, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
void SetSubBg1Record(DisplaySettings *displaySettings, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
void func_020cc1e0(DisplaySettings *displaySettings, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
void func_020cc1ac(DisplaySettings *displaySettings, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
void func_020cc18c(u32 bits);
void SetSubDispcntBits(u32 bits);
