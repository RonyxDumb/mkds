#include "Main/Save/nvram_new_wifi_info.h"
#include "code_021510a4.h"
#include "code_02151868.h"
#include "code_02151fc4.h"

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
