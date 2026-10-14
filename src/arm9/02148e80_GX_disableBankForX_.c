/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OSi_UnlockVram Os_UnlockVram
#define GXi_VRamLockId SDK_data_021802a8
#define disableBankForX_ GX_disableBankForX_
#include "nitro/types.h"
#include "gx.h"
#include "code32.h"
extern u16 GXi_VRamLockId;
#pragma thumb off
u32 disableBankForX_(u16 *ptr){
    u32 temp = *ptr;
    *ptr = 0;
    if (temp & (0x1 << 0))
        reg_GX_VRAMCNT_A = 0x0;
    if (temp & (0x1 << 1))
        reg_GX_VRAMCNT_B = 0x0;
    if (temp & (0x1 << 2))
        reg_GX_VRAMCNT_C = 0x0;
    if (temp & (0x1 << 3))
        reg_GX_VRAMCNT_D = 0x0;
    if (temp & (0x1 << 4))
        reg_GX_VRAMCNT_E = 0x0;
    if (temp & (0x1 << 5))
        reg_GX_VRAMCNT_F = 0x0;
    if (temp & (0x1 << 6))
        reg_GX_VRAMCNT_G = 0x0;
    if (temp & (0x1 << 7))
        reg_GX_VRAMCNT_H = 0x0;
    if (temp & (0x1 << 8))
        reg_GX_VRAMCNT_I = 0x0;
    OSi_UnlockVram((u16)temp, GXi_VRamLockId);
    return temp;
}
