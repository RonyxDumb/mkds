/* Decompiled C draft; module arm7; ROM address 037fade0. No matching claim. */
#include "types.h"
#include "deps/037fade0_FUN_037fade0.h"

void FUN_037fade0(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  if (param_1 != 0) {
    uVar1 = param_1 + 0x14U & 3;
    uVar2 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
    uVar3 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
    uVar1 = param_1 + 0x18U & 3;
    uVar2 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
    uVar1 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
    if (uVar1 == 0) {
      DAT_037fae14[1] = uVar3;
    }
    else {
      *(uint *)(uVar1 + 0x14) = uVar3;
    }
    if (uVar3 == 0) {
      *DAT_037fae14 = uVar1;
    }
    else {
      *(uint *)(uVar3 + 0x18) = uVar1;
    }
    return;
  }
  return;
}

