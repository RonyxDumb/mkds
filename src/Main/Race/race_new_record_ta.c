#include "Main/Race/race_new_record_ta.h"
#include "Main/System/heap.h"
#include "Main/Save/mission_record.h"
#include "Main/Race/race_hud_kart_removed.h"
#include "Main/Race/race_item_slot.h"
#include "Main/Race/race_hud_sub_screen_cells.h"

#include "Main/System/heap_call.h"
#include "Main/Save/backup_records_write.h"
#include "Main/Save/course_time_record.h"
#include "Main/Race/race_hud_draw.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "model_material_set.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Race/graphic_file_loaders_and_matrix2x2.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Race/race_ncer_entry_getters.h"
#include "sprite_animation_control.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/System/backup_net_camera_work.h"
#include "cpu_copy_clear_16.h"
#include "cell_animation.h"
#include "cpu_copy_fill.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/record_time_attack_requests.h"
#include "Main/Race/kart.h"
#include "Main/Save/ghost_record_file.h"
#include "Main/System/init_after_startup.h"

struct RaceNewRecordTa *gRaceNewRecordTa;

u32 GetRaceNewRecordTaBestLapNumber(void) {
    return (gRaceNewRecordTa->mBestLapNumber);
}

BOOL IsRaceNewRecordTaSaving(void) {
    return gRaceNewRecordTa != NULL ? gRaceNewRecordTa->mSaving : 0;
}

BOOL IsRaceNewRecordTaRunning(void) {
    return gRaceNewRecordTa != NULL ? gRaceNewRecordTa->mRunning : 0;
}

void InitRaceNewRecordTa(void) {
    s32 recordIndex;

    if (gRaceSetup->mMode != MODE_TIME_ATTACK) {
        return;
    }
    gRaceNewRecordTa = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(*gRaceNewRecordTa));
    gRaceNewRecordTa->mUpdate = StartRaceNewRecordTa;
    gRaceNewRecordTa->mUpdateFrames = 0;
    gRaceNewRecordTa->mFinishTimeIsRecord = 0;
    gRaceNewRecordTa->mFinishRecordIndex = -1;
    gRaceNewRecordTa->mBestLapIsRecord = 0;
    gRaceNewRecordTa->mBestLapNumber = 0;
    gRaceNewRecordTa->mSaving = 0;
    for (recordIndex = 0; recordIndex < 6; recordIndex++) {
        GetCourseTimeRecord(gRaceSetup->mCourseId, recordIndex, &gRaceNewRecordTa->mRecords[recordIndex]);
    }
    gRaceNewRecordTa->mSaving = 0;
    gRaceNewRecordTa->mRunning = 0;
    gRaceNewRecordTa->mOffsetX = -0x100;
    gRaceNewRecordTa->mCycleFrames = 0;
}

void ClearRaceNewRecordTaPointer(void) {
    if (gRaceSetup->mMode == MODE_TIME_ATTACK) {
        gRaceNewRecordTa = NULL;
    }
}

void UpdateRaceNewRecordTa(void) {
    if (gRaceSetup->mMode != MODE_TIME_ATTACK) {
        return;
    }
    gRaceNewRecordTa->mUpdate();
    gRaceNewRecordTa->mCycleFrames = gRaceNewRecordTa->mCycleFrames + 1;
    if (gRaceNewRecordTa->mCycleFrames >= RACE_NEW_RECORD_TA_CYCLE_FRAMES) {
        gRaceNewRecordTa->mCycleFrames = 0;
    }
}

