/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define NNSi_G3dGetTexPatAnmDataByIdx func_02013b20
#define NNSi_G3dGetTexPatAnmFV func_02013b3c
#include <nnsys/g3d/binres/res_struct_accessor.h>

#include "res_print_internal.h"
extern const NNSG3dResDictTexPatAnmData * NNSi_G3dGetTexPatAnmDataByIdx (const NNSG3dResTexPatAnm * pPatAnm, u32 idx);
#pragma thumb off
const NNSG3dResTexPatAnmFV * NNSi_G3dGetTexPatAnmFV (const NNSG3dResTexPatAnm * pPatAnm, u32 idx, u32 frame)
{
    NNS_G3D_ASSERT(IsValidAnimHeader(&pPatAnm->anmHeader, 'M', 'TP'));
    {
        const NNSG3dResDictTexPatAnmData * pAnmData =
            NNSi_G3dGetTexPatAnmDataByIdx(pPatAnm, idx);
        {

            const NNSG3dResTexPatAnmFV * pfvArray
                = (const NNSG3dResTexPatAnmFV *)((u8 *)pPatAnm + pAnmData->offset);

            const u32 fvIdx = (u32)((fx32)pAnmData->ratioDataFrame * frame >> FX32_SHIFT);
            NNS_G3D_ASSERT(fvIdx < pAnmData->numFV);

            {
                u32 realFvIdx = fvIdx;

                while (realFvIdx > 0 && pfvArray[ realFvIdx ].idxFrame >= frame) {
                    realFvIdx--;
                }

                while (realFvIdx + 1 < pAnmData->numFV && pfvArray[ realFvIdx + 1 ].idxFrame <= frame) {
                    realFvIdx++;
                }
                NNS_G3D_ASSERT(realFvIdx < pAnmData->numFV);

                return &pfvArray[realFvIdx];
            }
        }
    }
}
