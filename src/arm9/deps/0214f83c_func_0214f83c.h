#pragma once
/* Function-specific inferred declarations. */
undefined4 MaybeDebuggerOrAddonCode_from_thumb(void);
longlong Os_DisableIrq(void);
void Os_DisableIrqHandler(uint param_1);
undefined4 Os_Halt(void);
undefined4 Os_RestoreIrq(void);
void Os_SpinWait(uint param_1);
bool PM_GetLCDPower(void);
undefined4 PM_SetLCDPower(int param_1,int param_2,int param_3,int param_4);
void Pm_GetBacklightStatus(uint *param_1,uint *param_2);
uint SetIE(undefined4 param_1);
void func_0214f51c(uint param_1);
void func_0214f83c(uint param_1,ushort param_2,ushort param_3);
int func_0214fb54(void);
int func_0214fba8(undefined4 param_1,undefined4 param_2);
int func_0214fc74(undefined4 param_1);
undefined4 func_0214fefc(uint param_1,uint param_2);
#define _DAT_04000000 (*(uint *)(uintptr_t)0x4000000u)
#define psRam0214fa64 (*(short **)(uintptr_t)0x214fa64u)
#define puRam0214fa5c (*(undefined2 **)(uintptr_t)0x214fa5cu)
#define puRam0214fa68 (*(uint **)(uintptr_t)0x214fa68u)
#define uRam0214fa58 (*(uint *)(uintptr_t)0x214fa58u)
#define uRam0214fa60 (*(undefined4 *)(uintptr_t)0x214fa60u)
#define uRam0214fa6c (*(uint *)(uintptr_t)0x214fa6cu)
#define uRam0214fa70 (*(undefined4 *)(uintptr_t)0x214fa70u)
#define uRam0214fa74 (*(uint *)(uintptr_t)0x214fa74u)
#define uRam0214fa78 (*(uint *)(uintptr_t)0x214fa78u)
