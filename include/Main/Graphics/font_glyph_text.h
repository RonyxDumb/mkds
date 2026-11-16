#pragma once

#include "types.h"
#include "char_canvas_text_draw.h" // NNSG2dGlyph
#include "Main/Race/race_setup_block.h" // MinuteSecondMillisecondTime
#include "touch_panel_sampling.h"

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

// Entries of gFrameOffsets; the shift of a row after a press runs this many frames.
#define FRAME_OFFSET_COUNT 6
extern const s16 gFrameOffsets[FRAME_OFFSET_COUNT];
