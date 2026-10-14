/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define NNSi_GfdInitLnkVramBlockPool func_02016cd8
#include <nnsys/gfd/gfd_common.h>
#include "gfdi_LinkedListVramMan_Common.h"

#pragma thumb off
NNSiGfdLnkVramBlock * NNSi_GfdInitLnkVramBlockPool (NNSiGfdLnkVramBlock * pArrayHead, u32 lengthOfArray)
{
    NNS_GFD_NULL_ASSERT(pArrayHead);
    NNS_GFD_NON_ZERO_ASSERT(lengthOfArray);

    {
        int i;
        for (i = 0; i < lengthOfArray - 1; i++)
        {
            pArrayHead[i].pBlkNext = &pArrayHead[i + 1];
            pArrayHead[i + 1].pBlkPrev = &pArrayHead[i];
        }

        pArrayHead[0].pBlkPrev = NULL;
        pArrayHead[lengthOfArray - 1].pBlkNext = NULL;
    }

    return &pArrayHead[0];
}
