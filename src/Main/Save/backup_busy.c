#include "Main/Save/backup_busy.h"
#include "Main/Save/backup_first_block.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/record_time_attack_requests.h"
#include "Main/Save/ghost_record_file.h"

#pragma thumb on

void EnableMKDSSVSomeFlag_from_thumb(void) {
    g_SaveDataHolder->mBusy = 1;
}

void ResetSaveDataHolderTaskPendingFlag_from_thumb(void) {
    g_SaveDataHolder->mBusy = 0;
}

void Task_WriteSaveDataHeader_from_thumb(void) {
    if (g_SaveDataIoManager->mBackupEnabled != 0) {
        j_WaitForPendingCardOperation();
    }
    WriteSaveDataSection_Header_from_thumb(g_SaveDataHolder->mFirstBlock);
    if (g_SaveDataIoManager->mBackupEnabled != 0) {
        j_WaitForPendingCardOperation();
    }
    ResetSaveDataHolderTaskPendingFlag_from_thumb();
}

#pragma thumb off
