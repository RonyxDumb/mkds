#include "Main/Save/packed_wifi_info.h"
#include "overlay_section_symbols.h"

#pragma thumb on

u8 *GetPackedWiFiInfo(void) {
    return gPackedWiFiInfo;
}

#pragma thumb off
