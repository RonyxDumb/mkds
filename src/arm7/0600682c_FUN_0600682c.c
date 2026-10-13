/* Decompiled C draft; module arm7; ROM address 0600682c. No matching claim. */
#include "types.h"
#include "deps/0600682c_FUN_0600682c.h"

void FUN_0600682c(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = FUN_06000680();
  uVar1 = iVar2 + 0x154cU & 3;
  uVar3 = *(uint *)(iVar2 + 0x154cU & 0xfffffffc);
  uVar3 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  if (*(short *)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) == 9) {
    uVar1 = param_1 + 4U & 3;
    uVar3 = *(uint *)(param_1 + 4U & 0xfffffffc);
    FUN_06007980((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0xffff);
  }
  return;
}

