#pragma once

#include "types.h"

u32 GetVramBg3BaseOffset_Bottom(void);
u32 GetVramBg3BaseOffset_Top(void);
u32 GetVramBg2BaseOffset_Bottom(void);
u32 GetVramBg2BaseOffset_Top(void);

u32 GetVramBg1BaseOffset_Bottom(void);

u32 GetVramBg1BaseOffset_Top(void);

u32 GetVramBg0BaseOffset_Bottom(void);

u32 GetVramBg0BaseOffset_Top(void);
u32 G2S_GetBG3ScrPtr(void);
u32 G2_GetBG3ScrPtr(void);
u32 G2S_GetBG2ScrPtr(void);
u32 G2_GetBG2ScrPtr(void);

u32 G2S_GetBG1ScrPtr(void);

u32 G2_GetBG1ScrPtr(void);

u32 GetAnotherSubEngineBGOffset(void);

u32 G2_GetBG0ScrPtr(void);
