/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define sChannelLock SDK_data_0217d440
#define NNS_SndLockChannel func_0212bc58
#include <nnsys/snd/resource_mgr.h>

#include <nitro/snd.h>
#include <nnsys/misc.h>
extern u32 sChannelLock;
#pragma thumb off
BOOL NNS_SndLockChannel (u32 chBitFlag)
{
    if (chBitFlag == 0) return TRUE;
    if (chBitFlag & sChannelLock) return FALSE;

    SND_LockChannel(chBitFlag, 0);

    sChannelLock |= chBitFlag;

    return TRUE;
}