void DrawRaceNewRecordTaTime(RaceHudOamBuffer *oamBuffer, s32 baseX, s32 baseY, TimeRecord *record) {
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
            digits.mDigits[5] = digits.mDigits[6] = RACE_NEW_RECORD_TA_BLANK_DIGIT;
    }
    if (digits.mDigits[0] != 0) {
        cell = GetRaceNewRecordTaSNcerEntry(digits.mDigits[0] + 0xe);
        digit0Position[0] = TO_FIXED12(baseX + cellOffsets[0]);
        digit0Position[1] = TO_FIXED12(baseY);
        oamIndex = oamBuffer->mOamCount;
        oamBuffer->mOamCount +=
            NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cell, NULL, digit0Position, 0, 1);
    }
    cell = GetRaceNewRecordTaSNcerEntry(digits.mDigits[1] + 0xe);
    digit1Position[0] = TO_FIXED12(baseX + cellOffsets[1]);
    digit1Position[1] = TO_FIXED12(baseY);
    oamIndex = oamBuffer->mOamCount;
    oamBuffer->mOamCount +=
        NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cell, NULL, digit1Position, 0, 1);
    cell = GetRaceNewRecordTaSNcerEntry(0x18);
    firstSeparatorPosition[0] = TO_FIXED12(baseX + cellOffsets[2]);
    firstSeparatorPosition[1] = TO_FIXED12(baseY);
    oamIndex = oamBuffer->mOamCount;
    oamBuffer->mOamCount +=
        NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cell, NULL, firstSeparatorPosition, 0, 1);
    cell = GetRaceNewRecordTaSNcerEntry(digits.mDigits[2] + 0xe);
    digit2Position[0] = TO_FIXED12(baseX + cellOffsets[3]);
    digit2Position[1] = TO_FIXED12(baseY);
    oamIndex = oamBuffer->mOamCount;
    oamBuffer->mOamCount +=
        NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cell, NULL, digit2Position, 0, 1);
    cell = GetRaceNewRecordTaSNcerEntry(digits.mDigits[3] + 0xe);
    digit3Position[0] = TO_FIXED12(baseX + cellOffsets[4]);
    digit3Position[1] = TO_FIXED12(baseY);
    oamIndex = oamBuffer->mOamCount;
    oamBuffer->mOamCount +=
        NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cell, NULL, digit3Position, 0, 1);
    cell = GetRaceNewRecordTaSNcerEntry(0x18);
    secondSeparatorPosition[0] = TO_FIXED12(baseX + cellOffsets[5]);
    secondSeparatorPosition[1] = TO_FIXED12(baseY);
    oamIndex = oamBuffer->mOamCount;
    oamBuffer->mOamCount +=
        NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cell, NULL, secondSeparatorPosition, 0, 1);
    cell = GetRaceNewRecordTaSNcerEntry(digits.mDigits[4] + 0xe);
    digit4Position[0] = TO_FIXED12(baseX + cellOffsets[6]);
    digit4Position[1] = TO_FIXED12(baseY);
    oamIndex = oamBuffer->mOamCount;
    oamBuffer->mOamCount +=
        NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cell, NULL, digit4Position, 0, 1);
    cell = GetRaceNewRecordTaSNcerEntry(digits.mDigits[5] + 0xe);
    digit5Position[0] = TO_FIXED12(baseX + cellOffsets[7]);
    digit5Position[1] = TO_FIXED12(baseY);
    oamIndex = oamBuffer->mOamCount;
    oamBuffer->mOamCount +=
        NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cell, NULL, digit5Position, 0, 1);
    cell = GetRaceNewRecordTaSNcerEntry(digits.mDigits[6] + 0xe);
    digit6Position[0] = TO_FIXED12(baseX + cellOffsets[8]);
    digit6Position[1] = TO_FIXED12(baseY);
    oamIndex = oamBuffer->mOamCount;
    oamBuffer->mOamCount +=
        NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cell, NULL, digit6Position, 0, 1);
}

