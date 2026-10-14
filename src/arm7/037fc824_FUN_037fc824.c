/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define SND_StopChannel FUN_037fbd0c
#define SNDi_Work SDK_data_03807ecc
#define SND_InvalidateWave FUN_037fc824
#include "nitro/snd/common/exchannel.h"
#include "nitro/snd/common/util.h"
#include "nitro/snd/common/work.h"
#include "nitro/snd/common/channel.h"

#pragma thumb off
void SND_InvalidateWave(const void *start, const void *end)
{
    for (u8 ch = 0; ch < SND_CHANNEL_NUM; ch++) {
        SNDExChannel *ch_p = &SNDi_Work.channel[ch];

        if (!ch_p->active_flag) {
            continue;
        }

        if (ch_p->type != SND_EX_CHANNEL_PCM) {
            continue;
        }

        if (start <= ch_p->data && ch_p->data <= end) {
            ch_p->start_flag = FALSE;
            SND_StopChannel(ch, FALSE);
        }
    }
}
