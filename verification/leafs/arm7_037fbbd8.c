/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define SND_IsChannelActive FUN_037fbbd8
#include "nitro/snd/common/channel.h"
#include <nitro/hw/ARM7/ioreg_SND.h>

#pragma thumb off
BOOL SND_IsChannelActive(int chNo)
{
    SDK_MINMAX_ASSERT(chNo, SND_CHANNEL_MIN, SND_CHANNEL_MAX);

    u8 reg = *((REGType8v *)(REG_SOUND0CNT_8_ADDR + SND_CHANNEL_REG_OFFSET(chNo)));

    return (reg & REG_SND_SOUND0CNT_8_E_MASK) ? TRUE : FALSE;
}
