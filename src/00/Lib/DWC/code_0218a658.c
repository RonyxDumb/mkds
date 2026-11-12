#include "00/Lib/DWC/code_0218a658.h"
#include "00/unk_021b2000.h"
#include "string.h"
#include "code_02134398.h"

u8 gNintendoUsbApSsid[9] = {0x4e, 0x57, 0x43, 0x55, 0x53, 0x42, 0x41, 0x50, 0};

BOOL DWCi_AC_CheckNintendoUsbAP(const u8 *ssid) {
    int compare;
    compare = memcmp(ssid, gNintendoUsbApSsid, 8);
    if (compare == 0) {
        return 1;
    }
    return 0;
}
