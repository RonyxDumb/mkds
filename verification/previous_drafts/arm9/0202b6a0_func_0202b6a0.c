/* Decompiled C draft; module arm9; ROM address 0202b6a0. No matching claim. */
#include "types.h"
#include "deps/0202b6a0_func_0202b6a0.h"

void func_0202b6a0(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((*(int *)(*piRam0202b6e8 + iRam0202b6ec) != 0) &&
     (param_2 != *(int *)(*piRam0202b6e8 + param_1 * 0x2c + 0x4c))) {
    if (param_2 == 1) {
      uVar1 = 2;
    }
    else {
      uVar1 = 1;
    }
    func_0202cc18(param_1,uVar1);
  }
  *(int *)(*piRam0202b6e8 + param_1 * 0x2c + 0x4c) = param_2;
  return;
}

