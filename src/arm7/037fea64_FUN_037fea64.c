/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define GetPlayerTrack FUN_037fe2e4
#define SNDi_Work SDK_data_03807ecc
#define SND_SetTrackAllocatableChannel FUN_037fea64
#include "nitro/snd/common/seq.h"
#include "nitro/snd/common/bank.h"
#include "nitro/snd/common/exchannel.h"
#include "nitro/snd/common/mml.h"
#include "nitro/snd/common/util.h"
#include "nitro/snd/common/work.h"
#include "nitro/snd/common/main.h"
#include <nitro/misc.h>
extern SNDTrack *GetPlayerTrack(SNDPlayer *player_p, int trackNo);
#pragma thumb off
void SND_SetTrackAllocatableChannel(int playerNo, u32 trackBitMask, u32 chBitMask)
{
    SDK_MINMAX_ASSERT(playerNo, SND_PLAYER_MIN, SND_PLAYER_MAX);

    SNDPlayer *player_p = &SNDi_Work.player[playerNo];

    for (int trackNo = 0; trackNo < SND_TRACK_NUM_PER_PLAYER && trackBitMask != 0; trackNo++, trackBitMask >>= 1) {
        if ((trackBitMask & 1) == 0) {
            continue;
        }

        SNDTrack *track_p = GetPlayerTrack(player_p, trackNo);
        if (track_p == NULL) {
            continue;
        }

        track_p->channel_mask = chBitMask;
        track_p->channel_mask_flag = TRUE;
    }
}
