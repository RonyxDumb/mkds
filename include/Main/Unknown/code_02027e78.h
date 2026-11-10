#pragma once

#include "types.h"

void WriteSelectKartRegisters(void);
void SelectKartG2S_SetWnd0Position(u32 startX, u32 startY, u32 endX, u32 endY);
void SelectKartG2S_SetWndOutsidePlane(u32 lowBits, u32 extraBitFlag);
void SelectKartG2S_SetWnd0InsidePlane(u32 lowBits, u32 extraBitFlag);
u32 WriteSubWinEnableBits(u32 bits);
void WriteSubBlendAlpha(u32 firstPlane, u32 secondPlane, u32 firstCoefficient, u32 secondCoefficient);
void WriteSubBg3CntBits(u32 bits);
void SelectKartG2S_SetBG3Offset(u32 offsetX, u32 offsetY);
u32 SelectKartGXS_SetVisiblePlane(u32 bits);
u32 SelectKartGX_SetVisiblePlane(u32 bits);
void ReleaseSelectKart(void);
u32 SelectKartMB_IsMultiBootChildWrapper(void);
u32 SelectKartMB_IsMultiBootChild(void);
u16 *SelectKartMB_GetMultiBootParam(void);
unsigned int SelectKartGetConnectionKind(void);
