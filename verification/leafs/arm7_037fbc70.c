/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define SND_SetChannelTimer FUN_037fbc70
#include "nitro/snd/common/channel.h"
#include <nitro/hw/ARM7/ioreg_SND.h>

#pragma thumb off
void SND_SetChannelTimer(int chNo, int timer)
{
    SDK_MINMAX_ASSERT(chNo, SND_CHANNEL_MIN, SND_CHANNEL_MAX);
    SDK_MINMAX_ASSERT(timer, SND_CHANNEL_TIMER_MIN, SND_CHANNEL_TIMER_MAX);

    *((REGType16v *)(REG_SOUND0TMR_ADDR + SND_CHANNEL_REG_OFFSET(chNo))) = (u16)(0x10000 - timer);
}
