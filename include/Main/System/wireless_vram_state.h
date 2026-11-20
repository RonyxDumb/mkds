#pragma once

#include "types.h"
#include "Main/Scene/scene_display_archive_work.h"

void InitUnreadHalfwordGroups(void);
// Writes the cross product of lhs and rhs to axb (12 fractional bits); each component is shifted right by 12 without
// the rounding term that VEC_CrossProduct adds. axb may be lhs or rhs.
void Vec3CrossUnrounded(const Vec3 *lhs, const Vec3 *rhs, Vec3 *axb);
// Returns the dot product of lhs and rhs (fixed point with 12 fractional bits), shifted right by 12 without the
// rounding term that VEC_DotProduct adds.
s32 Vec3DotUnrounded(const Vec3 *lhs, const Vec3 *rhs);
// Writes vec scaled to length 0x1000 to dst with the hardware divider and square root and returns the length of vec. It
// does not test the length (many callers test the squared length against 16 first); Vec3NormalizeAndGetLengthOrZero
// returns 0 when the squared length is below 16. dst may be vec.
s32 Vec3NormalizeAndGetLengthUnchecked(const Vec3 *vec, Vec3 *dst);
void StopWvrAndWait(void);
void ClearLcdcBankAndStartWvrAndWait(void);
void WvrCallback(u32 state, s32 errorCode);
void DisableAllBanks(void);
void SetBankForARM7ByState(u32 bank);
void ClearLcdcBanksByState(void);
void InitWvrState(void);

extern UnreadHalfwordGroups gUnreadHalfwordGroups;
