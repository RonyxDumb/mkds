/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define GXx_SetMasterBrightness_ SetBrightness
#include "gx.h"

#include "nitro/types.h"
#include "OS_spinLock.h"
#include "OS_terminate_proc.h"
#include "code32.h"

#pragma thumb off
void GXx_SetMasterBrightness_(vu16 *dst, s32 brightness){
    if (!brightness)
    {
        *dst = 0x0;
    }
    else if (brightness > 0)
    {
        *dst = (u16)((1 << REG_GX_MASTER_BRIGHT_E_MOD_SHIFT) | brightness);
    }
    else
    {
        *dst = (u16)((2 << REG_GX_MASTER_BRIGHT_E_MOD_SHIFT) | -brightness);
    }
}
