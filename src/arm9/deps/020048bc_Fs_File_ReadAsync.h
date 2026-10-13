#pragma once
/* Function-specific inferred declarations. */
int Fs_File_DoRead(int param_1,undefined4 param_2,int param_3,int param_4);
void Fs_File_ReadAsync(void);
#define pcRam020048c8 (*(__typeof__(Fs_File_DoRead) **)(uintptr_t)0x20048c8u)
