/* Decompiled C draft; module arm7; ROM address 037fe3d0. No matching claim. */
#include "types.h"
#include "deps/037fe3d0_FUN_037fe3d0.h"

void FUN_037fe3d0(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 + 0x3cU & 3;
  uVar1 = *(uint *)(param_1 + 0x3cU & 0xfffffffc);
  for (uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20; uVar2 != 0;
      uVar2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) {
    FUN_037fcac8(uVar2);
    uVar1 = uVar2 + 0x50 & 3;
    uVar2 = *(uint *)(uVar2 + 0x50 & 0xfffffffc);
  }
  *(undefined4 *)(param_1 + 0x3c) = 0;
  return;
}

