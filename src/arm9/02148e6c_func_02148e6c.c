/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define disableBankForX_ SDK_data_02148e80
#define gGXState SDK_data_0218029e
#define GX_DisableBankForSubOBJ func_02148e6c
#include "nitro/types.h"
#include "gx.h"
#include "code32.h"
extern u32 disableBankForX_(u16 *ptr);
extern struct GX_State gGXState;
#pragma thumb off
u32 GX_DisableBankForSubOBJ(){
    return disableBankForX_(&gGXState.sub_obj);
}
