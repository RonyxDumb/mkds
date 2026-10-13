#pragma once
/* Function-specific inferred declarations. */
undefined4 AllocateReserveTEQSub(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);
int Bmg_GetRawStringPointer_from_thumb(undefined4 param_1,undefined4 param_2);
bool CheckUpdateGrandPrixResult(void);
void CopyMemory16(int param_1,int param_2,int param_3);
int CreateDisplayConfig(undefined4 param_1,undefined4 param_2);
void DisplayEngineConfig_SetBg1Config(int param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,undefined2 param_5,undefined2 param_6,undefined2 param_7,undefined2 param_8);
void DisplayEngineConfig_SetBg3Config(int param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,undefined2 param_5,undefined2 param_6,undefined2 param_7);
void FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(undefined4 param_1);
undefined4 GetBmgIndexFromCircuitIndex_from_thumb(int param_1);
undefined4 GetCurrentUnlockedSecretFlagsAndSaveIfResultScene(void);
undefined4 GetLoadedFont_from_thumb(int param_1);
void InitializeNavigationContext_from_thumb(undefined4 param_1,int *param_2);
void InstanceStructM_from_thumb(undefined4 param_1,undefined4 param_2,undefined4 param_3);
void LoadCupTrophyModel(int param_1,uint param_2);
void LoadPlayerGfxData_from_thumb(undefined4 param_1,undefined4 *param_2);
void MaybeReadScreenBlock_0(int *param_1,int param_2);
undefined4 Mem_AllocateHeap(uint param_1,undefined4 param_2);
void Mem_CpuFastMemorySet(undefined4 param_1,undefined4 *param_2,uint param_3);
void NNSi_MaybeSndPlayerStartSeq(undefined4 param_1,undefined4 param_2,undefined4 param_3);
void PlayerGfxData_Create_from_thumb(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7,code *param_8);
void PrepareNavigationContextFiles_from_thumb(void);
void SetGlobalDisplayConfig(int param_1);
void WaitForWorkerTask(void);
int find_buf_fn_from_thumb(undefined4 param_1);
void func_02025854(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7);
undefined4 func_02025a00(undefined4 param_1,undefined4 param_2,int param_3,short *param_4,undefined4 param_5);
void func_02025a50(int param_1,undefined4 param_2,int *param_3);
void func_0202a340(undefined4 param_1,int param_2);
void func_02062860(void);
void func_020629a4(void);
void func_02124094(int param_1,int param_2,undefined4 param_3,int param_4,int param_5);
void func_02124224(void);
void func_0212426c(void);
undefined4 func_021243ac(int param_1,int param_2,undefined4 param_3,int param_4);
void func_0212463c(int param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6,int param_7,undefined4 param_8,int param_9);
void func_02124748(int param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6,undefined4 param_7,int param_8);
void func_02145d38(void);
void func_02148ca0(void);
void func_02148cb8(void);
#define iRam0202a20c (*(int *)(uintptr_t)0x202a20cu)
#define iRam0202a210 (*(int *)(uintptr_t)0x202a210u)
#define iRam0202a31c (*(int *)(uintptr_t)0x202a31cu)
#define iRam0202a334 (*(int *)(uintptr_t)0x202a334u)
#define piRam0202a1a0 (*(int **)(uintptr_t)0x202a1a0u)
#define piRam0202a1ac (*(int **)(uintptr_t)0x202a1acu)
#define piRam0202a320 (*(int **)(uintptr_t)0x202a320u)
#define piRam0202a33c (*(int **)(uintptr_t)0x202a33cu)
#define psRam0202a208 (*(short **)(uintptr_t)0x202a208u)
#define puRam0202a1dc (*(undefined4 **)(uintptr_t)0x202a1dcu)
#define puRam0202a1e0 (*(ushort **)(uintptr_t)0x202a1e0u)
#define puRam0202a1e4 (*(ushort **)(uintptr_t)0x202a1e4u)
#define uRam0202a1a4 (*(undefined4 *)(uintptr_t)0x202a1a4u)
#define uRam0202a1a8 (*(undefined4 *)(uintptr_t)0x202a1a8u)
#define uRam0202a1b0 (*(undefined4 *)(uintptr_t)0x202a1b0u)
#define uRam0202a1b4 (*(undefined4 *)(uintptr_t)0x202a1b4u)
#define uRam0202a1b8 (*(undefined4 *)(uintptr_t)0x202a1b8u)
#define uRam0202a1bc (*(undefined4 *)(uintptr_t)0x202a1bcu)
#define uRam0202a1c0 (*(undefined4 *)(uintptr_t)0x202a1c0u)
#define uRam0202a1c4 (*(undefined4 *)(uintptr_t)0x202a1c4u)
#define uRam0202a1c8 (*(undefined4 *)(uintptr_t)0x202a1c8u)
#define uRam0202a1cc (*(undefined4 *)(uintptr_t)0x202a1ccu)
#define uRam0202a1d0 (*(undefined4 *)(uintptr_t)0x202a1d0u)
#define uRam0202a1d4 (*(undefined4 *)(uintptr_t)0x202a1d4u)
#define uRam0202a1d8 (*(undefined4 *)(uintptr_t)0x202a1d8u)
#define uRam0202a1e8 (*(undefined4 *)(uintptr_t)0x202a1e8u)
#define uRam0202a1ec (*(undefined4 *)(uintptr_t)0x202a1ecu)
#define uRam0202a1f0 (*(undefined4 *)(uintptr_t)0x202a1f0u)
#define uRam0202a1f4 (*(undefined4 *)(uintptr_t)0x202a1f4u)
#define uRam0202a1f8 (*(undefined4 *)(uintptr_t)0x202a1f8u)
#define uRam0202a1fc (*(undefined4 *)(uintptr_t)0x202a1fcu)
#define uRam0202a200 (*(undefined4 *)(uintptr_t)0x202a200u)
#define uRam0202a204 (*(undefined4 *)(uintptr_t)0x202a204u)
#define uRam0202a324 (*(undefined4 *)(uintptr_t)0x202a324u)
#define uRam0202a328 (*(undefined4 *)(uintptr_t)0x202a328u)
#define uRam0202a32c (*(undefined4 *)(uintptr_t)0x202a32cu)
#define uRam0202a330 (*(undefined4 *)(uintptr_t)0x202a330u)
#define uRam0202a338 (*(undefined4 *)(uintptr_t)0x202a338u)
