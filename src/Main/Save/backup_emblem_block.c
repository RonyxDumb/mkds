#include "Main/Save/backup_emblem_block.h"
#include "Main/Save/backup_write_copies.h"
#include "Main/Save/backup_read_copies.h"
#include "Main/Save/backup_read_copy.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/record_time_attack_requests.h"
#include "cpu_copy_fill.h"

#pragma thumb on

void WriteSaveChunk_NKFE_from_thumb(EmblemBlockData *blockData, s32 blockIndex) {
    s32 blockOffset = blockIndex * 0xb00;
    u32 *buffer;
    buffer = g_SaveDataIoManager->mBuffer;
    if (g_SaveDataIoManager->mBackupEnabled != 0) {
        Mem_CpuCopy8(blockData, buffer, sizeof(EmblemBlockData));
        buffer[0] = 0x45464b4e;
        SV_MaybeCompressWriteTwoOffsetsFlagC_from_thumb(blockOffset + 0x2b00, blockOffset + 0x33a00, buffer, 0xb00, NULL, 0);
    }
}

void ReadSaveChunk_NKFE_from_thumb(EmblemBlockData *blockData, s32 blockIndex) {
    s32 blockOffset = blockIndex * 0xb00;
    if (g_SaveDataIoManager->mBackupEnabled != 0) {
        g_SaveDataIoManager->mReadTarget = blockData;
        g_SaveDataIoManager->mUnk_5c = -1;
        ReadSaveChunkImpl_from_thumb(blockOffset + 0x2b00, blockOffset + 0x33a00, g_SaveDataIoManager->mBuffer, 0xb00,
                                 CopyToSXSomePtr_from_thumb, 0x45464b4e, 0);
    }
}

#pragma thumb off
