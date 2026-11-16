#pragma once

#include "types.h"
#include "Main/Unknown/unk_021759c0.h" // MinuteSecondMillisecondTime

typedef struct Unk02022aa8 Unk02022aa8;

void title_setupStates(void);
BOOL func_020adb34(void);
s32 GetCurrentMissionLevelStage(void);
s32 GetCurrentMissionLevel(void);
BOOL IsMissionRunRecordFilled(void);
BOOL IsTimeLessThan(MinuteSecondMillisecondTime *firstTime, MinuteSecondMillisecondTime *secondTime);
s16 func_020adc64(s32 index);
s32 CopyTextWithinWidth(const u16 *source, u16 *destination);
void GetFontGlyphOfChar(u32 *glyph, Unk02022aa8 *font, u32 code);
