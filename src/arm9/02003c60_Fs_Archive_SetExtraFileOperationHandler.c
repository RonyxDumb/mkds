/* Decompiled C draft; module arm9; ROM address 02003c60. No matching claim. */
#include "types.h"
#include "deps/02003c60_Fs_Archive_SetExtraFileOperationHandler.h"

void Fs_Archive_SetExtraFileOperationHandler(int param_1,int param_2,int param_3)

{
  if (param_3 == 0) {
    param_2 = 0;
  }
  else if (param_2 == 0) {
    param_3 = 0;
  }
  *(int *)(param_1 + 0x54) = param_2;
  *(int *)(param_1 + 0x58) = param_3;
  return;
}

