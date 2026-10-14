/* Decompiled C draft; module arm7; ROM address 037fae5c. No matching claim. */
#include "types.h"
#include "deps/037fae5c_FUN_037fae5c.h"

void FUN_037fae5c(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar4;
  uint uVar3;
  
  uVar4 = *(uint *)((uint)DAT_037faee0 & 0xfffffffc) >> ((uint)DAT_037faee0 & 3) * 8 |
          *(uint *)((uint)DAT_037faee0 & 0xfffffffc) << ((uint)DAT_037faee0 & 3) * -8 + 0x20;
  while( true ) {
    if (uVar4 == 0) {
      FUN_037fae18();
      return;
    }
    uVar1 = param_1 + 0xcU & 3;
    uVar2 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
    uVar3 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
    uVar1 = uVar4 + 0xc & 3;
    uVar2 = *(uint *)(uVar4 + 0xc & 0xfffffffc);
    uVar1 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
    if ((uVar3 <= uVar1) &&
       ((uVar1 != uVar3 || (*(short *)(param_1 + 0x10) < *(short *)(uVar4 + 0x10))))) break;
    uVar1 = uVar4 + 0x18 & 3;
    uVar4 = *(uint *)(uVar4 + 0x18 & 0xfffffffc);
    uVar4 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  }
  uVar1 = uVar4 + 0x14 & 3;
  uVar2 = *(uint *)(uVar4 + 0x14 & 0xfffffffc);
  uVar1 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  *(uint *)(param_1 + 0x14) = uVar1;
  *(uint *)(param_1 + 0x18) = uVar4;
  *(int *)(uVar4 + 0x14) = param_1;
  if (uVar1 == 0) {
    *DAT_037faee0 = param_1;
    FUN_037fac40();
    return;
  }
  *(int *)(uVar1 + 0x18) = param_1;
  return;
}

