#include "00/Lib/NitroWiFi/wireless_connection_control.h"
#include "00/Lib/DWC/connect_test_run.h"
#include "00/Lib/DWC/access_point_power_mode.h"
#include "00/Lib/DWC/network_check_status.h"
#include "00/Lib/wifi_library_globals.h"
#include "00/Lib/DWC/access_point_state.h"
#include "00/Lib/DWC/access_point_connect.h"
#include "00/Lib/DWC/connect_test_retry.h"
#include "00/Lib/DWC/connect_test_end.h"
#include "00/Lib/DWC/connect_test_process.h"
#include "00/Lib/DWC/connect_test_create.h"
#include "00/Lib/DWC/ip_address_get.h"
#include "00/Lib/DWC/connect_test_start.h"

u32 DWCi_AC_ConnectTest(void) {
    u32 phase;
    ACWORK *work;

    phase = DWCi_AC_GetPhase();
    work = DWCi_AC_GetMemPtr(AC_MEM_WORK);
    if (WCM_GetPhase() == WIFI_LINK_PHASE_CONNECTED) {
        switch (phase) {
            case AC_PHASE_TEST_START:
                phase = ConnectTestStart(work);
                break;
            case AC_PHASE_TEST_GET_IP:
                phase = GetIPAddress(work);
                break;
            case AC_PHASE_TEST_CREATE:
                phase = ConnectTestCreate();
                break;
            case AC_PHASE_TEST_PROCESS:
                phase = ConnectTestProcess(work);
                break;
            case AC_PHASE_TEST_END:
                phase = ConnectTestEnd(work);
                break;
            case AC_PHASE_TEST_RETRY:
                phase = ConnectTestRetry();
                break;
        }
    } else {
        switch (phase) {
            case AC_PHASE_TEST_END:
                phase = ConnectTestEnd(work);
                break;
            case AC_PHASE_TEST_RETRY:
                phase = ConnectTestRetry();
                break;
            case AC_PHASE_TEST_PROCESS:
                DWC_Netcheck_Abort();
                DWC_Netcheck_Destroy();
            default:
                work->mFindList[work->mConnectNo].mState = AUTO_CONNECT_FIND_TEST_ABORTED;
                phase = AC_PHASE_TEST_RETRY;
        }
    }
    return phase;
}
