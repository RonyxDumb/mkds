/* Decompiled C draft; module arm9; ROM address 020cadf4. No matching claim. */
#include "types.h"
#include "deps/020cadf4_func_020cadf4.h"

void func_020cadf4(int param_1)

{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = GetPMaybeState_1();
    if ((iVar1 == 0) || (iVar1 = func_020cae38(), iVar1 == 0)) {
      *(undefined2 *)(param_1 + 4) = 2;
    }
    else {
      *(undefined2 *)(param_1 + 4) = 6;
      func_020cae24(1);
    }
  }
  return;
}

