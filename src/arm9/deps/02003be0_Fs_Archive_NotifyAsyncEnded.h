#pragma once
/* Function-specific inferred declarations. */
uint Fs_Archive_HandleNextOperation(int param_1);
void Fs_Archive_NotifyAsyncEnded(int param_1,undefined4 param_2);
void Fs_File_ExecuteAsyncOperation(int param_1);
void Fs_File_ReleaseOperation(undefined4 *param_1,undefined4 param_2);
longlong Os_DisableIrq(void);
undefined4 Os_RestoreIrq(void);
void Os_Thread_WakeUp(uint *param_1);

