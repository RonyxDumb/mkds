/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define SND_Enable FUN_037fba7c
#include "nitro/snd/common/global.h"
#include "nitro/snd/common/capture.h"
#include "nitro/snd/common/channel.h"
#include <nitro/hw/ARM7/ioreg_SND.h>
#include <nitro/os/common/system.h>
#include <nitro/os/common/systemCall.h>
#include <nitro/spi/common/pm_common.h>

#pragma thumb off
void SND_Enable(void)
{
    reg_SND_SOUNDCNT_8 |= REG_SND_SOUNDCNT_8_E_MASK;
}
