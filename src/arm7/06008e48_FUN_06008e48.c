/* Decompiled C draft; module arm7; ROM address 06008e48. No matching claim. */
#include "types.h"
#include "deps/06008e48_FUN_06008e48.h"

uint FUN_06008e48(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 4U & 3;
  uVar2 = *(uint *)(param_1 + 4U & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

