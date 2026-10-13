#pragma once
/* Function-specific inferred declarations. */
void Mem_CpuFill8(uint *param_1,uint param_2,uint param_3);
void ClearSaveDataSection_MissionRun_from_thumb(void);
#define pcRam020572ac (*(__typeof__(Mem_CpuFill8) **)(uintptr_t)0x20572acu)
#define piRam020572a4 (*(int **)(uintptr_t)0x20572a4u)
#define uRam020572a8 (*(undefined4 *)(uintptr_t)0x20572a8u)
