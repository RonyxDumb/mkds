#include "Main/MapObjects/sphere_collision_data.h"

const u16 gCollisionSlotRadiusFlag = 0x100;
const u32 gSphereHitBitsMaskedFlag = 0x100;
const u16 gCollisionSlotDisabledFlag = 0x200;
const u32 gSphereHitBitsFlag = 0x80000000;
const u32 gSphereHitObjectBitsFlag = 0x40000000;
const u32 gSphereHitTriangleBitsFlag = 0x2000000;

CollisionHitRecord gFirstHitRecordInitial = {{0, 0, 0}, {0, 0, 0}, -1, {0, 0, 0}};
CollisionHitRecord gSecondHitRecordInitial = {{0, 0, 0}, {0, 0, 0}, -1, {0, 0, 0}};
