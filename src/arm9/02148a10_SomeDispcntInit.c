/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define sIsDispOn SDK_data_0216f070
#define sDispMode SDK_data_021802ac
#define GX_DispOff SomeDispcntInit
#include "gx.h"

#include "nitro/types.h"
#include "OS_spinLock.h"
#include "OS_terminate_proc.h"
#include "code32.h"
extern u16 sIsDispOn;
extern u16 sDispMode;
#pragma thumb off
void GX_DispOff(){
    u32 temp = reg_GX_DISPCNT;
    sIsDispOn = FALSE;
    sDispMode = (u16)((temp & REG_GX_DISPCNT_MODE_MASK) >> REG_GX_DISPCNT_MODE_SHIFT);
    reg_GX_DISPCNT = temp & ~REG_GX_DISPCNT_MODE_MASK;
}
