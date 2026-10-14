/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define PM_DeletePreSleepCallback func_0214f4bc
#define PM_DeletePostSleepCallback func_0214f4a4
#define SND_GetCurrentCommandTag func_02021114
#define SND_FlushCommand Sound_FlushCommand
#define SND_WaitForCommandProc func_02021154
#define ShutdownStrm func_0212c7f0
#define ForceStopStrm func_0212c824
#include <nnsys/snd/stream.h>

#include <nitro/snd.h>

#include <nnsys/misc.h>
#include <nnsys/snd/resource_mgr.h>
extern void ShutdownStrm (NNSSndStrm * stream);
#pragma thumb off
void ForceStopStrm (NNSSndStrm * stream)
{
    u32 commandTag;

    NNS_NULL_ASSERT(stream);

    if (stream->startFlag) {
        SND_StopTimer(
            stream->chBitMask,
            0,
            (u32)(1 << stream->alarmNo),
            0
            );

        PM_DeletePreSleepCallback(&stream->preSleepInfo);
        PM_DeletePostSleepCallback(&stream->postSleepInfo);

        stream->startFlag = FALSE;

        commandTag = SND_GetCurrentCommandTag();
        (void)SND_FlushCommand(SND_COMMAND_BLOCK);
        SND_WaitForCommandProc(commandTag);
    }

    ShutdownStrm(stream);
}
