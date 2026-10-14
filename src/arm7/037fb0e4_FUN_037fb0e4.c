/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define PXI_SetFifoRecvCallback FUN_037fb6c0
#define OSi_IsInitReset SDK_data_038078b0
#define OSi_CommonCallback SDK_data_037fb098
#define OS_InitReset FUN_037fb0e4
#include <nitro.h>
#include <nitro/mb.h>
#include <nitro/snd/common/global.h>
#include <nitro/card.h>

#include <nitro/code32.h>
    #include <nitro/itcm_begin.h>

    #include <nitro/itcm_end.h>
    #include <nitro/wram_begin.h>

    #include <nitro/wram_end.h>
#include <nitro/itcm_begin.h>

#include <nitro/itcm_end.h>
    #include <nitro/wram_begin.h>

#include <nitro/wram_end.h>
#include <nitro/itcm_begin.h>

#include <nitro/itcm_end.h>
extern u16 OSi_IsInitReset;
extern void OSi_CommonCallback (PXIFifoTag tag, u32 data, BOOL err);
#pragma thumb off
void OS_InitReset (void)
{
    if (OSi_IsInitReset) {
        return;
    }
    OSi_IsInitReset = TRUE;

#ifdef SDK_ARM9
    PXI_Init();
    while (!PXI_IsCallbackReady(PXI_FIFO_TAG_OS, PXI_PROC_ARM7)) {
    }
#endif

    PXI_SetFifoRecvCallback(PXI_FIFO_TAG_OS, OSi_CommonCallback);
}
