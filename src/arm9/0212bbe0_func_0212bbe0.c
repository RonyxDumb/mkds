/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define sCaptureLock SDK_data_0217d438
#define NNS_SndUnlockCapture func_0212bbe0
#include <nnsys/snd/resource_mgr.h>

#include <nitro/snd.h>
#include <nnsys/misc.h>
extern u32 sCaptureLock;
#pragma thumb off
void NNS_SndUnlockCapture (u32 capBitFlag)
{
    NNS_ASSERT((capBitFlag & sCaptureLock) == capBitFlag);
    sCaptureLock &= ~capBitFlag;
}
