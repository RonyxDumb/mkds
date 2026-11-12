#include "Main/Net/wifi_connection_lost.h"
#include "00/Menu/wi_fi_vs_matching.h"

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
