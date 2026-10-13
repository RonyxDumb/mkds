#pragma once
/* Function-specific inferred declarations. */
uint Fs_Archive_LoadFatFnt(int param_1,int param_2,uint param_3);
void Fs_LoadRomArchiveFatFnt(undefined4 param_1,undefined4 param_2);
#define pcRam02004e14 (*(__typeof__(Fs_Archive_LoadFatFnt) **)(uintptr_t)0x2004e14u)
#define uRam02004e18 (*(undefined4 *)(uintptr_t)0x2004e18u)
