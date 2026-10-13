/* Decompiled C draft; module arm9; ROM address 020f91e0. No matching claim. */
#include "types.h"
#include "deps/020f91e0_func_020f91e0.h"

bool func_020f91e0(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x70U & 3;
  uVar2 = *(uint *)(param_1 + 0x70U & 0xfffffffc);
  return iRam020f91f8 <= (int)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
}

