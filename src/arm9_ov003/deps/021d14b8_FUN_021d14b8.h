#pragma once
/* Function-specific inferred declarations. */
undefined4 FUN_021d1440(int param_1,int param_2,int param_3);
uint * FUN_021d14b8(undefined4 param_1,uint *param_2,int param_3);
undefined4 FUN_021d1cd4(ushort *param_1);
void FUN_021d2808(int *param_1);
int FUN_021d285c(undefined4 param_1,undefined4 param_2);
#define DAT_021d155c (*(int **)(uintptr_t)0x21d155cu)
#define DAT_021d1560 (*(undefined4 *)(uintptr_t)0x21d1560u)

/* Address resolved to indexed definition; inferred ABI remains provisional. */
void Fs_File_Initialize(undefined4 *param_1);
#define func_0x02004d80 Fs_File_Initialize
undefined4 Fs_File_Open(undefined4 param_1);
#define func_0x02004a30 Fs_File_Open
void Os_Terminate(void);
#define func_0x0200fd1c Os_Terminate
void Fs_File_Read(void);
#define func_0x020048ac Fs_File_Read
undefined4 Fs_File_Close(int param_1);
#define func_0x020049e8 Fs_File_Close
void DecompressLzss(uint param_1,byte *param_2);
#define func_0x0214d344 DecompressLzss
