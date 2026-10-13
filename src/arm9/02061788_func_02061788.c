/* Decompiled C draft; module arm9; ROM address 02061788. No matching claim. */
#include "types.h"
#include "deps/02061788_func_02061788.h"

undefined4 func_02061788(void)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar2 = (*(uint *)(uRam020617a4 & 0xfffffffc) >> (uRam020617a4 & 3) * 8 |
          *(uint *)(uRam020617a4 & 0xfffffffc) << (uRam020617a4 & 3) * -8 + 0x20) + 8;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) == 4) {
    uVar3 = 0x2e;
  }
  else {
    uVar3 = 0x1f;
  }
  return uVar3;
}

