/* Decompiled C draft; module arm7; ROM address 037f9158. No matching claim. */
#include "types.h"
#include "deps/037f9158_FUN_037f9158.h"

bool FUN_037f9158(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x48U & 3;
  uVar2 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  return (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) == 2;
}

