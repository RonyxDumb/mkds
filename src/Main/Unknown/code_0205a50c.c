#include "Main/Unknown/code_0205a50c.h"
#include "Main/Unknown/unk_0217a000.h"

BOOL IsInParticipantMask(s32 bitIndex) {
    BOOL isSet;

    isSet = TRUE;
    if (!(gWiFiRaceSync->mParticipantMask & (1 << bitIndex))) {
        isSet = FALSE;
    }
    return isSet;
}
