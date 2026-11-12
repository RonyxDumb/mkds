#include "gecom.h"
#include "data_02173000.h"
#include "gfd_LinkedListPlttVramMan.h"
#include "mic.h"
#include "gfd_LinkedListTexVramMan.h"

// Selects the fast DMA transfer for display lists when set.
void NNS_G3dGeUseFastDma(BOOL enabled) {
    NNS_G3dFlagUseFastDma = enabled;
}
