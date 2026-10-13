#pragma once
/* Function-specific inferred declarations. */
void Arm_FlushRange(uint param_1,int param_2);
undefined4 Fs_File_Close(int param_1);
void Fs_File_Initialize(undefined4 *param_1);
undefined4 Fs_File_OpenRaw(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5);
void Fs_File_Read(void);
undefined4 Fs_File_Seek(int param_1,int param_2,int param_3);
uint Fs_FindArchiveByMountName(void);
void MaybeSetupRomRootOrOverlays(int param_1,int param_2);
undefined4 Mem_DcDrainWriteBuffer(void);
longlong Os_DisableIrq(void);
undefined4 Os_RestoreIrq(void);
#define iRam0204dab4 (*(int *)(uintptr_t)0x204dab4u)
#define puRam0204daa8 (*(undefined1 **)(uintptr_t)0x204daa8u)
#define uRam0204daa4 (*(undefined4 *)(uintptr_t)0x204daa4u)
#define uRam0204daac (*(uint *)(uintptr_t)0x204daacu)
#define uRam0204dab0 (*(uint *)(uintptr_t)0x204dab0u)
