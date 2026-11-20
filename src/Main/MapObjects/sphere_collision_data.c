#include "Main/MapObjects/sphere_collision_data.h"
#include "Main/MapObjects/rock.h"

const u16 gCollisionSlotRadiusFlag = COLLISION_SLOT_FLAG_RADIUS_CHANGED;
const u32 gSphereHitBitsMaskedFlag = 0x100;
const u16 gCollisionSlotDisabledFlag = COLLISION_SLOT_FLAG_DISABLED;
const u32 gSphereHitBitsFlag = 0x80000000;
const u32 gSphereHitObjectBitsFlag = 0x40000000;
const u32 gSphereHitTriangleBitsFlag = 0x2000000;

CollisionHitRecord gFirstHitRecordInitial = {{0, 0, 0}, {0, 0, 0}, -1, {0, 0, 0}};
CollisionHitRecord gSecondHitRecordInitial = {{0, 0, 0}, {0, 0, 0}, -1, {0, 0, 0}};
