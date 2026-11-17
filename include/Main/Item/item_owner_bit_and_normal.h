#pragma once

#include "types.h"

extern const u16 gItemObjectOwnerExcludedBit;
// Declared without const here but defined const in item_owner_bit_and_normal.c; StartCourseMapItemObjects copies it
// into normal when the ground test finds no surface.
extern Vec3 gCourseMapItemVec3UnitY;
