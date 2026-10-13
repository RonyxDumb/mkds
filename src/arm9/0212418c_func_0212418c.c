/* Decompiled C draft; module arm9; ROM address 0212418c. No matching claim. */
#include "types.h"
#include "deps/0212418c_func_0212418c.h"

undefined4 func_0212418c(int param_1,undefined4 param_2,int param_3,int param_4)

{
  if ((int)(**(ushort **)
              (*(int *)(*(int *)((uint)*(ushort *)(param_4 + 6) * 0x40 + param_3 + param_1 * 0x40 +
                                0x3c) + 0x44) + 4) & uRam021241bc) >> 10 == 1) {
    return 1;
  }
  return 0;
}

