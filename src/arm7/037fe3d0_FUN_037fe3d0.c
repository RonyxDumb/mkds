/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define SND_FreeExChannel FUN_037fcac8
#define FreeTrackChannelAll FUN_037fe3d0
#include "nitro/snd/common/seq.h"
#include "nitro/snd/common/bank.h"
#include "nitro/snd/common/exchannel.h"
#include "nitro/snd/common/mml.h"
#include "nitro/snd/common/util.h"
#include "nitro/snd/common/work.h"
#include "nitro/snd/common/main.h"
#include <nitro/misc.h>

#pragma thumb off
void FreeTrackChannelAll(SNDTrack *track_p)
{
    SNDExChannel *ch_p = track_p->channel_list;

    while (ch_p != NULL) {
        SND_FreeExChannel(ch_p);
        ch_p = ch_p->nextLink;
    }

    track_p->channel_list = NULL;
}
