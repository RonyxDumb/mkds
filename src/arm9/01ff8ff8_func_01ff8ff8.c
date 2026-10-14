/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define NNS_G3dFuncSbcTable SDK_data_0216196c
#define G3dDrawInternal_Loop_ func_01ff8ff8
#include <nnsys/g3d/sbc.h>
#include <nnsys/g3d/kernel.h>
#include <nnsys/g3d/binres/res_struct.h>
#include <nnsys/g3d/glbstate.h>
#include <nnsys/g3d/gecom.h>
#include <nnsys/g3d/binres/res_struct_accessor.h>
#include <nnsys/g3d/util.h>
extern NNSG3dFuncSbc NNS_G3dFuncSbcTable[NNS_G3D_SBC_COMMAND_NUM];
#pragma thumb off
void G3dDrawInternal_Loop_ (NNSG3dRS * pRS)
{
    do {
        pRS->flag &= ~NNS_G3D_RSFLAG_SKIP;
        NNS_G3D_ASSERTMSG(NNS_G3dFuncSbcTable[NNS_G3D_GET_SBCCMD(*pRS->c)],
                          "SBC command not found / disabled.");

        (*NNS_G3dFuncSbcTable[NNS_G3D_GET_SBCCMD(*pRS->c)])
            (pRS, NNS_G3D_GET_SBCFLG(*pRS->c));
    }
    while (!(pRS->flag & NNS_G3D_RSFLAG_RETURN));
}
