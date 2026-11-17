#include "Main/Net/kart_progress_pack.h"
#include "Main/Race/kart_finish_time.h"
#include "Main/Race/kart_highest_lap.h"
#include "Main/Race/cup_records.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/System/backup_net_camera_work.h"
#include "00/Lib/DWC/friends_match_session.h"
#include "Main/Race/kart.h"
#include "Main/Save/ghost_record_file.h"
#include "Main/System/init_after_startup.h"

s32 PackOwnKartProgress(void) {
    u32 progress;
    s32 kartStartRank;
    u16 kartIndex;
    s32 value;
    s32 lapBits;

    kartIndex = gParticipantKartMap->mKartOfParticipant[DWC_GetMyAID()];
    kartStartRank = GetKartStartRank(kartIndex);
    progress = GetKartFinishTimeMs(kartIndex) & WIFI_RACE_SYNC_PROGRESS_TIME_MASK;
    if (IsKartEnded(kartIndex) != 0 &&
        gRaceProgress->mKarts[kartIndex].mStatus != RACE_PROGRESS_KART_STATUS_GOAL_OR_WINNING_TEAM &&
        gWiFiRaceSync->mFinishRecorded == FALSE) {
        progress = WIFI_RACE_SYNC_PROGRESS_DID_NOT_FINISH;
    }
    if (progress == 0) {
        progress = kartStartRank - 1;
    }
    if (gRaceProgress->mKarts[kartIndex].mStatus == RACE_PROGRESS_KART_STATUS_GOAL_OR_WINNING_TEAM) {
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
