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
    u32 c;
    s32 kartStartRank;
    u16 kartIndex;
    s32 d;
    s32 lapBits;

    kartIndex = gParticipantKartMap->mKartOfParticipant[GetOwnParticipantIndex()];
    kartStartRank = GetKartStartRank(kartIndex);
    c = GetKartFinishTimeMs(kartIndex) & WIFI_RACE_SYNC_PROGRESS_TIME_MASK;
    if (IsKartEnded(kartIndex) != 0 && gRaceProgress->mKarts[kartIndex].mStatus != 1 &&
        gWiFiRaceSync->mFinishRecorded == FALSE) {
        c = WIFI_RACE_SYNC_PROGRESS_DID_NOT_FINISH;
    }
    if (c == 0) {
        c = kartStartRank - 1;
    }
    if (gRaceProgress->mKarts[kartIndex].mStatus == 1) {
        d = 0;
    } else {
        d = 6 - GetKartHighestLap(kartIndex);
    }
    lapBits = (d << WIFI_RACE_SYNC_PROGRESS_LAPS_SHIFT) & WIFI_RACE_SYNC_PROGRESS_LAPS_MASK;
    if (IsKartEnded(kartIndex) == 0 && gWiFiRaceSync->mFinishRecorded == FALSE) {
        d = 1;
    } else {
        d = 0;
    }
    return c | (((d << WIFI_RACE_SYNC_PROGRESS_RACING_SHIFT) & WIFI_RACE_SYNC_PROGRESS_RACING_MASK) | lapBits);
}
