/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define sChannelLock SDK_data_0217d440
#define NNS_SndUnlockChannel func_0212bc20
#include <nnsys/snd/resource_mgr.h>

#include <nitro/snd.h>
#include <nnsys/misc.h>
extern u32 sChannelLock;
#pragma thumb off
void NNS_SndUnlockChannel (u32 chBitFlag)
{
    NNS_ASSERT((chBitFlag & sChannelLock) == chBitFlag);

    if (chBitFlag == 0) return;

    SND_UnlockChannel(chBitFlag, 0);

    sChannelLock &= ~chBitFlag;
}
