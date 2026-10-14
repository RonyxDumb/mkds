/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define CTRDGi_RestoreAccessCycle FUN_03803a44
#include <nitro/ctrdg.h>

#include <../include/ctrdg_work.h>

#include <nitro/os/ARM9/cache.h>

#pragma thumb off
void CTRDGi_RestoreAccessCycle (CTRDGRomCycle *r)
{
	MI_SetCartridgeRomCycle1st(r->c1);
	MI_SetCartridgeRomCycle2nd(r->c2);
}
