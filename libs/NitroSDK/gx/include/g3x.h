#pragma once

#include "types.h"

void GXi_NopClearFifo128_(void *dest);

void G2Bg0OfsWrite(u32 offset);

s32 G3X_GetMtxStackLevelPJ(s32 *level);
s32 G3X_GetMtxStackLevelPV(s32 *level);
void G3X_InitTable(void);
void G3X_SetClearColor(u32 rgb, u32 alpha, u16 depth, u32 polygonID, s32 fog);

void G3X_SetToonTable(const u16 *toonTable);
