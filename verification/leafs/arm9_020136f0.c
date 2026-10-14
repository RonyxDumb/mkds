/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define NNS_G3dGetTex Nsbtx_GetTEX0Block
#include <nnsys/g3d/binres/res_struct_accessor.h>

#pragma thumb off
NNSG3dResTex * NNS_G3dGetTex (const NNSG3dResFileHeader * header)
{
    u32 * blks;
    NNS_G3D_NULL_ASSERT(header);
    NNS_G3D_ASSERT(header->sigVal == NNS_G3D_SIGNATURE_NSBMD ||
                   header->sigVal == NNS_G3D_SIGNATURE_NSBTX);

    blks = (u32 *)((u8 *)header + header->headerSize);

    if (header->dataBlocks == 1) {
        if (header->sigVal == NNS_G3D_SIGNATURE_NSBTX) {
            return (NNSG3dResTex *)((u8 *)header + blks[0]);
        } else {
            return NULL;
        }
    } else {
        return (NNSG3dResTex *)((u8 *)header + blks[1]);
    }
}
