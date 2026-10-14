/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define SNDi_DecibelSquareTable SDK_data_03806f40
#define SND_UpdateExChannelEnvelope FUN_037fcc94
#include "nitro/snd/common/exchannel.h"
#include "nitro/snd/common/util.h"
#include "nitro/snd/common/work.h"
#include "nitro/snd/common/channel.h"

#pragma thumb off
s32 SND_UpdateExChannelEnvelope(SNDExChannel *ch_p, BOOL doPeriodicProc)
{
    if (doPeriodicProc) {
        switch (ch_p->env_status) {
        case SND_ENV_ATTACK: {
            s32 env_decay_s32 = -ch_p->env_decay;

            env_decay_s32 *= ch_p->attack;
            env_decay_s32 >>= 8;

            ch_p->env_decay = -env_decay_s32;

            if (ch_p->env_decay == 0) {
                ch_p->env_status = SND_ENV_DECAY;
            }
            break;
        }

        case SND_ENV_DECAY: {
            const s32 sustain_decay = SND_CalcDecibelSquare(ch_p->sustain) << SND_EX_CHANNEL_ENV_DECAY_SHIFT;

            ch_p->env_decay -= ch_p->decay;
            if (ch_p->env_decay > sustain_decay) {
                break;
            }
            ch_p->env_decay = sustain_decay;
            ch_p->env_status = SND_ENV_SUSTAIN;
            break;
        }

        case SND_ENV_SUSTAIN:
            break;

        case SND_ENV_RELEASE:
            ch_p->env_decay -= ch_p->release;
            break;
        }
    }

    return ch_p->env_decay >> SND_EX_CHANNEL_ENV_DECAY_SHIFT;
}
