#pragma once
/* Function-specific inferred declarations. */
void Arm_FlushRange(uint param_1,int param_2);
undefined4 CheckCourseSomeVectorBounds(void);
int ComputeValueInterpolation_from_thumb(int param_1,int param_2,int param_3,int param_4,int param_5);
void CopyBgData_Bg0_Bottom(undefined4 param_1,int param_2,uint param_3);
void CopyBgData_Bg1_Bottom(undefined4 param_1,int param_2,uint param_3);
void CopyBgData_Bg3_Top(undefined4 param_1,int param_2,uint param_3);
void CopyPaletteBottom(undefined4 param_1,int param_2,uint param_3);
void CopyPaletteTop(undefined4 param_1,int param_2,uint param_3);
void CopySomePaletteData(undefined4 param_1,int param_2,uint param_3);
void CopyTileDataTop_0(undefined4 param_1,int param_2,uint param_3);
void CopyToOamA(undefined4 param_1,int param_2,uint param_3);
void CopyToOamB(undefined4 param_1,int param_2,uint param_3);
void G2x_SetBlendAlpha_(uint *param_1,uint param_2,int param_3,uint param_4,int param_5);
uint GetB3F0_Beb1(void);
undefined4 GetChoises_s_b_Pallette_from_thumb(void);
int GetRacePaletteBlock(int param_1);
undefined4 GetSomeBgTileData_from_thumb(void);
undefined4 IsRaceOptionMenuOn_from_thumb(void);
void LoadRaceIntroDataOam(void);
void LoadStaffRollDataOam(void);
undefined4 MaybeCircuitUsesLocal3(void);
void NNSi_MaybeSndPlayerStartSeq(undefined4 param_1,undefined4 param_2,undefined4 param_3);
void SetDispcntSubBgMode(uint param_1);
void TEQSub_Fn10Impl_Fn12Impl(undefined4 param_1,int param_2,uint param_3);
void TEQSub_Fn11Impl_Fn13Impl(undefined4 param_1,int param_2,uint param_3);
void TEQSub_Fn24Impl(undefined4 param_1,int param_2,uint param_3);
void TEQSub_Fn25Impl(undefined4 param_1,int param_2,uint param_3);
void TEQSub_Fn26Impl_Fn28Impl(undefined4 param_1,int param_2,uint param_3);
void TEQSub_Fn27Impl_Fn29Impl(undefined4 param_1,int param_2,uint param_3);
void TEQSub_Fn30Impl(undefined4 param_1,int param_2,uint param_3);
void TEQSub_Fn35Impl(undefined4 param_1,int param_2,uint param_3);
void UpdateBldcntBldalphaBldy(ushort *param_1,ushort param_2,int param_3,ushort param_4,int param_5,int param_6);
void func_020b0b8c(void);
void func_020b17a4(void);
void func_020b18b0(void);
undefined4 func_020b2e98(void);
int func_020b32f8(void);
uint func_020c3e00(void);
uint func_020c3e14(int param_1);
int func_020c3e2c(int param_1);
void func_020cf340(int param_1,undefined4 param_2,uint param_3);
void func_0212b1c0(void);
void func_0214a428(uint *param_1,uint param_2,int param_3,int param_4,int param_5,int param_6);
#define DAT_020b173c (*(uint *)(uintptr_t)0x20b173cu)
#define DAT_020b1740 (*(uint *)(uintptr_t)0x20b1740u)
#define DAT_020b1744 (*(ushort **)(uintptr_t)0x20b1744u)
#define DAT_020b1748 (*(undefined4 *)(uintptr_t)0x20b1748u)
#define DAT_020b174c (*(uint *)(uintptr_t)0x20b174cu)
#define DAT_020b1750 (*(uint **)(uintptr_t)0x20b1750u)
#define DAT_020b1754 (*(int *)(uintptr_t)0x20b1754u)
#define DAT_020b1758 (*(uint **)(uintptr_t)0x20b1758u)
#define DAT_020b175c (*(uint **)(uintptr_t)0x20b175cu)
#define DAT_020b1760 (*(ushort **)(uintptr_t)0x20b1760u)
#define DAT_020b1764 (*(ushort **)(uintptr_t)0x20b1764u)
#define DAT_020b1768 (*(uint *)(uintptr_t)0x20b1768u)
#define DAT_020b176c (*(undefined4 **)(uintptr_t)0x20b176cu)
#define DAT_020b1770 (*(ushort **)(uintptr_t)0x20b1770u)
#define DAT_020b1774 (*(int *)(uintptr_t)0x20b1774u)
#define DAT_020b1778 (*(uint *)(uintptr_t)0x20b1778u)
#define DAT_020b177c (*(uint **)(uintptr_t)0x20b177cu)
#define DAT_020b1780 (*(int *)(uintptr_t)0x20b1780u)
#define DAT_020b1784 (*(undefined4 *)(uintptr_t)0x20b1784u)
#define DAT_020b1788 (*(int *)(uintptr_t)0x20b1788u)
#define DAT_020b178c (*(undefined4 *)(uintptr_t)0x20b178cu)
#define DAT_020b1790 (*(undefined4 **)(uintptr_t)0x20b1790u)
#define DAT_020b1794 (*(ushort **)(uintptr_t)0x20b1794u)
#define DAT_020b1798 (*(uint *)(uintptr_t)0x20b1798u)
#define DAT_020b179c (*(undefined4 *)(uintptr_t)0x20b179cu)
#define DAT_020b17a0 (*(undefined4 *)(uintptr_t)0x20b17a0u)
#define _DAT_04000000 (*(uint *)(uintptr_t)0x4000000u)
#define _DAT_05000000 (*(undefined2 *)(uintptr_t)0x5000000u)
