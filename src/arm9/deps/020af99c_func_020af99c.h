#pragma once
/* Function-specific inferred declarations. */
void Arm_FlushRange(uint param_1,int param_2);
void CopyBgData_Bg0_Bottom(undefined4 param_1,int param_2,uint param_3);
void CopyBgData_Bg2_Top(undefined4 param_1,int param_2,uint param_3);
void CopyPaletteBottom(undefined4 param_1,int param_2,uint param_3);
void CopyPaletteTop(undefined4 param_1,int param_2,uint param_3);
void CopySomePaletteData(undefined4 param_1,int param_2,uint param_3);
void CopyTileDataTop_0(undefined4 param_1,int param_2,uint param_3);
void GXS_EndLoadBGExtPltt(void);
void GX_SetBankForSubBGExtPltt(int param_1);
undefined4 GetChoises_s_b_Pallette_from_thumb(void);
int GetRacePaletteBlock(int param_1);
undefined4 GetSomeBgTileData_from_thumb(void);
void SetDispcntSubBgMode(uint param_1);
void TEQSub_Fn10Impl_Fn12Impl(undefined4 param_1,int param_2,uint param_3);
void TEQSub_Fn24Impl(undefined4 param_1,int param_2,uint param_3);
void TEQSub_Fn25Impl(undefined4 param_1,int param_2,uint param_3);
void TEQSub_Fn26Impl_Fn28Impl(undefined4 param_1,int param_2,uint param_3);
void TEQSub_Fn27Impl_Fn29Impl(undefined4 param_1,int param_2,uint param_3);
void TEQSub_Fn30Impl(undefined4 param_1,int param_2,uint param_3);
void TEQSub_Fn35Impl(undefined4 param_1,int param_2,uint param_3);
void func_020af99c(void);
void func_020b17a4(void);
void func_020b18b0(void);
int func_020b32f8(void);
uint func_020c3e14(int param_1);
void func_020cfca4(void);
void func_0214b468(undefined4 param_1,int param_2,undefined4 param_3);
void func_0214b4dc(void);
#define _DAT_04000000 (*(uint *)(uintptr_t)0x4000000u)
#define _DAT_05000000 (*(ushort *)(uintptr_t)0x5000000u)
#define puRam020afd38 (*(ushort **)(uintptr_t)0x20afd38u)
#define puRam020afd3c (*(undefined2 **)(uintptr_t)0x20afd3cu)
#define puRam020afd44 (*(undefined2 **)(uintptr_t)0x20afd44u)
#define puRam020afd4c (*(undefined2 **)(uintptr_t)0x20afd4cu)
#define puRam020afd50 (*(undefined2 **)(uintptr_t)0x20afd50u)
#define puRam020afd54 (*(ushort **)(uintptr_t)0x20afd54u)
#define puRam020afd58 (*(uint **)(uintptr_t)0x20afd58u)
#define puRam020afd60 (*(undefined4 **)(uintptr_t)0x20afd60u)
#define puRam020afd64 (*(ushort **)(uintptr_t)0x20afd64u)
#define uRam020afd28 (*(uint *)(uintptr_t)0x20afd28u)
#define uRam020afd2c (*(uint *)(uintptr_t)0x20afd2cu)
#define uRam020afd30 (*(undefined4 *)(uintptr_t)0x20afd30u)
#define uRam020afd34 (*(uint *)(uintptr_t)0x20afd34u)
#define uRam020afd40 (*(undefined4 *)(uintptr_t)0x20afd40u)
#define uRam020afd48 (*(undefined4 *)(uintptr_t)0x20afd48u)
#define uRam020afd5c (*(uint *)(uintptr_t)0x20afd5cu)
