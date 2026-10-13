#pragma once
/* Function-specific inferred declarations. */
void Mem_FinalizeHeapHead(undefined4 param_1);
void Mem_Frame_Finalize(void);
#define pcRam020180dc (*(__typeof__(Mem_FinalizeHeapHead) **)(uintptr_t)0x20180dcu)
