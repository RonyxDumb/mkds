#pragma once

#include "types.h"

void qsort(u8 *siblingPtr, u32 count, u32 size, int (*cmp)(void *, void *));
