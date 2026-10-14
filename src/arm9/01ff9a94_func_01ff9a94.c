/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define NNS_G3dGeBufferOP_N func_01ff9048
#define NNSi_G3dSendJointSRTMaya func_01ff9a94
#include <nnsys/g3d/cgtool/maya.h>
#include <nnsys/g3d/kernel.h>
#include <nnsys/g3d/gecom.h>
#include <nnsys/g3d/sbc.h>
#include <nnsys/g3d/util.h>

#include <nitro/code32.h>
#include <nitro/codereset.h>

#pragma thumb off
void NNSi_G3dSendJointSRTMaya (const NNSG3dJntAnmResult * result)
{
    BOOL trFlag = FALSE;

    if (!(result->flag & NNS_G3D_JNTANM_RESULTFLAG_TRANS_ZERO)) {
        trFlag = TRUE;
    }

    if ((result->flag & NNS_G3D_JNTANM_RESULTFLAG_MAYA_SSC) &&
        !(result->flag & NNS_G3D_JNTANM_RESULTFLAG_SCALEEX0_ONE)) {
        if (trFlag) {
            NNS_G3dGeBufferOP_N(G3OP_MTX_TRANS,
                                (u32 *)&result->trans.x,
                                G3OP_MTX_TRANS_NPARAMS);
            trFlag = FALSE;
        }
        NNS_G3dGeBufferOP_N(G3OP_MTX_SCALE,
                            (u32 *)&result->scaleEx0.x,
                            G3OP_MTX_SCALE_NPARAMS);
    }

    if (!(result->flag & NNS_G3D_JNTANM_RESULTFLAG_ROT_ZERO)) {
        if (trFlag) {
            NNS_G3dGeBufferOP_N(G3OP_MTX_MULT_4x3,
                                (u32 *)&result->rot._00,
                                G3OP_MTX_MULT_4x3_NPARAMS);
        } else {
            NNS_G3dGeBufferOP_N(G3OP_MTX_MULT_3x3,
                                (u32 *)&result->rot._00,
                                G3OP_MTX_MULT_3x3_NPARAMS);
        }
    } else {
        if (trFlag) {
            NNS_G3dGeBufferOP_N(G3OP_MTX_TRANS,
                                (u32 *)&result->trans.x,
                                G3OP_MTX_TRANS_NPARAMS);
        }
    }

    if (!(result->flag & NNS_G3D_JNTANM_RESULTFLAG_SCALE_ONE)) {
        NNS_G3dGeBufferOP_N(G3OP_MTX_SCALE,
                            (u32 *)&result->scale.x,
                            G3OP_MTX_SCALE_NPARAMS);
    }
}