void DrawRaceNewRecordTaRow(RaceHudOamBuffer *oamBuffer, s32 index, s32 baseX, s32 baseY) {
    s32 firstCellPosition[2];
    s32 secondCellPosition[2];
    TimeRecord record;
    s32 cycleFrames;
    BOOL isNewRecord;
    s32 oamIndex;
    void *cell;
    RaceNewRecordTa *newRecordTa;

    newRecordTa = gRaceNewRecordTa;
    cycleFrames = newRecordTa->mCycleFrames;
    isNewRecord = FALSE;
    record = newRecordTa->mRecords[index];
    if (index == 5) {
        if ((newRecordTa != NULL ? newRecordTa->mBestLapIsRecord : 0) != 0) {
            index = 0;
            isNewRecord = TRUE;
        } else {
            index = 6;
        }
    } else if (newRecordTa->mFinishTimeIsRecord == 0 || index < newRecordTa->mFinishRecordIndex) {
        index++;
    } else if (index == newRecordTa->mFinishRecordIndex) {
        index = 0;
        isNewRecord = TRUE;
    }
    if (record.mFilled != 0) {
        cell = GetRaceNewRecordTaSNcerEntry(index + 7);
        firstCellPosition[0] = TO_FIXED12(baseX + 0x32);
        firstCellPosition[1] = TO_FIXED12(baseY);
        oamIndex = oamBuffer->mOamCount;
        oamBuffer->mOamCount +=
            NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cell, NULL, firstCellPosition, 0, 1);
        cell = GetRaceNewRecordTaSNcerEntry(index + 0x1a);
        secondCellPosition[0] = TO_FIXED12(baseX + 0x3d);
        secondCellPosition[1] = TO_FIXED12(baseY);
        oamIndex = oamBuffer->mOamCount;
        oamBuffer->mOamCount +=
            NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cell, NULL, secondCellPosition, 0, 1);
    }
    if (isNewRecord != FALSE && cycleFrames >= 0x10) {
        return;
    }
    DrawRaceNewRecordTaTime(oamBuffer, baseX + 0xab, baseY, &record);
}

void DrawRaceNewRecordTa(RaceHudOamBuffer *oamBuffer) {
    s32 headerPosition[2];
    s32 rowPosition[2];
    s32 lastRowPosition[2];
    s32 unusedPosition[2];
    u16 rowIndex;
    s32 oamIndex;
    s32 rowY;
    void *cell;

    cell = GetRaceNewRecordTaSNcerEntry(0);
    headerPosition[0] = TO_FIXED12(gRaceNewRecordTa->mOffsetX + 0x80);
    headerPosition[1] = 0xc000;
    oamIndex = oamBuffer->mOamCount;
    oamBuffer->mOamCount +=
        NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cell, NULL, headerPosition, 0, 1);
    for (rowIndex = 0; rowIndex < 5; rowIndex++) {
        cell = GetRaceNewRecordTaSNcerEntry(rowIndex + 1);
        rowY = rowIndex * 0x18 + 0x28;
        rowPosition[0] = TO_FIXED12(gRaceNewRecordTa->mOffsetX);
        rowPosition[1] = (rowIndex * 0x18 + 0x28) << 12;
        oamIndex = oamBuffer->mOamCount;
        oamBuffer->mOamCount +=
            NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cell, NULL, rowPosition, 0, 1);
        DrawRaceNewRecordTaRow(oamBuffer, rowIndex, gRaceNewRecordTa->mOffsetX, rowY);
    }
    cell = GetRaceNewRecordTaSNcerEntry(6);
    lastRowPosition[0] = TO_FIXED12(gRaceNewRecordTa->mOffsetX);
    lastRowPosition[1] = 0x9f000;
    oamIndex = oamBuffer->mOamCount;
    oamBuffer->mOamCount +=
        NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cell, NULL, lastRowPosition, 0, 1);
    DrawRaceNewRecordTaRow(oamBuffer, rowIndex, gRaceNewRecordTa->mOffsetX + 1, 0xb4);
}

