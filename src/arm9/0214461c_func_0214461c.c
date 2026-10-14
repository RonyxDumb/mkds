/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define WmGetSharedDataAddress func_021445e0
#define WM_GetSharedDataAddress func_0214461c
#include <nitro/wm.h>

#include    "wm_arm9_private.h"
extern u16 * WmGetSharedDataAddress (WMDataSharingInfo * dsInfo, u32 aidBitmap, u16 * receiveBuf, u32 aid);
#pragma thumb off
u16 * WM_GetSharedDataAddress (WMDataSharingInfo * dsInfo, WMDataSet * receiveData, u16 aid)
{
    u32 aidBitmap = receiveData->aidBitmap;
    u32 receivedBitmap = receiveData->receivedBitmap;
    u32 aidBit = (1U << aid);

    if (dsInfo == NULL) {
        WM_WARNING("Parameter \"dsInfo\" must not be NULL.\n");
        return NULL;
    }

    if (receiveData == NULL) {
        WM_WARNING("Parameter \"receiveData\" must not be NULL.\n");
        return NULL;
    }

    if (!(aidBitmap & aidBit)) {
        return NULL;
    }

    if (!(receivedBitmap & aidBit)) {
        return NULL;
    }

    return WmGetSharedDataAddress(dsInfo, aidBitmap, receiveData->data, aid);
}
