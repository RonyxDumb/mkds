#include "Main/Unknown/code_020c5dd8.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_02056700.h"
#include "Main/Unknown/code_020b1d64.h"
#include "Main/Unknown/code_020b9994.h"
#include "Main/Unknown/code_020c06c4.h"

#include "Main/Unknown/code_020c5df0.h"
#include "Main/Unknown/code_020c5e30.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02056408.h"
#include "Main/Unknown/code_02056c6c.h"
#include "Main/Unknown/code_020ad000.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_020b1000.h"
#include "Main/Unknown/code_020b19f8.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020b837c.h"
#include "Main/Unknown/code_020ba000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0214cfe4.h"
#include "code_020222ec.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_020c70d8.h"
#include "01/code_021956dc.h"
#include "Main/Kart/KartTimes.h"

u32 GetRaceNewRecordTaBestLapNumber(void) {
    return (r2dtar_sStatus->mBestLapNumber);
}

s32 r2dtar_isSaving(void) {
    return r2dtar_sStatus != NULL ? r2dtar_sStatus->mUnk_18 : 0;
}

s32 func_020c70a0(void) {
    return r2dtar_sStatus != NULL ? r2dtar_sStatus->mUnk_dc : 0;
}

void r2dtar_init(void) {
    s32 i;

    if (gRaceMultiConfig->mMode != MODE_TIME_ATTACK) {
        return;
    }
    r2dtar_sStatus = heap_alloc(proc_getHeap(proc_getCurrent()), 0xe8);
    r2dtar_sStatus->mUpdate = r2dtar_20C610C;
    r2dtar_sStatus->mUpdateFrames = 0;
    r2dtar_sStatus->mFinishTimeIsRecord = 0;
    r2dtar_sStatus->mFinishRecordIndex = -1;
    r2dtar_sStatus->mBestLapIsRecord = 0;
    r2dtar_sStatus->mBestLapNumber = 0;
    r2dtar_sStatus->mUnk_18 = 0;
    for (i = 0; i < 6; i++) {
        savd_getNktaEntry(gRaceMultiConfig->mCourseId, i, &r2dtar_sStatus->mRecords[i]);
    }
    r2dtar_sStatus->mUnk_18 = 0;
    r2dtar_sStatus->mUnk_dc = 0;
    r2dtar_sStatus->mOffsetX = -0x100;
    r2dtar_sStatus->mCycleFrames = 0;
}

void r2dtar_finalize(void) {
    if (gRaceMultiConfig->mMode == MODE_TIME_ATTACK) {
        r2dtar_sStatus = NULL;
    }
}

void r2dtar_update(void) {
    if (gRaceMultiConfig->mMode != MODE_TIME_ATTACK) {
        return;
    }
    r2dtar_sStatus->mUpdate();
    r2dtar_sStatus->mCycleFrames = r2dtar_sStatus->mCycleFrames + 1;
    if (r2dtar_sStatus->mCycleFrames >= 0x18) {
        r2dtar_sStatus->mCycleFrames = 0;
    }
}

