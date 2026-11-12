#include "00/Lib/NitroWiFi/util.h"
#include "00/unk_021b5000.h"
#include "00/code_021a574c.h"
#include "code_02133048.h"
#include "code_0200fc8c.h"
#include "00/Lib/NitroWiFi/cpsif.h"
#include "00/code_021a68dc.h"
#include "00/Lib/NitroWiFi/code_021a669c.h"
#include "code_0200edc0.h"
#include "code_02142eac.h"

u8 gWcmRssiIndex;
u8 gWcmRssi[16];

u32 WCM_GetLinkLevel(void) {
    u32 enabled;
    WCMWork *work;
    u32 level;

    enabled = OS_DisableInterrupts();
    work = WCMi_GetSystemWork();
    level = 0;
    if (work != NULL && work->mPhase == 9) {
        level = WcmGetLinkLevel();
    }
    OS_RestoreInterrupts(enabled);
    return level;
}

u8 WCMi_GetRssiAverage(void) {
    s32 sum = 0;
    u32 count = gWcmRssiIndex;
    s32 i;

    if (count > 16) {
        for (i = 0; i < 16; i++) {
            sum += gWcmRssi[i];
        }
        sum = sum / 16;
    } else if (count != 0) {
        for (i = 0; i < (s32) count; i++) {
            sum += gWcmRssi[i];
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
