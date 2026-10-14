/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define SNDi_Work SDK_data_03807ecc
#define AllocTrack FUN_037fd37c
#include "nitro/snd/common/seq.h"
#include "nitro/snd/common/bank.h"
#include "nitro/snd/common/exchannel.h"
#include "nitro/snd/common/mml.h"
#include "nitro/snd/common/util.h"
#include "nitro/snd/common/work.h"
#include "nitro/snd/common/main.h"
#include <nitro/misc.h>

#pragma thumb off
int AllocTrack(void)
{
    for (int trackID = 0; trackID < SND_TRACK_NUM; trackID++) {
        SNDTrack *track_p = &SNDi_Work.track[trackID];

        if (!track_p->active_flag) {
            track_p->active_flag = TRUE;
            return trackID;
        }
    }

    return -1;
}
