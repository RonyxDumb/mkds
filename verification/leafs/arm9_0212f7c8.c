/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define NNSi_SndFaderIsFinished NNS_Snd_func_02068a4c
#include <nnsys/snd/fader.h>
#include <nnsys/misc.h>

#pragma thumb off
BOOL NNSi_SndFaderIsFinished (const NNSSndFader * fader)
{
    NNS_NULL_ASSERT(fader);

    return fader->counter >= fader->frame ? TRUE : FALSE;
}
