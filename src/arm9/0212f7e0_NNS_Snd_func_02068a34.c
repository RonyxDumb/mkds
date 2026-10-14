/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define NNSi_SndFaderUpdate NNS_Snd_func_02068a34
#include <nnsys/snd/fader.h>
#include <nnsys/misc.h>

#pragma thumb off
void NNSi_SndFaderUpdate (NNSSndFader * fader)
{
    NNS_NULL_ASSERT(fader);

    if (fader->counter < fader->frame) {
        fader->counter++;
    }
}
