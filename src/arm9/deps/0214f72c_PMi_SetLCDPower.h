#pragma once
/* Function-specific inferred declarations. */
undefined4 PM_SetLCDPower(int param_1,int param_2,int param_3,int param_4);
void PMi_SetLCDPower(int param_1);
#define pcRam0214f748 (*(__typeof__(PM_SetLCDPower) **)(uintptr_t)0x214f748u)
