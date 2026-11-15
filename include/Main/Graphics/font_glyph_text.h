#pragma once

#include "types.h"
#include "g2d_CharCanvas.h" // NNSG2dGlyph
#include "Main/Race/race_setup_block.h" // MinuteSecondMillisecondTime
#include "tp.h"

typedef struct NNSG2dFont NNSG2dFont;

void InitTitleStateHandlers(void);
BOOL AreOtherMissionRecordsFilled5To7(void);
s32 MissionRecordGetMissionRunTableColumn(void);
s32 MissionRecordGetMissionRunTableRow(void);
BOOL IsMissionRunRecordFilled(void);
BOOL IsTimeLessThan(MinuteSecondMillisecondTime *firstTime, MinuteSecondMillisecondTime *secondTime);
s16 LookupFrameOffset(s32 index);
s32 CopyTextWithinWidth(const u16 *source, u16 *destination);
void GetFontGlyphOfChar(NNSG2dGlyph *glyph, NNSG2dFont *font, u32 code);

extern const s16 gFrameOffsets[6];
