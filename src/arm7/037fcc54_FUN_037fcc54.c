/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define CalcRelease FUN_037fc6dc
#define SND_SetExChannelDecay FUN_037fcc54
#include "nitro/snd/common/exchannel.h"
#include "nitro/snd/common/util.h"
#include "nitro/snd/common/work.h"
#include "nitro/snd/common/channel.h"
extern u16 CalcRelease(int release);
#pragma thumb off
void SND_SetExChannelDecay(SNDExChannel *ch_p, int decay)
{
    SDK_MINMAX_ASSERT(decay, 0, 127);

    ch_p->decay = CalcRelease(decay);
}
