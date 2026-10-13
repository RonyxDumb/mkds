#pragma once
/* Function-specific inferred declarations. */
uint ExecutionContext_GetHeapHandle(int param_1);
uint GetActiveExecutionContext(void);
undefined4 Mem_AllocateHeap(uint param_1,undefined4 param_2);
void YetAlloc(void);
#define puRam020bc200 (*(undefined4 **)(uintptr_t)0x20bc200u)
#define uRam020bc204 (*(uint *)(uintptr_t)0x20bc204u)
