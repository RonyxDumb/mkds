/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define getJntSRTAnmResult_ func_02014c5c
#define NNSi_G3dAnmCalcNsBca Anim_UnkFnPtr_BCA
#include <nnsys/g3d/anm/nsbca.h>
#include <nnsys/g3d/sbc.h>
#include <nnsys/g3d/binres/res_struct_accessor.h>

#include <nitro/code32.h>

#include <nitro/codereset.h>
extern void getJntSRTAnmResult_ (const NNSG3dResJntAnm * pJntAnm, u32 dataIdx, fx32 Frame, NNSG3dJntAnmResult * pResult);
#pragma thumb off
void NNSi_G3dAnmCalcNsBca (NNSG3dJntAnmResult * pResult, const NNSG3dAnmObj * pAnmObj, u32 dataIdx)
{
    NNS_G3D_NULL_ASSERT(pResult);
    NNS_G3D_NULL_ASSERT(pAnmObj);

    {
        fx32 frame;
        NNSG3dResJntAnm * anm = (NNSG3dResJntAnm *)(pAnmObj->resAnm);

        if (pAnmObj->frame >= (anm->numFrame << FX32_SHIFT))
            frame = (anm->numFrame << FX32_SHIFT) - 1;
        else if (pAnmObj->frame < 0)
            frame = 0;
        else
            frame = pAnmObj->frame;

        getJntSRTAnmResult_(anm, dataIdx, frame, pResult);
    }
}
