#include "00/Lib/DWC/code_0218a64c.h"
#include "00/Lib/DWC/code_0218a350.h"

void DWCi_AC_GetNintendoUSBWepKey(const u8 *input, u8 *output) {
    MakeUsbWepKey(input + 0xc, output);
}
