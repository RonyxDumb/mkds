/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define NNSi_objSizeWTbl SDK_data_021530d0
#define NNSi_objSizeHTbl SDK_data_021530b8
#define NNS_G2dMakeCellToOams MaybeMakeOamSlot

#include <nitro.h>

#include <nnsys/g2d/g2d_CellAnimation.h>
#include <nnsys/g2d/g2d_SRTControl.h>
#include <nnsys/g2d/load/g2d_NCE_load.h>
#include <nnsys/g2d/fmt/g2d_Oam_data.h>

#include "g2d_Internal.h"

#pragma thumb off
u16 NNS_G2dMakeCellToOams (GXOamAttr * pDstOams, u16 numDstOam, const NNSG2dCellData * pCell, const MtxFx22 * pMtxSR, const NNSG2dFVec2 * pBaseTrans, u16 affineIndex, BOOL bDoubleAffine)
{
    u16 i = 0;
    NNSG2dFVec2 objTrans;
    GXOamAttr * pDstOam = NULL;
    const u16 numOBJ
        = (numDstOam < pCell->numOAMAttrs) ? numDstOam : pCell->numOAMAttrs;

    for (i = 0; i < numOBJ; i++) {
        pDstOam = &pDstOams[i];

        NNS_G2dCopyCellAsOamAttr(pCell, i, pDstOam);

        if ( pMtxSR != NULL || pBaseTrans != NULL ) {
            NNS_G2dGetOamTransFx32(pDstOam, &objTrans);
            if ( pMtxSR != NULL ) {
                NNSi_G2dRemovePositionAdjustmentFromDoubleAffineOBJ(pDstOam, &objTrans);
                {
                    const GXOamEffect effectTypeAfter = (bDoubleAffine) ?
                                                        GX_OAM_EFFECT_AFFINE_DOUBLE : GX_OAM_EFFECT_AFFINE;
                    const BOOL bShouldAdjust = (effectTypeAfter  == GX_OAM_EFFECT_AFFINE_DOUBLE);

                    MulMtx22(pMtxSR, &objTrans, &objTrans);

                    G2_SetOBJEffect(pDstOam, effectTypeAfter, affineIndex);

                    NNSi_G2dAdjustDifferenceOfRotateOrientation(pDstOam,
                                                                pMtxSR,
                                                                &objTrans,
                                                                bShouldAdjust);
                }
            }

            if ( pBaseTrans != NULL ) {
                objTrans.x += pBaseTrans->x;
                objTrans.y += pBaseTrans->y;
            }

            G2_SetOBJPosition(pDstOam,
                              (objTrans.x + 0x800) >> FX32_SHIFT,
                              (objTrans.y + 0x800) >> FX32_SHIFT);
        }
    }
    return numOBJ;
}
