#pragma once
/* Function-specific inferred declarations. */
void Mem_CpuFill8(uint *param_1,uint param_2,uint param_3);
void ClearSaveDataSection_TimeTrials_from_thumb(void);
#define pcRam020572c8 (*(__typeof__(Mem_CpuFill8) **)(uintptr_t)0x20572c8u)
#define piRam020572c0 (*(int **)(uintptr_t)0x20572c0u)
#define uRam020572c4 (*(undefined4 *)(uintptr_t)0x20572c4u)
