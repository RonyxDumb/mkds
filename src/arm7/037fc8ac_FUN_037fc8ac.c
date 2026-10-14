/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define sWeakLockChannel SDK_data_03807ea4
#define sLockChannel SDK_data_03807ea8
#define SND_GetLockedChannel FUN_037fc8ac
#include "nitro/snd/common/exchannel.h"
#include "nitro/snd/common/util.h"
#include "nitro/snd/common/work.h"
#include "nitro/snd/common/channel.h"
extern u32 sWeakLockChannel;
extern u32 sLockChannel;
#pragma thumb off
u32 SND_GetLockedChannel(u32 flags)
{
    if (flags & SND_LOCK_IMPLIED_ALLOC_CHANNEL) {
        return sWeakLockChannel;
    } else {
        return sLockChannel;
    }
}
