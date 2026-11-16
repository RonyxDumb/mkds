#pragma once

#include "types.h"

typedef struct HeapCall HeapCall;

void *ExecutionContext_GetHeapHandle(HeapCall *call);
void *GetActiveExecutionContext(void);
u32 ExecutionContext_Execute(HeapCall *call, u32 argument);

// A function run with a heap of its own; mParent is the call that was running before it.
typedef struct HeapCall {
    /* 00 */ const char *mName;
    /* 04 */ u32 mFunc;
    /* 08 */ u32 mAfterFunc;
    /* 0c */ void *mHeap;
    /* 10 */ struct HeapCall *mParent;
} HeapCall;

void ExecutionContext_SetFunction(HeapCall *call, u32 func);
void ExecutionContext_Create(HeapCall *call, u32 func);

extern HeapCall *g_ActiveExecutionContext;
