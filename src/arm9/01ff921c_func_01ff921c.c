/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define NNS_G3dFlagGXDmaAsync SDK_data_02173208
#define NNS_G3dGeWaitSendDL func_01ff921c
#include <nnsys/g3d/gecom.h>
extern volatile int NNS_G3dFlagGXDmaAsync;
#pragma thumb off
void NNS_G3dGeWaitSendDL (void)
{
    while (NNS_G3dFlagGXDmaAsync)
        ;
}
