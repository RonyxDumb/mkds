#pragma once
/* Function-specific inferred declarations. */
undefined4 FUN_021ba560(void);
undefined4 FUN_021ba9c0(void);
#define DAT_021ba60c (*(int **)(uintptr_t)0x21ba60cu)
#define DAT_021ba610 (*(undefined4 *)(uintptr_t)0x21ba610u)
#define DAT_021ba614 (*(undefined4 **)(uintptr_t)0x21ba614u)
#define DAT_021ba618 (*(undefined4 **)(uintptr_t)0x21ba618u)

/* Address resolved to indexed definition; inferred ABI remains provisional. */
undefined4 Os_ReceiveMessage(int param_1,uint *param_2,uint param_3);
#define func_0x0200ea3c Os_ReceiveMessage
longlong Os_DisableIrq(void);
#define func_0x0200fca0 Os_DisableIrq
undefined4 Os_RestoreIrq(void);
#define func_0x0200fcb4 Os_RestoreIrq
