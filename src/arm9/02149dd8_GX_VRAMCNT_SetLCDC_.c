/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */

#include "nitro/types.h"
#include "gx.h"
#include "code32.h"

#pragma thumb off
void GX_VRAMCNT_SetLCDC_(u32 mask) {
    if (mask & (0x1 << 0))
        reg_GX_VRAMCNT_A = 0x80;
    if (mask & (0x1 << 1))
        reg_GX_VRAMCNT_B = 0x80;
    if (mask & (0x1 << 2))
        reg_GX_VRAMCNT_C = 0x80;
    if (mask & (0x1 << 3))
        reg_GX_VRAMCNT_D = 0x80;
    if (mask & (0x1 << 4))
        reg_GX_VRAMCNT_E = 0x80;
    if (mask & (0x1 << 5))
        reg_GX_VRAMCNT_F = 0x80;
    if (mask & (0x1 << 6))
        reg_GX_VRAMCNT_G = 0x80;
    if (mask & (0x1 << 7))
        reg_GX_VRAMCNT_H = 0x80;
    if (mask & (0x1 << 8))
        reg_GX_VRAMCNT_I = 0x80;
}
