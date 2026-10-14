/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define NNSi_G3dGetTexPatAnmFV func_02013b3c
#define NNSi_G3dGetTexPatAnmTexNameByIdx func_02013bcc
#define SetTexParamaters_ func_02015c7c
#define NNSi_G3dGetTexPatAnmPlttNameByIdx func_02013bbc
#define SetPlttParamaters_ func_02015c24
#define NNSi_G3dAnmCalcNsBtp Anim_UnkFnPtr_BTP
#include <nnsys/g3d/anm/nsbtp.h>
#include <nnsys/g3d/binres/res_struct_accessor.h>
extern void SetTexParamaters_ (const NNSG3dResTex * pTex, const NNSG3dResName * pTexName, NNSG3dMatAnmResult * pResult);
extern void SetPlttParamaters_ (const NNSG3dResTex * pTex, const NNSG3dResName * pPlttName, NNSG3dMatAnmResult * pResult);
#pragma thumb off
void NNSi_G3dAnmCalcNsBtp (NNSG3dMatAnmResult * pResult, const NNSG3dAnmObj * pAnmObj, u32 dataIdx)
{
    NNS_G3D_NULL_ASSERT(pResult);
    NNS_G3D_NULL_ASSERT(pAnmObj);
    NNS_G3D_NULL_ASSERT(pAnmObj->resTex);

    {

        const NNSG3dResTexPatAnm * pPatAnm
            = (const NNSG3dResTexPatAnm *)pAnmObj->resAnm;

        const NNSG3dResTexPatAnmFV * pTexFV
            = NNSi_G3dGetTexPatAnmFV(pPatAnm,
                                     (u16)dataIdx,
                                     (u16)FX_Whole(pAnmObj->frame));
        NNS_G3D_NULL_ASSERT(pTexFV);

        SetTexParamaters_(pAnmObj->resTex,
                          NNSi_G3dGetTexPatAnmTexNameByIdx(pPatAnm, pTexFV->idTex),
                          pResult);

        if (pTexFV->idPltt != 255) {
            SetPlttParamaters_(pAnmObj->resTex,
                               NNSi_G3dGetTexPatAnmPlttNameByIdx(pPatAnm, pTexFV->idPltt),
                               pResult);
        }
    }
}
