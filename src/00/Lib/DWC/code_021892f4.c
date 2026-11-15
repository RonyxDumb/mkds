#include "00/Lib/DWC/code_021892f4.h"
#include "00/Lib/DWC/code_02187484.h"
#include "00/Lib/DWC/code_02188008.h"
#include "00/Lib/DWC/code_02188ee0.h"

u32 DWCi_AC_CloseNetwork(u8 *phase) {
    u8 phaseValue;
    int result;
    phaseValue = *phase;
    if (phaseValue <= 10) {
        result = DisConnectAP();
        if (result == 1) {
            *phase = 0;
            return 1;
        }
        if (result == -1) {
            *phase = 0x12;
            return 1;
        }
    } else if (phaseValue == 0xe) {
        DWC_Netcheck_Abort();
        DWC_Netcheck_Destroy();
        *phase = 0xc;
    } else if ((phaseValue < 0x12) && (result = CloseAutoConnectSocket(), result == 1)) {
        *phase = 10;
    }
    return 0;
}
