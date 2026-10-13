/* Decompiled C draft; module arm9; ROM address 020d8cac. No matching claim. */
#include "types.h"
#include "deps/020d8cac_func_020d8cac.h"

int func_020d8cac(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x18U & 3;
  uVar2 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 == 0 && uVar2 << uVar1 * -8 + 0x20 == 0) {
    uVar1 = param_1 + 0x14U & 3;
    uVar2 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
    uVar1 = 0x1000000 - (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  }
  else {
    uVar1 = param_1 + 0x14U & 3;
    uVar2 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
    uVar1 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  }
  return (int)uVar1 >> 0xc;
}

