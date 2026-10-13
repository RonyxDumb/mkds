/* Decompiled C draft; module arm9; ROM address 0200c4a4. No matching claim. */
#include "types.h"
#include "deps/0200c4a4_func_0200c4a4.h"

void func_0200c4a4(undefined4 param_1,int *param_2)

{
  if (*param_2 == 0) {
    func_0200cd1c();
  }
  Os_RestoreIrq(param_2[1]);
  return;
}

