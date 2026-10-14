/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define GetTexSRTAnm_ func_02015894
#define NNSi_G3dAnmCalcNsBta Anim_UnkFnPtr_BTA
#include <nnsys/g3d/anm/nsbta.h>
#include <nnsys/g3d/binres/res_struct_accessor.h>
extern void GetTexSRTAnm_ (const NNSG3dResTexSRTAnm * pTexAnm, u16 idx, u32 frame, NNSG3dMatAnmResult * pResult);
#pragma thumb off
void NNSi_G3dAnmCalcNsBta (NNSG3dMatAnmResult * pResult, const NNSG3dAnmObj * pAnmObj, u32 dataIdx)
{
    NNS_G3D_NULL_ASSERT(pResult);
    NNS_G3D_NULL_ASSERT(pAnmObj);

    {
        const NNSG3dResTexSRTAnm * pTexAnm
            = (const NNSG3dResTexSRTAnm *)pAnmObj->resAnm;

        GetTexSRTAnm_(pTexAnm,
                      (u16)dataIdx,
                      (u32)FX_Whole(pAnmObj->frame),
                      pResult);

        pResult->prmTexImage &= ~REG_G3_TEXIMAGE_PARAM_TGEN_MASK;
        pResult->prmTexImage |= GX_TEXGEN_TEXCOORD << REG_G3_TEXIMAGE_PARAM_TGEN_SHIFT;

        pResult->flag |= NNS_G3D_MATANM_RESULTFLAG_TEXMTX_SET;

    }
}
