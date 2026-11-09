#pragma once

#include "types.h"
#include "Main/Unknown/code_02036c5c.h" // DisplaySettings

void TitleSetSubDispcntBits(u32 bits);
void TitleSetMainDispcntBits(u32 bits);
void TitleSetSubBg3RecordParams(DisplaySettings *displaySettings, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 e,
                                u32 cntVal8, u32 cntVal2);
void TitleSetMainBg3RecordParams(DisplaySettings *displaySettings, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 e,
                                 u32 cntVal8, u32 cntVal2);
void TitleSetMainBg2RecordParams(DisplaySettings *displaySettings, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 e,
                                 u32 cntVal8, u32 cntVal2);
void TitleSetMainBg1Record(DisplaySettings *displaySettings, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 cntVal7,
                           u32 cntVal8, u32 cntVal2, u32 cntVal13);
