/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define PM_PrependPreSleepCallback func_0214f4ec
#define PM_AppendPostSleepCallback func_0214f4d4
#define NNS_SndStrmStart func_0212c948
#include <nnsys/snd/stream.h>

#include <nitro/snd.h>

#include <nnsys/misc.h>
#include <nnsys/snd/resource_mgr.h>

#pragma thumb off
void NNS_SndStrmStart (NNSSndStrm * stream)
{
    NNS_NULL_ASSERT(stream);

    SND_StartTimer(
        stream->chBitMask,
        0,
        (u32)(1 << stream->alarmNo),
        0
        );

    if (!stream->startFlag) {
        PM_PrependPreSleepCallback(&stream->preSleepInfo);
        PM_AppendPostSleepCallback(&stream->postSleepInfo);

        stream->startFlag = TRUE;
    }
}
