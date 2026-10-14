/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define NNS_G2dFindBinaryBlock Common_FindBlockByMagic
#include <nnsys/g2d/g2d_Load.h>

#include "g2di_Debug.h"

#pragma thumb off
NNSG2dBinaryBlockHeader * NNS_G2dFindBinaryBlock (NNSG2dBinaryFileHeader * pBinFileHeader, u32 signature)
{
    NNS_G2D_NULL_ASSERT(pBinFileHeader);

    {
        NNSG2dBinaryBlockHeader * pCursor = (NNSG2dBinaryBlockHeader *)((u32)pBinFileHeader + (u32)pBinFileHeader->headerSize);

        u16 count = 0;
        while (count < pBinFileHeader->dataBlocks) {
            NNS_G2D_NULL_ASSERT(pCursor);

            NNSI_G2D_DEBUGMSG0("pCursor->kind = %d\n", pCursor->kind);
            NNSI_G2D_DEBUGMSG0("signature = %d\n", signature);

            if (pCursor->kind == signature) {
                return pCursor;
            }
            pCursor = (NNSG2dBinaryBlockHeader *)((u32)pCursor + pCursor->size);
            count++;
        }
    }

    return NULL;
}
