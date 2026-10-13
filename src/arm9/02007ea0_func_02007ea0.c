/* Decompiled C draft; module arm9; ROM address 02007ea0. No matching claim. */
#include "types.h"
#include "deps/02007ea0_func_02007ea0.h"

void func_02007ea0(undefined4 param_1)

{
  Os_DisableIrq();
  *(undefined4 *)(*piRam02007ebc + iRam02007ec0) = param_1;
  Os_RestoreIrq();
  return;
}

