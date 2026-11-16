#include "Main/Net/wifi_race_sync_send.h"
#include "00/Menu/wi_fi_vs_matching.h"
#include "Main/Net/wifi_session.h"
#include "Main/Save/ghost_record_file.h"

u32 FinishWiFiRaceSyncSend(void) {
    u32 result;
    u32 flags;
    u32 testedValue;
    u32 zero;
    result = gWiFiSession->mRaceSyncEnabled;
    testedValue = result;
    zero = 0u;
    if (testedValue == zero) {
        return result;
    }
    result = (u32) gWiFiRaceSync;
    result = (result) + (0x700u);
    flags = *OFFSET_PTR(u16, result, 92);
    flags = (flags) & ~(4u);
    *OFFSET_PTR(u16, result, 92) = flags;
    return result;
}
