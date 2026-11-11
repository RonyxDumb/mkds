#pragma once

#include "types.h"

s32 CPSi_big_compare(const u16 *first, const u16 *second, s32 digitCount);
void CPSi_big_sub_small(u16 *result, const u16 *value, u32 borrow, s32 digitCount);
void CPSi_big_sub(u16 *difference, const u16 *minuend, const u16 *subtrahend, s32 digitCount);
void CPSi_big_negate(u16 *digits, s32 digitCount);
void CPSi_big_add_small(u16 *result, const u16 *value, u32 carry, s32 digitCount);
void CPSi_big_add(u16 *sum, const u16 *first, const u16 *second, s32 digitCount);
s32 CPSi_big_sign(const u16 *digits, s32 digitCount);
