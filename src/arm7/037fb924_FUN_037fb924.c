/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define SND_SetOutputSelector FUN_037fb924
#include "nitro/snd/common/global.h"
#include "nitro/snd/common/capture.h"
#include "nitro/snd/common/channel.h"
#include <nitro/hw/ARM7/ioreg_SND.h>
#include <nitro/os/common/system.h>
#include <nitro/os/common/systemCall.h>
#include <nitro/spi/common/pm_common.h>

#pragma thumb off
void SND_SetOutputSelector(SNDOutput left, SNDOutput right, SNDChannelOut channel1, SNDChannelOut channel3)
{
    BOOL enable = (reg_SND_SOUNDCNT_8 & REG_SND_SOUNDCNT_8_E_MASK) ? TRUE : FALSE;

    reg_SND_SOUNDCNT_8 = REG_SND_SOUNDCNT_8_FIELD(enable, channel3, channel1, right, left);
}
