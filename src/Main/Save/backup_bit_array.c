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
#include "Main/Sound/sound_seq.h"
#include "Main/System/backup_net_camera_work.h"
#include "cpu_copy_fill.h"
#include "friend_data_account_fields.h"
#include "Main/Save/ghost_record_file.h"

#pragma thumb on

void MaybeSetPersonalGhostForCoursePresent_from_thumb(s32 bitIndex, u8 *bytes, s32 unused) {
    u8 *bitArrayByte;

    bitArrayByte = GetGhostDataByteByCourse_from_thumb(bitIndex, bytes);
    *bitArrayByte |= 1 << (u8) (bitIndex % 8);
}

BOOL IsBitArrayBitSet(s32 bitIndex, u8 *bytes, s32 unused) {
    u8 *bitArrayByte;

    bitArrayByte = GetGhostDataByteByCourse_from_thumb(bitIndex, bytes);
    return (*bitArrayByte & (1 << (u8) (bitIndex % 8))) != 0 ? 1 : 0;
}

void ClearBitArrayBit(s32 bitIndex, u8 *bytes, s32 unused) {
    u8 *bitArrayByte;

    bitArrayByte = GetGhostDataByteByCourse_from_thumb(bitIndex, bytes);
    *bitArrayByte &= ~(1 << (u8) (bitIndex % 8));
}

BOOL MaybeHasPersonalGhostForCourse_from_thumb(u8 bitIndex) {
    return IsBitArrayBitSet(bitIndex, g_SaveDataHolder->mFirstBlock->mCourseGhostBits, 4);
}

void ClearCourseGhostBit(s32 bitIndex) {
    ClearBitArrayBit(bitIndex, g_SaveDataHolder->mFirstBlock->mCourseGhostBits, 4);
}

BOOL IsSlotGhostBitSet(u32 bitIndex) {
    return IsBitArrayBitSet(bitIndex, g_SaveDataHolder->mFirstBlock->mSlotGhostBits, 2);
}

void ClearSaveDataSection_Header_from_thumb(s32 copyOwnerName) {
    u16 ownerCharCount;
    u16 *ownerText;

    Mem_CpuFill8(g_SaveDataHolder->mFirstBlock, 0, sizeof(BackupFirstBlock));
    if (copyOwnerName != 0) {
        ownerCharCount = g_GlobalP->mOwnerCharCount;
        ownerText = g_GlobalP->mOwnerText;
        g_SaveDataHolder->mFirstBlock->mHasPlayerName = 1;
        Mem_CpuFill8(g_SaveDataHolder->mFirstBlock->mPlayerName, 0, sizeof(g_SaveDataHolder->mFirstBlock->mPlayerName));
        Mem_CpuCopy8(ownerText, g_SaveDataHolder->mFirstBlock->mPlayerName, ((u32) ownerCharCount << 17) >> 16);
    }
    g_SaveDataHolder->mFirstBlock->mSoundMode = SOUND_MODE_SURROUND;
    g_SaveDataHolder->mFirstBlock->mEmblemOff = 0;
    g_SaveDataHolder->mFirstBlock->mLocateFriendOff = 0;
    g_SaveDataHolder->mFirstBlock->mElo = BACKUP_ELO_INITIAL;
    j_GetCurrentUnlockedSecretFlags();
    j_PlayerProfileInfo_Create_from_thumb(&g_SaveDataHolder->mFirstBlock->mUserData, 0x414d434a);
}

#pragma thumb off
