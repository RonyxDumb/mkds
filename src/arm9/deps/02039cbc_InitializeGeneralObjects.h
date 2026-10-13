#pragma once
/* Function-specific inferred declarations. */
undefined4 AllocateHeapsAndBuffers(undefined4 param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,undefined4 *param_5,undefined4 *param_6);
void Card_SetUserCardPulledOutCallback(undefined4 param_1);
void CreateGlobalB488_from_thumb(void);
void CreateMountManager_from_thumb(undefined4 param_1);
uint ExecutionContext_GetHeapHandle(int param_1);
uint GetActiveExecutionContext(void);
void InitializeAudio(int param_1,int param_2,int param_3);
void InitializeGeneralObjects(void);
void InitializeGlobal1A44_from_thumb(undefined4 param_1);
void InitializeGlobalB488_from_thumb(undefined4 param_1);
void InitializeGlobalB_from_thumb(undefined4 param_1);
void InitializeGlobalCO(undefined4 param_1);
void InitializeGlobalZE(undefined4 param_1);
void InitializeGlobalZM(undefined4 param_1);
void InitializeOverlayManager(undefined4 param_1);
void InitializePrepareBackup_from_thumb(void);
void InitializeSaveDataHolder_from_thumb(undefined4 param_1);
void InitializeSaveDataIoManager_from_thumb(undefined4 param_1);
void InitializeSceneOverlayConfig(undefined4 param_1);
void InitializeSystemContext(undefined4 param_1);
void InitializeWorker(undefined4 param_1);
void Input_Initialize(undefined4 param_1);
void LoadEmbeddedStatic2DArchive_from_thumb(undefined4 param_1);
undefined4 Os_IsEmulator(void);
void PopulateMountDatas_MBChild_from_thumb(undefined4 param_1,undefined4 param_2,undefined4 param_3);
void PopulateNextRaceConfig(void);
void ResetOverlayManager(void);
void Rtc_Initialize(void);
void func_02057ed4(void);
void func_02108e94(void);
#define psRam02039dfc (*(short **)(uintptr_t)0x2039dfcu)
#define uRam02039df8 (*(undefined4 *)(uintptr_t)0x2039df8u)
