/* Decompiled C draft; module arm9; ROM address 0203be48. No matching claim. */
#include "types.h"
#include "deps/0203be48_func_0203be48.h"

void func_0203be48(int param_1,int param_2,undefined4 *param_3,undefined4 *param_4)

{
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = *(undefined4 *)(param_1 + param_2 * 4 + 4);
  }
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = *(undefined4 *)(param_1 + param_2 * 4 + 0x24);
  }
  return;
}

