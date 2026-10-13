#pragma once
/* Function-specific inferred declarations. */
void Card_Initialize(void);
void Fs_Archive_Initialize(int param_1);
undefined4 Fs_Archive_LoadFromFatFnt(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,int param_7,int param_8);
void Fs_Archive_SetExtraFileOperationHandler(int param_1,int param_2,int param_3);
void Fs_InitializeMountRom(undefined4 param_1);
undefined4 Fs_RegisterArchive(undefined4 *param_1,undefined4 param_2,undefined4 param_3);
int Os_AllocateLockId(void);
#define psRam02004f98 (*(short **)(uintptr_t)0x2004f98u)
#define puRam02004f80 (*(undefined4 **)(uintptr_t)0x2004f80u)
#define puRam02004f84 (*(undefined4 **)(uintptr_t)0x2004f84u)
#define puRam02004f88 (*(undefined4 **)(uintptr_t)0x2004f88u)
#define puRam02004f8c (*(undefined4 **)(uintptr_t)0x2004f8cu)
#define uRam02004f90 (*(undefined4 *)(uintptr_t)0x2004f90u)
#define uRam02004f94 (*(undefined4 *)(uintptr_t)0x2004f94u)
#define uRam02004f9c (*(undefined4 *)(uintptr_t)0x2004f9cu)
#define uRam02004fa8 (*(uint *)(uintptr_t)0x2004fa8u)
#define uRam02004fac (*(undefined4 *)(uintptr_t)0x2004facu)
#define uRam02004fb0 (*(undefined4 *)(uintptr_t)0x2004fb0u)
#define uRam02004fb4 (*(uint *)(uintptr_t)0x2004fb4u)
