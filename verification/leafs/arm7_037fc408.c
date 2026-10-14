/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define SND_IsCaptureActive FUN_037fc408
#include "nitro/snd/common/capture.h"
#include <nitro/hw/ARM7/ioreg_SND.h>

#pragma thumb off
BOOL SND_IsCaptureActive(SNDCapture capture)
{
    return ((*(REGType8v *)(REG_SNDCAP0CNT_ADDR + capture)) & REG_SND_SNDCAP0CNT_E_MASK) != 0;
}
