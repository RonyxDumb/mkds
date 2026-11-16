#include "Main/Save/backup_first_block_write_wrapper.h"
#include "Main/Save/backup_first_block.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Save/ghost_record_file.h"

#pragma thumb on
void WriteSaveDataSectionHeaderToSaveData_from_thumb(void) {
    WriteSaveDataSection_Header_from_thumb(g_SaveDataHolder->mFirstBlock);
}
#pragma thumb off
