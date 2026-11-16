#include "Main/Net/own_index.h"
#include "Main/System/backup_net_camera_work.h"

void ResetOwnIndex(void) {
    g_GlobalZE->mOwnIndex = CONNECTION_OWN_INDEX_NONE;
}
