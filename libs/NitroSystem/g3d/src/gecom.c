#include "gecom.h"
#include "data_02173000.h"
#include "gfd_LinkedListPlttVramMan.h"
#include "mic.h"
#include "gfd_LinkedListTexVramMan.h"

BOOL NNS_G3dFlagUseFastDma;
GxCommandBuffer *NNS_G3dGeBuffer;
vu32 NNS_G3dFlagGXDmaAsync;

// Selects the fast DMA transfer for display lists when set.
void NNS_G3dGeUseFastDma(BOOL enabled) {
    NNS_G3dFlagUseFastDma = enabled;
}
