#include "Main/Save/packed_wifi_info.h"
#include "Main/Unknown/unk_02180000.h"

#pragma thumb on

u8 *GetPackedWiFiInfo(void) {
    return gPackedWiFiInfo;
}

#pragma thumb off
