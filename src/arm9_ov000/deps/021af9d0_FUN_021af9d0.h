#pragma once
/* Function-specific inferred declarations. */
void FUN_021af9d0(int param_1,int param_2,undefined4 param_3,int param_4,int param_5,uint param_6);
void FUN_021afaac(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,ushort param_6);
void FUN_021afe84(undefined4 param_1,undefined4 param_2,char *param_3,int param_4,int param_5,int param_6);
undefined4 FUN_021b0094(uint param_1);
void FUN_021b0188(undefined4 param_1,undefined4 param_2);
#define DAT_021afa98 (*(int *)(uintptr_t)0x21afa98u)
#define DAT_021afa9c (*(int **)(uintptr_t)0x21afa9cu)
#define DAT_021afaa0 (*(undefined4 *)(uintptr_t)0x21afaa0u)
#define DAT_021afaa4 (*(undefined4 *)(uintptr_t)0x21afaa4u)
#define DAT_021afaa8 (*(undefined4 *)(uintptr_t)0x21afaa8u)

/* Address resolved to indexed definition; inferred ABI remains provisional. */
void Mem_CpuCopy8(ushort *param_1,uint *param_2,uint param_3);
#define func_0x0214d1fc Mem_CpuCopy8
longlong Os_DisableIrq(void);
#define func_0x0200fca0 Os_DisableIrq
undefined4 Os_RestoreIrq(void);
#define func_0x0200fcb4 Os_RestoreIrq
