/* Decompiled C draft; module arm9; ROM address 0206174c. No matching claim. */
#include "types.h"
#include "deps/0206174c_func_0206174c.h"

bool func_0206174c(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 8U & 3;
  uVar2 = *(uint *)(param_1 + 8U & 0xfffffffc);
  return (int)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) << 0x1f) < 0;
}

