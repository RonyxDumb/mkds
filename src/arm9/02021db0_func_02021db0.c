/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define NNS_G2dGetAnimSequenceByIdx func_02021db0
#include <nitro.h>

#include <nnsys/g2d/load/g2d_NAN_load.h>
#include <nnsys/g2d/g2d_Load.h>

#include "g2di_Debug.h"

#pragma thumb off
const NNSG2dAnimSequenceData * NNS_G2dGetAnimSequenceByIdx (const NNSG2dAnimBankData * pAnimBank, u16 idx)
{
    NNS_G2D_NULL_ASSERT(pAnimBank);

    if (NNS_G2dGetNumAnimSequence(pAnimBank) > idx) {
        return &pAnimBank->pSequenceArrayHead[idx];
    } else {
        return NULL;
    }
}
