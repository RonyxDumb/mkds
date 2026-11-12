#include "Main/Net/participant_mask.h"
#include "Main/MapObjects/data_0217a000.h"

BOOL IsInParticipantMask(s32 bitIndex) {
    BOOL isSet;

    isSet = TRUE;
    if (!(gWiFiRaceSync->mParticipantMask & (1 << bitIndex))) {
        isSet = FALSE;
    }
    return isSet;
}
