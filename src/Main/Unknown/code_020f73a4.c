#include "Main/Unknown/code_020f73a4.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020ee684.h"

void ReleaseItemObjectToItsPool(u32 item) {
    u32 value0 = item;
    u32 itemAddress;
    u32 value2;
    u32 poolsBase;
    u32 value12;
    value2 = ((u32) &it_sItemsets);
    itemAddress = value0;
    poolsBase = *(const u32 *) ((value2) + (0));
    value2 = *(const u32 *) ((itemAddress) + (68));
    value0 = 0x44u;
    value0 = (value2) * (value0) + (poolsBase);
    it_itemsetDestroyItem((ItemPool *) value0, (ItemObject *) itemAddress);
}

u32 CreateItemPushVector(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) proc_getCurrent();
    value0 = (u32) proc_getHeap((void *) value0);
    value1 = 0xcu;
    value0 = (u32) heap_alloc((void *) value0, value1);
    value1 = (u32) &gItemPushVector;
    *(u32 *) ((value1) + (0)) = value0;
    return value0;
}