void DrawRaceNewRecordTaTime(RaceHudOamBuffer *oamBuffer, s32 x, s32 y, TimeRecord *record) {
    s32 digit0Position[2];
    s32 digit1Position[2];
    s32 firstSeparatorPosition[2];
    s32 digit2Position[2];
    s32 digit3Position[2];
    s32 secondSeparatorPosition[2];
    s32 digit4Position[2];
    s32 digit5Position[2];
    s32 digit6Position[2];
    s32 cellOffsets[9] = {0, 9, 18, 28, 37, 46, 56, 65, 74};
    TimeDigits digits;
    s32 oamIndex;
    void *cell;

    SplitTimeDigits(record->mMinute, record->mSecond, record->mMillisecond, &digits);
    if (record->mFilled == 0) {
        digits.mDigits[0] = digits.mDigits[1] = digits.mDigits[2] = digits.mDigits[3] = digits.mDigits[4] =
            digits.mDigits[5] = digits.mDigits[6] = 0xb;
    }
    if (digits.mDigits[0] != 0) {
        cell = r2d_getRaceNewRecordTaSCell(digits.mDigits[0] + 0xe);
        digit0Position[0] = (x + cellOffsets[0]) << 12;
        digit0Position[1] = y << 12;
        oamIndex = oamBuffer->mOamCount;
        oamBuffer->mOamCount +=
            NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cell, NULL, digit0Position, 0, 1);
    }
    cell = r2d_getRaceNewRecordTaSCell(digits.mDigits[1] + 0xe);
    digit1Position[0] = (x + cellOffsets[1]) << 12;
    digit1Position[1] = y << 12;
    oamIndex = oamBuffer->mOamCount;
    oamBuffer->mOamCount +=
        NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cell, NULL, digit1Position, 0, 1);
    cell = r2d_getRaceNewRecordTaSCell(0x18);
    firstSeparatorPosition[0] = (x + cellOffsets[2]) << 12;
    firstSeparatorPosition[1] = y << 12;
    oamIndex = oamBuffer->mOamCount;
    oamBuffer->mOamCount +=
        NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cell, NULL, firstSeparatorPosition, 0, 1);
    cell = r2d_getRaceNewRecordTaSCell(digits.mDigits[2] + 0xe);
    digit2Position[0] = (x + cellOffsets[3]) << 12;
    digit2Position[1] = y << 12;
    oamIndex = oamBuffer->mOamCount;
    oamBuffer->mOamCount +=
        NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cell, NULL, digit2Position, 0, 1);
    cell = r2d_getRaceNewRecordTaSCell(digits.mDigits[3] + 0xe);
    digit3Position[0] = (x + cellOffsets[4]) << 12;
    digit3Position[1] = y << 12;
    oamIndex = oamBuffer->mOamCount;
    oamBuffer->mOamCount +=
        NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cell, NULL, digit3Position, 0, 1);
    cell = r2d_getRaceNewRecordTaSCell(0x18);
    secondSeparatorPosition[0] = (x + cellOffsets[5]) << 12;
    secondSeparatorPosition[1] = y << 12;
    oamIndex = oamBuffer->mOamCount;
    oamBuffer->mOamCount +=
        NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cell, NULL, secondSeparatorPosition, 0, 1);
    cell = r2d_getRaceNewRecordTaSCell(digits.mDigits[4] + 0xe);
    digit4Position[0] = (x + cellOffsets[6]) << 12;
    digit4Position[1] = y << 12;
    oamIndex = oamBuffer->mOamCount;
    oamBuffer->mOamCount +=
        NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cell, NULL, digit4Position, 0, 1);
    cell = r2d_getRaceNewRecordTaSCell(digits.mDigits[5] + 0xe);
    digit5Position[0] = (x + cellOffsets[7]) << 12;
    digit5Position[1] = y << 12;
    oamIndex = oamBuffer->mOamCount;
    oamBuffer->mOamCount +=
        NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cell, NULL, digit5Position, 0, 1);
    cell = r2d_getRaceNewRecordTaSCell(digits.mDigits[6] + 0xe);
    digit6Position[0] = (x + cellOffsets[8]) << 12;
    digit6Position[1] = y << 12;
    oamIndex = oamBuffer->mOamCount;
    oamBuffer->mOamCount +=
        NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cell, NULL, digit6Position, 0, 1);
}

