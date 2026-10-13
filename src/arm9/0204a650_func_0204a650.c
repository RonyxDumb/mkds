/* Decompiled C draft; module arm9; ROM address 0204a650. No matching claim. */
#include "types.h"
#include "deps/0204a650_func_0204a650.h"

bool func_0204a650(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 8U & 3;
  uVar2 = *(uint *)(param_1 + 8U & 0xfffffffc);
  return (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) == 3;
}

