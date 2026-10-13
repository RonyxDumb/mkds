/* Decompiled C draft; module arm9; ROM address 0204f080. No matching claim. */
#include "types.h"
#include "deps/0204f080_func_0204f080.h"

void func_0204f080(int *param_1)

{
  if (*param_1 != 6) {
    func_02050e60(8);
    return;
  }
  if (param_1[1] == 7) {
    *(undefined4 *)(*piRam0204f0b4 + 0x10) = 0;
    return;
  }
  func_0204f0b8();
  return;
}

