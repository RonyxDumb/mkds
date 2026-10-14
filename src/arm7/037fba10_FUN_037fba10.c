/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define SND_Disable FUN_037fba64
#define SND_StopChannel FUN_037fbd0c
#define SND_Shutdown FUN_037fba10
#include "nitro/snd/common/global.h"
#include "nitro/snd/common/capture.h"
#include "nitro/snd/common/channel.h"
#include <nitro/hw/ARM7/ioreg_SND.h>
#include <nitro/os/common/system.h>
#include <nitro/os/common/systemCall.h>
#include <nitro/spi/common/pm_common.h>
extern void SND_Disable(void);
#pragma thumb off
void SND_Shutdown(void)
{
    SND_Disable();

    for (int i = 0; i < SND_CHANNEL_NUM; ++i) {
        SND_StopChannel(i, SND_CHANNEL_STOP_HOLD);
    }

    SND_StopCapture(SND_CAPTURE_0);
    SND_StopCapture(SND_CAPTURE_1);
}
