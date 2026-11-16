#include "Main/Save/backup_buddy_record_block.h"
#include "Main/Save/backup_write_copies.h"
#include "Main/Save/backup_read_copies.h"
#include "Main/Save/backup_read_copy.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/record_time_attack_requests.h"
#include "cpu_copy_fill.h"

#pragma thumb on

void WriteSaveDataSection_FriendList_from_thumb(BuddyRecordBlock *block) {
    u32 *buffer;
    buffer = g_SaveDataIoManager->mBuffer;
    if (g_SaveDataIoManager->mBackupEnabled != 0) {
        Mem_CpuCopy8(block, buffer, sizeof(BuddyRecordBlock));
        *buffer = 0x4c464b4e;
        SV_MaybeCompressWriteTwoOffsetsFlagC_from_thumb(0x1f00, 0x32e00, buffer, 0xc00, NULL, 0);
    }
}

void ReadSaveDataSection_FriendList_from_thumb(void *block) {
    if (g_SaveDataIoManager->mBackupEnabled != 0) {
        g_SaveDataIoManager->mReadTarget = block;
        g_SaveDataIoManager->mUnk_5c = -1;
        ReadSaveChunkImpl_from_thumb(0x1f00, 0x32e00, g_SaveDataIoManager->mBuffer, 0xc00, CopyToSXSomePtr_from_thumb, 0x4c464b4e, 0);
    }
}

#pragma thumb off
