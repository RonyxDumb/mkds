#include "Main/System/frm_heap_reset.h"
#include "Main/Unknown/unk_02175000.h"
#include "frameheap.h"

void ResetFrmHeap(void) {
    NNS_FndFreeToFrmHeap(gStartupWork->mHeap, 3);
}
