/* Decompiled C draft; module arm9; ROM address 0204efcc. No matching claim. */
#include "types.h"
#include "deps/0204efcc_func_0204efcc.h"

void func_0204efcc(int *param_1)

{
  if (*param_1 != 4) {
    func_02050e60(8);
    return;
  }
  if (param_1[1] == 5) {
    *(undefined4 *)(*piRam0204f004 + 0x10) = 0;
    return;
  }
  func_02050e60(8);
  return;
}

