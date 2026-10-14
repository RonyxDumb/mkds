/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define SND_StartLfo FUN_037fc7f0
#include "nitro/snd/common/exchannel.h"
#include "nitro/snd/common/util.h"
#include "nitro/snd/common/work.h"
#include "nitro/snd/common/channel.h"

#pragma thumb off
void SND_StartLfo(SNDLfo *lfo)
{
    lfo->counter = 0;
    lfo->delay_counter = 0;
}
