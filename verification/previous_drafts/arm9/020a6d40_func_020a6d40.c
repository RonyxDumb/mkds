/* Decompiled C draft; module arm9; ROM address 020a6d40. No matching claim. */
#include "types.h"
#include "deps/020a6d40_func_020a6d40.h"

undefined4 func_020a6d40(void)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  
  uVar4 = *(uint *)(uRam020a6d88 & 0xfffffffc) >> (uRam020a6d88 & 3) * 8 |
          *(uint *)(uRam020a6d88 & 0xfffffffc) << (uRam020a6d88 & 3) * -8 + 0x20;
  uVar2 = uVar4 + 8;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) == 2) &&
     (uVar4 = uVar4 + 0x18, uVar2 = uVar4 & 3, uVar4 = *(uint *)(uVar4 & 0xfffffffc),
     (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) == 1)) {
    uVar3 = func_0209bf8c();
    return uVar3;
  }
  return 0;
}

