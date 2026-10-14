/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define FX_InvFx64c FX_Inv64
#include <nitro/fx/fx_cp.h>
#include <nitro/cp/divider.h>
#include <nitro/cp/sqrt.h>
extern void FX_InvAsync (fx32 denom);
#pragma thumb off
fx64c FX_InvFx64c (fx32 denom)
{
	FX_InvAsync(denom);
	return (fx64c)CP_GetDivResult64();
}
