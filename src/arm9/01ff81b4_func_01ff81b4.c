/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define NNS_G3dGeBufferOP_N func_01ff9048
#define NNSi_G3dFuncSbc_POSSCALE func_01ff81b4
#include <nnsys/g3d/sbc.h>
#include <nnsys/g3d/kernel.h>
#include <nnsys/g3d/binres/res_struct.h>
#include <nnsys/g3d/glbstate.h>
#include <nnsys/g3d/gecom.h>
#include <nnsys/g3d/binres/res_struct_accessor.h>
#include <nnsys/g3d/util.h>

#pragma thumb off
void NNSi_G3dFuncSbc_POSSCALE (NNSG3dRS * rs, u32 opt)
{
    VecFx32 s;
    NNS_G3D_NULL_ASSERT(rs);
    NNS_G3D_ASSERT(opt == NNS_G3D_SBCFLG_000 ||
                   opt == NNS_G3D_SBCFLG_001);

    if (!(rs->flag & NNS_G3D_RSFLAG_OPT_NOGECMD) &&
        !(rs->flag & NNS_G3D_RSFLAG_OPT_SKIP_SBCDRAW)) {
        if (opt == NNS_G3D_SBCFLG_000) {
            s.x = s.y = s.z = rs->posScale;
        } else {
            s.x = s.y = s.z = rs->invPosScale;
        }

        NNS_G3dGeBufferOP_N(G3OP_MTX_SCALE,
                            (u32 *)&s.x,
                            G3OP_MTX_SCALE_NPARAMS);
    }

    rs->c += 1;
}
