#include "00/Lib/DWC/connect_test_retry.h"
#include "00/Lib/NitroWiFi/socket_api_prototypes.h"

s32 ConnectTestRetry(void) {
    s32 result = SOC_Cleanup();
    if (result == 0 || result == -39) {
        return 9;
    }
    return 11;
}
