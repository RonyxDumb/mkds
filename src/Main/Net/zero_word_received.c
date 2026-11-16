#include "Main/Net/zero_word_received.h"
#include "Main/System/backup_net_camera_work.h"

#pragma thumb on

void SetZeroWordReceived(u32 *payload, int length) {
    if ((length == 4) && (*payload == 0)) {
        g_GlobalZE->mZeroWordReceived = 1;
    }
}

#pragma thumb off
