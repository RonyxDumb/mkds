/* Decompiled C draft; module arm9; ROM address 0207e654. No matching claim. */
#include "types.h"
#include "deps/0207e654_func_0207e654.h"

bool func_0207e654(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0xb0U & 3;
  uVar2 = *(uint *)(param_1 + 0xb0U & 0xfffffffc);
  return uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0;
}

