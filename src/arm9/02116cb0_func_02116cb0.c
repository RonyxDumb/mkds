/* Decompiled C draft; module arm9; ROM address 02116cb0. No matching claim. */
#include "types.h"
#include "deps/02116cb0_func_02116cb0.h"

void func_02116cb0(undefined2 *param_1,int param_2)

{
  if (param_2 == 0) {
    *param_1 = 0x30;
    return;
  }
  if (param_2 != 1) {
    return;
  }
  *param_1 = (short)uRam02116cc8;
  return;
}

