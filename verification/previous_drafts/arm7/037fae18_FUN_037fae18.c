/* Decompiled C draft; module arm7; ROM address 037fae18. No matching claim. */
#include "types.h"
#include "deps/037fae18_FUN_037fae18.h"

void FUN_037fae18(int param_1)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  
  piVar1 = DAT_037fae58;
  uVar3 = (uint)(DAT_037fae58 + 1) & 3;
  uVar2 = *(uint *)((uint)(DAT_037fae58 + 1) & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  *(uint *)(param_1 + 0x14) = uVar3;
  *(undefined4 *)(param_1 + 0x18) = 0;
  piVar1[1] = param_1;
  if (uVar3 == 0) {
    *piVar1 = param_1;
    FUN_037fac40();
  }
  else {
    *(int *)(uVar3 + 0x18) = param_1;
  }
  return;
}

