/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */

#include "fx.h"

#include "nitro/types.h"
#include "registers.h"
#include "code32.h"
extern fx32 FX_GetSqrtResult();
#pragma thumb off
fx32 FX_Sqrt(fx32 x){
    if (x > 0)
    {
        reg_CP_SQRTCNT = 0x1;
        reg_CP_SQRT_PARAM = (u64)((fx64)x << 32);
        return FX_GetSqrtResult();
    }
    else
    {
        return 0;
    }
}
