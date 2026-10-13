#pragma once
/* Function-specific inferred declarations. */
void FUN_021a57a8(void);
#define DAT_021a57e8 (*(int **)(uintptr_t)0x21a57e8u)
#define DAT_021a57ec (*(int *)(uintptr_t)0x21a57ecu)
#define DAT_021a57f0 (*(int *)(uintptr_t)0x21a57f0u)
#define DAT_021a57f4 (*(undefined4 *)(uintptr_t)0x21a57f4u)
#define DAT_021a57f8 (*(undefined4 *)(uintptr_t)0x21a57f8u)

/* Address resolved to indexed definition; inferred ABI remains provisional. */
longlong Os_DisableIrq(void);
#define func_0x0200fca0 Os_DisableIrq
void Os_Alarm_Cancel(undefined4 *param_1);
#define func_0x0200f8b8 Os_Alarm_Cancel
void Os_Alarm_Set(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4, undefined4 param_5);
#define func_0x0200f950 Os_Alarm_Set
undefined4 Os_RestoreIrq(void);
#define func_0x0200fcb4 Os_RestoreIrq
