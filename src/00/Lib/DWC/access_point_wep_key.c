#include "00/Lib/NitroWiFi/wireless_connection_manager.h"
#include "00/Lib/DWC/access_point_wep_key.h"
#include "00/Lib/DWC/access_point_power_mode.h"
#include "00/Lib/DWC/usb_wep_key.h"
#include "cpu_copy_fill.h"
#include "00/Lib/DWC/shop_access_point_key.h"

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
            Mem_CpuCopy8(userInfo->mWepKeys, wepKey->mKey, sizeof(wepKey->mKey));
            break;
        case AUTO_CONNECT_AP_TYPE_USER_SECOND_SSID + 2:
            userInfo++;
        case AUTO_CONNECT_AP_TYPE_USER_SECOND_SSID + 1:
            userInfo++;
        case AUTO_CONNECT_AP_TYPE_USER_SECOND_SSID:
            wepKey->mMode = WEP_KEY_MODE_SHORT;
            Mem_CpuCopy8(userInfo->mWep2Keys, wepKey->mKey, sizeof(userInfo->mWep2Keys));
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
