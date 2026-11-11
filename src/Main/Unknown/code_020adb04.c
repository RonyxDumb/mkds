#include "Main/Unknown/code_020adb04.h"
#include "Main/Unknown/code_0205ee14.h"
#include "Main/Unknown/code_020add18.h"
#include "Main/Unknown/code_020add90.h"
#include "Main/Unknown/code_0205f000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_02022aa8.h"

#pragma optimize_for_size on

void GetFontGlyphOfChar(NNSG2dGlyph *glyph, Unk02022aa8 *font, u32 code) {
    GetFontGlyph(glyph, font, GetFontGlyphIndex(font, code));
}

#pragma thumb on

s32 CopyTextWithinWidth(const u16 *source, u16 *destination) {
    s32 i;
    s32 widthSum;
    s32 charWidth;
    NNSG2dGlyph glyph;
    void *font;

    widthSum = 0;
    font = GetFontByIndex(0);
    FillHalfwords(destination, 0, 0x14);
    for (i = 0; i < 10; i++) {
        if (source[i] == 0) {
            return i;
        }
        GetFontGlyphOfChar(&glyph, font, source[i]);
        charWidth = glyph.mPWidths->mCharWidth;
        if (widthSum + charWidth > 0x30) {
            return i;
        }
        widthSum += charWidth + 1;
        destination[i] = source[i];
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
                        case 5:
                        case 6:
                        case 7:
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
    s32 i;

    for (i = 0; i < 7; i++) {
        gTitleScene->mStateHandlers[i].mWriteRegisters = gTitleStateHandlers[i].mWriteRegisters;
        gTitleScene->mStateHandlers[i].mUpdate = gTitleStateHandlers[i].mUpdate;
    }
}

#pragma thumb off
