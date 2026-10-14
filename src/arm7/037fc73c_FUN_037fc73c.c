/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define SND_SinIdx FUN_037fbfa4
#define SND_GetLfoValue FUN_037fc73c
#include "nitro/snd/common/exchannel.h"
#include "nitro/snd/common/util.h"
#include "nitro/snd/common/work.h"
#include "nitro/snd/common/channel.h"

#pragma thumb off
s32 SND_GetLfoValue(SNDLfo *lfo)
{
    if (lfo->param.depth == 0) {
        return 0;
    }
    if (lfo->delay_counter < lfo->param.delay) {
        return 0;
    }

    u32 offset = lfo->counter;
    offset >>= 8;

    return SND_SinIdx((int)offset) * lfo->param.depth * lfo->param.range;
}
