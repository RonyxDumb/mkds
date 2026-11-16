#include "00/Lib/DWC/ip_address_get.h"
#include "00/Lib/DWC/access_point_state.h"
#include "00/Lib/DWC/access_point_search.h"
#include "00/Lib/NitroWiFi/dns_resolver_setting.h"
#include "00/Lib/NitroWiFi/socket_api_prototypes.h"
#include "tick_counter.h"

u32 GetIPAddress(ACWORK *work) {
    if (SOC_GetHostID() != 0) {
        CheckSetDNS(work);
        if (work->mSkipNetCheck == 1) {
            return AC_PHASE_TEST_END;
        }
        return AC_PHASE_TEST_CREATE;
    }
    if ((OS_GetTick() - work->mTimeOut) * 64 / 0x1ff6210 >= 10) {
        work->mFindList[work->mConnectNo].mState = 1;
        return AC_PHASE_TEST_RETRY;
    }
    return AC_PHASE_TEST_GET_IP;
}
