#pragma once
#include "types.h"

// Colour masks the material loader picks by the 3-bit colour field of a material.
extern const u32 matColorMask_[8];

// The three axis indices that follow each pivot index (the nine rotations built from a pivot and two values).
extern const u8 pivotUtil_[9][4];
