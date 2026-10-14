/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define StartExChannel FUN_037fc5e4
#define SND_StartExChannelPcm FUN_037fcde8
#include "nitro/snd/common/exchannel.h"
#include "nitro/snd/common/util.h"
#include "nitro/snd/common/work.h"
#include "nitro/snd/common/channel.h"
extern void StartExChannel(SNDExChannel *ch_p, s32 length);
#pragma thumb off
BOOL SND_StartExChannelPcm(SNDExChannel *ch_p, const struct SNDWaveParam *wave, const void *data, s32 length)
{
    ch_p->type = SND_EX_CHANNEL_PCM;
    ch_p->wave = *wave;
    ch_p->data = data;

    StartExChannel(ch_p, length);

    return TRUE;
}
