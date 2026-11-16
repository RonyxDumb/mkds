#pragma once

#include "types.h"

void ClearSaveDataSection_Header_from_thumb(s32 copyOwnerName);
BOOL IsSlotGhostBitSet(u32 bitIndex);
void ClearCourseGhostBit(s32 bitIndex);
BOOL MaybeHasPersonalGhostForCourse_from_thumb(u8 bitIndex);
void ClearBitArrayBit(s32 bitIndex, u8 *bytes, s32 unused);
BOOL IsBitArrayBitSet(s32 bitIndex, u8 *bytes, s32 unused);
void MaybeSetPersonalGhostForCoursePresent_from_thumb(s32 bitIndex, u8 *bytes, s32 unused);
