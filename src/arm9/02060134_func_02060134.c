/* Decompiled C draft; module arm9; ROM address 02060134. No matching claim. */
#include "types.h"
#include "deps/02060134_func_02060134.h"

undefined4 func_02060134(undefined4 param_1,undefined4 param_2,undefined2 *param_3)

{
  bool bVar1;
  int iVar2;
  undefined2 uStack_28;
  undefined1 uStack_26;
  undefined1 uStack_25;
  char local_10;
  
  iVar2 = TimeTrialRecord_CopyFrom_from_thumb(param_1,param_2,(int)(uintptr_t)(&uStack_28));
  if ((iVar2 == 0) || (local_10 == '\0')) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    *(undefined1 *)(param_3 + 1) = uStack_26;
    *(undefined1 *)((int)param_3 + 3) = uStack_25;
    *param_3 = uStack_28;
    return 1;
  }
  return 0;
}

