/* Decompiled C draft; module arm9; ROM address 0204ffbc. No matching claim. */
#include "types.h"
#include "deps/0204ffbc_func_0204ffbc.h"

undefined4 func_0204ffbc(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam0204ffe4 & 0xfffffffc) >> (uRam0204ffe4 & 3) * 8 |
          *(uint *)(uRam0204ffe4 & 0xfffffffc) << (uRam0204ffe4 & 3) * -8 + 0x20) + 4;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  if ((uVar2 != 8) && (uVar2 != 9)) {
    return 0;
  }
  return 1;
}

