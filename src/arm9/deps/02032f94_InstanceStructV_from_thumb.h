#pragma once
/* Function-specific inferred declarations. */
void CopyBgData_Bg3_Bottom(undefined4 param_1,int param_2,uint param_3);
void CopyBgData_Bg3_Top(undefined4 param_1,int param_2,uint param_3);
void CopyPaletteBottom(undefined4 param_1,int param_2,uint param_3);
void CopyPaletteTop(undefined4 param_1,int param_2,uint param_3);
int CreateDisplayConfig(undefined4 param_1,undefined4 param_2);
void DisplayEngineConfig_SetBg0Config(undefined2 *param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,undefined2 param_5,undefined2 param_6,undefined2 param_7,undefined2 param_8);
void DisplayEngineConfig_SetBg1Config(int param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,undefined2 param_5,undefined2 param_6,undefined2 param_7,undefined2 param_8);
void DisplayEngineConfig_SetBg2Config2(int param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,undefined2 param_5,undefined2 param_6,undefined2 param_7);
void DisplayEngineConfig_SetBg3Config(int param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,undefined2 param_5,undefined2 param_6,undefined2 param_7);
void FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(undefined4 param_1);
void FormatRacerNameString_from_thumb(undefined4 param_1,int param_2,int param_3);
undefined4 GetLoadedFont_from_thumb(int param_1);
undefined4 GetPortraitShyGuyPalette_from_thumb(int param_1);
uint GetSomeLUMaxIndex(void);
void InitializeNavigationContext_from_thumb(undefined4 param_1,int *param_2);
void InstanceStructV_from_thumb(undefined4 param_1,undefined4 param_2,undefined4 param_3);
void LoadCupTrophyModel(int param_1,uint param_2);
void LoadPlayerGfxData_from_thumb(undefined4 param_1,undefined4 *param_2);
void MaybeReadScreenBlock_0(int *param_1,int param_2);
undefined4 Mem_AllocateHeap(uint param_1,undefined4 param_2);
void Mem_CpuFastMemorySet(undefined4 param_1,undefined4 *param_2,uint param_3);
void Mem_CpuFill16(undefined2 param_1,int param_2,int param_3);
void PlayerGfxData_Create_from_thumb(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7,code *param_8);
void PrepareNavigationContextFiles_from_thumb(void);
void SetGlobalDisplayConfig(int param_1);
void TEQSub_Fn10Impl_Fn12Impl(undefined4 param_1,int param_2,uint param_3);
void TEQSub_Fn11Impl_Fn13Impl(undefined4 param_1,int param_2,uint param_3);
void TEQSub_Fn27Impl_Fn29Impl(undefined4 param_1,int param_2,uint param_3);
void TEQSub_Fn30Impl(undefined4 param_1,int param_2,uint param_3);
void TEQSub_Fn35Impl(undefined4 param_1,int param_2,uint param_3);
int find_buf_fn_from_thumb(undefined4 param_1);
int func_0201ea30(int param_1,int param_2);
void func_02025884(int param_1,int param_2,int param_3,int param_4,int param_5,code *param_6);
undefined4 func_02025a00(undefined4 param_1,undefined4 param_2,int param_3,short *param_4,undefined4 param_5);
void func_02025a50(int param_1,undefined4 param_2,int *param_3);
void func_020336ec(void);
void func_02033840(void);
void func_020338f8(undefined4 param_1);
void func_02033a0c(undefined4 param_1);
void func_02033ab8(int param_1,uint param_2,undefined4 param_3,int param_4);
void func_02033b80(int param_1);
void func_02033c80(uint param_1);
byte func_02033e24(void);
void func_02033e6c(void);
void func_02062860(void);
void func_020629a4(void);
int func_02122778(int param_1);
void func_02123a48(undefined4 param_1);
void func_0212426c(void);
void func_021249a8(int param_1,int param_2,undefined4 param_3,int param_4);
void func_02124ed0(undefined4 param_1,int param_2,int param_3,undefined4 *param_4);
void func_0212775c(int param_1,undefined4 param_2);
void func_02148ca0(void);
#define DAT_02033350 (*(undefined4 *)(uintptr_t)0x2033350u)
#define DAT_02033354 (*(int **)(uintptr_t)0x2033354u)
#define DAT_02033358 (*(int **)(uintptr_t)0x2033358u)
#define DAT_0203335c (*(undefined4 *)(uintptr_t)0x203335cu)
#define DAT_02033360 (*(undefined4 *)(uintptr_t)0x2033360u)
#define DAT_02033364 (*(int **)(uintptr_t)0x2033364u)
#define DAT_02033368 (*(int *)(uintptr_t)0x2033368u)
#define DAT_0203336c (*(int *)(uintptr_t)0x203336cu)
#define DAT_02033370 (*(undefined4 **)(uintptr_t)0x2033370u)
#define DAT_02033374 (*(int *)(uintptr_t)0x2033374u)
#define DAT_02033378 (*(int *)(uintptr_t)0x2033378u)
#define DAT_0203337c (*(int **)(uintptr_t)0x203337cu)
#define DAT_02033380 (*(int *)(uintptr_t)0x2033380u)
#define DAT_02033384 (*(int *)(uintptr_t)0x2033384u)
#define DAT_02033388 (*(undefined4 *)(uintptr_t)0x2033388u)
#define DAT_0203338c (*(int *)(uintptr_t)0x203338cu)
#define DAT_02033390 (*(int **)(uintptr_t)0x2033390u)
#define DAT_02033394 (*(int *)(uintptr_t)0x2033394u)
#define DAT_02033398 (*(int *)(uintptr_t)0x2033398u)
#define DAT_0203339c (*(int *)(uintptr_t)0x203339cu)
#define DAT_020333a0 (*(undefined4 *)(uintptr_t)0x20333a0u)
#define DAT_020333a4 (*(int *)(uintptr_t)0x20333a4u)
#define DAT_020333a8 (*(int *)(uintptr_t)0x20333a8u)
#define DAT_020333ac (*(int *)(uintptr_t)0x20333acu)
#define DAT_020333b0 (*(int *)(uintptr_t)0x20333b0u)
#define DAT_020333b4 (*(undefined4 *)(uintptr_t)0x20333b4u)
#define DAT_020333b8 (*(int *)(uintptr_t)0x20333b8u)
#define DAT_020333bc (*(int *)(uintptr_t)0x20333bcu)
#define DAT_020333c0 (*(int *)(uintptr_t)0x20333c0u)
#define DAT_020333c4 (*(int *)(uintptr_t)0x20333c4u)
#define DAT_020333c8 (*(int *)(uintptr_t)0x20333c8u)
#define DAT_020336b8 (*(int **)(uintptr_t)0x20336b8u)
#define DAT_020336bc (*(undefined4 *)(uintptr_t)0x20336bcu)
#define DAT_020336c0 (*(undefined4 *)(uintptr_t)0x20336c0u)
#define DAT_020336c4 (*(undefined4 *)(uintptr_t)0x20336c4u)
#define DAT_020336c8 (*(undefined4 *)(uintptr_t)0x20336c8u)
#define DAT_020336cc (*(undefined4 *)(uintptr_t)0x20336ccu)
#define DAT_020336d0 (*(undefined4 *)(uintptr_t)0x20336d0u)
#define DAT_020336d4 (*(undefined4 *)(uintptr_t)0x20336d4u)
#define DAT_020336d8 (*(undefined4 *)(uintptr_t)0x20336d8u)
#define DAT_020336dc (*(undefined4 *)(uintptr_t)0x20336dcu)
#define DAT_020336e0 (*(undefined4 *)(uintptr_t)0x20336e0u)
#define DAT_020336e4 (*(int *)(uintptr_t)0x20336e4u)
#define DAT_020336e8 (*(int **)(uintptr_t)0x20336e8u)
