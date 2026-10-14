/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define SND_StopChannel FUN_037fbd0c
#define SND_FreeExChannel FUN_037fcac8
#define SNDi_Work SDK_data_03807ecc
#define sLockChannel SDK_data_03807ea8
#define sWeakLockChannel SDK_data_03807ea4
#define SND_LockChannel FUN_037fc908
#include "nitro/snd/common/exchannel.h"
#include "nitro/snd/common/util.h"
#include "nitro/snd/common/work.h"
#include "nitro/snd/common/channel.h"
extern void SND_FreeExChannel(SNDExChannel *ch_p);
extern u32 sLockChannel;
extern u32 sWeakLockChannel;
#pragma thumb off
void SND_LockChannel(u32 chBitMask, u32 flags)
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

    if (flags & SND_LOCK_IMPLIED_ALLOC_CHANNEL) {
        sWeakLockChannel |= chBitMask;
    } else {
        sLockChannel |= chBitMask;
    }
}
