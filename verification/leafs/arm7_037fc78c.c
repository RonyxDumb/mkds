/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define SND_UpdateLfo FUN_037fc78c
#include "nitro/snd/common/exchannel.h"
#include "nitro/snd/common/util.h"
#include "nitro/snd/common/work.h"
#include "nitro/snd/common/channel.h"

#pragma thumb off
void SND_UpdateLfo(SNDLfo *lfo)
{
    if (lfo->delay_counter < lfo->param.delay) {
        lfo->delay_counter++;
        return;
    }

    u32 offset = lfo->counter;
    offset += lfo->param.speed << 6;
    offset >>= 8;
    while (offset >= SND_SIN_PERIOD) {
        offset -= SND_SIN_PERIOD;
    }
    offset <<= 8;

    lfo->counter += lfo->param.speed << 6;
    lfo->counter &= 0xFF;

    lfo->counter |= offset;
}
