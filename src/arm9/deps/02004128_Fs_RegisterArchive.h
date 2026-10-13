#pragma once
/* Function-specific inferred declarations. */
uint Fs_FindArchiveByMountName(void);
uint Fs_PackArchiveMountName(int param_1,int param_2);
undefined4 Fs_RegisterArchive(undefined4 *param_1,undefined4 param_2,undefined4 param_3);
longlong Os_DisableIrq(void);
undefined4 Os_RestoreIrq(void);
#define piRam020041e0 (*(int **)(uintptr_t)0x20041e0u)
#define piRam020041e4 (*(int **)(uintptr_t)0x20041e4u)
