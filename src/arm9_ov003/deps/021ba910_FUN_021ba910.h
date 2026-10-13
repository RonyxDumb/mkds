#pragma once
/* Function-specific inferred declarations. */
undefined4 FUN_021ba910(undefined4 param_1,int param_2,undefined4 param_3);
undefined4 FUN_021bac0c(void);
#define DAT_021ba9b0 (*(undefined4 **)(uintptr_t)0x21ba9b0u)
#define DAT_021ba9b4 (*(undefined4 **)(uintptr_t)0x21ba9b4u)
#define DAT_021ba9b8 (*(undefined4 **)(uintptr_t)0x21ba9b8u)
#define DAT_021ba9bc (*(int **)(uintptr_t)0x21ba9bcu)

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
