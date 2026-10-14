/* Decompiled C draft; module arm7; ROM address 037f993c. No matching claim. */
#include "types.h"
#include "deps/037f993c_FUN_037f993c.h"

void FUN_037f993c(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 + 0x70U & 3;
  uVar1 = *(uint *)(param_1 + 0x70U & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if (uVar2 == 0) {
    *(int *)(param_1 + 0x6c) = param_2;
  }
  else {
    *(int *)(uVar2 + 0x10) = param_2;
  }
  *(uint *)(param_2 + 0x14) = uVar2;
  *(undefined4 *)(param_2 + 0x10) = 0;
  *(int *)(param_1 + 0x70) = param_2;
  return;
}

