/* Decompiled C draft; module arm7; ROM address 037f9918. No matching claim. */
#include "types.h"
#include "deps/037f9918_FUN_037f9918.h"

void FUN_037f9918(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = param_2 + 0x10U & 3;
  uVar2 = *(uint *)(param_2 + 0x10U & 0xfffffffc);
  uVar3 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  uVar1 = param_2 + 0x14U & 3;
  uVar2 = *(uint *)(param_2 + 0x14U & 0xfffffffc);
  uVar1 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  if (uVar3 == 0) {
    *(uint *)(param_1 + 0x70) = uVar1;
  }
  else {
    *(uint *)(uVar3 + 0x14) = uVar1;
  }
  if (uVar1 == 0) {
    *(uint *)(param_1 + 0x6c) = uVar3;
  }
  else {
    *(uint *)(uVar1 + 0x10) = uVar3;
  }
  return;
}

