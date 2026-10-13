#pragma once
/* Function-specific inferred declarations. */
void FUN_021a57fc(int param_1);
#define DAT_021a5858 (*(int **)(uintptr_t)0x21a5858u)
#define DAT_021a585c (*(int *)(uintptr_t)0x21a585cu)
#define DAT_021a5860 (*(int *)(uintptr_t)0x21a5860u)
#define DAT_021a5864 (*(undefined4 *)(uintptr_t)0x21a5864u)
#define DAT_021a5868 (*(undefined4 *)(uintptr_t)0x21a5868u)

/* Address resolved to indexed definition; inferred ABI remains provisional. */
longlong Os_DisableIrq(void);
#define func_0x0200fca0 Os_DisableIrq
void Os_Alarm_Cancel(undefined4 *param_1);
#define func_0x0200f8b8 Os_Alarm_Cancel
void Os_Alarm_Set(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4, undefined4 param_5);
#define func_0x0200f950 Os_Alarm_Set
undefined4 Os_RestoreIrq(void);
#define func_0x0200fcb4 Os_RestoreIrq
