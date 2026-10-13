#pragma once
/* Function-specific inferred declarations. */
void Arc_DisposeAllArchives_from_thumb(void);
void BrightCtx_SomeFnTopBottom(short param_1);
void Bright_FadeOutBlack(short param_1);
void Bright_FadeOutWhite(short param_1);
undefined4 Bright_IsBothScreensFadedIn(void);
undefined4 Bright_IsBothScreensFadedOut(void);
uint Card_IsPulledOut(void);
void Card_SetUserCardPulledOutCallback(undefined4 param_1);
void CleanupPlayerGfxDataFontsEtc_from_thumb(void);
void EnableGreenSwap(void);
uint ExecutionContext_GetHeapHandle(int param_1);
uint GetActiveExecutionContext(void);
int GetCurrentSceneId(void);
int GetNextSceneId(void);
void HandleAllGlobalTEQSubs(void);
void InitializeGlobalTEQ(undefined4 param_1,undefined4 param_2);
void LoadMA2ContentIfMounted_from_thumb(void);
void LoopFn_DisplayConfig(void);
void LoopFn_Some3D(void);
void LoopFn_Sound(void);
void MaybeChangeAudioForMenu(void);
undefined4 MaybeIfExpectsReturnToTitleScene(void);
undefined4 Mem_AllocateHeap(uint param_1,undefined4 param_2);
void MountArchivesForScene_from_thumb(int param_1);
void NotifyError(undefined4 param_1);
void OnSceneLoop(int param_1,undefined4 *param_2);
longlong Os_DisableIrq(void);
undefined4 Os_RestoreIrq(void);
bool PM_GetLCDPower(void);
void PMi_SetLCDPower(int param_1);
int Pad_DetectFolding(void);
void PlayBgEffectsAndMore(void);
void ResetDTCMFrameHeap(void);
void ResetDisplayConfig(void);
void SetActiveExecutionContextHeapGroupId_from_thumb(undefined2 param_1);
void SetBottomBrightness(undefined4 param_1);
void SetSomeSceneSseqId(undefined4 param_1);
void SetTopBrightness(undefined4 param_1);
bool ShouldPauseBgmInSceneChange(undefined4 param_1,int param_2);
void SomeMaskMountDataFlags_from_thumb(void);
void SomeVramConfig(void);
bool TryGetSceneSpecialBgmSseqId(int param_1,undefined4 *param_2);
void UpdateBrightnessContextsAndMore(int param_1);
void func_02037658(int param_1);
void func_02043410(void);
undefined2 func_020435c4(void);
void func_02043648(void);
void func_02043a34(void);
void func_02043ae0(void);
void func_02043b04(void);
void func_02043b3c(void);
void func_02043b48(void);
undefined4 func_0204984c(undefined4 param_1,int param_2);
undefined4 func_02049aa4(void);
undefined4 func_02049b6c(void);
void func_0204aba8(void);
void func_0204ac10(void);
void func_0204ac60(void);
void func_0204f7f4(void);
undefined4 func_020546d8(void);
undefined4 func_02054754(void);
int func_02054f58(void);
void func_02055340(void);
void func_02105ec0(void);
void func_02105fcc(void);
void func_0212034c(void);
void func_0214f83c(uint param_1,ushort param_2,ushort param_3);
int func_0214fb54(void);
#define psRam020497dc (*(short **)(uintptr_t)0x20497dcu)
#define uRam020497bc (*(uint *)(uintptr_t)0x20497bcu)
#define uRam020497c0 (*(uint *)(uintptr_t)0x20497c0u)
#define uRam020497c4 (*(undefined4 *)(uintptr_t)0x20497c4u)
#define uRam020497c8 (*(uint *)(uintptr_t)0x20497c8u)
#define uRam020497cc (*(uint *)(uintptr_t)0x20497ccu)
#define uRam020497d0 (*(undefined4 *)(uintptr_t)0x20497d0u)
#define uRam020497d4 (*(uint *)(uintptr_t)0x20497d4u)
#define uRam020497d8 (*(uint *)(uintptr_t)0x20497d8u)
#define uRam020497e0 (*(uint *)(uintptr_t)0x20497e0u)
#define uRam020497e4 (*(uint *)(uintptr_t)0x20497e4u)
#define uRam020497e8 (*(uint *)(uintptr_t)0x20497e8u)
#define uRam020497ec (*(undefined4 *)(uintptr_t)0x20497ecu)