void DrawRaceNewRecordTaRow(RaceHudOamBuffer *oamBuffer, s32 b, s32 x, s32 y) {
    s32 firstCellPosition[2];
    s32 secondCellPosition[2];
    TimeRecord record;
    s32 cycleFrames;
    BOOL isNewRecord;
    s32 oamIndex;
    void *cell;
    RaceNewRecordTa *newRecordTa;

    newRecordTa = r2dtar_sStatus;
    cycleFrames = newRecordTa->mCycleFrames;
    isNewRecord = FALSE;
    record = newRecordTa->mRecords[b];
    if (b == 5) {
        if ((newRecordTa != NULL ? newRecordTa->mBestLapIsRecord : 0) != 0) {
            b = 0;
            isNewRecord = TRUE;
        } else {
            b = 6;
        }
    } else if (newRecordTa->mFinishTimeIsRecord == 0 || b < newRecordTa->mFinishRecordIndex) {
        b++;
    } else if (b == newRecordTa->mFinishRecordIndex) {
        b = 0;
        isNewRecord = TRUE;
    }
    if (record.mFilled != 0) {
        cell = r2d_getRaceNewRecordTaSCell(b + 7);
        firstCellPosition[0] = (x + 0x32) << 12;
        firstCellPosition[1] = y << 12;
        oamIndex = oamBuffer->mOamCount;
        oamBuffer->mOamCount +=
            NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cell, NULL, firstCellPosition, 0, 1);
        cell = r2d_getRaceNewRecordTaSCell(b + 0x1a);
        secondCellPosition[0] = (x + 0x3d) << 12;
        secondCellPosition[1] = y << 12;
        oamIndex = oamBuffer->mOamCount;
        oamBuffer->mOamCount +=
            NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cell, NULL, secondCellPosition, 0, 1);
    }
    if (isNewRecord != FALSE && cycleFrames >= 0x10) {
        return;
    }
    DrawRaceNewRecordTaTime(oamBuffer, x + 0xab, y, &record);
}

void r2dtar_render(RaceHudOamBuffer *oamBuffer) {
    s32 headerPosition[2];
    s32 rowPosition[2];
    s32 lastRowPosition[2];
    s32 e3[2];
    u16 i;
    s32 oamIndex;
    s32 rowY;
    void *cell;

    cell = r2d_getRaceNewRecordTaSCell(0);
    headerPosition[0] = (r2dtar_sStatus->mOffsetX + 0x80) << 12;
    headerPosition[1] = 0xc000;
    oamIndex = oamBuffer->mOamCount;
    oamBuffer->mOamCount +=
        NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cell, NULL, headerPosition, 0, 1);
    for (i = 0; i < 5; i++) {
        cell = r2d_getRaceNewRecordTaSCell(i + 1);
        rowY = i * 0x18 + 0x28;
        rowPosition[0] = r2dtar_sStatus->mOffsetX << 12;
        rowPosition[1] = (i * 0x18 + 0x28) << 12;
        oamIndex = oamBuffer->mOamCount;
        oamBuffer->mOamCount +=
            NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cell, NULL, rowPosition, 0, 1);
        DrawRaceNewRecordTaRow(oamBuffer, i, r2dtar_sStatus->mOffsetX, rowY);
    }
    cell = r2d_getRaceNewRecordTaSCell(6);
    lastRowPosition[0] = r2dtar_sStatus->mOffsetX << 12;
    lastRowPosition[1] = 0x9f000;
    oamIndex = oamBuffer->mOamCount;
    oamBuffer->mOamCount +=
        NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cell, NULL, lastRowPosition, 0, 1);
    DrawRaceNewRecordTaRow(oamBuffer, i, r2dtar_sStatus->mOffsetX + 1, 0xb4);
}

