#include "Main/Save/backup_bit_array.h"
#include "Main/Save/bit_array_byte.h"
#include "Main/Race/gp_records_killer.h"
#include "Main/Menu/data_02175000.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "Main/MapObjects/data_0217a000.h"
#include "code_0214d018.h"
#include "dwc_account.h"
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

    MI_CpuFill8(gBackupBuffers->mFirstBlock, 0, 0x100);
    if (copyOwnerName != 0) {
        ownerCharCount = gStartupWork->mOwnerCharCount;
        ownerText = gStartupWork->mOwnerText;
        gBackupBuffers->mFirstBlock->mHasPlayerName = 1;
        MI_CpuFill8(gBackupBuffers->mFirstBlock->mPlayerName, 0, 0x14);
        MI_CpuCopy8(ownerText, gBackupBuffers->mFirstBlock->mPlayerName, ((u32) ownerCharCount << 17) >> 16);
    }
    gBackupBuffers->mFirstBlock->mSoundMode = SOUND_MODE_SURROUND;
    gBackupBuffers->mFirstBlock->mEmblemOff = 0;
    gBackupBuffers->mFirstBlock->mLocateFriendOff = 0;
    gBackupBuffers->mFirstBlock->mElo = 0x1388;
    SetSecretMessageFlagsWrapper();
    DWC_CreateUserData(&gBackupBuffers->mFirstBlock->mUserData, 0x414d434a);
}

#pragma thumb off
