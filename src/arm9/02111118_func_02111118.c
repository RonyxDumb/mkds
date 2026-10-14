/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define sChannelLock SDK_data_0217d328
#define sCaptureLock SDK_data_0217d324
#define sAlarmLock SDK_data_0217d320
#define NNSi_SndInitResourceMgr func_02111118
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
