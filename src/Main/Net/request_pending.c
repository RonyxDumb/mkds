#include "Main/Net/request_pending.h"
#include "Main/System/backup_net_camera_work.h"

void ClearRequestPending(WirelessMessage *event) {
    g_GlobalZE->mRequestPending = 0;
}