BOOL TryStoreRaceNewRecordTaFinishTime(s32 store) {
    u8 minute;
    u8 second;
    u16 millisecond;
    s32 recordIndex;
    s32 shiftIndex;
    TimeRecord *record;
    s32 totalMilliseconds;
    TimeRecord *slot;
    TimeRecord *records;
    u8 copiedMinute;
    u8 copiedSecond;
    u16 copiedMillisecond;

    GetKartFinishTime(GetFollowedKartOrEntryIndex(), &minute, &second, &millisecond);
    record = gRaceNewRecordTa->mRecords;
    totalMilliseconds = TIME_TO_MS(minute, second, millisecond);
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
        for (shiftIndex = 4; shiftIndex > recordIndex; shiftIndex--) {
            gRaceNewRecordTa->mRecords[shiftIndex] = gRaceNewRecordTa->mRecords[shiftIndex - 1];
            SetCourseTimeRecord(gRaceSetup->mCourseId, shiftIndex, &gRaceNewRecordTa->mRecords[shiftIndex]);
        }
        copiedMillisecond = millisecond;
        copiedSecond = second;
        copiedMinute = minute;
        records = gRaceNewRecordTa->mRecords;
        slot = records + recordIndex;
        slot->mMinute = copiedMinute;
        slot->mSecond = copiedSecond;
        records[recordIndex].mMillisecond = copiedMillisecond;
        MIi_CpuCopy16(gRaceSetup->mCurrentEntries[GetFollowedKartOrEntryIndex()].mPlayer.mName, slot->mName, 0x14);
        slot->mFilled = 1;
        slot->mCharacterIndex = gRaceSetup->mCurrentEntries[GetFollowedKartOrEntryIndex()].mCharacterIndex;
        slot->mKartIndex = gRaceSetup->mCurrentEntries[GetFollowedKartOrEntryIndex()].mKartIndex;
        SetCourseTimeRecord(gRaceSetup->mCourseId, recordIndex, slot);
        if (recordIndex != 5) {
            gRaceNewRecordTa->mFinishRecordIndex = recordIndex;
        }
    } else {
        gRaceNewRecordTa->mFinishRecordIndex = recordIndex;
    }
    return TRUE;
}

BOOL TryStoreRaceNewRecordTaBestLap(s32 store) {
    u8 minute;
    u8 second;
    u16 millisecond;
    TimeRecord *record;
    TimeRecord *records;
    u8 copiedMinute;
    u8 copiedSecond;
    u16 copiedMillisecond;

    record = &gRaceNewRecordTa->mRecords[TIME_RECORD_BEST_LAP];
    gRaceNewRecordTa->mBestLapNumber =
        GetKartBestLapTime(GetFollowedKartOrEntryIndex(), &minute, &second, &millisecond);
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
        records = gRaceNewRecordTa->mRecords;
        record = records + TIME_RECORD_BEST_LAP;
        record->mMinute = copiedMinute;
        record->mSecond = copiedSecond;
        records[TIME_RECORD_BEST_LAP].mMillisecond = copiedMillisecond;
        MIi_CpuCopy16(gRaceSetup->mCurrentEntries[GetFollowedKartOrEntryIndex()].mPlayer.mName, record->mName, 0x14);
        record->mFilled = 1;
        record->mCharacterIndex = gRaceSetup->mCurrentEntries[GetFollowedKartOrEntryIndex()].mCharacterIndex;
        record->mKartIndex = gRaceSetup->mCurrentEntries[GetFollowedKartOrEntryIndex()].mKartIndex;
        SetCourseTimeRecord(gRaceSetup->mCourseId, TIME_RECORD_BEST_LAP, record);
    }
    return TRUE;
}

