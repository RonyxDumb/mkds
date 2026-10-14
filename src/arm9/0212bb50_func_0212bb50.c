/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define sChannelLock SDK_data_0217d440
#define sCaptureLock SDK_data_0217d438
#define sAlarmLock SDK_data_0217d43c
#define NNSi_SndInitResourceMgr func_0212bb50
#include <nnsys/snd/resource_mgr.h>

#include <nitro/snd.h>
#include <nnsys/misc.h>
extern u32 sChannelLock;
extern u32 sCaptureLock;
extern u32 sAlarmLock;
#pragma thumb off
void NNSi_SndInitResourceMgr (void)
{
    sChannelLock = 0;
    sCaptureLock = 0;
    sAlarmLock = 0;
}
