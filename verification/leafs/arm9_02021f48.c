/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define GetPtrOamArrayHead_ CellBank_GetObjectTable
#include <nitro.h>

#include <nnsys/g2d/load/g2d_NCE_load.h>
#include <nnsys/g2d/g2d_Load.h>

#include "g2di_Debug.h"

#pragma thumb off
void * GetPtrOamArrayHead_ (NNSG2dCellDataBank * pCellBank)
{
    NNS_G2D_NULL_ASSERT(pCellBank);

    if (NNSi_G2dCellBankHasBR(pCellBank)) {
        return (NNSG2dCellDataWithBR *)(pCellBank->pCellDataArrayHead) + pCellBank->numCells;
    } else {
        return pCellBank->pCellDataArrayHead + pCellBank->numCells;
    }
}
