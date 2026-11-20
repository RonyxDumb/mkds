#include "Main/Save/backup_bit_array.h"
#include "Main/Save/bit_array_byte.h"
#include "Main/Race/gp_records_killer.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"
#include "Main/System/backup_net_camera_work.h"
#include "cpu_copy_fill.h"
#include "friend_data_account_fields.h"
#include "Main/Save/ghost_record_file.h"

#pragma thumb on

void SetBitArrayBit(s32 bitIndex, u8 *bytes, s32 unused) {
    u8 *bitArrayByte;

    bitArrayByte = GetBitArrayByte(bitIndex, bytes);
    *bitArrayByte |= 1 << (u8) (bitIndex % 8);
}

BOOL IsBitArrayBitSet(s32 bitIndex, u8 *bytes, s32 unused) {
    u8 *bitArrayByte;

    bitArrayByte = GetBitArrayByte(bitIndex, bytes);
    return (*bitArrayByte & (1 << (u8) (bitIndex % 8))) != 0 ? 1 : 0;
}

void ClearBitArrayBit(s32 bitIndex, u8 *bytes, s32 unused) {
    u8 *bitArrayByte;

    bitArrayByte = GetBitArrayByte(bitIndex, bytes);
    *bitArrayByte &= ~(1 << (u8) (bitIndex % 8));
}

BOOL IsCourseGhostBitSet(u8 bitIndex) {
    return IsBitArrayBitSet(bitIndex, gBackupBuffers->mFirstBlock->mCourseGhostBits, 4);
}

void ClearCourseGhostBit(s32 bitIndex) {
    ClearBitArrayBit(bitIndex, gBackupBuffers->mFirstBlock->mCourseGhostBits, 4);
}

BOOL IsSlotGhostBitSet(u32 bitIndex) {
    return IsBitArrayBitSet(bitIndex, gBackupBuffers->mFirstBlock->mSlotGhostBits, 2);
}

void ResetBackupFirstBlock(s32 copyOwnerName) {
    u16 ownerCharCount;
    u16 *ownerText;

    MI_CpuFill8(gBackupBuffers->mFirstBlock, 0, sizeof(BackupFirstBlock));
    if (copyOwnerName != 0) {
        ownerCharCount = gStartupWork->mOwnerCharCount;
        ownerText = gStartupWork->mOwnerText;
        gBackupBuffers->mFirstBlock->mHasPlayerName = 1;
        MI_CpuFill8(gBackupBuffers->mFirstBlock->mPlayerName, 0, sizeof(gBackupBuffers->mFirstBlock->mPlayerName));
        MI_CpuCopy8(ownerText, gBackupBuffers->mFirstBlock->mPlayerName, ((u32) ownerCharCount << 17) >> 16);
    }
    gBackupBuffers->mFirstBlock->mSoundMode = SOUND_MODE_SURROUND;
    gBackupBuffers->mFirstBlock->mEmblemOff = 0;
    gBackupBuffers->mFirstBlock->mLocateFriendOff = 0;
    gBackupBuffers->mFirstBlock->mElo = BACKUP_ELO_INITIAL;
    SetSecretMessageFlagsWrapper();
    DWC_CreateUserData(&gBackupBuffers->mFirstBlock->mUserData, 0x414d434a);
}

#pragma thumb off
