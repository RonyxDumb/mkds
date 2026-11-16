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

struct RaceNewRecordTa *g_GlobalE8;

u32 GetLeastTimeLapId(void) {
    return (g_GlobalE8->mBestLapNumber);
}

BOOL IsSavingTimeTrialRecord(void) {
    return g_GlobalE8 != NULL ? g_GlobalE8->mSaving : 0;
}

BOOL IsRaceNewRecordTaRunning(void) {
    return g_GlobalE8 != NULL ? g_GlobalE8->mRunning : 0;
}

void CreateGlobalE8(void) {
    s32 recordIndex;

    if (g_GlobalCO->mMode != MODE_TIME_ATTACK) {
        return;
    }
    g_GlobalE8 = Mem_AllocateHeap(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()), sizeof(*g_GlobalE8));
    g_GlobalE8->mUpdate = StructE8_SomeFnHandle;
    g_GlobalE8->mUpdateFrames = 0;
    g_GlobalE8->mFinishTimeIsRecord = 0;
    g_GlobalE8->mFinishRecordIndex = -1;
    g_GlobalE8->mBestLapIsRecord = 0;
    g_GlobalE8->mBestLapNumber = 0;
    g_GlobalE8->mSaving = 0;
    for (recordIndex = 0; recordIndex < 6; recordIndex++) {
        TimeTrialRecord_CopyFrom_from_thumb(g_GlobalCO->mCourseId, recordIndex, &g_GlobalE8->mRecords[recordIndex]);
    }
    g_GlobalE8->mSaving = 0;
    g_GlobalE8->mRunning = 0;
    g_GlobalE8->mOffsetX = -0x100;
    g_GlobalE8->mCycleFrames = 0;
}

void ResetGlobalE8(void) {
    if (g_GlobalCO->mMode == MODE_TIME_ATTACK) {
        g_GlobalE8 = NULL;
    }
}

void InvokeE8Handler(void) {
    if (g_GlobalCO->mMode != MODE_TIME_ATTACK) {
        return;
    }
    g_GlobalE8->mUpdate();
    g_GlobalE8->mCycleFrames = g_GlobalE8->mCycleFrames + 1;
    if (g_GlobalE8->mCycleFrames >= RACE_NEW_RECORD_TA_CYCLE_FRAMES) {
        g_GlobalE8->mCycleFrames = 0;
    }
}

