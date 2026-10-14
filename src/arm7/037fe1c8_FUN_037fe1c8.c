/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define SND_FreeExChannel FUN_037fcac8
#define ChannelCallback FUN_037fe1c8
#include "nitro/snd/common/seq.h"
#include "nitro/snd/common/bank.h"
#include "nitro/snd/common/exchannel.h"
#include "nitro/snd/common/mml.h"
#include "nitro/snd/common/util.h"
#include "nitro/snd/common/work.h"
#include "nitro/snd/common/main.h"
#include <nitro/misc.h>

#pragma thumb off
void ChannelCallback(SNDExChannel *drop_p, SNDExChannelCallbackStatus status, void *userData)
{
    SNDTrack *track_p = (SNDTrack *)userData;

    SDK_NULL_ASSERT(drop_p);
    SDK_NULL_ASSERT(track_p);

    if (status == SND_EX_CHANNEL_CALLBACK_FINISH) {
        drop_p->prio = SND_EX_CHANNEL_STOP_PRIO;
        SND_FreeExChannel(drop_p);
    }

    if (track_p->channel_list == drop_p) {
        track_p->channel_list = drop_p->nextLink;
        return;
    }

    SNDExChannel *ch_p = track_p->channel_list;

    while (ch_p->nextLink != NULL) {
        if (ch_p->nextLink == drop_p) {
            ch_p->nextLink = drop_p->nextLink;
            return;
        }
        ch_p = ch_p->nextLink;
    }
}
