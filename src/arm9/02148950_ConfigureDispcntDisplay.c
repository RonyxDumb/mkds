/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define sIsDispOn SDK_data_0216f070
#define sDispMode SDK_data_021802ac
#define GX_SetGraphicsMode ConfigureDispcntDisplay
#include "gx.h"

#include "nitro/types.h"
#include "OS_spinLock.h"
#include "OS_terminate_proc.h"
#include "code32.h"
extern u16 sIsDispOn;
extern u16 sDispMode;
#pragma thumb off
void GX_SetGraphicsMode(GXDispMode dispMode, GXBGMode bgMode, GXBG0As bg0_2d3d){
    u32 temp2 = reg_GX_DISPCNT;
    sDispMode = (u16)dispMode;
    if (!sIsDispOn)
        dispMode = (GXDispMode)0;
    reg_GX_DISPCNT = ((bgMode << REG_GX_DISPCNT_BGMODE_SHIFT) | ((temp2 & ~(REG_GX_DISPCNT_BGMODE_MASK | REG_GX_DISPCNT_MODE_MASK | REG_GX_DISPCNT_BG02D3D_MASK | REG_GX_DISPCNT_VRAM_MASK)) | (dispMode << REG_GX_DISPCNT_MODE_SHIFT))) | (bg0_2d3d << REG_GX_DISPCNT_BG02D3D_SHIFT);
    if (!sDispMode)
        sIsDispOn = FALSE;
}
