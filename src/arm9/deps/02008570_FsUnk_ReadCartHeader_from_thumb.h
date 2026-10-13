#pragma once
/* Function-specific inferred declarations. */
void Arm_FlushRange(uint param_1,int param_2);
int FsUnk_ReadCartHeader_from_thumb(undefined1 *param_1,int param_2,uint param_3);
undefined4 Fs_File_Close(int param_1);
void Fs_File_Initialize(undefined4 *param_1);
undefined4 Fs_File_OpenRaw(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5);
void Fs_File_Read(void);
undefined4 Fs_File_Seek(int param_1,int param_2,int param_3);
uint Fs_FindArchiveByMountName(void);
void Mem_CpuCopy8(ushort *param_1,uint *param_2,uint param_3);
void MemsetSomeObject_from_thumb(undefined4 param_1);
void func_0200850c(uint *param_1,uint param_2,uint param_3,int param_4);
void func_0200ae60(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5);
#define iRam0200884c (*(int *)(uintptr_t)0x200884cu)
#define iRam02008850 (*(int *)(uintptr_t)0x2008850u)
#define iRam02008854 (*(int *)(uintptr_t)0x2008854u)
#define iRam02008864 (*(int *)(uintptr_t)0x2008864u)
#define iRam02008868 (*(int *)(uintptr_t)0x2008868u)
#define iRam02008878 (*(int *)(uintptr_t)0x2008878u)
#define puRam0200886c (*(undefined4 **)(uintptr_t)0x200886cu)
#define uRam02008848 (*(uint *)(uintptr_t)0x2008848u)
#define uRam02008858 (*(undefined4 *)(uintptr_t)0x2008858u)
#define uRam0200885c (*(uint *)(uintptr_t)0x200885cu)
#define uRam02008860 (*(uint *)(uintptr_t)0x2008860u)
#define uRam02008870 (*(undefined4 *)(uintptr_t)0x2008870u)
#define uRam02008874 (*(undefined4 *)(uintptr_t)0x2008874u)
#define uRam0200887c (*(undefined4 *)(uintptr_t)0x200887cu)
