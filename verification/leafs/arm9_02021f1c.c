/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define NNS_G2dGetCellDataByIdx CellBank_GetMetatileEntry
#include <nitro.h>

#include <nnsys/g2d/load/g2d_NCE_load.h>
#include <nnsys/g2d/g2d_Load.h>

#include "g2di_Debug.h"

#pragma thumb off
const NNSG2dCellData * NNS_G2dGetCellDataByIdx (const NNSG2dCellDataBank * pCellData, u16 idx)
{
    NNS_G2D_NULL_ASSERT(pCellData);

    if (idx >= pCellData->numCells) {
        return NULL;
    }

    if (NNSi_G2dCellBankHasBR(pCellData)) {
        const NNSG2dCellDataWithBR * pCellBR =
            (const NNSG2dCellDataWithBR *)(pCellData->pCellDataArrayHead) + idx;
        return &pCellBR->cellData;
    } else {
        return pCellData->pCellDataArrayHead + idx;
    }
}
