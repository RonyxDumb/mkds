/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define texmtxCalc_flagTR_ func_01ff9490
#include <nnsys/g3d/cgtool/maya.h>
#include <nnsys/g3d/kernel.h>
#include <nnsys/g3d/gecom.h>
#include <nnsys/g3d/sbc.h>
#include <nnsys/g3d/util.h>

#include <nitro/code32.h>
#include <nitro/codereset.h>

#pragma thumb off
void texmtxCalc_flagTR_ (MtxFx44 * m, const NNSG3dMatAnmResult * anm)
{
    m->_00 = anm->scaleS;
    m->_11 = anm->scaleT;

    m->_01 = 0;

    m->_30 = 0;
    m->_31 = ((-2 * anm->scaleT + FX32_ONE * 2) * anm->origHeight << 3);

    m->_10 = 0;
}
