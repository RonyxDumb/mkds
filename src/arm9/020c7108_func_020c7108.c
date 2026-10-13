/* Decompiled C draft; module arm9; ROM address 020c7108. No matching claim. */
#include "types.h"
#include "deps/020c7108_func_020c7108.h"

undefined4 func_020c7108(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(uRam020c7144 & 0xfffffffc) >> (uRam020c7144 & 3) * 8 |
          *(uint *)(uRam020c7144 & 0xfffffffc) << (uRam020c7144 & 3) * -8 + 0x20;
  if (uVar3 == 0) {
    return 0;
  }
  uVar1 = uVar3 + 8 & 3;
  uVar2 = *(uint *)(uVar3 + 8 & 0xfffffffc);
  if ((uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0) &&
     (uVar1 = uVar3 + 0xc & 3, uVar3 = *(uint *)(uVar3 + 0xc & 0xfffffffc),
     uVar3 >> uVar1 * 8 == 0 && uVar3 << uVar1 * -8 + 0x20 == 0)) {
    return 1;
  }
  return 0;
}