void StructRA_SomeFn_6(RaceHudOamBuffer *oamBuffer, s32 baseX, s32 baseY, TimeRecord *record) {
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
        cell = GetB3C4_Cell_RaceNewRecordTaS(digits.mDigits[0] + 0xe);
        digit0Position[0] = TO_FIXED12(baseX + cellOffsets[0]);
        digit0Position[1] = TO_FIXED12(baseY);
        oamIndex = oamBuffer->mOamCount;
        oamBuffer->mOamCount +=
            MaybeMakeOamSlot(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cell, NULL, digit0Position, 0, 1);
    }
    cell = GetB3C4_Cell_RaceNewRecordTaS(digits.mDigits[1] + 0xe);
    digit1Position[0] = TO_FIXED12(baseX + cellOffsets[1]);
    digit1Position[1] = TO_FIXED12(baseY);
    oamIndex = oamBuffer->mOamCount;
    oamBuffer->mOamCount +=
        MaybeMakeOamSlot(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cell, NULL, digit1Position, 0, 1);
    cell = GetB3C4_Cell_RaceNewRecordTaS(0x18);
    firstSeparatorPosition[0] = TO_FIXED12(baseX + cellOffsets[2]);
    firstSeparatorPosition[1] = TO_FIXED12(baseY);
    oamIndex = oamBuffer->mOamCount;
    oamBuffer->mOamCount +=
        MaybeMakeOamSlot(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cell, NULL, firstSeparatorPosition, 0, 1);
    cell = GetB3C4_Cell_RaceNewRecordTaS(digits.mDigits[2] + 0xe);
    digit2Position[0] = TO_FIXED12(baseX + cellOffsets[3]);
    digit2Position[1] = TO_FIXED12(baseY);
    oamIndex = oamBuffer->mOamCount;
    oamBuffer->mOamCount +=
        MaybeMakeOamSlot(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cell, NULL, digit2Position, 0, 1);
    cell = GetB3C4_Cell_RaceNewRecordTaS(digits.mDigits[3] + 0xe);
    digit3Position[0] = TO_FIXED12(baseX + cellOffsets[4]);
    digit3Position[1] = TO_FIXED12(baseY);
    oamIndex = oamBuffer->mOamCount;
    oamBuffer->mOamCount +=
        MaybeMakeOamSlot(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cell, NULL, digit3Position, 0, 1);
    cell = GetB3C4_Cell_RaceNewRecordTaS(0x18);
    secondSeparatorPosition[0] = TO_FIXED12(baseX + cellOffsets[5]);
    secondSeparatorPosition[1] = TO_FIXED12(baseY);
    oamIndex = oamBuffer->mOamCount;
    oamBuffer->mOamCount +=
        MaybeMakeOamSlot(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cell, NULL, secondSeparatorPosition, 0, 1);
    cell = GetB3C4_Cell_RaceNewRecordTaS(digits.mDigits[4] + 0xe);
    digit4Position[0] = TO_FIXED12(baseX + cellOffsets[6]);
    digit4Position[1] = TO_FIXED12(baseY);
    oamIndex = oamBuffer->mOamCount;
    oamBuffer->mOamCount +=
        MaybeMakeOamSlot(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cell, NULL, digit4Position, 0, 1);
    cell = GetB3C4_Cell_RaceNewRecordTaS(digits.mDigits[5] + 0xe);
    digit5Position[0] = TO_FIXED12(baseX + cellOffsets[7]);
    digit5Position[1] = TO_FIXED12(baseY);
    oamIndex = oamBuffer->mOamCount;
    oamBuffer->mOamCount +=
        MaybeMakeOamSlot(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cell, NULL, digit5Position, 0, 1);
    cell = GetB3C4_Cell_RaceNewRecordTaS(digits.mDigits[6] + 0xe);
    digit6Position[0] = TO_FIXED12(baseX + cellOffsets[8]);
    digit6Position[1] = TO_FIXED12(baseY);
    oamIndex = oamBuffer->mOamCount;
    oamBuffer->mOamCount +=
        MaybeMakeOamSlot(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cell, NULL, digit6Position, 0, 1);
}

void StructRA_SomeFn_5(RaceHudOamBuffer *oamBuffer, s32 index, s32 baseX, s32 baseY) {
    s32 firstCellPosition[2];
    s32 secondCellPosition[2];
    TimeRecord record;
    s32 cycleFrames;
    BOOL isNewRecord;
    s32 oamIndex;
    void *cell;
    RaceNewRecordTa *newRecordTa;

    newRecordTa = g_GlobalE8;
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
        cell = GetB3C4_Cell_RaceNewRecordTaS(index + 7);
        firstCellPosition[0] = TO_FIXED12(baseX + 0x32);
        firstCellPosition[1] = TO_FIXED12(baseY);
        oamIndex = oamBuffer->mOamCount;
        oamBuffer->mOamCount +=
            MaybeMakeOamSlot(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cell, NULL, firstCellPosition, 0, 1);
        cell = GetB3C4_Cell_RaceNewRecordTaS(index + 0x1a);
        secondCellPosition[0] = TO_FIXED12(baseX + 0x3d);
        secondCellPosition[1] = TO_FIXED12(baseY);
        oamIndex = oamBuffer->mOamCount;
        oamBuffer->mOamCount +=
            MaybeMakeOamSlot(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cell, NULL, secondCellPosition, 0, 1);
    }
    if (isNewRecord != FALSE && cycleFrames >= 0x10) {
        return;
    }
    StructRA_SomeFn_6(oamBuffer, baseX + 0xab, baseY, &record);
}

