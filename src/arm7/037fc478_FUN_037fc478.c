/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define SND_GetLfoValue FUN_037fc73c
#define SND_UpdateLfo FUN_037fc78c
#define LfoMain FUN_037fc478
#include "nitro/snd/common/exchannel.h"
#include "nitro/snd/common/util.h"
#include "nitro/snd/common/work.h"
#include "nitro/snd/common/channel.h"
extern s32 SND_GetLfoValue(SNDLfo *lfo);
extern void SND_UpdateLfo(SNDLfo *lfo);
#pragma thumb off
s32 LfoMain(SNDExChannel *ch_p, BOOL doPeriodicProc)
{
    s64 lfo_value = SND_GetLfoValue(&ch_p->lfo);

    if (lfo_value != 0) {
        switch (ch_p->lfo.param.target) {
        case SND_LFO_VOLUME:
            lfo_value *= 60;
            break;
        case SND_LFO_PITCH:
            lfo_value *= (1 << SND_PITCH_DIVISION_BIT);
            break;
        case SND_LFO_PAN:
            lfo_value *= 64;
            break;
        }
        lfo_value >>= 14;
    }

    if (doPeriodicProc) {
        SND_UpdateLfo(&ch_p->lfo);
    }

    return lfo_value;
}
