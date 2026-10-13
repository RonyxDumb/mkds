#pragma once
/* Function-specific inferred declarations. */
void Mem_CpuFill8(uint *param_1,uint param_2,uint param_3);
void ClearSaveDataSection_Emblem_from_thumb(void);
#define pcRam02057300 (*(__typeof__(Mem_CpuFill8) **)(uintptr_t)0x2057300u)
#define piRam020572f8 (*(int **)(uintptr_t)0x20572f8u)
#define uRam020572fc (*(undefined4 *)(uintptr_t)0x20572fcu)
