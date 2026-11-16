#include "Main/Save/nvram_new_wifi_info.h"
#include "wifi_settings_nvram_backup.h"
#include "wifi_id_info.h"

#pragma thumb on

u32 StructDC_SomeFn_4_from_thumb(u32 work) {
    int result;
    DWCWiFiInfo wifiInfo;
    result = StructDW_SomeFn_from_thumb(&wifiInfo);
    if (result == 0) {
        return 0;
    }
    result = StructDW_SomeFn_0_from_thumb(&wifiInfo, (u8 *) work);
    if (result != 0) {
        return 1;
    }
    return 0;
}

#pragma thumb off
