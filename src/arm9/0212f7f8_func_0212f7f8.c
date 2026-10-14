/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define NNSi_SndFaderGet func_0212f7f8
#include <nnsys/snd/fader.h>
#include <nnsys/misc.h>

#pragma thumb off
int NNSi_SndFaderGet (const NNSSndFader * fader)
{
    s64 value;

    NNS_NULL_ASSERT(fader);

    if (fader->counter >= fader->frame) {
        return fader->target;
    }

    value = (fader->target - fader->origin)
            * fader->counter / fader->frame
            + fader->origin;

    return (int)value;
}