void StartRaceNewRecordTa(void) {
    MinuteSecondMillisecondTime setupTime;
    MinuteSecondMillisecondTime finishTime;
    u8 minute;
    u8 second;
    u16 millisecond;
    u8 bestLapMinute;
    u8 bestLapSecond;
    u16 bestLapMillisecond;
    BOOL storeGhost;
    BOOL hasSetupTime;
    s32 totalMilliseconds;
    s32 recordIndex;
    s32 unusedCount;
    s32 unusedValue;
    TimeRecord *record;
    TimeRecord *records;

    if (gRaceProgress->mRaceDone == 0) {
        return;
    }
    if (GetShowLapTime() != 0) {
        return;
    }
    if (gRaceSetup->mRaceKind == RACE_KIND_NORMAL) {
        gRaceNewRecordTa->mFinishTimeIsRecord = TryStoreRaceNewRecordTaFinishTime(1);
        gRaceNewRecordTa->mBestLapIsRecord = TryStoreRaceNewRecordTaBestLap(1);
        if (gRaceNewRecordTa->mFinishTimeIsRecord != 0 || gRaceNewRecordTa->mBestLapIsRecord != 0) {
            gRaceNewRecordTa->mSaving = 1;
            WriteBackupCourseTimeRecords();
            gRaceNewRecordTa->mUpdate = StoreRaceNewRecordTaGhost;
            gRaceNewRecordTa->mUpdateFrames = 0;
        } else {
            storeGhost = FALSE;
            if (IsRaceKeyRecordingNotFull() != 0) {
                if (gRaceSetup->mMode == MODE_TIME_ATTACK && gRaceSetup->mFirstGhostRecordFilled == 1) {
                    MI_CpuCopy8(&gRaceSetup->mFirstGhostRecordMillisecond, &setupTime, 4);
                    hasSetupTime = TRUE;
                } else {
                    hasSetupTime = FALSE;
                }
                if (hasSetupTime != FALSE) {
                    GetKartFinishTime((u16) gRaceSetup->mEntryIndex, &finishTime.mMinute, &finishTime.mSecond,
                                      &finishTime.mMillisecond);
                    if (IsTimeLessThan(&finishTime, &setupTime) != FALSE) {
                        storeGhost = TRUE;
                    }
                } else {
                    storeGhost = TRUE;
                }
            }
            if (storeGhost != FALSE) {
                gRaceNewRecordTa->mSaving = 1;
                FillAndWriteCourseGhostRecord(gRaceSetup->mCourseId, gRaceSetup->mEntryIndex);
                gRaceNewRecordTa->mUpdate = AdvanceRaceNewRecordTaAfterSave;
                gRaceNewRecordTa->mUpdateFrames = 0;
            } else {
                gRaceNewRecordTa->mUpdate = SlideInRaceNewRecordTa;
                gRaceNewRecordTa->mUpdateFrames = 0;
            }
        }
    } else {
        GetKartFinishTime(GetFollowedKartOrEntryIndex(), &minute, &second, &millisecond);
        records = gRaceNewRecordTa->mRecords;
        totalMilliseconds = TIME_TO_MS(minute, second, millisecond);
        for (recordIndex = 4; recordIndex >= 0; recordIndex--) {
            record = &records[recordIndex];
            if (record->mFilled != 0 &&
                totalMilliseconds == record->mMillisecond + (record->mSecond * 1000 + record->mMinute * 60000)) {
                recordIndex = 1;
                goto found;
            }
        }
        recordIndex = 0;
    found:
        gRaceNewRecordTa->mFinishTimeIsRecord = recordIndex;
        record = &gRaceNewRecordTa->mRecords[TIME_RECORD_BEST_LAP];
        gRaceNewRecordTa->mBestLapNumber =
            GetKartBestLapTime(GetFollowedKartOrEntryIndex(), &bestLapMinute, &bestLapSecond, &bestLapMillisecond);
        if (bestLapMinute == record->mMinute && bestLapSecond == record->mSecond &&
            bestLapMillisecond == record->mMillisecond) {
            storeGhost = TRUE;
        } else {
            storeGhost = FALSE;
        }
        gRaceNewRecordTa->mBestLapIsRecord = storeGhost;
        gRaceNewRecordTa->mUpdate = SlideInRaceNewRecordTa;
        gRaceNewRecordTa->mUpdateFrames = 0;
    }
    gRaceNewRecordTa->mRunning = 1;
}

