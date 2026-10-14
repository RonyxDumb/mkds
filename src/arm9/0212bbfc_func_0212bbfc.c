/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define sCaptureLock SDK_data_0217d438
#define NNS_SndLockCapture func_0212bbfc
#include <nnsys/snd/resource_mgr.h>

#include <nitro/snd.h>
#include <nnsys/misc.h>
extern u32 sCaptureLock;
#pragma thumb off
BOOL NNS_SndLockCapture (u32 capBitFlag)
{
    if (capBitFlag & sCaptureLock) return FALSE;

    sCaptureLock |= capBitFlag;

    return TRUE;
}
