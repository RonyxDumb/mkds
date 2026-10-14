/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define texmtxCalc_flag_ func_01ff9828
#include <nnsys/g3d/cgtool/maya.h>
#include <nnsys/g3d/kernel.h>
#include <nnsys/g3d/gecom.h>
#include <nnsys/g3d/sbc.h>
#include <nnsys/g3d/util.h>

#include <nitro/code32.h>
#include <nitro/codereset.h>

#pragma thumb off
void texmtxCalc_flag_ (MtxFx44 * m, const NNSG3dMatAnmResult * anm)
{
    fx32 ss_sin, ss_cos;
    fx32 st_sin, st_cos;
    fx32 tmpW, tmpH;

    tmpW = (s32)anm->origWidth << FX32_SHIFT;
    tmpH = (s32)anm->origHeight << FX32_SHIFT;
    FX_DivAsync(tmpH, tmpW);

    ss_sin = (fx32)((fx64)anm->scaleS * anm->sinR >> FX32_SHIFT);
    ss_cos = (fx32)((fx64)anm->scaleS * anm->cosR >> FX32_SHIFT);
    st_sin = (fx32)((fx64)anm->scaleT * anm->sinR >> FX32_SHIFT);
    st_cos = (fx32)((fx64)anm->scaleT * anm->cosR >> FX32_SHIFT);

    m->_00 = ss_cos;
    m->_11 = st_cos;

    m->_01 = -st_sin * FX_GetDivResult() >> FX32_SHIFT;
    FX_DivAsync(tmpW, tmpH);

    m->_30 = ((-ss_sin - ss_cos + anm->scaleS) * anm->origWidth << 3) -
             (fx32)((fx64)anm->scaleS * anm->transS >> (FX32_SHIFT - 4)) * anm->origWidth;

    m->_31 = ((st_sin - st_cos - anm->scaleT + FX32_ONE * 2) * anm->origHeight << 3) +
             (fx32)((fx64)anm->scaleT * anm->transT >> (FX32_SHIFT - 4)) * anm->origHeight;

    m->_10 = ss_sin * FX_GetDivResult() >> FX32_SHIFT;
}
