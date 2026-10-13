/* Decompiled C draft; module arm9; ROM address 0200ba84. No matching claim. */
#include "types.h"
#include "deps/0200ba84_func_0200ba84.h"

void func_0200ba84(undefined4 param_1)

{
  Os_DisableIrq();
  *(undefined4 *)(*piRam0200baa0 + iRam0200baa4) = param_1;
  Os_RestoreIrq();
  return;
}

