#pragma once

#include "types.h"

u16 *wcschr(const u16 *string, int target);
int wcsncmp(const u16 *first, const u16 *second, u32 count);
u16 *SomeStrcat16(u16 *dst, const u16 *src, u32 count);
u16 *CopyString16(u16 *dst, const u16 *src, u32 count);
u16 *wcscpy(u16 *dst, const u16 *src);
int wcslen(const u16 *string);
