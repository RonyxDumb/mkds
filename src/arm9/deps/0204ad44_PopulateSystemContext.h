#pragma once
/* Function-specific inferred declarations. */
void Mem_CpuCopy8(ushort *param_1,uint *param_2,uint param_3);
void Mem_CpuFill8(uint *param_1,uint param_2,uint param_3);
void Os_GetPersonalData(byte *param_1);
undefined8 Os_GetTick(void);
void Pm_GetBacklightStatus(uint *param_1,uint *param_2);
void PopulateSystemContext(void);
void func_02012b20(undefined4 param_1);
bool func_0204aab4(int param_1,int param_2);
#define DAT_0204af5c (*(uint *)(uintptr_t)0x204af5cu)
#define DAT_0204af60 (*(short **)(uintptr_t)0x204af60u)
#define DAT_0204af64 (*(undefined4 *)(uintptr_t)0x204af64u)
#define DAT_0204af68 (*(undefined4 *)(uintptr_t)0x204af68u)
#define DAT_0204af6c (*(undefined4 *)(uintptr_t)0x204af6cu)
