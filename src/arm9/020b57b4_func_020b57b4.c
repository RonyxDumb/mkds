/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define FX_Mul32x64cFunc func_020b57b4
#include <nitro/fx/fx.h>
#include <nitro/fx/fx_const.h>
#include <nitro/fx/fx_trig.h>

#include <math.h>

#include <nitro/code32.h>

#include <nitro/codereset.h>

#pragma thumb off
fx32 FX_Mul32x64cFunc (fx32 v32, fx64c v64c)
{
	fx64c tmp = v64c * v32 + 0x80000000LL;
	return FX32_CAST(tmp >> FX64C_SHIFT);
}
