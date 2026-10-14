/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define NNSi_G3dGetBinaryBlockFromFile SDK_data_02013c18
#define NNS_G3dGetJntAnmSet Anim_NSBCA_LoadGetJNT0Block
#include <nnsys/g3d/binres/res_struct_accessor.h>

#include "res_print_internal.h"
extern const void * NNSi_G3dGetBinaryBlockFromFile (const u8 * pFileHead, u32 fileSignature, u32 blockSignature);
#pragma thumb off
const NNSG3dResJntAnmSet * NNS_G3dGetJntAnmSet (const u8 * pFileHead)
{
    const void * pVisBlk
        = NNSi_G3dGetBinaryBlockFromFile(pFileHead,
                                         NNS_G3D_SIGNATURE_NSBCA,
                                         NNS_G3D_DATABLK_JNT_ANM);
    NNS_G3D_NULL_ASSERT(pVisBlk);
    return (const NNSG3dResJntAnmSet *)pVisBlk;
}
