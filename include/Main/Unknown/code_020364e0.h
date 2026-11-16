#pragma once

#include "types.h"

typedef struct HeapCall HeapCall;

void *proc_getHeap(HeapCall *call);
void *proc_getCurrent(void);
u32 proc_run(HeapCall *call, u32 argument);
