#pragma once

#include "types.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020b4000.h" // Ncgr

void SetupKeyboardLayoutHiragana(KeyboardRect *rects, Ncgr *ncgr, u32 rectCount);
void SetupKeyboardLayout(KeyboardRect *rects, Ncgr *ncgr, void (*callback)(KeyboardKeys *), s32 fixedCount,
                         u32 rectCount, u16 *charMap);
u16 LookupCharInTablePair(u16 **tablePair, u16 charCode);
KeyboardRect *FindKeyboardRectInDirection(u32 direction, KeyboardRect *rect, KeyboardRect *unused);
void RefreshKeyboardCursor(KeyboardKeys *keyboardKeys);
void AddToNonzeroNibblesInRect(u32 (*tiles)[8], s32 rowWidth, u32 addValue, s32 left, s32 top, s32 right, s32 bottom);
void AddToNonzeroNibblesOnRectEdge(u32 (*tiles)[8], s32 rowWidth, u32 addValue, s32 left, s32 top, s32 right,
                                   s32 bottom);
void AddToNonzeroNibblesInTile(u32 *tile, u32 addValue, s32 startX, s32 startRow, s32 endX, s32 endRow);
u32 IsCharInTable3(u16 charCode);
u32 IsCharInTable2(u16 charCode);
u32 IsCharInTable1(u16 charCode);
u16 CycleCharTables(u16 charCode);
u16 ConvertCharPair3(u16 charCode);
u16 ConvertCharPair2(u16 charCode);
u16 ConvertCharPair1(u16 charCode);
