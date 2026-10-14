/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define SND_GetChannelControl FUN_037fbb64
#include "nitro/snd/common/channel.h"
#include <nitro/hw/ARM7/ioreg_SND.h>

#pragma thumb off
u32 SND_GetChannelControl(int chNo)
{
    SDK_MINMAX_ASSERT(chNo, SND_CHANNEL_MIN, SND_CHANNEL_MAX);

    return *((REGType32v *)(REG_SOUND0CNT_ADDR + SND_CHANNEL_REG_OFFSET(chNo)));
}
