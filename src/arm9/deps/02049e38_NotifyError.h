#pragma once
/* Function-specific inferred declarations. */
void Bright_FadeOutBlack(short param_1);
undefined4 Bright_IsBothScreensFadedOut(void);
void Bright_ResetBlackBothScreens(void);
void LoopFn_Brightness(void);
void LoopFn_DisplayConfig(void);
void LoopFn_Some3D(void);
void LoopFn_Sound(void);
void NotifyError(undefined4 param_1);
void SetBrightness(ushort *param_1,int param_2);
void func_02049f60(void);
void func_0204ac10(void);
void func_02105fcc(void);
#define DAT_02049f4c (*(uint *)(uintptr_t)0x2049f4cu)
#define DAT_02049f50 (*(short **)(uintptr_t)0x2049f50u)
#define DAT_02049f54 (*(uint *)(uintptr_t)0x2049f54u)
#define DAT_02049f58 (*(uint *)(uintptr_t)0x2049f58u)
#define DAT_02049f5c (*(undefined4 *)(uintptr_t)0x2049f5cu)
