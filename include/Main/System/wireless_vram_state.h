#pragma once

#include "types.h"
#include "Main/Scene/scene_display_archive_work.h"

void InitializeGlobalHN(void);
// Writes the cross product of a and b to axb (12 fractional bits); each component is shifted right by 12 without the
// rounding term that VecFx32_CrossProduct adds. axb may be a or b.
void Vector3_Cross(const Vec3 *lhs, const Vec3 *rhs, Vec3 *axb);
// Returns the dot product of a and b (fixed point with 12 fractional bits), shifted right by 12 without the rounding
// term that Vector3_DotProduct adds.
s32 VecFx32_CrossProduct_0(const Vec3 *lhs, const Vec3 *rhs);
// Writes the vector v scaled to length 0x1000 to dst with the hardware divider and square root and returns the length
// of v. It does not test for a zero vector (many callers test the squared length against 16 first);
// Vec3NormalizeAndGetLengthOrZero does. dst may be v.
s32 Vector3_MaybeNormalize(const Vec3 *vec, Vec3 *dst);
void MaybeInitializeSomeWirelessShit(void);
void SomeVramConfig(void);
void WvrCallback(u32 state, s32 errorCode);
void ResetSomeVram(void);
void SetBankForARM7ByState(u32 bank);
void MaybePrepareVram(void);
void SomeVramInit(void);

extern UnreadHalfwordGroups g_GlobalHN;
