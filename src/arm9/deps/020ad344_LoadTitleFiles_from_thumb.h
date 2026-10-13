#pragma once
/* Function-specific inferred declarations. */
int AllocateKartAppearTableData_from_thumb(undefined4 param_1);
int Bmg_GetRawStringPointer_from_thumb(undefined4 param_1,undefined4 param_2);
void CellBank_ResetSomeMetatileObjectsMode_from_thumb(int param_1,int param_2,undefined4 param_3,int param_4);
void CopyBgData_Bg2_Top(undefined4 param_1,int param_2,uint param_3);
void CopyBgData_Bg3_Bottom(undefined4 param_1,int param_2,uint param_3);
void CopyPaletteBottom(undefined4 param_1,int param_2,uint param_3);
int CreateDisplayConfig(undefined4 param_1,undefined4 param_2);
void DisplayConfig_SetBottomEngineBg3Config(int param_1);
void DisplayConfig_SetTopEngineBg1Config(int param_1);
void DisplayConfig_SetTopEngineBg2Config(int param_1);
void DisplayConfig_SetTopEngineBg3Config(int param_1);
void EnableAlphaSetSubBldcntBldalpha(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);
void EnableAlphaSetTopBldcntBldalpha(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);
void GetActiveExecutionContextHeapHandle_4(void);
uint GetB488TitleMenuSkipIntro(void);
undefined4 GetLoadedFont_from_thumb(int param_1);
void Gfx_ReadCharGraphics(int *param_1,int param_2);
void Gfx_ReadCharGraphicsV2(int *param_1,int param_2);
void Gfx_ReadPalette(int *param_1,int param_2);
void InitializeNavigationContext_from_thumb(undefined4 param_1,int *param_2);
undefined4 IsTitleTrue(void);
void LoadCellBankFrom(int *param_1,int param_2);
void LoadTitleFiles_from_thumb(void);
void MaybeReadScreenBlock_0(int *param_1,int param_2);
undefined4 Mem_AllocateHeap(uint param_1,undefined4 param_2);
void OamBuffer_SomeFn_from_thumb(int param_1,int param_2);
void PopulateNextRaceConfig(void);
void PrepareNavigationContextFiles_from_thumb(void);
void ResetB488HeyhoPaletteRows_from_thumb(void);
void SetB488SinglePlayerMenuTarget(undefined4 param_1);
void SetB488_b2(undefined4 param_1);
void SetB488_b6(undefined4 param_1);
void SetCurrentMissionNotBeaten(undefined4 param_1);
void SetDispcntSubDisplayFrameSelect(uint param_1);
void SetDispcntTopDisplayFrameSelect(uint param_1);
void SetGlobalDisplayConfig(int param_1);
void SetSubDispcntWindow0Window1ObjDisplayFlag(int param_1);
void SetSystemContextOverlayState(undefined4 param_1);
void SetTopDispcntWindow0Window1ObjDisplayFlag(int param_1);
void StructP_SetAFlag4_SkipBattleIntro(uint param_1);
void TEQSub_Fn10Impl_Fn12Impl(undefined4 param_1,int param_2,uint param_3);
void TEQSub_Fn11Impl_Fn13Impl(undefined4 param_1,int param_2,uint param_3);
void TEQSub_Fn27Impl_Fn29Impl(undefined4 param_1,int param_2,uint param_3);
void TEQSub_Fn30Impl(undefined4 param_1,int param_2,uint param_3);
void TEQSub_Fn35Impl(undefined4 param_1,int param_2,uint param_3);
void Title_CopyFunctionList_from_thumb(void);
void Title_SomeBldalphaConfig_from_thumb(void);
void func_020b47c0(void);
void func_0212426c(void);
undefined4 func_021243ac(int param_1,int param_2,undefined4 param_3,int param_4);
void func_02124ed0(undefined4 param_1,int param_2,int param_3,undefined4 *param_4);
void func_02148ca0(void);
void func_0214b63c(void);
void func_0214b6a0(undefined4 param_1,int param_2,undefined4 param_3);
void func_0214b720(void);
#define iRam020ad708 (*(int *)(uintptr_t)0x20ad708u)
#define iRam020ad81c (*(int *)(uintptr_t)0x20ad81cu)
#define piRam020ad704 (*(int **)(uintptr_t)0x20ad704u)
#define piRam020ad818 (*(int **)(uintptr_t)0x20ad818u)
#define uRam020ad700 (*(undefined4 *)(uintptr_t)0x20ad700u)
#define uRam020ad70c (*(undefined4 *)(uintptr_t)0x20ad70cu)
#define uRam020ad710 (*(undefined4 *)(uintptr_t)0x20ad710u)
#define uRam020ad714 (*(undefined4 *)(uintptr_t)0x20ad714u)
#define uRam020ad718 (*(undefined4 *)(uintptr_t)0x20ad718u)
#define uRam020ad71c (*(undefined4 *)(uintptr_t)0x20ad71cu)
#define uRam020ad720 (*(undefined4 *)(uintptr_t)0x20ad720u)
#define uRam020ad724 (*(undefined4 *)(uintptr_t)0x20ad724u)
#define uRam020ad728 (*(undefined4 *)(uintptr_t)0x20ad728u)
#define uRam020ad72c (*(undefined4 *)(uintptr_t)0x20ad72cu)
#define uRam020ad730 (*(undefined4 *)(uintptr_t)0x20ad730u)
#define uRam020ad734 (*(undefined4 *)(uintptr_t)0x20ad734u)
#define uRam020ad738 (*(undefined4 *)(uintptr_t)0x20ad738u)
#define uRam020ad73c (*(undefined4 *)(uintptr_t)0x20ad73cu)
#define uRam020ad740 (*(undefined4 *)(uintptr_t)0x20ad740u)
#define uRam020ad744 (*(undefined4 *)(uintptr_t)0x20ad744u)
#define uRam020ad748 (*(undefined4 *)(uintptr_t)0x20ad748u)
#define uRam020ad74c (*(undefined4 *)(uintptr_t)0x20ad74cu)
#define uRam020ad750 (*(undefined4 *)(uintptr_t)0x20ad750u)
#define uRam020ad754 (*(undefined4 *)(uintptr_t)0x20ad754u)
#define uRam020ad758 (*(undefined4 *)(uintptr_t)0x20ad758u)
#define uRam020ad75c (*(undefined4 *)(uintptr_t)0x20ad75cu)
#define uRam020ad760 (*(undefined4 *)(uintptr_t)0x20ad760u)
#define uRam020ad764 (*(undefined4 *)(uintptr_t)0x20ad764u)
