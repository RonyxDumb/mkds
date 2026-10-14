/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define sDispMode SDK_data_021802ac
#define sIsDispOn SDK_data_0216f070
#define GX_DispOn func_021489c4
#include "gx.h"

#include "nitro/types.h"
#include "OS_spinLock.h"
#include "OS_terminate_proc.h"
#include "code32.h"
extern u16 sDispMode;
extern u16 sIsDispOn;
#pragma thumb off
void GX_DispOn(){
    sIsDispOn = TRUE;
    if (sDispMode)
    {
        reg_GX_DISPCNT = (reg_GX_DISPCNT & ~REG_GX_DISPCNT_MODE_MASK) | (sDispMode << REG_GX_DISPCNT_MODE_SHIFT);
    }
    else
    {
        reg_GX_DISPCNT = reg_GX_DISPCNT | (GX_DISPMODE_GRAPHICS << REG_GX_DISPCNT_MODE_SHIFT);
    }
}
