/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define MTX_RotAxis33 func_02146f98
#include <nitro/code32.h>

#include <nitro/fx/fx_mtx33.h>
#include <nitro/fx/fx_const.h>
#include <nitro/fx/fx_cp.h>

#include <nitro/code16.h>

#include <nitro/code32.h>

#include <nitro/code16.h>

#include <nitro/code32.h>
#include <nitro/code16.h>

#include <nitro/code32.h>
#include <nitro/code16.h>

#include <nitro/code32.h>

#include <nitro/codereset.h>

#pragma thumb off
void MTX_RotAxis33 (MtxFx33 *pDst, const VecFx32 *vec, fx32 sinVal, fx32 cosVal)
{
	fx64 t, ss, cc, xx, yy, zz;
	fx32 t01;
	fx32 s2;
	SDK_NULL_ASSERT(pDst);
	SDK_NULL_ASSERT(vec);

	t = (fx64)(FX32_ONE - (fx32)cosVal);
	ss = (fx64)sinVal;
	cc = (fx64)cosVal;
	xx = (fx64)vec->x;
	yy = (fx64)vec->y;
	zz = (fx64)vec->z;

	t01 = (fx32)((xx * xx * t) >> (FX64_SHIFT + FX64_SHIFT));
	pDst->_00 = t01 + cosVal;

	t01 = (fx32)((yy * yy * t) >> (FX64_SHIFT + FX64_SHIFT));
	pDst->_11 = t01 + cosVal;

	t01 = (fx32)((zz * zz * t) >> (FX64_SHIFT + FX64_SHIFT));
	pDst->_22 = t01 + cosVal;

	t01 = (fx32)((t * xx * yy) >> (FX64_SHIFT + FX64_SHIFT));
	s2 = (fx32)((ss * zz) >> FX64_SHIFT);
	pDst->_01 = t01 + s2;
	pDst->_10 = t01 - s2;

	t01 = (fx32)((t * xx * zz) >> (FX64_SHIFT + FX64_SHIFT));
	s2 = (fx32)((ss * yy) >> FX64_SHIFT);
	pDst->_02 = t01 - s2;
	pDst->_20 = t01 + s2;

	t01 = (fx32)((t * yy * zz) >> (FX64_SHIFT + FX64_SHIFT));
	s2 = (fx32)((ss * xx) >> FX64_SHIFT);
	pDst->_12 = t01 + s2;
	pDst->_21 = t01 - s2;
}
