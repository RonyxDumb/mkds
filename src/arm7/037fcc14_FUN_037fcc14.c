/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define SND_IsExChannelActive FUN_037fcc14
#include "nitro/snd/common/exchannel.h"
#include "nitro/snd/common/util.h"
#include "nitro/snd/common/work.h"
#include "nitro/snd/common/channel.h"

#pragma thumb off
BOOL SND_IsExChannelActive(SNDExChannel *ch_p)
{
    SDK_NULL_ASSERT(ch_p);

    return ch_p->active_flag;
}
