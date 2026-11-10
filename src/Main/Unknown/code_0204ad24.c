#include "Main/Unknown/code_0204ad24.h"
#include "Main/Unknown/unk_02175000.h"
#include "frameheap.h"

void ResetFrmHeap(void) {
    NNS_FndFreeToFrmHeap(gStartupWork->mHeap, 3);
}
