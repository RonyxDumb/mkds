/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define GetPlayerTrack FUN_037fe2e4
#define UpdateTrackChannel FUN_037fe088
#define UpdatePlayerChannel FUN_037fe044
#include "nitro/snd/common/seq.h"
#include "nitro/snd/common/bank.h"
#include "nitro/snd/common/exchannel.h"
#include "nitro/snd/common/mml.h"
#include "nitro/snd/common/util.h"
#include "nitro/snd/common/work.h"
#include "nitro/snd/common/main.h"
#include <nitro/misc.h>
extern SNDTrack *GetPlayerTrack(SNDPlayer *player_p, int trackNo);
extern void UpdateTrackChannel(SNDTrack *track_p, SNDPlayer *player_p, BOOL doRelease);
#pragma thumb off
void UpdatePlayerChannel(SNDPlayer *player_p)
{
    for (int trackNo = 0; trackNo < SND_TRACK_NUM_PER_PLAYER; trackNo++) {
        SNDTrack *track_p = GetPlayerTrack(player_p, trackNo);
        if (track_p == NULL) {
            continue;
        }

        UpdateTrackChannel(track_p, player_p, TRUE);
    }
}
