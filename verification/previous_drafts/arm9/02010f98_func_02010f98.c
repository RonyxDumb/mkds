/* Decompiled C draft; module arm9; ROM address 02010f98. No matching claim. */
#include "types.h"
#include "deps/02010f98_func_02010f98.h"

void func_02010f98(int param_1,uint param_2)

{
  *(uint *)(iRam02010fa8 + param_1 * 4) = param_2 | param_1 << 0x1e;
  return;
}

