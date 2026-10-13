#pragma once
/* Function-specific inferred declarations. */
int Fs_File_DoRead(int param_1,undefined4 param_2,int param_3,int param_4);
void Fs_File_Read(void);
#define pcRam020048b8 (*(__typeof__(Fs_File_DoRead) **)(uintptr_t)0x20048b8u)
