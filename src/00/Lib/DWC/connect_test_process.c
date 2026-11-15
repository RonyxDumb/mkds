#include "00/Lib/DWC/connect_test_process.h"
#include "00/Lib/DWC/access_point_power_mode.h"
#include "00/Lib/DWC/network_check_status.h"
#include "00/Lib/DWC/access_point_state.h"
#include "00/Lib/wifi_library_globals.h"
#include "00/Lib/DWC/no_internet_error.h"

u32 ConnectTestProcess(ACWORK *work) {
    ACHOLD *hold;
    u32 error;

    hold = DWCi_AC_GetMemPtr(AC_MEM_HOLD);
    error = DWC_Netcheck_GetError();
    if (error != 0) {
        if (hold->mEndType == DWCi_ConvConnectAPType(work->mConnectApType)) {
            hold->mErrorTest = DWC_Netcheck_GetReturnCode();
        }
        DWC_Netcheck_Destroy();
        if (error != 0xb) {
            work->mFindList[work->mConnectNo].mState = 1;
            return 0xb;
        }
        return 0xf;
    }
    return 0xe;
}
