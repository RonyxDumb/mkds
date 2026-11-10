#include "Main/Unknown/code_02122ae4.h"
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
