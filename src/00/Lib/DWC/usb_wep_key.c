#include "00/Lib/DWC/usb_wep_key.h"
#include "00/Lib/DWC/ssid_wep_decode.h"

void DWCi_AC_GetNintendoUSBWepKey(const u8 *input, u8 *output) {
    MakeUsbWepKey(input + 0xc, output);
}
