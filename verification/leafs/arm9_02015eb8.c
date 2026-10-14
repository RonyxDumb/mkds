/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define NNSi_G3dGetJointScaleBasic func_02015eb8
#include <nnsys/g3d/cgtool/basic.h>
#include <nnsys/g3d/gecom.h>
#include <nnsys/g3d/binres/res_struct.h>

#pragma thumb off
void NNSi_G3dGetJointScaleBasic (NNSG3dJntAnmResult * pResult, const fx32 * p, const u8 *, u32 srtflag)
{

    NNS_G3D_NULL_ASSERT(pResult);

    if (srtflag & NNS_G3D_SRTFLAG_SCALE_ONE) {
        pResult->flag |= NNS_G3D_JNTANM_RESULTFLAG_SCALE_ONE;
    } else {
        NNS_G3D_NULL_ASSERT(p);

        pResult->scale.x = *(p + 0);
        pResult->scale.y = *(p + 1);
        pResult->scale.z = *(p + 2);
    }

    pResult->flag |= NNS_G3D_JNTANM_RESULTFLAG_SCALEEX0_ONE |
                     NNS_G3D_JNTANM_RESULTFLAG_SCALEEX1_ONE;
}
