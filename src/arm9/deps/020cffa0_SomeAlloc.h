#pragma once
/* Function-specific inferred declarations. */
uint ExecutionContext_GetHeapHandle(int param_1);
uint GetActiveExecutionContext(void);
undefined4 Mem_AllocateHeap(uint param_1,undefined4 param_2);
void SomeAlloc(void);
#define puRam020cffcc (*(undefined4 **)(uintptr_t)0x20cffccu)
