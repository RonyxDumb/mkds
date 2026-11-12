#pragma once

#include "types.h"
#include "g2d_CharCanvas.h" // NNSG2dGlyph
#include "Main/Race/data_021759c0.h" // MinuteSecondMillisecondTime
#include "tp.h"

typedef struct Unk02022aa8 Unk02022aa8;

void InitTitleStateHandlers(void);
BOOL AreOtherMissionRecordsFilled5To7(void);
s32 MissionRecordGetMissionRunTableColumn(void);
s32 MissionRecordGetMissionRunTableRow(void);
BOOL IsMissionRunRecordFilled(void);
BOOL IsTimeLessThan(MinuteSecondMillisecondTime *firstTime, MinuteSecondMillisecondTime *secondTime);
s16 LookupFrameOffset(s32 index);
s32 CopyTextWithinWidth(const u16 *source, u16 *destination);
void GetFontGlyphOfChar(NNSG2dGlyph *glyph, Unk02022aa8 *font, u32 code);
