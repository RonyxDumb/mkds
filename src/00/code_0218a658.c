#include "00/code_0218a658.h"
#include "00/unk_021b2000.h"
#include "string.h"
#include "code_02134398.h"

BOOL DWCi_AC_CheckNintendoUsbAP(const u8 *ssid) {
    int compare;
    compare = memcmp(ssid, gNintendoUsbApSsid, 8);
    if (compare == 0) {
        return 1;
    }
    return 0;
}
