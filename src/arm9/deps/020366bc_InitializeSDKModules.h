#pragma once
/* Function-specific inferred declarations. */
void FX_Initialize(void);
void Fs_Initialize(void);
ushort GX_VBlankIntr(int param_1,ushort param_2);
void Gfx_Initialize(void);
void InitializeGlobalHN(void);
void InitializeSDKModules(void);
undefined4 MaybeInitializeDwc_from_thumb(undefined4 param_1);
void MaybePrepareVram(void);
void Os_DisableMainExRegion(void);
longlong Os_EnableIrq(void);
uint Os_EnableIrqHandler(uint param_1);
void Os_Initialize(void);
void Os_InitializeAlarm(void);
void Os_InitializeTick(void);
void Os_SetIrqHandler(uint param_1,undefined4 param_2);
void SomeDispcntInit(void);
void SomeVramConfig(void);
void SomeVramInit(void);
#define puRam02036760 (*(undefined4 **)(uintptr_t)0x2036760u)
#define puRam02036764 (*(uint **)(uintptr_t)0x2036764u)
#define puRam0203676c (*(undefined2 **)(uintptr_t)0x203676cu)
#define puRam02036774 (*(undefined4 **)(uintptr_t)0x2036774u)
#define uRam02036768 (*(undefined4 *)(uintptr_t)0x2036768u)
#define uRam02036770 (*(undefined4 *)(uintptr_t)0x2036770u)
