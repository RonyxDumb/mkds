#pragma once
/* Function-specific inferred declarations. */
void DC_InvalidateRangeNoClean(uint param_1,int param_2);
void DC_SomeClean(uint param_1,int param_2);
uint GetDtcmStartAddress(void);
void IC_InvalidateRangeNoClean(uint param_1,int param_2);
void MaybeGamecardTransferSY(void);
undefined4 Mem_DcDrainWriteBuffer(void);
longlong Os_DisableIrq(void);
uint Os_EnableIrqHandler(uint param_1);
undefined4 Os_RestoreIrq(void);
void Os_SetIrqHandler(uint param_1,undefined4 param_2);
uint SetIF(undefined4 param_1);
int StructSZ_SomeFn(int param_1);
#define iRam021465ec (*(int *)(uintptr_t)0x21465ecu)
#define uRam021465f0 (*(uint *)(uintptr_t)0x21465f0u)
#define uRam021465f4 (*(uint *)(uintptr_t)0x21465f4u)
#define uRam021465f8 (*(uint *)(uintptr_t)0x21465f8u)
#define uRam021465fc (*(undefined4 *)(uintptr_t)0x21465fcu)
