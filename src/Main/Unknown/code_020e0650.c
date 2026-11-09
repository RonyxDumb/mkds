#include "Main/Unknown/code_020e0650.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020e01f0.h"

void CreateCollisionHitLink(CollisionHitLink **slotPointer) {
    *slotPointer = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x1c);
    (*slotPointer)->mObject = NULL;
}
