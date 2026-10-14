/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define SNDi_Work SDK_data_03807ecc
#define SND_SeqInit FUN_037fef54
#include "nitro/snd/common/seq.h"
#include "nitro/snd/common/bank.h"
#include "nitro/snd/common/exchannel.h"
#include "nitro/snd/common/mml.h"
#include "nitro/snd/common/util.h"
#include "nitro/snd/common/work.h"
#include "nitro/snd/common/main.h"
#include <nitro/misc.h>

#pragma thumb off
void SND_SeqInit(void)
{
    for (int playerNo = 0; playerNo < SND_PLAYER_NUM; playerNo++) {
        SNDPlayer *player_p = &SNDi_Work.player[playerNo];

        player_p->active_flag = FALSE;
        player_p->myNo = (u8)playerNo;
    }

    for (int trackNo = 0; trackNo < SND_TRACK_NUM; trackNo++) {
        SNDTrack *track_p = &SNDi_Work.track[trackNo];

        track_p->active_flag = FALSE;
    }
}
