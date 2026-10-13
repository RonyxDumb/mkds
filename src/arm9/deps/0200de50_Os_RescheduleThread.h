#pragma once
/* Function-specific inferred declarations. */
void Arm_Context_Load(int param_1);
undefined4 Arm_Context_Save(int *param_1,undefined4 param_2,undefined4 param_3,int param_4);
undefined4 Arm_GetProcessorMode(void);
void Os_FindReadyThread(void);
void Os_RescheduleThread(void);
#define puRam0200df30 (*(undefined2 **)(uintptr_t)0x200df30u)
#define uRam0200df2c (*(uint *)(uintptr_t)0x200df2cu)
#define uRam0200df34 (*(uint *)(uintptr_t)0x200df34u)
#define uRam0200df38 (*(uint *)(uintptr_t)0x200df38u)