void StructRA_SomeFn_4(RaceHudOamBuffer *oamBuffer) {
    s32 headerPosition[2];
    s32 rowPosition[2];
    s32 lastRowPosition[2];
    s32 unusedPosition[2];
    u16 rowIndex;
    s32 oamIndex;
    s32 rowY;
    void *cell;

    cell = GetB3C4_Cell_RaceNewRecordTaS(0);
    headerPosition[0] = TO_FIXED12(g_GlobalE8->mOffsetX + 0x80);
    headerPosition[1] = 0xc000;
    oamIndex = oamBuffer->mOamCount;
    oamBuffer->mOamCount +=
        MaybeMakeOamSlot(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cell, NULL, headerPosition, 0, 1);
    for (rowIndex = 0; rowIndex < 5; rowIndex++) {
        cell = GetB3C4_Cell_RaceNewRecordTaS(rowIndex + 1);
        rowY = rowIndex * 0x18 + 0x28;
        rowPosition[0] = TO_FIXED12(g_GlobalE8->mOffsetX);
        rowPosition[1] = (rowIndex * 0x18 + 0x28) << 12;
        oamIndex = oamBuffer->mOamCount;
        oamBuffer->mOamCount +=
            MaybeMakeOamSlot(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cell, NULL, rowPosition, 0, 1);
        StructRA_SomeFn_5(oamBuffer, rowIndex, g_GlobalE8->mOffsetX, rowY);
    }
    cell = GetB3C4_Cell_RaceNewRecordTaS(6);
    lastRowPosition[0] = TO_FIXED12(g_GlobalE8->mOffsetX);
    lastRowPosition[1] = 0x9f000;
    oamIndex = oamBuffer->mOamCount;
    oamBuffer->mOamCount +=
        MaybeMakeOamSlot(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cell, NULL, lastRowPosition, 0, 1);
    StructRA_SomeFn_5(oamBuffer, rowIndex, g_GlobalE8->mOffsetX + 1, 0xb4);
}

BOOL CheckHandleSaveTimeTrialRecord2(s32 store) {
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

    GetPlayerTotalTime(GetCurrentPlayerRacerId(), &minute, &second, &millisecond);
    record = g_GlobalE8->mRecords;
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
            g_GlobalE8->mRecords[shiftIndex] = g_GlobalE8->mRecords[shiftIndex - 1];
            TimeTrialCopyToSaveData_from_thumb(g_GlobalCO->mCourseId, shiftIndex, &g_GlobalE8->mRecords[shiftIndex]);
        }
        copiedMillisecond = millisecond;
        copiedSecond = second;
        copiedMinute = minute;
        records = g_GlobalE8->mRecords;
        slot = records + recordIndex;
        slot->mMinute = copiedMinute;
        slot->mSecond = copiedSecond;
        records[recordIndex].mMillisecond = copiedMillisecond;
        CopyMemory16(g_GlobalCO->mCurrentEntries[GetCurrentPlayerRacerId()].mPlayer.mName, slot->mName, 0x14);
        slot->mFilled = 1;
        slot->mCharacterIndex = g_GlobalCO->mCurrentEntries[GetCurrentPlayerRacerId()].mCharacterIndex;
        slot->mKartIndex = g_GlobalCO->mCurrentEntries[GetCurrentPlayerRacerId()].mKartIndex;
        TimeTrialCopyToSaveData_from_thumb(g_GlobalCO->mCourseId, recordIndex, slot);
        if (recordIndex != 5) {
            g_GlobalE8->mFinishRecordIndex = recordIndex;
        }
    } else {
        g_GlobalE8->mFinishRecordIndex = recordIndex;
    }
    return TRUE;
}

