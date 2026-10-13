/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define disableBankForX_ SDK_data_02149060
#define gGXState SDK_data_021802b0
#define GX_DisableBankForBGExtPltt func_0214903c
#include "nitro/types.h"
#include "gx.h"
#include "code32.h"
extern u32 disableBankForX_(u16 *ptr);
extern struct GX_State gGXState;
#pragma thumb off
u32 GX_DisableBankForBGExtPltt(){
    reg_GX_DISPCNT &= ~REG_GX_DISPCNT_BG_MASK;
    return disableBankForX_(&gGXState.bgExtPltt);
}
