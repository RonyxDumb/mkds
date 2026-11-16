#include "00/Lib/DWC/connect_test_start.h"
#include "00/Lib/DWC/access_point_state.h"
#include "00/Lib/DWC/socket_config.h"
#include "00/Lib/CPS/stack_globals.h"
#include "00/Lib/NitroWiFi/socket_api_prototypes.h"
#include "00/Lib/NitroWiFi/socket_library_startup.h"

u32 ConnectTestStart(ACWORK *work) {
    ACHOLD *hold;
    SOCConfig *config;
    int result;
    hold = DWCi_AC_GetMemPtr(AC_MEM_HOLD);
    config = DWCi_AC_GetMemPtr(AC_MEM_SOC_CONFIG);
    MakeSOCConfig(hold, work, config);
    SOCLiYieldWait = 4;
    result = SOC_Startup(config);
    if (result != 0) {
        DWCi_AC_SetError(2);
        return AC_PHASE_ERROR;
    }
    return AC_PHASE_TEST_GET_IP;
}
