#pragma once
/* Function-specific inferred declarations. */
uint Fs_Archive_HandleNextOperation(int param_1);
uint Fs_File_DoExecuteOperation(int param_1,uint param_2);
void Fs_File_ExecuteAsyncOperation(int param_1);
longlong Os_DisableIrq(void);
undefined4 Os_RestoreIrq(void);
void Os_Thread_WakeUp(uint *param_1);

