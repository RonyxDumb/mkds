#include "00/Lib/NitroWiFi/code_021a4b98.h"
#include "00/Lib/DWC/code_02188de4.h"
#include "00/Lib/DWC/code_02188ec0.h"
#include "00/Lib/DWC/code_0218a64c.h"
#include "code_0214d018.h"
#include "00/Lib/DWC/code_0218a67c.h"

u32 FillApWepKey(struct ACWORK *work, u32 type, WCMWepDesc *wepKey) {
    DWCMemPage *userInfo;

    userInfo = work->mUserInfo;
    switch (type) {
        case AUTO_CONNECT_AP_TYPE_USER_FIRST_SSID + 2:
            userInfo++;
        case AUTO_CONNECT_AP_TYPE_USER_FIRST_SSID + 1:
            userInfo++;
        case AUTO_CONNECT_AP_TYPE_USER_FIRST_SSID:
            wepKey->mMode = userInfo->mWepMode;
            MI_CpuCopy8(userInfo->mWepKeys, wepKey->mKey, sizeof(wepKey->mKey));
            break;
        case AUTO_CONNECT_AP_TYPE_USER_SECOND_SSID + 2:
            userInfo++;
        case AUTO_CONNECT_AP_TYPE_USER_SECOND_SSID + 1:
            userInfo++;
        case AUTO_CONNECT_AP_TYPE_USER_SECOND_SSID:
            wepKey->mMode = WEP_KEY_MODE_SHORT;
            MI_CpuCopy8(userInfo->mWep2, wepKey->mKey, sizeof(userInfo->mWep2));
            wepKey->mKey[0x14] = 0;
            break;
        case AUTO_CONNECT_AP_TYPE_NWCUSBAP_SSID:
            wepKey->mMode = WEP_KEY_MODE_LONG;
            DWCi_AC_GetNintendoUSBWepKey(work->mBssDesc[work->mConnectNo].mSsid, wepKey->mKey);
            break;
        case AUTO_CONNECT_AP_TYPE_NDWCSHAP_SSID_PREFIX:
            wepKey->mMode = WEP_KEY_MODE_LONG;
            DWCi_AC_GetNintendoShopWepKey(work->mBssDesc[work->mConnectNo].mSsid, wepKey->mKey);
            break;
        case AUTO_CONNECT_AP_TYPE_FREESPOT_SSID:
        case AUTO_CONNECT_AP_TYPE_WAYPORT2_SSID:
            break;
    }
    if (wepKey->mMode != 0) {
        return 1;
    }
    return 0;
}
