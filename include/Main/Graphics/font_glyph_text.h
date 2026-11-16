#pragma once

#include "types.h"
#include "char_canvas_text_draw.h" // NNSG2dGlyph
#include "Main/Race/race_setup_block.h" // MinuteSecondMillisecondTime
#include "touch_panel_sampling.h"

typedef struct NNSG2dFont NNSG2dFont;

void Title_CopyFunctionList_from_thumb(void);
BOOL MaybeAllMissionStagesBeatenWithStarRank_from_thumb(void);
s32 GetCurrentMissionLevelStage(void);
s32 GetCurrentMissionLevel(void);
BOOL IsCurrentMissionLevelStageBeaten_from_thumb(void);
BOOL StructRCTime_SmallerThan_from_thumb(MinuteSecondMillisecondTime *firstTime, MinuteSecondMillisecondTime *secondTime);
s16 LookupFrameOffset(s32 index);
s32 GetClampedString10LengthForFontIndex0_from_thumb(const u16 *source, u16 *destination);
void MaybeGetNftrCodepointPixelSize(NNSG2dGlyph *glyph, NNSG2dFont *font, u32 code);

extern const s16 gFrameOffsets[6];
