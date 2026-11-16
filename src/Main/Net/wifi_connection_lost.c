#include "Main/Net/wifi_connection_lost.h"
#include "00/Menu/wi_fi_vs_matching.h"
#include "Main/Net/wifi_session.h"

BOOL IsWiFiConnectionLost(void) {
    u32 result = 0u;
    if (g_GlobalB->mConnectionLost != TRUE) {
        return result;
    }
    if (g_GlobalB->mStep == WIFI_SESSION_STEP_ENDED) {
        result = 1u;
    }
    return result;
}
