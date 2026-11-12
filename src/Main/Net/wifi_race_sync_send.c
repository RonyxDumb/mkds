#include "Main/Net/wifi_race_sync_send.h"
#include "00/Menu/wi_fi_vs_matching.h"
#include "Main/Net/wifi_session.h"

u32 FinishWiFiRaceSyncSend(void) {
    u32 value0;
    u32 flags;
    u32 testedValue;
    u32 zero;
    value0 = gWiFiSession->mRaceSyncEnabled;
    testedValue = value0;
    zero = 0u;
    if (testedValue == zero) {
        return value0;
    }
    value0 = (u32) gWiFiRaceSync;
    value0 = (value0) + (0x700u);
    flags = *OFFSET_PTR(u16, value0, 92);
    flags = (flags) & ~(4u);
    *OFFSET_PTR(u16, value0, 92) = flags;
    return value0;
}
