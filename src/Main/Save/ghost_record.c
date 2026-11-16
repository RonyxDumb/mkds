#include "Main/Save/ghost_record.h"
#include "Main/Save/backup_bit_array.h"
#include "Main/Save/backup_first_block_start_write.h"
#include "Main/Save/backup_ghost_head.h"
#include "Main/System/backup_net_camera_work.h"
#include "cpu_copy_fill.h"
#include "Main/Menu/select_race_rule_state.h"
#include "Main/Graphics/disp_cap.h"
#include "Main/Save/backup.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"
#include "friend_data_account_fields.h"
#include "Main/Save/ghost_record_file.h"

#pragma thumb on

void WriteSlotGhostRecord(u8 index, SlotGhostRecord *source) {
    int slotBit;
    SlotGhostRecord *destination;
    destination = gBackupBuffers->mSlotGhostRecords[0];
    source->mHead.mUnk_08 = source->mHead.mUnk_08 & ~GHOST_HEAD_FILLED_BIT | GHOST_HEAD_FILLED_BIT;
    MI_CpuCopy8(source, destination, (0x00001000u));
    WriteBackupSlotGhost(index, destination);
    slotBit = IsSlotGhostBitSet(index);
    if (slotBit == 0) {
        SetBitArrayBit(index, gBackupBuffers->mFirstBlock->mSlotGhostBits, 2);
        StartWriteBackupFirstBlock();
    }
}

#pragma thumb off

#pragma thumb on

void ReadSlotGhostRecord(u32 slotIndex) {
    SlotGhostRecord *ghostRecord;

    ghostRecord = gBackupBuffers->mSlotGhostRecords[0];
    if (IsSlotGhostBitSet(slotIndex) == 0) {
        ghostRecord->mHead.mFilled = 0;
    } else {
        ReadBackupSlotGhost(slotIndex, ghostRecord);
    }
}

s32 GetGhostLapTime(GhostRecordHead *ghostRecord, s32 lapNumber, MinuteSecondMillisecondTime *lapTime) {
    u8 byteOffset;
    u32 packedTime;

    byteOffset = (lapNumber - 1) * 3;
    packedTime = 0;
    if (ghostRecord->mFilled == 0) {
        return packedTime;
    }
    packedTime |= ghostRecord->mLapTimes[byteOffset] << 16;
    packedTime |= ghostRecord->mLapTimes[byteOffset + 1] << 8;
    packedTime |= ghostRecord->mLapTimes[byteOffset + 2];
    lapTime->mMinute = (packedTime >> 17) & 0x7f;
    lapTime->mSecond = (packedTime >> 10) & 0x7f;
    lapTime->mMillisecond = packedTime & 0x3ff;
    return 1;
}

BOOL GetGhostFinishTime(GhostRecordHead *ghostRecord, MinuteSecondMillisecondTime *finishTime) {
    if (ghostRecord->mFilled == 0) {
        return FALSE;
    }
    finishTime->mMinute = ghostRecord->mMinute;
    finishTime->mSecond = ghostRecord->mSecond;
    finishTime->mMillisecond = ghostRecord->mMillisecond;
    return TRUE;
}

s32 GetGhostLapTimeByIndex(s32 ghostRecordIndex, s32 lapNumber, MinuteSecondMillisecondTime *lapTime) {
    s32 result;

    result = 0;
    switch (ghostRecordIndex) {
        case GHOST_RECORD_INDEX_COURSE:
            result = GetGhostLapTime(&gBackupBuffers->mCourseGhostRecord->mHead, lapNumber, lapTime);
            break;
        case GHOST_RECORD_INDEX_FIRST_SLOT:
            result = GetGhostLapTime(&gBackupBuffers->mSlotGhostRecords[0]->mHead, lapNumber, lapTime);
            break;
        case GHOST_RECORD_INDEX_SECOND_SLOT:
            break;
    }
    return result;
}

s32 GetGhostFinishTimeByIndex(s32 ghostRecordIndex, MinuteSecondMillisecondTime *finishTime) {
    s32 result;

    result = 0;
    switch (ghostRecordIndex) {
        case GHOST_RECORD_INDEX_COURSE:
            result = GetGhostFinishTime(&gBackupBuffers->mCourseGhostRecord->mHead, finishTime);
            break;
        case GHOST_RECORD_INDEX_FIRST_SLOT:
            result = GetGhostFinishTime(&gBackupBuffers->mSlotGhostRecords[0]->mHead, finishTime);
            break;
        case GHOST_RECORD_INDEX_SECOND_SLOT:
            break;
    }
    return result;
}

void FillPlayerRecord(PlayerRecord *record) {
    MI_CpuCopy8(gBackupBuffers->mFirstBlock->mPlayerName, record->mName, sizeof(record->mName));
    if (gBackupBuffers->mEmblemRecord->mFilled != 0 && gBackupBuffers->mFirstBlock->mEmblemOff == 0) {
        record->mHasEmblem = 1;
        MI_CpuCopy8(gBackupBuffers->mEmblemRecord->mEmblemData, record->mEmblem, sizeof(record->mEmblem));
    } else {
        record->mHasEmblem = 0;
        MI_CpuFill8(record->mEmblem, 0, sizeof(record->mEmblem));
    }
    MI_CpuCopy8(gBackupBuffers->mFirstBlock->mFlags, record->mBits, sizeof(record->mBits));
    record->mRegion = gStartupWork->mRegion;
    record->mLanguageIndex = gStartupWork->mLanguageIndex;
    record->mElo = gBackupBuffers->mFirstBlock->mElo;
    record->mLowestGrandPrixRecordValue = GetLowestGrandPrixRecordValue();
    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
        MI_CpuFill8(&record->mFriendData, 0, 0xc);
    } else {
        DWC_CreateExchangeToken(&gBackupBuffers->mFirstBlock->mUserData, &record->mFriendData);
    }
}

#pragma thumb off