BOOL r2dtar_20C657C(s32 store) {
    u8 minute;
    u8 second;
    u16 millisecond;
    s32 recordIndex;
    s32 j;
    TimeRecord *record;
    s32 totalMilliseconds;
    TimeRecord *slot;
    TimeRecord *records;
    u8 copiedMinute;
    u8 copiedSecond;
    u16 copiedMillisecond;

    rstat_getDriverTotalTime(Race_GetPlayerId(), &minute, &second, &millisecond);
    record = r2dtar_sStatus->mRecords;
    totalMilliseconds = second * 1000 + minute * 60000 + millisecond;
    recordIndex = 0;
    do {
        if (record->mFilled == 0 ||
            totalMilliseconds < record->mMillisecond + (record->mSecond * 1000 + record->mMinute * 60000)) {
            goto found;
        }
        recordIndex++;
        record++;
    } while (recordIndex < 5);
    return FALSE;
found:
    if (store != 0) {
        for (j = 4; j > recordIndex; j--) {
            r2dtar_sStatus->mRecords[j] = r2dtar_sStatus->mRecords[j - 1];
            savd_setNktaEntry(gRaceMultiConfig->mCourseId, j, &r2dtar_sStatus->mRecords[j]);
        }
        copiedMillisecond = millisecond;
        copiedSecond = second;
        copiedMinute = minute;
        records = r2dtar_sStatus->mRecords;
        slot = records + recordIndex;
        slot->mMinute = copiedMinute;
        slot->mSecond = copiedSecond;
        records[recordIndex].mMillisecond = copiedMillisecond;
        MIi_CpuCopy16(gRaceMultiConfig->mCurrentEntries[Race_GetPlayerId()].mPlayer.mName, slot->mName, 0x14);
        slot->mFilled = 1;
        slot->mCharacterIndex = gRaceMultiConfig->mCurrentEntries[Race_GetPlayerId()].mCharacterIndex;
        slot->mKartIndex = gRaceMultiConfig->mCurrentEntries[Race_GetPlayerId()].mKartIndex;
        savd_setNktaEntry(gRaceMultiConfig->mCourseId, recordIndex, slot);
        if (recordIndex != 5) {
            r2dtar_sStatus->mFinishRecordIndex = recordIndex;
        }
    } else {
        r2dtar_sStatus->mFinishRecordIndex = recordIndex;
    }
    return TRUE;
}

BOOL r2dtar_20C6428(s32 store) {
    u8 minute;
    u8 second;
    u16 millisecond;
    TimeRecord *record;
    TimeRecord *records;
    u8 copiedMinute;
    u8 copiedSecond;
    u16 copiedMillisecond;

    record = &r2dtar_sStatus->mRecords[TIME_RECORD_BEST_LAP];
    r2dtar_sStatus->mBestLapNumber =
        rstat_getDriverBestLapTime(Race_GetPlayerId(), &minute, &second, &millisecond);
    if (record->mFilled != 0) {
        if (millisecond + (second * 1000 + minute * 60000) >=
            record->mMillisecond + (record->mSecond * 1000 + record->mMinute * 60000)) {
            return FALSE;
        }
    }
    if (store != 0) {
        copiedMillisecond = millisecond;
        copiedSecond = second;
        copiedMinute = minute;
        records = r2dtar_sStatus->mRecords;
        record = records + TIME_RECORD_BEST_LAP;
        record->mMinute = copiedMinute;
        record->mSecond = copiedSecond;
        records[TIME_RECORD_BEST_LAP].mMillisecond = copiedMillisecond;
        MIi_CpuCopy16(gRaceMultiConfig->mCurrentEntries[Race_GetPlayerId()].mPlayer.mName, record->mName, 0x14);
        record->mFilled = 1;
        record->mCharacterIndex = gRaceMultiConfig->mCurrentEntries[Race_GetPlayerId()].mCharacterIndex;
        record->mKartIndex = gRaceMultiConfig->mCurrentEntries[Race_GetPlayerId()].mKartIndex;
        savd_setNktaEntry(gRaceMultiConfig->mCourseId, TIME_RECORD_BEST_LAP, record);
    }
    return TRUE;
}

