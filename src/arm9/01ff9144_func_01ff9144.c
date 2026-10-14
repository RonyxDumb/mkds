/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define NNS_G3dGeBufferOP_N func_01ff9048
#define NNS_G3dGeFlushBuffer func_01ff9234
#define MI_SendGXCommandAsyncFast func_0214ccd4
#define MI_SendGXCommandAsync func_0214ced0
#define GXi_DmaId SDK_data_0216f074
#define NNS_G3dFlagUseFastDma SDK_data_0217320c
#define NNS_G3dFlagGXDmaAsync SDK_data_02173208
#define simpleUnlock_ SDK_data_01ff9210
#define NNS_G3dGeSendDL func_01ff9144
#include <nnsys/g3d/gecom.h>
extern void NNS_G3dGeBufferOP_N (u32 op, const u32 * args, u32 num);
extern void NNS_G3dGeFlushBuffer (void);
extern BOOL NNS_G3dFlagUseFastDma;
extern volatile int NNS_G3dFlagGXDmaAsync;
extern void simpleUnlock_ (void * arg);
#pragma thumb off
void NNS_G3dGeSendDL (const void * src, u32 szByte)
{
    NNS_G3D_NULL_ASSERT(src);
    NNS_G3D_ASSERT(szByte >= 4);

    if (szByte < 256 || GX_DMAID == GX_DMA_NOT_USE) {
        NNS_G3dGeBufferOP_N(*(const u32 *)src,
                            (const u32 *)src + 1,
                            (szByte >> 2) - 1);
    } else {
        NNS_G3dGeFlushBuffer();
        NNS_G3dFlagGXDmaAsync = 1;

        if (NNS_G3dFlagUseFastDma) {
            MI_SendGXCommandAsyncFast(GX_DMAID,
                                      src,
                                      szByte,
                                      &simpleUnlock_,
                                      (void *)&NNS_G3dFlagGXDmaAsync);
        } else {
            MI_SendGXCommandAsync(GX_DMAID,
                                  src,
                                  szByte,
                                  &simpleUnlock_,
                                  (void *)&NNS_G3dFlagGXDmaAsync);
        }
    }
}
