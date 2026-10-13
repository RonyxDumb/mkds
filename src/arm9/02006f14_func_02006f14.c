/* Decompiled C draft; module arm9; ROM address 02006f14. No matching claim. */
#include "types.h"
#include "deps/02006f14_func_02006f14.h"

undefined4 func_02006f14(int param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = (int *)func_020070b8();
  if ((*piVar1 != 4) && (*piVar1 != 6)) {
    func_020070c0(param_1 + -0xe);
    func_020070cc(param_2 + -0xe);
    return 1;
  }
  return 0;
}

