/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define PxiFifoCallback SDK_data_037ff8b4
#define PXI_SetFifoRecvCallback SDK_data_037fb6c0
#define InitPXI FUN_037ff89c
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
extern void PxiFifoCallback (PXIFifoTag tag, u32 data, BOOL);
#pragma thumb off
void InitPXI (void)
{
    PXI_SetFifoRecvCallback(PXI_FIFO_TAG_SOUND, PxiFifoCallback);

#ifdef SDK_ARM9
    if (IsCommandAvailable()) {
        while (!PXI_IsCallbackReady(PXI_FIFO_TAG_SOUND, PXI_PROC_ARM7)) {
            OS_SpinWait(100);
        }
    }
#endif
}
