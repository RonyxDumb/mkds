/* Decompiled C draft; module arm9; ROM address 0204f100. No matching claim. */
#include "types.h"
#include "deps/0204f100_func_0204f100.h"

void func_0204f100(int *param_1)

{
  int *piVar1;
  
  piVar1 = piRam0204f140;
  if (*param_1 != 2) {
    func_02050e60(8);
    return;
  }
  if (param_1[1] == 3) {
    *(short *)(*piRam0204f140 + iRam0204f144) = (short)param_1[5];
    *(undefined4 *)(*piVar1 + 0x10) = 0;
    return;
  }
  func_02050e60(8);
  return;
}

