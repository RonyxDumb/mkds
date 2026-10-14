/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */

#include "nitro/types.h"
#include "gx.h"
#include "code32.h"

#pragma thumb off
void G3X_SetFog(u32 enable, u32 alphamode, u32 depth, s32 offset){
    if (enable)
    {
        reg_G3X_FOG_OFFSET = (u16)offset;
        reg_G3X_DISP3DCNT = (u16)((reg_G3X_DISP3DCNT &~0x3f40) | (((depth << 0x8)|  (alphamode << 0x6)|0x80 )));

    }
    else
    {
        reg_G3X_DISP3DCNT = (u16)(reg_G3X_DISP3DCNT & (u16)~0x3080);
    }
}
