/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define SND_StopChannel FUN_037fbd0c
#include "nitro/snd/common/channel.h"
#include <nitro/hw/ARM7/ioreg_SND.h>

#pragma thumb off
void SND_StopChannel(int chNo, s32 flags)
{
    SDK_MINMAX_ASSERT(chNo, SND_CHANNEL_MIN, SND_CHANNEL_MAX);

    REGType32v *reg = (REGType32v *)(REG_SOUND0CNT_ADDR + SND_CHANNEL_REG_OFFSET(chNo));
    u32 ctrl = *reg;
    ctrl &= ~REG_SND_SOUND0CNT_E_MASK;
    if (flags & SND_CHANNEL_STOP_HOLD) {
        ctrl |= REG_SND_SOUND0CNT_HOLD_MASK;
    }
    *reg = ctrl;
}
