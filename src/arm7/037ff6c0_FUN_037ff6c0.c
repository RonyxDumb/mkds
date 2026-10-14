/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableInterrupts FUN_037faf70
#define SND_StartAlarm FUN_037ff440
#define OS_RestoreInterrupts FUN_037faf84
#define SND_UpdateSharedWork FUN_037ff2f4
#define StartTimer FUN_037ff6c0
#include <nitro/snd/common/command.h>

#include <nitro/misc.h>
#include <nitro/os.h>
#include <nitro/pxi.h>
#include <nitro/mi.h>

#include <nitro/snd/common/seq.h>
#include <nitro/snd/common/capture.h>
#include <nitro/snd/common/work.h>
#include <nitro/snd/common/global.h>
#include <nitro/snd/common/util.h>
#include <nitro/snd/common/alarm.h>
#include <nitro/snd/common/main.h>

#pragma thumb off
void StartTimer (u32 chBitMask, u32 capBitMask, u32 alarmBitMask, u32)
    {
        OSIntrMode enabled;
        int i;

        enabled = OS_DisableInterrupts();

        for (i = 0; i < SND_CHANNEL_NUM && chBitMask != 0; i++, chBitMask >>= 1) {
            if ((chBitMask & 0x01) == 0)
                continue;
            SND_StartChannel(i);
        }

        if (capBitMask & (1 << SND_CAPTURE_0)) {
            if (capBitMask & (1 << SND_CAPTURE_1)) {
                SND_StartCaptureBoth();
            } else {
                SND_StartCapture(SND_CAPTURE_0);
            }
        } else if (capBitMask & (1 << SND_CAPTURE_1))   {
            SND_StartCapture(SND_CAPTURE_1);
        }

        for (i = 0; i < SND_ALARM_NUM && alarmBitMask != 0; i++, alarmBitMask >>= 1) {
            if ((alarmBitMask & 0x01) == 0)
                continue;
            SND_StartAlarm(i);
        }

        (void)OS_RestoreInterrupts(enabled);

        SND_UpdateSharedWork();
    }
