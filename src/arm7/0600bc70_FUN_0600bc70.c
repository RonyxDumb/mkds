/* Decompiled C draft; module arm7; ROM address 0600bc70. No matching claim. */
#include "types.h"
#include "deps/0600bc70_FUN_0600bc70.h"

undefined4 FUN_0600bc70(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = DAT_0600bcac;
  if ((param_1 & DAT_0600bca8) != 0) {
    *(short *)((*(uint *)(DAT_0600bcac & 0xfffffffc) >> (DAT_0600bcac & 3) * 8 |
               *(uint *)(DAT_0600bcac & 0xfffffffc) << (DAT_0600bcac & 3) * -8 + 0x20) + 0x32c) =
         (short)param_1;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    uVar3 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
    uVar2 = uVar3 + 0x340;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    *(uint *)(uVar3 + 0x340) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20 | 4;
    return 0;
  }
  return 5;
}

