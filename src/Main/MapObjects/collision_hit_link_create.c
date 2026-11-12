#include "Main/MapObjects/collision_hit_link_create.h"
#include "Main/System/heap_call.h"
#include "Main/System/heap.h"
#include "Main/Unknown/code_020e01f0.h"

void CreateCollisionHitLink(CollisionHitLink **slotPointer) {
    *slotPointer = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x1c);
    (*slotPointer)->mObject = NULL;
}
