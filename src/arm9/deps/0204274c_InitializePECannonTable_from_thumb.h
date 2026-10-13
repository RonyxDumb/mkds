#pragma once
/* Function-specific inferred declarations. */
uint ExecutionContext_GetHeapHandle(int param_1);
uint GetActiveExecutionContext(void);
void InitializePECannonTable_from_thumb(void);
undefined4 Mem_AllocateHeap(uint param_1,undefined4 param_2);
#define piRam020427a8 (*(int **)(uintptr_t)0x20427a8u)
