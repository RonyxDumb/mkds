#pragma once
/* Function-specific inferred declarations. */
undefined4 FUN_021ba61c(int param_1,int param_2);
undefined4 FUN_021ba818(undefined4 param_1,int param_2,int param_3);
#define DAT_021ba6f0 (*(undefined4 *)(uintptr_t)0x21ba6f0u)
#define DAT_021ba6f4 (*(undefined4 *)(uintptr_t)0x21ba6f4u)
#define DAT_021ba6f8 (*(int **)(uintptr_t)0x21ba6f8u)
#define DAT_021ba6fc (*(int **)(uintptr_t)0x21ba6fcu)
#define DAT_021ba700 (*(undefined4 *)(uintptr_t)0x21ba700u)
#define DAT_021ba704 (*(int **)(uintptr_t)0x21ba704u)
#define DAT_021ba708 (*(undefined4 *)(uintptr_t)0x21ba708u)

/* Address resolved to indexed definition; inferred ABI remains provisional. */
void Os_MessageQueue_Initialize(uint *param_1,uint param_2,uint param_3);
#define func_0x0200eb90 Os_MessageQueue_Initialize
longlong Os_DisableIrq(void);
#define func_0x0200fca0 Os_DisableIrq
undefined4 Os_RestoreIrq(void);
#define func_0x0200fcb4 Os_RestoreIrq
undefined4 Os_ReceiveMessage(int param_1,uint *param_2,uint param_3);
#define func_0x0200ea3c Os_ReceiveMessage
