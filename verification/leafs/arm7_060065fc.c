/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define WmspSetVTSF FUN_060065fc
#include "wmsp_private.h"
#include <nitro/wram_begin.h>
#include <nitro/wram_end.h>

#pragma thumb off
void WmspSetVTSF(void)
{
    u16 vcount;
    u32 cur_tsf;
    u16 low0, low1, high;
    u32 v_tsf;

    vcount = (u16)GX_GetVCount();

    low0 = *(vu16 *)MREG_TSF0;
    high = *(vu16 *)MREG_TSF1;
    low1 = *(vu16 *)MREG_TSF0;
    if (low0 > low1) {
        high = *(vu16 *)MREG_TSF1;
    }
    cur_tsf = high;
    cur_tsf <<= 16;
    cur_tsf |= low1;

    v_tsf = cur_tsf;
    v_tsf <<= 1;
    v_tsf -= vcount * 127;
    v_tsf >>= 7;
    v_tsf &= 0x0000ffff;

    *(vu16 *)V_TSF = (u16)v_tsf;

    return;
}
