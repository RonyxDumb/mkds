#pragma once

#include "types.h"

unsigned int GetMenuInputSlot(void);

void WriteSinglePlaySelect1Registers(void);

void UpdateSinglePlaySelectMenuScreen0(void);

void WriteSinglePlaySelect0Registers(void);

void DrawSinglePlaySelectCells(void);

void UpdateSinglePlaySelectSubCells(void);

void SetupSinglePlaySelectGraphics(void);

void MenuGXS_SetVisiblePlane(int bits);
void MenuGX_SetVisiblePlane(int bits);
