/* Decompiled C draft; module arm9; ROM address 0207bfac. No matching claim. */
#include "types.h"
#include "deps/0207bfac_func_0207bfac.h"

bool func_0207bfac(int param_1)

{
  short sVar1;
  
  *(short *)(param_1 + 2) = *(short *)(param_1 + 2) + -1;
  sVar1 = *(short *)(param_1 + 2);
  if (sVar1 < 1) {
    *(undefined2 *)(param_1 + 2) = 0;
  }
  return sVar1 < 1;
}

