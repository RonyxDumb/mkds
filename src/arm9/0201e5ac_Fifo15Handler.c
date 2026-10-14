/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OSi_UnlockVram Os_UnlockVram
#define PXI_SetFifoRecvCallback Fifo_RegisterHandler
#define wvrCallback SDK_data_02173284
#define wvrArg SDK_data_02173280
#define wvrVRam SDK_data_0217327c
#define wvrLockId SDK_data_02173278
#define WvrReceiveCallback Fifo15Handler
#include <nitro/wvr/common/wvr_common.h>
#include <nitro/wvr/ARM9/wvr.h>
#include <nitro/pxi.h>
#include <nitro/os/ARM9/vramExclusive.h>
#include <nitro/gx/gx_vramcnt.h>
#include <nitro/wm.h>
extern WVRCallbackFunc wvrCallback;
extern void * wvrArg;
extern vu16 wvrVRam;
extern vu16 wvrLockId;
#pragma thumb off
void WvrReceiveCallback (PXIFifoTag tag, u32 data, BOOL err)
{
#pragma unused(tag , err)

    WVRCallbackFunc cb = wvrCallback;
    void * cbArg = wvrArg;
    WVRResult result = (WVRResult)(data & 0x000000ff);

    switch (data & 0xffff0000) {
    case WVR_PXI_COMMAND_STARTUP:
        switch (result) {
        case WVR_RESULT_FATAL_ERROR:

            if ((wvrVRam != 0) && (wvrLockId != 0)) {
                OSi_UnlockVram(wvrVRam, wvrLockId);
                wvrVRam = 0;
            }
            break;
        }
        break;
    case WVR_PXI_COMMAND_TERMINATE:
        switch (result) {
        case WVR_RESULT_SUCCESS:

            if ((wvrVRam != 0) && (wvrLockId != 0)) {
                OSi_UnlockVram(wvrVRam, wvrLockId);
                wvrVRam = 0;
            }
            break;
        }

        PXI_SetFifoRecvCallback(PXI_FIFO_TAG_WVR, NULL);
        break;
    }

    if (cb != NULL) {
        wvrCallback = NULL;
        wvrArg = NULL;
        cb(cbArg, result);
    }
}
