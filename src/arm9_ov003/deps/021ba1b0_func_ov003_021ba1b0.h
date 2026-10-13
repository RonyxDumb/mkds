#pragma once
/* Function-specific inferred declarations. */
void FUN_021ba734(undefined4 *param_1,uint param_2,undefined4 param_3,int param_4);
void FUN_021ba744(undefined4 *param_1,int param_2);
undefined4 FUN_021ba910(undefined4 param_1,int param_2,undefined4 param_3);
undefined4 FUN_021baaac(undefined1 *param_1,undefined1 *param_2,int param_3,undefined4 param_4);
int FUN_021babc0(int param_1,int param_2);
int func_ov003_021ba1b0(undefined4 *param_1,undefined4 param_2);
#define DAT_021ba36c (*(uint *)(uintptr_t)0x21ba36cu)
#define DAT_021ba370 (*(uint *)(uintptr_t)0x21ba370u)
#define DAT_021ba374 (*(undefined1 **)(uintptr_t)0x21ba374u)
#define DAT_021ba378 (*(undefined4 *)(uintptr_t)0x21ba378u)
#define DAT_021ba37c (*(undefined4 *)(uintptr_t)0x21ba37cu)
#define DAT_021ba380 (*(undefined4 *)(uintptr_t)0x21ba380u)
#define DAT_021ba384 (*(undefined4 *)(uintptr_t)0x21ba384u)
#define DAT_021ba388 (*(uint *)(uintptr_t)0x21ba388u)
#define DAT_021ba38c (*(undefined4 *)(uintptr_t)0x21ba38cu)
#define DAT_021ba390 (*(undefined4 *)(uintptr_t)0x21ba390u)

/* Address resolved to indexed definition; inferred ABI remains provisional. */
void Mem_CpuFill8(uint *param_1,uint param_2,uint param_3);
#define func_0x0214d168 Mem_CpuFill8
void Mem_CpuCopy8(ushort *param_1,uint *param_2,uint param_3);
#define func_0x0214d1fc Mem_CpuCopy8
void Os_Alarm_Create(unsigned int p0);
#define func_0x0200fb08 Os_Alarm_Create
void Os_Alarm_Set(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4, undefined4 param_5);
#define func_0x0200f950 Os_Alarm_Set
undefined4 Os_ReceiveMessage(int param_1,uint *param_2,uint param_3);
#define func_0x0200ea3c Os_ReceiveMessage
void Os_Alarm_Cancel(undefined4 *param_1);
#define func_0x0200f8b8 Os_Alarm_Cancel
