/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define G3X_ResetMtxStack G3X_ResetMatrixStack2
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
extern int G3X_GetMtxStackLevelPV (s32 *level);
extern int G3X_GetMtxStackLevelPJ (s32 *level);
#pragma thumb off
void G3X_ResetMtxStack (void)
{
	s32 levelPV;
	s32 levelPJ;
#ifdef SDK_DEBUG
	{
		GXPower power = GX_GetPower();
		SDK_WARNING(power & GX_POWER_GE, "GX_POWER_GE is off now, registers for it not changes.");
	}
#endif
	G3X_ResetMtxStackOverflow();

	while (G3X_GetMtxStackLevelPV(&levelPV))
		;

	while (G3X_GetMtxStackLevelPJ(&levelPJ))
		;

	G3_MtxMode(GX_MTXMODE_TEXTURE);
	G3_Identity();
	G3_MtxMode(GX_MTXMODE_PROJECTION);

	if (levelPJ != 0) {
		G3_PopMtx(levelPJ);
	}

	G3_MtxMode(GX_MTXMODE_POSITION_VECTOR);
	G3_PopMtx(levelPV);
	G3_Identity();

}
