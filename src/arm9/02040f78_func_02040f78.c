/* Decompiled C draft; module arm9; ROM address 02040f78. No matching claim. */
#include "types.h"
#include "deps/02040f78_func_02040f78.h"

int func_02040f78(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar6 = *(uint *)(uRam02040fd4 & 0xfffffffc) >> (uRam02040fd4 & 3) * 8 |
          *(uint *)(uRam02040fd4 & 0xfffffffc) << (uRam02040fd4 & 3) * -8 + 0x20;
  uVar1 = uVar6 + 0x44 & 3;
  uVar4 = *(uint *)(uVar6 + 0x44 & 0xfffffffc);
  if ((uVar4 >> uVar1 * 8 == 0 && uVar4 << uVar1 * -8 + 0x20 == 0) &&
     (uVar1 = uVar6 + 0x24 & 3, uVar4 = *(uint *)(uVar6 + 0x24 & 0xfffffffc),
     uVar4 >> uVar1 * 8 == 0 && uVar4 << uVar1 * -8 + 0x20 == 0)) {
    iVar3 = 0;
  }
  else {
    uVar4 = *(uint *)(uRam02040fd4 & 0xfffffffc) >> (uRam02040fd4 & 3) * 8 |
            *(uint *)(uRam02040fd4 & 0xfffffffc) << (uRam02040fd4 & 3) * -8 + 0x20;
    uVar1 = uVar4 + 0xf8;
    uVar2 = uVar1 & 3;
    uVar5 = *(uint *)(uVar1 & 0xfffffffc);
    uVar4 = uVar4 + 0x24;
    uVar1 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    iVar3 = (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) +
            (uint)*(ushort *)((uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) + param_1 * 2) *
            0x20;
  }
  if (iVar3 == 0) {
    iVar3 = 0;
  }
  else {
    uVar1 = uVar6 + 0xac & 3;
    uVar4 = *(uint *)(uVar6 + 0xac & 0xfffffffc);
    iVar3 = (uint)*(ushort *)(iVar3 + 0x1a) * 0x28 +
            (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20);
  }
  return iVar3;
}

