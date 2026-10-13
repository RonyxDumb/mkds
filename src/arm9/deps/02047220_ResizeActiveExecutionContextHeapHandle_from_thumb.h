#pragma once
/* Function-specific inferred declarations. */
uint ExecutionContext_GetHeapHandle(int param_1);
uint GetActiveExecutionContext(void);
uint Mem_ResizeExpHeap(int param_1,int param_2,int param_3);
void ResizeActiveExecutionContextHeapHandle_from_thumb(int param_1,int param_2);
#define iRam0204724c (*(int *)(uintptr_t)0x204724cu)
#define piRam02047248 (*(int **)(uintptr_t)0x2047248u)
