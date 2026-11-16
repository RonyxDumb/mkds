#include "Main/Save/GhostBits.h"
#include "Main/Unknown/code_02057498.h"
#include "Main/Unknown/code_02090000.h"
#include "Main/Unknown/code_02090354.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/code_02152000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0214d018.h"
#include "code_02152500.h"

#pragma thumb on

void savd_setBit(s32 bitIndex, u8 *bytes, s32 c) {
    u8 *bitArrayByte;

    bitArrayByte = savd_getByteForBit(bitIndex, bytes);
    *bitArrayByte |= 1 << (u8) (bitIndex % 8);
}

BOOL savd_isBitSet(s32 bitIndex, u8 *bytes, s32 c) {
    u8 *bitArrayByte;

    bitArrayByte = savd_getByteForBit(bitIndex, bytes);
    return (*bitArrayByte & (1 << (u8) (bitIndex % 8))) != 0 ? 1 : 0;
}

void savd_resetBit(s32 bitIndex, u8 *bytes, s32 c) {
    u8 *bitArrayByte;

    bitArrayByte = savd_getByteForBit(bitIndex, bytes);
    *bitArrayByte &= ~(1 << (u8) (bitIndex % 8));
}

BOOL savd_isPersonalGhostAvailable(u8 bitIndex) {
    return savd_isBitSet(bitIndex, gSaveData->mFirstBlock->mCourseGhostBits, 4);
}

void savd_setPersonalGhostUnavailable(s32 bitIndex) {
    savd_resetBit(bitIndex, gSaveData->mFirstBlock->mCourseGhostBits, 4);
}

BOOL savd_isDownloadGhostAvailable(u32 bitIndex) {
    return savd_isBitSet(bitIndex, gSaveData->mFirstBlock->mSlotGhostBits, 2);
}

void savd_initNksy(s32 copyOwnerName) {
    u16 ownerCharCount;
    u8 *ownerText;

    MI_CpuFill8(gSaveData->mFirstBlock, 0, 0x100);
    if (copyOwnerName != 0) {
        ownerCharCount = gSystemData->mOwnerCharCount;
        ownerText = gSystemData->mOwnerText;
        gSaveData->mFirstBlock->field31_0 = 1;
        MI_CpuFill8(gSaveData->mFirstBlock->mPlayerName, 0, 0x14);
        MI_CpuCopy8(ownerText, gSaveData->mFirstBlock->mPlayerName, ((u32) ownerCharCount << 17) >> 16);
    }
    gSaveData->mFirstBlock->mSoundMode = SOUND_MODE_SURROUND;
    gSaveData->mFirstBlock->field31_3 = 0;
    gSaveData->mFirstBlock->mLocateFriendOff = 0;
    gSaveData->mFirstBlock->mElo = 0x1388;
    unlock_tryUnlock2();
    DWC_CreateUserData((DWCAccUserData *) gSaveData->mFirstBlock->mUserData, 0x414d434a);
}

#pragma thumb off
