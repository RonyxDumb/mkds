/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define SNDi_Work SDK_data_03807ecc
#define sLockChannel SDK_data_03807ea8
#define sWeakLockChannel SDK_data_03807ea4
#define SND_ExChannelInit FUN_037fd31c
#include "nitro/snd/common/exchannel.h"
#include "nitro/snd/common/util.h"
#include "nitro/snd/common/work.h"
#include "nitro/snd/common/channel.h"
extern u32 sLockChannel;
extern u32 sWeakLockChannel;
#pragma thumb off
void SND_ExChannelInit(void)
{
    for (int ch = 0; ch < SND_CHANNEL_NUM; ch++) {
        SNDExChannel *ch_p = &SNDi_Work.channel[ch];

        ch_p->myNo = ch;
        ch_p->sync_flag = 0;
        ch_p->active_flag = FALSE;
    }

    sLockChannel = 0;
    sWeakLockChannel = 0;
}
