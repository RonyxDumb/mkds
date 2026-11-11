#include "Main/Unknown/code_0205afa8.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_0203c240.h"
#include "Main/Unknown/code_0203c8c0.h"
#include "Main/Unknown/code_0205d000.h"
#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_0217a000.h"
#include "00/code_0219b580.h"
#include "Main/Unknown/code_0203c5f8.h"

s32 PackOwnKartProgress(void) {
    u32 progress;
    s32 kartStartRank;
    u16 kartIndex;
    s32 value;
    s32 lapBits;

    kartIndex = gParticipantKartMap->mKartOfParticipant[GetOwnParticipantIndex()];
    kartStartRank = GetKartStartRank(kartIndex);
    progress = GetKartFinishTimeMs(kartIndex) & WIFI_RACE_SYNC_PROGRESS_TIME_MASK;
    if (IsKartEnded(kartIndex) != 0 &&
        gRaceProgress->mKarts[kartIndex].mStatus != RACE_PROGRESS_KART_STATUS_GOAL_REACHED &&
        gWiFiRaceSync->mFinishRecorded == FALSE) {
        progress = WIFI_RACE_SYNC_PROGRESS_DID_NOT_FINISH;
    }
    if (progress == 0) {
        progress = kartStartRank - 1;
    }
    if (gRaceProgress->mKarts[kartIndex].mStatus == RACE_PROGRESS_KART_STATUS_GOAL_REACHED) {
        value = 0;
    } else {
        value = 6 - GetKartHighestLap(kartIndex);
    }
    lapBits = (value << WIFI_RACE_SYNC_PROGRESS_LAPS_SHIFT) & WIFI_RACE_SYNC_PROGRESS_LAPS_MASK;
    if (IsKartEnded(kartIndex) == 0 && gWiFiRaceSync->mFinishRecorded == FALSE) {
        value = 1;
    } else {
        value = 0;
    }
    return progress |
           (((value << WIFI_RACE_SYNC_PROGRESS_RACING_SHIFT) & WIFI_RACE_SYNC_PROGRESS_RACING_MASK) | lapBits);
}
