/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define VEC_Distance VecFx32_Distance
#include <nitro/fx/fx_vec.h>
#include <nitro/fx/fx_cp.h>
#include <nitro/fx/fx_const.h>
#include <nitro/cp/divider.h>
#include <nitro/cp/sqrt.h>

#include <nitro/code32.h>

#include <nitro/codereset.h>

#pragma thumb off
fx32 VEC_Distance (const VecFx32 *v1, const VecFx32 *v2)
{
	fx64 tmp;
	fx32 diff;

	SDK_NULL_ASSERT(v1);
	SDK_NULL_ASSERT(v2);

	diff = v1->x - v2->x;
	tmp = (fx64)diff * diff;

	diff = v1->y - v2->y;
	tmp += (fx64)diff * diff;

	diff = v1->z - v2->z;
	tmp += (fx64)diff * diff;

	tmp <<= 2;
	CP_SetSqrt64((u64)tmp);

	return ((fx32)CP_GetSqrtResult32() + 1) >> 1;
}
