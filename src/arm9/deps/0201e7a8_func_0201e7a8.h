#pragma once
/* Function-specific inferred declarations. */
bool Fifo_IsHandlerReady(uint param_1,int param_2);
void Fifo_RegisterHandler(uint param_1,int param_2);
undefined4 Fifo_SendWord(uint param_1,int param_2,uint param_3);
int Os_AllocateLockId(void);
longlong Os_DisableIrq(void);
undefined4 Os_RestoreIrq(void);
void Os_UnlockVram(uint param_1,uint param_2);
undefined4 func_0200ff04(uint param_1,uint param_2);
undefined4 func_0201e7a8(int param_1,int param_2,undefined4 param_3);
void func_0214d5b8(void);
#define iRam0201ea28 (*(int *)(uintptr_t)0x201ea28u)
#define piRam0201ea14 (*(int **)(uintptr_t)0x201ea14u)
#define psRam0201ea10 (*(short **)(uintptr_t)0x201ea10u)
#define psRam0201ea18 (*(short **)(uintptr_t)0x201ea18u)
#define puRam0201ea1c (*(undefined1 **)(uintptr_t)0x201ea1cu)
#define puRam0201ea20 (*(undefined1 **)(uintptr_t)0x201ea20u)
#define puRam0201ea2c (*(undefined4 **)(uintptr_t)0x201ea2cu)
#define uRam0201ea24 (*(undefined4 *)(uintptr_t)0x201ea24u)
