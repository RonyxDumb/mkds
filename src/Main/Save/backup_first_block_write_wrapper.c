#include "Main/Save/backup_first_block_write_wrapper.h"
#include "Main/Save/backup_first_block.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma thumb on
void WriteBackupFirstBlockWrapper(void) {
    WriteBackupFirstBlock(gBackupBuffers->mFirstBlock);
}
#pragma thumb off
