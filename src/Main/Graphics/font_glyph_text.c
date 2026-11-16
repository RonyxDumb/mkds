#include "Main/Graphics/font_glyph_text.h"
#include "Main/Save/buddy_record_time.h"
#include "Main/Graphics/font_glyph.h"
#include "Main/Graphics/font_glyph_index.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Menu/keyboard_cursor_targets.h"
#include "Main/Kart/kart_ai_item_use.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "font_glyph_layout.h"
#include "Main/Menu/title_state_handlers.h"

const s16 gFrameOffsets[6] = {2, 4, 8, 4, 2, 0};

#pragma optimize_for_size on

void MaybeGetNftrCodepointPixelSize(NNSG2dGlyph *glyph, NNSG2dFont *font, u32 code) {
    GetFontGlyph(glyph, font, NFTR_SomeFn(font, code));
}

#pragma thumb on

s32 GetClampedString10LengthForFontIndex0_from_thumb(const u16 *source, u16 *destination) {
    s32 charIndex;
    s32 widthSum;
    s32 charWidth;
    NNSG2dGlyph glyph;
    void *font;

    widthSum = 0;
    font = GetLoadedFont_from_thumb(0);
    DoFill16(destination, 0, 0x14);
    for (charIndex = 0; charIndex < 10; charIndex++) {
        if (source[charIndex] == 0) {
            return charIndex;
        }
        MaybeGetNftrCodepointPixelSize(&glyph, font, source[charIndex]);
        charWidth = glyph.mPWidths->mCharWidth;
        if (widthSum + charWidth > 0x30) {
            return charIndex;
        }
        widthSum += charWidth + 1;
        destination[charIndex] = source[charIndex];
    }
    return 10;
}

s16 LookupFrameOffset(s32 index) {
    if (index < 0) {
        index = 0;
    }
    if (index >= 6) {
        index = 5;
    }
    return gFrameOffsets[index];
}

BOOL StructRCTime_SmallerThan_from_thumb(MinuteSecondMillisecondTime *firstTime, MinuteSecondMillisecondTime *secondTime) {
    s32 firstMilliseconds;
    s32 secondMilliseconds;

    firstMilliseconds = firstTime->mMillisecond + (firstTime->mSecond * 1000 + firstTime->mMinute * 60000);
    secondMilliseconds = secondTime->mMillisecond + (secondTime->mSecond * 1000 + secondTime->mMinute * 60000);
    if (firstMilliseconds < secondMilliseconds) {
        return TRUE;
    }
    return FALSE;
}

BOOL IsCurrentMissionLevelStageBeaten_from_thumb(void) {
    s32 value;
    s32 row;
    s32 column;

    row = GetCurrentMissionLevel();
    column = GetCurrentMissionLevelStage();
    return IsMissionStageBeaten(row, column, &value);
}

#pragma thumb off

s32 GetCurrentMissionLevel(void) {
    if (g_GlobalCO->mMode == MODE_MISSION_RUN) {
        return g_GlobalCO->mMissionTableRow;
    }
    return -1;
}

s32 GetCurrentMissionLevelStage(void) {
    if (g_GlobalCO->mMode == MODE_MISSION_RUN) {
        return g_GlobalCO->mMissionTableColumn;
    }
    return -1;
}

#pragma thumb on

// TRUE only when all 53 other cells hold 5 to 7 and the current Mission Run cell does not.
BOOL MaybeAllMissionStagesBeatenWithStarRank_from_thumb(void) {
    s32 row;
    s32 column;
    s32 isFilled;
    s32 value;

    if (GetCurrentMissionLevel() < 1 || GetCurrentMissionLevel() > 6 ||
        GetCurrentMissionLevelStage() < 1 || GetCurrentMissionLevelStage() > 9) {
        return FALSE;
    }
    for (row = 1; row <= 6; row++) {
        for (column = 1; column <= 9; column++) {
            isFilled = IsMissionStageBeaten(row, column, &value);
            if (row == GetCurrentMissionLevel() && column == GetCurrentMissionLevelStage()) {
                if (isFilled != 0 && (u32) (value - 5) <= 2) {
                    return FALSE;
                }
            } else {
                if (isFilled != 0) {
                    switch (value) {
                        case MISSION_RECORD_VALUE_FIRST_HIGH_TIER:
                        case MISSION_RECORD_VALUE_SECOND_HIGH_TIER:
                        case MISSION_RECORD_VALUE_TOP_TIER:
                            break;
                        default:
                            return FALSE;
                    }
                } else {
                    return FALSE;
                }
            }
        }
    }
    return TRUE;
}

void Title_CopyFunctionList_from_thumb(void) {
    s32 handlerIndex;

    for (handlerIndex = 0; handlerIndex < 7; handlerIndex++) {
        g_SceneTitleContext->mStateHandlers[handlerIndex].mWriteRegisters = g_HUFunctionList[handlerIndex].mWriteRegisters;
        g_SceneTitleContext->mStateHandlers[handlerIndex].mUpdate = g_HUFunctionList[handlerIndex].mUpdate;
    }
}

#pragma thumb off
