/* Decompiled C draft; module arm9; ROM address 020b5f68. No matching claim. */
#include "types.h"
#include "deps/020b5f68_func_020b5f68.h"

undefined4 func_020b5f68(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = *(uint *)(uRam020b5fe0 & 0xfffffffc) >> (uRam020b5fe0 & 3) * 8 |
          *(uint *)(uRam020b5fe0 & 0xfffffffc) << (uRam020b5fe0 & 3) * -8 + 0x20;
  uVar2 = uVar1 + 0x10 & 3;
  uVar3 = *(uint *)(uVar1 + 0x10 & 0xfffffffc);
  uVar4 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
  uVar2 = uVar1 + 0x14 & 3;
  uVar3 = *(uint *)(uVar1 + 0x14 & 0xfffffffc);
  uVar3 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
  uVar2 = uVar1 + 0x18 & 3;
  uVar1 = *(uint *)(uVar1 + 0x18 & 0xfffffffc);
  uVar1 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  uVar2 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  if (((((int)(uVar2 - uVar1) < (int)uVar4) && ((int)uVar4 < (int)(uVar2 + uVar1))) &&
      (uVar2 = param_1 + 4 & 3, uVar4 = *(uint *)(param_1 + 4 & 0xfffffffc),
      uVar2 = uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20, (int)(uVar2 - uVar1) < (int)uVar3))
     && ((int)uVar3 < (int)(uVar2 + uVar1))) {
    return 1;
  }
  return 0;
}

