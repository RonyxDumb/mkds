#include "00/Lib/DWC/socket_config.h"
#include "00/Lib/DWC/access_point_state.h"
#include "00/Lib/DWC/access_point_search.h"
#include "00/Lib/DWC/address_convert.h"
#include "00/Lib/NitroWiFi/wcm_search_defaults.h"
#include "cpu_copy_fill.h"

const SOCConfig gAcSocConfig = {{0, 0, 0, 1},
                                NULL,
                                NULL,
                                1,
                                0,
                                0,
                                0,
                                0,
                                0,
                                0x1000,
                                0x1000,
                                0,
                                0,
                                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                "NINTENDO-DS",
                                4,
                                0,
                                0};

void MakeSOCConfig(const ACHOLD *hold, ACWORK *work, SOCConfig *config) {
    DWCMemPage *info;

    MI_CpuCopy8(&gAcSocConfig, config, sizeof(gAcSocConfig));
    config->mAlloc = hold->mAlloc;
    config->mFree = hold->mFree;
    if (work->mConnectApType < AUTO_CONNECT_AP_TYPE_NWCUSBAP_SSID) {
        info = &work->mUserInfo[DWCi_ConvConnectAPType(work->mConnectApType)];
        if (info->mIp[0] != 0) {
            config->mFlag = 0;
            config->mAddr = ConvAddress(info->mIp);
            config->mNetmask = ConvNetMask(info->mNetmaskCidr);
            config->mRouter = ConvAddress(info->mGateway);
            config->mDns1 = ConvAddress(info->mDns1);
            config->mDns2 = ConvAddress(info->mDns2);
        } else {
            config->mFlag = 1;
            config->mAddr = 0;
            config->mNetmask = 0;
            config->mRouter = 0;
            config->mDns1 = 0;
            config->mDns2 = 0;
        }
    }
}
