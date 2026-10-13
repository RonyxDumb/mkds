#pragma once
/* Function-specific inferred declarations. */
uint Fs_Archive_HandleNextOperation(int param_1);
uint Fs_File_DoExecuteOperation(int param_1,uint param_2);
void Fs_File_ExecuteAsyncOperation(int param_1);
bool Fs_File_ExecuteSyncOperation(int param_1);
void Fs_File_ReleaseOperation(undefined4 *param_1,undefined4 param_2);

