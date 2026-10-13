#pragma once
/* Function-specific inferred declarations. */
int AllocateKartAppearTableData_from_thumb(undefined4 param_1);
void AndAnotherAlloc_0_from_thumb(undefined4 param_1,undefined4 param_2);
void CellBank_ResetSomeMetatileObjectsMode_from_thumb(int param_1,int param_2,undefined4 param_3,int param_4);
void CopyB43CFunctionTable_from_thumb(void);
void CopyInfoFromCOtoCA_from_thumb(void);
int CreateDisplayConfig(undefined4 param_1,undefined4 param_2);
void CreateGlobalCE_from_thumb(undefined4 param_1);
void CreateGlobalNN_from_thumb(undefined4 param_1,undefined4 param_2);
void CreateSetGlobalKTB_from_thumb(undefined4 param_1);
void DisplayConfig_SetBottomEngineBg0Config(int param_1);
void DisplayConfig_SetBottomEngineBg1Config(int param_1);
void DisplayConfig_SetBottomEngineBg2Config2(int param_1);
void DisplayConfig_SetBottomEngineBg3Config_1(int param_1);
void DisplayConfig_SetTopEngineBg0Config(int param_1);
void DisplayConfig_SetTopEngineBg1Config_1(int param_1);
void DisplayConfig_SetTopEngineBg2Config2(int param_1);
void DisplayConfig_SetTopEngineBg3Config_0(int param_1);
void EnableAlphaSetBldcntBldalphaSub(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);
void EnableAlphaSetBldcntBldalphaTop(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);
void GetActiveExecutionContextHeapHandle(void);
uint GetB488_B5(void);
uint GetB488_B6(void);
uint GetB488_SinglePlayerMenuTarget(void);
undefined4 GetGlobalCA_from_thumb(void);
undefined4 GetLoadedFont_from_thumb(int param_1);
uint GetPMaybeState_1(void);
void Gfx_ReadCharGraphics(int *param_1,int param_2);
void Gfx_ReadPalette(int *param_1,int param_2);
void InitializeGlobalB4A4_from_thumb(void);
void InitializeGlobalCA_from_thumb(undefined4 param_1);
void InitializeGlobalPK_from_thumb(undefined4 param_1);
void InitializeNavigationContext_from_thumb(undefined4 param_1,int *param_2);
void LoadCellBankFrom(int *param_1,int param_2);
undefined4 Mem_AllocateHeap(uint param_1,undefined4 param_2);
void OamBuffer_SomeFn_from_thumb(int param_1,int param_2);
void PrepareNavigationContextFiles_from_thumb(void);
void Scene_Menu_InitializeImpl_from_thumb(void);
void SetActiveExecutionContextHeapGroupId_from_thumb(undefined2 param_1);
void SetB488_B2(undefined4 param_1);
void SetDispcntWindows01ObjDisplayFlagsSub(int param_1);
void SetDispcntWindows01ObjDisplayFlagsTop(int param_1);
void SetGlobalDisplayConfig(int param_1);
void SetSinglePlayerMenuTarget(undefined4 param_1);
void SetSubDispcntTileObjMappingRemoveBoundary(uint param_1);
void SetTopDispcntTileObjMappingRemoveBoundary(uint param_1);
void VerifyCommonSelectGameFiles_from_thumb(void);
void VerifyCommonSelectRaceRuleFiles_from_thumb(void);
void VerifySelectCharacterFiles_from_thumb(void);
void VerifySelectCupCourseFiles_from_thumb(void);
void VerifySelectCupFiles_from_thumb(void);
void VerifySelectKartFiles_from_thumb(void);
void VerifySelectMenuFiles_from_thumb(void);
void func_02062860(void);
void func_020629a4(void);
void func_02078a34(int param_1);
void func_02078a9c(int param_1);
void func_020b47c0(void);
void func_020cbad0(void);
void func_020ccc74(undefined4 param_1,undefined4 param_2);
void func_0211f240(void);
void func_02124ed0(undefined4 param_1,int param_2,int param_3,undefined4 *param_4);
void func_021281fc(void);
#define DAT_020cbefc (*(undefined4 *)(uintptr_t)0x20cbefcu)
#define DAT_020cbf00 (*(int **)(uintptr_t)0x20cbf00u)
#define DAT_020cbf04 (*(undefined4 *)(uintptr_t)0x20cbf04u)
#define DAT_020cbf08 (*(int *)(uintptr_t)0x20cbf08u)
#define DAT_020cbf0c (*(int *)(uintptr_t)0x20cbf0cu)
#define DAT_020cbf10 (*(int *)(uintptr_t)0x20cbf10u)
#define DAT_020cbf14 (*(int *)(uintptr_t)0x20cbf14u)
#define DAT_020cbf18 (*(int *)(uintptr_t)0x20cbf18u)
#define DAT_020cbf1c (*(undefined4 *)(uintptr_t)0x20cbf1cu)
#define DAT_020cbf20 (*(int *)(uintptr_t)0x20cbf20u)
#define DAT_020cbf24 (*(undefined4 *)(uintptr_t)0x20cbf24u)
#define DAT_020cbf28 (*(int *)(uintptr_t)0x20cbf28u)
#define DAT_020cbf2c (*(undefined4 *)(uintptr_t)0x20cbf2cu)
#define DAT_020cbf30 (*(int *)(uintptr_t)0x20cbf30u)
#define DAT_020cbf34 (*(undefined4 *)(uintptr_t)0x20cbf34u)
#define DAT_020cbf38 (*(int *)(uintptr_t)0x20cbf38u)
#define DAT_020cbf3c (*(int *)(uintptr_t)0x20cbf3cu)
#define DAT_020cbf40 (*(undefined4 *)(uintptr_t)0x20cbf40u)
#define DAT_020cbf44 (*(int *)(uintptr_t)0x20cbf44u)
#define DAT_020cbf48 (*(undefined4 *)(uintptr_t)0x20cbf48u)
#define DAT_020cbf4c (*(int *)(uintptr_t)0x20cbf4cu)
#define DAT_020cbf50 (*(undefined4 *)(uintptr_t)0x20cbf50u)
#define DAT_020cbf54 (*(int *)(uintptr_t)0x20cbf54u)
#define DAT_020cbf58 (*(undefined4 *)(uintptr_t)0x20cbf58u)
#define DAT_020cbf5c (*(int *)(uintptr_t)0x20cbf5cu)
#define DAT_020cbf60 (*(undefined4 *)(uintptr_t)0x20cbf60u)
#define DAT_020cbf64 (*(int *)(uintptr_t)0x20cbf64u)
#define DAT_020cbf68 (*(int *)(uintptr_t)0x20cbf68u)
#define DAT_020cbf6c (*(int *)(uintptr_t)0x20cbf6cu)
#define DAT_020cbf70 (*(int *)(uintptr_t)0x20cbf70u)
#define DAT_020cc0d4 (*(int **)(uintptr_t)0x20cc0d4u)
#define DAT_020cc0d8 (*(int *)(uintptr_t)0x20cc0d8u)
#define DAT_020cc0dc (*(int *)(uintptr_t)0x20cc0dcu)
#define DAT_020cc0e0 (*(int *)(uintptr_t)0x20cc0e0u)
