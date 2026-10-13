#pragma once
/* Function-specific inferred declarations. */
void Mem_CpuFill8(uint *param_1,uint param_2,uint param_3);
void ClearSaveDataSection_FriendList_from_thumb(void);
#define pcRam0205725c (*(__typeof__(Mem_CpuFill8) **)(uintptr_t)0x205725cu)
#define piRam02057254 (*(int **)(uintptr_t)0x2057254u)
#define uRam02057258 (*(undefined4 *)(uintptr_t)0x2057258u)
