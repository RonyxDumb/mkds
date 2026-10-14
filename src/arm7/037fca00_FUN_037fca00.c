/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define SND_StopChannel FUN_037fbd0c
#define SND_FreeExChannel FUN_037fcac8
#define SNDi_Work SDK_data_03807ecc
#define sLockChannel SDK_data_03807ea8
#define SND_StopUnlockedChannel FUN_037fca00
#include "nitro/snd/common/exchannel.h"
#include "nitro/snd/common/util.h"
#include "nitro/snd/common/work.h"
#include "nitro/snd/common/channel.h"
extern void SND_FreeExChannel(SNDExChannel *ch_p);
extern u32 sLockChannel;
#pragma thumb off
void SND_StopUnlockedChannel(u32 chBitMask, u32 flags)
{
    SNDExChannel *ch_p;
    u32 mask = chBitMask;

    for (int chNo = 0; chNo < SND_CHANNEL_NUM && mask != 0; chNo++, mask >>= 1) {
        if ((mask & 1) == 0) {
            continue;
        }

        ch_p = &SNDi_Work.channel[chNo];

        if ((sLockChannel & (1 << chNo)) == 0) {
            if (ch_p->callback != NULL) {
                ch_p->callback(ch_p, SND_EX_CHANNEL_CALLBACK_DROP, ch_p->callback_data);
            }

            SND_StopChannel(chNo, FALSE);
            ch_p->prio = SND_EX_CHANNEL_STOP_PRIO;
            SND_FreeExChannel(ch_p);

            ch_p->sync_flag = 0;
            ch_p->active_flag = FALSE;
        }
    }
}
