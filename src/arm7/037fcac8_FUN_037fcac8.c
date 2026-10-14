/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define SND_FreeExChannel FUN_037fcac8
#include "nitro/snd/common/exchannel.h"
#include "nitro/snd/common/util.h"
#include "nitro/snd/common/work.h"
#include "nitro/snd/common/channel.h"

#pragma thumb off
void SND_FreeExChannel(SNDExChannel *ch_p)
{
    if (ch_p == NULL) {
        return;
    }

    ch_p->callback = NULL;
    ch_p->callback_data = NULL;
}
