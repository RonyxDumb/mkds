#include "Main/Net/connect_failed_callback.h"
#include "Main/Net/disconnect.h"
#include "Main/Net/connection.h"
#include "Main/MapObjects/data_0217a000.h"

#pragma thumb on

void ConnectFailedCallback(void) {
    if ((0x00000708u) < gConnectionWork->mStepWaitFrames) {
        SetRequestErrorCode(CONNECTION_ERROR_CONNECT_FAILED);
        return;
    }
    StopConnection();
}

#pragma thumb off
