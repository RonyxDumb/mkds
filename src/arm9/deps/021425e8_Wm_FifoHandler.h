#pragma once
/* Function-specific inferred declarations. */
void CopyMemory16(int param_1,int param_2,int param_3);
void DC_InvalidateRangeNoClean(uint param_1,int param_2);
void DC_SomeClean(uint param_1,int param_2);
void Mem_CpuCopy8(ushort *param_1,uint *param_2,uint param_3);
void Mem_CpuFill16(undefined2 param_1,int param_2,int param_3);
void Os_Terminate(void);
void Wm_DisableCallbackControl(void);
void Wm_FifoHandler(undefined4 param_1,ushort *param_2,int param_3);
int func_02142c24(void);
#define iRam02142970 (*(int *)(uintptr_t)0x2142970u)
#define psRam02142974 (*(short **)(uintptr_t)0x2142974u)
#define puRam02142978 (*(undefined2 **)(uintptr_t)0x2142978u)
#define uRam0214296c (*(uint *)(uintptr_t)0x214296cu)
#define uRam0214297c (*(undefined4 *)(uintptr_t)0x214297cu)
#define uRam02142980 (*(undefined4 *)(uintptr_t)0x2142980u)
#define uRam02142984 (*(undefined4 *)(uintptr_t)0x2142984u)
