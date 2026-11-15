#include "00/Lib/DWC/ip_address_get.h"
#include "00/Lib/DWC/access_point_search.h"
#include "00/Lib/NitroWiFi/dns_resolver_setting.h"
#include "00/Lib/NitroWiFi/socket_api_prototypes.h"
#include "os_tick.h"

u32 GetIPAddress(ACWORK *work) {
    if (SOC_GetHostID() != 0) {
        CheckSetDNS(work);
        if (work->mSkipNetCheck == 1) {
            return 0xf;
        }
        return 0xd;
    }
    if ((OS_GetTick() - work->mTimeOut) * 64 / 0x1ff6210 >= 10) {
        work->mFindList[work->mConnectNo].mState = 1;
        return 0xb;
    }
    return 0xc;
}
