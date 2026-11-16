#include "Main/Net/participant_mask.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Save/ghost_record_file.h"

BOOL IsInParticipantMask(s32 bitIndex) {
    BOOL isSet;

    isSet = TRUE;
    if (!(g_GlobalAA->mParticipantMask & (1 << bitIndex))) {
        isSet = FALSE;
    }
    return isSet;
}
