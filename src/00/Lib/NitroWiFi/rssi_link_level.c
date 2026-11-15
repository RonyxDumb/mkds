#include "00/Lib/NitroWiFi/wireless_connection_control.h"
#include "00/Lib/NitroWiFi/rssi_link_level.h"
#include "00/Lib/wifi_library_work_objects.h"
#include "00/Lib/NitroWiFi/wireless_connection_config.h"
#include "signed_int_divide.h"
#include "reset_interrupt_enable.h"
#include "00/Lib/NitroWiFi/dcf_send_receive.h"
#include "00/Lib/NitroWiFi/access_point_list.h"
#include "mutex_init_decl.h"
#include "wireless_power_mp.h"

u8 gWcmRssiIndex;
u8 gWcmRssi[16];

u32 WCM_GetLinkLevel(void) {
    u32 enabled;
    WCMWork *work;
    u32 level;

    enabled = OS_DisableInterrupts();
    work = WCMi_GetSystemWork();
    level = 0;
    if (work != NULL && work->mPhase == WIFI_LINK_PHASE_CONNECTED) {
        level = WcmGetLinkLevel();
    }
    OS_RestoreInterrupts(enabled);
    return level;
}

u8 WCMi_GetRssiAverage(void) {
    s32 sum = 0;
    u32 count = gWcmRssiIndex;
    s32 rssiIndex;

    if (count > 16) {
        for (rssiIndex = 0; rssiIndex < 16; rssiIndex++) {
            sum += gWcmRssi[rssiIndex];
        }
        sum = sum / 16;
    } else if (count != 0) {
        for (rssiIndex = 0; rssiIndex < (s32) count; rssiIndex++) {
            sum += gWcmRssi[rssiIndex];
        }
        sum = sum / (s32) count;
    }
    return sum;
}

s32 WcmGetLinkLevel(void) {
    u32 averageRssi = WCMi_GetRssiAverage();
    s32 level = 0;
    if (averageRssi >= 28) {
        level = 3;
    } else if (averageRssi >= 22) {
        level = 2;
    } else if (averageRssi >= 16) {
        level = 1;
    }
    return level;
}

void WCMi_ShelterRssi(u8 rssi) {
    u8 raw;
    u8 index;

    if (rssi & 2) {
        raw = (rssi >> 2) & 0xff;
    } else {
        raw = (rssi >> 2) + 25;
    }
    index = gWcmRssiIndex;
    gWcmRssi[index % 16] = raw;
    if (index >= 16) {
        gWcmRssiIndex = (index + 1) % 16 + 16;
    } else {
        gWcmRssiIndex++;
    }
}