BOOL CheckHandleSaveTimeTrialRecord_LeastLap(s32 store) {
    u8 minute;
    u8 second;
    u16 millisecond;
    TimeRecord *record;
    TimeRecord *records;
    u8 copiedMinute;
    u8 copiedSecond;
    u16 copiedMillisecond;

    record = &g_GlobalE8->mRecords[TIME_RECORD_BEST_LAP];
    g_GlobalE8->mBestLapNumber =
        GetLeastTimeLap(GetCurrentPlayerRacerId(), &minute, &second, &millisecond);
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
        records = g_GlobalE8->mRecords;
        record = records + TIME_RECORD_BEST_LAP;
        record->mMinute = copiedMinute;
        record->mSecond = copiedSecond;
        records[TIME_RECORD_BEST_LAP].mMillisecond = copiedMillisecond;
        CopyMemory16(g_GlobalCO->mCurrentEntries[GetCurrentPlayerRacerId()].mPlayer.mName, record->mName, 0x14);
        record->mFilled = 1;
        record->mCharacterIndex = g_GlobalCO->mCurrentEntries[GetCurrentPlayerRacerId()].mCharacterIndex;
        record->mKartIndex = g_GlobalCO->mCurrentEntries[GetCurrentPlayerRacerId()].mKartIndex;
        TimeTrialCopyToSaveData_from_thumb(g_GlobalCO->mCourseId, TIME_RECORD_BEST_LAP, record);
    }
    return TRUE;
}

void StructE8_SomeFnHandle(void) {
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

    if (g_GlobalMV->mRaceDone == 0) {
        return;
    }
    if (GetShowLapTime() != 0) {
        return;
    }
    if (g_GlobalCO->mRaceKind == RACE_KIND_NORMAL) {
        g_GlobalE8->mFinishTimeIsRecord = CheckHandleSaveTimeTrialRecord2(1);
        g_GlobalE8->mBestLapIsRecord = CheckHandleSaveTimeTrialRecord_LeastLap(1);
        if (g_GlobalE8->mFinishTimeIsRecord != 0 || g_GlobalE8->mBestLapIsRecord != 0) {
            g_GlobalE8->mSaving = 1;
            WriteTimeTrialsSaveDataSection_from_thumb();
            g_GlobalE8->mUpdate = StructE8_SomeFnHandle4;
            g_GlobalE8->mUpdateFrames = 0;
        } else {
            storeGhost = FALSE;
            if (IsRaceKeyRecordingNotFull() != 0) {
                if (g_GlobalCO->mMode == MODE_TIME_ATTACK && g_GlobalCO->mFirstGhostRecordFilled == 1) {
                    Mem_CpuCopy8(&g_GlobalCO->mFirstGhostRecordMillisecond, &setupTime, 4);
                    hasSetupTime = TRUE;
                } else {
                    hasSetupTime = FALSE;
                }
                if (hasSetupTime != FALSE) {
                    GetPlayerTotalTime((u16) g_GlobalCO->mEntryIndex, &finishTime.mMinute, &finishTime.mSecond,
                                      &finishTime.mMillisecond);
                    if (StructRCTime_SmallerThan_from_thumb(&finishTime, &setupTime) != FALSE) {
                        storeGhost = TRUE;
                    }
                } else {
                    storeGhost = TRUE;
                }
            }
            if (storeGhost != FALSE) {
                g_GlobalE8->mSaving = 1;
                FillPersonalGhostData_from_thumb(g_GlobalCO->mCourseId, g_GlobalCO->mEntryIndex);
                g_GlobalE8->mUpdate = StructE8_SomeFnHandle3;
                g_GlobalE8->mUpdateFrames = 0;
            } else {
                g_GlobalE8->mUpdate = StructE8_SomeFnHandle2;
                g_GlobalE8->mUpdateFrames = 0;
            }
        }
    } else {
        GetPlayerTotalTime(GetCurrentPlayerRacerId(), &minute, &second, &millisecond);
        records = g_GlobalE8->mRecords;
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
        g_GlobalE8->mFinishTimeIsRecord = recordIndex;
        record = &g_GlobalE8->mRecords[TIME_RECORD_BEST_LAP];
        g_GlobalE8->mBestLapNumber =
            GetLeastTimeLap(GetCurrentPlayerRacerId(), &bestLapMinute, &bestLapSecond, &bestLapMillisecond);
        if (bestLapMinute == record->mMinute && bestLapSecond == record->mSecond &&
            bestLapMillisecond == record->mMillisecond) {
            storeGhost = TRUE;
        } else {
            storeGhost = FALSE;
        }
        g_GlobalE8->mBestLapIsRecord = storeGhost;
        g_GlobalE8->mUpdate = StructE8_SomeFnHandle2;
        g_GlobalE8->mUpdateFrames = 0;
    }
    g_GlobalE8->mRunning = 1;
}

