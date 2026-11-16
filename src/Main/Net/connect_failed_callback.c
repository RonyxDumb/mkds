#include "Main/Net/connect_failed_callback.h"
#include "Main/Net/disconnect.h"
#include "Main/Net/connection.h"
#include "Main/System/backup_net_camera_work.h"

#pragma thumb on

void ConnectFailedCallback(void) {
    if ((0x00000708u) < g_GlobalZE->mStepWaitFrames) {
        SetRequestErrorCode(CONNECTION_ERROR_CONNECT_FAILED);
        return;
    }
    StopConnection();
}

#pragma thumb off
