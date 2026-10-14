/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define texmtxCalc_flagS_ func_01ff974c
#include <nnsys/g3d/cgtool/maya.h>
#include <nnsys/g3d/kernel.h>
#include <nnsys/g3d/gecom.h>
#include <nnsys/g3d/sbc.h>
#include <nnsys/g3d/util.h>

#include <nitro/code32.h>
#include <nitro/codereset.h>

#pragma thumb off
void texmtxCalc_flagS_ (MtxFx44 * m, const NNSG3dMatAnmResult * anm)
{
    fx32 tmpW, tmpH;

    tmpW = (s32)anm->origWidth << FX32_SHIFT;
    tmpH = (s32)anm->origHeight << FX32_SHIFT;
    FX_DivAsync(tmpH, tmpW);

    m->_00 = anm->cosR;
    m->_11 = anm->cosR;

    m->_01 = -anm->sinR * FX_GetDivResult() >> FX32_SHIFT;
    FX_DivAsync(tmpW, tmpH);

    m->_30 = ((-anm->sinR - anm->cosR + FX32_ONE) * anm->origWidth << 3) -
             (anm->transS * anm->origWidth << 4);

    m->_31 = ((anm->sinR - anm->cosR + FX32_ONE) * anm->origHeight << 3) +
             (anm->transT * anm->origHeight << 4);

    m->_10 = anm->sinR * FX_GetDivResult() >> FX32_SHIFT;
}
