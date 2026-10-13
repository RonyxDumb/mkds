/* Decompiled C draft; module arm9; ROM address 0204ea94. No matching claim. */
#include "types.h"
#include "deps/0204ea94_func_0204ea94.h"

void func_0204ea94(int *param_1)

{
  if (*param_1 != 10) {
    func_02050e60(8);
    return;
  }
  if (param_1[1] == 0xb) {
    *(undefined4 *)(*piRam0204eacc + 0x10) = 0;
    return;
  }
  func_02050e60(8);
  return;
}

