#include "00/Lib/NitroWiFi/code_021a6d1c.h"
#include "00/Lib/NitroWiFi/cpsif.h"

u32 SOCL_LinkIsOn(void) {
    u8 *mac;
    mac = WCM_GetApMacAddress();
    if (mac != NULL) {
        return 1;
    }
    return 0;
}

BOOL WCM_CompareBssID(const u8 *bssidLeft, const u8 *bssidRight) {
    int byteIndex;

    byteIndex = 0;
    do {
        if (bssidLeft[byteIndex] != bssidRight[byteIndex]) {
            return 0;
        }
        byteIndex++;
    } while (byteIndex < 6);
    return 1;
}
