#include "00/Lib/DWC/access_point_close.h"
#include "00/Lib/DWC/network_check_status.h"
#include "00/Lib/DWC/network_check_control.h"
#include "00/Lib/DWC/access_point_connect.h"

u32 DWCi_AC_CloseNetwork(u8 *phase) {
    u8 phaseValue;
    int result;
    phaseValue = *phase;
    if (phaseValue <= AC_PHASE_TEST_START) {
        result = DisConnectAP();
        if (result == 1) {
            *phase = 0;
            return 1;
        }
        if (result == -1) {
            *phase = AC_PHASE_END;
            return 1;
        }
    } else if (phaseValue == AC_PHASE_TEST_PROCESS) {
        DWC_Netcheck_Abort();
        DWC_Netcheck_Destroy();
        *phase = AC_PHASE_TEST_GET_IP;
    } else if ((phaseValue < AC_PHASE_END) && (result = CleanupSocketApi(), result == 1)) {
        *phase = AC_PHASE_TEST_START;
    }
    return 0;
}
