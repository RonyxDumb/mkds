#pragma once
/* Function-specific inferred declarations. */
void Fs_File_ExecuteAsyncOperation(int param_1);
bool Fs_File_ExecuteSyncOperation(int param_1);
void Fs_File_ReleaseOperation(undefined4 *param_1,undefined4 param_2);
undefined4 Fs_File_SendOperation(uint *param_1,uint param_2);
longlong Os_DisableIrq(void);
undefined4 Os_RestoreIrq(void);
void Os_Thread_Sleep(int param_1);

