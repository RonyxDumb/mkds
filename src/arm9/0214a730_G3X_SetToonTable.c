/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define MIi_CpuCopy16 SDK_data_0214cffc
#include <nitro/gx/g3x.h>
#include <nitro/gx/g3imm.h>
#include <nitro/gx/gx.h>
#include <nitro/gx/gx_bgcnt.h>
#include <nitro/hw/ARM9/ioreg_GX.h>
#include <nitro/hw/ARM9/ioreg_G3.h>
#include <nitro/hw/ARM9/ioreg_G2.h>
#include <nitro/fx/fx_const.h>
#include <nitro/mi/dma.h>
#include <nitro/mi/memory.h>

#include "gxasm.h"

#include <nitro/code32.h>

#include <nitro/codereset.h>

#pragma thumb off
void G3X_SetToonTable (const GXRgb *rgb_32)
{
	SDK_NULL_ASSERT(rgb_32);
	MI_CpuCopy16(rgb_32, (void *)REG_TOON_TABLE_0_L_ADDR, 64);
}
