#include "Main/Save/mission_record.h"
#include "Main/Menu/title_scene.h"
#include "Main/Race/race_setup_input.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Graphics/disp_cap.h"
#include "Main/Save/backup_records_write.h"
#include "Main/Save/backup_bit_array.h"
#include "Main/Save/backup_first_block_start_write.h"
#include "Main/Save/backup_ghost_head.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "Main/System/input_slots.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/System/backup_net_camera_work.h"
#include "cpu_copy_fill.h"
#include "Main/Race/kart.h"
#include "Main/Save/ghost_record_file.h"
#include "Main/System/init_after_startup.h"

#pragma thumb on

void PackMissionRecord(MissionRecord *missionRecord, UnpackedMissionRecord *unpackedMissionRecord) {
    if (unpackedMissionRecord->mFilled != 0) {
        missionRecord->mFilled = 1;
        missionRecord->mValue = unpackedMissionRecord->mValue;
    } else {
        missionRecord->mFilled = 0;
    }
}

void UnpackMissionRecord(MissionRecord *missionRecord, UnpackedMissionRecord *unpackedMissionRecord) {
    if (missionRecord->mFilled != 0) {
        unpackedMissionRecord->mFilled = 1;
        unpackedMissionRecord->mValue = missionRecord->mValue;
    } else {
        unpackedMissionRecord->mFilled = 0;
    }
}

void SetMissionRecord(s32 row, s32 column, UnpackedMissionRecord *unpackedMissionRecord) {
    PackMissionRecord(&gBackupBuffers->mMissionRecordBlock->mRecords[(row - 1) * 9 + column - 1],
                      unpackedMissionRecord);
}

s32 GetMissionRecord(s32 row, s32 column, UnpackedMissionRecord *unpackedMissionRecord) {
    UnpackMissionRecord(&gBackupBuffers->mMissionRecordBlock->mRecords[(row - 1) * 9 + column - 1],
                        unpackedMissionRecord);
    return 1;
}

void SetEmblemRecordAndWriteBackup(void *emblemData) {
    MI_CpuCopy8(emblemData, gBackupBuffers->mEmblemRecord->mEmblemData,
                sizeof(gBackupBuffers->mEmblemRecord->mEmblemData));
    gBackupBuffers->mEmblemRecord->mFilled = 1;
    WriteBackupEmblem();
}

void FillAndWriteCourseGhostRecord(s32 courseId, u16 entryIndex) {
    GhostRecord *ghostRecord;
    s32 playerIndex;
    s32 cupCourseIndex;
    u8 courseIndexByte;
    u8 lapNumber;
    u8 byteOffset;
    s32 clockDate[4];
    KartTime kartTime;
    u8 lapBytes[0xf];
    u32 tempValue;

    cupCourseIndex = FindCupCourseIndex();
    playerIndex = gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mIndex;
    ghostRecord = gBackupBuffers->mCourseGhostRecord;
    if (cupCourseIndex == -1) {
        return;
    }
    MI_CpuFill8(ghostRecord, 0, sizeof(GhostRecord));
    GetClockDateOrDefault(clockDate);
    ghostRecord->mHead.mYear = clockDate[0];
    ghostRecord->mHead.mMonth = clockDate[1];
    ghostRecord->mHead.mDay = clockDate[2];
    tempValue = gRaceSetup->mCurrentEntries[entryIndex].mCharacterIndex;
    ghostRecord->mHead.mCharacterIndex = (u8) tempValue;
    tempValue = gRaceSetup->mCurrentEntries[entryIndex].mKartIndex;
    ghostRecord->mHead.mKartIndex = (u8) tempValue;
    tempValue = gRaceSetup->mCourseId;
    ghostRecord->mHead.mCourseId = (u8) tempValue;
    ghostRecord->mHead.mFilled = 1;
    ghostRecord->mHead.mHasEmblem = 0;
    ghostRecord->mHead.mRegion = gStartupWork->mRegion;
    ghostRecord->mHead.mUnk_08_4 = 0;
    ghostRecord->mHead.mLowestGrandPrixRecordValue = GetLowestGrandPrixRecordValue();
    GetKartFinishTime(entryIndex, &kartTime.mMinute, &kartTime.mSecond, &kartTime.mMillisecond);
    ghostRecord->mHead.mMinute = kartTime.mMinute;
    ghostRecord->mHead.mSecond = kartTime.mSecond;
    ghostRecord->mHead.mMillisecond = kartTime.mMillisecond;
    MI_CpuCopy8(gBackupBuffers->mFirstBlock->mPlayerName, ghostRecord->mHead.mName, sizeof(ghostRecord->mHead.mName));
    MI_CpuCopy8(gInputSlots[playerIndex].mKeyRecording.mBuffer, ghostRecord->mKeyRecordingBuffer,
                sizeof(KeyRecordingBuffer));
    MI_CpuFill8(lapBytes, 0, 0xf);
    for (lapNumber = 1; lapNumber <= GetLapCount(); lapNumber++) {
        byteOffset = (lapNumber - 1) * 3;
        GetKartLapTime(entryIndex, lapNumber, &kartTime.mMinute, &kartTime.mSecond, &kartTime.mMillisecond);
        tempValue = 0;
        tempValue |= (kartTime.mMinute & 0x7f) << 17;
        tempValue |= (kartTime.mSecond & 0x7f) << 10;
        tempValue |= kartTime.mMillisecond & 0x3ff;
        lapBytes[byteOffset] = tempValue >> 16;
        lapBytes[byteOffset + 1] = tempValue >> 8;
        lapBytes[byteOffset + 2] = tempValue;
    }
    MI_CpuCopy8(lapBytes, ghostRecord->mHead.mLapTimes, 0xf);
    courseIndexByte = cupCourseIndex;
    WriteBackupCourseGhost(courseIndexByte, ghostRecord);
    if (IsCourseGhostBitSet(courseIndexByte) == 0) {
        SetBitArrayBit(courseIndexByte, gBackupBuffers->mFirstBlock->mCourseGhostBits, 4);
        StartWriteBackupFirstBlock();
    }
}

void ReadCourseGhostRecord(u32 courseId) {
    s32 cupCourseIndex;
    BOOL noGhost;
    GhostRecord *ghostRecord;

    noGhost = FALSE;
    cupCourseIndex = FindCupCourseIndex(courseId);
    ghostRecord = gBackupBuffers->mCourseGhostRecord;
    if (cupCourseIndex == -1) {
        noGhost = TRUE;
    } else if (IsCourseGhostBitSet(cupCourseIndex) == 0) {
        noGhost = TRUE;
    }
    if (noGhost != FALSE) {
        ghostRecord->mHead.mFilled = 0;
    } else {
        ReadBackupCourseGhost(cupCourseIndex, ghostRecord);
    }
}

#pragma thumb off
