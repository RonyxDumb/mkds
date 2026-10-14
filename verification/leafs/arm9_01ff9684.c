/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define texmtxCalc_flagRS_ func_01ff9684
#include <nnsys/g3d/cgtool/maya.h>
#include <nnsys/g3d/kernel.h>
#include <nnsys/g3d/gecom.h>
#include <nnsys/g3d/sbc.h>
#include <nnsys/g3d/util.h>

#include <nitro/code32.h>
#include <nitro/codereset.h>

#pragma thumb off
void texmtxCalc_flagRS_ (MtxFx44 * m, const NNSG3dMatAnmResult * anm)
{
    m->_00 = FX32_ONE;
    m->_11 = FX32_ONE;

    m->_01 = 0;

    m->_30 = -(anm->transS * anm->origWidth) << 4;
    m->_31 = (anm->transT * anm->origHeight) << 4;

    m->_10 = 0;
}
