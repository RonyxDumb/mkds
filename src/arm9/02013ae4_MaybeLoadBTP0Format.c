/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define NNSi_G3dGetBinaryBlockFromFile SDK_data_02013c18
#define NNS_G3dGetTexPatAnmSet MaybeLoadBTP0Format
#include <nnsys/g3d/binres/res_struct_accessor.h>

#include "res_print_internal.h"
extern const void * NNSi_G3dGetBinaryBlockFromFile (const u8 * pFileHead, u32 fileSignature, u32 blockSignature);
#pragma thumb off
const NNSG3dResTexPatAnmSet * NNS_G3dGetTexPatAnmSet (const u8 * pFileHead)
{
    const void * pVisBlk
        = NNSi_G3dGetBinaryBlockFromFile(pFileHead,
                                         NNS_G3D_SIGNATURE_NSBTP,
                                         NNS_G3D_DATABLK_TEXPAT_ANM);
    NNS_G3D_NULL_ASSERT(pVisBlk);
    return (const NNSG3dResTexPatAnmSet *)pVisBlk;
}
