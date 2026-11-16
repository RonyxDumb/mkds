#include "Main/Save/backup_first_block_records.h"
#include "Main/Save/buddy_record_clear.h"
#include "Main/Save/ghost_clear.h"
#include "Main/Save/emblem_record.h"
#include "Main/Save/backup_bit_array.h"
#include "Main/Save/backup_busy.h"
#include "Main/Save/backup_buddy_record_block.h"
#include "Main/Save/backup.h"
#include "Main/Save/backup_first_block.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/record_time_attack_requests.h"
#include "Main/Save/ghost_record_file.h"

#pragma thumb on

void ClearAllSaveDataSections_from_thumb(u32 copyOwnerName) {
    ClearSaveDataSection_Emblem_from_thumb();
    ClearSaveDataSection_GrandPrix_from_thumb();
    ClearSaveDataSection_TimeTrials_from_thumb();
    ClearSaveDataSection_MissionRun_from_thumb();
    ClearSaveDataGhosts_from_thumb();
    ClearSaveDataSection_FriendList_from_thumb();
    ClearSaveDataSection_Header_from_thumb(copyOwnerName);
}

void Task_WriteNonGhostSaveData_from_thumb(void) {
    WriteSaveDataSection_Emblem_from_thumb(g_SaveDataHolder->mEmblemRecord);
    if (g_SaveDataIoManager->mBackupEnabled != 0) {
        j_WaitForPendingCardOperation();
    }
    WriteSaveDataSection_GrandPrix_from_thumb(g_SaveDataHolder->mGrandPrixRecordBlock);
    if (g_SaveDataIoManager->mBackupEnabled != 0) {
        j_WaitForPendingCardOperation();
    }
    WriteSaveDataSection_TimeTrials_from_thumb(g_SaveDataHolder->mCourseTimeRecordBlock);
    if (g_SaveDataIoManager->mBackupEnabled != 0) {
        j_WaitForPendingCardOperation();
    }
    WriteSaveDataSection_MissionRun_from_thumb(g_SaveDataHolder->mMissionRecordBlock);
    if (g_SaveDataIoManager->mBackupEnabled != 0) {
        j_WaitForPendingCardOperation();
    }
    WriteSaveDataSection_FriendList_from_thumb(g_SaveDataHolder->mBuddyRecordBlock);
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
