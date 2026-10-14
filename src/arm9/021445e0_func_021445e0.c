/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define MATH_CountPopulation Math_CountPopulation
#define WmGetSharedDataAddress func_021445e0
#include <nitro/wm.h>

#include    "wm_arm9_private.h"

#pragma thumb off
u16 * WmGetSharedDataAddress (WMDataSharingInfo * dsInfo, u32 aidBitmap, u16 * receiveBuf, u32 aid)
{
    u32 mask;
    u32 count;
    u32 offset;

    mask = (0x0001U << aid) - 1U;
    aidBitmap &= mask;
    count = MATH_CountPopulation(aidBitmap);
    offset = dsInfo->dataLength * count;

    return (u16 *)(((u8 *)receiveBuf) + offset);
}