void StructE8_SomeFnHandle4(void) {
    MinuteSecondMillisecondTime setupTime;
    MinuteSecondMillisecondTime finishTime;
    BOOL storeGhost;
    BOOL hasSetupTime;
    s32 waiting;

    if (g_SaveDataHolder->mBusy == 0) {
        waiting = g_SaveDataIoManager->mBackupEnabled != 0 ? g_SaveDataIoManager->mCommandRunning : 0;
    } else {
        waiting = 1;
    }
    if (waiting != 0) {
        return;
    }
    storeGhost = FALSE;
    if (IsRaceKeyRecordingNotFull() != 0) {
        if (g_GlobalCO->mMode == MODE_TIME_ATTACK && g_GlobalCO->mFirstGhostRecordFilled == 1) {
            Mem_CpuCopy8(&g_GlobalCO->mFirstGhostRecordMillisecond, &setupTime, 4);
            hasSetupTime = TRUE;
        } else {
            hasSetupTime = FALSE;
        }
        if (hasSetupTime != FALSE) {
            GetPlayerTotalTime((u16) g_GlobalCO->mEntryIndex, &finishTime.mMinute, &finishTime.mSecond,
                              &finishTime.mMillisecond);
            if (StructRCTime_SmallerThan_from_thumb(&finishTime, &setupTime) != FALSE) {
                storeGhost = TRUE;
            }
        } else {
            storeGhost = TRUE;
        }
    }
    if (storeGhost != FALSE) {
        g_GlobalE8->mSaving = 1;
        FillPersonalGhostData_from_thumb(g_GlobalCO->mCourseId, g_GlobalCO->mEntryIndex);
        g_GlobalE8->mUpdate = StructE8_SomeFnHandle3;
        g_GlobalE8->mUpdateFrames = 0;
    } else {
        g_GlobalE8->mSaving = 0;
        g_GlobalE8->mUpdate = StructE8_SomeFnHandle5;
        g_GlobalE8->mUpdateFrames = 0;
    }
}

void StructE8_SomeFnHandle3(void) {
    s32 waiting;

    if (g_SaveDataHolder->mBusy == 0) {
        waiting = g_SaveDataIoManager->mBackupEnabled != 0 ? g_SaveDataIoManager->mCommandRunning : 0;
    } else {
        waiting = 1;
    }
    if (waiting != 0) {
        return;
    }
    g_GlobalE8->mSaving = 0;
    g_GlobalE8->mUpdate = StructE8_SomeFnHandle5;
    g_GlobalE8->mUpdateFrames = 0;
}

void StructE8_SomeFnHandle5(void) {
    if (GetShowLapTime() != 0) {
        return;
    }
    RequestRaceHudSubScreenNewRecord();
    g_GlobalE8->mUpdate = StructE8_SomeFnHandle2;
    g_GlobalE8->mUpdateFrames = 0;
}

void StructE8_SomeFnHandle2(void) {
    s32 frame;

    frame = g_GlobalE8->mUpdateFrames;
    g_GlobalE8->mUpdateFrames = frame + 1;
    if (frame < 0x14) {
        g_GlobalE8->mOffsetX = ComputeValueInterpolation_from_thumb(1, -0x100, 0, frame, 0x14);
    } else {
        g_GlobalE8->mOffsetX = 0;
        g_GlobalE8->mUpdate = StructE8_SomeFnHandle6;
        g_GlobalE8->mUpdateFrames = 0;
    }
}

void StructE8_SomeFnHandle6(void) {
    s32 frame;

    frame = g_GlobalE8->mUpdateFrames;
    g_GlobalE8->mUpdateFrames = frame + 1;
    if (frame < 0x3c) {
        return;
    }
    g_GlobalE8->mUpdate = StructE8_SomeFnHandle7;
    g_GlobalE8->mUpdateFrames = 0;
}

void StructE8_SomeFnHandle7(void) {
    g_GlobalE8->mRunning = 0;
}
