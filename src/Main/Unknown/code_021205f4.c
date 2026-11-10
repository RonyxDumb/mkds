#include "Main/Unknown/code_021205f4.h"
#include "00/code_021832d8.h"

u32 GetWiFiSessionErrorCodeNegated(void) {
    return ((0x0u) - ((gWiFiSession->mErrorCode)));
}
