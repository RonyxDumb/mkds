#pragma once
/* Function-specific inferred declarations. */
void FUN_021a5930(void);
undefined4 FUN_021a6470(uint param_1,uint param_2);
void FUN_021a6bdc(void);
#define DAT_021a6530 (*(uint **)(uintptr_t)0x21a6530u)
#define DAT_021a6534 (*(uint *)(uintptr_t)0x21a6534u)
#define DAT_021a6538 (*(int *)(uintptr_t)0x21a6538u)
#define DAT_021a653c (*(int *)(uintptr_t)0x21a653cu)
#define DAT_021a6540 (*(int *)(uintptr_t)0x21a6540u)
#define DAT_021a6544 (*(int *)(uintptr_t)0x21a6544u)
#define DAT_021a6548 (*(int *)(uintptr_t)0x21a6548u)
#define DAT_021a654c (*(int *)(uintptr_t)0x21a654cu)
#define DAT_021a6550 (*(int *)(uintptr_t)0x21a6550u)
#define DAT_021a6554 (*(int *)(uintptr_t)0x21a6554u)

/* Address resolved to indexed definition; inferred ABI remains provisional. */
longlong Os_DisableIrq(void);
#define func_0x0200fca0 Os_DisableIrq
undefined4 Os_RestoreIrq(void);
#define func_0x0200fcb4 Os_RestoreIrq
unsigned int OS_IsTickAvailable(void);
#define func_0x0200f6e4 OS_IsTickAvailable
void Os_InitializeTick(void);
#define func_0x0200f6f4 Os_InitializeTick
unsigned int func_0200fb18(void);
#define func_0x0200fb18 func_0200fb18
void Os_InitializeAlarm(void);
#define func_0x0200fb28 Os_InitializeAlarm
void Os_Alarm_Create(unsigned int p0);
#define func_0x0200fb08 Os_Alarm_Create
