/* Decompiled C draft; module arm9; ROM address 0207d3a4. No matching claim. */
#include "types.h"
#include "deps/0207d3a4_func_0207d3a4.h"

void func_0207d3a4(short *param_1)

{
  *param_1 = *param_1 + -1;
  if (0 < *param_1) {
    return;
  }
  *param_1 = 0;
  func_0207d194();
  return;
}

