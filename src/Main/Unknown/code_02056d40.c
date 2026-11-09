#include "Main/Unknown/code_02056d40.h"
#include "Main/Unknown/code_02057ca4.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma thumb on
void WriteBackupFirstBlockWrapper(void) {
    WriteBackupFirstBlock(data_0217aa08->mFirstBlock);
}
#pragma thumb off
