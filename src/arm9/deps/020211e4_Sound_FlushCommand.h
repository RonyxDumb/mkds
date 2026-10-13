#pragma once
/* Function-specific inferred declarations. */
void Arm_FlushRange(uint param_1,int param_2);
undefined4 Fifo_SendWord(uint param_1,int param_2,uint param_3);
longlong Os_DisableIrq(void);
undefined4 Os_RestoreIrq(void);
void Os_SpinWait(uint param_1);
void SoundInternal_RequestCommandProc(void);
uint Sound_CommandReceiveAndReply(uint param_1);
undefined4 Sound_FlushCommand(uint param_1);
#define iRam02021398 (*(int *)(uintptr_t)0x2021398u)
#define piRam0202138c (*(int **)(uintptr_t)0x202138cu)
#define piRam02021394 (*(int **)(uintptr_t)0x2021394u)
#define piRam0202139c (*(int **)(uintptr_t)0x202139cu)
#define puRam02021388 (*(undefined4 **)(uintptr_t)0x2021388u)
#define puRam020213a0 (*(undefined4 **)(uintptr_t)0x20213a0u)
#define uRam02021390 (*(undefined4 *)(uintptr_t)0x2021390u)
