#include "Main/Net/wifi_connection_lost.h"
#include "00/code_021832d8.h"

BOOL IsWiFiConnectionLost(void) {
    u32 result = 0u;
    if (gWiFiSession->mConnectionLost != 1u) {
        return result;
    }
    if (gWiFiSession->mStep == 0xcu) {
        result = 1u;
    }
    return result;
}
