#pragma once

#include "types.h"

// One cell position (mX, mY) in the emblem grid; mPointStack holds these.
typedef struct EmblemGridPoint {
    /* 00 */ u8 mX;
    /* 01 */ u8 mY;
} EmblemGridPoint;

#include "01/Menu/menu_screen_states_and_file_names.h"

s32 FillEmblemGridRegion(s32 startX, s32 startY, s32 newValue);
s32 SetEmblemGridLine(s32 lineX, s32 lineY, s32 endX, s32 endY, s32 value);
u8 GetEmblemGridCellValue(s32 cellX, s32 cellY);
u32 SetEmblemGridCellValue(u32 cellX, u32 cellY, u32 value);
void ResetEmblemGridChanges(void);
unsigned int IsEmblemGridChanged(void);
void ClearEmblemGridCopied(void);
unsigned int IsEmblemGridSwapped(void);
void SwapEmblemGridCells(void);
s32 SetEmblemGridCellsFromTable(u8 *indices, u16 *table);
u32 SetEmblemGridCells(u8 *src);
u8 *GetEmblemGridCells(void);
unsigned int GetEmblemGridCharSize(void);
unsigned int GetEmblemGridCharOffset(void);
int GetEmblemGridScrSize(void);
unsigned int GetEmblemGridScrOffset(void);
void *GetEmblemGridScr(void);
void CopyEmblemGridCellsOnFirstChange(void);
u8 *GetEmblemGridCellPtr(s32 cellX, s32 cellY);
unsigned int GetEmblemGridSide(void);
void CreateEmblemGrid(s32 side, s32 scrSide, s32 tableCount);
