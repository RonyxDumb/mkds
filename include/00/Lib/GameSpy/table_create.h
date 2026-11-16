#pragma once

#include "types.h"

void *TableNew(u32 elemSize, u32 nBuckets, void *hashFn, void *compFn, void *freeFn);
