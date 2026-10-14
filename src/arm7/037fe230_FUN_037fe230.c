/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define ClosePlayerTrack FUN_037fe270
#define FinishPlayer FUN_037fe230
#include "nitro/snd/common/seq.h"
#include "nitro/snd/common/bank.h"
#include "nitro/snd/common/exchannel.h"
#include "nitro/snd/common/mml.h"
#include "nitro/snd/common/util.h"
#include "nitro/snd/common/work.h"
#include "nitro/snd/common/main.h"
#include <nitro/misc.h>
extern void ClosePlayerTrack(SNDPlayer *player_p, int trackNo);
#pragma thumb off
void FinishPlayer(SNDPlayer *player_p)
{
    for (int trackNo = 0; trackNo < SND_TRACK_NUM_PER_PLAYER; trackNo++) {
        ClosePlayerTrack(player_p, trackNo);
    }

    player_p->active_flag = FALSE;
}
