#pragma once
/* Function-specific inferred declarations. */
undefined4 FUN_02185984(undefined4 param_1,undefined4 param_2,undefined4 param_3,int *param_4,undefined4 param_5,int param_6);
undefined4 FUN_021868a4(int *param_1,undefined4 param_2,undefined4 param_3);
undefined4 FUN_02186b0c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);
undefined4 FUN_02186bd4(int param_1,undefined4 param_2,undefined4 param_3);
void FUN_0218a67c(undefined4 param_1,undefined4 param_2);
int FUN_021a6abc(undefined2 *param_1);
int FUN_021a6b10(void);
#define DAT_02185ccc (*(undefined4 *)(uintptr_t)0x2185cccu)
#define DAT_02185cd0 (*(undefined4 *)(uintptr_t)0x2185cd0u)
#define DAT_02185cd4 (*(undefined4 *)(uintptr_t)0x2185cd4u)
#define DAT_02185cd8 (*(undefined4 *)(uintptr_t)0x2185cd8u)
#define DAT_02185cdc (*(undefined4 *)(uintptr_t)0x2185cdcu)
#define DAT_02185ce0 (*(int **)(uintptr_t)0x2185ce0u)
#define DAT_02185ce4 (*(undefined4 *)(uintptr_t)0x2185ce4u)
#define DAT_02185ce8 (*(undefined4 *)(uintptr_t)0x2185ce8u)
#define DAT_02185cec (*(undefined4 *)(uintptr_t)0x2185cecu)
#define DAT_02185cf0 (*(undefined4 *)(uintptr_t)0x2185cf0u)
#define DAT_02185cf4 (*(undefined4 *)(uintptr_t)0x2185cf4u)
#define DAT_02185cf8 (*(undefined4 *)(uintptr_t)0x2185cf8u)
#define DAT_02185cfc (*(undefined4 *)(uintptr_t)0x2185cfcu)
#define DAT_02185d00 (*(undefined4 *)(uintptr_t)0x2185d00u)
#define DAT_02185d04 (*(undefined4 *)(uintptr_t)0x2185d04u)
#define DAT_02185d08 (*(undefined4 *)(uintptr_t)0x2185d08u)
#define DAT_02185d0c (*(undefined4 *)(uintptr_t)0x2185d0cu)
#define DAT_02185d10 (*(undefined4 *)(uintptr_t)0x2185d10u)
#define DAT_02185d14 (*(undefined4 *)(uintptr_t)0x2185d14u)
#define DAT_02185d18 (*(undefined4 *)(uintptr_t)0x2185d18u)
#define DAT_02185d1c (*(undefined4 *)(uintptr_t)0x2185d1cu)
#define DAT_02185d20 (*(undefined4 *)(uintptr_t)0x2185d20u)
#define DAT_02185d24 (*(undefined4 *)(uintptr_t)0x2185d24u)
#define DAT_02185d28 (*(undefined4 *)(uintptr_t)0x2185d28u)
#define DAT_02185d2c (*(undefined4 *)(uintptr_t)0x2185d2cu)
#define DAT_02185d30 (*(int *)(uintptr_t)0x2185d30u)
#define DAT_02185d34 (*(undefined4 *)(uintptr_t)0x2185d34u)
#define DAT_02185d38 (*(undefined4 *)(uintptr_t)0x2185d38u)
#define DAT_02185d3c (*(undefined4 *)(uintptr_t)0x2185d3cu)
#define DAT_02185d40 (*(undefined4 *)(uintptr_t)0x2185d40u)
#define DAT_02185d44 (*(undefined4 *)(uintptr_t)0x2185d44u)
#define DAT_02185d48 (*(undefined4 *)(uintptr_t)0x2185d48u)
#define DAT_02185d4c (*(undefined4 *)(uintptr_t)0x2185d4cu)
#define DAT_02185d50 (*(undefined4 *)(uintptr_t)0x2185d50u)

/* Address resolved to indexed definition; inferred ABI remains provisional. */
void Os_GetMacAddress(undefined4 param_1);
#define func_0x0200fe58 Os_GetMacAddress
void Os_GetPersonalData(byte *param_1);
#define func_0x0200fddc Os_GetPersonalData
uint Rtc_GetDate(undefined4 param_1);
#define func_0x0214e038 Rtc_GetDate
uint Rtc_GetTime(undefined4 param_1);
#define func_0x0214df78 Rtc_GetTime
longlong Os_DisableIrq(void);
#define func_0x0200fca0 Os_DisableIrq
undefined4 Os_RestoreIrq(void);
#define func_0x0200fcb4 Os_RestoreIrq
void Mem_CpuCopy8(ushort *param_1,uint *param_2,uint param_3);
#define func_0x0214d1fc Mem_CpuCopy8
void Mem_CpuFill8(uint *param_1,uint param_2,uint param_3);
#define func_0x0214d168 Mem_CpuFill8
void MaybeUtil_SPrintF(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);
#define func_0x0200da28 MaybeUtil_SPrintF
void Util_SNPrintF(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);
#define func_0x0200d9e0 Util_SNPrintF
void StructDW_MaybeCreate_from_thumb(undefined4 *param_1);
#define func_0x02151910 StructDW_MaybeCreate_from_thumb
size_t strlen(char *__s);
#define func_0x0213a434 strlen