void r2dtar_20C610C(void) {
    MinuteSecondMillisecondTime setupTime;
    MinuteSecondMillisecondTime finishTime;
    u8 minute;
    u8 second;
    u16 millisecond;
    u8 bestLapMinute;
    u8 bestLapSecond;
    u16 bestLapMillisecond;
    BOOL r;
    BOOL hasSetupTime;
    s32 totalMilliseconds;
    s32 j;
    s32 n;
    s32 g;
    TimeRecord *record;
    TimeRecord *records;

    if (gRaceStatus->mRaceDone == 0) {
        return;
    }
    if (GetShowLapTime() != 0) {
        return;
    }
    if (gRaceMultiConfig->mRaceKind == RACE_KIND_NORMAL) {
        r2dtar_sStatus->mFinishTimeIsRecord = r2dtar_20C657C(1);
        r2dtar_sStatus->mBestLapIsRecord = r2dtar_20C6428(1);
        if (r2dtar_sStatus->mFinishTimeIsRecord != 0 || r2dtar_sStatus->mBestLapIsRecord != 0) {
            r2dtar_sStatus->mUnk_18 = 1;
            savd_flushNkta();
            r2dtar_sStatus->mUpdate = func_020c5f7c;
            r2dtar_sStatus->mUpdateFrames = 0;
        } else {
            r = FALSE;
            if (IsRaceKeyRecordingNotFull() != 0) {
                if (gRaceMultiConfig->mMode == MODE_TIME_ATTACK && gRaceMultiConfig->mFirstGhostRecordFilled == 1) {
                    MI_CpuCopy8(&gRaceMultiConfig->mFirstGhostRecordMillisecond, &setupTime, 4);
                    hasSetupTime = TRUE;
                } else {
                    hasSetupTime = FALSE;
                }
                if (hasSetupTime != FALSE) {
                    rstat_getDriverTotalTime((u16) gRaceMultiConfig->mEntryIndex, &finishTime.mMinute, &finishTime.mSecond,
                                      &finishTime.mMillisecond);
                    if (IsTimeLessThan(&finishTime, &setupTime) != FALSE) {
                        r = TRUE;
                    }
                } else {
                    r = TRUE;
                }
            }
            if (r != FALSE) {
                r2dtar_sStatus->mUnk_18 = 1;
                savd_storePersonalGhost(gRaceMultiConfig->mCourseId, gRaceMultiConfig->mEntryIndex);
                r2dtar_sStatus->mUpdate = func_020c5f08;
                r2dtar_sStatus->mUpdateFrames = 0;
            } else {
                r2dtar_sStatus->mUpdate = SlideInRaceNewRecordTa;
                r2dtar_sStatus->mUpdateFrames = 0;
            }
        }
    } else {
        rstat_getDriverTotalTime(Race_GetPlayerId(), &minute, &second, &millisecond);
        records = r2dtar_sStatus->mRecords;
        totalMilliseconds = second * 1000 + minute * 60000 + millisecond;
        for (j = 4; j >= 0; j--) {
            record = &records[j];
            if (record->mFilled != 0 &&
                totalMilliseconds == record->mMillisecond + (record->mSecond * 1000 + record->mMinute * 60000)) {
                j = 1;
                goto found;
            }
        }
        j = 0;
    found:
        r2dtar_sStatus->mFinishTimeIsRecord = j;
        record = &r2dtar_sStatus->mRecords[TIME_RECORD_BEST_LAP];
        r2dtar_sStatus->mBestLapNumber =
            rstat_getDriverBestLapTime(Race_GetPlayerId(), &bestLapMinute, &bestLapSecond, &bestLapMillisecond);
        if (bestLapMinute == record->mMinute && bestLapSecond == record->mSecond &&
            bestLapMillisecond == record->mMillisecond) {
            r = TRUE;
        } else {
            r = FALSE;
        }
        r2dtar_sStatus->mBestLapIsRecord = r;
        r2dtar_sStatus->mUpdate = SlideInRaceNewRecordTa;
        r2dtar_sStatus->mUpdateFrames = 0;
    }
    r2dtar_sStatus->mUnk_dc = 1;
}

