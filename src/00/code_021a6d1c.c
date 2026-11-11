#include "00/code_021a6d1c.h"
#include "00/code_021a6934.h"

u32 SOCL_LinkIsOn(void) {
    u8 *mac;
    mac = WCM_GetApMacAddress();
    if (mac != NULL) {
        return 1;
    }
    return 0;
}

BOOL WCM_CompareBssID(const u8 *bssidLeft, const u8 *bssidRight) {
    int i;

    i = 0;
    do {
        if (bssidLeft[i] != bssidRight[i]) {
            return 0;
        }
        i++;
    } while (i < 6);
    return 1;
}
