/* Decompiled C draft; module arm9; ROM address 0212775c. No matching claim. */
#include "types.h"
#include "deps/0212775c_func_0212775c.h"

void func_0212775c(int param_1,undefined4 param_2)

{
  if (param_1 == -1) {
    *(undefined4 *)(*piRam0212777c + iRam02127780) = param_2;
    return;
  }
  *(undefined4 *)(*piRam0212777c + param_1 * 4 + iRam02127784) = param_2;
  return;
}

