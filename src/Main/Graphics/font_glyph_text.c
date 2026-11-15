#include "Main/Graphics/font_glyph_text.h"
#include "Main/Save/buddy_record_time.h"
#include "Main/Graphics/font_glyph.h"
#include "Main/Graphics/font_glyph_index.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/MapObjects/data_02156000.h"
#include "Main/Kart/code_0208fd8c.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/MapObjects/data_0217b000.h"
#include "code_02022aa8.h"
#include "Main/Menu/title_state_handlers.h"

const s16 gFrameOffsets[6] = {2, 4, 8, 4, 2, 0};

#pragma optimize_for_size on

void GetFontGlyphOfChar(NNSG2dGlyph *glyph, NNSG2dFont *font, u32 code) {
    GetFontGlyph(glyph, font, GetFontGlyphIndex(font, code));
}

#pragma thumb on

s32 CopyTextWithinWidth(const u16 *source, u16 *destination) {
    s32 charIndex;
    s32 widthSum;
    s32 charWidth;
    NNSG2dGlyph glyph;
    void *font;

    widthSum = 0;
    font = GetFontByIndex(0);
    FillHalfwords(destination, 0, 0x14);
    for (charIndex = 0; charIndex < 10; charIndex++) {
        if (source[charIndex] == 0) {
            return charIndex;
        }
        GetFontGlyphOfChar(&glyph, font, source[charIndex]);
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

BOOL IsTimeLessThan(MinuteSecondMillisecondTime *firstTime, MinuteSecondMillisecondTime *secondTime) {
    s32 firstMilliseconds;
    s32 secondMilliseconds;

    firstMilliseconds = firstTime->mMillisecond + (firstTime->mSecond * 1000 + firstTime->mMinute * 60000);
    secondMilliseconds = secondTime->mMillisecond + (secondTime->mSecond * 1000 + secondTime->mMinute * 60000);
    if (firstMilliseconds < secondMilliseconds) {
        return TRUE;
    }
    return FALSE;
}

BOOL IsMissionRunRecordFilled(void) {
    s32 value;
    s32 row;
    s32 column;

    row = MissionRecordGetMissionRunTableRow();
    column = MissionRecordGetMissionRunTableColumn();
    return GetMissionRecordValue(row, column, &value);
}

#pragma thumb off

s32 MissionRecordGetMissionRunTableRow(void) {
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        return gRaceSetup->mMissionTableRow;
    }
    return -1;
}

s32 MissionRecordGetMissionRunTableColumn(void) {
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        return gRaceSetup->mMissionTableColumn;
    }
    return -1;
}

#pragma thumb on

// TRUE only when all 53 other cells hold 5 to 7 and the current Mission Run cell does not.
BOOL AreOtherMissionRecordsFilled5To7(void) {
    s32 row;
    s32 column;
    s32 isFilled;
    s32 value;

    if (MissionRecordGetMissionRunTableRow() < 1 || MissionRecordGetMissionRunTableRow() > 6 ||
        MissionRecordGetMissionRunTableColumn() < 1 || MissionRecordGetMissionRunTableColumn() > 9) {
        return FALSE;
    }
    for (row = 1; row <= 6; row++) {
        for (column = 1; column <= 9; column++) {
            isFilled = GetMissionRecordValue(row, column, &value);
            if (row == MissionRecordGetMissionRunTableRow() && column == MissionRecordGetMissionRunTableColumn()) {
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

void InitTitleStateHandlers(void) {
    s32 handlerIndex;

    for (handlerIndex = 0; handlerIndex < 7; handlerIndex++) {
        gTitleScene->mStateHandlers[handlerIndex].mWriteRegisters = gTitleStateHandlers[handlerIndex].mWriteRegisters;
        gTitleScene->mStateHandlers[handlerIndex].mUpdate = gTitleStateHandlers[handlerIndex].mUpdate;
    }
}

#pragma thumb off
