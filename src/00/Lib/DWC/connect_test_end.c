#include "00/Lib/DWC/connect_test_end.h"
#include "00/Lib/DWC/access_point_power_mode.h"
#include "00/Lib/DWC/access_point_state.h"

s32 ConnectTestEnd(const ACWORK *work) {
    SetAcHoldApType(work->mConnectApType);
    return AC_PHASE_COMPLETE;
}
