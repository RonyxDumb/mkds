#include "Main/Unknown/code_020f73a4.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020ee684.h"

void ReleaseItemObjectToItsPool(ItemObject *item) {
    ReleaseItemPoolObject(&gItemPools[item->mKind], item);
}

Vec3 *CreateItemPushVector(void) {
    void *heap = GetHeap(GetCurrentHeapCall());
    gItemPushVector = HeapAlloc(heap, 0xc);
    return gItemPushVector;
}
