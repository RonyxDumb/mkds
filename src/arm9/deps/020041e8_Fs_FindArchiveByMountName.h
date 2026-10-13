#pragma once
/* Function-specific inferred declarations. */
uint Fs_FindArchiveByMountName(void);
uint Fs_PackArchiveMountName(int param_1,int param_2);
longlong Os_DisableIrq(void);
undefined4 Os_RestoreIrq(void);
#define uRam02004234 (*(uint *)(uintptr_t)0x2004234u)