void func_020c5f7c(void) {
    MinuteSecondMillisecondTime setupTime;
    MinuteSecondMillisecondTime finishTime;
    BOOL r;
    BOOL hasSetupTime;
    s32 waiting;

    if (gSaveData->mBusy == 0) {
        waiting = gSaveCore->mBackupEnabled != 0 ? gSaveCore->mCommandRunning : 0;
    } else {
        waiting = 1;
    }
    if (waiting != 0) {
        return;
    }
    r = FALSE;
    if (IsRaceKeyRecordingNotFull() != 0) {
        if (gRaceMultiConfig->mMode == MODE_TIME_ATTACK && gRaceMultiConfig->mFirstGhostRecordFilled == 1) {
            MI_CpuCopy8(&gRaceMultiConfig->mFirstGhostRecordMillisecond, &setupTime, 4);
            hasSetupTime = TRUE;
        } else {
            hasSetupTime = FALSE;
        }
        if (hasSetupTime != FALSE) {
            rstat_getDriverTotalTime((u16) gRaceMultiConfig->mEntryIndex, &finishTime.mMinute, &finishTime.mSecond,
                              &finishTime.mMillisecond);
            if (IsTimeLessThan(&finishTime, &setupTime) != FALSE) {
                r = TRUE;
            }
        } else {
            r = TRUE;
        }
    }
    if (r != FALSE) {
        r2dtar_sStatus->mUnk_18 = 1;
        savd_storePersonalGhost(gRaceMultiConfig->mCourseId, gRaceMultiConfig->mEntryIndex);
        r2dtar_sStatus->mUpdate = func_020c5f08;
        r2dtar_sStatus->mUpdateFrames = 0;
    } else {
        r2dtar_sStatus->mUnk_18 = 0;
        r2dtar_sStatus->mUpdate = ShowRaceNewRecordTaSubScreen;
        r2dtar_sStatus->mUpdateFrames = 0;
    }
}

void func_020c5f08(void) {
    s32 waiting;

    if (gSaveData->mBusy == 0) {
        waiting = gSaveCore->mBackupEnabled != 0 ? gSaveCore->mCommandRunning : 0;
    } else {
        waiting = 1;
    }
    if (waiting != 0) {
        return;
    }
    r2dtar_sStatus->mUnk_18 = 0;
    r2dtar_sStatus->mUpdate = ShowRaceNewRecordTaSubScreen;
    r2dtar_sStatus->mUpdateFrames = 0;
}

void ShowRaceNewRecordTaSubScreen(void) {
    if (GetShowLapTime() != 0) {
        return;
    }
    RequestRaceHudSubScreenState6();
    r2dtar_sStatus->mUpdate = SlideInRaceNewRecordTa;
    r2dtar_sStatus->mUpdateFrames = 0;
}

void SlideInRaceNewRecordTa(void) {
    s32 n;

    n = r2dtar_sStatus->mUpdateFrames;
    r2dtar_sStatus->mUpdateFrames = n + 1;
    if (n < 0x14) {
        r2dtar_sStatus->mOffsetX = mutil_interpolate(1, -0x100, 0, n, 0x14);
    } else {
        r2dtar_sStatus->mOffsetX = 0;
        r2dtar_sStatus->mUpdate = (void (*)(void)) func_020c5df0;
        r2dtar_sStatus->mUpdateFrames = 0;
    }
}

u32 func_020c5df0(void) {
    u32 value0;
    u32 value1;
    u32 value2;
    u32 value3;
    s32 frame;
    s32 limit;
    value0 = (u32) &r2dtar_sStatus;
    value3 = *(const u32 *) ((value0) + (0));
    value2 = r2dtar_sStatus->mUpdateFrames;
    value1 = (value2) + (1u);
    r2dtar_sStatus->mUpdateFrames = value1;
    frame = value2;
    limit = 0x3cu;
    if (frame < limit) {
        return value0;
    }
    value2 = *(const u32 *) ((value0) + (0));
    value3 = (u32) &func_020c5dd8;
    value1 = 0u;
    *(u32 *) ((value2) + (0)) = value3;
    value0 = *(const u32 *) ((value0) + (0));
    *(u32 *) ((value0) + (4)) = value1;
    return value0;
}

u32 func_020c5dd8(void) {
    u32 value0;
    u32 zero;
    value0 = (u32) &r2dtar_sStatus;
    zero = 0u;
    value0 = *(const u32 *) ((value0) + (0));
    *(u32 *) ((value0) + (220)) = zero;
    return value0;
}
