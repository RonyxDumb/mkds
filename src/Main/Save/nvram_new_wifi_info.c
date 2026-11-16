#include "Main/Save/nvram_new_wifi_info.h"
#include "wifi_settings_nvram_backup.h"
#include "wifi_id_info.h"

#pragma thumb on

u32 WriteNewWiFiInfoToNvram(u32 work) {
    int result;
    DWCWiFiInfo wifiInfo;
    result = DWCi_AUTH_GetNewWiFiInfo(&wifiInfo);
    if (result == 0) {
        return 0;
    }
    result = DWCi_BM_SetWiFiInfo(&wifiInfo, (u8 *) work);
    if (result != 0) {
        return 1;
    }
    return 0;
}

#pragma thumb off
