#include "Main/Net/non_multiboot_own_index.h"
#include "Main/System/backup_net_camera_work.h"

void NonMultiBootResetOwnIndex(void) {
    g_GlobalZE->mOwnIndex = CONNECTION_OWN_INDEX_NONE;
}
