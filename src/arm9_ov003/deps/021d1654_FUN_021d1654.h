#pragma once
/* Function-specific inferred declarations. */
void FUN_021d1654(void);
void FUN_021d1d60(int param_1,int param_2,int param_3);
undefined4 FUN_021d283c(undefined4 param_1);
int FUN_021d285c(undefined4 param_1,undefined4 param_2);
#define DAT_021d1750 (*(int **)(uintptr_t)0x21d1750u)
#define DAT_021d1754 (*(undefined4 *)(uintptr_t)0x21d1754u)
#define DAT_021d1758 (*(undefined4 *)(uintptr_t)0x21d1758u)
#define DAT_021d175c (*(undefined4 *)(uintptr_t)0x21d175cu)
#define DAT_021d1760 (*(undefined4 *)(uintptr_t)0x21d1760u)
#define DAT_021d1764 (*(undefined4 *)(uintptr_t)0x21d1764u)
#define DAT_021d1768 (*(undefined4 *)(uintptr_t)0x21d1768u)
#define DAT_021d176c (*(undefined4 *)(uintptr_t)0x21d176cu)

/* Address resolved to indexed definition; inferred ABI remains provisional. */
void Fs_File_Initialize(undefined4 *param_1);
#define func_0x02004d80 Fs_File_Initialize
undefined4 Fs_File_Open(undefined4 param_1);
#define func_0x02004a30 Fs_File_Open
void Os_Terminate(void);
#define func_0x0200fd1c Os_Terminate
int Os_AllocateLockId(void);
#define func_0x0200cd28 Os_AllocateLockId
void Fs_File_Read(void);
#define func_0x020048ac Fs_File_Read
undefined4 Fs_File_Close(int param_1);
#define func_0x020049e8 Fs_File_Close
void Fs_Archive_Initialize(int param_1);
#define func_0x02004238 Fs_Archive_Initialize
undefined4 Fs_RegisterArchive(undefined4 *param_1,undefined4 param_2,undefined4 param_3);
#define func_0x02004128 Fs_RegisterArchive
void Fs_Archive_SetExtraFileOperationHandler(int param_1,int param_2,int param_3);
#define func_0x02003c60 Fs_Archive_SetExtraFileOperationHandler
undefined4 Fs_Archive_LoadFromFatFnt (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5, undefined4 param_6,int param_7,int param_8);
#define func_0x02004018 Fs_Archive_LoadFromFatFnt
uint Fs_Archive_LoadFatFnt(int param_1,int param_2,uint param_3);
#define func_0x02003e24 Fs_Archive_LoadFatFnt
void MaybeUtil_SPrintF(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);
#define func_0x0200da28 MaybeUtil_SPrintF
bool Fs_Chdir(undefined4 param_1);
#define func_0x020047ec Fs_Chdir
