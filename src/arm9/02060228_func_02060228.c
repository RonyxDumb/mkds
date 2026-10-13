/* Decompiled C draft; module arm9; ROM address 02060228. No matching claim. */
#include "types.h"
#include "deps/02060228_func_02060228.h"

undefined4 func_02060228(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 auStack_28 [24];
  char local_10;
  
  iVar1 = TimeTrialRecord_CopyFrom_from_thumb(param_1,param_2,(int)(uintptr_t)(auStack_28));
  if ((iVar1 != 0) && (local_10 != '\0')) {
    return 1;
  }
  return 0;
}

