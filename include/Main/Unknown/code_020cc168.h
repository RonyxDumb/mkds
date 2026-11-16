#pragma once

#include "types.h"

typedef struct Unk02180774 Unk02180774;

s32 RData_GetCurrentMissionLevel(void);
s32 RData_GetCurrentMissionIndex(void);
void menu_loadLastRaceConfig(void);
void menu_setupStates(void);
void menu_vblank(void);
void SetMainBg0Record(Unk02180774 *displaySettings, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
void func_020cc2f4(Unk02180774 *displaySettings, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
void func_020cc2c0(Unk02180774 *displaySettings, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
void func_020cc28c(Unk02180774 *displaySettings, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
void SetSubBg0Record(Unk02180774 *displaySettings, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
void SetSubBg1Record(Unk02180774 *displaySettings, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
void func_020cc1e0(Unk02180774 *displaySettings, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
void func_020cc1ac(Unk02180774 *displaySettings, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
void menu_GX_SetOBJVRamModeChar(u32 bits);
void menu_GXS_SetOBJVRamModeChar(u32 bits);
