/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define NNSi_G3dAnmCalcNsBva Anim_UnkFnPtr_BVA
#include <nnsys/g3d/anm/nsbva.h>
#include <nnsys/g3d/binres/res_struct_accessor.h>

#pragma thumb off
void NNSi_G3dAnmCalcNsBva (NNSG3dVisAnmResult * pResult, const NNSG3dAnmObj * pAnmObj, u32 dataIdx)
{
    NNS_G3D_NULL_ASSERT(pResult);
    NNS_G3D_NULL_ASSERT(pAnmObj);
    NNS_G3D_NULL_ASSERT(pAnmObj->resAnm);

    {
        u32 frame = (u32)FX_Whole(pAnmObj->frame);
        const NNSG3dResVisAnm * pVisAnm = pAnmObj->resAnm;
        u32 pos = frame * pVisAnm->numNode + dataIdx;
        u32 n = pos >> 5;
        u32 mask = 1U << (pos & 0x1f);

        pResult->isVisible = (BOOL)(pVisAnm->visData[n] & mask);
    }
}
