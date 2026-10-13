#pragma once
/* Function-specific inferred declarations. */
undefined4 Fs_File_Close(int param_1);
void Fs_File_Initialize(undefined4 *param_1);
undefined4 Fs_File_OpenById(int param_1,int param_2,undefined4 param_3);
void Fs_GetOverlayFileId(undefined4 *param_1,int param_2);
undefined4 Fs_OverlayInfo_DoLoad(int param_1,int param_2,int param_3,undefined4 param_4,int param_5,uint param_6,int param_7,uint param_8);
undefined4 Fs_OverlayInfo_Load(int param_1,int param_2,int param_3);
void Mem_CpuCopy8(ushort *param_1,uint *param_2,uint param_3);
#define uRam020056f0 (*(uint *)(uintptr_t)0x20056f0u)
#define uRam020056f4 (*(uint *)(uintptr_t)0x20056f4u)
#define uRam020056f8 (*(uint *)(uintptr_t)0x20056f8u)
#define uRam020056fc (*(uint *)(uintptr_t)0x20056fcu)
#define uRam02005700 (*(undefined4 *)(uintptr_t)0x2005700u)
