/* Decompiled C draft; module arm9; ROM address 0212ee54. No matching claim. */
#include "types.h"
#include "deps/0212ee54_func_0212ee54.h"

void func_0212ee54(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = Os_DisableIrq();
  IntrusiveListWrapper_InsertLast(uRam0212ee88,param_1);
  Os_RestoreIrq(uVar1);
  return;
}

