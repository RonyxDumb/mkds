/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define SND_InitLfoParam FUN_037fc800
#include "nitro/snd/common/exchannel.h"
#include "nitro/snd/common/util.h"
#include "nitro/snd/common/work.h"
#include "nitro/snd/common/channel.h"

#pragma thumb off
void SND_InitLfoParam(SNDLfoParam *lfo)
{
    lfo->target = SND_LFO_PITCH;
    lfo->depth = 0;
    lfo->range = 1;
    lfo->speed = 16;
    lfo->delay = 0;
}
