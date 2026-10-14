/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define SND_StopChannel FUN_037fbd0c
#define SND_SetupChannelPcm FUN_037fbea0
#define SND_SetupChannelPsg FUN_037fbde8
#define SND_SetupChannelNoise FUN_037fbd38
#define SND_SetChannelTimer FUN_037fbc70
#define SND_SetChannelVolume FUN_037fbc88
#define SND_SetChannelPan FUN_037fbbf4
#define SNDi_Work SDK_data_03807ecc
#define SND_UpdateExChannel FUN_037fd130
#include "nitro/snd/common/exchannel.h"
#include "nitro/snd/common/util.h"
#include "nitro/snd/common/work.h"
#include "nitro/snd/common/channel.h"

#pragma thumb off
void SND_UpdateExChannel(void)
{
    SNDExChannel *ch_p;

    for (int ch = 0; ch < SND_CHANNEL_NUM; ch++) {
        ch_p = &SNDi_Work.channel[ch];

        if (!ch_p->sync_flag) {
            continue;
        }

        if (ch_p->sync_flag & SND_EX_CHANNEL_UPDATE_STOP) {
            SND_StopChannel(ch, FALSE);
        }

        if (ch_p->sync_flag & SND_EX_CHANNEL_UPDATE_START) {
            switch (ch_p->type) {
            case SND_EX_CHANNEL_PCM:
                SND_SetupChannelPcm(
                    ch,
                    ch_p->data,
                    ch_p->wave.format,
                    ch_p->wave.loopflag ? SND_CHANNEL_LOOP_REPEAT : SND_CHANNEL_LOOP_1SHOT,
                    ch_p->wave.loopstart,
                    ch_p->wave.looplen,
                    ch_p->volume & 0xFF,
                    ch_p->volume >> 8,
                    ch_p->timer,
                    ch_p->pan);
                break;

            case SND_EX_CHANNEL_PSG:
                SND_SetupChannelPsg(ch, ch_p->duty, ch_p->volume & 0xFF, ch_p->volume >> 8, ch_p->timer, ch_p->pan);
                break;

            case SND_EX_CHANNEL_NOISE:
                SND_SetupChannelNoise(ch, ch_p->volume & 0xFF, ch_p->volume >> 8, ch_p->timer, ch_p->pan);
                break;
            }
        } else {
            if (ch_p->sync_flag & SND_EX_CHANNEL_UPDATE_TIMER) {
                SND_SetChannelTimer(ch, ch_p->timer);
            }
            if (ch_p->sync_flag & SND_EX_CHANNEL_UPDATE_VOLUME) {
                SND_SetChannelVolume(ch, ch_p->volume & 0xFF, ch_p->volume >> 8);
            }
            if (ch_p->sync_flag & SND_EX_CHANNEL_UPDATE_PAN) {
                SND_SetChannelPan(ch, ch_p->pan);
            }
        }
    }

    for (int ch = 0; ch < SND_CHANNEL_NUM; ch++) {
        ch_p = &SNDi_Work.channel[ch];

        if (!ch_p->sync_flag) {
            continue;
        }

        if (ch_p->sync_flag & SND_EX_CHANNEL_UPDATE_START) {
            SND_StartChannel(ch);
        }

        ch_p->sync_flag = 0;
    }
}
