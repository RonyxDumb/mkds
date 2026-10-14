/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define NNSi_G3dFuncSbc_RET func_01ff8c98
#include <nnsys/g3d/sbc.h>
#include <nnsys/g3d/kernel.h>
#include <nnsys/g3d/binres/res_struct.h>
#include <nnsys/g3d/glbstate.h>
#include <nnsys/g3d/gecom.h>
#include <nnsys/g3d/binres/res_struct_accessor.h>
#include <nnsys/g3d/util.h>

#pragma thumb off
void NNSi_G3dFuncSbc_RET (NNSG3dRS * rs, u32)
{
    NNS_G3D_NULL_ASSERT(rs);

#if !defined(NNS_G3D_SBC_CALLBACK_TIMING_A_DISABLE) || \
    !defined(NNS_G3D_SBC_CALLBACK_TIMING_B_DISABLE) || \
    !defined(NNS_G3D_SBC_CALLBACK_TIMING_C_DISABLE)

    if (rs->cbVecFunc[NNS_G3D_SBC_RET]) {
        (*rs->cbVecFunc[NNS_G3D_SBC_RET])(rs);
    }
#endif

    rs->flag |= NNS_G3D_RSFLAG_RETURN;
}
