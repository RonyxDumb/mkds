#pragma once

#include "types.h"

void func_02039774(void);
// Writes the cross product of a and b to axb (12 fractional bits); each component is shifted right by 12 without the
// rounding term that VEC_CrossProduct adds. axb may be a or b.
void vec_crossProduct(const Vec3 *a, const Vec3 *b, Vec3 *axb);
// Returns the dot product of a and b (fixed point with 12 fractional bits), shifted right by 12 without the rounding
// term that VEC_DotProduct adds.
s32 vec_dotProduct(const Vec3 *a, const Vec3 *b);
// Writes the vector v scaled to length 0x1000 to dst with the hardware divider and square root and returns the length
// of v. It does not test for a zero vector (many callers test the squared length against 16 first);
// vec_normalizeFast does. dst may be v.
s32 vec_normalize(const Vec3 *v, Vec3 *dst);
void vram_terminateWifiVram(void);
void vram_startUpWifiVram(void);
void wvrStartupCallback(u32 state, s32 b);
void vram_disableAll(void);
void vram_setBankForARM7(u32 bank);
void vram_clearDisableAll(void);
void vram_initializeWvrStatus(void);
