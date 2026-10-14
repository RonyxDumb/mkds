/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define disableBankForX_ SDK_data_02148e80
#define gGXState SDK_data_021802b0
#define GX_DisableBankForSubOBJExtPltt GX_DisableBankForOBJExtPltt
#include "nitro/types.h"
#include "gx.h"
#include "code32.h"
extern u32 disableBankForX_(u16 *ptr);
extern struct GX_State gGXState;
#pragma thumb off
u32 GX_DisableBankForSubOBJExtPltt(){
    reg_GXS_DB_DISPCNT &= ~REG_GX_DISPCNT_O_MASK;
    return disableBankForX_(&gGXState.sub_objExtPltt);
}
