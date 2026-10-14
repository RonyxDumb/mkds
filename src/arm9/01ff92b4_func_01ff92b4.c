/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define NNS_G3dGeFlushBuffer func_01ff9234
#define NNS_G3dGeBuffer SDK_data_02173204
#define NNS_G3dGeReleaseBuffer func_01ff92b4
#include <nnsys/g3d/gecom.h>
extern void NNS_G3dGeFlushBuffer (void);
extern NNSG3dGeBuffer * NNS_G3dGeBuffer;
#pragma thumb off
NNSG3dGeBuffer * NNS_G3dGeReleaseBuffer (void)
{
    NNSG3dGeBuffer * p;

    NNS_G3dGeFlushBuffer();

    p = NNS_G3dGeBuffer;
    NNS_G3dGeBuffer = NULL;

    return p;
}
