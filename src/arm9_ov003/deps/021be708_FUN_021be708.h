#pragma once
/* Function-specific inferred declarations. */
undefined4 FUN_021be708(undefined4 param_1,int param_2,undefined4 param_3);
undefined4 FUN_021be9b8(void);
#define DAT_021be7a8 (*(undefined4 **)(uintptr_t)0x21be7a8u)
#define DAT_021be7ac (*(undefined4 **)(uintptr_t)0x21be7acu)
#define DAT_021be7b0 (*(undefined4 **)(uintptr_t)0x21be7b0u)
#define DAT_021be7b4 (*(int **)(uintptr_t)0x21be7b4u)

/* Address resolved to indexed definition; inferred ABI remains provisional. */
longlong Os_DisableIrq(void);
#define func_0x0200fca0 Os_DisableIrq
void Mem_CpuFill8(uint *param_1,uint param_2,uint param_3);
#define func_0x0214d168 Mem_CpuFill8
void Mem_CpuCopy8(ushort *param_1,uint *param_2,uint param_3);
#define func_0x0214d1fc Mem_CpuCopy8
void Mem_CpuCopy32(undefined4 *param_1,undefined4 *param_2,int param_3);
#define func_0x0214d02c Mem_CpuCopy32
undefined4 Os_RestoreIrq(void);
#define func_0x0200fcb4 Os_RestoreIrq
