/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define CTRDGi_ChangeLatestAccessCycle FUN_03803a78
#include <nitro/ctrdg.h>

#include <../include/ctrdg_work.h>

#include <nitro/os/ARM9/cache.h>

#pragma thumb off
void CTRDGi_ChangeLatestAccessCycle (CTRDGRomCycle *r)
{
	r->c1 = MI_GetCartridgeRomCycle1st();
	r->c2 = MI_GetCartridgeRomCycle2nd();

	MI_SetCartridgeRomCycle1st(MI_CTRDG_ROMCYCLE1_18);
	MI_SetCartridgeRomCycle2nd(MI_CTRDG_ROMCYCLE2_6);
}