void StoreRaceNewRecordTaGhost(void) {
    MinuteSecondMillisecondTime setupTime;
    MinuteSecondMillisecondTime finishTime;
    BOOL storeGhost;
    BOOL hasSetupTime;
    s32 waiting;

    if (gBackupBuffers->mBusy == 0) {
        waiting = gBackupAccess->mBackupEnabled != 0 ? gBackupAccess->mCommandRunning : 0;
    } else {
        waiting = 1;
    }
    if (waiting != 0) {
        return;
    }
    storeGhost = FALSE;
    if (IsRaceKeyRecordingNotFull() != 0) {
        if (gRaceSetup->mMode == MODE_TIME_ATTACK && gRaceSetup->mFirstGhostRecordFilled == 1) {
            MI_CpuCopy8(&gRaceSetup->mFirstGhostRecordMillisecond, &setupTime, 4);
            hasSetupTime = TRUE;
        } else {
            hasSetupTime = FALSE;
        }
        if (hasSetupTime != FALSE) {
            GetKartFinishTime((u16) gRaceSetup->mEntryIndex, &finishTime.mMinute, &finishTime.mSecond,
                              &finishTime.mMillisecond);
            if (IsTimeLessThan(&finishTime, &setupTime) != FALSE) {
                storeGhost = TRUE;
            }
        } else {
            storeGhost = TRUE;
        }
    }
    if (storeGhost != FALSE) {
        gRaceNewRecordTa->mSaving = 1;
        FillAndWriteCourseGhostRecord(gRaceSetup->mCourseId, gRaceSetup->mEntryIndex);
        gRaceNewRecordTa->mUpdate = AdvanceRaceNewRecordTaAfterSave;
        gRaceNewRecordTa->mUpdateFrames = 0;
    } else {
        gRaceNewRecordTa->mSaving = 0;
        gRaceNewRecordTa->mUpdate = ShowRaceNewRecordTaSubScreen;
        gRaceNewRecordTa->mUpdateFrames = 0;
    }
}

void AdvanceRaceNewRecordTaAfterSave(void) {
    s32 waiting;

    if (gBackupBuffers->mBusy == 0) {
        waiting = gBackupAccess->mBackupEnabled != 0 ? gBackupAccess->mCommandRunning : 0;
    } else {
        waiting = 1;
    }
    if (waiting != 0) {
        return;
    }
    gRaceNewRecordTa->mSaving = 0;
    gRaceNewRecordTa->mUpdate = ShowRaceNewRecordTaSubScreen;
    gRaceNewRecordTa->mUpdateFrames = 0;
}

void ShowRaceNewRecordTaSubScreen(void) {
    if (GetShowLapTime() != 0) {
        return;
    }
    RequestRaceHudSubScreenNewRecord();
    gRaceNewRecordTa->mUpdate = SlideInRaceNewRecordTa;
    gRaceNewRecordTa->mUpdateFrames = 0;
}

void SlideInRaceNewRecordTa(void) {
    s32 frame;

    frame = gRaceNewRecordTa->mUpdateFrames;
    gRaceNewRecordTa->mUpdateFrames = frame + 1;
    if (frame < 0x14) {
        gRaceNewRecordTa->mOffsetX = InterpolateS16(1, -0x100, 0, frame, 0x14);
    } else {
        gRaceNewRecordTa->mOffsetX = 0;
        gRaceNewRecordTa->mUpdate = HoldRaceNewRecordTa;
        gRaceNewRecordTa->mUpdateFrames = 0;
    }
}

void HoldRaceNewRecordTa(void) {
    s32 frame;

    frame = gRaceNewRecordTa->mUpdateFrames;
    gRaceNewRecordTa->mUpdateFrames = frame + 1;
    if (frame < 0x3c) {
        return;
    }
    gRaceNewRecordTa->mUpdate = FinishRaceNewRecordTa;
    gRaceNewRecordTa->mUpdateFrames = 0;
}

void FinishRaceNewRecordTa(void) {
    gRaceNewRecordTa->mRunning = 0;
}
