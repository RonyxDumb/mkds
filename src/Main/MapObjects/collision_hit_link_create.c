#include "Main/MapObjects/collision_hit_link_create.h"
#include "Main/System/heap_call.h"
#include "Main/System/heap.h"
#include "Main/MapObjects/code_020e01f0.h"

const u16 gCylinderOuterRegionFlag = 0x2000;
const u16 gCylinderInnerRegionFlag = 0x1000;
const Vec3 gCylinderInnerZeroDistanceNormal = {0x1000, 0, 0};
const Vec3 gCylinderOuterZeroDistanceNormal = {0x1000, 0, 0};

void CreateCollisionHitLink(CollisionHitLink **slotPointer) {
    *slotPointer = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x1c);
    (*slotPointer)->mObject = NULL;
}
