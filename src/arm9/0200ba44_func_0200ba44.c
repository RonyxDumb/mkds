/* Decompiled C draft; module arm9; ROM address 0200ba44. No matching claim. */
#include "types.h"
#include "deps/0200ba44_func_0200ba44.h"

void func_0200ba44(undefined4 param_1,undefined4 param_2)

{
  Os_DisableIrq();
  *(short *)(*piRam0200ba78 + iRam0200ba7c) = (short)param_1;
  Os_RestoreIrq();
  if (*(code **)(*piRam0200ba78 + iRam0200ba80) != (code *)0x0) {
    (**(code **)(*piRam0200ba78 + iRam0200ba80))(param_1,param_2);
  }
  return;
}

